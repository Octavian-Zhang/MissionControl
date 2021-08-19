#include "rtwtypes.h"
#include <cmath>
#include "floor_jeUa7tf2.h"

creal_T floor_jeUa7tf2(const creal_T a)
{
    creal_T b;
    real_T ahi;
    real_T b_ahi;
    real_T tmp;
    b.re = std::floor(a.re);
    b.im = 0.0;
    if (b.re == a.re) {
        tmp = std::floor(a.im);
        ahi = 0.0;
        b_ahi = b.re;
        if (tmp != 0.0) {
            b_ahi = b.re + tmp;
            ahi = tmp - (b_ahi - b.re);
        }

        if (std::isnan(ahi)) {
            ahi = 0.0;
        }

        b.re = b_ahi;
        b.im = ahi;
    }

    return b;
}
