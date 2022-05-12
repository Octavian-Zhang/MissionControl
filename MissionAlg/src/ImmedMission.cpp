//
// File: ImmedMission.cpp
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 2.149
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed May 11 11:35:48 2022
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
#include <math.h>
#include <cstring>
#include <stdio.h>
#include "rt_modd_snf.h"
#include "linspace_Q5Un26da.h"
#include <stddef.h>
#include <cstdlib>
#include "LookUp_real_T_real_T.h"
#include "zero_crossing_types.h"
#include "ImmedMission_private.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Named constants for Chart: '<S1>/PreemptableMissionModeSelector'
    const uint8_T ImmedMission_IN_CollAvoidance
{
    1U
};
const uint8_T ImmedMission_IN_DetailedInsp{ 2U };

const uint8_T ImmedMission_IN_FlightMissionRH{ 3U };

const uint8_T ImmedMission_IN_Formation{ 4U };

const uint8_T ImmedMission_IN_ImmedMission{ 1U };

const uint8_T ImmedMission_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T ImmedMission_IN_SqCalibr{ 5U };

const uint8_T ImmedMission_IN_WaitToStart{ 2U };

const uint8_T ImmedMission_IN_pAttack{ 6U };

// Named constants for Chart: '<S35>/HdgHoldLogic'
const uint8_T ImmedMission_IN_OutOfRange{ 1U };

const uint8_T ImmedMission_IN_Turning{ 2U };

const uint8_T ImmedMission_IN_WithInRange{ 3U };

// Named constants for Chart: '<S65>/TrackSwitch'
const uint8_T ImmedMission_IN_Long{ 1U };

const uint8_T ImmedMission_IN_Short{ 2U };

// Named constants for Chart: '<S129>/TriggerCalibrStart'
const uint8_T ImmedMission_IN_Running{ 1U };

const uint8_T ImmedMission_IN_Waiting{ 2U };

// Named constants for Chart: '<S219>/EnableSailShift'
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
static uavDubinsConnection_ImmedMission_T
    *ImmedMission_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_ImmedMission_T *b_this, real_T varargin_2, real_T
     varargin_4);
static boolean_T ImmedMission_strcmp_hoc(const emxArray_char_T_ImmedMission_T *a);
static boolean_T ImmedMission_strcmp_hocj(const emxArray_char_T_ImmedMission_T
    *a);
static uavDubinsConnection_ImmedMission_T
    *ImmedMission_DubinsObjSingleton_getIstance(DW_ImmedMission_f_T *localDW);
static void ImmedMission_binary_expand_op_pu(boolean_T in1_data[], int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], int32_T in3,
    int32_T in4, DW_ImmedMission_f_T *localDW);
static void ImmedMission_emxEnsureCapacity_real_T(emxArray_real_T_ImmedMission_T
    *emxArray, int32_T oldNumel);
static real_T ImmedMission_norm_pv(const real_T x[3]);
static void ImmedMission_WaypointFollowerBase_searchClosestPath
    (uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T *obj, const
     real_T waypoints_data[], const int32_T waypoints_size[2], const real_T
     currentPose[4]);
static void ImmedMission_WaypointFollower_stepImpl
    (uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T *obj, const
     real_T currentPose[4], const real_T waypoints_data[], const int32_T
     waypoints_size[2], real_T lookaheadDistance, real_T varargout_1[3], real_T *
     varargout_2, real_T *varargout_3, uint8_T *varargout_4, uint8_T
     *varargout_5, DW_ImmedMission_f_T *localDW);
static void ImmedMission_binary_expand_op_puh(boolean_T in1_data[], int32_T
    in1_size[2], const emxArray_real_T_ImmedMission_T *in2, int32_T in3, int32_T
    in4);
static void ImmedMission_WaypointFollowerBase_getDistinctWpts(const
    emxArray_real_T_ImmedMission_T *waypoints, emxArray_real_T_ImmedMission_T
    *distinctWpts, DW_ImmedMission_f_T *localDW);
static void ImmedMission_circshift(emxArray_real_T_ImmedMission_T *a);
static void ImmedMission_binary_expand_op_p(emxArray_real_T_ImmedMission_T *in1,
    const emxArray_real_T_ImmedMission_T *in2, int32_T in3, int32_T in4);
static real_T ImmedMission_angdiff(real_T x, real_T y);
static void ImmedMission_binary_expand_op(emxArray_real_T_ImmedMission_T *in1,
    const emxArray_real_T_ImmedMission_T *in2, const
    emxArray_real_T_ImmedMission_T *in3);

//
// Output and update for atomic system:
//    '<S101>/Magnitude'
//    '<S108>/Vector Magnitude'
//    '<S109>/Vector Magnitude'
//
void ImmedMission_Magnitude(const real_T rtu_Vec[2], real_T *rty_Mag)
{
    // Sqrt: '<S110>/Sqrt' incorporates:
    //   Math: '<S110>/Math Function'
    //   Sum: '<S110>/Sum of Elements'
    //
    //  About '<S110>/Math Function':
    //   Operator: magnitude^2

    *rty_Mag = std::sqrt(rtu_Vec[0] * rtu_Vec[0] + rtu_Vec[1] * rtu_Vec[1]);
}

//
// Output and update for atomic system:
//    '<S98>/MagnitudeOrigVec'
//    '<S98>/MagnitudePerpVec'
//    '<S98>/MagnitudeProjVec'
//
void ImmedMission_MagnitudeOrigVec(const real_T rtu_Vec[3], real_T *rty_Mag)
{
    // Sqrt: '<S102>/Sqrt' incorporates:
    //   Math: '<S102>/Math Function'
    //   Sum: '<S102>/Sum of Elements'
    //
    //  About '<S102>/Math Function':
    //   Operator: magnitude^2

    *rty_Mag = std::sqrt((rtu_Vec[0] * rtu_Vec[0] + rtu_Vec[1] * rtu_Vec[1]) +
                         rtu_Vec[2] * rtu_Vec[2]);
}

//
// Output and update for atomic system:
//    '<S98>/Vec2QuatIn'
//    '<S98>/Vec2QuatOut'
//
void ImmedMission_Vec2QuatIn(const real_T rtu_Vec[3], real_T *rty_Quat, real_T
    *rty_Quat_d, real_T *rty_Quat_n, real_T *rty_Quat_f)
{
    // local block i/o variables
    real_T rtb_Elevation_l;
    real_T rtb_sincos_o1_d_idx_0;
    real_T rtb_sincos_o1_d_idx_1;
    real_T rtb_sincos_o1_l;
    real_T rtb_sincos_o2_idx_0;
    real_T rtb_sincos_o2_idx_1;
    real_T tmp;

    // Outputs for Atomic SubSystem: '<S108>/Vector Magnitude'
    ImmedMission_Magnitude(&rtu_Vec[0], &rtb_Elevation_l);

    // End of Outputs for SubSystem: '<S108>/Vector Magnitude'

    // Trigonometry: '<S108>/Atan2Elevation'
    rtb_Elevation_l = rt_atan2d_snf(rtu_Vec[2], rtb_Elevation_l);

    // Gain: '<S120>/1//2' incorporates:
    //   Trigonometry: '<S108>/Atan2Azimuth'

    rtb_sincos_o1_d_idx_0 = 0.5 * rt_atan2d_snf(rtu_Vec[1], rtu_Vec[0]);
    rtb_sincos_o1_d_idx_1 = 0.5 * rtb_Elevation_l;

    // Trigonometry: '<S120>/sincos'
    rtb_sincos_o2_idx_0 = std::cos(rtb_sincos_o1_d_idx_0);
    rtb_sincos_o1_d_idx_0 = std::sin(rtb_sincos_o1_d_idx_0);
    rtb_sincos_o2_idx_1 = std::cos(rtb_sincos_o1_d_idx_1);
    rtb_sincos_o1_l = std::sin(rtb_sincos_o1_d_idx_1);

    // Fcn: '<S120>/q0' incorporates:
    //   Fcn: '<S120>/q1'

    rtb_sincos_o1_d_idx_1 = rtb_sincos_o2_idx_0 * rtb_sincos_o2_idx_1;
    tmp = rtb_sincos_o1_d_idx_0 * rtb_sincos_o1_l;
    *rty_Quat = tmp * 0.0 + rtb_sincos_o1_d_idx_1;

    // Fcn: '<S120>/q1'
    *rty_Quat_d = rtb_sincos_o1_d_idx_1 * 0.0 - tmp;

    // Fcn: '<S120>/q2' incorporates:
    //   Fcn: '<S120>/q3'

    rtb_sincos_o1_d_idx_1 = rtb_sincos_o2_idx_0 * rtb_sincos_o1_l;
    tmp = rtb_sincos_o1_d_idx_0 * rtb_sincos_o2_idx_1;
    *rty_Quat_n = tmp * 0.0 + rtb_sincos_o1_d_idx_1;

    // Fcn: '<S120>/q3'
    *rty_Quat_f = tmp - rtb_sincos_o1_d_idx_1 * 0.0;
}

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
    // Start for MATLABSystem: '<S183>/Altitude'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S183>/Altitude'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 6; i++) {
        // InitializeConditions for MATLABSystem: '<S183>/Altitude'
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }
}

// System reset for atomic system:
void ImmedMission_Altitude_Reset(DW_Altitude_ImmedMission_T *localDW)
{
    // InitializeConditions for MATLABSystem: '<S183>/Altitude'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 6; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of InitializeConditions for MATLABSystem: '<S183>/Altitude'
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

    // MATLABSystem: '<S183>/Altitude'
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
        // MATLABSystem: '<S183>/Altitude'
        localDW->Altitude_o1[0] = lambda * std::cos(rtu_0[3]) + rtu_0[0];
        localDW->Altitude_o1[1] = lambda * std::sin(rtu_0[3]) + rtu_0[1];
        localDW->Altitude_o1[2] = lambda * 0.0 + rtu_0[2];

        // MATLABSystem: '<S183>/Altitude'
        localDW->HeadingAngle = rtu_0[3];

        // MATLABSystem: '<S183>/Altitude'
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
                // MATLABSystem: '<S183>/Altitude'
                localDW->Altitude_o1[0] = lambda * std::cos(rtu_0[3]) + rtu_0[0];
                localDW->Altitude_o1[1] = lambda * std::sin(rtu_0[3]) + rtu_0[1];
                localDW->Altitude_o1[2] = lambda * 0.0 + rtu_0[2];

                // MATLABSystem: '<S183>/Altitude'
                localDW->HeadingAngle = rtu_0[3];

                // MATLABSystem: '<S183>/Altitude'
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

            // MATLABSystem: '<S183>/Altitude'
            localDW->Altitude_o1[0] = rtu_0_tmp;
            r_idx_0 = rtu_0_tmp;
            rtu_0_tmp = (1.0 - lambda) * b_waypointsIn[1] + lambda * r_idx_1;

            // MATLABSystem: '<S183>/Altitude'
            localDW->Altitude_o1[1] = rtu_0_tmp;
            localDW->Altitude_o1[2] = (1.0 - lambda) * b_waypointsIn[2] + lambda
                * r_idx_2;

            // MATLABSystem: '<S183>/Altitude'
            localDW->HeadingAngle = rt_atan2d_snf(rtu_0_tmp - rtu_0[1], r_idx_0
                - rtu_0[0]);

            // MATLABSystem: '<S183>/Altitude'
            localDW->Altitude_o5 = 0U;
            p = false;
            if (localDW->obj.LastWaypointFlag) {
                p = true;
            }

            if (p) {
                // MATLABSystem: '<S183>/Altitude'
                localDW->Altitude_o5 = 1U;
            }

            localDW->obj.LastWaypointFlag = false;
        }
    }

    // End of MATLABSystem: '<S183>/Altitude'
}

// System initialize for atomic system:
void ImmedMission_CoordinateTransformationConversion_Init
    (DW_CoordinateTransformationConversion_ImmedMission_T *localDW)
{
    // Start for MATLABSystem: '<S217>/Coordinate Transformation Conversion'
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

    // MATLABSystem: '<S217>/Coordinate Transformation Conversion'
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

    // MATLABSystem: '<S217>/Coordinate Transformation Conversion'
    std::memcpy(&localDW->CoordinateTransformationConversion[0], &out[0],
                static_cast<uint32_T>(9U * sizeof(real_T)));
}

//
// System initialize for enable system:
//    '<S210>/DivisionByZeroProtection'
//    '<S17>/DivisionByZeroProtection'
//    '<S28>/DivisionByZeroProtection'
//
void ImmedMission_DivisionByZeroProtection_Init(real_T *rty_OmegaRad)
{
    *rty_OmegaRad = 0.0;
}

//
// Output and update for enable system:
//    '<S210>/DivisionByZeroProtection'
//    '<S17>/DivisionByZeroProtection'
//    '<S28>/DivisionByZeroProtection'
//
void ImmedMission_DivisionByZeroProtection(real_T rtu_HorizSpd, real_T
    rtu_CentripetalAcc, real_T *rty_OmegaRad)
{
    // Outputs for Enabled SubSystem: '<S210>/DivisionByZeroProtection' incorporates:
    //   EnablePort: '<S212>/Enable'

    if (rtu_HorizSpd > 0.0) {
        // Product: '<S212>/Divide'
        *rty_OmegaRad = 1.0 / rtu_HorizSpd * rtu_CentripetalAcc;
    }

    // End of Outputs for SubSystem: '<S210>/DivisionByZeroProtection'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

    static const char_T d[15]{ 'C', 'l', 'i', 'm', 'b', 'A', 'n', 'g', 'l', 'e',
        'L', 'i', 'm', 'i', 't' };

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
    if (aTmp->size[1] == 15) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 15) {
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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

    static const char_T d[14]{ 'D', 'i', 'v', 'e', 'A', 'n', 'g', 'l', 'e', 'L',
        'i', 'm', 'i', 't' };

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
    if (aTmp->size[1] == 14) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 14) {
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
static uavDubinsConnection_ImmedMission_T
    *ImmedMission_DubinsObjSingleton_getIstance(DW_ImmedMission_f_T *localDW)
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
    uavDubinsConnection_ImmedMission_T *outputArg;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (localDW->SingletonInstance_not_empty) ^ 1))) {
        creal_T tmp;
        creal_T tmp_0;
        real_T c_fid;
        real_T d_fid;
        real_T fid;
        int32_T b;
        int32_T b_0;
        int32_T c;
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
            b_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, b_0);
            loop_ub = k->size[0];
            for (b = 0; b <= static_cast<int32_T>(loop_ub - 1); b++) {
                data->data[b] = k->data[b];
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
                b_0 = static_cast<int32_T>(data_3->size[0] * data_3->size[1]);
                data_3->size[0] = 1;
                data_3->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_3, b_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (b_0 = 0; b_0 <= loop_ub; b_0++) {
                    data_3->data[b_0] = data->data[b_0];
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
                                b = 0;
                            } else {
                                c = 1;
                                b = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            b_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(b - c);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                b_0);
                            for (b = 0; b <= static_cast<int32_T>(loop_ub - 1);
                                    b++) {
                                curSection->data[b] = curLine->data[static_cast<
                                    int32_T>(c + b)];
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
                    b_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    ImmedMission_emxEnsureCapacity_char_T(ret, b_0);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (b = 0; b <= loop_ub; b++) {
                        ret->data[b] = curVal->data[b];
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
            b_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, b_0);
            loop_ub = k->size[0];
            for (b = 0; b <= static_cast<int32_T>(loop_ub - 1); b++) {
                data->data[b] = k->data[b];
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
                b_0 = static_cast<int32_T>(data_2->size[0] * data_2->size[1]);
                data_2->size[0] = 1;
                data_2->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_2, b_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (b_0 = 0; b_0 <= loop_ub; b_0++) {
                    data_2->data[b_0] = data->data[b_0];
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
                                b = 0;
                            } else {
                                c = 1;
                                b = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            b_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(b - c);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                b_0);
                            for (b = 0; b <= static_cast<int32_T>(loop_ub - 1);
                                    b++) {
                                curSection->data[b] = curLine->data[static_cast<
                                    int32_T>(c + b)];
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
                    b_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    ImmedMission_emxEnsureCapacity_char_T(ret, b_0);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (b = 0; b <= loop_ub; b++) {
                        ret->data[b] = curVal->data[b];
                    }

                    exitg1 = true;
                }
            }

            ImmedMission_emxFree_char_T(&data_2);
            ImmedMission_emxFree_char_T(&tmp_6);
            ImmedMission_emxFree_char_T(&tmp_5);
        }

        tmp_0 = ImmedMission_str2double(ret);
        fid = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV MaxRollAngle:\t\t%f\n", fid);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        c_fid = ImmedMission_fileManager(localDW);
        if (c_fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(c_fid, k, localDW);
            b_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, b_0);
            loop_ub = k->size[0];
            for (b = 0; b <= static_cast<int32_T>(loop_ub - 1); b++) {
                data->data[b] = k->data[b];
            }

            ImmedMission_cfclose(c_fid, localDW);
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
                b_0 = static_cast<int32_T>(data_1->size[0] * data_1->size[1]);
                data_1->size[0] = 1;
                data_1->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_1, b_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (b_0 = 0; b_0 <= loop_ub; b_0++) {
                    data_1->data[b_0] = data->data[b_0];
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
                                b = 0;
                            } else {
                                c = 1;
                                b = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            b_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(b - c);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                b_0);
                            for (b = 0; b <= static_cast<int32_T>(loop_ub - 1);
                                    b++) {
                                curSection->data[b] = curLine->data[static_cast<
                                    int32_T>(c + b)];
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
                    b_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    ImmedMission_emxEnsureCapacity_char_T(ret, b_0);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (b = 0; b <= loop_ub; b++) {
                        ret->data[b] = curVal->data[b];
                    }

                    exitg1 = true;
                }
            }

            ImmedMission_emxFree_char_T(&data_1);
            ImmedMission_emxFree_char_T(&tmp_4);
            ImmedMission_emxFree_char_T(&tmp_3);
        }

        tmp_0 = ImmedMission_str2double(ret);
        c_fid = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV ClimbAngleLimit:\t%f\n", c_fid);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        d_fid = ImmedMission_fileManager(localDW);
        if (d_fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            ImmedMission_fread(d_fid, k, localDW);
            b_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            ImmedMission_emxEnsureCapacity_char_T(data, b_0);
            loop_ub = k->size[0];
            for (b = 0; b <= static_cast<int32_T>(loop_ub - 1); b++) {
                data->data[b] = k->data[b];
            }

            ImmedMission_cfclose(d_fid, localDW);
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
                b_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                ImmedMission_emxEnsureCapacity_char_T(data_0, b_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (b_0 = 0; b_0 <= loop_ub; b_0++) {
                    data_0->data[b_0] = data->data[b_0];
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
                                b = 0;
                            } else {
                                c = 1;
                                b = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            b_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(b - c);
                            curSection->size[1] = loop_ub;
                            ImmedMission_emxEnsureCapacity_char_T(curSection,
                                b_0);
                            for (b = 0; b <= static_cast<int32_T>(loop_ub - 1);
                                    b++) {
                                curSection->data[b] = curLine->data[static_cast<
                                    int32_T>(c + b)];
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
                    b_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    ImmedMission_emxEnsureCapacity_char_T(ret, b_0);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (b = 0; b <= loop_ub; b++) {
                        ret->data[b] = curVal->data[b];
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
        d_fid = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV DiveAngleLimit:\t\t%f\n", d_fid);
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
                (std::isnan(c_fid)) ^ 1))) && (static_cast<boolean_T>(
                static_cast<int32_T>(static_cast<int32_T>(std::isnan(d_fid)) ^ 1))))
        {
            localDW->SingletonInstance.FlightPathAngleLimit[0] = d_fid;
            localDW->SingletonInstance.FlightPathAngleLimit[1] = c_fid;
        }

        ImmedMission_uavDubinsConnection_uavDubinsConnection
            (&localDW->SingletonInstance.DubinsConnector,
             localDW->SingletonInstance.AirSpeed,
             localDW->SingletonInstance.MaxRollAngle);
        localDW->SingletonInstance_not_empty = true;
    }

    outputArg = &localDW->SingletonInstance.DubinsConnector;
    return outputArg;
}

static void ImmedMission_binary_expand_op_pu(boolean_T in1_data[], int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], int32_T in3,
    int32_T in4, DW_ImmedMission_f_T *localDW)
{
    int32_T i_0;
    int32_T in2_size_idx_0;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    int32_T stride_0_0;
    i_0 = static_cast<int32_T>(in4 - in3);
    in2_size_idx_0 = static_cast<int32_T>(i_0 + 2);
    loop_ub_tmp = static_cast<int32_T>(i_0 + 1);
    for (int32_T i{0}; i < 3; i++) {
        for (stride_0_0 = 0; stride_0_0 <= static_cast<int32_T>(loop_ub_tmp - 1);
             stride_0_0++) {
            localDW->in2_data[static_cast<int32_T>(stride_0_0 +
                static_cast<int32_T>(static_cast<int32_T>(i_0 + 2) * i))] =
                in2_data[static_cast<int32_T>(static_cast<int32_T>
                (static_cast<int32_T>(in3 + stride_0_0) + static_cast<int32_T>
                 (in2_size[0] * i)) - 1)];
        }
    }

    localDW->in2_data[static_cast<int32_T>(i_0 + 1)] = (rtNaN);
    localDW->in2_data[static_cast<int32_T>(static_cast<int32_T>(i_0 + i_0) + 3)]
        = (rtNaN);
    localDW->in2_data[static_cast<int32_T>(static_cast<int32_T>(i_0 +
        static_cast<int32_T>(static_cast<int32_T>(i_0 + 2) << 1)) + 1)] = (rtNaN);
    in1_size[0] = static_cast<int32_T>(i_0 + 2) == 1 ? in2_size[0] :
        static_cast<int32_T>(i_0 + 2);
    in1_size[1] = 3;
    stride_0_0 = (in2_size[0] != 1);
    loop_ub_tmp = (static_cast<int32_T>(i_0 + 2) != 1);
    loop_ub = static_cast<int32_T>(i_0 + 2) == 1 ? in2_size[0] :
        static_cast<int32_T>(i_0 + 2);
    for (i_0 = 0; i_0 < 3; i_0++) {
        for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            in1_data[static_cast<int32_T>(i + static_cast<int32_T>(in1_size[0] *
                i_0))] = (in2_data[static_cast<int32_T>(static_cast<int32_T>(i *
                            stride_0_0) + static_cast<int32_T>(in2_size[0] * i_0))]
                          != localDW->in2_data[static_cast<int32_T>(static_cast<
                           int32_T>(i * loop_ub_tmp) + static_cast<int32_T>
                           (in2_size_idx_0 * i_0))]);
        }
    }
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

static void ImmedMission_WaypointFollowerBase_searchClosestPath
    (uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T *obj, const
     real_T waypoints_data[], const int32_T waypoints_size[2], const real_T
     currentPose[4])
{
    emxArray_real_T_ImmedMission_T *d;
    real_T currentPose_0[3];
    real_T lambda;
    real_T tempStartWaypoint;
    int32_T b_idx;
    int32_T b_k;
    int32_T last;
    ImmedMission_emxInit_real_T(&d, 2);
    b_k = static_cast<int32_T>(d->size[0] * d->size[1]);
    d->size[0] = 1;
    d->size[1] = static_cast<int32_T>(obj->NumWaypoints - 1.0);
    ImmedMission_emxEnsureCapacity_real_T(d, b_k);
    last = static_cast<int32_T>(static_cast<int32_T>(obj->NumWaypoints - 1.0) -
        1);
    for (b_k = 0; b_k <= last; b_k++) {
        real_T lambda_tmp;
        real_T lambda_tmp_tmp;
        real_T lambda_tmp_tmp_0;
        real_T lambda_tmp_tmp_1;
        real_T tempEndWaypoint;
        real_T tempEndWaypoint_idx_0;
        real_T tempEndWaypoint_idx_1;
        real_T tempStartWaypoint_idx_0;
        real_T tempStartWaypoint_idx_1;
        d->data[b_k] = 0.0;
        tempStartWaypoint = waypoints_data[b_k];
        tempEndWaypoint = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>((static_cast<real_T>(b_k) + 1.0) + 1.0) - 1)];
        lambda_tmp_tmp = tempEndWaypoint - tempStartWaypoint;
        lambda = (currentPose[0] - tempStartWaypoint) * lambda_tmp_tmp;
        tempStartWaypoint_idx_0 = tempStartWaypoint;
        tempEndWaypoint_idx_0 = tempEndWaypoint;
        tempStartWaypoint = waypoints_data[static_cast<int32_T>(b_k +
            waypoints_size[0])];
        tempEndWaypoint = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>((static_cast<real_T>(b_k)
                + 1.0) + 1.0) + waypoints_size[0]) - 1)];
        lambda_tmp_tmp_0 = tempEndWaypoint - tempStartWaypoint;
        lambda += (currentPose[1] - tempStartWaypoint) * lambda_tmp_tmp_0;
        tempStartWaypoint_idx_1 = tempStartWaypoint;
        tempEndWaypoint_idx_1 = tempEndWaypoint;
        tempStartWaypoint = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(waypoints_size[0] << 1) + b_k)];
        tempEndWaypoint = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>((static_cast<real_T>(b_k)
                + 1.0) + 1.0) + static_cast<int32_T>(waypoints_size[0] << 1)) -
             1)];
        lambda_tmp_tmp_1 = tempEndWaypoint - tempStartWaypoint;
        lambda_tmp = currentPose[2] - tempStartWaypoint;
        lambda = (lambda_tmp * lambda_tmp_tmp_1 + lambda) / ((lambda_tmp_tmp_0 *
            lambda_tmp_tmp_0 + lambda_tmp_tmp * lambda_tmp_tmp) +
            lambda_tmp_tmp_1 * lambda_tmp_tmp_1);
        if (lambda < 0.0) {
            currentPose_0[0] = currentPose[0] - tempStartWaypoint_idx_0;
            currentPose_0[1] = currentPose[1] - tempStartWaypoint_idx_1;
            currentPose_0[2] = lambda_tmp;
            d->data[b_k] = ImmedMission_norm_pv(currentPose_0);
        } else if (lambda > 1.0) {
            currentPose_0[0] = currentPose[0] - tempEndWaypoint_idx_0;
            currentPose_0[1] = currentPose[1] - tempEndWaypoint_idx_1;
            currentPose_0[2] = currentPose[2] - tempEndWaypoint;
            d->data[b_k] = ImmedMission_norm_pv(currentPose_0);
        } else {
            currentPose_0[0] = currentPose[0] - (lambda * lambda_tmp_tmp +
                tempStartWaypoint_idx_0);
            currentPose_0[1] = currentPose[1] - (lambda * lambda_tmp_tmp_0 +
                tempStartWaypoint_idx_1);
            currentPose_0[2] = currentPose[2] - (lambda * lambda_tmp_tmp_1 +
                tempStartWaypoint);
            d->data[b_k] = ImmedMission_norm_pv(currentPose_0);
        }
    }

    last = d->size[1];
    if (d->size[1] <= 2) {
        if (d->size[1] == 1) {
            b_idx = 1;
        } else if ((d->data[0] > d->data[static_cast<int32_T>(d->size[1] - 1)]) ||
                   (std::isnan(d->data[0]) && (static_cast<boolean_T>(
                      static_cast<int32_T>(static_cast<int32_T>(std::isnan
                        (d->data[static_cast<int32_T>(d->size[1] - 1)])) ^ 1)))))
        {
            b_idx = d->size[1];
        } else {
            b_idx = 1;
        }
    } else {
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(d->data[0])) ^ 1))) {
            b_idx = 1;
        } else {
            boolean_T exitg1;
            b_idx = 0;
            b_k = 2;
            exitg1 = false;
            while ((!exitg1) && (b_k <= last)) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (d->data[static_cast<int32_T>(b_k - 1)])) ^ 1))) {
                    b_idx = b_k;
                    exitg1 = true;
                } else {
                    b_k = static_cast<int32_T>(b_k + 1);
                }
            }
        }

        if (b_idx == 0) {
            b_idx = 1;
        } else {
            int32_T b;
            lambda = d->data[static_cast<int32_T>(b_idx - 1)];
            b = b_idx;
            for (b_k = static_cast<int32_T>(b + 1); b_k <= last; b_k++) {
                tempStartWaypoint = d->data[static_cast<int32_T>(b_k - 1)];
                if (lambda > tempStartWaypoint) {
                    lambda = tempStartWaypoint;
                    b_idx = b_k;
                }
            }
        }
    }

    ImmedMission_emxFree_real_T(&d);
    obj->WaypointIndex = static_cast<real_T>(b_idx);
    obj->SearchFlag = false;
}

