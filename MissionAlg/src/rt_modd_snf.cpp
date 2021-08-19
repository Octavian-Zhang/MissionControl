#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <cfloat>
#include <cmath>
#include "rt_modd_snf.h"

real_T rt_modd_snf(real_T u0, real_T u1)
{
    real_T q;
    real_T y;
    boolean_T yEq;
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
        y = std::fmod(u0, u1);
        yEq = (y == 0.0);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (yEq) ^ 1))) & (u1 > std::floor(u1))))) {
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
