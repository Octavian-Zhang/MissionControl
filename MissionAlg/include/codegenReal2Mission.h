//
// File: codegenReal2Mission.h
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
#ifndef RTW_HEADER_codegenReal2Mission_h_
#define RTW_HEADER_codegenReal2Mission_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include <stddef.h>
#include "SendData_IndividualUAVCmdT.h"
#include "SendData_FCUCMDT.h"
#include "codegenReal2Mission_types.h"
#include "RecvData_uint8_T.h"
#include "RecvData_RealUAVStateBusT.h"
#include "RecvData_IndividualUAVCmdT.h"
#include "SendData_TaskStatusT.h"
#include "RecvData_VectorSpeedT.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"
#include "DeSerOtherUAV.h"
#include "FlightMissionIterator.h"
#include "ImmedMission.h"
#include "Real2SimGuidance.h"
#include "rtGetInf.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtGetNaN.h"
#include "model_reference_types.h"
#include <cstring>
#include "zero_crossing_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef ODE4_INTG
#define ODE4_INTG

// ODE4 Integration Data
struct ODE4_IntgData {
    real_T *y;                         // output
    real_T *f[4];                      // derivatives
};

#endif

// Class declaration for model codegenReal2Mission
class codegenReal2MissionModelClass final
{
    // public data and function members
  public:
    // Block signals and states (default storage) for system '<Root>'
    struct DW_codegenReal2Mission_T {
        MdlrefDW_FlightMissionIterator_T ModelA_InstanceData;// '<S7>/ModelA'
        MdlrefDW_FlightMissionIterator_T ModelB_InstanceData;// '<S7>/ModelB'
        MdlrefDW_ImmedMission_T ImmedMission_InstanceData;// '<S8>/ImmedMission' 
        MdlrefDW_Real2SimGuidance_T Real2SimGuidance_InstanceData;// '<S100>/Real2SimGuidance' 
        FILE* eml_openfiles[20];       // '<S9>/ReadHomePoint'
        FILE* eml_openfiles_m[20];     // '<S13>/ReadHomePoint'
        FILE* eml_openfiles_mq[20];    // '<S1>/ReadHomePoint'
        FILE* eml_openfiles_b[20];     // '<S52>/ReadPursuitShiftPercentage'
        FILE* eml_openfiles_h[20];     // '<S94>/PrintOnboardLog'
        FILE* eml_openfiles_f[20];     // '<S2>/ReadParADRC'
        Msg_IndividualUAVCmd Queue_Msg[16];// '<S83>/Queue'
        FlightLogging Real2SimGuidance_o3;// '<S100>/Real2SimGuidance'
        missionCmd MsgRT_Buf[2];       // '<S47>/MsgRT'
        missionCmd MsgRT_Buf_a[2];     // '<S48>/MsgRT'
        IndividualUAVCmd Receive_o2;   // '<S83>/Receive'
        IndividualUAVCmd Receive;      // '<S91>/Receive'
        IndividualUAVCmd Receive_o2_m; // '<S82>/Receive'
        Buffer_IndividualUAVCmd
            Queue_InsertedFor_MissionValidation_at_inport_0_Queue;// synthesized block 
        IndividualUAVCmd Memory_PreviousInput;// '<S83>/Memory'
        FixedWingGuidanceStateBus TmpRTBAtSwitchMissionUAVStateInport1_Buf[2];// synthesized block 
        FixedWingGuidanceStateBus TmpRTBAtSwitchMissionUAVStateInport3_Buf[2];// synthesized block 
        missionCmd RcvNextMission;     // '<S2>/RcvNextMission'
        missionCmd RcvImmedCMD_o2;     // '<S2>/RcvImmedCMD'
        missionCmd Receive_o2_d;       // '<S47>/Receive'
        missionCmd Receive_o2_p;       // '<S48>/Receive'
        missionCmd ReceiveMissionA_o2; // '<S7>/ReceiveMissionA'
        missionCmd ReceiveMissionB_o2; // '<S7>/ReceiveMissionB'
        missionCmd ExecMsgA;           // '<S7>/MissionUAVScheduling'
        missionCmd ExecMsgB;           // '<S7>/MissionUAVScheduling'
        missionCmd ReceiveThisMission_o2;// '<S6>/ReceiveThisMission'
        Buffer_missionCmd Queue_InsertedFor_RcvNextMission_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd
            Queue_InsertedFor_FeedbackCurrentMission_at_inport_4_Queue;// synthesized block 
        Buffer_missionCmd
            Queue_InsertedFor_MissionUAVScheduling_at_inport_2_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_MsgRateTransitionA_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_MsgRateTransitionB_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_ReceiveMissionA_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_ReceiveMissionB_at_inport_0_Queue;// synthesized block 
        Msg_missionCmd
            Queue_InsertedFor_MissionUAVScheduling_at_inport_2_Out1RecvBuffer;// synthesized block 
        missionCmd CurrentFlightMission;// '<S2>/DataStoreMissionCmd'
        missionCmd MissionCMD;         // '<S84>/DataStoreMissionCmd'
        missionCmd ExecMsg_msgData;    // '<S7>/MissionUAVScheduling'
        missionCmd ExecMsgA_msgData;   // '<S7>/MissionUAVScheduling'
        missionCmd ExecMsgB_msgData;   // '<S7>/MissionUAVScheduling'
        RealUAVStateBus Receive_m;     // '<Root>/Receive'
        FixedWingGuidanceStateBus ImmedMission_o2;// '<S8>/ImmedMission'
        FixedWingGuidanceStateBus ModelA_o1;// '<S7>/ModelA'
        FixedWingGuidanceStateBus ModelB_o1;// '<S7>/ModelB'
        ParamADRC DataStoreRead;       // '<S2>/Data Store Read'
        ParamADRC ParamADRC_e;         // '<S2>/Data Store Memory'
        ParamADRC ParADRC;             // '<S2>/ReadParADRC'
        DangerInfo Receive_o2_a;       // '<S5>/Receive'
        FCUCMD Real2SimGuidance_o1;    // '<S100>/Real2SimGuidance'
        Buffer_DangerInfo
            Queue_InsertedFor_DangerLidarScanPoints_at_inport_0_Queue;// synthesized block 
        FixedWingGuidanceBus ImmedMission_o4;// '<S8>/ImmedMission'
        Queue_IndividualUAVCmd Queue_Queue;// '<S83>/Queue'
        VectorSpeed Receive_e;         // '<S3>/Receive'
        real_T RTLLA[3];               // '<Root>/RTLLA'
        real_T DeSerOtherUAV_m[4096];  // '<Root>/DeSerOtherUAV'
        real_T SelectNorthEastRadius[192];// '<S13>/SelectNorthEastRadius'
        real_T PointCloud[2097152];    // '<S13>/InterpCircle'
        real_T LLA0_c[3];              // '<S1>/ReadHomePoint'
        real_T RateTransition_Buf0[4096];// '<Root>/Rate Transition'
        real_T RateTransition_Buf1[4096];// '<Root>/Rate Transition'
        real_T RateTransition_Buf2[4096];// '<Root>/Rate Transition'
        real_T RTLLA_Buf[9];           // '<Root>/RTLLA'
        real_T HomePoint[3];           // '<S9>/ReadHomePoint'
        real_T EnableA_Buf[2];         // synthesized block
        real_T EnableB_Buf[2];         // synthesized block
        real_T TmpRTBAtSwitchTaskStatusInport1_Buf[2];// synthesized block
        real_T TmpRTBAtSwitchTaskStatusInport3_Buf[2];// synthesized block
        real_T TmpRTBAtModelAInport3_Buf[2];// synthesized block
        real_T TmpRTBAtModelBInport3_Buf[2];// synthesized block
        real_T DangerList[256];        // '<S13>/Data Store Memory'
        real_T HomePoint_g[3];         // '<S13>/ReadHomePoint'
        real_T HomePoint_l[3];         // '<S1>/ReadHomePoint'
        real_T RateTransition_c[4096]; // '<Root>/Rate Transition'
        real_T thisTaskStatus;         // '<S8>/ImmedMission'
        real_T ModelA_o2;              // '<S7>/ModelA'
        real_T ModelB_o2;              // '<S7>/ModelB'
        real_T EnableA;                // '<S7>/MissionUAVScheduling'
        real_T EnableB;                // '<S7>/MissionUAVScheduling'
        real_T DivideThree;            // '<S52>/DivideThree'
        real_T PursuitShift;           // '<S52>/ReadPursuitShiftPercentage'
        void* RateTransition_d0_SEMAPHORE;// '<Root>/Rate Transition'
        void* RTLLA_d0_SEMAPHORE;      // '<Root>/RTLLA'
        void* ExecMsg_msgInterface;    // '<S7>/MissionUAVScheduling'
        void* ExecMsg_msgHandle;       // '<S7>/MissionUAVScheduling'
        void* ExecMsg_msgDataPtr;      // '<S7>/MissionUAVScheduling'
        void* ExecMsgA_msgInterface;   // '<S7>/MissionUAVScheduling'
        void* ExecMsgB_msgInterface;   // '<S7>/MissionUAVScheduling'
        int32_T SelectNorthEastRadius_DIMS1[2];// '<S13>/SelectNorthEastRadius'
        int32_T SFunction_DIMS2[2];    // '<S13>/sizeconversion'
        int32_T SFunction_DIMS2_c[2];  // '<S13>/getDangerList'
        int32_T SFunction_DIMS2_i[2];  // '<S13>/InterpCircle'
        int32_T DelayInput1_DSTATE;    // '<S87>/Delay Input1'
        int32_T DelayInput1_DSTATE_e;  // '<S44>/Delay Input1'
        int32_T MemoryFlightStatus_PreviousInput;// '<S6>/MemoryFlightStatus'
        int32_T MemoryImmedStatus_PreviousInput;// '<S6>/MemoryImmedStatus'
        int8_T RateTransition_LstBufWR;// '<Root>/Rate Transition'
        int8_T RateTransition_RDBuf;   // '<Root>/Rate Transition'
        int8_T RTLLA_LstBufWR;         // '<Root>/RTLLA'
        int8_T RTLLA_RDBuf;            // '<Root>/RTLLA'
        int8_T RateTransition_RdBufIdx;// '<S99>/Rate Transition'
        int8_T RateTransition_WrBufIdx;// '<S99>/Rate Transition'
        int8_T EnableA_RdBufIdx;       // synthesized block
        int8_T EnableA_WrBufIdx;       // synthesized block
        int8_T EnableB_RdBufIdx;       // synthesized block
        int8_T EnableB_WrBufIdx;       // synthesized block
        int8_T MsgRT_RdBufIdx;         // '<S47>/MsgRT'
        int8_T MsgRT_WrBufIdx;         // '<S47>/MsgRT'
        int8_T RateTransition_RdBufIdx_c;// '<S47>/Rate Transition'
        int8_T RateTransition_WrBufIdx_j;// '<S47>/Rate Transition'
        int8_T MsgRT_RdBufIdx_b;       // '<S48>/MsgRT'
        int8_T MsgRT_WrBufIdx_b;       // '<S48>/MsgRT'
        int8_T RateTransition_RdBufIdx_o;// '<S48>/Rate Transition'
        int8_T RateTransition_WrBufIdx_h;// '<S48>/Rate Transition'
        int8_T TmpRTBAtSwitchMissionUAVStateInport1_RdBufIdx;// synthesized block 
        int8_T TmpRTBAtSwitchMissionUAVStateInport1_WrBufIdx;// synthesized block 
        int8_T TmpRTBAtSwitchMissionUAVStateInport3_RdBufIdx;// synthesized block 
        int8_T TmpRTBAtSwitchMissionUAVStateInport3_WrBufIdx;// synthesized block 
        int8_T TmpRTBAtSwitchTaskStatusInport1_RdBufIdx;// synthesized block
        int8_T TmpRTBAtSwitchTaskStatusInport1_WrBufIdx;// synthesized block
        int8_T TmpRTBAtSwitchTaskStatusInport3_RdBufIdx;// synthesized block
        int8_T TmpRTBAtSwitchTaskStatusInport3_WrBufIdx;// synthesized block
        int8_T TmpRTBAtModelAInport3_RdBufIdx;// synthesized block
        int8_T TmpRTBAtModelAInport3_WrBufIdx;// synthesized block
        int8_T TmpRTBAtModelBInport3_RdBufIdx;// synthesized block
        int8_T TmpRTBAtModelBInport3_WrBufIdx;// synthesized block
        uint8_T ReceiveFlightMode;     // '<S3>/ReceiveFlightMode'
        uint8_T EngagedFlag_Log;       // '<S100>/Real2SimGuidance'
        uint8_T Memory_PreviousInput_l;// '<S2>/Memory'
        uint8_T is_active_c18_codegenReal2Mission;// '<S7>/NewMission'
        uint8_T is_MissionSwitch;      // '<S7>/MissionUAVScheduling'
        uint8_T is_FollowSwitch;       // '<S7>/MissionUAVScheduling'
        uint8_T is_active_c15_codegenReal2Mission;// '<S7>/MissionUAVScheduling' 
        uint8_T is_active_MissionSwitch;// '<S7>/MissionUAVScheduling'
        uint8_T is_active_FollowSwitch;// '<S7>/MissionUAVScheduling'
        boolean_T ImmedMission_o3[2];  // '<S8>/ImmedMission'
        boolean_T eml_autoflush[20];   // '<S94>/PrintOnboardLog'
        boolean_T RateTransition_Buf_c[2];// '<S47>/Rate Transition'
        boolean_T RateTransition_Buf_l[2];// '<S48>/Rate Transition'
        boolean_T followSwitch;        // '<S7>/MissionUAVScheduling'
        boolean_T OR;                  // '<S6>/OR'
        boolean_T ParADRC_not_empty;   // '<S2>/ReadParADRC'
        boolean_T HomePoint_not_empty; // '<S9>/ReadHomePoint'
        boolean_T Memory_PreviousInput_f;// '<S7>/Memory'
        boolean_T Memory_PreviousInput_j;// '<S47>/Memory'
        boolean_T Memory_PreviousInput_p;// '<S48>/Memory'
        volatile boolean_T RateTransition_Buffer0;// '<S7>/Rate Transition'
        boolean_T followSwitch_start;  // '<S7>/NewMission'
        boolean_T PursuitShift_not_empty;// '<S52>/ReadPursuitShiftPercentage'
        boolean_T HomePoint_not_empty_k;// '<S13>/ReadHomePoint'
        boolean_T HomePoint_not_empty_o;// '<S1>/ReadHomePoint'
    };

