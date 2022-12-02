//
// File: Real2SimGuidance.h
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 5.11
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 16:47:43 2022
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
#include "DatalinkInterface.h"
#include "Real2SimGuidance_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include "model_reference_types.h"

// Block signals and states (default storage) for system '<S6>/ReadHomePoint'
struct DW_ReadHomePoint_Real2SimGuidance_T {
    FILE* eml_openfiles[20];           // '<S6>/ReadHomePoint'
    real_T HomePoint[3];               // '<S6>/ReadHomePoint'
    boolean_T HomePoint_not_empty;     // '<S6>/ReadHomePoint'
};

// Block signals and states (default storage) for model 'Real2SimGuidance'
struct DW_Real2SimGuidance_f_T {
    DW_ReadHomePoint_Real2SimGuidance_T sf_ReadHomePoint_p;// '<S7>/ReadHomePoint' 
    DW_ReadHomePoint_Real2SimGuidance_T sf_ReadHomePoint;// '<S6>/ReadHomePoint' 
    FILE* eml_openfiles[20];           // '<S15>/getLAPGainBias'
    FILE* eml_openfiles_k[20];         // '<Root>/Get Nominal Flight Speed'
    FILE* eml_openfiles_i[20];         // '<S97>/getSpeedLimit'
    FILE* eml_openfiles_p[20];         // '<S99>/getSpeedLimit'
    uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T obj;// '<S95>/TrackSimPath' 
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T obj_p;// '<S17>/Vector Field Histogram' 
    DubinsObjSingleton_Real2SimGuidance_f_T SingletonInstance;// '<S97>/getSpeedLimit' 
    DubinsObjSingleton_Real2SimGuidance_f_T SingletonInstance_p;// '<S99>/getSpeedLimit' 
    DubinsObjSingleton_Real2SimGuidance_T SingletonInstance_n;// '<Root>/Get Nominal Flight Speed' 
    Time CurrentTime;                  // '<Root>/TimeNow'
    s88w9UDFTziuJLEYZbYNZfH_Real2SimGuidance_T LAPGainBias;// '<S15>/getLAPGainBias' 
    robotics_slcore_internal_block_CoordinateTransformationConversion_Real2SimGuidance_T
        obj_h;                  // '<S16>/Coordinate Transformation Conversion'
    real_T TargetLocation[3];          // '<S99>/TargetLocation'
    real_T FrontBound[3];              // '<S99>/FrontBound'
    real_T TailBound[3];               // '<S99>/TailBound'
    real_T L1FrontBound[3];            // '<S99>/L1FrontBound'
    real_T L1TailBound[3];             // '<S99>/L1TailBound'
    real_T SpeedLimit[2];              // '<S99>/getSpeedLimit'
    real_T Integrator[3];              // '<S125>/Integrator'
    real_T estimatedExtendedStateDerivative[3];
                                     // '<S125>/Linear extended state observer'
    real_T Mean[3];                    // '<S95>/Mean'
    real_T SwitchLookAheadNED[3];      // '<S95>/SwitchLookAheadNED'
    real_T MatrixConcatenate[651];     // '<S94>/Matrix Concatenate'
    real_T LLA0[3];                    // '<S7>/ReadHomePoint'
    real_T LLA0_g[3];                  // '<S6>/ReadHomePoint'
    real_T EastSequence_X[216];        // '<S94>/EastSequence'
    real_T HeightSequence_X[216];      // '<S94>/HeightSequence'
    real_T NorthSequence_X[216];       // '<S94>/NorthSequence'
    real_T ADRC_Log[4];                // '<Root>/ADRC_Log'
    real_T Heading_Log[3];             // '<Root>/Heading_Log'
    real_T Mean_AccVal[3];             // '<S95>/Mean'
    real_T waypoints_data[651];
    real_T b_waypointsIn_data[651];
    real_T y[2097152];                 // '<S16>/minus'
    real_T SelectNorth[1048576];       // '<S16>/SelectNorth'
    real_T SelectEast[1048576];        // '<S16>/SelectEast'
    real_T theta[1048576];             // '<S16>/Cartesian2Polar'
    real_T rho[1048576];               // '<S16>/Cartesian2Polar'
    real_T Switch;                     // '<S54>/Switch'
    real_T Switch_o;                   // '<S55>/Switch'
    real_T TrigonometricFunction1;     // '<S61>/Trigonometric Function1'
    real_T SinCos_o1;                  // '<S46>/SinCos'
    real_T SinCos_o2;                  // '<S46>/SinCos'
    real_T TrigonometricFunction2;     // '<S61>/Trigonometric Function2'
    real_T minusAltitudeGCS;           // '<S6>/inverse'
    real_T SinCos_o1_f;                // '<S70>/SinCos'
    real_T SinCos_o2_b;                // '<S70>/SinCos'
    real_T Switch_n;                   // '<S78>/Switch'
    real_T TrigonometricFunction1_l;   // '<S84>/Trigonometric Function1'
    real_T TrigonometricFunction2_o;   // '<S84>/Trigonometric Function2'
    real_T Switch_m;                   // '<S79>/Switch'
    real_T minusAltitudeGCS_l;         // '<S7>/inverse'
    real_T RetDir;                     // '<Root>/RepulDir'
    real_T dotAltTD;                   // '<S100>/dotAltTD'
    real_T fh;                         // '<S100>/fhan_Alt'
    real_T Max;                        // '<S99>/Max'
    real_T Min;                        // '<S99>/Min'
    real_T Switch_p;                   // '<S119>/Switch'
    real_T Tsamp;                      // '<S164>/Tsamp'
    real_T IProdOut;                   // '<S166>/IProd Out'
    real_T Sum;                        // '<S178>/Sum'
    real_T Product;                    // '<S133>/Product'
    real_T biasHm70;                   // '<S111>/biasHm70'
    real_T Max_g;                      // '<S97>/Max'
    real_T Min_a;                      // '<S97>/Min'
    real_T OverwriteHeight;            // '<S96>/MemoryRefHeight'
    real_T LookaheadT;                 // '<S95>/LookaheadT'
    real_T Gain_m;                     // '<S95>/Gain'
    real_T DiscreteTimeIntegrator;     // '<S104>/Discrete-Time Integrator'
    real_T SimHdg;                     // '<S104>/MissionSwitchInitialPersuit'
    real_T Gain_b;                     // '<S106>/Gain'
    real_T NominalSpeed;               // '<Root>/Get Nominal Flight Speed'
    real_T VectorFieldHistogram;       // '<S17>/Vector Field Histogram'
    real_T Bias;                       // '<S15>/getLAPGainBias'
    real_T Gain_i;                     // '<S15>/getLAPGainBias'
    real_T lambdaWrapped;              // '<S14>/wrap2Pi'
    real_T UD_DSTATE;                  // '<S162>/UD'
    real_T Integrator_DSTATE;          // '<S169>/Integrator'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S104>/Discrete-Time Integrator'
    real_T CrossTrackError;            // '<Root>/CrossTrackError'
    real_T EngagedFlag;                // '<Root>/EngagedFlag_Log'
    real_T LagDistance;                // '<Root>/LagDistance'
    real_T RefGndSpd;                  // '<Root>/RefGndSpd'
    real_T biasH_Log;                  // '<Root>/biasH_Log'
    real_T MemoryRefHeight_PreviousInput;// '<S96>/MemoryRefHeight'
    int32_T SelectNorth_DIMS1[2];      // '<S16>/SelectNorth'
    int32_T SelectEast_DIMS1[2];       // '<S16>/SelectEast'
    int32_T SFunction_DIMS2[2];        // '<S16>/minus'
    int32_T SFunction_DIMS2_l[2];      // '<S16>/MatrixProduct'
    int32_T Inverse_DIMS1;             // '<S1>/Inverse'
    int32_T SFunction_DIMS3;           // '<S16>/Cartesian2Polar'
    int32_T SFunction_DIMS4;           // '<S16>/Cartesian2Polar'
    uint32_T durationCounter_1;        // '<Root>/TASgreaterthan15for1Sec'
    uint32_T temporalCounter_i1;       // '<S104>/MissionSwitchInitialPersuit'
    uint16_T temporalCounter_i1_o;     // '<Root>/EngagementDebouncer'
    int8_T DiscreteTimeIntegrator_PrevResetState;// '<S104>/Discrete-Time Integrator' 
    uint8_T Engaged;                   // '<S9>/Engagement'
    uint8_T FlightMode_Log;            // '<Root>/FlightMode_Log'
    uint8_T is_c16_Real2SimGuidance;   // '<Root>/TASgreaterthan15for1Sec'
    uint8_T is_active_c16_Real2SimGuidance;// '<Root>/TASgreaterthan15for1Sec'
    uint8_T Memory_PreviousInput;      // '<S9>/Memory'
    uint8_T is_c6_Real2SimGuidance;    // '<S119>/ControlLogic'
    uint8_T is_useADRC;                // '<S119>/ControlLogic'
    uint8_T is_Debounce;               // '<S119>/ControlLogic'
    uint8_T is_active_c6_Real2SimGuidance;// '<S119>/ControlLogic'
    uint8_T temporalCounter_i1_h;      // '<S119>/ControlLogic'
    uint8_T is_c3_Real2SimGuidance;    // '<S104>/MissionSwitchInitialPersuit'
    uint8_T is_Normal;                 // '<S104>/MissionSwitchInitialPersuit'
    uint8_T is_Debounce_b;             // '<S104>/MissionSwitchInitialPersuit'
    uint8_T is_active_c3_Real2SimGuidance;// '<S104>/MissionSwitchInitialPersuit' 
    uint8_T temporalCounter_i2;        // '<S104>/MissionSwitchInitialPersuit'
    uint8_T is_c2_Real2SimGuidance;    // '<S9>/Chart'
    uint8_T is_active_c2_Real2SimGuidance;// '<S9>/Chart'
    uint8_T is_c34_Real2SimGuidance;   // '<Root>/EngagementDebouncer'
    uint8_T is_Persuit;                // '<Root>/EngagementDebouncer'
    uint8_T is_Debounce_o;             // '<Root>/EngagementDebouncer'
    uint8_T is_L0Engaged;              // '<Root>/EngagementDebouncer'
    uint8_T is_L0Default;              // '<Root>/EngagementDebouncer'
    uint8_T is_Debounce_g;             // '<Root>/EngagementDebouncer'
    uint8_T is_active_c34_Real2SimGuidance;// '<Root>/EngagementDebouncer'
    uint8_T temporalCounter_i2_i;      // '<Root>/EngagementDebouncer'
    boolean_T validRangeLimitIndices_data[40000];
    boolean_T validAngleLimitIndices_data[40000];
    boolean_T tmp_data[40000];
    boolean_T tmp_data_m[40000];
    boolean_T tmp_data_c[40000];
    boolean_T validIndices_data[40000];
    boolean_T blockedR_data[40000];
    boolean_T blockedL_data[40000];
    boolean_T nearIdx_data[21960];
    boolean_T c_data[40000];
    boolean_T y_data[40000];
    boolean_T in2_data[40000];
    boolean_T TakeOffTrigger;          // '<Root>/TASgreaterthan15for1Sec'
    boolean_T inDngr;                  // '<Root>/RepulDir'
    boolean_T AND;                     // '<S9>/AND'
    boolean_T Compare;                 // '<S92>/Compare'
    boolean_T PID_U;                   // '<S119>/ControlLogic'
    boolean_T EnableADRC;              // '<S119>/ControlLogic'
    boolean_T EnablePID;               // '<S119>/ControlLogic'
    boolean_T BiasHSwitch;             // '<S9>/Chart'
    boolean_T Compare_o;               // '<S28>/Compare'
    boolean_T Compare_l;               // '<S29>/Compare'
    boolean_T Compare_k;               // '<S30>/Compare'
    boolean_T DelayInput1_DSTATE;      // '<S20>/Delay Input1'
    boolean_T DelayInput1_DSTATE_o;    // '<S22>/Delay Input1'
    boolean_T DelayInput1_DSTATE_p;    // '<S23>/Delay Input1'
    boolean_T AvoidDanger;             // '<Root>/DangerAvoidanceLog'
    boolean_T HdgStatus_Log;           // '<Root>/Status_Log'
    boolean_T MemoryNotInBrake_PreviousInput;// '<S9>/MemoryNotInBrake'
    boolean_T SingletonInstance_not_empty;// '<S99>/getSpeedLimit'
    boolean_T SingletonInstance_not_empty_c;// '<S97>/getSpeedLimit'
    boolean_T objisempty;              // '<S95>/TrackSimPath'
    boolean_T SingletonInstance_not_empty_e;// '<Root>/Get Nominal Flight Speed' 
    boolean_T objisempty_f;            // '<S17>/Vector Field Histogram'
    boolean_T objisempty_k;     // '<S16>/Coordinate Transformation Conversion'
    boolean_T LAPGainBias_not_empty;   // '<S15>/getLAPGainBias'
    boolean_T SpdFBControl_MODE;       // '<S99>/SpdFBControl'
    boolean_T PID_MODE;                // '<S119>/PID'
    boolean_T ADRC_MODE;               // '<S119>/ADRC'
    boolean_T EnableBias_MODE;         // '<S99>/EnableBias'
    boolean_T CalForwardShift_MODE;    // '<S104>/CalForwardShift'
    boolean_T EnabledSubsystem_MODE;   // '<Root>/Enabled Subsystem'
    boolean_T TieredVFH_MODE;          // '<S1>/TieredVFH+'
};

