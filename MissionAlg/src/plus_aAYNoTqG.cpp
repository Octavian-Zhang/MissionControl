//
// File: plus_aAYNoTqG.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 19 16:23:29 2021
//
#include "rtwtypes.h"
#include "plus_aAYNoTqG.h"

// Function for MATLAB Function: '<S2>/CommandCheck'
creal_T plus_aAYNoTqG(const creal_T a, real_T b)
{
  creal_T c;
  real_T b_alo;
  real_T b_bb;
  real_T bb;
  real_T shi;
  shi = a.re + b;
  bb = shi - a.re;
  b_bb = a.im - a.im;
  b_bb = (a.im - (a.im - b_bb)) + (0.0 - b_bb);
  b_alo = (a.re - (shi - bb)) + (b - bb);
  bb = shi;
  if (a.im != 0.0) {
    b_alo += a.im;
    bb = shi + b_alo;
    b_alo -= bb - shi;
  }

  c.im = b_alo;
  shi = bb;
  if (b_bb != 0.0) {
    b_bb += b_alo;
    shi = bb + b_bb;
    c.im = b_bb - (shi - bb);
  }

  c.re = shi;
  return c;
}

//
// File trailer for generated code.
//
// [EOF]
//
