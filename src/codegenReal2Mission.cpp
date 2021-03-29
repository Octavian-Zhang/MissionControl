//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.239
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 29 11:17:03 2021
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

// Named constants for Chart: '<S2>/TASgreaterthan15for1Sec'
const uint8_T codegenReal2Missi_IN_NotTakeOff = 2U;
const uint8_T codegenReal2Mission_IN_InAir = 1U;

// Named constants for Chart: '<S2>/TriggerTermination'
const uint8_T codegenRea_IN_MissionCompletion = 2U;
const uint8_T codegenReal2M_IN_InitialPersuit = 1U;
const uint8_T codegenReal_IN_MissionExecution = 3U;

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
//    '<S9>/fhan_Bank'
//    '<S18>/fhan_Alt'
//
void codegenReal2MissionModelClass::codegenReal2Mission_fhan_Bank(real_T rtu_u,
  real_T rtu_u_n, real_T rtu_u_f, real_T rtu_u_c, real_T *rty_fh)
{
  real_T a0;
  real_T a2;
  real_T d;
  real_T u;
  real_T y;
  real_T y_0;

  // SignalConversion generated from: '<S10>/ SFunction '
  d = rtu_u_f * rtu_u_c * rtu_u_c;
  a0 = rtu_u_n * rtu_u_c;
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

  a2 = (std::sqrt((8.0 * std::abs(y) + d) * d) - d) * y_0 / 2.0 + a0;
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

  a0 = ((a0 + y) - a2) * ((y_0 - u) / 2.0) + a2;
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

  // SignalConversion generated from: '<S10>/ SFunction '
  *rty_fh = (a0 / d - y) * -rtu_u_f * ((y_0 - u) / 2.0) - rtu_u_f * y;
}

//
// Output and update for atomic system:
//    '<S75>/fal(e,0.25,h)'
//    '<S75>/fal(e,0.5,h)'
//
void codegenReal2MissionModelClass::codegenReal2Mission_fale025h(real_T rtu_u,
  real_T rtu_u_g, real_T rtu_u_d, real_T *rty_y)
{
  real_T rtu_u_0;
  real_T tmp;

  // SignalConversion generated from: '<S78>/ SFunction '
  tmp = std::abs(rtu_u);
  if (tmp <= rtu_u_d) {
    *rty_y = rtu_u / rt_powd_snf(rtu_u_d, 1.0 - rtu_u_g);
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

    *rty_y = rt_powd_snf(tmp, rtu_u_g) * rtu_u_0;
  }

  // End of SignalConversion generated from: '<S78>/ SFunction '
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
  obj->ModelImpl.Configuration.PHeight = 1.17;
  obj->ModelImpl.Configuration.PFlightPathAngle = 11.7;
  obj->ModelImpl.Configuration.PAirSpeed = 0.30000000000000004;
  obj->ModelImpl.Configuration.PDRoll[0] = 3402.9722249999991;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -1.5707963267948966;
  obj->ModelImpl.Configuration.PDRoll[0] = 100.0;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -1.5707963267948966;
  obj->ModelImpl.Configuration.PDRoll[1] = 116.66999999999999;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 1.5707963267948966;
  obj->ModelImpl.Configuration.PDRoll[1] = 10.0;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 1.5707963267948966;
}

