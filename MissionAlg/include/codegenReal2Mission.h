//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.409
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu May  6 18:31:00 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
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
#include <cfloat>
#include <cstring>
#include <stddef.h>
#include "SendData_IndividualUAVCmdT.h"
#include "RecvData_IndividualUAVCmdT.h"
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
#include "PreemptableMissionModeSelector.h"
#include "Real2SimGuidance.h"
#include "MissionUAV.h"

// Includes for objects with custom storage classes.
#include "GCS_Location.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"

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
    IndividualUAVCmd ReceivePushedMissionCMD;// '<S3>/ReceivePushedMissionCMD'
    missionCmd ReceiveNextMission;     // '<Root>/ReceiveNextMission'
    missionCmd ReceiveCurrentMission_o2;// '<S2>/ReceiveCurrentMission'
    missionCmd MemoryCurrentMission;   // '<S2>/MemoryCurrentMission'
    missionCmd ReceiveThisMission_o2;  // '<S1>/ReceiveThisMission'
    Location MemoryPrevMissionLocation;// '<S2>/MemoryPrevMissionLocation'
    FixedWingGuidanceBus PreemptableMissionModeSelector_o2;// '<S2>/PreemptableMissionModeSelector' 
    real_T DelayPose[4];               // '<S2>/DelayPose'
    real_T PreemptableMissionModeSelector_o3;// '<S2>/PreemptableMissionModeSelector' 
    real_T PreemptableMissionModeSelector_o4[8];// '<S2>/PreemptableMissionModeSelector' 
    real_T PreemptableMissionModeSelector_o5[2];// '<S2>/PreemptableMissionModeSelector' 
    real_T SumEast;                    // '<S2>/SumEast'
    real_T SumNorth;                   // '<S2>/SumNorth'
    real_T ExecutionTrigger;           // '<Root>/Real2SimGuidance'
    real_T North;                      // '<S13>/MissionUavModel'
    real_T East;                       // '<S13>/MissionUavModel'
    real_T Height;                     // '<S13>/MissionUavModel'
    real_T AirSpeed;                   // '<S13>/MissionUavModel'
    real_T HeadingAngle;               // '<S13>/MissionUavModel'
    real_T FlightPathAngle;            // '<S13>/MissionUavModel'
    real_T RollAngle;                  // '<S13>/MissionUavModel'
    real_T RollAngleRate;              // '<S13>/MissionUavModel'
    real_T TriggerSend;                // '<S2>/MisisonCMDTemporalLogic'
    boolean_T StartSim;                // '<S2>/TriggerStartSim'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_codegenReal2Mission_T {
    missionCmd slMsgMgr_memArray_missionCmd[6];// synthesized block
    missionCmd MemoryCurrentMission_PreviousInput;// '<S2>/MemoryCurrentMission' 
    missionCmd missionCmd_k;           // '<S3>/DataStoreMissionCmd'
    Location MemoryPrevMissionLocation_PreviousInput;// '<S2>/MemoryPrevMissionLocation' 
    real_T DelayPose_PreviousInput[4]; // '<S2>/DelayPose'
    volatile real_T NonDeterministic_Buffer0;// '<Root>/NonDeterministic'
    real_T Clock;                      // '<Root>/DataStoreClock'
    Buffer_missionCmd Queue_InsertedFor_ReceiveNextMission_at_inport_0_Queue;// synthesized block 
    Buffer_missionCmd Queue_InsertedFor_ReceiveCurrentMission_at_inport_0_Queue;// synthesized block 
    Buffer_missionCmd Queue_InsertedFor_FeedbackCurrentMission_at_inport_0_Queue;// synthesized block 
    MemPool_missionCmd slMsgMgr_MemPool_missionCmd;// synthesized block
    missionCmd* slMsgMgr_freeList_missionCmd[6];// synthesized block
    uint8_T is_active_c24_codegenReal2Mission;// '<S2>/TriggerStartSim'
    uint8_T is_c24_codegenReal2Mission;// '<S2>/TriggerStartSim'
    uint8_T is_active_c20_codegenReal2Mission;// '<S2>/MisisonCMDTemporalLogic'
    uint8_T is_c20_codegenReal2Mission;// '<S2>/MisisonCMDTemporalLogic'
    boolean_T MissionSimUAV_MODE;      // '<S2>/MissionSimUAV'
    MdlrefDW_PreemptableMissionModeSelector_T
      PreemptableMissionModeSelector_InstanceData;// '<S2>/PreemptableMissionModeSelector' 
    MdlrefDW_Real2SimGuidance_T Real2SimGuidance_InstanceData;// '<Root>/Real2SimGuidance' 
    MdlrefDW_MissionUAV_T MissionUavModel_InstanceData;// '<S13>/MissionUavModel' 
  };

  // Continuous states (default storage)
  struct X_codegenReal2Mission_T {
    real_T Integrator_CSTATE[2];       // '<S2>/Integrator'
    X_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<Root>/Real2SimGuidance'
    X_MissionUAV_n_T MissionUavModel_CSTATE;// '<S13>/MissionUavModel'
  };

  // State derivatives (default storage)
  struct XDot_codegenReal2Mission_T {
    real_T Integrator_CSTATE[2];       // '<S2>/Integrator'
    XDot_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<Root>/Real2SimGuidance' 
    XDot_MissionUAV_n_T MissionUavModel_CSTATE;// '<S13>/MissionUavModel'
  };

  // State disabled
  struct XDis_codegenReal2Mission_T {
    boolean_T Integrator_CSTATE[2];    // '<S2>/Integrator'
    XDis_Real2SimGuidance_n_T Real2SimGuidance_CSTATE;// '<Root>/Real2SimGuidance' 
    XDis_MissionUAV_n_T MissionUavModel_CSTATE;// '<S13>/MissionUavModel'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX_codegenReal2Mission_T {
    ZCSigState Integrator_Reset_ZCE;   // '<S2>/Integrator'
    ZCSigState TriggerBroadcastAtMissionTime_Trig_ZCE;// '<S2>/TriggerBroadcastAtMissionTime' 
    ZCSigState FeedbackMissionCMD_Trig_ZCE;// '<S2>/FeedbackMissionCMD'
    ZCSigState TriggerCurrentMisisonFeedback_Trig_ZCE;// '<S1>/TriggerCurrentMisisonFeedback' 
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
    real_T odeY[19];
    real_T odeF[4][19];
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
  creal_T codegenReal2Mission_two_prod(real_T a);
  creal_T codegenReal2Mission_times(const creal_T a);
  creal_T codegenReal2Mission_two_diff(real_T a, real_T b);
  creal_T codegenReal2Mission_minus(const creal_T a, const creal_T b);
  int32_T codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data);
  creal_T codegenReal2Mission_createFromDateVec(const real_T inData[7]);
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
  void codegenReal2Mission_getDateVec(const creal_T dd, real_T *y, real_T *mo,
    real_T *d, real_T *h, real_T *m, real_T *s);
  int32_T codegenReal2Mission_ReceiveNextMission_SendData(const missionCmd *data);
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
//  '<S14>'  : 'codegenReal2Mission/FlightMission/SimState2Pose'
//  '<S15>'  : 'codegenReal2Mission/FlightMission/TriggerBroadcastAtMissionTime'
//  '<S16>'  : 'codegenReal2Mission/FlightMission/TriggerStartSim'
//  '<S17>'  : 'codegenReal2Mission/MissionValidation/CommandCheck'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
