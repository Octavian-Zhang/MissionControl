//
// File: div_nde_s32_floor.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun Apr 24 03:00:24 2022
//
#include "div_nde_s32_floor.h"
#include "rtwtypes.h"

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
