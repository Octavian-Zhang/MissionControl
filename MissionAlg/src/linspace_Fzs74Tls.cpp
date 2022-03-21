//
// File: linspace_Fzs74Tls.cpp
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 2.90
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Mar 21 00:56:32 2022
//
#include "rtwtypes.h"
#include <cmath>
#include "linspace_Fzs74Tls.h"

// Function for MATLAB Function: '<S132>/BaseWayPoint'
void linspace_Fzs74Tls(real_T d2, real_T y[91])
{
    y[90] = d2;
    y[0] = 0.0;
    if (0.0 == -d2) {
        real_T delta1;
        delta1 = d2 / 90.0;
        for (int32_T c_k{0}; c_k < 89; c_k++) {
            y[static_cast<int32_T>(c_k + 1)] = ((static_cast<real_T>(c_k) + 2.0)
                * 2.0 - 92.0) * delta1;
        }

        y[45] = 0.0;
    } else if ((d2 < 0.0) && (std::abs(d2) > 8.9884656743115785E+307)) {
        real_T delta1;
        delta1 = d2 / 90.0;
        for (int32_T c_k{0}; c_k < 89; c_k++) {
            y[static_cast<int32_T>(c_k + 1)] = (static_cast<real_T>(c_k) + 1.0) *
                delta1;
        }
    } else {
        real_T delta1;
        delta1 = d2 / 90.0;
        for (int32_T c_k{0}; c_k < 89; c_k++) {
            y[static_cast<int32_T>(c_k + 1)] = (static_cast<real_T>(c_k) + 1.0) *
                delta1;
        }
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
