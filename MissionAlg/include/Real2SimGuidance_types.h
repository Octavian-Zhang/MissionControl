#ifndef RTW_HEADER_Real2SimGuidance_types_h_
#define RTW_HEADER_Real2SimGuidance_types_h_
#include "rtwtypes.h"
#include "MissionModes.h"

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

#ifndef DEFINED_TYPEDEF_FOR_VectorSpeed_
#define DEFINED_TYPEDEF_FOR_VectorSpeed_

struct VectorSpeed
{
    real_T eastSpeed;
    real_T northSpeed;
    real_T skySpeed;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_TaskStatus_
#define DEFINED_TYPEDEF_FOR_TaskStatus_

struct TaskStatus
{
    int32_T FlightStatus;
    int32_T ImmedStatus;
    int32_T SequenceID;
    MissionModes MissionMode;
    int32_T numUAV;
    int32_T FormationPos;
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

#ifndef struct_cell_wrap_Real2SimGuidance_T
#define struct_cell_wrap_Real2SimGuidance_T

struct cell_wrap_Real2SimGuidance_T
{
    uint32_T f1[8];
};

#endif

#ifndef struct_uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T
#define struct_uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T

struct uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T
{
    int32_T isInitialized;
    cell_wrap_Real2SimGuidance_T inputVarSize[3];
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[219];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    boolean_T SearchFlag;
    uint8_T LookaheadDistFlag;
};

#endif

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

#endif

typedef struct tag_RTM_Real2SimGuidance_T RT_MODEL_Real2SimGuidance_T;

#endif

