//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.137
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 22 20:09:14 2021
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

// Named constants for Chart: '<S3>/Chart'
const uint8_T codegenReal2Mission_IN_Circle = 1U;
const uint8_T codegenReal2Mission_IN_Flower = 2U;

// Named constants for Chart: '<Root>/TASgreaterthan15for1Sec'
const uint8_T codegenReal2Missi_IN_NotTakeOff = 2U;
const uint8_T codegenReal2Mission_IN_InAir = 1U;

// Named constants for Chart: '<Root>/TriggerTermination'
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
  int_T nXc = 15;
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
//    '<S17>/fhan(v1-v0,v2,r0,h)1'
//    '<S74>/fhan(e1,ce2,r,h1)'
//    '<S75>/fhan(v1-v0,v2,r0,h)1'
//
void codegenReal2MissionModelClass::codegenReal2Miss_fhanv1v0v2r0h1(real_T rtu_u,
  real_T rtu_u_n, real_T rtu_u_f, real_T rtu_u_c, real_T *rty_fh)
{
  real_T a0;
  real_T a2;
  real_T d;
  real_T u;
  real_T y;
  real_T y_0;

  // SignalConversion generated from: '<S18>/ SFunction '
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

  // SignalConversion generated from: '<S18>/ SFunction '
  *rty_fh = (a0 / d - y) * -rtu_u_f * ((y_0 - u) / 2.0) - rtu_u_f * y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

//
// Output and update for atomic system:
//    '<S73>/fal(e,0.25,h)'
//    '<S73>/fal(e,0.5,h)'
//
void codegenReal2MissionModelClass::codegenReal2Mission_fale025h(real_T rtu_u,
  real_T rtu_u_a, real_T rtu_u_c, real_T *rty_y)
{
  real_T rtu_u_0;
  real_T tmp;

  // SignalConversion generated from: '<S76>/ SFunction '
  tmp = std::abs(rtu_u);
  if (tmp <= rtu_u_c) {
    *rty_y = rtu_u / rt_powd_snf(rtu_u_c, 1.0 - rtu_u_a);
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

    *rty_y = rt_powd_snf(tmp, rtu_u_a) * rtu_u_0;
  }

  // End of SignalConversion generated from: '<S76>/ SFunction '
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = std::fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > std::floor(u1))) {
      q = std::abs(u0 / u1);
      yEq = !(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

void codegenReal2MissionModelClass::WaypointFollowerBase_getDistinc(const real_T
  waypoints[183], real_T distinctWpts_data[], int32_T distinctWpts_size[2])
{
  int32_T i1;
  int32_T i2;
  int32_T ix;
  int32_T j;
  int32_T x_tmp;
  int8_T c_data[61];
  boolean_T x[183];
  boolean_T b[61];
  boolean_T exitg1;
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < 60; i2++) {
      x_tmp = 61 * i1 + i2;
      x[x_tmp] = (waypoints[((i2 + 2) + 61 * i1) - 1] != waypoints[x_tmp]);
    }

    x[61 * i1 + 60] = true;
  }

  i1 = 0;
  i2 = 122;
  x_tmp = 0;
  for (j = 0; j < 61; j++) {
    b[j] = false;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!x[ix - 1]) {
        ix += 61;
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
  for (i2 = 0; i2 < 61; i2++) {
    if (b[i2]) {
      c_data[i1] = static_cast<int8_T>(i2 + 1);
      i1++;
    }
  }

  distinctWpts_size[0] = x_tmp;
  distinctWpts_size[1] = 3;
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < x_tmp; i2++) {
      distinctWpts_data[i2 + distinctWpts_size[0] * i1] = waypoints[(61 * i1 +
        c_data[i2]) - 1];
    }
  }
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

