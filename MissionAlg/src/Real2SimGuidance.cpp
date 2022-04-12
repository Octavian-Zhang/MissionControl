//
// File: Real2SimGuidance.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.128
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Tue Apr 12 04:37:41 2022
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
#include "Real2SimGuidance_private.h"
#include "angdiff_9SMt2WI9.h"
#include "div_s32.h"
#include "floor_6aYiD2p8.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "split_lIfqwsQg.h"

// Named constants for Chart: '<Root>/EngagementDebouncer'
const uint8_T Real2SimGuidance_IN_Debounce{ 1U };

const uint8_T Real2SimGuidance_IN_Fault{ 1U };

const uint8_T Real2SimGuidance_IN_L0Default{ 2U };

const uint8_T Real2SimGuidance_IN_L0Engaged{ 2U };

const uint8_T Real2SimGuidance_IN_L1Engaged{ 3U };

const uint8_T Real2SimGuidance_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T Real2SimGuidance_IN_Normal{ 2U };

const uint8_T Real2SimGuidance_IN_Off{ 1U };

const uint8_T Real2SimGuidance_IN_On{ 2U };

const uint8_T Real2SimGuidance_IN_Persuit{ 3U };

// Named constants for Chart: '<S6>/Chart'
const uint8_T Real2SimGuidance_IN_NoBias{ 1U };

const uint8_T Real2SimGuidance_IN_hasBias{ 2U };

// Named constants for Chart: '<S69>/MissionSwitchInitialPersuit'
const uint8_T Real2SimGuidance_IN_Initial{ 1U };

const uint8_T Real2SimGuidance_IN_L1Hdg{ 2U };

const uint8_T Real2SimGuidance_IN_L1Hdg_b{ 1U };

const uint8_T Real2SimGuidance_IN_SimPnt{ 3U };

const uint8_T Real2SimGuidance_IN_SimPnt_g{ 2U };

// Named constants for Chart: '<S74>/ControlLogic'
const uint8_T Real2SimGuidance_IN_ADRC{ 1U };

const uint8_T Real2SimGuidance_IN_ADRC2PD{ 1U };

const uint8_T Real2SimGuidance_IN_Debounce_n{ 2U };

const uint8_T Real2SimGuidance_IN_PD{ 3U };

