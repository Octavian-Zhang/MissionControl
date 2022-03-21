//
// File: wrapToPi_eKulZbfm.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 2.62
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Mar 21 01:08:16 2022
//
#include "rtwtypes.h"
#include <cmath>
#include "mod_ZflSpsmf.h"
#include "wrapToPi_eKulZbfm.h"

// Function for MATLAB Function: '<S179>/StartPointGenerator'
void wrapToPi_eKulZbfm(real_T *theta)
{
    if (std::abs(*theta) > 3.1415926535897931) {
        real_T thetaWrap;
        thetaWrap = mod_ZflSpsmf(*theta + 3.1415926535897931);
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
