//
// File: codegenReal2Mission_types.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.143
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Jul 25 00:08:05 2022
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
#include "DatalinkInterface.h"
#include "MissionModes.h"
#include "rtw_linux.h"

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

#ifndef DEFINED_TYPEDEF_FOR_TaskStatus_
#define DEFINED_TYPEDEF_FOR_TaskStatus_

struct TaskStatus
{
    uint8_T EngagedFlag;
    int32_T FlightStatus;
    int32_T ImmedStatus;
    int32_T SequenceID;
    MissionModes MissionMode;
    int32_T numUAV;
    int32_T FormationPos;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

enum class QueuePolicy_T
    : int32_T {
    MSG_QUEUE_UNUSED = -1,             // Default value
    MSG_FIFO_QUEUE,
    MSG_LIFO_QUEUE,
    MSG_PRIORITY_QUEUE
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_IndividualUAVCmd_
#define DEFINED_TYPEDEF_FOR_Msg_IndividualUAVCmd_

struct Msg_IndividualUAVCmd
{
    IndividualUAVCmd *fData;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Queue_IndividualUAVCmd_
#define DEFINED_TYPEDEF_FOR_Queue_IndividualUAVCmd_

struct Queue_IndividualUAVCmd
{
    QueuePolicy_T fPolicy;
    int32_T fHead;
    int32_T fTail;
    int32_T fCapacity;
    Msg_IndividualUAVCmd *fArray;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Buffer_IndividualUAVCmd_
#define DEFINED_TYPEDEF_FOR_Buffer_IndividualUAVCmd_

struct Buffer_IndividualUAVCmd
{
    boolean_T fOccupied;
    Msg_IndividualUAVCmd fMsg;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MemPool_IndividualUAVCmd_
#define DEFINED_TYPEDEF_FOR_MemPool_IndividualUAVCmd_

struct MemPool_IndividualUAVCmd
{
    IndividualUAVCmd *fMemArray;
    int32_T fNumUsed;
    IndividualUAVCmd **fFreeList;
    int32_T fNumFree;
    int32_T fSize;
};

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

#ifndef DEFINED_TYPEDEF_FOR_SendData_FlightLoggingT_
#define DEFINED_TYPEDEF_FOR_SendData_FlightLoggingT_

class SendData_FlightLoggingT
{
  public:
    virtual void SendData(const FlightLogging *data, int32_T length, int32_T
                          *status) = 0;
    virtual ~SendData_FlightLoggingT()
    {
    }
};

#endif

// Custom Type definition for MATLAB Function: '<S71>/PrintOnboardLog'
#include <stdio.h>

// Custom Type definition for MATLAB Function: '<S59>/getCurrentTime'
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

#ifndef struct_emxArray_real_T_1x4_codegenReal2Mission_T
#define struct_emxArray_real_T_1x4_codegenReal2Mission_T

struct emxArray_real_T_1x4_codegenReal2Mission_T
{
    real_T data[4];
    int32_T size[2];
};

#endif                      // struct_emxArray_real_T_1x4_codegenReal2Mission_T

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

#endif                          // struct_emxArray_real_T_codegenReal2Mission_T

// Custom Type definition for MATLAB Function: '<S10>/getDangerList'
#ifndef struct_DangerArray_codegenReal2Mission_T
#define struct_DangerArray_codegenReal2Mission_T

struct DangerArray_codegenReal2Mission_T
{
    emxArray_real_T_codegenReal2Mission_T *DangerList;
};

#endif                              // struct_DangerArray_codegenReal2Mission_T

#ifndef struct_emxArray_boolean_T_codegenReal2Mission_T
#define struct_emxArray_boolean_T_codegenReal2Mission_T

struct emxArray_boolean_T_codegenReal2Mission_T
{
    boolean_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                       // struct_emxArray_boolean_T_codegenReal2Mission_T

#ifndef struct_emxArray_int32_T_codegenReal2Mission_T
#define struct_emxArray_int32_T_codegenReal2Mission_T

struct emxArray_int32_T_codegenReal2Mission_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                         // struct_emxArray_int32_T_codegenReal2Mission_T

#ifndef struct_emxArray_char_T_codegenReal2Mission_T
#define struct_emxArray_char_T_codegenReal2Mission_T

struct emxArray_char_T_codegenReal2Mission_T
{
    char_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif                          // struct_emxArray_char_T_codegenReal2Mission_T

#ifndef struct_emxArray_char_T_1x10_codegenReal2Mission_T
#define struct_emxArray_char_T_1x10_codegenReal2Mission_T

struct emxArray_char_T_1x10_codegenReal2Mission_T
{
    char_T data[10];
    int32_T size[2];
};

#endif                     // struct_emxArray_char_T_1x10_codegenReal2Mission_T

#ifndef struct_emxArray_char_T_1x16_codegenReal2Mission_T
#define struct_emxArray_char_T_1x16_codegenReal2Mission_T

struct emxArray_char_T_1x16_codegenReal2Mission_T
{
    char_T data[16];
    int32_T size[2];
};

#endif                     // struct_emxArray_char_T_1x16_codegenReal2Mission_T

// Custom Type definition for MATLAB Function: '<S71>/PrintOnboardLog'
#ifndef struct_cell_wrap_1_codegenReal2Mission_T
#define struct_cell_wrap_1_codegenReal2Mission_T

struct cell_wrap_1_codegenReal2Mission_T
{
    emxArray_char_T_1x16_codegenReal2Mission_T f1;
};

#endif                              // struct_cell_wrap_1_codegenReal2Mission_T

#ifndef SS_UINT64
#define SS_UINT64                      56
#endif

#ifndef SS_INT64
#define SS_INT64                       57
#endif
#endif                               // RTW_HEADER_codegenReal2Mission_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
