//
// File: plus_bEdW4Zmk.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 5.25
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:28:33 2022
//
#include "rtwtypes.h"
#include "plus_bEdW4Zmk.h"

// Function for MATLAB Function: '<S84>/Struct2PosixCurr'
creal_T plus_bEdW4Zmk(const creal_T a, real_T b)
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
