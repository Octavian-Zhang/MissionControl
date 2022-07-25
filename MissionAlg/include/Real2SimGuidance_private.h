//
// File: Real2SimGuidance_private.h
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 4.175
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Jul 25 10:07:06 2022
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
#ifndef RTW_HEADER_Real2SimGuidance_private_h_
#define RTW_HEADER_Real2SimGuidance_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "Real2SimGuidance.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtm)->timingBridge->taskCounter[(rtm)->Timing.mdlref_GlobalTID[sti]] == 0)
#endif

// Macros for accessing real-time model data structure
#ifndef rtmGetClockTick0
#define rtmGetClockTick0(rtm)          ( *(((rtm)->timingBridge->clockTick[(rtm)->Timing.mdlref_GlobalTID[0]])) )
#endif

#ifndef rtmGetClockTick1
#define rtmGetClockTick1(rtm)          ( *(((rtm)->timingBridge->clockTick[(rtm)->Timing.mdlref_GlobalTID[1]])) )
#endif

#ifndef rtmGetClockTickH0
#define rtmGetClockTickH0(rtm)         ( *((rtm)->timingBridge->clockTickH[(rtm)->Timing.mdlref_GlobalTID[0]]) )
#endif

#ifndef rtmGetClockTickH1
#define rtmGetClockTickH1(rtm)         ( *((rtm)->timingBridge->clockTickH[(rtm)->Timing.mdlref_GlobalTID[1]]) )
#endif

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

extern const real_T rtCP_pooled_ipsVxvhx7TJb[2];
extern const real_T rtCP_pooled_3GEHLKxQAnae[2];
extern const real_T rtCP_pooled_ibeJeFBArgtC[2];
extern const real_T rtCP_pooled_DIpj1z6HREP5[2];
extern const real_T rtCP_pooled_f3N7kzzFdIss[2];

#define rtCP_Cartesian2Polar_RngLmt    rtCP_pooled_ipsVxvhx7TJb  // Expression: RngLmt
                                                                 //  Referenced by: '<S16>/Cartesian2Polar'

#define rtCP_VectorFieldHistogram10_DistanceLimits rtCP_pooled_3GEHLKxQAnae// Expression: RngLmt
                                                                      //  Referenced by: '<S39>/VectorFieldHistogram10'

#define rtCP_VectorFieldHistogram10_HistogramThresholds rtCP_pooled_ibeJeFBArgtC// Expression: HistThrshld*10
                                                                      //  Referenced by: '<S39>/VectorFieldHistogram10'

#define rtCP_VectorFieldHistogram_DistanceLimits rtCP_pooled_DIpj1z6HREP5// Expression: RngLmt
                                                                      //  Referenced by: '<S17>/Vector Field Histogram'

#define rtCP_VectorFieldHistogram_HistogramThresholds rtCP_pooled_f3N7kzzFdIss// Expression: HistThrshld
                                                                      //  Referenced by: '<S17>/Vector Field Histogram'

#endif                                // RTW_HEADER_Real2SimGuidance_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
