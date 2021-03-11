//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 1.343
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Mar 11 17:48:09 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
// Code generation objectives:
//    1. Safety precaution
//    2. Execution efficiency
//    3. RAM efficiency
//    4. ROM efficiency
// Validation result: Not run
//
#include "codegenReal2Mission.h"
#include "codegenReal2Mission_private.h"

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
  int_T nXc = 8;
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
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
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
  int32_T i;
  int32_T i2;
  int32_T ix;
  int32_T iy;
  int32_T j;
  int8_T c_data[61];
  boolean_T x[183];
  boolean_T b[61];
  boolean_T exitg1;
  for (i = 0; i < 3; i++) {
    for (i2 = 0; i2 < 60; i2++) {
      iy = 61 * i + i2;
      x[iy] = (waypoints[((i2 + 2) + 61 * i) - 1] != waypoints[iy]);
    }

    x[61 * i + 60] = true;
  }

  for (i = 0; i < 61; i++) {
    b[i] = false;
  }

  iy = -1;
  i = 0;
  i2 = 122;
  for (j = 0; j < 61; j++) {
    i++;
    i2++;
    iy++;
    ix = i;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!x[ix - 1]) {
        ix += 61;
      } else {
        b[iy] = true;
        exitg1 = true;
      }
    }
  }

  iy = 0;
  i2 = 0;
  for (i = 0; i < 61; i++) {
    if (b[i]) {
      iy++;
      c_data[i2] = static_cast<int8_T>(i + 1);
      i2++;
    }
  }

  distinctWpts_size[0] = iy;
  distinctWpts_size[1] = 3;
  for (i = 0; i < 3; i++) {
    for (i2 = 0; i2 < iy; i2++) {
      distinctWpts_data[i2 + iy * i] = waypoints[(61 * i + c_data[i2]) - 1];
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

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isequal(real_T
  varargin_1, real_T varargin_2)
{
  boolean_T p;
  p = false;
  if (varargin_1 == varargin_2) {
    p = true;
  }

  return p;
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
  obj->ModelImpl.Configuration.PDRoll[0] = 102.0891;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -1.5707963267948966;
  obj->ModelImpl.Configuration.PDRoll[1] = 116.66999999999999;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 1.5707963267948966;
  obj->ModelImpl.Configuration.PDRoll[1] = 3.5001;
  obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 1.5707963267948966;
}

// Model step function
void codegenReal2MissionModelClass::step()
{
  // local block i/o variables
  real_T rtb_LookAheadNED_Log[3];
  real_T rtb_TrackSimPath_o5;
  real_T rtb_LagDistance;
  real_T rtb_SpeedProtection;
  real_T rtb_Height;
  real_T rtb_AirSpeed;
  real_T rtb_HeadingAngle;
  real_T rtb_FlightPathAngle;
  real_T rtb_RollAngle_f;
  real_T rtb_RollAngleRate;
  real_T rtb_North_d;
  real_T rtb_East_k;
  real_T rtb_North_dx;
  real_T rtb_FlightPathAngle_c;
  real_T rtb_East_k0;
  real_T rtb_AirSpeed_n;
  real_T rtb_HeadingAngle_g;
  real_T rtb_Height_n;
  real_T rtb_RollAngle_fm;
  real_T rtb_Up2Down;
  boolean_T rtb_Engaged;
  emxArray_real_T_codegenReal2M_T *d_0;
  uav_sluav_internal_system_Way_T *obj;
  real_T b_waypointsIn_data[183];
  real_T rtb_MatrixConcatenate[183];
  real_T appendedWaypoints_data[6];
  real_T b_waypointsIn[3];
  real_T rtb_Sum_nj[3];
  real_T rtb_TmpSignalConversionAtTrac_1[3];
  real_T rtb_TmpSignalConversionAtTrac_2[3];
  real_T u[3];
  real_T distToCenter_tmp[2];
  real_T rtb_TmpSignalConversionAtTrac_0[2];
  real_T Vg;
  real_T b;
  real_T d;
  real_T q;
  real_T rtb_Abs1_m;
  real_T rtb_Abs1_n;
  real_T rtb_FixedWingGuidanceStateBus_F;
  real_T rtb_FixedWingGuidanceStateBus_R;
  real_T rtb_Minus;
  real_T rtb_Speed2d3Path;
  real_T rtb_Sum1_b_idx_1;
  real_T rtb_Sum_kt_idx_1;
  real_T rtb_TmpSignalConversionAtTrac_3;
  real_T v_tmp_0;
  real_T v_tmp_1;
  real_T v_tmp_tmp;
  real_T x2;
  int32_T b_waypointsIn_size[2];
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_exponent_1;
  int32_T b_exponent_2;
  int32_T b_idx;
  int32_T b_k;
  int32_T i;
  int32_T n;
  int32_T v_tmp;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T p;
  boolean_T rEQ0;
  boolean_T rtb_TakeOffTrigger;
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
    // Outputs for Atomic SubSystem: '<Root>/LatLon2NorthEast'
    // Switch: '<S58>/Switch' incorporates:
    //   Gain: '<S18>/Gain1'
    //   Gain: '<S9>/Up2Down'
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_Up2Down = 0.017453292519943295 *
      codegenReal2Mission_U.RealUAVLatLonState.HeadingAngle_deg;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Gain: '<S19>/Gain1'
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_RollAngle_fm = 0.017453292519943295 *
      codegenReal2Mission_U.RealUAVLatLonState.FlightPathAngle_deg;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Gain: '<S20>/Gain1'
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_FlightPathAngle_c = 0.017453292519943295 *
      codegenReal2Mission_U.RealUAVLatLonState.RollAngle_deg;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   DataStoreRead: '<S4>/AltitudeGCS'
    //   Gain: '<S4>/inverse'
    //   Inport: '<Root>/RealUAVLatLonState'
    //   Sum: '<S21>/Sum'

    rtb_HeadingAngle_g = -codegenReal2Mission_DW.AltitudeGCS;
    rtb_HeadingAngle_g += codegenReal2Mission_U.RealUAVLatLonState.Height_meter;

    // Switch: '<S35>/Switch' incorporates:
    //   Abs: '<S35>/Abs'
    //   DataStoreRead: '<S4>/LatitudeGCS'
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'

    rtb_AirSpeed_n = std::abs(codegenReal2Mission_DW.LatitudeGCS);

    // Switch: '<S35>/Switch' incorporates:
    //   Constant: '<S36>/Constant'
    //   RelationalOperator: '<S36>/Compare'

    if (rtb_AirSpeed_n > 180.0) {
      // Switch: '<S35>/Switch' incorporates:
      //   Bias: '<S35>/Bias'
      //   Bias: '<S35>/Bias1'
      //   Constant: '<S35>/Constant2'
      //   DataStoreRead: '<S4>/LatitudeGCS'
      //   Math: '<S35>/Math Function1'

      rtb_AirSpeed_n = rt_modd_snf(codegenReal2Mission_DW.LatitudeGCS + 180.0,
        360.0) + -180.0;
    } else {
      // Switch: '<S35>/Switch' incorporates:
      //   DataStoreRead: '<S4>/LatitudeGCS'

      rtb_AirSpeed_n = codegenReal2Mission_DW.LatitudeGCS;
    }

    // End of Switch: '<S35>/Switch'

    // Abs: '<S32>/Abs1'
    rtb_Abs1_m = std::abs(rtb_AirSpeed_n);

    // Switch: '<S32>/Switch' incorporates:
    //   Constant: '<S34>/Constant'
    //   RelationalOperator: '<S34>/Compare'
    //   Switch: '<S23>/Switch1'

    if (rtb_Abs1_m > 90.0) {
      // Signum: '<S32>/Sign1'
      if (rtb_AirSpeed_n < 0.0) {
        rtb_Abs1_n = -1.0;
      } else if (rtb_AirSpeed_n > 0.0) {
        rtb_Abs1_n = 1.0;
      } else if (rtb_AirSpeed_n == 0.0) {
        rtb_Abs1_n = 0.0;
      } else {
        rtb_Abs1_n = (rtNaN);
      }

      // End of Signum: '<S32>/Sign1'

      // Switch: '<S35>/Switch' incorporates:
      //   Bias: '<S32>/Bias'
      //   Bias: '<S32>/Bias1'
      //   Gain: '<S32>/Gain'
      //   Product: '<S32>/Divide1'
      //   SignalConversion generated from: '<Root>/SimUAVStateBus'

      rtb_AirSpeed_n = (-(rtb_Abs1_m + -90.0) + 90.0) * rtb_Abs1_n;

      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Constant: '<S23>/Constant'

      rtb_Height_n = 180.0;
    } else {
      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Constant: '<S23>/Constant1'

      rtb_Height_n = 0.0;
    }

    // End of Switch: '<S32>/Switch'

    // Sum: '<S23>/Sum' incorporates:
    //   DataStoreRead: '<S4>/LongitudeGCS'

    rtb_Abs1_m = rtb_Height_n + codegenReal2Mission_DW.LongitudeGCS;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Abs: '<S33>/Abs'

    rtb_Height_n = std::abs(rtb_Abs1_m);

    // Switch: '<S33>/Switch' incorporates:
    //   Constant: '<S37>/Constant'
    //   RelationalOperator: '<S37>/Compare'

    if (rtb_Height_n > 180.0) {
      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Bias: '<S33>/Bias'
      //   Bias: '<S33>/Bias1'
      //   Constant: '<S33>/Constant2'
      //   Math: '<S33>/Math Function1'

      rtb_Height_n = rt_modd_snf(rtb_Abs1_m + 180.0, 360.0) + -180.0;
    } else {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_Height_n = rtb_Abs1_m;
    }

    // End of Switch: '<S33>/Switch'

    // Sum: '<S21>/Sum1' incorporates:
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_Abs1_m = codegenReal2Mission_U.RealUAVLatLonState.Latitude_deg -
      rtb_AirSpeed_n;
    rtb_Sum1_b_idx_1 = codegenReal2Mission_U.RealUAVLatLonState.Longitude_deg -
      rtb_Height_n;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Abs: '<S29>/Abs'

    rtb_Height_n = std::abs(rtb_Abs1_m);

    // Switch: '<S29>/Switch' incorporates:
    //   Bias: '<S29>/Bias'
    //   Bias: '<S29>/Bias1'
    //   Constant: '<S29>/Constant2'
    //   Constant: '<S30>/Constant'
    //   Math: '<S29>/Math Function1'
    //   RelationalOperator: '<S30>/Compare'

    if (rtb_Height_n > 180.0) {
      rtb_Abs1_m = rt_modd_snf(rtb_Abs1_m + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S29>/Switch'

    // Abs: '<S26>/Abs1'
    rtb_Abs1_n = std::abs(rtb_Abs1_m);

    // Switch: '<S26>/Switch' incorporates:
    //   Constant: '<S28>/Constant'
    //   RelationalOperator: '<S28>/Compare'
    //   Switch: '<S22>/Switch1'

    if (rtb_Abs1_n > 90.0) {
      // Signum: '<S26>/Sign1'
      if (rtb_Abs1_m < 0.0) {
        rtb_Abs1_m = -1.0;
      } else if (rtb_Abs1_m > 0.0) {
        rtb_Abs1_m = 1.0;
      } else if (rtb_Abs1_m == 0.0) {
        rtb_Abs1_m = 0.0;
      } else {
        rtb_Abs1_m = (rtNaN);
      }

      // End of Signum: '<S26>/Sign1'

      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Bias: '<S26>/Bias'
      //   Bias: '<S26>/Bias1'
      //   Gain: '<S26>/Gain'
      //   Product: '<S26>/Divide1'

      rtb_Height_n = (-(rtb_Abs1_n + -90.0) + 90.0) * rtb_Abs1_m;

      // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
      //   Constant: '<S22>/Constant'
      //   SignalConversion generated from: '<Root>/SimUAVStateBus'

      rtb_East_k0 = 180.0;
    } else {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_Height_n = rtb_Abs1_m;

      // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
      //   Constant: '<S22>/Constant1'
      //   SignalConversion generated from: '<Root>/SimUAVStateBus'

      rtb_East_k0 = 0.0;
    }

    // End of Switch: '<S26>/Switch'

    // Sum: '<S22>/Sum'
    rtb_Abs1_m = rtb_East_k0 + rtb_Sum1_b_idx_1;

    // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
    //   Abs: '<S27>/Abs'
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'

    rtb_East_k0 = std::abs(rtb_Abs1_m);

    // Switch: '<S27>/Switch' incorporates:
    //   Constant: '<S31>/Constant'
    //   RelationalOperator: '<S31>/Compare'

    if (rtb_East_k0 > 180.0) {
      // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
      //   Bias: '<S27>/Bias'
      //   Bias: '<S27>/Bias1'
      //   Constant: '<S27>/Constant2'
      //   Math: '<S27>/Math Function1'
      //   SignalConversion generated from: '<Root>/SimUAVStateBus'

      rtb_East_k0 = rt_modd_snf(rtb_Abs1_m + 180.0, 360.0) + -180.0;
    } else {
      // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
      //   SignalConversion generated from: '<Root>/SimUAVStateBus'

      rtb_East_k0 = rtb_Abs1_m;
    }

    // End of Switch: '<S27>/Switch'

    // UnitConversion: '<S25>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Abs1_m = 0.017453292519943295 * rtb_Height_n;
    rtb_Sum1_b_idx_1 = 0.017453292519943295 * rtb_East_k0;

    // Switch: '<S35>/Switch' incorporates:
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'
    //   UnitConversion: '<S40>/Unit Conversion'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_AirSpeed_n *= 0.017453292519943295;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Constant: '<S41>/Constant'
    //   Product: '<S41>/Product1'
    //   Sum: '<S41>/Sum1'
    //   Trigonometry: '<S41>/Trigonometric Function1'

    rtb_Height_n = std::sin(rtb_AirSpeed_n);
    rtb_Height_n = 1.0 - codegenReal2Mission_ConstB.sqrt_c *
      codegenReal2Mission_ConstB.sqrt_c * rtb_Height_n * rtb_Height_n;

    // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
    //   Constant: '<S39>/Constant1'
    //   Product: '<S39>/Product1'
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'
    //   Sqrt: '<S39>/sqrt'

    rtb_East_k0 = std::sqrt(rtb_Height_n);
    rtb_East_k0 = 6.378137E+6 / rtb_East_k0;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Constant: '<S39>/Constant2'
    //   Product: '<S24>/dNorth'
    //   Product: '<S39>/Product3'
    //   Trigonometry: '<S39>/Trigonometric Function1'

    rtb_Height_n = rt_atan2d_snf(1.0, rtb_East_k0 *
      codegenReal2Mission_ConstB.Sum1_m / rtb_Height_n);
    rtb_Height_n = rtb_Abs1_m / rtb_Height_n;

    // Switch: '<S35>/Switch' incorporates:
    //   Constant: '<S39>/Constant3'
    //   Product: '<S24>/dEast'
    //   Product: '<S39>/Product4'
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'
    //   Trigonometry: '<S39>/Trigonometric Function'
    //   Trigonometry: '<S39>/Trigonometric Function2'

    rtb_AirSpeed_n = rt_atan2d_snf(1.0, rtb_East_k0 * std::cos(rtb_AirSpeed_n));
    rtb_AirSpeed_n = 1.0 / rtb_AirSpeed_n * rtb_Sum1_b_idx_1;

    // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
    //   Product: '<S24>/x*cos'
    //   Product: '<S24>/y*sin'
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'
    //   Sum: '<S24>/Sum2'

    rtb_East_k0 = rtb_Height_n * codegenReal2Mission_ConstB.SinCos_o2_o +
      rtb_AirSpeed_n * codegenReal2Mission_ConstB.SinCos_o1_l;

    // Switch: '<S35>/Switch' incorporates:
    //   Product: '<S24>/x*sin'
    //   Product: '<S24>/y*cos'
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'
    //   Sum: '<S24>/Sum3'

    rtb_AirSpeed_n = rtb_AirSpeed_n * codegenReal2Mission_ConstB.SinCos_o2_o -
      rtb_Height_n * codegenReal2Mission_ConstB.SinCos_o1_l;

    // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
    //   Inport: '<Root>/RealUAVLatLonState'

    rtb_Abs1_m = rtb_HeadingAngle_g;
    rtb_Abs1_n = codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps;
    x2 = rtb_Up2Down;
    rtb_FixedWingGuidanceStateBus_F = rtb_RollAngle_fm;
    rtb_FixedWingGuidanceStateBus_R = rtb_FlightPathAngle_c;

    // End of Outputs for SubSystem: '<Root>/LatLon2NorthEast'

    // Chart: '<Root>/TASgreaterthan15for1Sec' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
    //   Inport: '<Root>/RealUAVLatLonState'

    if (codegenReal2Mission_DW.is_active_c1_codegenReal2Missio == 0U) {
      codegenReal2Mission_DW.is_active_c1_codegenReal2Missio = 1U;
      codegenReal2Mission_DW.is_c1_codegenReal2Mission =
        codegenReal2Missi_IN_NotTakeOff;
      rtb_TakeOffTrigger = false;
      codegenReal2Mission_DW.DataCounter_f = 0.0;
    } else if (codegenReal2Mission_DW.is_c1_codegenReal2Mission == 1) {
      rtb_TakeOffTrigger = true;
    } else {
      // case IN_NotTakeOff:
      if (codegenReal2Mission_DW.DataCounter_f >= 9.0) {
        codegenReal2Mission_DW.is_c1_codegenReal2Mission =
          codegenReal2Mission_IN_InAir;
        rtb_TakeOffTrigger = true;
      } else {
        // Outputs for Atomic SubSystem: '<Root>/LatLon2NorthEast'
        if (codegenReal2Mission_U.RealUAVLatLonState.AirSpeed_mps < 15.0) {
          codegenReal2Mission_DW.is_c1_codegenReal2Mission =
            codegenReal2Missi_IN_NotTakeOff;
          rtb_TakeOffTrigger = false;
          codegenReal2Mission_DW.DataCounter_f = 0.0;
        } else {
          rtb_TakeOffTrigger = false;
          codegenReal2Mission_DW.DataCounter_f++;
        }

        // End of Outputs for SubSystem: '<Root>/LatLon2NorthEast'
      }
    }

    // End of Chart: '<Root>/TASgreaterthan15for1Sec'

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   Memory: '<S2>/Memory'

    rtb_East_k = codegenReal2Mission_DW.Memory_PreviousInput;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   DataStoreRead: '<S2>/UAVidx'
    //   DataTypeConversion: '<S2>/Cast To Double'

    rtb_North_dx = codegenReal2Mission_DW.UAVidx;

    // Sum: '<S2>/Minus' incorporates:
    //   Bias: '<S2>/Bias'
    //   DataStoreRead: '<S2>/numMissionUAV'
    //   Gain: '<S2>/FindMiddle'

    rtb_Minus = rtb_North_dx - static_cast<real_T>(static_cast<int64_T>
      (codegenReal2Mission_DW.numMissionUAV + 1) << 30) * 4.6566128730773926E-10;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   Constant: '<S2>/2pi'
    //   DataStoreRead: '<S2>/numMissionUAV'
    //   Product: '<S2>/Divide'

    rtb_North_dx = 6.2831853071795862 / static_cast<real_T>
      (codegenReal2Mission_DW.numMissionUAV);

    // Delay: '<S2>/Delay'
    if (codegenReal2Mission_DW.icLoad != 0) {
      // BusCreator: '<S2>/Bus Creator' incorporates:
      //   Bias: '<S2>/Rotate90Deg'
      //   Product: '<S2>/Map2Radian'

      codegenReal2Mission_DW.Delay_DSTATE = rtb_Minus * rtb_North_dx +
        1.5707963267948966;
    }

    // End of Delay: '<S2>/Delay'

    // Outputs for Atomic SubSystem: '<S2>/MissionSimUAV'
    // Switch: '<S58>/Switch' incorporates:
    //   BusCreator: '<S2>/Bus Creator'
    //   Constant: '<S2>/MissionAirspeed'
    //   Gain: '<S9>/Up2Down'
    //   Saturate: '<S10>/AirspeedSaturation'

    rtb_Up2Down = 35.0;

    // Saturate: '<S10>/AltitudeSaturation' incorporates:
    //   BusCreator: '<S2>/Bus Creator'

    if (rtb_East_k > 500.0) {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_RollAngle_fm = 500.0;
    } else if (rtb_East_k < 100.0) {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_RollAngle_fm = 100.0;
    } else {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_RollAngle_fm = rtb_East_k;
    }

    // End of Saturate: '<S10>/AltitudeSaturation'

    // RateLimiter: '<S10>/ClimbRateLimiter'
    rtb_Minus = rtb_RollAngle_fm - codegenReal2Mission_DW.PrevY;
    if (rtb_Minus > 0.5) {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_RollAngle_fm = codegenReal2Mission_DW.PrevY + 0.5;
    } else {
      if (rtb_Minus < -0.5) {
        // SignalConversion generated from: '<Root>/SimUAVStateBus'
        rtb_RollAngle_fm = codegenReal2Mission_DW.PrevY + -0.5;
      }
    }

    codegenReal2Mission_DW.PrevY = rtb_RollAngle_fm;

    // End of RateLimiter: '<S10>/ClimbRateLimiter'

    // BusCreator: '<S10>/FixedWingGuidanceEnvironmentBus' incorporates:
    //   Constant: '<S10>/Gravity'
    //   Constant: '<S10>/NoWind'

    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth = 0.0;
    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast = 0.0;
    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown = 0.0;
    codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity = 9.807;

    // Sum: '<S12>/Sum' incorporates:
    //   Gain: '<S12>/Gain'
    //   Sum: '<S12>/Diff'
    //   UnitDelay: '<S12>/UD'
    //
    //  Block description for '<S12>/Sum':
    //
    //   Add in CPU
    //
    //  Block description for '<S12>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S12>/UD':
    //
    //   Store in Global RAM

    codegenReal2Mission_DW.UD_DSTATE_f = (codegenReal2Mission_DW.UD_DSTATE_f -
      rtb_RollAngle_fm) * 0.8 + rtb_RollAngle_fm;

    // End of Outputs for SubSystem: '<S2>/MissionSimUAV'
  }

  // Outputs for Atomic SubSystem: '<S2>/MissionSimUAV'
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // MATLAB Function: '<S10>/SimHeadingControl' incorporates:
    //   BusCreator: '<S2>/Bus Creator'
    //   Integrator: '<S16>/Integrator'

    rtb_Minus = 1.0 / codegenReal2Mission_X.Integrator_CSTATE[3];
    rtb_Sum1_b_idx_1 = std::cos(codegenReal2Mission_X.Integrator_CSTATE[5]);
    b = std::sin(codegenReal2Mission_X.Integrator_CSTATE[4]);
    Vg = std::cos(codegenReal2Mission_X.Integrator_CSTATE[4]);
    rtb_Sum1_b_idx_1 = (Vg * rtb_Sum1_b_idx_1 *
                        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth
                        + b * rtb_Sum1_b_idx_1 *
                        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast)
      + -std::sin(codegenReal2Mission_X.Integrator_CSTATE[5]) *
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown;
    d = codegenReal2Mission_DW.Delay_DSTATE -
      codegenReal2Mission_X.Integrator_CSTATE[4];
    if (std::abs(d) > 3.1415926535897931) {
      if (rtIsNaN(d + 3.1415926535897931)) {
        rtb_Speed2d3Path = (rtNaN);
      } else if (rtIsInf(d + 3.1415926535897931)) {
        rtb_Speed2d3Path = (rtNaN);
      } else if (d + 3.1415926535897931 == 0.0) {
        rtb_Speed2d3Path = 0.0;
      } else {
        rtb_Speed2d3Path = std::fmod(d + 3.1415926535897931, 6.2831853071795862);
        rEQ0 = (rtb_Speed2d3Path == 0.0);
        if (!rEQ0) {
          q = std::abs((d + 3.1415926535897931) / 6.2831853071795862);
          rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 *
                   q);
        }

        if (rEQ0) {
          rtb_Speed2d3Path = 0.0;
        } else {
          if (d + 3.1415926535897931 < 0.0) {
            rtb_Speed2d3Path += 6.2831853071795862;
          }
        }
      }

      if ((rtb_Speed2d3Path == 0.0) && (d + 3.1415926535897931 > 0.0)) {
        rtb_Speed2d3Path = 6.2831853071795862;
      }

      d = rtb_Speed2d3Path - 3.1415926535897931;
    }

    rtb_RollAngle_fm = rt_atan2d_snf((std::sqrt(rtb_Sum1_b_idx_1 *
      rtb_Sum1_b_idx_1 -
      (((codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth *
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth +
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast *
         codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast) +
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown) -
       codegenReal2Mission_X.Integrator_CSTATE[3] *
       codegenReal2Mission_X.Integrator_CSTATE[3])) + -rtb_Sum1_b_idx_1) * (0.39
      * d), std::cos(codegenReal2Mission_X.Integrator_CSTATE[4] -
                     (codegenReal2Mission_X.Integrator_CSTATE[4] - std::asin
                      (rtb_Minus *
                       codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth
                       * -b + rtb_Minus *
                       codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast
                       * Vg))) *
      codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity);

    // End of MATLAB Function: '<S10>/SimHeadingControl'

    // Saturate: '<S10>/RollAngleSaturation'
    if (rtb_RollAngle_fm > 0.52359877559829882) {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_RollAngle_fm = 0.52359877559829882;
    } else {
      if (rtb_RollAngle_fm < -0.52359877559829882) {
        // SignalConversion generated from: '<Root>/SimUAVStateBus'
        rtb_RollAngle_fm = -0.52359877559829882;
      }
    }

    // End of Saturate: '<S10>/RollAngleSaturation'

    // Sum: '<S14>/Sum' incorporates:
    //   Gain: '<S14>/Gain'
    //   Sum: '<S14>/Diff'
    //   UnitDelay: '<S14>/UD'
    //
    //  Block description for '<S14>/Sum':
    //
    //   Add in CPU
    //
    //  Block description for '<S14>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S14>/UD':
    //
    //   Store in Global RAM

    codegenReal2Mission_DW.UD_DSTATE_j = (codegenReal2Mission_DW.UD_DSTATE_j -
      rtb_RollAngle_fm) * 0.8 + rtb_RollAngle_fm;

    // Sum: '<S17>/Sum' incorporates:
    //   Gain: '<S17>/Gain'
    //   Sum: '<S17>/Diff'
    //   UnitDelay: '<S17>/UD'
    //
    //  Block description for '<S17>/Sum':
    //
    //   Add in CPU
    //
    //  Block description for '<S17>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S17>/UD':
    //
    //   Store in Global RAM

    codegenReal2Mission_DW.UD_DSTATE_jn = (codegenReal2Mission_DW.UD_DSTATE_jn -
      rtb_Up2Down) * 0.8 + rtb_Up2Down;

    // BusCreator: '<S10>/Slew Guidance Bus' incorporates:
    //   UnitDelay: '<S12>/UD'
    //   UnitDelay: '<S14>/UD'
    //   UnitDelay: '<S17>/UD'
    //
    //  Block description for '<S12>/UD':
    //
    //   Store in Global RAM
    //
    //  Block description for '<S14>/UD':
    //
    //   Store in Global RAM
    //
    //  Block description for '<S17>/UD':
    //
    //   Store in Global RAM

    codegenReal2Mission_B.SlewGuidanceBus.Height =
      codegenReal2Mission_DW.UD_DSTATE_f;
    codegenReal2Mission_B.SlewGuidanceBus.AirSpeed =
      codegenReal2Mission_DW.UD_DSTATE_jn;
    codegenReal2Mission_B.SlewGuidanceBus.RollAngle =
      codegenReal2Mission_DW.UD_DSTATE_j;
  }

  // MATLABSystem: '<S16>/ComputeDerivative' incorporates:
  //   Integrator: '<S16>/Integrator'

  rtb_Minus = std::cos(codegenReal2Mission_X.Integrator_CSTATE[5]);
  d = std::cos(codegenReal2Mission_X.Integrator_CSTATE[4]);
  rtb_Speed2d3Path = std::sin(codegenReal2Mission_X.Integrator_CSTATE[4]);
  rtb_Sum1_b_idx_1 = std::sin(codegenReal2Mission_X.Integrator_CSTATE[5]);
  Vg = (-(d * rtb_Minus) *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth +
        -(rtb_Speed2d3Path * rtb_Minus) *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast) +
    rtb_Sum1_b_idx_1 *
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
  codegenReal2Mission_B.ComputeDerivative[0] = Vg * d * rtb_Minus;
  codegenReal2Mission_B.ComputeDerivative[1] = Vg * rtb_Speed2d3Path * rtb_Minus;
  codegenReal2Mission_B.ComputeDerivative[2] = Vg * rtb_Sum1_b_idx_1;
  codegenReal2Mission_B.ComputeDerivative[3] =
    (codegenReal2Mission_B.SlewGuidanceBus.AirSpeed -
     codegenReal2Mission_X.Integrator_CSTATE[3]) *
    codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PAirSpeed;
  if (Vg == 0.0) {
    codegenReal2Mission_B.ComputeDerivative[4] = 0.0;
    codegenReal2Mission_B.ComputeDerivative[5] = 0.0;
  } else {
    if (codegenReal2Mission_X.Integrator_CSTATE[3] == 0.0) {
      codegenReal2Mission_B.ComputeDerivative[4] = 0.0;
    } else {
      rtb_Minus = 1.0 / (std::cos(std::asin((Vg * std::sin
        (codegenReal2Mission_X.Integrator_CSTATE[5]) +
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindDown) /
        codegenReal2Mission_X.Integrator_CSTATE[3])) *
                         codegenReal2Mission_X.Integrator_CSTATE[3]);
      codegenReal2Mission_B.ComputeDerivative[4] = std::cos(std::asin(rtb_Minus *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindNorth * -std::
        sin(codegenReal2Mission_X.Integrator_CSTATE[4]) + rtb_Minus *
        codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.WindEast * d)) *
        (codegenReal2Mission_B.FixedWingGuidanceEnvironmentB_g.Gravity / Vg *
         std::tan(codegenReal2Mission_X.Integrator_CSTATE[6]));
    }

    Vg = (codegenReal2Mission_B.SlewGuidanceBus.Height -
          codegenReal2Mission_X.Integrator_CSTATE[2]) *
      codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PHeight / Vg;
    if (!(Vg < 1.0)) {
      Vg = 1.0;
    }

    if (!(Vg > -1.0)) {
      Vg = -1.0;
    }

    Vg = std::asin(Vg);
    if ((!(Vg <
           codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
           [1])) && (!rtIsNaN
                     (codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
                      [1]))) {
      Vg =
        codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
        [1];
    }

    if ((!(Vg >
           codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
           [0])) && (!rtIsNaN
                     (codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
                      [0]))) {
      Vg =
        codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.FlightPathAngleLimits
        [0];
    }

    codegenReal2Mission_B.ComputeDerivative[5] = (Vg -
      codegenReal2Mission_X.Integrator_CSTATE[5]) *
      codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PFlightPathAngle;
  }

  codegenReal2Mission_B.ComputeDerivative[6] =
    codegenReal2Mission_X.Integrator_CSTATE[7];
  if (codegenReal2Mission_B.SlewGuidanceBus.RollAngle < 1.5707963267948966) {
    rtb_Sum1_b_idx_1 = codegenReal2Mission_B.SlewGuidanceBus.RollAngle;
  } else {
    rtb_Sum1_b_idx_1 = 1.5707963267948966;
  }

  if (!(rtb_Sum1_b_idx_1 > -1.5707963267948966)) {
    rtb_Sum1_b_idx_1 = -1.5707963267948966;
  }

  codegenReal2Mission_B.ComputeDerivative[7] = (rtb_Sum1_b_idx_1 -
    codegenReal2Mission_X.Integrator_CSTATE[6]) *
    codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PDRoll[0] +
    codegenReal2Mission_DW.obj_a.ModelImpl.Configuration.PDRoll[1] *
    -codegenReal2Mission_X.Integrator_CSTATE[7];

  // End of MATLABSystem: '<S16>/ComputeDerivative'
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // ZeroOrderHold: '<S10>/SimUAVStateZOH' incorporates:
    //   Integrator: '<S16>/Integrator'

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

    // Outputs for Atomic SubSystem: '<Root>/GenerateTrack'
    // S-Function (sfix_udelay): '<S3>/EastSequence'
    rtb_MatrixConcatenate[121] = codegenReal2Mission_B.SimUAVStateZOH.East;

    // Gain: '<S3>/Gain7'
    codegenReal2Mission_B.Gain7 = -codegenReal2Mission_B.SimUAVStateZOH.Height;

    // S-Function (sfix_udelay): '<S3>/HeightSequence'
    rtb_MatrixConcatenate[182] = codegenReal2Mission_B.Gain7;
    for (i = 0; i < 60; i++) {
      // S-Function (sfix_udelay): '<S3>/EastSequence'
      rtb_MatrixConcatenate[i + 61] = codegenReal2Mission_DW.EastSequence_X[i];

      // S-Function (sfix_udelay): '<S3>/HeightSequence'
      rtb_MatrixConcatenate[i + 122] = codegenReal2Mission_DW.HeightSequence_X[i];

      // S-Function (sfix_udelay): '<S3>/NorthSequence'
      rtb_MatrixConcatenate[i] = codegenReal2Mission_DW.NorthSequence_X[i];
    }

    // S-Function (sfix_udelay): '<S3>/NorthSequence'
    rtb_MatrixConcatenate[60] = codegenReal2Mission_B.SimUAVStateZOH.North;
    for (i = 0; i < 59; i++) {
      // Update for S-Function (sfix_udelay): '<S3>/EastSequence'
      codegenReal2Mission_DW.EastSequence_X[i] =
        codegenReal2Mission_DW.EastSequence_X[i + 1];

      // Update for S-Function (sfix_udelay): '<S3>/HeightSequence'
      codegenReal2Mission_DW.HeightSequence_X[i] =
        codegenReal2Mission_DW.HeightSequence_X[i + 1];

      // Update for S-Function (sfix_udelay): '<S3>/NorthSequence'
      codegenReal2Mission_DW.NorthSequence_X[i] =
        codegenReal2Mission_DW.NorthSequence_X[i + 1];
    }

    // Update for S-Function (sfix_udelay): '<S3>/EastSequence'
    codegenReal2Mission_DW.EastSequence_X[59] =
      codegenReal2Mission_B.SimUAVStateZOH.East;

    // Update for S-Function (sfix_udelay): '<S3>/HeightSequence'
    codegenReal2Mission_DW.HeightSequence_X[59] = codegenReal2Mission_B.Gain7;

    // Update for S-Function (sfix_udelay): '<S3>/NorthSequence'
    codegenReal2Mission_DW.NorthSequence_X[59] =
      codegenReal2Mission_B.SimUAVStateZOH.North;

    // Outputs for Atomic SubSystem: '<Root>/SpeedControl'
    // Sum: '<S69>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   S-Function (sfix_udelay): '<S3>/NorthSequence'
    //   Selector: '<S6>/WayPoint1d3'

    rtb_Minus = rtb_MatrixConcatenate[40] -
      codegenReal2Mission_B.SimUAVStateZOH.North;

    // End of Outputs for SubSystem: '<Root>/GenerateTrack'

    // DotProduct: '<S69>/Dot Product'
    rtb_Sum1_b_idx_1 = rtb_Minus * rtb_Minus;

    // Outputs for Atomic SubSystem: '<Root>/GenerateTrack'
    // Sum: '<S70>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   S-Function (sfix_udelay): '<S3>/NorthSequence'
    //   Selector: '<S6>/WayPoint2d3'

    rtb_Minus = rtb_MatrixConcatenate[20] -
      codegenReal2Mission_B.SimUAVStateZOH.North;

    // End of Outputs for SubSystem: '<Root>/GenerateTrack'

    // DotProduct: '<S70>/Dot Product'
    rtb_Speed2d3Path = rtb_Minus * rtb_Minus;

    // Outputs for Atomic SubSystem: '<Root>/GenerateTrack'
    // Sum: '<S71>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   S-Function (sfix_udelay): '<S3>/NorthSequence'
    //   Selector: '<S6>/WayPoint3d3'

    rtb_Minus = rtb_MatrixConcatenate[0] -
      codegenReal2Mission_B.SimUAVStateZOH.North;

    // End of Outputs for SubSystem: '<Root>/GenerateTrack'

    // DotProduct: '<S71>/Dot Product'
    d = rtb_Minus * rtb_Minus;

    // Sum: '<S69>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   Selector: '<S6>/WayPoint0d3'
    //   Selector: '<S6>/WayPoint1d3'

    rtb_Minus = rtb_MatrixConcatenate[101] - rtb_MatrixConcatenate[121];

    // DotProduct: '<S69>/Dot Product'
    rtb_Sum1_b_idx_1 += rtb_Minus * rtb_Minus;

    // Sum: '<S70>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   Selector: '<S6>/WayPoint0d3'
    //   Selector: '<S6>/WayPoint2d3'

    rtb_Minus = rtb_MatrixConcatenate[81] - rtb_MatrixConcatenate[121];

    // DotProduct: '<S70>/Dot Product'
    rtb_Speed2d3Path += rtb_Minus * rtb_Minus;

    // Sum: '<S71>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   Selector: '<S6>/WayPoint0d3'
    //   Selector: '<S6>/WayPoint3d3'

    rtb_Minus = rtb_MatrixConcatenate[61] - rtb_MatrixConcatenate[121];

    // DotProduct: '<S71>/Dot Product'
    d += rtb_Minus * rtb_Minus;

    // Sum: '<S69>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   Selector: '<S6>/WayPoint0d3'
    //   Selector: '<S6>/WayPoint1d3'

    rtb_Minus = rtb_MatrixConcatenate[162] - rtb_MatrixConcatenate[182];

    // Switch: '<S58>/Switch' incorporates:
    //   DotProduct: '<S69>/Dot Product'
    //   Gain: '<S9>/Up2Down'

    rtb_Up2Down = rtb_Minus * rtb_Minus + rtb_Sum1_b_idx_1;

    // Sum: '<S70>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   Selector: '<S6>/WayPoint0d3'
    //   Selector: '<S6>/WayPoint2d3'

    rtb_Minus = rtb_MatrixConcatenate[142] - rtb_MatrixConcatenate[182];

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   DotProduct: '<S70>/Dot Product'

    rtb_RollAngle_fm = rtb_Minus * rtb_Minus + rtb_Speed2d3Path;

    // Sum: '<S71>/Sum' incorporates:
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   Selector: '<S6>/WayPoint0d3'
    //   Selector: '<S6>/WayPoint3d3'

    rtb_Minus = rtb_MatrixConcatenate[122] - rtb_MatrixConcatenate[182];

    // DotProduct: '<S71>/Dot Product'
    d += rtb_Minus * rtb_Minus;

    // Switch: '<S58>/Switch' incorporates:
    //   Gain: '<S9>/Up2Down'
    //   Sqrt: '<S69>/sqrt'

    rtb_Up2Down = std::sqrt(rtb_Up2Down);

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Sqrt: '<S70>/sqrt'

    rtb_RollAngle_fm = std::sqrt(rtb_RollAngle_fm);

    // Sum: '<S6>/ComputeLB'
    rtb_Minus = rtb_Up2Down - rtb_RollAngle_fm;

    // Switch: '<S58>/Switch' incorporates:
    //   DotProduct: '<S71>/Dot Product'
    //   Gain: '<S9>/Up2Down'
    //   Sqrt: '<S71>/sqrt'

    rtb_Up2Down = d;
    rtb_Up2Down = std::sqrt(rtb_Up2Down);

    // Sum: '<S6>/ComputeUB'
    d = rtb_Up2Down - rtb_RollAngle_fm;

    // Sum: '<S68>/Sum' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_Sum_nj[0] = codegenReal2Mission_B.SimUAVStateZOH.North - rtb_East_k0;
    rtb_Sum_nj[1] = codegenReal2Mission_B.SimUAVStateZOH.East - rtb_AirSpeed_n;
    rtb_Sum_nj[2] = codegenReal2Mission_B.SimUAVStateZOH.Height - rtb_Abs1_m;

    // Switch: '<S58>/Switch' incorporates:
    //   DotProduct: '<S68>/Dot Product'
    //   Gain: '<S9>/Up2Down'
    //   Sqrt: '<S68>/sqrt'

    rtb_Up2Down = (rtb_Sum_nj[0] * rtb_Sum_nj[0] + rtb_Sum_nj[1] * rtb_Sum_nj[1])
      + rtb_Sum_nj[2] * rtb_Sum_nj[2];
    rtb_Up2Down = std::sqrt(rtb_Up2Down);

    // Sum: '<S6>/RangeDiff'
    rtb_LagDistance = rtb_RollAngle_fm - rtb_Up2Down;

    // Switch: '<S58>/Switch' incorporates:
    //   Gain: '<S97>/Derivative Gain'
    //   Gain: '<S9>/Up2Down'

    rtb_Up2Down = -0.01 * rtb_LagDistance;

    // SampleTimeMath: '<S100>/Tsamp'
    //
    //  About '<S100>/Tsamp':
    //   y = u * K where K = 1 / ( w * Ts )

    rtb_Sum1_b_idx_1 = rtb_Up2Down * 10.0;

    // Delay: '<S98>/UD'
    if (rtb_TakeOffTrigger && (codegenReal2Mission_PrevZCX.UD_Reset_ZCE != 1)) {
      codegenReal2Mission_DW.UD_DSTATE = 0.0;
    }

    codegenReal2Mission_PrevZCX.UD_Reset_ZCE = rtb_TakeOffTrigger;

    // Delay: '<S6>/Speed2d3Path'
    rtb_Speed2d3Path = codegenReal2Mission_DW.Speed2d3Path_DSTATE[0];

    // Switch: '<S58>/Switch' incorporates:
    //   Delay: '<S6>/Speed2d3Path'
    //   Delay: '<S98>/UD'
    //   Gain: '<S110>/Proportional Gain'
    //   Gain: '<S9>/Up2Down'
    //   Sum: '<S114>/Sum'
    //   Sum: '<S6>/Sum3'
    //   Sum: '<S98>/Diff'

    rtb_Up2Down = (-0.2 * rtb_LagDistance + (rtb_Sum1_b_idx_1 -
      codegenReal2Mission_DW.UD_DSTATE)) +
      codegenReal2Mission_DW.Speed2d3Path_DSTATE[0];

    // Saturate: '<S6>/SpeedProtection'
    if (rtb_Up2Down > 42.0) {
      // Saturate: '<S6>/SpeedProtection'
      rtb_SpeedProtection = 42.0;
    } else if (rtb_Up2Down < 28.0) {
      // Saturate: '<S6>/SpeedProtection'
      rtb_SpeedProtection = 28.0;
    } else {
      // Saturate: '<S6>/SpeedProtection'
      rtb_SpeedProtection = rtb_Up2Down;
    }

    // End of Saturate: '<S6>/SpeedProtection'

    // Update for Delay: '<S98>/UD'
    codegenReal2Mission_DW.UD_DSTATE = rtb_Sum1_b_idx_1;

    // Update for Delay: '<S6>/Speed2d3Path'
    for (i = 0; i < 19; i++) {
      codegenReal2Mission_DW.Speed2d3Path_DSTATE[i] =
        codegenReal2Mission_DW.Speed2d3Path_DSTATE[i + 1];
    }

    codegenReal2Mission_DW.Speed2d3Path_DSTATE[19] =
      codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

    // End of Update for Delay: '<S6>/Speed2d3Path'
    // End of Outputs for SubSystem: '<Root>/SpeedControl'

    // Outport: '<Root>/RefAirspeed'
    codegenReal2Mission_Y.RefAirspeed = rtb_SpeedProtection;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
    //   Gain: '<Root>/Height2Down'

    rtb_North_dx = -rtb_Abs1_m;

    // Gain: '<Root>/LookaheadT'
    rtb_Sum1_b_idx_1 = 3.0 * rtb_Speed2d3Path;

    // MATLABSystem: '<Root>/TrackSimPath' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
    //   Concatenate: '<S3>/Matrix Concatenate'
    //   SignalConversion generated from: '<Root>/TrackSimPath'

    obj = &codegenReal2Mission_DW.obj;
    codegenReal2Mission_DW.obj.LookaheadDistFlag = 0U;
    if (rtb_Sum1_b_idx_1 < 10.0) {
      rtb_Sum1_b_idx_1 = 10.0;
      codegenReal2Mission_DW.obj.LookaheadDistFlag = 1U;
    }

    codegenReal2Mission_DW.obj.InitialPose[0] = 0.0;
    codegenReal2Mission_DW.obj.InitialPose[1] = 0.0;
    codegenReal2Mission_DW.obj.InitialPose[2] = 0.0;
    codegenReal2Mission_DW.obj.InitialPose[3] = 0.0;
    std::memcpy(&b_waypointsIn_data[0],
                &codegenReal2Mission_DW.obj.WaypointsInternal[0], 183U * sizeof
                (real_T));
    rEQ0 = false;
    p = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 183)) {
      if ((b_waypointsIn_data[b_k] == rtb_MatrixConcatenate[b_k]) || (rtIsNaN
           (b_waypointsIn_data[b_k]) && rtIsNaN(rtb_MatrixConcatenate[b_k]))) {
        b_k++;
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
    codegenReal2Mission_DW.obj.LookaheadDistance = rtb_Sum1_b_idx_1;
    if (b_waypointsIn_size[0] == 0) {
      // MATLABSystem: '<Root>/TrackSimPath' incorporates:
      //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
      //   SignalConversion generated from: '<Root>/TrackSimPath'

      rtb_LookAheadNED_Log[0] = rtb_Sum1_b_idx_1 * std::cos(x2) + rtb_East_k0;
      rtb_LookAheadNED_Log[1] = rtb_Sum1_b_idx_1 * std::sin(x2) + rtb_AirSpeed_n;
      rtb_LookAheadNED_Log[2] = rtb_Sum1_b_idx_1 * 0.0 + rtb_North_dx;

      // MATLABSystem: '<Root>/TrackSimPath'
      rtb_TrackSimPath_o5 = 0.0;
    } else {
      codegenReal2Miss_emxInit_real_T(&d_0, 2);
      guard1 = false;
      if (b_waypointsIn_size[0] == 1) {
        if (codegenReal2Mission_DW.obj.StartFlag) {
          codegenReal2Mission_DW.obj.InitialPose[0] = rtb_East_k0;
          codegenReal2Mission_DW.obj.InitialPose[1] = rtb_AirSpeed_n;
          codegenReal2Mission_DW.obj.InitialPose[2] = rtb_North_dx;
          codegenReal2Mission_DW.obj.InitialPose[3] = x2;
        }

        b_waypointsIn[0] = b_waypointsIn_data[0] - rtb_East_k0;
        b_waypointsIn[1] = b_waypointsIn_data[1] - rtb_AirSpeed_n;
        b_waypointsIn[2] = b_waypointsIn_data[2] - rtb_North_dx;
        if (codegenReal2Mission_norm_b(b_waypointsIn) < 1.4901161193847656E-8) {
          // MATLABSystem: '<Root>/TrackSimPath' incorporates:
          //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
          //   SignalConversion generated from: '<Root>/TrackSimPath'

          rtb_LookAheadNED_Log[0] = rtb_Sum1_b_idx_1 * std::cos(x2) +
            rtb_East_k0;
          rtb_LookAheadNED_Log[1] = rtb_Sum1_b_idx_1 * std::sin(x2) +
            rtb_AirSpeed_n;
          rtb_LookAheadNED_Log[2] = rtb_Sum1_b_idx_1 * 0.0 + rtb_North_dx;

          // MATLABSystem: '<Root>/TrackSimPath'
          rtb_TrackSimPath_o5 = 0.0;
          codegenReal2Mission_DW.obj.StartFlag = false;
        } else {
          rtb_Sum_nj[0] = codegenReal2Mission_DW.obj.InitialPose[0];
          rtb_Sum_nj[1] = codegenReal2Mission_DW.obj.InitialPose[1];
          rtb_Sum_nj[2] = codegenReal2Mission_DW.obj.InitialPose[2];
          codegenReal2Mission_DW.obj.StartFlag = false;
          appendedWaypoints_data[0] = rtb_Sum_nj[0];
          appendedWaypoints_data[2] = rtb_Sum_nj[1];
          appendedWaypoints_data[4] = rtb_Sum_nj[2];
          for (b_k = 0; b_k < 3; b_k++) {
            appendedWaypoints_data[(b_k << 1) + 1] = b_waypointsIn_data[b_k];
          }

          codegenReal2Mission_DW.obj.NumWaypoints = 2.0;
          i = 2;
          for (b_k = 0; b_k < 6; b_k++) {
            rtb_MatrixConcatenate[b_k] = appendedWaypoints_data[b_k];
          }

          guard1 = true;
        }
      } else {
        i = b_waypointsIn_size[0];
        n = b_waypointsIn_size[0] * b_waypointsIn_size[1] - 1;
        if (0 <= n) {
          std::memcpy(&rtb_MatrixConcatenate[0], &b_waypointsIn_data[0], (n + 1)
                      * sizeof(real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        if (codegenReal2Mission_DW.obj.SearchFlag) {
          b_k = d_0->size[0] * d_0->size[1];
          d_0->size[0] = 1;
          d_0->size[1] = static_cast<int32_T>
            (codegenReal2Mission_DW.obj.NumWaypoints - 1.0);
          codege_emxEnsureCapacity_real_T(d_0, b_k);
          n = static_cast<int32_T>(codegenReal2Mission_DW.obj.NumWaypoints - 1.0)
            - 1;
          for (b_k = 0; b_k <= n; b_k++) {
            d_0->data[b_k] = 0.0;
          }

          b = codegenReal2Mission_DW.obj.NumWaypoints - 1.0;
          n = static_cast<int32_T>(b) - 1;
          for (b_k = 0; b_k <= n; b_k++) {
            v_tmp_tmp = rtb_MatrixConcatenate[static_cast<int32_T>((static_cast<
              real_T>(b_k) + 1.0) + 1.0) - 1];
            b = v_tmp_tmp - rtb_MatrixConcatenate[b_k];
            Vg = rtb_East_k0 - rtb_MatrixConcatenate[b_k];
            b_waypointsIn[0] = Vg;
            rtb_TmpSignalConversionAtTrac_1[0] = rtb_East_k0 - v_tmp_tmp;
            rtb_Sum_kt_idx_1 = rtb_MatrixConcatenate[b_k + i];
            v_tmp_tmp = rtb_MatrixConcatenate[(static_cast<int32_T>((
              static_cast<real_T>(b_k) + 1.0) + 1.0) + i) - 1];
            rtb_Sum1_b_idx_1 = v_tmp_tmp - rtb_Sum_kt_idx_1;
            q = rtb_AirSpeed_n - rtb_Sum_kt_idx_1;
            b_waypointsIn[1] = q;
            rtb_TmpSignalConversionAtTrac_1[1] = rtb_AirSpeed_n - v_tmp_tmp;
            v_tmp = i << 1;
            v_tmp_0 = rtb_MatrixConcatenate[v_tmp + b_k];
            v_tmp_tmp = rtb_MatrixConcatenate[(static_cast<int32_T>((
              static_cast<real_T>(b_k) + 1.0) + 1.0) + v_tmp) - 1];
            v_tmp_1 = v_tmp_tmp - v_tmp_0;
            rtb_TmpSignalConversionAtTrac_3 = rtb_North_dx - v_tmp_0;
            b_waypointsIn[2] = rtb_TmpSignalConversionAtTrac_3;
            rtb_TmpSignalConversionAtTrac_1[2] = rtb_North_dx - v_tmp_tmp;
            q = (rtb_TmpSignalConversionAtTrac_3 * v_tmp_1 + (q *
                  rtb_Sum1_b_idx_1 + Vg * b)) / (v_tmp_1 * v_tmp_1 +
              (rtb_Sum1_b_idx_1 * rtb_Sum1_b_idx_1 + b * b));
            rtb_TmpSignalConversionAtTrac_2[0] = rtb_East_k0 - (b * q +
              rtb_MatrixConcatenate[b_k]);
            rtb_TmpSignalConversionAtTrac_2[1] = rtb_AirSpeed_n -
              (rtb_Sum1_b_idx_1 * q + rtb_Sum_kt_idx_1);
            rtb_TmpSignalConversionAtTrac_2[2] = rtb_North_dx - (v_tmp_1 * q +
              v_tmp_0);
            if (q < 0.0) {
              d_0->data[b_k] = codegenReal2Mission_norm_b(b_waypointsIn);
            } else if (q > 1.0) {
              d_0->data[b_k] = codegenReal2Mission_norm_b
                (rtb_TmpSignalConversionAtTrac_1);
            } else {
              d_0->data[b_k] = codegenReal2Mission_norm_b
                (rtb_TmpSignalConversionAtTrac_2);
            }
          }

          n = d_0->size[1];
          if (d_0->size[1] <= 2) {
            if (d_0->size[1] == 1) {
              v_tmp = 1;
            } else if ((d_0->data[0] > d_0->data[1]) || (rtIsNaN(d_0->data[0]) &&
                        (!rtIsNaN(d_0->data[1])))) {
              v_tmp = 2;
            } else {
              v_tmp = 1;
            }
          } else {
            if (!rtIsNaN(d_0->data[0])) {
              v_tmp = 1;
            } else {
              v_tmp = 0;
              b_k = 2;
              exitg1 = false;
              while ((!exitg1) && (b_k <= d_0->size[1])) {
                if (!rtIsNaN(d_0->data[b_k - 1])) {
                  v_tmp = b_k;
                  exitg1 = true;
                } else {
                  b_k++;
                }
              }
            }

            if (v_tmp == 0) {
              v_tmp = 1;
            } else {
              rtb_Sum1_b_idx_1 = d_0->data[v_tmp - 1];
              b_idx = v_tmp;
              for (b_k = v_tmp + 1; b_k <= n; b_k++) {
                if (rtb_Sum1_b_idx_1 > d_0->data[b_k - 1]) {
                  rtb_Sum1_b_idx_1 = d_0->data[b_k - 1];
                  b_idx = b_k;
                }
              }

              v_tmp = b_idx;
            }
          }

          obj->WaypointIndex = v_tmp;
          obj->SearchFlag = false;
        }

        if (codegenReal2Mission_isequal(obj->WaypointIndex, obj->NumWaypoints))
        {
          obj->LastWaypointFlag = true;
          obj->WaypointIndex--;
        }

        b_k = static_cast<int32_T>(obj->WaypointIndex);
        rtb_Sum_nj[0] = rtb_MatrixConcatenate[b_k - 1];
        rtb_Sum_nj[1] = rtb_MatrixConcatenate[(b_k + i) - 1];
        n = i << 1;
        rtb_Sum_nj[2] = rtb_MatrixConcatenate[(n + b_k) - 1];
        b_k = static_cast<int32_T>(obj->WaypointIndex + 1.0);
        rtb_LookAheadNED_Log[0] = rtb_MatrixConcatenate[b_k - 1];
        u[0] = rtb_East_k0 - rtb_LookAheadNED_Log[0];
        rtb_LookAheadNED_Log[1] = rtb_MatrixConcatenate[(b_k + i) - 1];
        u[1] = rtb_AirSpeed_n - rtb_LookAheadNED_Log[1];
        rtb_LookAheadNED_Log[2] = rtb_MatrixConcatenate[(n + b_k) - 1];
        u[2] = rtb_North_dx - rtb_LookAheadNED_Log[2];
        rtb_Sum1_b_idx_1 = codegenReal2Mission_norm_b(u);
        guard2 = false;
        if (rtb_Sum1_b_idx_1 <= 1.0) {
          guard2 = true;
        } else {
          b = rtb_LookAheadNED_Log[0] - rtb_Sum_nj[0];
          b_waypointsIn[0] = b;
          Vg = rtb_LookAheadNED_Log[1] - rtb_Sum_nj[1];
          b_waypointsIn[1] = Vg;
          q = rtb_LookAheadNED_Log[2] - rtb_Sum_nj[2];
          b_waypointsIn[2] = q;
          rtb_Sum_kt_idx_1 = codegenReal2Mission_norm_b(b_waypointsIn);
          rtb_Sum1_b_idx_1 = (b / rtb_Sum_kt_idx_1 * (u[0] / rtb_Sum1_b_idx_1) +
                              Vg / rtb_Sum_kt_idx_1 * (u[1] / rtb_Sum1_b_idx_1))
            + q / rtb_Sum_kt_idx_1 * (u[2] / rtb_Sum1_b_idx_1);
          if (rtb_Sum1_b_idx_1 < 0.0) {
            rtb_Sum1_b_idx_1 = -1.0;
          } else if (rtb_Sum1_b_idx_1 > 0.0) {
            rtb_Sum1_b_idx_1 = 1.0;
          } else if (rtb_Sum1_b_idx_1 == 0.0) {
            rtb_Sum1_b_idx_1 = 0.0;
          } else {
            rtb_Sum1_b_idx_1 = (rtNaN);
          }

          if (rtb_Sum1_b_idx_1 >= 0.0) {
            guard2 = true;
          }
        }

        if (guard2) {
          obj->WaypointIndex++;
          if (codegenReal2Mission_isequal(obj->WaypointIndex, obj->NumWaypoints))
          {
            obj->LastWaypointFlag = true;
            obj->WaypointIndex--;
          }

          b_k = static_cast<int32_T>(obj->WaypointIndex);
          rtb_Sum_nj[0] = rtb_MatrixConcatenate[b_k - 1];
          rtb_Sum_nj[1] = rtb_MatrixConcatenate[(b_k + i) - 1];
          rtb_Sum_nj[2] = rtb_MatrixConcatenate[(n + b_k) - 1];
          b_k = static_cast<int32_T>(obj->WaypointIndex + 1.0);
          rtb_LookAheadNED_Log[0] = rtb_MatrixConcatenate[b_k - 1];
          rtb_LookAheadNED_Log[1] = rtb_MatrixConcatenate[(b_k + i) - 1];
          rtb_LookAheadNED_Log[2] = rtb_MatrixConcatenate[(n + b_k) - 1];
        }

        v_tmp_0 = rtb_LookAheadNED_Log[0] - rtb_Sum_nj[0];
        Vg = rtb_East_k0 - rtb_Sum_nj[0];
        rtb_Sum1_b_idx_1 = rtb_LookAheadNED_Log[0] - rtb_Sum_nj[0];
        b_waypointsIn[0] = Vg;
        rtb_TmpSignalConversionAtTrac_1[0] = rtb_East_k0 - rtb_LookAheadNED_Log
          [0];
        b = rtb_LookAheadNED_Log[1] - rtb_Sum_nj[1];
        q = rtb_AirSpeed_n - rtb_Sum_nj[1];
        b_waypointsIn[1] = q;
        rtb_TmpSignalConversionAtTrac_1[1] = rtb_AirSpeed_n -
          rtb_LookAheadNED_Log[1];
        rtb_Sum_kt_idx_1 = rtb_LookAheadNED_Log[2] - rtb_Sum_nj[2];
        rtb_TmpSignalConversionAtTrac_3 = rtb_North_dx - rtb_Sum_nj[2];
        b_waypointsIn[2] = rtb_TmpSignalConversionAtTrac_3;
        rtb_TmpSignalConversionAtTrac_1[2] = rtb_North_dx -
          rtb_LookAheadNED_Log[2];
        q = (rtb_TmpSignalConversionAtTrac_3 * rtb_Sum_kt_idx_1 + (q * b + Vg *
              v_tmp_0)) / (rtb_Sum_kt_idx_1 * rtb_Sum_kt_idx_1 + (b * b +
          rtb_Sum1_b_idx_1 * v_tmp_0));
        rtb_TmpSignalConversionAtTrac_2[0] = rtb_East_k0 - (rtb_Sum1_b_idx_1 * q
          + rtb_Sum_nj[0]);
        rtb_TmpSignalConversionAtTrac_2[1] = rtb_AirSpeed_n - (b * q +
          rtb_Sum_nj[1]);
        rtb_TmpSignalConversionAtTrac_2[2] = rtb_North_dx - (rtb_Sum_kt_idx_1 *
          q + rtb_Sum_nj[2]);
        if (q < 0.0) {
          rtb_TrackSimPath_o5 = codegenReal2Mission_norm_b(b_waypointsIn);
        } else if (q > 1.0) {
          rtb_TrackSimPath_o5 = codegenReal2Mission_norm_b
            (rtb_TmpSignalConversionAtTrac_1);
        } else {
          rtb_TrackSimPath_o5 = codegenReal2Mission_norm_b
            (rtb_TmpSignalConversionAtTrac_2);
        }

        if (obj->LastWaypointFlag) {
          q = ((Vg * rtb_Sum1_b_idx_1 + (rtb_AirSpeed_n - rtb_Sum_nj[1]) *
                (rtb_LookAheadNED_Log[1] - rtb_Sum_nj[1])) + (rtb_North_dx -
                rtb_Sum_nj[2]) * (rtb_LookAheadNED_Log[2] - rtb_Sum_nj[2])) /
            ((rtb_Sum1_b_idx_1 * rtb_Sum1_b_idx_1 + (rtb_LookAheadNED_Log[1] -
               rtb_Sum_nj[1]) * (rtb_LookAheadNED_Log[1] - rtb_Sum_nj[1])) +
             (rtb_LookAheadNED_Log[2] - rtb_Sum_nj[2]) * (rtb_LookAheadNED_Log[2]
              - rtb_Sum_nj[2]));
          b_waypointsIn[0] = rtb_East_k0 - (q * v_tmp_0 + rtb_Sum_nj[0]);
          b_waypointsIn[1] = rtb_AirSpeed_n - (q * b + rtb_Sum_nj[1]);
          b_waypointsIn[2] = rtb_North_dx - (q * rtb_Sum_kt_idx_1 + rtb_Sum_nj[2]);
          rtb_TrackSimPath_o5 = codegenReal2Mission_norm_b(b_waypointsIn);
        }

        rtb_TmpSignalConversionAtTrac_3 = std::abs(rtb_TrackSimPath_o5);
        if ((!rtIsInf(rtb_TmpSignalConversionAtTrac_3)) && (!rtIsNaN
             (rtb_TmpSignalConversionAtTrac_3))) {
          if (rtb_TmpSignalConversionAtTrac_3 <= 2.2250738585072014E-308) {
            rtb_Sum1_b_idx_1 = 4.94065645841247E-324;
            q = 4.94065645841247E-324;
          } else {
            frexp(rtb_TmpSignalConversionAtTrac_3, &b_exponent);
            rtb_Sum1_b_idx_1 = std::ldexp(1.0, b_exponent - 53);
            frexp(rtb_TmpSignalConversionAtTrac_3, &b_exponent_0);
            q = std::ldexp(1.0, b_exponent_0 - 53);
          }
        } else {
          rtb_Sum1_b_idx_1 = (rtNaN);
          q = (rtNaN);
        }

        Vg = std::sqrt(rtb_Sum1_b_idx_1);
        rtb_Sum1_b_idx_1 = 5.0 * q;
        if ((Vg > rtb_Sum1_b_idx_1) || rtIsNaN(rtb_Sum1_b_idx_1)) {
          rtb_Sum1_b_idx_1 = Vg;
        }

        if (obj->LookaheadDistance <= rtb_TrackSimPath_o5 + rtb_Sum1_b_idx_1) {
          obj->LookaheadDistance = obj->LookaheadFactor * rtb_TrackSimPath_o5;
        }

        Vg = obj->LookaheadDistance;
        q = rtb_Sum_nj[0] - rtb_East_k0;
        rtb_TmpSignalConversionAtTrac_3 = rtb_Sum_nj[1] - rtb_AirSpeed_n;
        rtb_Sum1_b_idx_1 = ((rtb_LookAheadNED_Log[0] - rtb_Sum_nj[0]) *
                            (rtb_LookAheadNED_Log[0] - rtb_Sum_nj[0]) +
                            (rtb_LookAheadNED_Log[1] - rtb_Sum_nj[1]) *
                            (rtb_LookAheadNED_Log[1] - rtb_Sum_nj[1])) +
          (rtb_LookAheadNED_Log[2] - rtb_Sum_nj[2]) * (rtb_LookAheadNED_Log[2] -
          rtb_Sum_nj[2]);
        v_tmp_1 = rtb_Sum_nj[2] - rtb_North_dx;
        b = ((v_tmp_0 * q + b * rtb_TmpSignalConversionAtTrac_3) +
             rtb_Sum_kt_idx_1 * v_tmp_1) * 2.0;
        q = std::sqrt(b * b - (((q * q + rtb_TmpSignalConversionAtTrac_3 *
          rtb_TmpSignalConversionAtTrac_3) + v_tmp_1 * v_tmp_1) - Vg * Vg) *
                      (4.0 * rtb_Sum1_b_idx_1));
        Vg = (-b + q) / 2.0 / rtb_Sum1_b_idx_1;
        rtb_Sum1_b_idx_1 = (-b - q) / 2.0 / rtb_Sum1_b_idx_1;
        if ((Vg > rtb_Sum1_b_idx_1) || rtIsNaN(rtb_Sum1_b_idx_1)) {
          rtb_Sum1_b_idx_1 = Vg;
        }

        // MATLABSystem: '<Root>/TrackSimPath' incorporates:
        //   BusCreator: '<S4>/FixedWingGuidanceStateBus'
        //   SignalConversion generated from: '<Root>/TrackSimPath'

        rtb_LookAheadNED_Log[0] = (1.0 - rtb_Sum1_b_idx_1) * rtb_Sum_nj[0] +
          rtb_Sum1_b_idx_1 * rtb_LookAheadNED_Log[0];
        rtb_LookAheadNED_Log[1] = (1.0 - rtb_Sum1_b_idx_1) * rtb_Sum_nj[1] +
          rtb_Sum1_b_idx_1 * rtb_LookAheadNED_Log[1];
        rtb_LookAheadNED_Log[2] = (1.0 - rtb_Sum1_b_idx_1) * rtb_Sum_nj[2] +
          rtb_Sum1_b_idx_1 * rtb_LookAheadNED_Log[2];
        obj->LastWaypointFlag = false;
      }

      codegenReal2Miss_emxFree_real_T(&d_0);
    }

    // End of MATLABSystem: '<Root>/TrackSimPath'

    // Outputs for Atomic SubSystem: '<Root>/NorthEast2LatLon'
    // Switch: '<S58>/Switch' incorporates:
    //   Gain: '<Root>/NED2ENU'
    //   Gain: '<S9>/Up2Down'
    //   MATLABSystem: '<Root>/TrackSimPath'
    //   Product: '<S47>/x*cos'

    rtb_Up2Down = rtb_LookAheadNED_Log[0] * codegenReal2Mission_ConstB.SinCos_o2;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Gain: '<Root>/NED2ENU'
    //   MATLABSystem: '<Root>/TrackSimPath'
    //   Product: '<S47>/y*sin'

    rtb_RollAngle_fm = rtb_LookAheadNED_Log[1] *
      codegenReal2Mission_ConstB.SinCos_o1;

    // Sum: '<S47>/Sum'
    rtb_Sum1_b_idx_1 = rtb_Up2Down - rtb_RollAngle_fm;

    // Switch: '<S58>/Switch' incorporates:
    //   Abs: '<S58>/Abs'
    //   DataStoreRead: '<S5>/LatitudeGCS'
    //   Gain: '<S9>/Up2Down'

    rtb_Up2Down = std::abs(codegenReal2Mission_DW.LatitudeGCS);

    // Switch: '<S58>/Switch' incorporates:
    //   Constant: '<S59>/Constant'
    //   RelationalOperator: '<S59>/Compare'

    if (rtb_Up2Down > 180.0) {
      // Switch: '<S58>/Switch' incorporates:
      //   Bias: '<S58>/Bias'
      //   Bias: '<S58>/Bias1'
      //   Constant: '<S58>/Constant2'
      //   DataStoreRead: '<S5>/LatitudeGCS'
      //   Math: '<S58>/Math Function1'

      rtb_Up2Down = rt_modd_snf(codegenReal2Mission_DW.LatitudeGCS + 180.0,
        360.0) + -180.0;
    } else {
      // Switch: '<S58>/Switch' incorporates:
      //   DataStoreRead: '<S5>/LatitudeGCS'

      rtb_Up2Down = codegenReal2Mission_DW.LatitudeGCS;
    }

    // End of Switch: '<S58>/Switch'

    // Abs: '<S55>/Abs1'
    Vg = std::abs(rtb_Up2Down);

    // RelationalOperator: '<S57>/Compare' incorporates:
    //   Constant: '<S57>/Constant'

    rEQ0 = (Vg > 90.0);

    // Switch: '<S55>/Switch'
    if (rEQ0) {
      // Signum: '<S55>/Sign1'
      if (rtb_Up2Down < 0.0) {
        q = -1.0;
      } else if (rtb_Up2Down > 0.0) {
        q = 1.0;
      } else if (rtb_Up2Down == 0.0) {
        q = 0.0;
      } else {
        q = (rtNaN);
      }

      // End of Signum: '<S55>/Sign1'

      // Switch: '<S58>/Switch' incorporates:
      //   Bias: '<S55>/Bias'
      //   Bias: '<S55>/Bias1'
      //   Gain: '<S55>/Gain'
      //   Gain: '<S9>/Up2Down'
      //   Product: '<S55>/Divide1'

      rtb_Up2Down = (-(Vg + -90.0) + 90.0) * q;
    }

    // End of Switch: '<S55>/Switch'

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   UnitConversion: '<S63>/Unit Conversion'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_RollAngle_fm = 0.017453292519943295 * rtb_Up2Down;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Constant: '<S64>/Constant'
    //   Product: '<S64>/Product1'
    //   Sum: '<S64>/Sum1'
    //   Trigonometry: '<S64>/Trigonometric Function1'

    rtb_FlightPathAngle_c = std::sin(rtb_RollAngle_fm);
    rtb_FlightPathAngle_c = 1.0 - codegenReal2Mission_ConstB.sqrt_l *
      codegenReal2Mission_ConstB.sqrt_l * rtb_FlightPathAngle_c *
      rtb_FlightPathAngle_c;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Constant: '<S61>/Constant1'
    //   Product: '<S61>/Product1'
    //   Sqrt: '<S61>/sqrt'

    rtb_HeadingAngle_g = std::sqrt(rtb_FlightPathAngle_c);
    rtb_HeadingAngle_g = 6.378137E+6 / rtb_HeadingAngle_g;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Constant: '<S61>/Constant2'
    //   Product: '<S47>/rad lat'
    //   Product: '<S61>/Product3'
    //   Trigonometry: '<S61>/Trigonometric Function1'

    rtb_FlightPathAngle_c = rt_atan2d_snf(1.0, rtb_HeadingAngle_g *
      codegenReal2Mission_ConstB.Sum1_f / rtb_FlightPathAngle_c) *
      rtb_Sum1_b_idx_1;

    // Product: '<S61>/Product4' incorporates:
    //   Trigonometry: '<S61>/Trigonometric Function'

    rtb_Sum1_b_idx_1 = rtb_HeadingAngle_g * std::cos(rtb_RollAngle_fm);

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Gain: '<Root>/NED2ENU'
    //   MATLABSystem: '<Root>/TrackSimPath'
    //   Product: '<S47>/x*sin'

    rtb_RollAngle_fm = rtb_LookAheadNED_Log[0] *
      codegenReal2Mission_ConstB.SinCos_o1;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Gain: '<Root>/NED2ENU'
    //   MATLABSystem: '<Root>/TrackSimPath'
    //   Product: '<S47>/y*cos'

    rtb_HeadingAngle_g = rtb_LookAheadNED_Log[1] *
      codegenReal2Mission_ConstB.SinCos_o2;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Constant: '<S61>/Constant3'
    //   Product: '<S47>/rad long '
    //   Sum: '<S47>/Sum1'
    //   Trigonometry: '<S61>/Trigonometric Function2'

    rtb_RollAngle_fm = (rtb_RollAngle_fm + rtb_HeadingAngle_g) * rt_atan2d_snf
      (1.0, rtb_Sum1_b_idx_1);

    // UnitConversion: '<S48>/Unit Conversion'
    // Unit Conversion - from: rad to: deg
    // Expression: output = (57.2958*input) + (0)
    rtb_Sum1_b_idx_1 = 57.295779513082323 * rtb_RollAngle_fm;

    // Switch: '<S46>/Switch1'
    if (rEQ0) {
      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Constant: '<S46>/Constant'

      rtb_RollAngle_fm = 180.0;
    } else {
      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Constant: '<S46>/Constant1'

      rtb_RollAngle_fm = 0.0;
    }

    // End of Switch: '<S46>/Switch1'

    // Sum: '<S46>/Sum' incorporates:
    //   DataStoreRead: '<S5>/LongitudeGCS'

    Vg = rtb_RollAngle_fm + codegenReal2Mission_DW.LongitudeGCS;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Abs: '<S56>/Abs'

    rtb_RollAngle_fm = std::abs(Vg);

    // Switch: '<S56>/Switch' incorporates:
    //   Constant: '<S60>/Constant'
    //   RelationalOperator: '<S60>/Compare'

    if (rtb_RollAngle_fm > 180.0) {
      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Bias: '<S56>/Bias'
      //   Bias: '<S56>/Bias1'
      //   Constant: '<S56>/Constant2'
      //   Math: '<S56>/Math Function1'

      rtb_RollAngle_fm = rt_modd_snf(Vg + 180.0, 360.0) + -180.0;
    } else {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_RollAngle_fm = Vg;
    }

    // End of Switch: '<S56>/Switch'

    // Sum: '<S44>/Sum' incorporates:
    //   UnitConversion: '<S48>/Unit Conversion'

    Vg = 57.295779513082323 * rtb_FlightPathAngle_c + rtb_Up2Down;
    rtb_Sum_kt_idx_1 = rtb_Sum1_b_idx_1 + rtb_RollAngle_fm;

    // Switch: '<S58>/Switch' incorporates:
    //   Abs: '<S52>/Abs'
    //   Gain: '<S9>/Up2Down'

    rtb_Up2Down = std::abs(Vg);

    // Switch: '<S52>/Switch' incorporates:
    //   Bias: '<S52>/Bias'
    //   Bias: '<S52>/Bias1'
    //   Constant: '<S52>/Constant2'
    //   Constant: '<S53>/Constant'
    //   Math: '<S52>/Math Function1'
    //   RelationalOperator: '<S53>/Compare'

    if (rtb_Up2Down > 180.0) {
      Vg = rt_modd_snf(Vg + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S52>/Switch'

    // Abs: '<S49>/Abs1'
    rtb_Sum1_b_idx_1 = std::abs(Vg);

    // Switch: '<S49>/Switch' incorporates:
    //   Constant: '<S51>/Constant'
    //   RelationalOperator: '<S51>/Compare'
    //   Switch: '<S45>/Switch1'

    if (rtb_Sum1_b_idx_1 > 90.0) {
      // Signum: '<S49>/Sign1'
      if (Vg < 0.0) {
        Vg = -1.0;
      } else if (Vg > 0.0) {
        Vg = 1.0;
      } else if (Vg == 0.0) {
        Vg = 0.0;
      } else {
        Vg = (rtNaN);
      }

      // End of Signum: '<S49>/Sign1'

      // Switch: '<S58>/Switch' incorporates:
      //   Bias: '<S49>/Bias'
      //   Bias: '<S49>/Bias1'
      //   Gain: '<S49>/Gain'
      //   Gain: '<S9>/Up2Down'
      //   Product: '<S49>/Divide1'

      rtb_Up2Down = (-(rtb_Sum1_b_idx_1 + -90.0) + 90.0) * Vg;

      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Constant: '<S45>/Constant'

      rtb_RollAngle_fm = 180.0;
    } else {
      // Switch: '<S58>/Switch' incorporates:
      //   Gain: '<S9>/Up2Down'

      rtb_Up2Down = Vg;

      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Constant: '<S45>/Constant1'

      rtb_RollAngle_fm = 0.0;
    }

    // End of Switch: '<S49>/Switch'

    // Sum: '<S45>/Sum'
    rtb_Sum1_b_idx_1 = rtb_RollAngle_fm + rtb_Sum_kt_idx_1;

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Abs: '<S50>/Abs'

    rtb_RollAngle_fm = std::abs(rtb_Sum1_b_idx_1);

    // Switch: '<S50>/Switch' incorporates:
    //   Constant: '<S54>/Constant'
    //   RelationalOperator: '<S54>/Compare'

    if (rtb_RollAngle_fm > 180.0) {
      // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
      //   Bias: '<S50>/Bias'
      //   Bias: '<S50>/Bias1'
      //   Constant: '<S50>/Constant2'
      //   Math: '<S50>/Math Function1'

      rtb_RollAngle_fm = rt_modd_snf(rtb_Sum1_b_idx_1 + 180.0, 360.0) + -180.0;
    } else {
      // SignalConversion generated from: '<Root>/SimUAVStateBus'
      rtb_RollAngle_fm = rtb_Sum1_b_idx_1;
    }

    // End of Switch: '<S50>/Switch'

    // SignalConversion generated from: '<Root>/SimUAVStateBus' incorporates:
    //   Gain: '<Root>/NED2ENU'
    //   Gain: '<S5>/Up2Down'
    //   MATLABSystem: '<Root>/TrackSimPath'

    rtb_FlightPathAngle_c = rtb_LookAheadNED_Log[2];

    // Outport: '<Root>/LookAheadPoint' incorporates:
    //   BusCreator: '<S5>/LookAheadPointBus'
    //   DataStoreRead: '<S5>/Data Store Read'
    //   Gain: '<S5>/inverse'
    //   Sum: '<S44>/Sum1'
    //   UnaryMinus: '<S44>/Ze2height'

    codegenReal2Mission_Y.LookAheadPoint_j.Latitude_deg = rtb_Up2Down;
    codegenReal2Mission_Y.LookAheadPoint_j.Longitude_deg = rtb_RollAngle_fm;
    codegenReal2Mission_Y.LookAheadPoint_j.Height_meter = -rtb_FlightPathAngle_c
      - (-codegenReal2Mission_DW.AltitudeGCS);

    // End of Outputs for SubSystem: '<Root>/NorthEast2LatLon'

    // Truth Table: '<Root>/EngagementTruthTable'
    //  Front Distance within Upper &  Lower Bound
    //  CrossTrack Error within 1.5 Second Bound
    if ((rtb_LagDistance < d) && (rtb_LagDistance > rtb_Minus) &&
        (rtb_TrackSimPath_o5 < rtb_Speed2d3Path * 1.5)) {
      //  Real UAV Engaged with Simulation UAV
      rtb_Engaged = true;
    } else {
      //  Default
      //  Real UAV Not Engaged with Simulation UAV
      rtb_Engaged = false;
    }

    // End of Truth Table: '<Root>/EngagementTruthTable'

    // Outport: '<Root>/EngagedFlag'
    codegenReal2Mission_Y.EngagedFlag = rtb_Engaged;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_North_dx = rtb_East_k0;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_East_k = rtb_AirSpeed_n;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_Height = rtb_Abs1_m;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_AirSpeed = rtb_Abs1_n;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_HeadingAngle = x2;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_FlightPathAngle = rtb_FixedWingGuidanceStateBus_F;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_RollAngle_f = rtb_FixedWingGuidanceStateBus_R;

    // SignalConversion generated from: '<Root>/RealUAVStateBus' incorporates:
    //   BusCreator: '<S4>/FixedWingGuidanceStateBus'

    rtb_RollAngleRate = 0.0;

    // SignalConversion generated from: '<Root>/SimUAVStateBus'
    rtb_North_d = codegenReal2Mission_B.SimUAVStateZOH.North;

    // BusCreator: '<S4>/FixedWingGuidanceStateBus' incorporates:
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'

    rtb_East_k0 = codegenReal2Mission_B.SimUAVStateZOH.East;

    // SignalConversion generated from: '<Root>/SimUAVStateBus'
    rtb_Height_n = codegenReal2Mission_B.SimUAVStateZOH.Height;

    // Switch: '<S35>/Switch' incorporates:
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'

    rtb_AirSpeed_n = codegenReal2Mission_B.SimUAVStateZOH.AirSpeed;

    // SignalConversion generated from: '<Root>/SimUAVStateBus'
    rtb_HeadingAngle_g = codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle;

    // SignalConversion generated from: '<Root>/SimUAVStateBus'
    rtb_FlightPathAngle_c = codegenReal2Mission_B.SimUAVStateZOH.FlightPathAngle;

    // SignalConversion generated from: '<Root>/SimUAVStateBus'
    rtb_RollAngle_fm = codegenReal2Mission_B.SimUAVStateZOH.RollAngle;

    // Switch: '<S58>/Switch' incorporates:
    //   Gain: '<S9>/Up2Down'
    //   SignalConversion generated from: '<Root>/SimUAVStateBus'

    rtb_Up2Down = codegenReal2Mission_B.SimUAVStateZOH.RollAngleRate;

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
        up0[0] = rtb_North_dx;
        up0[1] = rtb_East_k;
        up0[2] = rtb_Height;
        up0[3] = rtb_AirSpeed;
        up0[4] = rtb_HeadingAngle;
        up0[5] = rtb_FlightPathAngle;
        up0[6] = rtb_RollAngle_f;
        up0[7] = rtb_RollAngleRate;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[8];
        up1[0] = rtb_North_d;
        up1[1] = rtb_East_k0;
        up1[2] = rtb_Height_n;
        up1[3] = rtb_AirSpeed_n;
        up1[4] = rtb_HeadingAngle_g;
        up1[5] = rtb_FlightPathAngle_c;
        up1[6] = rtb_RollAngle_fm;
        up1[7] = rtb_Up2Down;
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
        up3[0] = rtb_LagDistance;
        rt_UpdateLogVar((LogVar *)var, up3, 0);
        var = var->next;
      }

      {
        real_T up4[3];
        up4[0] = rtb_LookAheadNED_Log[0];
        up4[1] = rtb_LookAheadNED_Log[1];
        up4[2] = rtb_LookAheadNED_Log[2];
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
      }
    }

    // Chart: '<Root>/TriggerTermination'
    if (codegenReal2Mission_DW.is_active_c4_codegenReal2Missio == 0U) {
      codegenReal2Mission_DW.is_active_c4_codegenReal2Missio = 1U;
      codegenReal2Mission_B.Terminate = false;
      codegenReal2Mission_DW.is_c4_codegenReal2Mission =
        codegenReal2M_IN_InitialPersuit;
      codegenReal2Mission_DW.DataCounter = 0.0;
    } else {
      switch (codegenReal2Mission_DW.is_c4_codegenReal2Mission) {
       case codegenReal2M_IN_InitialPersuit:
        if (codegenReal2Mission_DW.DataCounter >= 99.0) {
          codegenReal2Mission_DW.is_c4_codegenReal2Mission =
            codegenReal_IN_MissionExecution;
          codegenReal2Mission_DW.DataCounter = 0.0;
        } else if ((!rtb_TakeOffTrigger) || (!rtb_Engaged)) {
          codegenReal2Mission_DW.is_c4_codegenReal2Mission =
            codegenReal2M_IN_InitialPersuit;
          codegenReal2Mission_DW.DataCounter = 0.0;
        } else {
          codegenReal2Mission_DW.DataCounter++;
        }
        break;

       case codegenRea_IN_MissionCompletion:
        codegenReal2Mission_B.Terminate = true;
        break;

       default:
        // case IN_MissionExecution:
        if (codegenReal2Mission_DW.DataCounter >= 99.0) {
          codegenReal2Mission_DW.is_c4_codegenReal2Mission =
            codegenRea_IN_MissionCompletion;
          codegenReal2Mission_B.Terminate = true;
        } else if (rtb_Engaged) {
          codegenReal2Mission_DW.is_c4_codegenReal2Mission =
            codegenReal_IN_MissionExecution;
          codegenReal2Mission_DW.DataCounter = 0.0;
        } else {
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

    // Outputs for Atomic SubSystem: '<Root>/VisualizeSimUAV'
    // Switch: '<S58>/Switch' incorporates:
    //   Gain: '<S9>/Up2Down'

    rtb_Up2Down = -codegenReal2Mission_B.SimUAVStateZOH.Height;

    // End of Outputs for SubSystem: '<Root>/VisualizeSimUAV'
  }

  // End of Outputs for SubSystem: '<S2>/MissionSimUAV'

  // Step: '<S11>/Step'
  if ((&codegenReal2Mission_M)->Timing.t[0] < 0.0) {
    rtb_Sum1_b_idx_1 = 0.0;
  } else {
    rtb_Sum1_b_idx_1 = 0.13971948648386895;
  }

  // End of Step: '<S11>/Step'

  // Sum: '<S11>/Output' incorporates:
  //   Clock: '<S11>/Clock'
  //   Product: '<S11>/Product'

  rtb_Abs1_m = rtb_Sum1_b_idx_1 * (&codegenReal2Mission_M)->Timing.t[0];
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Gain: '<S2>/Gain2'
    codegenReal2Mission_B.Down = -codegenReal2Mission_B.SimUAVStateZOH.Height;
  }

  // SignalConversion generated from: '<S2>/TakeOffGathering' incorporates:
  //   Constant: '<S2>/Down'
  //   Gain: '<S2>/East'
  //   Gain: '<S2>/North'
  //   Trigonometry: '<S2>/Cos'
  //   Trigonometry: '<S2>/Sin'

  rtb_Sum_nj[0] = 100.0 * std::sin(rtb_Abs1_m);
  rtb_Sum_nj[1] = 100.0 * std::cos(rtb_Abs1_m);
  rtb_Sum_nj[2] = -150.0;

  // MATLABSystem: '<S2>/TakeOffGathering' incorporates:
  //   SignalConversion generated from: '<S2>/TakeOffGathering'

  codegenReal2Mission_DW.obj_m.OrbitRadiusFlag = 0U;
  codegenReal2Mission_DW.obj_m.LookaheadDistFlag = 0U;
  Vg = codegenReal2Mission_B.SimUAVStateZOH.North - rtb_Sum_nj[0];
  rtb_TmpSignalConversionAtTrac_0[0] = Vg;
  q = codegenReal2Mission_B.SimUAVStateZOH.East - rtb_Sum_nj[1];
  rtb_TmpSignalConversionAtTrac_0[1] = q;
  if (codegenReal2Mission_norm(rtb_TmpSignalConversionAtTrac_0) <
      2.47032822920623E-323) {
    // MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_B.TakeOffGathering_o2 =
      codegenReal2Mission_B.SimUAVStateZOH.HeadingAngle;
  } else {
    rEQ0 = false;
    p = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 3)) {
      if ((codegenReal2Mission_DW.obj_m.OrbitCenterInternal[b_k] ==
           rtb_Sum_nj[b_k]) || (rtIsNaN
           (codegenReal2Mission_DW.obj_m.OrbitCenterInternal[b_k]) && rtIsNaN
           (rtb_Sum_nj[b_k]))) {
        b_k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (p) {
      rEQ0 = true;
    }

    if ((!rEQ0) || (!(codegenReal2Mission_DW.obj_m.OrbitRadiusInternal == 500.0)))
    {
      codegenReal2Mission_DW.obj_m.NumCircles = 0.0;
      codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = rtb_Sum_nj[0];
      codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = rtb_Sum_nj[1];
      codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = -150.0;
      codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = 500.0;
      codegenReal2Mission_DW.obj_m.SelectTurnDirectionFlag = true;
    }

    codegenReal2Mission_DW.obj_m.LookaheadDistance = 100.0;
    distToCenter_tmp[0] = Vg;
    distToCenter_tmp[1] = q;
    rtb_Abs1_m = std::sqrt(q * q + Vg * Vg);
    rtb_TmpSignalConversionAtTrac_3 = std::abs
      (codegenReal2Mission_DW.obj_m.LookaheadDistance + 500.0);
    rtb_TakeOffTrigger = !rtIsInf(rtb_TmpSignalConversionAtTrac_3);
    rEQ0 = !rtIsNaN(rtb_TmpSignalConversionAtTrac_3);
    if (rtb_TakeOffTrigger && rEQ0) {
      if (rtb_TmpSignalConversionAtTrac_3 <= 2.2250738585072014E-308) {
        rtb_Sum1_b_idx_1 = 4.94065645841247E-324;
      } else {
        frexp(rtb_TmpSignalConversionAtTrac_3, &b_exponent_1);
        rtb_Sum1_b_idx_1 = std::ldexp(1.0, b_exponent_1 - 53);
      }
    } else {
      rtb_Sum1_b_idx_1 = (rtNaN);
    }

    guard1 = false;
    if (rtb_Abs1_m >= (codegenReal2Mission_DW.obj_m.LookaheadDistance + 500.0) -
        5.0 * rtb_Sum1_b_idx_1) {
      guard1 = true;
    } else {
      if (rtb_TakeOffTrigger && rEQ0) {
        if (rtb_TmpSignalConversionAtTrac_3 <= 2.2250738585072014E-308) {
          rtb_Sum1_b_idx_1 = 4.94065645841247E-324;
        } else {
          frexp(rtb_TmpSignalConversionAtTrac_3, &b_exponent_2);
          rtb_Sum1_b_idx_1 = std::ldexp(1.0, b_exponent_2 - 53);
        }
      } else {
        rtb_Sum1_b_idx_1 = (rtNaN);
      }

      if (rtb_Abs1_m <= (500.0 - codegenReal2Mission_DW.obj_m.LookaheadDistance)
          + 5.0 * rtb_Sum1_b_idx_1) {
        guard1 = true;
      } else {
        if (codegenReal2Mission_DW.obj_m.StartFlag) {
          codegenReal2Mission_DW.obj_m.PrevPosition[0] =
            codegenReal2Mission_B.SimUAVStateZOH.North;
          codegenReal2Mission_DW.obj_m.PrevPosition[1] =
            codegenReal2Mission_B.SimUAVStateZOH.East;
          codegenReal2Mission_DW.obj_m.StartFlag = false;
        }

        rtb_TmpSignalConversionAtTrac_0[0] = Vg;
        rtb_TmpSignalConversionAtTrac_0[1] = q;
        d = codegenReal2Mission_norm(rtb_TmpSignalConversionAtTrac_0);
        rtb_FixedWingGuidanceStateBus_R =
          codegenReal2Mission_DW.obj_m.LookaheadDistance *
          codegenReal2Mission_DW.obj_m.LookaheadDistance;
        rtb_Minus = ((rtb_FixedWingGuidanceStateBus_R - 250000.0) + d * d) /
          (2.0 * d);
        rtb_Abs1_n = rtb_Sum_nj[0] - codegenReal2Mission_B.SimUAVStateZOH.North;
        x2 = rtb_Abs1_n * rtb_Minus / d +
          codegenReal2Mission_B.SimUAVStateZOH.North;
        rtb_FixedWingGuidanceStateBus_F = rtb_Sum_nj[1] -
          codegenReal2Mission_B.SimUAVStateZOH.East;
        rtb_Abs1_m = rtb_FixedWingGuidanceStateBus_F * rtb_Minus / d +
          codegenReal2Mission_B.SimUAVStateZOH.East;
        rtb_Minus = std::sqrt(rtb_FixedWingGuidanceStateBus_R - rtb_Minus *
                              rtb_Minus);
        rtb_FixedWingGuidanceStateBus_R = rtb_FixedWingGuidanceStateBus_F *
          rtb_Minus / d;
        distToCenter_tmp[0] = x2 - rtb_FixedWingGuidanceStateBus_R;
        rtb_Minus = rtb_Abs1_n * rtb_Minus / d;
        rtb_Sum_kt_idx_1 = rtb_Minus + rtb_Abs1_m;
        u[0] = codegenReal2Mission_DW.obj_m.PrevPosition[0] - rtb_Sum_nj[0];
        u[1] = codegenReal2Mission_DW.obj_m.PrevPosition[1] - rtb_Sum_nj[1];
        u[2] = 0.0;
        rtb_Sum_nj[0] = Vg;
        rtb_Sum_nj[1] = q;
        rtb_Sum_nj[2] = 0.0;
        rtb_Sum1_b_idx_1 = codegenReal2Mission_norm_b(u);
        b = codegenReal2Mission_norm_b(rtb_Sum_nj);
        u[0] /= rtb_Sum1_b_idx_1;
        rtb_Sum_nj[0] = Vg / b;
        u[1] /= rtb_Sum1_b_idx_1;
        rtb_Sum_nj[1] = q / b;
        d = u[0] * rtb_Sum_nj[1] - u[1] * rtb_Sum_nj[0];
        rtb_Speed2d3Path = (u[0] * rtb_Sum_nj[0] + u[1] * rtb_Sum_nj[1]) + 0.0 /
          rtb_Sum1_b_idx_1 * (0.0 / b);
        codegenReal2Mission_DW.obj_m.PrevPosition[0] =
          codegenReal2Mission_B.SimUAVStateZOH.North;
        codegenReal2Mission_DW.obj_m.PrevPosition[1] =
          codegenReal2Mission_B.SimUAVStateZOH.East;
        codegenReal2Mission_DW.obj_m.PrevPosition[2] =
          codegenReal2Mission_B.Down;
        codegenReal2Mission_DW.obj_m.NumCircles += rt_atan2d_snf(d,
          rtb_Speed2d3Path) / 2.0 / 3.1415926535897931;
        if ((distToCenter_tmp[0] - codegenReal2Mission_B.SimUAVStateZOH.North) *
            rtb_FixedWingGuidanceStateBus_F - (rtb_Sum_kt_idx_1 -
             codegenReal2Mission_B.SimUAVStateZOH.East) * rtb_Abs1_n > 0.0) {
          Vg = distToCenter_tmp[0];
        } else {
          Vg = rtb_FixedWingGuidanceStateBus_R + x2;
          rtb_Sum_kt_idx_1 = rtb_Abs1_m - rtb_Minus;
        }
      }
    }

    if (guard1) {
      rtb_Sum1_b_idx_1 = codegenReal2Mission_norm(distToCenter_tmp);
      Vg = Vg / rtb_Sum1_b_idx_1 * 500.0 + rtb_Sum_nj[0];
      rtb_Sum_kt_idx_1 = q / rtb_Sum1_b_idx_1 * 500.0 + rtb_Sum_nj[1];
    }

    // MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_B.TakeOffGathering_o2 = rt_atan2d_snf(rtb_Sum_kt_idx_1 -
      codegenReal2Mission_B.SimUAVStateZOH.East, Vg -
      codegenReal2Mission_B.SimUAVStateZOH.North);
  }

  // End of MATLABSystem: '<S2>/TakeOffGathering'

  // Gain: '<S2>/Down2Height'
  codegenReal2Mission_B.Down2Height = 150.0;
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Matfile logging
    rt_UpdateTXYLogVars((&codegenReal2Mission_M)->rtwLogInfo,
                        ((&codegenReal2Mission_M)->Timing.t));
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Update for Memory: '<S2>/Memory'
      codegenReal2Mission_DW.Memory_PreviousInput =
        codegenReal2Mission_B.Down2Height;

      // Update for Delay: '<S2>/Delay'
      codegenReal2Mission_DW.icLoad = 0U;

      // Update for BusCreator: '<S2>/Bus Creator' incorporates:
      //   Delay: '<S2>/Delay'

      codegenReal2Mission_DW.Delay_DSTATE =
        codegenReal2Mission_B.TakeOffGathering_o2;
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

  // Derivatives for Atomic SubSystem: '<S2>/MissionSimUAV'
  // Derivatives for Integrator: '<S16>/Integrator' incorporates:
  //   MATLABSystem: '<S16>/ComputeDerivative'

  std::memcpy(&_rtXdot->Integrator_CSTATE[0],
              &codegenReal2Mission_B.ComputeDerivative[0], sizeof(real_T) << 3U);

  // End of Derivatives for SubSystem: '<S2>/MissionSimUAV'
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
    rt_DataLoggingInfo.loggingInterval = NULL;
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
      static int_T rt_ScopeSignalWidths[] = { 8, 8, 1, 1, 3, 1, 1 };

      static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1, 1, 2, 2, 1 };

      static int_T rt_ScopeSignalDimensions[] = { 8, 8, 1, 1, 3, 1, 1, 1, 1 };

      static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL), (NULL),
        (NULL), (NULL), (NULL), (NULL), (NULL) };

      static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4 };

      static const char_T *rt_ScopeSignalLabels[] = { "RealUAVState_Log",
        "SimUAVState_Log",
        "RefAirspeed_Log",
        "LagDistance_Log",
        "LookAheadNED_Log",
        "CrossTrackError_Log",
        "EngagedFlag_Log" };

      static char_T rt_ScopeSignalTitles[] =
        "RealUAVState_LogSimUAVState_LogRefAirspeed_LogLagDistance_LogLookAheadNED_LogCrossTrackError_LogEngagedFlag_Log";
      static int_T rt_ScopeSignalTitleLengths[] = { 16, 15, 15, 15, 16, 19, 15 };

      static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0, 0, 0, 0, 0 };

      static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

      BuiltInDTypeId dTypes[7] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE,
        SS_DOUBLE, SS_DOUBLE, SS_BOOLEAN };

      static char_T rt_ScopeBlockName[] = "codegenReal2Mission/ModelLogging";
      static int_T rt_ScopeFrameData[] = { 0, 0, 0, 0, 0, 0, 0 };

      static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
        (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL)
      };

      rt_ScopeSignalInfo.numSignals = 7;
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

    codegenReal2Mission_PrevZCX.UD_Reset_ZCE = POS_ZCSIG;

    // InitializeConditions for Memory: '<S2>/Memory'
    codegenReal2Mission_DW.Memory_PreviousInput = 50.0;

    // InitializeConditions for Delay: '<S2>/Delay'
    codegenReal2Mission_DW.icLoad = 1U;

    // SystemInitialize for Atomic SubSystem: '<S2>/MissionSimUAV'
    // InitializeConditions for RateLimiter: '<S10>/ClimbRateLimiter'
    codegenReal2Mission_DW.PrevY = 150.0;

    // InitializeConditions for UnitDelay: '<S12>/UD'
    //
    //  Block description for '<S12>/UD':
    //
    //   Store in Global RAM

    codegenReal2Mission_DW.UD_DSTATE_f = 150.0;

    // InitializeConditions for Integrator: '<S16>/Integrator'
    std::memset(&codegenReal2Mission_X.Integrator_CSTATE[0], 0, sizeof(real_T) <<
                3U);

    // InitializeConditions for UnitDelay: '<S17>/UD'
    //
    //  Block description for '<S17>/UD':
    //
    //   Store in Global RAM

    codegenReal2Mission_DW.UD_DSTATE_jn = 35.0;

    // Start for MATLABSystem: '<S16>/ComputeDerivative'
    codegenReal2Mission_DW.obj_a.isInitialized = 0;
    codegenReal2Mission_DW.obj_a.isInitialized = 1;
    codegenReal2Mis_Model_resetImpl(&codegenReal2Mission_DW.obj_a);

    // InitializeConditions for MATLABSystem: '<S16>/ComputeDerivative'
    codegenReal2Mis_Model_resetImpl(&codegenReal2Mission_DW.obj_a);

    // Outputs for Atomic SubSystem: '<S10>/InitializeSimLocation'
    // DataStoreWrite: '<S13>/DSnumMissionUAV' incorporates:
    //   Constant: '<S13>/Number Of Mission UAV'

    codegenReal2Mission_DW.numMissionUAV = codegenReal2Mission_P.numMissionUAV;

    // DataStoreWrite: '<S13>/DSuavIDX' incorporates:
    //   Constant: '<S13>/UAVidx'

    codegenReal2Mission_DW.UAVidx = codegenReal2Mission_P.UAVidx;

    // DataStoreWrite: '<S13>/DSAltitudeGCS' incorporates:
    //   Constant: '<S13>/AltitudeGCS'

    codegenReal2Mission_DW.AltitudeGCS = codegenReal2Mission_P.GCS_Altitude;

    // DataStoreWrite: '<S13>/DSLatitudeGCS' incorporates:
    //   Constant: '<S13>/LatitudeGCS'

    codegenReal2Mission_DW.LatitudeGCS = codegenReal2Mission_P.GCS_Latitude;

    // DataStoreWrite: '<S13>/DSLongitudeGCS' incorporates:
    //   Constant: '<S13>/LongitudeGCS'

    codegenReal2Mission_DW.LongitudeGCS = codegenReal2Mission_P.GCS_Longitude;

    // Product: '<S13>/Map2Radian' incorporates:
    //   Bias: '<S13>/Bias'
    //   Constant: '<S13>/2pi'
    //   Constant: '<S13>/Number Of Mission UAV'
    //   Constant: '<S13>/UAVidx'
    //   DataTypeConversion: '<S13>/Cast To Double'
    //   Gain: '<S13>/Gain'
    //   Product: '<S13>/Divide'
    //   Sum: '<S13>/Minus'

    rtb_ClockwiseRotation = (static_cast<real_T>(codegenReal2Mission_P.UAVidx) -
      static_cast<real_T>(static_cast<int64_T>
                          (codegenReal2Mission_P.numMissionUAV + 1) << 30) *
      4.6566128730773926E-10) * (6.2831853071795862 / static_cast<real_T>
      (codegenReal2Mission_P.numMissionUAV));

    // StateWriter: '<S13>/SimUAVState' incorporates:
    //   Bias: '<S13>/ClockwiseRotation'
    //   Constant: '<S13>/InitialFlightPathAngle'
    //   Constant: '<S13>/InitialHeight'
    //   Constant: '<S13>/InitialRollAngle'
    //   Constant: '<S13>/InitialRollAngleRate'
    //   Constant: '<S13>/InitialUAVAirspeed'
    //   Constant: '<S13>/Radius'
    //   Product: '<S13>/EastDis'
    //   Product: '<S13>/NorthDis'
    //   Trigonometry: '<S13>/Cos'
    //   Trigonometry: '<S13>/Sin'

    codegenReal2Mission_X.Integrator_CSTATE[4] = rtb_ClockwiseRotation +
      1.5707963267948966;
    codegenReal2Mission_X.Integrator_CSTATE[0] = std::cos(rtb_ClockwiseRotation)
      * 500.0;
    codegenReal2Mission_X.Integrator_CSTATE[1] = 500.0 * std::sin
      (rtb_ClockwiseRotation);
    codegenReal2Mission_X.Integrator_CSTATE[2] = 150.0;
    codegenReal2Mission_X.Integrator_CSTATE[3] = 35.0;
    codegenReal2Mission_X.Integrator_CSTATE[5] = 0.0;
    codegenReal2Mission_X.Integrator_CSTATE[6] = 0.0;
    codegenReal2Mission_X.Integrator_CSTATE[7] = 0.0;
    rtsiSetBlockStateForSolverChangedAtMajorStep(&(&codegenReal2Mission_M)
      ->solverInfo, true);
    rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
      (&(&codegenReal2Mission_M)->solverInfo, true);

    // End of Outputs for SubSystem: '<S10>/InitializeSimLocation'
    // End of SystemInitialize for SubSystem: '<S2>/MissionSimUAV'

    // SystemInitialize for Atomic SubSystem: '<Root>/GenerateTrack'
    for (i = 0; i < 60; i++) {
      // InitializeConditions for S-Function (sfix_udelay): '<S3>/HeightSequence' 
      codegenReal2Mission_DW.HeightSequence_X[i] = -50.0;
    }

    // End of SystemInitialize for SubSystem: '<Root>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<Root>/SpeedControl'
    // InitializeConditions for Delay: '<S6>/Speed2d3Path'
    for (i = 0; i < 20; i++) {
      codegenReal2Mission_DW.Speed2d3Path_DSTATE[i] = 35.0;
    }

    // End of InitializeConditions for Delay: '<S6>/Speed2d3Path'
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

    // Start for MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.isInitialized = 0;
    codegenReal2Mission_DW.obj_m.isInitialized = 1;
    codegenReal2Mission_DW.obj_m.PrevResetSignal = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_m.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevResetSignal *= 0.0;
    codegenReal2Mission_DW.obj_m.NumCircles *= 0.0;

    // Start for MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[0] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[0] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[0] *= 0.0;

    // Start for MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[1] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[1] = (rtNaN);
    codegenReal2Mission_DW.obj_m.PrevPosition[1] *= 0.0;

    // Start for MATLABSystem: '<S2>/TakeOffGathering'
    codegenReal2Mission_DW.obj_m.PrevPosition[2] = 0.0;
    codegenReal2Mission_DW.obj_m.OrbitCenterInternal[2] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S2>/TakeOffGathering'
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
