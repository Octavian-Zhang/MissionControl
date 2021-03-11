//
// File: codegenReal2Mission_types.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 1.343
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Mar 11 17:48:09 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
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

typedef struct {
  real_T Height;
  real_T AirSpeed;
  real_T RollAngle;
} FixedWingGuidanceControlBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceEnvironmentBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceEnvironmentBus_

typedef struct {
  real_T WindNorth;
  real_T WindEast;
  real_T WindDown;
  real_T Gravity;
} FixedWingGuidanceEnvironmentBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RealUAVStateBus_
#define DEFINED_TYPEDEF_FOR_RealUAVStateBus_

typedef struct {
  real_T Latitude_deg;
  real_T Longitude_deg;
  real_T Height_meter;
  real_T AirSpeed_mps;
  real_T HeadingAngle_deg;
  real_T FlightPathAngle_deg;
  real_T RollAngle_deg;
} RealUAVStateBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_

typedef struct {
  real_T Height;
  real_T AirSpeed;
  real_T HeadingAngle;
} FixedWingGuidanceBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceStateBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceStateBus_

typedef struct {
  real_T North;
  real_T East;
  real_T Height;
  real_T AirSpeed;
  real_T HeadingAngle;
  real_T FlightPathAngle;
  real_T RollAngle;
  real_T RollAngleRate;
} FixedWingGuidanceStateBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_LookAheadPoint_
#define DEFINED_TYPEDEF_FOR_LookAheadPoint_

typedef struct {
  real_T Latitude_deg;
  real_T Longitude_deg;
  real_T Height_meter;
} LookAheadPoint;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_pAzQu3LPpISTV2tr3rS1KE_
#define DEFINED_TYPEDEF_FOR_struct_pAzQu3LPpISTV2tr3rS1KE_

typedef struct {
  real_T PDRoll[2];
  real_T PHeight;
  real_T PFlightPathAngle;
  real_T PAirSpeed;
  real_T FlightPathAngleLimits[2];
} struct_pAzQu3LPpISTV2tr3rS1KE;

#endif

#ifndef struct_tag_DpZtOK5dGwCPaUdGDbuEQF
#define struct_tag_DpZtOK5dGwCPaUdGDbuEQF

struct tag_DpZtOK5dGwCPaUdGDbuEQF
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

#endif                                 //struct_tag_DpZtOK5dGwCPaUdGDbuEQF

#ifndef typedef_d_uav_internal_impl_fixedwing_T
#define typedef_d_uav_internal_impl_fixedwing_T

typedef tag_DpZtOK5dGwCPaUdGDbuEQF d_uav_internal_impl_fixedwing_T;

#endif                                 //typedef_d_uav_internal_impl_fixedwing_T

#ifndef struct_tag_80cOlreDzuSCuWWluR7A8F
#define struct_tag_80cOlreDzuSCuWWluR7A8F

struct tag_80cOlreDzuSCuWWluR7A8F
{
  int32_T isInitialized;
  d_uav_internal_impl_fixedwing_T OutputTemplate;
};

#endif                                 //struct_tag_80cOlreDzuSCuWWluR7A8F

#ifndef typedef_robotics_core_internal_system_T
#define typedef_robotics_core_internal_system_T

typedef tag_80cOlreDzuSCuWWluR7A8F robotics_core_internal_system_T;

#endif                                 //typedef_robotics_core_internal_system_T

#ifndef struct_tag_vxHWSOYrO9xtYchIOe7EKG
#define struct_tag_vxHWSOYrO9xtYchIOe7EKG

struct tag_vxHWSOYrO9xtYchIOe7EKG
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_vxHWSOYrO9xtYchIOe7EKG

#ifndef typedef_robotics_slcore_internal_bloc_T
#define typedef_robotics_slcore_internal_bloc_T

typedef tag_vxHWSOYrO9xtYchIOe7EKG robotics_slcore_internal_bloc_T;

#endif                                 //typedef_robotics_slcore_internal_bloc_T

#ifndef struct_tag_KSdGoEc2IyOHz4CLi4rcCD
#define struct_tag_KSdGoEc2IyOHz4CLi4rcCD

struct tag_KSdGoEc2IyOHz4CLi4rcCD
{
  int32_T __dummy;
};

#endif                                 //struct_tag_KSdGoEc2IyOHz4CLi4rcCD

#ifndef typedef_e_robotics_slcore_internal_bl_T
#define typedef_e_robotics_slcore_internal_bl_T

typedef tag_KSdGoEc2IyOHz4CLi4rcCD e_robotics_slcore_internal_bl_T;

#endif                                 //typedef_e_robotics_slcore_internal_bl_T

#ifndef struct_tag_mNPv5qrrP1EqstZULsDJuH
#define struct_tag_mNPv5qrrP1EqstZULsDJuH

