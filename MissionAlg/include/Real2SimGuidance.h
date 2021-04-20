//
// File: Real2SimGuidance.h
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Apr 20 11:33:08 2021
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
#ifndef RTW_HEADER_Real2SimGuidance_h_
#define RTW_HEADER_Real2SimGuidance_h_
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Real2SimGuidance_types.h"
#include "rt_nonfinite.h"

// Block signals for model 'Real2SimGuidance'
struct B_Real2SimGuidance_c_T {
  real_T BiasHSwitch;                  // '<S4>/BiasHSwitch'
  real_T NorthEastHeight[3];           // '<S4>/NED2NEU'
  real_T dotAltTD;                     // '<S64>/dotAltTD'
  real_T fh;                           // '<S64>/fhan_Alt'
  real_T InverseY;                     // '<S63>/InverseY'
  real_T InverseR;                     // '<S63>/InverseR'
  real_T dotTD;                        // '<S74>/dotTD'
  real_T GainADRCinvb0;                // '<S67>/GainADRCinvb0'
  real_T SumY;                         // '<S67>/SumY'
  real_T fh_p;                         // '<S74>/fhan_AirSpdADRC'
  real_T ESO;                          // '<S72>/ESO'
  real_T ESO_dot;                      // '<S72>/ESO_dot'
  real_T ESO_dotdot;                   // '<S72>/ESO_dotdot'
  real_T TrackInvH;                    // '<S58>/TrackInvH'
  boolean_T Terminate;                 // '<Root>/TriggerTermination'
  boolean_T Compare;                   // '<S62>/Compare'
};

// Block states (default storage) for model 'Real2SimGuidance'
struct DW_Real2SimGuidance_f_T {
  uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T obj;// '<S59>/TrackSimPath' 
  real_T EastSequence_X[72];           // '<S58>/EastSequence'
  real_T HeightSequence_X[72];         // '<S58>/HeightSequence'
  real_T NorthSequence_X[72];          // '<S58>/NorthSequence'
  real_T MemoryExecutionTrigger_PreviousInput;// '<Root>/MemoryExecutionTrigger' 
  real_T ADRC_U_Log;                   // '<Root>/ADRC_U_Log'
  real_T CrossTrackError;              // '<Root>/CrossTrackError'
  real_T Heading_Log[3];               // '<Root>/Heading_Log'
  real_T LagDistance;                  // '<Root>/LagDistance'
  real_T biasH_Log;                    // '<Root>/biasH_Log'
  real_T DataCounter;                  // '<Root>/TriggerTermination'
  real_T ReturnCounter;                // '<Root>/TriggerTermination'
  real_T Count;                        // '<Root>/TASgreaterthan15for1Sec'
  real_T MemoryRefHeight_PreviousInput;// '<S60>/MemoryRefHeight'
  uint8_T FlightMode_Log;              // '<Root>/FlightMode_Log'
  uint8_T Status_Log;                  // '<Root>/Status_Log'
  uint8_T is_active_c34_Real2SimGuidance;// '<Root>/TriggerTermination'
  uint8_T is_c34_Real2SimGuidance;     // '<Root>/TriggerTermination'
  uint8_T is_active_c16_Real2SimGuidance;// '<Root>/TASgreaterthan15for1Sec'
  uint8_T is_c16_Real2SimGuidance;     // '<Root>/TASgreaterthan15for1Sec'
  boolean_T objisempty;                // '<S59>/TrackSimPath'
  boolean_T ESO_MODE;                  // '<S67>/ESO'
};

// Continuous states for model 'Real2SimGuidance'
struct X_Real2SimGuidance_n_T {
  real_T TD_Alt_CSTATE;                // '<S64>/TD_Alt'
  real_T dotAltTD_CSTATE;              // '<S64>/dotAltTD'
  real_T TD_AirSpdADRC_CSTATE;         // '<S74>/TD_AirSpdADRC'
  real_T dotTD_CSTATE;                 // '<S74>/dotTD'
  real_T ESO_CSTATE;                   // '<S72>/ESO'
  real_T ESO_dot_CSTATE;               // '<S72>/ESO_dot'
  real_T ESO_dotdot_CSTATE;            // '<S72>/ESO_dotdot'
};

