//
// File: floor_jeUa7tf2.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.654
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 28 22:54:24 2021
//
#include "rtwtypes.h"
#include <cmath>
#include "floor_jeUa7tf2.h"

// Function for MATLAB Function: '<S9>/MATLAB Function'
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

//
// File trailer for generated code.
//
// [EOF]
//
