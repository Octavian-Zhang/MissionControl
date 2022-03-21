//
// File: Real2SimGuidance.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.85
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Mar 21 00:55:39 2022
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
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_powd_snf.h"

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

// Named constants for Chart: '<S68>/MissionSwitchInitialPersuit'
const uint8_T Real2SimGuidance_IN_Initial{ 1U };

const uint8_T Real2SimGuidance_IN_L1Hdg{ 2U };

const uint8_T Real2SimGuidance_IN_L1Hdg_b{ 1U };

const uint8_T Real2SimGuidance_IN_SimPnt{ 3U };

const uint8_T Real2SimGuidance_IN_SimPnt_g{ 2U };

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

// System initialize for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    int32_T i;

    // SystemInitialize for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Integrator: '<S67>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S67>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<S6>/GenerateTrack'
    for (i = 0; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S61>/HeightSequence' 
        localDW->HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<S6>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<S6>/SpeedControl'
    // InitializeConditions for Delay: '<S66>/Delay'
    for (i = 0; i < 72; i++) {
        std::memset(&localDW->Delay_DSTATE[i], 0, sizeof
                    (FixedWingGuidanceStateBus));
    }

    // End of InitializeConditions for Delay: '<S66>/Delay'

    // SystemInitialize for Atomic SubSystem: '<S66>/ADRC'
    // InitializeConditions for Integrator: '<S83>/TD_AirSpdADRC'
    localX->TD_AirSpdADRC_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S83>/dotTD'
    localX->dotTD_CSTATE = 0.0;

    // SystemInitialize for Enabled SubSystem: '<S73>/ESO'
    // InitializeConditions for Integrator: '<S81>/ESO'
    localX->ESO_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S81>/ESO_dot'
    localX->ESO_dot_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S81>/ESO_dotdot'
    localX->ESO_dotdot_CSTATE = 0.0;

    // End of SystemInitialize for SubSystem: '<S73>/ESO'
    // End of SystemInitialize for SubSystem: '<S66>/ADRC'
    // End of SystemInitialize for SubSystem: '<S6>/SpeedControl'

    // SystemInitialize for Atomic SubSystem: '<S6>/HeadingLogic'
    // SystemInitialize for Atomic SubSystem: '<S62>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // End of SystemInitialize for SubSystem: '<S62>/NewMissionHdg'

    // Start for MATLABSystem: '<S62>/TrackSimPath'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.SearchFlag = true;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S62>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 651; i++) {
        // InitializeConditions for MATLABSystem: '<S62>/TrackSimPath'
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

    // InitializeConditions for Integrator: '<S67>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S67>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemReset for Atomic SubSystem: '<S6>/HeadingNaNProtection'
    // InitializeConditions for Memory: '<S63>/MemoryRefHeight'
    localDW->MemoryRefHeight_PreviousInput = 0.0;

    // End of SystemReset for SubSystem: '<S6>/HeadingNaNProtection'

    // SystemReset for Atomic SubSystem: '<S6>/GenerateTrack'
    for (i = 0; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S61>/EastSequence' 
        localDW->EastSequence_X[i] = 0.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S61>/HeightSequence' 
        localDW->HeightSequence_X[i] = -150.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S61>/NorthSequence' 
        localDW->NorthSequence_X[i] = 0.0;
    }

    // End of SystemReset for SubSystem: '<S6>/GenerateTrack'

    // SystemReset for Atomic SubSystem: '<S6>/SpeedControl'
    // InitializeConditions for Delay: '<S66>/Delay'
    for (i = 0; i < 72; i++) {
        std::memset(&localDW->Delay_DSTATE[i], 0, sizeof
                    (FixedWingGuidanceStateBus));
    }

    // End of InitializeConditions for Delay: '<S66>/Delay'

    // SystemReset for Atomic SubSystem: '<S66>/ADRC'
    // InitializeConditions for Integrator: '<S83>/TD_AirSpdADRC'
    localX->TD_AirSpdADRC_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S83>/dotTD'
    localX->dotTD_CSTATE = 0.0;

    // End of SystemReset for SubSystem: '<S66>/ADRC'
    // End of SystemReset for SubSystem: '<S6>/SpeedControl'

    // SystemReset for Atomic SubSystem: '<S6>/HeadingLogic'
    // InitializeConditions for MATLABSystem: '<S62>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 651; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of InitializeConditions for MATLABSystem: '<S62>/TrackSimPath'

    // SystemReset for Atomic SubSystem: '<S62>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // SystemReset for Chart: '<S68>/MissionSwitchInitialPersuit'
    localDW->temporalCounter_i1 = 0U;
    localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2 = 0U;
    localDW->is_active_c3_Real2SimGuidance = 0U;
    localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->SimHdg = 0.0;

    // End of SystemReset for SubSystem: '<S62>/NewMissionHdg'
    // End of SystemReset for SubSystem: '<S6>/HeadingLogic'

    // SystemReset for Chart: '<S6>/Chart'
    localDW->is_active_c2_Real2SimGuidance = 0U;
    localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->BiasHSwitch = false;

    // End of SystemReset for SubSystem: '<Root>/Real2SimNav'

    // SystemReset for Chart: '<Root>/TASgreaterthan15for1Sec'
    localDW->is_active_c16_Real2SimGuidance = 0U;
    localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

    // SystemReset for Chart: '<Root>/EngagementDebouncer'
    localDW->is_DebounceExecution = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce_i = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_L0Engaged = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce_a = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2_n = 0U;
    localDW->is_L0Default = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i1_o = 0U;
    localDW->is_active_c34_Real2SimGuidance = 0U;
    localDW->Execution = 0U;
}