    // Continuous states (default storage)
    struct X_codegenReal2Mission_T {
        X_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S100>/Real2SimGuidance' 
    };

    // State derivatives (default storage)
    struct XDot_codegenReal2Mission_T {
        XDot_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S100>/Real2SimGuidance' 
    };

    // State disabled
    struct XDis_codegenReal2Mission_T {
        XDis_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S100>/Real2SimGuidance' 
    };

    // Real-time Model Data Structure
    struct RT_MODEL_codegenReal2Mission_T {
        const char_T *errorStatus;
        RTWSolverInfo solverInfo;
        rtTimingBridge timingBridge;
        X_codegenReal2Mission_T *contStates;
        int_T *periodicContStateIndices;
        real_T *periodicContStateRanges;
        real_T *derivs;
        XDis_codegenReal2Mission_T *contStateDisabled;
        boolean_T zCCacheNeedsReset;
        boolean_T derivCacheNeedsReset;
        boolean_T CTOutputIncnstWithState;
        real_T odeY[5];
        real_T odeF[4][5];
        ODE4_IntgData intgData;

        //
        //  Sizes:
        //  The following substructure contains sizes information
        //  for many of the model attributes such as inputs, outputs,
        //  dwork, sample times, etc.

        struct {
            int_T numContStates;
            int_T numPeriodicContStates;
            int_T numSampTimes;
        } Sizes;

