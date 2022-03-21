//
// File: rt_powd_snf.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.85
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Mar 21 00:55:39 2022
//
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <cmath>
#include "rt_powd_snf.h"

real_T rt_powd_snf(real_T u0, real_T u1)
{
    real_T y;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isnan(u0)) | static_cast<int32_T>(std::isnan(u1))))) {
        y = (rtNaN);
    } else {
        real_T tmp;
        real_T tmp_0;
        tmp = std::abs(u0);
        tmp_0 = std::abs(u1);
        if (std::isinf(u1)) {
            if (tmp == 1.0) {
                y = 1.0;
            } else if (tmp > 1.0) {
                if (u1 > 0.0) {
                    y = (rtInf);
                } else {
                    y = 0.0;
                }
            } else if (u1 > 0.0) {
                y = 0.0;
            } else {
                y = (rtInf);
            }
        } else if (tmp_0 == 0.0) {
            y = 1.0;
        } else if (tmp_0 == 1.0) {
            if (u1 > 0.0) {
                y = u0;
            } else {
                y = 1.0 / u0;
            }
        } else if (u1 == 2.0) {
            y = u0 * u0;
        } else if (static_cast<boolean_T>(static_cast<int32_T>((u1 == 0.5) & (u0
                      >= 0.0)))) {
            y = std::sqrt(u0);
        } else if (static_cast<boolean_T>(static_cast<int32_T>((u0 < 0.0) & (u1 >
                      std::floor(u1))))) {
            y = (rtNaN);
        } else {
            y = std::pow(u0, u1);
        }
    }

    return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
