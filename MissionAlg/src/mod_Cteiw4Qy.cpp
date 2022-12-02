//
// File: mod_Cteiw4Qy.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 4.42
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 16:52:33 2022
//
#include "rtwtypes.h"
#include "mod_Cteiw4Qy.h"
#include <cmath>

extern "C"
{

#include "rt_nonfinite.h"

}

// Function for MATLAB Function: '<S77>/StartPointGenerator'
real_T mod_Cteiw4Qy(real_T x)
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
