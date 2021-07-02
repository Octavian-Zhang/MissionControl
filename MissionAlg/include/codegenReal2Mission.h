//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.680
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Jul  2 04:32:41 2021
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
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <cfloat>
#include <stddef.h>
#include "RecvData_IndividualUAVCmdT.h"
#include "SendData_IndividualUAVCmdT.h"
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "codegenReal2Mission_types.h"

// Shared type includes
#include "multiword_types.h"
#include "model_reference_types.h"

// Child system includes
#define Real2SimGuidance_MDLREF_HIDE_CHILD_
#include "Real2SimGuidance.h"
#define FlightMissionMode_MDLREF_HIDE_CHILD_
#include "FlightMissionMode.h"
#define MissionUAV_MDLREF_HIDE_CHILD_
#include "MissionUAV.h"

// Includes for objects with custom storage classes.
#include "GCS_Location.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"
#include "rtw_linux.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

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

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
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
extern const FixedWingGuidanceBus codegenReal2Mission_rtZFixedWingGuidanceBus;// FixedWingGuidanceBus ground 

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
class codegenReal2MissionModelClass {
    // public data and function members
  public:
    // Block signals and states (default storage) for system '<Root>'
    struct DW_codegenReal2Mission_T {
        FILE * eml_openfiles[20];      // '<S9>/PrintOnboardLog'
        uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T obj;// '<S38>/TrackSimPath' 
        missionCmd slMsgMgr_memArray_missionCmd[9];// synthesized block
        missionCmd RateTransition_Buf[3];// '<Root>/Rate Transition'
        uav_sluav_internal_system_OrbitFollower_codegenReal2Mission_T obj_j;// '<S28>/Orbit Follower' 
        IndividualUAVCmd ReceivePushedMissionCMD;// '<S6>/ReceivePushedMissionCMD' 
        IndividualUAVCmd IndivCMD;     // '<S9>/IndivCMD'
        missionCmd RcvNextMission_o2;  // '<Root>/RcvNextMission'
        missionCmd RcvImmedCMD_o2;     // '<Root>/RcvImmedCMD'
        missionCmd ReceiveThisMission_o2;// '<S1>/ReceiveThisMission'
        missionCmd ReceiveCurrentMission_o2;// '<S2>/ReceiveCurrentMission'
        missionCmd cmdFlightMission;   // '<Root>/DataStoreMissionCmd'
        missionCmd MissionCMD;         // '<S6>/DataStoreMissionCmd'
        FixedWingGuidanceStateBus
            BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1;
        FixedWingGuidanceStateBus RealUAVState;// '<Root>/Real2SimGuidance'
        FixedWingGuidanceStateBus MemoryPose_PreviousInput;// '<Root>/MemoryPose' 
        MemPool_missionCmd slMsgMgr_MemPool_missionCmd;// synthesized block
        FixedWingGuidanceBus MergeGuidanceCMD;// '<S24>/MergeGuidanceCMD'
        FixedWingGuidanceBus PreemptableMissionModeSelector_o2;// '<S2>/PreemptableMissionModeSelector' 
        Buffer_missionCmd Queue_InsertedFor_RcvNextMission_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd
            Queue_InsertedFor_FeedbackCurrentMission_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue;// synthesized block 
        Buffer_missionCmd
            Queue_InsertedFor_ReceiveCurrentMission_at_inport_0_Queue;// synthesized block 
        real_T Switch[3];              // '<S27>/Switch'
        real_T ProductTargetVec[3];    // '<S40>/ProductTargetVec'
        real_T PreemptableMissionModeSelector_o3[8];// '<S2>/PreemptableMissionModeSelector' 
        real_T DiscreteTimeIntegrator[2];// '<S22>/Discrete-Time Integrator'
        real_T NorthSequence_X[360];   // '<S42>/NorthSequence'
        real_T EastSequence_X[360];    // '<S42>/EastSequence'
        real_T HeightSequence_X[360];  // '<S42>/HeightSequence'
        real_T DiscreteTimeIntegrator_DSTATE[2];// '<S22>/Discrete-Time Integrator' 
        real_T MemoryPose_PreviousInput_h[4];// '<S2>/MemoryPose'
        real_T MatrixConcatenate[1083];// '<S42>/Matrix Concatenate'
        real_T Track[2700];            // '<S37>/Long Track'
        real_T paddedWaypts[2700];
        real_T waypoints_data[2703];
        real_T Real2SimGuidance_o3;    // '<Root>/Real2SimGuidance'
        real_T North;                  // '<S24>/MergeCollAvoidSimUAV'
        real_T East;                   // '<S24>/MergeCollAvoidSimUAV'
        real_T Height;                 // '<S24>/MergeCollAvoidSimUAV'
        real_T AirSpeed;               // '<S24>/MergeCollAvoidSimUAV'
        real_T HeadingAngle;           // '<S24>/MergeCollAvoidSimUAV'
        real_T FlightPathAngle;        // '<S24>/MergeCollAvoidSimUAV'
        real_T RollAngle;              // '<S24>/MergeCollAvoidSimUAV'
        real_T RollAngleRate;          // '<S24>/MergeCollAvoidSimUAV'
        real_T TrackInvH;              // '<S42>/TrackInvH'
        real_T OrbitNavHdg;            // '<S80>/OrbitNavHdg'
        real_T thisTaskStatus;         // '<S2>/PreemptableMissionModeSelector'
        real_T CastToDouble;           // '<S16>/Cast To Double'
        real_T North_o;                // '<S16>/MissionUavModel'
        real_T East_k;                 // '<S16>/MissionUavModel'
        real_T Height_f;               // '<S16>/MissionUavModel'
        real_T AirSpeed_a;             // '<S16>/MissionUavModel'
        real_T HeadingAngle_g;         // '<S16>/MissionUavModel'
        real_T FlightPathAngle_h;      // '<S16>/MissionUavModel'
        real_T RollAngle_b;            // '<S16>/MissionUavModel'
        real_T RollAngleRate_a;        // '<S16>/MissionUavModel'
        real_T TriggerSend;            // '<S2>/MisisonCMDTemporalLogic'
        volatile real_T NonDeterministic_Buffer0;// '<Root>/NonDeterministic'
        real_T MemoryPrevRange_PreviousInput;// '<S27>/MemoryPrevRange'
        real_T NewRun;                 // '<S9>/PrintOnboardLog'
        void* RateTransition_d0_SEMAPHORE;// '<Root>/Rate Transition'
        missionCmd* slMsgMgr_freeList_missionCmd[9];// synthesized block
        int32_T SFunction_DIMS2[2];    // '<S37>/Long Track'
        int32_T CastToint32;           // '<S2>/Cast To int32'
        MissionModes ImmedMissionModeSelectorMode;
                                      // '<S24>/PreemptableMissionModeSelector'
        int8_T RateTransition_LstBufWR;// '<Root>/Rate Transition'
        int8_T RateTransition_RDBuf;   // '<Root>/Rate Transition'
        int8_T SwitchCase_ActiveSubsystem;// '<S24>/Switch Case'
        int8_T DiscreteTimeIntegrator_PrevResetState;// '<S22>/Discrete-Time Integrator' 
        uint8_T is_active_c26_codegenReal2Mission;// '<Root>/MissionSwitch'
        uint8_T is_c26_codegenReal2Mission;// '<Root>/MissionSwitch'
        uint8_T is_FlightMission;      // '<Root>/MissionSwitch'
        uint8_T MemoryStatus_PreviousInput;// '<S27>/MemoryStatus'
        uint8_T is_active_c10_codegenReal2Mission;// '<S37>/TrackSwitch'
        uint8_T is_c10_codegenReal2Mission;// '<S37>/TrackSwitch'
        uint8_T temporalCounter_i1;    // '<S37>/TrackSwitch'
        uint8_T is_active_c5_codegenReal2Mission;// '<S28>/HdgHoldLogic'
        uint8_T is_c5_codegenReal2Mission;// '<S28>/HdgHoldLogic'
        uint8_T temporalCounter_i1_i;  // '<S28>/HdgHoldLogic'
        uint8_T is_active_c25_codegenReal2Mission;
                                      // '<S24>/PreemptableMissionModeSelector'
        uint8_T is_GuidanceLogic;     // '<S24>/PreemptableMissionModeSelector'
        uint8_T is_active_c24_codegenReal2Mission;// '<S2>/TriggerStartSim'
        uint8_T is_c24_codegenReal2Mission;// '<S2>/TriggerStartSim'
        uint8_T is_active_c4_codegenReal2Mission;// '<S17>/EnableSailShift'
        uint8_T is_c4_codegenReal2Mission;// '<S17>/EnableSailShift'
        uint8_T temporalCounter_i1_n;  // '<S17>/EnableSailShift'
        uint8_T is_active_c20_codegenReal2Mission;// '<S2>/MisisonCMDTemporalLogic' 
        uint8_T is_c20_codegenReal2Mission;// '<S2>/MisisonCMDTemporalLogic'
        boolean_T MergeControlSwitch[2];// '<S24>/MergeControlSwitch'
        boolean_T InDangerSequence_X[360];// '<S42>/InDangerSequence'
        boolean_T eml_autoflush[20];   // '<S9>/PrintOnboardLog'
        boolean_T BooleanImmedMode;    // '<Root>/BooleanImmedMode'
        boolean_T endImmed;            // '<Root>/MissionSwitch'
        boolean_T RelationalOperator;  // '<S27>/Relational Operator'
        boolean_T StartSim;            // '<S2>/TriggerStartSim'
        boolean_T NewRun_not_empty;    // '<S9>/PrintOnboardLog'
        boolean_T MissionSimUAV_MODE;  // '<S2>/MissionSimUAV'
    };

