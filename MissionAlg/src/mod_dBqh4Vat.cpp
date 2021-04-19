//
// File: mod_dBqh4Vat.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 19 16:23:29 2021
//
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <cmath>
#include "mod_dBqh4Vat.h"

// Function for MATLAB Function: '<S68>/WayPointGenerator'
real_T mod_dBqh4Vat(real_T x)
{
  real_T q;
  real_T r;
  boolean_T rEQ0;
  if (std::isnan(x)) {
    r = (rtNaN);
  } else if (std::isinf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = std::fmod(x, 6.2831853071795862);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      q = std::abs(x / 6.2831853071795862);
      rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 6.2831853071795862;
    }
  }

  return r;
}

//
// File trailer for generated code.
//
// [EOF]
//