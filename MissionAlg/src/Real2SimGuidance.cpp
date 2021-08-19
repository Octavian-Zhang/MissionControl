#include "Real2SimGuidance.h"
#include "Real2SimGuidance_private.h"
#include "angdiff_e8uhYa4N.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_powd_snf.h"

const uint8_T Real2SimGuidance_IN_InAir{ 1U };

const uint8_T Real2SimGuidance_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T Real2SimGuidance_IN_NotTakeOff{ 2U };

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

const real_T Real2SimGuidance_period{ 0.1 };

static void Real2SimGuidance_WaypointFollowerBase_getDistinctWpts(const real_T
    waypoints[219], real_T distinctWpts_data[], int32_T distinctWpts_size[2]);
static real_T Real2SimGuidance_norm(const real_T x[3]);
static void Real2SimGuidance_emxInit_real_T(emxArray_real_T_Real2SimGuidance_T **
    pEmxArray, int32_T numDimensions);
static void Real2SimGuidance_emxEnsureCapacity_real_T
    (emxArray_real_T_Real2SimGuidance_T *emxArray, int32_T oldNumel);
static void Real2SimGuidance_emxFree_real_T(emxArray_real_T_Real2SimGuidance_T **
    pEmxArray);
static void Real2SimGuidance_WaypointFollowerBase_searchClosestPath
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T waypoints_data[], const int32_T waypoints_size[2], const real_T
     currentPose[4]);
static void Real2SimGuidance_WaypointFollowerBase_endWaypointReached_b
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T waypoints_data[], const int32_T waypoints_size[2], real_T
     curStartWaypoint[3], real_T curEndWaypoint[3], const real_T currentPose[4]);
static void Real2SimGuidance_WaypointFollowerBase_stepInternal
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T currentPose[4], const real_T waypointsIn[219], real_T lookaheadDist,
     real_T lookaheadPoint[3], real_T *desiredHeading, real_T *desiredYaw,
     uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T *status);
void Real2SimGuidance_fale025h(real_T rtu_u, real_T rtu_u_j, real_T rtu_u_e,
    real_T *rty_y)
{
    real_T rtu_u_0;
    real_T tmp;
    tmp = std::abs(rtu_u);
    if (tmp <= rtu_u_e) {
        *rty_y = rtu_u / rt_powd_snf(rtu_u_e, 1.0 - rtu_u_j);
    } else {
        if (rtu_u < 0.0) {
            rtu_u_0 = -1.0;
        } else if (rtu_u > 0.0) {
            rtu_u_0 = 1.0;
        } else if (rtu_u == 0.0) {
            rtu_u_0 = 0.0;
        } else {
            rtu_u_0 = (rtNaN);
        }

        *rty_y = rt_powd_snf(tmp, rtu_u_j) * rtu_u_0;
    }
}

static void Real2SimGuidance_WaypointFollowerBase_getDistinctWpts(const real_T
    waypoints[219], real_T distinctWpts_data[], int32_T distinctWpts_size[2])
{
    int32_T i1;
    int32_T i2;
    int32_T ix;
    int32_T j;
    int8_T c_data[73];
    boolean_T x[219];
    boolean_T b[73];
    boolean_T exitg1;
    for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < 72; i2++) {
            j = static_cast<int32_T>(static_cast<int32_T>(73 * i1) + i2);
            x[j] = (waypoints[static_cast<int32_T>(static_cast<int32_T>(
                      static_cast<int32_T>(i2 + 2) + static_cast<int32_T>(73 *
                       i1)) - 1)] != waypoints[j]);
        }

        x[static_cast<int32_T>(static_cast<int32_T>(73 * i1) + 72)] = true;
    }

    i1 = 0;
    i2 = 146;
    for (j = 0; j < 73; j++) {
        b[j] = false;
        i1 = static_cast<int32_T>(i1 + 1);
        i2 = static_cast<int32_T>(i2 + 1);
        ix = i1;
        exitg1 = false;
        while ((!exitg1) && (ix <= i2)) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (x[static_cast<int32_T>(ix - 1)]) ^ 1))) {
                ix = static_cast<int32_T>(ix + 73);
            } else {
                b[j] = true;
                exitg1 = true;
            }
        }
    }

    i1 = 0;
    for (i2 = 0; i2 < 73; i2++) {
        if (b[i2]) {
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    j = i1;
    i1 = 0;
    for (i2 = 0; i2 < 73; i2++) {
        if (b[i2]) {
            c_data[i1] = static_cast<int8_T>(static_cast<int32_T>(i2 + 1));
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    distinctWpts_size[0] = j;
    distinctWpts_size[1] = 3;
    for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 <= static_cast<int32_T>(j - 1); i2++) {
            distinctWpts_data[static_cast<int32_T>(i2 + static_cast<int32_T>(j *
                i1))] = waypoints[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(73 * i1) + static_cast<int32_T>(c_data[i2]))
                - 1)];
        }
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

static void Real2SimGuidance_emxInit_real_T(emxArray_real_T_Real2SimGuidance_T **
    pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_Real2SimGuidance_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_real_T_Real2SimGuidance_T *)std::malloc(sizeof
        (emxArray_real_T_Real2SimGuidance_T));
    emxArray = *pEmxArray;
    emxArray->data = (real_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
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

static void Real2SimGuidance_WaypointFollowerBase_searchClosestPath
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T waypoints_data[], const int32_T waypoints_size[2], const real_T
     currentPose[4])
{
    emxArray_real_T_Real2SimGuidance_T *d;
    real_T currentPose_0[3];
    real_T currentPose_1[3];
    real_T currentPose_2[3];
    real_T currentPose_tmp;
    real_T currentPose_tmp_0;
    real_T currentPose_tmp_1;
    real_T lambda;
    real_T lambda_tmp_tmp;
    real_T lambda_tmp_tmp_0;
    real_T lambda_tmp_tmp_tmp;
    real_T lambda_tmp_tmp_tmp_0;
    real_T lambda_tmp_tmp_tmp_tmp;
    int32_T b;
    int32_T b_idx;
    int32_T b_k;
    int32_T last;
    boolean_T exitg1;
    Real2SimGuidance_emxInit_real_T(&d, 2);
    b_k = static_cast<int32_T>(d->size[0] * d->size[1]);
    d->size[0] = 1;
    d->size[1] = static_cast<int32_T>(obj->NumWaypoints - 1.0);
    Real2SimGuidance_emxEnsureCapacity_real_T(d, b_k);
    last = static_cast<int32_T>(static_cast<int32_T>(obj->NumWaypoints - 1.0) -
        1);
    for (b_k = 0; b_k <= last; b_k++) {
        d->data[b_k] = 0.0;
        lambda = waypoints_data[static_cast<int32_T>(static_cast<int32_T>((
            static_cast<real_T>(b_k) + 1.0) + 1.0) - 1)] - waypoints_data[b_k];
        currentPose_0[0] = currentPose[0] - waypoints_data[b_k];
        currentPose_tmp_1 = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>((static_cast<real_T>(b_k) + 1.0) + 1.0) - 1)];
        currentPose_1[0] = currentPose[0] - currentPose_tmp_1;
        lambda_tmp_tmp_tmp = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>((static_cast<real_T>(b_k)
                + 1.0) + 1.0) + waypoints_size[0]) - 1)];
        lambda_tmp_tmp_tmp_0 = waypoints_data[static_cast<int32_T>(b_k +
            waypoints_size[0])];
        lambda_tmp_tmp = lambda_tmp_tmp_tmp - lambda_tmp_tmp_tmp_0;
        currentPose_tmp = currentPose[1] - lambda_tmp_tmp_tmp_0;
        currentPose_0[1] = currentPose_tmp;
        currentPose_1[1] = currentPose[1] - lambda_tmp_tmp_tmp;
        lambda_tmp_tmp_0 = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>((static_cast<real_T>(b_k)
                + 1.0) + 1.0) + static_cast<int32_T>(waypoints_size[0] << 1)) -
             1)];
        lambda_tmp_tmp_tmp_tmp = waypoints_data[static_cast<int32_T>(b_k +
            static_cast<int32_T>(waypoints_size[0] << 1))];
        lambda_tmp_tmp_tmp = lambda_tmp_tmp_0 - lambda_tmp_tmp_tmp_tmp;
        currentPose_tmp_0 = currentPose[2] - lambda_tmp_tmp_tmp_tmp;
        currentPose_0[2] = currentPose_tmp_0;
        currentPose_1[2] = currentPose[2] - lambda_tmp_tmp_0;
        lambda_tmp_tmp_0 = waypoints_data[b_k];
        lambda = (currentPose_tmp_0 * lambda_tmp_tmp_tmp + (currentPose_tmp *
                   lambda_tmp_tmp + (currentPose[0] - lambda_tmp_tmp_0) * lambda))
            / (lambda_tmp_tmp_tmp * lambda_tmp_tmp_tmp + (lambda_tmp_tmp *
                lambda_tmp_tmp + (waypoints_data[static_cast<int32_T>(
                  static_cast<int32_T>((static_cast<real_T>(b_k) + 1.0) + 1.0) -
                  1)] - lambda_tmp_tmp_0) * lambda));
        currentPose_2[0] = currentPose[0] - ((currentPose_tmp_1 -
            lambda_tmp_tmp_0) * lambda + lambda_tmp_tmp_0);
        currentPose_2[1] = currentPose[1] - (lambda_tmp_tmp * lambda +
            lambda_tmp_tmp_tmp_0);
        currentPose_2[2] = currentPose[2] - (lambda_tmp_tmp_tmp * lambda +
            lambda_tmp_tmp_tmp_tmp);
        if (lambda < 0.0) {
            d->data[b_k] = Real2SimGuidance_norm(currentPose_0);
        } else if (lambda > 1.0) {
            d->data[b_k] = Real2SimGuidance_norm(currentPose_1);
        } else {
            d->data[b_k] = Real2SimGuidance_norm(currentPose_2);
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
            lambda = d->data[static_cast<int32_T>(b_idx - 1)];
            b = b_idx;
            for (b_k = static_cast<int32_T>(b + 1); b_k <= last; b_k++) {
                currentPose_tmp_1 = d->data[static_cast<int32_T>(b_k - 1)];
                if (lambda > currentPose_tmp_1) {
                    lambda = currentPose_tmp_1;
                    b_idx = b_k;
                }
            }
        }
    }

    Real2SimGuidance_emxFree_real_T(&d);
    obj->WaypointIndex = static_cast<real_T>(b_idx);
    obj->SearchFlag = false;
}

