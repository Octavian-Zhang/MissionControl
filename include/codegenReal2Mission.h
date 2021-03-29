//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.229
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 29 09:26:04 2021
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
    FixedWingGuidanceStateBus SimUAVStateZOH;// '<S13>/SimUAVStateZOH'
    FixedWingGuidanceEnvironmentBus FixedWingGuidanceEnvironmentB_g;
                                     // '<S13>/FixedWingGuidanceEnvironmentBus'
    real_T NorthEastHeight[3];         // '<Root>/NED2NEU'
    real_T TD_Alt;                     // '<S9>/TD_Alt'
    real_T Sum[3];                     // '<Root>/Sum'
    real_T DataSwitch;                 // '<Root>/DataSwitch'
    real_T Down;                       // '<S3>/InvH2D'
    real_T CircleOscillation;          // '<S3>/CircleOscillation'
    real_T Down2Height;                // '<S3>/Down2Height'
    real_T dotAltTD;                   // '<S9>/dotAltTD'
    real_T ExecutionTrigger;           // '<Root>/TriggerTermination'
    real_T fh;                         // '<S9>/fhan_Alt'
    real_T InverseY;                   // '<S7>/InverseY'
    real_T InverseR;                   // '<S7>/InverseR'
    real_T dotTD;                      // '<S76>/dotTD'
    real_T ESOdotdotsum;               // '<S74>/ESOdotdotsum'
    real_T ESOdotsum;                  // '<S74>/ESOdotsum'
    real_T Inverse;                    // '<S74>/Inverse'
    real_T fh_f;                       // '<S76>/fhan_AirSpdADRC'
    real_T TrackInvH;                  // '<S4>/TrackInvH'
    real_T TakeOffGathering_o2;        // '<S3>/TakeOffGathering'
    real_T Airspeed;                   // '<S13>/AirspeedSaturation'
    real_T ClimbRateLimiter;           // '<S13>/ClimbRateLimiter'
    real_T RollAngle;                  // '<S13>/RollAngleSaturation'
    real_T dotBankTD;                  // '<S18>/dotBankTD'
    real_T fh_n;                       // '<S18>/fhan_Bank'
    real_T ComputeDerivative[8];       // '<S17>/ComputeDerivative'
    real_T Seletion;                   // '<S3>/ChartExecutionMode'
    boolean_T Terminate;               // '<Root>/TriggerTermination'
    boolean_T TakeOffTrigger;          // '<Root>/TASgreaterthan15for1Sec'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_codegenReal2Mission_T {
    uav_sluav_internal_system_Way_T obj;// '<Root>/TrackSimPath'
    uav_sluav_internal_system_Orb_T obj_m;// '<S3>/TakeOffGathering'
    robotics_core_internal_syst_b_T obj_a;// '<S17>/ComputeDerivative'
    real_T InitHdg_DSTATE;             // '<S3>/InitHdg'
    real_T EastSequence_X[72];         // '<S4>/EastSequence'
    real_T HeightSequence_X[72];       // '<S4>/HeightSequence'
    real_T NorthSequence_X[72];        // '<S4>/NorthSequence'
    real_T MemoryFlowerMode_PreviousInput;// '<S3>/MemoryFlowerMode'
    real_T MemoryRefHeight_PreviousInput;// '<Root>/MemoryRefHeight'
    real_T MemoryLookAheadP_PreviousInput;// '<S3>/MemoryLookAheadP'
    real_T AltitudeGCS;                // '<Root>/AltitudeGCS'
    real_T LatitudeGCS;                // '<Root>/LatitudeGCS'
    real_T LongitudeGCS;               // '<Root>/LongitudeGCS'
    real_T numMissionUAV;              // '<Root>/numMissionUAV'
    real_T DataCounter;                // '<Root>/TriggerTermination'
    real_T Count;                      // '<Root>/TASgreaterthan15for1Sec'
    real_T PrevY;                      // '<S13>/ClimbRateLimiter'
    struct {
      void *LoggedData[10];
    } ModelLogging_PWORK;              // '<Root>/ModelLogging'

    int32_T UAVidx;                    // '<Root>/UAVidx'
    uint8_T is_active_c4_codegenReal2Missio;// '<Root>/TriggerTermination'
    uint8_T is_c4_codegenReal2Mission; // '<Root>/TriggerTermination'
    uint8_T is_active_c1_codegenReal2Missio;// '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_c1_codegenReal2Mission; // '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_active_c10_codegenReal2Missi;// '<S3>/ChartExecutionMode'
    uint8_T is_c10_codegenReal2Mission;// '<S3>/ChartExecutionMode'
    boolean_T icLoad;                  // '<S3>/InitHdg'
  };

  // Continuous states (default storage)
  struct X_codegenReal2Mission_T {
    real_T TD_Alt_CSTATE;              // '<S9>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S9>/dotAltTD'
    real_T ESO_CSTATE;                 // '<S74>/ESO'
    real_T ESO_dot_CSTATE;             // '<S74>/ESO_dot'
    real_T ESO_dotdot_CSTATE;          // '<S74>/ESO_dotdot'
    real_T TD_AirSpdADRC_CSTATE;       // '<S76>/TD_AirSpdADRC'
    real_T dotTD_CSTATE;               // '<S76>/dotTD'
    real_T Integrator_CSTATE[8];       // '<S17>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S18>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S18>/dotBankTD'
  };

  // State derivatives (default storage)
  struct XDot_codegenReal2Mission_T {
    real_T TD_Alt_CSTATE;              // '<S9>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S9>/dotAltTD'
    real_T ESO_CSTATE;                 // '<S74>/ESO'
    real_T ESO_dot_CSTATE;             // '<S74>/ESO_dot'
    real_T ESO_dotdot_CSTATE;          // '<S74>/ESO_dotdot'
    real_T TD_AirSpdADRC_CSTATE;       // '<S76>/TD_AirSpdADRC'
    real_T dotTD_CSTATE;               // '<S76>/dotTD'
    real_T Integrator_CSTATE[8];       // '<S17>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S18>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S18>/dotBankTD'
  };

  // State disabled
  struct XDis_codegenReal2Mission_T {
    boolean_T TD_Alt_CSTATE;           // '<S9>/TD_Alt'
    boolean_T dotAltTD_CSTATE;         // '<S9>/dotAltTD'
    boolean_T ESO_CSTATE;              // '<S74>/ESO'
    boolean_T ESO_dot_CSTATE;          // '<S74>/ESO_dot'
    boolean_T ESO_dotdot_CSTATE;       // '<S74>/ESO_dotdot'
    boolean_T TD_AirSpdADRC_CSTATE;    // '<S76>/TD_AirSpdADRC'
    boolean_T dotTD_CSTATE;            // '<S76>/dotTD'
    boolean_T Integrator_CSTATE[8];    // '<S17>/Integrator'
    boolean_T TD_Bank_CSTATE;          // '<S18>/TD_Bank'
    boolean_T dotBankTD_CSTATE;        // '<S18>/dotBankTD'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX_codegenReal2Mission_T {
    ZCSigState ESO_Reset_ZCE;          // '<S74>/ESO'
    ZCSigState ESO_dot_Reset_ZCE;      // '<S74>/ESO_dot'
    ZCSigState ESO_dotdot_Reset_ZCE;   // '<S74>/ESO_dotdot'
    ZCSigState TD_AirSpdADRC_Reset_ZCE;// '<S76>/TD_AirSpdADRC'
    ZCSigState dotTD_Reset_ZCE;        // '<S76>/dotTD'
  };

  // Invariant block signals (default storage)
  struct ConstB_codegenReal2Mission_T {
    real_T Sum;                        // '<S67>/Sum'
    real_T Product1;                   // '<S68>/Product1'
    real_T Sum1;                       // '<S68>/Sum1'
    real_T sqrt_l;                     // '<S68>/sqrt'
    real_T Product2;                   // '<S63>/Product2'
    real_T Sum1_f;                     // '<S63>/Sum1'
    real_T UnitConversion;             // '<S64>/Unit Conversion'
    real_T SinCos_o1;                  // '<S49>/SinCos'
    real_T SinCos_o2;                  // '<S49>/SinCos'
    real_T UnitConversion_l;           // '<S40>/Unit Conversion'
    real_T Sum_m;                      // '<S44>/Sum'
    real_T Product1_i;                 // '<S45>/Product1'
    real_T Sum1_fg;                    // '<S45>/Sum1'
    real_T sqrt_c;                     // '<S45>/sqrt'
    real_T Product2_m;                 // '<S41>/Product2'
    real_T Sum1_m;                     // '<S41>/Sum1'
    real_T SinCos_o1_l;                // '<S26>/SinCos'
    real_T SinCos_o2_o;                // '<S26>/SinCos'
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
                                          //  Referenced by: '<S15>/AltitudeGCS'

    real_T GCS_Latitude;               // Variable: GCS_Latitude
                                          //  Referenced by: '<S15>/LatitudeGCS'

    real_T GCS_Longitude;              // Variable: GCS_Longitude
                                          //  Referenced by: '<S15>/LongitudeGCS'

    real_T numMissionUAV;              // Variable: numMissionUAV
                                          //  Referenced by: '<S15>/Number Of Mission UAV'

    int32_T UAVidx;                    // Variable: UAVidx
                                          //  Referenced by: '<S15>/UAVidx'

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

  // private member function(s) for subsystem '<S18>/fhan_Bank'
  static void codegenReal2Mission_fhan_Bank(real_T rtu_u, real_T rtu_u_n, real_T
    rtu_u_f, real_T rtu_u_c, real_T *rty_fh);

  // private member function(s) for subsystem '<S74>/fal(e,0.25,h)'
  static void codegenReal2Mission_fale025h(real_T rtu_u, real_T rtu_u_a, real_T
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
//  Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S17>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<Root>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S74>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S7>/AirspeedZOH' : Eliminated since input and output rates are identical


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
//  '<S1>'   : 'codegenReal2Mission/AngLog'
//  '<S2>'   : 'codegenReal2Mission/Engagement'
//  '<S3>'   : 'codegenReal2Mission/FlightMission'
//  '<S4>'   : 'codegenReal2Mission/GenerateTrack'
//  '<S5>'   : 'codegenReal2Mission/LatLon2NorthEast'
//  '<S6>'   : 'codegenReal2Mission/NorthEast2LatLon'
//  '<S7>'   : 'codegenReal2Mission/SpeedControl'
//  '<S8>'   : 'codegenReal2Mission/TASgreaterthan15for1Sec'
//  '<S9>'   : 'codegenReal2Mission/TD'
//  '<S10>'  : 'codegenReal2Mission/TriggerTermination'
//  '<S11>'  : 'codegenReal2Mission/VisualizeSimUAV'
//  '<S12>'  : 'codegenReal2Mission/FlightMission/ChartExecutionMode'
//  '<S13>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV'
//  '<S14>'  : 'codegenReal2Mission/FlightMission/Ramp'
//  '<S15>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/InitializeSimLocation'
//  '<S16>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimHeadingControl'
//  '<S17>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimUAV'
//  '<S18>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/TD'
//  '<S19>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/TD/fhan_Bank'
//  '<S20>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians'
//  '<S21>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians1'
//  '<S22>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians2'
//  '<S23>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth'
//  '<S24>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S25>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S26>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S27>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S28>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S29>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S30>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S31>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S32>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S33>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S34>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S35>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S36>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S37>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S38>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S39>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S40>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S41>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S42>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S43>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S44>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S45>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S46>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA'
//  '<S47>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S48>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S49>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S50>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S51>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S52>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S53>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S54>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S55>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S56>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S57>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S58>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S59>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S60>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S61>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S62>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S63>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S64>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S65>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S66>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S67>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S68>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S69>'  : 'codegenReal2Mission/SpeedControl/ADRC'
//  '<S70>'  : 'codegenReal2Mission/SpeedControl/Range2CurrentSim'
//  '<S71>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track1d3'
//  '<S72>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track2d3'
//  '<S73>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track3d3'
//  '<S74>'  : 'codegenReal2Mission/SpeedControl/ADRC/ESO'
//  '<S75>'  : 'codegenReal2Mission/SpeedControl/ADRC/NLSEF'
//  '<S76>'  : 'codegenReal2Mission/SpeedControl/ADRC/TD'
//  '<S77>'  : 'codegenReal2Mission/SpeedControl/ADRC/ESO/fal(e,0.25,h)'
//  '<S78>'  : 'codegenReal2Mission/SpeedControl/ADRC/ESO/fal(e,0.5,h)'
//  '<S79>'  : 'codegenReal2Mission/SpeedControl/ADRC/NLSEF/fhan(e1,ce2,r,h1)'
//  '<S80>'  : 'codegenReal2Mission/SpeedControl/ADRC/TD/fhan_AirSpdADRC'
//  '<S81>'  : 'codegenReal2Mission/TD/fhan_Alt'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
