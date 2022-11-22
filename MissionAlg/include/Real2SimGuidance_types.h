//
// File: Real2SimGuidance_types.h
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 5.10
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:19:22 2022
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
    uint8_T FlightMode;
    boolean_T AvoidDanger;
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
    VectorSpeed VectorSpd;
    Time TimeNow;
    ADRC ADRC_Log;
};

#endif

// Custom Type definition for MATLAB Function: '<S6>/ReadHomePoint'
#include <stdio.h>
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

// Custom Type definition for MATLAB Function: '<S15>/getLAPGainBias'
#ifndef struct_s88w9UDFTziuJLEYZbYNZfH_Real2SimGuidance_T
#define struct_s88w9UDFTziuJLEYZbYNZfH_Real2SimGuidance_T

struct s88w9UDFTziuJLEYZbYNZfH_Real2SimGuidance_T
{
    real_T Gain;
    real_T Bias;
};

#endif                     // struct_s88w9UDFTziuJLEYZbYNZfH_Real2SimGuidance_T

#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T

struct
    robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T
{
    int32_T isInitialized;
};

#endif
// struct_robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T 

// Custom Type definition for MATLAB Function: '<S99>/getSpeedLimit'
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
    real_T PolarObstacleDensity[120];
    boolean_T BinaryHistogram[120];
    boolean_T MaskedHistogram[120];
    real_T PreviousDirection;
    real_T AngularSectorMidPoints[120];
    real_T AngularDifference;
    real_T AngularSectorStartPoints[120];
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

// Custom Type definition for MATLAB Function: '<S99>/getSpeedLimit'
#ifndef struct_DubinsObjSingleton_Real2SimGuidance_f_T
#define struct_DubinsObjSingleton_Real2SimGuidance_f_T

struct DubinsObjSingleton_Real2SimGuidance_f_T
{
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
    real_T SpdLmt[2];
    uavDubinsConnection_Real2SimGuidance_T Connector;
};

#endif                        // struct_DubinsObjSingleton_Real2SimGuidance_f_T

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

#ifndef struct_emxArray_int32_T_Real2SimGuidance_T
#define struct_emxArray_int32_T_Real2SimGuidance_T

struct emxArray_int32_T_Real2SimGuidance_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                            // struct_emxArray_int32_T_Real2SimGuidance_T

// Forward declaration for rtModel
typedef struct tag_RTM_Real2SimGuidance_T RT_MODEL_Real2SimGuidance_T;

#endif                                 // RTW_HEADER_Real2SimGuidance_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
