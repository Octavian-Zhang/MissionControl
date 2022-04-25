//
// File: Real2SimGuidance.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.146
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun Apr 24 02:58:34 2022
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
#include "Real2SimGuidance.h"
#include "rtwtypes.h"
#include "Real2SimGuidance_types.h"
#include <cmath>
#include "rt_modd_snf.h"
#include "rt_atan2d_snf.h"
#include "angdiff_WJjwZrD2.h"
#include <cstring>
#include <math.h>
#include "coder_posix_time.h"
#include "split_uvVAOGsE.h"
#include "floor_LKLalLcG.h"
#include <cstdlib>
#include <stddef.h>
#include "div_s32.h"
#include "Real2SimGuidance_private.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Named constants for Chart: '<Root>/EngagementDebouncer'
    const uint8_T Real2SimGuidance_IN_Debounce
{
    1U
};
const uint8_T Real2SimGuidance_IN_Fault{ 1U };

const uint8_T Real2SimGuidance_IN_L0Default{ 2U };

const uint8_T Real2SimGuidance_IN_L0Engaged{ 2U };

const uint8_T Real2SimGuidance_IN_L1Engaged{ 3U };

const uint8_T Real2SimGuidance_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T Real2SimGuidance_IN_Normal{ 2U };

const uint8_T Real2SimGuidance_IN_Off{ 1U };

const uint8_T Real2SimGuidance_IN_On{ 2U };

const uint8_T Real2SimGuidance_IN_Persuit{ 3U };

// Named constants for Chart: '<S8>/Chart'
const uint8_T Real2SimGuidance_IN_NoBias{ 1U };

const uint8_T Real2SimGuidance_IN_hasBias{ 2U };

// Named constants for Chart: '<S71>/MissionSwitchInitialPersuit'
const uint8_T Real2SimGuidance_IN_Initial{ 1U };

const uint8_T Real2SimGuidance_IN_L1Hdg{ 2U };

const uint8_T Real2SimGuidance_IN_L1Hdg_n{ 1U };

const uint8_T Real2SimGuidance_IN_SimPnt{ 3U };

const uint8_T Real2SimGuidance_IN_SimPnt_a{ 2U };

// Named constants for Chart: '<S83>/ControlLogic'
const uint8_T Real2SimGuidance_IN_ADRC{ 1U };

const uint8_T Real2SimGuidance_IN_ADRC2PID{ 1U };

const uint8_T Real2SimGuidance_IN_Debounce_j{ 2U };

const uint8_T Real2SimGuidance_IN_PID{ 1U };

const uint8_T Real2SimGuidance_IN_PID2ADRC{ 2U };

const uint8_T Real2SimGuidance_IN_useADRC{ 2U };

// Named constants for Chart: '<Root>/TASgreaterthan15for1Sec'
const uint8_T Real2SimGuidance_IN_InAir{ 1U };

const uint8_T Real2SimGuidance_IN_NotTakeOff{ 2U };

// Forward declaration for local functions
static void Real2SimGuidance_emxInit_real_T(emxArray_real_T_Real2SimGuidance_T **
    pEmxArray, int32_T numDimensions);
static real_T Real2SimGuidance_norm(const real_T x[3]);
static void Real2SimGuidance_emxFree_real_T(emxArray_real_T_Real2SimGuidance_T **
    pEmxArray);
static void Real2SimGuidance_emxEnsureCapacity_real_T
    (emxArray_real_T_Real2SimGuidance_T *emxArray, int32_T oldNumel);
static void Real2SimGuidance_WaypointFollower_stepImpl
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T currentPose[4], const real_T waypoints[651], real_T
     lookaheadDistance, real_T varargout_1[3], real_T *varargout_2, real_T
     *varargout_3, uint8_T *varargout_4, real_T *varargout_5, uint8_T
     *varargout_6, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
    real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
    real_T *t_tm_year, boolean_T *t_tm_isdst);
static creal_T Real2SimGuidance_two_prod(real_T a);
static creal_T Real2SimGuidance_two_diff(real_T a, real_T b);
static creal_T Real2SimGuidance_times(const creal_T a);
static creal_T Real2SimGuidance_minus(const creal_T a, const creal_T b);
static void Real2SimGuidance_getDateVec(const creal_T dd, real_T *y, real_T *mo,
    real_T *d, real_T *h, real_T *m, real_T *s);
static creal_T Real2SimGuidance_two_sum(real_T a, real_T b);
static creal_T Real2SimGuidance_plus(const creal_T a, real_T b);
static void Real2SimGuidance_emxInit_real_T(emxArray_real_T_Real2SimGuidance_T **
    pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_Real2SimGuidance_T *emxArray;
    *pEmxArray = static_cast<emxArray_real_T_Real2SimGuidance_T *>(std::malloc
        (sizeof(emxArray_real_T_Real2SimGuidance_T)));
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

static real_T Real2SimGuidance_norm(const real_T x[3])
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

static void Real2SimGuidance_emxFree_real_T(emxArray_real_T_Real2SimGuidance_T **
    pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_real_T_Real2SimGuidance_T *>(nullptr))
    {
        if (((*pEmxArray)->data != static_cast<real_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_real_T_Real2SimGuidance_T *>(nullptr);
    }
}

static void Real2SimGuidance_emxEnsureCapacity_real_T
    (emxArray_real_T_Real2SimGuidance_T *emxArray, int32_T oldNumel)
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

static void Real2SimGuidance_WaypointFollower_stepImpl
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T currentPose[4], const real_T waypoints[651], real_T
     lookaheadDistance, real_T varargout_1[3], real_T *varargout_2, real_T
     *varargout_3, uint8_T *varargout_4, real_T *varargout_5, uint8_T
     *varargout_6, DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_real_T_Real2SimGuidance_T *d;
    real_T virtualWaypoint[3];
    real_T waypoints_0[3];
    real_T lambda;
    real_T virtualWaypoint_tmp_tmp;
    real_T virtualWaypoint_tmp_tmp_0;
    real_T virtualWaypoint_tmp_tmp_1;
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T i1;
    int32_T i2;
    int32_T iy;
    int32_T j;
    int32_T waypoints_size_idx_0;
    uint8_T c_data[217];
    boolean_T x[651];
    boolean_T b[217];
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
    p = false;
    p_0 = true;
    iy = 0;
    exitg1 = false;
    while ((!exitg1) && (iy < 651)) {
        if ((obj->WaypointsInternal[iy] == waypoints[iy]) || (std::isnan
                (obj->WaypointsInternal[iy]) && std::isnan(waypoints[iy]))) {
            iy = static_cast<int32_T>(iy + 1);
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
        std::memcpy(&obj->WaypointsInternal[0], &waypoints[0],
                    static_cast<uint32_T>(651U * sizeof(real_T)));
        obj->WaypointIndex = 1.0;
        obj->SearchFlag = true;
    }

    for (iy = 0; iy < 3; iy++) {
        for (j = 0; j < 216; j++) {
            i1 = static_cast<int32_T>(static_cast<int32_T>(217 * iy) + j);
            x[i1] = (waypoints[static_cast<int32_T>(static_cast<int32_T>(
                       static_cast<int32_T>(j + 2) + static_cast<int32_T>(217 *
                        iy)) - 1)] != waypoints[i1]);
        }

        x[static_cast<int32_T>(static_cast<int32_T>(217 * iy) + 216)] = true;
    }

    i1 = 0;
    i2 = 434;
    for (j = 0; j < 217; j++) {
        b[j] = false;
        i1 = static_cast<int32_T>(i1 + 1);
        i2 = static_cast<int32_T>(i2 + 1);
        iy = i1;
        exitg1 = false;
        while ((!exitg1) && (iy <= i2)) {
            if (x[static_cast<int32_T>(iy - 1)]) {
                b[j] = true;
                exitg1 = true;
            } else {
                iy = static_cast<int32_T>(iy + 217);
            }
        }
    }

    i1 = 0;
    for (iy = 0; iy < 217; iy++) {
        if (b[iy]) {
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    i2 = i1;
    i1 = 0;
    for (iy = 0; iy < 217; iy++) {
        if (b[iy]) {
            c_data[i1] = static_cast<uint8_T>(static_cast<int32_T>(iy + 1));
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    for (iy = 0; iy < 3; iy++) {
        for (j = 0; j <= static_cast<int32_T>(i2 - 1); j++) {
            localDW->b_waypointsIn_data[static_cast<int32_T>(j + static_cast<
                int32_T>(i2 * iy))] = waypoints[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(217 * iy) +
                static_cast<int32_T>(c_data[j])) - 1)];
        }
    }

    obj->NumWaypoints = static_cast<real_T>(i2);
    obj->LookaheadDistance = lambda;
    Real2SimGuidance_emxInit_real_T(&d, 2);
    if (i2 == 0) {
        varargout_1[0] = lambda * std::cos(currentPose[3]) + currentPose[0];
        varargout_1[1] = lambda * std::sin(currentPose[3]) + currentPose[1];
        varargout_1[2] = lambda * 0.0 + currentPose[2];
        *varargout_2 = currentPose[3];
        *varargout_3 = currentPose[3];
        *varargout_5 = 0.0;
        *varargout_6 = 1U;
    } else {
        boolean_T guard1{ false };

        guard1 = false;
        if (i2 == 1) {
            if (obj->StartFlag) {
                obj->InitialPose[0] = currentPose[0];
                obj->InitialPose[1] = currentPose[1];
                obj->InitialPose[2] = currentPose[2];
                obj->InitialPose[3] = currentPose[3];
            }

            virtualWaypoint[0] = localDW->b_waypointsIn_data[0] - currentPose[0];
            virtualWaypoint[1] = localDW->b_waypointsIn_data[1] - currentPose[1];
            virtualWaypoint[2] = localDW->b_waypointsIn_data[2] - currentPose[2];
            if (Real2SimGuidance_norm(virtualWaypoint) < 1.4901161193847656E-8)
            {
                varargout_1[0] = lambda * std::cos(currentPose[3]) +
                    currentPose[0];
                varargout_1[1] = lambda * std::sin(currentPose[3]) +
                    currentPose[1];
                varargout_1[2] = lambda * 0.0 + currentPose[2];
                *varargout_2 = currentPose[3];
                *varargout_3 = currentPose[3];
                *varargout_5 = 0.0;
                *varargout_6 = 1U;
                obj->StartFlag = false;
            } else {
                obj->StartFlag = false;
                obj->NumWaypoints = 2.0;
                waypoints_size_idx_0 = static_cast<int32_T>(i2 + 1);
                for (iy = 0; iy < 3; iy++) {
                    i1 = static_cast<int32_T>(static_cast<int32_T>(i2 + 1) * iy);
                    localDW->waypoints_data[i1] = obj->InitialPose[iy];
                    for (j = 0; j <= static_cast<int32_T>(i2 - 1); j++) {
                        localDW->waypoints_data[static_cast<int32_T>(
                            static_cast<int32_T>(j + i1) + 1)] =
                            localDW->b_waypointsIn_data[static_cast<int32_T>(
                            static_cast<int32_T>(i2 * iy) + j)];
                    }
                }

                guard1 = true;
            }
        } else {
            waypoints_size_idx_0 = i2;
            i1 = static_cast<int32_T>(i2 * 3);
            for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                localDW->waypoints_data[iy] = localDW->b_waypointsIn_data[iy];
            }

            guard1 = true;
        }

        if (guard1) {
            real_T b_0;
            real_T lambda_tmp;
            real_T lambda_tmp_0;
            real_T virtualWaypoint_tmp;
            real_T virtualWaypoint_tmp_0;
            real_T virtualWaypoint_tmp_1;
            real_T virtualWaypoint_tmp_tmp_2;
            real_T virtualWaypoint_tmp_tmp_3;
            real_T virtualWaypoint_tmp_tmp_4;
            real_T waypoints_tmp;
            boolean_T guard2{ false };

            if (obj->SearchFlag) {
                i1 = static_cast<int32_T>(d->size[0] * d->size[1]);
                d->size[0] = 1;
                d->size[1] = static_cast<int32_T>(obj->NumWaypoints - 1.0);
                Real2SimGuidance_emxEnsureCapacity_real_T(d, i1);
                j = static_cast<int32_T>(static_cast<int32_T>(obj->NumWaypoints
                    - 1.0) - 1);
                for (iy = 0; iy <= j; iy++) {
                    d->data[iy] = 0.0;
                    virtualWaypoint_tmp_tmp = localDW->waypoints_data[
                        static_cast<int32_T>(static_cast<int32_T>
                        ((static_cast<real_T>(iy) + 1.0) + 1.0) - 1)];
                    virtualWaypoint_tmp_tmp_2 = localDW->waypoints_data[iy];
                    virtualWaypoint_tmp = virtualWaypoint_tmp_tmp -
                        virtualWaypoint_tmp_tmp_2;
                    virtualWaypoint_tmp_tmp_0 = localDW->waypoints_data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>((static_cast<real_T>(iy) + 1.0) +
                        1.0) + waypoints_size_idx_0) - 1)];
                    virtualWaypoint_tmp_tmp_3 = localDW->waypoints_data[
                        static_cast<int32_T>(iy + waypoints_size_idx_0)];
                    virtualWaypoint_tmp_0 = virtualWaypoint_tmp_tmp_0 -
                        virtualWaypoint_tmp_tmp_3;
                    virtualWaypoint_tmp_tmp_1 = localDW->waypoints_data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>((static_cast<real_T>(iy) + 1.0) +
                        1.0) + static_cast<int32_T>(waypoints_size_idx_0 << 1))
                        - 1)];
                    virtualWaypoint_tmp_tmp_4 = localDW->waypoints_data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (waypoints_size_idx_0 << 1) + iy)];
                    virtualWaypoint_tmp_1 = virtualWaypoint_tmp_tmp_1 -
                        virtualWaypoint_tmp_tmp_4;
                    b_0 = currentPose[0] - virtualWaypoint_tmp_tmp_2;
                    lambda_tmp = currentPose[1] - virtualWaypoint_tmp_tmp_3;
                    lambda_tmp_0 = currentPose[2] - virtualWaypoint_tmp_tmp_4;
                    lambda = ((b_0 * virtualWaypoint_tmp + lambda_tmp *
                               virtualWaypoint_tmp_0) + lambda_tmp_0 *
                              virtualWaypoint_tmp_1) / ((virtualWaypoint_tmp *
                        virtualWaypoint_tmp + virtualWaypoint_tmp_0 *
                        virtualWaypoint_tmp_0) + virtualWaypoint_tmp_1 *
                        virtualWaypoint_tmp_1);
                    if (lambda < 0.0) {
                        virtualWaypoint[0] = b_0;
                        virtualWaypoint[1] = lambda_tmp;
                        virtualWaypoint[2] = lambda_tmp_0;
                        d->data[iy] = Real2SimGuidance_norm(virtualWaypoint);
                    } else if (lambda > 1.0) {
                        virtualWaypoint[0] = currentPose[0] -
                            virtualWaypoint_tmp_tmp;
                        virtualWaypoint[1] = currentPose[1] -
                            virtualWaypoint_tmp_tmp_0;
                        virtualWaypoint[2] = currentPose[2] -
                            virtualWaypoint_tmp_tmp_1;
                        d->data[iy] = Real2SimGuidance_norm(virtualWaypoint);
                    } else {
                        virtualWaypoint[0] = currentPose[0] - (lambda *
                            virtualWaypoint_tmp + virtualWaypoint_tmp_tmp_2);
                        virtualWaypoint[1] = currentPose[1] - (lambda *
                            virtualWaypoint_tmp_0 + virtualWaypoint_tmp_tmp_3);
                        virtualWaypoint[2] = currentPose[2] - (lambda *
                            virtualWaypoint_tmp_1 + virtualWaypoint_tmp_tmp_4);
                        d->data[iy] = Real2SimGuidance_norm(virtualWaypoint);
                    }
                }

                iy = d->size[1];
                if (d->size[1] <= 2) {
                    if (d->size[1] == 1) {
                        i1 = 1;
                    } else if ((d->data[0] > d->data[static_cast<int32_T>
                                (d->size[1] - 1)]) || (std::isnan(d->data[0]) &&
                                (static_cast<boolean_T>(static_cast<int32_T>(
                                   static_cast<int32_T>(std::isnan(d->data[
                                     static_cast<int32_T>(d->size[1] - 1)])) ^ 1)))))
                    {
                        i1 = d->size[1];
                    } else {
                        i1 = 1;
                    }
                } else {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(std::isnan(d->data[0])) ^ 1))) {
                        i1 = 1;
                    } else {
                        i1 = 0;
                        j = 2;
                        exitg1 = false;
                        while ((!exitg1) && (j <= iy)) {
                            if (static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(std::isnan(d->data[
                                    static_cast<int32_T>(j - 1)])) ^ 1))) {
                                i1 = j;
                                exitg1 = true;
                            } else {
                                j = static_cast<int32_T>(j + 1);
                            }
                        }
                    }

                    if (i1 == 0) {
                        i1 = 1;
                    } else {
                        lambda = d->data[static_cast<int32_T>(i1 - 1)];
                        i2 = i1;
                        for (j = static_cast<int32_T>(i2 + 1); j <= iy; j++) {
                            b_0 = d->data[static_cast<int32_T>(j - 1)];
                            if (lambda > b_0) {
                                lambda = b_0;
                                i1 = j;
                            }
                        }
                    }
                }

                obj->WaypointIndex = static_cast<real_T>(i1);
                obj->SearchFlag = false;
            }

            p = false;
            if (obj->WaypointIndex == obj->NumWaypoints) {
                p = true;
            }

            if (p) {
                obj->LastWaypointFlag = true;
                obj->WaypointIndex--;
            }

            virtualWaypoint_tmp_tmp_2 = localDW->waypoints_data
                [static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex +
                1.0) - 1)];
            virtualWaypoint[0] = currentPose[0] - virtualWaypoint_tmp_tmp_2;
            virtualWaypoint_tmp_tmp_3 = localDW->waypoints_data
                [static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
                (obj->WaypointIndex + 1.0) + waypoints_size_idx_0) - 1)];
            virtualWaypoint[1] = currentPose[1] - virtualWaypoint_tmp_tmp_3;
            virtualWaypoint_tmp_tmp_4 = localDW->waypoints_data
                [static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
                (obj->WaypointIndex + 1.0) + static_cast<int32_T>
                (waypoints_size_idx_0 << 1)) - 1)];
            virtualWaypoint[2] = currentPose[2] - virtualWaypoint_tmp_tmp_4;
            lambda = Real2SimGuidance_norm(virtualWaypoint);
            guard2 = false;
            if (lambda <= 1.0) {
                guard2 = true;
            } else {
                virtualWaypoint_tmp_tmp_1 = localDW->waypoints_data[static_cast<
                    int32_T>(static_cast<int32_T>(obj->WaypointIndex) - 1)];
                lambda_tmp = virtualWaypoint_tmp_tmp_2 -
                    virtualWaypoint_tmp_tmp_1;
                waypoints_0[0] = lambda_tmp;
                virtualWaypoint_tmp_tmp_0 = localDW->waypoints_data[static_cast<
                    int32_T>(static_cast<int32_T>(static_cast<int32_T>
                              (obj->WaypointIndex) + waypoints_size_idx_0) - 1)];
                lambda_tmp_0 = virtualWaypoint_tmp_tmp_3 -
                    virtualWaypoint_tmp_tmp_0;
                waypoints_0[1] = lambda_tmp_0;
                virtualWaypoint_tmp_tmp = localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(waypoints_size_idx_0 << 1) +
                     static_cast<int32_T>(obj->WaypointIndex)) - 1)];
                waypoints_tmp = virtualWaypoint_tmp_tmp_4 -
                    virtualWaypoint_tmp_tmp;
                waypoints_0[2] = waypoints_tmp;
                b_0 = Real2SimGuidance_norm(waypoints_0);
                lambda = (lambda_tmp / b_0 * (virtualWaypoint[0] / lambda) +
                          lambda_tmp_0 / b_0 * (virtualWaypoint[1] / lambda)) +
                    waypoints_tmp / b_0 * (virtualWaypoint[2] / lambda);
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
                    varargout_1[0] = virtualWaypoint_tmp_tmp_2;
                    varargout_1[1] = virtualWaypoint_tmp_tmp_3;
                    varargout_1[2] = virtualWaypoint_tmp_tmp_4;
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

                virtualWaypoint_tmp_tmp_1 = localDW->waypoints_data[static_cast<
                    int32_T>(static_cast<int32_T>(obj->WaypointIndex) - 1)];
                varargout_1[0] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(obj->WaypointIndex + 1.0) - 1)];
                virtualWaypoint_tmp_tmp_0 = localDW->waypoints_data[static_cast<
                    int32_T>(static_cast<int32_T>(static_cast<int32_T>
                              (obj->WaypointIndex) + waypoints_size_idx_0) - 1)];
                varargout_1[1] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + waypoints_size_idx_0) - 1)];
                virtualWaypoint_tmp_tmp = localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(waypoints_size_idx_0 << 1) +
                     static_cast<int32_T>(obj->WaypointIndex)) - 1)];
                varargout_1[2] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + static_cast<int32_T>(waypoints_size_idx_0 << 1)) -
                    1)];
            }

            virtualWaypoint_tmp = varargout_1[0] - virtualWaypoint_tmp_tmp_1;
            lambda_tmp = currentPose[0] - virtualWaypoint_tmp_tmp_1;
            virtualWaypoint_tmp_0 = varargout_1[1] - virtualWaypoint_tmp_tmp_0;
            lambda_tmp_0 = currentPose[1] - virtualWaypoint_tmp_tmp_0;
            virtualWaypoint_tmp_1 = varargout_1[2] - virtualWaypoint_tmp_tmp;
            b_0 = currentPose[2] - virtualWaypoint_tmp_tmp;
            lambda = ((lambda_tmp_0 * virtualWaypoint_tmp_0 + lambda_tmp *
                       virtualWaypoint_tmp) + b_0 * virtualWaypoint_tmp_1) /
                ((virtualWaypoint_tmp_0 * virtualWaypoint_tmp_0 +
                  virtualWaypoint_tmp * virtualWaypoint_tmp) +
                 virtualWaypoint_tmp_1 * virtualWaypoint_tmp_1);
            if (lambda < 0.0) {
                virtualWaypoint[0] = lambda_tmp;
                virtualWaypoint[1] = lambda_tmp_0;
                virtualWaypoint[2] = b_0;
                *varargout_5 = Real2SimGuidance_norm(virtualWaypoint);
            } else if (lambda > 1.0) {
                virtualWaypoint[0] = currentPose[0] - varargout_1[0];
                virtualWaypoint[1] = currentPose[1] - varargout_1[1];
                virtualWaypoint[2] = currentPose[2] - varargout_1[2];
                *varargout_5 = Real2SimGuidance_norm(virtualWaypoint);
            } else {
                virtualWaypoint[0] = currentPose[0] - (lambda *
                    virtualWaypoint_tmp + virtualWaypoint_tmp_tmp_1);
                virtualWaypoint[1] = currentPose[1] - (lambda *
                    virtualWaypoint_tmp_0 + virtualWaypoint_tmp_tmp_0);
                virtualWaypoint[2] = currentPose[2] - (lambda *
                    virtualWaypoint_tmp_1 + virtualWaypoint_tmp_tmp);
                *varargout_5 = Real2SimGuidance_norm(virtualWaypoint);
            }

            if (obj->LastWaypointFlag) {
                lambda = (((currentPose[0] - virtualWaypoint_tmp_tmp_1) *
                           (varargout_1[0] - virtualWaypoint_tmp_tmp_1) +
                           (currentPose[1] - virtualWaypoint_tmp_tmp_0) *
                           (varargout_1[1] - virtualWaypoint_tmp_tmp_0)) +
                          (currentPose[2] - virtualWaypoint_tmp_tmp) *
                          (varargout_1[2] - virtualWaypoint_tmp_tmp)) /
                    (((varargout_1[0] - virtualWaypoint_tmp_tmp_1) *
                      (varargout_1[0] - virtualWaypoint_tmp_tmp_1) +
                      (varargout_1[1] - virtualWaypoint_tmp_tmp_0) *
                      (varargout_1[1] - virtualWaypoint_tmp_tmp_0)) +
                     (varargout_1[2] - virtualWaypoint_tmp_tmp) * (varargout_1[2]
                      - virtualWaypoint_tmp_tmp));
                virtualWaypoint[0] = currentPose[0] - (lambda *
                    virtualWaypoint_tmp + virtualWaypoint_tmp_tmp_1);
                virtualWaypoint[1] = currentPose[1] - (lambda *
                    virtualWaypoint_tmp_0 + virtualWaypoint_tmp_tmp_0);
                virtualWaypoint[2] = currentPose[2] - (lambda *
                    virtualWaypoint_tmp_1 + virtualWaypoint_tmp_tmp);
                *varargout_5 = Real2SimGuidance_norm(virtualWaypoint);
            }

            b_0 = std::abs(*varargout_5);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isinf(b_0)) ^ 1))) & static_cast<
                    int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
                     static_cast<int32_T>(std::isnan(b_0)) ^ 1)))))) {
                if (b_0 <= 2.2250738585072014E-308) {
                    lambda = 4.94065645841247E-324;
                    b_0 = 4.94065645841247E-324;
                } else {
                    frexp(b_0, &b_exponent);
                    lambda = std::ldexp(1.0, static_cast<int32_T>(b_exponent -
                                         53));
                    frexp(b_0, &b_exponent_0);
                    b_0 = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0 - 53));
                }
            } else {
                lambda = (rtNaN);
                b_0 = (rtNaN);
            }

            if (obj->LookaheadDistance <= std::fmax(std::sqrt(lambda), 5.0 * b_0)
                + *varargout_5) {
                obj->LookaheadDistance = obj->LookaheadFactor * *varargout_5;
            }

            lambda_tmp = virtualWaypoint_tmp_tmp_1 - currentPose[0];
            lambda_tmp_0 = virtualWaypoint_tmp_tmp_0 - currentPose[1];
            lambda = ((varargout_1[0] - virtualWaypoint_tmp_tmp_1) *
                      (varargout_1[0] - virtualWaypoint_tmp_tmp_1) +
                      (varargout_1[1] - virtualWaypoint_tmp_tmp_0) *
                      (varargout_1[1] - virtualWaypoint_tmp_tmp_0)) +
                (varargout_1[2] - virtualWaypoint_tmp_tmp) * (varargout_1[2] -
                virtualWaypoint_tmp_tmp);
            waypoints_tmp = virtualWaypoint_tmp_tmp - currentPose[2];
            b_0 = ((virtualWaypoint_tmp * lambda_tmp + virtualWaypoint_tmp_0 *
                    lambda_tmp_0) + virtualWaypoint_tmp_1 * waypoints_tmp) * 2.0;
            virtualWaypoint_tmp = std::sqrt(b_0 * b_0 - (((lambda_tmp *
                lambda_tmp + lambda_tmp_0 * lambda_tmp_0) + waypoints_tmp *
                waypoints_tmp) - obj->LookaheadDistance * obj->LookaheadDistance)
                * (4.0 * lambda));
            lambda = std::fmax((-b_0 + virtualWaypoint_tmp) / 2.0 / lambda,
                               (-b_0 - virtualWaypoint_tmp) / 2.0 / lambda);
            virtualWaypoint_tmp = (1.0 - lambda) * virtualWaypoint_tmp_tmp_1 +
                lambda * varargout_1[0];
            varargout_1[0] = virtualWaypoint_tmp;
            virtualWaypoint_tmp_0 = (1.0 - lambda) * virtualWaypoint_tmp_tmp_0 +
                lambda * varargout_1[1];
            varargout_1[1] = virtualWaypoint_tmp_0;
            varargout_1[2] = (1.0 - lambda) * virtualWaypoint_tmp_tmp + lambda *
                varargout_1[2];
            *varargout_2 = rt_atan2d_snf(virtualWaypoint_tmp_0 - currentPose[1],
                virtualWaypoint_tmp - currentPose[0]);
            *varargout_3 = *varargout_2;
            *varargout_6 = 0U;
            p = false;
            if (obj->LastWaypointFlag) {
                p = true;
            }

            if (p) {
                *varargout_6 = 1U;
            }

            obj->LastWaypointFlag = false;
        }
    }

    Real2SimGuidance_emxFree_real_T(&d);
}

