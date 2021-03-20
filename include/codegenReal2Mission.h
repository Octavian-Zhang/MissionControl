//
// File: codegenReal2Mission.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.98
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sat Mar 20 14:48:46 2021
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

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern real_T b0;                      // Variable: b0
                                          //  Referenced by:
                                          //    '<S66>/Gain'
                                          //    '<S71>/Gain4'

extern real_T c;                       // Variable: c
                                          //  Referenced by: '<S72>/Gain'

extern real_T h1;                      // Variable: h1
                                          //  Referenced by: '<S72>/Constant1'


// Class declaration for model codegenReal2Mission
class codegenReal2MissionModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_codegenReal2Mission_T {
    FixedWingGuidanceStateBus SimUAVStateZOH;// '<S12>/SimUAVStateZOH'
    FixedWingGuidanceEnvironmentBus FixedWingGuidanceEnvironmentB_g;
                                     // '<S12>/FixedWingGuidanceEnvironmentBus'
    FixedWingGuidanceControlBus SlewGuidanceBus;// '<S12>/Slew Guidance Bus'
    real_T Down;                       // '<S3>/Gain2'
    real_T Switch;                     // '<S3>/Switch'
    real_T Down2Height;                // '<S3>/Down2Height'
    real_T ExecutionTrigger;           // '<Root>/TriggerTermination'
    real_T Gain1;                      // '<S7>/Gain1'
    real_T Gain;                       // '<S7>/Gain'
    real_T Gain3;                      // '<S71>/Gain3'
    real_T Integrator2;                // '<S73>/Integrator2'
    real_T Gain_o;                     // '<S66>/Gain'
    real_T Sum;                        // '<S71>/Sum'
    real_T Sum1;                       // '<S71>/Sum1'
    real_T Sum4;                       // '<S66>/Sum4'
    real_T fh;                         // '<S73>/fhan(v1-v0,v2,r0,h)1'
    real_T Gain7;                      // '<S4>/Gain7'
    real_T TakeOffGathering_o2;        // '<S3>/TakeOffGathering'
    real_T ComputeDerivative[8];       // '<S16>/ComputeDerivative'
    real_T Seletion;                   // '<S3>/Chart'
    boolean_T Terminate;               // '<Root>/TriggerTermination'
    boolean_T TakeOffTrigger;          // '<Root>/TASgreaterthan15for1Sec'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_codegenReal2Mission_T {
    uav_sluav_internal_system_Way_T obj;// '<Root>/TrackSimPath'
    uav_sluav_internal_system_Orb_T obj_m;// '<S3>/TakeOffGathering'
    robotics_core_internal_syst_b_T obj_a;// '<S16>/ComputeDerivative'
    real_T Delay_DSTATE;               // '<S3>/Delay'
    real_T Speed2d3Path_DSTATE[20];    // '<S7>/Speed2d3Path'
    real_T EastSequence_X[60];         // '<S4>/EastSequence'
    real_T HeightSequence_X[60];       // '<S4>/HeightSequence'
    real_T NorthSequence_X[60];        // '<S4>/NorthSequence'
    real_T Memory_PreviousInput;       // '<S3>/Memory'
    real_T Memory1_PreviousInput;      // '<S3>/Memory1'
    real_T AltitudeGCS;                // '<Root>/AltitudeGCS'
    real_T LatitudeGCS;                // '<Root>/LatitudeGCS'
    real_T LongitudeGCS;               // '<Root>/LongitudeGCS'
    real_T numMissionUAV;              // '<Root>/numMissionUAV'
    real_T DataCounter;                // '<Root>/TriggerTermination'
    real_T DataCounter_j;              // '<Root>/TASgreaterthan15for1Sec'
    real_T PrevY;                      // '<S12>/ClimbRateLimiter'
    struct {
      void *LoggedData[9];
    } ModelLogging_PWORK;              // '<Root>/ModelLogging'