        //
        //  Timing:
        //  The following substructure contains information regarding
        //  the timing information for the model.

        struct {
            uint32_T clockTick0;
            uint32_T clockTickH0;
            time_T stepSize0;
            uint32_T clockTick1;
            uint32_T clockTickH1;
            struct {
                uint32_T TID[4];
            } TaskCounters;

            struct {
                uint32_T TID1_2;
                boolean_T b_TID1_2;
                uint32_T TID1_3;
                boolean_T b_TID1_3;
            } RateInteraction;

            SimTimeStep simTimeStep;
            boolean_T stopRequestedFlag;
            time_T *t;
            time_T tArray[5];
        } Timing;
    };

    // Copy Constructor
    codegenReal2MissionModelClass(codegenReal2MissionModelClass const&) = delete;

    // Assignment Operator
    codegenReal2MissionModelClass& operator= (codegenReal2MissionModelClass
        const&) & = delete;

    // Move Constructor
    codegenReal2MissionModelClass(codegenReal2MissionModelClass &&) = delete;

    // Move Assignment Operator
    codegenReal2MissionModelClass& operator= (codegenReal2MissionModelClass &&) =
        delete;

    // Real-Time Model get method
    codegenReal2MissionModelClass::RT_MODEL_codegenReal2Mission_T * getRTM();

