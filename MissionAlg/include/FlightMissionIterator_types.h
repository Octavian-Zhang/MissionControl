//
// File: FlightMissionIterator_types.h
//
// Code generated for Simulink model 'FlightMissionIterator'.
//
// Model version                  : 2.17
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:25:10 2022
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
#ifndef RTW_HEADER_FlightMissionIterator_types_h_
#define RTW_HEADER_FlightMissionIterator_types_h_
#include "rtwtypes.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"
#ifndef DEFINED_TYPEDEF_FOR_missionCmd_
#define DEFINED_TYPEDEF_FOR_missionCmd_

struct missionCmd
{
    int32_T SequenceID;
    MissionModes MissionMode;
    Location MissionLocation;
    Parameters params;
    Location StartPosition;
    int32_T numUAV;
    int32_T FormationPos;
    real_T StartTime;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_

struct FixedWingGuidanceBus
{
    real_T Height;
    real_T AirSpeed;
    real_T HeadingAngle;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceStateBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceStateBus_

struct FixedWingGuidanceStateBus
{
    real_T North;
    real_T East;
    real_T Height;
    real_T AirSpeed;
    real_T HeadingAngle;
    real_T FlightPathAngle;
    real_T RollAngle;
    real_T RollAngleRate;
};

#endif

#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionIterator_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionIterator_T

struct
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionIterator_T
{
    int32_T isInitialized;
};

#endif
// struct_robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionIterator_T 

// Forward declaration for rtModel
typedef struct tag_RTM_FlightMissionIterator_T RT_MODEL_FlightMissionIterator_T;

#endif                             // RTW_HEADER_FlightMissionIterator_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
