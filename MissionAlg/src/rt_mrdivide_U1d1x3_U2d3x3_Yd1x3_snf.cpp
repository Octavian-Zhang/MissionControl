//
// File: rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 3.24
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  1 23:11:04 2022
//
#include "rtwtypes.h"
#include "rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf.h"
#include <cstring>
#include <cmath>

void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(const real_T u0[3], const real_T u1[9],
    real_T y[3])
{
    real_T A[9];
    real_T a21;
    real_T maxval;
    int32_T r1;
    int32_T r2;
    int32_T r3;
    std::memcpy(&A[0], &u1[0], static_cast<uint32_T>(9U * sizeof(real_T)));
    r1 = 0;
    r2 = 1;
    r3 = 2;
    maxval = std::abs(u1[0]);
    a21 = std::abs(u1[1]);
    if (a21 > maxval) {
        maxval = a21;
        r1 = 1;
        r2 = 0;
    }

    if (std::abs(u1[2]) > maxval) {
        r1 = 2;
        r2 = 1;
        r3 = 0;
    }

    A[r2] = u1[r2] / u1[r1];
    A[r3] /= A[r1];
    A[static_cast<int32_T>(r2 + 3)] -= A[static_cast<int32_T>(r1 + 3)] * A[r2];
    A[static_cast<int32_T>(r3 + 3)] -= A[static_cast<int32_T>(r1 + 3)] * A[r3];
    A[static_cast<int32_T>(r2 + 6)] -= A[static_cast<int32_T>(r1 + 6)] * A[r2];
    A[static_cast<int32_T>(r3 + 6)] -= A[static_cast<int32_T>(r1 + 6)] * A[r3];
    if (std::abs(A[static_cast<int32_T>(r3 + 3)]) > std::abs(A
            [static_cast<int32_T>(r2 + 3)])) {
        int32_T rtemp;
        rtemp = static_cast<int32_T>(r2 + 1);
        r2 = r3;
        r3 = static_cast<int32_T>(rtemp - 1);
    }

    A[static_cast<int32_T>(r3 + 3)] /= A[static_cast<int32_T>(r2 + 3)];
    A[static_cast<int32_T>(r3 + 6)] -= A[static_cast<int32_T>(r3 + 3)] * A[
        static_cast<int32_T>(r2 + 6)];
    y[r1] = u0[0] / A[r1];
    y[r2] = u0[1] - A[static_cast<int32_T>(r1 + 3)] * y[r1];
    y[r3] = u0[2] - A[static_cast<int32_T>(r1 + 6)] * y[r1];
    y[r2] /= A[static_cast<int32_T>(r2 + 3)];
    y[r3] -= A[static_cast<int32_T>(r2 + 6)] * y[r2];
    y[r3] /= A[static_cast<int32_T>(r3 + 6)];
    y[r2] -= A[static_cast<int32_T>(r3 + 3)] * y[r3];
    y[r1] -= y[r3] * A[r3];
    y[r1] -= y[r2] * A[r2];
}

//
// File trailer for generated code.
//
// [EOF]
//
