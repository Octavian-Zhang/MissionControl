#include "rtwtypes.h"
#include <cmath>
#include "split_MzIWb6Db.h"

creal_T split_MzIWb6Db(real_T a)
{
    creal_T aout;
    real_T temp;
    if (std::abs(a) <= 6.69692879491417E+299) {
        temp = 1.34217729E+8 * a;
        temp -= temp - a;
        aout.re = temp;
        aout.im = a - temp;
    } else if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                  static_cast<boolean_T>(static_cast<int32_T>
                   (static_cast<int32_T>(std::isinf(a)) ^ 1))) &
                 static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                   (static_cast<int32_T>(std::isnan(a)) ^ 1)))))) {
        a *= 3.7252902984619141E-9;
        temp = 1.34217729E+8 * a;
        temp -= temp - a;
        aout.re = temp * 2.68435456E+8;
        aout.im = (a - temp) * 2.68435456E+8;
    } else {
        aout.re = a;
        aout.im = 0.0;
    }

    return aout;
}
