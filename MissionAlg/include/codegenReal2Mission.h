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

#include "multiword_types.h"
#include "model_reference_types.h"

#include "Real2SimGuidance.h"
#include "FlightMissionMode.h"
#include "MissionUAV.h"

#include "GCS_Location.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"
#include "rtw_linux.h"

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

struct ODE4_IntgData {
    real_T *y;
    real_T *f[4];
};

#endif

extern const FixedWingGuidanceBus codegenReal2Mission_rtZFixedWingGuidanceBus;
extern real_T AltitudeGCS;
extern real_T LatitudeGCS;
extern real_T LongitudeGCS;
extern void* AltitudeGCS_m0;
extern void* LatitudeGCS_m0;
extern void* LongitudeGCS_m0;
class codegenReal2MissionModelClass {
  public:
    struct DW_codegenReal2Mission_T {
        MdlrefDW_FlightMissionMode_T PreemptableMissionModeSelector_InstanceData;
        MdlrefDW_MissionUAV_T MissionUavModel_InstanceData;
        MdlrefDW_Real2SimGuidance_T Real2SimGuidance_InstanceData;
        FILE * eml_openfiles[20];
        uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T obj;
        missionCmd slMsgMgr_memArray_missionCmd[9];
        missionCmd RateTransition_Buf[3];
        uav_sluav_internal_system_OrbitFollower_codegenReal2Mission_T obj_j;
        IndividualUAVCmd ReceivePushedMissionCMD;
        IndividualUAVCmd IndivCMD;
        missionCmd RcvNextMission_o2;
        missionCmd RcvImmedCMD_o2;
        missionCmd ReceiveThisMission_o2;
        missionCmd ReceiveCurrentMission_o2;
        missionCmd cmdFlightMission;
        missionCmd MissionCMD;
        FixedWingGuidanceStateBus
            BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1;
        FixedWingGuidanceStateBus RealUAVState;
        FixedWingGuidanceStateBus MemoryPose_PreviousInput;
        MemPool_missionCmd slMsgMgr_MemPool_missionCmd;
        FixedWingGuidanceBus MergeGuidanceCMD;
        FixedWingGuidanceBus PreemptableMissionModeSelector_o2;
        Buffer_missionCmd Queue_InsertedFor_RcvNextMission_at_inport_0_Queue;
        Buffer_missionCmd
            Queue_InsertedFor_FeedbackCurrentMission_at_inport_0_Queue;
        Buffer_missionCmd Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue;
        Buffer_missionCmd
            Queue_InsertedFor_ReceiveCurrentMission_at_inport_0_Queue;
        real_T Switch[3];
        real_T ProductTargetVec[3];
        real_T PreemptableMissionModeSelector_o3[8];
        real_T DiscreteTimeIntegrator[2];
        real_T NorthSequence_X[360];
        real_T EastSequence_X[360];
        real_T HeightSequence_X[360];
        real_T DiscreteTimeIntegrator_DSTATE[2];
        real_T MemoryPose_PreviousInput_h[4];
        real_T MatrixConcatenate[1083];
        real_T Track[2700];
        real_T paddedWaypts[2700];
        real_T waypoints_data[2703];
        real_T Real2SimGuidance_o3;
        real_T North;
        real_T East;
        real_T Height;
        real_T AirSpeed;
        real_T HeadingAngle;
        real_T FlightPathAngle;
        real_T RollAngle;
        real_T RollAngleRate;
        real_T TrackInvH;
        real_T OrbitNavHdg;
        real_T thisTaskStatus;
        real_T CastToDouble;
        real_T North_o;
        real_T East_k;
        real_T Height_f;
        real_T AirSpeed_a;
        real_T HeadingAngle_g;
        real_T FlightPathAngle_h;
        real_T RollAngle_b;
        real_T RollAngleRate_a;
        real_T TriggerSend;
        volatile real_T NonDeterministic_Buffer0;
        real_T MemoryPrevRange_PreviousInput;
        real_T NewRun;
        void* RateTransition_d0_SEMAPHORE;
        missionCmd* slMsgMgr_freeList_missionCmd[9];
        int32_T SFunction_DIMS2[2];
        int32_T CastToint32;
        MissionModes ImmedMissionModeSelectorMode;
        int8_T RateTransition_LstBufWR;
        int8_T RateTransition_RDBuf;
        int8_T SwitchCase_ActiveSubsystem;
        int8_T DiscreteTimeIntegrator_PrevResetState;
        uint8_T is_active_c26_codegenReal2Mission;
        uint8_T is_c26_codegenReal2Mission;
        uint8_T MemoryStatus_PreviousInput;
        uint8_T is_active_c10_codegenReal2Mission;
        uint8_T is_c10_codegenReal2Mission;
        uint8_T temporalCounter_i1;
        uint8_T is_active_c5_codegenReal2Mission;
        uint8_T is_c5_codegenReal2Mission;
        uint8_T temporalCounter_i1_i;
        uint8_T is_active_c25_codegenReal2Mission;
        uint8_T is_GuidanceLogic;
        uint8_T is_active_c24_codegenReal2Mission;
        uint8_T is_c24_codegenReal2Mission;
        uint8_T is_active_c4_codegenReal2Mission;
        uint8_T is_c4_codegenReal2Mission;
        uint8_T temporalCounter_i1_n;
        uint8_T is_active_c20_codegenReal2Mission;
        uint8_T is_c20_codegenReal2Mission;
        boolean_T MergeControlSwitch[2];
        boolean_T InDangerSequence_X[360];
        boolean_T eml_autoflush[20];
        boolean_T BooleanImmedMode;
        boolean_T endImmed;
        boolean_T RelationalOperator;
        boolean_T StartSim;
        boolean_T NewRun_not_empty;
        boolean_T SailShift_MODE;
        boolean_T MissionSimUAV_MODE;
    };

