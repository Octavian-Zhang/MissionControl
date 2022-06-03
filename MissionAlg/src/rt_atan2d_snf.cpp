//
// File: rt_atan2d_snf.cpp
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri Jun  3 15:12:52 2022
//
#include "rtwtypes.h"
#include "rt_atan2d_snf.h"
#include <cmath>
#include "rt_defines.h"

extern "C" {

#include "rtGetNaN.h"

}
    extern "C"
{

#include "rt_nonfinite.h"

}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
    real_T y;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isnan(u0)) | static_cast<int32_T>(std::isnan(u1))))) {
        y = (rtNaN);
    } else if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(u0)) & static_cast<int32_T>(std::isinf(u1))))) {
        int32_T u0_0;
        int32_T u1_0;
        if (u0 > 0.0) {
            u0_0 = 1;
        } else {
            u0_0 = -1;
        }

        if (u1 > 0.0) {
            u1_0 = 1;
        } else {
            u1_0 = -1;
        }

        y = std::atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
    } else if (u1 == 0.0) {
        if (u0 > 0.0) {
            y = RT_PI / 2.0;
        } else if (u0 < 0.0) {
            y = -(RT_PI / 2.0);
        } else {
            y = 0.0;
        }
    } else {
        y = std::atan2(u0, u1);
    }

    return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
