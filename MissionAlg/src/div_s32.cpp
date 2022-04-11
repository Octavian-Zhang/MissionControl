//
// File: div_s32.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.119
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Apr 11 09:17:33 2022
//
#include "rtwtypes.h"
#include "div_s32.h"

int32_T div_s32(int32_T numerator, int32_T denominator)
{
    int32_T quotient;
    if (denominator == 0) {
        quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

        // Divide by zero handler
    } else {
        uint32_T tempAbsQuotient;
        tempAbsQuotient = static_cast<uint32_T>((numerator < 0 ? static_cast<
            uint32_T>(static_cast<uint32_T>(~static_cast<uint32_T>(numerator)) +
                      1U) : static_cast<uint32_T>(numerator)) / (denominator < 0
            ? static_cast<uint32_T>(static_cast<uint32_T>(~static_cast<uint32_T>
            (denominator)) + 1U) : static_cast<uint32_T>(denominator)));
        quotient = (numerator < 0) != (denominator < 0) ? static_cast<int32_T>(-
            static_cast<int32_T>(tempAbsQuotient)) : static_cast<int32_T>
            (tempAbsQuotient);
    }

    return quotient;
}

//
// File trailer for generated code.
//
// [EOF]
//