// Continuous states for model 'Real2SimGuidance'
struct X_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;              // '<S100>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S100>/dotAltTD'
    real_T Integrator_CSTATE[3];       // '<S125>/Integrator'
};

// State derivatives for model 'Real2SimGuidance'
struct XDot_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;              // '<S100>/TD_Alt'
    real_T dotAltTD_CSTATE;            // '<S100>/dotAltTD'
    real_T Integrator_CSTATE[3];       // '<S125>/Integrator'
};

// State Disabled for model 'Real2SimGuidance'
struct XDis_Real2SimGuidance_n_T {
    boolean_T TD_Alt_CSTATE;           // '<S100>/TD_Alt'
    boolean_T dotAltTD_CSTATE;         // '<S100>/dotAltTD'
    boolean_T Integrator_CSTATE[3];    // '<S125>/Integrator'
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

// Model reference registration function
extern void Real2SimGuidance_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
    *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
    RT_MODEL_Real2SimGuidance_T *const Real2SimGuidance_M);
extern void Real2SimGuidance_wrap2Pi(real_T rtu_lambda, real_T
    *rty_lambdaWrapped);
extern void Real2SimGuidance_AngDiff(real_T rtu_alpha, real_T rtu_beta, real_T
    *rty_delta);
extern void Real2SimGuidance_ReadHomePoint_Init
    (DW_ReadHomePoint_Real2SimGuidance_T *localDW);
