//
// File: angdiff_9SMt2WI9.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.11
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Wed Feb 23 00:20:42 2022
//
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <cmath>
#include "angdiff_9SMt2WI9.h"

// Function for MATLAB Function: '<S4>/AngLog'
real_T angdiff_9SMt2WI9(real_T x, real_T y)
{
    real_T delta;
    delta = y - x;
    if (std::abs(delta) > 3.1415926535897931) {
        real_T thetaWrap;
        if (std::isnan(delta + 3.1415926535897931)) {
            thetaWrap = (rtNaN);
        } else if (std::isinf(delta + 3.1415926535897931)) {
            thetaWrap = (rtNaN);
        } else if (delta + 3.1415926535897931 == 0.0) {
            thetaWrap = 0.0;
        } else {
            boolean_T rEQ0;
            thetaWrap = std::fmod(delta + 3.1415926535897931, 6.2831853071795862);
            rEQ0 = (thetaWrap == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                real_T q;
                q = std::abs((delta + 3.1415926535897931) / 6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q -
                    std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
            }

            if (rEQ0) {
                thetaWrap = 0.0;
            } else if (delta + 3.1415926535897931 < 0.0) {
                thetaWrap += 6.2831853071795862;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((delta +
                3.1415926535897931 > 0.0) & (thetaWrap == 0.0)))) {
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