// Disable for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW)
{
    // Disable for Atomic SubSystem: '<Root>/Real2SimNav'
    // Disable for Atomic SubSystem: '<S6>/SpeedControl'
    // Disable for Atomic SubSystem: '<S66>/ADRC'
    // Disable for Enabled SubSystem: '<S73>/ESO'
    localDW->ESO_MODE = false;

    // End of Disable for SubSystem: '<S73>/ESO'
    // End of Disable for SubSystem: '<S66>/ADRC'
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
                      *rtu_BiasRatio, FCUCMD *rty_FCUCMD, uint8_T
                      *rty_EngagedFlag, FlightLogging *rty_FlightLogging,
                      DW_Real2SimGuidance_f_T *localDW, X_Real2SimGuidance_n_T
                      *localX)
{
    // local block i/o variables
    real_T rtb_SumNorth;
    real_T rtb_SumEast;
    real_T rtb_Switch_n;
    real_T rtb_Abs1_0[4];
    real_T rtb_SwitchLookAheadNED[3];
    real_T Switch;
    real_T a0;
    real_T a2;
    real_T rtb_Abs1;
    real_T rtb_FixedWingGuidanceStateBus_AirSpeed;
    real_T rtb_FixedWingGuidanceStateBus_FlightPathAngle;
    real_T rtb_FixedWingGuidanceStateBus_HeadingAngle;
    real_T rtb_FixedWingGuidanceStateBus_Height;
    real_T rtb_FixedWingGuidanceStateBus_RollAngle;
    real_T rtb_HeadWind;
    real_T rtb_LowerBound;
    real_T rtb_RealUAVNEUState_idx_0;
    real_T rtb_RealUAVNEUState_idx_1;
    real_T rtb_RealUAVNEUState_idx_2;
    real_T rtb_RefRngmMinRng;
    real_T rtb_Sum1_idx_1;
    real_T rtb_Sum_g0_idx_1;
    real_T rtb_Sum_k;
    real_T rtb_Switch;
    real_T rtb_SwitchLookAheadPoint_idx_0;
    real_T rtb_SwitchLookAheadPoint_idx_1;
    real_T rtb_SwitchLookAheadPoint_idx_2;
    real_T rtb_SwitchTargetHDG;
    real_T rtb_Switch_b;
    real_T rtb_UpperBound;
    real_T rtb_UpperBound_e;
    real_T y;
    real_T y_0;
    int32_T i;
    uint8_T b_varargout_4;
    uint8_T b_varargout_6;
    boolean_T rtb_GreaterThanOrEqual_h;
    boolean_T rtb_NoNewMission;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Switch: '<S25>/Switch' incorporates:
        //   Abs: '<S25>/Abs'
        //   Bias: '<S25>/Bias'
        //   Bias: '<S25>/Bias1'
        //   Constant: '<S25>/Constant2'
        //   Constant: '<S26>/Constant'
        //   DataStoreRead: '<S4>/LatitudeGCS'
        //   Math: '<S25>/Math Function1'
        //   RelationalOperator: '<S26>/Compare'

        if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch = LatitudeGCS;
        }

        // End of Switch: '<S25>/Switch'

        // Abs: '<S22>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch);

        // Switch: '<S22>/Switch' incorporates:
        //   Bias: '<S22>/Bias'
        //   Bias: '<S22>/Bias1'
        //   Constant: '<S13>/Constant'
        //   Constant: '<S13>/Constant1'
        //   Constant: '<S24>/Constant'
        //   Gain: '<S22>/Gain'
        //   Product: '<S22>/Divide1'
        //   RelationalOperator: '<S24>/Compare'
        //   Switch: '<S13>/Switch1'

        if (rtb_Abs1 > 90.0) {
            // Signum: '<S22>/Sign1'
            if (rtb_Switch < 0.0) {
                rtb_Switch = -1.0;
            } else if (rtb_Switch > 0.0) {
                rtb_Switch = 1.0;
            } else if (rtb_Switch == 0.0) {
                rtb_Switch = 0.0;
            } else {
                rtb_Switch = (rtNaN);
            }

            // End of Signum: '<S22>/Sign1'
            rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S22>/Switch'

        // Sum: '<S13>/Sum' incorporates:
        //   DataStoreRead: '<S4>/LongitudeGCS'

        rtb_Switch_b = static_cast<real_T>(i) + LongitudeGCS;

        // Switch: '<S23>/Switch' incorporates:
        //   Abs: '<S23>/Abs'
        //   Bias: '<S23>/Bias'
        //   Bias: '<S23>/Bias1'
        //   Constant: '<S23>/Constant2'
        //   Constant: '<S27>/Constant'
        //   Math: '<S23>/Math Function1'
        //   RelationalOperator: '<S27>/Compare'

        if (std::abs(rtb_Switch_b) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Switch_b + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S23>/Switch'

        // Sum: '<S11>/Sum1'
        rtb_Abs1 = rtu_StateFCU->RealUAVState.Latitude_deg - rtb_Switch;
        rtb_Sum1_idx_1 = rtu_StateFCU->RealUAVState.Longitude_deg - rtb_Switch_b;

        // Switch: '<S19>/Switch' incorporates:
        //   Abs: '<S19>/Abs'
        //   Bias: '<S19>/Bias'
        //   Bias: '<S19>/Bias1'
        //   Constant: '<S19>/Constant2'
        //   Constant: '<S20>/Constant'
        //   Math: '<S19>/Math Function1'
        //   RelationalOperator: '<S20>/Compare'

        if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch_b = rtb_Abs1;
        }

        // End of Switch: '<S19>/Switch'

        // Abs: '<S16>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch_b);

        // Switch: '<S16>/Switch' incorporates:
        //   Bias: '<S16>/Bias'
        //   Bias: '<S16>/Bias1'
        //   Constant: '<S12>/Constant'
        //   Constant: '<S12>/Constant1'
        //   Constant: '<S18>/Constant'
        //   Gain: '<S16>/Gain'
        //   Product: '<S16>/Divide1'
        //   RelationalOperator: '<S18>/Compare'
        //   Switch: '<S12>/Switch1'

        if (rtb_Abs1 > 90.0) {
            // Signum: '<S16>/Sign1'
            if (rtb_Switch_b < 0.0) {
                rtb_Switch_b = -1.0;
            } else if (rtb_Switch_b > 0.0) {
                rtb_Switch_b = 1.0;
            } else if (rtb_Switch_b == 0.0) {
                rtb_Switch_b = 0.0;
            } else {
                rtb_Switch_b = (rtNaN);
            }

            // End of Signum: '<S16>/Sign1'
            rtb_Switch_b *= -(rtb_Abs1 + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S16>/Switch'

        // Sum: '<S12>/Sum'
        rtb_Sum_k = static_cast<real_T>(i) + rtb_Sum1_idx_1;

        // Switch: '<S17>/Switch' incorporates:
        //   Abs: '<S17>/Abs'
        //   Bias: '<S17>/Bias'
        //   Bias: '<S17>/Bias1'
        //   Constant: '<S17>/Constant2'
        //   Constant: '<S21>/Constant'
        //   Math: '<S17>/Math Function1'
        //   RelationalOperator: '<S21>/Compare'

        if (std::abs(rtb_Sum_k) > 180.0) {
            rtb_Sum_k = rt_modd_snf(rtb_Sum_k + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S17>/Switch'

        // UnitConversion: '<S15>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Abs1 = 0.017453292519943295 * rtb_Switch_b;
        rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_k;

        // UnitConversion: '<S30>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch *= 0.017453292519943295;

        // Trigonometry: '<S31>/Trigonometric Function1'
        rtb_Sum_k = std::sin(rtb_Switch);

        // Sum: '<S31>/Sum1' incorporates:
        //   Constant: '<S31>/Constant'
        //   Product: '<S31>/Product1'

        rtb_Sum_k = 1.0 - 0.0066943799901413295 * rtb_Sum_k * rtb_Sum_k;

        // Product: '<S29>/Product1' incorporates:
        //   Constant: '<S29>/Constant1'
        //   Sqrt: '<S29>/sqrt'

        rtb_Switch_b = 6.378137E+6 / std::sqrt(rtb_Sum_k);

        // Product: '<S14>/dNorth' incorporates:
        //   Constant: '<S29>/Constant2'
        //   Product: '<S29>/Product3'
        //   Trigonometry: '<S29>/Trigonometric Function1'

        rtb_Sum_k = rtb_Abs1 / rt_atan2d_snf(1.0, rtb_Switch_b *
            0.99330562000985867 / rtb_Sum_k);

        // Switch: '<S40>/Switch' incorporates:
        //   Trigonometry: '<S14>/SinCos'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_n = 1.0;

        // Product: '<S14>/dEast' incorporates:
        //   Constant: '<S29>/Constant3'
        //   Product: '<S29>/Product4'
        //   Trigonometry: '<S29>/Trigonometric Function'
        //   Trigonometry: '<S29>/Trigonometric Function2'

        rtb_Switch_b = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_b * std::cos
            (rtb_Switch)) * rtb_Sum1_idx_1;

        // Sum: '<S14>/Sum2' incorporates:
        //   Product: '<S14>/x*cos'
        //   Product: '<S14>/y*sin'

        rtb_Switch = rtb_Sum_k * rtb_Switch_n + rtb_Switch_b * 0.0;

        // Switch: '<S40>/Switch' incorporates:
        //   Product: '<S14>/x*sin'
        //   Product: '<S14>/y*cos'
        //   Sum: '<S14>/Sum3'

        rtb_Switch_n = rtb_Switch_b * rtb_Switch_n - rtb_Sum_k * 0.0;

        // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
        //   DataStoreRead: '<S4>/AltitudeGCS'
        //   Gain: '<S10>/Gain1'
        //   Gain: '<S4>/inverse'
        //   Gain: '<S8>/Gain1'
        //   Gain: '<S9>/Gain1'
        //   Sum: '<S11>/Sum'

        rtb_Abs1 = rtb_Switch;
        rtb_Sum1_idx_1 = rtb_Switch_n;
        rtb_FixedWingGuidanceStateBus_Height =
            rtu_StateFCU->RealUAVState.Height_meter + -AltitudeGCS;
        rtb_FixedWingGuidanceStateBus_AirSpeed =
            rtu_StateFCU->RealUAVState.AirSpeed_mps;
        rtb_FixedWingGuidanceStateBus_HeadingAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.HeadingAngle_deg;
        rtb_FixedWingGuidanceStateBus_FlightPathAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.FlightPathAngle_deg;
        rtb_FixedWingGuidanceStateBus_RollAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.RollAngle_deg;

        // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
        // Outputs for Atomic SubSystem: '<S6>/HeadingNaNProtection'
        // Memory: '<S63>/MemoryRefHeight'
        rtb_Sum_k = localDW->MemoryRefHeight_PreviousInput;

        // End of Outputs for SubSystem: '<S6>/HeadingNaNProtection'

        // Sum: '<S6>/Minus' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

        rtb_HeadWind = rtu_StateFCU->RealUAVState.AirSpeed_mps -
            rtu_StateFCU->GndSpd_mps;

        // Logic: '<S6>/AND' incorporates:
        //   Constant: '<S65>/Constant'
        //   DataStoreRead: '<S6>/ReadFlightMode_Log'
        //   Memory: '<S6>/MemoryNotInBrake'
        //   RelationalOperator: '<S65>/Compare'

        localDW->AND = static_cast<boolean_T>(static_cast<int32_T>
            ((localDW->FlightMode_Log == 3.0) & static_cast<int32_T>
             (localDW->MemoryNotInBrake_PreviousInput)));

        // Outputs for Atomic SubSystem: '<S6>/GenerateTrack'
        // S-Function (sfix_udelay): '<S61>/EastSequence'
        localDW->MatrixConcatenate[433] = rtu_SimUAVState->East;

        // Gain: '<S61>/TrackInvH'
        localDW->TrackInvH = -rtu_SimUAVState->Height;

        // S-Function (sfix_udelay): '<S61>/HeightSequence'
        localDW->MatrixConcatenate[650] = localDW->TrackInvH;
        for (i = 0; i < 216; i++) {
            // S-Function (sfix_udelay): '<S61>/EastSequence'
            localDW->MatrixConcatenate[static_cast<int_T>(i + 217)] =
                localDW->EastSequence_X[i];

            // S-Function (sfix_udelay): '<S61>/HeightSequence'
            localDW->MatrixConcatenate[static_cast<int_T>(i + 434)] =
                localDW->HeightSequence_X[i];

            // S-Function (sfix_udelay): '<S61>/NorthSequence'
            localDW->MatrixConcatenate[i] = localDW->NorthSequence_X[i];
        }

        // S-Function (sfix_udelay): '<S61>/NorthSequence'
        localDW->MatrixConcatenate[216] = rtu_SimUAVState->North;

        // End of Outputs for SubSystem: '<S6>/GenerateTrack'

        // Outputs for Atomic SubSystem: '<S6>/SpeedControl'
        // Delay: '<S66>/Delay'
        rtb_Switch_b = localDW->Delay_DSTATE[0].AirSpeed;

        // Sum: '<S79>/Sum' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
        //   Delay: '<S66>/Delay'

        rtb_SwitchLookAheadPoint_idx_0 = localDW->Delay_DSTATE[0U].North -
            rtb_Switch;
        rtb_SwitchLookAheadPoint_idx_1 = localDW->Delay_DSTATE[0U].East -
            rtb_Switch_n;
        rtb_SwitchLookAheadPoint_idx_2 = localDW->Delay_DSTATE[0U].Height -
            localDW->Delay_DSTATE[0U].Height;

        // DotProduct: '<S79>/Dot Product'
        rtb_SwitchTargetHDG = rtb_SwitchLookAheadPoint_idx_0 *
            rtb_SwitchLookAheadPoint_idx_0;

        // Selector: '<S66>/SimLocation' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_SwitchLookAheadPoint_idx_0 = localDW->MatrixConcatenate[108];

        // DotProduct: '<S79>/Dot Product'
        rtb_SwitchTargetHDG += rtb_SwitchLookAheadPoint_idx_1 *
            rtb_SwitchLookAheadPoint_idx_1;

        // Selector: '<S66>/SimLocation' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_SwitchLookAheadPoint_idx_1 = localDW->MatrixConcatenate[325];

        // DotProduct: '<S79>/Dot Product'
        rtb_SwitchTargetHDG += rtb_SwitchLookAheadPoint_idx_2 *
            rtb_SwitchLookAheadPoint_idx_2;

        // Selector: '<S66>/SimLocation' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_SwitchLookAheadPoint_idx_2 = localDW->MatrixConcatenate[542];

        // Sqrt: '<S79>/sqrt' incorporates:
        //   DotProduct: '<S79>/Dot Product'

        rtb_SwitchTargetHDG = std::sqrt(rtb_SwitchTargetHDG);

        // Gain: '<S66>/InverseY'
        localDW->InverseY = -rtb_SwitchTargetHDG;

        // Sum: '<S80>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/SimLocation'
        //   Selector: '<S66>/TargetLocation'

        rtb_Switch = localDW->MatrixConcatenate[60] - localDW->
            MatrixConcatenate[108];

        // DotProduct: '<S80>/Dot Product'
        a0 = rtb_Switch * rtb_Switch;

        // Sum: '<S80>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/SimLocation'
        //   Selector: '<S66>/TargetLocation'

        rtb_Switch = localDW->MatrixConcatenate[277] -
            localDW->MatrixConcatenate[325];

        // DotProduct: '<S80>/Dot Product'
        a0 += rtb_Switch * rtb_Switch;

        // Sum: '<S80>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/SimLocation'
        //   Selector: '<S66>/TargetLocation'

        rtb_Switch = localDW->MatrixConcatenate[494] -
            localDW->MatrixConcatenate[542];

        // Switch: '<S40>/Switch' incorporates:
        //   DotProduct: '<S80>/Dot Product'
        //   Sqrt: '<S80>/sqrt'

        rtb_Switch_n = rtb_Switch * rtb_Switch + a0;
        rtb_Switch_n = std::sqrt(rtb_Switch_n);

        // Gain: '<S66>/InverseR'
        localDW->InverseR = -rtb_Switch_n;

        // End of Outputs for SubSystem: '<S6>/SpeedControl'
        // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    }

    // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S6>/SpeedControl'
    // Outputs for Atomic SubSystem: '<S66>/ADRC'
    // Outputs for Enabled SubSystem: '<S73>/ESO' incorporates:
    //   EnablePort: '<S81>/Enable'

    if (rtmIsMajorTimeStep(Real2SimGuidance_M) && rtmIsMajorTimeStep
            (Real2SimGuidance_M)) {
        if (localDW->AND) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->ESO_MODE) ^ 1))) {
                // InitializeConditions for Integrator: '<S81>/ESO'
                localX->ESO_CSTATE = 0.0;

                // InitializeConditions for Integrator: '<S81>/ESO_dot'
                localX->ESO_dot_CSTATE = 0.0;

                // InitializeConditions for Integrator: '<S81>/ESO_dotdot'
                localX->ESO_dotdot_CSTATE = 0.0;
                localDW->ESO_MODE = true;
            }
        } else {
            localDW->ESO_MODE = false;
        }
    }

    if (localDW->ESO_MODE) {
        // Integrator: '<S81>/ESO'
        localDW->ESO = localX->ESO_CSTATE;

        // Integrator: '<S81>/ESO_dot'
        localDW->ESO_dot = localX->ESO_dot_CSTATE;

        // Integrator: '<S81>/ESO_dotdot'
        localDW->ESO_dotdot = localX->ESO_dotdot_CSTATE;
    }

    // End of Outputs for SubSystem: '<S73>/ESO'

    // Integrator: '<S83>/dotTD'
    localDW->dotTD = localX->dotTD_CSTATE;

    // MATLAB Function: '<S82>/fhan(e1,ce2,r,h1)' incorporates:
    //   Gain: '<S82>/Gain'
    //   Integrator: '<S83>/TD_AirSpdADRC'
    //   Sum: '<S73>/SumTD'
    //   Sum: '<S73>/SumTDdot'

    // MATLAB Function 'Real2SimNav/SpeedControl/ADRC/NLSEF/fhan(e1,ce2,r,h1)': '<S86>:1' 
    // '<S86>:1:3'
    // '<S86>:1:4'
    // '<S86>:1:5'
    // '<S86>:1:6'
    // '<S86>:1:8'
    // '<S86>:1:9'
    a0 = (localDW->dotTD - localDW->ESO_dot) * 3.375 * 7.001953125;

    // '<S86>:1:10'
    rtb_Switch = (localX->TD_AirSpdADRC_CSTATE - localDW->ESO) + a0;

    // '<S86>:1:11'
    // '<S86>:1:12'
    if (rtb_Switch < 0.0) {
        y = -1.0;
    } else if (rtb_Switch > 0.0) {
        y = 1.0;
    } else if (rtb_Switch == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    a2 = (std::sqrt((8.0 * std::abs(rtb_Switch) + 490.27347564697266) *
                    490.27347564697266) - 490.27347564697266) * y / 2.0 + a0;

    // '<S86>:1:13'
    // '<S86>:1:14'
    if (rtb_Switch + 490.27347564697266 < 0.0) {
        y = -1.0;
    } else if (rtb_Switch + 490.27347564697266 > 0.0) {
        y = 1.0;
    } else if (rtb_Switch + 490.27347564697266 == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (rtb_Switch - 490.27347564697266 < 0.0) {
        y_0 = -1.0;
    } else if (rtb_Switch - 490.27347564697266 > 0.0) {
        y_0 = 1.0;
    } else if (rtb_Switch - 490.27347564697266 == 0.0) {
        y_0 = 0.0;
    } else {
        y_0 = (rtNaN);
    }

    a0 = ((a0 + rtb_Switch) - a2) * ((y - y_0) / 2.0) + a2;

    // '<S86>:1:15'
    // '<S86>:1:17'
    if (a0 < 0.0) {
        rtb_Switch = -1.0;
    } else if (a0 > 0.0) {
        rtb_Switch = 1.0;
    } else if (a0 == 0.0) {
        rtb_Switch = 0.0;
    } else {
        rtb_Switch = (rtNaN);
    }

    if (a0 + 490.27347564697266 < 0.0) {
        y = -1.0;
    } else if (a0 + 490.27347564697266 > 0.0) {
        y = 1.0;
    } else if (a0 + 490.27347564697266 == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (a0 - 490.27347564697266 < 0.0) {
        a2 = -1.0;
    } else if (a0 - 490.27347564697266 > 0.0) {
        a2 = 1.0;
    } else if (a0 - 490.27347564697266 == 0.0) {
        a2 = 0.0;
    } else {
        a2 = (rtNaN);
    }

    // Gain: '<S73>/GainADRCinvb0' incorporates:
    //   Gain: '<S82>/Gain1'
    //   MATLAB Function: '<S82>/fhan(e1,ce2,r,h1)'
    //   Sum: '<S73>/ESOpNLSEF'

    localDW->GainADRCinvb0 = (-((a0 / 490.27347564697266 - rtb_Switch) * -10.0 *
        ((y - a2) / 2.0) - 10.0 * rtb_Switch) - localDW->ESO_dotdot) *
        4.4444444444444446;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // ZeroOrderHold: '<S73>/ZOH_ADRC_U' incorporates:
        //   DataStoreWrite: '<S73>/WriteADRC_U_Log'

        localDW->ADRC_U_Log = localDW->GainADRCinvb0;

        // ZeroOrderHold: '<S73>/ZOH_ADRC_LagDis' incorporates:
        //   DataStoreWrite: '<S73>/WriteLagDistance'
        //   Integrator: '<S83>/TD_AirSpdADRC'
        //   Sum: '<S73>/LagDistanceSum'

        localDW->LagDistance = localX->TD_AirSpdADRC_CSTATE - localDW->InverseY;
    }

    // Sum: '<S73>/SumY'
    localDW->SumY = localDW->ESO - localDW->InverseY;

    // MATLAB Function: '<S83>/fhan_AirSpdADRC' incorporates:
    //   Integrator: '<S83>/TD_AirSpdADRC'
    //   SignalConversion generated from: '<S87>/ SFunction '
    //   Sum: '<S83>/Sum1'

    // MATLAB Function 'Real2SimNav/SpeedControl/ADRC/TD/fhan_AirSpdADRC': '<S87>:1' 
    // '<S87>:1:3'
    // '<S87>:1:4'
    // '<S87>:1:5'
    // '<S87>:1:6'
    // '<S87>:1:8'
    // '<S87>:1:9'
    a0 = localDW->dotTD * 0.1;

    // '<S87>:1:10'
    rtb_Switch = (localX->TD_AirSpdADRC_CSTATE - localDW->InverseR) + a0;

    // '<S87>:1:11'
    // '<S87>:1:12'
    if (rtb_Switch < 0.0) {
        y = -1.0;
    } else if (rtb_Switch > 0.0) {
        y = 1.0;
    } else if (rtb_Switch == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    a2 = (std::sqrt((8.0 * std::abs(rtb_Switch) + 0.05) * 0.05) - 0.05) * y /
        2.0 + a0;

    // '<S87>:1:13'
    // '<S87>:1:14'
    if (rtb_Switch + 0.05 < 0.0) {
        y = -1.0;
    } else if (rtb_Switch + 0.05 > 0.0) {
        y = 1.0;
    } else if (rtb_Switch + 0.05 == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (rtb_Switch - 0.05 < 0.0) {
        y_0 = -1.0;
    } else if (rtb_Switch - 0.05 > 0.0) {
        y_0 = 1.0;
    } else if (rtb_Switch - 0.05 == 0.0) {
        y_0 = 0.0;
    } else {
        y_0 = (rtNaN);
    }

    a0 = ((a0 + rtb_Switch) - a2) * ((y - y_0) / 2.0) + a2;

    // '<S87>:1:15'
    // '<S87>:1:17'
    if (a0 < 0.0) {
        rtb_Switch = -1.0;
    } else if (a0 > 0.0) {
        rtb_Switch = 1.0;
    } else if (a0 == 0.0) {
        rtb_Switch = 0.0;
    } else {
        rtb_Switch = (rtNaN);
    }

    if (a0 + 0.05 < 0.0) {
        y = -1.0;
    } else if (a0 + 0.05 > 0.0) {
        y = 1.0;
    } else if (a0 + 0.05 == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (a0 - 0.05 < 0.0) {
        a2 = -1.0;
    } else if (a0 - 0.05 > 0.0) {
        a2 = 1.0;
    } else if (a0 - 0.05 == 0.0) {
        a2 = 0.0;
    } else {
        a2 = (rtNaN);
    }

    localDW->fh_b = (a0 / 0.05 - rtb_Switch) * -5.0 * ((y - a2) / 2.0) - 5.0 *
        rtb_Switch;

    // End of MATLAB Function: '<S83>/fhan_AirSpdADRC'
    // End of Outputs for SubSystem: '<S66>/ADRC'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Sum: '<S75>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/FrontBound'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[108] -
            rtb_SwitchLookAheadPoint_idx_0;

        // DotProduct: '<S75>/Dot Product'
        a0 = rtb_Switch * rtb_Switch;

        // Sum: '<S76>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/TailBound'
        //   Sum: '<S75>/Sum'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[12] -
            rtb_SwitchLookAheadPoint_idx_0;

        // DotProduct: '<S76>/Dot Product'
        rtb_UpperBound = rtb_Switch * rtb_Switch;

        // Sum: '<S75>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/FrontBound'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[325] -
            rtb_SwitchLookAheadPoint_idx_1;

        // DotProduct: '<S75>/Dot Product'
        a0 += rtb_Switch * rtb_Switch;

        // Sum: '<S76>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/TailBound'
        //   Sum: '<S75>/Sum'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[229] -
            rtb_SwitchLookAheadPoint_idx_1;

        // DotProduct: '<S76>/Dot Product'
        rtb_UpperBound += rtb_Switch * rtb_Switch;

        // Sum: '<S75>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/FrontBound'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[542] -
            rtb_SwitchLookAheadPoint_idx_2;

        // DotProduct: '<S75>/Dot Product'
        a0 += rtb_Switch * rtb_Switch;

        // Sum: '<S76>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/TailBound'
        //   Sum: '<S75>/Sum'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[446] -
            rtb_SwitchLookAheadPoint_idx_2;

        // Sqrt: '<S75>/sqrt' incorporates:
        //   DotProduct: '<S75>/Dot Product'

        a0 = std::sqrt(a0);

        // Sum: '<S66>/ActRngmMinRng'
        rtb_SwitchTargetHDG -= a0;

        // Sum: '<S66>/RefRngmMinRng'
        rtb_RefRngmMinRng = rtb_Switch_n - a0;

        // Sum: '<S66>/ComputeLB'
        rtb_LowerBound = a0 - rtb_Switch_n;

        // Sum: '<S66>/ComputeUB' incorporates:
        //   DotProduct: '<S76>/Dot Product'
        //   Sqrt: '<S76>/sqrt'

        rtb_UpperBound = std::sqrt(rtb_Switch * rtb_Switch + rtb_UpperBound) -
            rtb_Switch_n;

        // Outputs for Enabled SubSystem: '<S66>/EnableBias' incorporates:
        //   EnablePort: '<S74>/Enable'

        // Math: '<S66>/Square' incorporates:
        //   Math: '<S74>/Square'

        rtb_UpperBound_e = rtb_RefRngmMinRng * rtb_RefRngmMinRng;

        // End of Outputs for SubSystem: '<S66>/EnableBias'

        // Product: '<S66>/DivideLB' incorporates:
        //   Bias: '<S66>/Bias'
        //   Math: '<S66>/Square'

        a0 = rtb_UpperBound_e / (rtb_RefRngmMinRng + 10.0);

        // Switch: '<S66>/Switch' incorporates:
        //   RelationalOperator: '<S66>/GreaterThanOrEqual'

        if (rtb_SwitchTargetHDG >= a0) {
            // Switch: '<S66>/Switch'
            Switch = rtb_SwitchTargetHDG;
        } else {
            // Switch: '<S66>/Switch'
            Switch = a0;
        }

        // End of Switch: '<S66>/Switch'

        // Outputs for Enabled SubSystem: '<S66>/EnableBias' incorporates:
        //   EnablePort: '<S74>/Enable'

        if (Switch > 0.0) {
            // Sum: '<S74>/biasHm70' incorporates:
            //   Product: '<S74>/Divide'

            localDW->biasHm70 = rtb_UpperBound_e / Switch - rtb_RefRngmMinRng;
        }

        // End of Outputs for SubSystem: '<S66>/EnableBias'

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/L1FrontBound'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[78] -
            rtb_SwitchLookAheadPoint_idx_0;

        // DotProduct: '<S77>/Dot Product'
        a0 = rtb_Switch * rtb_Switch;

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/L1TailBound'
        //   Sum: '<S77>/Sum'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_SwitchTargetHDG = localDW->MatrixConcatenate[42] -
            rtb_SwitchLookAheadPoint_idx_0;

        // DotProduct: '<S78>/Dot Product'
        rtb_RefRngmMinRng = rtb_SwitchTargetHDG * rtb_SwitchTargetHDG;

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/L1FrontBound'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[295] -
            rtb_SwitchLookAheadPoint_idx_1;

        // DotProduct: '<S77>/Dot Product'
        a0 += rtb_Switch * rtb_Switch;

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/L1TailBound'
        //   Sum: '<S77>/Sum'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_SwitchTargetHDG = localDW->MatrixConcatenate[259] -
            rtb_SwitchLookAheadPoint_idx_1;

        // DotProduct: '<S78>/Dot Product'
        rtb_RefRngmMinRng += rtb_SwitchTargetHDG * rtb_SwitchTargetHDG;

        // Sum: '<S77>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/L1FrontBound'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_Switch = localDW->MatrixConcatenate[512] -
            rtb_SwitchLookAheadPoint_idx_2;

        // Sum: '<S78>/Sum' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   Selector: '<S66>/L1TailBound'
        //   Sum: '<S77>/Sum'
        //   Switch: '<Root>/SwitchLookAheadPoint'

        rtb_SwitchTargetHDG = localDW->MatrixConcatenate[476] -
            rtb_SwitchLookAheadPoint_idx_2;

        // Sum: '<S66>/L1ComputeLB' incorporates:
        //   DotProduct: '<S77>/Dot Product'
        //   Sqrt: '<S77>/sqrt'

        Switch = std::sqrt(rtb_Switch * rtb_Switch + a0) - rtb_Switch_n;

        // Sum: '<S66>/L1ComputeUB' incorporates:
        //   DotProduct: '<S78>/Dot Product'
        //   Sqrt: '<S78>/sqrt'

        rtb_UpperBound_e = std::sqrt(rtb_SwitchTargetHDG * rtb_SwitchTargetHDG +
            rtb_RefRngmMinRng) - rtb_Switch_n;

        // Outputs for Atomic SubSystem: '<S6>/MaxBrake'
        // Switch: '<S40>/Switch' incorporates:
        //   Gain: '<S64>/Up2Down'

        rtb_Switch_n = -rtu_SimUAVState->Height;

        // Sum: '<S72>/Sum' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

        rtb_RefRngmMinRng = rtu_SimUAVState->North - rtb_Abs1;
        rtb_Sum_g0_idx_1 = rtu_SimUAVState->East - rtb_Sum1_idx_1;
        rtb_SwitchLookAheadPoint_idx_1 = rtb_Switch_n - rtb_Sum_k;

        // Switch: '<S40>/Switch' incorporates:
        //   DotProduct: '<S72>/Dot Product'
        //   Sqrt: '<S72>/sqrt'

        rtb_Switch_n = (rtb_RefRngmMinRng * rtb_RefRngmMinRng + rtb_Sum_g0_idx_1
                        * rtb_Sum_g0_idx_1) + rtb_SwitchLookAheadPoint_idx_1 *
            rtb_SwitchLookAheadPoint_idx_1;
        rtb_Switch_n = std::sqrt(rtb_Switch_n);

        // Outputs for Atomic SubSystem: '<S6>/HeadingLogic'
        // Outputs for Atomic SubSystem: '<S62>/NewMissionHdg'
        // Product: '<S64>/BrkRng' incorporates:
        //   Constant: '<S64>/SampleTime'
        //   Gain: '<S68>/Ts'

        rtb_SwitchLookAheadPoint_idx_1 = rtu_SimUAVState->AirSpeed * 0.1;

        // End of Outputs for SubSystem: '<S62>/NewMissionHdg'
        // End of Outputs for SubSystem: '<S6>/HeadingLogic'

        // Switch: '<S40>/Switch' incorporates:
        //   Constant: '<S64>/TrackDP'
        //   Product: '<S64>/BrkRng'
        //   Sum: '<S64>/Minus'

        rtb_Switch_n -= rtb_SwitchLookAheadPoint_idx_1 * 132.0;

        // Gain: '<S64>/Gain'
        rtb_Sum_g0_idx_1 = -rtb_Switch_n;

        // Switch: '<S64>/BrkSwitch' incorporates:
        //   Constant: '<S64>/MaxBrake'
        //   DataStoreWrite: '<S73>/WriteADRC_U_Log'
        //   Delay: '<S66>/Delay'
        //   Sum: '<S66>/SumSpd'

        if (rtb_Switch_n >= 0.0) {
            rtb_RefRngmMinRng = (rtb_HeadWind + localDW->ADRC_U_Log) +
                rtb_Switch_b;
        } else {
            rtb_RefRngmMinRng = 0.0;
        }

        // End of Switch: '<S64>/BrkSwitch'

        // Saturate: '<S64>/SpeedProtection'
        if (rtb_RefRngmMinRng > 46.0) {
            rtb_RefRngmMinRng = 46.0;
        } else if (rtb_RefRngmMinRng < 29.0) {
            rtb_RefRngmMinRng = 29.0;
        }

        // End of Saturate: '<S64>/SpeedProtection'
        // End of Outputs for SubSystem: '<S6>/MaxBrake'

        // Outputs for Atomic SubSystem: '<S6>/HeadingLogic'
        // Gain: '<S62>/LookaheadT'
        rtb_HeadWind = 3.6 * rtu_SimUAVState->AirSpeed;

        // SignalConversion generated from: '<S62>/TrackSimPath' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

        rtb_Abs1_0[0] = rtb_Abs1;
        rtb_Abs1_0[1] = rtb_Sum1_idx_1;
        rtb_Abs1_0[2] = rtb_Sum_k;
        rtb_Abs1_0[3] = rtb_FixedWingGuidanceStateBus_HeadingAngle;

        // MATLABSystem: '<S62>/TrackSimPath' incorporates:
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   DataStoreWrite: '<S62>/WriteCrossTrackError'

        Real2SimGuidance_WaypointFollower_stepImpl(&localDW->obj, rtb_Abs1_0,
            localDW->MatrixConcatenate, rtb_HeadWind, rtb_SwitchLookAheadNED,
            &rtb_SwitchTargetHDG, &rtb_Switch, &b_varargout_4,
            &localDW->CrossTrackError, &b_varargout_6, localDW);

        // RelationalOperator: '<S62>/Relational Operator' incorporates:
        //   DataStoreWrite: '<S62>/WriteCrossTrackError'
        //   Gain: '<S62>/Gain'

        rtb_NoNewMission = (localDW->CrossTrackError <= 0.5 * rtb_HeadWind);

        // Outputs for Atomic SubSystem: '<S62>/NewMissionHdg'
        // Outputs for Enabled SubSystem: '<S68>/CalForwardShift' incorporates:
        //   EnablePort: '<S70>/Enable'

        if (rtu_SimUAVState->AirSpeed > 0.0) {
            // Outputs for Atomic SubSystem: '<S6>/MaxBrake'
            // Saturate: '<S68>/Saturation' incorporates:
            //   Gain: '<S64>/Gain'

            if (-rtb_Switch_n <= 0.0) {
                rtb_Sum_k = 0.0;
            } else {
                rtb_Sum_k = -rtb_Switch_n;
            }

            // End of Saturate: '<S68>/Saturation'
            // End of Outputs for SubSystem: '<S6>/MaxBrake'

            // Gain: '<S70>/Gain' incorporates:
            //   Product: '<S70>/Divide'

            localDW->Gain_b = rtb_Sum_k / rtu_SimUAVState->AirSpeed * 10.0;
        }

        // End of Outputs for SubSystem: '<S68>/CalForwardShift'

        // Outputs for Atomic SubSystem: '<S6>/MaxBrake'
        // RelationalOperator: '<S68>/GreaterThanOrEqual' incorporates:
        //   Constant: '<S68>/PenetrationDepthThreshold'
        //   Gain: '<S64>/Gain'
        //   Product: '<S68>/Product'

        rtb_GreaterThanOrEqual_h = (-rtb_Switch_n >=
            rtb_SwitchLookAheadPoint_idx_1 * 72.0);

        // End of Outputs for SubSystem: '<S6>/MaxBrake'

        // Chart: '<S68>/MissionSwitchInitialPersuit' incorporates:
        //   Memory: '<S6>/Memory'

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
            // Transition: '<S71>:14'
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S71>:12'
            localDW->SimHdg = 1.0;
        } else if (static_cast<int32_T>(localDW->is_c3_Real2SimGuidance) == 1) {
            // During 'Initial': '<S71>:12'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((localDW->temporalCounter_i1 >= 216U) &
                                        (static_cast<int32_T>
                    (localDW->Memory_PreviousInput) != 0)))) {
                // Transition: '<S71>:15'
                localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Normal;

                // Entry Internal 'Normal': '<S71>:13'
                // Transition: '<S71>:53'
                localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                // Entry 'SimPnt': '<S71>:37'
                localDW->SimHdg = 1.0;
            } else {
                localDW->SimHdg = 1.0;
            }

            // During 'Normal': '<S71>:13'
        } else if (*rtu_NewMission) {
            // Transition: '<S71>:16'
            // Exit Internal 'Normal': '<S71>:13'
            // Exit Internal 'Debounce': '<S71>:38'
            localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S71>:12'
            localDW->SimHdg = 1.0;
        } else {
            switch (localDW->is_Normal) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S71>:38'
                if (static_cast<int32_T>(localDW->is_Debounce) == 1) {
                    // During 'L1Hdg': '<S71>:49'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                            10U) {
                        // Transition: '<S71>:46'
                        localDW->is_Debounce =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_Normal = Real2SimGuidance_IN_L1Hdg;

                        // Entry 'L1Hdg': '<S71>:42'
                        localDW->SimHdg = 0.0;
                    } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(static_cast<boolean_T>(
                                   static_cast<int32_T>(static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &
                                 static_cast<int32_T>(rtb_NoNewMission)))) {
                        // Transition: '<S71>:50'
                        localDW->is_Debounce = Real2SimGuidance_IN_SimPnt_g;
                        localDW->temporalCounter_i2 = 0U;
                    }

                    // During 'SimPnt': '<S71>:44'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                           10U) {
                    // Transition: '<S71>:48'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                    // Entry 'SimPnt': '<S71>:37'
                    localDW->SimHdg = 1.0;
                } else if (rtb_GreaterThanOrEqual_h) {
                    // Transition: '<S71>:51'
                    localDW->is_Debounce = Real2SimGuidance_IN_L1Hdg_b;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              case Real2SimGuidance_IN_L1Hdg:
                // During 'L1Hdg': '<S71>:42'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (static_cast<boolean_T>(static_cast<
                        int32_T>(static_cast<int32_T>(rtb_GreaterThanOrEqual_h) ^
                                 1))) & static_cast<int32_T>(rtb_NoNewMission))))
                {
                    // Transition: '<S71>:45'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce = Real2SimGuidance_IN_SimPnt_g;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              default:
                // During 'SimPnt': '<S71>:37'
                if (rtb_GreaterThanOrEqual_h) {
                    // Transition: '<S71>:47'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce = Real2SimGuidance_IN_L1Hdg_b;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;
            }
        }

        // End of Chart: '<S68>/MissionSwitchInitialPersuit'

        // DataTypeConversion: '<S68>/Cast' incorporates:
        //   DataStoreWrite: '<S62>/WriteStatus_Log'
        //   Logic: '<S68>/OR'
        //   MATLABSystem: '<S62>/TrackSimPath'

        localDW->HdgStatus_Log = static_cast<uint8_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
            (b_varargout_6) != 0) | (localDW->SimHdg != 0.0)))));

        // DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
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

        // MinMax: '<S68>/Min' incorporates:
        //   Constant: '<S68>/NewestPoint'
        //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
        //   Gain: '<S68>/Gain'
        //   Rounding: '<S68>/Round'
        //   Sum: '<S68>/Minus'

        rtb_Sum_k = std::fmin(217.0, std::round((217.0 -
                                localDW->DiscreteTimeIntegrator_DSTATE) + 1.5 *
                               localDW->Gain_b));

        // End of Outputs for SubSystem: '<S62>/NewMissionHdg'

        // Switch: '<S62>/SwitchLookAheadNED' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
        //   Concatenate: '<S61>/Matrix Concatenate'
        //   DataStoreWrite: '<S62>/WriteStatus_Log'
        //   Selector: '<S62>/WayPoint3d3'
        //   Sum: '<S69>/EastArrow'
        //   Sum: '<S69>/NorthArrow'
        //   Switch: '<S62>/SwitchTargetHDG'
        //   Trigonometry: '<S69>/HdgCmd'

        if (static_cast<int32_T>(localDW->HdgStatus_Log) != 0) {
            // Selector: '<S62>/WayPoint3d3' incorporates:
            //   Concatenate: '<S61>/Matrix Concatenate'
            //   Sum: '<S69>/NorthArrow'

            rtb_HeadWind = localDW->MatrixConcatenate[static_cast<int32_T>(
                static_cast<int32_T>(rtb_Sum_k) - 1)];
            rtb_SwitchLookAheadNED[0] = rtb_HeadWind;

            // Selector: '<S62>/WayPoint3d3' incorporates:
            //   Concatenate: '<S61>/Matrix Concatenate'
            //   Sum: '<S69>/EastArrow'
            //   Switch: '<S62>/SwitchLookAheadNED'

            rtb_SwitchLookAheadPoint_idx_1 = localDW->MatrixConcatenate[
                static_cast<int32_T>(static_cast<int32_T>(rtb_Sum_k) + 216)];
            rtb_SwitchLookAheadNED[1] = rtb_SwitchLookAheadPoint_idx_1;
            rtb_SwitchLookAheadNED[2] = localDW->MatrixConcatenate
                [static_cast<int32_T>(static_cast<int32_T>(rtb_Sum_k) + 433)];
            rtb_SwitchTargetHDG = rt_atan2d_snf(rtb_SwitchLookAheadPoint_idx_1 -
                rtb_Sum1_idx_1, rtb_HeadWind - rtb_Abs1);
        }

        // End of Switch: '<S62>/SwitchLookAheadNED'
        // End of Outputs for SubSystem: '<S6>/HeadingLogic'

        // DataStoreWrite: '<S6>/WriteHeading_Log' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
        //   MATLAB Function: '<S6>/AngLog'

        // MATLAB Function 'Real2SimNav/AngLog': '<S57>:1'
        // '<S57>:1:2'
        // '<S57>:1:3'
        // '<S57>:1:4'
        localDW->Heading_Log[0] = angdiff_9SMt2WI9
            (rtb_FixedWingGuidanceStateBus_HeadingAngle, rtb_SwitchTargetHDG);
        localDW->Heading_Log[1] = angdiff_9SMt2WI9(0.0,
            rtb_FixedWingGuidanceStateBus_HeadingAngle);
        localDW->Heading_Log[2] = angdiff_9SMt2WI9(0.0, rtb_SwitchTargetHDG);
    }

    // End of Outputs for SubSystem: '<S6>/SpeedControl'

    // Integrator: '<S67>/TD_Alt' incorporates:
    //   DataStoreWrite: '<S6>/WritebiasH_Log'

    localDW->biasH_Log = localX->TD_Alt_CSTATE;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        boolean_T aVarTruthTableCondition_3;

        // Gain: '<S6>/Gain'
        localDW->Gain = 0.5 * localDW->biasHm70;

        // Chart: '<S6>/Chart' incorporates:
        //   DataStoreRead: '<S6>/ReadEngagedFlag_Log'

        // Gateway: Real2SimNav/Chart
        // During: Real2SimNav/Chart
        if (static_cast<uint32_T>(localDW->is_active_c2_Real2SimGuidance) == 0U)
        {
            // Entry: Real2SimNav/Chart
            localDW->is_active_c2_Real2SimGuidance = 1U;

            // Entry Internal: Real2SimNav/Chart
            // Transition: '<S58>:6'
            localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

            // Entry 'hasBias': '<S58>:5'
            localDW->BiasHSwitch = true;
        } else if (static_cast<int32_T>(localDW->is_c2_Real2SimGuidance) == 1) {
            localDW->BiasHSwitch = false;

            // During 'NoBias': '<S58>:7'
            if (*rtu_NewMission) {
                // Transition: '<S58>:9'
                localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

                // Entry 'hasBias': '<S58>:5'
                localDW->BiasHSwitch = true;
            }
        } else {
            localDW->BiasHSwitch = true;

            // During 'hasBias': '<S58>:5'
            if (static_cast<int32_T>(localDW->EngagedFlag) > 1) {
                // Transition: '<S58>:8'
                localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NoBias;

                // Entry 'NoBias': '<S58>:7'
                localDW->BiasHSwitch = false;
            }
        }

        // End of Chart: '<S6>/Chart'

        // RelationalOperator: '<S59>/Compare' incorporates:
        //   Constant: '<S59>/Constant'

        localDW->Compare = (rtb_Sum_g0_idx_1 < 0.0);

        // Truth Table: '<S6>/Engagement' incorporates:
        //   DataStoreRead: '<S6>/ReadLagDistance'
        //   DataStoreWrite: '<S62>/WriteCrossTrackError'
        //   Delay: '<S66>/Delay'

        // Truth Table Function 'Real2SimNav/Engagement': '<S60>:1'
        //  Front Distance within L1 Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_UpperBound_e) & (localDW->LagDistance > Switch)))) {
            // Condition '#1': '<S60>:1:10'
            rtb_NoNewMission = true;
        } else {
            rtb_NoNewMission = false;
        }

        //  Front Distance within L0 Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_UpperBound) & (localDW->LagDistance > rtb_LowerBound)))) {
            // Condition '#2': '<S60>:1:14'
            rtb_GreaterThanOrEqual_h = true;
        } else {
            rtb_GreaterThanOrEqual_h = false;
        }

        //  CrossTrack Error within 1.5 Second Bound
        // Condition '#3': '<S60>:1:18'
        aVarTruthTableCondition_3 = (localDW->CrossTrackError < rtb_Switch_b *
            72.0 * 0.1 / 5.0);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rtb_NoNewMission) & static_cast<int32_T>
                (aVarTruthTableCondition_3)))) {
            // Decision 'D1': '<S60>:1:20'
            //  Real UAV Deeply Engaged with Simulation UAV
            // Action '1': '<S60>:1:32'
            localDW->Engaged = 2U;
        } else if (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(rtb_GreaterThanOrEqual_h) &
                     static_cast<int32_T>(aVarTruthTableCondition_3)))) {
            // Decision 'D2': '<S60>:1:22'
            //  Real UAV Engaged with Simulation UAV
            // Action '2': '<S60>:1:38'
            localDW->Engaged = 1U;
        } else {
            // Decision 'D3': '<S60>:1:24'
            //  Default
            //  Real UAV Not Engaged with Simulation UAV
            // Action '3': '<S60>:1:44'
            localDW->Engaged = 0U;
        }

        // End of Truth Table: '<S6>/Engagement'

        // Gain: '<S6>/NED2NEU' incorporates:
        //   Switch: '<S62>/SwitchLookAheadNED'

        localDW->NorthEastHeight[0] = rtb_SwitchLookAheadNED[0];
        localDW->NorthEastHeight[1] = rtb_SwitchLookAheadNED[1];
        localDW->NorthEastHeight[2] = -rtb_SwitchLookAheadNED[2];

        // ZeroOrderHold: '<S6>/LookaheadPoint_ZOH' incorporates:
        //   DataStoreWrite: '<S6>/WritebiasH_Log'
        //   Gain: '<S6>/NED2NEU'
        //   Sum: '<S6>/SumBiasH'

        rtb_RealUAVNEUState_idx_0 = localDW->NorthEastHeight[0];
        rtb_RealUAVNEUState_idx_1 = localDW->NorthEastHeight[1];
        rtb_RealUAVNEUState_idx_2 = localDW->NorthEastHeight[2] +
            localDW->biasH_Log;
    }

    // Integrator: '<S67>/dotAltTD'
    localDW->dotAltTD = localX->dotAltTD_CSTATE;

    // MATLAB Function: '<S67>/fhan_Alt' incorporates:
    //   SignalConversion generated from: '<S88>/ SFunction '

    // MATLAB Function 'Real2SimNav/TD/fhan_Alt': '<S88>:1'
    // '<S88>:1:3'
    // '<S88>:1:4'
    // '<S88>:1:5'
    // '<S88>:1:6'
    // '<S88>:1:8'
    // '<S88>:1:9'
    a0 = localDW->dotAltTD * 0.1;

    // Switch: '<S6>/BiasHSwitch' incorporates:
    //   Constant: '<S6>/ZeroBias'
    //   Product: '<S6>/Product'

    // '<S88>:1:10'
    if (localDW->BiasHSwitch) {
        rtb_Sum_k = localDW->Gain * *rtu_BiasRatio;
    } else {
        rtb_Sum_k = 0.0;
    }

    // End of Switch: '<S6>/BiasHSwitch'

    // MATLAB Function: '<S67>/fhan_Alt' incorporates:
    //   DataStoreWrite: '<S6>/WritebiasH_Log'
    //   Sum: '<S67>/Sum1'

    rtb_Switch = (localDW->biasH_Log - rtb_Sum_k) + a0;

    // '<S88>:1:11'
    // '<S88>:1:12'
    if (rtb_Switch < 0.0) {
        y = -1.0;
    } else if (rtb_Switch > 0.0) {
        y = 1.0;
    } else if (rtb_Switch == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    a2 = (std::sqrt((8.0 * std::abs(rtb_Switch) + 0.004000000000000001) *
                    0.004000000000000001) - 0.004000000000000001) * y / 2.0 + a0;

    // '<S88>:1:13'
    // '<S88>:1:14'
    if (rtb_Switch + 0.004000000000000001 < 0.0) {
        y = -1.0;
    } else if (rtb_Switch + 0.004000000000000001 > 0.0) {
        y = 1.0;
    } else if (rtb_Switch + 0.004000000000000001 == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (rtb_Switch - 0.004000000000000001 < 0.0) {
        y_0 = -1.0;
    } else if (rtb_Switch - 0.004000000000000001 > 0.0) {
        y_0 = 1.0;
    } else if (rtb_Switch - 0.004000000000000001 == 0.0) {
        y_0 = 0.0;
    } else {
        y_0 = (rtNaN);
    }

    a0 = ((a0 + rtb_Switch) - a2) * ((y - y_0) / 2.0) + a2;

    // '<S88>:1:15'
    // '<S88>:1:17'
    if (a0 < 0.0) {
        rtb_LowerBound = -1.0;
    } else if (a0 > 0.0) {
        rtb_LowerBound = 1.0;
    } else if (a0 == 0.0) {
        rtb_LowerBound = 0.0;
    } else {
        rtb_LowerBound = (rtNaN);
    }

    if (a0 + 0.004000000000000001 < 0.0) {
        y = -1.0;
    } else if (a0 + 0.004000000000000001 > 0.0) {
        y = 1.0;
    } else if (a0 + 0.004000000000000001 == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (a0 - 0.004000000000000001 < 0.0) {
        a2 = -1.0;
    } else if (a0 - 0.004000000000000001 > 0.0) {
        a2 = 1.0;
    } else if (a0 - 0.004000000000000001 == 0.0) {
        a2 = 0.0;
    } else {
        a2 = (rtNaN);
    }

    localDW->fh = (a0 / 0.004000000000000001 - rtb_LowerBound) * -0.4 * ((y - a2)
        / 2.0) - 0.4 * rtb_LowerBound;

    // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Chart: '<Root>/TASgreaterthan15for1Sec' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

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
                    ((rtb_FixedWingGuidanceStateBus_AirSpeed > 15.0) ^ 1))) |
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
                                   ((rtb_FixedWingGuidanceStateBus_AirSpeed >
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
            // Transition: '<S2>:105'
            // Entry 'DebounceExecution': '<S2>:104'
            // Entry Internal 'DebounceExecution': '<S2>:104'
            // Transition: '<S2>:97'
            localDW->is_DebounceExecution = Real2SimGuidance_IN_Persuit;

            // Entry 'Persuit': '<S2>:95'
            localDW->Execution = 0U;

            // Entry Internal 'Persuit': '<S2>:95'
            // Transition: '<S2>:100'
            localDW->is_Persuit = Real2SimGuidance_IN_Normal;
        } else {
            // During 'DebounceExecution': '<S2>:104'
            switch (localDW->is_DebounceExecution) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S2>:90'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_o) >= 180U)
                {
                    // Transition: '<S2>:93'
                    // Exit Internal 'Debounce': '<S2>:90'
                    localDW->is_Debounce_i = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_DebounceExecution = Real2SimGuidance_IN_Persuit;

                    // Entry 'Persuit': '<S2>:95'
                    localDW->Execution = 0U;
                    localDW->is_Persuit = Real2SimGuidance_IN_Fault;
                    localDW->temporalCounter_i1_o = 0U;

                    // Entry 'Fault': '<S2>:94'
                } else if (static_cast<int32_T>(localDW->is_Debounce_i) == 1) {
                    // During 'Off': '<S2>:103'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2_n) >=
                            40U) {
                        // Transition: '<S2>:87'
                        localDW->is_Debounce_i =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_DebounceExecution =
                            Real2SimGuidance_IN_Persuit;

                        // Entry 'Persuit': '<S2>:95'
                        localDW->Execution = 0U;

                        // Entry Internal 'Persuit': '<S2>:95'
                        // Transition: '<S2>:100'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    } else if (static_cast<int32_T>(*rty_EngagedFlag) > 0) {
                        // Transition: '<S2>:102'
                        localDW->is_Debounce_i = Real2SimGuidance_IN_On;
                        localDW->temporalCounter_i2_n = 0U;
                    }

                    // During 'On': '<S2>:92'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2_n) >=
                           40U) {
                    // Transition: '<S2>:99'
                    localDW->is_Debounce_i = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_DebounceExecution =
                        Real2SimGuidance_IN_L0Engaged;

                    // Entry Internal 'L0Engaged': '<S2>:101'
                    // Transition: '<S2>:120'
                    localDW->is_L0Engaged = Real2SimGuidance_IN_L0Default;

                    // Entry 'L0Default': '<S2>:106'
                    localDW->Execution = 1U;

                    // Entry Internal 'L0Default': '<S2>:106'
                    // Transition: '<S2>:108'
                    localDW->is_L0Default = Real2SimGuidance_IN_Normal;
                } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S2>:96'
                    localDW->is_Debounce_i = Real2SimGuidance_IN_Off;
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
                    localDW->is_DebounceExecution = Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_o = 0U;
                    localDW->is_Debounce_i = Real2SimGuidance_IN_Off;
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
                            localDW->Execution = 1U;
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
                                localDW->Execution = 1U;

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
                            localDW->Execution = 2U;
                        } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 1)
                        {
                            // Transition: '<S2>:116'
                            localDW->is_Debounce_a = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_n = 0U;
                        }
                        break;

                      case Real2SimGuidance_IN_L0Default:
                        localDW->Execution = 1U;

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
                        localDW->Execution = 2U;

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
                localDW->Execution = 0U;

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
                    localDW->is_DebounceExecution = Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_o = 0U;
                    localDW->is_Debounce_i = Real2SimGuidance_IN_On;
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

        // Switch: '<Root>/SwitchLookAheadPoint' incorporates:
        //   ZeroOrderHold: '<S6>/LookaheadPoint_ZOH'

        if (rtu_ControlSwitch[0]) {
            // Sum: '<Root>/SumNorth' incorporates:
            //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
            //   Constant: '<Root>/LookAheadDis'
            //   Product: '<Root>/ProductNorth'
            //   Trigonometry: '<Root>/Cos'

            rtb_SumNorth = std::cos(rtu_ImmedGuidanceCMD->HeadingAngle) * 1000.0
                + rtb_Abs1;

            // Sum: '<Root>/SumEast' incorporates:
            //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
            //   Constant: '<Root>/LookAheadDis'
            //   Product: '<Root>/ProductEast'
            //   Trigonometry: '<Root>/Sin'

            rtb_SumEast = 1000.0 * std::sin(rtu_ImmedGuidanceCMD->HeadingAngle)
                + rtb_Sum1_idx_1;
            rtb_SwitchLookAheadPoint_idx_0 = rtb_SumNorth;
            rtb_SwitchLookAheadPoint_idx_1 = rtb_SumEast;
            rtb_SwitchLookAheadPoint_idx_2 = rtu_ImmedGuidanceCMD->Height;
        } else {
            rtb_SwitchLookAheadPoint_idx_0 = rtb_RealUAVNEUState_idx_0;
            rtb_SwitchLookAheadPoint_idx_1 = rtb_RealUAVNEUState_idx_1;
            rtb_SwitchLookAheadPoint_idx_2 = rtb_RealUAVNEUState_idx_2;
        }

        // End of Switch: '<Root>/SwitchLookAheadPoint'

        // Switch: '<S40>/Switch' incorporates:
        //   Trigonometry: '<S37>/SinCos'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_n = 1.0;

        // Sum: '<S37>/Sum' incorporates:
        //   Product: '<S37>/x*cos'
        //   Product: '<S37>/y*sin'

        rtb_LowerBound = rtb_SwitchLookAheadPoint_idx_0 * rtb_Switch_n -
            rtb_SwitchLookAheadPoint_idx_1 * 0.0;

        // Switch: '<S48>/Switch' incorporates:
        //   Abs: '<S48>/Abs'
        //   Bias: '<S48>/Bias'
        //   Bias: '<S48>/Bias1'
        //   Constant: '<S48>/Constant2'
        //   Constant: '<S49>/Constant'
        //   DataStoreRead: '<S5>/LatitudeGCS'
        //   Math: '<S48>/Math Function1'
        //   RelationalOperator: '<S49>/Compare'

        if (std::abs(LatitudeGCS) > 180.0) {
            a0 = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
            a0 = LatitudeGCS;
        }

        // End of Switch: '<S48>/Switch'

        // Abs: '<S45>/Abs1'
        rtb_UpperBound = std::abs(a0);

        // Switch: '<S45>/Switch' incorporates:
        //   Bias: '<S45>/Bias'
        //   Bias: '<S45>/Bias1'
        //   Constant: '<S36>/Constant'
        //   Constant: '<S36>/Constant1'
        //   Constant: '<S47>/Constant'
        //   Gain: '<S45>/Gain'
        //   Product: '<S45>/Divide1'
        //   RelationalOperator: '<S47>/Compare'
        //   Switch: '<S36>/Switch1'

        if (rtb_UpperBound > 90.0) {
            // Signum: '<S45>/Sign1'
            if (a0 < 0.0) {
                a0 = -1.0;
            } else if (a0 > 0.0) {
                a0 = 1.0;
            } else if (a0 == 0.0) {
                a0 = 0.0;
            } else {
                a0 = (rtNaN);
            }

            // End of Signum: '<S45>/Sign1'
            a0 *= -(rtb_UpperBound + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S45>/Switch'

        // UnitConversion: '<S53>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum_k = 0.017453292519943295 * a0;

        // Trigonometry: '<S54>/Trigonometric Function1'
        rtb_Switch_b = std::sin(rtb_Sum_k);

        // Sum: '<S54>/Sum1' incorporates:
        //   Constant: '<S54>/Constant'
        //   Product: '<S54>/Product1'

        rtb_Switch_b = 1.0 - 0.0066943799901413295 * rtb_Switch_b * rtb_Switch_b;

        // Product: '<S51>/Product1' incorporates:
        //   Constant: '<S51>/Constant1'
        //   Sqrt: '<S51>/sqrt'

        rtb_Switch = 6.378137E+6 / std::sqrt(rtb_Switch_b);

        // Switch: '<S40>/Switch' incorporates:
        //   Product: '<S37>/y*cos'

        rtb_Switch_n *= rtb_SwitchLookAheadPoint_idx_1;

        // Sum: '<S36>/Sum' incorporates:
        //   DataStoreRead: '<S5>/LongitudeGCS'

        // Unit Conversion - from: rad to: deg
        // Expression: output = (57.2958*input) + (0)
        rtb_SwitchTargetHDG = static_cast<real_T>(i) + LongitudeGCS;

        // Switch: '<S46>/Switch' incorporates:
        //   Abs: '<S46>/Abs'
        //   Bias: '<S46>/Bias'
        //   Bias: '<S46>/Bias1'
        //   Constant: '<S46>/Constant2'
        //   Constant: '<S50>/Constant'
        //   Math: '<S46>/Math Function1'
        //   RelationalOperator: '<S50>/Compare'

        if (std::abs(rtb_SwitchTargetHDG) > 180.0) {
            rtb_SwitchTargetHDG = rt_modd_snf(rtb_SwitchTargetHDG + 180.0, 360.0)
                + -180.0;
        }

        // End of Switch: '<S46>/Switch'

        // Sum: '<S34>/Sum' incorporates:
        //   Constant: '<S51>/Constant2'
        //   Constant: '<S51>/Constant3'
        //   Product: '<S37>/rad lat'
        //   Product: '<S37>/rad long '
        //   Product: '<S37>/x*sin'
        //   Product: '<S51>/Product3'
        //   Product: '<S51>/Product4'
        //   Sum: '<S37>/Sum1'
        //   Trigonometry: '<S51>/Trigonometric Function'
        //   Trigonometry: '<S51>/Trigonometric Function1'
        //   Trigonometry: '<S51>/Trigonometric Function2'
        //   UnitConversion: '<S38>/Unit Conversion'

        rtb_LowerBound = rt_atan2d_snf(1.0, rtb_Switch * 0.99330562000985867 /
            rtb_Switch_b) * rtb_LowerBound * 57.295779513082323 + a0;
        rtb_Switch_b = (rtb_SwitchLookAheadPoint_idx_0 * 0.0 + rtb_Switch_n) *
            rt_atan2d_snf(1.0, rtb_Switch * std::cos(rtb_Sum_k)) *
            57.295779513082323 + rtb_SwitchTargetHDG;

        // Switch: '<S42>/Switch' incorporates:
        //   Abs: '<S42>/Abs'
        //   Bias: '<S42>/Bias'
        //   Bias: '<S42>/Bias1'
        //   Constant: '<S42>/Constant2'
        //   Constant: '<S43>/Constant'
        //   Math: '<S42>/Math Function1'
        //   RelationalOperator: '<S43>/Compare'

        if (std::abs(rtb_LowerBound) > 180.0) {
            rtb_SwitchTargetHDG = rt_modd_snf(rtb_LowerBound + 180.0, 360.0) +
                -180.0;
        } else {
            rtb_SwitchTargetHDG = rtb_LowerBound;
        }

        // End of Switch: '<S42>/Switch'

        // Abs: '<S39>/Abs1'
        rtb_LowerBound = std::abs(rtb_SwitchTargetHDG);

        // Switch: '<S39>/Switch' incorporates:
        //   Bias: '<S39>/Bias'
        //   Bias: '<S39>/Bias1'
        //   Constant: '<S41>/Constant'
        //   Gain: '<S39>/Gain'
        //   Product: '<S39>/Divide1'
        //   RelationalOperator: '<S41>/Compare'
        //   Switch: '<S35>/Switch1'

        if (rtb_LowerBound > 90.0) {
            // Signum: '<S39>/Sign1'
            if (rtb_SwitchTargetHDG < 0.0) {
                rtb_SwitchTargetHDG = -1.0;
            } else if (rtb_SwitchTargetHDG > 0.0) {
                rtb_SwitchTargetHDG = 1.0;
            } else if (rtb_SwitchTargetHDG == 0.0) {
                rtb_SwitchTargetHDG = 0.0;
            } else {
                rtb_SwitchTargetHDG = (rtNaN);
            }

            // End of Signum: '<S39>/Sign1'
            rtb_SwitchTargetHDG *= -(rtb_LowerBound + -90.0) + 90.0;

            // Switch: '<S40>/Switch' incorporates:
            //   Bias: '<S39>/Bias'
            //   Bias: '<S39>/Bias1'
            //   Constant: '<S35>/Constant'
            //   Gain: '<S39>/Gain'
            //   Product: '<S39>/Divide1'

            rtb_Switch_n = 180.0;
        } else {
            // Switch: '<S40>/Switch' incorporates:
            //   Constant: '<S35>/Constant1'

            rtb_Switch_n = 0.0;
        }

        // End of Switch: '<S39>/Switch'

        // Sum: '<S35>/Sum'
        rtb_LowerBound = rtb_Switch_n + rtb_Switch_b;

        // Switch: '<S40>/Switch' incorporates:
        //   Abs: '<S40>/Abs'

        rtb_Switch_n = std::abs(rtb_LowerBound);

        // Switch: '<S40>/Switch' incorporates:
        //   Constant: '<S44>/Constant'
        //   RelationalOperator: '<S44>/Compare'

        if (rtb_Switch_n > 180.0) {
            // Switch: '<S40>/Switch' incorporates:
            //   Bias: '<S40>/Bias'
            //   Bias: '<S40>/Bias1'
            //   Constant: '<S40>/Constant2'
            //   Math: '<S40>/Math Function1'

            rtb_Switch_n = rt_modd_snf(rtb_LowerBound + 180.0, 360.0) + -180.0;
        } else {
            // Switch: '<S40>/Switch'
            rtb_Switch_n = rtb_LowerBound;
        }

        // End of Switch: '<S40>/Switch'

        // Sum: '<S34>/Sum1' incorporates:
        //   DataStoreRead: '<S5>/AltitudeGCS'
        //   Gain: '<S5>/Up2Down'
        //   Gain: '<S5>/inverse'

        rty_FCUCMD->Height_meter = rtb_SwitchLookAheadPoint_idx_2 -
            (-AltitudeGCS);

        // Switch: '<Root>/SwitchSpdControl'
        if (rtu_ControlSwitch[1]) {
            a0 = rtu_ImmedGuidanceCMD->AirSpeed;
        } else {
            a0 = rtb_RefRngmMinRng;
        }

        // End of Switch: '<Root>/SwitchSpdControl'

        // BusCreator: '<Root>/FcuCmdBus'
        rty_FCUCMD->Latitude_deg = rtb_SwitchTargetHDG;
        rty_FCUCMD->Longitude_deg = rtb_Switch_n;
        rty_FCUCMD->RefAirSpd_mps = a0;

        // DataStoreRead: '<Root>/ReadLagDistance'
        rty_FlightLogging->LagDistance = localDW->LagDistance;

        // DataStoreRead: '<Root>/ReadCrossTrackError'
        rty_FlightLogging->CrossTrackError = localDW->CrossTrackError;

        // DataStoreRead: '<Root>/ReadEngagedFlag_Log'
        rty_FlightLogging->EngagedFlag = localDW->EngagedFlag;

        // DataStoreRead: '<Root>/ReadADRC_U_Log'
        rty_FlightLogging->ADRC_U = localDW->ADRC_U_Log;

        // DataStoreRead: '<Root>/ReadbiasH_Log'
        rty_FlightLogging->biasH = localDW->biasH_Log;

        // DataStoreRead: '<Root>/ReadFlightMode_Log'
        rty_FlightLogging->FlightMode = localDW->FlightMode_Log;

        // DataStoreRead: '<Root>/ReadStatus_Log'
        rty_FlightLogging->HdgStatus = localDW->HdgStatus_Log;

        // BusCreator: '<Root>/LoggingBus' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

        rty_FlightLogging->RealUAVState.North = rtb_Abs1;
        rty_FlightLogging->RealUAVState.East = rtb_Sum1_idx_1;
        rty_FlightLogging->RealUAVState.Height =
            rtb_FixedWingGuidanceStateBus_Height;
        rty_FlightLogging->RealUAVState.AirSpeed =
            rtb_FixedWingGuidanceStateBus_AirSpeed;
        rty_FlightLogging->RealUAVState.HeadingAngle =
            rtb_FixedWingGuidanceStateBus_HeadingAngle;
        rty_FlightLogging->RealUAVState.FlightPathAngle =
            rtb_FixedWingGuidanceStateBus_FlightPathAngle;
        rty_FlightLogging->RealUAVState.RollAngle =
            rtb_FixedWingGuidanceStateBus_RollAngle;
        rty_FlightLogging->RealUAVState.RollAngleRate = 0.0;
        rty_FlightLogging->SimUAVState = *rtu_SimUAVState;
        rty_FlightLogging->RefAirspeed = a0;

        // DataStoreRead: '<Root>/ReadHeading_Log'
        rty_FlightLogging->Heading[0] = localDW->Heading_Log[0];

        // BusCreator: '<Root>/LoggingBus'
        rty_FlightLogging->LookAheadNED[0] = rtb_SwitchLookAheadPoint_idx_0;

        // DataStoreRead: '<Root>/ReadHeading_Log'
        rty_FlightLogging->Heading[1] = localDW->Heading_Log[1];

        // BusCreator: '<Root>/LoggingBus'
        rty_FlightLogging->LookAheadNED[1] = rtb_SwitchLookAheadPoint_idx_1;

        // DataStoreRead: '<Root>/ReadHeading_Log'
        rty_FlightLogging->Heading[2] = localDW->Heading_Log[2];

        // BusCreator: '<Root>/LoggingBus' incorporates:
        //   Trigonometry: '<S3>/Atan2'

        rty_FlightLogging->LookAheadNED[2] = rtb_SwitchLookAheadPoint_idx_2;
        rty_FlightLogging->GroundSpeed = rtu_StateFCU->GndSpd_mps;
        rty_FlightLogging->VectorSpd = rtu_StateFCU->VecSpd;
        rty_FlightLogging->Altitude = rtu_StateFCU->Altitude;
        rty_FlightLogging->FlightPath = rt_atan2d_snf
            (rtu_StateFCU->VecSpd.skySpeed, rtu_StateFCU->GndSpd_mps);
    }
}

