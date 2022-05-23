//
// File: mod_d42kHWKw.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 3.19
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun May 22 08:43:45 2022
//
#include "rtwtypes.h"
#include "mod_d42kHWKw.h"
#include <cmath>

extern "C" {

#include "rt_nonfinite.h"

}
// Function for MATLAB Function: '<S96>/StartPointGenerator'
    real_T mod_d42kHWKw(real_T x)
{
    real_T r;
    if (std::isnan(x)) {
        r = (rtNaN);
    } else if (std::isinf(x)) {
        r = (rtNaN);
    } else if (x == 0.0) {
        r = 0.0;
    } else {
        boolean_T rEQ0;
        r = std::fmod(x, 6.2831853071795862);
        rEQ0 = (r == 0.0);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rEQ0) ^ 1))) {
            real_T q;
            q = std::abs(x / 6.2831853071795862);
            rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q - std::
                floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
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
