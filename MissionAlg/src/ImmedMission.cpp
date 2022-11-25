//
// File: ImmedMission.cpp
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 4.1
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Nov 25 19:06:19 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LLP64)
// Code generation objectives:
//    1. Safety precaution
//    2. Execution efficiency
//    3. RAM efficiency
//    4. ROM efficiency
// Validation result: Not run
//
#include "ImmedMission.h"
#include "rtwtypes.h"
#include "ImmedMission_types.h"
#include "MissionModes.h"
#include <cmath>
#include "rt_atan2d_snf.h"
#include <cstring>
#include <stdio.h>
#include "rt_modd_snf.h"
#include <stddef.h>
#include <cstdlib>
#include "zero_crossing_types.h"
#include "ImmedMission_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<S1>/PreemptableMissionModeSelector'
const uint8_T ImmedMission_IN_ImmedMission{ 1U };

const uint8_T ImmedMission_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T ImmedMission_IN_WaitToStart{ 2U };

// Named constants for Chart: '<S20>/HdgHoldLogic'
const uint8_T ImmedMission_IN_OutOfRange{ 1U };

const uint8_T ImmedMission_IN_Turning{ 2U };

const uint8_T ImmedMission_IN_WithInRange{ 3U };

// Forward declaration for local functions
static real_T ImmedMission_norm(const real_T x[3]);

// Forward declaration for local functions
static void ImmedMission_emxInit_char_T(emxArray_char_T_ImmedMission_T
    **pEmxArray, int32_T numDimensions);
static int8_T ImmedMission_filedata_p(DW_ImmedMission_f_T *localDW);
static int8_T ImmedMission_cfopen_j(const char_T *cfilename, const char_T
    *cpermission, DW_ImmedMission_f_T *localDW);
static void ImmedMission_emxEnsureCapacity_char_T(emxArray_char_T_ImmedMission_T
    *emxArray, int32_T oldNumel);
static void ImmedMission_fread_o(real_T fileID, emxArray_char_T_ImmedMission_T
    *A, DW_ImmedMission_f_T *localDW);
static int8_T ImmedMission_filedata(DW_ImmedMission_f_T *localDW);
static int8_T ImmedMission_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_ImmedMission_f_T *localDW);
static void ImmedMission_fread(real_T fileID, emxArray_char_T_ImmedMission_T *A,
    DW_ImmedMission_f_T *localDW);
static void ImmedMission_copysign(emxArray_char_T_ImmedMission_T *s1, int32_T
    *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T *foundsign, boolean_T *success);
static boolean_T ImmedMission_isUnitImag(const emxArray_char_T_ImmedMission_T *s,
    int32_T k, int32_T n);
static void ImmedMission_readNonFinite(const emxArray_char_T_ImmedMission_T *s,
    int32_T *k, int32_T n, boolean_T *b_finite, real_T *fv);
static boolean_T ImmedMission_copydigits(emxArray_char_T_ImmedMission_T *s1,
    int32_T *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T allowpoint);
static boolean_T ImmedMission_copyexponent(emxArray_char_T_ImmedMission_T *s1,
    int32_T *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n);
static void ImmedMission_readfloat(emxArray_char_T_ImmedMission_T *s1, int32_T
    *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign,
    boolean_T *success);
static void ImmedMission_emxFree_char_T(emxArray_char_T_ImmedMission_T
    **pEmxArray);
static creal_T ImmedMission_str2double(const emxArray_char_T_ImmedMission_T *s);
static int32_T ImmedMission_cfclose_g(real_T fid, DW_ImmedMission_f_T *localDW);
static int32_T ImmedMission_cfclose(real_T fid, DW_ImmedMission_f_T *localDW);
static void ImmedMission_strtok(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
    *remain);
static void ImmedMission_strtok_i(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token);
static void ImmedMission_strtrim(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *y);
static boolean_T ImmedMission_strcmp(const emxArray_char_T_ImmedMission_T *a);
static boolean_T ImmedMission_strcmp_m(const emxArray_char_T_ImmedMission_T *a);
static boolean_T ImmedMission_contains(const emxArray_char_T_ImmedMission_T *str);
static void ImmedMission_find_token(const emxArray_char_T_ImmedMission_T *x,
    int32_T *itoken, int32_T *iremain);
static void ImmedMission_strtok_iu(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
    *remain);
static boolean_T ImmedMission_strcmp_m2(const emxArray_char_T_ImmedMission_T *a);
static real_T ImmedMission_norm_p(const real_T x[2]);
static boolean_T ImmedMission_strcmp_m2h(const emxArray_char_T_ImmedMission_T *a);
static real_T ImmedMission_norm_pv(const real_T x[3]);
static real_T ImmedMission_angdiff(real_T x, real_T y);
static real_T ImmedMission_norm(const real_T x[3])
{
    real_T absxk;
    real_T scale;
    real_T t;
    real_T y;
    scale = 3.3121686421112381E-170;
    absxk = std::abs(x[0]);
    if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
    } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
    }

    absxk = std::abs(x[1]);
    if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
    } else {
        t = absxk / scale;
        y += t * t;
    }

    absxk = std::abs(x[2]);
    if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
    } else {
        t = absxk / scale;
        y += t * t;
    }

    return scale * std::sqrt(y);
}

// System initialize for atomic system:
void ImmedMission_Altitude_Init(DW_Altitude_ImmedMission_T *localDW)
{
    // Start for MATLABSystem: '<S55>/Altitude'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    localDW->obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S55>/Altitude'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 6; i++) {
        // Start for MATLABSystem: '<S55>/Altitude'
        localDW->obj.WaypointsInternal[i] = 0.0;

        // InitializeConditions for MATLABSystem: '<S55>/Altitude'
        localDW->obj.WaypointsInternal[i] *= 0.0;
    }
}

// System reset for atomic system:
void ImmedMission_Altitude_Reset(DW_Altitude_ImmedMission_T *localDW)
{
    // InitializeConditions for MATLABSystem: '<S55>/Altitude'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 6; i++) {
        localDW->obj.WaypointsInternal[i] *= 0.0;
    }

    // End of InitializeConditions for MATLABSystem: '<S55>/Altitude'
}

// Output and update for atomic system:
void ImmedMission_Altitude(const real_T rtu_0[4], const real_T rtu_1[6], real_T
    rtu_2, DW_Altitude_ImmedMission_T *localDW)
{
    real_T b_waypointsIn_data[6];
    real_T waypoints_data[6];
    real_T b_waypointsIn[3];
    real_T rtu_0_0[3];
    real_T lambda;
    real_T r_idx_0;
    real_T r_idx_1;
    real_T r_idx_2;
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T b_k;
    int32_T b_size_idx_1;
    int32_T c;
    int32_T e;
    int32_T waypoints_size_idx_0;
    int8_T b_data[2];
    boolean_T x[3];
    boolean_T distinctWptsIdx[2];
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T p;

    // MATLABSystem: '<S55>/Altitude'
    lambda = rtu_2;
    localDW->obj.LookaheadDistFlag = 0U;
    if (rtu_2 < 0.1) {
        lambda = 0.1;
        localDW->obj.LookaheadDistFlag = 1U;
    }

    localDW->obj.InitialPose[0] = 0.0;
    localDW->obj.InitialPose[1] = 0.0;
    localDW->obj.InitialPose[2] = 0.0;
    localDW->obj.InitialPose[3] = 0.0;
    localDW->obj.NumWaypoints = 2.0;
    guard1 = false;
    if (localDW->obj.NumWaypoints != 2.0) {
        guard1 = true;
    } else {
        boolean_T p_0;
        if (localDW->obj.NumWaypoints < 1.0) {
            c = 0;
        } else {
            c = static_cast<int32_T>(localDW->obj.NumWaypoints);
        }

        if (localDW->obj.NumWaypoints < 1.0) {
            e = 0;
        } else {
            e = static_cast<int32_T>(localDW->obj.NumWaypoints);
        }

        p = false;
        p_0 = false;
        if (c == e) {
            p_0 = true;
        }

        if (p_0 && (c != 0) && (e != 0)) {
            b_k = 0;
            exitg1 = false;
            while ((!exitg1) && (b_k <= static_cast<int32_T>(static_cast<int32_T>
                     (e * 3) - 1))) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((localDW->obj.WaypointsInternal[
                        static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(b_k / c) << 1) + b_k % c)] ==
                        rtu_1[static_cast<int32_T>(static_cast<int32_T>(
                         static_cast<int32_T>(b_k / e) << 1) + b_k % e)]) ^ 1)))
                {
                    p_0 = false;
                    exitg1 = true;
                } else {
                    b_k = static_cast<int32_T>(b_k + 1);
                }
            }
        }

        if (p_0) {
            p = true;
        }

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(p) ^
              1))) {
            guard1 = true;
        }
    }

    if (guard1) {
        for (b_k = 0; b_k < 6; b_k++) {
            localDW->obj.WaypointsInternal[b_k] = rtu_1[b_k];
        }

        localDW->obj.WaypointIndex = 1.0;
    }

    distinctWptsIdx[1] = true;
    x[0] = (rtu_1[0] != rtu_1[1]);
    x[1] = (rtu_1[2] != rtu_1[3]);
    x[2] = (rtu_1[4] != rtu_1[5]);
    distinctWptsIdx[0] = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 3)) {
        if (x[b_k]) {
            distinctWptsIdx[0] = true;
            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 1);
        }
    }

    e = 0;
    for (b_k = 0; b_k < 2; b_k++) {
        if (distinctWptsIdx[b_k]) {
            e = static_cast<int32_T>(e + 1);
        }
    }

    b_size_idx_1 = e;
    e = 0;
    for (b_k = 0; b_k < 2; b_k++) {
        if (distinctWptsIdx[b_k]) {
            b_data[e] = static_cast<int8_T>(static_cast<int32_T>(b_k + 1));
            e = static_cast<int32_T>(e + 1);
        }
    }

    for (b_k = 0; b_k < 3; b_k++) {
        for (c = 0; c <= static_cast<int32_T>(b_size_idx_1 - 1); c++) {
            b_waypointsIn_data[static_cast<int32_T>(c + static_cast<int32_T>
                (b_size_idx_1 * b_k))] = rtu_1[static_cast<int32_T>(static_cast<
                int32_T>(static_cast<int32_T>(b_k << 1) + static_cast<int32_T>
                         (b_data[c])) - 1)];
        }
    }

    localDW->obj.LookaheadDistance = lambda;
    if (b_size_idx_1 == 0) {
        // MATLABSystem: '<S55>/Altitude'
        localDW->Altitude_o1[0] = lambda * std::cos(rtu_0[3]) + rtu_0[0];
        localDW->Altitude_o1[1] = lambda * std::sin(rtu_0[3]) + rtu_0[1];
        localDW->Altitude_o1[2] = lambda * 0.0 + rtu_0[2];

        // MATLABSystem: '<S55>/Altitude'
        localDW->HeadingAngle = rtu_0[3];

        // MATLABSystem: '<S55>/Altitude'
        localDW->Altitude_o5 = 1U;
    } else {
        guard1 = false;
        if (b_size_idx_1 == 1) {
            if (localDW->obj.StartFlag) {
                localDW->obj.InitialPose[0] = rtu_0[0];
                localDW->obj.InitialPose[1] = rtu_0[1];
                localDW->obj.InitialPose[2] = rtu_0[2];
                localDW->obj.InitialPose[3] = rtu_0[3];
            }

            b_waypointsIn[0] = b_waypointsIn_data[0] - rtu_0[0];
            b_waypointsIn[1] = b_waypointsIn_data[1] - rtu_0[1];
            b_waypointsIn[2] = b_waypointsIn_data[2] - rtu_0[2];
            if (ImmedMission_norm(b_waypointsIn) < 1.4901161193847656E-8) {
                // MATLABSystem: '<S55>/Altitude'
                localDW->Altitude_o1[0] = lambda * std::cos(rtu_0[3]) + rtu_0[0];
                localDW->Altitude_o1[1] = lambda * std::sin(rtu_0[3]) + rtu_0[1];
                localDW->Altitude_o1[2] = lambda * 0.0 + rtu_0[2];

                // MATLABSystem: '<S55>/Altitude'
                localDW->HeadingAngle = rtu_0[3];

                // MATLABSystem: '<S55>/Altitude'
                localDW->Altitude_o5 = 1U;
                localDW->obj.StartFlag = false;
            } else {
                localDW->obj.StartFlag = false;
                localDW->obj.NumWaypoints = 2.0;
                waypoints_size_idx_0 = static_cast<int32_T>(b_size_idx_1 + 1);
                for (b_k = 0; b_k < 3; b_k++) {
                    e = static_cast<int32_T>(static_cast<int32_T>(b_size_idx_1 +
                        1) * b_k);
                    waypoints_data[e] = localDW->obj.InitialPose[b_k];
                    for (c = 0; c <= static_cast<int32_T>(b_size_idx_1 - 1); c++)
                    {
                        waypoints_data[static_cast<int32_T>(static_cast<int32_T>
                            (c + e) + 1)] = b_waypointsIn_data
                            [static_cast<int32_T>(static_cast<int32_T>
                            (b_size_idx_1 * b_k) + c)];
                    }
                }

                guard1 = true;
            }
        } else {
            waypoints_size_idx_0 = b_size_idx_1;
            e = static_cast<int32_T>(b_size_idx_1 * 3);
            for (b_k = 0; b_k <= static_cast<int32_T>(e - 1); b_k++) {
                waypoints_data[b_k] = b_waypointsIn_data[b_k];
            }

            guard1 = true;
        }

        if (guard1) {
            real_T b;
            real_T b_tmp_idx_2_tmp;
            real_T lambda_tmp;
            real_T rtu_0_tmp;
            real_T waypoints_tmp;
            real_T waypoints_tmp_0;
            real_T waypoints_tmp_1;
            boolean_T guard2{ false };

            p = false;
            if (localDW->obj.WaypointIndex == localDW->obj.NumWaypoints) {
                p = true;
            }

            if (p) {
                localDW->obj.LastWaypointFlag = true;
                localDW->obj.WaypointIndex--;
            }

            rtu_0_0[0] = rtu_0[0] - waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0) - 1)];
            rtu_0_0[1] = rtu_0[1] - waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>
                (localDW->obj.WaypointIndex + 1.0) + waypoints_size_idx_0) - 1)];
            rtu_0_0[2] = rtu_0[2] - waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>
                (localDW->obj.WaypointIndex + 1.0) + static_cast<int32_T>
                (waypoints_size_idx_0 << 1)) - 1)];
            guard2 = false;
            if (ImmedMission_norm(rtu_0_0) <= 30.0) {
                guard2 = true;
            } else {
                r_idx_0 = waypoints_data[static_cast<int32_T>(static_cast<
                    int32_T>(localDW->obj.WaypointIndex + 1.0) - 1)];
                b_waypointsIn[0] = rtu_0[0] - r_idx_0;
                rtu_0_0[0] = r_idx_0 - waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(localDW->obj.WaypointIndex) - 1)];
                r_idx_0 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (localDW->obj.WaypointIndex + 1.0) + waypoints_size_idx_0)
                     - 1)];
                b_waypointsIn[1] = rtu_0[1] - r_idx_0;
                rtu_0_0[1] = r_idx_0 - waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex) + waypoints_size_idx_0) - 1)];
                r_idx_2 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (localDW->obj.WaypointIndex + 1.0) + static_cast<int32_T>
                      (waypoints_size_idx_0 << 1)) - 1)];
                b_waypointsIn[2] = rtu_0[2] - r_idx_2;
                rtu_0_tmp = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (waypoints_size_idx_0 << 1) + static_cast<int32_T>
                      (localDW->obj.WaypointIndex)) - 1)];
                rtu_0_0[2] = r_idx_2 - rtu_0_tmp;
                lambda = ImmedMission_norm(rtu_0_0);
                b = ImmedMission_norm(b_waypointsIn);
                waypoints_tmp = waypoints_data[static_cast<int32_T>(static_cast<
                    int32_T>(localDW->obj.WaypointIndex) - 1)];
                r_idx_0 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0) - 1)];
                waypoints_tmp_0 = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex) + waypoints_size_idx_0) - 1)];
                r_idx_1 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (localDW->obj.WaypointIndex + 1.0) + waypoints_size_idx_0)
                     - 1)];
                lambda = ((r_idx_0 - waypoints_tmp) / lambda * (b_waypointsIn[0]
                           / b) + (r_idx_1 - waypoints_tmp_0) / lambda *
                          (b_waypointsIn[1] / b)) + (r_idx_2 - rtu_0_tmp) /
                    lambda * (b_waypointsIn[2] / b);
                if (std::isnan(lambda)) {
                    lambda = (rtNaN);
                } else if (lambda < 0.0) {
                    lambda = -1.0;
                } else {
                    lambda = static_cast<real_T>(lambda > 0.0);
                }

                if (lambda >= 0.0) {
                    guard2 = true;
                } else {
                    b_waypointsIn[0] = waypoints_tmp;
                    b_waypointsIn[1] = waypoints_tmp_0;
                    b_waypointsIn[2] = rtu_0_tmp;
                }
            }

            if (guard2) {
                localDW->obj.WaypointIndex++;
                p = false;
                if (localDW->obj.WaypointIndex == localDW->obj.NumWaypoints) {
                    p = true;
                }

                if (p) {
                    localDW->obj.LastWaypointFlag = true;
                    localDW->obj.WaypointIndex--;
                }

                b_waypointsIn[0] = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(localDW->obj.WaypointIndex) - 1)];
                r_idx_0 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0) - 1)];
                b_waypointsIn[1] = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex) + waypoints_size_idx_0) - 1)];
                r_idx_1 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (localDW->obj.WaypointIndex + 1.0) + waypoints_size_idx_0)
                     - 1)];
                b_waypointsIn[2] = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (waypoints_size_idx_0 << 1) + static_cast<int32_T>
                    (localDW->obj.WaypointIndex)) - 1)];
                r_idx_2 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (localDW->obj.WaypointIndex + 1.0) + static_cast<int32_T>
                      (waypoints_size_idx_0 << 1)) - 1)];
            }

            waypoints_tmp = r_idx_0 - b_waypointsIn[0];
            b = rtu_0[0] - b_waypointsIn[0];
            waypoints_tmp_0 = r_idx_1 - b_waypointsIn[1];
            rtu_0_tmp = rtu_0[1] - b_waypointsIn[1];
            waypoints_tmp_1 = r_idx_2 - b_waypointsIn[2];
            lambda_tmp = rtu_0[2] - b_waypointsIn[2];
            lambda = ((rtu_0_tmp * waypoints_tmp_0 + b * waypoints_tmp) +
                      lambda_tmp * waypoints_tmp_1) / ((waypoints_tmp_0 *
                waypoints_tmp_0 + waypoints_tmp * waypoints_tmp) +
                waypoints_tmp_1 * waypoints_tmp_1);
            if (lambda < 0.0) {
                rtu_0_0[0] = b;
                rtu_0_0[1] = rtu_0_tmp;
                rtu_0_0[2] = lambda_tmp;
                lambda = ImmedMission_norm(rtu_0_0);
            } else if (lambda > 1.0) {
                rtu_0_0[0] = rtu_0[0] - r_idx_0;
                rtu_0_0[1] = rtu_0[1] - r_idx_1;
                rtu_0_0[2] = rtu_0[2] - r_idx_2;
                lambda = ImmedMission_norm(rtu_0_0);
            } else {
                rtu_0_0[0] = rtu_0[0] - (lambda * waypoints_tmp + b_waypointsIn
                    [0]);
                rtu_0_0[1] = rtu_0[1] - (lambda * waypoints_tmp_0 +
                    b_waypointsIn[1]);
                rtu_0_0[2] = rtu_0[2] - (lambda * waypoints_tmp_1 +
                    b_waypointsIn[2]);
                lambda = ImmedMission_norm(rtu_0_0);
            }

            if (localDW->obj.LastWaypointFlag) {
                lambda = (((rtu_0[0] - b_waypointsIn[0]) * (r_idx_0 -
                            b_waypointsIn[0]) + (rtu_0[1] - b_waypointsIn[1]) *
                           (r_idx_1 - b_waypointsIn[1])) + (rtu_0[2] -
                           b_waypointsIn[2]) * (r_idx_2 - b_waypointsIn[2])) /
                    (((r_idx_0 - b_waypointsIn[0]) * (r_idx_0 - b_waypointsIn[0])
                      + (r_idx_1 - b_waypointsIn[1]) * (r_idx_1 - b_waypointsIn
                       [1])) + (r_idx_2 - b_waypointsIn[2]) * (r_idx_2 -
                      b_waypointsIn[2]));
                rtu_0_0[0] = rtu_0[0] - (lambda * waypoints_tmp + b_waypointsIn
                    [0]);
                rtu_0_0[1] = rtu_0[1] - (lambda * waypoints_tmp_0 +
                    b_waypointsIn[1]);
                rtu_0_0[2] = rtu_0[2] - (lambda * waypoints_tmp_1 +
                    b_waypointsIn[2]);
                lambda = ImmedMission_norm(rtu_0_0);
            }

            lambda_tmp = std::abs(lambda);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isinf(lambda_tmp)) | static_cast<int32_T>(std::isnan
                    (lambda_tmp))))) {
                b = (rtNaN);
                lambda_tmp = (rtNaN);
            } else if (lambda_tmp < 4.4501477170144028E-308) {
                b = 4.94065645841247E-324;
                lambda_tmp = 4.94065645841247E-324;
            } else {
                std::frexp(lambda_tmp, &b_exponent);
                b = std::ldexp(1.0, static_cast<int32_T>(b_exponent - 53));
                std::frexp(lambda_tmp, &b_exponent_0);
                lambda_tmp = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0 -
                    53));
            }

            if (localDW->obj.LookaheadDistance <= std::fmax(std::sqrt(b), 5.0 *
                    lambda_tmp) + lambda) {
                localDW->obj.LookaheadDistance = localDW->obj.LookaheadFactor *
                    lambda;
            }

            lambda = b_waypointsIn[0] - rtu_0[0];
            lambda_tmp = b_waypointsIn[1] - rtu_0[1];
            rtu_0_tmp = ((r_idx_0 - b_waypointsIn[0]) * (r_idx_0 -
                          b_waypointsIn[0]) + (r_idx_1 - b_waypointsIn[1]) *
                         (r_idx_1 - b_waypointsIn[1])) + (r_idx_2 -
                b_waypointsIn[2]) * (r_idx_2 - b_waypointsIn[2]);
            b_tmp_idx_2_tmp = b_waypointsIn[2] - rtu_0[2];
            b = ((waypoints_tmp * lambda + waypoints_tmp_0 * lambda_tmp) +
                 waypoints_tmp_1 * b_tmp_idx_2_tmp) * 2.0;
            lambda_tmp = std::sqrt(b * b - (((lambda * lambda + lambda_tmp *
                lambda_tmp) + b_tmp_idx_2_tmp * b_tmp_idx_2_tmp) -
                                    localDW->obj.LookaheadDistance *
                                    localDW->obj.LookaheadDistance) * (4.0 *
                                    rtu_0_tmp));
            lambda = std::fmax((-b + lambda_tmp) / 2.0 / rtu_0_tmp, (-b -
                                lambda_tmp) / 2.0 / rtu_0_tmp);
            rtu_0_tmp = (1.0 - lambda) * b_waypointsIn[0] + lambda * r_idx_0;

            // MATLABSystem: '<S55>/Altitude'
            localDW->Altitude_o1[0] = rtu_0_tmp;
            r_idx_0 = rtu_0_tmp;
            rtu_0_tmp = (1.0 - lambda) * b_waypointsIn[1] + lambda * r_idx_1;

            // MATLABSystem: '<S55>/Altitude'
            localDW->Altitude_o1[1] = rtu_0_tmp;
            localDW->Altitude_o1[2] = (1.0 - lambda) * b_waypointsIn[2] + lambda
                * r_idx_2;

            // MATLABSystem: '<S55>/Altitude'
            localDW->HeadingAngle = rt_atan2d_snf(rtu_0_tmp - rtu_0[1], r_idx_0
                - rtu_0[0]);

            // MATLABSystem: '<S55>/Altitude'
            localDW->Altitude_o5 = 0U;
            p = false;
            if (localDW->obj.LastWaypointFlag) {
                p = true;
            }

            if (p) {
                // MATLABSystem: '<S55>/Altitude'
                localDW->Altitude_o5 = 1U;
            }

            localDW->obj.LastWaypointFlag = false;
        }
    }

    // End of MATLABSystem: '<S55>/Altitude'
}

