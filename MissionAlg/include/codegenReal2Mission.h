//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.310
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Apr 20 11:34:51 2021
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
#include "SendData_IndividualUAVCmdT.h"
#include "RecvData_IndividualUAVCmdT.h"
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "uavdubinscodegen_connection_api.hpp"
#include "codegenReal2Mission_types.h"

// Shared type includes
#include "multiword_types.h"
#include "model_reference_types.h"

// Child system includes
#include "Real2SimGuidance.h"
#include "MissionUAV.h"

// Includes for objects with custom storage classes.
#include "GCS_Location.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"

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
  real_T *y;                           // output
  real_T *f[4];                        // derivatives
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

// Class declaration for model codegenReal2Mission
class codegenReal2MissionModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_codegenReal2Mission_T {
    real_T nedWayPoint[30720];         // '<S122>/biasNED'
    real_T nedWayPoint_a[30720];       // '<S71>/biasNED'
    real_T WayPoint[30720];            // '<S122>/WayPointGenerator'
    real_T RotateIndivWayPoint[30720]; // '<S122>/RotateIndivWayPoint'
    real_T rtb_WayPoint_m[30720];
    real_T paddedWaypts[30720];
    real_T paddedWaypts_c[30720];
    boolean_T x[30720];
    boolean_T x_k[30720];
    int16_T c_data[10240];
    int16_T c_data_c[10240];
    boolean_T b[10240];
    boolean_T b_b[10240];
    real_T mt_data[784];
    real_T b_fpa_data[784];
    real_T b_a_data[784];
    real_T mtr_data[784];
    real_T h_data[784];
    real_T mt_data_p[784];
    real_T b_fpa_data_c[784];
    real_T b_a_data_f[784];
    real_T mtr_data_g[784];
    real_T h_data_g[784];
    emxArray_uavDubinsPathSegment_2_codegenReal2Mission_T pathSegObj;
    emxArray_uavDubinsPathSegment_2_codegenReal2Mission_T pathSegObj_m;
    IndividualUAVCmd ReceivePushedMissionCMD;// '<S3>/ReceivePushedMissionCMD'
    missionCmd ReceiveNextMission;     // '<Root>/ReceiveNextMission'
    missionCmd ReceiveCurrentMission_o2;// '<S2>/ReceiveCurrentMission'
    missionCmd MemoryCurrentMission;   // '<S2>/MemoryCurrentMission'
    missionCmd ReceiveThisMission_o2;  // '<S1>/ReceiveThisMission'
    FixedWingGuidanceBus GuidanceCmds; // '<S2>/PreemptableMissionModeSelector'
    real_T ExecutionTrigger;           // '<Root>/Real2SimGuidance'
    real_T thisTaskStatus;             // '<S2>/PreemptableMissionModeSelector'
    real_T InitialState[8];            // '<S2>/PreemptableMissionModeSelector'
    real_T ResetTrigger;               // '<S2>/PreemptableMissionModeSelector'
    real_T North;                      // '<S13>/MissionUavModel'
    real_T East;                       // '<S13>/MissionUavModel'
    real_T Height;                     // '<S13>/MissionUavModel'
    real_T AirSpeed;                   // '<S13>/MissionUavModel'
    real_T HeadingAngle;               // '<S13>/MissionUavModel'
    real_T FlightPathAngle;            // '<S13>/MissionUavModel'
    real_T RollAngle;                  // '<S13>/MissionUavModel'
    real_T RollAngleRate;              // '<S13>/MissionUavModel'
    real_T TriggerSend;                // '<S2>/MisisonCMDTemporalLogic'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_codegenReal2Mission_T {
    uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T obj;// '<S21>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T obj_i;// '<S20>/Waypoint Follower' 
    uav_sluav_internal_system_OrbitFollower_codegenReal2Mission_T obj_a;// '<S19>/Orbit Follower' 
    uav_sluav_internal_system_OrbitFollower_codegenReal2Mission_T obj_n;// '<S18>/Orbit Follower' 
    missionCmd slMsgMgr_memArray_missionCmd[6];// synthesized block
    missionCmd MemoryCurrentMission_PreviousInput;// '<S2>/MemoryCurrentMission' 
    missionCmd missionCmd_k;           // '<S3>/DataStoreMissionCmd'
    Location MemoryPrevMissionLocation_PreviousInput;// '<S2>/MemoryPrevMissionLocation' 
    real_T DelayPose_PreviousInput[4]; // '<S2>/DelayPose'
    volatile real_T NonDeterministic_Buffer0;// '<Root>/NonDeterministic'
    real_T Clock;                      // '<Root>/DataStoreClock'
    real_T MemoryPrevRelPos_PreviousInput[3];// '<S21>/MemoryPrevRelPos'
    real_T MemoryTriggerWP_PreviousInput;// '<S21>/MemoryTriggerWP'
    real_T RotateRelPrevPos_DWORK4[9]; // '<S122>/RotateRelPrevPos'
    real_T MemoryPrevRelPos_PreviousInput_d[3];// '<S20>/MemoryPrevRelPos'
    real_T MemoryTriggerWP_PreviousInput_k;// '<S20>/MemoryTriggerWP'
    real_T RotateRelPrevPos_DWORK4_i[9];// '<S71>/RotateRelPrevPos'
    Buffer_missionCmd Queue_InsertedFor_ReceiveNextMission_at_inport_0_Queue;// synthesized block 
    Buffer_missionCmd Queue_InsertedFor_ReceiveCurrentMission_at_inport_0_Queue;// synthesized block 
    Buffer_missionCmd Queue_InsertedFor_FeedbackCurrentMission_at_inport_0_Queue;// synthesized block 
    MemPool_missionCmd slMsgMgr_MemPool_missionCmd;// synthesized block
    missionCmd* slMsgMgr_freeList_missionCmd[6];// synthesized block
    int32_T SequenceID_start;          // '<S2>/PreemptableMissionModeSelector'
    uint8_T is_active_c24_codegenReal2Mission;// '<S2>/TriggerStartSim'
    uint8_T is_c24_codegenReal2Mission;// '<S2>/TriggerStartSim'
    uint8_T is_active_c23_codegenReal2Mission;// '<S2>/PreemptableMissionModeSelector' 
    uint8_T is_GuidanceLogic;          // '<S2>/PreemptableMissionModeSelector'
    uint8_T is_OrbitFollower;          // '<S2>/PreemptableMissionModeSelector'
    uint8_T is_WaypointFollower;       // '<S2>/PreemptableMissionModeSelector'
    uint8_T is_active_c20_codegenReal2Mission;// '<S2>/MisisonCMDTemporalLogic'
    uint8_T is_c20_codegenReal2Mission;// '<S2>/MisisonCMDTemporalLogic'
    boolean_T MissionSimUAV_MODE;      // '<S2>/MissionSimUAV'
    MdlrefDW_Real2SimGuidance_T Real2SimGuidance_InstanceData;// '<Root>/Real2SimGuidance' 
    MdlrefDW_MissionUAV_T MissionUavModel_InstanceData;// '<S13>/MissionUavModel' 
  };

  // Continuous states (default storage)
  struct X_codegenReal2Mission_T {
    X_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<Root>/Real2SimGuidance'
    X_MissionUAV_n_T MissionUavModel_CSTATE;// '<S13>/MissionUavModel'
  };

  // State derivatives (default storage)
  struct XDot_codegenReal2Mission_T {
    XDot_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<Root>/Real2SimGuidance' 
    XDot_MissionUAV_n_T MissionUavModel_CSTATE;// '<S13>/MissionUavModel'
  };

  // State disabled
  struct XDis_codegenReal2Mission_T {
    XDis_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<Root>/Real2SimGuidance' 
    XDis_MissionUAV_n_T MissionUavModel_CSTATE;// '<S13>/MissionUavModel'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX_codegenReal2Mission_T {
    ZCSigState TriggerBroadcastAtMissionTime_Trig_ZCE;// '<S2>/TriggerBroadcastAtMissionTime' 
    ZCSigState WayPointGenerator_Trig_ZCE;// '<S21>/WayPointGenerator'
    ZCSigState WayPointGenerator_Trig_ZCE_b;// '<S20>/WayPointGenerator'
    ZCSigState FeedbackMissionCMD_Trig_ZCE;// '<S2>/FeedbackMissionCMD'
    ZCSigState TriggerCurrentMisisonFeedback_Trig_ZCE;// '<S1>/TriggerCurrentMisisonFeedback' 
  };

  // Invariant block signals (default storage)
  struct ConstB_codegenReal2Mission_T {
    real_T Sum;                        // '<S143>/Sum'
    real_T Product1;                   // '<S144>/Product1'
    real_T Sum1;                       // '<S144>/Sum1'
    real_T sqrt_m;                     // '<S144>/sqrt'
    real_T Product2;                   // '<S140>/Product2'
    real_T Sum1_m;                     // '<S140>/Sum1'
    real_T Sum_m;                      // '<S165>/Sum'
    real_T Product1_m;                 // '<S166>/Product1'
    real_T Sum1_l;                     // '<S166>/Sum1'
    real_T sqrt_c;                     // '<S166>/sqrt'
    real_T Product2_p;                 // '<S162>/Product2'
    real_T Sum1_c;                     // '<S162>/Sum1'
    real_T Sum_e;                      // '<S92>/Sum'
    real_T Product1_n;                 // '<S93>/Product1'
    real_T Sum1_f;                     // '<S93>/Sum1'
    real_T sqrt_cy;                    // '<S93>/sqrt'
    real_T Product2_e;                 // '<S89>/Product2'
    real_T Sum1_e;                     // '<S89>/Sum1'
    real_T Sum_l;                      // '<S114>/Sum'
    real_T Product1_o;                 // '<S115>/Product1'
    real_T Sum1_fj;                    // '<S115>/Sum1'
    real_T sqrt_cp;                    // '<S115>/sqrt'
    real_T Product2_i;                 // '<S111>/Product2'
    real_T Sum1_h;                     // '<S111>/Sum1'
    real_T Sum_k;                      // '<S66>/Sum'
    real_T Product1_i;                 // '<S67>/Product1'
    real_T Sum1_k;                     // '<S67>/Sum1'
    real_T sqrt_g;                     // '<S67>/sqrt'
    real_T Product2_k;                 // '<S63>/Product2'
    real_T Sum1_fi;                    // '<S63>/Sum1'
    real_T Sum_l4;                     // '<S43>/Sum'
    real_T Product1_a;                 // '<S44>/Product1'
    real_T Sum1_mm;                    // '<S44>/Sum1'
    real_T sqrt_mc;                    // '<S44>/sqrt'
    real_T Product2_im;                // '<S40>/Product2'
    real_T Sum1_a;                     // '<S40>/Sum1'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_codegenReal2Mission_T {
    RealUAVStateBus RealUAVLatLonState;// '<Root>/RealUAVLatLonState'
    uint8_T FlightMode;                // '<Root>/FlightMode'
    real_T GroundSpeed;                // '<Root>/GroundSpeed'
    VectorSpeed VectorSpd;             // '<Root>/VectorSpd'
    real_T Altitude;                   // '<Root>/Altitude'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_codegenReal2Mission_T {
    real_T RefAirspeed;                // '<Root>/RefAirspeed'
    LookAheadPoint LookAheadPoint_i;   // '<Root>/LookAheadPoint'
    boolean_T EngagedFlag;             // '<Root>/EngagedFlag'
    real_T thisTaskStatus;             // '<Root>/thisTaskStatus'
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
      time_T stepSize0;
      uint32_T clockTick1;
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
  // Block signals
  B_codegenReal2Mission_T codegenReal2Mission_B;

  // Block states
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
  boolean_T codegenReal2Mission_pop(Buffer_missionCmd *q, Msg_missionCmd
    *elementOut);
  void codegenReal2Mission_freeMemPool(MemPool_missionCmd *memPool, missionCmd
    *dataPtr);
  void codegenReal2Mission_destroyMsg(Msg_missionCmd *msg);
  int32_T codegenReal2Mission_ReceiveNextMission_RecvData(missionCmd *data);
  void codegenReal2Mission_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
    real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
    real_T *t_tm_year, boolean_T *t_tm_isdst);
  creal_T codegenReal2Mission_two_sum(real_T a, real_T b);
  creal_T codegenReal2Mission_plus(const creal_T a, real_T b);
  missionCmd *codegenReal2Mission_allocMemPool(MemPool_missionCmd *memPool,
    int32_T width);
  Msg_missionCmd codegenReal2Mission_createMsg(const missionCmd *data);
  boolean_T codegenReal2Mission_push(Buffer_missionCmd *q, Msg_missionCmd
    *element);
  int32_T codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd
    *data);
  int32_T codegenReal2Mission_ReceiveCurrentMission_RecvData(missionCmd *data);
  int32_T codegenReal2Mission_ReceiveThisMission_SendData(const missionCmd *data);
  void codegenReal2Mission_emxInit_real_T(emxArray_real_T_codegenReal2Mission_T **
    pEmxArray, int32_T numDimensions);
  void codegenReal2Mission_emxEnsureCapacity_real_T
    (emxArray_real_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
  matlabshared_autonomous_core_internal_NameValueParser_codegenReal2Mission_T
    *codegenReal2Mission_NameValueParser_NameValueParser
    (matlabshared_autonomous_core_internal_NameValueParser_codegenReal2Mission_T
     *obj);
  void codegenReal2Mission_validatestring(const char_T str[7], char_T out_data[],
    int32_T out_size[2]);
  boolean_T codegenReal2Mission_strcmp(const char_T a_data[], const int32_T
    a_size[2]);
  void codegenReal2Mission_merge(int32_T idx_data[], int32_T x_data[], int32_T
    offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T xwork_data[]);
  void codegenReal2Mission_sort(int32_T x_data[], const int32_T *x_size, int32_T
    idx_data[], int32_T *idx_size);
  void codegenReal2Mission_do_vectors(real_T c_data[], int32_T c_size[2],
    int32_T ia_data[], int32_T *ia_size, int32_T *ib_size);
  void codegenReal2Mission_do_vectors_j(const real_T b_data[], const int32_T
    *b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[], int32_T
    *ia_size, int32_T *ib_size);
  void codegenReal2Mission_merge_p(int32_T idx_data[], real_T x_data[], int32_T
    offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T xwork_data[]);
  void codegenReal2Mission_sortIdx(real_T x_data[], int32_T *x_size, int32_T
    idx_data[], int32_T *idx_size);
  void codegenReal2Mission_sort_f(real_T x_data[], const int32_T *x_size);
  void codegenReal2Mission_uavDubinsConnection_findDisabledIndices(real_T
    idx_data[], int32_T *idx_size);
  void* codegenReal2Mission_uavDubinsBuildable_uavDubinsBuildable(real_T
    airSpeed, real_T maxRollAngle, const real_T flightPathAngle[2], const real_T
    disabledPathTypes_data[], const int32_T *disabledPathTypes_size);
  void codegenReal2Mission_emxFree_real_T(emxArray_real_T_codegenReal2Mission_T **
    pEmxArray);
  boolean_T codegenReal2Mission_strcmp_a(const char_T a_data[], const int32_T
    a_size[2]);
  boolean_T codegenReal2Mission_strcmp_ab(const char_T a_data[], const int32_T
    a_size[2]);
  void codegenReal2Mission_uavDubinsPathSegment_uavDubinsPathSegment_g(const
    real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
    varargin_4, real_T varargin_5, real_T varargin_6, const
    cell_wrap_10_codegenReal2Mission_T varargin_7[4], const real_T varargin_8[4],
    uavDubinsPathSegment_codegenReal2Mission_T *b_this);
  real_T codegenReal2Mission_sum(const real_T x_data[]);
  void codegenReal2Mission_uavDubinsBuiltins_connect(const
    uavDubinsConnection_codegenReal2Mission_T *obj, const real_T startPose[4],
    const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
    real_T dpt_data[], const int32_T *dpt_size,
    uavDubinsPathSegment_codegenReal2Mission_T pathSegObjs_data[], int32_T
    *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size);
  void codegenReal2Mission_uavDubinsConnection_connect(const
    uavDubinsConnection_codegenReal2Mission_T *obj, const real_T startPoses[4],
    const real_T goalPoses[4], uavDubinsPathSegment_codegenReal2Mission_T
    pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
    int32_T *pathCosts_size);
  void codegenReal2Mission_strcmp_abl(const cell_wrap_10_codegenReal2Mission_T
    a[4], boolean_T b_bool[4]);
  boolean_T codegenReal2Mission_any(const boolean_T x[4]);
  void codegenReal2Mission_useConstantDim(const real_T varargin_2_data[], const
    int32_T varargin_2_size[2], real_T varargout_1_data[], int32_T
    varargout_1_size[2]);
  void codegenReal2Mission_emxInit_int32_T
    (emxArray_int32_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions);
  void codegenReal2Mission_emxEnsureCapacity_int32_T
    (emxArray_int32_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
  void codegenReal2Mission_emxInit_real_T1(emxArray_real_T_codegenReal2Mission_T
    **pEmxArray, int32_T numDimensions);
  void codegenReal2Mission_emxEnsureCapacity_real_T1
    (emxArray_real_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
  void codegenReal2Mission_emxInit_int32_T1
    (emxArray_int32_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions);
  void codegenReal2Mission_emxEnsureCapacity_int32_T1
    (emxArray_int32_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
  void codegenReal2Mission_merge_pa(emxArray_int32_T_codegenReal2Mission_T *idx,
    emxArray_real_T_codegenReal2Mission_T *x, int32_T offset, int32_T np,
    int32_T nq, emxArray_int32_T_codegenReal2Mission_T *iwork,
    emxArray_real_T_codegenReal2Mission_T *xwork);
  void codegenReal2Mission_merge_block(emxArray_int32_T_codegenReal2Mission_T
    *idx, emxArray_real_T_codegenReal2Mission_T *x, int32_T offset, int32_T n,
    int32_T preSortLevel, emxArray_int32_T_codegenReal2Mission_T *iwork,
    emxArray_real_T_codegenReal2Mission_T *xwork);
  void codegenReal2Mission_emxFree_int32_T
    (emxArray_int32_T_codegenReal2Mission_T **pEmxArray);
  void codegenReal2Mission_sort_fn(emxArray_real_T_codegenReal2Mission_T *x);
  void codegenReal2Mission_emxInit_boolean_T
    (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions);
  void codegenReal2Mission_emxFree_boolean_T
    (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray);
  void codegenReal2Mission_emxInit_boolean_T1
    (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions);
  void codegenReal2Mission_emxEnsureCapacity_boolean_T1
    (emxArray_boolean_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
  void codegenReal2Mission_wrapToPi(emxArray_real_T_codegenReal2Mission_T *theta);
  void codegenReal2Mission_emxEnsureCapacity_boolean_T
    (emxArray_boolean_T_codegenReal2Mission_T *emxArray, int32_T oldNumel);
  void codegenReal2Mission_eml_find(const
    emxArray_boolean_T_codegenReal2Mission_T *x,
    emxArray_int32_T_codegenReal2Mission_T *i);
  boolean_T codegenReal2Mission_strcmp_abl2(const char_T a_data[], const int32_T
    a_size[2]);
  boolean_T codegenReal2Mission_strcmp_abl2t(const char_T a_data[], const
    int32_T a_size[2]);
  boolean_T codegenReal2Mission_strcmp_abl2tg(const char_T a_data[], const
    int32_T a_size[2]);
  boolean_T codegenReal2Mission_strcmp_abl2tgy(const char_T a_data[], const
    int32_T a_size[2]);
  boolean_T codegenReal2Mission_strcmp_abl2tgyf(const char_T a_data[], const
    int32_T a_size[2]);
  boolean_T codegenReal2Mission_strcmp_abl2tgyfr(const char_T a_data[], const
    int32_T a_size[2]);
  void codegenReal2Mission_mtimes(const emxArray_real_T_codegenReal2Mission_T *A,
    const real_T B[4], emxArray_real_T_codegenReal2Mission_T *C);
  void codegenReal2Mission_uavDubinsPathSegment_interpolate(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_10_codegenReal2Mission_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length,
    emxArray_real_T_codegenReal2Mission_T *samples,
    emxArray_real_T_codegenReal2Mission_T *poses);
  void codegenReal2Mission_genSegWP(const
    uavDubinsConnection_codegenReal2Mission_T *connectionObj, const real_T
    start[4], const real_T ende[4], real_T b_stepSize,
    emxArray_real_T_codegenReal2Mission_T *segWayPoints);
  void codegenReal2Mission_repmat(const emxArray_real_T_codegenReal2Mission_T *a,
    real_T varargin_1, emxArray_real_T_codegenReal2Mission_T *b);
  void codegenReal2Mission_WaypointFollowerBase_getDistinctWpts(const real_T
    waypoints[30720], emxArray_real_T_codegenReal2Mission_T *distinctWpts);
  real_T codegenReal2Mission_norm_b(const real_T x[3]);
  void codegenReal2Mission_WaypointFollowerBase_createWaypoint
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     real_T virtualWaypoint[3]);
  void codegenReal2Mission_WaypointFollowerBase_getWaypoints
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     const emxArray_real_T_codegenReal2Mission_T *waypoints, real_T
     startWaypoint[3], real_T endWaypoint[3]);
  void codegenReal2Mission_WaypointFollowerBase_endWaypointReached_br
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     const emxArray_real_T_codegenReal2Mission_T *waypoints, real_T
     curStartWaypoint[3], real_T curEndWaypoint[3], const real_T currentPose[4]);
  real_T codegenReal2Mission_WaypointFollowerBase_pointToLine(const real_T p1[3],
    const real_T p2[3], const real_T p[3]);
  real_T codegenReal2Mission_WaypointFollowerBase_projectToLine(const real_T
    startWaypoint[3], const real_T endWaypoint[3], const real_T currentPosition
    [3]);
  void codegenReal2Mission_WaypointFollowerBase_getLookahead(const
    uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj, const
    real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
    currentPosition[3], real_T lookaheadPoint[3]);
  void codegenReal2Mission_WaypointFollowerBase_stepInternal
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     const real_T currentPose[4], const real_T waypointsIn[30720], real_T
     lookaheadDist, real_T lookaheadPoint[3], real_T *desiredHeading, real_T
     *desiredYaw, uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T
     *status);
  real_T codegenReal2Mission_norm(const real_T x[2]);
  real_T codegenReal2Mission_angdiff(real_T x, real_T y);
  void codegenReal2Mission_exit_internal_GuidanceLogic(void);
  creal_T codegenReal2Mission_two_prod(real_T a);
  creal_T codegenReal2Mission_times(const creal_T a);
  creal_T codegenReal2Mission_two_diff(real_T a, real_T b);
  creal_T codegenReal2Mission_minus(const creal_T a, const creal_T b);
  int32_T codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data);
  boolean_T codegenReal2Mission_isequaln(int32_T varargin_1_SequenceId, int32_T
    varargin_1_MissionMode, real_T varargin_1_MissionLocation_Lat, real_T
    varargin_1_MissionLocation_Lon, real_T varargin_1_MissionLocation_Alt,
    real_T varargin_1_MissionLocation_degHDG, real32_T varargin_1_params_Param1,
    real32_T varargin_1_params_Param2, real32_T varargin_1_params_Param3,
    real32_T varargin_1_params_Param4, real32_T varargin_1_params_Param5,
    real32_T varargin_1_params_Param6, real32_T varargin_1_params_Param7, const
    Location varargin_1_StartPosition, int32_T varargin_1_numUAV, int32_T
    varargin_1_FormationPos, real_T varargin_1_StartTime, int32_T
    varargin_2_SequenceId, int32_T varargin_2_MissionMode, const Location
    varargin_2_MissionLocation, const Parameters varargin_2_params, const
    Location varargin_2_StartPosition, int32_T varargin_2_numUAV, int32_T
    varargin_2_FormationPos, real_T varargin_2_StartTime);
  int32_T codegenReal2Mission_ReceiveNextMission_SendData(const missionCmd *data);
  void codegenReal2Mission_initMemPool(MemPool_missionCmd *memPool, missionCmd
    *memArray, missionCmd **freeList, int32_T size);

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void codegenReal2Mission_derivatives();
};