static void Real2SimGuidance_WaypointFollowerBase_endWaypointReached_b
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T waypoints_data[], const int32_T waypoints_size[2], real_T
     curStartWaypoint[3], real_T curEndWaypoint[3], const real_T currentPose[4])
{
    real_T curEndWaypoint_0[3];
    real_T tmp[3];
    real_T curEndWaypoint_1;
    real_T curEndWaypoint_tmp;
    real_T curEndWaypoint_tmp_0;
    real_T curEndWaypoint_tmp_1;
    real_T tmp_0;
    boolean_T guard1{ false };

    boolean_T p;
    tmp[0] = currentPose[0] - curEndWaypoint[0];
    tmp[1] = currentPose[1] - curEndWaypoint[1];
    tmp[2] = currentPose[2] - curEndWaypoint[2];
    curEndWaypoint_1 = Real2SimGuidance_norm(tmp);
    guard1 = false;
    if (curEndWaypoint_1 <= 1.0) {
        guard1 = true;
    } else {
        curEndWaypoint_tmp = curEndWaypoint[0] - curStartWaypoint[0];
        curEndWaypoint_0[0] = curEndWaypoint_tmp;
        curEndWaypoint_tmp_0 = curEndWaypoint[1] - curStartWaypoint[1];
        curEndWaypoint_0[1] = curEndWaypoint_tmp_0;
        curEndWaypoint_tmp_1 = curEndWaypoint[2] - curStartWaypoint[2];
        curEndWaypoint_0[2] = curEndWaypoint_tmp_1;
        tmp_0 = Real2SimGuidance_norm(curEndWaypoint_0);
        curEndWaypoint_1 = (curEndWaypoint_tmp / tmp_0 * (tmp[0] /
                             curEndWaypoint_1) + curEndWaypoint_tmp_0 / tmp_0 *
                            (tmp[1] / curEndWaypoint_1)) + curEndWaypoint_tmp_1 /
            tmp_0 * (tmp[2] / curEndWaypoint_1);
        if (curEndWaypoint_1 < 0.0) {
            curEndWaypoint_1 = -1.0;
        } else if (curEndWaypoint_1 > 0.0) {
            curEndWaypoint_1 = 1.0;
        } else if (curEndWaypoint_1 == 0.0) {
            curEndWaypoint_1 = 0.0;
        } else {
            curEndWaypoint_1 = (rtNaN);
        }

        if (curEndWaypoint_1 >= 0.0) {
            guard1 = true;
        }
    }

    if (guard1) {
        obj->WaypointIndex++;
        p = false;
        if (obj->WaypointIndex == obj->NumWaypoints) {
            p = true;
        }

        if (p) {
            obj->LastWaypointFlag = true;
            obj->WaypointIndex--;
        }

        curStartWaypoint[0] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(obj->WaypointIndex) - 1)];
        curEndWaypoint[0] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(obj->WaypointIndex + 1.0) - 1)];
        curStartWaypoint[1] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
              waypoints_size[0]) - 1)];
        curEndWaypoint[1] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex + 1.0)
              + waypoints_size[0]) - 1)];
        curStartWaypoint[2] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
              static_cast<int32_T>(waypoints_size[0] << 1)) - 1)];
        curEndWaypoint[2] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex + 1.0)
              + static_cast<int32_T>(waypoints_size[0] << 1)) - 1)];
    }
}