extern void Real2SimGuidance_ReadHomePoint(real_T rty_LLA0[3],
    DW_ReadHomePoint_Real2SimGuidance_T *localDW);
extern void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX);
extern void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot);
extern void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW);
extern void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const boolean_T *rtu_NewMission, const
    FixedWingGuidanceStateBus *rtu_SimUAVState, DW_Real2SimGuidance_f_T *localDW);
extern void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const boolean_T *rtu_NewMission, const uint8_T
    *rtu_FlightMode, const RealUAVStateBus *rtu_FlightState, const boolean_T
    rtu_ControlSwitch[2], const FixedWingGuidanceStateBus *rtu_SimUAVState,
    const FixedWingGuidanceBus *rtu_ImmedGuidanceCMD, const real_T
    *rtu_BiasRatio, const real_T *rtu_ParamADRC_hat_b, const real_T
    *rtu_ParamADRC_omega_o, const real_T *rtu_ParamADRC_omega_c, const real_T
    *rtu_ParamADRC_P, const real_T *rtu_ParamADRC_I, const real_T
    *rtu_ParamADRC_D, const boolean_T *rtu_ParamADRC_useADRC, const real_T
    rtu_PntCldData[2097152], const int32_T rtu_PntCldData_DIMS1[2], const real_T
    rtu_DngrListNER[192], const int32_T rtu_DngrListNER_DIMS1[2], const real_T
    *rtu_VecSpd_eastSpeed, const real_T *rtu_VecSpd_northSpeed, const real_T
    *rtu_VecSpd_skySpeed, FCUCMD *rty_FCUCMD, uint8_T *rty_EngagedFlag,
    FlightLogging *rty_FlightLogging, DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S42>/Data Type Duplicate' : Unused code path elimination
