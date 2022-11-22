#include "codegenReal2Mission.h"
#include "msgQueue.hpp"

/* Simulink Model IO */

// Arg 1
class SendData_IndividualUAVCmd : 
    public SendData_IndividualUAVCmdT, private msgQueue{
public:
    SendData_IndividualUAVCmd()
        : msgQueue("/PosixMQ_IndividualUAVCmd", O_CREAT | O_RDWR | O_NONBLOCK, 1, sizeof(IndividualUAVCmd)) {};
    void SendData(const IndividualUAVCmd *, int32_T, int32_T *);
};

// Arg 2
class SendData_FCUCMD : 
    public SendData_FCUCMDT, private msgQueue{
public:
    SendData_FCUCMD()
        : msgQueue("/PosixMQ_FCUCMD", O_CREAT | O_WRONLY | O_NONBLOCK, 1, sizeof(FCUCMD)) {};
    void SendData(const FCUCMD *, int32_T, int32_T *);
};

// Arg 3
class SendData_FlightLogging : 
    public SendData_FlightLoggingT{
public:
    void SendData(const FlightLogging *, int32_T, int32_T *);
};

// Arg 4
class RecvData_FlightMode : 
    public RecvData_uint8_T, private msgQueue{
public:
    RecvData_FlightMode()
        : msgQueue("/PosixMQ_FlightMode", O_CREAT | O_RDONLY | O_NONBLOCK, 1, sizeof(uint8_T)) {};
    void RecvData(uint8_T *, int32_T, int32_T *);
};

// Arg 5
class RecvData_RealUAVStateBus : 
    public RecvData_RealUAVStateBusT, private msgQueue{
public:
    RecvData_RealUAVStateBus()
        : msgQueue("/PosixMQ_RealUAVStateBus", O_CREAT | O_RDONLY | O_NONBLOCK, 1, sizeof(RealUAVStateBus)) {};
    void RecvData(RealUAVStateBus *, int32_T, int32_T *);
};

// Arg 6
class RecvData_IndividualUAVCmd :
    public RecvData_IndividualUAVCmdT, private msgQueue{
public:
    RecvData_IndividualUAVCmd()
        : msgQueue("/PosixMQ_IndividualUAVCmd", O_CREAT | O_RDWR | O_NONBLOCK, 1, sizeof(IndividualUAVCmd)) {};
    void RecvData(IndividualUAVCmd *, int32_T, int32_T *);
};

// Arg 7
class SendData_TaskStatus :
    public SendData_TaskStatusT, private msgQueue{
public:
    SendData_TaskStatus()
        : msgQueue("/PosixMQ_TaskStatus", O_CREAT | O_WRONLY | O_NONBLOCK, 1, sizeof(TaskStatus)) {};
    void SendData(const TaskStatus *, int32_T, int32_T *);
};

// Arg 8
class RecvData_NbrUAVStateBus : 
    public RecvData_RealUAVStateBusT, private msgQueue{
public:
    RecvData_NbrUAVStateBus()
        : msgQueue("/PosixMQ_NbrUAVStateBus", O_CREAT | O_RDONLY, 10, sizeof(RealUAVStateBus)) {};
    void RecvData(RealUAVStateBus *, int32_T, int32_T *);
};

// Arg 9
class RecvData_VectorSpeed :
    public RecvData_VectorSpeedT, private msgQueue{
public:
    RecvData_VectorSpeed()
        : msgQueue("/PosixMQ_VectorSpeed", O_CREAT | O_RDONLY | O_NONBLOCK, 1, sizeof(VectorSpeed)) {};
    void RecvData(VectorSpeed *, int32_T, int32_T *);
};