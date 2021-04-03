//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.279
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sat Apr  3 11:58:09 2021
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
    FixedWingGuidanceStateBus SimUAVStateZOH;// '<S6>/SimUAVStateZOH'
    FixedWingGuidanceEnvironmentBus FixedWingGuidanceEnvironmentB_i;
                                      // '<S6>/FixedWingGuidanceEnvironmentBus'
    real_T Down;                       // '<S1>/InvH2D'
    real_T CircleOscillation;          // '<S1>/CircleOscillation'
    real_T Down2Height;                // '<S1>/Down2Height'
    real_T ExecutionTrigger;           // '<S2>/TriggerTermination'
    real_T BiasHSwitch;                // '<S16>/BiasHSwitch'
    real_T NorthEastHeight[3];         // '<S16>/NED2NEU'
    real_T dotAltTD;                   // '<S76>/dotAltTD'
    real_T fh;                         // '<S76>/fhan_Alt'
    real_T InverseY;                   // '<S75>/InverseY'
    real_T InverseR;                   // '<S75>/InverseR'
    real_T dotTD;                      // '<S86>/dotTD'
    real_T GainADRCinvb0;              // '<S79>/GainADRCinvb0'
    real_T SumY;                       // '<S79>/SumY'
    real_T fh_g;                       // '<S86>/fhan_AirSpdADRC'
    real_T ESO;                        // '<S84>/ESO'
    real_T ESO_dot;                    // '<S84>/ESO_dot'
    real_T ESO_dotdot;                 // '<S84>/ESO_dotdot'
    real_T TrackInvH;                  // '<S70>/TrackInvH'
    real_T BiasHTrigger;               // '<S2>/Only1stTimeBiasH'
    real_T TakeOffGathering_o2;        // '<S1>/TakeOffGathering'
    real_T AirSpeed;                   // '<S6>/AirspeedSaturation'
    real_T Height;                     // '<S6>/ClimbRateLimiter'
    real_T ResetSimUAV;                // '<S9>/ResetSimUAV'
    real_T RollAngle;                  // '<S6>/RollAngleSaturation'
    real_T dotBankTD;                  // '<S10>/dotBankTD'
    real_T fh_p;                       // '<S10>/fhan_Bank'
    real_T ComputeDerivative[8];       // '<S9>/ComputeDerivative'
    real_T Seletion;                   // '<S1>/ChartExecutionMode'
    boolean_T Terminate;               // '<S2>/TriggerTermination'
    boolean_T Compare;                 // '<S74>/Compare'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_codegenReal2Mission_T {
    uav_sluav_internal_system_Way_T obj;// '<S71>/TrackSimPath'
    uav_sluav_internal_system_Orb_T obj_m;// '<S1>/TakeOffGathering'
    robotics_core_internal_syst_b_T obj_c;// '<S9>/ComputeDerivative'
    real_T InitHdg_DSTATE;             // '<S1>/InitHdg'
    real_T EastSequence_X[72];         // '<S70>/EastSequence'
    real_T HeightSequence_X[72];       // '<S70>/HeightSequence'
    real_T NorthSequence_X[72];        // '<S70>/NorthSequence'
    real_T MemoryFlowerMode_PreviousInput;// '<S1>/MemoryFlowerMode'
    real_T MemoryLookAheadP_PreviousInput;// '<S1>/MemoryLookAheadP'
    real_T AltitudeGCS;                // '<Root>/AltitudeGCS'
    real_T LatitudeGCS;                // '<Root>/LatitudeGCS'
    real_T LongitudeGCS;               // '<Root>/LongitudeGCS'
    real_T MemoryExecutionTrigger_Previous;// '<S2>/MemoryExecutionTrigger'
    real_T ADRC_U_Log;                 // '<S2>/ADRC_U_Log'
    real_T CrossTrackError;            // '<S2>/CrossTrackError'
    real_T Heading_Log[3];             // '<S2>/Heading_Log'
    real_T LagDistance;                // '<S2>/LagDistance'
    real_T DataCounter;                // '<S2>/TriggerTermination'
    real_T ReturnCounter;              // '<S2>/TriggerTermination'
    real_T Count;                      // '<S2>/TASgreaterthan15for1Sec'
    real_T MemoryRefHeight_PreviousInput;// '<S72>/MemoryRefHeight'
    real_T PrevY;                      // '<S6>/ClimbRateLimiter'
    real_T InitStateSimUAV[8];         // '<S6>/InitStateSimUAV'
    real_T ResetSimUAV;                // '<S6>/StartSimUAV'
    struct {
      void *LoggedData[16];
    } ModelLogging_PWORK;              // '<S2>/ModelLogging'

    int_T Integrator_IWORK;            // '<S9>/Integrator'
    uint8_T FlightMode_Log;            // '<S2>/FlightMode_Log'
    uint8_T Status_Log;                // '<S2>/Status_Log'
    uint8_T is_active_c34_codegenReal2Missi;// '<S2>/TriggerTermination'
    uint8_T is_c34_codegenReal2Mission;// '<S2>/TriggerTermination'
    uint8_T is_active_c16_codegenReal2Missi;// '<S2>/TASgreaterthan15for1Sec'
    uint8_T is_c16_codegenReal2Mission;// '<S2>/TASgreaterthan15for1Sec'
    uint8_T is_active_c3_codegenReal2Missio;// '<S2>/Only1stTimeBiasH'
    uint8_T is_c3_codegenReal2Mission; // '<S2>/Only1stTimeBiasH'
    uint8_T is_active_c10_codegenReal2Missi;// '<S1>/ChartExecutionMode'
    uint8_T is_c10_codegenReal2Mission;// '<S1>/ChartExecutionMode'
    boolean_T icLoad;                  // '<S1>/InitHdg'
    boolean_T ESO_MODE;                // '<S79>/ESO'
  };

  // Continuous states (default storage)
  struct X_codegenReal2Mission_T {
    real_T TD_Alt_CSTATE;              // '<S76>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S76>/dotAltTD'
    real_T TD_AirSpdADRC_CSTATE;       // '<S86>/TD_AirSpdADRC'
    real_T dotTD_CSTATE;               // '<S86>/dotTD'
    real_T ESO_CSTATE;                 // '<S84>/ESO'
    real_T ESO_dot_CSTATE;             // '<S84>/ESO_dot'
    real_T ESO_dotdot_CSTATE;          // '<S84>/ESO_dotdot'
    real_T Integrator_CSTATE[8];       // '<S9>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S10>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S10>/dotBankTD'
  };

  // State derivatives (default storage)
  struct XDot_codegenReal2Mission_T {
    real_T TD_Alt_CSTATE;              // '<S76>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S76>/dotAltTD'
    real_T TD_AirSpdADRC_CSTATE;       // '<S86>/TD_AirSpdADRC'
    real_T dotTD_CSTATE;               // '<S86>/dotTD'
    real_T ESO_CSTATE;                 // '<S84>/ESO'
    real_T ESO_dot_CSTATE;             // '<S84>/ESO_dot'
    real_T ESO_dotdot_CSTATE;          // '<S84>/ESO_dotdot'
    real_T Integrator_CSTATE[8];       // '<S9>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S10>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S10>/dotBankTD'
  };

  // State disabled
  struct XDis_codegenReal2Mission_T {
    boolean_T TD_Alt_CSTATE;           // '<S76>/TD_Alt'
    boolean_T dotAltTD_CSTATE;         // '<S76>/dotAltTD'
    boolean_T TD_AirSpdADRC_CSTATE;    // '<S86>/TD_AirSpdADRC'
    boolean_T dotTD_CSTATE;            // '<S86>/dotTD'
    boolean_T ESO_CSTATE;              // '<S84>/ESO'
    boolean_T ESO_dot_CSTATE;          // '<S84>/ESO_dot'
    boolean_T ESO_dotdot_CSTATE;       // '<S84>/ESO_dotdot'
    boolean_T Integrator_CSTATE[8];    // '<S9>/Integrator'
    boolean_T TD_Bank_CSTATE;          // '<S10>/TD_Bank'
    boolean_T dotBankTD_CSTATE;        // '<S10>/dotBankTD'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX_codegenReal2Mission_T {
    ZCSigState Integrator_Reset_ZCE;   // '<S9>/Integrator'
  };

  // Invariant block signals (default storage)
  struct ConstB_codegenReal2Mission_T {
    real_T UnitConversion;             // '<S39>/Unit Conversion'
    real_T Sum;                        // '<S43>/Sum'
    real_T Product1;                   // '<S44>/Product1'
    real_T Sum1;                       // '<S44>/Sum1'
    real_T sqrt_d;                     // '<S44>/sqrt'
    real_T Product2;                   // '<S40>/Product2'
    real_T Sum1_f;                     // '<S40>/Sum1'
    real_T SinCos_o1;                  // '<S25>/SinCos'
    real_T SinCos_o2;                  // '<S25>/SinCos'
    real_T Sum_f;                      // '<S66>/Sum'
    real_T Product1_d;                 // '<S67>/Product1'
    real_T Sum1_c;                     // '<S67>/Sum1'
    real_T sqrt_k;                     // '<S67>/sqrt'
    real_T Product2_k;                 // '<S62>/Product2'
    real_T Sum1_j;                     // '<S62>/Sum1'
    real_T UnitConversion_f;           // '<S63>/Unit Conversion'
    real_T SinCos_o1_f;                // '<S48>/SinCos'
    real_T SinCos_o2_h;                // '<S48>/SinCos'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_codegenReal2Mission_T {
    RealUAVStateBus RealUAVLatLonState;// '<Root>/RealUAVLatLonState'
    uint8_T FlightMode;                // '<Root>/FlightMode'
    real_T GroundSpd;                  // '<Root>/GroundSpd'
    VectorSpeed VectorSpd;             // '<Root>/VectorSpd'
    real_T Altitude;                   // '<Root>/Altitude'
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
                                          //  Referenced by: '<S5>/AltitudeGCS'

    real_T GCS_Latitude;               // Variable: GCS_Latitude
                                          //  Referenced by: '<S5>/LatitudeGCS'

    real_T GCS_Longitude;              // Variable: GCS_Longitude
                                          //  Referenced by: '<S5>/LongitudeGCS'

    real_T numMissionUAV;              // Variable: numMissionUAV
                                          //  Referenced by:
                                          //    '<S1>/Number Of Mission UAV'
                                          //    '<S5>/Number Of Mission UAV'

    int32_T UAVidx;                    // Variable: UAVidx
                                          //  Referenced by:
                                          //    '<S1>/UAVidx'
                                          //    '<S5>/UAVidx'

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
      boolean_T firstInitCondFlag;
      time_T tFinal;
      SimTimeStep simTimeStep;
      boolean_T stopRequestedFlag;
      time_T *t;
      time_T tArray[2];
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

  // private member function(s) for subsystem '<S10>/fhan_Bank'
  static void codegenReal2Mission_fhan_Bank(real_T rtu_u, real_T rtu_u_p, real_T
    rtu_u_e, real_T rtu_u_i, real_T *rty_fh);

  // private member function(s) for subsystem '<S84>/fal(e,0.25,h)'
  static void codegenReal2Mission_fale025h(real_T rtu_u, real_T rtu_u_b, real_T
    rtu_u_c, real_T *rty_y);

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
//  Block '<S71>/SwitchDesiredYaw' : Unused code path elimination
//  Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S2>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S75>/AirspeedZOH' : Eliminated since input and output rates are identical


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
//  '<S3>'   : 'codegenReal2Mission/VisualizeSimUAV'
//  '<S4>'   : 'codegenReal2Mission/FlightMission/ChartExecutionMode'
//  '<S5>'   : 'codegenReal2Mission/FlightMission/InitializeSimLocation'
//  '<S6>'   : 'codegenReal2Mission/FlightMission/MissionSimUAV'
//  '<S7>'   : 'codegenReal2Mission/FlightMission/Ramp'
//  '<S8>'   : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimHeadingControl'
//  '<S9>'   : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimUAV'
//  '<S10>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/TD'
//  '<S11>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/TD/fhan_Bank'
//  '<S12>'  : 'codegenReal2Mission/Real2SimGuidance/FlightPathFromVectorSpd'
//  '<S13>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast'
//  '<S14>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon'
//  '<S15>'  : 'codegenReal2Mission/Real2SimGuidance/Only1stTimeBiasH'
//  '<S16>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav'
//  '<S17>'  : 'codegenReal2Mission/Real2SimGuidance/TASgreaterthan15for1Sec'
//  '<S18>'  : 'codegenReal2Mission/Real2SimGuidance/TriggerTermination'
//  '<S19>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/Degrees to Radians'
//  '<S20>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/Degrees to Radians1'
//  '<S21>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/Degrees to Radians2'
//  '<S22>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth'
//  '<S23>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S24>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S25>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S26>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S27>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S28>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S29>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S30>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S31>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S32>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S33>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S34>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S35>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S36>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S37>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S38>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S39>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S40>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S41>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S42>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S43>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S44>'  : 'codegenReal2Mission/Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S45>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA'
//  '<S46>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S47>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S48>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S49>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S50>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S51>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S52>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S53>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S54>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S55>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S56>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S57>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S58>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S59>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S60>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S61>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S62>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S63>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S64>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S65>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S66>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S67>'  : 'codegenReal2Mission/Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S68>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/AngLog'
//  '<S69>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/Engagement'
//  '<S70>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/GenerateTrack'
//  '<S71>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/HeadingLogic'
//  '<S72>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/HeadingNaNProtection'
//  '<S73>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/MaxBrake'
//  '<S74>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/PointingMode'
//  '<S75>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl'
//  '<S76>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/TD'
//  '<S77>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/HeadingLogic/RefHdg'
//  '<S78>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/MaxBrake/Calculate Brake Range'
//  '<S79>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/ADRC'
//  '<S80>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/Range2CurrentSim'
//  '<S81>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track1d3'
//  '<S82>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track2d3'
//  '<S83>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track3d3'
//  '<S84>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/ESO'
//  '<S85>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/NLSEF'
//  '<S86>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/TD'
//  '<S87>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/ESO/fal(e,0.25,h)'
//  '<S88>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/ESO/fal(e,0.5,h)'
//  '<S89>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/NLSEF/fhan(e1,ce2,r,h1)'
//  '<S90>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/TD/fhan_AirSpdADRC'
//  '<S91>'  : 'codegenReal2Mission/Real2SimGuidance/Real2SimNav/TD/fhan_Alt'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
