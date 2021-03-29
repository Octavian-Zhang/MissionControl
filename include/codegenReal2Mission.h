//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.239
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 29 11:17:03 2021
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
#include <stddef.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <cfloat>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "codegenReal2Mission_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

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

// Class declaration for model codegenReal2Mission
class codegenReal2MissionModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_codegenReal2Mission_T {
    FixedWingGuidanceStateBus SimUAVStateZOH;// '<S4>/SimUAVStateZOH'
    FixedWingGuidanceEnvironmentBus FixedWingGuidanceEnvironmentB_g;
                                      // '<S4>/FixedWingGuidanceEnvironmentBus'
    real_T Down;                       // '<S1>/InvH2D'
    real_T CircleOscillation;          // '<S1>/CircleOscillation'
    real_T Down2Height;                // '<S1>/Down2Height'
    real_T NorthEastHeight[3];         // '<S2>/NED2NEU'
    real_T TD_Alt;                     // '<S18>/TD_Alt'
    real_T Sum[3];                     // '<S2>/Sum'
    real_T DataSwitch;                 // '<S2>/DataSwitch'
    real_T dotAltTD;                   // '<S18>/dotAltTD'
    real_T ExecutionTrigger;           // '<S2>/TriggerTermination'
    real_T fh;                         // '<S18>/fhan_Alt'
    real_T InverseY;                   // '<S16>/InverseY'
    real_T InverseR;                   // '<S16>/InverseR'
    real_T dotTD;                      // '<S77>/dotTD'
    real_T ESOdotdotsum;               // '<S75>/ESOdotdotsum'
    real_T ESOdotsum;                  // '<S75>/ESOdotsum'
    real_T Inverse;                    // '<S75>/Inverse'
    real_T fh_n;                       // '<S77>/fhan_AirSpdADRC'
    real_T TrackInvH;                  // '<S13>/TrackInvH'
    real_T TakeOffGathering_o2;        // '<S1>/TakeOffGathering'
    real_T Airspeed;                   // '<S4>/AirspeedSaturation'
    real_T ClimbRateLimiter;           // '<S4>/ClimbRateLimiter'
    real_T RollAngle;                  // '<S4>/RollAngleSaturation'
    real_T dotBankTD;                  // '<S9>/dotBankTD'
    real_T fh_n4;                      // '<S9>/fhan_Bank'
    real_T ComputeDerivative[8];       // '<S8>/ComputeDerivative'
    real_T Seletion;                   // '<S1>/ChartExecutionMode'
    boolean_T Terminate;               // '<S2>/TriggerTermination'
    boolean_T TakeOffTrigger;          // '<S2>/TASgreaterthan15for1Sec'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_codegenReal2Mission_T {
    uav_sluav_internal_system_Way_T obj;// '<S2>/TrackSimPath'
    uav_sluav_internal_system_Orb_T obj_m;// '<S1>/TakeOffGathering'
    robotics_core_internal_syst_b_T obj_a;// '<S8>/ComputeDerivative'
    real_T InitHdg_DSTATE;             // '<S1>/InitHdg'
    real_T EastSequence_X[72];         // '<S13>/EastSequence'
    real_T HeightSequence_X[72];       // '<S13>/HeightSequence'
    real_T NorthSequence_X[72];        // '<S13>/NorthSequence'
    real_T MemoryFlowerMode_PreviousInput;// '<S1>/MemoryFlowerMode'
    real_T MemoryLookAheadP_PreviousInput;// '<S1>/MemoryLookAheadP'
    real_T AltitudeGCS;                // '<Root>/AltitudeGCS'
    real_T LatitudeGCS;                // '<Root>/LatitudeGCS'
    real_T LongitudeGCS;               // '<Root>/LongitudeGCS'
    real_T numMissionUAV;              // '<Root>/numMissionUAV'
    real_T MemoryRefHeight_PreviousInput;// '<S2>/MemoryRefHeight'
    real_T DataCounter;                // '<S2>/TriggerTermination'
    real_T Count;                      // '<S2>/TASgreaterthan15for1Sec'
    real_T PrevY;                      // '<S4>/ClimbRateLimiter'
    struct {
      void *LoggedData[10];
    } ModelLogging_PWORK;              // '<S2>/ModelLogging'