//  Block '<S66>/Data Type Duplicate' : Unused code path elimination
//  Block '<S109>/Data Type Duplicate' : Unused code path elimination
//  Block '<S109>/Data Type Propagation' : Unused code path elimination
//  Block '<S118>/Data Type Duplicate' : Unused code path elimination
//  Block '<S118>/Data Type Propagation' : Unused code path elimination
//  Block '<S162>/DTDup' : Unused code path elimination


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
//  '<S10>'  : 'Real2SimGuidance/RepulDir'
//  '<S11>'  : 'Real2SimGuidance/TASgreaterthan15for1Sec'
//  '<S12>'  : 'Real2SimGuidance/TimeNow'
//  '<S13>'  : 'Real2SimGuidance/wrap2Pi'
//  '<S14>'  : 'Real2SimGuidance/AvoidDanger/CalTgtDir'
//  '<S15>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP'
//  '<S16>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint'
//  '<S17>'  : 'Real2SimGuidance/AvoidDanger/TieredVFH+'
//  '<S18>'  : 'Real2SimGuidance/AvoidDanger/CalTgtDir/wrap2Pi'
//  '<S19>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/AngDiff'
//  '<S20>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/AvoidanceFailure'
//  '<S21>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Compare To Constant'
//  '<S22>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Detect Fall Nonpositive'
//  '<S23>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Detect Rise Positive '
//  '<S24>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/FailDangerAvoidance'
//  '<S25>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/FinishDangerAvoidance'
//  '<S26>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/StartDangerAvoidance'
//  '<S27>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/getLAPGainBias'
//  '<S28>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/AvoidanceFailure/Positive'
//  '<S29>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Detect Fall Nonpositive/Nonpositive'
//  '<S30>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/Detect Rise Positive /Positive'
//  '<S31>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/FailDangerAvoidance/printFail'
//  '<S32>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/FinishDangerAvoidance/printFinish'
//  '<S33>'  : 'Real2SimGuidance/AvoidDanger/Hdg2LAP/StartDangerAvoidance/printStart'
//  '<S34>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/Cartesian2Polar'
//  '<S35>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/MatrixProduct'
//  '<S36>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/VisualizeCloudPoint'
//  '<S37>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/minus'
//  '<S38>'  : 'Real2SimGuidance/AvoidDanger/ProcessCloudPoint/VisualizeCloudPoint/Subsystem'
//  '<S39>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians'
//  '<S40>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians1'
//  '<S41>'  : 'Real2SimGuidance/LatLon2NorthEast/Degrees to Radians2'
//  '<S42>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth'
//  '<S43>'  : 'Real2SimGuidance/LatLon2NorthEast/ReadHomePoint'
//  '<S44>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S45>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S46>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S47>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S48>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S49>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S50>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S51>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S52>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S53>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S54>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S55>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S56>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S57>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S58>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S59>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S60>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S61>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S62>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S63>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S64>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S65>'  : 'Real2SimGuidance/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S66>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA'
//  '<S67>'  : 'Real2SimGuidance/NorthEast2LatLon/ReadHomePoint'
//  '<S68>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap'
//  '<S69>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1'
//  '<S70>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset'
//  '<S71>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/pos_deg'
//  '<S72>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S73>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S74>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S75>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S76>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S77>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S78>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S79>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S80>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S81>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S82>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S83>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S84>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S85>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S86>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S87>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S88>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S89>'  : 'Real2SimGuidance/NorthEast2LatLon/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S90>'  : 'Real2SimGuidance/Real2SimNav/AngDiff'
//  '<S91>'  : 'Real2SimGuidance/Real2SimNav/Chart'
//  '<S92>'  : 'Real2SimGuidance/Real2SimNav/Compare To Zero'
//  '<S93>'  : 'Real2SimGuidance/Real2SimNav/Engagement'
//  '<S94>'  : 'Real2SimGuidance/Real2SimNav/GenerateTrack'
//  '<S95>'  : 'Real2SimGuidance/Real2SimNav/HeadingLogic'
//  '<S96>'  : 'Real2SimGuidance/Real2SimNav/HeadingNaNProtection'
//  '<S97>'  : 'Real2SimGuidance/Real2SimNav/MaxBrake'
//  '<S98>'  : 'Real2SimGuidance/Real2SimNav/PointingMode'
//  '<S99>'  : 'Real2SimGuidance/Real2SimNav/SpeedControl'
//  '<S100>' : 'Real2SimGuidance/Real2SimNav/TD'
//  '<S101>' : 'Real2SimGuidance/Real2SimNav/wrap2PiRealHdg'
//  '<S102>' : 'Real2SimGuidance/Real2SimNav/wrap2PiTgtHdg'
//  '<S103>' : 'Real2SimGuidance/Real2SimNav/HeadingLogic/Calculate Range'
//  '<S104>' : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg'
//  '<S105>' : 'Real2SimGuidance/Real2SimNav/HeadingLogic/RefHdg'
//  '<S106>' : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg/CalForwardShift'
//  '<S107>' : 'Real2SimGuidance/Real2SimNav/HeadingLogic/NewMissionHdg/MissionSwitchInitialPersuit'
//  '<S108>' : 'Real2SimGuidance/Real2SimNav/MaxBrake/Calculate Brake Range'
//  '<S109>' : 'Real2SimGuidance/Real2SimNav/MaxBrake/Saturation Dynamic'
//  '<S110>' : 'Real2SimGuidance/Real2SimNav/MaxBrake/getSpeedLimit'
//  '<S111>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/EnableBias'
//  '<S112>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/L0RangeSim2Track1d3'
//  '<S113>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/L0RangeSim2Track3d3'
//  '<S114>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/L1RangeSim2Track1d3'
//  '<S115>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/L1RangeSim2Track3d3'
//  '<S116>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/Range2CurrentSim'
//  '<S117>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/RangeSim2Track2d3'
//  '<S118>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/Saturation Dynamic'
//  '<S119>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl'
//  '<S120>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/getSpeedLimit'
//  '<S121>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC'
//  '<S122>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ControlLogic'
//  '<S123>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID'
//  '<S124>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller'
//  '<S125>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Linear extended state observer'
//  '<S126>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Observer output'
//  '<S127>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller'
//  '<S128>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Linear extended state observer/Linear extended state observer'
//  '<S129>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/Observer output/Whole estimated extended state'
//  '<S130>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Dead time'
//  '<S131>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Extended state feedback robust controller'
//  '<S132>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Saturation'
//  '<S133>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Dead time/Dead time on'
//  '<S134>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/ADRC/ADRC controller/State feedback robust controller/Saturation/Saturation off'
//  '<S135>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller'
//  '<S136>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Anti-windup'
//  '<S137>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/D Gain'
//  '<S138>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter'
//  '<S139>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter ICs'
//  '<S140>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/I Gain'
//  '<S141>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain'
//  '<S142>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S143>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator'
//  '<S144>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator ICs'
//  '<S145>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Copy'
//  '<S146>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Gain'
//  '<S147>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/P Copy'
//  '<S148>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Parallel P Gain'
//  '<S149>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Reset Signal'
//  '<S150>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation'
//  '<S151>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation Fdbk'
//  '<S152>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum'
//  '<S153>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum Fdbk'
//  '<S154>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode'
//  '<S155>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode Sum'
//  '<S156>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Integral'
//  '<S157>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Ngain'
//  '<S158>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/postSat Signal'
//  '<S159>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/preSat Signal'
//  '<S160>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S161>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/D Gain/External Parameters'
//  '<S162>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator'
//  '<S163>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator/Tsamp'
//  '<S164>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S165>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S166>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/I Gain/External Parameters'
//  '<S167>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S168>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S169>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator/Discrete'
//  '<S170>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S171>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S172>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/N Gain/Passthrough'
//  '<S173>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/P Copy/Disabled'
//  '<S174>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Parallel P Gain/External Parameters'
//  '<S175>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Reset Signal/Disabled'
//  '<S176>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation/Passthrough'
//  '<S177>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S178>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum/Sum_PID'
//  '<S179>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S180>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S181>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S182>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S183>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S184>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S185>' : 'Real2SimGuidance/Real2SimNav/SpeedControl/SpdFBControl/PID/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S186>' : 'Real2SimGuidance/Real2SimNav/TD/fhan_Alt'

#endif                                 // RTW_HEADER_Real2SimGuidance_h_

//
// File trailer for generated code.
//
// [EOF]
//