// State derivatives for model 'Real2SimGuidance'
struct XDot_Real2SimGuidance_n_T {
  real_T TD_Alt_CSTATE;                // '<S64>/TD_Alt'
  real_T dotAltTD_CSTATE;              // '<S64>/dotAltTD'
  real_T TD_AirSpdADRC_CSTATE;         // '<S74>/TD_AirSpdADRC'
  real_T dotTD_CSTATE;                 // '<S74>/dotTD'
  real_T ESO_CSTATE;                   // '<S72>/ESO'
  real_T ESO_dot_CSTATE;               // '<S72>/ESO_dot'
  real_T ESO_dotdot_CSTATE;            // '<S72>/ESO_dotdot'
};

// State Disabled for model 'Real2SimGuidance'
struct XDis_Real2SimGuidance_n_T {
  boolean_T TD_Alt_CSTATE;             // '<S64>/TD_Alt'
  boolean_T dotAltTD_CSTATE;           // '<S64>/dotAltTD'
  boolean_T TD_AirSpdADRC_CSTATE;      // '<S74>/TD_AirSpdADRC'
  boolean_T dotTD_CSTATE;              // '<S74>/dotTD'
  boolean_T ESO_CSTATE;                // '<S72>/ESO'
  boolean_T ESO_dot_CSTATE;            // '<S72>/ESO_dot'
  boolean_T ESO_dotdot_CSTATE;         // '<S72>/ESO_dotdot'
};

// Invariant block signals for model 'Real2SimGuidance'
struct ConstB_Real2SimGuidance_h_T {
  real_T UnitConversion;               // '<S27>/Unit Conversion'
  real_T Sum;                          // '<S31>/Sum'
  real_T Product1;                     // '<S32>/Product1'
  real_T Sum1;                         // '<S32>/Sum1'
  real_T sqrt_e;                       // '<S32>/sqrt'
  real_T Product2;                     // '<S28>/Product2'
  real_T Sum1_h;                       // '<S28>/Sum1'
  real_T SinCos_o1;                    // '<S13>/SinCos'
  real_T SinCos_o2;                    // '<S13>/SinCos'
  real_T Sum_p;                        // '<S54>/Sum'
  real_T Product1_f;                   // '<S55>/Product1'
  real_T Sum1_g;                       // '<S55>/Sum1'
  real_T sqrt_g;                       // '<S55>/sqrt'
  real_T Product2_c;                   // '<S50>/Product2'
  real_T Sum1_o;                       // '<S50>/Sum1'
  real_T UnitConversion_g;             // '<S51>/Unit Conversion'
  real_T SinCos_o1_f;                  // '<S36>/SinCos'
  real_T SinCos_o2_b;                  // '<S36>/SinCos'
};

// Real-time Model Data Structure
struct tag_RTM_Real2SimGuidance_T {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
    boolean_T *stopRequestedFlag;
  } Timing;
};

struct MdlrefDW_Real2SimGuidance_T {
  B_Real2SimGuidance_c_T rtb;
  DW_Real2SimGuidance_f_T rtdw;
  RT_MODEL_Real2SimGuidance_T rtm;
};

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

// Model reference registration function
extern void Real2SimGuidance_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_Real2SimGuidance_T *
  const Real2SimGuidance_M);
extern void Real2SimGuidance_fale025h(real_T rtu_u, real_T rtu_u_j, real_T
  rtu_u_e, real_T *rty_y);
extern void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
  X_Real2SimGuidance_n_T *localX);
extern void Real2SimGuidance_Deriv(B_Real2SimGuidance_c_T *localB,
  DW_Real2SimGuidance_f_T *localDW, XDot_Real2SimGuidance_n_T *localXdot);
extern void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW);
extern void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
  Real2SimGuidance_M, real_T *rty_ExecutionTrigger, B_Real2SimGuidance_c_T
  *localB, DW_Real2SimGuidance_f_T *localDW);
