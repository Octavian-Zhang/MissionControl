//
// File: rt_hypotd_snf.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 5.10
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:19:22 2022
//
#include "rtwtypes.h"
#include "rt_hypotd_snf.h"
#include <cmath>

extern "C"
{

#include "rt_nonfinite.h"

}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
    real_T a;
    real_T b;
    real_T y;
    a = std::abs(u0);
    b = std::abs(u1);
    if (a < b) {
        a /= b;
        y = std::sqrt(a * a + 1.0) * b;
    } else if (a > b) {
        b /= a;
        y = std::sqrt(b * b + 1.0) * a;
    } else if (std::isnan(b)) {
        y = (rtNaN);
    } else {
        y = a * 1.4142135623730951;
    }

    return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
