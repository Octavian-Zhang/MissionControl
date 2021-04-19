//
// File: wrapToPi_iEuDNbvh.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 19 15:17:51 2021
//
#include "rtwtypes.h"
#include <cmath>
#include "mod_dBqh4Vat.h"
#include "wrapToPi_iEuDNbvh.h"

// Function for MATLAB Function: '<S68>/WayPointGenerator'
void wrapToPi_iEuDNbvh(real_T *theta)
{
  real_T thetaWrap;
  if (std::abs(*theta) > 3.1415926535897931) {
    thetaWrap = mod_dBqh4Vat(*theta + 3.1415926535897931);
    if ((thetaWrap == 0.0) && (*theta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    *theta = thetaWrap - 3.1415926535897931;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