    // Constructor
    codegenReal2MissionModelClass(SendData_IndividualUAVCmdT &
        CurrentMissionSendData_arg, SendData_FCUCMDT &FlightCMDSendData_arg,
        SendData_FlightLoggingT &FlightLogSendData_arg, RecvData_uint8_T
        &FlightModeRecvData_arg, RecvData_RealUAVStateBusT &
        FlightStateRecvData_arg, RecvData_IndividualUAVCmdT &
        MissionCMDRecvData_arg, SendData_TaskStatusT &MissionFBSendData_arg,
        RecvData_RealUAVStateBusT &NbrUAVstateRecvData_arg,
        RecvData_VectorSpeedT &VecSpdRecvData_arg);

    // model initialize function
    void initialize();

    // model step function
    void step();

    // model step function
    void step2();

    // model step function
    void step3();

    // model step function
    void codegenReal2Mission_PushNbrUAV();

    // model terminate function
    void terminate();

    // Destructor
    ~codegenReal2MissionModelClass();

    // Service port get method
    RecvData_RealUAVStateBusT & get_NbrUAVstateRecvData();

    // private data and function members
  private:
    // Block states
    DW_codegenReal2Mission_T codegenReal2Mission_DW;

    // Block continuous states
    X_codegenReal2Mission_T codegenReal2Mission_X;
    SendData_IndividualUAVCmdT &CurrentMissionSendData;
    SendData_FCUCMDT &FlightCMDSendData;
    SendData_FlightLoggingT &FlightLogSendData;
    RecvData_uint8_T &FlightModeRecvData;
    RecvData_RealUAVStateBusT &FlightStateRecvData;
    RecvData_RealUAVStateBusT &NbrUAVstateRecvData;
    RecvData_IndividualUAVCmdT &MissionCMDRecvData;
    SendData_TaskStatusT &MissionFBSendData;
    RecvData_VectorSpeedT &VecSpdRecvData;