// Update for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const boolean_T *rtu_NewMission, const
    FixedWingGuidanceStateBus *rtu_SimUAVState, DW_Real2SimGuidance_f_T *localDW)
{
    // Update for Atomic SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        int_T i;

        // Update for Atomic SubSystem: '<S6>/HeadingNaNProtection'
        // Switch: '<S63>/HeightSwitch' incorporates:
        //   Gain: '<S63>/Height2Down'
        //   RelationalOperator: '<S63>/IsNaN'

        if (std::isnan(-localDW->NorthEastHeight[2])) {
            // Update for Memory: '<S63>/MemoryRefHeight' incorporates:
            //   Constant: '<S63>/DefaultHeight'

            localDW->MemoryRefHeight_PreviousInput = -150.0;
        } else {
            // Update for Memory: '<S63>/MemoryRefHeight'
            localDW->MemoryRefHeight_PreviousInput = -localDW->NorthEastHeight[2];
        }

        // End of Switch: '<S63>/HeightSwitch'
        // End of Update for SubSystem: '<S6>/HeadingNaNProtection'

        // Update for Memory: '<S6>/MemoryNotInBrake'
        localDW->MemoryNotInBrake_PreviousInput = localDW->Compare;

        // Update for Atomic SubSystem: '<S6>/GenerateTrack'
        for (i = 0; i < 215; i++) {
            // Update for S-Function (sfix_udelay): '<S61>/EastSequence'
            localDW->EastSequence_X[i] = localDW->EastSequence_X
                [static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S61>/HeightSequence'
            localDW->HeightSequence_X[i] = localDW->HeightSequence_X[
                static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S61>/NorthSequence'
            localDW->NorthSequence_X[i] = localDW->NorthSequence_X
                [static_cast<int_T>(i + 1)];
        }

        // Update for S-Function (sfix_udelay): '<S61>/EastSequence'
        localDW->EastSequence_X[215] = rtu_SimUAVState->East;

        // Update for S-Function (sfix_udelay): '<S61>/HeightSequence'
        localDW->HeightSequence_X[215] = localDW->TrackInvH;

        // Update for S-Function (sfix_udelay): '<S61>/NorthSequence'
        localDW->NorthSequence_X[215] = rtu_SimUAVState->North;

        // End of Update for SubSystem: '<S6>/GenerateTrack'

        // Update for Atomic SubSystem: '<S6>/SpeedControl'
        // Update for Delay: '<S66>/Delay'
        for (i = 0; i < 71; i++) {
            localDW->Delay_DSTATE[i] = localDW->Delay_DSTATE[static_cast<int_T>
                (i + 1)];
        }

        localDW->Delay_DSTATE[71] = *rtu_SimUAVState;

        // End of Update for Delay: '<S66>/Delay'
        // End of Update for SubSystem: '<S6>/SpeedControl'

        // Update for Memory: '<S6>/Memory'
        localDW->Memory_PreviousInput = localDW->Engaged;

        // Update for Atomic SubSystem: '<S6>/HeadingLogic'
        // Update for Atomic SubSystem: '<S62>/NewMissionHdg'
        // Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S68>/Constant'

        localDW->DiscreteTimeIntegrator_DSTATE += 0.5;
        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        } else if (localDW->DiscreteTimeIntegrator_DSTATE <= (rtMinusInf)) {
            localDW->DiscreteTimeIntegrator_DSTATE = (rtMinusInf);
        }

        localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
            (*rtu_NewMission);

        // End of Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' 
        // End of Update for SubSystem: '<S62>/NewMissionHdg'
        // End of Update for SubSystem: '<S6>/HeadingLogic'
    }

    // End of Update for SubSystem: '<Root>/Real2SimNav'
}

