//
// File: rt_invd3x3_snf.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 4.42
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 16:52:33 2022
//
#include "rtwtypes.h"
#include "rt_invd3x3_snf.h"
#include <cstring>
#include <cmath>

void rt_invd3x3_snf(const real_T u[9], real_T y[9])
{
    real_T x[9];
    real_T absx11;
    real_T absx21;
    real_T absx31;
    int32_T p1;
    int32_T p2;
    int32_T p3;
    std::memcpy(&x[0], &u[0], static_cast<uint32_T>(9U * sizeof(real_T)));
    p1 = 1;
    p2 = 3;
    p3 = 6;
    absx11 = std::abs(u[0]);
    absx21 = std::abs(u[1]);
    absx31 = std::abs(u[2]);
    if ((absx21 > absx11) && (absx21 > absx31)) {
        p1 = 4;
        p2 = 0;
        x[0] = u[1];
        x[1] = u[0];
        x[3] = u[4];
        x[4] = u[3];
        x[6] = u[7];
        x[7] = u[6];
    } else if (absx31 > absx11) {
        p1 = 7;
        p3 = 0;
        x[2] = x[0];
        x[0] = u[2];
        x[5] = x[3];
        x[3] = u[5];
        x[8] = x[6];
        x[6] = u[8];
    }

    absx31 = x[1] / x[0];
    x[1] = absx31;
    absx11 = x[2] / x[0];
    x[2] = absx11;
    x[4] -= absx31 * x[3];
    x[5] -= absx11 * x[3];
    x[7] -= absx31 * x[6];
    x[8] -= absx11 * x[6];
    if (std::abs(x[5]) > std::abs(x[4])) {
        int32_T itmp;
        itmp = p2;
        p2 = p3;
        p3 = itmp;
        x[1] = absx11;
        x[2] = absx31;
        absx11 = x[4];
        x[4] = x[5];
        x[5] = absx11;
        absx11 = x[7];
        x[7] = x[8];
        x[8] = absx11;
    }

    absx31 = x[5] / x[4];
    x[8] -= absx31 * x[7];
    absx11 = (x[1] * absx31 - x[2]) / x[8];
    absx21 = -(x[7] * absx11 + x[1]) / x[4];
    y[static_cast<int32_T>(p1 - 1)] = ((1.0 - x[3] * absx21) - x[6] * absx11) /
        x[0];
    y[p1] = absx21;
    y[static_cast<int32_T>(p1 + 1)] = absx11;
    absx11 = -absx31 / x[8];
    absx21 = (1.0 - x[7] * absx11) / x[4];
    y[p2] = -(x[3] * absx21 + x[6] * absx11) / x[0];
    y[static_cast<int32_T>(p2 + 1)] = absx21;
    y[static_cast<int32_T>(p2 + 2)] = absx11;
    absx11 = 1.0 / x[8];
    absx21 = -x[7] * absx11 / x[4];
    y[p3] = -(x[3] * absx21 + x[6] * absx11) / x[0];
    y[static_cast<int32_T>(p3 + 1)] = absx21;
    y[static_cast<int32_T>(p3 + 2)] = absx11;
}

//
// File trailer for generated code.
//
// [EOF]
//
