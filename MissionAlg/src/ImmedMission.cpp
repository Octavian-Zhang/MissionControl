//
// File: ImmedMission.cpp
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 3.28
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Aug 10 13:59:36 2022
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
#include "rtw_linux.h"
#include "rt_modd_snf.h"
#include "linspace_Q5Un26da.h"
#include <stddef.h>
#include <cstdlib>
#include "ImmedMission_private.h"
#include "zero_crossing_types.h"

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

// Named constants for Chart: '<S24>/HdgHoldLogic'
const uint8_T ImmedMission_IN_OutOfRange{ 1U };

const uint8_T ImmedMission_IN_Turning{ 2U };

const uint8_T ImmedMission_IN_WithInRange{ 3U };

// Named constants for Chart: '<S58>/TriggerCalibrStart'
const uint8_T ImmedMission_IN_Running{ 1U };

const uint8_T ImmedMission_IN_Waiting{ 2U };

// Named constants for Chart: '<S148>/EnableSailShift'
const uint8_T ImmedMission_IN_NotShift{ 1U };

const uint8_T ImmedMission_IN_Shift{ 2U };

real_T ImmedMission::ImmedMission_norm(const real_T x[3])
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
void ImmedMission::ImmedMission_Altitude_Init(self_Altitude_ImmedMission_T
    *ImmedMission_self_arg, const real_T rtu_0[4], const real_T rtu_1[6], real_T
    rtu_2)
{
    (void) (rtu_0);
    (void) (rtu_1);
    (void) (rtu_2);

    // Start for MATLABSystem: '<S112>/Altitude'
    ImmedMission_self_arg->dwork.obj.LastWaypointFlag = false;
    ImmedMission_self_arg->dwork.obj.StartFlag = true;
    ImmedMission_self_arg->dwork.obj.LookaheadFactor = 1.01;
    ImmedMission_self_arg->dwork.objisempty = true;
    ImmedMission_self_arg->dwork.obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S112>/Altitude'
    ImmedMission_self_arg->dwork.obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 6; i++) {
        // InitializeConditions for MATLABSystem: '<S112>/Altitude'
        ImmedMission_self_arg->dwork.obj.WaypointsInternal[i] = (rtNaN);
    }
}

// System reset for atomic system:
void ImmedMission::ImmedMission_Altitude_Reset(self_Altitude_ImmedMission_T
    *ImmedMission_self_arg)
{
    // InitializeConditions for MATLABSystem: '<S112>/Altitude'
    ImmedMission_self_arg->dwork.obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 6; i++) {
        ImmedMission_self_arg->dwork.obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of InitializeConditions for MATLABSystem: '<S112>/Altitude'
}

// Output and update for atomic system:
void ImmedMission::ImmedMission_Altitude(self_Altitude_ImmedMission_T
    *ImmedMission_self_arg, const real_T rtu_0[4], const real_T rtu_1[6], real_T
    rtu_2)
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

    // MATLABSystem: '<S112>/Altitude'
    lambda = rtu_2;
    ImmedMission_self_arg->dwork.obj.LookaheadDistFlag = 0U;
    if (rtu_2 < 0.1) {
        lambda = 0.1;
        ImmedMission_self_arg->dwork.obj.LookaheadDistFlag = 1U;
    }

    ImmedMission_self_arg->dwork.obj.InitialPose[0] = 0.0;
    ImmedMission_self_arg->dwork.obj.InitialPose[1] = 0.0;
    ImmedMission_self_arg->dwork.obj.InitialPose[2] = 0.0;
    ImmedMission_self_arg->dwork.obj.InitialPose[3] = 0.0;
    p = false;
    p_0 = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 6)) {
        if ((ImmedMission_self_arg->dwork.obj.WaypointsInternal[b_k] ==
                rtu_1[b_k]) || (std::isnan
                                (ImmedMission_self_arg->dwork.obj.WaypointsInternal
                                 [b_k]) && std::isnan(rtu_1[b_k]))) {
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
            ImmedMission_self_arg->dwork.obj.WaypointsInternal[b_k] = rtu_1[b_k];
        }

        ImmedMission_self_arg->dwork.obj.WaypointIndex = 1.0;
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

    ImmedMission_self_arg->dwork.obj.NumWaypoints = static_cast<real_T>
        (c_size_idx_0);
    ImmedMission_self_arg->dwork.obj.LookaheadDistance = lambda;
    if (c_size_idx_0 == 0) {
        // MATLABSystem: '<S112>/Altitude'
        ImmedMission_self_arg->dwork.Altitude_o1[0] = lambda * std::cos(rtu_0[3])
            + rtu_0[0];
        ImmedMission_self_arg->dwork.Altitude_o1[1] = lambda * std::sin(rtu_0[3])
            + rtu_0[1];
        ImmedMission_self_arg->dwork.Altitude_o1[2] = lambda * 0.0 + rtu_0[2];

        // MATLABSystem: '<S112>/Altitude'
        ImmedMission_self_arg->dwork.HeadingAngle = rtu_0[3];

        // MATLABSystem: '<S112>/Altitude'
        ImmedMission_self_arg->dwork.Altitude_o5 = 1U;
    } else {
        boolean_T guard1{ false };

        guard1 = false;
        if (c_size_idx_0 == 1) {
            if (ImmedMission_self_arg->dwork.obj.StartFlag) {
                ImmedMission_self_arg->dwork.obj.InitialPose[0] = rtu_0[0];
                ImmedMission_self_arg->dwork.obj.InitialPose[1] = rtu_0[1];
                ImmedMission_self_arg->dwork.obj.InitialPose[2] = rtu_0[2];
                ImmedMission_self_arg->dwork.obj.InitialPose[3] = rtu_0[3];
            }

            b_waypointsIn[0] = b_waypointsIn_data[0] - rtu_0[0];
            b_waypointsIn[1] = b_waypointsIn_data[1] - rtu_0[1];
            b_waypointsIn[2] = b_waypointsIn_data[2] - rtu_0[2];
            if (ImmedMission_norm(b_waypointsIn) < 1.4901161193847656E-8) {
                // MATLABSystem: '<S112>/Altitude'
                ImmedMission_self_arg->dwork.Altitude_o1[0] = lambda * std::cos
                    (rtu_0[3]) + rtu_0[0];
                ImmedMission_self_arg->dwork.Altitude_o1[1] = lambda * std::sin
                    (rtu_0[3]) + rtu_0[1];
                ImmedMission_self_arg->dwork.Altitude_o1[2] = lambda * 0.0 +
                    rtu_0[2];

                // MATLABSystem: '<S112>/Altitude'
                ImmedMission_self_arg->dwork.HeadingAngle = rtu_0[3];

                // MATLABSystem: '<S112>/Altitude'
                ImmedMission_self_arg->dwork.Altitude_o5 = 1U;
                ImmedMission_self_arg->dwork.obj.StartFlag = false;
            } else {
                ImmedMission_self_arg->dwork.obj.StartFlag = false;
                ImmedMission_self_arg->dwork.obj.NumWaypoints = 2.0;
                waypoints_size_idx_0 = static_cast<int32_T>(c_size_idx_0 + 1);
                for (b_k = 0; b_k < 3; b_k++) {
                    int32_T waypoints_data_tmp;
                    waypoints_data_tmp = static_cast<int32_T>
                        (static_cast<int32_T>(c_size_idx_0 + 1) * b_k);
                    waypoints_data[waypoints_data_tmp] =
                        ImmedMission_self_arg->dwork.obj.InitialPose[b_k];
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
            if (ImmedMission_self_arg->dwork.obj.WaypointIndex ==
                    ImmedMission_self_arg->dwork.obj.NumWaypoints) {
                p = true;
            }

            if (p) {
                ImmedMission_self_arg->dwork.obj.LastWaypointFlag = true;
                ImmedMission_self_arg->dwork.obj.WaypointIndex--;
            }

            rtu_0_0[0] = rtu_0[0] - waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>
                (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) - 1)];
            rtu_0_0[1] = rtu_0[1] - waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>
                (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) +
                waypoints_size_idx_0) - 1)];
            rtu_0_0[2] = rtu_0[2] - waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>
                (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) +
                static_cast<int32_T>(waypoints_size_idx_0 << 1)) - 1)];
            guard2 = false;
            if (ImmedMission_norm(rtu_0_0) <= 30.0) {
                guard2 = true;
            } else {
                r_idx_0 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>
                     (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) - 1)];
                b_waypointsIn[0] = rtu_0[0] - r_idx_0;
                rtu_0_0[0] = r_idx_0 - waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>
                    (ImmedMission_self_arg->dwork.obj.WaypointIndex) - 1)];
                r_idx_0 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) +
                      waypoints_size_idx_0) - 1)];
                b_waypointsIn[1] = rtu_0[1] - r_idx_0;
                rtu_0_0[1] = r_idx_0 - waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (ImmedMission_self_arg->dwork.obj.WaypointIndex) +
                    waypoints_size_idx_0) - 1)];
                r_idx_2 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) +
                      static_cast<int32_T>(waypoints_size_idx_0 << 1)) - 1)];
                b_waypointsIn[2] = rtu_0[2] - r_idx_2;
                rtu_0_tmp = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (waypoints_size_idx_0 << 1) + static_cast<int32_T>
                      (ImmedMission_self_arg->dwork.obj.WaypointIndex)) - 1)];
                rtu_0_0[2] = r_idx_2 - rtu_0_tmp;
                lambda = ImmedMission_norm(rtu_0_0);
                b_0 = ImmedMission_norm(b_waypointsIn);
                waypoints_tmp = waypoints_data[static_cast<int32_T>(static_cast<
                    int32_T>(ImmedMission_self_arg->dwork.obj.WaypointIndex) - 1)];
                r_idx_0 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>
                     (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) - 1)];
                waypoints_tmp_0 = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (ImmedMission_self_arg->dwork.obj.WaypointIndex) +
                    waypoints_size_idx_0) - 1)];
                r_idx_1 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) +
                      waypoints_size_idx_0) - 1)];
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
                ImmedMission_self_arg->dwork.obj.WaypointIndex++;
                p = false;
                if (ImmedMission_self_arg->dwork.obj.WaypointIndex ==
                        ImmedMission_self_arg->dwork.obj.NumWaypoints) {
                    p = true;
                }

                if (p) {
                    ImmedMission_self_arg->dwork.obj.LastWaypointFlag = true;
                    ImmedMission_self_arg->dwork.obj.WaypointIndex--;
                }

                b_waypointsIn[0] = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>
                    (ImmedMission_self_arg->dwork.obj.WaypointIndex) - 1)];
                r_idx_0 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>
                     (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) - 1)];
                b_waypointsIn[1] = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (ImmedMission_self_arg->dwork.obj.WaypointIndex) +
                    waypoints_size_idx_0) - 1)];
                r_idx_1 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) +
                      waypoints_size_idx_0) - 1)];
                b_waypointsIn[2] = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (waypoints_size_idx_0 << 1) + static_cast<int32_T>
                    (ImmedMission_self_arg->dwork.obj.WaypointIndex)) - 1)];
                r_idx_2 = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                      (ImmedMission_self_arg->dwork.obj.WaypointIndex + 1.0) +
                      static_cast<int32_T>(waypoints_size_idx_0 << 1)) - 1)];
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

            if (ImmedMission_self_arg->dwork.obj.LastWaypointFlag) {
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

            if (ImmedMission_self_arg->dwork.obj.LookaheadDistance <= std::fmax
                    (std::sqrt(b_0), 5.0 * lambda_tmp) + lambda) {
                ImmedMission_self_arg->dwork.obj.LookaheadDistance =
                    ImmedMission_self_arg->dwork.obj.LookaheadFactor * lambda;
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
                                    ImmedMission_self_arg->dwork.obj.LookaheadDistance
                                    * ImmedMission_self_arg->dwork.obj.LookaheadDistance)
                                   * (4.0 * rtu_0_tmp));
            lambda = std::fmax((-b_0 + lambda_tmp) / 2.0 / rtu_0_tmp, (-b_0 -
                                lambda_tmp) / 2.0 / rtu_0_tmp);
            rtu_0_tmp = (1.0 - lambda) * b_waypointsIn[0] + lambda * r_idx_0;

            // MATLABSystem: '<S112>/Altitude'
            ImmedMission_self_arg->dwork.Altitude_o1[0] = rtu_0_tmp;
            r_idx_0 = rtu_0_tmp;
            rtu_0_tmp = (1.0 - lambda) * b_waypointsIn[1] + lambda * r_idx_1;

            // MATLABSystem: '<S112>/Altitude'
            ImmedMission_self_arg->dwork.Altitude_o1[1] = rtu_0_tmp;
            ImmedMission_self_arg->dwork.Altitude_o1[2] = (1.0 - lambda) *
                b_waypointsIn[2] + lambda * r_idx_2;

            // MATLABSystem: '<S112>/Altitude'
            ImmedMission_self_arg->dwork.HeadingAngle = rt_atan2d_snf(rtu_0_tmp
                - rtu_0[1], r_idx_0 - rtu_0[0]);

            // MATLABSystem: '<S112>/Altitude'
            ImmedMission_self_arg->dwork.Altitude_o5 = 0U;
            p = false;
            if (ImmedMission_self_arg->dwork.obj.LastWaypointFlag) {
                p = true;
            }

            if (p) {
                // MATLABSystem: '<S112>/Altitude'
                ImmedMission_self_arg->dwork.Altitude_o5 = 1U;
            }

            ImmedMission_self_arg->dwork.obj.LastWaypointFlag = false;
        }
    }

    // End of MATLABSystem: '<S112>/Altitude'
}

// System initialize for atomic system:
void ImmedMission::ImmedMission_CoordinateTransformationConversion_Init
    (self_CoordinateTransformationConversion_ImmedMission_T
     *ImmedMission_self_arg, const real_T rtu_0[3])
{
    (void) (rtu_0);

    // Start for MATLABSystem: '<S146>/Coordinate Transformation Conversion'
    ImmedMission_self_arg->dwork.objisempty = true;
    ImmedMission_self_arg->dwork.obj.isInitialized = 1;
}

// Output and update for atomic system:
void ImmedMission::ImmedMission_CoordinateTransformationConversion
    (self_CoordinateTransformationConversion_ImmedMission_T
     *ImmedMission_self_arg, const real_T rtu_0[3])
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

    // MATLABSystem: '<S146>/Coordinate Transformation Conversion'
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

    // MATLABSystem: '<S146>/Coordinate Transformation Conversion'
    std::memcpy(&ImmedMission_self_arg->
                dwork.CoordinateTransformationConversion[0], &out[0],
                static_cast<uint32_T>(9U * sizeof(real_T)));
}

//
// Output and update for enable system:
//    '<S139>/DivisionByZeroProtection'
//    '<S15>/DivisionByZeroProtection'
//
void ImmedMission::ImmedMission_DivisionByZeroProtection(real_T rtu_HorizSpd,
    real_T rtu_CentripetalAcc, real_T *rty_OmegaRad)
{
    // Outputs for Enabled SubSystem: '<S139>/DivisionByZeroProtection' incorporates:
    //   EnablePort: '<S141>/Enable'

    if (rtu_HorizSpd > 0.0) {
        // Product: '<S141>/Divide'
        *rty_OmegaRad = 1.0 / rtu_HorizSpd * rtu_CentripetalAcc;
    }

    // End of Outputs for SubSystem: '<S139>/DivisionByZeroProtection'
}

void ImmedMission::ImmedMission_emxInit_real_T(emxArray_real_T_ImmedMission_T
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

void ImmedMission::ImmedMission_emxFree_real_T(emxArray_real_T_ImmedMission_T
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

real_T ImmedMission::ImmedMission_norm_p(const real_T x[2])
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

void ImmedMission::ImmedMission_emxInit_char_T(emxArray_char_T_ImmedMission_T
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
int8_T ImmedMission::ImmedMission_filedata(void) const
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (ImmedMission_DW.eml_openfiles[static_cast<int32_T>
                (static_cast<int32_T>(static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S64>/BaseWayPoint'
int8_T ImmedMission::ImmedMission_cfopen(const char_T *cfilename, const char_T
    *cpermission)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = ImmedMission_filedata();
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            ImmedMission_DW.eml_openfiles[static_cast<int32_T>
                (static_cast<int32_T>(j) - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S64>/BaseWayPoint'
real_T ImmedMission::ImmedMission_fileManager(void)
{
    real_T f;
    int8_T fileid;
    fileid = ImmedMission_cfopen("config.ini", "rb");
    f = static_cast<real_T>(fileid);
    return f;
}

void ImmedMission::ImmedMission_emxEnsureCapacity_char_T
    (emxArray_char_T_ImmedMission_T *emxArray, int32_T oldNumel)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_fread(real_T fileID,
    emxArray_char_T_ImmedMission_T *A)
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
        filestar = ImmedMission_DW.eml_openfiles[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
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

void ImmedMission::ImmedMission_emxFree_char_T(emxArray_char_T_ImmedMission_T
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
boolean_T ImmedMission::ImmedMission_copydigits(emxArray_char_T_ImmedMission_T
    *s1, int32_T *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k,
    int32_T n, boolean_T allowpoint)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_readfloat(emxArray_char_T_ImmedMission_T *s1,
    int32_T *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
creal_T ImmedMission::ImmedMission_str2double(const
    emxArray_char_T_ImmedMission_T *s)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
int32_T ImmedMission::ImmedMission_cfclose(real_T fid)
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
        filestar = ImmedMission_DW.eml_openfiles[static_cast<int32_T>(
            static_cast<int32_T>(b_fileid) - 3)];
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
            ImmedMission_DW.eml_openfiles[static_cast<int32_T>(static_cast<
                int32_T>(fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_strtok(const emxArray_char_T_ImmedMission_T *x,
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_strtok_n(const emxArray_char_T_ImmedMission_T *x,
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_strtrim(const emxArray_char_T_ImmedMission_T *x,
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
boolean_T ImmedMission::ImmedMission_strcmp(const emxArray_char_T_ImmedMission_T
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
boolean_T ImmedMission::ImmedMission_strcmp_h(const
    emxArray_char_T_ImmedMission_T *a)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
boolean_T ImmedMission::ImmedMission_contains(const
    emxArray_char_T_ImmedMission_T *str)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_find_token(const emxArray_char_T_ImmedMission_T *
    x, int32_T *itoken, int32_T *iremain)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_strtok_nx(const emxArray_char_T_ImmedMission_T
    *x, emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_strtok_nx2(const emxArray_char_T_ImmedMission_T *
    x, emxArray_char_T_ImmedMission_T *token)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
boolean_T ImmedMission::ImmedMission_strcmp_ho(const
    emxArray_char_T_ImmedMission_T *a)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_readINI(emxArray_char_T_ImmedMission_T *ret)
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
    fileid = ImmedMission_cfopen("config.ini", "rb");
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        ImmedMission_emxInit_char_T(&data, 2);
        ImmedMission_emxInit_char_T(&j, 1);
        ImmedMission_fread(static_cast<real_T>(fileid), j);
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
        ImmedMission_cfclose(static_cast<real_T>(fileid));
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_readINI_o(emxArray_char_T_ImmedMission_T *ret)
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
    fileid = ImmedMission_cfopen("config.ini", "rb");
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        ImmedMission_emxInit_char_T(&data, 2);
        ImmedMission_emxInit_char_T(&j, 1);
        ImmedMission_fread(static_cast<real_T>(fileid), j);
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
        ImmedMission_cfclose(static_cast<real_T>(fileid));
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
boolean_T ImmedMission::ImmedMission_strcmp_hoc(const
    emxArray_char_T_ImmedMission_T *a)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
uavDubinsConnection_ImmedMission_T *ImmedMission::
    ImmedMission_uavDubinsConnection_uavDubinsConnection
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
boolean_T ImmedMission::ImmedMission_strcmp_hocj(const
    emxArray_char_T_ImmedMission_T *a)
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

// Function for MATLAB Function: '<S64>/BaseWayPoint'
real_T ImmedMission::ImmedMission_DubinsObjSingleton_getMinTurnRadius(void)
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
            (ImmedMission_DW.SingletonInstance_not_empty) ^ 1))) {
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
        ImmedMission_DW.SingletonInstance.AirSpeed = 35.0;
        ImmedMission_DW.SingletonInstance.MaxRollAngle = 0.3490658503988659;
        ImmedMission_DW.SingletonInstance.FlightPathAngleLimit[0] = -0.175;
        ImmedMission_DW.SingletonInstance.FlightPathAngleLimit[1] = 0.175;
        ret->size[0] = 1;
        ret->size[1] = 0;
        fid = ImmedMission_fileManager();
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
            ImmedMission_fread(fid, k);
            c_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, c_0);
            loop_ub = k->size[0];
            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub - 1); c_0++) {
                data->data[c_0] = k->data[c_0];
            }

            ImmedMission_cfclose(fid);
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
        fid = ImmedMission_fileManager();
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(fid, k);
            c_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, c_0);
            loop_ub = k->size[0];
            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub - 1); c_0++) {
                data->data[c_0] = k->data[c_0];
            }

            ImmedMission_cfclose(fid);
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
        fid = ImmedMission_fileManager();
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(fid, k);
            c_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, c_0);
            loop_ub = k->size[0];
            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub - 1); c_0++) {
                data->data[c_0] = k->data[c_0];
            }

            ImmedMission_cfclose(fid);
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
        fid = ImmedMission_fileManager();
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(fid, k);
            c_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, c_0);
            loop_ub = k->size[0];
            for (c_0 = 0; c_0 <= static_cast<int32_T>(loop_ub - 1); c_0++) {
                data->data[c_0] = k->data[c_0];
            }

            ImmedMission_cfclose(fid);
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
        ImmedMission_readINI(ret);
        tmp_0 = ImmedMission_str2double(ret);
        ClimbAngleLimit = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV ClimbAngleLimit:\t%f\n", ClimbAngleLimit);
        fflush(stdout);
        ImmedMission_readINI_o(ret);
        tmp_0 = ImmedMission_str2double(ret);
        DiveAngleLimit = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV DiveAngleLimit:\t\t%f\n", DiveAngleLimit);
        fflush(stdout);
        ImmedMission_emxFree_char_T(&ret);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(tmp.re)) ^ 1))) {
            ImmedMission_DW.SingletonInstance.AirSpeed = tmp.re;
        }

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(fid)) ^ 1))) {
            ImmedMission_DW.SingletonInstance.MaxRollAngle = fid;
        }

        if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (std::isnan(ClimbAngleLimit)) ^ 1))) && (static_cast<boolean_T>(
                static_cast<int32_T>(static_cast<int32_T>(std::isnan
                (DiveAngleLimit)) ^ 1)))) {
            ImmedMission_DW.SingletonInstance.FlightPathAngleLimit[0] =
                DiveAngleLimit;
            ImmedMission_DW.SingletonInstance.FlightPathAngleLimit[1] =
                ClimbAngleLimit;
        }

        ImmedMission_uavDubinsConnection_uavDubinsConnection
            (&ImmedMission_DW.SingletonInstance.Connector,
             ImmedMission_DW.SingletonInstance.AirSpeed,
             ImmedMission_DW.SingletonInstance.MaxRollAngle);
        ImmedMission_DW.SingletonInstance_not_empty = true;
    }

    outputArg = ImmedMission_DW.SingletonInstance.Connector.MinTurningRadius;
    return outputArg;
}