// Function for MATLAB Function: '<Root>/TimeNow'
static void Real2SimGuidance_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
    real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
    real_T *t_tm_year, boolean_T *t_tm_isdst)
{
    coderTm origStructTm;
    coderLocalTime(&origStructTm);
    *t_tm_nsec = (real_T)origStructTm.tm_nsec;
    *t_tm_sec = static_cast<real_T>(origStructTm.tm_sec);
    *t_tm_min = static_cast<real_T>(origStructTm.tm_min);
    *t_tm_hour = static_cast<real_T>(origStructTm.tm_hour);
    *t_tm_mday = static_cast<real_T>(origStructTm.tm_mday);
    *t_tm_mon = static_cast<real_T>(origStructTm.tm_mon);
    *t_tm_year = static_cast<real_T>(origStructTm.tm_year);
    *t_tm_isdst = (origStructTm.tm_isdst != 0);
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_two_prod(real_T a)
{
    creal_T c;
    creal_T da;
    real_T shi;
    real_T slo;
    int32_T trueCount;
    da = split_uvVAOGsE(a);
    shi = a * 8.64E+7;
    slo = (da.re * 8.64E+7 - shi) + da.im * 8.64E+7;
    trueCount = 0;
    if (std::isnan(slo)) {
        trueCount = 1;
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        slo = 0.0;
    }

    c.re = shi;
    c.im = slo;
    return c;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_two_diff(real_T a, real_T b)
{
    creal_T c;
    real_T bb;
    real_T shi;
    int32_T trueCount;
    shi = a - b;
    bb = shi - a;
    bb = (a - (shi - bb)) - (b + bb);
    trueCount = 0;
    if (std::isnan(bb)) {
        trueCount = 1;
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        bb = 0.0;
    }

    c.re = shi;
    c.im = bb;
    return c;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_times(const creal_T a)
{
    creal_T c;
    real_T ahi;
    real_T alo;
    real_T tmp;
    c = Real2SimGuidance_two_prod(a.re);
    tmp = a.im * 8.64E+7;
    alo = c.im;
    ahi = c.re;
    if (tmp != 0.0) {
        alo = c.im + tmp;
        ahi = c.re + alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    c.re = ahi;
    c.im = alo;
    return c;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_minus(const creal_T a, const creal_T b)
{
    creal_T c;
    creal_T cout;
    creal_T t;
    real_T ahi;
    real_T alo;
    c = Real2SimGuidance_two_diff(a.re, b.re);
    t = Real2SimGuidance_two_diff(a.im, b.im);
    alo = c.im;
    ahi = c.re;
    if (t.re != 0.0) {
        alo = c.im + t.re;
        ahi = c.re + alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    c.re = ahi;
    if (t.im != 0.0) {
        alo += t.im;
        ahi += alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    cout.re = ahi;
    cout.im = alo;
    return cout;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static void Real2SimGuidance_getDateVec(const creal_T dd, real_T *y, real_T *mo,
    real_T *d, real_T *h, real_T *m, real_T *s)
{
    creal_T b_c;
    creal_T b_thi_0;
    creal_T c_s;
    creal_T t;
    real_T b_ahi;
    real_T b_thi;
    real_T b_tmp;
    real_T slo;
    int32_T ic_quot;
    int32_T idn;
    b_c.re = dd.re / 8.64E+7;
    t = Real2SimGuidance_two_prod(b_c.re);
    c_s.re = 0.0;
    c_s.im = 0.0;
    if (dd.re != t.re) {
        c_s = Real2SimGuidance_two_diff(dd.re, t.re);
    }

    c_s.re = (0.0 * dd.im + c_s.re) - 0.0 * t.im;
    c_s.im = (c_s.im + dd.im) - t.im;
    b_tmp = (c_s.re + c_s.im) / 8.64E+7;
    b_ahi = 0.0;
    b_thi = b_c.re;
    if (b_tmp != 0.0) {
        b_thi = b_c.re + b_tmp;
        b_ahi = b_tmp - (b_thi - b_c.re);
    }

    if (std::isnan(b_ahi)) {
        b_ahi = 0.0;
    }

    b_thi_0.re = b_thi;
    b_thi_0.im = b_ahi;
    t = floor_LKLalLcG(b_thi_0);
    b_thi = t.re + t.im;
    b_thi_0 = Real2SimGuidance_minus(dd, Real2SimGuidance_times(t));
    b_c.re = b_thi_0.re / 1000.0;
    t = split_uvVAOGsE(b_c.re);
    b_tmp = b_c.re * 1000.0;
    slo = (t.re * 1000.0 - b_tmp) + t.im * 1000.0;
    idn = 0;
    if (std::isnan(slo)) {
        idn = 1;
    }

    if (static_cast<int32_T>(idn - 1) >= 0) {
        slo = 0.0;
    }

    c_s.re = 0.0;
    c_s.im = 0.0;
    if (b_thi_0.re != b_tmp) {
        c_s = Real2SimGuidance_two_diff(b_thi_0.re, b_tmp);
    }

    c_s.re = (0.0 * b_thi_0.im + c_s.re) - 0.0 * slo;
    c_s.im = (c_s.im + b_thi_0.im) - slo;
    slo = (c_s.re + c_s.im) / 1000.0;
    b_ahi = 0.0;
    b_tmp = b_c.re;
    if (slo != 0.0) {
        b_tmp = b_c.re + slo;
        b_ahi = slo - (b_tmp - b_c.re);
    }

    if (std::isnan(b_ahi)) {
        b_ahi = 0.0;
    }

    b_thi_0.re = b_tmp;
    b_thi_0.im = b_ahi;
    t = floor_LKLalLcG(b_thi_0);
    b_c = Real2SimGuidance_minus(b_thi_0, t);
    b_ahi = t.re + t.im;
    if (static_cast<boolean_T>(static_cast<int32_T>(((b_thi + 719529.0) - 61.0 >=
           0.0) & ((b_thi + 719529.0) - 61.0 <= 2.147483647E+9)))) {
        int32_T ia_quot;
        int32_T ib_rem;
        int32_T ic_rem;
        int32_T ig_rem;
        b_thi = std::round((b_thi + 719529.0) - 61.0);
        if (b_thi < 2.147483648E+9) {
            if (b_thi >= -2.147483648E+9) {
                idn = static_cast<int32_T>(b_thi);
            } else {
                idn = MIN_int32_T;
            }
        } else {
            idn = MAX_int32_T;
        }

        ig_rem = static_cast<int32_T>(idn - static_cast<int32_T>(146097 *
            div_s32(idn, 146097)));
        ic_quot = static_cast<int32_T>(std::trunc(static_cast<real_T>(ig_rem) /
            36524.0));
        ic_rem = static_cast<int32_T>(ig_rem - static_cast<int32_T>(36524 *
            div_s32(ig_rem, 36524)));
        if (ic_quot > 3) {
            ic_quot = 3;
            ic_rem = static_cast<int32_T>(ig_rem - 109572);
        }

        ib_rem = static_cast<int32_T>(ic_rem - static_cast<int32_T>(1461 *
            div_s32(ic_rem, 1461)));
        ia_quot = static_cast<int32_T>(std::trunc(static_cast<real_T>(ib_rem) /
            365.0));
        ig_rem = static_cast<int32_T>(ib_rem - static_cast<int32_T>(365 *
            div_s32(ib_rem, 365)));
        if (ia_quot > 3) {
            ia_quot = 3;
            ig_rem = static_cast<int32_T>(ib_rem - 1095);
        }

        *y = ((std::trunc(static_cast<real_T>(idn) / 146097.0) * 400.0 +
               static_cast<real_T>(ic_quot) * 100.0) + std::trunc
              (static_cast<real_T>(ic_rem) / 1461.0) * 4.0) + static_cast<real_T>
            (ia_quot);
        idn = static_cast<int32_T>(static_cast<int32_T>(std::trunc((static_cast<
            real_T>(ig_rem) * 5.0 + 308.0) / 153.0)) - 2);
        b_thi = static_cast<real_T>(idn);
        *d = ((static_cast<real_T>(ig_rem) - std::trunc((static_cast<real_T>(idn)
                 + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    } else {
        real_T b_a;
        real_T dc;
        b_tmp = std::floor(((b_thi + 719529.0) - 61.0) / 146097.0);
        slo = ((b_thi + 719529.0) - 61.0) - b_tmp * 146097.0;
        b_thi = std::floor(slo / 36524.0);
        if (b_thi > 3.0) {
            b_thi = 3.0;
        }

        dc = slo - b_thi * 36524.0;
        slo = std::floor(dc / 1461.0);
        dc -= slo * 1461.0;
        b_a = std::floor(dc / 365.0);
        if (b_a > 3.0) {
            b_a = 3.0;
        }

        dc -= b_a * 365.0;
        *y = ((b_tmp * 400.0 + b_thi * 100.0) + slo * 4.0) + b_a;
        b_thi = std::floor((dc * 5.0 + 308.0) / 153.0) - 2.0;
        *d = ((dc - std::floor((b_thi + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    }

    if (b_thi > 9.0) {
        (*y)++;
        *mo = (b_thi + 2.0) - 11.0;
    } else {
        *mo = (b_thi + 2.0) + 1.0;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((b_ahi >= 0.0) & (b_ahi <=
            2.147483647E+9)))) {
        idn = static_cast<int32_T>(std::round(b_ahi));
        ic_quot = static_cast<int32_T>(idn - static_cast<int32_T>(3600 * div_s32
            (idn, 3600)));
        *h = std::trunc(static_cast<real_T>(idn) / 3600.0);
        *m = std::trunc(static_cast<real_T>(ic_quot) / 60.0);
        b_ahi = static_cast<real_T>(static_cast<int32_T>(ic_quot -
            static_cast<int32_T>(60 * div_s32(ic_quot, 60))));
    } else {
        *h = std::floor(b_ahi / 3600.0);
        *m = std::floor((b_ahi - 3600.0 * *h) / 60.0);
        b_ahi -= 60.0 * *m;
    }

    *s = (b_c.re + b_c.im) + b_ahi;
    if (*s == 60.0) {
        *s = 59.999999999999993;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((dd.re == (rtInf)) & (dd.im ==
           0.0)))) {
        *y = (rtInf);
    } else if (static_cast<boolean_T>(static_cast<int32_T>((dd.re == (rtMinusInf))
                 & (dd.im == 0.0)))) {
        *y = (rtMinusInf);
    }
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_two_sum(real_T a, real_T b)
{
    creal_T c;
    real_T bb;
    real_T shi;
    int32_T trueCount;
    shi = a + b;
    bb = shi - a;
    bb = (a - (shi - bb)) + (b - bb);
    trueCount = 0;
    if (std::isnan(bb)) {
        trueCount = 1;
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        bb = 0.0;
    }

    c.re = shi;
    c.im = bb;
    return c;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_plus(const creal_T a, real_T b)
{
    creal_T c;
    creal_T t;
    real_T ahi;
    real_T alo;
    c = Real2SimGuidance_two_sum(a.re, b);
    t = Real2SimGuidance_two_sum(a.im, 0.0);
    alo = c.im;
    ahi = c.re;
    if (t.re != 0.0) {
        alo = c.im + t.re;
        ahi = c.re + alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    c.re = ahi;
    if (t.im != 0.0) {
        alo += t.im;
        ahi += alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    c.re = ahi;
    c.im = alo;
    return c;
}

// System initialize for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    // SystemInitialize for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Integrator: '<S70>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S70>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<S8>/GenerateTrack'
    for (int32_T i{0}; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S64>/HeightSequence' 
        localDW->HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<S8>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<S8>/SpeedControl'
    // SystemInitialize for Enabled SubSystem: '<S69>/SpdFBControl'
    // SystemInitialize for Enabled SubSystem: '<S83>/ADRC'
    // InitializeConditions for Integrator: '<S88>/Integrator'
    localX->Integrator_CSTATE[0] = 0.0;
    localX->Integrator_CSTATE[1] = 0.0;
    localX->Integrator_CSTATE[2] = 0.0;

    // End of SystemInitialize for SubSystem: '<S83>/ADRC'
    // End of SystemInitialize for SubSystem: '<S69>/SpdFBControl'
    // End of SystemInitialize for SubSystem: '<S8>/SpeedControl'

    // SystemInitialize for Atomic SubSystem: '<S8>/HeadingLogic'
    // SystemInitialize for Atomic SubSystem: '<S65>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // End of SystemInitialize for SubSystem: '<S65>/NewMissionHdg'

    // Start for MATLABSystem: '<S65>/TrackSimPath'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.SearchFlag = true;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S65>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 651; i++) {
        // InitializeConditions for MATLABSystem: '<S65>/TrackSimPath'
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S8>/HeadingLogic'
    // End of SystemInitialize for SubSystem: '<Root>/Real2SimNav'
}

// System reset for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Reset(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    // SystemReset for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Memory: '<S8>/MemoryNotInBrake'
    localDW->MemoryNotInBrake_PreviousInput = false;

    // InitializeConditions for Memory: '<S8>/Memory'
    localDW->Memory_PreviousInput = 0U;

    // InitializeConditions for Integrator: '<S70>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S70>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemReset for Atomic SubSystem: '<S8>/HeadingNaNProtection'
    // InitializeConditions for Memory: '<S66>/MemoryRefHeight'
    localDW->MemoryRefHeight_PreviousInput = 0.0;

    // End of SystemReset for SubSystem: '<S8>/HeadingNaNProtection'

    // SystemReset for Atomic SubSystem: '<S8>/GenerateTrack'
    for (int32_T i{0}; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S64>/EastSequence' 
        localDW->EastSequence_X[i] = 0.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S64>/HeightSequence' 
        localDW->HeightSequence_X[i] = -150.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S64>/NorthSequence' 
        localDW->NorthSequence_X[i] = 0.0;
    }

    // End of SystemReset for SubSystem: '<S8>/GenerateTrack'

    // SystemReset for Atomic SubSystem: '<S8>/HeadingLogic'
    // InitializeConditions for MATLABSystem: '<S65>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 651; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of InitializeConditions for MATLABSystem: '<S65>/TrackSimPath'

    // SystemReset for Atomic SubSystem: '<S65>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // SystemReset for Chart: '<S71>/MissionSwitchInitialPersuit'
    localDW->temporalCounter_i1 = 0U;
    localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce_m = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2 = 0U;
    localDW->is_active_c3_Real2SimGuidance = 0U;
    localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->SimHdg = 0.0;

    // End of SystemReset for SubSystem: '<S65>/NewMissionHdg'
    // End of SystemReset for SubSystem: '<S8>/HeadingLogic'

    // SystemReset for Chart: '<S8>/Chart'
    localDW->is_active_c2_Real2SimGuidance = 0U;
    localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

    // End of SystemReset for SubSystem: '<Root>/Real2SimNav'

    // SystemReset for Chart: '<Root>/TASgreaterthan15for1Sec'
    localDW->is_active_c16_Real2SimGuidance = 0U;
    localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

    // SystemReset for Chart: '<Root>/EngagementDebouncer'
    localDW->is_Debounce_m4 = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_L0Engaged = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce_b = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2_f = 0U;
    localDW->is_L0Default = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i1_i = 0U;
    localDW->is_active_c34_Real2SimGuidance = 0U;
    localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->Execution = 0.0;

    // SystemReset for MATLAB Function: '<Root>/Get Nominal Flight Speed'
    localDW->SingletonInstance_not_empty = false;
}

// Disable for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW)
{
    // Disable for Atomic SubSystem: '<Root>/Real2SimNav'
    // Disable for Atomic SubSystem: '<S8>/SpeedControl'
    // Disable for Enabled SubSystem: '<S69>/SpdFBControl'
    if (localDW->SpdFBControl_MODE) {
        // Disable for Enabled SubSystem: '<S83>/ADRC'
        localDW->ADRC_MODE = false;

        // End of Disable for SubSystem: '<S83>/ADRC'

        // Disable for Enabled SubSystem: '<S83>/PID'
        localDW->PID_MODE = false;

        // End of Disable for SubSystem: '<S83>/PID'
        localDW->SpdFBControl_MODE = false;
    }

    // End of Disable for SubSystem: '<S69>/SpdFBControl'
    // End of Disable for SubSystem: '<S8>/SpeedControl'
    // End of Disable for SubSystem: '<Root>/Real2SimNav'
}

// Outputs for referenced model: 'Real2SimGuidance'
void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const Real2SimGuidance_M,
                      const boolean_T *rtu_NewMission, const uint8_T
                      *rtu_FlightMode, const StateFCU *rtu_StateFCU, const
                      boolean_T rtu_ControlSwitch[2], const
                      FixedWingGuidanceStateBus *rtu_SimUAVState, const
                      FixedWingGuidanceBus *rtu_ImmedGuidanceCMD, const real_T
                      *rtu_BiasRatio, const real_T *rtu_ParamADRC_hat_b, const
                      real_T *rtu_ParamADRC_omega_o, const real_T
                      *rtu_ParamADRC_omega_b, const real_T *rtu_ParamADRC_P,
                      const real_T *rtu_ParamADRC_I, const real_T
                      *rtu_ParamADRC_D, const boolean_T *rtu_ParamADRC_useADRC,
                      FCUCMD *rty_FCUCMD, uint8_T *rty_EngagedFlag,
                      FlightLogging *rty_FlightLogging, DW_Real2SimGuidance_f_T *
                      localDW, X_Real2SimGuidance_n_T *localX)
{
    // local block i/o variables
    FixedWingGuidanceStateBus rtb_FixedWingGuidanceStateBus;
    real_T rtb_SumNorth;
    real_T rtb_SumEast;
    static const int8_T a[9]{ 0, 0, 0, 1, 0, 0, 0, 1, 0 };

    creal_T inputArg_data;
    real_T rtb_TmpSignalConversionAtSFunctionInport1[4];
    real_T rtb_SwitchLookAheadPoint[3];
    real_T tmp[3];
    real_T Switch;
    real_T rtb_Abs1;
    real_T rtb_Abs1_k;
    real_T rtb_Gain_p;
    real_T rtb_HeadWind;
    real_T rtb_RealUAVNEUState_idx_0;
    real_T rtb_RealUAVNEUState_idx_1;
    real_T rtb_RealUAVNEUState_idx_2;
    real_T rtb_RefAirspeed_Log;
    real_T rtb_Sum1_idx_0;
    real_T rtb_Sum_i;
    real_T rtb_Sum_k;
    real_T rtb_Switch;
    real_T rtb_SwitchLookAheadPoint_c;
    int32_T i;
    uint8_T b_varargout_4;
    uint8_T b_varargout_6;
    uint8_T rtb_Memory;
    boolean_T rtb_GreaterThanOrEqual_h;
    boolean_T rtb_NoNewMission;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        real_T rtb_SwitchLookAheadPoint_0;

        // Sum: '<S14>/Sum1' incorporates:
        //   DataStoreRead: '<S6>/LatitudeGCS'
        //   Switch: '<S28>/Switch'

        rtb_Sum1_idx_0 = rtu_StateFCU->RealUAVState.Latitude_deg - LatitudeGCS;

        // Switch: '<S22>/Switch' incorporates:
        //   Abs: '<S22>/Abs'
        //   Bias: '<S22>/Bias'
        //   Bias: '<S22>/Bias1'
        //   Constant: '<S22>/Constant2'
        //   Constant: '<S23>/Constant'
        //   Math: '<S22>/Math Function1'
        //   RelationalOperator: '<S23>/Compare'

        if (std::abs(rtb_Sum1_idx_0) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Abs1 = rtb_Sum1_idx_0;
        }

        // End of Switch: '<S22>/Switch'

        // Abs: '<S19>/Abs1'
        rtb_Abs1_k = std::abs(rtb_Abs1);

        // Switch: '<S19>/Switch' incorporates:
        //   Bias: '<S19>/Bias'
        //   Bias: '<S19>/Bias1'
        //   Constant: '<S15>/Constant'
        //   Constant: '<S15>/Constant1'
        //   Constant: '<S21>/Constant'
        //   Gain: '<S19>/Gain'
        //   Product: '<S19>/Divide1'
        //   RelationalOperator: '<S21>/Compare'
        //   Switch: '<S15>/Switch1'

        if (rtb_Abs1_k > 90.0) {
            // Signum: '<S19>/Sign1'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Abs1)) ^ 1))) {
                if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                } else {
                    rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                }
            }

            // End of Signum: '<S19>/Sign1'
            rtb_Abs1 *= -(rtb_Abs1_k + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S19>/Switch'

        // Sum: '<S15>/Sum' incorporates:
        //   DataStoreRead: '<S6>/LongitudeGCS'
        //   Sum: '<S14>/Sum1'
        //   Sum: '<S16>/Sum'

        rtb_Sum_k = (rtu_StateFCU->RealUAVState.Longitude_deg - LongitudeGCS) +
            static_cast<real_T>(i);

        // Switch: '<S20>/Switch' incorporates:
        //   Abs: '<S20>/Abs'
        //   Bias: '<S20>/Bias'
        //   Bias: '<S20>/Bias1'
        //   Constant: '<S20>/Constant2'
        //   Constant: '<S24>/Constant'
        //   Math: '<S20>/Math Function1'
        //   RelationalOperator: '<S24>/Compare'

        if (std::abs(rtb_Sum_k) > 180.0) {
            rtb_Sum_k = rt_modd_snf(rtb_Sum_k + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S20>/Switch'

        // UnitConversion: '<S18>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Abs1;
        rtb_Abs1_k = 0.017453292519943295 * rtb_Sum_k;

        // UnitConversion: '<S33>/Unit Conversion' incorporates:
        //   DataStoreRead: '<S6>/LatitudeGCS'
        //   Switch: '<S28>/Switch'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch = 0.017453292519943295 * LatitudeGCS;

        // Trigonometry: '<S34>/Trigonometric Function1'
        rtb_Sum_k = std::sin(rtb_Switch);

        // Sum: '<S34>/Sum1' incorporates:
        //   Constant: '<S34>/Constant'
        //   Product: '<S34>/Product1'

        rtb_Sum_k = 1.0 - 0.0066943799901413295 * rtb_Sum_k * rtb_Sum_k;

        // Product: '<S32>/Product1' incorporates:
        //   Constant: '<S32>/Constant1'
        //   Sqrt: '<S32>/sqrt'

        rtb_Abs1 = 6.378137E+6 / std::sqrt(rtb_Sum_k);

        // Product: '<S17>/dNorth' incorporates:
        //   Constant: '<S32>/Constant2'
        //   Product: '<S32>/Product3'
        //   Trigonometry: '<S32>/Trigonometric Function1'

        rtb_Sum_k = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Abs1 *
            0.99330562000985867 / rtb_Sum_k);

        // Product: '<S17>/dEast' incorporates:
        //   Constant: '<S32>/Constant3'
        //   Product: '<S32>/Product4'
        //   Trigonometry: '<S32>/Trigonometric Function'
        //   Trigonometry: '<S32>/Trigonometric Function2'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Abs1 = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1 * std::cos(rtb_Switch)) *
            rtb_Abs1_k;

        // BusCreator: '<S6>/FixedWingGuidanceStateBus' incorporates:
        //   Constant: '<S6>/dummyRollAngleRate'
        //   DataStoreRead: '<S6>/AltitudeGCS'
        //   Gain: '<S11>/Gain1'
        //   Gain: '<S12>/Gain1'
        //   Gain: '<S13>/Gain1'
        //   Gain: '<S6>/inverse'
        //   Product: '<S17>/x*cos'
        //   Product: '<S17>/x*sin'
        //   Product: '<S17>/y*cos'
        //   Product: '<S17>/y*sin'
        //   Sum: '<S14>/Sum'
        //   Sum: '<S17>/Sum2'
        //   Sum: '<S17>/Sum3'

        rtb_FixedWingGuidanceStateBus.North = rtb_Abs1 * 0.0 + rtb_Sum_k;
        rtb_FixedWingGuidanceStateBus.East = rtb_Abs1 - rtb_Sum_k * 0.0;
        rtb_FixedWingGuidanceStateBus.Height =
            rtu_StateFCU->RealUAVState.Height_meter + -AltitudeGCS;
        rtb_FixedWingGuidanceStateBus.AirSpeed =
            rtu_StateFCU->RealUAVState.AirSpeed_mps;
        rtb_FixedWingGuidanceStateBus.HeadingAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.HeadingAngle_deg;
        rtb_FixedWingGuidanceStateBus.FlightPathAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.FlightPathAngle_deg;
        rtb_FixedWingGuidanceStateBus.RollAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.RollAngle_deg;
        rtb_FixedWingGuidanceStateBus.RollAngleRate = 0.0;

        // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
        // Outputs for Atomic SubSystem: '<S8>/HeadingNaNProtection'
        // Memory: '<S66>/MemoryRefHeight'
        rtb_Abs1_k = localDW->MemoryRefHeight_PreviousInput;

        // End of Outputs for SubSystem: '<S8>/HeadingNaNProtection'

        // Sum: '<S8>/Minus'
        rtb_HeadWind = rtb_FixedWingGuidanceStateBus.AirSpeed -
            rtu_StateFCU->GndSpd_mps;

        // Outputs for Atomic SubSystem: '<S8>/GenerateTrack'
        // S-Function (sfix_udelay): '<S64>/EastSequence'
        localDW->MatrixConcatenate[433] = rtu_SimUAVState->East;

        // S-Function (sfix_udelay): '<S64>/HeightSequence'
        localDW->MatrixConcatenate[650] = rtu_SimUAVState->Height;
        for (i = 0; i < 216; i++) {
            // S-Function (sfix_udelay): '<S64>/EastSequence'
            localDW->MatrixConcatenate[static_cast<int_T>(i + 217)] =
                localDW->EastSequence_X[i];

            // S-Function (sfix_udelay): '<S64>/HeightSequence'
            localDW->MatrixConcatenate[static_cast<int_T>(i + 434)] =
                localDW->HeightSequence_X[i];

            // S-Function (sfix_udelay): '<S64>/NorthSequence'
            localDW->MatrixConcatenate[i] = localDW->NorthSequence_X[i];
        }

        // S-Function (sfix_udelay): '<S64>/NorthSequence'
        localDW->MatrixConcatenate[216] = rtu_SimUAVState->North;

        // End of Outputs for SubSystem: '<S8>/GenerateTrack'

        // Memory: '<S8>/Memory'
        rtb_Memory = localDW->Memory_PreviousInput;

        // Outputs for Atomic SubSystem: '<S8>/SpeedControl'
        // Sum: '<S82>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/TargetLocation'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[60] -
            rtu_SimUAVState->North;

        // DotProduct: '<S82>/Dot Product'
        rtb_SwitchLookAheadPoint_0 = rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S82>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/TargetLocation'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[277] -
            rtu_SimUAVState->East;

        // DotProduct: '<S82>/Dot Product'
        rtb_SwitchLookAheadPoint_0 += rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S82>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/TargetLocation'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[494] -
            rtu_SimUAVState->Height;

        // Sqrt: '<S82>/sqrt' incorporates:
        //   DotProduct: '<S82>/Dot Product'

        rtb_Sum1_idx_0 = std::sqrt(rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c + rtb_SwitchLookAheadPoint_0);

        // Sum: '<S81>/Sum'
        rtb_SwitchLookAheadPoint[0] = rtu_SimUAVState->North -
            rtb_FixedWingGuidanceStateBus.North;
        rtb_SwitchLookAheadPoint[1] = rtu_SimUAVState->East -
            rtb_FixedWingGuidanceStateBus.East;
        rtb_SwitchLookAheadPoint[2] = rtu_SimUAVState->Height -
            rtu_SimUAVState->Height;

        // Sqrt: '<S81>/sqrt' incorporates:
        //   DotProduct: '<S81>/Dot Product'

        rtb_Sum_i = std::sqrt((rtb_SwitchLookAheadPoint[0] *
                               rtb_SwitchLookAheadPoint[0] +
                               rtb_SwitchLookAheadPoint[1] *
                               rtb_SwitchLookAheadPoint[1]) +
                              rtb_SwitchLookAheadPoint[2] *
                              rtb_SwitchLookAheadPoint[2]);

        // Gain: '<S69>/Gain' incorporates:
        //   Sum: '<S69>/LagDistanceSum'

        localDW->Gain = -(rtb_Sum1_idx_0 - rtb_Sum_i);

        // DataStoreWrite: '<S69>/WriteLagDistance'
        localDW->LagDistance = localDW->Gain;

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/FrontBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[108] -
            rtu_SimUAVState->North;

        // DotProduct: '<S77>/Dot Product'
        rtb_SwitchLookAheadPoint_0 = rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/FrontBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[325] -
            rtu_SimUAVState->East;

        // DotProduct: '<S77>/Dot Product'
        rtb_SwitchLookAheadPoint_0 += rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/FrontBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[542] -
            rtu_SimUAVState->Height;

        // Sqrt: '<S77>/sqrt' incorporates:
        //   DotProduct: '<S77>/Dot Product'

        Switch = std::sqrt(rtb_SwitchLookAheadPoint_c *
                           rtb_SwitchLookAheadPoint_c +
                           rtb_SwitchLookAheadPoint_0);

        // Sum: '<S69>/ActRngmMinRng'
        rtb_Sum_i -= Switch;

        // Sum: '<S69>/RefRngmMinRng'
        rtb_Sum_k = rtb_Sum1_idx_0 - Switch;

        // Sum: '<S69>/ComputeLB'
        rtb_Switch = Switch - rtb_Sum1_idx_0;

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/TailBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[12] -
            rtu_SimUAVState->North;

        // DotProduct: '<S78>/Dot Product'
        rtb_SwitchLookAheadPoint_0 = rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/TailBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[229] -
            rtu_SimUAVState->East;

        // DotProduct: '<S78>/Dot Product'
        rtb_SwitchLookAheadPoint_0 += rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/TailBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[446] -
            rtu_SimUAVState->Height;

        // Sum: '<S69>/ComputeUB' incorporates:
        //   DotProduct: '<S78>/Dot Product'
        //   Sqrt: '<S78>/sqrt'

        rtb_Abs1 = std::sqrt(rtb_SwitchLookAheadPoint_c *
                             rtb_SwitchLookAheadPoint_c +
                             rtb_SwitchLookAheadPoint_0) - rtb_Sum1_idx_0;

        // Outputs for Enabled SubSystem: '<S69>/EnableBias' incorporates:
        //   EnablePort: '<S76>/Enable'

        // Math: '<S69>/Square' incorporates:
        //   Math: '<S76>/Square'

        rtb_SwitchLookAheadPoint_c = rtb_Sum_k * rtb_Sum_k;

        // End of Outputs for SubSystem: '<S69>/EnableBias'

        // Product: '<S69>/DivideLB' incorporates:
        //   Bias: '<S69>/Bias'
        //   Math: '<S69>/Square'

        Switch = rtb_SwitchLookAheadPoint_c / (rtb_Sum_k + 10.0);

        // Switch: '<S69>/Switch' incorporates:
        //   RelationalOperator: '<S69>/GreaterThanOrEqual'

        if (rtb_Sum_i >= Switch) {
            // Switch: '<S69>/Switch'
            Switch = rtb_Sum_i;
        }

        // End of Switch: '<S69>/Switch'

        // Outputs for Enabled SubSystem: '<S69>/EnableBias' incorporates:
        //   EnablePort: '<S76>/Enable'

        if (Switch > 0.0) {
            // Sum: '<S76>/biasHm70' incorporates:
            //   Product: '<S76>/Divide'

            localDW->biasHm70 = rtb_SwitchLookAheadPoint_c / Switch - rtb_Sum_k;
        }

        // End of Outputs for SubSystem: '<S69>/EnableBias'

        // Sum: '<S79>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/L1FrontBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[78] -
            rtu_SimUAVState->North;

        // DotProduct: '<S79>/Dot Product'
        rtb_SwitchLookAheadPoint_0 = rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S79>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/L1FrontBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[295] -
            rtu_SimUAVState->East;

        // DotProduct: '<S79>/Dot Product'
        rtb_SwitchLookAheadPoint_0 += rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S79>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/L1FrontBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[512] -
            rtu_SimUAVState->Height;

        // Sum: '<S69>/L1ComputeLB' incorporates:
        //   DotProduct: '<S79>/Dot Product'
        //   Sqrt: '<S79>/sqrt'

        Switch = std::sqrt(rtb_SwitchLookAheadPoint_c *
                           rtb_SwitchLookAheadPoint_c +
                           rtb_SwitchLookAheadPoint_0) - rtb_Sum1_idx_0;

        // Sum: '<S80>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/L1TailBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[42] -
            rtu_SimUAVState->North;

        // DotProduct: '<S80>/Dot Product'
        rtb_SwitchLookAheadPoint_0 = rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S80>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/L1TailBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[259] -
            rtu_SimUAVState->East;

        // DotProduct: '<S80>/Dot Product'
        rtb_SwitchLookAheadPoint_0 += rtb_SwitchLookAheadPoint_c *
            rtb_SwitchLookAheadPoint_c;

        // Sum: '<S80>/Sum' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   Selector: '<S69>/L1TailBound'

        rtb_SwitchLookAheadPoint_c = localDW->MatrixConcatenate[476] -
            rtu_SimUAVState->Height;

        // Sum: '<S69>/L1ComputeUB' incorporates:
        //   DotProduct: '<S80>/Dot Product'
        //   Sqrt: '<S80>/sqrt'

        rtb_Sum_k = std::sqrt(rtb_SwitchLookAheadPoint_c *
                              rtb_SwitchLookAheadPoint_c +
                              rtb_SwitchLookAheadPoint_0) - rtb_Sum1_idx_0;

        // Outputs for Enabled SubSystem: '<S69>/SpdFBControl' incorporates:
        //   EnablePort: '<S83>/Enable'

        if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
            // Logic: '<S8>/AND' incorporates:
            //   Constant: '<S68>/Constant'
            //   DataStoreRead: '<S8>/ReadFlightMode_Log'
            //   Memory: '<S8>/MemoryNotInBrake'
            //   RelationalOperator: '<S68>/Compare'

            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((localDW->FlightMode_Log == 3.0) &
                                        static_cast<int32_T>
                                        (localDW->MemoryNotInBrake_PreviousInput))))
            {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (localDW->SpdFBControl_MODE) ^ 1)))
                {
                    // SystemReset for Chart: '<S83>/ControlLogic'
                    localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->temporalCounter_i1_n = 0U;
                    localDW->is_active_c6_Real2SimGuidance = 0U;
                    localDW->is_c6_Real2SimGuidance =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->PID_U = false;
                    localDW->EnableADRC = false;
                    localDW->EnablePID = false;
                    localDW->SpdFBControl_MODE = true;
                }
            } else if (localDW->SpdFBControl_MODE) {
                // Disable for Enabled SubSystem: '<S83>/ADRC'
                localDW->ADRC_MODE = false;

                // End of Disable for SubSystem: '<S83>/ADRC'

                // Disable for Enabled SubSystem: '<S83>/PID'
                localDW->PID_MODE = false;

                // End of Disable for SubSystem: '<S83>/PID'
                localDW->SpdFBControl_MODE = false;
            }

            // End of Logic: '<S8>/AND'
        }

        // End of Outputs for SubSystem: '<S69>/SpdFBControl'
        // End of Outputs for SubSystem: '<S8>/SpeedControl'
        // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    }

    // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S8>/SpeedControl'
    // Outputs for Enabled SubSystem: '<S69>/SpdFBControl' incorporates:
    //   EnablePort: '<S83>/Enable'

    if (localDW->SpdFBControl_MODE) {
        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Chart: '<S83>/ControlLogic'
            if (static_cast<uint32_T>(localDW->temporalCounter_i1_n) < 15U) {
                localDW->temporalCounter_i1_n = static_cast<uint8_T>(
                    static_cast<uint32_T>(static_cast<uint32_T>
                    (localDW->temporalCounter_i1_n) + 1U));
            }

            // Gateway: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
            // During: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
            if (static_cast<uint32_T>(localDW->is_active_c6_Real2SimGuidance) ==
                0U) {
                // Entry: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
                localDW->is_active_c6_Real2SimGuidance = 1U;

                // Entry Internal: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic 
                // Transition: '<S85>:81'
                localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                // Entry 'PID': '<S85>:53'
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;
            } else if (localDW->is_c6_Real2SimGuidance ==
                       Real2SimGuidance_IN_PID) {
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;

                // During 'PID': '<S85>:53'
                rtb_NoNewMission = static_cast<boolean_T>(static_cast<int32_T>((
                    static_cast<int32_T>(rtb_Memory) != 0) & static_cast<int32_T>
                    (*rtu_ParamADRC_useADRC)));
                if (rtb_NoNewMission) {
                    // Transition: '<S85>:83'
                    localDW->is_c6_Real2SimGuidance =
                        Real2SimGuidance_IN_useADRC;
                    localDW->is_useADRC = Real2SimGuidance_IN_Debounce_j;
                    localDW->is_Debounce = Real2SimGuidance_IN_PID2ADRC;
                    localDW->temporalCounter_i1_n = 0U;

                    // Entry 'PID2ADRC': '<S85>:62'
                    localDW->EnableADRC = true;
                }

                // During 'useADRC': '<S85>:92'
            } else if (static_cast<boolean_T>(static_cast<int32_T>
                        (static_cast<int32_T>(*rtu_ParamADRC_useADRC) ^ 1))) {
                // Transition: '<S85>:98'
                // Exit Internal 'useADRC': '<S85>:92'
                // Exit Internal 'Debounce': '<S85>:58'
                localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                // Entry 'PID': '<S85>:53'
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;
            } else if (localDW->is_useADRC == Real2SimGuidance_IN_ADRC) {
                localDW->EnablePID = false;
                localDW->EnableADRC = true;
                localDW->PID_U = false;

                // During 'ADRC': '<S85>:63'
                if (static_cast<int32_T>(rtb_Memory) == 0) {
                    // Transition: '<S85>:84'
                    localDW->is_useADRC = Real2SimGuidance_IN_Debounce_j;
                    localDW->is_Debounce = Real2SimGuidance_IN_ADRC2PID;
                    localDW->temporalCounter_i1_n = 0U;

                    // Entry 'ADRC2PID': '<S85>:61'
                    localDW->EnablePID = true;
                }

                // During 'Debounce': '<S85>:58'
            } else if (localDW->is_Debounce == Real2SimGuidance_IN_ADRC2PID) {
                localDW->EnablePID = true;

                // During 'ADRC2PID': '<S85>:61'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_n) >= 10U)
                {
                    // Transition: '<S85>:86'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                    // Entry 'PID': '<S85>:53'
                    localDW->EnableADRC = false;
                    localDW->PID_U = true;
                } else if (static_cast<int32_T>(rtb_Memory) != 0) {
                    // Transition: '<S85>:59'
                    localDW->is_Debounce = Real2SimGuidance_IN_PID2ADRC;
                    localDW->temporalCounter_i1_n = 0U;

                    // Entry 'PID2ADRC': '<S85>:62'
                    localDW->EnableADRC = true;
                }
            } else {
                localDW->EnableADRC = true;

                // During 'PID2ADRC': '<S85>:62'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_n) >= 10U)
                {
                    // Transition: '<S85>:85'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_useADRC = Real2SimGuidance_IN_ADRC;

                    // Entry 'ADRC': '<S85>:63'
                    localDW->EnablePID = false;
                    localDW->PID_U = false;
                } else if (static_cast<int32_T>(rtb_Memory) == 0) {
                    // Transition: '<S85>:60'
                    localDW->is_Debounce = Real2SimGuidance_IN_ADRC2PID;
                    localDW->temporalCounter_i1_n = 0U;

                    // Entry 'ADRC2PID': '<S85>:61'
                    localDW->EnablePID = true;
                }
            }

            // End of Chart: '<S83>/ControlLogic'

            // Outputs for Enabled SubSystem: '<S83>/ADRC' incorporates:
            //   EnablePort: '<S84>/Enable'

            if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
                if (localDW->EnableADRC) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(localDW->ADRC_MODE) ^ 1))) {
                        // InitializeConditions for Integrator: '<S88>/Integrator' 
                        localX->Integrator_CSTATE[0] = 0.0;
                        localX->Integrator_CSTATE[1] = 0.0;
                        localX->Integrator_CSTATE[2] = 0.0;
                        localDW->ADRC_MODE = true;
                    }
                } else {
                    localDW->ADRC_MODE = false;
                }
            }

            // End of Outputs for SubSystem: '<S83>/ADRC'
        }

        // Outputs for Enabled SubSystem: '<S83>/ADRC' incorporates:
        //   EnablePort: '<S84>/Enable'

        if (localDW->ADRC_MODE) {
            // RateTransition: '<S84>/RThat_b' incorporates:
            //   RateTransition: '<S84>/RTomega_b'

            if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
                // RateTransition: '<S84>/RThat_b'
                localDW->RThat_b = *rtu_ParamADRC_hat_b;

                // RateTransition: '<S84>/RTomega_b'
                localDW->RTomega_b = *rtu_ParamADRC_omega_b;
            }

            // End of RateTransition: '<S84>/RThat_b'

            // MATLAB Function: '<S90>/Extended state feedback robust controller' 
            // MATLAB Function 'ADRC controller/State feedback robust controller/Extended state feedback robust controller': '<S94>:1' 
            // '<S94>:1:8'
            if (localDW->RThat_b == 0.0) {
                // '<S94>:1:17'
                // '<S94>:1:18'
                rtb_Sum1_idx_0 = 1.0;
            } else {
                // '<S94>:1:20'
                rtb_Sum1_idx_0 = localDW->RThat_b;
            }

            // '<S94>:1:9'
            if (localDW->RTomega_b == 0.0) {
                // '<S94>:1:17'
                // '<S94>:1:18'
                rtb_Sum_i = 5.0;
            } else {
                // '<S94>:1:20'
                rtb_Sum_i = localDW->RTomega_b;
            }

            // Product: '<S96>/Product' incorporates:
            //   Integrator: '<S88>/Integrator'
            //   MATLAB Function: '<S90>/Extended state feedback robust controller'
            //   Step: '<S96>/Step'

            // '<S94>:1:10'
            // '<S94>:1:25'
            // '<S94>:1:26'
            // '<S94>:1:12'
            rtb_Sum1_idx_0 = ((rtb_Sum_i * rtb_Sum_i * localX->
                               Integrator_CSTATE[0] + (rtb_Sum_i - (-rtb_Sum_i))
                               * localX->Integrator_CSTATE[1]) +
                              localX->Integrator_CSTATE[2]) * (1.0 /
                rtb_Sum1_idx_0) * static_cast<real_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>
                (((*(Real2SimGuidance_M->timingBridge->
                     taskTime[Real2SimGuidance_M->Timing.mdlref_GlobalTID[0]])) <
                  0.2) ^ 1))));

            // RateTransition: '<S84>/RTomega_o'
            if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
                // RateTransition: '<S84>/RTomega_o'
                localDW->RTomega_o = *rtu_ParamADRC_omega_o;
            }

            // End of RateTransition: '<S84>/RTomega_o'

            // MATLAB Function: '<S88>/Linear extended state observer' incorporates:
            //   Integrator: '<S88>/Integrator'

            // MATLAB Function 'ADRC controller/Linear extended state observer/Linear extended state observer': '<S91>:1' 
            // '<S91>:1:16'
            // '<S91>:1:10'
            if (localDW->RThat_b == 0.0) {
                // '<S91>:1:22'
                // '<S91>:1:23'
                rtb_Sum_i = 1.0;
            } else {
                // '<S91>:1:25'
                rtb_Sum_i = localDW->RThat_b;
            }

            // '<S91>:1:11'
            if (localDW->RTomega_o == 0.0) {
                // '<S91>:1:22'
                // '<S91>:1:23'
                rtb_SwitchLookAheadPoint_c = 25.0;
            } else {
                // '<S91>:1:25'
                rtb_SwitchLookAheadPoint_c = localDW->RTomega_o;
            }

            // '<S91>:1:13'
            // '<S91>:1:35'
            // '<S91>:1:14'
            // '<S91>:1:39'
            rtb_TmpSignalConversionAtSFunctionInport1[0] = 1.0;
            rtb_TmpSignalConversionAtSFunctionInport1[1] =
                rtb_SwitchLookAheadPoint_c;
            rtb_TmpSignalConversionAtSFunctionInport1[2] =
                rtb_SwitchLookAheadPoint_c * rtb_SwitchLookAheadPoint_c;
            for (i = 1; static_cast<int32_T>(i + 1) > 1; i = static_cast<int32_T>
                    (i - 1)) {
                rtb_TmpSignalConversionAtSFunctionInport1[i] -=
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(i - 1)] * -rtb_SwitchLookAheadPoint_c;
            }

            rtb_TmpSignalConversionAtSFunctionInport1[3] =
                rtb_SwitchLookAheadPoint_c *
                rtb_TmpSignalConversionAtSFunctionInport1[2];
            for (i = 2; static_cast<int32_T>(i + 1) > 1; i = static_cast<int32_T>
                    (i - 1)) {
                rtb_TmpSignalConversionAtSFunctionInport1[i] -=
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(i - 1)] * -rtb_SwitchLookAheadPoint_c;
            }

            // '<S91>:1:40'
            // '<S91>:1:16'
            rtb_SwitchLookAheadPoint_c = localDW->Gain -
                localX->Integrator_CSTATE[0];
            tmp[0] = 0.0 * rtb_Sum1_idx_0;
            tmp[1] = -rtb_Sum_i * rtb_Sum1_idx_0;
            tmp[2] = 0.0 * rtb_Sum1_idx_0;
            for (i = 0; i < 3; i++) {
                localDW->estimatedExtendedStateDerivative[i] =
                    (((static_cast<real_T>(a[static_cast<int32_T>(i + 3)]) *
                       localX->Integrator_CSTATE[1] + 0.0 *
                       localX->Integrator_CSTATE[0]) + static_cast<real_T>(a[
                       static_cast<int32_T>(i + 6)]) * localX->
                      Integrator_CSTATE[2]) + tmp[i]) +
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(i + 1)] * rtb_SwitchLookAheadPoint_c;
            }

            // End of MATLAB Function: '<S88>/Linear extended state observer'

            // RateTransition: '<S84>/RThat_z' incorporates:
            //   Concatenate: '<S83>/Vector Concatenate'
            //   Integrator: '<S88>/Integrator'
            //   RateTransition: '<S84>/RTu'

            if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
                localDW->VectorConcatenate[0] = localX->Integrator_CSTATE[0];
                localDW->VectorConcatenate[1] = localX->Integrator_CSTATE[1];
                localDW->VectorConcatenate[2] = localX->Integrator_CSTATE[2];

                // RateTransition: '<S84>/RTu' incorporates:
                //   Concatenate: '<S83>/Vector Concatenate'
                //   Integrator: '<S88>/Integrator'

                localDW->RTu = rtb_Sum1_idx_0;
            }

            // End of RateTransition: '<S84>/RThat_z'
        }

        // End of Outputs for SubSystem: '<S83>/ADRC'
        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Outputs for Enabled SubSystem: '<S83>/PID' incorporates:
            //   EnablePort: '<S86>/Enable'

            if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
                if (localDW->EnablePID) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(localDW->PID_MODE) ^ 1))) {
                        // InitializeConditions for Delay: '<S125>/UD'
                        localDW->UD_DSTATE = 0.0;

                        // InitializeConditions for DiscreteIntegrator: '<S132>/Integrator' 
                        localDW->Integrator_DSTATE = 0.0;
                        localDW->PID_MODE = true;
                    }
                } else {
                    localDW->PID_MODE = false;
                }
            }

            if (localDW->PID_MODE) {
                // Product: '<S124>/DProd Out'
                rtb_Sum1_idx_0 = localDW->Gain * *rtu_ParamADRC_D;

                // SampleTimeMath: '<S127>/Tsamp'
                //
                //  About '<S127>/Tsamp':
                //   y = u * K where K = 1 / ( w * Ts )

                localDW->Tsamp = rtb_Sum1_idx_0 * 10.0;

                // Product: '<S129>/IProd Out'
                localDW->IProdOut = localDW->Gain * *rtu_ParamADRC_I;

                // Product: '<S137>/PProd Out'
                rtb_Sum1_idx_0 = localDW->Gain * *rtu_ParamADRC_P;

                // Sum: '<S141>/Sum' incorporates:
                //   Delay: '<S125>/UD'
                //   DiscreteIntegrator: '<S132>/Integrator'
                //   Sum: '<S125>/Diff'

                localDW->Sum = (rtb_Sum1_idx_0 + localDW->Integrator_DSTATE) +
                    (localDW->Tsamp - localDW->UD_DSTATE);
            }

            // End of Outputs for SubSystem: '<S83>/PID'

            // Switch: '<S83>/Switch'
            if (localDW->PID_U) {
                // Switch: '<S83>/Switch'
                localDW->Switch_p = localDW->Sum;
            } else {
                // Switch: '<S83>/Switch'
                localDW->Switch_p = localDW->RTu;
            }

            // End of Switch: '<S83>/Switch'

            // SignalConversion generated from: '<S83>/Vector Concatenate' incorporates:
            //   Concatenate: '<S83>/Vector Concatenate'

            localDW->VectorConcatenate[3] = localDW->Switch_p;

            // DataStoreWrite: '<S83>/WriteADRC_Log'
            localDW->ADRC_Log[0] = localDW->VectorConcatenate[0];
            localDW->ADRC_Log[1] = localDW->VectorConcatenate[1];
            localDW->ADRC_Log[2] = localDW->VectorConcatenate[2];
            localDW->ADRC_Log[3] = localDW->VectorConcatenate[3];
        }
    }

    // End of Outputs for SubSystem: '<S69>/SpdFBControl'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Outputs for Atomic SubSystem: '<S8>/MaxBrake'
        // Sum: '<S75>/Sum'
        rtb_SwitchLookAheadPoint[0] = rtu_SimUAVState->North -
            rtb_FixedWingGuidanceStateBus.North;
        rtb_SwitchLookAheadPoint[1] = rtu_SimUAVState->East -
            rtb_FixedWingGuidanceStateBus.East;
        rtb_SwitchLookAheadPoint[2] = rtu_SimUAVState->Height - rtb_Abs1_k;

        // Outputs for Atomic SubSystem: '<S8>/HeadingLogic'
        // Outputs for Atomic SubSystem: '<S65>/NewMissionHdg'
        // Product: '<S67>/BrkRng' incorporates:
        //   Constant: '<S67>/SampleTime'
        //   Gain: '<S71>/Ts'

        rtb_SwitchLookAheadPoint_c = rtu_SimUAVState->AirSpeed * 0.1;

        // End of Outputs for SubSystem: '<S65>/NewMissionHdg'
        // End of Outputs for SubSystem: '<S8>/HeadingLogic'

        // Sum: '<S67>/Minus' incorporates:
        //   Constant: '<S67>/TrackDP'
        //   DotProduct: '<S75>/Dot Product'
        //   Product: '<S67>/BrkRng'
        //   Sqrt: '<S75>/sqrt'

        rtb_Sum_i = std::sqrt((rtb_SwitchLookAheadPoint[0] *
                               rtb_SwitchLookAheadPoint[0] +
                               rtb_SwitchLookAheadPoint[1] *
                               rtb_SwitchLookAheadPoint[1]) +
                              rtb_SwitchLookAheadPoint[2] *
                              rtb_SwitchLookAheadPoint[2]) -
            rtb_SwitchLookAheadPoint_c * 132.0;

        // Gain: '<S67>/Gain'
        rtb_Gain_p = -rtb_Sum_i;

        // Switch: '<S67>/BrkSwitch' incorporates:
        //   Constant: '<S67>/MaxBrake'
        //   Sum: '<S69>/SumSpd'

        if (rtb_Sum_i >= 0.0) {
            rtb_RefAirspeed_Log = (rtb_HeadWind + localDW->Switch_p) +
                rtu_SimUAVState->AirSpeed;
        } else {
            rtb_RefAirspeed_Log = 0.0;
        }

        // End of Switch: '<S67>/BrkSwitch'

        // Saturate: '<S67>/SpeedProtection'
        if (rtb_RefAirspeed_Log > 46.0) {
            rtb_RefAirspeed_Log = 46.0;
        } else if (rtb_RefAirspeed_Log < 29.0) {
            rtb_RefAirspeed_Log = 29.0;
        }

        // End of Saturate: '<S67>/SpeedProtection'
        // End of Outputs for SubSystem: '<S8>/MaxBrake'

        // Outputs for Atomic SubSystem: '<S8>/HeadingLogic'
        // Gain: '<S65>/LookaheadT'
        rtb_Sum1_idx_0 = 3.6 * rtu_SimUAVState->AirSpeed;

        // SignalConversion generated from: '<S65>/TrackSimPath'
        rtb_TmpSignalConversionAtSFunctionInport1[0] =
            rtb_FixedWingGuidanceStateBus.North;
        rtb_TmpSignalConversionAtSFunctionInport1[1] =
            rtb_FixedWingGuidanceStateBus.East;
        rtb_TmpSignalConversionAtSFunctionInport1[2] = rtb_Abs1_k;
        rtb_TmpSignalConversionAtSFunctionInport1[3] =
            rtb_FixedWingGuidanceStateBus.HeadingAngle;

        // MATLABSystem: '<S65>/TrackSimPath' incorporates:
        //   Concatenate: '<S64>/Matrix Concatenate'
        //   DataStoreWrite: '<S65>/WriteCrossTrackError'

        Real2SimGuidance_WaypointFollower_stepImpl(&localDW->obj,
            rtb_TmpSignalConversionAtSFunctionInport1,
            localDW->MatrixConcatenate, rtb_Sum1_idx_0, rtb_SwitchLookAheadPoint,
            &rtb_HeadWind, &rtb_Sum_i, &b_varargout_4, &localDW->CrossTrackError,
            &b_varargout_6, localDW);

        // RelationalOperator: '<S65>/Relational Operator' incorporates:
        //   DataStoreWrite: '<S65>/WriteCrossTrackError'
        //   Gain: '<S65>/Gain'

        rtb_NoNewMission = (localDW->CrossTrackError <= 0.5 * rtb_Sum1_idx_0);

        // Outputs for Atomic SubSystem: '<S65>/NewMissionHdg'
        // Outputs for Enabled SubSystem: '<S71>/CalForwardShift' incorporates:
        //   EnablePort: '<S73>/Enable'

        if (rtu_SimUAVState->AirSpeed > 0.0) {
            // Saturate: '<S71>/Saturation'
            if (rtb_Gain_p <= 0.0) {
                rtb_Abs1_k = 0.0;
            } else {
                rtb_Abs1_k = rtb_Gain_p;
            }

            // End of Saturate: '<S71>/Saturation'

            // Gain: '<S73>/Gain' incorporates:
            //   Product: '<S73>/Divide'

            localDW->Gain_b = rtb_Abs1_k / rtu_SimUAVState->AirSpeed * 10.0;
        }

        // End of Outputs for SubSystem: '<S71>/CalForwardShift'

        // RelationalOperator: '<S71>/GreaterThanOrEqual' incorporates:
        //   Constant: '<S71>/PenetrationDepthThreshold'
        //   Product: '<S71>/Product'

        rtb_GreaterThanOrEqual_h = (rtb_Gain_p >= rtb_SwitchLookAheadPoint_c *
            72.0);

        // Chart: '<S71>/MissionSwitchInitialPersuit'
        if (static_cast<uint32_T>(localDW->temporalCounter_i2) < 15U) {
            localDW->temporalCounter_i2 = static_cast<uint8_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i2) + 1U));
        }

        // Gateway: Real2SimNav/HeadingLogic/NewMissionHdg/MissionSwitchInitialPersuit 
        if (localDW->temporalCounter_i1 < MAX_uint32_T) {
            localDW->temporalCounter_i1 = static_cast<uint32_T>
                (localDW->temporalCounter_i1 + 1U);
        }

        // During: Real2SimNav/HeadingLogic/NewMissionHdg/MissionSwitchInitialPersuit 
        if (static_cast<uint32_T>(localDW->is_active_c3_Real2SimGuidance) == 0U)
        {
            // Entry: Real2SimNav/HeadingLogic/NewMissionHdg/MissionSwitchInitialPersuit 
            localDW->is_active_c3_Real2SimGuidance = 1U;

            // Entry Internal: Real2SimNav/HeadingLogic/NewMissionHdg/MissionSwitchInitialPersuit 
            // Transition: '<S74>:14'
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S74>:12'
            localDW->SimHdg = 1.0;
        } else if (localDW->is_c3_Real2SimGuidance ==
                   Real2SimGuidance_IN_Initial) {
            // During 'Initial': '<S74>:12'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((localDW->temporalCounter_i1 >= 216U) &
                                        (static_cast<int32_T>(rtb_Memory) != 0))))
            {
                // Transition: '<S74>:15'
                localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Normal;

                // Entry Internal 'Normal': '<S74>:13'
                // Transition: '<S74>:53'
                localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                // Entry 'SimPnt': '<S74>:37'
                localDW->SimHdg = 1.0;
            } else {
                localDW->SimHdg = 1.0;
            }

            // During 'Normal': '<S74>:13'
        } else if (*rtu_NewMission) {
            // Transition: '<S74>:16'
            // Exit Internal 'Normal': '<S74>:13'
            // Exit Internal 'Debounce': '<S74>:38'
            localDW->is_Debounce_m = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S74>:12'
            localDW->SimHdg = 1.0;
        } else {
            switch (localDW->is_Normal) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S74>:38'
                if (localDW->is_Debounce_m == Real2SimGuidance_IN_L1Hdg_n) {
                    // During 'L1Hdg': '<S74>:49'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                            10U) {
                        // Transition: '<S74>:46'
                        localDW->is_Debounce_m =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_Normal = Real2SimGuidance_IN_L1Hdg;

                        // Entry 'L1Hdg': '<S74>:42'
                        localDW->SimHdg = 0.0;
                    } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(static_cast<boolean_T>(
                                   static_cast<int32_T>(static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &
                                 static_cast<int32_T>(rtb_NoNewMission)))) {
                        // Transition: '<S74>:50'
                        localDW->is_Debounce_m = Real2SimGuidance_IN_SimPnt_a;
                        localDW->temporalCounter_i2 = 0U;
                    }

                    // During 'SimPnt': '<S74>:44'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                           10U) {
                    // Transition: '<S74>:48'
                    localDW->is_Debounce_m = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                    // Entry 'SimPnt': '<S74>:37'
                    localDW->SimHdg = 1.0;
                } else if (rtb_GreaterThanOrEqual_h) {
                    // Transition: '<S74>:51'
                    localDW->is_Debounce_m = Real2SimGuidance_IN_L1Hdg_n;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              case Real2SimGuidance_IN_L1Hdg:
                // During 'L1Hdg': '<S74>:42'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (static_cast<boolean_T>(static_cast<
                        int32_T>(static_cast<int32_T>(rtb_GreaterThanOrEqual_h) ^
                                 1))) & static_cast<int32_T>(rtb_NoNewMission))))
                {
                    // Transition: '<S74>:45'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce_m = Real2SimGuidance_IN_SimPnt_a;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              default:
                // During 'SimPnt': '<S74>:37'
                if (rtb_GreaterThanOrEqual_h) {
                    // Transition: '<S74>:47'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce_m = Real2SimGuidance_IN_L1Hdg_n;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;
            }
        }

        // End of Chart: '<S71>/MissionSwitchInitialPersuit'

        // DataTypeConversion: '<S71>/Cast' incorporates:
        //   DataStoreWrite: '<S65>/WriteStatus_Log'
        //   Logic: '<S71>/OR'
        //   MATLABSystem: '<S65>/TrackSimPath'

        localDW->HdgStatus_Log = static_cast<uint8_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
            (b_varargout_6) != 0) | (localDW->SimHdg != 0.0)))));

        // DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
        if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                (localDW->DiscreteTimeIntegrator_PrevResetState) <= 0) &
                static_cast<int32_T>(*rtu_NewMission)))) {
            localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
        }

        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        }

        // MinMax: '<S71>/Min' incorporates:
        //   Constant: '<S71>/NewestPoint'
        //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
        //   Gain: '<S71>/Gain'
        //   Rounding: '<S71>/Round'
        //   Sum: '<S71>/Minus'

        rtb_Abs1_k = std::fmin(217.0, std::round((217.0 -
            localDW->DiscreteTimeIntegrator_DSTATE) + 1.5 * localDW->Gain_b));

        // End of Outputs for SubSystem: '<S65>/NewMissionHdg'

        // Switch: '<S65>/SwitchLookAheadNED' incorporates:
        //   DataStoreWrite: '<S65>/WriteStatus_Log'
        //   Sum: '<S72>/EastArrow'
        //   Sum: '<S72>/NorthArrow'
        //   Switch: '<S65>/SwitchTargetHDG'
        //   Trigonometry: '<S72>/HdgCmd'

        if (static_cast<int32_T>(localDW->HdgStatus_Log) != 0) {
            // Selector: '<S65>/WayPoint3d3' incorporates:
            //   Concatenate: '<S64>/Matrix Concatenate'
            //   Sum: '<S72>/NorthArrow'

            rtb_Sum1_idx_0 = localDW->MatrixConcatenate[static_cast<int32_T>(
                static_cast<int32_T>(rtb_Abs1_k) - 1)];

            // Switch: '<S65>/SwitchLookAheadNED' incorporates:
            //   Selector: '<S65>/WayPoint3d3'

            localDW->SwitchLookAheadNED[0] = rtb_Sum1_idx_0;

            // Selector: '<S65>/WayPoint3d3' incorporates:
            //   Concatenate: '<S64>/Matrix Concatenate'
            //   Sum: '<S72>/EastArrow'

            rtb_HeadWind = localDW->MatrixConcatenate[static_cast<int32_T>(
                static_cast<int32_T>(rtb_Abs1_k) + 216)];

            // Switch: '<S65>/SwitchLookAheadNED' incorporates:
            //   Concatenate: '<S64>/Matrix Concatenate'
            //   Selector: '<S65>/WayPoint3d3'

            localDW->SwitchLookAheadNED[1] = rtb_HeadWind;
            localDW->SwitchLookAheadNED[2] = localDW->MatrixConcatenate[
                static_cast<int32_T>(static_cast<int32_T>(rtb_Abs1_k) + 433)];
            rtb_HeadWind = rt_atan2d_snf(rtb_HeadWind -
                rtb_FixedWingGuidanceStateBus.East, rtb_Sum1_idx_0 -
                rtb_FixedWingGuidanceStateBus.North);
        } else {
            // Switch: '<S65>/SwitchLookAheadNED' incorporates:
            //   MATLABSystem: '<S65>/TrackSimPath'

            localDW->SwitchLookAheadNED[0] = rtb_SwitchLookAheadPoint[0];
            localDW->SwitchLookAheadNED[1] = rtb_SwitchLookAheadPoint[1];
            localDW->SwitchLookAheadNED[2] = rtb_SwitchLookAheadPoint[2];
        }

        // End of Switch: '<S65>/SwitchLookAheadNED'
        // End of Outputs for SubSystem: '<S8>/HeadingLogic'

        // DataStoreWrite: '<S8>/WriteHeading_Log' incorporates:
        //   MATLAB Function: '<S8>/AngLog'

        // MATLAB Function 'Real2SimNav/AngLog': '<S60>:1'
        // '<S60>:1:2'
        // '<S60>:1:3'
        // '<S60>:1:4'
        localDW->Heading_Log[0] = angdiff_WJjwZrD2
            (rtb_FixedWingGuidanceStateBus.HeadingAngle, rtb_HeadWind);
        localDW->Heading_Log[1] = angdiff_WJjwZrD2(0.0,
            rtb_FixedWingGuidanceStateBus.HeadingAngle);
        localDW->Heading_Log[2] = angdiff_WJjwZrD2(0.0, rtb_HeadWind);
    }

    // End of Outputs for SubSystem: '<S8>/SpeedControl'

    // Integrator: '<S70>/TD_Alt' incorporates:
    //   DataStoreWrite: '<S8>/WritebiasH_Log'

    localDW->biasH_Log = localX->TD_Alt_CSTATE;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Chart: '<S8>/Chart'
        // Gateway: Real2SimNav/Chart
        // During: Real2SimNav/Chart
        if (static_cast<uint32_T>(localDW->is_active_c2_Real2SimGuidance) == 0U)
        {
            // Entry: Real2SimNav/Chart
            localDW->is_active_c2_Real2SimGuidance = 1U;

            // Entry Internal: Real2SimNav/Chart
            // Transition: '<S61>:6'
            localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

            // Entry 'hasBias': '<S61>:5'
            // Switch: '<S8>/BiasHSwitch' incorporates:
            //   Gain: '<S8>/Gain'
            //   Product: '<S8>/Product'

            localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
        } else if (localDW->is_c2_Real2SimGuidance == Real2SimGuidance_IN_NoBias)
        {
            // During 'NoBias': '<S61>:7'
            if (*rtu_NewMission) {
                // Transition: '<S61>:9'
                localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

                // Entry 'hasBias': '<S61>:5'
                // Switch: '<S8>/BiasHSwitch' incorporates:
                //   Gain: '<S8>/Gain'
                //   Product: '<S8>/Product'

                localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
            } else {
                // Switch: '<S8>/BiasHSwitch' incorporates:
                //   Constant: '<S8>/ZeroBias'

                localDW->BiasHSwitch = 0.0;
            }

            // During 'hasBias': '<S61>:5'
        } else if (localDW->EngagedFlag > 1.0) {
            // Transition: '<S61>:8'
            localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NoBias;

            // Entry 'NoBias': '<S61>:7'
            // Switch: '<S8>/BiasHSwitch' incorporates:
            //   Constant: '<S8>/ZeroBias'

            localDW->BiasHSwitch = 0.0;
        } else {
            // Switch: '<S8>/BiasHSwitch' incorporates:
            //   Gain: '<S8>/Gain'
            //   Product: '<S8>/Product'

            localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
        }

        // End of Chart: '<S8>/Chart'

        // RelationalOperator: '<S62>/Compare' incorporates:
        //   Constant: '<S62>/Constant'

        localDW->Compare = (rtb_Gain_p < 0.0);

        // Truth Table: '<S8>/Engagement' incorporates:
        //   DataStoreRead: '<S8>/ReadLagDistance'
        //   DataStoreWrite: '<S65>/WriteCrossTrackError'

        // Truth Table Function 'Real2SimNav/Engagement': '<S63>:1'
        //  Front Distance within L1 Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_Sum_k) & (localDW->LagDistance > Switch)))) {
            // Condition '#1': '<S63>:1:11'
            rtb_NoNewMission = true;
        } else {
            rtb_NoNewMission = false;
        }

        //  Front Distance within L0 Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_Abs1) & (localDW->LagDistance > rtb_Switch)))) {
            // Condition '#2': '<S63>:1:15'
            rtb_GreaterThanOrEqual_h = true;
        } else {
            rtb_GreaterThanOrEqual_h = false;
        }

        //  CrossTrack Error within L1 Bound
        // Condition '#3': '<S63>:1:19'
        //  CrossTrack Error within L0 Bound
        // Condition '#4': '<S63>:1:23'
        if (rtb_NoNewMission && (localDW->CrossTrackError < std::abs(rtb_Sum_k -
              Switch) / 2.0)) {
            // Decision 'D1': '<S63>:1:25'
            //  Real UAV Deeply Engaged with Simulation UAV
            // Action '1': '<S63>:1:37'
            localDW->Engaged = 2U;
        } else if (rtb_GreaterThanOrEqual_h) {
            if (localDW->CrossTrackError < std::abs(rtb_Abs1 - rtb_Switch) / 2.0)
            {
                // Decision 'D2': '<S63>:1:27'
                //  Real UAV Engaged with Simulation UAV
                // Action '2': '<S63>:1:43'
                localDW->Engaged = 1U;
            } else {
                // Decision 'D3': '<S63>:1:29'
                //  Default
                //  Real UAV Not Engaged with Simulation UAV
                // Action '3': '<S63>:1:49'
                localDW->Engaged = 0U;
            }
        } else {
            // Decision 'D3': '<S63>:1:29'
            //  Default
            //  Real UAV Not Engaged with Simulation UAV
            // Action '3': '<S63>:1:49'
            localDW->Engaged = 0U;
        }

        // End of Truth Table: '<S8>/Engagement'

        // ZeroOrderHold: '<S8>/LookaheadPoint_ZOH' incorporates:
        //   DataStoreWrite: '<S8>/WritebiasH_Log'
        //   Sum: '<S8>/SumBiasH'
        //   Switch: '<S65>/SwitchLookAheadNED'

        rtb_RealUAVNEUState_idx_0 = localDW->SwitchLookAheadNED[0];
        rtb_RealUAVNEUState_idx_1 = localDW->SwitchLookAheadNED[1];
        rtb_RealUAVNEUState_idx_2 = localDW->SwitchLookAheadNED[2] +
            localDW->biasH_Log;
    }

    // Integrator: '<S70>/dotAltTD'
    localDW->dotAltTD = localX->dotAltTD_CSTATE;

    // MATLAB Function: '<S70>/fhan_Alt' incorporates:
    //   DataStoreWrite: '<S8>/WritebiasH_Log'
    //   SignalConversion generated from: '<S149>/ SFunction '
    //   Sum: '<S70>/Sum1'

    // MATLAB Function 'Real2SimNav/TD/fhan_Alt': '<S149>:1'
    // '<S149>:1:3'
    // '<S149>:1:4'
    // '<S149>:1:5'
    // '<S149>:1:6'
    // '<S149>:1:8'
    // '<S149>:1:9'
    rtb_Abs1 = localDW->dotAltTD * 0.1;

    // '<S149>:1:10'
    rtb_Gain_p = (localDW->biasH_Log - localDW->BiasHSwitch) + rtb_Abs1;

    // '<S149>:1:11'
    // '<S149>:1:12'
    if (std::isnan(rtb_Gain_p)) {
        rtb_Sum1_idx_0 = rtb_Gain_p;
    } else if (rtb_Gain_p < 0.0) {
        rtb_Sum1_idx_0 = -1.0;
    } else {
        rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Gain_p > 0.0);
    }

    rtb_Abs1_k = (std::sqrt((8.0 * std::abs(rtb_Gain_p) + 0.004000000000000001) *
                            0.004000000000000001) - 0.004000000000000001) *
        rtb_Sum1_idx_0 / 2.0 + rtb_Abs1;

    // '<S149>:1:13'
    // '<S149>:1:14'
    if (std::isnan(rtb_Gain_p + 0.004000000000000001)) {
        rtb_Sum1_idx_0 = rtb_Gain_p + 0.004000000000000001;
    } else if (rtb_Gain_p + 0.004000000000000001 < 0.0) {
        rtb_Sum1_idx_0 = -1.0;
    } else {
        rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Gain_p + 0.004000000000000001 >
            0.0);
    }

    if (std::isnan(rtb_Gain_p - 0.004000000000000001)) {
        rtb_Sum_k = rtb_Gain_p - 0.004000000000000001;
    } else if (rtb_Gain_p - 0.004000000000000001 < 0.0) {
        rtb_Sum_k = -1.0;
    } else {
        rtb_Sum_k = static_cast<real_T>(rtb_Gain_p - 0.004000000000000001 > 0.0);
    }

    rtb_Gain_p = ((rtb_Abs1 + rtb_Gain_p) - rtb_Abs1_k) * ((rtb_Sum1_idx_0 -
        rtb_Sum_k) / 2.0) + rtb_Abs1_k;

    // '<S149>:1:15'
    // '<S149>:1:17'
    if (std::isnan(rtb_Gain_p)) {
        rtb_Abs1 = rtb_Gain_p;
    } else if (rtb_Gain_p < 0.0) {
        rtb_Abs1 = -1.0;
    } else {
        rtb_Abs1 = static_cast<real_T>(rtb_Gain_p > 0.0);
    }

    if (std::isnan(rtb_Gain_p + 0.004000000000000001)) {
        rtb_Sum1_idx_0 = rtb_Gain_p + 0.004000000000000001;
    } else if (rtb_Gain_p + 0.004000000000000001 < 0.0) {
        rtb_Sum1_idx_0 = -1.0;
    } else {
        rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Gain_p + 0.004000000000000001 >
            0.0);
    }

    if (std::isnan(rtb_Gain_p - 0.004000000000000001)) {
        rtb_Sum_k = rtb_Gain_p - 0.004000000000000001;
    } else if (rtb_Gain_p - 0.004000000000000001 < 0.0) {
        rtb_Sum_k = -1.0;
    } else {
        rtb_Sum_k = static_cast<real_T>(rtb_Gain_p - 0.004000000000000001 > 0.0);
    }

    localDW->fh = (rtb_Gain_p / 0.004000000000000001 - rtb_Abs1) * -0.4 *
        ((rtb_Sum1_idx_0 - rtb_Sum_k) / 2.0) - 0.4 * rtb_Abs1;

    // End of MATLAB Function: '<S70>/fhan_Alt'
    // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Chart: '<Root>/TASgreaterthan15for1Sec'
        // Gateway: TASgreaterthan15for1Sec
        // During: TASgreaterthan15for1Sec
        if (static_cast<uint32_T>(localDW->is_active_c16_Real2SimGuidance) == 0U)
        {
            // Entry: TASgreaterthan15for1Sec
            localDW->is_active_c16_Real2SimGuidance = 1U;

            // Entry Internal: TASgreaterthan15for1Sec
            // Transition: '<S9>:3'
            localDW->durationCounter_1 = 0;
            localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NotTakeOff;

            // Entry 'NotTakeOff': '<S9>:2'
            rtb_NoNewMission = false;
        } else if (localDW->is_c16_Real2SimGuidance == Real2SimGuidance_IN_InAir)
        {
            // During 'InAir': '<S9>:4'
            rtb_NoNewMission = true;
        } else {
            // During 'NotTakeOff': '<S9>:2'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((rtb_FixedWingGuidanceStateBus.AirSpeed >
                   15.0) & (rtu_StateFCU->RealUAVState.Height_meter > 30.0)))) {
                // '<S9>:5:2'
                rtb_NoNewMission = true;
            } else {
                rtb_NoNewMission = false;
            }

            // '<S9>:5:2'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_NoNewMission) ^ 1))) {
                localDW->durationCounter_1 = 0;
            }

            if (localDW->durationCounter_1 > 10) {
                // Transition: '<S9>:5'
                localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_InAir;

                // Entry 'InAir': '<S9>:4'
                rtb_NoNewMission = true;
            } else {
                rtb_NoNewMission = false;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((rtb_FixedWingGuidanceStateBus.AirSpeed >
                15.0) & (rtu_StateFCU->RealUAVState.Height_meter > 30.0)))) {
            // '<S9>:5:2'
            rtb_GreaterThanOrEqual_h = true;
        } else {
            rtb_GreaterThanOrEqual_h = false;
        }

        // '<S9>:5:2'
        if (rtb_GreaterThanOrEqual_h) {
            localDW->durationCounter_1 = static_cast<int32_T>
                (localDW->durationCounter_1 + 1);
        } else {
            localDW->durationCounter_1 = 0;
        }

        // End of Chart: '<Root>/TASgreaterthan15for1Sec'

        // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
        //   EnablePort: '<S2>/Enable'

        if (rtb_NoNewMission) {
            // SignalConversion generated from: '<S2>/InPlace'
            *rty_EngagedFlag = localDW->Engaged;
        }

        // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'

        // Chart: '<Root>/EngagementDebouncer'
        if (static_cast<uint32_T>(localDW->temporalCounter_i1_i) < 1023U) {
            localDW->temporalCounter_i1_i = static_cast<uint16_T>(static_cast<
                uint32_T>(static_cast<uint32_T>(localDW->temporalCounter_i1_i) +
                          1U));
        }

        if (static_cast<uint32_T>(localDW->temporalCounter_i2_f) < 63U) {
            localDW->temporalCounter_i2_f = static_cast<uint8_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i2_f) + 1U));
        }

        // Gateway: EngagementDebouncer
        // During: EngagementDebouncer
        if (static_cast<uint32_T>(localDW->is_active_c34_Real2SimGuidance) == 0U)
        {
            // Entry: EngagementDebouncer
            localDW->is_active_c34_Real2SimGuidance = 1U;

            // Entry Internal: EngagementDebouncer
            // Transition: '<S3>:97'
            localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_Persuit;

            // Entry 'Persuit': '<S3>:95'
            localDW->Execution = 0.0;

            // Entry Internal 'Persuit': '<S3>:95'
            // Transition: '<S3>:100'
            localDW->is_Persuit = Real2SimGuidance_IN_Normal;
        } else {
            switch (localDW->is_c34_Real2SimGuidance) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S3>:90'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_i) >= 180U)
                {
                    // Transition: '<S3>:93'
                    // Exit Internal 'Debounce': '<S3>:90'
                    localDW->is_Debounce_m4 =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Persuit;

                    // Entry 'Persuit': '<S3>:95'
                    localDW->Execution = 0.0;
                    localDW->is_Persuit = Real2SimGuidance_IN_Fault;
                    localDW->temporalCounter_i1_i = 0U;

                    // Entry 'Fault': '<S3>:94'
                } else if (localDW->is_Debounce_m4 == Real2SimGuidance_IN_Off) {
                    // During 'Off': '<S3>:103'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2_f) >=
                            40U) {
                        // Transition: '<S3>:87'
                        localDW->is_Debounce_m4 =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_c34_Real2SimGuidance =
                            Real2SimGuidance_IN_Persuit;

                        // Entry 'Persuit': '<S3>:95'
                        localDW->Execution = 0.0;

                        // Entry Internal 'Persuit': '<S3>:95'
                        // Transition: '<S3>:100'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    } else if (static_cast<int32_T>(*rty_EngagedFlag) > 0) {
                        // Transition: '<S3>:102'
                        localDW->is_Debounce_m4 = Real2SimGuidance_IN_On;
                        localDW->temporalCounter_i2_f = 0U;
                    }

                    // During 'On': '<S3>:92'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2_f) >=
                           40U) {
                    // Transition: '<S3>:99'
                    localDW->is_Debounce_m4 =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_L0Engaged;

                    // Entry Internal 'L0Engaged': '<S3>:101'
                    // Transition: '<S3>:120'
                    localDW->is_L0Engaged = Real2SimGuidance_IN_L0Default;

                    // Entry 'L0Default': '<S3>:106'
                    localDW->Execution = 1.0;

                    // Entry Internal 'L0Default': '<S3>:106'
                    // Transition: '<S3>:108'
                    localDW->is_L0Default = Real2SimGuidance_IN_Normal;
                } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S3>:96'
                    localDW->is_Debounce_m4 = Real2SimGuidance_IN_Off;
                    localDW->temporalCounter_i2_f = 0U;
                }
                break;

              case Real2SimGuidance_IN_L0Engaged:
                // During 'L0Engaged': '<S3>:101'
                if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S3>:91'
                    // Exit Internal 'L0Engaged': '<S3>:101'
                    // Exit Internal 'Debounce': '<S3>:111'
                    localDW->is_Debounce_b = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

                    // Exit Internal 'L0Default': '<S3>:106'
                    localDW->is_L0Default = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_L0Engaged = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_i = 0U;
                    localDW->is_Debounce_m4 = Real2SimGuidance_IN_Off;
                    localDW->temporalCounter_i2_f = 0U;
                } else {
                    switch (localDW->is_L0Engaged) {
                      case Real2SimGuidance_IN_Debounce:
                        // During 'Debounce': '<S3>:111'
                        if (static_cast<uint32_T>(localDW->temporalCounter_i1_i)
                            >= 60U) {
                            // Transition: '<S3>:119'
                            // Exit Internal 'Debounce': '<S3>:111'
                            localDW->is_Debounce_b =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged =
                                Real2SimGuidance_IN_L0Default;

                            // Entry 'L0Default': '<S3>:106'
                            localDW->Execution = 1.0;
                            localDW->is_L0Default = Real2SimGuidance_IN_Fault;
                            localDW->temporalCounter_i1_i = 0U;

                            // Entry 'Fault': '<S3>:109'
                        } else if (localDW->is_Debounce_b ==
                                   Real2SimGuidance_IN_Off) {
                            // During 'Off': '<S3>:114'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i2_f) >= 30U) {
                                // Transition: '<S3>:122'
                                localDW->is_Debounce_b =
                                    Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                                localDW->is_L0Engaged =
                                    Real2SimGuidance_IN_L0Default;

                                // Entry 'L0Default': '<S3>:106'
                                localDW->Execution = 1.0;

                                // Entry Internal 'L0Default': '<S3>:106'
                                // Transition: '<S3>:108'
                                localDW->is_L0Default =
                                    Real2SimGuidance_IN_Normal;
                            } else if (static_cast<int32_T>(*rty_EngagedFlag) >
                                       1) {
                                // Transition: '<S3>:115'
                                localDW->is_Debounce_b = Real2SimGuidance_IN_On;
                                localDW->temporalCounter_i2_f = 0U;
                            }

                            // During 'On': '<S3>:113'
                        } else if (static_cast<uint32_T>
                                   (localDW->temporalCounter_i2_f) >= 30U) {
                            // Transition: '<S3>:118'
                            localDW->is_Debounce_b =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged =
                                Real2SimGuidance_IN_L1Engaged;

                            // Entry 'L1Engaged': '<S3>:112'
                            localDW->Execution = 2.0;
                        } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 1)
                        {
                            // Transition: '<S3>:116'
                            localDW->is_Debounce_b = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_f = 0U;
                        }
                        break;

                      case Real2SimGuidance_IN_L0Default:
                        localDW->Execution = 1.0;

                        // During 'L0Default': '<S3>:106'
                        if (localDW->is_L0Default == Real2SimGuidance_IN_Fault)
                        {
                            // During 'Fault': '<S3>:109'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i1_i) >= 600U) {
                                // Transition: '<S3>:107'
                                localDW->is_L0Default =
                                    Real2SimGuidance_IN_Normal;
                            }

                            // During 'Normal': '<S3>:110'
                        } else if (static_cast<int32_T>(*rty_EngagedFlag) > 1) {
                            // Transition: '<S3>:117'
                            localDW->is_L0Default =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged = Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1_i = 0U;
                            localDW->is_Debounce_b = Real2SimGuidance_IN_On;
                            localDW->temporalCounter_i2_f = 0U;
                        }
                        break;

                      default:
                        localDW->Execution = 2.0;

                        // During 'L1Engaged': '<S3>:112'
                        if (static_cast<int32_T>(*rty_EngagedFlag) <= 1) {
                            // Transition: '<S3>:121'
                            localDW->is_L0Engaged = Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1_i = 0U;
                            localDW->is_Debounce_b = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_f = 0U;
                        }
                        break;
                    }
                }
                break;

              default:
                localDW->Execution = 0.0;

                // During 'Persuit': '<S3>:95'
                if (localDW->is_Persuit == Real2SimGuidance_IN_Fault) {
                    // During 'Fault': '<S3>:94'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i1_i) >=
                            600U) {
                        // Transition: '<S3>:89'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    }

                    // During 'Normal': '<S3>:88'
                } else if (static_cast<boolean_T>(static_cast<int32_T>((
                              static_cast<int32_T>(*rty_EngagedFlag) > 0) &
                             static_cast<int32_T>(rtb_NoNewMission)))) {
                    // Transition: '<S3>:98'
                    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_i = 0U;
                    localDW->is_Debounce_m4 = Real2SimGuidance_IN_On;
                    localDW->temporalCounter_i2_f = 0U;
                }
                break;
            }
        }

        // End of Chart: '<Root>/EngagementDebouncer'

        // DataStoreWrite: '<Root>/WriteEngagedFlag_Log'
        localDW->EngagedFlag = localDW->Execution;

        // Logic: '<Root>/NoNewMission'
        rtb_NoNewMission = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(*rtu_NewMission) ^ 1));

        // Product: '<Root>/Product' incorporates:
        //   DataStoreWrite: '<Root>/WriteFlightMode_Log'
        //   DataTypeConversion: '<Root>/Cast To Double'
        //   Logic: '<Root>/NOT'

        localDW->FlightMode_Log = static_cast<real_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (rtu_ControlSwitch[1]) ^ 1)))) * (rtb_NoNewMission ?
            static_cast<real_T>(*rtu_FlightMode) : 0.0);

        // RelationalOperator: '<S1>/Compare' incorporates:
        //   Constant: '<S1>/Constant'

        rtb_NoNewMission = (static_cast<int32_T>(*rtu_FlightMode) == 3);

        // BusCreator: '<Root>/CreatADRC' incorporates:
        //   DataStoreRead: '<Root>/ReadADRC_Log'

        rty_FlightLogging->ADRC_Log.x1_ControlError = localDW->ADRC_Log[0];
        rty_FlightLogging->ADRC_Log.x2 = localDW->ADRC_Log[1];
        rty_FlightLogging->ADRC_Log.x3_TotalDisturbance = localDW->ADRC_Log[2];
        rty_FlightLogging->ADRC_Log.u = localDW->ADRC_Log[3];

        // Switch: '<Root>/SwitchLookAheadPoint' incorporates:
        //   ZeroOrderHold: '<S8>/LookaheadPoint_ZOH'

        if (rtu_ControlSwitch[0]) {
            // Sum: '<Root>/SumNorth' incorporates:
            //   Constant: '<Root>/LookAheadDis'
            //   Product: '<Root>/ProductNorth'
            //   Trigonometry: '<Root>/Cos'

            rtb_SumNorth = std::cos(rtu_ImmedGuidanceCMD->HeadingAngle) * 1000.0
                + rtb_FixedWingGuidanceStateBus.North;

            // Sum: '<Root>/SumEast' incorporates:
            //   Constant: '<Root>/LookAheadDis'
            //   Product: '<Root>/ProductEast'
            //   Trigonometry: '<Root>/Sin'

            rtb_SumEast = 1000.0 * std::sin(rtu_ImmedGuidanceCMD->HeadingAngle)
                + rtb_FixedWingGuidanceStateBus.East;
            rtb_SwitchLookAheadPoint[0] = rtb_SumNorth;
            rtb_SwitchLookAheadPoint[1] = rtb_SumEast;
            rtb_SwitchLookAheadPoint[2] = rtu_ImmedGuidanceCMD->Height;
        } else {
            rtb_SwitchLookAheadPoint[0] = rtb_RealUAVNEUState_idx_0;
            rtb_SwitchLookAheadPoint[1] = rtb_RealUAVNEUState_idx_1;
            rtb_SwitchLookAheadPoint[2] = rtb_RealUAVNEUState_idx_2;
        }

        // End of Switch: '<Root>/SwitchLookAheadPoint'

        // UnitConversion: '<S56>/Unit Conversion' incorporates:
        //   DataStoreRead: '<S7>/LatitudeGCS'
        //   Switch: '<S51>/Switch'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum_k = 0.017453292519943295 * LatitudeGCS;

        // Trigonometry: '<S57>/Trigonometric Function1'
        rtb_Abs1 = std::sin(rtb_Sum_k);

        // Sum: '<S57>/Sum1' incorporates:
        //   Constant: '<S57>/Constant'
        //   Product: '<S57>/Product1'

        rtb_Abs1 = 1.0 - 0.0066943799901413295 * rtb_Abs1 * rtb_Abs1;

        // Product: '<S54>/Product1' incorporates:
        //   Constant: '<S54>/Constant1'
        //   Sqrt: '<S54>/sqrt'

        rtb_Switch = 6.378137E+6 / std::sqrt(rtb_Abs1);

        // Sum: '<S37>/Sum' incorporates:
        //   Constant: '<S54>/Constant2'
        //   DataStoreRead: '<S7>/LatitudeGCS'
        //   Product: '<S40>/rad lat'
        //   Product: '<S40>/x*cos'
        //   Product: '<S40>/y*sin'
        //   Product: '<S54>/Product3'
        //   Sum: '<S40>/Sum'
        //   Switch: '<S51>/Switch'
        //   Trigonometry: '<S54>/Trigonometric Function1'
        //   UnitConversion: '<S41>/Unit Conversion'

        // Unit Conversion - from: rad to: deg
        // Expression: output = (57.2958*input) + (0)
        rtb_Sum1_idx_0 = (rtb_SwitchLookAheadPoint[0] -
                          rtb_SwitchLookAheadPoint[1] * 0.0) * rt_atan2d_snf(1.0,
            rtb_Switch * 0.99330562000985867 / rtb_Abs1) * 57.295779513082323 +
            LatitudeGCS;

        // Switch: '<S45>/Switch' incorporates:
        //   Abs: '<S45>/Abs'
        //   Bias: '<S45>/Bias'
        //   Bias: '<S45>/Bias1'
        //   Constant: '<S45>/Constant2'
        //   Constant: '<S46>/Constant'
        //   Math: '<S45>/Math Function1'
        //   RelationalOperator: '<S46>/Compare'

        if (std::abs(rtb_Sum1_idx_0) > 180.0) {
            rtb_Sum1_idx_0 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S45>/Switch'

        // Abs: '<S42>/Abs1'
        rtb_Gain_p = std::abs(rtb_Sum1_idx_0);

        // Switch: '<S42>/Switch' incorporates:
        //   Bias: '<S42>/Bias'
        //   Bias: '<S42>/Bias1'
        //   Constant: '<S38>/Constant'
        //   Constant: '<S38>/Constant1'
        //   Constant: '<S44>/Constant'
        //   Gain: '<S42>/Gain'
        //   Product: '<S42>/Divide1'
        //   RelationalOperator: '<S44>/Compare'
        //   Switch: '<S38>/Switch1'

        if (rtb_Gain_p > 90.0) {
            // Signum: '<S42>/Sign1'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Sum1_idx_0)) ^ 1))) {
                if (rtb_Sum1_idx_0 < 0.0) {
                    rtb_Sum1_idx_0 = -1.0;
                } else {
                    rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Sum1_idx_0 > 0.0);
                }
            }

            // End of Signum: '<S42>/Sign1'
            rtb_Sum1_idx_0 *= -(rtb_Gain_p + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S42>/Switch'

        // Sum: '<S38>/Sum' incorporates:
        //   Constant: '<S54>/Constant3'
        //   DataStoreRead: '<S7>/LongitudeGCS'
        //   Product: '<S40>/rad long '
        //   Product: '<S40>/x*sin'
        //   Product: '<S40>/y*cos'
        //   Product: '<S54>/Product4'
        //   Sum: '<S37>/Sum'
        //   Sum: '<S39>/Sum'
        //   Sum: '<S40>/Sum1'
        //   Trigonometry: '<S54>/Trigonometric Function'
        //   Trigonometry: '<S54>/Trigonometric Function2'
        //   UnitConversion: '<S41>/Unit Conversion'

        rtb_Sum_i = ((rtb_SwitchLookAheadPoint[0] * 0.0 +
                      rtb_SwitchLookAheadPoint[1]) * rt_atan2d_snf(1.0,
                      rtb_Switch * std::cos(rtb_Sum_k)) * 57.295779513082323 +
                     LongitudeGCS) + static_cast<real_T>(i);

        // Switch: '<S43>/Switch' incorporates:
        //   Abs: '<S43>/Abs'
        //   Bias: '<S43>/Bias'
        //   Bias: '<S43>/Bias1'
        //   Constant: '<S43>/Constant2'
        //   Constant: '<S47>/Constant'
        //   Math: '<S43>/Math Function1'
        //   RelationalOperator: '<S47>/Compare'

        if (std::abs(rtb_Sum_i) > 180.0) {
            rtb_Sum_i = rt_modd_snf(rtb_Sum_i + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S43>/Switch'

        // Sum: '<S37>/Sum1' incorporates:
        //   DataStoreRead: '<S7>/AltitudeGCS'
        //   Gain: '<S7>/Up2Down'
        //   Gain: '<S7>/inverse'

        Switch = rtb_SwitchLookAheadPoint[2] - (-AltitudeGCS);

        // Saturate: '<Root>/Saturation'
        if (Switch <= 80.0) {
            rty_FCUCMD->Height_meter = 80.0;
        } else {
            rty_FCUCMD->Height_meter = Switch;
        }

        // End of Saturate: '<Root>/Saturation'

        // MATLAB Function: '<Root>/Get Nominal Flight Speed'
        // MATLAB Function 'Get Nominal Flight Speed': '<S5>:1'
        // '<S5>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->SingletonInstance_not_empty) ^ 1))) {
            localDW->SingletonInstance.DubinsConnector.AirSpeed = 10.0;
            localDW->SingletonInstance.DubinsConnector.MaxRollAngle =
                0.3490658503988659;
            localDW->SingletonInstance.DubinsConnector.AirSpeed = 35.0;
            localDW->SingletonInstance_not_empty = true;
        }

        Switch = localDW->SingletonInstance.DubinsConnector.AirSpeed;

        // End of MATLAB Function: '<Root>/Get Nominal Flight Speed'

        // Switch: '<Root>/Switch'
        if (rtb_NoNewMission) {
            // Switch: '<Root>/SwitchSpdControl'
            if (rtu_ControlSwitch[1]) {
                Switch = rtu_ImmedGuidanceCMD->AirSpeed;
            } else {
                Switch = rtb_RefAirspeed_Log;
            }

            // End of Switch: '<Root>/SwitchSpdControl'
        }

        // End of Switch: '<Root>/Switch'

        // BusCreator: '<Root>/FcuCmdBus'
        rty_FCUCMD->Latitude_deg = rtb_Sum1_idx_0;
        rty_FCUCMD->Longitude_deg = rtb_Sum_i;
        rty_FCUCMD->RefAirSpd_mps = Switch;

        // DataStoreRead: '<Root>/ReadLagDistance'
        rty_FlightLogging->InnerState.LagDistance = localDW->LagDistance;

        // DataStoreRead: '<Root>/ReadCrossTrackError'
        rty_FlightLogging->InnerState.CrossTrackError = localDW->CrossTrackError;

        // DataStoreRead: '<Root>/ReadEngagedFlag_Log'
        rty_FlightLogging->InnerState.EngagedFlag = localDW->EngagedFlag;

        // DataStoreRead: '<Root>/ReadbiasH_Log'
        rty_FlightLogging->InnerState.biasH = localDW->biasH_Log;

        // DataStoreRead: '<Root>/ReadStatus_Log'
        rty_FlightLogging->InnerState.HdgStatus = localDW->HdgStatus_Log;

        // BusCreator: '<Root>/InnerStateBus' incorporates:
        //   DataStoreRead: '<Root>/ReadHeading_Log'

        rty_FlightLogging->InnerState.RealHeading = localDW->Heading_Log[1];
        rty_FlightLogging->InnerState.TargetHeading = localDW->Heading_Log[2];
        rty_FlightLogging->InnerState.HeadingDiff = localDW->Heading_Log[0];

        // DataStoreRead: '<Root>/ReadFlightMode_Log'
        rty_FlightLogging->MiscStatus.FlightMode = localDW->FlightMode_Log;

        // BusCreator: '<Root>/MiscStateBus' incorporates:
        //   Trigonometry: '<S4>/Atan2'

        rty_FlightLogging->MiscStatus.GroundSpeed = rtu_StateFCU->GndSpd_mps;
        rty_FlightLogging->MiscStatus.Altitude = rtu_StateFCU->Altitude;
        rty_FlightLogging->MiscStatus.FlightPath = rt_atan2d_snf
            (rtu_StateFCU->VecSpd.skySpeed, rtu_StateFCU->GndSpd_mps);

        // MATLAB Function: '<Root>/TimeNow'
        // MATLAB Function 'TimeNow': '<S10>:1'
        // '<S10>:1:3'
        Real2SimGuidance_getLocalTime(&rtb_RefAirspeed_Log, &rtb_Gain_p,
            &rtb_RealUAVNEUState_idx_0, &rtb_Abs1, &rtb_Abs1_k, &Switch,
            &rtb_Sum_k, &rtb_NoNewMission);
        rtb_RealUAVNEUState_idx_1 = rtb_Abs1;
        rtb_RealUAVNEUState_idx_2 = rtb_Gain_p;
        rtb_Sum1_idx_0 = rtb_RefAirspeed_Log / 1.0E+6;
        rtb_RefAirspeed_Log = rtb_Gain_p;
        rtb_Switch = rtb_Sum1_idx_0;
        rtb_Gain_p = (((((rtb_Sum_k + Switch) + rtb_Abs1_k) + rtb_Abs1) +
                       rtb_RealUAVNEUState_idx_0) + rtb_Gain_p) + rtb_Sum1_idx_0;
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(rtb_Gain_p)) ^ 1))) & static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(rtb_Gain_p)) ^ 1)))))) {
            rtb_Gain_p = rtb_Sum_k;
            rtb_Abs1 = Switch;
            if ((Switch < 1.0) || (Switch > 12.0)) {
                rtb_Abs1 = std::floor((Switch - 1.0) / 12.0);
                rtb_Gain_p = rtb_Sum_k + rtb_Abs1;
                rtb_Abs1 = ((Switch - 1.0) - rtb_Abs1 * 12.0) + 1.0;
            }

            if (rtb_Abs1 < 3.0) {
                rtb_Gain_p--;
                rtb_Abs1 += 9.0;
            } else {
                rtb_Abs1 -= 3.0;
            }

            if ((rtb_Sum1_idx_0 < 0.0) || (rtb_Sum1_idx_0 >= 1000.0)) {
                rtb_Switch = std::floor(rtb_Sum1_idx_0 / 1000.0);
                rtb_RefAirspeed_Log = rtb_RealUAVNEUState_idx_2 + rtb_Switch;
                rtb_Switch = rtb_Sum1_idx_0 - rtb_Switch * 1000.0;
            }

            inputArg_data.re = ((((((365.0 * rtb_Gain_p + std::floor(rtb_Gain_p /
                4.0)) - std::floor(rtb_Gain_p / 100.0)) + std::floor(rtb_Gain_p /
                                    400.0)) + std::floor((153.0 * rtb_Abs1 + 2.0)
                                   / 5.0)) + rtb_Abs1_k) + 60.0) - 719529.0;
            inputArg_data.im = 0.0;
            inputArg_data = Real2SimGuidance_plus(Real2SimGuidance_plus
                (Real2SimGuidance_plus(Real2SimGuidance_times(inputArg_data),
                (60.0 * rtb_RealUAVNEUState_idx_1 + rtb_RealUAVNEUState_idx_0) *
                60000.0), rtb_RefAirspeed_Log * 1000.0), rtb_Switch);
        } else {
            inputArg_data.re = rtb_Gain_p;
            inputArg_data.im = 0.0;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_RefAirspeed_Log,
            &rtb_Gain_p, &rtb_Switch, &rtb_Abs1, &rtb_Abs1_k, &Switch);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Switch, &rtb_Gain_p,
            &rtb_Abs1, &rtb_Abs1_k, &Switch, &rtb_Sum_k);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Abs1, &rtb_Abs1_k,
            &rtb_Switch, &Switch, &rtb_Sum_k, &rtb_HeadWind);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Abs1_k, &Switch,
            &rtb_Sum_k, &rtb_Abs1, &rtb_HeadWind, &rtb_Sum1_idx_0);
        Real2SimGuidance_getDateVec(inputArg_data, &Switch, &rtb_Sum_k,
            &rtb_HeadWind, &rtb_Sum1_idx_0, &rtb_Abs1_k, &rtb_Sum_i);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Sum_k, &rtb_HeadWind,
            &rtb_Sum1_idx_0, &rtb_Sum_i, &rtb_SwitchLookAheadPoint_c, &Switch);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_HeadWind,
            &rtb_Sum1_idx_0, &rtb_Sum_i, &rtb_SwitchLookAheadPoint_c,
            &rtb_RealUAVNEUState_idx_1, &rtb_Sum_k);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_HeadWind,
            &rtb_Sum1_idx_0, &rtb_Sum_i, &rtb_SwitchLookAheadPoint_c,
            &rtb_RealUAVNEUState_idx_1, &rtb_RealUAVNEUState_idx_0);
        rtb_Sum1_idx_0 = std::round(rtb_RefAirspeed_Log);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.year = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                rty_FlightLogging->TimeNow.year = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.year = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round(rtb_Gain_p);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.month = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                rty_FlightLogging->TimeNow.month = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.month = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round(rtb_Switch);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.day = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                rty_FlightLogging->TimeNow.day = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.day = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round(rtb_Abs1);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.hour = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                rty_FlightLogging->TimeNow.hour = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.hour = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round(rtb_Abs1_k);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.minute = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                rty_FlightLogging->TimeNow.minute = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.minute = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::floor(Switch);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.second = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                rty_FlightLogging->TimeNow.second = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.second = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round((rtb_Sum_k - std::floor
            (rtb_RealUAVNEUState_idx_0)) * 1000.0);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.millisecond = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                rty_FlightLogging->TimeNow.millisecond = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.millisecond = MAX_int32_T;
        }

        // End of MATLAB Function: '<Root>/TimeNow'

        // BusCreator: '<Root>/LoggingBus'
        rty_FlightLogging->RealUAVState = rtu_StateFCU->RealUAVState;
        rty_FlightLogging->SimUAVState = *rtu_SimUAVState;
        rty_FlightLogging->FlightCMD = *rty_FCUCMD;
        rty_FlightLogging->VectorSpd = rtu_StateFCU->VecSpd;
    }
}

