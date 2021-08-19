#include "rtwtypes.h"
#include <cmath>
#include <math.h>
#include "skip_to_last_equal_value_ZlLNIyBv.h"

real_T skip_to_last_equal_value_ZlLNIyBv(int32_T *k, const real_T x[28], const
    int32_T perm[28])
{
    real_T absx;
    real_T xk;
    int32_T exponent;
    boolean_T exitg1;
    xk = x[static_cast<int32_T>(perm[static_cast<int32_T>(*k - 1)] - 1)];
    exitg1 = false;
    while ((!exitg1) && (*k < 28)) {
        absx = std::abs(xk / 2.0);
        if (absx <= 2.2250738585072014E-308) {
            absx = 4.94065645841247E-324;
        } else {
            frexp(absx, &exponent);
            absx = std::ldexp(1.0, static_cast<int32_T>(exponent - 53));
        }

        if (std::abs(xk - x[static_cast<int32_T>(perm[*k] - 1)]) < absx) {
            *k = static_cast<int32_T>(*k + 1);
        } else {
            exitg1 = true;
        }
    }

    return xk;
}