    int32_T UAVidx;                    // '<Root>/UAVidx'
    uint8_T is_active_c4_codegenReal2Missio;// '<S2>/TriggerTermination'
    uint8_T is_c4_codegenReal2Mission; // '<S2>/TriggerTermination'
    uint8_T is_active_c1_codegenReal2Missio;// '<S2>/TASgreaterthan15for1Sec'
    uint8_T is_c1_codegenReal2Mission; // '<S2>/TASgreaterthan15for1Sec'
    uint8_T is_active_c10_codegenReal2Missi;// '<S1>/ChartExecutionMode'
    uint8_T is_c10_codegenReal2Mission;// '<S1>/ChartExecutionMode'
    boolean_T icLoad;                  // '<S1>/InitHdg'
  };

  // Continuous states (default storage)
  struct X_codegenReal2Mission_T {
    real_T TD_Alt_CSTATE;              // '<S18>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S18>/dotAltTD'
    real_T ESO_CSTATE;                 // '<S75>/ESO'
    real_T ESO_dot_CSTATE;             // '<S75>/ESO_dot'
    real_T ESO_dotdot_CSTATE;          // '<S75>/ESO_dotdot'
    real_T TD_AirSpdADRC_CSTATE;       // '<S77>/TD_AirSpdADRC'
    real_T dotTD_CSTATE;               // '<S77>/dotTD'
    real_T Integrator_CSTATE[8];       // '<S8>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S9>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S9>/dotBankTD'
  };

  // State derivatives (default storage)
  struct XDot_codegenReal2Mission_T {
    real_T TD_Alt_CSTATE;              // '<S18>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S18>/dotAltTD'
    real_T ESO_CSTATE;                 // '<S75>/ESO'
    real_T ESO_dot_CSTATE;             // '<S75>/ESO_dot'
    real_T ESO_dotdot_CSTATE;          // '<S75>/ESO_dotdot'
    real_T TD_AirSpdADRC_CSTATE;       // '<S77>/TD_AirSpdADRC'
    real_T dotTD_CSTATE;               // '<S77>/dotTD'
    real_T Integrator_CSTATE[8];       // '<S8>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S9>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S9>/dotBankTD'
  };

  // State disabled
  struct XDis_codegenReal2Mission_T {
    boolean_T TD_Alt_CSTATE;           // '<S18>/TD_Alt'
    boolean_T dotAltTD_CSTATE;         // '<S18>/dotAltTD'
    boolean_T ESO_CSTATE;              // '<S75>/ESO'
    boolean_T ESO_dot_CSTATE;          // '<S75>/ESO_dot'
    boolean_T ESO_dotdot_CSTATE;       // '<S75>/ESO_dotdot'
    boolean_T TD_AirSpdADRC_CSTATE;    // '<S77>/TD_AirSpdADRC'
    boolean_T dotTD_CSTATE;            // '<S77>/dotTD'
    boolean_T Integrator_CSTATE[8];    // '<S8>/Integrator'
    boolean_T TD_Bank_CSTATE;          // '<S9>/TD_Bank'
    boolean_T dotBankTD_CSTATE;        // '<S9>/dotBankTD'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX_codegenReal2Mission_T {
    ZCSigState ESO_Reset_ZCE;          // '<S75>/ESO'
    ZCSigState ESO_dot_Reset_ZCE;      // '<S75>/ESO_dot'
    ZCSigState ESO_dotdot_Reset_ZCE;   // '<S75>/ESO_dotdot'
    ZCSigState TD_AirSpdADRC_Reset_ZCE;// '<S77>/TD_AirSpdADRC'
    ZCSigState dotTD_Reset_ZCE;        // '<S77>/dotTD'
  };

  // Invariant block signals (default storage)
  struct ConstB_codegenReal2Mission_T {
    real_T Sum;                        // '<S68>/Sum'
    real_T Product1;                   // '<S69>/Product1'
    real_T Sum1;                       // '<S69>/Sum1'
    real_T sqrt_k;                     // '<S69>/sqrt'
    real_T Product2;                   // '<S64>/Product2'
    real_T Sum1_k;                     // '<S64>/Sum1'
    real_T UnitConversion;             // '<S65>/Unit Conversion'
    real_T SinCos_o1;                  // '<S50>/SinCos'
    real_T SinCos_o2;                  // '<S50>/SinCos'
    real_T UnitConversion_p;           // '<S41>/Unit Conversion'
    real_T Sum_c;                      // '<S45>/Sum'
    real_T Product1_e;                 // '<S46>/Product1'
    real_T Sum1_b;                     // '<S46>/Sum1'
    real_T sqrt_g;                     // '<S46>/sqrt'
    real_T Product2_o;                 // '<S42>/Product2'
    real_T Sum1_e;                     // '<S42>/Sum1'
    real_T SinCos_o1_h;                // '<S27>/SinCos'
    real_T SinCos_o2_c;                // '<S27>/SinCos'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_codegenReal2Mission_T {
    RealUAVStateBus RealUAVLatLonState;// '<Root>/RealUAVLatLonState'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_codegenReal2Mission_T {
    real_T RefAirspeed;                // '<Root>/RefAirspeed'
    LookAheadPoint LookAheadPoint_j;   // '<Root>/LookAheadPoint'
    boolean_T EngagedFlag;             // '<Root>/EngagedFlag'
  };

  // Parameters (default storage)
  struct P_codegenReal2Mission_T {
    real_T GCS_Altitude;               // Variable: GCS_Altitude
                                          //  Referenced by: '<S6>/AltitudeGCS'

    real_T GCS_Latitude;               // Variable: GCS_Latitude
                                          //  Referenced by: '<S6>/LatitudeGCS'

    real_T GCS_Longitude;              // Variable: GCS_Longitude
                                          //  Referenced by: '<S6>/LongitudeGCS'

    real_T numMissionUAV;              // Variable: numMissionUAV
                                          //  Referenced by: '<S6>/Number Of Mission UAV'

    int32_T UAVidx;                    // Variable: UAVidx
                                          //  Referenced by: '<S6>/UAVidx'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_codegenReal2Mission_T {
    const char_T *errorStatus;
    RTWLogInfo *rtwLogInfo;
    RTWSolverInfo solverInfo;
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
      time_T tFinal;
      SimTimeStep simTimeStep;
      boolean_T stopRequestedFlag;
      time_T *t;
      time_T tArray[3];
    } Timing;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  codegenReal2MissionModelClass();

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
  // Tunable parameters
  static P_codegenReal2Mission_T codegenReal2Mission_P;

  // Block signals
  B_codegenReal2Mission_T codegenReal2Mission_B;

  // Block states
  DW_codegenReal2Mission_T codegenReal2Mission_DW;
  X_codegenReal2Mission_T codegenReal2Mission_X;// Block continuous states
  PrevZCX_codegenReal2Mission_T codegenReal2Mission_PrevZCX;// Triggered events

  // External inputs
  ExtU_codegenReal2Mission_T codegenReal2Mission_U;

  // External outputs
  ExtY_codegenReal2Mission_T codegenReal2Mission_Y;

  // Real-Time Model
  RT_MODEL_codegenReal2Mission_T codegenReal2Mission_M;

  // private member function(s) for subsystem '<S9>/fhan_Bank'
  static void codegenReal2Mission_fhan_Bank(real_T rtu_u, real_T rtu_u_n, real_T
    rtu_u_f, real_T rtu_u_c, real_T *rty_fh);

  // private member function(s) for subsystem '<S75>/fal(e,0.25,h)'
  static void codegenReal2Mission_fale025h(real_T rtu_u, real_T rtu_u_g, real_T
    rtu_u_d, real_T *rty_y);

  // private member function(s) for subsystem '<Root>'
  void WaypointFollowerBase_getDistinc(const real_T waypoints[219], real_T
    distinctWpts_data[], int32_T distinctWpts_size[2]);
  real_T codegenReal2Mission_norm_b(const real_T x[3]);
  void codegenReal2Miss_emxInit_real_T(emxArray_real_T_codegenReal2M_T
    **pEmxArray, int32_T numDimensions);
  void codege_emxEnsureCapacity_real_T(emxArray_real_T_codegenReal2M_T *emxArray,
    int32_T oldNumel);
  void codegenReal2Miss_emxFree_real_T(emxArray_real_T_codegenReal2M_T
    **pEmxArray);
  void WaypointFollowerBase_searchClos(uav_sluav_internal_system_Way_T *obj,
    const real_T waypoints_data[], const int32_T waypoints_size[2], const real_T
    currentPose[4]);
  void WaypointFollowerBase_endWaypo_b(uav_sluav_internal_system_Way_T *obj,
    const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
    curStartWaypoint[3], real_T curEndWaypoint[3], const real_T currentPose[4]);
  void WaypointFollowerBase_stepIntern(uav_sluav_internal_system_Way_T *obj,
    const real_T currentPose[4], const real_T waypointsIn[219], real_T
    lookaheadDist, real_T lookaheadPoint[3], real_T *desiredHeading, real_T
    *desiredYaw, uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T
    *status);
  real_T codegenReal2Mission_norm(const real_T x[2]);
  void codegenReal2Mis_Model_resetImpl(robotics_core_internal_syst_b_T *obj);

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
//  Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S2>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S75>/beta_01' : Eliminated nontunable gain of 1
//  Block '<S16>/AirspeedZOH' : Eliminated since input and output rates are identical


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
//  '<S1>'   : 'codegenReal2Mission/FlightMission'
//  '<S2>'   : 'codegenReal2Mission/Real2SimGuidance'
//  '<S3>'   : 'codegenReal2Mission/FlightMission/ChartExecutionMode'
//  '<S4>'   : 'codegenReal2Mission/FlightMission/MissionSimUAV'
//  '<S5>'   : 'codegenReal2Mission/FlightMission/Ramp'
//  '<S6>'   : 'codegenReal2Mission/FlightMission/MissionSimUAV/InitializeSimLocation'
//  '<S7>'   : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimHeadingControl'
//  '<S8>'   : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimUAV'
//  '<S9>'   : 'codegenReal2Mission/FlightMission/MissionSimUAV/TD'
//  '<S10>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/TD/fhan_Bank'
//  '<S11>'  : 'codegenReal2Mission/Real2SimGuidance/AngLog'
//  '<S12>'  : 'codegenReal2Mission/Real2SimGuidance/Engagement'
//  '<S13>'  : 'codegenReal2Mission/Real2SimGuidance/GenerateTrack'
//  '<S14>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast'
//  '<S15>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon'
//  '<S16>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl'
//  '<S17>'  : 'codegenReal2Mission/Real2SimGuidance/TASgreaterthan15for1Sec'
//  '<S18>'  : 'codegenReal2Mission/Real2SimGuidance/TD'
//  '<S19>'  : 'codegenReal2Mission/Real2SimGuidance/TriggerTermination'
//  '<S20>'  : 'codegenReal2Mission/Real2SimGuidance/VisualizeSimUAV'
//  '<S21>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/Degrees to Radians'
//  '<S22>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/Degrees to Radians1'
//  '<S23>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/Degrees to Radians2'
//  '<S24>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth'
//  '<S25>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S26>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S27>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S28>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S29>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S30>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S31>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S32>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S33>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S34>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S35>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S36>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S37>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S38>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S39>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S40>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S41>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S42>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S43>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S44>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S45>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S46>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S47>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA'
//  '<S48>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S49>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S50>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S51>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S52>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S53>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S54>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S55>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S56>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S57>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S58>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S59>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S60>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S61>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S62>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S63>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S64>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S65>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S66>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S67>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S68>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S69>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S70>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/ADRC'
//  '<S71>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/Range2CurrentSim'
//  '<S72>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/RangeSim2Track1d3'
//  '<S73>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/RangeSim2Track2d3'
//  '<S74>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/RangeSim2Track3d3'
//  '<S75>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/ADRC/ESO'
//  '<S76>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/ADRC/NLSEF'
//  '<S77>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/ADRC/TD'
//  '<S78>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/ADRC/ESO/fal(e,0.25,h)'
//  '<S79>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/ADRC/ESO/fal(e,0.5,h)'
//  '<S80>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/ADRC/NLSEF/fhan(e1,ce2,r,h1)'
//  '<S81>'  : 'codegenReal2Mission/Real2SimGuidance/SpeedControl/ADRC/TD/fhan_AirSpdADRC'
//  '<S82>'  : 'codegenReal2Mission/Real2SimGuidance/TD/fhan_Alt'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
