//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.337
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Jul 25 10:14:43 2022
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
#include "codegenReal2Mission_types.h"
#include "RecvData_IndividualUAVCmdT.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"
#include "FlightMissionMode.h"
#include "ImmedMission.h"
#include "MissionUAV.h"
#include "Real2SimGuidance.h"
#include "rtGetInf.h"

extern "C" {

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

#ifndef ODE4_INTG
#define ODE4_INTG

// ODE4 Integration Data
struct ODE4_IntgData {
    real_T *y;                         // output
    real_T *f[4];                      // derivatives
};

#endif

// External data declarations for dependent source files
extern const real_T codegenReal2Mission_RGND;// real_T ground

//
//  Exported States
//
//  Note: Exported states are block states with an exported global
//  storage class designation.  Code generation will declare the memory for these
//  states and exports their symbols.
//

extern real_T AltitudeGCS;             // Simulink.Signal object 'AltitudeGCS'
extern real_T LatitudeGCS;             // Simulink.Signal object 'LatitudeGCS'
extern real_T LongitudeGCS;            // Simulink.Signal object 'LongitudeGCS'
extern void* AltitudeGCS_m0;           // synthesized block
extern void* LatitudeGCS_m0;           // synthesized block
extern void* LongitudeGCS_m0;          // synthesized block

// Class declaration for model codegenReal2Mission
class codegenReal2MissionModelClass final
{
    // public data and function members
  public:
    // Block signals and states (default storage) for system '<Root>'
    struct DW_codegenReal2Mission_T {
        MdlrefDW_FlightMissionMode_T PreemptableMissionModeSelector_InstanceData;
                                      // '<S93>/PreemptableMissionModeSelector'
        MdlrefDW_ImmedMission_T ImmedMission_InstanceData;// '<S56>/ImmedMission' 
        MdlrefDW_MissionUAV_T MissionUavModel_InstanceData;// '<S102>/MissionUavModel' 
        MdlrefDW_Real2SimGuidance_T Real2SimGuidance_InstanceData;// '<S129>/Real2SimGuidance' 
        FILE* eml_openfiles[20];       // '<S88>/PrintOnboardLog'
        FILE* eml_openfiles_b[20];     // '<S57>/ReadParADRC'
        FILE* eml_openfiles_j[20];     // '<S123>/PrintOnboardLog'
        IndividualUAVCmd slMsgMgr_memArray_IndividualUAVCmd[17];// synthesized block 
        missionCmd slMsgMgr_memArray_missionCmd[9];// synthesized block
        FlightLogging Real2SimGuidance_o3;// '<S129>/Real2SimGuidance'
        RealUAVStateBus MsgBuff[2];    // '<S5>/MsgBuffDS'
        IndividualUAVCmd Receive_o2;   // '<S110>/Receive'
        IndividualUAVCmd Receive;      // '<S120>/Receive'
        IndividualUAVCmd IndivCMD;     // '<S88>/IndivCMD'
        Msg_IndividualUAVCmd Queue_Msg[16];// '<S110>/Queue'
        missionCmd RcvNextMission;     // '<S3>/RcvNextMission'
        missionCmd RcvImmedCMD_o2;     // '<S3>/RcvImmedCMD'
        missionCmd ReceiveThisMission_o2;// '<S54>/ReceiveThisMission'
        missionCmd ImmedCMD;           // '<S112>/CommandCheck'
        missionCmd ReceiveCurrentMission_o2;// '<S93>/ReceiveCurrentMission'
        missionCmd CurrentFlightMission;// '<S3>/DataStoreMissionCmd'
        missionCmd MissionCMD;         // '<S112>/DataStoreMissionCmd'
        DangerInfo slMsgMgr_memArray_DangerInfo[2];// synthesized block
        RealUAVStateBus Receive_o2_j;  // '<S5>/Receive'
        FixedWingGuidanceStateBus ImmedMission_o2;// '<S56>/ImmedMission'
        ParamADRC ParamADRC_e;         // '<S3>/Data Store Memory'
        DangerInfo Receive_o2_a;       // '<S53>/Receive'
        MemPool_DangerInfo slMsgMgr_MemPool_DangerInfo;// synthesized block
        MemPool_IndividualUAVCmd slMsgMgr_MemPool_IndividualUAVCmd;// synthesized block 
        MemPool_missionCmd slMsgMgr_MemPool_missionCmd;// synthesized block
        FixedWingGuidanceBus ImmedMission_o4;// '<S56>/ImmedMission'
        FixedWingGuidanceBus PreemptableMissionModeSelector_o2;
                                      // '<S93>/PreemptableMissionModeSelector'
        Queue_IndividualUAVCmd Queue_Queue;// '<S110>/Queue'
        Buffer_DangerInfo
            Queue_InsertedFor_DangerLidarScanPoints_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_RcvNextMission_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_FlightMission_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd
            Queue_InsertedFor_FeedbackCurrentMission_at_inport_5_Queue;// synthesized block 
        Buffer_real_T Queue_InsertedFor_ProcessIndivState_at_inport_0_Queue;// synthesized block 
        DangerArray_codegenReal2Mission_T localObj;// '<S61>/getDangerList'
        real_T PreemptableMissionModeSelector_o3[8];
                                      // '<S93>/PreemptableMissionModeSelector'
        real_T SelectNorthEastRadius[192];// '<S61>/SelectNorthEastRadius'
        real_T PointCloud[2097152];    // '<S61>/InterpCircle'
        real_T Delay_DSTATE[60];       // '<S92>/Delay'
        real_T RateTransition_Buf0[4096];// '<Root>/Rate Transition'
        real_T RateTransition_Buf1[4096];// '<Root>/Rate Transition'
        real_T RateTransition_Buf2[4096];// '<Root>/Rate Transition'
        real_T RTLLA_Buf[9];           // '<Root>/RTLLA'
        real_T CatPos[4096];           // '<S5>/Data Store Memory'
        real_T MemoryPose_PreviousInput[4];// '<S93>/MemoryPose'
        real_T RateTransition[4096];   // '<Root>/Rate Transition'
        real_T Switch_m[4096];
        real_T Omega;                  // '<S19>/Divide'
        real_T thisTaskStatus;         // '<S56>/ImmedMission'
        real_T PushImmed;              // '<S112>/CommandCheck'
        real_T TriggerSend;            // '<S92>/MisisonCMDTemporalLogic'
        real_T DivideThree;            // '<S106>/DivideThree'
        real_T thisTaskStatus_g;      // '<S93>/PreemptableMissionModeSelector'
        real_T CastToDouble;           // '<S102>/Cast To Double'
        real_T North;                  // '<S102>/MissionUavModel'
        real_T East;                   // '<S102>/MissionUavModel'
        real_T Height;                 // '<S102>/MissionUavModel'
        real_T AirSpeed;               // '<S102>/MissionUavModel'
        real_T HeadingAngle;           // '<S102>/MissionUavModel'
        real_T FlightPathAngle;        // '<S102>/MissionUavModel'
        real_T RollAngle;              // '<S102>/MissionUavModel'
        real_T RollAngleRate;          // '<S102>/MissionUavModel'
        void* RateTransition_d0_SEMAPHORE;// '<Root>/Rate Transition'
        void* RTLLA_d0_SEMAPHORE;      // '<Root>/RTLLA'
        IndividualUAVCmd* slMsgMgr_freeList_IndividualUAVCmd[17];// synthesized block 
        missionCmd* slMsgMgr_freeList_missionCmd[9];// synthesized block
        DangerInfo* slMsgMgr_freeList_DangerInfo[2];// synthesized block
        int32_T SFunction_DIMS2[2];    // '<S3>/RemoveNaN'
        int32_T SelectNorthEastRadius_DIMS1[2];// '<S61>/SelectNorthEastRadius'
        int32_T SFunction_DIMS2_h[2];  // '<S61>/sizeconversion'
        int32_T SFunction_DIMS2_p[2];  // '<S61>/getDangerList'
        int32_T SFunction_DIMS2_e[2];  // '<S61>/InterpCircle'
        int32_T Reset;                 // '<S93>/Cast To int32'
        int32_T DelayInput1_DSTATE;    // '<S116>/Delay Input1'
        int32_T MemoryFlightStatus_PreviousInput;// '<S54>/MemoryFlightStatus'
        int32_T MemoryImmedStatus_PreviousInput;// '<S54>/MemoryImmedStatus'
        int32_T followSwitch_start;    // '<S92>/NewMission'
        int8_T RateTransition_LstBufWR;// '<Root>/Rate Transition'
        int8_T RateTransition_RDBuf;   // '<Root>/Rate Transition'
        int8_T RTLLA_LstBufWR;         // '<Root>/RTLLA'
        int8_T RTLLA_RDBuf;            // '<Root>/RTLLA'
        uint8_T EngagedFlag_Log;       // '<S129>/Real2SimGuidance'
        uint8_T Memory;                // '<S3>/Memory'
        uint8_T Memory_PreviousInput;  // '<S3>/Memory'
        uint8_T is_active_c14_codegenReal2Mission;// '<S92>/NewMission'
        uint8_T is_c14_codegenReal2Mission;// '<S92>/NewMission'
        uint8_T is_active_c12_codegenReal2Mission;// '<S92>/MisisonCMDTemporalLogic' 
        uint8_T is_c12_codegenReal2Mission;// '<S92>/MisisonCMDTemporalLogic'
        uint8_T is_active_c5_codegenReal2Mission;// '<S93>/TriggerStartSim'
        uint8_T is_c5_codegenReal2Mission;// '<S93>/TriggerStartSim'
        boolean_T ImmedMission_o3[2];  // '<S56>/ImmedMission'
        boolean_T eml_autoflush[20];   // '<S123>/PrintOnboardLog'
        boolean_T eml_autoflush_m[20]; // '<S88>/PrintOnboardLog'
        boolean_T OR;                  // '<S54>/OR'
        boolean_T NewMission;          // '<S92>/NewMission'
        boolean_T StartSim;            // '<S93>/TriggerStartSim'
        boolean_T DelayInput1_DSTATE_d;// '<S7>/Delay Input1'
        boolean_T DelayInput1_DSTATE_k;// '<S111>/Delay Input1'
        boolean_T InitMemory_PreviousInput;// '<S110>/InitMemory'
        boolean_T Memory_PreviousInput_e;// '<S110>/Memory'
        boolean_T MemoryPreemption_PreviousInput;// '<S110>/MemoryPreemption'
        boolean_T localObj_not_empty;  // '<S61>/getDangerList'
        boolean_T MissionSimUAV_MODE;  // '<S93>/MissionSimUAV'
    };

    // Continuous states (default storage)
    struct X_codegenReal2Mission_T {
        X_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S129>/Real2SimGuidance' 
        X_MissionUAV_n_T MissionUavModel_CSTATE;// '<S102>/MissionUavModel'
    };

    // State derivatives (default storage)
    struct XDot_codegenReal2Mission_T {
        XDot_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S129>/Real2SimGuidance' 
        XDot_MissionUAV_n_T MissionUavModel_CSTATE;// '<S102>/MissionUavModel'
    };

    // State disabled
    struct XDis_codegenReal2Mission_T {
        XDis_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S129>/Real2SimGuidance' 
        XDis_MissionUAV_n_T MissionUavModel_CSTATE;// '<S102>/MissionUavModel'
    };

    // Zero-crossing (trigger) state
    struct PrevZCX_codegenReal2Mission_T {
        ZCSigState TriggerMissionDispatch_Trig_ZCE;// '<S109>/TriggerMissionDispatch' 
        ZCSigState TriggerBroadcastAtMissionTime_Trig_ZCE;// '<S92>/TriggerBroadcastAtMissionTime' 
        ZCSigState FeedbackMissionCMD_Trig_ZCE;// '<S93>/FeedbackMissionCMD'
        ZCSigState TriggerCurrentMisisonFeedback_Trig_ZCE;// '<S54>/TriggerCurrentMisisonFeedback' 
    };

    // External inputs (root inport signals with default storage)
    struct ExtU_codegenReal2Mission_T {
        uint8_T FlightMode;            // '<Root>/FlightMode'
        StateFCU FlightState;          // '<Root>/FlightState'
    };

    // External outputs (root outports fed by signals with default storage)
    struct ExtY_codegenReal2Mission_T {
        FCUCMD FlightCMD;              // '<Root>/FlightCMD'
        TaskStatus MissionFB;          // '<Root>/MissionFB'
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
        boolean_T *contStateDisabled;
        boolean_T zCCacheNeedsReset;
        boolean_T derivCacheNeedsReset;
        boolean_T CTOutputIncnstWithState;
        real_T odeY[15];
        real_T odeF[4][15];
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
            boolean_T firstInitCondFlag;
            SimTimeStep simTimeStep;
            boolean_T stopRequestedFlag;
            time_T *t;
            time_T tArray[4];
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
        CurrentMissionSendData_arg, SendData_FlightLoggingT &
        FlightLogSendData_arg, RecvData_IndividualUAVCmdT &
        MissionCMDRecvData_arg, RecvData_RealUAVStateBusT &
        NbrUAVstateRecvData_arg);

    // Root inports set method
    void setExternalInputs(const ExtU_codegenReal2Mission_T
                           *pExtU_codegenReal2Mission_T)
    {
        codegenReal2Mission_U = *pExtU_codegenReal2Mission_T;
    }

    // Root outports get method
    const ExtY_codegenReal2Mission_T &getExternalOutputs() const
    {
        return codegenReal2Mission_Y;
    }

    // model initialize function
    void initialize();

    // model step function
    void step();

    // model step function
    void codegenReal2Mission_PushNbrUAV();

    // model terminate function
    void terminate();

    // Destructor
    ~codegenReal2MissionModelClass();

    // private data and function members
  private:
    // External inputs
    ExtU_codegenReal2Mission_T codegenReal2Mission_U;

    // External outputs
    ExtY_codegenReal2Mission_T codegenReal2Mission_Y;

    // Block states
    DW_codegenReal2Mission_T codegenReal2Mission_DW;

    // Block continuous states
    X_codegenReal2Mission_T codegenReal2Mission_X;

    // Triggered events
    PrevZCX_codegenReal2Mission_T codegenReal2Mission_PrevZCX;
    SendData_IndividualUAVCmdT &CurrentMissionSendData;
    SendData_FlightLoggingT &FlightLogSendData;
    RecvData_IndividualUAVCmdT &MissionCMDRecvData;
    RecvData_RealUAVStateBusT &NbrUAVstateRecvData;

    // private member function(s) for subsystem '<Root>'
    void codegenReal2Mission_emxInit_real_T
        (emxArray_real_T_codegenReal2Mission_T **pEmxArray, int32_T
         numDimensions);
    int8_T codegenReal2Mission_filedata_i(void) const;
    int8_T codegenReal2Mission_cfopen_o(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_fileManager_f(real_T varargin_1, FILE* *f,
        boolean_T *a);
    void codegenReal2Mission_string_string(MissionModes val, char_T
        obj_Value_data[], int32_T obj_Value_size[2]);
    void codegenReal2Mission_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
        real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
        real_T *t_tm_year, boolean_T *t_tm_isdst);
    creal_T codegenReal2Mission_two_prod(real_T a);
    creal_T codegenReal2Mission_times(const creal_T a);
    creal_T codegenReal2Mission_two_sum(real_T a, real_T b);
    creal_T codegenReal2Mission_plus(const creal_T a, real_T b);
    creal_T codegenReal2Mission_datetime_datetime(void);
    creal_T codegenReal2Mission_two_diff(real_T a, real_T b);
    creal_T codegenReal2Mission_minus(const creal_T a, const creal_T b);
    void codegenReal2Mission_getDateVec(const creal_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
    void codegenReal2Mission_printIndivMissionCMD_f(int32_T
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
    int32_T codegenReal2Mission_cfclose_l(real_T fid);
    IndividualUAVCmd *codegenReal2Mission_allocMemPool(MemPool_IndividualUAVCmd *
        memPool, int32_T width);
    Msg_IndividualUAVCmd codegenReal2Mission_createMsg_p(const IndividualUAVCmd *
        data);
    void codegenReal2Mission_freeMemPool(MemPool_IndividualUAVCmd *memPool,
        IndividualUAVCmd *dataPtr);
    void codegenReal2Mission_destroyMsg_m(Msg_IndividualUAVCmd *msg);
    boolean_T codegenReal2Mission_push_i(Queue_IndividualUAVCmd *q,
        Msg_IndividualUAVCmd *element);
    int32_T codegenReal2Mission_Queue_SendData(const IndividualUAVCmd *data);
    boolean_T codegenReal2Mission_pop_c(Queue_IndividualUAVCmd *q,
        Msg_IndividualUAVCmd *elementOut);
    int32_T codegenReal2Mission_Queue_RecvData(IndividualUAVCmd *data);
    DangerInfo *codegenReal2Mission_allocMemPool_n(MemPool_DangerInfo *memPool,
        int32_T width);
    Msg_DangerInfo codegenReal2Mission_createMsg_fl(const DangerInfo *data);
    void codegenReal2Mission_freeMemPool_j(MemPool_DangerInfo *memPool,
        DangerInfo *dataPtr);
    void codegenReal2Mission_destroyMsg_i(Msg_DangerInfo *msg);
    boolean_T codegenReal2Mission_push_j(Buffer_DangerInfo *q, Msg_DangerInfo
        *element);
    int32_T codegenReal2Mission_Receive_SendData(const DangerInfo *data);
    creal_T codegenReal2Mission_createFromDateVec(const real_T inData[7]);
    boolean_T codegenReal2Mission_isequaln_n(MissionModes varargin_1,
        MissionModes varargin_2);
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
    MissionModes codegenReal2Mission_convert_to_enum_MissionModes(int32_T input);
    creal_T codegenReal2Mission_divide(const creal_T a);
    void codegenReal2Mission_days2ymd(real_T days, real_T *y, real_T *m, real_T *
        d);
    void codegenReal2Mission_secs2hms(real_T secs, real_T *h, real_T *m, real_T *
        s);
    void codegenReal2Mission_getDateVec_o(real_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
    void codegenReal2Mission_getDateVec_oe(const creal_T dd, real_T *y, real_T
        *mo, real_T *d, real_T *h, real_T *m, real_T *s);
    missionCmd *codegenReal2Mission_allocMemPool_c(MemPool_missionCmd *memPool,
        int32_T width);
    Msg_missionCmd codegenReal2Mission_createMsg_f(const missionCmd *data);
    void codegenReal2Mission_freeMemPool_h(MemPool_missionCmd *memPool,
        missionCmd *dataPtr);
    void codegenReal2Mission_destroyMsg_g(Msg_missionCmd *msg);
    boolean_T codegenReal2Mission_push_ix(Buffer_missionCmd *q, Msg_missionCmd
        *element);
    int32_T codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_MessageMerge_In1_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_RcvImmedCMD_SendData(const missionCmd *data);
    boolean_T codegenReal2Mission_pop_h(Buffer_missionCmd *q, Msg_missionCmd
        *elementOut);
    int32_T codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd *
        data);
    int32_T codegenReal2Mission_ReceiveCurrentMission_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_RcvImmedCMD_RecvData(missionCmd *data);
    boolean_T codegenReal2Mission_pop_j(Buffer_DangerInfo *q, Msg_DangerInfo
        *elementOut);
    int32_T codegenReal2Mission_Receive_RecvData(DangerInfo *data);
    void codegenReal2Mission_int2str(real_T xin, char_T s_data[], int32_T
        s_size[2]);
    void codegenReal2Mission_emxEnsureCapacity_real_T
        (emxArray_real_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
    void codegenReal2Mission_flipud(emxArray_real_T_codegenReal2Mission_T *x);
    void codegenReal2Mission_emxInit_int32_T
        (emxArray_int32_T_codegenReal2Mission_T **pEmxArray, int32_T
         numDimensions);
    void codegenReal2Mission_emxEnsureCapacity_int32_T
        (emxArray_int32_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
    void codegenReal2Mission_emxFree_int32_T
        (emxArray_int32_T_codegenReal2Mission_T **pEmxArray);
    void codegenReal2Mission_sortIdx(const emxArray_real_T_codegenReal2Mission_T
        *x, emxArray_int32_T_codegenReal2Mission_T *idx);
    void codegenReal2Mission_emxFree_real_T
        (emxArray_real_T_codegenReal2Mission_T **pEmxArray);
    void codegenReal2Mission_unique_vector(const
        emxArray_real_T_codegenReal2Mission_T *a,
        emxArray_real_T_codegenReal2Mission_T *b,
        emxArray_int32_T_codegenReal2Mission_T *ndx,
        emxArray_int32_T_codegenReal2Mission_T *pos);
    void codegenReal2Mission_emxInit_boolean_T
        (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray, int32_T
         numDimensions);
    void codegenReal2Mission_emxEnsureCapacity_boolean_T
        (emxArray_boolean_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
    void codegenReal2Mission_emxFree_boolean_T
        (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray);
    int32_T codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data);
    void codegenReal2Mission_getDateVec_g(real_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
    int8_T codegenReal2Mission_filedata(void) const;
    int8_T codegenReal2Mission_cfopen(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_fileManager(real_T varargin_1, FILE* *f, boolean_T *
        a);
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
    int32_T codegenReal2Mission_cfclose(real_T fid);
    Msg_real_T codegenReal2Mission_createMsg(const real_T *data);
    boolean_T codegenReal2Mission_push(Buffer_real_T *q, const Msg_real_T
        *element);
    int32_T codegenReal2Mission_Receive_c_SendData(const real_T *data);
    boolean_T codegenReal2Mission_pop(Buffer_real_T *q, Msg_real_T *elementOut);
    int32_T codegenReal2Mission_Receive_l_RecvData(real_T *data);
    void codegenReal2Mission_emxFreeStruct_DangerArray
        (DangerArray_codegenReal2Mission_T *pStruct);
    void codegenReal2Mission_initMemPool(MemPool_IndividualUAVCmd *memPool,
        IndividualUAVCmd *memArray, IndividualUAVCmd **freeList, int32_T size);
    void codegenReal2Mission_initMemPool_o(MemPool_missionCmd *memPool,
        missionCmd *memArray, missionCmd **freeList, int32_T size);
    void codegenReal2Mission_initMemPool_d(MemPool_DangerInfo *memPool,
        DangerInfo *memArray, DangerInfo **freeList, int32_T size);
    void codegenReal2Mission_initQueue(Queue_IndividualUAVCmd *q, QueuePolicy_T
        policy, int32_T capacity, Msg_IndividualUAVCmd *qPool);
    void codegenReal2Mission_emxInitStruct_DangerArray
        (DangerArray_codegenReal2Mission_T *pStruct);
    void codegenReal2Mission_emxInit_char_T
        (emxArray_char_T_codegenReal2Mission_T **pEmxArray, int32_T
         numDimensions);
    int8_T codegenReal2Mission_filedata_k(const FILE* eml_openfiles_g[20]);
    int8_T codegenReal2Mission_cfopen_g(const char_T *cfilename, const char_T
        *cpermission, FILE* eml_openfiles_g[20]);
    void codegenReal2Mission_emxEnsureCapacity_char_T
        (emxArray_char_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
    void codegenReal2Mission_fread(real_T fileID, FILE* eml_openfiles_g[20],
        emxArray_char_T_codegenReal2Mission_T *A);
    int32_T codegenReal2Mission_cfclose_e(real_T fid, FILE* eml_openfiles_g[20]);
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
    boolean_T codegenReal2Mission_strcmp_i(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_copydigits
        (emxArray_char_T_codegenReal2Mission_T *s1, int32_T *idx, const
         emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n,
         boolean_T allowpoint);
    void codegenReal2Mission_readfloat(emxArray_char_T_codegenReal2Mission_T *s1,
        int32_T *idx, const emxArray_char_T_codegenReal2Mission_T *s, int32_T *k,
        int32_T n, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
        real_T *nfv, boolean_T *foundsign, boolean_T *success);
    creal_T codegenReal2Mission_str2double(const
        emxArray_char_T_codegenReal2Mission_T *s);
    boolean_T codegenReal2Mission_strcmp_i1(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_i15(const
        emxArray_char_T_codegenReal2Mission_T *a);
    int8_T codegenReal2Mission_filedata_e(void) const;
    int8_T codegenReal2Mission_cfopen_j(const char_T *cfilename, const char_T
        *cpermission);
    real_T codegenReal2Mission_fileManager_p(void);
    void codegenReal2Mission_fread_n(real_T fileID,
        emxArray_char_T_codegenReal2Mission_T *A);
    int32_T codegenReal2Mission_cfclose_g(real_T fid);
    void codegenReal2Mission_strtok_e2sz(const
        emxArray_char_T_codegenReal2Mission_T *x,
        emxArray_char_T_codegenReal2Mission_T *token);
    boolean_T codegenReal2Mission_strcmp_b(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_by(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_byv(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_byvm(const
        emxArray_char_T_codegenReal2Mission_T *a);
    boolean_T codegenReal2Mission_strcmp_byvm0(const
        emxArray_char_T_codegenReal2Mission_T *a);
    void codegenReal2Mission_readINI(emxArray_char_T_codegenReal2Mission_T *ret);
    void codegenReal2Mission_readINI_g(emxArray_char_T_codegenReal2Mission_T
        *ret);
    void codegenReal2Mission_readINI_gx(emxArray_char_T_codegenReal2Mission_T
        *ret);
    boolean_T codegenReal2Mission_strcmp_byvm0m(const
        emxArray_char_T_codegenReal2Mission_T *a);

    // Continuous states update member function
    void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

    // Derivatives member function
    void codegenReal2Mission_derivatives();

    // Real-Time Model
    RT_MODEL_codegenReal2Mission_T codegenReal2Mission_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S28>/Data Type Duplicate' : Unused code path elimination
//  Block '<S61>/Down2Up' : Unused code path elimination
//  Block '<S63>/Data Type Duplicate' : Unused code path elimination
//  Block '<S63>/Sum' : Unused code path elimination
//  Block '<S63>/Ze2height' : Unused code path elimination
//  Block '<S61>/inverse' : Unused code path elimination
//  Block '<S106>/BiasID' : Unused code path elimination
//  Block '<S106>/Divide' : Unused code path elimination
//  Block '<S106>/GreaterThan' : Unused code path elimination
//  Block '<S106>/Mod' : Unused code path elimination
//  Block '<S106>/One' : Unused code path elimination
//  Block '<S106>/Sum' : Unused code path elimination
//  Block '<S106>/SwitchpDelay' : Unused code path elimination
//  Block '<S106>/SwitchxDelay' : Unused code path elimination
//  Block '<S106>/Zero' : Unused code path elimination
//  Block '<S106>/deBiasID' : Unused code path elimination
//  Block '<S106>/half' : Unused code path elimination
//  Block '<S106>/pCeil' : Unused code path elimination
//  Block '<S106>/pGain' : Unused code path elimination
//  Block '<S106>/pMinus' : Unused code path elimination
//  Block '<S106>/xCeil' : Unused code path elimination
//  Block '<S106>/xGain' : Unused code path elimination
//  Block '<S23>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S61>/Reshape' : Reshape block reduction
//  Block '<S54>/Cast To uint8' : Eliminate redundant data type conversion
//  Block '<S54>/intFormationPos' : Eliminate redundant data type conversion
//  Block '<S54>/intMissionMode' : Eliminate redundant data type conversion
//  Block '<S54>/intNumUAV' : Eliminate redundant data type conversion
//  Block '<S54>/intSequenceId' : Eliminate redundant data type conversion
//  Block '<S119>/Signal Copy' : Eliminate redundant signal conversion block


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
//  '<S1>'   : 'codegenReal2Mission/DeSerOtherUAV'
//  '<S2>'   : 'codegenReal2Mission/GCSLLA'
//  '<S3>'   : 'codegenReal2Mission/MissionLogic'
//  '<S4>'   : 'codegenReal2Mission/TrackingControl'
//  '<S5>'   : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer'
//  '<S6>'   : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/Compare To Constant'
//  '<S7>'   : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/Detect Fall Nonpositive'
//  '<S8>'   : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/Enabled Subsystem'
//  '<S9>'   : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState'
//  '<S10>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/WriteBuff'
//  '<S11>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/testUniq'
//  '<S12>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/Detect Fall Nonpositive/Nonpositive'
//  '<S13>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem'
//  '<S14>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConcatenateUAVPos'
//  '<S15>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState'
//  '<S16>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED'
//  '<S17>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/PrintNbrID'
//  '<S18>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ReadBuff'
//  '<S19>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/DivisionByZeroProtection'
//  '<S20>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/MATLAB Function'
//  '<S21>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/Radians to Degrees'
//  '<S22>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix'
//  '<S23>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S24>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast'
//  '<S25>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/Degrees to Radians'
//  '<S26>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/Degrees to Radians1'
//  '<S27>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/Degrees to Radians2'
//  '<S28>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth'
//  '<S29>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S30>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S31>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S32>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S33>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S34>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S35>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S36>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S37>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S38>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S39>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S40>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S41>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S42>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S43>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S44>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S45>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S46>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S47>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S48>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S49>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S50>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S51>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/PrintNbrID/PrintNbrID'
//  '<S52>'  : 'codegenReal2Mission/DeSerOtherUAV/While Iterator Serializer/WriteBuff/WriteBuff'
//  '<S53>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints'
//  '<S54>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission'
//  '<S55>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant'
//  '<S56>'  : 'codegenReal2Mission/MissionLogic/ImmedMission_Variant'
//  '<S57>'  : 'codegenReal2Mission/MissionLogic/InitializeSimLocation'
//  '<S58>'  : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD'
//  '<S59>'  : 'codegenReal2Mission/MissionLogic/RemoveNaN'
//  '<S60>'  : 'codegenReal2Mission/MissionLogic/VisualizeUAV'
//  '<S61>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD'
//  '<S62>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/InterpCircle'
//  '<S63>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth'
//  '<S64>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/getDangerList'
//  '<S65>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/sizeconversion'
//  '<S66>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap'
//  '<S67>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0'
//  '<S68>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem'
//  '<S69>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/pos_rad'
//  '<S70>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S71>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S72>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S73>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S74>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S75>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S76>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S77>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S78>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S79>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S80>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S81>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S82>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S83>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S84>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S85>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S86>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S87>'  : 'codegenReal2Mission/MissionLogic/DangerLidarScanPoints/GenPCD/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S88>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback'
//  '<S89>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/PrintOnboardLog'
//  '<S90>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/TimeConverter'
//  '<S91>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler'
//  '<S92>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV'
//  '<S93>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission'
//  '<S94>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/JumpDelay'
//  '<S95>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic'
//  '<S96>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission'
//  '<S97>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/TriggerBroadcastAtMissionTime'
//  '<S98>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/getCurrentTime'
//  '<S99>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/Compare To Constant'
//  '<S100>' : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/Compare To Zero (ID)'
//  '<S101>' : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/FeedbackMissionCMD'
//  '<S102>' : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/MissionSimUAV'
//  '<S103>' : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/NullLoc'
//  '<S104>' : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/SimState2Pose'
//  '<S105>' : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim'
//  '<S106>' : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/JumpDelay/ComputDelay'
//  '<S107>' : 'codegenReal2Mission/MissionLogic/InitializeSimLocation/ReadHomePoint'
//  '<S108>' : 'codegenReal2Mission/MissionLogic/InitializeSimLocation/ReadParADRC'
//  '<S109>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation'
//  '<S110>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD'
//  '<S111>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation/Detect Rise Positive'
//  '<S112>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation/TriggerMissionDispatch'
//  '<S113>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation/getCurrentTime'
//  '<S114>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation/Detect Rise Positive/Positive'
//  '<S115>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/MissionValidation/TriggerMissionDispatch/CommandCheck'
//  '<S116>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/Detect Change'
//  '<S117>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/IsAvoidDanger'
//  '<S118>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/NotAvoidDanger'
//  '<S119>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/ProcessDanger'
//  '<S120>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/ReadOne'
//  '<S121>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/Struct2PosixCurr'
//  '<S122>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/Struct2PosixUplink'
//  '<S123>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/UplinkLog'
//  '<S124>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/getCurrentTime'
//  '<S125>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/greaterthanZero'
//  '<S126>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/smallerthanZero'
//  '<S127>' : 'codegenReal2Mission/MissionLogic/PreProcessMissionCMD/QueueCMD/UplinkLog/PrintOnboardLog'
//  '<S128>' : 'codegenReal2Mission/MissionLogic/VisualizeUAV/VisualizeUAV'
//  '<S129>' : 'codegenReal2Mission/TrackingControl/Real2SimGuidance'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
