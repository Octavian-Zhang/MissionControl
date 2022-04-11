//
// File: floor_6aYiD2p8.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.119
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Apr 11 09:17:33 2022
//
#include "rtwtypes.h"
#include <cmath>
#include "floor_6aYiD2p8.h"

// Function for MATLAB Function: '<Root>/TimeNow'
creal_T floor_6aYiD2p8(const creal_T a)
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