// Derivatives for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot)
{
    // Derivatives for Atomic SubSystem: '<Root>/Real2SimNav'
    // Derivatives for Atomic SubSystem: '<S6>/SpeedControl'
    // Derivatives for Atomic SubSystem: '<S66>/ADRC'
    // Derivatives for Integrator: '<S83>/TD_AirSpdADRC'
    localXdot->TD_AirSpdADRC_CSTATE = localDW->dotTD;

    // Derivatives for Enabled SubSystem: '<S73>/ESO'
    if (localDW->ESO_MODE) {
        real_T y;
        real_T y_n;

        // MATLAB Function: '<S81>/fal(e,0.5,h)' incorporates:
        //   MATLAB Function: '<S81>/fal(e,0.25,h)'
        //   SignalConversion generated from: '<S84>/ SFunction '
        //   SignalConversion generated from: '<S85>/ SFunction '

        // MATLAB Function 'Real2SimNav/SpeedControl/ADRC/ESO/fal(e,0.5,h)': '<S85>:1' 
        // '<S85>:1:3'
        // '<S85>:1:4'
        // '<S85>:1:5'
        y_n = std::abs(localDW->SumY);
        if (y_n <= 0.1) {
            // '<S85>:1:7'
            // '<S85>:1:8'
            y = localDW->SumY / 0.31622776601683794;

            // '<S84>:1:7'
            // '<S84>:1:8'
            y_n = localDW->SumY / 0.17782794100389229;
        } else {
            real_T tmp;

            // '<S85>:1:10'
            if (localDW->SumY < 0.0) {
                tmp = -1.0;
            } else if (localDW->SumY > 0.0) {
                tmp = 1.0;
            } else if (localDW->SumY == 0.0) {
                tmp = 0.0;
            } else {
                tmp = (rtNaN);
            }

            y = rt_powd_snf(y_n, 0.5) * tmp;

            // '<S84>:1:10'
            if (localDW->SumY < 0.0) {
                tmp = -1.0;
            } else if (localDW->SumY > 0.0) {
                tmp = 1.0;
            } else if (localDW->SumY == 0.0) {
                tmp = 0.0;
            } else {
                tmp = (rtNaN);
            }

            y_n = rt_powd_snf(y_n, 0.25) * tmp;
        }

        // End of MATLAB Function: '<S81>/fal(e,0.5,h)'

        // Derivatives for Integrator: '<S81>/ESO' incorporates:
        //   Gain: '<S81>/beta_01'
        //   Sum: '<S81>/ESOdotsum'

        // MATLAB Function 'Real2SimNav/SpeedControl/ADRC/ESO/fal(e,0.25,h)': '<S84>:1' 
        // '<S84>:1:3'
        // '<S84>:1:4'
        // '<S84>:1:5'
        localXdot->ESO_CSTATE = localDW->ESO_dot - 15.0 * localDW->SumY;

        // Derivatives for Integrator: '<S81>/ESO_dot' incorporates:
        //   Gain: '<S81>/Gain1'
        //   Gain: '<S81>/Gain4'
        //   Sum: '<S81>/ESOdotdotsum'

        localXdot->ESO_dot_CSTATE = (0.225 * localDW->GainADRCinvb0 +
            localDW->ESO_dotdot) - 75.0 * y;

        // Derivatives for Integrator: '<S81>/ESO_dotdot' incorporates:
        //   Gain: '<S81>/Gain'
        //   Gain: '<S81>/Inverse'

        localXdot->ESO_dotdot_CSTATE = -(125.0 * y_n);
    } else {
        {
            real_T *dx;
            int_T i;
            dx = &(localXdot->ESO_CSTATE);
            for (i=0; i < 3; i++) {
                dx[i] = 0.0;
            }
        }
    }

    // End of Derivatives for SubSystem: '<S73>/ESO'

    // Derivatives for Integrator: '<S83>/dotTD'
    localXdot->dotTD_CSTATE = localDW->fh_b;

    // End of Derivatives for SubSystem: '<S66>/ADRC'
    // End of Derivatives for SubSystem: '<S6>/SpeedControl'

    // Derivatives for Integrator: '<S67>/TD_Alt'
    localXdot->TD_Alt_CSTATE = localDW->dotAltTD;

    // Derivatives for Integrator: '<S67>/dotAltTD'
    localXdot->dotAltTD_CSTATE = localDW->fh;

    // End of Derivatives for SubSystem: '<Root>/Real2SimNav'
}

// Model initialize function
void Real2SimGuidance_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_Real2SimGuidance_T
    *const Real2SimGuidance_M)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));

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
