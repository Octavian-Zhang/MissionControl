//
// File: div_s32.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 5.10
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:19:22 2022
//
#include "div_s32.h"
#include "rtwtypes.h"

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
