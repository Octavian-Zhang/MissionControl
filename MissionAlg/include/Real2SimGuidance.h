//
// File: Real2SimGuidance.h
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 4.148
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri Jun  3 15:15:59 2022
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
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Real2SimGuidance_types.h"

extern "C" {

#include "rtGetNaN.h"

}
    extern "C"
{

#include "rt_nonfinite.h"

}

extern "C" {

#include "rtGetInf.h"

}
#include "model_reference_types.h"

// Block signals and states (default storage) for model 'Real2SimGuidance'
struct DW_Real2SimGuidance_f_T {
    FILE* eml_openfiles[20];           // '<S14>/getLAPGainBias'
    FILE* eml_openfiles_o[20];         // '<Root>/Get Nominal Flight Speed'
    FILE* eml_openfiles_f[20];         // '<S93>/getSpeedLimit'
    FILE* eml_openfiles_k[20];         // '<S95>/getSpeedLimit'
    uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T obj;// '<S91>/TrackSimPath' 
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T obj_p;// '<S1>/Vector Field Histogram' 
    DubinsObjSingleton_Real2SimGuidance_d_T SingletonInstance;// '<S93>/getSpeedLimit' 
    DubinsObjSingleton_Real2SimGuidance_d_T SingletonInstance_n;// '<S95>/getSpeedLimit' 
    DubinsObjSingleton_Real2SimGuidance_T SingletonInstance_e;// '<Root>/Get Nominal Flight Speed' 
    s88w9UDFTziuJLEYZbYNZfH_Real2SimGuidance_T LAPGainBias;// '<S14>/getLAPGainBias' 
    robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T
        obj_h;                  // '<S15>/Coordinate Transformation Conversion'
    real_T SpeedLimit[2];              // '<S95>/getSpeedLimit'
    real_T VectorConcatenate[4];       // '<S112>/Vector Concatenate'
    real_T estimatedExtendedStateDerivative[3];
                                     // '<S118>/Linear extended state observer'
    real_T SwitchLookAheadNED[3];      // '<S91>/SwitchLookAheadNED'
    real_T EastSequence_X[216];        // '<S90>/EastSequence'
    real_T HeightSequence_X[216];      // '<S90>/HeightSequence'
    real_T NorthSequence_X[216];       // '<S90>/NorthSequence'
    real_T ADRC_Log[4];                // '<Root>/ADRC_Log'
    real_T Heading_Log[3];             // '<Root>/Heading_Log'
    real_T MatrixConcatenate[651];     // '<S90>/Matrix Concatenate'
    real_T y[2097152];                 // '<S15>/minus'
    real_T SelectNorth[1048576];       // '<S15>/SelectNorth'
    real_T SelectEast[1048576];        // '<S15>/SelectEast'
    real_T theta[1048576];             // '<S15>/Cartesian2Polar'
    real_T rho[1048576];               // '<S15>/Cartesian2Polar'
    real_T kalpha[540];
    real_T waypoints_data[651];
    real_T b_waypointsIn_data[651];
    real_T BiasHSwitch;                // '<S9>/BiasHSwitch'
    real_T dotAltTD;                   // '<S96>/dotAltTD'
    real_T fh;                         // '<S96>/fhan_Alt'
    real_T Gain;                       // '<S95>/Gain'
    real_T Switch_p;                   // '<S112>/Switch'
    real_T Tsamp;                      // '<S157>/Tsamp'
    real_T IProdOut;                   // '<S159>/IProd Out'
    real_T Sum;                        // '<S171>/Sum'
    real_T RThat_b;                    // '<S114>/RThat_b'
    real_T RTomega_b;                  // '<S114>/RTomega_b'
    real_T RTomega_o;                  // '<S114>/RTomega_o'
    real_T RTu;                        // '<S114>/RTu'
    real_T biasHm70;                   // '<S104>/biasHm70'
    real_T SimHdg;                     // '<S97>/MissionSwitchInitialPersuit'
    real_T Gain_b;                     // '<S99>/Gain'
    real_T Execution;                  // '<Root>/EngagementDebouncer'
    real_T UD_DSTATE;                  // '<S155>/UD'
    real_T Integrator_DSTATE;          // '<S162>/Integrator'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S97>/Discrete-Time Integrator'
    real_T CrossTrackError;            // '<Root>/CrossTrackError'
    real_T EngagedFlag;                // '<Root>/EngagedFlag_Log'
    real_T LagDistance;                // '<Root>/LagDistance'
    real_T RefGndSpd;                  // '<Root>/RefGndSpd'
    real_T biasH_Log;                  // '<Root>/biasH_Log'
    real_T MemoryRefHeight_PreviousInput;// '<S92>/MemoryRefHeight'
    int32_T SelectNorth_DIMS1[2];      // '<S15>/SelectNorth'
    int32_T SelectEast_DIMS1[2];       // '<S15>/SelectEast'
    int32_T SFunction_DIMS2[2];        // '<S15>/minus'
    int32_T SFunction_DIMS2_c[2];      // '<S15>/MatrixProduct'
    int32_T durationCounter_1;         // '<Root>/TASgreaterthan15for1Sec'
    int32_T SFunction_DIMS3;           // '<S15>/Cartesian2Polar'
    int32_T SFunction_DIMS4;           // '<S15>/Cartesian2Polar'
    uint32_T temporalCounter_i1;       // '<S97>/MissionSwitchInitialPersuit'
    uint16_T temporalCounter_i1_i;     // '<Root>/EngagementDebouncer'
    int8_T DiscreteTimeIntegrator_PrevResetState;// '<S97>/Discrete-Time Integrator' 
    uint8_T Engaged;                   // '<S9>/Engagement'
    uint8_T FlightMode_Log;            // '<Root>/FlightMode_Log'
    uint8_T is_active_c16_Real2SimGuidance;// '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_c16_Real2SimGuidance;   // '<Root>/TASgreaterthan15for1Sec'
    uint8_T Memory_PreviousInput;      // '<S9>/Memory'
    uint8_T is_active_c6_Real2SimGuidance;// '<S112>/ControlLogic'
    uint8_T is_c6_Real2SimGuidance;    // '<S112>/ControlLogic'
    uint8_T is_useADRC;                // '<S112>/ControlLogic'
    uint8_T is_Debounce;               // '<S112>/ControlLogic'
    uint8_T temporalCounter_i1_n;      // '<S112>/ControlLogic'
    uint8_T is_active_c3_Real2SimGuidance;// '<S97>/MissionSwitchInitialPersuit' 
    uint8_T is_c3_Real2SimGuidance;    // '<S97>/MissionSwitchInitialPersuit'
    uint8_T is_Normal;                 // '<S97>/MissionSwitchInitialPersuit'
    uint8_T is_Debounce_m;             // '<S97>/MissionSwitchInitialPersuit'
    uint8_T temporalCounter_i2;        // '<S97>/MissionSwitchInitialPersuit'
    uint8_T is_active_c2_Real2SimGuidance;// '<S9>/Chart'
    uint8_T is_c2_Real2SimGuidance;    // '<S9>/Chart'
    uint8_T is_active_c34_Real2SimGuidance;// '<Root>/EngagementDebouncer'
    uint8_T is_c34_Real2SimGuidance;   // '<Root>/EngagementDebouncer'
    uint8_T is_Persuit;                // '<Root>/EngagementDebouncer'
    uint8_T is_Debounce_m4;            // '<Root>/EngagementDebouncer'
    uint8_T is_L0Engaged;              // '<Root>/EngagementDebouncer'
    uint8_T is_L0Default;              // '<Root>/EngagementDebouncer'
    uint8_T is_Debounce_b;             // '<Root>/EngagementDebouncer'
    uint8_T temporalCounter_i2_f;      // '<Root>/EngagementDebouncer'
    boolean_T validRangeLimitIndices_data[40000];
    boolean_T validAngleLimitIndices_data[40000];
    boolean_T tmp_data[40000];
    boolean_T tmp_data_m[40000];
    boolean_T tmp_data_c[40000];
    boolean_T validIndices_data[40000];
    boolean_T blockedR_data[40000];
    boolean_T blockedL_data[40000];
    boolean_T nearIdx_data[49140];
    boolean_T c_data[40000];
    boolean_T y_data[40000];
    boolean_T in2_data[40000];
    boolean_T Compare;                 // '<S88>/Compare'
    boolean_T PID_U;                   // '<S112>/ControlLogic'
    boolean_T EnableADRC;              // '<S112>/ControlLogic'
    boolean_T EnablePID;               // '<S112>/ControlLogic'
    boolean_T Compare_o;               // '<S26>/Compare'
    boolean_T Compare_l;               // '<S27>/Compare'
    boolean_T Compare_k;               // '<S28>/Compare'
    boolean_T DelayInput1_DSTATE;      // '<S18>/Delay Input1'
    boolean_T DelayInput1_DSTATE_o;    // '<S20>/Delay Input1'
    boolean_T DelayInput1_DSTATE_p;    // '<S21>/Delay Input1'
    boolean_T AvoidDanger;             // '<Root>/DangerAvoidanceLog'
    boolean_T HdgStatus_Log;           // '<Root>/Status_Log'
    boolean_T MemoryNotInBrake_PreviousInput;// '<S9>/MemoryNotInBrake'
    boolean_T SingletonInstance_not_empty;// '<S95>/getSpeedLimit'
    boolean_T SingletonInstance_not_empty_b;// '<S93>/getSpeedLimit'
    boolean_T objisempty;              // '<S91>/TrackSimPath'
    boolean_T SingletonInstance_not_empty_a;// '<Root>/Get Nominal Flight Speed' 
    boolean_T objisempty_f;            // '<S1>/Vector Field Histogram'
    boolean_T objisempty_k;     // '<S15>/Coordinate Transformation Conversion'
    boolean_T LAPGainBias_not_empty;   // '<S14>/getLAPGainBias'
    boolean_T SpdFBControl_MODE;       // '<S95>/SpdFBControl'
    boolean_T PID_MODE;                // '<S112>/PID'
    boolean_T ADRC_MODE;               // '<S112>/ADRC'
};

