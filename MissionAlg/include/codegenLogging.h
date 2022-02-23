//
// File: codegenLogging.h
//
// Code generated for Simulink model 'codegenLogging'.
//
// Model version                  : 3.62
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Wed Feb 23 00:19:48 2022
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
#ifndef RTW_HEADER_codegenLogging_h_
#define RTW_HEADER_codegenLogging_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "codegenLogging_types.h"

// Real-time Model Data Structure
struct tag_RTM_codegenLogging_T {
    const char_T **errorStatus;
};

struct MdlrefDW_codegenLogging_T {
    RT_MODEL_codegenLogging_T rtm;
};

// Model reference registration function
extern void codegenLogging_initialize(const char_T **rt_errorStatus,
    RT_MODEL_codegenLogging_T *const codegenLogging_M);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/ModelLogging' : Unused code path elimination


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
//  '<Root>' : 'codegenLogging'

#endif                                 // RTW_HEADER_codegenLogging_h_

//
// File trailer for generated code.
//
// [EOF]
//