static void ImmedMission_emxInit_char_T(emxArray_char_T_ImmedMission_T
    **pEmxArray, int32_T numDimensions)
{
    emxArray_char_T_ImmedMission_T *emxArray;
    *pEmxArray = static_cast<emxArray_char_T_ImmedMission_T *>(std::malloc
        (sizeof(emxArray_char_T_ImmedMission_T)));
    emxArray = *pEmxArray;
    emxArray->data = static_cast<char_T *>(nullptr);
    emxArray->numDimensions = numDimensions;
    emxArray->size = static_cast<int32_T *>(std::malloc(static_cast<uint32_T>
        (sizeof(int32_T) * static_cast<uint32_T>(numDimensions))));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (int32_T i{0}; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
static int8_T ImmedMission_filedata_p(DW_ImmedMission_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles_o[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
static int8_T ImmedMission_cfopen_j(const char_T *cfilename, const char_T
    *cpermission, DW_ImmedMission_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = ImmedMission_filedata_p(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles_o[static_cast<int32_T>(static_cast<int32_T>(j)
                - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

static void ImmedMission_emxEnsureCapacity_char_T(emxArray_char_T_ImmedMission_T
    *emxArray, int32_T oldNumel)
{
    int32_T i;
    int32_T newNumel;
    void *newData;
    if (oldNumel < 0) {
        oldNumel = 0;
    }

    newNumel = 1;
    for (i = 0; i <= static_cast<int32_T>(emxArray->numDimensions - 1); i++) {
        newNumel = static_cast<int32_T>(newNumel * emxArray->size[i]);
    }

    if (newNumel > emxArray->allocatedSize) {
        i = emxArray->allocatedSize;
        if (i < 16) {
            i = 16;
        }

        while (i < newNumel) {
            if (i > 1073741823) {
                i = MAX_int32_T;
            } else {
                i = static_cast<int32_T>(i << 1);
            }
        }

        newData = std::calloc(static_cast<uint32_T>(i), sizeof(char_T));
        if (emxArray->data != nullptr) {
            std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
                         (char_T) * static_cast<uint32_T>(oldNumel)));
            if (emxArray->canFreeData) {
                std::free(emxArray->data);
            }
        }

        emxArray->data = static_cast<char_T *>(newData);
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
static void ImmedMission_fread_o(real_T fileID, emxArray_char_T_ImmedMission_T
    *A, DW_ImmedMission_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(fileID);
    if (fileID != static_cast<real_T>(static_cast<int8_T>(fileID))) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        filestar = localDW->eml_openfiles_o[static_cast<int32_T>
            (static_cast<int32_T>(fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
              static_cast<boolean_T>(static_cast<int32_T>((fileID != 0.0) ^ 1)))
             | static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
               ((fileID != 1.0) ^ 1)))))) | static_cast<int32_T>
            (static_cast<boolean_T>(static_cast<int32_T>((fileID != 2.0) ^ 1))))))
    {
        filestar = NULL;
    }

    A->size[0] = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == NULL) ^ 1))) {
        int32_T c;
        c = 1;
        while (c > 0) {
            int32_T i;
            int32_T loop_ub;
            int32_T numRead;
            int32_T tmp;
            c = 0;
            numRead = 1;
            while (static_cast<boolean_T>(static_cast<int32_T>((c < 1024) &
                     (numRead > 0)))) {
                size_t numReadSizeT;
                numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c),
                                     filestar);
                numRead = (int32_T)numReadSizeT;
                c = static_cast<int32_T>(c + (int32_T)numReadSizeT);
            }

            numRead = A->size[0];
            if (c < 1) {
                i = -1;
                loop_ub = -1;
            } else {
                i = static_cast<int32_T>(c - 1);
                loop_ub = static_cast<int32_T>(c - 1);
            }

            tmp = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(i + A->size[0])
                + 1);
            ImmedMission_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static int8_T ImmedMission_filedata(DW_ImmedMission_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static int8_T ImmedMission_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_ImmedMission_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = ImmedMission_filedata(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles[static_cast<int32_T>(static_cast<int32_T>(j)
                - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_fread(real_T fileID, emxArray_char_T_ImmedMission_T *A,
    DW_ImmedMission_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(fileID);
    if (fileID != static_cast<real_T>(static_cast<int8_T>(fileID))) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        filestar = localDW->eml_openfiles[static_cast<int32_T>
            (static_cast<int32_T>(fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
              static_cast<boolean_T>(static_cast<int32_T>((fileID != 0.0) ^ 1)))
             | static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
               ((fileID != 1.0) ^ 1)))))) | static_cast<int32_T>
            (static_cast<boolean_T>(static_cast<int32_T>((fileID != 2.0) ^ 1))))))
    {
        filestar = NULL;
    }

    A->size[0] = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == NULL) ^ 1))) {
        int32_T c;
        c = 1;
        while (c > 0) {
            int32_T i;
            int32_T loop_ub;
            int32_T numRead;
            int32_T tmp;
            c = 0;
            numRead = 1;
            while (static_cast<boolean_T>(static_cast<int32_T>((c < 1024) &
                     (numRead > 0)))) {
                size_t numReadSizeT;
                numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c),
                                     filestar);
                numRead = (int32_T)numReadSizeT;
                c = static_cast<int32_T>(c + (int32_T)numReadSizeT);
            }

            numRead = A->size[0];
            if (c < 1) {
                i = -1;
                loop_ub = -1;
            } else {
                i = static_cast<int32_T>(c - 1);
                loop_ub = static_cast<int32_T>(c - 1);
            }

            tmp = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(i + A->size[0])
                + 1);
            ImmedMission_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_copysign(emxArray_char_T_ImmedMission_T *s1, int32_T
    *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T *foundsign, boolean_T *success)
{
    static const boolean_T b[128]{ false, false, false, false, false, false,
        false, false, false, true, true, true, true, true, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, true, true, true, true, true, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false };

    boolean_T exitg1;
    boolean_T isneg;
    isneg = false;
    *foundsign = false;
    exitg1 = false;
    while ((!exitg1) && (*k <= n)) {
        char_T tmp;
        tmp = s->data[static_cast<int32_T>(*k - 1)];
        if (tmp == '-') {
            isneg = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(isneg) ^ 1));
            *foundsign = true;
            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == ',') {
            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == '+') {
            *foundsign = true;
            *k = static_cast<int32_T>(*k + 1);
        } else if (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(b[static_cast<int32_T>
                      (static_cast<int32_T>(static_cast<uint8_T>(tmp)) & 127)]) ^
                     1))) {
            exitg1 = true;
        } else {
            *k = static_cast<int32_T>(*k + 1);
        }
    }

    *success = (*k <= n);
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (*success) & static_cast<int32_T>(isneg)))) {
        if ((*idx >= 2) && (s1->data[static_cast<int32_T>(*idx - 2)] == '-')) {
            s1->data[static_cast<int32_T>(*idx - 2)] = ' ';
        } else {
            s1->data[static_cast<int32_T>(*idx - 1)] = '-';
            *idx = static_cast<int32_T>(*idx + 1);
        }
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static boolean_T ImmedMission_isUnitImag(const emxArray_char_T_ImmedMission_T *s,
    int32_T k, int32_T n)
{
    boolean_T p;
    p = false;
    if (k <= n) {
        char_T c_idx_0;
        c_idx_0 = s->data[static_cast<int32_T>(k - 1)];
        if (c_idx_0 == 'j') {
            p = true;
        } else if (c_idx_0 == 'i') {
            if (k >= static_cast<int32_T>(n - 1)) {
                p = true;
            } else {
                int32_T b_k;
                char_T c_idx_1;
                char_T c_idx_2;
                b_k = k;
                c_idx_0 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_0 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                b_k = static_cast<int32_T>(b_k + 1);
                c_idx_1 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_1 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                b_k = static_cast<int32_T>(b_k + 1);
                c_idx_2 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_2 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
                     (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f')))
                {
                } else if ((c_idx_0 == 'N') || (c_idx_0 == 'n')) {
                    if ((c_idx_1 == 'A') || (c_idx_1 == 'a')) {
                        if ((c_idx_2 != 'N') && (c_idx_2 != 'n')) {
                            p = true;
                        }
                    } else {
                        p = true;
                    }
                } else {
                    p = true;
                }
            }
        }
    }

    return p;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_readNonFinite(const emxArray_char_T_ImmedMission_T *s,
    int32_T *k, int32_T n, boolean_T *b_finite, real_T *fv)
{
    int32_T ksaved;
    char_T c_idx_0;
    char_T c_idx_1;
    char_T c_idx_2;
    ksaved = *k;
    c_idx_0 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    c_idx_1 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_1 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    c_idx_2 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_2 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') || (c_idx_1 ==
          'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
        *b_finite = false;
        *fv = (rtInf);
    } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
                (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
        *b_finite = false;
        *fv = (rtNaN);
    } else {
        *b_finite = true;
        *fv = 0.0;
        *k = ksaved;
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static boolean_T ImmedMission_copydigits(emxArray_char_T_ImmedMission_T *s1,
    int32_T *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T allowpoint)
{
    boolean_T exitg1;
    boolean_T haspoint;
    boolean_T success;
    success = (*k <= n);
    haspoint = false;
    exitg1 = false;
    while ((!exitg1) && (static_cast<boolean_T>(static_cast<int32_T>((*k <= n) &
              static_cast<int32_T>(success))))) {
        char_T tmp;
        tmp = s->data[static_cast<int32_T>(*k - 1)];
        if ((tmp >= '0') && (tmp <= '9')) {
            s1->data[static_cast<int32_T>(*idx - 1)] = tmp;
            *idx = static_cast<int32_T>(*idx + 1);
            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == '.') {
            success = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(haspoint) ^ 1))) & static_cast<int32_T>
                 (allowpoint)));
            if (success) {
                s1->data[static_cast<int32_T>(*idx - 1)] = '.';
                *idx = static_cast<int32_T>(*idx + 1);
                haspoint = true;
            }

            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == ',') {
            *k = static_cast<int32_T>(*k + 1);
        } else {
            exitg1 = true;
        }
    }

    return success;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static boolean_T ImmedMission_copyexponent(emxArray_char_T_ImmedMission_T *s1,
    int32_T *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n)
{
    int32_T b_k;
    boolean_T success;
    success = true;
    if (*k <= n) {
        char_T tmp;
        tmp = s->data[static_cast<int32_T>(*k - 1)];
        if ((tmp == 'E') || (tmp == 'e')) {
            int32_T kexp;
            boolean_T b_success;
            s1->data[static_cast<int32_T>(*idx - 1)] = 'e';
            *idx = static_cast<int32_T>(*idx + 1);
            *k = static_cast<int32_T>(*k + 1);
            while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ','))
            {
                *k = static_cast<int32_T>(*k + 1);
            }

            if (*k <= n) {
                if (s->data[static_cast<int32_T>(*k - 1)] == '-') {
                    s1->data[static_cast<int32_T>(*idx - 1)] = '-';
                    *idx = static_cast<int32_T>(*idx + 1);
                    *k = static_cast<int32_T>(*k + 1);
                } else if (s->data[static_cast<int32_T>(*k - 1)] == '+') {
                    *k = static_cast<int32_T>(*k + 1);
                }
            }

            kexp = *k;
            b_k = *k;
            b_success = ImmedMission_copydigits(s1, idx, s, &b_k, n, false);
            *k = b_k;
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(b_success) ^ 1))) | (b_k <= kexp)))) {
                success = false;
            }
        }
    }

    return success;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_readfloat(emxArray_char_T_ImmedMission_T *s1, int32_T
    *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign,
    boolean_T *success)
{
    static const boolean_T b[128]{ false, false, false, false, false, false,
        false, false, false, true, true, true, true, true, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, true, true, true, true, true, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false };

    int32_T b_idx;
    int32_T b_k;
    boolean_T a__3;
    *isimag = false;
    *b_finite = true;
    *nfv = 0.0;
    b_idx = *idx;
    b_k = *k;
    ImmedMission_copysign(s1, &b_idx, s, &b_k, n, foundsign, success);
    *idx = b_idx;
    *k = b_k;
    if (*success) {
        char_T tmp;
        boolean_T exitg1;
        if (ImmedMission_isUnitImag(s, b_k, n)) {
            *isimag = true;
            *k = static_cast<int32_T>(b_k + 1);
            exitg1 = false;
            while ((!exitg1) && (*k <= n)) {
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(tmp)) & 127)] ||
                    (tmp == '\x00') || (tmp == ',')) {
                    *k = static_cast<int32_T>(*k + 1);
                } else {
                    exitg1 = true;
                }
            }

            if ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == '*')) {
                b_k = static_cast<int32_T>(*k + 1);
                ImmedMission_copysign(s1, &b_idx, s, &b_k, n, &a__3, success);
                *idx = b_idx;
                if (*success) {
                    if (ImmedMission_isUnitImag(s, b_k, n)) {
                        *success = false;
                    } else {
                        ImmedMission_readNonFinite(s, &b_k, n, b_finite, nfv);
                        if (*b_finite) {
                            *success = ImmedMission_copydigits(s1, idx, s, &b_k,
                                n, true);
                            if (*success) {
                                *success = ImmedMission_copyexponent(s1, idx, s,
                                    &b_k, n);
                            }
                        } else if ((b_idx >= 2) && (s1->data[static_cast<int32_T>
                                                    (b_idx - 2)] == '-')) {
                            *idx = static_cast<int32_T>(b_idx - 1);
                            s1->data[static_cast<int32_T>(b_idx - 2)] = ' ';
                            *nfv = -*nfv;
                        }

                        exitg1 = false;
                        while ((!exitg1) && (b_k <= n)) {
                            tmp = s->data[static_cast<int32_T>(b_k - 1)];
                            if (b[static_cast<int32_T>(static_cast<int32_T>(
                                    static_cast<uint8_T>(tmp)) & 127)] || (tmp ==
                                 '\x00') || (tmp == ',')) {
                                b_k = static_cast<int32_T>(b_k + 1);
                            } else {
                                exitg1 = true;
                            }
                        }

                        if ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)]
                                           == '*')) {
                            b_k = static_cast<int32_T>(b_k + 1);
                            exitg1 = false;
                            while ((!exitg1) && (b_k <= n)) {
                                tmp = s->data[static_cast<int32_T>(b_k - 1)];
                                if (b[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(tmp)) & 127)] ||
                                        (tmp == '\x00') || (tmp == ',')) {
                                    b_k = static_cast<int32_T>(b_k + 1);
                                } else {
                                    exitg1 = true;
                                }
                            }
                        }

                        if (b_k <= n) {
                            tmp = s->data[static_cast<int32_T>(b_k - 1)];
                            if ((tmp == 'i') || (tmp == 'j')) {
                                b_k = static_cast<int32_T>(b_k + 1);
                            }
                        }
                    }

                    exitg1 = false;
                    while ((!exitg1) && (b_k <= n)) {
                        tmp = s->data[static_cast<int32_T>(b_k - 1)];
                        if (b[static_cast<int32_T>(static_cast<int32_T>(
                                static_cast<uint8_T>(tmp)) & 127)] || (tmp ==
                                '\x00') || (tmp == ',')) {
                            b_k = static_cast<int32_T>(b_k + 1);
                        } else {
                            exitg1 = true;
                        }
                    }
                }

                *k = b_k;
            } else {
                s1->data[static_cast<int32_T>(b_idx - 1)] = '1';
                *idx = static_cast<int32_T>(b_idx + 1);
            }
        } else {
            ImmedMission_readNonFinite(s, &b_k, n, b_finite, nfv);
            *k = b_k;
            if (*b_finite) {
                *success = ImmedMission_copydigits(s1, idx, s, k, n, true);
                if (*success) {
                    *success = ImmedMission_copyexponent(s1, idx, s, k, n);
                }
            } else if ((b_idx >= 2) && (s1->data[static_cast<int32_T>(b_idx - 2)]
                        == '-')) {
                *idx = static_cast<int32_T>(b_idx - 1);
                s1->data[static_cast<int32_T>(b_idx - 2)] = ' ';
                *nfv = -*nfv;
            }

            exitg1 = false;
            while ((!exitg1) && (*k <= n)) {
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(s->data[
                        static_cast<int32_T>(*k - 1)])) & 127)]) {
                    *k = static_cast<int32_T>(*k + 1);
                } else {
                    tmp = s->data[static_cast<int32_T>(*k - 1)];
                    if ((tmp == '\x00') || (tmp == ',')) {
                        *k = static_cast<int32_T>(*k + 1);
                    } else {
                        exitg1 = true;
                    }
                }
            }

            if ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == '*')) {
                *k = static_cast<int32_T>(*k + 1);
                while ((*k <= n) && (b[static_cast<int32_T>(static_cast<int32_T>
                         (static_cast<uint8_T>(s->data[static_cast<int32_T>(*k -
                            1)])) & 127)] || (s->data[static_cast<int32_T>(*k -
                          1)] == '\x00') || (s->data[static_cast<int32_T>(*k - 1)]
                         == ','))) {
                    *k = static_cast<int32_T>(*k + 1);
                }
            }

            if (*k <= n) {
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if ((tmp == 'i') || (tmp == 'j')) {
                    *k = static_cast<int32_T>(*k + 1);
                    *isimag = true;
                }
            }
        }

        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
            if (b[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                    (s->data[static_cast<int32_T>(*k - 1)])) & 127)]) {
                *k = static_cast<int32_T>(*k + 1);
            } else {
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if ((tmp == '\x00') || (tmp == ',')) {
                    *k = static_cast<int32_T>(*k + 1);
                } else {
                    exitg1 = true;
                }
            }
        }
    }
}