static void Real2SimGuidance_WaypointFollowerBase_stepInternal
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T currentPose[4], const real_T waypointsIn[219], real_T lookaheadDist,
     real_T lookaheadPoint[3], real_T *desiredHeading, real_T *desiredYaw,
     uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T *status)
{
    real_T b_waypointsIn_data[219];
    real_T waypoints_data[219];
    real_T appendedWaypoints_data[6];
    real_T currentPose_0[3];
    real_T currentPose_1[3];
    real_T currentPose_2[3];
    real_T virtualWaypoint[3];
    real_T b;
    real_T b_tmp_idx_1_tmp;
    real_T b_tmp_idx_2_tmp;
    real_T currentPose_tmp;
    real_T lambda;
    real_T lambda_tmp_tmp;
    real_T lambda_tmp_tmp_0;
    real_T lambda_tmp_tmp_1;
    int32_T b_waypointsIn_size[2];
    int32_T waypoints_size[2];
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T b_k;
    int32_T loop_ub;
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T p;
    boolean_T p_0;
    obj->LookaheadDistFlag = 0U;
    if (lookaheadDist < 10.0) {
        lookaheadDist = 10.0;
        obj->LookaheadDistFlag = 1U;
    }

    *lookaheadDistFlag = obj->LookaheadDistFlag;
    obj->InitialPose[0] = 0.0;
    obj->InitialPose[1] = 0.0;
    obj->InitialPose[2] = 0.0;
    obj->InitialPose[3] = 0.0;
    p = false;
    p_0 = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 219)) {
        if ((obj->WaypointsInternal[b_k] == waypointsIn[b_k]) || (std::isnan
                (obj->WaypointsInternal[b_k]) && std::isnan(waypointsIn[b_k])))
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
        std::memcpy(&obj->WaypointsInternal[0], &waypointsIn[0],
                    static_cast<uint32_T>(219U * sizeof(real_T)));
        obj->WaypointIndex = 1.0;
        obj->SearchFlag = true;
    }

    Real2SimGuidance_WaypointFollowerBase_getDistinctWpts(waypointsIn,
        b_waypointsIn_data, b_waypointsIn_size);
    obj->NumWaypoints = static_cast<real_T>(b_waypointsIn_size[0]);
    obj->LookaheadDistance = lookaheadDist;
    if (b_waypointsIn_size[0] == 0) {
        lookaheadPoint[0] = lookaheadDist * std::cos(currentPose[3]) +
            currentPose[0];
        lookaheadPoint[1] = lookaheadDist * std::sin(currentPose[3]) +
            currentPose[1];
        lookaheadPoint[2] = lookaheadDist * 0.0 + currentPose[2];
        *desiredHeading = currentPose[3];
        *desiredYaw = currentPose[3];
        *crossTrackError = 0.0;
        *status = 1U;
    } else {
        guard1 = false;
        if (b_waypointsIn_size[0] == 1) {
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
                lookaheadPoint[0] = lookaheadDist * std::cos(currentPose[3]) +
                    currentPose[0];
                lookaheadPoint[1] = lookaheadDist * std::sin(currentPose[3]) +
                    currentPose[1];
                lookaheadPoint[2] = lookaheadDist * 0.0 + currentPose[2];
                *desiredHeading = currentPose[3];
                *desiredYaw = currentPose[3];
                *crossTrackError = 0.0;
                *status = 1U;
                obj->StartFlag = false;
            } else {
                obj->StartFlag = false;
                for (b_k = 0; b_k < 3; b_k++) {
                    appendedWaypoints_data[static_cast<int32_T>(b_k << 1)] =
                        obj->InitialPose[b_k];
                    appendedWaypoints_data[static_cast<int32_T>(1 + static_cast<
                        int32_T>(b_k << 1))] = b_waypointsIn_data
                        [static_cast<int32_T>(b_waypointsIn_size[0] * b_k)];
                }

                obj->NumWaypoints = 2.0;
                waypoints_size[0] = 2;
                waypoints_size[1] = 3;
                for (b_k = 0; b_k < 6; b_k++) {
                    waypoints_data[b_k] = appendedWaypoints_data[b_k];
                }

                guard1 = true;
            }
        } else {
            waypoints_size[0] = b_waypointsIn_size[0];
            waypoints_size[1] = 3;
            loop_ub = static_cast<int32_T>(b_waypointsIn_size[0] * 3);
            for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
                waypoints_data[b_k] = b_waypointsIn_data[b_k];
            }

            guard1 = true;
        }

        if (guard1) {
            if (obj->SearchFlag) {
                Real2SimGuidance_WaypointFollowerBase_searchClosestPath(obj,
                    waypoints_data, waypoints_size, currentPose);
            }

            p = false;
            if (obj->WaypointIndex == obj->NumWaypoints) {
                p = true;
            }

            if (p) {
                obj->LastWaypointFlag = true;
                obj->WaypointIndex--;
            }

            virtualWaypoint[0] = waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(obj->WaypointIndex) - 1)];
            lookaheadPoint[0] = waypoints_data[static_cast<int32_T>(static_cast<
                int32_T>(obj->WaypointIndex + 1.0) - 1)];
            virtualWaypoint[1] = waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
                waypoints_size[0]) - 1)];
            lookaheadPoint[1] = waypoints_data[static_cast<int32_T>(static_cast<
                int32_T>(static_cast<int32_T>(obj->WaypointIndex + 1.0) +
                         waypoints_size[0]) - 1)];
            virtualWaypoint[2] = waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
                static_cast<int32_T>(waypoints_size[0] << 1)) - 1)];
            lookaheadPoint[2] = waypoints_data[static_cast<int32_T>(static_cast<
                int32_T>(static_cast<int32_T>(obj->WaypointIndex + 1.0) +
                         static_cast<int32_T>(waypoints_size[0] << 1)) - 1)];
            Real2SimGuidance_WaypointFollowerBase_endWaypointReached_b(obj,
                waypoints_data, waypoints_size, virtualWaypoint, lookaheadPoint,
                currentPose);
            lambda_tmp_tmp = lookaheadPoint[0] - virtualWaypoint[0];
            b = currentPose[0] - virtualWaypoint[0];
            currentPose_0[0] = b;
            currentPose_1[0] = currentPose[0] - lookaheadPoint[0];
            lambda_tmp_tmp_0 = lookaheadPoint[1] - virtualWaypoint[1];
            lambda = currentPose[1] - virtualWaypoint[1];
            currentPose_0[1] = lambda;
            currentPose_1[1] = currentPose[1] - lookaheadPoint[1];
            lambda_tmp_tmp_1 = lookaheadPoint[2] - virtualWaypoint[2];
            currentPose_tmp = currentPose[2] - virtualWaypoint[2];
            currentPose_0[2] = currentPose_tmp;
            currentPose_1[2] = currentPose[2] - lookaheadPoint[2];
            lambda = (currentPose_tmp * lambda_tmp_tmp_1 + (lambda *
                       lambda_tmp_tmp_0 + b * lambda_tmp_tmp)) /
                (lambda_tmp_tmp_1 * lambda_tmp_tmp_1 + (lambda_tmp_tmp_0 *
                  lambda_tmp_tmp_0 + lambda_tmp_tmp * lambda_tmp_tmp));
            currentPose_2[0] = currentPose[0] - (lambda_tmp_tmp * lambda +
                virtualWaypoint[0]);
            currentPose_2[1] = currentPose[1] - (lambda_tmp_tmp_0 * lambda +
                virtualWaypoint[1]);
            currentPose_2[2] = currentPose[2] - (lambda_tmp_tmp_1 * lambda +
                virtualWaypoint[2]);
            if (lambda < 0.0) {
                *crossTrackError = Real2SimGuidance_norm(currentPose_0);
            } else if (lambda > 1.0) {
                *crossTrackError = Real2SimGuidance_norm(currentPose_1);
            } else {
                *crossTrackError = Real2SimGuidance_norm(currentPose_2);
            }

            if (obj->LastWaypointFlag) {
                lambda = (((currentPose[0] - virtualWaypoint[0]) *
                           (lookaheadPoint[0] - virtualWaypoint[0]) +
                           (currentPose[1] - virtualWaypoint[1]) *
                           (lookaheadPoint[1] - virtualWaypoint[1])) +
                          (currentPose[2] - virtualWaypoint[2]) *
                          (lookaheadPoint[2] - virtualWaypoint[2])) /
                    (((lookaheadPoint[0] - virtualWaypoint[0]) *
                      (lookaheadPoint[0] - virtualWaypoint[0]) +
                      (lookaheadPoint[1] - virtualWaypoint[1]) *
                      (lookaheadPoint[1] - virtualWaypoint[1])) +
                     (lookaheadPoint[2] - virtualWaypoint[2]) * (lookaheadPoint
                      [2] - virtualWaypoint[2]));
                currentPose_0[0] = currentPose[0] - (lambda * lambda_tmp_tmp +
                    virtualWaypoint[0]);
                currentPose_0[1] = currentPose[1] - (lambda * lambda_tmp_tmp_0 +
                    virtualWaypoint[1]);
                currentPose_0[2] = currentPose[2] - (lambda * lambda_tmp_tmp_1 +
                    virtualWaypoint[2]);
                *crossTrackError = Real2SimGuidance_norm(currentPose_0);
            }

            b = std::abs(*crossTrackError);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isinf(b)) ^ 1))) &
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(std::isnan(b)) ^
                     1)))))) {
                if (b <= 2.2250738585072014E-308) {
                    lambda = 4.94065645841247E-324;
                    b = 4.94065645841247E-324;
                } else {
                    frexp(b, &b_exponent);
                    lambda = std::ldexp(1.0, static_cast<int32_T>(b_exponent -
                                         53));
                    frexp(b, &b_exponent_0);
                    b = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0 - 53));
                }
            } else {
                lambda = (rtNaN);
                b = (rtNaN);
            }

            if (obj->LookaheadDistance <= std::fmax(std::sqrt(lambda), 5.0 * b)
                    + *crossTrackError) {
                obj->LookaheadDistance = obj->LookaheadFactor * *crossTrackError;
            }

            lambda = ((lookaheadPoint[0] - virtualWaypoint[0]) *
                      (lookaheadPoint[0] - virtualWaypoint[0]) +
                      (lookaheadPoint[1] - virtualWaypoint[1]) *
                      (lookaheadPoint[1] - virtualWaypoint[1])) +
                (lookaheadPoint[2] - virtualWaypoint[2]) * (lookaheadPoint[2] -
                virtualWaypoint[2]);
            currentPose_tmp = virtualWaypoint[0] - currentPose[0];
            b_tmp_idx_1_tmp = virtualWaypoint[1] - currentPose[1];
            b_tmp_idx_2_tmp = virtualWaypoint[2] - currentPose[2];
            b = ((lambda_tmp_tmp * currentPose_tmp + lambda_tmp_tmp_0 *
                  b_tmp_idx_1_tmp) + lambda_tmp_tmp_1 * b_tmp_idx_2_tmp) * 2.0;
            lambda_tmp_tmp = std::sqrt(b * b - (((currentPose_tmp *
                currentPose_tmp + b_tmp_idx_1_tmp * b_tmp_idx_1_tmp) +
                b_tmp_idx_2_tmp * b_tmp_idx_2_tmp) - obj->LookaheadDistance *
                obj->LookaheadDistance) * (4.0 * lambda));
            lambda = std::fmax((-b + lambda_tmp_tmp) / 2.0 / lambda, (-b -
                                lambda_tmp_tmp) / 2.0 / lambda);
            lambda_tmp_tmp = (1.0 - lambda) * virtualWaypoint[0] + lambda *
                lookaheadPoint[0];
            lookaheadPoint[0] = lambda_tmp_tmp;
            lambda_tmp_tmp_0 = (1.0 - lambda) * virtualWaypoint[1] + lambda *
                lookaheadPoint[1];
            lookaheadPoint[1] = lambda_tmp_tmp_0;
            lookaheadPoint[2] = (1.0 - lambda) * virtualWaypoint[2] + lambda *
                lookaheadPoint[2];
            *desiredHeading = rt_atan2d_snf(lambda_tmp_tmp_0 - currentPose[1],
                lambda_tmp_tmp - currentPose[0]);
            *desiredYaw = *desiredHeading;
            *status = 0U;
            p = false;
            if (obj->LastWaypointFlag) {
                p = true;
            }

            if (p) {
                *status = 1U;
            }

            obj->LastWaypointFlag = false;
        }
    }
}

