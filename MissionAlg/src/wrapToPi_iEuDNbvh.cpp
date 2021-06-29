//
// File: wrapToPi_iEuDNbvh.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 2.687
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 28 22:52:13 2021
//
#include "rtwtypes.h"
#include <cmath>
#include "mod_dBqh4Vat.h"
#include "wrapToPi_iEuDNbvh.h"

// Function for MATLAB Function: '<S161>/WayPointGenerator'
void wrapToPi_iEuDNbvh(real_T *theta)
{
    real_T thetaWrap;
    if (std::abs(*theta) > 3.1415926535897931) {
        thetaWrap = mod_dBqh4Vat(*theta + 3.1415926535897931);
        if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
                (*theta + 3.1415926535897931 > 0.0)))) {
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
