//
// File: wrapToPi_kQV0kjUY.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 3.25
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jul 14 15:03:49 2022
//
#include "rtwtypes.h"
#include "wrapToPi_kQV0kjUY.h"
#include <cmath>
#include "mod_d42kHWKw.h"

// Function for MATLAB Function: '<S95>/StartPointGenerator'
void wrapToPi_kQV0kjUY(real_T *theta)
{
    if (std::abs(*theta) > 3.1415926535897931) {
        real_T thetaWrap;
        thetaWrap = mod_d42kHWKw(*theta + 3.1415926535897931);
        if (static_cast<boolean_T>(static_cast<int32_T>((*theta +
                3.1415926535897931 > 0.0) & (thetaWrap == 0.0)))) {
            thetaWrap = 6.2831853071795862;
        }

        *theta = thetaWrap - 3.1415926535897931;
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