    struct X_codegenReal2Mission_T {
        X_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;
        X_MissionUAV_n_T MissionUavModel_CSTATE;
    };

    struct XDot_codegenReal2Mission_T {
        XDot_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;
        XDot_MissionUAV_n_T MissionUavModel_CSTATE;
    };

    struct XDis_codegenReal2Mission_T {
        XDis_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;
        XDis_MissionUAV_n_T MissionUavModel_CSTATE;
    };

    struct PrevZCX_codegenReal2Mission_T {
        ZCSigState TriggerBroadcastAtMissionTime_Trig_ZCE;
        ZCSigState FeedbackMissionCMD_Trig_ZCE;
        ZCSigState TriggerCurrentMisisonFeedback_Trig_ZCE;
    };

    struct ExtU_codegenReal2Mission_T {
        RealUAVStateBus RealUAVLatLonState;
        uint8_T FlightMode;
        real_T GroundSpeed;
        VectorSpeed VectorSpd;
        real_T Altitude;
    };

    struct ExtY_codegenReal2Mission_T {
        real_T RefAirspeed;
        LookAheadPoint LookAheadPoint_i;
        boolean_T EngagedFlag;
        TaskStatus thisTaskStatus;
    };

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
        struct {
            int_T numContStates;
            int_T numPeriodicContStates;
            int_T numSampTimes;
        } Sizes;

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

    void initialize();
    void codegenReal2Mission_PushNewMission();
    void step();
    void terminate();
    codegenReal2MissionModelClass(SendData_IndividualUAVCmdT&
        CurrentMissionSendData_arg,RecvData_IndividualUAVCmdT&
        MissionCMDRecvData_arg);
    ~codegenReal2MissionModelClass();
    void setExternalInputs(const ExtU_codegenReal2Mission_T
                           * pExtU_codegenReal2Mission_T)
    {
        codegenReal2Mission_U = *pExtU_codegenReal2Mission_T;
    }

    const codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T
        & getExternalOutputs() const
    {
        return codegenReal2Mission_Y;
    }

    codegenReal2MissionModelClass::RT_MODEL_codegenReal2Mission_T * getRTM();
  private:
    DW_codegenReal2Mission_T codegenReal2Mission_DW;
    SendData_IndividualUAVCmdT& CurrentMissionSendData;
    RecvData_IndividualUAVCmdT& MissionCMDRecvData;
    X_codegenReal2Mission_T codegenReal2Mission_X;
    PrevZCX_codegenReal2Mission_T codegenReal2Mission_PrevZCX;
    ExtU_codegenReal2Mission_T codegenReal2Mission_U;
    ExtY_codegenReal2Mission_T codegenReal2Mission_Y;
    RT_MODEL_codegenReal2Mission_T codegenReal2Mission_M;
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
    creal_T codegenReal2Mission_createFromDateVec(const real_T inData[7]);
    boolean_T codegenReal2Mission_isequaln_f(MissionModes varargin_1,
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
    int32_T codegenReal2Mission_RcvImmedCMD_SendData(const missionCmd *data);
    int32_T codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data);
    void codegenReal2Mission_initMemPool(MemPool_missionCmd *memPool, missionCmd
        *memArray, missionCmd **freeList, int32_T size);
    void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );
    void codegenReal2Mission_derivatives();
};

#endif

