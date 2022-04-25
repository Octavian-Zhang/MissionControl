//
// File: Real2SimGuidance.h
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.146
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun Apr 24 02:58:34 2022
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
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Real2SimGuidance_types.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include "rtGetInf.h"
#include "model_reference_types.h"

// Block signals and states (default storage) for model 'Real2SimGuidance'
struct DW_Real2SimGuidance_f_T {
    uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T obj;// '<S65>/TrackSimPath' 
    DubinsObjSingleton_Real2SimGuidance_T SingletonInstance;// '<Root>/Get Nominal Flight Speed' 
    real_T VectorConcatenate[4];       // '<S83>/Vector Concatenate'
    real_T estimatedExtendedStateDerivative[3];
                                      // '<S88>/Linear extended state observer'
    real_T SwitchLookAheadNED[3];      // '<S65>/SwitchLookAheadNED'
    real_T EastSequence_X[216];        // '<S64>/EastSequence'
    real_T HeightSequence_X[216];      // '<S64>/HeightSequence'
    real_T NorthSequence_X[216];       // '<S64>/NorthSequence'
    real_T ADRC_Log[4];                // '<Root>/ADRC_Log'
    real_T Heading_Log[3];             // '<Root>/Heading_Log'
    real_T MatrixConcatenate[651];     // '<S64>/Matrix Concatenate'
    real_T waypoints_data[651];
    real_T b_waypointsIn_data[651];
    real_T BiasHSwitch;                // '<S8>/BiasHSwitch'
    real_T dotAltTD;                   // '<S70>/dotAltTD'
    real_T fh;                         // '<S70>/fhan_Alt'
    real_T Gain;                       // '<S69>/Gain'
    real_T Switch_p;                   // '<S83>/Switch'
    real_T Tsamp;                      // '<S127>/Tsamp'
    real_T IProdOut;                   // '<S129>/IProd Out'
    real_T Sum;                        // '<S141>/Sum'
    real_T RThat_b;                    // '<S84>/RThat_b'
    real_T RTomega_b;                  // '<S84>/RTomega_b'
    real_T RTomega_o;                  // '<S84>/RTomega_o'
    real_T RTu;                        // '<S84>/RTu'
    real_T biasHm70;                   // '<S76>/biasHm70'
    real_T SimHdg;                     // '<S71>/MissionSwitchInitialPersuit'
    real_T Gain_b;                     // '<S73>/Gain'
    real_T Execution;                  // '<Root>/EngagementDebouncer'
    real_T UD_DSTATE;                  // '<S125>/UD'
    real_T Integrator_DSTATE;          // '<S132>/Integrator'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S71>/Discrete-Time Integrator'
    real_T CrossTrackError;            // '<Root>/CrossTrackError'
    real_T EngagedFlag;                // '<Root>/EngagedFlag_Log'
    real_T FlightMode_Log;             // '<Root>/FlightMode_Log'
    real_T LagDistance;                // '<Root>/LagDistance'
    real_T biasH_Log;                  // '<Root>/biasH_Log'
    real_T MemoryRefHeight_PreviousInput;// '<S66>/MemoryRefHeight'
    int32_T durationCounter_1;         // '<Root>/TASgreaterthan15for1Sec'
    uint32_T temporalCounter_i1;       // '<S71>/MissionSwitchInitialPersuit'
    uint16_T temporalCounter_i1_i;     // '<Root>/EngagementDebouncer'
    int8_T DiscreteTimeIntegrator_PrevResetState;// '<S71>/Discrete-Time Integrator' 
    uint8_T Engaged;                   // '<S8>/Engagement'
    uint8_T HdgStatus_Log;             // '<Root>/Status_Log'
    uint8_T is_active_c16_Real2SimGuidance;// '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_c16_Real2SimGuidance;   // '<Root>/TASgreaterthan15for1Sec'
    uint8_T Memory_PreviousInput;      // '<S8>/Memory'
    uint8_T is_active_c6_Real2SimGuidance;// '<S83>/ControlLogic'
    uint8_T is_c6_Real2SimGuidance;    // '<S83>/ControlLogic'
    uint8_T is_useADRC;                // '<S83>/ControlLogic'
    uint8_T is_Debounce;               // '<S83>/ControlLogic'
    uint8_T temporalCounter_i1_n;      // '<S83>/ControlLogic'
    uint8_T is_active_c3_Real2SimGuidance;// '<S71>/MissionSwitchInitialPersuit' 
    uint8_T is_c3_Real2SimGuidance;    // '<S71>/MissionSwitchInitialPersuit'
    uint8_T is_Normal;                 // '<S71>/MissionSwitchInitialPersuit'
    uint8_T is_Debounce_m;             // '<S71>/MissionSwitchInitialPersuit'
    uint8_T temporalCounter_i2;        // '<S71>/MissionSwitchInitialPersuit'
    uint8_T is_active_c2_Real2SimGuidance;// '<S8>/Chart'
    uint8_T is_c2_Real2SimGuidance;    // '<S8>/Chart'
    uint8_T is_active_c34_Real2SimGuidance;// '<Root>/EngagementDebouncer'
    uint8_T is_c34_Real2SimGuidance;   // '<Root>/EngagementDebouncer'
    uint8_T is_Persuit;                // '<Root>/EngagementDebouncer'
    uint8_T is_Debounce_m4;            // '<Root>/EngagementDebouncer'
    uint8_T is_L0Engaged;              // '<Root>/EngagementDebouncer'
    uint8_T is_L0Default;              // '<Root>/EngagementDebouncer'
    uint8_T is_Debounce_b;             // '<Root>/EngagementDebouncer'
    uint8_T temporalCounter_i2_f;      // '<Root>/EngagementDebouncer'
    boolean_T Compare;                 // '<S62>/Compare'
    boolean_T PID_U;                   // '<S83>/ControlLogic'
    boolean_T EnableADRC;              // '<S83>/ControlLogic'
    boolean_T EnablePID;               // '<S83>/ControlLogic'
    boolean_T MemoryNotInBrake_PreviousInput;// '<S8>/MemoryNotInBrake'
    boolean_T objisempty;              // '<S65>/TrackSimPath'
    boolean_T SingletonInstance_not_empty;// '<Root>/Get Nominal Flight Speed'
    boolean_T SpdFBControl_MODE;       // '<S69>/SpdFBControl'
    boolean_T PID_MODE;                // '<S83>/PID'
    boolean_T ADRC_MODE;               // '<S83>/ADRC'
};