    // Continuous states (default storage)
    struct X_codegenReal2Mission_T {
        real_T Real2SimGuidance_CSTATE[7];// '<Root>/Real2SimGuidance'
        real_T MissionUavModel_CSTATE[10];// '<S16>/MissionUavModel'
    };

    // State derivatives (default storage)
    struct XDot_codegenReal2Mission_T {
        real_T Real2SimGuidance_CSTATE[7];// '<Root>/Real2SimGuidance'
        real_T MissionUavModel_CSTATE[10];// '<S16>/MissionUavModel'
    };

    // State disabled
    struct XDis_codegenReal2Mission_T {
        boolean_T Real2SimGuidance_CSTATE[7];// '<Root>/Real2SimGuidance'
        boolean_T MissionUavModel_CSTATE[10];// '<S16>/MissionUavModel'
    };

    // Zero-crossing (trigger) state
    struct PrevZCX_codegenReal2Mission_T {
        ZCSigState TriggerBroadcastAtMissionTime_Trig_ZCE;// '<S2>/TriggerBroadcastAtMissionTime' 
        ZCSigState FeedbackMissionCMD_Trig_ZCE;// '<S2>/FeedbackMissionCMD'
        ZCSigState TriggerCurrentMisisonFeedback_Trig_ZCE;// '<S1>/TriggerCurrentMisisonFeedback' 
    };