void ImmedMission::ImmedMission_emxEnsureCapacity_real_T
    (emxArray_real_T_ImmedMission_T *emxArray, int32_T oldNumel)
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

void ImmedMission::ImmedMission_binary_expand_op_pu(boolean_T in1_data[],
    int32_T in1_size[2], const emxArray_real_T_ImmedMission_T *in2, int32_T in3,
    int32_T in4)
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

void ImmedMission::ImmedMission_WaypointFollowerBase_getDistinctWpts(const
    emxArray_real_T_ImmedMission_T *waypoints, emxArray_real_T_ImmedMission_T
    *distinctWpts)
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
                    ImmedMission_DW.x_data[static_cast<int32_T>(vstride +
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
            ImmedMission_binary_expand_op_pu(ImmedMission_DW.x_data, x_size,
                waypoints, static_cast<int32_T>(outsize_idx_0 + 1), static_cast<
                int32_T>(vstride + 1));
        }

        outsize_idx_0 = x_size[0];
        for (i1 = 0; i1 <= static_cast<int32_T>(outsize_idx_0 - 1); i1++) {
            ImmedMission_DW.i_data[i1] = false;
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
                if (ImmedMission_DW.x_data[static_cast<int32_T>(ix - 1)]) {
                    ImmedMission_DW.i_data[outsize_idx_0] = true;
                    exitg1 = true;
                } else {
                    ix = static_cast<int32_T>(ix + vstride);
                }
            }
        }

        outsize_idx_0 = static_cast<int32_T>(x_size[0] - 1);
        i1 = 0;
        for (vstride = 0; vstride <= outsize_idx_0; vstride++) {
            if (ImmedMission_DW.i_data[vstride]) {
                i1 = static_cast<int32_T>(i1 + 1);
            }
        }

        ix = i1;
        i1 = 0;
        for (vstride = 0; vstride <= outsize_idx_0; vstride++) {
            if (ImmedMission_DW.i_data[vstride]) {
                ImmedMission_DW.j_data[i1] = static_cast<int16_T>
                    (static_cast<int32_T>(vstride + 1));
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
                    int32_T>(ImmedMission_DW.j_data[vstride])) - 1)];
            }
        }
    }
}

// Function for MATLAB Function: '<S64>/BaseWayPoint'
void ImmedMission::ImmedMission_circshift(emxArray_real_T_ImmedMission_T *a)
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

real_T ImmedMission::ImmedMission_norm_pv(const real_T x[3])
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

real_T ImmedMission::ImmedMission_angdiff(real_T x, real_T y)
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

void ImmedMission::ImmedMission_binary_expand_op_p
    (emxArray_real_T_ImmedMission_T *in1, const emxArray_real_T_ImmedMission_T
     *in2, int32_T in3, int32_T in4)
{
    emxArray_real_T_ImmedMission_T *in1_0;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    ImmedMission_emxInit_real_T(&in1_0, 1);

    // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
    //   ActionPort: '<S8>/Action Port'

    // Outputs for Triggered SubSystem: '<S58>/WayPointGen' incorporates:
    //   TriggerPort: '<S64>/Trigger'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   MATLAB Function: '<S64>/BaseWayPoint'

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
    // End of Outputs for SubSystem: '<S58>/WayPointGen'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
    ImmedMission_emxFree_real_T(&in1_0);
}

void ImmedMission::ImmedMission_binary_expand_op(emxArray_real_T_ImmedMission_T *
    in1, const emxArray_real_T_ImmedMission_T *in2, const
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
    //   ActionPort: '<S8>/Action Port'

    // Outputs for Triggered SubSystem: '<S58>/WayPointGen' incorporates:
    //   TriggerPort: '<S64>/Trigger'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   MATLAB Function: '<S64>/BaseWayPoint'

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
    // End of Outputs for SubSystem: '<S58>/WayPointGen'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
    ImmedMission_emxFree_real_T(&in2_0);
}

