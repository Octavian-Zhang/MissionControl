//
// File: rt_remd_snf.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 4.33
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:24:11 2022
//
#include "rtwtypes.h"
#include "rt_remd_snf.h"
#include <cmath>
#include <cfloat>

extern "C"
{

#include "rt_nonfinite.h"

}

real_T rt_remd_snf(real_T u0, real_T u1)
{
    real_T y;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
              isnan(u0)) | static_cast<int32_T>(std::isnan(u1))))) |
            static_cast<int32_T>(std::isinf(u0))))) {
        y = (rtNaN);
    } else if (std::isinf(u1)) {
        y = u0;
    } else if (static_cast<boolean_T>(static_cast<int32_T>((u1 != 0.0) & (u1 !=
                  std::trunc(u1))))) {
        real_T q;
        q = std::abs(u0 / u1);
        if (static_cast<boolean_T>(static_cast<int32_T>((std::abs(q - std::floor
                (q + 0.5)) > DBL_EPSILON * q) ^ 1))) {
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