void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    int32_T i;
    localX->TD_Alt_CSTATE = 0.0;
    localX->dotAltTD_CSTATE = 0.0;
    for (i = 0; i < 72; i++) {
        localDW->HeightSequence_X[i] = -150.0;
    }

    localX->TD_AirSpdADRC_CSTATE = 0.0;
    localX->dotTD_CSTATE = 0.0;
    localX->ESO_CSTATE = 0.0;
    localX->ESO_dot_CSTATE = 0.0;
    localX->ESO_dotdot_CSTATE = 0.0;
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.SearchFlag = true;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 219; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }
}

void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW)
{
    localDW->ESO_MODE = false;
}

void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const Real2SimGuidance_M,
                      const FixedWingGuidanceStateBus *rtu_SimUAVState, const
                      boolean_T *rtu_ImmedModeSwitch, const RealUAVStateBus
                      *rtu_RealUAVLatLonState, const uint8_T *rtu_FlightMode,
                      const real_T *rtu_GroundSpd, const boolean_T
                      rtu_ControlSwitch[2], const FixedWingGuidanceBus
                      *rtu_ImmedGuidanceCMD, const MissionModes
                      *rtu_thisTaskStatus_MissionMode, const int32_T
                      *rtu_thisTaskStatus_numUAV, const int32_T
                      *rtu_thisTaskStatus_FormationPos, LookAheadPoint
                      *rty_LookAheadPoint, real_T *rty_RefAirspeed, real_T
                      *rty_ExecutionTrigger, boolean_T *rty_EngagedFlag,
                      FixedWingGuidanceStateBus *rty_RealUAVState,
                      DW_Real2SimGuidance_f_T *localDW, X_Real2SimGuidance_n_T
                      *localX)
{
    real_T rtb_SumNorth;
    real_T rtb_SumEast;
    real_T rtb_MatrixConcatenate[219];
    real_T rty_RealUAVState_0[4];
    real_T rtb_SwitchLookAheadNED[3];
    real_T a0;
    real_T a2;
    real_T rtb_Abs1;
    real_T rtb_AirSpeed;
    real_T rtb_Down;
    real_T rtb_LongitudeGCS;
    real_T rtb_LowerBound;
    real_T rtb_RealUAVNEUState_idx_0;
    real_T rtb_RealUAVNEUState_idx_1;
    real_T rtb_RealUAVNEUState_idx_2;
    real_T rtb_RefGndSpd;
    real_T rtb_Sum1_idx_0;
    real_T rtb_Sum1_idx_1;
    real_T rtb_Sum_g0_0;
    real_T rtb_Sum_h_idx_0;
    real_T rtb_SwitchLookAheadPoint_idx_0;
    real_T rtb_SwitchLookAheadPoint_idx_2;
    real_T rtb_Switch_f;
    real_T rtb_UpperBound;
    real_T y;
    real_T y_0;
    int32_T i;
    uint8_T lookaheadFlag;
    boolean_T rtb_SpdAND;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        localDW->FlightMode_Log = static_cast<real_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (rtu_ControlSwitch[1]) ^ 1)))) * static_cast<real_T>(*rtu_FlightMode);
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_Sum_h_idx_0 = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_LongitudeGCS = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_idx_0 = rtu_RealUAVLatLonState->Latitude_deg - rtb_Sum_h_idx_0;
        rtb_Sum1_idx_1 = rtu_RealUAVLatLonState->Longitude_deg -
            rtb_LongitudeGCS;
        if (std::abs(rtb_Sum1_idx_0) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Abs1 = rtb_Sum1_idx_0;
        }

        rtb_LongitudeGCS = std::abs(rtb_Abs1);
        if (rtb_LongitudeGCS > 90.0) {
            if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
            } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
            } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
            } else {
                rtb_Abs1 = (rtNaN);
            }

            rtb_Abs1 *= -(rtb_LongitudeGCS + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        rtb_LongitudeGCS = static_cast<real_T>(i) + rtb_Sum1_idx_1;
        if (std::abs(rtb_LongitudeGCS) > 180.0) {
            rtb_LongitudeGCS = rt_modd_snf(rtb_LongitudeGCS + 180.0, 360.0) +
                -180.0;
        }

        rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Abs1;
        rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_LongitudeGCS;
        rtb_Sum_h_idx_0 *= 0.017453292519943295;
        rtb_LongitudeGCS = std::sin(rtb_Sum_h_idx_0);
        rtb_LongitudeGCS = 1.0 - 0.0066943799901413295 * rtb_LongitudeGCS *
            rtb_LongitudeGCS;
        rtb_Abs1 = 6.378137E+6 / std::sqrt(rtb_LongitudeGCS);
        rtb_LongitudeGCS = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, rtb_Abs1 *
            0.99330562000985867 / rtb_LongitudeGCS);
        rtb_Abs1 = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1 * std::cos(rtb_Sum_h_idx_0))
            * rtb_Sum1_idx_1;
        rtb_Sum_h_idx_0 = rtb_Abs1 * 0.0 + rtb_LongitudeGCS;
        rtb_Abs1 -= rtb_LongitudeGCS * 0.0;
        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_LongitudeGCS = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rty_RealUAVState->North = rtb_Sum_h_idx_0;
        rty_RealUAVState->East = rtb_Abs1;
        rty_RealUAVState->Height = rtu_RealUAVLatLonState->Height_meter +
            -rtb_LongitudeGCS;
        rty_RealUAVState->AirSpeed = rtu_RealUAVLatLonState->AirSpeed_mps;
        rty_RealUAVState->HeadingAngle = 0.017453292519943295 *
            rtu_RealUAVLatLonState->HeadingAngle_deg;
        rty_RealUAVState->FlightPathAngle = 0.017453292519943295 *
            rtu_RealUAVLatLonState->FlightPathAngle_deg;
        rty_RealUAVState->RollAngle = 0.017453292519943295 *
            rtu_RealUAVLatLonState->RollAngle_deg;
        rty_RealUAVState->RollAngleRate = 0.0;
        if (*rtu_thisTaskStatus_MissionMode != None) {
            rtb_Sum_h_idx_0 = static_cast<real_T>
                (*rtu_thisTaskStatus_FormationPos);
            rtb_Abs1 = static_cast<real_T>(*rtu_thisTaskStatus_numUAV);
            rtb_LongitudeGCS = rtb_Sum_h_idx_0 / rtb_Abs1;
            if (rtb_LongitudeGCS > 1.0) {
                rtb_LongitudeGCS = 1.0;
            } else if (rtb_LongitudeGCS < -1.0) {
                rtb_LongitudeGCS = -1.0;
            }

            rtb_Sum_h_idx_0 = 0.8 * rtb_LongitudeGCS;
            if (rtb_Sum_h_idx_0 > 0.0) {
                rtb_Sum_h_idx_0 += 0.2;
            } else {
                rtb_Sum_h_idx_0 += -0.2;
            }

            rtb_Abs1 = rtb_Sum_h_idx_0 - localDW->PrevY;
            if (rtb_Abs1 > Real2SimGuidance_period) {
                localDW->RateLimiter = localDW->PrevY + Real2SimGuidance_period;
            } else if (rtb_Abs1 < -0.1) {
                localDW->RateLimiter = localDW->PrevY + -0.1;
            } else {
                localDW->RateLimiter = rtb_Sum_h_idx_0;
            }

            localDW->PrevY = localDW->RateLimiter;
        }

        rtb_LongitudeGCS = localDW->MemoryRefHeight_PreviousInput;
        rtb_MatrixConcatenate[145] = rtu_SimUAVState->East;
        localDW->TrackInvH = -rtu_SimUAVState->Height;
        rtb_MatrixConcatenate[218] = localDW->TrackInvH;
        for (i = 0; i < 72; i++) {
            rtb_MatrixConcatenate[static_cast<int_T>(i + 73)] =
                localDW->EastSequence_X[i];
            rtb_MatrixConcatenate[static_cast<int_T>(i + 146)] =
                localDW->HeightSequence_X[i];
            rtb_MatrixConcatenate[i] = localDW->NorthSequence_X[i];
        }

        rtb_MatrixConcatenate[72] = rtu_SimUAVState->North;
        rtb_Sum1_idx_0 = rty_RealUAVState->AirSpeed - *rtu_GroundSpd;
        localDW->Compare_e = (localDW->FlightMode_Log == 3.0);
        rtb_SwitchLookAheadPoint_idx_0 = rtu_SimUAVState->North -
            rty_RealUAVState->North;
        rtb_Sum1_idx_1 = rtu_SimUAVState->East - rty_RealUAVState->East;
        rtb_SwitchLookAheadPoint_idx_2 = rtu_SimUAVState->Height -
            rtu_SimUAVState->Height;
        a0 = rtb_SwitchLookAheadPoint_idx_0 * rtb_SwitchLookAheadPoint_idx_0;
        rtb_SwitchLookAheadPoint_idx_0 = rtb_MatrixConcatenate[72];
        a0 += rtb_Sum1_idx_1 * rtb_Sum1_idx_1;
        rtb_Sum1_idx_1 = rtb_MatrixConcatenate[145];
        a0 += rtb_SwitchLookAheadPoint_idx_2 * rtb_SwitchLookAheadPoint_idx_2;
        rtb_SwitchLookAheadPoint_idx_2 = rtb_MatrixConcatenate[218];
        rtb_Sum_h_idx_0 = std::sqrt(a0);
        localDW->InverseY = -rtb_Sum_h_idx_0;
        y = rtb_MatrixConcatenate[24] - rtb_MatrixConcatenate[72];
        rtb_Sum_g0_0 = y * y;
        y = rtb_MatrixConcatenate[97] - rtb_MatrixConcatenate[145];
        rtb_Sum_g0_0 += y * y;
        y = rtb_MatrixConcatenate[170] - rtb_MatrixConcatenate[218];
        rtb_Abs1 = std::sqrt(y * y + rtb_Sum_g0_0);
        localDW->InverseR = -rtb_Abs1;
    }

    if (rtmIsMajorTimeStep(Real2SimGuidance_M) && rtmIsMajorTimeStep
            (Real2SimGuidance_M)) {
        localDW->ESO_MODE = localDW->Compare_e;
    }

    if (localDW->ESO_MODE) {
        localDW->ESO = localX->ESO_CSTATE;
        localDW->ESO_dot = localX->ESO_dot_CSTATE;
        localDW->ESO_dotdot = localX->ESO_dotdot_CSTATE;
    }

    localDW->dotTD = localX->dotTD_CSTATE;
    a0 = (localDW->dotTD - localDW->ESO_dot) * 3.5 * 7.0;
    y = (localX->TD_AirSpdADRC_CSTATE - localDW->ESO) + a0;
    if (y < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (y > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (y == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    a2 = (std::sqrt((8.0 * std::abs(y) + 490.0) * 490.0) - 490.0) * rtb_Sum_g0_0
        / 2.0 + a0;
    if (y + 490.0 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (y + 490.0 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (y + 490.0 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    if (y - 490.0 < 0.0) {
        y_0 = -1.0;
    } else if (y - 490.0 > 0.0) {
        y_0 = 1.0;
    } else if (y - 490.0 == 0.0) {
        y_0 = 0.0;
    } else {
        y_0 = (rtNaN);
    }

    a0 = ((a0 + y) - a2) * ((rtb_Sum_g0_0 - y_0) / 2.0) + a2;
    if (a0 < 0.0) {
        y = -1.0;
    } else if (a0 > 0.0) {
        y = 1.0;
    } else if (a0 == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (a0 + 490.0 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (a0 + 490.0 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (a0 + 490.0 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
    }

    if (a0 - 490.0 < 0.0) {
        a2 = -1.0;
    } else if (a0 - 490.0 > 0.0) {
        a2 = 1.0;
    } else if (a0 - 490.0 == 0.0) {
        a2 = 0.0;
    } else {
        a2 = (rtNaN);
    }

    localDW->GainADRCinvb0 = (-((a0 / 490.0 - y) * -10.0 * ((rtb_Sum_g0_0 - a2) /
        2.0) - 10.0 * y) - localDW->ESO_dotdot) * 10.0;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        localDW->ADRC_U_Log = localDW->GainADRCinvb0;
        localDW->LagDistance = localX->TD_AirSpdADRC_CSTATE - localDW->InverseY;
    }

    localDW->SumY = localDW->ESO - localDW->InverseY;
    a0 = localDW->dotTD * 0.1;
    y = (localX->TD_AirSpdADRC_CSTATE - localDW->InverseR) + a0;
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
        2.0 + a0;
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

    a0 = ((a0 + y) - a2) * ((rtb_Sum_g0_0 - y_0) / 2.0) + a2;
    if (a0 < 0.0) {
        y = -1.0;
    } else if (a0 > 0.0) {
        y = 1.0;
    } else if (a0 == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (a0 + 0.05 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (a0 + 0.05 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (a0 + 0.05 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
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

    localDW->fh_p = (a0 / 0.05 - y) * -5.0 * ((rtb_Sum_g0_0 - a2) / 2.0) - 5.0 *
        y;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        y = rtb_MatrixConcatenate[48] - rtb_SwitchLookAheadPoint_idx_0;
        rtb_Sum_g0_0 = y * y;
        a0 = rtb_MatrixConcatenate[0] - rtb_SwitchLookAheadPoint_idx_0;
        rtb_RefGndSpd = a0 * a0;
        y = rtb_MatrixConcatenate[121] - rtb_Sum1_idx_1;
        rtb_Sum_g0_0 += y * y;
        a0 = rtb_MatrixConcatenate[73] - rtb_Sum1_idx_1;
        rtb_RefGndSpd += a0 * a0;
        y = rtb_MatrixConcatenate[194] - rtb_SwitchLookAheadPoint_idx_2;
        a0 = rtb_MatrixConcatenate[146] - rtb_SwitchLookAheadPoint_idx_2;
        rtb_Down = std::sqrt(y * y + rtb_Sum_g0_0);
        rtb_Sum_h_idx_0 -= rtb_Down;
        rtb_LowerBound = rtb_Down - rtb_Abs1;
        rtb_UpperBound = std::sqrt(a0 * a0 + rtb_RefGndSpd) - rtb_Abs1;
        rtb_Down = rtb_Abs1 - rtb_Down;
        rtb_AirSpeed = rtu_SimUAVState->AirSpeed;
        rtb_RefGndSpd = (rtb_Sum1_idx_0 + localDW->ADRC_U_Log) + rtb_AirSpeed;
        if (rtb_Sum_h_idx_0 <= 75.063829787234042) {
            rtb_Sum_h_idx_0 = 75.063829787234042;
        }

        rtb_Down = rtb_Down * rtb_Down / rtb_Sum_h_idx_0 - rtb_Down;
        rty_RealUAVState_0[0] = rty_RealUAVState->North;
        rty_RealUAVState_0[1] = rty_RealUAVState->East;
        rty_RealUAVState_0[2] = rtb_LongitudeGCS;
        rty_RealUAVState_0[3] = rty_RealUAVState->HeadingAngle;
        Real2SimGuidance_WaypointFollowerBase_stepInternal(&localDW->obj,
            rty_RealUAVState_0, rtb_MatrixConcatenate, 3.6 * rtb_AirSpeed,
            rtb_SwitchLookAheadNED, &rtb_Abs1, &rtb_Sum_h_idx_0, &lookaheadFlag,
            &localDW->CrossTrackError, &localDW->Status_Log);
        if (static_cast<int32_T>(localDW->Status_Log) != 0) {
            rtb_SwitchLookAheadNED[0] = rtb_MatrixConcatenate[0];
            rtb_SwitchLookAheadNED[1] = rtb_MatrixConcatenate[73];
            rtb_SwitchLookAheadNED[2] = rtb_MatrixConcatenate[146];
            rtb_Abs1 = rt_atan2d_snf(rtb_MatrixConcatenate[73] -
                rty_RealUAVState->East, rtb_MatrixConcatenate[0] -
                rty_RealUAVState->North);
        }

        localDW->Heading_Log[0] = angdiff_e8uhYa4N
            (rty_RealUAVState->HeadingAngle, rtb_Abs1);
        localDW->Heading_Log[1] = angdiff_e8uhYa4N(0.0,
            rty_RealUAVState->HeadingAngle);
        localDW->Heading_Log[2] = angdiff_e8uhYa4N(0.0, rtb_Abs1);
    }

    localDW->biasH_Log = localX->TD_Alt_CSTATE;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        *rty_EngagedFlag = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((localDW->LagDistance < rtb_UpperBound) & (localDW->LagDistance >
            rtb_LowerBound)))) & (localDW->CrossTrackError < rtb_AirSpeed * 1.5)));
        if (*rty_EngagedFlag) {
            localDW->BiasHSwitch = 0.0;
        } else {
            localDW->BiasHSwitch = rtb_Down * localDW->RateLimiter;
        }

        rtb_Sum_h_idx_0 = std::cos(rtu_SimUAVState->HeadingAngle);
        rtb_Switch_f = 126.0 * rtb_Sum_h_idx_0 + rtu_SimUAVState->North;
        rtb_Abs1 = std::sin(rtu_SimUAVState->HeadingAngle);
        rtb_LowerBound = 126.0 * rtb_Abs1 + rtu_SimUAVState->East;
        rtb_Down = -rtu_SimUAVState->Height;
        rtb_Switch_f -= rty_RealUAVState->North;
        rtb_SwitchLookAheadPoint_idx_2 = rtb_LowerBound - rty_RealUAVState->East;
        rtb_Down -= rtb_LongitudeGCS;
        localDW->NorthEastHeight[0] = rtb_SwitchLookAheadNED[0];
        localDW->NorthEastHeight[1] = rtb_SwitchLookAheadNED[1];
        localDW->NorthEastHeight[2] = -rtb_SwitchLookAheadNED[2];
        rtb_RealUAVNEUState_idx_0 = localDW->NorthEastHeight[0];
        rtb_RealUAVNEUState_idx_1 = localDW->NorthEastHeight[1];
        rtb_RealUAVNEUState_idx_2 = localDW->NorthEastHeight[2] +
            localDW->biasH_Log;
        if (static_cast<boolean_T>(static_cast<int32_T>((std::sqrt((rtb_Switch_f
                 * rtb_Switch_f + rtb_SwitchLookAheadPoint_idx_2 *
                 rtb_SwitchLookAheadPoint_idx_2) + rtb_Down * rtb_Down) >= 252.0)
              ^ 1))) {
            rtb_RefGndSpd = 0.0;
        }

        if (rtb_RefGndSpd > 41.0) {
            rtb_Switch_f = 41.0;
        } else if (rtb_RefGndSpd < 29.0) {
            rtb_Switch_f = 29.0;
        } else {
            rtb_Switch_f = rtb_RefGndSpd;
        }
    }

    localDW->dotAltTD = localX->dotAltTD_CSTATE;
    a0 = localDW->dotAltTD * 0.1;
    y = (localDW->biasH_Log - localDW->BiasHSwitch) + a0;
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
        / 2.0 + a0;
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

    a0 = ((a0 + y) - a2) * ((rtb_Sum_g0_0 - y_0) / 2.0) + a2;
    if (a0 < 0.0) {
        rtb_RefGndSpd = -1.0;
    } else if (a0 > 0.0) {
        rtb_RefGndSpd = 1.0;
    } else if (a0 == 0.0) {
        rtb_RefGndSpd = 0.0;
    } else {
        rtb_RefGndSpd = (rtNaN);
    }

    if (a0 + 0.004000000000000001 < 0.0) {
        rtb_Sum_g0_0 = -1.0;
    } else if (a0 + 0.004000000000000001 > 0.0) {
        rtb_Sum_g0_0 = 1.0;
    } else if (a0 + 0.004000000000000001 == 0.0) {
        rtb_Sum_g0_0 = 0.0;
    } else {
        rtb_Sum_g0_0 = (rtNaN);
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

    localDW->fh = (a0 / 0.004000000000000001 - rtb_RefGndSpd) * -0.4 *
        ((rtb_Sum_g0_0 - a2) / 2.0) - 0.4 * rtb_RefGndSpd;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        localDW->chartAbsoluteTimeCounter = static_cast<int32_T>
            (localDW->chartAbsoluteTimeCounter + 1);
        rtb_SpdAND = static_cast<boolean_T>(static_cast<int32_T>
            ((rty_RealUAVState->AirSpeed > 15.0) &
             (rtu_RealUAVLatLonState->Height_meter > 30.0)));
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (rtb_SpdAND) ^ 1))) | static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (localDW->condWasTrueAtLastTimeStep_1) ^ 1)))))) {
            localDW->durationLastReferenceTick_1 =
                localDW->chartAbsoluteTimeCounter;
        }

        localDW->condWasTrueAtLastTimeStep_1 = rtb_SpdAND;
        if (static_cast<uint32_T>(localDW->is_active_c16_Real2SimGuidance) == 0U)
        {
            localDW->chartAbsoluteTimeCounter = 0;
            localDW->is_active_c16_Real2SimGuidance = 1U;
            localDW->durationLastReferenceTick_1 =
                localDW->chartAbsoluteTimeCounter;
            localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NotTakeOff;
            rtb_SpdAND = false;
            localDW->condWasTrueAtLastTimeStep_1 = static_cast<boolean_T>(
                static_cast<int32_T>((rty_RealUAVState->AirSpeed > 15.0) &
                (rtu_RealUAVLatLonState->Height_meter > 30.0)));
        } else if (static_cast<int32_T>(localDW->is_c16_Real2SimGuidance) == 1)
        {
            rtb_SpdAND = true;
        } else {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(rtb_SpdAND) ^ 1))) |
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                     (localDW->condWasTrueAtLastTimeStep_1) ^ 1)))))) {
                localDW->durationLastReferenceTick_1 =
                    localDW->chartAbsoluteTimeCounter;
            }

            localDW->condWasTrueAtLastTimeStep_1 = rtb_SpdAND;
            if (static_cast<int32_T>(localDW->chartAbsoluteTimeCounter -
                                     localDW->durationLastReferenceTick_1) > 10)
            {
                localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_InAir;
                rtb_SpdAND = true;
            } else {
                rtb_SpdAND = false;
            }
        }

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

        if (static_cast<uint32_T>(localDW->is_active_c34_Real2SimGuidance) == 0U)
        {
            localDW->is_active_c34_Real2SimGuidance = 1U;
            localDW->is_c34_Real2SimGuidance =
                Real2SimGuidance_IN_DebounceExecution;
            localDW->Terminate = false;
            localDW->is_DebounceExecution = Real2SimGuidance_IN_Persuit;
            *rty_ExecutionTrigger = 0.0;
            localDW->is_Persuit = Real2SimGuidance_IN_Normal;
        } else {
            switch (localDW->is_c34_Real2SimGuidance) {
              case Real2SimGuidance_IN_DebounceExecution:
                if (localDW->FlightMode_Log == 6.0) {
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_DebounceExecution =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Landing;
                    *rty_ExecutionTrigger = 0.0;
                } else {
                    localDW->Terminate = false;
                    switch (localDW->is_DebounceExecution) {
                      case Real2SimGuidance_IN_Debounce:
                        if (static_cast<uint32_T>(localDW->temporalCounter_i1) >=
                            180U) {
                            localDW->is_Debounce =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_DebounceExecution =
                                Real2SimGuidance_IN_Persuit;
                            *rty_ExecutionTrigger = 0.0;
                            localDW->is_Persuit = Real2SimGuidance_IN_Fault;
                            localDW->temporalCounter_i1 = 0U;
                        } else if (static_cast<int32_T>(localDW->is_Debounce) ==
                                   1) {
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i2) >= 60U) {
                                localDW->is_Debounce =
                                    Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                                localDW->is_DebounceExecution =
                                    Real2SimGuidance_IN_Persuit;
                                *rty_ExecutionTrigger = 0.0;
                                localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                            } else if (static_cast<boolean_T>
                                       (static_cast<int32_T>(static_cast<int32_T>
                                    (rtb_SpdAND) | static_cast<int32_T>
                                         (*rty_EngagedFlag)))) {
                                localDW->is_Debounce = Real2SimGuidance_IN_On;
                                localDW->temporalCounter_i2 = 0U;
                            }
                        } else if (static_cast<uint32_T>
                                   (localDW->temporalCounter_i2) >= 60U) {
                            localDW->is_Debounce =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_DebounceExecution =
                                Real2SimGuidance_IN_Engaged;
                            *rty_ExecutionTrigger = 1.0;
                        } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                     static_cast<int32_T>(*rty_EngagedFlag) ^ 1)))
                        {
                            localDW->is_Debounce = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2 = 0U;
                        }
                        break;

                      case Real2SimGuidance_IN_Engaged:
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(*rty_EngagedFlag) ^ 1))) {
                            localDW->is_DebounceExecution =
                                Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1 = 0U;
                            localDW->is_Debounce = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2 = 0U;
                        }
                        break;

                      default:
                        if (static_cast<int32_T>(localDW->is_Persuit) == 1) {
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i1) >= 600U) {
                                localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                            }
                        } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                     static_cast<int32_T>(rtb_SpdAND) |
                                     static_cast<int32_T>(*rty_EngagedFlag)))) {
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
                if (rtu_RealUAVLatLonState->Height_meter < 30.0) {
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_MissionCompletion;
                    localDW->Terminate = true;
                } else {
                    *rty_ExecutionTrigger = 0.0;
                }
                break;

              default:
                localDW->Terminate = true;
                break;
            }
        }

        if (localDW->Terminate) {
            rtmSetStopRequested(Real2SimGuidance_M, 1);
        }

        rtb_SpdAND = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(*rtu_ImmedModeSwitch) & static_cast<int32_T>
             (rtu_ControlSwitch[0])));
        if (rtb_SpdAND) {
            rtb_SumNorth = std::cos(rtu_ImmedGuidanceCMD->HeadingAngle) * 1000.0
                + rty_RealUAVState->North;
            rtb_SumEast = 1000.0 * std::sin(rtu_ImmedGuidanceCMD->HeadingAngle)
                + rty_RealUAVState->East;
            rtb_SwitchLookAheadPoint_idx_0 = rtb_SumNorth;
            rtb_Sum1_idx_1 = rtb_SumEast;
            rtb_SwitchLookAheadPoint_idx_2 = rtu_ImmedGuidanceCMD->Height;
        } else {
            rtb_SwitchLookAheadPoint_idx_0 = rtb_RealUAVNEUState_idx_0;
            rtb_Sum1_idx_1 = rtb_RealUAVNEUState_idx_1;
            rtb_SwitchLookAheadPoint_idx_2 = rtb_RealUAVNEUState_idx_2;
        }

        rtb_RefGndSpd = rtb_SwitchLookAheadPoint_idx_0 - rtb_Sum1_idx_1 * 0.0;
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_Sum_h_idx_0 = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtb_Abs1 = 0.017453292519943295 * rtb_Sum_h_idx_0;
        rtb_Down = std::sin(rtb_Abs1);
        rtb_Down = 1.0 - 0.0066943799901413295 * rtb_Down * rtb_Down;
        rtb_LongitudeGCS = 6.378137E+6 / std::sqrt(rtb_Down);
        rtb_Sum1_idx_0 = rt_atan2d_snf(1.0, rtb_LongitudeGCS *
            0.99330562000985867 / rtb_Down) * rtb_RefGndSpd * 57.295779513082323;
        rtb_Sum1_idx_1 = (rtb_SwitchLookAheadPoint_idx_0 * 0.0 + rtb_Sum1_idx_1)
            * rt_atan2d_snf(1.0, rtb_LongitudeGCS * std::cos(rtb_Abs1)) *
            57.295779513082323;
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_RefGndSpd = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum_h_idx_0 += rtb_Sum1_idx_0;
        rtb_RealUAVNEUState_idx_0 = rtb_Sum1_idx_1 + rtb_RefGndSpd;
        if (std::abs(rtb_Sum_h_idx_0) > 180.0) {
            rtb_Sum_h_idx_0 = rt_modd_snf(rtb_Sum_h_idx_0 + 180.0, 360.0) +
                -180.0;
        }

        rtb_RefGndSpd = std::abs(rtb_Sum_h_idx_0);
        if (rtb_RefGndSpd > 90.0) {
            if (rtb_Sum_h_idx_0 < 0.0) {
                rtb_RealUAVNEUState_idx_1 = -1.0;
            } else if (rtb_Sum_h_idx_0 > 0.0) {
                rtb_RealUAVNEUState_idx_1 = 1.0;
            } else if (rtb_Sum_h_idx_0 == 0.0) {
                rtb_RealUAVNEUState_idx_1 = 0.0;
            } else {
                rtb_RealUAVNEUState_idx_1 = (rtNaN);
            }

            rtb_Sum_h_idx_0 = (-(rtb_RefGndSpd + -90.0) + 90.0) *
                rtb_RealUAVNEUState_idx_1;
            i = 180;
        } else {
            i = 0;
        }

        rtb_Abs1 = static_cast<real_T>(i) + rtb_RealUAVNEUState_idx_0;
        if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
        }

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_RefGndSpd = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rty_LookAheadPoint->Latitude_deg = rtb_Sum_h_idx_0;
        rty_LookAheadPoint->Longitude_deg = rtb_Abs1;
        rty_LookAheadPoint->Height_meter = rtb_SwitchLookAheadPoint_idx_2 -
            (-rtb_RefGndSpd);
        rtb_SpdAND = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(*rtu_ImmedModeSwitch) & static_cast<int32_T>
             (rtu_ControlSwitch[1])));
        if (rtb_SpdAND) {
            *rty_RefAirspeed = rtu_ImmedGuidanceCMD->AirSpeed;
        } else {
            *rty_RefAirspeed = rtb_Switch_f;
        }
    }
}

