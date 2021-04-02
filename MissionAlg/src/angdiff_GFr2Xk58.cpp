//
// File: angdiff_GFr2Xk58.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.167
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Mar 23 16:05:29 2021
//
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <cmath>
#include "angdiff_GFr2Xk58.h"

// Function for MATLAB Function: '<Root>/AngLog'
real_T angdiff_GFr2Xk58(real_T x, real_T y)
{
  real_T delta;
  real_T q;
  real_T thetaWrap;
  boolean_T rEQ0;
  delta = y - x;
  if (std::abs(delta) > 3.1415926535897931) {
    if (rtIsNaN(delta + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (rtIsInf(delta + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (delta + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      thetaWrap = std::fmod(delta + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        q = std::abs((delta + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (delta + 3.1415926535897931 < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }

    if ((thetaWrap == 0.0) && (delta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    delta = thetaWrap - 3.1415926535897931;
  }

  return delta;
}

//
// File trailer for generated code.
//
// [EOF]
//
