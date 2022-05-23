//
// File: isPalindrome_QBg8pX4c.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.142
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun May 22 08:47:08 2022
//
#include "rtwtypes.h"
#include "isPalindrome_QBg8pX4c.h"
#include <cmath>

extern "C" {

#include "rt_nonfinite.h"

}
// Function for MATLAB Function: '<S61>/CommandCheck'
    boolean_T isPalindrome_QBg8pX4c(real_T inputNum)
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
            } else if (inputNum == 0.0) {
                trailing = 0.0;
            } else {
                trailing = std::fmod(inputNum, 10.0);
                if (trailing == 0.0) {
                    trailing = 0.0;
                } else if (inputNum < 0.0) {
                    trailing += 10.0;
                }
            }

            if (std::floor(inputNum / divisor) != trailing) {
                result = false;
                exitg1 = 1;
            } else {
                trailing = inputNum;
                if (divisor == 0.0) {
                    if (inputNum == 0.0) {
                        trailing = 0.0;
                    }
                } else if (std::isnan(inputNum)) {
                    trailing = (rtNaN);
                } else if (std::isinf(inputNum)) {
                    trailing = (rtNaN);
                } else if (inputNum == 0.0) {
                    trailing = 0.0;
                } else if (std::isinf(divisor)) {
                    if (inputNum < 0.0) {
                        trailing = divisor;
                    }
                } else {
                    trailing = std::fmod(inputNum, divisor);
                    if (trailing == 0.0) {
                        trailing = divisor * 0.0;
                    } else if (inputNum < 0.0) {
                        trailing += divisor;
                    }
                }

                inputNum = std::floor(trailing / 10.0);
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