// Continuous states for model 'Real2SimGuidance'
struct X_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;              // '<S96>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S96>/dotAltTD'
    real_T Integrator_CSTATE[3];       // '<S118>/Integrator'
};

// State derivatives for model 'Real2SimGuidance'
struct XDot_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;              // '<S96>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S96>/dotAltTD'
    real_T Integrator_CSTATE[3];       // '<S118>/Integrator'
};

// State Disabled for model 'Real2SimGuidance'
struct XDis_Real2SimGuidance_n_T {
    boolean_T TD_Alt_CSTATE;           // '<S96>/TD_Alt'
    boolean_T dotAltTD_CSTATE;         // '<S96>/dotAltTD'
    boolean_T Integrator_CSTATE[3];    // '<S118>/Integrator'
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
    *rtu_ParamADRC_omega_o, const real_T *rtu_ParamADRC_omega_c, const real_T
    *rtu_ParamADRC_P, const real_T *rtu_ParamADRC_I, const real_T
    *rtu_ParamADRC_D, const boolean_T *rtu_ParamADRC_useADRC, const real_T
    rtu_PointCloudData[2097152], const int32_T rtu_PointCloudData_DIMS1[2],
    FCUCMD *rty_FCUCMD, uint8_T *rty_EngagedFlag, FlightLogging
    *rty_FlightLogging, DW_Real2SimGuidance_f_T *localDW, X_Real2SimGuidance_n_T
    *localX);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S40>/Data Type Duplicate' : Unused code path elimination
