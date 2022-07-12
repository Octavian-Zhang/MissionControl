//
// File: RecvData_IndividualUAVCmdT.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.288
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri Jul  1 18:01:36 2022
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

#ifndef RTW_HEADER_RecvData_IndividualUAVCmdT_h_
#define RTW_HEADER_RecvData_IndividualUAVCmdT_h_
#include "DatalinkInterface.h"
#include "rtwtypes.h"

class RecvData_IndividualUAVCmdT
{
  public:
    virtual void RecvData(IndividualUAVCmd *data, int32_T length, int32_T
                          *status) = 0;
    virtual ~RecvData_IndividualUAVCmdT()
    {
    }
};

#endif                               // RTW_HEADER_RecvData_IndividualUAVCmdT_h_

//
// File trailer for generated code.
//
// [EOF]
//
