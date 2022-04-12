//
// File: MissionModes.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.200
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Tue Apr 12 09:42:40 2022
//

#ifndef RTW_HEADER_MissionModes_h_
#define RTW_HEADER_MissionModes_h_
#include "rtwtypes.h"

// Enumeration class that captures all mission modes
typedef int32_T MissionModes;

// enum MissionModes
const MissionModes MissionModes_CircNav{ 1 };

const MissionModes MissionModes_HorzFrmnNav{ 2 };

const MissionModes MissionModes_RunWayNav{ 3 };

const MissionModes MissionModes_NewRunWay{ 5 };

const MissionModes MissionModes_DetailedInsp{ 128 };

const MissionModes MissionModes_CollAvoidance{ 129 };

const MissionModes MissionModes_FlightMissionRH{ 130 };

const MissionModes MissionModes_SqCalibr{ 132 };

const MissionModes MissionModes_pAttack{ 133 };

const MissionModes MissionModes_CircDispNav{ 11 };

const MissionModes MissionModes_CustomFrmnNav{ 22 };

const MissionModes MissionModes_FrmnRunWay{ 33 };

const MissionModes MissionModes_ProtLine{ 44 };

const MissionModes MissionModes_WaitToStart{ 255 };

const MissionModes MissionModes_None{ 0 };// Default value

const MissionModes MissionModes_TuneADRC{ 252 };

const MissionModes MissionModes_ShiftENU{ 254 };

const MissionModes MissionModes_ShiftXYZ{ 253 };

#endif                                 // RTW_HEADER_MissionModes_h_

//
// File trailer for generated code.
//
// [EOF]
//
