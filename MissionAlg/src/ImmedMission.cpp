//
// File: ImmedMission.cpp
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 3.19
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  1 23:05:15 2022
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
#include <math.h>
#include "rt_atan2d_snf.h"
#include <cstring>
#include <stdio.h>
#include "rt_modd_snf.h"
#include "linspace_Q5Un26da.h"
#include <stddef.h>
#include <cstdlib>
#include "zero_crossing_types.h"
#include "ImmedMission_private.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Named constants for Chart: '<S1>/PreemptableMissionModeSelector'
    const uint8_T ImmedMission_IN_DetailedInsp
{
    1U
};
const uint8_T ImmedMission_IN_FlightMissionRH{ 2U };

const uint8_T ImmedMission_IN_Formation{ 3U };

const uint8_T ImmedMission_IN_ImmedMission{ 1U };

const uint8_T ImmedMission_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T ImmedMission_IN_SqCalibr{ 4U };

const uint8_T ImmedMission_IN_WaitToStart{ 2U };

const uint8_T ImmedMission_IN_pAttack{ 5U };

// Named constants for Chart: '<S23>/HdgHoldLogic'
const uint8_T ImmedMission_IN_OutOfRange{ 1U };

const uint8_T ImmedMission_IN_Turning{ 2U };

const uint8_T ImmedMission_IN_WithInRange{ 3U };

// Named constants for Chart: '<S57>/TriggerCalibrStart'
const uint8_T ImmedMission_IN_Running{ 1U };

const uint8_T ImmedMission_IN_Waiting{ 2U };

// Named constants for Chart: '<S147>/EnableSailShift'
const uint8_T ImmedMission_IN_NotShift{ 1U };

const uint8_T ImmedMission_IN_Shift{ 2U };

// Forward declaration for local functions
static real_T ImmedMission_norm(const real_T x[3]);

// Forward declaration for local functions
static void ImmedMission_emxInit_real_T(emxArray_real_T_ImmedMission_T
    **pEmxArray, int32_T numDimensions);
static void ImmedMission_emxFree_real_T(emxArray_real_T_ImmedMission_T
    **pEmxArray);
static real_T ImmedMission_norm_p(const real_T x[2]);
static void ImmedMission_emxInit_char_T(emxArray_char_T_ImmedMission_T
    **pEmxArray, int32_T numDimensions);
static int8_T ImmedMission_filedata(DW_ImmedMission_f_T *localDW);
static int8_T ImmedMission_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_ImmedMission_f_T *localDW);
static real_T ImmedMission_fileManager(DW_ImmedMission_f_T *localDW);
static void ImmedMission_emxEnsureCapacity_char_T(emxArray_char_T_ImmedMission_T
    *emxArray, int32_T oldNumel);
static void ImmedMission_fread(real_T fileID, emxArray_char_T_ImmedMission_T *A,
    DW_ImmedMission_f_T *localDW);
static void ImmedMission_emxFree_char_T(emxArray_char_T_ImmedMission_T
    **pEmxArray);
static boolean_T ImmedMission_copydigits(emxArray_char_T_ImmedMission_T *s1,
    int32_T *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T allowpoint);
static void ImmedMission_readfloat(emxArray_char_T_ImmedMission_T *s1, int32_T
    *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
    boolean_T *foundsign, boolean_T *success);
static creal_T ImmedMission_str2double(const emxArray_char_T_ImmedMission_T *s);
static int32_T ImmedMission_cfclose(real_T fid, DW_ImmedMission_f_T *localDW);
static void ImmedMission_strtok(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
    *remain);
static void ImmedMission_strtok_n(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token);
static void ImmedMission_strtrim(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *y);
static boolean_T ImmedMission_strcmp(const emxArray_char_T_ImmedMission_T *a);
static boolean_T ImmedMission_strcmp_h(const emxArray_char_T_ImmedMission_T *a);
static boolean_T ImmedMission_contains(const emxArray_char_T_ImmedMission_T *str);
static void ImmedMission_find_token(const emxArray_char_T_ImmedMission_T *x,
    int32_T *itoken, int32_T *iremain);
static void ImmedMission_strtok_nx(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
    *remain);
static void ImmedMission_strtok_nx2(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token);
static boolean_T ImmedMission_strcmp_ho(const emxArray_char_T_ImmedMission_T *a);
static void ImmedMission_readINI(emxArray_char_T_ImmedMission_T *ret,
    DW_ImmedMission_f_T *localDW);
static void ImmedMission_readINI_o(emxArray_char_T_ImmedMission_T *ret,
    DW_ImmedMission_f_T *localDW);
static boolean_T ImmedMission_strcmp_hoc(const emxArray_char_T_ImmedMission_T *a);
static uavDubinsConnection_ImmedMission_T
    *ImmedMission_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_ImmedMission_T *b_this, real_T varargin_2, real_T
     varargin_4);
static boolean_T ImmedMission_strcmp_hocj(const emxArray_char_T_ImmedMission_T
    *a);
static real_T ImmedMission_DubinsObjSingleton_getMinTurnRadius
    (DW_ImmedMission_f_T *localDW);
static void ImmedMission_emxEnsureCapacity_real_T(emxArray_real_T_ImmedMission_T
    *emxArray, int32_T oldNumel);
static void ImmedMission_binary_expand_op_pu(boolean_T in1_data[], int32_T
    in1_size[2], const emxArray_real_T_ImmedMission_T *in2, int32_T in3, int32_T
    in4);
static void ImmedMission_WaypointFollowerBase_getDistinctWpts(const
    emxArray_real_T_ImmedMission_T *waypoints, emxArray_real_T_ImmedMission_T
    *distinctWpts, DW_ImmedMission_f_T *localDW);
static void ImmedMission_circshift(emxArray_real_T_ImmedMission_T *a);
static real_T ImmedMission_norm_pv(const real_T x[3]);
static real_T ImmedMission_angdiff(real_T x, real_T y);
static void ImmedMission_binary_expand_op_p(emxArray_real_T_ImmedMission_T *in1,
    const emxArray_real_T_ImmedMission_T *in2, int32_T in3, int32_T in4);
static void ImmedMission_binary_expand_op(emxArray_real_T_ImmedMission_T *in1,
    const emxArray_real_T_ImmedMission_T *in2, const
    emxArray_real_T_ImmedMission_T *in3);
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
    // Start for MATLABSystem: '<S111>/Altitude'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S111>/Altitude'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 6; i++) {
        // InitializeConditions for MATLABSystem: '<S111>/Altitude'
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }
}

// System reset for atomic system:
void ImmedMission_Altitude_Reset(DW_Altitude_ImmedMission_T *localDW)
{
    // InitializeConditions for MATLABSystem: '<S111>/Altitude'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 6; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of InitializeConditions for MATLABSystem: '<S111>/Altitude'
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
    int32_T c_size_idx_0;
    int32_T i1;
    int32_T waypoints_size_idx_0;
    int8_T c_data[2];
    boolean_T x[6];
    boolean_T b[2];
    boolean_T exitg1;
    boolean_T p;
    boolean_T p_0;

    // MATLABSystem: '<S111>/Altitude'
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
    p = false;
    p_0 = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 6)) {
        if ((localDW->obj.WaypointsInternal[b_k] == rtu_1[b_k]) || (std::isnan
                (localDW->obj.WaypointsInternal[b_k]) && std::isnan(rtu_1[b_k])))
        {
            b_k = static_cast<int32_T>(b_k + 1);
        } else {
            p_0 = false;
            exitg1 = true;
        }
    }

    if (p_0) {
        p = true;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(p) ^ 1)))
    {
        for (b_k = 0; b_k < 6; b_k++) {
            localDW->obj.WaypointsInternal[b_k] = rtu_1[b_k];
        }

        localDW->obj.WaypointIndex = 1.0;
    }

    b_waypointsIn_data[0] = rtu_1[1];
    b_waypointsIn_data[2] = rtu_1[3];
    b_waypointsIn_data[4] = rtu_1[5];
    b_waypointsIn_data[1] = (rtNaN);
    b_waypointsIn_data[3] = (rtNaN);
    b_waypointsIn_data[5] = (rtNaN);
    for (b_k = 0; b_k < 6; b_k++) {
        x[b_k] = (rtu_1[b_k] != b_waypointsIn_data[b_k]);
    }

    b[0] = false;
    b[1] = false;
    b_k = 1;
    exitg1 = false;
    while ((!exitg1) && (b_k <= 5)) {
        if (x[static_cast<int32_T>(b_k - 1)]) {
            b[0] = true;
            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 2);
        }
    }

    b_k = 2;
    exitg1 = false;
    while ((!exitg1) && (b_k <= 6)) {
        if (x[static_cast<int32_T>(b_k - 1)]) {
            b[1] = true;
            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 2);
        }
    }

    i1 = 0;
    for (b_k = 0; b_k < 2; b_k++) {
        if (b[b_k]) {
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    c_size_idx_0 = i1;
    i1 = 0;
    for (b_k = 0; b_k < 2; b_k++) {
        if (b[b_k]) {
            c_data[i1] = static_cast<int8_T>(static_cast<int32_T>(b_k + 1));
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    for (b_k = 0; b_k < 3; b_k++) {
        for (i1 = 0; i1 <= static_cast<int32_T>(c_size_idx_0 - 1); i1++) {
            b_waypointsIn_data[static_cast<int32_T>(i1 + static_cast<int32_T>
                (c_size_idx_0 * b_k))] = rtu_1[static_cast<int32_T>(static_cast<
                int32_T>(static_cast<int32_T>(b_k << 1) + static_cast<int32_T>
                         (c_data[i1])) - 1)];
        }
    }

    localDW->obj.NumWaypoints = static_cast<real_T>(c_size_idx_0);
    localDW->obj.LookaheadDistance = lambda;
    if (c_size_idx_0 == 0) {
        // MATLABSystem: '<S111>/Altitude'
        localDW->Altitude_o1[0] = lambda * std::cos(rtu_0[3]) + rtu_0[0];
        localDW->Altitude_o1[1] = lambda * std::sin(rtu_0[3]) + rtu_0[1];
        localDW->Altitude_o1[2] = lambda * 0.0 + rtu_0[2];

        // MATLABSystem: '<S111>/Altitude'
        localDW->HeadingAngle = rtu_0[3];

        // MATLABSystem: '<S111>/Altitude'
        localDW->Altitude_o5 = 1U;
    } else {
        boolean_T guard1{ false };

        guard1 = false;
        if (c_size_idx_0 == 1) {
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
                // MATLABSystem: '<S111>/Altitude'
                localDW->Altitude_o1[0] = lambda * std::cos(rtu_0[3]) + rtu_0[0];
                localDW->Altitude_o1[1] = lambda * std::sin(rtu_0[3]) + rtu_0[1];
                localDW->Altitude_o1[2] = lambda * 0.0 + rtu_0[2];

                // MATLABSystem: '<S111>/Altitude'
                localDW->HeadingAngle = rtu_0[3];

                // MATLABSystem: '<S111>/Altitude'
                localDW->Altitude_o5 = 1U;
                localDW->obj.StartFlag = false;
            } else {
                localDW->obj.StartFlag = false;
                localDW->obj.NumWaypoints = 2.0;
                waypoints_size_idx_0 = static_cast<int32_T>(c_size_idx_0 + 1);
                for (b_k = 0; b_k < 3; b_k++) {
                    int32_T waypoints_data_tmp;
                    waypoints_data_tmp = static_cast<int32_T>
                        (static_cast<int32_T>(c_size_idx_0 + 1) * b_k);
                    waypoints_data[waypoints_data_tmp] =
                        localDW->obj.InitialPose[b_k];
                    for (i1 = 0; i1 <= static_cast<int32_T>(c_size_idx_0 - 1);
                            i1++) {
                        waypoints_data[static_cast<int32_T>(static_cast<int32_T>
                            (i1 + waypoints_data_tmp) + 1)] =
                            b_waypointsIn_data[static_cast<int32_T>(static_cast<
                            int32_T>(c_size_idx_0 * b_k) + i1)];
                    }
                }

                guard1 = true;
            }
        } else {
            waypoints_size_idx_0 = c_size_idx_0;
            i1 = static_cast<int32_T>(c_size_idx_0 * 3);
            for (b_k = 0; b_k <= static_cast<int32_T>(i1 - 1); b_k++) {
                waypoints_data[b_k] = b_waypointsIn_data[b_k];
            }

            guard1 = true;
        }

        if (guard1) {
            real_T b_0;
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
                r_idx_0 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0) - 1)];
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
                b_0 = ImmedMission_norm(b_waypointsIn);
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
                           / b_0) + (r_idx_1 - waypoints_tmp_0) / lambda *
                          (b_waypointsIn[1] / b_0)) + (r_idx_2 - rtu_0_tmp) /
                    lambda * (b_waypointsIn[2] / b_0);
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (lambda)) ^ 1))) {
                    if (lambda < 0.0) {
                        lambda = -1.0;
                    } else {
                        lambda = static_cast<real_T>(lambda > 0.0);
                    }
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
            b_0 = rtu_0[0] - b_waypointsIn[0];
            waypoints_tmp_0 = r_idx_1 - b_waypointsIn[1];
            rtu_0_tmp = rtu_0[1] - b_waypointsIn[1];
            waypoints_tmp_1 = r_idx_2 - b_waypointsIn[2];
            lambda_tmp = rtu_0[2] - b_waypointsIn[2];
            lambda = ((rtu_0_tmp * waypoints_tmp_0 + b_0 * waypoints_tmp) +
                      lambda_tmp * waypoints_tmp_1) / ((waypoints_tmp_0 *
                waypoints_tmp_0 + waypoints_tmp * waypoints_tmp) +
                waypoints_tmp_1 * waypoints_tmp_1);
            if (lambda < 0.0) {
                rtu_0_0[0] = b_0;
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
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isinf(lambda_tmp)) ^ 1))) &
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(std::isnan
                      (lambda_tmp)) ^ 1)))))) {
                if (lambda_tmp <= 2.2250738585072014E-308) {
                    b_0 = 4.94065645841247E-324;
                    lambda_tmp = 4.94065645841247E-324;
                } else {
                    frexp(lambda_tmp, &b_exponent);
                    b_0 = std::ldexp(1.0, static_cast<int32_T>(b_exponent - 53));
                    frexp(lambda_tmp, &b_exponent_0);
                    lambda_tmp = std::ldexp(1.0, static_cast<int32_T>
                                            (b_exponent_0 - 53));
                }
            } else {
                b_0 = (rtNaN);
                lambda_tmp = (rtNaN);
            }

            if (localDW->obj.LookaheadDistance <= std::fmax(std::sqrt(b_0), 5.0 *
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
            b_0 = ((waypoints_tmp * lambda + waypoints_tmp_0 * lambda_tmp) +
                   waypoints_tmp_1 * b_tmp_idx_2_tmp) * 2.0;
            lambda_tmp = std::sqrt(b_0 * b_0 - (((lambda * lambda + lambda_tmp *
                lambda_tmp) + b_tmp_idx_2_tmp * b_tmp_idx_2_tmp) -
                                    localDW->obj.LookaheadDistance *
                                    localDW->obj.LookaheadDistance) * (4.0 *
                                    rtu_0_tmp));
            lambda = std::fmax((-b_0 + lambda_tmp) / 2.0 / rtu_0_tmp, (-b_0 -
                                lambda_tmp) / 2.0 / rtu_0_tmp);
            rtu_0_tmp = (1.0 - lambda) * b_waypointsIn[0] + lambda * r_idx_0;

            // MATLABSystem: '<S111>/Altitude'
            localDW->Altitude_o1[0] = rtu_0_tmp;
            r_idx_0 = rtu_0_tmp;
            rtu_0_tmp = (1.0 - lambda) * b_waypointsIn[1] + lambda * r_idx_1;

            // MATLABSystem: '<S111>/Altitude'
            localDW->Altitude_o1[1] = rtu_0_tmp;
            localDW->Altitude_o1[2] = (1.0 - lambda) * b_waypointsIn[2] + lambda
                * r_idx_2;

            // MATLABSystem: '<S111>/Altitude'
            localDW->HeadingAngle = rt_atan2d_snf(rtu_0_tmp - rtu_0[1], r_idx_0
                - rtu_0[0]);

            // MATLABSystem: '<S111>/Altitude'
            localDW->Altitude_o5 = 0U;
            p = false;
            if (localDW->obj.LastWaypointFlag) {
                p = true;
            }

            if (p) {
                // MATLABSystem: '<S111>/Altitude'
                localDW->Altitude_o5 = 1U;
            }

            localDW->obj.LastWaypointFlag = false;
        }
    }

    // End of MATLABSystem: '<S111>/Altitude'
}

// System initialize for atomic system:
void ImmedMission_CoordinateTransformationConversion_Init
    (DW_CoordinateTransformationConversion_ImmedMission_T *localDW)
{
    // Start for MATLABSystem: '<S145>/Coordinate Transformation Conversion'
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
}

// Output and update for atomic system:
void ImmedMission_CoordinateTransformationConversion(const real_T rtu_0[3],
    DW_CoordinateTransformationConversion_ImmedMission_T *localDW)
{
    real_T out[9];
    real_T ct_idx_0;
    real_T ct_idx_1;
    real_T ct_idx_2;
    real_T out_tmp;
    real_T out_tmp_0;
    real_T st_idx_0;
    real_T st_idx_1;
    real_T st_idx_2;

    // MATLABSystem: '<S145>/Coordinate Transformation Conversion'
    ct_idx_0 = std::cos(rtu_0[0]);
    ct_idx_1 = std::cos(rtu_0[1]);
    ct_idx_2 = std::cos(rtu_0[2]);
    st_idx_0 = std::sin(rtu_0[0]);
    st_idx_1 = std::sin(rtu_0[1]);
    st_idx_2 = std::sin(rtu_0[2]);
    out[0] = ct_idx_0 * ct_idx_1;
    out_tmp = st_idx_1 * st_idx_2;
    out[3] = out_tmp * ct_idx_0 - st_idx_0 * ct_idx_2;
    out_tmp_0 = st_idx_1 * ct_idx_2;
    out[6] = out_tmp_0 * ct_idx_0 + st_idx_0 * st_idx_2;
    out[1] = st_idx_0 * ct_idx_1;
    out[4] = out_tmp * st_idx_0 + ct_idx_0 * ct_idx_2;
    out[7] = out_tmp_0 * st_idx_0 - ct_idx_0 * st_idx_2;
    out[2] = -st_idx_1;
    out[5] = ct_idx_1 * st_idx_2;
    out[8] = ct_idx_1 * ct_idx_2;

    // MATLABSystem: '<S145>/Coordinate Transformation Conversion'
    std::memcpy(&localDW->CoordinateTransformationConversion[0], &out[0],
                static_cast<uint32_T>(9U * sizeof(real_T)));
}

//
// Output and update for enable system:
//    '<S138>/DivisionByZeroProtection'
//    '<S14>/DivisionByZeroProtection'
//
void ImmedMission_DivisionByZeroProtection(real_T rtu_HorizSpd, real_T
    rtu_CentripetalAcc, real_T *rty_OmegaRad)
{
    // Outputs for Enabled SubSystem: '<S138>/DivisionByZeroProtection' incorporates:
    //   EnablePort: '<S140>/Enable'

    if (rtu_HorizSpd > 0.0) {
        // Product: '<S140>/Divide'
        *rty_OmegaRad = 1.0 / rtu_HorizSpd * rtu_CentripetalAcc;
    }

    // End of Outputs for SubSystem: '<S138>/DivisionByZeroProtection'
}

