//
// File: MissionModes.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.680
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Jul  2 04:32:41 2021
//

#ifndef RTW_HEADER_MissionModes_h_
#define RTW_HEADER_MissionModes_h_
#include "rtwtypes.h"

typedef enum {
    CircNav = 1,
    CircDispNav = 11,
    HorzFrmnNav = 2,
    CustomFrmnNav = 22,
    RunWayNav = 3,
    ProtLine = 4,
    DetailedInsp = 999,
    CollAvoidance = 998,
    FlightMissionRH = 997,
    WaitToStart = 67698467,
    None = 0                           // Default value
} MissionModes;

#endif                                 // RTW_HEADER_MissionModes_h_

//
// File trailer for generated code.
//
// [EOF]
//
