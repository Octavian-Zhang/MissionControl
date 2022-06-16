//
// File: MissionUAV.h
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 3.8
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jun 16 22:37:10 2022
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
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MissionUAV_types.h"

extern "C" {

#include "rtGetInf.h"

}
    extern "C"
{

#include "rt_nonfinite.h"

}

extern "C" {

#include "rtGetNaN.h"

}
#include "model_reference_types.h"
#include "zero_crossing_types.h"

// Block signals and states (default storage) for model 'MissionUAV'
struct DW_MissionUAV_f_T {
    FILE* eml_openfiles[20];           // '<S1>/Get Max Bank'
    FILE* eml_openfiles_p[20];         // '<S1>/Get Speed Limit'
    robotics_core_internal_system_navigation_StateVector2Struct_MissionUAV_T obj;// '<S4>/StateVector2Struct' 
    DubinsObjSingleton_MissionUAV_b_T SingletonInstance;// '<S1>/Get Speed Limit' 
    robotics_core_internal_system_navigation_Model_MissionUAV_T obj_j;// '<S4>/ComputeDerivative' 
    DubinsObjSingleton_MissionUAV_T SingletonInstance_f;// '<S1>/Get Max Bank'
    FixedWingGuidanceEnvironmentBus FixedWingGuidanceEnvironmentBus_p;
                                      // '<S1>/FixedWingGuidanceEnvironmentBus'
    real_T ComputeDerivative[8];       // '<S4>/ComputeDerivative'
    real_T SpdLmt[2];                  // '<S1>/Get Speed Limit'
    real_T Max;                        // '<S1>/Max'
    real_T Min;                        // '<S1>/Min'
    real_T MinBankAng;                 // '<S1>/MinBankAng'
    real_T Inverse;                    // '<S1>/Inverse'
    real_T dotBankTD;                  // '<S8>/dotBankTD'
    real_T fh;                         // '<S8>/fhan_Bank'
    int_T Integrator_IWORK;            // '<S4>/Integrator'
    boolean_T objisempty;              // '<S4>/StateVector2Struct'
    boolean_T objisempty_a;            // '<S4>/ComputeDerivative'
    boolean_T SingletonInstance_not_empty;// '<S1>/Get Speed Limit'
    boolean_T SingletonInstance_not_empty_m;// '<S1>/Get Max Bank'
};

// Continuous states for model 'MissionUAV'
struct X_MissionUAV_n_T {
    real_T Integrator_CSTATE[8];       // '<S4>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S8>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S8>/dotBankTD'
};

// State derivatives for model 'MissionUAV'
struct XDot_MissionUAV_n_T {
    real_T Integrator_CSTATE[8];       // '<S4>/Integrator'
    real_T TD_Bank_CSTATE;             // '<S8>/TD_Bank'
    real_T dotBankTD_CSTATE;           // '<S8>/dotBankTD'
};

// State Disabled for model 'MissionUAV'
struct XDis_MissionUAV_n_T {
    boolean_T Integrator_CSTATE[8];    // '<S4>/Integrator'
    boolean_T TD_Bank_CSTATE;          // '<S8>/TD_Bank'
    boolean_T dotBankTD_CSTATE;        // '<S8>/dotBankTD'
};

// Zero-crossing (trigger) state for model 'MissionUAV'
struct ZCE_MissionUAV_T {
    ZCSigState Integrator_Reset_ZCE;   // '<S4>/Integrator'
    ZCSigState TD_Bank_Reset_ZCE;      // '<S8>/TD_Bank'
    ZCSigState dotBankTD_Reset_ZCE;    // '<S8>/dotBankTD'
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
//  Block '<S5>/Data Type Duplicate' : Unused code path elimination
//  Block '<S5>/Data Type Propagation' : Unused code path elimination
//  Block '<S6>/Data Type Duplicate' : Unused code path elimination
//  Block '<S6>/Data Type Propagation' : Unused code path elimination
//  Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
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
//  '<S2>'   : 'MissionUAV/MissionUAV/Get Max Bank'
//  '<S3>'   : 'MissionUAV/MissionUAV/Get Speed Limit'
//  '<S4>'   : 'MissionUAV/MissionUAV/MissionUAV'
//  '<S5>'   : 'MissionUAV/MissionUAV/Saturation Dynamic'
//  '<S6>'   : 'MissionUAV/MissionUAV/Saturation Dynamic Speed Limit'
//  '<S7>'   : 'MissionUAV/MissionUAV/SimHdgControl'
//  '<S8>'   : 'MissionUAV/MissionUAV/TD'
//  '<S9>'   : 'MissionUAV/MissionUAV/TD/fhan_Bank'

#endif                                 // RTW_HEADER_MissionUAV_h_

//
// File trailer for generated code.
//
// [EOF]
//