    // External inputs (root inport signals with default storage)
    struct ExtU_codegenReal2Mission_T {
        RealUAVStateBus RealUAVLatLonState;// '<Root>/RealUAVLatLonState'
        uint8_T FlightMode;            // '<Root>/FlightMode'
        real_T GroundSpeed;            // '<Root>/GroundSpeed'
        VectorSpeed VectorSpd;         // '<Root>/VectorSpd'
        real_T Altitude;               // '<Root>/Altitude'
    };

    // External outputs (root outports fed by signals with default storage)
    struct ExtY_codegenReal2Mission_T {
        real_T RefAirspeed;            // '<Root>/RefAirspeed'
        LookAheadPoint LookAheadPoint_i;// '<Root>/LookAheadPoint'
        boolean_T EngagedFlag;         // '<Root>/EngagedFlag'
        TaskStatus thisTaskStatus;     // '<Root>/thisTaskStatus'
    };

    // Real-time Model Data Structure
    struct RT_MODEL_codegenReal2Mission_T {
        const char_T *errorStatus;
        RTWLogInfo *rtwLogInfo;
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
        real_T odeY[17];
        real_T odeF[4][17];
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
            time_T tFinal;
            SimTimeStep simTimeStep;
            boolean_T stopRequestedFlag;
            time_T *t;
            time_T tArray[4];
        } Timing;
    };

    // model initialize function
    void initialize();

    // model step function
    void codegenReal2Mission_PushNewMission();

    // model step function
    void step();

    // model terminate function
    void terminate();

    // Constructor
    codegenReal2MissionModelClass(SendData_IndividualUAVCmdT&
        CurrentMissionSendData_arg,RecvData_IndividualUAVCmdT&
        MissionCMDRecvData_arg);

    // Destructor
    ~codegenReal2MissionModelClass();

    // Root-level structure-based inputs set method

    // Root inports set method
    void setExternalInputs(const ExtU_codegenReal2Mission_T
                           * pExtU_codegenReal2Mission_T)
    {
        codegenReal2Mission_U = *pExtU_codegenReal2Mission_T;
    }

    // Root-level structure-based outputs get method

    // Root outports get method
    const codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T
        & getExternalOutputs() const
    {
        return codegenReal2Mission_Y;
    }

    // Real-Time Model get method
    codegenReal2MissionModelClass::RT_MODEL_codegenReal2Mission_T * getRTM();

    // private data and function members
  private:
    // Block signals and states
    DW_codegenReal2Mission_T codegenReal2Mission_DW;
    SendData_IndividualUAVCmdT& CurrentMissionSendData;
    RecvData_IndividualUAVCmdT& MissionCMDRecvData;
    X_codegenReal2Mission_T codegenReal2Mission_X;// Block continuous states
    PrevZCX_codegenReal2Mission_T codegenReal2Mission_PrevZCX;// Triggered events 

    // External inputs
    ExtU_codegenReal2Mission_T codegenReal2Mission_U;

    // External outputs
    ExtY_codegenReal2Mission_T codegenReal2Mission_Y;

    // Real-Time Model
    RT_MODEL_codegenReal2Mission_T codegenReal2Mission_M;

    // private member function(s) for subsystem '<Root>'
    void codegenReal2Mission_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
        real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
        real_T *t_tm_year, boolean_T *t_tm_isdst);
    creal_T codegenReal2Mission_two_sum(real_T a, real_T b);
    creal_T codegenReal2Mission_plus(const creal_T a, real_T b);
    boolean_T codegenReal2Mission_pop(Buffer_missionCmd *q, Msg_missionCmd
        *elementOut);
    void codegenReal2Mission_freeMemPool(MemPool_missionCmd *memPool, missionCmd
        *dataPtr);
    void codegenReal2Mission_destroyMsg(Msg_missionCmd *msg);
    int32_T codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data);
    missionCmd *codegenReal2Mission_allocMemPool(MemPool_missionCmd *memPool,
        int32_T width);
    Msg_missionCmd codegenReal2Mission_createMsg(const missionCmd *data);
    boolean_T codegenReal2Mission_push(Buffer_missionCmd *q, Msg_missionCmd
        *element);
    int32_T codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd *
        data);
    int32_T codegenReal2Mission_ReceiveCurrentMission_RecvData(missionCmd *data);
    int32_T codegenReal2Mission_ReceiveThisMission_SendData(const missionCmd
        *data);
    int32_T codegenReal2Mission_RcvImmedCMD_RecvData(missionCmd *data);
    real_T codegenReal2Mission_norm(const real_T x[2]);
    real_T codegenReal2Mission_norm_b(const real_T x[3]);
    real_T codegenReal2Mission_angdiff(real_T x, real_T y);
    void codegenReal2Mission_any(const boolean_T x_data[], const int32_T x_size
        [2], boolean_T y_data[], int32_T *y_size);
    void codegenReal2Mission_WaypointFollowerBase_getDistinctWpts(const real_T
        waypoints_data[], const int32_T waypoints_size[2], real_T
        distinctWpts_data[], int32_T distinctWpts_size[2]);
    void codegenReal2Mission_WaypointFollowerBase_createWaypoint
        (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
         real_T virtualWaypoint[3]);
    void codegenReal2Mission_emxInit_real_T
        (emxArray_real_T_codegenReal2Mission_T **pEmxArray, int32_T
         numDimensions);
    void codegenReal2Mission_emxEnsureCapacity_real_T
        (emxArray_real_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
    void codegenReal2Mission_emxFree_real_T
        (emxArray_real_T_codegenReal2Mission_T **pEmxArray);
    void codegenReal2Mission_WaypointFollowerBase_searchClosestPath
        (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
         const real_T waypoints_data[], const int32_T waypoints_size[2], const
         real_T currentPose[4]);
    void codegenReal2Mission_WaypointFollowerBase_getWaypoints
        (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
         const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
         startWaypoint[3], real_T endWaypoint[3]);
    void codegenReal2Mission_WaypointFollowerBase_endWaypointReached_b
        (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
         const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
         curStartWaypoint[3], real_T curEndWaypoint[3], const real_T
         currentPose[4]);
    real_T codegenReal2Mission_WaypointFollowerBase_pointToLine(const real_T p1
        [3], const real_T p2[3], const real_T p[3]);
    real_T codegenReal2Mission_WaypointFollowerBase_projectToLine(const real_T
        startWaypoint[3], const real_T endWaypoint[3], const real_T
        currentPosition[3]);
    void codegenReal2Mission_WaypointFollowerBase_getLookahead(const
        uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
        const real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
        currentPosition[3], real_T lookaheadPoint[3]);
    void codegenReal2Mission_WaypointFollowerBase_stepInternal
        (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
         const real_T currentPose[4], real_T waypointsIn_data[], int32_T
         waypointsIn_size[2], real_T lookaheadDist, real_T lookaheadPoint[3],
         real_T *desiredHeading, real_T *desiredYaw, uint8_T *lookaheadDistFlag,
         real_T *crossTrackError, uint8_T *status);
    int32_T codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data);
    creal_T codegenReal2Mission_two_prod(real_T a);
    creal_T codegenReal2Mission_two_diff(real_T a, real_T b);
    void codegenReal2Mission_getDateVec_i(real_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
    int8_T codegenReal2Mission_filedata(void);
    int8_T codegenReal2Mission_cfopen(const char_T *cfilename, const char_T
        *cpermission);
    void codegenReal2Mission_fileManager(real_T varargin_1, FILE * *f, boolean_T
        *a);
    void codegenReal2Mission_string_string(MissionModes val, char_T
        obj_Value_data[], int32_T obj_Value_size[2]);
    creal_T codegenReal2Mission_times(const creal_T a);
    creal_T codegenReal2Mission_datetime_datetime(void);
    creal_T codegenReal2Mission_minus(const creal_T a, const creal_T b);
    void codegenReal2Mission_getDateVec(const creal_T dd, real_T *y, real_T *mo,
        real_T *d, real_T *h, real_T *m, real_T *s);
    void codegenReal2Mission_printIndivMissionCMD(int32_T
        IndivMissionCMD_SequenceId, MissionModes IndivMissionCMD_MissionMode,
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
    creal_T codegenReal2Mission_createFromDateVec(const real_T inData[7]);
    boolean_T codegenReal2Mission_isequaln_f(MissionModes varargin_1,
        MissionModes varargin_2);
    boolean_T codegenReal2Mission_isequaln(int32_T varargin_1_SequenceId,
        MissionModes varargin_1_MissionMode, real_T
        varargin_1_MissionLocation_Lat, real_T varargin_1_MissionLocation_Lon,
        real_T varargin_1_MissionLocation_Alt, real_T
        varargin_1_MissionLocation_degHDG, real32_T varargin_1_params_Param1,
        real32_T varargin_1_params_Param2, real32_T varargin_1_params_Param3,
        real32_T varargin_1_params_Param4, real32_T varargin_1_params_Param5,
        real32_T varargin_1_params_Param6, real32_T varargin_1_params_Param7,
        const Location varargin_1_StartPosition, int32_T varargin_1_numUAV,
        int32_T varargin_1_FormationPos, real_T varargin_1_StartTime, int32_T
        varargin_2_SequenceId, MissionModes varargin_2_MissionMode, const
        Location varargin_2_MissionLocation, const Parameters varargin_2_params,
        const Location varargin_2_StartPosition, int32_T varargin_2_numUAV,
        int32_T varargin_2_FormationPos, real_T varargin_2_StartTime);
    int32_T codegenReal2Mission_RcvImmedCMD_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data);
    void codegenReal2Mission_initMemPool(MemPool_missionCmd *memPool, missionCmd
        *memArray, missionCmd **freeList, int32_T size);

    // Continuous states update member function
    void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

    // Derivatives member function
    void codegenReal2Mission_derivatives();
};

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
//  '<S1>'   : 'codegenReal2Mission/FeedbackCurrentMission'
//  '<S2>'   : 'codegenReal2Mission/FlightMission'
//  '<S3>'   : 'codegenReal2Mission/ImmedMission'
//  '<S4>'   : 'codegenReal2Mission/InitializeSimLocation'
//  '<S5>'   : 'codegenReal2Mission/MissionSwitch'
//  '<S6>'   : 'codegenReal2Mission/MissionValidation'
//  '<S7>'   : 'codegenReal2Mission/OnboardTaskStatusEncoder'
//  '<S8>'   : 'codegenReal2Mission/getCurrentTime'
//  '<S9>'   : 'codegenReal2Mission/FeedbackCurrentMission/TriggerCurrentMisisonFeedback'
//  '<S10>'  : 'codegenReal2Mission/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/PrintOnboardLog'
//  '<S11>'  : 'codegenReal2Mission/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/TimeConverter'
//  '<S12>'  : 'codegenReal2Mission/FlightMission/Compare To Constant'
//  '<S13>'  : 'codegenReal2Mission/FlightMission/Compare To Zero (ID)'
//  '<S14>'  : 'codegenReal2Mission/FlightMission/FeedbackMissionCMD'
//  '<S15>'  : 'codegenReal2Mission/FlightMission/MisisonCMDTemporalLogic'
//  '<S16>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV'
//  '<S17>'  : 'codegenReal2Mission/FlightMission/SailDistance'
//  '<S18>'  : 'codegenReal2Mission/FlightMission/SimState2Pose'
//  '<S19>'  : 'codegenReal2Mission/FlightMission/TriggerBroadcastAtMissionTime'
//  '<S20>'  : 'codegenReal2Mission/FlightMission/TriggerStartSim'
//  '<S21>'  : 'codegenReal2Mission/FlightMission/SailDistance/EnableSailShift'
//  '<S22>'  : 'codegenReal2Mission/FlightMission/SailDistance/SailShift'
//  '<S23>'  : 'codegenReal2Mission/FlightMission/SailDistance/SailShift/Degrees to Radians'
//  '<S24>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance'
//  '<S25>'  : 'codegenReal2Mission/ImmedMission/RealState2Pose'
//  '<S26>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode997_FlightMissionRH'
//  '<S27>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance'
//  '<S28>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp'
//  '<S29>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/ModeNull'
//  '<S30>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/PreemptableMissionModeSelector'
//  '<S31>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode997_FlightMissionRH/Degrees to Radians'
//  '<S32>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode997_FlightMissionRH/NewAltShift'
//  '<S33>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode997_FlightMissionRH/OldAltShift'
//  '<S34>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode997_FlightMissionRH/RegionalScanMode'
//  '<S35>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/Calculate Range'
//  '<S36>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/Compare To Zero'
//  '<S37>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/GenerateTrack'
//  '<S38>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/HeadingControl'
//  '<S39>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth'
//  '<S40>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage'
//  '<S41>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/GenerateTrack/Long Track'
//  '<S42>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/GenerateTrack/TrackGenerator'
//  '<S43>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/GenerateTrack/TrackSwitch'
//  '<S44>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap'
//  '<S45>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap LL0'
//  '<S46>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/Subsystem'
//  '<S47>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/pos_rad'
//  '<S48>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S49>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S50>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S51>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S52>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S53>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S54>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S55>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S56>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S57>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S58>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S59>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S60>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S61>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S62>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S63>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S64>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S65>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S66>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/AngdiffAzimuth'
//  '<S67>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/AngdiffElevation'
//  '<S68>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/GenAzimuthElevation'
//  '<S69>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/GenQuaternionIn'
//  '<S70>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/GenQuaternionOut'
//  '<S71>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/MagnitudeOrigVec'
//  '<S72>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/MagnitudePerpVec'
//  '<S73>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/MagnitudeProjVec'
//  '<S74>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/Projection'
//  '<S75>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/GenAzimuthElevation/Magnitude'
//  '<S76>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/GenQuaternionIn/Magnitude'
//  '<S77>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode998_CollAvoidance/LinearSecantPercentage/GenQuaternionOut/Magnitude'
//  '<S78>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/Calculate Range'
//  '<S79>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/Degrees to Radians'
//  '<S80>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/FeedthroughHDG'
//  '<S81>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/HdgHoldLogic'
//  '<S82>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth'
//  '<S83>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/Turning'
//  '<S84>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap'
//  '<S85>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap LL0'
//  '<S86>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/Subsystem'
//  '<S87>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/pos_rad'
//  '<S88>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S89>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S90>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S91>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S92>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S93>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S94>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S95>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S96>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S97>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S98>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S99>'  : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S100>' : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S101>' : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S102>' : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S103>' : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S104>' : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S105>' : 'codegenReal2Mission/ImmedMission/ImmedMissionGuidance/Mode999_DetailedInsp/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S106>' : 'codegenReal2Mission/MissionValidation/CommandCheck'
//  '<S107>' : 'codegenReal2Mission/MissionValidation/ImmedCMD'
//  '<S108>' : 'codegenReal2Mission/MissionValidation/PushCMD'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
