//
// File: MissionUAV.h
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 4.1
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Nov 25 19:06:22 2022
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
#include "rt_zcfcn.h"

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include "zero_crossing_types.h"

// Block signals and states (default storage) for system '<S8>/TD_Bank'
struct DW_TD_Bank_MissionUAV_T {
    real_T DelayInput_DSTATE;          // '<S10>/DelayInput'
    real_T DelayOutput_DSTATE;         // '<S10>/DelayOutput'
};

// Zero-crossing (trigger) state for system '<S8>/TD_Bank'
struct ZCV_TD_Bank_MissionUAV_T {
    real_T DelayInput_Reset_ZC;        // '<S10>/DelayInput'
    real_T DelayOutput_Reset_ZC;       // '<S10>/DelayOutput'
};

// Zero-crossing (trigger) state for system '<S8>/TD_Bank'
struct ZCE_TD_Bank_MissionUAV_T {
    ZCSigState DelayInput_Reset_ZCE;   // '<S10>/DelayInput'
    ZCSigState DelayOutput_Reset_ZCE;  // '<S10>/DelayOutput'
};

// Block signals and states (default storage) for model 'MissionUAV'
struct DW_MissionUAV_f_T {
    DW_TD_Bank_MissionUAV_T dotBankTD; // '<S8>/dotBankTD'
    DW_TD_Bank_MissionUAV_T TD_Bank;   // '<S8>/TD_Bank'
    FILE* eml_openfiles[20];           // '<S1>/Get Max Bank'
    FILE* eml_openfiles_a[20];         // '<S1>/Get Speed Limit'
    robotics_core_internal_system_navigation_StateVector2Struct_MissionUAV_T obj;// '<S5>/StateVector2Struct' 
    DubinsObjSingleton_MissionUAV_a_T SingletonInstance;// '<S1>/Get Speed Limit' 
    robotics_core_internal_system_navigation_Model_MissionUAV_T obj_j;// '<S5>/ComputeDerivative' 
    DubinsObjSingleton_MissionUAV_T SingletonInstance_p;// '<S1>/Get Max Bank'
    real_T DelayInput_DSTATE[8];       // '<S9>/DelayInput'
    real_T DelayOutput_DSTATE[8];      // '<S9>/DelayOutput'
    boolean_T objisempty;              // '<S5>/StateVector2Struct'
    boolean_T icLoad;                  // '<S9>/DelayOutput'
    boolean_T objisempty_a;            // '<S5>/ComputeDerivative'
    boolean_T SingletonInstance_not_empty;// '<S1>/Get Speed Limit'
    boolean_T SingletonInstance_not_empty_p;// '<S1>/Get Max Bank'
};

// Zero-crossing (trigger) state for model 'MissionUAV'
struct ZCV_MissionUAV_g_T {
    ZCV_TD_Bank_MissionUAV_T dotBankTD;// '<S8>/TD_Bank'
    ZCV_TD_Bank_MissionUAV_T TD_Bank;  // '<S8>/TD_Bank'
    real_T DelayInput_Reset_ZC_d;      // '<S9>/DelayInput'
    real_T DelayOutput_Reset_ZC_i;     // '<S9>/DelayOutput'
};

// Zero-crossing (trigger) state for model 'MissionUAV'
struct ZCE_MissionUAV_T {
    ZCE_TD_Bank_MissionUAV_T dotBankTD;// '<S8>/dotBankTD'
    ZCE_TD_Bank_MissionUAV_T TD_Bank;  // '<S8>/TD_Bank'
    ZCSigState DelayInput_Reset_ZCE_g; // '<S9>/DelayInput'
    ZCSigState DelayOutput_Reset_ZCE_a;// '<S9>/DelayOutput'
};

// Real-time Model Data Structure
struct tag_RTM_MissionUAV_T {
    const char_T **errorStatus;
};

struct MdlrefDW_MissionUAV_T {
    DW_MissionUAV_f_T rtdw;
    RT_MODEL_MissionUAV_T rtm;
    ZCE_MissionUAV_T rtzce;
};

// Model reference registration function
extern void MissionUAV_initialize(const char_T **rt_errorStatus,
    RT_MODEL_MissionUAV_T *const MissionUAV_M, ZCE_MissionUAV_T *localZCE);
extern void MissionUAV_TD_Bank_Update(real_T rtu_InputU, real_T *rty_OutputY,
    DW_TD_Bank_MissionUAV_T *localDW);
extern void MissionUAV_TD_Bank(const real_T *rtu_Reset, real_T *rty_OutputY,
    real_T rtp_deltaT, DW_TD_Bank_MissionUAV_T *localDW,
    ZCE_TD_Bank_MissionUAV_T *localZCE);
extern void MissionUAV_Init(DW_MissionUAV_f_T *localDW);
extern void MissionUAV(const real_T *rtu_ResetState, const real_T rtu_StartPos[8],
                       const real_T *rtu_UAVGuidanceCmd_Height, const real_T
                       *rtu_UAVGuidanceCmd_AirSpeed, const real_T
                       *rtu_UAVGuidanceCmd_HeadingAngle, real_T
                       *rty_SimUAVState_North, real_T *rty_SimUAVState_East,
                       real_T *rty_SimUAVState_Height, real_T
                       *rty_SimUAVState_AirSpeed, real_T
                       *rty_SimUAVState_HeadingAngle, real_T
                       *rty_SimUAVState_FlightPathAngle, real_T
                       *rty_SimUAVState_RollAngle, real_T
                       *rty_SimUAVState_RollAngleRate, DW_MissionUAV_f_T
                       *localDW, ZCE_MissionUAV_T *localZCE);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/Data Type Duplicate' : Unused code path elimination
//  Block '<S6>/Data Type Propagation' : Unused code path elimination
//  Block '<S7>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/Data Type Propagation' : Unused code path elimination
//  Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S9>/Reshape' : Reshape block reduction
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
//  '<S4>'   : 'MissionUAV/MissionUAV/Heading Control'
//  '<S5>'   : 'MissionUAV/MissionUAV/MissionUAV'
//  '<S6>'   : 'MissionUAV/MissionUAV/Saturation Dynamic'
//  '<S7>'   : 'MissionUAV/MissionUAV/Saturation Dynamic Speed Limit'
//  '<S8>'   : 'MissionUAV/MissionUAV/TD'
//  '<S9>'   : 'MissionUAV/MissionUAV/MissionUAV/DiscreteIntegrator'
//  '<S10>'  : 'MissionUAV/MissionUAV/TD/TD_Bank'
//  '<S11>'  : 'MissionUAV/MissionUAV/TD/dotBankTD'
//  '<S12>'  : 'MissionUAV/MissionUAV/TD/fhan_Bank'

#endif                                 // RTW_HEADER_MissionUAV_h_

//
// File trailer for generated code.
//
// [EOF]
//
