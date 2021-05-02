//
// File: floor_jeUa7tf2.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.398
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  2 12:27:38 2021
//
#include "rtwtypes.h"
#include <cmath>
#include "floor_jeUa7tf2.h"

// Function for MATLAB Function: '<S1>/getCurrentTime'
creal_T floor_jeUa7tf2(const creal_T a)
{
  creal_T b;
  real_T alo;
  real_T b_ahi;
  real_T x;
  b.re = std::floor(a.re);
  b.im = 0.0;
  if (b.re == a.re) {
    x = std::floor(a.im);
    alo = 0.0;
    b_ahi = b.re;
    if (x != 0.0) {
      b_ahi = b.re + x;
      alo = x - (b_ahi - b.re);
    }

    if (std::isnan(alo)) {
      alo = 0.0;
    }

    b.re = b_ahi;
    b.im = alo;
  }

  return b;
}

//
// File trailer for generated code.
//
// [EOF]
//
