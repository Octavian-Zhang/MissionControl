//
// File: SendData_IndividualUAVCmdT.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.409
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu May  6 18:31:00 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives:
//    1. Safety precaution
//    2. Execution efficiency
//    3. RAM efficiency
//    4. ROM efficiency
// Validation result: Not run
//

#ifndef RTW_HEADER_SendData_IndividualUAVCmdT_h_
#define RTW_HEADER_SendData_IndividualUAVCmdT_h_
#include "rtwtypes.h"
#include "DatalinkInterface.h"

class SendData_IndividualUAVCmdT
{
 public:
  virtual void SendData(const IndividualUAVCmd *data, int32_T length, int32_T
                        *status) = 0;
  virtual ~SendData_IndividualUAVCmdT()
  {
  }
};

#endif                               // RTW_HEADER_SendData_IndividualUAVCmdT_h_

//
// File trailer for generated code.
//
// [EOF]
//
