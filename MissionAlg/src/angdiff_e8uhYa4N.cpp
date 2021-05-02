//
// File: angdiff_e8uhYa4N.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  2 12:09:34 2021
//
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <cmath>
#include "angdiff_e8uhYa4N.h"

// Function for MATLAB Function: '<S4>/AngLog'
real_T angdiff_e8uhYa4N(real_T x, real_T y)
{
  real_T delta;
  real_T q;
  real_T thetaWrap;
  boolean_T rEQ0;
  delta = y - x;
  if (std::abs(delta) > 3.1415926535897931) {
    if (std::isnan(delta + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (std::isinf(delta + 3.1415926535897931)) {
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