// Function for MATLAB Function: '<Root>/AngLog'
real_T codegenReal2MissionModelClass::codegenReal2Mission_angdiff(real_T x,
  real_T y)
{
  real_T delta;
  real_T q;
  real_T thetaWrap;
  boolean_T rEQ0;
  delta = y - x;
  if (std::abs(delta) > 3.1415926535897931) {
    if (rtIsNaN(delta + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (rtIsInf(delta + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (delta + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      thetaWrap = std::fmod(delta + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        q = std::abs((delta + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (delta + 3.1415926535897931 < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }

    if ((thetaWrap == 0.0) && (delta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    delta = thetaWrap - 3.1415926535897931;
  }

  return delta;
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
    emxArray_real_T_codegenReal2M_T *d;
    real_T b_waypointsIn_data[183];
    real_T rtb_MatrixConcatenate[183];
    real_T appendedWaypoints_data[6];
    real_T b_waypointsIn[3];
    real_T rtb_Sum_c[3];
    real_T rtb_Sum_o[3];
    real_T rtb_TmpSignalConversionAtTrac_1[3];
    real_T rtb_TmpSignalConversionAtTrac_2[3];
    real_T distToCenter_tmp[2];
    real_T rtb_TmpSignalConversionAtTrac_0[2];
    real_T q;
    real_T rtb_Abs1_i;
    real_T rtb_Abs1_n;
    real_T rtb_East;
    real_T rtb_FlightPathAngle;
    real_T rtb_HeadingAngle;
    real_T rtb_HeadingAngle_g_tmp;
    real_T rtb_HeadingAngle_n;
    real_T rtb_Height;
    real_T rtb_Height_m;
    real_T rtb_Integrator1;
    real_T rtb_LookaheadT;
    real_T rtb_North_l;
    real_T rtb_Output;
    real_T rtb_RealHdg_Log;
    real_T rtb_RollAngle_p;
    real_T rtb_Sum1_b_idx_0;
    real_T rtb_Switch_c;
    real_T rtb_TargetHdg_Log;
    real_T turnVector_idx_0;
    real_T turnVector_idx_1;
    real_T turnVector_idx_2;
    int32_T b_waypointsIn_size[2];
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T b_exponent_1;
    int32_T b_exponent_2;
    int32_T b_idx;
    int32_T i;
    int32_T loop_ub;
    int32_T waypoints;
    int32_T waypoints_size_idx_0;
    boolean_T exitg1;
    boolean_T guard1 = false;
    boolean_T guard2 = false;
    boolean_T p;
    boolean_T rEQ0;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Outputs for Atomic SubSystem: '<Root>/LatLon2NorthEast'
      // BusCreator: '<S5>/FixedWingGuidanceStateBus' incorporates:
      //   Gain: '<S19>/Gain1'
      //   Gain: '<S20>/Gain1'
      //   Gain: '<S21>/Gain1'
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_HeadingAngle = 0.017453292519943295 *
        codegenReal2Mission_U.RealUAVLatLonState.HeadingAngle_deg;
      rtb_FlightPathAngle = 0.017453292519943295 *
        codegenReal2Mission_U.RealUAVLatLonState.FlightPathAngle_deg;
      rtb_RollAngle_p = 0.017453292519943295 *
        codegenReal2Mission_U.RealUAVLatLonState.RollAngle_deg;

      // Gain: '<S5>/inverse' incorporates:
      //   DataStoreRead: '<S5>/AltitudeGCS'

      rtb_HeadingAngle_n = -codegenReal2Mission_DW.AltitudeGCS;

      // BusCreator: '<S5>/FixedWingGuidanceStateBus' incorporates:
      //   Gain: '<S5>/Down2Up'
      //   Inport: '<Root>/RealUAVLatLonState'
      //   Sum: '<S22>/Sum'

      rtb_Height = codegenReal2Mission_U.RealUAVLatLonState.Height_meter +
        rtb_HeadingAngle_n;

      // Abs: '<S36>/Abs' incorporates:
      //   DataStoreRead: '<S5>/LatitudeGCS'

      rtb_Switch_c = std::abs(codegenReal2Mission_DW.LatitudeGCS);

      // Switch: '<S36>/Switch' incorporates:
      //   Bias: '<S36>/Bias'
      //   Bias: '<S36>/Bias1'
      //   Constant: '<S36>/Constant2'
      //   Constant: '<S37>/Constant'
      //   DataStoreRead: '<S5>/LatitudeGCS'
      //   Math: '<S36>/Math Function1'
      //   RelationalOperator: '<S37>/Compare'

      if (rtb_Switch_c > 180.0) {
        rtb_Switch_c = rt_modd_snf(codegenReal2Mission_DW.LatitudeGCS + 180.0,
          360.0) + -180.0;
      } else {
        rtb_Switch_c = codegenReal2Mission_DW.LatitudeGCS;
      }

      // End of Switch: '<S36>/Switch'

      // Abs: '<S33>/Abs1'
      rtb_Abs1_i = std::abs(rtb_Switch_c);

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

      if (rtb_Abs1_i > 90.0) {
        // Signum: '<S33>/Sign1'
        if (rtb_Switch_c < 0.0) {
          rtb_Switch_c = -1.0;
        } else if (rtb_Switch_c > 0.0) {
          rtb_Switch_c = 1.0;
        } else if (rtb_Switch_c == 0.0) {
          rtb_Switch_c = 0.0;
        } else {
          rtb_Switch_c = (rtNaN);
        }

        // End of Signum: '<S33>/Sign1'
        rtb_Switch_c *= -(rtb_Abs1_i + -90.0) + 90.0;
        rtb_Height_m = 180.0;
      } else {
        rtb_Height_m = 0.0;
      }

      // End of Switch: '<S33>/Switch'

      // Sum: '<S24>/Sum' incorporates:
      //   DataStoreRead: '<S5>/LongitudeGCS'

      rtb_Abs1_i = rtb_Height_m + codegenReal2Mission_DW.LongitudeGCS;

      // Abs: '<S34>/Abs'
      rtb_Height_m = std::abs(rtb_Abs1_i);

      // Switch: '<S34>/Switch' incorporates:
      //   Bias: '<S34>/Bias'
      //   Bias: '<S34>/Bias1'
      //   Constant: '<S34>/Constant2'
      //   Constant: '<S38>/Constant'
      //   Math: '<S34>/Math Function1'
      //   RelationalOperator: '<S38>/Compare'

      if (rtb_Height_m > 180.0) {
        rtb_Abs1_i = rt_modd_snf(rtb_Abs1_i + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S34>/Switch'

      // Sum: '<S22>/Sum1' incorporates:
      //   Inport: '<Root>/RealUAVLatLonState'

      rtb_Sum1_b_idx_0 = codegenReal2Mission_U.RealUAVLatLonState.Latitude_deg -
        rtb_Switch_c;

      // Abs: '<S30>/Abs'
      rtb_Height_m = std::abs(rtb_Sum1_b_idx_0);

      // Switch: '<S30>/Switch' incorporates:
      //   Bias: '<S30>/Bias'
      //   Bias: '<S30>/Bias1'
      //   Constant: '<S30>/Constant2'
      //   Constant: '<S31>/Constant'
      //   Math: '<S30>/Math Function1'
      //   RelationalOperator: '<S31>/Compare'

      if (rtb_Height_m > 180.0) {
        rtb_Sum1_b_idx_0 = rt_modd_snf(rtb_Sum1_b_idx_0 + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S30>/Switch'

      // Abs: '<S27>/Abs1'
      rtb_Abs1_n = std::abs(rtb_Sum1_b_idx_0);

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

      if (rtb_Abs1_n > 90.0) {
        // Signum: '<S27>/Sign1'
        if (rtb_Sum1_b_idx_0 < 0.0) {
          rtb_Sum1_b_idx_0 = -1.0;
        } else if (rtb_Sum1_b_idx_0 > 0.0) {
          rtb_Sum1_b_idx_0 = 1.0;
        } else if (rtb_Sum1_b_idx_0 == 0.0) {
          rtb_Sum1_b_idx_0 = 0.0;
        } else {
          rtb_Sum1_b_idx_0 = (rtNaN);
        }

        // End of Signum: '<S27>/Sign1'
        rtb_Height_m = (-(rtb_Abs1_n + -90.0) + 90.0) * rtb_Sum1_b_idx_0;
        rtb_Abs1_n = 180.0;
      } else {
        rtb_Height_m = rtb_Sum1_b_idx_0;
        rtb_Abs1_n = 0.0;
      }

      // End of Switch: '<S27>/Switch'

      // Sum: '<S23>/Sum' incorporates:
      //   Inport: '<Root>/RealUAVLatLonState'
      //   Sum: '<S22>/Sum1'

      rtb_Abs1_i = (codegenReal2Mission_U.RealUAVLatLonState.Longitude_deg -
                    rtb_Abs1_i) + rtb_Abs1_n;

      // Abs: '<S28>/Abs'
      rtb_Abs1_n = std::abs(rtb_Abs1_i);

      // Switch: '<S28>/Switch' incorporates:
      //   Bias: '<S28>/Bias'
      //   Bias: '<S28>/Bias1'
      //   Constant: '<S28>/Constant2'
      //   Constant: '<S32>/Constant'
      //   Math: '<S28>/Math Function1'
      //   RelationalOperator: '<S32>/Compare'

      if (rtb_Abs1_n > 180.0) {
        rtb_Abs1_i = rt_modd_snf(rtb_Abs1_i + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S28>/Switch'

      // UnitConversion: '<S26>/Unit Conversion'
      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Sum1_b_idx_0 = 0.017453292519943295 * rtb_Height_m;

      // UnitConversion: '<S41>/Unit Conversion'
      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Switch_c *= 0.017453292519943295;

      // Trigonometry: '<S42>/Trigonometric Function1'
      rtb_Height_m = std::sin(rtb_Switch_c);

      // Sum: '<S42>/Sum1' incorporates:
      //   Constant: '<S42>/Constant'
      //   Product: '<S42>/Product1'

      rtb_Height_m = 1.0 - codegenReal2Mission_ConstB.sqrt_c *
        codegenReal2Mission_ConstB.sqrt_c * rtb_Height_m * rtb_Height_m;

      // Sqrt: '<S40>/sqrt'
      rtb_Abs1_n = std::sqrt(rtb_Height_m);

      // Product: '<S40>/Product1' incorporates:
      //   Constant: '<S40>/Constant1'

      rtb_Abs1_n = 6.378137E+6 / rtb_Abs1_n;

      // Product: '<S25>/dNorth' incorporates:
      //   Constant: '<S40>/Constant2'
      //   Product: '<S40>/Product3'
      //   Trigonometry: '<S40>/Trigonometric Function1'

      rtb_Height_m = rtb_Sum1_b_idx_0 / rt_atan2d_snf(1.0, rtb_Abs1_n *
        codegenReal2Mission_ConstB.Sum1_m / rtb_Height_m);

      // Product: '<S25>/dEast' incorporates:
      //   Constant: '<S40>/Constant3'
      //   Product: '<S40>/Product4'
      //   Trigonometry: '<S40>/Trigonometric Function'
      //   Trigonometry: '<S40>/Trigonometric Function2'
      //   UnitConversion: '<S26>/Unit Conversion'

      rtb_Switch_c = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_n * std::cos(rtb_Switch_c))
        * (0.017453292519943295 * rtb_Abs1_i);

      // BusCreator: '<S5>/FixedWingGuidanceStateBus' incorporates:
      //   Inport: '<Root>/RealUAVLatLonState'
      //   Product: '<S25>/x*cos'
      //   Product: '<S25>/x*sin'
      //   Product: '<S25>/y*cos'
      //   Product: '<S25>/y*sin'
      //   Sum: '<S25>/Sum2'
      //   Sum: '<S25>/Sum3'

      rtb_Abs1_n = rtb_Height_m * codegenReal2Mission_ConstB.SinCos_o2_o +
        rtb_Switch_c * codegenReal2Mission_ConstB.SinCos_o1_l;
      rtb_Switch_c = rtb_Switch_c * codegenReal2Mission_ConstB.SinCos_o2_o -
        rtb_Height_m * codegenReal2Mission_ConstB.SinCos_o1_l;
      rtb_Abs1_i = codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps;

      // End of Outputs for SubSystem: '<Root>/LatLon2NorthEast'

      // Chart: '<Root>/TASgreaterthan15for1Sec' incorporates:
      //   BusCreator: '<S5>/FixedWingGuidanceStateBus'
      //   Inport: '<Root>/RealUAVLatLonState'

      if (codegenReal2Mission_DW.is_active_c1_codegenReal2Missio == 0U) {
        codegenReal2Mission_DW.is_active_c1_codegenReal2Missio = 1U;
        codegenReal2Mission_DW.is_c1_codegenReal2Mission =
          codegenReal2Missi_IN_NotTakeOff;
        codegenReal2Mission_B.TakeOffTrigger = false;
        codegenReal2Mission_DW.DataCounter_j = 0.0;
      } else if (codegenReal2Mission_DW.is_c1_codegenReal2Mission == 1) {
        codegenReal2Mission_B.TakeOffTrigger = true;

        // case IN_NotTakeOff:
      } else if (codegenReal2Mission_DW.DataCounter_j >= 9.0) {
        codegenReal2Mission_DW.is_c1_codegenReal2Mission =
          codegenReal2Mission_IN_InAir;
        codegenReal2Mission_B.TakeOffTrigger = true;
      } else {
        // Outputs for Atomic SubSystem: '<Root>/LatLon2NorthEast'
        if (codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps < 15.0) {
          codegenReal2Mission_DW.is_c1_codegenReal2Mission =
            codegenReal2Missi_IN_NotTakeOff;
          codegenReal2Mission_B.TakeOffTrigger = false;
          codegenReal2Mission_DW.DataCounter_j = 0.0;
        } else {
          codegenReal2Mission_B.TakeOffTrigger = false;
          codegenReal2Mission_DW.DataCounter_j++;
        }

        // End of Outputs for SubSystem: '<Root>/LatLon2NorthEast'
      }

      // End of Chart: '<Root>/TASgreaterthan15for1Sec'

      // Memory: '<S3>/Memory'
      rtb_East = codegenReal2Mission_DW.Memory_PreviousInput;

      // DataTypeConversion: '<S3>/Cast To Double' incorporates:
      //   DataStoreRead: '<S3>/UAVidx'

      rtb_North_l = codegenReal2Mission_DW.UAVidx;

      // Delay: '<S3>/Delay'
      if (codegenReal2Mission_DW.icLoad) {
        // BusCreator: '<S3>/Bus Creator' incorporates:
        //   Bias: '<S3>/Bias'
        //   Bias: '<S3>/Rotate90Deg'
        //   Constant: '<S3>/2pi'
        //   DataStoreRead: '<S3>/numMissionUAV'
        //   Gain: '<S3>/FindMiddle'
        //   Product: '<S3>/Divide'
        //   Product: '<S3>/Map2Radian'
        //   Sum: '<S3>/Minus'

        codegenReal2Mission_DW.Delay_DSTATE = (rtb_North_l -
          (codegenReal2Mission_DW.numMissionUAV + 1.0) * 0.5) *
          (6.2831853071795862 / codegenReal2Mission_DW.numMissionUAV) +
          1.5707963267948966;
      }

      // End of Delay: '<S3>/Delay'

      // Outputs for Atomic SubSystem: '<S3>/MissionSimUAV'
      // Saturate: '<S12>/AirspeedSaturation' incorporates:
      //   BusCreator: '<S3>/Bus Creator'
      //   Constant: '<S3>/MissionAirspeed'

      codegenReal2Mission_B.Airspeed = 35.0;

      // Saturate: '<S12>/AltitudeSaturation' incorporates:
      //   BusCreator: '<S3>/Bus Creator'

      if (rtb_East > 500.0) {
        rtb_LookaheadT = 500.0;
      } else if (rtb_East < 100.0) {
        rtb_LookaheadT = 100.0;
      } else {
        rtb_LookaheadT = rtb_East;
      }

      // End of Saturate: '<S12>/AltitudeSaturation'

      // RateLimiter: '<S12>/ClimbRateLimiter'
      rtb_Sum1_b_idx_0 = rtb_LookaheadT - codegenReal2Mission_DW.PrevY;
      if (rtb_Sum1_b_idx_0 > 0.75) {
        // RateLimiter: '<S12>/ClimbRateLimiter'
        codegenReal2Mission_B.ClimbRateLimiter = codegenReal2Mission_DW.PrevY +
          0.75;
      } else if (rtb_Sum1_b_idx_0 < -0.75) {
        // RateLimiter: '<S12>/ClimbRateLimiter'
        codegenReal2Mission_B.ClimbRateLimiter = codegenReal2Mission_DW.PrevY +
          -0.75;
      } else {
        // RateLimiter: '<S12>/ClimbRateLimiter'
        codegenReal2Mission_B.ClimbRateLimiter = rtb_LookaheadT;
      }

      codegenReal2Mission_DW.PrevY = codegenReal2Mission_B.ClimbRateLimiter;

      // End of RateLimiter: '<S12>/ClimbRateLimiter'

      // BusCreator: '<S12>/FixedWingGuidanceEnvironmentBus' incorporates:
      //   Constant: '<S12>/Gravity'
      //   Constant: '<S12>/NoWind'

      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth = 0.0;
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast = 0.0;
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown = 0.0;
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity = 9.807;

      // End of Outputs for SubSystem: '<S3>/MissionSimUAV'
    }

    // Outputs for Atomic SubSystem: '<S3>/MissionSimUAV'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // MATLAB Function: '<S12>/SimHeadingControl' incorporates:
      //   BusCreator: '<S3>/Bus Creator'
      //   Integrator: '<S16>/Integrator'

      rtb_Sum1_b_idx_0 = 1.0 / codegenReal2Mission_X.Integrator_CSTATE_g[3];
      rtb_East = std::cos(codegenReal2Mission_X.Integrator_CSTATE_g[5]);
      rtb_North_l = std::sin(codegenReal2Mission_X.Integrator_CSTATE_g[4]);
      rtb_Integrator1 = std::cos(codegenReal2Mission_X.Integrator_CSTATE_g[4]);
      rtb_East = (rtb_Integrator1 * rtb_East *
                  codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth
                  + rtb_North_l * rtb_East *
                  codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast)
        + -std::sin(codegenReal2Mission_X.Integrator_CSTATE_g[5]) *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown;
      rtb_Height_m = codegenReal2Mission_DW.Delay_DSTATE -
        codegenReal2Mission_X.Integrator_CSTATE_g[4];
      if (std::abs(rtb_Height_m) > 3.1415926535897931) {
        if (rtIsNaN(rtb_Height_m + 3.1415926535897931)) {
          rtb_Output = (rtNaN);
        } else if (rtIsInf(rtb_Height_m + 3.1415926535897931)) {
          rtb_Output = (rtNaN);
        } else if (rtb_Height_m + 3.1415926535897931 == 0.0) {
          rtb_Output = 0.0;
        } else {
          rtb_Output = std::fmod(rtb_Height_m + 3.1415926535897931,
            6.2831853071795862);
          rEQ0 = (rtb_Output == 0.0);
          if (!rEQ0) {
            q = std::abs((rtb_Height_m + 3.1415926535897931) /
                         6.2831853071795862);
            rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 *
                     q);
          }

          if (rEQ0) {
            rtb_Output = 0.0;
          } else if (rtb_Height_m + 3.1415926535897931 < 0.0) {
            rtb_Output += 6.2831853071795862;
          }
        }

        if ((rtb_Output == 0.0) && (rtb_Height_m + 3.1415926535897931 > 0.0)) {
          rtb_Output = 6.2831853071795862;
        }

        rtb_Height_m = rtb_Output - 3.1415926535897931;
      }

      codegenReal2Mission_B.RollAngle = rt_atan2d_snf((std::sqrt(rtb_East *
        rtb_East -
        (((codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth *
           codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth +
           codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast *
           codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast) +
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown *
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown) -
         codegenReal2Mission_X.Integrator_CSTATE_g[3] *
         codegenReal2Mission_X.Integrator_CSTATE_g[3])) + -rtb_East) * (0.39 *
        rtb_Height_m), std::cos(codegenReal2Mission_X.Integrator_CSTATE_g[4] -
        (codegenReal2Mission_X.Integrator_CSTATE_g[4] - std::asin
         (rtb_Sum1_b_idx_0 *
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth *
          -rtb_North_l + rtb_Sum1_b_idx_0 *
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast *
          rtb_Integrator1))) *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity);

      // Saturate: '<S12>/RollAngleSaturation'
      if (codegenReal2Mission_B.RollAngle > 0.3490658503988659) {
        // MATLAB Function: '<S12>/SimHeadingControl' incorporates:
        //   Saturate: '<S12>/RollAngleSaturation'

        codegenReal2Mission_B.RollAngle = 0.3490658503988659;
      } else if (codegenReal2Mission_B.RollAngle < -0.3490658503988659) {
        // MATLAB Function: '<S12>/SimHeadingControl' incorporates:
        //   Saturate: '<S12>/RollAngleSaturation'

        codegenReal2Mission_B.RollAngle = -0.3490658503988659;
      }

      // End of Saturate: '<S12>/RollAngleSaturation'
    }

    // MATLABSystem: '<S16>/ComputeDerivative' incorporates:
    //   BusCreator: '<S12>/Slew Guidance Bus'
    //   Integrator: '<S16>/Integrator'
    //   Integrator: '<S17>/Integrator3'

    rtb_East = std::sin(codegenReal2Mission_X.Integrator_CSTATE_g[5]);
    rtb_Sum1_b_idx_0 = std::cos(codegenReal2Mission_X.Integrator_CSTATE_g[5]);
    rtb_Integrator1 = std::cos(codegenReal2Mission_X.Integrator_CSTATE_g[4]);
    rtb_HeadingAngle_n = std::sin(codegenReal2Mission_X.Integrator_CSTATE_g[4]);
    rtb_Height_m = (-(rtb_Integrator1 * rtb_Sum1_b_idx_0) *
                    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth
                    + -(rtb_HeadingAngle_n * rtb_Sum1_b_idx_0) *
                    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast)
      + rtb_East *
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown;
    rtb_Height_m = std::sqrt(rtb_Height_m * rtb_Height_m -
      (((codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth *
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth +
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast *
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast) +
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown) -
       codegenReal2Mission_X.Integrator_CSTATE_g[3] *
       codegenReal2Mission_X.Integrator_CSTATE_g[3])) + -rtb_Height_m;
    codegenReal2Mission_B.ComputeDerivative[0] = rtb_Height_m * rtb_Integrator1 *
      rtb_Sum1_b_idx_0;
    codegenReal2Mission_B.ComputeDerivative[1] = rtb_Height_m *
      rtb_HeadingAngle_n * rtb_Sum1_b_idx_0;
    codegenReal2Mission_B.ComputeDerivative[2] = rtb_Height_m * rtb_East;
    codegenReal2Mission_B.ComputeDerivative[3] = (codegenReal2Mission_B.Airspeed
      - codegenReal2Mission_X.Integrator_CSTATE_g[3]) *
      codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PAirSpeed;
    if (rtb_Height_m == 0.0) {
      codegenReal2Mission_B.ComputeDerivative[4] = 0.0;
      codegenReal2Mission_B.ComputeDerivative[5] = 0.0;
    } else {
      if (codegenReal2Mission_X.Integrator_CSTATE_g[3] == 0.0) {
        codegenReal2Mission_B.ComputeDerivative[4] = 0.0;
      } else {
        rtb_Sum1_b_idx_0 = 1.0 / (std::cos(std::asin((rtb_Height_m * rtb_East +
          codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown) /
          codegenReal2Mission_X.Integrator_CSTATE_g[3])) *
          codegenReal2Mission_X.Integrator_CSTATE_g[3]);
        codegenReal2Mission_B.ComputeDerivative[4] = std::cos(std::asin
          (rtb_Sum1_b_idx_0 *
           codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth *
           -std::sin(codegenReal2Mission_X.Integrator_CSTATE_g[4]) +
           rtb_Sum1_b_idx_0 *
           codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast *
           rtb_Integrator1)) *
          (codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity /
           rtb_Height_m * std::tan(codegenReal2Mission_X.Integrator_CSTATE_g[6]));
      }

      q = (codegenReal2Mission_B.ClimbRateLimiter -
           codegenReal2Mission_X.Integrator_CSTATE_g[2]) *
        codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PHeight /
        rtb_Height_m;
      if (!(q < 1.0)) {
        q = 1.0;
      }

      if (!(q > -1.0)) {
        q = -1.0;
      }

      q = std::asin(q);
      if ((!(q <
             codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
             [1])) && (!rtIsNaN
                       (codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
                        [1]))) {
        q =
          codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
          [1];
      }

      if ((!(q >
             codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
             [0])) && (!rtIsNaN
                       (codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
                        [0]))) {
        q =
          codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
          [0];
      }

      codegenReal2Mission_B.ComputeDerivative[5] = (q -
        codegenReal2Mission_X.Integrator_CSTATE_g[5]) *
        codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PFlightPathAngle;
    }

    codegenReal2Mission_B.ComputeDerivative[6] =
      codegenReal2Mission_X.Integrator_CSTATE_g[7];
    if (codegenReal2Mission_X.Integrator3_CSTATE_b < 1.5707963267948966) {
      rtb_North_l = codegenReal2Mission_X.Integrator3_CSTATE_b;
    } else {
      rtb_North_l = 1.5707963267948966;
    }

    if (!(rtb_North_l > -1.5707963267948966)) {
      rtb_North_l = -1.5707963267948966;
    }

    codegenReal2Mission_B.ComputeDerivative[7] = (rtb_North_l -
      codegenReal2Mission_X.Integrator_CSTATE_g[6]) *
      codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PDRoll[0] +
      codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PDRoll[1] *
      -codegenReal2Mission_X.Integrator_CSTATE_g[7];

    // End of MATLABSystem: '<S16>/ComputeDerivative'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // ZeroOrderHold: '<S12>/SimUAVStateZOH' incorporates:
      //   Integrator: '<S16>/Integrator'

      codegenReal2Mission_B.SimUAVStateZOH.North =
        codegenReal2Mission_X.Integrator_CSTATE_g[0];
      codegenReal2Mission_B.SimUAVStateZOH.East =
        codegenReal2Mission_X.Integrator_CSTATE_g[1];
      codegenReal2Mission_B.SimUAVStateZOH.Height =
        codegenReal2Mission_X.Integrator_CSTATE_g[2];
      codegenReal2Mission_B.SimUAVStateZOH.AirSpeed =
        codegenReal2Mission_X.Integrator_CSTATE_g[3];
      codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle =
        codegenReal2Mission_X.Integrator_CSTATE_g[4];
      codegenReal2Mission_B.SimUAVStateZOH.FlightPathAngle =
        codegenReal2Mission_X.Integrator_CSTATE_g[5];
      codegenReal2Mission_B.SimUAVStateZOH.RollAngle =
        codegenReal2Mission_X.Integrator_CSTATE_g[6];
      codegenReal2Mission_B.SimUAVStateZOH.RollAngleRate =
        codegenReal2Mission_X.Integrator_CSTATE_g[7];
    }

    // Integrator: '<S17>/Integrator2'
    codegenReal2Mission_B.Integrator2_e =
      codegenReal2Mission_X.Integrator2_CSTATE_n;

    // MATLAB Function: '<S17>/fhan(v1-v0,v2,r0,h)1' incorporates:
    //   Constant: '<S17>/Constant2'
    //   Constant: '<S17>/Constant3'
    //   Integrator: '<S17>/Integrator3'
    //   Sum: '<S17>/Sum1'

    codegenReal2Miss_fhanv1v0v2r0h1(codegenReal2Mission_X.Integrator3_CSTATE_b -
      codegenReal2Mission_B.RollAngle, codegenReal2Mission_B.Integrator2_e,
      0.087266462599716474, 0.1, &codegenReal2Mission_B.fh_n);

    // End of Outputs for SubSystem: '<S3>/MissionSimUAV'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Outputs for Atomic SubSystem: '<Root>/GenerateTrack'
      // S-Function (sfix_udelay): '<S4>/EastSequence'
      rtb_MatrixConcatenate[121] = codegenReal2Mission_B.SimUAVStateZOH.East;

      // Gain: '<S4>/Gain7'
      codegenReal2Mission_B.Gain7 = -codegenReal2Mission_B.SimUAVStateZOH.Height;

      // S-Function (sfix_udelay): '<S4>/HeightSequence'
      rtb_MatrixConcatenate[182] = codegenReal2Mission_B.Gain7;
      for (i = 0; i < 60; i++) {
        // S-Function (sfix_udelay): '<S4>/EastSequence'
        rtb_MatrixConcatenate[i + 61] = codegenReal2Mission_DW.EastSequence_X[i];

        // S-Function (sfix_udelay): '<S4>/HeightSequence'
        rtb_MatrixConcatenate[i + 122] =
          codegenReal2Mission_DW.HeightSequence_X[i];

        // S-Function (sfix_udelay): '<S4>/NorthSequence'
        rtb_MatrixConcatenate[i] = codegenReal2Mission_DW.NorthSequence_X[i];
      }

      // S-Function (sfix_udelay): '<S4>/NorthSequence'
      rtb_MatrixConcatenate[60] = codegenReal2Mission_B.SimUAVStateZOH.North;
      for (i = 0; i < 59; i++) {
        // Update for S-Function (sfix_udelay): '<S4>/EastSequence'
        codegenReal2Mission_DW.EastSequence_X[i] =
          codegenReal2Mission_DW.EastSequence_X[i + 1];

        // Update for S-Function (sfix_udelay): '<S4>/HeightSequence'
        codegenReal2Mission_DW.HeightSequence_X[i] =
          codegenReal2Mission_DW.HeightSequence_X[i + 1];

        // Update for S-Function (sfix_udelay): '<S4>/NorthSequence'
        codegenReal2Mission_DW.NorthSequence_X[i] =
          codegenReal2Mission_DW.NorthSequence_X[i + 1];
      }

      // Update for S-Function (sfix_udelay): '<S4>/EastSequence'
      codegenReal2Mission_DW.EastSequence_X[59] =
        codegenReal2Mission_B.SimUAVStateZOH.East;

      // Update for S-Function (sfix_udelay): '<S4>/HeightSequence'
      codegenReal2Mission_DW.HeightSequence_X[59] = codegenReal2Mission_B.Gain7;

      // Update for S-Function (sfix_udelay): '<S4>/NorthSequence'
      codegenReal2Mission_DW.NorthSequence_X[59] =
        codegenReal2Mission_B.SimUAVStateZOH.North;

      // End of Outputs for SubSystem: '<Root>/GenerateTrack'

      // Outputs for Atomic SubSystem: '<Root>/SpeedControl'
      // Sum: '<S69>/Sum' incorporates:
      //   BusCreator: '<S5>/FixedWingGuidanceStateBus'

      rtb_Sum_o[0] = codegenReal2Mission_B.SimUAVStateZOH.North - rtb_Abs1_n;
      rtb_Sum_o[1] = codegenReal2Mission_B.SimUAVStateZOH.East - rtb_Switch_c;
      rtb_Sum_o[2] = codegenReal2Mission_B.SimUAVStateZOH.Height - rtb_Height;

      // DotProduct: '<S69>/Dot Product'
      rtb_Output = rtb_Sum_o[0] * rtb_Sum_o[0];

      // Outputs for Atomic SubSystem: '<Root>/GenerateTrack'
      // Selector: '<S7>/WayPoint0d3' incorporates:
      //   S-Function (sfix_udelay): '<S4>/NorthSequence'
      //   Sum: '<S72>/Sum'

      rtb_Sum_o[0] = codegenReal2Mission_B.SimUAVStateZOH.North;

      // End of Outputs for SubSystem: '<Root>/GenerateTrack'

      // DotProduct: '<S69>/Dot Product'
      rtb_Output += rtb_Sum_o[1] * rtb_Sum_o[1];

      // Selector: '<S7>/WayPoint0d3' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Sum: '<S72>/Sum'

      rtb_Sum_o[1] = rtb_MatrixConcatenate[121];

      // DotProduct: '<S69>/Dot Product'
      rtb_LookaheadT = rtb_Sum_o[2] * rtb_Sum_o[2] + rtb_Output;

      // Selector: '<S7>/WayPoint0d3' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Sum: '<S72>/Sum'

      rtb_Sum_o[2] = rtb_MatrixConcatenate[182];

      // Gain: '<S7>/Gain1' incorporates:
      //   Sqrt: '<S69>/sqrt'

      codegenReal2Mission_B.Gain1 = -std::sqrt(rtb_LookaheadT);

      // Outputs for Atomic SubSystem: '<Root>/GenerateTrack'
      // Sum: '<S71>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   S-Function (sfix_udelay): '<S4>/NorthSequence'
      //   Selector: '<S7>/WayPoint2d3'

      rtb_Height_m = rtb_MatrixConcatenate[20] -
        codegenReal2Mission_B.SimUAVStateZOH.North;

      // End of Outputs for SubSystem: '<Root>/GenerateTrack'

      // DotProduct: '<S71>/Dot Product'
      rtb_East = rtb_Height_m * rtb_Height_m;

      // Sum: '<S71>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Selector: '<S7>/WayPoint0d3'
      //   Selector: '<S7>/WayPoint2d3'

      rtb_Height_m = rtb_MatrixConcatenate[81] - rtb_MatrixConcatenate[121];

      // DotProduct: '<S71>/Dot Product'
      rtb_East += rtb_Height_m * rtb_Height_m;

      // Sum: '<S71>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Selector: '<S7>/WayPoint0d3'
      //   Selector: '<S7>/WayPoint2d3'

      rtb_Height_m = rtb_MatrixConcatenate[142] - rtb_MatrixConcatenate[182];

      // DotProduct: '<S71>/Dot Product'
      rtb_LookaheadT = rtb_Height_m * rtb_Height_m + rtb_East;

      // Sqrt: '<S71>/sqrt'
      rtb_LookaheadT = std::sqrt(rtb_LookaheadT);

      // Gain: '<S7>/Gain'
      codegenReal2Mission_B.Gain = -rtb_LookaheadT;

      // End of Outputs for SubSystem: '<Root>/SpeedControl'
    }

    // Outputs for Atomic SubSystem: '<Root>/SpeedControl'
    // Outputs for Atomic SubSystem: '<S7>/ADRC'
    // Integrator: '<S73>/Integrator2'
    rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
    if (rEQ0) {
      rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
              (codegenReal2Mission_PrevZCX.Integrator2_Reset_ZCE != 1));
      codegenReal2Mission_PrevZCX.Integrator2_Reset_ZCE =
        codegenReal2Mission_B.TakeOffTrigger;

      // evaluate zero-crossings
      if (rEQ0) {
        codegenReal2Mission_X.Integrator2_CSTATE = 0.0;
      }
    }

    rtb_Output = codegenReal2Mission_X.Integrator2_CSTATE;

    // Sum: '<S68>/Sum3' incorporates:
    //   Integrator: '<S73>/Integrator2'

    rtb_Height_m = codegenReal2Mission_X.Integrator2_CSTATE -
      codegenReal2Mission_B.Gain1;

    // MATLAB Function: '<S73>/fal(e,0.25,h)' incorporates:
    //   Constant: '<S73>/Constant'
    //   Constant: '<S73>/Constant1'

    codegenReal2Mission_fale025h(rtb_Height_m, 0.25, 0.1, &rtb_East);

    // MATLAB Function: '<S73>/fal(e,0.5,h)' incorporates:
    //   Constant: '<S73>/Constant2'
    //   Constant: '<S73>/Constant3'

    codegenReal2Mission_fale025h(rtb_Height_m, 0.5, 0.1, &rtb_Sum1_b_idx_0);

    // Gain: '<S73>/Gain3' incorporates:
    //   Gain: '<S73>/Gain'

    codegenReal2Mission_B.Gain3 = -(1.2679145539688905 * rtb_East);

    // Integrator: '<S73>/Integrator'
    rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
    if (rEQ0) {
      rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
              (codegenReal2Mission_PrevZCX.Integrator_Reset_ZCE != 1));
      codegenReal2Mission_PrevZCX.Integrator_Reset_ZCE =
        codegenReal2Mission_B.TakeOffTrigger;

      // evaluate zero-crossings
      if (rEQ0) {
        codegenReal2Mission_X.Integrator_CSTATE = 0.0;
      }
    }

    rtb_North_l = codegenReal2Mission_X.Integrator_CSTATE;

    // End of Integrator: '<S73>/Integrator'

    // Integrator: '<S73>/Integrator1'
    rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
    if (rEQ0) {
      rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
              (codegenReal2Mission_PrevZCX.Integrator1_Reset_ZCE != 1));
      codegenReal2Mission_PrevZCX.Integrator1_Reset_ZCE =
        codegenReal2Mission_B.TakeOffTrigger;

      // evaluate zero-crossings
      if (rEQ0) {
        codegenReal2Mission_X.Integrator1_CSTATE = 0.0;
      }
    }

    rtb_Integrator1 = codegenReal2Mission_X.Integrator1_CSTATE;

    // End of Integrator: '<S73>/Integrator1'

    // Integrator: '<S75>/Integrator3'
    rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
    if (rEQ0) {
      rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
              (codegenReal2Mission_PrevZCX.Integrator3_Reset_ZCE != 1));
      codegenReal2Mission_PrevZCX.Integrator3_Reset_ZCE =
        codegenReal2Mission_B.TakeOffTrigger;

      // evaluate zero-crossings
      if (rEQ0) {
        codegenReal2Mission_X.Integrator3_CSTATE = 0.0;
      }
    }

    // Integrator: '<S75>/Integrator3'
    rtb_East = codegenReal2Mission_X.Integrator3_CSTATE;

    // Sum: '<S68>/Sum' incorporates:
    //   Integrator: '<S75>/Integrator3'

    rtb_Output = codegenReal2Mission_X.Integrator3_CSTATE - rtb_Output;

    // Integrator: '<S75>/Integrator2'
    rEQ0 = rtsiGetIsOkayToUpdateMode(&(&codegenReal2Mission_M)->solverInfo);
    if (rEQ0) {
      rEQ0 = (codegenReal2Mission_B.TakeOffTrigger &&
              (codegenReal2Mission_PrevZCX.Integrator2_Reset_ZCE_i != 1));
      codegenReal2Mission_PrevZCX.Integrator2_Reset_ZCE_i =
        codegenReal2Mission_B.TakeOffTrigger;

      // evaluate zero-crossings
      if (rEQ0) {
        codegenReal2Mission_X.Integrator2_CSTATE_l = 0.0;
      }
    }

    // Integrator: '<S75>/Integrator2'
    codegenReal2Mission_B.Integrator2 =
      codegenReal2Mission_X.Integrator2_CSTATE_l;

    // MATLAB Function: '<S74>/fhan(e1,ce2,r,h1)' incorporates:
    //   Constant: '<S74>/Constant'
    //   Constant: '<S74>/Constant1'
    //   Gain: '<S74>/Gain'
    //   Sum: '<S68>/Sum1'

    codegenReal2Miss_fhanv1v0v2r0h1(rtb_Output, 5.0 *
      (codegenReal2Mission_B.Integrator2 - rtb_Integrator1), 5.0, 6.0, &q);

    // Sum: '<S68>/Sum2' incorporates:
    //   Gain: '<S74>/Gain1'

    codegenReal2Mission_B.Sum2 = -q - rtb_North_l;

    // Sum: '<S73>/Sum' incorporates:
    //   Gain: '<S73>/Gain1'

    codegenReal2Mission_B.Sum = (codegenReal2Mission_B.Sum2 + rtb_North_l) -
      1.5811388300841895 * rtb_Sum1_b_idx_0;

    // Sum: '<S73>/Sum1'
    codegenReal2Mission_B.Sum1 = rtb_Integrator1 - rtb_Height_m;

    // Sum: '<S68>/Sum4'
    codegenReal2Mission_B.Sum4 = rtb_East - codegenReal2Mission_B.Gain1;

    // MATLAB Function: '<S75>/fhan(v1-v0,v2,r0,h)1' incorporates:
    //   Constant: '<S75>/Constant2'
    //   Constant: '<S75>/Constant3'
    //   Sum: '<S75>/Sum1'

    codegenReal2Miss_fhanv1v0v2r0h1(rtb_East - codegenReal2Mission_B.Gain,
      codegenReal2Mission_B.Integrator2, 0.5, 0.1, &codegenReal2Mission_B.fh);

    // End of Outputs for SubSystem: '<S7>/ADRC'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Sum: '<S7>/SumSpd' incorporates:
      //   Delay: '<S7>/Speed2d3Path'

      rtb_Sum1_b_idx_0 = codegenReal2Mission_B.Sum2 +
        codegenReal2Mission_DW.Speed2d3Path_DSTATE[0];

      // Saturate: '<S7>/SpeedProtection'
      if (rtb_Sum1_b_idx_0 > 41.0) {
        // ZeroOrderHold: '<S7>/AirspeedZOH'
        rtb_Sum1_b_idx_0 = 41.0;
      } else if (rtb_Sum1_b_idx_0 < 29.0) {
        // ZeroOrderHold: '<S7>/AirspeedZOH'
        rtb_Sum1_b_idx_0 = 29.0;
      }

      // End of Saturate: '<S7>/SpeedProtection'

      // Sum: '<S70>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Selector: '<S7>/WayPoint1d3'
      //   Sum: '<S72>/Sum'

      rtb_Height_m = rtb_MatrixConcatenate[40] - rtb_Sum_o[0];

      // DotProduct: '<S70>/Dot Product'
      rtb_East = rtb_Height_m * rtb_Height_m;

      // Sum: '<S72>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Selector: '<S7>/WayPoint1d3'
      //   Selector: '<S7>/WayPoint3d3'
      //   Sum: '<S70>/Sum'

      rtb_Output = rtb_MatrixConcatenate[0] - rtb_Sum_o[0];

      // DotProduct: '<S72>/Dot Product'
      rtb_North_l = rtb_Output * rtb_Output;

      // Sum: '<S70>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Selector: '<S7>/WayPoint1d3'
      //   Sum: '<S72>/Sum'

      rtb_Height_m = rtb_MatrixConcatenate[101] - rtb_Sum_o[1];

      // DotProduct: '<S70>/Dot Product'
      rtb_East += rtb_Height_m * rtb_Height_m;

      // Sum: '<S72>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Selector: '<S7>/WayPoint1d3'
      //   Selector: '<S7>/WayPoint3d3'
      //   Sum: '<S70>/Sum'

      rtb_Output = rtb_MatrixConcatenate[61] - rtb_Sum_o[1];

      // DotProduct: '<S72>/Dot Product'
      rtb_North_l += rtb_Output * rtb_Output;

      // Sum: '<S70>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Selector: '<S7>/WayPoint1d3'
      //   Sum: '<S72>/Sum'

      rtb_Height_m = rtb_MatrixConcatenate[162] - rtb_Sum_o[2];

      // Sum: '<S72>/Sum' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'
      //   Selector: '<S7>/WayPoint1d3'
      //   Selector: '<S7>/WayPoint3d3'
      //   Sum: '<S70>/Sum'

      rtb_Output = rtb_MatrixConcatenate[122] - rtb_Sum_o[2];

      // DotProduct: '<S70>/Dot Product'
      q = rtb_Height_m * rtb_Height_m + rtb_East;

      // Sum: '<S7>/ComputeLB' incorporates:
      //   Sqrt: '<S70>/sqrt'

      rtb_Height_m = std::sqrt(q) - rtb_LookaheadT;

      // DotProduct: '<S72>/Dot Product'
      q = rtb_Output * rtb_Output + rtb_North_l;

      // Sum: '<S7>/ComputeUB' incorporates:
      //   Sqrt: '<S72>/sqrt'

      rtb_East = std::sqrt(q) - rtb_LookaheadT;

      // Outport: '<Root>/RefAirspeed'
      codegenReal2Mission_Y.RefAirspeed = rtb_Sum1_b_idx_0;

      // Gain: '<Root>/Height2Down' incorporates:
      //   BusCreator: '<S5>/FixedWingGuidanceStateBus'

      rtb_North_l = -rtb_Height;

      // Gain: '<Root>/LookaheadT' incorporates:
      //   Delay: '<S7>/Speed2d3Path'

      rtb_LookaheadT = 3.0 * codegenReal2Mission_DW.Speed2d3Path_DSTATE[0];

      // MATLABSystem: '<Root>/TrackSimPath' incorporates:
      //   Concatenate: '<S4>/Matrix Concatenate'

      codegenReal2Mission_DW.obj.LookaheadDistFlag = 0U;
      if (rtb_LookaheadT < 10.0) {
        rtb_LookaheadT = 10.0;
        codegenReal2Mission_DW.obj.LookaheadDistFlag = 1U;
      }

      codegenReal2Mission_DW.obj.InitialPose[0] = 0.0;
      codegenReal2Mission_DW.obj.InitialPose[1] = 0.0;
      codegenReal2Mission_DW.obj.InitialPose[2] = 0.0;
      codegenReal2Mission_DW.obj.InitialPose[3] = 0.0;
      rEQ0 = false;
      p = true;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 183)) {
        if ((codegenReal2Mission_DW.obj.WaypointsInternal[i] ==
             rtb_MatrixConcatenate[i]) || (rtIsNaN
             (codegenReal2Mission_DW.obj.WaypointsInternal[i]) && rtIsNaN
             (rtb_MatrixConcatenate[i]))) {
          i++;
        } else {
          p = false;
          exitg1 = true;
        }
      }

      if (p) {
        rEQ0 = true;
      }

      if (!rEQ0) {
        std::memcpy(&codegenReal2Mission_DW.obj.WaypointsInternal[0],
                    &rtb_MatrixConcatenate[0], 183U * sizeof(real_T));
        codegenReal2Mission_DW.obj.WaypointIndex = 1.0;
        codegenReal2Mission_DW.obj.SearchFlag = true;
      }

      WaypointFollowerBase_getDistinc(rtb_MatrixConcatenate, b_waypointsIn_data,
        b_waypointsIn_size);
      codegenReal2Mission_DW.obj.NumWaypoints = b_waypointsIn_size[0];
      codegenReal2Mission_DW.obj.LookaheadDistance = rtb_LookaheadT;
      codegenReal2Miss_emxInit_real_T(&d, 2);

      // MATLABSystem: '<Root>/TrackSimPath' incorporates:
      //   BusCreator: '<S5>/FixedWingGuidanceStateBus'
      //   SignalConversion generated from: '<Root>/TrackSimPath'

      if (b_waypointsIn_size[0] == 0) {
        // MATLABSystem: '<Root>/TrackSimPath' incorporates:
        //   BusCreator: '<S5>/FixedWingGuidanceStateBus'
        //   SignalConversion generated from: '<Root>/TrackSimPath'

        rtb_Sum_o[0] = rtb_LookaheadT * std::cos(rtb_HeadingAngle) + rtb_Abs1_n;
        rtb_Sum_o[1] = rtb_LookaheadT * std::sin(rtb_HeadingAngle) +
          rtb_Switch_c;
        rtb_Sum_o[2] = rtb_LookaheadT * 0.0 + rtb_North_l;
        rtb_Output = rtb_HeadingAngle;
        rtb_Integrator1 = 0.0;
      } else {
        guard1 = false;
        if (b_waypointsIn_size[0] == 1) {
          if (codegenReal2Mission_DW.obj.StartFlag) {
            codegenReal2Mission_DW.obj.InitialPose[0] = rtb_Abs1_n;
            codegenReal2Mission_DW.obj.InitialPose[1] = rtb_Switch_c;
            codegenReal2Mission_DW.obj.InitialPose[2] = rtb_North_l;
            codegenReal2Mission_DW.obj.InitialPose[3] = rtb_HeadingAngle;
          }

          b_waypointsIn[0] = b_waypointsIn_data[0] - rtb_Abs1_n;
          b_waypointsIn[1] = b_waypointsIn_data[1] - rtb_Switch_c;
          b_waypointsIn[2] = b_waypointsIn_data[2] - rtb_North_l;
          if (codegenReal2Mission_norm_b(b_waypointsIn) < 1.4901161193847656E-8)
          {
            // MATLABSystem: '<Root>/TrackSimPath' incorporates:
            //   BusCreator: '<S5>/FixedWingGuidanceStateBus'
            //   SignalConversion generated from: '<Root>/TrackSimPath'

            rtb_Sum_o[0] = rtb_LookaheadT * std::cos(rtb_HeadingAngle) +
              rtb_Abs1_n;
            rtb_Sum_o[1] = rtb_LookaheadT * std::sin(rtb_HeadingAngle) +
              rtb_Switch_c;
            rtb_Sum_o[2] = rtb_LookaheadT * 0.0 + rtb_North_l;
            rtb_Output = rtb_HeadingAngle;
            rtb_Integrator1 = 0.0;
            codegenReal2Mission_DW.obj.StartFlag = false;
          } else {
            codegenReal2Mission_DW.obj.StartFlag = false;
            for (i = 0; i < 3; i++) {
              appendedWaypoints_data[i << 1] =
                codegenReal2Mission_DW.obj.InitialPose[i];
              appendedWaypoints_data[1 + (i << 1)] =
                b_waypointsIn_data[b_waypointsIn_size[0] * i];
            }

            codegenReal2Mission_DW.obj.NumWaypoints = 2.0;
            waypoints_size_idx_0 = 2;
            for (i = 0; i < 6; i++) {
              rtb_MatrixConcatenate[i] = appendedWaypoints_data[i];
            }

            guard1 = true;
          }
        } else {
          waypoints_size_idx_0 = b_waypointsIn_size[0];
          loop_ub = b_waypointsIn_size[0] * 3;
          if (0 <= loop_ub - 1) {
            std::memcpy(&rtb_MatrixConcatenate[0], &b_waypointsIn_data[0],
                        loop_ub * sizeof(real_T));
          }

          guard1 = true;
        }

        if (guard1) {
          if (codegenReal2Mission_DW.obj.SearchFlag) {
            i = d->size[0] * d->size[1];
            d->size[0] = 1;
            d->size[1] = static_cast<int32_T>
              (codegenReal2Mission_DW.obj.NumWaypoints - 1.0);
            codege_emxEnsureCapacity_real_T(d, i);
            loop_ub = static_cast<int32_T>
              (codegenReal2Mission_DW.obj.NumWaypoints - 1.0) - 1;
            for (i = 0; i <= loop_ub; i++) {
              d->data[i] = 0.0;
            }

            loop_ub = static_cast<int32_T>
              (codegenReal2Mission_DW.obj.NumWaypoints - 1.0) - 1;
            for (i = 0; i <= loop_ub; i++) {
              rtb_Integrator1 = rtb_MatrixConcatenate[static_cast<int32_T>((
                static_cast<real_T>(i) + 1.0) + 1.0) - 1];
              rtb_RealHdg_Log = rtb_MatrixConcatenate[i];
              rtb_LookaheadT = rtb_Integrator1 - rtb_RealHdg_Log;
              q = rtb_Abs1_n - rtb_RealHdg_Log;
              b_waypointsIn[0] = q;
              rtb_TmpSignalConversionAtTrac_1[0] = rtb_Abs1_n - rtb_Integrator1;
              rtb_Integrator1 = rtb_MatrixConcatenate[(static_cast<int32_T>((
                static_cast<real_T>(i) + 1.0) + 1.0) + waypoints_size_idx_0) - 1];
              rtb_HeadingAngle_g_tmp = rtb_MatrixConcatenate[i +
                waypoints_size_idx_0];
              rtb_HeadingAngle_n = rtb_Integrator1 - rtb_HeadingAngle_g_tmp;
              rtb_Output = rtb_Switch_c - rtb_HeadingAngle_g_tmp;
              b_waypointsIn[1] = rtb_Output;
              rtb_TmpSignalConversionAtTrac_1[1] = rtb_Switch_c -
                rtb_Integrator1;
              rtb_TargetHdg_Log = rtb_MatrixConcatenate[(static_cast<int32_T>((
                static_cast<real_T>(i) + 1.0) + 1.0) + (waypoints_size_idx_0 <<
                1)) - 1];
              turnVector_idx_1 = rtb_MatrixConcatenate[i + (waypoints_size_idx_0
                << 1)];
              turnVector_idx_0 = rtb_TargetHdg_Log - turnVector_idx_1;
              rtb_Integrator1 = rtb_North_l - turnVector_idx_1;
              b_waypointsIn[2] = rtb_Integrator1;
              rtb_TmpSignalConversionAtTrac_1[2] = rtb_North_l -
                rtb_TargetHdg_Log;
              rtb_Integrator1 = (rtb_Integrator1 * turnVector_idx_0 +
                                 (rtb_Output * rtb_HeadingAngle_n + q *
                                  rtb_LookaheadT)) / (turnVector_idx_0 *
                turnVector_idx_0 + (rtb_HeadingAngle_n * rtb_HeadingAngle_n +
                                    rtb_LookaheadT * rtb_LookaheadT));
              rtb_TmpSignalConversionAtTrac_2[0] = rtb_Abs1_n - (rtb_LookaheadT *
                rtb_Integrator1 + rtb_RealHdg_Log);
              rtb_TmpSignalConversionAtTrac_2[1] = rtb_Switch_c -
                (rtb_HeadingAngle_n * rtb_Integrator1 + rtb_HeadingAngle_g_tmp);
              rtb_TmpSignalConversionAtTrac_2[2] = rtb_North_l -
                (turnVector_idx_0 * rtb_Integrator1 + turnVector_idx_1);
              if (rtb_Integrator1 < 0.0) {
                d->data[i] = codegenReal2Mission_norm_b(b_waypointsIn);
              } else if (rtb_Integrator1 > 1.0) {
                d->data[i] = codegenReal2Mission_norm_b
                  (rtb_TmpSignalConversionAtTrac_1);
              } else {
                d->data[i] = codegenReal2Mission_norm_b
                  (rtb_TmpSignalConversionAtTrac_2);
              }
            }

            i = d->size[1];
            if (d->size[1] <= 2) {
              if (d->size[1] == 1) {
                loop_ub = 1;
              } else if ((d->data[0] > d->data[d->size[1] - 1]) || (rtIsNaN
                          (d->data[0]) && (!rtIsNaN(d->data[d->size[1] - 1]))))
              {
                loop_ub = d->size[1];
              } else {
                loop_ub = 1;
              }
            } else {
              if (!rtIsNaN(d->data[0])) {
                loop_ub = 1;
              } else {
                loop_ub = 0;
                waypoints = 2;
                exitg1 = false;
                while ((!exitg1) && (waypoints <= i)) {
                  if (!rtIsNaN(d->data[waypoints - 1])) {
                    loop_ub = waypoints;
                    exitg1 = true;
                  } else {
                    waypoints++;
                  }
                }
              }

              if (loop_ub == 0) {
                loop_ub = 1;
              } else {
                rtb_LookaheadT = d->data[loop_ub - 1];
                b_idx = loop_ub;
                for (waypoints = loop_ub + 1; waypoints <= i; waypoints++) {
                  rtb_Integrator1 = d->data[waypoints - 1];
                  if (rtb_LookaheadT > rtb_Integrator1) {
                    rtb_LookaheadT = rtb_Integrator1;
                    b_idx = waypoints;
                  }
                }

                loop_ub = b_idx;
              }
            }

            codegenReal2Mission_DW.obj.WaypointIndex = loop_ub;
            codegenReal2Mission_DW.obj.SearchFlag = false;
          }

          rEQ0 = false;
          if (codegenReal2Mission_DW.obj.WaypointIndex ==
              codegenReal2Mission_DW.obj.NumWaypoints) {
            rEQ0 = true;
          }

          if (rEQ0) {
            codegenReal2Mission_DW.obj.LastWaypointFlag = true;
            codegenReal2Mission_DW.obj.WaypointIndex--;
          }

          b_waypointsIn[0] = rtb_Abs1_n - rtb_MatrixConcatenate
            [static_cast<int32_T>(codegenReal2Mission_DW.obj.WaypointIndex + 1.0)
            - 1];
          b_waypointsIn[1] = rtb_Switch_c - rtb_MatrixConcatenate
            [(static_cast<int32_T>(codegenReal2Mission_DW.obj.WaypointIndex +
               1.0) + waypoints_size_idx_0) - 1];
          b_waypointsIn[2] = rtb_North_l - rtb_MatrixConcatenate
            [(static_cast<int32_T>(codegenReal2Mission_DW.obj.WaypointIndex +
               1.0) + (waypoints_size_idx_0 << 1)) - 1];
          guard2 = false;
          if (codegenReal2Mission_norm_b(b_waypointsIn) <= 1.0) {
            guard2 = true;
          } else {
            rtb_LookaheadT = rtb_MatrixConcatenate[static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex + 1.0) - 1];
            rtb_Sum_o[0] = rtb_Abs1_n - rtb_LookaheadT;
            b_waypointsIn[0] = rtb_LookaheadT - rtb_MatrixConcatenate[
              static_cast<int32_T>(codegenReal2Mission_DW.obj.WaypointIndex) - 1];
            rtb_LookaheadT = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1];
            rtb_Sum_o[1] = rtb_Switch_c - rtb_LookaheadT;
            b_waypointsIn[1] = rtb_LookaheadT - rtb_MatrixConcatenate[(
              static_cast<int32_T>(codegenReal2Mission_DW.obj.WaypointIndex) +
              waypoints_size_idx_0) - 1];
            q = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex + 1.0) +
              (waypoints_size_idx_0 << 1)) - 1];
            rtb_Sum_o[2] = rtb_North_l - q;
            turnVector_idx_2 = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex) + (waypoints_size_idx_0
              << 1)) - 1];
            b_waypointsIn[2] = q - turnVector_idx_2;
            rtb_Integrator1 = codegenReal2Mission_norm_b(b_waypointsIn);
            rtb_HeadingAngle_n = codegenReal2Mission_norm_b(rtb_Sum_o);
            turnVector_idx_0 = rtb_MatrixConcatenate[static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex) - 1];
            rtb_LookaheadT = rtb_MatrixConcatenate[static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex + 1.0) - 1];
            turnVector_idx_1 = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex) + waypoints_size_idx_0)
              - 1];
            rtb_Output = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1];
            rtb_Integrator1 = ((rtb_LookaheadT - turnVector_idx_0) /
                               rtb_Integrator1 * (rtb_Sum_o[0] /
              rtb_HeadingAngle_n) + (rtb_Output - turnVector_idx_1) /
                               rtb_Integrator1 * (rtb_Sum_o[1] /
              rtb_HeadingAngle_n)) + (q - turnVector_idx_2) / rtb_Integrator1 *
              (rtb_Sum_o[2] / rtb_HeadingAngle_n);
            if (rtb_Integrator1 < 0.0) {
              rtb_Integrator1 = -1.0;
            } else if (rtb_Integrator1 > 0.0) {
              rtb_Integrator1 = 1.0;
            } else if (rtb_Integrator1 == 0.0) {
              rtb_Integrator1 = 0.0;
            } else {
              rtb_Integrator1 = (rtNaN);
            }

            if (rtb_Integrator1 >= 0.0) {
              guard2 = true;
            } else {
              rtb_Sum_o[0] = rtb_LookaheadT;
              rtb_Sum_o[1] = rtb_Output;
              rtb_Sum_o[2] = q;
            }
          }

          if (guard2) {
            codegenReal2Mission_DW.obj.WaypointIndex++;
            rEQ0 = false;
            if (codegenReal2Mission_DW.obj.WaypointIndex ==
                codegenReal2Mission_DW.obj.NumWaypoints) {
              rEQ0 = true;
            }

            if (rEQ0) {
              codegenReal2Mission_DW.obj.LastWaypointFlag = true;
              codegenReal2Mission_DW.obj.WaypointIndex--;
            }

            turnVector_idx_0 = rtb_MatrixConcatenate[static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex) - 1];
            rtb_Sum_o[0] = rtb_MatrixConcatenate[static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex + 1.0) - 1];
            turnVector_idx_1 = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex) + waypoints_size_idx_0)
              - 1];
            rtb_Sum_o[1] = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1];
            turnVector_idx_2 = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex) + (waypoints_size_idx_0
              << 1)) - 1];
            rtb_Sum_o[2] = rtb_MatrixConcatenate[(static_cast<int32_T>
              (codegenReal2Mission_DW.obj.WaypointIndex + 1.0) +
              (waypoints_size_idx_0 << 1)) - 1];
          }

          rtb_LookaheadT = rtb_Sum_o[0] - turnVector_idx_0;
          q = rtb_Abs1_n - turnVector_idx_0;
          b_waypointsIn[0] = q;
          rtb_TmpSignalConversionAtTrac_1[0] = rtb_Abs1_n - rtb_Sum_o[0];
          rtb_HeadingAngle_n = rtb_Sum_o[1] - turnVector_idx_1;
          rtb_Output = rtb_Switch_c - turnVector_idx_1;
          b_waypointsIn[1] = rtb_Output;
          rtb_TmpSignalConversionAtTrac_1[1] = rtb_Switch_c - rtb_Sum_o[1];
          rtb_TargetHdg_Log = rtb_Sum_o[2] - turnVector_idx_2;
          rtb_Integrator1 = rtb_North_l - turnVector_idx_2;
          b_waypointsIn[2] = rtb_Integrator1;
          rtb_TmpSignalConversionAtTrac_1[2] = rtb_North_l - rtb_Sum_o[2];
          rtb_Integrator1 = (rtb_Integrator1 * rtb_TargetHdg_Log + (rtb_Output *
            rtb_HeadingAngle_n + q * rtb_LookaheadT)) / (rtb_TargetHdg_Log *
            rtb_TargetHdg_Log + (rtb_HeadingAngle_n * rtb_HeadingAngle_n +
            rtb_LookaheadT * rtb_LookaheadT));
          rtb_TmpSignalConversionAtTrac_2[0] = rtb_Abs1_n - (rtb_LookaheadT *
            rtb_Integrator1 + turnVector_idx_0);
          rtb_TmpSignalConversionAtTrac_2[1] = rtb_Switch_c -
            (rtb_HeadingAngle_n * rtb_Integrator1 + turnVector_idx_1);
          rtb_TmpSignalConversionAtTrac_2[2] = rtb_North_l - (rtb_TargetHdg_Log *
            rtb_Integrator1 + turnVector_idx_2);
          if (rtb_Integrator1 < 0.0) {
            rtb_Integrator1 = codegenReal2Mission_norm_b(b_waypointsIn);
          } else if (rtb_Integrator1 > 1.0) {
            rtb_Integrator1 = codegenReal2Mission_norm_b
              (rtb_TmpSignalConversionAtTrac_1);
          } else {
            rtb_Integrator1 = codegenReal2Mission_norm_b
              (rtb_TmpSignalConversionAtTrac_2);
          }

          if (codegenReal2Mission_DW.obj.LastWaypointFlag) {
            rtb_Integrator1 = ((q * rtb_LookaheadT + (rtb_Switch_c -
              turnVector_idx_1) * (rtb_Sum_o[1] - turnVector_idx_1)) +
                               (rtb_North_l - turnVector_idx_2) *
                               rtb_TargetHdg_Log) / ((rtb_LookaheadT *
              rtb_LookaheadT + (rtb_Sum_o[1] - turnVector_idx_1) * (rtb_Sum_o[1]
              - turnVector_idx_1)) + (rtb_Sum_o[2] - turnVector_idx_2) *
              (rtb_Sum_o[2] - turnVector_idx_2));
            b_waypointsIn[0] = rtb_Abs1_n - (rtb_Integrator1 * rtb_LookaheadT +
              turnVector_idx_0);
            b_waypointsIn[1] = rtb_Switch_c - (rtb_Integrator1 *
              rtb_HeadingAngle_n + turnVector_idx_1);
            b_waypointsIn[2] = rtb_North_l - (rtb_Integrator1 *
              rtb_TargetHdg_Log + turnVector_idx_2);
            rtb_Integrator1 = codegenReal2Mission_norm_b(b_waypointsIn);
          }

          rtb_HeadingAngle_g_tmp = std::abs(rtb_Integrator1);
          if ((!rtIsInf(rtb_HeadingAngle_g_tmp)) && (!rtIsNaN
               (rtb_HeadingAngle_g_tmp))) {
            if (rtb_HeadingAngle_g_tmp <= 2.2250738585072014E-308) {
              rtb_RealHdg_Log = 4.94065645841247E-324;
              rtb_Output = 4.94065645841247E-324;
            } else {
              frexp(rtb_HeadingAngle_g_tmp, &b_exponent);
              rtb_RealHdg_Log = std::ldexp(1.0, b_exponent - 53);
              frexp(rtb_HeadingAngle_g_tmp, &b_exponent_0);
              rtb_Output = std::ldexp(1.0, b_exponent_0 - 53);
            }
          } else {
            rtb_RealHdg_Log = (rtNaN);
            rtb_Output = (rtNaN);
          }

          q = std::sqrt(rtb_RealHdg_Log);
          rtb_Output *= 5.0;
          if ((q > rtb_Output) || rtIsNaN(rtb_Output)) {
            rtb_Output = q;
          }

          if (codegenReal2Mission_DW.obj.LookaheadDistance <= rtb_Integrator1 +
              rtb_Output) {
            codegenReal2Mission_DW.obj.LookaheadDistance =
              codegenReal2Mission_DW.obj.LookaheadFactor * rtb_Integrator1;
          }

          q = turnVector_idx_0 - rtb_Abs1_n;
          rtb_RealHdg_Log = turnVector_idx_1 - rtb_Switch_c;
          rtb_Output = ((rtb_Sum_o[0] - turnVector_idx_0) * (rtb_Sum_o[0] -
            turnVector_idx_0) + (rtb_Sum_o[1] - turnVector_idx_1) * (rtb_Sum_o[1]
            - turnVector_idx_1)) + (rtb_Sum_o[2] - turnVector_idx_2) *
            (rtb_Sum_o[2] - turnVector_idx_2);
          rtb_North_l = turnVector_idx_2 - rtb_North_l;
          rtb_LookaheadT = ((rtb_LookaheadT * q + rtb_HeadingAngle_n *
                             rtb_RealHdg_Log) + rtb_TargetHdg_Log * rtb_North_l)
            * 2.0;
          rtb_North_l = std::sqrt(rtb_LookaheadT * rtb_LookaheadT - (((q * q +
            rtb_RealHdg_Log * rtb_RealHdg_Log) + rtb_North_l * rtb_North_l) -
            codegenReal2Mission_DW.obj.LookaheadDistance *
            codegenReal2Mission_DW.obj.LookaheadDistance) * (4.0 * rtb_Output));
          q = (-rtb_LookaheadT + rtb_North_l) / 2.0 / rtb_Output;
          rtb_North_l = (-rtb_LookaheadT - rtb_North_l) / 2.0 / rtb_Output;
          if ((q > rtb_North_l) || rtIsNaN(rtb_North_l)) {
            rtb_North_l = q;
          }

          rtb_Sum_o[0] = (1.0 - rtb_North_l) * turnVector_idx_0 + rtb_North_l *
            rtb_Sum_o[0];
          rtb_Sum_o[1] = (1.0 - rtb_North_l) * turnVector_idx_1 + rtb_North_l *
            rtb_Sum_o[1];
          rtb_Sum_o[2] = (1.0 - rtb_North_l) * turnVector_idx_2 + rtb_North_l *
            rtb_Sum_o[2];
          rtb_Output = rt_atan2d_snf(rtb_Sum_o[1] - rtb_Switch_c, rtb_Sum_o[0] -
            rtb_Abs1_n);
          codegenReal2Mission_DW.obj.LastWaypointFlag = false;
        }
      }

      codegenReal2Miss_emxFree_real_T(&d);

      // Outputs for Atomic SubSystem: '<Root>/NorthEast2LatLon'
      // Product: '<S48>/x*cos' incorporates:
      //   Gain: '<Root>/NED2NEU'
      //   MATLABSystem: '<Root>/TrackSimPath'

      rtb_LookaheadT = rtb_Sum_o[0] * codegenReal2Mission_ConstB.SinCos_o2;

      // Product: '<S48>/y*sin' incorporates:
      //   Gain: '<Root>/NED2NEU'
      //   MATLABSystem: '<Root>/TrackSimPath'

      q = rtb_Sum_o[1] * codegenReal2Mission_ConstB.SinCos_o1;

      // Sum: '<S48>/Sum'
      rtb_North_l = rtb_LookaheadT - q;

      // Abs: '<S59>/Abs' incorporates:
      //   DataStoreRead: '<S6>/LatitudeGCS'

      rtb_LookaheadT = std::abs(codegenReal2Mission_DW.LatitudeGCS);

      // Switch: '<S59>/Switch' incorporates:
      //   Bias: '<S59>/Bias'
      //   Bias: '<S59>/Bias1'
      //   Constant: '<S59>/Constant2'
      //   Constant: '<S60>/Constant'
      //   DataStoreRead: '<S6>/LatitudeGCS'
      //   Math: '<S59>/Math Function1'
      //   RelationalOperator: '<S60>/Compare'

      if (rtb_LookaheadT > 180.0) {
        rtb_LookaheadT = rt_modd_snf(codegenReal2Mission_DW.LatitudeGCS + 180.0,
          360.0) + -180.0;
      } else {
        rtb_LookaheadT = codegenReal2Mission_DW.LatitudeGCS;
      }

      // End of Switch: '<S59>/Switch'

      // Abs: '<S56>/Abs1'
      q = std::abs(rtb_LookaheadT);

      // RelationalOperator: '<S58>/Compare' incorporates:
      //   Constant: '<S58>/Constant'

      rEQ0 = (q > 90.0);

      // Switch: '<S56>/Switch' incorporates:
      //   Bias: '<S56>/Bias'
      //   Bias: '<S56>/Bias1'
      //   Gain: '<S56>/Gain'
      //   Product: '<S56>/Divide1'

      if (rEQ0) {
        // Signum: '<S56>/Sign1'
        if (rtb_LookaheadT < 0.0) {
          rtb_LookaheadT = -1.0;
        } else if (rtb_LookaheadT > 0.0) {
          rtb_LookaheadT = 1.0;
        } else if (rtb_LookaheadT == 0.0) {
          rtb_LookaheadT = 0.0;
        } else {
          rtb_LookaheadT = (rtNaN);
        }

        // End of Signum: '<S56>/Sign1'
        rtb_LookaheadT *= -(q + -90.0) + 90.0;
      }

      // End of Switch: '<S56>/Switch'

      // UnitConversion: '<S64>/Unit Conversion'
      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      q = 0.017453292519943295 * rtb_LookaheadT;

      // Trigonometry: '<S65>/Trigonometric Function1'
      turnVector_idx_0 = std::sin(q);

      // Sum: '<S65>/Sum1' incorporates:
      //   Constant: '<S65>/Constant'
      //   Product: '<S65>/Product1'

      turnVector_idx_0 = 1.0 - codegenReal2Mission_ConstB.sqrt_l *
        codegenReal2Mission_ConstB.sqrt_l * turnVector_idx_0 * turnVector_idx_0;

      // Sqrt: '<S62>/sqrt'
      rtb_HeadingAngle_n = std::sqrt(turnVector_idx_0);

      // Product: '<S62>/Product1' incorporates:
      //   Constant: '<S62>/Constant1'

      rtb_HeadingAngle_n = 6.378137E+6 / rtb_HeadingAngle_n;

      // Product: '<S48>/rad lat' incorporates:
      //   Constant: '<S62>/Constant2'
      //   Product: '<S62>/Product3'
      //   Trigonometry: '<S62>/Trigonometric Function1'

      turnVector_idx_0 = rt_atan2d_snf(1.0, rtb_HeadingAngle_n *
        codegenReal2Mission_ConstB.Sum1_f / turnVector_idx_0) * rtb_North_l;

      // Product: '<S62>/Product4' incorporates:
      //   Trigonometry: '<S62>/Trigonometric Function'

      rtb_North_l = rtb_HeadingAngle_n * std::cos(q);

      // Product: '<S48>/x*sin' incorporates:
      //   Gain: '<Root>/NED2NEU'
      //   MATLABSystem: '<Root>/TrackSimPath'

      q = rtb_Sum_o[0] * codegenReal2Mission_ConstB.SinCos_o1;

      // Product: '<S48>/y*cos' incorporates:
      //   Gain: '<Root>/NED2NEU'
      //   MATLABSystem: '<Root>/TrackSimPath'

      rtb_HeadingAngle_n = rtb_Sum_o[1] * codegenReal2Mission_ConstB.SinCos_o2;

      // UnitConversion: '<S49>/Unit Conversion' incorporates:
      //   Constant: '<S62>/Constant3'
      //   Product: '<S48>/rad long '
      //   Sum: '<S48>/Sum1'
      //   Trigonometry: '<S62>/Trigonometric Function2'

      // Unit Conversion - from: rad to: deg
      // Expression: output = (57.2958*input) + (0)
      rtb_HeadingAngle_n = (q + rtb_HeadingAngle_n) * rt_atan2d_snf(1.0,
        rtb_North_l) * 57.295779513082323;

      // Switch: '<S47>/Switch1' incorporates:
      //   Constant: '<S47>/Constant'
      //   Constant: '<S47>/Constant1'

      if (rEQ0) {
        q = 180.0;
      } else {
        q = 0.0;
      }

      // End of Switch: '<S47>/Switch1'

      // Sum: '<S47>/Sum' incorporates:
      //   DataStoreRead: '<S6>/LongitudeGCS'

      turnVector_idx_1 = q + codegenReal2Mission_DW.LongitudeGCS;

      // Abs: '<S57>/Abs'
      q = std::abs(turnVector_idx_1);

      // Switch: '<S57>/Switch' incorporates:
      //   Bias: '<S57>/Bias'
      //   Bias: '<S57>/Bias1'
      //   Constant: '<S57>/Constant2'
      //   Constant: '<S61>/Constant'
      //   Math: '<S57>/Math Function1'
      //   RelationalOperator: '<S61>/Compare'

      if (q > 180.0) {
        turnVector_idx_1 = rt_modd_snf(turnVector_idx_1 + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S57>/Switch'

      // Sum: '<S45>/Sum' incorporates:
      //   UnitConversion: '<S49>/Unit Conversion'

      rtb_North_l = 57.295779513082323 * turnVector_idx_0 + rtb_LookaheadT;

      // Abs: '<S53>/Abs'
      rtb_LookaheadT = std::abs(rtb_North_l);

      // Switch: '<S53>/Switch' incorporates:
      //   Bias: '<S53>/Bias'
      //   Bias: '<S53>/Bias1'
      //   Constant: '<S53>/Constant2'
      //   Constant: '<S54>/Constant'
      //   Math: '<S53>/Math Function1'
      //   RelationalOperator: '<S54>/Compare'

      if (rtb_LookaheadT > 180.0) {
        rtb_North_l = rt_modd_snf(rtb_North_l + 180.0, 360.0) + -180.0;
      }

      // End of Switch: '<S53>/Switch'

      // Abs: '<S50>/Abs1'
      rtb_LookaheadT = std::abs(rtb_North_l);

      // Switch: '<S50>/Switch' incorporates:
      //   Constant: '<S46>/Constant'
      //   Constant: '<S46>/Constant1'
      //   Constant: '<S52>/Constant'
      //   RelationalOperator: '<S52>/Compare'
      //   Switch: '<S46>/Switch1'

      if (rtb_LookaheadT > 90.0) {
        // Signum: '<S50>/Sign1'
        if (rtb_North_l < 0.0) {
          rtb_North_l = -1.0;
        } else if (rtb_North_l > 0.0) {
          rtb_North_l = 1.0;
        } else if (rtb_North_l == 0.0) {
          rtb_North_l = 0.0;
        } else {
          rtb_North_l = (rtNaN);
        }

        // End of Signum: '<S50>/Sign1'

        // Outport: '<Root>/LookAheadPoint' incorporates:
        //   Bias: '<S50>/Bias'
        //   Bias: '<S50>/Bias1'
        //   Gain: '<S50>/Gain'
        //   Product: '<S50>/Divide1'

        codegenReal2Mission_Y.LookAheadPoint_j.Latitude_deg = (-(rtb_LookaheadT
          + -90.0) + 90.0) * rtb_North_l;
        q = 180.0;
      } else {
        // Outport: '<Root>/LookAheadPoint'
        codegenReal2Mission_Y.LookAheadPoint_j.Latitude_deg = rtb_North_l;
        q = 0.0;
      }

      // End of Switch: '<S50>/Switch'

      // Sum: '<S46>/Sum' incorporates:
      //   Sum: '<S45>/Sum'

      rtb_LookaheadT = (rtb_HeadingAngle_n + turnVector_idx_1) + q;

      // Abs: '<S51>/Abs'
      q = std::abs(rtb_LookaheadT);

      // Switch: '<S51>/Switch' incorporates:
      //   Constant: '<S55>/Constant'
      //   RelationalOperator: '<S55>/Compare'

      if (q > 180.0) {
        // Outport: '<Root>/LookAheadPoint' incorporates:
        //   Bias: '<S51>/Bias'
        //   Bias: '<S51>/Bias1'
        //   Constant: '<S51>/Constant2'
        //   Math: '<S51>/Math Function1'

        codegenReal2Mission_Y.LookAheadPoint_j.Longitude_deg = rt_modd_snf
          (rtb_LookaheadT + 180.0, 360.0) + -180.0;
      } else {
        // Outport: '<Root>/LookAheadPoint'
        codegenReal2Mission_Y.LookAheadPoint_j.Longitude_deg = rtb_LookaheadT;
      }

      // End of Switch: '<S51>/Switch'

      // Gain: '<S6>/Up2Down' incorporates:
      //   Gain: '<Root>/NED2NEU'
      //   MATLABSystem: '<Root>/TrackSimPath'

      turnVector_idx_0 = rtb_Sum_o[2];

      // Outport: '<Root>/LookAheadPoint' incorporates:
      //   DataStoreRead: '<S6>/Data Store Read'
      //   Gain: '<S6>/inverse'
      //   Sum: '<S45>/Sum1'
      //   UnaryMinus: '<S45>/Ze2height'

      codegenReal2Mission_Y.LookAheadPoint_j.Height_meter = -turnVector_idx_0 -
        (-codegenReal2Mission_DW.AltitudeGCS);

      // End of Outputs for SubSystem: '<Root>/NorthEast2LatLon'

      // Truth Table: '<Root>/EngagementTruthTable' incorporates:
      //   Delay: '<S7>/Speed2d3Path'

      //  Front Distance within Upper &  Lower Bound
      //  CrossTrack Error within 1.5 Second Bound
      if ((codegenReal2Mission_B.Sum4 < rtb_East) && (codegenReal2Mission_B.Sum4
           > rtb_Height_m) && (rtb_Integrator1 <
           codegenReal2Mission_DW.Speed2d3Path_DSTATE[0] * 1.5)) {
        //  Real UAV Engaged with Simulation UAV
        rEQ0 = true;
      } else {
        //  Default
        //  Real UAV Not Engaged with Simulation UAV
        rEQ0 = false;
      }

      // End of Truth Table: '<Root>/EngagementTruthTable'

      // Outport: '<Root>/EngagedFlag'
      codegenReal2Mission_Y.EngagedFlag = rEQ0;

      // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
      //   BusCreator: '<S5>/FixedWingGuidanceStateBus'

      rtb_North_l = rtb_Abs1_n;

      // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
      //   BusCreator: '<S5>/FixedWingGuidanceStateBus'

      rtb_East = rtb_Switch_c;

      // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
      //   BusCreator: '<S5>/FixedWingGuidanceStateBus'

      turnVector_idx_1 = 0.0;

      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      turnVector_idx_2 = codegenReal2Mission_B.SimUAVStateZOH.North;

      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_Abs1_n = codegenReal2Mission_B.SimUAVStateZOH.East;

      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_Height_m = codegenReal2Mission_B.SimUAVStateZOH.Height;

      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_Switch_c = codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_HeadingAngle_n = codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle;

      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      turnVector_idx_0 = codegenReal2Mission_B.SimUAVStateZOH.FlightPathAngle;

      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      q = codegenReal2Mission_B.SimUAVStateZOH.RollAngle;

      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_LookaheadT = codegenReal2Mission_B.SimUAVStateZOH.RollAngleRate;

      // MATLAB Function: '<Root>/AngLog' incorporates:
      //   BusCreator: '<S5>/FixedWingGuidanceStateBus'
      //   MATLABSystem: '<Root>/TrackSimPath'

      rtb_TargetHdg_Log = codegenReal2Mission_angdiff(0.0, rtb_Output);
      rtb_RealHdg_Log = codegenReal2Mission_angdiff(0.0, rtb_HeadingAngle);
      rtb_Output = codegenReal2Mission_angdiff(rtb_HeadingAngle, rtb_Output);

      // Scope: '<Root>/ModelLogging'
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
          up0[0] = rtb_North_l;
          up0[1] = rtb_East;
          up0[2] = rtb_Height;
          up0[3] = rtb_Abs1_i;
          up0[4] = rtb_HeadingAngle;
          up0[5] = rtb_FlightPathAngle;
          up0[6] = rtb_RollAngle_p;
          up0[7] = turnVector_idx_1;
          rt_UpdateLogVar((LogVar *)var, up0, 0);
          var = var->next;
        }

        {
          real_T up1[8];
          up1[0] = turnVector_idx_2;
          up1[1] = rtb_Abs1_n;
          up1[2] = rtb_Height_m;
          up1[3] = rtb_Switch_c;
          up1[4] = rtb_HeadingAngle_n;
          up1[5] = turnVector_idx_0;
          up1[6] = q;
          up1[7] = rtb_LookaheadT;
          rt_UpdateLogVar((LogVar *)var, up1, 0);
          var = var->next;
        }

        {
          real_T up2[1];
          up2[0] = rtb_Sum1_b_idx_0;
          rt_UpdateLogVar((LogVar *)var, up2, 0);
          var = var->next;
        }

        {
          real_T up3[1];
          up3[0] = codegenReal2Mission_B.Sum4;
          rt_UpdateLogVar((LogVar *)var, up3, 0);
          var = var->next;
        }

        {
          real_T up4[3];
          up4[0] = rtb_Sum_o[0];
          up4[1] = rtb_Sum_o[1];
          up4[2] = rtb_Sum_o[2];
          rt_UpdateLogVar((LogVar *)var, up4, 0);
          var = var->next;
        }

        {
          real_T up5[1];
          up5[0] = rtb_Integrator1;
          rt_UpdateLogVar((LogVar *)var, up5, 0);
          var = var->next;
        }

        {
          boolean_T up6[1];
          up6[0] = rEQ0;
          rt_UpdateLogVar((LogVar *)var, up6, 0);
          var = var->next;
        }

        {
          real_T up7[3];
          up7[0] = rtb_Output;
          up7[1] = rtb_RealHdg_Log;
          up7[2] = rtb_TargetHdg_Log;
          rt_UpdateLogVar((LogVar *)var, up7, 0);
          var = var->next;
        }

        {
          real_T up8[1];
          up8[0] = codegenReal2Mission_B.Sum2;
          rt_UpdateLogVar((LogVar *)var, up8, 0);
        }
      }

      // Chart: '<Root>/TriggerTermination'
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
          if (codegenReal2Mission_DW.DataCounter >= 299.0) {
            codegenReal2Mission_DW.is_c4_codegenReal2Mission =
              codegenReal_IN_MissionExecution;
            codegenReal2Mission_B.ExecutionTrigger = 1.0;
            codegenReal2Mission_DW.DataCounter = 0.0;
          } else if ((!codegenReal2Mission_B.TakeOffTrigger) || (!rEQ0)) {
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
          } else if (rEQ0) {
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

      // End of Chart: '<Root>/TriggerTermination'

      // Stop: '<Root>/Stop Simulation'
      if (codegenReal2Mission_B.Terminate) {
        rtmSetStopRequested((&codegenReal2Mission_M), 1);
      }

      // End of Stop: '<Root>/Stop Simulation'

      // Gain: '<S3>/Gain2'
      codegenReal2Mission_B.Down = -codegenReal2Mission_B.SimUAVStateZOH.Height;
    }

    // End of Outputs for SubSystem: '<Root>/SpeedControl'

    // Step: '<S13>/Step'
    if ((&codegenReal2Mission_M)->Timing.t[0] < 0.0) {
      rtb_Integrator1 = 0.0;
    } else {
      rtb_Integrator1 = 0.057119866428905326;
    }

    // End of Step: '<S13>/Step'

    // Sum: '<S13>/Output' incorporates:
    //   Clock: '<S13>/Clock'
    //   Product: '<S13>/Product'

    rtb_Output = rtb_Integrator1 * (&codegenReal2Mission_M)->Timing.t[0];
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Memory: '<S3>/Memory1'
      rtb_LookaheadT = codegenReal2Mission_DW.Memory1_PreviousInput;

      // Switch: '<S3>/Switch'
      if (rtb_LookaheadT > 0.0) {
        // Switch: '<S3>/Switch' incorporates:
        //   Constant: '<S3>/Constant'

        codegenReal2Mission_B.Switch = 300.0;
      } else {
        // Switch: '<S3>/Switch' incorporates:
        //   Constant: '<S3>/Constant1'

        codegenReal2Mission_B.Switch = 0.0;
      }

      // End of Switch: '<S3>/Switch'
    }

    // SignalConversion generated from: '<S3>/TakeOffGathering' incorporates:
    //   Constant: '<S3>/Down'
    //   Product: '<S3>/ProductEast'
    //   Product: '<S3>/ProductNorth'
    //   Trigonometry: '<S3>/Cos'
    //   Trigonometry: '<S3>/Sin'

    rtb_Sum_o[0] = std::sin(rtb_Output) * codegenReal2Mission_B.Switch;
    rtb_Sum_o[1] = std::cos(rtb_Output) * codegenReal2Mission_B.Switch;
    rtb_Sum_o[2] = -150.0;

    // MATLABSystem: '<S3>/TakeOffGathering' incorporates:
    //   SignalConversion generated from: '<S3>/TakeOffGathering'

    codegenReal2Mission_DW.obj_m.OrbitRadiusFlag = 0U;
    codegenReal2Mission_DW.obj_m.LookaheadDistFlag = 0U;
    q = codegenReal2Mission_B.SimUAVStateZOH.North - rtb_Sum_o[0];
    rtb_TmpSignalConversionAtTrac_0[0] = q;
    rtb_Output = codegenReal2Mission_B.SimUAVStateZOH.East - rtb_Sum_o[1];
    rtb_TmpSignalConversionAtTrac_0[1] = rtb_Output;
    if (codegenReal2Mission_norm(rtb_TmpSignalConversionAtTrac_0) <
        2.47032822920623E-323) {
      // MATLABSystem: '<S3>/TakeOffGathering'
      codegenReal2Mission_B.TakeOffGathering_o2 =
        codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle;
      rtb_Sum1_b_idx_0 = codegenReal2Mission_DW.obj_m.NumCircles;
    } else {
      rEQ0 = false;
      p = true;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        if ((codegenReal2Mission_DW.obj_m.OrbitCenterInternal[i] == rtb_Sum_o[i])
            || (rtIsNaN(codegenReal2Mission_DW.obj_m.OrbitCenterInternal[i]) &&
                rtIsNaN(rtb_Sum_o[i]))) {
          i++;
        } else {
          p = false;
          exitg1 = true;
        }
      }

      if (p) {
        rEQ0 = true;
      }

      if ((!rEQ0) || (!(codegenReal2Mission_DW.obj_m.OrbitRadiusInternal ==
                        1000.0))) {
        codegenReal2Mission_DW.obj_m.NumCircles = 0.0;
        codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = rtb_Sum_o[0];
        codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = rtb_Sum_o[1];
        codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = -150.0;
        codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = 1000.0;
        codegenReal2Mission_DW.obj_m.SelectTurnDirectionFlag = true;
      }

      codegenReal2Mission_DW.obj_m.LookaheadDistance = 100.0;
      distToCenter_tmp[0] = q;
      distToCenter_tmp[1] = rtb_Output;
      rtb_Height = std::sqrt(rtb_Output * rtb_Output + q * q);
      rtb_HeadingAngle_g_tmp = std::abs
        (codegenReal2Mission_DW.obj_m.LookaheadDistance + 1000.0);
      rEQ0 = !rtIsInf(rtb_HeadingAngle_g_tmp);
      p = !rtIsNaN(rtb_HeadingAngle_g_tmp);
      if (rEQ0 && p) {
        if (rtb_HeadingAngle_g_tmp <= 2.2250738585072014E-308) {
          rtb_RealHdg_Log = 4.94065645841247E-324;
        } else {
          frexp(rtb_HeadingAngle_g_tmp, &b_exponent_1);
          rtb_RealHdg_Log = std::ldexp(1.0, b_exponent_1 - 53);
        }
      } else {
        rtb_RealHdg_Log = (rtNaN);
      }

      guard1 = false;
      if (rtb_Height >= (codegenReal2Mission_DW.obj_m.LookaheadDistance + 1000.0)
          - 5.0 * rtb_RealHdg_Log) {
        guard1 = true;
      } else {
        if (rEQ0 && p) {
          if (rtb_HeadingAngle_g_tmp <= 2.2250738585072014E-308) {
            rtb_RealHdg_Log = 4.94065645841247E-324;
          } else {
            frexp(rtb_HeadingAngle_g_tmp, &b_exponent_2);
            rtb_RealHdg_Log = std::ldexp(1.0, b_exponent_2 - 53);
          }
        } else {
          rtb_RealHdg_Log = (rtNaN);
        }

        if (rtb_Height <= (1000.0 -
                           codegenReal2Mission_DW.obj_m.LookaheadDistance) + 5.0
            * rtb_RealHdg_Log) {
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

          rtb_TmpSignalConversionAtTrac_0[0] = q;
          rtb_TmpSignalConversionAtTrac_0[1] = rtb_Output;
          rtb_Height_m = codegenReal2Mission_norm
            (rtb_TmpSignalConversionAtTrac_0);
          rtb_Abs1_i = codegenReal2Mission_DW.obj_m.LookaheadDistance *
            codegenReal2Mission_DW.obj_m.LookaheadDistance;
          rtb_Sum1_b_idx_0 = ((rtb_Abs1_i - 1.0E+6) + rtb_Height_m *
                              rtb_Height_m) / (2.0 * rtb_Height_m);
          rtb_HeadingAngle = rtb_Sum_o[0] -
            codegenReal2Mission_B.SimUAVStateZOH.North;
          rtb_FlightPathAngle = rtb_HeadingAngle * rtb_Sum1_b_idx_0 /
            rtb_Height_m + codegenReal2Mission_B.SimUAVStateZOH.North;
          rtb_RollAngle_p = rtb_Sum_o[1] -
            codegenReal2Mission_B.SimUAVStateZOH.East;
          rtb_Height = rtb_RollAngle_p * rtb_Sum1_b_idx_0 / rtb_Height_m +
            codegenReal2Mission_B.SimUAVStateZOH.East;
          rtb_Abs1_n = std::sqrt(rtb_Abs1_i - rtb_Sum1_b_idx_0 *
            rtb_Sum1_b_idx_0);
          rtb_Abs1_i = rtb_RollAngle_p * rtb_Abs1_n / rtb_Height_m;
          distToCenter_tmp[0] = rtb_FlightPathAngle - rtb_Abs1_i;
          rtb_Abs1_n = rtb_HeadingAngle * rtb_Abs1_n / rtb_Height_m;
          rtb_Switch_c = rtb_Abs1_n + rtb_Height;
          rtb_Sum1_b_idx_0 = codegenReal2Mission_DW.obj_m.PrevPosition[1] -
            rtb_Sum_o[1];
          rtb_Sum_c[0] = codegenReal2Mission_DW.obj_m.PrevPosition[0] -
            rtb_Sum_o[0];
          rtb_Sum_c[1] = rtb_Sum1_b_idx_0;
          rtb_Sum_c[2] = 0.0;
          rtb_Sum_o[0] = q;
          rtb_Sum_o[1] = rtb_Output;
          rtb_Sum_o[2] = 0.0;
          rtb_Integrator1 = codegenReal2Mission_norm_b(rtb_Sum_c);
          rtb_HeadingAngle_n = codegenReal2Mission_norm_b(rtb_Sum_o);
          rtb_Height_m = rtb_Sum_c[0] / rtb_Integrator1;
          rtb_East = q / rtb_HeadingAngle_n;
          rtb_LookaheadT = rtb_Output / rtb_HeadingAngle_n;
          codegenReal2Mission_DW.obj_m.PrevPosition[0] =
            codegenReal2Mission_B.SimUAVStateZOH.North;
          codegenReal2Mission_DW.obj_m.PrevPosition[1] =
            codegenReal2Mission_B.SimUAVStateZOH.East;
          codegenReal2Mission_DW.obj_m.PrevPosition[2] =
            codegenReal2Mission_B.Down;
          rtb_Sum1_b_idx_0 /= rtb_Integrator1;
          codegenReal2Mission_DW.obj_m.NumCircles += rt_atan2d_snf(rtb_Height_m *
            rtb_LookaheadT - rtb_East * rtb_Sum1_b_idx_0, (rtb_Sum1_b_idx_0 *
            rtb_LookaheadT + rtb_Height_m * rtb_East) + 0.0 / rtb_Integrator1 *
            (0.0 / rtb_HeadingAngle_n)) / 2.0 / 3.1415926535897931;
          rtb_Sum1_b_idx_0 = codegenReal2Mission_DW.obj_m.NumCircles;
          if ((distToCenter_tmp[0] - codegenReal2Mission_B.SimUAVStateZOH.North)
              * rtb_RollAngle_p - rtb_HeadingAngle * (rtb_Switch_c -
               codegenReal2Mission_B.SimUAVStateZOH.East) > 0.0) {
            rtb_North_l = distToCenter_tmp[0];
          } else {
            rtb_North_l = rtb_Abs1_i + rtb_FlightPathAngle;
            rtb_Switch_c = rtb_Height - rtb_Abs1_n;
          }
        }
      }

      if (guard1) {
        rtb_Integrator1 = codegenReal2Mission_norm(distToCenter_tmp);
        rtb_North_l = q / rtb_Integrator1 * 1000.0 + rtb_Sum_o[0];
        rtb_Switch_c = rtb_Output / rtb_Integrator1 * 1000.0 + rtb_Sum_o[1];
        rtb_Sum1_b_idx_0 = codegenReal2Mission_DW.obj_m.NumCircles;
      }

      // MATLABSystem: '<S3>/TakeOffGathering'
      codegenReal2Mission_B.TakeOffGathering_o2 = rt_atan2d_snf(rtb_Switch_c -
        codegenReal2Mission_B.SimUAVStateZOH.East, rtb_North_l -
        codegenReal2Mission_B.SimUAVStateZOH.North);
    }

    if ((codegenReal2Mission_DW.obj_m.PrevResetSignal <= 2.2227587494850775E-162)
        && (codegenReal2Mission_B.ExecutionTrigger > 2.2227587494850775E-162)) {
      codegenReal2Mission_DW.obj_m.NumCircles *= 0.0;
    }

    codegenReal2Mission_DW.obj_m.PrevResetSignal =
      codegenReal2Mission_B.ExecutionTrigger;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Chart: '<S3>/Chart' incorporates:
      //   MATLABSystem: '<S3>/TakeOffGathering'

      if (codegenReal2Mission_DW.is_active_c10_codegenReal2Missi == 0U) {
        codegenReal2Mission_DW.is_active_c10_codegenReal2Missi = 1U;
        codegenReal2Mission_DW.is_c10_codegenReal2Mission =
          codegenReal2Mission_IN_Circle;
        codegenReal2Mission_B.Seletion = 0.0;
      } else if (codegenReal2Mission_DW.is_c10_codegenReal2Mission == 1) {
        if ((rtb_Sum1_b_idx_0 > 2.0) && (codegenReal2Mission_B.ExecutionTrigger
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

      // End of Chart: '<S3>/Chart'
    }

    // Gain: '<S3>/Down2Height'
    codegenReal2Mission_B.Down2Height = 150.0;
  }

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Matfile logging
    rt_UpdateTXYLogVars((&codegenReal2Mission_M)->rtwLogInfo,
                        ((&codegenReal2Mission_M)->Timing.t));
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    int_T idxDelay;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Update for Memory: '<S3>/Memory'
      codegenReal2Mission_DW.Memory_PreviousInput =
        codegenReal2Mission_B.Down2Height;

      // Update for Delay: '<S3>/Delay'
      codegenReal2Mission_DW.icLoad = false;

      // Update for BusCreator: '<S3>/Bus Creator' incorporates:
      //   Delay: '<S3>/Delay'

      codegenReal2Mission_DW.Delay_DSTATE =
        codegenReal2Mission_B.TakeOffGathering_o2;

      // Update for Atomic SubSystem: '<Root>/SpeedControl'
      // Update for Delay: '<S7>/Speed2d3Path'
      for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        codegenReal2Mission_DW.Speed2d3Path_DSTATE[idxDelay] =
          codegenReal2Mission_DW.Speed2d3Path_DSTATE[idxDelay + 1];
      }

      codegenReal2Mission_DW.Speed2d3Path_DSTATE[19] =
        codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

      // End of Update for Delay: '<S7>/Speed2d3Path'
      // End of Update for SubSystem: '<Root>/SpeedControl'

      // Update for Memory: '<S3>/Memory1'
      codegenReal2Mission_DW.Memory1_PreviousInput =
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

  // Derivatives for Atomic SubSystem: '<S3>/MissionSimUAV'
  // Derivatives for Integrator: '<S16>/Integrator' incorporates:
  //   MATLABSystem: '<S16>/ComputeDerivative'

  std::memcpy(&_rtXdot->Integrator_CSTATE_g[0],
              &codegenReal2Mission_B.ComputeDerivative[0], sizeof(real_T) << 3U);

  // Derivatives for Integrator: '<S17>/Integrator3'
  _rtXdot->Integrator3_CSTATE_b = codegenReal2Mission_B.Integrator2_e;

  // Derivatives for Integrator: '<S17>/Integrator2'
  _rtXdot->Integrator2_CSTATE_n = codegenReal2Mission_B.fh_n;

  // End of Derivatives for SubSystem: '<S3>/MissionSimUAV'

  // Derivatives for Atomic SubSystem: '<Root>/SpeedControl'
  // Derivatives for Atomic SubSystem: '<S7>/ADRC'
  // Derivatives for Integrator: '<S73>/Integrator2'
  _rtXdot->Integrator2_CSTATE = codegenReal2Mission_B.Sum1;

  // Derivatives for Integrator: '<S73>/Integrator'
  _rtXdot->Integrator_CSTATE = codegenReal2Mission_B.Gain3;

  // Derivatives for Integrator: '<S73>/Integrator1'
  _rtXdot->Integrator1_CSTATE = codegenReal2Mission_B.Sum;

  // Derivatives for Integrator: '<S75>/Integrator3'
  _rtXdot->Integrator3_CSTATE = codegenReal2Mission_B.Integrator2;

  // Derivatives for Integrator: '<S75>/Integrator2'
  _rtXdot->Integrator2_CSTATE_l = codegenReal2Mission_B.fh;

  // End of Derivatives for SubSystem: '<S7>/ADRC'
  // End of Derivatives for SubSystem: '<Root>/SpeedControl'
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

    // SetupRuntimeResources for Scope: '<Root>/ModelLogging'
    {
      RTWLogSignalInfo rt_ScopeSignalInfo;
      static int_T rt_ScopeSignalWidths[] = { 8, 8, 1, 1, 3, 1, 1, 3, 1 };

      static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1, 1, 2, 2, 1, 1, 1 };

      static int_T rt_ScopeSignalDimensions[] = { 8, 8, 1, 1, 3, 1, 1, 1, 1, 3,
        1 };

      static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL), (NULL),
        (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL) };

      static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
      };

      static const char_T *rt_ScopeSignalLabels[] = { "RealUAVState_Log",
        "SimUAVState_Log",
        "RefAirspeed_Log",
        "LagDistance_Log",
        "LookAheadNED_Log",
        "CrossTrackError_Log",
        "EngagedFlag_Log",
        "Heading_Log",
        "ADRC_U_Log" };

      static char_T rt_ScopeSignalTitles[] =
        "RealUAVState_LogSimUAVState_LogRefAirspeed_LogLagDistance_LogLookAheadNED_LogCrossTrackError_LogEngagedFlag_LogHeading_LogADRC_U_Log";
      static int_T rt_ScopeSignalTitleLengths[] = { 16, 15, 15, 15, 16, 19, 15,
        11, 10 };

      static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

      static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 };

      BuiltInDTypeId dTypes[9] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE,
        SS_DOUBLE, SS_DOUBLE, SS_BOOLEAN, SS_DOUBLE, SS_DOUBLE };

      static char_T rt_ScopeBlockName[] = "codegenReal2Mission/ModelLogging";
      static int_T rt_ScopeFrameData[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

      static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
        (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL),
        (NULL), (NULL)
      };

      rt_ScopeSignalInfo.numSignals = 9;
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
        "Real2SimLog",
        1,
        0,
        1,
        0.1,
        &rt_ScopeSignalInfo,
        rt_ScopeBlockName);
      if (codegenReal2Mission_DW.ModelLogging_PWORK.LoggedData[0] == (NULL))
        return;
    }

    codegenReal2Mission_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.Integrator2_Reset_ZCE_i = UNINITIALIZED_ZCSIG;

    // InitializeConditions for Memory: '<S3>/Memory'
    codegenReal2Mission_DW.Memory_PreviousInput = 50.0;

    // InitializeConditions for Delay: '<S3>/Delay'
    codegenReal2Mission_DW.icLoad = true;

    // SystemInitialize for Atomic SubSystem: '<S3>/MissionSimUAV'
    // InitializeConditions for RateLimiter: '<S12>/ClimbRateLimiter'
    codegenReal2Mission_DW.PrevY = 150.0;

    // InitializeConditions for Integrator: '<S16>/Integrator'
    std::memset(&codegenReal2Mission_X.Integrator_CSTATE_g[0], 0, sizeof(real_T)
                << 3U);

    // InitializeConditions for Integrator: '<S17>/Integrator3'
    codegenReal2Mission_X.Integrator3_CSTATE_b = 0.0;

    // InitializeConditions for Integrator: '<S17>/Integrator2'
    codegenReal2Mission_X.Integrator2_CSTATE_n = 0.0;

    // Start for MATLABSystem: '<S16>/ComputeDerivative'
    codegenReal2Mission_DW.obj_a.isInitialized = 0;
    codegenReal2Mission_DW.obj_a.isInitialized = 1;
    codegenReal2Mis_Model_resetImpl(&codegenReal2Mission_DW.obj_a);

    // InitializeConditions for MATLABSystem: '<S16>/ComputeDerivative'
    codegenReal2Mis_Model_resetImpl(&codegenReal2Mission_DW.obj_a);

    // Outputs for Atomic SubSystem: '<S12>/InitializeSimLocation'
    // DataStoreWrite: '<S14>/DSnumMissionUAV' incorporates:
    //   Constant: '<S14>/Number Of Mission UAV'

    codegenReal2Mission_DW.numMissionUAV = codegenReal2Mission_P.numMissionUAV;

    // DataStoreWrite: '<S14>/DSuavIDX' incorporates:
    //   Constant: '<S14>/UAVidx'

    codegenReal2Mission_DW.UAVidx = codegenReal2Mission_P.UAVidx;

    // DataStoreWrite: '<S14>/DSAltitudeGCS' incorporates:
    //   Constant: '<S14>/AltitudeGCS'

    codegenReal2Mission_DW.AltitudeGCS = codegenReal2Mission_P.GCS_Altitude;

    // DataStoreWrite: '<S14>/DSLatitudeGCS' incorporates:
    //   Constant: '<S14>/LatitudeGCS'

    codegenReal2Mission_DW.LatitudeGCS = codegenReal2Mission_P.GCS_Latitude;

    // DataStoreWrite: '<S14>/DSLongitudeGCS' incorporates:
    //   Constant: '<S14>/LongitudeGCS'

    codegenReal2Mission_DW.LongitudeGCS = codegenReal2Mission_P.GCS_Longitude;

    // Product: '<S14>/Map2Radian' incorporates:
    //   Bias: '<S14>/Bias'
    //   Constant: '<S14>/2pi'
    //   Constant: '<S14>/Number Of Mission UAV'
    //   Constant: '<S14>/UAVidx'
    //   DataTypeConversion: '<S14>/Cast To Double'
    //   Gain: '<S14>/Gain'
    //   Product: '<S14>/Divide'
    //   Sum: '<S14>/Minus'

    rtb_ClockwiseRotation = (static_cast<real_T>(codegenReal2Mission_P.UAVidx) -
      (codegenReal2Mission_P.numMissionUAV + 1.0) * 0.5) * (6.2831853071795862 /
      codegenReal2Mission_P.numMissionUAV);

    // StateWriter: '<S14>/SimUAVState' incorporates:
    //   Bias: '<S14>/ClockwiseRotation'
    //   Constant: '<S14>/InitialFlightPathAngle'
    //   Constant: '<S14>/InitialHeight'
    //   Constant: '<S14>/InitialRollAngle'
    //   Constant: '<S14>/InitialRollAngleRate'
    //   Constant: '<S14>/InitialUAVAirspeed'
    //   Constant: '<S14>/Radius'
    //   Product: '<S14>/EastDis'
    //   Product: '<S14>/NorthDis'
    //   Reshape: '<S14>/Reshape'
    //   Trigonometry: '<S14>/Cos'
    //   Trigonometry: '<S14>/Sin'

    codegenReal2Mission_X.Integrator_CSTATE_g[0] = std::cos
      (rtb_ClockwiseRotation) * 1000.0;
    codegenReal2Mission_X.Integrator_CSTATE_g[1] = 1000.0 * std::sin
      (rtb_ClockwiseRotation);
    codegenReal2Mission_X.Integrator_CSTATE_g[2] = 150.0;
    codegenReal2Mission_X.Integrator_CSTATE_g[3] = 35.0;
    codegenReal2Mission_X.Integrator_CSTATE_g[4] = rtb_ClockwiseRotation +
      1.5707963267948966;
    codegenReal2Mission_X.Integrator_CSTATE_g[5] = 0.0;
    codegenReal2Mission_X.Integrator_CSTATE_g[6] = 0.0;
    codegenReal2Mission_X.Integrator_CSTATE_g[7] = 0.0;
    rtsiSetBlockStateForSolverChangedAtMajorStep(&(&codegenReal2Mission_M)
      ->solverInfo, true);
    rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
      (&(&codegenReal2Mission_M)->solverInfo, true);

    // End of Outputs for SubSystem: '<S12>/InitializeSimLocation'
    // End of SystemInitialize for SubSystem: '<S3>/MissionSimUAV'

    // SystemInitialize for Atomic SubSystem: '<Root>/GenerateTrack'
    for (i = 0; i < 60; i++) {
      // InitializeConditions for S-Function (sfix_udelay): '<S4>/HeightSequence' 
      codegenReal2Mission_DW.HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<Root>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<Root>/SpeedControl'
    // InitializeConditions for Delay: '<S7>/Speed2d3Path'
    for (i = 0; i < 20; i++) {
      codegenReal2Mission_DW.Speed2d3Path_DSTATE[i] = 35.0;
    }

    // End of InitializeConditions for Delay: '<S7>/Speed2d3Path'

    // SystemInitialize for Atomic SubSystem: '<S7>/ADRC'
    // InitializeConditions for Integrator: '<S73>/Integrator2'
    codegenReal2Mission_X.Integrator2_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S73>/Integrator'
    codegenReal2Mission_X.Integrator_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S73>/Integrator1'
    codegenReal2Mission_X.Integrator1_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S75>/Integrator3'
    codegenReal2Mission_X.Integrator3_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S75>/Integrator2'
    codegenReal2Mission_X.Integrator2_CSTATE_l = 0.0;

    // End of SystemInitialize for SubSystem: '<S7>/ADRC'
    // End of SystemInitialize for SubSystem: '<Root>/SpeedControl'

    // Start for MATLABSystem: '<Root>/TrackSimPath'
    codegenReal2Mission_DW.obj.LastWaypointFlag = false;
    codegenReal2Mission_DW.obj.StartFlag = true;
    codegenReal2Mission_DW.obj.LookaheadFactor = 1.01;
    codegenReal2Mission_DW.obj.SearchFlag = true;
    codegenReal2Mission_DW.obj.isInitialized = 0;
    codegenReal2Mission_DW.obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<Root>/TrackSimPath'
    codegenReal2Mission_DW.obj.WaypointIndex = 1.0;
    for (i = 0; i < 183; i++) {
      // Start for MATLABSystem: '<Root>/TrackSimPath'
      codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);

      // InitializeConditions for MATLABSystem: '<Root>/TrackSimPath'
      codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    // Start for MATLABSystem: '<S3>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.isInitialized = 0;
    codegenReal2Mission_DW.obj_m.isInitialized = 1;
    codegenReal2Mission_DW.obj_m.PrevResetSignal = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_m.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S3>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevResetSignal *= 0.0;
    codegenReal2Mission_DW.obj_m.NumCircles *= 0.0;

    // Start for MATLABSystem: '<S3>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[0] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S3>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[0] *= 0.0;

    // Start for MATLABSystem: '<S3>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[1] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S3>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[1] *= 0.0;

    // Start for MATLABSystem: '<S3>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[2] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S3>/TakeOffGathering'
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
