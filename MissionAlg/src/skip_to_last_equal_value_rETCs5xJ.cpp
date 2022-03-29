//
// File: skip_to_last_equal_value_rETCs5xJ.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 2.79
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Tue Mar 29 06:49:07 2022
//
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <math.h>
#include "skip_to_last_equal_value_rETCs5xJ.h"

// Function for MATLAB Function: '<S178>/WayPointGenerator'
real_T skip_to_last_equal_value_rETCs5xJ(int32_T *k, const real_T x[28], const
    int32_T perm[28])
{
    real_T xk;
    int32_T exponent;
    boolean_T exitg1;
    xk = x[static_cast<int32_T>(perm[static_cast<int32_T>(*k - 1)] - 1)];
    exitg1 = false;
    while ((!exitg1) && (*k < 28)) {
        real_T absx;
        real_T tmp;
        boolean_T p;
        absx = std::abs(xk / 2.0);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(absx)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(absx)) ^ 1)))))) {
            if (absx <= 2.2250738585072014E-308) {
                absx = 4.94065645841247E-324;
            } else {
                frexp(absx, &exponent);
                absx = std::ldexp(1.0, static_cast<int32_T>(exponent - 53));
            }
        } else {
            absx = (rtNaN);
        }

        tmp = x[static_cast<int32_T>(perm[*k] - 1)];
        if (std::abs(xk - tmp) < absx) {
            p = true;
        } else if (std::isinf(tmp)) {
            if (std::isinf(xk)) {
                p = ((tmp > 0.0) == (xk > 0.0));
            } else {
                p = false;
            }
        } else {
            p = false;
        }

        if (p) {
            *k = static_cast<int32_T>(*k + 1);
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
