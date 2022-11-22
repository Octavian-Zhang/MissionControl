//
// File: rt_mldivided3x3_snf.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 4.33
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:24:11 2022
//
#include "rtwtypes.h"
#include "rt_mldivided3x3_snf.h"
#include <cstring>
#include <cmath>

void rt_mldivided3x3_snf(const real_T u0[9], const real_T u1[9], real_T y[9])
{
    real_T A[9];
    real_T a21;
    real_T maxval;
    real_T y_tmp;
    real_T y_tmp_0;
    real_T y_tmp_1;
    real_T y_tmp_2;
    int32_T r1;
    int32_T r2;
    int32_T r3;
    std::memcpy(&A[0], &u0[0], static_cast<uint32_T>(9U * sizeof(real_T)));
    r1 = 0;
    r2 = 1;
    r3 = 2;
    maxval = std::abs(u0[0]);
    a21 = std::abs(u0[1]);
    if (a21 > maxval) {
        maxval = a21;
        r1 = 1;
        r2 = 0;
    }

    if (std::abs(u0[2]) > maxval) {
        r1 = 2;
        r2 = 1;
        r3 = 0;
    }

    A[r2] = u0[r2] / u0[r1];
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
    y[0] = u1[r1];
    y[1] = u1[r2] - y[0] * A[r2];
    maxval = A[static_cast<int32_T>(r3 + 3)];
    y[2] = (u1[r3] - y[0] * A[r3]) - maxval * y[1];
    a21 = A[static_cast<int32_T>(r3 + 6)];
    y[2] /= a21;
    y_tmp = A[static_cast<int32_T>(r1 + 6)];
    y[0] -= y_tmp * y[2];
    y_tmp_0 = A[static_cast<int32_T>(r2 + 6)];
    y[1] -= y_tmp_0 * y[2];
    y_tmp_1 = A[static_cast<int32_T>(r2 + 3)];
    y[1] /= y_tmp_1;
    y_tmp_2 = A[static_cast<int32_T>(r1 + 3)];
    y[0] -= y_tmp_2 * y[1];
    y[0] /= A[r1];
    y[3] = u1[static_cast<int32_T>(r1 + 3)];
    y[4] = u1[static_cast<int32_T>(r2 + 3)] - y[3] * A[r2];
    y[5] = (u1[static_cast<int32_T>(r3 + 3)] - y[3] * A[r3]) - maxval * y[4];
    y[5] /= a21;
    y[3] -= y_tmp * y[5];
    y[4] -= y_tmp_0 * y[5];
    y[4] /= y_tmp_1;
    y[3] -= y_tmp_2 * y[4];
    y[3] /= A[r1];
    y[6] = u1[static_cast<int32_T>(r1 + 6)];
    y[7] = u1[static_cast<int32_T>(r2 + 6)] - y[6] * A[r2];
    y[8] = (u1[static_cast<int32_T>(r3 + 6)] - y[6] * A[r3]) - maxval * y[7];
    y[8] /= a21;
    y[6] -= y_tmp * y[8];
    y[7] -= y_tmp_0 * y[8];
    y[7] /= y_tmp_1;
    y[6] -= y_tmp_2 * y[7];
    y[6] /= A[r1];
}

//
// File trailer for generated code.
//
// [EOF]
//