static void ImmedMission_emxFree_char_T(emxArray_char_T_ImmedMission_T
    **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_char_T_ImmedMission_T *>(nullptr)) {
        if (((*pEmxArray)->data != static_cast<char_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_char_T_ImmedMission_T *>(nullptr);
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static creal_T ImmedMission_str2double(const emxArray_char_T_ImmedMission_T *s)
{
    static const boolean_T c[128]{ false, false, false, false, false, false,
        false, false, false, true, true, true, true, true, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, true, true, true, true, true, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false };

    emxArray_char_T_ImmedMission_T *s1;
    creal_T x;
    real_T b_scanned1;
    real_T scanned1;
    real_T scanned2;
    int32_T idx;
    int32_T k;
    boolean_T a__1;
    boolean_T c_success;
    boolean_T foundsign;
    boolean_T isfinite1;
    boolean_T isimag1;
    boolean_T success;
    x.re = (rtNaN);
    x.im = 0.0;
    if (s->size[1] >= 1) {
        int32_T i;
        int32_T ntoread;
        boolean_T exitg1;
        ImmedMission_emxInit_char_T(&s1, 2);
        ntoread = 0;
        k = 1;
        exitg1 = false;
        while ((!exitg1) && (k <= s->size[1])) {
            char_T tmp;
            tmp = s->data[static_cast<int32_T>(k - 1)];
            if (c[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                    (tmp)) & 127)] || (tmp == '\x00')) {
                k = static_cast<int32_T>(k + 1);
            } else {
                exitg1 = true;
            }
        }

        i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
        s1->size[0] = 1;
        s1->size[1] = static_cast<int32_T>(s->size[1] + 2);
        ImmedMission_emxEnsureCapacity_char_T(s1, i);
        idx = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(idx + 1); i++) {
            s1->data[i] = '\x00';
        }

        idx = 1;
        ImmedMission_readfloat(s1, &idx, s, &k, s->size[1], &isimag1, &isfinite1,
                               &scanned1, &a__1, &success);
        if (isfinite1) {
            ntoread = 1;
        }

        if (success) {
            if (k <= s->size[1]) {
                s1->data[static_cast<int32_T>(idx - 1)] = ' ';
                idx = static_cast<int32_T>(idx + 1);
                ImmedMission_readfloat(s1, &idx, s, &k, s->size[1], &a__1,
                                       &success, &scanned2, &foundsign,
                                       &c_success);
                if (success) {
                    ntoread = static_cast<int32_T>(ntoread + 1);
                }

                success = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(isimag1) ^
                    static_cast<int32_T>(a__1)))) & static_cast<int32_T>
                     (foundsign)))) & (k > s->size[1])))) & static_cast<int32_T>
                    (c_success)));
            } else {
                scanned2 = 0.0;
            }
        } else {
            scanned2 = 0.0;
        }

        if (success) {
            s1->data[static_cast<int32_T>(idx - 1)] = '\x00';
            switch (ntoread) {
              case 2:
                ntoread = sscanf(&s1->data[0], "%lf %lf", &scanned1, &scanned2);
                if (ntoread != 2) {
                    scanned1 = (rtNaN);
                    scanned2 = (rtNaN);
                }
                break;

              case 1:
                ntoread = sscanf(&s1->data[0], "%lf", &b_scanned1);
                if (isfinite1) {
                    if (ntoread == 1) {
                        scanned1 = b_scanned1;
                    } else {
                        scanned1 = (rtNaN);
                    }
                } else if (ntoread == 1) {
                    scanned2 = b_scanned1;
                } else {
                    scanned2 = (rtNaN);
                }
                break;
            }

            if (isimag1) {
                x.re = scanned2;
                x.im = scanned1;
            } else {
                x.re = scanned1;
                x.im = scanned2;
            }
        }

        ImmedMission_emxFree_char_T(&s1);
    }

    return x;
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
static int32_T ImmedMission_cfclose_g(real_T fid, DW_ImmedMission_f_T *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(fid);
    if (fid != static_cast<real_T>(static_cast<int8_T>(fid))) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = localDW->eml_openfiles_o[static_cast<int32_T>
            (static_cast<int32_T>(b_fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(b_fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((filestar != NULL) & (
            static_cast<int32_T>(fileid) >= 3)))) {
        int32_T cst;
        cst = fclose(filestar);
        if (cst == 0) {
            st = 0;
            localDW->eml_openfiles_o[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static int32_T ImmedMission_cfclose(real_T fid, DW_ImmedMission_f_T *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(fid);
    if (fid != static_cast<real_T>(static_cast<int8_T>(fid))) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = localDW->eml_openfiles[static_cast<int32_T>
            (static_cast<int32_T>(b_fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(b_fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((filestar != NULL) & (
            static_cast<int32_T>(fileid) >= 3)))) {
        int32_T cst;
        cst = fclose(filestar);
        if (cst == 0) {
            st = 0;
            localDW->eml_openfiles[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_strtok(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
    *remain)
{
    int32_T b;
    int32_T i;
    int32_T itoken;
    int32_T k;
    int32_T n;
    n = x->size[1];
    k = 0;
    while ((static_cast<int32_T>(k + 1) <= n) && (x->data[k] == '\x0a')) {
        k = static_cast<int32_T>(k + 1);
    }

    itoken = static_cast<int32_T>(k + 1);
    while ((static_cast<int32_T>(k + 1) <= n) && (x->data[k] != '\x0a')) {
        k = static_cast<int32_T>(k + 1);
    }

    if (static_cast<int32_T>(k + 1) > x->size[1]) {
        n = 0;
        b = 0;
    } else {
        n = k;
        b = x->size[1];
    }

    i = static_cast<int32_T>(remain->size[0] * remain->size[1]);
    remain->size[0] = 1;
    b = static_cast<int32_T>(b - n);
    remain->size[1] = b;
    ImmedMission_emxEnsureCapacity_char_T(remain, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        remain->data[i] = x->data[static_cast<int32_T>(n + i)];
    }

    if (itoken > k) {
        itoken = 0;
        k = 0;
    } else {
        itoken = static_cast<int32_T>(itoken - 1);
    }

    i = static_cast<int32_T>(token->size[0] * token->size[1]);
    token->size[0] = 1;
    b = static_cast<int32_T>(k - itoken);
    token->size[1] = b;
    ImmedMission_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_strtok_i(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token)
{
    int32_T itoken;
    int32_T k;
    int32_T n;
    n = x->size[1];
    k = 1;
    while ((k <= n) && (x->data[static_cast<int32_T>(k - 1)] == ';')) {
        k = static_cast<int32_T>(k + 1);
    }

    itoken = k;
    while ((k <= n) && (x->data[static_cast<int32_T>(k - 1)] != ';')) {
        k = static_cast<int32_T>(k + 1);
    }

    if (itoken > static_cast<int32_T>(k - 1)) {
        n = 0;
        k = 0;
    } else {
        n = static_cast<int32_T>(itoken - 1);
        k = static_cast<int32_T>(k - 1);
    }

    itoken = static_cast<int32_T>(token->size[0] * token->size[1]);
    token->size[0] = 1;
    k = static_cast<int32_T>(k - n);
    token->size[1] = k;
    ImmedMission_emxEnsureCapacity_char_T(token, itoken);
    for (itoken = 0; itoken <= static_cast<int32_T>(k - 1); itoken++) {
        token->data[itoken] = x->data[static_cast<int32_T>(n + itoken)];
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_strtrim(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *y)
{
    static const boolean_T d[128]{ false, false, false, false, false, false,
        false, false, false, true, true, true, true, true, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, true, true, true, true, true, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false };

    int32_T b_j1;
    int32_T i;
    int32_T j2;
    b_j1 = 0;
    while ((static_cast<int32_T>(b_j1 + 1) <= x->size[1]) &&
            (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(d[
               static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                 (x->data[b_j1])) & 127)]) & (x->data[b_j1] != '\x00'))))) {
        b_j1 = static_cast<int32_T>(b_j1 + 1);
    }

    j2 = static_cast<int32_T>(x->size[1] - 1);
    while ((static_cast<int32_T>(j2 + 1) > 0) && (static_cast<boolean_T>(
             static_cast<int32_T>(static_cast<int32_T>(d[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<uint8_T>(x->data[j2])) & 127)])
              & (x->data[j2] != '\x00'))))) {
        j2 = static_cast<int32_T>(j2 - 1);
    }

    if (static_cast<int32_T>(b_j1 + 1) > static_cast<int32_T>(j2 + 1)) {
        b_j1 = 0;
        j2 = -1;
    }

    i = static_cast<int32_T>(y->size[0] * y->size[1]);
    y->size[0] = 1;
    j2 = static_cast<int32_T>(j2 - b_j1);
    y->size[1] = static_cast<int32_T>(j2 + 1);
    ImmedMission_emxEnsureCapacity_char_T(y, i);
    for (i = 0; i <= j2; i++) {
        y->data[i] = x->data[static_cast<int32_T>(b_j1 + i)];
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static boolean_T ImmedMission_strcmp(const emxArray_char_T_ImmedMission_T *a)
{
    static const char_T c[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

    static const char_T d[9]{ 'H', 'o', 'm', 'e', 'P', 'o', 'i', 'n', 't' };

    emxArray_char_T_ImmedMission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    ImmedMission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        ImmedMission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 9) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 9) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    ImmedMission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static boolean_T ImmedMission_strcmp_m(const emxArray_char_T_ImmedMission_T *a)
{
    static const char_T c[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

    static const char_T d[3]{ 'L', 'a', 't' };

    emxArray_char_T_ImmedMission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    ImmedMission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        ImmedMission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 3) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 3) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    ImmedMission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static boolean_T ImmedMission_contains(const emxArray_char_T_ImmedMission_T *str)
{
    int32_T matchPos;
    matchPos = 0;
    int32_T exitg1;
    do {
        exitg1 = 0;
        if (matchPos <= static_cast<int32_T>(str->size[1] - 1)) {
            if (str->data[matchPos] == '=') {
                exitg1 = 1;
            } else {
                matchPos = static_cast<int32_T>(matchPos + 1);
            }
        } else {
            matchPos = -1;
            exitg1 = 1;
        }
    } while (exitg1 == 0);

    return static_cast<int32_T>(matchPos + 1) > 0;
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_find_token(const emxArray_char_T_ImmedMission_T *x,
    int32_T *itoken, int32_T *iremain)
{
    int32_T n;
    n = x->size[1];
    *iremain = 1;
    while ((*iremain <= n) && (x->data[static_cast<int32_T>(*iremain - 1)] ==
                               '=')) {
        *iremain = static_cast<int32_T>(*iremain + 1);
    }

    *itoken = *iremain;
    while ((*iremain <= n) && (x->data[static_cast<int32_T>(*iremain - 1)] !=
                               '=')) {
        *iremain = static_cast<int32_T>(*iremain + 1);
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static void ImmedMission_strtok_iu(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
    *remain)
{
    int32_T b;
    int32_T c;
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    ImmedMission_find_token(x, &itoken, &iremain);
    if (iremain > x->size[1]) {
        c = 0;
        b = 0;
    } else {
        c = static_cast<int32_T>(iremain - 1);
        b = x->size[1];
    }

    i = static_cast<int32_T>(remain->size[0] * remain->size[1]);
    remain->size[0] = 1;
    b = static_cast<int32_T>(b - c);
    remain->size[1] = b;
    ImmedMission_emxEnsureCapacity_char_T(remain, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        remain->data[i] = x->data[static_cast<int32_T>(c + i)];
    }

    if (itoken > static_cast<int32_T>(iremain - 1)) {
        itoken = 0;
        iremain = 0;
    } else {
        itoken = static_cast<int32_T>(itoken - 1);
        iremain = static_cast<int32_T>(iremain - 1);
    }

    i = static_cast<int32_T>(token->size[0] * token->size[1]);
    token->size[0] = 1;
    b = static_cast<int32_T>(iremain - itoken);
    token->size[1] = b;
    ImmedMission_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static boolean_T ImmedMission_strcmp_m2(const emxArray_char_T_ImmedMission_T *a)
{
    static const char_T c[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

    static const char_T d[3]{ 'L', 'o', 'n' };

    emxArray_char_T_ImmedMission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    ImmedMission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        ImmedMission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 3) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 3) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    ImmedMission_emxFree_char_T(&aTmp);
    return b_bool;
}

static real_T ImmedMission_norm_p(const real_T x[2])
{
    real_T absxk;
    real_T scale;
    real_T t;
    real_T y;
    scale = 3.3121686421112381E-170;
    absxk = std::abs(x[0]);
    if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
    } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
    }

    absxk = std::abs(x[1]);
    if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
    } else {
        t = absxk / scale;
        y += t * t;
    }

    return scale * std::sqrt(y);
}

// Function for MATLAB Function: '<S24>/ReadHomePoint'
static boolean_T ImmedMission_strcmp_m2h(const emxArray_char_T_ImmedMission_T *a)
{
    static const char_T c[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

    static const char_T d[3]{ 'A', 'l', 't' };

    emxArray_char_T_ImmedMission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    ImmedMission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        ImmedMission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 3) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 3) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    ImmedMission_emxFree_char_T(&aTmp);
    return b_bool;
}

static real_T ImmedMission_norm_pv(const real_T x[3])
{
    real_T absxk;
    real_T scale;
    real_T t;
    real_T y;
    scale = 3.3121686421112381E-170;
    absxk = std::abs(x[0]);
    if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
    } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
    }

    absxk = std::abs(x[1]);
    if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
    } else {
        t = absxk / scale;
        y += t * t;
    }

    absxk = std::abs(x[2]);
    if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
    } else {
        t = absxk / scale;
        y += t * t;
    }

    return scale * std::sqrt(y);
}

static real_T ImmedMission_angdiff(real_T x, real_T y)
{
    real_T delta;
    delta = y - x;
    if (std::abs(delta) > 3.1415926535897931) {
        real_T thetaWrap;
        if (std::isnan(delta + 3.1415926535897931) || std::isinf(delta +
                3.1415926535897931)) {
            thetaWrap = (rtNaN);
        } else if (delta + 3.1415926535897931 == 0.0) {
            thetaWrap = 0.0;
        } else {
            boolean_T rEQ0;
            thetaWrap = std::fmod(delta + 3.1415926535897931, 6.2831853071795862);
            rEQ0 = (thetaWrap == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                real_T q;
                q = std::abs((delta + 3.1415926535897931) / 6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q -
                    std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
            }

            if (rEQ0) {
                thetaWrap = 0.0;
            } else if (delta + 3.1415926535897931 < 0.0) {
                thetaWrap += 6.2831853071795862;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((delta +
                3.1415926535897931 > 0.0) & (thetaWrap == 0.0)))) {
            thetaWrap = 6.2831853071795862;
        }

        delta = thetaWrap - 3.1415926535897931;
    }

    return delta;
}

// System initialize for referenced model: 'ImmedMission'
void ImmedMission_Init(boolean_T rty_ControlSwitch[2], FixedWingGuidanceBus
                       *rty_GuidanceCMD, DW_ImmedMission_f_T *localDW,
                       ZCE_ImmedMission_T *localZCE)
{
    FILE* a;

    // Start for SwitchCase: '<S1>/Switch Case'
    localDW->SwitchCase_ActiveSubsystem = -1;

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode128_DetailedInsp'
    // SystemInitialize for MATLAB Function: '<S24>/ReadHomePoint'
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S24>/ReadHomePoint'

    // Start for MATLABSystem: '<S20>/Orbit Follower'
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    localDW->obj.PrevResetSignal = 0.0;
    localDW->obj.OrbitRadiusInternal = 0.0;
    localDW->obj.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S20>/Orbit Follower'
    localDW->obj.OrbitRadiusInternal *= 0.0;
    localDW->obj.PrevResetSignal *= 0.0;
    localDW->obj.NumCircles *= 0.0;

    // Start for MATLABSystem: '<S20>/Orbit Follower'
    localDW->obj.PrevPosition[0] = 0.0;
    localDW->obj.OrbitCenterInternal[0] = 0.0;

    // InitializeConditions for MATLABSystem: '<S20>/Orbit Follower'
    localDW->obj.OrbitCenterInternal[0] *= 0.0;
    localDW->obj.PrevPosition[0] *= 0.0;

    // Start for MATLABSystem: '<S20>/Orbit Follower'
    localDW->obj.PrevPosition[1] = 0.0;
    localDW->obj.OrbitCenterInternal[1] = 0.0;

    // InitializeConditions for MATLABSystem: '<S20>/Orbit Follower'
    localDW->obj.OrbitCenterInternal[1] *= 0.0;
    localDW->obj.PrevPosition[1] *= 0.0;

    // Start for MATLABSystem: '<S20>/Orbit Follower'
    localDW->obj.PrevPosition[2] = 0.0;
    localDW->obj.OrbitCenterInternal[2] = 0.0;

    // InitializeConditions for MATLABSystem: '<S20>/Orbit Follower'
    localDW->obj.OrbitCenterInternal[2] *= 0.0;
    localDW->obj.PrevPosition[2] *= 0.0;
    localDW->obj.StartFlag = true;
    localDW->obj.SelectTurnDirectionFlag = true;
    localDW->obj.TurnDirectionInternal = 1.0;
    localDW->obj.OrbitRadiusFlag = 0U;
    localDW->obj.LookaheadDistFlag = 0U;

    // End of SystemInitialize for SubSystem: '<S1>/Mode128_DetailedInsp'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode132_pAttack'
    // SystemInitialize for MATLAB Function: '<S57>/ReadHomePoint'
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles_o[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S57>/ReadHomePoint'

    // SystemInitialize for Triggered SubSystem: '<S55>/WayPointGen'
    localZCE->WayPointGen_Trig_ZCE = NEG_ZCSIG;

    // End of SystemInitialize for SubSystem: '<S55>/WayPointGen'

    // Constant: '<S55>/Constant'
    ImmedMission_Altitude_Init(&localDW->Altitude);
    ImmedMission_Altitude_Init(&localDW->Heading);

    // End of SystemInitialize for SubSystem: '<S1>/Mode132_pAttack'

    // SystemInitialize for Merge: '<S1>/MergeCollAvoidSimUAV'
    std::memset(&localDW->MergeCollAvoidSimUAV, 0, sizeof
                (FixedWingGuidanceStateBus));

    // SystemInitialize for Merge: '<S1>/MergeControlSwitch'
    rty_ControlSwitch[0] = false;
    rty_ControlSwitch[1] = false;
    std::memset(rty_GuidanceCMD, 0, sizeof(FixedWingGuidanceBus));
}

// Disable for referenced model: 'ImmedMission'
void ImmedMission_Disable(DW_ImmedMission_f_T *localDW)
{
    // Disable for SwitchCase: '<S1>/Switch Case'
    localDW->SwitchCase_ActiveSubsystem = -1;
}

// Output and update for referenced model: 'ImmedMission'
void ImmedMission(const FixedWingGuidanceStateBus *rtu_SimUAVstate, const
                  missionCmd *rtu_MissionInput, const boolean_T *rtu_NewImmed,
                  const FixedWingGuidanceStateBus *rtu_RealUAVState, const
                  MissionModes *rtu_FlightMission_MissionMode, const real_T
                  *rtu_FlightMission_MissionLocation_degHDG, const real32_T
                  *rtu_FlightMission_params_Param3, const int32_T
                  *rtu_FlightMission_numUAV, const int32_T
                  *rtu_FlightMission_FormationPos, const real_T
                  rtu_OtherUAVstate[4096], const uint8_T *rtu_RealUAVEngaged,
                  const int32_T *rtu_SelfID, real_T *rty_TaskState,
                  FixedWingGuidanceStateBus *rty_FinalSimUAVState, boolean_T
                  rty_ControlSwitch[2], FixedWingGuidanceBus *rty_GuidanceCMD,
                  DW_ImmedMission_f_T *localDW, ZCE_ImmedMission_T *localZCE)
{
    // local block i/o variables
    real_T rtb_TmpSignalConversionAtAltitudeInport1[4];
    real_T rtb_sqrt;
    emxArray_char_T_ImmedMission_T *curKey;
    emxArray_char_T_ImmedMission_T *curLine;
    emxArray_char_T_ImmedMission_T *curSection;
    emxArray_char_T_ImmedMission_T *curVal;
    emxArray_char_T_ImmedMission_T *data;
    emxArray_char_T_ImmedMission_T *data_0;
    emxArray_char_T_ImmedMission_T *data_1;
    emxArray_char_T_ImmedMission_T *data_2;
    emxArray_char_T_ImmedMission_T *data_3;
    emxArray_char_T_ImmedMission_T *data_4;
    emxArray_char_T_ImmedMission_T *data_5;
    emxArray_char_T_ImmedMission_T *q;
    emxArray_char_T_ImmedMission_T *ret;
    emxArray_char_T_ImmedMission_T *tmp_2;
    emxArray_char_T_ImmedMission_T *tmp_3;
    emxArray_char_T_ImmedMission_T *tmp_4;
    emxArray_char_T_ImmedMission_T *tmp_5;
    emxArray_char_T_ImmedMission_T *tmp_6;
    emxArray_char_T_ImmedMission_T *tmp_7;
    emxArray_char_T_ImmedMission_T *x_0;
    real_T LLA0_a[3];
    real_T rtb_Sum_c[3];
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport2[3];
    real_T distToCenter_tmp[2];
    real_T rtb_TmpSignalConversionAtOrbitF[2];
    real_T rtb_Down;
    real_T rtb_North;
    real_T rtb_North_d;
    real_T rtb_North_tmp;
    int32_T b_exponent;
    int32_T i1;
    int32_T i2;
    int32_T iy;
    int32_T j;
    int32_T rtb_BiasOldIdx;
    int16_T c_data[1024];
    int8_T rtAction;
    int8_T rtPrevAction;
    boolean_T x[4096];
    boolean_T y[1024];
    boolean_T b_x[3];
    boolean_T exitg1;
    boolean_T isStable;
    boolean_T rtb_Compare_g;

    // MATLAB Function: '<Root>/RemoveNaN'
    // MATLAB Function 'RemoveNaN': '<S3>:1'
    // '<S3>:1:3'
    for (i1 = 0; i1 < 4096; i1++) {
        x[i1] = std::isnan(rtu_OtherUAVstate[i1]);
    }

    i1 = 0;
    i2 = 3072;
    iy = 0;
    for (j = 0; j < 1024; j++) {
        int32_T ix;
        y[j] = false;
        i1 = static_cast<int32_T>(i1 + 1);
        i2 = static_cast<int32_T>(i2 + 1);
        ix = i1;
        exitg1 = false;
        while ((!exitg1) && (ix <= i2)) {
            if (x[static_cast<int32_T>(ix - 1)]) {
                y[j] = true;
                exitg1 = true;
            } else {
                ix = static_cast<int32_T>(ix + 1024);
            }
        }

        isStable = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(y[j]) ^ 1));
        if (isStable) {
            iy = static_cast<int32_T>(iy + 1);
        }

        y[j] = isStable;
    }

    i2 = iy;
    iy = 0;
    for (j = 0; j < 1024; j++) {
        if (y[j]) {
            c_data[iy] = static_cast<int16_T>(static_cast<int32_T>(j + 1));
            iy = static_cast<int32_T>(iy + 1);
        }
    }

    // '<S3>:1:3'
    for (i1 = 0; i1 < 4; i1++) {
        for (j = 0; j <= static_cast<int32_T>(i2 - 1); j++) {
            localDW->Out_data[static_cast<int32_T>(j + static_cast<int32_T>(i2 *
                i1))] = rtu_OtherUAVstate[static_cast<int32_T>
                (static_cast<int32_T>(static_cast<int32_T>(i1 << 10) +
                  static_cast<int32_T>(c_data[j])) - 1)];
        }
    }

    // '<S3>:1:4'
    for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1++) {
        y[i1] = (localDW->Out_data[i1] != static_cast<real_T>(*rtu_SelfID));
    }

    iy = static_cast<int32_T>(i2 - 1);
    i1 = 0;
    for (j = 0; j <= iy; j++) {
        if (y[j]) {
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    // '<S3>:1:4'
    localDW->SFunction_DIMS2[0] = i1;
    localDW->SFunction_DIMS2[1] = 3;

    // End of MATLAB Function: '<Root>/RemoveNaN'

    // Chart: '<S1>/PreemptableMissionModeSelector'
    // Gateway: ImmedMissionGuidance/PreemptableMissionModeSelector
    j = 0;
    do {
        isStable = true;

        // During: ImmedMissionGuidance/PreemptableMissionModeSelector
        if (static_cast<uint32_T>(localDW->is_active_c25_ImmedMission) == 0U) {
            // Entry: ImmedMissionGuidance/PreemptableMissionModeSelector
            localDW->is_active_c25_ImmedMission = 1U;

            // Entry Internal: ImmedMissionGuidance/PreemptableMissionModeSelector 
            // Transition: '<S8>:152'
            isStable = false;
            localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
            localDW->ImmedMission_n = MissionModes::WaitToStart;

            // Entry 'WaitToStart': '<S8>:151'
        } else if (localDW->is_c25_ImmedMission == ImmedMission_IN_ImmedMission)
        {
            // During 'ImmedMission': '<S8>:154'
            if (*rtu_NewImmed) {
                // Transition: '<S8>:155'
                // Exit Internal 'ImmedMission': '<S8>:154'
                isStable = false;
                localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
                localDW->ImmedMission_n = MissionModes::WaitToStart;

                // Entry 'WaitToStart': '<S8>:151'
            }
        } else {
            // During 'WaitToStart': '<S8>:151'
            // Transition: '<S8>:153'
            switch (rtu_MissionInput->MissionMode) {
              case MissionModes::DetailedInsp:
                // Transition: '<S8>:187'
                // Transition: '<S8>:124'
                localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
                isStable = false;
                localDW->ImmedMission_n = MissionModes::DetailedInsp;
                break;

              case MissionModes::FlightMissionRH:
                // Transition: '<S8>:130'
                // Transition: '<S8>:189'
                // Transition: '<S8>:182'
                localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
                isStable = false;
                localDW->ImmedMission_n = MissionModes::FlightMissionRH;
                break;

              case MissionModes::pAttack:
                // Transition: '<S8>:185'
                // Transition: '<S8>:202'
                // Transition: '<S8>:217'
                localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
                isStable = false;
                localDW->ImmedMission_n = MissionModes::pAttack;
                break;
            }
        }

        j = static_cast<int32_T>(static_cast<uint32_T>(static_cast<uint32_T>(j)
            + 1U));
    } while (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(isStable) ^ 1))) &
                    (static_cast<uint32_T>(j) <= 1000U))));

    // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
    // Gain: '<S2>/Gain2'
    rtb_Down = -rtu_RealUAVState->Height;

    // Outputs for IfAction SubSystem: '<S1>/AvoidInterPlaneCollision' incorporates:
    //   ActionPort: '<S4>/Action Port'

    // Outputs for Atomic SubSystem: '<S9>/SelectState'
    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   SignalConversion generated from: '<S12>/To Virtual Bus'
    //   SignalConversion generated from: '<S2>/SimPose'

    rtb_North_tmp = rtu_RealUAVState->North;
    rtb_North_d = rtu_RealUAVState->East;
    rtb_North = rtu_RealUAVState->HeadingAngle;

    // End of Outputs for SubSystem: '<S9>/SelectState'
    // End of Outputs for SubSystem: '<S1>/AvoidInterPlaneCollision'
    // End of Outputs for SubSystem: '<Root>/RealState2Pose'
    rtPrevAction = localDW->SwitchCase_ActiveSubsystem;
    switch (localDW->ImmedMission_n) {
      case MissionModes::DetailedInsp:
        rtAction = 0;
        break;

      case MissionModes::FlightMissionRH:
        rtAction = 1;
        break;

      case MissionModes::pAttack:
        rtAction = 2;
        break;

      default:
        rtAction = 3;
        break;
    }

    localDW->SwitchCase_ActiveSubsystem = rtAction;
    ImmedMission_emxInit_char_T(&ret, 2);
    ImmedMission_emxInit_char_T(&data, 2);
    ImmedMission_emxInit_char_T(&curSection, 2);
    ImmedMission_emxInit_char_T(&curKey, 2);
    ImmedMission_emxInit_char_T(&curVal, 2);
    ImmedMission_emxInit_char_T(&curLine, 2);
    ImmedMission_emxInit_char_T(&x_0, 2);
    ImmedMission_emxInit_char_T(&q, 1);

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   Constant: '<S20>/ControlHdg'
    //   Constant: '<S20>/ControlSpd'
    //   Constant: '<S20>/ShiftSimUAV'
    //   Constant: '<S4>/ShiftSimUAV'
    //   Constant: '<S51>/ControlHdg'
    //   Constant: '<S51>/ControlSpd'
    //   Constant: '<S55>/Constant'
    //   Constant: '<S55>/ControlHdg'
    //   Constant: '<S55>/ControlSpd'
    //   Constant: '<S55>/InitTrigger'
    //   Constant: '<S55>/ShiftSimUAV'

    switch (rtAction) {
      case 0:
        {
            real_T Alt;
            real_T Lon;
            real_T rtb_East;
            real_T rtb_HeadingAngle;
            real_T rtb_Sum_l;
            real_T rtb_VectorConcatenate_tmp;
            real_T stateNew_idx_5;
            boolean_T guard1{ false };

            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FILE* a;

                // SystemReset for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
                //   ActionPort: '<S5>/Action Port'

                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S20>/HdgHoldLogic'
                //   MATLAB Function: '<S24>/ReadHomePoint'
                //   MATLABSystem: '<S20>/Orbit Follower'

                localDW->HomePoint_not_empty_p = false;
                a = NULL;
                for (j = 0; j < 20; j++) {
                    localDW->eml_openfiles[j] = a;
                }

                localDW->obj.OrbitRadiusInternal *= 0.0;
                localDW->obj.PrevResetSignal *= 0.0;
                localDW->obj.NumCircles *= 0.0;
                localDW->obj.OrbitCenterInternal[0] *= 0.0;
                localDW->obj.PrevPosition[0] *= 0.0;
                localDW->obj.OrbitCenterInternal[1] *= 0.0;
                localDW->obj.PrevPosition[1] *= 0.0;
                localDW->obj.OrbitCenterInternal[2] *= 0.0;
                localDW->obj.PrevPosition[2] *= 0.0;
                localDW->obj.StartFlag = true;
                localDW->obj.SelectTurnDirectionFlag = true;
                localDW->obj.TurnDirectionInternal = 1.0;
                localDW->temporalCounter_i1 = 0U;
                localDW->is_active_c1_ImmedMission = 0U;
                localDW->is_c1_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;

                // End of SystemReset for SubSystem: '<S1>/Mode128_DetailedInsp' 
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
            //   ActionPort: '<S5>/Action Port'

            // Signum: '<S20>/Sign' incorporates:
            //   DataTypeConversion: '<S20>/DoubleTurnDir'

            if (static_cast<real_T>(rtu_MissionInput->FormationPos) < 0.0) {
                rtb_HeadingAngle = -1.0;
            } else {
                rtb_HeadingAngle = static_cast<real_T>(static_cast<real_T>
                    (rtu_MissionInput->FormationPos) > 0.0);
            }

            // End of Signum: '<S20>/Sign'

            // MATLAB Function: '<S24>/ReadHomePoint'
            // MATLAB Function 'ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/ReadHomePoint': '<S27>:1' 
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->HomePoint_not_empty_p) ^ 1))) {
                creal_T tmp;
                creal_T tmp_0;
                creal_T tmp_1;

                // '<S27>:1:5'
                // '<S27>:1:6'
                ret->size[0] = 1;
                ret->size[1] = 0;
                rtPrevAction = ImmedMission_cfopen("config.ini", "rb", localDW);
                if (static_cast<int32_T>(rtPrevAction) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    ImmedMission_fread(static_cast<real_T>(rtPrevAction), q,
                                       localDW);
                    i1 = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    ImmedMission_emxEnsureCapacity_char_T(data, i1);
                    i2 = q->size[0];
                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1++) {
                        data->data[i1] = q->data[i1];
                    }

                    ImmedMission_cfclose(static_cast<real_T>(rtPrevAction),
                                         localDW);
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    ImmedMission_emxInit_char_T(&tmp_4, 2);
                    ImmedMission_emxInit_char_T(&data_2, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i1 = static_cast<int32_T>(data_2->size[0] * data_2->
                            size[1]);
                        data_2->size[0] = 1;
                        data_2->size[1] = data->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(data_2, i1);
                        j = static_cast<int32_T>(static_cast<int32_T>(data->
                            size[0] * data->size[1]) - 1);
                        for (i1 = 0; i1 <= j; i1++) {
                            data_2->data[i1] = data->data[i1];
                        }

                        ImmedMission_strtok(data_2, curLine, data);
                        ImmedMission_strtok_i(curLine, tmp_4);
                        ImmedMission_strtrim(tmp_4, curLine);
                        if (curLine->size[1] >= 2) {
                            isStable = false;
                            if (curLine->data[0] == '[') {
                                isStable = true;
                            }

                            guard1 = false;
                            if (isStable) {
                                isStable = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    isStable = true;
                                }

                                if (isStable) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = 1;
                                        iy = static_cast<int32_T>(curLine->size
                                            [1] - 1);
                                    }

                                    i1 = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    i2 = static_cast<int32_T>(iy - j);
                                    curSection->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curSection, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curSection->data[i1] = curLine->data[
                                            static_cast<int32_T>(j + i1)];
                                    }

                                    curKey->size[0] = 1;
                                    curKey->size[1] = 0;
                                } else {
                                    guard1 = true;
                                }
                            } else {
                                guard1 = true;
                            }

                            if (guard1) {
                                if (curLine->data[0] == ';') {
                                    isStable = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (isStable) ^ 1))) &&
                                        ImmedMission_contains(curLine)) {
                                    ImmedMission_strtok_iu(curLine, curVal, x_0);
                                    ImmedMission_find_token(x_0, &j, &iy);
                                    if (j > static_cast<int32_T>(iy - 1)) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = static_cast<int32_T>(j - 1);
                                        iy = static_cast<int32_T>(iy - 1);
                                    }

                                    ImmedMission_strtrim(curVal, curKey);
                                    i1 = static_cast<int32_T>(curLine->size[0] *
                                        curLine->size[1]);
                                    curLine->size[0] = 1;
                                    i2 = static_cast<int32_T>(iy - j);
                                    curLine->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curLine, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curLine->data[i1] = x_0->data[
                                            static_cast<int32_T>(j + i1)];
                                    }

                                    ImmedMission_strtrim(curLine, curVal);
                                }
                            }
                        }

                        if (ImmedMission_strcmp(curSection) &&
                                ImmedMission_strcmp_m(curKey)) {
                            i1 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            ImmedMission_emxEnsureCapacity_char_T(ret, i1);
                            i2 = curVal->size[1];
                            for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1
                                    ++) {
                                ret->data[i1] = curVal->data[i1];
                            }

                            exitg1 = true;
                        }
                    }

                    ImmedMission_emxFree_char_T(&data_2);
                    ImmedMission_emxFree_char_T(&tmp_4);
                }

                tmp = ImmedMission_str2double(ret);
                printf("Set Home Point Latitude:\t%f\n", tmp.re);
                fflush(stdout);
                ret->size[0] = 1;
                ret->size[1] = 0;
                rtPrevAction = ImmedMission_cfopen("config.ini", "rb", localDW);
                if (static_cast<int32_T>(rtPrevAction) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    ImmedMission_fread(static_cast<real_T>(rtPrevAction), q,
                                       localDW);
                    i1 = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    ImmedMission_emxEnsureCapacity_char_T(data, i1);
                    i2 = q->size[0];
                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1++) {
                        data->data[i1] = q->data[i1];
                    }

                    ImmedMission_cfclose(static_cast<real_T>(rtPrevAction),
                                         localDW);
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    ImmedMission_emxInit_char_T(&tmp_3, 2);
                    ImmedMission_emxInit_char_T(&data_1, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i1 = static_cast<int32_T>(data_1->size[0] * data_1->
                            size[1]);
                        data_1->size[0] = 1;
                        data_1->size[1] = data->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(data_1, i1);
                        j = static_cast<int32_T>(static_cast<int32_T>(data->
                            size[0] * data->size[1]) - 1);
                        for (i1 = 0; i1 <= j; i1++) {
                            data_1->data[i1] = data->data[i1];
                        }

                        ImmedMission_strtok(data_1, curLine, data);
                        ImmedMission_strtok_i(curLine, tmp_3);
                        ImmedMission_strtrim(tmp_3, curLine);
                        if (curLine->size[1] >= 2) {
                            isStable = false;
                            if (curLine->data[0] == '[') {
                                isStable = true;
                            }

                            guard1 = false;
                            if (isStable) {
                                isStable = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    isStable = true;
                                }

                                if (isStable) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = 1;
                                        iy = static_cast<int32_T>(curLine->size
                                            [1] - 1);
                                    }

                                    i1 = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    i2 = static_cast<int32_T>(iy - j);
                                    curSection->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curSection, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curSection->data[i1] = curLine->data[
                                            static_cast<int32_T>(j + i1)];
                                    }

                                    curKey->size[0] = 1;
                                    curKey->size[1] = 0;
                                } else {
                                    guard1 = true;
                                }
                            } else {
                                guard1 = true;
                            }

                            if (guard1) {
                                if (curLine->data[0] == ';') {
                                    isStable = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (isStable) ^ 1))) &&
                                        ImmedMission_contains(curLine)) {
                                    ImmedMission_strtok_iu(curLine, curVal, x_0);
                                    ImmedMission_find_token(x_0, &iy, &j);
                                    if (iy > static_cast<int32_T>(j - 1)) {
                                        iy = 0;
                                        j = 0;
                                    } else {
                                        iy = static_cast<int32_T>(iy - 1);
                                        j = static_cast<int32_T>(j - 1);
                                    }

                                    ImmedMission_strtrim(curVal, curKey);
                                    i1 = static_cast<int32_T>(curLine->size[0] *
                                        curLine->size[1]);
                                    curLine->size[0] = 1;
                                    i2 = static_cast<int32_T>(j - iy);
                                    curLine->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curLine, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curLine->data[i1] = x_0->data[
                                            static_cast<int32_T>(iy + i1)];
                                    }

                                    ImmedMission_strtrim(curLine, curVal);
                                }
                            }
                        }

                        if (ImmedMission_strcmp(curSection) &&
                                ImmedMission_strcmp_m2(curKey)) {
                            i1 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            ImmedMission_emxEnsureCapacity_char_T(ret, i1);
                            i2 = curVal->size[1];
                            for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1
                                    ++) {
                                ret->data[i1] = curVal->data[i1];
                            }

                            exitg1 = true;
                        }
                    }

                    ImmedMission_emxFree_char_T(&data_1);
                    ImmedMission_emxFree_char_T(&tmp_3);
                }

                tmp_0 = ImmedMission_str2double(ret);
                printf("Set Home Point Longitude:\t%f\n", tmp_0.re);
                fflush(stdout);
                ret->size[0] = 1;
                ret->size[1] = 0;
                rtPrevAction = ImmedMission_cfopen("config.ini", "rb", localDW);
                if (static_cast<int32_T>(rtPrevAction) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    ImmedMission_fread(static_cast<real_T>(rtPrevAction), q,
                                       localDW);
                    i1 = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    ImmedMission_emxEnsureCapacity_char_T(data, i1);
                    i2 = q->size[0];
                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1++) {
                        data->data[i1] = q->data[i1];
                    }

                    ImmedMission_cfclose(static_cast<real_T>(rtPrevAction),
                                         localDW);
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    ImmedMission_emxInit_char_T(&tmp_2, 2);
                    ImmedMission_emxInit_char_T(&data_0, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i1 = static_cast<int32_T>(data_0->size[0] * data_0->
                            size[1]);
                        data_0->size[0] = 1;
                        data_0->size[1] = data->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(data_0, i1);
                        j = static_cast<int32_T>(static_cast<int32_T>(data->
                            size[0] * data->size[1]) - 1);
                        for (i1 = 0; i1 <= j; i1++) {
                            data_0->data[i1] = data->data[i1];
                        }

                        ImmedMission_strtok(data_0, curLine, data);
                        ImmedMission_strtok_i(curLine, tmp_2);
                        ImmedMission_strtrim(tmp_2, curLine);
                        if (curLine->size[1] >= 2) {
                            isStable = false;
                            if (curLine->data[0] == '[') {
                                isStable = true;
                            }

                            guard1 = false;
                            if (isStable) {
                                isStable = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    isStable = true;
                                }

                                if (isStable) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = 1;
                                        iy = static_cast<int32_T>(curLine->size
                                            [1] - 1);
                                    }

                                    i1 = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    i2 = static_cast<int32_T>(iy - j);
                                    curSection->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curSection, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curSection->data[i1] = curLine->data[
                                            static_cast<int32_T>(j + i1)];
                                    }

                                    curKey->size[0] = 1;
                                    curKey->size[1] = 0;
                                } else {
                                    guard1 = true;
                                }
                            } else {
                                guard1 = true;
                            }

                            if (guard1) {
                                if (curLine->data[0] == ';') {
                                    isStable = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (isStable) ^ 1))) &&
                                        ImmedMission_contains(curLine)) {
                                    ImmedMission_strtok_iu(curLine, curVal, x_0);
                                    ImmedMission_find_token(x_0, &iy, &j);
                                    if (iy > static_cast<int32_T>(j - 1)) {
                                        iy = 0;
                                        j = 0;
                                    } else {
                                        iy = static_cast<int32_T>(iy - 1);
                                        j = static_cast<int32_T>(j - 1);
                                    }

                                    ImmedMission_strtrim(curVal, curKey);
                                    i1 = static_cast<int32_T>(curLine->size[0] *
                                        curLine->size[1]);
                                    curLine->size[0] = 1;
                                    i2 = static_cast<int32_T>(j - iy);
                                    curLine->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curLine, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curLine->data[i1] = x_0->data[
                                            static_cast<int32_T>(iy + i1)];
                                    }

                                    ImmedMission_strtrim(curLine, curVal);
                                }
                            }
                        }

                        if (ImmedMission_strcmp(curSection) &&
                                ImmedMission_strcmp_m2h(curKey)) {
                            i1 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            ImmedMission_emxEnsureCapacity_char_T(ret, i1);
                            i2 = curVal->size[1];
                            for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1
                                    ++) {
                                ret->data[i1] = curVal->data[i1];
                            }

                            exitg1 = true;
                        }
                    }

                    ImmedMission_emxFree_char_T(&data_0);
                    ImmedMission_emxFree_char_T(&tmp_2);
                }

                tmp_1 = ImmedMission_str2double(ret);
                printf("Set Home Point Altitude:\t%f\n", tmp_1.re);
                fflush(stdout);
                localDW->HomePoint_l[0] = tmp.re;
                localDW->HomePoint_l[1] = tmp_0.re;
                localDW->HomePoint_l[2] = tmp_1.re;
                localDW->HomePoint_not_empty_p = true;
                b_x[0] = std::isnan(localDW->HomePoint_l[0]);
                b_x[1] = std::isnan(localDW->HomePoint_l[1]);
                b_x[2] = std::isnan(localDW->HomePoint_l[2]);
                isStable = false;
                j = 0;
                exitg1 = false;
                while ((!exitg1) && (j < 3)) {
                    if (b_x[j]) {
                        isStable = true;
                        exitg1 = true;
                    } else {
                        j = static_cast<int32_T>(j + 1);
                    }
                }

                if (isStable) {
                    // '<S27>:1:7'
                    // '<S27>:1:8'
                    localDW->HomePoint_l[0] = 35.8617;
                    localDW->HomePoint_l[1] = 104.1954;
                    localDW->HomePoint_l[2] = 0.0;
                }
            }

            // Switch: '<S41>/Switch' incorporates:
            //   Abs: '<S41>/Abs'
            //   Bias: '<S41>/Bias'
            //   Bias: '<S41>/Bias1'
            //   Constant: '<S41>/Constant2'
            //   Constant: '<S42>/Constant'
            //   MATLAB Function: '<S24>/ReadHomePoint'
            //   Math: '<S41>/Math Function1'
            //   RelationalOperator: '<S42>/Compare'

            // '<S27>:1:12'
            if (std::abs(localDW->HomePoint_l[0]) > 180.0) {
                Lon = rt_modd_snf(localDW->HomePoint_l[0] + 180.0, 360.0) -
                    180.0;
            } else {
                Lon = localDW->HomePoint_l[0];
            }

            // End of Switch: '<S41>/Switch'

            // Abs: '<S38>/Abs1'
            rtb_East = std::abs(Lon);

            // Switch: '<S38>/Switch' incorporates:
            //   Bias: '<S38>/Bias'
            //   Bias: '<S38>/Bias1'
            //   Constant: '<S29>/Constant'
            //   Constant: '<S29>/Constant1'
            //   Constant: '<S40>/Constant'
            //   Gain: '<S38>/Gain'
            //   Product: '<S38>/Divide1'
            //   RelationalOperator: '<S40>/Compare'
            //   Signum: '<S38>/Sign1'
            //   Switch: '<S29>/Switch1'

            if (rtb_East > 90.0) {
                // Signum: '<S38>/Sign1'
                if (std::isnan(Lon)) {
                    Alt = (rtNaN);
                } else if (Lon < 0.0) {
                    Alt = -1.0;
                } else {
                    Alt = static_cast<real_T>(Lon > 0.0);
                }

                Lon = (-(rtb_East - 90.0) + 90.0) * Alt;
                i1 = 180;
            } else {
                i1 = 0;
            }

            // End of Switch: '<S38>/Switch'

            // Sum: '<S29>/Sum' incorporates:
            //   MATLAB Function: '<S24>/ReadHomePoint'
            //   Switch: '<S29>/Switch1'

            Alt = static_cast<real_T>(i1) + localDW->HomePoint_l[1];

            // Switch: '<S39>/Switch' incorporates:
            //   Abs: '<S39>/Abs'
            //   Bias: '<S39>/Bias'
            //   Bias: '<S39>/Bias1'
            //   Constant: '<S39>/Constant2'
            //   Constant: '<S43>/Constant'
            //   Math: '<S39>/Math Function1'
            //   RelationalOperator: '<S43>/Compare'

            if (std::abs(Alt) > 180.0) {
                Alt = rt_modd_snf(Alt + 180.0, 360.0) - 180.0;
            }

            // End of Switch: '<S39>/Switch'

            // Sum: '<S26>/Sum1'
            rtb_East = rtu_MissionInput->MissionLocation.Lat - Lon;
            stateNew_idx_5 = rtu_MissionInput->MissionLocation.Lon - Alt;

            // Switch: '<S35>/Switch' incorporates:
            //   Abs: '<S35>/Abs'
            //   Bias: '<S35>/Bias'
            //   Bias: '<S35>/Bias1'
            //   Constant: '<S35>/Constant2'
            //   Constant: '<S36>/Constant'
            //   Math: '<S35>/Math Function1'
            //   RelationalOperator: '<S36>/Compare'

            if (std::abs(rtb_East) > 180.0) {
                Alt = rt_modd_snf(rtb_East + 180.0, 360.0) - 180.0;
            } else {
                Alt = rtb_East;
            }

            // End of Switch: '<S35>/Switch'

            // Abs: '<S32>/Abs1'
            rtb_East = std::abs(Alt);

            // Switch: '<S32>/Switch' incorporates:
            //   Bias: '<S32>/Bias'
            //   Bias: '<S32>/Bias1'
            //   Constant: '<S28>/Constant'
            //   Constant: '<S28>/Constant1'
            //   Constant: '<S34>/Constant'
            //   Gain: '<S32>/Gain'
            //   Product: '<S32>/Divide1'
            //   RelationalOperator: '<S34>/Compare'
            //   Signum: '<S32>/Sign1'
            //   Switch: '<S28>/Switch1'

            if (rtb_East > 90.0) {
                // Signum: '<S32>/Sign1'
                if (std::isnan(Alt)) {
                    Alt = (rtNaN);
                } else if (Alt < 0.0) {
                    Alt = -1.0;
                } else {
                    Alt = static_cast<real_T>(Alt > 0.0);
                }

                Alt *= -(rtb_East - 90.0) + 90.0;
                i1 = 180;
            } else {
                i1 = 0;
            }

            // End of Switch: '<S32>/Switch'

            // Sum: '<S28>/Sum' incorporates:
            //   Switch: '<S28>/Switch1'

            rtb_Sum_l = static_cast<real_T>(i1) + stateNew_idx_5;

            // Switch: '<S33>/Switch' incorporates:
            //   Abs: '<S33>/Abs'
            //   Bias: '<S33>/Bias'
            //   Bias: '<S33>/Bias1'
            //   Constant: '<S33>/Constant2'
            //   Constant: '<S37>/Constant'
            //   Math: '<S33>/Math Function1'
            //   RelationalOperator: '<S37>/Compare'

            if (std::abs(rtb_Sum_l) > 180.0) {
                rtb_Sum_l = rt_modd_snf(rtb_Sum_l + 180.0, 360.0) - 180.0;
            }

            // End of Switch: '<S33>/Switch'

            // UnitConversion: '<S31>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_East = 0.017453292519943295 * Alt;
            stateNew_idx_5 = 0.017453292519943295 * rtb_Sum_l;

            // UnitConversion: '<S46>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            Lon *= 0.017453292519943295;

            // Trigonometry: '<S47>/Trigonometric Function1'
            rtb_Sum_l = std::sin(Lon);

            // Sum: '<S47>/Sum1' incorporates:
            //   Constant: '<S47>/Constant'
            //   Product: '<S47>/Product1'

            rtb_Sum_l = 1.0 - 0.0066943799901413295 * rtb_Sum_l * rtb_Sum_l;

            // Product: '<S45>/Product1' incorporates:
            //   Constant: '<S45>/Constant1'
            //   Sqrt: '<S45>/sqrt'

            Alt = 6.378137E+6 / std::sqrt(rtb_Sum_l);

            // Product: '<S30>/dNorth' incorporates:
            //   Constant: '<S45>/Constant2'
            //   Product: '<S45>/Product3'
            //   Trigonometry: '<S45>/Trigonometric Function1'

            rtb_Sum_l = rtb_East / rt_atan2d_snf(1.0, Alt * 0.99330562000985867 /
                rtb_Sum_l);

            // Product: '<S30>/dEast' incorporates:
            //   Constant: '<S45>/Constant3'
            //   Product: '<S45>/Product4'
            //   Trigonometry: '<S45>/Trigonometric Function'
            //   Trigonometry: '<S45>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            Alt = 1.0 / rt_atan2d_snf(1.0, Alt * std::cos(Lon)) * stateNew_idx_5;

            // SignalConversion generated from: '<S20>/Orbit Follower' incorporates:
            //   MATLAB Function: '<S24>/ReadHomePoint'
            //   Product: '<S30>/x*cos'
            //   Product: '<S30>/x*sin'
            //   Product: '<S30>/y*cos'
            //   Product: '<S30>/y*sin'
            //   Sum: '<S26>/Sum'
            //   Sum: '<S30>/Sum2'
            //   Sum: '<S30>/Sum3'
            //   UnaryMinus: '<S26>/Ze2height'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = Alt * 0.0 +
                rtb_Sum_l;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = Alt - rtb_Sum_l *
                0.0;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                -(rtu_MissionInput->MissionLocation.Alt - localDW->HomePoint_l[2]);

            // MATLABSystem: '<S20>/Orbit Follower' incorporates:
            //   DataTypeConversion: '<S20>/DoubleParam4'
            //   SignalConversion generated from: '<S20>/Orbit Follower'
            //   SignalConversion generated from: '<S2>/SimPose'
            //   Sum: '<S21>/Sum'

            localDW->obj.OrbitRadiusFlag = 1U;
            Lon = static_cast<real_T>(rtu_MissionInput->params.Param1);
            localDW->obj.LookaheadDistFlag = 0U;
            if (static_cast<real_T>(rtu_MissionInput->params.Param1) < 0.1) {
                Lon = 0.1;
                localDW->obj.LookaheadDistFlag = 1U;
            }

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            stateNew_idx_5 = rtb_North_tmp -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0];

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtOrbitF[0] = stateNew_idx_5;

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            rtb_VectorConcatenate_tmp = rtb_North_d -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtOrbitF[1] = rtb_VectorConcatenate_tmp;
            if (ImmedMission_norm_p(rtb_TmpSignalConversionAtOrbitF) <
                    2.47032822920623E-323) {
                LLA0_a[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

                // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
                rtb_East = rtb_North;

                // End of Outputs for SubSystem: '<Root>/RealState2Pose'
            } else {
                real_T turnVector_idx_1;
                isStable = false;
                rtb_Compare_g = true;
                j = 0;
                exitg1 = false;
                while ((!exitg1) && (j < 3)) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((localDW->obj.OrbitCenterInternal
                            [j] ==
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[j]) ^
                                                1))) {
                        rtb_Compare_g = false;
                        exitg1 = true;
                    } else {
                        j = static_cast<int32_T>(j + 1);
                    }
                }

                if (rtb_Compare_g) {
                    isStable = true;
                }

                guard1 = false;
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(isStable) ^ 1)))
                {
                    guard1 = true;
                } else {
                    isStable = false;
                    if (localDW->obj.OrbitRadiusInternal == 0.1) {
                        isStable = true;
                    }

                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(isStable) ^ 1))) {
                        guard1 = true;
                    }
                }

                if (guard1) {
                    localDW->obj.NumCircles = 0.0;
                    localDW->obj.OrbitCenterInternal[0] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                    localDW->obj.OrbitCenterInternal[1] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                    localDW->obj.OrbitCenterInternal[2] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                    localDW->obj.OrbitRadiusInternal = 0.1;
                    localDW->obj.SelectTurnDirectionFlag = true;
                }

                if (Lon >= 0.1) {
                    localDW->obj.LookaheadDistance = 0.090000000000000011;
                } else {
                    localDW->obj.LookaheadDistance = Lon;
                }

                // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
                turnVector_idx_1 = rtb_North_tmp -
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0];

                // End of Outputs for SubSystem: '<Root>/RealState2Pose'
                distToCenter_tmp[0] = turnVector_idx_1;
                distToCenter_tmp[1] = rtb_VectorConcatenate_tmp;
                Lon = std::sqrt(rtb_VectorConcatenate_tmp *
                                rtb_VectorConcatenate_tmp + turnVector_idx_1 *
                                turnVector_idx_1);
                rtb_Sum_l = std::abs(localDW->obj.LookaheadDistance + 0.1);
                isStable = std::isinf(rtb_Sum_l);
                rtb_Compare_g = std::isnan(rtb_Sum_l);
                if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                        int32_T>(isStable) | static_cast<int32_T>(rtb_Compare_g))))
                {
                    Alt = (rtNaN);
                } else if (rtb_Sum_l < 4.4501477170144028E-308) {
                    Alt = 4.94065645841247E-324;
                } else {
                    std::frexp(rtb_Sum_l, &rtb_BiasOldIdx);
                    Alt = std::ldexp(1.0, static_cast<int32_T>(rtb_BiasOldIdx -
                                      53));
                }

                guard1 = false;
                if (Lon >= (localDW->obj.LookaheadDistance + 0.1) - 5.0 * Alt) {
                    guard1 = true;
                } else {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               (static_cast<int32_T>(isStable) |
                          static_cast<int32_T>(rtb_Compare_g)))) {
                        Alt = (rtNaN);
                    } else if (rtb_Sum_l < 4.4501477170144028E-308) {
                        Alt = 4.94065645841247E-324;
                    } else {
                        std::frexp(rtb_Sum_l, &b_exponent);
                        Alt = std::ldexp(1.0, static_cast<int32_T>(b_exponent -
                                          53));
                    }

                    if (Lon <= (0.1 - localDW->obj.LookaheadDistance) + 5.0 *
                            Alt) {
                        guard1 = true;
                    } else {
                        real_T Alt_tmp;
                        real_T LLA0_a_0;
                        real_T LLA0_a_tmp;
                        real_T Lat_tmp;
                        real_T rtb_Sum_i;
                        real_T rtb_Sum_jk_tmp;
                        if (localDW->obj.StartFlag) {
                            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose' 
                            localDW->obj.PrevPosition[0] = rtb_North_tmp;
                            localDW->obj.PrevPosition[1] = rtb_North_d;

                            // End of Outputs for SubSystem: '<Root>/RealState2Pose' 
                            localDW->obj.StartFlag = false;
                        }

                        // Outputs for Atomic SubSystem: '<Root>/RealState2Pose' 
                        LLA0_a_0 = rtb_North_tmp -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0];

                        // End of Outputs for SubSystem: '<Root>/RealState2Pose' 
                        rtb_TmpSignalConversionAtOrbitF[0] = LLA0_a_0;
                        rtb_TmpSignalConversionAtOrbitF[1] =
                            rtb_VectorConcatenate_tmp;
                        Lon = ImmedMission_norm_p
                            (rtb_TmpSignalConversionAtOrbitF);
                        turnVector_idx_1 = localDW->obj.LookaheadDistance *
                            localDW->obj.LookaheadDistance;
                        rtb_Sum_l = ((turnVector_idx_1 - 0.010000000000000002) +
                                     Lon * Lon) / (2.0 * Lon);

                        // Outputs for Atomic SubSystem: '<Root>/RealState2Pose' 
                        Lat_tmp = rtb_TmpSignalConversionAtOrbitFollowerInport2
                            [0] - rtb_North_tmp;
                        rtb_East = Lat_tmp * rtb_Sum_l / Lon + rtb_North_tmp;
                        Alt_tmp = rtb_TmpSignalConversionAtOrbitFollowerInport2
                            [1] - rtb_North_d;
                        Alt = Alt_tmp * rtb_Sum_l / Lon + rtb_North_d;

                        // End of Outputs for SubSystem: '<Root>/RealState2Pose' 
                        rtb_Sum_l = std::sqrt(turnVector_idx_1 - rtb_Sum_l *
                                              rtb_Sum_l);
                        turnVector_idx_1 = Alt_tmp * rtb_Sum_l / Lon;
                        distToCenter_tmp[0] = rtb_East - turnVector_idx_1;
                        distToCenter_tmp[1] = turnVector_idx_1 + rtb_East;
                        rtb_East = Lat_tmp * rtb_Sum_l / Lon;
                        Lon = rtb_East + Alt;
                        rtb_Sum_l = Alt - rtb_East;
                        if ((rtb_HeadingAngle == 0.0) && (static_cast<boolean_T>
                                (static_cast<int32_T>(static_cast<int32_T>
                                (localDW->obj.SelectTurnDirectionFlag) ^ 1)))) {
                            rtb_East = localDW->obj.TurnDirectionInternal;
                        } else {
                            rtb_East = rtb_HeadingAngle;
                        }

                        Alt = localDW->obj.PrevPosition[0] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                        turnVector_idx_1 = localDW->obj.PrevPosition[1] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                        LLA0_a[0] = Alt;
                        LLA0_a[1] = turnVector_idx_1;
                        LLA0_a[2] = 0.0;
                        rtb_Sum_c[0] = LLA0_a_0;
                        rtb_Sum_c[1] = rtb_VectorConcatenate_tmp;
                        rtb_Sum_c[2] = 0.0;
                        if (rtb_East < 0.0) {
                            LLA0_a[0] = LLA0_a_0;
                            rtb_Sum_c[0] = Alt;
                            LLA0_a[1] = rtb_VectorConcatenate_tmp;
                            rtb_Sum_c[1] = turnVector_idx_1;
                            LLA0_a[2] = 0.0;
                            rtb_Sum_c[2] = 0.0;
                        }

                        Alt = ImmedMission_norm_pv(LLA0_a);
                        turnVector_idx_1 = ImmedMission_norm_pv(rtb_Sum_c);
                        LLA0_a_0 = LLA0_a[0] / Alt;
                        rtb_Sum_i = rtb_Sum_c[0] / turnVector_idx_1;
                        LLA0_a_tmp = LLA0_a[1] / Alt;
                        rtb_Sum_jk_tmp = rtb_Sum_c[1] / turnVector_idx_1;

                        // Outputs for Atomic SubSystem: '<Root>/RealState2Pose' 
                        localDW->obj.PrevPosition[0] = rtb_North_tmp;
                        localDW->obj.PrevPosition[1] = rtb_North_d;

                        // End of Outputs for SubSystem: '<Root>/RealState2Pose' 
                        localDW->obj.PrevPosition[2] = rtb_Down;
                        localDW->obj.NumCircles += rt_atan2d_snf(LLA0_a_0 *
                            rtb_Sum_jk_tmp - rtb_Sum_i * LLA0_a_tmp, (LLA0_a_0 *
                            rtb_Sum_i + LLA0_a_tmp * rtb_Sum_jk_tmp) + 0.0 / Alt
                            * (0.0 / turnVector_idx_1)) / 2.0 /
                            3.1415926535897931;
                        if (std::isnan(rtb_East)) {
                            Alt = (rtNaN);
                        } else if (rtb_East < 0.0) {
                            Alt = -1.0;
                        } else {
                            Alt = static_cast<real_T>(rtb_East > 0.0);
                        }

                        switch (static_cast<int32_T>(Alt)) {
                          case 1:
                            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose' 
                            if ((distToCenter_tmp[0] - rtb_North_tmp) * Alt_tmp
                                    - (Lon - rtb_North_d) * Lat_tmp > 0.0) {
                                rtb_North = distToCenter_tmp[0];
                                rtb_Sum_l = Lon;
                            } else {
                                rtb_North = distToCenter_tmp[1];
                            }

                            // End of Outputs for SubSystem: '<Root>/RealState2Pose' 
                            break;

                          case -1:
                            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose' 
                            if ((distToCenter_tmp[0] - rtb_North_tmp) * Alt_tmp
                                    - (Lon - rtb_North_d) * Lat_tmp < 0.0) {
                                rtb_North = distToCenter_tmp[0];
                                rtb_Sum_l = Lon;
                            } else {
                                rtb_North = distToCenter_tmp[1];
                            }

                            // End of Outputs for SubSystem: '<Root>/RealState2Pose' 
                            break;

                          default:
                            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose' 
                            if (std::abs(ImmedMission_angdiff(rt_atan2d_snf(Lon
                                    - rtb_North_d, distToCenter_tmp[0] -
                                    rtb_North_tmp), rtb_North)) < std::abs
                                    (ImmedMission_angdiff(rt_atan2d_snf
                                    (rtb_Sum_l - rtb_North_d, distToCenter_tmp[1]
                                     - rtb_North_tmp), rtb_North))) {
                                rtb_North = distToCenter_tmp[0];
                                rtb_Sum_l = Lon;
                            } else {
                                rtb_North = distToCenter_tmp[1];
                            }

                            if ((rtb_North - rtb_North_tmp) * Alt_tmp -
                                    (rtb_Sum_l - rtb_North_d) * Lat_tmp > 0.0) {
                                localDW->obj.TurnDirectionInternal = 1.0;
                            } else {
                                localDW->obj.TurnDirectionInternal = -1.0;
                            }

                            // End of Outputs for SubSystem: '<Root>/RealState2Pose' 
                            localDW->obj.SelectTurnDirectionFlag = false;
                            break;
                        }
                    }
                }

                if (guard1) {
                    Alt = ImmedMission_norm_p(distToCenter_tmp);
                    rtb_North = turnVector_idx_1 / Alt * 0.1 +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                    rtb_Sum_l = rtb_VectorConcatenate_tmp / Alt * 0.1 +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                }

                LLA0_a[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

                // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
                rtb_East = rt_atan2d_snf(rtb_Sum_l - rtb_North_d, rtb_North -
                    rtb_North_tmp);

                // End of Outputs for SubSystem: '<Root>/RealState2Pose'
            }

            // Sum: '<S21>/Sum'
            rtb_Sum_c[2] = rtb_Down -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Sqrt: '<S21>/sqrt' incorporates:
            //   DotProduct: '<S21>/Dot Product'

            rtb_Down = std::sqrt((stateNew_idx_5 * stateNew_idx_5 +
                                  rtb_VectorConcatenate_tmp *
                                  rtb_VectorConcatenate_tmp) + rtb_Sum_c[2] *
                                 rtb_Sum_c[2]);

            // Chart: '<S20>/HdgHoldLogic' incorporates:
            //   DataTypeConversion: '<S20>/Param2'
            //   DataTypeConversion: '<S20>/Param3'

            // Gateway: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
            if (static_cast<uint32_T>(localDW->temporalCounter_i1) < 31U) {
                localDW->temporalCounter_i1 = static_cast<uint8_T>
                    (static_cast<uint32_T>(static_cast<uint32_T>
                      (localDW->temporalCounter_i1) + 1U));
            }

            // During: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
            if (static_cast<uint32_T>(localDW->is_active_c1_ImmedMission) == 0U)
            {
                // Entry: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
                localDW->is_active_c1_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
                // Transition: '<S23>:4'
                if (rtb_Down >= static_cast<real_T>
                        (rtu_MissionInput->params.Param3)) {
                    // Transition: '<S23>:26'
                    localDW->is_c1_ImmedMission = ImmedMission_IN_OutOfRange;

                    // Entry 'OutOfRange': '<S23>:11'
                    rtb_North = 1.0;
                } else {
                    // Transition: '<S23>:27'
                    localDW->is_c1_ImmedMission = ImmedMission_IN_WithInRange;

                    // Entry 'WithInRange': '<S23>:9'
                    rtb_North = 0.0;
                }
            } else {
                switch (localDW->is_c1_ImmedMission) {
                  case ImmedMission_IN_OutOfRange:
                    // During 'OutOfRange': '<S23>:11'
                    if (rtb_Down < static_cast<real_T>
                            (rtu_MissionInput->params.Param2)) {
                        // Transition: '<S23>:15'
                        localDW->is_c1_ImmedMission =
                            ImmedMission_IN_WithInRange;

                        // Entry 'WithInRange': '<S23>:9'
                        rtb_North = 0.0;
                    } else {
                        rtb_North = 1.0;
                    }
                    break;

                  case ImmedMission_IN_Turning:
                    // During 'Turning': '<S23>:23'
                    if (static_cast<int32_T>(localDW->temporalCounter_i1) >= 20)
                    {
                        // Transition: '<S23>:24'
                        localDW->is_c1_ImmedMission = ImmedMission_IN_OutOfRange;

                        // Entry 'OutOfRange': '<S23>:11'
                        rtb_North = 1.0;
                    } else {
                        rtb_North = 2.0;
                    }
                    break;

                  default:
                    // During 'WithInRange': '<S23>:9'
                    if (rtb_Down >= static_cast<real_T>
                            (rtu_MissionInput->params.Param3)) {
                        // Transition: '<S23>:14'
                        localDW->is_c1_ImmedMission = ImmedMission_IN_Turning;
                        localDW->temporalCounter_i1 = 0U;

                        // Entry 'Turning': '<S23>:23'
                        rtb_North = 2.0;
                    } else {
                        rtb_North = 0.0;
                    }
                    break;
                }
            }

            // End of Chart: '<S20>/HdgHoldLogic'

            // DataTypeConversion: '<S20>/DoubleStatus'
            *rty_TaskState = rtb_North;

            // Outputs for Enabled SubSystem: '<S20>/FeedthroughHDG' incorporates:
            //   EnablePort: '<S22>/Enable'

            if (rtb_North > 0.0) {
                // SignalConversion generated from: '<S22>/OrbitNavHdg' incorporates:
                //   MATLABSystem: '<S20>/Orbit Follower'

                localDW->OrbitNavHdg = rtb_East;
            }

            // End of Outputs for SubSystem: '<S20>/FeedthroughHDG'

            // BusCreator: '<S20>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S20>/DoubleTurnDir'
            //   DataTypeConversion: '<S20>/Param4'
            //   Gain: '<S20>/Down2Height'
            //   Gain: '<S20>/Gain'
            //   Gain: '<S20>/GainLayering'
            //   MATLABSystem: '<S20>/Orbit Follower'
            //   Sum: '<S20>/Minus'
            //   Sum: '<S20>/SumHeight'

            rty_GuidanceCMD->Height = -((static_cast<real_T>
                (rtu_MissionInput->FormationPos) - 0.5 * rtb_HeadingAngle) *
                20.0 + LLA0_a[2]);
            rty_GuidanceCMD->AirSpeed = static_cast<real_T>
                (rtu_MissionInput->params.Param4);

            // Switch: '<S20>/Switch' incorporates:
            //   Constant: '<S20>/Constant'
            //   Constant: '<S20>/Zero'
            //   Constant: '<S25>/Constant'
            //   Product: '<S20>/Product'
            //   RelationalOperator: '<S25>/Compare'

            if (rtb_North == 2.0) {
                Alt = 2.3561944901923448 * rtb_HeadingAngle;
            } else {
                Alt = 0.0;
            }

            // BusCreator: '<S20>/GuidanceCMDBusCreator' incorporates:
            //   Sum: '<S20>/Sum'
            //   Switch: '<S20>/Switch'

            rty_GuidanceCMD->HeadingAngle = Alt + localDW->OrbitNavHdg;
            rtb_Compare_g = false;
            rty_ControlSwitch[0] = true;
            rty_ControlSwitch[1] = true;

            // End of Outputs for SubSystem: '<S1>/Mode128_DetailedInsp'
        }
        break;

      case 1:
        {
            real_T rtb_East;

            // Outputs for IfAction SubSystem: '<S1>/Mode130_FlightMissionRH' incorporates:
            //   ActionPort: '<S6>/Action Port'

            // RelationalOperator: '<S53>/Compare' incorporates:
            //   Constant: '<S53>/Constant'

            rtb_Compare_g = (*rtu_FlightMission_MissionMode == MissionModes::
                             HorzScanNav);

            // DataTypeConversion: '<S51>/DoubleStatus'
            *rty_TaskState = static_cast<real_T>(rtb_Compare_g);

            // Bias: '<S51>/BiasNumUAV'
            rtb_BiasOldIdx = *rtu_FlightMission_numUAV;

            // Abs: '<S51>/InterPlaneDis' incorporates:
            //   DataTypeConversion: '<S51>/Param3'

            rtb_East = std::abs(static_cast<real_T>
                                (*rtu_FlightMission_params_Param3));

            // Product: '<S51>/Divide' incorporates:
            //   Bias: '<S51>/BiasMissionUAV'
            //   Bias: '<S51>/BiasNumUAV'
            //   Product: '<S51>/ProductScanWidth'

            rtb_Down = static_cast<real_T>(static_cast<int32_T>(rtb_BiasOldIdx -
                1)) * rtb_East / static_cast<real_T>(static_cast<int32_T>
                (rtu_MissionInput->numUAV - 1));

            // Bias: '<S51>/BiasOldIdx'
            rtb_BiasOldIdx = *rtu_FlightMission_FormationPos;

            // Sum: '<S51>/Minus' incorporates:
            //   Bias: '<S51>/BiasNewIdx'
            //   Bias: '<S51>/BiasOldIdx'
            //   DataTypeConversion: '<S51>/DoubleTurnDir'
            //   Product: '<S51>/ProductNewShift'
            //   Product: '<S51>/ProductOldShift'

            rtb_Down = (static_cast<real_T>(rtu_MissionInput->FormationPos) -
                        1.0) * rtb_Down - static_cast<real_T>
                (static_cast<int32_T>(rtb_BiasOldIdx - 1)) * rtb_East;

            // Gain: '<S52>/Gain1'
            rtb_North = 0.017453292519943295 *
                *rtu_FlightMission_MissionLocation_degHDG;

            // Sum: '<S51>/SumNorth' incorporates:
            //   Bias: '<S51>/Rotate90deg'
            //   Product: '<S51>/ProductNorth'
            //   Trigonometry: '<S51>/Cos'

            rtb_North_d = std::cos(rtb_North + 1.5707963267948966) * rtb_Down +
                rtu_SimUAVstate->North;

            // Sum: '<S51>/SumEast' incorporates:
            //   Bias: '<S51>/Rotate90deg'
            //   Product: '<S51>/ProductEast'
            //   Trigonometry: '<S51>/Sin'

            rtb_Down = std::sin(rtb_North + 1.5707963267948966) * rtb_Down +
                rtu_SimUAVstate->East;

            // DataTypeConversion: '<S51>/DoubleFormPos'
            rtb_East = static_cast<real_T>(*rtu_FlightMission_FormationPos);

            // Sum: '<S51>/SumHeight' incorporates:
            //   Bias: '<S51>/NewBias'
            //   Bias: '<S51>/OldBias'
            //   Constant: '<S51>/Three'
            //   DataTypeConversion: '<S51>/DoubleTurnDir'
            //   Gain: '<S51>/Gain'
            //   Math: '<S51>/NewMod'
            //   Math: '<S51>/OldMod'
            //   Sum: '<S51>/MinusLayer'

            rtb_East = (rt_modd_snf(static_cast<real_T>
                                    (rtu_MissionInput->FormationPos) - 1.0, 3.0)
                        - rt_modd_snf(rtb_East - 1.0, 3.0)) * 15.0 +
                rtu_SimUAVstate->Height;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   BusAssignment: '<S51>/Bus Assignment'

            localDW->MergeCollAvoidSimUAV = *rtu_SimUAVstate;

            // BusAssignment: '<S51>/Bus Assignment'
            localDW->MergeCollAvoidSimUAV.North = rtb_North_d;
            localDW->MergeCollAvoidSimUAV.East = rtb_Down;
            localDW->MergeCollAvoidSimUAV.Height = rtb_East;
            rty_ControlSwitch[0] = false;
            rty_ControlSwitch[1] = false;

            // End of Outputs for SubSystem: '<S1>/Mode130_FlightMissionRH'
        }
        break;

      case 2:
        {
            real_T Alt;
            real_T Lon;
            real_T rtb_East;
            real_T rtb_HeadingAngle;
            real_T rtb_Sum_l;
            real_T stateNew_idx_5;
            ZCEventType zcEvent;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FILE* a;

                // SystemReset for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
                //   ActionPort: '<S7>/Action Port'

                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   MATLAB Function: '<S57>/ReadHomePoint'

                localDW->HomePoint_not_empty = false;
                a = NULL;
                for (j = 0; j < 20; j++) {
                    localDW->eml_openfiles_o[j] = a;
                }

                // SystemReset for Triggered SubSystem: '<S55>/WayPointGen'
                localZCE->WayPointGen_Trig_ZCE = NEG_ZCSIG;

                // End of SystemReset for SubSystem: '<S55>/WayPointGen'
                ImmedMission_Altitude_Reset(&localDW->Altitude);
                ImmedMission_Altitude_Reset(&localDW->Heading);

                // End of SystemReset for SubSystem: '<S1>/Mode132_pAttack'
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
            //   ActionPort: '<S7>/Action Port'

            // MATLAB Function: '<S57>/ReadHomePoint'
            // MATLAB Function 'ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/ReadHomePoint': '<S60>:1' 
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->HomePoint_not_empty) ^ 1))) {
                creal_T tmp;
                creal_T tmp_0;
                creal_T tmp_1;
                boolean_T guard1;

                // '<S60>:1:5'
                // '<S60>:1:6'
                ret->size[0] = 1;
                ret->size[1] = 0;
                rtPrevAction = ImmedMission_cfopen_j("config.ini", "rb", localDW);
                if (static_cast<int32_T>(rtPrevAction) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    ImmedMission_fread_o(static_cast<real_T>(rtPrevAction), q,
                                         localDW);
                    i1 = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    ImmedMission_emxEnsureCapacity_char_T(data, i1);
                    i2 = q->size[0];
                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1++) {
                        data->data[i1] = q->data[i1];
                    }

                    ImmedMission_cfclose_g(static_cast<real_T>(rtPrevAction),
                                           localDW);
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    ImmedMission_emxInit_char_T(&tmp_7, 2);
                    ImmedMission_emxInit_char_T(&data_5, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i1 = static_cast<int32_T>(data_5->size[0] * data_5->
                            size[1]);
                        data_5->size[0] = 1;
                        data_5->size[1] = data->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(data_5, i1);
                        j = static_cast<int32_T>(static_cast<int32_T>(data->
                            size[0] * data->size[1]) - 1);
                        for (i1 = 0; i1 <= j; i1++) {
                            data_5->data[i1] = data->data[i1];
                        }

                        ImmedMission_strtok(data_5, curLine, data);
                        ImmedMission_strtok_i(curLine, tmp_7);
                        ImmedMission_strtrim(tmp_7, curLine);
                        if (curLine->size[1] >= 2) {
                            isStable = false;
                            if (curLine->data[0] == '[') {
                                isStable = true;
                            }

                            guard1 = false;
                            if (isStable) {
                                isStable = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    isStable = true;
                                }

                                if (isStable) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = 1;
                                        iy = static_cast<int32_T>(curLine->size
                                            [1] - 1);
                                    }

                                    i1 = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    i2 = static_cast<int32_T>(iy - j);
                                    curSection->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curSection, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curSection->data[i1] = curLine->data[
                                            static_cast<int32_T>(j + i1)];
                                    }

                                    curKey->size[0] = 1;
                                    curKey->size[1] = 0;
                                } else {
                                    guard1 = true;
                                }
                            } else {
                                guard1 = true;
                            }

                            if (guard1) {
                                if (curLine->data[0] == ';') {
                                    isStable = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (isStable) ^ 1))) &&
                                        ImmedMission_contains(curLine)) {
                                    ImmedMission_strtok_iu(curLine, curVal, x_0);
                                    ImmedMission_find_token(x_0, &j, &iy);
                                    if (j > static_cast<int32_T>(iy - 1)) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = static_cast<int32_T>(j - 1);
                                        iy = static_cast<int32_T>(iy - 1);
                                    }

                                    ImmedMission_strtrim(curVal, curKey);
                                    i1 = static_cast<int32_T>(curLine->size[0] *
                                        curLine->size[1]);
                                    curLine->size[0] = 1;
                                    i2 = static_cast<int32_T>(iy - j);
                                    curLine->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curLine, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curLine->data[i1] = x_0->data[
                                            static_cast<int32_T>(j + i1)];
                                    }

                                    ImmedMission_strtrim(curLine, curVal);
                                }
                            }
                        }

                        if (ImmedMission_strcmp(curSection) &&
                                ImmedMission_strcmp_m(curKey)) {
                            i1 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            ImmedMission_emxEnsureCapacity_char_T(ret, i1);
                            i2 = curVal->size[1];
                            for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1
                                    ++) {
                                ret->data[i1] = curVal->data[i1];
                            }

                            exitg1 = true;
                        }
                    }

                    ImmedMission_emxFree_char_T(&data_5);
                    ImmedMission_emxFree_char_T(&tmp_7);
                }

                tmp = ImmedMission_str2double(ret);
                printf("Set Home Point Latitude:\t%f\n", tmp.re);
                fflush(stdout);
                ret->size[0] = 1;
                ret->size[1] = 0;
                rtPrevAction = ImmedMission_cfopen_j("config.ini", "rb", localDW);
                if (static_cast<int32_T>(rtPrevAction) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    ImmedMission_fread_o(static_cast<real_T>(rtPrevAction), q,
                                         localDW);
                    i1 = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    ImmedMission_emxEnsureCapacity_char_T(data, i1);
                    i2 = q->size[0];
                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1++) {
                        data->data[i1] = q->data[i1];
                    }

                    ImmedMission_cfclose_g(static_cast<real_T>(rtPrevAction),
                                           localDW);
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    ImmedMission_emxInit_char_T(&tmp_6, 2);
                    ImmedMission_emxInit_char_T(&data_4, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i1 = static_cast<int32_T>(data_4->size[0] * data_4->
                            size[1]);
                        data_4->size[0] = 1;
                        data_4->size[1] = data->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(data_4, i1);
                        j = static_cast<int32_T>(static_cast<int32_T>(data->
                            size[0] * data->size[1]) - 1);
                        for (i1 = 0; i1 <= j; i1++) {
                            data_4->data[i1] = data->data[i1];
                        }

                        ImmedMission_strtok(data_4, curLine, data);
                        ImmedMission_strtok_i(curLine, tmp_6);
                        ImmedMission_strtrim(tmp_6, curLine);
                        if (curLine->size[1] >= 2) {
                            isStable = false;
                            if (curLine->data[0] == '[') {
                                isStable = true;
                            }

                            guard1 = false;
                            if (isStable) {
                                isStable = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    isStable = true;
                                }

                                if (isStable) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = 1;
                                        iy = static_cast<int32_T>(curLine->size
                                            [1] - 1);
                                    }

                                    i1 = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    i2 = static_cast<int32_T>(iy - j);
                                    curSection->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curSection, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curSection->data[i1] = curLine->data[
                                            static_cast<int32_T>(j + i1)];
                                    }

                                    curKey->size[0] = 1;
                                    curKey->size[1] = 0;
                                } else {
                                    guard1 = true;
                                }
                            } else {
                                guard1 = true;
                            }

                            if (guard1) {
                                if (curLine->data[0] == ';') {
                                    isStable = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (isStable) ^ 1))) &&
                                        ImmedMission_contains(curLine)) {
                                    ImmedMission_strtok_iu(curLine, curVal, x_0);
                                    ImmedMission_find_token(x_0, &iy, &j);
                                    if (iy > static_cast<int32_T>(j - 1)) {
                                        iy = 0;
                                        j = 0;
                                    } else {
                                        iy = static_cast<int32_T>(iy - 1);
                                        j = static_cast<int32_T>(j - 1);
                                    }

                                    ImmedMission_strtrim(curVal, curKey);
                                    i1 = static_cast<int32_T>(curLine->size[0] *
                                        curLine->size[1]);
                                    curLine->size[0] = 1;
                                    i2 = static_cast<int32_T>(j - iy);
                                    curLine->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curLine, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curLine->data[i1] = x_0->data[
                                            static_cast<int32_T>(iy + i1)];
                                    }

                                    ImmedMission_strtrim(curLine, curVal);
                                }
                            }
                        }

                        if (ImmedMission_strcmp(curSection) &&
                                ImmedMission_strcmp_m2(curKey)) {
                            i1 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            ImmedMission_emxEnsureCapacity_char_T(ret, i1);
                            i2 = curVal->size[1];
                            for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1
                                    ++) {
                                ret->data[i1] = curVal->data[i1];
                            }

                            exitg1 = true;
                        }
                    }

                    ImmedMission_emxFree_char_T(&data_4);
                    ImmedMission_emxFree_char_T(&tmp_6);
                }

                tmp_0 = ImmedMission_str2double(ret);
                printf("Set Home Point Longitude:\t%f\n", tmp_0.re);
                fflush(stdout);
                ret->size[0] = 1;
                ret->size[1] = 0;
                rtPrevAction = ImmedMission_cfopen_j("config.ini", "rb", localDW);
                if (static_cast<int32_T>(rtPrevAction) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    ImmedMission_fread_o(static_cast<real_T>(rtPrevAction), q,
                                         localDW);
                    i1 = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    ImmedMission_emxEnsureCapacity_char_T(data, i1);
                    i2 = q->size[0];
                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1++) {
                        data->data[i1] = q->data[i1];
                    }

                    ImmedMission_cfclose_g(static_cast<real_T>(rtPrevAction),
                                           localDW);
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    ImmedMission_emxInit_char_T(&tmp_5, 2);
                    ImmedMission_emxInit_char_T(&data_3, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i1 = static_cast<int32_T>(data_3->size[0] * data_3->
                            size[1]);
                        data_3->size[0] = 1;
                        data_3->size[1] = data->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(data_3, i1);
                        j = static_cast<int32_T>(static_cast<int32_T>(data->
                            size[0] * data->size[1]) - 1);
                        for (i1 = 0; i1 <= j; i1++) {
                            data_3->data[i1] = data->data[i1];
                        }

                        ImmedMission_strtok(data_3, curLine, data);
                        ImmedMission_strtok_i(curLine, tmp_5);
                        ImmedMission_strtrim(tmp_5, curLine);
                        if (curLine->size[1] >= 2) {
                            isStable = false;
                            if (curLine->data[0] == '[') {
                                isStable = true;
                            }

                            guard1 = false;
                            if (isStable) {
                                isStable = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    isStable = true;
                                }

                                if (isStable) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = 1;
                                        iy = static_cast<int32_T>(curLine->size
                                            [1] - 1);
                                    }

                                    i1 = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    i2 = static_cast<int32_T>(iy - j);
                                    curSection->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curSection, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curSection->data[i1] = curLine->data[
                                            static_cast<int32_T>(j + i1)];
                                    }

                                    curKey->size[0] = 1;
                                    curKey->size[1] = 0;
                                } else {
                                    guard1 = true;
                                }
                            } else {
                                guard1 = true;
                            }

                            if (guard1) {
                                if (curLine->data[0] == ';') {
                                    isStable = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (isStable) ^ 1))) &&
                                        ImmedMission_contains(curLine)) {
                                    ImmedMission_strtok_iu(curLine, curVal, x_0);
                                    ImmedMission_find_token(x_0, &iy, &j);
                                    if (iy > static_cast<int32_T>(j - 1)) {
                                        iy = 0;
                                        j = 0;
                                    } else {
                                        iy = static_cast<int32_T>(iy - 1);
                                        j = static_cast<int32_T>(j - 1);
                                    }

                                    ImmedMission_strtrim(curVal, curKey);
                                    i1 = static_cast<int32_T>(curLine->size[0] *
                                        curLine->size[1]);
                                    curLine->size[0] = 1;
                                    i2 = static_cast<int32_T>(j - iy);
                                    curLine->size[1] = i2;
                                    ImmedMission_emxEnsureCapacity_char_T
                                        (curLine, i1);
                                    for (i1 = 0; i1 <= static_cast<int32_T>(i2 -
                                          1); i1++) {
                                        curLine->data[i1] = x_0->data[
                                            static_cast<int32_T>(iy + i1)];
                                    }

                                    ImmedMission_strtrim(curLine, curVal);
                                }
                            }
                        }

                        if (ImmedMission_strcmp(curSection) &&
                                ImmedMission_strcmp_m2h(curKey)) {
                            i1 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            ImmedMission_emxEnsureCapacity_char_T(ret, i1);
                            i2 = curVal->size[1];
                            for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1
                                    ++) {
                                ret->data[i1] = curVal->data[i1];
                            }

                            exitg1 = true;
                        }
                    }

                    ImmedMission_emxFree_char_T(&data_3);
                    ImmedMission_emxFree_char_T(&tmp_5);
                }

                tmp_1 = ImmedMission_str2double(ret);
                printf("Set Home Point Altitude:\t%f\n", tmp_1.re);
                fflush(stdout);
                localDW->HomePoint[0] = tmp.re;
                localDW->HomePoint[1] = tmp_0.re;
                localDW->HomePoint[2] = tmp_1.re;
                localDW->HomePoint_not_empty = true;
                b_x[0] = std::isnan(localDW->HomePoint[0]);
                b_x[1] = std::isnan(localDW->HomePoint[1]);
                b_x[2] = std::isnan(localDW->HomePoint[2]);
                isStable = false;
                j = 0;
                exitg1 = false;
                while ((!exitg1) && (j < 3)) {
                    if (b_x[j]) {
                        isStable = true;
                        exitg1 = true;
                    } else {
                        j = static_cast<int32_T>(j + 1);
                    }
                }

                if (isStable) {
                    // '<S60>:1:7'
                    // '<S60>:1:8'
                    localDW->HomePoint[0] = 35.8617;
                    localDW->HomePoint[1] = 104.1954;
                    localDW->HomePoint[2] = 0.0;
                }
            }

            // Switch: '<S74>/Switch' incorporates:
            //   Abs: '<S74>/Abs'
            //   Bias: '<S74>/Bias'
            //   Bias: '<S74>/Bias1'
            //   Constant: '<S74>/Constant2'
            //   Constant: '<S75>/Constant'
            //   MATLAB Function: '<S57>/ReadHomePoint'
            //   Math: '<S74>/Math Function1'
            //   RelationalOperator: '<S75>/Compare'

            // '<S60>:1:12'
            if (std::abs(localDW->HomePoint[0]) > 180.0) {
                Lon = rt_modd_snf(localDW->HomePoint[0] + 180.0, 360.0) - 180.0;
            } else {
                Lon = localDW->HomePoint[0];
            }

            // End of Switch: '<S74>/Switch'

            // Abs: '<S71>/Abs1'
            rtb_East = std::abs(Lon);

            // Switch: '<S71>/Switch' incorporates:
            //   Bias: '<S71>/Bias'
            //   Bias: '<S71>/Bias1'
            //   Constant: '<S62>/Constant'
            //   Constant: '<S62>/Constant1'
            //   Constant: '<S73>/Constant'
            //   Gain: '<S71>/Gain'
            //   Product: '<S71>/Divide1'
            //   RelationalOperator: '<S73>/Compare'
            //   Signum: '<S71>/Sign1'
            //   Switch: '<S62>/Switch1'

            if (rtb_East > 90.0) {
                // Signum: '<S71>/Sign1'
                if (std::isnan(Lon)) {
                    Alt = (rtNaN);
                } else if (Lon < 0.0) {
                    Alt = -1.0;
                } else {
                    Alt = static_cast<real_T>(Lon > 0.0);
                }

                Lon = (-(rtb_East - 90.0) + 90.0) * Alt;
                i1 = 180;
            } else {
                i1 = 0;
            }

            // End of Switch: '<S71>/Switch'

            // Sum: '<S62>/Sum' incorporates:
            //   MATLAB Function: '<S57>/ReadHomePoint'
            //   Switch: '<S62>/Switch1'

            Alt = static_cast<real_T>(i1) + localDW->HomePoint[1];

            // Switch: '<S72>/Switch' incorporates:
            //   Abs: '<S72>/Abs'
            //   Bias: '<S72>/Bias'
            //   Bias: '<S72>/Bias1'
            //   Constant: '<S72>/Constant2'
            //   Constant: '<S76>/Constant'
            //   Math: '<S72>/Math Function1'
            //   RelationalOperator: '<S76>/Compare'

            if (std::abs(Alt) > 180.0) {
                Alt = rt_modd_snf(Alt + 180.0, 360.0) - 180.0;
            }

            // End of Switch: '<S72>/Switch'

            // Sum: '<S59>/Sum1'
            rtb_East = rtu_MissionInput->MissionLocation.Lat - Lon;
            stateNew_idx_5 = rtu_MissionInput->MissionLocation.Lon - Alt;

            // Switch: '<S68>/Switch' incorporates:
            //   Abs: '<S68>/Abs'
            //   Bias: '<S68>/Bias'
            //   Bias: '<S68>/Bias1'
            //   Constant: '<S68>/Constant2'
            //   Constant: '<S69>/Constant'
            //   Math: '<S68>/Math Function1'
            //   RelationalOperator: '<S69>/Compare'

            if (std::abs(rtb_East) > 180.0) {
                Alt = rt_modd_snf(rtb_East + 180.0, 360.0) - 180.0;
            } else {
                Alt = rtb_East;
            }

            // End of Switch: '<S68>/Switch'

            // Abs: '<S65>/Abs1'
            rtb_East = std::abs(Alt);

            // Switch: '<S65>/Switch' incorporates:
            //   Bias: '<S65>/Bias'
            //   Bias: '<S65>/Bias1'
            //   Constant: '<S61>/Constant'
            //   Constant: '<S61>/Constant1'
            //   Constant: '<S67>/Constant'
            //   Gain: '<S65>/Gain'
            //   Product: '<S65>/Divide1'
            //   RelationalOperator: '<S67>/Compare'
            //   Signum: '<S65>/Sign1'
            //   Switch: '<S61>/Switch1'

            if (rtb_East > 90.0) {
                // Signum: '<S65>/Sign1'
                if (std::isnan(Alt)) {
                    Alt = (rtNaN);
                } else if (Alt < 0.0) {
                    Alt = -1.0;
                } else {
                    Alt = static_cast<real_T>(Alt > 0.0);
                }

                Alt *= -(rtb_East - 90.0) + 90.0;
                i1 = 180;
            } else {
                i1 = 0;
            }

            // End of Switch: '<S65>/Switch'

            // Sum: '<S61>/Sum' incorporates:
            //   Switch: '<S61>/Switch1'

            rtb_Sum_l = static_cast<real_T>(i1) + stateNew_idx_5;

            // Switch: '<S66>/Switch' incorporates:
            //   Abs: '<S66>/Abs'
            //   Bias: '<S66>/Bias'
            //   Bias: '<S66>/Bias1'
            //   Constant: '<S66>/Constant2'
            //   Constant: '<S70>/Constant'
            //   Math: '<S66>/Math Function1'
            //   RelationalOperator: '<S70>/Compare'

            if (std::abs(rtb_Sum_l) > 180.0) {
                rtb_Sum_l = rt_modd_snf(rtb_Sum_l + 180.0, 360.0) - 180.0;
            }

            // End of Switch: '<S66>/Switch'

            // UnitConversion: '<S64>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_East = 0.017453292519943295 * Alt;
            stateNew_idx_5 = 0.017453292519943295 * rtb_Sum_l;

            // UnitConversion: '<S79>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            Lon *= 0.017453292519943295;

            // Trigonometry: '<S80>/Trigonometric Function1'
            rtb_Sum_l = std::sin(Lon);

            // Sum: '<S80>/Sum1' incorporates:
            //   Constant: '<S80>/Constant'
            //   Product: '<S80>/Product1'

            rtb_Sum_l = 1.0 - 0.0066943799901413295 * rtb_Sum_l * rtb_Sum_l;

            // Product: '<S78>/Product1' incorporates:
            //   Constant: '<S78>/Constant1'
            //   Sqrt: '<S78>/sqrt'

            Alt = 6.378137E+6 / std::sqrt(rtb_Sum_l);

            // Product: '<S63>/dNorth' incorporates:
            //   Constant: '<S78>/Constant2'
            //   Product: '<S78>/Product3'
            //   Trigonometry: '<S78>/Trigonometric Function1'

            rtb_Sum_l = rtb_East / rt_atan2d_snf(1.0, Alt * 0.99330562000985867 /
                rtb_Sum_l);

            // Product: '<S63>/dEast' incorporates:
            //   Constant: '<S78>/Constant3'
            //   Product: '<S78>/Product4'
            //   Trigonometry: '<S78>/Trigonometric Function'
            //   Trigonometry: '<S78>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            Alt = 1.0 / rt_atan2d_snf(1.0, Alt * std::cos(Lon)) * stateNew_idx_5;

            // Reshape: '<S55>/ReshapeRowVec' incorporates:
            //   MATLAB Function: '<S57>/ReadHomePoint'
            //   Product: '<S63>/x*cos'
            //   Product: '<S63>/x*sin'
            //   Product: '<S63>/y*cos'
            //   Product: '<S63>/y*sin'
            //   Sum: '<S59>/Sum'
            //   Sum: '<S63>/Sum2'
            //   Sum: '<S63>/Sum3'
            //   UnaryMinus: '<S59>/Ze2height'

            rtb_Sum_c[0] = Alt * 0.0 + rtb_Sum_l;
            rtb_Sum_c[1] = Alt - rtb_Sum_l * 0.0;
            rtb_Sum_c[2] = -(rtu_MissionInput->MissionLocation.Alt -
                             localDW->HomePoint[2]);

            // Outputs for Triggered SubSystem: '<S55>/WayPointGen' incorporates:
            //   TriggerPort: '<S58>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &localZCE->WayPointGen_Trig_ZCE,
                               (1.0));
            if (zcEvent != NO_ZCEVENT) {
                // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
                // Concatenate: '<S58>/Matrix Concatenate' incorporates:
                //   Reshape: '<S55>/ReshapeRowVec'
                //   Reshape: '<S55>/RowVecPose'
                //   SignalConversion generated from: '<S2>/SimPose'
                //   SignalConversion generated from: '<S58>/MissionPos'

                localDW->MatrixConcatenate[0] = rtb_North_tmp;

                // End of Outputs for SubSystem: '<Root>/RealState2Pose'
                localDW->MatrixConcatenate[1] = rtb_Sum_c[0];

                // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
                localDW->MatrixConcatenate[2] = rtb_North_d;

                // End of Outputs for SubSystem: '<Root>/RealState2Pose'
                localDW->MatrixConcatenate[3] = rtb_Sum_c[1];
                localDW->MatrixConcatenate[4] = rtb_Down;
                localDW->MatrixConcatenate[5] = rtb_Sum_c[2];
            }

            // End of Outputs for SubSystem: '<S55>/WayPointGen'

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            // SignalConversion generated from: '<S55>/Altitude' incorporates:
            //   Constant: '<S55>/InitTrigger'
            //   SignalConversion generated from: '<S2>/SimPose'

            rtb_TmpSignalConversionAtAltitudeInport1[0] = rtb_North_tmp;
            rtb_TmpSignalConversionAtAltitudeInport1[1] = rtb_North_d;

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtAltitudeInport1[2] = rtb_Down;

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtAltitudeInport1[3] = rtb_North;

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'
            ImmedMission_Altitude(rtb_TmpSignalConversionAtAltitudeInport1,
                                  localDW->MatrixConcatenate, 50.0,
                                  &localDW->Altitude);

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            // Sum: '<S56>/Sum' incorporates:
            //   Constant: '<S55>/Constant'
            //   Reshape: '<S55>/ReshapeRowVec'
            //   Reshape: '<S55>/RowVecPose'
            //   SignalConversion generated from: '<S2>/SimPose'

            rtb_North_tmp -= rtb_Sum_c[0];

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'

            // DotProduct: '<S56>/Dot Product'
            rtb_HeadingAngle = rtb_North_tmp * rtb_North_tmp;

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            // Sum: '<S56>/Sum' incorporates:
            //   Reshape: '<S55>/ReshapeRowVec'
            //   Reshape: '<S55>/RowVecPose'
            //   SignalConversion generated from: '<S2>/SimPose'

            rtb_North_tmp = rtb_North_d - rtb_Sum_c[1];

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'

            // DotProduct: '<S56>/Dot Product'
            rtb_HeadingAngle += rtb_North_tmp * rtb_North_tmp;

            // Sum: '<S56>/Sum' incorporates:
            //   Reshape: '<S55>/ReshapeRowVec'
            //   Reshape: '<S55>/RowVecPose'

            rtb_North_tmp = rtb_Down - rtb_Sum_c[2];

            // Sqrt: '<S56>/sqrt' incorporates:
            //   DotProduct: '<S56>/Dot Product'

            rtb_sqrt = std::sqrt(rtb_North_tmp * rtb_North_tmp +
                                 rtb_HeadingAngle);
            ImmedMission_Altitude(rtb_TmpSignalConversionAtAltitudeInport1,
                                  localDW->MatrixConcatenate, rtb_sqrt,
                                  &localDW->Heading);

            // Switch: '<S55>/Switch' incorporates:
            //   Logic: '<S55>/AND'

            if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                    (localDW->Altitude.Altitude_o5) != 0) & (static_cast<int32_T>
                    (localDW->Heading.Altitude_o5) != 0)))) {
                // DataTypeConversion: '<S55>/DoubleStatus' incorporates:
                //   Constant: '<S55>/Attack'

                *rty_TaskState = 658475.0;
            } else {
                // DataTypeConversion: '<S55>/DoubleStatus' incorporates:
                //   Constant: '<S55>/Zero'

                *rty_TaskState = 0.0;
            }

            // End of Switch: '<S55>/Switch'

            // BusCreator: '<S55>/GuidanceCMDBusCreator' incorporates:
            //   Gain: '<S55>/Down2Height'

            rty_GuidanceCMD->Height = -localDW->Altitude.Altitude_o1[2];
            rty_GuidanceCMD->AirSpeed = 0.0;
            rty_GuidanceCMD->HeadingAngle = localDW->Heading.HeadingAngle;
            rtb_Compare_g = false;
            rty_ControlSwitch[0] = true;
            rty_ControlSwitch[1] = false;

            // End of Outputs for SubSystem: '<S1>/Mode132_pAttack'
        }
        break;

      default:
        {
            real_T Alt;
            real_T Lon;
            real_T rtb_HeadingAngle;
            real_T rtb_Sum_l;

            // Outputs for IfAction SubSystem: '<S1>/AvoidInterPlaneCollision' incorporates:
            //   ActionPort: '<S4>/Action Port'

            // Outputs for Atomic SubSystem: '<S9>/SelectState'
            // SignalConversion generated from: '<S12>/To Virtual Bus'
            rtb_HeadingAngle = rtu_RealUAVState->AirSpeed;

            // SignalConversion generated from: '<S12>/To Virtual Bus'
            Lon = rtu_RealUAVState->FlightPathAngle;

            // SignalConversion generated from: '<S12>/To Virtual Bus'
            Alt = rtu_RealUAVState->RollAngle;

            // End of Outputs for SubSystem: '<S9>/SelectState'

            // Product: '<S11>/HorizSpd' incorporates:
            //   Trigonometry: '<S11>/Cos'

            rtb_Sum_l = rtb_HeadingAngle * std::cos(Lon);

            // Outputs for Enabled SubSystem: '<S11>/DivisionByZeroProtection' incorporates:
            //   EnablePort: '<S14>/Enable'

            if (rtb_Sum_l > 0.0) {
                // Product: '<S14>/Divide' incorporates:
                //   Gain: '<S11>/Gravity'
                //   Trigonometry: '<S11>/Tan'

                localDW->Omega = 1.0 / rtb_Sum_l * (9.81 * std::tan(Alt));
            }

            // End of Outputs for SubSystem: '<S11>/DivisionByZeroProtection'

            // MATLAB Function: '<S9>/pdist2'
            // MATLAB Function 'ConstTurnPredState/MATLAB Function': '<S15>:1'
            // '<S15>:1:2'
            // '<S15>:1:4'
            // '<S15>:1:5'
            // MATLAB Function 'ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/pdist2': '<S13>:1' 
            if (localDW->SFunction_DIMS2[0] == 0) {
                j = 0;
            } else {
                j = localDW->SFunction_DIMS2[0];
            }

            // '<S13>:1:2'
            localDW->SFunction_DIMS2_g = j;

            // End of MATLAB Function: '<S9>/pdist2'

            // Logic: '<S9>/AND' incorporates:
            //   Constant: '<S9>/ControlSpd'

            rty_ControlSwitch[0] = false;
            rty_ControlSwitch[1] = false;

            // DataTypeConversion: '<S9>/Cast To Double'
            *rty_TaskState = 0.0;

            // BusCreator: '<S9>/GuidanceCMDBusCreator'
            rty_GuidanceCMD->Height = 0.0;
            rty_GuidanceCMD->AirSpeed = 0.0;
            rty_GuidanceCMD->HeadingAngle = 0.0;
            rtb_Compare_g = false;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   Constant: '<S4>/ShiftSimUAV'
            //   SignalConversion generated from: '<S4>/SimUAVstate'

            localDW->MergeCollAvoidSimUAV = *rtu_SimUAVstate;

            // End of Outputs for SubSystem: '<S1>/AvoidInterPlaneCollision'
        }
        break;
    }

    ImmedMission_emxFree_char_T(&q);
    ImmedMission_emxFree_char_T(&x_0);
    ImmedMission_emxFree_char_T(&curLine);
    ImmedMission_emxFree_char_T(&curVal);
    ImmedMission_emxFree_char_T(&curKey);
    ImmedMission_emxFree_char_T(&curSection);
    ImmedMission_emxFree_char_T(&data);
    ImmedMission_emxFree_char_T(&ret);

    // Switch: '<Root>/SwitchShiftSimUAV'
    if (rtb_Compare_g) {
        *rty_FinalSimUAVState = localDW->MergeCollAvoidSimUAV;
    } else {
        *rty_FinalSimUAVState = *rtu_SimUAVstate;
    }

    // End of Switch: '<Root>/SwitchShiftSimUAV'

    // Update for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput = *rtu_RealUAVEngaged;
}

// Model initialize function
void ImmedMission_initialize(const char_T **rt_errorStatus,
    RT_MODEL_ImmedMission_T *const ImmedMission_M)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));

    // initialize error status
    rtmSetErrorStatusPointer(ImmedMission_M, rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
