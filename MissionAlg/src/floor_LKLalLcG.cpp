//
// File: floor_LKLalLcG.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 4.188
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Aug 10 14:01:28 2022
//
#include "rtwtypes.h"
#include "floor_LKLalLcG.h"
#include <cmath>

// Function for MATLAB Function: '<Root>/TimeNow'
creal_T floor_LKLalLcG(const creal_T a)
{
    creal_T b;
    b.re = std::floor(a.re);
    b.im = 0.0;
    if (b.re == a.re) {
        real_T ahi;
        real_T b_ahi;
        real_T tmp;
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
