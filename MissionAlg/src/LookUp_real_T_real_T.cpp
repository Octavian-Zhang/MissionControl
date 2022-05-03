//
// File: LookUp_real_T_real_T.cpp
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 2.149
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon May  2 19:21:44 2022
//
#include "LookUp_real_T_real_T.h"
#include "BINARYSEARCH_real_T.h"
#include "rtwtypes.h"

// Lookup Utility LookUp_real_T_real_T
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
    real_T *pUData, uint32_T iHi)
{
    uint32_T iLeft;
    uint32_T iRght;
    BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

    {
        real_T lambda;
        if (pUData[iRght] > pUData[iLeft] ) {
            real_T num;
            real_T den;
            den = pUData[iRght];
            den -= pUData[iLeft];
            num = u;
            num -= pUData[iLeft];
            lambda = num / den;
        } else {
            lambda = 0.0;
        }

        {
            real_T yLeftCast;
            real_T yRghtCast;
            yLeftCast = pYData[iLeft];
            yRghtCast = pYData[iRght];
            yLeftCast += lambda * ( yRghtCast - yLeftCast );
            (*pY) = yLeftCast;
        }
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
