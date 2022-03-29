//
// File: LookUp_real_T_real_T.cpp
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 2.137
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Tue Mar 29 06:37:48 2022
//
#include "rtwtypes.h"
#include "BINARYSEARCH_real_T.h"
#include "LookUp_real_T_real_T.h"

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
