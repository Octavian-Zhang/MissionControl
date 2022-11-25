//
// File: codegenReal2Mission_types.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 5.28
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Nov 25 19:38:09 2022
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

#ifndef DEFINED_TYPEDEF_FOR_DangerInfo_
#define DEFINED_TYPEDEF_FOR_DangerInfo_

struct DangerInfo
{
    int32_T DangerID;
    real_T Radius;
    Location DangerLoc;
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
    IndividualUAVCmd fData;
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

#ifndef DEFINED_TYPEDEF_FOR_Msg_missionCmd_
#define DEFINED_TYPEDEF_FOR_Msg_missionCmd_

struct Msg_missionCmd
{
    missionCmd fData;
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

#ifndef DEFINED_TYPEDEF_FOR_Msg_DangerInfo_
#define DEFINED_TYPEDEF_FOR_Msg_DangerInfo_

struct Msg_DangerInfo
{
    DangerInfo fData;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Buffer_DangerInfo_
#define DEFINED_TYPEDEF_FOR_Buffer_DangerInfo_

struct Buffer_DangerInfo
{
    boolean_T fOccupied;
    Msg_DangerInfo fMsg;
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
        = default;
};

#endif

// Custom Type definition for MATLAB Function: '<S2>/ReadParADRC'
#include <stdio.h>

// Custom Type definition for MATLAB Function: '<S95>/CurrentTime'
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

#ifndef struct_emxArray_char_T_1x16_codegenReal2Mission_T
#define struct_emxArray_char_T_1x16_codegenReal2Mission_T

struct emxArray_char_T_1x16_codegenReal2Mission_T
{
    char_T data[16];
    int32_T size[2];
};

#endif                     // struct_emxArray_char_T_1x16_codegenReal2Mission_T

// Custom Type definition for MATLAB Function: '<S94>/PrintOnboardLog'
#ifndef struct_cell_wrap_1_codegenReal2Mission_T
#define struct_cell_wrap_1_codegenReal2Mission_T

struct cell_wrap_1_codegenReal2Mission_T
{
    emxArray_char_T_1x16_codegenReal2Mission_T f1;
};

#endif                              // struct_cell_wrap_1_codegenReal2Mission_T

#ifndef SS_UINT64
#define SS_UINT64                      59
#endif

#ifndef SS_INT64
#define SS_INT64                       60
#endif
#endif                               // RTW_HEADER_codegenReal2Mission_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
