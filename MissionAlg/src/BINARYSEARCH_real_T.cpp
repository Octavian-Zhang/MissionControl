//
// File: BINARYSEARCH_real_T.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.654
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 28 22:54:24 2021
//
#include "rtwtypes.h"
#include "BINARYSEARCH_real_T.h"

// Lookup Binary Search Utility BINARYSEARCH_real_T
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
    real_T *pData, uint32_T iHi)
{
    // Find the location of current input value in the data table.
    *piLeft = 0U;
    *piRght = iHi;
    if (u <= pData[0] ) {
        // Less than or equal to the smallest point in the table.
        *piRght = 0U;
    } else if (u >= pData[iHi] ) {
        // Greater than or equal to the largest point in the table.
        *piLeft = iHi;
    } else {
        uint32_T i;

        // Do a binary search.
        while (( *piRght - *piLeft ) > 1U ) {
            // Get the average of the left and right indices using to Floor rounding. 
            i = (*piLeft + *piRght) >> 1;

            // Move either the right index or the left index so that
            //  LeftDataPoint <= CurrentValue < RightDataPoint
            if (u < pData[i] ) {
                *piRght = i;
            } else {
                *piLeft = i;
            }
        }
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