void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const FixedWingGuidanceStateBus *rtu_SimUAVState,
    DW_Real2SimGuidance_f_T *localDW)
{
    real_T Down;
    int_T i;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        Down = -localDW->NorthEastHeight[2];
        if (std::isnan(-localDW->NorthEastHeight[2])) {
            localDW->MemoryRefHeight_PreviousInput = -150.0;
        } else {
            localDW->MemoryRefHeight_PreviousInput = -localDW->NorthEastHeight[2];
        }

        for (i = 0; i < 71; i++) {
            localDW->EastSequence_X[i] = localDW->EastSequence_X
                [static_cast<int_T>(i + 1)];
            localDW->HeightSequence_X[i] = localDW->HeightSequence_X[
                static_cast<int_T>(i + 1)];
            localDW->NorthSequence_X[i] = localDW->NorthSequence_X
                [static_cast<int_T>(i + 1)];
        }

        localDW->EastSequence_X[71] = rtu_SimUAVState->East;
        localDW->HeightSequence_X[71] = localDW->TrackInvH;
        localDW->NorthSequence_X[71] = rtu_SimUAVState->North;
    }

    if (localDW->ESO_MODE) {
        Real2SimGuidance_fale025h(localDW->SumY, 0.5, 0.1, &Down);
        Real2SimGuidance_fale025h(localDW->SumY, 0.25, 0.1, &Down);
    }
}

