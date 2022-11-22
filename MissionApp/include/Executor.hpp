#pragma once

#include <iostream>
#include <vector>
#include <csignal>
#include <atomic>
#include <algorithm>
#include <exception>
#include <cmath>
#include <numeric>
#include <memory>

#include "WorkerPool.hpp"
#include "Timer.hpp"

namespace platform {
namespace runtime {

/** @brief A global flag to control the termination of executor
 */
volatile std::sig_atomic_t haltExecutor = false;

/** @brief The signal handler which is invoked to terminate the executor when
 *        a SIGINT signal occurs
 *
 *  @param The signal number
*/
void ctrlCHandler(int signalNum) {
    if(signalNum == SIGINT) {
        // Consider aborting the program directly to avoid the synchronization problem
        haltExecutor = true;
    }
}


/** @brief An executor monitors events given by users and dispatches the handlers of triggered events
 *          to threads for execution. Currently the supported types of events are periodic and aperiodic.
 *
 *  Usage:
 *     platform::runtime::Executor executor;
 *
 *     executor.addEvent([](){ std::this_thread::sleep_for(std::chrono::seconds(5)); },
 *                        [](){ std::cout << "Event B is triggered" << std::endl; });
 *
 *     executor.addPeriodicEvent([](){ std::cout << "Event A (period=2 ticks) is triggered\n" << std::endl; }, 2);
 *
 *     executor.run();
*/
class Executor {

    public:

        Executor(size_t numWorkers=0) : workerPool(numWorkers) { }

        ~Executor() {
            stop();
        }

        Executor(const Executor& other) = delete;
        Executor(Executor&& other) = delete;

        Executor& operator = (const Executor& other) = delete;
        Executor& operator = (Executor&& other) = delete;

        /** @brief Function for adding a periodic event.
         *
         *  @param handler The event handler which gets called when the event is triggered
         *  @param tick The period of occurence
         *  @param offset The period of occurence
        */
        void addPeriodicEvent(std::function<void()>&& handler, const size_t tick, const size_t offset=0) {
            periodicEvents.push_back(std::unique_ptr<PeriodicEvent>(
                        new PeriodicEvent(tick, std::move(handler), offset)));
        }

        /** @brief Function for adding an aperiodic event.
         *
         *  @param waitFun The event to be monitored
         *  @param handler The event handler which gets called when the event is triggered
         *  @param haltFun The function to enable the waiting thread to return early from the waitFun
        */
        void addEvent(std::function<bool()>&& waitFun, std::function<void()> &&handler,
                std::function<void()> &&haltFun) {
            aperiodicEvents.push_back(std::unique_ptr<AperiodicEvent>(
                        new AperiodicEvent(std::move(waitFun), std::move(handler), std::move(haltFun))));
        }

        /** @brief Set up the base rate of timer. This is only used for periodic events.
         *
         *  A base rate is the time unit (in seconds) of a tick, e.g. if baseRate = 2 seconds,
         *  then one tick is 2 seconds. A periodic event uses ticks to represent the length
         *  of its period,
         *
         *  Example:
         *    Assume baseRate = 2 seconds, then a periodic event with 3 ticks means this
         *    event will repeatedly trigger every 6 seconds (3 ticks * baseRate)
         *
         *  @param rate The base rate in seconds
        */
        void setBaseRateInSeconds(std::chrono::duration<double> rate) {
            assert(rate.count() > 0.0);
            baseRate = rate;
        }

        /** @brief Run the executor with a logger given by users. Users can provide their
         *         own timer implementation, otherwise default timer is used
         *
         *  Example:
         *     CustomLogger logger;
         *     executor.run<CustomLogger, CustomTimer>(logger);  // Users provide their own logger & timer
         *     executor.run<CustomLogger>(logger);   // Only logger is provided (default timer will be used)
         *
         *  @param logger A user-provided logger
         *  @param tickLimit An optional time limit
        */
        template <typename LoggerT, typename TimerT=utility::Timer>
        void run(LoggerT& logger, int tickLimit=-1) {
            run<LoggerT, TimerT>(&logger, tickLimit);
        }


        /** @brief Run the executor with the timer specified by users and without logger
         *
         *  Example:
         *      executor.run<CustomTimer>();
         *
         *  @param tickLimit An optional time limit
         */
        template <typename TimerT>
        void run(int tickLimit=-1) {
            run<UnusedLogger, TimerT>(tickLimit);
        }

        /** @brief Run the executor with default logger (UnusedLogger) and timer
         *
         *  Example:
         *      executor.run(10);  // executor terminates after 10 ticks pass
         *
         *  @param tickLimit An optional time limit
         */
        void run(int tickLimit=-1) {
            run<UnusedLogger, utility::Timer>(nullptr, tickLimit);
        }


    private:

