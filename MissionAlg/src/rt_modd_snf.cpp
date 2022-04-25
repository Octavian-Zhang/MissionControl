//
// File: rt_modd_snf.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 2.93
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun Apr 24 02:53:00 2022
//
#include "rtwtypes.h"
#include "rt_modd_snf.h"
#include <cmath>
#include <cfloat>

extern "C" {

#include "rt_nonfinite.h"

}
    real_T rt_modd_snf(real_T u0, real_T u1)
{
    real_T y;
    y = u0;
    if (u1 == 0.0) {
        if (u0 == 0.0) {
            y = u1;
        }
    } else if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                  static_cast<boolean_T>(static_cast<int32_T>
                   (static_cast<int32_T>(std::isnan(u0)) | static_cast<int32_T>
                    (std::isnan(u1))))) | static_cast<int32_T>(std::isinf(u0)))))
    {
        y = (rtNaN);
    } else if (u0 == 0.0) {
        y = 0.0 / u1;
    } else if (std::isinf(u1)) {
        if ((u1 < 0.0) != (u0 < 0.0)) {
            y = u1;
        }
    } else {
        boolean_T yEq;
        y = std::fmod(u0, u1);
        yEq = (y == 0.0);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (yEq) ^ 1))) & (u1 > std::floor(u1))))) {
            real_T q;
            q = std::abs(u0 / u1);
            yEq = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q - std::
                floor(q + 0.5)) > DBL_EPSILON * q) ^ 1));
        }

        if (yEq) {
            y = u1 * 0.0;
        } else if ((u0 < 0.0) != (u1 < 0.0)) {
            y += u1;
        }
    }

    return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
