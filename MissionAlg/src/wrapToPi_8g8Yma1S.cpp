//
// File: wrapToPi_8g8Yma1S.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 4.42
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 16:52:33 2022
//
#include "rtwtypes.h"
#include "wrapToPi_8g8Yma1S.h"
#include <cmath>
#include "mod_Cteiw4Qy.h"

// Function for MATLAB Function: '<S77>/StartPointGenerator'
void wrapToPi_8g8Yma1S(real_T *theta)
{
    if (std::abs(*theta) > 3.1415926535897931) {
        real_T thetaWrap;
        thetaWrap = mod_Cteiw4Qy(*theta + 3.1415926535897931);
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
