//
// File: div_nde_s32_floor.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.188
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Apr 11 09:35:15 2022
//
#include "rtwtypes.h"
#include "div_nde_s32_floor.h"

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
    return static_cast<int32_T>((((numerator < 0) != (denominator < 0)) &&
        (numerator % denominator != 0) ? -1 : 0) + static_cast<int32_T>
        (numerator / denominator));
}

//
// File trailer for generated code.
//
// [EOF]
//
