//
// File: rt_mrdivide_U1d8192x3_U2d3x3_Yd8192x3_snf.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 4.42
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Nov 25 19:13:34 2022
//
#include "rtwtypes.h"
#include "rt_mrdivide_U1d8192x3_U2d3x3_Yd8192x3_snf.h"
#include <cstring>
#include <cmath>

void rt_mrdivide_U1d8192x3_U2d3x3_Yd8192x3_snf(const real_T u0[24576], const
    real_T u1[9], real_T y[24576])
{
    real_T A[9];
    real_T a21;
    real_T maxval;
    int32_T r1;
    int32_T r2;
    int32_T r3;
    int32_T rtemp;
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
        rtemp = static_cast<int32_T>(r2 + 1);
        r2 = r3;
        r3 = static_cast<int32_T>(rtemp - 1);
    }

    A[static_cast<int32_T>(r3 + 3)] /= A[static_cast<int32_T>(r2 + 3)];
    A[static_cast<int32_T>(r3 + 6)] -= A[static_cast<int32_T>(r3 + 3)] * A[
        static_cast<int32_T>(r2 + 6)];
    for (rtemp = 0; rtemp < 8192; rtemp++) {
        int32_T y_tmp;
        int32_T y_tmp_0;
        int32_T y_tmp_1;
        y_tmp = static_cast<int32_T>(static_cast<int32_T>(r1 << 13) + rtemp);
        y[y_tmp] = u0[rtemp] / A[r1];
        y_tmp_0 = static_cast<int32_T>(static_cast<int32_T>(r2 << 13) + rtemp);
        y[y_tmp_0] = u0[static_cast<int32_T>(rtemp + 8192)] - A
            [static_cast<int32_T>(r1 + 3)] * y[y_tmp];
        y_tmp_1 = static_cast<int32_T>(static_cast<int32_T>(r3 << 13) + rtemp);
        y[y_tmp_1] = u0[static_cast<int32_T>(rtemp + 16384)] - A
            [static_cast<int32_T>(r1 + 6)] * y[y_tmp];
        y[y_tmp_0] /= A[static_cast<int32_T>(r2 + 3)];
        y[y_tmp_1] -= A[static_cast<int32_T>(r2 + 6)] * y[y_tmp_0];
        y[y_tmp_1] /= A[static_cast<int32_T>(r3 + 6)];
        y[y_tmp_0] -= A[static_cast<int32_T>(r3 + 3)] * y[y_tmp_1];
        y[y_tmp] -= y[y_tmp_1] * A[r3];
        y[y_tmp] -= y[y_tmp_0] * A[r2];
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
