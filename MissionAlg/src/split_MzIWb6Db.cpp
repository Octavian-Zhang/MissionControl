//
// File: split_MzIWb6Db.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.398
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  2 12:27:38 2021
//
#include "rtwtypes.h"
#include <cmath>
#include "split_MzIWb6Db.h"

// Function for MATLAB Function: '<S1>/getCurrentTime'
creal_T split_MzIWb6Db(real_T a)
{
  creal_T aout;
  real_T temp;
  if (std::abs(a) <= 6.69692879491417E+299) {
    temp = 1.34217729E+8 * a;
    temp -= temp - a;
    aout.re = temp;
    aout.im = a - temp;
  } else if ((!std::isinf(a)) && (!std::isnan(a))) {
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