// Update for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const boolean_T *rtu_NewMission, const
    FixedWingGuidanceStateBus *rtu_SimUAVState, DW_Real2SimGuidance_f_T *localDW)
{
    // Update for Atomic SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Update for Atomic SubSystem: '<S8>/HeadingNaNProtection'
        // Switch: '<S66>/HeightSwitch' incorporates:
        //   RelationalOperator: '<S66>/IsNaN'

        if (std::isnan(localDW->SwitchLookAheadNED[2])) {
            // Update for Memory: '<S66>/MemoryRefHeight' incorporates:
            //   Constant: '<S66>/DefaultHeight'

            localDW->MemoryRefHeight_PreviousInput = -150.0;
        } else {
            // Update for Memory: '<S66>/MemoryRefHeight'
            localDW->MemoryRefHeight_PreviousInput = localDW->
                SwitchLookAheadNED[2];
        }

        // End of Switch: '<S66>/HeightSwitch'
        // End of Update for SubSystem: '<S8>/HeadingNaNProtection'

        // Update for Memory: '<S8>/MemoryNotInBrake'
        localDW->MemoryNotInBrake_PreviousInput = localDW->Compare;

        // Update for Atomic SubSystem: '<S8>/GenerateTrack'
        for (int_T i{0}; i < 215; i++) {
            // Update for S-Function (sfix_udelay): '<S64>/EastSequence'
            localDW->EastSequence_X[i] = localDW->EastSequence_X
                [static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S64>/HeightSequence'
            localDW->HeightSequence_X[i] = localDW->HeightSequence_X[
                static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S64>/NorthSequence'
            localDW->NorthSequence_X[i] = localDW->NorthSequence_X
                [static_cast<int_T>(i + 1)];
        }

        // Update for S-Function (sfix_udelay): '<S64>/EastSequence'
        localDW->EastSequence_X[215] = rtu_SimUAVState->East;

        // Update for S-Function (sfix_udelay): '<S64>/HeightSequence'
        localDW->HeightSequence_X[215] = rtu_SimUAVState->Height;

        // Update for S-Function (sfix_udelay): '<S64>/NorthSequence'
        localDW->NorthSequence_X[215] = rtu_SimUAVState->North;

        // End of Update for SubSystem: '<S8>/GenerateTrack'

        // Update for Memory: '<S8>/Memory'
        localDW->Memory_PreviousInput = localDW->Engaged;

        // Update for Atomic SubSystem: '<S8>/HeadingLogic'
        // Update for Atomic SubSystem: '<S65>/NewMissionHdg'
        // Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S71>/Constant'

        localDW->DiscreteTimeIntegrator_DSTATE += 0.5;
        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        }

        localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
            (*rtu_NewMission);

        // End of Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' 
        // End of Update for SubSystem: '<S65>/NewMissionHdg'
        // End of Update for SubSystem: '<S8>/HeadingLogic'
    }

    // Update for Atomic SubSystem: '<S8>/SpeedControl'
    // Update for Enabled SubSystem: '<S69>/SpdFBControl' incorporates:
    //   EnablePort: '<S83>/Enable'

    if (localDW->SpdFBControl_MODE && rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Update for Enabled SubSystem: '<S83>/PID' incorporates:
        //   EnablePort: '<S86>/Enable'

        if (localDW->PID_MODE) {
            // Update for Delay: '<S125>/UD'
            localDW->UD_DSTATE = localDW->Tsamp;

            // Update for DiscreteIntegrator: '<S132>/Integrator'
            localDW->Integrator_DSTATE += 0.1 * localDW->IProdOut;
        }

        // End of Update for SubSystem: '<S83>/PID'
    }

    // End of Update for SubSystem: '<S69>/SpdFBControl'
    // End of Update for SubSystem: '<S8>/SpeedControl'
    // End of Update for SubSystem: '<Root>/Real2SimNav'
}

