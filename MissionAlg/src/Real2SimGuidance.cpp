//
// File: Real2SimGuidance.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 19 15:14:45 2021
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
#include "angdiff_e8uhYa4N.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_powd_snf.h"

// Named constants for Chart: '<Root>/TASgreaterthan15for1Sec'
const uint8_T Real2SimGuidance_IN_InAir{ 1U };

const uint8_T Real2SimGuidance_IN_NotTakeOff{ 2U };

// Named constants for Chart: '<Root>/TriggerTermination'
const uint8_T Real2SimGuidance_IN_InitialPersuit{ 1U };

const uint8_T Real2SimGuidance_IN_Landing{ 2U };

const uint8_T Real2SimGuidance_IN_MissionCompletion{ 3U };

const uint8_T Real2SimGuidance_IN_MissionExecution{ 4U };

// Forward declaration for local functions
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
   real_T lookaheadPoint[3], real_T *desiredHeading, real_T *desiredYaw, uint8_T
   *lookaheadDistFlag, real_T *crossTrackError, uint8_T *status);

//
// Output and update for atomic system:
//    '<S72>/fal(e,0.25,h)'
//    '<S72>/fal(e,0.5,h)'
//
void Real2SimGuidance_fale025h(real_T rtu_u, real_T rtu_u_j, real_T rtu_u_e,
  real_T *rty_y)
{
  real_T rtu_u_0;
  real_T tmp;

  // SignalConversion generated from: '<S75>/ SFunction '
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

  // End of SignalConversion generated from: '<S75>/ SFunction '
}

static void Real2SimGuidance_WaypointFollowerBase_getDistinctWpts(const real_T
  waypoints[219], real_T distinctWpts_data[], int32_T distinctWpts_size[2])
{
  int32_T i1;
  int32_T i2;
  int32_T ix;
  int32_T j;
  int32_T x_tmp;
  int8_T c_data[73];
  boolean_T x[219];
  boolean_T b[73];
  boolean_T exitg1;
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < 72; i2++) {
      x_tmp = 73 * i1 + i2;
      x[x_tmp] = (waypoints[((i2 + 2) + 73 * i1) - 1] != waypoints[x_tmp]);
    }

    x[73 * i1 + 72] = true;
  }

  i1 = 0;
  i2 = 146;
  x_tmp = 0;
  for (j = 0; j < 73; j++) {
    b[j] = false;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!x[ix - 1]) {
        ix += 73;
      } else {
        b[j] = true;
        exitg1 = true;
      }
    }

    if (b[j]) {
      x_tmp++;
    }
  }

  i1 = 0;
  for (i2 = 0; i2 < 73; i2++) {
    if (b[i2]) {
      c_data[i1] = static_cast<int8_T>(i2 + 1);
      i1++;
    }
  }

  distinctWpts_size[0] = x_tmp;
  distinctWpts_size[1] = 3;
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < x_tmp; i2++) {
      distinctWpts_data[i2 + distinctWpts_size[0] * i1] = waypoints[(73 * i1 +
        c_data[i2]) - 1];
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
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
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
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
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
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(real_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
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
    if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)->canFreeData)
    {
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
  real_T lambda;
  real_T lambda_tmp_tmp;
  real_T lambda_tmp_tmp_0;
  real_T lambda_tmp_tmp_1;
  real_T lambda_tmp_tmp_tmp;
  real_T lambda_tmp_tmp_tmp_0;
  real_T lambda_tmp_tmp_tmp_tmp;
  int32_T b_idx;
  int32_T b_idx_0;
  int32_T b_k;
  int32_T last;
  boolean_T exitg1;
  Real2SimGuidance_emxInit_real_T(&d, 2);
  b_k = d->size[0] * d->size[1];
  d->size[0] = 1;
  d->size[1] = static_cast<int32_T>(obj->NumWaypoints - 1.0);
  Real2SimGuidance_emxEnsureCapacity_real_T(d, b_k);
  last = static_cast<int32_T>(obj->NumWaypoints - 1.0) - 1;
  for (b_k = 0; b_k <= last; b_k++) {
    d->data[b_k] = 0.0;
    lambda_tmp_tmp_tmp = waypoints_data[static_cast<int32_T>((static_cast<real_T>
      (b_k) + 1.0) + 1.0) - 1];
    lambda_tmp_tmp_tmp_0 = waypoints_data[b_k];
    lambda_tmp_tmp = lambda_tmp_tmp_tmp - lambda_tmp_tmp_tmp_0;
    lambda = currentPose[0] - lambda_tmp_tmp_tmp_0;
    currentPose_0[0] = lambda;
    currentPose_1[0] = currentPose[0] - lambda_tmp_tmp_tmp;
    lambda_tmp_tmp_tmp = waypoints_data[(static_cast<int32_T>
      ((static_cast<real_T>(b_k) + 1.0) + 1.0) + waypoints_size[0]) - 1];
    lambda_tmp_tmp_tmp_0 = waypoints_data[b_k + waypoints_size[0]];
    lambda_tmp_tmp_0 = lambda_tmp_tmp_tmp - lambda_tmp_tmp_tmp_0;
    currentPose_tmp = currentPose[1] - lambda_tmp_tmp_tmp_0;
    currentPose_0[1] = currentPose_tmp;
    currentPose_1[1] = currentPose[1] - lambda_tmp_tmp_tmp;
    lambda_tmp_tmp_1 = waypoints_data[(static_cast<int32_T>((static_cast<real_T>
      (b_k) + 1.0) + 1.0) + (waypoints_size[0] << 1)) - 1];
    lambda_tmp_tmp_tmp_tmp = waypoints_data[b_k + (waypoints_size[0] << 1)];
    lambda_tmp_tmp_tmp = lambda_tmp_tmp_1 - lambda_tmp_tmp_tmp_tmp;
    currentPose_tmp_0 = currentPose[2] - lambda_tmp_tmp_tmp_tmp;
    currentPose_0[2] = currentPose_tmp_0;
    currentPose_1[2] = currentPose[2] - lambda_tmp_tmp_1;
    lambda = (currentPose_tmp_0 * lambda_tmp_tmp_tmp + (currentPose_tmp *
               lambda_tmp_tmp_0 + lambda * lambda_tmp_tmp)) /
      (lambda_tmp_tmp_tmp * lambda_tmp_tmp_tmp + (lambda_tmp_tmp_0 *
        lambda_tmp_tmp_0 + lambda_tmp_tmp * lambda_tmp_tmp));
    currentPose_2[0] = currentPose[0] - (lambda_tmp_tmp * lambda +
      waypoints_data[b_k]);
    currentPose_2[1] = currentPose[1] - (lambda_tmp_tmp_0 * lambda +
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
    } else if ((d->data[0] > d->data[d->size[1] - 1]) || (std::isnan(d->data[0])
                && (!std::isnan(d->data[d->size[1] - 1])))) {
      b_idx = d->size[1];
    } else {
      b_idx = 1;
    }
  } else {
    if (!std::isnan(d->data[0])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k <= last)) {
        if (!std::isnan(d->data[b_k - 1])) {
          b_idx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }

    if (b_idx == 0) {
      b_idx = 1;
    } else {
      lambda_tmp_tmp = d->data[b_idx - 1];
      b_idx_0 = b_idx;
      for (b_k = b_idx + 1; b_k <= last; b_k++) {
        lambda_tmp_tmp_0 = d->data[b_k - 1];
        if (lambda_tmp_tmp > lambda_tmp_tmp_0) {
          lambda_tmp_tmp = lambda_tmp_tmp_0;
          b_idx_0 = b_k;
        }
      }

      b_idx = b_idx_0;
    }
  }

  Real2SimGuidance_emxFree_real_T(&d);
  obj->WaypointIndex = b_idx;
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
    curEndWaypoint_1 = (curEndWaypoint_tmp / tmp_0 * (tmp[0] / curEndWaypoint_1)
                        + curEndWaypoint_tmp_0 / tmp_0 * (tmp[1] /
      curEndWaypoint_1)) + curEndWaypoint_tmp_1 / tmp_0 * (tmp[2] /
      curEndWaypoint_1);
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

    curStartWaypoint[0] = waypoints_data[static_cast<int32_T>(obj->WaypointIndex)
      - 1];
    curEndWaypoint[0] = waypoints_data[static_cast<int32_T>(obj->WaypointIndex +
      1.0) - 1];
    curStartWaypoint[1] = waypoints_data[(static_cast<int32_T>
      (obj->WaypointIndex) + waypoints_size[0]) - 1];
    curEndWaypoint[1] = waypoints_data[(static_cast<int32_T>(obj->WaypointIndex
      + 1.0) + waypoints_size[0]) - 1];
    curStartWaypoint[2] = waypoints_data[(static_cast<int32_T>
      (obj->WaypointIndex) + (waypoints_size[0] << 1)) - 1];
    curEndWaypoint[2] = waypoints_data[(static_cast<int32_T>(obj->WaypointIndex
      + 1.0) + (waypoints_size[0] << 1)) - 1];
  }
}

