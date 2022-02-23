//
// File: RecvData_IndividualUAVCmdT.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.91
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Wed Feb 23 00:38:39 2022
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
#include "rtwtypes.h"
#include "DatalinkInterface.h"

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
