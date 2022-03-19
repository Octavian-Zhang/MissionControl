//
// File: SendData_IndividualUAVCmdT.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.98
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Fri Mar 18 20:29:43 2022
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

#ifndef RTW_HEADER_SendData_IndividualUAVCmdT_h_
#define RTW_HEADER_SendData_IndividualUAVCmdT_h_
#include "rtwtypes.h"
#include "DatalinkInterface.h"

class SendData_IndividualUAVCmdT
{
  public:
    virtual void SendData(const IndividualUAVCmd *data, int32_T length, int32_T *
                          status) = 0;
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