const uint8_T Real2SimGuidance_IN_PD2ADRC{ 2U };

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
    *pEmxArray = (emxArray_real_T_Real2SimGuidance_T *)std::malloc(sizeof
        (emxArray_real_T_Real2SimGuidance_T));
    emxArray = *pEmxArray;
    emxArray->data = (real_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
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
    if (*pEmxArray != (emxArray_real_T_Real2SimGuidance_T *)nullptr) {
        if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_real_T_Real2SimGuidance_T *)nullptr;
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

        emxArray->data = (real_T *)newData;
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
    real_T appendedWaypoints_data[6];
    real_T virtualWaypoint[3];
    real_T waypoints_0[3];
    real_T lambda;
    real_T virtualWaypoint_tmp_tmp;
    real_T virtualWaypoint_tmp_tmp_0;
    real_T virtualWaypoint_tmp_tmp_1;
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T c_size_idx_0;
    int32_T i1;
    int32_T i2;
    int32_T iy;
    int32_T j;
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

    c_size_idx_0 = i1;
    i1 = 0;
    for (iy = 0; iy < 217; iy++) {
        if (b[iy]) {
            c_data[i1] = static_cast<uint8_T>(static_cast<int32_T>(iy + 1));
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    for (iy = 0; iy < 3; iy++) {
        for (j = 0; j <= static_cast<int32_T>(c_size_idx_0 - 1); j++) {
            localDW->b_waypointsIn_data[static_cast<int32_T>(j + static_cast<
                int32_T>(c_size_idx_0 * iy))] = waypoints[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(217 * iy) +
                static_cast<int32_T>(c_data[j])) - 1)];
        }
    }

    obj->NumWaypoints = static_cast<real_T>(c_size_idx_0);
    obj->LookaheadDistance = lambda;
    Real2SimGuidance_emxInit_real_T(&d, 2);
    if (c_size_idx_0 == 0) {
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
        if (c_size_idx_0 == 1) {
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
                for (iy = 0; iy < 3; iy++) {
                    appendedWaypoints_data[static_cast<int32_T>(iy << 1)] =
                        obj->InitialPose[iy];
                    for (j = 0; j <= static_cast<int32_T>(c_size_idx_0 - 1); j++)
                    {
                        appendedWaypoints_data[static_cast<int32_T>(static_cast<
                            int32_T>(j + static_cast<int32_T>(iy << 1)) + 1)] =
                            localDW->b_waypointsIn_data[static_cast<int32_T>(
                            static_cast<int32_T>(c_size_idx_0 * iy) + j)];
                    }
                }

                obj->NumWaypoints = 2.0;
                c_size_idx_0 = 2;
                for (iy = 0; iy < 6; iy++) {
                    localDW->waypoints_data[iy] = appendedWaypoints_data[iy];
                }

                guard1 = true;
            }
        } else {
            i1 = static_cast<int32_T>(c_size_idx_0 * 3);
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
                        1.0) + c_size_idx_0) - 1)];
                    virtualWaypoint_tmp_tmp_3 = localDW->waypoints_data[
                        static_cast<int32_T>(iy + c_size_idx_0)];
                    virtualWaypoint_tmp_0 = virtualWaypoint_tmp_tmp_0 -
                        virtualWaypoint_tmp_tmp_3;
                    virtualWaypoint_tmp_tmp_1 = localDW->waypoints_data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>((static_cast<real_T>(iy) + 1.0) +
                        1.0) + static_cast<int32_T>(c_size_idx_0 << 1)) - 1)];
                    virtualWaypoint_tmp_tmp_4 = localDW->waypoints_data[
                        static_cast<int32_T>(static_cast<int32_T>(c_size_idx_0 <<
                        1) + iy)];
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
                (obj->WaypointIndex + 1.0) + c_size_idx_0) - 1)];
            virtualWaypoint[1] = currentPose[1] - virtualWaypoint_tmp_tmp_3;
            virtualWaypoint_tmp_tmp_4 = localDW->waypoints_data
                [static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
                (obj->WaypointIndex + 1.0) + static_cast<int32_T>(c_size_idx_0 <<
                1)) - 1)];
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
                              (obj->WaypointIndex) + c_size_idx_0) - 1)];
                lambda_tmp_0 = virtualWaypoint_tmp_tmp_3 -
                    virtualWaypoint_tmp_tmp_0;
                waypoints_0[1] = lambda_tmp_0;
                virtualWaypoint_tmp_tmp = localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(c_size_idx_0 << 1) +
                     static_cast<int32_T>(obj->WaypointIndex)) - 1)];
                waypoints_tmp = virtualWaypoint_tmp_tmp_4 -
                    virtualWaypoint_tmp_tmp;
                waypoints_0[2] = waypoints_tmp;
                b_0 = Real2SimGuidance_norm(waypoints_0);
                lambda = (lambda_tmp / b_0 * (virtualWaypoint[0] / lambda) +
                          lambda_tmp_0 / b_0 * (virtualWaypoint[1] / lambda)) +
                    waypoints_tmp / b_0 * (virtualWaypoint[2] / lambda);
                if (lambda < 0.0) {
                    lambda = -1.0;
                } else if (lambda > 0.0) {
                    lambda = 1.0;
                } else if (lambda == 0.0) {
                    lambda = 0.0;
                } else {
                    lambda = (rtNaN);
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
                              (obj->WaypointIndex) + c_size_idx_0) - 1)];
                varargout_1[1] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + c_size_idx_0) - 1)];
                virtualWaypoint_tmp_tmp = localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(c_size_idx_0 << 1) +
                     static_cast<int32_T>(obj->WaypointIndex)) - 1)];
                varargout_1[2] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + static_cast<int32_T>(c_size_idx_0 << 1)) - 1)];
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
    da = split_lIfqwsQg(a);
    shi = a * 8.64E+7;
    slo = (da.re * 8.64E+7 - shi) + da.im * 8.64E+7;
    trueCount = 0;
    if (std::isnan(slo)) {
        trueCount = 1;
    }

    if (0 <= static_cast<int32_T>(trueCount - 1)) {
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

    if (0 <= static_cast<int32_T>(trueCount - 1)) {
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
    t = floor_6aYiD2p8(b_thi_0);
    b_thi = t.re + t.im;
    b_thi_0 = Real2SimGuidance_minus(dd, Real2SimGuidance_times(t));
    b_c.re = b_thi_0.re / 1000.0;
    t = split_lIfqwsQg(b_c.re);
    b_tmp = b_c.re * 1000.0;
    slo = (t.re * 1000.0 - b_tmp) + t.im * 1000.0;
    idn = 0;
    if (std::isnan(slo)) {
        idn = 1;
    }

    if (0 <= static_cast<int32_T>(idn - 1)) {
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
    t = floor_6aYiD2p8(b_thi_0);
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

    if (0 <= static_cast<int32_T>(trueCount - 1)) {
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
    int32_T i;

    // SystemInitialize for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Integrator: '<S68>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S68>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<S6>/GenerateTrack'
    for (i = 0; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S62>/HeightSequence' 
        localDW->HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<S6>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<S6>/SpeedControl'
    // SystemInitialize for Enabled SubSystem: '<S67>/ADRC'
    // SystemInitialize for Enabled SubSystem: '<S74>/ADRC'
    // InitializeConditions for Integrator: '<S86>/Integrator'
    localX->Integrator_CSTATE[0] = 0.0;
    localX->Integrator_CSTATE[1] = 0.0;
    localX->Integrator_CSTATE[2] = 0.0;

    // End of SystemInitialize for SubSystem: '<S74>/ADRC'
    // End of SystemInitialize for SubSystem: '<S67>/ADRC'
    // End of SystemInitialize for SubSystem: '<S6>/SpeedControl'

    // SystemInitialize for Atomic SubSystem: '<S6>/HeadingLogic'
    // SystemInitialize for Atomic SubSystem: '<S63>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S69>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // End of SystemInitialize for SubSystem: '<S63>/NewMissionHdg'

    // Start for MATLABSystem: '<S63>/TrackSimPath'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.SearchFlag = true;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S63>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 651; i++) {
        // InitializeConditions for MATLABSystem: '<S63>/TrackSimPath'
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S6>/HeadingLogic'
    // End of SystemInitialize for SubSystem: '<Root>/Real2SimNav'
}

// System reset for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Reset(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    int32_T i;

    // SystemReset for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Memory: '<S6>/MemoryNotInBrake'
    localDW->MemoryNotInBrake_PreviousInput = false;

    // InitializeConditions for Memory: '<S6>/Memory'
    localDW->Memory_PreviousInput = 0U;

    // InitializeConditions for Integrator: '<S68>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S68>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemReset for Atomic SubSystem: '<S6>/HeadingNaNProtection'
    // InitializeConditions for Memory: '<S64>/MemoryRefHeight'
    localDW->MemoryRefHeight_PreviousInput = 0.0;

    // End of SystemReset for SubSystem: '<S6>/HeadingNaNProtection'

    // SystemReset for Atomic SubSystem: '<S6>/GenerateTrack'
    for (i = 0; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S62>/EastSequence' 
        localDW->EastSequence_X[i] = 0.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S62>/HeightSequence' 
        localDW->HeightSequence_X[i] = -150.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S62>/NorthSequence' 
        localDW->NorthSequence_X[i] = 0.0;
    }

    // End of SystemReset for SubSystem: '<S6>/GenerateTrack'

    // SystemReset for Atomic SubSystem: '<S6>/HeadingLogic'
    // InitializeConditions for MATLABSystem: '<S63>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 651; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of InitializeConditions for MATLABSystem: '<S63>/TrackSimPath'

    // SystemReset for Atomic SubSystem: '<S63>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S69>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // SystemReset for Chart: '<S69>/MissionSwitchInitialPersuit'
    localDW->temporalCounter_i1 = 0U;
    localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce_i = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2 = 0U;
    localDW->is_active_c3_Real2SimGuidance = 0U;
    localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->SimHdg = 0.0;

    // End of SystemReset for SubSystem: '<S63>/NewMissionHdg'
    // End of SystemReset for SubSystem: '<S6>/HeadingLogic'

    // SystemReset for Chart: '<S6>/Chart'
    localDW->is_active_c2_Real2SimGuidance = 0U;
    localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

    // End of SystemReset for SubSystem: '<Root>/Real2SimNav'

    // SystemReset for Chart: '<Root>/TASgreaterthan15for1Sec'
    localDW->is_active_c16_Real2SimGuidance = 0U;
    localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

    // SystemReset for Chart: '<Root>/EngagementDebouncer'
    localDW->is_Debounce_id = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_L0Engaged = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce_a = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2_n = 0U;
    localDW->is_L0Default = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i1_o = 0U;
    localDW->is_active_c34_Real2SimGuidance = 0U;
    localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->Execution = 0.0;
}

// Disable for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW)
{
    // Disable for Atomic SubSystem: '<Root>/Real2SimNav'
    // Disable for Atomic SubSystem: '<S6>/SpeedControl'
    // Disable for Enabled SubSystem: '<S67>/ADRC'
    if (localDW->ADRC_MODE) {
        // Disable for Enabled SubSystem: '<S74>/ADRC'
        localDW->ADRC_MODE_c = false;

        // End of Disable for SubSystem: '<S74>/ADRC'

        // Disable for Enabled SubSystem: '<S74>/PD'
        localDW->PD_MODE = false;

        // End of Disable for SubSystem: '<S74>/PD'
        localDW->ADRC_MODE = false;
    }

    // End of Disable for SubSystem: '<S67>/ADRC'
    // End of Disable for SubSystem: '<S6>/SpeedControl'
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
                      const real_T *rtu_ParamADRC_D, FCUCMD *rty_FCUCMD, uint8_T
                      *rty_EngagedFlag, FlightLogging *rty_FlightLogging,
                      DW_Real2SimGuidance_f_T *localDW, X_Real2SimGuidance_n_T
                      *localX)
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
    real_T rtb_Gain_p;
    real_T rtb_LowerBound;
    real_T rtb_RealUAVNEUState_idx_0;
    real_T rtb_RealUAVNEUState_idx_1;
    real_T rtb_RealUAVNEUState_idx_2;
    real_T rtb_RefRngmMinRng;
    real_T rtb_Sum1_idx_0;
    real_T rtb_Sum1_idx_1;
    real_T rtb_Sum_k;
    real_T rtb_Switch;
    real_T rtb_Switch_b;
    real_T rtb_UpperBound;
    real_T rtb_UpperBound_e;
    int32_T i;
    uint8_T b_varargout_4;
    uint8_T b_varargout_6;
    uint8_T rtb_Memory;
    boolean_T rtb_GreaterThanOrEqual_h;
    boolean_T rtb_NoNewMission;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Switch: '<S26>/Switch' incorporates:
        //   Abs: '<S26>/Abs'
        //   Bias: '<S26>/Bias'
        //   Bias: '<S26>/Bias1'
        //   Constant: '<S26>/Constant2'
        //   Constant: '<S27>/Constant'
        //   DataStoreRead: '<S4>/LatitudeGCS'
        //   Math: '<S26>/Math Function1'
        //   RelationalOperator: '<S27>/Compare'

        if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch = LatitudeGCS;
        }

        // End of Switch: '<S26>/Switch'

        // Abs: '<S23>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch);

        // Switch: '<S23>/Switch' incorporates:
        //   Bias: '<S23>/Bias'
        //   Bias: '<S23>/Bias1'
        //   Constant: '<S14>/Constant'
        //   Constant: '<S14>/Constant1'
        //   Constant: '<S25>/Constant'
        //   Gain: '<S23>/Gain'
        //   Product: '<S23>/Divide1'
        //   RelationalOperator: '<S25>/Compare'
        //   Switch: '<S14>/Switch1'

        if (rtb_Abs1 > 90.0) {
            // Signum: '<S23>/Sign1'
            if (rtb_Switch < 0.0) {
                rtb_Switch = -1.0;
            } else if (rtb_Switch > 0.0) {
                rtb_Switch = 1.0;
            } else if (rtb_Switch == 0.0) {
                rtb_Switch = 0.0;
            } else {
                rtb_Switch = (rtNaN);
            }

            // End of Signum: '<S23>/Sign1'
            rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S23>/Switch'

        // Sum: '<S14>/Sum' incorporates:
        //   DataStoreRead: '<S4>/LongitudeGCS'

        rtb_Switch_b = static_cast<real_T>(i) + LongitudeGCS;

        // Switch: '<S24>/Switch' incorporates:
        //   Abs: '<S24>/Abs'
        //   Bias: '<S24>/Bias'
        //   Bias: '<S24>/Bias1'
        //   Constant: '<S24>/Constant2'
        //   Constant: '<S28>/Constant'
        //   Math: '<S24>/Math Function1'
        //   RelationalOperator: '<S28>/Compare'

        if (std::abs(rtb_Switch_b) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Switch_b + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S24>/Switch'

        // Sum: '<S12>/Sum1'
        rtb_Sum1_idx_0 = rtu_StateFCU->RealUAVState.Latitude_deg - rtb_Switch;
        rtb_Sum1_idx_1 = rtu_StateFCU->RealUAVState.Longitude_deg - rtb_Switch_b;

        // Switch: '<S20>/Switch' incorporates:
        //   Abs: '<S20>/Abs'
        //   Bias: '<S20>/Bias'
        //   Bias: '<S20>/Bias1'
        //   Constant: '<S20>/Constant2'
        //   Constant: '<S21>/Constant'
        //   Math: '<S20>/Math Function1'
        //   RelationalOperator: '<S21>/Compare'

        if (std::abs(rtb_Sum1_idx_0) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch_b = rtb_Sum1_idx_0;
        }

        // End of Switch: '<S20>/Switch'

        // Abs: '<S17>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch_b);

        // Switch: '<S17>/Switch' incorporates:
        //   Bias: '<S17>/Bias'
        //   Bias: '<S17>/Bias1'
        //   Constant: '<S13>/Constant'
        //   Constant: '<S13>/Constant1'
        //   Constant: '<S19>/Constant'
        //   Gain: '<S17>/Gain'
        //   Product: '<S17>/Divide1'
        //   RelationalOperator: '<S19>/Compare'
        //   Switch: '<S13>/Switch1'

        if (rtb_Abs1 > 90.0) {
            // Signum: '<S17>/Sign1'
            if (rtb_Switch_b < 0.0) {
                rtb_Switch_b = -1.0;
            } else if (rtb_Switch_b > 0.0) {
                rtb_Switch_b = 1.0;
            } else if (rtb_Switch_b == 0.0) {
                rtb_Switch_b = 0.0;
            } else {
                rtb_Switch_b = (rtNaN);
            }

            // End of Signum: '<S17>/Sign1'
            rtb_Switch_b *= -(rtb_Abs1 + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S17>/Switch'

        // Sum: '<S13>/Sum'
        rtb_Sum_k = static_cast<real_T>(i) + rtb_Sum1_idx_1;

        // Switch: '<S18>/Switch' incorporates:
        //   Abs: '<S18>/Abs'
        //   Bias: '<S18>/Bias'
        //   Bias: '<S18>/Bias1'
        //   Constant: '<S18>/Constant2'
        //   Constant: '<S22>/Constant'
        //   Math: '<S18>/Math Function1'
        //   RelationalOperator: '<S22>/Compare'

        if (std::abs(rtb_Sum_k) > 180.0) {
            rtb_Sum_k = rt_modd_snf(rtb_Sum_k + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S18>/Switch'

        // UnitConversion: '<S16>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Switch_b;
        rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_k;

        // UnitConversion: '<S31>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch *= 0.017453292519943295;

        // Trigonometry: '<S32>/Trigonometric Function1'
        rtb_Sum_k = std::sin(rtb_Switch);

        // Sum: '<S32>/Sum1' incorporates:
        //   Constant: '<S32>/Constant'
        //   Product: '<S32>/Product1'

        rtb_Sum_k = 1.0 - 0.0066943799901413295 * rtb_Sum_k * rtb_Sum_k;

        // Product: '<S30>/Product1' incorporates:
        //   Constant: '<S30>/Constant1'
        //   Sqrt: '<S30>/sqrt'

        rtb_Switch_b = 6.378137E+6 / std::sqrt(rtb_Sum_k);

        // Product: '<S15>/dNorth' incorporates:
        //   Constant: '<S30>/Constant2'
        //   Product: '<S30>/Product3'
        //   Trigonometry: '<S30>/Trigonometric Function1'

        rtb_Sum_k = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_b *
            0.99330562000985867 / rtb_Sum_k);

        // Product: '<S15>/dEast' incorporates:
        //   Constant: '<S30>/Constant3'
        //   Product: '<S30>/Product4'
        //   Trigonometry: '<S30>/Trigonometric Function'
        //   Trigonometry: '<S30>/Trigonometric Function2'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_b = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_b * std::cos
            (rtb_Switch)) * rtb_Sum1_idx_1;

        // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
        //   Constant: '<S4>/dummyRollAngleRate'
        //   DataStoreRead: '<S4>/AltitudeGCS'
        //   Gain: '<S10>/Gain1'
        //   Gain: '<S11>/Gain1'
        //   Gain: '<S4>/inverse'
        //   Gain: '<S9>/Gain1'
        //   Product: '<S15>/x*cos'
        //   Product: '<S15>/x*sin'
        //   Product: '<S15>/y*cos'
        //   Product: '<S15>/y*sin'
        //   Sum: '<S12>/Sum'
        //   Sum: '<S15>/Sum2'
        //   Sum: '<S15>/Sum3'

        rtb_FixedWingGuidanceStateBus.North = rtb_Switch_b * 0.0 + rtb_Sum_k;
        rtb_FixedWingGuidanceStateBus.East = rtb_Switch_b - rtb_Sum_k * 0.0;
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
        // Outputs for Atomic SubSystem: '<S6>/HeadingNaNProtection'
        // Memory: '<S64>/MemoryRefHeight'
        rtb_Switch = localDW->MemoryRefHeight_PreviousInput;

        // End of Outputs for SubSystem: '<S6>/HeadingNaNProtection'

        // Sum: '<S6>/Minus'
        localDW->HeadWind = rtb_FixedWingGuidanceStateBus.AirSpeed -
            rtu_StateFCU->GndSpd_mps;

        // Outputs for Atomic SubSystem: '<S6>/GenerateTrack'
        // S-Function (sfix_udelay): '<S62>/EastSequence'
        localDW->MatrixConcatenate[433] = rtu_SimUAVState->East;

        // S-Function (sfix_udelay): '<S62>/HeightSequence'
        localDW->MatrixConcatenate[650] = rtu_SimUAVState->Height;
        for (i = 0; i < 216; i++) {
            // S-Function (sfix_udelay): '<S62>/EastSequence'
            localDW->MatrixConcatenate[static_cast<int_T>(i + 217)] =
                localDW->EastSequence_X[i];

            // S-Function (sfix_udelay): '<S62>/HeightSequence'
            localDW->MatrixConcatenate[static_cast<int_T>(i + 434)] =
                localDW->HeightSequence_X[i];

            // S-Function (sfix_udelay): '<S62>/NorthSequence'
            localDW->MatrixConcatenate[i] = localDW->NorthSequence_X[i];
        }

        // S-Function (sfix_udelay): '<S62>/NorthSequence'
        localDW->MatrixConcatenate[216] = rtu_SimUAVState->North;

        // End of Outputs for SubSystem: '<S6>/GenerateTrack'

        // Memory: '<S6>/Memory'
        rtb_Memory = localDW->Memory_PreviousInput;

        // Outputs for Atomic SubSystem: '<S6>/SpeedControl'
        // Sum: '<S81>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/TargetLocation'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[60] - rtu_SimUAVState->North;

        // DotProduct: '<S81>/Dot Product'
        rtb_Sum_k = rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S81>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/TargetLocation'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[277] - rtu_SimUAVState->East;

        // DotProduct: '<S81>/Dot Product'
        rtb_Sum_k += rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S81>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/TargetLocation'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[494] -
            rtu_SimUAVState->Height;

        // Sqrt: '<S81>/sqrt' incorporates:
        //   DotProduct: '<S81>/Dot Product'

        rtb_Abs1 = std::sqrt(rtb_Sum1_idx_0 * rtb_Sum1_idx_0 + rtb_Sum_k);

        // Sum: '<S80>/Sum'
        rtb_SwitchLookAheadPoint[0] = rtu_SimUAVState->North -
            rtb_FixedWingGuidanceStateBus.North;
        rtb_SwitchLookAheadPoint[1] = rtu_SimUAVState->East -
            rtb_FixedWingGuidanceStateBus.East;
        rtb_SwitchLookAheadPoint[2] = rtu_SimUAVState->Height -
            rtu_SimUAVState->Height;

        // Sqrt: '<S80>/sqrt' incorporates:
        //   DotProduct: '<S80>/Dot Product'

        rtb_Switch_b = std::sqrt((rtb_SwitchLookAheadPoint[0] *
            rtb_SwitchLookAheadPoint[0] + rtb_SwitchLookAheadPoint[1] *
            rtb_SwitchLookAheadPoint[1]) + rtb_SwitchLookAheadPoint[2] *
            rtb_SwitchLookAheadPoint[2]);

        // Gain: '<S67>/Gain' incorporates:
        //   Sum: '<S67>/LagDistanceSum'

        localDW->Gain = -(rtb_Abs1 - rtb_Switch_b);

        // DataStoreWrite: '<S67>/WriteLagDistance'
        localDW->LagDistance = localDW->Gain;

        // Outputs for Enabled SubSystem: '<S67>/ADRC' incorporates:
        //   EnablePort: '<S74>/Enable'

        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Logic: '<S6>/AND' incorporates:
            //   Constant: '<S66>/Constant'
            //   DataStoreRead: '<S6>/ReadFlightMode_Log'
            //   Memory: '<S6>/MemoryNotInBrake'
            //   RelationalOperator: '<S66>/Compare'

            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((localDW->FlightMode_Log == 3.0) &
                                        static_cast<int32_T>
                                        (localDW->MemoryNotInBrake_PreviousInput))))
            {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (localDW->ADRC_MODE) ^ 1))) {
                    // SystemReset for Chart: '<S74>/ControlLogic'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->temporalCounter_i1_c = 0U;
                    localDW->is_active_c6_Real2SimGuidance = 0U;
                    localDW->is_c6_Real2SimGuidance =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->PD_U = false;
                    localDW->EnablePD = false;
                    localDW->EnableADRC = false;
                    localDW->ADRC_MODE = true;
                }
            } else if (localDW->ADRC_MODE) {
                // Disable for Enabled SubSystem: '<S74>/ADRC'
                localDW->ADRC_MODE_c = false;

                // End of Disable for SubSystem: '<S74>/ADRC'

                // Disable for Enabled SubSystem: '<S74>/PD'
                localDW->PD_MODE = false;

                // End of Disable for SubSystem: '<S74>/PD'
                localDW->ADRC_MODE = false;
            }

            // End of Logic: '<S6>/AND'
        }

        // End of Outputs for SubSystem: '<S67>/ADRC'
        // End of Outputs for SubSystem: '<S6>/SpeedControl'
        // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    }

    // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S6>/SpeedControl'
    // Outputs for Enabled SubSystem: '<S67>/ADRC' incorporates:
    //   EnablePort: '<S74>/Enable'

    if (localDW->ADRC_MODE) {
        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Chart: '<S74>/ControlLogic'
            if (static_cast<uint32_T>(localDW->temporalCounter_i1_c) < 15U) {
                localDW->temporalCounter_i1_c = static_cast<uint8_T>(
                    static_cast<uint32_T>(static_cast<uint32_T>
                    (localDW->temporalCounter_i1_c) + 1U));
            }

            // Gateway: Real2SimNav/SpeedControl/ADRC/ControlLogic
            // During: Real2SimNav/SpeedControl/ADRC/ControlLogic
            if (static_cast<uint32_T>(localDW->is_active_c6_Real2SimGuidance) ==
                0U) {
                // Entry: Real2SimNav/SpeedControl/ADRC/ControlLogic
                localDW->is_active_c6_Real2SimGuidance = 1U;

                // Entry Internal: Real2SimNav/SpeedControl/ADRC/ControlLogic
                // Transition: '<S83>:81'
                localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PD;

                // Entry 'PD': '<S83>:53'
                localDW->EnablePD = true;
                localDW->EnableADRC = false;
                localDW->PD_U = true;
            } else {
                switch (localDW->is_c6_Real2SimGuidance) {
                  case Real2SimGuidance_IN_ADRC:
                    localDW->EnablePD = false;
                    localDW->EnableADRC = true;
                    localDW->PD_U = false;

                    // During 'ADRC': '<S83>:63'
                    if (static_cast<int32_T>(rtb_Memory) == 0) {
                        // Transition: '<S83>:84'
                        localDW->is_c6_Real2SimGuidance =
                            Real2SimGuidance_IN_Debounce_n;
                        localDW->is_Debounce = Real2SimGuidance_IN_ADRC2PD;
                        localDW->temporalCounter_i1_c = 0U;

                        // Entry 'ADRC2PD': '<S83>:61'
                        localDW->EnablePD = true;
                    }
                    break;

                  case Real2SimGuidance_IN_Debounce_n:
                    // During 'Debounce': '<S83>:58'
                    if (static_cast<int32_T>(localDW->is_Debounce) == 1) {
                        localDW->EnablePD = true;

                        // During 'ADRC2PD': '<S83>:61'
                        if (static_cast<uint32_T>(localDW->temporalCounter_i1_c)
                            >= 10U) {
                            // Transition: '<S83>:86'
                            localDW->is_Debounce =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_c6_Real2SimGuidance =
                                Real2SimGuidance_IN_PD;

                            // Entry 'PD': '<S83>:53'
                            localDW->EnablePD = true;
                            localDW->EnableADRC = false;
                            localDW->PD_U = true;
                        } else if (static_cast<int32_T>(rtb_Memory) != 0) {
                            // Transition: '<S83>:59'
                            localDW->is_Debounce = Real2SimGuidance_IN_PD2ADRC;
                            localDW->temporalCounter_i1_c = 0U;

                            // Entry 'PD2ADRC': '<S83>:62'
                            localDW->EnableADRC = true;
                        }
                    } else {
                        localDW->EnableADRC = true;

                        // During 'PD2ADRC': '<S83>:62'
                        if (static_cast<uint32_T>(localDW->temporalCounter_i1_c)
                            >= 10U) {
                            // Transition: '<S83>:85'
                            localDW->is_Debounce =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_c6_Real2SimGuidance =
                                Real2SimGuidance_IN_ADRC;

                            // Entry 'ADRC': '<S83>:63'
                            localDW->EnablePD = false;
                            localDW->EnableADRC = true;
                            localDW->PD_U = false;
                        } else if (static_cast<int32_T>(rtb_Memory) == 0) {
                            // Transition: '<S83>:60'
                            localDW->is_Debounce = Real2SimGuidance_IN_ADRC2PD;
                            localDW->temporalCounter_i1_c = 0U;

                            // Entry 'ADRC2PD': '<S83>:61'
                            localDW->EnablePD = true;
                        }
                    }
                    break;

                  default:
                    localDW->EnablePD = true;
                    localDW->EnableADRC = false;
                    localDW->PD_U = true;

                    // During 'PD': '<S83>:53'
                    if (static_cast<int32_T>(rtb_Memory) != 0) {
                        // Transition: '<S83>:83'
                        localDW->is_c6_Real2SimGuidance =
                            Real2SimGuidance_IN_Debounce_n;
                        localDW->is_Debounce = Real2SimGuidance_IN_PD2ADRC;
                        localDW->temporalCounter_i1_c = 0U;

                        // Entry 'PD2ADRC': '<S83>:62'
                        localDW->EnableADRC = true;
                    }
                    break;
                }
            }

            // End of Chart: '<S74>/ControlLogic'

            // Outputs for Enabled SubSystem: '<S74>/ADRC' incorporates:
            //   EnablePort: '<S82>/Enable'

            if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
                if (localDW->EnableADRC) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(localDW->ADRC_MODE_c) ^ 1))) {
                        // InitializeConditions for Integrator: '<S86>/Integrator' 
                        localX->Integrator_CSTATE[0] = 0.0;
                        localX->Integrator_CSTATE[1] = 0.0;
                        localX->Integrator_CSTATE[2] = 0.0;
                        localDW->ADRC_MODE_c = true;
                    }
                } else {
                    localDW->ADRC_MODE_c = false;
                }
            }

            // End of Outputs for SubSystem: '<S74>/ADRC'
        }

        // Outputs for Enabled SubSystem: '<S74>/ADRC' incorporates:
        //   EnablePort: '<S82>/Enable'

        if (localDW->ADRC_MODE_c) {
            // Integrator: '<S86>/Integrator'
            localDW->Integrator[0] = localX->Integrator_CSTATE[0];
            localDW->Integrator[1] = localX->Integrator_CSTATE[1];
            localDW->Integrator[2] = localX->Integrator_CSTATE[2];

            // MATLAB Function: '<S88>/Extended state feedback robust controller' 
            // MATLAB Function 'ADRC controller/State feedback robust controller/Extended state feedback robust controller': '<S92>:1' 
            // '<S92>:1:8'
            if (*rtu_ParamADRC_hat_b == 0.0) {
                // '<S92>:1:17'
                // '<S92>:1:18'
                rtb_Sum1_idx_0 = 1.0;
            } else {
                // '<S92>:1:20'
                rtb_Sum1_idx_0 = *rtu_ParamADRC_hat_b;
            }

            // '<S92>:1:9'
            if (*rtu_ParamADRC_omega_b == 0.0) {
                // '<S92>:1:17'
                // '<S92>:1:18'
                rtb_Sum_k = 5.0;
            } else {
                // '<S92>:1:20'
                rtb_Sum_k = *rtu_ParamADRC_omega_b;
            }

            // Product: '<S94>/Product' incorporates:
            //   MATLAB Function: '<S88>/Extended state feedback robust controller'
            //   Step: '<S94>/Step'

            // '<S92>:1:10'
            // '<S92>:1:25'
            // '<S92>:1:26'
            // '<S92>:1:12'
            localDW->Product = ((rtb_Sum_k * rtb_Sum_k * localDW->Integrator[0]
                                 + (rtb_Sum_k - (-rtb_Sum_k)) *
                                 localDW->Integrator[1]) + localDW->Integrator[2])
                * (1.0 / rtb_Sum1_idx_0) * static_cast<real_T>
                (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                   (((*(Real2SimGuidance_M->timingBridge->
                        taskTime[Real2SimGuidance_M->Timing.mdlref_GlobalTID[0]]))
                     < 0.2) ^ 1))));

            // MATLAB Function: '<S86>/Linear extended state observer'
            // MATLAB Function 'ADRC controller/Linear extended state observer/Linear extended state observer': '<S89>:1' 
            // '<S89>:1:16'
            // '<S89>:1:10'
            if (*rtu_ParamADRC_hat_b == 0.0) {
                // '<S89>:1:22'
                // '<S89>:1:23'
                rtb_Sum1_idx_0 = 1.0;
            } else {
                // '<S89>:1:25'
                rtb_Sum1_idx_0 = *rtu_ParamADRC_hat_b;
            }

            // '<S89>:1:11'
            if (*rtu_ParamADRC_omega_o == 0.0) {
                // '<S89>:1:22'
                // '<S89>:1:23'
                rtb_Sum_k = 25.0;
            } else {
                // '<S89>:1:25'
                rtb_Sum_k = *rtu_ParamADRC_omega_o;
            }

            // '<S89>:1:13'
            // '<S89>:1:35'
            // '<S89>:1:14'
            // '<S89>:1:39'
            rtb_TmpSignalConversionAtSFunctionInport1[0] = 1.0;
            rtb_TmpSignalConversionAtSFunctionInport1[1] = rtb_Sum_k;
            rtb_TmpSignalConversionAtSFunctionInport1[2] = rtb_Sum_k * rtb_Sum_k;
            for (i = 1; static_cast<int32_T>(i + 1) > 1; i = static_cast<int32_T>
                    (i - 1)) {
                rtb_TmpSignalConversionAtSFunctionInport1[i] -=
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(i - 1)] * -rtb_Sum_k;
            }

            rtb_TmpSignalConversionAtSFunctionInport1[3] = rtb_Sum_k *
                rtb_TmpSignalConversionAtSFunctionInport1[2];
            for (i = 2; static_cast<int32_T>(i + 1) > 1; i = static_cast<int32_T>
                    (i - 1)) {
                rtb_TmpSignalConversionAtSFunctionInport1[i] -=
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(i - 1)] * -rtb_Sum_k;
            }

            // '<S89>:1:40'
            // '<S89>:1:16'
            rtb_Sum_k = localDW->Gain - localDW->Integrator[0];
            tmp[0] = 0.0 * localDW->Product;
            tmp[1] = -rtb_Sum1_idx_0 * localDW->Product;
            tmp[2] = 0.0 * localDW->Product;
            for (i = 0; i < 3; i++) {
                localDW->estimatedExtendedStateDerivative[i] =
                    (((static_cast<real_T>(a[static_cast<int32_T>(i + 3)]) *
                       localDW->Integrator[1] + 0.0 * localDW->Integrator[0]) +
                      static_cast<real_T>(a[static_cast<int32_T>(i + 6)]) *
                      localDW->Integrator[2]) + tmp[i]) +
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(i + 1)] * rtb_Sum_k;
            }

            // End of MATLAB Function: '<S86>/Linear extended state observer'
        }

        // End of Outputs for SubSystem: '<S74>/ADRC'

        // SignalConversion generated from: '<S74>/Vector Concatenate' incorporates:
        //   DataStoreWrite: '<S74>/WriteADRC_Log'

        localDW->ADRC_Log[0] = localDW->Integrator[0];
        localDW->ADRC_Log[1] = localDW->Integrator[1];
        localDW->ADRC_Log[2] = localDW->Integrator[2];
        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Outputs for Enabled SubSystem: '<S74>/PD' incorporates:
            //   EnablePort: '<S84>/Enable'

            if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
                if (localDW->EnablePD) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(localDW->PD_MODE) ^ 1))) {
                        // InitializeConditions for Delay: '<S123>/UD'
                        localDW->UD_DSTATE = 0.0;
                        localDW->PD_MODE = true;
                    }
                } else {
                    localDW->PD_MODE = false;
                }
            }

            if (localDW->PD_MODE) {
                // Product: '<S122>/DProd Out'
                rtb_Sum1_idx_0 = localDW->Gain * *rtu_ParamADRC_D;

                // SampleTimeMath: '<S125>/Tsamp'
                //
                //  About '<S125>/Tsamp':
                //   y = u * K where K = 1 / ( w * Ts )

                localDW->Tsamp = rtb_Sum1_idx_0 * 10.0;

                // Product: '<S135>/PProd Out'
                rtb_Sum1_idx_0 = localDW->Gain * *rtu_ParamADRC_P;

                // Sum: '<S139>/Sum' incorporates:
                //   Delay: '<S123>/UD'
                //   Sum: '<S123>/Diff'

                localDW->Sum = (localDW->Tsamp - localDW->UD_DSTATE) +
                    rtb_Sum1_idx_0;
            }

            // End of Outputs for SubSystem: '<S74>/PD'
        }

        // Switch: '<S74>/Switch'
        if (localDW->PD_U) {
            // Switch: '<S74>/Switch'
            localDW->Switch_p = localDW->Sum;
        } else {
            // Switch: '<S74>/Switch'
            localDW->Switch_p = localDW->Product;
        }

        // End of Switch: '<S74>/Switch'

        // SignalConversion generated from: '<S74>/Vector Concatenate' incorporates:
        //   DataStoreWrite: '<S74>/WriteADRC_Log'

        localDW->ADRC_Log[3] = localDW->Switch_p;
    }

    // End of Outputs for SubSystem: '<S67>/ADRC'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Sum: '<S76>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/FrontBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[108] -
            rtu_SimUAVState->North;

        // DotProduct: '<S76>/Dot Product'
        rtb_Sum_k = rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S76>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/FrontBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[325] - rtu_SimUAVState->East;

        // DotProduct: '<S76>/Dot Product'
        rtb_Sum_k += rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S76>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/FrontBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[542] -
            rtu_SimUAVState->Height;

        // Sqrt: '<S76>/sqrt' incorporates:
        //   DotProduct: '<S76>/Dot Product'

        rtb_Sum1_idx_0 = std::sqrt(rtb_Sum1_idx_0 * rtb_Sum1_idx_0 + rtb_Sum_k);

        // Sum: '<S67>/ActRngmMinRng'
        rtb_Switch_b -= rtb_Sum1_idx_0;

        // SignalConversion generated from: '<S67>/SimStateBus'
        localDW->AirSpeed = rtu_SimUAVState->AirSpeed;

        // Sum: '<S67>/RefRngmMinRng'
        rtb_RefRngmMinRng = rtb_Abs1 - rtb_Sum1_idx_0;

        // Sum: '<S67>/ComputeLB'
        rtb_LowerBound = rtb_Sum1_idx_0 - rtb_Abs1;

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/TailBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[12] - rtu_SimUAVState->North;

        // DotProduct: '<S77>/Dot Product'
        rtb_Sum_k = rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/TailBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[229] - rtu_SimUAVState->East;

        // DotProduct: '<S77>/Dot Product'
        rtb_Sum_k += rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/TailBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[446] -
            rtu_SimUAVState->Height;

        // Sum: '<S67>/ComputeUB' incorporates:
        //   DotProduct: '<S77>/Dot Product'
        //   Sqrt: '<S77>/sqrt'

        rtb_UpperBound = std::sqrt(rtb_Sum1_idx_0 * rtb_Sum1_idx_0 + rtb_Sum_k)
            - rtb_Abs1;

        // Outputs for Enabled SubSystem: '<S67>/EnableBias' incorporates:
        //   EnablePort: '<S75>/Enable'

        // Math: '<S67>/Square' incorporates:
        //   Math: '<S75>/Square'

        rtb_UpperBound_e = rtb_RefRngmMinRng * rtb_RefRngmMinRng;

        // End of Outputs for SubSystem: '<S67>/EnableBias'

        // Product: '<S67>/DivideLB' incorporates:
        //   Bias: '<S67>/Bias'
        //   Math: '<S67>/Square'

        rtb_Sum1_idx_0 = rtb_UpperBound_e / (rtb_RefRngmMinRng + 10.0);

        // Switch: '<S67>/Switch' incorporates:
        //   RelationalOperator: '<S67>/GreaterThanOrEqual'

        if (rtb_Switch_b >= rtb_Sum1_idx_0) {
            // Switch: '<S67>/Switch'
            Switch = rtb_Switch_b;
        } else {
            // Switch: '<S67>/Switch'
            Switch = rtb_Sum1_idx_0;
        }

        // End of Switch: '<S67>/Switch'

        // Outputs for Enabled SubSystem: '<S67>/EnableBias' incorporates:
        //   EnablePort: '<S75>/Enable'

        if (Switch > 0.0) {
            // Sum: '<S75>/biasHm70' incorporates:
            //   Product: '<S75>/Divide'

            localDW->biasHm70 = rtb_UpperBound_e / Switch - rtb_RefRngmMinRng;
        }

        // End of Outputs for SubSystem: '<S67>/EnableBias'

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/L1FrontBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[78] - rtu_SimUAVState->North;

        // DotProduct: '<S78>/Dot Product'
        rtb_Sum_k = rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/L1FrontBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[295] - rtu_SimUAVState->East;

        // DotProduct: '<S78>/Dot Product'
        rtb_Sum_k += rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/L1FrontBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[512] -
            rtu_SimUAVState->Height;

        // Sum: '<S67>/L1ComputeLB' incorporates:
        //   DotProduct: '<S78>/Dot Product'
        //   Sqrt: '<S78>/sqrt'

        Switch = std::sqrt(rtb_Sum1_idx_0 * rtb_Sum1_idx_0 + rtb_Sum_k) -
            rtb_Abs1;

        // Sum: '<S79>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/L1TailBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[42] - rtu_SimUAVState->North;

        // DotProduct: '<S79>/Dot Product'
        rtb_Sum_k = rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S79>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/L1TailBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[259] - rtu_SimUAVState->East;

        // DotProduct: '<S79>/Dot Product'
        rtb_Sum_k += rtb_Sum1_idx_0 * rtb_Sum1_idx_0;

        // Sum: '<S79>/Sum' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   Selector: '<S67>/L1TailBound'

        rtb_Sum1_idx_0 = localDW->MatrixConcatenate[476] -
            rtu_SimUAVState->Height;

        // Sum: '<S67>/L1ComputeUB' incorporates:
        //   DotProduct: '<S79>/Dot Product'
        //   Sqrt: '<S79>/sqrt'

        rtb_UpperBound_e = std::sqrt(rtb_Sum1_idx_0 * rtb_Sum1_idx_0 + rtb_Sum_k)
            - rtb_Abs1;

        // Outputs for Atomic SubSystem: '<S6>/MaxBrake'
        // Sum: '<S73>/Sum'
        rtb_SwitchLookAheadPoint[0] = rtu_SimUAVState->North -
            rtb_FixedWingGuidanceStateBus.North;
        rtb_SwitchLookAheadPoint[1] = rtu_SimUAVState->East -
            rtb_FixedWingGuidanceStateBus.East;
        rtb_SwitchLookAheadPoint[2] = rtu_SimUAVState->Height - rtb_Switch;

        // Outputs for Atomic SubSystem: '<S6>/HeadingLogic'
        // Outputs for Atomic SubSystem: '<S63>/NewMissionHdg'
        // Product: '<S65>/BrkRng' incorporates:
        //   Constant: '<S65>/SampleTime'
        //   Gain: '<S69>/Ts'

        rtb_Sum_k = rtu_SimUAVState->AirSpeed * 0.1;

        // End of Outputs for SubSystem: '<S63>/NewMissionHdg'
        // End of Outputs for SubSystem: '<S6>/HeadingLogic'

        // Sum: '<S65>/Minus' incorporates:
        //   Constant: '<S65>/TrackDP'
        //   DotProduct: '<S73>/Dot Product'
        //   Product: '<S65>/BrkRng'
        //   Sqrt: '<S73>/sqrt'

        rtb_Switch_b = std::sqrt((rtb_SwitchLookAheadPoint[0] *
            rtb_SwitchLookAheadPoint[0] + rtb_SwitchLookAheadPoint[1] *
            rtb_SwitchLookAheadPoint[1]) + rtb_SwitchLookAheadPoint[2] *
            rtb_SwitchLookAheadPoint[2]) - rtb_Sum_k * 132.0;

        // Gain: '<S65>/Gain'
        rtb_Gain_p = -rtb_Switch_b;

        // Switch: '<S65>/BrkSwitch' incorporates:
        //   Constant: '<S65>/MaxBrake'
        //   Sum: '<S67>/SumSpd'

        if (rtb_Switch_b >= 0.0) {
            rtb_RefRngmMinRng = (localDW->HeadWind + localDW->Switch_p) +
                localDW->AirSpeed;
        } else {
            rtb_RefRngmMinRng = 0.0;
        }

        // End of Switch: '<S65>/BrkSwitch'

        // Saturate: '<S65>/SpeedProtection'
        if (rtb_RefRngmMinRng > 46.0) {
            rtb_RefRngmMinRng = 46.0;
        } else if (rtb_RefRngmMinRng < 29.0) {
            rtb_RefRngmMinRng = 29.0;
        }

        // End of Saturate: '<S65>/SpeedProtection'
        // End of Outputs for SubSystem: '<S6>/MaxBrake'

        // Outputs for Atomic SubSystem: '<S6>/HeadingLogic'
        // Gain: '<S63>/LookaheadT'
        rtb_Switch_b = 3.6 * rtu_SimUAVState->AirSpeed;

        // SignalConversion generated from: '<S63>/TrackSimPath'
        rtb_TmpSignalConversionAtSFunctionInport1[0] =
            rtb_FixedWingGuidanceStateBus.North;
        rtb_TmpSignalConversionAtSFunctionInport1[1] =
            rtb_FixedWingGuidanceStateBus.East;
        rtb_TmpSignalConversionAtSFunctionInport1[2] = rtb_Switch;
        rtb_TmpSignalConversionAtSFunctionInport1[3] =
            rtb_FixedWingGuidanceStateBus.HeadingAngle;

        // MATLABSystem: '<S63>/TrackSimPath' incorporates:
        //   Concatenate: '<S62>/Matrix Concatenate'
        //   DataStoreWrite: '<S63>/WriteCrossTrackError'

        Real2SimGuidance_WaypointFollower_stepImpl(&localDW->obj,
            rtb_TmpSignalConversionAtSFunctionInport1,
            localDW->MatrixConcatenate, rtb_Switch_b, rtb_SwitchLookAheadPoint,
            &rtb_Abs1, &rtb_Sum1_idx_0, &b_varargout_4,
            &localDW->CrossTrackError, &b_varargout_6, localDW);

        // RelationalOperator: '<S63>/Relational Operator' incorporates:
        //   DataStoreWrite: '<S63>/WriteCrossTrackError'
        //   Gain: '<S63>/Gain'

        rtb_NoNewMission = (localDW->CrossTrackError <= 0.5 * rtb_Switch_b);

        // Outputs for Atomic SubSystem: '<S63>/NewMissionHdg'
        // Outputs for Enabled SubSystem: '<S69>/CalForwardShift' incorporates:
        //   EnablePort: '<S71>/Enable'

        if (rtu_SimUAVState->AirSpeed > 0.0) {
            // Saturate: '<S69>/Saturation'
            if (rtb_Gain_p <= 0.0) {
                rtb_Switch = 0.0;
            } else {
                rtb_Switch = rtb_Gain_p;
            }

            // End of Saturate: '<S69>/Saturation'

            // Gain: '<S71>/Gain' incorporates:
            //   Product: '<S71>/Divide'

            localDW->Gain_b = rtb_Switch / rtu_SimUAVState->AirSpeed * 10.0;
        }

        // End of Outputs for SubSystem: '<S69>/CalForwardShift'

        // RelationalOperator: '<S69>/GreaterThanOrEqual' incorporates:
        //   Constant: '<S69>/PenetrationDepthThreshold'
        //   Product: '<S69>/Product'

        rtb_GreaterThanOrEqual_h = (rtb_Gain_p >= rtb_Sum_k * 72.0);

        // Chart: '<S69>/MissionSwitchInitialPersuit'
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
            // Transition: '<S72>:14'
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S72>:12'
            localDW->SimHdg = 1.0;
        } else if (static_cast<int32_T>(localDW->is_c3_Real2SimGuidance) == 1) {
            // During 'Initial': '<S72>:12'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((localDW->temporalCounter_i1 >= 216U) &
                                        (static_cast<int32_T>(rtb_Memory) != 0))))
            {
                // Transition: '<S72>:15'
                localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Normal;

                // Entry Internal 'Normal': '<S72>:13'
                // Transition: '<S72>:53'
                localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                // Entry 'SimPnt': '<S72>:37'
                localDW->SimHdg = 1.0;
            } else {
                localDW->SimHdg = 1.0;
            }

            // During 'Normal': '<S72>:13'
        } else if (*rtu_NewMission) {
            // Transition: '<S72>:16'
            // Exit Internal 'Normal': '<S72>:13'
            // Exit Internal 'Debounce': '<S72>:38'
            localDW->is_Debounce_i = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S72>:12'
            localDW->SimHdg = 1.0;
        } else {
            switch (localDW->is_Normal) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S72>:38'
                if (static_cast<int32_T>(localDW->is_Debounce_i) == 1) {
                    // During 'L1Hdg': '<S72>:49'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                            10U) {
                        // Transition: '<S72>:46'
                        localDW->is_Debounce_i =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_Normal = Real2SimGuidance_IN_L1Hdg;

                        // Entry 'L1Hdg': '<S72>:42'
                        localDW->SimHdg = 0.0;
                    } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(static_cast<boolean_T>(
                                   static_cast<int32_T>(static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &
                                 static_cast<int32_T>(rtb_NoNewMission)))) {
                        // Transition: '<S72>:50'
                        localDW->is_Debounce_i = Real2SimGuidance_IN_SimPnt_g;
                        localDW->temporalCounter_i2 = 0U;
                    }

                    // During 'SimPnt': '<S72>:44'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                           10U) {
                    // Transition: '<S72>:48'
                    localDW->is_Debounce_i = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                    // Entry 'SimPnt': '<S72>:37'
                    localDW->SimHdg = 1.0;
                } else if (rtb_GreaterThanOrEqual_h) {
                    // Transition: '<S72>:51'
                    localDW->is_Debounce_i = Real2SimGuidance_IN_L1Hdg_b;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              case Real2SimGuidance_IN_L1Hdg:
                // During 'L1Hdg': '<S72>:42'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (static_cast<boolean_T>(static_cast<
                        int32_T>(static_cast<int32_T>(rtb_GreaterThanOrEqual_h) ^
                                 1))) & static_cast<int32_T>(rtb_NoNewMission))))
                {
                    // Transition: '<S72>:45'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce_i = Real2SimGuidance_IN_SimPnt_g;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              default:
                // During 'SimPnt': '<S72>:37'
                if (rtb_GreaterThanOrEqual_h) {
                    // Transition: '<S72>:47'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce_i = Real2SimGuidance_IN_L1Hdg_b;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;
            }
        }

        // End of Chart: '<S69>/MissionSwitchInitialPersuit'

        // DataTypeConversion: '<S69>/Cast' incorporates:
        //   DataStoreWrite: '<S63>/WriteStatus_Log'
        //   Logic: '<S69>/OR'
        //   MATLABSystem: '<S63>/TrackSimPath'

        localDW->HdgStatus_Log = static_cast<uint8_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
            (b_varargout_6) != 0) | (localDW->SimHdg != 0.0)))));

        // DiscreteIntegrator: '<S69>/Discrete-Time Integrator'
        if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                (localDW->DiscreteTimeIntegrator_PrevResetState) <= 0) &
                static_cast<int32_T>(*rtu_NewMission)))) {
            localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
        }

        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        } else if (localDW->DiscreteTimeIntegrator_DSTATE <= (rtMinusInf)) {
            localDW->DiscreteTimeIntegrator_DSTATE = (rtMinusInf);
        }

        // MinMax: '<S69>/Min' incorporates:
        //   Constant: '<S69>/NewestPoint'
        //   DiscreteIntegrator: '<S69>/Discrete-Time Integrator'
        //   Gain: '<S69>/Gain'
        //   Rounding: '<S69>/Round'
        //   Sum: '<S69>/Minus'

        rtb_Switch = std::fmin(217.0, std::round((217.0 -
            localDW->DiscreteTimeIntegrator_DSTATE) + 1.5 * localDW->Gain_b));

        // End of Outputs for SubSystem: '<S63>/NewMissionHdg'

        // Switch: '<S63>/SwitchLookAheadNED' incorporates:
        //   DataStoreWrite: '<S63>/WriteStatus_Log'
        //   Sum: '<S70>/EastArrow'
        //   Sum: '<S70>/NorthArrow'
        //   Switch: '<S63>/SwitchTargetHDG'
        //   Trigonometry: '<S70>/HdgCmd'

        if (static_cast<int32_T>(localDW->HdgStatus_Log) != 0) {
            // Selector: '<S63>/WayPoint3d3' incorporates:
            //   Concatenate: '<S62>/Matrix Concatenate'
            //   Sum: '<S70>/NorthArrow'

            rtb_Abs1 = localDW->MatrixConcatenate[static_cast<int32_T>(
                static_cast<int32_T>(rtb_Switch) - 1)];

            // Switch: '<S63>/SwitchLookAheadNED' incorporates:
            //   Selector: '<S63>/WayPoint3d3'

            localDW->SwitchLookAheadNED[0] = rtb_Abs1;

            // Selector: '<S63>/WayPoint3d3' incorporates:
            //   Concatenate: '<S62>/Matrix Concatenate'
            //   Sum: '<S70>/EastArrow'

            rtb_Switch_b = localDW->MatrixConcatenate[static_cast<int32_T>(
                static_cast<int32_T>(rtb_Switch) + 216)];

            // Switch: '<S63>/SwitchLookAheadNED' incorporates:
            //   Concatenate: '<S62>/Matrix Concatenate'
            //   Selector: '<S63>/WayPoint3d3'

            localDW->SwitchLookAheadNED[1] = rtb_Switch_b;
            localDW->SwitchLookAheadNED[2] = localDW->MatrixConcatenate[
                static_cast<int32_T>(static_cast<int32_T>(rtb_Switch) + 433)];
            rtb_Abs1 = rt_atan2d_snf(rtb_Switch_b -
                rtb_FixedWingGuidanceStateBus.East, rtb_Abs1 -
                rtb_FixedWingGuidanceStateBus.North);
        } else {
            // Switch: '<S63>/SwitchLookAheadNED' incorporates:
            //   MATLABSystem: '<S63>/TrackSimPath'

            localDW->SwitchLookAheadNED[0] = rtb_SwitchLookAheadPoint[0];
            localDW->SwitchLookAheadNED[1] = rtb_SwitchLookAheadPoint[1];
            localDW->SwitchLookAheadNED[2] = rtb_SwitchLookAheadPoint[2];
        }

        // End of Switch: '<S63>/SwitchLookAheadNED'
        // End of Outputs for SubSystem: '<S6>/HeadingLogic'

        // DataStoreWrite: '<S6>/WriteHeading_Log' incorporates:
        //   MATLAB Function: '<S6>/AngLog'

        // MATLAB Function 'Real2SimNav/AngLog': '<S58>:1'
        // '<S58>:1:2'
        // '<S58>:1:3'
        // '<S58>:1:4'
        localDW->Heading_Log[0] = angdiff_9SMt2WI9
            (rtb_FixedWingGuidanceStateBus.HeadingAngle, rtb_Abs1);
        localDW->Heading_Log[1] = angdiff_9SMt2WI9(0.0,
            rtb_FixedWingGuidanceStateBus.HeadingAngle);
        localDW->Heading_Log[2] = angdiff_9SMt2WI9(0.0, rtb_Abs1);
    }

    // End of Outputs for SubSystem: '<S6>/SpeedControl'

    // Integrator: '<S68>/TD_Alt' incorporates:
    //   DataStoreWrite: '<S6>/WritebiasH_Log'

    localDW->biasH_Log = localX->TD_Alt_CSTATE;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        boolean_T aVarTruthTableCondition_3;

        // Chart: '<S6>/Chart'
        // Gateway: Real2SimNav/Chart
        // During: Real2SimNav/Chart
        if (static_cast<uint32_T>(localDW->is_active_c2_Real2SimGuidance) == 0U)
        {
            // Entry: Real2SimNav/Chart
            localDW->is_active_c2_Real2SimGuidance = 1U;

            // Entry Internal: Real2SimNav/Chart
            // Transition: '<S59>:6'
            localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

            // Entry 'hasBias': '<S59>:5'
            // Switch: '<S6>/BiasHSwitch' incorporates:
            //   Gain: '<S6>/Gain'
            //   Product: '<S6>/Product'

            localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
        } else if (static_cast<int32_T>(localDW->is_c2_Real2SimGuidance) == 1) {
            // During 'NoBias': '<S59>:7'
            if (*rtu_NewMission) {
                // Transition: '<S59>:9'
                localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

                // Entry 'hasBias': '<S59>:5'
                // Switch: '<S6>/BiasHSwitch' incorporates:
                //   Gain: '<S6>/Gain'
                //   Product: '<S6>/Product'

                localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
            } else {
                // Switch: '<S6>/BiasHSwitch' incorporates:
                //   Constant: '<S6>/ZeroBias'

                localDW->BiasHSwitch = 0.0;
            }

            // During 'hasBias': '<S59>:5'
        } else if (localDW->EngagedFlag > 1.0) {
            // Transition: '<S59>:8'
            localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NoBias;

            // Entry 'NoBias': '<S59>:7'
            // Switch: '<S6>/BiasHSwitch' incorporates:
            //   Constant: '<S6>/ZeroBias'

            localDW->BiasHSwitch = 0.0;
        } else {
            // Switch: '<S6>/BiasHSwitch' incorporates:
            //   Gain: '<S6>/Gain'
            //   Product: '<S6>/Product'

            localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
        }

        // End of Chart: '<S6>/Chart'

        // RelationalOperator: '<S60>/Compare' incorporates:
        //   Constant: '<S60>/Constant'

        localDW->Compare = (rtb_Gain_p < 0.0);

        // Truth Table: '<S6>/Engagement' incorporates:
        //   DataStoreRead: '<S6>/ReadLagDistance'
        //   DataStoreWrite: '<S63>/WriteCrossTrackError'

        // Truth Table Function 'Real2SimNav/Engagement': '<S61>:1'
        //  Front Distance within L1 Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_UpperBound_e) & (localDW->LagDistance > Switch)))) {
            // Condition '#1': '<S61>:1:10'
            rtb_NoNewMission = true;
        } else {
            rtb_NoNewMission = false;
        }

        //  Front Distance within L0 Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_UpperBound) & (localDW->LagDistance > rtb_LowerBound)))) {
            // Condition '#2': '<S61>:1:14'
            rtb_GreaterThanOrEqual_h = true;
        } else {
            rtb_GreaterThanOrEqual_h = false;
        }

        //  CrossTrack Error within 1.5 Second Bound
        // Condition '#3': '<S61>:1:18'
        aVarTruthTableCondition_3 = (localDW->CrossTrackError <
            localDW->AirSpeed * 72.0 * 0.1 / 5.0);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rtb_NoNewMission) & static_cast<int32_T>
                (aVarTruthTableCondition_3)))) {
            // Decision 'D1': '<S61>:1:20'
            //  Real UAV Deeply Engaged with Simulation UAV
            // Action '1': '<S61>:1:32'
            localDW->Engaged = 2U;
        } else if (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(rtb_GreaterThanOrEqual_h) &
                     static_cast<int32_T>(aVarTruthTableCondition_3)))) {
            // Decision 'D2': '<S61>:1:22'
            //  Real UAV Engaged with Simulation UAV
            // Action '2': '<S61>:1:38'
            localDW->Engaged = 1U;
        } else {
            // Decision 'D3': '<S61>:1:24'
            //  Default
            //  Real UAV Not Engaged with Simulation UAV
            // Action '3': '<S61>:1:44'
            localDW->Engaged = 0U;
        }

        // End of Truth Table: '<S6>/Engagement'

        // ZeroOrderHold: '<S6>/LookaheadPoint_ZOH' incorporates:
        //   DataStoreWrite: '<S6>/WritebiasH_Log'
        //   Sum: '<S6>/SumBiasH'
        //   Switch: '<S63>/SwitchLookAheadNED'

        rtb_RealUAVNEUState_idx_0 = localDW->SwitchLookAheadNED[0];
        rtb_RealUAVNEUState_idx_1 = localDW->SwitchLookAheadNED[1];
        rtb_RealUAVNEUState_idx_2 = localDW->SwitchLookAheadNED[2] +
            localDW->biasH_Log;
    }

    // Integrator: '<S68>/dotAltTD'
    localDW->dotAltTD = localX->dotAltTD_CSTATE;

    // MATLAB Function: '<S68>/fhan_Alt' incorporates:
    //   DataStoreWrite: '<S6>/WritebiasH_Log'
    //   SignalConversion generated from: '<S147>/ SFunction '
    //   Sum: '<S68>/Sum1'

    // MATLAB Function 'Real2SimNav/TD/fhan_Alt': '<S147>:1'
    // '<S147>:1:3'
    // '<S147>:1:4'
    // '<S147>:1:5'
    // '<S147>:1:6'
    // '<S147>:1:8'
    // '<S147>:1:9'
    Switch = localDW->dotAltTD * 0.1;

    // '<S147>:1:10'
    rtb_LowerBound = (localDW->biasH_Log - localDW->BiasHSwitch) + Switch;

    // '<S147>:1:11'
    // '<S147>:1:12'
    if (rtb_LowerBound < 0.0) {
        rtb_UpperBound = -1.0;
    } else if (rtb_LowerBound > 0.0) {
        rtb_UpperBound = 1.0;
    } else if (rtb_LowerBound == 0.0) {
        rtb_UpperBound = 0.0;
    } else {
        rtb_UpperBound = (rtNaN);
    }

    rtb_UpperBound_e = (std::sqrt((8.0 * std::abs(rtb_LowerBound) +
                          0.004000000000000001) * 0.004000000000000001) -
                        0.004000000000000001) * rtb_UpperBound / 2.0 + Switch;

    // '<S147>:1:13'
    // '<S147>:1:14'
    if (rtb_LowerBound + 0.004000000000000001 < 0.0) {
        rtb_UpperBound = -1.0;
    } else if (rtb_LowerBound + 0.004000000000000001 > 0.0) {
        rtb_UpperBound = 1.0;
    } else if (rtb_LowerBound + 0.004000000000000001 == 0.0) {
        rtb_UpperBound = 0.0;
    } else {
        rtb_UpperBound = (rtNaN);
    }

    if (rtb_LowerBound - 0.004000000000000001 < 0.0) {
        rtb_Gain_p = -1.0;
    } else if (rtb_LowerBound - 0.004000000000000001 > 0.0) {
        rtb_Gain_p = 1.0;
    } else if (rtb_LowerBound - 0.004000000000000001 == 0.0) {
        rtb_Gain_p = 0.0;
    } else {
        rtb_Gain_p = (rtNaN);
    }

    rtb_LowerBound = ((Switch + rtb_LowerBound) - rtb_UpperBound_e) *
        ((rtb_UpperBound - rtb_Gain_p) / 2.0) + rtb_UpperBound_e;

    // '<S147>:1:15'
    // '<S147>:1:17'
    if (rtb_LowerBound < 0.0) {
        Switch = -1.0;
    } else if (rtb_LowerBound > 0.0) {
        Switch = 1.0;
    } else if (rtb_LowerBound == 0.0) {
        Switch = 0.0;
    } else {
        Switch = (rtNaN);
    }

    if (rtb_LowerBound + 0.004000000000000001 < 0.0) {
        rtb_UpperBound = -1.0;
    } else if (rtb_LowerBound + 0.004000000000000001 > 0.0) {
        rtb_UpperBound = 1.0;
    } else if (rtb_LowerBound + 0.004000000000000001 == 0.0) {
        rtb_UpperBound = 0.0;
    } else {
        rtb_UpperBound = (rtNaN);
    }

    if (rtb_LowerBound - 0.004000000000000001 < 0.0) {
        rtb_Gain_p = -1.0;
    } else if (rtb_LowerBound - 0.004000000000000001 > 0.0) {
        rtb_Gain_p = 1.0;
    } else if (rtb_LowerBound - 0.004000000000000001 == 0.0) {
        rtb_Gain_p = 0.0;
    } else {
        rtb_Gain_p = (rtNaN);
    }

    localDW->fh = (rtb_LowerBound / 0.004000000000000001 - Switch) * -0.4 *
        ((rtb_UpperBound - rtb_Gain_p) / 2.0) - 0.4 * Switch;

    // End of MATLAB Function: '<S68>/fhan_Alt'
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
            // Transition: '<S7>:3'
            localDW->durationCounter_1 = 0;
            localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NotTakeOff;

            // Entry 'NotTakeOff': '<S7>:2'
            rtb_NoNewMission = false;
        } else if (static_cast<int32_T>(localDW->is_c16_Real2SimGuidance) == 1)
        {
            // During 'InAir': '<S7>:4'
            rtb_NoNewMission = true;
        } else {
            // During 'NotTakeOff': '<S7>:2'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    ((rtb_FixedWingGuidanceStateBus.AirSpeed > 15.0) ^ 1))) |
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>
                     ((rtu_StateFCU->RealUAVState.Height_meter > 30.0) ^ 1))))))
            {
                localDW->durationCounter_1 = 0;
            } else {
                // '<S7>:5:1'
            }

            if (localDW->durationCounter_1 > 10) {
                // Transition: '<S7>:5'
                localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_InAir;

                // Entry 'InAir': '<S7>:4'
                rtb_NoNewMission = true;
            } else {
                rtb_NoNewMission = false;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((rtb_FixedWingGuidanceStateBus.AirSpeed >
                15.0) & (rtu_StateFCU->RealUAVState.Height_meter > 30.0)))) {
            // '<S7>:5:1'
            localDW->durationCounter_1 = static_cast<int32_T>
                (localDW->durationCounter_1 + 1);
        } else {
            localDW->durationCounter_1 = 0;
        }

        // End of Chart: '<Root>/TASgreaterthan15for1Sec'

        // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
        //   EnablePort: '<S1>/Enable'

        if (rtb_NoNewMission) {
            // Inport: '<S1>/InPlace'
            *rty_EngagedFlag = localDW->Engaged;
        }

        // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'

        // Chart: '<Root>/EngagementDebouncer'
        if (static_cast<uint32_T>(localDW->temporalCounter_i1_o) < 1023U) {
            localDW->temporalCounter_i1_o = static_cast<uint16_T>(static_cast<
                uint32_T>(static_cast<uint32_T>(localDW->temporalCounter_i1_o) +
                          1U));
        }

        if (static_cast<uint32_T>(localDW->temporalCounter_i2_n) < 63U) {
            localDW->temporalCounter_i2_n = static_cast<uint8_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i2_n) + 1U));
        }

        // Gateway: EngagementDebouncer
        // During: EngagementDebouncer
        if (static_cast<uint32_T>(localDW->is_active_c34_Real2SimGuidance) == 0U)
        {
            // Entry: EngagementDebouncer
            localDW->is_active_c34_Real2SimGuidance = 1U;

            // Entry Internal: EngagementDebouncer
            // Transition: '<S2>:97'
            localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_Persuit;

            // Entry 'Persuit': '<S2>:95'
            localDW->Execution = 0.0;

            // Entry Internal 'Persuit': '<S2>:95'
            // Transition: '<S2>:100'
            localDW->is_Persuit = Real2SimGuidance_IN_Normal;
        } else {
            switch (localDW->is_c34_Real2SimGuidance) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S2>:90'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_o) >= 180U)
                {
                    // Transition: '<S2>:93'
                    // Exit Internal 'Debounce': '<S2>:90'
                    localDW->is_Debounce_id =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Persuit;

                    // Entry 'Persuit': '<S2>:95'
                    localDW->Execution = 0.0;
                    localDW->is_Persuit = Real2SimGuidance_IN_Fault;
                    localDW->temporalCounter_i1_o = 0U;

                    // Entry 'Fault': '<S2>:94'
                } else if (static_cast<int32_T>(localDW->is_Debounce_id) == 1) {
                    // During 'Off': '<S2>:103'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2_n) >=
                            40U) {
                        // Transition: '<S2>:87'
                        localDW->is_Debounce_id =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_c34_Real2SimGuidance =
                            Real2SimGuidance_IN_Persuit;

                        // Entry 'Persuit': '<S2>:95'
                        localDW->Execution = 0.0;

                        // Entry Internal 'Persuit': '<S2>:95'
                        // Transition: '<S2>:100'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    } else if (static_cast<int32_T>(*rty_EngagedFlag) > 0) {
                        // Transition: '<S2>:102'
                        localDW->is_Debounce_id = Real2SimGuidance_IN_On;
                        localDW->temporalCounter_i2_n = 0U;
                    }

                    // During 'On': '<S2>:92'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2_n) >=
                           40U) {
                    // Transition: '<S2>:99'
                    localDW->is_Debounce_id =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_L0Engaged;

                    // Entry Internal 'L0Engaged': '<S2>:101'
                    // Transition: '<S2>:120'
                    localDW->is_L0Engaged = Real2SimGuidance_IN_L0Default;

                    // Entry 'L0Default': '<S2>:106'
                    localDW->Execution = 1.0;

                    // Entry Internal 'L0Default': '<S2>:106'
                    // Transition: '<S2>:108'
                    localDW->is_L0Default = Real2SimGuidance_IN_Normal;
                } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S2>:96'
                    localDW->is_Debounce_id = Real2SimGuidance_IN_Off;
                    localDW->temporalCounter_i2_n = 0U;
                }
                break;

              case Real2SimGuidance_IN_L0Engaged:
                // During 'L0Engaged': '<S2>:101'
                if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S2>:91'
                    // Exit Internal 'L0Engaged': '<S2>:101'
                    // Exit Internal 'Debounce': '<S2>:111'
                    localDW->is_Debounce_a = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

                    // Exit Internal 'L0Default': '<S2>:106'
                    localDW->is_L0Default = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_L0Engaged = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_o = 0U;
                    localDW->is_Debounce_id = Real2SimGuidance_IN_Off;
                    localDW->temporalCounter_i2_n = 0U;
                } else {
                    switch (localDW->is_L0Engaged) {
                      case Real2SimGuidance_IN_Debounce:
                        // During 'Debounce': '<S2>:111'
                        if (static_cast<uint32_T>(localDW->temporalCounter_i1_o)
                            >= 60U) {
                            // Transition: '<S2>:119'
                            // Exit Internal 'Debounce': '<S2>:111'
                            localDW->is_Debounce_a =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged =
                                Real2SimGuidance_IN_L0Default;

                            // Entry 'L0Default': '<S2>:106'
                            localDW->Execution = 1.0;
                            localDW->is_L0Default = Real2SimGuidance_IN_Fault;
                            localDW->temporalCounter_i1_o = 0U;

                            // Entry 'Fault': '<S2>:109'
                        } else if (static_cast<int32_T>(localDW->is_Debounce_a) ==
                                   1) {
                            // During 'Off': '<S2>:114'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i2_n) >= 30U) {
                                // Transition: '<S2>:122'
                                localDW->is_Debounce_a =
                                    Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                                localDW->is_L0Engaged =
                                    Real2SimGuidance_IN_L0Default;

                                // Entry 'L0Default': '<S2>:106'
                                localDW->Execution = 1.0;

                                // Entry Internal 'L0Default': '<S2>:106'
                                // Transition: '<S2>:108'
                                localDW->is_L0Default =
                                    Real2SimGuidance_IN_Normal;
                            } else if (static_cast<int32_T>(*rty_EngagedFlag) >
                                       1) {
                                // Transition: '<S2>:115'
                                localDW->is_Debounce_a = Real2SimGuidance_IN_On;
                                localDW->temporalCounter_i2_n = 0U;
                            }

                            // During 'On': '<S2>:113'
                        } else if (static_cast<uint32_T>
                                   (localDW->temporalCounter_i2_n) >= 30U) {
                            // Transition: '<S2>:118'
                            localDW->is_Debounce_a =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged =
                                Real2SimGuidance_IN_L1Engaged;

                            // Entry 'L1Engaged': '<S2>:112'
                            localDW->Execution = 2.0;
                        } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 1)
                        {
                            // Transition: '<S2>:116'
                            localDW->is_Debounce_a = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_n = 0U;
                        }
                        break;

                      case Real2SimGuidance_IN_L0Default:
                        localDW->Execution = 1.0;

                        // During 'L0Default': '<S2>:106'
                        if (static_cast<int32_T>(localDW->is_L0Default) == 1) {
                            // During 'Fault': '<S2>:109'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i1_o) >= 600U) {
                                // Transition: '<S2>:107'
                                localDW->is_L0Default =
                                    Real2SimGuidance_IN_Normal;
                            }

                            // During 'Normal': '<S2>:110'
                        } else if (static_cast<int32_T>(*rty_EngagedFlag) > 1) {
                            // Transition: '<S2>:117'
                            localDW->is_L0Default =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged = Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1_o = 0U;
                            localDW->is_Debounce_a = Real2SimGuidance_IN_On;
                            localDW->temporalCounter_i2_n = 0U;
                        }
                        break;

                      default:
                        localDW->Execution = 2.0;

                        // During 'L1Engaged': '<S2>:112'
                        if (static_cast<int32_T>(*rty_EngagedFlag) <= 1) {
                            // Transition: '<S2>:121'
                            localDW->is_L0Engaged = Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1_o = 0U;
                            localDW->is_Debounce_a = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_n = 0U;
                        }
                        break;
                    }
                }
                break;

              default:
                localDW->Execution = 0.0;

                // During 'Persuit': '<S2>:95'
                if (static_cast<int32_T>(localDW->is_Persuit) == 1) {
                    // During 'Fault': '<S2>:94'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i1_o) >=
                            600U) {
                        // Transition: '<S2>:89'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    }

                    // During 'Normal': '<S2>:88'
                } else if (static_cast<boolean_T>(static_cast<int32_T>((
                              static_cast<int32_T>(*rty_EngagedFlag) > 0) &
                             static_cast<int32_T>(rtb_NoNewMission)))) {
                    // Transition: '<S2>:98'
                    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_o = 0U;
                    localDW->is_Debounce_id = Real2SimGuidance_IN_On;
                    localDW->temporalCounter_i2_n = 0U;
                }
                break;
            }
        }

        // End of Chart: '<Root>/EngagementDebouncer'

        // DataStoreWrite: '<Root>/WriteEngagedFlag_Log'
        localDW->EngagedFlag = localDW->Execution;

        // Product: '<Root>/Product' incorporates:
        //   DataStoreWrite: '<Root>/WriteFlightMode_Log'
        //   DataTypeConversion: '<Root>/Cast To Double'
        //   Logic: '<Root>/NOT'
        //   Logic: '<Root>/NoNewMission'

        localDW->FlightMode_Log = (static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(*rtu_NewMission) ^ 1)) ? static_cast<real_T>
            (*rtu_FlightMode) : 0.0) * static_cast<real_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (rtu_ControlSwitch[1]) ^ 1))));

        // BusCreator: '<Root>/CreatADRC' incorporates:
        //   DataStoreRead: '<Root>/ReadADRC_Log'

        rty_FlightLogging->ADRC_Log.x1_ControlError = localDW->ADRC_Log[0];
        rty_FlightLogging->ADRC_Log.x2 = localDW->ADRC_Log[1];
        rty_FlightLogging->ADRC_Log.x3_TotalDisturbance = localDW->ADRC_Log[2];
        rty_FlightLogging->ADRC_Log.u = localDW->ADRC_Log[3];

        // Switch: '<Root>/SwitchLookAheadPoint' incorporates:
        //   ZeroOrderHold: '<S6>/LookaheadPoint_ZOH'

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

        // Switch: '<S49>/Switch' incorporates:
        //   Abs: '<S49>/Abs'
        //   Bias: '<S49>/Bias'
        //   Bias: '<S49>/Bias1'
        //   Constant: '<S49>/Constant2'
        //   Constant: '<S50>/Constant'
        //   DataStoreRead: '<S5>/LatitudeGCS'
        //   Math: '<S49>/Math Function1'
        //   RelationalOperator: '<S50>/Compare'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Sum1_idx_0 = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
            rtb_Sum1_idx_0 = LatitudeGCS;
        }

        // End of Switch: '<S49>/Switch'

        // Abs: '<S46>/Abs1'
        rtb_LowerBound = std::abs(rtb_Sum1_idx_0);

        // Switch: '<S46>/Switch' incorporates:
        //   Bias: '<S46>/Bias'
        //   Bias: '<S46>/Bias1'
        //   Constant: '<S37>/Constant'
        //   Constant: '<S37>/Constant1'
        //   Constant: '<S48>/Constant'
        //   Gain: '<S46>/Gain'
        //   Product: '<S46>/Divide1'
        //   RelationalOperator: '<S48>/Compare'
        //   Switch: '<S37>/Switch1'

        if (rtb_LowerBound > 90.0) {
            // Signum: '<S46>/Sign1'
            if (rtb_Sum1_idx_0 < 0.0) {
                rtb_Sum1_idx_0 = -1.0;
            } else if (rtb_Sum1_idx_0 > 0.0) {
                rtb_Sum1_idx_0 = 1.0;
            } else if (rtb_Sum1_idx_0 == 0.0) {
                rtb_Sum1_idx_0 = 0.0;
            } else {
                rtb_Sum1_idx_0 = (rtNaN);
            }

            // End of Signum: '<S46>/Sign1'
            rtb_Sum1_idx_0 *= -(rtb_LowerBound + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S46>/Switch'

        // UnitConversion: '<S54>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum_k = 0.017453292519943295 * rtb_Sum1_idx_0;

        // Trigonometry: '<S55>/Trigonometric Function1'
        rtb_Switch_b = std::sin(rtb_Sum_k);

        // Sum: '<S55>/Sum1' incorporates:
        //   Constant: '<S55>/Constant'
        //   Product: '<S55>/Product1'

        rtb_Switch_b = 1.0 - 0.0066943799901413295 * rtb_Switch_b * rtb_Switch_b;

        // Product: '<S52>/Product1' incorporates:
        //   Constant: '<S52>/Constant1'
        //   Sqrt: '<S52>/sqrt'

        rtb_Switch = 6.378137E+6 / std::sqrt(rtb_Switch_b);

        // Sum: '<S37>/Sum' incorporates:
        //   DataStoreRead: '<S5>/LongitudeGCS'

        // Unit Conversion - from: rad to: deg
        // Expression: output = (57.2958*input) + (0)
        rtb_Abs1 = static_cast<real_T>(i) + LongitudeGCS;

        // Switch: '<S47>/Switch' incorporates:
        //   Abs: '<S47>/Abs'
        //   Bias: '<S47>/Bias'
        //   Bias: '<S47>/Bias1'
        //   Constant: '<S47>/Constant2'
        //   Constant: '<S51>/Constant'
        //   Math: '<S47>/Math Function1'
        //   RelationalOperator: '<S51>/Compare'

        if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S47>/Switch'

        // Sum: '<S35>/Sum' incorporates:
        //   Constant: '<S52>/Constant2'
        //   Constant: '<S52>/Constant3'
        //   Product: '<S38>/rad lat'
        //   Product: '<S38>/rad long '
        //   Product: '<S38>/x*cos'
        //   Product: '<S38>/x*sin'
        //   Product: '<S38>/y*cos'
        //   Product: '<S38>/y*sin'
        //   Product: '<S52>/Product3'
        //   Product: '<S52>/Product4'
        //   Sum: '<S38>/Sum'
        //   Sum: '<S38>/Sum1'
        //   Trigonometry: '<S52>/Trigonometric Function'
        //   Trigonometry: '<S52>/Trigonometric Function1'
        //   Trigonometry: '<S52>/Trigonometric Function2'
        //   UnitConversion: '<S39>/Unit Conversion'

        rtb_Sum1_idx_0 += (rtb_SwitchLookAheadPoint[0] -
                           rtb_SwitchLookAheadPoint[1] * 0.0) * rt_atan2d_snf
            (1.0, rtb_Switch * 0.99330562000985867 / rtb_Switch_b) *
            57.295779513082323;
        rtb_Sum1_idx_1 = (rtb_SwitchLookAheadPoint[0] * 0.0 +
                          rtb_SwitchLookAheadPoint[1]) * rt_atan2d_snf(1.0,
            rtb_Switch * std::cos(rtb_Sum_k)) * 57.295779513082323 + rtb_Abs1;

        // Switch: '<S43>/Switch' incorporates:
        //   Abs: '<S43>/Abs'
        //   Bias: '<S43>/Bias'
        //   Bias: '<S43>/Bias1'
        //   Constant: '<S43>/Constant2'
        //   Constant: '<S44>/Constant'
        //   Math: '<S43>/Math Function1'
        //   RelationalOperator: '<S44>/Compare'

        if (std::abs(rtb_Sum1_idx_0) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Abs1 = rtb_Sum1_idx_0;
        }

        // End of Switch: '<S43>/Switch'

        // Abs: '<S40>/Abs1'
        rtb_LowerBound = std::abs(rtb_Abs1);

        // Switch: '<S40>/Switch' incorporates:
        //   Bias: '<S40>/Bias'
        //   Bias: '<S40>/Bias1'
        //   Constant: '<S36>/Constant'
        //   Constant: '<S36>/Constant1'
        //   Constant: '<S42>/Constant'
        //   Gain: '<S40>/Gain'
        //   Product: '<S40>/Divide1'
        //   RelationalOperator: '<S42>/Compare'
        //   Switch: '<S36>/Switch1'

        if (rtb_LowerBound > 90.0) {
            // Signum: '<S40>/Sign1'
            if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
            } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
            } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
            } else {
                rtb_Abs1 = (rtNaN);
            }

            // End of Signum: '<S40>/Sign1'
            rtb_Abs1 *= -(rtb_LowerBound + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S40>/Switch'

        // Sum: '<S36>/Sum'
        rtb_Switch_b = static_cast<real_T>(i) + rtb_Sum1_idx_1;

        // Switch: '<S41>/Switch' incorporates:
        //   Abs: '<S41>/Abs'
        //   Bias: '<S41>/Bias'
        //   Bias: '<S41>/Bias1'
        //   Constant: '<S41>/Constant2'
        //   Constant: '<S45>/Constant'
        //   Math: '<S41>/Math Function1'
        //   RelationalOperator: '<S45>/Compare'

        if (std::abs(rtb_Switch_b) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Switch_b + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S41>/Switch'

        // Sum: '<S35>/Sum1' incorporates:
        //   DataStoreRead: '<S5>/AltitudeGCS'
        //   Gain: '<S5>/Up2Down'
        //   Gain: '<S5>/inverse'

        rty_FCUCMD->Height_meter = rtb_SwitchLookAheadPoint[2] - (-AltitudeGCS);

        // BusCreator: '<Root>/FcuCmdBus'
        rty_FCUCMD->Latitude_deg = rtb_Abs1;
        rty_FCUCMD->Longitude_deg = rtb_Switch_b;

        // Switch: '<Root>/SwitchSpdControl'
        if (rtu_ControlSwitch[1]) {
            // BusCreator: '<Root>/FcuCmdBus'
            rty_FCUCMD->RefAirSpd_mps = rtu_ImmedGuidanceCMD->AirSpeed;
        } else {
            // BusCreator: '<Root>/FcuCmdBus'
            rty_FCUCMD->RefAirSpd_mps = rtb_RefRngmMinRng;
        }

        // End of Switch: '<Root>/SwitchSpdControl'

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
        //   Trigonometry: '<S3>/Atan2'

        rty_FlightLogging->MiscStatus.GroundSpeed = rtu_StateFCU->GndSpd_mps;
        rty_FlightLogging->MiscStatus.Altitude = rtu_StateFCU->Altitude;
        rty_FlightLogging->MiscStatus.FlightPath = rt_atan2d_snf
            (rtu_StateFCU->VecSpd.skySpeed, rtu_StateFCU->GndSpd_mps);

        // MATLAB Function: '<Root>/TimeNow'
        // MATLAB Function 'TimeNow': '<S8>:1'
        // '<S8>:1:3'
        Real2SimGuidance_getLocalTime(&rtb_RefRngmMinRng, &rtb_LowerBound,
            &rtb_RealUAVNEUState_idx_0, &Switch, &rtb_UpperBound_e, &rtb_Gain_p,
            &rtb_Abs1, &rtb_NoNewMission);
        rtb_RealUAVNEUState_idx_1 = Switch;
        rtb_RealUAVNEUState_idx_2 = rtb_LowerBound;
        rtb_Switch = rtb_RefRngmMinRng / 1.0E+6;
        rtb_RefRngmMinRng = rtb_LowerBound;
        rtb_UpperBound = rtb_Switch;
        rtb_LowerBound = (((((rtb_Abs1 + rtb_Gain_p) + rtb_UpperBound_e) +
                            Switch) + rtb_RealUAVNEUState_idx_0) +
                          rtb_LowerBound) + rtb_Switch;
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(rtb_LowerBound)) ^ 1))) & static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(rtb_LowerBound)) ^ 1)))))) {
            rtb_LowerBound = rtb_Abs1;
            Switch = rtb_Gain_p;
            if ((rtb_Gain_p < 1.0) || (rtb_Gain_p > 12.0)) {
                Switch = std::floor((rtb_Gain_p - 1.0) / 12.0);
                rtb_LowerBound = rtb_Abs1 + Switch;
                Switch = ((rtb_Gain_p - 1.0) - Switch * 12.0) + 1.0;
            }

            if (Switch < 3.0) {
                rtb_LowerBound--;
                Switch += 9.0;
            } else {
                Switch -= 3.0;
            }

            if ((rtb_Switch < 0.0) || (1000.0 <= rtb_Switch)) {
                rtb_UpperBound = std::floor(rtb_Switch / 1000.0);
                rtb_RefRngmMinRng = rtb_RealUAVNEUState_idx_2 + rtb_UpperBound;
                rtb_UpperBound = rtb_Switch - rtb_UpperBound * 1000.0;
            }

            inputArg_data.re = ((((((365.0 * rtb_LowerBound + std::floor
                (rtb_LowerBound / 4.0)) - std::floor(rtb_LowerBound / 100.0)) +
                                   std::floor(rtb_LowerBound / 400.0)) + std::
                                  floor((153.0 * Switch + 2.0) / 5.0)) +
                                 rtb_UpperBound_e) + 60.0) - 719529.0;
            inputArg_data.im = 0.0;
            inputArg_data = Real2SimGuidance_plus(Real2SimGuidance_plus
                (Real2SimGuidance_plus(Real2SimGuidance_times(inputArg_data),
                (60.0 * rtb_RealUAVNEUState_idx_1 + rtb_RealUAVNEUState_idx_0) *
                60000.0), rtb_RefRngmMinRng * 1000.0), rtb_UpperBound);
        } else {
            inputArg_data.re = rtb_LowerBound;
            inputArg_data.im = 0.0;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_RefRngmMinRng,
            &rtb_LowerBound, &rtb_UpperBound, &Switch, &rtb_UpperBound_e,
            &rtb_Gain_p);
        rtb_RefRngmMinRng = std::round(rtb_RefRngmMinRng);
        if (rtb_RefRngmMinRng < 2.147483648E+9) {
            if (rtb_RefRngmMinRng >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.year = static_cast<int32_T>
                    (rtb_RefRngmMinRng);
            } else {
                rty_FlightLogging->TimeNow.year = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.year = MAX_int32_T;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_RefRngmMinRng,
            &rtb_LowerBound, &rtb_UpperBound, &Switch, &rtb_UpperBound_e,
            &rtb_Gain_p);
        rtb_RefRngmMinRng = std::round(rtb_LowerBound);
        if (rtb_RefRngmMinRng < 2.147483648E+9) {
            if (rtb_RefRngmMinRng >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.month = static_cast<int32_T>
                    (rtb_RefRngmMinRng);
            } else {
                rty_FlightLogging->TimeNow.month = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.month = MAX_int32_T;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_RefRngmMinRng,
            &rtb_LowerBound, &rtb_UpperBound, &Switch, &rtb_UpperBound_e,
            &rtb_Gain_p);
        rtb_RefRngmMinRng = std::round(rtb_UpperBound);
        if (rtb_RefRngmMinRng < 2.147483648E+9) {
            if (rtb_RefRngmMinRng >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.day = static_cast<int32_T>
                    (rtb_RefRngmMinRng);
            } else {
                rty_FlightLogging->TimeNow.day = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.day = MAX_int32_T;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_RefRngmMinRng,
            &rtb_LowerBound, &rtb_UpperBound, &Switch, &rtb_UpperBound_e,
            &rtb_Gain_p);
        rtb_RefRngmMinRng = std::round(Switch);
        if (rtb_RefRngmMinRng < 2.147483648E+9) {
            if (rtb_RefRngmMinRng >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.hour = static_cast<int32_T>
                    (rtb_RefRngmMinRng);
            } else {
                rty_FlightLogging->TimeNow.hour = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.hour = MAX_int32_T;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_RefRngmMinRng,
            &rtb_LowerBound, &rtb_UpperBound, &Switch, &rtb_UpperBound_e,
            &rtb_Gain_p);
        rtb_RefRngmMinRng = std::round(rtb_UpperBound_e);
        if (rtb_RefRngmMinRng < 2.147483648E+9) {
            if (rtb_RefRngmMinRng >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.minute = static_cast<int32_T>
                    (rtb_RefRngmMinRng);
            } else {
                rty_FlightLogging->TimeNow.minute = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.minute = MAX_int32_T;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_RefRngmMinRng,
            &rtb_LowerBound, &rtb_UpperBound, &Switch, &rtb_UpperBound_e,
            &rtb_Gain_p);
        rtb_RefRngmMinRng = std::floor(rtb_Gain_p);
        if (rtb_RefRngmMinRng < 2.147483648E+9) {
            if (rtb_RefRngmMinRng >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.second = static_cast<int32_T>
                    (rtb_RefRngmMinRng);
            } else {
                rty_FlightLogging->TimeNow.second = MIN_int32_T;
            }
        } else {
            rty_FlightLogging->TimeNow.second = MAX_int32_T;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_LowerBound,
            &rtb_UpperBound, &Switch, &rtb_UpperBound_e, &rtb_Gain_p,
            &rtb_RefRngmMinRng);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_LowerBound,
            &rtb_UpperBound, &Switch, &rtb_UpperBound_e, &rtb_Gain_p, &rtb_Abs1);
        rtb_RefRngmMinRng = std::round((rtb_RefRngmMinRng - std::floor(rtb_Abs1))
            * 1000.0);
        if (rtb_RefRngmMinRng < 2.147483648E+9) {
            if (rtb_RefRngmMinRng >= -2.147483648E+9) {
                rty_FlightLogging->TimeNow.millisecond = static_cast<int32_T>
                    (rtb_RefRngmMinRng);
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
        // Update for Atomic SubSystem: '<S6>/HeadingNaNProtection'
        // Switch: '<S64>/HeightSwitch' incorporates:
        //   RelationalOperator: '<S64>/IsNaN'

        if (std::isnan(localDW->SwitchLookAheadNED[2])) {
            // Update for Memory: '<S64>/MemoryRefHeight' incorporates:
            //   Constant: '<S64>/DefaultHeight'

            localDW->MemoryRefHeight_PreviousInput = -150.0;
        } else {
            // Update for Memory: '<S64>/MemoryRefHeight'
            localDW->MemoryRefHeight_PreviousInput = localDW->
                SwitchLookAheadNED[2];
        }

        // End of Switch: '<S64>/HeightSwitch'
        // End of Update for SubSystem: '<S6>/HeadingNaNProtection'

        // Update for Memory: '<S6>/MemoryNotInBrake'
        localDW->MemoryNotInBrake_PreviousInput = localDW->Compare;

        // Update for Atomic SubSystem: '<S6>/GenerateTrack'
        for (int_T i{0}; i < 215; i++) {
            // Update for S-Function (sfix_udelay): '<S62>/EastSequence'
            localDW->EastSequence_X[i] = localDW->EastSequence_X
                [static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S62>/HeightSequence'
            localDW->HeightSequence_X[i] = localDW->HeightSequence_X[
                static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S62>/NorthSequence'
            localDW->NorthSequence_X[i] = localDW->NorthSequence_X
                [static_cast<int_T>(i + 1)];
        }

        // Update for S-Function (sfix_udelay): '<S62>/EastSequence'
        localDW->EastSequence_X[215] = rtu_SimUAVState->East;

        // Update for S-Function (sfix_udelay): '<S62>/HeightSequence'
        localDW->HeightSequence_X[215] = rtu_SimUAVState->Height;

        // Update for S-Function (sfix_udelay): '<S62>/NorthSequence'
        localDW->NorthSequence_X[215] = rtu_SimUAVState->North;

        // End of Update for SubSystem: '<S6>/GenerateTrack'

        // Update for Memory: '<S6>/Memory'
        localDW->Memory_PreviousInput = localDW->Engaged;

        // Update for Atomic SubSystem: '<S6>/HeadingLogic'
        // Update for Atomic SubSystem: '<S63>/NewMissionHdg'
        // Update for DiscreteIntegrator: '<S69>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S69>/Constant'

        localDW->DiscreteTimeIntegrator_DSTATE += 0.5;
        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        } else if (localDW->DiscreteTimeIntegrator_DSTATE <= (rtMinusInf)) {
            localDW->DiscreteTimeIntegrator_DSTATE = (rtMinusInf);
        }

        localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
            (*rtu_NewMission);

        // End of Update for DiscreteIntegrator: '<S69>/Discrete-Time Integrator' 
        // End of Update for SubSystem: '<S63>/NewMissionHdg'
        // End of Update for SubSystem: '<S6>/HeadingLogic'
    }

    // Update for Atomic SubSystem: '<S6>/SpeedControl'
    // Update for Enabled SubSystem: '<S67>/ADRC' incorporates:
    //   EnablePort: '<S74>/Enable'

    if (localDW->ADRC_MODE && rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Update for Enabled SubSystem: '<S74>/PD' incorporates:
        //   EnablePort: '<S84>/Enable'

        if (localDW->PD_MODE) {
            // Update for Delay: '<S123>/UD'
            localDW->UD_DSTATE = localDW->Tsamp;
        }

        // End of Update for SubSystem: '<S74>/PD'
    }

    // End of Update for SubSystem: '<S67>/ADRC'
    // End of Update for SubSystem: '<S6>/SpeedControl'
    // End of Update for SubSystem: '<Root>/Real2SimNav'
}

// Derivatives for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot)
{
    // Derivatives for Atomic SubSystem: '<Root>/Real2SimNav'
    // Derivatives for Atomic SubSystem: '<S6>/SpeedControl'
    // Derivatives for Enabled SubSystem: '<S67>/ADRC'
    if (localDW->ADRC_MODE) {
        // Derivatives for Enabled SubSystem: '<S74>/ADRC'
        if (localDW->ADRC_MODE_c) {
            // Derivatives for Integrator: '<S86>/Integrator'
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

        // End of Derivatives for SubSystem: '<S74>/ADRC'
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

    // End of Derivatives for SubSystem: '<S67>/ADRC'
    // End of Derivatives for SubSystem: '<S6>/SpeedControl'

    // Derivatives for Integrator: '<S68>/TD_Alt'
    localXdot->TD_Alt_CSTATE = localDW->dotAltTD;

    // Derivatives for Integrator: '<S68>/dotAltTD'
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