static void ImmedMission_emxInit_real_T(emxArray_real_T_ImmedMission_T
    **pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_ImmedMission_T *emxArray;
    *pEmxArray = static_cast<emxArray_real_T_ImmedMission_T *>(std::malloc
        (sizeof(emxArray_real_T_ImmedMission_T)));
    emxArray = *pEmxArray;
    emxArray->data = static_cast<real_T *>(nullptr);
    emxArray->numDimensions = numDimensions;
    emxArray->size = static_cast<int32_T *>(std::malloc(static_cast<uint32_T>
        (sizeof(int32_T) * static_cast<uint32_T>(numDimensions))));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (int32_T i{0}; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void ImmedMission_emxFree_real_T(emxArray_real_T_ImmedMission_T
    **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_real_T_ImmedMission_T *>(nullptr)) {
        if (((*pEmxArray)->data != static_cast<real_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_real_T_ImmedMission_T *>(nullptr);
    }
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static real_T ImmedMission_fileManager(DW_ImmedMission_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = ImmedMission_cfopen("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static void ImmedMission_fread(real_T fileID, emxArray_char_T_ImmedMission_T *A,
    DW_ImmedMission_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(std::round(fileID));
    if (fileID != static_cast<real_T>(fileid)) {
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
            int32_T c_0;
            int32_T i;
            int32_T numRead;
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
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            i = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(c_0 + A->
                size[0]) + 1);
            ImmedMission_emxEnsureCapacity_char_T(A, i);
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            for (i = 0; i <= c_0; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static void ImmedMission_readfloat(emxArray_char_T_ImmedMission_T *s1, int32_T
    *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
    boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
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

    emxArray_char_T_ImmedMission_T *d;
    int32_T b_idx;
    int32_T b_k;
    int32_T g_k;
    char_T c_idx_0;
    boolean_T a__3;
    boolean_T exitg1;
    boolean_T isneg;
    ImmedMission_emxInit_char_T(&d, 2);
    *isimag = false;
    *b_finite = true;
    *nfv = 0.0;
    b_idx = *idx;
    b_k = *k;
    isneg = false;
    *foundsign = false;
    exitg1 = false;
    while ((!exitg1) && (b_k <= n)) {
        c_idx_0 = s->data[static_cast<int32_T>(b_k - 1)];
        if (c_idx_0 == '-') {
            isneg = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(isneg) ^ 1));
            *foundsign = true;
            b_k = static_cast<int32_T>(b_k + 1);
        } else if (c_idx_0 == ',') {
            b_k = static_cast<int32_T>(b_k + 1);
        } else if (c_idx_0 == '+') {
            *foundsign = true;
            b_k = static_cast<int32_T>(b_k + 1);
        } else if (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(b[static_cast<int32_T>
                      (static_cast<int32_T>(static_cast<uint8_T>(c_idx_0)) & 127)])
                     ^ 1))) {
            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 1);
        }
    }

    *success = (b_k <= n);
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (*success) & static_cast<int32_T>(isneg)))) {
        if ((*idx >= 2) && (s1->data[static_cast<int32_T>(*idx - 2)] == '-')) {
            s1->data[static_cast<int32_T>(*idx - 2)] = ' ';
        } else {
            s1->data[static_cast<int32_T>(*idx - 1)] = '-';
            b_idx = static_cast<int32_T>(*idx + 1);
        }
    }

    *idx = b_idx;
    *k = b_k;
    if (*success) {
        char_T c_idx_1;
        char_T c_idx_2;
        isneg = false;
        if (b_k <= n) {
            c_idx_0 = s->data[static_cast<int32_T>(b_k - 1)];
            if (c_idx_0 == 'j') {
                isneg = true;
            } else if (c_idx_0 == 'i') {
                if (b_k >= static_cast<int32_T>(n - 1)) {
                    isneg = true;
                } else {
                    g_k = b_k;
                    c_idx_0 = '\x00';
                    while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)]
                                          == ',')) {
                        g_k = static_cast<int32_T>(g_k + 1);
                    }

                    if (g_k <= n) {
                        c_idx_0 = s->data[static_cast<int32_T>(g_k - 1)];
                    }

                    g_k = static_cast<int32_T>(g_k + 1);
                    c_idx_1 = '\x00';
                    while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)]
                                          == ',')) {
                        g_k = static_cast<int32_T>(g_k + 1);
                    }

                    if (g_k <= n) {
                        c_idx_1 = s->data[static_cast<int32_T>(g_k - 1)];
                    }

                    g_k = static_cast<int32_T>(g_k + 1);
                    c_idx_2 = '\x00';
                    while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)]
                                          == ',')) {
                        g_k = static_cast<int32_T>(g_k + 1);
                    }

                    if (g_k <= n) {
                        c_idx_2 = s->data[static_cast<int32_T>(g_k - 1)];
                    }

                    if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 ==
                            'N') || (c_idx_1 == 'n')) && ((c_idx_2 == 'F') ||
                            (c_idx_2 == 'f'))) {
                    } else if ((c_idx_0 == 'N') || (c_idx_0 == 'n')) {
                        if ((c_idx_1 == 'A') || (c_idx_1 == 'a')) {
                            if ((c_idx_2 != 'N') && (c_idx_2 != 'n')) {
                                isneg = true;
                            }
                        } else {
                            isneg = true;
                        }
                    } else {
                        isneg = true;
                    }
                }
            }
        }

        if (isneg) {
            if (allowimag) {
                *isimag = true;
                *k = static_cast<int32_T>(b_k + 1);
                exitg1 = false;
                while ((!exitg1) && (*k <= n)) {
                    if (b[static_cast<int32_T>(static_cast<int32_T>
                                               (static_cast<uint8_T>(s->data[
                            static_cast<int32_T>(*k - 1)])) & 127)]) {
                        *k = static_cast<int32_T>(*k + 1);
                    } else {
                        c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
                        if ((c_idx_0 == '\x00') || (c_idx_0 == ',')) {
                            *k = static_cast<int32_T>(*k + 1);
                        } else {
                            exitg1 = true;
                        }
                    }
                }

                if ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == '*'))
                {
                    *k = static_cast<int32_T>(*k + 1);
                    ImmedMission_readfloat(s1, idx, s, k, n, false, &isneg,
                                           b_finite, nfv, &a__3, success);
                } else {
                    s1->data[static_cast<int32_T>(b_idx - 1)] = '1';
                    *idx = static_cast<int32_T>(b_idx + 1);
                }
            } else {
                *success = false;
            }
        } else {
            g_k = b_k;
            c_idx_0 = '\x00';
            while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)] == ','))
            {
                g_k = static_cast<int32_T>(g_k + 1);
            }

            if (g_k <= n) {
                c_idx_0 = s->data[static_cast<int32_T>(g_k - 1)];
            }

            g_k = static_cast<int32_T>(g_k + 1);
            c_idx_1 = '\x00';
            while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)] == ','))
            {
                g_k = static_cast<int32_T>(g_k + 1);
            }

            if (g_k <= n) {
                c_idx_1 = s->data[static_cast<int32_T>(g_k - 1)];
            }

            g_k = static_cast<int32_T>(g_k + 1);
            c_idx_2 = '\x00';
            while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)] == ','))
            {
                g_k = static_cast<int32_T>(g_k + 1);
            }

            if (g_k <= n) {
                c_idx_2 = s->data[static_cast<int32_T>(g_k - 1)];
            }

            g_k = static_cast<int32_T>(g_k + 1);
            if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
                    (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f')))
            {
                *b_finite = false;
                *nfv = (rtInf);
            } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 ==
                         'A') || (c_idx_1 == 'a')) && ((c_idx_2 == 'N') ||
                        (c_idx_2 == 'n'))) {
                *b_finite = false;
                *nfv = (rtNaN);
            } else {
                g_k = b_k;
            }

            *k = g_k;
            if (*b_finite) {
                int32_T loop_ub;
                b_k = static_cast<int32_T>(d->size[0] * d->size[1]);
                d->size[0] = 1;
                d->size[1] = s1->size[1];
                ImmedMission_emxEnsureCapacity_char_T(d, b_k);
                loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                for (b_k = 0; b_k <= loop_ub; b_k++) {
                    d->data[b_k] = s1->data[b_k];
                }

                *success = ImmedMission_copydigits(d, &b_idx, s, &g_k, n, true);
                b_k = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                s1->size[0] = 1;
                s1->size[1] = d->size[1];
                ImmedMission_emxEnsureCapacity_char_T(s1, b_k);
                loop_ub = d->size[1];
                for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
                    s1->data[b_k] = d->data[b_k];
                }

                *idx = b_idx;
                *k = g_k;
                if ((*success) && (g_k <= n)) {
                    c_idx_0 = s->data[static_cast<int32_T>(g_k - 1)];
                    if ((c_idx_0 == 'E') || (c_idx_0 == 'e')) {
                        s1->data[static_cast<int32_T>(b_idx - 1)] = 'e';
                        *idx = static_cast<int32_T>(b_idx + 1);
                        while ((static_cast<int32_T>(g_k + 1) <= n) && (s->
                                data[g_k] == ',')) {
                            g_k = static_cast<int32_T>(g_k + 1);
                        }

                        if (static_cast<int32_T>(g_k + 1) <= n) {
                            if (s->data[g_k] == '-') {
                                s1->data[b_idx] = '-';
                                *idx = static_cast<int32_T>(b_idx + 2);
                                g_k = static_cast<int32_T>(g_k + 1);
                            } else if (s->data[g_k] == '+') {
                                g_k = static_cast<int32_T>(g_k + 1);
                            }
                        }

                        b_k = static_cast<int32_T>(d->size[0] * d->size[1]);
                        d->size[0] = 1;
                        d->size[1] = s1->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(d, b_k);
                        loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                        for (b_k = 0; b_k <= loop_ub; b_k++) {
                            d->data[b_k] = s1->data[b_k];
                        }

                        b_idx = static_cast<int32_T>(g_k + 1);
                        isneg = ImmedMission_copydigits(d, idx, s, &b_idx, n,
                            false);
                        b_k = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                        s1->size[0] = 1;
                        s1->size[1] = d->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(s1, b_k);
                        loop_ub = d->size[1];
                        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1);
                                b_k++) {
                            s1->data[b_k] = d->data[b_k];
                        }

                        *k = b_idx;
                        if (static_cast<boolean_T>(static_cast<int32_T>((b_idx <=
                               static_cast<int32_T>(g_k + 1)) |
                                static_cast<int32_T>(static_cast<boolean_T>(
                                static_cast<int32_T>(static_cast<int32_T>(isneg)
                                 ^ 1)))))) {
                            *success = false;
                        }
                    }
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
                    c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
                    if ((c_idx_0 == '\x00') || (c_idx_0 == ',')) {
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
                c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
                if ((c_idx_0 == 'i') || (c_idx_0 == 'j')) {
                    *k = static_cast<int32_T>(*k + 1);
                    *isimag = true;
                }
            }
        }

        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
            c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
            if (b[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                    (c_idx_0)) & 127)] || (c_idx_0 == '\x00') || (c_idx_0 == ','))
            {
                *k = static_cast<int32_T>(*k + 1);
            } else {
                exitg1 = true;
            }
        }
    }

    ImmedMission_emxFree_char_T(&d);
}

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

    emxArray_char_T_ImmedMission_T *d;
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
    ImmedMission_emxInit_char_T(&d, 2);
    x.re = (rtNaN);
    x.im = 0.0;
    if (s->size[1] >= 1) {
        int32_T i;
        int32_T loop_ub;
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

        i = static_cast<int32_T>(d->size[0] * d->size[1]);
        d->size[0] = 1;
        d->size[1] = static_cast<int32_T>(s->size[1] + 2);
        ImmedMission_emxEnsureCapacity_char_T(d, i);
        loop_ub = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub + 1); i++) {
            d->data[i] = '\x00';
        }

        idx = 1;
        ImmedMission_readfloat(d, &idx, s, &k, s->size[1], true, &isimag1,
                               &isfinite1, &scanned1, &a__1, &success);
        i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
        s1->size[0] = 1;
        s1->size[1] = d->size[1];
        ImmedMission_emxEnsureCapacity_char_T(s1, i);
        loop_ub = static_cast<int32_T>(d->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            s1->data[i] = d->data[i];
        }

        if (isfinite1) {
            ntoread = 1;
        }

        if (success) {
            if (k <= s->size[1]) {
                s1->data[static_cast<int32_T>(idx - 1)] = ' ';
                i = static_cast<int32_T>(d->size[0] * d->size[1]);
                d->size[0] = 1;
                d->size[1] = s1->size[1];
                ImmedMission_emxEnsureCapacity_char_T(d, i);
                loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                for (i = 0; i <= loop_ub; i++) {
                    d->data[i] = s1->data[i];
                }

                idx = static_cast<int32_T>(idx + 1);
                ImmedMission_readfloat(d, &idx, s, &k, s->size[1], true, &a__1,
                                       &success, &scanned2, &foundsign,
                                       &c_success);
                i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                s1->size[0] = 1;
                s1->size[1] = d->size[1];
                ImmedMission_emxEnsureCapacity_char_T(s1, i);
                loop_ub = static_cast<int32_T>(d->size[1] - 1);
                for (i = 0; i <= loop_ub; i++) {
                    s1->data[i] = d->data[i];
                }

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

    ImmedMission_emxFree_char_T(&d);
    return x;
}

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static int32_T ImmedMission_cfclose(real_T fid, DW_ImmedMission_f_T *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(std::round(fid));
    if (fid != static_cast<real_T>(fileid)) {
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static void ImmedMission_strtok_n(const emxArray_char_T_ImmedMission_T *x,
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

    static const char_T d[3]{ 'U', 'A', 'V' };

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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static boolean_T ImmedMission_strcmp_h(const emxArray_char_T_ImmedMission_T *a)
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

    static const char_T d[10]{ 'N', 'o', 'r', 'm', 'A', 'i', 'r', 'S', 'p', 'd'
    };

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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 10) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 10) {
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static void ImmedMission_strtok_nx(const emxArray_char_T_ImmedMission_T *x,
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static void ImmedMission_strtok_nx2(const emxArray_char_T_ImmedMission_T *x,
    emxArray_char_T_ImmedMission_T *token)
{
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    ImmedMission_find_token(x, &itoken, &iremain);
    if (itoken > static_cast<int32_T>(iremain - 1)) {
        itoken = 0;
        iremain = 0;
    } else {
        itoken = static_cast<int32_T>(itoken - 1);
        iremain = static_cast<int32_T>(iremain - 1);
    }

    i = static_cast<int32_T>(token->size[0] * token->size[1]);
    token->size[0] = 1;
    iremain = static_cast<int32_T>(iremain - itoken);
    token->size[1] = iremain;
    ImmedMission_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(iremain - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static boolean_T ImmedMission_strcmp_ho(const emxArray_char_T_ImmedMission_T *a)
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

    static const char_T d[9]{ 'M', 'a', 'x', 'A', 'i', 'r', 'S', 'p', 'd' };

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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static void ImmedMission_readINI(emxArray_char_T_ImmedMission_T *ret,
    DW_ImmedMission_f_T *localDW)
{
    static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T i[15]{ 'C', 'l', 'i', 'm', 'b', 'A', 'n', 'g', 'l', 'e',
        'L', 'i', 'm', 'i', 't' };

    emxArray_char_T_ImmedMission_T *aTmp;
    emxArray_char_T_ImmedMission_T *curKey;
    emxArray_char_T_ImmedMission_T *curLine;
    emxArray_char_T_ImmedMission_T *curSection;
    emxArray_char_T_ImmedMission_T *curVal;
    emxArray_char_T_ImmedMission_T *data;
    emxArray_char_T_ImmedMission_T *data_0;
    emxArray_char_T_ImmedMission_T *j;
    emxArray_char_T_ImmedMission_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = ImmedMission_cfopen("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        ImmedMission_emxInit_char_T(&data, 2);
        ImmedMission_emxInit_char_T(&j, 1);
        ImmedMission_fread(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        ImmedMission_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        ImmedMission_emxFree_char_T(&j);
        ImmedMission_emxInit_char_T(&curSection, 2);
        ImmedMission_emxInit_char_T(&curKey, 2);
        ImmedMission_emxInit_char_T(&curVal, 2);
        ImmedMission_cfclose(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        ImmedMission_emxInit_char_T(&curLine, 2);
        ImmedMission_emxInit_char_T(&aTmp, 2);
        ImmedMission_emxInit_char_T(&tmp, 2);
        ImmedMission_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                ImmedMission_strtok(data_0, curLine, data);
                ImmedMission_strtok_n(curLine, tmp);
                ImmedMission_strtrim(tmp, curLine);
                if (curLine->size[1] >= 2) {
                    boolean_T guard1{ false };

                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                iremain = 0;
                                itoken = 0;
                            } else {
                                iremain = 1;
                                itoken = static_cast<int32_T>(curLine->size[1] -
                                    1);
                            }

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curSection->data[itoken_0] = curLine->data[
                                    static_cast<int32_T>(iremain + itoken_0)];
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
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                ImmedMission_contains(curLine)) {
                            ImmedMission_strtok_nx(curLine, aTmp, curVal);
                            ImmedMission_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            ImmedMission_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            ImmedMission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (ImmedMission_strcmp(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(aTmp, itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 15) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 15) {
                                if (h[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(aTmp->data[iremain]))
                                     & 127)] != h[static_cast<int32_T>(i[iremain])])
                                {
                                    exitg2 = 1;
                                } else {
                                    iremain = static_cast<int32_T>(iremain + 1);
                                }
                            } else {
                                b_bool = true;
                                exitg2 = 1;
                            }
                        } while (exitg2 == 0);
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(ret, itoken_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            ret->data[itoken_0] = curVal->data[itoken_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        ImmedMission_emxFree_char_T(&data_0);
        ImmedMission_emxFree_char_T(&tmp);
        ImmedMission_emxFree_char_T(&aTmp);
        ImmedMission_emxFree_char_T(&curLine);
        ImmedMission_emxFree_char_T(&curVal);
        ImmedMission_emxFree_char_T(&curKey);
        ImmedMission_emxFree_char_T(&curSection);
        ImmedMission_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static void ImmedMission_readINI_o(emxArray_char_T_ImmedMission_T *ret,
    DW_ImmedMission_f_T *localDW)
{
    static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T i[14]{ 'D', 'i', 'v', 'e', 'A', 'n', 'g', 'l', 'e', 'L',
        'i', 'm', 'i', 't' };

    emxArray_char_T_ImmedMission_T *aTmp;
    emxArray_char_T_ImmedMission_T *curKey;
    emxArray_char_T_ImmedMission_T *curLine;
    emxArray_char_T_ImmedMission_T *curSection;
    emxArray_char_T_ImmedMission_T *curVal;
    emxArray_char_T_ImmedMission_T *data;
    emxArray_char_T_ImmedMission_T *data_0;
    emxArray_char_T_ImmedMission_T *j;
    emxArray_char_T_ImmedMission_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = ImmedMission_cfopen("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        ImmedMission_emxInit_char_T(&data, 2);
        ImmedMission_emxInit_char_T(&j, 1);
        ImmedMission_fread(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        ImmedMission_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        ImmedMission_emxFree_char_T(&j);
        ImmedMission_emxInit_char_T(&curSection, 2);
        ImmedMission_emxInit_char_T(&curKey, 2);
        ImmedMission_emxInit_char_T(&curVal, 2);
        ImmedMission_cfclose(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        ImmedMission_emxInit_char_T(&curLine, 2);
        ImmedMission_emxInit_char_T(&aTmp, 2);
        ImmedMission_emxInit_char_T(&tmp, 2);
        ImmedMission_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                ImmedMission_strtok(data_0, curLine, data);
                ImmedMission_strtok_n(curLine, tmp);
                ImmedMission_strtrim(tmp, curLine);
                if (curLine->size[1] >= 2) {
                    boolean_T guard1{ false };

                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                iremain = 0;
                                itoken = 0;
                            } else {
                                iremain = 1;
                                itoken = static_cast<int32_T>(curLine->size[1] -
                                    1);
                            }

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curSection->data[itoken_0] = curLine->data[
                                    static_cast<int32_T>(iremain + itoken_0)];
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
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                ImmedMission_contains(curLine)) {
                            ImmedMission_strtok_nx(curLine, aTmp, curVal);
                            ImmedMission_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            ImmedMission_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            ImmedMission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (ImmedMission_strcmp(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(aTmp, itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 14) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 14) {
                                if (h[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(aTmp->data[iremain]))
                                     & 127)] != h[static_cast<int32_T>(i[iremain])])
                                {
                                    exitg2 = 1;
                                } else {
                                    iremain = static_cast<int32_T>(iremain + 1);
                                }
                            } else {
                                b_bool = true;
                                exitg2 = 1;
                            }
                        } while (exitg2 == 0);
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        ImmedMission_emxEnsureCapacity_char_T(ret, itoken_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            ret->data[itoken_0] = curVal->data[itoken_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        ImmedMission_emxFree_char_T(&data_0);
        ImmedMission_emxFree_char_T(&tmp);
        ImmedMission_emxFree_char_T(&aTmp);
        ImmedMission_emxFree_char_T(&curLine);
        ImmedMission_emxFree_char_T(&curVal);
        ImmedMission_emxFree_char_T(&curKey);
        ImmedMission_emxFree_char_T(&curSection);
        ImmedMission_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static boolean_T ImmedMission_strcmp_hoc(const emxArray_char_T_ImmedMission_T *a)
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

    static const char_T d[9]{ 'M', 'i', 'n', 'A', 'i', 'r', 'S', 'p', 'd' };

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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static uavDubinsConnection_ImmedMission_T
    *ImmedMission_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_ImmedMission_T *b_this, real_T varargin_2, real_T
     varargin_4)
{
    uavDubinsConnection_ImmedMission_T *c_this;
    real_T b_x;
    c_this = b_this;
    b_this->AirSpeed = 10.0;
    b_this->MaxRollAngle = varargin_4;
    b_x = b_this->MaxRollAngle;
    b_this->MinTurningRadius = b_this->AirSpeed * b_this->AirSpeed / (9.8 * std::
        tan(b_x));
    b_this->AirSpeed = varargin_2;
    b_x = b_this->MaxRollAngle;
    b_this->MinTurningRadius = b_this->AirSpeed * b_this->AirSpeed / (9.8 * std::
        tan(b_x));
    b_x = b_this->MaxRollAngle;
    b_this->MinTurningRadius = b_this->AirSpeed * b_this->AirSpeed / (9.8 * std::
        tan(b_x));
    return c_this;
}

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static boolean_T ImmedMission_strcmp_hocj(const emxArray_char_T_ImmedMission_T
    *a)
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

    static const char_T d[12]{ 'M', 'a', 'x', 'R', 'o', 'l', 'l', 'A', 'n', 'g',
        'l', 'e' };

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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 12) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 12) {
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

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static real_T ImmedMission_DubinsObjSingleton_getMinTurnRadius
    (DW_ImmedMission_f_T *localDW)
{
    emxArray_char_T_ImmedMission_T *b_remainder;
    emxArray_char_T_ImmedMission_T *curKey;
    emxArray_char_T_ImmedMission_T *curLine;
    emxArray_char_T_ImmedMission_T *curSection;
    emxArray_char_T_ImmedMission_T *curVal;
    emxArray_char_T_ImmedMission_T *data;
    emxArray_char_T_ImmedMission_T *data_0;
    emxArray_char_T_ImmedMission_T *data_1;
    emxArray_char_T_ImmedMission_T *data_2;
    emxArray_char_T_ImmedMission_T *data_3;
    emxArray_char_T_ImmedMission_T *k;
    emxArray_char_T_ImmedMission_T *ret;
    emxArray_char_T_ImmedMission_T *tmp_1;
    emxArray_char_T_ImmedMission_T *tmp_2;
    emxArray_char_T_ImmedMission_T *tmp_3;
    emxArray_char_T_ImmedMission_T *tmp_4;
    emxArray_char_T_ImmedMission_T *tmp_5;
    emxArray_char_T_ImmedMission_T *tmp_6;
    emxArray_char_T_ImmedMission_T *tmp_7;
    emxArray_char_T_ImmedMission_T *tmp_8;
    real_T outputArg;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (localDW->SingletonInstance_not_empty) ^ 1))) {
        creal_T tmp;
        creal_T tmp_0;
        real_T ClimbAngleLimit;
        real_T DiveAngleLimit;
        real_T fid;
        int32_T c;
        int32_T c_0;
        int32_T loop_ub;
        boolean_T b_bool;
        boolean_T exitg1;
        boolean_T guard1{ false };

        ImmedMission_emxInit_char_T(&ret, 2);
        localDW->SingletonInstance.AirSpeed = 35.0;
        localDW->SingletonInstance.MaxRollAngle = 0.3490658503988659;
        localDW->SingletonInstance.FlightPathAngleLimit[0] = -0.175;
        localDW->SingletonInstance.FlightPathAngleLimit[1] = 0.175;
        ret->size[0] = 1;
        ret->size[1] = 0;
        fid = ImmedMission_fileManager(localDW);
        ImmedMission_emxInit_char_T(&data, 2);
        ImmedMission_emxInit_char_T(&curSection, 2);
        ImmedMission_emxInit_char_T(&curKey, 2);
        ImmedMission_emxInit_char_T(&curVal, 2);
        ImmedMission_emxInit_char_T(&curLine, 2);
        ImmedMission_emxInit_char_T(&b_remainder, 2);
        ImmedMission_emxInit_char_T(&k, 1);
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(fid, k, localDW);
            c_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, c_0);
            loop_ub = k->size[0];
            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub - 1); c_0++) {
                data->data[c_0] = k->data[c_0];
            }

            ImmedMission_cfclose(fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            ImmedMission_emxInit_char_T(&tmp_7, 2);
            ImmedMission_emxInit_char_T(&tmp_8, 2);
            ImmedMission_emxInit_char_T(&data_3, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                c_0 = static_cast<int32_T>(data_3->size[0] * data_3->size[1]);
                data_3->size[0] = 1;
                data_3->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_3, c_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                    data_3->data[c_0] = data->data[c_0];
                }

                ImmedMission_strtok(data_3, curLine, data);
                ImmedMission_strtok_n(curLine, tmp_8);
                ImmedMission_strtrim(tmp_8, curLine);
                if (curLine->size[1] >= 2) {
                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                loop_ub = 0;
                            } else {
                                c = 1;
                                loop_ub = static_cast<int32_T>(curLine->size[1]
                                    - 1);
                            }

                            c_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(loop_ub - c);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                c_0);
                            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub -
                                    1); c_0++) {
                                curSection->data[c_0] = curLine->data[
                                    static_cast<int32_T>(c + c_0)];
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
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                ImmedMission_contains(curLine)) {
                            ImmedMission_strtok_nx(curLine, curVal, b_remainder);
                            ImmedMission_strtrim(curVal, curKey);
                            ImmedMission_strtok_nx2(b_remainder, tmp_7);
                            ImmedMission_strtrim(tmp_7, curVal);
                        }
                    }
                }

                if (ImmedMission_strcmp(curSection) && ImmedMission_strcmp_h
                        (curKey)) {
                    c_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    ImmedMission_emxEnsureCapacity_char_T(ret, c_0);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                        ret->data[c_0] = curVal->data[c_0];
                    }

                    exitg1 = true;
                }
            }

            ImmedMission_emxFree_char_T(&data_3);
            ImmedMission_emxFree_char_T(&tmp_8);
            ImmedMission_emxFree_char_T(&tmp_7);
        }

        tmp = ImmedMission_str2double(ret);
        printf("Set UAV NormAirSpeed:\t\t%f\n", tmp.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        fid = ImmedMission_fileManager(localDW);
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(fid, k, localDW);
            c_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, c_0);
            loop_ub = k->size[0];
            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub - 1); c_0++) {
                data->data[c_0] = k->data[c_0];
            }

            ImmedMission_cfclose(fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            ImmedMission_emxInit_char_T(&tmp_5, 2);
            ImmedMission_emxInit_char_T(&tmp_6, 2);
            ImmedMission_emxInit_char_T(&data_2, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                c_0 = static_cast<int32_T>(data_2->size[0] * data_2->size[1]);
                data_2->size[0] = 1;
                data_2->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_2, c_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                    data_2->data[c_0] = data->data[c_0];
                }

                ImmedMission_strtok(data_2, curLine, data);
                ImmedMission_strtok_n(curLine, tmp_6);
                ImmedMission_strtrim(tmp_6, curLine);
                if (curLine->size[1] >= 2) {
                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                loop_ub = 0;
                            } else {
                                c = 1;
                                loop_ub = static_cast<int32_T>(curLine->size[1]
                                    - 1);
                            }

                            c_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(loop_ub - c);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                c_0);
                            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub -
                                    1); c_0++) {
                                curSection->data[c_0] = curLine->data[
                                    static_cast<int32_T>(c + c_0)];
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
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                ImmedMission_contains(curLine)) {
                            ImmedMission_strtok_nx(curLine, curVal, b_remainder);
                            ImmedMission_strtrim(curVal, curKey);
                            ImmedMission_strtok_nx2(b_remainder, tmp_5);
                            ImmedMission_strtrim(tmp_5, curVal);
                        }
                    }
                }

                if (ImmedMission_strcmp(curSection) && ImmedMission_strcmp_ho
                        (curKey)) {
                    c_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    ImmedMission_emxEnsureCapacity_char_T(ret, c_0);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                        ret->data[c_0] = curVal->data[c_0];
                    }

                    exitg1 = true;
                }
            }

            ImmedMission_emxFree_char_T(&data_2);
            ImmedMission_emxFree_char_T(&tmp_6);
            ImmedMission_emxFree_char_T(&tmp_5);
        }

        tmp_0 = ImmedMission_str2double(ret);
        printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_0.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        fid = ImmedMission_fileManager(localDW);
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(fid, k, localDW);
            c_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, c_0);
            loop_ub = k->size[0];
            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub - 1); c_0++) {
                data->data[c_0] = k->data[c_0];
            }

            ImmedMission_cfclose(fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            ImmedMission_emxInit_char_T(&tmp_3, 2);
            ImmedMission_emxInit_char_T(&tmp_4, 2);
            ImmedMission_emxInit_char_T(&data_1, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                c_0 = static_cast<int32_T>(data_1->size[0] * data_1->size[1]);
                data_1->size[0] = 1;
                data_1->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_1, c_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                    data_1->data[c_0] = data->data[c_0];
                }

                ImmedMission_strtok(data_1, curLine, data);
                ImmedMission_strtok_n(curLine, tmp_4);
                ImmedMission_strtrim(tmp_4, curLine);
                if (curLine->size[1] >= 2) {
                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                loop_ub = 0;
                            } else {
                                c = 1;
                                loop_ub = static_cast<int32_T>(curLine->size[1]
                                    - 1);
                            }

                            c_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(loop_ub - c);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                c_0);
                            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub -
                                    1); c_0++) {
                                curSection->data[c_0] = curLine->data[
                                    static_cast<int32_T>(c + c_0)];
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
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                ImmedMission_contains(curLine)) {
                            ImmedMission_strtok_nx(curLine, curVal, b_remainder);
                            ImmedMission_strtrim(curVal, curKey);
                            ImmedMission_strtok_nx2(b_remainder, tmp_3);
                            ImmedMission_strtrim(tmp_3, curVal);
                        }
                    }
                }

                if (ImmedMission_strcmp(curSection) && ImmedMission_strcmp_hoc
                        (curKey)) {
                    c_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    ImmedMission_emxEnsureCapacity_char_T(ret, c_0);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                        ret->data[c_0] = curVal->data[c_0];
                    }

                    exitg1 = true;
                }
            }

            ImmedMission_emxFree_char_T(&data_1);
            ImmedMission_emxFree_char_T(&tmp_4);
            ImmedMission_emxFree_char_T(&tmp_3);
        }

        tmp_0 = ImmedMission_str2double(ret);
        printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_0.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        fid = ImmedMission_fileManager(localDW);
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(fid, k, localDW);
            c_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, c_0);
            loop_ub = k->size[0];
            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub - 1); c_0++) {
                data->data[c_0] = k->data[c_0];
            }

            ImmedMission_cfclose(fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            ImmedMission_emxInit_char_T(&tmp_1, 2);
            ImmedMission_emxInit_char_T(&tmp_2, 2);
            ImmedMission_emxInit_char_T(&data_0, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                c_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_0, c_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                    data_0->data[c_0] = data->data[c_0];
                }

                ImmedMission_strtok(data_0, curLine, data);
                ImmedMission_strtok_n(curLine, tmp_2);
                ImmedMission_strtrim(tmp_2, curLine);
                if (curLine->size[1] >= 2) {
                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                loop_ub = 0;
                            } else {
                                c = 1;
                                loop_ub = static_cast<int32_T>(curLine->size[1]
                                    - 1);
                            }

                            c_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(loop_ub - c);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                c_0);
                            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub -
                                    1); c_0++) {
                                curSection->data[c_0] = curLine->data[
                                    static_cast<int32_T>(c + c_0)];
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
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                ImmedMission_contains(curLine)) {
                            ImmedMission_strtok_nx(curLine, curVal, b_remainder);
                            ImmedMission_strtrim(curVal, curKey);
                            ImmedMission_strtok_nx2(b_remainder, tmp_1);
                            ImmedMission_strtrim(tmp_1, curVal);
                        }
                    }
                }

                if (ImmedMission_strcmp(curSection) && ImmedMission_strcmp_hocj
                        (curKey)) {
                    c_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    ImmedMission_emxEnsureCapacity_char_T(ret, c_0);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                        ret->data[c_0] = curVal->data[c_0];
                    }

                    exitg1 = true;
                }
            }

            ImmedMission_emxFree_char_T(&data_0);
            ImmedMission_emxFree_char_T(&tmp_2);
            ImmedMission_emxFree_char_T(&tmp_1);
        }

        ImmedMission_emxFree_char_T(&k);
        ImmedMission_emxFree_char_T(&b_remainder);
        ImmedMission_emxFree_char_T(&curLine);
        ImmedMission_emxFree_char_T(&curVal);
        ImmedMission_emxFree_char_T(&curKey);
        ImmedMission_emxFree_char_T(&curSection);
        ImmedMission_emxFree_char_T(&data);
        tmp_0 = ImmedMission_str2double(ret);
        fid = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV MaxRollAngle:\t\t%f\n", fid);
        fflush(stdout);
        ImmedMission_readINI(ret, localDW);
        tmp_0 = ImmedMission_str2double(ret);
        ClimbAngleLimit = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV ClimbAngleLimit:\t%f\n", ClimbAngleLimit);
        fflush(stdout);
        ImmedMission_readINI_o(ret, localDW);
        tmp_0 = ImmedMission_str2double(ret);
        DiveAngleLimit = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV DiveAngleLimit:\t\t%f\n", DiveAngleLimit);
        fflush(stdout);
        ImmedMission_emxFree_char_T(&ret);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(tmp.re)) ^ 1))) {
            localDW->SingletonInstance.AirSpeed = tmp.re;
        }

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(fid)) ^ 1))) {
            localDW->SingletonInstance.MaxRollAngle = fid;
        }

        if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (std::isnan(ClimbAngleLimit)) ^ 1))) && (static_cast<boolean_T>(
                static_cast<int32_T>(static_cast<int32_T>(std::isnan
                (DiveAngleLimit)) ^ 1)))) {
            localDW->SingletonInstance.FlightPathAngleLimit[0] = DiveAngleLimit;
            localDW->SingletonInstance.FlightPathAngleLimit[1] = ClimbAngleLimit;
        }

        ImmedMission_uavDubinsConnection_uavDubinsConnection
            (&localDW->SingletonInstance.Connector,
             localDW->SingletonInstance.AirSpeed,
             localDW->SingletonInstance.MaxRollAngle);
        localDW->SingletonInstance_not_empty = true;
    }

    outputArg = localDW->SingletonInstance.Connector.MinTurningRadius;
    return outputArg;
}

static void ImmedMission_emxEnsureCapacity_real_T(emxArray_real_T_ImmedMission_T
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

        newData = std::calloc(static_cast<uint32_T>(i), sizeof(real_T));
        if (emxArray->data != nullptr) {
            std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
                         (real_T) * static_cast<uint32_T>(oldNumel)));
            if (emxArray->canFreeData) {
                std::free(emxArray->data);
            }
        }

        emxArray->data = static_cast<real_T *>(newData);
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

static void ImmedMission_binary_expand_op_pu(boolean_T in1_data[], int32_T
    in1_size[2], const emxArray_real_T_ImmedMission_T *in2, int32_T in3, int32_T
    in4)
{
    emxArray_real_T_ImmedMission_T *in2_0;
    int32_T i;
    int32_T i_0;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    int32_T stride_0_0;
    ImmedMission_emxInit_real_T(&in2_0, 2);
    i = static_cast<int32_T>(in4 - in3);
    i_0 = static_cast<int32_T>(in2_0->size[0] * in2_0->size[1]);
    in2_0->size[0] = static_cast<int32_T>(i + 2);
    in2_0->size[1] = 3;
    ImmedMission_emxEnsureCapacity_real_T(in2_0, i_0);
    loop_ub_tmp = static_cast<int32_T>(i + 1);
    for (i_0 = 0; i_0 < 3; i_0++) {
        for (stride_0_0 = 0; stride_0_0 <= static_cast<int32_T>(loop_ub_tmp - 1);
             stride_0_0++) {
            in2_0->data[static_cast<int32_T>(stride_0_0 + static_cast<int32_T>
                (in2_0->size[0] * i_0))] = in2->data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(in3 + stride_0_0) +
                static_cast<int32_T>(in2->size[0] * i_0)) - 1)];
        }
    }

    in2_0->data[static_cast<int32_T>(i + 1)] = (rtNaN);
    in2_0->data[static_cast<int32_T>(static_cast<int32_T>(i + in2_0->size[0]) +
        1)] = (rtNaN);
    in2_0->data[static_cast<int32_T>(static_cast<int32_T>(i +
        static_cast<int32_T>(in2_0->size[0] << 1)) + 1)] = (rtNaN);
    in1_size[0] = in2_0->size[0] == 1 ? in2->size[0] : in2_0->size[0];
    in1_size[1] = 3;
    stride_0_0 = (in2->size[0] != 1);
    loop_ub_tmp = (in2_0->size[0] != 1);
    loop_ub = in2_0->size[0] == 1 ? in2->size[0] : in2_0->size[0];
    for (i = 0; i < 3; i++) {
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            in1_data[static_cast<int32_T>(i_0 + static_cast<int32_T>(in1_size[0]
                * i))] = (in2->data[static_cast<int32_T>(static_cast<int32_T>
                           (i_0 * stride_0_0) + static_cast<int32_T>(in2->size[0]
                            * i))] != in2_0->data[static_cast<int32_T>(
                           static_cast<int32_T>(i_0 * loop_ub_tmp) +
                           static_cast<int32_T>(in2_0->size[0] * i))]);
        }
    }

    ImmedMission_emxFree_real_T(&in2_0);
}

