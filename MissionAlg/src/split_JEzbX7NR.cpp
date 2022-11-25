//
// File: split_JEzbX7NR.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 5.10
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Nov 25 19:08:54 2022
//
#include "rtwtypes.h"
#include "split_JEzbX7NR.h"
#include <cmath>

// Function for MATLAB Function: '<Root>/TimeNow'
creal_T split_JEzbX7NR(real_T a)
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
