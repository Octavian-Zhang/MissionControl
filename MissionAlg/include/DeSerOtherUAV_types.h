//
// File: DeSerOtherUAV_types.h
//
// Code generated for Simulink model 'DeSerOtherUAV'.
//
// Model version                  : 5.1
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Nov 25 19:07:07 2022
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
#include "DatalinkInterface.h"
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
