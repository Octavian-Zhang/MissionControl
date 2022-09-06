//
// File: FlightMissionMode_types.h
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 3.37
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Sep  6 11:59:48 2022
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
#ifndef RTW_HEADER_FlightMissionMode_types_h_
#define RTW_HEADER_FlightMissionMode_types_h_
#include "rtwtypes.h"
#include "DatalinkInterface.h"
#include "MissionModes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_

struct FixedWingGuidanceBus
{
    real_T Height;
    real_T AirSpeed;
    real_T HeadingAngle;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_RunWayLineSegment_
#define DEFINED_TYPEDEF_FOR_RunWayLineSegment_

enum class RunWayLineSegment
    : int32_T {
    None = 0,                          // Default value
    Init,
    Left,
    Top,
    Right,
    Bottom
};

#endif

#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T

struct
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
{
    int32_T isInitialized;
};

#endif
// struct_robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T 

#ifndef struct_cell_wrap_FlightMissionMode_T
#define struct_cell_wrap_FlightMissionMode_T

struct cell_wrap_FlightMissionMode_T
{
    uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_FlightMissionMode_T

#ifndef struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T
#define struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T

struct uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T
{
    int32_T isInitialized;
    cell_wrap_FlightMissionMode_T inputVarSize[3];
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[384];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    uint8_T LookaheadDistFlag;
};

#endif // struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T

// Custom Type definition for MATLAB Function: '<S96>/StartPointGenerator'
#include <stdio.h>
#ifndef struct_emxArray_char_T_1x2_FlightMissionMode_T
#define struct_emxArray_char_T_1x2_FlightMissionMode_T

struct emxArray_char_T_1x2_FlightMissionMode_T
{
    char_T data[2];
    int32_T size[2];
};

#endif                        // struct_emxArray_char_T_1x2_FlightMissionMode_T

// Custom Type definition for MATLAB Function: '<S96>/StartPointGenerator'
#ifndef struct_cell_wrap_0_FlightMissionMode_T
#define struct_cell_wrap_0_FlightMissionMode_T

struct cell_wrap_0_FlightMissionMode_T
{
    emxArray_char_T_1x2_FlightMissionMode_T f1;
};

#endif                                // struct_cell_wrap_0_FlightMissionMode_T

#ifndef struct_uavDubinsPathSegment_FlightMissionMode_T
#define struct_uavDubinsPathSegment_FlightMissionMode_T

struct uavDubinsPathSegment_FlightMissionMode_T
{
    real_T StartPose[4];
    real_T GoalPose[4];
    real_T FlightPathAngle;
    real_T AirSpeed;
    real_T MinTurningRadius;
    real_T HelixRadius;
    cell_wrap_0_FlightMissionMode_T MotionTypes[4];
    real_T MotionLengths[4];
    real_T Length;
};

#endif                       // struct_uavDubinsPathSegment_FlightMissionMode_T

#ifndef struct_emxArray_real_T_FlightMissionMode_T
#define struct_emxArray_real_T_FlightMissionMode_T

struct emxArray_real_T_FlightMissionMode_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                            // struct_emxArray_real_T_FlightMissionMode_T

#ifndef struct_emxArray_char_T_FlightMissionMode_T
#define struct_emxArray_char_T_FlightMissionMode_T

struct emxArray_char_T_FlightMissionMode_T
{
    char_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                            // struct_emxArray_char_T_FlightMissionMode_T

// Custom Type definition for MATLAB Function: '<S96>/StartPointGenerator'
#ifndef struct_cell_wrap_22_FlightMissionMode_T
#define struct_cell_wrap_22_FlightMissionMode_T

struct cell_wrap_22_FlightMissionMode_T
{
    cell_wrap_0_FlightMissionMode_T f1[4];
};

#endif                               // struct_cell_wrap_22_FlightMissionMode_T

#ifndef struct_emxArray_boolean_T_FlightMissionMode_T
#define struct_emxArray_boolean_T_FlightMissionMode_T

struct emxArray_boolean_T_FlightMissionMode_T
{
    boolean_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                         // struct_emxArray_boolean_T_FlightMissionMode_T

#ifndef struct_emxArray_int32_T_FlightMissionMode_T
#define struct_emxArray_int32_T_FlightMissionMode_T

struct emxArray_int32_T_FlightMissionMode_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                           // struct_emxArray_int32_T_FlightMissionMode_T

// Custom Type definition for MATLAB Function: '<S96>/StartPointGenerator'
#ifndef struct_uavDubinsConnection_FlightMissionMode_T
#define struct_uavDubinsConnection_FlightMissionMode_T

struct uavDubinsConnection_FlightMissionMode_T
{
    real_T MinTurningRadius;
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
};

#endif                        // struct_uavDubinsConnection_FlightMissionMode_T

#ifndef struct_DubinsObjSingleton_FlightMissionMode_T
#define struct_DubinsObjSingleton_FlightMissionMode_T

struct DubinsObjSingleton_FlightMissionMode_T
{
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
    uavDubinsConnection_FlightMissionMode_T Connector;
};

#endif                         // struct_DubinsObjSingleton_FlightMissionMode_T

#ifndef struct_emxArray_int32_T_28_FlightMissionMode_T
#define struct_emxArray_int32_T_28_FlightMissionMode_T

struct emxArray_int32_T_28_FlightMissionMode_T
{
    int32_T data[28];
    int32_T size;
};

#endif                        // struct_emxArray_int32_T_28_FlightMissionMode_T

// Custom Type definition for MATLAB Function: '<S96>/WayPointGenerator'
#ifndef struct_uavDubinsConnection_FlightMissionMode_c_T
#define struct_uavDubinsConnection_FlightMissionMode_c_T

struct uavDubinsConnection_FlightMissionMode_c_T
{
    real_T MinTurningRadius;
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
};

#endif                      // struct_uavDubinsConnection_FlightMissionMode_c_T

#ifndef struct_DubinsObjSingleton_FlightMissionMode_b_T
#define struct_DubinsObjSingleton_FlightMissionMode_b_T

struct DubinsObjSingleton_FlightMissionMode_b_T
{
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
    uavDubinsConnection_FlightMissionMode_c_T Connector;
};

#endif                       // struct_DubinsObjSingleton_FlightMissionMode_b_T

#ifndef struct_cell_wrap_11_FlightMissionMode_T
#define struct_cell_wrap_11_FlightMissionMode_T

struct cell_wrap_11_FlightMissionMode_T
{
    emxArray_char_T_1x2_FlightMissionMode_T f1;
};

#endif                               // struct_cell_wrap_11_FlightMissionMode_T

#ifndef struct_uavDubinsPathSegment_FlightMissionMode_g_T
#define struct_uavDubinsPathSegment_FlightMissionMode_g_T

struct uavDubinsPathSegment_FlightMissionMode_g_T
{
    real_T StartPose[4];
    real_T GoalPose[4];
    real_T FlightPathAngle;
    real_T AirSpeed;
    real_T MinTurningRadius;
    real_T HelixRadius;
    cell_wrap_11_FlightMissionMode_T MotionTypes[4];
    real_T MotionLengths[4];
    real_T Length;
};

#endif                     // struct_uavDubinsPathSegment_FlightMissionMode_g_T

#ifndef struct_cell_wrap_22_FlightMissionMode_h_T
#define struct_cell_wrap_22_FlightMissionMode_h_T

struct cell_wrap_22_FlightMissionMode_h_T
{
    cell_wrap_11_FlightMissionMode_T f1[4];
};

#endif                             // struct_cell_wrap_22_FlightMissionMode_h_T

#ifndef struct_uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T
#define struct_uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T

struct uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T
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

#endif    // struct_uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T

// Custom Type definition for MATLAB Function: '<S181>/WayPointGenerator'
#include <stdio.h>
#ifndef struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T
#define struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T

struct uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T
{
    int32_T isInitialized;
    cell_wrap_FlightMissionMode_T inputVarSize[3];
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[24576];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    uint8_T LookaheadDistFlag;
};

#endif
     // struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T

#ifndef struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T
#define struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T

struct uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T
{
    int32_T isInitialized;
    cell_wrap_FlightMissionMode_T inputVarSize[3];
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[24576];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    boolean_T SearchFlag;
    uint8_T LookaheadDistFlag;
};

#endif
    // struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T
#endif                                 // RTW_HEADER_FlightMissionMode_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