// Derivatives for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot)
{
    // Derivatives for Atomic SubSystem: '<Root>/Real2SimNav'
    // Derivatives for Atomic SubSystem: '<S8>/SpeedControl'
    // Derivatives for Enabled SubSystem: '<S69>/SpdFBControl'
    if (localDW->SpdFBControl_MODE) {
        // Derivatives for Enabled SubSystem: '<S83>/ADRC'
        if (localDW->ADRC_MODE) {
            // Derivatives for Integrator: '<S88>/Integrator'
            localXdot->Integrator_CSTATE[0] =
                localDW->estimatedExtendedStateDerivative[0];
            localXdot->Integrator_CSTATE[1] =
                localDW->estimatedExtendedStateDerivative[1];
            localXdot->Integrator_CSTATE[2] =
                localDW->estimatedExtendedStateDerivative[2];
        } else {
            {
                real_T *dx;
                int_T i;
                dx = &(localXdot->Integrator_CSTATE[0]);
                for (i=0; i < 3; i++) {
                    dx[i] = 0.0;
                }
            }
        }

        // End of Derivatives for SubSystem: '<S83>/ADRC'
    } else {
        {
            real_T *dx;
            int_T i;
            dx = &(localXdot->Integrator_CSTATE[0]);
            for (i=0; i < 3; i++) {
                dx[i] = 0.0;
            }
        }
    }

    // End of Derivatives for SubSystem: '<S69>/SpdFBControl'
    // End of Derivatives for SubSystem: '<S8>/SpeedControl'

    // Derivatives for Integrator: '<S70>/TD_Alt'
    localXdot->TD_Alt_CSTATE = localDW->dotAltTD;

    // Derivatives for Integrator: '<S70>/dotAltTD'
    localXdot->dotAltTD_CSTATE = localDW->fh;

    // End of Derivatives for SubSystem: '<Root>/Real2SimNav'
}

// Model initialize function
void Real2SimGuidance_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
    *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
    RT_MODEL_Real2SimGuidance_T *const Real2SimGuidance_M)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));

    // setup the global timing engine
    Real2SimGuidance_M->Timing.mdlref_GlobalTID[0] = mdlref_TID0;
    Real2SimGuidance_M->Timing.mdlref_GlobalTID[1] = mdlref_TID1;
    Real2SimGuidance_M->timingBridge = (timingBridge);

    // initialize error status
    rtmSetErrorStatusPointer(Real2SimGuidance_M, rt_errorStatus);

    // initialize stop requested flag
    rtmSetStopRequestedPtr(Real2SimGuidance_M, rt_stopRequested);

    // initialize RTWSolverInfo
    Real2SimGuidance_M->solverInfo = (rt_solverInfo);

    // Set the Timing fields to the appropriate data in the RTWSolverInfo
    rtmSetSimTimeStepPointer(Real2SimGuidance_M, rtsiGetSimTimeStepPtr
        (Real2SimGuidance_M->solverInfo));
    Real2SimGuidance_M->Timing.stepSize0 = (rtsiGetStepSize
        (Real2SimGuidance_M->solverInfo));
}

//
// File trailer for generated code.
//
// [EOF]
//
