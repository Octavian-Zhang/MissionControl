//
// File: MissionUAV_types.h
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 2.2
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Wed Feb 23 00:20:27 2022
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
#ifndef RTW_HEADER_MissionUAV_types_h_
#define RTW_HEADER_MissionUAV_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
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

#ifndef struct_b_uav_internal_impl_fixedwing_State_MissionUAV_T
#define struct_b_uav_internal_impl_fixedwing_State_MissionUAV_T

struct b_uav_internal_impl_fixedwing_State_MissionUAV_T
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

#endif               // struct_b_uav_internal_impl_fixedwing_State_MissionUAV_T

#ifndef struct_robotics_core_internal_system_navigation_StateVector2Struct_MissionUAV_T
#define struct_robotics_core_internal_system_navigation_StateVector2Struct_MissionUAV_T

struct robotics_core_internal_system_navigation_StateVector2Struct_MissionUAV_T
{
    int32_T isInitialized;
    b_uav_internal_impl_fixedwing_State_MissionUAV_T OutputTemplate;
};

#endif
// struct_robotics_core_internal_system_navigation_StateVector2Struct_MissionUAV_T 

#ifndef struct_d_uav_internal_impl_fixedwing_Configuration_MissionUAV_T
#define struct_d_uav_internal_impl_fixedwing_Configuration_MissionUAV_T

struct d_uav_internal_impl_fixedwing_Configuration_MissionUAV_T
{
    real_T PDRoll[2];
    real_T PHeight;
    real_T PFlightPathAngle;
    real_T PAirSpeed;
    real_T FlightPathAngleLimits[2];
};

#endif       // struct_d_uav_internal_impl_fixedwing_Configuration_MissionUAV_T

#ifndef struct_c_uav_internal_impl_fixedwing_GuidanceModel_MissionUAV_T
#define struct_c_uav_internal_impl_fixedwing_GuidanceModel_MissionUAV_T

struct c_uav_internal_impl_fixedwing_GuidanceModel_MissionUAV_T
{
    d_uav_internal_impl_fixedwing_Configuration_MissionUAV_T Configuration;
};

#endif       // struct_c_uav_internal_impl_fixedwing_GuidanceModel_MissionUAV_T

#ifndef struct_robotics_core_internal_system_navigation_Model_MissionUAV_T
#define struct_robotics_core_internal_system_navigation_Model_MissionUAV_T

struct robotics_core_internal_system_navigation_Model_MissionUAV_T
{
    int32_T isInitialized;
    c_uav_internal_impl_fixedwing_GuidanceModel_MissionUAV_T ModelImpl;
};

#endif    // struct_robotics_core_internal_system_navigation_Model_MissionUAV_T

// Forward declaration for rtModel
typedef struct tag_RTM_MissionUAV_T RT_MODEL_MissionUAV_T;

#endif                                 // RTW_HEADER_MissionUAV_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
