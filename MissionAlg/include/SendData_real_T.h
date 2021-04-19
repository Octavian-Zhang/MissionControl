//
// File: SendData_real_T.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 19 16:23:29 2021
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

#ifndef RTW_HEADER_SendData_real_T_h_
#define RTW_HEADER_SendData_real_T_h_
#include "rtwtypes.h"

class SendData_real_T
{
 public:
  virtual void SendData(const real_T *data, int32_T length, int32_T *status) = 0;
  virtual ~SendData_real_T()
  {
  }
};

#endif                                 // RTW_HEADER_SendData_real_T_h_

//
// File trailer for generated code.
//
// [EOF]
//