        /** @brief The event base class - each event (regardless of the type) must have a handler
         *
         *  The executor guarantees:
         *    1. The handler will be invoked as many times as the event gets triggered.
         *    2. The handler will be invoked sequentially even the event gets triggered multiple times in a short period,
         *       i.e. the handler will NOT be invoked on multiple threads at the same time.
         *
         *  Users need to guarantee:
         *     There is no data race between concurrent events and handlers.
         */
        struct Event {
            Event(std::function<void()> &&handler): handler(std::move(handler)) {}

            std::function<void()> handler;

            /** @brief remainRuns records the number of times the handler needs to be executed
             *
             *  Whenever the event gets triggered, remainRuns is incremented by 1
             *  and the remainRuns is decremented by 1 everytime after the handler is executed.
             *  This can be used for overrun detection.
             */
            std::atomic<int> remainRuns {0};

            void operator()() {
               auto numRuns = remainRuns.load();
               while(numRuns) {
                   for(int i=0; i<numRuns; i++) {
                       handler();
                   }
                   const int numFinishedRuns = numRuns;
                   numRuns = remainRuns.fetch_sub(numFinishedRuns) - numFinishedRuns;
               }
            }
        };

        struct PeriodicEvent final: public Event {
            PeriodicEvent(size_t tick, std::function<void()> &&handler, size_t offset):
                Event(std::move(handler)), tick(tick), offset(offset) {}
            size_t tick {1};
            size_t offset {0};
        };

        /** @brief Aperiodic events are triggered irregularly
         *
         *  An aperiodic event might never be triggered or triggered after a long time, and thus
         *  a haltFun is required to allow the thread waiting for the aperiodic event to return
         *  early when the executor terminates.
         */
        struct AperiodicEvent final: public Event {
            AperiodicEvent(std::function<bool()> &&event, std::function<void()> &&handler, std::function<void()> &&haltFun):
                Event(std::move(handler)), waitFun(std::move(event)), haltFun(std::move(haltFun)) {}
            std::function<bool()> waitFun;
            std::function<void()> haltFun;
        };

        /** @brief A logger using standard output streams
         *
         *  Default logger type which is used as the logger template parameter in the `run()` methods
         *  when users do not provide a logger, i.e. logging is not needed.
         */
        struct UnusedLogger {
            std::ostream& LogVerbose() { return std::cout; }
            std::ostream& LogError()   { return std::cerr; }
        };

        std::vector<std::unique_ptr<PeriodicEvent>> periodicEvents;
        std::vector<std::unique_ptr<AperiodicEvent>> aperiodicEvents;

        std::vector<std::thread> waiters;
        utility::WorkerPool workerPool;

        bool start {false};
        std::chrono::duration<double> baseRate {0.0};

        std::condition_variable cv;
        std::mutex mtx;

        /** @brief The function to be called by the threads monitoring aperiodic events
         *
         *  The function executed by the threads which wait for aperiodic events.
         *  Executor creates a thread (called waiter) to wait for each aperiodic event. The waiter
         *  will call the `waitFun` which returns when the aperiodic event is triggered.
         *  The `index` is the index of the aperiodic event in the vector.
         *
         *  @param index The index of the aperiodic event monitored by the thread
        */
        void waiterLoop(const int index);


        /** @brief Schedule periodic events if any
         *
         *  Create a timer armed with the base rate to schedule the periodic events and dispatch
         *  the handlers of triggered events to execution. This function is called by the main
         *  thread only when periodic events exist.
         *
         *  @param logger An optional logger which will be called to emit information
         *  @param tickLimit An optional time limit
        */
        template <typename LoggerT, typename TimerT>
        void schedulePeriodicEvents(LoggerT* logger, int tickLimit=-1);

        /** @brief Register the SIGINT signal handler which will terminate the executor when called
         */
        void registerCtrlC() { std::signal(SIGINT, ctrlCHandler); }

        /** @brief Invoke the halt function to enable early return from aperiodic events
         *
         *  Notfiy waiters to return from waitFun. Without this, waiters might get stuck indefinitely
         */
        void unblockWaiters() {
            std::for_each(aperiodicEvents.begin(), aperiodicEvents.end(),
                    [](std::unique_ptr<AperiodicEvent>& e){ e->haltFun(); });
        }

        /**  @brief Terminate the executor and join all threads (workers & waiters)
         */
        void stop();

        /** @brief This function implements the logic to schedule all events
         *
         *  All other run() methods will call this function to start the event execution
         *
         *  @param logger An optional logger which will be called to emit information
         *  @param tickLimit An optional time limit
         */
        template <typename LoggerT, typename TimerT>
        void run(LoggerT *logger=nullptr, int tickLimit=-1);

        /** @brief An utility function to calculate the greatest common divisor of two numbers
         */
        size_t gcd(size_t a, size_t b) const { return (b == 0) ? a : gcd(b, a%b); }
};


void Executor::stop() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        start = false;
        haltExecutor = true;
    }
    cv.notify_all();

