#include "ModelIO.hpp"
#include "DataLogging.hpp"

// Arg 1
void SendData_IndividualUAVCmd::
    SendData(const IndividualUAVCmd *data, int32_T length, int32_T *status)
{
    // Add send data logic here
    unsigned int priority = 0; // Mission feedback -> Lowest priority
    *status = -mq_send(getMQ(), (char *)data, length, priority);
    if (*status == 0) // Not failed, successfully received
    {
        printf("\nSent Mission Feedback: %i\n", data->SequenceID);
        fflush(stdout);
    }
}

// Arg 2
void SendData_FCUCMD::
    SendData(const FCUCMD *data, int32_T length, int32_T *status)
{
    // Add send data logic here
    unsigned int priority = 16384; // FlightCMD output -> Highest priority
    *status = -mq_send(getMQ(), (char *)data, length, priority);
    if (*status != 0) // failed
    {
        int err = errno;
        printf("%s errno = %i\n", getName(), err);
    }
}

// Arg 3
void SendData_FlightLogging::
    SendData(const FlightLogging *data, int32_T length, int32_T *status)
{
    DataLogging::wrtieLog(data);
}

// Arg 4
void RecvData_FlightMode::
    RecvData(uint8_T *data, int32_T length, int32_T *status)
{
    // Add receive data logic here
    unsigned int priority = 16384; // ModeFCU input -> Highest priority
    *status = -mq_receive(getMQ(), (char *)data, length, &priority);
    if (*status >= 0) // failed
    {
        int err = errno;
        printf("%s errno = %i\n", getName(), err);
    }
}

// Arg 5
void RecvData_RealUAVStateBus::
    RecvData(RealUAVStateBus *data, int32_T length, int32_T *status)
{
    // Add receive data logic here
    unsigned int priority = 16384; // FlightState input -> Highest priority
    *status = -mq_receive(getMQ(), (char *)data, length, &priority);
    if (*status >= 0) // failed
    {
        int err = errno;
        printf("%s errno = %i\n", getName(), err);
    }
}

// Arg 6
void RecvData_IndividualUAVCmd::
    RecvData(IndividualUAVCmd *data, int32_T length, int32_T *status)
{
    // Add receive data logic here
    unsigned int priority = 16384; // Mission upload -> Highest priority
    *status = -mq_receive(getMQ(), (char *)data, length, &priority);
    if (*status < 0) // Not failed, successfully received
    {
        printf("\nReceived Mission Command: %i\n", data->SequenceID);
        fflush(stdout);
    }
}

// Arg 7
void SendData_TaskStatus::
    SendData(const TaskStatus *data, int32_T length, int32_T *status)
{
    // Add send data logic here
    unsigned int priority = 0; // TaskState download -> Lowest priority
    *status = -mq_send(getMQ(), (char *)data, length, priority);
    if (*status != 0) // failed
    {
        int err = errno;
        printf("%s errno = %i\n", getName(), err);
    }
}

// Arg 8
void RecvData_NbrUAVStateBus::
    RecvData(RealUAVStateBus *data, int32_T length, int32_T *status)
{
    // Add receive data logic here
    timespec timeout;
    unsigned int priority = 0; // NbrState upload -> Lowest priority
    if (!clock_gettime(CLOCK_REALTIME, &timeout))
    {
        timeout.tv_sec = timeout.tv_sec + (timeout.tv_nsec +
            static_cast<decltype(timespec::tv_nsec)>(1e8)) /
            static_cast<decltype(timespec::tv_nsec)>(1e9); // (timenow + 0.1sec) / 1sec
        timeout.tv_nsec = (timeout.tv_nsec +
            static_cast<decltype(timespec::tv_nsec)>(1e8)) %
            static_cast<decltype(timespec::tv_nsec)>(1e9); // (timenow + 0.1sec) % 1sec
        *status = -mq_timedreceive(getMQ(), (char *)data, length, &priority, &timeout);
    }
}

// Arg 9
void RecvData_VectorSpeed::
    RecvData(VectorSpeed *data, int32_T length, int32_T *status)
{
    // Add receive data logic here
    unsigned int priority = 0; // VecSpd input -> Lowest priority
    *status = -mq_receive(getMQ(), (char *)data, length, &priority);
    if (*status >= 0) // failed
    {
        int err = errno;
        printf("%s errno = %i\n", getName(), err);
    }
}