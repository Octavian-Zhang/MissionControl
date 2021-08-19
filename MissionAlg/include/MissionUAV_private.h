#ifndef RTW_HEADER_MissionUAV_private_h_
#define RTW_HEADER_MissionUAV_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "zero_crossing_types.h"

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ( *((rtm)->timingBridge->firstInitCond) )
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MINOR_TIME_STEP)
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
#endif

