//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 1.343
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Mar 11 17:48:09 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
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
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "codegenReal2Mission_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
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
typedef struct {
  real_T *y;                           // output
  real_T *f[4];                        // derivatives
} ODE4_IntgData;

#endif

// Class declaration for model codegenReal2Mission
class codegenReal2MissionModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  typedef struct {
    FixedWingGuidanceStateBus SimUAVStateZOH;// '<S10>/SimUAVStateZOH'
    FixedWingGuidanceEnvironmentBus FixedWingGuidanceEnvironmentB_g;
                                     // '<S10>/FixedWingGuidanceEnvironmentBus'
    FixedWingGuidanceControlBus SlewGuidanceBus;// '<S10>/Slew Guidance Bus'
    real_T Down;                       // '<S2>/Gain2'
    real_T Down2Height;                // '<S2>/Down2Height'
    real_T Gain7;                      // '<S3>/Gain7'
    real_T TakeOffGathering_o2;        // '<S2>/TakeOffGathering'
    real_T ComputeDerivative[8];       // '<S16>/ComputeDerivative'
    boolean_T Terminate;               // '<Root>/TriggerTermination'
  } B_codegenReal2Mission_T;

  // Block states (default storage) for system '<Root>'
  typedef struct {
    uav_sluav_internal_system_Way_T obj;// '<Root>/TrackSimPath'
    uav_sluav_internal_system_Orb_T obj_m;// '<S2>/TakeOffGathering'
    robotics_core_internal_syst_b_T obj_a;// '<S16>/ComputeDerivative'
    real_T Delay_DSTATE;               // '<S2>/Delay'
    real_T UD_DSTATE;                  // '<S98>/UD'
    real_T Speed2d3Path_DSTATE[20];    // '<S6>/Speed2d3Path'
    real_T EastSequence_X[60];         // '<S3>/EastSequence'
    real_T HeightSequence_X[60];       // '<S3>/HeightSequence'
    real_T NorthSequence_X[60];        // '<S3>/NorthSequence'
    real_T UD_DSTATE_f;                // '<S12>/UD'
    real_T UD_DSTATE_j;                // '<S14>/UD'
    real_T UD_DSTATE_jn;               // '<S17>/UD'
    real_T Memory_PreviousInput;       // '<S2>/Memory'
    real_T AltitudeGCS;                // '<Root>/AltitudeGCS'
    real_T LatitudeGCS;                // '<Root>/LatitudeGCS'
    real_T LongitudeGCS;               // '<Root>/LongitudeGCS'
    real_T DataCounter;                // '<Root>/TriggerTermination'
    real_T DataCounter_f;              // '<Root>/TASgreaterthan15for1Sec'
    real_T PrevY;                      // '<S10>/ClimbRateLimiter'
    struct {
      void *LoggedData[7];
    } ModelLogging_PWORK;              // '<Root>/ModelLogging'

    int32_T UAVidx;                    // '<Root>/UAVidx'
    int32_T numMissionUAV;             // '<Root>/numMissionUAV'
    uint8_T icLoad;                    // '<S2>/Delay'
    uint8_T is_active_c4_codegenReal2Missio;// '<Root>/TriggerTermination'
    uint8_T is_c4_codegenReal2Mission; // '<Root>/TriggerTermination'
    uint8_T is_active_c1_codegenReal2Missio;// '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_c1_codegenReal2Mission; // '<Root>/TASgreaterthan15for1Sec'
  } DW_codegenReal2Mission_T;

  // Continuous states (default storage)
  typedef struct {
    real_T Integrator_CSTATE[8];       // '<S16>/Integrator'
  } X_codegenReal2Mission_T;

  // State derivatives (default storage)
  typedef struct {
    real_T Integrator_CSTATE[8];       // '<S16>/Integrator'
  } XDot_codegenReal2Mission_T;

  // State disabled
  typedef struct {
    boolean_T Integrator_CSTATE[8];    // '<S16>/Integrator'
  } XDis_codegenReal2Mission_T;

  // Zero-crossing (trigger) state
  typedef struct {
    ZCSigState UD_Reset_ZCE;           // '<S98>/UD'
  } PrevZCX_codegenReal2Mission_T;

  // Invariant block signals (default storage)
  typedef const struct tag_ConstB_codegenReal2Missio_T {
    real_T Sum;                        // '<S65>/Sum'
    real_T Product1;                   // '<S66>/Product1'
    real_T Sum1;                       // '<S66>/Sum1'
    real_T sqrt_l;                     // '<S66>/sqrt'
    real_T Product2;                   // '<S61>/Product2'
    real_T Sum1_f;                     // '<S61>/Sum1'
    real_T UnitConversion;             // '<S62>/Unit Conversion'
    real_T SinCos_o1;                  // '<S47>/SinCos'
    real_T SinCos_o2;                  // '<S47>/SinCos'
    real_T UnitConversion_l;           // '<S38>/Unit Conversion'
    real_T Sum_m;                      // '<S42>/Sum'
    real_T Product1_i;                 // '<S43>/Product1'
    real_T Sum1_fg;                    // '<S43>/Sum1'
    real_T sqrt_c;                     // '<S43>/sqrt'
    real_T Product2_m;                 // '<S39>/Product2'
    real_T Sum1_m;                     // '<S39>/Sum1'
    real_T SinCos_o1_l;                // '<S24>/SinCos'
    real_T SinCos_o2_o;                // '<S24>/SinCos'
  } ConstB_codegenReal2Mission_T;

  // External inputs (root inport signals with default storage)
  typedef struct {
    RealUAVStateBus RealUAVLatLonState;// '<Root>/RealUAVLatLonState'
  } ExtU_codegenReal2Mission_T;

  // External outputs (root outports fed by signals with default storage)
  typedef struct {
    real_T RefAirspeed;                // '<Root>/RefAirspeed'
    LookAheadPoint LookAheadPoint_j;   // '<Root>/LookAheadPoint'
    boolean_T EngagedFlag;             // '<Root>/EngagedFlag'
  } ExtY_codegenReal2Mission_T;

  // Parameters (default storage)
  struct P_codegenReal2Mission_T {
    real_T GCS_Altitude;               // Variable: GCS_Altitude
                                          //  Referenced by: '<S13>/AltitudeGCS'

    real_T GCS_Latitude;               // Variable: GCS_Latitude
                                          //  Referenced by: '<S13>/LatitudeGCS'

    real_T GCS_Longitude;              // Variable: GCS_Longitude
                                          //  Referenced by: '<S13>/LongitudeGCS'

    int32_T UAVidx;                    // Variable: UAVidx
                                          //  Referenced by: '<S13>/UAVidx'

    int32_T numMissionUAV;             // Variable: numMissionUAV
                                          //  Referenced by: '<S13>/Number Of Mission UAV'

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
    real_T odeY[8];
    real_T odeF[4][8];
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

  // private member function(s) for subsystem '<Root>'
  void WaypointFollowerBase_getDistinc(const real_T waypoints[183], real_T
    distinctWpts_data[], int32_T distinctWpts_size[2]);
  void codegenReal2Miss_emxInit_real_T(emxArray_real_T_codegenReal2M_T
    **pEmxArray, int32_T numDimensions);
  real_T codegenReal2Mission_norm_b(const real_T x[3]);
  void codege_emxEnsureCapacity_real_T(emxArray_real_T_codegenReal2M_T *emxArray,
    int32_T oldNumel);
  boolean_T codegenReal2Mission_isequal(real_T varargin_1, real_T varargin_2);
  void codegenReal2Miss_emxFree_real_T(emxArray_real_T_codegenReal2M_T
    **pEmxArray);
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
//  Block '<S12>/Data Type Duplicate' : Unused code path elimination
//  Block '<S14>/Data Type Duplicate' : Unused code path elimination
//  Block '<S17>/Data Type Duplicate' : Unused code path elimination
//  Block '<S98>/DTDup' : Unused code path elimination
//  Block '<S13>/Reshape' : Reshape block reduction
//  Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S16>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<Root>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S6>/AirspeedZOH' : Eliminated since input and output rates are identical


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
//  '<S1>'   : 'codegenReal2Mission/EngagementTruthTable'
//  '<S2>'   : 'codegenReal2Mission/FlightMission'
//  '<S3>'   : 'codegenReal2Mission/GenerateTrack'
//  '<S4>'   : 'codegenReal2Mission/LatLon2NorthEast'
//  '<S5>'   : 'codegenReal2Mission/NorthEast2LatLon'
//  '<S6>'   : 'codegenReal2Mission/SpeedControl'
//  '<S7>'   : 'codegenReal2Mission/TASgreaterthan15for1Sec'
//  '<S8>'   : 'codegenReal2Mission/TriggerTermination'
//  '<S9>'   : 'codegenReal2Mission/VisualizeSimUAV'
//  '<S10>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV'
//  '<S11>'  : 'codegenReal2Mission/FlightMission/Ramp'
//  '<S12>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/HeightTF'
//  '<S13>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/InitializeSimLocation'
//  '<S14>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/RollTF'
//  '<S15>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimHeadingControl'
//  '<S16>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimUAV'
//  '<S17>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/TASTF'
//  '<S18>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians'
//  '<S19>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians1'
//  '<S20>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians2'
//  '<S21>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth'
//  '<S22>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S23>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S24>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S25>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S26>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S27>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S28>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S29>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S30>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S31>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S32>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S33>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S34>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S35>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S36>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S37>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S38>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S39>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S40>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S41>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S42>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S43>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S44>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA'
//  '<S45>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S46>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S47>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S48>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S49>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S50>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S51>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S52>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S53>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S54>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S55>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S56>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S57>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S58>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S59>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S60>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S61>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S62>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S63>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S64>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S65>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S66>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S67>'  : 'codegenReal2Mission/SpeedControl/FrontController'
//  '<S68>'  : 'codegenReal2Mission/SpeedControl/Range2CurrentSim'
//  '<S69>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track1d3'
//  '<S70>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track2d3'
//  '<S71>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track3d3'
//  '<S72>'  : 'codegenReal2Mission/SpeedControl/FrontController/Anti-windup'
//  '<S73>'  : 'codegenReal2Mission/SpeedControl/FrontController/D Gain'
//  '<S74>'  : 'codegenReal2Mission/SpeedControl/FrontController/Filter'
//  '<S75>'  : 'codegenReal2Mission/SpeedControl/FrontController/Filter ICs'
//  '<S76>'  : 'codegenReal2Mission/SpeedControl/FrontController/I Gain'
//  '<S77>'  : 'codegenReal2Mission/SpeedControl/FrontController/Ideal P Gain'
//  '<S78>'  : 'codegenReal2Mission/SpeedControl/FrontController/Ideal P Gain Fdbk'
//  '<S79>'  : 'codegenReal2Mission/SpeedControl/FrontController/Integrator'
//  '<S80>'  : 'codegenReal2Mission/SpeedControl/FrontController/Integrator ICs'
//  '<S81>'  : 'codegenReal2Mission/SpeedControl/FrontController/N Copy'
//  '<S82>'  : 'codegenReal2Mission/SpeedControl/FrontController/N Gain'
//  '<S83>'  : 'codegenReal2Mission/SpeedControl/FrontController/P Copy'
//  '<S84>'  : 'codegenReal2Mission/SpeedControl/FrontController/Parallel P Gain'
//  '<S85>'  : 'codegenReal2Mission/SpeedControl/FrontController/Reset Signal'
//  '<S86>'  : 'codegenReal2Mission/SpeedControl/FrontController/Saturation'
//  '<S87>'  : 'codegenReal2Mission/SpeedControl/FrontController/Saturation Fdbk'
//  '<S88>'  : 'codegenReal2Mission/SpeedControl/FrontController/Sum'
//  '<S89>'  : 'codegenReal2Mission/SpeedControl/FrontController/Sum Fdbk'
//  '<S90>'  : 'codegenReal2Mission/SpeedControl/FrontController/Tracking Mode'
//  '<S91>'  : 'codegenReal2Mission/SpeedControl/FrontController/Tracking Mode Sum'
//  '<S92>'  : 'codegenReal2Mission/SpeedControl/FrontController/Tsamp - Integral'
//  '<S93>'  : 'codegenReal2Mission/SpeedControl/FrontController/Tsamp - Ngain'
//  '<S94>'  : 'codegenReal2Mission/SpeedControl/FrontController/postSat Signal'
//  '<S95>'  : 'codegenReal2Mission/SpeedControl/FrontController/preSat Signal'
//  '<S96>'  : 'codegenReal2Mission/SpeedControl/FrontController/Anti-windup/Disabled'
//  '<S97>'  : 'codegenReal2Mission/SpeedControl/FrontController/D Gain/Internal Parameters'
//  '<S98>'  : 'codegenReal2Mission/SpeedControl/FrontController/Filter/Differentiator'
//  '<S99>'  : 'codegenReal2Mission/SpeedControl/FrontController/Filter/Differentiator/Tsamp'
//  '<S100>' : 'codegenReal2Mission/SpeedControl/FrontController/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S101>' : 'codegenReal2Mission/SpeedControl/FrontController/Filter ICs/Internal IC - Differentiator'
//  '<S102>' : 'codegenReal2Mission/SpeedControl/FrontController/I Gain/Disabled'
//  '<S103>' : 'codegenReal2Mission/SpeedControl/FrontController/Ideal P Gain/Passthrough'
//  '<S104>' : 'codegenReal2Mission/SpeedControl/FrontController/Ideal P Gain Fdbk/Disabled'
//  '<S105>' : 'codegenReal2Mission/SpeedControl/FrontController/Integrator/Disabled'
//  '<S106>' : 'codegenReal2Mission/SpeedControl/FrontController/Integrator ICs/Disabled'
//  '<S107>' : 'codegenReal2Mission/SpeedControl/FrontController/N Copy/Disabled wSignal Specification'
//  '<S108>' : 'codegenReal2Mission/SpeedControl/FrontController/N Gain/Passthrough'
//  '<S109>' : 'codegenReal2Mission/SpeedControl/FrontController/P Copy/Disabled'
//  '<S110>' : 'codegenReal2Mission/SpeedControl/FrontController/Parallel P Gain/Internal Parameters'
//  '<S111>' : 'codegenReal2Mission/SpeedControl/FrontController/Reset Signal/External Reset'
//  '<S112>' : 'codegenReal2Mission/SpeedControl/FrontController/Saturation/Passthrough'
//  '<S113>' : 'codegenReal2Mission/SpeedControl/FrontController/Saturation Fdbk/Disabled'
//  '<S114>' : 'codegenReal2Mission/SpeedControl/FrontController/Sum/Sum_PD'
//  '<S115>' : 'codegenReal2Mission/SpeedControl/FrontController/Sum Fdbk/Disabled'
//  '<S116>' : 'codegenReal2Mission/SpeedControl/FrontController/Tracking Mode/Disabled'
//  '<S117>' : 'codegenReal2Mission/SpeedControl/FrontController/Tracking Mode Sum/Passthrough'
//  '<S118>' : 'codegenReal2Mission/SpeedControl/FrontController/Tsamp - Integral/Disabled wSignal Specification'
//  '<S119>' : 'codegenReal2Mission/SpeedControl/FrontController/Tsamp - Ngain/Passthrough'
//  '<S120>' : 'codegenReal2Mission/SpeedControl/FrontController/postSat Signal/Forward_Path'
//  '<S121>' : 'codegenReal2Mission/SpeedControl/FrontController/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
