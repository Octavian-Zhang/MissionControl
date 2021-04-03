//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.283
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sat Apr  3 21:13:42 2021
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
#include "codegenReal2Mission.h"
#include "codegenReal2Mission_private.h"
#include "angdiff_GFr2Xk58.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_powd_snf.h"

// Named constants for Chart: '<S1>/ChartExecutionMode'
const uint8_T codegenReal2Mission_IN_Circle = 1U;
const uint8_T codegenReal2Mission_IN_Flower = 2U;

// Named constants for Chart: '<S2>/Only1stTimeBiasH'
const uint8_T codegenReal2Mission_IN_Running = 1U;
const uint8_T codegenReal2Mission_IN_Start = 2U;

// Named constants for Chart: '<S2>/TASgreaterthan15for1Sec'
const uint8_T codegenReal2Missi_IN_NotTakeOff = 2U;
const uint8_T codegenReal2Mission_IN_InAir = 1U;

// Named constants for Chart: '<S2>/TriggerTermination'
const uint8_T codegenRea_IN_MissionCompletion = 3U;
const uint8_T codegenReal2M_IN_InitialPersuit = 1U;
const uint8_T codegenReal2Mission_IN_Landing = 2U;
const uint8_T codegenReal_IN_MissionExecution = 4U;

//
// This function updates continuous states using the ODE4 fixed-step
// solver algorithm
//
void codegenReal2MissionModelClass::rt_ertODEUpdateContinuousStates
  (RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = static_cast<ODE4_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 17;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  codegenReal2Mission_derivatives();

  // f1 = f(t + (h/2), y + (h/2)*f0)
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  this->step();
  codegenReal2Mission_derivatives();

  // f2 = f(t + (h/2), y + (h/2)*f1)
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  this->step();
  codegenReal2Mission_derivatives();

  // f3 = f(t + h, y + h*f2)
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  this->step();
  codegenReal2Mission_derivatives();

  // tnew = t + h
  // ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3)
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

//
// Output and update for atomic system:
//    '<S10>/fhan_Bank'
//    '<S76>/fhan_Alt'
//
void codegenReal2MissionModelClass::codegenReal2Mission_fhan_Bank(real_T rtu_u,
  real_T rtu_u_p, real_T rtu_u_e, real_T rtu_u_i, real_T *rty_fh)
{
  real_T a0;
  real_T d;
  real_T skySpeed;
  real_T u;
  real_T y;
  real_T y_0;

  // SignalConversion generated from: '<S11>/ SFunction '
  d = rtu_u_e * rtu_u_i * rtu_u_i;
  a0 = rtu_u_p * rtu_u_i;
  y = rtu_u + a0;
  if (y < 0.0) {
    y_0 = -1.0;
  } else if (y > 0.0) {
    y_0 = 1.0;
  } else if (y == 0.0) {
    y_0 = 0.0;
  } else {
    y_0 = (rtNaN);
  }

  skySpeed = (std::sqrt((8.0 * std::abs(y) + d) * d) - d) * y_0 / 2.0 + a0;
  y_0 = y + d;
  u = y - d;
  if (y_0 < 0.0) {
    y_0 = -1.0;
  } else if (y_0 > 0.0) {
    y_0 = 1.0;
  } else if (y_0 == 0.0) {
    y_0 = 0.0;
  } else {
    y_0 = (rtNaN);
  }

  if (u < 0.0) {
    u = -1.0;
  } else if (u > 0.0) {
    u = 1.0;
  } else if (u == 0.0) {
    u = 0.0;
  } else {
    u = (rtNaN);
  }

  a0 = ((a0 + y) - skySpeed) * ((y_0 - u) / 2.0) + skySpeed;
  if (a0 < 0.0) {
    y = -1.0;
  } else if (a0 > 0.0) {
    y = 1.0;
  } else if (a0 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  y_0 = a0 + d;
  u = a0 - d;
  if (y_0 < 0.0) {
    y_0 = -1.0;
  } else if (y_0 > 0.0) {
    y_0 = 1.0;
  } else if (y_0 == 0.0) {
    y_0 = 0.0;
  } else {
    y_0 = (rtNaN);
  }

  if (u < 0.0) {
    u = -1.0;
  } else if (u > 0.0) {
    u = 1.0;
  } else if (u == 0.0) {
    u = 0.0;
  } else {
    u = (rtNaN);
  }

  // SignalConversion generated from: '<S11>/ SFunction '
  *rty_fh = (a0 / d - y) * -rtu_u_e * ((y_0 - u) / 2.0) - rtu_u_e * y;
}

//
// Output and update for atomic system:
//    '<S84>/fal(e,0.25,h)'
//    '<S84>/fal(e,0.5,h)'
//
void codegenReal2MissionModelClass::codegenReal2Mission_fale025h(real_T rtu_u,
  real_T rtu_u_b, real_T rtu_u_c, real_T *rty_y)
{
  real_T rtu_u_0;
  real_T tmp;

  // SignalConversion generated from: '<S87>/ SFunction '
  tmp = std::abs(rtu_u);
  if (tmp <= rtu_u_c) {
    *rty_y = rtu_u / rt_powd_snf(rtu_u_c, 1.0 - rtu_u_b);
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

    *rty_y = rt_powd_snf(tmp, rtu_u_b) * rtu_u_0;
  }

  // End of SignalConversion generated from: '<S87>/ SFunction '
}

void codegenReal2MissionModelClass::WaypointFollowerBase_getDistinc(const real_T
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

real_T codegenReal2MissionModelClass::codegenReal2Mission_norm_b(const real_T x
  [3])
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

void codegenReal2MissionModelClass::codegenReal2Miss_emxInit_real_T
  (emxArray_real_T_codegenReal2M_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_codegenReal2M_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_codegenReal2M_T *)std::malloc(sizeof
    (emxArray_real_T_codegenReal2M_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void codegenReal2MissionModelClass::codege_emxEnsureCapacity_real_T
  (emxArray_real_T_codegenReal2M_T *emxArray, int32_T oldNumel)
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
    if (emxArray->data != NULL) {
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

void codegenReal2MissionModelClass::codegenReal2Miss_emxFree_real_T
  (emxArray_real_T_codegenReal2M_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_codegenReal2M_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_codegenReal2M_T *)NULL;
  }
}

void codegenReal2MissionModelClass::WaypointFollowerBase_searchClos
  (uav_sluav_internal_system_Way_T *obj, const real_T waypoints_data[], const
   int32_T waypoints_size[2], const real_T currentPose[4])
{
  emxArray_real_T_codegenReal2M_T *d;
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
  codegenReal2Miss_emxInit_real_T(&d, 2);
  b_k = d->size[0] * d->size[1];
  d->size[0] = 1;
  d->size[1] = static_cast<int32_T>(obj->NumWaypoints - 1.0);
  codege_emxEnsureCapacity_real_T(d, b_k);
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
      d->data[b_k] = codegenReal2Mission_norm_b(currentPose_0);
    } else if (lambda > 1.0) {
      d->data[b_k] = codegenReal2Mission_norm_b(currentPose_1);
    } else {
      d->data[b_k] = codegenReal2Mission_norm_b(currentPose_2);
    }
  }

  last = d->size[1];
  if (d->size[1] <= 2) {
    if (d->size[1] == 1) {
      b_idx = 1;
    } else if ((d->data[0] > d->data[d->size[1] - 1]) || (rtIsNaN(d->data[0]) &&
                (!rtIsNaN(d->data[d->size[1] - 1])))) {
      b_idx = d->size[1];
    } else {
      b_idx = 1;
    }
  } else {
    if (!rtIsNaN(d->data[0])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k <= last)) {
        if (!rtIsNaN(d->data[b_k - 1])) {
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

  codegenReal2Miss_emxFree_real_T(&d);
  obj->WaypointIndex = b_idx;
  obj->SearchFlag = false;
}

void codegenReal2MissionModelClass::WaypointFollowerBase_endWaypo_b
  (uav_sluav_internal_system_Way_T *obj, const real_T waypoints_data[], const
   int32_T waypoints_size[2], real_T curStartWaypoint[3], real_T curEndWaypoint
   [3], const real_T currentPose[4])
{
  real_T curEndWaypoint_0[3];
  real_T tmp[3];
  real_T curEndWaypoint_1;
  real_T curEndWaypoint_tmp;
  real_T curEndWaypoint_tmp_0;
  real_T curEndWaypoint_tmp_1;
  real_T tmp_0;
  boolean_T guard1 = false;
  boolean_T p;
  tmp[0] = currentPose[0] - curEndWaypoint[0];
  tmp[1] = currentPose[1] - curEndWaypoint[1];
  tmp[2] = currentPose[2] - curEndWaypoint[2];
  curEndWaypoint_1 = codegenReal2Mission_norm_b(tmp);
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
    tmp_0 = codegenReal2Mission_norm_b(curEndWaypoint_0);
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

void codegenReal2MissionModelClass::WaypointFollowerBase_stepIntern
  (uav_sluav_internal_system_Way_T *obj, const real_T currentPose[4], const
   real_T waypointsIn[219], real_T lookaheadDist, real_T lookaheadPoint[3],
   real_T *desiredHeading, real_T *desiredYaw, uint8_T *lookaheadDistFlag,
   real_T *crossTrackError, uint8_T *status)
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
  boolean_T guard1 = false;
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
    if ((obj->WaypointsInternal[b_k] == waypointsIn[b_k]) || (rtIsNaN
         (obj->WaypointsInternal[b_k]) && rtIsNaN(waypointsIn[b_k]))) {
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

  WaypointFollowerBase_getDistinc(waypointsIn, b_waypointsIn_data,
    b_waypointsIn_size);
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
      if (codegenReal2Mission_norm_b(virtualWaypoint) < 1.4901161193847656E-8) {
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
        WaypointFollowerBase_searchClos(obj, waypoints_data, waypoints_size,
          currentPose);
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
      WaypointFollowerBase_endWaypo_b(obj, waypoints_data, waypoints_size,
        virtualWaypoint, lookaheadPoint, currentPose);
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
        *crossTrackError = codegenReal2Mission_norm_b(currentPose_0);
      } else if (lambda > 1.0) {
        *crossTrackError = codegenReal2Mission_norm_b(currentPose_1);
      } else {
        *crossTrackError = codegenReal2Mission_norm_b(currentPose_2);
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
        *crossTrackError = codegenReal2Mission_norm_b(currentPose_0);
      }

      currentPose_tmp = std::abs(*crossTrackError);
      if ((!rtIsInf(currentPose_tmp)) && (!rtIsNaN(currentPose_tmp))) {
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

      lambda = std::sqrt(lambda);
      currentPose_tmp *= 5.0;
      if ((lambda > currentPose_tmp) || rtIsNaN(currentPose_tmp)) {
        currentPose_tmp = lambda;
      }

      if (obj->LookaheadDistance <= *crossTrackError + currentPose_tmp) {
        obj->LookaheadDistance = obj->LookaheadFactor * *crossTrackError;
      }

      currentPose_tmp = ((lookaheadPoint[0] - virtualWaypoint[0]) *
                         (lookaheadPoint[0] - virtualWaypoint[0]) +
                         (lookaheadPoint[1] - virtualWaypoint[1]) *
                         (lookaheadPoint[1] - virtualWaypoint[1])) +
        (lookaheadPoint[2] - virtualWaypoint[2]) * (lookaheadPoint[2] -
        virtualWaypoint[2]);
      lambda = virtualWaypoint[0] - currentPose[0];
      currentPose_tmp_0 = virtualWaypoint[1] - currentPose[1];
      b_tmp_idx_2_tmp = virtualWaypoint[2] - currentPose[2];
      b = ((b * lambda + lambda_tmp_tmp * currentPose_tmp_0) + lambda_tmp_tmp_0 *
           b_tmp_idx_2_tmp) * 2.0;
      lambda_tmp_tmp = std::sqrt(b * b - (((lambda * lambda + currentPose_tmp_0 *
        currentPose_tmp_0) + b_tmp_idx_2_tmp * b_tmp_idx_2_tmp) -
        obj->LookaheadDistance * obj->LookaheadDistance) * (4.0 *
        currentPose_tmp));
      lambda = (-b + lambda_tmp_tmp) / 2.0 / currentPose_tmp;
      b = (-b - lambda_tmp_tmp) / 2.0 / currentPose_tmp;
      if ((lambda > b) || rtIsNaN(b)) {
        b = lambda;
      }

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

real_T codegenReal2MissionModelClass::codegenReal2Mission_norm(const real_T x[2])
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

void codegenReal2MissionModelClass::codegenReal2Mis_Model_resetImpl
  (robotics_core_internal_syst_b_T *obj)
{
  obj->ModelImpl.Configuration.PHeight = 3.9;
  obj->ModelImpl.Configuration.PFlightPathAngle = 39.0;
  obj->ModelImpl.Configuration.PAirSpeed = 0.39;
  obj->ModelImpl.Configuration.PHeight = 3.9;
  obj->ModelImpl.Configuration.PFlightPathAngle = 11.7;
  obj->ModelImpl.Configuration.PAirSpeed = 0.3;
  obj->ModelImpl.Configuration.PDRoll[0] = 3402.9722249999991;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -1.5707963267948966;
  obj->ModelImpl.Configuration.PDRoll[0] = 100.0;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -0.21109333322274654;
  obj->ModelImpl.Configuration.PDRoll[1] = 116.66999999999999;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 1.5707963267948966;
  obj->ModelImpl.Configuration.PDRoll[1] = 10.0;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 0.21109333322274654;
}

// Model step function
void codegenReal2MissionModelClass::step()
{
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // set solver stop time
    rtsiSetSolverStopTime(&(&codegenReal2Mission_M)->solverInfo,
                          (((&codegenReal2Mission_M)->Timing.clockTick0+1)*
      (&codegenReal2Mission_M)->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep((&codegenReal2Mission_M))) {
    (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetT(&(&codegenReal2Mission_M)
      ->solverInfo);
  }

  {
    real_T rtb_MatrixConcatenate[219];
    real_T rtb_Reshape[8];
    real_T rtb_FixedWingGuidanceStateBus_N[4];
    real_T rtb_Heading_Log[3];
    real_T rtb_RealUAVNEUState[3];
    real_T rtb_Sum_b[3];
    real_T rtb_SwitchLookAheadNED[3];
    real_T distToCenter_tmp[2];
    real_T rtb_TmpSignalConversionAtSFun_0[2];
    real_T a0;
    real_T d;
    real_T eastSpeed;
    real_T q;
    real_T rtb_Abs1;
    real_T rtb_AirSpeed;
    real_T rtb_AirSpeed_ae;
    real_T rtb_AirSpeed_c;
    real_T rtb_AirSpeed_f;
    real_T rtb_Down;
    real_T rtb_East;
    real_T rtb_FixedWingGuidanceStateBus_A;
    real_T rtb_FixedWingGuidanceStateBus_H;
    real_T rtb_FlightPathAngle;
    real_T rtb_FlightPathAngle_g;
    real_T rtb_HeadWind;
    real_T rtb_HeadingAngle;
    real_T rtb_Height;
    real_T rtb_Height_n;
    real_T rtb_LowerBound;
    real_T rtb_MemoryExecutionTrigger;
    real_T rtb_North;
    real_T rtb_North_m;
    real_T rtb_OverwriteHeight;
    real_T rtb_RefAirspeed_Log;
    real_T rtb_RefGndSpd;
    real_T rtb_RollAngleRate;
    real_T rtb_RollAngleRate_m;
    real_T rtb_RollAngle_i;
    real_T rtb_RollAngle_k;
    real_T rtb_Switch;
    real_T rtb_Switch_j;
    real_T rtb_eastSpeed;
    real_T rtb_northSpeed;
    real_T rtb_skySpeed;
    real_T rtb_ycos_o;
    real_T skySpeed;
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T i;
    uint8_T rtb_FlightMode_Log_l;
    uint8_T rtb_Status_Log;
    boolean_T exitg1;
    boolean_T guard1 = false;
    boolean_T rEQ0;
    boolean_T rtb_Engaged;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Step: '<S1>/Step' incorporates:
      //   DataStoreWrite: '<S6>/ResetOnStart'

      codegenReal2Mission_DW.ResetSimUAV = ((((&codegenReal2Mission_M)
        ->Timing.clockTick1) * 0.1) < 0.0);

      // Outputs for Atomic SubSystem: '<S1>/InitializeSimLocation'
      // DataStoreWrite: '<S5>/DSAltitudeGCS' incorporates:
      //   Constant: '<S5>/AltitudeGCS'

      codegenReal2Mission_DW.AltitudeGCS = codegenReal2Mission_P.GCS_Altitude;

      // DataStoreWrite: '<S5>/DSLatitudeGCS' incorporates:
      //   Constant: '<S5>/LatitudeGCS'

      codegenReal2Mission_DW.LatitudeGCS = codegenReal2Mission_P.GCS_Latitude;

      // DataStoreWrite: '<S5>/DSLongitudeGCS' incorporates:
      //   Constant: '<S5>/LongitudeGCS'

      codegenReal2Mission_DW.LongitudeGCS = codegenReal2Mission_P.GCS_Longitude;

      // DataTypeConversion: '<S5>/Cast To Double' incorporates:
      //   Constant: '<S5>/UAVidx'

      rtb_Abs1 = codegenReal2Mission_P.UAVidx;

      // Gain: '<S5>/Gain' incorporates:
      //   Bias: '<S5>/Bias'
      //   Constant: '<S5>/Number Of Mission UAV'
      //   Gain: '<S1>/FindMiddle'

      eastSpeed = (codegenReal2Mission_P.numMissionUAV + 1.0) * 0.5;

      // Product: '<S5>/Map2Radian' incorporates:
      //   Constant: '<S5>/2pi'
      //   Constant: '<S5>/Number Of Mission UAV'
      //   Gain: '<S5>/Gain'
      //   Product: '<S5>/Divide'
      //   Sum: '<S5>/Minus'

      rtb_Abs1 = (rtb_Abs1 - eastSpeed) * (6.2831853071795862 /
        codegenReal2Mission_P.numMissionUAV);

      // Bias: '<S5>/ClockwiseRotation'
      rtb_Switch_j = rtb_Abs1 + 1.5707963267948966;

      // Reshape: '<S5>/Reshape' incorporates:
      //   Constant: '<S5>/InitialFlightPathAngle'
      //   Constant: '<S5>/InitialHeight'
      //   Constant: '<S5>/InitialRollAngle'
      //   Constant: '<S5>/InitialRollAngleRate'
      //   Constant: '<S5>/InitialUAVAirspeed'
      //   Constant: '<S5>/Radius'
      //   Product: '<S5>/EastDis'
      //   Product: '<S5>/NorthDis'
      //   Trigonometry: '<S5>/Cos'
      //   Trigonometry: '<S5>/Sin'

      rtb_Reshape[0] = std::cos(rtb_Abs1) * 1000.0;
      rtb_Reshape[1] = 1000.0 * std::sin(rtb_Abs1);
      rtb_Reshape[2] = 150.0;
      rtb_Reshape[3] = 35.0;
      rtb_Reshape[4] = rtb_Switch_j;
      rtb_Reshape[5] = 0.0;
      rtb_Reshape[6] = 0.0;
      rtb_Reshape[7] = 0.0;

      // End of Outputs for SubSystem: '<S1>/InitializeSimLocation'

      // Memory: '<S1>/MemoryFlowerMode'
      rtb_FlightPathAngle_g =
        codegenReal2Mission_DW.MemoryFlowerMode_PreviousInput;

      // Outputs for Atomic SubSystem: '<S1>/InitializeSimLocation'
      // DataTypeConversion: '<S1>/Cast To Double' incorporates:
      //   Constant: '<S5>/UAVidx'
      //   DataTypeConversion: '<S5>/Cast To Double'

      rtb_Switch = codegenReal2Mission_P.UAVidx;

      // End of Outputs for SubSystem: '<S1>/InitializeSimLocation'

      // Delay: '<S1>/InitHdg' incorporates:
      //   Bias: '<S1>/Rotate90Deg'
      //   Constant: '<S1>/2pi'
      //   Constant: '<S1>/Number Of Mission UAV'
      //   Product: '<S1>/Divide'
      //   Product: '<S1>/Map2Radian'
      //   Sum: '<S1>/Minus'

      if (codegenReal2Mission_DW.icLoad) {
        codegenReal2Mission_DW.InitHdg_DSTATE = (rtb_Switch - eastSpeed) *
          (6.2831853071795862 / codegenReal2Mission_P.numMissionUAV) +
          1.5707963267948966;
      }

      // BusCreator: '<S1>/Bus Creator' incorporates:
      //   Delay: '<S1>/InitHdg'

      d = codegenReal2Mission_DW.InitHdg_DSTATE;

      // Outputs for Atomic SubSystem: '<S1>/MissionSimUAV'
      // DataStoreWrite: '<S6>/ResetOnStart'
      if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        rtsiSetBlockStateForSolverChangedAtMajorStep(&(&codegenReal2Mission_M)
          ->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&codegenReal2Mission_M)->solverInfo, true);
      }

      // DataStoreWrite: '<S6>/WriteInitState'
      std::memcpy(&codegenReal2Mission_DW.InitStateSimUAV[0], &rtb_Reshape[0],
                  sizeof(real_T) << 3U);
      if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        rtsiSetBlockStateForSolverChangedAtMajorStep(&(&codegenReal2Mission_M)
          ->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&codegenReal2Mission_M)->solverInfo, true);
      }

      // End of DataStoreWrite: '<S6>/WriteInitState'

      // Saturate: '<S6>/AirspeedSaturation' incorporates:
      //   BusCreator: '<S1>/Bus Creator'

      codegenReal2Mission_B.AirSpeed = 35.0;

      // Saturate: '<S6>/AltitudeSaturation' incorporates:
      //   BusCreator: '<S1>/Bus Creator'

      if (rtb_FlightPathAngle_g > 500.0) {
        rtb_Abs1 = 500.0;
      } else if (rtb_FlightPathAngle_g < 100.0) {
        rtb_Abs1 = 100.0;
      } else {
        rtb_Abs1 = rtb_FlightPathAngle_g;
      }

      // End of Saturate: '<S6>/AltitudeSaturation'

      // RateLimiter: '<S6>/ClimbRateLimiter'
      eastSpeed = rtb_Abs1 - codegenReal2Mission_DW.PrevY;
      if (eastSpeed > 0.5) {
        // RateLimiter: '<S6>/ClimbRateLimiter'
        codegenReal2Mission_B.Height = codegenReal2Mission_DW.PrevY + 0.5;
      } else if (eastSpeed < -0.5) {
        // RateLimiter: '<S6>/ClimbRateLimiter'
        codegenReal2Mission_B.Height = codegenReal2Mission_DW.PrevY + -0.5;
      } else {
        // RateLimiter: '<S6>/ClimbRateLimiter'
        codegenReal2Mission_B.Height = rtb_Abs1;
      }

      codegenReal2Mission_DW.PrevY = codegenReal2Mission_B.Height;

      // End of RateLimiter: '<S6>/ClimbRateLimiter'

      // BusCreator: '<S6>/FixedWingGuidanceEnvironmentBus' incorporates:
      //   Constant: '<S6>/Gravity'
      //   Constant: '<S6>/NoWind'

      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth = 0.0;
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast = 0.0;
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindDown = 0.0;
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.Gravity = 9.807;

      // End of Outputs for SubSystem: '<S1>/MissionSimUAV'
    }

    // Outputs for Atomic SubSystem: '<S1>/MissionSimUAV'
    // DataStoreRead: '<S9>/ResetSimUAV'
    codegenReal2Mission_B.ResetSimUAV = codegenReal2Mission_DW.ResetSimUAV;

    // DataStoreRead: '<S9>/InitState'
    std::memcpy(&rtb_Reshape[0], &codegenReal2Mission_DW.InitStateSimUAV[0],
                sizeof(real_T) << 3U);

    // Integrator: '<S9>/Integrator'
    rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
    if (rEQ0 && ((codegenReal2Mission_B.ResetSimUAV != 0.0) ||
                 (codegenReal2Mission_DW.Integrator_IWORK != 0))) {
      // evaluate the level of the reset signal
      std::memcpy(&codegenReal2Mission_X.Integrator_CSTATE[0], &rtb_Reshape[0],
                  sizeof(real_T) << 3U);
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // MATLAB Function: '<S6>/SimHeadingControl' incorporates:
      //   BusCreator: '<S1>/Bus Creator'
      //   Integrator: '<S9>/Integrator'

      a0 = 1.0 / codegenReal2Mission_X.Integrator_CSTATE[3];
      eastSpeed = std::cos(codegenReal2Mission_X.Integrator_CSTATE[5]);
      eastSpeed = (std::cos(codegenReal2Mission_X.Integrator_CSTATE[4]) *
                   eastSpeed *
                   codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth
                   + std::sin(codegenReal2Mission_X.Integrator_CSTATE[4]) *
                   eastSpeed *
                   codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast)
        + -std::sin(codegenReal2Mission_X.Integrator_CSTATE[5]) *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindDown;
      d -= codegenReal2Mission_X.Integrator_CSTATE[4];
      if (std::abs(d) > 3.1415926535897931) {
        if (rtIsNaN(d + 3.1415926535897931)) {
          skySpeed = (rtNaN);
        } else if (rtIsInf(d + 3.1415926535897931)) {
          skySpeed = (rtNaN);
        } else if (d + 3.1415926535897931 == 0.0) {
          skySpeed = 0.0;
        } else {
          skySpeed = std::fmod(d + 3.1415926535897931, 6.2831853071795862);
          rEQ0 = (skySpeed == 0.0);
          if (!rEQ0) {
            q = std::abs((d + 3.1415926535897931) / 6.2831853071795862);
            rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 *
                     q);
          }

          if (rEQ0) {
            skySpeed = 0.0;
          } else if (d + 3.1415926535897931 < 0.0) {
            skySpeed += 6.2831853071795862;
          }
        }

        if ((skySpeed == 0.0) && (d + 3.1415926535897931 > 0.0)) {
          skySpeed = 6.2831853071795862;
        }

        d = skySpeed - 3.1415926535897931;
      }

      codegenReal2Mission_B.RollAngle = rt_atan2d_snf((std::sqrt(eastSpeed *
        eastSpeed -
        (((codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth *
           codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth +
           codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast *
           codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast) +
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindDown *
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindDown) -
         codegenReal2Mission_X.Integrator_CSTATE[3] *
         codegenReal2Mission_X.Integrator_CSTATE[3])) + -eastSpeed) * (0.39 * d),
        std::cos(codegenReal2Mission_X.Integrator_CSTATE[4] -
                 (codegenReal2Mission_X.Integrator_CSTATE[4] - std::asin(a0 *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth * -std::
        sin(codegenReal2Mission_X.Integrator_CSTATE[4]) + a0 *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast * std::
        cos(codegenReal2Mission_X.Integrator_CSTATE[4])))) *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.Gravity);

      // Saturate: '<S6>/RollAngleSaturation'
      if (codegenReal2Mission_B.RollAngle > 0.3490658503988659) {
        // MATLAB Function: '<S6>/SimHeadingControl' incorporates:
        //   Saturate: '<S6>/RollAngleSaturation'

        codegenReal2Mission_B.RollAngle = 0.3490658503988659;
      } else if (codegenReal2Mission_B.RollAngle < -0.3490658503988659) {
        // MATLAB Function: '<S6>/SimHeadingControl' incorporates:
        //   Saturate: '<S6>/RollAngleSaturation'

        codegenReal2Mission_B.RollAngle = -0.3490658503988659;
      }

      // End of Saturate: '<S6>/RollAngleSaturation'
    }

    // MATLABSystem: '<S9>/ComputeDerivative' incorporates:
    //   BusCreator: '<S6>/SlewGuidanceBus'
    //   Integrator: '<S10>/TD_Bank'
    //   Integrator: '<S9>/Integrator'

    eastSpeed = std::cos(codegenReal2Mission_X.Integrator_CSTATE[5]);
    a0 = std::cos(codegenReal2Mission_X.Integrator_CSTATE[4]);
    d = std::sin(codegenReal2Mission_X.Integrator_CSTATE[4]);
    skySpeed = std::sin(codegenReal2Mission_X.Integrator_CSTATE[5]);
    q = (-(a0 * eastSpeed) *
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth + -(d *
          eastSpeed) *
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast) +
      skySpeed * codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindDown;
    q = std::sqrt(q * q -
                  (((codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth
                     * codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth
                     + codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast
                     * codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast)
                    + codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindDown
                    * codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindDown)
                   - codegenReal2Mission_X.Integrator_CSTATE[3] *
                   codegenReal2Mission_X.Integrator_CSTATE[3])) + -q;
    codegenReal2Mission_B.ComputeDerivative[0] = q * a0 * eastSpeed;
    codegenReal2Mission_B.ComputeDerivative[1] = q * d * eastSpeed;
    codegenReal2Mission_B.ComputeDerivative[2] = q * skySpeed;
    codegenReal2Mission_B.ComputeDerivative[3] = (codegenReal2Mission_B.AirSpeed
      - codegenReal2Mission_X.Integrator_CSTATE[3]) *
      codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.PAirSpeed;
    if (q == 0.0) {
      codegenReal2Mission_B.ComputeDerivative[4] = 0.0;
      codegenReal2Mission_B.ComputeDerivative[5] = 0.0;
    } else {
      if (codegenReal2Mission_X.Integrator_CSTATE[3] == 0.0) {
        codegenReal2Mission_B.ComputeDerivative[4] = 0.0;
      } else {
        a0 = 1.0 / (std::cos(std::asin((q * skySpeed +
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindDown) /
          codegenReal2Mission_X.Integrator_CSTATE[3])) *
                    codegenReal2Mission_X.Integrator_CSTATE[3]);
        codegenReal2Mission_B.ComputeDerivative[4] = std::cos(std::asin(a0 *
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindNorth * -std::
          sin(codegenReal2Mission_X.Integrator_CSTATE[4]) + a0 *
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.WindEast * std::
          cos(codegenReal2Mission_X.Integrator_CSTATE[4]))) *
          (codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_i.Gravity / q *
           std::tan(codegenReal2Mission_X.Integrator_CSTATE[6]));
      }

      eastSpeed = (codegenReal2Mission_B.Height -
                   codegenReal2Mission_X.Integrator_CSTATE[2]) *
        codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.PHeight / q;
      if (!(eastSpeed < 1.0)) {
        eastSpeed = 1.0;
      }

      if (!(eastSpeed > -1.0)) {
        eastSpeed = -1.0;
      }

      eastSpeed = std::asin(eastSpeed);
      if ((!(eastSpeed <
             codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.FlightPathAngleLimits
             [1])) && (!rtIsNaN
                       (codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.FlightPathAngleLimits
                        [1]))) {
        eastSpeed =
          codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.FlightPathAngleLimits
          [1];
      }

      if ((!(eastSpeed >
             codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.FlightPathAngleLimits
             [0])) && (!rtIsNaN
                       (codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.FlightPathAngleLimits
                        [0]))) {
        eastSpeed =
          codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.FlightPathAngleLimits
          [0];
      }

      codegenReal2Mission_B.ComputeDerivative[5] = (eastSpeed -
        codegenReal2Mission_X.Integrator_CSTATE[5]) *
        codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.PFlightPathAngle;
    }

    codegenReal2Mission_B.ComputeDerivative[6] =
      codegenReal2Mission_X.Integrator_CSTATE[7];
    if (codegenReal2Mission_X.TD_Bank_CSTATE < 1.5707963267948966) {
      eastSpeed = codegenReal2Mission_X.TD_Bank_CSTATE;
    } else {
      eastSpeed = 1.5707963267948966;
    }

    if (!(eastSpeed > -1.5707963267948966)) {
      eastSpeed = -1.5707963267948966;
    }

    codegenReal2Mission_B.ComputeDerivative[7] = (eastSpeed -
      codegenReal2Mission_X.Integrator_CSTATE[6]) *
      codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.PDRoll[0] +
      codegenReal2Mission_DW.obj_c.ModelImpl.Configuration.PDRoll[1] *
      -codegenReal2Mission_X.Integrator_CSTATE[7];

    // End of MATLABSystem: '<S9>/ComputeDerivative'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // ZeroOrderHold: '<S6>/SimUAVStateZOH' incorporates:
      //   Integrator: '<S9>/Integrator'

      codegenReal2Mission_B.SimUAVStateZOH.North =
        codegenReal2Mission_X.Integrator_CSTATE[0];
      codegenReal2Mission_B.SimUAVStateZOH.East =
        codegenReal2Mission_X.Integrator_CSTATE[1];
      codegenReal2Mission_B.SimUAVStateZOH.Height =
        codegenReal2Mission_X.Integrator_CSTATE[2];
      codegenReal2Mission_B.SimUAVStateZOH.AirSpeed =
        codegenReal2Mission_X.Integrator_CSTATE[3];
      codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle =
        codegenReal2Mission_X.Integrator_CSTATE[4];
      codegenReal2Mission_B.SimUAVStateZOH.FlightPathAngle =
        codegenReal2Mission_X.Integrator_CSTATE[5];
      codegenReal2Mission_B.SimUAVStateZOH.RollAngle =
        codegenReal2Mission_X.Integrator_CSTATE[6];
      codegenReal2Mission_B.SimUAVStateZOH.RollAngleRate =
        codegenReal2Mission_X.Integrator_CSTATE[7];
    }

    // Integrator: '<S10>/dotBankTD'
    codegenReal2Mission_B.dotBankTD = codegenReal2Mission_X.dotBankTD_CSTATE;

    // MATLAB Function: '<S10>/fhan_Bank' incorporates:
    //   Constant: '<S10>/Constant2'
    //   Constant: '<S10>/Constant3'
    //   Integrator: '<S10>/TD_Bank'
    //   Sum: '<S10>/Sum1'

    codegenReal2Mission_fhan_Bank(codegenReal2Mission_X.TD_Bank_CSTATE -
      codegenReal2Mission_B.RollAngle, codegenReal2Mission_B.dotBankTD,
      0.087266462599716474, 0.1, &codegenReal2Mission_B.fh_p);

    // End of Outputs for SubSystem: '<S1>/MissionSimUAV'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // SignalConversion generated from: '<Root>/VectorSpd' incorporates:
      //   Inport: '<Root>/VectorSpd'

      rtb_eastSpeed = codegenReal2Mission_U.VectorSpd.eastSpeed;

      // SignalConversion generated from: '<Root>/VectorSpd' incorporates:
      //   Inport: '<Root>/VectorSpd'

      rtb_northSpeed = codegenReal2Mission_U.VectorSpd.northSpeed;

      // SignalConversion generated from: '<Root>/VectorSpd' incorporates:
      //   Inport: '<Root>/VectorSpd'

      rtb_skySpeed = codegenReal2Mission_U.VectorSpd.skySpeed;

      // Outputs for Atomic SubSystem: '<Root>/Real2SimGuidance'
      // DataStoreWrite: '<S2>/WriteFlightMode_Log' incorporates:
      //   Inport: '<Root>/FlightMode'

      codegenReal2Mission_DW.FlightMode_Log = codegenReal2Mission_U.FlightMode;

      // Abs: '<S36>/Abs' incorporates:
      //   DataStoreRead: '<S13>/LatitudeGCS'

      rtb_Switch = std::abs(codegenReal2Mission_DW.LatitudeGCS);

      // Switch: '<S36>/Switch' incorporates:
      //   Bias: '<S36>/Bias'
      //   Bias: '<S36>/Bias1'
      //   Constant: '<S36>/Constant2'
      //   Constant: '<S37>/Constant'
      //   DataStoreRead: '<S13>/LatitudeGCS'
      //   Math: '<S36>/Math Function1'
      //   RelationalOperator: '<S37>/Compare'

      if (rtb_Switch > 180.0) {
        rtb_Switch = rt_modd_snf(codegenReal2Mission_DW.LatitudeGCS + 180.0,
          360.0) + -180.0;
      } else {
        rtb_Switch = codegenReal2Mission_DW.LatitudeGCS;
      }

      // End of Switch: '<S36>/Switch'

      // Abs: '<S33>/Abs1'
      rtb_Abs1 = std::abs(rtb_Switch);

      // Switch: '<S33>/Switch' incorporates:
      //   Bias: '<S33>/Bias'
      //   Bias: '<S33>/Bias1'
      //   Constant: '<S24>/Constant'
      //   Constant: '<S24>/Constant1'
      //   Constant: '<S35>/Constant'
      //   Gain: '<S33>/Gain'
      //   Product: '<S33>/Divide1'
      //   RelationalOperator: '<S35>/Compare'
      //   Switch: '<S24>/Switch1'

      if (rtb_Abs1 > 90.0) {
        // Signum: '<S33>/Sign1'
        if (rtb_Switch < 0.0) {
          rtb_Switch = -1.0;
        } else if (rtb_Switch > 0.0) {
          rtb_Switch = 1.0;
        } else if (rtb_Switch == 0.0) {
          rtb_Switch = 0.0;
        } else {
          rtb_Switch = (rtNaN);
        }

        // End of Signum: '<S33>/Sign1'
        rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
        rtb_FlightPathAngle_g = 180.0;
      } else {
        rtb_FlightPathAngle_g = 0.0;
      }

      // End of Switch: '<S33>/Switch'

      // Sum: '<S24>/Sum' incorporates:
      //   DataStoreRead: '<S13>/LongitudeGCS'

      rtb_Abs1 = rtb_FlightPathAngle_g + codegenReal2Mission_DW.LongitudeGCS;

      // Abs: '<S34>/Abs'
      rtb_FlightPathAngle_g = std::abs(rtb_Abs1);

      // Switch: '<S34>/Switch' incorporates:
      //   Bias: '<S34>/Bias'
      //   Bias: '<S34>/Bias1'
      //   Constant: '<S34>/Constant2'
      //   Constant: '<S38>/Constant'
      //   Math: '<S34>/Math Function1'
      //   RelationalOperator: '<S38>/Compare'

      if (rtb_FlightPathAngle_g > 180.0) {
        rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S34>/Switch'

      // Sum: '<S22>/Sum1' incorporates:
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_Switch_j = codegenReal2Mission_U.RealUAVLatLonState.Latitude_deg -
        rtb_Switch;

      // Abs: '<S30>/Abs'
      rtb_FlightPathAngle_g = std::abs(rtb_Switch_j);

      // Switch: '<S30>/Switch' incorporates:
      //   Bias: '<S30>/Bias'
      //   Bias: '<S30>/Bias1'
      //   Constant: '<S30>/Constant2'
      //   Constant: '<S31>/Constant'
      //   Math: '<S30>/Math Function1'
      //   RelationalOperator: '<S31>/Compare'

      if (rtb_FlightPathAngle_g > 180.0) {
        rtb_Switch_j = rt_modd_snf(rtb_Switch_j + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S30>/Switch'

      // Abs: '<S27>/Abs1'
      rtb_FlightPathAngle_g = std::abs(rtb_Switch_j);

      // Switch: '<S27>/Switch' incorporates:
      //   Bias: '<S27>/Bias'
      //   Bias: '<S27>/Bias1'
      //   Constant: '<S23>/Constant'
      //   Constant: '<S23>/Constant1'
      //   Constant: '<S29>/Constant'
      //   Gain: '<S27>/Gain'
      //   Product: '<S27>/Divide1'
      //   RelationalOperator: '<S29>/Compare'
      //   Switch: '<S23>/Switch1'

      if (rtb_FlightPathAngle_g > 90.0) {
        // Signum: '<S27>/Sign1'
        if (rtb_Switch_j < 0.0) {
          rtb_Switch_j = -1.0;
        } else if (rtb_Switch_j > 0.0) {
          rtb_Switch_j = 1.0;
        } else if (rtb_Switch_j == 0.0) {
          rtb_Switch_j = 0.0;
        } else {
          rtb_Switch_j = (rtNaN);
        }

        // End of Signum: '<S27>/Sign1'
        rtb_FlightPathAngle_g = (-(rtb_FlightPathAngle_g + -90.0) + 90.0) *
          rtb_Switch_j;
        rtb_AirSpeed_c = 180.0;
      } else {
        rtb_FlightPathAngle_g = rtb_Switch_j;
        rtb_AirSpeed_c = 0.0;
      }

      // End of Switch: '<S27>/Switch'

      // Sum: '<S23>/Sum' incorporates:
      //   Inport: '<Root>/RealUAVLatLonState'
      //   Sum: '<S22>/Sum1'

      rtb_Abs1 = (codegenReal2Mission_U.RealUAVLatLonState.Longitude_deg -
                  rtb_Abs1) + rtb_AirSpeed_c;

      // Abs: '<S28>/Abs'
      rtb_AirSpeed_c = std::abs(rtb_Abs1);

      // Switch: '<S28>/Switch' incorporates:
      //   Bias: '<S28>/Bias'
      //   Bias: '<S28>/Bias1'
      //   Constant: '<S28>/Constant2'
      //   Constant: '<S32>/Constant'
      //   Math: '<S28>/Math Function1'
      //   RelationalOperator: '<S32>/Compare'

      if (rtb_AirSpeed_c > 180.0) {
        rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S28>/Switch'

      // UnitConversion: '<S26>/Unit Conversion'
      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Switch_j = 0.017453292519943295 * rtb_FlightPathAngle_g;

      // UnitConversion: '<S41>/Unit Conversion'
      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Switch *= 0.017453292519943295;

      // Trigonometry: '<S42>/Trigonometric Function1'
      rtb_AirSpeed_c = std::sin(rtb_Switch);

      // Sum: '<S42>/Sum1' incorporates:
      //   Constant: '<S42>/Constant'
      //   Product: '<S42>/Product1'

      rtb_AirSpeed_c = 1.0 - codegenReal2Mission_ConstB.sqrt_d *
        codegenReal2Mission_ConstB.sqrt_d * rtb_AirSpeed_c * rtb_AirSpeed_c;

      // Sqrt: '<S40>/sqrt'
      rtb_FlightPathAngle_g = std::sqrt(rtb_AirSpeed_c);

      // Product: '<S40>/Product1' incorporates:
      //   Constant: '<S40>/Constant1'

      rtb_FlightPathAngle_g = 6.378137E+6 / rtb_FlightPathAngle_g;

      // Product: '<S25>/dNorth' incorporates:
      //   Constant: '<S40>/Constant2'
      //   Product: '<S40>/Product3'
      //   Trigonometry: '<S40>/Trigonometric Function1'

      rtb_AirSpeed_c = rtb_Switch_j / rt_atan2d_snf(1.0, rtb_FlightPathAngle_g *
        codegenReal2Mission_ConstB.Sum1_f / rtb_AirSpeed_c);

      // Product: '<S25>/dEast' incorporates:
      //   Constant: '<S40>/Constant3'
      //   Product: '<S40>/Product4'
      //   Trigonometry: '<S40>/Trigonometric Function'
      //   Trigonometry: '<S40>/Trigonometric Function2'
      //   UnitConversion: '<S26>/Unit Conversion'

      rtb_Switch = 1.0 / rt_atan2d_snf(1.0, rtb_FlightPathAngle_g * std::cos
        (rtb_Switch)) * (0.017453292519943295 * rtb_Abs1);

      // Sum: '<S25>/Sum2' incorporates:
      //   Product: '<S25>/x*cos'
      //   Product: '<S25>/y*sin'

      rtb_FlightPathAngle_g = rtb_AirSpeed_c *
        codegenReal2Mission_ConstB.SinCos_o2 + rtb_Switch *
        codegenReal2Mission_ConstB.SinCos_o1;

      // Sum: '<S25>/Sum3' incorporates:
      //   Product: '<S25>/x*sin'
      //   Product: '<S25>/y*cos'

      rtb_AirSpeed_f = rtb_Switch * codegenReal2Mission_ConstB.SinCos_o2 -
        rtb_AirSpeed_c * codegenReal2Mission_ConstB.SinCos_o1;

      // Gain: '<S13>/inverse' incorporates:
      //   DataStoreRead: '<S13>/AltitudeGCS'

      rtb_Switch = -codegenReal2Mission_DW.AltitudeGCS;

      // BusCreator: '<S13>/FixedWingGuidanceStateBus' incorporates:
      //   Gain: '<S19>/Gain1'
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_FixedWingGuidanceStateBus_H = 0.017453292519943295 *
        codegenReal2Mission_U.RealUAVLatLonState.HeadingAngle_deg;

      // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'
      //   Gain: '<S21>/Gain1'
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_RollAngle_i = 0.017453292519943295 *
        codegenReal2Mission_U.RealUAVLatLonState.RollAngle_deg;

      // BusCreator: '<S13>/FixedWingGuidanceStateBus' incorporates:
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_North_m = rtb_FlightPathAngle_g;
      rtb_FixedWingGuidanceStateBus_A =
        codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps;

      // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
      //   Inport: '<Root>/RealUAVLatLonState'
      //   Sum: '<S22>/Sum'

      rtb_Height_n = codegenReal2Mission_U.RealUAVLatLonState.Height_meter +
        rtb_Switch;

      // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_AirSpeed_c = codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps;

      // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'

      rtb_Switch = rtb_FixedWingGuidanceStateBus_H;

      // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
      //   Gain: '<S20>/Gain1'
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_FlightPathAngle_g = 0.017453292519943295 *
        codegenReal2Mission_U.RealUAVLatLonState.FlightPathAngle_deg;

      // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'
      //   Constant: '<S13>/dummyRollAngleRate'

      rtb_RollAngleRate = 0.0;

      // SignalConversion generated from: '<S2>/SimUAVStateBus'
      rtb_North = codegenReal2Mission_B.SimUAVStateZOH.North;

      // SignalConversion generated from: '<S2>/SimUAVStateBus'
      rtb_East = codegenReal2Mission_B.SimUAVStateZOH.East;

      // SignalConversion generated from: '<S2>/SimUAVStateBus'
      rtb_Height = codegenReal2Mission_B.SimUAVStateZOH.Height;

      // SignalConversion generated from: '<S2>/SimUAVStateBus'
      rtb_AirSpeed_ae = codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

      // SignalConversion generated from: '<S2>/SimUAVStateBus'
      rtb_HeadingAngle = codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle;

      // SignalConversion generated from: '<S2>/SimUAVStateBus'
      rtb_FlightPathAngle = codegenReal2Mission_B.SimUAVStateZOH.FlightPathAngle;

      // SignalConversion generated from: '<S2>/SimUAVStateBus'
      rtb_RollAngle_k = codegenReal2Mission_B.SimUAVStateZOH.RollAngle;

      // SignalConversion generated from: '<S2>/SimUAVStateBus'
      rtb_RollAngleRate_m = codegenReal2Mission_B.SimUAVStateZOH.RollAngleRate;

      // Memory: '<S2>/MemoryExecutionTrigger'
      rtb_MemoryExecutionTrigger =
        codegenReal2Mission_DW.MemoryExecutionTrigger_Previous;

      // Outputs for Atomic SubSystem: '<S2>/Real2SimNav'
      // Outputs for Atomic SubSystem: '<S16>/HeadingNaNProtection'
      // Memory: '<S72>/MemoryRefHeight'
      rtb_OverwriteHeight = codegenReal2Mission_DW.MemoryRefHeight_PreviousInput;

      // End of Outputs for SubSystem: '<S16>/HeadingNaNProtection'

      // Outputs for Atomic SubSystem: '<S16>/GenerateTrack'
      // S-Function (sfix_udelay): '<S70>/EastSequence'
      rtb_MatrixConcatenate[145] = codegenReal2Mission_B.SimUAVStateZOH.East;

      // Gain: '<S70>/TrackInvH'
      codegenReal2Mission_B.TrackInvH =
        -codegenReal2Mission_B.SimUAVStateZOH.Height;

      // S-Function (sfix_udelay): '<S70>/HeightSequence'
      rtb_MatrixConcatenate[218] = codegenReal2Mission_B.TrackInvH;
      for (i = 0; i < 72; i++) {
        // S-Function (sfix_udelay): '<S70>/EastSequence'
        rtb_MatrixConcatenate[i + 73] = codegenReal2Mission_DW.EastSequence_X[i];

        // S-Function (sfix_udelay): '<S70>/HeightSequence'
        rtb_MatrixConcatenate[i + 146] =
          codegenReal2Mission_DW.HeightSequence_X[i];

        // S-Function (sfix_udelay): '<S70>/NorthSequence'
        rtb_MatrixConcatenate[i] = codegenReal2Mission_DW.NorthSequence_X[i];
      }

      // S-Function (sfix_udelay): '<S70>/NorthSequence'
      rtb_MatrixConcatenate[72] = codegenReal2Mission_B.SimUAVStateZOH.North;
      for (i = 0; i < 71; i++) {
        // Update for S-Function (sfix_udelay): '<S70>/EastSequence'
        codegenReal2Mission_DW.EastSequence_X[i] =
          codegenReal2Mission_DW.EastSequence_X[i + 1];

        // Update for S-Function (sfix_udelay): '<S70>/HeightSequence'
        codegenReal2Mission_DW.HeightSequence_X[i] =
          codegenReal2Mission_DW.HeightSequence_X[i + 1];

        // Update for S-Function (sfix_udelay): '<S70>/NorthSequence'
        codegenReal2Mission_DW.NorthSequence_X[i] =
          codegenReal2Mission_DW.NorthSequence_X[i + 1];
      }

      // Update for S-Function (sfix_udelay): '<S70>/EastSequence'
      codegenReal2Mission_DW.EastSequence_X[71] =
        codegenReal2Mission_B.SimUAVStateZOH.East;

      // Update for S-Function (sfix_udelay): '<S70>/HeightSequence'
      codegenReal2Mission_DW.HeightSequence_X[71] =
        codegenReal2Mission_B.TrackInvH;

      // Update for S-Function (sfix_udelay): '<S70>/NorthSequence'
      codegenReal2Mission_DW.NorthSequence_X[71] =
        codegenReal2Mission_B.SimUAVStateZOH.North;

      // End of Outputs for SubSystem: '<S16>/GenerateTrack'

      // Sum: '<S16>/Minus' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'
      //   Inport: '<Root>/GroundSpd'
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_HeadWind = codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps -
        codegenReal2Mission_U.GroundSpd;

      // RelationalOperator: '<S74>/Compare' incorporates:
      //   Constant: '<S74>/Constant'
      //   DataStoreRead: '<S16>/ReadFlightMode_Log'

      codegenReal2Mission_B.Compare = (codegenReal2Mission_DW.FlightMode_Log ==
        3);

      // Outputs for Atomic SubSystem: '<S16>/SpeedControl'
      // Sum: '<S80>/Sum' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'

      rtb_Heading_Log[0] = codegenReal2Mission_B.SimUAVStateZOH.North -
        rtb_North_m;
      rtb_Heading_Log[1] = codegenReal2Mission_B.SimUAVStateZOH.East -
        rtb_AirSpeed_f;
      rtb_Heading_Log[2] = codegenReal2Mission_B.SimUAVStateZOH.Height -
        codegenReal2Mission_B.SimUAVStateZOH.Height;

      // DotProduct: '<S80>/Dot Product'
      eastSpeed = rtb_Heading_Log[0] * rtb_Heading_Log[0];

      // Outputs for Atomic SubSystem: '<S16>/GenerateTrack'
      // Sum: '<S82>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   S-Function (sfix_udelay): '<S70>/NorthSequence'
      //   Selector: '<S75>/WayPoint2d3'

      a0 = rtb_MatrixConcatenate[24] -
        codegenReal2Mission_B.SimUAVStateZOH.North;

      // End of Outputs for SubSystem: '<S16>/GenerateTrack'

      // DotProduct: '<S82>/Dot Product'
      d = a0 * a0;

      // Outputs for Atomic SubSystem: '<S16>/GenerateTrack'
      // Selector: '<S75>/WayPoint0d3' incorporates:
      //   DataStoreRead: '<S2>/ReadHeading_Log'
      //   S-Function (sfix_udelay): '<S70>/NorthSequence'

      rtb_Heading_Log[0] = codegenReal2Mission_B.SimUAVStateZOH.North;

      // End of Outputs for SubSystem: '<S16>/GenerateTrack'

      // DotProduct: '<S80>/Dot Product'
      eastSpeed += rtb_Heading_Log[1] * rtb_Heading_Log[1];

      // Sum: '<S82>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   Selector: '<S75>/WayPoint0d3'
      //   Selector: '<S75>/WayPoint2d3'

      a0 = rtb_MatrixConcatenate[97] - rtb_MatrixConcatenate[145];

      // DotProduct: '<S82>/Dot Product'
      d += a0 * a0;

      // Selector: '<S75>/WayPoint0d3' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreRead: '<S2>/ReadHeading_Log'

      rtb_Heading_Log[1] = rtb_MatrixConcatenate[145];

      // DotProduct: '<S80>/Dot Product'
      rtb_Abs1 = rtb_Heading_Log[2] * rtb_Heading_Log[2] + eastSpeed;

      // Sum: '<S82>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   Selector: '<S75>/WayPoint0d3'
      //   Selector: '<S75>/WayPoint2d3'

      a0 = rtb_MatrixConcatenate[170] - rtb_MatrixConcatenate[218];

      // Selector: '<S75>/WayPoint0d3' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreRead: '<S2>/ReadHeading_Log'

      rtb_Heading_Log[2] = rtb_MatrixConcatenate[218];

      // Sqrt: '<S80>/sqrt'
      rtb_Abs1 = std::sqrt(rtb_Abs1);

      // Gain: '<S75>/InverseY'
      codegenReal2Mission_B.InverseY = -rtb_Abs1;

      // DotProduct: '<S82>/Dot Product'
      rtb_Switch_j = a0 * a0 + d;

      // Sqrt: '<S82>/sqrt'
      rtb_Switch_j = std::sqrt(rtb_Switch_j);

      // Gain: '<S75>/InverseR'
      codegenReal2Mission_B.InverseR = -rtb_Switch_j;

      // End of Outputs for SubSystem: '<S16>/SpeedControl'
      // End of Outputs for SubSystem: '<S2>/Real2SimNav'
      // End of Outputs for SubSystem: '<Root>/Real2SimGuidance'
    }

    // Outputs for Atomic SubSystem: '<Root>/Real2SimGuidance'
    // Outputs for Atomic SubSystem: '<S2>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S16>/SpeedControl'
    // Outputs for Atomic SubSystem: '<S75>/ADRC'
    // Outputs for Enabled SubSystem: '<S79>/ESO' incorporates:
    //   EnablePort: '<S84>/Enable'

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M)) && rtmIsMajorTimeStep
        ((&codegenReal2Mission_M))) {
      codegenReal2Mission_DW.ESO_MODE = codegenReal2Mission_B.Compare;
    }

    if (codegenReal2Mission_DW.ESO_MODE) {
      // Integrator: '<S84>/ESO'
      codegenReal2Mission_B.ESO = codegenReal2Mission_X.ESO_CSTATE;

      // Integrator: '<S84>/ESO_dot'
      codegenReal2Mission_B.ESO_dot = codegenReal2Mission_X.ESO_dot_CSTATE;

      // Integrator: '<S84>/ESO_dotdot'
      codegenReal2Mission_B.ESO_dotdot = codegenReal2Mission_X.ESO_dotdot_CSTATE;
    }

    // End of Outputs for SubSystem: '<S79>/ESO'

    // Integrator: '<S86>/dotTD'
    codegenReal2Mission_B.dotTD = codegenReal2Mission_X.dotTD_CSTATE;

    // MATLAB Function: '<S85>/fhan(e1,ce2,r,h1)' incorporates:
    //   Gain: '<S85>/Gain'
    //   Integrator: '<S86>/TD_AirSpdADRC'
    //   Sum: '<S79>/SumTD'
    //   Sum: '<S79>/SumTDdot'

    a0 = (codegenReal2Mission_B.dotTD - codegenReal2Mission_B.ESO_dot) * 3.2203 *
      9.6465;
    eastSpeed = (codegenReal2Mission_X.TD_AirSpdADRC_CSTATE -
                 codegenReal2Mission_B.ESO) + a0;
    if (eastSpeed < 0.0) {
      d = -1.0;
    } else if (eastSpeed > 0.0) {
      d = 1.0;
    } else if (eastSpeed == 0.0) {
      d = 0.0;
    } else {
      d = (rtNaN);
    }

    skySpeed = (std::sqrt((8.0 * std::abs(eastSpeed) + 465.27481124999997) *
                          465.27481124999997) - 465.27481124999997) * d / 2.0 +
      a0;
    if (eastSpeed + 465.27481124999997 < 0.0) {
      d = -1.0;
    } else if (eastSpeed + 465.27481124999997 > 0.0) {
      d = 1.0;
    } else if (eastSpeed + 465.27481124999997 == 0.0) {
      d = 0.0;
    } else {
      d = (rtNaN);
    }

    if (eastSpeed - 465.27481124999997 < 0.0) {
      q = -1.0;
    } else if (eastSpeed - 465.27481124999997 > 0.0) {
      q = 1.0;
    } else if (eastSpeed - 465.27481124999997 == 0.0) {
      q = 0.0;
    } else {
      q = (rtNaN);
    }

    eastSpeed = ((a0 + eastSpeed) - skySpeed) * ((d - q) / 2.0) + skySpeed;
    if (eastSpeed < 0.0) {
      skySpeed = -1.0;
    } else if (eastSpeed > 0.0) {
      skySpeed = 1.0;
    } else if (eastSpeed == 0.0) {
      skySpeed = 0.0;
    } else {
      skySpeed = (rtNaN);
    }

    if (eastSpeed + 465.27481124999997 < 0.0) {
      a0 = -1.0;
    } else if (eastSpeed + 465.27481124999997 > 0.0) {
      a0 = 1.0;
    } else if (eastSpeed + 465.27481124999997 == 0.0) {
      a0 = 0.0;
    } else {
      a0 = (rtNaN);
    }

    if (eastSpeed - 465.27481124999997 < 0.0) {
      d = -1.0;
    } else if (eastSpeed - 465.27481124999997 > 0.0) {
      d = 1.0;
    } else if (eastSpeed - 465.27481124999997 == 0.0) {
      d = 0.0;
    } else {
      d = (rtNaN);
    }

    // Gain: '<S79>/GainADRCinvb0' incorporates:
    //   Gain: '<S85>/Gain1'
    //   MATLAB Function: '<S85>/fhan(e1,ce2,r,h1)'
    //   Sum: '<S79>/ESOpNLSEF'

    codegenReal2Mission_B.GainADRCinvb0 = (-((eastSpeed / 465.27481124999997 -
      skySpeed) * -5.0 * ((a0 - d) / 2.0) - 5.0 * skySpeed) -
      codegenReal2Mission_B.ESO_dotdot) * 0.44698730556052207;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // ZeroOrderHold: '<S79>/ZOH_ADRC_U' incorporates:
      //   DataStoreWrite: '<S79>/WriteADRC_U_Log'

      codegenReal2Mission_DW.ADRC_U_Log = codegenReal2Mission_B.GainADRCinvb0;

      // ZeroOrderHold: '<S79>/ZOH_ADRC_LagDis' incorporates:
      //   DataStoreWrite: '<S79>/WriteLagDistance'
      //   Integrator: '<S86>/TD_AirSpdADRC'
      //   Sum: '<S79>/LagDistanceSum'

      codegenReal2Mission_DW.LagDistance =
        codegenReal2Mission_X.TD_AirSpdADRC_CSTATE -
        codegenReal2Mission_B.InverseY;
    }

    // Sum: '<S79>/SumY'
    codegenReal2Mission_B.SumY = codegenReal2Mission_B.ESO -
      codegenReal2Mission_B.InverseY;

    // MATLAB Function: '<S86>/fhan_AirSpdADRC' incorporates:
    //   Integrator: '<S86>/TD_AirSpdADRC'
    //   SignalConversion generated from: '<S90>/ SFunction '
    //   Sum: '<S86>/Sum1'

    a0 = codegenReal2Mission_B.dotTD * 0.1;
    eastSpeed = (codegenReal2Mission_X.TD_AirSpdADRC_CSTATE -
                 codegenReal2Mission_B.InverseR) + a0;
    if (eastSpeed < 0.0) {
      d = -1.0;
    } else if (eastSpeed > 0.0) {
      d = 1.0;
    } else if (eastSpeed == 0.0) {
      d = 0.0;
    } else {
      d = (rtNaN);
    }

    skySpeed = (std::sqrt((8.0 * std::abs(eastSpeed) + 0.005000000000000001) *
                          0.005000000000000001) - 0.005000000000000001) * d /
      2.0 + a0;
    if (eastSpeed + 0.005000000000000001 < 0.0) {
      d = -1.0;
    } else if (eastSpeed + 0.005000000000000001 > 0.0) {
      d = 1.0;
    } else if (eastSpeed + 0.005000000000000001 == 0.0) {
      d = 0.0;
    } else {
      d = (rtNaN);
    }

    if (eastSpeed - 0.005000000000000001 < 0.0) {
      q = -1.0;
    } else if (eastSpeed - 0.005000000000000001 > 0.0) {
      q = 1.0;
    } else if (eastSpeed - 0.005000000000000001 == 0.0) {
      q = 0.0;
    } else {
      q = (rtNaN);
    }

    eastSpeed = ((a0 + eastSpeed) - skySpeed) * ((d - q) / 2.0) + skySpeed;
    if (eastSpeed < 0.0) {
      skySpeed = -1.0;
    } else if (eastSpeed > 0.0) {
      skySpeed = 1.0;
    } else if (eastSpeed == 0.0) {
      skySpeed = 0.0;
    } else {
      skySpeed = (rtNaN);
    }

    if (eastSpeed + 0.005000000000000001 < 0.0) {
      a0 = -1.0;
    } else if (eastSpeed + 0.005000000000000001 > 0.0) {
      a0 = 1.0;
    } else if (eastSpeed + 0.005000000000000001 == 0.0) {
      a0 = 0.0;
    } else {
      a0 = (rtNaN);
    }

    if (eastSpeed - 0.005000000000000001 < 0.0) {
      d = -1.0;
    } else if (eastSpeed - 0.005000000000000001 > 0.0) {
      d = 1.0;
    } else if (eastSpeed - 0.005000000000000001 == 0.0) {
      d = 0.0;
    } else {
      d = (rtNaN);
    }

    codegenReal2Mission_B.fh_g = (eastSpeed / 0.005000000000000001 - skySpeed) *
      -0.5 * ((a0 - d) / 2.0) - 0.5 * skySpeed;

    // End of MATLAB Function: '<S86>/fhan_AirSpdADRC'
    // End of Outputs for SubSystem: '<S75>/ADRC'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Sum: '<S81>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreRead: '<S2>/ReadHeading_Log'
      //   Selector: '<S75>/WayPoint1d3'

      a0 = rtb_MatrixConcatenate[48] - rtb_Heading_Log[0];

      // DotProduct: '<S81>/Dot Product'
      d = a0 * a0;

      // Sum: '<S83>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreRead: '<S2>/ReadHeading_Log'
      //   Selector: '<S75>/WayPoint1d3'
      //   Selector: '<S75>/WayPoint3d3'
      //   Sum: '<S81>/Sum'

      eastSpeed = rtb_MatrixConcatenate[0] - rtb_Heading_Log[0];

      // DotProduct: '<S83>/Dot Product'
      rtb_ycos_o = eastSpeed * eastSpeed;

      // Sum: '<S81>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreRead: '<S2>/ReadHeading_Log'
      //   Selector: '<S75>/WayPoint1d3'

      a0 = rtb_MatrixConcatenate[121] - rtb_Heading_Log[1];

      // DotProduct: '<S81>/Dot Product'
      d += a0 * a0;

      // Sum: '<S83>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreRead: '<S2>/ReadHeading_Log'
      //   Selector: '<S75>/WayPoint1d3'
      //   Selector: '<S75>/WayPoint3d3'
      //   Sum: '<S81>/Sum'

      eastSpeed = rtb_MatrixConcatenate[73] - rtb_Heading_Log[1];

      // DotProduct: '<S83>/Dot Product'
      rtb_ycos_o += eastSpeed * eastSpeed;

      // Sum: '<S81>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreRead: '<S2>/ReadHeading_Log'
      //   Selector: '<S75>/WayPoint1d3'

      a0 = rtb_MatrixConcatenate[194] - rtb_Heading_Log[2];

      // Sum: '<S83>/Sum' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreRead: '<S2>/ReadHeading_Log'
      //   Selector: '<S75>/WayPoint1d3'
      //   Selector: '<S75>/WayPoint3d3'
      //   Sum: '<S81>/Sum'

      eastSpeed = rtb_MatrixConcatenate[146] - rtb_Heading_Log[2];

      // DotProduct: '<S81>/Dot Product'
      rtb_Down = a0 * a0 + d;

      // Sqrt: '<S81>/sqrt'
      rtb_Down = std::sqrt(rtb_Down);

      // Sum: '<S75>/ActRngmMinRng'
      rtb_Abs1 -= rtb_Down;

      // Sum: '<S75>/ComputeLB'
      rtb_LowerBound = rtb_Down - rtb_Switch_j;

      // DotProduct: '<S83>/Dot Product'
      rtb_ycos_o += eastSpeed * eastSpeed;

      // Sum: '<S75>/ComputeUB' incorporates:
      //   Sqrt: '<S83>/sqrt'

      rtb_ycos_o = std::sqrt(rtb_ycos_o) - rtb_Switch_j;

      // Sum: '<S75>/RefRngmMinRng'
      rtb_Down = rtb_Switch_j - rtb_Down;

      // SignalConversion generated from: '<S75>/SimStateBus'
      rtb_AirSpeed = codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

      // Sum: '<S75>/SumSpd' incorporates:
      //   DataStoreWrite: '<S79>/WriteADRC_U_Log'
      //   SignalConversion generated from: '<S75>/SimStateBus'

      rtb_RefGndSpd = (rtb_HeadWind + codegenReal2Mission_DW.ADRC_U_Log) +
        codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

      // Saturate: '<S75>/Saturation'
      if (rtb_Abs1 <= 54.697674418604649) {
        rtb_Abs1 = 54.697674418604649;
      }

      // End of Saturate: '<S75>/Saturation'

      // Sum: '<S75>/biasHm70' incorporates:
      //   Math: '<S75>/Square'
      //   Product: '<S75>/Divide'

      rtb_Down = rtb_Down * rtb_Down / rtb_Abs1 - rtb_Down;

      // Outputs for Atomic SubSystem: '<S16>/HeadingLogic'
      // SignalConversion generated from: '<S71>/TrackSimPath' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'

      rtb_FixedWingGuidanceStateBus_N[0] = rtb_North_m;
      rtb_FixedWingGuidanceStateBus_N[1] = rtb_AirSpeed_f;
      rtb_FixedWingGuidanceStateBus_N[2] = rtb_OverwriteHeight;
      rtb_FixedWingGuidanceStateBus_N[3] = rtb_FixedWingGuidanceStateBus_H;

      // MATLABSystem: '<S71>/TrackSimPath' incorporates:
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreWrite: '<S71>/WriteCrossTrackError'
      //   DataStoreWrite: '<S71>/WriteStatus_Log'
      //   Gain: '<S16>/LookaheadT'
      //   SignalConversion generated from: '<S75>/SimStateBus'

      WaypointFollowerBase_stepIntern(&codegenReal2Mission_DW.obj,
        rtb_FixedWingGuidanceStateBus_N, rtb_MatrixConcatenate, 3.6 *
        codegenReal2Mission_B.SimUAVStateZOH.AirSpeed, rtb_SwitchLookAheadNED,
        &rtb_Switch_j, &rtb_Abs1, &rtb_FlightMode_Log_l,
        &codegenReal2Mission_DW.CrossTrackError,
        &codegenReal2Mission_DW.Status_Log);

      // Switch: '<S71>/SwitchLookAheadNED' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'
      //   Concatenate: '<S70>/Matrix Concatenate'
      //   DataStoreWrite: '<S71>/WriteStatus_Log'
      //   Selector: '<S71>/WayPoint3d3'
      //   Sum: '<S77>/EastArrow'
      //   Sum: '<S77>/NorthArrow'
      //   Switch: '<S71>/SwitchTargetHDG'
      //   Trigonometry: '<S77>/HdgCmd'

      if (codegenReal2Mission_DW.Status_Log > 0) {
        rtb_SwitchLookAheadNED[0] = rtb_MatrixConcatenate[0];
        rtb_SwitchLookAheadNED[1] = rtb_MatrixConcatenate[73];
        rtb_SwitchLookAheadNED[2] = rtb_MatrixConcatenate[146];
        rtb_Switch_j = rt_atan2d_snf(rtb_MatrixConcatenate[73] - rtb_AirSpeed_f,
          rtb_MatrixConcatenate[0] - rtb_North_m);
      }

      // End of Switch: '<S71>/SwitchLookAheadNED'
      // End of Outputs for SubSystem: '<S16>/HeadingLogic'

      // DataStoreWrite: '<S16>/WriteHeading_Log' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'
      //   MATLAB Function: '<S16>/AngLog'

      codegenReal2Mission_DW.Heading_Log[0] = angdiff_GFr2Xk58
        (rtb_FixedWingGuidanceStateBus_H, rtb_Switch_j);
      codegenReal2Mission_DW.Heading_Log[1] = angdiff_GFr2Xk58(0.0,
        rtb_FixedWingGuidanceStateBus_H);
      codegenReal2Mission_DW.Heading_Log[2] = angdiff_GFr2Xk58(0.0, rtb_Switch_j);
    }

    // End of Outputs for SubSystem: '<S16>/SpeedControl'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Switch: '<S16>/BiasHSwitch'
      if (rtb_MemoryExecutionTrigger != 0.0) {
        // Switch: '<S16>/BiasHSwitch' incorporates:
        //   Constant: '<S16>/ZeroBias'

        codegenReal2Mission_B.BiasHSwitch = 0.0;
      } else {
        // Switch: '<S16>/BiasHSwitch'
        codegenReal2Mission_B.BiasHSwitch = rtb_Down;
      }

      // End of Switch: '<S16>/BiasHSwitch'

      // Truth Table: '<S16>/Engagement' incorporates:
      //   DataStoreRead: '<S16>/ReadLagDistance'
      //   DataStoreWrite: '<S71>/WriteCrossTrackError'

      //  Front Distance within Upper &  Lower Bound
      //  CrossTrack Error within 1.5 Second Bound
      if ((codegenReal2Mission_DW.LagDistance < rtb_ycos_o) &&
          (codegenReal2Mission_DW.LagDistance > rtb_LowerBound) &&
          (codegenReal2Mission_DW.CrossTrackError < rtb_AirSpeed * 1.5)) {
        //  Real UAV Engaged with Simulation UAV
        rtb_Engaged = true;
      } else {
        //  Default
        //  Real UAV Not Engaged with Simulation UAV
        rtb_Engaged = false;
      }

      // End of Truth Table: '<S16>/Engagement'

      // Outputs for Atomic SubSystem: '<S16>/MaxBrake'
      // Trigonometry: '<S73>/North'
      rtb_Abs1 = std::cos(codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle);

      // Trigonometry: '<S73>/East'
      rtb_Switch_j = std::sin(codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle);

      // Gain: '<S73>/Up2Down'
      rtb_Down = -codegenReal2Mission_B.SimUAVStateZOH.Height;

      // Sum: '<S78>/Sum' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'
      //   Constant: '<S73>/AheadRange'
      //   Product: '<S73>/EastDisBrk'
      //   Product: '<S73>/NorthDisBrk'
      //   Sum: '<S73>/SumEastBrk'
      //   Sum: '<S73>/SumNorthBrk'

      rtb_Sum_b[0] = (84.0 * rtb_Abs1 +
                      codegenReal2Mission_B.SimUAVStateZOH.North) - rtb_North_m;
      rtb_Sum_b[1] = (84.0 * rtb_Switch_j +
                      codegenReal2Mission_B.SimUAVStateZOH.East) -
        rtb_AirSpeed_f;
      rtb_Sum_b[2] = rtb_Down - rtb_OverwriteHeight;

      // End of Outputs for SubSystem: '<S16>/MaxBrake'

      // Gain: '<S16>/NED2NEU' incorporates:
      //   Switch: '<S71>/SwitchLookAheadNED'

      codegenReal2Mission_B.NorthEastHeight[0] = rtb_SwitchLookAheadNED[0];
      codegenReal2Mission_B.NorthEastHeight[1] = rtb_SwitchLookAheadNED[1];
      codegenReal2Mission_B.NorthEastHeight[2] = -rtb_SwitchLookAheadNED[2];

      // ZeroOrderHold: '<S16>/LookaheadPoint_ZOH' incorporates:
      //   Gain: '<S16>/NED2NEU'
      //   Integrator: '<S76>/TD_Alt'
      //   Sum: '<S16>/SumBiasH'

      rtb_RealUAVNEUState[0] = codegenReal2Mission_B.NorthEastHeight[0];
      rtb_RealUAVNEUState[1] = codegenReal2Mission_B.NorthEastHeight[1];
      rtb_RealUAVNEUState[2] = codegenReal2Mission_B.NorthEastHeight[2] +
        codegenReal2Mission_X.TD_Alt_CSTATE;

      // Outputs for Atomic SubSystem: '<S16>/MaxBrake'
      // DotProduct: '<S78>/Dot Product'
      rtb_Abs1 = (rtb_Sum_b[0] * rtb_Sum_b[0] + rtb_Sum_b[1] * rtb_Sum_b[1]) +
        rtb_Sum_b[2] * rtb_Sum_b[2];

      // Switch: '<S73>/BrkSwitch' incorporates:
      //   Constant: '<S73>/MaxBrake'
      //   Sqrt: '<S78>/sqrt'

      if (!(std::sqrt(rtb_Abs1) >= 168.0)) {
        rtb_RefGndSpd = 0.0;
      }

      // End of Switch: '<S73>/BrkSwitch'

      // Saturate: '<S73>/SpeedProtection'
      if (rtb_RefGndSpd > 41.0) {
        rtb_RefAirspeed_Log = 41.0;
      } else if (rtb_RefGndSpd < 29.0) {
        rtb_RefAirspeed_Log = 29.0;
      } else {
        rtb_RefAirspeed_Log = rtb_RefGndSpd;
      }

      // End of Saturate: '<S73>/SpeedProtection'
      // End of Outputs for SubSystem: '<S16>/MaxBrake'
    }

    // Integrator: '<S76>/dotAltTD'
    codegenReal2Mission_B.dotAltTD = codegenReal2Mission_X.dotAltTD_CSTATE;

    // MATLAB Function: '<S76>/fhan_Alt' incorporates:
    //   Constant: '<S76>/Constant2'
    //   Constant: '<S76>/Constant3'
    //   Integrator: '<S76>/TD_Alt'
    //   Sum: '<S76>/Sum1'

    codegenReal2Mission_fhan_Bank(codegenReal2Mission_X.TD_Alt_CSTATE -
      codegenReal2Mission_B.BiasHSwitch, codegenReal2Mission_B.dotAltTD, 1.0,
      0.1, &codegenReal2Mission_B.fh);

    // End of Outputs for SubSystem: '<S2>/Real2SimNav'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // DataStoreRead: '<S2>/ReadLagDistance'
      rtb_LowerBound = codegenReal2Mission_DW.LagDistance;

      // DataStoreRead: '<S2>/ReadCrossTrackError'
      rtb_ycos_o = codegenReal2Mission_DW.CrossTrackError;

      // DataStoreRead: '<S2>/ReadHeading_Log'
      rtb_Heading_Log[0] = codegenReal2Mission_DW.Heading_Log[0];
      rtb_Heading_Log[1] = codegenReal2Mission_DW.Heading_Log[1];
      rtb_Heading_Log[2] = codegenReal2Mission_DW.Heading_Log[2];

      // DataStoreRead: '<S2>/ReadADRC_U_Log'
      rtb_Down = codegenReal2Mission_DW.ADRC_U_Log;

      // Outputs for Atomic SubSystem: '<S2>/Real2SimNav'
      // DataStoreRead: '<S2>/ReadbiasH_Log' incorporates:
      //   Integrator: '<S76>/TD_Alt'

      rtb_Switch_j = codegenReal2Mission_X.TD_Alt_CSTATE;

      // End of Outputs for SubSystem: '<S2>/Real2SimNav'

      // DataStoreRead: '<S2>/ReadFlightMode_Log'
      rtb_FlightMode_Log_l = codegenReal2Mission_DW.FlightMode_Log;

      // DataStoreRead: '<S2>/ReadStatus_Log'
      rtb_Status_Log = codegenReal2Mission_DW.Status_Log;

      // Trigonometry: '<S12>/Atan2' incorporates:
      //   Inport: '<Root>/GroundSpd'

      rtb_Abs1 = rt_atan2d_snf(rtb_skySpeed, codegenReal2Mission_U.GroundSpd);

      // Scope: '<S2>/ModelLogging' incorporates:
      //   Inport: '<Root>/Altitude'
      //   Inport: '<Root>/GroundSpd'

      if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        StructLogVar *svar = (StructLogVar *)
          codegenReal2Mission_DW.ModelLogging_PWORK.LoggedData[0];
        LogVar *var = svar->signals.values;

        // time
        {
          double locTime = (((&codegenReal2Mission_M)->Timing.clockTick1) * 0.1);
          ;
          rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
        }

        // signals
        {
          real_T up0[8];
          up0[0] = rtb_North_m;
          up0[1] = rtb_AirSpeed_f;
          up0[2] = rtb_Height_n;
          up0[3] = rtb_AirSpeed_c;
          up0[4] = rtb_Switch;
          up0[5] = rtb_FlightPathAngle_g;
          up0[6] = rtb_RollAngle_i;
          up0[7] = rtb_RollAngleRate;
          rt_UpdateLogVar((LogVar *)var, up0, 0);
          var = var->next;
        }

        {
          real_T up1[8];
          up1[0] = rtb_North;
          up1[1] = rtb_East;
          up1[2] = rtb_Height;
          up1[3] = rtb_AirSpeed_ae;
          up1[4] = rtb_HeadingAngle;
          up1[5] = rtb_FlightPathAngle;
          up1[6] = rtb_RollAngle_k;
          up1[7] = rtb_RollAngleRate_m;
          rt_UpdateLogVar((LogVar *)var, up1, 0);
          var = var->next;
        }

        {
          real_T up2[1];
          up2[0] = rtb_RefAirspeed_Log;
          rt_UpdateLogVar((LogVar *)var, up2, 0);
          var = var->next;
        }

        {
          real_T up3[1];
          up3[0] = rtb_LowerBound;
          rt_UpdateLogVar((LogVar *)var, up3, 0);
          var = var->next;
        }

        {
          real_T up4[3];
          up4[0] = rtb_RealUAVNEUState[0];
          up4[1] = rtb_RealUAVNEUState[1];
          up4[2] = rtb_RealUAVNEUState[2];
          rt_UpdateLogVar((LogVar *)var, up4, 0);
          var = var->next;
        }

        {
          real_T up5[1];
          up5[0] = rtb_ycos_o;
          rt_UpdateLogVar((LogVar *)var, up5, 0);
          var = var->next;
        }

        {
          boolean_T up6[1];
          up6[0] = rtb_Engaged;
          rt_UpdateLogVar((LogVar *)var, up6, 0);
          var = var->next;
        }

        {
          real_T up7[3];
          up7[0] = rtb_Heading_Log[0];
          up7[1] = rtb_Heading_Log[1];
          up7[2] = rtb_Heading_Log[2];
          rt_UpdateLogVar((LogVar *)var, up7, 0);
          var = var->next;
        }

        {
          real_T up8[1];
          up8[0] = rtb_Down;
          rt_UpdateLogVar((LogVar *)var, up8, 0);
          var = var->next;
        }

        {
          real_T up9[1];
          up9[0] = rtb_Switch_j;
          rt_UpdateLogVar((LogVar *)var, up9, 0);
          var = var->next;
        }

        {
          real_T up10[1];
          up10[0] = codegenReal2Mission_U.GroundSpd;
          rt_UpdateLogVar((LogVar *)var, up10, 0);
          var = var->next;
        }

        {
          uint8_T up11[1];
          up11[0] = rtb_FlightMode_Log_l;
          rt_UpdateLogVar((LogVar *)var, up11, 0);
          var = var->next;
        }

        {
          uint8_T up12[1];
          up12[0] = rtb_Status_Log;
          rt_UpdateLogVar((LogVar *)var, up12, 0);
          var = var->next;
        }

        {
          real_T up13[3];
          up13[0] = rtb_eastSpeed;
          up13[1] = rtb_northSpeed;
          up13[2] = rtb_skySpeed;
          rt_UpdateLogVar((LogVar *)var, up13, 0);
          var = var->next;
        }

        {
          real_T up14[1];
          up14[0] = codegenReal2Mission_U.Altitude;
          rt_UpdateLogVar((LogVar *)var, up14, 0);
          var = var->next;
        }

        {
          real_T up15[1];
          up15[0] = rtb_Abs1;
          rt_UpdateLogVar((LogVar *)var, up15, 0);
        }
      }

      // Chart: '<S2>/TASgreaterthan15for1Sec' incorporates:
      //   BusCreator: '<S13>/FixedWingGuidanceStateBus'
      //   Inport: '<Root>/RealUAVLatLonState'

      if (codegenReal2Mission_DW.is_active_c16_codegenReal2Missi == 0U) {
        codegenReal2Mission_DW.is_active_c16_codegenReal2Missi = 1U;
        codegenReal2Mission_DW.is_c16_codegenReal2Mission =
          codegenReal2Missi_IN_NotTakeOff;
        rEQ0 = false;
        codegenReal2Mission_DW.Count = 0.0;
      } else if (codegenReal2Mission_DW.is_c16_codegenReal2Mission == 1) {
        rEQ0 = true;

        // case IN_NotTakeOff:
      } else if (codegenReal2Mission_DW.Count >= 9.0) {
        codegenReal2Mission_DW.is_c16_codegenReal2Mission =
          codegenReal2Mission_IN_InAir;
        rEQ0 = true;
      } else if ((rtb_FixedWingGuidanceStateBus_A < 15.0) ||
                 (codegenReal2Mission_U.RealUAVLatLonState.Height_meter < 50.0))
      {
        codegenReal2Mission_DW.is_c16_codegenReal2Mission =
          codegenReal2Missi_IN_NotTakeOff;
        rEQ0 = false;
        codegenReal2Mission_DW.Count = 0.0;
      } else {
        rEQ0 = false;
        codegenReal2Mission_DW.Count++;
      }

      // End of Chart: '<S2>/TASgreaterthan15for1Sec'

      // Chart: '<S2>/TriggerTermination' incorporates:
      //   Inport: '<Root>/FlightMode'
      //   Inport: '<Root>/RealUAVLatLonState'

      if (codegenReal2Mission_DW.is_active_c34_codegenReal2Missi == 0U) {
        codegenReal2Mission_DW.is_active_c34_codegenReal2Missi = 1U;
        codegenReal2Mission_B.Terminate = false;
        codegenReal2Mission_DW.is_c34_codegenReal2Mission =
          codegenReal2M_IN_InitialPersuit;
        codegenReal2Mission_B.ExecutionTrigger = 0.0;
        codegenReal2Mission_DW.DataCounter = 0.0;
        codegenReal2Mission_DW.ReturnCounter = 0.0;
      } else {
        switch (codegenReal2Mission_DW.is_c34_codegenReal2Mission) {
         case codegenReal2M_IN_InitialPersuit:
          if (codegenReal2Mission_DW.DataCounter >= 299.0) {
            codegenReal2Mission_DW.is_c34_codegenReal2Mission =
              codegenReal_IN_MissionExecution;
            codegenReal2Mission_B.ExecutionTrigger = 1.0;
            codegenReal2Mission_DW.DataCounter = 0.0;
            codegenReal2Mission_DW.ReturnCounter = 0.0;
          } else if (codegenReal2Mission_U.FlightMode == 6) {
            codegenReal2Mission_DW.is_c34_codegenReal2Mission =
              codegenReal2Mission_IN_Landing;
            codegenReal2Mission_B.ExecutionTrigger = 0.0;
          } else {
            codegenReal2Mission_B.ExecutionTrigger = 0.0;
            if ((!rEQ0) || (!rtb_Engaged)) {
              codegenReal2Mission_DW.DataCounter = 0.0;
            } else {
              codegenReal2Mission_DW.DataCounter++;
            }
          }
          break;

         case codegenReal2Mission_IN_Landing:
          if (codegenReal2Mission_U.RealUAVLatLonState.Height_meter < 30.0) {
            codegenReal2Mission_DW.is_c34_codegenReal2Mission =
              codegenRea_IN_MissionCompletion;
            codegenReal2Mission_B.Terminate = true;
          } else {
            codegenReal2Mission_B.ExecutionTrigger = 0.0;
          }
          break;

         case codegenRea_IN_MissionCompletion:
          codegenReal2Mission_B.Terminate = true;
          break;

         default:
          // case IN_MissionExecution:
          if (codegenReal2Mission_U.FlightMode == 6) {
            codegenReal2Mission_DW.is_c34_codegenReal2Mission =
              codegenReal2Mission_IN_Landing;
            codegenReal2Mission_B.ExecutionTrigger = 0.0;
          } else if (codegenReal2Mission_DW.ReturnCounter >= 299.0) {
            codegenReal2Mission_DW.is_c34_codegenReal2Mission =
              codegenReal2M_IN_InitialPersuit;
            codegenReal2Mission_B.ExecutionTrigger = 0.0;
            codegenReal2Mission_DW.DataCounter = 0.0;
            codegenReal2Mission_DW.ReturnCounter = 0.0;
          } else {
            codegenReal2Mission_B.ExecutionTrigger = 1.0;
            if (rtb_Engaged) {
              codegenReal2Mission_DW.ReturnCounter = 0.0;
            } else {
              codegenReal2Mission_DW.ReturnCounter++;
            }
          }
          break;
        }
      }

      // End of Chart: '<S2>/TriggerTermination'

      // Stop: '<S2>/Stop Simulation'
      if (codegenReal2Mission_B.Terminate) {
        rtmSetStopRequested((&codegenReal2Mission_M), 1);
      }

      // End of Stop: '<S2>/Stop Simulation'

      // Product: '<S48>/x*cos'
      rtb_Abs1 = rtb_RealUAVNEUState[0] * codegenReal2Mission_ConstB.SinCos_o2_h;

      // Product: '<S48>/y*sin'
      rtb_Switch_j = rtb_RealUAVNEUState[1] *
        codegenReal2Mission_ConstB.SinCos_o1_f;

      // Sum: '<S48>/Sum'
      rtb_Switch = rtb_Abs1 - rtb_Switch_j;

      // Abs: '<S59>/Abs' incorporates:
      //   DataStoreRead: '<S14>/LatitudeGCS'

      rtb_Abs1 = std::abs(codegenReal2Mission_DW.LatitudeGCS);

      // Switch: '<S59>/Switch' incorporates:
      //   Bias: '<S59>/Bias'
      //   Bias: '<S59>/Bias1'
      //   Constant: '<S59>/Constant2'
      //   Constant: '<S60>/Constant'
      //   DataStoreRead: '<S14>/LatitudeGCS'
      //   Math: '<S59>/Math Function1'
      //   RelationalOperator: '<S60>/Compare'

      if (rtb_Abs1 > 180.0) {
        rtb_Abs1 = rt_modd_snf(codegenReal2Mission_DW.LatitudeGCS + 180.0, 360.0)
          + -180.0;
      } else {
        rtb_Abs1 = codegenReal2Mission_DW.LatitudeGCS;
      }

      // End of Switch: '<S59>/Switch'

      // Abs: '<S56>/Abs1'
      rtb_eastSpeed = std::abs(rtb_Abs1);

      // RelationalOperator: '<S58>/Compare' incorporates:
      //   Constant: '<S58>/Constant'

      rEQ0 = (rtb_eastSpeed > 90.0);

      // Switch: '<S56>/Switch' incorporates:
      //   Bias: '<S56>/Bias'
      //   Bias: '<S56>/Bias1'
      //   Gain: '<S56>/Gain'
      //   Product: '<S56>/Divide1'

      if (rEQ0) {
        // Signum: '<S56>/Sign1'
        if (rtb_Abs1 < 0.0) {
          rtb_Abs1 = -1.0;
        } else if (rtb_Abs1 > 0.0) {
          rtb_Abs1 = 1.0;
        } else if (rtb_Abs1 == 0.0) {
          rtb_Abs1 = 0.0;
        } else {
          rtb_Abs1 = (rtNaN);
        }

        // End of Signum: '<S56>/Sign1'
        rtb_Abs1 *= -(rtb_eastSpeed + -90.0) + 90.0;
      }

      // End of Switch: '<S56>/Switch'

      // UnitConversion: '<S64>/Unit Conversion'
      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Switch_j = 0.017453292519943295 * rtb_Abs1;

      // Trigonometry: '<S65>/Trigonometric Function1'
      rtb_Down = std::sin(rtb_Switch_j);

      // Sum: '<S65>/Sum1' incorporates:
      //   Constant: '<S65>/Constant'
      //   Product: '<S65>/Product1'

      rtb_Down = 1.0 - codegenReal2Mission_ConstB.sqrt_k *
        codegenReal2Mission_ConstB.sqrt_k * rtb_Down * rtb_Down;

      // Sqrt: '<S62>/sqrt'
      rtb_ycos_o = std::sqrt(rtb_Down);

      // Product: '<S62>/Product1' incorporates:
      //   Constant: '<S62>/Constant1'

      rtb_ycos_o = 6.378137E+6 / rtb_ycos_o;

      // Product: '<S48>/rad lat' incorporates:
      //   Constant: '<S62>/Constant2'
      //   Product: '<S62>/Product3'
      //   Trigonometry: '<S62>/Trigonometric Function1'

      rtb_Down = rt_atan2d_snf(1.0, rtb_ycos_o *
        codegenReal2Mission_ConstB.Sum1_j / rtb_Down) * rtb_Switch;

      // Product: '<S62>/Product4' incorporates:
      //   Trigonometry: '<S62>/Trigonometric Function'

      rtb_Switch = rtb_ycos_o * std::cos(rtb_Switch_j);

      // Product: '<S48>/x*sin'
      rtb_Switch_j = rtb_RealUAVNEUState[0] *
        codegenReal2Mission_ConstB.SinCos_o1_f;

      // Product: '<S48>/y*cos'
      rtb_ycos_o = rtb_RealUAVNEUState[1] *
        codegenReal2Mission_ConstB.SinCos_o2_h;

      // UnitConversion: '<S49>/Unit Conversion' incorporates:
      //   Constant: '<S62>/Constant3'
      //   Product: '<S48>/rad long '
      //   Sum: '<S48>/Sum1'
      //   Trigonometry: '<S62>/Trigonometric Function2'

      // Unit Conversion - from: rad to: deg
      // Expression: output = (57.2958*input) + (0)
      rtb_Switch = (rtb_Switch_j + rtb_ycos_o) * rt_atan2d_snf(1.0, rtb_Switch) *
        57.295779513082323;

      // Switch: '<S47>/Switch1' incorporates:
      //   Constant: '<S47>/Constant'
      //   Constant: '<S47>/Constant1'

      if (rEQ0) {
        rtb_Switch_j = 180.0;
      } else {
        rtb_Switch_j = 0.0;
      }

      // End of Switch: '<S47>/Switch1'

      // Sum: '<S47>/Sum' incorporates:
      //   DataStoreRead: '<S14>/LongitudeGCS'

      rtb_northSpeed = rtb_Switch_j + codegenReal2Mission_DW.LongitudeGCS;

      // Abs: '<S57>/Abs'
      rtb_Switch_j = std::abs(rtb_northSpeed);

      // Switch: '<S57>/Switch' incorporates:
      //   Bias: '<S57>/Bias'
      //   Bias: '<S57>/Bias1'
      //   Constant: '<S57>/Constant2'
      //   Constant: '<S61>/Constant'
      //   Math: '<S57>/Math Function1'
      //   RelationalOperator: '<S61>/Compare'

      if (rtb_Switch_j > 180.0) {
        rtb_northSpeed = rt_modd_snf(rtb_northSpeed + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S57>/Switch'

      // Sum: '<S45>/Sum' incorporates:
      //   UnitConversion: '<S49>/Unit Conversion'

      rtb_eastSpeed = 57.295779513082323 * rtb_Down + rtb_Abs1;

      // Abs: '<S53>/Abs'
      rtb_Abs1 = std::abs(rtb_eastSpeed);

      // Switch: '<S53>/Switch' incorporates:
      //   Bias: '<S53>/Bias'
      //   Bias: '<S53>/Bias1'
      //   Constant: '<S53>/Constant2'
      //   Constant: '<S54>/Constant'
      //   Math: '<S53>/Math Function1'
      //   RelationalOperator: '<S54>/Compare'

      if (rtb_Abs1 > 180.0) {
        rtb_eastSpeed = rt_modd_snf(rtb_eastSpeed + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S53>/Switch'

      // Abs: '<S50>/Abs1'
      rtb_skySpeed = std::abs(rtb_eastSpeed);

      // Switch: '<S50>/Switch' incorporates:
      //   Constant: '<S46>/Constant'
      //   Constant: '<S46>/Constant1'
      //   Constant: '<S52>/Constant'
      //   RelationalOperator: '<S52>/Compare'
      //   Switch: '<S46>/Switch1'

      if (rtb_skySpeed > 90.0) {
        // Signum: '<S50>/Sign1'
        if (rtb_eastSpeed < 0.0) {
          rtb_eastSpeed = -1.0;
        } else if (rtb_eastSpeed > 0.0) {
          rtb_eastSpeed = 1.0;
        } else if (rtb_eastSpeed == 0.0) {
          rtb_eastSpeed = 0.0;
        } else {
          rtb_eastSpeed = (rtNaN);
        }

        // End of Signum: '<S50>/Sign1'

        // Outport: '<Root>/LookAheadPoint' incorporates:
        //   Bias: '<S50>/Bias'
        //   Bias: '<S50>/Bias1'
        //   Gain: '<S50>/Gain'
        //   Product: '<S50>/Divide1'

        codegenReal2Mission_Y.LookAheadPoint_j.Latitude_deg = (-(rtb_skySpeed +
          -90.0) + 90.0) * rtb_eastSpeed;
        rtb_Switch_j = 180.0;
      } else {
        // Outport: '<Root>/LookAheadPoint'
        codegenReal2Mission_Y.LookAheadPoint_j.Latitude_deg = rtb_eastSpeed;
        rtb_Switch_j = 0.0;
      }

      // End of Switch: '<S50>/Switch'

      // Sum: '<S46>/Sum' incorporates:
      //   Sum: '<S45>/Sum'

      rtb_Switch = (rtb_Switch + rtb_northSpeed) + rtb_Switch_j;

      // Abs: '<S51>/Abs'
      rtb_Switch_j = std::abs(rtb_Switch);

      // Switch: '<S51>/Switch' incorporates:
      //   Constant: '<S55>/Constant'
      //   RelationalOperator: '<S55>/Compare'

      if (rtb_Switch_j > 180.0) {
        // Outport: '<Root>/LookAheadPoint' incorporates:
        //   Bias: '<S51>/Bias'
        //   Bias: '<S51>/Bias1'
        //   Constant: '<S51>/Constant2'
        //   Math: '<S51>/Math Function1'

        codegenReal2Mission_Y.LookAheadPoint_j.Longitude_deg = rt_modd_snf
          (rtb_Switch + 180.0, 360.0) + -180.0;
      } else {
        // Outport: '<Root>/LookAheadPoint'
        codegenReal2Mission_Y.LookAheadPoint_j.Longitude_deg = rtb_Switch;
      }

      // End of Switch: '<S51>/Switch'

      // Gain: '<S14>/Up2Down'
      rtb_Down = -rtb_RealUAVNEUState[2];

      // Chart: '<S2>/Only1stTimeBiasH'
      if (codegenReal2Mission_DW.is_active_c3_codegenReal2Missio == 0U) {
        codegenReal2Mission_DW.is_active_c3_codegenReal2Missio = 1U;
        codegenReal2Mission_DW.is_c3_codegenReal2Mission =
          codegenReal2Mission_IN_Start;
        codegenReal2Mission_B.BiasHTrigger = 0.0;
      } else if (codegenReal2Mission_DW.is_c3_codegenReal2Mission == 1) {
        codegenReal2Mission_B.BiasHTrigger = 1.0;

        // case IN_Start:
      } else if (codegenReal2Mission_B.ExecutionTrigger != 0.0) {
        codegenReal2Mission_DW.is_c3_codegenReal2Mission =
          codegenReal2Mission_IN_Running;
        codegenReal2Mission_B.BiasHTrigger = 1.0;
      } else {
        codegenReal2Mission_B.BiasHTrigger = 0.0;
      }

      // End of Chart: '<S2>/Only1stTimeBiasH'

      // Outport: '<Root>/RefAirspeed'
      codegenReal2Mission_Y.RefAirspeed = rtb_RefAirspeed_Log;

      // Outport: '<Root>/LookAheadPoint' incorporates:
      //   DataStoreRead: '<S14>/AltitudeGCS'
      //   Gain: '<S14>/inverse'
      //   Sum: '<S45>/Sum1'
      //   UnaryMinus: '<S45>/Ze2height'

      codegenReal2Mission_Y.LookAheadPoint_j.Height_meter = -rtb_Down -
        (-codegenReal2Mission_DW.AltitudeGCS);

      // Outport: '<Root>/EngagedFlag'
      codegenReal2Mission_Y.EngagedFlag = rtb_Engaged;

      // Gain: '<S1>/InvH2D'
      codegenReal2Mission_B.Down = -codegenReal2Mission_B.SimUAVStateZOH.Height;
    }

    // End of Outputs for SubSystem: '<Root>/Real2SimGuidance'

    // Step: '<S7>/Step'
    if ((&codegenReal2Mission_M)->Timing.t[0] < 0.0) {
      eastSpeed = 0.0;
    } else {
      eastSpeed = 0.057119866428905326;
    }

    // End of Step: '<S7>/Step'

    // Sum: '<S7>/Output' incorporates:
    //   Clock: '<S7>/Clock'
    //   Product: '<S7>/Product'

    rtb_RefAirspeed_Log = eastSpeed * (&codegenReal2Mission_M)->Timing.t[0];
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Memory: '<S1>/MemoryLookAheadP'
      rtb_Switch = codegenReal2Mission_DW.MemoryLookAheadP_PreviousInput;

      // Switch: '<S1>/CircleOscillation'
      if (rtb_Switch > 0.0) {
        // Switch: '<S1>/CircleOscillation' incorporates:
        //   Constant: '<S1>/Constant'

        codegenReal2Mission_B.CircleOscillation = 300.0;
      } else {
        // Switch: '<S1>/CircleOscillation' incorporates:
        //   Constant: '<S1>/Constant1'

        codegenReal2Mission_B.CircleOscillation = 0.0;
      }

      // End of Switch: '<S1>/CircleOscillation'
    }

    // SignalConversion generated from: '<S1>/TakeOffGathering' incorporates:
    //   Constant: '<S1>/Down'
    //   Product: '<S1>/ProductEast'
    //   Product: '<S1>/ProductNorth'
    //   Trigonometry: '<S1>/Cos'
    //   Trigonometry: '<S1>/Sin'

    rtb_Heading_Log[0] = std::sin(rtb_RefAirspeed_Log) *
      codegenReal2Mission_B.CircleOscillation;
    rtb_Heading_Log[1] = std::cos(rtb_RefAirspeed_Log) *
      codegenReal2Mission_B.CircleOscillation;
    rtb_Heading_Log[2] = -150.0;

    // MATLABSystem: '<S1>/TakeOffGathering' incorporates:
    //   SignalConversion generated from: '<S1>/TakeOffGathering'

    codegenReal2Mission_DW.obj_m.OrbitRadiusFlag = 0U;
    codegenReal2Mission_DW.obj_m.LookaheadDistFlag = 0U;
    rtb_LowerBound = codegenReal2Mission_B.SimUAVStateZOH.North -
      rtb_Heading_Log[0];
    rtb_TmpSignalConversionAtSFun_0[0] = rtb_LowerBound;
    rtb_RefAirspeed_Log = codegenReal2Mission_B.SimUAVStateZOH.East -
      rtb_Heading_Log[1];
    rtb_TmpSignalConversionAtSFun_0[1] = rtb_RefAirspeed_Log;
    if (codegenReal2Mission_norm(rtb_TmpSignalConversionAtSFun_0) <
        2.47032822920623E-323) {
      // MATLABSystem: '<S1>/TakeOffGathering'
      codegenReal2Mission_B.TakeOffGathering_o2 =
        codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle;
      rtb_RefAirspeed_Log = codegenReal2Mission_DW.obj_m.NumCircles;
    } else {
      rtb_Engaged = false;
      rEQ0 = true;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        if ((codegenReal2Mission_DW.obj_m.OrbitCenterInternal[i] ==
             rtb_Heading_Log[i]) || (rtIsNaN
             (codegenReal2Mission_DW.obj_m.OrbitCenterInternal[i]) && rtIsNaN
             (rtb_Heading_Log[i]))) {
          i++;
        } else {
          rEQ0 = false;
          exitg1 = true;
        }
      }

      if (rEQ0) {
        rtb_Engaged = true;
      }

      if ((!rtb_Engaged) || (!(codegenReal2Mission_DW.obj_m.OrbitRadiusInternal ==
            1000.0))) {
        codegenReal2Mission_DW.obj_m.NumCircles = 0.0;
        codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = rtb_Heading_Log[0];
        codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = rtb_Heading_Log[1];
        codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = -150.0;
        codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = 1000.0;
        codegenReal2Mission_DW.obj_m.SelectTurnDirectionFlag = true;
      }

      codegenReal2Mission_DW.obj_m.LookaheadDistance = 100.0;
      distToCenter_tmp[0] = rtb_LowerBound;
      distToCenter_tmp[1] = rtb_RefAirspeed_Log;
      rtb_Switch = std::sqrt(rtb_RefAirspeed_Log * rtb_RefAirspeed_Log +
        rtb_LowerBound * rtb_LowerBound);
      rtb_northSpeed = std::abs(codegenReal2Mission_DW.obj_m.LookaheadDistance +
        1000.0);
      rEQ0 = !rtIsInf(rtb_northSpeed);
      rtb_Engaged = !rtIsNaN(rtb_northSpeed);
      if (rEQ0 && rtb_Engaged) {
        if (rtb_northSpeed <= 2.2250738585072014E-308) {
          rtb_eastSpeed = 4.94065645841247E-324;
        } else {
          frexp(rtb_northSpeed, &b_exponent);
          rtb_eastSpeed = std::ldexp(1.0, b_exponent - 53);
        }
      } else {
        rtb_eastSpeed = (rtNaN);
      }

      guard1 = false;
      if (rtb_Switch >= (codegenReal2Mission_DW.obj_m.LookaheadDistance + 1000.0)
          - 5.0 * rtb_eastSpeed) {
        guard1 = true;
      } else {
        if (rEQ0 && rtb_Engaged) {
          if (rtb_northSpeed <= 2.2250738585072014E-308) {
            rtb_eastSpeed = 4.94065645841247E-324;
          } else {
            frexp(rtb_northSpeed, &b_exponent_0);
            rtb_eastSpeed = std::ldexp(1.0, b_exponent_0 - 53);
          }
        } else {
          rtb_eastSpeed = (rtNaN);
        }

        if (rtb_Switch <= (1000.0 -
                           codegenReal2Mission_DW.obj_m.LookaheadDistance) + 5.0
            * rtb_eastSpeed) {
          guard1 = true;
        } else {
          if (codegenReal2Mission_DW.obj_m.StartFlag) {
            codegenReal2Mission_DW.obj_m.PrevPosition[0] =
              codegenReal2Mission_B.SimUAVStateZOH.North;
            codegenReal2Mission_DW.obj_m.PrevPosition[1] =
              codegenReal2Mission_B.SimUAVStateZOH.East;
            codegenReal2Mission_DW.obj_m.PrevPosition[2] =
              codegenReal2Mission_B.Down;
            codegenReal2Mission_DW.obj_m.StartFlag = false;
          }

          rtb_TmpSignalConversionAtSFun_0[0] = rtb_LowerBound;
          rtb_TmpSignalConversionAtSFun_0[1] = rtb_RefAirspeed_Log;
          d = codegenReal2Mission_norm(rtb_TmpSignalConversionAtSFun_0);
          rtb_Abs1 = codegenReal2Mission_DW.obj_m.LookaheadDistance *
            codegenReal2Mission_DW.obj_m.LookaheadDistance;
          a0 = ((rtb_Abs1 - 1.0E+6) + d * d) / (2.0 * d);
          rtb_eastSpeed = rtb_Heading_Log[0] -
            codegenReal2Mission_B.SimUAVStateZOH.North;
          rtb_northSpeed = rtb_eastSpeed * a0 / d +
            codegenReal2Mission_B.SimUAVStateZOH.North;
          rtb_skySpeed = rtb_Heading_Log[1] -
            codegenReal2Mission_B.SimUAVStateZOH.East;
          rtb_Switch = rtb_skySpeed * a0 / d +
            codegenReal2Mission_B.SimUAVStateZOH.East;
          rtb_Switch_j = std::sqrt(rtb_Abs1 - a0 * a0);
          rtb_Abs1 = rtb_skySpeed * rtb_Switch_j / d;
          distToCenter_tmp[0] = rtb_northSpeed - rtb_Abs1;
          rtb_Switch_j = rtb_eastSpeed * rtb_Switch_j / d;
          rtb_FlightPathAngle_g = rtb_Switch_j + rtb_Switch;
          rtb_RealUAVNEUState[0] = codegenReal2Mission_DW.obj_m.PrevPosition[0]
            - rtb_Heading_Log[0];
          rtb_RealUAVNEUState[1] = codegenReal2Mission_DW.obj_m.PrevPosition[1]
            - rtb_Heading_Log[1];
          rtb_Sum_b[0] = rtb_RealUAVNEUState[0];
          rtb_Sum_b[1] = rtb_RealUAVNEUState[1];
          rtb_Sum_b[2] = 0.0;
          rtb_SwitchLookAheadNED[0] = rtb_LowerBound;
          rtb_SwitchLookAheadNED[1] = rtb_RefAirspeed_Log;
          rtb_SwitchLookAheadNED[2] = 0.0;
          eastSpeed = codegenReal2Mission_norm_b(rtb_Sum_b);
          rtb_AirSpeed_c = codegenReal2Mission_norm_b(rtb_SwitchLookAheadNED);
          a0 = rtb_RealUAVNEUState[0] / eastSpeed;
          rtb_LowerBound /= rtb_AirSpeed_c;
          rtb_ycos_o = rtb_RealUAVNEUState[1] / eastSpeed;
          rtb_RefAirspeed_Log /= rtb_AirSpeed_c;
          rtb_RealUAVNEUState[2] = a0 * rtb_RefAirspeed_Log - rtb_LowerBound *
            rtb_ycos_o;
          codegenReal2Mission_DW.obj_m.PrevPosition[0] =
            codegenReal2Mission_B.SimUAVStateZOH.North;
          codegenReal2Mission_DW.obj_m.PrevPosition[1] =
            codegenReal2Mission_B.SimUAVStateZOH.East;
          codegenReal2Mission_DW.obj_m.PrevPosition[2] =
            codegenReal2Mission_B.Down;
          codegenReal2Mission_DW.obj_m.NumCircles += rt_atan2d_snf
            (rtb_RealUAVNEUState[2], (a0 * rtb_LowerBound + rtb_ycos_o *
              rtb_RefAirspeed_Log) + 0.0 / eastSpeed * (0.0 / rtb_AirSpeed_c)) /
            2.0 / 3.1415926535897931;
          rtb_RefAirspeed_Log = codegenReal2Mission_DW.obj_m.NumCircles;
          rtb_RealUAVNEUState[2] = (distToCenter_tmp[0] -
            codegenReal2Mission_B.SimUAVStateZOH.North) * rtb_skySpeed -
            rtb_eastSpeed * (rtb_FlightPathAngle_g -
                             codegenReal2Mission_B.SimUAVStateZOH.East);
          if (rtb_RealUAVNEUState[2] > 0.0) {
            rtb_eastSpeed = distToCenter_tmp[0];
          } else {
            rtb_eastSpeed = rtb_Abs1 + rtb_northSpeed;
            rtb_FlightPathAngle_g = rtb_Switch - rtb_Switch_j;
          }
        }
      }

      if (guard1) {
        eastSpeed = codegenReal2Mission_norm(distToCenter_tmp);
        rtb_eastSpeed = rtb_LowerBound / eastSpeed * 1000.0 + rtb_Heading_Log[0];
        rtb_FlightPathAngle_g = rtb_RefAirspeed_Log / eastSpeed * 1000.0 +
          rtb_Heading_Log[1];
        rtb_RefAirspeed_Log = codegenReal2Mission_DW.obj_m.NumCircles;
      }

      // MATLABSystem: '<S1>/TakeOffGathering'
      codegenReal2Mission_B.TakeOffGathering_o2 = rt_atan2d_snf
        (rtb_FlightPathAngle_g - codegenReal2Mission_B.SimUAVStateZOH.East,
         rtb_eastSpeed - codegenReal2Mission_B.SimUAVStateZOH.North);
    }

    if ((codegenReal2Mission_DW.obj_m.PrevResetSignal <= 2.2227587494850775E-162)
        && (codegenReal2Mission_B.ExecutionTrigger > 2.2227587494850775E-162)) {
      codegenReal2Mission_DW.obj_m.NumCircles *= 0.0;
    }

    codegenReal2Mission_DW.obj_m.PrevResetSignal =
      codegenReal2Mission_B.ExecutionTrigger;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Chart: '<S1>/ChartExecutionMode' incorporates:
      //   MATLABSystem: '<S1>/TakeOffGathering'

      if (codegenReal2Mission_DW.is_active_c10_codegenReal2Missi == 0U) {
        codegenReal2Mission_DW.is_active_c10_codegenReal2Missi = 1U;
        codegenReal2Mission_DW.is_c10_codegenReal2Mission =
          codegenReal2Mission_IN_Circle;
        codegenReal2Mission_B.Seletion = 0.0;
      } else if (codegenReal2Mission_DW.is_c10_codegenReal2Mission == 1) {
        if ((rtb_RefAirspeed_Log > 3.0) &&
            (codegenReal2Mission_B.ExecutionTrigger != 0.0)) {
          codegenReal2Mission_DW.is_c10_codegenReal2Mission =
            codegenReal2Mission_IN_Flower;
          codegenReal2Mission_B.Seletion = 1.0;
        } else {
          codegenReal2Mission_B.Seletion = 0.0;
        }
      } else {
        // case IN_Flower:
        codegenReal2Mission_B.Seletion = 1.0;
      }

      // End of Chart: '<S1>/ChartExecutionMode'
    }

    // Gain: '<S1>/Down2Height'
    codegenReal2Mission_B.Down2Height = 150.0;
  }

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Matfile logging
    rt_UpdateTXYLogVars((&codegenReal2Mission_M)->rtwLogInfo,
                        ((&codegenReal2Mission_M)->Timing.t));
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    real_T y;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Update for Memory: '<S1>/MemoryFlowerMode'
      codegenReal2Mission_DW.MemoryFlowerMode_PreviousInput =
        codegenReal2Mission_B.Down2Height;

      // Update for Delay: '<S1>/InitHdg'
      codegenReal2Mission_DW.icLoad = false;
      codegenReal2Mission_DW.InitHdg_DSTATE =
        codegenReal2Mission_B.TakeOffGathering_o2;
    }

    // Update for Atomic SubSystem: '<S1>/MissionSimUAV'
    // Update for Integrator: '<S9>/Integrator'
    codegenReal2Mission_DW.Integrator_IWORK = 0;

    // End of Update for SubSystem: '<S1>/MissionSimUAV'

    // Update for Atomic SubSystem: '<Root>/Real2SimGuidance'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Update for Memory: '<S2>/MemoryExecutionTrigger'
      codegenReal2Mission_DW.MemoryExecutionTrigger_Previous =
        codegenReal2Mission_B.BiasHTrigger;

      // Update for Atomic SubSystem: '<S2>/Real2SimNav'
      // Update for Atomic SubSystem: '<S16>/HeadingNaNProtection'
      // Switch: '<S72>/HeightSwitch' incorporates:
      //   Gain: '<S72>/Height2Down'
      //   RelationalOperator: '<S72>/IsNaN'

      if (rtIsNaN(-codegenReal2Mission_B.NorthEastHeight[2])) {
        // Update for Memory: '<S72>/MemoryRefHeight' incorporates:
        //   Constant: '<S72>/DefaultHeight'

        codegenReal2Mission_DW.MemoryRefHeight_PreviousInput = -150.0;
      } else {
        // Update for Memory: '<S72>/MemoryRefHeight'
        codegenReal2Mission_DW.MemoryRefHeight_PreviousInput =
          -codegenReal2Mission_B.NorthEastHeight[2];
      }

      // End of Switch: '<S72>/HeightSwitch'
      // End of Update for SubSystem: '<S16>/HeadingNaNProtection'
      // End of Update for SubSystem: '<S2>/Real2SimNav'
    }

    // Update for Atomic SubSystem: '<S2>/Real2SimNav'
    // Update for Atomic SubSystem: '<S16>/SpeedControl'
    // Update for Atomic SubSystem: '<S75>/ADRC'
    // Update for Enabled SubSystem: '<S79>/ESO' incorporates:
    //   EnablePort: '<S84>/Enable'

    if (codegenReal2Mission_DW.ESO_MODE) {
      // MATLAB Function: '<S84>/fal(e,0.5,h)' incorporates:
      //   Constant: '<S84>/Constant2'
      //   Constant: '<S84>/Constant3'

      codegenReal2Mission_fale025h(codegenReal2Mission_B.SumY, 0.5, 0.1, &y);

      // MATLAB Function: '<S84>/fal(e,0.25,h)' incorporates:
      //   Constant: '<S84>/Constant'
      //   Constant: '<S84>/Constant1'

      codegenReal2Mission_fale025h(codegenReal2Mission_B.SumY, 0.25, 0.1, &y);
    }

    // End of Update for SubSystem: '<S79>/ESO'
    // End of Update for SubSystem: '<S75>/ADRC'
    // End of Update for SubSystem: '<S16>/SpeedControl'
    // End of Update for SubSystem: '<S2>/Real2SimNav'
    // End of Update for SubSystem: '<Root>/Real2SimGuidance'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Update for Memory: '<S1>/MemoryLookAheadP'
      codegenReal2Mission_DW.MemoryLookAheadP_PreviousInput =
        codegenReal2Mission_B.Seletion;
    }

    // ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output 
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&codegenReal2Mission_M)->solverInfo)) {
        rtsiSetSimTimeStep(&(&codegenReal2Mission_M)->solverInfo,MINOR_TIME_STEP);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&codegenReal2Mission_M)->solverInfo, false);
        codegenReal2MissionModelClass::step();
        rtsiSetSimTimeStep(&(&codegenReal2Mission_M)->solverInfo,
                           MAJOR_TIME_STEP);
      }
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // signal main to stop simulation
    {                                  // Sample time: [0.0s, 0.0s]
      if ((rtmGetTFinal((&codegenReal2Mission_M))!=-1) &&
          !((rtmGetTFinal((&codegenReal2Mission_M))-(((&codegenReal2Mission_M)
              ->Timing.clockTick1) * 0.1)) > (((&codegenReal2Mission_M)
             ->Timing.clockTick1) * 0.1) * (DBL_EPSILON))) {
        rtmSetErrorStatus((&codegenReal2Mission_M), "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&(&codegenReal2Mission_M)->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++(&codegenReal2Mission_M)->Timing.clockTick0;
    (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&codegenReal2Mission_M)->solverInfo);

    {
      // Update absolute timer for sample time: [0.1s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.1, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      (&codegenReal2Mission_M)->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void codegenReal2MissionModelClass::codegenReal2Mission_derivatives()
{
  codegenReal2MissionModelClass::XDot_codegenReal2Mission_T *_rtXdot;
  real_T y;
  real_T y_f;
  _rtXdot = ((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs);

  // Derivatives for Atomic SubSystem: '<S1>/MissionSimUAV'
  // Derivatives for Integrator: '<S9>/Integrator' incorporates:
  //   MATLABSystem: '<S9>/ComputeDerivative'

  if (codegenReal2Mission_B.ResetSimUAV == 0.0) {
    std::memcpy(&_rtXdot->Integrator_CSTATE[0],
                &codegenReal2Mission_B.ComputeDerivative[0], sizeof(real_T) <<
                3U);
  } else {
    // level reset is active
    std::memset(&_rtXdot->Integrator_CSTATE[0], 0, sizeof(real_T) << 3U);
  }

  // End of Derivatives for Integrator: '<S9>/Integrator'

  // Derivatives for Integrator: '<S10>/TD_Bank'
  _rtXdot->TD_Bank_CSTATE = codegenReal2Mission_B.dotBankTD;

  // Derivatives for Integrator: '<S10>/dotBankTD'
  _rtXdot->dotBankTD_CSTATE = codegenReal2Mission_B.fh_p;

  // End of Derivatives for SubSystem: '<S1>/MissionSimUAV'

  // Derivatives for Atomic SubSystem: '<Root>/Real2SimGuidance'
  // Derivatives for Atomic SubSystem: '<S2>/Real2SimNav'
  // Derivatives for Atomic SubSystem: '<S16>/SpeedControl'
  // Derivatives for Atomic SubSystem: '<S75>/ADRC'
  // Derivatives for Integrator: '<S86>/TD_AirSpdADRC'
  _rtXdot->TD_AirSpdADRC_CSTATE = codegenReal2Mission_B.dotTD;

  // Derivatives for Enabled SubSystem: '<S79>/ESO'
  if (codegenReal2Mission_DW.ESO_MODE) {
    // MATLAB Function: '<S84>/fal(e,0.5,h)' incorporates:
    //   Constant: '<S84>/Constant2'
    //   Constant: '<S84>/Constant3'

    codegenReal2Mission_fale025h(codegenReal2Mission_B.SumY, 0.5, 0.1, &y);

    // MATLAB Function: '<S84>/fal(e,0.25,h)' incorporates:
    //   Constant: '<S84>/Constant'
    //   Constant: '<S84>/Constant1'

    codegenReal2Mission_fale025h(codegenReal2Mission_B.SumY, 0.25, 0.1, &y_f);

    // Derivatives for Integrator: '<S84>/ESO' incorporates:
    //   Gain: '<S84>/beta_01'
    //   Sum: '<S84>/ESOdotsum'

    _rtXdot->ESO_CSTATE = codegenReal2Mission_B.ESO_dot -
      codegenReal2Mission_B.SumY;

    // Derivatives for Integrator: '<S84>/ESO_dot' incorporates:
    //   Gain: '<S84>/Gain1'
    //   Gain: '<S84>/Gain4'
    //   Sum: '<S84>/ESOdotdotsum'

    _rtXdot->ESO_dot_CSTATE = (2.2372 * codegenReal2Mission_B.GainADRCinvb0 +
      codegenReal2Mission_B.ESO_dotdot) - 1.5811388300841895 * y;

    // Derivatives for Integrator: '<S84>/ESO_dotdot' incorporates:
    //   Gain: '<S84>/Gain'
    //   Gain: '<S84>/Inverse'

    _rtXdot->ESO_dotdot_CSTATE = -(1.2679145539688905 * y_f);
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs)
             ->ESO_CSTATE);
      for (i=0; i < 3; i++) {
        dx[i] = 0.0;
      }
    }
  }

  // End of Derivatives for SubSystem: '<S79>/ESO'

  // Derivatives for Integrator: '<S86>/dotTD'
  _rtXdot->dotTD_CSTATE = codegenReal2Mission_B.fh_g;

  // End of Derivatives for SubSystem: '<S75>/ADRC'
  // End of Derivatives for SubSystem: '<S16>/SpeedControl'

  // Derivatives for Integrator: '<S76>/TD_Alt'
  _rtXdot->TD_Alt_CSTATE = codegenReal2Mission_B.dotAltTD;

  // Derivatives for Integrator: '<S76>/dotAltTD'
  _rtXdot->dotAltTD_CSTATE = codegenReal2Mission_B.fh;

  // End of Derivatives for SubSystem: '<S2>/Real2SimNav'
  // End of Derivatives for SubSystem: '<Root>/Real2SimGuidance'
}

// Model initialize function
void codegenReal2MissionModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&codegenReal2Mission_M)->solverInfo,
                          &(&codegenReal2Mission_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&codegenReal2Mission_M)->solverInfo, &rtmGetTPtr
                ((&codegenReal2Mission_M)));
    rtsiSetStepSizePtr(&(&codegenReal2Mission_M)->solverInfo,
                       &(&codegenReal2Mission_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&codegenReal2Mission_M)->solverInfo, &(&codegenReal2Mission_M)
                 ->derivs);
    rtsiSetContStatesPtr(&(&codegenReal2Mission_M)->solverInfo, (real_T **)
                         &(&codegenReal2Mission_M)->contStates);
    rtsiSetNumContStatesPtr(&(&codegenReal2Mission_M)->solverInfo,
      &(&codegenReal2Mission_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&codegenReal2Mission_M)->solverInfo,
      &(&codegenReal2Mission_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&codegenReal2Mission_M)->solverInfo, &(
      &codegenReal2Mission_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&codegenReal2Mission_M)->solverInfo,
      &(&codegenReal2Mission_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&codegenReal2Mission_M)->solverInfo,
                          (&rtmGetErrorStatus((&codegenReal2Mission_M))));
    rtsiSetRTModelPtr(&(&codegenReal2Mission_M)->solverInfo,
                      (&codegenReal2Mission_M));
  }

  rtsiSetSimTimeStep(&(&codegenReal2Mission_M)->solverInfo, MAJOR_TIME_STEP);
  (&codegenReal2Mission_M)->intgData.y = (&codegenReal2Mission_M)->odeY;
  (&codegenReal2Mission_M)->intgData.f[0] = (&codegenReal2Mission_M)->odeF[0];
  (&codegenReal2Mission_M)->intgData.f[1] = (&codegenReal2Mission_M)->odeF[1];
  (&codegenReal2Mission_M)->intgData.f[2] = (&codegenReal2Mission_M)->odeF[2];
  (&codegenReal2Mission_M)->intgData.f[3] = (&codegenReal2Mission_M)->odeF[3];
  (&codegenReal2Mission_M)->contStates = ((X_codegenReal2Mission_T *)
    &codegenReal2Mission_X);
  rtsiSetSolverData(&(&codegenReal2Mission_M)->solverInfo, static_cast<void *>
                    (&(&codegenReal2Mission_M)->intgData));
  rtsiSetSolverName(&(&codegenReal2Mission_M)->solverInfo,"ode4");
  rtmSetTPtr((&codegenReal2Mission_M), &(&codegenReal2Mission_M)->Timing.tArray
             [0]);
  rtmSetTFinal((&codegenReal2Mission_M), -1);
  (&codegenReal2Mission_M)->Timing.stepSize0 = 0.1;
  rtmSetFirstInitCond((&codegenReal2Mission_M), 1);

  // Setup for data logging
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    (&codegenReal2Mission_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  // Setup for data logging
  {
    rtliSetLogXSignalInfo((&codegenReal2Mission_M)->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs((&codegenReal2Mission_M)->rtwLogInfo, (NULL));
    rtliSetLogT((&codegenReal2Mission_M)->rtwLogInfo, "");
    rtliSetLogX((&codegenReal2Mission_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&codegenReal2Mission_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&codegenReal2Mission_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&codegenReal2Mission_M)->rtwLogInfo, 4);
    rtliSetLogMaxRows((&codegenReal2Mission_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&codegenReal2Mission_M)->rtwLogInfo, 1);
    rtliSetLogY((&codegenReal2Mission_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&codegenReal2Mission_M)->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs((&codegenReal2Mission_M)->rtwLogInfo, (NULL));
  }

  // Matfile logging
  rt_StartDataLoggingWithStartTime((&codegenReal2Mission_M)->rtwLogInfo, 0.0,
    rtmGetTFinal((&codegenReal2Mission_M)), (&codegenReal2Mission_M)
    ->Timing.stepSize0, (&rtmGetErrorStatus((&codegenReal2Mission_M))));

  {
    int32_T i;
    codegenReal2Mission_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

    // InitializeConditions for Memory: '<S1>/MemoryFlowerMode'
    codegenReal2Mission_DW.MemoryFlowerMode_PreviousInput = 50.0;

    // InitializeConditions for Delay: '<S1>/InitHdg'
    codegenReal2Mission_DW.icLoad = true;

    // SystemInitialize for Atomic SubSystem: '<S1>/MissionSimUAV'
    // Start for DataStoreMemory: '<S6>/InitStateSimUAV'
    std::memcpy(&codegenReal2Mission_DW.InitStateSimUAV[0],
                &rtCP_InitStateSimUAV_InitialVal[0], sizeof(real_T) << 3U);

    // InitializeConditions for RateLimiter: '<S6>/ClimbRateLimiter'
    codegenReal2Mission_DW.PrevY = 150.0;

    // InitializeConditions for Integrator: '<S9>/Integrator'
    if (rtmIsFirstInitCond((&codegenReal2Mission_M))) {
      std::memset(&codegenReal2Mission_X.Integrator_CSTATE[0], 0, sizeof(real_T)
                  << 3U);
    }

    codegenReal2Mission_DW.Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S9>/Integrator'

    // InitializeConditions for Integrator: '<S10>/TD_Bank'
    codegenReal2Mission_X.TD_Bank_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S10>/dotBankTD'
    codegenReal2Mission_X.dotBankTD_CSTATE = 0.0;

    // Start for MATLABSystem: '<S9>/ComputeDerivative'
    codegenReal2Mission_DW.obj_c.isInitialized = 1;
    codegenReal2Mis_Model_resetImpl(&codegenReal2Mission_DW.obj_c);

    // InitializeConditions for MATLABSystem: '<S9>/ComputeDerivative'
    codegenReal2Mis_Model_resetImpl(&codegenReal2Mission_DW.obj_c);

    // End of SystemInitialize for SubSystem: '<S1>/MissionSimUAV'

    // SystemInitialize for Atomic SubSystem: '<Root>/Real2SimGuidance'
    // SetupRuntimeResources for Scope: '<S2>/ModelLogging' incorporates:
    //   Inport: '<Root>/Altitude'
    //   Inport: '<Root>/GroundSpd'

    {
      RTWLogSignalInfo rt_ScopeSignalInfo;
      static int_T rt_ScopeSignalWidths[] = { 8, 8, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1,
        1, 3, 1, 1 };

      static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1, 1, 2, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1 };

      static int_T rt_ScopeSignalDimensions[] = { 8, 8, 1, 1, 3, 1, 1, 1, 3, 1,
        1, 1, 1, 1, 3, 1, 1 };

      static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL), (NULL),
        (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL),
        (NULL), (NULL), (NULL), (NULL) };

      static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4 };

      static const char_T *rt_ScopeSignalLabels[] = { "RealUAVState_Log",
        "SimUAVState_Log",
        "RefAirspeed_Log",
        "LagDistance_Log",
        "LookAheadNED_Log",
        "CrossTrackError_Log",
        "EngagedFlag_Log",
        "Heading_Log",
        "ADRC_U_Log",
        "biasH_Log",
        "GroundSpeed_Log",
        "FlightMode_Log",
        "Status_Log",
        "VectorSpd_Log",
        "Altitude_Log",
        "FlightPath" };

      static char_T rt_ScopeSignalTitles[] =
        "RealUAVState_LogSimUAVState_LogRefAirspeed_LogLagDistance_LogLookAheadNED_LogCrossTrackError_LogEngagedFlag_LogHeading_LogADRC_U_LogbiasH_LogGroundSpeed_LogFlightMode_LogStatus_LogVectorSpd_LogAltitude_LogFlightPath";
      static int_T rt_ScopeSignalTitleLengths[] = { 16, 15, 15, 15, 16, 19, 15,
        11, 10, 9, 15, 14, 10, 13, 12, 10 };

      static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0 };

      static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1 };

      BuiltInDTypeId dTypes[16] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE,
        SS_DOUBLE, SS_DOUBLE, SS_BOOLEAN, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE,
        SS_DOUBLE, SS_UINT8, SS_UINT8, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

      static char_T rt_ScopeBlockName[] =
        "codegenReal2Mission/Real2SimGuidance/ModelLogging";
      static int_T rt_ScopeFrameData[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0 };

      static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
        (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL),
        (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL)
      };

      rt_ScopeSignalInfo.numSignals = 16;
      rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
      rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
      rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
      rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
      rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
      rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
      rt_ScopeSignalInfo.dataTypes = dTypes;
      rt_ScopeSignalInfo.complexSignals = (NULL);
      rt_ScopeSignalInfo.frameData = rt_ScopeFrameData;
      rt_ScopeSignalInfo.preprocessingPtrs =
        rt_ScopeSignalLoggingPreprocessingFcnPtrs;
      rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
      rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
      rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
      rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
      rt_ScopeSignalInfo.blockNames.cptr = (NULL);
      rt_ScopeSignalInfo.stateNames.cptr = (NULL);
      rt_ScopeSignalInfo.crossMdlRef = (NULL);
      rt_ScopeSignalInfo.dataTypeConvert = (NULL);
      codegenReal2Mission_DW.ModelLogging_PWORK.LoggedData[0] =
        rt_CreateStructLogVar(
        (&codegenReal2Mission_M)->rtwLogInfo,
        0.0,
        rtmGetTFinal((&codegenReal2Mission_M)),
        (&codegenReal2Mission_M)->Timing.stepSize0,
        (&rtmGetErrorStatus((&codegenReal2Mission_M))),
        "ScopeData",
        1,
        0,
        1,
        0.1,
        &rt_ScopeSignalInfo,
        rt_ScopeBlockName);
      if (codegenReal2Mission_DW.ModelLogging_PWORK.LoggedData[0] == (NULL))
        return;
    }

    // SystemInitialize for Atomic SubSystem: '<S2>/Real2SimNav'
    // InitializeConditions for Integrator: '<S76>/TD_Alt'
    codegenReal2Mission_X.TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S76>/dotAltTD'
    codegenReal2Mission_X.dotAltTD_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<S16>/GenerateTrack'
    for (i = 0; i < 72; i++) {
      // InitializeConditions for S-Function (sfix_udelay): '<S70>/HeightSequence' 
      codegenReal2Mission_DW.HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<S16>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<S16>/SpeedControl'
    // SystemInitialize for Atomic SubSystem: '<S75>/ADRC'
    // InitializeConditions for Integrator: '<S86>/TD_AirSpdADRC'
    codegenReal2Mission_X.TD_AirSpdADRC_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S86>/dotTD'
    codegenReal2Mission_X.dotTD_CSTATE = 0.0;

    // SystemInitialize for Enabled SubSystem: '<S79>/ESO'
    // InitializeConditions for Integrator: '<S84>/ESO'
    codegenReal2Mission_X.ESO_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S84>/ESO_dot'
    codegenReal2Mission_X.ESO_dot_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S84>/ESO_dotdot'
    codegenReal2Mission_X.ESO_dotdot_CSTATE = 0.0;

    // End of SystemInitialize for SubSystem: '<S79>/ESO'
    // End of SystemInitialize for SubSystem: '<S75>/ADRC'
    // End of SystemInitialize for SubSystem: '<S16>/SpeedControl'

    // SystemInitialize for Atomic SubSystem: '<S16>/HeadingLogic'
    // Start for MATLABSystem: '<S71>/TrackSimPath'
    codegenReal2Mission_DW.obj.LastWaypointFlag = false;
    codegenReal2Mission_DW.obj.StartFlag = true;
    codegenReal2Mission_DW.obj.LookaheadFactor = 1.01;
    codegenReal2Mission_DW.obj.SearchFlag = true;
    codegenReal2Mission_DW.obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S71>/TrackSimPath'
    codegenReal2Mission_DW.obj.WaypointIndex = 1.0;
    for (i = 0; i < 219; i++) {
      // Start for MATLABSystem: '<S71>/TrackSimPath'
      codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);

      // InitializeConditions for MATLABSystem: '<S71>/TrackSimPath'
      codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S16>/HeadingLogic'
    // End of SystemInitialize for SubSystem: '<S2>/Real2SimNav'
    // End of SystemInitialize for SubSystem: '<Root>/Real2SimGuidance'

    // Start for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.isInitialized = 1;
    codegenReal2Mission_DW.obj_m.PrevResetSignal = 0.0;
    codegenReal2Mission_DW.obj_m.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevResetSignal *= 0.0;
    codegenReal2Mission_DW.obj_m.NumCircles *= 0.0;

    // Start for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[0] = 0.0;

    // InitializeConditions for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[0] *= 0.0;

    // Start for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[1] = 0.0;

    // InitializeConditions for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[1] *= 0.0;

    // Start for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[2] = 0.0;

    // InitializeConditions for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[2] *= 0.0;
    codegenReal2Mission_DW.obj_m.StartFlag = true;
    codegenReal2Mission_DW.obj_m.SelectTurnDirectionFlag = true;
    codegenReal2Mission_DW.obj_m.TurnDirectionInternal = 1.0;
    codegenReal2Mission_DW.obj_m.OrbitRadiusFlag = 0U;
    codegenReal2Mission_DW.obj_m.LookaheadDistFlag = 0U;
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond((&codegenReal2Mission_M))) {
    rtmSetFirstInitCond((&codegenReal2Mission_M), 0);
  }
}

// Model terminate function
void codegenReal2MissionModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
codegenReal2MissionModelClass::codegenReal2MissionModelClass() :
  codegenReal2Mission_B(),
  codegenReal2Mission_DW(),
  codegenReal2Mission_X(),
  codegenReal2Mission_PrevZCX(),
  codegenReal2Mission_U(),
  codegenReal2Mission_Y(),
  codegenReal2Mission_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
codegenReal2MissionModelClass::~codegenReal2MissionModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
codegenReal2MissionModelClass::RT_MODEL_codegenReal2Mission_T
  * codegenReal2MissionModelClass::getRTM()
{
  return (&codegenReal2Mission_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
