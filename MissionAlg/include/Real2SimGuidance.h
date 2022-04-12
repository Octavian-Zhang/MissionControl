//
// File: Real2SimGuidance.h
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.129
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Tue Apr 12 09:26:29 2022
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

// Shared type includes
#include "model_reference_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Block signals and states (default storage) for model 'Real2SimGuidance'
struct DW_Real2SimGuidance_f_T {
    uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T obj;// '<S63>/TrackSimPath' 
    real_T Integrator[3];              // '<S86>/Integrator'
    real_T estimatedExtendedStateDerivative[3];
                                      // '<S86>/Linear extended state observer'
    real_T SwitchLookAheadNED[3];      // '<S63>/SwitchLookAheadNED'
    real_T EastSequence_X[216];        // '<S62>/EastSequence'
    real_T HeightSequence_X[216];      // '<S62>/HeightSequence'
    real_T NorthSequence_X[216];       // '<S62>/NorthSequence'
    real_T ADRC_Log[4];                // '<Root>/ADRC_Log'
    real_T Heading_Log[3];             // '<Root>/Heading_Log'
    real_T MatrixConcatenate[651];     // '<S62>/Matrix Concatenate'
    real_T waypoints_data[651];
    real_T b_waypointsIn_data[651];
    real_T HeadWind;                   // '<S6>/Minus'
    real_T BiasHSwitch;                // '<S6>/BiasHSwitch'
    real_T dotAltTD;                   // '<S68>/dotAltTD'
    real_T fh;                         // '<S68>/fhan_Alt'
    real_T Gain;                       // '<S67>/Gain'
    real_T AirSpeed;
    real_T Switch_p;                   // '<S81>/Switch'
    real_T Tsamp;                      // '<S125>/Tsamp'
    real_T Sum;                        // '<S139>/Sum'
    real_T Product;                    // '<S94>/Product'
    real_T biasHm70;                   // '<S74>/biasHm70'
    real_T SimHdg;                     // '<S69>/MissionSwitchInitialPersuit'
    real_T Gain_b;                     // '<S71>/Gain'
    real_T Execution;                  // '<Root>/EngagementDebouncer'
    real_T UD_DSTATE;                  // '<S123>/UD'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S69>/Discrete-Time Integrator'
    real_T CrossTrackError;            // '<Root>/CrossTrackError'
    real_T EngagedFlag;                // '<Root>/EngagedFlag_Log'
    real_T FlightMode_Log;             // '<Root>/FlightMode_Log'
    real_T LagDistance;                // '<Root>/LagDistance'
    real_T biasH_Log;                  // '<Root>/biasH_Log'
    real_T MemoryRefHeight_PreviousInput;// '<S64>/MemoryRefHeight'
    int32_T durationCounter_1;         // '<Root>/TASgreaterthan15for1Sec'
    uint32_T temporalCounter_i1;       // '<S69>/MissionSwitchInitialPersuit'
    uint16_T temporalCounter_i1_o;     // '<Root>/EngagementDebouncer'
    int8_T DiscreteTimeIntegrator_PrevResetState;// '<S69>/Discrete-Time Integrator' 
    uint8_T Engaged;                   // '<S6>/Engagement'
    uint8_T HdgStatus_Log;             // '<Root>/Status_Log'
    uint8_T is_active_c16_Real2SimGuidance;// '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_c16_Real2SimGuidance;   // '<Root>/TASgreaterthan15for1Sec'
    uint8_T Memory_PreviousInput;      // '<S6>/Memory'
    uint8_T is_active_c6_Real2SimGuidance;// '<S81>/ControlLogic'
    uint8_T is_c6_Real2SimGuidance;    // '<S81>/ControlLogic'
    uint8_T is_Debounce;               // '<S81>/ControlLogic'
    uint8_T temporalCounter_i1_c;      // '<S81>/ControlLogic'
    uint8_T is_active_c3_Real2SimGuidance;// '<S69>/MissionSwitchInitialPersuit' 
    uint8_T is_c3_Real2SimGuidance;    // '<S69>/MissionSwitchInitialPersuit'
    uint8_T is_Normal;                 // '<S69>/MissionSwitchInitialPersuit'
    uint8_T is_Debounce_i;             // '<S69>/MissionSwitchInitialPersuit'
    uint8_T temporalCounter_i2;        // '<S69>/MissionSwitchInitialPersuit'
    uint8_T is_active_c2_Real2SimGuidance;// '<S6>/Chart'
    uint8_T is_c2_Real2SimGuidance;    // '<S6>/Chart'
    uint8_T is_active_c34_Real2SimGuidance;// '<Root>/EngagementDebouncer'
    uint8_T is_c34_Real2SimGuidance;   // '<Root>/EngagementDebouncer'
    uint8_T is_Persuit;                // '<Root>/EngagementDebouncer'
    uint8_T is_Debounce_id;            // '<Root>/EngagementDebouncer'
    uint8_T is_L0Engaged;              // '<Root>/EngagementDebouncer'
    uint8_T is_L0Default;              // '<Root>/EngagementDebouncer'
    uint8_T is_Debounce_a;             // '<Root>/EngagementDebouncer'
    uint8_T temporalCounter_i2_n;      // '<Root>/EngagementDebouncer'
    boolean_T Compare;                 // '<S60>/Compare'
    boolean_T PD_U;                    // '<S81>/ControlLogic'
    boolean_T EnablePD;                // '<S81>/ControlLogic'
    boolean_T EnableADRC;              // '<S81>/ControlLogic'
    boolean_T MemoryNotInBrake_PreviousInput;// '<S6>/MemoryNotInBrake'
    boolean_T objisempty;              // '<S63>/TrackSimPath'
    boolean_T SpdFBControl_MODE;       // '<S67>/SpdFBControl'
    boolean_T PD_MODE;                 // '<S81>/PD'
    boolean_T ADRC_MODE;               // '<S81>/ADRC'
};

