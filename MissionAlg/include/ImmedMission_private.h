//
// File: ImmedMission_private.h
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 4.2
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 16:44:56 2022
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
#ifndef RTW_HEADER_ImmedMission_private_h_
#define RTW_HEADER_ImmedMission_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ImmedMission_types.h"
#include "MissionModes.h"
#include "ImmedMission.h"

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
#endif                                 // RTW_HEADER_ImmedMission_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
