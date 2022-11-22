//
// File: floor_0EeG1Grp.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 5.10
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:19:22 2022
//
#include "rtwtypes.h"
#include "floor_0EeG1Grp.h"
#include <cmath>

// Function for MATLAB Function: '<Root>/TimeNow'
creal_T floor_0EeG1Grp(const creal_T a)
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