//  Block '<S63>/Data Type Duplicate' : Unused code path elimination
//  Block '<S102>/Data Type Duplicate' : Unused code path elimination
//  Block '<S102>/Data Type Propagation' : Unused code path elimination
//  Block '<S111>/Data Type Duplicate' : Unused code path elimination
//  Block '<S111>/Data Type Propagation' : Unused code path elimination
//  Block '<S155>/DTDup' : Unused code path elimination
//  Block '<Root>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S9>/LookaheadPoint_ZOH' : Eliminated since input and output rates are identical
//  Block '<S9>/RT_EngagedFlag' : Eliminated since input and output rates are identical
//  Block '<S9>/Rate Transition' : Eliminated since input and output rates are identical
//  Block '<S95>/AirspeedZOH' : Eliminated since input and output rates are identical
//  Block '<S114>/RTErr' : Eliminated since input and output rates are identical
//  Block '<S95>/ZOH_ADRC_LagDis' : Eliminated since input and output rates are identical


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
//  '<S1>'   : 'Real2SimGuidance/AvoidDanger'
//  '<S2>'   : 'Real2SimGuidance/Compare To Constant'
//  '<S3>'   : 'Real2SimGuidance/Enabled Subsystem'
//  '<S4>'   : 'Real2SimGuidance/EngagementDebouncer'
//  '<S5>'   : 'Real2SimGuidance/Get Nominal Flight Speed'
//  '<S6>'   : 'Real2SimGuidance/LatLon2NorthEast'
//  '<S7>'   : 'Real2SimGuidance/NorthEast2LatLon'
//  '<S8>'   : 'Real2SimGuidance/Radians to Degrees'
//  '<S9>'   : 'Real2SimGuidance/Real2SimNav'
//  '<S10>'  : 'Real2SimGuidance/TASgreaterthan15for1Sec'
//  '<S11>'  : 'Real2SimGuidance/TimeNow'
//  '<S12>'  : 'Real2SimGuidance/WrapAngle'
//  '<S13>'  : 'Real2SimGuidance/AvoidDanger/CalTgtDir'
//  '<S14>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP'
//  '<S15>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint'
//  '<S16>'  : 'Real2SimGuidance/AvoidDanger/CalTgtDir/wrap2pi'
//  '<S17>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/AngDiff'
//  '<S18>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/AvoidanceFailure'
//  '<S19>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Compare To Constant'
//  '<S20>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Detect Fall Nonpositive'
//  '<S21>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Detect Rise Positive '
//  '<S22>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/FailDangerAvoidance'
//  '<S23>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/FinishDangerAvoidance'
//  '<S24>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/StartDangerAvoidance'
//  '<S25>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/getLAPGainBias'
//  '<S26>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/AvoidanceFailure/Positive'
//  '<S27>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Detect Fall Nonpositive/Nonpositive'
//  '<S28>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Detect Rise Positive /Positive'
//  '<S29>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/FailDangerAvoidance/printFail'
//  '<S30>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/FinishDangerAvoidance/printFinish'
//  '<S31>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/StartDangerAvoidance/printStart'
//  '<S32>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/Cartesian2Polar'
//  '<S33>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/MatrixProduct'
//  '<S34>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/VisualizeCloudPoint'
//  '<S35>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/minus'
//  '<S36>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/VisualizeCloudPoint/Subsystem'
//  '<S37>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians'
//  '<S38>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians1'
//  '<S39>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians2'
//  '<S40>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth'
//  '<S41>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S42>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S43>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S44>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S45>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S46>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S47>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S48>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S49>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S50>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S51>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S52>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S53>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S54>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S55>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S56>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S57>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S58>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S59>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S60>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S61>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S62>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S63>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA'
//  '<S64>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S65>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S66>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S67>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S68>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S69>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S70>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S71>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S72>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S73>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S74>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S75>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S76>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S77>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S78>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S79>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S80>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S81>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S82>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S83>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S84>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S85>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S86>'  : 'Real2SimGuidance/Real2SimNav/AngLog'
//  '<S87>'  : 'Real2SimGuidance/Real2SimNav/Chart'
//  '<S88>'  : 'Real2SimGuidance/Real2SimNav/Compare To Zero'
//  '<S89>'  : 'Real2SimGuidance/Real2SimNav/Engagement'
//  '<S90>'  : 'Real2SimGuidance/Real2SimNav/GenerateTrack'
//  '<S91>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic'
//  '<S92>'  : 'Real2SimGuidance/Real2SimNav/HeadingNaNProtection'
//  '<S93>'  : 'Real2SimGuidance/Real2SimNav/MaxBrake'
//  '<S94>'  : 'Real2SimGuidance/Real2SimNav/PointingMode'
//  '<S95>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl'
//  '<S96>'  : 'Real2SimGuidance/Real2SimNav/TD'
//  '<S97>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg'
//  '<S98>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/RefHdg'
//  '<S99>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg/CalForwardShift'
//  '<S100>' : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg/MissionSwitchInitialPersuit'
//  '<S101>' : 'Real2SimGuidance/Real2SimNav/MaxBrake/Calculate Brake Range'
//  '<S102>' : 'Real2SimGuidance/Real2SimNav/MaxBrake/Saturation Dynamic'
//  '<S103>' : 'Real2SimGuidance/Real2SimNav/MaxBrake/getSpeedLimit'
//  '<S104>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/EnableBias'
//  '<S105>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/L0RangeSim2Track1d3'
//  '<S106>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/L0RangeSim2Track3d3'
//  '<S107>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/L1RangeSim2Track1d3'
//  '<S108>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/L1RangeSim2Track3d3'
//  '<S109>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/Range2CurrentSim'
//  '<S110>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track2d3'
//  '<S111>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/Saturation Dynamic'
//  '<S112>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl'
//  '<S113>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/getSpeedLimit'
//  '<S114>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC'
//  '<S115>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ControlLogic'
//  '<S116>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID'
//  '<S117>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller'
//  '<S118>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Linear extended state observer'
//  '<S119>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Observer output'
//  '<S120>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller'
//  '<S121>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Linear extended state observer/Linear extended state observer'
//  '<S122>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Observer output/Whole estimated extended state'
//  '<S123>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Dead time'
//  '<S124>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Extended state feedback robust controller'
//  '<S125>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Saturation'
//  '<S126>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Dead time/Dead time on'
//  '<S127>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Saturation/Saturation off'
//  '<S128>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller'
//  '<S129>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Anti-windup'
//  '<S130>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/D Gain'
//  '<S131>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter'
//  '<S132>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter ICs'
//  '<S133>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/I Gain'
//  '<S134>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain'
//  '<S135>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S136>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator'
//  '<S137>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator ICs'
//  '<S138>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Copy'
//  '<S139>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Gain'
//  '<S140>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/P Copy'
//  '<S141>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Parallel P Gain'
//  '<S142>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Reset Signal'
//  '<S143>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation'
//  '<S144>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation Fdbk'
//  '<S145>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum'
//  '<S146>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum Fdbk'
//  '<S147>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode'
//  '<S148>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode Sum'
//  '<S149>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Integral'
//  '<S150>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Ngain'
//  '<S151>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/postSat Signal'
//  '<S152>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/preSat Signal'
//  '<S153>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S154>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/D Gain/External Parameters'
//  '<S155>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator'
//  '<S156>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator/Tsamp'
//  '<S157>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S158>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S159>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/I Gain/External Parameters'
//  '<S160>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S161>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S162>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator/Discrete'
//  '<S163>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S164>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S165>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Gain/Passthrough'
//  '<S166>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/P Copy/Disabled'
//  '<S167>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Parallel P Gain/External Parameters'
//  '<S168>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Reset Signal/Disabled'
//  '<S169>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation/Passthrough'
//  '<S170>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S171>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum/Sum_PID'
//  '<S172>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S173>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S174>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S175>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S176>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S177>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S178>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S179>' : 'Real2SimGuidance/Real2SimNav/TD/fhan_Alt'

#endif                                 // RTW_HEADER_Real2SimGuidance_h_

//
// File trailer for generated code.
//
// [EOF]
//