static void ImmedMission_WaypointFollowerBase_getDistinctWpts(const
    emxArray_real_T_ImmedMission_T *waypoints, emxArray_real_T_ImmedMission_T
    *distinctWpts, DW_ImmedMission_f_T *localDW)
{
    emxArray_real_T_ImmedMission_T *waypoints_0;
    int32_T x_size[2];
    if (static_cast<boolean_T>(static_cast<int32_T>((waypoints->size[0] == 0) |
            (waypoints->size[1] == 0)))) {
        distinctWpts->size[0] = 0;
        distinctWpts->size[1] = 0;
    } else {
        int32_T i1;
        int32_T i2;
        int32_T ix;
        int32_T outsize_idx_0;
        int32_T vstride;
        if (waypoints->size[0] < 2) {
            outsize_idx_0 = 0;
            vstride = -1;
        } else {
            outsize_idx_0 = 1;
            vstride = static_cast<int32_T>(waypoints->size[0] - 1);
        }

        i1 = static_cast<int32_T>(vstride - outsize_idx_0);
        if (static_cast<int32_T>(i1 + 2) == waypoints->size[0]) {
            ImmedMission_emxInit_real_T(&waypoints_0, 2);
            vstride = static_cast<int32_T>(waypoints_0->size[0] *
                waypoints_0->size[1]);
            waypoints_0->size[0] = static_cast<int32_T>(i1 + 2);
            waypoints_0->size[1] = 3;
            ImmedMission_emxEnsureCapacity_real_T(waypoints_0, vstride);
            i2 = static_cast<int32_T>(i1 + 1);
            for (vstride = 0; vstride < 3; vstride++) {
                for (ix = 0; ix <= static_cast<int32_T>(i2 - 1); ix++) {
                    waypoints_0->data[static_cast<int32_T>(ix +
                        static_cast<int32_T>(waypoints_0->size[0] * vstride))] =
                        waypoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (outsize_idx_0 + ix) + static_cast<int32_T>
                        (waypoints->size[0] * vstride))];
                }
            }

            waypoints_0->data[static_cast<int32_T>(i1 + 1)] = (rtNaN);
            waypoints_0->data[static_cast<int32_T>(static_cast<int32_T>(i1 +
                waypoints_0->size[0]) + 1)] = (rtNaN);
            waypoints_0->data[static_cast<int32_T>(static_cast<int32_T>(i1 +
                static_cast<int32_T>(waypoints_0->size[0] << 1)) + 1)] = (rtNaN);
            outsize_idx_0 = waypoints->size[0];
            x_size[0] = waypoints->size[0];
            for (i1 = 0; i1 < 3; i1++) {
                for (vstride = 0; vstride <= static_cast<int32_T>(outsize_idx_0
                        - 1); vstride++) {
                    localDW->x_data[static_cast<int32_T>(vstride +
                        static_cast<int32_T>(x_size[0] * i1))] =
                        (waypoints->data[static_cast<int32_T>
                         (static_cast<int32_T>(waypoints->size[0] * i1) +
                          vstride)] != waypoints_0->data[static_cast<int32_T>(
                          static_cast<int32_T>(waypoints_0->size[0] * i1) +
                          vstride)]);
                }
            }

            ImmedMission_emxFree_real_T(&waypoints_0);
        } else {
            ImmedMission_binary_expand_op_pu(localDW->x_data, x_size, waypoints,
                static_cast<int32_T>(outsize_idx_0 + 1), static_cast<int32_T>
                (vstride + 1));
        }

        outsize_idx_0 = x_size[0];
        for (i1 = 0; i1 <= static_cast<int32_T>(outsize_idx_0 - 1); i1++) {
            localDW->i_data[i1] = false;
        }

        vstride = x_size[0];
        i1 = 0;
        i2 = static_cast<int32_T>(x_size[0] << 1);
        for (outsize_idx_0 = 0; outsize_idx_0 <= static_cast<int32_T>(vstride -
                1); outsize_idx_0++) {
            boolean_T exitg1;
            i1 = static_cast<int32_T>(i1 + 1);
            i2 = static_cast<int32_T>(i2 + 1);
            ix = i1;
            exitg1 = false;
            while ((!exitg1) && (static_cast<boolean_T>(static_cast<int32_T>
                     ((vstride > 0) & (ix <= i2))))) {
                if (localDW->x_data[static_cast<int32_T>(ix - 1)]) {
                    localDW->i_data[outsize_idx_0] = true;
                    exitg1 = true;
                } else {
                    ix = static_cast<int32_T>(ix + vstride);
                }
            }
        }

        outsize_idx_0 = static_cast<int32_T>(x_size[0] - 1);
        i1 = 0;
        for (vstride = 0; vstride <= outsize_idx_0; vstride++) {
            if (localDW->i_data[vstride]) {
                i1 = static_cast<int32_T>(i1 + 1);
            }
        }

        ix = i1;
        i1 = 0;
        for (vstride = 0; vstride <= outsize_idx_0; vstride++) {
            if (localDW->i_data[vstride]) {
                localDW->j_data[i1] = static_cast<int16_T>(static_cast<int32_T>
                    (vstride + 1));
                i1 = static_cast<int32_T>(i1 + 1);
            }
        }

        outsize_idx_0 = waypoints->size[1];
        vstride = static_cast<int32_T>(distinctWpts->size[0] *
            distinctWpts->size[1]);
        distinctWpts->size[0] = ix;
        distinctWpts->size[1] = waypoints->size[1];
        ImmedMission_emxEnsureCapacity_real_T(distinctWpts, vstride);
        for (i1 = 0; i1 <= static_cast<int32_T>(outsize_idx_0 - 1); i1++) {
            for (vstride = 0; vstride <= static_cast<int32_T>(ix - 1); vstride++)
            {
                distinctWpts->data[static_cast<int32_T>(vstride +
                    static_cast<int32_T>(distinctWpts->size[0] * i1))] =
                    waypoints->data[static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(waypoints->size[0] * i1) + static_cast<
                    int32_T>(localDW->j_data[vstride])) - 1)];
            }
        }
    }
}

// Function for MATLAB Function: '<S63>/BaseWayPoint'
static void ImmedMission_circshift(emxArray_real_T_ImmedMission_T *a)
{
    emxArray_real_T_ImmedMission_T *a__1;
    if (a->size[0] != 0) {
        int32_T b_idx_1;
        int32_T ns;
        int32_T nv;
        boolean_T shiftright;
        ns = 45;
        shiftright = false;
        if (a->size[0] < 45) {
            if (a->size[0] == 0) {
                b_idx_1 = MAX_int32_T;

                // Divide by zero handler
            } else {
                b_idx_1 = static_cast<int32_T>(45 / a->size[0]);
            }

            ns = static_cast<int32_T>(45 - static_cast<int32_T>(b_idx_1 *
                a->size[0]));
        }

        if (ns > static_cast<int32_T>(a->size[0] >> 1)) {
            ns = static_cast<int32_T>(a->size[0] - ns);
            shiftright = true;
        }

        ImmedMission_emxInit_real_T(&a__1, 2);
        b_idx_1 = static_cast<int32_T>(std::floor(static_cast<real_T>(a->size[0])
            / 2.0));
        nv = static_cast<int32_T>(a__1->size[0] * a__1->size[1]);
        a__1->size[0] = 1;
        a__1->size[1] = b_idx_1;
        ImmedMission_emxEnsureCapacity_real_T(a__1, nv);
        nv = static_cast<int32_T>(b_idx_1 - 1);
        for (b_idx_1 = 0; b_idx_1 <= nv; b_idx_1++) {
            a__1->data[b_idx_1] = 0.0;
        }

        nv = a->size[0];
        if ((a->size[0] > 1) && (ns > 0)) {
            int32_T d_k;
            int32_T pageroot;
            if (shiftright) {
                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a__1->data[d_k] = a->data[static_cast<int32_T>
                        (static_cast<int32_T>(d_k + nv) - ns)];
                }

                for (d_k = a->size[0]; d_k >= static_cast<int32_T>(ns + 1); d_k =
                     static_cast<int32_T>(d_k - 1)) {
                    a->data[static_cast<int32_T>(d_k + -1)] = a->data[
                        static_cast<int32_T>(static_cast<int32_T>(d_k - ns) - 1)];
                }

                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a->data[d_k] = a__1->data[d_k];
                }

                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a__1->data[d_k] = a->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>(nv + d_k) +
                          nv) - ns)];
                }

                for (d_k = nv; d_k >= static_cast<int32_T>(ns + 1); d_k =
                        static_cast<int32_T>(d_k - 1)) {
                    b_idx_1 = static_cast<int32_T>(nv + d_k);
                    a->data[static_cast<int32_T>(b_idx_1 - 1)] = a->data[
                        static_cast<int32_T>(static_cast<int32_T>(b_idx_1 - ns)
                        - 1)];
                }

                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a->data[static_cast<int32_T>(nv + d_k)] = a__1->data[d_k];
                }
            } else {
                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a__1->data[d_k] = a->data[d_k];
                }

                d_k = static_cast<int32_T>(a->size[0] - ns);
                for (int32_T e_k{1}; static_cast<int32_T>(e_k - 1) <=
                        static_cast<int32_T>(d_k - 1); e_k = static_cast<int32_T>
                        (e_k + 1)) {
                    a->data[static_cast<int32_T>(e_k + -1)] = a->data[
                        static_cast<int32_T>(static_cast<int32_T>(e_k + ns) - 1)];
                }

                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a->data[static_cast<int32_T>(static_cast<int32_T>(d_k + nv)
                        - ns)] = a__1->data[d_k];
                }

                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a__1->data[d_k] = a->data[static_cast<int32_T>(nv + d_k)];
                }

                d_k = static_cast<int32_T>(nv - ns);
                for (int32_T e_k{1}; static_cast<int32_T>(e_k - 1) <=
                        static_cast<int32_T>(d_k - 1); e_k = static_cast<int32_T>
                        (e_k + 1)) {
                    b_idx_1 = static_cast<int32_T>(nv + e_k);
                    a->data[static_cast<int32_T>(b_idx_1 - 1)] = a->data[
                        static_cast<int32_T>(static_cast<int32_T>(b_idx_1 + ns)
                        - 1)];
                }

                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a->data[static_cast<int32_T>(static_cast<int32_T>(
                        static_cast<int32_T>(nv + d_k) + nv) - ns)] = a__1->
                        data[d_k];
                }
            }

            pageroot = static_cast<int32_T>(static_cast<int32_T>(nv << 1) - 1);
            if (shiftright) {
                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a__1->data[d_k] = a->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>
                          (static_cast<int32_T>(pageroot + d_k) + nv) - ns) + 1)];
                }

                for (d_k = nv; d_k >= static_cast<int32_T>(ns + 1); d_k =
                        static_cast<int32_T>(d_k - 1)) {
                    b_idx_1 = static_cast<int32_T>(pageroot + d_k);
                    a->data[b_idx_1] = a->data[static_cast<int32_T>(b_idx_1 - ns)];
                }

                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a->data[static_cast<int32_T>(static_cast<int32_T>(pageroot +
                        d_k) + 1)] = a__1->data[d_k];
                }
            } else {
                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a__1->data[d_k] = a->data[static_cast<int32_T>
                        (static_cast<int32_T>(pageroot + d_k) + 1)];
                }

                d_k = static_cast<int32_T>(nv - ns);
                for (int32_T e_k{1}; static_cast<int32_T>(e_k - 1) <=
                        static_cast<int32_T>(d_k - 1); e_k = static_cast<int32_T>
                        (e_k + 1)) {
                    b_idx_1 = static_cast<int32_T>(pageroot + e_k);
                    a->data[b_idx_1] = a->data[static_cast<int32_T>(b_idx_1 + ns)];
                }

                for (d_k = 0; d_k <= static_cast<int32_T>(ns - 1); d_k =
                        static_cast<int32_T>(d_k + 1)) {
                    a->data[static_cast<int32_T>(static_cast<int32_T>(
                        static_cast<int32_T>(static_cast<int32_T>(pageroot + d_k)
                        + nv) - ns) + 1)] = a__1->data[d_k];
                }
            }
        }

        ImmedMission_emxFree_real_T(&a__1);
    }
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

static void ImmedMission_binary_expand_op_p(emxArray_real_T_ImmedMission_T *in1,
    const emxArray_real_T_ImmedMission_T *in2, int32_T in3, int32_T in4)
{
    emxArray_real_T_ImmedMission_T *in1_0;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    ImmedMission_emxInit_real_T(&in1_0, 1);

    // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
    //   ActionPort: '<S7>/Action Port'

    // Outputs for Triggered SubSystem: '<S57>/WayPointGen' incorporates:
    //   TriggerPort: '<S63>/Trigger'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   MATLAB Function: '<S63>/BaseWayPoint'

    i = in1_0->size[0];
    in1_0->size[0] = static_cast<int32_T>(static_cast<int32_T>(in4 - in3) + 1) ==
        1 ? in1->size[0] : static_cast<int32_T>(static_cast<int32_T>(in4 - in3)
        + 1);
    ImmedMission_emxEnsureCapacity_real_T(in1_0, i);
    stride_0_0 = (in1->size[0] != 1);
    stride_1_0 = (static_cast<int32_T>(static_cast<int32_T>(in4 - in3) + 1) != 1);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(in4 - in3) + 1) == 1 ?
        in1->size[0] : static_cast<int32_T>(static_cast<int32_T>(in4 - in3) + 1);
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_0->data[i] = in2->data[static_cast<int32_T>(static_cast<int32_T>(i *
            stride_1_0) + in3)] + in1->data[static_cast<int32_T>
            (static_cast<int32_T>(i * stride_0_0) + static_cast<int32_T>
             (in1->size[0] << 1))];
    }

    loop_ub = in1_0->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1->data[static_cast<int32_T>(i + static_cast<int32_T>(in1->size[0] <<
            1))] = in1_0->data[i];
    }

    // End of SwitchCase: '<S1>/Switch Case'
    // End of Outputs for SubSystem: '<S57>/WayPointGen'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
    ImmedMission_emxFree_real_T(&in1_0);
}

static void ImmedMission_binary_expand_op(emxArray_real_T_ImmedMission_T *in1,
    const emxArray_real_T_ImmedMission_T *in2, const
    emxArray_real_T_ImmedMission_T *in3)
{
    emxArray_real_T_ImmedMission_T *in2_0;
    int32_T i;
    int32_T loop_ub;
    int32_T loop_ub_0;
    int32_T loop_ub_1;
    int32_T stride_1_0;
    ImmedMission_emxInit_real_T(&in2_0, 2);

    // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
    //   ActionPort: '<S7>/Action Port'

    // Outputs for Triggered SubSystem: '<S57>/WayPointGen' incorporates:
    //   TriggerPort: '<S63>/Trigger'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   MATLAB Function: '<S63>/BaseWayPoint'

    loop_ub = in2->size[0];
    loop_ub_0 = in2->size[0];
    loop_ub_1 = in2->size[0];
    i = static_cast<int32_T>(in2_0->size[0] * in2_0->size[1]);
    in2_0->size[0] = in2->size[0];
    in2_0->size[1] = 3;
    ImmedMission_emxEnsureCapacity_real_T(in2_0, i);
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_0->data[i] = in2->data[static_cast<int32_T>(i + in2->size[0])];
    }

    for (i = 0; i <= static_cast<int32_T>(loop_ub_0 - 1); i++) {
        in2_0->data[static_cast<int32_T>(i + in2_0->size[0])] = in2->data[i];
    }

    for (i = 0; i <= static_cast<int32_T>(loop_ub_1 - 1); i++) {
        in2_0->data[static_cast<int32_T>(i + static_cast<int32_T>(in2_0->size[0]
            << 1))] = in2->data[static_cast<int32_T>(static_cast<int32_T>
            (in2->size[0] << 1) + i)];
    }

    i = static_cast<int32_T>(in1->size[0] * in1->size[1]);
    in1->size[0] = in3->size[0] == 1 ? in2_0->size[0] : in3->size[0];
    in1->size[1] = 3;
    ImmedMission_emxEnsureCapacity_real_T(in1, i);
    loop_ub_1 = (in2_0->size[0] != 1);
    stride_1_0 = (in3->size[0] != 1);
    loop_ub = in3->size[0] == 1 ? in2_0->size[0] : in3->size[0];
    for (i = 0; i < 3; i++) {
        for (loop_ub_0 = 0; loop_ub_0 <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_0++) {
            in1->data[static_cast<int32_T>(loop_ub_0 + static_cast<int32_T>
                (in1->size[0] * i))] = in2_0->data[static_cast<int32_T>(
                static_cast<int32_T>(loop_ub_0 * loop_ub_1) +
                static_cast<int32_T>(in2_0->size[0] * i))] + in3->data[
                static_cast<int32_T>(static_cast<int32_T>(loop_ub_0 * stride_1_0)
                + static_cast<int32_T>(in3->size[0] * i))];
        }
    }

    // End of SwitchCase: '<S1>/Switch Case'
    // End of Outputs for SubSystem: '<S57>/WayPointGen'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
    ImmedMission_emxFree_real_T(&in2_0);
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
    // Start for MATLABSystem: '<S23>/Orbit Follower'
    localDW->objisempty_e = true;
    localDW->obj_c.isInitialized = 1;
    localDW->obj_c.PrevResetSignal = 0.0;
    localDW->obj_c.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S23>/Orbit Follower'
    localDW->obj_c.OrbitRadiusInternal = (rtNaN);
    localDW->obj_c.PrevResetSignal *= 0.0;
    localDW->obj_c.NumCircles *= 0.0;

    // Start for MATLABSystem: '<S23>/Orbit Follower'
    localDW->obj_c.PrevPosition[0] = 0.0;

    // InitializeConditions for MATLABSystem: '<S23>/Orbit Follower'
    localDW->obj_c.OrbitCenterInternal[0] = (rtNaN);
    localDW->obj_c.PrevPosition[0] *= 0.0;

    // Start for MATLABSystem: '<S23>/Orbit Follower'
    localDW->obj_c.PrevPosition[1] = 0.0;

    // InitializeConditions for MATLABSystem: '<S23>/Orbit Follower'
    localDW->obj_c.OrbitCenterInternal[1] = (rtNaN);
    localDW->obj_c.PrevPosition[1] *= 0.0;

    // Start for MATLABSystem: '<S23>/Orbit Follower'
    localDW->obj_c.PrevPosition[2] = 0.0;

    // InitializeConditions for MATLABSystem: '<S23>/Orbit Follower'
    localDW->obj_c.OrbitCenterInternal[2] = (rtNaN);
    localDW->obj_c.PrevPosition[2] *= 0.0;
    localDW->obj_c.StartFlag = true;
    localDW->obj_c.SelectTurnDirectionFlag = true;
    localDW->obj_c.TurnDirectionInternal = 1.0;
    localDW->obj_c.OrbitRadiusFlag = 0U;
    localDW->obj_c.LookaheadDistFlag = 0U;

    // End of SystemInitialize for SubSystem: '<S1>/Mode128_DetailedInsp'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode131_SqCalibr'
    // SystemInitialize for Triggered SubSystem: '<S57>/WayPointGen'
    // SystemInitialize for MATLAB Function: '<S63>/BaseWayPoint'
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S63>/BaseWayPoint'

    // Start for MATLABSystem: '<S63>/RotateATMissionHdg'
    localDW->objisempty_o = true;
    localDW->obj_n.isInitialized = 1;
    localZCE->WayPointGen_Trig_ZCE_d = NEG_ZCSIG;

    // End of SystemInitialize for SubSystem: '<S57>/WayPointGen'

    // Start for MATLABSystem: '<S57>/Waypoint Follower'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.CacheInputSizes = false;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    for (int32_T i{0}; i < 8; i++) {
        localDW->obj.inputVarSize[0].f1[i] = 1U;
    }

    localDW->obj.inputVarSize[1].f1[0] = 0U;
    localDW->obj.inputVarSize[1].f1[1] = 0U;
    for (int32_T i{0}; i < 6; i++) {
        localDW->obj.inputVarSize[1].f1[static_cast<int32_T>(i + 2)] = 1U;
    }

    for (int32_T i{0}; i < 8; i++) {
        localDW->obj.inputVarSize[2].f1[i] = 1U;
    }

    // InitializeConditions for MATLABSystem: '<S57>/Waypoint Follower'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 30723; i++) {
        // InitializeConditions for MATLABSystem: '<S57>/Waypoint Follower'
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S1>/Mode131_SqCalibr'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode132_pAttack'
    // SystemInitialize for Triggered SubSystem: '<S111>/WayPointGen'
    localZCE->WayPointGen_Trig_ZCE = NEG_ZCSIG;

    // End of SystemInitialize for SubSystem: '<S111>/WayPointGen'

    // Constant: '<S111>/Constant'
    ImmedMission_Altitude_Init(&localDW->Altitude);
    ImmedMission_Altitude_Init(&localDW->Heading);

    // End of SystemInitialize for SubSystem: '<S1>/Mode132_pAttack'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU'
    ImmedMission_CoordinateTransformationConversion_Init
        (&localDW->CoordinateTransformationConversion);

    // End of SystemInitialize for SubSystem: '<S1>/Mode254_ShiftEarthENU'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode253_ShiftBodyXYZ'
    ImmedMission_CoordinateTransformationConversion_Init
        (&localDW->CoordinateTransformationConversion_j);

    // End of SystemInitialize for SubSystem: '<S1>/Mode253_ShiftBodyXYZ'

    // SystemInitialize for Merge: '<S1>/MergeCollAvoidSimUAV'
    std::memset(&localDW->MergeCollAvoidSimUAV, 0, sizeof
                (FixedWingGuidanceStateBus));

    // SystemInitialize for Merge: '<S1>/MergeControlSwitch'
    rty_ControlSwitch[0] = false;
    rty_ControlSwitch[1] = false;
    std::memset(rty_GuidanceCMD, 0, sizeof(FixedWingGuidanceBus));
}

// System reset for referenced model: 'ImmedMission'
void ImmedMission_Reset(DW_ImmedMission_f_T *localDW)
{
    // InitializeConditions for Memory: '<S1>/Memory'
    localDW->Memory_PreviousInput = 0U;

    // InitializeConditions for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput_j = 0U;

    // SystemReset for Chart: '<S1>/PreemptableMissionModeSelector'
    localDW->is_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
    localDW->is_active_c25_ImmedMission = 0U;
    localDW->is_c25_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
    localDW->ImmedMission_a = MissionModes::None;
    localDW->FlightMode_prev = MissionModes::None;
    localDW->FlightMode_start = MissionModes::None;
}

// Disable for referenced model: 'ImmedMission'
void ImmedMission_Disable(DW_ImmedMission_f_T *localDW)
{
    // Disable for Atomic SubSystem: '<S145>/SailDistance'
    // Disable for Enabled SubSystem: '<S147>/SailShift'
    // Disable for SwitchCase: '<S1>/Switch Case'
    localDW->SailShift_MODE = static_cast<boolean_T>(static_cast<int32_T>((
        static_cast<int32_T>(localDW->SwitchCase_ActiveSubsystem) != 4) &
        static_cast<int32_T>(localDW->SailShift_MODE)));

    // End of Disable for SubSystem: '<S147>/SailShift'
    // End of Disable for SubSystem: '<S145>/SailDistance'
    localDW->SwitchCase_ActiveSubsystem = -1;
}