    int32_T UAVidx;                    // '<Root>/UAVidx'
    uint8_T is_active_c4_codegenReal2Missio;// '<Root>/TriggerTermination'
    uint8_T is_c4_codegenReal2Mission; // '<Root>/TriggerTermination'
    uint8_T is_active_c1_codegenReal2Missio;// '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_c1_codegenReal2Mission; // '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_active_c10_codegenReal2Missi;// '<S3>/Chart'
    uint8_T is_c10_codegenReal2Mission;// '<S3>/Chart'
    boolean_T icLoad;                  // '<S3>/Delay'
  };

  // Continuous states (default storage)
  struct X_codegenReal2Mission_T {
    real_T Integrator2_CSTATE;         // '<S71>/Integrator2'
    real_T Integrator3_CSTATE;         // '<S73>/Integrator3'
    real_T Integrator2_CSTATE_l;       // '<S73>/Integrator2'
    real_T Integrator1_CSTATE;         // '<S71>/Integrator1'
    real_T Integrator_CSTATE;          // '<S71>/Integrator'
    real_T Integrator_CSTATE_g[8];     // '<S16>/Integrator'
  };

  // State derivatives (default storage)
  struct XDot_codegenReal2Mission_T {
    real_T Integrator2_CSTATE;         // '<S71>/Integrator2'
    real_T Integrator3_CSTATE;         // '<S73>/Integrator3'
    real_T Integrator2_CSTATE_l;       // '<S73>/Integrator2'
    real_T Integrator1_CSTATE;         // '<S71>/Integrator1'
    real_T Integrator_CSTATE;          // '<S71>/Integrator'
    real_T Integrator_CSTATE_g[8];     // '<S16>/Integrator'
  };

  // State disabled
  struct XDis_codegenReal2Mission_T {
    boolean_T Integrator2_CSTATE;      // '<S71>/Integrator2'
    boolean_T Integrator3_CSTATE;      // '<S73>/Integrator3'
    boolean_T Integrator2_CSTATE_l;    // '<S73>/Integrator2'
    boolean_T Integrator1_CSTATE;      // '<S71>/Integrator1'
    boolean_T Integrator_CSTATE;       // '<S71>/Integrator'
    boolean_T Integrator_CSTATE_g[8];  // '<S16>/Integrator'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX_codegenReal2Mission_T {
    ZCSigState Integrator2_Reset_ZCE;  // '<S71>/Integrator2'
    ZCSigState Integrator3_Reset_ZCE;  // '<S73>/Integrator3'
    ZCSigState Integrator2_Reset_ZCE_i;// '<S73>/Integrator2'
    ZCSigState Integrator1_Reset_ZCE;  // '<S71>/Integrator1'
    ZCSigState Integrator_Reset_ZCE;   // '<S71>/Integrator'
  };

  // Invariant block signals (default storage)
  struct ConstB_codegenReal2Mission_T {
    real_T Sum;                        // '<S64>/Sum'
    real_T Product1;                   // '<S65>/Product1'
    real_T Sum1;                       // '<S65>/Sum1'
    real_T sqrt_l;                     // '<S65>/sqrt'
    real_T Product2;                   // '<S60>/Product2'
    real_T Sum1_f;                     // '<S60>/Sum1'
    real_T UnitConversion;             // '<S61>/Unit Conversion'
    real_T SinCos_o1;                  // '<S46>/SinCos'
    real_T SinCos_o2;                  // '<S46>/SinCos'
    real_T UnitConversion_l;           // '<S37>/Unit Conversion'
    real_T Sum_m;                      // '<S41>/Sum'
    real_T Product1_i;                 // '<S42>/Product1'
    real_T Sum1_fg;                    // '<S42>/Sum1'
    real_T sqrt_c;                     // '<S42>/sqrt'
    real_T Product2_m;                 // '<S38>/Product2'
    real_T Sum1_m;                     // '<S38>/Sum1'
    real_T SinCos_o1_l;                // '<S23>/SinCos'
    real_T SinCos_o2_o;                // '<S23>/SinCos'
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
                                          //  Referenced by: '<S14>/AltitudeGCS'

    real_T GCS_Latitude;               // Variable: GCS_Latitude
                                          //  Referenced by: '<S14>/LatitudeGCS'

    real_T GCS_Longitude;              // Variable: GCS_Longitude
                                          //  Referenced by: '<S14>/LongitudeGCS'

    real_T numMissionUAV;              // Variable: numMissionUAV
                                          //  Referenced by: '<S14>/Number Of Mission UAV'

    int32_T UAVidx;                    // Variable: UAVidx
                                          //  Referenced by: '<S14>/UAVidx'

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
    real_T odeY[13];
    real_T odeF[4][13];
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

  // private member function(s) for subsystem '<S71>/fal(e,0.25,h)'
  static void codegenReal2Mission_fale025h(real_T rtu_u, real_T rtu_u_a, real_T
    rtu_u_c, real_T *rty_y);

  // private member function(s) for subsystem '<S72>/fhan(e1,ce2,r,h1)'
  static void codegenReal2Missio_fhane1ce2rh1(real_T rtu_u, real_T rtu_u_e,
    real_T rtu_u_h, real_T rtu_u_d, real_T *rty_fh);

  // private member function(s) for subsystem '<Root>'
  void WaypointFollowerBase_getDistinc(const real_T waypoints[183], real_T
    distinctWpts_data[], int32_T distinctWpts_size[2]);
  void codegenReal2Miss_emxInit_real_T(emxArray_real_T_codegenReal2M_T
    **pEmxArray, int32_T numDimensions);
  real_T codegenReal2Mission_norm_b(const real_T x[3]);
  void codege_emxEnsureCapacity_real_T(emxArray_real_T_codegenReal2M_T *emxArray,
    int32_T oldNumel);
  void codegenReal2Miss_emxFree_real_T(emxArray_real_T_codegenReal2M_T
    **pEmxArray);
  real_T codegenReal2Mission_angdiff(real_T x, real_T y);
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
//  Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S16>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<Root>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S71>/Gain2' : Eliminated nontunable gain of 1


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
//  '<S2>'   : 'codegenReal2Mission/EngagementTruthTable'
//  '<S3>'   : 'codegenReal2Mission/FlightMission'
//  '<S4>'   : 'codegenReal2Mission/GenerateTrack'
//  '<S5>'   : 'codegenReal2Mission/LatLon2NorthEast'
//  '<S6>'   : 'codegenReal2Mission/NorthEast2LatLon'
//  '<S7>'   : 'codegenReal2Mission/SpeedControl'
//  '<S8>'   : 'codegenReal2Mission/TASgreaterthan15for1Sec'
//  '<S9>'   : 'codegenReal2Mission/TriggerTermination'
//  '<S10>'  : 'codegenReal2Mission/VisualizeSimUAV'
//  '<S11>'  : 'codegenReal2Mission/FlightMission/Chart'
//  '<S12>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV'
//  '<S13>'  : 'codegenReal2Mission/FlightMission/Ramp'
//  '<S14>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/InitializeSimLocation'
//  '<S15>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimHeadingControl'
//  '<S16>'  : 'codegenReal2Mission/FlightMission/MissionSimUAV/SimUAV'
//  '<S17>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians'
//  '<S18>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians1'
//  '<S19>'  : 'codegenReal2Mission/LatLon2NorthEast/Degrees to Radians2'
//  '<S20>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth'
//  '<S21>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S22>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S23>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S24>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S25>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S26>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S27>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S28>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S29>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S30>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S31>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S32>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S33>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S34>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S35>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S36>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S37>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S38>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S39>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S40>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S41>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S42>'  : 'codegenReal2Mission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S43>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA'
//  '<S44>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S45>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S46>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S47>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S48>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S49>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S50>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S51>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S52>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S53>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S54>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S55>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S56>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S57>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S58>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S59>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S60>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S61>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S62>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S63>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S64>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S65>'  : 'codegenReal2Mission/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S66>'  : 'codegenReal2Mission/SpeedControl/ADRC'
//  '<S67>'  : 'codegenReal2Mission/SpeedControl/Range2CurrentSim'
//  '<S68>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track1d3'
//  '<S69>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track2d3'
//  '<S70>'  : 'codegenReal2Mission/SpeedControl/RangeSim2Track3d3'
//  '<S71>'  : 'codegenReal2Mission/SpeedControl/ADRC/ESO'
//  '<S72>'  : 'codegenReal2Mission/SpeedControl/ADRC/NLSEF'
//  '<S73>'  : 'codegenReal2Mission/SpeedControl/ADRC/TD'
//  '<S74>'  : 'codegenReal2Mission/SpeedControl/ADRC/ESO/fal(e,0.25,h)'
//  '<S75>'  : 'codegenReal2Mission/SpeedControl/ADRC/ESO/fal(e,0.5,h)'
//  '<S76>'  : 'codegenReal2Mission/SpeedControl/ADRC/NLSEF/fhan(e1,ce2,r,h1)'
//  '<S77>'  : 'codegenReal2Mission/SpeedControl/ADRC/TD/fhan(v1-v0,v2,r0,h)1'

#endif                                 // RTW_HEADER_codegenReal2Mission_h_

//
// File trailer for generated code.
//
// [EOF]
//
