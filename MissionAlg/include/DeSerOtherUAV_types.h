//
// File: DeSerOtherUAV_types.h
//
// Code generated for Simulink model 'DeSerOtherUAV'.
//
// Model version                  : 4.339
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Sep  5 17:28:26 2022
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
#ifndef RTW_HEADER_DeSerOtherUAV_types_h_
#define RTW_HEADER_DeSerOtherUAV_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_RealUAVStateBus_
#define DEFINED_TYPEDEF_FOR_RealUAVStateBus_

struct RealUAVStateBus
{
    int32_T UAV_ID;
    real_T Latitude_deg;
    real_T Longitude_deg;
    real_T Height_meter;
    real_T Altitude_meter;
    real_T AirSpeed_mps;
    real_T GndSpd_mps;
    real_T HeadingAngle_deg;
    real_T FlightPathAngle_deg;
    real_T RollAngle_deg;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

enum class QueuePolicy_T
    : int32_T {
    MSG_QUEUE_UNUSED = -1,             // Default value
    MSG_FIFO_QUEUE,
    MSG_LIFO_QUEUE,
    MSG_PRIORITY_QUEUE
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_real_T_
#define DEFINED_TYPEDEF_FOR_Msg_real_T_

struct Msg_real_T
{
    real_T fData;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Buffer_real_T_
#define DEFINED_TYPEDEF_FOR_Buffer_real_T_

struct Buffer_real_T
{
    boolean_T fOccupied;
    Msg_real_T fMsg;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_RecvData_RealUAVStateBusT_
#define DEFINED_TYPEDEF_FOR_RecvData_RealUAVStateBusT_

class RecvData_RealUAVStateBusT
{
  public:
    virtual void RecvData(RealUAVStateBus *data, int32_T length, int32_T *status)
        = 0;
    virtual ~RecvData_RealUAVStateBusT()
    {
    }
};

#endif

#ifndef SS_UINT64
#define SS_UINT64                      22
#endif

#ifndef SS_INT64
#define SS_INT64                       23
#endif
#endif                                 // RTW_HEADER_DeSerOtherUAV_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