static void ImmedMission_WaypointFollower_stepImpl
    (uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T *obj, const
     real_T currentPose[4], const real_T waypoints_data[], const int32_T
     waypoints_size[2], real_T lookaheadDistance, real_T varargout_1[3], real_T *
     varargout_2, real_T *varargout_3, uint8_T *varargout_4, uint8_T
     *varargout_5, DW_ImmedMission_f_T *localDW)
{
    real_T lambda_tmp[3];
    real_T waypointsIn[3];
    real_T lambda;
    int32_T waypointsIn_size[2];
    int32_T x_size[2];
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T c;
    int32_T i1;
    int32_T i2;
    int32_T vstride;
    int16_T j_data[901];
    int8_T waypointsIn_0[2];
    boolean_T x_data[2703];
    boolean_T i_data[901];
    boolean_T exitg1;
    boolean_T p;
    boolean_T p_0;
    lambda = lookaheadDistance;
    obj->LookaheadDistFlag = 0U;
    if (lookaheadDistance < 10.0) {
        lambda = 10.0;
        obj->LookaheadDistFlag = 1U;
    }

    *varargout_4 = obj->LookaheadDistFlag;
    obj->InitialPose[0] = 0.0;
    obj->InitialPose[1] = 0.0;
    obj->InitialPose[2] = 0.0;
    obj->InitialPose[3] = 0.0;
    for (i1 = 0; i1 < 2700; i1++) {
        localDW->paddedWaypts_m[i1] = (rtNaN);
    }

    vstride = waypoints_size[1];
    for (i1 = 0; i1 <= static_cast<int32_T>(vstride - 1); i1++) {
        i2 = waypoints_size[0];
        for (c = 0; c <= static_cast<int32_T>(i2 - 1); c++) {
            localDW->paddedWaypts_m[static_cast<int32_T>(c + static_cast<int32_T>
                (900 * i1))] = waypoints_data[static_cast<int32_T>
                (static_cast<int32_T>(waypoints_size[0] * i1) + c)];
        }
    }

    p = false;
    p_0 = true;
    c = 0;
    exitg1 = false;
    while ((!exitg1) && (c < 2700)) {
        if ((obj->WaypointsInternal[c] == localDW->paddedWaypts_m[c]) || (std::
                isnan(obj->WaypointsInternal[c]) && std::isnan
                (localDW->paddedWaypts_m[c]))) {
            c = static_cast<int32_T>(c + 1);
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
        std::memcpy(&obj->WaypointsInternal[0], &localDW->paddedWaypts_m[0],
                    static_cast<uint32_T>(2700U * sizeof(real_T)));
        obj->WaypointIndex = 1.0;
        obj->SearchFlag = true;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((waypoints_size[0] == 0) |
            (waypoints_size[1] == 0)))) {
        waypointsIn_size[0] = 0;
        waypointsIn_size[1] = 0;
    } else {
        int32_T loop_ub_tmp;
        if (waypoints_size[0] < 2) {
            vstride = 0;
            c = -1;
        } else {
            vstride = 1;
            c = static_cast<int32_T>(waypoints_size[0] - 1);
        }

        i1 = static_cast<int32_T>(c - vstride);
        if (static_cast<int32_T>(i1 + 2) == waypoints_size[0]) {
            int32_T waypoints_size_idx_0;
            waypoints_size_idx_0 = static_cast<int32_T>(i1 + 2);
            loop_ub_tmp = static_cast<int32_T>(i1 + 1);
            for (c = 0; c < 3; c++) {
                for (i2 = 0; i2 <= static_cast<int32_T>(loop_ub_tmp - 1); i2++)
                {
                    localDW->waypoints_data[static_cast<int32_T>(i2 +
                        static_cast<int32_T>(static_cast<int32_T>(i1 + 2) * c))]
                        = waypoints_data[static_cast<int32_T>
                        (static_cast<int32_T>(vstride + i2) +
                         static_cast<int32_T>(waypoints_size[0] * c))];
                }
            }

            localDW->waypoints_data[static_cast<int32_T>(i1 + 1)] = (rtNaN);
            localDW->waypoints_data[static_cast<int32_T>(static_cast<int32_T>(i1
                + i1) + 3)] = (rtNaN);
            localDW->waypoints_data[static_cast<int32_T>(static_cast<int32_T>(i1
                + static_cast<int32_T>(static_cast<int32_T>(i1 + 2) << 1)) + 1)]
                = (rtNaN);
            vstride = waypoints_size[0];
            x_size[0] = waypoints_size[0];
            for (i1 = 0; i1 < 3; i1++) {
                for (c = 0; c <= static_cast<int32_T>(vstride - 1); c++) {
                    x_data[static_cast<int32_T>(c + static_cast<int32_T>(x_size
                        [0] * i1))] = (waypoints_data[static_cast<int32_T>(
                                        static_cast<int32_T>(waypoints_size[0] *
                                         i1) + c)] != localDW->waypoints_data[
                                       static_cast<int32_T>(static_cast<int32_T>
                                        (waypoints_size_idx_0 * i1) + c)]);
                }
            }
        } else {
            ImmedMission_binary_expand_op_pu(x_data, x_size, waypoints_data,
                waypoints_size, static_cast<int32_T>(vstride + 1),
                static_cast<int32_T>(c + 1), localDW);
        }

        vstride = x_size[0];
        for (i1 = 0; i1 <= static_cast<int32_T>(vstride - 1); i1++) {
            i_data[i1] = false;
        }

        vstride = x_size[0];
        i1 = 0;
        i2 = static_cast<int32_T>(x_size[0] << 1);
        for (c = 0; c <= static_cast<int32_T>(vstride - 1); c++) {
            i1 = static_cast<int32_T>(i1 + 1);
            i2 = static_cast<int32_T>(i2 + 1);
            loop_ub_tmp = i1;
            exitg1 = false;
            while ((!exitg1) && (static_cast<boolean_T>(static_cast<int32_T>
                     ((vstride > 0) & (loop_ub_tmp <= i2))))) {
                if (x_data[static_cast<int32_T>(loop_ub_tmp - 1)]) {
                    i_data[c] = true;
                    exitg1 = true;
                } else {
                    loop_ub_tmp = static_cast<int32_T>(loop_ub_tmp + vstride);
                }
            }
        }

        c = static_cast<int32_T>(x_size[0] - 1);
        i1 = 0;
        for (vstride = 0; vstride <= c; vstride++) {
            if (i_data[vstride]) {
                i1 = static_cast<int32_T>(i1 + 1);
            }
        }

        i2 = i1;
        i1 = 0;
        for (vstride = 0; vstride <= c; vstride++) {
            if (i_data[vstride]) {
                j_data[i1] = static_cast<int16_T>(static_cast<int32_T>(vstride +
                    1));
                i1 = static_cast<int32_T>(i1 + 1);
            }
        }

        vstride = waypoints_size[1];
        waypointsIn_size[0] = i2;
        waypointsIn_size[1] = waypoints_size[1];
        for (i1 = 0; i1 <= static_cast<int32_T>(vstride - 1); i1++) {
            for (c = 0; c <= static_cast<int32_T>(i2 - 1); c++) {
                localDW->waypoints_data[static_cast<int32_T>(c +
                    static_cast<int32_T>(i2 * i1))] = waypoints_data[
                    static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(waypoints_size[0] * i1) +
                     static_cast<int32_T>(j_data[c])) - 1)];
            }
        }
    }

    obj->NumWaypoints = static_cast<real_T>(waypointsIn_size[0]);
    obj->LookaheadDistance = lambda;
    if (static_cast<boolean_T>(static_cast<int32_T>((waypointsIn_size[0] == 0) |
          (waypointsIn_size[1] == 0)))) {
        varargout_1[0] = lambda * std::cos(currentPose[3]) + currentPose[0];
        varargout_1[1] = lambda * std::sin(currentPose[3]) + currentPose[1];
        varargout_1[2] = lambda * 0.0 + currentPose[2];
        *varargout_2 = currentPose[3];
        *varargout_3 = currentPose[3];
        *varargout_5 = 1U;
    } else {
        boolean_T guard1{ false };

        guard1 = false;
        if (waypointsIn_size[0] == 1) {
            if (obj->StartFlag) {
                obj->InitialPose[0] = currentPose[0];
                obj->InitialPose[1] = currentPose[1];
                obj->InitialPose[2] = currentPose[2];
                obj->InitialPose[3] = currentPose[3];
            }

            waypointsIn[0] = localDW->waypoints_data[0] - currentPose[0];
            waypointsIn[1] = localDW->waypoints_data[1] - currentPose[1];
            waypointsIn[2] = localDW->waypoints_data[2] - currentPose[2];
            if (ImmedMission_norm_pv(waypointsIn) < 1.4901161193847656E-8) {
                varargout_1[0] = lambda * std::cos(currentPose[3]) +
                    currentPose[0];
                varargout_1[1] = lambda * std::sin(currentPose[3]) +
                    currentPose[1];
                varargout_1[2] = lambda * 0.0 + currentPose[2];
                *varargout_2 = currentPose[3];
                *varargout_3 = currentPose[3];
                *varargout_5 = 1U;
                obj->StartFlag = false;
            } else {
                obj->StartFlag = false;
                obj->NumWaypoints = 2.0;
                waypointsIn_0[0] = 1;
                waypointsIn_0[1] = 3;
                for (i1 = 0; i1 < 3; i1++) {
                    localDW->virtualWaypoint_data[static_cast<int32_T>(i1 << 1)]
                        = obj->InitialPose[i1];
                    localDW->virtualWaypoint_data[static_cast<int32_T>(1 +
                        static_cast<int32_T>(i1 << 1))] =
                        localDW->waypoints_data[static_cast<int32_T>(
                        static_cast<int32_T>(waypointsIn_0[0]) * i1)];
                }

                waypointsIn_size[0] = 2;
                waypointsIn_size[1] = 3;
                for (i1 = 0; i1 < 6; i1++) {
                    localDW->waypoints_data[i1] = localDW->
                        virtualWaypoint_data[i1];
                }

                guard1 = true;
            }
        } else {
            guard1 = true;
        }

        if (guard1) {
            real_T b;
            real_T b_tmp_idx_2_tmp;
            real_T currentPose_tmp;
            real_T lambda_tmp_0;
            real_T varargout_1_tmp_tmp;
            real_T varargout_1_tmp_tmp_0;
            real_T varargout_1_tmp_tmp_1;
            real_T virtualWaypoint_idx_0;
            real_T virtualWaypoint_idx_1;
            real_T virtualWaypoint_idx_2;
            boolean_T guard2{ false };

            if (obj->SearchFlag) {
                ImmedMission_WaypointFollowerBase_searchClosestPath(obj,
                    localDW->waypoints_data, waypointsIn_size, currentPose);
            }

            p = false;
            if (obj->WaypointIndex == obj->NumWaypoints) {
                p = true;
            }

            if (p) {
                obj->LastWaypointFlag = true;
                obj->WaypointIndex--;
            }

            virtualWaypoint_idx_0 = localDW->waypoints_data[static_cast<int32_T>
                (static_cast<int32_T>(obj->WaypointIndex) - 1)];
            varargout_1_tmp_tmp = localDW->waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(obj->WaypointIndex + 1.0) - 1)];
            lambda_tmp[0] = currentPose[0] - varargout_1_tmp_tmp;
            varargout_1[0] = varargout_1_tmp_tmp;
            virtualWaypoint_idx_1 = localDW->waypoints_data[static_cast<int32_T>
                (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
                  waypointsIn_size[0]) - 1)];
            varargout_1_tmp_tmp_0 = localDW->waypoints_data[static_cast<int32_T>
                (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex +
                   1.0) + waypointsIn_size[0]) - 1)];
            lambda_tmp[1] = currentPose[1] - varargout_1_tmp_tmp_0;
            varargout_1[1] = varargout_1_tmp_tmp_0;
            virtualWaypoint_idx_2 = localDW->waypoints_data[static_cast<int32_T>
                (static_cast<int32_T>(static_cast<int32_T>(waypointsIn_size[0] <<
                   1) + static_cast<int32_T>(obj->WaypointIndex)) - 1)];
            varargout_1_tmp_tmp_1 = localDW->waypoints_data[static_cast<int32_T>
                (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex +
                   1.0) + static_cast<int32_T>(waypointsIn_size[0] << 1)) - 1)];
            lambda_tmp[2] = currentPose[2] - varargout_1_tmp_tmp_1;
            varargout_1[2] = varargout_1_tmp_tmp_1;
            lambda = ImmedMission_norm_pv(lambda_tmp);
            guard2 = false;
            if (lambda <= 100.0) {
                guard2 = true;
            } else {
                varargout_1_tmp_tmp -= virtualWaypoint_idx_0;
                waypointsIn[0] = varargout_1_tmp_tmp;
                varargout_1_tmp_tmp_0 -= virtualWaypoint_idx_1;
                waypointsIn[1] = varargout_1_tmp_tmp_0;
                varargout_1_tmp_tmp_1 -= virtualWaypoint_idx_2;
                waypointsIn[2] = varargout_1_tmp_tmp_1;
                b = ImmedMission_norm_pv(waypointsIn);
                lambda = (varargout_1_tmp_tmp / b * (lambda_tmp[0] / lambda) +
                          varargout_1_tmp_tmp_0 / b * (lambda_tmp[1] / lambda))
                    + varargout_1_tmp_tmp_1 / b * (lambda_tmp[2] / lambda);
                if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                        int32_T>(std::isnan(lambda)) ^ 1))) {
                    if (lambda < 0.0) {
                        lambda = -1.0;
                    } else {
                        lambda = static_cast<real_T>(lambda > 0.0);
                    }
                }

                if (lambda >= 0.0) {
                    guard2 = true;
                }
            }

            if (guard2) {
                obj->WaypointIndex++;
                p = false;
                if (obj->WaypointIndex == obj->NumWaypoints) {
                    p = true;
                }

                if (p) {
                    obj->LastWaypointFlag = true;
                    obj->WaypointIndex--;
                }

                virtualWaypoint_idx_0 = localDW->waypoints_data[static_cast<
                    int32_T>(static_cast<int32_T>(obj->WaypointIndex) - 1)];
                varargout_1[0] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(obj->WaypointIndex + 1.0) - 1)];
                virtualWaypoint_idx_1 = localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(obj->WaypointIndex) +
                     waypointsIn_size[0]) - 1)];
                varargout_1[1] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + waypointsIn_size[0]) - 1)];
                virtualWaypoint_idx_2 = localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(waypointsIn_size[0] << 1) +
                     static_cast<int32_T>(obj->WaypointIndex)) - 1)];
                varargout_1[2] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + static_cast<int32_T>(waypointsIn_size[0] << 1)) - 1)];
            }

            varargout_1_tmp_tmp = varargout_1[0] - virtualWaypoint_idx_0;
            b = currentPose[0] - virtualWaypoint_idx_0;
            varargout_1_tmp_tmp_0 = varargout_1[1] - virtualWaypoint_idx_1;
            currentPose_tmp = currentPose[1] - virtualWaypoint_idx_1;
            varargout_1_tmp_tmp_1 = varargout_1[2] - virtualWaypoint_idx_2;
            lambda_tmp_0 = currentPose[2] - virtualWaypoint_idx_2;
            lambda = ((currentPose_tmp * varargout_1_tmp_tmp_0 + b *
                       varargout_1_tmp_tmp) + lambda_tmp_0 *
                      varargout_1_tmp_tmp_1) / ((varargout_1_tmp_tmp_0 *
                varargout_1_tmp_tmp_0 + varargout_1_tmp_tmp *
                varargout_1_tmp_tmp) + varargout_1_tmp_tmp_1 *
                varargout_1_tmp_tmp_1);
            if (lambda < 0.0) {
                lambda_tmp[0] = b;
                lambda_tmp[1] = currentPose_tmp;
                lambda_tmp[2] = lambda_tmp_0;
                lambda = ImmedMission_norm_pv(lambda_tmp);
            } else if (lambda > 1.0) {
                lambda_tmp[0] = currentPose[0] - varargout_1[0];
                lambda_tmp[1] = currentPose[1] - varargout_1[1];
                lambda_tmp[2] = currentPose[2] - varargout_1[2];
                lambda = ImmedMission_norm_pv(lambda_tmp);
            } else {
                lambda_tmp[0] = currentPose[0] - (lambda * varargout_1_tmp_tmp +
                    virtualWaypoint_idx_0);
                lambda_tmp[1] = currentPose[1] - (lambda * varargout_1_tmp_tmp_0
                    + virtualWaypoint_idx_1);
                lambda_tmp[2] = currentPose[2] - (lambda * varargout_1_tmp_tmp_1
                    + virtualWaypoint_idx_2);
                lambda = ImmedMission_norm_pv(lambda_tmp);
            }

            if (obj->LastWaypointFlag) {
                lambda = (((currentPose[0] - virtualWaypoint_idx_0) *
                           (varargout_1[0] - virtualWaypoint_idx_0) +
                           (currentPose[1] - virtualWaypoint_idx_1) *
                           (varargout_1[1] - virtualWaypoint_idx_1)) +
                          (currentPose[2] - virtualWaypoint_idx_2) *
                          (varargout_1[2] - virtualWaypoint_idx_2)) /
                    (((varargout_1[0] - virtualWaypoint_idx_0) * (varargout_1[0]
                       - virtualWaypoint_idx_0) + (varargout_1[1] -
                       virtualWaypoint_idx_1) * (varargout_1[1] -
                       virtualWaypoint_idx_1)) + (varargout_1[2] -
                      virtualWaypoint_idx_2) * (varargout_1[2] -
                      virtualWaypoint_idx_2));
                lambda_tmp[0] = currentPose[0] - (lambda * varargout_1_tmp_tmp +
                    virtualWaypoint_idx_0);
                lambda_tmp[1] = currentPose[1] - (lambda * varargout_1_tmp_tmp_0
                    + virtualWaypoint_idx_1);
                lambda_tmp[2] = currentPose[2] - (lambda * varargout_1_tmp_tmp_1
                    + virtualWaypoint_idx_2);
                lambda = ImmedMission_norm_pv(lambda_tmp);
            }

            currentPose_tmp = std::abs(lambda);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isinf(currentPose_tmp)) ^ 1))) &
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(std::isnan
                      (currentPose_tmp)) ^ 1)))))) {
                if (currentPose_tmp <= 2.2250738585072014E-308) {
                    b = 4.94065645841247E-324;
                    currentPose_tmp = 4.94065645841247E-324;
                } else {
                    frexp(currentPose_tmp, &b_exponent);
                    b = std::ldexp(1.0, static_cast<int32_T>(b_exponent - 53));
                    frexp(currentPose_tmp, &b_exponent_0);
                    currentPose_tmp = std::ldexp(1.0, static_cast<int32_T>
                        (b_exponent_0 - 53));
                }
            } else {
                b = (rtNaN);
                currentPose_tmp = (rtNaN);
            }

            if (obj->LookaheadDistance <= std::fmax(std::sqrt(b), 5.0 *
                    currentPose_tmp) + lambda) {
                obj->LookaheadDistance = obj->LookaheadFactor * lambda;
            }

            lambda = ((varargout_1[0] - virtualWaypoint_idx_0) * (varargout_1[0]
                       - virtualWaypoint_idx_0) + (varargout_1[1] -
                       virtualWaypoint_idx_1) * (varargout_1[1] -
                       virtualWaypoint_idx_1)) + (varargout_1[2] -
                virtualWaypoint_idx_2) * (varargout_1[2] - virtualWaypoint_idx_2);
            currentPose_tmp = virtualWaypoint_idx_0 - currentPose[0];
            lambda_tmp_0 = virtualWaypoint_idx_1 - currentPose[1];
            b_tmp_idx_2_tmp = virtualWaypoint_idx_2 - currentPose[2];
            b = ((varargout_1_tmp_tmp * currentPose_tmp + varargout_1_tmp_tmp_0 *
                  lambda_tmp_0) + varargout_1_tmp_tmp_1 * b_tmp_idx_2_tmp) * 2.0;
            currentPose_tmp = std::sqrt(b * b - (((currentPose_tmp *
                currentPose_tmp + lambda_tmp_0 * lambda_tmp_0) + b_tmp_idx_2_tmp
                * b_tmp_idx_2_tmp) - obj->LookaheadDistance *
                obj->LookaheadDistance) * (4.0 * lambda));
            lambda = std::fmax((-b + currentPose_tmp) / 2.0 / lambda, (-b -
                                currentPose_tmp) / 2.0 / lambda);
            varargout_1_tmp_tmp = (1.0 - lambda) * virtualWaypoint_idx_0 +
                lambda * varargout_1[0];
            varargout_1[0] = varargout_1_tmp_tmp;
            varargout_1_tmp_tmp_0 = (1.0 - lambda) * virtualWaypoint_idx_1 +
                lambda * varargout_1[1];
            varargout_1[1] = varargout_1_tmp_tmp_0;
            varargout_1[2] = (1.0 - lambda) * virtualWaypoint_idx_2 + lambda *
                varargout_1[2];
            *varargout_2 = rt_atan2d_snf(varargout_1_tmp_tmp_0 - currentPose[1],
                varargout_1_tmp_tmp - currentPose[0]);
            *varargout_3 = *varargout_2;
            *varargout_5 = 0U;
            p = false;
            if (obj->LastWaypointFlag) {
                p = true;
            }

            if (p) {
                *varargout_5 = 1U;
            }

            obj->LastWaypointFlag = false;
        }
    }
}

