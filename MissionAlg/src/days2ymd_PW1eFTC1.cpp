//
// File: days2ymd_PW1eFTC1.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 5.38
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 17:15:53 2022
//
#include "rtwtypes.h"
#include "days2ymd_PW1eFTC1.h"
#include <cmath>
#include "div_s32.h"

// Function for MATLAB Function: '<S83>/CommandCheck'
void days2ymd_PW1eFTC1(real_T days, real_T *y, real_T *m, real_T *d)
{
    real_T g;
    if (static_cast<boolean_T>(static_cast<int32_T>(((days + 719529.0) - 61.0 >=
           0.0) & ((days + 719529.0) - 61.0 <= 2.147483647E+9)))) {
        int32_T ia_quot;
        int32_T ib_rem;
        int32_T ic_quot;
        int32_T ic_rem;
        int32_T idn;
        int32_T ig_rem;
        g = std::round((days + 719529.0) - 61.0);
        if (g < 2.147483648E+9) {
            if (g >= -2.147483648E+9) {
                idn = static_cast<int32_T>(g);
            } else {
                idn = MIN_int32_T;
            }
        } else {
            idn = MAX_int32_T;
        }

        ig_rem = static_cast<int32_T>(idn - static_cast<int32_T>(146097 *
            div_s32(idn, 146097)));
        ic_quot = static_cast<int32_T>(std::trunc(static_cast<real_T>(ig_rem) /
            36524.0));
        ic_rem = static_cast<int32_T>(ig_rem - static_cast<int32_T>(36524 *
            div_s32(ig_rem, 36524)));
        if (ic_quot > 3) {
            ic_quot = 3;
            ic_rem = static_cast<int32_T>(ig_rem - 109572);
        }

        ib_rem = static_cast<int32_T>(ic_rem - static_cast<int32_T>(1461 *
            div_s32(ic_rem, 1461)));
        ia_quot = static_cast<int32_T>(std::trunc(static_cast<real_T>(ib_rem) /
            365.0));
        ig_rem = static_cast<int32_T>(ib_rem - static_cast<int32_T>(365 *
            div_s32(ib_rem, 365)));
        if (ia_quot > 3) {
            ia_quot = 3;
            ig_rem = static_cast<int32_T>(ib_rem - 1095);
        }

        *y = ((std::trunc(static_cast<real_T>(idn) / 146097.0) * 400.0 +
               static_cast<real_T>(ic_quot) * 100.0) + std::trunc
              (static_cast<real_T>(ic_rem) / 1461.0) * 4.0) + static_cast<real_T>
            (ia_quot);
        idn = static_cast<int32_T>(static_cast<int32_T>(std::trunc((static_cast<
            real_T>(ig_rem) * 5.0 + 308.0) / 153.0)) - 2);
        g = static_cast<real_T>(idn);
        *d = ((static_cast<real_T>(ig_rem) - std::trunc((static_cast<real_T>(idn)
                 + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    } else {
        real_T a;
        real_T c;
        real_T dc;
        real_T dg;
        g = std::floor(((days + 719529.0) - 61.0) / 146097.0);
        dg = ((days + 719529.0) - 61.0) - g * 146097.0;
        c = std::floor(dg / 36524.0);
        if (c > 3.0) {
            c = 3.0;
        }

        dc = dg - c * 36524.0;
        dg = std::floor(dc / 1461.0);
        dc -= dg * 1461.0;
        a = std::floor(dc / 365.0);
        if (a > 3.0) {
            a = 3.0;
        }

        dc -= a * 365.0;
        *y = ((g * 400.0 + c * 100.0) + dg * 4.0) + a;
        g = std::floor((dc * 5.0 + 308.0) / 153.0) - 2.0;
        *d = ((dc - std::floor((g + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    }

    if (g > 9.0) {
        (*y)++;
        *m = (g + 2.0) - 11.0;
    } else {
        *m = (g + 2.0) + 1.0;
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
