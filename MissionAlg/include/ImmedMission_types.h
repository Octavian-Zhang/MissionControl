//
// File: ImmedMission_types.h
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
#ifndef RTW_HEADER_ImmedMission_types_h_
#define RTW_HEADER_ImmedMission_types_h_
#include "rtwtypes.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"
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

#ifndef struct_cell_wrap_ImmedMission_T
#define struct_cell_wrap_ImmedMission_T

struct cell_wrap_ImmedMission_T
{
    uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_ImmedMission_T

#ifndef struct_uav_sluav_internal_system_WaypointFollower_ImmedMission_T
#define struct_uav_sluav_internal_system_WaypointFollower_ImmedMission_T

struct uav_sluav_internal_system_WaypointFollower_ImmedMission_T
{
    int32_T isInitialized;
    cell_wrap_ImmedMission_T inputVarSize[3];
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[6];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    uint8_T LookaheadDistFlag;
};

#endif      // struct_uav_sluav_internal_system_WaypointFollower_ImmedMission_T

// Custom Type definition for MATLAB Function: '<S57>/ReadHomePoint'
#include <stdio.h>
#ifndef struct_uav_sluav_internal_system_OrbitFollower_ImmedMission_T
#define struct_uav_sluav_internal_system_OrbitFollower_ImmedMission_T

struct uav_sluav_internal_system_OrbitFollower_ImmedMission_T
{
    int32_T isInitialized;
    real_T NumCircles;
    real_T PrevPosition[3];
    boolean_T StartFlag;
    real_T LookaheadDistance;
    boolean_T SelectTurnDirectionFlag;
    real_T TurnDirectionInternal;
    real_T OrbitCenterInternal[3];
    real_T OrbitRadiusInternal;
    uint8_T OrbitRadiusFlag;
    uint8_T LookaheadDistFlag;
    real_T PrevResetSignal;
};

#endif         // struct_uav_sluav_internal_system_OrbitFollower_ImmedMission_T

#ifndef struct_emxArray_char_T_ImmedMission_T
#define struct_emxArray_char_T_ImmedMission_T

struct emxArray_char_T_ImmedMission_T
{
    char_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                                 // struct_emxArray_char_T_ImmedMission_T

// Forward declaration for rtModel
typedef struct tag_RTM_ImmedMission_T RT_MODEL_ImmedMission_T;

#endif                                 // RTW_HEADER_ImmedMission_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