// Outputs for referenced model: 'ImmedMission'
void ImmedMission(const FixedWingGuidanceStateBus *rtu_SimUAVstate, const
                  missionCmd *rtu_MissionInput, const boolean_T *rtu_NewImmed,
                  const RealUAVStateBus *rtu_RealUAVState, const int32_T
                  *rtu_FlightMission_SequenceID, const MissionModes
                  *rtu_FlightMission_MissionMode, const real_T
                  *rtu_FlightMission_MissionLocation_Lat, const real_T
                  *rtu_FlightMission_MissionLocation_Lon, const real_T
                  *rtu_FlightMission_MissionLocation_Alt, const real_T
                  *rtu_FlightMission_MissionLocation_degHDG, const real32_T
                  *rtu_FlightMission_params_Param3, const int32_T
                  *rtu_FlightMission_numUAV, const int32_T
                  *rtu_FlightMission_FormationPos, const int32_T
                  rtu_OtherUAVstate_DIMS1[2], const MissionModes *rtu_FlightMode,
                  real_T *rty_TaskStatus, FixedWingGuidanceStateBus
                  *rty_FinalSimUAVState, boolean_T rty_ControlSwitch[2],
                  FixedWingGuidanceBus *rty_GuidanceCMD, DW_ImmedMission_f_T
                  *localDW, ZCE_ImmedMission_T *localZCE)
{
    // local block i/o variables
    real_T rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[3];
    real_T rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e
        [3];
    real_T rtb_TmpSignalConversionAtAltitudeInport1[4];
    real_T rtb_sqrt;
    static const real_T b_a[722]{ 1.0, 0.0, 0.99984769515639127,
        0.017452406437283512, 0.99939082701909576, 0.034899496702500969,
        0.99862953475457383, 0.052335956242943835, 0.9975640502598242,
        0.0697564737441253, 0.99619469809174555, 0.087155742747658166,
        0.99452189536827329, 0.10452846326765347, 0.992546151641322,
        0.12186934340514748, 0.99026806874157036, 0.13917310096006544,
        0.98768834059513777, 0.15643446504023087, 0.984807753012208,
        0.17364817766693033, 0.981627183447664, 0.1908089953765448,
        0.97814760073380569, 0.20791169081775934, 0.97437006478523525,
        0.224951054343865, 0.97029572627599647, 0.24192189559966773,
        0.96592582628906831, 0.25881904510252074, 0.96126169593831889,
        0.27563735581699916, 0.95630475596303544, 0.29237170472273677,
        0.95105651629515353, 0.3090169943749474, 0.94551857559931685,
        0.3255681544571567, 0.93969262078590843, 0.34202014332566871,
        0.93358042649720174, 0.35836794954530027, 0.92718385456678742,
        0.374606593415912, 0.92050485345244037, 0.39073112848927377,
        0.91354545764260087, 0.40673664307580021, 0.90630778703664994,
        0.42261826174069944, 0.898794046299167, 0.4383711467890774,
        0.8910065241883679, 0.45399049973954675, 0.882947592858927,
        0.46947156278589081, 0.87461970713939574, 0.48480962024633706,
        0.86602540378443871, 0.49999999999999994, 0.85716730070211233,
        0.51503807491005416, 0.848048096156426, 0.5299192642332049,
        0.838670567945424, 0.54463903501502708, 0.82903757255504162,
        0.5591929034707469, 0.8191520442889918, 0.573576436351046,
        0.80901699437494745, 0.58778525229247314, 0.79863551004729283,
        0.60181502315204827, 0.7880107536067219, 0.61566147532565829,
        0.7771459614569709, 0.62932039104983739, 0.766044443118978,
        0.64278760968653925, 0.754709580222772, 0.65605902899050728,
        0.74314482547739424, 0.66913060635885824, 0.73135370161917046,
        0.68199836006249848, 0.71933980033865119, 0.69465837045899725,
        0.70710678118654757, 0.70710678118654746, 0.69465837045899725,
        0.71933980033865119, 0.68199836006249848, 0.73135370161917046,
        0.66913060635885824, 0.74314482547739424, 0.65605902899050728,
        0.754709580222772, 0.64278760968653936, 0.766044443118978,
        0.6293203910498375, 0.7771459614569709, 0.61566147532565829,
        0.788010753606722, 0.60181502315204827, 0.79863551004729283,
        0.58778525229247314, 0.80901699437494745, 0.573576436351046,
        0.8191520442889918, 0.55919290347074679, 0.82903757255504174,
        0.54463903501502708, 0.838670567945424, 0.5299192642332049,
        0.84804809615642607, 0.51503807491005416, 0.85716730070211233,
        0.50000000000000011, 0.8660254037844386, 0.48480962024633711,
        0.87461970713939574, 0.46947156278589086, 0.88294759285892688,
        0.45399049973954686, 0.89100652418836779, 0.43837114678907746,
        0.898794046299167, 0.42261826174069944, 0.90630778703664994,
        0.40673664307580021, 0.91354545764260087, 0.39073112848927372,
        0.92050485345244037, 0.37460659341591196, 0.92718385456678742,
        0.35836794954530038, 0.93358042649720174, 0.34202014332566882,
        0.93969262078590832, 0.32556815445715676, 0.94551857559931674,
        0.30901699437494745, 0.95105651629515353, 0.29237170472273677,
        0.95630475596303544, 0.27563735581699916, 0.96126169593831889,
        0.25881904510252074, 0.96592582628906831, 0.24192189559966767,
        0.97029572627599647, 0.22495105434386492, 0.97437006478523525,
        0.20791169081775945, 0.97814760073380558, 0.19080899537654492,
        0.981627183447664, 0.17364817766693041, 0.984807753012208,
        0.15643446504023092, 0.98768834059513777, 0.13917310096006547,
        0.99026806874157036, 0.12186934340514749, 0.992546151641322,
        0.10452846326765346, 0.99452189536827329, 0.087155742747658138,
        0.99619469809174555, 0.069756473744125233, 0.9975640502598242,
        0.052335956242943966, 0.99862953475457383, 0.03489949670250108,
        0.99939082701909576, 0.0174524064372836, 0.99984769515639127,
        6.123233995736766E-17, 1.0, -0.017452406437283477, 0.99984769515639127,
        -0.034899496702500955, 0.99939082701909576, -0.052335956242943842,
        0.99862953475457383, -0.06975647374412533, 0.9975640502598242,
        -0.087155742747658235, 0.99619469809174555, -0.10452846326765355,
        0.99452189536827329, -0.12186934340514737, 0.99254615164132209,
        -0.13917310096006535, 0.99026806874157036, -0.15643446504023081,
        0.98768834059513777, -0.1736481776669303, 0.984807753012208,
        -0.1908089953765448, 0.981627183447664, -0.20791169081775934,
        0.97814760073380569, -0.22495105434386503, 0.97437006478523525,
        -0.24192189559966779, 0.97029572627599647, -0.25881904510252085,
        0.96592582628906831, -0.27563735581699905, 0.96126169593831889,
        -0.29237170472273666, 0.95630475596303555, -0.30901699437494734,
        0.95105651629515364, -0.32556815445715664, 0.94551857559931685,
        -0.34202014332566871, 0.93969262078590843, -0.35836794954530027,
        0.93358042649720174, -0.37460659341591207, 0.92718385456678742,
        -0.39073112848927377, 0.92050485345244026, -0.40673664307580026,
        0.91354545764260087, -0.42261826174069933, 0.90630778703665,
        -0.43837114678907751, 0.89879404629916693, -0.45399049973954675,
        0.8910065241883679, -0.46947156278589092, 0.88294759285892688,
        -0.484809620246337, 0.87461970713939585, -0.49999999999999978,
        0.86602540378443871, -0.51503807491005427, 0.85716730070211233,
        -0.52991926423320479, 0.84804809615642607, -0.54463903501502708,
        0.838670567945424, -0.55919290347074668, 0.82903757255504174,
        -0.57357643635104616, 0.81915204428899169, -0.587785252292473,
        0.80901699437494745, -0.60181502315204838, 0.79863551004729272,
        -0.61566147532565829, 0.788010753606722, -0.62932039104983728,
        0.777145961456971, -0.64278760968653936, 0.766044443118978,
        -0.65605902899050716, 0.75470958022277213, -0.66913060635885824,
        0.74314482547739424, -0.68199836006249837, 0.73135370161917057,
        -0.69465837045899737, 0.71933980033865108, -0.70710678118654746,
        0.70710678118654757, -0.7193398003386513, 0.69465837045899714,
        -0.73135370161917046, 0.68199836006249859, -0.74314482547739413,
        0.66913060635885835, -0.754709580222772, 0.65605902899050728,
        -0.7660444431189779, 0.64278760968653947, -0.7771459614569709,
        0.62932039104983739, -0.7880107536067219, 0.6156614753256584,
        -0.79863551004729294, 0.60181502315204816, -0.80901699437494734,
        0.58778525229247325, -0.81915204428899191, 0.57357643635104594,
        -0.82903757255504162, 0.5591929034707469, -0.83867056794542394,
        0.54463903501502731, -0.848048096156426, 0.5299192642332049,
        -0.85716730070211222, 0.51503807491005438, -0.86602540378443871,
        0.49999999999999994, -0.87461970713939574, 0.48480962024633717,
        -0.882947592858927, 0.46947156278589069, -0.89100652418836779,
        0.45399049973954686, -0.898794046299167, 0.43837114678907729,
        -0.90630778703664994, 0.4226182617406995, -0.91354545764260076,
        0.40673664307580043, -0.92050485345244037, 0.39073112848927377,
        -0.92718385456678731, 0.37460659341591224, -0.93358042649720174,
        0.35836794954530021, -0.93969262078590832, 0.34202014332566888,
        -0.94551857559931685, 0.32556815445715659, -0.95105651629515353,
        0.30901699437494751, -0.95630475596303555, 0.2923717047227366,
        -0.96126169593831889, 0.27563735581699922, -0.9659258262890682,
        0.258819045102521, -0.97029572627599647, 0.24192189559966773,
        -0.97437006478523513, 0.2249510543438652, -0.97814760073380569,
        0.20791169081775931, -0.981627183447664, 0.19080899537654497,
        -0.984807753012208, 0.17364817766693028, -0.98768834059513766,
        0.15643446504023098, -0.99026806874157036, 0.13917310096006533,
        -0.992546151641322, 0.12186934340514755, -0.99452189536827329,
        0.10452846326765373, -0.99619469809174555, 0.0871557427476582,
        -0.9975640502598242, 0.069756473744125524, -0.99862953475457383,
        0.052335956242943807, -0.99939082701909576, 0.034899496702501143,
        -0.99984769515639127, 0.017452406437283439, -1.0, 1.2246467991473532E-16,
        -0.99984769515639127, -0.017452406437283637, -0.99939082701909576,
        -0.0348994967025009, -0.99862953475457383, -0.052335956242943564,
        -0.9975640502598242, -0.069756473744125275, -0.99619469809174555,
        -0.087155742747657944, -0.99452189536827329, -0.1045284632676535,
        -0.99254615164132209, -0.12186934340514731, -0.99026806874157025,
        -0.13917310096006552, -0.98768834059513777, -0.15643446504023073,
        -0.984807753012208, -0.17364817766693047, -0.981627183447664,
        -0.19080899537654472, -0.97814760073380558, -0.20791169081775951,
        -0.97437006478523525, -0.22495105434386498, -0.97029572627599658,
        -0.24192189559966751, -0.96592582628906831, -0.25881904510252079,
        -0.96126169593831889, -0.275637355816999, -0.95630475596303544,
        -0.29237170472273677, -0.95105651629515364, -0.30901699437494728,
        -0.94551857559931674, -0.32556815445715676, -0.93969262078590843,
        -0.34202014332566866, -0.93358042649720174, -0.35836794954530043,
        -0.92718385456678742, -0.374606593415912, -0.92050485345244037,
        -0.39073112848927355, -0.91354545764260087, -0.40673664307580021,
        -0.90630778703665, -0.42261826174069927, -0.89879404629916693,
        -0.43837114678907746, -0.8910065241883679, -0.45399049973954669,
        -0.88294759285892688, -0.46947156278589086, -0.87461970713939585,
        -0.48480962024633695, -0.8660254037844386, -0.50000000000000011,
        -0.85716730070211233, -0.51503807491005416, -0.84804809615642607,
        -0.52991926423320479, -0.838670567945424, -0.54463903501502708,
        -0.82903757255504185, -0.55919290347074668, -0.8191520442889918,
        -0.57357643635104616, -0.80901699437494745, -0.587785252292473,
        -0.79863551004729283, -0.60181502315204838, -0.788010753606722,
        -0.61566147532565818, -0.77714596145697079, -0.62932039104983761,
        -0.76604444311897812, -0.64278760968653925, -0.75470958022277213,
        -0.656059028990507, -0.74314482547739424, -0.66913060635885824,
        -0.73135370161917057, -0.68199836006249837, -0.71933980033865108,
        -0.69465837045899737, -0.70710678118654768, -0.70710678118654746,
        -0.69465837045899725, -0.71933980033865119, -0.68199836006249859,
        -0.73135370161917046, -0.66913060635885813, -0.74314482547739436,
        -0.65605902899050728, -0.754709580222772, -0.64278760968653947,
        -0.7660444431189779, -0.62932039104983784, -0.77714596145697057,
        -0.61566147532565807, -0.78801075360672213, -0.60181502315204827,
        -0.79863551004729283, -0.58778525229247325, -0.80901699437494734,
        -0.57357643635104638, -0.81915204428899158, -0.55919290347074657,
        -0.82903757255504185, -0.544639035015027, -0.838670567945424,
        -0.529919264233205, -0.848048096156426, -0.51503807491005449,
        -0.85716730070211211, -0.50000000000000044, -0.86602540378443849,
        -0.48480962024633684, -0.87461970713939585, -0.46947156278589075,
        -0.882947592858927, -0.45399049973954692, -0.89100652418836779,
        -0.43837114678907774, -0.89879404629916682, -0.42261826174069916,
        -0.90630778703665, -0.4067366430758001, -0.913545457642601,
        -0.39073112848927383, -0.92050485345244026, -0.37460659341591229,
        -0.92718385456678731, -0.35836794954530071, -0.93358042649720163,
        -0.34202014332566855, -0.93969262078590843, -0.32556815445715664,
        -0.94551857559931685, -0.30901699437494756, -0.95105651629515353,
        -0.2923717047227371, -0.95630475596303532, -0.27563735581699889,
        -0.96126169593831889, -0.25881904510252063, -0.96592582628906831,
        -0.24192189559966779, -0.97029572627599647, -0.22495105434386525,
        -0.97437006478523513, -0.20791169081775979, -0.97814760073380558,
        -0.19080899537654461, -0.981627183447664, -0.17364817766693033,
        -0.984807753012208, -0.15643446504023104, -0.98768834059513766,
        -0.13917310096006583, -0.99026806874157025, -0.12186934340514717,
        -0.99254615164132209, -0.10452846326765336, -0.9945218953682734,
        -0.087155742747658249, -0.99619469809174555, -0.06975647374412558,
        -0.9975640502598242, -0.052335956242944306, -0.99862953475457383,
        -0.034899496702500761, -0.99939082701909576, -0.017452406437283498,
        -0.99984769515639127, -1.8369701987210297E-16, -1.0, 0.01745240643728313,
        -0.99984769515639127, 0.034899496702501281, -0.99939082701909576,
        0.052335956242943946, -0.99862953475457383, 0.069756473744125219,
        -0.99756405025982431, 0.087155742747657888, -0.99619469809174555,
        0.10452846326765299, -0.9945218953682734, 0.12186934340514768,
        -0.992546151641322, 0.13917310096006547, -0.99026806874157036,
        0.15643446504023067, -0.98768834059513777, 0.17364817766692997,
        -0.98480775301220813, 0.19080899537654511, -0.98162718344766386,
        0.20791169081775943, -0.97814760073380558, 0.22495105434386492,
        -0.97437006478523525, 0.24192189559966745, -0.97029572627599658,
        0.2588190451025203, -0.96592582628906842, 0.27563735581699939,
        -0.96126169593831878, 0.29237170472273671, -0.95630475596303544,
        0.30901699437494723, -0.95105651629515364, 0.32556815445715631,
        -0.945518575599317, 0.342020143325669, -0.93969262078590832,
        0.35836794954530038, -0.93358042649720174, 0.37460659341591196,
        -0.92718385456678742, 0.39073112848927349, -0.92050485345244049,
        0.40673664307579976, -0.91354545764260109, 0.42261826174069961,
        -0.90630778703664983, 0.4383711467890774, -0.898794046299167,
        0.45399049973954664, -0.891006524188368, 0.46947156278589042,
        -0.8829475928589271, 0.48480962024633728, -0.87461970713939563,
        0.50000000000000011, -0.8660254037844386, 0.51503807491005416,
        -0.85716730070211233, 0.52991926423320468, -0.84804809615642607,
        0.54463903501502664, -0.83867056794542427, 0.559192903470747,
        -0.82903757255504162, 0.573576436351046, -0.8191520442889918,
        0.58778525229247292, -0.80901699437494756, 0.60181502315204793,
        -0.798635510047293, 0.61566147532565851, -0.78801075360672179,
        0.6293203910498375, -0.77714596145697079, 0.64278760968653925,
        -0.76604444311897812, 0.656059028990507, -0.75470958022277213,
        0.66913060635885779, -0.74314482547739458, 0.68199836006249859,
        -0.73135370161917035, 0.69465837045899725, -0.71933980033865108,
        0.70710678118654735, -0.70710678118654768, 0.71933980033865086,
        -0.69465837045899759, 0.73135370161917068, -0.68199836006249825,
        0.74314482547739424, -0.66913060635885813, 0.7547095802227719,
        -0.65605902899050739, 0.76604444311897779, -0.64278760968653958,
        0.77714596145697057, -0.62932039104983784, 0.788010753606722,
        -0.61566147532565818, 0.79863551004729283, -0.60181502315204827,
        0.80901699437494734, -0.58778525229247336, 0.81915204428899158,
        -0.57357643635104649, 0.82903757255504185, -0.55919290347074657,
        0.838670567945424, -0.544639035015027, 0.84804809615642585,
        -0.529919264233205, 0.85716730070211211, -0.51503807491005449,
        0.86602540378443837, -0.50000000000000044, 0.87461970713939585,
        -0.48480962024633689, 0.882947592858927, -0.46947156278589081,
        0.89100652418836779, -0.45399049973954697, 0.89879404629916682,
        -0.43837114678907779, 0.90630778703665, -0.42261826174069922,
        0.913545457642601, -0.40673664307580015, 0.92050485345244026,
        -0.39073112848927388, 0.92718385456678731, -0.37460659341591235,
        0.93358042649720152, -0.35836794954530077, 0.93969262078590843,
        -0.3420201433256686, 0.94551857559931685, -0.3255681544571567,
        0.95105651629515353, -0.30901699437494762, 0.95630475596303532,
        -0.29237170472273716, 0.96126169593831889, -0.27563735581699894,
        0.96592582628906831, -0.25881904510252068, 0.97029572627599647,
        -0.24192189559966787, 0.97437006478523513, -0.22495105434386534,
        0.97814760073380558, -0.20791169081775987, 0.981627183447664,
        -0.19080899537654467, 0.984807753012208, -0.17364817766693039,
        0.98768834059513766, -0.15643446504023112, 0.99026806874157025,
        -0.13917310096006588, 0.99254615164132209, -0.12186934340514723,
        0.99452189536827329, -0.10452846326765342, 0.99619469809174555,
        -0.087155742747658319, 0.9975640502598242, -0.069756473744125636,
        0.99862953475457383, -0.052335956242944369, 0.99939082701909576,
        -0.034899496702500823, 0.99984769515639127, -0.01745240643728356, 1.0,
        -2.4492935982947064E-16 };

    static const int16_T d[91]{ 270, 271, 272, 273, 274, 275, 276, 277, 278, 279,
        280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293,
        294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307,
        308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321,
        322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335,
        336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349,
        350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 0 };

    emxArray_real_T_ImmedMission_T MatrixConcatenate_d;
    emxArray_real_T_ImmedMission_T *WayPoint;
    emxArray_real_T_ImmedMission_T *WayPoint_0;
    emxArray_real_T_ImmedMission_T *d_b;
    emxArray_real_T_ImmedMission_T *e;
    emxArray_real_T_ImmedMission_T *rotWayPoint;
    emxArray_real_T_ImmedMission_T *rotWayPoint_0;
    emxArray_real_T_ImmedMission_T *step;
    emxArray_real_T_ImmedMission_T *tmp;
    emxArray_real_T_ImmedMission_T *tmp_0;
    emxArray_real_T_ImmedMission_T *waypointsIn;
    emxArray_real_T_ImmedMission_T *y;
    real_T WPQ1_tmp[91];
    real_T out[9];
    real_T rtb_Sum_gu[3];
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport2[3];
    real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1[3];
    real_T turnVector[3];
    real_T distToCenter_tmp[2];
    real_T rtb_TmpSignalConversionAtOrbitF[2];
    real_T rtb_Abs1;
    real_T rtb_Down;
    real_T rtb_Py_n;
    real_T rtb_Sum1_idx_0;
    real_T rtb_Sum1_idx_1;
    real_T rtb_Switch;
    real_T rtb_Switch_m2;
    real_T rtb_Switch_tmp;
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
    real_T rtb_Up;
    real_T xyCenter_idx_1;
    int32_T MatrixConcatenate_DIMS1[2];
    int32_T colIdx;
    int32_T nm1d2;
    int32_T rtb_BiasNumUAV;
    int32_T rtb_BiasOldIdx;
    uint32_T inSize[8];
    int8_T waypointsIn_0[2];
    int8_T rtAction;
    int8_T rtPrevAction;
    boolean_T rtb_Compare_lh;
    ImmedMission_emxInit_real_T(&e, 2);

    // Chart: '<S1>/PreemptableMissionModeSelector' incorporates:
    //   Memory: '<S1>/Memory'

    // Gateway: ImmedMissionGuidance/PreemptableMissionModeSelector
    localDW->FlightMode_prev = localDW->FlightMode_start;
    localDW->FlightMode_start = *rtu_FlightMode;

    // During: ImmedMissionGuidance/PreemptableMissionModeSelector
    if (static_cast<uint32_T>(localDW->is_active_c25_ImmedMission) == 0U) {
        localDW->FlightMode_prev = *rtu_FlightMode;

        // Entry: ImmedMissionGuidance/PreemptableMissionModeSelector
        localDW->is_active_c25_ImmedMission = 1U;

        // Entry Internal: ImmedMissionGuidance/PreemptableMissionModeSelector
        // Transition: '<S11>:152'
        localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
        localDW->ImmedMission_a = MissionModes::WaitToStart;

        // Entry 'WaitToStart': '<S11>:151'
    } else if (localDW->is_c25_ImmedMission == ImmedMission_IN_ImmedMission) {
        // During 'ImmedMission': '<S11>:154'
        if (*rtu_NewImmed) {
            // Transition: '<S11>:155'
            // Exit Internal 'ImmedMission': '<S11>:154'
            // Exit Internal 'Formation': '<S11>:246'
            localDW->is_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
            localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
            localDW->ImmedMission_a = MissionModes::WaitToStart;

            // Entry 'WaitToStart': '<S11>:151'
        } else {
            switch (localDW->is_ImmedMission) {
              case ImmedMission_IN_DetailedInsp:
                // During 'DetailedInsp': '<S11>:166'
                break;

              case ImmedMission_IN_FlightMissionRH:
                // During 'FlightMissionRH': '<S11>:167'
                break;

              case ImmedMission_IN_Formation:
                // During 'Formation': '<S11>:246'
                if (localDW->FlightMode_prev != localDW->FlightMode_start) {
                    // Transition: '<S11>:247'
                    // Exit Internal 'Formation': '<S11>:246'
                    localDW->is_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
                    localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
                    localDW->ImmedMission_a = MissionModes::WaitToStart;

                    // Entry 'WaitToStart': '<S11>:151'
                }
                break;

              case ImmedMission_IN_SqCalibr:
                // During 'SqCalibr': '<S11>:170'
                if (static_cast<int32_T>(localDW->Memory_PreviousInput) != 0) {
                    // Transition: '<S11>:177'
                    localDW->is_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
                    localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
                    localDW->ImmedMission_a = MissionModes::WaitToStart;

                    // Entry 'WaitToStart': '<S11>:151'
                }
                break;

              default:
                // During 'pAttack': '<S11>:204'
                break;
            }
        }
    } else {
        // During 'WaitToStart': '<S11>:151'
        // Transition: '<S11>:153'
        switch (rtu_MissionInput->MissionMode) {
          case MissionModes::DetailedInsp:
            // Transition: '<S11>:187'
            // Transition: '<S11>:124'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_DetailedInsp;
            localDW->ImmedMission_a = MissionModes::DetailedInsp;
            break;

          case MissionModes::FlightMissionRH:
            // Transition: '<S11>:130'
            // Transition: '<S11>:189'
            // Transition: '<S11>:182'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_FlightMissionRH;
            localDW->ImmedMission_a = MissionModes::FlightMissionRH;
            break;

          case MissionModes::SqCalibr:
            // Transition: '<S11>:185'
            // Transition: '<S11>:193'
            // Transition: '<S11>:174'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_SqCalibr;
            localDW->ImmedMission_a = MissionModes::SqCalibr;
            break;

          case MissionModes::pAttack:
            // Transition: '<S11>:200'
            // Transition: '<S11>:202'
            // Transition: '<S11>:217'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_pAttack;
            localDW->ImmedMission_a = MissionModes::pAttack;
            break;

          default:
            if (rtu_MissionInput->SequenceID == *rtu_FlightMission_SequenceID) {
                // Transition: '<S11>:243'
                switch (rtu_MissionInput->MissionMode) {
                  case MissionModes::ShiftEarthENU:
                    // Transition: '<S11>:231'
                    // Transition: '<S11>:233'
                    localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
                    localDW->is_ImmedMission = ImmedMission_IN_Formation;
                    localDW->ImmedMission_a = MissionModes::ShiftEarthENU;
                    break;

                  case MissionModes::ShiftBodyXYZ:
                    // Transition: '<S11>:228'
                    // Transition: '<S11>:232'
                    // Transition: '<S11>:235'
                    localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
                    localDW->is_ImmedMission = ImmedMission_IN_Formation;
                    localDW->ImmedMission_a = MissionModes::ShiftBodyXYZ;
                    break;
                }
            }
            break;
        }
    }

    // End of Chart: '<S1>/PreemptableMissionModeSelector'

    // Sum: '<S154>/Sum1' incorporates:
    //   DataStoreRead: '<S2>/LatitudeGCS'
    //   Switch: '<S168>/Switch'

    rtb_Sum1_idx_0 = rtu_RealUAVState->Latitude_deg - LatitudeGCS;

    // Switch: '<S162>/Switch' incorporates:
    //   Abs: '<S162>/Abs'
    //   Bias: '<S162>/Bias'
    //   Bias: '<S162>/Bias1'
    //   Constant: '<S162>/Constant2'
    //   Constant: '<S163>/Constant'
    //   Math: '<S162>/Math Function1'
    //   RelationalOperator: '<S163>/Compare'

    if (std::abs(rtb_Sum1_idx_0) > 180.0) {
        rtb_Switch_m2 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
    } else {
        rtb_Switch_m2 = rtb_Sum1_idx_0;
    }

    // End of Switch: '<S162>/Switch'

    // Abs: '<S159>/Abs1'
    rtb_Abs1 = std::abs(rtb_Switch_m2);

    // Switch: '<S159>/Switch' incorporates:
    //   Bias: '<S159>/Bias'
    //   Bias: '<S159>/Bias1'
    //   Constant: '<S155>/Constant'
    //   Constant: '<S155>/Constant1'
    //   Constant: '<S161>/Constant'
    //   Gain: '<S159>/Gain'
    //   Product: '<S159>/Divide1'
    //   RelationalOperator: '<S161>/Compare'
    //   Switch: '<S155>/Switch1'

    if (rtb_Abs1 > 90.0) {
        // Signum: '<S159>/Sign1'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(rtb_Switch_m2)) ^ 1))) {
            if (rtb_Switch_m2 < 0.0) {
                rtb_Switch_m2 = -1.0;
            } else {
                rtb_Switch_m2 = static_cast<real_T>(rtb_Switch_m2 > 0.0);
            }
        }

        // End of Signum: '<S159>/Sign1'
        rtb_Switch_m2 *= -(rtb_Abs1 + -90.0) + 90.0;
        nm1d2 = 180;
    } else {
        nm1d2 = 0;
    }

    // End of Switch: '<S159>/Switch'

    // Sum: '<S155>/Sum' incorporates:
    //   DataStoreRead: '<S2>/LongitudeGCS'
    //   Sum: '<S154>/Sum1'
    //   Sum: '<S156>/Sum'

    rtb_Abs1 = (rtu_RealUAVState->Longitude_deg - LongitudeGCS) +
        static_cast<real_T>(nm1d2);

    // Switch: '<S160>/Switch' incorporates:
    //   Abs: '<S160>/Abs'
    //   Bias: '<S160>/Bias'
    //   Bias: '<S160>/Bias1'
    //   Constant: '<S160>/Constant2'
    //   Constant: '<S164>/Constant'
    //   Math: '<S160>/Math Function1'
    //   RelationalOperator: '<S164>/Compare'

    if (std::abs(rtb_Abs1) > 180.0) {
        rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S160>/Switch'

    // UnitConversion: '<S158>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Switch_m2;
    rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Abs1;

    // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
    //   ActionPort: '<S7>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
    //   ActionPort: '<S8>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
    //   ActionPort: '<S5>/Action Port'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   DataStoreRead: '<S2>/LatitudeGCS'
    //   Switch: '<S168>/Switch'
    //   UnitConversion: '<S105>/Unit Conversion'
    //   UnitConversion: '<S133>/Unit Conversion'
    //   UnitConversion: '<S173>/Unit Conversion'
    //   UnitConversion: '<S48>/Unit Conversion'
    //   UnitConversion: '<S82>/Unit Conversion'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Switch_tmp = 0.017453292519943295 * LatitudeGCS;

    // End of Outputs for SubSystem: '<S1>/Mode128_DetailedInsp'
    // End of Outputs for SubSystem: '<S1>/Mode132_pAttack'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'

    // Trigonometry: '<S174>/Trigonometric Function1' incorporates:
    //   UnitConversion: '<S173>/Unit Conversion'

    rtb_Abs1 = std::sin(rtb_Switch_tmp);

    // Sum: '<S174>/Sum1' incorporates:
    //   Constant: '<S174>/Constant'
    //   Product: '<S174>/Product1'

    rtb_Abs1 = 1.0 - 0.0066943799901413295 * rtb_Abs1 * rtb_Abs1;

    // Product: '<S172>/Product1' incorporates:
    //   Constant: '<S172>/Constant1'
    //   Sqrt: '<S172>/sqrt'

    rtb_Switch_m2 = 6.378137E+6 / std::sqrt(rtb_Abs1);

    // Product: '<S157>/dNorth' incorporates:
    //   Constant: '<S172>/Constant2'
    //   Product: '<S172>/Product3'
    //   Trigonometry: '<S172>/Trigonometric Function1'

    rtb_Abs1 = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_m2 *
        0.99330562000985867 / rtb_Abs1);

    // Product: '<S157>/dEast' incorporates:
    //   Constant: '<S172>/Constant3'
    //   Product: '<S172>/Product4'
    //   Trigonometry: '<S172>/Trigonometric Function'
    //   Trigonometry: '<S172>/Trigonometric Function2'
    //   UnitConversion: '<S173>/Unit Conversion'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Switch_m2 = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_m2 * std::cos
        (rtb_Switch_tmp)) * rtb_Sum1_idx_1;

    // Sum: '<S157>/Sum2' incorporates:
    //   Product: '<S157>/x*cos'
    //   Product: '<S157>/y*sin'

    rtb_Switch = rtb_Switch_m2 * 0.0 + rtb_Abs1;

    // Sum: '<S157>/Sum3' incorporates:
    //   Product: '<S157>/x*sin'
    //   Product: '<S157>/y*cos'

    rtb_Py_n = rtb_Switch_m2 - rtb_Abs1 * 0.0;

    // Gain: '<S2>/Down2Up' incorporates:
    //   DataStoreRead: '<S2>/AltitudeGCS'
    //   Gain: '<S2>/inverse'
    //   Sum: '<S154>/Sum'

    rtb_Up = rtu_RealUAVState->Height_meter + -AltitudeGCS;

    // Gain: '<S151>/Gain1'
    rtb_Abs1 = 0.017453292519943295 * rtu_RealUAVState->HeadingAngle_deg;

    // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
    // Gain: '<S3>/Gain2' incorporates:
    //   BusCreator: '<S2>/FixedWingGuidanceStateBus'

    rtb_Down = -rtb_Up;

    // End of Outputs for SubSystem: '<Root>/RealState2Pose'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
    //   Concatenate: '<S63>/Matrix Concatenate'
    //   Constant: '<S111>/Constant'
    //   Constant: '<S111>/ControlHdg'
    //   Constant: '<S111>/ControlSpd'
    //   Constant: '<S111>/InitTrigger'
    //   Constant: '<S111>/ShiftSimUAV'
    //   Constant: '<S138>/Constant'
    //   Constant: '<S138>/ControlHdg'
    //   Constant: '<S138>/ControlSpd'
    //   Constant: '<S145>/Constant'
    //   Constant: '<S145>/ControlHdg'
    //   Constant: '<S145>/ControlSpd'
    //   Constant: '<S23>/ControlHdg'
    //   Constant: '<S23>/ControlSpd'
    //   Constant: '<S23>/ShiftSimUAV'
    //   Constant: '<S4>/ShiftSimUAV'
    //   Constant: '<S53>/ControlHdg'
    //   Constant: '<S53>/ControlSpd'
    //   Constant: '<S57>/InitTrigger'
    //   Constant: '<S57>/ShiftSimUAV'
    //   Gain: '<S138>/Gravity'
    //   Gain: '<S14>/Gravity'
    //   Gain: '<S152>/Gain1'
    //   Gain: '<S153>/Gain1'
    //   MATLAB Function: '<S63>/BaseWayPoint'
    //   MATLABSystem: '<S57>/Waypoint Follower'
    //   Product: '<S138>/HorizSpd'
    //   Product: '<S14>/HorizSpd'
    //   Trigonometry: '<S138>/Cos'
    //   Trigonometry: '<S138>/Tan'
    //   Trigonometry: '<S14>/Cos'
    //   Trigonometry: '<S14>/Tan'

    rtPrevAction = localDW->SwitchCase_ActiveSubsystem;
    switch (localDW->ImmedMission_a) {
      case MissionModes::DetailedInsp:
        rtAction = 0;
        break;

      case MissionModes::FlightMissionRH:
        rtAction = 1;
        break;

      case MissionModes::SqCalibr:
        rtAction = 2;
        break;

      case MissionModes::pAttack:
        rtAction = 3;
        break;

      case MissionModes::ShiftEarthENU:
        rtAction = 4;
        break;

      case MissionModes::ShiftBodyXYZ:
        rtAction = 5;
        break;

      default:
        rtAction = 6;
        break;
    }

    localDW->SwitchCase_ActiveSubsystem = rtAction;
    if (static_cast<int32_T>(rtPrevAction) != static_cast<int32_T>(rtAction)) {
        // Disable for Atomic SubSystem: '<S145>/SailDistance'
        // Disable for Enabled SubSystem: '<S147>/SailShift'
        localDW->SailShift_MODE = static_cast<boolean_T>(static_cast<int32_T>((
            static_cast<int32_T>(rtPrevAction) != 4) & static_cast<int32_T>
            (localDW->SailShift_MODE)));

        // End of Disable for SubSystem: '<S147>/SailShift'
        // End of Disable for SubSystem: '<S145>/SailDistance'
    }

    switch (rtAction) {
      case 0:
        {
            real_T rtb_Sum_ow;
            real_T rtb_Switch_k;
            real_T rtb_TmpSignalConversionAtOrbitF_tmp;
            real_T stateNew_idx_5;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // SystemReset for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
                //   ActionPort: '<S5>/Action Port'

                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S23>/HdgHoldLogic'
                //   MATLABSystem: '<S23>/Orbit Follower'

                localDW->temporalCounter_i1_p = 0U;
                localDW->is_active_c1_ImmedMission = 0U;
                localDW->is_c1_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
                localDW->obj_c.OrbitRadiusInternal = (rtNaN);
                localDW->obj_c.PrevResetSignal *= 0.0;
                localDW->obj_c.NumCircles *= 0.0;
                localDW->obj_c.OrbitCenterInternal[0] = (rtNaN);
                localDW->obj_c.PrevPosition[0] *= 0.0;
                localDW->obj_c.OrbitCenterInternal[1] = (rtNaN);
                localDW->obj_c.PrevPosition[1] *= 0.0;
                localDW->obj_c.OrbitCenterInternal[2] = (rtNaN);
                localDW->obj_c.PrevPosition[2] *= 0.0;
                localDW->obj_c.StartFlag = true;
                localDW->obj_c.SelectTurnDirectionFlag = true;
                localDW->obj_c.TurnDirectionInternal = 1.0;

                // End of SystemReset for SubSystem: '<S1>/Mode128_DetailedInsp' 
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
            //   ActionPort: '<S5>/Action Port'

            // Sum: '<S28>/Sum1' incorporates:
            //   DataStoreRead: '<S23>/LatitudeGCS'
            //   Switch: '<S43>/Switch'

            rtb_Sum1_idx_0 = rtu_MissionInput->MissionLocation.Lat - LatitudeGCS;

            // Switch: '<S37>/Switch' incorporates:
            //   Abs: '<S37>/Abs'
            //   Bias: '<S37>/Bias'
            //   Bias: '<S37>/Bias1'
            //   Constant: '<S37>/Constant2'
            //   Constant: '<S38>/Constant'
            //   Math: '<S37>/Math Function1'
            //   RelationalOperator: '<S38>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                rtb_Switch_k = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) +
                    -180.0;
            } else {
                rtb_Switch_k = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S37>/Switch'

            // Abs: '<S34>/Abs1'
            rtb_Sum1_idx_0 = std::abs(rtb_Switch_k);

            // Switch: '<S34>/Switch' incorporates:
            //   Bias: '<S34>/Bias'
            //   Bias: '<S34>/Bias1'
            //   Constant: '<S30>/Constant'
            //   Constant: '<S30>/Constant1'
            //   Constant: '<S36>/Constant'
            //   Gain: '<S34>/Gain'
            //   Product: '<S34>/Divide1'
            //   RelationalOperator: '<S36>/Compare'
            //   Switch: '<S30>/Switch1'

            if (rtb_Sum1_idx_0 > 90.0) {
                // Signum: '<S34>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Switch_k)) ^ 1))) {
                    if (rtb_Switch_k < 0.0) {
                        rtb_Switch_k = -1.0;
                    } else {
                        rtb_Switch_k = static_cast<real_T>(rtb_Switch_k > 0.0);
                    }
                }

                // End of Signum: '<S34>/Sign1'
                rtb_Switch_k *= -(rtb_Sum1_idx_0 + -90.0) + 90.0;
                nm1d2 = 180;
            } else {
                nm1d2 = 0;
            }

            // End of Switch: '<S34>/Switch'

            // Sum: '<S30>/Sum' incorporates:
            //   DataStoreRead: '<S23>/LongitudeGCS'
            //   Sum: '<S28>/Sum1'
            //   Sum: '<S31>/Sum'

            rtb_Sum_ow = (rtu_MissionInput->MissionLocation.Lon - LongitudeGCS)
                + static_cast<real_T>(nm1d2);

            // Switch: '<S35>/Switch' incorporates:
            //   Abs: '<S35>/Abs'
            //   Bias: '<S35>/Bias'
            //   Bias: '<S35>/Bias1'
            //   Constant: '<S35>/Constant2'
            //   Constant: '<S39>/Constant'
            //   Math: '<S35>/Math Function1'
            //   RelationalOperator: '<S39>/Compare'

            if (std::abs(rtb_Sum_ow) > 180.0) {
                rtb_Sum_ow = rt_modd_snf(rtb_Sum_ow + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S35>/Switch'

            // UnitConversion: '<S33>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Switch_k;
            rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_ow;

            // Trigonometry: '<S49>/Trigonometric Function1'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum_ow = std::sin(rtb_Switch_tmp);

            // Sum: '<S49>/Sum1' incorporates:
            //   Constant: '<S49>/Constant'
            //   Product: '<S49>/Product1'

            rtb_Sum_ow = 1.0 - 0.0066943799901413295 * rtb_Sum_ow * rtb_Sum_ow;

            // Product: '<S47>/Product1' incorporates:
            //   Constant: '<S47>/Constant1'
            //   Sqrt: '<S47>/sqrt'

            rtb_Switch_k = 6.378137E+6 / std::sqrt(rtb_Sum_ow);

            // Product: '<S32>/dNorth' incorporates:
            //   Constant: '<S47>/Constant2'
            //   Product: '<S47>/Product3'
            //   Trigonometry: '<S47>/Trigonometric Function1'

            rtb_Sum_ow = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_k *
                0.99330562000985867 / rtb_Sum_ow);

            // UnitConversion: '<S46>/Unit Conversion' incorporates:
            //   Constant: '<S23>/AngleLLA'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Up = 0.0;

            // Product: '<S32>/dEast' incorporates:
            //   Constant: '<S47>/Constant3'
            //   Product: '<S47>/Product4'
            //   Trigonometry: '<S47>/Trigonometric Function'
            //   Trigonometry: '<S47>/Trigonometric Function2'

            rtb_Switch_k = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_k * std::cos
                (rtb_Switch_tmp)) * rtb_Sum1_idx_1;

            // SignalConversion generated from: '<S23>/Orbit Follower' incorporates:
            //   DataStoreRead: '<S23>/AltitudeGCS'
            //   Gain: '<S23>/inverse'
            //   Product: '<S32>/x*cos'
            //   Product: '<S32>/x*sin'
            //   Product: '<S32>/y*cos'
            //   Product: '<S32>/y*sin'
            //   Sum: '<S28>/Sum'
            //   Sum: '<S32>/Sum2'
            //   Sum: '<S32>/Sum3'
            //   UnaryMinus: '<S28>/Ze2height'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Switch_k *
                0.0 + rtb_Sum_ow;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Switch_k -
                rtb_Sum_ow * 0.0;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                -(rtu_MissionInput->MissionLocation.Alt + -AltitudeGCS);

            // Sum: '<S24>/Sum' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'

            rtb_Sum_gu[0] = rtb_Switch -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
            rtb_Sum_gu[1] = rtb_Py_n -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
            rtb_Sum_gu[2] = rtb_Down -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Sqrt: '<S24>/sqrt' incorporates:
            //   DotProduct: '<S24>/Dot Product'

            rtb_Sum1_idx_0 = std::sqrt((rtb_Sum_gu[0] * rtb_Sum_gu[0] +
                rtb_Sum_gu[1] * rtb_Sum_gu[1]) + rtb_Sum_gu[2] * rtb_Sum_gu[2]);

            // Chart: '<S23>/HdgHoldLogic' incorporates:
            //   DataTypeConversion: '<S23>/Param2'
            //   DataTypeConversion: '<S23>/Param3'

            if (static_cast<uint32_T>(localDW->temporalCounter_i1_p) < 31U) {
                localDW->temporalCounter_i1_p = static_cast<uint8_T>(
                    static_cast<uint32_T>(static_cast<uint32_T>
                    (localDW->temporalCounter_i1_p) + 1U));
            }

            // Gateway: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
            // During: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
            if (static_cast<uint32_T>(localDW->is_active_c1_ImmedMission) == 0U)
            {
                // Entry: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
                localDW->is_active_c1_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
                // Transition: '<S27>:4'
                if (rtb_Sum1_idx_0 >= static_cast<real_T>
                        (rtu_MissionInput->params.Param3)) {
                    // Transition: '<S27>:26'
                    localDW->is_c1_ImmedMission = ImmedMission_IN_OutOfRange;

                    // Entry 'OutOfRange': '<S27>:11'
                    rtb_Sum1_idx_0 = 1.0;
                } else {
                    // Transition: '<S27>:27'
                    localDW->is_c1_ImmedMission = ImmedMission_IN_WithInRange;

                    // Entry 'WithInRange': '<S27>:9'
                    rtb_Sum1_idx_0 = 0.0;
                }
            } else {
                switch (localDW->is_c1_ImmedMission) {
                  case ImmedMission_IN_OutOfRange:
                    // During 'OutOfRange': '<S27>:11'
                    if (rtb_Sum1_idx_0 < static_cast<real_T>
                            (rtu_MissionInput->params.Param2)) {
                        // Transition: '<S27>:15'
                        localDW->is_c1_ImmedMission =
                            ImmedMission_IN_WithInRange;

                        // Entry 'WithInRange': '<S27>:9'
                        rtb_Sum1_idx_0 = 0.0;
                    } else {
                        rtb_Sum1_idx_0 = 1.0;
                    }
                    break;

                  case ImmedMission_IN_Turning:
                    // During 'Turning': '<S27>:23'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i1_p) >=
                            20U) {
                        // Transition: '<S27>:24'
                        localDW->is_c1_ImmedMission = ImmedMission_IN_OutOfRange;

                        // Entry 'OutOfRange': '<S27>:11'
                        rtb_Sum1_idx_0 = 1.0;
                    } else {
                        rtb_Sum1_idx_0 = 2.0;
                    }
                    break;

                  default:
                    // During 'WithInRange': '<S27>:9'
                    if (rtb_Sum1_idx_0 >= static_cast<real_T>
                            (rtu_MissionInput->params.Param3)) {
                        // Transition: '<S27>:14'
                        localDW->is_c1_ImmedMission = ImmedMission_IN_Turning;
                        localDW->temporalCounter_i1_p = 0U;

                        // Entry 'Turning': '<S27>:23'
                        rtb_Sum1_idx_0 = 2.0;
                    } else {
                        rtb_Sum1_idx_0 = 0.0;
                    }
                    break;
                }
            }

            // End of Chart: '<S23>/HdgHoldLogic'

            // DataTypeConversion: '<S23>/DoubleStatus'
            *rty_TaskStatus = rtb_Sum1_idx_0;

            // SignalConversion generated from: '<S23>/Orbit Follower' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'

            rtb_Sum_ow = rtb_Switch;
            rtb_Switch_k = rtb_Py_n;
            rtb_Sum1_idx_1 = rtb_Down;
            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 = rtb_Abs1;

            // Signum: '<S23>/Sign' incorporates:
            //   DataTypeConversion: '<S23>/DoubleTurnDir'

            if (static_cast<real_T>(rtu_MissionInput->FormationPos) < 0.0) {
                rtb_Switch = -1.0;
            } else {
                rtb_Switch = static_cast<real_T>(static_cast<real_T>
                    (rtu_MissionInput->FormationPos) > 0.0);
            }

            // End of Signum: '<S23>/Sign'

            // MATLABSystem: '<S23>/Orbit Follower' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   DataTypeConversion: '<S23>/DoubleParam4'

            localDW->obj_c.OrbitRadiusFlag = 1U;
            rtb_Down = static_cast<real_T>(rtu_MissionInput->params.Param1);
            localDW->obj_c.LookaheadDistFlag = 0U;
            if (static_cast<real_T>(rtu_MissionInput->params.Param1) < 0.1) {
                rtb_Down = 0.1;
                localDW->obj_c.LookaheadDistFlag = 1U;
            }

            rtb_TmpSignalConversionAtOrbitF_tmp = rtb_Sum_ow -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
            rtb_TmpSignalConversionAtOrbitF[0] =
                rtb_TmpSignalConversionAtOrbitF_tmp;
            stateNew_idx_5 = rtb_Py_n -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
            rtb_TmpSignalConversionAtOrbitF[1] = stateNew_idx_5;
            if (ImmedMission_norm_p(rtb_TmpSignalConversionAtOrbitF) <
                    2.47032822920623E-323) {
                rtb_Sum_gu[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
            } else {
                real_T lambda_tmp_tmp;
                boolean_T exitg1;
                boolean_T guard1{ false };

                boolean_T rtb_Ctrl;
                rtb_Compare_lh = false;
                rtb_Ctrl = true;
                nm1d2 = 0;
                exitg1 = false;
                while ((!exitg1) && (nm1d2 < 3)) {
                    if ((localDW->obj_c.OrbitCenterInternal[nm1d2] ==
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2])
                        || (std::isnan(localDW->obj_c.OrbitCenterInternal[nm1d2])
                            && std::isnan
                            (rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2])))
                    {
                        nm1d2 = static_cast<int32_T>(nm1d2 + 1);
                    } else {
                        rtb_Ctrl = false;
                        exitg1 = true;
                    }
                }

                if (rtb_Ctrl) {
                    rtb_Compare_lh = true;
                }

                if ((static_cast<boolean_T>(static_cast<int32_T>
                                            (static_cast<int32_T>(rtb_Compare_lh)
                       ^ 1))) || (!(localDW->obj_c.OrbitRadiusInternal == 0.1)))
                {
                    localDW->obj_c.NumCircles = 0.0;
                    localDW->obj_c.OrbitCenterInternal[0] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                    localDW->obj_c.OrbitCenterInternal[1] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                    localDW->obj_c.OrbitCenterInternal[2] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                    localDW->obj_c.OrbitRadiusInternal = 0.1;
                    localDW->obj_c.SelectTurnDirectionFlag = true;
                }

                if (rtb_Down >= 0.1) {
                    localDW->obj_c.LookaheadDistance = 0.090000000000000011;
                } else {
                    localDW->obj_c.LookaheadDistance = rtb_Down;
                }

                distToCenter_tmp[0] = rtb_TmpSignalConversionAtOrbitF_tmp;
                distToCenter_tmp[1] = stateNew_idx_5;
                rtb_Switch_m2 = std::sqrt(stateNew_idx_5 * stateNew_idx_5 +
                    rtb_TmpSignalConversionAtOrbitF_tmp *
                    rtb_TmpSignalConversionAtOrbitF_tmp);
                rtb_Down = std::abs(localDW->obj_c.LookaheadDistance + 0.1);
                rtb_Compare_lh = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(std::isinf(rtb_Down)) ^ 1));
                rtb_Ctrl = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(std::isnan(rtb_Down)) ^ 1));
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rtb_Compare_lh)
                      & static_cast<int32_T>(rtb_Ctrl)))) {
                    if (rtb_Down <= 2.2250738585072014E-308) {
                        rtb_Py_n = 4.94065645841247E-324;
                    } else {
                        frexp(rtb_Down, &rtb_BiasOldIdx);
                        rtb_Py_n = std::ldexp(1.0, static_cast<int32_T>
                                              (rtb_BiasOldIdx - 53));
                    }
                } else {
                    rtb_Py_n = (rtNaN);
                }

                guard1 = false;
                if (rtb_Switch_m2 >= (localDW->obj_c.LookaheadDistance + 0.1) -
                        5.0 * rtb_Py_n) {
                    guard1 = true;
                } else {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               (static_cast<int32_T>
                                                (rtb_Compare_lh) &
                                                static_cast<int32_T>(rtb_Ctrl))))
                    {
                        if (rtb_Down <= 2.2250738585072014E-308) {
                            rtb_Py_n = 4.94065645841247E-324;
                        } else {
                            frexp(rtb_Down, &colIdx);
                            rtb_Py_n = std::ldexp(1.0, static_cast<int32_T>
                                                  (colIdx - 53));
                        }
                    } else {
                        rtb_Py_n = (rtNaN);
                    }

                    if (rtb_Switch_m2 <= (0.1 - localDW->obj_c.LookaheadDistance)
                        + 5.0 * rtb_Py_n) {
                        guard1 = true;
                    } else {
                        real_T rtb_Switch_p_tmp;
                        real_T stateNew_idx_2;
                        if (localDW->obj_c.StartFlag) {
                            localDW->obj_c.PrevPosition[0] = rtb_Sum_ow;
                            localDW->obj_c.PrevPosition[1] = rtb_Switch_k;
                            localDW->obj_c.StartFlag = false;
                        }

                        rtb_TmpSignalConversionAtOrbitF[0] =
                            rtb_TmpSignalConversionAtOrbitF_tmp;
                        rtb_TmpSignalConversionAtOrbitF[1] = stateNew_idx_5;
                        rtb_Py_n = ImmedMission_norm_p
                            (rtb_TmpSignalConversionAtOrbitF);
                        stateNew_idx_2 = localDW->obj_c.LookaheadDistance *
                            localDW->obj_c.LookaheadDistance;
                        rtb_Abs1 = ((stateNew_idx_2 - 0.010000000000000002) +
                                    rtb_Py_n * rtb_Py_n) / (2.0 * rtb_Py_n);
                        rtb_Switch_tmp =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] -
                            rtb_Sum_ow;
                        rtb_Down = rtb_Switch_tmp * rtb_Abs1 / rtb_Py_n +
                            rtb_Sum_ow;
                        rtb_Switch_p_tmp =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] -
                            rtb_Switch_k;
                        rtb_Switch_m2 = rtb_Switch_p_tmp * rtb_Abs1 / rtb_Py_n +
                            rtb_Switch_k;
                        rtb_Abs1 = std::sqrt(stateNew_idx_2 - rtb_Abs1 *
                                             rtb_Abs1);
                        stateNew_idx_2 = rtb_Switch_p_tmp * rtb_Abs1 / rtb_Py_n;
                        distToCenter_tmp[0] = rtb_Down - stateNew_idx_2;
                        distToCenter_tmp[1] = stateNew_idx_2 + rtb_Down;
                        rtb_Abs1 = rtb_Switch_tmp * rtb_Abs1 / rtb_Py_n;
                        rtb_Down = rtb_Abs1 + rtb_Switch_m2;
                        xyCenter_idx_1 = rtb_Switch_m2 - rtb_Abs1;
                        if ((rtb_Switch == 0.0) && (static_cast<boolean_T>(
                                static_cast<int32_T>(static_cast<int32_T>
                                (localDW->obj_c.SelectTurnDirectionFlag) ^ 1))))
                        {
                            rtb_Abs1 = localDW->obj_c.TurnDirectionInternal;
                        } else {
                            rtb_Abs1 = rtb_Switch;
                        }

                        stateNew_idx_2 = localDW->obj_c.PrevPosition[0] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                        rtb_Switch_m2 = localDW->obj_c.PrevPosition[1] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                        rtb_Sum_gu[0] = stateNew_idx_2;
                        rtb_Sum_gu[1] = rtb_Switch_m2;
                        rtb_Sum_gu[2] = 0.0;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                            rtb_TmpSignalConversionAtOrbitF_tmp;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                            stateNew_idx_5;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                            0.0;
                        if (rtb_Abs1 < 0.0) {
                            rtb_Sum_gu[0] = rtb_TmpSignalConversionAtOrbitF_tmp;
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]
                                = stateNew_idx_2;
                            rtb_Sum_gu[1] = stateNew_idx_5;
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1]
                                = rtb_Switch_m2;
                            rtb_Sum_gu[2] = 0.0;
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2]
                                = 0.0;
                        }

                        lambda_tmp_tmp = ImmedMission_norm_pv(rtb_Sum_gu);
                        rtb_Switch_m2 = ImmedMission_norm_pv
                            (rtb_TmpSignalConversionAtRotateATMissionHdgInport1);
                        stateNew_idx_2 = rtb_Sum_gu[0] / lambda_tmp_tmp;
                        stateNew_idx_5 =
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]
                            / rtb_Switch_m2;
                        rtb_Py_n = rtb_Sum_gu[1] / lambda_tmp_tmp;
                        rtb_TmpSignalConversionAtOrbitF_tmp =
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1]
                            / rtb_Switch_m2;
                        localDW->obj_c.PrevPosition[0] = rtb_Sum_ow;
                        localDW->obj_c.PrevPosition[1] = rtb_Switch_k;
                        localDW->obj_c.PrevPosition[2] = rtb_Sum1_idx_1;
                        localDW->obj_c.NumCircles += rt_atan2d_snf
                            (stateNew_idx_2 *
                             rtb_TmpSignalConversionAtOrbitF_tmp -
                             stateNew_idx_5 * rtb_Py_n, (stateNew_idx_2 *
                              stateNew_idx_5 + rtb_Py_n *
                              rtb_TmpSignalConversionAtOrbitF_tmp) + 0.0 /
                             lambda_tmp_tmp * (0.0 / rtb_Switch_m2)) / 2.0 /
                            3.1415926535897931;
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(std::isnan(rtb_Abs1)) ^ 1)))
                        {
                            if (rtb_Abs1 < 0.0) {
                                rtb_Abs1 = -1.0;
                            } else {
                                rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                            }
                        }

                        switch (static_cast<int32_T>(rtb_Abs1)) {
                          case 1:
                            if ((distToCenter_tmp[0] - rtb_Sum_ow) *
                                    rtb_Switch_p_tmp - (rtb_Down - rtb_Switch_k)
                                * rtb_Switch_tmp > 0.0) {
                                rtb_Abs1 = distToCenter_tmp[0];
                                xyCenter_idx_1 = rtb_Down;
                            } else {
                                rtb_Abs1 = distToCenter_tmp[1];
                            }
                            break;

                          case -1:
                            if ((distToCenter_tmp[0] - rtb_Sum_ow) *
                                    rtb_Switch_p_tmp - (rtb_Down - rtb_Switch_k)
                                * rtb_Switch_tmp < 0.0) {
                                rtb_Abs1 = distToCenter_tmp[0];
                                xyCenter_idx_1 = rtb_Down;
                            } else {
                                rtb_Abs1 = distToCenter_tmp[1];
                            }
                            break;

                          default:
                            if (std::abs(ImmedMission_angdiff(rt_atan2d_snf
                                    (rtb_Down - rtb_Switch_k, distToCenter_tmp[0]
                                     - rtb_Sum_ow),
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3))
                                < std::abs(ImmedMission_angdiff(rt_atan2d_snf
                                    (xyCenter_idx_1 - rtb_Switch_k,
                                     distToCenter_tmp[1] - rtb_Sum_ow),
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3)))
                            {
                                rtb_Abs1 = distToCenter_tmp[0];
                                xyCenter_idx_1 = rtb_Down;
                            } else {
                                rtb_Abs1 = distToCenter_tmp[1];
                            }

                            if ((rtb_Abs1 - rtb_Sum_ow) * rtb_Switch_p_tmp -
                                    (xyCenter_idx_1 - rtb_Switch_k) *
                                    rtb_Switch_tmp > 0.0) {
                                localDW->obj_c.TurnDirectionInternal = 1.0;
                            } else {
                                localDW->obj_c.TurnDirectionInternal = -1.0;
                            }

                            localDW->obj_c.SelectTurnDirectionFlag = false;
                            break;
                        }
                    }
                }

                if (guard1) {
                    lambda_tmp_tmp = ImmedMission_norm_p(distToCenter_tmp);
                    rtb_Abs1 = rtb_TmpSignalConversionAtOrbitF_tmp /
                        lambda_tmp_tmp * 0.1 +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                    xyCenter_idx_1 = stateNew_idx_5 / lambda_tmp_tmp * 0.1 +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                }

                rtb_Sum_gu[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                rtb_Abs1 = rt_atan2d_snf(xyCenter_idx_1 - rtb_Switch_k, rtb_Abs1
                    - rtb_Sum_ow);
            }

            // Outputs for Enabled SubSystem: '<S23>/FeedthroughHDG' incorporates:
            //   EnablePort: '<S26>/Enable'

            if (rtb_Sum1_idx_0 > 0.0) {
                // SignalConversion generated from: '<S26>/OrbitNavHdg' incorporates:
                //   MATLABSystem: '<S23>/Orbit Follower'

                localDW->OrbitNavHdg = rtb_Abs1;
            }

            // End of Outputs for SubSystem: '<S23>/FeedthroughHDG'

            // Switch: '<S23>/Switch' incorporates:
            //   Constant: '<S23>/Constant'
            //   Constant: '<S29>/Constant'
            //   Product: '<S23>/Product'
            //   RelationalOperator: '<S29>/Compare'

            if (rtb_Sum1_idx_0 == 2.0) {
                rtb_Up = 2.3561944901923448 * rtb_Switch;
            }

            // End of Switch: '<S23>/Switch'

            // BusCreator: '<S23>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S23>/DoubleTurnDir'
            //   DataTypeConversion: '<S23>/Param4'
            //   Gain: '<S23>/Down2Height'
            //   Gain: '<S23>/Gain'
            //   Gain: '<S23>/GainLayering'
            //   MATLABSystem: '<S23>/Orbit Follower'
            //   Sum: '<S23>/Minus'
            //   Sum: '<S23>/Sum'
            //   Sum: '<S23>/SumHeight'

            rty_GuidanceCMD->Height = -((static_cast<real_T>
                (rtu_MissionInput->FormationPos) - 0.5 * rtb_Switch) * 20.0 +
                rtb_Sum_gu[2]);
            rty_GuidanceCMD->AirSpeed = static_cast<real_T>
                (rtu_MissionInput->params.Param4);
            rty_GuidanceCMD->HeadingAngle = rtb_Up + localDW->OrbitNavHdg;
            rtb_Compare_lh = false;
            rty_ControlSwitch[0] = true;
            rty_ControlSwitch[1] = true;

            // End of Outputs for SubSystem: '<S1>/Mode128_DetailedInsp'
        }
        break;

      case 1:
        // Outputs for IfAction SubSystem: '<S1>/Mode130_FlightMissionRH' incorporates:
        //   ActionPort: '<S6>/Action Port'

        rty_ControlSwitch[0] = false;
        rty_ControlSwitch[1] = false;

        // Bias: '<S53>/BiasNumUAV' incorporates:
        //   Constant: '<S53>/ControlHdg'
        //   Constant: '<S53>/ControlSpd'

        rtb_BiasNumUAV = *rtu_FlightMission_numUAV;

        // Bias: '<S53>/BiasOldIdx'
        rtb_BiasOldIdx = *rtu_FlightMission_FormationPos;

        // Gain: '<S54>/Gain1'
        rtb_Switch = 0.017453292519943295 *
            *rtu_FlightMission_MissionLocation_degHDG;

        // Bias: '<S53>/Rotate90deg'
        rtb_Py_n = rtb_Switch + 1.5707963267948966;

        // Sum: '<S53>/Minus' incorporates:
        //   Bias: '<S53>/BiasMissionUAV'
        //   Bias: '<S53>/BiasNewIdx'
        //   Bias: '<S53>/BiasNumUAV'
        //   Bias: '<S53>/BiasOldIdx'
        //   DataTypeConversion: '<S53>/DoubleTurnDir'
        //   DataTypeConversion: '<S53>/Param3'
        //   Product: '<S53>/Divide'
        //   Product: '<S53>/ProductNewShift'
        //   Product: '<S53>/ProductOldShift'
        //   Product: '<S53>/ProductScanWidth'

        rtb_Switch = static_cast<real_T>(static_cast<int32_T>(rtb_BiasNumUAV - 1))
            * static_cast<real_T>(*rtu_FlightMission_params_Param3) /
            static_cast<real_T>(static_cast<int32_T>(rtu_MissionInput->numUAV -
            1)) * (static_cast<real_T>(rtu_MissionInput->FormationPos) + -1.0) -
            static_cast<real_T>(static_cast<int32_T>(rtb_BiasOldIdx - 1)) *
            static_cast<real_T>(*rtu_FlightMission_params_Param3);

        // Sum: '<S53>/SumNorth' incorporates:
        //   Product: '<S53>/ProductNorth'
        //   Trigonometry: '<S53>/Cos'

        rtb_Abs1 = std::cos(rtb_Py_n) * rtb_Switch + rtu_SimUAVstate->North;

        // Sum: '<S53>/SumEast' incorporates:
        //   Product: '<S53>/ProductEast'
        //   Trigonometry: '<S53>/Sin'

        rtb_Switch = std::sin(rtb_Py_n) * rtb_Switch + rtu_SimUAVstate->East;

        // DataTypeConversion: '<S53>/DoubleFormPos'
        rtb_Py_n = static_cast<real_T>(*rtu_FlightMission_FormationPos);

        // Sum: '<S53>/SumHeight' incorporates:
        //   Bias: '<S53>/NewBias'
        //   Bias: '<S53>/OldBias'
        //   Constant: '<S53>/Three'
        //   DataTypeConversion: '<S53>/DoubleTurnDir'
        //   Gain: '<S53>/Gain'
        //   Math: '<S53>/NewMod'
        //   Math: '<S53>/OldMod'
        //   Sum: '<S53>/MinusLayer'

        rtb_Py_n = (rt_modd_snf(static_cast<real_T>
                                (rtu_MissionInput->FormationPos) + -1.0, 3.0) -
                    rt_modd_snf(rtb_Py_n + -1.0, 3.0)) * 15.0 +
            rtu_SimUAVstate->Height;

        // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
        //   BusAssignment: '<S53>/Bus Assignment'

        localDW->MergeCollAvoidSimUAV = *rtu_SimUAVstate;

        // BusAssignment: '<S53>/Bus Assignment'
        localDW->MergeCollAvoidSimUAV.North = rtb_Abs1;
        localDW->MergeCollAvoidSimUAV.East = rtb_Switch;
        localDW->MergeCollAvoidSimUAV.Height = rtb_Py_n;

        // RelationalOperator: '<S55>/Compare' incorporates:
        //   Constant: '<S55>/Constant'

        rtb_Compare_lh = (*rtu_FlightMission_MissionMode == MissionModes::
                          HorzScanNav);

        // DataTypeConversion: '<S53>/DoubleStatus'
        *rty_TaskStatus = static_cast<real_T>(rtb_Compare_lh);

        // End of Outputs for SubSystem: '<S1>/Mode130_FlightMissionRH'
        break;

      case 2:
        {
            real_T rtb_Sum_ow;
            real_T rtb_Switch_k;
            real_T stateNew_idx_2;
            int32_T b_ibmat;
            int32_T boffset;
            int32_T coffset;
            boolean_T exitg1;
            boolean_T rtb_Ctrl;
            ZCEventType zcEvent;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FILE* a;

                // SystemReset for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
                //   ActionPort: '<S7>/Action Port'

                // SystemReset for Triggered SubSystem: '<S57>/WayPointGen'
                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S57>/TriggerCalibrStart'
                //   MATLAB Function: '<S63>/BaseWayPoint'
                //   MATLABSystem: '<S57>/Waypoint Follower'

                localDW->SingletonInstance_not_empty = false;
                a = NULL;
                for (colIdx = 0; colIdx < 20; colIdx++) {
                    localDW->eml_openfiles[colIdx] = a;
                }

                localZCE->WayPointGen_Trig_ZCE_d = NEG_ZCSIG;

                // End of SystemReset for SubSystem: '<S57>/WayPointGen'
                localDW->obj.WaypointIndex = 1.0;
                for (colIdx = 0; colIdx < 30723; colIdx++) {
                    localDW->obj.WaypointsInternal[colIdx] = (rtNaN);
                }

                localDW->is_active_c7_ImmedMission = 0U;
                localDW->is_c7_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;

                // End of SystemReset for SubSystem: '<S1>/Mode131_SqCalibr'
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S7>/Action Port'

            // Sum: '<S86>/Sum1' incorporates:
            //   DataStoreRead: '<S61>/PrevLatitudeGCS'
            //   DataStoreRead: '<S61>/PrevLongitudeGCS'
            //   Sum: '<S88>/Sum'
            //   Switch: '<S100>/Switch'

            rtb_Sum1_idx_0 = *rtu_FlightMission_MissionLocation_Lat -
                LatitudeGCS;
            rtb_Sum1_idx_1 = *rtu_FlightMission_MissionLocation_Lon -
                LongitudeGCS;

            // Switch: '<S94>/Switch' incorporates:
            //   Abs: '<S94>/Abs'
            //   Bias: '<S94>/Bias'
            //   Bias: '<S94>/Bias1'
            //   Constant: '<S94>/Constant2'
            //   Constant: '<S95>/Constant'
            //   Math: '<S94>/Math Function1'
            //   RelationalOperator: '<S95>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                rtb_Switch_m2 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) +
                    -180.0;
            } else {
                rtb_Switch_m2 = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S94>/Switch'

            // Abs: '<S91>/Abs1'
            rtb_Sum1_idx_0 = std::abs(rtb_Switch_m2);

            // Switch: '<S91>/Switch' incorporates:
            //   Bias: '<S91>/Bias'
            //   Bias: '<S91>/Bias1'
            //   Constant: '<S87>/Constant'
            //   Constant: '<S87>/Constant1'
            //   Constant: '<S93>/Constant'
            //   Gain: '<S91>/Gain'
            //   Product: '<S91>/Divide1'
            //   RelationalOperator: '<S93>/Compare'
            //   Switch: '<S87>/Switch1'

            if (rtb_Sum1_idx_0 > 90.0) {
                // Signum: '<S91>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Switch_m2)) ^ 1))) {
                    if (rtb_Switch_m2 < 0.0) {
                        rtb_Switch_m2 = -1.0;
                    } else {
                        rtb_Switch_m2 = static_cast<real_T>(rtb_Switch_m2 > 0.0);
                    }
                }

                // End of Signum: '<S91>/Sign1'
                rtb_Switch_m2 *= -(rtb_Sum1_idx_0 + -90.0) + 90.0;
                nm1d2 = 180;
            } else {
                nm1d2 = 0;
            }

            // End of Switch: '<S91>/Switch'

            // Sum: '<S87>/Sum'
            rtb_Sum_ow = static_cast<real_T>(nm1d2) + rtb_Sum1_idx_1;

            // Switch: '<S92>/Switch' incorporates:
            //   Abs: '<S92>/Abs'
            //   Bias: '<S92>/Bias'
            //   Bias: '<S92>/Bias1'
            //   Constant: '<S92>/Constant2'
            //   Constant: '<S96>/Constant'
            //   Math: '<S92>/Math Function1'
            //   RelationalOperator: '<S96>/Compare'

            if (std::abs(rtb_Sum_ow) > 180.0) {
                rtb_Sum_ow = rt_modd_snf(rtb_Sum_ow + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S92>/Switch'

            // UnitConversion: '<S90>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Switch_m2;
            rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_ow;

            // Trigonometry: '<S106>/Trigonometric Function1'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum_ow = std::sin(rtb_Switch_tmp);

            // Sum: '<S106>/Sum1' incorporates:
            //   Constant: '<S106>/Constant'
            //   Product: '<S106>/Product1'

            rtb_Sum_ow = 1.0 - 0.0066943799901413295 * rtb_Sum_ow * rtb_Sum_ow;

            // Product: '<S104>/Product1' incorporates:
            //   Constant: '<S104>/Constant1'
            //   Sqrt: '<S104>/sqrt'

            rtb_Switch_m2 = 6.378137E+6 / std::sqrt(rtb_Sum_ow);

            // Product: '<S89>/dNorth' incorporates:
            //   Constant: '<S104>/Constant2'
            //   Product: '<S104>/Product3'
            //   Trigonometry: '<S104>/Trigonometric Function1'

            rtb_Sum_ow = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_m2 *
                0.99330562000985867 / rtb_Sum_ow);

            // Product: '<S89>/dEast' incorporates:
            //   Constant: '<S104>/Constant3'
            //   Product: '<S104>/Product4'
            //   Trigonometry: '<S104>/Trigonometric Function'
            //   Trigonometry: '<S104>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_m2 = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_m2 * std::cos
                (rtb_Switch_tmp)) * rtb_Sum1_idx_1;

            // Sum: '<S86>/Sum' incorporates:
            //   DataStoreRead: '<S61>/PrevAltitudeGCS'
            //   Gain: '<S61>/PrevInverse'

            rtb_Switch_k = *rtu_FlightMission_MissionLocation_Alt + -AltitudeGCS;

            // Reshape: '<S57>/ReshapeXe' incorporates:
            //   Product: '<S89>/x*cos'
            //   Product: '<S89>/x*sin'
            //   Product: '<S89>/y*cos'
            //   Product: '<S89>/y*sin'
            //   Sum: '<S89>/Sum2'
            //   Sum: '<S89>/Sum3'
            //   UnaryMinus: '<S86>/Ze2height'

            rtb_Sum_gu[0] = rtb_Switch_m2 * 0.0 + rtb_Sum_ow;
            rtb_Sum_gu[1] = rtb_Switch_m2 - rtb_Sum_ow * 0.0;
            rtb_Sum_gu[2] = -rtb_Switch_k;

            // Sum: '<S57>/Minus' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   Reshape: '<S57>/ReshapeXe'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Switch -
                rtb_Sum_gu[0];
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Py_n -
                rtb_Sum_gu[1];

            // Sum: '<S60>/Sum1' incorporates:
            //   DataStoreRead: '<S57>/LatitudeGCS'
            //   Switch: '<S77>/Switch'

            rtb_Sum1_idx_0 = rtu_MissionInput->MissionLocation.Lat - LatitudeGCS;

            // Switch: '<S71>/Switch' incorporates:
            //   Abs: '<S71>/Abs'
            //   Bias: '<S71>/Bias'
            //   Bias: '<S71>/Bias1'
            //   Constant: '<S71>/Constant2'
            //   Constant: '<S72>/Constant'
            //   Math: '<S71>/Math Function1'
            //   RelationalOperator: '<S72>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                rtb_Up = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
            } else {
                rtb_Up = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S71>/Switch'

            // Abs: '<S68>/Abs1'
            rtb_Sum1_idx_0 = std::abs(rtb_Up);

            // Switch: '<S68>/Switch' incorporates:
            //   Bias: '<S68>/Bias'
            //   Bias: '<S68>/Bias1'
            //   Constant: '<S64>/Constant'
            //   Constant: '<S64>/Constant1'
            //   Constant: '<S70>/Constant'
            //   Gain: '<S68>/Gain'
            //   Product: '<S68>/Divide1'
            //   RelationalOperator: '<S70>/Compare'
            //   Switch: '<S64>/Switch1'

            if (rtb_Sum1_idx_0 > 90.0) {
                // Signum: '<S68>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Up)) ^ 1))) {
                    if (rtb_Up < 0.0) {
                        rtb_Up = -1.0;
                    } else {
                        rtb_Up = static_cast<real_T>(rtb_Up > 0.0);
                    }
                }

                // End of Signum: '<S68>/Sign1'
                rtb_Up *= -(rtb_Sum1_idx_0 + -90.0) + 90.0;
                nm1d2 = 180;
            } else {
                nm1d2 = 0;
            }

            // End of Switch: '<S68>/Switch'

            // Sum: '<S64>/Sum' incorporates:
            //   DataStoreRead: '<S57>/LongitudeGCS'
            //   Sum: '<S60>/Sum1'
            //   Sum: '<S65>/Sum'

            rtb_Sum_ow = (rtu_MissionInput->MissionLocation.Lon - LongitudeGCS)
                + static_cast<real_T>(nm1d2);

            // Switch: '<S69>/Switch' incorporates:
            //   Abs: '<S69>/Abs'
            //   Bias: '<S69>/Bias'
            //   Bias: '<S69>/Bias1'
            //   Constant: '<S69>/Constant2'
            //   Constant: '<S73>/Constant'
            //   Math: '<S69>/Math Function1'
            //   RelationalOperator: '<S73>/Compare'

            if (std::abs(rtb_Sum_ow) > 180.0) {
                rtb_Sum_ow = rt_modd_snf(rtb_Sum_ow + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S69>/Switch'

            // UnitConversion: '<S67>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Up;
            rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_ow;

            // Trigonometry: '<S83>/Trigonometric Function1'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Up = std::sin(rtb_Switch_tmp);

            // Sum: '<S83>/Sum1' incorporates:
            //   Constant: '<S83>/Constant'
            //   Product: '<S83>/Product1'

            rtb_Up = 1.0 - 0.0066943799901413295 * rtb_Up * rtb_Up;

            // Product: '<S81>/Product1' incorporates:
            //   Constant: '<S81>/Constant1'
            //   Sqrt: '<S81>/sqrt'

            rtb_Sum_ow = 6.378137E+6 / std::sqrt(rtb_Up);

            // Product: '<S66>/dNorth' incorporates:
            //   Constant: '<S81>/Constant2'
            //   Product: '<S81>/Product3'
            //   Trigonometry: '<S81>/Trigonometric Function1'

            rtb_Up = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Sum_ow *
                0.99330562000985867 / rtb_Up);

            // Product: '<S66>/dEast' incorporates:
            //   Constant: '<S81>/Constant3'
            //   Product: '<S81>/Product4'
            //   Trigonometry: '<S81>/Trigonometric Function'
            //   Trigonometry: '<S81>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_k = 1.0 / rt_atan2d_snf(1.0, rtb_Sum_ow * std::cos
                (rtb_Switch_tmp)) * rtb_Sum1_idx_1;

            // Outputs for Triggered SubSystem: '<S57>/WayPointGen' incorporates:
            //   TriggerPort: '<S63>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &localZCE->WayPointGen_Trig_ZCE_d,
                               (1.0));
            if (zcEvent != NO_ZCEVENT) {
                int32_T ibmat;

                // Saturate: '<S63>/Saturation' incorporates:
                //   DataTypeConversion: '<S57>/Param2'

                if (rtu_MissionInput->params.Param2 <= 1.0F) {
                    // Saturate: '<S63>/Saturation'
                    rtb_Sum_ow = 1.0;
                } else {
                    // Saturate: '<S63>/Saturation'
                    rtb_Sum_ow = static_cast<real_T>
                        (rtu_MissionInput->params.Param2);
                }

                // End of Saturate: '<S63>/Saturation'

                // SignalConversion generated from: '<S63>/RotateATMissionHdg' incorporates:
                //   Bias: '<S63>/Bias'
                //   Gain: '<S59>/Gain1'

                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    0.017453292519943295 *
                    rtu_MissionInput->MissionLocation.degHDG +
                    -0.78539816339744828;

                // MATLABSystem: '<S63>/RotateATMissionHdg'
                stateNew_idx_2 = std::cos
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = std::sin
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
                out[0] = stateNew_idx_2;
                out[3] = 0.0 * stateNew_idx_2 -
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                out[6] = 0.0 * stateNew_idx_2 +
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] * 0.0;
                out[1] = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                out[4] = 0.0 *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] +
                    stateNew_idx_2;
                out[7] = 0.0 *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] -
                    stateNew_idx_2 * 0.0;
                out[2] = -0.0;
                out[5] = 0.0;
                out[8] = 1.0;

                // Reshape: '<S63>/ReshapeRowVec' incorporates:
                //   DataStoreRead: '<S57>/AltitudeGCS'
                //   Gain: '<S57>/inverse'
                //   Product: '<S66>/x*cos'
                //   Product: '<S66>/x*sin'
                //   Product: '<S66>/y*cos'
                //   Product: '<S66>/y*sin'
                //   Sum: '<S60>/Sum'
                //   Sum: '<S66>/Sum2'
                //   Sum: '<S66>/Sum3'
                //   UnaryMinus: '<S60>/Ze2height'

                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    rtb_Switch_k * 0.0 + rtb_Up;
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                    rtb_Switch_k - rtb_Up * 0.0;
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                    -(rtu_MissionInput->MissionLocation.Alt + -AltitudeGCS);

                // MATLAB Function: '<S63>/BaseWayPoint' incorporates:
                //   DataTypeConversion: '<S57>/Param1'
                //   DataTypeConversion: '<S57>/Param3'

                // MATLAB Function 'ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/WayPointGen/BaseWayPoint': '<S109>:1' 
                // '<S109>:1:5'
                // '<S109>:1:26'
                // '<S109>:1:5'
                rtb_Sum1_idx_0 =
                    ImmedMission_DubinsObjSingleton_getMinTurnRadius(localDW);

                // '<S109>:1:8'
                colIdx = 0;
                for (nm1d2 = 0; nm1d2 < 360; nm1d2++) {
                    localDW->CirVec[colIdx] = b_a[colIdx] * rtb_Sum1_idx_0;
                    localDW->CirVec[static_cast<int32_T>(colIdx + 1)] = b_a[
                        static_cast<int32_T>(colIdx + 1)] * rtb_Sum1_idx_0;
                    colIdx = static_cast<int32_T>(colIdx + 2);
                }

                // '<S109>:1:11'
                // '<S109>:1:12'
                linspace_Q5Un26da(static_cast<real_T>
                                  (rtu_MissionInput->params.Param3), WPQ1_tmp);

                // '<S109>:1:16'
                // '<S109>:1:17'
                // '<S109>:1:21'
                // '<S109>:1:22'
                // '<S109>:1:26'
                // '<S109>:1:27'
                // '<S109>:1:31'
                rtb_Up = static_cast<real_T>(rtu_MissionInput->params.Param1) /
                    2.0;
                rtb_Sum1_idx_0 = -static_cast<real_T>
                    (rtu_MissionInput->params.Param1) / 2.0;
                for (colIdx = 0; colIdx < 91; colIdx++) {
                    rtb_Switch_k = WPQ1_tmp[colIdx];
                    nm1d2 = static_cast<int32_T>(colIdx << 1);
                    localDW->a[static_cast<int32_T>(3 * colIdx)] =
                        localDW->CirVec[nm1d2] + rtb_Up;
                    localDW->a[static_cast<int32_T>(static_cast<int32_T>(3 *
                        colIdx) + 1)] = localDW->CirVec[static_cast<int32_T>
                        (nm1d2 + 1)] + rtb_Up;
                    localDW->a[static_cast<int32_T>(static_cast<int32_T>(3 *
                        colIdx) + 2)] = rtb_Switch_k;
                    nm1d2 = static_cast<int32_T>(static_cast<int32_T>(colIdx +
                        90) << 1);
                    b_ibmat = static_cast<int32_T>(static_cast<int32_T>(colIdx +
                        91) * 3);
                    localDW->a[b_ibmat] = localDW->CirVec[nm1d2] +
                        rtb_Sum1_idx_0;
                    localDW->a[static_cast<int32_T>(b_ibmat + 1)] =
                        localDW->CirVec[static_cast<int32_T>(nm1d2 + 1)] +
                        rtb_Up;
                    localDW->a[static_cast<int32_T>(b_ibmat + 2)] = rtb_Switch_k;
                    nm1d2 = static_cast<int32_T>(static_cast<int32_T>(colIdx +
                        180) << 1);
                    b_ibmat = static_cast<int32_T>(static_cast<int32_T>(colIdx +
                        182) * 3);
                    localDW->a[b_ibmat] = localDW->CirVec[nm1d2] +
                        rtb_Sum1_idx_0;
                    localDW->a[static_cast<int32_T>(b_ibmat + 1)] =
                        localDW->CirVec[static_cast<int32_T>(nm1d2 + 1)] +
                        rtb_Sum1_idx_0;
                    localDW->a[static_cast<int32_T>(b_ibmat + 2)] = rtb_Switch_k;
                    nm1d2 = static_cast<int32_T>(static_cast<int32_T>(d[colIdx])
                        << 1);
                    b_ibmat = static_cast<int32_T>(static_cast<int32_T>(colIdx +
                        273) * 3);
                    localDW->a[b_ibmat] = localDW->CirVec[nm1d2] + rtb_Up;
                    localDW->a[static_cast<int32_T>(b_ibmat + 1)] =
                        localDW->CirVec[static_cast<int32_T>(nm1d2 + 1)] +
                        rtb_Sum1_idx_0;
                    localDW->a[static_cast<int32_T>(b_ibmat + 2)] = rtb_Switch_k;
                }

                ImmedMission_emxInit_real_T(&d_b, 2);
                boffset = static_cast<int32_T>(d_b->size[0] * d_b->size[1]);

                // MATLAB Function: '<S63>/BaseWayPoint'
                d_b->size[0] = 3;
                d_b->size[1] = static_cast<int32_T>(364 * static_cast<int32_T>
                    (rtb_Sum_ow));
                ImmedMission_emxEnsureCapacity_real_T(d_b, boffset);

                // MATLAB Function: '<S63>/BaseWayPoint'
                for (b_ibmat = 0; b_ibmat <= static_cast<int32_T>
                        (static_cast<int32_T>(rtb_Sum_ow) - 1); b_ibmat =
                        static_cast<int32_T>(b_ibmat + 1)) {
                    coffset = static_cast<int32_T>(static_cast<int32_T>(b_ibmat *
                        1092) - 1);
                    for (nm1d2 = 0; nm1d2 < 364; nm1d2++) {
                        boffset = static_cast<int32_T>(nm1d2 * 3);
                        ibmat = static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(nm1d2 * 3) + coffset) + 1);
                        d_b->data[ibmat] = localDW->a[boffset];
                        d_b->data[static_cast<int32_T>(ibmat + 1)] = localDW->a[
                            static_cast<int32_T>(boffset + 1)];
                        d_b->data[static_cast<int32_T>(ibmat + 2)] = localDW->a[
                            static_cast<int32_T>(boffset + 2)];
                    }
                }

                boffset = static_cast<int32_T>(e->size[0] * e->size[1]);

                // MATLAB Function: '<S63>/BaseWayPoint'
                e->size[0] = d_b->size[1];
                e->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(e, boffset);

                // MATLAB Function: '<S63>/BaseWayPoint'
                coffset = d_b->size[1];
                for (colIdx = 0; colIdx < 3; colIdx++) {
                    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(coffset - 1);
                            nm1d2++) {
                        e->data[static_cast<int32_T>(nm1d2 + static_cast<int32_T>
                            (e->size[0] * colIdx))] = d_b->data
                            [static_cast<int32_T>(static_cast<int32_T>(3 * nm1d2)
                            + colIdx)];
                    }
                }

                ImmedMission_emxFree_real_T(&d_b);
                ImmedMission_emxInit_real_T(&WayPoint, 2);

                // MATLAB Function: '<S63>/BaseWayPoint'
                ImmedMission_circshift(e);
                boffset = static_cast<int32_T>(WayPoint->size[0] *
                    WayPoint->size[1]);

                // MATLAB Function: '<S63>/BaseWayPoint'
                WayPoint->size[0] = e->size[0];
                WayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(WayPoint, boffset);

                // MATLAB Function: '<S63>/BaseWayPoint'
                coffset = static_cast<int32_T>(e->size[0] * 3);
                for (colIdx = 0; colIdx <= static_cast<int32_T>(coffset - 1);
                        colIdx++) {
                    WayPoint->data[colIdx] = e->data[colIdx];
                }

                ImmedMission_emxInit_real_T(&y, 2);

                // MATLAB Function: '<S63>/BaseWayPoint' incorporates:
                //   DataTypeConversion: '<S57>/Param3'

                // '<S109>:1:32'
                rtb_Switch_m2 = 4.0 * rtb_Sum_ow * static_cast<real_T>
                    (rtu_MissionInput->params.Param3);
                if (std::isnan(static_cast<real_T>
                               (rtu_MissionInput->params.Param3))) {
                    boffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y, boffset);
                    y->data[0] = (rtNaN);
                } else if (std::isnan(rtb_Switch_m2)) {
                    boffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y, boffset);
                    y->data[0] = (rtNaN);
                } else if (static_cast<boolean_T>(static_cast<int32_T>(
                             static_cast<int32_T>(static_cast<boolean_T>(
                               static_cast<int32_T>(static_cast<int32_T>(
                                 static_cast<boolean_T>(static_cast<int32_T>
                                  ((rtb_Switch_m2 > 0.0) &
                                   (rtu_MissionInput->params.Param3 < 0.0F)))) |
                                (rtu_MissionInput->params.Param3 == 0.0F)))) |
                             static_cast<int32_T>(static_cast<boolean_T>(
                               static_cast<int32_T>((rtb_Switch_m2 < 0.0) &
                                (rtu_MissionInput->params.Param3 > 0.0F))))))) {
                    y->size[0] = 1;
                    y->size[1] = 0;
                } else if (std::isinf(rtb_Switch_m2) && std::isinf
                           (static_cast<real_T>(rtu_MissionInput->params.Param3)))
                {
                    boffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y, boffset);
                    y->data[0] = (rtNaN);
                } else if (std::isinf(static_cast<real_T>
                                      (rtu_MissionInput->params.Param3))) {
                    boffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y, boffset);
                    y->data[0] = 0.0;
                } else if (std::floor(static_cast<real_T>
                                      (rtu_MissionInput->params.Param3)) ==
                           static_cast<real_T>(rtu_MissionInput->params.Param3))
                {
                    boffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    coffset = static_cast<int32_T>(rtb_Switch_m2 /
                        static_cast<real_T>(rtu_MissionInput->params.Param3));
                    y->size[1] = static_cast<int32_T>(coffset + 1);
                    ImmedMission_emxEnsureCapacity_real_T(y, boffset);
                    for (colIdx = 0; colIdx <= coffset; colIdx++) {
                        y->data[colIdx] = static_cast<real_T>
                            (rtu_MissionInput->params.Param3) *
                            static_cast<real_T>(colIdx);
                    }
                } else {
                    rtb_Up = std::floor(rtb_Switch_m2 / static_cast<real_T>
                                        (rtu_MissionInput->params.Param3) + 0.5);
                    rtb_Sum1_idx_0 = rtb_Up * static_cast<real_T>
                        (rtu_MissionInput->params.Param3);
                    if (rtu_MissionInput->params.Param3 > 0.0F) {
                        rtb_Switch_k = rtb_Sum1_idx_0 - rtb_Switch_m2;
                    } else {
                        rtb_Switch_k = rtb_Switch_m2 - rtb_Sum1_idx_0;
                    }

                    if (std::abs(rtb_Switch_k) < 4.4408920985006262E-16 * std::
                            fmax(0.0, std::abs(rtb_Switch_m2))) {
                        rtb_Up++;
                        rtb_Sum1_idx_0 = rtb_Switch_m2;
                    } else if (rtb_Switch_k > 0.0) {
                        rtb_Sum1_idx_0 = (rtb_Up - 1.0) * static_cast<real_T>
                            (rtu_MissionInput->params.Param3);
                    } else {
                        rtb_Up++;
                    }

                    if (rtb_Up >= 0.0) {
                        colIdx = static_cast<int32_T>(static_cast<int32_T>
                            (rtb_Up) - 1);
                    } else {
                        colIdx = -1;
                    }

                    boffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = static_cast<int32_T>(colIdx + 1);
                    ImmedMission_emxEnsureCapacity_real_T(y, boffset);
                    if (static_cast<int32_T>(colIdx + 1) > 0) {
                        y->data[0] = 0.0;
                        if (static_cast<int32_T>(colIdx + 1) > 1) {
                            y->data[colIdx] = rtb_Sum1_idx_0;
                            nm1d2 = static_cast<int32_T>(colIdx / 2);
                            for (b_ibmat = 1; static_cast<int32_T>(b_ibmat - 1) <=
                                 static_cast<int32_T>(nm1d2 - 2); b_ibmat =
                                    static_cast<int32_T>(b_ibmat + 1)) {
                                rtb_Switch_m2 = static_cast<real_T>(b_ibmat) *
                                    static_cast<real_T>
                                    (rtu_MissionInput->params.Param3);
                                y->data[b_ibmat] = rtb_Switch_m2;
                                y->data[static_cast<int32_T>(colIdx - b_ibmat)] =
                                    rtb_Sum1_idx_0 - rtb_Switch_m2;
                            }

                            if (static_cast<int32_T>(nm1d2 << 1) == colIdx) {
                                y->data[nm1d2] = rtb_Sum1_idx_0 / 2.0;
                            } else {
                                rtb_Switch_m2 = static_cast<real_T>(nm1d2) *
                                    static_cast<real_T>
                                    (rtu_MissionInput->params.Param3);
                                y->data[nm1d2] = rtb_Switch_m2;
                                y->data[static_cast<int32_T>(nm1d2 + 1)] =
                                    rtb_Sum1_idx_0 - rtb_Switch_m2;
                            }
                        }
                    }
                }

                ImmedMission_emxInit_real_T(&step, 2);
                boffset = static_cast<int32_T>(step->size[0] * step->size[1]);

                // MATLAB Function: '<S63>/BaseWayPoint'
                step->size[0] = 1;
                step->size[1] = static_cast<int32_T>(y->size[1] * 91);
                ImmedMission_emxEnsureCapacity_real_T(step, boffset);

                // MATLAB Function: '<S63>/BaseWayPoint'
                if (static_cast<int32_T>(y->size[1] * 91) != 0) {
                    colIdx = 0;
                    for (b_ibmat = 0; b_ibmat <= static_cast<int32_T>(y->size[1]
                          - 1); b_ibmat = static_cast<int32_T>(b_ibmat + 1)) {
                        step->data[colIdx] = y->data[b_ibmat];
                        for (nm1d2 = 0; nm1d2 < 90; nm1d2++) {
                            step->data[static_cast<int32_T>(static_cast<int32_T>
                                (colIdx + nm1d2) + 1)] = step->data[colIdx];
                        }

                        colIdx = static_cast<int32_T>(colIdx + 91);
                    }
                }

                ImmedMission_emxFree_real_T(&y);

                // MATLAB Function: '<S63>/BaseWayPoint'
                if (static_cast<int32_T>(step->size[1] - 46) < 46) {
                    nm1d2 = 0;
                    colIdx = 0;
                } else {
                    nm1d2 = 45;
                    colIdx = static_cast<int32_T>(step->size[1] - 46);
                }

                // '<S109>:1:33'
                if (static_cast<int32_T>(colIdx - nm1d2) == WayPoint->size[0]) {
                    ImmedMission_emxInit_real_T(&WayPoint_0, 1);
                    b_ibmat = static_cast<int32_T>(WayPoint->size[0] - 1);
                    boffset = WayPoint_0->size[0];
                    WayPoint_0->size[0] = WayPoint->size[0];
                    ImmedMission_emxEnsureCapacity_real_T(WayPoint_0, boffset);
                    for (colIdx = 0; colIdx <= b_ibmat; colIdx++) {
                        WayPoint_0->data[colIdx] = WayPoint->data
                            [static_cast<int32_T>(static_cast<int32_T>
                            (WayPoint->size[0] << 1) + colIdx)] + step->data[
                            static_cast<int32_T>(nm1d2 + colIdx)];
                    }

                    coffset = WayPoint_0->size[0];
                    for (colIdx = 0; colIdx <= static_cast<int32_T>(coffset - 1);
                         colIdx++) {
                        WayPoint->data[static_cast<int32_T>(colIdx +
                            static_cast<int32_T>(WayPoint->size[0] << 1))] =
                            WayPoint_0->data[colIdx];
                    }

                    ImmedMission_emxFree_real_T(&WayPoint_0);
                } else {
                    ImmedMission_binary_expand_op_p(WayPoint, step, nm1d2,
                        static_cast<int32_T>(colIdx - 1));
                }

                ImmedMission_emxFree_real_T(&step);
                ImmedMission_emxInit_real_T(&rotWayPoint, 2);

                // MATLAB Function: '<S63>/BaseWayPoint'
                // '<S109>:1:35'
                b_ibmat = WayPoint->size[0];
                boffset = static_cast<int32_T>(rotWayPoint->size[0] *
                    rotWayPoint->size[1]);

                // MATLAB Function: '<S63>/BaseWayPoint'
                rotWayPoint->size[0] = WayPoint->size[0];
                rotWayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(rotWayPoint, boffset);

                // MATLAB Function: '<S63>/BaseWayPoint' incorporates:
                //   MATLABSystem: '<S63>/RotateATMissionHdg'

                for (colIdx = 0; colIdx < 3; colIdx++) {
                    coffset = static_cast<int32_T>(colIdx * b_ibmat);
                    boffset = static_cast<int32_T>(colIdx * 3);
                    for (ibmat = 0; ibmat <= static_cast<int32_T>(b_ibmat - 1);
                            ibmat = static_cast<int32_T>(ibmat + 1)) {
                        rotWayPoint->data[static_cast<int32_T>(coffset + ibmat)]
                            = (WayPoint->data[static_cast<int32_T>
                               (WayPoint->size[0] + ibmat)] * out
                               [static_cast<int32_T>(boffset + 1)] +
                               WayPoint->data[ibmat] * out[boffset]) +
                            WayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(WayPoint->size[0] << 1) +
                             ibmat)] * out[static_cast<int32_T>(boffset + 2)];
                    }
                }

                boffset = static_cast<int32_T>(WayPoint->size[0] *
                    WayPoint->size[1]);

                // MATLAB Function: '<S63>/BaseWayPoint'
                WayPoint->size[0] = rotWayPoint->size[0];
                WayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(WayPoint, boffset);

                // MATLAB Function: '<S63>/BaseWayPoint' incorporates:
                //   Reshape: '<S63>/ReshapeRowVec'

                nm1d2 = rotWayPoint->size[0];
                for (coffset = 0; coffset <= static_cast<int32_T>(nm1d2 - 1);
                        coffset = static_cast<int32_T>(coffset + 1)) {
                    WayPoint->data[coffset] =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                }

                for (coffset = 0; coffset <= static_cast<int32_T>(nm1d2 - 1);
                        coffset = static_cast<int32_T>(coffset + 1)) {
                    WayPoint->data[static_cast<int32_T>(nm1d2 + coffset)] =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1];
                }

                b_ibmat = static_cast<int32_T>(rotWayPoint->size[0] << 1);
                for (coffset = 0; coffset <= static_cast<int32_T>(nm1d2 - 1);
                        coffset = static_cast<int32_T>(coffset + 1)) {
                    WayPoint->data[static_cast<int32_T>(b_ibmat + coffset)] =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2];
                }

                // '<S109>:1:38'
                ImmedMission_emxInit_real_T(&tmp, 2);
                if (rotWayPoint->size[0] == WayPoint->size[0]) {
                    ImmedMission_emxInit_real_T(&rotWayPoint_0, 2);
                    coffset = rotWayPoint->size[0];
                    b_ibmat = rotWayPoint->size[0];
                    nm1d2 = rotWayPoint->size[0];
                    boffset = static_cast<int32_T>(rotWayPoint_0->size[0] *
                        rotWayPoint_0->size[1]);
                    rotWayPoint_0->size[0] = rotWayPoint->size[0];
                    rotWayPoint_0->size[1] = 3;
                    ImmedMission_emxEnsureCapacity_real_T(rotWayPoint_0, boffset);
                    for (colIdx = 0; colIdx <= static_cast<int32_T>(coffset - 1);
                         colIdx++) {
                        rotWayPoint_0->data[colIdx] = rotWayPoint->data[
                            static_cast<int32_T>(colIdx + rotWayPoint->size[0])];
                    }

                    for (colIdx = 0; colIdx <= static_cast<int32_T>(b_ibmat - 1);
                         colIdx++) {
                        rotWayPoint_0->data[static_cast<int32_T>(colIdx +
                            rotWayPoint_0->size[0])] = rotWayPoint->data[colIdx];
                    }

                    for (colIdx = 0; colIdx <= static_cast<int32_T>(nm1d2 - 1);
                            colIdx++) {
                        rotWayPoint_0->data[static_cast<int32_T>(colIdx +
                            static_cast<int32_T>(rotWayPoint_0->size[0] << 1))] =
                            rotWayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(rotWayPoint->size[0] << 1) +
                             colIdx)];
                    }

                    boffset = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
                    tmp->size[0] = rotWayPoint_0->size[0];
                    tmp->size[1] = 3;
                    ImmedMission_emxEnsureCapacity_real_T(tmp, boffset);
                    coffset = static_cast<int32_T>(rotWayPoint_0->size[0] * 3);
                    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(coffset - 1);
                            nm1d2++) {
                        tmp->data[nm1d2] = rotWayPoint_0->data[nm1d2] +
                            WayPoint->data[nm1d2];
                    }

                    ImmedMission_emxFree_real_T(&rotWayPoint_0);
                } else {
                    ImmedMission_binary_expand_op(tmp, rotWayPoint, WayPoint);
                }

                ImmedMission_emxFree_real_T(&rotWayPoint);
                ImmedMission_emxFree_real_T(&WayPoint);

                // MATLAB Function: '<S63>/BaseWayPoint'
                localDW->SFunction_DIMS2_b[0] = tmp->size[0];
                localDW->SFunction_DIMS2_b[1] = tmp->size[1];
                coffset = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
                for (colIdx = 0; colIdx <= static_cast<int32_T>(coffset - 1);
                        colIdx++) {
                    localDW->nedWayPoint[colIdx] = tmp->data[colIdx];
                }

                ImmedMission_emxFree_real_T(&tmp);

                // Concatenate: '<S63>/Matrix Concatenate' incorporates:
                //   Reshape: '<S57>/ReshapeXe'
                //   SignalConversion generated from: '<S63>/FlightMissionLoc'

                localDW->MatrixConcatenate_DIMS1[0] = static_cast<int32_T>
                    (localDW->SFunction_DIMS2_b[0] + 1);
                localDW->MatrixConcatenate_DIMS1[1] = localDW->
                    SFunction_DIMS2_b[1];
                localDW->MatrixConcatenate_d[0] = rtb_Sum_gu[0];
                localDW->MatrixConcatenate_d[localDW->MatrixConcatenate_DIMS1[0]]
                    = rtb_Sum_gu[1];
                localDW->MatrixConcatenate_d[static_cast<int32_T>
                    (localDW->MatrixConcatenate_DIMS1[0] << 1)] = rtb_Sum_gu[2];
                coffset = localDW->SFunction_DIMS2_b[1];
                for (colIdx = 0; colIdx <= static_cast<int32_T>(coffset - 1);
                        colIdx++) {
                    b_ibmat = localDW->SFunction_DIMS2_b[0];
                    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(b_ibmat - 1);
                            nm1d2++) {
                        localDW->MatrixConcatenate_d[static_cast<int32_T>(
                            static_cast<int32_T>(nm1d2 + static_cast<int32_T>
                            (localDW->MatrixConcatenate_DIMS1[0] * colIdx)) + 1)]
                            = localDW->nedWayPoint[static_cast<int32_T>(
                            static_cast<int32_T>(localDW->SFunction_DIMS2_b[0] *
                            colIdx) + nm1d2)];
                    }
                }

                // End of Concatenate: '<S63>/Matrix Concatenate'

                // Sum: '<S63>/Minus' incorporates:
                //   Reshape: '<S57>/ReshapeXe'
                //   Selector: '<S63>/Selector'
                //   SignalConversion generated from: '<S63>/FlightMissionLoc'

                localDW->Minus[0] = localDW->nedWayPoint[0] - rtb_Sum_gu[0];
                localDW->Minus[1] = localDW->nedWayPoint
                    [localDW->SFunction_DIMS2_b[0]] - rtb_Sum_gu[1];
                localDW->Minus[2] = localDW->nedWayPoint[static_cast<int32_T>
                    (localDW->SFunction_DIMS2_b[0] << 1)] - rtb_Sum_gu[2];
            }

            // End of Outputs for SubSystem: '<S57>/WayPointGen'

            // SignalConversion generated from: '<S57>/Waypoint Follower' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   Constant: '<S57>/InitTrigger'
            //   MATLAB Function: '<S63>/BaseWayPoint'

            rtb_Sum_ow = rtb_Switch;
            rtb_Switch_k = rtb_Py_n;
            rtb_Sum1_idx_1 = rtb_Down;

            // MATLABSystem: '<S57>/Waypoint Follower' incorporates:
            //   Concatenate: '<S63>/Matrix Concatenate'

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.CacheInputSizes) ^ 1))) {
                localDW->obj.CacheInputSizes = true;
                for (colIdx = 0; colIdx < 8; colIdx++) {
                    localDW->obj.inputVarSize[0].f1[colIdx] = 1U;
                }

                colIdx = localDW->MatrixConcatenate_DIMS1[0];
                if (localDW->MatrixConcatenate_DIMS1[0] < 0) {
                    colIdx = 0;
                }

                localDW->obj.inputVarSize[1].f1[0] = static_cast<uint32_T>
                    (colIdx);
                colIdx = localDW->MatrixConcatenate_DIMS1[1];
                if (localDW->MatrixConcatenate_DIMS1[1] < 0) {
                    colIdx = 0;
                }

                localDW->obj.inputVarSize[1].f1[1] = static_cast<uint32_T>
                    (colIdx);
                for (colIdx = 0; colIdx < 6; colIdx++) {
                    localDW->obj.inputVarSize[1].f1[static_cast<int32_T>(colIdx
                        + 2)] = 1U;
                }

                for (colIdx = 0; colIdx < 8; colIdx++) {
                    localDW->obj.inputVarSize[2].f1[colIdx] = 1U;
                }
            }

            colIdx = localDW->MatrixConcatenate_DIMS1[0];
            if (localDW->MatrixConcatenate_DIMS1[0] < 0) {
                colIdx = 0;
            }

            inSize[0] = static_cast<uint32_T>(colIdx);
            colIdx = localDW->MatrixConcatenate_DIMS1[1];
            if (localDW->MatrixConcatenate_DIMS1[1] < 0) {
                colIdx = 0;
            }

            inSize[1] = static_cast<uint32_T>(colIdx);
            for (colIdx = 0; colIdx < 6; colIdx++) {
                inSize[static_cast<int32_T>(colIdx + 2)] = 1U;
            }

            nm1d2 = 0;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 < 8)) {
                if (localDW->obj.inputVarSize[1].f1[nm1d2] != inSize[nm1d2]) {
                    for (colIdx = 0; colIdx < 8; colIdx++) {
                        localDW->obj.inputVarSize[1].f1[colIdx] = inSize[colIdx];
                    }

                    exitg1 = true;
                } else {
                    nm1d2 = static_cast<int32_T>(nm1d2 + 1);
                }
            }

            localDW->obj.LookaheadDistFlag = 0U;
            localDW->obj.InitialPose[0] = 0.0;
            localDW->obj.InitialPose[1] = 0.0;
            localDW->obj.InitialPose[2] = 0.0;
            localDW->obj.InitialPose[3] = 0.0;
            for (colIdx = 0; colIdx < 30723; colIdx++) {
                localDW->paddedWaypts[colIdx] = (rtNaN);
            }

            coffset = localDW->MatrixConcatenate_DIMS1[0];
            colIdx = 0;
            for (nm1d2 = 0; nm1d2 < 3; nm1d2++) {
                for (b_ibmat = 0; b_ibmat <= static_cast<int32_T>(coffset - 1);
                        b_ibmat++) {
                    localDW->paddedWaypts[static_cast<int32_T>(b_ibmat + colIdx)]
                        = localDW->MatrixConcatenate_d[static_cast<int32_T>(
                        static_cast<int32_T>(localDW->MatrixConcatenate_DIMS1[0]
                        * nm1d2) + b_ibmat)];
                }

                colIdx = static_cast<int32_T>(colIdx + 10241);
            }

            rtb_Compare_lh = false;
            rtb_Ctrl = true;
            nm1d2 = 0;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 < 30723)) {
                if ((localDW->obj.WaypointsInternal[nm1d2] ==
                        localDW->paddedWaypts[nm1d2]) || (std::isnan
                        (localDW->obj.WaypointsInternal[nm1d2]) && std::isnan
                        (localDW->paddedWaypts[nm1d2]))) {
                    nm1d2 = static_cast<int32_T>(nm1d2 + 1);
                } else {
                    rtb_Ctrl = false;
                    exitg1 = true;
                }
            }

            if (rtb_Ctrl) {
                rtb_Compare_lh = true;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_Compare_lh) ^ 1))) {
                std::memcpy(&localDW->obj.WaypointsInternal[0],
                            &localDW->paddedWaypts[0], static_cast<uint32_T>
                            (30723U * sizeof(real_T)));
                localDW->obj.WaypointIndex = 1.0;
            }

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            ImmedMission_emxInit_real_T(&waypointsIn, 2);

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S7>/Action Port'

            MatrixConcatenate_d.data = &localDW->MatrixConcatenate_d[0];
            MatrixConcatenate_DIMS1[0] = localDW->MatrixConcatenate_DIMS1[0];
            MatrixConcatenate_DIMS1[1] = localDW->MatrixConcatenate_DIMS1[1];

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            MatrixConcatenate_d.size = &MatrixConcatenate_DIMS1[0];
            MatrixConcatenate_d.allocatedSize = 30723;
            MatrixConcatenate_d.numDimensions = 2;
            MatrixConcatenate_d.canFreeData = false;

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S7>/Action Port'

            // MATLABSystem: '<S57>/Waypoint Follower' incorporates:
            //   Concatenate: '<S63>/Matrix Concatenate'

            ImmedMission_WaypointFollowerBase_getDistinctWpts
                (&MatrixConcatenate_d, waypointsIn, localDW);
            localDW->obj.NumWaypoints = static_cast<real_T>(waypointsIn->size[0]);
            localDW->obj.LookaheadDistance = 150.0;

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            ImmedMission_emxInit_real_T(&tmp_0, 2);

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S7>/Action Port'

            // MATLABSystem: '<S57>/Waypoint Follower' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   SignalConversion generated from: '<S57>/Waypoint Follower'

            if (static_cast<boolean_T>(static_cast<int32_T>((waypointsIn->size[0]
                   == 0) | (waypointsIn->size[1] == 0)))) {
                rtb_Up = rtb_Down;

                // MATLABSystem: '<S57>/Waypoint Follower' incorporates:
                //   SignalConversion generated from: '<S57>/Waypoint Follower'

                localDW->WaypointFollower_o5 = 1U;
            } else {
                boolean_T guard1;
                guard1 = false;
                if (waypointsIn->size[0] == 1) {
                    if (localDW->obj.StartFlag) {
                        localDW->obj.InitialPose[0] = rtb_Switch;
                        localDW->obj.InitialPose[1] = rtb_Py_n;
                        localDW->obj.InitialPose[2] = rtb_Down;
                        localDW->obj.InitialPose[3] = rtb_Abs1;
                    }

                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                        waypointsIn->data[0] - rtb_Switch;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                        waypointsIn->data[1] - rtb_Py_n;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                        waypointsIn->data[2] - rtb_Down;
                    if (ImmedMission_norm_pv
                            (rtb_TmpSignalConversionAtRotateATMissionHdgInport1)
                        < 1.4901161193847656E-8) {
                        rtb_Up = rtb_Down;

                        // MATLABSystem: '<S57>/Waypoint Follower' incorporates:
                        //   SignalConversion generated from: '<S57>/Waypoint Follower'

                        localDW->WaypointFollower_o5 = 1U;
                        localDW->obj.StartFlag = false;
                    } else {
                        localDW->obj.StartFlag = false;
                        localDW->obj.NumWaypoints = 2.0;
                        waypointsIn_0[0] = 1;
                        waypointsIn_0[1] = 3;
                        boffset = static_cast<int32_T>(tmp_0->size[0] *
                            tmp_0->size[1]);
                        tmp_0->size[0] = 2;
                        tmp_0->size[1] = 3;
                        ImmedMission_emxEnsureCapacity_real_T(tmp_0, boffset);
                        for (colIdx = 0; colIdx < 3; colIdx++) {
                            tmp_0->data[static_cast<int32_T>(tmp_0->size[0] *
                                colIdx)] = localDW->obj.InitialPose[colIdx];
                            tmp_0->data[static_cast<int32_T>(1 + static_cast<
                                int32_T>(tmp_0->size[0] * colIdx))] =
                                waypointsIn->data[static_cast<int32_T>(
                                static_cast<int32_T>(waypointsIn_0[0]) * colIdx)];
                        }

                        boffset = static_cast<int32_T>(waypointsIn->size[0] *
                            waypointsIn->size[1]);
                        waypointsIn->size[0] = 2;
                        waypointsIn->size[1] = 3;
                        ImmedMission_emxEnsureCapacity_real_T(waypointsIn,
                            boffset);
                        for (colIdx = 0; colIdx < 6; colIdx++) {
                            waypointsIn->data[colIdx] = tmp_0->data[colIdx];
                        }

                        guard1 = true;
                    }
                } else {
                    guard1 = true;
                }

                if (guard1) {
                    real_T lambda_tmp_tmp;
                    real_T rtb_Switch_p_tmp;
                    real_T rtb_TmpSignalConversionAtOrbitF_tmp;
                    real_T stateNew_idx_5;
                    boolean_T guard2{ false };

                    rtb_Compare_lh = false;
                    if (localDW->obj.WaypointIndex == localDW->obj.NumWaypoints)
                    {
                        rtb_Compare_lh = true;
                    }

                    if (rtb_Compare_lh) {
                        localDW->obj.LastWaypointFlag = true;
                        localDW->obj.WaypointIndex--;
                    }

                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                        waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(localDW->obj.WaypointIndex) - 1)];
                    rtb_Up = waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0)
                         - 1)];
                    rtb_Sum_gu[0] = rtb_Switch - rtb_Up;
                    stateNew_idx_2 = rtb_Up;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                        waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>
                          (localDW->obj.WaypointIndex) + waypointsIn->size[0]) -
                         1)];
                    rtb_Up = waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>
                          (localDW->obj.WaypointIndex + 1.0) + waypointsIn->
                          size[0]) - 1)];
                    rtb_Sum_gu[1] = rtb_Py_n - rtb_Up;
                    rtb_Switch_m2 = rtb_Up;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                        waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>
                          (waypointsIn->size[0] << 1) + static_cast<int32_T>
                          (localDW->obj.WaypointIndex)) - 1)];
                    rtb_Up = waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>
                          (localDW->obj.WaypointIndex + 1.0) +
                          static_cast<int32_T>(waypointsIn->size[0] << 1)) - 1)];
                    rtb_Sum_gu[2] = rtb_Down - rtb_Up;
                    rtb_Switch = ImmedMission_norm_pv(rtb_Sum_gu);
                    guard2 = false;
                    if (rtb_Switch <= 100.0) {
                        guard2 = true;
                    } else {
                        rtb_Abs1 = stateNew_idx_2 -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                        turnVector[0] = rtb_Abs1;
                        rtb_Sum1_idx_0 = rtb_Switch_m2 -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1];
                        turnVector[1] = rtb_Sum1_idx_0;
                        stateNew_idx_5 = rtb_Up -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2];
                        turnVector[2] = stateNew_idx_5;
                        lambda_tmp_tmp = ImmedMission_norm_pv(turnVector);
                        rtb_Abs1 = (rtb_Abs1 / lambda_tmp_tmp * (rtb_Sum_gu[0] /
                                     rtb_Switch) + rtb_Sum1_idx_0 /
                                    lambda_tmp_tmp * (rtb_Sum_gu[1] / rtb_Switch))
                            + stateNew_idx_5 / lambda_tmp_tmp * (rtb_Sum_gu[2] /
                            rtb_Switch);
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(std::isnan(rtb_Abs1)) ^ 1)))
                        {
                            if (rtb_Abs1 < 0.0) {
                                rtb_Abs1 = -1.0;
                            } else {
                                rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                            }
                        }

                        if (rtb_Abs1 >= 0.0) {
                            guard2 = true;
                        }
                    }

                    if (guard2) {
                        localDW->obj.WaypointIndex++;
                        rtb_Compare_lh = false;
                        if (localDW->obj.WaypointIndex ==
                                localDW->obj.NumWaypoints) {
                            rtb_Compare_lh = true;
                        }

                        if (rtb_Compare_lh) {
                            localDW->obj.LastWaypointFlag = true;
                            localDW->obj.WaypointIndex--;
                        }

                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                            waypointsIn->data[static_cast<int32_T>
                            (static_cast<int32_T>(localDW->obj.WaypointIndex) -
                             1)];
                        stateNew_idx_2 = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>(localDW->obj.WaypointIndex +
                            1.0) - 1)];
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                            waypointsIn->data[static_cast<int32_T>
                            (static_cast<int32_T>(static_cast<int32_T>
                              (localDW->obj.WaypointIndex) + waypointsIn->size[0])
                             - 1)];
                        rtb_Switch_m2 = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<int32_T>
                            (localDW->obj.WaypointIndex + 1.0) +
                            waypointsIn->size[0]) - 1)];
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                            waypointsIn->data[static_cast<int32_T>
                            (static_cast<int32_T>(static_cast<int32_T>
                              (waypointsIn->size[0] << 1) + static_cast<int32_T>
                              (localDW->obj.WaypointIndex)) - 1)];
                        rtb_Up = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<int32_T>
                            (localDW->obj.WaypointIndex + 1.0) +
                            static_cast<int32_T>(waypointsIn->size[0] << 1)) - 1)];
                    }

                    rtb_Sum1_idx_0 = stateNew_idx_2 -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                    rtb_TmpSignalConversionAtOrbitF_tmp = rtb_Sum_ow -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                    rtb_Switch_p_tmp = rtb_Switch_m2 -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1];
                    stateNew_idx_5 = rtb_Py_n -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1];
                    lambda_tmp_tmp = rtb_Up -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2];
                    rtb_Switch_tmp = rtb_Down -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2];
                    rtb_Switch = ((stateNew_idx_5 * rtb_Switch_p_tmp +
                                   rtb_TmpSignalConversionAtOrbitF_tmp *
                                   rtb_Sum1_idx_0) + rtb_Switch_tmp *
                                  lambda_tmp_tmp) / ((rtb_Switch_p_tmp *
                        rtb_Switch_p_tmp + rtb_Sum1_idx_0 * rtb_Sum1_idx_0) +
                        lambda_tmp_tmp * lambda_tmp_tmp);
                    if (rtb_Switch < 0.0) {
                        rtb_Sum_gu[0] = rtb_TmpSignalConversionAtOrbitF_tmp;
                        rtb_Sum_gu[1] = stateNew_idx_5;
                        rtb_Sum_gu[2] = rtb_Switch_tmp;
                        rtb_Switch = ImmedMission_norm_pv(rtb_Sum_gu);
                    } else if (rtb_Switch > 1.0) {
                        rtb_Sum_gu[0] = rtb_Sum_ow - stateNew_idx_2;
                        rtb_Sum_gu[1] = rtb_Py_n - rtb_Switch_m2;
                        rtb_Sum_gu[2] = rtb_Down - rtb_Up;
                        rtb_Switch = ImmedMission_norm_pv(rtb_Sum_gu);
                    } else {
                        rtb_Sum_gu[0] = rtb_Sum_ow - (rtb_Switch *
                            rtb_Sum1_idx_0 +
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
                        rtb_Sum_gu[1] = rtb_Py_n - (rtb_Switch *
                            rtb_Switch_p_tmp +
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1]);
                        rtb_Sum_gu[2] = rtb_Down - (rtb_Switch * lambda_tmp_tmp
                            + rtb_TmpSignalConversionAtRotateATMissionHdgInport1[
                            2]);
                        rtb_Switch = ImmedMission_norm_pv(rtb_Sum_gu);
                    }

                    if (localDW->obj.LastWaypointFlag) {
                        rtb_Switch = (((rtb_Sum_ow -
                                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                        [0]) * (stateNew_idx_2 -
                                                rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                                [0]) + (rtb_Py_n -
                                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                        [1]) * (rtb_Switch_m2 -
                                                rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                                [1])) + (rtb_Down -
                                       rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                       [2]) * (rtb_Up -
                                               rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                               [2])) / (((stateNew_idx_2 -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0])
                            * (stateNew_idx_2 -
                               rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                               [0]) + (rtb_Switch_m2 -
                                       rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                       [1]) * (rtb_Switch_m2 -
                                               rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                               [1])) + (rtb_Up -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2])
                            * (rtb_Up -
                               rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                               [2]));
                        rtb_Sum_gu[0] = rtb_Sum_ow - (rtb_Switch *
                            rtb_Sum1_idx_0 +
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
                        rtb_Sum_gu[1] = rtb_Py_n - (rtb_Switch *
                            rtb_Switch_p_tmp +
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1]);
                        rtb_Sum_gu[2] = rtb_Down - (rtb_Switch * lambda_tmp_tmp
                            + rtb_TmpSignalConversionAtRotateATMissionHdgInport1[
                            2]);
                        rtb_Switch = ImmedMission_norm_pv(rtb_Sum_gu);
                    }

                    rtb_Down = std::abs(rtb_Switch);
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                            (static_cast<int32_T>(std::isinf(rtb_Down)) ^ 1))) &
                          static_cast<int32_T>(static_cast<boolean_T>(
                            static_cast<int32_T>(static_cast<int32_T>(std::isnan
                              (rtb_Down)) ^ 1)))))) {
                        if (rtb_Down <= 2.2250738585072014E-308) {
                            rtb_Py_n = 4.94065645841247E-324;
                            rtb_Abs1 = 4.94065645841247E-324;
                        } else {
                            frexp(rtb_Down, &rtb_BiasNumUAV);
                            rtb_Py_n = std::ldexp(1.0, static_cast<int32_T>
                                                  (rtb_BiasNumUAV - 53));
                            frexp(rtb_Down, &rtb_BiasOldIdx);
                            rtb_Abs1 = std::ldexp(1.0, static_cast<int32_T>
                                                  (rtb_BiasOldIdx - 53));
                        }
                    } else {
                        rtb_Py_n = (rtNaN);
                        rtb_Abs1 = (rtNaN);
                    }

                    if (localDW->obj.LookaheadDistance <= std::fmax(std::sqrt
                            (rtb_Py_n), 5.0 * rtb_Abs1) + rtb_Switch) {
                        localDW->obj.LookaheadDistance =
                            localDW->obj.LookaheadFactor * rtb_Switch;
                    }

                    rtb_Py_n =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] -
                        rtb_Sum_ow;
                    rtb_Down =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] -
                        rtb_Switch_k;
                    rtb_Abs1 = ((stateNew_idx_2 -
                                 rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                 [0]) * (stateNew_idx_2 -
                                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                         [0]) + (rtb_Switch_m2 -
                                 rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                 [1]) * (rtb_Switch_m2 -
                                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                         [1])) + (rtb_Up -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2]) *
                        (rtb_Up -
                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2]);
                    rtb_Sum1_idx_1 =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] -
                        rtb_Sum1_idx_1;
                    rtb_Switch = ((rtb_Sum1_idx_0 * rtb_Py_n + rtb_Switch_p_tmp *
                                   rtb_Down) + lambda_tmp_tmp * rtb_Sum1_idx_1) *
                        2.0;
                    rtb_Py_n = std::sqrt(rtb_Switch * rtb_Switch - (((rtb_Py_n *
                                            rtb_Py_n + rtb_Down * rtb_Down) +
                                           rtb_Sum1_idx_1 * rtb_Sum1_idx_1) -
                                          localDW->obj.LookaheadDistance *
                                          localDW->obj.LookaheadDistance) * (4.0
                                          * rtb_Abs1));
                    rtb_Abs1 = std::fmax((-rtb_Switch + rtb_Py_n) / 2.0 /
                                         rtb_Abs1, (-rtb_Switch - rtb_Py_n) /
                                         2.0 / rtb_Abs1);
                    rtb_Up = (1.0 - rtb_Abs1) *
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] +
                        rtb_Abs1 * rtb_Up;
                    rtb_Abs1 = rt_atan2d_snf(((1.0 - rtb_Abs1) *
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] +
                        rtb_Abs1 * rtb_Switch_m2) - rtb_Switch_k, ((1.0 -
                        rtb_Abs1) *
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] +
                        rtb_Abs1 * stateNew_idx_2) - rtb_Sum_ow);

                    // MATLABSystem: '<S57>/Waypoint Follower' incorporates:
                    //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
                    //   SignalConversion generated from: '<S57>/Waypoint Follower'

                    localDW->WaypointFollower_o5 = 0U;
                    rtb_Compare_lh = false;
                    if (localDW->obj.LastWaypointFlag) {
                        rtb_Compare_lh = true;
                    }

                    if (rtb_Compare_lh) {
                        // MATLABSystem: '<S57>/Waypoint Follower'
                        localDW->WaypointFollower_o5 = 1U;
                    }

                    localDW->obj.LastWaypointFlag = false;
                }
            }

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            ImmedMission_emxFree_real_T(&tmp_0);
            ImmedMission_emxFree_real_T(&waypointsIn);

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S7>/Action Port'

            // DataTypeConversion: '<S57>/DoubleStatus'
            *rty_TaskStatus = static_cast<real_T>(localDW->WaypointFollower_o5);

            // BusCreator: '<S57>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S57>/Param4'
            //   Gain: '<S57>/Down2Height'
            //   MATLABSystem: '<S57>/Waypoint Follower'

            rty_GuidanceCMD->Height = -rtb_Up;
            rty_GuidanceCMD->AirSpeed = static_cast<real_T>
                (rtu_MissionInput->params.Param4);
            rty_GuidanceCMD->HeadingAngle = rtb_Abs1;

            // Sum: '<S58>/Add3' incorporates:
            //   Product: '<S58>/Element product'

            rtb_Switch = rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                localDW->Minus[1] - localDW->Minus[0] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

            // Signum: '<S57>/Sign'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Switch)) ^ 1))) {
                if (rtb_Switch < 0.0) {
                    rtb_Switch = -1.0;
                } else {
                    rtb_Switch = static_cast<real_T>(rtb_Switch > 0.0);
                }
            }

            // End of Signum: '<S57>/Sign'

            // Chart: '<S57>/TriggerCalibrStart' incorporates:
            //   Product: '<S57>/Product'

            // Gateway: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
            localDW->xSign_prev = localDW->xSign_start;
            localDW->xSign_start = rtb_Switch;

            // During: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
            if (static_cast<uint32_T>(localDW->is_active_c7_ImmedMission) == 0U)
            {
                localDW->xSign_prev = rtb_Switch;

                // Entry: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
                localDW->is_active_c7_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
                // Transition: '<S62>:2'
                localDW->is_c7_ImmedMission = ImmedMission_IN_Waiting;

                // Entry 'Waiting': '<S62>:1'
                rtb_Ctrl = false;
            } else if (localDW->is_c7_ImmedMission == ImmedMission_IN_Running) {
                // During 'Running': '<S62>:3'
                rtb_Ctrl = true;

                // During 'Waiting': '<S62>:1'
            } else if (static_cast<boolean_T>(static_cast<int32_T>
                        ((localDW->Minus[0] *
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                          localDW->Minus[1] *
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[1] < 0.0)
                         & (localDW->xSign_prev != localDW->xSign_start)))) {
                // Transition: '<S62>:4'
                localDW->is_c7_ImmedMission = ImmedMission_IN_Running;

                // Entry 'Running': '<S62>:3'
                rtb_Ctrl = true;
            } else {
                rtb_Ctrl = false;
            }

            // End of Chart: '<S57>/TriggerCalibrStart'
            rtb_Compare_lh = false;

            // SignalConversion generated from: '<S7>/ControlSwitch' incorporates:
            //   Constant: '<S57>/ShiftSimUAV'

            rty_ControlSwitch[0] = rtb_Ctrl;
            rty_ControlSwitch[1] = rtb_Ctrl;

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
        }
        break;

      case 3:
        {
            ZCEventType zcEvent;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // SystemReset for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
                //   ActionPort: '<S8>/Action Port'

                // SystemReset for Triggered SubSystem: '<S111>/WayPointGen'
                // SystemReset for SwitchCase: '<S1>/Switch Case'
                localZCE->WayPointGen_Trig_ZCE = NEG_ZCSIG;

                // End of SystemReset for SubSystem: '<S111>/WayPointGen'
                ImmedMission_Altitude_Reset(&localDW->Altitude);
                ImmedMission_Altitude_Reset(&localDW->Heading);

                // End of SystemReset for SubSystem: '<S1>/Mode132_pAttack'
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
            //   ActionPort: '<S8>/Action Port'

            // SignalConversion generated from: '<S111>/Altitude' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   Gain: '<S3>/Gain2'

            rtb_TmpSignalConversionAtAltitudeInport1[0] = rtb_Switch;
            rtb_TmpSignalConversionAtAltitudeInport1[1] = rtb_Py_n;

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtAltitudeInport1[2] = -rtb_Up;

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtAltitudeInport1[3] = rtb_Abs1;

            // Reshape: '<S111>/RowVecPose' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Py_n;

            // Sum: '<S113>/Sum1' incorporates:
            //   DataStoreRead: '<S111>/LatitudeGCS'
            //   Switch: '<S128>/Switch'

            rtb_Sum1_idx_0 = rtu_MissionInput->MissionLocation.Lat - LatitudeGCS;

            // Switch: '<S122>/Switch' incorporates:
            //   Abs: '<S122>/Abs'
            //   Bias: '<S122>/Bias'
            //   Bias: '<S122>/Bias1'
            //   Constant: '<S122>/Constant2'
            //   Constant: '<S123>/Constant'
            //   Math: '<S122>/Math Function1'
            //   RelationalOperator: '<S123>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                rtb_Abs1 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
            } else {
                rtb_Abs1 = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S122>/Switch'

            // Abs: '<S119>/Abs1'
            rtb_Py_n = std::abs(rtb_Abs1);

            // Switch: '<S119>/Switch' incorporates:
            //   Bias: '<S119>/Bias'
            //   Bias: '<S119>/Bias1'
            //   Constant: '<S115>/Constant'
            //   Constant: '<S115>/Constant1'
            //   Constant: '<S121>/Constant'
            //   Gain: '<S119>/Gain'
            //   Product: '<S119>/Divide1'
            //   RelationalOperator: '<S121>/Compare'
            //   Switch: '<S115>/Switch1'

            if (rtb_Py_n > 90.0) {
                // Signum: '<S119>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Abs1)) ^ 1))) {
                    if (rtb_Abs1 < 0.0) {
                        rtb_Abs1 = -1.0;
                    } else {
                        rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                    }
                }

                // End of Signum: '<S119>/Sign1'
                rtb_Abs1 *= -(rtb_Py_n + -90.0) + 90.0;
                nm1d2 = 180;
            } else {
                nm1d2 = 0;
            }

            // End of Switch: '<S119>/Switch'

            // Sum: '<S115>/Sum' incorporates:
            //   DataStoreRead: '<S111>/LongitudeGCS'
            //   Sum: '<S113>/Sum1'
            //   Sum: '<S116>/Sum'

            rtb_Py_n = (rtu_MissionInput->MissionLocation.Lon - LongitudeGCS) +
                static_cast<real_T>(nm1d2);

            // Switch: '<S120>/Switch' incorporates:
            //   Abs: '<S120>/Abs'
            //   Bias: '<S120>/Bias'
            //   Bias: '<S120>/Bias1'
            //   Constant: '<S120>/Constant2'
            //   Constant: '<S124>/Constant'
            //   Math: '<S120>/Math Function1'
            //   RelationalOperator: '<S124>/Compare'

            if (std::abs(rtb_Py_n) > 180.0) {
                rtb_Py_n = rt_modd_snf(rtb_Py_n + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S120>/Switch'

            // UnitConversion: '<S118>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Abs1;
            rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Py_n;

            // Trigonometry: '<S134>/Trigonometric Function1'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Py_n = std::sin(rtb_Switch_tmp);

            // Sum: '<S134>/Sum1' incorporates:
            //   Constant: '<S134>/Constant'
            //   Product: '<S134>/Product1'

            rtb_Py_n = 1.0 - 0.0066943799901413295 * rtb_Py_n * rtb_Py_n;

            // Product: '<S132>/Product1' incorporates:
            //   Constant: '<S132>/Constant1'
            //   Sqrt: '<S132>/sqrt'

            rtb_Abs1 = 6.378137E+6 / std::sqrt(rtb_Py_n);

            // Product: '<S117>/dNorth' incorporates:
            //   Constant: '<S132>/Constant2'
            //   Product: '<S132>/Product3'
            //   Trigonometry: '<S132>/Trigonometric Function1'

            rtb_Py_n = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Abs1 *
                0.99330562000985867 / rtb_Py_n);

            // Product: '<S117>/dEast' incorporates:
            //   Constant: '<S132>/Constant3'
            //   Product: '<S132>/Product4'
            //   Trigonometry: '<S132>/Trigonometric Function'
            //   Trigonometry: '<S132>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1 * std::cos
                (rtb_Switch_tmp)) * rtb_Sum1_idx_1;

            // Reshape: '<S111>/ReshapeRowVec' incorporates:
            //   DataStoreRead: '<S111>/AltitudeGCS'
            //   Gain: '<S111>/inverse'
            //   Product: '<S117>/x*cos'
            //   Product: '<S117>/x*sin'
            //   Product: '<S117>/y*cos'
            //   Product: '<S117>/y*sin'
            //   Sum: '<S113>/Sum'
            //   Sum: '<S117>/Sum2'
            //   Sum: '<S117>/Sum3'
            //   UnaryMinus: '<S113>/Ze2height'

            rtb_Sum_gu[0] = rtb_Abs1 * 0.0 + rtb_Py_n;
            rtb_Sum_gu[1] = rtb_Abs1 - rtb_Py_n * 0.0;
            rtb_Sum_gu[2] = -(rtu_MissionInput->MissionLocation.Alt +
                              -AltitudeGCS);

            // Outputs for Triggered SubSystem: '<S111>/WayPointGen' incorporates:
            //   TriggerPort: '<S114>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &localZCE->WayPointGen_Trig_ZCE,
                               (1.0));
            if (zcEvent != NO_ZCEVENT) {
                // Concatenate: '<S114>/Matrix Concatenate' incorporates:
                //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
                //   Gain: '<S3>/Gain2'
                //   Reshape: '<S111>/ReshapeRowVec'
                //   Reshape: '<S111>/RowVecPose'
                //   SignalConversion generated from: '<S114>/MissionPos'

                localDW->MatrixConcatenate[0] = rtb_Switch;
                localDW->MatrixConcatenate[1] = rtb_Sum_gu[0];
                localDW->MatrixConcatenate[2] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                localDW->MatrixConcatenate[3] = rtb_Sum_gu[1];

                // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
                localDW->MatrixConcatenate[4] = -rtb_Up;

                // End of Outputs for SubSystem: '<Root>/RealState2Pose'
                localDW->MatrixConcatenate[5] = rtb_Sum_gu[2];
            }

            // End of Outputs for SubSystem: '<S111>/WayPointGen'
            ImmedMission_Altitude(rtb_TmpSignalConversionAtAltitudeInport1,
                                  localDW->MatrixConcatenate, 50.0,
                                  &localDW->Altitude);

            // Sum: '<S112>/Sum' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   Constant: '<S111>/Constant'
            //   Constant: '<S111>/InitTrigger'
            //   Reshape: '<S111>/ReshapeRowVec'
            //   Reshape: '<S111>/RowVecPose'

            rtb_Switch -= rtb_Sum_gu[0];

            // DotProduct: '<S112>/Dot Product'
            rtb_Abs1 = rtb_Switch * rtb_Switch;

            // Sum: '<S112>/Sum' incorporates:
            //   Reshape: '<S111>/ReshapeRowVec'
            //   Reshape: '<S111>/RowVecPose'

            rtb_Switch = rtb_TmpSignalConversionAtOrbitFollowerInport2[1] -
                rtb_Sum_gu[1];

            // DotProduct: '<S112>/Dot Product'
            rtb_Abs1 += rtb_Switch * rtb_Switch;

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            // Sum: '<S112>/Sum' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   Gain: '<S3>/Gain2'
            //   Reshape: '<S111>/ReshapeRowVec'
            //   Reshape: '<S111>/RowVecPose'

            rtb_Switch = -rtb_Up - rtb_Sum_gu[2];

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'

            // Sqrt: '<S112>/sqrt' incorporates:
            //   DotProduct: '<S112>/Dot Product'

            rtb_sqrt = std::sqrt(rtb_Switch * rtb_Switch + rtb_Abs1);
            ImmedMission_Altitude(rtb_TmpSignalConversionAtAltitudeInport1,
                                  localDW->MatrixConcatenate, rtb_sqrt,
                                  &localDW->Heading);

            // Switch: '<S111>/Switch' incorporates:
            //   Logic: '<S111>/AND'

            if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                    (localDW->Altitude.Altitude_o5) != 0) & (static_cast<int32_T>
                    (localDW->Heading.Altitude_o5) != 0)))) {
                // DataTypeConversion: '<S111>/DoubleStatus' incorporates:
                //   Constant: '<S111>/Attack'

                *rty_TaskStatus = 658475.0;
            } else {
                // DataTypeConversion: '<S111>/DoubleStatus' incorporates:
                //   Constant: '<S111>/Zero'

                *rty_TaskStatus = 0.0;
            }

            // End of Switch: '<S111>/Switch'

            // BusCreator: '<S111>/GuidanceCMDBusCreator' incorporates:
            //   Gain: '<S111>/Down2Height'

            rty_GuidanceCMD->Height = -localDW->Altitude.Altitude_o1[2];
            rty_GuidanceCMD->AirSpeed = 0.0;
            rty_GuidanceCMD->HeadingAngle = localDW->Heading.HeadingAngle;
            rtb_Compare_lh = false;
            rty_ControlSwitch[0] = true;
            rty_ControlSwitch[1] = false;

            // End of Outputs for SubSystem: '<S1>/Mode132_pAttack'
        }
        break;

      case 4:
        {
            boolean_T guard1;
            boolean_T guard2;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // SystemReset for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU' incorporates:
                //   ActionPort: '<S10>/Action Port'

                // SystemReset for Atomic SubSystem: '<S145>/SailDistance'
                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S147>/EnableSailShift'

                localDW->temporalCounter_i1 = 0U;
                localDW->is_active_c12_ImmedMission = 0U;
                localDW->is_c12_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;

                // End of SystemReset for SubSystem: '<S145>/SailDistance'
                // End of SystemReset for SubSystem: '<S1>/Mode254_ShiftEarthENU' 
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU' incorporates:
            //   ActionPort: '<S10>/Action Port'

            rtb_Compare_lh = true;

            // Outputs for Atomic SubSystem: '<S145>/SailDistance'
            // Outputs for Enabled SubSystem: '<S147>/SailShift' incorporates:
            //   EnablePort: '<S149>/Enable'

            // Gain: '<S146>/Gain1' incorporates:
            //   Constant: '<S145>/Constant'
            //   Gain: '<S150>/Gain1'

            rtb_Switch = 0.017453292519943295 *
                rtu_MissionInput->StartPosition.degHDG;

            // End of Outputs for SubSystem: '<S147>/SailShift'
            // End of Outputs for SubSystem: '<S145>/SailDistance'

            // SignalConversion generated from: '<S145>/Coordinate Transformation Conversion' incorporates:
            //   Constant: '<S145>/Zero'
            //   Gain: '<S146>/Gain1'

            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                0] = rtb_Switch;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                1] = 0.0;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                2] = 0.0;
            ImmedMission_CoordinateTransformationConversion
                (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e,
                 &localDW->CoordinateTransformationConversion);

            // Product: '<S145>/Product' incorporates:
            //   MATLABSystem: '<S145>/Coordinate Transformation Conversion'
            //   Reshape: '<S145>/Reshape'

            colIdx = 0;
            for (nm1d2 = 0; nm1d2 < 3; nm1d2++) {
                rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2] = 0.0;
                rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2] +=
                    localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                    [colIdx] * rtu_MissionInput->StartPosition.Lat;
                rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2] +=
                    localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                    [static_cast<int32_T>(colIdx + 1)] *
                    rtu_MissionInput->StartPosition.Lon;
                rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2] +=
                    localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                    [static_cast<int32_T>(colIdx + 2)] *
                    rtu_MissionInput->StartPosition.Alt;
                colIdx = static_cast<int32_T>(colIdx + 3);
            }

            // End of Product: '<S145>/Product'

            // Outputs for Atomic SubSystem: '<S145>/SailDistance'
            // Chart: '<S147>/EnableSailShift'
            if (static_cast<uint32_T>(localDW->temporalCounter_i1) < 127U) {
                localDW->temporalCounter_i1 = static_cast<uint8_T>
                    (static_cast<uint32_T>(static_cast<uint32_T>
                      (localDW->temporalCounter_i1) + 1U));
            }

            // Gateway: ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
            // During: ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
            guard1 = false;
            guard2 = false;
            if (static_cast<uint32_T>(localDW->is_active_c12_ImmedMission) == 0U)
            {
                // Entry: ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
                localDW->is_active_c12_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
                // Transition: '<S148>:5'
                localDW->is_c12_ImmedMission = ImmedMission_IN_NotShift;
                localDW->temporalCounter_i1 = 0U;

                // Entry 'NotShift': '<S148>:4'
                guard1 = true;
            } else if (localDW->is_c12_ImmedMission == ImmedMission_IN_NotShift)
            {
                // During 'NotShift': '<S148>:4'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((static_cast<uint32_T>
                        (localDW->temporalCounter_i1) >= 100U) &
                                            (rtu_MissionInput->params.Param5 !=
                        0.0F)))) {
                    // Transition: '<S148>:8'
                    localDW->is_c12_ImmedMission = ImmedMission_IN_Shift;

                    // Entry 'Shift': '<S148>:6'
                    guard2 = true;
                } else {
                    guard1 = true;
                }

                // During 'Shift': '<S148>:6'
            } else if (rtu_MissionInput->params.Param5 == 0.0F) {
                // Transition: '<S148>:9'
                localDW->is_c12_ImmedMission = ImmedMission_IN_NotShift;
                localDW->temporalCounter_i1 = 0U;

                // Entry 'NotShift': '<S148>:4'
                guard1 = true;
            } else {
                guard2 = true;
            }

            if (guard2) {
                // Outputs for Enabled SubSystem: '<S147>/SailShift' incorporates:
                //   EnablePort: '<S149>/Enable'

                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (localDW->SailShift_MODE) ^ 1))) {
                    // InitializeConditions for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' 
                    localDW->DiscreteTimeIntegrator_DSTATE[0] = 0.0;
                    localDW->DiscreteTimeIntegrator_DSTATE[1] = 0.0;
                    localDW->SailShift_MODE = true;
                }

                // Product: '<S149>/Product' incorporates:
                //   Trigonometry: '<S149>/Cos'
                //   Trigonometry: '<S149>/Sin'

                localDW->Product[0] = static_cast<real_T>
                    (rtu_MissionInput->params.Param5) * std::cos(rtb_Switch);
                localDW->Product[1] = static_cast<real_T>
                    (rtu_MissionInput->params.Param5) * std::sin(rtb_Switch);

                // DiscreteIntegrator: '<S149>/Discrete-Time Integrator'
                localDW->DiscreteTimeIntegrator[0] = 0.05 * localDW->Product[0]
                    + localDW->DiscreteTimeIntegrator_DSTATE[0];
                localDW->DiscreteTimeIntegrator[1] = 0.05 * localDW->Product[1]
                    + localDW->DiscreteTimeIntegrator_DSTATE[1];

                // End of Outputs for SubSystem: '<S147>/SailShift'

                // Switch: '<S147>/Switch'
                rtb_Sum1_idx_0 = localDW->DiscreteTimeIntegrator[0];
                rtb_Sum1_idx_1 = localDW->DiscreteTimeIntegrator[1];
            }

            if (guard1) {
                // Outputs for Enabled SubSystem: '<S147>/SailShift' incorporates:
                //   EnablePort: '<S149>/Enable'

                localDW->SailShift_MODE = false;

                // End of Outputs for SubSystem: '<S147>/SailShift'

                // Switch: '<S147>/Switch' incorporates:
                //   Constant: '<S147>/Zero'

                rtb_Sum1_idx_0 = 0.0;
                rtb_Sum1_idx_1 = 0.0;
            }

            // End of Chart: '<S147>/EnableSailShift'
            // End of Outputs for SubSystem: '<S145>/SailDistance'

            // Sum: '<S145>/AddEast'
            rtb_Switch = (rtu_SimUAVstate->East +
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[0]) +
                rtb_Sum1_idx_1;

            // Sum: '<S145>/AddHeight'
            rtb_Abs1 = rtu_SimUAVstate->Height +
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Sum: '<S145>/AddNorth'
            rtb_Py_n = (rtu_SimUAVstate->North +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1]) +
                rtb_Sum1_idx_0;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   BusAssignment: '<S145>/Bus Assignment'

            localDW->MergeCollAvoidSimUAV = *rtu_SimUAVstate;

            // BusAssignment: '<S145>/Bus Assignment'
            localDW->MergeCollAvoidSimUAV.North = rtb_Py_n;
            localDW->MergeCollAvoidSimUAV.East = rtb_Switch;
            localDW->MergeCollAvoidSimUAV.Height = rtb_Abs1;
            rty_ControlSwitch[0] = false;
            rty_ControlSwitch[1] = false;

            // SignalConversion generated from: '<S10>/thisTaskStatus' incorporates:
            //   Constant: '<S145>/ControlHdg'
            //   Constant: '<S145>/ControlSpd'

            *rty_TaskStatus = 0.0;

            // End of Outputs for SubSystem: '<S1>/Mode254_ShiftEarthENU'
        }
        break;

      case 5:
        {
            real_T rtb_Sum_ow;
            real_T rtb_Switch_k;
            real_T stateNew_idx_2;
            real_T stateNew_idx_5;

            // Outputs for IfAction SubSystem: '<S1>/Mode253_ShiftBodyXYZ' incorporates:
            //   ActionPort: '<S9>/Action Port'

            rtb_Compare_lh = true;

            // SignalConversion generated from: '<S138>/Coordinate Transformation Conversion' incorporates:
            //   Constant: '<S138>/Constant'

            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[0]
                = rtu_SimUAVstate->HeadingAngle;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[1]
                = rtu_SimUAVstate->FlightPathAngle;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[2]
                = rtu_SimUAVstate->RollAngle;
            ImmedMission_CoordinateTransformationConversion
                (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1,
                 &localDW->CoordinateTransformationConversion_j);

            // Product: '<S138>/Matrix Multiply' incorporates:
            //   MATLABSystem: '<S138>/Coordinate Transformation Conversion'
            //   SignalConversion generated from: '<S138>/Matrix Multiply'

            for (colIdx = 0; colIdx < 3; colIdx++) {
                rtb_Sum_gu[colIdx] = 0.0;
                rtb_Sum_gu[colIdx] +=
                    localDW->CoordinateTransformationConversion_j.CoordinateTransformationConversion
                    [colIdx] * 0.0;
                rtb_Sum_gu[colIdx] +=
                    localDW->CoordinateTransformationConversion_j.CoordinateTransformationConversion
                    [static_cast<int32_T>(colIdx + 3)] *
                    rtu_MissionInput->StartPosition.Lon;
                rtb_Sum_gu[colIdx] +=
                    localDW->CoordinateTransformationConversion_j.CoordinateTransformationConversion
                    [static_cast<int32_T>(colIdx + 6)] *
                    rtu_MissionInput->StartPosition.Alt;
            }

            // End of Product: '<S138>/Matrix Multiply'

            // Sum: '<S138>/AddEast'
            rtb_Abs1 = rtu_SimUAVstate->East + rtb_Sum_gu[1];

            // Sum: '<S138>/AddHeight'
            rtb_Py_n = rtu_SimUAVstate->Height + rtb_Sum_gu[2];

            // Sum: '<S138>/AddNorth'
            rtb_Down = rtu_SimUAVstate->North + rtb_Sum_gu[0];

            // BusAssignment: '<S138>/Bus Assignment'
            rtb_Up = rtu_SimUAVstate->AirSpeed;
            rtb_Sum_ow = rtu_SimUAVstate->HeadingAngle;
            rtb_Switch_k = rtu_SimUAVstate->FlightPathAngle;
            rtb_Sum1_idx_1 = rtu_SimUAVstate->RollAngle;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   BusAssignment: '<S138>/Bus Assignment'

            localDW->MergeCollAvoidSimUAV.RollAngleRate =
                rtu_SimUAVstate->RollAngleRate;

            // Trigonometry: '<S142>/sincos' incorporates:
            //   SignalConversion generated from: '<S142>/sincos'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = std::cos
                (rtb_Sum_ow);
            stateNew_idx_2 = std::sin(rtb_Sum_ow);
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = std::cos
                (rtb_Switch_k);
            rtb_Switch_m2 = std::sin(rtb_Switch_k);
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = std::cos
                (rtb_Sum1_idx_1);
            rtb_Sum1_idx_0 = std::sin(rtb_Sum1_idx_1);

            // Fcn: '<S142>/Fcn11'
            out[0] = rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

            // Fcn: '<S142>/Fcn21' incorporates:
            //   Fcn: '<S142>/Fcn22'

            stateNew_idx_5 = rtb_Switch_m2 * rtb_Sum1_idx_0;
            out[1] = stateNew_idx_5 *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0] -
                stateNew_idx_2 * rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Fcn: '<S142>/Fcn31' incorporates:
            //   Fcn: '<S142>/Fcn32'

            rtb_Switch_tmp = rtb_Switch_m2 *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
            out[2] = rtb_Switch_tmp *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                stateNew_idx_2 * rtb_Sum1_idx_0;

            // Fcn: '<S142>/Fcn12'
            out[3] = stateNew_idx_2 *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

            // Fcn: '<S142>/Fcn22'
            out[4] = stateNew_idx_5 * stateNew_idx_2 +
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Fcn: '<S142>/Fcn32'
            out[5] = rtb_Switch_tmp * stateNew_idx_2 -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                rtb_Sum1_idx_0;

            // Fcn: '<S142>/Fcn13'
            out[6] = -rtb_Switch_m2;

            // Fcn: '<S142>/Fcn23'
            out[7] = rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                rtb_Sum1_idx_0;

            // Fcn: '<S142>/Fcn33'
            out[8] = rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Product: '<S138>/Product' incorporates:
            //   Concatenate: '<S143>/Vector Concatenate'
            //   Reshape: '<S138>/Reshape'

            colIdx = 0;
            for (nm1d2 = 0; nm1d2 < 3; nm1d2++) {
                rtb_Sum_gu[nm1d2] = 0.0;
                rtb_Sum_gu[nm1d2] += out[colIdx] * rtb_Up;
                rtb_Sum_gu[nm1d2] += out[static_cast<int32_T>(colIdx + 1)] * 0.0;
                rtb_Sum_gu[nm1d2] += out[static_cast<int32_T>(colIdx + 2)] * 0.0;
                colIdx = static_cast<int32_T>(colIdx + 3);
            }

            // End of Product: '<S138>/Product'

            // Outputs for Enabled SubSystem: '<S138>/DivisionByZeroProtection'
            ImmedMission_DivisionByZeroProtection(rtb_Up * std::cos(rtb_Switch_k),
                9.81 * std::tan(rtb_Sum1_idx_1), &localDW->Omega_g);

            // End of Outputs for SubSystem: '<S138>/DivisionByZeroProtection'

            // Product: '<S138>/Divide' incorporates:
            //   Gain: '<S138>/Gravity'
            //   Product: '<S138>/HorizSpd'
            //   Trigonometry: '<S138>/Cos'
            //   Trigonometry: '<S138>/Tan'

            rtb_Switch = rtu_MissionInput->StartPosition.Lat /
                rtu_SimUAVstate->AirSpeed;

            // MATLAB Function: '<S138>/ConstTurnPred' incorporates:
            //   BusAssignment: '<S138>/Bus Assignment'
            //   Gain: '<S138>/Inverse'
            //   Gain: '<S141>/Gain'

            // MATLAB Function 'ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/ConstTurnPred': '<S139>:1' 
            // '<S139>:1:2'
            rtb_Switch_m2 = rtb_Down;
            stateNew_idx_2 = rtb_Abs1;
            rtb_Down = 57.295779513082323 * localDW->Omega_g;
            stateNew_idx_5 = -rtb_Py_n;

            // '<S139>:1:4'
            rtb_Abs1 = std::fmax(std::abs(0.017453292519943295 * rtb_Down),
                                 2.2204460492503131E-16);
            rtb_BiasNumUAV = 0;
            if (rtb_Down < 0.0) {
                rtb_BiasNumUAV = 1;
            }

            if (static_cast<int32_T>(rtb_BiasNumUAV - 1) >= 0) {
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 = -rtb_Abs1;
            }

            if (rtb_Down < 0.0) {
                rtb_Abs1 = rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
            }

            rtb_Py_n = rtb_Abs1 * rtb_Switch;
            rtb_Down = std::sin(rtb_Py_n) / rtb_Abs1;
            rtb_Sum1_idx_0 = (1.0 - std::cos(rtb_Py_n)) / rtb_Abs1;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   BusAssignment: '<S138>/FinalStateBus'

            // '<S139>:1:5'
            localDW->MergeCollAvoidSimUAV.AirSpeed = rtb_Up;
            localDW->MergeCollAvoidSimUAV.HeadingAngle = rtb_Sum_ow;
            localDW->MergeCollAvoidSimUAV.FlightPathAngle = rtb_Switch_k;
            localDW->MergeCollAvoidSimUAV.RollAngle = rtb_Sum1_idx_1;

            // MATLAB Function: '<S138>/ConstTurnPred'
            rtb_Abs1 = rtb_Switch * rtb_Switch * 0.5 * 0.0;

            // BusAssignment: '<S138>/FinalStateBus' incorporates:
            //   Gain: '<S138>/Down2Up'
            //   MATLAB Function: '<S138>/ConstTurnPred'
            //   Product: '<S138>/Product'

            localDW->MergeCollAvoidSimUAV.North = ((rtb_Down * rtb_Sum_gu[0] +
                rtb_Switch_m2) - rtb_Sum1_idx_0 * rtb_Sum_gu[1]) + rtb_Abs1;
            localDW->MergeCollAvoidSimUAV.East = ((rtb_Sum1_idx_0 * rtb_Sum_gu[0]
                + stateNew_idx_2) + rtb_Down * rtb_Sum_gu[1]) + rtb_Abs1;
            localDW->MergeCollAvoidSimUAV.Height = -((rtb_Sum_gu[2] * rtb_Switch
                + stateNew_idx_5) + rtb_Abs1);
            rty_ControlSwitch[0] = false;
            rty_ControlSwitch[1] = false;

            // SignalConversion generated from: '<S9>/thisTaskStatus' incorporates:
            //   Constant: '<S138>/ControlHdg'
            //   Constant: '<S138>/ControlSpd'

            *rty_TaskStatus = 0.0;

            // End of Outputs for SubSystem: '<S1>/Mode253_ShiftBodyXYZ'
        }
        break;

      default:
        // Outputs for IfAction SubSystem: '<S1>/AvoidInterPlaneCollision' incorporates:
        //   ActionPort: '<S4>/Action Port'

        // Logic: '<S12>/AND' incorporates:
        //   Constant: '<S12>/ControlSpd'

        rty_ControlSwitch[0] = false;
        rty_ControlSwitch[1] = false;

        // DataTypeConversion: '<S12>/Cast To Double'
        *rty_TaskStatus = 0.0;

        // BusCreator: '<S12>/GuidanceCMDBusCreator'
        rty_GuidanceCMD->Height = 0.0;
        rty_GuidanceCMD->AirSpeed = 0.0;
        rty_GuidanceCMD->HeadingAngle = 0.0;

        // Outputs for Enabled SubSystem: '<S14>/DivisionByZeroProtection'
        ImmedMission_DivisionByZeroProtection(rtu_RealUAVState->AirSpeed_mps *
            std::cos(0.017453292519943295 *
                     rtu_RealUAVState->FlightPathAngle_deg), 9.81 * std::tan
            (0.017453292519943295 * rtu_RealUAVState->RollAngle_deg),
            &localDW->Omega);

        // End of Outputs for SubSystem: '<S14>/DivisionByZeroProtection'

        // MATLAB Function: '<S12>/pdist2' incorporates:
        //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
        //   Gain: '<S14>/Gravity'
        //   Gain: '<S152>/Gain1'
        //   Gain: '<S153>/Gain1'
        //   Product: '<S14>/HorizSpd'
        //   Trigonometry: '<S14>/Cos'
        //   Trigonometry: '<S14>/Tan'

        // MATLAB Function 'ConstTurnPredState/MATLAB Function': '<S18>:1'
        // '<S18>:1:2'
        // '<S18>:1:4'
        // '<S18>:1:5'
        // MATLAB Function 'ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/pdist2': '<S16>:1' 
        if (rtu_OtherUAVstate_DIMS1[0] == 0) {
            nm1d2 = 0;
        } else {
            nm1d2 = rtu_OtherUAVstate_DIMS1[0];
        }

        // '<S16>:1:2'
        localDW->SFunction_DIMS2 = nm1d2;

        // End of MATLAB Function: '<S12>/pdist2'
        rtb_Compare_lh = false;

        // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
        //   Constant: '<S4>/ShiftSimUAV'
        //   SignalConversion generated from: '<S4>/SimUAVstate'

        localDW->MergeCollAvoidSimUAV = *rtu_SimUAVstate;

        // End of Outputs for SubSystem: '<S1>/AvoidInterPlaneCollision'
        break;
    }

    // Switch: '<Root>/SwitchShiftSimUAV'
    if (rtb_Compare_lh) {
        *rty_FinalSimUAVState = localDW->MergeCollAvoidSimUAV;
    } else {
        *rty_FinalSimUAVState = *rtu_SimUAVstate;
    }

    // End of Switch: '<Root>/SwitchShiftSimUAV'
    ImmedMission_emxFree_real_T(&e);
}

