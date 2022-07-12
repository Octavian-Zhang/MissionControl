//
// File: ert_main.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.288
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri Jul  1 18:01:36 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LLP64)
// Code generation objectives:
//    1. Safety precaution
//    2. Execution efficiency
//    3. RAM efficiency
//    4. ROM efficiency
// Validation result: Not run
//
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include "rt_nonfinite.h"
#include <stdio.h>              // This example main program uses printf/fflush
#include "codegenReal2Mission.h"       // Model header file

#include <future>
#include <iostream>
#include "msgQueue.hpp"
#include "DataLogging.hpp"
#include "version.h"

/* Simulink Model IO */
static msgQueue MQ_ExtU("/PosixMQ_ExtU", O_CREAT | O_RDONLY | O_NONBLOCK, 1, 
    sizeof(codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T));
static msgQueue MQ_ExtY("/PosixMQ_ExtY", O_CREAT | O_WRONLY | O_NONBLOCK, 1, 
    sizeof(codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T));

class codegenReal2MissionModelClassSendData_IndividualUAVCmdT : public
    SendData_IndividualUAVCmdT{
    mqd_t msgQueue;
  public:
    void SendData(const IndividualUAVCmd* data, int32_T length, int32_T* status)
    {
        // Add send data logic here
        unsigned int priority = 0; // Mission feedback -> Lowest priority
        *status = -mq_send(msgQueue, (char*)data, length, priority);
        if (*status == 0) // Not failed, successfully received
        {
            printf("\nSent Mission Feedback: %i\n", data->SequenceID);
            fflush(stdout);
        }
    }
    void SetMQ(mqd_t mq)
    {
        msgQueue = mq;
    }
};

static codegenReal2MissionModelClassSendData_IndividualUAVCmdT
    CurrentMissionSendData_arg;
class codegenReal2MissionModelClassSendData_FlightLoggingT : public
    SendData_FlightLoggingT{
  public:
    void SendData(const FlightLogging* data, int32_T length, int32_T* status)
    {
        // Add send data logic here
        DataLogging::wrtieLog(data);
    }
};

static codegenReal2MissionModelClassSendData_FlightLoggingT
    FlightLogSendData_arg;
class codegenReal2MissionModelClassRecvData_IndividualUAVCmdT : public
    RecvData_IndividualUAVCmdT{
    mqd_t msgQueue;
  public:
    void RecvData(IndividualUAVCmd* data, int32_T length, int32_T* status)
    {
        // Add receive data logic here
        unsigned int priority = 16384; // Mission upload -> Highest priority
        *status = -mq_receive(msgQueue, (char *)data, length, &priority);
        if (*status < 0) // Not failed, successfully received
        {
            printf("\nReceived Mission Command: %i\n", data->SequenceID);
            fflush(stdout);
        }
    }
    void SetMQ(mqd_t mq)
    {
        msgQueue = mq;
    }
};

static codegenReal2MissionModelClassRecvData_IndividualUAVCmdT
    MissionCMDRecvData_arg;
class codegenReal2MissionModelClassRecvData_RealUAVStateBusT : public
    RecvData_RealUAVStateBusT{
    mqd_t msgQueue;
  public:
    void RecvData(RealUAVStateBus* data, int32_T length, int32_T* status)
    {
        // Add receive data logic here
        timespec timeout; unsigned int priority = 8192; // Neighbour UAV State -> IO priority
        if (!clock_gettime(CLOCK_REALTIME, &timeout))
        {
            timeout.tv_sec = timeout.tv_sec + (timeout.tv_nsec + 
                static_cast<decltype(timespec::tv_nsec)>(1e8)) / 
                static_cast<decltype(timespec::tv_nsec)>(1e9);
            timeout.tv_nsec = (timeout.tv_nsec + 
                static_cast<decltype(timespec::tv_nsec)>(1e8)) % 
                static_cast<decltype(timespec::tv_nsec)>(1e9);
            *status = -mq_timedreceive(msgQueue, (char *)data, length, &priority, &timeout);
            if (*status < 0) // Not failed, successfully received
            {
                printf("UAV");
                fflush(stdout);
            }
        }
    }
    void SetMQ(mqd_t mq)
    {
        msgQueue = mq;
    }
};

static codegenReal2MissionModelClassRecvData_RealUAVStateBusT
    NbrUAVstateRecvData_arg;