extern void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const
  Real2SimGuidance_M, const real_T *rtu_SimUAVState_North, const real_T
  *rtu_SimUAVState_East, const real_T *rtu_SimUAVState_Height, const real_T
  *rtu_SimUAVState_AirSpeed, const real_T *rtu_SimUAVState_HeadingAngle, const
  RealUAVStateBus *rtu_RealUAVLatLonState, const uint8_T *rtu_FlightMode, const
  real_T *rtu_GroundSpd, LookAheadPoint *rty_LookAheadPoint, real_T
  *rty_RefAirspeed, real_T *rty_ExecutionTrigger, boolean_T *rty_EngagedFlag,
  B_Real2SimGuidance_c_T *localB, DW_Real2SimGuidance_f_T *localDW,
  X_Real2SimGuidance_n_T *localX);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Atan2' : Unused code path elimination
//  Block '<Root>/ModelLogging' : Unused code path elimination
//  Block '<S59>/SwitchDesiredYaw' : Unused code path elimination
//  Block '<S63>/AirspeedZOH' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'Real2SimGuidance'
//  '<S1>'   : 'Real2SimGuidance/FlightPathFromVectorSpd'
//  '<S2>'   : 'Real2SimGuidance/LatLon2NorthEast'
//  '<S3>'   : 'Real2SimGuidance/NorthEast2LatLon'
//  '<S4>'   : 'Real2SimGuidance/Real2SimNav'
//  '<S5>'   : 'Real2SimGuidance/TASgreaterthan15for1Sec'
//  '<S6>'   : 'Real2SimGuidance/TriggerTermination'
//  '<S7>'   : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians'
//  '<S8>'   : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians1'
//  '<S9>'   : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians2'
//  '<S10>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth'
//  '<S11>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S12>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S13>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S14>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S15>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S16>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S17>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S18>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S19>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S20>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S21>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S22>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S23>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S24>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S25>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S26>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S27>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S28>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S29>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S30>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S31>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S32>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S33>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA'
//  '<S34>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S35>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S36>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S37>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S38>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S39>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S40>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S41>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S42>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S43>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S44>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S45>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S46>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S47>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S48>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S49>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S50>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S51>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S52>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S53>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S54>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S55>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S56>'  : 'Real2SimGuidance/Real2SimNav/AngLog'
//  '<S57>'  : 'Real2SimGuidance/Real2SimNav/Engagement'
//  '<S58>'  : 'Real2SimGuidance/Real2SimNav/GenerateTrack'
//  '<S59>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic'
//  '<S60>'  : 'Real2SimGuidance/Real2SimNav/HeadingNaNProtection'
//  '<S61>'  : 'Real2SimGuidance/Real2SimNav/MaxBrake'
//  '<S62>'  : 'Real2SimGuidance/Real2SimNav/PointingMode'
//  '<S63>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl'
//  '<S64>'  : 'Real2SimGuidance/Real2SimNav/TD'
//  '<S65>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/RefHdg'
//  '<S66>'  : 'Real2SimGuidance/Real2SimNav/MaxBrake/Calculate Brake Range'
//  '<S67>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/ADRC'
//  '<S68>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/Range2CurrentSim'
//  '<S69>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track1d3'
//  '<S70>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track2d3'
//  '<S71>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track3d3'
//  '<S72>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/ESO'
//  '<S73>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/NLSEF'
//  '<S74>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/TD'
//  '<S75>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/ESO/fal(e,0.25,h)'
//  '<S76>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/ESO/fal(e,0.5,h)'
//  '<S77>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/NLSEF/fhan(e1,ce2,r,h1)'
//  '<S78>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/ADRC/TD/fhan_AirSpdADRC'
//  '<S79>'  : 'Real2SimGuidance/Real2SimNav/TD/fhan_Alt'

#endif                                 // RTW_HEADER_Real2SimGuidance_h_

//
// File trailer for generated code.
//
// [EOF]
//
