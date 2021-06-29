//
// File: split_MzIWb6Db.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.654
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 28 22:54:24 2021
//
#include "rtwtypes.h"
#include <cmath>
#include "split_MzIWb6Db.h"

// Function for MATLAB Function: '<S9>/MATLAB Function'
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

//
// File trailer for generated code.
//
// [EOF]
//
