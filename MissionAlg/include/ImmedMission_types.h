//
// File: ImmedMission_types.h
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 3.19
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Jul 25 10:04:08 2022
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

// Model Code Variants
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

#ifndef DEFINED_TYPEDEF_FOR_RealUAVStateBus_
#define DEFINED_TYPEDEF_FOR_RealUAVStateBus_

struct RealUAVStateBus
{
    int32_T UAV_ID;
    real_T Latitude_deg;
    real_T Longitude_deg;
    real_T Height_meter;
    real_T Altitude_meter;
    real_T AirSpeed_mps;
    real_T GndSpd_mps;
    real_T HeadingAngle_deg;
    real_T FlightPathAngle_deg;
    real_T RollAngle_deg;
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

#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_ImmedMission_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_ImmedMission_T

struct
    robotics_slcore_internal_block_CoordinateTransformationConversion_ImmedMission_T
{
    int32_T isInitialized;
};

#endif
// struct_robotics_slcore_internal_block_CoordinateTransformationConversion_ImmedMission_T 

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

// Custom Type definition for MATLAB Function: '<S63>/BaseWayPoint'
#include <stdio.h>
#ifndef struct_uavDubinsConnection_ImmedMission_T
#define struct_uavDubinsConnection_ImmedMission_T

struct uavDubinsConnection_ImmedMission_T
{
    real_T MinTurningRadius;
    real_T AirSpeed;
    real_T MaxRollAngle;
};

#endif                             // struct_uavDubinsConnection_ImmedMission_T

#ifndef struct_DubinsObjSingleton_ImmedMission_T
#define struct_DubinsObjSingleton_ImmedMission_T

struct DubinsObjSingleton_ImmedMission_T
{
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
    uavDubinsConnection_ImmedMission_T Connector;
};

#endif                              // struct_DubinsObjSingleton_ImmedMission_T

#ifndef struct_emxArray_real_T_ImmedMission_T
#define struct_emxArray_real_T_ImmedMission_T

struct emxArray_real_T_ImmedMission_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                                 // struct_emxArray_real_T_ImmedMission_T

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

#ifndef struct_uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T
#define struct_uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T

struct uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T
{
    int32_T isInitialized;
    cell_wrap_ImmedMission_T inputVarSize[3];
    boolean_T CacheInputSizes;
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[30723];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    uint8_T LookaheadDistFlag;
};

#endif    // struct_uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T

// Forward declaration for rtModel
typedef struct tag_RTM_ImmedMission_T RT_MODEL_ImmedMission_T;

#endif                                 // RTW_HEADER_ImmedMission_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
