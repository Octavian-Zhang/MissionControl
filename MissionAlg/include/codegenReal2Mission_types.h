#ifndef RTW_HEADER_codegenReal2Mission_types_h_
#define RTW_HEADER_codegenReal2Mission_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "DatalinkInterface.h"

#include "rtw_linux.h"
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

#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

typedef enum {
    MSG_QUEUE_UNUSED = -1,
    MSG_FIFO_QUEUE,
    MSG_LIFO_QUEUE,
    MSG_PRIORITY_QUEUE
} QueuePolicy_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_missionCmd_
#define DEFINED_TYPEDEF_FOR_Msg_missionCmd_

struct Msg_missionCmd
{
    missionCmd *fData;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Buffer_missionCmd_
#define DEFINED_TYPEDEF_FOR_Buffer_missionCmd_

struct Buffer_missionCmd
{
    boolean_T fOccupied;
    Msg_missionCmd fMsg;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MemPool_missionCmd_
#define DEFINED_TYPEDEF_FOR_MemPool_missionCmd_

struct MemPool_missionCmd
{
    missionCmd *fMemArray;
    int32_T fNumUsed;
    missionCmd **fFreeList;
    int32_T fNumFree;
    int32_T fSize;
};

#endif

#include <stdio.h>

#include "coder_posix_time.h"
#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_codegenReal2Mission_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_codegenReal2Mission_T

struct
    robotics_slcore_internal_block_CoordinateTransformationConversion_codegenReal2Mission_T
{
    int32_T isInitialized;
};

#endif

#ifndef struct_cell_wrap_codegenReal2Mission_T
#define struct_cell_wrap_codegenReal2Mission_T

struct cell_wrap_codegenReal2Mission_T
{
    uint32_T f1[8];
};

#endif

#ifndef struct_uav_sluav_internal_system_OrbitFollower_codegenReal2Mission_T
#define struct_uav_sluav_internal_system_OrbitFollower_codegenReal2Mission_T

struct uav_sluav_internal_system_OrbitFollower_codegenReal2Mission_T
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

#endif

#ifndef struct_uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T
#define struct_uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T

struct uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T
{
    int32_T isInitialized;
    cell_wrap_codegenReal2Mission_T inputVarSize[3];
    boolean_T CacheInputSizes;
    real_T LookaheadDistance;
    real_T WaypointIndex;
    real_T NumWaypoints;
    real_T WaypointsInternal[2700];
    boolean_T LastWaypointFlag;
    boolean_T StartFlag;
    real_T InitialPose[4];
    real_T LookaheadFactor;
    boolean_T SearchFlag;
    uint8_T LookaheadDistFlag;
};

#endif

#ifndef struct_emxArray_char_T_1x16_codegenReal2Mission_T
#define struct_emxArray_char_T_1x16_codegenReal2Mission_T

struct emxArray_char_T_1x16_codegenReal2Mission_T
{
    char_T data[16];
    int32_T size[2];
};

#endif

#ifndef struct_cell_wrap_1_codegenReal2Mission_T
#define struct_cell_wrap_1_codegenReal2Mission_T

struct cell_wrap_1_codegenReal2Mission_T
{
    emxArray_char_T_1x16_codegenReal2Mission_T f1;
};

#endif

#ifndef struct_emxArray_real_T_codegenReal2Mission_T
#define struct_emxArray_real_T_codegenReal2Mission_T

struct emxArray_real_T_codegenReal2Mission_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif
#endif