extern const codegenReal2MissionModelClass::ConstB_codegenReal2Mission_T
  codegenReal2Mission_ConstB;          // constant block i/o

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S18>/Right' : Unused code path elimination
//  Block '<S18>/Front' : Eliminate redundant signal conversion block
//  Block '<S18>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S18>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S18>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S18>/Up' : Eliminate redundant signal conversion block
//  Block '<S19>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S19>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S19>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S20>/Front' : Eliminate redundant signal conversion block
//  Block '<S20>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S20>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S20>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S20>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S20>/Right' : Eliminate redundant signal conversion block
//  Block '<S20>/Up' : Eliminate redundant signal conversion block
//  Block '<S71>/Reshape' : Reshape block reduction
//  Block '<S21>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S21>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S21>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S21>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S122>/Reshape' : Reshape block reduction


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
//  '<S3>'   : 'codegenReal2Mission/MissionValidation'
//  '<S4>'   : 'codegenReal2Mission/VisualizeMissionUAV'
//  '<S5>'   : 'codegenReal2Mission/getCurrentTime'
//  '<S6>'   : 'codegenReal2Mission/FeedbackCurrentMission/TriggerCurrentMisisonFeedback'
//  '<S7>'   : 'codegenReal2Mission/FeedbackCurrentMission/getCurrentTime'
//  '<S8>'   : 'codegenReal2Mission/FlightMission/Compare To Zero (ID)'
//  '<S9>'   : 'codegenReal2Mission/FlightMission/Compare To Zero (Mode)'
//  '<S10>'  : 'codegenReal2Mission/FlightMission/FeedbackMissionCMD'
//  '<S11>'  : 'codegenReal2Mission/FlightMission/InitializeSimLocation'
//  '<S12>'  : 'codegenReal2Mission/FlightMission/MisisonCMDTemporalLogic'
//  '<S13>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV'
//  '<S14>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector'
//  '<S15>'  : 'codegenReal2Mission/FlightMission/SimState2Pose'
//  '<S16>'  : 'codegenReal2Mission/FlightMission/TriggerBroadcastAtMissionTime'
//  '<S17>'  : 'codegenReal2Mission/FlightMission/TriggerStartSim'
//  '<S18>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav'
//  '<S19>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav'
//  '<S20>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav'
//  '<S21>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav'
//  '<S22>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth'
//  '<S23>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap'
//  '<S24>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S25>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem'
//  '<S26>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/pos_rad'
//  '<S27>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S28>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S29>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S30>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S31>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S32>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S33>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S34>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S35>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S36>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S37>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S38>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S39>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S40>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S41>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S42>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S43>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S44>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S45>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth'
//  '<S46>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap'
//  '<S47>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S48>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem'
//  '<S49>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/pos_rad'
//  '<S50>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S51>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S52>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S53>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S54>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S55>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S56>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S57>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S58>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S59>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S60>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S61>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S62>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S63>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S64>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S65>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S66>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S67>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S68>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Degrees to Radians'
//  '<S69>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth'
//  '<S70>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth'
//  '<S71>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/WayPointGenerator'
//  '<S72>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap'
//  '<S73>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S74>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem'
//  '<S75>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/pos_rad'
//  '<S76>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S77>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S78>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S79>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S80>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S81>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S82>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S83>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S84>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S85>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S86>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S87>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S88>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S89>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S90>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S91>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S92>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S93>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S94>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap'
//  '<S95>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S96>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem'
//  '<S97>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/pos_rad'
//  '<S98>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S99>'  : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S100>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S101>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S102>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S103>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S104>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S105>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S106>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S107>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S108>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S109>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S110>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S111>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S112>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S113>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S114>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S115>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S116>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/WayPointGenerator/WayPointGenerator'
//  '<S117>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/WayPointGenerator/biasNED'
//  '<S118>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/WayPointGenerator/biasWayPoint'
//  '<S119>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Degrees to Radians'
//  '<S120>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth'
//  '<S121>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth'
//  '<S122>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/WayPointGenerator'
//  '<S123>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap'
//  '<S124>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S125>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem'
//  '<S126>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/pos_rad'
//  '<S127>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S128>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S129>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S130>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S131>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S132>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S133>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S134>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S135>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S136>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S137>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S138>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S139>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S140>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S141>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S142>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S143>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S144>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S145>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap'
//  '<S146>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S147>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem'
//  '<S148>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/pos_rad'
//  '<S149>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S150>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S151>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S152>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S153>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S154>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S155>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S156>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S157>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S158>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S159>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S160>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S161>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S162>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S163>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S164>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S165>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S166>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S167>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/WayPointGenerator/WayPointGenerator'
//  '<S168>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/WayPointGenerator/biasNED'
//  '<S169>' : 'codegenReal2Mission/FlightMission/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/WayPointGenerator/biasWayPoint'
//  '<S170>' : 'codegenReal2Mission/MissionValidation/CommandCheck'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
