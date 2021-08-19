#ifndef RTW_HEADER_FlightMissionMode_types_h_
#define RTW_HEADER_FlightMissionMode_types_h_
#include "rtwtypes.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"

#ifndef DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_
#define DEFINED_TYPEDEF_FOR_FixedWingGuidanceBus_

struct FixedWingGuidanceBus
{
    real_T Height;
    real_T AirSpeed;
    real_T HeadingAngle;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_RunWaySegment_
#define DEFINED_TYPEDEF_FOR_RunWaySegment_

typedef enum {
    RunWaySegment_None = 0,
    RunWaySegment_Bottom,
    RunWaySegment_Left,
    RunWaySegment_Top,
    RunWaySegment_Right
} RunWaySegment;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ProtectionLineSegment_
#define DEFINED_TYPEDEF_FOR_ProtectionLineSegment_

typedef enum {
    ProtectionLineSegment_None = 0,
    ProtectionLineSegment_Init,
    ProtectionLineSegment_Left,
    ProtectionLineSegment_Top,
    ProtectionLineSegment_Right,
    ProtectionLineSegment_Bottom
} ProtectionLineSegment;

#endif

#ifndef struct_cell_wrap_FlightMissionMode_T
#define struct_cell_wrap_FlightMissionMode_T

struct cell_wrap_FlightMissionMode_T
{
    uint32_T f1[8];
};

#endif

#ifndef struct_uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T
#define struct_uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T

struct uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T
{
    int32_T isInitialized;
    cell_wrap_FlightMissionMode_T inputVarSize[5];
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

#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T

struct
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
{
    int32_T isInitialized;
};

#endif

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

#endif

#ifndef struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T
#define struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T

struct uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T
{
    int32_T isInitialized;
    cell_wrap_FlightMissionMode_T inputVarSize[3];
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

#ifndef struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T
#define struct_uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T

struct uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T
{
    int32_T isInitialized;
    cell_wrap_FlightMissionMode_T inputVarSize[3];
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[300];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    uint8_T LookaheadDistFlag;
};

#endif

#ifndef struct_cell_wrap_12_FlightMissionMode_T
#define struct_cell_wrap_12_FlightMissionMode_T

struct cell_wrap_12_FlightMissionMode_T
{
    char_T f1[7];
};

#endif

#ifndef struct_emxArray_char_T_1x2_FlightMissionMode_T
#define struct_emxArray_char_T_1x2_FlightMissionMode_T

struct emxArray_char_T_1x2_FlightMissionMode_T
{
    char_T data[2];
    int32_T size[2];
};

#endif

#ifndef struct_cell_wrap_10_FlightMissionMode_T
#define struct_cell_wrap_10_FlightMissionMode_T

struct cell_wrap_10_FlightMissionMode_T
{
    emxArray_char_T_1x2_FlightMissionMode_T f1;
};

#endif

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
    cell_wrap_10_FlightMissionMode_T MotionTypes[4];
    real_T MotionLengths[4];
    real_T Length;
};

#endif

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

#endif

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

#endif

#ifndef struct_uavDubinsConnection_FlightMissionMode_T
#define struct_uavDubinsConnection_FlightMissionMode_T

struct uavDubinsConnection_FlightMissionMode_T
{
    real_T MinTurningRadius;
    real_T AirSpeed;
    real_T MaxRollAngle;
    real_T FlightPathAngleLimit[2];
};

#endif

#ifndef struct_matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
#define struct_matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T

struct matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
{
    cell_wrap_12_FlightMissionMode_T Defaults;
    cell_wrap_12_FlightMissionMode_T ParsedResults;
};

#endif

#ifndef struct_emxArray_uavDubinsPathSegment_2_FlightMissionMode_T
#define struct_emxArray_uavDubinsPathSegment_2_FlightMissionMode_T

struct emxArray_uavDubinsPathSegment_2_FlightMissionMode_T
{
    uavDubinsPathSegment_FlightMissionMode_T data[28];
    int32_T size;
};

#endif

#ifndef struct_emxArray_int32_T_28_FlightMissionMode_T
#define struct_emxArray_int32_T_28_FlightMissionMode_T

struct emxArray_int32_T_28_FlightMissionMode_T
{
    int32_T data[28];
    int32_T size;
};

#endif

#ifndef struct_cell_wrap_1_FlightMissionMode_T
#define struct_cell_wrap_1_FlightMissionMode_T

struct cell_wrap_1_FlightMissionMode_T
{
    emxArray_char_T_1x2_FlightMissionMode_T f1;
};

#endif

#ifndef struct_uavDubinsPathSegment_FlightMissionMode_b_T
#define struct_uavDubinsPathSegment_FlightMissionMode_b_T

struct uavDubinsPathSegment_FlightMissionMode_b_T
{
    real_T StartPose[4];
    real_T GoalPose[4];
    real_T FlightPathAngle;
    real_T AirSpeed;
    real_T MinTurningRadius;
    real_T HelixRadius;
    cell_wrap_1_FlightMissionMode_T MotionTypes[4];
    real_T MotionLengths[4];
    real_T Length;
};

#endif

#ifndef struct_emxArray_uavDubinsPathSegment_2_FlightMissionMode_p_T
#define struct_emxArray_uavDubinsPathSegment_2_FlightMissionMode_p_T

struct emxArray_uavDubinsPathSegment_2_FlightMissionMode_p_T
{
    uavDubinsPathSegment_FlightMissionMode_b_T data[28];
    int32_T size;
};

#endif

typedef struct tag_RTM_FlightMissionMode_T RT_MODEL_FlightMissionMode_T;

#endif

