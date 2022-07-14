//
// File: rt_hypotd_snf.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 4.175
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jul 14 15:00:22 2022
//
#include "rtwtypes.h"
#include "rt_hypotd_snf.h"
#include <cmath>

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
    real_T a;
    real_T y;
    a = std::abs(u0);
    y = std::abs(u1);
    if (a < y) {
        a /= y;
        y *= std::sqrt(a * a + 1.0);
    } else if (a > y) {
        y /= a;
        y = std::sqrt(y * y + 1.0) * a;
    } else if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(y)) ^ 1))) {
        y = a * 1.4142135623730951;
    }

    return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
