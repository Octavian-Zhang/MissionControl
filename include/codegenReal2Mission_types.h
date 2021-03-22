//
// File: codegenReal2Mission_types.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.130
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 22 15:22:27 2021
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
#ifndef RTW_HEADER_codegenReal2Mission_types_h_
#define RTW_HEADER_codegenReal2Mission_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceControlBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceControlBus_

struct FixedWingGuidanceControlBus
{
  real_T Height;
  real_T AirSpeed;
  real_T RollAngle;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceEnvironmentBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceEnvironmentBus_

struct FixedWingGuidanceEnvironmentBus
{
  real_T WindNorth;
  real_T WindEast;
  real_T WindDown;
  real_T Gravity;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_RealUAVStateBus_
#define DEFINED_TYPEDEF_FOR_RealUAVStateBus_

struct RealUAVStateBus
{
  real_T Latitude_deg;
  real_T Longitude_deg;
  real_T Height_meter;
  real_T AirSpeed_mps;
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

#ifndef DEFINED_TYPEDEF_FOR_LookAheadPoint_
#define DEFINED_TYPEDEF_FOR_LookAheadPoint_

struct LookAheadPoint
{
  real_T Latitude_deg;
  real_T Longitude_deg;
  real_T Height_meter;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_pAzQu3LPpISTV2tr3rS1KE_
#define DEFINED_TYPEDEF_FOR_struct_pAzQu3LPpISTV2tr3rS1KE_

struct struct_pAzQu3LPpISTV2tr3rS1KE
{
  real_T PDRoll[2];
  real_T PHeight;
  real_T PFlightPathAngle;
  real_T PAirSpeed;
  real_T FlightPathAngleLimits[2];
};

#endif

#ifndef struct_d_uav_internal_impl_fixedwing_T
#define struct_d_uav_internal_impl_fixedwing_T

struct d_uav_internal_impl_fixedwing_T
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

#endif                                // struct_d_uav_internal_impl_fixedwing_T

#ifndef struct_robotics_core_internal_system_T
#define struct_robotics_core_internal_system_T

struct robotics_core_internal_system_T
{
  int32_T isInitialized;
  d_uav_internal_impl_fixedwing_T OutputTemplate;
};

#endif                                // struct_robotics_core_internal_system_T

#ifndef struct_robotics_slcore_internal_bloc_T
#define struct_robotics_slcore_internal_bloc_T

struct robotics_slcore_internal_bloc_T
{
  int32_T isInitialized;
};

#endif                                // struct_robotics_slcore_internal_bloc_T

#ifndef struct_e_robotics_slcore_internal_bl_T
#define struct_e_robotics_slcore_internal_bl_T

struct e_robotics_slcore_internal_bl_T
{
  int32_T __dummy;
};

#endif                                // struct_e_robotics_slcore_internal_bl_T

#ifndef struct_uav_sluav_internal_system_UAV_T
#define struct_uav_sluav_internal_system_UAV_T

struct uav_sluav_internal_system_UAV_T
{
  int32_T isInitialized;
  e_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_uav_sluav_internal_system_UAV_T

#ifndef struct_h_uav_internal_impl_fixedwing_T
#define struct_h_uav_internal_impl_fixedwing_T

struct h_uav_internal_impl_fixedwing_T
{
  real_T PDRoll[2];
  real_T PHeight;
  real_T PFlightPathAngle;
  real_T PAirSpeed;
  real_T FlightPathAngleLimits[2];
};

#endif                                // struct_h_uav_internal_impl_fixedwing_T

#ifndef struct_f_uav_internal_impl_fixedwing_T
#define struct_f_uav_internal_impl_fixedwing_T

struct f_uav_internal_impl_fixedwing_T
{
  h_uav_internal_impl_fixedwing_T Configuration;
};

#endif                                // struct_f_uav_internal_impl_fixedwing_T

#ifndef struct_robotics_core_internal_syst_b_T
#define struct_robotics_core_internal_syst_b_T

struct robotics_core_internal_syst_b_T
{
  int32_T isInitialized;
  f_uav_internal_impl_fixedwing_T ModelImpl;
};

#endif                                // struct_robotics_core_internal_syst_b_T

#ifndef struct_cell_wrap_codegenReal2Mission_T
#define struct_cell_wrap_codegenReal2Mission_T

struct cell_wrap_codegenReal2Mission_T
{
  uint32_T f1[8];
};

#endif                                // struct_cell_wrap_codegenReal2Mission_T

#ifndef struct_uav_sluav_internal_system_Orb_T
#define struct_uav_sluav_internal_system_Orb_T

struct uav_sluav_internal_system_Orb_T
{
  int32_T isInitialized;
  cell_wrap_codegenReal2Mission_T inputVarSize[6];
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

#endif                                // struct_uav_sluav_internal_system_Orb_T

#ifndef struct_uav_sluav_internal_system_Way_T
#define struct_uav_sluav_internal_system_Way_T

struct uav_sluav_internal_system_Way_T
{
  int32_T isInitialized;
  cell_wrap_codegenReal2Mission_T inputVarSize[3];
  real_T LookaheadDistance;
  real_T WaypointIndex;
  real_T NumWaypoints;
  real_T WaypointsInternal[183];
  boolean_T LastWaypointFlag;
  boolean_T StartFlag;
  real_T InitialPose[4];
  real_T LookaheadFactor;
  boolean_T SearchFlag;
  uint8_T LookaheadDistFlag;
};

#endif                                // struct_uav_sluav_internal_system_Way_T

#ifndef struct_emxArray_real_T_codegenReal2M_T
#define struct_emxArray_real_T_codegenReal2M_T

struct emxArray_real_T_codegenReal2M_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                // struct_emxArray_real_T_codegenReal2M_T
#endif                               // RTW_HEADER_codegenReal2Mission_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
