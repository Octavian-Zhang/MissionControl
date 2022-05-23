//
// File: MissionUAV_private.h
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun May 22 08:36:10 2022
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
#ifndef RTW_HEADER_MissionUAV_private_h_
#define RTW_HEADER_MissionUAV_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "zero_crossing_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ( *((rtm)->timingBridge->firstInitCond) )
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MINOR_TIME_STEP)
#endif

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         (*((rtm)->Timing.simTimeStep))
#endif

#ifndef rtmGetSimTimeStepPointer
#define rtmGetSimTimeStepPointer(rtm)  (rtm)->Timing.simTimeStep
#endif

#ifndef rtmSetSimTimeStepPointer
#define rtmSetSimTimeStepPointer(rtm, val) ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       (*((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  (*((rtm)->Timing.stopRequestedFlag) = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedPtr
#define rtmSetStopRequestedPtr(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (*((rtm)->timingBridge->taskTime[0]))
#endif
#endif                                 // RTW_HEADER_MissionUAV_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