static codegenReal2MissionModelClass codegenReal2Mission_Obj{
    CurrentMissionSendData_arg, FlightLogSendData_arg, MissionCMDRecvData_arg,
    NbrUAVstateRecvData_arg };         // Instance of model class

#define CHECK_STATUS(status, fcn)      if (status != 0) {fprintf(stderr, "Call to %s returned error status (%d).\n", fcn, status); perror(fcn); fflush(stderr); exit(EXIT_FAILURE);}

// Semaphores used for threads synchronization
sem_t quitSem[1];
sem_t periodicTaskStartSem[1];
sem_t periodicTaskStopSem[1];
sem_t periodicTriggerSem[1];
timer_t timers[1];
int threadID[1];
void MW_sem_wait(sem_t *sem)
{
    int status;
    while (((status = sem_wait(sem)) == -1) && (errno == EINTR)) {
        // Restart if interrupted by a signal
        continue;
    }

    CHECK_STATUS(status, "sem_wait");
}

void MW_blockSignal(int sigNo, sigset_t *sigMask)
{
    int ret;
    sigaddset(sigMask, sigNo);
    ret = pthread_sigmask(SIG_BLOCK, sigMask, (nullptr));
    CHECK_STATUS(ret, "pthread_sigmask");
}

void MW_sigWait(sigset_t *sigMask)
{
    int ret;
    ret = sigwaitinfo(sigMask, (nullptr));
    if (ret == -1) {
        fprintf(stderr, "Call to sigwait returned error.\n");
        perror("sigwait");
        fflush(stderr);
        exit(EXIT_FAILURE);
    }
}

void MW_setTaskPeriod(double periodInSeconds, int sigNo, int idx)
{
    struct sigevent sev;
    struct itimerspec its;
    int ret;

    // Create a timer
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = sigNo;
    sev.sigev_value.sival_int = idx;
    ret = timer_create(CLOCK_REALTIME, &sev, &timers[idx]);
    CHECK_STATUS(ret, "timer_create");

    // Real-time scheduling timer
    its.it_value.tv_sec = (time_t)periodInSeconds;
    its.it_value.tv_nsec = (periodInSeconds - (time_t)periodInSeconds) *
        1000000000;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;
    ret = timer_settime(timers[idx], 0, &its, (nullptr));
    CHECK_STATUS(ret, "timer_settime");
}

