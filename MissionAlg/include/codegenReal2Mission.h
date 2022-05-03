//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.222
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue May  3 03:10:34 2022
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
#include "model_reference_types.h"
#include <cstring>
#include "zero_crossing_types.h"

// Includes for objects with custom storage classes
#include "GCS_Location.h"

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
                                      // '<S14>/PreemptableMissionModeSelector'
        MdlrefDW_ImmedMission_T ImmedMission_InstanceData;// '<S5>/ImmedMission' 
        MdlrefDW_MissionUAV_T MissionUavModel_InstanceData;// '<S23>/MissionUavModel' 
        MdlrefDW_Real2SimGuidance_T Real2SimGuidance_InstanceData;// '<S33>/Real2SimGuidance' 
        FILE* eml_openfiles[20];       // '<S9>/PrintOnboardLog'
        missionCmd slMsgMgr_memArray_missionCmd[9];// synthesized block
        FlightLogging Real2SimGuidance_o3;// '<S33>/Real2SimGuidance'
        IndividualUAVCmd ReceivePushedMissionCMD_o2;// '<S1>/ReceivePushedMissionCMD' 
        IndividualUAVCmd IndivCMD;     // '<S9>/IndivCMD'
        missionCmd RcvNextMission;     // '<S1>/RcvNextMission'
        missionCmd RcvImmedCMD_o2;     // '<S1>/RcvImmedCMD'
        missionCmd ReceiveThisMission_o2;// '<S3>/ReceiveThisMission'
        missionCmd ImmedCMD;           // '<S29>/CommandCheck'
        missionCmd ReceiveCurrentMission_o2;// '<S14>/ReceiveCurrentMission'
        missionCmd CurrentFlightMission;// '<S1>/DataStoreMissionCmd'
        missionCmd MissionCMD;         // '<S29>/DataStoreMissionCmd'
        FixedWingGuidanceStateBus
            BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1;
        FixedWingGuidanceStateBus ImmedMission_o2;// '<S5>/ImmedMission'
        ParamADRC ParamADRC_e;         // '<S1>/Data Store Memory'
        MemPool_missionCmd slMsgMgr_MemPool_missionCmd;// synthesized block
        FixedWingGuidanceBus ImmedMission_o4;// '<S5>/ImmedMission'
        FixedWingGuidanceBus PreemptableMissionModeSelector_o2;
                                      // '<S14>/PreemptableMissionModeSelector'
        Buffer_missionCmd Queue_InsertedFor_RcvNextMission_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_FlightMission_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd
            Queue_InsertedFor_FeedbackCurrentMission_at_inport_4_Queue;// synthesized block 
        real_T PreemptableMissionModeSelector_o3[8];
                                      // '<S14>/PreemptableMissionModeSelector'
        real_T
            TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [4];
        real_T MemoryPose_PreviousInput[4];// '<S14>/MemoryPose'
        real_T thisTaskStatus;         // '<S5>/ImmedMission'
        real_T PushImmed;              // '<S29>/CommandCheck'
        real_T TriggerSend;            // '<S13>/MisisonCMDTemporalLogic'
        real_T DivideThree;            // '<S27>/DivideThree'
        real_T thisTaskStatus_g;      // '<S14>/PreemptableMissionModeSelector'
        real_T CastToDouble;           // '<S23>/Cast To Double'
        real_T North;                  // '<S23>/MissionUavModel'
        real_T East;                   // '<S23>/MissionUavModel'
        real_T Height;                 // '<S23>/MissionUavModel'
        real_T AirSpeed;               // '<S23>/MissionUavModel'
        real_T HeadingAngle;           // '<S23>/MissionUavModel'
        real_T FlightPathAngle;        // '<S23>/MissionUavModel'
        real_T RollAngle;              // '<S23>/MissionUavModel'
        real_T RollAngleRate;          // '<S23>/MissionUavModel'
        real_T Memory_PreviousInput;   // '<S7>/Memory'
        real_T NewRun;                 // '<S9>/PrintOnboardLog'
        missionCmd* slMsgMgr_freeList_missionCmd[9];// synthesized block
        int32_T Reset;                 // '<S14>/Cast To int32'
        int32_T MemoryFlightStatus_PreviousInput;// '<S3>/MemoryFlightStatus'
        int32_T MemoryImmedStatus_PreviousInput;// '<S3>/MemoryImmedStatus'
        int32_T followSwitch_start;    // '<S13>/NewMission'
        uint8_T EngagedFlag_Log;       // '<S33>/Real2SimGuidance'
        uint8_T Memory;                // '<S1>/Memory'
        uint8_T Memory_PreviousInput_l;// '<S1>/Memory'
        uint8_T is_active_c14_codegenReal2Mission;// '<S13>/NewMission'
        uint8_T is_c14_codegenReal2Mission;// '<S13>/NewMission'
        uint8_T is_active_c12_codegenReal2Mission;// '<S13>/MisisonCMDTemporalLogic' 
        uint8_T is_c12_codegenReal2Mission;// '<S13>/MisisonCMDTemporalLogic'
        uint8_T is_active_c5_codegenReal2Mission;// '<S14>/TriggerStartSim'
        uint8_T is_c5_codegenReal2Mission;// '<S14>/TriggerStartSim'
        boolean_T ImmedMission_o3[2];  // '<S5>/ImmedMission'
        boolean_T eml_autoflush[20];   // '<S9>/PrintOnboardLog'
        boolean_T OR;                  // '<S3>/OR'
        boolean_T NewMission;          // '<S13>/NewMission'
        boolean_T StartSim;            // '<S14>/TriggerStartSim'
        boolean_T NewRun_not_empty;    // '<S9>/PrintOnboardLog'
        boolean_T MissionSimUAV_MODE;  // '<S14>/MissionSimUAV'
    };

    // Continuous states (default storage)
    struct X_codegenReal2Mission_T {
        X_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S33>/Real2SimGuidance' 
        X_MissionUAV_n_T MissionUavModel_CSTATE;// '<S23>/MissionUavModel'
    };

    // State derivatives (default storage)
    struct XDot_codegenReal2Mission_T {
        XDot_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S33>/Real2SimGuidance' 
        XDot_MissionUAV_n_T MissionUavModel_CSTATE;// '<S23>/MissionUavModel'
    };

    // State disabled
    struct XDis_codegenReal2Mission_T {
        XDis_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<S33>/Real2SimGuidance' 
        XDis_MissionUAV_n_T MissionUavModel_CSTATE;// '<S23>/MissionUavModel'
    };

    // Zero-crossing (trigger) state
    struct PrevZCX_codegenReal2Mission_T {
        ZCSigState TriggerBroadcastAtMissionTime_Trig_ZCE;// '<S13>/TriggerBroadcastAtMissionTime' 
        ZCSigState FeedbackMissionCMD_Trig_ZCE;// '<S14>/FeedbackMissionCMD'
        ZCSigState TriggerCurrentMisisonFeedback_Trig_ZCE;// '<S3>/TriggerCurrentMisisonFeedback' 
    };

    // Constant parameters (default storage)
    struct ConstP_codegenReal2Mission_T {
        // Expression: struct('hat_b', 0.25, 'omega_o', 1, 'omega_b', 0.1, 'P', 0.2, 'I', 0.01, 'D', 0.01, 'useADRC', true)
        //  Referenced by: '<S1>/Data Store Memory'

        ParamADRC DataStoreMemory_InitialValue;
    };

    // External inputs (root inport signals with default storage)
    struct ExtU_codegenReal2Mission_T {
        uint8_T FlightMode;            // '<Root>/FlightMode'
        RealUAVStateBus OtherUAVstate[128];// '<Root>/OtherUAVstate'
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
            time_T tArray[3];
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
        MissionCMDRecvData_arg);

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

    // private member function(s) for subsystem '<Root>'
    creal_T codegenReal2Mission_two_prod(real_T a);
    creal_T codegenReal2Mission_times(const creal_T a);
    creal_T codegenReal2Mission_two_sum(real_T a, real_T b);
    creal_T codegenReal2Mission_plus(const creal_T a, real_T b);
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
    void codegenReal2Mission_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
        real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
        real_T *t_tm_year, boolean_T *t_tm_isdst);
    MissionModes codegenReal2Mission_convert_to_enum_MissionModes(int32_T input);
    creal_T codegenReal2Mission_two_diff(real_T a, real_T b);
    creal_T codegenReal2Mission_divide(const creal_T a);
    creal_T codegenReal2Mission_minus(const creal_T a, const creal_T b);
    void codegenReal2Mission_days2ymd(real_T days, real_T *y, real_T *m, real_T *
        d);
    void codegenReal2Mission_secs2hms(real_T secs, real_T *h, real_T *m, real_T *
        s);
    void codegenReal2Mission_getDateVec_o(real_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
    void codegenReal2Mission_getDateVec_oe(const creal_T dd, real_T *y, real_T
        *mo, real_T *d, real_T *h, real_T *m, real_T *s);
    missionCmd *codegenReal2Mission_allocMemPool(MemPool_missionCmd *memPool,
        int32_T width);
    Msg_missionCmd codegenReal2Mission_createMsg(const missionCmd *data);
    void codegenReal2Mission_freeMemPool(MemPool_missionCmd *memPool, missionCmd
        *dataPtr);
    void codegenReal2Mission_destroyMsg(Msg_missionCmd *msg);
    boolean_T codegenReal2Mission_push(Buffer_missionCmd *q, Msg_missionCmd
        *element);
    int32_T codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_MessageMerge_In1_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_RcvImmedCMD_SendData(const missionCmd *data);
    boolean_T codegenReal2Mission_pop(Buffer_missionCmd *q, Msg_missionCmd
        *elementOut);
    int32_T codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd *
        data);
    int32_T codegenReal2Mission_ReceiveCurrentMission_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_RcvImmedCMD_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data);
    void codegenReal2Mission_getDateVec_g(real_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
    int8_T codegenReal2Mission_filedata(void) const;
    int8_T codegenReal2Mission_cfopen(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_fileManager(real_T varargin_1, FILE* *f, boolean_T *
        a);
    void codegenReal2Mission_string_string(MissionModes val, char_T
        obj_Value_data[], int32_T obj_Value_size[2]);
    creal_T codegenReal2Mission_datetime_datetime(void);
    void codegenReal2Mission_getDateVec(const creal_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
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
    void codegenReal2Mission_initMemPool(MemPool_missionCmd *memPool, missionCmd
        *memArray, missionCmd **freeList, int32_T size);

    // Continuous states update member function
    void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

    // Derivatives member function
    void codegenReal2Mission_derivatives();

    // Real-Time Model
    RT_MODEL_codegenReal2Mission_T codegenReal2Mission_M;
};

// Constant parameters (default storage)
extern const codegenReal2MissionModelClass::ConstP_codegenReal2Mission_T
    codegenReal2Mission_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S27>/BiasID' : Unused code path elimination
//  Block '<S27>/Divide' : Unused code path elimination
//  Block '<S27>/GreaterThan' : Unused code path elimination
//  Block '<S27>/Mod' : Unused code path elimination
//  Block '<S27>/One' : Unused code path elimination
//  Block '<S27>/Sum' : Unused code path elimination
//  Block '<S27>/SwitchpDelay' : Unused code path elimination
//  Block '<S27>/SwitchxDelay' : Unused code path elimination
//  Block '<S27>/Zero' : Unused code path elimination
//  Block '<S27>/deBiasID' : Unused code path elimination
//  Block '<S27>/half' : Unused code path elimination
//  Block '<S27>/pCeil' : Unused code path elimination
//  Block '<S27>/pGain' : Unused code path elimination
//  Block '<S27>/pMinus' : Unused code path elimination
//  Block '<S27>/xCeil' : Unused code path elimination
//  Block '<S27>/xGain' : Unused code path elimination
//  Block '<S3>/Cast To uint8' : Eliminate redundant data type conversion
//  Block '<S3>/intFormationPos' : Eliminate redundant data type conversion
//  Block '<S3>/intMissionMode' : Eliminate redundant data type conversion
//  Block '<S3>/intNumUAV' : Eliminate redundant data type conversion
//  Block '<S3>/intSequenceId' : Eliminate redundant data type conversion


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
//  '<S1>'   : 'codegenReal2Mission/MissionLogic'
//  '<S2>'   : 'codegenReal2Mission/TrackingControl'
//  '<S3>'   : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission'
//  '<S4>'   : 'codegenReal2Mission/MissionLogic/FlightMission_Variant'
//  '<S5>'   : 'codegenReal2Mission/MissionLogic/ImmedMission_Variant'
//  '<S6>'   : 'codegenReal2Mission/MissionLogic/InitializeSimLocation'
//  '<S7>'   : 'codegenReal2Mission/MissionLogic/MissionValidation'
//  '<S8>'   : 'codegenReal2Mission/MissionLogic/VisualizeUAV'
//  '<S9>'   : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback'
//  '<S10>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/PrintOnboardLog'
//  '<S11>'  : 'codegenReal2Mission/MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/TimeConverter'
//  '<S12>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler'
//  '<S13>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV'
//  '<S14>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission'
//  '<S15>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/JumpDelay'
//  '<S16>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic'
//  '<S17>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission'
//  '<S18>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/TriggerBroadcastAtMissionTime'
//  '<S19>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/getCurrentTime'
//  '<S20>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/Compare To Constant'
//  '<S21>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/Compare To Zero (ID)'
//  '<S22>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/FeedbackMissionCMD'
//  '<S23>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/MissionSimUAV'
//  '<S24>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/NullLoc'
//  '<S25>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/SimState2Pose'
//  '<S26>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim'
//  '<S27>'  : 'codegenReal2Mission/MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/JumpDelay/ComputDelay'
//  '<S28>'  : 'codegenReal2Mission/MissionLogic/MissionValidation/Compare To Zero'
//  '<S29>'  : 'codegenReal2Mission/MissionLogic/MissionValidation/TriggerMissionDispatch'
//  '<S30>'  : 'codegenReal2Mission/MissionLogic/MissionValidation/getCurrentTime'
//  '<S31>'  : 'codegenReal2Mission/MissionLogic/MissionValidation/TriggerMissionDispatch/CommandCheck'
//  '<S32>'  : 'codegenReal2Mission/MissionLogic/VisualizeUAV/VisualizeUAV'
//  '<S33>'  : 'codegenReal2Mission/TrackingControl/Real2SimGuidance'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