static void Real2SimGuidance_WaypointFollowerBase_stepInternal
  (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
   real_T currentPose[4], const real_T waypointsIn[219], real_T lookaheadDist,
   real_T lookaheadPoint[3], real_T *desiredHeading, real_T *desiredYaw, uint8_T
   *lookaheadDistFlag, real_T *crossTrackError, uint8_T *status)
{
  real_T b_waypointsIn_data[219];
  real_T waypoints_data[219];
  real_T appendedWaypoints_data[6];
  real_T currentPose_0[3];
  real_T currentPose_1[3];
  real_T currentPose_2[3];
  real_T virtualWaypoint[3];
  real_T b;
  real_T b_tmp_idx_2_tmp;
  real_T currentPose_tmp;
  real_T currentPose_tmp_0;
  real_T lambda;
  real_T lambda_tmp_tmp;
  real_T lambda_tmp_tmp_0;
  int32_T b_waypointsIn_size[2];
  int32_T waypoints_size[2];
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_k;
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
         (obj->WaypointsInternal[b_k]) && std::isnan(waypointsIn[b_k]))) {
      b_k++;
    } else {
      p_0 = false;
      exitg1 = true;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    std::memcpy(&obj->WaypointsInternal[0], &waypointsIn[0], 219U * sizeof
                (real_T));
    obj->WaypointIndex = 1.0;
    obj->SearchFlag = true;
  }

  Real2SimGuidance_WaypointFollowerBase_getDistinctWpts(waypointsIn,
    b_waypointsIn_data, b_waypointsIn_size);
  obj->NumWaypoints = b_waypointsIn_size[0];
  obj->LookaheadDistance = lookaheadDist;
  if (b_waypointsIn_size[0] == 0) {
    lookaheadPoint[0] = lookaheadDist * std::cos(currentPose[3]) + currentPose[0];
    lookaheadPoint[1] = lookaheadDist * std::sin(currentPose[3]) + currentPose[1];
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
      if (Real2SimGuidance_norm(virtualWaypoint) < 1.4901161193847656E-8) {
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
          appendedWaypoints_data[b_k << 1] = obj->InitialPose[b_k];
          appendedWaypoints_data[1 + (b_k << 1)] =
            b_waypointsIn_data[b_waypointsIn_size[0] * b_k];
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
      b_k = b_waypointsIn_size[0] * 3;
      if (0 <= b_k - 1) {
        std::memcpy(&waypoints_data[0], &b_waypointsIn_data[0], b_k * sizeof
                    (real_T));
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

      virtualWaypoint[0] = waypoints_data[static_cast<int32_T>
        (obj->WaypointIndex) - 1];
      lookaheadPoint[0] = waypoints_data[static_cast<int32_T>(obj->WaypointIndex
        + 1.0) - 1];
      virtualWaypoint[1] = waypoints_data[(static_cast<int32_T>
        (obj->WaypointIndex) + waypoints_size[0]) - 1];
      lookaheadPoint[1] = waypoints_data[(static_cast<int32_T>
        (obj->WaypointIndex + 1.0) + waypoints_size[0]) - 1];
      virtualWaypoint[2] = waypoints_data[(static_cast<int32_T>
        (obj->WaypointIndex) + (waypoints_size[0] << 1)) - 1];
      lookaheadPoint[2] = waypoints_data[(static_cast<int32_T>
        (obj->WaypointIndex + 1.0) + (waypoints_size[0] << 1)) - 1];
      Real2SimGuidance_WaypointFollowerBase_endWaypointReached_b(obj,
        waypoints_data, waypoints_size, virtualWaypoint, lookaheadPoint,
        currentPose);
      b = lookaheadPoint[0] - virtualWaypoint[0];
      lambda = currentPose[0] - virtualWaypoint[0];
      currentPose_0[0] = lambda;
      currentPose_1[0] = currentPose[0] - lookaheadPoint[0];
      lambda_tmp_tmp = lookaheadPoint[1] - virtualWaypoint[1];
      currentPose_tmp = currentPose[1] - virtualWaypoint[1];
      currentPose_0[1] = currentPose_tmp;
      currentPose_1[1] = currentPose[1] - lookaheadPoint[1];
      lambda_tmp_tmp_0 = lookaheadPoint[2] - virtualWaypoint[2];
      currentPose_tmp_0 = currentPose[2] - virtualWaypoint[2];
      currentPose_0[2] = currentPose_tmp_0;
      currentPose_1[2] = currentPose[2] - lookaheadPoint[2];
      lambda = (currentPose_tmp_0 * lambda_tmp_tmp_0 + (currentPose_tmp *
                 lambda_tmp_tmp + lambda * b)) / (lambda_tmp_tmp_0 *
        lambda_tmp_tmp_0 + (lambda_tmp_tmp * lambda_tmp_tmp + b * b));
      currentPose_2[0] = currentPose[0] - (b * lambda + virtualWaypoint[0]);
      currentPose_2[1] = currentPose[1] - (lambda_tmp_tmp * lambda +
        virtualWaypoint[1]);
      currentPose_2[2] = currentPose[2] - (lambda_tmp_tmp_0 * lambda +
        virtualWaypoint[2]);
      if (lambda < 0.0) {
        *crossTrackError = Real2SimGuidance_norm(currentPose_0);
      } else if (lambda > 1.0) {
        *crossTrackError = Real2SimGuidance_norm(currentPose_1);
      } else {
        *crossTrackError = Real2SimGuidance_norm(currentPose_2);
      }

      if (obj->LastWaypointFlag) {
        lambda = (((currentPose[0] - virtualWaypoint[0]) * (lookaheadPoint[0] -
                    virtualWaypoint[0]) + (currentPose[1] - virtualWaypoint[1]) *
                   (lookaheadPoint[1] - virtualWaypoint[1])) + (currentPose[2] -
                   virtualWaypoint[2]) * (lookaheadPoint[2] - virtualWaypoint[2]))
          / (((lookaheadPoint[0] - virtualWaypoint[0]) * (lookaheadPoint[0] -
               virtualWaypoint[0]) + (lookaheadPoint[1] - virtualWaypoint[1]) *
              (lookaheadPoint[1] - virtualWaypoint[1])) + (lookaheadPoint[2] -
              virtualWaypoint[2]) * (lookaheadPoint[2] - virtualWaypoint[2]));
        currentPose_0[0] = currentPose[0] - (lambda * b + virtualWaypoint[0]);
        currentPose_0[1] = currentPose[1] - (lambda * lambda_tmp_tmp +
          virtualWaypoint[1]);
        currentPose_0[2] = currentPose[2] - (lambda * lambda_tmp_tmp_0 +
          virtualWaypoint[2]);
        *crossTrackError = Real2SimGuidance_norm(currentPose_0);
      }

      currentPose_tmp = std::abs(*crossTrackError);
      if ((!std::isinf(currentPose_tmp)) && (!std::isnan(currentPose_tmp))) {
        if (currentPose_tmp <= 2.2250738585072014E-308) {
          lambda = 4.94065645841247E-324;
          currentPose_tmp = 4.94065645841247E-324;
        } else {
          frexp(currentPose_tmp, &b_exponent);
          lambda = std::ldexp(1.0, b_exponent - 53);
          frexp(currentPose_tmp, &b_exponent_0);
          currentPose_tmp = std::ldexp(1.0, b_exponent_0 - 53);
        }
      } else {
        lambda = (rtNaN);
        currentPose_tmp = (rtNaN);
      }

      if (obj->LookaheadDistance <= std::fmax(std::sqrt(lambda), 5.0 *
           currentPose_tmp) + *crossTrackError) {
        obj->LookaheadDistance = obj->LookaheadFactor * *crossTrackError;
      }

      lambda = ((lookaheadPoint[0] - virtualWaypoint[0]) * (lookaheadPoint[0] -
                 virtualWaypoint[0]) + (lookaheadPoint[1] - virtualWaypoint[1]) *
                (lookaheadPoint[1] - virtualWaypoint[1])) + (lookaheadPoint[2] -
        virtualWaypoint[2]) * (lookaheadPoint[2] - virtualWaypoint[2]);
      currentPose_tmp = virtualWaypoint[0] - currentPose[0];
      currentPose_tmp_0 = virtualWaypoint[1] - currentPose[1];
      b_tmp_idx_2_tmp = virtualWaypoint[2] - currentPose[2];
      b = ((b * currentPose_tmp + lambda_tmp_tmp * currentPose_tmp_0) +
           lambda_tmp_tmp_0 * b_tmp_idx_2_tmp) * 2.0;
      lambda_tmp_tmp = std::sqrt(b * b - (((currentPose_tmp * currentPose_tmp +
        currentPose_tmp_0 * currentPose_tmp_0) + b_tmp_idx_2_tmp *
        b_tmp_idx_2_tmp) - obj->LookaheadDistance * obj->LookaheadDistance) *
        (4.0 * lambda));
      b = std::fmax((-b + lambda_tmp_tmp) / 2.0 / lambda, (-b - lambda_tmp_tmp) /
                    2.0 / lambda);
      lambda_tmp_tmp = (1.0 - b) * virtualWaypoint[0] + b * lookaheadPoint[0];
      lookaheadPoint[0] = lambda_tmp_tmp;
      lambda_tmp_tmp_0 = (1.0 - b) * virtualWaypoint[1] + b * lookaheadPoint[1];
      lookaheadPoint[1] = lambda_tmp_tmp_0;
      lookaheadPoint[2] = (1.0 - b) * virtualWaypoint[2] + b * lookaheadPoint[2];
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
  // InitializeConditions for Integrator: '<S74>/TD_AirSpdADRC'
  localX->TD_AirSpdADRC_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<S74>/dotTD'
  localX->dotTD_CSTATE = 0.0;

  // SystemInitialize for Enabled SubSystem: '<S67>/ESO'
  // InitializeConditions for Integrator: '<S72>/ESO'
  localX->ESO_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<S72>/ESO_dot'
  localX->ESO_dot_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<S72>/ESO_dotdot'
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
    // Start for MATLABSystem: '<S59>/TrackSimPath'
    localDW->obj.WaypointsInternal[i] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S59>/TrackSimPath'
    localDW->obj.WaypointsInternal[i] = (rtNaN);
  }

  // End of SystemInitialize for SubSystem: '<S4>/HeadingLogic'
  // End of SystemInitialize for SubSystem: '<Root>/Real2SimNav'
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
                      const real_T *rtu_SimUAVState_North, const real_T
                      *rtu_SimUAVState_East, const real_T
                      *rtu_SimUAVState_Height, const real_T
                      *rtu_SimUAVState_AirSpeed, const real_T
                      *rtu_SimUAVState_HeadingAngle, const RealUAVStateBus
                      *rtu_RealUAVLatLonState, const uint8_T *rtu_FlightMode,
                      const real_T *rtu_GroundSpd, LookAheadPoint
                      *rty_LookAheadPoint, real_T *rty_RefAirspeed, real_T
                      *rty_ExecutionTrigger, boolean_T *rty_EngagedFlag,
                      B_Real2SimGuidance_c_T *localB, DW_Real2SimGuidance_f_T
                      *localDW, X_Real2SimGuidance_n_T *localX)
{
  // local block i/o variables
  FixedWingGuidanceStateBus rtb_FixedWingGuidanceStateBus;
  real_T rtb_MatrixConcatenate[219];
  real_T tmp[4];
  real_T rtb_SwitchLookAheadNED[3];
  real_T a0;
  real_T rtb_Abs1;
  real_T rtb_Abs1_k;
  real_T rtb_Down;
  real_T rtb_LowerBound;
  real_T rtb_North;
  real_T rtb_RealUAVNEUState_idx_0;
  real_T rtb_RealUAVNEUState_idx_1;
  real_T rtb_RefGndSpd;
  real_T rtb_Sum;
  real_T rtb_Sum_g0_0;
  real_T rtb_Sum_k;
  real_T rtb_Sum_m_idx_0;
  real_T rtb_Switch;
  real_T
    rtb_TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_TargetSpeed_at_inport_0Inport1;
  real_T rtb_UpperBound;
  real_T skySpeed;
  real_T y;
  real_T y_0;
  int32_T i;
  uint8_T lookaheadFlag;
  boolean_T rtb_TakeOffTrigger;
  if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
    // DataStoreWrite: '<Root>/WriteFlightMode_Log'
    localDW->FlightMode_Log = *rtu_FlightMode;

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

    rtb_Sum = static_cast<real_T>(i) + LongitudeGCS;

    // Sum: '<S10>/Sum1'
    rtb_Abs1 = rtu_RealUAVLatLonState->Latitude_deg - rtb_Switch;

    // Switch: '<S18>/Switch' incorporates:
    //   Abs: '<S18>/Abs'
    //   Bias: '<S18>/Bias'
    //   Bias: '<S18>/Bias1'
    //   Constant: '<S18>/Constant2'
    //   Constant: '<S19>/Constant'
    //   Math: '<S18>/Math Function1'
    //   RelationalOperator: '<S19>/Compare'

    if (std::abs(rtb_Abs1) > 180.0) {
      rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S18>/Switch'

    // Abs: '<S15>/Abs1'
    rtb_Abs1_k = std::abs(rtb_Abs1);

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

    if (rtb_Abs1_k > 90.0) {
      // Signum: '<S15>/Sign1'
      if (rtb_Abs1 < 0.0) {
        rtb_Abs1 = -1.0;
      } else if (rtb_Abs1 > 0.0) {
        rtb_Abs1 = 1.0;
      } else if (rtb_Abs1 == 0.0) {
        rtb_Abs1 = 0.0;
      } else {
        rtb_Abs1 = (rtNaN);
      }

      // End of Signum: '<S15>/Sign1'
      rtb_Abs1_k = (-(rtb_Abs1_k + -90.0) + 90.0) * rtb_Abs1;
      i = 180;
    } else {
      rtb_Abs1_k = rtb_Abs1;
      i = 0;
    }

    // End of Switch: '<S15>/Switch'

    // Switch: '<S22>/Switch' incorporates:
    //   Abs: '<S22>/Abs'
    //   Bias: '<S22>/Bias'
    //   Bias: '<S22>/Bias1'
    //   Constant: '<S22>/Constant2'
    //   Constant: '<S26>/Constant'
    //   Math: '<S22>/Math Function1'
    //   RelationalOperator: '<S26>/Compare'

    if (std::abs(rtb_Sum) > 180.0) {
      rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S22>/Switch'

    // Sum: '<S11>/Sum' incorporates:
    //   Sum: '<S10>/Sum1'

    rtb_Sum_k = (rtu_RealUAVLatLonState->Longitude_deg - rtb_Sum) + static_cast<
      real_T>(i);

    // UnitConversion: '<S14>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Abs1 = 0.017453292519943295 * rtb_Abs1_k;

    // UnitConversion: '<S29>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Switch *= 0.017453292519943295;

    // Trigonometry: '<S30>/Trigonometric Function1'
    rtb_Sum = std::sin(rtb_Switch);

    // Sum: '<S30>/Sum1' incorporates:
    //   Constant: '<S30>/Constant'
    //   Product: '<S30>/Product1'

    rtb_Sum = 1.0 - Real2SimGuidance_ConstB.sqrt_e *
      Real2SimGuidance_ConstB.sqrt_e * rtb_Sum * rtb_Sum;

    // Product: '<S28>/Product1' incorporates:
    //   Constant: '<S28>/Constant1'
    //   Sqrt: '<S28>/sqrt'

    rtb_Abs1_k = 6.378137E+6 / std::sqrt(rtb_Sum);

    // Product: '<S13>/dNorth' incorporates:
    //   Constant: '<S28>/Constant2'
    //   Product: '<S28>/Product3'
    //   Trigonometry: '<S28>/Trigonometric Function1'

    rtb_Sum = rtb_Abs1 / rt_atan2d_snf(1.0, rtb_Abs1_k *
      Real2SimGuidance_ConstB.Sum1_h / rtb_Sum);

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

    // Product: '<S13>/dEast' incorporates:
    //   Constant: '<S28>/Constant3'
    //   Product: '<S28>/Product4'
    //   Trigonometry: '<S28>/Trigonometric Function'
    //   Trigonometry: '<S28>/Trigonometric Function2'
    //   UnitConversion: '<S14>/Unit Conversion'

    rtb_Abs1_k = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_k * std::cos(rtb_Switch)) *
      (0.017453292519943295 * rtb_Sum_k);

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

    rtb_FixedWingGuidanceStateBus.North = rtb_Sum *
      Real2SimGuidance_ConstB.SinCos_o2 + rtb_Abs1_k *
      Real2SimGuidance_ConstB.SinCos_o1;
    rtb_FixedWingGuidanceStateBus.East = rtb_Abs1_k *
      Real2SimGuidance_ConstB.SinCos_o2 - rtb_Sum *
      Real2SimGuidance_ConstB.SinCos_o1;
    rtb_FixedWingGuidanceStateBus.Height = rtu_RealUAVLatLonState->Height_meter
      + -AltitudeGCS;
    rtb_FixedWingGuidanceStateBus.AirSpeed =
      rtu_RealUAVLatLonState->AirSpeed_mps;
    rtb_FixedWingGuidanceStateBus.HeadingAngle = 0.017453292519943295 *
      rtu_RealUAVLatLonState->HeadingAngle_deg;
    rtb_FixedWingGuidanceStateBus.FlightPathAngle = 0.017453292519943295 *
      rtu_RealUAVLatLonState->FlightPathAngle_deg;
    rtb_FixedWingGuidanceStateBus.RollAngle = 0.017453292519943295 *
      rtu_RealUAVLatLonState->RollAngle_deg;
    rtb_FixedWingGuidanceStateBus.RollAngleRate = 0.0;

    // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S4>/GenerateTrack'
    // S-Function (sfix_udelay): '<S58>/EastSequence'
    rtb_MatrixConcatenate[145] = *rtu_SimUAVState_East;

    // Gain: '<S58>/TrackInvH'
    localB->TrackInvH = -*rtu_SimUAVState_Height;

    // S-Function (sfix_udelay): '<S58>/HeightSequence'
    rtb_MatrixConcatenate[218] = localB->TrackInvH;
    for (i = 0; i < 72; i++) {
      // S-Function (sfix_udelay): '<S58>/EastSequence'
      rtb_MatrixConcatenate[i + 73] = localDW->EastSequence_X[i];

      // S-Function (sfix_udelay): '<S58>/HeightSequence'
      rtb_MatrixConcatenate[i + 146] = localDW->HeightSequence_X[i];

      // S-Function (sfix_udelay): '<S58>/NorthSequence'
      rtb_MatrixConcatenate[i] = localDW->NorthSequence_X[i];
    }

    // S-Function (sfix_udelay): '<S58>/NorthSequence'
    rtb_MatrixConcatenate[72] = *rtu_SimUAVState_North;
    for (i = 0; i < 71; i++) {
      // Update for S-Function (sfix_udelay): '<S58>/EastSequence'
      localDW->EastSequence_X[i] = localDW->EastSequence_X[i + 1];

      // Update for S-Function (sfix_udelay): '<S58>/HeightSequence'
      localDW->HeightSequence_X[i] = localDW->HeightSequence_X[i + 1];

      // Update for S-Function (sfix_udelay): '<S58>/NorthSequence'
      localDW->NorthSequence_X[i] = localDW->NorthSequence_X[i + 1];
    }

    // Update for S-Function (sfix_udelay): '<S58>/EastSequence'
    localDW->EastSequence_X[71] = *rtu_SimUAVState_East;

    // Update for S-Function (sfix_udelay): '<S58>/HeightSequence'
    localDW->HeightSequence_X[71] = localB->TrackInvH;

    // Update for S-Function (sfix_udelay): '<S58>/NorthSequence'
    localDW->NorthSequence_X[71] = *rtu_SimUAVState_North;

    // End of Outputs for SubSystem: '<S4>/GenerateTrack'

    // Sum: '<S4>/Minus'
    rtb_Sum = rtb_FixedWingGuidanceStateBus.AirSpeed - *rtu_GroundSpd;

    // RelationalOperator: '<S62>/Compare' incorporates:
    //   Constant: '<S62>/Constant'
    //   DataStoreRead: '<S4>/ReadFlightMode_Log'

    localB->Compare = (localDW->FlightMode_Log == 3);

    // Outputs for Atomic SubSystem: '<S4>/SpeedControl'
    // Sum: '<S68>/Sum'
    rtb_Sum_m_idx_0 = *rtu_SimUAVState_North -
      rtb_FixedWingGuidanceStateBus.North;
    rtb_Abs1_k = *rtu_SimUAVState_East - rtb_FixedWingGuidanceStateBus.East;
    rtb_Sum_k = *rtu_SimUAVState_Height - *rtu_SimUAVState_Height;

    // DotProduct: '<S68>/Dot Product'
    a0 = rtb_Sum_m_idx_0 * rtb_Sum_m_idx_0;

    // Selector: '<S63>/WayPoint0d3' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Sum: '<S71>/Sum'

    rtb_Sum_m_idx_0 = rtb_MatrixConcatenate[72];

    // DotProduct: '<S68>/Dot Product'
    a0 += rtb_Abs1_k * rtb_Abs1_k;

    // Selector: '<S63>/WayPoint0d3' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Sum: '<S71>/Sum'

    rtb_Abs1_k = rtb_MatrixConcatenate[145];

    // DotProduct: '<S68>/Dot Product'
    a0 += rtb_Sum_k * rtb_Sum_k;

    // Selector: '<S63>/WayPoint0d3' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Sum: '<S71>/Sum'

    rtb_Sum_k = rtb_MatrixConcatenate[218];

    // Sqrt: '<S68>/sqrt' incorporates:
    //   DotProduct: '<S68>/Dot Product'

    rtb_Abs1 = std::sqrt(a0);

    // Gain: '<S63>/InverseY'
    localB->InverseY = -rtb_Abs1;

    // Sum: '<S70>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint0d3'
    //   Selector: '<S63>/WayPoint2d3'

    y = rtb_MatrixConcatenate[24] - rtb_MatrixConcatenate[72];

    // DotProduct: '<S70>/Dot Product'
    rtb_Sum_g0_0 = y * y;

    // Sum: '<S70>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint0d3'
    //   Selector: '<S63>/WayPoint2d3'

    y = rtb_MatrixConcatenate[97] - rtb_MatrixConcatenate[145];

    // DotProduct: '<S70>/Dot Product'
    rtb_Sum_g0_0 += y * y;

    // Sum: '<S70>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint0d3'
    //   Selector: '<S63>/WayPoint2d3'

    y = rtb_MatrixConcatenate[170] - rtb_MatrixConcatenate[218];

    // Sqrt: '<S70>/sqrt' incorporates:
    //   DotProduct: '<S70>/Dot Product'

    rtb_Switch = std::sqrt(y * y + rtb_Sum_g0_0);

    // Gain: '<S63>/InverseR'
    localB->InverseR = -rtb_Switch;

    // End of Outputs for SubSystem: '<S4>/SpeedControl'
    // End of Outputs for SubSystem: '<Root>/Real2SimNav'
  }

  // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
  // Outputs for Atomic SubSystem: '<S4>/SpeedControl'
  // Outputs for Atomic SubSystem: '<S63>/ADRC'
  // Outputs for Enabled SubSystem: '<S67>/ESO' incorporates:
  //   EnablePort: '<S72>/Enable'

  if (rtmIsMajorTimeStep(Real2SimGuidance_M) && rtmIsMajorTimeStep
      (Real2SimGuidance_M)) {
    localDW->ESO_MODE = localB->Compare;
  }

  if (localDW->ESO_MODE) {
    // Integrator: '<S72>/ESO'
    localB->ESO = localX->ESO_CSTATE;

    // Integrator: '<S72>/ESO_dot'
    localB->ESO_dot = localX->ESO_dot_CSTATE;

    // Integrator: '<S72>/ESO_dotdot'
    localB->ESO_dotdot = localX->ESO_dotdot_CSTATE;
  }

  // End of Outputs for SubSystem: '<S67>/ESO'

  // Integrator: '<S74>/dotTD'
  localB->dotTD = localX->dotTD_CSTATE;

  // MATLAB Function: '<S73>/fhan(e1,ce2,r,h1)' incorporates:
  //   Gain: '<S73>/Gain'
  //   Integrator: '<S74>/TD_AirSpdADRC'
  //   Sum: '<S67>/SumTD'
  //   Sum: '<S67>/SumTDdot'

  a0 = (localB->dotTD - localB->ESO_dot) * 2.9661889429554025 * 7.00933418379271;
  y = (localX->TD_AirSpdADRC_CSTATE - localB->ESO) + a0;
  if (y < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (y > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (y == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  skySpeed = (std::sqrt((8.0 * std::abs(y) + 245.65382850042508) *
                        245.65382850042508) - 245.65382850042508) * rtb_Sum_g0_0
    / 2.0 + a0;
  if (y + 245.65382850042508 < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (y + 245.65382850042508 > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (y + 245.65382850042508 == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  if (y - 245.65382850042508 < 0.0) {
    y_0 = -1.0;
  } else if (y - 245.65382850042508 > 0.0) {
    y_0 = 1.0;
  } else if (y - 245.65382850042508 == 0.0) {
    y_0 = 0.0;
  } else {
    y_0 = (rtNaN);
  }

  a0 = ((a0 + y) - skySpeed) * ((rtb_Sum_g0_0 - y_0) / 2.0) + skySpeed;
  if (a0 < 0.0) {
    skySpeed = -1.0;
  } else if (a0 > 0.0) {
    skySpeed = 1.0;
  } else if (a0 == 0.0) {
    skySpeed = 0.0;
  } else {
    skySpeed = (rtNaN);
  }

  if (a0 + 245.65382850042508 < 0.0) {
    y = -1.0;
  } else if (a0 + 245.65382850042508 > 0.0) {
    y = 1.0;
  } else if (a0 + 245.65382850042508 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  if (a0 - 245.65382850042508 < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (a0 - 245.65382850042508 > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (a0 - 245.65382850042508 == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  // Gain: '<S67>/GainADRCinvb0' incorporates:
  //   Gain: '<S73>/Gain1'
  //   MATLAB Function: '<S73>/fhan(e1,ce2,r,h1)'
  //   Sum: '<S67>/ESOpNLSEF'

  localB->GainADRCinvb0 = (-((a0 / 245.65382850042508 - skySpeed) * -5.0 * ((y -
    rtb_Sum_g0_0) / 2.0) - 5.0 * skySpeed) - localB->ESO_dotdot) *
    4.898253049157602;
  if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
    // ZeroOrderHold: '<S67>/ZOH_ADRC_U' incorporates:
    //   DataStoreWrite: '<S67>/WriteADRC_U_Log'

    localDW->ADRC_U_Log = localB->GainADRCinvb0;

    // ZeroOrderHold: '<S67>/ZOH_ADRC_LagDis' incorporates:
    //   DataStoreWrite: '<S67>/WriteLagDistance'
    //   Integrator: '<S74>/TD_AirSpdADRC'
    //   Sum: '<S67>/LagDistanceSum'

    localDW->LagDistance = localX->TD_AirSpdADRC_CSTATE - localB->InverseY;
  }

  // Sum: '<S67>/SumY'
  localB->SumY = localB->ESO - localB->InverseY;

  // MATLAB Function: '<S74>/fhan_AirSpdADRC' incorporates:
  //   Integrator: '<S74>/TD_AirSpdADRC'
  //   SignalConversion generated from: '<S78>/ SFunction '
  //   Sum: '<S74>/Sum1'

  a0 = localB->dotTD * 0.1;
  y = (localX->TD_AirSpdADRC_CSTATE - localB->InverseR) + a0;
  if (y < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (y > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (y == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  skySpeed = (std::sqrt((8.0 * std::abs(y) + 0.005000000000000001) *
                        0.005000000000000001) - 0.005000000000000001) *
    rtb_Sum_g0_0 / 2.0 + a0;
  if (y + 0.005000000000000001 < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (y + 0.005000000000000001 > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (y + 0.005000000000000001 == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  if (y - 0.005000000000000001 < 0.0) {
    y_0 = -1.0;
  } else if (y - 0.005000000000000001 > 0.0) {
    y_0 = 1.0;
  } else if (y - 0.005000000000000001 == 0.0) {
    y_0 = 0.0;
  } else {
    y_0 = (rtNaN);
  }

  a0 = ((a0 + y) - skySpeed) * ((rtb_Sum_g0_0 - y_0) / 2.0) + skySpeed;
  if (a0 < 0.0) {
    skySpeed = -1.0;
  } else if (a0 > 0.0) {
    skySpeed = 1.0;
  } else if (a0 == 0.0) {
    skySpeed = 0.0;
  } else {
    skySpeed = (rtNaN);
  }

  if (a0 + 0.005000000000000001 < 0.0) {
    y = -1.0;
  } else if (a0 + 0.005000000000000001 > 0.0) {
    y = 1.0;
  } else if (a0 + 0.005000000000000001 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  if (a0 - 0.005000000000000001 < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (a0 - 0.005000000000000001 > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (a0 - 0.005000000000000001 == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  localB->fh_p = (a0 / 0.005000000000000001 - skySpeed) * -0.5 * ((y -
    rtb_Sum_g0_0) / 2.0) - 0.5 * skySpeed;

  // End of MATLAB Function: '<S74>/fhan_AirSpdADRC'
  // End of Outputs for SubSystem: '<S63>/ADRC'
  if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
    // Sum: '<S69>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint1d3'
    //   Sum: '<S71>/Sum'

    y = rtb_MatrixConcatenate[48] - rtb_Sum_m_idx_0;

    // DotProduct: '<S69>/Dot Product'
    rtb_Sum_g0_0 = y * y;

    // Sum: '<S71>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint3d3'
    //   Sum: '<S69>/Sum'

    a0 = rtb_MatrixConcatenate[0] - rtb_Sum_m_idx_0;

    // DotProduct: '<S71>/Dot Product'
    rtb_RefGndSpd = a0 * a0;

    // Sum: '<S69>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint1d3'
    //   Sum: '<S71>/Sum'

    y = rtb_MatrixConcatenate[121] - rtb_Abs1_k;

    // DotProduct: '<S69>/Dot Product'
    rtb_Sum_g0_0 += y * y;

    // Sum: '<S71>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint3d3'
    //   Sum: '<S69>/Sum'

    a0 = rtb_MatrixConcatenate[73] - rtb_Abs1_k;

    // DotProduct: '<S71>/Dot Product'
    rtb_RefGndSpd += a0 * a0;

    // Sum: '<S69>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint1d3'
    //   Sum: '<S71>/Sum'

    y = rtb_MatrixConcatenate[194] - rtb_Sum_k;

    // Sum: '<S71>/Sum' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   Selector: '<S63>/WayPoint3d3'
    //   Sum: '<S69>/Sum'

    a0 = rtb_MatrixConcatenate[146] - rtb_Sum_k;

    // Sqrt: '<S69>/sqrt' incorporates:
    //   DotProduct: '<S69>/Dot Product'

    rtb_Down = std::sqrt(y * y + rtb_Sum_g0_0);

    // Sum: '<S63>/ActRngmMinRng'
    rtb_Abs1 -= rtb_Down;

    // Sum: '<S63>/ComputeLB'
    rtb_LowerBound = rtb_Down - rtb_Switch;

    // Sum: '<S63>/ComputeUB' incorporates:
    //   DotProduct: '<S71>/Dot Product'
    //   Sqrt: '<S71>/sqrt'

    rtb_UpperBound = std::sqrt(a0 * a0 + rtb_RefGndSpd) - rtb_Switch;

    // Sum: '<S63>/RefRngmMinRng'
    rtb_Down = rtb_Switch - rtb_Down;

    // Sum: '<S63>/SumSpd' incorporates:
    //   DataStoreWrite: '<S67>/WriteADRC_U_Log'

    rtb_RefGndSpd = (rtb_Sum + localDW->ADRC_U_Log) + *rtu_SimUAVState_AirSpeed;

    // SignalConversion generated from: '<S63>/TargetSpeed'
    rtb_TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_TargetSpeed_at_inport_0Inport1
      = *rtu_SimUAVState_AirSpeed;

    // Saturate: '<S63>/Saturation'
    if (rtb_Abs1 <= 71.272727272727266) {
      rtb_Abs1 = 71.272727272727266;
    }

    // End of Saturate: '<S63>/Saturation'

    // Sum: '<S63>/biasHm70' incorporates:
    //   Math: '<S63>/Square'
    //   Product: '<S63>/Divide'

    rtb_Down = rtb_Down * rtb_Down / rtb_Abs1 - rtb_Down;

    // Outputs for Atomic SubSystem: '<S4>/HeadingLogic'
    // SignalConversion generated from: '<S59>/TrackSimPath'
    tmp[0] = rtb_FixedWingGuidanceStateBus.North;
    tmp[1] = rtb_FixedWingGuidanceStateBus.East;
    tmp[2] = localDW->MemoryRefHeight_PreviousInput;
    tmp[3] = rtb_FixedWingGuidanceStateBus.HeadingAngle;

    // MATLABSystem: '<S59>/TrackSimPath' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   DataStoreWrite: '<S59>/WriteCrossTrackError'
    //   DataStoreWrite: '<S59>/WriteStatus_Log'
    //   Gain: '<S4>/LookaheadT'

    Real2SimGuidance_WaypointFollowerBase_stepInternal(&localDW->obj, tmp,
      rtb_MatrixConcatenate, 3.6 *
      rtb_TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_TargetSpeed_at_inport_0Inport1,
      rtb_SwitchLookAheadNED, &rtb_Abs1, &rtb_Switch, &lookaheadFlag,
      &localDW->CrossTrackError, &localDW->Status_Log);

    // Switch: '<S59>/SwitchLookAheadNED' incorporates:
    //   Concatenate: '<S58>/Matrix Concatenate'
    //   DataStoreWrite: '<S59>/WriteStatus_Log'
    //   Selector: '<S59>/WayPoint3d3'
    //   Sum: '<S65>/EastArrow'
    //   Sum: '<S65>/NorthArrow'
    //   Switch: '<S59>/SwitchTargetHDG'
    //   Trigonometry: '<S65>/HdgCmd'

    if (localDW->Status_Log > 0) {
      rtb_SwitchLookAheadNED[0] = rtb_MatrixConcatenate[0];
      rtb_SwitchLookAheadNED[1] = rtb_MatrixConcatenate[73];
      rtb_SwitchLookAheadNED[2] = rtb_MatrixConcatenate[146];
      rtb_Abs1 = rt_atan2d_snf(rtb_MatrixConcatenate[73] -
        rtb_FixedWingGuidanceStateBus.East, rtb_MatrixConcatenate[0] -
        rtb_FixedWingGuidanceStateBus.North);
    }

    // End of Switch: '<S59>/SwitchLookAheadNED'
    // End of Outputs for SubSystem: '<S4>/HeadingLogic'

    // DataStoreWrite: '<S4>/WriteHeading_Log' incorporates:
    //   MATLAB Function: '<S4>/AngLog'

    localDW->Heading_Log[0] = angdiff_e8uhYa4N
      (rtb_FixedWingGuidanceStateBus.HeadingAngle, rtb_Abs1);
    localDW->Heading_Log[1] = angdiff_e8uhYa4N(0.0,
      rtb_FixedWingGuidanceStateBus.HeadingAngle);
    localDW->Heading_Log[2] = angdiff_e8uhYa4N(0.0, rtb_Abs1);
  }

  // End of Outputs for SubSystem: '<S4>/SpeedControl'

  // Integrator: '<S64>/TD_Alt' incorporates:
  //   DataStoreWrite: '<S4>/WritebiasH_Log'

  localDW->biasH_Log = localX->TD_Alt_CSTATE;
  if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
    // Switch: '<S4>/BiasHSwitch'
    if (localDW->MemoryExecutionTrigger_PreviousInput != 0.0) {
      // Switch: '<S4>/BiasHSwitch' incorporates:
      //   Constant: '<S4>/ZeroBias'

      localB->BiasHSwitch = 0.0;
    } else {
      // Switch: '<S4>/BiasHSwitch'
      localB->BiasHSwitch = rtb_Down;
    }

    // End of Switch: '<S4>/BiasHSwitch'

    // Truth Table: '<S4>/Engagement' incorporates:
    //   DataStoreRead: '<S4>/ReadLagDistance'
    //   DataStoreWrite: '<S59>/WriteCrossTrackError'

    //  Front Distance within Upper &  Lower Bound
    //  CrossTrack Error within 1.5 Second Bound
    if ((localDW->LagDistance < rtb_UpperBound) && (localDW->LagDistance >
         rtb_LowerBound) && (localDW->CrossTrackError <
         rtb_TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_TargetSpeed_at_inport_0Inport1
         * 1.5)) {
      //  Real UAV Engaged with Simulation UAV
      *rty_EngagedFlag = true;
    } else {
      //  Default
      //  Real UAV Not Engaged with Simulation UAV
      *rty_EngagedFlag = false;
    }

    // End of Truth Table: '<S4>/Engagement'

    // Outputs for Atomic SubSystem: '<S4>/MaxBrake'
    // Trigonometry: '<S61>/North'
    rtb_North = std::cos(*rtu_SimUAVState_HeadingAngle);

    // Sum: '<S61>/SumNorthBrk' incorporates:
    //   Constant: '<S61>/AheadRange'
    //   Product: '<S61>/NorthDisBrk'

    rtb_Abs1 = 126.0 * rtb_North + *rtu_SimUAVState_North;

    // Trigonometry: '<S61>/East'
    rtb_North = std::sin(*rtu_SimUAVState_HeadingAngle);

    // Sum: '<S61>/SumEastBrk' incorporates:
    //   Constant: '<S61>/AheadRange'
    //   Product: '<S61>/EastDisBrk'

    rtb_Switch = 126.0 * rtb_North + *rtu_SimUAVState_East;

    // Gain: '<S61>/Up2Down'
    rtb_Down = -*rtu_SimUAVState_Height;

    // Sum: '<S66>/Sum'
    rtb_LowerBound = rtb_Abs1 - rtb_FixedWingGuidanceStateBus.North;
    rtb_UpperBound = rtb_Switch - rtb_FixedWingGuidanceStateBus.East;
    rtb_TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_TargetSpeed_at_inport_0Inport1
      = rtb_Down - localDW->MemoryRefHeight_PreviousInput;

    // End of Outputs for SubSystem: '<S4>/MaxBrake'

    // Gain: '<S4>/NED2NEU' incorporates:
    //   Switch: '<S59>/SwitchLookAheadNED'

    localB->NorthEastHeight[0] = rtb_SwitchLookAheadNED[0];
    localB->NorthEastHeight[1] = rtb_SwitchLookAheadNED[1];
    localB->NorthEastHeight[2] = -rtb_SwitchLookAheadNED[2];

    // ZeroOrderHold: '<S4>/LookaheadPoint_ZOH' incorporates:
    //   DataStoreWrite: '<S4>/WritebiasH_Log'
    //   Gain: '<S4>/NED2NEU'
    //   Sum: '<S4>/SumBiasH'

    rtb_RealUAVNEUState_idx_0 = localB->NorthEastHeight[0];
    rtb_RealUAVNEUState_idx_1 = localB->NorthEastHeight[1];
    rtb_North = localB->NorthEastHeight[2] + localDW->biasH_Log;

    // Outputs for Atomic SubSystem: '<S4>/MaxBrake'
    // Switch: '<S61>/BrkSwitch' incorporates:
    //   Constant: '<S61>/MaxBrake'
    //   DotProduct: '<S66>/Dot Product'
    //   Sqrt: '<S66>/sqrt'

    if (!(std::sqrt((rtb_LowerBound * rtb_LowerBound + rtb_UpperBound *
                     rtb_UpperBound) +
                    rtb_TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_TargetSpeed_at_inport_0Inport1
                    * rtb_TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_TargetSpeed_at_inport_0Inport1)
          >= 252.0)) {
      rtb_RefGndSpd = 0.0;
    }

    // End of Switch: '<S61>/BrkSwitch'

    // Saturate: '<S61>/SpeedProtection'
    if (rtb_RefGndSpd > 41.0) {
      *rty_RefAirspeed = 41.0;
    } else if (rtb_RefGndSpd < 29.0) {
      *rty_RefAirspeed = 29.0;
    } else {
      *rty_RefAirspeed = rtb_RefGndSpd;
    }

    // End of Saturate: '<S61>/SpeedProtection'
    // End of Outputs for SubSystem: '<S4>/MaxBrake'
  }

  // Integrator: '<S64>/dotAltTD'
  localB->dotAltTD = localX->dotAltTD_CSTATE;

  // MATLAB Function: '<S64>/fhan_Alt' incorporates:
  //   DataStoreWrite: '<S4>/WritebiasH_Log'
  //   SignalConversion generated from: '<S79>/ SFunction '
  //   Sum: '<S64>/Sum1'

  a0 = localB->dotAltTD * 0.1;
  y = (localDW->biasH_Log - localB->BiasHSwitch) + a0;
  if (y < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (y > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (y == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  skySpeed = (std::sqrt((8.0 * std::abs(y) + 0.010000000000000002) *
                        0.010000000000000002) - 0.010000000000000002) *
    rtb_Sum_g0_0 / 2.0 + a0;
  if (y + 0.010000000000000002 < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (y + 0.010000000000000002 > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (y + 0.010000000000000002 == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  if (y - 0.010000000000000002 < 0.0) {
    y_0 = -1.0;
  } else if (y - 0.010000000000000002 > 0.0) {
    y_0 = 1.0;
  } else if (y - 0.010000000000000002 == 0.0) {
    y_0 = 0.0;
  } else {
    y_0 = (rtNaN);
  }

  a0 = ((a0 + y) - skySpeed) * ((rtb_Sum_g0_0 - y_0) / 2.0) + skySpeed;
  if (a0 < 0.0) {
    rtb_RefGndSpd = -1.0;
  } else if (a0 > 0.0) {
    rtb_RefGndSpd = 1.0;
  } else if (a0 == 0.0) {
    rtb_RefGndSpd = 0.0;
  } else {
    rtb_RefGndSpd = (rtNaN);
  }

  if (a0 + 0.010000000000000002 < 0.0) {
    y = -1.0;
  } else if (a0 + 0.010000000000000002 > 0.0) {
    y = 1.0;
  } else if (a0 + 0.010000000000000002 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  if (a0 - 0.010000000000000002 < 0.0) {
    rtb_Sum_g0_0 = -1.0;
  } else if (a0 - 0.010000000000000002 > 0.0) {
    rtb_Sum_g0_0 = 1.0;
  } else if (a0 - 0.010000000000000002 == 0.0) {
    rtb_Sum_g0_0 = 0.0;
  } else {
    rtb_Sum_g0_0 = (rtNaN);
  }

  localB->fh = -(a0 / 0.010000000000000002 - rtb_RefGndSpd) * ((y - rtb_Sum_g0_0)
    / 2.0) - rtb_RefGndSpd;

  // End of MATLAB Function: '<S64>/fhan_Alt'
  // End of Outputs for SubSystem: '<Root>/Real2SimNav'
  if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
    // Chart: '<Root>/TASgreaterthan15for1Sec'
    if (localDW->is_active_c16_Real2SimGuidance == 0U) {
      localDW->is_active_c16_Real2SimGuidance = 1U;
      localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NotTakeOff;
      rtb_TakeOffTrigger = false;
      localDW->Count = 0.0;
    } else if (localDW->is_c16_Real2SimGuidance == 1) {
      rtb_TakeOffTrigger = true;

      // case IN_NotTakeOff:
    } else if (localDW->Count >= 9.0) {
      localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_InAir;
      rtb_TakeOffTrigger = true;
    } else if ((rtb_FixedWingGuidanceStateBus.AirSpeed < 15.0) ||
               (rtu_RealUAVLatLonState->Height_meter < 50.0)) {
      localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NotTakeOff;
      rtb_TakeOffTrigger = false;
      localDW->Count = 0.0;
    } else {
      rtb_TakeOffTrigger = false;
      localDW->Count++;
    }

    // End of Chart: '<Root>/TASgreaterthan15for1Sec'

    // Chart: '<Root>/TriggerTermination'
    if (localDW->is_active_c34_Real2SimGuidance == 0U) {
      localDW->is_active_c34_Real2SimGuidance = 1U;
      localB->Terminate = false;
      localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_InitialPersuit;
      *rty_ExecutionTrigger = 0.0;
      localDW->DataCounter = 0.0;
      localDW->ReturnCounter = 0.0;
    } else {
      switch (localDW->is_c34_Real2SimGuidance) {
       case Real2SimGuidance_IN_InitialPersuit:
        if (localDW->DataCounter >= 149.0) {
          localDW->is_c34_Real2SimGuidance =
            Real2SimGuidance_IN_MissionExecution;
          *rty_ExecutionTrigger = 1.0;
          localDW->DataCounter = 0.0;
          localDW->ReturnCounter = 0.0;
        } else if (*rtu_FlightMode == 6) {
          localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_Landing;
          *rty_ExecutionTrigger = 0.0;
        } else {
          *rty_ExecutionTrigger = 0.0;
          if ((!rtb_TakeOffTrigger) || (!*rty_EngagedFlag)) {
            localDW->DataCounter = 0.0;
          } else {
            localDW->DataCounter++;
          }
        }
        break;

       case Real2SimGuidance_IN_Landing:
        if (rtu_RealUAVLatLonState->Height_meter < 30.0) {
          localDW->is_c34_Real2SimGuidance =
            Real2SimGuidance_IN_MissionCompletion;
          localB->Terminate = true;
        } else {
          *rty_ExecutionTrigger = 0.0;
        }
        break;

       case Real2SimGuidance_IN_MissionCompletion:
        localB->Terminate = true;
        break;

       default:
        // case IN_MissionExecution:
        if (*rtu_FlightMode == 6) {
          localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_Landing;
          *rty_ExecutionTrigger = 0.0;
        } else if (localDW->ReturnCounter >= 149.0) {
          localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_InitialPersuit;
          *rty_ExecutionTrigger = 0.0;
          localDW->DataCounter = 0.0;
          localDW->ReturnCounter = 0.0;
        } else {
          *rty_ExecutionTrigger = 1.0;
          if (*rty_EngagedFlag) {
            localDW->ReturnCounter = 0.0;
          } else {
            localDW->ReturnCounter++;
          }
        }
        break;
      }
    }

    // End of Chart: '<Root>/TriggerTermination'

    // Stop: '<Root>/Stop Simulation'
    if (localB->Terminate) {
      rtmSetStopRequested(Real2SimGuidance_M, 1);
    }

    // End of Stop: '<Root>/Stop Simulation'

    // Switch: '<S47>/Switch' incorporates:
    //   Abs: '<S47>/Abs'
    //   Bias: '<S47>/Bias'
    //   Bias: '<S47>/Bias1'
    //   Constant: '<S47>/Constant2'
    //   Constant: '<S48>/Constant'
    //   DataStoreRead: '<S3>/LatitudeGCS'
    //   Math: '<S47>/Math Function1'
    //   RelationalOperator: '<S48>/Compare'

    if (std::abs(LatitudeGCS) > 180.0) {
      rtb_Abs1 = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
    } else {
      rtb_Abs1 = LatitudeGCS;
    }

    // End of Switch: '<S47>/Switch'

    // Abs: '<S44>/Abs1'
    rtb_RefGndSpd = std::abs(rtb_Abs1);

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

    if (rtb_RefGndSpd > 90.0) {
      // Signum: '<S44>/Sign1'
      if (rtb_Abs1 < 0.0) {
        rtb_Abs1 = -1.0;
      } else if (rtb_Abs1 > 0.0) {
        rtb_Abs1 = 1.0;
      } else if (rtb_Abs1 == 0.0) {
        rtb_Abs1 = 0.0;
      } else {
        rtb_Abs1 = (rtNaN);
      }

      // End of Signum: '<S44>/Sign1'
      rtb_Abs1 *= -(rtb_RefGndSpd + -90.0) + 90.0;
      i = 180;
    } else {
      i = 0;
    }

    // End of Switch: '<S44>/Switch'

    // UnitConversion: '<S52>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Switch = 0.017453292519943295 * rtb_Abs1;

    // Trigonometry: '<S53>/Trigonometric Function1'
    rtb_Down = std::sin(rtb_Switch);

    // Sum: '<S53>/Sum1' incorporates:
    //   Constant: '<S53>/Constant'
    //   Product: '<S53>/Product1'

    rtb_Down = 1.0 - Real2SimGuidance_ConstB.sqrt_g *
      Real2SimGuidance_ConstB.sqrt_g * rtb_Down * rtb_Down;

    // Product: '<S50>/Product1' incorporates:
    //   Constant: '<S50>/Constant1'
    //   Sqrt: '<S50>/sqrt'

    rtb_Sum = 6.378137E+6 / std::sqrt(rtb_Down);

    // Sum: '<S35>/Sum' incorporates:
    //   DataStoreRead: '<S3>/LongitudeGCS'

    // Unit Conversion - from: rad to: deg
    // Expression: output = (57.2958*input) + (0)
    rtb_RefGndSpd = static_cast<real_T>(i) + LongitudeGCS;

    // Sum: '<S33>/Sum' incorporates:
    //   Constant: '<S50>/Constant2'
    //   Product: '<S36>/rad lat'
    //   Product: '<S36>/x*cos'
    //   Product: '<S36>/y*sin'
    //   Product: '<S50>/Product3'
    //   Sum: '<S36>/Sum'
    //   Trigonometry: '<S50>/Trigonometric Function1'
    //   UnitConversion: '<S37>/Unit Conversion'

    rtb_UpperBound = (rtb_RealUAVNEUState_idx_0 *
                      Real2SimGuidance_ConstB.SinCos_o2_b -
                      rtb_RealUAVNEUState_idx_1 *
                      Real2SimGuidance_ConstB.SinCos_o1_f) * rt_atan2d_snf(1.0,
      rtb_Sum * Real2SimGuidance_ConstB.Sum1_o / rtb_Down) * 57.295779513082323
      + rtb_Abs1;

    // Switch: '<S41>/Switch' incorporates:
    //   Abs: '<S41>/Abs'
    //   Bias: '<S41>/Bias'
    //   Bias: '<S41>/Bias1'
    //   Constant: '<S41>/Constant2'
    //   Constant: '<S42>/Constant'
    //   Math: '<S41>/Math Function1'
    //   RelationalOperator: '<S42>/Compare'

    if (std::abs(rtb_UpperBound) > 180.0) {
      rtb_UpperBound = rt_modd_snf(rtb_UpperBound + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S41>/Switch'

    // Abs: '<S38>/Abs1'
    rtb_LowerBound = std::abs(rtb_UpperBound);

    // Switch: '<S38>/Switch' incorporates:
    //   Constant: '<S34>/Constant'
    //   Constant: '<S34>/Constant1'
    //   Constant: '<S40>/Constant'
    //   RelationalOperator: '<S40>/Compare'
    //   Switch: '<S34>/Switch1'

    if (rtb_LowerBound > 90.0) {
      // Signum: '<S38>/Sign1'
      if (rtb_UpperBound < 0.0) {
        rtb_UpperBound = -1.0;
      } else if (rtb_UpperBound > 0.0) {
        rtb_UpperBound = 1.0;
      } else if (rtb_UpperBound == 0.0) {
        rtb_UpperBound = 0.0;
      } else {
        rtb_UpperBound = (rtNaN);
      }

      // End of Signum: '<S38>/Sign1'

      // ZeroOrderHold: '<Root>/LookaheadPoint_ZOH' incorporates:
      //   Bias: '<S38>/Bias'
      //   Bias: '<S38>/Bias1'
      //   Gain: '<S38>/Gain'
      //   Product: '<S38>/Divide1'

      rty_LookAheadPoint->Latitude_deg = (-(rtb_LowerBound + -90.0) + 90.0) *
        rtb_UpperBound;
      i = 180;
    } else {
      // ZeroOrderHold: '<Root>/LookaheadPoint_ZOH'
      rty_LookAheadPoint->Latitude_deg = rtb_UpperBound;
      i = 0;
    }

    // End of Switch: '<S38>/Switch'

    // Switch: '<S45>/Switch' incorporates:
    //   Abs: '<S45>/Abs'
    //   Bias: '<S45>/Bias'
    //   Bias: '<S45>/Bias1'
    //   Constant: '<S45>/Constant2'
    //   Constant: '<S49>/Constant'
    //   Math: '<S45>/Math Function1'
    //   RelationalOperator: '<S49>/Compare'

    if (std::abs(rtb_RefGndSpd) > 180.0) {
      rtb_RefGndSpd = rt_modd_snf(rtb_RefGndSpd + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S45>/Switch'

    // Sum: '<S34>/Sum' incorporates:
    //   Constant: '<S50>/Constant3'
    //   Product: '<S36>/rad long '
    //   Product: '<S36>/x*sin'
    //   Product: '<S36>/y*cos'
    //   Product: '<S50>/Product4'
    //   Sum: '<S33>/Sum'
    //   Sum: '<S36>/Sum1'
    //   Trigonometry: '<S50>/Trigonometric Function'
    //   Trigonometry: '<S50>/Trigonometric Function2'
    //   UnitConversion: '<S37>/Unit Conversion'

    rtb_RealUAVNEUState_idx_0 = ((rtb_RealUAVNEUState_idx_0 *
      Real2SimGuidance_ConstB.SinCos_o1_f + rtb_RealUAVNEUState_idx_1 *
      Real2SimGuidance_ConstB.SinCos_o2_b) * rt_atan2d_snf(1.0, rtb_Sum * std::
      cos(rtb_Switch)) * 57.295779513082323 + rtb_RefGndSpd) +
      static_cast<real_T>(i);

    // Switch: '<S39>/Switch' incorporates:
    //   Abs: '<S39>/Abs'
    //   Constant: '<S43>/Constant'
    //   RelationalOperator: '<S43>/Compare'

    if (std::abs(rtb_RealUAVNEUState_idx_0) > 180.0) {
      // ZeroOrderHold: '<Root>/LookaheadPoint_ZOH' incorporates:
      //   Bias: '<S39>/Bias'
      //   Bias: '<S39>/Bias1'
      //   Constant: '<S39>/Constant2'
      //   Math: '<S39>/Math Function1'

      rty_LookAheadPoint->Longitude_deg = rt_modd_snf(rtb_RealUAVNEUState_idx_0
        + 180.0, 360.0) + -180.0;
    } else {
      // ZeroOrderHold: '<Root>/LookaheadPoint_ZOH'
      rty_LookAheadPoint->Longitude_deg = rtb_RealUAVNEUState_idx_0;
    }

    // End of Switch: '<S39>/Switch'

    // ZeroOrderHold: '<Root>/LookaheadPoint_ZOH' incorporates:
    //   DataStoreRead: '<S3>/AltitudeGCS'
    //   Gain: '<S3>/Up2Down'
    //   Gain: '<S3>/inverse'
    //   Sum: '<S33>/Sum1'

    rty_LookAheadPoint->Height_meter = rtb_North - (-AltitudeGCS);
  }
}

// Update for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
  Real2SimGuidance_M, real_T *rty_ExecutionTrigger, B_Real2SimGuidance_c_T
  *localB, DW_Real2SimGuidance_f_T *localDW)
{
  real_T y;
  if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
    // Update for Memory: '<Root>/MemoryExecutionTrigger'
    localDW->MemoryExecutionTrigger_PreviousInput = *rty_ExecutionTrigger;

    // Update for Atomic SubSystem: '<Root>/Real2SimNav'
    // Update for Atomic SubSystem: '<S4>/HeadingNaNProtection'
    // Switch: '<S60>/HeightSwitch' incorporates:
    //   Gain: '<S60>/Height2Down'
    //   RelationalOperator: '<S60>/IsNaN'

    if (std::isnan(-localB->NorthEastHeight[2])) {
      // Memory: '<S60>/MemoryRefHeight' incorporates:
      //   Constant: '<S60>/DefaultHeight'

      localDW->MemoryRefHeight_PreviousInput = -150.0;
    } else {
      // Update for Memory: '<S60>/MemoryRefHeight'
      localDW->MemoryRefHeight_PreviousInput = -localB->NorthEastHeight[2];
    }

    // End of Switch: '<S60>/HeightSwitch'
    // End of Update for SubSystem: '<S4>/HeadingNaNProtection'
    // End of Update for SubSystem: '<Root>/Real2SimNav'
  }

  // Update for Atomic SubSystem: '<Root>/Real2SimNav'
  // Update for Atomic SubSystem: '<S4>/SpeedControl'
  // Update for Atomic SubSystem: '<S63>/ADRC'
  // Update for Enabled SubSystem: '<S67>/ESO' incorporates:
  //   EnablePort: '<S72>/Enable'

  if (localDW->ESO_MODE) {
    // MATLAB Function: '<S72>/fal(e,0.5,h)' incorporates:
    //   Constant: '<S72>/Constant2'
    //   Constant: '<S72>/Constant3'

    Real2SimGuidance_fale025h(localB->SumY, 0.5, 0.1, &y);

    // MATLAB Function: '<S72>/fal(e,0.25,h)' incorporates:
    //   Constant: '<S72>/Constant'
    //   Constant: '<S72>/Constant1'

    Real2SimGuidance_fale025h(localB->SumY, 0.25, 0.1, &y);
  }

  // End of Update for SubSystem: '<S67>/ESO'
  // End of Update for SubSystem: '<S63>/ADRC'
  // End of Update for SubSystem: '<S4>/SpeedControl'
  // End of Update for SubSystem: '<Root>/Real2SimNav'
}

// Derivatives for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Deriv(B_Real2SimGuidance_c_T *localB,
  DW_Real2SimGuidance_f_T *localDW, XDot_Real2SimGuidance_n_T *localXdot)
{
  real_T y;
  real_T y_d;

  // Derivatives for Atomic SubSystem: '<Root>/Real2SimNav'
  // Derivatives for Atomic SubSystem: '<S4>/SpeedControl'
  // Derivatives for Atomic SubSystem: '<S63>/ADRC'
  // Derivatives for Integrator: '<S74>/TD_AirSpdADRC'
  localXdot->TD_AirSpdADRC_CSTATE = localB->dotTD;

  // Derivatives for Enabled SubSystem: '<S67>/ESO'
  if (localDW->ESO_MODE) {
    // MATLAB Function: '<S72>/fal(e,0.5,h)' incorporates:
    //   Constant: '<S72>/Constant2'
    //   Constant: '<S72>/Constant3'

    Real2SimGuidance_fale025h(localB->SumY, 0.5, 0.1, &y);

    // MATLAB Function: '<S72>/fal(e,0.25,h)' incorporates:
    //   Constant: '<S72>/Constant'
    //   Constant: '<S72>/Constant1'

    Real2SimGuidance_fale025h(localB->SumY, 0.25, 0.1, &y_d);

    // Derivatives for Integrator: '<S72>/ESO' incorporates:
    //   Gain: '<S72>/beta_01'
    //   Sum: '<S72>/ESOdotsum'

    localXdot->ESO_CSTATE = localB->ESO_dot - localB->SumY;

    // Derivatives for Integrator: '<S72>/ESO_dot' incorporates:
    //   Gain: '<S72>/Gain1'
    //   Gain: '<S72>/Gain4'
    //   Sum: '<S72>/ESOdotdotsum'

    localXdot->ESO_dot_CSTATE = (0.20415441790455871 * localB->GainADRCinvb0 +
      localB->ESO_dotdot) - 1.5811388300841895 * y;

    // Derivatives for Integrator: '<S72>/ESO_dotdot' incorporates:
    //   Gain: '<S72>/Gain'
    //   Gain: '<S72>/Inverse'

    localXdot->ESO_dotdot_CSTATE = -(1.2679145539688905 * y_d);
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

  // Derivatives for Integrator: '<S74>/dotTD'
  localXdot->dotTD_CSTATE = localB->fh_p;

  // End of Derivatives for SubSystem: '<S63>/ADRC'
  // End of Derivatives for SubSystem: '<S4>/SpeedControl'

  // Derivatives for Integrator: '<S64>/TD_Alt'
  localXdot->TD_Alt_CSTATE = localB->dotAltTD;

  // Derivatives for Integrator: '<S64>/dotAltTD'
  localXdot->dotAltTD_CSTATE = localB->fh;

  // End of Derivatives for SubSystem: '<Root>/Real2SimNav'
}

// Model initialize function
void Real2SimGuidance_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_Real2SimGuidance_T *
  const Real2SimGuidance_M)
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