// Continuous states for model 'Real2SimGuidance'
struct X_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;              // '<S70>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S70>/dotAltTD'
    real_T Integrator_CSTATE[3];       // '<S88>/Integrator'
};

// State derivatives for model 'Real2SimGuidance'
struct XDot_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;              // '<S70>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S70>/dotAltTD'
    real_T Integrator_CSTATE[3];       // '<S88>/Integrator'
};

// State Disabled for model 'Real2SimGuidance'
struct XDis_Real2SimGuidance_n_T {
    boolean_T TD_Alt_CSTATE;           // '<S70>/TD_Alt'
    boolean_T dotAltTD_CSTATE;         // '<S70>/dotAltTD'
    boolean_T Integrator_CSTATE[3];    // '<S88>/Integrator'
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
    *rtu_ParamADRC_P, const real_T *rtu_ParamADRC_I, const real_T
    *rtu_ParamADRC_D, const boolean_T *rtu_ParamADRC_useADRC, FCUCMD *rty_FCUCMD,
    uint8_T *rty_EngagedFlag, FlightLogging *rty_FlightLogging,
    DW_Real2SimGuidance_f_T *localDW, X_Real2SimGuidance_n_T *localX);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S14>/Data Type Duplicate' : Unused code path elimination
//  Block '<S37>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/SwitchDesiredYaw' : Unused code path elimination
//  Block '<S125>/DTDup' : Unused code path elimination
//  Block '<Root>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S69>/AirspeedZOH' : Eliminated since input and output rates are identical
//  Block '<S84>/RTErr' : Eliminated since input and output rates are identical
//  Block '<S69>/ZOH_ADRC_LagDis' : Eliminated since input and output rates are identical


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
//  '<S1>'   : 'Real2SimGuidance/Compare To Constant'
//  '<S2>'   : 'Real2SimGuidance/Enabled Subsystem'
//  '<S3>'   : 'Real2SimGuidance/EngagementDebouncer'
//  '<S4>'   : 'Real2SimGuidance/FlightPathFromVectorSpd'
//  '<S5>'   : 'Real2SimGuidance/Get Nominal Flight Speed'
//  '<S6>'   : 'Real2SimGuidance/LatLon2NorthEast'
//  '<S7>'   : 'Real2SimGuidance/NorthEast2LatLon'
//  '<S8>'   : 'Real2SimGuidance/Real2SimNav'
//  '<S9>'   : 'Real2SimGuidance/TASgreaterthan15for1Sec'
//  '<S10>'  : 'Real2SimGuidance/TimeNow'
//  '<S11>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians'
//  '<S12>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians1'
//  '<S13>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians2'
//  '<S14>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth'
//  '<S15>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S16>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S17>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S18>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S19>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S20>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S21>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S22>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S23>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S24>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S25>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S26>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S27>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S28>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S29>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S30>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S31>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S32>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S33>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S34>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S35>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S36>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S37>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA'
//  '<S38>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S39>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S40>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S41>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S42>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S43>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S44>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S45>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S46>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S47>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S48>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S49>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S50>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S51>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S52>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S53>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S54>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S55>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S56>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S57>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S58>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S59>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S60>'  : 'Real2SimGuidance/Real2SimNav/AngLog'
//  '<S61>'  : 'Real2SimGuidance/Real2SimNav/Chart'
//  '<S62>'  : 'Real2SimGuidance/Real2SimNav/Compare To Zero'
//  '<S63>'  : 'Real2SimGuidance/Real2SimNav/Engagement'
//  '<S64>'  : 'Real2SimGuidance/Real2SimNav/GenerateTrack'
//  '<S65>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic'
//  '<S66>'  : 'Real2SimGuidance/Real2SimNav/HeadingNaNProtection'
//  '<S67>'  : 'Real2SimGuidance/Real2SimNav/MaxBrake'
//  '<S68>'  : 'Real2SimGuidance/Real2SimNav/PointingMode'
//  '<S69>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl'
//  '<S70>'  : 'Real2SimGuidance/Real2SimNav/TD'
//  '<S71>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg'
//  '<S72>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/RefHdg'
//  '<S73>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg/CalForwardShift'
//  '<S74>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg/MissionSwitchInitialPersuit'
//  '<S75>'  : 'Real2SimGuidance/Real2SimNav/MaxBrake/Calculate Brake Range'
//  '<S76>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/EnableBias'
//  '<S77>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/L0RangeSim2Track1d3'
//  '<S78>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/L0RangeSim2Track3d3'
//  '<S79>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/L1RangeSim2Track1d3'
//  '<S80>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/L1RangeSim2Track3d3'
//  '<S81>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/Range2CurrentSim'
//  '<S82>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track2d3'
//  '<S83>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl'
//  '<S84>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC'
//  '<S85>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ControlLogic'
//  '<S86>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID'
//  '<S87>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller'
//  '<S88>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Linear extended state observer'
//  '<S89>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Observer output'
//  '<S90>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller'
//  '<S91>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Linear extended state observer/Linear extended state observer'
//  '<S92>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Observer output/Whole estimated extended state'
//  '<S93>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Dead time'
//  '<S94>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Extended state feedback robust controller'
//  '<S95>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Saturation'
//  '<S96>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Dead time/Dead time on'
//  '<S97>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Saturation/Saturation off'
//  '<S98>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller'
//  '<S99>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Anti-windup'
//  '<S100>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/D Gain'
//  '<S101>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter'
//  '<S102>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter ICs'
//  '<S103>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/I Gain'
//  '<S104>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain'
//  '<S105>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S106>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator'
//  '<S107>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator ICs'
//  '<S108>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Copy'
//  '<S109>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Gain'
//  '<S110>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/P Copy'
//  '<S111>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Parallel P Gain'
//  '<S112>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Reset Signal'
//  '<S113>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation'
//  '<S114>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation Fdbk'
//  '<S115>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum'
//  '<S116>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum Fdbk'
//  '<S117>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode'
//  '<S118>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode Sum'
//  '<S119>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Integral'
//  '<S120>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Ngain'
//  '<S121>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/postSat Signal'
//  '<S122>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/preSat Signal'
//  '<S123>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S124>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/D Gain/External Parameters'
//  '<S125>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator'
//  '<S126>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator/Tsamp'
//  '<S127>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S128>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S129>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/I Gain/External Parameters'
//  '<S130>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S131>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S132>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator/Discrete'
//  '<S133>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S134>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S135>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Gain/Passthrough'
//  '<S136>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/P Copy/Disabled'
//  '<S137>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Parallel P Gain/External Parameters'
//  '<S138>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Reset Signal/Disabled'
//  '<S139>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation/Passthrough'
//  '<S140>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S141>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum/Sum_PID'
//  '<S142>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S143>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S144>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S145>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S146>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S147>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S148>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S149>' : 'Real2SimGuidance/Real2SimNav/TD/fhan_Alt'

#endif                                 // RTW_HEADER_Real2SimGuidance_h_

//
// File trailer for generated code.
//
// [EOF]
//
