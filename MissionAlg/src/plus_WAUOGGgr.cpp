//
// File: plus_WAUOGGgr.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.288
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri Jul  1 18:01:36 2022
//
#include "rtwtypes.h"
#include "plus_WAUOGGgr.h"

// Function for MATLAB Function: '<S103>/Struct2PosixCurr'
creal_T plus_WAUOGGgr(const creal_T a, real_T b)
{
    creal_T c;
    real_T alo;
    real_T bb;
    real_T shi;
    real_T t_im;
    shi = a.re + b;
    bb = shi - a.re;
    c.im = (a.re - (shi - bb)) + (b - bb);
    bb = a.im - a.im;
    t_im = (a.im - (a.im - bb)) + (0.0 - bb);
    alo = c.im;
    bb = shi;
    if (a.im != 0.0) {
        alo = c.im + a.im;
        bb = shi + alo;
        alo -= bb - shi;
    }

    c.re = bb;
    if (t_im != 0.0) {
        alo += t_im;
        bb += alo;
        alo -= bb - c.re;
    }

    c.re = bb;
    c.im = alo;
    return c;
}

//
// File trailer for generated code.
//
// [EOF]
//
