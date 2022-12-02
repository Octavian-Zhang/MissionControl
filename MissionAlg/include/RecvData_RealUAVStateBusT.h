//
// File: RecvData_RealUAVStateBusT.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 5.38
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 17:15:53 2022
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

#ifndef RTW_HEADER_RecvData_RealUAVStateBusT_h_
#define RTW_HEADER_RecvData_RealUAVStateBusT_h_
#include "DatalinkInterface.h"
#include "rtwtypes.h"

class RecvData_RealUAVStateBusT
{
  public:
    virtual void RecvData(RealUAVStateBus *data, int32_T length, int32_T *status)
        = 0;
    virtual ~RecvData_RealUAVStateBusT()
        = default;
};

#endif                                // RTW_HEADER_RecvData_RealUAVStateBusT_h_

//
// File trailer for generated code.
//
// [EOF]
//
