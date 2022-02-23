//
// File: Real2SimGuidance.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 3.11
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Wed Feb 23 00:20:42 2022
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

// Named constants for Chart: '<Root>/TASgreaterthan15for1Sec'
const uint8_T Real2SimGuidance_IN_InAir{ 1U };

const uint8_T Real2SimGuidance_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T Real2SimGuidance_IN_NotTakeOff{ 2U };

// Named constants for Chart: '<Root>/TriggerTermination'
const uint8_T Real2SimGuidance_IN_Debounce{ 1U };

const uint8_T Real2SimGuidance_IN_DebounceExecution{ 1U };

const uint8_T Real2SimGuidance_IN_Engaged{ 2U };

const uint8_T Real2SimGuidance_IN_Fault{ 1U };

const uint8_T Real2SimGuidance_IN_Landing{ 2U };

const uint8_T Real2SimGuidance_IN_MissionCompletion{ 3U };

const uint8_T Real2SimGuidance_IN_Normal{ 2U };

const uint8_T Real2SimGuidance_IN_Off{ 1U };

const uint8_T Real2SimGuidance_IN_On{ 2U };

const uint8_T Real2SimGuidance_IN_Persuit{ 3U };

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
     real_T currentPose[4], const real_T waypoints[219], real_T
     lookaheadDistance, real_T varargout_1[3], real_T *varargout_2, real_T
     *varargout_3, uint8_T *varargout_4, real_T *varargout_5, uint8_T
     *varargout_6);
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
     real_T currentPose[4], const real_T waypoints[219], real_T
     lookaheadDistance, real_T varargout_1[3], real_T *varargout_2, real_T
     *varargout_3, uint8_T *varargout_4, real_T *varargout_5, uint8_T
     *varargout_6)
{
    emxArray_real_T_Real2SimGuidance_T *d;
    real_T b_waypointsIn_data[219];
    real_T waypoints_data[219];
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
    int8_T c_data[73];
    boolean_T x[219];
    boolean_T b[73];
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
    while ((!exitg1) && (iy < 219)) {
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
                    static_cast<uint32_T>(219U * sizeof(real_T)));
        obj->WaypointIndex = 1.0;
        obj->SearchFlag = true;
    }

    for (iy = 0; iy < 3; iy++) {
        for (j = 0; j < 72; j++) {
            i1 = static_cast<int32_T>(static_cast<int32_T>(73 * iy) + j);
            x[i1] = (waypoints[static_cast<int32_T>(static_cast<int32_T>(
                       static_cast<int32_T>(j + 2) + static_cast<int32_T>(73 *
                        iy)) - 1)] != waypoints[i1]);
        }

        x[static_cast<int32_T>(static_cast<int32_T>(73 * iy) + 72)] = true;
    }

    i1 = 0;
    i2 = 146;
    for (j = 0; j < 73; j++) {
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
                iy = static_cast<int32_T>(iy + 73);
            }
        }
    }

    i1 = 0;
    for (iy = 0; iy < 73; iy++) {
        if (b[iy]) {
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    c_size_idx_0 = i1;
    i1 = 0;
    for (iy = 0; iy < 73; iy++) {
        if (b[iy]) {
            c_data[i1] = static_cast<int8_T>(static_cast<int32_T>(iy + 1));
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    for (iy = 0; iy < 3; iy++) {
        for (j = 0; j <= static_cast<int32_T>(c_size_idx_0 - 1); j++) {
            b_waypointsIn_data[static_cast<int32_T>(j + static_cast<int32_T>
                (c_size_idx_0 * iy))] = waypoints[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(73 * iy) +
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

            virtualWaypoint[0] = b_waypointsIn_data[0] - currentPose[0];
            virtualWaypoint[1] = b_waypointsIn_data[1] - currentPose[1];
            virtualWaypoint[2] = b_waypointsIn_data[2] - currentPose[2];
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
                            b_waypointsIn_data[static_cast<int32_T>(static_cast<
                            int32_T>(c_size_idx_0 * iy) + j)];
                    }
                }

                obj->NumWaypoints = 2.0;
                c_size_idx_0 = 2;
                for (iy = 0; iy < 6; iy++) {
                    waypoints_data[iy] = appendedWaypoints_data[iy];
                }

                guard1 = true;
            }
        } else {
            i1 = static_cast<int32_T>(c_size_idx_0 * 3);
            for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                waypoints_data[iy] = b_waypointsIn_data[iy];
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
                    virtualWaypoint_tmp_tmp = waypoints_data[static_cast<int32_T>
                        (static_cast<int32_T>((static_cast<real_T>(iy) + 1.0) +
                          1.0) - 1)];
                    virtualWaypoint_tmp_tmp_2 = waypoints_data[iy];
                    virtualWaypoint_tmp = virtualWaypoint_tmp_tmp -
                        virtualWaypoint_tmp_tmp_2;
                    virtualWaypoint_tmp_tmp_0 = waypoints_data
                        [static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>((static_cast<real_T>(iy) + 1.0) +
                        1.0) + c_size_idx_0) - 1)];
                    virtualWaypoint_tmp_tmp_3 = waypoints_data
                        [static_cast<int32_T>(iy + c_size_idx_0)];
                    virtualWaypoint_tmp_0 = virtualWaypoint_tmp_tmp_0 -
                        virtualWaypoint_tmp_tmp_3;
                    virtualWaypoint_tmp_tmp_1 = waypoints_data
                        [static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>((static_cast<real_T>(iy) + 1.0) +
                        1.0) + static_cast<int32_T>(c_size_idx_0 << 1)) - 1)];
                    virtualWaypoint_tmp_tmp_4 = waypoints_data
                        [static_cast<int32_T>(static_cast<int32_T>(c_size_idx_0 <<
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

            virtualWaypoint_tmp_tmp_2 = waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(obj->WaypointIndex + 1.0) - 1)];
            virtualWaypoint[0] = currentPose[0] - virtualWaypoint_tmp_tmp_2;
            virtualWaypoint_tmp_tmp_3 = waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex +
                1.0) + c_size_idx_0) - 1)];
            virtualWaypoint[1] = currentPose[1] - virtualWaypoint_tmp_tmp_3;
            virtualWaypoint_tmp_tmp_4 = waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex +
                1.0) + static_cast<int32_T>(c_size_idx_0 << 1)) - 1)];
            virtualWaypoint[2] = currentPose[2] - virtualWaypoint_tmp_tmp_4;
            lambda = Real2SimGuidance_norm(virtualWaypoint);
            guard2 = false;
            if (lambda <= 1.0) {
                guard2 = true;
            } else {
                virtualWaypoint_tmp_tmp_1 = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(obj->WaypointIndex) - 1)];
                lambda_tmp = virtualWaypoint_tmp_tmp_2 -
                    virtualWaypoint_tmp_tmp_1;
                waypoints_0[0] = lambda_tmp;
                virtualWaypoint_tmp_tmp_0 = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex)
                    + c_size_idx_0) - 1)];
                lambda_tmp_0 = virtualWaypoint_tmp_tmp_3 -
                    virtualWaypoint_tmp_tmp_0;
                waypoints_0[1] = lambda_tmp_0;
                virtualWaypoint_tmp_tmp = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(c_size_idx_0 << 1)
                    + static_cast<int32_T>(obj->WaypointIndex)) - 1)];
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

                virtualWaypoint_tmp_tmp_1 = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(obj->WaypointIndex) - 1)];
                varargout_1[0] = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(obj->WaypointIndex + 1.0) - 1)];
                virtualWaypoint_tmp_tmp_0 = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex)
                    + c_size_idx_0) - 1)];
                varargout_1[1] = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + c_size_idx_0) - 1)];
                virtualWaypoint_tmp_tmp = waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(c_size_idx_0 << 1)
                    + static_cast<int32_T>(obj->WaypointIndex)) - 1)];
                varargout_1[2] = waypoints_data[static_cast<int32_T>(
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
    // InitializeConditions for Integrator: '<S64>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S64>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<S4>/GenerateTrack'
    for (i = 0; i < 72; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S58>/HeightSequence' 
        localDW->HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<S4>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<S4>/SpeedControl'
    // SystemInitialize for Atomic SubSystem: '<S63>/ADRC'
    // InitializeConditions for Integrator: '<S75>/TD_AirSpdADRC'
    localX->TD_AirSpdADRC_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S75>/dotTD'
    localX->dotTD_CSTATE = 0.0;

    // SystemInitialize for Enabled SubSystem: '<S67>/ESO'
    // InitializeConditions for Integrator: '<S73>/ESO'
    localX->ESO_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S73>/ESO_dot'
    localX->ESO_dot_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S73>/ESO_dotdot'
    localX->ESO_dotdot_CSTATE = 0.0;

    // End of SystemInitialize for SubSystem: '<S67>/ESO'
    // End of SystemInitialize for SubSystem: '<S63>/ADRC'
    // End of SystemInitialize for SubSystem: '<S4>/SpeedControl'

    // SystemInitialize for Atomic SubSystem: '<S4>/HeadingLogic'
    // Start for MATLABSystem: '<S59>/TrackSimPath'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.SearchFlag = true;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S59>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 219; i++) {
        // InitializeConditions for MATLABSystem: '<S59>/TrackSimPath'
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S4>/HeadingLogic'
    // End of SystemInitialize for SubSystem: '<Root>/Real2SimNav'
}

// System reset for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Reset(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    int32_T i;

    // SystemReset for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Integrator: '<S64>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S64>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemReset for Atomic SubSystem: '<S4>/HeadingNaNProtection'
    // InitializeConditions for Memory: '<S60>/MemoryRefHeight'
    localDW->MemoryRefHeight_PreviousInput = 0.0;

    // End of SystemReset for SubSystem: '<S4>/HeadingNaNProtection'

    // SystemReset for Atomic SubSystem: '<S4>/GenerateTrack'
    for (i = 0; i < 72; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S58>/EastSequence' 
        localDW->EastSequence_X[i] = 0.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S58>/HeightSequence' 
        localDW->HeightSequence_X[i] = -150.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S58>/NorthSequence' 
        localDW->NorthSequence_X[i] = 0.0;
    }

    // End of SystemReset for SubSystem: '<S4>/GenerateTrack'

    // SystemReset for Atomic SubSystem: '<S4>/SpeedControl'
    // SystemReset for Atomic SubSystem: '<S63>/ADRC'
    // InitializeConditions for Integrator: '<S75>/TD_AirSpdADRC'
    localX->TD_AirSpdADRC_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S75>/dotTD'
    localX->dotTD_CSTATE = 0.0;

    // End of SystemReset for SubSystem: '<S63>/ADRC'
    // End of SystemReset for SubSystem: '<S4>/SpeedControl'

    // SystemReset for Atomic SubSystem: '<S4>/HeadingLogic'
    // InitializeConditions for MATLABSystem: '<S59>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 219; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of InitializeConditions for MATLABSystem: '<S59>/TrackSimPath'
    // End of SystemReset for SubSystem: '<S4>/HeadingLogic'
    // End of SystemReset for SubSystem: '<Root>/Real2SimNav'

    // SystemReset for Chart: '<Root>/TASgreaterthan15for1Sec'
    localDW->is_active_c16_Real2SimGuidance = 0U;
    localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

    // SystemReset for Chart: '<Root>/TriggerTermination'
    localDW->is_DebounceExecution = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2 = 0U;
    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i1 = 0U;
    localDW->is_active_c34_Real2SimGuidance = 0U;
    localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->Terminate = false;
}

// Disable for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW)
{
    // Disable for Atomic SubSystem: '<Root>/Real2SimNav'
    // Disable for Atomic SubSystem: '<S4>/SpeedControl'
    // Disable for Atomic SubSystem: '<S63>/ADRC'
    // Disable for Enabled SubSystem: '<S67>/ESO'
    localDW->ESO_MODE = false;

    // End of Disable for SubSystem: '<S67>/ESO'
    // End of Disable for SubSystem: '<S63>/ADRC'
    // End of Disable for SubSystem: '<S4>/SpeedControl'
    // End of Disable for SubSystem: '<Root>/Real2SimNav'
}

// Outputs for referenced model: 'Real2SimGuidance'
void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const Real2SimGuidance_M,
                      const boolean_T *rtu_NewMission, const uint8_T
                      *rtu_FlightMode, const StateFCU *rtu_StateFCU, const
                      boolean_T rtu_ControlSwitch[2], const
                      FixedWingGuidanceStateBus *rtu_SimUAVState, const
                      FixedWingGuidanceBus *rtu_ImmedGuidanceCMD, const real_T
                      *rtu_BiasRatio, FCUCMD *rty_FCUCMD, boolean_T
                      *rty_EngagedFlag, FixedWingGuidanceStateBus
                      *rty_outputRealUAVState, FixedWingGuidanceStateBus
                      *rty_outputSimUAVState, real_T *rty_outputRefAirspeed,
                      real_T *rty_outputLagDistance, real_T
                      rty_outputLookAheadNED[3], real_T
                      *rty_outputCrossTrackError, boolean_T
                      *rty_outputEngagedFlag, real_T rty_outputHeading[3],
                      real_T *rty_outputADRC_U, real_T *rty_outputbiasH, real_T *
                      rty_outputGroundSpeed, real_T *rty_outputFlightMode,
                      uint8_T *rty_outputHdgStatus, VectorSpeed
                      *rty_outputVectorSpd, real_T *rty_outputAltitude, real_T
                      *rty_outputFlightPath, DW_Real2SimGuidance_f_T *localDW,
                      X_Real2SimGuidance_n_T *localX)
{
    // local block i/o variables
    real_T rtb_SumNorth;
    real_T rtb_SumEast;
    real_T rtb_MatrixConcatenate[219];
    real_T rty_outputRealUAVState_0[4];
    real_T rtb_SwitchLookAheadNED[3];
    real_T a2;
    real_T d;
    real_T rtb_Abs1;
    real_T rtb_CastToDouble;
    real_T rtb_LowerBound;
    real_T rtb_RealUAVNEUState_idx_0;
    real_T rtb_RealUAVNEUState_idx_1;
    real_T rtb_RealUAVNEUState_idx_2;
    real_T rtb_RefRngmMinRng;
    real_T rtb_Sum1_idx_1;
    real_T rtb_Sum_g0_0;
    real_T rtb_Sum_g0_idx_0;
    real_T rtb_Sum_k;
    real_T rtb_Sum_m_idx_0;
    real_T rtb_Sum_m_idx_1;
    real_T rtb_Sum_m_idx_2;
    real_T rtb_Switch;
    real_T rtb_Switch_b;
    real_T rtb_UpperBound;
    real_T y;
    real_T y_0;
    int32_T i;
    uint8_T b_varargout_4;
    boolean_T rtb_Compare_i;
    boolean_T rtb_NoNewMission;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // DataTypeConversion: '<Root>/Cast To Double' incorporates:
        //   Logic: '<Root>/NOT'

        rtb_CastToDouble = static_cast<real_T>(static_cast<int32_T>(static_cast<
            boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (rtu_ControlSwitch[1]) ^ 1))));

        // Logic: '<Root>/NoNewMission'
        rtb_NoNewMission = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(*rtu_NewMission) ^ 1));

        // Inport: '<Root>/SimUAVState'
        *rty_outputSimUAVState = *rtu_SimUAVState;

        // Switch: '<S24>/Switch' incorporates:
        //   Abs: '<S24>/Abs'
        //   Bias: '<S24>/Bias'
        //   Bias: '<S24>/Bias1'
        //   Constant: '<S24>/Constant2'
        //   Constant: '<S25>/Constant'
        //   DataStoreRead: '<S2>/LatitudeGCS'
        //   Math: '<S24>/Math Function1'
        //   RelationalOperator: '<S25>/Compare'

        if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch = LatitudeGCS;
        }

        // End of Switch: '<S24>/Switch'

        // Abs: '<S21>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch);

        // Switch: '<S21>/Switch' incorporates:
        //   Bias: '<S21>/Bias'
        //   Bias: '<S21>/Bias1'
        //   Constant: '<S12>/Constant'
        //   Constant: '<S12>/Constant1'
        //   Constant: '<S23>/Constant'
        //   Gain: '<S21>/Gain'
        //   Product: '<S21>/Divide1'
        //   RelationalOperator: '<S23>/Compare'
        //   Switch: '<S12>/Switch1'

        if (rtb_Abs1 > 90.0) {
            // Signum: '<S21>/Sign1'
            if (rtb_Switch < 0.0) {
                rtb_Switch = -1.0;
            } else if (rtb_Switch > 0.0) {
                rtb_Switch = 1.0;
            } else if (rtb_Switch == 0.0) {
                rtb_Switch = 0.0;
            } else {
                rtb_Switch = (rtNaN);
            }

            // End of Signum: '<S21>/Sign1'
            rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S21>/Switch'

        // Sum: '<S12>/Sum' incorporates:
        //   DataStoreRead: '<S2>/LongitudeGCS'

        rtb_Switch_b = static_cast<real_T>(i) + LongitudeGCS;

        // Switch: '<S22>/Switch' incorporates:
        //   Abs: '<S22>/Abs'
        //   Bias: '<S22>/Bias'
        //   Bias: '<S22>/Bias1'
        //   Constant: '<S22>/Constant2'
        //   Constant: '<S26>/Constant'
        //   Math: '<S22>/Math Function1'
        //   RelationalOperator: '<S26>/Compare'

        if (std::abs(rtb_Switch_b) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Switch_b + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S22>/Switch'

        // Sum: '<S10>/Sum1'
        rtb_Abs1 = rtu_StateFCU->RealUAVState.Latitude_deg - rtb_Switch;
        rtb_Sum1_idx_1 = rtu_StateFCU->RealUAVState.Longitude_deg - rtb_Switch_b;

        // Switch: '<S18>/Switch' incorporates:
        //   Abs: '<S18>/Abs'
        //   Bias: '<S18>/Bias'
        //   Bias: '<S18>/Bias1'
        //   Constant: '<S18>/Constant2'
        //   Constant: '<S19>/Constant'
        //   Math: '<S18>/Math Function1'
        //   RelationalOperator: '<S19>/Compare'

        if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch_b = rtb_Abs1;
        }

        // End of Switch: '<S18>/Switch'

        // Abs: '<S15>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch_b);

        // Switch: '<S15>/Switch' incorporates:
        //   Bias: '<S15>/Bias'
        //   Bias: '<S15>/Bias1'
        //   Constant: '<S11>/Constant'
        //   Constant: '<S11>/Constant1'
        //   Constant: '<S17>/Constant'
        //   Gain: '<S15>/Gain'
        //   Product: '<S15>/Divide1'
        //   RelationalOperator: '<S17>/Compare'
        //   Switch: '<S11>/Switch1'

        if (rtb_Abs1 > 90.0) {
            // Signum: '<S15>/Sign1'
            if (rtb_Switch_b < 0.0) {
                rtb_Switch_b = -1.0;
            } else if (rtb_Switch_b > 0.0) {
                rtb_Switch_b = 1.0;
            } else if (rtb_Switch_b == 0.0) {
                rtb_Switch_b = 0.0;
            } else {
                rtb_Switch_b = (rtNaN);
            }

            // End of Signum: '<S15>/Sign1'
            rtb_Switch_b *= -(rtb_Abs1 + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S15>/Switch'

        // Sum: '<S11>/Sum'
        rtb_Sum_k = static_cast<real_T>(i) + rtb_Sum1_idx_1;

        // Switch: '<S16>/Switch' incorporates:
        //   Abs: '<S16>/Abs'
        //   Bias: '<S16>/Bias'
        //   Bias: '<S16>/Bias1'
        //   Constant: '<S16>/Constant2'
        //   Constant: '<S20>/Constant'
        //   Math: '<S16>/Math Function1'
        //   RelationalOperator: '<S20>/Compare'

        if (std::abs(rtb_Sum_k) > 180.0) {
            rtb_Sum_k = rt_modd_snf(rtb_Sum_k + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S16>/Switch'

        // UnitConversion: '<S14>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Abs1 = 0.017453292519943295 * rtb_Switch_b;
        rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_k;

        // UnitConversion: '<S29>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch *= 0.017453292519943295;

        // Trigonometry: '<S30>/Trigonometric Function1'
        rtb_Sum_k = std::sin(rtb_Switch);

        // Sum: '<S30>/Sum1' incorporates:
        //   Constant: '<S30>/Constant'
        //   Product: '<S30>/Product1'

        rtb_Sum_k = 1.0 - 0.0066943799901413295 * rtb_Sum_k * rtb_Sum_k;

        // Product: '<S28>/Product1' incorporates:
        //   Constant: '<S28>/Constant1'
        //   Sqrt: '<S28>/sqrt'

        rtb_Switch_b = 6.378137E+6 / std::sqrt(rtb_Sum_k);

        // Product: '<S13>/dNorth' incorporates:
        //   Constant: '<S28>/Constant2'
        //   Product: '<S28>/Product3'
        //   Trigonometry: '<S28>/Trigonometric Function1'

        rtb_Sum_k = rtb_Abs1 / rt_atan2d_snf(1.0, rtb_Switch_b *
            0.99330562000985867 / rtb_Sum_k);

        // Product: '<S13>/dEast' incorporates:
        //   Constant: '<S28>/Constant3'
        //   Product: '<S28>/Product4'
        //   Trigonometry: '<S28>/Trigonometric Function'
        //   Trigonometry: '<S28>/Trigonometric Function2'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_b = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_b * std::cos
            (rtb_Switch)) * rtb_Sum1_idx_1;

        // BusCreator: '<S2>/FixedWingGuidanceStateBus' incorporates:
        //   Constant: '<S2>/dummyRollAngleRate'
        //   DataStoreRead: '<S2>/AltitudeGCS'
        //   Gain: '<S2>/inverse'
        //   Gain: '<S7>/Gain1'
        //   Gain: '<S8>/Gain1'
        //   Gain: '<S9>/Gain1'
        //   Product: '<S13>/x*cos'
        //   Product: '<S13>/x*sin'
        //   Product: '<S13>/y*cos'
        //   Product: '<S13>/y*sin'
        //   Sum: '<S10>/Sum'
        //   Sum: '<S13>/Sum2'
        //   Sum: '<S13>/Sum3'

        rty_outputRealUAVState->North = rtb_Switch_b * 0.0 + rtb_Sum_k;
        rty_outputRealUAVState->East = rtb_Switch_b - rtb_Sum_k * 0.0;
        rty_outputRealUAVState->Height = rtu_StateFCU->RealUAVState.Height_meter
            + -AltitudeGCS;
        rty_outputRealUAVState->AirSpeed =
            rtu_StateFCU->RealUAVState.AirSpeed_mps;
        rty_outputRealUAVState->HeadingAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.HeadingAngle_deg;
        rty_outputRealUAVState->FlightPathAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.FlightPathAngle_deg;
        rty_outputRealUAVState->RollAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.RollAngle_deg;
        rty_outputRealUAVState->RollAngleRate = 0.0;

        // SignalConversion generated from: '<Root>/SelectorStateFCU'
        *rty_outputGroundSpeed = rtu_StateFCU->GndSpd_mps;

        // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
        // Outputs for Atomic SubSystem: '<S4>/HeadingNaNProtection'
        // Memory: '<S60>/MemoryRefHeight'
        rtb_Switch = localDW->MemoryRefHeight_PreviousInput;

        // End of Outputs for SubSystem: '<S4>/HeadingNaNProtection'

        // Outputs for Atomic SubSystem: '<S4>/GenerateTrack'
        // S-Function (sfix_udelay): '<S58>/EastSequence'
        rtb_MatrixConcatenate[145] = rty_outputSimUAVState->East;

        // Gain: '<S58>/TrackInvH'
        localDW->TrackInvH = -rty_outputSimUAVState->Height;

        // S-Function (sfix_udelay): '<S58>/HeightSequence'
        rtb_MatrixConcatenate[218] = localDW->TrackInvH;
        for (i = 0; i < 72; i++) {
            // S-Function (sfix_udelay): '<S58>/EastSequence'
            rtb_MatrixConcatenate[static_cast<int_T>(i + 73)] =
                localDW->EastSequence_X[i];

            // S-Function (sfix_udelay): '<S58>/HeightSequence'
            rtb_MatrixConcatenate[static_cast<int_T>(i + 146)] =
                localDW->HeightSequence_X[i];

            // S-Function (sfix_udelay): '<S58>/NorthSequence'
            rtb_MatrixConcatenate[i] = localDW->NorthSequence_X[i];
        }

        // S-Function (sfix_udelay): '<S58>/NorthSequence'
        rtb_MatrixConcatenate[72] = rty_outputSimUAVState->North;

        // End of Outputs for SubSystem: '<S4>/GenerateTrack'

        // Sum: '<S4>/Minus'
        rtb_Switch_b = rty_outputRealUAVState->AirSpeed - *rty_outputGroundSpeed;

        // RelationalOperator: '<S62>/Compare' incorporates:
        //   Constant: '<S62>/Constant'
        //   DataStoreRead: '<S4>/ReadFlightMode_Log'

        localDW->Compare = (localDW->FlightMode_Log == 3.0);

        // Outputs for Atomic SubSystem: '<S4>/SpeedControl'
        // Sum: '<S69>/Sum'
        rtb_Sum_m_idx_0 = rty_outputSimUAVState->North -
            rty_outputRealUAVState->North;
        rtb_Sum_m_idx_1 = rty_outputSimUAVState->East -
            rty_outputRealUAVState->East;
        rtb_Sum_m_idx_2 = rty_outputSimUAVState->Height -
            rty_outputSimUAVState->Height;

        // DotProduct: '<S69>/Dot Product'
        rtb_Sum_k = rtb_Sum_m_idx_0 * rtb_Sum_m_idx_0;

        // Outputs for Atomic SubSystem: '<S4>/GenerateTrack'
        // Selector: '<S63>/WayPoint0d3' incorporates:
        //   S-Function (sfix_udelay): '<S58>/NorthSequence'
        //   Sum: '<S72>/Sum'

        rtb_Sum_m_idx_0 = rty_outputSimUAVState->North;

        // End of Outputs for SubSystem: '<S4>/GenerateTrack'

        // DotProduct: '<S69>/Dot Product'
        rtb_Sum_k += rtb_Sum_m_idx_1 * rtb_Sum_m_idx_1;

        // Selector: '<S63>/WayPoint0d3' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Sum: '<S72>/Sum'

        rtb_Sum_m_idx_1 = rtb_MatrixConcatenate[145];

        // DotProduct: '<S69>/Dot Product'
        rtb_Sum_k += rtb_Sum_m_idx_2 * rtb_Sum_m_idx_2;

        // Selector: '<S63>/WayPoint0d3' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Sum: '<S72>/Sum'

        rtb_Sum_m_idx_2 = rtb_MatrixConcatenate[218];

        // Sqrt: '<S69>/sqrt' incorporates:
        //   DotProduct: '<S69>/Dot Product'

        rtb_Abs1 = std::sqrt(rtb_Sum_k);

        // Gain: '<S63>/InverseY'
        localDW->InverseY = -rtb_Abs1;

        // Outputs for Atomic SubSystem: '<S4>/GenerateTrack'
        // Sum: '<S71>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   S-Function (sfix_udelay): '<S58>/NorthSequence'
        //   Selector: '<S63>/WayPoint2d3'

        y = rtb_MatrixConcatenate[24] - rty_outputSimUAVState->North;

        // End of Outputs for SubSystem: '<S4>/GenerateTrack'

        // DotProduct: '<S71>/Dot Product'
        rtb_Sum_g0_0 = y * y;

        // Sum: '<S71>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Selector: '<S63>/WayPoint0d3'
        //   Selector: '<S63>/WayPoint2d3'

        y = rtb_MatrixConcatenate[97] - rtb_MatrixConcatenate[145];

        // DotProduct: '<S71>/Dot Product'
        rtb_Sum_g0_0 += y * y;

        // Sum: '<S71>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Selector: '<S63>/WayPoint0d3'
        //   Selector: '<S63>/WayPoint2d3'

        y = rtb_MatrixConcatenate[170] - rtb_MatrixConcatenate[218];

        // Sqrt: '<S71>/sqrt' incorporates:
        //   DotProduct: '<S71>/Dot Product'

        rtb_Sum1_idx_1 = std::sqrt(y * y + rtb_Sum_g0_0);

        // Gain: '<S63>/InverseR'
        localDW->InverseR = -rtb_Sum1_idx_1;

        // End of Outputs for SubSystem: '<S4>/SpeedControl'
        // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    }

    // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S4>/SpeedControl'
    // Outputs for Atomic SubSystem: '<S63>/ADRC'
    // Outputs for Enabled SubSystem: '<S67>/ESO' incorporates:
    //   EnablePort: '<S73>/Enable'

    if (rtmIsMajorTimeStep(Real2SimGuidance_M) && rtmIsMajorTimeStep
            (Real2SimGuidance_M)) {
        if (localDW->Compare) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->ESO_MODE) ^ 1))) {
                // InitializeConditions for Integrator: '<S73>/ESO'
                localX->ESO_CSTATE = 0.0;

                // InitializeConditions for Integrator: '<S73>/ESO_dot'
                localX->ESO_dot_CSTATE = 0.0;

                // InitializeConditions for Integrator: '<S73>/ESO_dotdot'
                localX->ESO_dotdot_CSTATE = 0.0;
                localDW->ESO_MODE = true;
            }
        } else {
            localDW->ESO_MODE = false;
        }
    }

    if (localDW->ESO_MODE) {
        // Integrator: '<S73>/ESO'
        localDW->ESO = localX->ESO_CSTATE;

        // Integrator: '<S73>/ESO_dot'
        localDW->ESO_dot = localX->ESO_dot_CSTATE;

        // Integrator: '<S73>/ESO_dotdot'
        localDW->ESO_dotdot = localX->ESO_dotdot_CSTATE;
    }

    // End of Outputs for SubSystem: '<S67>/ESO'

    // Integrator: '<S75>/dotTD'
    localDW->dotTD = localX->dotTD_CSTATE;

    // MATLAB Function: '<S74>/fhan(e1,ce2,r,h1)' incorporates:
    //   Gain: '<S74>/Gain'
    //   Integrator: '<S75>/TD_AirSpdADRC'
    //   Sum: '<S67>/SumTD'
    //   Sum: '<S67>/SumTDdot'

    // MATLAB Function 'Real2SimNav/SpeedControl/ADRC/NLSEF/fhan(e1,ce2,r,h1)': '<S78>:1' 
    // '<S78>:1:3'
    // '<S78>:1:4'
    // '<S78>:1:5'
    // '<S78>:1:6'
    // '<S78>:1:8'
    // '<S78>:1:9'
    rtb_Sum_k = (localDW->dotTD - localDW->ESO_dot) * 3.375 * 7.001953125;

    // '<S78>:1:10'
    y = (localX->TD_AirSpdADRC_CSTATE - localDW->ESO) + rtb_Sum_k;

    // '<S78>:1:11'
    // '<S78>:1:12'
    if (y < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (y > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (y == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    a2 = (std::sqrt((8.0 * std::abs(y) + 490.27347564697266) *
                    490.27347564697266) - 490.27347564697266) * rtb_Sum_g0_0 /
        2.0 + rtb_Sum_k;

    // '<S78>:1:13'
    // '<S78>:1:14'
    if (y + 490.27347564697266 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (y + 490.27347564697266 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (y + 490.27347564697266 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    if (y - 490.27347564697266 < 0.0) {
        y_0 = -1.0;
    } else if (y - 490.27347564697266 > 0.0) {
        y_0 = 1.0;
    } else if (y - 490.27347564697266 == 0.0) {
        y_0 = 0.0;
    } else {
        y_0 = (rtNaN);
    }

    rtb_Sum_k = ((rtb_Sum_k + y) - a2) * ((rtb_Sum_g0_0 - y_0) / 2.0) + a2;

    // '<S78>:1:15'
    // '<S78>:1:17'
    if (rtb_Sum_k < 0.0) {
        y = -1.0;
    } else if (rtb_Sum_k > 0.0) {
        y = 1.0;
    } else if (rtb_Sum_k == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (rtb_Sum_k + 490.27347564697266 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (rtb_Sum_k + 490.27347564697266 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (rtb_Sum_k + 490.27347564697266 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    if (rtb_Sum_k - 490.27347564697266 < 0.0) {
        a2 = -1.0;
    } else if (rtb_Sum_k - 490.27347564697266 > 0.0) {
        a2 = 1.0;
    } else if (rtb_Sum_k - 490.27347564697266 == 0.0) {
        a2 = 0.0;
    } else {
        a2 = (rtNaN);
    }

    // Gain: '<S67>/GainADRCinvb0' incorporates:
    //   Gain: '<S74>/Gain1'
    //   MATLAB Function: '<S74>/fhan(e1,ce2,r,h1)'
    //   Sum: '<S67>/ESOpNLSEF'

    localDW->GainADRCinvb0 = (-((rtb_Sum_k / 490.27347564697266 - y) * -10.0 *
        ((rtb_Sum_g0_0 - a2) / 2.0) - 10.0 * y) - localDW->ESO_dotdot) *
        4.4444444444444446;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // ZeroOrderHold: '<S67>/ZOH_ADRC_U' incorporates:
        //   DataStoreWrite: '<S67>/WriteADRC_U_Log'

        localDW->ADRC_U_Log = localDW->GainADRCinvb0;

        // ZeroOrderHold: '<S67>/ZOH_ADRC_LagDis' incorporates:
        //   DataStoreWrite: '<S67>/WriteLagDistance'
        //   Integrator: '<S75>/TD_AirSpdADRC'
        //   Sum: '<S67>/LagDistanceSum'

        localDW->LagDistance = localX->TD_AirSpdADRC_CSTATE - localDW->InverseY;
    }

    // Sum: '<S67>/SumY'
    localDW->SumY = localDW->ESO - localDW->InverseY;

    // MATLAB Function: '<S75>/fhan_AirSpdADRC' incorporates:
    //   Integrator: '<S75>/TD_AirSpdADRC'
    //   SignalConversion generated from: '<S79>/ SFunction '
    //   Sum: '<S75>/Sum1'

    // MATLAB Function 'Real2SimNav/SpeedControl/ADRC/TD/fhan_AirSpdADRC': '<S79>:1' 
    // '<S79>:1:3'
    // '<S79>:1:4'
    // '<S79>:1:5'
    // '<S79>:1:6'
    // '<S79>:1:8'
    // '<S79>:1:9'
    rtb_Sum_k = localDW->dotTD * 0.1;

    // '<S79>:1:10'
    y = (localX->TD_AirSpdADRC_CSTATE - localDW->InverseR) + rtb_Sum_k;

    // '<S79>:1:11'
    // '<S79>:1:12'
    if (y < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (y > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (y == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    a2 = (std::sqrt((8.0 * std::abs(y) + 0.05) * 0.05) - 0.05) * rtb_Sum_g0_0 /
        2.0 + rtb_Sum_k;

    // '<S79>:1:13'
    // '<S79>:1:14'
    if (y + 0.05 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (y + 0.05 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (y + 0.05 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    if (y - 0.05 < 0.0) {
        y_0 = -1.0;
    } else if (y - 0.05 > 0.0) {
        y_0 = 1.0;
    } else if (y - 0.05 == 0.0) {
        y_0 = 0.0;
    } else {
        y_0 = (rtNaN);
    }

    rtb_Sum_k = ((rtb_Sum_k + y) - a2) * ((rtb_Sum_g0_0 - y_0) / 2.0) + a2;

    // '<S79>:1:15'
    // '<S79>:1:17'
    if (rtb_Sum_k < 0.0) {
        y = -1.0;
    } else if (rtb_Sum_k > 0.0) {
        y = 1.0;
    } else if (rtb_Sum_k == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (rtb_Sum_k + 0.05 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (rtb_Sum_k + 0.05 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (rtb_Sum_k + 0.05 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    if (rtb_Sum_k - 0.05 < 0.0) {
        a2 = -1.0;
    } else if (rtb_Sum_k - 0.05 > 0.0) {
        a2 = 1.0;
    } else if (rtb_Sum_k - 0.05 == 0.0) {
        a2 = 0.0;
    } else {
        a2 = (rtNaN);
    }

    localDW->fh_b = (rtb_Sum_k / 0.05 - y) * -5.0 * ((rtb_Sum_g0_0 - a2) / 2.0)
        - 5.0 * y;

    // End of MATLAB Function: '<S75>/fhan_AirSpdADRC'
    // End of Outputs for SubSystem: '<S63>/ADRC'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Sum: '<S70>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Selector: '<S63>/WayPoint1d3'
        //   Sum: '<S72>/Sum'

        y = rtb_MatrixConcatenate[48] - rtb_Sum_m_idx_0;

        // DotProduct: '<S70>/Dot Product'
        rtb_Sum_g0_0 = y * y;

        // Sum: '<S72>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Selector: '<S63>/WayPoint3d3'
        //   Sum: '<S70>/Sum'

        rtb_Sum_k = rtb_MatrixConcatenate[0] - rtb_Sum_m_idx_0;

        // DotProduct: '<S72>/Dot Product'
        rtb_UpperBound = rtb_Sum_k * rtb_Sum_k;

        // Sum: '<S70>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Selector: '<S63>/WayPoint1d3'
        //   Sum: '<S72>/Sum'

        y = rtb_MatrixConcatenate[121] - rtb_Sum_m_idx_1;

        // DotProduct: '<S70>/Dot Product'
        rtb_Sum_g0_0 += y * y;

        // Sum: '<S72>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Selector: '<S63>/WayPoint3d3'
        //   Sum: '<S70>/Sum'

        rtb_Sum_k = rtb_MatrixConcatenate[73] - rtb_Sum_m_idx_1;

        // DotProduct: '<S72>/Dot Product'
        rtb_UpperBound += rtb_Sum_k * rtb_Sum_k;

        // Sum: '<S70>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Selector: '<S63>/WayPoint1d3'
        //   Sum: '<S72>/Sum'

        y = rtb_MatrixConcatenate[194] - rtb_Sum_m_idx_2;

        // Sum: '<S72>/Sum' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   Selector: '<S63>/WayPoint3d3'
        //   Sum: '<S70>/Sum'

        rtb_Sum_k = rtb_MatrixConcatenate[146] - rtb_Sum_m_idx_2;

        // Sqrt: '<S70>/sqrt' incorporates:
        //   DotProduct: '<S70>/Dot Product'

        d = std::sqrt(y * y + rtb_Sum_g0_0);

        // Sum: '<S63>/ActRngmMinRng'
        rtb_Abs1 -= d;

        // Sum: '<S63>/RefRngmMinRng'
        rtb_RefRngmMinRng = rtb_Sum1_idx_1 - d;

        // Sum: '<S63>/ComputeLB'
        rtb_LowerBound = d - rtb_Sum1_idx_1;

        // Sum: '<S63>/ComputeUB' incorporates:
        //   DotProduct: '<S72>/Dot Product'
        //   Sqrt: '<S72>/sqrt'

        rtb_UpperBound = std::sqrt(rtb_Sum_k * rtb_Sum_k + rtb_UpperBound) -
            rtb_Sum1_idx_1;

        // Outputs for Enabled SubSystem: '<S63>/EnableBias' incorporates:
        //   EnablePort: '<S68>/Enable'

        // Math: '<S63>/Square' incorporates:
        //   Math: '<S68>/Square'

        rtb_Sum_k = rtb_RefRngmMinRng * rtb_RefRngmMinRng;

        // End of Outputs for SubSystem: '<S63>/EnableBias'

        // Product: '<S63>/DivideLB' incorporates:
        //   Bias: '<S63>/Bias'
        //   Math: '<S63>/Square'

        rtb_Sum1_idx_1 = rtb_Sum_k / (rtb_RefRngmMinRng + 10.0);

        // Switch: '<S63>/Switch' incorporates:
        //   RelationalOperator: '<S63>/GreaterThanOrEqual'

        if (rtb_Abs1 >= rtb_Sum1_idx_1) {
            // Switch: '<S63>/Switch'
            d = rtb_Abs1;
        } else {
            // Switch: '<S63>/Switch'
            d = rtb_Sum1_idx_1;
        }

        // End of Switch: '<S63>/Switch'

        // Outputs for Enabled SubSystem: '<S63>/EnableBias' incorporates:
        //   EnablePort: '<S68>/Enable'

        if (d > 0.0) {
            // Sum: '<S68>/biasHm70' incorporates:
            //   Product: '<S68>/Divide'

            localDW->biasHm70 = rtb_Sum_k / d - rtb_RefRngmMinRng;
        }

        // End of Outputs for SubSystem: '<S63>/EnableBias'

        // SignalConversion generated from: '<S63>/SimStateBus'
        d = rty_outputSimUAVState->AirSpeed;

        // Sum: '<S63>/SumSpd' incorporates:
        //   DataStoreWrite: '<S67>/WriteADRC_U_Log'
        //   SignalConversion generated from: '<S63>/SimStateBus'

        rtb_RefRngmMinRng = (rtb_Switch_b + localDW->ADRC_U_Log) +
            rty_outputSimUAVState->AirSpeed;

        // Outputs for Atomic SubSystem: '<S4>/HeadingLogic'
        // SignalConversion generated from: '<S59>/TrackSimPath'
        rty_outputRealUAVState_0[0] = rty_outputRealUAVState->North;
        rty_outputRealUAVState_0[1] = rty_outputRealUAVState->East;
        rty_outputRealUAVState_0[2] = rtb_Switch;
        rty_outputRealUAVState_0[3] = rty_outputRealUAVState->HeadingAngle;

        // MATLABSystem: '<S59>/TrackSimPath' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   DataStoreWrite: '<S59>/WriteCrossTrackError'
        //   DataStoreWrite: '<S59>/WriteStatus_Log'
        //   Gain: '<S4>/LookaheadT'
        //   SignalConversion generated from: '<S63>/SimStateBus'

        Real2SimGuidance_WaypointFollower_stepImpl(&localDW->obj,
            rty_outputRealUAVState_0, rtb_MatrixConcatenate, 3.6 *
            rty_outputSimUAVState->AirSpeed, rtb_SwitchLookAheadNED,
            &rtb_Switch_b, &rtb_Abs1, &b_varargout_4, &localDW->CrossTrackError,
            &localDW->HdgStatus_Log);

        // Switch: '<S59>/SwitchLookAheadNED' incorporates:
        //   Concatenate: '<S58>/Matrix Concatenate'
        //   DataStoreWrite: '<S59>/WriteStatus_Log'
        //   Selector: '<S59>/WayPoint3d3'
        //   Sum: '<S65>/EastArrow'
        //   Sum: '<S65>/NorthArrow'
        //   Switch: '<S59>/SwitchTargetHDG'
        //   Trigonometry: '<S65>/HdgCmd'

        if (static_cast<int32_T>(localDW->HdgStatus_Log) != 0) {
            rtb_SwitchLookAheadNED[0] = rtb_MatrixConcatenate[0];
            rtb_SwitchLookAheadNED[1] = rtb_MatrixConcatenate[73];
            rtb_SwitchLookAheadNED[2] = rtb_MatrixConcatenate[146];
            rtb_Switch_b = rt_atan2d_snf(rtb_MatrixConcatenate[73] -
                rty_outputRealUAVState->East, rtb_MatrixConcatenate[0] -
                rty_outputRealUAVState->North);
        }

        // End of Switch: '<S59>/SwitchLookAheadNED'
        // End of Outputs for SubSystem: '<S4>/HeadingLogic'

        // DataStoreWrite: '<S4>/WriteHeading_Log' incorporates:
        //   MATLAB Function: '<S4>/AngLog'

        // MATLAB Function 'Real2SimNav/AngLog': '<S56>:1'
        // '<S56>:1:2'
        // '<S56>:1:3'
        // '<S56>:1:4'
        localDW->Heading_Log[0] = angdiff_9SMt2WI9
            (rty_outputRealUAVState->HeadingAngle, rtb_Switch_b);
        localDW->Heading_Log[1] = angdiff_9SMt2WI9(0.0,
            rty_outputRealUAVState->HeadingAngle);
        localDW->Heading_Log[2] = angdiff_9SMt2WI9(0.0, rtb_Switch_b);
    }

    // End of Outputs for SubSystem: '<S4>/SpeedControl'

    // Integrator: '<S64>/TD_Alt' incorporates:
    //   DataStoreWrite: '<S4>/WritebiasH_Log'

    localDW->biasH_Log = localX->TD_Alt_CSTATE;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Truth Table: '<S4>/Engagement' incorporates:
        //   DataStoreRead: '<S4>/ReadLagDistance'
        //   DataStoreWrite: '<S59>/WriteCrossTrackError'

        // Truth Table Function 'Real2SimNav/Engagement': '<S57>:1'
        //  Front Distance within Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_UpperBound) & (localDW->LagDistance > rtb_LowerBound)))) {
            // Condition '#1': '<S57>:1:9'
            rtb_Compare_i = true;
        } else {
            rtb_Compare_i = false;
        }

        //  CrossTrack Error within 1.5 Second Bound
        // Condition '#2': '<S57>:1:13'
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((localDW->CrossTrackError < d * 1.5) &
                                    static_cast<int32_T>(rtb_Compare_i)))) {
            // Decision 'D1': '<S57>:1:15'
            //  Real UAV Engaged with Simulation UAV
            // Action '1': '<S57>:1:25'
            localDW->Engaged = true;
        } else {
            // Decision 'D2': '<S57>:1:17'
            //  Default
            //  Real UAV Not Engaged with Simulation UAV
            // Action '2': '<S57>:1:31'
            localDW->Engaged = false;
        }

        // End of Truth Table: '<S4>/Engagement'

        // Outputs for Atomic SubSystem: '<S4>/MaxBrake'
        // Product: '<S61>/BrkRng' incorporates:
        //   Constant: '<S61>/SampleTime'
        //   Constant: '<S61>/TrackDP'

        rtb_Abs1 = rty_outputSimUAVState->AirSpeed * 0.1 * 72.0;

        // Gain: '<S61>/Half'
        d = 0.5 * rtb_Abs1;

        // Sum: '<S66>/Sum' incorporates:
        //   Gain: '<S61>/Up2Down'
        //   Product: '<S61>/EastDisBrk'
        //   Product: '<S61>/NorthDisBrk'
        //   Sum: '<S61>/SumEastBrk'
        //   Sum: '<S61>/SumNorthBrk'
        //   Trigonometry: '<S61>/East'
        //   Trigonometry: '<S61>/North'

        rtb_Sum_g0_idx_0 = (std::cos(rty_outputSimUAVState->HeadingAngle) * d +
                            rty_outputSimUAVState->North) -
            rty_outputRealUAVState->North;
        rtb_Switch_b = (std::sin(rty_outputSimUAVState->HeadingAngle) * d +
                        rty_outputSimUAVState->East) -
            rty_outputRealUAVState->East;
        rtb_Switch = -rty_outputSimUAVState->Height - rtb_Switch;

        // End of Outputs for SubSystem: '<S4>/MaxBrake'

        // Gain: '<S4>/NED2NEU' incorporates:
        //   Switch: '<S59>/SwitchLookAheadNED'

        localDW->NorthEastHeight[0] = rtb_SwitchLookAheadNED[0];
        localDW->NorthEastHeight[1] = rtb_SwitchLookAheadNED[1];
        localDW->NorthEastHeight[2] = -rtb_SwitchLookAheadNED[2];

        // ZeroOrderHold: '<S4>/LookaheadPoint_ZOH' incorporates:
        //   DataStoreWrite: '<S4>/WritebiasH_Log'
        //   Gain: '<S4>/NED2NEU'
        //   Sum: '<S4>/SumBiasH'

        rtb_RealUAVNEUState_idx_0 = localDW->NorthEastHeight[0];
        rtb_RealUAVNEUState_idx_1 = localDW->NorthEastHeight[1];
        rtb_RealUAVNEUState_idx_2 = localDW->NorthEastHeight[2] +
            localDW->biasH_Log;

        // Outputs for Atomic SubSystem: '<S4>/MaxBrake'
        // RelationalOperator: '<S61>/GreaterThanOrEqual' incorporates:
        //   DotProduct: '<S66>/Dot Product'
        //   Sqrt: '<S66>/sqrt'

        rtb_Compare_i = (std::sqrt((rtb_Sum_g0_idx_0 * rtb_Sum_g0_idx_0 +
                           rtb_Switch_b * rtb_Switch_b) + rtb_Switch *
                          rtb_Switch) >= rtb_Abs1);

        // Switch: '<S61>/BrkSwitch' incorporates:
        //   Constant: '<S61>/MaxBrake'

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rtb_Compare_i) ^ 1))) {
            rtb_RefRngmMinRng = 0.0;
        }

        // End of Switch: '<S61>/BrkSwitch'

        // Saturate: '<S61>/SpeedProtection'
        if (rtb_RefRngmMinRng > 41.0) {
            rtb_Sum_g0_idx_0 = 41.0;
        } else if (rtb_RefRngmMinRng < 29.0) {
            rtb_Sum_g0_idx_0 = 29.0;
        } else {
            rtb_Sum_g0_idx_0 = rtb_RefRngmMinRng;
        }

        // End of Saturate: '<S61>/SpeedProtection'
        // End of Outputs for SubSystem: '<S4>/MaxBrake'
    }

    // Switch: '<S4>/BiasHSwitch' incorporates:
    //   Constant: '<S4>/ZeroBias'

    if (localDW->Engaged) {
        rtb_LowerBound = 0.0;
    } else {
        // Product: '<S4>/Product'
        rtb_LowerBound = localDW->biasHm70 * *rtu_BiasRatio;
    }

    // End of Switch: '<S4>/BiasHSwitch'

    // Integrator: '<S64>/dotAltTD'
    localDW->dotAltTD = localX->dotAltTD_CSTATE;

    // MATLAB Function: '<S64>/fhan_Alt' incorporates:
    //   DataStoreWrite: '<S4>/WritebiasH_Log'
    //   SignalConversion generated from: '<S80>/ SFunction '
    //   Sum: '<S64>/Sum1'

    // MATLAB Function 'Real2SimNav/TD/fhan_Alt': '<S80>:1'
    // '<S80>:1:3'
    // '<S80>:1:4'
    // '<S80>:1:5'
    // '<S80>:1:6'
    // '<S80>:1:8'
    // '<S80>:1:9'
    rtb_Sum_k = localDW->dotAltTD * 0.1;

    // '<S80>:1:10'
    y = (localDW->biasH_Log - rtb_LowerBound) + rtb_Sum_k;

    // '<S80>:1:11'
    // '<S80>:1:12'
    if (y < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (y > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (y == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    a2 = (std::sqrt((8.0 * std::abs(y) + 0.004000000000000001) *
                    0.004000000000000001) - 0.004000000000000001) * rtb_Sum_g0_0
        / 2.0 + rtb_Sum_k;

    // '<S80>:1:13'
    // '<S80>:1:14'
    if (y + 0.004000000000000001 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (y + 0.004000000000000001 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (y + 0.004000000000000001 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    if (y - 0.004000000000000001 < 0.0) {
        y_0 = -1.0;
    } else if (y - 0.004000000000000001 > 0.0) {
        y_0 = 1.0;
    } else if (y - 0.004000000000000001 == 0.0) {
        y_0 = 0.0;
    } else {
        y_0 = (rtNaN);
    }

    rtb_Sum_k = ((rtb_Sum_k + y) - a2) * ((rtb_Sum_g0_0 - y_0) / 2.0) + a2;

    // '<S80>:1:15'
    // '<S80>:1:17'
    if (rtb_Sum_k < 0.0) {
        rtb_LowerBound = -1.0;
    } else if (rtb_Sum_k > 0.0) {
        rtb_LowerBound = 1.0;
    } else if (rtb_Sum_k == 0.0) {
        rtb_LowerBound = 0.0;
    } else {
        rtb_LowerBound = (rtNaN);
    }

    if (rtb_Sum_k + 0.004000000000000001 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (rtb_Sum_k + 0.004000000000000001 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (rtb_Sum_k + 0.004000000000000001 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    if (rtb_Sum_k - 0.004000000000000001 < 0.0) {
        a2 = -1.0;
    } else if (rtb_Sum_k - 0.004000000000000001 > 0.0) {
        a2 = 1.0;
    } else if (rtb_Sum_k - 0.004000000000000001 == 0.0) {
        a2 = 0.0;
    } else {
        a2 = (rtNaN);
    }

    localDW->fh = (rtb_Sum_k / 0.004000000000000001 - rtb_LowerBound) * -0.4 *
        ((rtb_Sum_g0_0 - a2) / 2.0) - 0.4 * rtb_LowerBound;

    // End of MATLAB Function: '<S64>/fhan_Alt'
    // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Product: '<Root>/Product' incorporates:
        //   DataStoreWrite: '<Root>/WriteFlightMode_Log'

        localDW->FlightMode_Log = rtb_CastToDouble * static_cast<real_T>
            (*rtu_FlightMode) * static_cast<real_T>(rtb_NoNewMission) *
            static_cast<real_T>(rtb_Compare_i);

        // Chart: '<Root>/TASgreaterthan15for1Sec'
        // Gateway: TASgreaterthan15for1Sec
        // During: TASgreaterthan15for1Sec
        if (static_cast<uint32_T>(localDW->is_active_c16_Real2SimGuidance) == 0U)
        {
            // Entry: TASgreaterthan15for1Sec
            localDW->is_active_c16_Real2SimGuidance = 1U;

            // Entry Internal: TASgreaterthan15for1Sec
            // Transition: '<S5>:3'
            localDW->durationCounter_1 = 0;
            localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NotTakeOff;

            // Entry 'NotTakeOff': '<S5>:2'
            rtb_NoNewMission = false;
        } else if (static_cast<int32_T>(localDW->is_c16_Real2SimGuidance) == 1)
        {
            // During 'InAir': '<S5>:4'
            rtb_NoNewMission = true;
        } else {
            // During 'NotTakeOff': '<S5>:2'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    ((rty_outputRealUAVState->AirSpeed > 15.0) ^ 1))) |
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>
                     ((rtu_StateFCU->RealUAVState.Height_meter > 30.0) ^ 1))))))
            {
                localDW->durationCounter_1 = 0;
            } else {
                // '<S5>:5:1'
            }

            if (localDW->durationCounter_1 > 10) {
                // Transition: '<S5>:5'
                localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_InAir;

                // Entry 'InAir': '<S5>:4'
                rtb_NoNewMission = true;
            } else {
                rtb_NoNewMission = false;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((rty_outputRealUAVState->AirSpeed > 15.0) &
                                    (rtu_StateFCU->RealUAVState.Height_meter >
                30.0)))) {
            // '<S5>:5:1'
            localDW->durationCounter_1 = static_cast<int32_T>
                (localDW->durationCounter_1 + 1);
        } else {
            localDW->durationCounter_1 = 0;
        }

        // End of Chart: '<Root>/TASgreaterthan15for1Sec'

        // Logic: '<Root>/AND'
        *rty_outputEngagedFlag = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(localDW->Engaged) & static_cast<int32_T>
            (rtb_NoNewMission)));

        // Chart: '<Root>/TriggerTermination' incorporates:
        //   DataStoreWrite: '<Root>/WriteFlightMode_Log'

        if (static_cast<uint32_T>(localDW->temporalCounter_i1) < 1023U) {
            localDW->temporalCounter_i1 = static_cast<uint16_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i1) + 1U));
        }

        if (static_cast<uint32_T>(localDW->temporalCounter_i2) < 63U) {
            localDW->temporalCounter_i2 = static_cast<uint8_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i2) + 1U));
        }

        // Gateway: TriggerTermination
        // During: TriggerTermination
        if (static_cast<uint32_T>(localDW->is_active_c34_Real2SimGuidance) == 0U)
        {
            // Entry: TriggerTermination
            localDW->is_active_c34_Real2SimGuidance = 1U;

            // Entry Internal: TriggerTermination
            // Transition: '<S6>:105'
            localDW->is_c34_Real2SimGuidance =
                Real2SimGuidance_IN_DebounceExecution;

            // Entry 'DebounceExecution': '<S6>:104'
            localDW->Terminate = false;

            // Entry Internal 'DebounceExecution': '<S6>:104'
            // Transition: '<S6>:97'
            localDW->is_DebounceExecution = Real2SimGuidance_IN_Persuit;

            // Entry 'Persuit': '<S6>:95'
            // Entry Internal 'Persuit': '<S6>:95'
            // Transition: '<S6>:100'
            localDW->is_Persuit = Real2SimGuidance_IN_Normal;
        } else {
            switch (localDW->is_c34_Real2SimGuidance) {
              case Real2SimGuidance_IN_DebounceExecution:
                // During 'DebounceExecution': '<S6>:104'
                if (localDW->FlightMode_Log == 6.0) {
                    // Transition: '<S6>:18'
                    // Exit Internal 'DebounceExecution': '<S6>:104'
                    // Exit Internal 'Debounce': '<S6>:90'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

                    // Exit Internal 'Persuit': '<S6>:95'
                    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_DebounceExecution =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Landing;

                    // Entry 'Landing': '<S6>:22'
                } else {
                    localDW->Terminate = false;
                    switch (localDW->is_DebounceExecution) {
                      case Real2SimGuidance_IN_Debounce:
                        // During 'Debounce': '<S6>:90'
                        if (static_cast<uint32_T>(localDW->temporalCounter_i1) >=
                            180U) {
                            // Transition: '<S6>:93'
                            // Exit Internal 'Debounce': '<S6>:90'
                            localDW->is_Debounce =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_DebounceExecution =
                                Real2SimGuidance_IN_Persuit;

                            // Entry 'Persuit': '<S6>:95'
                            localDW->is_Persuit = Real2SimGuidance_IN_Fault;
                            localDW->temporalCounter_i1 = 0U;

                            // Entry 'Fault': '<S6>:94'
                        } else if (static_cast<int32_T>(localDW->is_Debounce) ==
                                   1) {
                            // During 'Off': '<S6>:103'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i2) >= 60U) {
                                // Transition: '<S6>:87'
                                localDW->is_Debounce =
                                    Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                                localDW->is_DebounceExecution =
                                    Real2SimGuidance_IN_Persuit;

                                // Entry 'Persuit': '<S6>:95'
                                // Entry Internal 'Persuit': '<S6>:95'
                                // Transition: '<S6>:100'
                                localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                            } else if (static_cast<boolean_T>
                                       (static_cast<int32_T>(static_cast<int32_T>
                                    (rtb_NoNewMission) & static_cast<int32_T>
                                         (*rty_outputEngagedFlag)))) {
                                // Transition: '<S6>:102'
                                localDW->is_Debounce = Real2SimGuidance_IN_On;
                                localDW->temporalCounter_i2 = 0U;
                            }

                            // During 'On': '<S6>:92'
                        } else if (static_cast<uint32_T>
                                   (localDW->temporalCounter_i2) >= 60U) {
                            // Transition: '<S6>:99'
                            localDW->is_Debounce =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_DebounceExecution =
                                Real2SimGuidance_IN_Engaged;

                            // Entry 'Engaged': '<S6>:101'
                        } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                     static_cast<int32_T>(*rty_outputEngagedFlag)
                                     ^ 1))) {
                            // Transition: '<S6>:96'
                            localDW->is_Debounce = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2 = 0U;
                        }
                        break;

                      case Real2SimGuidance_IN_Engaged:
                        // During 'Engaged': '<S6>:101'
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(*rty_outputEngagedFlag) ^ 1)))
                        {
                            // Transition: '<S6>:91'
                            localDW->is_DebounceExecution =
                                Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1 = 0U;
                            localDW->is_Debounce = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2 = 0U;
                        }
                        break;

                      default:
                        // During 'Persuit': '<S6>:95'
                        if (static_cast<int32_T>(localDW->is_Persuit) == 1) {
                            // During 'Fault': '<S6>:94'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i1) >= 600U) {
                                // Transition: '<S6>:89'
                                localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                            }

                            // During 'Normal': '<S6>:88'
                        } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                     static_cast<int32_T>(rtb_NoNewMission) |
                                     static_cast<int32_T>(*rty_outputEngagedFlag))))
                        {
                            // Transition: '<S6>:98'
                            localDW->is_Persuit =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_DebounceExecution =
                                Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1 = 0U;
                            localDW->is_Debounce = Real2SimGuidance_IN_On;
                            localDW->temporalCounter_i2 = 0U;
                        }
                        break;
                    }
                }
                break;

              case Real2SimGuidance_IN_Landing:
                // During 'Landing': '<S6>:22'
                if (rtu_StateFCU->RealUAVState.Height_meter < 30.0) {
                    // Transition: '<S6>:23'
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_MissionCompletion;

                    // Entry 'MissionCompletion': '<S6>:14'
                    localDW->Terminate = true;
                }
                break;

              default:
                // During 'MissionCompletion': '<S6>:14'
                localDW->Terminate = true;
                break;
            }
        }

        // End of Chart: '<Root>/TriggerTermination'

        // Stop: '<Root>/Stop Simulation'
        if (localDW->Terminate) {
            rtmSetStopRequested(Real2SimGuidance_M, 1);
        }

        // End of Stop: '<Root>/Stop Simulation'

        // Switch: '<Root>/SwitchLookAheadPoint' incorporates:
        //   ZeroOrderHold: '<S4>/LookaheadPoint_ZOH'

        if (rtu_ControlSwitch[0]) {
            // Sum: '<Root>/SumNorth' incorporates:
            //   Constant: '<Root>/LookAheadDis'
            //   Product: '<Root>/ProductNorth'
            //   Trigonometry: '<Root>/Cos'

            rtb_SumNorth = std::cos(rtu_ImmedGuidanceCMD->HeadingAngle) * 1000.0
                + rty_outputRealUAVState->North;

            // Sum: '<Root>/SumEast' incorporates:
            //   Constant: '<Root>/LookAheadDis'
            //   Product: '<Root>/ProductEast'
            //   Trigonometry: '<Root>/Sin'

            rtb_SumEast = 1000.0 * std::sin(rtu_ImmedGuidanceCMD->HeadingAngle)
                + rty_outputRealUAVState->East;
            rty_outputLookAheadNED[0] = rtb_SumNorth;
            rty_outputLookAheadNED[1] = rtb_SumEast;
            rty_outputLookAheadNED[2] = rtu_ImmedGuidanceCMD->Height;
        } else {
            rty_outputLookAheadNED[0] = rtb_RealUAVNEUState_idx_0;
            rty_outputLookAheadNED[1] = rtb_RealUAVNEUState_idx_1;
            rty_outputLookAheadNED[2] = rtb_RealUAVNEUState_idx_2;
        }

        // End of Switch: '<Root>/SwitchLookAheadPoint'

        // Switch: '<S47>/Switch' incorporates:
        //   Abs: '<S47>/Abs'
        //   Bias: '<S47>/Bias'
        //   Bias: '<S47>/Bias1'
        //   Constant: '<S47>/Constant2'
        //   Constant: '<S48>/Constant'
        //   DataStoreRead: '<S3>/LatitudeGCS'
        //   Math: '<S47>/Math Function1'
        //   RelationalOperator: '<S48>/Compare'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        if (std::abs(LatitudeGCS) > 180.0) {
            d = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
            d = LatitudeGCS;
        }

        // End of Switch: '<S47>/Switch'

        // Abs: '<S44>/Abs1'
        rtb_CastToDouble = std::abs(d);

        // Switch: '<S44>/Switch' incorporates:
        //   Bias: '<S44>/Bias'
        //   Bias: '<S44>/Bias1'
        //   Constant: '<S35>/Constant'
        //   Constant: '<S35>/Constant1'
        //   Constant: '<S46>/Constant'
        //   Gain: '<S44>/Gain'
        //   Product: '<S44>/Divide1'
        //   RelationalOperator: '<S46>/Compare'
        //   Switch: '<S35>/Switch1'

        if (rtb_CastToDouble > 90.0) {
            // Signum: '<S44>/Sign1'
            if (d < 0.0) {
                d = -1.0;
            } else if (d > 0.0) {
                d = 1.0;
            } else if (d == 0.0) {
                d = 0.0;
            } else {
                d = (rtNaN);
            }

            // End of Signum: '<S44>/Sign1'
            d *= -(rtb_CastToDouble + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S44>/Switch'

        // UnitConversion: '<S52>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum_k = 0.017453292519943295 * d;

        // Trigonometry: '<S53>/Trigonometric Function1'
        rtb_Switch_b = std::sin(rtb_Sum_k);

        // Sum: '<S53>/Sum1' incorporates:
        //   Constant: '<S53>/Constant'
        //   Product: '<S53>/Product1'

        rtb_Switch_b = 1.0 - 0.0066943799901413295 * rtb_Switch_b * rtb_Switch_b;

        // Product: '<S50>/Product1' incorporates:
        //   Constant: '<S50>/Constant1'
        //   Sqrt: '<S50>/sqrt'

        rtb_Switch = 6.378137E+6 / std::sqrt(rtb_Switch_b);

        // Sum: '<S35>/Sum' incorporates:
        //   DataStoreRead: '<S3>/LongitudeGCS'

        // Unit Conversion - from: rad to: deg
        // Expression: output = (57.2958*input) + (0)
        rtb_Abs1 = static_cast<real_T>(i) + LongitudeGCS;

        // Switch: '<S45>/Switch' incorporates:
        //   Abs: '<S45>/Abs'
        //   Bias: '<S45>/Bias'
        //   Bias: '<S45>/Bias1'
        //   Constant: '<S45>/Constant2'
        //   Constant: '<S49>/Constant'
        //   Math: '<S45>/Math Function1'
        //   RelationalOperator: '<S49>/Compare'

        if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S45>/Switch'

        // Sum: '<S33>/Sum' incorporates:
        //   Constant: '<S50>/Constant2'
        //   Constant: '<S50>/Constant3'
        //   Product: '<S36>/rad lat'
        //   Product: '<S36>/rad long '
        //   Product: '<S36>/x*cos'
        //   Product: '<S36>/x*sin'
        //   Product: '<S36>/y*cos'
        //   Product: '<S36>/y*sin'
        //   Product: '<S50>/Product3'
        //   Product: '<S50>/Product4'
        //   Sum: '<S36>/Sum'
        //   Sum: '<S36>/Sum1'
        //   Trigonometry: '<S50>/Trigonometric Function'
        //   Trigonometry: '<S50>/Trigonometric Function1'
        //   Trigonometry: '<S50>/Trigonometric Function2'
        //   UnitConversion: '<S37>/Unit Conversion'

        rtb_CastToDouble = (rty_outputLookAheadNED[0] - rty_outputLookAheadNED[1]
                            * 0.0) * rt_atan2d_snf(1.0, rtb_Switch *
            0.99330562000985867 / rtb_Switch_b) * 57.295779513082323 + d;
        rtb_Switch = (rty_outputLookAheadNED[0] * 0.0 + rty_outputLookAheadNED[1])
            * rt_atan2d_snf(1.0, rtb_Switch * std::cos(rtb_Sum_k)) *
            57.295779513082323 + rtb_Abs1;

        // Switch: '<S41>/Switch' incorporates:
        //   Abs: '<S41>/Abs'
        //   Bias: '<S41>/Bias'
        //   Bias: '<S41>/Bias1'
        //   Constant: '<S41>/Constant2'
        //   Constant: '<S42>/Constant'
        //   Math: '<S41>/Math Function1'
        //   RelationalOperator: '<S42>/Compare'

        if (std::abs(rtb_CastToDouble) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_CastToDouble + 180.0, 360.0) + -180.0;
        } else {
            rtb_Abs1 = rtb_CastToDouble;
        }

        // End of Switch: '<S41>/Switch'

        // Abs: '<S38>/Abs1'
        rtb_CastToDouble = std::abs(rtb_Abs1);

        // Switch: '<S38>/Switch' incorporates:
        //   Bias: '<S38>/Bias'
        //   Bias: '<S38>/Bias1'
        //   Constant: '<S34>/Constant'
        //   Constant: '<S34>/Constant1'
        //   Constant: '<S40>/Constant'
        //   Gain: '<S38>/Gain'
        //   Product: '<S38>/Divide1'
        //   RelationalOperator: '<S40>/Compare'
        //   Switch: '<S34>/Switch1'

        if (rtb_CastToDouble > 90.0) {
            // Signum: '<S38>/Sign1'
            if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
            } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
            } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
            } else {
                rtb_Abs1 = (rtNaN);
            }

            // End of Signum: '<S38>/Sign1'
            rtb_Abs1 *= -(rtb_CastToDouble + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S38>/Switch'

        // Sum: '<S34>/Sum'
        rtb_Sum1_idx_1 = static_cast<real_T>(i) + rtb_Switch;

        // Switch: '<S39>/Switch' incorporates:
        //   Abs: '<S39>/Abs'
        //   Bias: '<S39>/Bias'
        //   Bias: '<S39>/Bias1'
        //   Constant: '<S39>/Constant2'
        //   Constant: '<S43>/Constant'
        //   Math: '<S39>/Math Function1'
        //   RelationalOperator: '<S43>/Compare'

        if (std::abs(rtb_Sum1_idx_1) > 180.0) {
            rtb_Sum1_idx_1 = rt_modd_snf(rtb_Sum1_idx_1 + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S39>/Switch'

        // Sum: '<S33>/Sum1' incorporates:
        //   DataStoreRead: '<S3>/AltitudeGCS'
        //   Gain: '<S3>/Up2Down'
        //   Gain: '<S3>/inverse'

        rty_FCUCMD->Height_meter = rty_outputLookAheadNED[2] - (-AltitudeGCS);

        // Switch: '<Root>/SwitchSpdControl'
        if (rtu_ControlSwitch[1]) {
            *rty_outputRefAirspeed = rtu_ImmedGuidanceCMD->AirSpeed;
        } else {
            *rty_outputRefAirspeed = rtb_Sum_g0_idx_0;
        }

        // End of Switch: '<Root>/SwitchSpdControl'

        // BusCreator: '<Root>/FcuCmdBus'
        rty_FCUCMD->Latitude_deg = rtb_Abs1;
        rty_FCUCMD->Longitude_deg = rtb_Sum1_idx_1;
        rty_FCUCMD->RefAirSpd_mps = *rty_outputRefAirspeed;

        // SignalConversion generated from: '<Root>/SelectorStateFCU'
        *rty_outputVectorSpd = rtu_StateFCU->VecSpd;

        // Trigonometry: '<S1>/Atan2'
        *rty_outputFlightPath = rt_atan2d_snf(rty_outputVectorSpd->skySpeed,
            *rty_outputGroundSpeed);

        // SignalConversion generated from: '<Root>/EngagedFlag'
        *rty_EngagedFlag = *rty_outputEngagedFlag;

        // SignalConversion generated from: '<Root>/SelectorStateFCU'
        *rty_outputAltitude = rtu_StateFCU->Altitude;

        // DataStoreRead: '<Root>/ReadLagDistance'
        *rty_outputLagDistance = localDW->LagDistance;

        // DataStoreRead: '<Root>/ReadCrossTrackError'
        *rty_outputCrossTrackError = localDW->CrossTrackError;

        // DataStoreRead: '<Root>/ReadHeading_Log'
        rty_outputHeading[0] = localDW->Heading_Log[0];
        rty_outputHeading[1] = localDW->Heading_Log[1];
        rty_outputHeading[2] = localDW->Heading_Log[2];

        // DataStoreRead: '<Root>/ReadADRC_U_Log'
        *rty_outputADRC_U = localDW->ADRC_U_Log;

        // DataStoreRead: '<Root>/ReadbiasH_Log'
        *rty_outputbiasH = localDW->biasH_Log;

        // DataStoreRead: '<Root>/ReadFlightMode_Log'
        *rty_outputFlightMode = localDW->FlightMode_Log;

        // DataStoreRead: '<Root>/ReadStatus_Log'
        *rty_outputHdgStatus = localDW->HdgStatus_Log;
    }
}

// Update for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, FixedWingGuidanceStateBus *rty_outputSimUAVState,
    DW_Real2SimGuidance_f_T *localDW)
{
    // Update for Atomic SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Update for Atomic SubSystem: '<S4>/HeadingNaNProtection'
        // Switch: '<S60>/HeightSwitch' incorporates:
        //   Gain: '<S60>/Height2Down'
        //   RelationalOperator: '<S60>/IsNaN'

        if (std::isnan(-localDW->NorthEastHeight[2])) {
            // Update for Memory: '<S60>/MemoryRefHeight' incorporates:
            //   Constant: '<S60>/DefaultHeight'

            localDW->MemoryRefHeight_PreviousInput = -150.0;
        } else {
            // Update for Memory: '<S60>/MemoryRefHeight'
            localDW->MemoryRefHeight_PreviousInput = -localDW->NorthEastHeight[2];
        }

        // End of Switch: '<S60>/HeightSwitch'
        // End of Update for SubSystem: '<S4>/HeadingNaNProtection'

        // Update for Atomic SubSystem: '<S4>/GenerateTrack'
        for (int_T i{0}; i < 71; i++) {
            // Update for S-Function (sfix_udelay): '<S58>/EastSequence'
            localDW->EastSequence_X[i] = localDW->EastSequence_X
                [static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S58>/HeightSequence'
            localDW->HeightSequence_X[i] = localDW->HeightSequence_X[
                static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S58>/NorthSequence'
            localDW->NorthSequence_X[i] = localDW->NorthSequence_X
                [static_cast<int_T>(i + 1)];
        }

        // Update for S-Function (sfix_udelay): '<S58>/EastSequence'
        localDW->EastSequence_X[71] = rty_outputSimUAVState->East;

        // Update for S-Function (sfix_udelay): '<S58>/HeightSequence'
        localDW->HeightSequence_X[71] = localDW->TrackInvH;

        // Update for S-Function (sfix_udelay): '<S58>/NorthSequence'
        localDW->NorthSequence_X[71] = rty_outputSimUAVState->North;

        // End of Update for SubSystem: '<S4>/GenerateTrack'
    }

    // End of Update for SubSystem: '<Root>/Real2SimNav'
}

// Derivatives for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot)
{
    // Derivatives for Atomic SubSystem: '<Root>/Real2SimNav'
    // Derivatives for Atomic SubSystem: '<S4>/SpeedControl'
    // Derivatives for Atomic SubSystem: '<S63>/ADRC'
    // Derivatives for Integrator: '<S75>/TD_AirSpdADRC'
    localXdot->TD_AirSpdADRC_CSTATE = localDW->dotTD;

    // Derivatives for Enabled SubSystem: '<S67>/ESO'
    if (localDW->ESO_MODE) {
        real_T y;
        real_T y_n;

        // MATLAB Function: '<S73>/fal(e,0.5,h)' incorporates:
        //   MATLAB Function: '<S73>/fal(e,0.25,h)'
        //   SignalConversion generated from: '<S76>/ SFunction '
        //   SignalConversion generated from: '<S77>/ SFunction '

        // MATLAB Function 'Real2SimNav/SpeedControl/ADRC/ESO/fal(e,0.5,h)': '<S77>:1' 
        // '<S77>:1:3'
        // '<S77>:1:4'
        // '<S77>:1:5'
        y_n = std::abs(localDW->SumY);
        if (y_n <= 0.1) {
            // '<S77>:1:7'
            // '<S77>:1:8'
            y = localDW->SumY / 0.31622776601683794;

            // '<S76>:1:7'
            // '<S76>:1:8'
            y_n = localDW->SumY / 0.17782794100389229;
        } else {
            real_T tmp;

            // '<S77>:1:10'
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

            // '<S76>:1:10'
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

        // End of MATLAB Function: '<S73>/fal(e,0.5,h)'

        // Derivatives for Integrator: '<S73>/ESO' incorporates:
        //   Gain: '<S73>/beta_01'
        //   Sum: '<S73>/ESOdotsum'

        // MATLAB Function 'Real2SimNav/SpeedControl/ADRC/ESO/fal(e,0.25,h)': '<S76>:1' 
        // '<S76>:1:3'
        // '<S76>:1:4'
        // '<S76>:1:5'
        localXdot->ESO_CSTATE = localDW->ESO_dot - 15.0 * localDW->SumY;

        // Derivatives for Integrator: '<S73>/ESO_dot' incorporates:
        //   Gain: '<S73>/Gain1'
        //   Gain: '<S73>/Gain4'
        //   Sum: '<S73>/ESOdotdotsum'

        localXdot->ESO_dot_CSTATE = (0.225 * localDW->GainADRCinvb0 +
            localDW->ESO_dotdot) - 75.0 * y;

        // Derivatives for Integrator: '<S73>/ESO_dotdot' incorporates:
        //   Gain: '<S73>/Gain'
        //   Gain: '<S73>/Inverse'

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

    // End of Derivatives for SubSystem: '<S67>/ESO'

    // Derivatives for Integrator: '<S75>/dotTD'
    localXdot->dotTD_CSTATE = localDW->fh_b;

    // End of Derivatives for SubSystem: '<S63>/ADRC'
    // End of Derivatives for SubSystem: '<S4>/SpeedControl'

    // Derivatives for Integrator: '<S64>/TD_Alt'
    localXdot->TD_Alt_CSTATE = localDW->dotAltTD;

    // Derivatives for Integrator: '<S64>/dotAltTD'
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