// Continuous states for model 'Real2SimGuidance'
struct X_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;              // '<S68>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S68>/dotAltTD'
    real_T Integrator_CSTATE[3];       // '<S86>/Integrator'
};

// State derivatives for model 'Real2SimGuidance'
struct XDot_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;              // '<S68>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S68>/dotAltTD'
    real_T Integrator_CSTATE[3];       // '<S86>/Integrator'
};

// State Disabled for model 'Real2SimGuidance'
struct XDis_Real2SimGuidance_n_T {
    boolean_T TD_Alt_CSTATE;           // '<S68>/TD_Alt'
    boolean_T dotAltTD_CSTATE;         // '<S68>/dotAltTD'
    boolean_T Integrator_CSTATE[3];    // '<S86>/Integrator'
};

// Real-time Model Data Structure
struct tag_RTM_Real2SimGuidance_T {
    const char_T **errorStatus;
    RTWSolverInfo *solverInfo;
    const rtTimingBridge *timingBridge;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
        time_T stepSize0;
        int_T mdlref_GlobalTID[2];
        SimTimeStep *simTimeStep;
        boolean_T *stopRequestedFlag;
    } Timing;
};

struct MdlrefDW_Real2SimGuidance_T {
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
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
    *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
    RT_MODEL_Real2SimGuidance_T *const Real2SimGuidance_M);
extern void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX);
extern void Real2SimGuidance_Reset(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX);
extern void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot);
extern void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW);
extern void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const boolean_T *rtu_NewMission, const
    FixedWingGuidanceStateBus *rtu_SimUAVState, DW_Real2SimGuidance_f_T *localDW);
extern void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const boolean_T *rtu_NewMission, const uint8_T
    *rtu_FlightMode, const StateFCU *rtu_StateFCU, const boolean_T
    rtu_ControlSwitch[2], const FixedWingGuidanceStateBus *rtu_SimUAVState,
    const FixedWingGuidanceBus *rtu_ImmedGuidanceCMD, const real_T
    *rtu_BiasRatio, const real_T *rtu_ParamADRC_hat_b, const real_T
    *rtu_ParamADRC_omega_o, const real_T *rtu_ParamADRC_omega_b, const real_T
    *rtu_ParamADRC_P, const real_T *rtu_ParamADRC_D, FCUCMD *rty_FCUCMD, uint8_T
    *rty_EngagedFlag, FlightLogging *rty_FlightLogging, DW_Real2SimGuidance_f_T *
    localDW, X_Real2SimGuidance_n_T *localX);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S63>/SwitchDesiredYaw' : Unused code path elimination
