//
// File: div_s32_sat.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 2.117
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed May 11 11:51:03 2022
//
#include "div_s32_sat.h"
#include "rtwtypes.h"

int32_T div_s32_sat(int32_T numerator, int32_T denominator)
{
    int32_T quotient;
    if (denominator == 0) {
        quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

        // Divide by zero handler
    } else {
        uint32_T tempAbsQuotient;
        boolean_T quotientNeedsNegation;
        quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
        tempAbsQuotient = static_cast<uint32_T>((numerator < 0 ? static_cast<
            uint32_T>(static_cast<uint32_T>(~static_cast<uint32_T>(numerator)) +
                      1U) : static_cast<uint32_T>(numerator)) / (denominator < 0
            ? static_cast<uint32_T>(static_cast<uint32_T>(~static_cast<uint32_T>
            (denominator)) + 1U) : static_cast<uint32_T>(denominator)));
        if ((!quotientNeedsNegation) && (tempAbsQuotient >= 2147483647U)) {
            quotient = MAX_int32_T;
        } else if (quotientNeedsNegation && (tempAbsQuotient > 2147483647U)) {
            quotient = MIN_int32_T;
        } else {
            quotient = quotientNeedsNegation ? static_cast<int32_T>(-
                static_cast<int32_T>(tempAbsQuotient)) : static_cast<int32_T>
                (tempAbsQuotient);
        }
    }

    return quotient;
}

//
// File trailer for generated code.
//
// [EOF]
//