static void ImmedMission_binary_expand_op_puh(boolean_T in1_data[], int32_T
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
            ImmedMission_binary_expand_op_puh(localDW->x_data, x_size, waypoints,
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

// Function for MATLAB Function: '<S135>/BaseWayPoint'
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
    //   ActionPort: '<S9>/Action Port'

    // Outputs for Triggered SubSystem: '<S129>/WayPointGen' incorporates:
    //   TriggerPort: '<S135>/Trigger'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   MATLAB Function: '<S135>/BaseWayPoint'

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
    // End of Outputs for SubSystem: '<S129>/WayPointGen'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
    ImmedMission_emxFree_real_T(&in1_0);
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
    //   ActionPort: '<S9>/Action Port'

    // Outputs for Triggered SubSystem: '<S129>/WayPointGen' incorporates:
    //   TriggerPort: '<S135>/Trigger'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   MATLAB Function: '<S135>/BaseWayPoint'

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
    // End of Outputs for SubSystem: '<S129>/WayPointGen'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
    ImmedMission_emxFree_real_T(&in2_0);
}

// System initialize for referenced model: 'ImmedMission'
void ImmedMission_Init(boolean_T rty_ControlSwitch[2], FixedWingGuidanceBus
                       *rty_GuidanceCMD, DW_ImmedMission_f_T *localDW,
                       ZCE_ImmedMission_T *localZCE)
{
    FILE* a;
    real_T Omega;
    int32_T i;

    // Start for SwitchCase: '<S1>/Switch Case'
    localDW->SwitchCase_ActiveSubsystem = -1;

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode128_DetailedInsp'
    // Start for MATLABSystem: '<S35>/Orbit Follower'
    localDW->objisempty_e = true;
    localDW->obj_c.isInitialized = 1;
    localDW->obj_c.PrevResetSignal = 0.0;
    localDW->obj_c.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S35>/Orbit Follower'
    localDW->obj_c.OrbitRadiusInternal = (rtNaN);
    localDW->obj_c.PrevResetSignal *= 0.0;
    localDW->obj_c.NumCircles *= 0.0;

    // Start for MATLABSystem: '<S35>/Orbit Follower'
    localDW->obj_c.PrevPosition[0] = 0.0;

    // InitializeConditions for MATLABSystem: '<S35>/Orbit Follower'
    localDW->obj_c.OrbitCenterInternal[0] = (rtNaN);
    localDW->obj_c.PrevPosition[0] *= 0.0;

    // Start for MATLABSystem: '<S35>/Orbit Follower'
    localDW->obj_c.PrevPosition[1] = 0.0;

    // InitializeConditions for MATLABSystem: '<S35>/Orbit Follower'
    localDW->obj_c.OrbitCenterInternal[1] = (rtNaN);
    localDW->obj_c.PrevPosition[1] *= 0.0;

    // Start for MATLABSystem: '<S35>/Orbit Follower'
    localDW->obj_c.PrevPosition[2] = 0.0;

    // InitializeConditions for MATLABSystem: '<S35>/Orbit Follower'
    localDW->obj_c.OrbitCenterInternal[2] = (rtNaN);
    localDW->obj_c.PrevPosition[2] *= 0.0;
    localDW->obj_c.StartFlag = true;
    localDW->obj_c.SelectTurnDirectionFlag = true;
    localDW->obj_c.TurnDirectionInternal = 1.0;
    localDW->obj_c.OrbitRadiusFlag = 0U;
    localDW->obj_c.LookaheadDistFlag = 0U;

    // End of SystemInitialize for SubSystem: '<S1>/Mode128_DetailedInsp'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode129_CollAvoidance'
    // SystemInitialize for Atomic SubSystem: '<S65>/HeadingControl'
    // Start for MATLABSystem: '<S68>/TrackSimPath'
    localDW->obj_j.LastWaypointFlag = false;
    localDW->obj_j.StartFlag = true;
    localDW->obj_j.LookaheadFactor = 1.01;
    localDW->obj_j.SearchFlag = true;
    localDW->obj_j.CacheInputSizes = false;
    localDW->objisempty_k = true;
    localDW->obj_j.isInitialized = 1;
    for (i = 0; i < 8; i++) {
        localDW->obj_j.inputVarSize[0].f1[i] = 1U;
    }

    i = localDW->SFunction_DIMS2_j[0];
    if (localDW->SFunction_DIMS2_j[0] < 0) {
        i = 0;
    }

    localDW->obj_j.inputVarSize[1].f1[0] = static_cast<uint32_T>(i);
    i = localDW->SFunction_DIMS2_j[1];
    if (localDW->SFunction_DIMS2_j[1] < 0) {
        i = 0;
    }

    localDW->obj_j.inputVarSize[1].f1[1] = static_cast<uint32_T>(i);
    for (i = 0; i < 6; i++) {
        localDW->obj_j.inputVarSize[1].f1[static_cast<int32_T>(i + 2)] = 1U;
    }

    for (i = 0; i < 8; i++) {
        localDW->obj_j.inputVarSize[2].f1[i] = 1U;
    }

    // End of Start for MATLABSystem: '<S68>/TrackSimPath'

    // InitializeConditions for MATLABSystem: '<S68>/TrackSimPath'
    localDW->obj_j.WaypointIndex = 1.0;
    for (i = 0; i < 2700; i++) {
        // InitializeConditions for MATLABSystem: '<S68>/TrackSimPath'
        localDW->obj_j.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S65>/HeadingControl'
    // End of SystemInitialize for SubSystem: '<S1>/Mode129_CollAvoidance'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode131_SqCalibr'
    // SystemInitialize for Triggered SubSystem: '<S129>/WayPointGen'
    // SystemInitialize for MATLAB Function: '<S135>/BaseWayPoint'
    a = NULL;
    for (i = 0; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S135>/BaseWayPoint'

    // Start for MATLABSystem: '<S135>/RotateATMissionHdg'
    localDW->objisempty_o = true;
    localDW->obj_n.isInitialized = 1;
    localZCE->WayPointGen_Trig_ZCE_d = NEG_ZCSIG;

    // End of SystemInitialize for SubSystem: '<S129>/WayPointGen'

    // Start for MATLABSystem: '<S129>/Waypoint Follower'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.CacheInputSizes = false;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
        localDW->obj.inputVarSize[0].f1[i] = 1U;
    }

    localDW->obj.inputVarSize[1].f1[0] = 0U;
    localDW->obj.inputVarSize[1].f1[1] = 0U;
    for (i = 0; i < 6; i++) {
        localDW->obj.inputVarSize[1].f1[static_cast<int32_T>(i + 2)] = 1U;
    }

    for (i = 0; i < 8; i++) {
        localDW->obj.inputVarSize[2].f1[i] = 1U;
    }

    // End of Start for MATLABSystem: '<S129>/Waypoint Follower'

    // InitializeConditions for MATLABSystem: '<S129>/Waypoint Follower'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 30723; i++) {
        // InitializeConditions for MATLABSystem: '<S129>/Waypoint Follower'
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S1>/Mode131_SqCalibr'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode132_pAttack'
    // SystemInitialize for Triggered SubSystem: '<S183>/WayPointGen'
    localZCE->WayPointGen_Trig_ZCE = NEG_ZCSIG;

    // End of SystemInitialize for SubSystem: '<S183>/WayPointGen'

    // Constant: '<S183>/Constant'
    ImmedMission_Altitude_Init(&localDW->Altitude);
    ImmedMission_Altitude_Init(&localDW->Heading);

    // End of SystemInitialize for SubSystem: '<S1>/Mode132_pAttack'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU'
    ImmedMission_CoordinateTransformationConversion_Init
        (&localDW->CoordinateTransformationConversion);

    // End of SystemInitialize for SubSystem: '<S1>/Mode254_ShiftEarthENU'

    // SystemInitialize for IfAction SubSystem: '<S1>/Mode253_ShiftBodyXYZ'
    // SystemInitialize for Enabled SubSystem: '<S210>/DivisionByZeroProtection' 
    ImmedMission_DivisionByZeroProtection_Init(&localDW->Omega_g);

    // End of SystemInitialize for SubSystem: '<S210>/DivisionByZeroProtection'
    ImmedMission_CoordinateTransformationConversion_Init
        (&localDW->CoordinateTransformationConversion_j);

    // End of SystemInitialize for SubSystem: '<S1>/Mode253_ShiftBodyXYZ'

    // SystemInitialize for IfAction SubSystem: '<S1>/AvoidInterPlaneCollision'
    // SystemInitialize for Iterator SubSystem: '<S14>/For Each Subsystem'
    for (i = 0; i < 128; i++) {
        // SystemInitialize for Enabled SubSystem: '<S18>/NoPredNaN'
        // SystemInitialize for Enabled SubSystem: '<S28>/DivisionByZeroProtection' 
        ImmedMission_DivisionByZeroProtection_Init(&localDW->CoreSubsys_d[i].
            Omega);

        // End of SystemInitialize for SubSystem: '<S28>/DivisionByZeroProtection' 
        // End of SystemInitialize for SubSystem: '<S18>/NoPredNaN'
    }

    // End of SystemInitialize for SubSystem: '<S14>/For Each Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S17>/DivisionByZeroProtection'
    ImmedMission_DivisionByZeroProtection_Init(&Omega);

    // End of SystemInitialize for SubSystem: '<S17>/DivisionByZeroProtection'
    // End of SystemInitialize for SubSystem: '<S1>/AvoidInterPlaneCollision'

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
    // Disable for Atomic SubSystem: '<S217>/SailDistance'
    // Disable for Enabled SubSystem: '<S219>/SailShift'
    // Disable for SwitchCase: '<S1>/Switch Case'
    localDW->SailShift_MODE = static_cast<boolean_T>(static_cast<int32_T>((
        static_cast<int32_T>(localDW->SwitchCase_ActiveSubsystem) != 5) &
        static_cast<int32_T>(localDW->SailShift_MODE)));

    // End of Disable for SubSystem: '<S219>/SailShift'
    // End of Disable for SubSystem: '<S217>/SailDistance'
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
                  *rtu_FlightMission_FormationPos, const RealUAVStateBus
                  rtu_OtherUAVstate[128], const MissionModes *rtu_FlightMode,
                  real_T *rty_TaskStatus, FixedWingGuidanceStateBus
                  *rty_FinalSimUAVState, boolean_T rty_ControlSwitch[2],
                  FixedWingGuidanceBus *rty_GuidanceCMD, DW_ImmedMission_f_T
                  *localDW, ZCE_ImmedMission_T *localZCE)
{
    // local block i/o variables
    real_T rtb_CentripetalAcc_p;
    real_T rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[3];
    real_T rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e
        [3];
    real_T rtb_TmpSignalConversionAtAltitudeInport1[4];
    real_T rtb_sqrt;
    real_T rtb_MinusVecCenter2UAV[3];
    real_T rtb_ProjVec[3];
    real_T rtb_PerpVec[3];
    real_T rtb_SelectIn[3];
    real_T rtb_SelectOut[3];
    real_T rtb_q0;
    real_T rtb_q1;
    real_T rtb_q2;
    real_T rtb_q3;
    real_T rtb_Product1_l;
    real_T rtb_Sqrt;
    real_T rtb_U;
    real_T rtb_ProductN;
    real_T rtb_ProductE;
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
    emxArray_real_T_ImmedMission_T *tmp_1;
    emxArray_real_T_ImmedMission_T *waypointsIn;
    emxArray_real_T_ImmedMission_T *y;
    real_T rtb_ImpAsg_InsertedFor_StatePred_at_inport_0[384];
    real_T WPQ1_tmp[91];
    real_T rtb_Switch_gs_0[9];
    real_T rtb_VectorConcatenate_a[9];
    real_T rtb_Switch_o[7];
    real_T rtb_Asin[6];
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport1[4];
    real_T rtb_Sum_o[3];
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport2[3];
    real_T rtb_VectorConcatenate[3];
    real_T turnVector[3];
    real_T distToCenter_tmp[2];
    real_T rtb_Sum1[2];
    real_T rtb_TmpSignalConversionAtOrbitF[2];
    real_T xyCenter[2];
    real_T rtb_Abs1;
    real_T rtb_Abs1_k;
    real_T rtb_East;
    real_T rtb_HeadingAngle;
    real_T rtb_North;
    real_T rtb_Product2;
    real_T rtb_QuaternionInterpolation_idx_0;
    real_T rtb_QuaternionInterpolation_idx_2;
    real_T rtb_QuaternionInterpolation_idx_3;
    real_T rtb_Sum_dq;
    real_T rtb_Sum_n;
    real_T rtb_Switch;
    real_T rtb_Switch_gh;
    real_T rtb_Switch_m2;
    real_T stateNew_idx_0;
    real_T t;
    int32_T MatrixConcatenate_DIMS1[2];
    int32_T ForEach_itr;
    int32_T ForEach_itr_c;
    int32_T coffset;
    int32_T rtb_BiasNumUAV;
    int32_T rtb_BiasOldIdx;
    uint32_T inSize[8];
    uint32_T tmp_0;
    int16_T b_data[361];
    int8_T waypointsIn_0[2];
    int8_T rtAction;
    int8_T rtPrevAction;
    uint8_T rtb_SumofElements_i;
    boolean_T x_data[384];
    boolean_T rtb_InDangerSequence[361];
    boolean_T idx_data[128];
    boolean_T rtb_IsNaN[7];
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
        // Transition: '<S13>:152'
        localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
        localDW->ImmedMission_a = MissionModes::WaitToStart;

        // Entry 'WaitToStart': '<S13>:151'
    } else if (localDW->is_c25_ImmedMission == ImmedMission_IN_ImmedMission) {
        // During 'ImmedMission': '<S13>:154'
        if (*rtu_NewImmed) {
            // Transition: '<S13>:155'
            // Exit Internal 'ImmedMission': '<S13>:154'
            // Exit Internal 'Formation': '<S13>:246'
            localDW->is_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
            localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
            localDW->ImmedMission_a = MissionModes::WaitToStart;

            // Entry 'WaitToStart': '<S13>:151'
        } else {
            switch (localDW->is_ImmedMission) {
              case ImmedMission_IN_CollAvoidance:
                // During 'CollAvoidance': '<S13>:148'
                break;

              case ImmedMission_IN_DetailedInsp:
                // During 'DetailedInsp': '<S13>:166'
                break;

              case ImmedMission_IN_FlightMissionRH:
                // During 'FlightMissionRH': '<S13>:167'
                break;

              case ImmedMission_IN_Formation:
                // During 'Formation': '<S13>:246'
                if (localDW->FlightMode_prev != localDW->FlightMode_start) {
                    // Transition: '<S13>:247'
                    // Exit Internal 'Formation': '<S13>:246'
                    localDW->is_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
                    localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
                    localDW->ImmedMission_a = MissionModes::WaitToStart;

                    // Entry 'WaitToStart': '<S13>:151'
                }
                break;

              case ImmedMission_IN_SqCalibr:
                // During 'SqCalibr': '<S13>:170'
                if (static_cast<int32_T>(localDW->Memory_PreviousInput) != 0) {
                    // Transition: '<S13>:177'
                    localDW->is_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;
                    localDW->is_c25_ImmedMission = ImmedMission_IN_WaitToStart;
                    localDW->ImmedMission_a = MissionModes::WaitToStart;

                    // Entry 'WaitToStart': '<S13>:151'
                }
                break;

              default:
                // During 'pAttack': '<S13>:204'
                break;
            }
        }
    } else {
        // During 'WaitToStart': '<S13>:151'
        // Transition: '<S13>:153'
        switch (rtu_MissionInput->MissionMode) {
          case MissionModes::DetailedInsp:
            // Transition: '<S13>:187'
            // Transition: '<S13>:124'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_DetailedInsp;
            localDW->ImmedMission_a = MissionModes::DetailedInsp;
            break;

          case MissionModes::FlightMissionRH:
            // Transition: '<S13>:130'
            // Transition: '<S13>:189'
            // Transition: '<S13>:182'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_FlightMissionRH;
            localDW->ImmedMission_a = MissionModes::FlightMissionRH;
            break;

          case MissionModes::CollAvoidance:
            // Transition: '<S13>:185'
            // Transition: '<S13>:191'
            // Transition: '<S13>:131'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_CollAvoidance;
            localDW->ImmedMission_a = MissionModes::CollAvoidance;
            break;

          case MissionModes::SqCalibr:
            // Transition: '<S13>:176'
            // Transition: '<S13>:193'
            // Transition: '<S13>:174'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_SqCalibr;
            localDW->ImmedMission_a = MissionModes::SqCalibr;
            break;

          case MissionModes::pAttack:
            // Transition: '<S13>:200'
            // Transition: '<S13>:202'
            // Transition: '<S13>:217'
            localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
            localDW->is_ImmedMission = ImmedMission_IN_pAttack;
            localDW->ImmedMission_a = MissionModes::pAttack;
            break;

          default:
            if (rtu_MissionInput->SequenceID == *rtu_FlightMission_SequenceID) {
                // Transition: '<S13>:243'
                switch (rtu_MissionInput->MissionMode) {
                  case MissionModes::ShiftEarthENU:
                    // Transition: '<S13>:231'
                    // Transition: '<S13>:233'
                    localDW->is_c25_ImmedMission = ImmedMission_IN_ImmedMission;
                    localDW->is_ImmedMission = ImmedMission_IN_Formation;
                    localDW->ImmedMission_a = MissionModes::ShiftEarthENU;
                    break;

                  case MissionModes::ShiftBodyXYZ:
                    // Transition: '<S13>:228'
                    // Transition: '<S13>:232'
                    // Transition: '<S13>:235'
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

    // Sum: '<S226>/Sum1' incorporates:
    //   DataStoreRead: '<S2>/LatitudeGCS'
    //   DataStoreRead: '<S2>/LongitudeGCS'
    //   Sum: '<S228>/Sum'
    //   Switch: '<S240>/Switch'

    rtb_Sum1[0] = rtu_RealUAVState->Latitude_deg - LatitudeGCS;
    rtb_Sum1[1] = rtu_RealUAVState->Longitude_deg - LongitudeGCS;

    // Switch: '<S234>/Switch' incorporates:
    //   Abs: '<S234>/Abs'
    //   Bias: '<S234>/Bias'
    //   Bias: '<S234>/Bias1'
    //   Constant: '<S234>/Constant2'
    //   Constant: '<S235>/Constant'
    //   Math: '<S234>/Math Function1'
    //   RelationalOperator: '<S235>/Compare'

    if (std::abs(rtb_Sum1[0]) > 180.0) {
        rtb_Switch_m2 = rt_modd_snf(rtb_Sum1[0] + 180.0, 360.0) + -180.0;
    } else {
        rtb_Switch_m2 = rtb_Sum1[0];
    }

    // End of Switch: '<S234>/Switch'

    // Abs: '<S231>/Abs1'
    rtb_Abs1 = std::abs(rtb_Switch_m2);

    // Switch: '<S231>/Switch' incorporates:
    //   Bias: '<S231>/Bias'
    //   Bias: '<S231>/Bias1'
    //   Constant: '<S227>/Constant'
    //   Constant: '<S227>/Constant1'
    //   Constant: '<S233>/Constant'
    //   Gain: '<S231>/Gain'
    //   Product: '<S231>/Divide1'
    //   RelationalOperator: '<S233>/Compare'
    //   Switch: '<S227>/Switch1'

    if (rtb_Abs1 > 90.0) {
        // Signum: '<S231>/Sign1'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(rtb_Switch_m2)) ^ 1))) {
            if (rtb_Switch_m2 < 0.0) {
                rtb_Switch_m2 = -1.0;
            } else {
                rtb_Switch_m2 = static_cast<real_T>(rtb_Switch_m2 > 0.0);
            }
        }

        // End of Signum: '<S231>/Sign1'
        rtb_Switch_m2 *= -(rtb_Abs1 + -90.0) + 90.0;
        coffset = 180;
    } else {
        coffset = 0;
    }

    // End of Switch: '<S231>/Switch'

    // Sum: '<S227>/Sum'
    rtb_Sum_dq = static_cast<real_T>(coffset) + rtb_Sum1[1];

    // Switch: '<S232>/Switch' incorporates:
    //   Abs: '<S232>/Abs'
    //   Bias: '<S232>/Bias'
    //   Bias: '<S232>/Bias1'
    //   Constant: '<S232>/Constant2'
    //   Constant: '<S236>/Constant'
    //   Math: '<S232>/Math Function1'
    //   RelationalOperator: '<S236>/Compare'

    if (std::abs(rtb_Sum_dq) > 180.0) {
        rtb_Sum_dq = rt_modd_snf(rtb_Sum_dq + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S232>/Switch'

    // UnitConversion: '<S230>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Sum1[0] = 0.017453292519943295 * rtb_Switch_m2;
    rtb_Sum1[1] = 0.017453292519943295 * rtb_Sum_dq;

    // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
    //   ActionPort: '<S9>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
    //   ActionPort: '<S10>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Mode129_CollAvoidance' incorporates:
    //   ActionPort: '<S7>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
    //   ActionPort: '<S6>/Action Port'

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
    //   ForEach: '<S249>/For Each'

    // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   DataStoreRead: '<S2>/LatitudeGCS'
    //   Switch: '<S240>/Switch'
    //   Trigonometry: '<S178>/Trigonometric Function1'
    //   Trigonometry: '<S206>/Trigonometric Function1'
    //   Trigonometry: '<S246>/Trigonometric Function1'
    //   Trigonometry: '<S276>/Trigonometric Function1'
    //   Trigonometry: '<S61>/Trigonometric Function1'
    //   Trigonometry: '<S94>/Trigonometric Function1'
    //   UnitConversion: '<S154>/Unit Conversion'
    //   UnitConversion: '<S177>/Unit Conversion'
    //   UnitConversion: '<S205>/Unit Conversion'
    //   UnitConversion: '<S245>/Unit Conversion'
    //   UnitConversion: '<S275>/Unit Conversion'
    //   UnitConversion: '<S60>/Unit Conversion'
    //   UnitConversion: '<S93>/Unit Conversion'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    stateNew_idx_0 = 0.017453292519943295 * LatitudeGCS;
    rtb_QuaternionInterpolation_idx_3 = std::sin(stateNew_idx_0);

    // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'
    // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    // End of Outputs for SubSystem: '<S1>/Mode128_DetailedInsp'
    // End of Outputs for SubSystem: '<S1>/Mode129_CollAvoidance'
    // End of Outputs for SubSystem: '<S1>/Mode132_pAttack'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'

    // Sum: '<S246>/Sum1' incorporates:
    //   Constant: '<S246>/Constant'
    //   Product: '<S246>/Product1'
    //   Trigonometry: '<S246>/Trigonometric Function1'

    rtb_Sum_dq = 1.0 - 0.0066943799901413295 * rtb_QuaternionInterpolation_idx_3
        * rtb_QuaternionInterpolation_idx_3;

    // Product: '<S244>/Product1' incorporates:
    //   Constant: '<S244>/Constant1'
    //   Sqrt: '<S244>/sqrt'

    rtb_Switch_m2 = 6.378137E+6 / std::sqrt(rtb_Sum_dq);

    // Product: '<S229>/dNorth' incorporates:
    //   Constant: '<S244>/Constant2'
    //   Product: '<S244>/Product3'
    //   Trigonometry: '<S244>/Trigonometric Function1'

    rtb_Sum_dq = rtb_Sum1[0] / rt_atan2d_snf(1.0, rtb_Switch_m2 *
        0.99330562000985867 / rtb_Sum_dq);

    // Outputs for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
    //   ActionPort: '<S10>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
    //   ActionPort: '<S6>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
    //   ActionPort: '<S9>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Mode129_CollAvoidance' incorporates:
    //   ActionPort: '<S7>/Action Port'

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
    //   ForEach: '<S249>/For Each'

    // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   Trigonometry: '<S176>/Trigonometric Function'
    //   Trigonometry: '<S204>/Trigonometric Function'
    //   Trigonometry: '<S244>/Trigonometric Function'
    //   Trigonometry: '<S274>/Trigonometric Function'
    //   Trigonometry: '<S59>/Trigonometric Function'
    //   Trigonometry: '<S92>/Trigonometric Function'
    //   UnitConversion: '<S245>/Unit Conversion'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_QuaternionInterpolation_idx_2 = std::cos(stateNew_idx_0);

    // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'
    // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    // End of Outputs for SubSystem: '<S1>/Mode129_CollAvoidance'
    // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
    // End of Outputs for SubSystem: '<S1>/Mode128_DetailedInsp'
    // End of Outputs for SubSystem: '<S1>/Mode132_pAttack'

    // Product: '<S229>/dEast' incorporates:
    //   Constant: '<S244>/Constant3'
    //   Product: '<S244>/Product4'
    //   Trigonometry: '<S244>/Trigonometric Function'
    //   Trigonometry: '<S244>/Trigonometric Function2'

    rtb_Switch_m2 = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_m2 *
        rtb_QuaternionInterpolation_idx_2) * rtb_Sum1[1];

    // Outputs for Atomic SubSystem: '<Root>/RealState2Pose'
    // Gain: '<S4>/Gain2' incorporates:
    //   DataStoreRead: '<S2>/AltitudeGCS'
    //   Gain: '<S2>/inverse'
    //   Sum: '<S226>/Sum'

    rtb_Abs1 = -(rtu_RealUAVState->Height_meter + -AltitudeGCS);

    // SignalConversion generated from: '<S4>/SimPose' incorporates:
    //   Product: '<S229>/x*cos'
    //   Product: '<S229>/y*sin'
    //   Sum: '<S229>/Sum2'

    rtb_North = rtb_Switch_m2 * 0.0 + rtb_Sum_dq;

    // SignalConversion generated from: '<S4>/SimPose' incorporates:
    //   Product: '<S229>/x*sin'
    //   Product: '<S229>/y*cos'
    //   Sum: '<S229>/Sum3'

    rtb_East = rtb_Switch_m2 - rtb_Sum_dq * 0.0;

    // SignalConversion generated from: '<S4>/SimPose' incorporates:
    //   Gain: '<S223>/Gain1'

    rtb_HeadingAngle = 0.017453292519943295 * rtu_RealUAVState->HeadingAngle_deg;

    // End of Outputs for SubSystem: '<Root>/RealState2Pose'

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
    //   ForEach: '<S249>/For Each'

    for (ForEach_itr = 0; ForEach_itr < 128; ForEach_itr++) {
        // ForEachSliceSelector generated from: '<S249>/OtherUAVstate'
        rtb_Sum_dq = rtu_OtherUAVstate[ForEach_itr].Latitude_deg;

        // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
        // Sum: '<S256>/Sum1' incorporates:
        //   DataStoreRead: '<S3>/LatitudeGCS'
        //   ForEachSliceSelector generated from: '<S249>/OtherUAVstate'
        //   Switch: '<S270>/Switch'

        rtb_Sum1[0] = rtb_Sum_dq - LatitudeGCS;

        // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'

        // ForEachSliceSelector generated from: '<S249>/OtherUAVstate'
        t = rtu_OtherUAVstate[ForEach_itr].Longitude_deg;

        // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
        // Sum: '<S256>/Sum1' incorporates:
        //   DataStoreRead: '<S3>/LongitudeGCS'
        //   ForEachSliceSelector generated from: '<S249>/OtherUAVstate'
        //   Sum: '<S258>/Sum'

        rtb_Sum1[1] = t - LongitudeGCS;

        // Switch: '<S264>/Switch' incorporates:
        //   Abs: '<S264>/Abs'
        //   Bias: '<S264>/Bias'
        //   Bias: '<S264>/Bias1'
        //   Constant: '<S264>/Constant2'
        //   Constant: '<S265>/Constant'
        //   Math: '<S264>/Math Function1'
        //   RelationalOperator: '<S265>/Compare'

        if (std::abs(rtb_Sum1[0]) > 180.0) {
            rtb_Sum_n = rt_modd_snf(rtb_Sum1[0] + 180.0, 360.0) + -180.0;
        } else {
            rtb_Sum_n = rtb_Sum1[0];
        }

        // End of Switch: '<S264>/Switch'

        // Abs: '<S261>/Abs1'
        rtb_Abs1_k = std::abs(rtb_Sum_n);

        // Switch: '<S261>/Switch' incorporates:
        //   Bias: '<S261>/Bias'
        //   Bias: '<S261>/Bias1'
        //   Constant: '<S257>/Constant'
        //   Constant: '<S257>/Constant1'
        //   Constant: '<S263>/Constant'
        //   Gain: '<S261>/Gain'
        //   Product: '<S261>/Divide1'
        //   RelationalOperator: '<S263>/Compare'
        //   Switch: '<S257>/Switch1'

        if (rtb_Abs1_k > 90.0) {
            // Signum: '<S261>/Sign1'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Sum_n)) ^ 1))) {
                if (rtb_Sum_n < 0.0) {
                    rtb_Sum_n = -1.0;
                } else {
                    rtb_Sum_n = static_cast<real_T>(rtb_Sum_n > 0.0);
                }
            }

            // End of Signum: '<S261>/Sign1'
            rtb_Sum_n *= -(rtb_Abs1_k + -90.0) + 90.0;
            coffset = 180;
        } else {
            coffset = 0;
        }

        // End of Switch: '<S261>/Switch'

        // Sum: '<S257>/Sum'
        rtb_Product2 = static_cast<real_T>(coffset) + rtb_Sum1[1];

        // Switch: '<S262>/Switch' incorporates:
        //   Abs: '<S262>/Abs'
        //   Bias: '<S262>/Bias'
        //   Bias: '<S262>/Bias1'
        //   Constant: '<S262>/Constant2'
        //   Constant: '<S266>/Constant'
        //   Math: '<S262>/Math Function1'
        //   RelationalOperator: '<S266>/Compare'

        if (std::abs(rtb_Product2) > 180.0) {
            rtb_Product2 = rt_modd_snf(rtb_Product2 + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S262>/Switch'

        // Sum: '<S276>/Sum1' incorporates:
        //   Constant: '<S276>/Constant'
        //   Product: '<S276>/Product1'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_m2 = 1.0 - 0.0066943799901413295 *
            rtb_QuaternionInterpolation_idx_3 *
            rtb_QuaternionInterpolation_idx_3;

        // Product: '<S274>/Product1' incorporates:
        //   Constant: '<S274>/Constant1'
        //   Sqrt: '<S274>/sqrt'

        rtb_Switch = 6.378137E+6 / std::sqrt(rtb_Switch_m2);

        // UnitConversion: '<S260>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1[0] = 0.017453292519943295 * rtb_Sum_n;
        rtb_Sum1[1] = 0.017453292519943295 * rtb_Product2;

        // Product: '<S259>/dNorth' incorporates:
        //   Constant: '<S274>/Constant2'
        //   Product: '<S274>/Product3'
        //   Trigonometry: '<S274>/Trigonometric Function1'

        rtb_Switch_gh = rtb_Sum1[0] / rt_atan2d_snf(1.0, rtb_Switch *
            0.99330562000985867 / rtb_Switch_m2);

        // Product: '<S259>/dEast' incorporates:
        //   Constant: '<S274>/Constant3'
        //   Product: '<S274>/Product4'
        //   Trigonometry: '<S274>/Trigonometric Function2'

        rtb_Switch_m2 = 1.0 / rt_atan2d_snf(1.0, rtb_Switch *
            rtb_QuaternionInterpolation_idx_2) * rtb_Sum1[1];

        // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'

        // RelationalOperator: '<S252>/Compare' incorporates:
        //   Constant: '<S252>/Constant'

        rtb_IsNaN[0] = (rtb_Sum_dq != 0.0);
        rtb_IsNaN[1] = (t != 0.0);

        // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
        // ForEachSliceSelector generated from: '<S249>/OtherUAVstate' incorporates:
        //   Gain: '<S251>/Down2Up'

        rtb_Abs1_k = rtu_OtherUAVstate[ForEach_itr].Height_meter;

        // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'

        // RelationalOperator: '<S252>/Compare' incorporates:
        //   Constant: '<S252>/Constant'
        //   ForEachSliceSelector generated from: '<S249>/OtherUAVstate'

        rtb_IsNaN[2] = (rtb_Abs1_k != 0.0);

        // ForEachSliceSelector generated from: '<S249>/OtherUAVstate'
        rtb_Switch = rtu_OtherUAVstate[ForEach_itr].AirSpeed_mps;

        // RelationalOperator: '<S252>/Compare' incorporates:
        //   Constant: '<S252>/Constant'
        //   ForEachSliceSelector generated from: '<S249>/OtherUAVstate'

        rtb_IsNaN[3] = (rtb_Switch != 0.0);

        // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
        // ForEachSliceSelector generated from: '<S249>/OtherUAVstate' incorporates:
        //   Gain: '<S253>/Gain1'

        rtb_Sum_n = rtu_OtherUAVstate[ForEach_itr].HeadingAngle_deg;

        // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'

        // RelationalOperator: '<S252>/Compare' incorporates:
        //   Constant: '<S252>/Constant'
        //   ForEachSliceSelector generated from: '<S249>/OtherUAVstate'

        rtb_IsNaN[4] = (rtb_Sum_n != 0.0);

        // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
        // ForEachSliceSelector generated from: '<S249>/OtherUAVstate' incorporates:
        //   Gain: '<S254>/Gain1'

        rtb_Product2 = rtu_OtherUAVstate[ForEach_itr].FlightPathAngle_deg;

        // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'

        // RelationalOperator: '<S252>/Compare' incorporates:
        //   Constant: '<S252>/Constant'
        //   ForEachSliceSelector generated from: '<S249>/OtherUAVstate'

        rtb_IsNaN[5] = (rtb_Product2 != 0.0);

        // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
        // ForEachSliceSelector generated from: '<S249>/OtherUAVstate' incorporates:
        //   Gain: '<S255>/Gain1'

        rtb_Sum_dq = rtu_OtherUAVstate[ForEach_itr].RollAngle_deg;

        // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'

        // RelationalOperator: '<S252>/Compare' incorporates:
        //   Constant: '<S252>/Constant'
        //   ForEachSliceSelector generated from: '<S249>/OtherUAVstate'

        rtb_IsNaN[6] = (rtb_Sum_dq != 0.0);

        // Sum: '<S249>/Sum of Elements'
        tmp_0 = 0U;
        for (coffset = 0; coffset < 7; coffset++) {
            tmp_0 = static_cast<uint32_T>(tmp_0 + static_cast<uint32_T>
                (rtb_IsNaN[coffset]));
        }

        // Switch: '<S249>/Switch' incorporates:
        //   DataStoreRead: '<S3>/AltitudeGCS'
        //   Gain: '<S251>/Down2Up'
        //   Gain: '<S251>/inverse'
        //   Gain: '<S253>/Gain1'
        //   Gain: '<S254>/Gain1'
        //   Gain: '<S255>/Gain1'
        //   Product: '<S259>/x*cos'
        //   Product: '<S259>/x*sin'
        //   Product: '<S259>/y*cos'
        //   Product: '<S259>/y*sin'
        //   Sum: '<S249>/Sum of Elements'
        //   Sum: '<S256>/Sum'
        //   Sum: '<S259>/Sum2'
        //   Sum: '<S259>/Sum3'

        rtb_Compare_lh = (static_cast<int32_T>(static_cast<uint8_T>(tmp_0)) != 0);

        // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
        rtb_Switch_o[0] = rtb_Switch_m2 * 0.0 + rtb_Switch_gh;
        rtb_Switch_o[1] = rtb_Switch_m2 - rtb_Switch_gh * 0.0;
        rtb_Switch_o[2] = rtb_Abs1_k + -AltitudeGCS;

        // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'
        rtb_Switch_o[3] = rtb_Switch;

        // Outputs for Atomic SubSystem: '<S249>/LatLon2NorthEast'
        rtb_Switch_o[4] = 0.017453292519943295 * rtb_Sum_n;
        rtb_Switch_o[5] = 0.017453292519943295 * rtb_Product2;
        rtb_Switch_o[6] = 0.017453292519943295 * rtb_Sum_dq;

        // End of Outputs for SubSystem: '<S249>/LatLon2NorthEast'

        // ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
        for (coffset = 0; coffset < 7; coffset++) {
            // Switch: '<S249>/Switch' incorporates:
            //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'

            if (rtb_Compare_lh) {
                localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[static_cast<
                    int32_T>(ForEach_itr + static_cast<int32_T>(coffset << 7))] =
                    rtb_Switch_o[coffset];
            } else {
                localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[static_cast<
                    int32_T>(ForEach_itr + static_cast<int32_T>(coffset << 7))] =
                    (rtNaN);
            }
        }

        // End of ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
    }

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem'

    // SwitchCase: '<S1>/Switch Case' incorporates:
    //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
    //   Concatenate: '<S135>/Matrix Concatenate'
    //   Constant: '<S125>/ControlHdg'
    //   Constant: '<S125>/ControlSpd'
    //   Constant: '<S129>/InitTrigger'
    //   Constant: '<S129>/ShiftSimUAV'
    //   Constant: '<S183>/Constant'
    //   Constant: '<S183>/ControlHdg'
    //   Constant: '<S183>/ControlSpd'
    //   Constant: '<S183>/InitTrigger'
    //   Constant: '<S183>/ShiftSimUAV'
    //   Constant: '<S210>/ControlHdg'
    //   Constant: '<S210>/ControlSpd'
    //   Constant: '<S217>/ControlHdg'
    //   Constant: '<S217>/ControlSpd'
    //   Constant: '<S35>/ControlHdg'
    //   Constant: '<S35>/ControlSpd'
    //   Constant: '<S35>/ShiftSimUAV'
    //   Constant: '<S5>/ShiftSimUAV'
    //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
    //   ForEachSliceSelector generated from: '<S18>/StateNow'
    //   Gain: '<S17>/Gravity'
    //   Gain: '<S210>/Gravity'
    //   Gain: '<S224>/Gain1'
    //   Gain: '<S225>/Gain1'
    //   MATLAB Function: '<S135>/BaseWayPoint'
    //   MATLABSystem: '<S129>/Waypoint Follower'
    //   Product: '<S17>/HorizSpd'
    //   Product: '<S210>/HorizSpd'
    //   Product: '<S28>/HorizSpd'
    //   QuatInterp: '<S98>/Quaternion Interpolation'
    //   Sum: '<S18>/Sum of Elements'
    //   Sum: '<S249>/Sum of Elements'
    //   Sum: '<S71>/MinusVecCenter2UAV'
    //   Trigonometry: '<S17>/Cos'
    //   Trigonometry: '<S17>/Tan'
    //   Trigonometry: '<S210>/Cos'
    //   Trigonometry: '<S210>/Tan'
    //   Trigonometry: '<S28>/Cos'

    rtPrevAction = localDW->SwitchCase_ActiveSubsystem;
    switch (localDW->ImmedMission_a) {
      case MissionModes::DetailedInsp:
        rtAction = 0;
        break;

      case MissionModes::CollAvoidance:
        rtAction = 1;
        break;

      case MissionModes::FlightMissionRH:
        rtAction = 2;
        break;

      case MissionModes::SqCalibr:
        rtAction = 3;
        break;

      case MissionModes::pAttack:
        rtAction = 4;
        break;

      case MissionModes::ShiftEarthENU:
        rtAction = 5;
        break;

      case MissionModes::ShiftBodyXYZ:
        rtAction = 6;
        break;

      default:
        rtAction = 7;
        break;
    }

    localDW->SwitchCase_ActiveSubsystem = rtAction;
    if (static_cast<int32_T>(rtPrevAction) != static_cast<int32_T>(rtAction)) {
        // Disable for Atomic SubSystem: '<S217>/SailDistance'
        // Disable for Enabled SubSystem: '<S219>/SailShift'
        localDW->SailShift_MODE = static_cast<boolean_T>(static_cast<int32_T>((
            static_cast<int32_T>(rtPrevAction) != 5) & static_cast<int32_T>
            (localDW->SailShift_MODE)));

        // End of Disable for SubSystem: '<S219>/SailShift'
        // End of Disable for SubSystem: '<S217>/SailDistance'
    }

    switch (rtAction) {
      case 0:
        {
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // SystemReset for IfAction SubSystem: '<S1>/Mode128_DetailedInsp' incorporates:
                //   ActionPort: '<S6>/Action Port'

                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S35>/HdgHoldLogic'
                //   MATLABSystem: '<S35>/Orbit Follower'

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
            //   ActionPort: '<S6>/Action Port'

            // Sum: '<S40>/Sum1' incorporates:
            //   DataStoreRead: '<S35>/LatitudeGCS'
            //   DataStoreRead: '<S35>/LongitudeGCS'
            //   Sum: '<S43>/Sum'
            //   Switch: '<S55>/Switch'

            rtb_Sum1[0] = rtu_MissionInput->MissionLocation.Lat - LatitudeGCS;
            rtb_Sum1[1] = rtu_MissionInput->MissionLocation.Lon - LongitudeGCS;

            // Switch: '<S49>/Switch' incorporates:
            //   Abs: '<S49>/Abs'
            //   Bias: '<S49>/Bias'
            //   Bias: '<S49>/Bias1'
            //   Constant: '<S49>/Constant2'
            //   Constant: '<S50>/Constant'
            //   Math: '<S49>/Math Function1'
            //   RelationalOperator: '<S50>/Compare'

            if (std::abs(rtb_Sum1[0]) > 180.0) {
                rtb_Switch_m2 = rt_modd_snf(rtb_Sum1[0] + 180.0, 360.0) + -180.0;
            } else {
                rtb_Switch_m2 = rtb_Sum1[0];
            }

            // End of Switch: '<S49>/Switch'

            // Abs: '<S46>/Abs1'
            rtb_Abs1_k = std::abs(rtb_Switch_m2);

            // Switch: '<S46>/Switch' incorporates:
            //   Bias: '<S46>/Bias'
            //   Bias: '<S46>/Bias1'
            //   Constant: '<S42>/Constant'
            //   Constant: '<S42>/Constant1'
            //   Constant: '<S48>/Constant'
            //   Gain: '<S46>/Gain'
            //   Product: '<S46>/Divide1'
            //   RelationalOperator: '<S48>/Compare'
            //   Switch: '<S42>/Switch1'

            if (rtb_Abs1_k > 90.0) {
                // Signum: '<S46>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Switch_m2)) ^ 1))) {
                    if (rtb_Switch_m2 < 0.0) {
                        rtb_Switch_m2 = -1.0;
                    } else {
                        rtb_Switch_m2 = static_cast<real_T>(rtb_Switch_m2 > 0.0);
                    }
                }

                // End of Signum: '<S46>/Sign1'
                rtb_Switch_m2 *= -(rtb_Abs1_k + -90.0) + 90.0;
                coffset = 180;
            } else {
                coffset = 0;
            }

            // End of Switch: '<S46>/Switch'

            // Sum: '<S42>/Sum'
            rtb_Sum_n = static_cast<real_T>(coffset) + rtb_Sum1[1];

            // Switch: '<S47>/Switch' incorporates:
            //   Abs: '<S47>/Abs'
            //   Bias: '<S47>/Bias'
            //   Bias: '<S47>/Bias1'
            //   Constant: '<S47>/Constant2'
            //   Constant: '<S51>/Constant'
            //   Math: '<S47>/Math Function1'
            //   RelationalOperator: '<S51>/Compare'

            if (std::abs(rtb_Sum_n) > 180.0) {
                rtb_Sum_n = rt_modd_snf(rtb_Sum_n + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S47>/Switch'

            // UnitConversion: '<S45>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1[0] = 0.017453292519943295 * rtb_Switch_m2;
            rtb_Sum1[1] = 0.017453292519943295 * rtb_Sum_n;

            // Sum: '<S61>/Sum1' incorporates:
            //   Constant: '<S61>/Constant'
            //   Product: '<S61>/Product1'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum_n = 1.0 - 0.0066943799901413295 *
                rtb_QuaternionInterpolation_idx_3 *
                rtb_QuaternionInterpolation_idx_3;

            // Product: '<S59>/Product1' incorporates:
            //   Constant: '<S59>/Constant1'
            //   Sqrt: '<S59>/sqrt'

            rtb_Switch_m2 = 6.378137E+6 / std::sqrt(rtb_Sum_n);

            // Product: '<S44>/dNorth' incorporates:
            //   Constant: '<S59>/Constant2'
            //   Product: '<S59>/Product3'
            //   Trigonometry: '<S59>/Trigonometric Function1'

            rtb_Sum_n = rtb_Sum1[0] / rt_atan2d_snf(1.0, rtb_Switch_m2 *
                0.99330562000985867 / rtb_Sum_n);

            // UnitConversion: '<S58>/Unit Conversion' incorporates:
            //   Constant: '<S35>/AngleLLA'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_gh = 0.0;

            // Product: '<S44>/dEast' incorporates:
            //   Constant: '<S59>/Constant3'
            //   Product: '<S59>/Product4'
            //   Trigonometry: '<S59>/Trigonometric Function2'

            rtb_Switch_m2 = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_m2 *
                rtb_QuaternionInterpolation_idx_2) * rtb_Sum1[1];

            // SignalConversion generated from: '<S35>/Orbit Follower' incorporates:
            //   DataStoreRead: '<S35>/AltitudeGCS'
            //   Gain: '<S35>/inverse'
            //   Product: '<S44>/x*cos'
            //   Product: '<S44>/x*sin'
            //   Product: '<S44>/y*cos'
            //   Product: '<S44>/y*sin'
            //   Sum: '<S40>/Sum'
            //   Sum: '<S44>/Sum2'
            //   Sum: '<S44>/Sum3'
            //   UnaryMinus: '<S40>/Ze2height'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Switch_m2 *
                0.0 + rtb_Sum_n;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Switch_m2 -
                rtb_Sum_n * 0.0;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                -(rtu_MissionInput->MissionLocation.Alt + -AltitudeGCS);

            // Sum: '<S36>/Sum'
            rtb_Sum_o[0] = rtb_North -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
            rtb_Sum_o[1] = rtb_East -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
            rtb_Sum_o[2] = rtb_Abs1 -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Sqrt: '<S36>/sqrt' incorporates:
            //   DotProduct: '<S36>/Dot Product'

            rtb_Abs1_k = std::sqrt((rtb_Sum_o[0] * rtb_Sum_o[0] + rtb_Sum_o[1] *
                                    rtb_Sum_o[1]) + rtb_Sum_o[2] * rtb_Sum_o[2]);

            // Chart: '<S35>/HdgHoldLogic' incorporates:
            //   DataTypeConversion: '<S35>/Param2'
            //   DataTypeConversion: '<S35>/Param3'

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
                // Transition: '<S39>:4'
                if (rtb_Abs1_k >= static_cast<real_T>
                        (rtu_MissionInput->params.Param3)) {
                    // Transition: '<S39>:26'
                    localDW->is_c1_ImmedMission = ImmedMission_IN_OutOfRange;

                    // Entry 'OutOfRange': '<S39>:11'
                    rtb_Abs1_k = 1.0;
                } else {
                    // Transition: '<S39>:27'
                    localDW->is_c1_ImmedMission = ImmedMission_IN_WithInRange;

                    // Entry 'WithInRange': '<S39>:9'
                    rtb_Abs1_k = 0.0;
                }
            } else {
                switch (localDW->is_c1_ImmedMission) {
                  case ImmedMission_IN_OutOfRange:
                    // During 'OutOfRange': '<S39>:11'
                    if (rtb_Abs1_k < static_cast<real_T>
                            (rtu_MissionInput->params.Param2)) {
                        // Transition: '<S39>:15'
                        localDW->is_c1_ImmedMission =
                            ImmedMission_IN_WithInRange;

                        // Entry 'WithInRange': '<S39>:9'
                        rtb_Abs1_k = 0.0;
                    } else {
                        rtb_Abs1_k = 1.0;
                    }
                    break;

                  case ImmedMission_IN_Turning:
                    // During 'Turning': '<S39>:23'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i1_p) >=
                            20U) {
                        // Transition: '<S39>:24'
                        localDW->is_c1_ImmedMission = ImmedMission_IN_OutOfRange;

                        // Entry 'OutOfRange': '<S39>:11'
                        rtb_Abs1_k = 1.0;
                    } else {
                        rtb_Abs1_k = 2.0;
                    }
                    break;

                  default:
                    // During 'WithInRange': '<S39>:9'
                    if (rtb_Abs1_k >= static_cast<real_T>
                            (rtu_MissionInput->params.Param3)) {
                        // Transition: '<S39>:14'
                        localDW->is_c1_ImmedMission = ImmedMission_IN_Turning;
                        localDW->temporalCounter_i1_p = 0U;

                        // Entry 'Turning': '<S39>:23'
                        rtb_Abs1_k = 2.0;
                    } else {
                        rtb_Abs1_k = 0.0;
                    }
                    break;
                }
            }

            // End of Chart: '<S35>/HdgHoldLogic'

            // DataTypeConversion: '<S35>/DoubleStatus'
            *rty_TaskStatus = rtb_Abs1_k;

            // SignalConversion generated from: '<S35>/Orbit Follower'
            rtb_TmpSignalConversionAtOrbitFollowerInport1[0] = rtb_North;
            rtb_TmpSignalConversionAtOrbitFollowerInport1[1] = rtb_East;
            rtb_TmpSignalConversionAtOrbitFollowerInport1[2] = rtb_Abs1;
            rtb_TmpSignalConversionAtOrbitFollowerInport1[3] = rtb_HeadingAngle;

            // Signum: '<S35>/Sign' incorporates:
            //   DataTypeConversion: '<S35>/DoubleTurnDir'

            if (static_cast<real_T>(rtu_MissionInput->FormationPos) < 0.0) {
                rtb_Abs1 = -1.0;
            } else {
                rtb_Abs1 = static_cast<real_T>(static_cast<real_T>
                    (rtu_MissionInput->FormationPos) > 0.0);
            }

            // End of Signum: '<S35>/Sign'

            // MATLABSystem: '<S35>/Orbit Follower' incorporates:
            //   DataTypeConversion: '<S35>/DoubleParam4'
            //   SignalConversion generated from: '<S35>/Orbit Follower'

            localDW->obj_c.OrbitRadiusFlag = 1U;
            rtb_HeadingAngle = static_cast<real_T>
                (rtu_MissionInput->params.Param1);
            localDW->obj_c.LookaheadDistFlag = 0U;
            if (static_cast<real_T>(rtu_MissionInput->params.Param1) < 0.1) {
                rtb_HeadingAngle = 0.1;
                localDW->obj_c.LookaheadDistFlag = 1U;
            }

            rtb_TmpSignalConversionAtOrbitF[0] = rtb_North -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
            rtb_Switch_m2 = rtb_TmpSignalConversionAtOrbitFollowerInport1[1] -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
            rtb_TmpSignalConversionAtOrbitF[1] = rtb_Switch_m2;
            if (ImmedMission_norm_p(rtb_TmpSignalConversionAtOrbitF) <
                    2.47032822920623E-323) {
                rtb_Sum_o[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                rtb_North = rtb_TmpSignalConversionAtOrbitFollowerInport1[3];
            } else {
                boolean_T exitg1;
                boolean_T guard1{ false };

                boolean_T rtb_Ctrl;
                rtb_Compare_lh = false;
                rtb_Ctrl = true;
                ForEach_itr = 0;
                exitg1 = false;
                while ((!exitg1) && (ForEach_itr < 3)) {
                    if ((localDW->obj_c.OrbitCenterInternal[ForEach_itr] ==
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[ForEach_itr])
                        || (std::isnan(localDW->
                                       obj_c.OrbitCenterInternal[ForEach_itr]) &&
                            std::isnan
                            (rtb_TmpSignalConversionAtOrbitFollowerInport2[ForEach_itr])))
                    {
                        ForEach_itr = static_cast<int32_T>(ForEach_itr + 1);
                    } else {
                        rtb_Ctrl = false;
                        exitg1 = true;
                    }
                }

                if (rtb_Ctrl) {
                    rtb_Compare_lh = true;
                }

                if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                        int32_T>(rtb_Compare_lh) ^ 1))) ||
                        (!(localDW->obj_c.OrbitRadiusInternal == 0.1))) {
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

                if (rtb_HeadingAngle >= 0.1) {
                    localDW->obj_c.LookaheadDistance = 0.090000000000000011;
                } else {
                    localDW->obj_c.LookaheadDistance = rtb_HeadingAngle;
                }

                rtb_Sum1[0] = rtb_North;
                rtb_Sum1[1] = rtb_TmpSignalConversionAtOrbitFollowerInport1[1];
                xyCenter[0] = rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                xyCenter[1] = rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                stateNew_idx_0 = rtb_Sum1[0] - xyCenter[0];
                distToCenter_tmp[0] = stateNew_idx_0;
                rtb_Sum_n = rtb_Sum1[1] - xyCenter[1];
                distToCenter_tmp[1] = rtb_Sum_n;
                rtb_Switch = std::sqrt(rtb_Sum_n * rtb_Sum_n + stateNew_idx_0 *
                                       stateNew_idx_0);
                rtb_HeadingAngle = std::abs(localDW->obj_c.LookaheadDistance +
                    0.1);
                rtb_Compare_lh = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(std::isinf(rtb_HeadingAngle)) ^ 1));
                rtb_Ctrl = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(std::isnan(rtb_HeadingAngle)) ^ 1));
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rtb_Compare_lh)
                      & static_cast<int32_T>(rtb_Ctrl)))) {
                    if (rtb_HeadingAngle <= 2.2250738585072014E-308) {
                        rtb_East = 4.94065645841247E-324;
                    } else {
                        frexp(rtb_HeadingAngle, &rtb_BiasOldIdx);
                        rtb_East = std::ldexp(1.0, static_cast<int32_T>
                                              (rtb_BiasOldIdx - 53));
                    }
                } else {
                    rtb_East = (rtNaN);
                }

                guard1 = false;
                if (rtb_Switch >= (localDW->obj_c.LookaheadDistance + 0.1) - 5.0
                    * rtb_East) {
                    guard1 = true;
                } else {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               (static_cast<int32_T>
                                                (rtb_Compare_lh) &
                                                static_cast<int32_T>(rtb_Ctrl))))
                    {
                        if (rtb_HeadingAngle <= 2.2250738585072014E-308) {
                            rtb_East = 4.94065645841247E-324;
                        } else {
                            frexp(rtb_HeadingAngle, &ForEach_itr_c);
                            rtb_East = std::ldexp(1.0, static_cast<int32_T>
                                                  (ForEach_itr_c - 53));
                        }
                    } else {
                        rtb_East = (rtNaN);
                    }

                    if (rtb_Switch <= (0.1 - localDW->obj_c.LookaheadDistance) +
                        5.0 * rtb_East) {
                        guard1 = true;
                    } else {
                        if (localDW->obj_c.StartFlag) {
                            localDW->obj_c.PrevPosition[0] = rtb_North;
                            localDW->obj_c.PrevPosition[1] =
                                rtb_TmpSignalConversionAtOrbitFollowerInport1[1];
                            localDW->obj_c.StartFlag = false;
                        }

                        rtb_TmpSignalConversionAtOrbitF[0] = stateNew_idx_0;
                        rtb_TmpSignalConversionAtOrbitF[1] = rtb_Sum_n;
                        rtb_East = ImmedMission_norm_p
                            (rtb_TmpSignalConversionAtOrbitF);
                        rtb_Switch = localDW->obj_c.LookaheadDistance *
                            localDW->obj_c.LookaheadDistance;
                        rtb_Sum_dq = ((rtb_Switch - 0.010000000000000002) +
                                      rtb_East * rtb_East) / (2.0 * rtb_East);
                        rtb_Sum_n = xyCenter[0] - rtb_Sum1[0];
                        rtb_North = rtb_Sum_n * rtb_Sum_dq / rtb_East +
                            rtb_Sum1[0];
                        stateNew_idx_0 = xyCenter[1] - rtb_Sum1[1];
                        rtb_HeadingAngle = stateNew_idx_0 * rtb_Sum_dq /
                            rtb_East + rtb_Sum1[1];
                        rtb_Switch = std::sqrt(rtb_Switch - rtb_Sum_dq *
                                               rtb_Sum_dq);
                        stateNew_idx_0 = stateNew_idx_0 * rtb_Switch / rtb_East;
                        distToCenter_tmp[0] = rtb_North - stateNew_idx_0;
                        distToCenter_tmp[1] = stateNew_idx_0 + rtb_North;
                        rtb_East = rtb_Sum_n * rtb_Switch / rtb_East;
                        stateNew_idx_0 = rtb_East + rtb_HeadingAngle;
                        rtb_HeadingAngle -= rtb_East;
                        if ((rtb_Abs1 == 0.0) && (static_cast<boolean_T>(
                                static_cast<int32_T>(static_cast<int32_T>
                                (localDW->obj_c.SelectTurnDirectionFlag) ^ 1))))
                        {
                            rtb_East = localDW->obj_c.TurnDirectionInternal;
                        } else {
                            rtb_East = rtb_Abs1;
                        }

                        rtb_Switch = localDW->obj_c.PrevPosition[0] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                        rtb_Sum_n = localDW->obj_c.PrevPosition[1] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                        rtb_Sum_o[0] = rtb_Switch;
                        rtb_Sum_o[1] = rtb_Sum_n;
                        rtb_Sum_o[2] = 0.0;
                        rtb_VectorConcatenate[0] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[0] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                        rtb_VectorConcatenate[1] = rtb_Switch_m2;
                        rtb_VectorConcatenate[2] = 0.0;
                        if (rtb_East < 0.0) {
                            rtb_Sum_o[0] = rtb_VectorConcatenate[0];
                            rtb_VectorConcatenate[0] = rtb_Switch;
                            rtb_Sum_o[1] = rtb_Switch_m2;
                            rtb_VectorConcatenate[1] = rtb_Sum_n;
                            rtb_Sum_o[2] = 0.0;
                            rtb_VectorConcatenate[2] = 0.0;
                        }

                        rtb_Product2 = ImmedMission_norm_pv(rtb_Sum_o);
                        rtb_Switch_m2 = ImmedMission_norm_pv
                            (rtb_VectorConcatenate);
                        rtb_Sum_dq = rtb_Sum_o[0] / rtb_Product2;
                        rtb_Switch = rtb_VectorConcatenate[0] / rtb_Switch_m2;
                        rtb_North = rtb_Sum_o[1] / rtb_Product2;
                        rtb_Sum_n = rtb_VectorConcatenate[1] / rtb_Switch_m2;
                        localDW->obj_c.PrevPosition[0] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[0];
                        localDW->obj_c.PrevPosition[1] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[1];
                        localDW->obj_c.PrevPosition[2] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[2];
                        localDW->obj_c.NumCircles += rt_atan2d_snf(rtb_Sum_dq *
                            rtb_Sum_n - rtb_Switch * rtb_North, (rtb_Sum_dq *
                            rtb_Switch + rtb_North * rtb_Sum_n) + 0.0 /
                            rtb_Product2 * (0.0 / rtb_Switch_m2)) / 2.0 /
                            3.1415926535897931;
                        rtb_Sum_o[0] = xyCenter[0] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[0];
                        rtb_Sum_o[1] = xyCenter[1] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[1];
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(std::isnan(rtb_East)) ^ 1)))
                        {
                            if (rtb_East < 0.0) {
                                rtb_East = -1.0;
                            } else {
                                rtb_East = static_cast<real_T>(rtb_East > 0.0);
                            }
                        }

                        switch (static_cast<int32_T>(rtb_East)) {
                          case 1:
                            if ((distToCenter_tmp[0] -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1
                                    [0]) * rtb_Sum_o[1] - (stateNew_idx_0 -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1
                                    [1]) * rtb_Sum_o[0] > 0.0) {
                                xyCenter[0] = distToCenter_tmp[0];
                                xyCenter[1] = stateNew_idx_0;
                            } else {
                                xyCenter[0] = distToCenter_tmp[1];
                                xyCenter[1] = rtb_HeadingAngle;
                            }
                            break;

                          case -1:
                            if ((distToCenter_tmp[0] -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1
                                    [0]) * rtb_Sum_o[1] - (stateNew_idx_0 -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1
                                    [1]) * rtb_Sum_o[0] < 0.0) {
                                xyCenter[0] = distToCenter_tmp[0];
                                xyCenter[1] = stateNew_idx_0;
                            } else {
                                xyCenter[0] = distToCenter_tmp[1];
                                xyCenter[1] = rtb_HeadingAngle;
                            }
                            break;

                          default:
                            if (std::abs(ImmedMission_angdiff(rt_atan2d_snf
                                    (stateNew_idx_0 -
                                     rtb_TmpSignalConversionAtOrbitFollowerInport1
                                     [1], distToCenter_tmp[0] -
                                     rtb_TmpSignalConversionAtOrbitFollowerInport1
                                     [0]),
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1
                                    [3])) < std::abs(ImmedMission_angdiff
                                                     (rt_atan2d_snf
                                                      (rtb_HeadingAngle -
                                                       rtb_TmpSignalConversionAtOrbitFollowerInport1
                                                       [1], distToCenter_tmp[1]
                                                       - rtb_TmpSignalConversionAtOrbitFollowerInport1
                                                       [0]),
                                                      rtb_TmpSignalConversionAtOrbitFollowerInport1
                                                      [3]))) {
                                xyCenter[0] = distToCenter_tmp[0];
                                xyCenter[1] = stateNew_idx_0;
                            } else {
                                xyCenter[0] = distToCenter_tmp[1];
                                xyCenter[1] = rtb_HeadingAngle;
                            }

                            if ((xyCenter[0] -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1
                                    [0]) * rtb_Sum_o[1] - (xyCenter[1] -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1
                                    [1]) * rtb_Sum_o[0] > 0.0) {
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
                    rtb_Product2 = ImmedMission_norm_p(distToCenter_tmp);
                    xyCenter[0] += stateNew_idx_0 / rtb_Product2 * 0.1;
                    xyCenter[1] += rtb_Sum_n / rtb_Product2 * 0.1;
                }

                rtb_Sum_o[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                rtb_North = rt_atan2d_snf(xyCenter[1] - rtb_Sum1[1], xyCenter[0]
                    - rtb_Sum1[0]);
            }

            // Outputs for Enabled SubSystem: '<S35>/FeedthroughHDG' incorporates:
            //   EnablePort: '<S38>/Enable'

            if (rtb_Abs1_k > 0.0) {
                // SignalConversion generated from: '<S38>/OrbitNavHdg' incorporates:
                //   MATLABSystem: '<S35>/Orbit Follower'

                localDW->OrbitNavHdg = rtb_North;
            }

            // End of Outputs for SubSystem: '<S35>/FeedthroughHDG'

            // Switch: '<S35>/Switch' incorporates:
            //   Constant: '<S35>/Constant'
            //   Constant: '<S41>/Constant'
            //   Product: '<S35>/Product'
            //   RelationalOperator: '<S41>/Compare'

            if (rtb_Abs1_k == 2.0) {
                rtb_Switch_gh = 2.3561944901923448 * rtb_Abs1;
            }

            // End of Switch: '<S35>/Switch'

            // BusCreator: '<S35>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S35>/DoubleTurnDir'
            //   DataTypeConversion: '<S35>/Param4'
            //   Gain: '<S35>/Down2Height'
            //   Gain: '<S35>/Gain'
            //   Gain: '<S35>/GainLayering'
            //   MATLABSystem: '<S35>/Orbit Follower'
            //   Sum: '<S35>/Minus'
            //   Sum: '<S35>/Sum'
            //   Sum: '<S35>/SumHeight'

            rty_GuidanceCMD->Height = -((static_cast<real_T>
                (rtu_MissionInput->FormationPos) - 0.5 * rtb_Abs1) * 20.0 +
                rtb_Sum_o[2]);
            rty_GuidanceCMD->AirSpeed = static_cast<real_T>
                (rtu_MissionInput->params.Param4);
            rty_GuidanceCMD->HeadingAngle = rtb_Switch_gh + localDW->OrbitNavHdg;
            rtb_Compare_lh = false;
            rty_ControlSwitch[0] = true;
            rty_ControlSwitch[1] = true;

            // End of Outputs for SubSystem: '<S1>/Mode128_DetailedInsp'
        }
        break;

      case 1:
        {
            int32_T colToCopy;
            boolean_T exitg1;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // InitializeConditions for IfAction SubSystem: '<S1>/Mode129_CollAvoidance' incorporates:
                //   ActionPort: '<S7>/Action Port'

                // InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Memory: '<S65>/MemoryPrevRange'
                //   Memory: '<S65>/MemoryStatus'
                //   S-Function (sfix_udelay): '<S72>/AirSpdSeq'
                //   S-Function (sfix_udelay): '<S72>/EastSeq'
                //   S-Function (sfix_udelay): '<S72>/HdgSeq'
                //   S-Function (sfix_udelay): '<S72>/HeightSeq'
                //   S-Function (sfix_udelay): '<S72>/InDangerSequence'
                //   S-Function (sfix_udelay): '<S72>/NorthSeq'
                //   S-Function (sfix_udelay): '<S72>/PitchSeq'
                //   S-Function (sfix_udelay): '<S72>/RollRateSeq'
                //   S-Function (sfix_udelay): '<S72>/RollSeq'

                localDW->MemoryPrevRange_PreviousInput = 0.0;
                localDW->MemoryStatus_PreviousInput = 0U;
                std::memset(&localDW->NorthSeq_X[0], 0, static_cast<uint32_T>
                            (360U * sizeof(real_T)));
                std::memset(&localDW->EastSeq_X[0], 0, static_cast<uint32_T>
                            (360U * sizeof(real_T)));
                std::memset(&localDW->HeightSeq_X[0], 0, static_cast<uint32_T>
                            (360U * sizeof(real_T)));
                std::memset(&localDW->AirSpdSeq_X[0], 0, static_cast<uint32_T>
                            (360U * sizeof(real_T)));
                std::memset(&localDW->HdgSeq_X[0], 0, static_cast<uint32_T>(360U
                             * sizeof(real_T)));
                std::memset(&localDW->PitchSeq_X[0], 0, static_cast<uint32_T>
                            (360U * sizeof(real_T)));
                std::memset(&localDW->RollSeq_X[0], 0, static_cast<uint32_T>
                            (360U * sizeof(real_T)));
                std::memset(&localDW->RollRateSeq_X[0], 0, static_cast<uint32_T>
                            (360U * sizeof(real_T)));
                std::memset(&localDW->InDangerSequence_X[0], 0,
                            static_cast<uint32_T>(360U * sizeof(boolean_T)));

                // End of InitializeConditions for SubSystem: '<S1>/Mode129_CollAvoidance' 

                // SystemReset for IfAction SubSystem: '<S1>/Mode129_CollAvoidance' incorporates:
                //   ActionPort: '<S7>/Action Port'

                // SystemReset for Atomic SubSystem: '<S65>/HeadingControl'
                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S65>/TrackSwitch'
                //   MATLABSystem: '<S68>/TrackSimPath'

                localDW->obj_j.WaypointIndex = 1.0;
                for (coffset = 0; coffset < 2700; coffset++) {
                    localDW->obj_j.WaypointsInternal[coffset] = (rtNaN);
                }

                // End of SystemReset for SubSystem: '<S65>/HeadingControl'
                localDW->temporalCounter_i1_d = 0U;
                localDW->is_active_c4_ImmedMission = 0U;
                localDW->is_c4_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;

                // End of SystemReset for SubSystem: '<S1>/Mode129_CollAvoidance' 
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode129_CollAvoidance' incorporates:
            //   ActionPort: '<S7>/Action Port'

            // Sum: '<S69>/Sum1' incorporates:
            //   DataStoreRead: '<S65>/LatitudeGCS'
            //   DataStoreRead: '<S65>/LongitudeGCS'
            //   Sum: '<S76>/Sum'
            //   Switch: '<S88>/Switch'

            rtb_Sum1[0] = rtu_MissionInput->MissionLocation.Lat - LatitudeGCS;
            rtb_Sum1[1] = rtu_MissionInput->MissionLocation.Lon - LongitudeGCS;

            // Switch: '<S82>/Switch' incorporates:
            //   Abs: '<S82>/Abs'
            //   Bias: '<S82>/Bias'
            //   Bias: '<S82>/Bias1'
            //   Constant: '<S82>/Constant2'
            //   Constant: '<S83>/Constant'
            //   Math: '<S82>/Math Function1'
            //   RelationalOperator: '<S83>/Compare'

            if (std::abs(rtb_Sum1[0]) > 180.0) {
                rtb_Switch_gh = rt_modd_snf(rtb_Sum1[0] + 180.0, 360.0) + -180.0;
            } else {
                rtb_Switch_gh = rtb_Sum1[0];
            }

            // End of Switch: '<S82>/Switch'

            // Abs: '<S79>/Abs1'
            rtb_Abs1_k = std::abs(rtb_Switch_gh);

            // Switch: '<S79>/Switch' incorporates:
            //   Bias: '<S79>/Bias'
            //   Bias: '<S79>/Bias1'
            //   Constant: '<S75>/Constant'
            //   Constant: '<S75>/Constant1'
            //   Constant: '<S81>/Constant'
            //   Gain: '<S79>/Gain'
            //   Product: '<S79>/Divide1'
            //   RelationalOperator: '<S81>/Compare'
            //   Switch: '<S75>/Switch1'

            if (rtb_Abs1_k > 90.0) {
                // Signum: '<S79>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Switch_gh)) ^ 1))) {
                    if (rtb_Switch_gh < 0.0) {
                        rtb_Switch_gh = -1.0;
                    } else {
                        rtb_Switch_gh = static_cast<real_T>(rtb_Switch_gh > 0.0);
                    }
                }

                // End of Signum: '<S79>/Sign1'
                rtb_Switch_gh *= -(rtb_Abs1_k + -90.0) + 90.0;
                coffset = 180;
            } else {
                coffset = 0;
            }

            // End of Switch: '<S79>/Switch'

            // Sum: '<S75>/Sum'
            rtb_Switch_m2 = static_cast<real_T>(coffset) + rtb_Sum1[1];

            // Switch: '<S80>/Switch' incorporates:
            //   Abs: '<S80>/Abs'
            //   Bias: '<S80>/Bias'
            //   Bias: '<S80>/Bias1'
            //   Constant: '<S80>/Constant2'
            //   Constant: '<S84>/Constant'
            //   Math: '<S80>/Math Function1'
            //   RelationalOperator: '<S84>/Compare'

            if (std::abs(rtb_Switch_m2) > 180.0) {
                rtb_Switch_m2 = rt_modd_snf(rtb_Switch_m2 + 180.0, 360.0) +
                    -180.0;
            }

            // End of Switch: '<S80>/Switch'

            // UnitConversion: '<S78>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1[0] = 0.017453292519943295 * rtb_Switch_gh;
            rtb_Sum1[1] = 0.017453292519943295 * rtb_Switch_m2;

            // Sum: '<S94>/Sum1' incorporates:
            //   Constant: '<S94>/Constant'
            //   Product: '<S94>/Product1'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_m2 = 1.0 - 0.0066943799901413295 *
                rtb_QuaternionInterpolation_idx_3 *
                rtb_QuaternionInterpolation_idx_3;

            // Product: '<S92>/Product1' incorporates:
            //   Constant: '<S92>/Constant1'
            //   Sqrt: '<S92>/sqrt'

            rtb_Switch_gh = 6.378137E+6 / std::sqrt(rtb_Switch_m2);

            // Product: '<S77>/dNorth' incorporates:
            //   Constant: '<S92>/Constant2'
            //   Product: '<S92>/Product3'
            //   Trigonometry: '<S92>/Trigonometric Function1'

            rtb_Switch_m2 = rtb_Sum1[0] / rt_atan2d_snf(1.0, rtb_Switch_gh *
                0.99330562000985867 / rtb_Switch_m2);

            // Product: '<S77>/dEast' incorporates:
            //   Constant: '<S92>/Constant3'
            //   Product: '<S92>/Product4'
            //   Trigonometry: '<S92>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_gh = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_gh *
                rtb_QuaternionInterpolation_idx_2) * rtb_Sum1[1];

            // Sum: '<S77>/Sum2' incorporates:
            //   Product: '<S77>/x*cos'
            //   Product: '<S77>/y*sin'

            rtb_Switch = rtb_Switch_gh * 0.0 + rtb_Switch_m2;

            // Sum: '<S77>/Sum3' incorporates:
            //   Product: '<S77>/x*sin'
            //   Product: '<S77>/y*cos'

            rtb_Abs1_k = rtb_Switch_gh - rtb_Switch_m2 * 0.0;

            // Gain: '<S65>/Down2Up' incorporates:
            //   DataStoreRead: '<S65>/AltitudeGCS'
            //   Gain: '<S65>/inverse'
            //   Sum: '<S69>/Sum'

            rtb_Switch_gh = rtu_MissionInput->MissionLocation.Alt + -AltitudeGCS;

            // Sum: '<S66>/Sum'
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Switch -
                rtu_SimUAVstate->North;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Abs1_k -
                rtu_SimUAVstate->East;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = rtb_Switch_gh -
                rtu_SimUAVstate->Height;

            // Sqrt: '<S66>/sqrt' incorporates:
            //   DotProduct: '<S66>/Dot Product'

            localDW->sqrt_f = std::sqrt
                ((rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                  rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                  rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                  rtb_TmpSignalConversionAtOrbitFollowerInport2[1]) +
                 rtb_TmpSignalConversionAtOrbitFollowerInport2[2] *
                 rtb_TmpSignalConversionAtOrbitFollowerInport2[2]);

            // Sum: '<S65>/Sum' incorporates:
            //   DataTypeConversion: '<S65>/Param1'
            //   DataTypeConversion: '<S65>/Param2'

            rtb_Switch_m2 = static_cast<real_T>(rtu_MissionInput->params.Param1)
                + static_cast<real_T>(rtu_MissionInput->params.Param2);

            // RelationalOperator: '<S65>/Relational Operator'
            localDW->InDanger = (localDW->sqrt_f <= rtb_Switch_m2);

            // DataTypeConversion: '<S65>/DoubleStatus'
            *rty_TaskStatus = static_cast<real_T>(localDW->InDanger);

            // S-Function (sfix_udelay): '<S72>/NorthSeq'
            localDW->MatrixConcatenateState[360] = rtu_SimUAVstate->North;

            // S-Function (sfix_udelay): '<S72>/EastSeq'
            localDW->MatrixConcatenateState[721] = rtu_SimUAVstate->East;

            // S-Function (sfix_udelay): '<S72>/HeightSeq'
            localDW->MatrixConcatenateState[1082] = rtu_SimUAVstate->Height;

            // S-Function (sfix_udelay): '<S72>/AirSpdSeq'
            localDW->MatrixConcatenateState[1443] = rtu_SimUAVstate->AirSpeed;

            // S-Function (sfix_udelay): '<S72>/HdgSeq'
            localDW->MatrixConcatenateState[1804] =
                rtu_SimUAVstate->HeadingAngle;

            // S-Function (sfix_udelay): '<S72>/PitchSeq'
            localDW->MatrixConcatenateState[2165] =
                rtu_SimUAVstate->FlightPathAngle;

            // S-Function (sfix_udelay): '<S72>/RollSeq'
            localDW->MatrixConcatenateState[2526] = rtu_SimUAVstate->RollAngle;
            for (coffset = 0; coffset < 360; coffset++) {
                // S-Function (sfix_udelay): '<S72>/NorthSeq'
                localDW->MatrixConcatenateState[coffset] = localDW->
                    NorthSeq_X[coffset];

                // S-Function (sfix_udelay): '<S72>/EastSeq'
                localDW->MatrixConcatenateState[static_cast<int_T>(coffset + 361)]
                    = localDW->EastSeq_X[coffset];

                // S-Function (sfix_udelay): '<S72>/HeightSeq'
                localDW->MatrixConcatenateState[static_cast<int_T>(coffset + 722)]
                    = localDW->HeightSeq_X[coffset];

                // S-Function (sfix_udelay): '<S72>/AirSpdSeq'
                localDW->MatrixConcatenateState[static_cast<int_T>(coffset +
                    1083)] = localDW->AirSpdSeq_X[coffset];

                // S-Function (sfix_udelay): '<S72>/HdgSeq'
                localDW->MatrixConcatenateState[static_cast<int_T>(coffset +
                    1444)] = localDW->HdgSeq_X[coffset];

                // S-Function (sfix_udelay): '<S72>/PitchSeq'
                localDW->MatrixConcatenateState[static_cast<int_T>(coffset +
                    1805)] = localDW->PitchSeq_X[coffset];

                // S-Function (sfix_udelay): '<S72>/RollSeq'
                localDW->MatrixConcatenateState[static_cast<int_T>(coffset +
                    2166)] = localDW->RollSeq_X[coffset];

                // S-Function (sfix_udelay): '<S72>/RollRateSeq'
                localDW->MatrixConcatenateState[static_cast<int_T>(coffset +
                    2527)] = localDW->RollRateSeq_X[coffset];
            }

            // S-Function (sfix_udelay): '<S72>/RollRateSeq'
            localDW->MatrixConcatenateState[2887] =
                rtu_SimUAVstate->RollAngleRate;

            // Outputs for Iterator SubSystem: '<S65>/MapTrack' incorporates:
            //   ForEach: '<S71>/For Each'

            for (rtb_BiasNumUAV = 0; rtb_BiasNumUAV < 361; rtb_BiasNumUAV++) {
                // Sum: '<S71>/MinusVecCenter2UAV' incorporates:
                //   BusCreator: '<S71>/Bus Creator'
                //   Concatenate: '<S72>/Matrix Concatenate State'
                //   ForEachSliceSelector generated from: '<S71>/SimUAVstate'
                //   Reshape: '<S71>/Reshape'

                rtb_MinusVecCenter2UAV[0] = localDW->
                    MatrixConcatenateState[rtb_BiasNumUAV] - rtb_Switch;

                // Sum: '<S71>/MinusVecCenter2UAV' incorporates:
                //   BusCreator: '<S71>/Bus Creator'
                //   Concatenate: '<S72>/Matrix Concatenate State'
                //   ForEachSliceSelector generated from: '<S71>/SimUAVstate'
                //   Sum: '<S97>/Sum'

                rtb_Product2 = localDW->MatrixConcatenateState
                    [static_cast<int32_T>(rtb_BiasNumUAV + 361)];

                // Sum: '<S71>/MinusVecCenter2UAV' incorporates:
                //   BusCreator: '<S71>/Bus Creator'
                //   ForEachSliceSelector generated from: '<S71>/SimUAVstate'
                //   Reshape: '<S71>/Reshape'

                rtb_MinusVecCenter2UAV[1] = rtb_Product2 - rtb_Abs1_k;

                // Sum: '<S71>/MinusVecCenter2UAV' incorporates:
                //   BusCreator: '<S71>/Bus Creator'
                //   Concatenate: '<S72>/Matrix Concatenate State'
                //   ForEachSliceSelector generated from: '<S71>/SimUAVstate'
                //   Sum: '<S97>/Sum'

                stateNew_idx_0 = localDW->MatrixConcatenateState
                    [static_cast<int32_T>(rtb_BiasNumUAV + 722)];

                // Sum: '<S71>/MinusVecCenter2UAV' incorporates:
                //   BusCreator: '<S71>/Bus Creator'
                //   ForEachSliceSelector generated from: '<S71>/SimUAVstate'
                //   Reshape: '<S71>/Reshape'

                rtb_MinusVecCenter2UAV[2] = stateNew_idx_0 - rtb_Switch_gh;

                // Sum: '<S97>/Sum' incorporates:
                //   BusCreator: '<S71>/Bus Creator'
                //   Concatenate: '<S72>/Matrix Concatenate State'
                //   ForEachSliceSelector generated from: '<S71>/SimUAVstate'
                //   Reshape: '<S71>/Reshape'

                rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Switch -
                    localDW->MatrixConcatenateState[rtb_BiasNumUAV];
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Abs1_k -
                    rtb_Product2;
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = rtb_Switch_gh
                    - stateNew_idx_0;

                // Sqrt: '<S97>/sqrt' incorporates:
                //   DotProduct: '<S97>/Dot Product'

                rtb_Sum_n = std::sqrt
                    ((rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                      rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                      rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                      rtb_TmpSignalConversionAtOrbitFollowerInport2[1]) +
                     rtb_TmpSignalConversionAtOrbitFollowerInport2[2] *
                     rtb_TmpSignalConversionAtOrbitFollowerInport2[2]);

                // RelationalOperator: '<S71>/Relational Operator'
                localDW->CoreSubsys[rtb_BiasNumUAV].InDanger = (rtb_Sum_n <=
                    rtb_Switch_m2);

                // Outputs for Enabled SubSystem: '<S71>/LinearSecantPercentage' incorporates:
                //   EnablePort: '<S98>/Enable'

                if (localDW->CoreSubsys[rtb_BiasNumUAV].InDanger) {
                    real_T absxk;
                    real_T absxk_tmp;
                    real_T absxk_tmp_0;
                    real_T absxk_tmp_1;
                    real_T absxk_tmp_2;
                    real_T absxk_tmp_3;
                    real_T absxk_tmp_4;
                    real_T absxk_tmp_5;
                    real_T normp;
                    real_T normq;
                    real_T rtb_QuaternionInterpolation_idx_1;

                    // SignalConversion generated from: '<S107>/sincos' incorporates:
                    //   BusCreator: '<S71>/Bus Creator'
                    //   Concatenate: '<S72>/Matrix Concatenate State'
                    //   ForEachSliceSelector generated from: '<S71>/SimUAVstate'

                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0] =
                        localDW->MatrixConcatenateState[static_cast<int32_T>
                        (rtb_BiasNumUAV + 1444)];
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1] =
                        localDW->MatrixConcatenateState[static_cast<int32_T>
                        (rtb_BiasNumUAV + 1805)];
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                        localDW->MatrixConcatenateState[static_cast<int32_T>
                        (rtb_BiasNumUAV + 2166)];

                    // Trigonometry: '<S107>/sincos'
                    rtb_Sum_o[0] = std::cos
                        (rtb_TmpSignalConversionAtOrbitFollowerInport2[0]);
                    rtb_Sum_dq = std::sin
                        (rtb_TmpSignalConversionAtOrbitFollowerInport2[0]);
                    rtb_Sum_o[1] = std::cos
                        (rtb_TmpSignalConversionAtOrbitFollowerInport2[1]);
                    rtb_QuaternionInterpolation_idx_2 = std::sin
                        (rtb_TmpSignalConversionAtOrbitFollowerInport2[1]);
                    rtb_Sum_o[2] = std::cos
                        (rtb_TmpSignalConversionAtOrbitFollowerInport2[2]);
                    rtb_QuaternionInterpolation_idx_3 = std::sin
                        (rtb_TmpSignalConversionAtOrbitFollowerInport2[2]);

                    // Fcn: '<S107>/Fcn11'
                    rtb_VectorConcatenate_a[0] = rtb_Sum_o[0] * rtb_Sum_o[1];

                    // Fcn: '<S107>/Fcn21' incorporates:
                    //   Fcn: '<S107>/Fcn22'

                    rtb_Product2 = rtb_QuaternionInterpolation_idx_2 *
                        rtb_QuaternionInterpolation_idx_3;
                    rtb_VectorConcatenate_a[1] = rtb_Product2 * rtb_Sum_o[0] -
                        rtb_Sum_dq * rtb_Sum_o[2];

                    // Fcn: '<S107>/Fcn31' incorporates:
                    //   Fcn: '<S107>/Fcn32'

                    t = rtb_QuaternionInterpolation_idx_2 * rtb_Sum_o[2];
                    rtb_VectorConcatenate_a[2] = t * rtb_Sum_o[0] + rtb_Sum_dq *
                        rtb_QuaternionInterpolation_idx_3;

                    // Fcn: '<S107>/Fcn12'
                    rtb_VectorConcatenate_a[3] = rtb_Sum_dq * rtb_Sum_o[1];

                    // Fcn: '<S107>/Fcn22'
                    rtb_VectorConcatenate_a[4] = rtb_Product2 * rtb_Sum_dq +
                        rtb_Sum_o[0] * rtb_Sum_o[2];

                    // Fcn: '<S107>/Fcn32'
                    rtb_VectorConcatenate_a[5] = t * rtb_Sum_dq - rtb_Sum_o[0] *
                        rtb_QuaternionInterpolation_idx_3;

                    // Fcn: '<S107>/Fcn13'
                    rtb_VectorConcatenate_a[6] =
                        -rtb_QuaternionInterpolation_idx_2;

                    // Fcn: '<S107>/Fcn23'
                    rtb_VectorConcatenate_a[7] = rtb_Sum_o[1] *
                        rtb_QuaternionInterpolation_idx_3;

                    // Fcn: '<S107>/Fcn33'
                    rtb_VectorConcatenate_a[8] = rtb_Sum_o[1] * rtb_Sum_o[2];

                    // Outputs for Atomic SubSystem: '<S98>/Projection'
                    // Product: '<S105>/Product'
                    rtb_Sum_dq = 0.0;
                    for (coffset = 0; coffset < 3; coffset++) {
                        rtb_QuaternionInterpolation_idx_2 =
                            (rtb_VectorConcatenate_a[static_cast<int32_T>
                             (coffset + 3)] * 0.0 +
                             rtb_VectorConcatenate_a[coffset]) +
                            rtb_VectorConcatenate_a[static_cast<int32_T>(coffset
                            + 6)] * 0.0;

                        // Product: '<S105>/Product' incorporates:
                        //   Concatenate: '<S119>/Vector Concatenate'
                        //   Product: '<S98>/ProductHdgVec'

                        rtb_Sum_dq += rtb_QuaternionInterpolation_idx_2 *
                            rtb_QuaternionInterpolation_idx_2;
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[coffset] =
                            rtb_QuaternionInterpolation_idx_2;
                    }

                    // Fcn: '<S120>/q3' incorporates:
                    //   Concatenate: '<S119>/Vector Concatenate'
                    //   Product: '<S105>/Product'
                    //   Product: '<S98>/ProductHdgVec'

                    rtb_q3 = rtb_Sum_dq;

                    // Product: '<S105>/Divide' incorporates:
                    //   Math: '<S105>/Transpose'

                    for (coffset = 0; coffset < 3; coffset++) {
                        rtb_Sum_dq =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[coffset]
                            / rtb_q3;
                        rtb_Switch_gs_0[static_cast<int32_T>(3 * coffset)] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                            rtb_Sum_dq;
                        rtb_Switch_gs_0[static_cast<int32_T>(static_cast<int32_T>
                            (3 * coffset) + 1)] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                            rtb_Sum_dq;
                        rtb_Switch_gs_0[static_cast<int32_T>(static_cast<int32_T>
                            (3 * coffset) + 2)] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] *
                            rtb_Sum_dq;
                    }

                    // End of Product: '<S105>/Divide'
                    // End of Outputs for SubSystem: '<S98>/Projection'
                    for (coffset = 0; coffset < 3; coffset++) {
                        // Product: '<S98>/Product'
                        rtb_ProjVec[coffset] = 0.0;
                        rtb_ProjVec[coffset] += rtb_Switch_gs_0[coffset] *
                            rtb_MinusVecCenter2UAV[0];
                        rtb_ProjVec[coffset] += rtb_Switch_gs_0
                            [static_cast<int32_T>(coffset + 3)] *
                            rtb_MinusVecCenter2UAV[1];
                        rtb_ProjVec[coffset] += rtb_Switch_gs_0
                            [static_cast<int32_T>(coffset + 6)] *
                            rtb_MinusVecCenter2UAV[2];

                        // Sum: '<S98>/MinusPerpVec'
                        rtb_PerpVec[coffset] = rtb_MinusVecCenter2UAV[coffset] -
                            rtb_ProjVec[coffset];
                    }

                    // Outputs for Atomic SubSystem: '<S98>/MagnitudePerpVec'
                    ImmedMission_MagnitudeOrigVec(rtb_PerpVec, &rtb_Sqrt);

                    // End of Outputs for SubSystem: '<S98>/MagnitudePerpVec'

                    // Sqrt: '<S98>/Sqrt' incorporates:
                    //   Math: '<S98>/SquareBigRadius'
                    //   Math: '<S98>/SquarePerpVec'
                    //   Sum: '<S98>/MinusHalfSecantMagSquare'
                    //
                    //  About '<S98>/SquareBigRadius':
                    //   Operator: magnitude^2
                    //
                    //  About '<S98>/SquarePerpVec':
                    //   Operator: magnitude^2

                    rtb_Product2 = std::sqrt(rtb_Switch_m2 * rtb_Switch_m2 -
                        rtb_Sqrt * rtb_Sqrt);

                    // Product: '<S98>/ProductMaxHdgVec'
                    rtb_Sum_dq = rtb_Product2 *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0];

                    // Sum: '<S98>/Plus'
                    rtb_Asin[0] = rtb_Sum_dq + rtb_PerpVec[0];

                    // Sum: '<S98>/Minus'
                    rtb_Asin[3] = rtb_PerpVec[0] - rtb_Sum_dq;

                    // Product: '<S98>/ProductMaxHdgVec'
                    rtb_Sum_dq = rtb_Product2 *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

                    // Sum: '<S98>/Plus'
                    rtb_Asin[1] = rtb_Sum_dq + rtb_PerpVec[1];

                    // Sum: '<S98>/Minus'
                    rtb_Asin[4] = rtb_PerpVec[1] - rtb_Sum_dq;

                    // Product: '<S98>/ProductMaxHdgVec'
                    rtb_Sum_dq = rtb_Product2 *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

                    // Sum: '<S98>/Plus'
                    rtb_Asin[2] = rtb_Sum_dq + rtb_PerpVec[2];

                    // Sum: '<S98>/Minus'
                    rtb_Asin[5] = rtb_PerpVec[2] - rtb_Sum_dq;

                    // Trigonometry: '<S98>/Asin' incorporates:
                    //   Product: '<S98>/DivideInOutVec'

                    for (coffset = 0; coffset < 6; coffset++) {
                        // Product: '<S98>/DivideInOutVec' incorporates:
                        //   Trigonometry: '<S98>/Asin'

                        rtb_Sum_dq = rtb_Asin[coffset] / rtb_Switch_m2;
                        if (rtb_Sum_dq > 1.0) {
                            rtb_Sum_dq = 1.0;
                        } else if (rtb_Sum_dq < -1.0) {
                            rtb_Sum_dq = -1.0;
                        }

                        rtb_Asin[coffset] = std::asin(rtb_Sum_dq);
                    }

                    // End of Trigonometry: '<S98>/Asin'

                    // Selector: '<S98>/SelectIn' incorporates:
                    //   Trigonometry: '<S98>/Asin'

                    rtb_SelectIn[0] = rtb_Asin[3];
                    rtb_SelectIn[1] = rtb_Asin[4];
                    rtb_SelectIn[2] = rtb_Asin[5];

                    // Outputs for Atomic SubSystem: '<S98>/Vec2QuatIn'
                    ImmedMission_Vec2QuatIn(rtb_SelectIn, &rtb_q0, &rtb_q1,
                                            &rtb_q2, &rtb_q3);

                    // End of Outputs for SubSystem: '<S98>/Vec2QuatIn'

                    // Selector: '<S98>/SelectOut' incorporates:
                    //   Trigonometry: '<S98>/Asin'

                    rtb_SelectOut[0] = rtb_Asin[0];
                    rtb_SelectOut[1] = rtb_Asin[1];
                    rtb_SelectOut[2] = rtb_Asin[2];

                    // Outputs for Atomic SubSystem: '<S98>/Vec2QuatOut'
                    ImmedMission_Vec2QuatIn(rtb_SelectOut, &rtb_ProductE, &rtb_U,
                                            &rtb_ProductN, &rtb_Product1_l);

                    // End of Outputs for SubSystem: '<S98>/Vec2QuatOut'

                    // Outputs for Atomic SubSystem: '<S98>/MagnitudeProjVec'
                    ImmedMission_MagnitudeOrigVec(rtb_ProjVec, &rtb_Sqrt);

                    // End of Outputs for SubSystem: '<S98>/MagnitudeProjVec'

                    // Product: '<S98>/ProductSign' incorporates:
                    //   Product: '<S98>/Product'

                    rtb_Sum_dq = (rtb_ProjVec[0] *
                                  rtb_TmpSignalConversionAtOrbitFollowerInport2
                                  [0] + rtb_ProjVec[1] *
                                  rtb_TmpSignalConversionAtOrbitFollowerInport2
                                  [1]) + rtb_ProjVec[2] *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

                    // Signum: '<S98>/Sign' incorporates:
                    //   Product: '<S98>/ProductSign'

                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(std::isnan(rtb_Sum_dq)) ^ 1))) {
                        if (rtb_Sum_dq < 0.0) {
                            rtb_Sum_dq = -1.0;
                        } else {
                            rtb_Sum_dq = static_cast<real_T>(rtb_Sum_dq > 0.0);
                        }
                    }

                    // End of Signum: '<S98>/Sign'

                    // Product: '<S98>/Divide' incorporates:
                    //   Gain: '<S98>/Double'
                    //   Product: '<S98>/ProductMagProj'
                    //   Sum: '<S98>/Sum'

                    rtb_Sum_dq = (rtb_Sqrt * rtb_Sum_dq + rtb_Product2) / (2.0 *
                        rtb_Product2);

                    // Saturate: '<S98>/Saturation'
                    if (rtb_Sum_dq > 1.0) {
                        rtb_Sum_dq = 1.0;
                    } else if (rtb_Sum_dq < 0.0) {
                        rtb_Sum_dq = 0.0;
                    }

                    // End of Saturate: '<S98>/Saturation'

                    // QuatInterp: '<S98>/Quaternion Interpolation'
                    rtb_TmpSignalConversionAtOrbitFollowerInport1[0] = rtb_q0;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1[1] = rtb_q1;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1[2] = rtb_q2;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1[3] = rtb_q3;
                    rtb_QuaternionInterpolation_idx_0 = rtb_ProductE;
                    rtb_QuaternionInterpolation_idx_1 = rtb_U;
                    rtb_QuaternionInterpolation_idx_2 = rtb_ProductN;
                    rtb_QuaternionInterpolation_idx_3 = rtb_Product1_l;
                    rtb_Product2 = 3.3121686421112381E-170;
                    absxk = std::abs(rtb_q0);
                    if (absxk > 3.3121686421112381E-170) {
                        normp = 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / 3.3121686421112381E-170;
                        normp = t * t;
                    }

                    absxk_tmp_0 = std::abs(rtb_q1);
                    if (absxk_tmp_0 > rtb_Product2) {
                        t = rtb_Product2 / absxk_tmp_0;
                        normp = normp * t * t + 1.0;
                        rtb_Product2 = absxk_tmp_0;
                    } else {
                        t = absxk_tmp_0 / rtb_Product2;
                        normp += t * t;
                    }

                    absxk_tmp_2 = std::abs(rtb_q2);
                    if (absxk_tmp_2 > rtb_Product2) {
                        t = rtb_Product2 / absxk_tmp_2;
                        normp = normp * t * t + 1.0;
                        rtb_Product2 = absxk_tmp_2;
                    } else {
                        t = absxk_tmp_2 / rtb_Product2;
                        normp += t * t;
                    }

                    absxk_tmp_4 = std::abs(rtb_q3);
                    if (absxk_tmp_4 > rtb_Product2) {
                        t = rtb_Product2 / absxk_tmp_4;
                        normp = normp * t * t + 1.0;
                        rtb_Product2 = absxk_tmp_4;
                    } else {
                        t = absxk_tmp_4 / rtb_Product2;
                        normp += t * t;
                    }

                    normp = rtb_Product2 * std::sqrt(normp);
                    rtb_Product2 = 3.3121686421112381E-170;
                    absxk_tmp = std::abs(rtb_ProductE);
                    if (absxk_tmp > 3.3121686421112381E-170) {
                        normq = 1.0;
                        rtb_Product2 = absxk_tmp;
                    } else {
                        t = absxk_tmp / 3.3121686421112381E-170;
                        normq = t * t;
                    }

                    absxk_tmp_1 = std::abs(rtb_U);
                    if (absxk_tmp_1 > rtb_Product2) {
                        t = rtb_Product2 / absxk_tmp_1;
                        normq = normq * t * t + 1.0;
                        rtb_Product2 = absxk_tmp_1;
                    } else {
                        t = absxk_tmp_1 / rtb_Product2;
                        normq += t * t;
                    }

                    absxk_tmp_3 = std::abs(rtb_ProductN);
                    if (absxk_tmp_3 > rtb_Product2) {
                        t = rtb_Product2 / absxk_tmp_3;
                        normq = normq * t * t + 1.0;
                        rtb_Product2 = absxk_tmp_3;
                    } else {
                        t = absxk_tmp_3 / rtb_Product2;
                        normq += t * t;
                    }

                    absxk_tmp_5 = std::abs(rtb_Product1_l);
                    if (absxk_tmp_5 > rtb_Product2) {
                        t = rtb_Product2 / absxk_tmp_5;
                        normq = normq * t * t + 1.0;
                        rtb_Product2 = absxk_tmp_5;
                    } else {
                        t = absxk_tmp_5 / rtb_Product2;
                        normq += t * t;
                    }

                    normq = rtb_Product2 * std::sqrt(normq);
                    if (static_cast<boolean_T>(static_cast<int32_T>((normp >
                            1.0000000149011612) | (normp < 0.99999998509883881))))
                    {
                        rtb_Product2 = 3.3121686421112381E-170;
                        if (absxk > 3.3121686421112381E-170) {
                            normp = 1.0;
                            rtb_Product2 = absxk;
                        } else {
                            t = absxk / 3.3121686421112381E-170;
                            normp = t * t;
                        }

                        if (absxk_tmp_0 > rtb_Product2) {
                            t = rtb_Product2 / absxk_tmp_0;
                            normp = normp * t * t + 1.0;
                            rtb_Product2 = absxk_tmp_0;
                        } else {
                            t = absxk_tmp_0 / rtb_Product2;
                            normp += t * t;
                        }

                        if (absxk_tmp_2 > rtb_Product2) {
                            t = rtb_Product2 / absxk_tmp_2;
                            normp = normp * t * t + 1.0;
                            rtb_Product2 = absxk_tmp_2;
                        } else {
                            t = absxk_tmp_2 / rtb_Product2;
                            normp += t * t;
                        }

                        if (absxk_tmp_4 > rtb_Product2) {
                            t = rtb_Product2 / absxk_tmp_4;
                            normp = normp * t * t + 1.0;
                            rtb_Product2 = absxk_tmp_4;
                        } else {
                            t = absxk_tmp_4 / rtb_Product2;
                            normp += t * t;
                        }

                        normp = rtb_Product2 * std::sqrt(normp);
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[0] =
                            rtb_q0 / normp;
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[1] =
                            rtb_q1 / normp;
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[2] =
                            rtb_q2 / normp;
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[3] =
                            rtb_q3 / normp;
                    }

                    if (static_cast<boolean_T>(static_cast<int32_T>((normq >
                            1.0000000149011612) | (normq < 0.99999998509883881))))
                    {
                        rtb_Product2 = 3.3121686421112381E-170;
                        if (absxk_tmp > 3.3121686421112381E-170) {
                            normp = 1.0;
                            rtb_Product2 = absxk_tmp;
                        } else {
                            t = absxk_tmp / 3.3121686421112381E-170;
                            normp = t * t;
                        }

                        if (absxk_tmp_1 > rtb_Product2) {
                            t = rtb_Product2 / absxk_tmp_1;
                            normp = normp * t * t + 1.0;
                            rtb_Product2 = absxk_tmp_1;
                        } else {
                            t = absxk_tmp_1 / rtb_Product2;
                            normp += t * t;
                        }

                        if (absxk_tmp_3 > rtb_Product2) {
                            t = rtb_Product2 / absxk_tmp_3;
                            normp = normp * t * t + 1.0;
                            rtb_Product2 = absxk_tmp_3;
                        } else {
                            t = absxk_tmp_3 / rtb_Product2;
                            normp += t * t;
                        }

                        if (absxk_tmp_5 > rtb_Product2) {
                            t = rtb_Product2 / absxk_tmp_5;
                            normp = normp * t * t + 1.0;
                            rtb_Product2 = absxk_tmp_5;
                        } else {
                            t = absxk_tmp_5 / rtb_Product2;
                            normp += t * t;
                        }

                        normp = rtb_Product2 * std::sqrt(normp);
                        rtb_QuaternionInterpolation_idx_0 = rtb_ProductE / normp;
                        rtb_QuaternionInterpolation_idx_1 = rtb_U / normp;
                        rtb_QuaternionInterpolation_idx_2 = rtb_ProductN / normp;
                        rtb_QuaternionInterpolation_idx_3 = rtb_Product1_l /
                            normp;
                    }

                    if (((rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                            rtb_QuaternionInterpolation_idx_0 +
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[1] *
                            rtb_QuaternionInterpolation_idx_1) +
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[2] *
                            rtb_QuaternionInterpolation_idx_2) +
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[3] *
                            rtb_QuaternionInterpolation_idx_3 < 0.0) {
                        rtb_QuaternionInterpolation_idx_0 =
                            -rtb_QuaternionInterpolation_idx_0;
                        rtb_QuaternionInterpolation_idx_1 =
                            -rtb_QuaternionInterpolation_idx_1;
                        rtb_QuaternionInterpolation_idx_2 =
                            -rtb_QuaternionInterpolation_idx_2;
                        rtb_QuaternionInterpolation_idx_3 =
                            -rtb_QuaternionInterpolation_idx_3;
                    }

                    absxk_tmp_2 =
                        ((rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                          rtb_QuaternionInterpolation_idx_0 -
                          -rtb_TmpSignalConversionAtOrbitFollowerInport1[1] *
                          rtb_QuaternionInterpolation_idx_1) -
                         -rtb_TmpSignalConversionAtOrbitFollowerInport1[2] *
                         rtb_QuaternionInterpolation_idx_2) -
                        -rtb_TmpSignalConversionAtOrbitFollowerInport1[3] *
                        rtb_QuaternionInterpolation_idx_3;
                    absxk_tmp_0 =
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                         rtb_QuaternionInterpolation_idx_1 +
                         rtb_QuaternionInterpolation_idx_0 *
                         -rtb_TmpSignalConversionAtOrbitFollowerInport1[1]) +
                        (-rtb_TmpSignalConversionAtOrbitFollowerInport1[2] *
                         rtb_QuaternionInterpolation_idx_3 -
                         rtb_QuaternionInterpolation_idx_2 *
                         -rtb_TmpSignalConversionAtOrbitFollowerInport1[3]);
                    normq = (rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                             rtb_QuaternionInterpolation_idx_2 +
                             rtb_QuaternionInterpolation_idx_0 *
                             -rtb_TmpSignalConversionAtOrbitFollowerInport1[2])
                        + (rtb_QuaternionInterpolation_idx_1 *
                           -rtb_TmpSignalConversionAtOrbitFollowerInport1[3] -
                           -rtb_TmpSignalConversionAtOrbitFollowerInport1[1] *
                           rtb_QuaternionInterpolation_idx_3);
                    rtb_QuaternionInterpolation_idx_3 =
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                         rtb_QuaternionInterpolation_idx_3 +
                         rtb_QuaternionInterpolation_idx_0 *
                         -rtb_TmpSignalConversionAtOrbitFollowerInport1[3]) +
                        (-rtb_TmpSignalConversionAtOrbitFollowerInport1[1] *
                         rtb_QuaternionInterpolation_idx_2 -
                         rtb_QuaternionInterpolation_idx_1 *
                         -rtb_TmpSignalConversionAtOrbitFollowerInport1[2]);
                    rtb_Product2 = 3.3121686421112381E-170;
                    absxk = std::abs(absxk_tmp_2);
                    if (absxk > 3.3121686421112381E-170) {
                        normp = 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / 3.3121686421112381E-170;
                        normp = t * t;
                    }

                    absxk = std::abs(absxk_tmp_0);
                    if (absxk > rtb_Product2) {
                        t = rtb_Product2 / absxk;
                        normp = normp * t * t + 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / rtb_Product2;
                        normp += t * t;
                    }

                    absxk = std::abs(normq);
                    if (absxk > rtb_Product2) {
                        t = rtb_Product2 / absxk;
                        normp = normp * t * t + 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / rtb_Product2;
                        normp += t * t;
                    }

                    absxk = std::abs(rtb_QuaternionInterpolation_idx_3);
                    if (absxk > rtb_Product2) {
                        t = rtb_Product2 / absxk;
                        normp = normp * t * t + 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / rtb_Product2;
                        normp += t * t;
                    }

                    normp = rtb_Product2 * std::sqrt(normp);
                    rtb_QuaternionInterpolation_idx_0 = absxk_tmp_2 / normp;
                    absxk_tmp_0 /= normp;
                    rtb_QuaternionInterpolation_idx_1 = 0.0;
                    absxk_tmp_2 = normq / normp;
                    rtb_QuaternionInterpolation_idx_2 = 0.0;
                    absxk_tmp_4 = rtb_QuaternionInterpolation_idx_3 / normp;
                    rtb_QuaternionInterpolation_idx_3 = 0.0;
                    rtb_Product2 = 3.3121686421112381E-170;
                    absxk = std::abs(absxk_tmp_0);
                    if (absxk > 3.3121686421112381E-170) {
                        normp = 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / 3.3121686421112381E-170;
                        normp = t * t;
                    }

                    absxk = std::abs(absxk_tmp_2);
                    if (absxk > rtb_Product2) {
                        t = rtb_Product2 / absxk;
                        normp = normp * t * t + 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / rtb_Product2;
                        normp += t * t;
                    }

                    absxk = std::abs(absxk_tmp_4);
                    if (absxk > rtb_Product2) {
                        t = rtb_Product2 / absxk;
                        normp = normp * t * t + 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / rtb_Product2;
                        normp += t * t;
                    }

                    normp = rtb_Product2 * std::sqrt(normp);
                    normq = rt_atan2d_snf(normp,
                                          rtb_QuaternionInterpolation_idx_0);
                    if (normp != 0.0) {
                        rtb_QuaternionInterpolation_idx_1 = absxk_tmp_0 / normp *
                            normq;
                        rtb_QuaternionInterpolation_idx_2 = absxk_tmp_2 / normp *
                            normq;
                        rtb_QuaternionInterpolation_idx_3 = absxk_tmp_4 / normp *
                            normq;
                    }

                    rtb_QuaternionInterpolation_idx_0 = rtb_Sum_dq * 0.0;

                    // QuatInterp: '<S98>/Quaternion Interpolation'
                    rtb_QuaternionInterpolation_idx_1 *= rtb_Sum_dq;
                    rtb_QuaternionInterpolation_idx_2 *= rtb_Sum_dq;
                    rtb_QuaternionInterpolation_idx_3 *= rtb_Sum_dq;
                    rtb_Product2 = 3.3121686421112381E-170;
                    absxk = std::abs(rtb_QuaternionInterpolation_idx_1);
                    if (absxk > 3.3121686421112381E-170) {
                        normq = 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / 3.3121686421112381E-170;
                        normq = t * t;
                    }

                    absxk = std::abs(rtb_QuaternionInterpolation_idx_2);
                    if (absxk > rtb_Product2) {
                        t = rtb_Product2 / absxk;
                        normq = normq * t * t + 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / rtb_Product2;
                        normq += t * t;
                    }

                    absxk = std::abs(rtb_QuaternionInterpolation_idx_3);
                    if (absxk > rtb_Product2) {
                        t = rtb_Product2 / absxk;
                        normq = normq * t * t + 1.0;
                        rtb_Product2 = absxk;
                    } else {
                        t = absxk / rtb_Product2;
                        normq += t * t;
                    }

                    normq = rtb_Product2 * std::sqrt(normq);
                    if (normq == 0.0) {
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = 0.0;
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = 0.0;
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = 0.0;
                    } else {
                        rtb_Sum_dq = std::exp(rtb_QuaternionInterpolation_idx_0)
                            * std::sin(normq);
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] =
                            rtb_Sum_dq * rtb_QuaternionInterpolation_idx_1 /
                            normq;
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1] =
                            rtb_Sum_dq * rtb_QuaternionInterpolation_idx_2 /
                            normq;
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                            rtb_Sum_dq * rtb_QuaternionInterpolation_idx_3 /
                            normq;
                    }

                    absxk_tmp_2 = std::exp(rtb_QuaternionInterpolation_idx_0) *
                        std::cos(normq);
                    rtb_QuaternionInterpolation_idx_0 =
                        ((rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                          absxk_tmp_2 -
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                          rtb_TmpSignalConversionAtOrbitFollowerInport1[1]) -
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport1[2]) -
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2] *
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[3];
                    rtb_QuaternionInterpolation_idx_1 =
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                         absxk_tmp_2 *
                         rtb_TmpSignalConversionAtOrbitFollowerInport1[1]) +
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1[2] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[2] -
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport1[3]);
                    rtb_QuaternionInterpolation_idx_2 =
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[1] +
                         absxk_tmp_2 *
                         rtb_TmpSignalConversionAtOrbitFollowerInport1[2]) +
                        (rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport1[3] -
                         rtb_TmpSignalConversionAtOrbitFollowerInport1[1] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[2]);
                    rtb_QuaternionInterpolation_idx_3 =
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1[0] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[2] +
                         absxk_tmp_2 *
                         rtb_TmpSignalConversionAtOrbitFollowerInport1[3]) +
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1[1] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[1] -
                         rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                         rtb_TmpSignalConversionAtOrbitFollowerInport1[2]);

                    // Product: '<S112>/Product1' incorporates:
                    //   Product: '<S118>/Product2'

                    rtb_Product1_l = rtb_QuaternionInterpolation_idx_2 *
                        rtb_QuaternionInterpolation_idx_2;

                    // Product: '<S98>/ProductN' incorporates:
                    //   Product: '<S118>/Product3'

                    rtb_ProductN = rtb_QuaternionInterpolation_idx_3 *
                        rtb_QuaternionInterpolation_idx_3;

                    // Sqrt: '<S117>/sqrt' incorporates:
                    //   Product: '<S118>/Product'
                    //   Product: '<S118>/Product1'
                    //   Sum: '<S118>/Sum'

                    rtb_Sum_dq = std::sqrt(((rtb_QuaternionInterpolation_idx_0 *
                        rtb_QuaternionInterpolation_idx_0 +
                        rtb_QuaternionInterpolation_idx_1 *
                        rtb_QuaternionInterpolation_idx_1) + rtb_Product1_l) +
                                           rtb_ProductN);

                    // Product: '<S98>/ProductN' incorporates:
                    //   Product: '<S112>/Product'

                    rtb_ProductN = rtb_QuaternionInterpolation_idx_0 /
                        rtb_Sum_dq;

                    // Product: '<S112>/Product1'
                    rtb_Product1_l = rtb_QuaternionInterpolation_idx_1 /
                        rtb_Sum_dq;

                    // Product: '<S112>/Product2'
                    rtb_Product2 = rtb_QuaternionInterpolation_idx_2 /
                        rtb_Sum_dq;

                    // Product: '<S112>/Product3'
                    rtb_Sum_dq = rtb_QuaternionInterpolation_idx_3 / rtb_Sum_dq;

                    // Trigonometry: '<S98>/Sin' incorporates:
                    //   Fcn: '<S106>/fcn1'

                    rtb_U = (rtb_Product1_l * rtb_Product2 + rtb_ProductN *
                             rtb_Sum_dq) * 2.0;

                    // Product: '<S98>/ProductE' incorporates:
                    //   Fcn: '<S106>/fcn2'

                    rtb_ProductE = ((rtb_ProductN * rtb_ProductN +
                                     rtb_Product1_l * rtb_Product1_l) -
                                    rtb_Product2 * rtb_Product2) - rtb_Sum_dq *
                        rtb_Sum_dq;

                    // Trigonometry: '<S111>/Trigonometric Function1'
                    rtb_VectorConcatenate[0] = rt_atan2d_snf(rtb_U, rtb_ProductE);

                    // Fcn: '<S106>/fcn3'
                    absxk = (rtb_Product1_l * rtb_Sum_dq - rtb_ProductN *
                             rtb_Product2) * -2.0;

                    // If: '<S113>/If'
                    if (absxk > 1.0) {
                        // Outputs for IfAction SubSystem: '<S113>/If Action Subsystem' incorporates:
                        //   ActionPort: '<S114>/Action Port'

                        // Product: '<S98>/ProductE' incorporates:
                        //   Constant: '<S114>/Constant'

                        rtb_ProductE = 1.0;

                        // End of Outputs for SubSystem: '<S113>/If Action Subsystem' 
                    } else if (absxk < -1.0) {
                        // Outputs for IfAction SubSystem: '<S113>/If Action Subsystem1' incorporates:
                        //   ActionPort: '<S115>/Action Port'

                        // Product: '<S98>/ProductE' incorporates:
                        //   Constant: '<S115>/Constant'

                        rtb_ProductE = 1.0;

                        // End of Outputs for SubSystem: '<S113>/If Action Subsystem1' 
                    } else {
                        // Outputs for IfAction SubSystem: '<S113>/If Action Subsystem2' incorporates:
                        //   ActionPort: '<S116>/Action Port'

                        // Product: '<S98>/ProductE' incorporates:
                        //   SignalConversion generated from: '<S116>/In'

                        rtb_ProductE = absxk;

                        // End of Outputs for SubSystem: '<S113>/If Action Subsystem2' 
                    }

                    // End of If: '<S113>/If'

                    // Trigonometry: '<S111>/trigFcn'
                    if (rtb_ProductE > 1.0) {
                        rtb_Product2 = 1.0;
                    } else if (rtb_ProductE < -1.0) {
                        rtb_Product2 = -1.0;
                    } else {
                        rtb_Product2 = rtb_ProductE;
                    }

                    rtb_VectorConcatenate[1] = std::asin(rtb_Product2);

                    // End of Trigonometry: '<S111>/trigFcn'

                    // Outputs for Atomic SubSystem: '<S98>/GenAzimuthElevation' 
                    // Outputs for Atomic SubSystem: '<S101>/Magnitude'
                    ImmedMission_Magnitude(&rtb_MinusVecCenter2UAV[0], &rtb_Sqrt);

                    // End of Outputs for SubSystem: '<S101>/Magnitude'

                    // MATLAB Function: '<S98>/AngdiffAzimuth' incorporates:
                    //   Sum: '<S71>/MinusVecCenter2UAV'
                    //   Trigonometry: '<S101>/Atan2Azimuth'

                    // MATLAB Function 'ImmedMissionGuidance/Mode129_CollAvoidance/Mode129_Variant/Mode129/MapTrack/LinearSecantPercentage/AngdiffAzimuth': '<S99>:1' 
                    // '<S99>:1:3'
                    rtb_Sum_dq = rt_atan2d_snf(rtb_MinusVecCenter2UAV[1],
                        rtb_MinusVecCenter2UAV[0]) - rtb_VectorConcatenate[0];

                    // End of Outputs for SubSystem: '<S98>/GenAzimuthElevation' 
                    if (std::abs(rtb_Sum_dq) > 3.1415926535897931) {
                        if (std::isnan(rtb_Sum_dq + 3.1415926535897931)) {
                            rtb_Product2 = (rtNaN);
                        } else if (std::isinf(rtb_Sum_dq + 3.1415926535897931))
                        {
                            rtb_Product2 = (rtNaN);
                        } else if (rtb_Sum_dq + 3.1415926535897931 == 0.0) {
                            rtb_Product2 = 0.0;
                        } else {
                            rtb_Product2 = std::fmod(rtb_Sum_dq +
                                3.1415926535897931, 6.2831853071795862);
                            rtb_Compare_lh = (rtb_Product2 == 0.0);
                            if (static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_Compare_lh) ^ 1)))
                            {
                                absxk = std::abs((rtb_Sum_dq +
                                                  3.1415926535897931) /
                                                 6.2831853071795862);
                                rtb_Compare_lh = static_cast<boolean_T>(
                                    static_cast<int32_T>((std::abs(absxk - std::
                                    floor(absxk + 0.5)) > 2.2204460492503131E-16
                                    * absxk) ^ 1));
                            }

                            if (rtb_Compare_lh) {
                                rtb_Product2 = 0.0;
                            } else if (rtb_Sum_dq + 3.1415926535897931 < 0.0) {
                                rtb_Product2 += 6.2831853071795862;
                            }
                        }

                        if (static_cast<boolean_T>(static_cast<int32_T>
                                                   ((rtb_Sum_dq +
                                3.1415926535897931 > 0.0) & (rtb_Product2 == 0.0))))
                        {
                            rtb_Product2 = 6.2831853071795862;
                        }

                        rtb_Sum_dq = rtb_Product2 - 3.1415926535897931;
                    }

                    // End of MATLAB Function: '<S98>/AngdiffAzimuth'

                    // Outputs for Atomic SubSystem: '<S98>/GenAzimuthElevation' 
                    // MATLAB Function: '<S98>/AngdiffElevation' incorporates:
                    //   Trigonometry: '<S101>/Atan2Elevation'

                    // MATLAB Function 'ImmedMissionGuidance/Mode129_CollAvoidance/Mode129_Variant/Mode129/MapTrack/LinearSecantPercentage/AngdiffElevation': '<S100>:1' 
                    // '<S100>:1:3'
                    t = rt_atan2d_snf(rtb_MinusVecCenter2UAV[2], rtb_Sqrt) -
                        rtb_VectorConcatenate[1];

                    // End of Outputs for SubSystem: '<S98>/GenAzimuthElevation' 
                    if (std::abs(t) > 3.1415926535897931) {
                        if (std::isnan(t + 3.1415926535897931)) {
                            rtb_Product2 = (rtNaN);
                        } else if (std::isinf(t + 3.1415926535897931)) {
                            rtb_Product2 = (rtNaN);
                        } else if (t + 3.1415926535897931 == 0.0) {
                            rtb_Product2 = 0.0;
                        } else {
                            rtb_Product2 = std::fmod(t + 3.1415926535897931,
                                6.2831853071795862);
                            rtb_Compare_lh = (rtb_Product2 == 0.0);
                            if (static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_Compare_lh) ^ 1)))
                            {
                                absxk = std::abs((t + 3.1415926535897931) /
                                                 6.2831853071795862);
                                rtb_Compare_lh = static_cast<boolean_T>(
                                    static_cast<int32_T>((std::abs(absxk - std::
                                    floor(absxk + 0.5)) > 2.2204460492503131E-16
                                    * absxk) ^ 1));
                            }

                            if (rtb_Compare_lh) {
                                rtb_Product2 = 0.0;
                            } else if (t + 3.1415926535897931 < 0.0) {
                                rtb_Product2 += 6.2831853071795862;
                            }
                        }

                        if (static_cast<boolean_T>(static_cast<int32_T>((t +
                                3.1415926535897931 > 0.0) & (rtb_Product2 == 0.0))))
                        {
                            rtb_Product2 = 6.2831853071795862;
                        }

                        t = rtb_Product2 - 3.1415926535897931;
                    }

                    // End of MATLAB Function: '<S98>/AngdiffElevation'

                    // SignalConversion generated from: '<S98>/Azimuth' incorporates:
                    //   Constant: '<S98>/Ones'
                    //   Constant: '<S98>/Zeros'

                    rtb_Sum1[0] = 0.0;
                    rtb_Sum1[1] = 1.0;

                    // Product: '<S98>/ProductE' incorporates:
                    //   Sum: '<S98>/SumAzimuth'

                    rtb_ProductE = rtb_VectorConcatenate[0] + rtb_Sum_dq;

                    // SignalConversion generated from: '<S98>/Azimuth'
                    xyCenter[0] = rtb_VectorConcatenate[0];
                    xyCenter[1] = rtb_ProductE;

                    // S-Function (sfix_look1_dyn): '<S98>/Azimuth' incorporates:
                    //   Constant: '<S98>/Constant'

                    // Dynamic Look-Up Table Block: '<S98>/Azimuth'
                    //  Input0  Data Type:  Floating Point real_T
                    //  Input1  Data Type:  Floating Point real_T
                    //  Input2  Data Type:  Floating Point real_T
                    //  Output0 Data Type:  Floating Point real_T
                    //  Lookup Method: Linear_Endpoint
                    //

                    LookUp_real_T_real_T( &(rtb_ProductE), &xyCenter[0], 0.6,
                                         &rtb_Sum1[0], 1U);

                    // Trigonometry: '<S98>/Sin' incorporates:
                    //   Sum: '<S98>/SumElevation'

                    rtb_U = t + rtb_VectorConcatenate[1];

                    // SignalConversion generated from: '<S98>/Elevation'
                    xyCenter[0] = rtb_VectorConcatenate[1];
                    xyCenter[1] = rtb_U;

                    // S-Function (sfix_look1_dyn): '<S98>/Elevation' incorporates:
                    //   Constant: '<S98>/Constant'

                    // Dynamic Look-Up Table Block: '<S98>/Elevation'
                    //  Input0  Data Type:  Floating Point real_T
                    //  Input1  Data Type:  Floating Point real_T
                    //  Input2  Data Type:  Floating Point real_T
                    //  Output0 Data Type:  Floating Point real_T
                    //  Lookup Method: Linear_Endpoint
                    //

                    LookUp_real_T_real_T( &(rtb_U), &xyCenter[0], 0.6,
                                         &rtb_Sum1[0], 1U);

                    // Product: '<S98>/ProductN' incorporates:
                    //   Trigonometry: '<S98>/Cos'

                    rtb_ProductN = std::cos(rtb_U);

                    // Trigonometry: '<S98>/CosAzimuth'
                    rtb_Sum_dq = std::cos(rtb_ProductE);

                    // Outputs for Atomic SubSystem: '<S98>/MagnitudeOrigVec'
                    ImmedMission_MagnitudeOrigVec(rtb_MinusVecCenter2UAV,
                        &rtb_Sqrt);

                    // End of Outputs for SubSystem: '<S98>/MagnitudeOrigVec'

                    // Product: '<S98>/ProductE' incorporates:
                    //   Trigonometry: '<S98>/SinAzimuth'

                    rtb_ProductE = std::sin(rtb_ProductE) * rtb_ProductN;

                    // Product: '<S98>/ProductN'
                    rtb_ProductN *= rtb_Sum_dq;

                    // Trigonometry: '<S98>/Sin'
                    rtb_U = std::sin(rtb_U);

                    // Product: '<S98>/ProductTargetVec'
                    localDW->CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[0] =
                        rtb_Sqrt * rtb_ProductN;
                    localDW->CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[1] =
                        rtb_Sqrt * rtb_ProductE;
                    localDW->CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[2] =
                        rtb_Sqrt * rtb_U;

                    // Product: '<S71>/Scale2ExpansionChannel' incorporates:
                    //   DataTypeConversion: '<S65>/Param2'
                    //   Switch: '<S71>/Switch'

                    rtb_Product2 = static_cast<real_T>
                        (rtu_MissionInput->params.Param2) / rtb_Switch_m2;

                    // Switch: '<S71>/Switch' incorporates:
                    //   DataTypeConversion: '<S65>/Param1'
                    //   Product: '<S71>/Scale2DangerSphere'
                    //   Product: '<S71>/Scale2ExpansionChannel'
                    //   Reshape: '<S71>/Reshape'
                    //   Sum: '<S71>/SumTargetPos'

                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = (
                        static_cast<real_T>(rtu_MissionInput->params.Param1) *
                        localDW->CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[0] /
                        rtb_Sum_n + rtb_Product2 * localDW->
                        CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[0]) +
                        rtb_Switch;
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = (
                        static_cast<real_T>(rtu_MissionInput->params.Param1) *
                        localDW->CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[1] /
                        rtb_Sum_n + rtb_Product2 * localDW->
                        CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[1]) +
                        rtb_Abs1_k;
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = (
                        static_cast<real_T>(rtu_MissionInput->params.Param1) *
                        localDW->CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[2] /
                        rtb_Sum_n + rtb_Product2 * localDW->
                        CoreSubsys[rtb_BiasNumUAV].ProductTargetVec[2]) +
                        rtb_Switch_gh;
                } else {
                    // Switch: '<S71>/Switch' incorporates:
                    //   BusCreator: '<S71>/Bus Creator'
                    //   Concatenate: '<S72>/Matrix Concatenate State'
                    //   ForEachSliceSelector generated from: '<S71>/SimUAVstate'

                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0] =
                        localDW->MatrixConcatenateState[rtb_BiasNumUAV];
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1] =
                        rtb_Product2;
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                        stateNew_idx_0;
                }

                // End of Outputs for SubSystem: '<S71>/LinearSecantPercentage'

                // Sum: '<S71>/Plus' incorporates:
                //   BusAssignment: '<S71>/Bus Assignment'
                //   Gain: '<S71>/ShrinkHeight'
                //   QuatInterp: '<S98>/Quaternion Interpolation'
                //   Sum: '<S71>/Minus'
                //   Sum: '<S71>/MinusVecCenter2UAV'

                rtb_Sum_n = (rtb_TmpSignalConversionAtOrbitFollowerInport2[2] -
                             stateNew_idx_0) * 0.2 + stateNew_idx_0;

                // ForEachSliceAssignment generated from: '<S71>/hisTrack' incorporates:
                //   BusAssignment: '<S71>/AssignmentHeight'
                //   BusAssignment: '<S71>/Bus Assignment'
                //   Gain: '<S71>/TrackInvH'

                localDW->ImpAsg_InsertedFor_hisTrack_at_inport_0[rtb_BiasNumUAV]
                    = rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                localDW->ImpAsg_InsertedFor_hisTrack_at_inport_0
                    [static_cast<int32_T>(rtb_BiasNumUAV + 361)] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                localDW->ImpAsg_InsertedFor_hisTrack_at_inport_0
                    [static_cast<int32_T>(rtb_BiasNumUAV + 722)] = -rtb_Sum_n;

                // ForEachSliceAssignment generated from: '<S71>/CollAvoidSimUAV' incorporates:
                //   BusAssignment: '<S71>/AssignmentHeight'
                //   BusAssignment: '<S71>/Bus Assignment'
                //   BusCreator: '<S71>/Bus Creator'
                //   Concatenate: '<S72>/Matrix Concatenate State'

                localDW->
                    ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[rtb_BiasNumUAV]
                    .North = rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                localDW->
                    ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[rtb_BiasNumUAV]
                    .East = rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                localDW->
                    ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[rtb_BiasNumUAV]
                    .Height = rtb_Sum_n;
                localDW->
                    ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[rtb_BiasNumUAV]
                    .AirSpeed = localDW->MatrixConcatenateState
                    [static_cast<int32_T>(rtb_BiasNumUAV + 1083)];
                localDW->
                    ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[rtb_BiasNumUAV]
                    .HeadingAngle = localDW->MatrixConcatenateState
                    [static_cast<int32_T>(rtb_BiasNumUAV + 1444)];
                localDW->
                    ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[rtb_BiasNumUAV]
                    .FlightPathAngle = localDW->MatrixConcatenateState[
                    static_cast<int32_T>(rtb_BiasNumUAV + 1805)];
                localDW->
                    ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[rtb_BiasNumUAV]
                    .RollAngle = localDW->MatrixConcatenateState
                    [static_cast<int32_T>(rtb_BiasNumUAV + 2166)];
                localDW->
                    ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[rtb_BiasNumUAV]
                    .RollAngleRate = localDW->MatrixConcatenateState[
                    static_cast<int32_T>(rtb_BiasNumUAV + 2527)];
            }

            // End of Outputs for SubSystem: '<S65>/MapTrack'

            // S-Function (sfix_udelay): '<S72>/InDangerSequence' incorporates:
            //   QuatInterp: '<S98>/Quaternion Interpolation'
            //   Sum: '<S71>/MinusVecCenter2UAV'

            std::memcpy(&rtb_InDangerSequence[0], &localDW->InDangerSequence_X[0],
                        static_cast<uint32_T>(360U * sizeof(boolean_T)));
            rtb_InDangerSequence[360] = localDW->InDanger;

            // MATLAB Function: '<S65>/Long Track' incorporates:
            //   ForEachSliceAssignment generated from: '<S71>/hisTrack'

            // MATLAB Function 'ImmedMissionGuidance/Mode129_CollAvoidance/Mode129_Variant/Mode129/Long Track': '<S70>:1' 
            colToCopy = 0;
            for (ForEach_itr_c = 0; ForEach_itr_c < 361; ForEach_itr_c++) {
                if (rtb_InDangerSequence[ForEach_itr_c]) {
                    colToCopy = static_cast<int32_T>(colToCopy + 1);
                }
            }

            if (colToCopy <= 73) {
                // '<S70>:1:3'
                // '<S70>:1:4'
                localDW->SFunction_DIMS2_j[0] = 73;
                localDW->SFunction_DIMS2_j[1] = 3;
                for (coffset = 0; coffset < 3; coffset++) {
                    for (ForEach_itr_c = 0; ForEach_itr_c < 73; ForEach_itr_c++)
                    {
                        localDW->Track[static_cast<int32_T>(ForEach_itr_c +
                            static_cast<int32_T>(localDW->SFunction_DIMS2_j[0] *
                            coffset))] =
                            localDW->ImpAsg_InsertedFor_hisTrack_at_inport_0[
                            static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(361 * coffset) + ForEach_itr_c)
                            + 288)];
                    }
                }
            } else {
                rtb_BiasNumUAV = 0;
                for (ForEach_itr = 0; ForEach_itr < 361; ForEach_itr++) {
                    if (rtb_InDangerSequence[ForEach_itr]) {
                        rtb_BiasNumUAV = static_cast<int32_T>(rtb_BiasNumUAV + 1);
                    }
                }

                ForEach_itr = rtb_BiasNumUAV;
                rtb_BiasOldIdx = 0;
                for (rtb_BiasNumUAV = 0; rtb_BiasNumUAV < 361; rtb_BiasNumUAV++)
                {
                    if (rtb_InDangerSequence[rtb_BiasNumUAV]) {
                        b_data[rtb_BiasOldIdx] = static_cast<int16_T>(
                            static_cast<int32_T>(rtb_BiasNumUAV + 1));
                        rtb_BiasOldIdx = static_cast<int32_T>(rtb_BiasOldIdx + 1);
                    }
                }

                // '<S70>:1:6'
                localDW->SFunction_DIMS2_j[0] = ForEach_itr;
                localDW->SFunction_DIMS2_j[1] = 3;
                for (coffset = 0; coffset < 3; coffset++) {
                    for (ForEach_itr_c = 0; ForEach_itr_c <= static_cast<int32_T>
                            (ForEach_itr - 1); ForEach_itr_c++) {
                        localDW->Track[static_cast<int32_T>(ForEach_itr_c +
                            static_cast<int32_T>(localDW->SFunction_DIMS2_j[0] *
                            coffset))] =
                            localDW->ImpAsg_InsertedFor_hisTrack_at_inport_0[
                            static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(361 * coffset) + static_cast<
                            int32_T>(b_data[ForEach_itr_c])) - 1)];
                    }
                }
            }

            // End of MATLAB Function: '<S65>/Long Track'

            // Outputs for Atomic SubSystem: '<S65>/HeadingControl'
            // MATLABSystem: '<S68>/TrackSimPath'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj_j.CacheInputSizes) ^ 1))) {
                localDW->obj_j.CacheInputSizes = true;
                for (coffset = 0; coffset < 8; coffset++) {
                    localDW->obj_j.inputVarSize[0].f1[coffset] = 1U;
                }

                localDW->obj_j.inputVarSize[1].f1[0] = static_cast<uint32_T>
                    (localDW->SFunction_DIMS2_j[0]);
                localDW->obj_j.inputVarSize[1].f1[1] = 3U;
                for (coffset = 0; coffset < 6; coffset++) {
                    localDW->obj_j.inputVarSize[1].f1[static_cast<int32_T>
                        (coffset + 2)] = 1U;
                }

                for (coffset = 0; coffset < 8; coffset++) {
                    localDW->obj_j.inputVarSize[2].f1[coffset] = 1U;
                }
            }

            inSize[0] = static_cast<uint32_T>(localDW->SFunction_DIMS2_j[0]);
            inSize[1] = 3U;
            for (coffset = 0; coffset < 6; coffset++) {
                inSize[static_cast<int32_T>(coffset + 2)] = 1U;
            }

            ForEach_itr = 0;
            exitg1 = false;
            while ((!exitg1) && (ForEach_itr < 8)) {
                if (localDW->obj_j.inputVarSize[1].f1[ForEach_itr] !=
                        inSize[ForEach_itr]) {
                    for (coffset = 0; coffset < 8; coffset++) {
                        localDW->obj_j.inputVarSize[1].f1[coffset] =
                            inSize[coffset];
                    }

                    exitg1 = true;
                } else {
                    ForEach_itr = static_cast<int32_T>(ForEach_itr + 1);
                }
            }

            // SignalConversion generated from: '<S68>/TrackSimPath'
            rtb_TmpSignalConversionAtOrbitFollowerInport1[0] = rtb_North;
            rtb_TmpSignalConversionAtOrbitFollowerInport1[1] = rtb_East;
            rtb_TmpSignalConversionAtOrbitFollowerInport1[2] = rtb_Abs1;
            rtb_TmpSignalConversionAtOrbitFollowerInport1[3] = rtb_HeadingAngle;

            // MATLABSystem: '<S68>/TrackSimPath' incorporates:
            //   Constant: '<S68>/LookAheadDis'

            ImmedMission_WaypointFollower_stepImpl(&localDW->obj_j,
                rtb_TmpSignalConversionAtOrbitFollowerInport1, localDW->Track,
                localDW->SFunction_DIMS2_j, 200.0,
                rtb_TmpSignalConversionAtOrbitFollowerInport2, &rtb_Abs1_k,
                &rtb_Switch, &rtb_SumofElements_i, &localDW->TrackSimPath_o5,
                localDW);

            // BusCreator: '<S65>/GuidanceCMDBusCreator' incorporates:
            //   Gain: '<S68>/Down2Height'
            //   MATLABSystem: '<S68>/TrackSimPath'

            rty_GuidanceCMD->Height =
                -rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // End of Outputs for SubSystem: '<S65>/HeadingControl'
            rty_GuidanceCMD->AirSpeed = 0.0;

            // Outputs for Atomic SubSystem: '<S65>/HeadingControl'
            rty_GuidanceCMD->HeadingAngle = rtb_Abs1_k;

            // End of Outputs for SubSystem: '<S65>/HeadingControl'

            // Chart: '<S65>/TrackSwitch' incorporates:
            //   Constant: '<S67>/Constant'
            //   Logic: '<S65>/AND'
            //   Memory: '<S65>/MemoryPrevRange'
            //   Memory: '<S65>/MemoryStatus'
            //   RelationalOperator: '<S67>/Compare'
            //   Sum: '<S65>/RangeDeriv'

            if (static_cast<uint32_T>(localDW->temporalCounter_i1_d) < 127U) {
                localDW->temporalCounter_i1_d = static_cast<uint8_T>(
                    static_cast<uint32_T>(static_cast<uint32_T>
                    (localDW->temporalCounter_i1_d) + 1U));
            }

            // Gateway: ImmedMissionGuidance/Mode129_CollAvoidance/Mode129_Variant/Mode129/TrackSwitch 
            // During: ImmedMissionGuidance/Mode129_CollAvoidance/Mode129_Variant/Mode129/TrackSwitch 
            if (static_cast<uint32_T>(localDW->is_active_c4_ImmedMission) == 0U)
            {
                // Entry: ImmedMissionGuidance/Mode129_CollAvoidance/Mode129_Variant/Mode129/TrackSwitch 
                localDW->is_active_c4_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode129_CollAvoidance/Mode129_Variant/Mode129/TrackSwitch 
                // Transition: '<S73>:3'
                localDW->is_c4_ImmedMission = ImmedMission_IN_Short;

                // SignalConversion generated from: '<S7>/ControlSwitch'
                // Entry 'Short': '<S73>:2'
                rty_ControlSwitch[0] = false;
            } else if (localDW->is_c4_ImmedMission == ImmedMission_IN_Long) {
                // During 'Long': '<S73>:4'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (static_cast<boolean_T>
                        (static_cast<int32_T>((localDW->sqrt_f -
                          localDW->MemoryPrevRange_PreviousInput >= 0.0) & (
                          static_cast<int32_T>
                          (localDW->MemoryStatus_PreviousInput) != 0)))) & (
                        static_cast<uint32_T>(localDW->temporalCounter_i1_d) >=
                        100U)))) {
                    // Transition: '<S73>:9'
                    localDW->is_c4_ImmedMission = ImmedMission_IN_Short;

                    // SignalConversion generated from: '<S7>/ControlSwitch'
                    // Entry 'Short': '<S73>:2'
                    rty_ControlSwitch[0] = false;
                } else {
                    // SignalConversion generated from: '<S7>/ControlSwitch'
                    rty_ControlSwitch[0] = true;
                }

                // During 'Short': '<S73>:2'
            } else if (localDW->InDanger) {
                // Transition: '<S73>:5'
                localDW->is_c4_ImmedMission = ImmedMission_IN_Long;
                localDW->temporalCounter_i1_d = 0U;

                // SignalConversion generated from: '<S7>/ControlSwitch'
                // Entry 'Long': '<S73>:4'
                rty_ControlSwitch[0] = true;
            } else {
                // SignalConversion generated from: '<S7>/ControlSwitch'
                rty_ControlSwitch[0] = false;
            }

            // End of Chart: '<S65>/TrackSwitch'

            // SignalConversion generated from: '<S7>/ControlSwitch' incorporates:
            //   Constant: '<S65>/ControlSpd'

            // MATLAB Function 'ImmedMissionGuidance/Mode129_CollAvoidance/Mode129_Variant/Mode129/selectEnd': '<S74>:1' 
            // '<S74>:1:3'
            rty_ControlSwitch[1] = false;

            // SignalConversion generated from: '<S7>/ShiftSimUAVswitch'
            rtb_Compare_lh = localDW->InDanger;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   MATLAB Function: '<S65>/selectEnd'
            //   SignalConversion generated from: '<S7>/ShiftedSimUAV'

            localDW->MergeCollAvoidSimUAV =
                localDW->ImpAsg_InsertedFor_CollAvoidSimUAV_at_inport_0[360];

            // End of Outputs for SubSystem: '<S1>/Mode129_CollAvoidance'
        }
        break;

      case 2:
        // Outputs for IfAction SubSystem: '<S1>/Mode130_FlightMissionRH' incorporates:
        //   ActionPort: '<S8>/Action Port'

        rty_ControlSwitch[0] = false;
        rty_ControlSwitch[1] = false;

        // Bias: '<S125>/BiasNumUAV' incorporates:
        //   Constant: '<S125>/ControlHdg'
        //   Constant: '<S125>/ControlSpd'

        rtb_BiasNumUAV = *rtu_FlightMission_numUAV;

        // Bias: '<S125>/BiasOldIdx'
        rtb_BiasOldIdx = *rtu_FlightMission_FormationPos;

        // Gain: '<S126>/Gain1'
        rtb_Abs1 = 0.017453292519943295 *
            *rtu_FlightMission_MissionLocation_degHDG;

        // Bias: '<S125>/Rotate90deg'
        rtb_East = rtb_Abs1 + 1.5707963267948966;

        // Sum: '<S125>/Minus' incorporates:
        //   Bias: '<S125>/BiasMissionUAV'
        //   Bias: '<S125>/BiasNewIdx'
        //   Bias: '<S125>/BiasNumUAV'
        //   Bias: '<S125>/BiasOldIdx'
        //   DataTypeConversion: '<S125>/DoubleTurnDir'
        //   DataTypeConversion: '<S125>/Param3'
        //   Product: '<S125>/Divide'
        //   Product: '<S125>/ProductNewShift'
        //   Product: '<S125>/ProductOldShift'
        //   Product: '<S125>/ProductScanWidth'

        rtb_Abs1 = static_cast<real_T>(static_cast<int32_T>(rtb_BiasNumUAV - 1))
            * static_cast<real_T>(*rtu_FlightMission_params_Param3) /
            static_cast<real_T>(static_cast<int32_T>(rtu_MissionInput->numUAV -
            1)) * (static_cast<real_T>(rtu_MissionInput->FormationPos) + -1.0) -
            static_cast<real_T>(static_cast<int32_T>(rtb_BiasOldIdx - 1)) *
            static_cast<real_T>(*rtu_FlightMission_params_Param3);

        // Sum: '<S125>/SumNorth' incorporates:
        //   Product: '<S125>/ProductNorth'
        //   Trigonometry: '<S125>/Cos'

        rtb_North = std::cos(rtb_East) * rtb_Abs1 + rtu_SimUAVstate->North;

        // Sum: '<S125>/SumEast' incorporates:
        //   Product: '<S125>/ProductEast'
        //   Trigonometry: '<S125>/Sin'

        rtb_Abs1 = std::sin(rtb_East) * rtb_Abs1 + rtu_SimUAVstate->East;

        // DataTypeConversion: '<S125>/DoubleFormPos'
        rtb_East = static_cast<real_T>(*rtu_FlightMission_FormationPos);

        // Sum: '<S125>/SumHeight' incorporates:
        //   Bias: '<S125>/NewBias'
        //   Bias: '<S125>/OldBias'
        //   Constant: '<S125>/Three'
        //   DataTypeConversion: '<S125>/DoubleTurnDir'
        //   Gain: '<S125>/Gain'
        //   Math: '<S125>/NewMod'
        //   Math: '<S125>/OldMod'
        //   Sum: '<S125>/MinusLayer'

        rtb_East = (rt_modd_snf(static_cast<real_T>
                                (rtu_MissionInput->FormationPos) + -1.0, 3.0) -
                    rt_modd_snf(rtb_East + -1.0, 3.0)) * 15.0 +
            rtu_SimUAVstate->Height;

        // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
        //   BusAssignment: '<S125>/Bus Assignment'

        localDW->MergeCollAvoidSimUAV = *rtu_SimUAVstate;

        // BusAssignment: '<S125>/Bus Assignment'
        localDW->MergeCollAvoidSimUAV.North = rtb_North;
        localDW->MergeCollAvoidSimUAV.East = rtb_Abs1;
        localDW->MergeCollAvoidSimUAV.Height = rtb_East;

        // RelationalOperator: '<S127>/Compare' incorporates:
        //   Constant: '<S127>/Constant'

        rtb_Compare_lh = (*rtu_FlightMission_MissionMode == MissionModes::
                          HorzScanNav);

        // DataTypeConversion: '<S125>/DoubleStatus'
        *rty_TaskStatus = static_cast<real_T>(rtb_Compare_lh);

        // End of Outputs for SubSystem: '<S1>/Mode130_FlightMissionRH'
        break;

      case 3:
        {
            boolean_T exitg1;
            boolean_T rtb_Ctrl;
            ZCEventType zcEvent;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FILE* a;

                // SystemReset for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
                //   ActionPort: '<S9>/Action Port'

                // SystemReset for Triggered SubSystem: '<S129>/WayPointGen'
                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S129>/TriggerCalibrStart'
                //   MATLAB Function: '<S135>/BaseWayPoint'
                //   MATLABSystem: '<S129>/Waypoint Follower'

                localDW->SingletonInstance_not_empty = false;
                a = NULL;
                for (coffset = 0; coffset < 20; coffset++) {
                    localDW->eml_openfiles[coffset] = a;
                }

                localZCE->WayPointGen_Trig_ZCE_d = NEG_ZCSIG;

                // End of SystemReset for SubSystem: '<S129>/WayPointGen'
                localDW->obj.WaypointIndex = 1.0;
                for (coffset = 0; coffset < 30723; coffset++) {
                    localDW->obj.WaypointsInternal[coffset] = (rtNaN);
                }

                localDW->is_active_c7_ImmedMission = 0U;
                localDW->is_c7_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;

                // End of SystemReset for SubSystem: '<S1>/Mode131_SqCalibr'
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S9>/Action Port'

            // Sum: '<S158>/Sum1' incorporates:
            //   DataStoreRead: '<S133>/PrevLatitudeGCS'
            //   DataStoreRead: '<S133>/PrevLongitudeGCS'
            //   Sum: '<S160>/Sum'
            //   Switch: '<S172>/Switch'

            rtb_Sum1[0] = *rtu_FlightMission_MissionLocation_Lat - LatitudeGCS;
            rtb_Sum1[1] = *rtu_FlightMission_MissionLocation_Lon - LongitudeGCS;

            // Switch: '<S166>/Switch' incorporates:
            //   Abs: '<S166>/Abs'
            //   Bias: '<S166>/Bias'
            //   Bias: '<S166>/Bias1'
            //   Constant: '<S166>/Constant2'
            //   Constant: '<S167>/Constant'
            //   Math: '<S166>/Math Function1'
            //   RelationalOperator: '<S167>/Compare'

            if (std::abs(rtb_Sum1[0]) > 180.0) {
                rtb_Switch = rt_modd_snf(rtb_Sum1[0] + 180.0, 360.0) + -180.0;
            } else {
                rtb_Switch = rtb_Sum1[0];
            }

            // End of Switch: '<S166>/Switch'

            // Abs: '<S163>/Abs1'
            rtb_Abs1_k = std::abs(rtb_Switch);

            // Switch: '<S163>/Switch' incorporates:
            //   Bias: '<S163>/Bias'
            //   Bias: '<S163>/Bias1'
            //   Constant: '<S159>/Constant'
            //   Constant: '<S159>/Constant1'
            //   Constant: '<S165>/Constant'
            //   Gain: '<S163>/Gain'
            //   Product: '<S163>/Divide1'
            //   RelationalOperator: '<S165>/Compare'
            //   Switch: '<S159>/Switch1'

            if (rtb_Abs1_k > 90.0) {
                // Signum: '<S163>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Switch)) ^ 1))) {
                    if (rtb_Switch < 0.0) {
                        rtb_Switch = -1.0;
                    } else {
                        rtb_Switch = static_cast<real_T>(rtb_Switch > 0.0);
                    }
                }

                // End of Signum: '<S163>/Sign1'
                rtb_Switch *= -(rtb_Abs1_k + -90.0) + 90.0;
                coffset = 180;
            } else {
                coffset = 0;
            }

            // End of Switch: '<S163>/Switch'

            // Sum: '<S159>/Sum'
            rtb_Sum_n = static_cast<real_T>(coffset) + rtb_Sum1[1];

            // Switch: '<S164>/Switch' incorporates:
            //   Abs: '<S164>/Abs'
            //   Bias: '<S164>/Bias'
            //   Bias: '<S164>/Bias1'
            //   Constant: '<S164>/Constant2'
            //   Constant: '<S168>/Constant'
            //   Math: '<S164>/Math Function1'
            //   RelationalOperator: '<S168>/Compare'

            if (std::abs(rtb_Sum_n) > 180.0) {
                rtb_Sum_n = rt_modd_snf(rtb_Sum_n + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S164>/Switch'

            // UnitConversion: '<S162>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1[0] = 0.017453292519943295 * rtb_Switch;
            rtb_Sum1[1] = 0.017453292519943295 * rtb_Sum_n;

            // Sum: '<S178>/Sum1' incorporates:
            //   Constant: '<S178>/Constant'
            //   Product: '<S178>/Product1'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum_n = 1.0 - 0.0066943799901413295 *
                rtb_QuaternionInterpolation_idx_3 *
                rtb_QuaternionInterpolation_idx_3;

            // Product: '<S176>/Product1' incorporates:
            //   Constant: '<S176>/Constant1'
            //   Sqrt: '<S176>/sqrt'

            rtb_Switch = 6.378137E+6 / std::sqrt(rtb_Sum_n);

            // Product: '<S161>/dNorth' incorporates:
            //   Constant: '<S176>/Constant2'
            //   Product: '<S176>/Product3'
            //   Trigonometry: '<S176>/Trigonometric Function1'

            rtb_Sum_n = rtb_Sum1[0] / rt_atan2d_snf(1.0, rtb_Switch *
                0.99330562000985867 / rtb_Sum_n);

            // Product: '<S161>/dEast' incorporates:
            //   Constant: '<S176>/Constant3'
            //   Product: '<S176>/Product4'
            //   Trigonometry: '<S176>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch = 1.0 / rt_atan2d_snf(1.0, rtb_Switch *
                rtb_QuaternionInterpolation_idx_2) * rtb_Sum1[1];

            // Sum: '<S158>/Sum' incorporates:
            //   DataStoreRead: '<S133>/PrevAltitudeGCS'
            //   Gain: '<S133>/PrevInverse'

            rtb_Switch_m2 = *rtu_FlightMission_MissionLocation_Alt +
                -AltitudeGCS;

            // Reshape: '<S129>/ReshapeXe' incorporates:
            //   Product: '<S161>/x*cos'
            //   Product: '<S161>/x*sin'
            //   Product: '<S161>/y*cos'
            //   Product: '<S161>/y*sin'
            //   Sum: '<S161>/Sum2'
            //   Sum: '<S161>/Sum3'
            //   UnaryMinus: '<S158>/Ze2height'

            rtb_Sum_o[0] = rtb_Switch * 0.0 + rtb_Sum_n;
            rtb_Sum_o[1] = rtb_Switch - rtb_Sum_n * 0.0;
            rtb_Sum_o[2] = -rtb_Switch_m2;

            // Sum: '<S129>/Minus' incorporates:
            //   Reshape: '<S129>/ReshapeXe'

            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_North -
                rtb_Sum_o[0];
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_East -
                rtb_Sum_o[1];

            // Sum: '<S132>/Sum1' incorporates:
            //   DataStoreRead: '<S129>/LatitudeGCS'
            //   DataStoreRead: '<S129>/LongitudeGCS'
            //   Sum: '<S137>/Sum'
            //   Switch: '<S149>/Switch'

            rtb_Sum1[0] = rtu_MissionInput->MissionLocation.Lat - LatitudeGCS;
            rtb_Sum1[1] = rtu_MissionInput->MissionLocation.Lon - LongitudeGCS;

            // Switch: '<S143>/Switch' incorporates:
            //   Abs: '<S143>/Abs'
            //   Bias: '<S143>/Bias'
            //   Bias: '<S143>/Bias1'
            //   Constant: '<S143>/Constant2'
            //   Constant: '<S144>/Constant'
            //   Math: '<S143>/Math Function1'
            //   RelationalOperator: '<S144>/Compare'

            if (std::abs(rtb_Sum1[0]) > 180.0) {
                rtb_Switch_gh = rt_modd_snf(rtb_Sum1[0] + 180.0, 360.0) + -180.0;
            } else {
                rtb_Switch_gh = rtb_Sum1[0];
            }

            // End of Switch: '<S143>/Switch'

            // Abs: '<S140>/Abs1'
            rtb_Abs1_k = std::abs(rtb_Switch_gh);

            // Switch: '<S140>/Switch' incorporates:
            //   Bias: '<S140>/Bias'
            //   Bias: '<S140>/Bias1'
            //   Constant: '<S136>/Constant'
            //   Constant: '<S136>/Constant1'
            //   Constant: '<S142>/Constant'
            //   Gain: '<S140>/Gain'
            //   Product: '<S140>/Divide1'
            //   RelationalOperator: '<S142>/Compare'
            //   Switch: '<S136>/Switch1'

            if (rtb_Abs1_k > 90.0) {
                // Signum: '<S140>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_Switch_gh)) ^ 1))) {
                    if (rtb_Switch_gh < 0.0) {
                        rtb_Switch_gh = -1.0;
                    } else {
                        rtb_Switch_gh = static_cast<real_T>(rtb_Switch_gh > 0.0);
                    }
                }

                // End of Signum: '<S140>/Sign1'
                rtb_Switch_gh *= -(rtb_Abs1_k + -90.0) + 90.0;
                coffset = 180;
            } else {
                coffset = 0;
            }

            // End of Switch: '<S140>/Switch'

            // Sum: '<S136>/Sum'
            rtb_Sum_n = static_cast<real_T>(coffset) + rtb_Sum1[1];

            // Switch: '<S141>/Switch' incorporates:
            //   Abs: '<S141>/Abs'
            //   Bias: '<S141>/Bias'
            //   Bias: '<S141>/Bias1'
            //   Constant: '<S141>/Constant2'
            //   Constant: '<S145>/Constant'
            //   Math: '<S141>/Math Function1'
            //   RelationalOperator: '<S145>/Compare'

            if (std::abs(rtb_Sum_n) > 180.0) {
                rtb_Sum_n = rt_modd_snf(rtb_Sum_n + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S141>/Switch'

            // UnitConversion: '<S139>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1[0] = 0.017453292519943295 * rtb_Switch_gh;
            rtb_Sum1[1] = 0.017453292519943295 * rtb_Sum_n;

            // Trigonometry: '<S155>/Trigonometric Function1'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_gh = std::sin(stateNew_idx_0);

            // Sum: '<S155>/Sum1' incorporates:
            //   Constant: '<S155>/Constant'
            //   Product: '<S155>/Product1'

            rtb_Switch_gh = 1.0 - 0.0066943799901413295 * rtb_Switch_gh *
                rtb_Switch_gh;

            // Product: '<S153>/Product1' incorporates:
            //   Constant: '<S153>/Constant1'
            //   Sqrt: '<S153>/sqrt'

            rtb_Sum_n = 6.378137E+6 / std::sqrt(rtb_Switch_gh);

            // Product: '<S138>/dNorth' incorporates:
            //   Constant: '<S153>/Constant2'
            //   Product: '<S153>/Product3'
            //   Trigonometry: '<S153>/Trigonometric Function1'

            rtb_Switch_gh = rtb_Sum1[0] / rt_atan2d_snf(1.0, rtb_Sum_n *
                0.99330562000985867 / rtb_Switch_gh);

            // Product: '<S138>/dEast' incorporates:
            //   Constant: '<S153>/Constant3'
            //   Product: '<S153>/Product4'
            //   Trigonometry: '<S153>/Trigonometric Function'
            //   Trigonometry: '<S153>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_m2 = 1.0 / rt_atan2d_snf(1.0, rtb_Sum_n * std::cos
                (stateNew_idx_0)) * rtb_Sum1[1];

            // Outputs for Triggered SubSystem: '<S129>/WayPointGen' incorporates:
            //   TriggerPort: '<S135>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &localZCE->WayPointGen_Trig_ZCE_d,
                               (1.0));
            if (zcEvent != NO_ZCEVENT) {
                int32_T colIdx;
                int32_T colToCopy;

                // Saturate: '<S135>/Saturation' incorporates:
                //   DataTypeConversion: '<S129>/Param2'

                if (rtu_MissionInput->params.Param2 <= 1.0F) {
                    // Saturate: '<S135>/Saturation'
                    rtb_Sum_n = 1.0;
                } else {
                    // Saturate: '<S135>/Saturation'
                    rtb_Sum_n = static_cast<real_T>
                        (rtu_MissionInput->params.Param2);
                }

                // End of Saturate: '<S135>/Saturation'

                // SignalConversion generated from: '<S135>/RotateATMissionHdg' incorporates:
                //   Bias: '<S135>/Bias'
                //   Gain: '<S131>/Gain1'

                rtb_VectorConcatenate[0] = 0.017453292519943295 *
                    rtu_MissionInput->MissionLocation.degHDG +
                    -0.78539816339744828;

                // MATLABSystem: '<S135>/RotateATMissionHdg'
                rtb_Switch = std::cos(rtb_VectorConcatenate[0]);
                rtb_VectorConcatenate[0] = std::sin(rtb_VectorConcatenate[0]);
                rtb_VectorConcatenate_a[0] = rtb_Switch;
                rtb_VectorConcatenate_a[3] = 0.0 * rtb_Switch -
                    rtb_VectorConcatenate[0];
                rtb_VectorConcatenate_a[6] = 0.0 * rtb_Switch +
                    rtb_VectorConcatenate[0] * 0.0;
                rtb_VectorConcatenate_a[1] = rtb_VectorConcatenate[0];
                rtb_VectorConcatenate_a[4] = 0.0 * rtb_VectorConcatenate[0] +
                    rtb_Switch;
                rtb_VectorConcatenate_a[7] = 0.0 * rtb_VectorConcatenate[0] -
                    rtb_Switch * 0.0;
                rtb_VectorConcatenate_a[2] = -0.0;
                rtb_VectorConcatenate_a[5] = 0.0;
                rtb_VectorConcatenate_a[8] = 1.0;

                // Reshape: '<S135>/ReshapeRowVec' incorporates:
                //   DataStoreRead: '<S129>/AltitudeGCS'
                //   Gain: '<S129>/inverse'
                //   Product: '<S138>/x*cos'
                //   Product: '<S138>/x*sin'
                //   Product: '<S138>/y*cos'
                //   Product: '<S138>/y*sin'
                //   Sum: '<S132>/Sum'
                //   Sum: '<S138>/Sum2'
                //   Sum: '<S138>/Sum3'
                //   UnaryMinus: '<S132>/Ze2height'

                rtb_VectorConcatenate[0] = rtb_Switch_m2 * 0.0 + rtb_Switch_gh;
                rtb_VectorConcatenate[1] = rtb_Switch_m2 - rtb_Switch_gh * 0.0;
                rtb_VectorConcatenate[2] =
                    -(rtu_MissionInput->MissionLocation.Alt + -AltitudeGCS);

                // MATLAB Function: '<S135>/BaseWayPoint' incorporates:
                //   DataTypeConversion: '<S129>/Param1'
                //   DataTypeConversion: '<S129>/Param3'

                // MATLAB Function 'ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/WayPointGen/BaseWayPoint': '<S181>:1' 
                // '<S181>:1:5'
                // '<S181>:1:26'
                // '<S181>:1:5'
                rtb_Abs1_k = (ImmedMission_DubinsObjSingleton_getIstance(localDW))
                    ->MinTurningRadius;

                // '<S181>:1:8'
                for (coffset = 0; coffset < 360; coffset++) {
                    ForEach_itr_c = static_cast<int32_T>(coffset << 1);
                    localDW->CirVec[ForEach_itr_c] = b_a[ForEach_itr_c] *
                        rtb_Abs1_k;
                    localDW->CirVec[static_cast<int32_T>(ForEach_itr_c + 1)] =
                        b_a[static_cast<int32_T>(ForEach_itr_c + 1)] *
                        rtb_Abs1_k;
                }

                // '<S181>:1:11'
                // '<S181>:1:12'
                linspace_Q5Un26da(static_cast<real_T>
                                  (rtu_MissionInput->params.Param3), WPQ1_tmp);

                // '<S181>:1:16'
                // '<S181>:1:17'
                // '<S181>:1:21'
                // '<S181>:1:22'
                // '<S181>:1:26'
                // '<S181>:1:27'
                // '<S181>:1:31'
                rtb_Abs1_k = static_cast<real_T>(rtu_MissionInput->params.Param1)
                    / 2.0;
                rtb_Switch_gh = -static_cast<real_T>
                    (rtu_MissionInput->params.Param1) / 2.0;
                for (coffset = 0; coffset < 91; coffset++) {
                    rtb_Switch_m2 = WPQ1_tmp[coffset];
                    ForEach_itr_c = static_cast<int32_T>(coffset << 1);
                    localDW->a[static_cast<int32_T>(3 * coffset)] =
                        localDW->CirVec[ForEach_itr_c] + rtb_Abs1_k;
                    localDW->a[static_cast<int32_T>(static_cast<int32_T>(3 *
                        coffset) + 1)] = localDW->CirVec[static_cast<int32_T>
                        (ForEach_itr_c + 1)] + rtb_Abs1_k;
                    localDW->a[static_cast<int32_T>(static_cast<int32_T>(3 *
                        coffset) + 2)] = rtb_Switch_m2;
                    ForEach_itr_c = static_cast<int32_T>(static_cast<int32_T>
                        (coffset + 90) << 1);
                    ForEach_itr = static_cast<int32_T>(static_cast<int32_T>
                        (coffset + 91) * 3);
                    localDW->a[ForEach_itr] = localDW->CirVec[ForEach_itr_c] +
                        rtb_Switch_gh;
                    localDW->a[static_cast<int32_T>(ForEach_itr + 1)] =
                        localDW->CirVec[static_cast<int32_T>(ForEach_itr_c + 1)]
                        + rtb_Abs1_k;
                    localDW->a[static_cast<int32_T>(ForEach_itr + 2)] =
                        rtb_Switch_m2;
                    ForEach_itr_c = static_cast<int32_T>(static_cast<int32_T>
                        (coffset + 180) << 1);
                    ForEach_itr = static_cast<int32_T>(static_cast<int32_T>
                        (coffset + 182) * 3);
                    localDW->a[ForEach_itr] = localDW->CirVec[ForEach_itr_c] +
                        rtb_Switch_gh;
                    localDW->a[static_cast<int32_T>(ForEach_itr + 1)] =
                        localDW->CirVec[static_cast<int32_T>(ForEach_itr_c + 1)]
                        + rtb_Switch_gh;
                    localDW->a[static_cast<int32_T>(ForEach_itr + 2)] =
                        rtb_Switch_m2;
                    ForEach_itr_c = static_cast<int32_T>(static_cast<int32_T>
                        (d[coffset]) << 1);
                    ForEach_itr = static_cast<int32_T>(static_cast<int32_T>
                        (coffset + 273) * 3);
                    localDW->a[ForEach_itr] = localDW->CirVec[ForEach_itr_c] +
                        rtb_Abs1_k;
                    localDW->a[static_cast<int32_T>(ForEach_itr + 1)] =
                        localDW->CirVec[static_cast<int32_T>(ForEach_itr_c + 1)]
                        + rtb_Switch_gh;
                    localDW->a[static_cast<int32_T>(ForEach_itr + 2)] =
                        rtb_Switch_m2;
                }

                ImmedMission_emxInit_real_T(&d_b, 2);
                coffset = static_cast<int32_T>(d_b->size[0] * d_b->size[1]);

                // MATLAB Function: '<S135>/BaseWayPoint'
                d_b->size[0] = 3;
                d_b->size[1] = static_cast<int32_T>(364 * static_cast<int32_T>
                    (rtb_Sum_n));
                ImmedMission_emxEnsureCapacity_real_T(d_b, coffset);

                // MATLAB Function: '<S135>/BaseWayPoint'
                for (colIdx = 0; colIdx <= static_cast<int32_T>
                        (static_cast<int32_T>(rtb_Sum_n) - 1); colIdx =
                        static_cast<int32_T>(colIdx + 1)) {
                    colToCopy = static_cast<int32_T>(static_cast<int32_T>(colIdx
                        * 1092) - 1);
                    for (ForEach_itr = 0; ForEach_itr < 364; ForEach_itr++) {
                        ForEach_itr_c = static_cast<int32_T>(ForEach_itr * 3);
                        coffset = static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(ForEach_itr * 3) + colToCopy) +
                            1);
                        d_b->data[coffset] = localDW->a[ForEach_itr_c];
                        d_b->data[static_cast<int32_T>(coffset + 1)] =
                            localDW->a[static_cast<int32_T>(ForEach_itr_c + 1)];
                        d_b->data[static_cast<int32_T>(coffset + 2)] =
                            localDW->a[static_cast<int32_T>(ForEach_itr_c + 2)];
                    }
                }

                coffset = static_cast<int32_T>(e->size[0] * e->size[1]);

                // MATLAB Function: '<S135>/BaseWayPoint'
                e->size[0] = d_b->size[1];
                e->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(e, coffset);

                // MATLAB Function: '<S135>/BaseWayPoint'
                ForEach_itr = d_b->size[1];
                for (coffset = 0; coffset < 3; coffset++) {
                    for (ForEach_itr_c = 0; ForEach_itr_c <= static_cast<int32_T>
                            (ForEach_itr - 1); ForEach_itr_c++) {
                        e->data[static_cast<int32_T>(ForEach_itr_c +
                            static_cast<int32_T>(e->size[0] * coffset))] =
                            d_b->data[static_cast<int32_T>(static_cast<int32_T>
                            (3 * ForEach_itr_c) + coffset)];
                    }
                }

                ImmedMission_emxFree_real_T(&d_b);
                ImmedMission_emxInit_real_T(&WayPoint, 2);

                // MATLAB Function: '<S135>/BaseWayPoint'
                ImmedMission_circshift(e);
                coffset = static_cast<int32_T>(WayPoint->size[0] *
                    WayPoint->size[1]);

                // MATLAB Function: '<S135>/BaseWayPoint'
                WayPoint->size[0] = e->size[0];
                WayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(WayPoint, coffset);

                // MATLAB Function: '<S135>/BaseWayPoint'
                ForEach_itr = static_cast<int32_T>(e->size[0] * 3);
                for (coffset = 0; coffset <= static_cast<int32_T>(ForEach_itr -
                        1); coffset++) {
                    WayPoint->data[coffset] = e->data[coffset];
                }

                ImmedMission_emxInit_real_T(&y, 2);

                // MATLAB Function: '<S135>/BaseWayPoint' incorporates:
                //   DataTypeConversion: '<S129>/Param3'

                // '<S181>:1:32'
                rtb_Switch = 4.0 * rtb_Sum_n * static_cast<real_T>
                    (rtu_MissionInput->params.Param3);
                if (std::isnan(static_cast<real_T>
                               (rtu_MissionInput->params.Param3))) {
                    coffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y, coffset);
                    y->data[0] = (rtNaN);
                } else if (std::isnan(rtb_Switch)) {
                    coffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y, coffset);
                    y->data[0] = (rtNaN);
                } else if (static_cast<boolean_T>(static_cast<int32_T>(
                             static_cast<int32_T>(static_cast<boolean_T>(
                               static_cast<int32_T>(static_cast<int32_T>(
                                 static_cast<boolean_T>(static_cast<int32_T>
                                  ((rtb_Switch > 0.0) &
                                   (rtu_MissionInput->params.Param3 < 0.0F)))) |
                                (rtu_MissionInput->params.Param3 == 0.0F)))) |
                             static_cast<int32_T>(static_cast<boolean_T>(
                               static_cast<int32_T>((rtb_Switch < 0.0) &
                                (rtu_MissionInput->params.Param3 > 0.0F))))))) {
                    y->size[0] = 1;
                    y->size[1] = 0;
                } else if (std::isinf(rtb_Switch) && std::isinf
                           (static_cast<real_T>(rtu_MissionInput->params.Param3)))
                {
                    coffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y, coffset);
                    y->data[0] = (rtNaN);
                } else if (std::isinf(static_cast<real_T>
                                      (rtu_MissionInput->params.Param3))) {
                    coffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = 1;
                    ImmedMission_emxEnsureCapacity_real_T(y, coffset);
                    y->data[0] = 0.0;
                } else if (std::floor(static_cast<real_T>
                                      (rtu_MissionInput->params.Param3)) ==
                           static_cast<real_T>(rtu_MissionInput->params.Param3))
                {
                    coffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    ForEach_itr = static_cast<int32_T>(rtb_Switch /
                        static_cast<real_T>(rtu_MissionInput->params.Param3));
                    y->size[1] = static_cast<int32_T>(ForEach_itr + 1);
                    ImmedMission_emxEnsureCapacity_real_T(y, coffset);
                    for (coffset = 0; coffset <= ForEach_itr; coffset++) {
                        y->data[coffset] = static_cast<real_T>
                            (rtu_MissionInput->params.Param3) *
                            static_cast<real_T>(coffset);
                    }
                } else {
                    rtb_Switch_gh = std::floor(rtb_Switch / static_cast<real_T>
                        (rtu_MissionInput->params.Param3) + 0.5);
                    rtb_Abs1_k = rtb_Switch_gh * static_cast<real_T>
                        (rtu_MissionInput->params.Param3);
                    if (rtu_MissionInput->params.Param3 > 0.0F) {
                        rtb_Switch_m2 = rtb_Abs1_k - rtb_Switch;
                    } else {
                        rtb_Switch_m2 = rtb_Switch - rtb_Abs1_k;
                    }

                    if (std::abs(rtb_Switch_m2) < 4.4408920985006262E-16 * std::
                            fmax(0.0, std::abs(rtb_Switch))) {
                        rtb_Switch_gh++;
                        rtb_Abs1_k = rtb_Switch;
                    } else if (rtb_Switch_m2 > 0.0) {
                        rtb_Abs1_k = (rtb_Switch_gh - 1.0) * static_cast<real_T>
                            (rtu_MissionInput->params.Param3);
                    } else {
                        rtb_Switch_gh++;
                    }

                    if (rtb_Switch_gh >= 0.0) {
                        colToCopy = static_cast<int32_T>(static_cast<int32_T>
                            (rtb_Switch_gh) - 1);
                    } else {
                        colToCopy = -1;
                    }

                    coffset = static_cast<int32_T>(y->size[0] * y->size[1]);
                    y->size[0] = 1;
                    y->size[1] = static_cast<int32_T>(colToCopy + 1);
                    ImmedMission_emxEnsureCapacity_real_T(y, coffset);
                    if (static_cast<int32_T>(colToCopy + 1) > 0) {
                        y->data[0] = 0.0;
                        if (static_cast<int32_T>(colToCopy + 1) > 1) {
                            y->data[colToCopy] = rtb_Abs1_k;
                            ForEach_itr_c = static_cast<int32_T>(colToCopy / 2);
                            for (ForEach_itr = 1; static_cast<int32_T>
                                    (ForEach_itr - 1) <= static_cast<int32_T>
                                    (ForEach_itr_c - 2); ForEach_itr =
                                    static_cast<int32_T>(ForEach_itr + 1)) {
                                rtb_Switch = static_cast<real_T>(ForEach_itr) *
                                    static_cast<real_T>
                                    (rtu_MissionInput->params.Param3);
                                y->data[ForEach_itr] = rtb_Switch;
                                y->data[static_cast<int32_T>(colToCopy -
                                    ForEach_itr)] = rtb_Abs1_k - rtb_Switch;
                            }

                            if (static_cast<int32_T>(ForEach_itr_c << 1) ==
                                    colToCopy) {
                                y->data[ForEach_itr_c] = rtb_Abs1_k / 2.0;
                            } else {
                                rtb_Switch = static_cast<real_T>(ForEach_itr_c) *
                                    static_cast<real_T>
                                    (rtu_MissionInput->params.Param3);
                                y->data[ForEach_itr_c] = rtb_Switch;
                                y->data[static_cast<int32_T>(ForEach_itr_c + 1)]
                                    = rtb_Abs1_k - rtb_Switch;
                            }
                        }
                    }
                }

                ImmedMission_emxInit_real_T(&step, 2);
                coffset = static_cast<int32_T>(step->size[0] * step->size[1]);

                // MATLAB Function: '<S135>/BaseWayPoint'
                step->size[0] = 1;
                step->size[1] = static_cast<int32_T>(y->size[1] * 91);
                ImmedMission_emxEnsureCapacity_real_T(step, coffset);

                // MATLAB Function: '<S135>/BaseWayPoint'
                if (static_cast<int32_T>(y->size[1] * 91) != 0) {
                    colIdx = 0;
                    for (ForEach_itr_c = 0; ForEach_itr_c <= static_cast<int32_T>
                            (y->size[1] - 1); ForEach_itr_c =
                            static_cast<int32_T>(ForEach_itr_c + 1)) {
                        step->data[colIdx] = y->data[ForEach_itr_c];
                        for (ForEach_itr = 0; ForEach_itr < 90; ForEach_itr++) {
                            step->data[static_cast<int32_T>(static_cast<int32_T>
                                (colIdx + ForEach_itr) + 1)] = step->data[colIdx];
                        }

                        colIdx = static_cast<int32_T>(colIdx + 91);
                    }
                }

                ImmedMission_emxFree_real_T(&y);

                // MATLAB Function: '<S135>/BaseWayPoint'
                if (static_cast<int32_T>(step->size[1] - 46) < 46) {
                    ForEach_itr_c = 0;
                    ForEach_itr = 0;
                } else {
                    ForEach_itr_c = 45;
                    ForEach_itr = static_cast<int32_T>(step->size[1] - 46);
                }

                // '<S181>:1:33'
                if (static_cast<int32_T>(ForEach_itr - ForEach_itr_c) ==
                        WayPoint->size[0]) {
                    ImmedMission_emxInit_real_T(&WayPoint_0, 1);
                    colIdx = static_cast<int32_T>(WayPoint->size[0] - 1);
                    coffset = WayPoint_0->size[0];
                    WayPoint_0->size[0] = WayPoint->size[0];
                    ImmedMission_emxEnsureCapacity_real_T(WayPoint_0, coffset);
                    for (coffset = 0; coffset <= colIdx; coffset++) {
                        WayPoint_0->data[coffset] = WayPoint->data
                            [static_cast<int32_T>(static_cast<int32_T>
                            (WayPoint->size[0] << 1) + coffset)] + step->data[
                            static_cast<int32_T>(ForEach_itr_c + coffset)];
                    }

                    ForEach_itr = WayPoint_0->size[0];
                    for (coffset = 0; coffset <= static_cast<int32_T>
                            (ForEach_itr - 1); coffset++) {
                        WayPoint->data[static_cast<int32_T>(coffset +
                            static_cast<int32_T>(WayPoint->size[0] << 1))] =
                            WayPoint_0->data[coffset];
                    }

                    ImmedMission_emxFree_real_T(&WayPoint_0);
                } else {
                    ImmedMission_binary_expand_op_p(WayPoint, step,
                        ForEach_itr_c, static_cast<int32_T>(ForEach_itr - 1));
                }

                ImmedMission_emxFree_real_T(&step);
                ImmedMission_emxInit_real_T(&rotWayPoint, 2);

                // MATLAB Function: '<S135>/BaseWayPoint' incorporates:
                //   Sum: '<S18>/Sum of Elements'
                //   Sum: '<S249>/Sum of Elements'

                // '<S181>:1:35'
                ForEach_itr_c = WayPoint->size[0];
                coffset = static_cast<int32_T>(rotWayPoint->size[0] *
                    rotWayPoint->size[1]);

                // MATLAB Function: '<S135>/BaseWayPoint'
                rotWayPoint->size[0] = WayPoint->size[0];
                rotWayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(rotWayPoint, coffset);

                // MATLAB Function: '<S135>/BaseWayPoint' incorporates:
                //   MATLABSystem: '<S135>/RotateATMissionHdg'

                for (colIdx = 0; colIdx < 3; colIdx++) {
                    coffset = static_cast<int32_T>(colIdx * ForEach_itr_c);
                    colToCopy = static_cast<int32_T>(colIdx * 3);
                    for (ForEach_itr = 0; ForEach_itr <= static_cast<int32_T>
                            (ForEach_itr_c - 1); ForEach_itr =
                            static_cast<int32_T>(ForEach_itr + 1)) {
                        rotWayPoint->data[static_cast<int32_T>(coffset +
                            ForEach_itr)] = (WayPoint->data[static_cast<int32_T>
                                             (WayPoint->size[0] + ForEach_itr)] *
                                             rtb_VectorConcatenate_a[
                                             static_cast<int32_T>(colToCopy + 1)]
                                             + WayPoint->data[ForEach_itr] *
                                             rtb_VectorConcatenate_a[colToCopy])
                            + WayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(WayPoint->size[0] << 1) +
                             ForEach_itr)] * rtb_VectorConcatenate_a[
                            static_cast<int32_T>(colToCopy + 2)];
                    }
                }

                coffset = static_cast<int32_T>(WayPoint->size[0] *
                    WayPoint->size[1]);

                // MATLAB Function: '<S135>/BaseWayPoint'
                WayPoint->size[0] = rotWayPoint->size[0];
                WayPoint->size[1] = 3;
                ImmedMission_emxEnsureCapacity_real_T(WayPoint, coffset);

                // MATLAB Function: '<S135>/BaseWayPoint' incorporates:
                //   Reshape: '<S135>/ReshapeRowVec'

                ForEach_itr = rotWayPoint->size[0];
                for (colToCopy = 0; colToCopy <= static_cast<int32_T>
                        (ForEach_itr - 1); colToCopy = static_cast<int32_T>
                        (colToCopy + 1)) {
                    WayPoint->data[colToCopy] = rtb_VectorConcatenate[0];
                }

                for (colToCopy = 0; colToCopy <= static_cast<int32_T>
                        (ForEach_itr - 1); colToCopy = static_cast<int32_T>
                        (colToCopy + 1)) {
                    WayPoint->data[static_cast<int32_T>(ForEach_itr + colToCopy)]
                        = rtb_VectorConcatenate[1];
                }

                colIdx = static_cast<int32_T>(rotWayPoint->size[0] << 1);
                for (colToCopy = 0; colToCopy <= static_cast<int32_T>
                        (ForEach_itr - 1); colToCopy = static_cast<int32_T>
                        (colToCopy + 1)) {
                    WayPoint->data[static_cast<int32_T>(colIdx + colToCopy)] =
                        rtb_VectorConcatenate[2];
                }

                // '<S181>:1:38'
                ImmedMission_emxInit_real_T(&tmp, 2);
                if (rotWayPoint->size[0] == WayPoint->size[0]) {
                    ImmedMission_emxInit_real_T(&rotWayPoint_0, 2);
                    ForEach_itr = rotWayPoint->size[0];
                    colIdx = rotWayPoint->size[0];
                    ForEach_itr_c = rotWayPoint->size[0];
                    coffset = static_cast<int32_T>(rotWayPoint_0->size[0] *
                        rotWayPoint_0->size[1]);
                    rotWayPoint_0->size[0] = rotWayPoint->size[0];
                    rotWayPoint_0->size[1] = 3;
                    ImmedMission_emxEnsureCapacity_real_T(rotWayPoint_0, coffset);
                    for (coffset = 0; coffset <= static_cast<int32_T>
                            (ForEach_itr - 1); coffset++) {
                        rotWayPoint_0->data[coffset] = rotWayPoint->data[
                            static_cast<int32_T>(coffset + rotWayPoint->size[0])];
                    }

                    for (coffset = 0; coffset <= static_cast<int32_T>(colIdx - 1);
                         coffset++) {
                        rotWayPoint_0->data[static_cast<int32_T>(coffset +
                            rotWayPoint_0->size[0])] = rotWayPoint->data[coffset];
                    }

                    for (coffset = 0; coffset <= static_cast<int32_T>
                            (ForEach_itr_c - 1); coffset++) {
                        rotWayPoint_0->data[static_cast<int32_T>(coffset +
                            static_cast<int32_T>(rotWayPoint_0->size[0] << 1))] =
                            rotWayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(rotWayPoint->size[0] << 1) +
                             coffset)];
                    }

                    coffset = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
                    tmp->size[0] = rotWayPoint_0->size[0];
                    tmp->size[1] = 3;
                    ImmedMission_emxEnsureCapacity_real_T(tmp, coffset);
                    ForEach_itr = static_cast<int32_T>(rotWayPoint_0->size[0] *
                        3);
                    for (ForEach_itr_c = 0; ForEach_itr_c <= static_cast<int32_T>
                            (ForEach_itr - 1); ForEach_itr_c++) {
                        tmp->data[ForEach_itr_c] = rotWayPoint_0->
                            data[ForEach_itr_c] + WayPoint->data[ForEach_itr_c];
                    }

                    ImmedMission_emxFree_real_T(&rotWayPoint_0);
                } else {
                    ImmedMission_binary_expand_op(tmp, rotWayPoint, WayPoint);
                }

                ImmedMission_emxFree_real_T(&rotWayPoint);
                ImmedMission_emxFree_real_T(&WayPoint);

                // MATLAB Function: '<S135>/BaseWayPoint'
                localDW->SFunction_DIMS2_b[0] = tmp->size[0];
                localDW->SFunction_DIMS2_b[1] = tmp->size[1];
                ForEach_itr = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
                for (coffset = 0; coffset <= static_cast<int32_T>(ForEach_itr -
                        1); coffset++) {
                    localDW->nedWayPoint[coffset] = tmp->data[coffset];
                }

                ImmedMission_emxFree_real_T(&tmp);

                // Concatenate: '<S135>/Matrix Concatenate' incorporates:
                //   Reshape: '<S129>/ReshapeXe'
                //   SignalConversion generated from: '<S135>/FlightMissionLoc'

                localDW->MatrixConcatenate_DIMS1[0] = static_cast<int32_T>
                    (localDW->SFunction_DIMS2_b[0] + 1);
                localDW->MatrixConcatenate_DIMS1[1] = localDW->
                    SFunction_DIMS2_b[1];
                localDW->MatrixConcatenate_d[0] = rtb_Sum_o[0];
                localDW->MatrixConcatenate_d[localDW->MatrixConcatenate_DIMS1[0]]
                    = rtb_Sum_o[1];
                localDW->MatrixConcatenate_d[static_cast<int32_T>
                    (localDW->MatrixConcatenate_DIMS1[0] << 1)] = rtb_Sum_o[2];
                ForEach_itr = localDW->SFunction_DIMS2_b[1];
                for (coffset = 0; coffset <= static_cast<int32_T>(ForEach_itr -
                        1); coffset++) {
                    colIdx = localDW->SFunction_DIMS2_b[0];
                    for (ForEach_itr_c = 0; ForEach_itr_c <= static_cast<int32_T>
                            (colIdx - 1); ForEach_itr_c++) {
                        localDW->MatrixConcatenate_d[static_cast<int32_T>(
                            static_cast<int32_T>(ForEach_itr_c +
                            static_cast<int32_T>
                            (localDW->MatrixConcatenate_DIMS1[0] * coffset)) + 1)]
                            = localDW->nedWayPoint[static_cast<int32_T>(
                            static_cast<int32_T>(localDW->SFunction_DIMS2_b[0] *
                            coffset) + ForEach_itr_c)];
                    }
                }

                // End of Concatenate: '<S135>/Matrix Concatenate'

                // Sum: '<S135>/Minus' incorporates:
                //   Reshape: '<S129>/ReshapeXe'
                //   Selector: '<S135>/Selector'
                //   SignalConversion generated from: '<S135>/FlightMissionLoc'

                localDW->Minus[0] = localDW->nedWayPoint[0] - rtb_Sum_o[0];
                localDW->Minus[1] = localDW->nedWayPoint
                    [localDW->SFunction_DIMS2_b[0]] - rtb_Sum_o[1];
                localDW->Minus[2] = localDW->nedWayPoint[static_cast<int32_T>
                    (localDW->SFunction_DIMS2_b[0] << 1)] - rtb_Sum_o[2];
            }

            // End of Outputs for SubSystem: '<S129>/WayPointGen'

            // SignalConversion generated from: '<S129>/Waypoint Follower' incorporates:
            //   Constant: '<S129>/InitTrigger'
            //   MATLAB Function: '<S135>/BaseWayPoint'
            //   Sum: '<S18>/Sum of Elements'
            //   Sum: '<S249>/Sum of Elements'

            rtb_TmpSignalConversionAtOrbitFollowerInport1[0] = rtb_North;
            rtb_TmpSignalConversionAtOrbitFollowerInport1[1] = rtb_East;
            rtb_TmpSignalConversionAtOrbitFollowerInport1[2] = rtb_Abs1;

            // MATLABSystem: '<S129>/Waypoint Follower' incorporates:
            //   Concatenate: '<S135>/Matrix Concatenate'

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.CacheInputSizes) ^ 1))) {
                localDW->obj.CacheInputSizes = true;
                for (coffset = 0; coffset < 8; coffset++) {
                    localDW->obj.inputVarSize[0].f1[coffset] = 1U;
                }

                coffset = localDW->MatrixConcatenate_DIMS1[0];
                if (localDW->MatrixConcatenate_DIMS1[0] < 0) {
                    coffset = 0;
                }

                localDW->obj.inputVarSize[1].f1[0] = static_cast<uint32_T>
                    (coffset);
                coffset = localDW->MatrixConcatenate_DIMS1[1];
                if (localDW->MatrixConcatenate_DIMS1[1] < 0) {
                    coffset = 0;
                }

                localDW->obj.inputVarSize[1].f1[1] = static_cast<uint32_T>
                    (coffset);
                for (coffset = 0; coffset < 6; coffset++) {
                    localDW->obj.inputVarSize[1].f1[static_cast<int32_T>(coffset
                        + 2)] = 1U;
                }

                for (coffset = 0; coffset < 8; coffset++) {
                    localDW->obj.inputVarSize[2].f1[coffset] = 1U;
                }
            }

            coffset = localDW->MatrixConcatenate_DIMS1[0];
            if (localDW->MatrixConcatenate_DIMS1[0] < 0) {
                coffset = 0;
            }

            inSize[0] = static_cast<uint32_T>(coffset);
            coffset = localDW->MatrixConcatenate_DIMS1[1];
            if (localDW->MatrixConcatenate_DIMS1[1] < 0) {
                coffset = 0;
            }

            inSize[1] = static_cast<uint32_T>(coffset);
            for (coffset = 0; coffset < 6; coffset++) {
                inSize[static_cast<int32_T>(coffset + 2)] = 1U;
            }

            ForEach_itr = 0;
            exitg1 = false;
            while ((!exitg1) && (ForEach_itr < 8)) {
                if (localDW->obj.inputVarSize[1].f1[ForEach_itr] !=
                        inSize[ForEach_itr]) {
                    for (coffset = 0; coffset < 8; coffset++) {
                        localDW->obj.inputVarSize[1].f1[coffset] =
                            inSize[coffset];
                    }

                    exitg1 = true;
                } else {
                    ForEach_itr = static_cast<int32_T>(ForEach_itr + 1);
                }
            }

            localDW->obj.LookaheadDistFlag = 0U;
            localDW->obj.InitialPose[0] = 0.0;
            localDW->obj.InitialPose[1] = 0.0;
            localDW->obj.InitialPose[2] = 0.0;
            localDW->obj.InitialPose[3] = 0.0;
            for (coffset = 0; coffset < 30723; coffset++) {
                localDW->paddedWaypts[coffset] = (rtNaN);
            }

            ForEach_itr = localDW->MatrixConcatenate_DIMS1[0];
            for (coffset = 0; coffset < 3; coffset++) {
                for (ForEach_itr_c = 0; ForEach_itr_c <= static_cast<int32_T>
                        (ForEach_itr - 1); ForEach_itr_c++) {
                    localDW->paddedWaypts[static_cast<int32_T>(ForEach_itr_c +
                        static_cast<int32_T>(10241 * coffset))] =
                        localDW->MatrixConcatenate_d[static_cast<int32_T>(
                        static_cast<int32_T>(localDW->MatrixConcatenate_DIMS1[0]
                        * coffset) + ForEach_itr_c)];
                }
            }

            rtb_Compare_lh = false;
            rtb_Ctrl = true;
            ForEach_itr = 0;
            exitg1 = false;
            while ((!exitg1) && (ForEach_itr < 30723)) {
                if ((localDW->obj.WaypointsInternal[ForEach_itr] ==
                        localDW->paddedWaypts[ForEach_itr]) || (std::isnan
                        (localDW->obj.WaypointsInternal[ForEach_itr]) && std::
                        isnan(localDW->paddedWaypts[ForEach_itr]))) {
                    ForEach_itr = static_cast<int32_T>(ForEach_itr + 1);
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
            //   ActionPort: '<S9>/Action Port'

            MatrixConcatenate_d.data = &localDW->MatrixConcatenate_d[0];
            MatrixConcatenate_DIMS1[0] = localDW->MatrixConcatenate_DIMS1[0];
            MatrixConcatenate_DIMS1[1] = localDW->MatrixConcatenate_DIMS1[1];

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            MatrixConcatenate_d.size = &MatrixConcatenate_DIMS1[0];
            MatrixConcatenate_d.allocatedSize = 30723;
            MatrixConcatenate_d.numDimensions = 2;
            MatrixConcatenate_d.canFreeData = false;

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S9>/Action Port'

            // MATLABSystem: '<S129>/Waypoint Follower' incorporates:
            //   Concatenate: '<S135>/Matrix Concatenate'

            ImmedMission_WaypointFollowerBase_getDistinctWpts
                (&MatrixConcatenate_d, waypointsIn, localDW);
            localDW->obj.NumWaypoints = static_cast<real_T>(waypointsIn->size[0]);
            localDW->obj.LookaheadDistance = 150.0;

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            ImmedMission_emxInit_real_T(&tmp_1, 2);

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S9>/Action Port'

            // MATLABSystem: '<S129>/Waypoint Follower' incorporates:
            //   SignalConversion generated from: '<S129>/Waypoint Follower'

            if (static_cast<boolean_T>(static_cast<int32_T>((waypointsIn->size[0]
                   == 0) | (waypointsIn->size[1] == 0)))) {
                rtb_Abs1_k = rtb_Abs1;
                rtb_North = rtb_HeadingAngle;

                // MATLABSystem: '<S129>/Waypoint Follower' incorporates:
                //   SignalConversion generated from: '<S129>/Waypoint Follower'

                localDW->WaypointFollower_o5 = 1U;
            } else {
                boolean_T guard1;
                guard1 = false;
                if (waypointsIn->size[0] == 1) {
                    if (localDW->obj.StartFlag) {
                        localDW->obj.InitialPose[0] = rtb_North;
                        localDW->obj.InitialPose[1] = rtb_East;
                        localDW->obj.InitialPose[2] = rtb_Abs1;
                        localDW->obj.InitialPose[3] = rtb_HeadingAngle;
                    }

                    rtb_VectorConcatenate[0] = waypointsIn->data[0] - rtb_North;
                    rtb_VectorConcatenate[1] = waypointsIn->data[1] - rtb_East;
                    rtb_VectorConcatenate[2] = waypointsIn->data[2] - rtb_Abs1;
                    if (ImmedMission_norm_pv(rtb_VectorConcatenate) <
                            1.4901161193847656E-8) {
                        rtb_Abs1_k = rtb_Abs1;
                        rtb_North = rtb_HeadingAngle;

                        // MATLABSystem: '<S129>/Waypoint Follower' incorporates:
                        //   SignalConversion generated from: '<S129>/Waypoint Follower'

                        localDW->WaypointFollower_o5 = 1U;
                        localDW->obj.StartFlag = false;
                    } else {
                        localDW->obj.StartFlag = false;
                        localDW->obj.NumWaypoints = 2.0;
                        waypointsIn_0[0] = 1;
                        waypointsIn_0[1] = 3;
                        coffset = static_cast<int32_T>(tmp_1->size[0] *
                            tmp_1->size[1]);
                        tmp_1->size[0] = 2;
                        tmp_1->size[1] = 3;
                        ImmedMission_emxEnsureCapacity_real_T(tmp_1, coffset);
                        for (coffset = 0; coffset < 3; coffset++) {
                            tmp_1->data[static_cast<int32_T>(tmp_1->size[0] *
                                coffset)] = localDW->obj.InitialPose[coffset];
                            tmp_1->data[static_cast<int32_T>(1 +
                                static_cast<int32_T>(tmp_1->size[0] * coffset))]
                                = waypointsIn->data[static_cast<int32_T>(
                                static_cast<int32_T>(waypointsIn_0[0]) * coffset)];
                        }

                        coffset = static_cast<int32_T>(waypointsIn->size[0] *
                            waypointsIn->size[1]);
                        waypointsIn->size[0] = 2;
                        waypointsIn->size[1] = 3;
                        ImmedMission_emxEnsureCapacity_real_T(waypointsIn,
                            coffset);
                        for (coffset = 0; coffset < 6; coffset++) {
                            waypointsIn->data[coffset] = tmp_1->data[coffset];
                        }

                        guard1 = true;
                    }
                } else {
                    guard1 = true;
                }

                if (guard1) {
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

                    rtb_VectorConcatenate[0] = waypointsIn->data
                        [static_cast<int32_T>(static_cast<int32_T>
                        (localDW->obj.WaypointIndex) - 1)];
                    rtb_Abs1_k = waypointsIn->data[static_cast<int32_T>(
                        static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0) -
                        1)];
                    rtb_Sum_o[0] = rtb_North - rtb_Abs1_k;
                    rtb_Switch = rtb_Abs1_k;
                    rtb_VectorConcatenate[1] = waypointsIn->data
                        [static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(localDW->obj.WaypointIndex) +
                         waypointsIn->size[0]) - 1)];
                    rtb_Abs1_k = waypointsIn->data[static_cast<int32_T>(
                        static_cast<int32_T>(static_cast<int32_T>
                        (localDW->obj.WaypointIndex + 1.0) + waypointsIn->size[0])
                        - 1)];
                    rtb_Sum_o[1] = rtb_East - rtb_Abs1_k;
                    rtb_Sum_n = rtb_Abs1_k;
                    rtb_VectorConcatenate[2] = waypointsIn->data
                        [static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(waypointsIn->size[0] << 1) +
                         static_cast<int32_T>(localDW->obj.WaypointIndex)) - 1)];
                    rtb_Abs1_k = waypointsIn->data[static_cast<int32_T>(
                        static_cast<int32_T>(static_cast<int32_T>
                        (localDW->obj.WaypointIndex + 1.0) + static_cast<int32_T>
                        (waypointsIn->size[0] << 1)) - 1)];
                    rtb_Sum_o[2] = rtb_Abs1 - rtb_Abs1_k;
                    rtb_Abs1 = ImmedMission_norm_pv(rtb_Sum_o);
                    guard2 = false;
                    if (rtb_Abs1 <= 100.0) {
                        guard2 = true;
                    } else {
                        rtb_HeadingAngle = rtb_Switch - rtb_VectorConcatenate[0];
                        turnVector[0] = rtb_HeadingAngle;
                        rtb_Switch_gh = rtb_Sum_n - rtb_VectorConcatenate[1];
                        turnVector[1] = rtb_Switch_gh;
                        rtb_Switch_m2 = rtb_Abs1_k - rtb_VectorConcatenate[2];
                        turnVector[2] = rtb_Switch_m2;
                        rtb_Product2 = ImmedMission_norm_pv(turnVector);
                        rtb_HeadingAngle = (rtb_HeadingAngle / rtb_Product2 *
                                            (rtb_Sum_o[0] / rtb_Abs1) +
                                            rtb_Switch_gh / rtb_Product2 *
                                            (rtb_Sum_o[1] / rtb_Abs1)) +
                            rtb_Switch_m2 / rtb_Product2 * (rtb_Sum_o[2] /
                            rtb_Abs1);
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(std::isnan(rtb_HeadingAngle))
                              ^ 1))) {
                            if (rtb_HeadingAngle < 0.0) {
                                rtb_HeadingAngle = -1.0;
                            } else {
                                rtb_HeadingAngle = static_cast<real_T>
                                    (rtb_HeadingAngle > 0.0);
                            }
                        }

                        if (rtb_HeadingAngle >= 0.0) {
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

                        rtb_VectorConcatenate[0] = waypointsIn->data[
                            static_cast<int32_T>(static_cast<int32_T>
                            (localDW->obj.WaypointIndex) - 1)];
                        rtb_Switch = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>(localDW->obj.WaypointIndex +
                            1.0) - 1)];
                        rtb_VectorConcatenate[1] = waypointsIn->data[
                            static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(localDW->obj.WaypointIndex) +
                            waypointsIn->size[0]) - 1)];
                        rtb_Sum_n = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<int32_T>
                            (localDW->obj.WaypointIndex + 1.0) +
                            waypointsIn->size[0]) - 1)];
                        rtb_VectorConcatenate[2] = waypointsIn->data[
                            static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(waypointsIn->size[0] << 1) +
                            static_cast<int32_T>(localDW->obj.WaypointIndex)) -
                            1)];
                        rtb_Abs1_k = waypointsIn->data[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<int32_T>
                            (localDW->obj.WaypointIndex + 1.0) +
                            static_cast<int32_T>(waypointsIn->size[0] << 1)) - 1)];
                    }

                    t = rtb_Switch - rtb_VectorConcatenate[0];
                    rtb_QuaternionInterpolation_idx_2 = rtb_North -
                        rtb_VectorConcatenate[0];
                    rtb_Product2 = rtb_Sum_n - rtb_VectorConcatenate[1];
                    rtb_HeadingAngle = rtb_East - rtb_VectorConcatenate[1];
                    stateNew_idx_0 = rtb_Abs1_k - rtb_VectorConcatenate[2];
                    rtb_Sum_dq = rtb_TmpSignalConversionAtOrbitFollowerInport1[2]
                        - rtb_VectorConcatenate[2];
                    rtb_Abs1 = ((rtb_HeadingAngle * rtb_Product2 +
                                 rtb_QuaternionInterpolation_idx_2 * t) +
                                rtb_Sum_dq * stateNew_idx_0) / ((rtb_Product2 *
                        rtb_Product2 + t * t) + stateNew_idx_0 * stateNew_idx_0);
                    if (rtb_Abs1 < 0.0) {
                        rtb_Sum_o[0] = rtb_QuaternionInterpolation_idx_2;
                        rtb_Sum_o[1] = rtb_HeadingAngle;
                        rtb_Sum_o[2] = rtb_Sum_dq;
                        rtb_Abs1 = ImmedMission_norm_pv(rtb_Sum_o);
                    } else if (rtb_Abs1 > 1.0) {
                        rtb_Sum_o[0] = rtb_North - rtb_Switch;
                        rtb_Sum_o[1] = rtb_East - rtb_Sum_n;
                        rtb_Sum_o[2] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[2] -
                            rtb_Abs1_k;
                        rtb_Abs1 = ImmedMission_norm_pv(rtb_Sum_o);
                    } else {
                        rtb_Sum_o[0] = rtb_North - (rtb_Abs1 * t +
                            rtb_VectorConcatenate[0]);
                        rtb_Sum_o[1] = rtb_East - (rtb_Abs1 * rtb_Product2 +
                            rtb_VectorConcatenate[1]);
                        rtb_Sum_o[2] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[2] -
                            (rtb_Abs1 * stateNew_idx_0 + rtb_VectorConcatenate[2]);
                        rtb_Abs1 = ImmedMission_norm_pv(rtb_Sum_o);
                    }

                    if (localDW->obj.LastWaypointFlag) {
                        rtb_Abs1 = (((rtb_East - rtb_VectorConcatenate[1]) *
                                     rtb_Product2 +
                                     rtb_QuaternionInterpolation_idx_2 * t) +
                                    (rtb_TmpSignalConversionAtOrbitFollowerInport1
                                     [2] - rtb_VectorConcatenate[2]) *
                                    (rtb_Abs1_k - rtb_VectorConcatenate[2])) /
                            (((rtb_Sum_n - rtb_VectorConcatenate[1]) *
                              (rtb_Sum_n - rtb_VectorConcatenate[1]) + t * t) +
                             (rtb_Abs1_k - rtb_VectorConcatenate[2]) *
                             (rtb_Abs1_k - rtb_VectorConcatenate[2]));
                        rtb_Sum_o[0] = rtb_North - (rtb_Abs1 * t +
                            rtb_VectorConcatenate[0]);
                        rtb_Sum_o[1] = rtb_East - (rtb_Abs1 * rtb_Product2 +
                            rtb_VectorConcatenate[1]);
                        rtb_Sum_o[2] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1[2] -
                            (rtb_Abs1 * stateNew_idx_0 + rtb_VectorConcatenate[2]);
                        rtb_Abs1 = ImmedMission_norm_pv(rtb_Sum_o);
                    }

                    rtb_HeadingAngle = std::abs(rtb_Abs1);
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                            (static_cast<int32_T>(std::isinf(rtb_HeadingAngle)) ^
                             1))) & static_cast<int32_T>(static_cast<boolean_T>(
                            static_cast<int32_T>(static_cast<int32_T>(std::isnan
                              (rtb_HeadingAngle)) ^ 1)))))) {
                        if (rtb_HeadingAngle <= 2.2250738585072014E-308) {
                            rtb_East = 4.94065645841247E-324;
                            rtb_North = 4.94065645841247E-324;
                        } else {
                            frexp(rtb_HeadingAngle, &rtb_BiasNumUAV);
                            rtb_East = std::ldexp(1.0, static_cast<int32_T>
                                                  (rtb_BiasNumUAV - 53));
                            frexp(rtb_HeadingAngle, &rtb_BiasOldIdx);
                            rtb_North = std::ldexp(1.0, static_cast<int32_T>
                                                   (rtb_BiasOldIdx - 53));
                        }
                    } else {
                        rtb_East = (rtNaN);
                        rtb_North = (rtNaN);
                    }

                    if (localDW->obj.LookaheadDistance <= std::fmax(std::sqrt
                            (rtb_East), 5.0 * rtb_North) + rtb_Abs1) {
                        localDW->obj.LookaheadDistance =
                            localDW->obj.LookaheadFactor * rtb_Abs1;
                    }

                    rtb_North = rtb_VectorConcatenate[0] -
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[0];
                    rtb_East = rtb_VectorConcatenate[1] -
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[1];
                    rtb_HeadingAngle = ((rtb_Switch - rtb_VectorConcatenate[0]) *
                                        (rtb_Switch - rtb_VectorConcatenate[0])
                                        + (rtb_Sum_n - rtb_VectorConcatenate[1])
                                        * (rtb_Sum_n - rtb_VectorConcatenate[1]))
                        + (rtb_Abs1_k - rtb_VectorConcatenate[2]) * (rtb_Abs1_k
                        - rtb_VectorConcatenate[2]);
                    rtb_Switch_m2 = rtb_VectorConcatenate[2] -
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[2];
                    rtb_Abs1 = ((t * rtb_North + rtb_Product2 * rtb_East) +
                                stateNew_idx_0 * rtb_Switch_m2) * 2.0;
                    rtb_North = std::sqrt(rtb_Abs1 * rtb_Abs1 - (((rtb_North *
                        rtb_North + rtb_East * rtb_East) + rtb_Switch_m2 *
                                            rtb_Switch_m2) -
                                           localDW->obj.LookaheadDistance *
                                           localDW->obj.LookaheadDistance) *
                                          (4.0 * rtb_HeadingAngle));
                    rtb_North = std::fmax((-rtb_Abs1 + rtb_North) / 2.0 /
                                          rtb_HeadingAngle, (-rtb_Abs1 -
                                           rtb_North) / 2.0 / rtb_HeadingAngle);
                    rtb_Abs1_k = (1.0 - rtb_North) * rtb_VectorConcatenate[2] +
                        rtb_North * rtb_Abs1_k;
                    rtb_North = rt_atan2d_snf(((1.0 - rtb_North) *
                        rtb_VectorConcatenate[1] + rtb_North * rtb_Sum_n) -
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[1], ((1.0
                        - rtb_North) * rtb_VectorConcatenate[0] + rtb_North *
                        rtb_Switch) -
                        rtb_TmpSignalConversionAtOrbitFollowerInport1[0]);

                    // MATLABSystem: '<S129>/Waypoint Follower' incorporates:
                    //   SignalConversion generated from: '<S129>/Waypoint Follower'

                    localDW->WaypointFollower_o5 = 0U;
                    rtb_Compare_lh = false;
                    if (localDW->obj.LastWaypointFlag) {
                        rtb_Compare_lh = true;
                    }

                    if (rtb_Compare_lh) {
                        // MATLABSystem: '<S129>/Waypoint Follower'
                        localDW->WaypointFollower_o5 = 1U;
                    }

                    localDW->obj.LastWaypointFlag = false;
                }
            }

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
            ImmedMission_emxFree_real_T(&tmp_1);
            ImmedMission_emxFree_real_T(&waypointsIn);

            // Outputs for IfAction SubSystem: '<S1>/Mode131_SqCalibr' incorporates:
            //   ActionPort: '<S9>/Action Port'

            // DataTypeConversion: '<S129>/DoubleStatus'
            *rty_TaskStatus = static_cast<real_T>(localDW->WaypointFollower_o5);

            // BusCreator: '<S129>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S129>/Param4'
            //   Gain: '<S129>/Down2Height'
            //   MATLABSystem: '<S129>/Waypoint Follower'

            rty_GuidanceCMD->Height = -rtb_Abs1_k;
            rty_GuidanceCMD->AirSpeed = static_cast<real_T>
                (rtu_MissionInput->params.Param4);
            rty_GuidanceCMD->HeadingAngle = rtb_North;

            // Sum: '<S130>/Add3' incorporates:
            //   Product: '<S130>/Element product'

            rtb_Abs1 = rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                localDW->Minus[1] - localDW->Minus[0] *
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

            // Signum: '<S129>/Sign'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Abs1)) ^ 1))) {
                if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                } else {
                    rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                }
            }

            // End of Signum: '<S129>/Sign'

            // Chart: '<S129>/TriggerCalibrStart' incorporates:
            //   Product: '<S129>/Product'

            // Gateway: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
            localDW->xSign_prev = localDW->xSign_start;
            localDW->xSign_start = rtb_Abs1;

            // During: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
            if (static_cast<uint32_T>(localDW->is_active_c7_ImmedMission) == 0U)
            {
                localDW->xSign_prev = rtb_Abs1;

                // Entry: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
                localDW->is_active_c7_ImmedMission = 1U;

                // Entry Internal: ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart 
                // Transition: '<S134>:2'
                localDW->is_c7_ImmedMission = ImmedMission_IN_Waiting;

                // Entry 'Waiting': '<S134>:1'
                rtb_Ctrl = false;
            } else if (localDW->is_c7_ImmedMission == ImmedMission_IN_Running) {
                // During 'Running': '<S134>:3'
                rtb_Ctrl = true;

                // During 'Waiting': '<S134>:1'
            } else if (static_cast<boolean_T>(static_cast<int32_T>
                        ((localDW->Minus[0] *
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                          localDW->Minus[1] *
                          rtb_TmpSignalConversionAtOrbitFollowerInport2[1] < 0.0)
                         & (localDW->xSign_prev != localDW->xSign_start)))) {
                // Transition: '<S134>:4'
                localDW->is_c7_ImmedMission = ImmedMission_IN_Running;

                // Entry 'Running': '<S134>:3'
                rtb_Ctrl = true;
            } else {
                rtb_Ctrl = false;
            }

            // End of Chart: '<S129>/TriggerCalibrStart'
            rtb_Compare_lh = false;

            // SignalConversion generated from: '<S9>/ControlSwitch' incorporates:
            //   Constant: '<S129>/ShiftSimUAV'

            rty_ControlSwitch[0] = rtb_Ctrl;
            rty_ControlSwitch[1] = rtb_Ctrl;

            // End of Outputs for SubSystem: '<S1>/Mode131_SqCalibr'
        }
        break;

      case 4:
        {
            ZCEventType zcEvent;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // SystemReset for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
                //   ActionPort: '<S10>/Action Port'

                // SystemReset for Triggered SubSystem: '<S183>/WayPointGen'
                // SystemReset for SwitchCase: '<S1>/Switch Case'
                localZCE->WayPointGen_Trig_ZCE = NEG_ZCSIG;

                // End of SystemReset for SubSystem: '<S183>/WayPointGen'
                ImmedMission_Altitude_Reset(&localDW->Altitude);
                ImmedMission_Altitude_Reset(&localDW->Heading);

                // End of SystemReset for SubSystem: '<S1>/Mode132_pAttack'
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode132_pAttack' incorporates:
            //   ActionPort: '<S10>/Action Port'

            // SignalConversion generated from: '<S183>/Altitude'
            rtb_TmpSignalConversionAtAltitudeInport1[0] = rtb_North;
            rtb_TmpSignalConversionAtAltitudeInport1[1] = rtb_East;
            rtb_TmpSignalConversionAtAltitudeInport1[2] = rtb_Abs1;
            rtb_TmpSignalConversionAtAltitudeInport1[3] = rtb_HeadingAngle;

            // Reshape: '<S183>/RowVecPose'
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_North;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_East;

            // Sum: '<S185>/Sum1' incorporates:
            //   DataStoreRead: '<S183>/LatitudeGCS'
            //   DataStoreRead: '<S183>/LongitudeGCS'
            //   Sum: '<S188>/Sum'
            //   Switch: '<S200>/Switch'

            rtb_Sum1[0] = rtu_MissionInput->MissionLocation.Lat - LatitudeGCS;
            rtb_Sum1[1] = rtu_MissionInput->MissionLocation.Lon - LongitudeGCS;

            // Switch: '<S194>/Switch' incorporates:
            //   Abs: '<S194>/Abs'
            //   Bias: '<S194>/Bias'
            //   Bias: '<S194>/Bias1'
            //   Constant: '<S194>/Constant2'
            //   Constant: '<S195>/Constant'
            //   Math: '<S194>/Math Function1'
            //   RelationalOperator: '<S195>/Compare'

            if (std::abs(rtb_Sum1[0]) > 180.0) {
                rtb_North = rt_modd_snf(rtb_Sum1[0] + 180.0, 360.0) + -180.0;
            } else {
                rtb_North = rtb_Sum1[0];
            }

            // End of Switch: '<S194>/Switch'

            // Abs: '<S191>/Abs1'
            rtb_East = std::abs(rtb_North);

            // Switch: '<S191>/Switch' incorporates:
            //   Bias: '<S191>/Bias'
            //   Bias: '<S191>/Bias1'
            //   Constant: '<S187>/Constant'
            //   Constant: '<S187>/Constant1'
            //   Constant: '<S193>/Constant'
            //   Gain: '<S191>/Gain'
            //   Product: '<S191>/Divide1'
            //   RelationalOperator: '<S193>/Compare'
            //   Switch: '<S187>/Switch1'

            if (rtb_East > 90.0) {
                // Signum: '<S191>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (rtb_North)) ^ 1))) {
                    if (rtb_North < 0.0) {
                        rtb_North = -1.0;
                    } else {
                        rtb_North = static_cast<real_T>(rtb_North > 0.0);
                    }
                }

                // End of Signum: '<S191>/Sign1'
                rtb_North *= -(rtb_East + -90.0) + 90.0;
                coffset = 180;
            } else {
                coffset = 0;
            }

            // End of Switch: '<S191>/Switch'

            // Sum: '<S187>/Sum'
            rtb_East = static_cast<real_T>(coffset) + rtb_Sum1[1];

            // Switch: '<S192>/Switch' incorporates:
            //   Abs: '<S192>/Abs'
            //   Bias: '<S192>/Bias'
            //   Bias: '<S192>/Bias1'
            //   Constant: '<S192>/Constant2'
            //   Constant: '<S196>/Constant'
            //   Math: '<S192>/Math Function1'
            //   RelationalOperator: '<S196>/Compare'

            if (std::abs(rtb_East) > 180.0) {
                rtb_East = rt_modd_snf(rtb_East + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S192>/Switch'

            // UnitConversion: '<S190>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1[0] = 0.017453292519943295 * rtb_North;
            rtb_Sum1[1] = 0.017453292519943295 * rtb_East;

            // Sum: '<S206>/Sum1' incorporates:
            //   Constant: '<S206>/Constant'
            //   Product: '<S206>/Product1'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_East = 1.0 - 0.0066943799901413295 *
                rtb_QuaternionInterpolation_idx_3 *
                rtb_QuaternionInterpolation_idx_3;

            // Product: '<S204>/Product1' incorporates:
            //   Constant: '<S204>/Constant1'
            //   Sqrt: '<S204>/sqrt'

            rtb_North = 6.378137E+6 / std::sqrt(rtb_East);

            // Product: '<S189>/dNorth' incorporates:
            //   Constant: '<S204>/Constant2'
            //   Product: '<S204>/Product3'
            //   Trigonometry: '<S204>/Trigonometric Function1'

            rtb_East = rtb_Sum1[0] / rt_atan2d_snf(1.0, rtb_North *
                0.99330562000985867 / rtb_East);

            // Product: '<S189>/dEast' incorporates:
            //   Constant: '<S204>/Constant3'
            //   Product: '<S204>/Product4'
            //   Trigonometry: '<S204>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_North = 1.0 / rt_atan2d_snf(1.0, rtb_North *
                rtb_QuaternionInterpolation_idx_2) * rtb_Sum1[1];

            // Reshape: '<S183>/ReshapeRowVec' incorporates:
            //   DataStoreRead: '<S183>/AltitudeGCS'
            //   Gain: '<S183>/inverse'
            //   Product: '<S189>/x*cos'
            //   Product: '<S189>/x*sin'
            //   Product: '<S189>/y*cos'
            //   Product: '<S189>/y*sin'
            //   Sum: '<S185>/Sum'
            //   Sum: '<S189>/Sum2'
            //   Sum: '<S189>/Sum3'
            //   UnaryMinus: '<S185>/Ze2height'

            rtb_Sum_o[0] = rtb_North * 0.0 + rtb_East;
            rtb_Sum_o[1] = rtb_North - rtb_East * 0.0;
            rtb_Sum_o[2] = -(rtu_MissionInput->MissionLocation.Alt +
                             -AltitudeGCS);

            // Outputs for Triggered SubSystem: '<S183>/WayPointGen' incorporates:
            //   TriggerPort: '<S186>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &localZCE->WayPointGen_Trig_ZCE,
                               (1.0));
            if (zcEvent != NO_ZCEVENT) {
                // Concatenate: '<S186>/Matrix Concatenate' incorporates:
                //   Reshape: '<S183>/ReshapeRowVec'
                //   Reshape: '<S183>/RowVecPose'
                //   SignalConversion generated from: '<S186>/MyPose'

                localDW->MatrixConcatenate[0] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                localDW->MatrixConcatenate[1] = rtb_Sum_o[0];
                localDW->MatrixConcatenate[2] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                localDW->MatrixConcatenate[3] = rtb_Sum_o[1];
                localDW->MatrixConcatenate[4] = rtb_Abs1;
                localDW->MatrixConcatenate[5] = rtb_Sum_o[2];
            }

            // End of Outputs for SubSystem: '<S183>/WayPointGen'
            ImmedMission_Altitude(rtb_TmpSignalConversionAtAltitudeInport1,
                                  localDW->MatrixConcatenate, 50.0,
                                  &localDW->Altitude);

            // Sum: '<S184>/Sum' incorporates:
            //   Constant: '<S183>/Constant'
            //   Constant: '<S183>/InitTrigger'
            //   Reshape: '<S183>/ReshapeRowVec'
            //   Reshape: '<S183>/RowVecPose'

            rtb_East = rtb_TmpSignalConversionAtOrbitFollowerInport2[0] -
                rtb_Sum_o[0];

            // DotProduct: '<S184>/Dot Product'
            rtb_North = rtb_East * rtb_East;

            // Sum: '<S184>/Sum' incorporates:
            //   Reshape: '<S183>/ReshapeRowVec'
            //   Reshape: '<S183>/RowVecPose'

            rtb_East = rtb_TmpSignalConversionAtOrbitFollowerInport2[1] -
                rtb_Sum_o[1];

            // DotProduct: '<S184>/Dot Product'
            rtb_North += rtb_East * rtb_East;

            // Sum: '<S184>/Sum' incorporates:
            //   Reshape: '<S183>/ReshapeRowVec'
            //   Reshape: '<S183>/RowVecPose'

            rtb_East = rtb_Abs1 - rtb_Sum_o[2];

            // Sqrt: '<S184>/sqrt' incorporates:
            //   DotProduct: '<S184>/Dot Product'

            rtb_sqrt = std::sqrt(rtb_East * rtb_East + rtb_North);
            ImmedMission_Altitude(rtb_TmpSignalConversionAtAltitudeInport1,
                                  localDW->MatrixConcatenate, rtb_sqrt,
                                  &localDW->Heading);

            // Switch: '<S183>/Switch' incorporates:
            //   Logic: '<S183>/AND'

            if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                    (localDW->Altitude.Altitude_o5) != 0) & (static_cast<int32_T>
                    (localDW->Heading.Altitude_o5) != 0)))) {
                // DataTypeConversion: '<S183>/DoubleStatus' incorporates:
                //   Constant: '<S183>/Attack'

                *rty_TaskStatus = 658475.0;
            } else {
                // DataTypeConversion: '<S183>/DoubleStatus' incorporates:
                //   Constant: '<S183>/Zero'

                *rty_TaskStatus = 0.0;
            }

            // End of Switch: '<S183>/Switch'

            // BusCreator: '<S183>/GuidanceCMDBusCreator' incorporates:
            //   Gain: '<S183>/Down2Height'

            rty_GuidanceCMD->Height = -localDW->Altitude.Altitude_o1[2];
            rty_GuidanceCMD->AirSpeed = 0.0;
            rty_GuidanceCMD->HeadingAngle = localDW->Heading.HeadingAngle;
            rtb_Compare_lh = false;
            rty_ControlSwitch[0] = true;
            rty_ControlSwitch[1] = false;

            // End of Outputs for SubSystem: '<S1>/Mode132_pAttack'
        }
        break;

      case 5:
        {
            boolean_T guard1;
            boolean_T guard2;
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // SystemReset for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU' incorporates:
                //   ActionPort: '<S12>/Action Port'

                // SystemReset for Atomic SubSystem: '<S217>/SailDistance'
                // SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
                //   Chart: '<S219>/EnableSailShift'

                localDW->temporalCounter_i1 = 0U;
                localDW->is_active_c12_ImmedMission = 0U;
                localDW->is_c12_ImmedMission = ImmedMission_IN_NO_ACTIVE_CHILD;

                // End of SystemReset for SubSystem: '<S217>/SailDistance'
                // End of SystemReset for SubSystem: '<S1>/Mode254_ShiftEarthENU' 
            }

            // Outputs for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU' incorporates:
            //   ActionPort: '<S12>/Action Port'

            // Outputs for Atomic SubSystem: '<S217>/SailDistance'
            // Outputs for Enabled SubSystem: '<S219>/SailShift' incorporates:
            //   EnablePort: '<S221>/Enable'

            // Gain: '<S218>/Gain1' incorporates:
            //   Gain: '<S222>/Gain1'

            rtb_Abs1 = 0.017453292519943295 *
                rtu_MissionInput->StartPosition.degHDG;

            // End of Outputs for SubSystem: '<S219>/SailShift'
            // End of Outputs for SubSystem: '<S217>/SailDistance'

            // SignalConversion generated from: '<S217>/Coordinate Transformation Conversion' incorporates:
            //   Constant: '<S217>/Zero'
            //   Gain: '<S218>/Gain1'

            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                0] = rtb_Abs1;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                1] = 0.0;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e[
                2] = 0.0;
            ImmedMission_CoordinateTransformationConversion
                (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_e,
                 &localDW->CoordinateTransformationConversion);

            // Product: '<S217>/Product' incorporates:
            //   MATLABSystem: '<S217>/Coordinate Transformation Conversion'
            //   Reshape: '<S217>/Reshape'

            for (coffset = 0; coffset < 3; coffset++) {
                rtb_TmpSignalConversionAtOrbitFollowerInport2[coffset] =
                    (localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                     [static_cast<int32_T>(static_cast<int32_T>(3 * coffset) + 1)]
                     * rtu_MissionInput->StartPosition.Lon +
                     localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                     [static_cast<int32_T>(3 * coffset)] *
                     rtu_MissionInput->StartPosition.Lat) +
                    localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                    [static_cast<int32_T>(static_cast<int32_T>(3 * coffset) + 2)]
                    * rtu_MissionInput->StartPosition.Alt;
            }

            // End of Product: '<S217>/Product'

            // Outputs for Atomic SubSystem: '<S217>/SailDistance'
            // Chart: '<S219>/EnableSailShift'
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
                // Transition: '<S220>:5'
                localDW->is_c12_ImmedMission = ImmedMission_IN_NotShift;
                localDW->temporalCounter_i1 = 0U;

                // Entry 'NotShift': '<S220>:4'
                guard1 = true;
            } else if (localDW->is_c12_ImmedMission == ImmedMission_IN_NotShift)
            {
                // During 'NotShift': '<S220>:4'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((static_cast<uint32_T>
                        (localDW->temporalCounter_i1) >= 100U) &
                                            (rtu_MissionInput->params.Param5 !=
                        0.0F)))) {
                    // Transition: '<S220>:8'
                    localDW->is_c12_ImmedMission = ImmedMission_IN_Shift;

                    // Entry 'Shift': '<S220>:6'
                    guard2 = true;
                } else {
                    guard1 = true;
                }

                // During 'Shift': '<S220>:6'
            } else if (rtu_MissionInput->params.Param5 == 0.0F) {
                // Transition: '<S220>:9'
                localDW->is_c12_ImmedMission = ImmedMission_IN_NotShift;
                localDW->temporalCounter_i1 = 0U;

                // Entry 'NotShift': '<S220>:4'
                guard1 = true;
            } else {
                guard2 = true;
            }

            if (guard2) {
                // Outputs for Enabled SubSystem: '<S219>/SailShift' incorporates:
                //   EnablePort: '<S221>/Enable'

                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (localDW->SailShift_MODE) ^ 1))) {
                    // InitializeConditions for DiscreteIntegrator: '<S221>/Discrete-Time Integrator' 
                    localDW->DiscreteTimeIntegrator_DSTATE[0] = 0.0;
                    localDW->DiscreteTimeIntegrator_DSTATE[1] = 0.0;
                    localDW->SailShift_MODE = true;
                }

                // Product: '<S221>/Product' incorporates:
                //   Trigonometry: '<S221>/Cos'
                //   Trigonometry: '<S221>/Sin'

                localDW->Product[0] = static_cast<real_T>
                    (rtu_MissionInput->params.Param5) * std::cos(rtb_Abs1);
                localDW->Product[1] = static_cast<real_T>
                    (rtu_MissionInput->params.Param5) * std::sin(rtb_Abs1);

                // DiscreteIntegrator: '<S221>/Discrete-Time Integrator'
                localDW->DiscreteTimeIntegrator[0] = 0.05 * localDW->Product[0]
                    + localDW->DiscreteTimeIntegrator_DSTATE[0];
                localDW->DiscreteTimeIntegrator[1] = 0.05 * localDW->Product[1]
                    + localDW->DiscreteTimeIntegrator_DSTATE[1];

                // End of Outputs for SubSystem: '<S219>/SailShift'

                // Switch: '<S219>/Switch'
                rtb_Sum1[0] = localDW->DiscreteTimeIntegrator[0];
                rtb_Sum1[1] = localDW->DiscreteTimeIntegrator[1];
            }

            if (guard1) {
                // Outputs for Enabled SubSystem: '<S219>/SailShift' incorporates:
                //   EnablePort: '<S221>/Enable'

                localDW->SailShift_MODE = false;

                // End of Outputs for SubSystem: '<S219>/SailShift'

                // Switch: '<S219>/Switch' incorporates:
                //   Constant: '<S219>/Zero'

                rtb_Sum1[0] = 0.0;
                rtb_Sum1[1] = 0.0;
            }

            // End of Chart: '<S219>/EnableSailShift'
            // End of Outputs for SubSystem: '<S217>/SailDistance'

            // Sum: '<S217>/AddEast'
            rtb_Abs1 = (rtu_SimUAVstate->East +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0]) +
                rtb_Sum1[1];

            // Sum: '<S217>/AddHeight'
            rtb_North = rtu_SimUAVstate->Height +
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

            // Sum: '<S217>/AddNorth'
            rtb_East = (rtu_SimUAVstate->North +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1]) +
                rtb_Sum1[0];

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   BusAssignment: '<S217>/Bus Assignment'

            localDW->MergeCollAvoidSimUAV = *rtu_SimUAVstate;

            // BusAssignment: '<S217>/Bus Assignment'
            localDW->MergeCollAvoidSimUAV.North = rtb_East;
            localDW->MergeCollAvoidSimUAV.East = rtb_Abs1;
            localDW->MergeCollAvoidSimUAV.Height = rtb_North;
            rty_ControlSwitch[0] = false;
            rty_ControlSwitch[1] = false;

            // SignalConversion generated from: '<S12>/ShiftSimUAVswitch' incorporates:
            //   Constant: '<S217>/Constant'
            //   Constant: '<S217>/ControlHdg'
            //   Constant: '<S217>/ControlSpd'

            rtb_Compare_lh = true;

            // SignalConversion generated from: '<S12>/thisTaskStatus'
            *rty_TaskStatus = 0.0;

            // End of Outputs for SubSystem: '<S1>/Mode254_ShiftEarthENU'
        }
        break;

      case 6:
        // Outputs for IfAction SubSystem: '<S1>/Mode253_ShiftBodyXYZ' incorporates:
        //   ActionPort: '<S11>/Action Port'

        // SignalConversion generated from: '<S210>/Coordinate Transformation Conversion' 
        rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[0] =
            rtu_SimUAVstate->HeadingAngle;
        rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[1] =
            rtu_SimUAVstate->FlightPathAngle;
        rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[2] =
            rtu_SimUAVstate->RollAngle;
        ImmedMission_CoordinateTransformationConversion
            (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1,
             &localDW->CoordinateTransformationConversion_j);

        // Product: '<S210>/Matrix Multiply' incorporates:
        //   MATLABSystem: '<S210>/Coordinate Transformation Conversion'
        //   SignalConversion generated from: '<S210>/Matrix Multiply'

        for (coffset = 0; coffset < 3; coffset++) {
            rtb_Sum_o[coffset] =
                (localDW->CoordinateTransformationConversion_j.CoordinateTransformationConversion
                 [static_cast<int32_T>(coffset + 3)] *
                 rtu_MissionInput->StartPosition.Lon +
                 localDW->CoordinateTransformationConversion_j.CoordinateTransformationConversion
                 [coffset] * 0.0) +
                localDW->CoordinateTransformationConversion_j.CoordinateTransformationConversion
                [static_cast<int32_T>(coffset + 6)] *
                rtu_MissionInput->StartPosition.Alt;
        }

        // End of Product: '<S210>/Matrix Multiply'

        // Sum: '<S210>/AddEast'
        rtb_North = rtu_SimUAVstate->East + rtb_Sum_o[1];

        // Sum: '<S210>/AddHeight'
        rtb_East = rtu_SimUAVstate->Height + rtb_Sum_o[2];

        // Sum: '<S210>/AddNorth'
        rtb_HeadingAngle = rtu_SimUAVstate->North + rtb_Sum_o[0];

        // BusAssignment: '<S210>/Bus Assignment'
        rtb_Switch_gh = rtu_SimUAVstate->AirSpeed;
        rtb_Switch_m2 = rtu_SimUAVstate->HeadingAngle;
        rtb_Switch = rtu_SimUAVstate->FlightPathAngle;
        rtb_Sum_n = rtu_SimUAVstate->RollAngle;

        // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
        //   BusAssignment: '<S210>/Bus Assignment'

        localDW->MergeCollAvoidSimUAV.RollAngleRate =
            rtu_SimUAVstate->RollAngleRate;

        // Trigonometry: '<S214>/sincos' incorporates:
        //   SignalConversion generated from: '<S214>/sincos'

        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = std::cos
            (rtb_Switch_m2);
        rtb_Sum_dq = std::sin(rtb_Switch_m2);
        rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = std::cos(rtb_Switch);
        rtb_Abs1 = std::sin(rtb_Switch);
        rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = std::cos(rtb_Sum_n);
        rtb_Abs1_k = std::sin(rtb_Sum_n);

        // Fcn: '<S214>/Fcn11'
        rtb_VectorConcatenate_a[0] =
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

        // Fcn: '<S214>/Fcn21' incorporates:
        //   Fcn: '<S214>/Fcn22'

        rtb_Product2 = rtb_Abs1 * rtb_Abs1_k;
        rtb_VectorConcatenate_a[1] = rtb_Product2 *
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] - rtb_Sum_dq *
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

        // Fcn: '<S214>/Fcn31' incorporates:
        //   Fcn: '<S214>/Fcn32'

        t = rtb_Abs1 * rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
        rtb_VectorConcatenate_a[2] = t *
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] + rtb_Sum_dq *
            rtb_Abs1_k;

        // Fcn: '<S214>/Fcn12'
        rtb_VectorConcatenate_a[3] = rtb_Sum_dq *
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

        // Fcn: '<S214>/Fcn22'
        rtb_VectorConcatenate_a[4] = rtb_Product2 * rtb_Sum_dq +
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

        // Fcn: '<S214>/Fcn32'
        rtb_VectorConcatenate_a[5] = t * rtb_Sum_dq -
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] * rtb_Abs1_k;

        // Fcn: '<S214>/Fcn13'
        rtb_VectorConcatenate_a[6] = -rtb_Abs1;

        // Fcn: '<S214>/Fcn23'
        rtb_VectorConcatenate_a[7] =
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] * rtb_Abs1_k;

        // Fcn: '<S214>/Fcn33'
        rtb_VectorConcatenate_a[8] =
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

        // Product: '<S210>/Product' incorporates:
        //   Concatenate: '<S215>/Vector Concatenate'
        //   Reshape: '<S210>/Reshape'

        for (coffset = 0; coffset < 3; coffset++) {
            rtb_Sum_o[coffset] = (rtb_VectorConcatenate_a[static_cast<int32_T>(
                                   static_cast<int32_T>(3 * coffset) + 1)] * 0.0
                                  + rtb_VectorConcatenate_a[static_cast<int32_T>
                                  (3 * coffset)] * rtb_Switch_gh) +
                rtb_VectorConcatenate_a[static_cast<int32_T>(static_cast<int32_T>
                (3 * coffset) + 2)] * 0.0;
        }

        // End of Product: '<S210>/Product'

        // Outputs for Enabled SubSystem: '<S210>/DivisionByZeroProtection'
        ImmedMission_DivisionByZeroProtection(rtb_Switch_gh * std::cos
            (rtb_Switch), 9.81 * std::tan(rtb_Sum_n), &localDW->Omega_g);

        // End of Outputs for SubSystem: '<S210>/DivisionByZeroProtection'

        // Product: '<S210>/Divide' incorporates:
        //   Gain: '<S210>/Gravity'
        //   Product: '<S210>/HorizSpd'
        //   Trigonometry: '<S210>/Cos'
        //   Trigonometry: '<S210>/Tan'

        rtb_Abs1 = rtu_MissionInput->StartPosition.Lat /
            rtu_SimUAVstate->AirSpeed;

        // MATLAB Function: '<S210>/ConstTurnPred' incorporates:
        //   BusAssignment: '<S210>/Bus Assignment'
        //   Gain: '<S210>/Inverse'
        //   Gain: '<S213>/Gain'

        // MATLAB Function 'ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/ConstTurnPred': '<S211>:1' 
        // '<S211>:1:2'
        stateNew_idx_0 = rtb_HeadingAngle;
        rtb_Product2 = rtb_North;
        rtb_HeadingAngle = 57.295779513082323 * localDW->Omega_g;
        rtb_Sum_dq = -rtb_East;

        // '<S211>:1:4'
        rtb_North = std::fmax(std::abs(0.017453292519943295 * rtb_HeadingAngle),
                              2.2204460492503131E-16);
        rtb_BiasNumUAV = 0;
        if (rtb_HeadingAngle < 0.0) {
            rtb_BiasNumUAV = 1;
        }

        if (static_cast<int32_T>(rtb_BiasNumUAV - 1) >= 0) {
            rtb_QuaternionInterpolation_idx_0 = -rtb_North;
        }

        if (rtb_HeadingAngle < 0.0) {
            rtb_North = rtb_QuaternionInterpolation_idx_0;
        }

        rtb_East = rtb_North * rtb_Abs1;
        rtb_HeadingAngle = std::sin(rtb_East) / rtb_North;
        rtb_Abs1_k = (1.0 - std::cos(rtb_East)) / rtb_North;

        // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
        //   BusAssignment: '<S210>/FinalStateBus'

        // '<S211>:1:5'
        localDW->MergeCollAvoidSimUAV.AirSpeed = rtb_Switch_gh;
        localDW->MergeCollAvoidSimUAV.HeadingAngle = rtb_Switch_m2;
        localDW->MergeCollAvoidSimUAV.FlightPathAngle = rtb_Switch;
        localDW->MergeCollAvoidSimUAV.RollAngle = rtb_Sum_n;

        // MATLAB Function: '<S210>/ConstTurnPred'
        rtb_East = rtb_Abs1 * rtb_Abs1 * 0.5 * 0.0;

        // BusAssignment: '<S210>/FinalStateBus' incorporates:
        //   Gain: '<S210>/Down2Up'
        //   MATLAB Function: '<S210>/ConstTurnPred'
        //   Product: '<S210>/Product'

        localDW->MergeCollAvoidSimUAV.North = ((rtb_HeadingAngle * rtb_Sum_o[0]
            + stateNew_idx_0) - rtb_Abs1_k * rtb_Sum_o[1]) + rtb_East;
        localDW->MergeCollAvoidSimUAV.East = ((rtb_Abs1_k * rtb_Sum_o[0] +
            rtb_Product2) + rtb_HeadingAngle * rtb_Sum_o[1]) + rtb_East;
        localDW->MergeCollAvoidSimUAV.Height = -((rtb_Sum_o[2] * rtb_Abs1 +
            rtb_Sum_dq) + rtb_East);
        rty_ControlSwitch[0] = false;
        rty_ControlSwitch[1] = false;

        // SignalConversion generated from: '<S11>/ShiftSimUAVswitch' incorporates:
        //   Constant: '<S210>/Constant'
        //   Constant: '<S210>/ControlHdg'
        //   Constant: '<S210>/ControlSpd'

        rtb_Compare_lh = true;

        // SignalConversion generated from: '<S11>/thisTaskStatus'
        *rty_TaskStatus = 0.0;

        // End of Outputs for SubSystem: '<S1>/Mode253_ShiftBodyXYZ'
        break;

      default:
        {
            int32_T colToCopy;

            // Outputs for IfAction SubSystem: '<S1>/AvoidInterPlaneCollision' incorporates:
            //   ActionPort: '<S5>/Action Port'

            // Logic: '<S14>/AND' incorporates:
            //   Constant: '<S14>/ControlSpd'

            rty_ControlSwitch[0] = false;
            rty_ControlSwitch[1] = false;

            // DataTypeConversion: '<S14>/Cast To Double'
            *rty_TaskStatus = 0.0;

            // BusCreator: '<S14>/GuidanceCMDBusCreator'
            rty_GuidanceCMD->Height = 0.0;
            rty_GuidanceCMD->AirSpeed = 0.0;
            rty_GuidanceCMD->HeadingAngle = 0.0;

            // Outputs for Iterator SubSystem: '<S14>/For Each Subsystem' incorporates:
            //   ForEach: '<S18>/For Each'

            for (ForEach_itr_c = 0; ForEach_itr_c < 128; ForEach_itr_c++) {
                // Sum: '<S18>/Sum of Elements'
                tmp_0 = 0U;
                for (coffset = 0; coffset < 7; coffset++) {
                    // Sum: '<S18>/Sum of Elements' incorporates:
                    //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
                    //   ForEachSliceSelector generated from: '<S18>/StateNow'
                    //   RelationalOperator: '<S18>/IsNaN'

                    tmp_0 = static_cast<uint32_T>(static_cast<uint32_T>(std::
                        isnan
                        (localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                         static_cast<int32_T>(static_cast<int32_T>(coffset << 7)
                        + ForEach_itr_c)])) + tmp_0);
                }

                // Logic: '<S18>/NOT' incorporates:
                //   Sum: '<S18>/Sum of Elements'

                localDW->CoreSubsys_d[ForEach_itr_c].NOT = (static_cast<int32_T>
                    (static_cast<uint8_T>(tmp_0)) == 0);

                // Outputs for Enabled SubSystem: '<S18>/NoPredNaN' incorporates:
                //   EnablePort: '<S27>/Enable'

                if (localDW->CoreSubsys_d[ForEach_itr_c].NOT) {
                    // ForEachSliceSelector generated from: '<S18>/StateNow' incorporates:
                    //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
                    //   Trigonometry: '<S28>/Tan'
                    //   Trigonometry: '<S32>/sincos'

                    rtb_Abs1 =
                        localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                        static_cast<int32_T>(ForEach_itr_c + 768)];

                    // Gain: '<S28>/Gravity' incorporates:
                    //   ForEachSliceSelector generated from: '<S18>/StateNow'
                    //   Trigonometry: '<S28>/Tan'

                    rtb_CentripetalAcc_p = std::tan(rtb_Abs1) * 9.81;

                    // Outputs for Enabled SubSystem: '<S28>/DivisionByZeroProtection' 
                    ImmedMission_DivisionByZeroProtection
                        (localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                         static_cast<int32_T>(ForEach_itr_c + 384)] * std::cos
                         (localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                          static_cast<int32_T>(ForEach_itr_c + 640)]),
                         rtb_CentripetalAcc_p, &localDW->
                         CoreSubsys_d[ForEach_itr_c].Omega);

                    // End of Outputs for SubSystem: '<S28>/DivisionByZeroProtection' 

                    // ForEachSliceSelector generated from: '<S18>/StateNow' incorporates:
                    //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
                    //   Product: '<S28>/HorizSpd'
                    //   Trigonometry: '<S28>/Cos'
                    //   Trigonometry: '<S32>/sincos'

                    rtb_East =
                        localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                        static_cast<int32_T>(ForEach_itr_c + 512)];

                    // Trigonometry: '<S32>/sincos' incorporates:
                    //   ForEachSliceSelector generated from: '<S18>/StateNow'

                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = std::sin
                        (rtb_East);
                    rtb_Sum_o[0] = std::cos(rtb_East);

                    // ForEachSliceSelector generated from: '<S18>/StateNow' incorporates:
                    //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
                    //   Trigonometry: '<S32>/sincos'

                    rtb_East =
                        localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                        static_cast<int32_T>(ForEach_itr_c + 640)];

                    // Trigonometry: '<S32>/sincos' incorporates:
                    //   ForEachSliceSelector generated from: '<S18>/StateNow'

                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = std::sin
                        (rtb_East);
                    rtb_Sum_o[1] = std::cos(rtb_East);
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = std::sin
                        (rtb_Abs1);
                    rtb_Sum_o[2] = std::cos(rtb_Abs1);

                    // Fcn: '<S32>/Fcn11'
                    rtb_VectorConcatenate_a[0] = rtb_Sum_o[0] * rtb_Sum_o[1];

                    // Fcn: '<S32>/Fcn21' incorporates:
                    //   Fcn: '<S32>/Fcn22'

                    rtb_Product2 =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                    rtb_VectorConcatenate_a[1] = rtb_Product2 * rtb_Sum_o[0] -
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                        rtb_Sum_o[2];

                    // Fcn: '<S32>/Fcn31' incorporates:
                    //   Fcn: '<S32>/Fcn32'

                    t = rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                        rtb_Sum_o[2];
                    rtb_VectorConcatenate_a[2] = t * rtb_Sum_o[0] +
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

                    // Fcn: '<S32>/Fcn12'
                    rtb_VectorConcatenate_a[3] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                        rtb_Sum_o[1];

                    // Fcn: '<S32>/Fcn22'
                    rtb_VectorConcatenate_a[4] = rtb_Product2 *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                        rtb_Sum_o[0] * rtb_Sum_o[2];

                    // Fcn: '<S32>/Fcn32'
                    rtb_VectorConcatenate_a[5] = t *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] -
                        rtb_Sum_o[0] *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

                    // Fcn: '<S32>/Fcn13'
                    rtb_VectorConcatenate_a[6] =
                        -rtb_TmpSignalConversionAtOrbitFollowerInport2[1];

                    // Fcn: '<S32>/Fcn23'
                    rtb_VectorConcatenate_a[7] = rtb_Sum_o[1] *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];

                    // Fcn: '<S32>/Fcn33'
                    rtb_VectorConcatenate_a[8] = rtb_Sum_o[1] * rtb_Sum_o[2];

                    // Product: '<S28>/Product' incorporates:
                    //   Concatenate: '<S33>/Vector Concatenate'
                    //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
                    //   ForEachSliceSelector generated from: '<S18>/StateNow'
                    //   Reshape: '<S28>/Reshape'

                    rtb_Abs1 =
                        localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                        static_cast<int32_T>(ForEach_itr_c + 384)];
                    for (coffset = 0; coffset < 3; coffset++) {
                        rtb_VectorConcatenate[coffset] =
                            (rtb_VectorConcatenate_a[static_cast<int32_T>(
                              static_cast<int32_T>(3 * coffset) + 1)] * 0.0 +
                             rtb_VectorConcatenate_a[static_cast<int32_T>(3 *
                              coffset)] * rtb_Abs1) + rtb_VectorConcatenate_a[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            coffset) + 2)] * 0.0;
                    }

                    // End of Product: '<S28>/Product'

                    // MATLAB Function: '<S28>/MATLAB Function' incorporates:
                    //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
                    //   ForEachSliceSelector generated from: '<S18>/StateNow'
                    //   Gain: '<S28>/Inverse'
                    //   Gain: '<S31>/Gain'
                    //   Product: '<S28>/Product'
                    //   SignalConversion generated from: '<S30>/ SFunction '

                    // MATLAB Function 'ConstTurnPredState/MATLAB Function': '<S30>:1' 
                    // '<S30>:1:2'
                    rtb_HeadingAngle = 57.295779513082323 *
                        localDW->CoreSubsys_d[ForEach_itr_c].Omega;

                    // '<S30>:1:4'
                    rtb_North = std::fmax(std::abs(0.017453292519943295 *
                                           rtb_HeadingAngle),
                                          2.2204460492503131E-16);
                    rtb_BiasNumUAV = 0;
                    if (rtb_HeadingAngle < 0.0) {
                        rtb_BiasNumUAV = 1;
                    }

                    if (static_cast<int32_T>(rtb_BiasNumUAV - 1) >= 0) {
                        rtb_QuaternionInterpolation_idx_0 = -rtb_North;
                    }

                    if (rtb_HeadingAngle < 0.0) {
                        rtb_North = rtb_QuaternionInterpolation_idx_0;
                    }

                    rtb_East = rtb_North * 5.0;
                    rtb_HeadingAngle = std::sin(rtb_East) / rtb_North;
                    rtb_Abs1_k = (1.0 - std::cos(rtb_East)) / rtb_North;

                    // '<S30>:1:5'
                    localDW->CoreSubsys_d[ForEach_itr_c].PredNED[0] =
                        (rtb_HeadingAngle * rtb_VectorConcatenate[0] +
                         localDW->
                         ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[ForEach_itr_c])
                        - rtb_Abs1_k * rtb_VectorConcatenate[1];
                    localDW->CoreSubsys_d[ForEach_itr_c].PredNED[1] =
                        (rtb_Abs1_k * rtb_VectorConcatenate[0] +
                         localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                         static_cast<int32_T>(ForEach_itr_c + 128)]) +
                        rtb_HeadingAngle * rtb_VectorConcatenate[1];
                    localDW->CoreSubsys_d[ForEach_itr_c].PredNED[2] =
                        -localDW->ImpAsg_InsertedFor_OtherUAVNED_at_inport_0[
                        static_cast<int32_T>(ForEach_itr_c + 256)] +
                        rtb_VectorConcatenate[2] * 5.0;

                    // End of MATLAB Function: '<S28>/MATLAB Function'

                    // Gain: '<S28>/Down2Up'
                    localDW->CoreSubsys_d[ForEach_itr_c].Down2Up =
                        -localDW->CoreSubsys_d[ForEach_itr_c].PredNED[2];
                }

                // End of Outputs for SubSystem: '<S18>/NoPredNaN'

                // Switch: '<S18>/Switch' incorporates:
                //   ForEachSliceAssignment generated from: '<S18>/StatePred'
                //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
                //   ForEachSliceSelector generated from: '<S18>/StateNow'
                //   Product: '<S28>/HorizSpd'
                //   Trigonometry: '<S28>/Cos'

                if (localDW->CoreSubsys_d[ForEach_itr_c].NOT) {
                    rtb_ImpAsg_InsertedFor_StatePred_at_inport_0[ForEach_itr_c] =
                        localDW->CoreSubsys_d[ForEach_itr_c].PredNED[0];
                    rtb_ImpAsg_InsertedFor_StatePred_at_inport_0
                        [static_cast<int32_T>(ForEach_itr_c + 128)] =
                        localDW->CoreSubsys_d[ForEach_itr_c].PredNED[1];
                    rtb_ImpAsg_InsertedFor_StatePred_at_inport_0
                        [static_cast<int32_T>(ForEach_itr_c + 256)] =
                        localDW->CoreSubsys_d[ForEach_itr_c].Down2Up;
                } else {
                    rtb_ImpAsg_InsertedFor_StatePred_at_inport_0[ForEach_itr_c] =
                        (rtNaN);
                    rtb_ImpAsg_InsertedFor_StatePred_at_inport_0
                        [static_cast<int32_T>(ForEach_itr_c + 128)] = (rtNaN);
                    rtb_ImpAsg_InsertedFor_StatePred_at_inport_0
                        [static_cast<int32_T>(ForEach_itr_c + 256)] = (rtNaN);
                }

                // End of Switch: '<S18>/Switch'
            }

            // End of Outputs for SubSystem: '<S14>/For Each Subsystem'

            // MATLAB Function: '<S14>/AllUAVstateMAT' incorporates:
            //   ForEachSliceAssignment generated from: '<S18>/StatePred'
            //   ForEachSliceAssignment generated from: '<S249>/OtherUAVNED'
            //   ForEachSliceSelector generated from: '<S18>/StateNow'
            //   Product: '<S28>/HorizSpd'
            //   Trigonometry: '<S28>/Cos'

            // MATLAB Function 'ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/AllUAVstateMAT': '<S15>:1' 
            // '<S15>:1:2'
            for (coffset = 0; coffset < 384; coffset++) {
                x_data[coffset] = std::isnan
                    (rtb_ImpAsg_InsertedFor_StatePred_at_inport_0[coffset]);
            }

            rtb_BiasOldIdx = 0;
            ForEach_itr = 256;
            colToCopy = 0;
            for (ForEach_itr_c = 0; ForEach_itr_c < 128; ForEach_itr_c++) {
                int32_T colIdx;
                boolean_T exitg1;
                idx_data[ForEach_itr_c] = false;
                rtb_BiasOldIdx = static_cast<int32_T>(rtb_BiasOldIdx + 1);
                ForEach_itr = static_cast<int32_T>(ForEach_itr + 1);
                colIdx = rtb_BiasOldIdx;
                exitg1 = false;
                while ((!exitg1) && (colIdx <= ForEach_itr)) {
                    if (x_data[static_cast<int32_T>(colIdx - 1)]) {
                        idx_data[ForEach_itr_c] = true;
                        exitg1 = true;
                    } else {
                        colIdx = static_cast<int32_T>(colIdx + 128);
                    }
                }

                colToCopy = static_cast<int32_T>(colToCopy + static_cast<int32_T>
                    (idx_data[ForEach_itr_c]));
            }

            // '<S15>:1:3'
            if (static_cast<int32_T>(128 - colToCopy) < 1) {
                coffset = -1;
            } else {
                coffset = static_cast<int32_T>(127 - colToCopy);
            }

            localDW->SFunction_DIMS2_m[0] = static_cast<int32_T>(coffset + 1);
            localDW->SFunction_DIMS2_m[1] = 3;

            // End of MATLAB Function: '<S14>/AllUAVstateMAT'

            // Outputs for Enabled SubSystem: '<S17>/DivisionByZeroProtection'
            ImmedMission_DivisionByZeroProtection(rtu_RealUAVState->AirSpeed_mps
                * std::cos(0.017453292519943295 *
                           rtu_RealUAVState->FlightPathAngle_deg), 9.81 * std::
                tan(0.017453292519943295 * rtu_RealUAVState->RollAngle_deg),
                &rtb_Abs1);

            // End of Outputs for SubSystem: '<S17>/DivisionByZeroProtection'

            // MATLAB Function: '<S14>/pdist2' incorporates:
            //   BusCreator: '<S2>/FixedWingGuidanceStateBus'
            //   Gain: '<S17>/Gravity'
            //   Gain: '<S224>/Gain1'
            //   Gain: '<S225>/Gain1'
            //   Product: '<S17>/HorizSpd'
            //   Trigonometry: '<S17>/Cos'
            //   Trigonometry: '<S17>/Tan'

            // MATLAB Function 'ConstTurnPredState/MATLAB Function': '<S22>:1'
            // '<S22>:1:2'
            // '<S22>:1:4'
            // '<S22>:1:5'
            // MATLAB Function 'ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/pdist2': '<S20>:1' 
            if (localDW->SFunction_DIMS2_m[0] == 0) {
                localDW->SFunction_DIMS2 = 0;
            } else {
                localDW->SFunction_DIMS2 = localDW->SFunction_DIMS2_m[0];
            }

            // End of MATLAB Function: '<S14>/pdist2'
            // '<S20>:1:2'
            rtb_Compare_lh = false;

            // Merge: '<S1>/MergeCollAvoidSimUAV' incorporates:
            //   Constant: '<S5>/ShiftSimUAV'
            //   SignalConversion generated from: '<S5>/SimUAVstate'

            localDW->MergeCollAvoidSimUAV = *rtu_SimUAVstate;

            // End of Outputs for SubSystem: '<S1>/AvoidInterPlaneCollision'
        }
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
void ImmedMission_Update(const FixedWingGuidanceStateBus *rtu_SimUAVstate, const
    uint8_T *rtu_RealUAVEngaged, DW_ImmedMission_f_T *localDW)
{
    // Update for Memory: '<S1>/Memory'
    localDW->Memory_PreviousInput = localDW->WaypointFollower_o5;

    // Update for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput_j = *rtu_RealUAVEngaged;

    // Update for SwitchCase: '<S1>/Switch Case'
    switch (localDW->SwitchCase_ActiveSubsystem) {
      case 0:
      case 2:
      case 3:
      case 4:
      case 6:
      case 7:
        break;

      case 1:
        // Update for IfAction SubSystem: '<S1>/Mode129_CollAvoidance' incorporates:
        //   ActionPort: '<S7>/Action Port'

        // Update for Memory: '<S65>/MemoryPrevRange'
        localDW->MemoryPrevRange_PreviousInput = localDW->sqrt_f;

        // Update for Memory: '<S65>/MemoryStatus'
        localDW->MemoryStatus_PreviousInput = localDW->TrackSimPath_o5;
        for (int_T i{0}; i < 359; i++) {
            // Update for S-Function (sfix_udelay): '<S72>/NorthSeq'
            localDW->NorthSeq_X[i] = localDW->NorthSeq_X[static_cast<int_T>(i +
                1)];

            // Update for S-Function (sfix_udelay): '<S72>/EastSeq'
            localDW->EastSeq_X[i] = localDW->EastSeq_X[static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S72>/HeightSeq'
            localDW->HeightSeq_X[i] = localDW->HeightSeq_X[static_cast<int_T>(i
                + 1)];

            // Update for S-Function (sfix_udelay): '<S72>/AirSpdSeq'
            localDW->AirSpdSeq_X[i] = localDW->AirSpdSeq_X[static_cast<int_T>(i
                + 1)];

            // Update for S-Function (sfix_udelay): '<S72>/HdgSeq'
            localDW->HdgSeq_X[i] = localDW->HdgSeq_X[static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S72>/PitchSeq'
            localDW->PitchSeq_X[i] = localDW->PitchSeq_X[static_cast<int_T>(i +
                1)];

            // Update for S-Function (sfix_udelay): '<S72>/RollSeq'
            localDW->RollSeq_X[i] = localDW->RollSeq_X[static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S72>/RollRateSeq'
            localDW->RollRateSeq_X[i] = localDW->RollRateSeq_X[static_cast<int_T>
                (i + 1)];

            // Update for S-Function (sfix_udelay): '<S72>/InDangerSequence'
            localDW->InDangerSequence_X[i] = localDW->InDangerSequence_X[
                static_cast<int_T>(i + 1)];
        }

        // Update for S-Function (sfix_udelay): '<S72>/NorthSeq'
        localDW->NorthSeq_X[359] = rtu_SimUAVstate->North;

        // Update for S-Function (sfix_udelay): '<S72>/EastSeq'
        localDW->EastSeq_X[359] = rtu_SimUAVstate->East;

        // Update for S-Function (sfix_udelay): '<S72>/HeightSeq'
        localDW->HeightSeq_X[359] = rtu_SimUAVstate->Height;

        // Update for S-Function (sfix_udelay): '<S72>/AirSpdSeq'
        localDW->AirSpdSeq_X[359] = rtu_SimUAVstate->AirSpeed;

        // Update for S-Function (sfix_udelay): '<S72>/HdgSeq'
        localDW->HdgSeq_X[359] = rtu_SimUAVstate->HeadingAngle;

        // Update for S-Function (sfix_udelay): '<S72>/PitchSeq'
        localDW->PitchSeq_X[359] = rtu_SimUAVstate->FlightPathAngle;

        // Update for S-Function (sfix_udelay): '<S72>/RollSeq'
        localDW->RollSeq_X[359] = rtu_SimUAVstate->RollAngle;

        // Update for S-Function (sfix_udelay): '<S72>/RollRateSeq'
        localDW->RollRateSeq_X[359] = rtu_SimUAVstate->RollAngleRate;

        // Update for S-Function (sfix_udelay): '<S72>/InDangerSequence'
        localDW->InDangerSequence_X[359] = localDW->InDanger;

        // End of Update for SubSystem: '<S1>/Mode129_CollAvoidance'
        break;

      case 5:
        // Update for IfAction SubSystem: '<S1>/Mode254_ShiftEarthENU' incorporates:
        //   ActionPort: '<S12>/Action Port'

        // Update for Atomic SubSystem: '<S217>/SailDistance'
        // Update for Enabled SubSystem: '<S219>/SailShift' incorporates:
        //   EnablePort: '<S221>/Enable'

        if (localDW->SailShift_MODE) {
            // Update for DiscreteIntegrator: '<S221>/Discrete-Time Integrator'
            localDW->DiscreteTimeIntegrator_DSTATE[0] = 0.05 * localDW->Product
                [0] + localDW->DiscreteTimeIntegrator[0];
            localDW->DiscreteTimeIntegrator_DSTATE[1] = 0.05 * localDW->Product
                [1] + localDW->DiscreteTimeIntegrator[1];
        }

        // End of Update for SubSystem: '<S219>/SailShift'
        // End of Update for SubSystem: '<S217>/SailDistance'
        // End of Update for SubSystem: '<S1>/Mode254_ShiftEarthENU'
        break;
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