    // private member function(s) for subsystem '<Root>'
    void codegenReal2Mission_emxInit_char_T
        (emxArray_char_T_codegenReal2Mission_T **pEmxArray, int32_T
         numDimensions);
    int8_T codegenReal2Mission_filedata(void) const;
    int8_T codegenReal2Mission_cfopen(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_emxEnsureCapacity_char_T
        (emxArray_char_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
    void codegenReal2Mission_fread(real_T fileID,
        emxArray_char_T_codegenReal2Mission_T *A);
    int32_T codegenReal2Mission_cfclose(real_T fid);
    void codegenReal2Mission_strtok(const emxArray_char_T_codegenReal2Mission_T *
        x, emxArray_char_T_codegenReal2Mission_T *token,
        emxArray_char_T_codegenReal2Mission_T *remain);
    void codegenReal2Mission_strtok_p(const
        emxArray_char_T_codegenReal2Mission_T *x,
        emxArray_char_T_codegenReal2Mission_T *token);
    void codegenReal2Mission_strtrim(const emxArray_char_T_codegenReal2Mission_T
        *x, emxArray_char_T_codegenReal2Mission_T *y);
    boolean_T codegenReal2Mission_contains(const
        emxArray_char_T_codegenReal2Mission_T *str);
    void codegenReal2Mission_find_token(const
        emxArray_char_T_codegenReal2Mission_T *x, int32_T *itoken, int32_T
        *iremain);
    void codegenReal2Mission_strtok_ph(const
        emxArray_char_T_codegenReal2Mission_T *x,
        emxArray_char_T_codegenReal2Mission_T *token,
        emxArray_char_T_codegenReal2Mission_T *remain);
    void codegenReal2Mission_emxFree_char_T
        (emxArray_char_T_codegenReal2Mission_T **pEmxArray);
    boolean_T codegenReal2Mission_strcmp(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_p(const
        emxArray_char_T_codegenReal2Mission_T *a);
    void codegenReal2Mission_copysign(emxArray_char_T_codegenReal2Mission_T *s1,
        int32_T *idx, const emxArray_char_T_codegenReal2Mission_T *s, int32_T *k,
        int32_T n, boolean_T *foundsign, boolean_T *success);
    boolean_T codegenReal2Mission_isUnitImag(const
        emxArray_char_T_codegenReal2Mission_T *s, int32_T k, int32_T n);
    void codegenReal2Mission_readNonFinite(const
        emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n,
        boolean_T *b_finite, real_T *fv);
    boolean_T codegenReal2Mission_copydigits
        (emxArray_char_T_codegenReal2Mission_T *s1, int32_T *idx, const
         emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n,
         boolean_T allowpoint);
    boolean_T codegenReal2Mission_copyexponent
        (emxArray_char_T_codegenReal2Mission_T *s1, int32_T *idx, const
         emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n);
    void codegenReal2Mission_readfloat(emxArray_char_T_codegenReal2Mission_T *s1,
        int32_T *idx, const emxArray_char_T_codegenReal2Mission_T *s, int32_T *k,
        int32_T n, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
        boolean_T *foundsign, boolean_T *success);
    creal_T codegenReal2Mission_str2double(const
        emxArray_char_T_codegenReal2Mission_T *s);
    boolean_T codegenReal2Mission_strcmp_p4(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_p4a(const
        emxArray_char_T_codegenReal2Mission_T *a);
    int8_T codegenReal2Mission_filedata_g(void) const;
    int8_T codegenReal2Mission_cfopen_j(const char_T *cfilename, const char_T
        *cpermission);
    real_T codegenReal2Mission_fileManager_d(void);
    void codegenReal2Mission_fread_eg(real_T fileID,
        emxArray_char_T_codegenReal2Mission_T *A);
    int32_T codegenReal2Mission_cfclose_p(real_T fid);
    void codegenReal2Mission_strtok_cxm4(const
        emxArray_char_T_codegenReal2Mission_T *x,
        emxArray_char_T_codegenReal2Mission_T *token);
    boolean_T codegenReal2Mission_strcmp_a(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_a5(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_a5y(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_a5y5(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_a5y50(const
        emxArray_char_T_codegenReal2Mission_T *a);
    void codegenReal2Mission_readINI(emxArray_char_T_codegenReal2Mission_T *ret);
    void codegenReal2Mission_readINI_p(emxArray_char_T_codegenReal2Mission_T
        *ret);
    void codegenReal2Mission_readINI_pw(emxArray_char_T_codegenReal2Mission_T
        *ret);
    boolean_T codegenReal2Mission_strcmp_a5y50m(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_pop_k(Buffer_IndividualUAVCmd *q,
        Msg_IndividualUAVCmd *elementOut);
    int32_T codegenReal2Mission_Receive_RecvData(IndividualUAVCmd *data);
    creal_T codegenReal2Mission_two_prod(real_T a);
    creal_T codegenReal2Mission_times(const creal_T a);
    creal_T codegenReal2Mission_two_sum(real_T a, real_T b);
    creal_T codegenReal2Mission_plus(const creal_T a, real_T b);
    creal_T codegenReal2Mission_createFromDateVec(const real_T inData[7]);
    boolean_T codegenReal2Mission_isequaln(int32_T varargin_1_SequenceID,
        MissionModes varargin_1_MissionMode, real_T
        varargin_1_MissionLocation_Lat, real_T varargin_1_MissionLocation_Lon,
        real_T varargin_1_MissionLocation_Alt, real_T
        varargin_1_MissionLocation_degHDG, real32_T varargin_1_params_Param1,
        real32_T varargin_1_params_Param2, real32_T varargin_1_params_Param3,
        real32_T varargin_1_params_Param4, real32_T varargin_1_params_Param5,
        real32_T varargin_1_params_Param6, real32_T varargin_1_params_Param7,
        const Location varargin_1_StartPosition, int32_T varargin_1_numUAV,
        int32_T varargin_1_FormationPos, real_T varargin_1_StartTime, int32_T
        varargin_2_SequenceID, MissionModes varargin_2_MissionMode, const
        Location varargin_2_MissionLocation, const Parameters varargin_2_params,
        const Location varargin_2_StartPosition, int32_T varargin_2_numUAV,
        int32_T varargin_2_FormationPos, real_T varargin_2_StartTime);
    creal_T codegenReal2Mission_two_diff(real_T a, real_T b);
    creal_T codegenReal2Mission_divide(const creal_T a);
    creal_T codegenReal2Mission_minus(const creal_T a, const creal_T b);
    void codegenReal2Mission_getDateVec_i(real_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
    void codegenReal2Mission_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
        real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
        real_T *t_tm_year, boolean_T *t_tm_isdst);
    void codegenReal2Mission_getDateVec_ii(const creal_T dd, real_T *y, real_T
        *mo, real_T *d, real_T *h, real_T *m, real_T *s);
    Msg_missionCmd codegenReal2Mission_createMsg_f(const missionCmd *data);
    boolean_T codegenReal2Mission_push_i(Buffer_missionCmd *q, const
        Msg_missionCmd *element);
    int32_T codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_ReceiveThisMission_SendData(const missionCmd
        *data);
    int32_T codegenReal2Mission_RcvImmedCMD_SendData(const missionCmd *data);
    int8_T codegenReal2Mission_filedata_i(void) const;
    int8_T codegenReal2Mission_cfopen_h(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_fileManager(real_T varargin_1, FILE* *f, boolean_T *
        a);
    void codegenReal2Mission_string_string(MissionModes val, char_T
        obj_Value_data[], int32_T obj_Value_size[2]);
    creal_T codegenReal2Mission_datetime_datetime(void);
    void codegenReal2Mission_getDateVec_b(const creal_T dd, real_T *y, real_T
        *mo, real_T *d, real_T *h, real_T *m, real_T *s);
    void codegenReal2Mission_printIndivMissionCMD(int32_T
        IndivMissionCMD_SequenceID, MissionModes IndivMissionCMD_MissionMode,
        real_T IndivMissionCMD_MissionLocation_Lat, real_T
        IndivMissionCMD_MissionLocation_Lon, real_T
        IndivMissionCMD_MissionLocation_Alt, real_T
        IndivMissionCMD_MissionLocation_degHDG, real32_T
        IndivMissionCMD_params_Param1, real32_T IndivMissionCMD_params_Param2,
        real32_T IndivMissionCMD_params_Param3, real32_T
        IndivMissionCMD_params_Param4, real32_T IndivMissionCMD_params_Param5,
        real32_T IndivMissionCMD_params_Param6, real32_T
        IndivMissionCMD_params_Param7, const Location
        IndivMissionCMD_StartPosition, int32_T IndivMissionCMD_numUAV, int32_T
        IndivMissionCMD_FormationPos, const Time IndivMissionCMD_StartTime,
        real_T fileID);
    int32_T codegenReal2Mission_cfclose_n(real_T fid);
    Msg_IndividualUAVCmd codegenReal2Mission_createMsg(const IndividualUAVCmd
        *data);
    boolean_T codegenReal2Mission_push(Queue_IndividualUAVCmd *q, const
        Msg_IndividualUAVCmd *element);
    int32_T codegenReal2Mission_Queue_SendData(const IndividualUAVCmd *data);
    boolean_T codegenReal2Mission_pop(Queue_IndividualUAVCmd *q,
        Msg_IndividualUAVCmd *elementOut);
    int32_T codegenReal2Mission_Queue_RecvData(IndividualUAVCmd *data);
    boolean_T codegenReal2Mission_push_b(Buffer_IndividualUAVCmd *q, const
        Msg_IndividualUAVCmd *element);
    int32_T codegenReal2Mission_Receive_b_SendData(const IndividualUAVCmd *data);
    Msg_DangerInfo codegenReal2Mission_createMsg_fl(const DangerInfo *data);
    boolean_T codegenReal2Mission_push_j(Buffer_DangerInfo *q, const
        Msg_DangerInfo *element);
    int32_T codegenReal2Mission_Receive_SendData(const DangerInfo *data);
    boolean_T codegenReal2Mission_pop_h(Buffer_missionCmd *q, Msg_missionCmd
        *elementOut);
    int32_T codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_MissionUAVScheduling_In3_SendData(const
        missionCmd *data);
    void codegenReal2Mission_FollowSwitch(const int32_T *sfEvent);
    Msg_missionCmd *codegenReal2Mission_MissionUAVScheduling_In3_RecvMsg(void);
    boolean_T codegenReal2Mission_sf_msg_pop_ExecMsg(boolean_T *ExecMsg_isValid);
    int32_T codegenReal2Mission_Receive_SendMsg(const Msg_missionCmd *msg);
    void codegenReal2Mission_sf_msg_forward_ExecMsg_ExecMsgA(boolean_T
        *ExecMsg_isValid);
    int32_T codegenReal2Mission_Receive_e_SendMsg(const Msg_missionCmd *msg);
    void codegenReal2Mission_sf_msg_forward_ExecMsg_ExecMsgB(boolean_T
        *ExecMsg_isValid);
    void codegenReal2Mission_sf_msg_discard_ExecMsg(boolean_T *ExecMsg_isValid);
    int8_T codegenReal2Mission_filedata_hj(void) const;
    int8_T codegenReal2Mission_cfopen_k(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_fread_e(real_T fileID,
        emxArray_char_T_codegenReal2Mission_T *A);
    int32_T codegenReal2Mission_cfclose_l(real_T fid);
    int32_T codegenReal2Mission_Receive_d_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_Receive_e_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_RcvImmedCMD_RecvData(missionCmd *data);
    int8_T codegenReal2Mission_filedata_p(void) const;
    int8_T codegenReal2Mission_cfopen_o(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_fread_i(real_T fileID,
        emxArray_char_T_codegenReal2Mission_T *A);
    int32_T codegenReal2Mission_cfclose_m(real_T fid);
    boolean_T codegenReal2Mission_pop_j(Buffer_DangerInfo *q, Msg_DangerInfo
        *elementOut);
    int32_T codegenReal2Mission_Receive_h_RecvData(DangerInfo *data);
    int8_T codegenReal2Mission_filedata_h(void) const;
    int8_T codegenReal2Mission_cfopen_p(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_fread_j(real_T fileID,
        emxArray_char_T_codegenReal2Mission_T *A);
    int32_T codegenReal2Mission_cfclose_g(real_T fid);
    void codegenReal2Mission_unique_vector(const real_T a_data[], const int32_T *
        a_size, real_T b_data[], int32_T *b_size, int32_T ndx_data[], int32_T
        *ndx_size, int32_T pos_data[], int32_T *pos_size);
    void codegenReal2Mission_emxInit_real_T
        (emxArray_real_T_codegenReal2Mission_T **pEmxArray, int32_T
         numDimensions);
    void codegenReal2Mission_emxEnsureCapacity_real_T
        (emxArray_real_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
    void codegenReal2Mission_emxFree_real_T
        (emxArray_real_T_codegenReal2Mission_T **pEmxArray);
    int32_T codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data);
    void codegenReal2Mission_getDateVec(real_T dd, real_T *y, real_T *mo, real_T
        *d, real_T *h, real_T *m, real_T *s);
    int32_T codegenReal2Mission_ReceiveMissionA_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_ReceiveMissionA_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_ReceiveMissionB_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_ReceiveMissionB_RecvData(missionCmd *data);
    void codegenReal2Mission_initQueue(Queue_IndividualUAVCmd *q, QueuePolicy_T
        policy, int32_T capacity, Msg_IndividualUAVCmd *qPool);

    // Continuous states update member function
    void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

    // Derivatives member function
    void codegenReal2Mission_derivatives();

    // model instance variable for '<Root>/DeSerOtherUAV'
    DeSerOtherUAV DeSerOtherUAVMDLOBJ2;

    // Real-Time Model
    RT_MODEL_codegenReal2Mission_T codegenReal2Mission_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S13>/Down2Up' : Unused code path elimination
//  Block '<S15>/Data Type Duplicate' : Unused code path elimination
//  Block '<S15>/Sum' : Unused code path elimination
//  Block '<S15>/Ze2height' : Unused code path elimination
//  Block '<S13>/inverse' : Unused code path elimination
//  Block '<S58>/Data Type Duplicate' : Unused code path elimination
//  Block '<S13>/Reshape' : Reshape block reduction
//  Block '<S6>/Cast To uint8' : Eliminate redundant data type conversion
//  Block '<S6>/intFormationPos' : Eliminate redundant data type conversion
//  Block '<S6>/intMissionMode' : Eliminate redundant data type conversion
//  Block '<S6>/intNumUAV' : Eliminate redundant data type conversion
//  Block '<S6>/intSequenceId' : Eliminate redundant data type conversion
//  Block '<S90>/Signal Copy' : Eliminate redundant signal conversion block
//  Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'codegenReal2Mission'
//  '<S1>'   : 'codegenReal2Mission/GCSLLA'
//  '<S2>'   : 'codegenReal2Mission/MissionLogic'
//  '<S3>'   : 'codegenReal2Mission/TrackingControl'
//  '<S4>'   : 'codegenReal2Mission/GCSLLA/ReadHomePoint'
//  '<S5>'   : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints'
//  '<S6>'   : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission'
//  '<S7>'   : 'codegenReal2Mission/MissionLogic/FlightMission'
//  '<S8>'   : 'codegenReal2Mission/MissionLogic/ImmedMission_Variant'
//  '<S9>'   : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast'
//  '<S10>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD'
//  '<S11>'  : 'codegenReal2Mission/MissionLogic/ReadParADRC'
//  '<S12>'  : 'codegenReal2Mission/MissionLogic/VisualizeUAV'
//  '<S13>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD'
//  '<S14>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/InterpCircle'
//  '<S15>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth'
//  '<S16>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/ReadHomePoint'
//  '<S17>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/getDangerList'
//  '<S18>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/sizeconversion'
//  '<S19>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap'
//  '<S20>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0'
//  '<S21>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem'
//  '<S22>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/pos_rad'
//  '<S23>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S24>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S25>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S26>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S27>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S28>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S29>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S30>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S31>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S32>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S33>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S34>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S35>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S36>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S37>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S38>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S39>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S40>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S41>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/Compare To Constant'
//  '<S42>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback'
//  '<S43>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/TimeConverter'
//  '<S44>'  : 'codegenReal2Mission/MissionLogic/FlightMission/Detect Change'
//  '<S45>'  : 'codegenReal2Mission/MissionLogic/FlightMission/JumpDelay'
//  '<S46>'  : 'codegenReal2Mission/MissionLogic/FlightMission/MissionUAVScheduling'
//  '<S47>'  : 'codegenReal2Mission/MissionLogic/FlightMission/MsgRateTransitionA'
//  '<S48>'  : 'codegenReal2Mission/MissionLogic/FlightMission/MsgRateTransitionB'
//  '<S49>'  : 'codegenReal2Mission/MissionLogic/FlightMission/NewMission'
//  '<S50>'  : 'codegenReal2Mission/MissionLogic/FlightMission/TriggerNewMissionBroadcast'
//  '<S51>'  : 'codegenReal2Mission/MissionLogic/FlightMission/getCurrentTime'
//  '<S52>'  : 'codegenReal2Mission/MissionLogic/FlightMission/JumpDelay/ComputDelay'
//  '<S53>'  : 'codegenReal2Mission/MissionLogic/FlightMission/JumpDelay/ComputDelay/ReadPursuitShiftPercentage'
//  '<S54>'  : 'codegenReal2Mission/MissionLogic/FlightMission/getCurrentTime/CurrentTime'
//  '<S55>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/Degrees to Radians'
//  '<S56>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/Degrees to Radians1'
//  '<S57>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/Degrees to Radians2'
//  '<S58>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth'
//  '<S59>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/ReadHomePoint'
//  '<S60>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S61>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S62>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S63>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S64>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S65>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S66>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S67>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S68>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S69>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S70>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S71>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S72>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S73>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S74>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S75>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S76>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S77>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S78>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S79>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S80>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S81>'  : 'codegenReal2Mission/MissionLogic/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S82>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation'
//  '<S83>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD'
//  '<S84>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation/TriggerMissionDispatch'
//  '<S85>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation/TriggerMissionDispatch/CommandCheck'
//  '<S86>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/Compare To Constant'
//  '<S87>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/Detect Change'
//  '<S88>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/IsAvoidDanger'
//  '<S89>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/NotAvoidDanger'
//  '<S90>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/ProcessDanger'
//  '<S91>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/ReadOne'
//  '<S92>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/Struct2PosixCurr'
//  '<S93>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/Struct2PosixUplink'
//  '<S94>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/UplinkLog'
//  '<S95>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/getCurrentTime'
//  '<S96>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/smallerthanZero'
//  '<S97>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/UplinkLog/PrintOnboardLog'
//  '<S98>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/getCurrentTime/CurrentTime'
//  '<S99>'  : 'codegenReal2Mission/MissionLogic/VisualizeUAV/VisualizeUAV'
//  '<S100>' : 'codegenReal2Mission/TrackingControl/Real2SimGuidance'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
