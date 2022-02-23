//
// File: codegenReal2Mission_types.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.91
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Wed Feb 23 00:38:39 2022
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
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "DatalinkInterface.h"

// Model Code Variants
#include "rtw_linux.h"
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

#ifndef DEFINED_TYPEDEF_FOR_TaskStatus_
#define DEFINED_TYPEDEF_FOR_TaskStatus_

struct TaskStatus
{
    boolean_T EngagedFlag;
    int32_T FlightStatus;
    int32_T ImmedStatus;
    int32_T SequenceID;
    MissionModes MissionMode;
    int32_T numUAV;
    int32_T FormationPos;
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

#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

typedef enum {
    MSG_QUEUE_UNUSED = -1,             // Default value
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

// Custom Type definition for MATLAB Function: '<S6>/CommandCheck'
#include <stdio.h>

// Custom Type definition for MATLAB Function: '<S6>/getCurrentTime'
#include "coder_posix_time.h"
#ifndef struct_robotics_slcore_internal_block_CoordinateTransformationConversion_codegenReal2Mission_T
#define struct_robotics_slcore_internal_block_CoordinateTransformationConversion_codegenReal2Mission_T

struct
    robotics_slcore_internal_block_CoordinateTransformationConversion_codegenReal2Mission_T
{
    int32_T isInitialized;
};

#endif
// struct_robotics_slcore_internal_block_CoordinateTransformationConversion_codegenReal2Mission_T 

#ifndef struct_b_robotics_slcore_internal_block_SampleTimeImpl_codegenReal2Mission_T
#define struct_b_robotics_slcore_internal_block_SampleTimeImpl_codegenReal2Mission_T

struct b_robotics_slcore_internal_block_SampleTimeImpl_codegenReal2Mission_T
{
    int32_T __dummy;
};

#endif
// struct_b_robotics_slcore_internal_block_SampleTimeImpl_codegenReal2Mission_T

#ifndef struct_uav_sluav_internal_system_UAVAnimation_codegenReal2Mission_T
#define struct_uav_sluav_internal_system_UAVAnimation_codegenReal2Mission_T

struct uav_sluav_internal_system_UAVAnimation_codegenReal2Mission_T
{
    int32_T isInitialized;
    b_robotics_slcore_internal_block_SampleTimeImpl_codegenReal2Mission_T
        SampleTimeHandler;
};

#endif   // struct_uav_sluav_internal_system_UAVAnimation_codegenReal2Mission_T

#ifndef struct_emxArray_char_T_1x16_codegenReal2Mission_T
#define struct_emxArray_char_T_1x16_codegenReal2Mission_T

struct emxArray_char_T_1x16_codegenReal2Mission_T
{
    char_T data[16];
    int32_T size[2];
};

#endif                     // struct_emxArray_char_T_1x16_codegenReal2Mission_T

// Custom Type definition for MATLAB Function: '<S9>/PrintOnboardLog'
#ifndef struct_cell_wrap_1_codegenReal2Mission_T
#define struct_cell_wrap_1_codegenReal2Mission_T

struct cell_wrap_1_codegenReal2Mission_T
{
    emxArray_char_T_1x16_codegenReal2Mission_T f1;
};

#endif                              // struct_cell_wrap_1_codegenReal2Mission_T
#endif                               // RTW_HEADER_codegenReal2Mission_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