struct tag_mNPv5qrrP1EqstZULsDJuH
{
  int32_T isInitialized;
  e_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                 //struct_tag_mNPv5qrrP1EqstZULsDJuH

#ifndef typedef_uav_sluav_internal_system_UAV_T
#define typedef_uav_sluav_internal_system_UAV_T

typedef tag_mNPv5qrrP1EqstZULsDJuH uav_sluav_internal_system_UAV_T;

#endif                                 //typedef_uav_sluav_internal_system_UAV_T

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_real_T

#ifndef typedef_emxArray_real_T_codegenReal2M_T
#define typedef_emxArray_real_T_codegenReal2M_T

typedef emxArray_real_T emxArray_real_T_codegenReal2M_T;

#endif                                 //typedef_emxArray_real_T_codegenReal2M_T

#ifndef struct_tag_ABWza1iaEA8Y5abywxspAD
#define struct_tag_ABWza1iaEA8Y5abywxspAD

struct tag_ABWza1iaEA8Y5abywxspAD
{
  real_T PDRoll[2];
  real_T PHeight;
  real_T PFlightPathAngle;
  real_T PAirSpeed;
  real_T FlightPathAngleLimits[2];
};

#endif                                 //struct_tag_ABWza1iaEA8Y5abywxspAD

#ifndef typedef_h_uav_internal_impl_fixedwing_T
#define typedef_h_uav_internal_impl_fixedwing_T

typedef tag_ABWza1iaEA8Y5abywxspAD h_uav_internal_impl_fixedwing_T;

#endif                                 //typedef_h_uav_internal_impl_fixedwing_T

#ifndef struct_tag_IbOa21kY7bU07ga2IA41uF
#define struct_tag_IbOa21kY7bU07ga2IA41uF

struct tag_IbOa21kY7bU07ga2IA41uF
{
  h_uav_internal_impl_fixedwing_T Configuration;
};

#endif                                 //struct_tag_IbOa21kY7bU07ga2IA41uF

#ifndef typedef_f_uav_internal_impl_fixedwing_T
#define typedef_f_uav_internal_impl_fixedwing_T

typedef tag_IbOa21kY7bU07ga2IA41uF f_uav_internal_impl_fixedwing_T;

#endif                                 //typedef_f_uav_internal_impl_fixedwing_T

#ifndef struct_tag_cRQ8LJ4aHh1ii35euuuWVE
#define struct_tag_cRQ8LJ4aHh1ii35euuuWVE

struct tag_cRQ8LJ4aHh1ii35euuuWVE
{
  int32_T isInitialized;
  f_uav_internal_impl_fixedwing_T ModelImpl;
};

#endif                                 //struct_tag_cRQ8LJ4aHh1ii35euuuWVE

#ifndef typedef_robotics_core_internal_syst_b_T
#define typedef_robotics_core_internal_syst_b_T

typedef tag_cRQ8LJ4aHh1ii35euuuWVE robotics_core_internal_syst_b_T;

#endif                                 //typedef_robotics_core_internal_syst_b_T

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 //struct_tag_PMfBDzoakfdM9QAdfx2o6D

#ifndef typedef_cell_wrap_codegenReal2Mission_T
#define typedef_cell_wrap_codegenReal2Mission_T

typedef tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_codegenReal2Mission_T;

#endif                                 //typedef_cell_wrap_codegenReal2Mission_T

#ifndef struct_tag_hTfQEE47D0mspESapJM7ZB
#define struct_tag_hTfQEE47D0mspESapJM7ZB

struct tag_hTfQEE47D0mspESapJM7ZB
{
  int32_T isInitialized;
  cell_wrap_codegenReal2Mission_T inputVarSize[5];
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

#endif                                 //struct_tag_hTfQEE47D0mspESapJM7ZB

#ifndef typedef_uav_sluav_internal_system_Orb_T
#define typedef_uav_sluav_internal_system_Orb_T

typedef tag_hTfQEE47D0mspESapJM7ZB uav_sluav_internal_system_Orb_T;

#endif                                 //typedef_uav_sluav_internal_system_Orb_T

#ifndef struct_tag_Qc4GHH92VZlAxtOz1lExsE
#define struct_tag_Qc4GHH92VZlAxtOz1lExsE

struct tag_Qc4GHH92VZlAxtOz1lExsE
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

#endif                                 //struct_tag_Qc4GHH92VZlAxtOz1lExsE

#ifndef typedef_uav_sluav_internal_system_Way_T
#define typedef_uav_sluav_internal_system_Way_T

typedef tag_Qc4GHH92VZlAxtOz1lExsE uav_sluav_internal_system_Way_T;

#endif                                 //typedef_uav_sluav_internal_system_Way_T

#ifndef SS_INT64
#define SS_INT64                       29
#endif

#ifndef SS_UINT64
#define SS_UINT64                      30
#endif
#endif                               // RTW_HEADER_codegenReal2Mission_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