// Model step function
void codegenReal2MissionModelClass::step()
{
  // local block i/o variables
  real_T rtb_Down;
  real_T rtb_MatrixConcatenate[219];
  real_T rtb_FixedWingGuidanceStateBus_0[4];
  real_T rtb_Sum_dv[3];
  real_T rtb_Sum_np[3];
  real_T distToCenter_tmp[2];
  real_T rtb_TmpSignalConversionAtSFun_0[2];
  real_T Gain;
  real_T Vg;
  real_T a2;
  real_T d;
  real_T q;
  real_T rtb_Abs1_n;
  real_T rtb_AirSpeed;
  real_T rtb_AirSpeed_c;
  real_T rtb_AirSpeed_l;
  real_T rtb_Down_a;
  real_T rtb_East;
  real_T rtb_East_p;
  real_T rtb_FixedWingGuidanceStateBus_E;
  real_T rtb_FixedWingGuidanceStateBus_N;
  real_T rtb_FlightPathAngle;
  real_T rtb_FlightPathAngle_g;
  real_T rtb_HeadingAngle;
  real_T rtb_HeadingAngle_e;
  real_T rtb_Height;
  real_T rtb_Height_n;
  real_T rtb_LookAheadPoint_Height_meter;
  real_T rtb_LowerBound;
  real_T rtb_MemoryLookAheadP;
  real_T rtb_North;
  real_T rtb_Output;
  real_T rtb_RollAngleRate;
  real_T rtb_RollAngle_i;
  real_T rtb_SpeedProtection;
  real_T rtb_Sum_c;
  real_T rtb_Sum_nn;
  real_T rtb_Switch_e;
  real_T rtb_Switch_n;
  real_T rtb_TD_AirSpdADRC;
  real_T rtb_TargetHDG_Rad;
  real_T rtb_TargetHdg_Log;
  real_T rtb_TrackSimPath_o5;
  real_T rtb_UpperBound;
  real_T rtb_ZOH_ADRC_LagDis;
  real_T rtb_ZOH_ADRC_U;
  real_T rtb_ycos_k;
  real_T y;
  real_T y_0;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T i;
  uint8_T lookaheadFlag;
  uint8_T status;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T rEQ0;
  boolean_T rtb_Engaged;
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

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Memory: '<S1>/MemoryFlowerMode'
    rtb_East_p = codegenReal2Mission_DW.MemoryFlowerMode_PreviousInput;

    // DataTypeConversion: '<S1>/Cast To Double' incorporates:
    //   DataStoreRead: '<S1>/UAVidx'

    rtb_MemoryLookAheadP = codegenReal2Mission_DW.UAVidx;

    // Delay: '<S1>/InitHdg'
    if (codegenReal2Mission_DW.icLoad) {
      // BusCreator: '<S1>/Bus Creator' incorporates:
      //   Bias: '<S1>/Bias'
      //   Bias: '<S1>/Rotate90Deg'
      //   Constant: '<S1>/2pi'
      //   DataStoreRead: '<S1>/numMissionUAV'
      //   Gain: '<S1>/FindMiddle'
      //   Product: '<S1>/Divide'
      //   Product: '<S1>/Map2Radian'
      //   Sum: '<S1>/Minus'

      codegenReal2Mission_DW.InitHdg_DSTATE = (rtb_MemoryLookAheadP -
        (codegenReal2Mission_DW.numMissionUAV + 1.0) * 0.5) *
        (6.2831853071795862 / codegenReal2Mission_DW.numMissionUAV) +
        1.5707963267948966;
    }

    // End of Delay: '<S1>/InitHdg'

    // Outputs for Atomic SubSystem: '<S1>/MissionSimUAV'
    // Saturate: '<S4>/AirspeedSaturation' incorporates:
    //   BusCreator: '<S1>/Bus Creator'
    //   Constant: '<S1>/MissionAirspeed'

    codegenReal2Mission_B.Airspeed = 35.0;

    // Saturate: '<S4>/AltitudeSaturation' incorporates:
    //   BusCreator: '<S1>/Bus Creator'

    if (rtb_East_p > 500.0) {
      rtb_Sum_nn = 500.0;
    } else if (rtb_East_p < 100.0) {
      rtb_Sum_nn = 100.0;
    } else {
      rtb_Sum_nn = rtb_East_p;
    }

    // End of Saturate: '<S4>/AltitudeSaturation'

    // RateLimiter: '<S4>/ClimbRateLimiter'
    rtb_TD_AirSpdADRC = rtb_Sum_nn - codegenReal2Mission_DW.PrevY;
    if (rtb_TD_AirSpdADRC > 0.5) {
      // RateLimiter: '<S4>/ClimbRateLimiter'
      codegenReal2Mission_B.ClimbRateLimiter = codegenReal2Mission_DW.PrevY +
        0.5;
    } else if (rtb_TD_AirSpdADRC < -0.5) {
      // RateLimiter: '<S4>/ClimbRateLimiter'
      codegenReal2Mission_B.ClimbRateLimiter = codegenReal2Mission_DW.PrevY +
        -0.5;
    } else {
      // RateLimiter: '<S4>/ClimbRateLimiter'
      codegenReal2Mission_B.ClimbRateLimiter = rtb_Sum_nn;
    }

    codegenReal2Mission_DW.PrevY = codegenReal2Mission_B.ClimbRateLimiter;

    // End of RateLimiter: '<S4>/ClimbRateLimiter'

    // BusCreator: '<S4>/FixedWingGuidanceEnvironmentBus' incorporates:
    //   Constant: '<S4>/Gravity'
    //   Constant: '<S4>/NoWind'

    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth = 0.0;
    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast = 0.0;
    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown = 0.0;
    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity = 9.807;

    // End of Outputs for SubSystem: '<S1>/MissionSimUAV'
  }

  // Outputs for Atomic SubSystem: '<S1>/MissionSimUAV'
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // MATLAB Function: '<S4>/SimHeadingControl' incorporates:
    //   BusCreator: '<S1>/Bus Creator'
    //   Integrator: '<S8>/Integrator'

    rtb_Sum_nn = 1.0 / codegenReal2Mission_X.Integrator_CSTATE[3];
    rtb_TD_AirSpdADRC = std::cos(codegenReal2Mission_X.Integrator_CSTATE[5]);
    rtb_Output = std::sin(codegenReal2Mission_X.Integrator_CSTATE[4]);
    Vg = std::cos(codegenReal2Mission_X.Integrator_CSTATE[4]);
    rtb_TD_AirSpdADRC = (Vg * rtb_TD_AirSpdADRC *
                         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth
                         + rtb_Output * rtb_TD_AirSpdADRC *
                         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast)
      + -std::sin(codegenReal2Mission_X.Integrator_CSTATE[5]) *
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown;
    d = codegenReal2Mission_DW.InitHdg_DSTATE -
      codegenReal2Mission_X.Integrator_CSTATE[4];
    if (std::abs(d) > 3.1415926535897931) {
      if (rtIsNaN(d + 3.1415926535897931)) {
        Gain = (rtNaN);
      } else if (rtIsInf(d + 3.1415926535897931)) {
        Gain = (rtNaN);
      } else if (d + 3.1415926535897931 == 0.0) {
        Gain = 0.0;
      } else {
        Gain = std::fmod(d + 3.1415926535897931, 6.2831853071795862);
        rEQ0 = (Gain == 0.0);
        if (!rEQ0) {
          q = std::abs((d + 3.1415926535897931) / 6.2831853071795862);
          rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 *
                   q);
        }

        if (rEQ0) {
          Gain = 0.0;
        } else if (d + 3.1415926535897931 < 0.0) {
          Gain += 6.2831853071795862;
        }
      }

      if ((Gain == 0.0) && (d + 3.1415926535897931 > 0.0)) {
        Gain = 6.2831853071795862;
      }

      d = Gain - 3.1415926535897931;
    }

    codegenReal2Mission_B.RollAngle = rt_atan2d_snf((std::sqrt(rtb_TD_AirSpdADRC
      * rtb_TD_AirSpdADRC -
      (((codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth *
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth +
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast *
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast) +
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown) -
       codegenReal2Mission_X.Integrator_CSTATE[3] *
       codegenReal2Mission_X.Integrator_CSTATE[3])) + -rtb_TD_AirSpdADRC) *
      (0.39 * d), std::cos(codegenReal2Mission_X.Integrator_CSTATE[4] -
      (codegenReal2Mission_X.Integrator_CSTATE[4] - std::asin(rtb_Sum_nn *
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth *
      -rtb_Output + rtb_Sum_nn *
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast * Vg))) *
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity);

    // Saturate: '<S4>/RollAngleSaturation'
    if (codegenReal2Mission_B.RollAngle > 0.3490658503988659) {
      // MATLAB Function: '<S4>/SimHeadingControl' incorporates:
      //   Saturate: '<S4>/RollAngleSaturation'

      codegenReal2Mission_B.RollAngle = 0.3490658503988659;
    } else if (codegenReal2Mission_B.RollAngle < -0.3490658503988659) {
      // MATLAB Function: '<S4>/SimHeadingControl' incorporates:
      //   Saturate: '<S4>/RollAngleSaturation'

      codegenReal2Mission_B.RollAngle = -0.3490658503988659;
    }

    // End of Saturate: '<S4>/RollAngleSaturation'
  }

  // MATLABSystem: '<S8>/ComputeDerivative' incorporates:
  //   BusCreator: '<S4>/Slew Guidance Bus'
  //   Integrator: '<S8>/Integrator'
  //   Integrator: '<S9>/TD_Bank'

  rtb_Sum_nn = std::cos(codegenReal2Mission_X.Integrator_CSTATE[5]);
  rtb_TD_AirSpdADRC = std::cos(codegenReal2Mission_X.Integrator_CSTATE[4]);
  rtb_Output = std::sin(codegenReal2Mission_X.Integrator_CSTATE[4]);
  d = std::sin(codegenReal2Mission_X.Integrator_CSTATE[5]);
  Vg = (-(rtb_TD_AirSpdADRC * rtb_Sum_nn) *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth +
        -(rtb_Output * rtb_Sum_nn) *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast) + d *
    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown;
  Vg = std::sqrt(Vg * Vg -
                 (((codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth
                    * codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth
                    + codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast
                    * codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast)
                   + codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown
                   * codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown)
                  - codegenReal2Mission_X.Integrator_CSTATE[3] *
                  codegenReal2Mission_X.Integrator_CSTATE[3])) + -Vg;
  codegenReal2Mission_B.ComputeDerivative[0] = Vg * rtb_TD_AirSpdADRC *
    rtb_Sum_nn;
  codegenReal2Mission_B.ComputeDerivative[1] = Vg * rtb_Output * rtb_Sum_nn;
  codegenReal2Mission_B.ComputeDerivative[2] = Vg * d;
  codegenReal2Mission_B.ComputeDerivative[3] = (codegenReal2Mission_B.Airspeed -
    codegenReal2Mission_X.Integrator_CSTATE[3]) *
    codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PAirSpeed;
  if (Vg == 0.0) {
    codegenReal2Mission_B.ComputeDerivative[4] = 0.0;
    codegenReal2Mission_B.ComputeDerivative[5] = 0.0;
  } else {
    if (codegenReal2Mission_X.Integrator_CSTATE[3] == 0.0) {
      codegenReal2Mission_B.ComputeDerivative[4] = 0.0;
    } else {
      rtb_Sum_nn = 1.0 / (std::cos(std::asin((Vg * d +
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown) /
        codegenReal2Mission_X.Integrator_CSTATE[3])) *
                          codegenReal2Mission_X.Integrator_CSTATE[3]);
      codegenReal2Mission_B.ComputeDerivative[4] = std::cos(std::asin(rtb_Sum_nn
        * codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth *
        -rtb_Output + rtb_Sum_nn *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast *
        rtb_TD_AirSpdADRC)) *
        (codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity / Vg *
         std::tan(codegenReal2Mission_X.Integrator_CSTATE[6]));
    }

    rtb_Sum_nn = (codegenReal2Mission_B.ClimbRateLimiter -
                  codegenReal2Mission_X.Integrator_CSTATE[2]) *
      codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PHeight / Vg;
    if (!(rtb_Sum_nn < 1.0)) {
      rtb_Sum_nn = 1.0;
    }

    if (!(rtb_Sum_nn > -1.0)) {
      rtb_Sum_nn = -1.0;
    }

    rtb_Sum_nn = std::asin(rtb_Sum_nn);
    if ((!(rtb_Sum_nn <
           codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
           [1])) && (!rtIsNaN
                     (codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
                      [1]))) {
      rtb_Sum_nn =
        codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
        [1];
    }

    if ((!(rtb_Sum_nn >
           codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
           [0])) && (!rtIsNaN
                     (codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
                      [0]))) {
      rtb_Sum_nn =
        codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
        [0];
    }

    codegenReal2Mission_B.ComputeDerivative[5] = (rtb_Sum_nn -
      codegenReal2Mission_X.Integrator_CSTATE[5]) *
      codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PFlightPathAngle;
  }

  codegenReal2Mission_B.ComputeDerivative[6] =
    codegenReal2Mission_X.Integrator_CSTATE[7];
  if (codegenReal2Mission_X.TD_Bank_CSTATE < 1.5707963267948966) {
    rtb_Sum_nn = codegenReal2Mission_X.TD_Bank_CSTATE;
  } else {
    rtb_Sum_nn = 1.5707963267948966;
  }

  if (!(rtb_Sum_nn > -1.5707963267948966)) {
    rtb_Sum_nn = -1.5707963267948966;
  }

  codegenReal2Mission_B.ComputeDerivative[7] = (rtb_Sum_nn -
    codegenReal2Mission_X.Integrator_CSTATE[6]) *
    codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PDRoll[0] +
    codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PDRoll[1] *
    -codegenReal2Mission_X.Integrator_CSTATE[7];

  // End of MATLABSystem: '<S8>/ComputeDerivative'
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // ZeroOrderHold: '<S4>/SimUAVStateZOH' incorporates:
    //   Integrator: '<S8>/Integrator'

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

  // Integrator: '<S9>/dotBankTD'
  codegenReal2Mission_B.dotBankTD = codegenReal2Mission_X.dotBankTD_CSTATE;

  // MATLAB Function: '<S9>/fhan_Bank' incorporates:
  //   Constant: '<S9>/Constant2'
  //   Constant: '<S9>/Constant3'
  //   Integrator: '<S9>/TD_Bank'
  //   Sum: '<S9>/Sum1'

  codegenReal2Mission_fhan_Bank(codegenReal2Mission_X.TD_Bank_CSTATE -
    codegenReal2Mission_B.RollAngle, codegenReal2Mission_B.dotBankTD,
    0.087266462599716474, 0.1, &codegenReal2Mission_B.fh_n4);

  // End of Outputs for SubSystem: '<S1>/MissionSimUAV'

  // Outputs for Atomic SubSystem: '<Root>/Real2SimGuidance'
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Outputs for Atomic SubSystem: '<S2>/LatLon2NorthEast'
    // Abs: '<S38>/Abs' incorporates:
    //   DataStoreRead: '<S14>/LatitudeGCS'

    rtb_Switch_e = std::abs(codegenReal2Mission_DW.LatitudeGCS);

    // Switch: '<S38>/Switch' incorporates:
    //   Bias: '<S38>/Bias'
    //   Bias: '<S38>/Bias1'
    //   Constant: '<S38>/Constant2'
    //   Constant: '<S39>/Constant'
    //   DataStoreRead: '<S14>/LatitudeGCS'
    //   Math: '<S38>/Math Function1'
    //   RelationalOperator: '<S39>/Compare'

    if (rtb_Switch_e > 180.0) {
      rtb_Switch_e = rt_modd_snf(codegenReal2Mission_DW.LatitudeGCS + 180.0,
        360.0) + -180.0;
    } else {
      rtb_Switch_e = codegenReal2Mission_DW.LatitudeGCS;
    }

    // End of Switch: '<S38>/Switch'

    // Abs: '<S35>/Abs1'
    rtb_Abs1_n = std::abs(rtb_Switch_e);

    // Switch: '<S35>/Switch' incorporates:
    //   Bias: '<S35>/Bias'
    //   Bias: '<S35>/Bias1'
    //   Constant: '<S26>/Constant'
    //   Constant: '<S26>/Constant1'
    //   Constant: '<S37>/Constant'
    //   Gain: '<S35>/Gain'
    //   Product: '<S35>/Divide1'
    //   RelationalOperator: '<S37>/Compare'
    //   Switch: '<S26>/Switch1'

    if (rtb_Abs1_n > 90.0) {
      // Signum: '<S35>/Sign1'
      if (rtb_Switch_e < 0.0) {
        rtb_Switch_e = -1.0;
      } else if (rtb_Switch_e > 0.0) {
        rtb_Switch_e = 1.0;
      } else if (rtb_Switch_e == 0.0) {
        rtb_Switch_e = 0.0;
      } else {
        rtb_Switch_e = (rtNaN);
      }

      // End of Signum: '<S35>/Sign1'
      rtb_Switch_e *= -(rtb_Abs1_n + -90.0) + 90.0;
      rtb_Abs1_n = 180.0;
    } else {
      rtb_Abs1_n = 0.0;
    }

    // End of Switch: '<S35>/Switch'

    // Sum: '<S26>/Sum' incorporates:
    //   DataStoreRead: '<S14>/LongitudeGCS'

    rtb_East_p = rtb_Abs1_n + codegenReal2Mission_DW.LongitudeGCS;

    // Abs: '<S36>/Abs'
    rtb_Abs1_n = std::abs(rtb_East_p);

    // Switch: '<S36>/Switch' incorporates:
    //   Bias: '<S36>/Bias'
    //   Bias: '<S36>/Bias1'
    //   Constant: '<S36>/Constant2'
    //   Constant: '<S40>/Constant'
    //   Math: '<S36>/Math Function1'
    //   RelationalOperator: '<S40>/Compare'

    if (rtb_Abs1_n > 180.0) {
      rtb_East_p = rt_modd_snf(rtb_East_p + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S36>/Switch'

    // Sum: '<S24>/Sum1' incorporates:
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_MemoryLookAheadP = codegenReal2Mission_U.RealUAVLatLonState.Latitude_deg
      - rtb_Switch_e;

    // Abs: '<S32>/Abs'
    rtb_Abs1_n = std::abs(rtb_MemoryLookAheadP);

    // Switch: '<S32>/Switch' incorporates:
    //   Bias: '<S32>/Bias'
    //   Bias: '<S32>/Bias1'
    //   Constant: '<S32>/Constant2'
    //   Constant: '<S33>/Constant'
    //   Math: '<S32>/Math Function1'
    //   RelationalOperator: '<S33>/Compare'

    if (rtb_Abs1_n > 180.0) {
      rtb_MemoryLookAheadP = rt_modd_snf(rtb_MemoryLookAheadP + 180.0, 360.0) +
        -180.0;
    }

    // End of Switch: '<S32>/Switch'

    // Abs: '<S29>/Abs1'
    rtb_Abs1_n = std::abs(rtb_MemoryLookAheadP);

    // Switch: '<S29>/Switch' incorporates:
    //   Bias: '<S29>/Bias'
    //   Bias: '<S29>/Bias1'
    //   Constant: '<S25>/Constant'
    //   Constant: '<S25>/Constant1'
    //   Constant: '<S31>/Constant'
    //   Gain: '<S29>/Gain'
    //   Product: '<S29>/Divide1'
    //   RelationalOperator: '<S31>/Compare'
    //   Switch: '<S25>/Switch1'

    if (rtb_Abs1_n > 90.0) {
      // Signum: '<S29>/Sign1'
      if (rtb_MemoryLookAheadP < 0.0) {
        rtb_FlightPathAngle_g = -1.0;
      } else if (rtb_MemoryLookAheadP > 0.0) {
        rtb_FlightPathAngle_g = 1.0;
      } else if (rtb_MemoryLookAheadP == 0.0) {
        rtb_FlightPathAngle_g = 0.0;
      } else {
        rtb_FlightPathAngle_g = (rtNaN);
      }

      // End of Signum: '<S29>/Sign1'
      rtb_Abs1_n = (-(rtb_Abs1_n + -90.0) + 90.0) * rtb_FlightPathAngle_g;
      rtb_FlightPathAngle_g = 180.0;
    } else {
      rtb_Abs1_n = rtb_MemoryLookAheadP;
      rtb_FlightPathAngle_g = 0.0;
    }

    // End of Switch: '<S29>/Switch'

    // Sum: '<S25>/Sum' incorporates:
    //   Inport: '<Root>/RealUAVLatLonState'
    //   Sum: '<S24>/Sum1'

    rtb_East_p = (codegenReal2Mission_U.RealUAVLatLonState.Longitude_deg -
                  rtb_East_p) + rtb_FlightPathAngle_g;

    // Abs: '<S30>/Abs'
    rtb_FlightPathAngle_g = std::abs(rtb_East_p);

    // Switch: '<S30>/Switch' incorporates:
    //   Bias: '<S30>/Bias'
    //   Bias: '<S30>/Bias1'
    //   Constant: '<S30>/Constant2'
    //   Constant: '<S34>/Constant'
    //   Math: '<S30>/Math Function1'
    //   RelationalOperator: '<S34>/Compare'

    if (rtb_FlightPathAngle_g > 180.0) {
      rtb_East_p = rt_modd_snf(rtb_East_p + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S30>/Switch'

    // UnitConversion: '<S28>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_MemoryLookAheadP = 0.017453292519943295 * rtb_Abs1_n;

    // UnitConversion: '<S43>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Switch_e *= 0.017453292519943295;

    // Trigonometry: '<S44>/Trigonometric Function1'
    rtb_Abs1_n = std::sin(rtb_Switch_e);

    // Sum: '<S44>/Sum1' incorporates:
    //   Constant: '<S44>/Constant'
    //   Product: '<S44>/Product1'

    rtb_Abs1_n = 1.0 - codegenReal2Mission_ConstB.sqrt_g *
      codegenReal2Mission_ConstB.sqrt_g * rtb_Abs1_n * rtb_Abs1_n;

    // Sqrt: '<S42>/sqrt'
    rtb_FlightPathAngle_g = std::sqrt(rtb_Abs1_n);

    // Product: '<S42>/Product1' incorporates:
    //   Constant: '<S42>/Constant1'

    rtb_FlightPathAngle_g = 6.378137E+6 / rtb_FlightPathAngle_g;

    // Product: '<S27>/dNorth' incorporates:
    //   Constant: '<S42>/Constant2'
    //   Product: '<S42>/Product3'
    //   Trigonometry: '<S42>/Trigonometric Function1'

    rtb_Abs1_n = rtb_MemoryLookAheadP / rt_atan2d_snf(1.0, rtb_FlightPathAngle_g
      * codegenReal2Mission_ConstB.Sum1_e / rtb_Abs1_n);

    // Product: '<S27>/dEast' incorporates:
    //   Constant: '<S42>/Constant3'
    //   Product: '<S42>/Product4'
    //   Trigonometry: '<S42>/Trigonometric Function'
    //   Trigonometry: '<S42>/Trigonometric Function2'
    //   UnitConversion: '<S28>/Unit Conversion'

    rtb_Switch_e = 1.0 / rt_atan2d_snf(1.0, rtb_FlightPathAngle_g * std::cos
      (rtb_Switch_e)) * (0.017453292519943295 * rtb_East_p);

    // Sum: '<S27>/Sum2' incorporates:
    //   Product: '<S27>/x*cos'
    //   Product: '<S27>/y*sin'

    rtb_FlightPathAngle_g = rtb_Abs1_n * codegenReal2Mission_ConstB.SinCos_o2_c
      + rtb_Switch_e * codegenReal2Mission_ConstB.SinCos_o1_h;

    // Sum: '<S27>/Sum3' incorporates:
    //   Product: '<S27>/x*sin'
    //   Product: '<S27>/y*cos'

    rtb_Switch_e = rtb_Switch_e * codegenReal2Mission_ConstB.SinCos_o2_c -
      rtb_Abs1_n * codegenReal2Mission_ConstB.SinCos_o1_h;

    // BusCreator: '<S14>/FixedWingGuidanceStateBus' incorporates:
    //   Gain: '<S21>/Gain1'
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_FixedWingGuidanceStateBus_N = rtb_FlightPathAngle_g;
    rtb_FixedWingGuidanceStateBus_E = rtb_Switch_e;
    rtb_HeadingAngle = 0.017453292519943295 *
      codegenReal2Mission_U.RealUAVLatLonState.HeadingAngle_deg;

    // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S14>/FixedWingGuidanceStateBus'

    rtb_MemoryLookAheadP = rtb_FlightPathAngle_g;

    // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S14>/FixedWingGuidanceStateBus'

    rtb_East_p = rtb_Switch_e;

    // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
    //   DataStoreRead: '<S14>/AltitudeGCS'
    //   Gain: '<S14>/inverse'
    //   Inport: '<Root>/RealUAVLatLonState'
    //   Sum: '<S24>/Sum'

    rtb_Height = codegenReal2Mission_U.RealUAVLatLonState.Height_meter +
      -codegenReal2Mission_DW.AltitudeGCS;

    // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S14>/FixedWingGuidanceStateBus'
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_AirSpeed_c = codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps;

    // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
    //   Gain: '<S22>/Gain1'
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_FlightPathAngle = 0.017453292519943295 *
      codegenReal2Mission_U.RealUAVLatLonState.FlightPathAngle_deg;

    // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
    //   Gain: '<S23>/Gain1'
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_RollAngle_i = 0.017453292519943295 *
      codegenReal2Mission_U.RealUAVLatLonState.RollAngle_deg;

    // SignalConversion generated from: '<S2>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S14>/FixedWingGuidanceStateBus'
    //   Constant: '<S14>/dummyRollAngleRate'

    rtb_RollAngleRate = 0.0;

    // End of Outputs for SubSystem: '<S2>/LatLon2NorthEast'

    // SignalConversion generated from: '<S2>/SimUAVStateBus'
    rtb_North = codegenReal2Mission_B.SimUAVStateZOH.North;

    // SignalConversion generated from: '<S2>/SimUAVStateBus'
    rtb_East = codegenReal2Mission_B.SimUAVStateZOH.East;

    // SignalConversion generated from: '<S2>/SimUAVStateBus'
    rtb_Height_n = codegenReal2Mission_B.SimUAVStateZOH.Height;

    // SignalConversion generated from: '<S2>/SimUAVStateBus'
    rtb_AirSpeed_l = codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

    // SignalConversion generated from: '<S2>/SimUAVStateBus'
    rtb_HeadingAngle_e = codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle;

    // SignalConversion generated from: '<S2>/SimUAVStateBus'
    rtb_FlightPathAngle_g = codegenReal2Mission_B.SimUAVStateZOH.FlightPathAngle;

    // SignalConversion generated from: '<S2>/SimUAVStateBus'
    rtb_Abs1_n = codegenReal2Mission_B.SimUAVStateZOH.RollAngle;

    // SignalConversion generated from: '<S2>/SimUAVStateBus'
    rtb_Switch_e = codegenReal2Mission_B.SimUAVStateZOH.RollAngleRate;

    // Chart: '<S2>/TASgreaterthan15for1Sec' incorporates:
    //   BusCreator: '<S14>/FixedWingGuidanceStateBus'
    //   Inport: '<Root>/RealUAVLatLonState'

    if (codegenReal2Mission_DW.is_active_c1_codegenReal2Missio == 0U) {
      codegenReal2Mission_DW.is_active_c1_codegenReal2Missio = 1U;
      codegenReal2Mission_DW.is_c1_codegenReal2Mission =
        codegenReal2Missi_IN_NotTakeOff;
      codegenReal2Mission_B.TakeOffTrigger = false;
      codegenReal2Mission_DW.Count = 0.0;
    } else if (codegenReal2Mission_DW.is_c1_codegenReal2Mission == 1) {
      codegenReal2Mission_B.TakeOffTrigger = true;

      // case IN_NotTakeOff:
    } else if (codegenReal2Mission_DW.Count >= 9.0) {
      codegenReal2Mission_DW.is_c1_codegenReal2Mission =
        codegenReal2Mission_IN_InAir;
      codegenReal2Mission_B.TakeOffTrigger = true;
    } else {
      // Outputs for Atomic SubSystem: '<S2>/LatLon2NorthEast'
      if (codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps < 15.0) {
        codegenReal2Mission_DW.is_c1_codegenReal2Mission =
          codegenReal2Missi_IN_NotTakeOff;
        codegenReal2Mission_B.TakeOffTrigger = false;
        codegenReal2Mission_DW.Count = 0.0;
      } else {
        codegenReal2Mission_B.TakeOffTrigger = false;
        codegenReal2Mission_DW.Count++;
      }

      // End of Outputs for SubSystem: '<S2>/LatLon2NorthEast'
    }

    // End of Chart: '<S2>/TASgreaterthan15for1Sec'

    // Outputs for Atomic SubSystem: '<S2>/GenerateTrack'
    // S-Function (sfix_udelay): '<S13>/EastSequence'
    rtb_MatrixConcatenate[145] = codegenReal2Mission_B.SimUAVStateZOH.East;

    // Gain: '<S13>/TrackInvH'
    codegenReal2Mission_B.TrackInvH =
      -codegenReal2Mission_B.SimUAVStateZOH.Height;

    // S-Function (sfix_udelay): '<S13>/HeightSequence'
    rtb_MatrixConcatenate[218] = codegenReal2Mission_B.TrackInvH;
    for (i = 0; i < 72; i++) {
      // S-Function (sfix_udelay): '<S13>/EastSequence'
      rtb_MatrixConcatenate[i + 73] = codegenReal2Mission_DW.EastSequence_X[i];

      // S-Function (sfix_udelay): '<S13>/HeightSequence'
      rtb_MatrixConcatenate[i + 146] = codegenReal2Mission_DW.HeightSequence_X[i];

      // S-Function (sfix_udelay): '<S13>/NorthSequence'
      rtb_MatrixConcatenate[i] = codegenReal2Mission_DW.NorthSequence_X[i];
    }

    // S-Function (sfix_udelay): '<S13>/NorthSequence'
    rtb_MatrixConcatenate[72] = codegenReal2Mission_B.SimUAVStateZOH.North;
    for (i = 0; i < 71; i++) {
      // Update for S-Function (sfix_udelay): '<S13>/EastSequence'
      codegenReal2Mission_DW.EastSequence_X[i] =
        codegenReal2Mission_DW.EastSequence_X[i + 1];

      // Update for S-Function (sfix_udelay): '<S13>/HeightSequence'
      codegenReal2Mission_DW.HeightSequence_X[i] =
        codegenReal2Mission_DW.HeightSequence_X[i + 1];

      // Update for S-Function (sfix_udelay): '<S13>/NorthSequence'
      codegenReal2Mission_DW.NorthSequence_X[i] =
        codegenReal2Mission_DW.NorthSequence_X[i + 1];
    }

    // Update for S-Function (sfix_udelay): '<S13>/EastSequence'
    codegenReal2Mission_DW.EastSequence_X[71] =
      codegenReal2Mission_B.SimUAVStateZOH.East;

    // Update for S-Function (sfix_udelay): '<S13>/HeightSequence'
    codegenReal2Mission_DW.HeightSequence_X[71] =
      codegenReal2Mission_B.TrackInvH;

    // Update for S-Function (sfix_udelay): '<S13>/NorthSequence'
    codegenReal2Mission_DW.NorthSequence_X[71] =
      codegenReal2Mission_B.SimUAVStateZOH.North;

    // End of Outputs for SubSystem: '<S2>/GenerateTrack'

    // Outputs for Atomic SubSystem: '<S2>/SpeedControl'
    // Sum: '<S71>/Sum' incorporates:
    //   BusCreator: '<S14>/FixedWingGuidanceStateBus'

    rtb_Sum_np[0] = codegenReal2Mission_B.SimUAVStateZOH.North -
      rtb_FixedWingGuidanceStateBus_N;
    rtb_Sum_np[1] = codegenReal2Mission_B.SimUAVStateZOH.East -
      rtb_FixedWingGuidanceStateBus_E;
    rtb_Sum_np[2] = codegenReal2Mission_B.SimUAVStateZOH.Height -
      codegenReal2Mission_B.SimUAVStateZOH.Height;

    // DotProduct: '<S71>/Dot Product'
    rtb_TD_AirSpdADRC = rtb_Sum_np[0] * rtb_Sum_np[0];

    // Outputs for Atomic SubSystem: '<S2>/GenerateTrack'
    // Selector: '<S16>/WayPoint0d3' incorporates:
    //   S-Function (sfix_udelay): '<S13>/NorthSequence'
    //   Sum: '<S74>/Sum'

    rtb_Sum_np[0] = codegenReal2Mission_B.SimUAVStateZOH.North;

    // End of Outputs for SubSystem: '<S2>/GenerateTrack'

    // DotProduct: '<S71>/Dot Product'
    rtb_TD_AirSpdADRC += rtb_Sum_np[1] * rtb_Sum_np[1];

    // Selector: '<S16>/WayPoint0d3' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Sum: '<S74>/Sum'

    rtb_Sum_np[1] = rtb_MatrixConcatenate[145];

    // DotProduct: '<S71>/Dot Product'
    rtb_TD_AirSpdADRC += rtb_Sum_np[2] * rtb_Sum_np[2];

    // Selector: '<S16>/WayPoint0d3' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Sum: '<S74>/Sum'

    rtb_Sum_np[2] = rtb_MatrixConcatenate[218];

    // Sqrt: '<S71>/sqrt' incorporates:
    //   DotProduct: '<S71>/Dot Product'

    rtb_ycos_k = std::sqrt(rtb_TD_AirSpdADRC);

    // Gain: '<S16>/InverseY'
    codegenReal2Mission_B.InverseY = -rtb_ycos_k;

    // Outputs for Atomic SubSystem: '<S2>/GenerateTrack'
    // Sum: '<S73>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   S-Function (sfix_udelay): '<S13>/NorthSequence'
    //   Selector: '<S16>/WayPoint2d3'

    rtb_Sum_nn = rtb_MatrixConcatenate[24] -
      codegenReal2Mission_B.SimUAVStateZOH.North;

    // End of Outputs for SubSystem: '<S2>/GenerateTrack'

    // DotProduct: '<S73>/Dot Product'
    rtb_Output = rtb_Sum_nn * rtb_Sum_nn;

    // Sum: '<S73>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Selector: '<S16>/WayPoint0d3'
    //   Selector: '<S16>/WayPoint2d3'

    rtb_Sum_nn = rtb_MatrixConcatenate[97] - rtb_MatrixConcatenate[145];

    // DotProduct: '<S73>/Dot Product'
    rtb_Output += rtb_Sum_nn * rtb_Sum_nn;

    // Sum: '<S73>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Selector: '<S16>/WayPoint0d3'
    //   Selector: '<S16>/WayPoint2d3'

    rtb_Sum_nn = rtb_MatrixConcatenate[170] - rtb_MatrixConcatenate[218];

    // Sqrt: '<S73>/sqrt' incorporates:
    //   DotProduct: '<S73>/Dot Product'

    rtb_Down_a = std::sqrt(rtb_Sum_nn * rtb_Sum_nn + rtb_Output);

    // Gain: '<S16>/InverseR'
    codegenReal2Mission_B.InverseR = -rtb_Down_a;

    // End of Outputs for SubSystem: '<S2>/SpeedControl'
  }

  // Outputs for Atomic SubSystem: '<S2>/SpeedControl'
  // Outputs for Atomic SubSystem: '<S16>/ADRC'
  // Integrator: '<S75>/ESO'
  rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
  if (rEQ0) {
    rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
            (codegenReal2Mission_PrevZCX.ESO_Reset_ZCE != 1));
    codegenReal2Mission_PrevZCX.ESO_Reset_ZCE =
      codegenReal2Mission_B.TakeOffTrigger;

    // evaluate zero-crossings
    if (rEQ0) {
      codegenReal2Mission_X.ESO_CSTATE = 0.0;
    }
  }

  // Sum: '<S5>/Output' incorporates:
  //   Integrator: '<S75>/ESO'

  rtb_Output = codegenReal2Mission_X.ESO_CSTATE;

  // Integrator: '<S75>/ESO_dot'
  rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
  if (rEQ0) {
    rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
            (codegenReal2Mission_PrevZCX.ESO_dot_Reset_ZCE != 1));
    codegenReal2Mission_PrevZCX.ESO_dot_Reset_ZCE =
      codegenReal2Mission_B.TakeOffTrigger;

    // evaluate zero-crossings
    if (rEQ0) {
      codegenReal2Mission_X.ESO_dot_CSTATE = 0.0;
    }
  }

  d = codegenReal2Mission_X.ESO_dot_CSTATE;

  // End of Integrator: '<S75>/ESO_dot'

  // Integrator: '<S75>/ESO_dotdot'
  rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
  if (rEQ0) {
    rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
            (codegenReal2Mission_PrevZCX.ESO_dotdot_Reset_ZCE != 1));
    codegenReal2Mission_PrevZCX.ESO_dotdot_Reset_ZCE =
      codegenReal2Mission_B.TakeOffTrigger;

    // evaluate zero-crossings
    if (rEQ0) {
      codegenReal2Mission_X.ESO_dotdot_CSTATE = 0.0;
    }
  }

  Vg = codegenReal2Mission_X.ESO_dotdot_CSTATE;

  // End of Integrator: '<S75>/ESO_dotdot'

  // Integrator: '<S77>/TD_AirSpdADRC'
  rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
  if (rEQ0) {
    rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
            (codegenReal2Mission_PrevZCX.TD_AirSpdADRC_Reset_ZCE != 1));
    codegenReal2Mission_PrevZCX.TD_AirSpdADRC_Reset_ZCE =
      codegenReal2Mission_B.TakeOffTrigger;

    // evaluate zero-crossings
    if (rEQ0) {
      codegenReal2Mission_X.TD_AirSpdADRC_CSTATE = 0.0;
    }
  }

  rtb_TD_AirSpdADRC = codegenReal2Mission_X.TD_AirSpdADRC_CSTATE;

  // Sum: '<S70>/Sum' incorporates:
  //   Integrator: '<S77>/TD_AirSpdADRC'

  rtb_Sum_nn = codegenReal2Mission_X.TD_AirSpdADRC_CSTATE - rtb_Output;

  // Integrator: '<S77>/dotTD'
  rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
  if (rEQ0) {
    rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
            (codegenReal2Mission_PrevZCX.dotTD_Reset_ZCE != 1));
    codegenReal2Mission_PrevZCX.dotTD_Reset_ZCE =
      codegenReal2Mission_B.TakeOffTrigger;

    // evaluate zero-crossings
    if (rEQ0) {
      codegenReal2Mission_X.dotTD_CSTATE = 0.0;
    }
  }

  // Integrator: '<S77>/dotTD'
  codegenReal2Mission_B.dotTD = codegenReal2Mission_X.dotTD_CSTATE;

  // MATLAB Function: '<S76>/fhan(e1,ce2,r,h1)' incorporates:
  //   Gain: '<S76>/Gain'
  //   SignalConversion generated from: '<S80>/ SFunction '
  //   Sum: '<S70>/Sum1'

  q = (codegenReal2Mission_B.dotTD - d) * 3.2202531507756045 * 9.64653500837626;
  rtb_Sum_nn += q;
  if (rtb_Sum_nn < 0.0) {
    y = -1.0;
  } else if (rtb_Sum_nn > 0.0) {
    y = 1.0;
  } else if (rtb_Sum_nn == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  a2 = (std::sqrt((8.0 * std::abs(rtb_Sum_nn) + 465.27818833914387) *
                  465.27818833914387) - 465.27818833914387) * y / 2.0 + q;
  if (rtb_Sum_nn + 465.27818833914387 < 0.0) {
    y = -1.0;
  } else if (rtb_Sum_nn + 465.27818833914387 > 0.0) {
    y = 1.0;
  } else if (rtb_Sum_nn + 465.27818833914387 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  if (rtb_Sum_nn - 465.27818833914387 < 0.0) {
    y_0 = -1.0;
  } else if (rtb_Sum_nn - 465.27818833914387 > 0.0) {
    y_0 = 1.0;
  } else if (rtb_Sum_nn - 465.27818833914387 == 0.0) {
    y_0 = 0.0;
  } else {
    y_0 = (rtNaN);
  }

  rtb_Sum_nn = ((q + rtb_Sum_nn) - a2) * ((y - y_0) / 2.0) + a2;
  if (rtb_Sum_nn < 0.0) {
    Gain = -1.0;
  } else if (rtb_Sum_nn > 0.0) {
    Gain = 1.0;
  } else if (rtb_Sum_nn == 0.0) {
    Gain = 0.0;
  } else {
    Gain = (rtNaN);
  }

  if (rtb_Sum_nn + 465.27818833914387 < 0.0) {
    q = -1.0;
  } else if (rtb_Sum_nn + 465.27818833914387 > 0.0) {
    q = 1.0;
  } else if (rtb_Sum_nn + 465.27818833914387 == 0.0) {
    q = 0.0;
  } else {
    q = (rtNaN);
  }

  if (rtb_Sum_nn - 465.27818833914387 < 0.0) {
    y = -1.0;
  } else if (rtb_Sum_nn - 465.27818833914387 > 0.0) {
    y = 1.0;
  } else if (rtb_Sum_nn - 465.27818833914387 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  // Gain: '<S70>/Gain' incorporates:
  //   Gain: '<S76>/Gain1'
  //   MATLAB Function: '<S76>/fhan(e1,ce2,r,h1)'
  //   Sum: '<S70>/ESOpNLSEF'

  Gain = (-((rtb_Sum_nn / 465.27818833914387 - Gain) * -5.0 * ((q - y) / 2.0) -
            5.0 * Gain) - Vg) * 0.4469922429475931;

  // Sum: '<S70>/Sum3'
  rtb_Sum_nn = rtb_Output - codegenReal2Mission_B.InverseY;

  // MATLAB Function: '<S75>/fal(e,0.5,h)' incorporates:
  //   Constant: '<S75>/Constant2'
  //   Constant: '<S75>/Constant3'

  codegenReal2Mission_fale025h(rtb_Sum_nn, 0.5, 0.1, &rtb_Output);

  // Sum: '<S75>/ESOdotdotsum' incorporates:
  //   Gain: '<S75>/Gain1'
  //   Gain: '<S75>/Gain4'

  codegenReal2Mission_B.ESOdotdotsum = (2.23717528833547 * Gain + Vg) -
    1.5811388300841895 * rtb_Output;

  // Sum: '<S75>/ESOdotsum'
  codegenReal2Mission_B.ESOdotsum = d - rtb_Sum_nn;

  // MATLAB Function: '<S75>/fal(e,0.25,h)' incorporates:
  //   Constant: '<S75>/Constant'
  //   Constant: '<S75>/Constant1'

  codegenReal2Mission_fale025h(rtb_Sum_nn, 0.25, 0.1, &Vg);

  // Gain: '<S75>/Inverse' incorporates:
  //   Gain: '<S75>/Gain'

  codegenReal2Mission_B.Inverse = -(1.2679145539688905 * Vg);

  // MATLAB Function: '<S77>/fhan_AirSpdADRC' incorporates:
  //   SignalConversion generated from: '<S81>/ SFunction '
  //   Sum: '<S77>/Sum1'

  q = codegenReal2Mission_B.dotTD * 0.1;
  rtb_Sum_nn = (rtb_TD_AirSpdADRC - codegenReal2Mission_B.InverseR) + q;
  if (rtb_Sum_nn < 0.0) {
    y = -1.0;
  } else if (rtb_Sum_nn > 0.0) {
    y = 1.0;
  } else if (rtb_Sum_nn == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  a2 = (std::sqrt((8.0 * std::abs(rtb_Sum_nn) + 0.005000000000000001) *
                  0.005000000000000001) - 0.005000000000000001) * y / 2.0 + q;
  if (rtb_Sum_nn + 0.005000000000000001 < 0.0) {
    y = -1.0;
  } else if (rtb_Sum_nn + 0.005000000000000001 > 0.0) {
    y = 1.0;
  } else if (rtb_Sum_nn + 0.005000000000000001 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  if (rtb_Sum_nn - 0.005000000000000001 < 0.0) {
    y_0 = -1.0;
  } else if (rtb_Sum_nn - 0.005000000000000001 > 0.0) {
    y_0 = 1.0;
  } else if (rtb_Sum_nn - 0.005000000000000001 == 0.0) {
    y_0 = 0.0;
  } else {
    y_0 = (rtNaN);
  }

  rtb_Sum_nn = ((q + rtb_Sum_nn) - a2) * ((y - y_0) / 2.0) + a2;
  if (rtb_Sum_nn < 0.0) {
    rtb_Output = -1.0;
  } else if (rtb_Sum_nn > 0.0) {
    rtb_Output = 1.0;
  } else if (rtb_Sum_nn == 0.0) {
    rtb_Output = 0.0;
  } else {
    rtb_Output = (rtNaN);
  }

  if (rtb_Sum_nn + 0.005000000000000001 < 0.0) {
    q = -1.0;
  } else if (rtb_Sum_nn + 0.005000000000000001 > 0.0) {
    q = 1.0;
  } else if (rtb_Sum_nn + 0.005000000000000001 == 0.0) {
    q = 0.0;
  } else {
    q = (rtNaN);
  }

  if (rtb_Sum_nn - 0.005000000000000001 < 0.0) {
    y = -1.0;
  } else if (rtb_Sum_nn - 0.005000000000000001 > 0.0) {
    y = 1.0;
  } else if (rtb_Sum_nn - 0.005000000000000001 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  codegenReal2Mission_B.fh_n = (rtb_Sum_nn / 0.005000000000000001 - rtb_Output) *
    -0.5 * ((q - y) / 2.0) - 0.5 * rtb_Output;

  // End of MATLAB Function: '<S77>/fhan_AirSpdADRC'
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // ZeroOrderHold: '<S70>/ZOH_ADRC_LagDis' incorporates:
    //   Sum: '<S70>/LagDistanceSum'

    rtb_ZOH_ADRC_LagDis = rtb_TD_AirSpdADRC - codegenReal2Mission_B.InverseY;

    // ZeroOrderHold: '<S70>/ZOH_ADRC_U'
    rtb_ZOH_ADRC_U = Gain;

    // Sum: '<S72>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Selector: '<S16>/WayPoint1d3'
    //   Sum: '<S74>/Sum'

    rtb_Sum_nn = rtb_MatrixConcatenate[48] - rtb_Sum_np[0];

    // DotProduct: '<S72>/Dot Product'
    rtb_Output = rtb_Sum_nn * rtb_Sum_nn;

    // Sum: '<S74>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Selector: '<S16>/WayPoint1d3'
    //   Selector: '<S16>/WayPoint3d3'
    //   Sum: '<S72>/Sum'

    rtb_TD_AirSpdADRC = rtb_MatrixConcatenate[0] - rtb_Sum_np[0];

    // DotProduct: '<S74>/Dot Product'
    rtb_SpeedProtection = rtb_TD_AirSpdADRC * rtb_TD_AirSpdADRC;

    // Sum: '<S72>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Selector: '<S16>/WayPoint1d3'
    //   Sum: '<S74>/Sum'

    rtb_Sum_nn = rtb_MatrixConcatenate[121] - rtb_Sum_np[1];

    // DotProduct: '<S72>/Dot Product'
    rtb_Output += rtb_Sum_nn * rtb_Sum_nn;

    // Sum: '<S74>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Selector: '<S16>/WayPoint1d3'
    //   Selector: '<S16>/WayPoint3d3'
    //   Sum: '<S72>/Sum'

    rtb_TD_AirSpdADRC = rtb_MatrixConcatenate[73] - rtb_Sum_np[1];

    // DotProduct: '<S74>/Dot Product'
    rtb_SpeedProtection += rtb_TD_AirSpdADRC * rtb_TD_AirSpdADRC;

    // Sum: '<S72>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Selector: '<S16>/WayPoint1d3'
    //   Sum: '<S74>/Sum'

    rtb_Sum_nn = rtb_MatrixConcatenate[194] - rtb_Sum_np[2];

    // Sum: '<S74>/Sum' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Selector: '<S16>/WayPoint1d3'
    //   Selector: '<S16>/WayPoint3d3'
    //   Sum: '<S72>/Sum'

    rtb_TD_AirSpdADRC = rtb_MatrixConcatenate[146] - rtb_Sum_np[2];

    // Sqrt: '<S72>/sqrt' incorporates:
    //   DotProduct: '<S72>/Dot Product'

    rtb_Switch_n = std::sqrt(rtb_Sum_nn * rtb_Sum_nn + rtb_Output);

    // Sum: '<S16>/ActRngmMinRng'
    rtb_ycos_k -= rtb_Switch_n;

    // Sum: '<S16>/ComputeLB'
    rtb_LowerBound = rtb_Switch_n - rtb_Down_a;

    // Sum: '<S16>/ComputeUB' incorporates:
    //   DotProduct: '<S74>/Dot Product'
    //   Sqrt: '<S74>/sqrt'

    rtb_UpperBound = std::sqrt(rtb_TD_AirSpdADRC * rtb_TD_AirSpdADRC +
      rtb_SpeedProtection) - rtb_Down_a;

    // Sum: '<S16>/RefRngmMinRng'
    rtb_Switch_n = rtb_Down_a - rtb_Switch_n;

    // SignalConversion generated from: '<S16>/SimStateBus'
    rtb_AirSpeed = codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

    // Sum: '<S16>/SumSpd' incorporates:
    //   SignalConversion generated from: '<S16>/SimStateBus'

    rtb_SpeedProtection = rtb_ZOH_ADRC_U +
      codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

    // Saturate: '<S16>/SpeedProtection'
    if (rtb_SpeedProtection > 41.0) {
      rtb_SpeedProtection = 41.0;
    } else if (rtb_SpeedProtection < 29.0) {
      rtb_SpeedProtection = 29.0;
    }

    // End of Saturate: '<S16>/SpeedProtection'

    // Saturate: '<S16>/Saturation'
    if (rtb_ycos_k <= 46.666666666666664) {
      rtb_ycos_k = 46.666666666666664;
    }

    // End of Saturate: '<S16>/Saturation'

    // Sum: '<S16>/biasHm70' incorporates:
    //   Math: '<S16>/Square'
    //   Product: '<S16>/Divide'

    rtb_Switch_n = rtb_Switch_n * rtb_Switch_n / rtb_ycos_k - rtb_Switch_n;

    // SignalConversion generated from: '<S2>/TrackSimPath' incorporates:
    //   BusCreator: '<S14>/FixedWingGuidanceStateBus'
    //   Memory: '<S2>/MemoryRefHeight'

    rtb_FixedWingGuidanceStateBus_0[0] = rtb_FixedWingGuidanceStateBus_N;
    rtb_FixedWingGuidanceStateBus_0[1] = rtb_FixedWingGuidanceStateBus_E;
    rtb_FixedWingGuidanceStateBus_0[2] =
      codegenReal2Mission_DW.MemoryRefHeight_PreviousInput;
    rtb_FixedWingGuidanceStateBus_0[3] = rtb_HeadingAngle;

    // MATLABSystem: '<S2>/TrackSimPath' incorporates:
    //   Concatenate: '<S13>/Matrix Concatenate'
    //   Gain: '<S2>/LookaheadT'
    //   SignalConversion generated from: '<S16>/SimStateBus'

    WaypointFollowerBase_stepIntern(&codegenReal2Mission_DW.obj,
      rtb_FixedWingGuidanceStateBus_0, rtb_MatrixConcatenate, 3.6 *
      codegenReal2Mission_B.SimUAVStateZOH.AirSpeed,
      codegenReal2Mission_B.NorthEastHeight, &rtb_TargetHDG_Rad, &rtb_ycos_k,
      &lookaheadFlag, &rtb_TrackSimPath_o5, &status);

    // Gain: '<S2>/NED2NEU' incorporates:
    //   MATLABSystem: '<S2>/TrackSimPath'

    codegenReal2Mission_B.NorthEastHeight[2] =
      -codegenReal2Mission_B.NorthEastHeight[2];
  }

  // End of Outputs for SubSystem: '<S16>/ADRC'
  // End of Outputs for SubSystem: '<S2>/SpeedControl'

  // Integrator: '<S18>/TD_Alt'
  codegenReal2Mission_B.TD_Alt = codegenReal2Mission_X.TD_Alt_CSTATE;

  // Sum: '<S2>/Sum' incorporates:
  //   Gain: '<S2>/NED2NEU'

  codegenReal2Mission_B.Sum[0] = codegenReal2Mission_B.NorthEastHeight[0];
  codegenReal2Mission_B.Sum[1] = codegenReal2Mission_B.NorthEastHeight[1];
  codegenReal2Mission_B.Sum[2] = codegenReal2Mission_B.NorthEastHeight[2] +
    codegenReal2Mission_B.TD_Alt;
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Truth Table: '<S2>/Engagement'
    //  Front Distance within Upper &  Lower Bound
    //  CrossTrack Error within 1.5 Second Bound
    if ((rtb_ZOH_ADRC_LagDis < rtb_UpperBound) && (rtb_ZOH_ADRC_LagDis >
         rtb_LowerBound) && (rtb_TrackSimPath_o5 < rtb_AirSpeed * 1.5)) {
      //  Real UAV Engaged with Simulation UAV
      rtb_Engaged = true;
    } else {
      //  Default
      //  Real UAV Not Engaged with Simulation UAV
      rtb_Engaged = false;
    }

    // End of Truth Table: '<S2>/Engagement'

    // MATLAB Function: '<S2>/AngLog' incorporates:
    //   BusCreator: '<S14>/FixedWingGuidanceStateBus'

    rtb_TargetHdg_Log = angdiff_GFr2Xk58(0.0, rtb_TargetHDG_Rad);
    rtb_LowerBound = angdiff_GFr2Xk58(0.0, rtb_HeadingAngle);
    rtb_TargetHDG_Rad = angdiff_GFr2Xk58(rtb_HeadingAngle, rtb_TargetHDG_Rad);

    // Scope: '<S2>/ModelLogging'
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
        up0[0] = rtb_MemoryLookAheadP;
        up0[1] = rtb_East_p;
        up0[2] = rtb_Height;
        up0[3] = rtb_AirSpeed_c;
        up0[4] = rtb_HeadingAngle;
        up0[5] = rtb_FlightPathAngle;
        up0[6] = rtb_RollAngle_i;
        up0[7] = rtb_RollAngleRate;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[8];
        up1[0] = rtb_North;
        up1[1] = rtb_East;
        up1[2] = rtb_Height_n;
        up1[3] = rtb_AirSpeed_l;
        up1[4] = rtb_HeadingAngle_e;
        up1[5] = rtb_FlightPathAngle_g;
        up1[6] = rtb_Abs1_n;
        up1[7] = rtb_Switch_e;
        rt_UpdateLogVar((LogVar *)var, up1, 0);
        var = var->next;
      }

      {
        real_T up2[1];
        up2[0] = rtb_SpeedProtection;
        rt_UpdateLogVar((LogVar *)var, up2, 0);
        var = var->next;
      }

      {
        real_T up3[1];
        up3[0] = rtb_ZOH_ADRC_LagDis;
        rt_UpdateLogVar((LogVar *)var, up3, 0);
        var = var->next;
      }

      {
        real_T up4[3];
        up4[0] = codegenReal2Mission_B.Sum[0];
        up4[1] = codegenReal2Mission_B.Sum[1];
        up4[2] = codegenReal2Mission_B.Sum[2];
        rt_UpdateLogVar((LogVar *)var, up4, 0);
        var = var->next;
      }

      {
        real_T up5[1];
        up5[0] = rtb_TrackSimPath_o5;
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
        up7[0] = rtb_TargetHDG_Rad;
        up7[1] = rtb_LowerBound;
        up7[2] = rtb_TargetHdg_Log;
        rt_UpdateLogVar((LogVar *)var, up7, 0);
        var = var->next;
      }

      {
        real_T up8[1];
        up8[0] = rtb_ZOH_ADRC_U;
        rt_UpdateLogVar((LogVar *)var, up8, 0);
        var = var->next;
      }

      {
        real_T up9[1];
        up9[0] = codegenReal2Mission_B.TD_Alt;
        rt_UpdateLogVar((LogVar *)var, up9, 0);
      }
    }

    // Chart: '<S2>/TriggerTermination'
    if (codegenReal2Mission_DW.is_active_c4_codegenReal2Missio == 0U) {
      codegenReal2Mission_DW.is_active_c4_codegenReal2Missio = 1U;
      codegenReal2Mission_B.Terminate = false;
      codegenReal2Mission_DW.is_c4_codegenReal2Mission =
        codegenReal2M_IN_InitialPersuit;
      codegenReal2Mission_B.ExecutionTrigger = 0.0;
      codegenReal2Mission_DW.DataCounter = 0.0;
    } else {
      switch (codegenReal2Mission_DW.is_c4_codegenReal2Mission) {
       case codegenReal2M_IN_InitialPersuit:
        if (codegenReal2Mission_DW.DataCounter >= 599.0) {
          codegenReal2Mission_DW.is_c4_codegenReal2Mission =
            codegenReal_IN_MissionExecution;
          codegenReal2Mission_B.ExecutionTrigger = 1.0;
          codegenReal2Mission_DW.DataCounter = 0.0;
        } else if ((!codegenReal2Mission_B.TakeOffTrigger) || (!rtb_Engaged)) {
          codegenReal2Mission_DW.is_c4_codegenReal2Mission =
            codegenReal2M_IN_InitialPersuit;
          codegenReal2Mission_B.ExecutionTrigger = 0.0;
          codegenReal2Mission_DW.DataCounter = 0.0;
        } else {
          codegenReal2Mission_B.ExecutionTrigger = 0.0;
          codegenReal2Mission_DW.DataCounter++;
        }
        break;

       case codegenRea_IN_MissionCompletion:
        codegenReal2Mission_B.Terminate = true;
        break;

       default:
        // case IN_MissionExecution:
        if (codegenReal2Mission_DW.DataCounter >= 599.0) {
          codegenReal2Mission_DW.is_c4_codegenReal2Mission =
            codegenRea_IN_MissionCompletion;
          codegenReal2Mission_B.Terminate = true;
        } else if (rtb_Engaged) {
          codegenReal2Mission_DW.is_c4_codegenReal2Mission =
            codegenReal_IN_MissionExecution;
          codegenReal2Mission_B.ExecutionTrigger = 1.0;
          codegenReal2Mission_DW.DataCounter = 0.0;
        } else {
          codegenReal2Mission_B.ExecutionTrigger = 1.0;
          codegenReal2Mission_DW.DataCounter++;
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

    // Switch: '<S2>/DataSwitch'
    if (codegenReal2Mission_B.ExecutionTrigger > 0.0) {
      // Switch: '<S2>/DataSwitch' incorporates:
      //   Constant: '<S2>/ZeroBias'

      codegenReal2Mission_B.DataSwitch = 0.0;
    } else {
      // Switch: '<S2>/DataSwitch'
      codegenReal2Mission_B.DataSwitch = rtb_Switch_n;
    }

    // End of Switch: '<S2>/DataSwitch'

    // Gain: '<S2>/Height2Down'
    rtb_Down = -codegenReal2Mission_B.NorthEastHeight[2];

    // Outputs for Atomic SubSystem: '<S2>/NorthEast2LatLon'
    // Switch: '<S61>/Switch' incorporates:
    //   Abs: '<S61>/Abs'
    //   Bias: '<S61>/Bias'
    //   Bias: '<S61>/Bias1'
    //   Constant: '<S61>/Constant2'
    //   Constant: '<S62>/Constant'
    //   DataStoreRead: '<S15>/LatitudeGCS'
    //   Math: '<S61>/Math Function1'
    //   RelationalOperator: '<S62>/Compare'

    if (std::abs(codegenReal2Mission_DW.LatitudeGCS) > 180.0) {
      rtb_Sum_nn = rt_modd_snf(codegenReal2Mission_DW.LatitudeGCS + 180.0, 360.0)
        + -180.0;
    } else {
      rtb_Sum_nn = codegenReal2Mission_DW.LatitudeGCS;
    }

    // End of Switch: '<S61>/Switch'

    // Abs: '<S58>/Abs1'
    rtb_TargetHdg_Log = std::abs(rtb_Sum_nn);

    // Switch: '<S58>/Switch' incorporates:
    //   Bias: '<S58>/Bias'
    //   Bias: '<S58>/Bias1'
    //   Constant: '<S49>/Constant'
    //   Constant: '<S49>/Constant1'
    //   Constant: '<S60>/Constant'
    //   Gain: '<S58>/Gain'
    //   Product: '<S58>/Divide1'
    //   RelationalOperator: '<S60>/Compare'
    //   Switch: '<S49>/Switch1'

    if (rtb_TargetHdg_Log > 90.0) {
      // Signum: '<S58>/Sign1'
      if (rtb_Sum_nn < 0.0) {
        rtb_Sum_nn = -1.0;
      } else if (rtb_Sum_nn > 0.0) {
        rtb_Sum_nn = 1.0;
      } else if (rtb_Sum_nn == 0.0) {
        rtb_Sum_nn = 0.0;
      } else {
        rtb_Sum_nn = (rtNaN);
      }

      // End of Signum: '<S58>/Sign1'
      rtb_Sum_nn *= -(rtb_TargetHdg_Log + -90.0) + 90.0;
      i = 180;
    } else {
      i = 0;
    }

    // End of Switch: '<S58>/Switch'

    // UnitConversion: '<S66>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Switch_n = 0.017453292519943295 * rtb_Sum_nn;

    // Trigonometry: '<S67>/Trigonometric Function1'
    rtb_Down_a = std::sin(rtb_Switch_n);

    // Sum: '<S67>/Sum1' incorporates:
    //   Constant: '<S67>/Constant'
    //   Product: '<S67>/Product1'

    rtb_Down_a = 1.0 - codegenReal2Mission_ConstB.sqrt_k *
      codegenReal2Mission_ConstB.sqrt_k * rtb_Down_a * rtb_Down_a;

    // Product: '<S64>/Product1' incorporates:
    //   Constant: '<S64>/Constant1'
    //   Sqrt: '<S64>/sqrt'

    rtb_ycos_k = 6.378137E+6 / std::sqrt(rtb_Down_a);

    // Sum: '<S49>/Sum' incorporates:
    //   DataStoreRead: '<S15>/LongitudeGCS'

    // Unit Conversion - from: rad to: deg
    // Expression: output = (57.2958*input) + (0)
    rtb_Switch_e = static_cast<real_T>(i) + codegenReal2Mission_DW.LongitudeGCS;

    // Sum: '<S47>/Sum' incorporates:
    //   Constant: '<S64>/Constant2'
    //   Product: '<S50>/rad lat'
    //   Product: '<S50>/x*cos'
    //   Product: '<S50>/y*sin'
    //   Product: '<S64>/Product3'
    //   Sum: '<S50>/Sum'
    //   Trigonometry: '<S64>/Trigonometric Function1'
    //   UnitConversion: '<S51>/Unit Conversion'

    rtb_TargetHdg_Log = (codegenReal2Mission_B.Sum[0] *
                         codegenReal2Mission_ConstB.SinCos_o2 -
                         codegenReal2Mission_B.Sum[1] *
                         codegenReal2Mission_ConstB.SinCos_o1) * rt_atan2d_snf
      (1.0, rtb_ycos_k * codegenReal2Mission_ConstB.Sum1_k / rtb_Down_a) *
      57.295779513082323 + rtb_Sum_nn;

    // Switch: '<S55>/Switch' incorporates:
    //   Abs: '<S55>/Abs'
    //   Bias: '<S55>/Bias'
    //   Bias: '<S55>/Bias1'
    //   Constant: '<S55>/Constant2'
    //   Constant: '<S56>/Constant'
    //   Math: '<S55>/Math Function1'
    //   RelationalOperator: '<S56>/Compare'

    if (std::abs(rtb_TargetHdg_Log) > 180.0) {
      rtb_TargetHdg_Log = rt_modd_snf(rtb_TargetHdg_Log + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S55>/Switch'

    // Abs: '<S52>/Abs1'
    rtb_ZOH_ADRC_LagDis = std::abs(rtb_TargetHdg_Log);

    // Switch: '<S52>/Switch' incorporates:
    //   Constant: '<S48>/Constant'
    //   Constant: '<S48>/Constant1'
    //   Constant: '<S54>/Constant'
    //   RelationalOperator: '<S54>/Compare'
    //   Switch: '<S48>/Switch1'

    if (rtb_ZOH_ADRC_LagDis > 90.0) {
      // Signum: '<S52>/Sign1'
      if (rtb_TargetHdg_Log < 0.0) {
        rtb_TargetHdg_Log = -1.0;
      } else if (rtb_TargetHdg_Log > 0.0) {
        rtb_TargetHdg_Log = 1.0;
      } else if (rtb_TargetHdg_Log == 0.0) {
        rtb_TargetHdg_Log = 0.0;
      } else {
        rtb_TargetHdg_Log = (rtNaN);
      }

      // End of Signum: '<S52>/Sign1'

      // BusCreator: '<S15>/LookAheadPointBus' incorporates:
      //   Bias: '<S52>/Bias'
      //   Bias: '<S52>/Bias1'
      //   Gain: '<S52>/Gain'
      //   Product: '<S52>/Divide1'

      rtb_TargetHdg_Log *= -(rtb_ZOH_ADRC_LagDis + -90.0) + 90.0;
      i = 180;
    } else {
      i = 0;
    }

    // End of Switch: '<S52>/Switch'

    // Switch: '<S59>/Switch' incorporates:
    //   Abs: '<S59>/Abs'
    //   Bias: '<S59>/Bias'
    //   Bias: '<S59>/Bias1'
    //   Constant: '<S59>/Constant2'
    //   Constant: '<S63>/Constant'
    //   Math: '<S59>/Math Function1'
    //   RelationalOperator: '<S63>/Compare'

    if (std::abs(rtb_Switch_e) > 180.0) {
      rtb_Switch_e = rt_modd_snf(rtb_Switch_e + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S59>/Switch'

    // Sum: '<S48>/Sum' incorporates:
    //   Constant: '<S64>/Constant3'
    //   Product: '<S50>/rad long '
    //   Product: '<S50>/x*sin'
    //   Product: '<S50>/y*cos'
    //   Product: '<S64>/Product4'
    //   Sum: '<S47>/Sum'
    //   Sum: '<S50>/Sum1'
    //   Trigonometry: '<S64>/Trigonometric Function'
    //   Trigonometry: '<S64>/Trigonometric Function2'
    //   UnitConversion: '<S51>/Unit Conversion'

    rtb_Sum_c = ((codegenReal2Mission_B.Sum[0] *
                  codegenReal2Mission_ConstB.SinCos_o1 +
                  codegenReal2Mission_B.Sum[1] *
                  codegenReal2Mission_ConstB.SinCos_o2) * rt_atan2d_snf(1.0,
      rtb_ycos_k * std::cos(rtb_Switch_n)) * 57.295779513082323 + rtb_Switch_e)
      + static_cast<real_T>(i);

    // Switch: '<S53>/Switch' incorporates:
    //   Abs: '<S53>/Abs'
    //   Constant: '<S57>/Constant'
    //   RelationalOperator: '<S57>/Compare'

    if (std::abs(rtb_Sum_c) > 180.0) {
      // BusCreator: '<S15>/LookAheadPointBus' incorporates:
      //   Bias: '<S53>/Bias'
      //   Bias: '<S53>/Bias1'
      //   Constant: '<S53>/Constant2'
      //   Math: '<S53>/Math Function1'

      rtb_Sum_c = rt_modd_snf(rtb_Sum_c + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S53>/Switch'

    // BusCreator: '<S15>/LookAheadPointBus' incorporates:
    //   DataStoreRead: '<S15>/Data Store Read'
    //   Gain: '<S15>/Up2Down'
    //   Gain: '<S15>/inverse'
    //   Sum: '<S47>/Sum1'

    rtb_LookAheadPoint_Height_meter = codegenReal2Mission_B.Sum[2] -
      (-codegenReal2Mission_DW.AltitudeGCS);

    // End of Outputs for SubSystem: '<S2>/NorthEast2LatLon'
  }

  // Integrator: '<S18>/dotAltTD'
  codegenReal2Mission_B.dotAltTD = codegenReal2Mission_X.dotAltTD_CSTATE;

  // MATLAB Function: '<S18>/fhan_Alt' incorporates:
  //   Constant: '<S18>/Constant2'
  //   Constant: '<S18>/Constant3'
  //   Sum: '<S18>/Sum1'

  codegenReal2Mission_fhan_Bank(codegenReal2Mission_B.TD_Alt -
    codegenReal2Mission_B.DataSwitch, codegenReal2Mission_B.dotAltTD, 1.0, 0.1,
    &codegenReal2Mission_B.fh);

  // End of Outputs for SubSystem: '<Root>/Real2SimGuidance'
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Outport: '<Root>/RefAirspeed'
    codegenReal2Mission_Y.RefAirspeed = rtb_SpeedProtection;

    // Outport: '<Root>/LookAheadPoint' incorporates:
    //   BusCreator: '<S15>/LookAheadPointBus'

    codegenReal2Mission_Y.LookAheadPoint_j.Latitude_deg = rtb_TargetHdg_Log;
    codegenReal2Mission_Y.LookAheadPoint_j.Longitude_deg = rtb_Sum_c;
    codegenReal2Mission_Y.LookAheadPoint_j.Height_meter =
      rtb_LookAheadPoint_Height_meter;

    // Outport: '<Root>/EngagedFlag'
    codegenReal2Mission_Y.EngagedFlag = rtb_Engaged;

    // Gain: '<S1>/InvH2D'
    codegenReal2Mission_B.Down = -codegenReal2Mission_B.SimUAVStateZOH.Height;
  }

  // Step: '<S5>/Step'
  if ((&codegenReal2Mission_M)->Timing.t[0] < 0.0) {
    rtb_TD_AirSpdADRC = 0.0;
  } else {
    rtb_TD_AirSpdADRC = 0.057119866428905326;
  }

  // End of Step: '<S5>/Step'

  // Sum: '<S5>/Output' incorporates:
  //   Clock: '<S5>/Clock'
  //   Product: '<S5>/Product'

  rtb_Output = rtb_TD_AirSpdADRC * (&codegenReal2Mission_M)->Timing.t[0];
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Memory: '<S1>/MemoryLookAheadP'
    rtb_MemoryLookAheadP = codegenReal2Mission_DW.MemoryLookAheadP_PreviousInput;

    // Switch: '<S1>/CircleOscillation'
    if (rtb_MemoryLookAheadP > 0.0) {
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

  rtb_Sum_np[0] = std::sin(rtb_Output) * codegenReal2Mission_B.CircleOscillation;
  rtb_Sum_np[1] = std::cos(rtb_Output) * codegenReal2Mission_B.CircleOscillation;
  rtb_Sum_np[2] = -150.0;

  // MATLABSystem: '<S1>/TakeOffGathering' incorporates:
  //   SignalConversion generated from: '<S1>/TakeOffGathering'

  codegenReal2Mission_DW.obj_m.OrbitRadiusFlag = 0U;
  codegenReal2Mission_DW.obj_m.LookaheadDistFlag = 0U;
  rtb_TargetHdg_Log = codegenReal2Mission_B.SimUAVStateZOH.North - rtb_Sum_np[0];
  rtb_TmpSignalConversionAtSFun_0[0] = rtb_TargetHdg_Log;
  rtb_SpeedProtection = codegenReal2Mission_B.SimUAVStateZOH.East - rtb_Sum_np[1];
  rtb_TmpSignalConversionAtSFun_0[1] = rtb_SpeedProtection;
  if (codegenReal2Mission_norm(rtb_TmpSignalConversionAtSFun_0) <
      2.47032822920623E-323) {
    // MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_B.TakeOffGathering_o2 =
      codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle;
    rtb_SpeedProtection = codegenReal2Mission_DW.obj_m.NumCircles;
  } else {
    rtb_Engaged = false;
    rEQ0 = true;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      if ((codegenReal2Mission_DW.obj_m.OrbitCenterInternal[i] == rtb_Sum_np[i])
          || (rtIsNaN(codegenReal2Mission_DW.obj_m.OrbitCenterInternal[i]) &&
              rtIsNaN(rtb_Sum_np[i]))) {
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
      codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = rtb_Sum_np[0];
      codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = rtb_Sum_np[1];
      codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = -150.0;
      codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = 1000.0;
      codegenReal2Mission_DW.obj_m.SelectTurnDirectionFlag = true;
    }

    codegenReal2Mission_DW.obj_m.LookaheadDistance = 100.0;
    distToCenter_tmp[0] = rtb_TargetHdg_Log;
    distToCenter_tmp[1] = rtb_SpeedProtection;
    rtb_Switch_e = std::sqrt(rtb_SpeedProtection * rtb_SpeedProtection +
      rtb_TargetHdg_Log * rtb_TargetHdg_Log);
    rtb_ZOH_ADRC_U = std::abs(codegenReal2Mission_DW.obj_m.LookaheadDistance +
      1000.0);
    rEQ0 = !rtIsInf(rtb_ZOH_ADRC_U);
    rtb_Engaged = !rtIsNaN(rtb_ZOH_ADRC_U);
    if (rEQ0 && rtb_Engaged) {
      if (rtb_ZOH_ADRC_U <= 2.2250738585072014E-308) {
        rtb_ZOH_ADRC_LagDis = 4.94065645841247E-324;
      } else {
        frexp(rtb_ZOH_ADRC_U, &b_exponent);
        rtb_ZOH_ADRC_LagDis = std::ldexp(1.0, b_exponent - 53);
      }
    } else {
      rtb_ZOH_ADRC_LagDis = (rtNaN);
    }

    guard1 = false;
    if (rtb_Switch_e >= (codegenReal2Mission_DW.obj_m.LookaheadDistance + 1000.0)
        - 5.0 * rtb_ZOH_ADRC_LagDis) {
      guard1 = true;
    } else {
      if (rEQ0 && rtb_Engaged) {
        if (rtb_ZOH_ADRC_U <= 2.2250738585072014E-308) {
          rtb_ZOH_ADRC_LagDis = 4.94065645841247E-324;
        } else {
          frexp(rtb_ZOH_ADRC_U, &b_exponent_0);
          rtb_ZOH_ADRC_LagDis = std::ldexp(1.0, b_exponent_0 - 53);
        }
      } else {
        rtb_ZOH_ADRC_LagDis = (rtNaN);
      }

      if (rtb_Switch_e <= (1000.0 -
                           codegenReal2Mission_DW.obj_m.LookaheadDistance) + 5.0
          * rtb_ZOH_ADRC_LagDis) {
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

        rtb_TmpSignalConversionAtSFun_0[0] = rtb_TargetHdg_Log;
        rtb_TmpSignalConversionAtSFun_0[1] = rtb_SpeedProtection;
        d = codegenReal2Mission_norm(rtb_TmpSignalConversionAtSFun_0);
        rtb_TrackSimPath_o5 = codegenReal2Mission_DW.obj_m.LookaheadDistance *
          codegenReal2Mission_DW.obj_m.LookaheadDistance;
        rtb_Sum_nn = ((rtb_TrackSimPath_o5 - 1.0E+6) + d * d) / (2.0 * d);
        rtb_ZOH_ADRC_LagDis = rtb_Sum_np[0] -
          codegenReal2Mission_B.SimUAVStateZOH.North;
        rtb_ZOH_ADRC_U = rtb_ZOH_ADRC_LagDis * rtb_Sum_nn / d +
          codegenReal2Mission_B.SimUAVStateZOH.North;
        rtb_Switch_n = rtb_Sum_np[1] - codegenReal2Mission_B.SimUAVStateZOH.East;
        rtb_Switch_e = rtb_Switch_n * rtb_Sum_nn / d +
          codegenReal2Mission_B.SimUAVStateZOH.East;
        rtb_Abs1_n = std::sqrt(rtb_TrackSimPath_o5 - rtb_Sum_nn * rtb_Sum_nn);
        rtb_TrackSimPath_o5 = rtb_Switch_n * rtb_Abs1_n / d;
        distToCenter_tmp[0] = rtb_ZOH_ADRC_U - rtb_TrackSimPath_o5;
        rtb_Abs1_n = rtb_ZOH_ADRC_LagDis * rtb_Abs1_n / d;
        rtb_FlightPathAngle_g = rtb_Abs1_n + rtb_Switch_e;
        rtb_LowerBound = codegenReal2Mission_DW.obj_m.PrevPosition[1] -
          rtb_Sum_np[1];
        rtb_Sum_dv[0] = codegenReal2Mission_DW.obj_m.PrevPosition[0] -
          rtb_Sum_np[0];
        rtb_Sum_dv[1] = rtb_LowerBound;
        rtb_Sum_dv[2] = 0.0;
        rtb_Sum_np[0] = rtb_TargetHdg_Log;
        rtb_Sum_np[1] = rtb_SpeedProtection;
        rtb_Sum_np[2] = 0.0;
        rtb_TD_AirSpdADRC = codegenReal2Mission_norm_b(rtb_Sum_dv);
        rtb_Output = codegenReal2Mission_norm_b(rtb_Sum_np);
        rtb_Sum_nn = rtb_Sum_dv[0] / rtb_TD_AirSpdADRC;
        rtb_TargetHdg_Log /= rtb_Output;
        rtb_SpeedProtection /= rtb_Output;
        codegenReal2Mission_DW.obj_m.PrevPosition[0] =
          codegenReal2Mission_B.SimUAVStateZOH.North;
        codegenReal2Mission_DW.obj_m.PrevPosition[1] =
          codegenReal2Mission_B.SimUAVStateZOH.East;
        codegenReal2Mission_DW.obj_m.PrevPosition[2] =
          codegenReal2Mission_B.Down;
        rtb_East_p = rtb_LowerBound / rtb_TD_AirSpdADRC;
        codegenReal2Mission_DW.obj_m.NumCircles += rt_atan2d_snf(rtb_Sum_nn *
          rtb_SpeedProtection - rtb_TargetHdg_Log * rtb_East_p, (rtb_East_p *
          rtb_SpeedProtection + rtb_Sum_nn * rtb_TargetHdg_Log) + 0.0 /
          rtb_TD_AirSpdADRC * (0.0 / rtb_Output)) / 2.0 / 3.1415926535897931;
        rtb_SpeedProtection = codegenReal2Mission_DW.obj_m.NumCircles;
        if ((distToCenter_tmp[0] - codegenReal2Mission_B.SimUAVStateZOH.North) *
            rtb_Switch_n - rtb_ZOH_ADRC_LagDis * (rtb_FlightPathAngle_g -
             codegenReal2Mission_B.SimUAVStateZOH.East) > 0.0) {
          rtb_TargetHdg_Log = distToCenter_tmp[0];
        } else {
          rtb_TargetHdg_Log = rtb_TrackSimPath_o5 + rtb_ZOH_ADRC_U;
          rtb_FlightPathAngle_g = rtb_Switch_e - rtb_Abs1_n;
        }
      }
    }

    if (guard1) {
      rtb_TD_AirSpdADRC = codegenReal2Mission_norm(distToCenter_tmp);
      rtb_TargetHdg_Log = rtb_TargetHdg_Log / rtb_TD_AirSpdADRC * 1000.0 +
        rtb_Sum_np[0];
      rtb_FlightPathAngle_g = rtb_SpeedProtection / rtb_TD_AirSpdADRC * 1000.0 +
        rtb_Sum_np[1];
      rtb_SpeedProtection = codegenReal2Mission_DW.obj_m.NumCircles;
    }

    // MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_B.TakeOffGathering_o2 = rt_atan2d_snf
      (rtb_FlightPathAngle_g - codegenReal2Mission_B.SimUAVStateZOH.East,
       rtb_TargetHdg_Log - codegenReal2Mission_B.SimUAVStateZOH.North);
  }

  if ((codegenReal2Mission_DW.obj_m.PrevResetSignal <= 2.2227587494850775E-162) &&
      (codegenReal2Mission_B.ExecutionTrigger > 2.2227587494850775E-162)) {
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
      if ((rtb_SpeedProtection > 3.0) && (codegenReal2Mission_B.ExecutionTrigger
           != 0.0)) {
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
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Matfile logging
    rt_UpdateTXYLogVars((&codegenReal2Mission_M)->rtwLogInfo,
                        ((&codegenReal2Mission_M)->Timing.t));
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Update for Memory: '<S1>/MemoryFlowerMode'
      codegenReal2Mission_DW.MemoryFlowerMode_PreviousInput =
        codegenReal2Mission_B.Down2Height;

      // Update for Delay: '<S1>/InitHdg'
      codegenReal2Mission_DW.icLoad = false;

      // Update for BusCreator: '<S1>/Bus Creator' incorporates:
      //   Delay: '<S1>/InitHdg'

      codegenReal2Mission_DW.InitHdg_DSTATE =
        codegenReal2Mission_B.TakeOffGathering_o2;

      // Update for Atomic SubSystem: '<Root>/Real2SimGuidance'
      // Update for Memory: '<S2>/MemoryRefHeight'
      codegenReal2Mission_DW.MemoryRefHeight_PreviousInput = rtb_Down;

      // End of Update for SubSystem: '<Root>/Real2SimGuidance'

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
  _rtXdot = ((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs);

  // Derivatives for Atomic SubSystem: '<S1>/MissionSimUAV'
  // Derivatives for Integrator: '<S8>/Integrator' incorporates:
  //   MATLABSystem: '<S8>/ComputeDerivative'

  std::memcpy(&_rtXdot->Integrator_CSTATE[0],
              &codegenReal2Mission_B.ComputeDerivative[0], sizeof(real_T) << 3U);

  // Derivatives for Integrator: '<S9>/TD_Bank'
  _rtXdot->TD_Bank_CSTATE = codegenReal2Mission_B.dotBankTD;

  // Derivatives for Integrator: '<S9>/dotBankTD'
  _rtXdot->dotBankTD_CSTATE = codegenReal2Mission_B.fh_n4;

  // End of Derivatives for SubSystem: '<S1>/MissionSimUAV'

  // Derivatives for Atomic SubSystem: '<Root>/Real2SimGuidance'
  // Derivatives for Atomic SubSystem: '<S2>/SpeedControl'
  // Derivatives for Atomic SubSystem: '<S16>/ADRC'
  // Derivatives for Integrator: '<S75>/ESO'
  _rtXdot->ESO_CSTATE = codegenReal2Mission_B.ESOdotsum;

  // Derivatives for Integrator: '<S75>/ESO_dot'
  _rtXdot->ESO_dot_CSTATE = codegenReal2Mission_B.ESOdotdotsum;

  // Derivatives for Integrator: '<S75>/ESO_dotdot'
  _rtXdot->ESO_dotdot_CSTATE = codegenReal2Mission_B.Inverse;

  // Derivatives for Integrator: '<S77>/TD_AirSpdADRC'
  _rtXdot->TD_AirSpdADRC_CSTATE = codegenReal2Mission_B.dotTD;

  // Derivatives for Integrator: '<S77>/dotTD'
  _rtXdot->dotTD_CSTATE = codegenReal2Mission_B.fh_n;

  // End of Derivatives for SubSystem: '<S16>/ADRC'
  // End of Derivatives for SubSystem: '<S2>/SpeedControl'

  // Derivatives for Integrator: '<S18>/TD_Alt'
  _rtXdot->TD_Alt_CSTATE = codegenReal2Mission_B.dotAltTD;

  // Derivatives for Integrator: '<S18>/dotAltTD'
  _rtXdot->dotAltTD_CSTATE = codegenReal2Mission_B.fh;

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
    real_T rtb_ClockwiseRotation;
    int32_T i;
    codegenReal2Mission_PrevZCX.ESO_Reset_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.ESO_dot_Reset_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.ESO_dotdot_Reset_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.TD_AirSpdADRC_Reset_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.dotTD_Reset_ZCE = UNINITIALIZED_ZCSIG;

    // InitializeConditions for Memory: '<S1>/MemoryFlowerMode'
    codegenReal2Mission_DW.MemoryFlowerMode_PreviousInput = 50.0;

    // InitializeConditions for Delay: '<S1>/InitHdg'
    codegenReal2Mission_DW.icLoad = true;

    // SystemInitialize for Atomic SubSystem: '<S1>/MissionSimUAV'
    // InitializeConditions for RateLimiter: '<S4>/ClimbRateLimiter'
    codegenReal2Mission_DW.PrevY = 150.0;

    // InitializeConditions for Integrator: '<S8>/Integrator'
    std::memset(&codegenReal2Mission_X.Integrator_CSTATE[0], 0, sizeof(real_T) <<
                3U);

    // InitializeConditions for Integrator: '<S9>/TD_Bank'
    codegenReal2Mission_X.TD_Bank_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S9>/dotBankTD'
    codegenReal2Mission_X.dotBankTD_CSTATE = 0.0;

    // Start for MATLABSystem: '<S8>/ComputeDerivative'
    codegenReal2Mission_DW.obj_a.isInitialized = 0;
    codegenReal2Mission_DW.obj_a.isInitialized = 1;
    codegenReal2Mis_Model_resetImpl(&codegenReal2Mission_DW.obj_a);

    // InitializeConditions for MATLABSystem: '<S8>/ComputeDerivative'
    codegenReal2Mis_Model_resetImpl(&codegenReal2Mission_DW.obj_a);

    // Outputs for Atomic SubSystem: '<S4>/InitializeSimLocation'
    // DataStoreWrite: '<S6>/DSnumMissionUAV' incorporates:
    //   Constant: '<S6>/Number Of Mission UAV'

    codegenReal2Mission_DW.numMissionUAV = codegenReal2Mission_P.numMissionUAV;

    // DataStoreWrite: '<S6>/DSuavIDX' incorporates:
    //   Constant: '<S6>/UAVidx'

    codegenReal2Mission_DW.UAVidx = codegenReal2Mission_P.UAVidx;

    // DataStoreWrite: '<S6>/DSAltitudeGCS' incorporates:
    //   Constant: '<S6>/AltitudeGCS'

    codegenReal2Mission_DW.AltitudeGCS = codegenReal2Mission_P.GCS_Altitude;

    // DataStoreWrite: '<S6>/DSLatitudeGCS' incorporates:
    //   Constant: '<S6>/LatitudeGCS'

    codegenReal2Mission_DW.LatitudeGCS = codegenReal2Mission_P.GCS_Latitude;

    // DataStoreWrite: '<S6>/DSLongitudeGCS' incorporates:
    //   Constant: '<S6>/LongitudeGCS'

    codegenReal2Mission_DW.LongitudeGCS = codegenReal2Mission_P.GCS_Longitude;

    // Product: '<S6>/Map2Radian' incorporates:
    //   Bias: '<S6>/Bias'
    //   Constant: '<S6>/2pi'
    //   Constant: '<S6>/Number Of Mission UAV'
    //   Constant: '<S6>/UAVidx'
    //   DataTypeConversion: '<S6>/Cast To Double'
    //   Gain: '<S6>/Gain'
    //   Product: '<S6>/Divide'
    //   Sum: '<S6>/Minus'

    rtb_ClockwiseRotation = (static_cast<real_T>(codegenReal2Mission_P.UAVidx) -
      (codegenReal2Mission_P.numMissionUAV + 1.0) * 0.5) * (6.2831853071795862 /
      codegenReal2Mission_P.numMissionUAV);

    // StateWriter: '<S6>/SimUAVState' incorporates:
    //   Bias: '<S6>/ClockwiseRotation'
    //   Constant: '<S6>/InitialFlightPathAngle'
    //   Constant: '<S6>/InitialHeight'
    //   Constant: '<S6>/InitialRollAngle'
    //   Constant: '<S6>/InitialRollAngleRate'
    //   Constant: '<S6>/InitialUAVAirspeed'
    //   Constant: '<S6>/Radius'
    //   Product: '<S6>/EastDis'
    //   Product: '<S6>/NorthDis'
    //   Reshape: '<S6>/Reshape'
    //   Trigonometry: '<S6>/Cos'
    //   Trigonometry: '<S6>/Sin'

    codegenReal2Mission_X.Integrator_CSTATE[0] = std::cos(rtb_ClockwiseRotation)
      * 1000.0;
    codegenReal2Mission_X.Integrator_CSTATE[1] = 1000.0 * std::sin
      (rtb_ClockwiseRotation);
    codegenReal2Mission_X.Integrator_CSTATE[2] = 150.0;
    codegenReal2Mission_X.Integrator_CSTATE[3] = 35.0;
    codegenReal2Mission_X.Integrator_CSTATE[4] = rtb_ClockwiseRotation +
      1.5707963267948966;
    codegenReal2Mission_X.Integrator_CSTATE[5] = 0.0;
    codegenReal2Mission_X.Integrator_CSTATE[6] = 0.0;
    codegenReal2Mission_X.Integrator_CSTATE[7] = 0.0;
    rtsiSetBlockStateForSolverChangedAtMajorStep(&(&codegenReal2Mission_M)
      ->solverInfo, true);
    rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
      (&(&codegenReal2Mission_M)->solverInfo, true);

    // End of Outputs for SubSystem: '<S4>/InitializeSimLocation'
    // End of SystemInitialize for SubSystem: '<S1>/MissionSimUAV'

    // SystemInitialize for Atomic SubSystem: '<Root>/Real2SimGuidance'
    // SetupRuntimeResources for Scope: '<S2>/ModelLogging'
    {
      RTWLogSignalInfo rt_ScopeSignalInfo;
      static int_T rt_ScopeSignalWidths[] = { 8, 8, 1, 1, 3, 1, 1, 3, 1, 1 };

      static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1, 1, 2, 2, 1, 1, 1,
        1 };

      static int_T rt_ScopeSignalDimensions[] = { 8, 8, 1, 1, 3, 1, 1, 1, 1, 3,
        1, 1 };

      static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL), (NULL),
        (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL) };

      static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4 };

      static const char_T *rt_ScopeSignalLabels[] = { "RealUAVState_Log",
        "SimUAVState_Log",
        "RefAirspeed_Log",
        "LagDistance_Log",
        "LookAheadNED_Log",
        "CrossTrackError_Log",
        "EngagedFlag_Log",
        "Heading_Log",
        "ADRC_U_Log",
        "biasH_Log" };

      static char_T rt_ScopeSignalTitles[] =
        "RealUAVState_LogSimUAVState_LogRefAirspeed_LogLagDistance_LogLookAheadNED_LogCrossTrackError_LogEngagedFlag_LogHeading_LogADRC_U_LogbiasH_Log";
      static int_T rt_ScopeSignalTitleLengths[] = { 16, 15, 15, 15, 16, 19, 15,
        11, 10, 9 };

      static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0 };

      static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 };

      BuiltInDTypeId dTypes[10] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE,
        SS_DOUBLE, SS_DOUBLE, SS_BOOLEAN, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

      static char_T rt_ScopeBlockName[] =
        "codegenReal2Mission/Real2SimGuidance/ModelLogging";
      static int_T rt_ScopeFrameData[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

      static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
        (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL),
        (NULL), (NULL), (NULL)
      };

      rt_ScopeSignalInfo.numSignals = 10;
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

    // InitializeConditions for Integrator: '<S18>/TD_Alt'
    codegenReal2Mission_X.TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S18>/dotAltTD'
    codegenReal2Mission_X.dotAltTD_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<S2>/GenerateTrack'
    for (i = 0; i < 72; i++) {
      // InitializeConditions for S-Function (sfix_udelay): '<S13>/HeightSequence' 
      codegenReal2Mission_DW.HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<S2>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<S2>/SpeedControl'
    // SystemInitialize for Atomic SubSystem: '<S16>/ADRC'
    // InitializeConditions for Integrator: '<S75>/ESO'
    codegenReal2Mission_X.ESO_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S75>/ESO_dot'
    codegenReal2Mission_X.ESO_dot_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S75>/ESO_dotdot'
    codegenReal2Mission_X.ESO_dotdot_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S77>/TD_AirSpdADRC'
    codegenReal2Mission_X.TD_AirSpdADRC_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S77>/dotTD'
    codegenReal2Mission_X.dotTD_CSTATE = 0.0;

    // End of SystemInitialize for SubSystem: '<S16>/ADRC'
    // End of SystemInitialize for SubSystem: '<S2>/SpeedControl'

    // Start for MATLABSystem: '<S2>/TrackSimPath'
    codegenReal2Mission_DW.obj.LastWaypointFlag = false;
    codegenReal2Mission_DW.obj.StartFlag = true;
    codegenReal2Mission_DW.obj.LookaheadFactor = 1.01;
    codegenReal2Mission_DW.obj.SearchFlag = true;
    codegenReal2Mission_DW.obj.isInitialized = 0;
    codegenReal2Mission_DW.obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S2>/TrackSimPath'
    codegenReal2Mission_DW.obj.WaypointIndex = 1.0;
    for (i = 0; i < 219; i++) {
      // Start for MATLABSystem: '<S2>/TrackSimPath'
      codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);

      // InitializeConditions for MATLABSystem: '<S2>/TrackSimPath'
      codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<Root>/Real2SimGuidance'

    // Start for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.isInitialized = 0;
    codegenReal2Mission_DW.obj_m.isInitialized = 1;
    codegenReal2Mission_DW.obj_m.PrevResetSignal = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_m.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevResetSignal *= 0.0;
    codegenReal2Mission_DW.obj_m.NumCircles *= 0.0;

    // Start for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[0] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[0] *= 0.0;

    // Start for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[1] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[1] *= 0.0;

    // Start for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[2] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S1>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[2] *= 0.0;
    codegenReal2Mission_DW.obj_m.StartFlag = true;
    codegenReal2Mission_DW.obj_m.SelectTurnDirectionFlag = true;
    codegenReal2Mission_DW.obj_m.TurnDirectionInternal = 1.0;
    codegenReal2Mission_DW.obj_m.OrbitRadiusFlag = 0U;
    codegenReal2Mission_DW.obj_m.LookaheadDistFlag = 0U;
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
