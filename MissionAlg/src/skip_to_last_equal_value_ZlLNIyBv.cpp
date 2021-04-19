//
// File: skip_to_last_equal_value_ZlLNIyBv.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 19 16:23:29 2021
//
#include "rtwtypes.h"
#include <cmath>
#include <math.h>
#include "skip_to_last_equal_value_ZlLNIyBv.h"

// Function for MATLAB Function: '<S68>/WayPointGenerator'
real_T skip_to_last_equal_value_ZlLNIyBv(int32_T *k, const real_T x[28], const
  int32_T perm[28])
{
  real_T absx;
  real_T xk;
  int32_T exponent;
  boolean_T exitg1;
  xk = x[perm[*k - 1] - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < 28)) {
    absx = std::abs(xk / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = std::ldexp(1.0, exponent - 53);
    }

    if (std::abs(xk - x[perm[*k] - 1]) < absx) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return xk;
}

//
// File trailer for generated code.
//
// [EOF]
//