// System initialize for referenced model: 'ImmedMission'
void ImmedMission::init(boolean_T rty_ControlSwitch[2], FixedWingGuidanceBus
                        *rty_GuidanceCMD)
{
    // local block i/o variables
    real_T rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[3];
    real_T rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e
        [3];
    real_T rtb_TmpSignalConversionAtAltitudeInport1[4];
    real_T rtb_sqrt;
    FILE* a;

    // Start for SwitchCase: '<S1>/Switch Case'
    ImmedMission_DW.SwitchCase_ActiveSubsystem = -1;

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode128_DetailedInsp'
    // Start for MATLABSystem: '<S24>/Orbit Follower'
    ImmedMission_DW.objisempty_e = true;
    ImmedMission_DW.obj_c.isInitialized = 1;
    ImmedMission_DW.obj_c.PrevResetSignal = 0.0;
    ImmedMission_DW.obj_c.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S24>/Orbit Follower'
    ImmedMission_DW.obj_c.OrbitRadiusInternal = (rtNaN);
    ImmedMission_DW.obj_c.PrevResetSignal *= 0.0;
    ImmedMission_DW.obj_c.NumCircles *= 0.0;

    // Start for MATLABSystem: '<S24>/Orbit Follower'
    ImmedMission_DW.obj_c.PrevPosition[0] = 0.0;

    // InitializeConditions for MATLABSystem: '<S24>/Orbit Follower'
    ImmedMission_DW.obj_c.OrbitCenterInternal[0] = (rtNaN);
    ImmedMission_DW.obj_c.PrevPosition[0] *= 0.0;

    // Start for MATLABSystem: '<S24>/Orbit Follower'
    ImmedMission_DW.obj_c.PrevPosition[1] = 0.0;

    // InitializeConditions for MATLABSystem: '<S24>/Orbit Follower'
    ImmedMission_DW.obj_c.OrbitCenterInternal[1] = (rtNaN);
    ImmedMission_DW.obj_c.PrevPosition[1] *= 0.0;

    // Start for MATLABSystem: '<S24>/Orbit Follower'
    ImmedMission_DW.obj_c.PrevPosition[2] = 0.0;

    // InitializeConditions for MATLABSystem: '<S24>/Orbit Follower'
    ImmedMission_DW.obj_c.OrbitCenterInternal[2] = (rtNaN);
    ImmedMission_DW.obj_c.PrevPosition[2] *= 0.0;
    ImmedMission_DW.obj_c.StartFlag = true;
    ImmedMission_DW.obj_c.SelectTurnDirectionFlag = true;
    ImmedMission_DW.obj_c.TurnDirectionInternal = 1.0;
    ImmedMission_DW.obj_c.OrbitRadiusFlag = 0U;
    ImmedMission_DW.obj_c.LookaheadDistFlag = 0U;

    // End of SystemInitialize for SubSystem: '<S1>/Mode128_DetailedInsp'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode131_SqCalibr'
    // SystemInitialize for Triggered SubSystem: '<S58>/WayPointGen'
    // SystemInitialize for MATLAB Function: '<S64>/BaseWayPoint'
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        ImmedMission_DW.eml_openfiles[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S64>/BaseWayPoint'

    // Start for MATLABSystem: '<S64>/RotateATMissionHdg'
    ImmedMission_DW.objisempty_o = true;
    ImmedMission_DW.obj_n.isInitialized = 1;
    ImmedMission_PrevZCX.WayPointGen_Trig_ZCE_d = NEG_ZCSIG;

    // End of SystemInitialize for SubSystem: '<S58>/WayPointGen'

    // Start for MATLABSystem: '<S58>/Waypoint Follower'
    ImmedMission_DW.obj.LastWaypointFlag = false;
    ImmedMission_DW.obj.StartFlag = true;
    ImmedMission_DW.obj.LookaheadFactor = 1.01;
    ImmedMission_DW.obj.CacheInputSizes = false;
    ImmedMission_DW.objisempty = true;
    ImmedMission_DW.obj.isInitialized = 1;
    for (int32_T i{0}; i < 8; i++) {
        ImmedMission_DW.obj.inputVarSize[0].f1[i] = 1U;
    }

    ImmedMission_DW.obj.inputVarSize[1].f1[0] = 0U;
    ImmedMission_DW.obj.inputVarSize[1].f1[1] = 0U;
    for (int32_T i{0}; i < 6; i++) {
        ImmedMission_DW.obj.inputVarSize[1].f1[static_cast<int32_T>(i + 2)] = 1U;
    }

    for (int32_T i{0}; i < 8; i++) {
        ImmedMission_DW.obj.inputVarSize[2].f1[i] = 1U;
    }

    // InitializeConditions for MATLABSystem: '<S58>/Waypoint Follower'
    ImmedMission_DW.obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 30723; i++) {
        // InitializeConditions for MATLABSystem: '<S58>/Waypoint Follower'
        ImmedMission_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S1>/Mode131_SqCalibr'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode132_pAttack'
    // SystemInitialize for Triggered SubSystem: '<S112>/WayPointGen'
    ImmedMission_PrevZCX.WayPointGen_Trig_ZCE = NEG_ZCSIG;

    // End of SystemInitialize for SubSystem: '<S112>/WayPointGen'

    // Constant: '<S112>/Constant'
    ImmedMission_Altitude_Init(&self_Altitude,
        rtb_TmpSignalConversionAtAltitudeInport1,
        ImmedMission_DW.MatrixConcatenate, 50.0);
    ImmedMission_Altitude_Init(&self_Heading,
        rtb_TmpSignalConversionAtAltitudeInport1,
        ImmedMission_DW.MatrixConcatenate, rtb_sqrt);

    // End of SystemInitialize for SubSystem: '<S1>/Mode132_pAttack'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU'
    ImmedMission_CoordinateTransformationConversion_Init
        (&self_CoordinateTransformationConversion,
         rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e);

    // End of SystemInitialize for SubSystem: '<S1>/Mode254_ShiftEarthENU'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode253_ShiftBodyXYZ'
    ImmedMission_CoordinateTransformationConversion_Init
        (&self_CoordinateTransformationConversion_j,
         rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1);

    // End of SystemInitialize for SubSystem: '<S1>/Mode253_ShiftBodyXYZ'

    // SystemInitialize for Merge: '<S1>/MergeCollAvoidSimUAV'
    std::memset(&ImmedMission_DW.MergeCollAvoidSimUAV, 0, sizeof
                (FixedWingGuidanceStateBus));

    // SystemInitialize for Merge: '<S1>/MergeControlSwitch'
    rty_ControlSwitch[0] = false;
    rty_ControlSwitch[1] = false;
    std::memset(rty_GuidanceCMD, 0, sizeof(FixedWingGuidanceBus));
}

// Disable for referenced model: 'ImmedMission'
void ImmedMission::disable(void)
{
    // Disable for Atomic SubSystem: '<S146>/SailDistance'
    // Disable for Enabled SubSystem: '<S148>/SailShift'
    // Disable for SwitchCase: '<S1>/Switch Case'
    ImmedMission_DW.SailShift_MODE = static_cast<boolean_T>(static_cast<int32_T>
        ((static_cast<int32_T>(ImmedMission_DW.SwitchCase_ActiveSubsystem) != 4)
         & static_cast<int32_T>(ImmedMission_DW.SailShift_MODE)));

    // End of Disable for SubSystem: '<S148>/SailShift'
    // End of Disable for SubSystem: '<S146>/SailDistance'
    ImmedMission_DW.SwitchCase_ActiveSubsystem = -1;
}

// Output and update for referenced model: 'ImmedMission'
void ImmedMission::step(const FixedWingGuidanceStateBus *rtu_SimUAVstate, const
                        missionCmd *rtu_MissionInput, const boolean_T
                        *rtu_NewImmed, const RealUAVStateBus *rtu_RealUAVState,
                        const int32_T *rtu_FlightMission_SequenceID, const
                        MissionModes *rtu_FlightMission_MissionMode, const
                        real_T *rtu_FlightMission_MissionLocation_Lat, const
                        real_T *rtu_FlightMission_MissionLocation_Lon, const
                        real_T *rtu_FlightMission_MissionLocation_Alt, const
                        real_T *rtu_FlightMission_MissionLocation_degHDG, const
                        real32_T *rtu_FlightMission_params_Param3, const int32_T
                        *rtu_FlightMission_numUAV, const int32_T
                        *rtu_FlightMission_FormationPos, const real_T
                        rtu_OtherUAVstate[4096], const uint8_T
                        *rtu_RealUAVEngaged, const MissionModes *rtu_FlightMode,
                        real_T *rty_TaskStatus, FixedWingGuidanceStateBus
                        *rty_FinalSimUAVState, boolean_T rty_ControlSwitch[2],
                        FixedWingGuidanceBus *rty_GuidanceCMD)
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
    emxArray_real_T_ImmedMission_T *step_0;
    emxArray_real_T_ImmedMission_T *tmp;
    emxArray_real_T_ImmedMission_T *tmp_0;
    emxArray_real_T_ImmedMission_T *waypointsIn;
    emxArray_real_T_ImmedMission_T *y_0;
    real_T WPQ1_tmp[91];
    real_T out[9];
    real_T rtb_Sum_o[3];
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport2[3];
    real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1[3];
    real_T turnVector[3];
    real_T distToCenter_tmp[2];
    real_T rtb_TmpSignalConversionAtOrbitF[2];
    real_T distToCenter_tmp_tmp;
    real_T rtb_Abs1;
    real_T rtb_Down;
    real_T rtb_LatitudeGCS;
    real_T rtb_Sum1_idx_0;
    real_T rtb_Sum1_idx_1;
    real_T rtb_Sum_dq;
    real_T rtb_Switch_m2;
    real_T rtb_Up;
    real_T xyCenter_idx_1;
    int32_T MatrixConcatenate_DIMS1[2];
    int32_T boffset;
    int32_T colIdx;
    int32_T i1;
    int32_T i2;
    int32_T iy;
    int32_T nm1d2;
    int32_T rtb_BiasNumUAV;
    int32_T rtb_BiasOldIdx;
    uint32_T inSize[8];
    int16_T c_data[1024];
    int8_T waypointsIn_0[2];
    int8_T rtAction;
    int8_T rtPrevAction;
    boolean_T x[4096];
    boolean_T y[1024];
    boolean_T exitg1;
    boolean_T rtb_Compare_lh;
    ImmedMission_emxInit_real_T(&e, 2);

    // Chart: '<S1>/PreemptableMissionModeSelector' incorporates:
    //   Memory: '<S1>/Memory'

    // Gateway: ImmedMissionGuidance/PreemptableMissionModeSelector
    ImmedMission_DW.FlightMode_prev = ImmedMission_DW.FlightMode_start;
    ImmedMission_DW.FlightMode_start = *rtu_FlightMode;

    // During: ImmedMissionGuidance/PreemptableMissionModeSelector
    if (static_cast<uint32_T>(ImmedMission_DW.is_active_c25_ImmedMission) == 0U)
    {
        ImmedMission_DW.FlightMode_prev = *rtu_FlightMode;

        // Entry: ImmedMissionGuidance/PreemptableMissionModeSelector
        ImmedMission_DW.is_active_c25_ImmedMission = 1U;

        // Entry Internal: ImmedMissionGuidance/PreemptableMissionModeSelector
        // Transition: '<S12>:152'
        ImmedMission_DW.is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
        ImmedMission_DW.ImmedMission_a = MissionModes::WaitToStart;

        // Entry 'WaitToStart': '<S12>:151'
    } else if (ImmedMission_DW.is_c25_ImmedMission ==
               ImmedMission_IN_ImmedMission) {
        // During 'ImmedMission': '<S12>:154'
        if (*rtu_NewImmed) {
            // Transition: '<S12>:155'
            // Exit Internal 'ImmedMission': '<S12>:154'
            // Exit Internal 'Formation': '<S12>:246'
            ImmedMission_DW.is_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
            ImmedMission_DW.is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
            ImmedMission_DW.ImmedMission_a = MissionModes::WaitToStart;

            // Entry 'WaitToStart': '<S12>:151'
        } else {
            switch (ImmedMission_DW.is_ImmedMission) {
              case ImmedMission_IN_DetailedInsp:
                // During 'DetailedInsp': '<S12>:166'
                break;

              case ImmedMission_IN_FlightMissionRH:
                // During 'FlightMissionRH': '<S12>:167'
                break;

              case ImmedMission_IN_Formation:
                // During 'Formation': '<S12>:246'
                if (ImmedMission_DW.FlightMode_prev !=
                        ImmedMission_DW.FlightMode_start) {
                    // Transition: '<S12>:247'
                    // Exit Internal 'Formation': '<S12>:246'
                    ImmedMission_DW.is_ImmedMission =
                        ImmedMission_IN_NO_ACTIVE_CHILD;
                    ImmedMission_DW.is_c25_ImmedMission =
                        ImmedMission_IN_WaitToStart;
                    ImmedMission_DW.ImmedMission_a = MissionModes::WaitToStart;

                    // Entry 'WaitToStart': '<S12>:151'
                }
                break;

              case ImmedMission_IN_SqCalibr:
                // During 'SqCalibr': '<S12>:170'
                if (static_cast<int32_T>(ImmedMission_DW.Memory_PreviousInput)
                        != 0) {
                    // Transition: '<S12>:177'
                    ImmedMission_DW.is_ImmedMission =
                        ImmedMission_IN_NO_ACTIVE_CHILD;
                    ImmedMission_DW.is_c25_ImmedMission =
                        ImmedMission_IN_WaitToStart;
                    ImmedMission_DW.ImmedMission_a = MissionModes::WaitToStart;

                    // Entry 'WaitToStart': '<S12>:151'
                }
                break;

              default:
                // During 'pAttack': '<S12>:204'
                break;
            }
        }
    } else {
        // During 'WaitToStart': '<S12>:151'
        // Transition: '<S12>:153'
        switch (rtu_MissionInput->MissionMode) {
          case MissionModes::DetailedInsp:
            // Transition: '<S12>:187'
            // Transition: '<S12>:124'
            ImmedMission_DW.is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            ImmedMission_DW.is_ImmedMission = ImmedMission_IN_DetailedInsp;
            ImmedMission_DW.ImmedMission_a = MissionModes::DetailedInsp;
            break;

          case MissionModes::FlightMissionRH:
            // Transition: '<S12>:130'
            // Transition: '<S12>:189'
            // Transition: '<S12>:182'
            ImmedMission_DW.is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            ImmedMission_DW.is_ImmedMission = ImmedMission_IN_FlightMissionRH;
            ImmedMission_DW.ImmedMission_a = MissionModes::FlightMissionRH;
            break;

          case MissionModes::SqCalibr:
            // Transition: '<S12>:185'
            // Transition: '<S12>:193'
            // Transition: '<S12>:174'
            ImmedMission_DW.is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            ImmedMission_DW.is_ImmedMission = ImmedMission_IN_SqCalibr;
            ImmedMission_DW.ImmedMission_a = MissionModes::SqCalibr;
            break;

          case MissionModes::pAttack:
            // Transition: '<S12>:200'
            // Transition: '<S12>:202'
            // Transition: '<S12>:217'
            ImmedMission_DW.is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            ImmedMission_DW.is_ImmedMission = ImmedMission_IN_pAttack;
            ImmedMission_DW.ImmedMission_a = MissionModes::pAttack;
            break;

          default:
            if (rtu_MissionInput->SequenceID == *rtu_FlightMission_SequenceID) {
                // Transition: '<S12>:243'
                switch (rtu_MissionInput->MissionMode) {
                  case MissionModes::ShiftEarthENU:
                    // Transition: '<S12>:231'
                    // Transition: '<S12>:233'
                    ImmedMission_DW.is_c25_ImmedMission =
                        ImmedMission_IN_ImmedMission;
                    ImmedMission_DW.is_ImmedMission = ImmedMission_IN_Formation;
                    ImmedMission_DW.ImmedMission_a = MissionModes::ShiftEarthENU;
                    break;

                  case MissionModes::ShiftBodyXYZ:
                    // Transition: '<S12>:228'
                    // Transition: '<S12>:232'
                    // Transition: '<S12>:235'
                    ImmedMission_DW.is_c25_ImmedMission =
                        ImmedMission_IN_ImmedMission;
                    ImmedMission_DW.is_ImmedMission = ImmedMission_IN_Formation;
                    ImmedMission_DW.ImmedMission_a = MissionModes::ShiftBodyXYZ;
                    break;
                }
            }
            break;
        }
    }

    // End of Chart: '<S1>/PreemptableMissionModeSelector'

    // DataStoreRead: '<S2>/LatitudeGCS'
    rtw_pthread_mutex_lock(LatitudeGCS_m0);
    rtb_LatitudeGCS = LatitudeGCS;
    rtw_pthread_mutex_unlock(LatitudeGCS_m0);

    // DataStoreRead: '<S2>/LongitudeGCS'
    rtw_pthread_mutex_lock(LongitudeGCS_m0);
    rtb_Abs1 = LongitudeGCS;
    rtw_pthread_mutex_unlock(LongitudeGCS_m0);

    // Sum: '<S155>/Sum1' incorporates:
    //   Sum: '<S157>/Sum'

    rtb_Sum1_idx_0 = rtu_RealUAVState->Latitude_deg - rtb_LatitudeGCS;
    rtb_Sum1_idx_1 = rtu_RealUAVState->Longitude_deg - rtb_Abs1;

    // Switch: '<S163>/Switch' incorporates:
    //   Abs: '<S163>/Abs'
    //   Bias: '<S163>/Bias'
    //   Bias: '<S163>/Bias1'
    //   Constant: '<S163>/Constant2'
    //   Constant: '<S164>/Constant'
    //   Math: '<S163>/Math Function1'
    //   RelationalOperator: '<S164>/Compare'

    if (std::abs(rtb_Sum1_idx_0) > 180.0) {
        rtb_Switch_m2 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
    } else {
        rtb_Switch_m2 = rtb_Sum1_idx_0;
    }

    // End of Switch: '<S163>/Switch'

    // Abs: '<S160>/Abs1'
    rtb_Abs1 = std::abs(rtb_Switch_m2);

    // Switch: '<S160>/Switch' incorporates:
    //   Bias: '<S160>/Bias'
    //   Bias: '<S160>/Bias1'
    //   Constant: '<S156>/Constant'
    //   Constant: '<S156>/Constant1'
    //   Constant: '<S162>/Constant'
    //   Gain: '<S160>/Gain'
    //   Product: '<S160>/Divide1'
    //   RelationalOperator: '<S162>/Compare'
    //   Switch: '<S156>/Switch1'

    if (rtb_Abs1 > 90.0) {
        // Signum: '<S160>/Sign1'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(rtb_Switch_m2)) ^ 1))) {
            if (rtb_Switch_m2 < 0.0) {
                rtb_Switch_m2 = -1.0;
            } else {
                rtb_Switch_m2 = static_cast<real_T>(rtb_Switch_m2 > 0.0);
            }
        }

        // End of Signum: '<S160>/Sign1'
        rtb_Switch_m2 *= -(rtb_Abs1 + -90.0) + 90.0;
        iy = 180;
    } else {
        iy = 0;
    }

    // End of Switch: '<S160>/Switch'

    // Sum: '<S156>/Sum'
    rtb_Sum_dq = static_cast<real_T>(iy) + rtb_Sum1_idx_1;

    // Switch: '<S161>/Switch' incorporates:
    //   Abs: '<S161>/Abs'
    //   Bias: '<S161>/Bias'
    //   Bias: '<S161>/Bias1'
    //   Constant: '<S161>/Constant2'
    //   Constant: '<S165>/Constant'
    //   Math: '<S161>/Math Function1'
    //   RelationalOperator: '<S165>/Compare'

    if (std::abs(rtb_Sum_dq) > 180.0) {
        rtb_Sum_dq = rt_modd_snf(rtb_Sum_dq + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S161>/Switch'

    // UnitConversion: '<S159>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Switch_m2;
    rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_dq;

    // UnitConversion: '<S174>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_LatitudeGCS *= 0.017453292519943295;

    // Trigonometry: '<S175>/Trigonometric Function1'
    rtb_Sum_dq = std::sin(rtb_LatitudeGCS);

    // Sum: '<S175>/Sum1' incorporates:
    //   Constant: '<S175>/Constant'
    //   Product: '<S175>/Product1'

    rtb_Sum_dq = 1.0 - 0.0066943799901413295 * rtb_Sum_dq * rtb_Sum_dq;

    // Product: '<S173>/Product1' incorporates:
    //   Constant: '<S173>/Constant1'
    //   Sqrt: '<S173>/sqrt'

    rtb_Switch_m2 = 6.378137E+6 / std::sqrt(rtb_Sum_dq);

    // Product: '<S158>/dNorth' incorporates:
    //   Constant: '<S173>/Constant2'
    //   Product: '<S173>/Product3'
    //   Trigonometry: '<S173>/Trigonometric Function1'

    rtb_Sum_dq = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_m2 *
        0.99330562000985867 / rtb_Sum_dq);

    // Product: '<S158>/dEast' incorporates:
    //   Constant: '<S173>/Constant3'
    //   Product: '<S173>/Product4'
    //   Trigonometry: '<S173>/Trigonometric Function'
    //   Trigonometry: '<S173>/Trigonometric Function2'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Switch_m2 = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_m2 * std::cos
        (rtb_LatitudeGCS)) * rtb_Sum1_idx_1;

    // Sum: '<S158>/Sum2' incorporates:
    //   Product: '<S158>/x*cos'
    //   Product: '<S158>/y*sin'

    rtb_LatitudeGCS = rtb_Switch_m2 * 0.0 + rtb_Sum_dq;

    // Sum: '<S158>/Sum3' incorporates:
    //   Product: '<S158>/x*sin'
    //   Product: '<S158>/y*cos'

    rtb_Abs1 = rtb_Switch_m2 - rtb_Sum_dq * 0.0;

    // DataStoreRead: '<S2>/AltitudeGCS'
    rtw_pthread_mutex_lock(AltitudeGCS_m0);
    rtb_Sum_dq = AltitudeGCS;
    rtw_pthread_mutex_unlock(AltitudeGCS_m0);

    // Gain: '<S2>/Down2Up' incorporates:
    //   Gain: '<S2>/inverse'
    //   Sum: '<S155>/Sum'

    rtb_Up = rtu_RealUAVState->Height_meter + -rtb_Sum_dq;

    // Gain: '<S152>/Gain1'
    rtb_Sum_dq = 0.017453292519943295 * rtu_RealUAVState->HeadingAngle_deg;

    // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
    // Gain: '<S3>/Gain2' incorporates:
    //   BusCreator: '<S2>/FixedWingGuidanceStateBus'

    rtb_Down = -rtb_Up;

    // End of Outputs for SubSystem: '<Root>/RealState2Pose'

    // MATLAB Function: '<Root>/RemoveNaN'
    // MATLAB Function 'RemoveNaN': '<S4>:1'
    // '<S4>:1:3'
    for (iy = 0; iy < 4096; iy++) {
        x[iy] = std::isnan(rtu_OtherUAVstate[iy]);
    }

    i1 = 0;
    i2 = 3072;
    iy = 0;
    for (nm1d2 = 0; nm1d2 < 1024; nm1d2++) {
        y[nm1d2] = false;
        i1 = static_cast<int32_T>(i1 + 1);
        i2 = static_cast<int32_T>(i2 + 1);
        boffset = i1;
        exitg1 = false;
        while ((!exitg1) && (boffset <= i2)) {
            if (x[static_cast<int32_T>(boffset - 1)]) {
                y[nm1d2] = true;
                exitg1 = true;
            } else {
                boffset = static_cast<int32_T>(boffset + 1024);
            }
        }

        rtb_Compare_lh = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(y[nm1d2]) ^ 1));
        if (rtb_Compare_lh) {
            iy = static_cast<int32_T>(iy + 1);
        }

        y[nm1d2] = rtb_Compare_lh;
    }

    i2 = iy;
    iy = 0;
    for (nm1d2 = 0; nm1d2 < 1024; nm1d2++) {
        if (y[nm1d2]) {
            c_data[iy] = static_cast<int16_T>(static_cast<int32_T>(nm1d2 + 1));
            iy = static_cast<int32_T>(iy + 1);
        }
    }

    // '<S4>:1:3'
    for (iy = 0; iy < 4; iy++) {
        for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(i2 - 1); nm1d2++) {
            ImmedMission_DW.Out_data[static_cast<int32_T>(nm1d2 +
                static_cast<int32_T>(i2 * iy))] = rtu_OtherUAVstate[static_cast<
                int32_T>(static_cast<int32_T>(static_cast<int32_T>(iy << 10) +
                          static_cast<int32_T>(c_data[nm1d2])) - 1)];
        }
    }

    // '<S4>:1:4'
    for (iy = 0; iy <= static_cast<int32_T>(i2 - 1); iy++) {
        y[iy] = (ImmedMission_DW.Out_data[iy] != static_cast<real_T>
                 (rtu_RealUAVState->UAV_ID));
    }

    iy = 0;
    for (i1 = 0; i1 <= static_cast<int32_T>(i2 - 1); i1 = static_cast<int32_T>
            (i1 + 1)) {
        if (y[i1]) {
            iy = static_cast<int32_T>(iy + 1);
        }
    }

    // '<S4>:1:4'
    ImmedMission_DW.SFunction_DIMS2[0] = iy;
    ImmedMission_DW.SFunction_DIMS2[1] = 3;

    // End of MATLAB Function: '<Root>/RemoveNaN'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
    //   Concatenate: '<S64>/Matrix Concatenate'
    //   Constant: '<S112>/Constant'
    //   Constant: '<S112>/ControlHdg'
    //   Constant: '<S112>/ControlSpd'
    //   Constant: '<S112>/InitTrigger'
    //   Constant: '<S112>/ShiftSimUAV'
    //   Constant: '<S139>/Constant'
    //   Constant: '<S139>/ControlHdg'
    //   Constant: '<S139>/ControlSpd'
    //   Constant: '<S146>/Constant'
    //   Constant: '<S146>/ControlHdg'
    //   Constant: '<S146>/ControlSpd'
    //   Constant: '<S24>/ControlHdg'
    //   Constant: '<S24>/ControlSpd'
    //   Constant: '<S24>/ShiftSimUAV'
    //   Constant: '<S54>/ControlHdg'
    //   Constant: '<S54>/ControlSpd'
    //   Constant: '<S58>/InitTrigger'
    //   Constant: '<S58>/ShiftSimUAV'
    //   Constant: '<S5>/ShiftSimUAV'
    //   Gain: '<S139>/Gravity'
    //   Gain: '<S153>/Gain1'
    //   Gain: '<S154>/Gain1'
    //   Gain: '<S15>/Gravity'
    //   MATLAB Function: '<S64>/BaseWayPoint'
    //   MATLABSystem: '<S58>/Waypoint Follower'
    //   Product: '<S139>/HorizSpd'
    //   Product: '<S15>/HorizSpd'
    //   Trigonometry: '<S139>/Cos'
    //   Trigonometry: '<S139>/Tan'
    //   Trigonometry: '<S15>/Cos'
    //   Trigonometry: '<S15>/Tan'

    rtPrevAction = ImmedMission_DW.SwitchCase_ActiveSubsystem;
    switch (ImmedMission_DW.ImmedMission_a) {
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

    ImmedMission_DW.SwitchCase_ActiveSubsystem = rtAction;
    if (static_cast<int32_T>(rtPrevAction) != static_cast<int32_T>(rtAction)) {
        // Disable for Atomic SubSystem: '<S146>/SailDistance'
        // Disable for Enabled SubSystem: '<S148>/SailShift'
        ImmedMission_DW.SailShift_MODE = static_cast<boolean_T>
            (static_cast<int32_T>((static_cast<int32_T>(rtPrevAction) != 4) &
              static_cast<int32_T>(ImmedMission_DW.SailShift_MODE)));

        // End of Disable for SubSystem: '<S148>/SailShift'
        // End of Disable for SubSystem: '<S146>/SailDistance'
    }

    switch (rtAction) {
      case 0:
        {
            real_T rtb_Gain1_g;
            real_T rtb_Sum_n;
            real_T rtb_Switch_j;
            real_T rtb_Switch_k;
            real_T rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // SystemReset for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
                //   ActionPort: '<S6>/Action Port'

                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S24>/HdgHoldLogic'
                //   MATLABSystem: '<S24>/Orbit Follower'

                ImmedMission_DW.temporalCounter_i1_p = 0U;
                ImmedMission_DW.is_active_c1_ImmedMission = 0U;
                ImmedMission_DW.is_c1_ImmedMission =
                    ImmedMission_IN_NO_ACTIVE_CHILD;
                ImmedMission_DW.obj_c.OrbitRadiusInternal = (rtNaN);
                ImmedMission_DW.obj_c.PrevResetSignal *= 0.0;
                ImmedMission_DW.obj_c.NumCircles *= 0.0;
                ImmedMission_DW.obj_c.OrbitCenterInternal[0] = (rtNaN);
                ImmedMission_DW.obj_c.PrevPosition[0] *= 0.0;
                ImmedMission_DW.obj_c.OrbitCenterInternal[1] = (rtNaN);
                ImmedMission_DW.obj_c.PrevPosition[1] *= 0.0;
                ImmedMission_DW.obj_c.OrbitCenterInternal[2] = (rtNaN);
                ImmedMission_DW.obj_c.PrevPosition[2] *= 0.0;
                ImmedMission_DW.obj_c.StartFlag = true;
                ImmedMission_DW.obj_c.SelectTurnDirectionFlag = true;
                ImmedMission_DW.obj_c.TurnDirectionInternal = 1.0;
                ImmedMission_DW.obj_c.OrbitRadiusFlag = 0U;
                ImmedMission_DW.obj_c.LookaheadDistFlag = 0U;

                // End of SystemReset for SubSystem: '<S1>/Mode128_DetailedInsp' 
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
            //   ActionPort: '<S6>/Action Port'

            // DataStoreRead: '<S24>/AltitudeGCS'
            rtw_pthread_mutex_lock(AltitudeGCS_m0);
            rtb_Switch_m2 = AltitudeGCS;
            rtw_pthread_mutex_unlock(AltitudeGCS_m0);

            // DataStoreRead: '<S24>/LatitudeGCS'
            rtw_pthread_mutex_lock(LatitudeGCS_m0);
            rtb_Up = LatitudeGCS;
            rtw_pthread_mutex_unlock(LatitudeGCS_m0);

            // DataStoreRead: '<S24>/LongitudeGCS'
            rtw_pthread_mutex_lock(LongitudeGCS_m0);
            rtb_Gain1_g = LongitudeGCS;
            rtw_pthread_mutex_unlock(LongitudeGCS_m0);

            // Sum: '<S29>/Sum1' incorporates:
            //   Sum: '<S32>/Sum'

            rtb_Sum1_idx_0 = rtu_MissionInput->MissionLocation.Lat - rtb_Up;
            rtb_Sum1_idx_1 = rtu_MissionInput->MissionLocation.Lon - rtb_Gain1_g;

            // Switch: '<S38>/Switch' incorporates:
            //   Abs: '<S38>/Abs'
            //   Bias: '<S38>/Bias'
            //   Bias: '<S38>/Bias1'
            //   Constant: '<S38>/Constant2'
            //   Constant: '<S39>/Constant'
            //   Math: '<S38>/Math Function1'
            //   RelationalOperator: '<S39>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                rtb_Switch_k = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) +
                    -180.0;
            } else {
                rtb_Switch_k = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S38>/Switch'

            // Abs: '<S35>/Abs1'
            rtb_Gain1_g = std::abs(rtb_Switch_k);

            // Switch: '<S35>/Switch' incorporates:
            //   Bias: '<S35>/Bias'
            //   Bias: '<S35>/Bias1'
            //   Constant: '<S31>/Constant'
            //   Constant: '<S31>/Constant1'
            //   Constant: '<S37>/Constant'
            //   Gain: '<S35>/Gain'
            //   Product: '<S35>/Divide1'
            //   RelationalOperator: '<S37>/Compare'
            //   Switch: '<S31>/Switch1'

            if (rtb_Gain1_g > 90.0) {
                // Signum: '<S35>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Switch_k)) ^ 1))) {
                    if (rtb_Switch_k < 0.0) {
                        rtb_Switch_k = -1.0;
                    } else {
                        rtb_Switch_k = static_cast<real_T>(rtb_Switch_k > 0.0);
                    }
                }

                // End of Signum: '<S35>/Sign1'
                rtb_Switch_k *= -(rtb_Gain1_g + -90.0) + 90.0;
                iy = 180;
            } else {
                iy = 0;
            }

            // End of Switch: '<S35>/Switch'

            // Sum: '<S31>/Sum'
            rtb_Sum_n = static_cast<real_T>(iy) + rtb_Sum1_idx_1;

            // Switch: '<S36>/Switch' incorporates:
            //   Abs: '<S36>/Abs'
            //   Bias: '<S36>/Bias'
            //   Bias: '<S36>/Bias1'
            //   Constant: '<S36>/Constant2'
            //   Constant: '<S40>/Constant'
            //   Math: '<S36>/Math Function1'
            //   RelationalOperator: '<S40>/Compare'

            if (std::abs(rtb_Sum_n) > 180.0) {
                rtb_Sum_n = rt_modd_snf(rtb_Sum_n + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S36>/Switch'

            // UnitConversion: '<S34>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Switch_k;
            rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_n;

            // UnitConversion: '<S49>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Up *= 0.017453292519943295;

            // Trigonometry: '<S50>/Trigonometric Function1'
            rtb_Sum_n = std::sin(rtb_Up);

            // Sum: '<S50>/Sum1' incorporates:
            //   Constant: '<S50>/Constant'
            //   Product: '<S50>/Product1'

            rtb_Sum_n = 1.0 - 0.0066943799901413295 * rtb_Sum_n * rtb_Sum_n;

            // Product: '<S48>/Product1' incorporates:
            //   Constant: '<S48>/Constant1'
            //   Sqrt: '<S48>/sqrt'

            rtb_Switch_k = 6.378137E+6 / std::sqrt(rtb_Sum_n);

            // Product: '<S33>/dNorth' incorporates:
            //   Constant: '<S48>/Constant2'
            //   Product: '<S48>/Product3'
            //   Trigonometry: '<S48>/Trigonometric Function1'

            rtb_Sum_n = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_k *
                0.99330562000985867 / rtb_Sum_n);

            // UnitConversion: '<S47>/Unit Conversion' incorporates:
            //   Constant: '<S24>/AngleLLA'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_j = 0.0;

            // Product: '<S33>/dEast' incorporates:
            //   Constant: '<S48>/Constant3'
            //   Product: '<S48>/Product4'
            //   Trigonometry: '<S48>/Trigonometric Function'
            //   Trigonometry: '<S48>/Trigonometric Function2'

            rtb_Switch_k = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_k * std::cos
                (rtb_Up)) * rtb_Sum1_idx_1;

            // SignalConversion generated from: '<S24>/Orbit Follower' incorporates:
            //   Gain: '<S24>/inverse'
            //   Product: '<S33>/x*cos'
            //   Product: '<S33>/x*sin'
            //   Product: '<S33>/y*cos'
            //   Product: '<S33>/y*sin'
            //   Sum: '<S29>/Sum'
            //   Sum: '<S33>/Sum2'
            //   Sum: '<S33>/Sum3'
            //   UnaryMinus: '<S29>/Ze2height'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Switch_k *
                0.0 + rtb_Sum_n;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Switch_k -
                rtb_Sum_n * 0.0;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                -(rtu_MissionInput->MissionLocation.Alt + -rtb_Switch_m2);

            // Sum: '<S25>/Sum'
            rtb_Sum_o[0] = rtb_LatitudeGCS -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
            rtb_Sum_o[1] = rtb_Abs1 -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
            rtb_Sum_o[2] = rtb_Down -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Sqrt: '<S25>/sqrt' incorporates:
            //   DotProduct: '<S25>/Dot Product'

            rtb_Gain1_g = std::sqrt((rtb_Sum_o[0] * rtb_Sum_o[0] + rtb_Sum_o[1] *
                rtb_Sum_o[1]) + rtb_Sum_o[2] * rtb_Sum_o[2]);

            // Chart: '<S24>/HdgHoldLogic' incorporates:
            //   DataTypeConversion: '<S24>/Param2'
            //   DataTypeConversion: '<S24>/Param3'

            if (static_cast<uint32_T>(ImmedMission_DW.temporalCounter_i1_p) <
                    31U) {
                ImmedMission_DW.temporalCounter_i1_p = static_cast<uint8_T>(
                    static_cast<uint32_T>(static_cast<uint32_T>
                    (ImmedMission_DW.temporalCounter_i1_p) + 1U));
            }

            // Gateway: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
            // During: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
            if (static_cast<uint32_T>(ImmedMission_DW.is_active_c1_ImmedMission)
                == 0U) {
                // Entry: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
                ImmedMission_DW.is_active_c1_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic 
                // Transition: '<S28>:4'
                if (rtb_Gain1_g >= static_cast<real_T>
                        (rtu_MissionInput->params.Param3)) {
                    // Transition: '<S28>:26'
                    ImmedMission_DW.is_c1_ImmedMission =
                        ImmedMission_IN_OutOfRange;

                    // Entry 'OutOfRange': '<S28>:11'
                    rtb_Gain1_g = 1.0;
                } else {
                    // Transition: '<S28>:27'
                    ImmedMission_DW.is_c1_ImmedMission =
                        ImmedMission_IN_WithInRange;

                    // Entry 'WithInRange': '<S28>:9'
                    rtb_Gain1_g = 0.0;
                }
            } else {
                switch (ImmedMission_DW.is_c1_ImmedMission) {
                  case ImmedMission_IN_OutOfRange:
                    // During 'OutOfRange': '<S28>:11'
                    if (rtb_Gain1_g < static_cast<real_T>
                            (rtu_MissionInput->params.Param2)) {
                        // Transition: '<S28>:15'
                        ImmedMission_DW.is_c1_ImmedMission =
                            ImmedMission_IN_WithInRange;

                        // Entry 'WithInRange': '<S28>:9'
                        rtb_Gain1_g = 0.0;
                    } else {
                        rtb_Gain1_g = 1.0;
                    }
                    break;

                  case ImmedMission_IN_Turning:
                    // During 'Turning': '<S28>:23'
                    if (static_cast<uint32_T>
                            (ImmedMission_DW.temporalCounter_i1_p) >= 20U) {
                        // Transition: '<S28>:24'
                        ImmedMission_DW.is_c1_ImmedMission =
                            ImmedMission_IN_OutOfRange;

                        // Entry 'OutOfRange': '<S28>:11'
                        rtb_Gain1_g = 1.0;
                    } else {
                        rtb_Gain1_g = 2.0;
                    }
                    break;

                  default:
                    // During 'WithInRange': '<S28>:9'
                    if (rtb_Gain1_g >= static_cast<real_T>
                            (rtu_MissionInput->params.Param3)) {
                        // Transition: '<S28>:14'
                        ImmedMission_DW.is_c1_ImmedMission =
                            ImmedMission_IN_Turning;
                        ImmedMission_DW.temporalCounter_i1_p = 0U;

                        // Entry 'Turning': '<S28>:23'
                        rtb_Gain1_g = 2.0;
                    } else {
                        rtb_Gain1_g = 0.0;
                    }
                    break;
                }
            }

            // End of Chart: '<S24>/HdgHoldLogic'

            // DataTypeConversion: '<S24>/DoubleStatus'
            *rty_TaskStatus = rtb_Gain1_g;

            // SignalConversion generated from: '<S24>/Orbit Follower'
            rtb_Up = rtb_LatitudeGCS;
            rtb_Sum1_idx_1 = rtb_Abs1;
            rtb_Switch_k = rtb_Down;
            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 = rtb_Sum_dq;

            // Signum: '<S24>/Sign' incorporates:
            //   DataTypeConversion: '<S24>/DoubleTurnDir'

            if (static_cast<real_T>(rtu_MissionInput->FormationPos) < 0.0) {
                rtb_LatitudeGCS = -1.0;
            } else {
                rtb_LatitudeGCS = static_cast<real_T>(static_cast<real_T>
                    (rtu_MissionInput->FormationPos) > 0.0);
            }

            // End of Signum: '<S24>/Sign'

            // MATLABSystem: '<S24>/Orbit Follower' incorporates:
            //   DataTypeConversion: '<S24>/DoubleParam4'
            //   SignalConversion generated from: '<S24>/Orbit Follower'

            ImmedMission_DW.obj_c.OrbitRadiusFlag = 0U;
            ImmedMission_DW.obj_c.OrbitRadiusFlag = 1U;
            rtb_Down = static_cast<real_T>(rtu_MissionInput->params.Param1);
            ImmedMission_DW.obj_c.LookaheadDistFlag = 0U;
            if (static_cast<real_T>(rtu_MissionInput->params.Param1) < 0.1) {
                rtb_Down = 0.1;
                ImmedMission_DW.obj_c.LookaheadDistFlag = 1U;
            }

            rtb_TmpSignalConversionAtOrbitF[0] = rtb_Up -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
            rtb_TmpSignalConversionAtOrbitF[1] = rtb_Abs1 -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
            if (ImmedMission_norm_p(rtb_TmpSignalConversionAtOrbitF) <
                    2.47032822920623E-323) {
                rtb_Sum_o[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                rtb_Abs1 = rtb_Sum_dq;
            } else {
                boolean_T guard1{ false };

                boolean_T rtb_Ctrl;
                rtb_Compare_lh = false;
                rtb_Ctrl = true;
                iy = 0;
                exitg1 = false;
                while ((!exitg1) && (iy < 3)) {
                    if ((ImmedMission_DW.obj_c.OrbitCenterInternal[iy] ==
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[iy]) ||
                        (std::isnan(ImmedMission_DW.obj_c.OrbitCenterInternal[iy])
                         && std::isnan
                            (rtb_TmpSignalConversionAtOrbitFollowerInport2[iy])))
                    {
                        iy = static_cast<int32_T>(iy + 1);
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
                       ^ 1))) || (!(ImmedMission_DW.obj_c.OrbitRadiusInternal ==
                                    0.1))) {
                    ImmedMission_DW.obj_c.NumCircles = 0.0;
                    ImmedMission_DW.obj_c.OrbitCenterInternal[0] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                    ImmedMission_DW.obj_c.OrbitCenterInternal[1] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                    ImmedMission_DW.obj_c.OrbitCenterInternal[2] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                    ImmedMission_DW.obj_c.OrbitRadiusInternal = 0.1;
                    ImmedMission_DW.obj_c.SelectTurnDirectionFlag = true;
                }

                if (rtb_Down >= 0.1) {
                    ImmedMission_DW.obj_c.LookaheadDistance =
                        0.090000000000000011;
                } else {
                    ImmedMission_DW.obj_c.LookaheadDistance = rtb_Down;
                }

                distToCenter_tmp_tmp = rtb_Up -
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                distToCenter_tmp[0] = distToCenter_tmp_tmp;
                rtb_Sum1_idx_0 = rtb_Abs1 -
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                distToCenter_tmp[1] = rtb_Sum1_idx_0;
                rtb_Switch_m2 = std::sqrt(rtb_Sum1_idx_0 * rtb_Sum1_idx_0 +
                    distToCenter_tmp_tmp * distToCenter_tmp_tmp);
                rtb_Down = std::abs(ImmedMission_DW.obj_c.LookaheadDistance +
                                    0.1);
                rtb_Compare_lh = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(std::isinf(rtb_Down)) ^ 1));
                rtb_Ctrl = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(std::isnan(rtb_Down)) ^ 1));
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rtb_Compare_lh)
                      & static_cast<int32_T>(rtb_Ctrl)))) {
                    if (rtb_Down <= 2.2250738585072014E-308) {
                        rtb_Sum_dq = 4.94065645841247E-324;
                    } else {
                        frexp(rtb_Down, &rtb_BiasOldIdx);
                        rtb_Sum_dq = std::ldexp(1.0, static_cast<int32_T>
                                                (rtb_BiasOldIdx - 53));
                    }
                } else {
                    rtb_Sum_dq = (rtNaN);
                }

                guard1 = false;
                if (rtb_Switch_m2 >= (ImmedMission_DW.obj_c.LookaheadDistance +
                                      0.1) - 5.0 * rtb_Sum_dq) {
                    guard1 = true;
                } else {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               (static_cast<int32_T>
                                                (rtb_Compare_lh) &
                                                static_cast<int32_T>(rtb_Ctrl))))
                    {
                        if (rtb_Down <= 2.2250738585072014E-308) {
                            rtb_Sum_dq = 4.94065645841247E-324;
                        } else {
                            frexp(rtb_Down, &colIdx);
                            rtb_Sum_dq = std::ldexp(1.0, static_cast<int32_T>
                                                    (colIdx - 53));
                        }
                    } else {
                        rtb_Sum_dq = (rtNaN);
                    }

                    if (rtb_Switch_m2 <= (0.1 -
                                          ImmedMission_DW.obj_c.LookaheadDistance)
                        + 5.0 * rtb_Sum_dq) {
                        guard1 = true;
                    } else {
                        real_T rtb_Switch_p_tmp;
                        real_T
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp;
                        if (ImmedMission_DW.obj_c.StartFlag) {
                            ImmedMission_DW.obj_c.PrevPosition[0] = rtb_Up;
                            ImmedMission_DW.obj_c.PrevPosition[1] = rtb_Abs1;
                            ImmedMission_DW.obj_c.PrevPosition[2] = rtb_Switch_k;
                            ImmedMission_DW.obj_c.StartFlag = false;
                        }

                        rtb_TmpSignalConversionAtOrbitF[0] =
                            distToCenter_tmp_tmp;
                        rtb_TmpSignalConversionAtOrbitF[1] = rtb_Abs1 -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                        rtb_Sum_dq = ImmedMission_norm_p
                            (rtb_TmpSignalConversionAtOrbitF);
                        rtb_Sum1_idx_0 = ImmedMission_DW.obj_c.LookaheadDistance
                            * ImmedMission_DW.obj_c.LookaheadDistance;
                        rtb_Abs1 = ((rtb_Sum1_idx_0 - 0.010000000000000002) +
                                    rtb_Sum_dq * rtb_Sum_dq) / (2.0 * rtb_Sum_dq);
                        rtb_Sum_n =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] -
                            rtb_Up;
                        rtb_Down = rtb_Sum_n * rtb_Abs1 / rtb_Sum_dq + rtb_Up;
                        rtb_Switch_p_tmp =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] -
                            rtb_Sum1_idx_1;
                        rtb_Switch_m2 = rtb_Switch_p_tmp * rtb_Abs1 / rtb_Sum_dq
                            + rtb_Sum1_idx_1;
                        rtb_Abs1 = std::sqrt(rtb_Sum1_idx_0 - rtb_Abs1 *
                                             rtb_Abs1);
                        rtb_Sum1_idx_0 = rtb_Switch_p_tmp * rtb_Abs1 /
                            rtb_Sum_dq;
                        distToCenter_tmp[0] = rtb_Down - rtb_Sum1_idx_0;
                        distToCenter_tmp[1] = rtb_Sum1_idx_0 + rtb_Down;
                        rtb_Abs1 = rtb_Sum_n * rtb_Abs1 / rtb_Sum_dq;
                        rtb_Switch_p_tmp = rtb_Abs1 + rtb_Switch_m2;
                        xyCenter_idx_1 = rtb_Switch_m2 - rtb_Abs1;
                        if ((rtb_LatitudeGCS == 0.0) && (static_cast<boolean_T>(
                                static_cast<int32_T>(static_cast<int32_T>
                                (ImmedMission_DW.obj_c.SelectTurnDirectionFlag) ^
                               1)))) {
                            rtb_Abs1 =
                                ImmedMission_DW.obj_c.TurnDirectionInternal;
                        } else {
                            rtb_Abs1 = rtb_LatitudeGCS;
                        }

                        rtb_Sum1_idx_0 = ImmedMission_DW.obj_c.PrevPosition[0] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                        rtb_Switch_m2 = ImmedMission_DW.obj_c.PrevPosition[1] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                        rtb_Sum_o[0] = rtb_Sum1_idx_0;
                        rtb_Sum_o[1] = rtb_Switch_m2;
                        rtb_Sum_o[2] = 0.0;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                            distToCenter_tmp_tmp;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                            rtb_Sum1_idx_1 -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                            0.0;
                        if (rtb_Abs1 < 0.0) {
                            rtb_Sum_o[0] = distToCenter_tmp_tmp;
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]
                                = rtb_Sum1_idx_0;
                            rtb_Sum_o[1] =
                                rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                [1];
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1]
                                = rtb_Switch_m2;
                            rtb_Sum_o[2] = 0.0;
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2]
                                = 0.0;
                        }

                        rtb_Sum_dq = ImmedMission_norm_pv(rtb_Sum_o);
                        rtb_Switch_m2 = ImmedMission_norm_pv
                            (rtb_TmpSignalConversionAtRotateATMissionHdgInport1);
                        rtb_Sum1_idx_0 = rtb_Sum_o[0] / rtb_Sum_dq;
                        distToCenter_tmp_tmp =
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]
                            / rtb_Switch_m2;
                        rtb_Down = rtb_Sum_o[1] / rtb_Sum_dq;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp =
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1]
                            / rtb_Switch_m2;
                        ImmedMission_DW.obj_c.PrevPosition[0] = rtb_Up;
                        ImmedMission_DW.obj_c.PrevPosition[1] = rtb_Sum1_idx_1;
                        ImmedMission_DW.obj_c.PrevPosition[2] = rtb_Switch_k;
                        ImmedMission_DW.obj_c.NumCircles += rt_atan2d_snf
                            (rtb_Sum1_idx_0 *
                             rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp
                             - distToCenter_tmp_tmp * rtb_Down, (rtb_Sum1_idx_0 *
                              distToCenter_tmp_tmp + rtb_Down *
                              rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp)
                             + 0.0 / rtb_Sum_dq * (0.0 / rtb_Switch_m2)) / 2.0 /
                            3.1415926535897931;
                        rtb_Sum_o[1] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] -
                            rtb_Sum1_idx_1;
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
                            if ((distToCenter_tmp[0] - rtb_Up) * rtb_Sum_o[1] -
                                    (rtb_Switch_p_tmp - rtb_Sum1_idx_1) *
                                    rtb_Sum_n > 0.0) {
                                rtb_Abs1 = distToCenter_tmp[0];
                                xyCenter_idx_1 = rtb_Switch_p_tmp;
                            } else {
                                rtb_Abs1 = distToCenter_tmp[1];
                            }
                            break;

                          case -1:
                            if ((distToCenter_tmp[0] - rtb_Up) * rtb_Sum_o[1] -
                                    (rtb_Switch_p_tmp - rtb_Sum1_idx_1) *
                                    rtb_Sum_n < 0.0) {
                                rtb_Abs1 = distToCenter_tmp[0];
                                xyCenter_idx_1 = rtb_Switch_p_tmp;
                            } else {
                                rtb_Abs1 = distToCenter_tmp[1];
                            }
                            break;

                          default:
                            if (std::abs(ImmedMission_angdiff(rt_atan2d_snf
                                    (rtb_Switch_p_tmp - rtb_Sum1_idx_1,
                                     distToCenter_tmp[0] - rtb_Up),
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3))
                                < std::abs(ImmedMission_angdiff(rt_atan2d_snf
                                    (xyCenter_idx_1 - rtb_Sum1_idx_1,
                                     distToCenter_tmp[1] - rtb_Up),
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3)))
                            {
                                rtb_Abs1 = distToCenter_tmp[0];
                                xyCenter_idx_1 = rtb_Switch_p_tmp;
                            } else {
                                rtb_Abs1 = distToCenter_tmp[1];
                            }

                            if ((rtb_Abs1 - rtb_Up) * rtb_Sum_o[1] -
                                    (xyCenter_idx_1 - rtb_Sum1_idx_1) *
                                    rtb_Sum_n > 0.0) {
                                ImmedMission_DW.obj_c.TurnDirectionInternal =
                                    1.0;
                            } else {
                                ImmedMission_DW.obj_c.TurnDirectionInternal =
                                    -1.0;
                            }

                            ImmedMission_DW.obj_c.SelectTurnDirectionFlag =
                                false;
                            break;
                        }
                    }
                }

                if (guard1) {
                    rtb_Sum_dq = ImmedMission_norm_p(distToCenter_tmp);
                    rtb_Abs1 = distToCenter_tmp_tmp / rtb_Sum_dq * 0.1 +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                    xyCenter_idx_1 = rtb_Sum1_idx_0 / rtb_Sum_dq * 0.1 +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                }

                rtb_Sum_o[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                rtb_Abs1 = rt_atan2d_snf(xyCenter_idx_1 - rtb_Sum1_idx_1,
                    rtb_Abs1 - rtb_Up);
            }

            // Outputs for Enabled SubSystem: '<S24>/FeedthroughHDG' incorporates:
            //   EnablePort: '<S27>/Enable'

            if (rtb_Gain1_g > 0.0) {
                // SignalConversion generated from: '<S27>/OrbitNavHdg' incorporates:
                //   MATLABSystem: '<S24>/Orbit Follower'

                ImmedMission_DW.OrbitNavHdg = rtb_Abs1;
            }

            // End of Outputs for SubSystem: '<S24>/FeedthroughHDG'

            // Switch: '<S24>/Switch' incorporates:
            //   Constant: '<S24>/Constant'
            //   Constant: '<S30>/Constant'
            //   Product: '<S24>/Product'
            //   RelationalOperator: '<S30>/Compare'

            if (rtb_Gain1_g == 2.0) {
                rtb_Switch_j = 2.3561944901923448 * rtb_LatitudeGCS;
            }

            // End of Switch: '<S24>/Switch'

            // BusCreator: '<S24>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S24>/DoubleTurnDir'
            //   DataTypeConversion: '<S24>/Param4'
            //   Gain: '<S24>/Down2Height'
            //   Gain: '<S24>/Gain'
            //   Gain: '<S24>/GainLayering'
            //   MATLABSystem: '<S24>/Orbit Follower'
            //   Sum: '<S24>/Minus'
            //   Sum: '<S24>/Sum'
            //   Sum: '<S24>/SumHeight'

            rty_GuidanceCMD->Height = -((static_cast<real_T>
                (rtu_MissionInput->FormationPos) - 0.5 * rtb_LatitudeGCS) * 20.0
                + rtb_Sum_o[2]);
            rty_GuidanceCMD->AirSpeed = static_cast<real_T>
                (rtu_MissionInput->params.Param4);
            rty_GuidanceCMD->HeadingAngle = rtb_Switch_j +
                ImmedMission_DW.OrbitNavHdg;
            rtb_Compare_lh = false;
            rty_ControlSwitch[0] = true;
            rty_ControlSwitch[1] = true;

            // End of Outputs for SubSystem: '<S1>/Mode128_DetailedInsp'
        }
        break;

      case 1:
        // Outputs for IfAction SubSystem: '<S1>/Mode130_FlightMissionRH' incorporates:
        //   ActionPort: '<S7>/Action Port'

        rty_ControlSwitch[0] = false;
        rty_ControlSwitch[1] = false;

        // Bias: '<S54>/BiasNumUAV' incorporates:
        //   Constant: '<S54>/ControlHdg'
        //   Constant: '<S54>/ControlSpd'

        rtb_BiasNumUAV = *rtu_FlightMission_numUAV;

        // Bias: '<S54>/BiasOldIdx'
        rtb_BiasOldIdx = *rtu_FlightMission_FormationPos;

        // Gain: '<S55>/Gain1'
        rtb_LatitudeGCS = 0.017453292519943295 *
            *rtu_FlightMission_MissionLocation_degHDG;

        // Bias: '<S54>/Rotate90deg'
        rtb_Sum_dq = rtb_LatitudeGCS + 1.5707963267948966;

        // Sum: '<S54>/Minus' incorporates:
        //   Bias: '<S54>/BiasMissionUAV'
        //   Bias: '<S54>/BiasNewIdx'
        //   Bias: '<S54>/BiasNumUAV'
        //   Bias: '<S54>/BiasOldIdx'
        //   DataTypeConversion: '<S54>/DoubleTurnDir'
        //   DataTypeConversion: '<S54>/Param3'
        //   Product: '<S54>/Divide'
        //   Product: '<S54>/ProductNewShift'
        //   Product: '<S54>/ProductOldShift'
        //   Product: '<S54>/ProductScanWidth'

        rtb_LatitudeGCS = static_cast<real_T>(static_cast<int32_T>
            (rtb_BiasNumUAV - 1)) * static_cast<real_T>
            (*rtu_FlightMission_params_Param3) / static_cast<real_T>(
            static_cast<int32_T>(rtu_MissionInput->numUAV - 1)) *
            (static_cast<real_T>(rtu_MissionInput->FormationPos) + -1.0) -
            static_cast<real_T>(static_cast<int32_T>(rtb_BiasOldIdx - 1)) *
            static_cast<real_T>(*rtu_FlightMission_params_Param3);

        // Sum: '<S54>/SumNorth' incorporates:
        //   Product: '<S54>/ProductNorth'
        //   Trigonometry: '<S54>/Cos'

        rtb_Abs1 = std::cos(rtb_Sum_dq) * rtb_LatitudeGCS +
            rtu_SimUAVstate->North;

        // Sum: '<S54>/SumEast' incorporates:
        //   Product: '<S54>/ProductEast'
        //   Trigonometry: '<S54>/Sin'

        rtb_LatitudeGCS = std::sin(rtb_Sum_dq) * rtb_LatitudeGCS +
            rtu_SimUAVstate->East;

        // DataTypeConversion: '<S54>/DoubleFormPos'
        rtb_Sum_dq = static_cast<real_T>(*rtu_FlightMission_FormationPos);

        // Sum: '<S54>/SumHeight' incorporates:
        //   Bias: '<S54>/NewBias'
        //   Bias: '<S54>/OldBias'
        //   Constant: '<S54>/Three'
        //   DataTypeConversion: '<S54>/DoubleTurnDir'
        //   Gain: '<S54>/Gain'
        //   Math: '<S54>/NewMod'
        //   Math: '<S54>/OldMod'
        //   Sum: '<S54>/MinusLayer'

        rtb_Sum_dq = (rt_modd_snf(static_cast<real_T>
                       (rtu_MissionInput->FormationPos) + -1.0, 3.0) -
                      rt_modd_snf(rtb_Sum_dq + -1.0, 3.0)) * 15.0 +
            rtu_SimUAVstate->Height;

        // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
        //   BusAssignment: '<S54>/Bus Assignment'

        ImmedMission_DW.MergeCollAvoidSimUAV = *rtu_SimUAVstate;

        // BusAssignment: '<S54>/Bus Assignment'
        ImmedMission_DW.MergeCollAvoidSimUAV.North = rtb_Abs1;
        ImmedMission_DW.MergeCollAvoidSimUAV.East = rtb_LatitudeGCS;
        ImmedMission_DW.MergeCollAvoidSimUAV.Height = rtb_Sum_dq;

        // RelationalOperator: '<S56>/Compare' incorporates:
        //   Constant: '<S56>/Constant'

        rtb_Compare_lh = (*rtu_FlightMission_MissionMode == MissionModes::
                          HorzScanNav);

        // DataTypeConversion: '<S54>/DoubleStatus'
        *rty_TaskStatus = static_cast<real_T>(rtb_Compare_lh);

        // End of Outputs for SubSystem: '<S1>/Mode130_FlightMissionRH'
        break;

      case 2:
        {
            real_T rtb_Gain1_g;
            real_T rtb_Sum_n;
            real_T rtb_Switch_j;
            real_T rtb_Switch_k;
            boolean_T rtb_Ctrl;
            ZCEventType zcEvent;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FILE* a;

                // SystemReset for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
                //   ActionPort: '<S8>/Action Port'

                // SystemReset for Triggered SubSystem: '<S58>/WayPointGen'
                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S58>/TriggerCalibrStart'
                //   MATLAB Function: '<S64>/BaseWayPoint'
                //   MATLABSystem: '<S58>/Waypoint Follower'

                ImmedMission_DW.SingletonInstance_not_empty = false;
                a = NULL;
                for (colIdx = 0; colIdx < 20; colIdx++) {
                    ImmedMission_DW.eml_openfiles[colIdx] = a;
                }

                ImmedMission_PrevZCX.WayPointGen_Trig_ZCE_d = NEG_ZCSIG;

                // End of SystemReset for SubSystem: '<S58>/WayPointGen'
                ImmedMission_DW.obj.WaypointIndex = 1.0;
                for (iy = 0; iy < 30723; iy++) {
                    ImmedMission_DW.obj.WaypointsInternal[iy] = (rtNaN);
                }

                ImmedMission_DW.is_active_c7_ImmedMission = 0U;
                ImmedMission_DW.is_c7_ImmedMission =
                    ImmedMission_IN_NO_ACTIVE_CHILD;

                // End of SystemReset for SubSystem: '<S1>/Mode131_SqCalibr'
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S8>/Action Port'

            // DataStoreRead: '<S58>/AltitudeGCS'
            rtw_pthread_mutex_lock(AltitudeGCS_m0);
            rtb_Switch_m2 = AltitudeGCS;
            rtw_pthread_mutex_unlock(AltitudeGCS_m0);

            // DataStoreRead: '<S62>/PrevLatitudeGCS'
            rtw_pthread_mutex_lock(LatitudeGCS_m0);
            rtb_Switch_k = LatitudeGCS;
            rtw_pthread_mutex_unlock(LatitudeGCS_m0);

            // DataStoreRead: '<S62>/PrevLongitudeGCS'
            rtw_pthread_mutex_lock(LongitudeGCS_m0);
            rtb_Gain1_g = LongitudeGCS;
            rtw_pthread_mutex_unlock(LongitudeGCS_m0);

            // Sum: '<S87>/Sum1' incorporates:
            //   Sum: '<S89>/Sum'

            rtb_Sum1_idx_0 = *rtu_FlightMission_MissionLocation_Lat -
                rtb_Switch_k;
            rtb_Sum1_idx_1 = *rtu_FlightMission_MissionLocation_Lon -
                rtb_Gain1_g;

            // Switch: '<S95>/Switch' incorporates:
            //   Abs: '<S95>/Abs'
            //   Bias: '<S95>/Bias'
            //   Bias: '<S95>/Bias1'
            //   Constant: '<S95>/Constant2'
            //   Constant: '<S96>/Constant'
            //   Math: '<S95>/Math Function1'
            //   RelationalOperator: '<S96>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                rtb_Switch_j = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) +
                    -180.0;
            } else {
                rtb_Switch_j = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S95>/Switch'

            // Abs: '<S92>/Abs1'
            rtb_Gain1_g = std::abs(rtb_Switch_j);

            // Switch: '<S92>/Switch' incorporates:
            //   Bias: '<S92>/Bias'
            //   Bias: '<S92>/Bias1'
            //   Constant: '<S88>/Constant'
            //   Constant: '<S88>/Constant1'
            //   Constant: '<S94>/Constant'
            //   Gain: '<S92>/Gain'
            //   Product: '<S92>/Divide1'
            //   RelationalOperator: '<S94>/Compare'
            //   Switch: '<S88>/Switch1'

            if (rtb_Gain1_g > 90.0) {
                // Signum: '<S92>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Switch_j)) ^ 1))) {
                    if (rtb_Switch_j < 0.0) {
                        rtb_Switch_j = -1.0;
                    } else {
                        rtb_Switch_j = static_cast<real_T>(rtb_Switch_j > 0.0);
                    }
                }

                // End of Signum: '<S92>/Sign1'
                rtb_Switch_j *= -(rtb_Gain1_g + -90.0) + 90.0;
                iy = 180;
            } else {
                iy = 0;
            }

            // End of Switch: '<S92>/Switch'

            // Sum: '<S88>/Sum'
            rtb_Gain1_g = static_cast<real_T>(iy) + rtb_Sum1_idx_1;

            // Switch: '<S93>/Switch' incorporates:
            //   Abs: '<S93>/Abs'
            //   Bias: '<S93>/Bias'
            //   Bias: '<S93>/Bias1'
            //   Constant: '<S93>/Constant2'
            //   Constant: '<S97>/Constant'
            //   Math: '<S93>/Math Function1'
            //   RelationalOperator: '<S97>/Compare'

            if (std::abs(rtb_Gain1_g) > 180.0) {
                rtb_Gain1_g = rt_modd_snf(rtb_Gain1_g + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S93>/Switch'

            // UnitConversion: '<S91>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Switch_j;
            rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Gain1_g;

            // UnitConversion: '<S106>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_k *= 0.017453292519943295;

            // Trigonometry: '<S107>/Trigonometric Function1'
            rtb_Gain1_g = std::sin(rtb_Switch_k);

            // Sum: '<S107>/Sum1' incorporates:
            //   Constant: '<S107>/Constant'
            //   Product: '<S107>/Product1'

            rtb_Gain1_g = 1.0 - 0.0066943799901413295 * rtb_Gain1_g *
                rtb_Gain1_g;

            // Product: '<S105>/Product1' incorporates:
            //   Constant: '<S105>/Constant1'
            //   Sqrt: '<S105>/sqrt'

            rtb_Switch_j = 6.378137E+6 / std::sqrt(rtb_Gain1_g);

            // Product: '<S90>/dNorth' incorporates:
            //   Constant: '<S105>/Constant2'
            //   Product: '<S105>/Product3'
            //   Trigonometry: '<S105>/Trigonometric Function1'

            rtb_Gain1_g = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_j *
                0.99330562000985867 / rtb_Gain1_g);

            // Product: '<S90>/dEast' incorporates:
            //   Constant: '<S105>/Constant3'
            //   Product: '<S105>/Product4'
            //   Trigonometry: '<S105>/Trigonometric Function'
            //   Trigonometry: '<S105>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_j = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_j * std::cos
                (rtb_Switch_k)) * rtb_Sum1_idx_1;

            // Sum: '<S90>/Sum2' incorporates:
            //   Product: '<S90>/x*cos'
            //   Product: '<S90>/y*sin'

            rtb_Switch_k = rtb_Switch_j * 0.0 + rtb_Gain1_g;

            // Sum: '<S90>/Sum3' incorporates:
            //   Product: '<S90>/x*sin'
            //   Product: '<S90>/y*cos'

            rtb_Up = rtb_Switch_j - rtb_Gain1_g * 0.0;

            // DataStoreRead: '<S62>/PrevAltitudeGCS'
            rtw_pthread_mutex_lock(AltitudeGCS_m0);
            rtb_Gain1_g = AltitudeGCS;
            rtw_pthread_mutex_unlock(AltitudeGCS_m0);

            // Sum: '<S87>/Sum' incorporates:
            //   Gain: '<S62>/PrevInverse'

            rtb_Gain1_g = *rtu_FlightMission_MissionLocation_Alt + -rtb_Gain1_g;

            // Reshape: '<S58>/ReshapeXe' incorporates:
            //   UnaryMinus: '<S87>/Ze2height'

            rtb_Sum_o[0] = rtb_Switch_k;
            rtb_Sum_o[1] = rtb_Up;
            rtb_Sum_o[2] = -rtb_Gain1_g;

            // Sum: '<S58>/Minus' incorporates:
            //   Reshape: '<S58>/ReshapeXe'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_LatitudeGCS -
                rtb_Switch_k;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Abs1 - rtb_Up;

            // DataStoreRead: '<S58>/LatitudeGCS'
            rtw_pthread_mutex_lock(LatitudeGCS_m0);
            rtb_Up = LatitudeGCS;
            rtw_pthread_mutex_unlock(LatitudeGCS_m0);

            // DataStoreRead: '<S58>/LongitudeGCS'
            rtw_pthread_mutex_lock(LongitudeGCS_m0);
            rtb_Gain1_g = LongitudeGCS;
            rtw_pthread_mutex_unlock(LongitudeGCS_m0);

            // Sum: '<S61>/Sum1' incorporates:
            //   Sum: '<S66>/Sum'

            rtb_Sum1_idx_0 = rtu_MissionInput->MissionLocation.Lat - rtb_Up;
            rtb_Sum1_idx_1 = rtu_MissionInput->MissionLocation.Lon - rtb_Gain1_g;

            // Switch: '<S72>/Switch' incorporates:
            //   Abs: '<S72>/Abs'
            //   Bias: '<S72>/Bias'
            //   Bias: '<S72>/Bias1'
            //   Constant: '<S72>/Constant2'
            //   Constant: '<S73>/Constant'
            //   Math: '<S72>/Math Function1'
            //   RelationalOperator: '<S73>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                rtb_Sum_n = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
            } else {
                rtb_Sum_n = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S72>/Switch'

            // Abs: '<S69>/Abs1'
            rtb_Gain1_g = std::abs(rtb_Sum_n);

            // Switch: '<S69>/Switch' incorporates:
            //   Bias: '<S69>/Bias'
            //   Bias: '<S69>/Bias1'
            //   Constant: '<S65>/Constant'
            //   Constant: '<S65>/Constant1'
            //   Constant: '<S71>/Constant'
            //   Gain: '<S69>/Gain'
            //   Product: '<S69>/Divide1'
            //   RelationalOperator: '<S71>/Compare'
            //   Switch: '<S65>/Switch1'

            if (rtb_Gain1_g > 90.0) {
                // Signum: '<S69>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Sum_n)) ^ 1))) {
                    if (rtb_Sum_n < 0.0) {
                        rtb_Sum_n = -1.0;
                    } else {
                        rtb_Sum_n = static_cast<real_T>(rtb_Sum_n > 0.0);
                    }
                }

                // End of Signum: '<S69>/Sign1'
                rtb_Sum_n *= -(rtb_Gain1_g + -90.0) + 90.0;
                iy = 180;
            } else {
                iy = 0;
            }

            // End of Switch: '<S69>/Switch'

            // Sum: '<S65>/Sum'
            rtb_Gain1_g = static_cast<real_T>(iy) + rtb_Sum1_idx_1;

            // Switch: '<S70>/Switch' incorporates:
            //   Abs: '<S70>/Abs'
            //   Bias: '<S70>/Bias'
            //   Bias: '<S70>/Bias1'
            //   Constant: '<S70>/Constant2'
            //   Constant: '<S74>/Constant'
            //   Math: '<S70>/Math Function1'
            //   RelationalOperator: '<S74>/Compare'

            if (std::abs(rtb_Gain1_g) > 180.0) {
                rtb_Gain1_g = rt_modd_snf(rtb_Gain1_g + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S70>/Switch'

            // UnitConversion: '<S68>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Sum_n;
            rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Gain1_g;

            // UnitConversion: '<S83>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Up *= 0.017453292519943295;

            // Trigonometry: '<S84>/Trigonometric Function1'
            rtb_Sum_n = std::sin(rtb_Up);

            // Sum: '<S84>/Sum1' incorporates:
            //   Constant: '<S84>/Constant'
            //   Product: '<S84>/Product1'

            rtb_Sum_n = 1.0 - 0.0066943799901413295 * rtb_Sum_n * rtb_Sum_n;

            // Product: '<S82>/Product1' incorporates:
            //   Constant: '<S82>/Constant1'
            //   Sqrt: '<S82>/sqrt'

            rtb_Gain1_g = 6.378137E+6 / std::sqrt(rtb_Sum_n);

            // Product: '<S67>/dNorth' incorporates:
            //   Constant: '<S82>/Constant2'
            //   Product: '<S82>/Product3'
            //   Trigonometry: '<S82>/Trigonometric Function1'

            rtb_Sum_n = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Gain1_g *
                0.99330562000985867 / rtb_Sum_n);

            // Product: '<S67>/dEast' incorporates:
            //   Constant: '<S82>/Constant3'
            //   Product: '<S82>/Product4'
            //   Trigonometry: '<S82>/Trigonometric Function'
            //   Trigonometry: '<S82>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Up = 1.0 / rt_atan2d_snf(1.0, rtb_Gain1_g * std::cos(rtb_Up)) *
                rtb_Sum1_idx_1;

            // Outputs for Triggered SubSystem: '<S58>/WayPointGen' incorporates:
            //   TriggerPort: '<S64>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &ImmedMission_PrevZCX.WayPointGen_Trig_ZCE_d,
                               (1.0));
            if (zcEvent != NO_ZCEVENT) {
                // Saturate: '<S64>/Saturation' incorporates:
                //   DataTypeConversion: '<S58>/Param2'

                if (rtu_MissionInput->params.Param2 <= 1.0F) {
                    // Saturate: '<S64>/Saturation'
                    rtb_Switch_k = 1.0;
                } else {
                    // Saturate: '<S64>/Saturation'
                    rtb_Switch_k = static_cast<real_T>
                        (rtu_MissionInput->params.Param2);
                }

                // End of Saturate: '<S64>/Saturation'

                // SignalConversion generated from: '<S64>/RotateATMissionHdg' incorporates:
                //   Bias: '<S64>/Bias'
                //   Gain: '<S60>/Gain1'

                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    0.017453292519943295 *
                    rtu_MissionInput->MissionLocation.degHDG +
                    -0.78539816339744828;

                // MATLABSystem: '<S64>/RotateATMissionHdg'
                rtb_Sum1_idx_0 = std::cos
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = std::sin
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
                out[0] = rtb_Sum1_idx_0;
                out[3] = 0.0 * rtb_Sum1_idx_0 -
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                out[6] = 0.0 * rtb_Sum1_idx_0 +
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] * 0.0;
                out[1] = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                out[4] = 0.0 *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] +
                    rtb_Sum1_idx_0;
                out[7] = 0.0 *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] -
                    rtb_Sum1_idx_0 * 0.0;
                out[2] = -0.0;
                out[5] = 0.0;
                out[8] = 1.0;

                // Reshape: '<S64>/ReshapeRowVec' incorporates:
                //   Gain: '<S58>/inverse'
                //   Product: '<S67>/x*cos'
                //   Product: '<S67>/x*sin'
                //   Product: '<S67>/y*cos'
                //   Product: '<S67>/y*sin'
                //   Sum: '<S61>/Sum'
                //   Sum: '<S67>/Sum2'
                //   Sum: '<S67>/Sum3'
                //   UnaryMinus: '<S61>/Ze2height'

                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = rtb_Up *
                    0.0 + rtb_Sum_n;
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] = rtb_Up -
                    rtb_Sum_n * 0.0;
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                    -(rtu_MissionInput->MissionLocation.Alt + -rtb_Switch_m2);

                // MATLAB Function: '<S64>/BaseWayPoint' incorporates:
                //   DataTypeConversion: '<S58>/Param1'
                //   DataTypeConversion: '<S58>/Param3'

                // MATLAB Function 'ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/WayPointGen/BaseWayPoint': '<S110>:1' 
                // '<S110>:1:5'
                // '<S110>:1:26'
                // '<S110>:1:5'
                rtb_Gain1_g = ImmedMission_DubinsObjSingleton_getMinTurnRadius();

                // '<S110>:1:8'
                iy = 0;
                for (nm1d2 = 0; nm1d2 < 360; nm1d2++) {
                    ImmedMission_DW.CirVec[iy] = b_a[iy] * rtb_Gain1_g;
                    ImmedMission_DW.CirVec[static_cast<int32_T>(iy + 1)] = b_a[
                        static_cast<int32_T>(iy + 1)] * rtb_Gain1_g;
                    iy = static_cast<int32_T>(iy + 2);
                }

                // '<S110>:1:11'
                // '<S110>:1:12'
                linspace_Q5Un26da(static_cast<real_T>
                                  (rtu_MissionInput->params.Param3), WPQ1_tmp);

                // '<S110>:1:16'
                // '<S110>:1:17'
                // '<S110>:1:21'
                // '<S110>:1:22'
                // '<S110>:1:26'
                // '<S110>:1:27'
                // '<S110>:1:31'
                rtb_Gain1_g = static_cast<real_T>
                    (rtu_MissionInput->params.Param1) / 2.0;
                rtb_Up = -static_cast<real_T>(rtu_MissionInput->params.Param1) /
                    2.0;
                for (iy = 0; iy < 91; iy++) {
                    rtb_Sum1_idx_1 = WPQ1_tmp[iy];
                    colIdx = static_cast<int32_T>(iy << 1);
                    ImmedMission_DW.a[static_cast<int32_T>(3 * iy)] =
                        ImmedMission_DW.CirVec[colIdx] + rtb_Gain1_g;
                    ImmedMission_DW.a[static_cast<int32_T>(static_cast<int32_T>
                        (3 * iy) + 1)] = ImmedMission_DW.CirVec
                        [static_cast<int32_T>(colIdx + 1)] + rtb_Gain1_g;
                    ImmedMission_DW.a[static_cast<int32_T>(static_cast<int32_T>
                        (3 * iy) + 2)] = rtb_Sum1_idx_1;
                    colIdx = static_cast<int32_T>(static_cast<int32_T>(iy + 90) <<
                        1);
                    nm1d2 = static_cast<int32_T>(static_cast<int32_T>(iy + 91) *
                        3);
                    ImmedMission_DW.a[nm1d2] = ImmedMission_DW.CirVec[colIdx] +
                        rtb_Up;
                    ImmedMission_DW.a[static_cast<int32_T>(nm1d2 + 1)] =
                        ImmedMission_DW.CirVec[static_cast<int32_T>(colIdx + 1)]
                        + rtb_Gain1_g;
                    ImmedMission_DW.a[static_cast<int32_T>(nm1d2 + 2)] =
                        rtb_Sum1_idx_1;
                    colIdx = static_cast<int32_T>(static_cast<int32_T>(iy + 180)
                        << 1);
                    nm1d2 = static_cast<int32_T>(static_cast<int32_T>(iy + 182) *
                        3);
                    ImmedMission_DW.a[nm1d2] = ImmedMission_DW.CirVec[colIdx] +
                        rtb_Up;
                    ImmedMission_DW.a[static_cast<int32_T>(nm1d2 + 1)] =
                        ImmedMission_DW.CirVec[static_cast<int32_T>(colIdx + 1)]
                        + rtb_Up;
                    ImmedMission_DW.a[static_cast<int32_T>(nm1d2 + 2)] =
                        rtb_Sum1_idx_1;
                    colIdx = static_cast<int32_T>(static_cast<int32_T>(d[iy]) <<
                        1);
                    nm1d2 = static_cast<int32_T>(static_cast<int32_T>(iy + 273) *
                        3);
                    ImmedMission_DW.a[nm1d2] = ImmedMission_DW.CirVec[colIdx] +
                        rtb_Gain1_g;
                    ImmedMission_DW.a[static_cast<int32_T>(nm1d2 + 1)] =
                        ImmedMission_DW.CirVec[static_cast<int32_T>(colIdx + 1)]
                        + rtb_Up;
                    ImmedMission_DW.a[static_cast<int32_T>(nm1d2 + 2)] =
                        rtb_Sum1_idx_1;
                }

                ImmedMission_emxInit_real_T(&d_b, 2);
                i2 = static_cast<int32_T>(d_b->size[0] * d_b->size[1]);

                // MATLAB Function: '<S64>/BaseWayPoint'
                d_b->size[0] = 3;
                d_b->size[1] = static_cast<int32_T>(364 * static_cast<int32_T>
                    (rtb_Switch_k));
                ImmedMission_emxEnsureCapacity_real_T(d_b, i2);

                // MATLAB Function: '<S64>/BaseWayPoint'
                for (iy = 0; iy <= static_cast<int32_T>(static_cast<int32_T>
                        (rtb_Switch_k) - 1); iy = static_cast<int32_T>(iy + 1))
                {
                    i1 = static_cast<int32_T>(static_cast<int32_T>(iy * 1092) -
                        1);
                    for (nm1d2 = 0; nm1d2 < 364; nm1d2++) {
                        i2 = static_cast<int32_T>(nm1d2 * 3);
                        boffset = static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(nm1d2 * 3) + i1) + 1);
                        d_b->data[boffset] = ImmedMission_DW.a[i2];
                        d_b->data[static_cast<int32_T>(boffset + 1)] =
                            ImmedMission_DW.a[static_cast<int32_T>(i2 + 1)];
                        d_b->data[static_cast<int32_T>(boffset + 2)] =
                            ImmedMission_DW.a[static_cast<int32_T>(i2 + 2)];
                    }
                }

                i2 = static_cast<int32_T>(e->size[0] * e->size[1]);

                // MATLAB Function: '<S64>/BaseWayPoint'
                e->size[0] = d_b->size[1];
                e->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(e, i2);

                // MATLAB Function: '<S64>/BaseWayPoint'
                i1 = d_b->size[1];
                for (iy = 0; iy < 3; iy++) {
                    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(i1 - 1); nm1d2
                            ++) {
                        e->data[static_cast<int32_T>(nm1d2 + static_cast<int32_T>
                            (e->size[0] * iy))] = d_b->data[static_cast<int32_T>
                            (static_cast<int32_T>(3 * nm1d2) + iy)];
                    }
                }

                ImmedMission_emxFree_real_T(&d_b);
                ImmedMission_emxInit_real_T(&WayPoint, 2);

                // MATLAB Function: '<S64>/BaseWayPoint'
                ImmedMission_circshift(e);
                i2 = static_cast<int32_T>(WayPoint->size[0] * WayPoint->size[1]);

                // MATLAB Function: '<S64>/BaseWayPoint'
                WayPoint->size[0] = e->size[0];
                WayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(WayPoint, i2);

                // MATLAB Function: '<S64>/BaseWayPoint'
                i1 = static_cast<int32_T>(e->size[0] * 3);
                for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                    WayPoint->data[iy] = e->data[iy];
                }

                ImmedMission_emxInit_real_T(&y_0, 2);

                // MATLAB Function: '<S64>/BaseWayPoint' incorporates:
                //   DataTypeConversion: '<S58>/Param3'

                // '<S110>:1:32'
                rtb_Switch_m2 = 4.0 * rtb_Switch_k * static_cast<real_T>
                    (rtu_MissionInput->params.Param3);
                if (std::isnan(static_cast<real_T>
                               (rtu_MissionInput->params.Param3))) {
                    i2 = static_cast<int32_T>(y_0->size[0] * y_0->size[1]);
                    y_0->size[0] = 1;
                    y_0->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y_0, i2);
                    y_0->data[0] = (rtNaN);
                } else if (std::isnan(rtb_Switch_m2)) {
                    i2 = static_cast<int32_T>(y_0->size[0] * y_0->size[1]);
                    y_0->size[0] = 1;
                    y_0->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y_0, i2);
                    y_0->data[0] = (rtNaN);
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
                    y_0->size[0] = 1;
                    y_0->size[1] = 0;
                } else if (std::isinf(rtb_Switch_m2) && std::isinf
                           (static_cast<real_T>(rtu_MissionInput->params.Param3)))
                {
                    i2 = static_cast<int32_T>(y_0->size[0] * y_0->size[1]);
                    y_0->size[0] = 1;
                    y_0->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y_0, i2);
                    y_0->data[0] = (rtNaN);
                } else if (std::isinf(static_cast<real_T>
                                      (rtu_MissionInput->params.Param3))) {
                    i2 = static_cast<int32_T>(y_0->size[0] * y_0->size[1]);
                    y_0->size[0] = 1;
                    y_0->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y_0, i2);
                    y_0->data[0] = 0.0;
                } else if (std::floor(static_cast<real_T>
                                      (rtu_MissionInput->params.Param3)) ==
                           static_cast<real_T>(rtu_MissionInput->params.Param3))
                {
                    i2 = static_cast<int32_T>(y_0->size[0] * y_0->size[1]);
                    y_0->size[0] = 1;
                    i1 = static_cast<int32_T>(rtb_Switch_m2 / static_cast<real_T>
                        (rtu_MissionInput->params.Param3));
                    y_0->size[1] = static_cast<int32_T>(i1 + 1);
                    ImmedMission_emxEnsureCapacity_real_T(y_0, i2);
                    for (iy = 0; iy <= i1; iy++) {
                        y_0->data[iy] = static_cast<real_T>
                            (rtu_MissionInput->params.Param3) *
                            static_cast<real_T>(iy);
                    }
                } else {
                    rtb_Up = std::floor(rtb_Switch_m2 / static_cast<real_T>
                                        (rtu_MissionInput->params.Param3) + 0.5);
                    rtb_Gain1_g = rtb_Up * static_cast<real_T>
                        (rtu_MissionInput->params.Param3);
                    if (rtu_MissionInput->params.Param3 > 0.0F) {
                        rtb_Switch_k = rtb_Gain1_g - rtb_Switch_m2;
                    } else {
                        rtb_Switch_k = rtb_Switch_m2 - rtb_Gain1_g;
                    }

                    if (std::abs(rtb_Switch_k) < 4.4408920985006262E-16 * std::
                            fmax(0.0, std::abs(rtb_Switch_m2))) {
                        rtb_Up++;
                        rtb_Gain1_g = rtb_Switch_m2;
                    } else if (rtb_Switch_k > 0.0) {
                        rtb_Gain1_g = (rtb_Up - 1.0) * static_cast<real_T>
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

                    i2 = static_cast<int32_T>(y_0->size[0] * y_0->size[1]);
                    y_0->size[0] = 1;
                    y_0->size[1] = static_cast<int32_T>(colIdx + 1);
                    ImmedMission_emxEnsureCapacity_real_T(y_0, i2);
                    if (static_cast<int32_T>(colIdx + 1) > 0) {
                        y_0->data[0] = 0.0;
                        if (static_cast<int32_T>(colIdx + 1) > 1) {
                            y_0->data[colIdx] = rtb_Gain1_g;
                            nm1d2 = static_cast<int32_T>(colIdx / 2);
                            for (iy = 1; static_cast<int32_T>(iy - 1) <=
                                    static_cast<int32_T>(nm1d2 - 2); iy =
                                    static_cast<int32_T>(iy + 1)) {
                                rtb_Switch_m2 = static_cast<real_T>(iy) *
                                    static_cast<real_T>
                                    (rtu_MissionInput->params.Param3);
                                y_0->data[iy] = rtb_Switch_m2;
                                y_0->data[static_cast<int32_T>(colIdx - iy)] =
                                    rtb_Gain1_g - rtb_Switch_m2;
                            }

                            if (static_cast<int32_T>(nm1d2 << 1) == colIdx) {
                                y_0->data[nm1d2] = rtb_Gain1_g / 2.0;
                            } else {
                                rtb_Switch_m2 = static_cast<real_T>(nm1d2) *
                                    static_cast<real_T>
                                    (rtu_MissionInput->params.Param3);
                                y_0->data[nm1d2] = rtb_Switch_m2;
                                y_0->data[static_cast<int32_T>(nm1d2 + 1)] =
                                    rtb_Gain1_g - rtb_Switch_m2;
                            }
                        }
                    }
                }

                ImmedMission_emxInit_real_T(&step_0, 2);
                i2 = static_cast<int32_T>(step_0->size[0] * step_0->size[1]);

                // MATLAB Function: '<S64>/BaseWayPoint'
                step_0->size[0] = 1;
                step_0->size[1] = static_cast<int32_T>(y_0->size[1] * 91);
                ImmedMission_emxEnsureCapacity_real_T(step_0, i2);

                // MATLAB Function: '<S64>/BaseWayPoint'
                if (static_cast<int32_T>(y_0->size[1] * 91) != 0) {
                    colIdx = 0;
                    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(y_0->size[1] -
                          1); nm1d2 = static_cast<int32_T>(nm1d2 + 1)) {
                        step_0->data[colIdx] = y_0->data[nm1d2];
                        for (iy = 0; iy < 90; iy++) {
                            step_0->data[static_cast<int32_T>
                                (static_cast<int32_T>(colIdx + iy) + 1)] =
                                step_0->data[colIdx];
                        }

                        colIdx = static_cast<int32_T>(colIdx + 91);
                    }
                }

                ImmedMission_emxFree_real_T(&y_0);

                // MATLAB Function: '<S64>/BaseWayPoint'
                if (static_cast<int32_T>(step_0->size[1] - 46) < 46) {
                    nm1d2 = 0;
                    colIdx = 0;
                } else {
                    nm1d2 = 45;
                    colIdx = static_cast<int32_T>(step_0->size[1] - 46);
                }

                // '<S110>:1:33'
                if (static_cast<int32_T>(colIdx - nm1d2) == WayPoint->size[0]) {
                    ImmedMission_emxInit_real_T(&WayPoint_0, 1);
                    colIdx = static_cast<int32_T>(WayPoint->size[0] - 1);
                    i2 = WayPoint_0->size[0];
                    WayPoint_0->size[0] = WayPoint->size[0];
                    ImmedMission_emxEnsureCapacity_real_T(WayPoint_0, i2);
                    for (iy = 0; iy <= colIdx; iy++) {
                        WayPoint_0->data[iy] = WayPoint->data
                            [static_cast<int32_T>(static_cast<int32_T>
                            (WayPoint->size[0] << 1) + iy)] + step_0->data[
                            static_cast<int32_T>(nm1d2 + iy)];
                    }

                    i1 = WayPoint_0->size[0];
                    for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                        WayPoint->data[static_cast<int32_T>(iy + static_cast<
                            int32_T>(WayPoint->size[0] << 1))] =
                            WayPoint_0->data[iy];
                    }

                    ImmedMission_emxFree_real_T(&WayPoint_0);
                } else {
                    ImmedMission_binary_expand_op_p(WayPoint, step_0, nm1d2,
                        static_cast<int32_T>(colIdx - 1));
                }

                ImmedMission_emxFree_real_T(&step_0);
                ImmedMission_emxInit_real_T(&rotWayPoint, 2);

                // MATLAB Function: '<S64>/BaseWayPoint'
                // '<S110>:1:35'
                i1 = WayPoint->size[0];
                i2 = static_cast<int32_T>(rotWayPoint->size[0] *
                    rotWayPoint->size[1]);

                // MATLAB Function: '<S64>/BaseWayPoint'
                rotWayPoint->size[0] = WayPoint->size[0];
                rotWayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(rotWayPoint, i2);

                // MATLAB Function: '<S64>/BaseWayPoint' incorporates:
                //   MATLABSystem: '<S64>/RotateATMissionHdg'

                for (colIdx = 0; colIdx < 3; colIdx++) {
                    i2 = static_cast<int32_T>(colIdx * i1);
                    boffset = static_cast<int32_T>(colIdx * 3);
                    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(i1 - 1); nm1d2
                         = static_cast<int32_T>(nm1d2 + 1)) {
                        rotWayPoint->data[static_cast<int32_T>(i2 + nm1d2)] =
                            (WayPoint->data[static_cast<int32_T>(WayPoint->size
                              [0] + nm1d2)] * out[static_cast<int32_T>(boffset +
                              1)] + WayPoint->data[nm1d2] * out[boffset]) +
                            WayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(WayPoint->size[0] << 1) +
                             nm1d2)] * out[static_cast<int32_T>(boffset + 2)];
                    }
                }

                i2 = static_cast<int32_T>(WayPoint->size[0] * WayPoint->size[1]);

                // MATLAB Function: '<S64>/BaseWayPoint'
                WayPoint->size[0] = rotWayPoint->size[0];
                WayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(WayPoint, i2);

                // MATLAB Function: '<S64>/BaseWayPoint' incorporates:
                //   Reshape: '<S64>/ReshapeRowVec'

                nm1d2 = rotWayPoint->size[0];
                for (i1 = 0; i1 <= static_cast<int32_T>(nm1d2 - 1); i1 =
                        static_cast<int32_T>(i1 + 1)) {
                    WayPoint->data[i1] =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                }

                for (i1 = 0; i1 <= static_cast<int32_T>(nm1d2 - 1); i1 =
                        static_cast<int32_T>(i1 + 1)) {
                    WayPoint->data[static_cast<int32_T>(nm1d2 + i1)] =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1];
                }

                iy = static_cast<int32_T>(rotWayPoint->size[0] << 1);
                for (i1 = 0; i1 <= static_cast<int32_T>(nm1d2 - 1); i1 =
                        static_cast<int32_T>(i1 + 1)) {
                    WayPoint->data[static_cast<int32_T>(iy + i1)] =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2];
                }

                // '<S110>:1:38'
                ImmedMission_emxInit_real_T(&tmp, 2);
                if (rotWayPoint->size[0] == WayPoint->size[0]) {
                    ImmedMission_emxInit_real_T(&rotWayPoint_0, 2);
                    i1 = rotWayPoint->size[0];
                    colIdx = rotWayPoint->size[0];
                    nm1d2 = rotWayPoint->size[0];
                    i2 = static_cast<int32_T>(rotWayPoint_0->size[0] *
                        rotWayPoint_0->size[1]);
                    rotWayPoint_0->size[0] = rotWayPoint->size[0];
                    rotWayPoint_0->size[1] = 3;
                    ImmedMission_emxEnsureCapacity_real_T(rotWayPoint_0, i2);
                    for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                        rotWayPoint_0->data[iy] = rotWayPoint->data[static_cast<
                            int32_T>(iy + rotWayPoint->size[0])];
                    }

                    for (iy = 0; iy <= static_cast<int32_T>(colIdx - 1); iy++) {
                        rotWayPoint_0->data[static_cast<int32_T>(iy +
                            rotWayPoint_0->size[0])] = rotWayPoint->data[iy];
                    }

                    for (iy = 0; iy <= static_cast<int32_T>(nm1d2 - 1); iy++) {
                        rotWayPoint_0->data[static_cast<int32_T>(iy +
                            static_cast<int32_T>(rotWayPoint_0->size[0] << 1))] =
                            rotWayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(rotWayPoint->size[0] << 1) +
                             iy)];
                    }

                    i2 = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
                    tmp->size[0] = rotWayPoint_0->size[0];
                    tmp->size[1] = 3;
                    ImmedMission_emxEnsureCapacity_real_T(tmp, i2);
                    i1 = static_cast<int32_T>(rotWayPoint_0->size[0] * 3);
                    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(i1 - 1); nm1d2
                            ++) {
                        tmp->data[nm1d2] = rotWayPoint_0->data[nm1d2] +
                            WayPoint->data[nm1d2];
                    }

                    ImmedMission_emxFree_real_T(&rotWayPoint_0);
                } else {
                    ImmedMission_binary_expand_op(tmp, rotWayPoint, WayPoint);
                }

                ImmedMission_emxFree_real_T(&rotWayPoint);
                ImmedMission_emxFree_real_T(&WayPoint);

                // MATLAB Function: '<S64>/BaseWayPoint'
                ImmedMission_DW.SFunction_DIMS2_b[0] = tmp->size[0];
                ImmedMission_DW.SFunction_DIMS2_b[1] = tmp->size[1];
                i1 = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
                for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                    ImmedMission_DW.nedWayPoint[iy] = tmp->data[iy];
                }

                ImmedMission_emxFree_real_T(&tmp);

                // Concatenate: '<S64>/Matrix Concatenate' incorporates:
                //   Reshape: '<S58>/ReshapeXe'
                //   SignalConversion generated from: '<S64>/FlightMissionLoc'

                ImmedMission_DW.MatrixConcatenate_DIMS1[0] = static_cast<int32_T>
                    (ImmedMission_DW.SFunction_DIMS2_b[0] + 1);
                ImmedMission_DW.MatrixConcatenate_DIMS1[1] =
                    ImmedMission_DW.SFunction_DIMS2_b[1];
                ImmedMission_DW.MatrixConcatenate_d[0] = rtb_Sum_o[0];
                ImmedMission_DW.MatrixConcatenate_d[ImmedMission_DW.MatrixConcatenate_DIMS1
                    [0]] = rtb_Sum_o[1];
                ImmedMission_DW.MatrixConcatenate_d[static_cast<int32_T>
                    (ImmedMission_DW.MatrixConcatenate_DIMS1[0] << 1)] =
                    rtb_Sum_o[2];
                i1 = ImmedMission_DW.SFunction_DIMS2_b[1];
                for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                    colIdx = ImmedMission_DW.SFunction_DIMS2_b[0];
                    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(colIdx - 1);
                            nm1d2++) {
                        ImmedMission_DW.MatrixConcatenate_d[static_cast<int32_T>
                            (static_cast<int32_T>(nm1d2 + static_cast<int32_T>
                              (ImmedMission_DW.MatrixConcatenate_DIMS1[0] * iy))
                             + 1)] = ImmedMission_DW.nedWayPoint
                            [static_cast<int32_T>(static_cast<int32_T>
                            (ImmedMission_DW.SFunction_DIMS2_b[0] * iy) + nm1d2)];
                    }
                }

                // End of Concatenate: '<S64>/Matrix Concatenate'

                // Sum: '<S64>/Minus' incorporates:
                //   Reshape: '<S58>/ReshapeXe'
                //   Selector: '<S64>/Selector'
                //   SignalConversion generated from: '<S64>/FlightMissionLoc'

                ImmedMission_DW.Minus[0] = ImmedMission_DW.nedWayPoint[0] -
                    rtb_Sum_o[0];
                ImmedMission_DW.Minus[1] =
                    ImmedMission_DW.nedWayPoint[ImmedMission_DW.SFunction_DIMS2_b
                    [0]] - rtb_Sum_o[1];
                ImmedMission_DW.Minus[2] = ImmedMission_DW.nedWayPoint[
                    static_cast<int32_T>(ImmedMission_DW.SFunction_DIMS2_b[0] <<
                    1)] - rtb_Sum_o[2];
            }

            // End of Outputs for SubSystem: '<S58>/WayPointGen'

            // SignalConversion generated from: '<S58>/Waypoint Follower' incorporates:
            //   Constant: '<S58>/InitTrigger'
            //   MATLAB Function: '<S64>/BaseWayPoint'

            rtb_Up = rtb_LatitudeGCS;
            rtb_Sum1_idx_1 = rtb_Abs1;
            rtb_Switch_k = rtb_Down;

            // MATLABSystem: '<S58>/Waypoint Follower' incorporates:
            //   Concatenate: '<S64>/Matrix Concatenate'

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (ImmedMission_DW.obj.CacheInputSizes) ^ 1))) {
                ImmedMission_DW.obj.CacheInputSizes = true;
                for (iy = 0; iy < 8; iy++) {
                    ImmedMission_DW.obj.inputVarSize[0].f1[iy] = 1U;
                }

                iy = ImmedMission_DW.MatrixConcatenate_DIMS1[0];
                if (ImmedMission_DW.MatrixConcatenate_DIMS1[0] < 0) {
                    iy = 0;
                }

                ImmedMission_DW.obj.inputVarSize[1].f1[0] = static_cast<uint32_T>
                    (iy);
                iy = ImmedMission_DW.MatrixConcatenate_DIMS1[1];
                if (ImmedMission_DW.MatrixConcatenate_DIMS1[1] < 0) {
                    iy = 0;
                }

                ImmedMission_DW.obj.inputVarSize[1].f1[1] = static_cast<uint32_T>
                    (iy);
                for (iy = 0; iy < 6; iy++) {
                    ImmedMission_DW.obj.inputVarSize[1].f1[static_cast<int32_T>
                        (iy + 2)] = 1U;
                }

                for (iy = 0; iy < 8; iy++) {
                    ImmedMission_DW.obj.inputVarSize[2].f1[iy] = 1U;
                }
            }

            iy = ImmedMission_DW.MatrixConcatenate_DIMS1[0];
            if (ImmedMission_DW.MatrixConcatenate_DIMS1[0] < 0) {
                iy = 0;
            }

            inSize[0] = static_cast<uint32_T>(iy);
            iy = ImmedMission_DW.MatrixConcatenate_DIMS1[1];
            if (ImmedMission_DW.MatrixConcatenate_DIMS1[1] < 0) {
                iy = 0;
            }

            inSize[1] = static_cast<uint32_T>(iy);
            for (iy = 0; iy < 6; iy++) {
                inSize[static_cast<int32_T>(iy + 2)] = 1U;
            }

            iy = 0;
            exitg1 = false;
            while ((!exitg1) && (iy < 8)) {
                if (ImmedMission_DW.obj.inputVarSize[1].f1[iy] != inSize[iy]) {
                    for (iy = 0; iy < 8; iy++) {
                        ImmedMission_DW.obj.inputVarSize[1].f1[iy] = inSize[iy];
                    }

                    exitg1 = true;
                } else {
                    iy = static_cast<int32_T>(iy + 1);
                }
            }

            ImmedMission_DW.obj.LookaheadDistFlag = 0U;
            ImmedMission_DW.obj.InitialPose[0] = 0.0;
            ImmedMission_DW.obj.InitialPose[1] = 0.0;
            ImmedMission_DW.obj.InitialPose[2] = 0.0;
            ImmedMission_DW.obj.InitialPose[3] = 0.0;
            for (iy = 0; iy < 30723; iy++) {
                ImmedMission_DW.paddedWaypts[iy] = (rtNaN);
            }

            i1 = ImmedMission_DW.MatrixConcatenate_DIMS1[0];
            iy = 0;
            for (nm1d2 = 0; nm1d2 < 3; nm1d2++) {
                for (colIdx = 0; colIdx <= static_cast<int32_T>(i1 - 1); colIdx
                        ++) {
                    ImmedMission_DW.paddedWaypts[static_cast<int32_T>(colIdx +
                        iy)] = ImmedMission_DW.MatrixConcatenate_d
                        [static_cast<int32_T>(static_cast<int32_T>
                        (ImmedMission_DW.MatrixConcatenate_DIMS1[0] * nm1d2) +
                        colIdx)];
                }

                iy = static_cast<int32_T>(iy + 10241);
            }

            rtb_Compare_lh = false;
            rtb_Ctrl = true;
            iy = 0;
            exitg1 = false;
            while ((!exitg1) && (iy < 30723)) {
                if ((ImmedMission_DW.obj.WaypointsInternal[iy] ==
                        ImmedMission_DW.paddedWaypts[iy]) || (std::isnan
                        (ImmedMission_DW.obj.WaypointsInternal[iy]) && std::
                        isnan(ImmedMission_DW.paddedWaypts[iy]))) {
                    iy = static_cast<int32_T>(iy + 1);
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
                std::memcpy(&ImmedMission_DW.obj.WaypointsInternal[0],
                            &ImmedMission_DW.paddedWaypts[0],
                            static_cast<uint32_T>(30723U * sizeof(real_T)));
                ImmedMission_DW.obj.WaypointIndex = 1.0;
            }

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            ImmedMission_emxInit_real_T(&waypointsIn, 2);

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S8>/Action Port'

            MatrixConcatenate_d.data = &ImmedMission_DW.MatrixConcatenate_d[0];
            MatrixConcatenate_DIMS1[0] =
                ImmedMission_DW.MatrixConcatenate_DIMS1[0];
            MatrixConcatenate_DIMS1[1] =
                ImmedMission_DW.MatrixConcatenate_DIMS1[1];

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            MatrixConcatenate_d.size = &MatrixConcatenate_DIMS1[0];
            MatrixConcatenate_d.allocatedSize = 30723;
            MatrixConcatenate_d.numDimensions = 2;
            MatrixConcatenate_d.canFreeData = false;

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S8>/Action Port'

            // MATLABSystem: '<S58>/Waypoint Follower' incorporates:
            //   Concatenate: '<S64>/Matrix Concatenate'

            ImmedMission_WaypointFollowerBase_getDistinctWpts
                (&MatrixConcatenate_d, waypointsIn);
            ImmedMission_DW.obj.NumWaypoints = static_cast<real_T>
                (waypointsIn->size[0]);
            ImmedMission_DW.obj.LookaheadDistance = 150.0;

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            ImmedMission_emxInit_real_T(&tmp_0, 2);

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S8>/Action Port'

            // MATLABSystem: '<S58>/Waypoint Follower' incorporates:
            //   SignalConversion generated from: '<S58>/Waypoint Follower'

            if (static_cast<boolean_T>(static_cast<int32_T>((waypointsIn->size[0]
                   == 0) | (waypointsIn->size[1] == 0)))) {
                rtb_Gain1_g = rtb_Down;
                rtb_Abs1 = rtb_Sum_dq;

                // MATLABSystem: '<S58>/Waypoint Follower' incorporates:
                //   SignalConversion generated from: '<S58>/Waypoint Follower'

                ImmedMission_DW.WaypointFollower_o5 = 1U;
            } else {
                boolean_T guard1;
                guard1 = false;
                if (waypointsIn->size[0] == 1) {
                    if (ImmedMission_DW.obj.StartFlag) {
                        ImmedMission_DW.obj.InitialPose[0] = rtb_LatitudeGCS;
                        ImmedMission_DW.obj.InitialPose[1] = rtb_Abs1;
                        ImmedMission_DW.obj.InitialPose[2] = rtb_Down;
                        ImmedMission_DW.obj.InitialPose[3] = rtb_Sum_dq;
                    }

                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                        waypointsIn->data[0] - rtb_LatitudeGCS;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                        waypointsIn->data[1] - rtb_Abs1;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                        waypointsIn->data[2] - rtb_Down;
                    if (ImmedMission_norm_pv
                            (rtb_TmpSignalConversionAtRotateATMissionHdgInport1)
                        < 1.4901161193847656E-8) {
                        rtb_Gain1_g = rtb_Down;
                        rtb_Abs1 = rtb_Sum_dq;

                        // MATLABSystem: '<S58>/Waypoint Follower' incorporates:
                        //   SignalConversion generated from: '<S58>/Waypoint Follower'

                        ImmedMission_DW.WaypointFollower_o5 = 1U;
                        ImmedMission_DW.obj.StartFlag = false;
                    } else {
                        ImmedMission_DW.obj.StartFlag = false;
                        ImmedMission_DW.obj.NumWaypoints = 2.0;
                        waypointsIn_0[0] = 1;
                        waypointsIn_0[1] = 3;
                        i2 = static_cast<int32_T>(tmp_0->size[0] * tmp_0->size[1]);
                        tmp_0->size[0] = 2;
                        tmp_0->size[1] = 3;
                        ImmedMission_emxEnsureCapacity_real_T(tmp_0, i2);
                        for (iy = 0; iy < 3; iy++) {
                            tmp_0->data[static_cast<int32_T>(tmp_0->size[0] * iy)]
                                = ImmedMission_DW.obj.InitialPose[iy];
                            tmp_0->data[static_cast<int32_T>(1 +
                                static_cast<int32_T>(tmp_0->size[0] * iy))] =
                                waypointsIn->data[static_cast<int32_T>(
                                static_cast<int32_T>(waypointsIn_0[0]) * iy)];
                        }

                        i2 = static_cast<int32_T>(waypointsIn->size[0] *
                            waypointsIn->size[1]);
                        waypointsIn->size[0] = 2;
                        waypointsIn->size[1] = 3;
                        ImmedMission_emxEnsureCapacity_real_T(waypointsIn, i2);
                        for (iy = 0; iy < 6; iy++) {
                            waypointsIn->data[iy] = tmp_0->data[iy];
                        }

                        guard1 = true;
                    }
                } else {
                    guard1 = true;
                }

                if (guard1) {
                    real_T rtb_Switch_p_tmp;
                    real_T rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
                    boolean_T guard2{ false };

                    rtb_Compare_lh = false;
                    if (ImmedMission_DW.obj.WaypointIndex ==
                            ImmedMission_DW.obj.NumWaypoints) {
                        rtb_Compare_lh = true;
                    }

                    if (rtb_Compare_lh) {
                        ImmedMission_DW.obj.LastWaypointFlag = true;
                        ImmedMission_DW.obj.WaypointIndex--;
                    }

                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                        waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(ImmedMission_DW.obj.WaypointIndex)
                         - 1)];
                    rtb_Gain1_g = waypointsIn->data[static_cast<int32_T>(
                        static_cast<int32_T>(ImmedMission_DW.obj.WaypointIndex +
                        1.0) - 1)];
                    rtb_Sum_o[0] = rtb_LatitudeGCS - rtb_Gain1_g;
                    rtb_Sum1_idx_0 = rtb_Gain1_g;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                        waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>
                          (ImmedMission_DW.obj.WaypointIndex) +
                          waypointsIn->size[0]) - 1)];
                    rtb_Gain1_g = waypointsIn->data[static_cast<int32_T>(
                        static_cast<int32_T>(static_cast<int32_T>
                        (ImmedMission_DW.obj.WaypointIndex + 1.0) +
                        waypointsIn->size[0]) - 1)];
                    rtb_Sum_o[1] = rtb_Abs1 - rtb_Gain1_g;
                    rtb_Switch_m2 = rtb_Gain1_g;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                        waypointsIn->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>
                          (waypointsIn->size[0] << 1) + static_cast<int32_T>
                          (ImmedMission_DW.obj.WaypointIndex)) - 1)];
                    rtb_Gain1_g = waypointsIn->data[static_cast<int32_T>(
                        static_cast<int32_T>(static_cast<int32_T>
                        (ImmedMission_DW.obj.WaypointIndex + 1.0) +
                        static_cast<int32_T>(waypointsIn->size[0] << 1)) - 1)];
                    rtb_Sum_o[2] = rtb_Down - rtb_Gain1_g;
                    rtb_LatitudeGCS = ImmedMission_norm_pv(rtb_Sum_o);
                    guard2 = false;
                    if (rtb_LatitudeGCS <= 100.0) {
                        guard2 = true;
                    } else {
                        rtb_Switch_j = rtb_Sum1_idx_0 -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                        turnVector[0] = rtb_Switch_j;
                        rtb_Sum_n = rtb_Switch_m2 -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1];
                        turnVector[1] = rtb_Sum_n;
                        rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 =
                            rtb_Gain1_g -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2];
                        turnVector[2] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
                        rtb_Sum_dq = ImmedMission_norm_pv(turnVector);
                        rtb_Switch_p_tmp = (rtb_Switch_j / rtb_Sum_dq *
                                            (rtb_Sum_o[0] / rtb_LatitudeGCS) +
                                            rtb_Sum_n / rtb_Sum_dq * (rtb_Sum_o
                                             [1] / rtb_LatitudeGCS)) +
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 /
                            rtb_Sum_dq * (rtb_Sum_o[2] / rtb_LatitudeGCS);
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(std::isnan(rtb_Switch_p_tmp))
                              ^ 1))) {
                            if (rtb_Switch_p_tmp < 0.0) {
                                rtb_Switch_p_tmp = -1.0;
                            } else {
                                rtb_Switch_p_tmp = static_cast<real_T>
                                    (rtb_Switch_p_tmp > 0.0);
                            }
                        }

                        if (rtb_Switch_p_tmp >= 0.0) {
                            guard2 = true;
                        }
                    }

                    if (guard2) {
                        ImmedMission_DW.obj.WaypointIndex++;
                        rtb_Compare_lh = false;
                        if (ImmedMission_DW.obj.WaypointIndex ==
                                ImmedMission_DW.obj.NumWaypoints) {
                            rtb_Compare_lh = true;
                        }

                        if (rtb_Compare_lh) {
                            ImmedMission_DW.obj.LastWaypointFlag = true;
                            ImmedMission_DW.obj.WaypointIndex--;
                        }

                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                            waypointsIn->data[static_cast<int32_T>
                            (static_cast<int32_T>
                             (ImmedMission_DW.obj.WaypointIndex) - 1)];
                        rtb_Sum1_idx_0 = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>
                            (ImmedMission_DW.obj.WaypointIndex + 1.0) - 1)];
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                            waypointsIn->data[static_cast<int32_T>
                            (static_cast<int32_T>(static_cast<int32_T>
                              (ImmedMission_DW.obj.WaypointIndex) +
                              waypointsIn->size[0]) - 1)];
                        rtb_Switch_m2 = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<int32_T>
                            (ImmedMission_DW.obj.WaypointIndex + 1.0) +
                            waypointsIn->size[0]) - 1)];
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                            waypointsIn->data[static_cast<int32_T>
                            (static_cast<int32_T>(static_cast<int32_T>
                              (waypointsIn->size[0] << 1) + static_cast<int32_T>
                              (ImmedMission_DW.obj.WaypointIndex)) - 1)];
                        rtb_Gain1_g = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<int32_T>
                            (ImmedMission_DW.obj.WaypointIndex + 1.0) +
                            static_cast<int32_T>(waypointsIn->size[0] << 1)) - 1)];
                    }

                    rtb_Switch_j = rtb_Sum1_idx_0 -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                    rtb_Sum_dq = rtb_Up -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                    rtb_Sum_n = rtb_Switch_m2 -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1];
                    rtb_Switch_p_tmp = rtb_Abs1 -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1];
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 =
                        rtb_Gain1_g -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2];
                    distToCenter_tmp_tmp = rtb_Down -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2];
                    rtb_LatitudeGCS = ((rtb_Switch_p_tmp * rtb_Sum_n +
                                        rtb_Sum_dq * rtb_Switch_j) +
                                       distToCenter_tmp_tmp *
                                       rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3)
                        / ((rtb_Sum_n * rtb_Sum_n + rtb_Switch_j * rtb_Switch_j)
                           + rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3
                           * rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3);
                    if (rtb_LatitudeGCS < 0.0) {
                        rtb_Sum_o[0] = rtb_Sum_dq;
                        rtb_Sum_o[1] = rtb_Switch_p_tmp;
                        rtb_Sum_o[2] = distToCenter_tmp_tmp;
                        rtb_LatitudeGCS = ImmedMission_norm_pv(rtb_Sum_o);
                    } else if (rtb_LatitudeGCS > 1.0) {
                        rtb_Sum_o[0] = rtb_Up - rtb_Sum1_idx_0;
                        rtb_Sum_o[1] = rtb_Abs1 - rtb_Switch_m2;
                        rtb_Sum_o[2] = rtb_Down - rtb_Gain1_g;
                        rtb_LatitudeGCS = ImmedMission_norm_pv(rtb_Sum_o);
                    } else {
                        rtb_Sum_o[0] = rtb_Up - (rtb_LatitudeGCS * rtb_Switch_j
                            + rtb_TmpSignalConversionAtRotateATMissionHdgInport1[
                            0]);
                        rtb_Sum_o[1] = rtb_Abs1 - (rtb_LatitudeGCS * rtb_Sum_n +
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1]);
                        rtb_Sum_o[2] = rtb_Down - (rtb_LatitudeGCS *
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3
                            + rtb_TmpSignalConversionAtRotateATMissionHdgInport1[
                            2]);
                        rtb_LatitudeGCS = ImmedMission_norm_pv(rtb_Sum_o);
                    }

                    if (ImmedMission_DW.obj.LastWaypointFlag) {
                        rtb_LatitudeGCS = (((rtb_Up -
                                             rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                             [0]) * (rtb_Sum1_idx_0 -
                                             rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                             [0]) + (rtb_Abs1 -
                                             rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                             [1]) * (rtb_Switch_m2 -
                                             rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                             [1])) + (rtb_Down -
                                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                            [2]) * (rtb_Gain1_g -
                                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                            [2])) / (((rtb_Sum1_idx_0 -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0])
                            * (rtb_Sum1_idx_0 -
                               rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                               [0]) + (rtb_Switch_m2 -
                                       rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                       [1]) * (rtb_Switch_m2 -
                                               rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                               [1])) + (rtb_Gain1_g -
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2])
                            * (rtb_Gain1_g -
                               rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                               [2]));
                        rtb_Sum_o[0] = rtb_Up - (rtb_LatitudeGCS * rtb_Switch_j
                            + rtb_TmpSignalConversionAtRotateATMissionHdgInport1[
                            0]);
                        rtb_Sum_o[1] = rtb_Abs1 - (rtb_LatitudeGCS * rtb_Sum_n +
                            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1]);
                        rtb_Sum_o[2] = rtb_Down - (rtb_LatitudeGCS *
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3
                            + rtb_TmpSignalConversionAtRotateATMissionHdgInport1[
                            2]);
                        rtb_LatitudeGCS = ImmedMission_norm_pv(rtb_Sum_o);
                    }

                    rtb_Down = std::abs(rtb_LatitudeGCS);
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                            (static_cast<int32_T>(std::isinf(rtb_Down)) ^ 1))) &
                          static_cast<int32_T>(static_cast<boolean_T>(
                            static_cast<int32_T>(static_cast<int32_T>(std::isnan
                              (rtb_Down)) ^ 1)))))) {
                        if (rtb_Down <= 2.2250738585072014E-308) {
                            rtb_Sum_dq = 4.94065645841247E-324;
                            rtb_Abs1 = 4.94065645841247E-324;
                        } else {
                            frexp(rtb_Down, &rtb_BiasNumUAV);
                            rtb_Sum_dq = std::ldexp(1.0, static_cast<int32_T>
                                                    (rtb_BiasNumUAV - 53));
                            frexp(rtb_Down, &rtb_BiasOldIdx);
                            rtb_Abs1 = std::ldexp(1.0, static_cast<int32_T>
                                                  (rtb_BiasOldIdx - 53));
                        }
                    } else {
                        rtb_Sum_dq = (rtNaN);
                        rtb_Abs1 = (rtNaN);
                    }

                    if (ImmedMission_DW.obj.LookaheadDistance <= std::fmax(std::
                            sqrt(rtb_Sum_dq), 5.0 * rtb_Abs1) + rtb_LatitudeGCS)
                    {
                        ImmedMission_DW.obj.LookaheadDistance =
                            ImmedMission_DW.obj.LookaheadFactor *
                            rtb_LatitudeGCS;
                    }

                    rtb_Down =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] -
                        rtb_Up;
                    rtb_Abs1 =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] -
                        rtb_Sum1_idx_1;
                    rtb_Switch_p_tmp = ((rtb_Sum1_idx_0 -
                                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                         [0]) * (rtb_Sum1_idx_0 -
                                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                         [0]) + (rtb_Switch_m2 -
                                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                         [1]) * (rtb_Switch_m2 -
                                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                                         [1])) + (rtb_Gain1_g -
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2]) *
                        (rtb_Gain1_g -
                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2]);
                    rtb_Sum_dq =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] -
                        rtb_Switch_k;
                    rtb_LatitudeGCS = ((rtb_Switch_j * rtb_Down + rtb_Sum_n *
                                        rtb_Abs1) +
                                       rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3
                                       * rtb_Sum_dq) * 2.0;
                    rtb_Sum_dq = std::sqrt(rtb_LatitudeGCS * rtb_LatitudeGCS -
                                           (((rtb_Down * rtb_Down + rtb_Abs1 *
                        rtb_Abs1) + rtb_Sum_dq * rtb_Sum_dq) -
                                            ImmedMission_DW.obj.LookaheadDistance
                                            * ImmedMission_DW.obj.LookaheadDistance)
                                           * (4.0 * rtb_Switch_p_tmp));
                    rtb_Abs1 = std::fmax((-rtb_LatitudeGCS + rtb_Sum_dq) / 2.0 /
                                         rtb_Switch_p_tmp, (-rtb_LatitudeGCS -
                                          rtb_Sum_dq) / 2.0 / rtb_Switch_p_tmp);
                    rtb_Gain1_g = (1.0 - rtb_Abs1) *
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] +
                        rtb_Abs1 * rtb_Gain1_g;
                    rtb_Abs1 = rt_atan2d_snf(((1.0 - rtb_Abs1) *
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] +
                        rtb_Abs1 * rtb_Switch_m2) - rtb_Sum1_idx_1, ((1.0 -
                        rtb_Abs1) *
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] +
                        rtb_Abs1 * rtb_Sum1_idx_0) - rtb_Up);

                    // MATLABSystem: '<S58>/Waypoint Follower' incorporates:
                    //   SignalConversion generated from: '<S58>/Waypoint Follower'

                    ImmedMission_DW.WaypointFollower_o5 = 0U;
                    rtb_Compare_lh = false;
                    if (ImmedMission_DW.obj.LastWaypointFlag) {
                        rtb_Compare_lh = true;
                    }

                    if (rtb_Compare_lh) {
                        // MATLABSystem: '<S58>/Waypoint Follower'
                        ImmedMission_DW.WaypointFollower_o5 = 1U;
                    }

                    ImmedMission_DW.obj.LastWaypointFlag = false;
                }
            }

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            ImmedMission_emxFree_real_T(&tmp_0);
            ImmedMission_emxFree_real_T(&waypointsIn);

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S8>/Action Port'

            // DataTypeConversion: '<S58>/DoubleStatus'
            *rty_TaskStatus = static_cast<real_T>
                (ImmedMission_DW.WaypointFollower_o5);

            // BusCreator: '<S58>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S58>/Param4'
            //   Gain: '<S58>/Down2Height'
            //   MATLABSystem: '<S58>/Waypoint Follower'

            rty_GuidanceCMD->Height = -rtb_Gain1_g;
            rty_GuidanceCMD->AirSpeed = static_cast<real_T>
                (rtu_MissionInput->params.Param4);
            rty_GuidanceCMD->HeadingAngle = rtb_Abs1;

            // Sum: '<S59>/Add3' incorporates:
            //   Product: '<S59>/Element product'

            rtb_LatitudeGCS = rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                ImmedMission_DW.Minus[1] - ImmedMission_DW.Minus[0] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

            // Signum: '<S58>/Sign'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_LatitudeGCS)) ^ 1))) {
                if (rtb_LatitudeGCS < 0.0) {
                    rtb_LatitudeGCS = -1.0;
                } else {
                    rtb_LatitudeGCS = static_cast<real_T>(rtb_LatitudeGCS > 0.0);
                }
            }

            // End of Signum: '<S58>/Sign'

            // Chart: '<S58>/TriggerCalibrStart' incorporates:
            //   Product: '<S58>/Product'

            // Gateway: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
            ImmedMission_DW.xSign_prev = ImmedMission_DW.xSign_start;
            ImmedMission_DW.xSign_start = rtb_LatitudeGCS;

            // During: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
            if (static_cast<uint32_T>(ImmedMission_DW.is_active_c7_ImmedMission)
                == 0U) {
                ImmedMission_DW.xSign_prev = rtb_LatitudeGCS;

                // Entry: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
                ImmedMission_DW.is_active_c7_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
                // Transition: '<S63>:2'
                ImmedMission_DW.is_c7_ImmedMission = ImmedMission_IN_Waiting;

                // Entry 'Waiting': '<S63>:1'
                rtb_Ctrl = false;
            } else if (ImmedMission_DW.is_c7_ImmedMission ==
                       ImmedMission_IN_Running) {
                // During 'Running': '<S63>:3'
                rtb_Ctrl = true;

                // During 'Waiting': '<S63>:1'
            } else if (static_cast<boolean_T>(static_cast<int32_T>
                        ((ImmedMission_DW.Minus[0] *
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                          ImmedMission_DW.Minus[1] *
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[1] < 0.0)
                         & (ImmedMission_DW.xSign_prev !=
                            ImmedMission_DW.xSign_start)))) {
                // Transition: '<S63>:4'
                ImmedMission_DW.is_c7_ImmedMission = ImmedMission_IN_Running;

                // Entry 'Running': '<S63>:3'
                rtb_Ctrl = true;
            } else {
                rtb_Ctrl = false;
            }

            // End of Chart: '<S58>/TriggerCalibrStart'
            rtb_Compare_lh = false;

            // SignalConversion generated from: '<S8>/ControlSwitch' incorporates:
            //   Constant: '<S58>/ShiftSimUAV'

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
                //   ActionPort: '<S9>/Action Port'

                // SystemReset for Triggered SubSystem: '<S112>/WayPointGen'
                // SystemReset for SwitchCase: '<S1>/Switch Case'
                ImmedMission_PrevZCX.WayPointGen_Trig_ZCE = NEG_ZCSIG;

                // End of SystemReset for SubSystem: '<S112>/WayPointGen'
                ImmedMission_Altitude_Reset(&self_Altitude);
                ImmedMission_Altitude_Reset(&self_Heading);

                // End of SystemReset for SubSystem: '<S1>/Mode132_pAttack'
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
            //   ActionPort: '<S9>/Action Port'

            // SignalConversion generated from: '<S112>/Altitude' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   Gain: '<S3>/Gain2'

            rtb_TmpSignalConversionAtAltitudeInport1[0] = rtb_LatitudeGCS;
            rtb_TmpSignalConversionAtAltitudeInport1[1] = rtb_Abs1;

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtAltitudeInport1[2] = -rtb_Up;

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtAltitudeInport1[3] = rtb_Sum_dq;

            // Reshape: '<S112>/RowVecPose' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   Gain: '<S3>/Gain2'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_LatitudeGCS;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Abs1;

            // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = -rtb_Up;

            // End of Outputs for SubSystem: '<Root>/RealState2Pose'

            // DataStoreRead: '<S112>/LatitudeGCS'
            rtw_pthread_mutex_lock(LatitudeGCS_m0);
            rtb_LatitudeGCS = LatitudeGCS;
            rtw_pthread_mutex_unlock(LatitudeGCS_m0);

            // DataStoreRead: '<S112>/LongitudeGCS'
            rtw_pthread_mutex_lock(LongitudeGCS_m0);
            rtb_Sum_dq = LongitudeGCS;
            rtw_pthread_mutex_unlock(LongitudeGCS_m0);

            // Sum: '<S114>/Sum1' incorporates:
            //   Sum: '<S117>/Sum'

            rtb_Sum1_idx_0 = rtu_MissionInput->MissionLocation.Lat -
                rtb_LatitudeGCS;
            rtb_Sum1_idx_1 = rtu_MissionInput->MissionLocation.Lon - rtb_Sum_dq;

            // Switch: '<S123>/Switch' incorporates:
            //   Abs: '<S123>/Abs'
            //   Bias: '<S123>/Bias'
            //   Bias: '<S123>/Bias1'
            //   Constant: '<S123>/Constant2'
            //   Constant: '<S124>/Constant'
            //   Math: '<S123>/Math Function1'
            //   RelationalOperator: '<S124>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                rtb_Abs1 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
            } else {
                rtb_Abs1 = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S123>/Switch'

            // Abs: '<S120>/Abs1'
            rtb_Sum_dq = std::abs(rtb_Abs1);

            // Switch: '<S120>/Switch' incorporates:
            //   Bias: '<S120>/Bias'
            //   Bias: '<S120>/Bias1'
            //   Constant: '<S116>/Constant'
            //   Constant: '<S116>/Constant1'
            //   Constant: '<S122>/Constant'
            //   Gain: '<S120>/Gain'
            //   Product: '<S120>/Divide1'
            //   RelationalOperator: '<S122>/Compare'
            //   Switch: '<S116>/Switch1'

            if (rtb_Sum_dq > 90.0) {
                // Signum: '<S120>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Abs1)) ^ 1))) {
                    if (rtb_Abs1 < 0.0) {
                        rtb_Abs1 = -1.0;
                    } else {
                        rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                    }
                }

                // End of Signum: '<S120>/Sign1'
                rtb_Abs1 *= -(rtb_Sum_dq + -90.0) + 90.0;
                iy = 180;
            } else {
                iy = 0;
            }

            // End of Switch: '<S120>/Switch'

            // Sum: '<S116>/Sum'
            rtb_Sum_dq = static_cast<real_T>(iy) + rtb_Sum1_idx_1;

            // Switch: '<S121>/Switch' incorporates:
            //   Abs: '<S121>/Abs'
            //   Bias: '<S121>/Bias'
            //   Bias: '<S121>/Bias1'
            //   Constant: '<S121>/Constant2'
            //   Constant: '<S125>/Constant'
            //   Math: '<S121>/Math Function1'
            //   RelationalOperator: '<S125>/Compare'

            if (std::abs(rtb_Sum_dq) > 180.0) {
                rtb_Sum_dq = rt_modd_snf(rtb_Sum_dq + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S121>/Switch'

            // UnitConversion: '<S119>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Abs1;
            rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_dq;

            // UnitConversion: '<S134>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_LatitudeGCS *= 0.017453292519943295;

            // Trigonometry: '<S135>/Trigonometric Function1'
            rtb_Sum_dq = std::sin(rtb_LatitudeGCS);

            // Sum: '<S135>/Sum1' incorporates:
            //   Constant: '<S135>/Constant'
            //   Product: '<S135>/Product1'

            rtb_Sum_dq = 1.0 - 0.0066943799901413295 * rtb_Sum_dq * rtb_Sum_dq;

            // Product: '<S133>/Product1' incorporates:
            //   Constant: '<S133>/Constant1'
            //   Sqrt: '<S133>/sqrt'

            rtb_Abs1 = 6.378137E+6 / std::sqrt(rtb_Sum_dq);

            // Product: '<S118>/dNorth' incorporates:
            //   Constant: '<S133>/Constant2'
            //   Product: '<S133>/Product3'
            //   Trigonometry: '<S133>/Trigonometric Function1'

            rtb_Sum_dq = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Abs1 *
                0.99330562000985867 / rtb_Sum_dq);

            // Product: '<S118>/dEast' incorporates:
            //   Constant: '<S133>/Constant3'
            //   Product: '<S133>/Product4'
            //   Trigonometry: '<S133>/Trigonometric Function'
            //   Trigonometry: '<S133>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1 * std::cos
                (rtb_LatitudeGCS)) * rtb_Sum1_idx_1;

            // Sum: '<S118>/Sum2' incorporates:
            //   Product: '<S118>/x*cos'
            //   Product: '<S118>/y*sin'

            rtb_LatitudeGCS = rtb_Abs1 * 0.0 + rtb_Sum_dq;

            // Sum: '<S118>/Sum3' incorporates:
            //   Product: '<S118>/x*sin'
            //   Product: '<S118>/y*cos'

            rtb_Abs1 -= rtb_Sum_dq * 0.0;

            // DataStoreRead: '<S112>/AltitudeGCS'
            rtw_pthread_mutex_lock(AltitudeGCS_m0);
            rtb_Sum_dq = AltitudeGCS;
            rtw_pthread_mutex_unlock(AltitudeGCS_m0);

            // Reshape: '<S112>/ReshapeRowVec' incorporates:
            //   Gain: '<S112>/inverse'
            //   Sum: '<S114>/Sum'
            //   UnaryMinus: '<S114>/Ze2height'

            rtb_Sum_o[2] = -(rtu_MissionInput->MissionLocation.Alt + -rtb_Sum_dq);

            // Outputs for Triggered SubSystem: '<S112>/WayPointGen' incorporates:
            //   TriggerPort: '<S115>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &ImmedMission_PrevZCX.WayPointGen_Trig_ZCE,
                               (1.0));
            if (zcEvent != NO_ZCEVENT) {
                // Concatenate: '<S115>/Matrix Concatenate' incorporates:
                //   Reshape: '<S112>/ReshapeRowVec'
                //   Reshape: '<S112>/RowVecPose'
                //   SignalConversion generated from: '<S115>/MyPose'

                ImmedMission_DW.MatrixConcatenate[0] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                ImmedMission_DW.MatrixConcatenate[1] = rtb_LatitudeGCS;
                ImmedMission_DW.MatrixConcatenate[2] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                ImmedMission_DW.MatrixConcatenate[3] = rtb_Abs1;
                ImmedMission_DW.MatrixConcatenate[4] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                ImmedMission_DW.MatrixConcatenate[5] = rtb_Sum_o[2];
            }

            // End of Outputs for SubSystem: '<S112>/WayPointGen'
            ImmedMission_Altitude(&self_Altitude,
                                  rtb_TmpSignalConversionAtAltitudeInport1,
                                  ImmedMission_DW.MatrixConcatenate, 50.0);

            // Sum: '<S113>/Sum' incorporates:
            //   Constant: '<S112>/Constant'
            //   Constant: '<S112>/InitTrigger'
            //   Reshape: '<S112>/ReshapeRowVec'
            //   Reshape: '<S112>/RowVecPose'

            rtb_LatitudeGCS = rtb_TmpSignalConversionAtOrbitFollowerInport2[0] -
                rtb_LatitudeGCS;

            // DotProduct: '<S113>/Dot Product'
            rtb_Down = rtb_LatitudeGCS * rtb_LatitudeGCS;

            // Sum: '<S113>/Sum' incorporates:
            //   Reshape: '<S112>/ReshapeRowVec'
            //   Reshape: '<S112>/RowVecPose'

            rtb_LatitudeGCS = rtb_TmpSignalConversionAtOrbitFollowerInport2[1] -
                rtb_Abs1;

            // DotProduct: '<S113>/Dot Product'
            rtb_Down += rtb_LatitudeGCS * rtb_LatitudeGCS;

            // Sum: '<S113>/Sum' incorporates:
            //   Reshape: '<S112>/ReshapeRowVec'
            //   Reshape: '<S112>/RowVecPose'

            rtb_LatitudeGCS = rtb_TmpSignalConversionAtOrbitFollowerInport2[2] -
                rtb_Sum_o[2];

            // Sqrt: '<S113>/sqrt' incorporates:
            //   DotProduct: '<S113>/Dot Product'

            rtb_sqrt = std::sqrt(rtb_LatitudeGCS * rtb_LatitudeGCS + rtb_Down);
            ImmedMission_Altitude(&self_Heading,
                                  rtb_TmpSignalConversionAtAltitudeInport1,
                                  ImmedMission_DW.MatrixConcatenate, rtb_sqrt);

            // Switch: '<S112>/Switch' incorporates:
            //   Logic: '<S112>/AND'

            if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                    (self_Altitude.dwork.Altitude_o5) != 0) &
                    (static_cast<int32_T>(self_Heading.dwork.Altitude_o5) != 0))))
            {
                // DataTypeConversion: '<S112>/DoubleStatus' incorporates:
                //   Constant: '<S112>/Attack'

                *rty_TaskStatus = 658475.0;
            } else {
                // DataTypeConversion: '<S112>/DoubleStatus' incorporates:
                //   Constant: '<S112>/Zero'

                *rty_TaskStatus = 0.0;
            }

            // End of Switch: '<S112>/Switch'

            // BusCreator: '<S112>/GuidanceCMDBusCreator' incorporates:
            //   Gain: '<S112>/Down2Height'

            rty_GuidanceCMD->Height = -self_Altitude.dwork.Altitude_o1[2];
            rty_GuidanceCMD->AirSpeed = 0.0;
            rty_GuidanceCMD->HeadingAngle = self_Heading.dwork.HeadingAngle;
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
                //   ActionPort: '<S11>/Action Port'

                // SystemReset for Atomic SubSystem: '<S146>/SailDistance'
                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S148>/EnableSailShift'

                ImmedMission_DW.temporalCounter_i1 = 0U;
                ImmedMission_DW.is_active_c12_ImmedMission = 0U;
                ImmedMission_DW.is_c12_ImmedMission =
                    ImmedMission_IN_NO_ACTIVE_CHILD;

                // End of SystemReset for SubSystem: '<S146>/SailDistance'
                // End of SystemReset for SubSystem: '<S1>/Mode254_ShiftEarthENU' 
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU' incorporates:
            //   ActionPort: '<S11>/Action Port'

            rtb_Compare_lh = true;

            // Outputs for Atomic SubSystem: '<S146>/SailDistance'
            // Outputs for Enabled SubSystem: '<S148>/SailShift' incorporates:
            //   EnablePort: '<S150>/Enable'

            // Gain: '<S147>/Gain1' incorporates:
            //   Constant: '<S146>/Constant'
            //   Gain: '<S151>/Gain1'

            rtb_LatitudeGCS = 0.017453292519943295 *
                rtu_MissionInput->StartPosition.degHDG;

            // End of Outputs for SubSystem: '<S148>/SailShift'
            // End of Outputs for SubSystem: '<S146>/SailDistance'

            // SignalConversion generated from: '<S146>/Coordinate Transformation Conversion' incorporates:
            //   Constant: '<S146>/Zero'
            //   Gain: '<S147>/Gain1'

            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                0] = rtb_LatitudeGCS;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                1] = 0.0;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                2] = 0.0;
            ImmedMission_CoordinateTransformationConversion
                (&self_CoordinateTransformationConversion,
                 rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e);

            // Product: '<S146>/Product' incorporates:
            //   MATLABSystem: '<S146>/Coordinate Transformation Conversion'
            //   Reshape: '<S146>/Reshape'

            iy = 0;
            for (nm1d2 = 0; nm1d2 < 3; nm1d2++) {
                rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2] = 0.0;
                rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2] +=
                    self_CoordinateTransformationConversion.dwork.CoordinateTransformationConversion
                    [iy] * rtu_MissionInput->StartPosition.Lat;
                rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2] +=
                    self_CoordinateTransformationConversion.dwork.CoordinateTransformationConversion
                    [static_cast<int32_T>(iy + 1)] *
                    rtu_MissionInput->StartPosition.Lon;
                rtb_TmpSignalConversionAtOrbitFollowerInport2[nm1d2] +=
                    self_CoordinateTransformationConversion.dwork.CoordinateTransformationConversion
                    [static_cast<int32_T>(iy + 2)] *
                    rtu_MissionInput->StartPosition.Alt;
                iy = static_cast<int32_T>(iy + 3);
            }

            // End of Product: '<S146>/Product'

            // Outputs for Atomic SubSystem: '<S146>/SailDistance'
            // Chart: '<S148>/EnableSailShift'
            if (static_cast<uint32_T>(ImmedMission_DW.temporalCounter_i1) < 127U)
            {
                ImmedMission_DW.temporalCounter_i1 = static_cast<uint8_T>(
                    static_cast<uint32_T>(static_cast<uint32_T>
                    (ImmedMission_DW.temporalCounter_i1) + 1U));
            }

            // Gateway: ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
            // During: ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
            guard1 = false;
            guard2 = false;
            if (static_cast<uint32_T>(ImmedMission_DW.is_active_c12_ImmedMission)
                == 0U) {
                // Entry: ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
                ImmedMission_DW.is_active_c12_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
                // Transition: '<S149>:5'
                ImmedMission_DW.is_c12_ImmedMission = ImmedMission_IN_NotShift;
                ImmedMission_DW.temporalCounter_i1 = 0U;

                // Entry 'NotShift': '<S149>:4'
                guard1 = true;
            } else if (ImmedMission_DW.is_c12_ImmedMission ==
                       ImmedMission_IN_NotShift) {
                // During 'NotShift': '<S149>:4'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((static_cast<uint32_T>
                        (ImmedMission_DW.temporalCounter_i1) >= 100U) &
                                            (rtu_MissionInput->params.Param5 !=
                        0.0F)))) {
                    // Transition: '<S149>:8'
                    ImmedMission_DW.is_c12_ImmedMission = ImmedMission_IN_Shift;

                    // Entry 'Shift': '<S149>:6'
                    guard2 = true;
                } else {
                    guard1 = true;
                }

                // During 'Shift': '<S149>:6'
            } else if (rtu_MissionInput->params.Param5 == 0.0F) {
                // Transition: '<S149>:9'
                ImmedMission_DW.is_c12_ImmedMission = ImmedMission_IN_NotShift;
                ImmedMission_DW.temporalCounter_i1 = 0U;

                // Entry 'NotShift': '<S149>:4'
                guard1 = true;
            } else {
                guard2 = true;
            }

            if (guard2) {
                // Outputs for Enabled SubSystem: '<S148>/SailShift' incorporates:
                //   EnablePort: '<S150>/Enable'

                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (ImmedMission_DW.SailShift_MODE) ^ 1)))
                {
                    // InitializeConditions for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' 
                    ImmedMission_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0;
                    ImmedMission_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0;
                    ImmedMission_DW.SailShift_MODE = true;
                }

                // DiscreteIntegrator: '<S150>/Discrete-Time Integrator' incorporates:
                //   Product: '<S150>/Product'
                //   Trigonometry: '<S150>/Cos'
                //   Trigonometry: '<S150>/Sin'

                rtb_Sum1_idx_0 = static_cast<real_T>
                    (rtu_MissionInput->params.Param5) * std::cos(rtb_LatitudeGCS)
                    * 0.05;
                rtb_Sum1_idx_1 = static_cast<real_T>
                    (rtu_MissionInput->params.Param5) * std::sin(rtb_LatitudeGCS)
                    * 0.05;

                // DiscreteIntegrator: '<S150>/Discrete-Time Integrator'
                ImmedMission_DW.DiscreteTimeIntegrator[0] =
                    ImmedMission_DW.DiscreteTimeIntegrator_DSTATE[0] +
                    rtb_Sum1_idx_0;

                // Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' 
                ImmedMission_DW.DiscreteTimeIntegrator_DSTATE[0] =
                    ImmedMission_DW.DiscreteTimeIntegrator[0] + rtb_Sum1_idx_0;

                // DiscreteIntegrator: '<S150>/Discrete-Time Integrator'
                ImmedMission_DW.DiscreteTimeIntegrator[1] =
                    ImmedMission_DW.DiscreteTimeIntegrator_DSTATE[1] +
                    rtb_Sum1_idx_1;

                // Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' 
                ImmedMission_DW.DiscreteTimeIntegrator_DSTATE[1] =
                    ImmedMission_DW.DiscreteTimeIntegrator[1] + rtb_Sum1_idx_1;

                // End of Outputs for SubSystem: '<S148>/SailShift'

                // Switch: '<S148>/Switch'
                rtb_Sum1_idx_0 = ImmedMission_DW.DiscreteTimeIntegrator[0];
                rtb_Sum1_idx_1 = ImmedMission_DW.DiscreteTimeIntegrator[1];
            }

            if (guard1) {
                // Outputs for Enabled SubSystem: '<S148>/SailShift' incorporates:
                //   EnablePort: '<S150>/Enable'

                ImmedMission_DW.SailShift_MODE = false;

                // End of Outputs for SubSystem: '<S148>/SailShift'

                // Switch: '<S148>/Switch' incorporates:
                //   Constant: '<S148>/Zero'

                rtb_Sum1_idx_0 = 0.0;
                rtb_Sum1_idx_1 = 0.0;
            }

            // End of Chart: '<S148>/EnableSailShift'
            // End of Outputs for SubSystem: '<S146>/SailDistance'

            // Sum: '<S146>/AddEast'
            rtb_LatitudeGCS = (rtu_SimUAVstate->East +
                               rtb_TmpSignalConversionAtOrbitFollowerInport2[0])
                + rtb_Sum1_idx_1;

            // Sum: '<S146>/AddHeight'
            rtb_Abs1 = rtu_SimUAVstate->Height +
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Sum: '<S146>/AddNorth'
            rtb_Sum_dq = (rtu_SimUAVstate->North +
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[1]) +
                rtb_Sum1_idx_0;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   BusAssignment: '<S146>/Bus Assignment'

            ImmedMission_DW.MergeCollAvoidSimUAV = *rtu_SimUAVstate;

            // BusAssignment: '<S146>/Bus Assignment'
            ImmedMission_DW.MergeCollAvoidSimUAV.North = rtb_Sum_dq;
            ImmedMission_DW.MergeCollAvoidSimUAV.East = rtb_LatitudeGCS;
            ImmedMission_DW.MergeCollAvoidSimUAV.Height = rtb_Abs1;
            rty_ControlSwitch[0] = false;
            rty_ControlSwitch[1] = false;

            // SignalConversion generated from: '<S11>/thisTaskStatus' incorporates:
            //   Constant: '<S146>/ControlHdg'
            //   Constant: '<S146>/ControlSpd'

            *rty_TaskStatus = 0.0;

            // End of Outputs for SubSystem: '<S1>/Mode254_ShiftEarthENU'
        }
        break;

      case 5:
        {
            real_T rtb_Gain1_g;
            real_T rtb_Sum_n;
            real_T rtb_Switch_j;
            real_T rtb_Switch_k;

            // Outputs for IfAction SubSystem: '<S1>/Mode253_ShiftBodyXYZ' incorporates:
            //   ActionPort: '<S10>/Action Port'

            rtb_Compare_lh = true;

            // SignalConversion generated from: '<S139>/Coordinate Transformation Conversion' incorporates:
            //   Constant: '<S139>/Constant'

            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[0]
                = rtu_SimUAVstate->HeadingAngle;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[1]
                = rtu_SimUAVstate->FlightPathAngle;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[2]
                = rtu_SimUAVstate->RollAngle;
            ImmedMission_CoordinateTransformationConversion
                (&self_CoordinateTransformationConversion_j,
                 rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1);

            // Product: '<S139>/Matrix Multiply' incorporates:
            //   MATLABSystem: '<S139>/Coordinate Transformation Conversion'
            //   SignalConversion generated from: '<S139>/Matrix Multiply'

            for (iy = 0; iy < 3; iy++) {
                rtb_Sum_o[iy] = 0.0;
                rtb_Sum_o[iy] +=
                    self_CoordinateTransformationConversion_j.dwork.CoordinateTransformationConversion
                    [iy] * 0.0;
                rtb_Sum_o[iy] +=
                    self_CoordinateTransformationConversion_j.dwork.CoordinateTransformationConversion
                    [static_cast<int32_T>(iy + 3)] *
                    rtu_MissionInput->StartPosition.Lon;
                rtb_Sum_o[iy] +=
                    self_CoordinateTransformationConversion_j.dwork.CoordinateTransformationConversion
                    [static_cast<int32_T>(iy + 6)] *
                    rtu_MissionInput->StartPosition.Alt;
            }

            real_T rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;

            // End of Product: '<S139>/Matrix Multiply'

            // Sum: '<S139>/AddEast'
            rtb_Abs1 = rtu_SimUAVstate->East + rtb_Sum_o[1];

            // Sum: '<S139>/AddHeight'
            rtb_Sum_dq = rtu_SimUAVstate->Height + rtb_Sum_o[2];

            // Sum: '<S139>/AddNorth'
            rtb_Down = rtu_SimUAVstate->North + rtb_Sum_o[0];

            // BusAssignment: '<S139>/Bus Assignment'
            rtb_Up = rtu_SimUAVstate->AirSpeed;
            rtb_Sum1_idx_1 = rtu_SimUAVstate->HeadingAngle;
            rtb_Switch_k = rtu_SimUAVstate->FlightPathAngle;
            rtb_Switch_j = rtu_SimUAVstate->RollAngle;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   BusAssignment: '<S139>/Bus Assignment'

            ImmedMission_DW.MergeCollAvoidSimUAV.RollAngleRate =
                rtu_SimUAVstate->RollAngleRate;
            ImmedMission_DW.MergeCollAvoidSimUAV.North = rtb_Down;
            ImmedMission_DW.MergeCollAvoidSimUAV.East = rtb_Abs1;
            ImmedMission_DW.MergeCollAvoidSimUAV.Height = rtb_Sum_dq;

            // Trigonometry: '<S143>/sincos' incorporates:
            //   SignalConversion generated from: '<S143>/sincos'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = std::cos
                (rtb_Sum1_idx_1);
            rtb_Sum1_idx_0 = std::sin(rtb_Sum1_idx_1);
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = std::cos
                (rtb_Switch_k);
            rtb_Switch_m2 = std::sin(rtb_Switch_k);
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = std::cos
                (rtb_Switch_j);
            rtb_Gain1_g = std::sin(rtb_Switch_j);

            // Fcn: '<S143>/Fcn11'
            out[0] = rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

            // Fcn: '<S143>/Fcn21' incorporates:
            //   Fcn: '<S143>/Fcn22'

            rtb_Sum_n = rtb_Switch_m2 * rtb_Gain1_g;
            out[1] = rtb_Sum_n * rtb_TmpSignalConversionAtOrbitFollowerInport2[0]
                - rtb_Sum1_idx_0 *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Fcn: '<S143>/Fcn31' incorporates:
            //   Fcn: '<S143>/Fcn32'

            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 = rtb_Switch_m2 *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
            out[2] = rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                rtb_Sum1_idx_0 * rtb_Gain1_g;

            // Fcn: '<S143>/Fcn12'
            out[3] = rtb_Sum1_idx_0 *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

            // Fcn: '<S143>/Fcn22'
            out[4] = rtb_Sum_n * rtb_Sum1_idx_0 +
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Fcn: '<S143>/Fcn32'
            out[5] = rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 *
                rtb_Sum1_idx_0 - rtb_TmpSignalConversionAtOrbitFollowerInport2[0]
                * rtb_Gain1_g;

            // Fcn: '<S143>/Fcn13'
            out[6] = -rtb_Switch_m2;

            // Fcn: '<S143>/Fcn23'
            out[7] = rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                rtb_Gain1_g;

            // Fcn: '<S143>/Fcn33'
            out[8] = rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Product: '<S139>/Product' incorporates:
            //   Concatenate: '<S144>/Vector Concatenate'
            //   Reshape: '<S139>/Reshape'

            iy = 0;
            for (nm1d2 = 0; nm1d2 < 3; nm1d2++) {
                rtb_Sum_o[nm1d2] = 0.0;
                rtb_Sum_o[nm1d2] += out[iy] * rtb_Up;
                rtb_Sum_o[nm1d2] += out[static_cast<int32_T>(iy + 1)] * 0.0;
                rtb_Sum_o[nm1d2] += out[static_cast<int32_T>(iy + 2)] * 0.0;
                iy = static_cast<int32_T>(iy + 3);
            }

            // End of Product: '<S139>/Product'

            // Outputs for Enabled SubSystem: '<S139>/DivisionByZeroProtection'
            ImmedMission_DivisionByZeroProtection(rtb_Up * std::cos(rtb_Switch_k),
                9.81 * std::tan(rtb_Switch_j), &ImmedMission_DW.Omega_g);

            // End of Outputs for SubSystem: '<S139>/DivisionByZeroProtection'

            // Product: '<S139>/Divide' incorporates:
            //   Gain: '<S139>/Gravity'
            //   Product: '<S139>/HorizSpd'
            //   Trigonometry: '<S139>/Cos'
            //   Trigonometry: '<S139>/Tan'

            rtb_LatitudeGCS = rtu_MissionInput->StartPosition.Lat /
                rtu_SimUAVstate->AirSpeed;

            // MATLAB Function: '<S139>/ConstTurnPred' incorporates:
            //   BusAssignment: '<S139>/Bus Assignment'
            //   Gain: '<S139>/Inverse'
            //   Gain: '<S142>/Gain'

            // MATLAB Function 'ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/ConstTurnPred': '<S140>:1' 
            // '<S140>:1:2'
            rtb_Switch_m2 = rtb_Down;
            rtb_Sum1_idx_0 = rtb_Abs1;
            rtb_Down = 57.295779513082323 * ImmedMission_DW.Omega_g;
            rtb_Sum_n = -rtb_Sum_dq;

            // '<S140>:1:4'
            rtb_Abs1 = std::fmax(std::abs(0.017453292519943295 * rtb_Down),
                                 2.2204460492503131E-16);
            iy = 0;
            if (rtb_Down < 0.0) {
                iy = 1;
            }

            if (static_cast<int32_T>(iy - 1) >= 0) {
                distToCenter_tmp_tmp = -rtb_Abs1;
            }

            if (rtb_Down < 0.0) {
                rtb_Abs1 = distToCenter_tmp_tmp;
            }

            rtb_Sum_dq = rtb_Abs1 * rtb_LatitudeGCS;
            rtb_Down = std::sin(rtb_Sum_dq) / rtb_Abs1;
            rtb_Gain1_g = (1.0 - std::cos(rtb_Sum_dq)) / rtb_Abs1;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   BusAssignment: '<S139>/FinalStateBus'

            // '<S140>:1:5'
            ImmedMission_DW.MergeCollAvoidSimUAV.AirSpeed = rtb_Up;
            ImmedMission_DW.MergeCollAvoidSimUAV.HeadingAngle = rtb_Sum1_idx_1;
            ImmedMission_DW.MergeCollAvoidSimUAV.FlightPathAngle = rtb_Switch_k;
            ImmedMission_DW.MergeCollAvoidSimUAV.RollAngle = rtb_Switch_j;

            // MATLAB Function: '<S139>/ConstTurnPred'
            rtb_Abs1 = rtb_LatitudeGCS * rtb_LatitudeGCS * 0.5 * 0.0;

            // BusAssignment: '<S139>/FinalStateBus' incorporates:
            //   Gain: '<S139>/Down2Up'
            //   MATLAB Function: '<S139>/ConstTurnPred'
            //   Product: '<S139>/Product'

            ImmedMission_DW.MergeCollAvoidSimUAV.North = ((rtb_Down * rtb_Sum_o
                [0] + rtb_Switch_m2) - rtb_Gain1_g * rtb_Sum_o[1]) + rtb_Abs1;
            ImmedMission_DW.MergeCollAvoidSimUAV.East = ((rtb_Gain1_g *
                rtb_Sum_o[0] + rtb_Sum1_idx_0) + rtb_Down * rtb_Sum_o[1]) +
                rtb_Abs1;
            ImmedMission_DW.MergeCollAvoidSimUAV.Height = -((rtb_Sum_o[2] *
                rtb_LatitudeGCS + rtb_Sum_n) + rtb_Abs1);
            rty_ControlSwitch[0] = false;
            rty_ControlSwitch[1] = false;

            // SignalConversion generated from: '<S10>/thisTaskStatus' incorporates:
            //   Constant: '<S139>/ControlHdg'
            //   Constant: '<S139>/ControlSpd'

            *rty_TaskStatus = 0.0;

            // End of Outputs for SubSystem: '<S1>/Mode253_ShiftBodyXYZ'
        }
        break;

      default:
        // Outputs for IfAction SubSystem: '<S1>/AvoidInterPlaneCollision' incorporates:
        //   ActionPort: '<S5>/Action Port'

        // Logic: '<S13>/AND' incorporates:
        //   Constant: '<S13>/ControlSpd'

        rty_ControlSwitch[0] = false;
        rty_ControlSwitch[1] = false;

        // DataTypeConversion: '<S13>/Cast To Double'
        *rty_TaskStatus = 0.0;

        // BusCreator: '<S13>/GuidanceCMDBusCreator'
        rty_GuidanceCMD->Height = 0.0;
        rty_GuidanceCMD->AirSpeed = 0.0;
        rty_GuidanceCMD->HeadingAngle = 0.0;

        // Outputs for Enabled SubSystem: '<S15>/DivisionByZeroProtection'
        ImmedMission_DivisionByZeroProtection(rtu_RealUAVState->AirSpeed_mps *
            std::cos(0.017453292519943295 *
                     rtu_RealUAVState->FlightPathAngle_deg), 9.81 * std::tan
            (0.017453292519943295 * rtu_RealUAVState->RollAngle_deg),
            &ImmedMission_DW.Omega);

        // End of Outputs for SubSystem: '<S15>/DivisionByZeroProtection'

        // MATLAB Function: '<S13>/pdist2' incorporates:
        //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
        //   Gain: '<S153>/Gain1'
        //   Gain: '<S154>/Gain1'
        //   Gain: '<S15>/Gravity'
        //   Product: '<S15>/HorizSpd'
        //   Trigonometry: '<S15>/Cos'
        //   Trigonometry: '<S15>/Tan'

        // MATLAB Function 'ConstTurnPredState/MATLAB Function': '<S19>:1'
        // '<S19>:1:2'
        // '<S19>:1:4'
        // '<S19>:1:5'
        // MATLAB Function 'ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/pdist2': '<S17>:1' 
        if (ImmedMission_DW.SFunction_DIMS2[0] == 0) {
            iy = 0;
        } else {
            iy = ImmedMission_DW.SFunction_DIMS2[0];
        }

        // '<S17>:1:2'
        ImmedMission_DW.SFunction_DIMS2_c = iy;

        // End of MATLAB Function: '<S13>/pdist2'
        rtb_Compare_lh = false;

        // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
        //   Constant: '<S5>/ShiftSimUAV'
        //   SignalConversion generated from: '<S5>/SimUAVstate'

        ImmedMission_DW.MergeCollAvoidSimUAV = *rtu_SimUAVstate;

        // End of Outputs for SubSystem: '<S1>/AvoidInterPlaneCollision'
        break;
    }

    // End of SwitchCase: '<S1>/Switch Case'

    // Switch: '<Root>/SwitchShiftSimUAV'
    if (rtb_Compare_lh) {
        *rty_FinalSimUAVState = ImmedMission_DW.MergeCollAvoidSimUAV;
    } else {
        *rty_FinalSimUAVState = *rtu_SimUAVstate;
    }

    // End of Switch: '<Root>/SwitchShiftSimUAV'

    // Update for Memory: '<S1>/Memory'
    ImmedMission_DW.Memory_PreviousInput = ImmedMission_DW.WaypointFollower_o5;

    // Update for Memory: '<Root>/Memory'
    ImmedMission_DW.Memory_PreviousInput_j = *rtu_RealUAVEngaged;
    ImmedMission_emxFree_real_T(&e);
}

// Model initialize function
void ImmedMission::initialize()
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));
}

// Constructor
ImmedMission::ImmedMission() :
    ImmedMission_DW(),
    ImmedMission_PrevZCX(),
    self_CoordinateTransformationConversion_j(),
    self_CoordinateTransformationConversion(),
    self_Heading(),
    self_Altitude(),
    ImmedMission_M()
{
    // Currently there is no constructor body generated.
}

// Destructor
ImmedMission::~ImmedMission()
{
    // Currently there is no destructor body generated.
}

// Real-Time Model get method
ImmedMission::RT_MODEL_ImmedMission_T * ImmedMission::getRTM()
{
    return (&ImmedMission_M);
}

// member function to setup error status pointer
void ImmedMission::setErrorStatusPointer(const char_T **rt_errorStatus)
{
    rtmSetErrorStatusPointer((&ImmedMission_M), rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
