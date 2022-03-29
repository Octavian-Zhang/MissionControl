//
// File: MissionUAV.h
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 2.12
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Tue Mar 29 06:36:24 2022
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
#ifndef RTW_HEADER_MissionUAV_h_
#define RTW_HEADER_MissionUAV_h_
#include <cmath>
#include <cstring>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MissionUAV_types.h"

// Shared type includes
#include "model_reference_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Block signals and states (default storage) for model 'MissionUAV'
struct DW_MissionUAV_f_T {
    robotics_core_internal_system_navigation_StateVector2Struct_MissionUAV_T obj;// '<S2>/StateVector2Struct' 
    robotics_core_internal_system_navigation_Model_MissionUAV_T obj_j;// '<S2>/ComputeDerivative' 
    FixedWingGuidanceEnvironmentBus FixedWingGuidanceEnvironmentBus_p;
                                      // '<S1>/FixedWingGuidanceEnvironmentBus'
    FixedWingGuidanceControlBus SlewGuidanceBus;// '<S1>/SlewGuidanceBus'
    real_T RateTransition[8];          // '<S1>/Rate Transition'
    real_T ComputeDerivative[8];       // '<S2>/ComputeDerivative'
    real_T RollAngle;                  // '<S1>/RollAngleSaturation'
    real_T dotBankTD;                  // '<S4>/dotBankTD'
    real_T fh;                         // '<S4>/fhan_Bank'
    int_T Integrator_IWORK;            // '<S2>/Integrator'
    boolean_T objisempty;              // '<S2>/StateVector2Struct'
    boolean_T objisempty_a;            // '<S2>/ComputeDerivative'
};

// Continuous states for model 'MissionUAV'
struct X_MissionUAV_n_T {
    real_T Integrator_CSTATE[8];       // '<S2>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S4>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S4>/dotBankTD'
};

// State derivatives for model 'MissionUAV'
struct XDot_MissionUAV_n_T {
    real_T Integrator_CSTATE[8];       // '<S2>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S4>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S4>/dotBankTD'
};

// State Disabled for model 'MissionUAV'
struct XDis_MissionUAV_n_T {
    boolean_T Integrator_CSTATE[8];    // '<S2>/Integrator'
    boolean_T TD_Bank_CSTATE;          // '<S4>/TD_Bank'
    boolean_T dotBankTD_CSTATE;        // '<S4>/dotBankTD'
};

// Zero-crossing (trigger) state for model 'MissionUAV'
struct ZCE_MissionUAV_T {
    ZCSigState Integrator_Reset_ZCE;   // '<S2>/Integrator'
    ZCSigState TD_Bank_Reset_ZCE;      // '<S4>/TD_Bank'
    ZCSigState dotBankTD_Reset_ZCE;    // '<S4>/dotBankTD'
};

// Real-time Model Data Structure
struct tag_RTM_MissionUAV_T {
    const char_T **errorStatus;
    RTWSolverInfo *solverInfo;
    const rtTimingBridge *timingBridge;

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

struct MdlrefDW_MissionUAV_T {
    DW_MissionUAV_f_T rtdw;
    RT_MODEL_MissionUAV_T rtm;
    ZCE_MissionUAV_T rtzce;
};

// Model reference registration function
extern void MissionUAV_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
    *timingBridge, RT_MODEL_MissionUAV_T *const MissionUAV_M, ZCE_MissionUAV_T
    *localZCE);
extern void MissionUAV_Init(RT_MODEL_MissionUAV_T * const MissionUAV_M,
    DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX);
extern void MissionUAV_Reset(RT_MODEL_MissionUAV_T * const MissionUAV_M,
    DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX);
extern void MissionUAV_Deriv(const real_T *rtu_ResetState, DW_MissionUAV_f_T
    *localDW, XDot_MissionUAV_n_T *localXdot);
extern void MissionUAV_Update(DW_MissionUAV_f_T *localDW);
extern void MissionUAV(RT_MODEL_MissionUAV_T * const MissionUAV_M, const real_T *
                       rtu_ResetState, const real_T rtu_StartPos[8], const
                       real_T *rtu_UAVGuidanceCmd_Height, const real_T
                       *rtu_UAVGuidanceCmd_AirSpeed, const real_T
                       *rtu_UAVGuidanceCmd_HeadingAngle, real_T
                       *rty_SimUAVState_North, real_T *rty_SimUAVState_East,
                       real_T *rty_SimUAVState_Height, real_T
                       *rty_SimUAVState_AirSpeed, real_T
                       *rty_SimUAVState_HeadingAngle, real_T
                       *rty_SimUAVState_FlightPathAngle, real_T
                       *rty_SimUAVState_RollAngle, real_T
                       *rty_SimUAVState_RollAngleRate, DW_MissionUAV_f_T
                       *localDW, X_MissionUAV_n_T *localX);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S1>/RateTransitionRollTD' : Eliminated since input and output rates are identical
//  Block '<S1>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'MissionUAV'
//  '<S1>'   : 'MissionUAV/MissionUAV'
//  '<S2>'   : 'MissionUAV/MissionUAV/MissionUAV'
//  '<S3>'   : 'MissionUAV/MissionUAV/SimHdgControl'
//  '<S4>'   : 'MissionUAV/MissionUAV/TD'
//  '<S5>'   : 'MissionUAV/MissionUAV/TD/fhan_Bank'

#endif                                 // RTW_HEADER_MissionUAV_h_

//
// File trailer for generated code.
//
// [EOF]
//
