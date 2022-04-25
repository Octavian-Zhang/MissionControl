//
// File: model_reference_types.h
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 2.12
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun Apr 24 02:57:24 2022
//
#ifndef MODEL_REFERENCE_TYPES_H
#define MODEL_REFERENCE_TYPES_H
#include "rtwtypes.h"
#ifndef MODEL_REFERENCE_TYPES
#define MODEL_REFERENCE_TYPES

//===========================================================================*
//  Model reference type definitions                                          *
// ===========================================================================
//
//  This structure is used by model reference to
//  communicate timing information through the hierarchy.

typedef struct _rtTimingBridge_tag rtTimingBridge;
struct _rtTimingBridge_tag {
    uint32_T nTasks;
    uint32_T** clockTick;
    uint32_T** clockTickH;
    uint32_T* taskCounter;
    real_T** taskTime;
    boolean_T** rateTransition;
    boolean_T *firstInitCond;
};

//
//  This structure is used by model reference to
//  communicate variable discrete rate timing information through the hierarchy.

typedef struct _rtCtrlRateMdlRefTiming_tag rtCtrlRateMdlRefTiming;
struct _rtCtrlRateMdlRefTiming_tag {
    uint32_T firstCtrlRateTID;
    uint32_T* numTicksToNextHitForCtrlRate;
};

#endif                                 // MODEL_REFERENCE_TYPES
#endif                                 // MODEL_REFERENCE_TYPES_H

//
// File trailer for generated code.
//
// [EOF]
//
