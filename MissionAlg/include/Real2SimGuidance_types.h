//
// File: Real2SimGuidance_types.h
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 4.127
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun May 22 08:38:50 2022
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
#ifndef RTW_HEADER_Real2SimGuidance_types_h_
#define RTW_HEADER_Real2SimGuidance_types_h_
#include "rtwtypes.h"
#include "DatalinkInterface.h"

// Model Code Variants
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

#ifndef DEFINED_TYPEDEF_FOR_VectorSpeed_
#define DEFINED_TYPEDEF_FOR_VectorSpeed_

struct VectorSpeed
{
    real_T eastSpeed;
    real_T northSpeed;
    real_T skySpeed;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_StateFCU_
#define DEFINED_TYPEDEF_FOR_StateFCU_

struct StateFCU
{
    RealUAVStateBus RealUAVState;
    real_T GndSpd_mps;
    real_T Altitude;
    VectorSpeed VecSpd;
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

#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_

struct FixedWingGuidanceBus
{
    real_T Height;
    real_T AirSpeed;
    real_T HeadingAngle;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_ParamADRC_
#define DEFINED_TYPEDEF_FOR_ParamADRC_

struct ParamADRC
{
    real_T hat_b;
    real_T omega_o;
    real_T omega_c;
    real_T P;
    real_T I;
    real_T D;
    boolean_T useADRC;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_ADRC_
#define DEFINED_TYPEDEF_FOR_ADRC_

struct ADRC
{
    real_T x1_ControlError;
    real_T x2;
    real_T x3_TotalDisturbance;
    real_T u;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_FCUCMD_
#define DEFINED_TYPEDEF_FOR_FCUCMD_

struct FCUCMD
{
    real_T Latitude_deg;
    real_T Longitude_deg;
    real_T Height_meter;
    real_T RefAirSpd_mps;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_InternalStatus_
#define DEFINED_TYPEDEF_FOR_InternalStatus_

struct InternalStatus
{
    real_T LagDistance;
    real_T CrossTrackError;
    real_T EngagedFlag;
    real_T RealHeading;
    real_T TargetHeading;
    real_T HeadingDiff;
    real_T biasH;
    boolean_T HdgStatus;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MiscellaneousFlightStatus_
#define DEFINED_TYPEDEF_FOR_MiscellaneousFlightStatus_

struct MiscellaneousFlightStatus
{
    real_T GroundSpeed;
    uint8_T FlightMode;
    real_T Altitude;
    real_T FlightPath;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_FlightLogging_
#define DEFINED_TYPEDEF_FOR_FlightLogging_

struct FlightLogging
{
    RealUAVStateBus RealUAVState;
    FixedWingGuidanceStateBus SimUAVState;
    FCUCMD FlightCMD;
    InternalStatus InnerState;
    MiscellaneousFlightStatus MiscStatus;
    VectorSpeed VectorSpd;
    Time TimeNow;
    ADRC ADRC_Log;
};

#endif

// Custom Type definition for MATLAB Function: '<S91>/getSpeedLimit'
#include <stdio.h>
#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T

struct
    robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T
{
    int32_T isInitialized;
};

#endif
// struct_robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T 

// Custom Type definition for MATLAB Function: '<S91>/getSpeedLimit'
#ifndef struct_uavDubinsConnection_Real2SimGuidance_T
#define struct_uavDubinsConnection_Real2SimGuidance_T

struct uavDubinsConnection_Real2SimGuidance_T
{
    real_T AirSpeed;
    real_T MaxRollAngle;
};

#endif                         // struct_uavDubinsConnection_Real2SimGuidance_T

// Custom Type definition for MATLAB Function: '<Root>/TimeNow'
#include "coder_posix_time.h"
#ifndef struct_d_cell_wrap_Real2SimGuidance_T
#define struct_d_cell_wrap_Real2SimGuidance_T

struct d_cell_wrap_Real2SimGuidance_T
{
    real_T f1[2];
};

#endif                                 // struct_d_cell_wrap_Real2SimGuidance_T

#ifndef struct_cell_wrap_Real2SimGuidance_T
#define struct_cell_wrap_Real2SimGuidance_T

struct cell_wrap_Real2SimGuidance_T
{
    uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_Real2SimGuidance_T

#ifndef struct_nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T
#define struct_nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T

struct nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T
{
    int32_T isInitialized;
    cell_wrap_Real2SimGuidance_T inputVarSize[3];
    boolean_T CacheInputSizes;
    real_T NarrowOpeningThreshold;
    real_T DistanceLimits[2];
    real_T RobotRadius;
    real_T SafetyDistance;
    real_T MinTurningRadius;
    real_T TargetDirectionWeight;
    real_T CurrentDirectionWeight;
    real_T PreviousDirectionWeight;
    real_T HistogramThresholds[2];
    real_T PolarObstacleDensity[360];
    boolean_T BinaryHistogram[360];
    boolean_T MaskedHistogram[360];
    real_T PreviousDirection;
    real_T AngularSectorMidPoints[360];
    real_T AngularDifference;
    real_T AngularSectorStartPoints[360];
    real_T AngularLimits[2];
};

#endif    // struct_nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T

#ifndef struct_robotics_core_internal_NameValueParser_Real2SimGuidance_T
#define struct_robotics_core_internal_NameValueParser_Real2SimGuidance_T

struct robotics_core_internal_NameValueParser_Real2SimGuidance_T
{
    d_cell_wrap_Real2SimGuidance_T Defaults[2];
    d_cell_wrap_Real2SimGuidance_T ParsedResults[2];
};

#endif      // struct_robotics_core_internal_NameValueParser_Real2SimGuidance_T

// Custom Type definition for MATLAB Function: '<Root>/Get Nominal Flight Speed' 
#ifndef struct_DubinsObjSingleton_Real2SimGuidance_T
#define struct_DubinsObjSingleton_Real2SimGuidance_T

struct DubinsObjSingleton_Real2SimGuidance_T
{
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
    uavDubinsConnection_Real2SimGuidance_T Connector;
};

#endif                          // struct_DubinsObjSingleton_Real2SimGuidance_T

#ifndef struct_uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T
#define struct_uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T

struct uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T
{
    int32_T isInitialized;
    cell_wrap_Real2SimGuidance_T inputVarSize[3];
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[651];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    boolean_T SearchFlag;
    uint8_T LookaheadDistFlag;
};

#endif  // struct_uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T

// Custom Type definition for MATLAB Function: '<S91>/getSpeedLimit'
#ifndef struct_DubinsObjSingleton_Real2SimGuidance_h_T
#define struct_DubinsObjSingleton_Real2SimGuidance_h_T

struct DubinsObjSingleton_Real2SimGuidance_h_T
{
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
    real_T SpdLmt[2];
    uavDubinsConnection_Real2SimGuidance_T Connector;
};

#endif                        // struct_DubinsObjSingleton_Real2SimGuidance_h_T

#ifndef struct_emxArray_real_T_Real2SimGuidance_T
#define struct_emxArray_real_T_Real2SimGuidance_T

struct emxArray_real_T_Real2SimGuidance_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                             // struct_emxArray_real_T_Real2SimGuidance_T

#ifndef struct_emxArray_char_T_Real2SimGuidance_T
#define struct_emxArray_char_T_Real2SimGuidance_T

struct emxArray_char_T_Real2SimGuidance_T
{
    char_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                             // struct_emxArray_char_T_Real2SimGuidance_T

#ifndef struct_emxArray_boolean_T_Real2SimGuidance_T
#define struct_emxArray_boolean_T_Real2SimGuidance_T

struct emxArray_boolean_T_Real2SimGuidance_T
{
    boolean_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                          // struct_emxArray_boolean_T_Real2SimGuidance_T

// Forward declaration for rtModel
typedef struct tag_RTM_Real2SimGuidance_T RT_MODEL_Real2SimGuidance_T;

#endif                                 // RTW_HEADER_Real2SimGuidance_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
