//
// File: angdiff_WJjwZrD2.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 4.157
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri May 27 22:56:41 2022
//
#include "rtwtypes.h"
#include "angdiff_WJjwZrD2.h"
#include <cmath>

extern "C" {

#include "rt_nonfinite.h"

}
// Function for MATLAB Function: '<S9>/AngLog'
    real_T angdiff_WJjwZrD2(real_T x, real_T y)
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
