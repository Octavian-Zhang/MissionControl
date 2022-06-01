//
// File: isPalindrome_KPAwztvD.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.216
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  1 23:14:28 2022
//
#include "rtwtypes.h"
#include "isPalindrome_KPAwztvD.h"
#include <cmath>

extern "C" {

#include "rt_nonfinite.h"

}
// Function for MATLAB Function: '<S100>/CommandCheck'
    boolean_T isPalindrome_KPAwztvD(real_T inputNum)
{
    real_T divisor;
    boolean_T result;
    for (divisor = 1.0; inputNum / divisor >= 10.0; divisor *= 10.0) {
    }

    int32_T exitg1;
    do {
        exitg1 = 0;
        if (inputNum != 0.0) {
            real_T trailing;
            if (std::isnan(inputNum)) {
                trailing = (rtNaN);
            } else if (std::isinf(inputNum)) {
                trailing = (rtNaN);
            } else {
                trailing = std::fmod(inputNum, 10.0);
                if (trailing == 0.0) {
                    trailing = 0.0;
                }
            }

            if (std::floor(inputNum / divisor) != trailing) {
                result = false;
                exitg1 = 1;
            } else {
                if (static_cast<boolean_T>(static_cast<int32_T>((divisor == 0.0)
                      ^ 1))) {
                    if (std::isnan(inputNum)) {
                        inputNum = (rtNaN);
                    } else if (std::isinf(inputNum)) {
                        inputNum = (rtNaN);
                    } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(std::isinf(divisor)) ^ 1)))
                    {
                        inputNum = std::fmod(inputNum, divisor);
                        if (inputNum == 0.0) {
                            inputNum = divisor * 0.0;
                        }
                    }
                }

                inputNum = std::floor(inputNum / 10.0);
                divisor = std::floor(divisor / 100.0);
            }
        } else {
            result = true;
            exitg1 = 1;
        }
    } while (exitg1 == 0);

    return result;
}

//
// File trailer for generated code.
//
// [EOF]
//
