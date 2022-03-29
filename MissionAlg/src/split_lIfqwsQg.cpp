//
// File: split_lIfqwsQg.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.150
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Tue Mar 29 06:52:10 2022
//
#include "rtwtypes.h"
#include <cmath>
#include "split_lIfqwsQg.h"

// Function for MATLAB Function: '<S8>/PrintOnboardLog'
creal_T split_lIfqwsQg(real_T a)
{
    creal_T aout;
    if (std::abs(a) <= 6.69692879491417E+299) {
        real_T temp;
        temp = 1.34217729E+8 * a;
        temp -= temp - a;
        aout.re = temp;
        aout.im = a - temp;
    } else if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                  static_cast<boolean_T>(static_cast<int32_T>
                   (static_cast<int32_T>(std::isinf(a)) ^ 1))) &
                 static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                   (static_cast<int32_T>(std::isnan(a)) ^ 1)))))) {
        real_T temp;
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

//
// File trailer for generated code.
//
// [EOF]
//
