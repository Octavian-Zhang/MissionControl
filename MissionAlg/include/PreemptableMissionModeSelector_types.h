//
// File: PreemptableMissionModeSelector_types.h
//
// Code generated for Simulink model 'PreemptableMissionModeSelector'.
//
// Model version                  : 2.427
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu May  6 18:30:27 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives:
//    1. Safety precaution
//    2. Execution efficiency
//    3. RAM efficiency
//    4. ROM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_PreemptableMissionModeSelector_types_h_
#define RTW_HEADER_PreemptableMissionModeSelector_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "DatalinkInterface.h"

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

#ifndef struct_cell_wrap_PreemptableMissionModeSelector_T
#define struct_cell_wrap_PreemptableMissionModeSelector_T

struct cell_wrap_PreemptableMissionModeSelector_T
{
  uint32_T f1[8];
};

#endif                     // struct_cell_wrap_PreemptableMissionModeSelector_T

#ifndef struct_uav_sluav_internal_system_OrbitFollower_PreemptableMissionModeSelector_T
#define struct_uav_sluav_internal_system_OrbitFollower_PreemptableMissionModeSelector_T

struct uav_sluav_internal_system_OrbitFollower_PreemptableMissionModeSelector_T
{
  int32_T isInitialized;
  cell_wrap_PreemptableMissionModeSelector_T inputVarSize[5];
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

#endif
// struct_uav_sluav_internal_system_OrbitFollower_PreemptableMissionModeSelector_T 

#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_PreemptableMissionModeSelector_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_PreemptableMissionModeSelector_T

struct
  robotics_slcore_internal_block_CoordinateTransformationConversion_PreemptableMissionModeSelector_T
{
  int32_T isInitialized;
};

#endif
// struct_robotics_slcore_internal_block_CoordinateTransformationConversion_PreemptableMissionModeSelector_T 

#ifndef struct_emxArray_real_T_PreemptableMissionModeSelector_T
#define struct_emxArray_real_T_PreemptableMissionModeSelector_T

struct emxArray_real_T_PreemptableMissionModeSelector_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif               // struct_emxArray_real_T_PreemptableMissionModeSelector_T

#ifndef struct_uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
#define struct_uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T

struct
  uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
{
  int32_T isInitialized;
  cell_wrap_PreemptableMissionModeSelector_T inputVarSize[3];
  real_T LookaheadDistance;
  real_T WaypointIndex;
  real_T NumWaypoints;
  real_T WaypointsInternal[30720];
  boolean_T LastWaypointFlag;
  boolean_T StartFlag;
  real_T InitialPose[4];
  real_T LookaheadFactor;
  uint8_T LookaheadDistFlag;
};

#endif
// struct_uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T 

// Custom Type definition for MATLAB Function: '<S168>/WayPointGenerator'
#ifndef struct_cell_wrap_12_PreemptableMissionModeSelector_T
#define struct_cell_wrap_12_PreemptableMissionModeSelector_T

struct cell_wrap_12_PreemptableMissionModeSelector_T
{
  char_T f1[7];
};

#endif                  // struct_cell_wrap_12_PreemptableMissionModeSelector_T

#ifndef struct_emxArray_char_T_1x2_PreemptableMissionModeSelector_T
#define struct_emxArray_char_T_1x2_PreemptableMissionModeSelector_T

struct emxArray_char_T_1x2_PreemptableMissionModeSelector_T
{
  char_T data[2];
  int32_T size[2];
};

#endif           // struct_emxArray_char_T_1x2_PreemptableMissionModeSelector_T

// Custom Type definition for MATLAB Function: '<S86>/WayPointGenerator'
#ifndef struct_cell_wrap_1_PreemptableMissionModeSelector_T
#define struct_cell_wrap_1_PreemptableMissionModeSelector_T

struct cell_wrap_1_PreemptableMissionModeSelector_T
{
  emxArray_char_T_1x2_PreemptableMissionModeSelector_T f1;
};

#endif                   // struct_cell_wrap_1_PreemptableMissionModeSelector_T

#ifndef struct_uavDubinsPathSegment_PreemptableMissionModeSelector_T
#define struct_uavDubinsPathSegment_PreemptableMissionModeSelector_T

struct uavDubinsPathSegment_PreemptableMissionModeSelector_T
{
  real_T StartPose[4];
  real_T GoalPose[4];
  real_T FlightPathAngle;
  real_T AirSpeed;
  real_T MinTurningRadius;
  real_T HelixRadius;
  cell_wrap_1_PreemptableMissionModeSelector_T MotionTypes[4];
  real_T MotionLengths[4];
  real_T Length;
};

#endif          // struct_uavDubinsPathSegment_PreemptableMissionModeSelector_T

#ifndef struct_emxArray_boolean_T_PreemptableMissionModeSelector_T
#define struct_emxArray_boolean_T_PreemptableMissionModeSelector_T

struct emxArray_boolean_T_PreemptableMissionModeSelector_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif            // struct_emxArray_boolean_T_PreemptableMissionModeSelector_T

#ifndef struct_emxArray_int32_T_PreemptableMissionModeSelector_T
#define struct_emxArray_int32_T_PreemptableMissionModeSelector_T

struct emxArray_int32_T_PreemptableMissionModeSelector_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif              // struct_emxArray_int32_T_PreemptableMissionModeSelector_T

// Custom Type definition for MATLAB Function: '<S168>/WayPointGenerator'
#ifndef struct_cell_wrap_10_PreemptableMissionModeSelector_T
#define struct_cell_wrap_10_PreemptableMissionModeSelector_T

struct cell_wrap_10_PreemptableMissionModeSelector_T
{
  emxArray_char_T_1x2_PreemptableMissionModeSelector_T f1;
};

#endif                  // struct_cell_wrap_10_PreemptableMissionModeSelector_T

#ifndef struct_uavDubinsPathSegment_PreemptableMissionModeSelector_b_T
#define struct_uavDubinsPathSegment_PreemptableMissionModeSelector_b_T

struct uavDubinsPathSegment_PreemptableMissionModeSelector_b_T
{
  real_T StartPose[4];
  real_T GoalPose[4];
  real_T FlightPathAngle;
  real_T AirSpeed;
  real_T MinTurningRadius;
  real_T HelixRadius;
  cell_wrap_10_PreemptableMissionModeSelector_T MotionTypes[4];
  real_T MotionLengths[4];
  real_T Length;
};

#endif        // struct_uavDubinsPathSegment_PreemptableMissionModeSelector_b_T

#ifndef struct_uavDubinsConnection_PreemptableMissionModeSelector_T
#define struct_uavDubinsConnection_PreemptableMissionModeSelector_T

struct uavDubinsConnection_PreemptableMissionModeSelector_T
{
  real_T MinTurningRadius;
  real_T AirSpeed;
  real_T MaxRollAngle;
  real_T FlightPathAngleLimit[2];
};

#endif           // struct_uavDubinsConnection_PreemptableMissionModeSelector_T

#ifndef struct_matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
#define struct_matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T

struct
  matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
{
  cell_wrap_12_PreemptableMissionModeSelector_T Defaults;
  cell_wrap_12_PreemptableMissionModeSelector_T ParsedResults;
};

#endif
// struct_matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T 

// Custom Type definition for MATLAB Function: '<S86>/WayPointGenerator'
#ifndef struct_emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_T
#define struct_emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_T

struct emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_T
{
  uavDubinsPathSegment_PreemptableMissionModeSelector_T data[28];
  int32_T size;
};

#endif
     // struct_emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_T

#ifndef struct_emxArray_int32_T_28_PreemptableMissionModeSelector_T
#define struct_emxArray_int32_T_28_PreemptableMissionModeSelector_T

struct emxArray_int32_T_28_PreemptableMissionModeSelector_T
{
  int32_T data[28];
  int32_T size;
};

#endif           // struct_emxArray_int32_T_28_PreemptableMissionModeSelector_T

// Custom Type definition for MATLAB Function: '<S168>/WayPointGenerator'
#ifndef struct_emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_g_T
#define struct_emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_g_T

struct emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_g_T
{
  uavDubinsPathSegment_PreemptableMissionModeSelector_b_T data[28];
  int32_T size;
};

#endif
   // struct_emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_g_T

// Forward declaration for rtModel
typedef struct tag_RTM_PreemptableMissionModeSelector_T
  RT_MODEL_PreemptableMissionModeSelector_T;

#endif                    // RTW_HEADER_PreemptableMissionModeSelector_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