    const auto joinThread = [](std::thread& thd){
      if(thd.joinable()) {
          thd.join();
      }
    };

    std::for_each(waiters.begin(), waiters.end(), joinThread);
}

void Executor::waiterLoop(const int index) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&](){ return haltExecutor || start; });

    while(start) {
        if(haltExecutor) {
            break;
        }

        lock.unlock();
        const bool isTriggered = aperiodicEvents[index]->waitFun();
        if(!isTriggered) {
            break;
        }

        const bool isDispatched = (aperiodicEvents[index]->remainRuns.fetch_add(1) != 0);

        if(!isDispatched) {
            workerPool.post([this, index](){ (*this->aperiodicEvents[index])(); });
        }
        lock.lock();
    }
}

template <typename LoggerT, typename TimerT>
void Executor::schedulePeriodicEvents(LoggerT *logger, int tickLimit) {

    // Sort periodic events in decreasing order based on the ticks. This is for ERT's
    // rate-monotonic scheduling, i.e. short cycle events get triggered first.
    std::sort(periodicEvents.begin(), periodicEvents.end(),
        [](std::unique_ptr<PeriodicEvent>& e1, std::unique_ptr<PeriodicEvent>& e2){
            return e1->tick < e2->tick;
        }
    );

    const auto lcm = std::accumulate(periodicEvents.begin(), periodicEvents.end(), 1u,
        [this](size_t lcm, std::unique_ptr<PeriodicEvent>& event) {
            return (lcm * event->tick) / gcd(lcm, event->tick);
        }
    );

    TimerT timer(baseRate);

    std::unique_lock<std::mutex> lock(mtx);
    start = true;
    cv.notify_all();

    try {
        timer.start();
    }
    catch (const std::exception& e) {
        if(logger) {
           logger->LogError() << "Error: " << e.what() << '\n';
        }
        haltExecutor = true;
        cv.notify_all();
        return ;
    }

    size_t currentTick = 0;

    while(!haltExecutor && tickLimit != 0) {
        lock.unlock();

        // Wait for timer to expire, i.e. one tick (period) passes
        try {
            timer.wait();
        }
        catch (const std::exception&) {
            if(logger) {
                logger->LogError() << "Error: an error occurs in timer wait function\n";
            }
            break;
        }

        for(size_t i=0; i<periodicEvents.size(); i++) {
            if(currentTick % periodicEvents[i]->tick == periodicEvents[i]->offset) {
                if(periodicEvents[i]->remainRuns.fetch_add(1) == 0) {
                    workerPool.post([this, i](){ (*this->periodicEvents[i])(); });
                }
                else {
                    // Prior executions are not finished yet while the event gets triggered again
                    if(logger) {
                        logger->LogVerbose() << "INFO: Overrun detected: Periodic event " << i << " triggers too fast\n";
                    }
                }
            }
        }

        currentTick = (currentTick+1)%lcm;

        if(tickLimit > 0 && --tickLimit == 0) {
            // Dispatch all events for the last tick
            for(auto &event: periodicEvents) {
                if(event->remainRuns.fetch_add(1) == 0) {
                    workerPool.post([&event](){ (*event)(); });
                }
            }

            // Wait for all events to finish execution
            workerPool.wait();
        }

        lock.lock();
    } // End of periodic event schedule loop
}

template <typename LoggerT, typename TimerT>
void Executor::run(LoggerT* logger, int tickLimit) {

    if((periodicEvents.empty() && aperiodicEvents.empty()) || tickLimit == 0) {
        return;
    }

    workerPool.start();

    for(size_t i=0; i<aperiodicEvents.size(); i++) {
        waiters.emplace_back([this, i]{ this->waiterLoop(i); });
    }

    registerCtrlC();

    if(!periodicEvents.empty()) {
        schedulePeriodicEvents<LoggerT, TimerT>(logger, tickLimit);
    }
    else {
        // If a time limit (tickLimit) is given, wake up the main thread only
        // when reaching the time limit. Otherwise, wake up every 1 second.
        double sleepInterval = tickLimit > 0 ?
            tickLimit * std::chrono::duration<double>(baseRate).count() : 1.0;

        std::unique_lock<std::mutex> lock(mtx);
        start = true;
        cv.notify_all();

        while(1) {
            const bool predicateResult = cv.wait_for(lock,
                    std::chrono::duration<double>(sleepInterval),
                    [&]{ return !haltExecutor; });

            // Two possible wakeup scenarios that the executor should terminate:
            //    1. The predicate is true
            //    2. A time limit is given and time out
            if(predicateResult || tickLimit > 0) {
                break;
            }
        }
    }
    unblockWaiters();
    stop();
}

} // End of runtime namespace
} // End of platform namespace