void MW_sem_waitTriggerWithOverrunDetection(sem_t *startSem, int triggerIdx)
{
    int ret;
    ret = sem_trywait(startSem);
    if (ret == -1) {
        if (errno == EAGAIN) {
            MW_sem_wait(startSem);
        } else {
            fprintf(stderr, "Call to sem_trywait returned error.\n");
            perror("sigtimedwait");
            fflush(stderr);
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Overrun - periodic trigger %d base rate too fast.\n", triggerIdx);
        fflush(stdout);
    }
}

void MW_sem_waitTaskWithOverrunDetection(sem_t *stopSem, int taskIdx)
{
    int ret;
    ret = sem_trywait(stopSem);
    if (ret == -1) {
        if (errno == EAGAIN) {
            printf("Overrun - rate for periodic task %d too fast.\n", taskIdx);
            fflush(stdout);
            MW_sem_wait(stopSem);
        } else {
            fprintf(stderr, "Call to sem_trywait returned error.\n");
            perror(" sem_trywait");
            fflush(stderr);
            exit(EXIT_FAILURE);
        }
    }
}

void* periodicTask(void *arg)
{
    int ret;
    int taskId = *((int *) arg);
    sigset_t ss;
    sigemptyset(&ss);
    MW_blockSignal(SIGRTMIN, &ss);
    while (1) {
        MW_sem_wait(&periodicTaskStartSem[taskId]);

        unsigned int priority = 8192; 

        // Set model inputs here
        codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T ExtU{};
        if (mq_receive(MQ_ExtU.getMQ(), (char *)&ExtU, sizeof(ExtU), &priority) > 0)
        {
            printf(">"); // resemble istream operator >>
            fflush(stdout);
        }
        codegenReal2Mission_Obj.setExternalInputs(&ExtU);

        codegenReal2Mission_Obj.step();
        printf("."); fflush(stdout);

        // Get model outputs here
        codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T ExtY{};
        ExtY = codegenReal2Mission_Obj.getExternalOutputs();
        if (mq_send(MQ_ExtY.getMQ(), (char *)&ExtY, sizeof(ExtY), priority) == 0)
        {
            printf("<"); // resemble ostream operator <<
            fflush(stdout);
        }
        
        ret = sem_post(&periodicTaskStopSem[taskId]);
        CHECK_STATUS(ret, "sem_post");
    }

    return (nullptr);
}

void* baseRateTaskScheduler(void *arg)
{
    volatile boolean_T noErr;
    int ret;
    int_T taskId[1]{ 0 };

    sigset_t ss;
    sigemptyset(&ss);
    MW_blockSignal(SIGRTMIN, &ss);

    // Unused arguments
    (void)(arg);
    noErr = (rtmGetErrorStatus(codegenReal2Mission_Obj.getRTM()) == (nullptr)) &&
        !rtmGetStopRequested(codegenReal2Mission_Obj.getRTM());
    while (noErr) {
        // Wait for the next timer interrupt
        MW_sem_waitTriggerWithOverrunDetection(&periodicTriggerSem[0], 0);
        MW_sem_waitTaskWithOverrunDetection(&periodicTaskStopSem[taskId[0]], 0);
        noErr = (rtmGetErrorStatus(codegenReal2Mission_Obj.getRTM()) == (nullptr))
            && !rtmGetStopRequested(codegenReal2Mission_Obj.getRTM());
        if (noErr) {
            ret = sem_post(&periodicTaskStartSem[taskId[0]]);
            CHECK_STATUS(ret, "sem_post");
        }
    }                                  // while

    ret = sem_post(&quitSem[0]);
    CHECK_STATUS(ret, "sem_post");
    ret = timer_delete(timers[0]);
    CHECK_STATUS(ret, "timer_delete");
    return (nullptr);
}

void sigHandler_TimerSignal(int signo, siginfo_t *sigInfo, void *ctx)
{
    int ret;

    // Unused arguments
    (void)(ctx);
    (void)(signo);
    switch ((*sigInfo).si_value.sival_int) {
      case 0:
        ret = sem_post(&periodicTriggerSem[0]);
        CHECK_STATUS(ret, "sem_post");
        break;
    }
}

int main(int argc, const char *argv[])
{
    int i;
    pthread_t periodicThread[1];
    pthread_t periodicTriggerThread[1];
    struct sched_param sp;
    int ret, policy = SCHED_RR;
    pthread_attr_t attr;
    double periodicTriggerRate[1];
    int priority[1];

    // Unused arguments
    (void)(argc);
    (void)(argv);
    std::cout << argv[0] << "\tVersion\t" << VERSION_MAJOR << "." << VERSION_MINOR << "\n";
    priority[0] = sched_get_priority_max(SCHED_RR)-1;
    periodicTriggerRate[0] = 0.1;
    printf("**starting the model**\n");
    fflush(stdout);
    rtmSetErrorStatus(codegenReal2Mission_Obj.getRTM(), 0);

    // Initialize semaphore used for thread synchronization
    for (i = 0; i < 1; i++) {
        ret = sem_init(&quitSem[i], 0, 0);
        CHECK_STATUS(ret, "sem_init:quitSem");
    }

    // Create threads executing the Simulink model
    pthread_attr_init(&attr);
    ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    CHECK_STATUS(ret, "pthread_attr_setinheritsched");
    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    CHECK_STATUS(ret, "pthread_attr_setdetachstate");
    ret = pthread_attr_setschedpolicy(&attr, policy);
    CHECK_STATUS(ret, "pthread_attr_setschedpolicy");
    ret = pthread_attr_getschedpolicy(&attr, &policy);
    CHECK_STATUS(ret, "pthread_attr_getschedpolicy");

    // Open POSIX message queue
    msgQueue mqSndCMD("/PosixMQ_SndCMD", O_CREAT | O_WRONLY | O_NONBLOCK, 1, sizeof(IndividualUAVCmd));
    msgQueue mqRcvCMD("/PosixMQ_RcvCMD", O_CREAT | O_RDONLY | O_NONBLOCK, 1, sizeof(IndividualUAVCmd));
    msgQueue mqNbrState("/PosixMQ_NbrState", O_CREAT | O_RDONLY, 1, sizeof(RealUAVStateBus));

    CurrentMissionSendData_arg.SetMQ(mqSndCMD.getMQ());
    MissionCMDRecvData_arg.SetMQ(mqRcvCMD.getMQ());
    NbrUAVstateRecvData_arg.SetMQ(mqNbrState.getMQ());

    // Waiting for OS clock calibration
    msgQueue mqStart("/ptrPosixMQ_Start", O_CREAT | O_RDONLY, 1, sizeof(bool));
    bool startflag{}; printf("Waiting for OS Clock Calibration: %i\n", static_cast<int>(startflag));
    printf((mq_receive(mqStart.getMQ(), (char *)&startflag, sizeof(bool), nullptr) > 0) 
        ? "OS Clock Calibrated: %i\n" : "MQ_Receive Error %i", static_cast<int>(startflag));

    // Initialize model
    codegenReal2Mission_Obj.initialize();

    {
        // Connect and enable the signal handler for timers notification
        struct sigaction sa;
        sa.sa_sigaction = &sigHandler_TimerSignal;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = SA_RESTART;// Restart functions if interrupted by handler
        sa.sa_flags |= SA_SIGINFO; // Enable passing signal data to the handler
        if (sigaction(SIGRTMIN, &sa, (nullptr)) == -1) {
            fprintf(stderr,
                    "Failed to register signal handler for signal SIGRTMIN : %s\n",
                    strerror(errno));
        }
    }

    // Create periodic threads
    for (i = 0; i < 1; i++) {
        ret = sem_init(&periodicTaskStartSem[i], 0, 0);
        CHECK_STATUS(ret, "sem_init");
        ret = sem_init(&periodicTaskStopSem[i], 0, 1);
        CHECK_STATUS(ret, "sem_init");
        threadID[i] = i;
        if (policy == SCHED_FIFO || policy == SCHED_RR) {
            sp.sched_priority = priority[i];
            ret = pthread_attr_setschedparam(&attr, &sp);
            CHECK_STATUS(ret, "pthread_attr_setschedparam");
        }

        ret = pthread_create(&periodicThread[i], &attr, periodicTask, (void *)
                             &threadID[i]);
        CHECK_STATUS(ret,"pthread_create");
    }

    // Initialize semaphores for periodic triggers
    for (i = 0; i < 1; i++) {
        ret = sem_init(&periodicTriggerSem[i], 0, 0);
        CHECK_STATUS(ret, "sem_init");
    }

    // Create periodic trigger threads
    if (policy == SCHED_FIFO || policy == SCHED_RR) {
        sp.sched_priority = sched_get_priority_max(SCHED_RR);
        ret = pthread_attr_setschedparam(&attr, &sp);
        CHECK_STATUS(ret, "pthread_attr_setschedparam");
    }

    ret = pthread_create(&periodicTriggerThread[0], &attr, baseRateTaskScheduler,
                         (nullptr));
    CHECK_STATUS(ret, "pthread_create");
    pthread_attr_destroy(&attr);

    // Create periodic timers
    for (i = 0; i < 1; i++) {
        MW_setTaskPeriod(periodicTriggerRate[i], SIGRTMIN, i);
    }

    auto PushNbrUAVFuture = std::async(std::launch::async, [&]()
                                       {while (true)
    {
        codegenReal2Mission_Obj.codegenReal2Mission_PushNbrUAV();
        printf("*"); fflush(stdout);
    } });

    // Wait for a stopping condition.
    for (i = 0; i < 1; i++) {
        MW_sem_wait(&quitSem[i]);
    }

    printf("**stopping the model**\n");
    fflush(stdout);
    if (rtmGetErrorStatus(codegenReal2Mission_Obj.getRTM()) != (nullptr)) {
        fprintf(stderr, "\n**%s**\n", rtmGetErrorStatus
                (codegenReal2Mission_Obj.getRTM()));
    }

    // Terminate model
    codegenReal2Mission_Obj.terminate();

    {
        // Restore the signal handler for signal: SIGRTMIN
        struct sigaction sa;
        sa.sa_handler = SIG_DFL;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = SA_RESTART;// Restart functions if interrupted by handler
        if (sigaction(SIGRTMIN, &sa, (nullptr)) == -1) {
            fprintf(stderr,
                    "Failed to restore default signal handler for signal SIGRTMIN : %s\n",
                    strerror(errno));
        }
    }

    for (i = 0; i < 1; i++) {
        ret = sem_destroy(&periodicTaskStartSem[i]);
        CHECK_STATUS(ret, "sem_destroy");
        ret = sem_destroy(&periodicTaskStopSem[i]);
        CHECK_STATUS(ret, "sem_destroy");
    }

    for (i = 0; i < 1; i++) {
        ret = sem_destroy(&periodicTriggerSem[i]);
        CHECK_STATUS(ret, "sem_destroy");
        ret = sem_destroy(&quitSem[i]);
        CHECK_STATUS(ret, "sem_destroy");
    }

    return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
