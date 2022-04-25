//
// File: MissionModes.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.220
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun Apr 24 20:30:50 2022
//

#ifndef RTW_HEADER_MissionModes_h_
#define RTW_HEADER_MissionModes_h_
#include "rtwtypes.h"

// Enumeration class that captures all mission modes
enum class MissionModes
    : int32_T {
    CircNav = 1,
    HorzFrmnNav = 2,
    RunWayNav = 3,
    NewRunWay = 5,
    DetailedInsp = 128,
    CollAvoidance = 129,
    FlightMissionRH = 130,
    SqCalibr = 132,
    pAttack = 133,
    CircDispNav = 11,
    CustomFrmnNav = 22,
    FrmnRunWay = 33,
    ProtLine = 44,
    WaitToStart = 255,
    None = 0,                          // Default value
    TuneADRC = 252,
    ShiftENU = 254,
    ShiftXYZ = 253
};

#endif                                 // RTW_HEADER_MissionModes_h_

//
// File trailer for generated code.
//
// [EOF]
//
