//
// File: div_s32_floor.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.188
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Apr 11 09:35:15 2022
//
#include "rtwtypes.h"
#include "div_s32_floor.h"

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
    int32_T quotient;
    if (denominator == 0) {
        quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

        // Divide by zero handler
    } else {
        uint32_T absDenominator;
        uint32_T absNumerator;
        uint32_T tempAbsQuotient;
        boolean_T quotientNeedsNegation;
        absNumerator = numerator < 0 ? static_cast<uint32_T>(static_cast<
            uint32_T>(~static_cast<uint32_T>(numerator)) + 1U) : static_cast<
            uint32_T>(numerator);
        absDenominator = denominator < 0 ? static_cast<uint32_T>(static_cast<
            uint32_T>(~static_cast<uint32_T>(denominator)) + 1U) : static_cast<
            uint32_T>(denominator);
        quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
        tempAbsQuotient = static_cast<uint32_T>(absNumerator / absDenominator);
        if (quotientNeedsNegation) {
            absNumerator %= absDenominator;
            if (absNumerator > 0U) {
                tempAbsQuotient = static_cast<uint32_T>(tempAbsQuotient + 1U);
            }
        }

        quotient = quotientNeedsNegation ? static_cast<int32_T>
            (-static_cast<int32_T>(tempAbsQuotient)) : static_cast<int32_T>
            (tempAbsQuotient);
    }

    return quotient;
}

//
// File trailer for generated code.
//
// [EOF]
//
