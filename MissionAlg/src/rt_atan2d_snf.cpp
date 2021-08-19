#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <cmath>
#include "rt_defines.h"
#include "rt_atan2d_snf.h"

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
    real_T y;
    int32_T u0_0;
    int32_T u1_0;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isnan(u0)) | static_cast<int32_T>(std::isnan(u1))))) {
        y = (rtNaN);
    } else if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(u0)) & static_cast<int32_T>(std::isinf(u1))))) {
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