//  Block '<S123>/DTDup' : Unused code path elimination
//  Block '<Root>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S67>/ZOH_ADRC_LagDis' : Eliminated since input and output rates are identical


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
//  '<S1>'   : 'Real2SimGuidance/Enabled Subsystem'
//  '<S2>'   : 'Real2SimGuidance/EngagementDebouncer'
//  '<S3>'   : 'Real2SimGuidance/FlightPathFromVectorSpd'
//  '<S4>'   : 'Real2SimGuidance/LatLon2NorthEast'
//  '<S5>'   : 'Real2SimGuidance/NorthEast2LatLon'
//  '<S6>'   : 'Real2SimGuidance/Real2SimNav'
//  '<S7>'   : 'Real2SimGuidance/TASgreaterthan15for1Sec'
//  '<S8>'   : 'Real2SimGuidance/TimeNow'
//  '<S9>'   : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians'
//  '<S10>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians1'
//  '<S11>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians2'
//  '<S12>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth'
//  '<S13>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S14>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S15>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S16>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S17>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S18>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S19>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S20>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S21>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S22>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S23>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S24>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S25>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S26>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S27>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S28>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S29>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S30>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S31>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S32>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S33>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S34>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S35>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA'
//  '<S36>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S37>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S38>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S39>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S40>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S41>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S42>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S43>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S44>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S45>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S46>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S47>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S48>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S49>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S50>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S51>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S52>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S53>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S54>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S55>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S56>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S57>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S58>'  : 'Real2SimGuidance/Real2SimNav/AngLog'
//  '<S59>'  : 'Real2SimGuidance/Real2SimNav/Chart'
//  '<S60>'  : 'Real2SimGuidance/Real2SimNav/Compare To Zero'
//  '<S61>'  : 'Real2SimGuidance/Real2SimNav/Engagement'
//  '<S62>'  : 'Real2SimGuidance/Real2SimNav/GenerateTrack'
//  '<S63>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic'
//  '<S64>'  : 'Real2SimGuidance/Real2SimNav/HeadingNaNProtection'
//  '<S65>'  : 'Real2SimGuidance/Real2SimNav/MaxBrake'
//  '<S66>'  : 'Real2SimGuidance/Real2SimNav/PointingMode'
//  '<S67>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl'
//  '<S68>'  : 'Real2SimGuidance/Real2SimNav/TD'
//  '<S69>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg'
//  '<S70>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/RefHdg'
//  '<S71>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg/CalForwardShift'
//  '<S72>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg/MissionSwitchInitialPersuit'
//  '<S73>'  : 'Real2SimGuidance/Real2SimNav/MaxBrake/Calculate Brake Range'
//  '<S74>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/EnableBias'
//  '<S75>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/L0RangeSim2Track1d3'
//  '<S76>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/L0RangeSim2Track3d3'
//  '<S77>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/L1RangeSim2Track1d3'
//  '<S78>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/L1RangeSim2Track3d3'
//  '<S79>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/Range2CurrentSim'
//  '<S80>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track2d3'
//  '<S81>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl'
//  '<S82>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC'
//  '<S83>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ControlLogic'
//  '<S84>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD'
//  '<S85>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller'
//  '<S86>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Linear extended state observer'
//  '<S87>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Observer output'
//  '<S88>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller'
//  '<S89>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Linear extended state observer/Linear extended state observer'
//  '<S90>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Observer output/Whole estimated extended state'
//  '<S91>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Dead time'
//  '<S92>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Extended state feedback robust controller'
//  '<S93>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Saturation'
//  '<S94>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Dead time/Dead time on'
//  '<S95>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Saturation/Saturation off'
//  '<S96>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller'
//  '<S97>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Anti-windup'
//  '<S98>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/D Gain'
//  '<S99>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Filter'
//  '<S100>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Filter ICs'
//  '<S101>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/I Gain'
//  '<S102>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Ideal P Gain'
//  '<S103>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S104>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Integrator'
//  '<S105>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Integrator ICs'
//  '<S106>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/N Copy'
//  '<S107>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/N Gain'
//  '<S108>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/P Copy'
//  '<S109>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Parallel P Gain'
//  '<S110>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Reset Signal'
//  '<S111>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Saturation'
//  '<S112>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Saturation Fdbk'
//  '<S113>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Sum'
//  '<S114>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Sum Fdbk'
//  '<S115>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Tracking Mode'
//  '<S116>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Tracking Mode Sum'
//  '<S117>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Tsamp - Integral'
//  '<S118>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Tsamp - Ngain'
//  '<S119>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/postSat Signal'
//  '<S120>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/preSat Signal'
//  '<S121>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Anti-windup/Disabled'
//  '<S122>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/D Gain/External Parameters'
//  '<S123>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Filter/Differentiator'
//  '<S124>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Filter/Differentiator/Tsamp'
//  '<S125>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S126>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S127>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/I Gain/Disabled'
//  '<S128>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S129>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S130>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Integrator/Disabled'
//  '<S131>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Integrator ICs/Disabled'
//  '<S132>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S133>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/N Gain/Passthrough'
//  '<S134>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/P Copy/Disabled'
//  '<S135>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Parallel P Gain/External Parameters'
//  '<S136>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Reset Signal/Disabled'
//  '<S137>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Saturation/Passthrough'
//  '<S138>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S139>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Sum/Sum_PD'
//  '<S140>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S141>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S142>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S143>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Tsamp - Integral/Disabled wSignal Specification'
//  '<S144>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S145>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S146>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PD/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S147>' : 'Real2SimGuidance/Real2SimNav/TD/fhan_Alt'

#endif                                 // RTW_HEADER_Real2SimGuidance_h_

//
// File trailer for generated code.
//
// [EOF]
//
