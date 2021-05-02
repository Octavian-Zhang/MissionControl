//
// File: rt_remd_snf.cpp
//
// Code generated for Simulink model 'PreemptableMissionModeSelector'.
//
// Model version                  : 2.427
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  2 12:25:38 2021
//
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <cfloat>
#include <cmath>
#include "rt_remd_snf.h"

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
    y = (rtNaN);
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