void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot)
{
    real_T y;
    real_T y_d;
    localXdot->TD_AirSpdADRC_CSTATE = localDW->dotTD;
    if (localDW->ESO_MODE) {
        Real2SimGuidance_fale025h(localDW->SumY, 0.5, 0.1, &y);
        Real2SimGuidance_fale025h(localDW->SumY, 0.25, 0.1, &y_d);
        localXdot->ESO_CSTATE = localDW->ESO_dot - 15.0 * localDW->SumY;
        localXdot->ESO_dot_CSTATE = (0.1 * localDW->GainADRCinvb0 +
            localDW->ESO_dotdot) - 75.0 * y;
        localXdot->ESO_dotdot_CSTATE = -(125.0 * y_d);
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

    localXdot->dotTD_CSTATE = localDW->fh_p;
    localXdot->TD_Alt_CSTATE = localDW->dotAltTD;
    localXdot->dotAltTD_CSTATE = localDW->fh;
}

void Real2SimGuidance_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_Real2SimGuidance_T
    *const Real2SimGuidance_M)
{
    rt_InitInfAndNaN(sizeof(real_T));
    rtmSetErrorStatusPointer(Real2SimGuidance_M, rt_errorStatus);
    rtmSetStopRequestedPtr(Real2SimGuidance_M, rt_stopRequested);
    Real2SimGuidance_M->solverInfo = (rt_solverInfo);
    rtmSetSimTimeStepPointer(Real2SimGuidance_M, rtsiGetSimTimeStepPtr
        (Real2SimGuidance_M->solverInfo));
    Real2SimGuidance_M->Timing.stepSize0 = (rtsiGetStepSize
        (Real2SimGuidance_M->solverInfo));
}