// Update for referenced model: 'ImmedMission'
void ImmedMission_Update(const uint8_T *rtu_RealUAVEngaged, DW_ImmedMission_f_T *
    localDW)
{
    // Update for Memory: '<S1>/Memory'
    localDW->Memory_PreviousInput = localDW->WaypointFollower_o5;

    // Update for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput_j = *rtu_RealUAVEngaged;

    // Update for SwitchCase: '<S1>/Switch Case'
    if (static_cast<int32_T>(localDW->SwitchCase_ActiveSubsystem) == 4) {
        // Update for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU' incorporates:
        //   ActionPort: '<S10>/Action Port'

        // Update for Atomic SubSystem: '<S145>/SailDistance'
        // Update for Enabled SubSystem: '<S147>/SailShift' incorporates:
        //   EnablePort: '<S149>/Enable'

        if (localDW->SailShift_MODE) {
            // Update for DiscreteIntegrator: '<S149>/Discrete-Time Integrator'
            localDW->DiscreteTimeIntegrator_DSTATE[0] = 0.05 * localDW->Product
                [0] + localDW->DiscreteTimeIntegrator[0];
            localDW->DiscreteTimeIntegrator_DSTATE[1] = 0.05 * localDW->Product
                [1] + localDW->DiscreteTimeIntegrator[1];
        }

        // End of Update for SubSystem: '<S147>/SailShift'
        // End of Update for SubSystem: '<S145>/SailDistance'
        // End of Update for SubSystem: '<S1>/Mode254_ShiftEarthENU'
    }

    // End of Update for SwitchCase: '<S1>/Switch Case'
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
