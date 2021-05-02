//
// File: PreemptableMissionModeSelector.cpp
//
// Code generated for Simulink model 'PreemptableMissionModeSelector'.
//
// Model version                  : 2.427
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  2 12:25:38 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives:
//    1. Safety precaution
//    2. Execution efficiency
//    3. RAM efficiency
//    4. ROM efficiency
// Validation result: Not run
//
#include "PreemptableMissionModeSelector.h"
#include "PreemptableMissionModeSelector_private.h"
#include "mod_dBqh4Vat.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf.h"
#include "rt_remd_snf.h"
#include "skip_to_last_equal_value_ZlLNIyBv.h"
#include "wrapToPi_iEuDNbvh.h"

// Named constants for Chart: '<Root>/PreemptableMissionModeSelector'
const uint8_T PreemptableMissionModeSelector_IN_CircleDisplayNav{ 1U };

const uint8_T PreemptableMissionModeSelector_IN_CirclingNav{ 2U };

const uint8_T PreemptableMissionModeSelector_IN_CustomFormationNav{ 1U };

const uint8_T PreemptableMissionModeSelector_IN_HorizontalFormationNav{ 2U };

const uint8_T PreemptableMissionModeSelector_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T PreemptableMissionModeSelector_IN_OrbitFollower{ 1U };

const uint8_T PreemptableMissionModeSelector_IN_ProtectionLine{ 2U };

const uint8_T PreemptableMissionModeSelector_IN_RunWayNav{ 3U };

const uint8_T PreemptableMissionModeSelector_IN_WaitToStart{ 4U };

const uint8_T PreemptableMissionModeSelector_IN_WaypointFollower{ 5U };

// Forward declaration for local functions
static real_T PreemptableMissionModeSelector_norm(const real_T x[2]);
static real_T PreemptableMissionModeSelector_norm_m(const real_T x[3]);
static real_T PreemptableMissionModeSelector_angdiff(real_T x, real_T y);

// Forward declaration for local functions
static void PreemptableMissionModeSelector_emxInit_real_T
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions);
static void PreemptableMissionModeSelector_emxEnsureCapacity_real_T
  (emxArray_real_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel);
static void PreemptableMissionModeSelector_WaypointFollowerBase_getDistinctWpts(
  const real_T waypoints[30720],
  emxArray_real_T_PreemptableMissionModeSelector_T *distinctWpts,
  B_WaypointFollower_PreemptableMissionModeSelector_T *localB);
static real_T PreemptableMissionModeSelector_norm_ml(const real_T x[3]);
static void PreemptableMissionModeSelector_WaypointFollowerBase_createWaypoint
  (uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
   *obj, real_T virtualWaypoint[3]);
static void PreemptableMissionModeSelector_emxFree_real_T
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray);
static void PreemptableMissionModeSelector_WaypointFollowerBase_getWaypoints
  (uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
   *obj, const emxArray_real_T_PreemptableMissionModeSelector_T *waypoints,
   real_T startWaypoint[3], real_T endWaypoint[3]);
static void
  PreemptableMissionModeSelector_WaypointFollowerBase_endWaypointReached_c
  (uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
   *obj, const emxArray_real_T_PreemptableMissionModeSelector_T *waypoints,
   real_T curStartWaypoint[3], real_T curEndWaypoint[3], const real_T
   currentPose[4]);
static real_T PreemptableMissionModeSelector_WaypointFollowerBase_pointToLine(
  const real_T p1[3], const real_T p2[3], const real_T p[3]);
static real_T PreemptableMissionModeSelector_WaypointFollowerBase_projectToLine(
  const real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
  currentPosition[3]);
static void PreemptableMissionModeSelector_WaypointFollowerBase_getLookahead(
  const
  uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
  *obj, const real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
  currentPosition[3], real_T lookaheadPoint[3]);
static void PreemptableMissionModeSelector_WaypointFollowerBase_stepInternal
  (uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
   *obj, const real_T currentPose[4], const real_T waypointsIn[30720], real_T
   lookaheadDist, real_T lookaheadPoint[3], real_T *desiredHeading, real_T
   *desiredYaw, uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T
   *status, B_WaypointFollower_PreemptableMissionModeSelector_T *localB);

// Forward declaration for local functions
static void PreemptableMissionModeSelector_emxInit_real_T_h
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions);
static void PreemptableMissionModeSelector_exit_internal_GuidanceLogic
  (DW_PreemptableMissionModeSelector_f_T *localDW);
static void PreemptableMissionModeSelector_emxFree_real_T_n
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray);
static uavDubinsConnection_PreemptableMissionModeSelector_T
  *PreemptableMissionModeSelector_uavDubinsConnection_uavDubinsConnection
  (uavDubinsConnection_PreemptableMissionModeSelector_T *b_this);
static
  matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
  *PreemptableMissionModeSelector_NameValueParser_NameValueParser
  (matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
   *obj);
static void PreemptableMissionModeSelector_validatestring(const char_T str[7],
  char_T out_data[], int32_T out_size[2]);
static boolean_T PreemptableMissionModeSelector_strcmp(const char_T a_data[],
  const int32_T a_size[2]);
static void PreemptableMissionModeSelector_merge(int32_T idx_data[], int32_T
  x_data[], int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[],
  int32_T xwork_data[]);
static void PreemptableMissionModeSelector_sort(int32_T x_data[], const int32_T *
  x_size, int32_T idx_data[], int32_T *idx_size);
static void PreemptableMissionModeSelector_do_vectors(real_T c_data[], int32_T
  c_size[2], int32_T ia_data[], int32_T *ia_size, int32_T *ib_size);
static void PreemptableMissionModeSelector_do_vectors_b(const real_T b_data[],
  const int32_T *b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[],
  int32_T *ia_size, int32_T *ib_size);
static void PreemptableMissionModeSelector_merge_n(int32_T idx_data[], real_T
  x_data[], int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
  xwork_data[]);
static void PreemptableMissionModeSelector_sortIdx(real_T x_data[], int32_T
  *x_size, int32_T idx_data[], int32_T *idx_size);
static void PreemptableMissionModeSelector_sort_p(real_T x_data[], const int32_T
  *x_size);
static void
  PreemptableMissionModeSelector_uavDubinsConnection_findDisabledIndices(real_T
  idx_data[], int32_T *idx_size);
static void
  * PreemptableMissionModeSelector_uavDubinsBuildable_uavDubinsBuildable(real_T
  airSpeed, real_T maxRollAngle, const real_T flightPathAngle[2], const real_T
  disabledPathTypes_data[], const int32_T *disabledPathTypes_size);
static void PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
  (emxArray_real_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel);
static boolean_T PreemptableMissionModeSelector_strcmp_m(const char_T a_data[],
  const int32_T a_size[2]);
static boolean_T PreemptableMissionModeSelector_strcmp_m2(const char_T a_data[],
  const int32_T a_size[2]);
static void
  PreemptableMissionModeSelector_uavDubinsPathSegment_uavDubinsPathSegment_c(
  const real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3,
  real_T varargin_4, real_T varargin_5, real_T varargin_6, const
  cell_wrap_1_PreemptableMissionModeSelector_T varargin_7[4], const real_T
  varargin_8[4], uavDubinsPathSegment_PreemptableMissionModeSelector_T *b_this);
static real_T PreemptableMissionModeSelector_sum(const real_T x_data[]);
static void PreemptableMissionModeSelector_uavDubinsBuiltins_connect(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *obj, const real_T
  startPose[4], const real_T goalPose[4], boolean_T flagOptimal, real_T
  turningRadius, const real_T dpt_data[], const int32_T *dpt_size,
  uavDubinsPathSegment_PreemptableMissionModeSelector_T pathSegObjs_data[],
  int32_T *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
  B_PreemptableMissionModeSelector_c_T *localB);
static void PreemptableMissionModeSelector_uavDubinsConnection_connect(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *obj, const real_T
  startPoses[4], const real_T goalPoses[4],
  uavDubinsPathSegment_PreemptableMissionModeSelector_T pathSegObjs_data[],
  int32_T *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
  B_PreemptableMissionModeSelector_c_T *localB);
static void PreemptableMissionModeSelector_strcmp_m2j(const
  cell_wrap_1_PreemptableMissionModeSelector_T a[4], boolean_T b_bool[4]);
static boolean_T PreemptableMissionModeSelector_any(const boolean_T x[4]);
static void PreemptableMissionModeSelector_useConstantDim(const real_T
  varargin_2_data[], const int32_T varargin_2_size[2], real_T varargout_1_data[],
  int32_T varargout_1_size[2]);
static void PreemptableMissionModeSelector_emxInit_real_T1
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions);
static void PreemptableMissionModeSelector_eml_find(boolean_T x, int32_T i_data[],
  int32_T i_size[2]);
static void PreemptableMissionModeSelector_emxEnsureCapacity_real_T1
  (emxArray_real_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel);
static boolean_T PreemptableMissionModeSelector_strcmp_m2ju(const char_T a_data[],
  const int32_T a_size[2]);
static boolean_T PreemptableMissionModeSelector_strcmp_m2juc(const char_T
  a_data[], const int32_T a_size[2]);
static void PreemptableMissionModeSelector_emxInit_boolean_T1
  (emxArray_boolean_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions);
static void PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T1
  (emxArray_boolean_T_PreemptableMissionModeSelector_T *emxArray, int32_T
   oldNumel);
static void PreemptableMissionModeSelector_emxFree_boolean_T
  (emxArray_boolean_T_PreemptableMissionModeSelector_T **pEmxArray);
static void PreemptableMissionModeSelector_wrapToPi
  (emxArray_real_T_PreemptableMissionModeSelector_T *theta);
static boolean_T PreemptableMissionModeSelector_strcmp_m2jucf(const char_T
  a_data[], const int32_T a_size[2]);
static boolean_T PreemptableMissionModeSelector_strcmp_m2jucfm(const char_T
  a_data[], const int32_T a_size[2]);
static boolean_T PreemptableMissionModeSelector_strcmp_m2jucfmm(const char_T
  a_data[], const int32_T a_size[2]);
static boolean_T PreemptableMissionModeSelector_strcmp_m2jucfmmw(const char_T
  a_data[], const int32_T a_size[2]);
static void PreemptableMissionModeSelector_mtimes(const
  emxArray_real_T_PreemptableMissionModeSelector_T *A, const real_T B[4],
  emxArray_real_T_PreemptableMissionModeSelector_T *C);
static void PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate(
  const real_T b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_1_PreemptableMissionModeSelector_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, real_T samples, real_T poses_data[], int32_T poses_size[2]);
static void PreemptableMissionModeSelector_emxInit_int32_T
  (emxArray_int32_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions);
static void PreemptableMissionModeSelector_emxEnsureCapacity_int32_T
  (emxArray_int32_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel);
static void PreemptableMissionModeSelector_emxInit_int32_T1
  (emxArray_int32_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions);
static void PreemptableMissionModeSelector_emxEnsureCapacity_int32_T1
  (emxArray_int32_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel);
static void PreemptableMissionModeSelector_emxFree_int32_T
  (emxArray_int32_T_PreemptableMissionModeSelector_T **pEmxArray);
static void PreemptableMissionModeSelector_merge_ni
  (emxArray_int32_T_PreemptableMissionModeSelector_T *idx,
   emxArray_real_T_PreemptableMissionModeSelector_T *x, int32_T offset, int32_T
   np, int32_T nq, emxArray_int32_T_PreemptableMissionModeSelector_T *iwork,
   emxArray_real_T_PreemptableMissionModeSelector_T *xwork);
static void PreemptableMissionModeSelector_merge_block
  (emxArray_int32_T_PreemptableMissionModeSelector_T *idx,
   emxArray_real_T_PreemptableMissionModeSelector_T *x, int32_T offset, int32_T
   n, int32_T preSortLevel, emxArray_int32_T_PreemptableMissionModeSelector_T
   *iwork, emxArray_real_T_PreemptableMissionModeSelector_T *xwork);
static void PreemptableMissionModeSelector_sort_ps
  (emxArray_real_T_PreemptableMissionModeSelector_T *x);
static void PreemptableMissionModeSelector_emxInit_boolean_T
  (emxArray_boolean_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions);
static void PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T
  (emxArray_boolean_T_PreemptableMissionModeSelector_T *emxArray, int32_T
   oldNumel);
static void PreemptableMissionModeSelector_eml_find_h(const
  emxArray_boolean_T_PreemptableMissionModeSelector_T *x,
  emxArray_int32_T_PreemptableMissionModeSelector_T *i);
static void PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate_p(
  const real_T b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_1_PreemptableMissionModeSelector_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, emxArray_real_T_PreemptableMissionModeSelector_T *samples,
  emxArray_real_T_PreemptableMissionModeSelector_T *poses);
static void PreemptableMissionModeSelector_genSegWP(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *connectionObj, const
  real_T start[4], const real_T ende[4], real_T b_stepSize,
  emxArray_real_T_PreemptableMissionModeSelector_T *segWayPoints,
  B_PreemptableMissionModeSelector_c_T *localB);
static void
  PreemptableMissionModeSelector_uavDubinsPathSegment_uavDubinsPathSegment_fw(
  const real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3,
  real_T varargin_4, real_T varargin_5, real_T varargin_6, const
  cell_wrap_10_PreemptableMissionModeSelector_T varargin_7[4], const real_T
  varargin_8[4], uavDubinsPathSegment_PreemptableMissionModeSelector_b_T *b_this);
static void PreemptableMissionModeSelector_uavDubinsBuiltins_connect_i(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *obj, const real_T
  startPose[4], const real_T goalPose[4], boolean_T flagOptimal, real_T
  turningRadius, const real_T dpt_data[], const int32_T *dpt_size,
  uavDubinsPathSegment_PreemptableMissionModeSelector_b_T pathSegObjs_data[],
  int32_T *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
  B_PreemptableMissionModeSelector_c_T *localB);
static void PreemptableMissionModeSelector_uavDubinsConnection_connect_j(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *obj, const real_T
  startPoses[4], const real_T goalPoses[4],
  uavDubinsPathSegment_PreemptableMissionModeSelector_b_T pathSegObjs_data[],
  int32_T *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
  B_PreemptableMissionModeSelector_c_T *localB);
static void PreemptableMissionModeSelector_strcmp_imet(const
  cell_wrap_10_PreemptableMissionModeSelector_T a[4], boolean_T b_bool[4]);
static void PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate_c(
  const real_T b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_10_PreemptableMissionModeSelector_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, emxArray_real_T_PreemptableMissionModeSelector_T *samples,
  emxArray_real_T_PreemptableMissionModeSelector_T *poses);
static void PreemptableMissionModeSelector_genSegWP_la(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *connectionObj, const
  real_T start[4], const real_T ende[4], real_T b_stepSize,
  emxArray_real_T_PreemptableMissionModeSelector_T *segWayPoints,
  B_PreemptableMissionModeSelector_c_T *localB);
static void PreemptableMissionModeSelector_repmat(const
  emxArray_real_T_PreemptableMissionModeSelector_T *a, real_T varargin_1,
  emxArray_real_T_PreemptableMissionModeSelector_T *b);
static real_T PreemptableMissionModeSelector_norm(const real_T x[2])
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

static real_T PreemptableMissionModeSelector_norm_m(const real_T x[3])
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

static real_T PreemptableMissionModeSelector_angdiff(real_T x, real_T y)
{
  real_T delta;
  real_T q;
  real_T thetaWrap;
  boolean_T rEQ0;
  delta = y - x;
  if (std::abs(delta) > 3.1415926535897931) {
    if (std::isnan(delta + 3.1415926535897931) || std::isinf(delta +
         3.1415926535897931)) {
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

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//
void PreemptableMissionModeSelector_OrbitFollower_Init
  (DW_OrbitFollower_PreemptableMissionModeSelector_T *localDW)
{
  // Start for MATLABSystem: '<S2>/Orbit Follower'
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.PrevResetSignal = 0.0;
  localDW->obj.NumCircles = 0.0;

  // InitializeConditions for MATLABSystem: '<S2>/Orbit Follower'
  localDW->obj.OrbitRadiusInternal = (rtNaN);
  localDW->obj.PrevResetSignal *= 0.0;
  localDW->obj.NumCircles *= 0.0;

  // Start for MATLABSystem: '<S2>/Orbit Follower'
  localDW->obj.PrevPosition[0] = 0.0;

  // InitializeConditions for MATLABSystem: '<S2>/Orbit Follower'
  localDW->obj.OrbitCenterInternal[0] = (rtNaN);
  localDW->obj.PrevPosition[0] *= 0.0;

  // Start for MATLABSystem: '<S2>/Orbit Follower'
  localDW->obj.PrevPosition[1] = 0.0;

  // InitializeConditions for MATLABSystem: '<S2>/Orbit Follower'
  localDW->obj.OrbitCenterInternal[1] = (rtNaN);
  localDW->obj.PrevPosition[1] *= 0.0;

  // Start for MATLABSystem: '<S2>/Orbit Follower'
  localDW->obj.PrevPosition[2] = 0.0;

  // InitializeConditions for MATLABSystem: '<S2>/Orbit Follower'
  localDW->obj.OrbitCenterInternal[2] = (rtNaN);
  localDW->obj.PrevPosition[2] *= 0.0;
  localDW->obj.StartFlag = true;
  localDW->obj.SelectTurnDirectionFlag = true;
  localDW->obj.TurnDirectionInternal = 1.0;
  localDW->obj.OrbitRadiusFlag = 0U;
  localDW->obj.LookaheadDistFlag = 0U;
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//
void PreemptableMissionModeSelector_OrbitFollower(const real_T rtu_0[4], const
  real_T rtu_1[3], real_T rtu_2, real_T rtu_3, real_T rtu_4,
  B_OrbitFollower_PreemptableMissionModeSelector_T *localB,
  DW_OrbitFollower_PreemptableMissionModeSelector_T *localDW)
{
  real_T u[3];
  real_T v[3];
  real_T distToCenter_tmp[2];
  real_T rtu_0_0[2];
  real_T a;
  real_T d;
  real_T distToCenter;
  real_T h;
  real_T radius;
  real_T rtu_0_tmp;
  real_T u_tmp;
  real_T v_tmp;
  real_T x2;
  real_T xyCenter_idx_0;
  real_T y2;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_k;
  boolean_T exitg1;
  boolean_T guard1{ false };

  boolean_T p;
  boolean_T p_0;

  // MATLABSystem: '<S2>/Orbit Follower'
  radius = rtu_2;
  localDW->obj.OrbitRadiusFlag = 0U;
  if (rtu_2 <= 220.0) {
    radius = 220.0;
    localDW->obj.OrbitRadiusFlag = 1U;
  }

  distToCenter = rtu_4;
  localDW->obj.LookaheadDistFlag = 0U;
  if (rtu_4 < 35.0) {
    distToCenter = 35.0;
    localDW->obj.LookaheadDistFlag = 1U;
  }

  xyCenter_idx_0 = rtu_0[0] - rtu_1[0];
  rtu_0_0[0] = xyCenter_idx_0;
  rtu_0_tmp = rtu_0[1] - rtu_1[1];
  rtu_0_0[1] = rtu_0_tmp;
  if (PreemptableMissionModeSelector_norm(rtu_0_0) < 2.47032822920623E-323) {
    // MATLABSystem: '<S2>/Orbit Follower'
    localB->OrbitFollower_o1[0] = radius * std::cos(rtu_0[3]) + rtu_0[0];
    localB->OrbitFollower_o1[1] = radius * std::sin(rtu_0[3]) + rtu_0[1];
    localB->OrbitFollower_o1[2] = rtu_1[2];

    // MATLABSystem: '<S2>/Orbit Follower'
    localB->OrbitFollower_o2 = rtu_0[3];

    // MATLABSystem: '<S2>/Orbit Follower'
    localB->OrbitFollower_o6 = localDW->obj.NumCircles;
  } else {
    p = false;
    p_0 = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 3)) {
      if ((localDW->obj.OrbitCenterInternal[b_k] == rtu_1[b_k]) || (std::isnan
           (localDW->obj.OrbitCenterInternal[b_k]) && std::isnan(rtu_1[b_k]))) {
        b_k = static_cast<int32_T>(b_k + 1);
      } else {
        p_0 = false;
        exitg1 = true;
      }
    }

    if (p_0) {
      p = true;
    }

    guard1 = false;
    if (!p) {
      guard1 = true;
    } else {
      p = false;
      if ((localDW->obj.OrbitRadiusInternal == radius) || (std::isnan
           (localDW->obj.OrbitRadiusInternal) && std::isnan(radius))) {
        p = true;
      }

      if (!p) {
        guard1 = true;
      }
    }

    if (guard1) {
      localDW->obj.NumCircles = 0.0;
      localDW->obj.OrbitCenterInternal[0] = rtu_1[0];
      localDW->obj.OrbitCenterInternal[1] = rtu_1[1];
      localDW->obj.OrbitCenterInternal[2] = rtu_1[2];
      localDW->obj.OrbitRadiusInternal = radius;
      localDW->obj.SelectTurnDirectionFlag = true;
    }

    if (distToCenter >= radius) {
      localDW->obj.LookaheadDistance = 0.9 * radius;
    } else {
      localDW->obj.LookaheadDistance = distToCenter;
    }

    distToCenter_tmp[0] = xyCenter_idx_0;
    distToCenter_tmp[1] = rtu_0_tmp;
    distToCenter = std::sqrt(rtu_0_tmp * rtu_0_tmp + xyCenter_idx_0 *
      xyCenter_idx_0);
    y2 = radius + localDW->obj.LookaheadDistance;
    x2 = std::abs(y2);
    p = !std::isinf(x2);
    p_0 = !std::isnan(x2);
    if (p && p_0) {
      if (x2 <= 2.2250738585072014E-308) {
        d = 4.94065645841247E-324;
      } else {
        frexp(x2, &b_exponent);
        d = std::ldexp(1.0, static_cast<int32_T>(b_exponent - 53));
      }
    } else {
      d = (rtNaN);
    }

    guard1 = false;
    if (distToCenter >= y2 - 5.0 * d) {
      guard1 = true;
    } else {
      if (p && p_0) {
        if (x2 <= 2.2250738585072014E-308) {
          d = 4.94065645841247E-324;
        } else {
          frexp(x2, &b_exponent_0);
          d = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0 - 53));
        }
      } else {
        d = (rtNaN);
      }

      if (distToCenter <= (radius - localDW->obj.LookaheadDistance) + 5.0 * d) {
        guard1 = true;
      } else {
        if (localDW->obj.StartFlag) {
          localDW->obj.PrevPosition[0] = rtu_0[0];
          localDW->obj.PrevPosition[1] = rtu_0[1];
          localDW->obj.StartFlag = false;
        }

        rtu_0_0[0] = xyCenter_idx_0;
        rtu_0_0[1] = rtu_0_tmp;
        d = PreemptableMissionModeSelector_norm(rtu_0_0);
        h = localDW->obj.LookaheadDistance * localDW->obj.LookaheadDistance;
        a = ((h - radius * radius) + d * d) / (2.0 * d);
        radius = rtu_1[0] - rtu_0[0];
        x2 = radius * a / d + rtu_0[0];
        distToCenter = rtu_1[1] - rtu_0[1];
        y2 = distToCenter * a / d + rtu_0[1];
        h = std::sqrt(h - a * a);
        a = distToCenter * h / d;
        distToCenter_tmp[0] = x2 - a;
        distToCenter_tmp[1] = a + x2;
        x2 = radius * h / d;
        d = x2 + y2;
        y2 -= x2;
        if ((rtu_3 == 0.0) && (!localDW->obj.SelectTurnDirectionFlag)) {
          x2 = localDW->obj.TurnDirectionInternal;
        } else {
          x2 = rtu_3;
        }

        h = localDW->obj.PrevPosition[0] - rtu_1[0];
        a = localDW->obj.PrevPosition[1] - rtu_1[1];
        u[0] = h;
        u[1] = a;
        u[2] = 0.0;
        v[0] = xyCenter_idx_0;
        v[1] = rtu_0_tmp;
        v[2] = 0.0;
        if (x2 < 0.0) {
          u[0] = xyCenter_idx_0;
          v[0] = h;
          u[1] = rtu_0_tmp;
          v[1] = a;
          u[2] = 0.0;
          v[2] = 0.0;
          x2 = -1.0;
        } else if (x2 > 0.0) {
          x2 = 1.0;
        } else if (x2 == 0.0) {
          x2 = 0.0;
        } else {
          x2 = (rtNaN);
        }

        h = PreemptableMissionModeSelector_norm_m(u);
        rtu_0_tmp = PreemptableMissionModeSelector_norm_m(v);
        xyCenter_idx_0 = u[0] / h;
        a = v[0] / rtu_0_tmp;
        u_tmp = u[1] / h;
        v_tmp = v[1] / rtu_0_tmp;
        localDW->obj.PrevPosition[0] = rtu_0[0];
        localDW->obj.PrevPosition[1] = rtu_0[1];
        localDW->obj.PrevPosition[2] = rtu_0[2];
        localDW->obj.NumCircles += rt_atan2d_snf(xyCenter_idx_0 * v_tmp - a *
          u_tmp, (xyCenter_idx_0 * a + u_tmp * v_tmp) + 0.0 / h * (0.0 /
          rtu_0_tmp)) / 2.0 / 3.1415926535897931;

        // MATLABSystem: '<S2>/Orbit Follower'
        localB->OrbitFollower_o6 = localDW->obj.NumCircles;
        switch (static_cast<int32_T>(x2)) {
         case 1:
          if ((distToCenter_tmp[0] - rtu_0[0]) * distToCenter - (d - rtu_0[1]) *
              radius > 0.0) {
            xyCenter_idx_0 = distToCenter_tmp[0];
            y2 = d;
          } else {
            xyCenter_idx_0 = distToCenter_tmp[1];
          }
          break;

         case -1:
          if ((distToCenter_tmp[0] - rtu_0[0]) * distToCenter - (d - rtu_0[1]) *
              radius < 0.0) {
            xyCenter_idx_0 = distToCenter_tmp[0];
            y2 = d;
          } else {
            xyCenter_idx_0 = distToCenter_tmp[1];
          }
          break;

         default:
          if (std::abs(PreemptableMissionModeSelector_angdiff(rt_atan2d_snf(d -
                 rtu_0[1], distToCenter_tmp[0] - rtu_0[0]), rtu_0[3])) < std::
              abs(PreemptableMissionModeSelector_angdiff(rt_atan2d_snf(y2 -
                 rtu_0[1], distToCenter_tmp[1] - rtu_0[0]), rtu_0[3]))) {
            xyCenter_idx_0 = distToCenter_tmp[0];
            y2 = d;
          } else {
            xyCenter_idx_0 = distToCenter_tmp[1];
          }

          if ((xyCenter_idx_0 - rtu_0[0]) * distToCenter - (y2 - rtu_0[1]) *
              radius > 0.0) {
            localDW->obj.TurnDirectionInternal = 1.0;
          } else {
            localDW->obj.TurnDirectionInternal = -1.0;
          }

          localDW->obj.SelectTurnDirectionFlag = false;
          break;
        }
      }
    }

    if (guard1) {
      h = PreemptableMissionModeSelector_norm(distToCenter_tmp);
      xyCenter_idx_0 = xyCenter_idx_0 / h * radius + rtu_1[0];
      y2 = rtu_0_tmp / h * radius + rtu_1[1];

      // MATLABSystem: '<S2>/Orbit Follower'
      localB->OrbitFollower_o6 = localDW->obj.NumCircles;
    }

    // MATLABSystem: '<S2>/Orbit Follower'
    localB->OrbitFollower_o1[0] = xyCenter_idx_0;
    localB->OrbitFollower_o1[1] = y2;
    localB->OrbitFollower_o1[2] = rtu_1[2];

    // MATLABSystem: '<S2>/Orbit Follower'
    localB->OrbitFollower_o2 = rt_atan2d_snf(y2 - rtu_0[1], xyCenter_idx_0 -
      rtu_0[0]);
  }

  // End of MATLABSystem: '<S2>/Orbit Follower'
}

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void PreemptableMissionModeSelector_RotateATMissionHdg_Init
  (DW_RotateATMissionHdg_PreemptableMissionModeSelector_T *localDW)
{
  // Start for MATLABSystem: '<S56>/RotateATMissionHdg'
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void PreemptableMissionModeSelector_RotateATMissionHdg(const real_T rtu_0[3],
  B_RotateATMissionHdg_PreemptableMissionModeSelector_T *localB)
{
  real_T RotateATMissionHdg_tmp;
  real_T RotateATMissionHdg_tmp_0;
  real_T ct_idx_0;
  real_T ct_idx_1;
  real_T ct_idx_2;
  real_T st_idx_0;
  real_T st_idx_1;
  real_T st_idx_2;

  // MATLABSystem: '<S56>/RotateATMissionHdg'
  ct_idx_0 = std::cos(rtu_0[0]);
  ct_idx_1 = std::cos(rtu_0[1]);
  ct_idx_2 = std::cos(rtu_0[2]);
  st_idx_0 = std::sin(rtu_0[0]);
  st_idx_1 = std::sin(rtu_0[1]);
  st_idx_2 = std::sin(rtu_0[2]);
  localB->RotateATMissionHdg[0] = ct_idx_0 * ct_idx_1;
  RotateATMissionHdg_tmp = st_idx_1 * st_idx_2;
  localB->RotateATMissionHdg[3] = RotateATMissionHdg_tmp * ct_idx_0 - st_idx_0 *
    ct_idx_2;
  RotateATMissionHdg_tmp_0 = st_idx_1 * ct_idx_2;
  localB->RotateATMissionHdg[6] = RotateATMissionHdg_tmp_0 * ct_idx_0 + st_idx_0
    * st_idx_2;
  localB->RotateATMissionHdg[1] = st_idx_0 * ct_idx_1;
  localB->RotateATMissionHdg[4] = RotateATMissionHdg_tmp * st_idx_0 + ct_idx_0 *
    ct_idx_2;
  localB->RotateATMissionHdg[7] = RotateATMissionHdg_tmp_0 * st_idx_0 - ct_idx_0
    * st_idx_2;
  localB->RotateATMissionHdg[2] = -st_idx_1;
  localB->RotateATMissionHdg[5] = ct_idx_1 * st_idx_2;
  localB->RotateATMissionHdg[8] = ct_idx_1 * ct_idx_2;
}

//
// Output and update for atomic system:
//    '<S56>/biasNED'
//    '<S86>/biasNED'
//
void PreemptableMissionModeSelector_biasNED(const real_T rtu_MissionNED[3],
  const real_T rtu_IndivRotWP[30720], real_T rty_nedWayPoint[30720],
  B_biasNED_PreemptableMissionModeSelector_T *localB)
{
  int32_T ibmat;
  int32_T itilerow;
  int32_T jcol;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = static_cast<int32_T>(jcol * 10240);
    for (itilerow = 0; itilerow < 10240; itilerow++) {
      localB->b[static_cast<int32_T>(ibmat + itilerow)] = rtu_MissionNED[jcol];
    }
  }

  for (jcol = 0; jcol < 10240; jcol++) {
    rty_nedWayPoint[jcol] = rtu_IndivRotWP[static_cast<int32_T>(jcol + 10240)] +
      localB->b[jcol];
    rty_nedWayPoint[static_cast<int32_T>(jcol + 10240)] = localB->b
      [static_cast<int32_T>(jcol + 10240)] + rtu_IndivRotWP[jcol];
    rty_nedWayPoint[static_cast<int32_T>(jcol + 20480)] = rtu_IndivRotWP[
      static_cast<int32_T>(jcol + 20480)] + localB->b[static_cast<int32_T>(jcol
      + 20480)];
  }
}

//
// Output and update for atomic system:
//    '<S56>/biasNEDstartpose'
//    '<S86>/biasNEDstartpose'
//
void PreemptableMissionModeSelector_biasNEDstartpose(const real_T
  rtu_MissionNED[3], const real_T rtu_IndivRotWP[3], real_T rty_nedWayPoint[3])
{
  rty_nedWayPoint[0] = rtu_MissionNED[0] + rtu_IndivRotWP[1];
  rty_nedWayPoint[1] = rtu_IndivRotWP[0] + rtu_MissionNED[1];
  rty_nedWayPoint[2] = rtu_IndivRotWP[2] + rtu_MissionNED[2];
}

//
// Output and update for atomic system:
//    '<S56>/minus'
//    '<S86>/minus'
//
void PreemptableMissionModeSelector_minus(const real_T rtu_uP[30720], const
  real_T rtu_uN[3], real_T rty_y[30720])
{
  int32_T ibmat;
  int32_T itilerow;
  int32_T jcol;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = static_cast<int32_T>(jcol * 10240);
    for (itilerow = 0; itilerow < 10240; itilerow++) {
      rty_y[static_cast<int32_T>(ibmat + itilerow)] = rtu_uN[jcol];
    }
  }

  for (jcol = 0; jcol < 30720; jcol++) {
    rty_y[jcol] = rtu_uP[jcol] - rty_y[jcol];
  }
}

static void PreemptableMissionModeSelector_emxInit_real_T
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_real_T_PreemptableMissionModeSelector_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_PreemptableMissionModeSelector_T *)std::malloc
    (sizeof(emxArray_real_T_PreemptableMissionModeSelector_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T) *
    static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
    emxArray->size[i] = 0;
  }
}

static void PreemptableMissionModeSelector_emxEnsureCapacity_real_T
  (emxArray_real_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel)
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
      std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof(real_T) *
        static_cast<uint32_T>(oldNumel)));
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void PreemptableMissionModeSelector_WaypointFollowerBase_getDistinctWpts(
  const real_T waypoints[30720],
  emxArray_real_T_PreemptableMissionModeSelector_T *distinctWpts,
  B_WaypointFollower_PreemptableMissionModeSelector_T *localB)
{
  int32_T i1;
  int32_T i2;
  int32_T ix;
  int32_T j;
  int32_T x_tmp;
  boolean_T exitg1;
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < 10239; i2++) {
      x_tmp = static_cast<int32_T>(static_cast<int32_T>(10240 * i1) + i2);
      localB->x[x_tmp] = (waypoints[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(i2 + 2) + static_cast<int32_T>(10240 * i1)) - 1)]
                          != waypoints[x_tmp]);
    }

    localB->x[static_cast<int32_T>(static_cast<int32_T>(10240 * i1) + 10239)] =
      true;
  }

  i1 = 0;
  i2 = 20480;
  x_tmp = 0;
  for (j = 0; j < 10240; j++) {
    localB->b[j] = false;
    i1 = static_cast<int32_T>(i1 + 1);
    i2 = static_cast<int32_T>(i2 + 1);
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!localB->x[static_cast<int32_T>(ix - 1)]) {
        ix = static_cast<int32_T>(ix + 10240);
      } else {
        localB->b[j] = true;
        exitg1 = true;
      }
    }

    if (localB->b[j]) {
      x_tmp = static_cast<int32_T>(x_tmp + 1);
    }
  }

  i1 = 0;
  for (i2 = 0; i2 < 10240; i2++) {
    if (localB->b[i2]) {
      localB->c_data[i1] = static_cast<int16_T>(static_cast<int32_T>(i2 + 1));
      i1 = static_cast<int32_T>(i1 + 1);
    }
  }

  i1 = static_cast<int32_T>(distinctWpts->size[0] * distinctWpts->size[1]);
  distinctWpts->size[0] = x_tmp;
  distinctWpts->size[1] = 3;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T(distinctWpts, i1);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 <= static_cast<int32_T>(x_tmp - 1); i2++) {
      distinctWpts->data[static_cast<int32_T>(i2 + static_cast<int32_T>
        (distinctWpts->size[0] * i1))] = waypoints[static_cast<int32_T>(
        static_cast<int32_T>(static_cast<int32_T>(10240 * i1) +
        static_cast<int32_T>(localB->c_data[i2])) - 1)];
    }
  }
}

static real_T PreemptableMissionModeSelector_norm_ml(const real_T x[3])
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

static void PreemptableMissionModeSelector_WaypointFollowerBase_createWaypoint
  (uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
   *obj, real_T virtualWaypoint[3])
{
  virtualWaypoint[0] = obj->InitialPose[0];
  virtualWaypoint[1] = obj->InitialPose[1];
  virtualWaypoint[2] = obj->InitialPose[2];
  obj->StartFlag = false;
}

static void PreemptableMissionModeSelector_emxFree_real_T
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_PreemptableMissionModeSelector_T *)nullptr)
  {
    if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_PreemptableMissionModeSelector_T *)nullptr;
  }
}

static void PreemptableMissionModeSelector_WaypointFollowerBase_getWaypoints
  (uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
   *obj, const emxArray_real_T_PreemptableMissionModeSelector_T *waypoints,
   real_T startWaypoint[3], real_T endWaypoint[3])
{
  boolean_T p;
  p = false;
  if (obj->WaypointIndex == obj->NumWaypoints) {
    p = true;
  }

  if (p) {
    obj->LastWaypointFlag = true;
    obj->WaypointIndex--;
  }

  startWaypoint[0] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>
    (obj->WaypointIndex) - 1)];
  endWaypoint[0] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>
    (obj->WaypointIndex + 1.0) - 1)];
  startWaypoint[1] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>(
    static_cast<int32_T>(obj->WaypointIndex) + waypoints->size[0]) - 1)];
  endWaypoint[1] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>(
    static_cast<int32_T>(obj->WaypointIndex + 1.0) + waypoints->size[0]) - 1)];
  startWaypoint[2] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>(
    static_cast<int32_T>(obj->WaypointIndex) + static_cast<int32_T>
    (waypoints->size[0] << 1)) - 1)];
  endWaypoint[2] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>(
    static_cast<int32_T>(obj->WaypointIndex + 1.0) + static_cast<int32_T>
    (waypoints->size[0] << 1)) - 1)];
}

static void
  PreemptableMissionModeSelector_WaypointFollowerBase_endWaypointReached_c
  (uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
   *obj, const emxArray_real_T_PreemptableMissionModeSelector_T *waypoints,
   real_T curStartWaypoint[3], real_T curEndWaypoint[3], const real_T
   currentPose[4])
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
  curEndWaypoint_1 = PreemptableMissionModeSelector_norm_ml(tmp);
  guard1 = false;
  if (curEndWaypoint_1 <= 100.0) {
    guard1 = true;
  } else {
    curEndWaypoint_tmp = curEndWaypoint[0] - curStartWaypoint[0];
    curEndWaypoint_0[0] = curEndWaypoint_tmp;
    curEndWaypoint_tmp_0 = curEndWaypoint[1] - curStartWaypoint[1];
    curEndWaypoint_0[1] = curEndWaypoint_tmp_0;
    curEndWaypoint_tmp_1 = curEndWaypoint[2] - curStartWaypoint[2];
    curEndWaypoint_0[2] = curEndWaypoint_tmp_1;
    tmp_0 = PreemptableMissionModeSelector_norm_ml(curEndWaypoint_0);
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

    curStartWaypoint[0] = waypoints->data[static_cast<int32_T>
      (static_cast<int32_T>(obj->WaypointIndex) - 1)];
    curEndWaypoint[0] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>
      (obj->WaypointIndex + 1.0) - 1)];
    curStartWaypoint[1] = waypoints->data[static_cast<int32_T>
      (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
        waypoints->size[0]) - 1)];
    curEndWaypoint[1] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>
      (static_cast<int32_T>(obj->WaypointIndex + 1.0) + waypoints->size[0]) - 1)];
    curStartWaypoint[2] = waypoints->data[static_cast<int32_T>
      (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
        static_cast<int32_T>(waypoints->size[0] << 1)) - 1)];
    curEndWaypoint[2] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>
      (static_cast<int32_T>(obj->WaypointIndex + 1.0) + static_cast<int32_T>
       (waypoints->size[0] << 1)) - 1)];
  }
}

static real_T PreemptableMissionModeSelector_WaypointFollowerBase_pointToLine(
  const real_T p1[3], const real_T p2[3], const real_T p[3])
{
  real_T p_0[3];
  real_T p_1[3];
  real_T p_2[3];
  real_T dist;
  real_T lambda;
  real_T lambda_tmp_tmp;
  real_T lambda_tmp_tmp_0;
  real_T lambda_tmp_tmp_1;
  real_T p_tmp;
  real_T p_tmp_0;
  lambda_tmp_tmp = p2[0] - p1[0];
  lambda = p[0] - p1[0];
  p_0[0] = lambda;
  p_1[0] = p[0] - p2[0];
  lambda_tmp_tmp_0 = p2[1] - p1[1];
  p_tmp = p[1] - p1[1];
  p_0[1] = p_tmp;
  p_1[1] = p[1] - p2[1];
  lambda_tmp_tmp_1 = p2[2] - p1[2];
  p_tmp_0 = p[2] - p1[2];
  p_0[2] = p_tmp_0;
  p_1[2] = p[2] - p2[2];
  lambda = (p_tmp_0 * lambda_tmp_tmp_1 + (p_tmp * lambda_tmp_tmp_0 + lambda *
             lambda_tmp_tmp)) / (lambda_tmp_tmp_1 * lambda_tmp_tmp_1 +
    (lambda_tmp_tmp_0 * lambda_tmp_tmp_0 + lambda_tmp_tmp * lambda_tmp_tmp));
  p_2[0] = p[0] - (lambda_tmp_tmp * lambda + p1[0]);
  p_2[1] = p[1] - (lambda_tmp_tmp_0 * lambda + p1[1]);
  p_2[2] = p[2] - (lambda_tmp_tmp_1 * lambda + p1[2]);
  if (lambda < 0.0) {
    dist = PreemptableMissionModeSelector_norm_ml(p_0);
  } else if (lambda > 1.0) {
    dist = PreemptableMissionModeSelector_norm_ml(p_1);
  } else {
    dist = PreemptableMissionModeSelector_norm_ml(p_2);
  }

  return dist;
}

static real_T PreemptableMissionModeSelector_WaypointFollowerBase_projectToLine(
  const real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
  currentPosition[3])
{
  real_T currentPosition_0[3];
  real_T dist;
  real_T lambda;
  real_T lambda_tmp_tmp;
  real_T lambda_tmp_tmp_0;
  real_T lambda_tmp_tmp_1;
  lambda_tmp_tmp = endWaypoint[0] - startWaypoint[0];
  lambda_tmp_tmp_0 = endWaypoint[1] - startWaypoint[1];
  lambda_tmp_tmp_1 = endWaypoint[2] - startWaypoint[2];
  lambda = ((currentPosition[2] - startWaypoint[2]) * lambda_tmp_tmp_1 +
            ((currentPosition[1] - startWaypoint[1]) * lambda_tmp_tmp_0 +
             (currentPosition[0] - startWaypoint[0]) * lambda_tmp_tmp)) /
    (lambda_tmp_tmp_1 * lambda_tmp_tmp_1 + (lambda_tmp_tmp_0 * lambda_tmp_tmp_0
      + lambda_tmp_tmp * lambda_tmp_tmp));
  currentPosition_0[0] = currentPosition[0] - (lambda * lambda_tmp_tmp +
    startWaypoint[0]);
  currentPosition_0[1] = currentPosition[1] - (lambda * lambda_tmp_tmp_0 +
    startWaypoint[1]);
  currentPosition_0[2] = currentPosition[2] - (lambda * lambda_tmp_tmp_1 +
    startWaypoint[2]);
  dist = PreemptableMissionModeSelector_norm_ml(currentPosition_0);
  return dist;
}

static void PreemptableMissionModeSelector_WaypointFollowerBase_getLookahead(
  const
  uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
  *obj, const real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
  currentPosition[3], real_T lookaheadPoint[3])
{
  real_T a_tmp_tmp;
  real_T a_tmp_tmp_0;
  real_T b;
  real_T b_tmp_idx_0_tmp;
  real_T b_tmp_idx_1_tmp;
  real_T b_tmp_idx_2_tmp;
  real_T y;
  b = endWaypoint[0] - startWaypoint[0];
  b_tmp_idx_0_tmp = startWaypoint[0] - currentPosition[0];
  a_tmp_tmp = endWaypoint[1] - startWaypoint[1];
  b_tmp_idx_1_tmp = startWaypoint[1] - currentPosition[1];
  a_tmp_tmp_0 = endWaypoint[2] - startWaypoint[2];
  y = a_tmp_tmp_0 * a_tmp_tmp_0 + (a_tmp_tmp * a_tmp_tmp + b * b);
  b_tmp_idx_2_tmp = startWaypoint[2] - currentPosition[2];
  b = ((b * b_tmp_idx_0_tmp + a_tmp_tmp * b_tmp_idx_1_tmp) + a_tmp_tmp_0 *
       b_tmp_idx_2_tmp) * 2.0;
  b_tmp_idx_0_tmp = std::sqrt(b * b - (((b_tmp_idx_0_tmp * b_tmp_idx_0_tmp +
    b_tmp_idx_1_tmp * b_tmp_idx_1_tmp) + b_tmp_idx_2_tmp * b_tmp_idx_2_tmp) -
    obj->LookaheadDistance * obj->LookaheadDistance) * (4.0 * y));
  y = std::fmax((-b + b_tmp_idx_0_tmp) / 2.0 / y, (-b - b_tmp_idx_0_tmp) / 2.0 /
                y);
  lookaheadPoint[0] = (1.0 - y) * startWaypoint[0] + y * endWaypoint[0];
  lookaheadPoint[1] = (1.0 - y) * startWaypoint[1] + y * endWaypoint[1];
  lookaheadPoint[2] = (1.0 - y) * startWaypoint[2] + y * endWaypoint[2];
}

static void PreemptableMissionModeSelector_WaypointFollowerBase_stepInternal
  (uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
   *obj, const real_T currentPose[4], const real_T waypointsIn[30720], real_T
   lookaheadDist, real_T lookaheadPoint[3], real_T *desiredHeading, real_T
   *desiredYaw, uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T
   *status, B_WaypointFollower_PreemptableMissionModeSelector_T *localB)
{
  emxArray_real_T_PreemptableMissionModeSelector_T *b_waypointsIn;
  emxArray_real_T_PreemptableMissionModeSelector_T *waypoints;
  real_T appendedWaypoints_data[6];
  real_T endWaypoint[3];
  real_T virtualWaypoint[3];
  real_T absx_tmp;
  real_T r;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_k;
  int32_T loop_ub;
  boolean_T exitg1;
  boolean_T guard1{ false };

  boolean_T p;
  boolean_T p_0;
  obj->LookaheadDistFlag = 0U;
  if (lookaheadDist < 0.1) {
    lookaheadDist = 0.1;
    obj->LookaheadDistFlag = 1U;
  }

  *lookaheadDistFlag = obj->LookaheadDistFlag;
  obj->InitialPose[0] = 0.0;
  obj->InitialPose[1] = 0.0;
  obj->InitialPose[2] = 0.0;
  obj->InitialPose[3] = 0.0;
  for (b_k = 0; b_k < 30720; b_k++) {
    localB->paddedWaypts[b_k] = (rtNaN);
  }

  for (b_k = 0; b_k < 3; b_k++) {
    for (loop_ub = 0; loop_ub < 10240; loop_ub++) {
      localB->paddedWaypts[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(loop_ub + 1) + static_cast<int32_T>(10240 * b_k)) -
        1)] = waypointsIn[static_cast<int32_T>(static_cast<int32_T>(10240 * b_k)
        + loop_ub)];
    }
  }

  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 30720)) {
    if ((obj->WaypointsInternal[b_k] == localB->paddedWaypts[b_k]) || (std::
         isnan(obj->WaypointsInternal[b_k]) && std::isnan(localB->
          paddedWaypts[b_k]))) {
      b_k = static_cast<int32_T>(b_k + 1);
    } else {
      p_0 = false;
      exitg1 = true;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    std::memcpy(&obj->WaypointsInternal[0], &localB->paddedWaypts[0],
                static_cast<uint32_T>(30720U * sizeof(real_T)));
    obj->WaypointIndex = 1.0;
  }

  PreemptableMissionModeSelector_emxInit_real_T(&b_waypointsIn, 2);
  PreemptableMissionModeSelector_WaypointFollowerBase_getDistinctWpts
    (waypointsIn, b_waypointsIn, localB);
  obj->NumWaypoints = static_cast<real_T>(b_waypointsIn->size[0]);
  obj->LookaheadDistance = lookaheadDist;
  PreemptableMissionModeSelector_emxInit_real_T(&waypoints, 2);
  if (b_waypointsIn->size[0] == 0) {
    lookaheadPoint[0] = lookaheadDist * std::cos(currentPose[3]) + currentPose[0];
    lookaheadPoint[1] = lookaheadDist * std::sin(currentPose[3]) + currentPose[1];
    lookaheadPoint[2] = lookaheadDist * 0.0 + currentPose[2];
    *desiredHeading = currentPose[3];
    *desiredYaw = currentPose[3];
    *crossTrackError = 0.0;
    *status = 1U;
  } else {
    guard1 = false;
    if (b_waypointsIn->size[0] == 1) {
      if (obj->StartFlag) {
        obj->InitialPose[0] = currentPose[0];
        obj->InitialPose[1] = currentPose[1];
        obj->InitialPose[2] = currentPose[2];
        obj->InitialPose[3] = currentPose[3];
      }

      virtualWaypoint[0] = b_waypointsIn->data[0] - currentPose[0];
      virtualWaypoint[1] = b_waypointsIn->data[1] - currentPose[1];
      virtualWaypoint[2] = b_waypointsIn->data[2] - currentPose[2];
      if (PreemptableMissionModeSelector_norm_ml(virtualWaypoint) <
          1.4901161193847656E-8) {
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
        PreemptableMissionModeSelector_WaypointFollowerBase_createWaypoint(obj,
          virtualWaypoint);
        for (b_k = 0; b_k < 3; b_k++) {
          appendedWaypoints_data[static_cast<int32_T>(b_k << 1)] =
            virtualWaypoint[b_k];
          appendedWaypoints_data[static_cast<int32_T>(1 + static_cast<int32_T>
            (b_k << 1))] = b_waypointsIn->data[static_cast<int32_T>
            (b_waypointsIn->size[0] * b_k)];
        }

        obj->NumWaypoints = 2.0;
        b_k = static_cast<int32_T>(waypoints->size[0] * waypoints->size[1]);
        waypoints->size[0] = 2;
        waypoints->size[1] = 3;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T(waypoints, b_k);
        for (b_k = 0; b_k < 6; b_k++) {
          waypoints->data[b_k] = appendedWaypoints_data[b_k];
        }

        guard1 = true;
      }
    } else {
      b_k = static_cast<int32_T>(waypoints->size[0] * waypoints->size[1]);
      waypoints->size[0] = b_waypointsIn->size[0];
      waypoints->size[1] = 3;
      PreemptableMissionModeSelector_emxEnsureCapacity_real_T(waypoints, b_k);
      loop_ub = static_cast<int32_T>(b_waypointsIn->size[0] * 3);
      for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
        waypoints->data[b_k] = b_waypointsIn->data[b_k];
      }

      guard1 = true;
    }

    if (guard1) {
      PreemptableMissionModeSelector_WaypointFollowerBase_getWaypoints(obj,
        waypoints, virtualWaypoint, endWaypoint);
      PreemptableMissionModeSelector_WaypointFollowerBase_endWaypointReached_c
        (obj, waypoints, virtualWaypoint, endWaypoint, currentPose);
      *crossTrackError =
        PreemptableMissionModeSelector_WaypointFollowerBase_pointToLine
        (virtualWaypoint, endWaypoint, &currentPose[0]);
      if (obj->LastWaypointFlag) {
        *crossTrackError =
          PreemptableMissionModeSelector_WaypointFollowerBase_projectToLine
          (virtualWaypoint, endWaypoint, &currentPose[0]);
      }

      absx_tmp = std::abs(*crossTrackError);
      if ((!std::isinf(absx_tmp)) && (!std::isnan(absx_tmp))) {
        if (absx_tmp <= 2.2250738585072014E-308) {
          r = 4.94065645841247E-324;
          absx_tmp = 4.94065645841247E-324;
        } else {
          frexp(absx_tmp, &b_exponent);
          r = std::ldexp(1.0, static_cast<int32_T>(b_exponent - 53));
          frexp(absx_tmp, &b_exponent_0);
          absx_tmp = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0 - 53));
        }
      } else {
        r = (rtNaN);
        absx_tmp = (rtNaN);
      }

      if (obj->LookaheadDistance <= std::fmax(std::sqrt(r), 5.0 * absx_tmp) +
          *crossTrackError) {
        obj->LookaheadDistance = obj->LookaheadFactor * *crossTrackError;
      }

      PreemptableMissionModeSelector_WaypointFollowerBase_getLookahead(obj,
        virtualWaypoint, endWaypoint, &currentPose[0], lookaheadPoint);
      *desiredHeading = rt_atan2d_snf(lookaheadPoint[1] - currentPose[1],
        lookaheadPoint[0] - currentPose[0]);
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

  PreemptableMissionModeSelector_emxFree_real_T(&b_waypointsIn);
  PreemptableMissionModeSelector_emxFree_real_T(&waypoints);
}

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void PreemptableMissionModeSelector_WaypointFollower_Init
  (DW_WaypointFollower_PreemptableMissionModeSelector_T *localDW)
{
  int32_T i;

  // Start for MATLABSystem: '<S4>/Waypoint Follower'
  localDW->obj.LastWaypointFlag = false;
  localDW->obj.StartFlag = true;
  localDW->obj.LookaheadFactor = 1.01;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;

  // InitializeConditions for MATLABSystem: '<S4>/Waypoint Follower'
  localDW->obj.WaypointIndex = 1.0;
  for (i = 0; i < 30720; i++) {
    // Start for MATLABSystem: '<S4>/Waypoint Follower'
    localDW->obj.WaypointsInternal[i] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S4>/Waypoint Follower'
    localDW->obj.WaypointsInternal[i] = (rtNaN);
  }
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void PreemptableMissionModeSelector_WaypointFollower(const real_T rtu_0[4],
  const real_T rtu_1[30720], real_T rtu_2,
  B_WaypointFollower_PreemptableMissionModeSelector_T *localB,
  DW_WaypointFollower_PreemptableMissionModeSelector_T *localDW)
{
  real_T crossTrackError;
  real_T desiredYaw;
  uint8_T lookaheadFlag;

  // MATLABSystem: '<S4>/Waypoint Follower'
  PreemptableMissionModeSelector_WaypointFollowerBase_stepInternal(&localDW->obj,
    rtu_0, rtu_1, rtu_2, localB->WaypointFollower_o1,
    &localB->WaypointFollower_o2, &desiredYaw, &lookaheadFlag, &crossTrackError,
    &localB->WaypointFollower_o5, localB);
}

//
// Output and update for atomic system:
//    '<S117>/biasNED'
//    '<S168>/biasNED'
//
void PreemptableMissionModeSelector_biasNED_l(const real_T rtu_MissionNED[3],
  const real_T rtu_IndivRotWP[30720], real_T rty_nedWayPoint[30720],
  B_biasNED_PreemptableMissionModeSelector_h_T *localB)
{
  int32_T ibmat;
  int32_T itilerow;
  int32_T jcol;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = static_cast<int32_T>(jcol * 10240);
    for (itilerow = 0; itilerow < 10240; itilerow++) {
      localB->b[static_cast<int32_T>(ibmat + itilerow)] = rtu_MissionNED[jcol];
    }
  }

  for (jcol = 0; jcol < 10240; jcol++) {
    rty_nedWayPoint[jcol] = rtu_IndivRotWP[static_cast<int32_T>(jcol + 10240)] +
      localB->b[jcol];
    rty_nedWayPoint[static_cast<int32_T>(jcol + 10240)] = localB->b
      [static_cast<int32_T>(jcol + 10240)] + rtu_IndivRotWP[jcol];
    rty_nedWayPoint[static_cast<int32_T>(jcol + 20480)] = rtu_IndivRotWP[
      static_cast<int32_T>(jcol + 20480)] + localB->b[static_cast<int32_T>(jcol
      + 20480)];
  }
}

static void PreemptableMissionModeSelector_emxInit_real_T_h
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_real_T_PreemptableMissionModeSelector_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_PreemptableMissionModeSelector_T *)std::malloc
    (sizeof(emxArray_real_T_PreemptableMissionModeSelector_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T) *
    static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
    emxArray->size[i] = 0;
  }
}

// Function for Chart: '<Root>/PreemptableMissionModeSelector'
static void PreemptableMissionModeSelector_exit_internal_GuidanceLogic
  (DW_PreemptableMissionModeSelector_f_T *localDW)
{
  localDW->is_OrbitFollower = PreemptableMissionModeSelector_IN_NO_ACTIVE_CHILD;
  localDW->is_WaypointFollower =
    PreemptableMissionModeSelector_IN_NO_ACTIVE_CHILD;
  localDW->is_GuidanceLogic = PreemptableMissionModeSelector_IN_NO_ACTIVE_CHILD;
}

static void PreemptableMissionModeSelector_emxFree_real_T_n
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_PreemptableMissionModeSelector_T *)nullptr)
  {
    if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_PreemptableMissionModeSelector_T *)nullptr;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static uavDubinsConnection_PreemptableMissionModeSelector_T
  *PreemptableMissionModeSelector_uavDubinsConnection_uavDubinsConnection
  (uavDubinsConnection_PreemptableMissionModeSelector_T *b_this)
{
  uavDubinsConnection_PreemptableMissionModeSelector_T *c_this;
  real_T b_x;
  c_this = b_this;
  b_this->AirSpeed = 10.0;
  b_this->FlightPathAngleLimit[0] = -0.175;
  b_this->FlightPathAngleLimit[1] = 0.175;
  b_this->MaxRollAngle = 0.3490658503988659;
  b_x = b_this->MaxRollAngle;
  b_this->MinTurningRadius = b_this->AirSpeed * b_this->AirSpeed / (9.8 * std::
    tan(b_x));
  b_this->AirSpeed = 35.0;
  b_x = b_this->MaxRollAngle;
  b_this->MinTurningRadius = b_this->AirSpeed * b_this->AirSpeed / (9.8 * std::
    tan(b_x));
  b_x = b_this->MaxRollAngle;
  b_this->MinTurningRadius = b_this->AirSpeed * b_this->AirSpeed / (9.8 * std::
    tan(b_x));
  return c_this;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static
  matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
  *PreemptableMissionModeSelector_NameValueParser_NameValueParser
  (matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
   *obj)
{
  static const char_T c[7]{ 'o', 'p', 't', 'i', 'm', 'a', 'l' };

  cell_wrap_12_PreemptableMissionModeSelector_T b;
  matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
    *b_obj;
  int32_T i;
  b_obj = obj;
  for (i = 0; i < 7; i++) {
    b.f1[i] = c[i];
  }

  obj->Defaults = b;
  return b_obj;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_validatestring(const char_T str[7],
  char_T out_data[], int32_T out_size[2])
{
  static const char_T c[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~', '\x7f' };

  static const char_T d[7]{ 'o', 'p', 't', 'i', 'm', 'a', 'l' };

  int32_T exitg1;
  int32_T kstr;
  int32_T nmatched;
  boolean_T b_bool;
  nmatched = 0;
  b_bool = false;
  kstr = 0;
  do {
    exitg1 = 0;
    if (kstr < 7) {
      if (c[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
            (str[kstr])) & 127)] != c[static_cast<int32_T>(d[kstr])]) {
        exitg1 = 1;
      } else {
        kstr = static_cast<int32_T>(kstr + 1);
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (b_bool) {
    nmatched = 1;
    out_size[0] = 1;
    out_size[1] = 7;
    for (kstr = 0; kstr < 7; kstr++) {
      out_data[kstr] = d[kstr];
    }
  } else {
    out_size[0] = 1;
    out_size[1] = 0;
  }

  if (nmatched == 0) {
    out_size[0] = 1;
    out_size[1] = 0;
  } else if (out_size[1] == 0) {
    out_size[0] = 1;
    out_size[1] = 0;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp(const char_T a_data[],
  const int32_T a_size[2])
{
  static const char_T b[3]{ 'a', 'l', 'l' };

  int32_T exitg1;
  int32_T kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 3) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (a_data[kstr] != b[kstr]) {
          exitg1 = 1;
        } else {
          kstr = static_cast<int32_T>(kstr + 1);
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_merge(int32_T idx_data[], int32_T
  x_data[], int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[],
  int32_T xwork_data[])
{
  int32_T exitg1;
  int32_T iout;
  int32_T offset1;
  int32_T p;
  int32_T q;
  if (nq != 0) {
    offset1 = static_cast<int32_T>(np + nq);
    for (p = 0; p <= static_cast<int32_T>(offset1 - 1); p = static_cast<int32_T>
         (p + 1)) {
      q = static_cast<int32_T>(offset + p);
      iwork_data[p] = idx_data[q];
      xwork_data[p] = x_data[q];
    }

    p = 0;
    q = np;
    iout = static_cast<int32_T>(offset - 1);
    do {
      exitg1 = 0;
      iout = static_cast<int32_T>(iout + 1);
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (static_cast<int32_T>(p + 1) < np) {
          p = static_cast<int32_T>(p + 1);
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (static_cast<int32_T>(q + 1) < offset1) {
          q = static_cast<int32_T>(q + 1);
        } else {
          offset1 = static_cast<int32_T>(iout - p);
          while (static_cast<int32_T>(p + 1) <= np) {
            q = static_cast<int32_T>(static_cast<int32_T>(offset1 + p) + 1);
            idx_data[q] = iwork_data[p];
            x_data[q] = xwork_data[p];
            p = static_cast<int32_T>(p + 1);
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_sort(int32_T x_data[], const int32_T *
  x_size, int32_T idx_data[], int32_T *idx_size)
{
  int32_T b_idx_data[28];
  int32_T b_x_data[28];
  int32_T iwork_data[28];
  int32_T vwork_data[28];
  int32_T x4[4];
  int32_T b;
  int32_T dim;
  int32_T i1;
  int32_T i2;
  int32_T i4;
  int32_T nDone;
  int32_T nQuartets;
  int32_T nQuartets_tmp;
  int32_T nTail;
  int32_T tailOffset;
  int32_T tmp;
  int32_T vstride;
  int32_T vwork_size_idx_0;
  int8_T idx4[4];
  int8_T perm[4];
  dim = 2;
  if (*x_size != 1) {
    dim = 1;
    b = static_cast<int32_T>(*x_size - 1);
  } else {
    b = 0;
  }

  vwork_size_idx_0 = static_cast<int32_T>(b + 1);
  *idx_size = *x_size;
  vstride = 1;
  nDone = 0;
  while (nDone <= static_cast<int32_T>(dim - 2)) {
    vstride = static_cast<int32_T>(vstride * *x_size);
    nDone = 1;
  }

  for (dim = 0; dim <= static_cast<int32_T>(vstride - 1); dim =
       static_cast<int32_T>(dim + 1)) {
    for (nDone = 0; nDone <= b; nDone = static_cast<int32_T>(nDone + 1)) {
      vwork_data[nDone] = x_data[static_cast<int32_T>(static_cast<int32_T>(nDone
        * vstride) + dim)];
    }

    nQuartets = static_cast<int32_T>(static_cast<int8_T>(vwork_size_idx_0));
    for (nDone = 0; nDone <= static_cast<int32_T>(nQuartets - 1); nDone++) {
      b_idx_data[nDone] = 0;
    }

    if (vwork_size_idx_0 != 0) {
      for (nDone = 0; nDone <= static_cast<int32_T>(vwork_size_idx_0 - 1); nDone
           ++) {
        b_x_data[nDone] = vwork_data[nDone];
      }

      nQuartets = static_cast<int32_T>(static_cast<int8_T>(vwork_size_idx_0));
      for (nDone = 0; nDone <= static_cast<int32_T>(nQuartets - 1); nDone++) {
        b_idx_data[nDone] = 0;
      }

      x4[0] = 0;
      idx4[0] = 0;
      x4[1] = 0;
      idx4[1] = 0;
      x4[2] = 0;
      idx4[2] = 0;
      x4[3] = 0;
      idx4[3] = 0;
      nQuartets_tmp = static_cast<int32_T>(vwork_size_idx_0 >> 2);
      for (tailOffset = 0; tailOffset <= static_cast<int32_T>(nQuartets_tmp - 1);
           tailOffset = static_cast<int32_T>(tailOffset + 1)) {
        nTail = static_cast<int32_T>(tailOffset << 2);
        idx4[0] = static_cast<int8_T>(static_cast<int32_T>(nTail + 1));
        idx4[1] = static_cast<int8_T>(static_cast<int32_T>(nTail + 2));
        idx4[2] = static_cast<int8_T>(static_cast<int32_T>(nTail + 3));
        idx4[3] = static_cast<int8_T>(static_cast<int32_T>(nTail + 4));
        x4[0] = b_x_data[nTail];
        i1 = b_x_data[static_cast<int32_T>(nTail + 1)];
        x4[1] = i1;
        nDone = b_x_data[static_cast<int32_T>(nTail + 2)];
        x4[2] = nDone;
        nQuartets = b_x_data[static_cast<int32_T>(nTail + 3)];
        x4[3] = nQuartets;
        if (b_x_data[nTail] <= i1) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (nDone <= nQuartets) {
          nQuartets = 3;
          i4 = 4;
        } else {
          nQuartets = 4;
          i4 = 3;
        }

        nDone = x4[static_cast<int32_T>(i1 - 1)];
        tmp = x4[static_cast<int32_T>(nQuartets - 1)];
        if (nDone <= tmp) {
          nDone = x4[static_cast<int32_T>(i2 - 1)];
          if (nDone <= tmp) {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(i2);
            perm[2] = static_cast<int8_T>(nQuartets);
            perm[3] = static_cast<int8_T>(i4);
          } else if (nDone <= x4[static_cast<int32_T>(i4 - 1)]) {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(nQuartets);
            perm[2] = static_cast<int8_T>(i2);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(nQuartets);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(i2);
          }
        } else {
          tmp = x4[static_cast<int32_T>(i4 - 1)];
          if (nDone <= tmp) {
            if (x4[static_cast<int32_T>(i2 - 1)] <= tmp) {
              perm[0] = static_cast<int8_T>(nQuartets);
              perm[1] = static_cast<int8_T>(i1);
              perm[2] = static_cast<int8_T>(i2);
              perm[3] = static_cast<int8_T>(i4);
            } else {
              perm[0] = static_cast<int8_T>(nQuartets);
              perm[1] = static_cast<int8_T>(i1);
              perm[2] = static_cast<int8_T>(i4);
              perm[3] = static_cast<int8_T>(i2);
            }
          } else {
            perm[0] = static_cast<int8_T>(nQuartets);
            perm[1] = static_cast<int8_T>(i4);
            perm[2] = static_cast<int8_T>(i1);
            perm[3] = static_cast<int8_T>(i2);
          }
        }

        b_idx_data[nTail] = static_cast<int32_T>(idx4[static_cast<int32_T>(
          static_cast<int32_T>(perm[0]) - 1)]);
        b_idx_data[static_cast<int32_T>(nTail + 1)] = static_cast<int32_T>(idx4[
          static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)]);
        b_idx_data[static_cast<int32_T>(nTail + 2)] = static_cast<int32_T>(idx4[
          static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)]);
        b_idx_data[static_cast<int32_T>(nTail + 3)] = static_cast<int32_T>(idx4[
          static_cast<int32_T>(static_cast<int32_T>(perm[3]) - 1)]);
        b_x_data[nTail] = x4[static_cast<int32_T>(static_cast<int32_T>(perm[0])
          - 1)];
        b_x_data[static_cast<int32_T>(nTail + 1)] = x4[static_cast<int32_T>(
          static_cast<int32_T>(perm[1]) - 1)];
        b_x_data[static_cast<int32_T>(nTail + 2)] = x4[static_cast<int32_T>(
          static_cast<int32_T>(perm[2]) - 1)];
        b_x_data[static_cast<int32_T>(nTail + 3)] = x4[static_cast<int32_T>(
          static_cast<int32_T>(perm[3]) - 1)];
      }

      nDone = static_cast<int32_T>(nQuartets_tmp << 2);
      nQuartets = static_cast<int32_T>(vwork_size_idx_0 - nDone);
      if (nQuartets > 0) {
        for (tailOffset = 0; tailOffset <= static_cast<int32_T>(nQuartets - 1);
             tailOffset = static_cast<int32_T>(tailOffset + 1)) {
          nTail = static_cast<int32_T>(nDone + tailOffset);
          idx4[tailOffset] = static_cast<int8_T>(static_cast<int32_T>(nTail + 1));
          x4[tailOffset] = b_x_data[nTail];
        }

        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        switch (nQuartets) {
         case 1:
          perm[0] = 1;
          break;

         case 2:
          if (x4[0] <= x4[1]) {
            perm[0] = 1;
            perm[1] = 2;
          } else {
            perm[0] = 2;
            perm[1] = 1;
          }
          break;

         default:
          if (x4[0] <= x4[1]) {
            if (x4[1] <= x4[2]) {
              perm[0] = 1;
              perm[1] = 2;
              perm[2] = 3;
            } else if (x4[0] <= x4[2]) {
              perm[0] = 1;
              perm[1] = 3;
              perm[2] = 2;
            } else {
              perm[0] = 3;
              perm[1] = 1;
              perm[2] = 2;
            }
          } else if (x4[0] <= x4[2]) {
            perm[0] = 2;
            perm[1] = 1;
            perm[2] = 3;
          } else if (x4[1] <= x4[2]) {
            perm[0] = 2;
            perm[1] = 3;
            perm[2] = 1;
          } else {
            perm[0] = 3;
            perm[1] = 2;
            perm[2] = 1;
          }
          break;
        }

        for (tailOffset = 0; tailOffset <= static_cast<int32_T>(nQuartets - 1);
             tailOffset = static_cast<int32_T>(tailOffset + 1)) {
          nTail = static_cast<int32_T>(static_cast<int32_T>(perm[tailOffset]) -
            1);
          i1 = static_cast<int32_T>(nDone + tailOffset);
          b_idx_data[i1] = static_cast<int32_T>(idx4[nTail]);
          b_x_data[i1] = x4[nTail];
        }
      }

      if (vwork_size_idx_0 > 1) {
        for (nDone = 0; nDone <= static_cast<int32_T>(vwork_size_idx_0 - 1);
             nDone++) {
          vwork_data[nDone] = 0;
        }

        nQuartets = static_cast<int32_T>(static_cast<int8_T>(vwork_size_idx_0));
        for (nDone = 0; nDone <= static_cast<int32_T>(nQuartets - 1); nDone++) {
          iwork_data[nDone] = 0;
        }

        nQuartets = nQuartets_tmp;
        nDone = 4;
        while (nQuartets > 1) {
          if (static_cast<uint32_T>(static_cast<uint32_T>(nQuartets) & 1U) != 0U)
          {
            nQuartets = static_cast<int32_T>(nQuartets - 1);
            tailOffset = static_cast<int32_T>(nDone * nQuartets);
            nTail = static_cast<int32_T>(vwork_size_idx_0 - tailOffset);
            if (nTail > nDone) {
              PreemptableMissionModeSelector_merge(b_idx_data, b_x_data,
                tailOffset, nDone, static_cast<int32_T>(nTail - nDone),
                iwork_data, vwork_data);
            }
          }

          tailOffset = static_cast<int32_T>(nDone << 1);
          nQuartets = static_cast<int32_T>(nQuartets >> 1);
          for (nTail = 0; nTail <= static_cast<int32_T>(nQuartets - 1); nTail =
               static_cast<int32_T>(nTail + 1)) {
            PreemptableMissionModeSelector_merge(b_idx_data, b_x_data,
              static_cast<int32_T>(nTail * tailOffset), nDone, nDone, iwork_data,
              vwork_data);
          }

          nDone = tailOffset;
        }

        if (vwork_size_idx_0 > nDone) {
          PreemptableMissionModeSelector_merge(b_idx_data, b_x_data, 0, nDone,
            static_cast<int32_T>(vwork_size_idx_0 - nDone), iwork_data,
            vwork_data);
        }
      }

      for (nDone = 0; nDone <= static_cast<int32_T>(vwork_size_idx_0 - 1); nDone
           ++) {
        vwork_data[nDone] = b_x_data[nDone];
      }
    }

    for (nQuartets = 0; nQuartets <= b; nQuartets = static_cast<int32_T>
         (nQuartets + 1)) {
      nDone = static_cast<int32_T>(dim + static_cast<int32_T>(nQuartets *
        vstride));
      x_data[nDone] = vwork_data[nQuartets];
      idx_data[nDone] = b_idx_data[nQuartets];
    }
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_do_vectors(real_T c_data[], int32_T
  c_size[2], int32_T ia_data[], int32_T *ia_size, int32_T *ib_size)
{
  static const real_T a[28]{ 6.384265086E+9, 6.384265284E+9, 6.384480708E+9,
    6.384480906E+9, 6.384473283E+9, 6.384263997E+9, 2.1067690282E+11,
    2.10676902826E+11, 2.10677124976E+11, 2.10677124982E+11, 2.10677124751E+11,
    2.10676902787E+11, 2.10680747748E+11, 2.10680754288E+11, 2.10687863274E+11,
    2.10687869814E+11, 2.10687618255E+11, 2.10680711811E+11, 6.384264226E+9,
    6.384264232E+9, 6.384264001E+9, 6.38447332E+9, 6.384473281E+9,
    6.384473314E+9, 6.384265282E+9, 6.384480904E+9, 6.38426509E+9,
    6.384480712E+9 };

  static const int32_T aperm[28]{ 6, 21, 19, 20, 1, 27, 25, 2, 23, 5, 24, 22, 3,
    28, 26, 4, 12, 7, 8, 11, 9, 10, 18, 13, 14, 17, 15, 16 };

  static const int8_T e[28]{ 6, 21, 19, 20, 1, 27, 25, 2, 23, 5, 24, 22, 3, 28,
    26, 4, 12, 7, 8, 11, 9, 10, 18, 13, 14, 17, 15, 16 };

  emxArray_int32_T_28_PreemptableMissionModeSelector_T ia_data_0;
  int32_T b_ialast;
  int32_T iafirst;
  int32_T ialast;
  int32_T nc;
  int32_T nia;
  c_size[0] = 1;
  *ib_size = 0;
  nc = 0;
  nia = -1;
  iafirst = 0;
  ialast = 1;
  while (ialast <= 28) {
    b_ialast = ialast;
    skip_to_last_equal_value_ZlLNIyBv(&b_ialast, a, aperm);
    nc = static_cast<int32_T>(nc + 1);
    nia = static_cast<int32_T>(nia + 1);
    ia_data[nia] = static_cast<int32_T>(e[iafirst]);
    ialast = static_cast<int32_T>(b_ialast + 1);
    iafirst = b_ialast;
  }

  if (1 > static_cast<int32_T>(nia + 1)) {
    iafirst = -1;
  } else {
    iafirst = nia;
  }

  *ia_size = static_cast<int32_T>(iafirst + 1);
  PreemptableMissionModeSelector_sort(ia_data, ia_size, ia_data_0.data,
    &ia_data_0.size);
  for (iafirst = 0; iafirst <= nia; iafirst = static_cast<int32_T>(iafirst + 1))
  {
    c_data[iafirst] = a[static_cast<int32_T>(ia_data[iafirst] - 1)];
  }

  if (1 > nc) {
    c_size[1] = 0;
  } else {
    c_size[1] = nc;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_do_vectors_b(const real_T b_data[],
  const int32_T *b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[],
  int32_T *ia_size, int32_T *ib_size)
{
  emxArray_int32_T_28_PreemptableMissionModeSelector_T ia_data_0;
  real_T tmp[28];
  real_T ak;
  real_T b_absx;
  real_T bk;
  int32_T bperm_data[28];
  int32_T iwork_data[28];
  int32_T b_k;
  int32_T c_k;
  int32_T exponent;
  int32_T i;
  int32_T i2;
  int32_T ialast;
  int32_T ialast_tmp;
  int32_T j;
  int32_T kEnd;
  int32_T n;
  int32_T q;
  int32_T qEnd;
  int32_T tmp_0;
  boolean_T exitg1;
  c_size[0] = 1;
  *ib_size = 0;
  i = static_cast<int32_T>(static_cast<int8_T>(*b_size));
  for (ialast = 0; ialast <= static_cast<int32_T>(i - 1); ialast++) {
    bperm_data[ialast] = 0;
  }

  if (*b_size != 0) {
    for (ialast = 1; ialast <= static_cast<int32_T>(static_cast<int32_T>(*b_size
           + 1) - 2); ialast = static_cast<int32_T>(ialast + 2)) {
      if (b_data[static_cast<int32_T>(ialast - 1)] <= b_data[ialast]) {
        bperm_data[static_cast<int32_T>(ialast - 1)] = ialast;
        bperm_data[ialast] = static_cast<int32_T>(ialast + 1);
      } else {
        bperm_data[static_cast<int32_T>(ialast - 1)] = static_cast<int32_T>
          (ialast + 1);
        bperm_data[ialast] = ialast;
      }
    }

    if (static_cast<uint32_T>(static_cast<uint32_T>(*b_size) & 1U) != 0U) {
      bperm_data[static_cast<int32_T>(*b_size - 1)] = *b_size;
    }

    i = 2;
    while (i < static_cast<int32_T>(static_cast<int32_T>(*b_size + 1) - 1)) {
      i2 = static_cast<int32_T>(i << 1);
      j = 1;
      ialast = static_cast<int32_T>(i + 1);
      while (ialast < static_cast<int32_T>(*b_size + 1)) {
        n = j;
        q = ialast;
        qEnd = static_cast<int32_T>(j + i2);
        if (qEnd > static_cast<int32_T>(*b_size + 1)) {
          qEnd = static_cast<int32_T>(*b_size + 1);
        }

        c_k = 0;
        kEnd = static_cast<int32_T>(qEnd - j);
        while (static_cast<int32_T>(c_k + 1) <= kEnd) {
          ialast_tmp = bperm_data[static_cast<int32_T>(q - 1)];
          tmp_0 = bperm_data[static_cast<int32_T>(n - 1)];
          if (b_data[static_cast<int32_T>(tmp_0 - 1)] <= b_data
              [static_cast<int32_T>(ialast_tmp - 1)]) {
            iwork_data[c_k] = tmp_0;
            n = static_cast<int32_T>(n + 1);
            if (n == ialast) {
              while (q < qEnd) {
                c_k = static_cast<int32_T>(c_k + 1);
                iwork_data[c_k] = bperm_data[static_cast<int32_T>(q - 1)];
                q = static_cast<int32_T>(q + 1);
              }
            }
          } else {
            iwork_data[c_k] = ialast_tmp;
            q = static_cast<int32_T>(q + 1);
            if (q == qEnd) {
              while (n < ialast) {
                c_k = static_cast<int32_T>(c_k + 1);
                iwork_data[c_k] = bperm_data[static_cast<int32_T>(n - 1)];
                n = static_cast<int32_T>(n + 1);
              }
            }
          }

          c_k = static_cast<int32_T>(c_k + 1);
        }

        for (ialast = 0; ialast <= static_cast<int32_T>(kEnd - 1); ialast =
             static_cast<int32_T>(ialast + 1)) {
          bperm_data[static_cast<int32_T>(static_cast<int32_T>(j + ialast) - 1)]
            = iwork_data[ialast];
        }

        j = qEnd;
        ialast = static_cast<int32_T>(qEnd + i);
      }

      i = i2;
    }
  }

  n = 0;
  i = -1;
  i2 = 0;
  ialast = 1;
  j = 1;
  while ((ialast <= 28) && (j <= *b_size)) {
    qEnd = ialast;
    for (ialast = 0; ialast < 28; ialast++) {
      tmp[ialast] = static_cast<real_T>(ialast) + 1.0;
      iwork_data[ialast] = static_cast<int32_T>(ialast + 1);
    }

    ak = skip_to_last_equal_value_ZlLNIyBv(&qEnd, tmp, iwork_data);
    ialast = qEnd;
    bk = b_data[static_cast<int32_T>(bperm_data[static_cast<int32_T>(j - 1)] - 1)];
    exitg1 = false;
    while ((!exitg1) && (j < *b_size)) {
      b_absx = std::abs(bk / 2.0);
      if (b_absx <= 2.2250738585072014E-308) {
        b_absx = 4.94065645841247E-324;
      } else {
        frexp(b_absx, &b_k);
        b_absx = std::ldexp(1.0, static_cast<int32_T>(b_k - 53));
      }

      if (std::abs(bk - b_data[static_cast<int32_T>(bperm_data[j] - 1)]) <
          b_absx) {
        j = static_cast<int32_T>(j + 1);
      } else {
        exitg1 = true;
      }
    }

    b_absx = std::abs(bk / 2.0);
    if (b_absx <= 2.2250738585072014E-308) {
      b_absx = 4.94065645841247E-324;
    } else {
      frexp(b_absx, &exponent);
      b_absx = std::ldexp(1.0, static_cast<int32_T>(exponent - 53));
    }

    if (std::abs(bk - ak) < b_absx) {
      ialast = static_cast<int32_T>(qEnd + 1);
      i2 = qEnd;
      j = static_cast<int32_T>(j + 1);
    } else if (ak < bk) {
      n = static_cast<int32_T>(n + 1);
      i = static_cast<int32_T>(i + 1);
      ia_data[i] = static_cast<int32_T>(i2 + 1);
      ialast = static_cast<int32_T>(qEnd + 1);
      i2 = qEnd;
    } else {
      j = static_cast<int32_T>(j + 1);
    }
  }

  while (ialast <= 28) {
    b_k = ialast;
    for (ialast = 0; ialast < 28; ialast++) {
      tmp[ialast] = static_cast<real_T>(ialast) + 1.0;
      iwork_data[ialast] = static_cast<int32_T>(ialast + 1);
    }

    skip_to_last_equal_value_ZlLNIyBv(&b_k, tmp, iwork_data);
    n = static_cast<int32_T>(n + 1);
    i = static_cast<int32_T>(i + 1);
    ia_data[i] = static_cast<int32_T>(i2 + 1);
    ialast = static_cast<int32_T>(b_k + 1);
    i2 = b_k;
  }

  if (1 > static_cast<int32_T>(i + 1)) {
    i2 = -1;
  } else {
    i2 = i;
  }

  *ia_size = static_cast<int32_T>(i2 + 1);
  PreemptableMissionModeSelector_sort(ia_data, ia_size, ia_data_0.data,
    &ia_data_0.size);
  for (b_k = 0; b_k <= i; b_k = static_cast<int32_T>(b_k + 1)) {
    c_data[b_k] = static_cast<real_T>(static_cast<int32_T>(ia_data[b_k] - 1)) +
      1.0;
  }

  if (1 > n) {
    c_size[1] = 0;
  } else {
    c_size[1] = n;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_merge_n(int32_T idx_data[], real_T
  x_data[], int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
  xwork_data[])
{
  int32_T exitg1;
  int32_T iout;
  int32_T offset1;
  int32_T p;
  int32_T q;
  if (nq != 0) {
    offset1 = static_cast<int32_T>(np + nq);
    for (p = 0; p <= static_cast<int32_T>(offset1 - 1); p = static_cast<int32_T>
         (p + 1)) {
      q = static_cast<int32_T>(offset + p);
      iwork_data[p] = idx_data[q];
      xwork_data[p] = x_data[q];
    }

    p = 0;
    q = np;
    iout = static_cast<int32_T>(offset - 1);
    do {
      exitg1 = 0;
      iout = static_cast<int32_T>(iout + 1);
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (static_cast<int32_T>(p + 1) < np) {
          p = static_cast<int32_T>(p + 1);
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (static_cast<int32_T>(q + 1) < offset1) {
          q = static_cast<int32_T>(q + 1);
        } else {
          offset1 = static_cast<int32_T>(iout - p);
          while (static_cast<int32_T>(p + 1) <= np) {
            q = static_cast<int32_T>(static_cast<int32_T>(offset1 + p) + 1);
            idx_data[q] = iwork_data[p];
            x_data[q] = xwork_data[p];
            p = static_cast<int32_T>(p + 1);
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_sortIdx(real_T x_data[], int32_T
  *x_size, int32_T idx_data[], int32_T *idx_size)
{
  real_T b_x_data[28];
  real_T xwork_data[28];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T iwork_data[28];
  int32_T b_x_size;
  int32_T i4;
  int32_T ib;
  int32_T n;
  int32_T nPairs;
  int32_T nTail;
  int8_T idx4[4];
  int8_T perm[4];
  *idx_size = static_cast<int32_T>(static_cast<int8_T>(*x_size));
  nPairs = static_cast<int32_T>(static_cast<int8_T>(*x_size));
  for (n = 0; n <= static_cast<int32_T>(nPairs - 1); n++) {
    idx_data[n] = 0;
  }

  if (*x_size != 0) {
    b_x_size = *x_size;
    nPairs = *x_size;
    for (n = 0; n <= static_cast<int32_T>(nPairs - 1); n++) {
      b_x_data[n] = x_data[n];
    }

    *idx_size = static_cast<int32_T>(static_cast<int8_T>(*x_size));
    nPairs = static_cast<int32_T>(static_cast<int8_T>(*x_size));
    for (n = 0; n <= static_cast<int32_T>(nPairs - 1); n++) {
      idx_data[n] = 0;
    }

    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    ib = 0;
    for (nPairs = 0; nPairs <= static_cast<int32_T>(*x_size - 1); nPairs =
         static_cast<int32_T>(nPairs + 1)) {
      ib = static_cast<int32_T>(ib + 1);
      idx4[static_cast<int32_T>(ib - 1)] = static_cast<int8_T>(static_cast<
        int32_T>(nPairs + 1));
      x4[static_cast<int32_T>(ib - 1)] = b_x_data[nPairs];
      if (ib == 4) {
        if (x4[0] <= x4[1]) {
          ib = 1;
          nTail = 2;
        } else {
          ib = 2;
          nTail = 1;
        }

        if (x4[2] <= x4[3]) {
          n = 3;
          i4 = 4;
        } else {
          n = 4;
          i4 = 3;
        }

        tmp = x4[static_cast<int32_T>(ib - 1)];
        tmp_0 = x4[static_cast<int32_T>(n - 1)];
        if (tmp <= tmp_0) {
          tmp = x4[static_cast<int32_T>(nTail - 1)];
          if (tmp <= tmp_0) {
            perm[0] = static_cast<int8_T>(ib);
            perm[1] = static_cast<int8_T>(nTail);
            perm[2] = static_cast<int8_T>(n);
            perm[3] = static_cast<int8_T>(i4);
          } else if (tmp <= x4[static_cast<int32_T>(i4 - 1)]) {
            perm[0] = static_cast<int8_T>(ib);
            perm[1] = static_cast<int8_T>(n);
            perm[2] = static_cast<int8_T>(nTail);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(ib);
            perm[1] = static_cast<int8_T>(n);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(nTail);
          }
        } else {
          tmp_0 = x4[static_cast<int32_T>(i4 - 1)];
          if (tmp <= tmp_0) {
            if (x4[static_cast<int32_T>(nTail - 1)] <= tmp_0) {
              perm[0] = static_cast<int8_T>(n);
              perm[1] = static_cast<int8_T>(ib);
              perm[2] = static_cast<int8_T>(nTail);
              perm[3] = static_cast<int8_T>(i4);
            } else {
              perm[0] = static_cast<int8_T>(n);
              perm[1] = static_cast<int8_T>(ib);
              perm[2] = static_cast<int8_T>(i4);
              perm[3] = static_cast<int8_T>(nTail);
            }
          } else {
            perm[0] = static_cast<int8_T>(n);
            perm[1] = static_cast<int8_T>(i4);
            perm[2] = static_cast<int8_T>(ib);
            perm[3] = static_cast<int8_T>(nTail);
          }
        }

        idx_data[static_cast<int32_T>(nPairs - 3)] = static_cast<int32_T>(idx4[
          static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)]);
        idx_data[static_cast<int32_T>(nPairs - 2)] = static_cast<int32_T>(idx4[
          static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)]);
        idx_data[static_cast<int32_T>(nPairs - 1)] = static_cast<int32_T>(idx4[
          static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)]);
        idx_data[nPairs] = static_cast<int32_T>(idx4[static_cast<int32_T>(
          static_cast<int32_T>(perm[3]) - 1)]);
        b_x_data[static_cast<int32_T>(nPairs - 3)] = x4[static_cast<int32_T>(
          static_cast<int32_T>(perm[0]) - 1)];
        b_x_data[static_cast<int32_T>(nPairs - 2)] = x4[static_cast<int32_T>(
          static_cast<int32_T>(perm[1]) - 1)];
        b_x_data[static_cast<int32_T>(nPairs - 1)] = x4[static_cast<int32_T>(
          static_cast<int32_T>(perm[2]) - 1)];
        b_x_data[nPairs] = x4[static_cast<int32_T>(static_cast<int32_T>(perm[3])
          - 1)];
        ib = 0;
      }
    }

    if (ib > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      switch (ib) {
       case 1:
        perm[0] = 1;
        break;

       case 2:
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
        break;

       default:
        if (x4[0] <= x4[1]) {
          if (x4[1] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 2;
            perm[2] = 3;
          } else if (x4[0] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 3;
            perm[2] = 2;
          } else {
            perm[0] = 3;
            perm[1] = 1;
            perm[2] = 2;
          }
        } else if (x4[0] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 1;
          perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 3;
          perm[2] = 1;
        } else {
          perm[0] = 3;
          perm[1] = 2;
          perm[2] = 1;
        }
        break;
      }

      for (nPairs = 0; nPairs <= static_cast<int32_T>(ib - 1); nPairs =
           static_cast<int32_T>(nPairs + 1)) {
        nTail = static_cast<int32_T>(static_cast<int32_T>(perm[nPairs]) - 1);
        n = static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>(
          static_cast<int32_T>(*x_size - 1) - ib) + nPairs) + 1);
        idx_data[n] = static_cast<int32_T>(idx4[nTail]);
        b_x_data[n] = x4[nTail];
      }
    }

    if (*x_size > 1) {
      nPairs = *x_size;
      for (n = 0; n <= static_cast<int32_T>(nPairs - 1); n++) {
        xwork_data[n] = 0.0;
      }

      nPairs = static_cast<int32_T>(static_cast<int8_T>(*x_size));
      for (n = 0; n <= static_cast<int32_T>(nPairs - 1); n++) {
        iwork_data[n] = 0;
      }

      nPairs = static_cast<int32_T>(*x_size >> 2);
      n = 4;
      while (nPairs > 1) {
        if (static_cast<uint32_T>(static_cast<uint32_T>(nPairs) & 1U) != 0U) {
          nPairs = static_cast<int32_T>(nPairs - 1);
          ib = static_cast<int32_T>(n * nPairs);
          nTail = static_cast<int32_T>(*x_size - ib);
          if (nTail > n) {
            PreemptableMissionModeSelector_merge_n(idx_data, b_x_data, ib, n,
              static_cast<int32_T>(nTail - n), iwork_data, xwork_data);
          }
        }

        ib = static_cast<int32_T>(n << 1);
        nPairs = static_cast<int32_T>(nPairs >> 1);
        for (nTail = 0; nTail <= static_cast<int32_T>(nPairs - 1); nTail =
             static_cast<int32_T>(nTail + 1)) {
          PreemptableMissionModeSelector_merge_n(idx_data, b_x_data,
            static_cast<int32_T>(nTail * ib), n, n, iwork_data, xwork_data);
        }

        n = ib;
      }

      if (*x_size > n) {
        PreemptableMissionModeSelector_merge_n(idx_data, b_x_data, 0, n,
          static_cast<int32_T>(*x_size - n), iwork_data, xwork_data);
      }
    }

    for (n = 0; n <= static_cast<int32_T>(b_x_size - 1); n++) {
      x_data[n] = b_x_data[n];
    }
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_sort_p(real_T x_data[], const int32_T
  *x_size)
{
  emxArray_int32_T_28_PreemptableMissionModeSelector_T vwork_data_0;
  real_T vwork_data[28];
  int32_T b;
  int32_T c_k;
  int32_T dim;
  int32_T vstride;
  int32_T vwork_size;
  dim = 2;
  if (*x_size != 1) {
    dim = 1;
    b = static_cast<int32_T>(*x_size - 1);
  } else {
    b = 0;
  }

  vwork_size = static_cast<int32_T>(b + 1);
  vstride = 1;
  c_k = 0;
  while (c_k <= static_cast<int32_T>(dim - 2)) {
    vstride = static_cast<int32_T>(vstride * *x_size);
    c_k = 1;
  }

  for (dim = 0; dim <= static_cast<int32_T>(vstride - 1); dim =
       static_cast<int32_T>(dim + 1)) {
    for (c_k = 0; c_k <= b; c_k = static_cast<int32_T>(c_k + 1)) {
      vwork_data[c_k] = x_data[static_cast<int32_T>(static_cast<int32_T>(c_k *
        vstride) + dim)];
    }

    PreemptableMissionModeSelector_sortIdx(vwork_data, &vwork_size,
      vwork_data_0.data, &vwork_data_0.size);
    for (c_k = 0; c_k <= b; c_k = static_cast<int32_T>(c_k + 1)) {
      x_data[static_cast<int32_T>(dim + static_cast<int32_T>(c_k * vstride))] =
        vwork_data[c_k];
    }
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void
  PreemptableMissionModeSelector_uavDubinsConnection_findDisabledIndices(real_T
  idx_data[], int32_T *idx_size)
{
  real_T c_data[28];
  real_T ia_data_0[28];
  int32_T ia_data[28];
  int32_T c_size[2];
  int32_T ia_size;
  int32_T ia_size_0;
  int32_T ib_size;
  PreemptableMissionModeSelector_do_vectors(c_data, c_size, ia_data, &ia_size,
    &ib_size);
  ia_size_0 = ia_size;
  for (ib_size = 0; ib_size <= static_cast<int32_T>(ia_size - 1); ib_size++) {
    ia_data_0[ib_size] = static_cast<real_T>(ia_data[ib_size]);
  }

  PreemptableMissionModeSelector_do_vectors_b(ia_data_0, &ia_size_0, c_data,
    c_size, ia_data, &ia_size, &ib_size);
  *idx_size = ia_size;
  for (ib_size = 0; ib_size <= static_cast<int32_T>(ia_size - 1); ib_size++) {
    idx_data[ib_size] = static_cast<real_T>(ia_data[ib_size]);
  }

  PreemptableMissionModeSelector_sort_p(idx_data, idx_size);
  for (ib_size = 0; ib_size <= static_cast<int32_T>(*idx_size - 1); ib_size++) {
    idx_data[ib_size]--;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void
  * PreemptableMissionModeSelector_uavDubinsBuildable_uavDubinsBuildable(real_T
  airSpeed, real_T maxRollAngle, const real_T flightPathAngle[2], const real_T
  disabledPathTypes_data[], const int32_T *disabledPathTypes_size)
{
  real_T b_disabledPathTypes_data[28];
  real_T b_flightPathAngle[2];
  int32_T i;
  int32_T loop_ub;
  b_flightPathAngle[0] = flightPathAngle[0];
  b_flightPathAngle[1] = flightPathAngle[1];
  loop_ub = *disabledPathTypes_size;
  for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
    b_disabledPathTypes_data[i] = disabledPathTypes_data[i];
  }

  return uavDubinsConnectionObj(airSpeed, maxRollAngle, &b_flightPathAngle[0],
    &b_disabledPathTypes_data[0], static_cast<uint32_T>(*disabledPathTypes_size));
}

static void PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
  (emxArray_real_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel)
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
      std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof(real_T) *
        static_cast<uint32_T>(oldNumel)));
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp_m(const char_T a_data[],
  const int32_T a_size[2])
{
  static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~', '\x7f' };

  static const char_T c[2]{ 'H', 'L' };

  int32_T exitg1;
  int32_T kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (b[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
              (a_data[kstr])) & 127)] != b[static_cast<int32_T>(c[kstr])]) {
          exitg1 = 1;
        } else {
          kstr = static_cast<int32_T>(kstr + 1);
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp_m2(const char_T a_data[],
  const int32_T a_size[2])
{
  static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~', '\x7f' };

  static const char_T c[2]{ 'H', 'R' };

  int32_T exitg1;
  int32_T kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (b[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
              (a_data[kstr])) & 127)] != b[static_cast<int32_T>(c[kstr])]) {
          exitg1 = 1;
        } else {
          kstr = static_cast<int32_T>(kstr + 1);
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void
  PreemptableMissionModeSelector_uavDubinsPathSegment_uavDubinsPathSegment_c(
  const real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3,
  real_T varargin_4, real_T varargin_5, real_T varargin_6, const
  cell_wrap_1_PreemptableMissionModeSelector_T varargin_7[4], const real_T
  varargin_8[4], uavDubinsPathSegment_PreemptableMissionModeSelector_T *b_this)
{
  static const char_T d[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A',
    'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
    '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '{', '|', '}',
    '~', '\x7f' };

  real_T thetaWrap;
  int32_T k;
  b_this->MinTurningRadius = varargin_5;
  b_this->StartPose[0] = varargin_1[0];
  b_this->StartPose[1] = varargin_1[1];
  b_this->StartPose[2] = varargin_1[2];
  thetaWrap = mod_dBqh4Vat(varargin_1[3]);
  b_this->StartPose[3] = thetaWrap;
  if ((thetaWrap == 0.0) && (varargin_1[3] > 0.0)) {
    b_this->StartPose[3] = 6.2831853071795862;
  }

  wrapToPi_iEuDNbvh(&b_this->StartPose[3]);
  b_this->GoalPose[0] = varargin_2[0];
  b_this->GoalPose[1] = varargin_2[1];
  b_this->GoalPose[2] = varargin_2[2];
  thetaWrap = mod_dBqh4Vat(varargin_2[3]);
  b_this->GoalPose[3] = thetaWrap;
  if ((thetaWrap == 0.0) && (varargin_2[3] > 0.0)) {
    b_this->GoalPose[3] = 6.2831853071795862;
  }

  wrapToPi_iEuDNbvh(&b_this->GoalPose[3]);
  b_this->AirSpeed = varargin_4;
  b_this->HelixRadius = varargin_6;
  b_this->FlightPathAngle = varargin_3;
  b_this->MotionLengths[0] = varargin_8[0];
  b_this->MotionTypes[0] = varargin_7[0];
  b_this->MotionLengths[1] = varargin_8[1];
  b_this->MotionTypes[1] = varargin_7[1];
  b_this->MotionLengths[2] = varargin_8[2];
  b_this->MotionTypes[2] = varargin_7[2];
  b_this->MotionLengths[3] = varargin_8[3];
  b_this->MotionTypes[3] = varargin_7[3];
  b_this->MotionTypes[0].f1.size[0] = 1;
  b_this->MotionTypes[0].f1.size[1] = varargin_7[0].f1.size[1];
  for (k = 0; k <= static_cast<int32_T>(varargin_7[0].f1.size[1] - 1); k =
       static_cast<int32_T>(k + 1)) {
    b_this->MotionTypes[0].f1.data[k] = d[static_cast<int32_T>(static_cast<
      uint8_T>(varargin_7[0].f1.data[k]))];
  }

  b_this->MotionTypes[1].f1.size[0] = 1;
  b_this->MotionTypes[1].f1.size[1] = 1;
  b_this->MotionTypes[1].f1.data[0] = d[static_cast<int32_T>(static_cast<int32_T>
    (static_cast<uint8_T>(varargin_7[1].f1.data[0])) & 127)];
  b_this->MotionTypes[2].f1.size[0] = 1;
  b_this->MotionTypes[2].f1.size[1] = 1;
  b_this->MotionTypes[2].f1.data[0] = d[static_cast<int32_T>(static_cast<int32_T>
    (static_cast<uint8_T>(varargin_7[2].f1.data[0])) & 127)];
  b_this->MotionTypes[3].f1.size[0] = 1;
  b_this->MotionTypes[3].f1.size[1] = varargin_7[3].f1.size[1];
  for (k = 0; k <= static_cast<int32_T>(varargin_7[3].f1.size[1] - 1); k =
       static_cast<int32_T>(k + 1)) {
    b_this->MotionTypes[3].f1.data[k] = d[static_cast<int32_T>(static_cast<
      uint8_T>(varargin_7[3].f1.data[k]))];
  }

  if (PreemptableMissionModeSelector_strcmp_m(b_this->MotionTypes[0].f1.data,
       b_this->MotionTypes[0].f1.size)) {
    b_this->MotionTypes[0].f1.size[0] = 1;
    b_this->MotionTypes[0].f1.size[1] = 2;
    b_this->MotionTypes[0].f1.data[0] = 'H';
    b_this->MotionTypes[0].f1.data[1] = 'l';
  } else if (PreemptableMissionModeSelector_strcmp_m2(b_this->MotionTypes[0].
              f1.data, b_this->MotionTypes[0].f1.size)) {
    b_this->MotionTypes[0].f1.size[0] = 1;
    b_this->MotionTypes[0].f1.size[1] = 2;
    b_this->MotionTypes[0].f1.data[0] = 'H';
    b_this->MotionTypes[0].f1.data[1] = 'r';
  } else if (PreemptableMissionModeSelector_strcmp_m2(b_this->MotionTypes[3].
              f1.data, b_this->MotionTypes[3].f1.size)) {
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = 2;
    b_this->MotionTypes[3].f1.data[0] = 'H';
    b_this->MotionTypes[3].f1.data[1] = 'r';
  } else if (PreemptableMissionModeSelector_strcmp_m(b_this->MotionTypes[3].
              f1.data, b_this->MotionTypes[3].f1.size)) {
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = 2;
    b_this->MotionTypes[3].f1.data[0] = 'H';
    b_this->MotionTypes[3].f1.data[1] = 'l';
  }

  b_this->Length = ((varargin_8[0] + varargin_8[1]) + varargin_8[2]) +
    varargin_8[3];
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static real_T PreemptableMissionModeSelector_sum(const real_T x_data[])
{
  return ((x_data[0] + x_data[1]) + x_data[2]) + x_data[3];
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_uavDubinsBuiltins_connect(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *obj, const real_T
  startPose[4], const real_T goalPose[4], boolean_T flagOptimal, real_T
  turningRadius, const real_T dpt_data[], const int32_T *dpt_size,
  uavDubinsPathSegment_PreemptableMissionModeSelector_T pathSegObjs_data[],
  int32_T *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
  B_PreemptableMissionModeSelector_c_T *localB)
{
  void* buildableObj_UAVDubinsBuildableObj;
  cell_wrap_1_PreemptableMissionModeSelector_T m[4];
  cell_wrap_1_PreemptableMissionModeSelector_T ac;
  cell_wrap_1_PreemptableMissionModeSelector_T ad;
  cell_wrap_1_PreemptableMissionModeSelector_T ae;
  cell_wrap_1_PreemptableMissionModeSelector_T af;
  cell_wrap_1_PreemptableMissionModeSelector_T bc;
  cell_wrap_1_PreemptableMissionModeSelector_T bd;
  cell_wrap_1_PreemptableMissionModeSelector_T be;
  cell_wrap_1_PreemptableMissionModeSelector_T bf;
  cell_wrap_1_PreemptableMissionModeSelector_T cc;
  cell_wrap_1_PreemptableMissionModeSelector_T cd;
  cell_wrap_1_PreemptableMissionModeSelector_T ce;
  cell_wrap_1_PreemptableMissionModeSelector_T cf;
  cell_wrap_1_PreemptableMissionModeSelector_T dc;
  cell_wrap_1_PreemptableMissionModeSelector_T dd;
  cell_wrap_1_PreemptableMissionModeSelector_T de;
  cell_wrap_1_PreemptableMissionModeSelector_T df;
  cell_wrap_1_PreemptableMissionModeSelector_T ec;
  cell_wrap_1_PreemptableMissionModeSelector_T ed;
  cell_wrap_1_PreemptableMissionModeSelector_T ee;
  cell_wrap_1_PreemptableMissionModeSelector_T ef;
  cell_wrap_1_PreemptableMissionModeSelector_T fc;
  cell_wrap_1_PreemptableMissionModeSelector_T fd;
  cell_wrap_1_PreemptableMissionModeSelector_T fe;
  cell_wrap_1_PreemptableMissionModeSelector_T ff;
  cell_wrap_1_PreemptableMissionModeSelector_T gc;
  cell_wrap_1_PreemptableMissionModeSelector_T gd;
  cell_wrap_1_PreemptableMissionModeSelector_T ge;
  cell_wrap_1_PreemptableMissionModeSelector_T gf;
  cell_wrap_1_PreemptableMissionModeSelector_T hc;
  cell_wrap_1_PreemptableMissionModeSelector_T hd;
  cell_wrap_1_PreemptableMissionModeSelector_T he;
  cell_wrap_1_PreemptableMissionModeSelector_T hf;
  cell_wrap_1_PreemptableMissionModeSelector_T ic;
  cell_wrap_1_PreemptableMissionModeSelector_T id;
  cell_wrap_1_PreemptableMissionModeSelector_T ie;
  cell_wrap_1_PreemptableMissionModeSelector_T jc;
  cell_wrap_1_PreemptableMissionModeSelector_T jd;
  cell_wrap_1_PreemptableMissionModeSelector_T je;
  cell_wrap_1_PreemptableMissionModeSelector_T jf;
  cell_wrap_1_PreemptableMissionModeSelector_T kb;
  cell_wrap_1_PreemptableMissionModeSelector_T kc;
  cell_wrap_1_PreemptableMissionModeSelector_T kd;
  cell_wrap_1_PreemptableMissionModeSelector_T ke;
  cell_wrap_1_PreemptableMissionModeSelector_T kf;
  cell_wrap_1_PreemptableMissionModeSelector_T lb;
  cell_wrap_1_PreemptableMissionModeSelector_T lc;
  cell_wrap_1_PreemptableMissionModeSelector_T ld;
  cell_wrap_1_PreemptableMissionModeSelector_T le;
  cell_wrap_1_PreemptableMissionModeSelector_T lf;
  cell_wrap_1_PreemptableMissionModeSelector_T mb;
  cell_wrap_1_PreemptableMissionModeSelector_T mc;
  cell_wrap_1_PreemptableMissionModeSelector_T md;
  cell_wrap_1_PreemptableMissionModeSelector_T me;
  cell_wrap_1_PreemptableMissionModeSelector_T mf;
  cell_wrap_1_PreemptableMissionModeSelector_T nb;
  cell_wrap_1_PreemptableMissionModeSelector_T nc;
  cell_wrap_1_PreemptableMissionModeSelector_T nd;
  cell_wrap_1_PreemptableMissionModeSelector_T ne;
  cell_wrap_1_PreemptableMissionModeSelector_T nf;
  cell_wrap_1_PreemptableMissionModeSelector_T ob;
  cell_wrap_1_PreemptableMissionModeSelector_T oc;
  cell_wrap_1_PreemptableMissionModeSelector_T od;
  cell_wrap_1_PreemptableMissionModeSelector_T oe;
  cell_wrap_1_PreemptableMissionModeSelector_T of;
  cell_wrap_1_PreemptableMissionModeSelector_T pb;
  cell_wrap_1_PreemptableMissionModeSelector_T pc;
  cell_wrap_1_PreemptableMissionModeSelector_T pd;
  cell_wrap_1_PreemptableMissionModeSelector_T pe;
  cell_wrap_1_PreemptableMissionModeSelector_T pf;
  cell_wrap_1_PreemptableMissionModeSelector_T qb;
  cell_wrap_1_PreemptableMissionModeSelector_T qc;
  cell_wrap_1_PreemptableMissionModeSelector_T qd;
  cell_wrap_1_PreemptableMissionModeSelector_T qe;
  cell_wrap_1_PreemptableMissionModeSelector_T qf;
  cell_wrap_1_PreemptableMissionModeSelector_T rb;
  cell_wrap_1_PreemptableMissionModeSelector_T rc;
  cell_wrap_1_PreemptableMissionModeSelector_T rd;
  cell_wrap_1_PreemptableMissionModeSelector_T re;
  cell_wrap_1_PreemptableMissionModeSelector_T rf;
  cell_wrap_1_PreemptableMissionModeSelector_T sb;
  cell_wrap_1_PreemptableMissionModeSelector_T sc;
  cell_wrap_1_PreemptableMissionModeSelector_T sd;
  cell_wrap_1_PreemptableMissionModeSelector_T se;
  cell_wrap_1_PreemptableMissionModeSelector_T sf;
  cell_wrap_1_PreemptableMissionModeSelector_T tb;
  cell_wrap_1_PreemptableMissionModeSelector_T tc;
  cell_wrap_1_PreemptableMissionModeSelector_T td;
  cell_wrap_1_PreemptableMissionModeSelector_T te;
  cell_wrap_1_PreemptableMissionModeSelector_T tf;
  cell_wrap_1_PreemptableMissionModeSelector_T ub;
  cell_wrap_1_PreemptableMissionModeSelector_T uc;
  cell_wrap_1_PreemptableMissionModeSelector_T ud;
  cell_wrap_1_PreemptableMissionModeSelector_T ue;
  cell_wrap_1_PreemptableMissionModeSelector_T uf;
  cell_wrap_1_PreemptableMissionModeSelector_T vb;
  cell_wrap_1_PreemptableMissionModeSelector_T vc;
  cell_wrap_1_PreemptableMissionModeSelector_T vd;
  cell_wrap_1_PreemptableMissionModeSelector_T ve;
  cell_wrap_1_PreemptableMissionModeSelector_T vf;
  cell_wrap_1_PreemptableMissionModeSelector_T wb;
  cell_wrap_1_PreemptableMissionModeSelector_T wc;
  cell_wrap_1_PreemptableMissionModeSelector_T wd;
  cell_wrap_1_PreemptableMissionModeSelector_T we;
  cell_wrap_1_PreemptableMissionModeSelector_T wf;
  cell_wrap_1_PreemptableMissionModeSelector_T xb;
  cell_wrap_1_PreemptableMissionModeSelector_T xc;
  cell_wrap_1_PreemptableMissionModeSelector_T xd;
  cell_wrap_1_PreemptableMissionModeSelector_T xe;
  cell_wrap_1_PreemptableMissionModeSelector_T yb;
  cell_wrap_1_PreemptableMissionModeSelector_T yc;
  cell_wrap_1_PreemptableMissionModeSelector_T yd;
  cell_wrap_1_PreemptableMissionModeSelector_T ye;
  emxArray_real_T_PreemptableMissionModeSelector_T *g;
  emxArray_real_T_PreemptableMissionModeSelector_T *g1;
  emxArray_real_T_PreemptableMissionModeSelector_T *g_0;
  emxArray_real_T_PreemptableMissionModeSelector_T *ml;
  emxArray_real_T_PreemptableMissionModeSelector_T *ml1;
  emxArray_real_T_PreemptableMissionModeSelector_T *s;
  emxArray_real_T_PreemptableMissionModeSelector_T *s1;
  real_T b_goalPose[4];
  real_T b_startPose[4];
  real_T ml1_0[4];
  real_T ml1_data[4];
  real_T l;
  real_T ml1_tmp;
  int32_T b_nRows;
  int32_T loop_ub;
  int32_T mt;
  int32_T mt_size_idx_0;
  int32_T xf_tmp;
  int16_T tmp[2];
  int16_T num_idx_1;
  kb.f1.size[0] = 1;
  kb.f1.size[1] = 1;
  kb.f1.data[0] = 'L';
  lb.f1.size[0] = 1;
  lb.f1.size[1] = 1;
  lb.f1.data[0] = 'S';
  mb.f1.size[0] = 1;
  mb.f1.size[1] = 1;
  mb.f1.data[0] = 'L';
  nb.f1.size[0] = 1;
  nb.f1.size[1] = 1;
  nb.f1.data[0] = 'N';
  ob.f1.size[0] = 1;
  ob.f1.size[1] = 1;
  ob.f1.data[0] = 'L';
  pb.f1.size[0] = 1;
  pb.f1.size[1] = 1;
  pb.f1.data[0] = 'S';
  qb.f1.size[0] = 1;
  qb.f1.size[1] = 1;
  qb.f1.data[0] = 'R';
  rb.f1.size[0] = 1;
  rb.f1.size[1] = 1;
  rb.f1.data[0] = 'N';
  sb.f1.size[0] = 1;
  sb.f1.size[1] = 1;
  sb.f1.data[0] = 'R';
  tb.f1.size[0] = 1;
  tb.f1.size[1] = 1;
  tb.f1.data[0] = 'S';
  ub.f1.size[0] = 1;
  ub.f1.size[1] = 1;
  ub.f1.data[0] = 'L';
  vb.f1.size[0] = 1;
  vb.f1.size[1] = 1;
  vb.f1.data[0] = 'N';
  wb.f1.size[0] = 1;
  wb.f1.size[1] = 1;
  wb.f1.data[0] = 'R';
  xb.f1.size[0] = 1;
  xb.f1.size[1] = 1;
  xb.f1.data[0] = 'S';
  yb.f1.size[0] = 1;
  yb.f1.size[1] = 1;
  yb.f1.data[0] = 'R';
  ac.f1.size[0] = 1;
  ac.f1.size[1] = 1;
  ac.f1.data[0] = 'N';
  bc.f1.size[0] = 1;
  bc.f1.size[1] = 1;
  bc.f1.data[0] = 'R';
  cc.f1.size[0] = 1;
  cc.f1.size[1] = 1;
  cc.f1.data[0] = 'L';
  dc.f1.size[0] = 1;
  dc.f1.size[1] = 1;
  dc.f1.data[0] = 'R';
  ec.f1.size[0] = 1;
  ec.f1.size[1] = 1;
  ec.f1.data[0] = 'N';
  fc.f1.size[0] = 1;
  fc.f1.size[1] = 1;
  fc.f1.data[0] = 'L';
  gc.f1.size[0] = 1;
  gc.f1.size[1] = 1;
  gc.f1.data[0] = 'R';
  hc.f1.size[0] = 1;
  hc.f1.size[1] = 1;
  hc.f1.data[0] = 'L';
  ic.f1.size[0] = 1;
  ic.f1.size[1] = 1;
  ic.f1.data[0] = 'N';
  jc.f1.size[0] = 1;
  jc.f1.size[1] = 2;
  kc.f1.size[0] = 1;
  kc.f1.size[1] = 1;
  kc.f1.data[0] = 'L';
  lc.f1.size[0] = 1;
  lc.f1.size[1] = 1;
  lc.f1.data[0] = 'S';
  mc.f1.size[0] = 1;
  mc.f1.size[1] = 1;
  mc.f1.data[0] = 'L';
  nc.f1.size[0] = 1;
  nc.f1.size[1] = 2;
  oc.f1.size[0] = 1;
  oc.f1.size[1] = 1;
  oc.f1.data[0] = 'L';
  pc.f1.size[0] = 1;
  pc.f1.size[1] = 1;
  pc.f1.data[0] = 'S';
  qc.f1.size[0] = 1;
  qc.f1.size[1] = 1;
  qc.f1.data[0] = 'R';
  rc.f1.size[0] = 1;
  rc.f1.size[1] = 2;
  sc.f1.size[0] = 1;
  sc.f1.size[1] = 1;
  sc.f1.data[0] = 'R';
  tc.f1.size[0] = 1;
  tc.f1.size[1] = 1;
  tc.f1.data[0] = 'S';
  uc.f1.size[0] = 1;
  uc.f1.size[1] = 1;
  uc.f1.data[0] = 'L';
  vc.f1.size[0] = 1;
  vc.f1.size[1] = 2;
  wc.f1.size[0] = 1;
  wc.f1.size[1] = 1;
  wc.f1.data[0] = 'R';
  xc.f1.size[0] = 1;
  xc.f1.size[1] = 1;
  xc.f1.data[0] = 'S';
  yc.f1.size[0] = 1;
  yc.f1.size[1] = 1;
  yc.f1.data[0] = 'R';
  ad.f1.size[0] = 1;
  ad.f1.size[1] = 2;
  bd.f1.size[0] = 1;
  bd.f1.size[1] = 1;
  bd.f1.data[0] = 'R';
  cd.f1.size[0] = 1;
  cd.f1.size[1] = 1;
  cd.f1.data[0] = 'L';
  dd.f1.size[0] = 1;
  dd.f1.size[1] = 1;
  dd.f1.data[0] = 'R';
  ed.f1.size[0] = 1;
  ed.f1.size[1] = 2;
  fd.f1.size[0] = 1;
  fd.f1.size[1] = 1;
  fd.f1.data[0] = 'L';
  gd.f1.size[0] = 1;
  gd.f1.size[1] = 1;
  gd.f1.data[0] = 'R';
  hd.f1.size[0] = 1;
  hd.f1.size[1] = 1;
  hd.f1.data[0] = 'L';
  id.f1.size[0] = 1;
  id.f1.size[1] = 1;
  id.f1.data[0] = 'L';
  jd.f1.size[0] = 1;
  jd.f1.size[1] = 1;
  jd.f1.data[0] = 'S';
  kd.f1.size[0] = 1;
  kd.f1.size[1] = 1;
  kd.f1.data[0] = 'L';
  ld.f1.size[0] = 1;
  ld.f1.size[1] = 2;
  md.f1.size[0] = 1;
  md.f1.size[1] = 1;
  md.f1.data[0] = 'L';
  nd.f1.size[0] = 1;
  nd.f1.size[1] = 1;
  nd.f1.data[0] = 'S';
  od.f1.size[0] = 1;
  od.f1.size[1] = 1;
  od.f1.data[0] = 'R';
  pd.f1.size[0] = 1;
  pd.f1.size[1] = 2;
  qd.f1.size[0] = 1;
  qd.f1.size[1] = 1;
  qd.f1.data[0] = 'R';
  rd.f1.size[0] = 1;
  rd.f1.size[1] = 1;
  rd.f1.data[0] = 'S';
  sd.f1.size[0] = 1;
  sd.f1.size[1] = 1;
  sd.f1.data[0] = 'L';
  td.f1.size[0] = 1;
  td.f1.size[1] = 2;
  ud.f1.size[0] = 1;
  ud.f1.size[1] = 1;
  ud.f1.data[0] = 'R';
  vd.f1.size[0] = 1;
  vd.f1.size[1] = 1;
  vd.f1.data[0] = 'S';
  wd.f1.size[0] = 1;
  wd.f1.size[1] = 1;
  wd.f1.data[0] = 'R';
  xd.f1.size[0] = 1;
  xd.f1.size[1] = 2;
  yd.f1.size[0] = 1;
  yd.f1.size[1] = 1;
  yd.f1.data[0] = 'R';
  ae.f1.size[0] = 1;
  ae.f1.size[1] = 1;
  ae.f1.data[0] = 'L';
  be.f1.size[0] = 1;
  be.f1.size[1] = 1;
  be.f1.data[0] = 'R';
  ce.f1.size[0] = 1;
  ce.f1.size[1] = 2;
  de.f1.size[0] = 1;
  de.f1.size[1] = 1;
  de.f1.data[0] = 'L';
  ee.f1.size[0] = 1;
  ee.f1.size[1] = 1;
  ee.f1.data[0] = 'R';
  fe.f1.size[0] = 1;
  fe.f1.size[1] = 1;
  fe.f1.data[0] = 'L';
  ge.f1.size[0] = 1;
  ge.f1.size[1] = 2;
  jc.f1.data[0] = 'H';
  nc.f1.data[0] = 'H';
  rc.f1.data[0] = 'H';
  vc.f1.data[0] = 'H';
  ad.f1.data[0] = 'H';
  ed.f1.data[0] = 'H';
  ld.f1.data[0] = 'H';
  pd.f1.data[0] = 'H';
  td.f1.data[0] = 'H';
  xd.f1.data[0] = 'H';
  ce.f1.data[0] = 'H';
  ge.f1.data[0] = 'H';
  jc.f1.data[1] = 'l';
  nc.f1.data[1] = 'l';
  rc.f1.data[1] = 'r';
  vc.f1.data[1] = 'r';
  ad.f1.data[1] = 'r';
  ed.f1.data[1] = 'l';
  ld.f1.data[1] = 'l';
  pd.f1.data[1] = 'r';
  td.f1.data[1] = 'l';
  xd.f1.data[1] = 'r';
  ce.f1.data[1] = 'r';
  ge.f1.data[1] = 'l';
  he.f1.size[0] = 1;
  he.f1.size[1] = 1;
  he.f1.data[0] = 'L';
  ie.f1.size[0] = 1;
  ie.f1.size[1] = 1;
  ie.f1.data[0] = 'R';
  je.f1.size[0] = 1;
  je.f1.size[1] = 1;
  je.f1.data[0] = 'S';
  ke.f1.size[0] = 1;
  ke.f1.size[1] = 1;
  ke.f1.data[0] = 'L';
  le.f1.size[0] = 1;
  le.f1.size[1] = 1;
  le.f1.data[0] = 'L';
  me.f1.size[0] = 1;
  me.f1.size[1] = 1;
  me.f1.data[0] = 'R';
  ne.f1.size[0] = 1;
  ne.f1.size[1] = 1;
  ne.f1.data[0] = 'S';
  oe.f1.size[0] = 1;
  oe.f1.size[1] = 1;
  oe.f1.data[0] = 'R';
  pe.f1.size[0] = 1;
  pe.f1.size[1] = 1;
  pe.f1.data[0] = 'L';
  qe.f1.size[0] = 1;
  qe.f1.size[1] = 1;
  qe.f1.data[0] = 'R';
  re.f1.size[0] = 1;
  re.f1.size[1] = 1;
  re.f1.data[0] = 'L';
  se.f1.size[0] = 1;
  se.f1.size[1] = 1;
  se.f1.data[0] = 'R';
  te.f1.size[0] = 1;
  te.f1.size[1] = 1;
  te.f1.data[0] = 'R';
  ue.f1.size[0] = 1;
  ue.f1.size[1] = 1;
  ue.f1.data[0] = 'L';
  ve.f1.size[0] = 1;
  ve.f1.size[1] = 1;
  ve.f1.data[0] = 'S';
  we.f1.size[0] = 1;
  we.f1.size[1] = 1;
  we.f1.data[0] = 'R';
  xe.f1.size[0] = 1;
  xe.f1.size[1] = 1;
  xe.f1.data[0] = 'R';
  ye.f1.size[0] = 1;
  ye.f1.size[1] = 1;
  ye.f1.data[0] = 'L';
  af.f1.size[0] = 1;
  af.f1.size[1] = 1;
  af.f1.data[0] = 'R';
  bf.f1.size[0] = 1;
  bf.f1.size[1] = 1;
  bf.f1.data[0] = 'L';
  cf.f1.size[0] = 1;
  cf.f1.size[1] = 1;
  cf.f1.data[0] = 'R';
  df.f1.size[0] = 1;
  df.f1.size[1] = 1;
  df.f1.data[0] = 'L';
  ef.f1.size[0] = 1;
  ef.f1.size[1] = 1;
  ef.f1.data[0] = 'S';
  ff.f1.size[0] = 1;
  ff.f1.size[1] = 1;
  ff.f1.data[0] = 'L';
  gf.f1.size[0] = 1;
  gf.f1.size[1] = 1;
  gf.f1.data[0] = 'L';
  hf.f1.size[0] = 1;
  hf.f1.size[1] = 1;
  hf.f1.data[0] = 'S';
  jf.f1.size[0] = 1;
  jf.f1.size[1] = 1;
  jf.f1.data[0] = 'R';
  kf.f1.size[0] = 1;
  kf.f1.size[1] = 1;
  kf.f1.data[0] = 'L';
  lf.f1.size[0] = 1;
  lf.f1.size[1] = 1;
  lf.f1.data[0] = 'R';
  mf.f1.size[0] = 1;
  mf.f1.size[1] = 1;
  mf.f1.data[0] = 'S';
  nf.f1.size[0] = 1;
  nf.f1.size[1] = 1;
  nf.f1.data[0] = 'R';
  of.f1.size[0] = 1;
  of.f1.size[1] = 1;
  of.f1.data[0] = 'L';
  pf.f1.size[0] = 1;
  pf.f1.size[1] = 1;
  pf.f1.data[0] = 'L';
  qf.f1.size[0] = 1;
  qf.f1.size[1] = 1;
  qf.f1.data[0] = 'S';
  rf.f1.size[0] = 1;
  rf.f1.size[1] = 1;
  rf.f1.data[0] = 'L';
  sf.f1.size[0] = 1;
  sf.f1.size[1] = 1;
  sf.f1.data[0] = 'R';
  tf.f1.size[0] = 1;
  tf.f1.size[1] = 1;
  tf.f1.data[0] = 'R';
  uf.f1.size[0] = 1;
  uf.f1.size[1] = 1;
  uf.f1.data[0] = 'S';
  vf.f1.size[0] = 1;
  vf.f1.size[1] = 1;
  vf.f1.data[0] = 'L';
  wf.f1.size[0] = 1;
  wf.f1.size[1] = 1;
  wf.f1.data[0] = 'R';
  buildableObj_UAVDubinsBuildableObj =
    PreemptableMissionModeSelector_uavDubinsBuildable_uavDubinsBuildable
    (obj->AirSpeed, obj->MaxRollAngle, obj->FlightPathAngleLimit, dpt_data,
     dpt_size);
  b_startPose[0] = startPose[0];
  b_goalPose[0] = goalPose[0];
  b_startPose[1] = startPose[1];
  b_goalPose[1] = goalPose[1];
  b_startPose[2] = startPose[2];
  b_goalPose[2] = goalPose[2];
  b_startPose[3] = startPose[3];
  b_goalPose[3] = goalPose[3];
  b_nRows = 1;
  if (!flagOptimal) {
    b_nRows = 28;
  }

  PreemptableMissionModeSelector_emxInit_real_T_h(&s, 2);
  PreemptableMissionModeSelector_emxInit_real_T_h(&g, 2);
  PreemptableMissionModeSelector_emxInit_real_T_h(&ml, 2);
  xf_tmp = static_cast<int32_T>(b_nRows << 2);
  mt = static_cast<int32_T>(s->size[0] * s->size[1]);
  s->size[0] = xf_tmp;
  s->size[1] = xf_tmp;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(s, mt);
  mt = static_cast<int32_T>(g->size[0] * g->size[1]);
  g->size[0] = xf_tmp;
  g->size[1] = xf_tmp;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g, mt);
  mt_size_idx_0 = b_nRows;
  mt = static_cast<int32_T>(ml->size[0] * ml->size[1]);
  ml->size[0] = xf_tmp;
  ml->size[1] = xf_tmp;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ml, mt);
  uavDubinsDistanceCodegen_real64(buildableObj_UAVDubinsBuildableObj,
    &b_startPose[0], 1U, &b_goalPose[0], 1U, flagOptimal, turningRadius,
    &s->data[0], &g->data[0], &localB->b_fpa_data[0], &localB->b_a_data[0],
    &localB->mtr_data[0], &localB->h_data[0], &localB->mt_data[0], &ml->data[0]);
  b_nRows = 0;
  if (!flagOptimal) {
    b_nRows = 27;
  }

  PreemptableMissionModeSelector_emxInit_real_T_h(&g1, 2);
  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
    static_cast<int32_T>(s->size[0] * s->size[1])) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = static_cast<int32_T>(g1->size[0] * g1->size[1]);
  g1->size[0] = static_cast<int32_T>(num_idx_1);
  g1->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g1, mt);
  loop_ub = static_cast<int32_T>(num_idx_1);
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt <= static_cast<int32_T>(loop_ub - 1); mt++) {
      g1->data[static_cast<int32_T>(mt + static_cast<int32_T>(g1->size[0] *
        xf_tmp))] = s->data[static_cast<int32_T>(xf_tmp + static_cast<int32_T>(
        static_cast<int32_T>(tmp[0]) * mt))];
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&s);
  PreemptableMissionModeSelector_emxInit_real_T_h(&s1, 2);
  mt = static_cast<int32_T>(s1->size[0] * s1->size[1]);
  s1->size[0] = static_cast<int32_T>(num_idx_1);
  s1->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(s1, mt);
  loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
  for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
    s1->data[xf_tmp] = g1->data[xf_tmp];
  }

  PreemptableMissionModeSelector_emxInit_real_T_h(&g_0, 2);
  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
    static_cast<int32_T>(g->size[0] * g->size[1])) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
  g_0->size[0] = static_cast<int32_T>(num_idx_1);
  g_0->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g_0, mt);
  loop_ub = static_cast<int32_T>(num_idx_1);
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt <= static_cast<int32_T>(loop_ub - 1); mt++) {
      g_0->data[static_cast<int32_T>(mt + static_cast<int32_T>(g_0->size[0] *
        xf_tmp))] = g->data[static_cast<int32_T>(xf_tmp + static_cast<int32_T>(
        static_cast<int32_T>(tmp[0]) * mt))];
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&g);
  mt = static_cast<int32_T>(g1->size[0] * g1->size[1]);
  g1->size[0] = static_cast<int32_T>(num_idx_1);
  g1->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g1, mt);
  loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
  for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
    g1->data[xf_tmp] = g_0->data[xf_tmp];
  }

  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
    static_cast<int32_T>(ml->size[0] * ml->size[1])) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
  g_0->size[0] = static_cast<int32_T>(num_idx_1);
  g_0->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g_0, mt);
  loop_ub = static_cast<int32_T>(num_idx_1);
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt <= static_cast<int32_T>(loop_ub - 1); mt++) {
      g_0->data[static_cast<int32_T>(mt + static_cast<int32_T>(g_0->size[0] *
        xf_tmp))] = ml->data[static_cast<int32_T>(xf_tmp + static_cast<int32_T>(
        static_cast<int32_T>(tmp[0]) * mt))];
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&ml);
  PreemptableMissionModeSelector_emxInit_real_T_h(&ml1, 2);
  mt = static_cast<int32_T>(ml1->size[0] * ml1->size[1]);
  ml1->size[0] = static_cast<int32_T>(num_idx_1);
  ml1->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ml1, mt);
  loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
  for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
    ml1->data[xf_tmp] = g_0->data[xf_tmp];
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&g_0);
  loop_ub = static_cast<int32_T>(mt_size_idx_0 * mt_size_idx_0);
  for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
    localB->mt_data[xf_tmp]++;
  }

  l = 0.0;
  *pathCosts_size = static_cast<int32_T>(b_nRows + 1);
  for (xf_tmp = 0; xf_tmp <= b_nRows; xf_tmp++) {
    pathCosts_data[xf_tmp] = (rtNaN);
  }

  m[0] = kb;
  m[1] = lb;
  m[2] = mb;
  m[3] = nb;
  if (flagOptimal) {
    *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>
      (static_cast<int32_T>(b_nRows + 1)));
    for (xf_tmp = 0; xf_tmp <= b_nRows; xf_tmp = static_cast<int32_T>(xf_tmp + 1))
    {
      l++;
      ml1_tmp = localB->mt_data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      if (ml1_tmp == 1.0) {
        m[0] = kb;
        m[1] = lb;
        m[2] = mb;
        m[3] = nb;
      }

      if (ml1_tmp == 2.0) {
        m[0] = ob;
        m[1] = pb;
        m[2] = qb;
        m[3] = rb;
      }

      if (ml1_tmp == 3.0) {
        m[0] = sb;
        m[1] = tb;
        m[2] = ub;
        m[3] = vb;
      }

      if (ml1_tmp == 4.0) {
        m[0] = wb;
        m[1] = xb;
        m[2] = yb;
        m[3] = ac;
      }

      if (ml1_tmp == 5.0) {
        m[0] = bc;
        m[1] = cc;
        m[2] = dc;
        m[3] = ec;
      }

      if (ml1_tmp == 6.0) {
        m[0] = fc;
        m[1] = gc;
        m[2] = hc;
        m[3] = ic;
      }

      if (ml1_tmp == 7.0) {
        m[0] = jc;
        m[1] = kc;
        m[2] = lc;
        m[3] = mc;
      }

      if (ml1_tmp == 8.0) {
        m[0] = nc;
        m[1] = oc;
        m[2] = pc;
        m[3] = qc;
      }

      if (ml1_tmp == 9.0) {
        m[0] = rc;
        m[1] = sc;
        m[2] = tc;
        m[3] = uc;
      }

      if (ml1_tmp == 10.0) {
        m[0] = vc;
        m[1] = wc;
        m[2] = xc;
        m[3] = yc;
      }

      if (ml1_tmp == 11.0) {
        m[0] = ad;
        m[1] = bd;
        m[2] = cd;
        m[3] = dd;
      }

      if (ml1_tmp == 12.0) {
        m[0] = ed;
        m[1] = fd;
        m[2] = gd;
        m[3] = hd;
      }

      if (ml1_tmp == 13.0) {
        m[0] = id;
        m[1] = jd;
        m[2] = kd;
        m[3] = ld;
      }

      if (ml1_tmp == 14.0) {
        m[0] = md;
        m[1] = nd;
        m[2] = od;
        m[3] = pd;
      }

      if (ml1_tmp == 15.0) {
        m[0] = qd;
        m[1] = rd;
        m[2] = sd;
        m[3] = td;
      }

      if (ml1_tmp == 16.0) {
        m[0] = ud;
        m[1] = vd;
        m[2] = wd;
        m[3] = xd;
      }

      if (ml1_tmp == 17.0) {
        m[0] = yd;
        m[1] = ae;
        m[2] = be;
        m[3] = ce;
      }

      if (ml1_tmp == 18.0) {
        m[0] = de;
        m[1] = ee;
        m[2] = fe;
        m[3] = ge;
      }

      if (ml1_tmp == 19.0) {
        m[0] = he;
        m[1] = ie;
        m[2] = je;
        m[3] = ke;
      }

      if (ml1_tmp == 20.0) {
        m[0] = le;
        m[1] = me;
        m[2] = ne;
        m[3] = oe;
      }

      if (ml1_tmp == 21.0) {
        m[0] = pe;
        m[1] = qe;
        m[2] = re;
        m[3] = se;
      }

      if (ml1_tmp == 22.0) {
        m[0] = te;
        m[1] = ue;
        m[2] = ve;
        m[3] = we;
      }

      if (ml1_tmp == 23.0) {
        m[0] = xe;
        m[1] = ye;
        m[2] = af;
        m[3] = bf;
      }

      if (ml1_tmp == 24.0) {
        m[0] = cf;
        m[1] = df;
        m[2] = ef;
        m[3] = ff;
      }

      if (ml1_tmp == 25.0) {
        m[0] = gf;
        m[1] = hf;
        m[2] = jf;
        m[3] = kf;
      }

      if (ml1_tmp == 26.0) {
        m[0] = lf;
        m[1] = mf;
        m[2] = nf;
        m[3] = of;
      }

      if (ml1_tmp == 27.0) {
        m[0] = pf;
        m[1] = qf;
        m[2] = rf;
        m[3] = sf;
      }

      if (ml1_tmp == 28.0) {
        m[0] = tf;
        m[1] = uf;
        m[2] = vf;
        m[3] = wf;
      }

      b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      ml1_0[0] = ml1_tmp;
      ml1_data[0] = ml1_tmp;
      b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + s1->size[0]) - 1)];
      b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + g1->size[0]) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
        int32_T>(l) + ml1->size[0]) - 1)];
      ml1_0[1] = ml1_tmp;
      ml1_data[1] = ml1_tmp;
      b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1)) - 1)];
      b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1)) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>
        (static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1)) - 1)];
      ml1_0[2] = ml1_tmp;
      ml1_data[2] = ml1_tmp;
      b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3)) - 1)];
      b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3)) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
        int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3)) - 1)];
      ml1_0[3] = ml1_tmp;
      ml1_data[3] = ml1_tmp;
      PreemptableMissionModeSelector_uavDubinsPathSegment_uavDubinsPathSegment_c
        (b_startPose, b_goalPose, localB->b_fpa_data[static_cast<int32_T>(
          static_cast<int32_T>(l) - 1)], localB->b_a_data[0], localB->mtr_data[0],
         localB->h_data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)], m,
         ml1_0, &pathSegObjs_data[xf_tmp]);
      pathCosts_data[xf_tmp] = PreemptableMissionModeSelector_sum(ml1_data);
    }
  } else {
    *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>
      (static_cast<int32_T>(b_nRows + 1)));
    for (xf_tmp = 1; static_cast<int32_T>(xf_tmp - 1) <= b_nRows; xf_tmp =
         static_cast<int32_T>(xf_tmp + 1)) {
      l++;
      if (1 == xf_tmp) {
        m[0] = kb;
        m[1] = lb;
        m[2] = mb;
        m[3] = nb;
      }

      if (2 == xf_tmp) {
        m[0] = ob;
        m[1] = pb;
        m[2] = qb;
        m[3] = rb;
      }

      if (3 == xf_tmp) {
        m[0] = sb;
        m[1] = tb;
        m[2] = ub;
        m[3] = vb;
      }

      if (4 == xf_tmp) {
        m[0] = wb;
        m[1] = xb;
        m[2] = yb;
        m[3] = ac;
      }

      if (5 == xf_tmp) {
        m[0] = bc;
        m[1] = cc;
        m[2] = dc;
        m[3] = ec;
      }

      if (6 == xf_tmp) {
        m[0] = fc;
        m[1] = gc;
        m[2] = hc;
        m[3] = ic;
      }

      if (7 == xf_tmp) {
        m[0] = jc;
        m[1] = kc;
        m[2] = lc;
        m[3] = mc;
      }

      if (8 == xf_tmp) {
        m[0] = nc;
        m[1] = oc;
        m[2] = pc;
        m[3] = qc;
      }

      if (9 == xf_tmp) {
        m[0] = rc;
        m[1] = sc;
        m[2] = tc;
        m[3] = uc;
      }

      if (10 == xf_tmp) {
        m[0] = vc;
        m[1] = wc;
        m[2] = xc;
        m[3] = yc;
      }

      if (11 == xf_tmp) {
        m[0] = ad;
        m[1] = bd;
        m[2] = cd;
        m[3] = dd;
      }

      if (12 == xf_tmp) {
        m[0] = ed;
        m[1] = fd;
        m[2] = gd;
        m[3] = hd;
      }

      if (13 == xf_tmp) {
        m[0] = id;
        m[1] = jd;
        m[2] = kd;
        m[3] = ld;
      }

      if (14 == xf_tmp) {
        m[0] = md;
        m[1] = nd;
        m[2] = od;
        m[3] = pd;
      }

      if (15 == xf_tmp) {
        m[0] = qd;
        m[1] = rd;
        m[2] = sd;
        m[3] = td;
      }

      if (16 == xf_tmp) {
        m[0] = ud;
        m[1] = vd;
        m[2] = wd;
        m[3] = xd;
      }

      if (17 == xf_tmp) {
        m[0] = yd;
        m[1] = ae;
        m[2] = be;
        m[3] = ce;
      }

      if (18 == xf_tmp) {
        m[0] = de;
        m[1] = ee;
        m[2] = fe;
        m[3] = ge;
      }

      if (19 == xf_tmp) {
        m[0] = he;
        m[1] = ie;
        m[2] = je;
        m[3] = ke;
      }

      if (20 == xf_tmp) {
        m[0] = le;
        m[1] = me;
        m[2] = ne;
        m[3] = oe;
      }

      if (21 == xf_tmp) {
        m[0] = pe;
        m[1] = qe;
        m[2] = re;
        m[3] = se;
      }

      if (22 == xf_tmp) {
        m[0] = te;
        m[1] = ue;
        m[2] = ve;
        m[3] = we;
      }

      if (23 == xf_tmp) {
        m[0] = xe;
        m[1] = ye;
        m[2] = af;
        m[3] = bf;
      }

      if (24 == xf_tmp) {
        m[0] = cf;
        m[1] = df;
        m[2] = ef;
        m[3] = ff;
      }

      if (25 == xf_tmp) {
        m[0] = gf;
        m[1] = hf;
        m[2] = jf;
        m[3] = kf;
      }

      if (26 == xf_tmp) {
        m[0] = lf;
        m[1] = mf;
        m[2] = nf;
        m[3] = of;
      }

      if (27 == xf_tmp) {
        m[0] = pf;
        m[1] = qf;
        m[2] = rf;
        m[3] = sf;
      }

      if (28 == xf_tmp) {
        m[0] = tf;
        m[1] = uf;
        m[2] = vf;
        m[3] = wf;
      }

      b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      ml1_0[0] = ml1_tmp;
      ml1_data[0] = ml1_tmp;
      b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + s1->size[0]) - 1)];
      b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + g1->size[0]) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
        int32_T>(l) + ml1->size[0]) - 1)];
      ml1_0[1] = ml1_tmp;
      ml1_data[1] = ml1_tmp;
      b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1)) - 1)];
      b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1)) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>
        (static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1)) - 1)];
      ml1_0[2] = ml1_tmp;
      ml1_data[2] = ml1_tmp;
      b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3)) - 1)];
      b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3)) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
        int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3)) - 1)];
      ml1_0[3] = ml1_tmp;
      ml1_data[3] = ml1_tmp;
      PreemptableMissionModeSelector_uavDubinsPathSegment_uavDubinsPathSegment_c
        (b_startPose, b_goalPose, localB->b_fpa_data[static_cast<int32_T>(
          static_cast<int32_T>(l) - 1)], localB->b_a_data[0], localB->mtr_data[0],
         localB->h_data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)], m,
         ml1_0, &pathSegObjs_data[static_cast<int32_T>(xf_tmp - 1)]);
      pathCosts_data[static_cast<int32_T>(xf_tmp - 1)] =
        PreemptableMissionModeSelector_sum(ml1_data);
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&ml1);
  PreemptableMissionModeSelector_emxFree_real_T_n(&g1);
  PreemptableMissionModeSelector_emxFree_real_T_n(&s1);
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_uavDubinsConnection_connect(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *obj, const real_T
  startPoses[4], const real_T goalPoses[4],
  uavDubinsPathSegment_PreemptableMissionModeSelector_T pathSegObjs_data[],
  int32_T *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
  B_PreemptableMissionModeSelector_c_T *localB)
{
  matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
    parser;
  real_T idx_data[28];
  int32_T tmp_size[2];
  int32_T flagOptimal;
  int32_T idx_size;
  char_T tmp_data[7];
  PreemptableMissionModeSelector_NameValueParser_NameValueParser(&parser);
  parser.ParsedResults = parser.Defaults;
  flagOptimal = 1;
  PreemptableMissionModeSelector_validatestring(parser.ParsedResults.f1,
    tmp_data, tmp_size);
  if (PreemptableMissionModeSelector_strcmp(tmp_data, tmp_size)) {
    flagOptimal = 0;
  }

  PreemptableMissionModeSelector_uavDubinsConnection_findDisabledIndices
    (idx_data, &idx_size);
  PreemptableMissionModeSelector_uavDubinsBuiltins_connect(obj, startPoses,
    goalPoses, flagOptimal == 1, obj->MinTurningRadius, idx_data, &idx_size,
    pathSegObjs_data, pathSegObjs_size, pathCosts_data, pathCosts_size, localB);
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_strcmp_m2j(const
  cell_wrap_1_PreemptableMissionModeSelector_T a[4], boolean_T b_bool[4])
{
  b_bool[0] = false;
  if ((a[0].f1.size[1] == 1) && (!(a[0].f1.data[0] != 'N'))) {
    b_bool[0] = true;
  }

  b_bool[1] = false;
  if ((a[1].f1.size[1] == 1) && (!(a[1].f1.data[0] != 'N'))) {
    b_bool[1] = true;
  }

  b_bool[2] = false;
  if ((a[2].f1.size[1] == 1) && (!(a[2].f1.data[0] != 'N'))) {
    b_bool[2] = true;
  }

  b_bool[3] = false;
  if ((a[3].f1.size[1] == 1) && (!(a[3].f1.data[0] != 'N'))) {
    b_bool[3] = true;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_any(const boolean_T x[4])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (!x[k]) {
      k = static_cast<int32_T>(k + 1);
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_useConstantDim(const real_T
  varargin_2_data[], const int32_T varargin_2_size[2], real_T varargout_1_data[],
  int32_T varargout_1_size[2])
{
  int32_T loop_ub;
  int32_T varargout_1_data_tmp;
  varargout_1_size[0] = 1;
  varargout_1_size[1] = varargin_2_size[1];
  loop_ub = static_cast<int32_T>(varargin_2_size[1] - 1);
  for (varargout_1_data_tmp = 0; varargout_1_data_tmp <= loop_ub;
       varargout_1_data_tmp++) {
    varargout_1_data[varargout_1_data_tmp] =
      varargin_2_data[varargout_1_data_tmp];
  }

  for (loop_ub = 0; loop_ub <= static_cast<int32_T>(varargin_2_size[1] - 2);
       loop_ub = static_cast<int32_T>(loop_ub + 1)) {
    varargout_1_data[static_cast<int32_T>(loop_ub + 1)] +=
      varargout_1_data[loop_ub];
  }
}

static void PreemptableMissionModeSelector_emxInit_real_T1
  (emxArray_real_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_real_T_PreemptableMissionModeSelector_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_PreemptableMissionModeSelector_T *)std::malloc
    (sizeof(emxArray_real_T_PreemptableMissionModeSelector_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T) *
    static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
    emxArray->size[i] = 0;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_eml_find(boolean_T x, int32_T i_data[],
  int32_T i_size[2])
{
  if (x) {
    i_size[0] = 1;
    i_size[1] = 1;
    i_data[0] = 1;
  } else {
    i_size[0] = 0;
    i_size[1] = 0;
  }
}

static void PreemptableMissionModeSelector_emxEnsureCapacity_real_T1
  (emxArray_real_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel)
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
      std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof(real_T) *
        static_cast<uint32_T>(oldNumel)));
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp_m2ju(const char_T a_data[],
  const int32_T a_size[2])
{
  boolean_T b_bool;
  b_bool = false;
  if ((a_size[1] == 1) && (!(a_data[0] != 'N'))) {
    b_bool = true;
  }

  return b_bool;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp_m2juc(const char_T
  a_data[], const int32_T a_size[2])
{
  static const char_T b[2]{ 'H', 'l' };

  int32_T exitg1;
  int32_T kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (a_data[kstr] != b[kstr]) {
          exitg1 = 1;
        } else {
          kstr = static_cast<int32_T>(kstr + 1);
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static void PreemptableMissionModeSelector_emxInit_boolean_T1
  (emxArray_boolean_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_boolean_T_PreemptableMissionModeSelector_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_PreemptableMissionModeSelector_T *)std::
    malloc(sizeof(emxArray_boolean_T_PreemptableMissionModeSelector_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T) *
    static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
    emxArray->size[i] = 0;
  }
}

static void PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T1
  (emxArray_boolean_T_PreemptableMissionModeSelector_T *emxArray, int32_T
   oldNumel)
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

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(boolean_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
        (boolean_T) * static_cast<uint32_T>(oldNumel)));
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void PreemptableMissionModeSelector_emxFree_boolean_T
  (emxArray_boolean_T_PreemptableMissionModeSelector_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T_PreemptableMissionModeSelector_T *)
      nullptr) {
    if (((*pEmxArray)->data != (boolean_T *)nullptr) && (*pEmxArray)
        ->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T_PreemptableMissionModeSelector_T *)nullptr;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_wrapToPi
  (emxArray_real_T_PreemptableMissionModeSelector_T *theta)
{
  emxArray_boolean_T_PreemptableMissionModeSelector_T *x;
  emxArray_real_T_PreemptableMissionModeSelector_T *y;
  int32_T b_k;
  int32_T loop_ub;
  boolean_T b_y;
  boolean_T exitg1;
  PreemptableMissionModeSelector_emxInit_real_T1(&y, 1);
  b_k = y->size[0];
  y->size[0] = theta->size[0];
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(y, b_k);
  for (b_k = 0; b_k <= static_cast<int32_T>(theta->size[0] - 1); b_k =
       static_cast<int32_T>(b_k + 1)) {
    y->data[b_k] = std::abs(theta->data[b_k]);
  }

  PreemptableMissionModeSelector_emxInit_boolean_T1(&x, 1);
  b_k = x->size[0];
  x->size[0] = y->size[0];
  PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T1(x, b_k);
  loop_ub = y->size[0];
  for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
    x->data[b_k] = (y->data[b_k] > 3.1415926535897931);
  }

  b_y = false;
  b_k = 1;
  exitg1 = false;
  while ((!exitg1) && (b_k <= x->size[0])) {
    if (!x->data[static_cast<int32_T>(b_k - 1)]) {
      b_k = static_cast<int32_T>(b_k + 1);
    } else {
      b_y = true;
      exitg1 = true;
    }
  }

  if (b_y) {
    b_k = y->size[0];
    y->size[0] = theta->size[0];
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(y, b_k);
    loop_ub = theta->size[0];
    for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
      y->data[b_k] = theta->data[b_k] + 3.1415926535897931;
    }

    b_k = theta->size[0];
    theta->size[0] = y->size[0];
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(theta, b_k);
    for (b_k = 0; b_k <= static_cast<int32_T>(y->size[0] - 1); b_k =
         static_cast<int32_T>(b_k + 1)) {
      theta->data[b_k] = mod_dBqh4Vat(y->data[b_k]);
    }

    b_k = x->size[0];
    x->size[0] = theta->size[0];
    PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T1(x, b_k);
    loop_ub = theta->size[0];
    for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
      x->data[b_k] = (theta->data[b_k] == 0.0);
    }

    for (b_k = 0; b_k <= static_cast<int32_T>(x->size[0] - 1); b_k =
         static_cast<int32_T>(b_k + 1)) {
      if (x->data[b_k] && (y->data[b_k] > 0.0)) {
        theta->data[b_k] = 6.2831853071795862;
      }
    }

    loop_ub = theta->size[0];
    for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
      theta->data[b_k] -= 3.1415926535897931;
    }
  }

  PreemptableMissionModeSelector_emxFree_boolean_T(&x);
  PreemptableMissionModeSelector_emxFree_real_T_n(&y);
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp_m2jucf(const char_T
  a_data[], const int32_T a_size[2])
{
  static const char_T b[2]{ 'H', 'r' };

  int32_T exitg1;
  int32_T kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (a_data[kstr] != b[kstr]) {
          exitg1 = 1;
        } else {
          kstr = static_cast<int32_T>(kstr + 1);
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp_m2jucfm(const char_T
  a_data[], const int32_T a_size[2])
{
  boolean_T b_bool;
  b_bool = false;
  if ((a_size[1] == 1) && (!(a_data[0] != 'L'))) {
    b_bool = true;
  }

  return b_bool;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp_m2jucfmm(const char_T
  a_data[], const int32_T a_size[2])
{
  boolean_T b_bool;
  b_bool = false;
  if ((a_size[1] == 1) && (!(a_data[0] != 'R'))) {
    b_bool = true;
  }

  return b_bool;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static boolean_T PreemptableMissionModeSelector_strcmp_m2jucfmmw(const char_T
  a_data[], const int32_T a_size[2])
{
  boolean_T b_bool;
  b_bool = false;
  if ((a_size[1] == 1) && (!(a_data[0] != 'S'))) {
    b_bool = true;
  }

  return b_bool;
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_mtimes(const
  emxArray_real_T_PreemptableMissionModeSelector_T *A, const real_T B[4],
  emxArray_real_T_PreemptableMissionModeSelector_T *C)
{
  int32_T i;
  int32_T m;
  m = A->size[0];
  i = static_cast<int32_T>(C->size[0] * C->size[1]);
  C->size[0] = A->size[0];
  C->size[1] = 2;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(C, i);
  for (i = 0; i <= static_cast<int32_T>(m - 1); i = static_cast<int32_T>(i + 1))
  {
    C->data[i] = A->data[i] * B[0] + A->data[static_cast<int32_T>(A->size[0] + i)]
      * B[1];
  }

  for (i = 0; i <= static_cast<int32_T>(m - 1); i = static_cast<int32_T>(i + 1))
  {
    C->data[static_cast<int32_T>(m + i)] = A->data[i] * B[2] + A->data[
      static_cast<int32_T>(A->size[0] + i)] * B[3];
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate(
  const real_T b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_1_PreemptableMissionModeSelector_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, real_T samples, real_T poses_data[], int32_T poses_size[2])
{
  emxArray_real_T_PreemptableMissionModeSelector_T *S;
  emxArray_real_T_PreemptableMissionModeSelector_T *b_y;
  emxArray_real_T_PreemptableMissionModeSelector_T *c_x;
  emxArray_real_T_PreemptableMissionModeSelector_T *d_x;
  emxArray_real_T_PreemptableMissionModeSelector_T *y;
  real_T ns_data[12];
  real_T state[6];
  real_T TransformMatrix[4];
  real_T tempMotionLength_data[4];
  real_T x_data[4];
  real_T S_data[2];
  real_T tempSamples_data[2];
  real_T z_data[2];
  real_T TransformMatrix_tmp;
  real_T TransformMatrix_tmp_0;
  real_T d_b;
  real_T intermediateLength;
  real_T radius;
  real_T samples_tmp;
  real_T state_0;
  real_T tempStartPose_idx_2;
  int32_T tempMotionLength_size[2];
  int32_T x_size[2];
  int32_T count;
  int32_T loop_ub;
  int32_T ns_size_idx_0;
  int32_T o_data;
  int32_T tempMotionLength_data_tmp;
  int32_T tempSamples_size_idx_0;
  boolean_T tmp[4];
  boolean_T tempSamplesIndex;
  poses_size[0] = 0;
  poses_size[1] = 6;
  if (!std::isnan(b_this_Length)) {
    tempStartPose_idx_2 = -b_this_StartPose[2];
    poses_size[0] = 1;
    poses_size[1] = 6;
    for (count = 0; count < 6; count++) {
      poses_data[count] = 0.0;
    }

    samples_tmp = std::cos(std::abs(b_this_FlightPathAngle));
    samples *= samples_tmp;
    TransformMatrix[0] = b_this_MotionLengths[0] * samples_tmp;
    TransformMatrix[1] = b_this_MotionLengths[1] * samples_tmp;
    TransformMatrix[2] = b_this_MotionLengths[2] * samples_tmp;
    tempMotionLength_size[0] = 1;
    tempMotionLength_size[1] = 4;
    tempMotionLength_data[0] = TransformMatrix[0];
    tempMotionLength_data[1] = TransformMatrix[1];
    tempMotionLength_data[2] = TransformMatrix[2];
    tempMotionLength_data[3] = b_this_MotionLengths[3] * samples_tmp;
    PreemptableMissionModeSelector_strcmp_m2j(b_this_MotionTypes, tmp);
    if (PreemptableMissionModeSelector_any(tmp)) {
      tempMotionLength_size[0] = 1;
      tempMotionLength_size[1] = 3;
      tempMotionLength_data[0] = TransformMatrix[0];
      tempMotionLength_data[1] = TransformMatrix[1];
      tempMotionLength_data[2] = TransformMatrix[2];
    }

    PreemptableMissionModeSelector_useConstantDim(tempMotionLength_data,
      tempMotionLength_size, x_data, x_size);
    intermediateLength = 0.0;
    state[0] = b_this_StartPose[0];
    state[1] = -b_this_StartPose[1];
    state[3] = -b_this_StartPose[3];
    tempMotionLength_data_tmp = 0;
    PreemptableMissionModeSelector_emxInit_real_T1(&y, 1);
    PreemptableMissionModeSelector_emxInit_real_T_h(&b_y, 2);
    PreemptableMissionModeSelector_emxInit_real_T1(&c_x, 1);
    PreemptableMissionModeSelector_emxInit_real_T1(&d_x, 1);
    PreemptableMissionModeSelector_emxInit_real_T_h(&S, 2);
    while (tempMotionLength_data_tmp <= static_cast<int32_T>
           (tempMotionLength_size[1] - 1)) {
      if (static_cast<int32_T>(tempMotionLength_data_tmp + 1) == 1) {
        tempSamplesIndex = ((samples >= intermediateLength) && (samples <=
          (intermediateLength + tempMotionLength_data[0]) + 1.0E-6));
      } else {
        tempSamplesIndex = ((samples > intermediateLength) && (samples <=
          (intermediateLength + tempMotionLength_data[tempMotionLength_data_tmp])
          + 1.0E-6));
      }

      PreemptableMissionModeSelector_eml_find(tempSamplesIndex, &o_data, x_size);
      if (!PreemptableMissionModeSelector_strcmp_m2ju
          (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
           b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
        radius = b_this_MinTurningRadius;
        if (PreemptableMissionModeSelector_strcmp_m2juc
            (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
             b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          radius = b_this_HelixRadius;
        } else if (PreemptableMissionModeSelector_strcmp_m2jucf
                   (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                    b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          radius = b_this_HelixRadius;
        }

        count = 0;
        tempSamples_size_idx_0 = 1;
        tempSamples_data[0] = 0.0;
        if ((x_size[0] != 0) && (x_size[1] != 0)) {
          tempSamples_size_idx_0 = 2;
          tempSamples_data[1] = 0.0;
          count = 1;
          tempSamples_data[0] = samples;
          samples = -1.0;
        }

        tempSamples_data[count] = x_data[tempMotionLength_data_tmp];
        for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 - 1);
             count++) {
          S_data[count] = (tempSamples_data[count] - intermediateLength) /
            radius;
        }

        ns_size_idx_0 = tempSamples_size_idx_0;
        loop_ub = static_cast<int32_T>(static_cast<int32_T>
          (tempSamples_size_idx_0 * 6) - 1);
        for (count = 0; count <= loop_ub; count++) {
          ns_data[count] = 0.0;
        }

        for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 - 1);
             count++) {
          z_data[count] = tempStartPose_idx_2 + tempSamples_data[count];
        }

        TransformMatrix_tmp = std::sin(state[3]);
        TransformMatrix_tmp_0 = std::cos(state[3]);
        TransformMatrix[0] = TransformMatrix_tmp_0;
        TransformMatrix[2] = TransformMatrix_tmp;
        TransformMatrix[1] = -TransformMatrix_tmp;
        TransformMatrix[3] = TransformMatrix_tmp_0;
        if (b_this_Length != 0.0) {
          TransformMatrix_tmp = -b_this_GoalPose[2] - tempStartPose_idx_2;
          TransformMatrix_tmp_0 = b_this_Length * samples_tmp;
          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            z_data[count] = tempSamples_data[count] / TransformMatrix_tmp_0 *
              TransformMatrix_tmp + tempStartPose_idx_2;
          }
        }

        count = y->size[0];
        y->size[0] = tempSamples_size_idx_0;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(y, count);
        for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 - 1);
             count++) {
          y->data[count] = b_this_FlightPathAngle;
        }

        if (PreemptableMissionModeSelector_strcmp_m2juc
            (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
             b_this_MotionTypes[tempMotionLength_data_tmp].f1.size) ||
            PreemptableMissionModeSelector_strcmp_m2jucfm
            (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
             b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          count = c_x->size[0];
          c_x->size[0] = tempSamples_size_idx_0;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(c_x, count);
          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            c_x->data[count] = S_data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count = static_cast<int32_T>(count + 1)) {
            c_x->data[count] = std::sin(c_x->data[count]);
          }

          count = d_x->size[0];
          d_x->size[0] = tempSamples_size_idx_0;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(d_x, count);
          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            d_x->data[count] = S_data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count = static_cast<int32_T>(count + 1)) {
            d_x->data[count] = std::cos(d_x->data[count]);
          }

          count = static_cast<int32_T>(S->size[0] * S->size[1]);
          S->size[0] = c_x->size[0];
          S->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S, count);
          loop_ub = c_x->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            S->data[count] = c_x->data[count];
          }

          loop_ub = d_x->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            S->data[static_cast<int32_T>(count + c_x->size[0])] = 1.0 -
              d_x->data[count];
          }

          PreemptableMissionModeSelector_mtimes(S, TransformMatrix, b_y);
          d_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          TransformMatrix_tmp = state[0];
          TransformMatrix_tmp_0 = state[1];
          state_0 = state[3];
          loop_ub = b_y->size[0];
          ns_size_idx_0 = b_y->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            ns_data[count] = b_y->data[count] * radius + TransformMatrix_tmp;
            ns_data[static_cast<int32_T>(count + ns_size_idx_0)] = b_y->data[
              static_cast<int32_T>(count + b_y->size[0])] * radius +
              TransformMatrix_tmp_0;
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 << 1))] = z_data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 * 3))] = state_0 + S_data[count];
          }

          loop_ub = y->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 << 2))] = y->data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 * 5))] = -d_b;
          }
        } else if (PreemptableMissionModeSelector_strcmp_m2jucf
                   (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                    b_this_MotionTypes[tempMotionLength_data_tmp].f1.size) ||
                   PreemptableMissionModeSelector_strcmp_m2jucfmm
                   (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                    b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          count = c_x->size[0];
          c_x->size[0] = tempSamples_size_idx_0;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(c_x, count);
          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            c_x->data[count] = S_data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count = static_cast<int32_T>(count + 1)) {
            c_x->data[count] = std::sin(c_x->data[count]);
          }

          count = d_x->size[0];
          d_x->size[0] = tempSamples_size_idx_0;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(d_x, count);
          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            d_x->data[count] = S_data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count = static_cast<int32_T>(count + 1)) {
            d_x->data[count] = std::cos(d_x->data[count]);
          }

          count = static_cast<int32_T>(S->size[0] * S->size[1]);
          S->size[0] = c_x->size[0];
          S->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S, count);
          loop_ub = c_x->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            S->data[count] = c_x->data[count];
          }

          loop_ub = d_x->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            S->data[static_cast<int32_T>(count + c_x->size[0])] = d_x->
              data[count] - 1.0;
          }

          PreemptableMissionModeSelector_mtimes(S, TransformMatrix, b_y);
          d_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          TransformMatrix_tmp = state[0];
          TransformMatrix_tmp_0 = state[1];
          state_0 = state[3];
          loop_ub = b_y->size[0];
          ns_size_idx_0 = b_y->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            ns_data[count] = b_y->data[count] * radius + TransformMatrix_tmp;
            ns_data[static_cast<int32_T>(count + ns_size_idx_0)] = b_y->data[
              static_cast<int32_T>(count + b_y->size[0])] * radius +
              TransformMatrix_tmp_0;
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 << 1))] = z_data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 * 3))] = state_0 - S_data[count];
          }

          loop_ub = y->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 << 2))] = y->data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 * 5))] = d_b;
          }
        } else if (PreemptableMissionModeSelector_strcmp_m2jucfmmw
                   (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                    b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          count = static_cast<int32_T>(S->size[0] * S->size[1]);
          S->size[0] = tempSamples_size_idx_0;
          S->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S, count);
          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            S->data[count] = S_data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            S->data[static_cast<int32_T>(count + tempSamples_size_idx_0)] = 0.0;
          }

          PreemptableMissionModeSelector_mtimes(S, TransformMatrix, b_y);
          TransformMatrix_tmp = state[0];
          TransformMatrix_tmp_0 = state[1];
          loop_ub = b_y->size[0];
          ns_size_idx_0 = b_y->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            ns_data[count] = b_y->data[count] * radius + TransformMatrix_tmp;
            ns_data[static_cast<int32_T>(count + ns_size_idx_0)] = b_y->data[
              static_cast<int32_T>(count + b_y->size[0])] * radius +
              TransformMatrix_tmp_0;
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 << 1))] = z_data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 * 3))] = state[3];
          }

          loop_ub = y->size[0];
          for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 << 2))] = y->data[count];
          }

          for (count = 0; count <= static_cast<int32_T>(tempSamples_size_idx_0 -
                1); count++) {
            ns_data[static_cast<int32_T>(count + static_cast<int32_T>
              (ns_size_idx_0 * 5))] = 0.0;
          }
        }

        if ((x_size[0] != 0) && (x_size[1] != 0)) {
          if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            for (count = 0; count < 6; count++) {
              poses_data[count] = ns_data[static_cast<int32_T>(ns_size_idx_0 *
                count)];
            }
          }

          if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            poses_data[0] = ns_data[0];
          }

          if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            poses_data[1] = -ns_data[ns_size_idx_0];
          }

          if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            poses_data[2] = -ns_data[static_cast<int32_T>(ns_size_idx_0 << 1)];
          }

          if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            poses_data[3] = -ns_data[static_cast<int32_T>(ns_size_idx_0 * 3)];
          }
        }

        for (count = 0; count < 6; count++) {
          state[count] = ns_data[static_cast<int32_T>(static_cast<int32_T>
            (ns_size_idx_0 + static_cast<int32_T>(ns_size_idx_0 * count)) - 1)];
        }
      }

      intermediateLength += tempMotionLength_data[tempMotionLength_data_tmp];
      tempMotionLength_data_tmp = static_cast<int32_T>(tempMotionLength_data_tmp
        + 1);
    }

    PreemptableMissionModeSelector_emxFree_real_T_n(&S);
    PreemptableMissionModeSelector_emxFree_real_T_n(&d_x);
    PreemptableMissionModeSelector_emxFree_real_T_n(&c_x);
    PreemptableMissionModeSelector_emxFree_real_T_n(&b_y);
    count = y->size[0];
    y->size[0] = 1;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(y, count);
    y->data[0] = poses_data[3];
    PreemptableMissionModeSelector_wrapToPi(y);
    loop_ub = y->size[0];
    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
      poses_data[3] = y->data[count];
    }

    PreemptableMissionModeSelector_emxFree_real_T_n(&y);
  }
}

static void PreemptableMissionModeSelector_emxInit_int32_T
  (emxArray_int32_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_int32_T_PreemptableMissionModeSelector_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T_PreemptableMissionModeSelector_T *)std::malloc
    (sizeof(emxArray_int32_T_PreemptableMissionModeSelector_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T) *
    static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
    emxArray->size[i] = 0;
  }
}

static void PreemptableMissionModeSelector_emxEnsureCapacity_int32_T
  (emxArray_int32_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel)
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

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(int32_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(oldNumel)));
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void PreemptableMissionModeSelector_emxInit_int32_T1
  (emxArray_int32_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_int32_T_PreemptableMissionModeSelector_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T_PreemptableMissionModeSelector_T *)std::malloc
    (sizeof(emxArray_int32_T_PreemptableMissionModeSelector_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T) *
    static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
    emxArray->size[i] = 0;
  }
}

static void PreemptableMissionModeSelector_emxEnsureCapacity_int32_T1
  (emxArray_int32_T_PreemptableMissionModeSelector_T *emxArray, int32_T oldNumel)
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

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(int32_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(oldNumel)));
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void PreemptableMissionModeSelector_emxFree_int32_T
  (emxArray_int32_T_PreemptableMissionModeSelector_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T_PreemptableMissionModeSelector_T *)nullptr)
  {
    if (((*pEmxArray)->data != (int32_T *)nullptr) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T_PreemptableMissionModeSelector_T *)nullptr;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_merge_ni
  (emxArray_int32_T_PreemptableMissionModeSelector_T *idx,
   emxArray_real_T_PreemptableMissionModeSelector_T *x, int32_T offset, int32_T
   np, int32_T nq, emxArray_int32_T_PreemptableMissionModeSelector_T *iwork,
   emxArray_real_T_PreemptableMissionModeSelector_T *xwork)
{
  int32_T exitg1;
  int32_T iout;
  int32_T offset1;
  int32_T p;
  int32_T q;
  if (nq != 0) {
    offset1 = static_cast<int32_T>(np + nq);
    for (p = 0; p <= static_cast<int32_T>(offset1 - 1); p = static_cast<int32_T>
         (p + 1)) {
      q = static_cast<int32_T>(offset + p);
      iwork->data[p] = idx->data[q];
      xwork->data[p] = x->data[q];
    }

    p = 0;
    q = np;
    iout = static_cast<int32_T>(offset - 1);
    do {
      exitg1 = 0;
      iout = static_cast<int32_T>(iout + 1);
      if (xwork->data[p] <= xwork->data[q]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (static_cast<int32_T>(p + 1) < np) {
          p = static_cast<int32_T>(p + 1);
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[q];
        x->data[iout] = xwork->data[q];
        if (static_cast<int32_T>(q + 1) < offset1) {
          q = static_cast<int32_T>(q + 1);
        } else {
          offset1 = static_cast<int32_T>(iout - p);
          while (static_cast<int32_T>(p + 1) <= np) {
            q = static_cast<int32_T>(static_cast<int32_T>(offset1 + p) + 1);
            idx->data[q] = iwork->data[p];
            x->data[q] = xwork->data[p];
            p = static_cast<int32_T>(p + 1);
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_merge_block
  (emxArray_int32_T_PreemptableMissionModeSelector_T *idx,
   emxArray_real_T_PreemptableMissionModeSelector_T *x, int32_T offset, int32_T
   n, int32_T preSortLevel, emxArray_int32_T_PreemptableMissionModeSelector_T
   *iwork, emxArray_real_T_PreemptableMissionModeSelector_T *xwork)
{
  int32_T bLen;
  int32_T nPairs;
  int32_T nTail;
  int32_T tailOffset;
  nPairs = static_cast<int32_T>(n >> preSortLevel);
  bLen = static_cast<int32_T>(1 << preSortLevel);
  while (nPairs > 1) {
    if (static_cast<uint32_T>(static_cast<uint32_T>(nPairs) & 1U) != 0U) {
      nPairs = static_cast<int32_T>(nPairs - 1);
      tailOffset = static_cast<int32_T>(bLen * nPairs);
      nTail = static_cast<int32_T>(n - tailOffset);
      if (nTail > bLen) {
        PreemptableMissionModeSelector_merge_ni(idx, x, static_cast<int32_T>
          (offset + tailOffset), bLen, static_cast<int32_T>(nTail - bLen), iwork,
          xwork);
      }
    }

    tailOffset = static_cast<int32_T>(bLen << 1);
    nPairs = static_cast<int32_T>(nPairs >> 1);
    for (nTail = 0; nTail <= static_cast<int32_T>(nPairs - 1); nTail =
         static_cast<int32_T>(nTail + 1)) {
      PreemptableMissionModeSelector_merge_ni(idx, x, static_cast<int32_T>
        (offset + static_cast<int32_T>(nTail * tailOffset)), bLen, bLen, iwork,
        xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    PreemptableMissionModeSelector_merge_ni(idx, x, offset, bLen,
      static_cast<int32_T>(n - bLen), iwork, xwork);
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_sort_ps
  (emxArray_real_T_PreemptableMissionModeSelector_T *x)
{
  emxArray_int32_T_PreemptableMissionModeSelector_T *idx;
  emxArray_int32_T_PreemptableMissionModeSelector_T *iwork;
  emxArray_real_T_PreemptableMissionModeSelector_T *b_x;
  emxArray_real_T_PreemptableMissionModeSelector_T *xwork;
  real_T b_xwork[256];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T b_iwork[256];
  int32_T idx4[4];
  int32_T bLen;
  int32_T bLen2;
  int32_T b_iwork_tmp;
  int32_T e_k;
  int32_T exitg1;
  int32_T i2;
  int32_T ib;
  int32_T n;
  int32_T nNonNaN;
  int32_T nPairs;
  int32_T p;
  int32_T preSortLevel;
  int32_T q;
  int32_T wOffset;
  int8_T perm[4];
  PreemptableMissionModeSelector_emxInit_real_T_h(&b_x, 2);
  b_iwork_tmp = static_cast<int32_T>(b_x->size[0] * b_x->size[1]);
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(b_x, b_iwork_tmp);
  wOffset = static_cast<int32_T>(x->size[1] - 1);
  for (preSortLevel = 0; preSortLevel <= wOffset; preSortLevel++) {
    b_x->data[preSortLevel] = x->data[preSortLevel];
  }

  if (x->size[1] != 0) {
    b_iwork_tmp = static_cast<int32_T>(b_x->size[0] * b_x->size[1]);
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(b_x, b_iwork_tmp);
    wOffset = static_cast<int32_T>(x->size[1] - 1);
    for (preSortLevel = 0; preSortLevel <= wOffset; preSortLevel++) {
      b_x->data[preSortLevel] = x->data[preSortLevel];
    }

    PreemptableMissionModeSelector_emxInit_int32_T(&idx, 2);
    b_iwork_tmp = static_cast<int32_T>(idx->size[0] * idx->size[1]);
    idx->size[0] = 1;
    idx->size[1] = x->size[1];
    PreemptableMissionModeSelector_emxEnsureCapacity_int32_T(idx, b_iwork_tmp);
    wOffset = static_cast<int32_T>(x->size[1] - 1);
    for (preSortLevel = 0; preSortLevel <= wOffset; preSortLevel++) {
      idx->data[preSortLevel] = 0;
    }

    PreemptableMissionModeSelector_emxInit_real_T1(&xwork, 1);
    n = x->size[1];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    b_iwork_tmp = xwork->size[0];
    xwork->size[0] = x->size[1];
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(xwork, b_iwork_tmp);
    wOffset = x->size[1];
    for (preSortLevel = 0; preSortLevel <= static_cast<int32_T>(wOffset - 1);
         preSortLevel++) {
      xwork->data[preSortLevel] = 0.0;
    }

    nNonNaN = 0;
    ib = 0;
    for (wOffset = 0; wOffset <= static_cast<int32_T>(n - 1); wOffset =
         static_cast<int32_T>(wOffset + 1)) {
      if (std::isnan(b_x->data[wOffset])) {
        preSortLevel = static_cast<int32_T>(static_cast<int32_T>(n - nNonNaN) -
          1);
        idx->data[preSortLevel] = static_cast<int32_T>(wOffset + 1);
        xwork->data[preSortLevel] = b_x->data[wOffset];
        nNonNaN = static_cast<int32_T>(nNonNaN + 1);
      } else {
        ib = static_cast<int32_T>(ib + 1);
        idx4[static_cast<int32_T>(ib - 1)] = static_cast<int32_T>(wOffset + 1);
        x4[static_cast<int32_T>(ib - 1)] = b_x->data[wOffset];
        if (ib == 4) {
          preSortLevel = static_cast<int32_T>(wOffset - nNonNaN);
          if (x4[0] <= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }

          if (x4[2] <= x4[3]) {
            bLen = 3;
            bLen2 = 4;
          } else {
            bLen = 4;
            bLen2 = 3;
          }

          tmp = x4[static_cast<int32_T>(ib - 1)];
          tmp_0 = x4[static_cast<int32_T>(bLen - 1)];
          if (tmp <= tmp_0) {
            tmp = x4[static_cast<int32_T>(i2 - 1)];
            if (tmp <= tmp_0) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i2);
              perm[2] = static_cast<int8_T>(bLen);
              perm[3] = static_cast<int8_T>(bLen2);
            } else if (tmp <= x4[static_cast<int32_T>(bLen2 - 1)]) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(bLen);
              perm[2] = static_cast<int8_T>(i2);
              perm[3] = static_cast<int8_T>(bLen2);
            } else {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(bLen);
              perm[2] = static_cast<int8_T>(bLen2);
              perm[3] = static_cast<int8_T>(i2);
            }
          } else {
            tmp_0 = x4[static_cast<int32_T>(bLen2 - 1)];
            if (tmp <= tmp_0) {
              if (x4[static_cast<int32_T>(i2 - 1)] <= tmp_0) {
                perm[0] = static_cast<int8_T>(bLen);
                perm[1] = static_cast<int8_T>(ib);
                perm[2] = static_cast<int8_T>(i2);
                perm[3] = static_cast<int8_T>(bLen2);
              } else {
                perm[0] = static_cast<int8_T>(bLen);
                perm[1] = static_cast<int8_T>(ib);
                perm[2] = static_cast<int8_T>(bLen2);
                perm[3] = static_cast<int8_T>(i2);
              }
            } else {
              perm[0] = static_cast<int8_T>(bLen);
              perm[1] = static_cast<int8_T>(bLen2);
              perm[2] = static_cast<int8_T>(ib);
              perm[3] = static_cast<int8_T>(i2);
            }
          }

          idx->data[static_cast<int32_T>(preSortLevel - 3)] = idx4
            [static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)];
          idx->data[static_cast<int32_T>(preSortLevel - 2)] = idx4
            [static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)];
          idx->data[static_cast<int32_T>(preSortLevel - 1)] = idx4
            [static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)];
          idx->data[preSortLevel] = idx4[static_cast<int32_T>
            (static_cast<int32_T>(perm[3]) - 1)];
          b_x->data[static_cast<int32_T>(preSortLevel - 3)] = x4
            [static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)];
          b_x->data[static_cast<int32_T>(preSortLevel - 2)] = x4
            [static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)];
          b_x->data[static_cast<int32_T>(preSortLevel - 1)] = x4
            [static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)];
          b_x->data[preSortLevel] = x4[static_cast<int32_T>(static_cast<int32_T>
            (perm[3]) - 1)];
          ib = 0;
        }
      }
    }

    wOffset = static_cast<int32_T>(static_cast<int32_T>(x->size[1] - nNonNaN) -
      1);
    if (ib > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      switch (ib) {
       case 1:
        perm[0] = 1;
        break;

       case 2:
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
        break;

       default:
        if (x4[0] <= x4[1]) {
          if (x4[1] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 2;
            perm[2] = 3;
          } else if (x4[0] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 3;
            perm[2] = 2;
          } else {
            perm[0] = 3;
            perm[1] = 1;
            perm[2] = 2;
          }
        } else if (x4[0] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 1;
          perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 3;
          perm[2] = 1;
        } else {
          perm[0] = 3;
          perm[1] = 2;
          perm[2] = 1;
        }
        break;
      }

      for (i2 = 0; i2 <= static_cast<int32_T>(ib - 1); i2 = static_cast<int32_T>
           (i2 + 1)) {
        preSortLevel = static_cast<int32_T>(static_cast<int32_T>(perm[i2]) - 1);
        b_iwork_tmp = static_cast<int32_T>(static_cast<int32_T>
          (static_cast<int32_T>(wOffset - ib) + i2) + 1);
        idx->data[b_iwork_tmp] = idx4[preSortLevel];
        b_x->data[b_iwork_tmp] = x4[preSortLevel];
      }
    }

    ib = static_cast<int32_T>(static_cast<int32_T>(nNonNaN >> 1) + 1);
    for (i2 = 1; static_cast<int32_T>(i2 - 1) <= static_cast<int32_T>(ib - 2);
         i2 = static_cast<int32_T>(i2 + 1)) {
      bLen = static_cast<int32_T>(wOffset + i2);
      bLen2 = idx->data[bLen];
      preSortLevel = static_cast<int32_T>(n - i2);
      idx->data[bLen] = idx->data[preSortLevel];
      idx->data[preSortLevel] = bLen2;
      b_x->data[bLen] = xwork->data[preSortLevel];
      b_x->data[preSortLevel] = xwork->data[bLen];
    }

    if (static_cast<uint32_T>(static_cast<uint32_T>(nNonNaN) & 1U) != 0U) {
      preSortLevel = static_cast<int32_T>(wOffset + ib);
      b_x->data[preSortLevel] = xwork->data[preSortLevel];
    }

    PreemptableMissionModeSelector_emxInit_int32_T1(&iwork, 1);
    b_iwork_tmp = iwork->size[0];
    iwork->size[0] = x->size[1];
    PreemptableMissionModeSelector_emxEnsureCapacity_int32_T1(iwork, b_iwork_tmp);
    wOffset = x->size[1];
    for (preSortLevel = 0; preSortLevel <= static_cast<int32_T>(wOffset - 1);
         preSortLevel++) {
      iwork->data[preSortLevel] = 0;
    }

    nNonNaN = static_cast<int32_T>(x->size[1] - nNonNaN);
    preSortLevel = 2;
    if (nNonNaN > 1) {
      if (x->size[1] >= 256) {
        n = static_cast<int32_T>(nNonNaN >> 8);
        if (n > 0) {
          for (ib = 0; ib <= static_cast<int32_T>(n - 1); ib =
               static_cast<int32_T>(ib + 1)) {
            i2 = static_cast<int32_T>(static_cast<int32_T>(ib << 8) - 1);
            for (wOffset = 0; wOffset < 6; wOffset++) {
              bLen = static_cast<int32_T>(1 << static_cast<int32_T>(wOffset + 2));
              bLen2 = static_cast<int32_T>(bLen << 1);
              nPairs = static_cast<int32_T>(256 >> static_cast<int32_T>(wOffset
                + 3));
              for (e_k = 0; e_k <= static_cast<int32_T>(nPairs - 1); e_k =
                   static_cast<int32_T>(e_k + 1)) {
                preSortLevel = static_cast<int32_T>(static_cast<int32_T>(e_k *
                  bLen2) + i2);
                for (p = 0; p <= static_cast<int32_T>(bLen2 - 1); p =
                     static_cast<int32_T>(p + 1)) {
                  b_iwork_tmp = static_cast<int32_T>(static_cast<int32_T>
                    (preSortLevel + p) + 1);
                  b_iwork[p] = idx->data[b_iwork_tmp];
                  b_xwork[p] = b_x->data[b_iwork_tmp];
                }

                p = 0;
                q = bLen;
                do {
                  exitg1 = 0;
                  preSortLevel = static_cast<int32_T>(preSortLevel + 1);
                  if (b_xwork[p] <= b_xwork[q]) {
                    idx->data[preSortLevel] = b_iwork[p];
                    b_x->data[preSortLevel] = b_xwork[p];
                    if (static_cast<int32_T>(p + 1) < bLen) {
                      p = static_cast<int32_T>(p + 1);
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx->data[preSortLevel] = b_iwork[q];
                    b_x->data[preSortLevel] = b_xwork[q];
                    if (static_cast<int32_T>(q + 1) < bLen2) {
                      q = static_cast<int32_T>(q + 1);
                    } else {
                      q = static_cast<int32_T>(preSortLevel - p);
                      while (static_cast<int32_T>(p + 1) <= bLen) {
                        b_iwork_tmp = static_cast<int32_T>(static_cast<int32_T>
                          (q + p) + 1);
                        idx->data[b_iwork_tmp] = b_iwork[p];
                        b_x->data[b_iwork_tmp] = b_xwork[p];
                        p = static_cast<int32_T>(p + 1);
                      }

                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }

          n = static_cast<int32_T>(n << 8);
          ib = static_cast<int32_T>(nNonNaN - n);
          if (ib > 0) {
            b_iwork_tmp = iwork->size[0];
            iwork->size[0] = x->size[1];
            PreemptableMissionModeSelector_emxEnsureCapacity_int32_T1(iwork,
              b_iwork_tmp);
            wOffset = x->size[1];
            for (preSortLevel = 0; preSortLevel <= static_cast<int32_T>(wOffset
                  - 1); preSortLevel++) {
              iwork->data[preSortLevel] = 0;
            }

            PreemptableMissionModeSelector_merge_block(idx, b_x, n, ib, 2, iwork,
              xwork);
          }

          preSortLevel = 8;
        }
      }

      PreemptableMissionModeSelector_merge_block(idx, b_x, 0, nNonNaN,
        preSortLevel, iwork, xwork);
    }

    PreemptableMissionModeSelector_emxFree_int32_T(&idx);
    PreemptableMissionModeSelector_emxFree_real_T_n(&xwork);
    PreemptableMissionModeSelector_emxFree_int32_T(&iwork);
  }

  b_iwork_tmp = static_cast<int32_T>(x->size[0] * x->size[1]);
  x->size[0] = 1;
  x->size[1] = b_x->size[1];
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(x, b_iwork_tmp);
  wOffset = b_x->size[1];
  for (preSortLevel = 0; preSortLevel <= static_cast<int32_T>(wOffset - 1);
       preSortLevel++) {
    x->data[preSortLevel] = b_x->data[preSortLevel];
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&b_x);
}

static void PreemptableMissionModeSelector_emxInit_boolean_T
  (emxArray_boolean_T_PreemptableMissionModeSelector_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_boolean_T_PreemptableMissionModeSelector_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_PreemptableMissionModeSelector_T *)std::
    malloc(sizeof(emxArray_boolean_T_PreemptableMissionModeSelector_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T) *
    static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
    emxArray->size[i] = 0;
  }
}

static void PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T
  (emxArray_boolean_T_PreemptableMissionModeSelector_T *emxArray, int32_T
   oldNumel)
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

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(boolean_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
        (boolean_T) * static_cast<uint32_T>(oldNumel)));
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_eml_find_h(const
  emxArray_boolean_T_PreemptableMissionModeSelector_T *x,
  emxArray_int32_T_PreemptableMissionModeSelector_T *i)
{
  int32_T idx;
  int32_T ii;
  int32_T nx;
  boolean_T exitg1;
  nx = x->size[1];
  idx = 0;
  ii = static_cast<int32_T>(i->size[0] * i->size[1]);
  i->size[0] = 1;
  i->size[1] = x->size[1];
  PreemptableMissionModeSelector_emxEnsureCapacity_int32_T(i, ii);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= static_cast<int32_T>(nx - 1))) {
    if (x->data[ii]) {
      idx = static_cast<int32_T>(idx + 1);
      i->data[static_cast<int32_T>(idx - 1)] = static_cast<int32_T>(ii + 1);
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii = static_cast<int32_T>(ii + 1);
      }
    } else {
      ii = static_cast<int32_T>(ii + 1);
    }
  }

  if (x->size[1] == 1) {
    if (idx == 0) {
      i->size[0] = 1;
      i->size[1] = 0;
    }
  } else if (1 > idx) {
    i->size[1] = 0;
  } else {
    ii = static_cast<int32_T>(i->size[0] * i->size[1]);
    i->size[1] = idx;
    PreemptableMissionModeSelector_emxEnsureCapacity_int32_T(i, ii);
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate_p(
  const real_T b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_1_PreemptableMissionModeSelector_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, emxArray_real_T_PreemptableMissionModeSelector_T *samples,
  emxArray_real_T_PreemptableMissionModeSelector_T *poses)
{
  emxArray_boolean_T_PreemptableMissionModeSelector_T *tempSamplesIndex;
  emxArray_boolean_T_PreemptableMissionModeSelector_T *tempSamplesIndex_0;
  emxArray_int32_T_PreemptableMissionModeSelector_T *ab;
  emxArray_real_T_PreemptableMissionModeSelector_T *S;
  emxArray_real_T_PreemptableMissionModeSelector_T *S_0;
  emxArray_real_T_PreemptableMissionModeSelector_T *e_x;
  emxArray_real_T_PreemptableMissionModeSelector_T *ns;
  emxArray_real_T_PreemptableMissionModeSelector_T *p;
  emxArray_real_T_PreemptableMissionModeSelector_T *tempSamples;
  emxArray_real_T_PreemptableMissionModeSelector_T *z;
  real_T state[6];
  real_T TransformMatrix[4];
  real_T c_x_data[4];
  real_T tempMotionLength_data[4];
  real_T TransformMatrix_tmp;
  real_T b_b_tmp;
  real_T e_b;
  real_T intermediateLength;
  real_T radius;
  real_T samples_0;
  real_T startIndex;
  real_T state_0;
  real_T tempStartPose_idx_2;
  int32_T c_x_size[2];
  int32_T tempMotionLength_size[2];
  int32_T S_idx_0;
  int32_T count;
  int32_T d_k;
  int32_T loop_ub;
  int32_T poses_0;
  int32_T tempMotionLength_data_tmp;
  boolean_T tmp[4];
  poses->size[0] = 0;
  poses->size[1] = 6;
  if ((!std::isnan(b_this_Length)) && (samples->size[1] != 0)) {
    tempStartPose_idx_2 = -b_this_StartPose[2];
    d_k = static_cast<int32_T>(poses->size[0] * poses->size[1]);
    poses->size[0] = samples->size[1];
    poses->size[1] = 6;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(poses, d_k);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(samples->size[1] * 6) -
      1);
    for (d_k = 0; d_k <= loop_ub; d_k++) {
      poses->data[d_k] = 0.0;
    }

    b_b_tmp = std::cos(std::abs(b_this_FlightPathAngle));
    d_k = static_cast<int32_T>(samples->size[0] * samples->size[1]);
    samples->size[0] = 1;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(samples, d_k);
    loop_ub = static_cast<int32_T>(samples->size[1] - 1);
    for (d_k = 0; d_k <= loop_ub; d_k++) {
      samples->data[d_k] *= b_b_tmp;
    }

    TransformMatrix[0] = b_this_MotionLengths[0] * b_b_tmp;
    TransformMatrix[1] = b_this_MotionLengths[1] * b_b_tmp;
    TransformMatrix[2] = b_this_MotionLengths[2] * b_b_tmp;
    tempMotionLength_size[0] = 1;
    tempMotionLength_size[1] = 4;
    tempMotionLength_data[0] = TransformMatrix[0];
    tempMotionLength_data[1] = TransformMatrix[1];
    tempMotionLength_data[2] = TransformMatrix[2];
    tempMotionLength_data[3] = b_this_MotionLengths[3] * b_b_tmp;
    PreemptableMissionModeSelector_strcmp_m2j(b_this_MotionTypes, tmp);
    if (PreemptableMissionModeSelector_any(tmp)) {
      tempMotionLength_size[0] = 1;
      tempMotionLength_size[1] = 3;
      tempMotionLength_data[0] = TransformMatrix[0];
      tempMotionLength_data[1] = TransformMatrix[1];
      tempMotionLength_data[2] = TransformMatrix[2];
    }

    PreemptableMissionModeSelector_useConstantDim(tempMotionLength_data,
      tempMotionLength_size, c_x_data, c_x_size);
    PreemptableMissionModeSelector_sort_ps(samples);
    intermediateLength = 0.0;
    startIndex = 1.0;
    state[0] = b_this_StartPose[0];
    state[1] = -b_this_StartPose[1];
    state[3] = -b_this_StartPose[3];
    poses_0 = 0;
    PreemptableMissionModeSelector_emxInit_boolean_T(&tempSamplesIndex, 2);
    PreemptableMissionModeSelector_emxInit_real_T1(&tempSamples, 1);
    PreemptableMissionModeSelector_emxInit_real_T1(&S, 1);
    PreemptableMissionModeSelector_emxInit_real_T_h(&ns, 2);
    PreemptableMissionModeSelector_emxInit_real_T1(&z, 1);
    PreemptableMissionModeSelector_emxInit_real_T_h(&p, 2);
    PreemptableMissionModeSelector_emxInit_real_T1(&e_x, 1);
    PreemptableMissionModeSelector_emxInit_int32_T(&ab, 2);
    PreemptableMissionModeSelector_emxInit_boolean_T(&tempSamplesIndex_0, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&S_0, 2);
    while (poses_0 <= static_cast<int32_T>(tempMotionLength_size[1] - 1)) {
      if (static_cast<int32_T>(poses_0 + 1) == 1) {
        d_k = static_cast<int32_T>(tempSamplesIndex->size[0] *
          tempSamplesIndex->size[1]);
        tempSamplesIndex->size[0] = 1;
        tempSamplesIndex->size[1] = samples->size[1];
        PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T
          (tempSamplesIndex, d_k);
        loop_ub = static_cast<int32_T>(samples->size[1] - 1);
        radius = (intermediateLength + tempMotionLength_data[0]) + 1.0E-6;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          samples_0 = samples->data[d_k];
          tempSamplesIndex->data[d_k] = ((samples_0 >= intermediateLength) &&
            (samples_0 <= radius));
        }
      } else {
        d_k = static_cast<int32_T>(tempSamplesIndex->size[0] *
          tempSamplesIndex->size[1]);
        tempSamplesIndex->size[0] = 1;
        tempSamplesIndex->size[1] = samples->size[1];
        PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T
          (tempSamplesIndex, d_k);
        loop_ub = static_cast<int32_T>(samples->size[1] - 1);
        radius = (intermediateLength + tempMotionLength_data[poses_0]) + 1.0E-6;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          samples_0 = samples->data[d_k];
          tempSamplesIndex->data[d_k] = ((samples_0 > intermediateLength) &&
            (samples_0 <= radius));
        }
      }

      d_k = static_cast<int32_T>(tempSamplesIndex_0->size[0] *
        tempSamplesIndex_0->size[1]);
      tempSamplesIndex_0->size[0] = 1;
      tempSamplesIndex_0->size[1] = tempSamplesIndex->size[1];
      PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T
        (tempSamplesIndex_0, d_k);
      loop_ub = tempSamplesIndex->size[1];
      for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
        tempSamplesIndex_0->data[d_k] = tempSamplesIndex->data[d_k];
      }

      PreemptableMissionModeSelector_eml_find_h(tempSamplesIndex_0, ab);
      if (!PreemptableMissionModeSelector_strcmp_m2ju(b_this_MotionTypes[poses_0]
           .f1.data, b_this_MotionTypes[poses_0].f1.size)) {
        radius = b_this_MinTurningRadius;
        if (PreemptableMissionModeSelector_strcmp_m2juc
            (b_this_MotionTypes[poses_0].f1.data, b_this_MotionTypes[poses_0].
             f1.size)) {
          radius = b_this_HelixRadius;
        } else if (PreemptableMissionModeSelector_strcmp_m2jucf
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          radius = b_this_HelixRadius;
        }

        count = 0;
        d_k = tempSamples->size[0];
        tempSamples->size[0] = 1;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples,
          d_k);
        tempSamples->data[0] = 0.0;
        if (ab->size[1] != 0) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = static_cast<int32_T>(ab->size[1] + 1);
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples,
            d_k);
          loop_ub = ab->size[1];
          for (d_k = 0; d_k <= loop_ub; d_k++) {
            tempSamples->data[d_k] = 0.0;
          }

          loop_ub = ab->size[1];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            tempSamples->data[d_k] = samples->data[static_cast<int32_T>(ab->
              data[d_k] - 1)];
          }

          count = ab->size[1];
          loop_ub = static_cast<int32_T>(ab->size[1] - 1);
          for (d_k = 0; d_k <= loop_ub; d_k++) {
            samples->data[static_cast<int32_T>(ab->data[d_k] - 1)] = -1.0;
          }
        }

        tempSamples->data[count] = c_x_data[poses_0];
        d_k = S->size[0];
        S->size[0] = tempSamples->size[0];
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(S, d_k);
        loop_ub = tempSamples->size[0];
        for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
          S->data[d_k] = (tempSamples->data[d_k] - intermediateLength) / radius;
        }

        d_k = static_cast<int32_T>(ns->size[0] * ns->size[1]);
        ns->size[0] = S->size[0];
        ns->size[1] = 6;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ns, d_k);
        loop_ub = static_cast<int32_T>(static_cast<int32_T>(S->size[0] * 6) - 1);
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          ns->data[d_k] = 0.0;
        }

        d_k = z->size[0];
        z->size[0] = tempSamples->size[0];
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(z, d_k);
        loop_ub = tempSamples->size[0];
        for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
          z->data[d_k] = tempStartPose_idx_2 + tempSamples->data[d_k];
        }

        samples_0 = std::sin(state[3]);
        TransformMatrix_tmp = std::cos(state[3]);
        TransformMatrix[0] = TransformMatrix_tmp;
        TransformMatrix[2] = samples_0;
        TransformMatrix[1] = -samples_0;
        TransformMatrix[3] = TransformMatrix_tmp;
        if (b_this_Length != 0.0) {
          samples_0 = -b_this_GoalPose[2] - tempStartPose_idx_2;
          TransformMatrix_tmp = b_this_Length * b_b_tmp;
          d_k = z->size[0];
          z->size[0] = tempSamples->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(z, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            z->data[d_k] = tempSamples->data[d_k] / TransformMatrix_tmp *
              samples_0 + tempStartPose_idx_2;
          }
        }

        if (PreemptableMissionModeSelector_strcmp_m2juc
            (b_this_MotionTypes[poses_0].f1.data, b_this_MotionTypes[poses_0].
             f1.size) || PreemptableMissionModeSelector_strcmp_m2jucfm
            (b_this_MotionTypes[poses_0].f1.data, b_this_MotionTypes[poses_0].
             f1.size)) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = S->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples,
            d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            tempSamples->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S->size[0] - 1); d_k =
               static_cast<int32_T>(d_k + 1)) {
            tempSamples->data[d_k] = std::sin(tempSamples->data[d_k]);
          }

          d_k = e_x->size[0];
          e_x->size[0] = S->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(e_x, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            e_x->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S->size[0] - 1); d_k =
               static_cast<int32_T>(d_k + 1)) {
            e_x->data[d_k] = std::cos(e_x->data[d_k]);
          }

          d_k = static_cast<int32_T>(S_0->size[0] * S_0->size[1]);
          S_0->size[0] = tempSamples->size[0];
          S_0->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S_0, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[d_k] = tempSamples->data[d_k];
          }

          loop_ub = e_x->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[static_cast<int32_T>(d_k + tempSamples->size[0])] = 1.0 -
              e_x->data[d_k];
          }

          PreemptableMissionModeSelector_mtimes(S_0, TransformMatrix, p);
          e_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          state_0 = state[3];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          loop_ub = p->size[0];
          d_k = static_cast<int32_T>(ns->size[0] * ns->size[1]);
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ns, d_k);
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[static_cast<int32_T>(d_k + ns->size[0])] = p->data[
              static_cast<int32_T>(d_k + p->size[0])] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 1))] = z->data[d_k];
          }

          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 3))] = state_0 + S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(count - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 2))] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(tempMotionLength_data_tmp -
                1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 5))] = -e_b;
          }
        } else if (PreemptableMissionModeSelector_strcmp_m2jucf
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size) ||
                   PreemptableMissionModeSelector_strcmp_m2jucfmm
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = S->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples,
            d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            tempSamples->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S->size[0] - 1); d_k =
               static_cast<int32_T>(d_k + 1)) {
            tempSamples->data[d_k] = std::sin(tempSamples->data[d_k]);
          }

          d_k = e_x->size[0];
          e_x->size[0] = S->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(e_x, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            e_x->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S->size[0] - 1); d_k =
               static_cast<int32_T>(d_k + 1)) {
            e_x->data[d_k] = std::cos(e_x->data[d_k]);
          }

          d_k = static_cast<int32_T>(S_0->size[0] * S_0->size[1]);
          S_0->size[0] = tempSamples->size[0];
          S_0->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S_0, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[d_k] = tempSamples->data[d_k];
          }

          loop_ub = e_x->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[static_cast<int32_T>(d_k + tempSamples->size[0])] =
              e_x->data[d_k] - 1.0;
          }

          PreemptableMissionModeSelector_mtimes(S_0, TransformMatrix, p);
          e_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          state_0 = state[3];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          loop_ub = p->size[0];
          d_k = static_cast<int32_T>(ns->size[0] * ns->size[1]);
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ns, d_k);
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[static_cast<int32_T>(d_k + ns->size[0])] = p->data[
              static_cast<int32_T>(d_k + p->size[0])] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 1))] = z->data[d_k];
          }

          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 3))] = state_0 - S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(count - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 2))] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(tempMotionLength_data_tmp -
                1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 5))] = e_b;
          }
        } else if (PreemptableMissionModeSelector_strcmp_m2jucfmmw
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          count = S->size[0];
          d_k = static_cast<int32_T>(S_0->size[0] * S_0->size[1]);
          S_0->size[0] = S->size[0];
          S_0->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S_0, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(count - 1); d_k++) {
            S_0->data[static_cast<int32_T>(d_k + S->size[0])] = 0.0;
          }

          PreemptableMissionModeSelector_mtimes(S_0, TransformMatrix, p);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          S_idx_0 = S->size[0];
          loop_ub = p->size[0];
          d_k = static_cast<int32_T>(ns->size[0] * ns->size[1]);
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ns, d_k);
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[static_cast<int32_T>(d_k + ns->size[0])] = p->data[
              static_cast<int32_T>(d_k + p->size[0])] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 1))] = z->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(count - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 3))] = state[3];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(tempMotionLength_data_tmp -
                1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 2))] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S_idx_0 - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 5))] = 0.0;
          }
        }

        if (ab->size[1] != 0) {
          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k < 6; d_k++) {
            for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                 loop_ub; tempMotionLength_data_tmp++) {
              poses->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
                int32_T>(count + tempMotionLength_data_tmp) +
                static_cast<int32_T>(poses->size[0] * d_k)) - 1)] = ns->data[
                static_cast<int32_T>(tempMotionLength_data_tmp +
                static_cast<int32_T>(ns->size[0] * d_k))];
            }
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[static_cast<int32_T>(static_cast<int32_T>(count + d_k) -
              1)] = ns->data[d_k];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[static_cast<int32_T>(static_cast<int32_T>
              (static_cast<int32_T>(count + d_k) + poses->size[0]) - 1)] =
              -ns->data[static_cast<int32_T>(d_k + ns->size[0])];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[static_cast<int32_T>(static_cast<int32_T>
              (static_cast<int32_T>(count + d_k) + static_cast<int32_T>
               (poses->size[0] << 1)) - 1)] = -ns->data[static_cast<int32_T>(d_k
              + static_cast<int32_T>(ns->size[0] << 1))];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[static_cast<int32_T>(static_cast<int32_T>
              (static_cast<int32_T>(count + d_k) + static_cast<int32_T>
               (poses->size[0] * 3)) - 1)] = -ns->data[static_cast<int32_T>(d_k
              + static_cast<int32_T>(ns->size[0] * 3))];
          }
        }

        count = ns->size[0];
        for (d_k = 0; d_k < 6; d_k++) {
          state[d_k] = ns->data[static_cast<int32_T>(static_cast<int32_T>(count
            + static_cast<int32_T>(ns->size[0] * d_k)) - 1)];
        }

        startIndex += static_cast<real_T>(ab->size[1]);
      }

      intermediateLength += tempMotionLength_data[poses_0];
      poses_0 = static_cast<int32_T>(poses_0 + 1);
    }

    PreemptableMissionModeSelector_emxFree_real_T_n(&S_0);
    PreemptableMissionModeSelector_emxFree_boolean_T(&tempSamplesIndex_0);
    PreemptableMissionModeSelector_emxFree_int32_T(&ab);
    PreemptableMissionModeSelector_emxFree_real_T_n(&e_x);
    PreemptableMissionModeSelector_emxFree_real_T_n(&p);
    PreemptableMissionModeSelector_emxFree_real_T_n(&z);
    PreemptableMissionModeSelector_emxFree_real_T_n(&ns);
    PreemptableMissionModeSelector_emxFree_real_T_n(&S);
    PreemptableMissionModeSelector_emxFree_boolean_T(&tempSamplesIndex);
    loop_ub = poses->size[0];
    d_k = tempSamples->size[0];
    tempSamples->size[0] = poses->size[0];
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples, d_k);
    for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
      tempSamples->data[d_k] = poses->data[static_cast<int32_T>(d_k +
        static_cast<int32_T>(poses->size[0] * 3))];
    }

    PreemptableMissionModeSelector_wrapToPi(tempSamples);
    loop_ub = tempSamples->size[0];
    for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
      poses->data[static_cast<int32_T>(d_k + static_cast<int32_T>(poses->size[0]
        * 3))] = tempSamples->data[d_k];
    }

    PreemptableMissionModeSelector_emxFree_real_T_n(&tempSamples);
  }
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_genSegWP(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *connectionObj, const
  real_T start[4], const real_T ende[4], real_T b_stepSize,
  emxArray_real_T_PreemptableMissionModeSelector_T *segWayPoints,
  B_PreemptableMissionModeSelector_c_T *localB)
{
  emxArray_real_T_PreemptableMissionModeSelector_T *lengths;
  emxArray_real_T_PreemptableMissionModeSelector_T *poses;
  real_T a__2_data[28];
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T realStepSize;
  int32_T a__2_size;
  int32_T k;
  int32_T nm1d2;
  boolean_T guard1{ false };

  PreemptableMissionModeSelector_uavDubinsConnection_connect(connectionObj,
    start, ende, localB->pathSegObj_g.data, &localB->pathSegObj_g.size,
    a__2_data, &a__2_size, localB);
  realStepSize = localB->pathSegObj_g.data[0].Length / std::round
    (localB->pathSegObj_g.data[0].Length / b_stepSize);
  PreemptableMissionModeSelector_emxInit_real_T_h(&lengths, 2);
  if (std::isnan(realStepSize)) {
    nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
    lengths->size[0] = 1;
    lengths->size[1] = 1;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
    lengths->data[0] = (rtNaN);
  } else if (std::isnan(localB->pathSegObj_g.data[0].Length)) {
    nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
    lengths->size[0] = 1;
    lengths->size[1] = 1;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
    lengths->data[0] = (rtNaN);
  } else if (realStepSize == 0.0) {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else if ((0.0 < localB->pathSegObj_g.data[0].Length) && (realStepSize < 0.0))
  {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else if ((localB->pathSegObj_g.data[0].Length < 0.0) && (realStepSize > 0.0))
  {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else {
    guard1 = false;
    if (std::isinf(localB->pathSegObj_g.data[0].Length)) {
      if (std::isinf(realStepSize)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
      } else if (0.0 == localB->pathSegObj_g.data[0].Length) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (std::isinf(realStepSize)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = 0.0;
      } else if (std::floor(realStepSize) == realStepSize) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        k = static_cast<int32_T>(std::floor(localB->pathSegObj_g.data[0].Length /
          realStepSize));
        lengths->size[1] = static_cast<int32_T>(k + 1);
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        for (a__2_size = 0; a__2_size <= k; a__2_size++) {
          lengths->data[a__2_size] = realStepSize * static_cast<real_T>
            (a__2_size);
        }
      } else {
        ndbl = std::floor(localB->pathSegObj_g.data[0].Length / realStepSize +
                          0.5);
        apnd = ndbl * realStepSize;
        if (realStepSize > 0.0) {
          cdiff = apnd - localB->pathSegObj_g.data[0].Length;
        } else {
          cdiff = localB->pathSegObj_g.data[0].Length - apnd;
        }

        if (std::abs(cdiff) < 4.4408920985006262E-16 * std::abs
            (localB->pathSegObj_g.data[0].Length)) {
          ndbl++;
          apnd = localB->pathSegObj_g.data[0].Length;
        } else if (cdiff > 0.0) {
          apnd = (ndbl - 1.0) * realStepSize;
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          a__2_size = static_cast<int32_T>(static_cast<int32_T>(ndbl) - 1);
        } else {
          a__2_size = -1;
        }

        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = static_cast<int32_T>(a__2_size + 1);
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        if (static_cast<int32_T>(a__2_size + 1) > 0) {
          lengths->data[0] = 0.0;
          if (static_cast<int32_T>(a__2_size + 1) > 1) {
            lengths->data[a__2_size] = apnd;
            nm1d2 = static_cast<int32_T>(a__2_size / 2);
            for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>
                 (nm1d2 - 2); k = static_cast<int32_T>(k + 1)) {
              ndbl = static_cast<real_T>(k) * realStepSize;
              lengths->data[k] = ndbl;
              lengths->data[static_cast<int32_T>(a__2_size - k)] = apnd - ndbl;
            }

            if (static_cast<int32_T>(nm1d2 << 1) == a__2_size) {
              lengths->data[nm1d2] = apnd / 2.0;
            } else {
              ndbl = static_cast<real_T>(nm1d2) * realStepSize;
              lengths->data[nm1d2] = ndbl;
              lengths->data[static_cast<int32_T>(nm1d2 + 1)] = apnd - ndbl;
            }
          }
        }
      }
    }
  }

  PreemptableMissionModeSelector_emxInit_real_T_h(&poses, 2);
  PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate_p
    (localB->pathSegObj_g.data[0].StartPose, localB->pathSegObj_g.data[0].
     GoalPose, localB->pathSegObj_g.data[0].FlightPathAngle,
     localB->pathSegObj_g.data[0].AirSpeed, localB->pathSegObj_g.data[0].
     MinTurningRadius, localB->pathSegObj_g.data[0].HelixRadius,
     localB->pathSegObj_g.data[0].MotionTypes, localB->pathSegObj_g.data[0].
     MotionLengths, localB->pathSegObj_g.data[0].Length, lengths, poses);
  k = poses->size[0];
  nm1d2 = static_cast<int32_T>(segWayPoints->size[0] * segWayPoints->size[1]);
  segWayPoints->size[0] = poses->size[0];
  segWayPoints->size[1] = 3;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(segWayPoints, nm1d2);
  PreemptableMissionModeSelector_emxFree_real_T_n(&lengths);
  for (a__2_size = 0; a__2_size < 3; a__2_size++) {
    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(k - 1); nm1d2++) {
      segWayPoints->data[static_cast<int32_T>(nm1d2 + static_cast<int32_T>
        (segWayPoints->size[0] * a__2_size))] = poses->data[static_cast<int32_T>
        (nm1d2 + static_cast<int32_T>(poses->size[0] * a__2_size))];
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&poses);
}

// Function for MATLAB Function: '<S117>/WayPointGenerator'
static void
  PreemptableMissionModeSelector_uavDubinsPathSegment_uavDubinsPathSegment_fw(
  const real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3,
  real_T varargin_4, real_T varargin_5, real_T varargin_6, const
  cell_wrap_10_PreemptableMissionModeSelector_T varargin_7[4], const real_T
  varargin_8[4], uavDubinsPathSegment_PreemptableMissionModeSelector_b_T *b_this)
{
  static const char_T d[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A',
    'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
    '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '{', '|', '}',
    '~', '\x7f' };

  real_T thetaWrap;
  int32_T k;
  b_this->MinTurningRadius = varargin_5;
  b_this->StartPose[0] = varargin_1[0];
  b_this->StartPose[1] = varargin_1[1];
  b_this->StartPose[2] = varargin_1[2];
  thetaWrap = mod_dBqh4Vat(varargin_1[3]);
  b_this->StartPose[3] = thetaWrap;
  if ((thetaWrap == 0.0) && (varargin_1[3] > 0.0)) {
    b_this->StartPose[3] = 6.2831853071795862;
  }

  wrapToPi_iEuDNbvh(&b_this->StartPose[3]);
  b_this->GoalPose[0] = varargin_2[0];
  b_this->GoalPose[1] = varargin_2[1];
  b_this->GoalPose[2] = varargin_2[2];
  thetaWrap = mod_dBqh4Vat(varargin_2[3]);
  b_this->GoalPose[3] = thetaWrap;
  if ((thetaWrap == 0.0) && (varargin_2[3] > 0.0)) {
    b_this->GoalPose[3] = 6.2831853071795862;
  }

  wrapToPi_iEuDNbvh(&b_this->GoalPose[3]);
  b_this->AirSpeed = varargin_4;
  b_this->HelixRadius = varargin_6;
  b_this->FlightPathAngle = varargin_3;
  b_this->MotionLengths[0] = varargin_8[0];
  b_this->MotionTypes[0] = varargin_7[0];
  b_this->MotionLengths[1] = varargin_8[1];
  b_this->MotionTypes[1] = varargin_7[1];
  b_this->MotionLengths[2] = varargin_8[2];
  b_this->MotionTypes[2] = varargin_7[2];
  b_this->MotionLengths[3] = varargin_8[3];
  b_this->MotionTypes[3] = varargin_7[3];
  b_this->MotionTypes[0].f1.size[0] = 1;
  b_this->MotionTypes[0].f1.size[1] = varargin_7[0].f1.size[1];
  for (k = 0; k <= static_cast<int32_T>(varargin_7[0].f1.size[1] - 1); k =
       static_cast<int32_T>(k + 1)) {
    b_this->MotionTypes[0].f1.data[k] = d[static_cast<int32_T>(static_cast<
      uint8_T>(varargin_7[0].f1.data[k]))];
  }

  b_this->MotionTypes[1].f1.size[0] = 1;
  b_this->MotionTypes[1].f1.size[1] = 1;
  b_this->MotionTypes[1].f1.data[0] = d[static_cast<int32_T>(static_cast<int32_T>
    (static_cast<uint8_T>(varargin_7[1].f1.data[0])) & 127)];
  b_this->MotionTypes[2].f1.size[0] = 1;
  b_this->MotionTypes[2].f1.size[1] = 1;
  b_this->MotionTypes[2].f1.data[0] = d[static_cast<int32_T>(static_cast<int32_T>
    (static_cast<uint8_T>(varargin_7[2].f1.data[0])) & 127)];
  b_this->MotionTypes[3].f1.size[0] = 1;
  b_this->MotionTypes[3].f1.size[1] = varargin_7[3].f1.size[1];
  for (k = 0; k <= static_cast<int32_T>(varargin_7[3].f1.size[1] - 1); k =
       static_cast<int32_T>(k + 1)) {
    b_this->MotionTypes[3].f1.data[k] = d[static_cast<int32_T>(static_cast<
      uint8_T>(varargin_7[3].f1.data[k]))];
  }

  if (PreemptableMissionModeSelector_strcmp_m(b_this->MotionTypes[0].f1.data,
       b_this->MotionTypes[0].f1.size)) {
    b_this->MotionTypes[0].f1.size[0] = 1;
    b_this->MotionTypes[0].f1.size[1] = 2;
    b_this->MotionTypes[0].f1.data[0] = 'H';
    b_this->MotionTypes[0].f1.data[1] = 'l';
  } else if (PreemptableMissionModeSelector_strcmp_m2(b_this->MotionTypes[0].
              f1.data, b_this->MotionTypes[0].f1.size)) {
    b_this->MotionTypes[0].f1.size[0] = 1;
    b_this->MotionTypes[0].f1.size[1] = 2;
    b_this->MotionTypes[0].f1.data[0] = 'H';
    b_this->MotionTypes[0].f1.data[1] = 'r';
  } else if (PreemptableMissionModeSelector_strcmp_m2(b_this->MotionTypes[3].
              f1.data, b_this->MotionTypes[3].f1.size)) {
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = 2;
    b_this->MotionTypes[3].f1.data[0] = 'H';
    b_this->MotionTypes[3].f1.data[1] = 'r';
  } else if (PreemptableMissionModeSelector_strcmp_m(b_this->MotionTypes[3].
              f1.data, b_this->MotionTypes[3].f1.size)) {
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = 2;
    b_this->MotionTypes[3].f1.data[0] = 'H';
    b_this->MotionTypes[3].f1.data[1] = 'l';
  }

  b_this->Length = ((varargin_8[0] + varargin_8[1]) + varargin_8[2]) +
    varargin_8[3];
}

// Function for MATLAB Function: '<S117>/WayPointGenerator'
static void PreemptableMissionModeSelector_uavDubinsBuiltins_connect_i(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *obj, const real_T
  startPose[4], const real_T goalPose[4], boolean_T flagOptimal, real_T
  turningRadius, const real_T dpt_data[], const int32_T *dpt_size,
  uavDubinsPathSegment_PreemptableMissionModeSelector_b_T pathSegObjs_data[],
  int32_T *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
  B_PreemptableMissionModeSelector_c_T *localB)
{
  void* buildableObj_UAVDubinsBuildableObj;
  cell_wrap_10_PreemptableMissionModeSelector_T m[4];
  cell_wrap_10_PreemptableMissionModeSelector_T ac;
  cell_wrap_10_PreemptableMissionModeSelector_T ad;
  cell_wrap_10_PreemptableMissionModeSelector_T ae;
  cell_wrap_10_PreemptableMissionModeSelector_T af;
  cell_wrap_10_PreemptableMissionModeSelector_T bc;
  cell_wrap_10_PreemptableMissionModeSelector_T bd;
  cell_wrap_10_PreemptableMissionModeSelector_T be;
  cell_wrap_10_PreemptableMissionModeSelector_T bf;
  cell_wrap_10_PreemptableMissionModeSelector_T cc;
  cell_wrap_10_PreemptableMissionModeSelector_T cd;
  cell_wrap_10_PreemptableMissionModeSelector_T ce;
  cell_wrap_10_PreemptableMissionModeSelector_T cf;
  cell_wrap_10_PreemptableMissionModeSelector_T dc;
  cell_wrap_10_PreemptableMissionModeSelector_T dd;
  cell_wrap_10_PreemptableMissionModeSelector_T de;
  cell_wrap_10_PreemptableMissionModeSelector_T df;
  cell_wrap_10_PreemptableMissionModeSelector_T ec;
  cell_wrap_10_PreemptableMissionModeSelector_T ed;
  cell_wrap_10_PreemptableMissionModeSelector_T ee;
  cell_wrap_10_PreemptableMissionModeSelector_T ef;
  cell_wrap_10_PreemptableMissionModeSelector_T fc;
  cell_wrap_10_PreemptableMissionModeSelector_T fd;
  cell_wrap_10_PreemptableMissionModeSelector_T fe;
  cell_wrap_10_PreemptableMissionModeSelector_T ff;
  cell_wrap_10_PreemptableMissionModeSelector_T gc;
  cell_wrap_10_PreemptableMissionModeSelector_T gd;
  cell_wrap_10_PreemptableMissionModeSelector_T ge;
  cell_wrap_10_PreemptableMissionModeSelector_T gf;
  cell_wrap_10_PreemptableMissionModeSelector_T hc;
  cell_wrap_10_PreemptableMissionModeSelector_T hd;
  cell_wrap_10_PreemptableMissionModeSelector_T he;
  cell_wrap_10_PreemptableMissionModeSelector_T hf;
  cell_wrap_10_PreemptableMissionModeSelector_T ic;
  cell_wrap_10_PreemptableMissionModeSelector_T id;
  cell_wrap_10_PreemptableMissionModeSelector_T ie;
  cell_wrap_10_PreemptableMissionModeSelector_T jc;
  cell_wrap_10_PreemptableMissionModeSelector_T jd;
  cell_wrap_10_PreemptableMissionModeSelector_T je;
  cell_wrap_10_PreemptableMissionModeSelector_T jf;
  cell_wrap_10_PreemptableMissionModeSelector_T kb;
  cell_wrap_10_PreemptableMissionModeSelector_T kc;
  cell_wrap_10_PreemptableMissionModeSelector_T kd;
  cell_wrap_10_PreemptableMissionModeSelector_T ke;
  cell_wrap_10_PreemptableMissionModeSelector_T kf;
  cell_wrap_10_PreemptableMissionModeSelector_T lb;
  cell_wrap_10_PreemptableMissionModeSelector_T lc;
  cell_wrap_10_PreemptableMissionModeSelector_T ld;
  cell_wrap_10_PreemptableMissionModeSelector_T le;
  cell_wrap_10_PreemptableMissionModeSelector_T lf;
  cell_wrap_10_PreemptableMissionModeSelector_T mb;
  cell_wrap_10_PreemptableMissionModeSelector_T mc;
  cell_wrap_10_PreemptableMissionModeSelector_T md;
  cell_wrap_10_PreemptableMissionModeSelector_T me;
  cell_wrap_10_PreemptableMissionModeSelector_T mf;
  cell_wrap_10_PreemptableMissionModeSelector_T nb;
  cell_wrap_10_PreemptableMissionModeSelector_T nc;
  cell_wrap_10_PreemptableMissionModeSelector_T nd;
  cell_wrap_10_PreemptableMissionModeSelector_T ne;
  cell_wrap_10_PreemptableMissionModeSelector_T nf;
  cell_wrap_10_PreemptableMissionModeSelector_T ob;
  cell_wrap_10_PreemptableMissionModeSelector_T oc;
  cell_wrap_10_PreemptableMissionModeSelector_T od;
  cell_wrap_10_PreemptableMissionModeSelector_T oe;
  cell_wrap_10_PreemptableMissionModeSelector_T of;
  cell_wrap_10_PreemptableMissionModeSelector_T pb;
  cell_wrap_10_PreemptableMissionModeSelector_T pc;
  cell_wrap_10_PreemptableMissionModeSelector_T pd;
  cell_wrap_10_PreemptableMissionModeSelector_T pe;
  cell_wrap_10_PreemptableMissionModeSelector_T pf;
  cell_wrap_10_PreemptableMissionModeSelector_T qb;
  cell_wrap_10_PreemptableMissionModeSelector_T qc;
  cell_wrap_10_PreemptableMissionModeSelector_T qd;
  cell_wrap_10_PreemptableMissionModeSelector_T qe;
  cell_wrap_10_PreemptableMissionModeSelector_T qf;
  cell_wrap_10_PreemptableMissionModeSelector_T rb;
  cell_wrap_10_PreemptableMissionModeSelector_T rc;
  cell_wrap_10_PreemptableMissionModeSelector_T rd;
  cell_wrap_10_PreemptableMissionModeSelector_T re;
  cell_wrap_10_PreemptableMissionModeSelector_T rf;
  cell_wrap_10_PreemptableMissionModeSelector_T sb;
  cell_wrap_10_PreemptableMissionModeSelector_T sc;
  cell_wrap_10_PreemptableMissionModeSelector_T sd;
  cell_wrap_10_PreemptableMissionModeSelector_T se;
  cell_wrap_10_PreemptableMissionModeSelector_T sf;
  cell_wrap_10_PreemptableMissionModeSelector_T tb;
  cell_wrap_10_PreemptableMissionModeSelector_T tc;
  cell_wrap_10_PreemptableMissionModeSelector_T td;
  cell_wrap_10_PreemptableMissionModeSelector_T te;
  cell_wrap_10_PreemptableMissionModeSelector_T tf;
  cell_wrap_10_PreemptableMissionModeSelector_T ub;
  cell_wrap_10_PreemptableMissionModeSelector_T uc;
  cell_wrap_10_PreemptableMissionModeSelector_T ud;
  cell_wrap_10_PreemptableMissionModeSelector_T ue;
  cell_wrap_10_PreemptableMissionModeSelector_T uf;
  cell_wrap_10_PreemptableMissionModeSelector_T vb;
  cell_wrap_10_PreemptableMissionModeSelector_T vc;
  cell_wrap_10_PreemptableMissionModeSelector_T vd;
  cell_wrap_10_PreemptableMissionModeSelector_T ve;
  cell_wrap_10_PreemptableMissionModeSelector_T vf;
  cell_wrap_10_PreemptableMissionModeSelector_T wb;
  cell_wrap_10_PreemptableMissionModeSelector_T wc;
  cell_wrap_10_PreemptableMissionModeSelector_T wd;
  cell_wrap_10_PreemptableMissionModeSelector_T we;
  cell_wrap_10_PreemptableMissionModeSelector_T wf;
  cell_wrap_10_PreemptableMissionModeSelector_T xb;
  cell_wrap_10_PreemptableMissionModeSelector_T xc;
  cell_wrap_10_PreemptableMissionModeSelector_T xd;
  cell_wrap_10_PreemptableMissionModeSelector_T xe;
  cell_wrap_10_PreemptableMissionModeSelector_T yb;
  cell_wrap_10_PreemptableMissionModeSelector_T yc;
  cell_wrap_10_PreemptableMissionModeSelector_T yd;
  cell_wrap_10_PreemptableMissionModeSelector_T ye;
  emxArray_real_T_PreemptableMissionModeSelector_T *g;
  emxArray_real_T_PreemptableMissionModeSelector_T *g1;
  emxArray_real_T_PreemptableMissionModeSelector_T *g_0;
  emxArray_real_T_PreemptableMissionModeSelector_T *ml;
  emxArray_real_T_PreemptableMissionModeSelector_T *ml1;
  emxArray_real_T_PreemptableMissionModeSelector_T *s;
  emxArray_real_T_PreemptableMissionModeSelector_T *s1;
  real_T b_goalPose[4];
  real_T b_startPose[4];
  real_T ml1_0[4];
  real_T ml1_data[4];
  real_T l;
  real_T ml1_tmp;
  int32_T b_nRows;
  int32_T loop_ub;
  int32_T mt;
  int32_T mt_size_idx_0;
  int32_T xf_tmp;
  int16_T tmp[2];
  int16_T num_idx_1;
  kb.f1.size[0] = 1;
  kb.f1.size[1] = 1;
  kb.f1.data[0] = 'L';
  lb.f1.size[0] = 1;
  lb.f1.size[1] = 1;
  lb.f1.data[0] = 'S';
  mb.f1.size[0] = 1;
  mb.f1.size[1] = 1;
  mb.f1.data[0] = 'L';
  nb.f1.size[0] = 1;
  nb.f1.size[1] = 1;
  nb.f1.data[0] = 'N';
  ob.f1.size[0] = 1;
  ob.f1.size[1] = 1;
  ob.f1.data[0] = 'L';
  pb.f1.size[0] = 1;
  pb.f1.size[1] = 1;
  pb.f1.data[0] = 'S';
  qb.f1.size[0] = 1;
  qb.f1.size[1] = 1;
  qb.f1.data[0] = 'R';
  rb.f1.size[0] = 1;
  rb.f1.size[1] = 1;
  rb.f1.data[0] = 'N';
  sb.f1.size[0] = 1;
  sb.f1.size[1] = 1;
  sb.f1.data[0] = 'R';
  tb.f1.size[0] = 1;
  tb.f1.size[1] = 1;
  tb.f1.data[0] = 'S';
  ub.f1.size[0] = 1;
  ub.f1.size[1] = 1;
  ub.f1.data[0] = 'L';
  vb.f1.size[0] = 1;
  vb.f1.size[1] = 1;
  vb.f1.data[0] = 'N';
  wb.f1.size[0] = 1;
  wb.f1.size[1] = 1;
  wb.f1.data[0] = 'R';
  xb.f1.size[0] = 1;
  xb.f1.size[1] = 1;
  xb.f1.data[0] = 'S';
  yb.f1.size[0] = 1;
  yb.f1.size[1] = 1;
  yb.f1.data[0] = 'R';
  ac.f1.size[0] = 1;
  ac.f1.size[1] = 1;
  ac.f1.data[0] = 'N';
  bc.f1.size[0] = 1;
  bc.f1.size[1] = 1;
  bc.f1.data[0] = 'R';
  cc.f1.size[0] = 1;
  cc.f1.size[1] = 1;
  cc.f1.data[0] = 'L';
  dc.f1.size[0] = 1;
  dc.f1.size[1] = 1;
  dc.f1.data[0] = 'R';
  ec.f1.size[0] = 1;
  ec.f1.size[1] = 1;
  ec.f1.data[0] = 'N';
  fc.f1.size[0] = 1;
  fc.f1.size[1] = 1;
  fc.f1.data[0] = 'L';
  gc.f1.size[0] = 1;
  gc.f1.size[1] = 1;
  gc.f1.data[0] = 'R';
  hc.f1.size[0] = 1;
  hc.f1.size[1] = 1;
  hc.f1.data[0] = 'L';
  ic.f1.size[0] = 1;
  ic.f1.size[1] = 1;
  ic.f1.data[0] = 'N';
  jc.f1.size[0] = 1;
  jc.f1.size[1] = 2;
  kc.f1.size[0] = 1;
  kc.f1.size[1] = 1;
  kc.f1.data[0] = 'L';
  lc.f1.size[0] = 1;
  lc.f1.size[1] = 1;
  lc.f1.data[0] = 'S';
  mc.f1.size[0] = 1;
  mc.f1.size[1] = 1;
  mc.f1.data[0] = 'L';
  nc.f1.size[0] = 1;
  nc.f1.size[1] = 2;
  oc.f1.size[0] = 1;
  oc.f1.size[1] = 1;
  oc.f1.data[0] = 'L';
  pc.f1.size[0] = 1;
  pc.f1.size[1] = 1;
  pc.f1.data[0] = 'S';
  qc.f1.size[0] = 1;
  qc.f1.size[1] = 1;
  qc.f1.data[0] = 'R';
  rc.f1.size[0] = 1;
  rc.f1.size[1] = 2;
  sc.f1.size[0] = 1;
  sc.f1.size[1] = 1;
  sc.f1.data[0] = 'R';
  tc.f1.size[0] = 1;
  tc.f1.size[1] = 1;
  tc.f1.data[0] = 'S';
  uc.f1.size[0] = 1;
  uc.f1.size[1] = 1;
  uc.f1.data[0] = 'L';
  vc.f1.size[0] = 1;
  vc.f1.size[1] = 2;
  wc.f1.size[0] = 1;
  wc.f1.size[1] = 1;
  wc.f1.data[0] = 'R';
  xc.f1.size[0] = 1;
  xc.f1.size[1] = 1;
  xc.f1.data[0] = 'S';
  yc.f1.size[0] = 1;
  yc.f1.size[1] = 1;
  yc.f1.data[0] = 'R';
  ad.f1.size[0] = 1;
  ad.f1.size[1] = 2;
  bd.f1.size[0] = 1;
  bd.f1.size[1] = 1;
  bd.f1.data[0] = 'R';
  cd.f1.size[0] = 1;
  cd.f1.size[1] = 1;
  cd.f1.data[0] = 'L';
  dd.f1.size[0] = 1;
  dd.f1.size[1] = 1;
  dd.f1.data[0] = 'R';
  ed.f1.size[0] = 1;
  ed.f1.size[1] = 2;
  fd.f1.size[0] = 1;
  fd.f1.size[1] = 1;
  fd.f1.data[0] = 'L';
  gd.f1.size[0] = 1;
  gd.f1.size[1] = 1;
  gd.f1.data[0] = 'R';
  hd.f1.size[0] = 1;
  hd.f1.size[1] = 1;
  hd.f1.data[0] = 'L';
  id.f1.size[0] = 1;
  id.f1.size[1] = 1;
  id.f1.data[0] = 'L';
  jd.f1.size[0] = 1;
  jd.f1.size[1] = 1;
  jd.f1.data[0] = 'S';
  kd.f1.size[0] = 1;
  kd.f1.size[1] = 1;
  kd.f1.data[0] = 'L';
  ld.f1.size[0] = 1;
  ld.f1.size[1] = 2;
  md.f1.size[0] = 1;
  md.f1.size[1] = 1;
  md.f1.data[0] = 'L';
  nd.f1.size[0] = 1;
  nd.f1.size[1] = 1;
  nd.f1.data[0] = 'S';
  od.f1.size[0] = 1;
  od.f1.size[1] = 1;
  od.f1.data[0] = 'R';
  pd.f1.size[0] = 1;
  pd.f1.size[1] = 2;
  qd.f1.size[0] = 1;
  qd.f1.size[1] = 1;
  qd.f1.data[0] = 'R';
  rd.f1.size[0] = 1;
  rd.f1.size[1] = 1;
  rd.f1.data[0] = 'S';
  sd.f1.size[0] = 1;
  sd.f1.size[1] = 1;
  sd.f1.data[0] = 'L';
  td.f1.size[0] = 1;
  td.f1.size[1] = 2;
  ud.f1.size[0] = 1;
  ud.f1.size[1] = 1;
  ud.f1.data[0] = 'R';
  vd.f1.size[0] = 1;
  vd.f1.size[1] = 1;
  vd.f1.data[0] = 'S';
  wd.f1.size[0] = 1;
  wd.f1.size[1] = 1;
  wd.f1.data[0] = 'R';
  xd.f1.size[0] = 1;
  xd.f1.size[1] = 2;
  yd.f1.size[0] = 1;
  yd.f1.size[1] = 1;
  yd.f1.data[0] = 'R';
  ae.f1.size[0] = 1;
  ae.f1.size[1] = 1;
  ae.f1.data[0] = 'L';
  be.f1.size[0] = 1;
  be.f1.size[1] = 1;
  be.f1.data[0] = 'R';
  ce.f1.size[0] = 1;
  ce.f1.size[1] = 2;
  de.f1.size[0] = 1;
  de.f1.size[1] = 1;
  de.f1.data[0] = 'L';
  ee.f1.size[0] = 1;
  ee.f1.size[1] = 1;
  ee.f1.data[0] = 'R';
  fe.f1.size[0] = 1;
  fe.f1.size[1] = 1;
  fe.f1.data[0] = 'L';
  ge.f1.size[0] = 1;
  ge.f1.size[1] = 2;
  jc.f1.data[0] = 'H';
  nc.f1.data[0] = 'H';
  rc.f1.data[0] = 'H';
  vc.f1.data[0] = 'H';
  ad.f1.data[0] = 'H';
  ed.f1.data[0] = 'H';
  ld.f1.data[0] = 'H';
  pd.f1.data[0] = 'H';
  td.f1.data[0] = 'H';
  xd.f1.data[0] = 'H';
  ce.f1.data[0] = 'H';
  ge.f1.data[0] = 'H';
  jc.f1.data[1] = 'l';
  nc.f1.data[1] = 'l';
  rc.f1.data[1] = 'r';
  vc.f1.data[1] = 'r';
  ad.f1.data[1] = 'r';
  ed.f1.data[1] = 'l';
  ld.f1.data[1] = 'l';
  pd.f1.data[1] = 'r';
  td.f1.data[1] = 'l';
  xd.f1.data[1] = 'r';
  ce.f1.data[1] = 'r';
  ge.f1.data[1] = 'l';
  he.f1.size[0] = 1;
  he.f1.size[1] = 1;
  he.f1.data[0] = 'L';
  ie.f1.size[0] = 1;
  ie.f1.size[1] = 1;
  ie.f1.data[0] = 'R';
  je.f1.size[0] = 1;
  je.f1.size[1] = 1;
  je.f1.data[0] = 'S';
  ke.f1.size[0] = 1;
  ke.f1.size[1] = 1;
  ke.f1.data[0] = 'L';
  le.f1.size[0] = 1;
  le.f1.size[1] = 1;
  le.f1.data[0] = 'L';
  me.f1.size[0] = 1;
  me.f1.size[1] = 1;
  me.f1.data[0] = 'R';
  ne.f1.size[0] = 1;
  ne.f1.size[1] = 1;
  ne.f1.data[0] = 'S';
  oe.f1.size[0] = 1;
  oe.f1.size[1] = 1;
  oe.f1.data[0] = 'R';
  pe.f1.size[0] = 1;
  pe.f1.size[1] = 1;
  pe.f1.data[0] = 'L';
  qe.f1.size[0] = 1;
  qe.f1.size[1] = 1;
  qe.f1.data[0] = 'R';
  re.f1.size[0] = 1;
  re.f1.size[1] = 1;
  re.f1.data[0] = 'L';
  se.f1.size[0] = 1;
  se.f1.size[1] = 1;
  se.f1.data[0] = 'R';
  te.f1.size[0] = 1;
  te.f1.size[1] = 1;
  te.f1.data[0] = 'R';
  ue.f1.size[0] = 1;
  ue.f1.size[1] = 1;
  ue.f1.data[0] = 'L';
  ve.f1.size[0] = 1;
  ve.f1.size[1] = 1;
  ve.f1.data[0] = 'S';
  we.f1.size[0] = 1;
  we.f1.size[1] = 1;
  we.f1.data[0] = 'R';
  xe.f1.size[0] = 1;
  xe.f1.size[1] = 1;
  xe.f1.data[0] = 'R';
  ye.f1.size[0] = 1;
  ye.f1.size[1] = 1;
  ye.f1.data[0] = 'L';
  af.f1.size[0] = 1;
  af.f1.size[1] = 1;
  af.f1.data[0] = 'R';
  bf.f1.size[0] = 1;
  bf.f1.size[1] = 1;
  bf.f1.data[0] = 'L';
  cf.f1.size[0] = 1;
  cf.f1.size[1] = 1;
  cf.f1.data[0] = 'R';
  df.f1.size[0] = 1;
  df.f1.size[1] = 1;
  df.f1.data[0] = 'L';
  ef.f1.size[0] = 1;
  ef.f1.size[1] = 1;
  ef.f1.data[0] = 'S';
  ff.f1.size[0] = 1;
  ff.f1.size[1] = 1;
  ff.f1.data[0] = 'L';
  gf.f1.size[0] = 1;
  gf.f1.size[1] = 1;
  gf.f1.data[0] = 'L';
  hf.f1.size[0] = 1;
  hf.f1.size[1] = 1;
  hf.f1.data[0] = 'S';
  jf.f1.size[0] = 1;
  jf.f1.size[1] = 1;
  jf.f1.data[0] = 'R';
  kf.f1.size[0] = 1;
  kf.f1.size[1] = 1;
  kf.f1.data[0] = 'L';
  lf.f1.size[0] = 1;
  lf.f1.size[1] = 1;
  lf.f1.data[0] = 'R';
  mf.f1.size[0] = 1;
  mf.f1.size[1] = 1;
  mf.f1.data[0] = 'S';
  nf.f1.size[0] = 1;
  nf.f1.size[1] = 1;
  nf.f1.data[0] = 'R';
  of.f1.size[0] = 1;
  of.f1.size[1] = 1;
  of.f1.data[0] = 'L';
  pf.f1.size[0] = 1;
  pf.f1.size[1] = 1;
  pf.f1.data[0] = 'L';
  qf.f1.size[0] = 1;
  qf.f1.size[1] = 1;
  qf.f1.data[0] = 'S';
  rf.f1.size[0] = 1;
  rf.f1.size[1] = 1;
  rf.f1.data[0] = 'L';
  sf.f1.size[0] = 1;
  sf.f1.size[1] = 1;
  sf.f1.data[0] = 'R';
  tf.f1.size[0] = 1;
  tf.f1.size[1] = 1;
  tf.f1.data[0] = 'R';
  uf.f1.size[0] = 1;
  uf.f1.size[1] = 1;
  uf.f1.data[0] = 'S';
  vf.f1.size[0] = 1;
  vf.f1.size[1] = 1;
  vf.f1.data[0] = 'L';
  wf.f1.size[0] = 1;
  wf.f1.size[1] = 1;
  wf.f1.data[0] = 'R';
  buildableObj_UAVDubinsBuildableObj =
    PreemptableMissionModeSelector_uavDubinsBuildable_uavDubinsBuildable
    (obj->AirSpeed, obj->MaxRollAngle, obj->FlightPathAngleLimit, dpt_data,
     dpt_size);
  b_startPose[0] = startPose[0];
  b_goalPose[0] = goalPose[0];
  b_startPose[1] = startPose[1];
  b_goalPose[1] = goalPose[1];
  b_startPose[2] = startPose[2];
  b_goalPose[2] = goalPose[2];
  b_startPose[3] = startPose[3];
  b_goalPose[3] = goalPose[3];
  b_nRows = 1;
  if (!flagOptimal) {
    b_nRows = 28;
  }

  PreemptableMissionModeSelector_emxInit_real_T_h(&s, 2);
  PreemptableMissionModeSelector_emxInit_real_T_h(&g, 2);
  PreemptableMissionModeSelector_emxInit_real_T_h(&ml, 2);
  xf_tmp = static_cast<int32_T>(b_nRows << 2);
  mt = static_cast<int32_T>(s->size[0] * s->size[1]);
  s->size[0] = xf_tmp;
  s->size[1] = xf_tmp;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(s, mt);
  mt = static_cast<int32_T>(g->size[0] * g->size[1]);
  g->size[0] = xf_tmp;
  g->size[1] = xf_tmp;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g, mt);
  mt_size_idx_0 = b_nRows;
  mt = static_cast<int32_T>(ml->size[0] * ml->size[1]);
  ml->size[0] = xf_tmp;
  ml->size[1] = xf_tmp;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ml, mt);
  uavDubinsDistanceCodegen_real64(buildableObj_UAVDubinsBuildableObj,
    &b_startPose[0], 1U, &b_goalPose[0], 1U, flagOptimal, turningRadius,
    &s->data[0], &g->data[0], &localB->b_fpa_data_f[0], &localB->b_a_data_g[0],
    &localB->mtr_data_g[0], &localB->h_data_m[0], &localB->mt_data_cv[0],
    &ml->data[0]);
  b_nRows = 0;
  if (!flagOptimal) {
    b_nRows = 27;
  }

  PreemptableMissionModeSelector_emxInit_real_T_h(&g1, 2);
  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
    static_cast<int32_T>(s->size[0] * s->size[1])) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = static_cast<int32_T>(g1->size[0] * g1->size[1]);
  g1->size[0] = static_cast<int32_T>(num_idx_1);
  g1->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g1, mt);
  loop_ub = static_cast<int32_T>(num_idx_1);
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt <= static_cast<int32_T>(loop_ub - 1); mt++) {
      g1->data[static_cast<int32_T>(mt + static_cast<int32_T>(g1->size[0] *
        xf_tmp))] = s->data[static_cast<int32_T>(xf_tmp + static_cast<int32_T>(
        static_cast<int32_T>(tmp[0]) * mt))];
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&s);
  PreemptableMissionModeSelector_emxInit_real_T_h(&s1, 2);
  mt = static_cast<int32_T>(s1->size[0] * s1->size[1]);
  s1->size[0] = static_cast<int32_T>(num_idx_1);
  s1->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(s1, mt);
  loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
  for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
    s1->data[xf_tmp] = g1->data[xf_tmp];
  }

  PreemptableMissionModeSelector_emxInit_real_T_h(&g_0, 2);
  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
    static_cast<int32_T>(g->size[0] * g->size[1])) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
  g_0->size[0] = static_cast<int32_T>(num_idx_1);
  g_0->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g_0, mt);
  loop_ub = static_cast<int32_T>(num_idx_1);
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt <= static_cast<int32_T>(loop_ub - 1); mt++) {
      g_0->data[static_cast<int32_T>(mt + static_cast<int32_T>(g_0->size[0] *
        xf_tmp))] = g->data[static_cast<int32_T>(xf_tmp + static_cast<int32_T>(
        static_cast<int32_T>(tmp[0]) * mt))];
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&g);
  mt = static_cast<int32_T>(g1->size[0] * g1->size[1]);
  g1->size[0] = static_cast<int32_T>(num_idx_1);
  g1->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g1, mt);
  loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
  for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
    g1->data[xf_tmp] = g_0->data[xf_tmp];
  }

  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
    static_cast<int32_T>(ml->size[0] * ml->size[1])) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
  g_0->size[0] = static_cast<int32_T>(num_idx_1);
  g_0->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(g_0, mt);
  loop_ub = static_cast<int32_T>(num_idx_1);
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt <= static_cast<int32_T>(loop_ub - 1); mt++) {
      g_0->data[static_cast<int32_T>(mt + static_cast<int32_T>(g_0->size[0] *
        xf_tmp))] = ml->data[static_cast<int32_T>(xf_tmp + static_cast<int32_T>(
        static_cast<int32_T>(tmp[0]) * mt))];
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&ml);
  PreemptableMissionModeSelector_emxInit_real_T_h(&ml1, 2);
  mt = static_cast<int32_T>(ml1->size[0] * ml1->size[1]);
  ml1->size[0] = static_cast<int32_T>(num_idx_1);
  ml1->size[1] = 4;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ml1, mt);
  loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
  for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
    ml1->data[xf_tmp] = g_0->data[xf_tmp];
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&g_0);
  loop_ub = static_cast<int32_T>(mt_size_idx_0 * mt_size_idx_0);
  for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
    localB->mt_data_cv[xf_tmp]++;
  }

  l = 0.0;
  *pathCosts_size = static_cast<int32_T>(b_nRows + 1);
  for (xf_tmp = 0; xf_tmp <= b_nRows; xf_tmp++) {
    pathCosts_data[xf_tmp] = (rtNaN);
  }

  m[0] = kb;
  m[1] = lb;
  m[2] = mb;
  m[3] = nb;
  if (flagOptimal) {
    *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>
      (static_cast<int32_T>(b_nRows + 1)));
    for (xf_tmp = 0; xf_tmp <= b_nRows; xf_tmp = static_cast<int32_T>(xf_tmp + 1))
    {
      l++;
      ml1_tmp = localB->mt_data_cv[static_cast<int32_T>(static_cast<int32_T>(l)
        - 1)];
      if (ml1_tmp == 1.0) {
        m[0] = kb;
        m[1] = lb;
        m[2] = mb;
        m[3] = nb;
      }

      if (ml1_tmp == 2.0) {
        m[0] = ob;
        m[1] = pb;
        m[2] = qb;
        m[3] = rb;
      }

      if (ml1_tmp == 3.0) {
        m[0] = sb;
        m[1] = tb;
        m[2] = ub;
        m[3] = vb;
      }

      if (ml1_tmp == 4.0) {
        m[0] = wb;
        m[1] = xb;
        m[2] = yb;
        m[3] = ac;
      }

      if (ml1_tmp == 5.0) {
        m[0] = bc;
        m[1] = cc;
        m[2] = dc;
        m[3] = ec;
      }

      if (ml1_tmp == 6.0) {
        m[0] = fc;
        m[1] = gc;
        m[2] = hc;
        m[3] = ic;
      }

      if (ml1_tmp == 7.0) {
        m[0] = jc;
        m[1] = kc;
        m[2] = lc;
        m[3] = mc;
      }

      if (ml1_tmp == 8.0) {
        m[0] = nc;
        m[1] = oc;
        m[2] = pc;
        m[3] = qc;
      }

      if (ml1_tmp == 9.0) {
        m[0] = rc;
        m[1] = sc;
        m[2] = tc;
        m[3] = uc;
      }

      if (ml1_tmp == 10.0) {
        m[0] = vc;
        m[1] = wc;
        m[2] = xc;
        m[3] = yc;
      }

      if (ml1_tmp == 11.0) {
        m[0] = ad;
        m[1] = bd;
        m[2] = cd;
        m[3] = dd;
      }

      if (ml1_tmp == 12.0) {
        m[0] = ed;
        m[1] = fd;
        m[2] = gd;
        m[3] = hd;
      }

      if (ml1_tmp == 13.0) {
        m[0] = id;
        m[1] = jd;
        m[2] = kd;
        m[3] = ld;
      }

      if (ml1_tmp == 14.0) {
        m[0] = md;
        m[1] = nd;
        m[2] = od;
        m[3] = pd;
      }

      if (ml1_tmp == 15.0) {
        m[0] = qd;
        m[1] = rd;
        m[2] = sd;
        m[3] = td;
      }

      if (ml1_tmp == 16.0) {
        m[0] = ud;
        m[1] = vd;
        m[2] = wd;
        m[3] = xd;
      }

      if (ml1_tmp == 17.0) {
        m[0] = yd;
        m[1] = ae;
        m[2] = be;
        m[3] = ce;
      }

      if (ml1_tmp == 18.0) {
        m[0] = de;
        m[1] = ee;
        m[2] = fe;
        m[3] = ge;
      }

      if (ml1_tmp == 19.0) {
        m[0] = he;
        m[1] = ie;
        m[2] = je;
        m[3] = ke;
      }

      if (ml1_tmp == 20.0) {
        m[0] = le;
        m[1] = me;
        m[2] = ne;
        m[3] = oe;
      }

      if (ml1_tmp == 21.0) {
        m[0] = pe;
        m[1] = qe;
        m[2] = re;
        m[3] = se;
      }

      if (ml1_tmp == 22.0) {
        m[0] = te;
        m[1] = ue;
        m[2] = ve;
        m[3] = we;
      }

      if (ml1_tmp == 23.0) {
        m[0] = xe;
        m[1] = ye;
        m[2] = af;
        m[3] = bf;
      }

      if (ml1_tmp == 24.0) {
        m[0] = cf;
        m[1] = df;
        m[2] = ef;
        m[3] = ff;
      }

      if (ml1_tmp == 25.0) {
        m[0] = gf;
        m[1] = hf;
        m[2] = jf;
        m[3] = kf;
      }

      if (ml1_tmp == 26.0) {
        m[0] = lf;
        m[1] = mf;
        m[2] = nf;
        m[3] = of;
      }

      if (ml1_tmp == 27.0) {
        m[0] = pf;
        m[1] = qf;
        m[2] = rf;
        m[3] = sf;
      }

      if (ml1_tmp == 28.0) {
        m[0] = tf;
        m[1] = uf;
        m[2] = vf;
        m[3] = wf;
      }

      b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      ml1_0[0] = ml1_tmp;
      ml1_data[0] = ml1_tmp;
      b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + s1->size[0]) - 1)];
      b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + g1->size[0]) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
        int32_T>(l) + ml1->size[0]) - 1)];
      ml1_0[1] = ml1_tmp;
      ml1_data[1] = ml1_tmp;
      b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1)) - 1)];
      b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1)) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>
        (static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1)) - 1)];
      ml1_0[2] = ml1_tmp;
      ml1_data[2] = ml1_tmp;
      b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3)) - 1)];
      b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3)) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
        int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3)) - 1)];
      ml1_0[3] = ml1_tmp;
      ml1_data[3] = ml1_tmp;
      PreemptableMissionModeSelector_uavDubinsPathSegment_uavDubinsPathSegment_fw
        (b_startPose, b_goalPose, localB->b_fpa_data_f[static_cast<int32_T>(
          static_cast<int32_T>(l) - 1)], localB->b_a_data_g[0],
         localB->mtr_data_g[0], localB->h_data_m[static_cast<int32_T>(
          static_cast<int32_T>(l) - 1)], m, ml1_0, &pathSegObjs_data[xf_tmp]);
      pathCosts_data[xf_tmp] = PreemptableMissionModeSelector_sum(ml1_data);
    }
  } else {
    *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>
      (static_cast<int32_T>(b_nRows + 1)));
    for (xf_tmp = 1; static_cast<int32_T>(xf_tmp - 1) <= b_nRows; xf_tmp =
         static_cast<int32_T>(xf_tmp + 1)) {
      l++;
      if (1 == xf_tmp) {
        m[0] = kb;
        m[1] = lb;
        m[2] = mb;
        m[3] = nb;
      }

      if (2 == xf_tmp) {
        m[0] = ob;
        m[1] = pb;
        m[2] = qb;
        m[3] = rb;
      }

      if (3 == xf_tmp) {
        m[0] = sb;
        m[1] = tb;
        m[2] = ub;
        m[3] = vb;
      }

      if (4 == xf_tmp) {
        m[0] = wb;
        m[1] = xb;
        m[2] = yb;
        m[3] = ac;
      }

      if (5 == xf_tmp) {
        m[0] = bc;
        m[1] = cc;
        m[2] = dc;
        m[3] = ec;
      }

      if (6 == xf_tmp) {
        m[0] = fc;
        m[1] = gc;
        m[2] = hc;
        m[3] = ic;
      }

      if (7 == xf_tmp) {
        m[0] = jc;
        m[1] = kc;
        m[2] = lc;
        m[3] = mc;
      }

      if (8 == xf_tmp) {
        m[0] = nc;
        m[1] = oc;
        m[2] = pc;
        m[3] = qc;
      }

      if (9 == xf_tmp) {
        m[0] = rc;
        m[1] = sc;
        m[2] = tc;
        m[3] = uc;
      }

      if (10 == xf_tmp) {
        m[0] = vc;
        m[1] = wc;
        m[2] = xc;
        m[3] = yc;
      }

      if (11 == xf_tmp) {
        m[0] = ad;
        m[1] = bd;
        m[2] = cd;
        m[3] = dd;
      }

      if (12 == xf_tmp) {
        m[0] = ed;
        m[1] = fd;
        m[2] = gd;
        m[3] = hd;
      }

      if (13 == xf_tmp) {
        m[0] = id;
        m[1] = jd;
        m[2] = kd;
        m[3] = ld;
      }

      if (14 == xf_tmp) {
        m[0] = md;
        m[1] = nd;
        m[2] = od;
        m[3] = pd;
      }

      if (15 == xf_tmp) {
        m[0] = qd;
        m[1] = rd;
        m[2] = sd;
        m[3] = td;
      }

      if (16 == xf_tmp) {
        m[0] = ud;
        m[1] = vd;
        m[2] = wd;
        m[3] = xd;
      }

      if (17 == xf_tmp) {
        m[0] = yd;
        m[1] = ae;
        m[2] = be;
        m[3] = ce;
      }

      if (18 == xf_tmp) {
        m[0] = de;
        m[1] = ee;
        m[2] = fe;
        m[3] = ge;
      }

      if (19 == xf_tmp) {
        m[0] = he;
        m[1] = ie;
        m[2] = je;
        m[3] = ke;
      }

      if (20 == xf_tmp) {
        m[0] = le;
        m[1] = me;
        m[2] = ne;
        m[3] = oe;
      }

      if (21 == xf_tmp) {
        m[0] = pe;
        m[1] = qe;
        m[2] = re;
        m[3] = se;
      }

      if (22 == xf_tmp) {
        m[0] = te;
        m[1] = ue;
        m[2] = ve;
        m[3] = we;
      }

      if (23 == xf_tmp) {
        m[0] = xe;
        m[1] = ye;
        m[2] = af;
        m[3] = bf;
      }

      if (24 == xf_tmp) {
        m[0] = cf;
        m[1] = df;
        m[2] = ef;
        m[3] = ff;
      }

      if (25 == xf_tmp) {
        m[0] = gf;
        m[1] = hf;
        m[2] = jf;
        m[3] = kf;
      }

      if (26 == xf_tmp) {
        m[0] = lf;
        m[1] = mf;
        m[2] = nf;
        m[3] = of;
      }

      if (27 == xf_tmp) {
        m[0] = pf;
        m[1] = qf;
        m[2] = rf;
        m[3] = sf;
      }

      if (28 == xf_tmp) {
        m[0] = tf;
        m[1] = uf;
        m[2] = vf;
        m[3] = wf;
      }

      b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
      ml1_0[0] = ml1_tmp;
      ml1_data[0] = ml1_tmp;
      b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + s1->size[0]) - 1)];
      b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + g1->size[0]) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
        int32_T>(l) + ml1->size[0]) - 1)];
      ml1_0[1] = ml1_tmp;
      ml1_data[1] = ml1_tmp;
      b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1)) - 1)];
      b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1)) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>
        (static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1)) - 1)];
      ml1_0[2] = ml1_tmp;
      ml1_data[2] = ml1_tmp;
      b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3)) - 1)];
      b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3)) - 1)];
      ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
        int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3)) - 1)];
      ml1_0[3] = ml1_tmp;
      ml1_data[3] = ml1_tmp;
      PreemptableMissionModeSelector_uavDubinsPathSegment_uavDubinsPathSegment_fw
        (b_startPose, b_goalPose, localB->b_fpa_data_f[static_cast<int32_T>(
          static_cast<int32_T>(l) - 1)], localB->b_a_data_g[0],
         localB->mtr_data_g[0], localB->h_data_m[static_cast<int32_T>(
          static_cast<int32_T>(l) - 1)], m, ml1_0, &pathSegObjs_data[
         static_cast<int32_T>(xf_tmp - 1)]);
      pathCosts_data[static_cast<int32_T>(xf_tmp - 1)] =
        PreemptableMissionModeSelector_sum(ml1_data);
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&ml1);
  PreemptableMissionModeSelector_emxFree_real_T_n(&g1);
  PreemptableMissionModeSelector_emxFree_real_T_n(&s1);
}

// Function for MATLAB Function: '<S117>/WayPointGenerator'
static void PreemptableMissionModeSelector_uavDubinsConnection_connect_j(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *obj, const real_T
  startPoses[4], const real_T goalPoses[4],
  uavDubinsPathSegment_PreemptableMissionModeSelector_b_T pathSegObjs_data[],
  int32_T *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
  B_PreemptableMissionModeSelector_c_T *localB)
{
  matlabshared_autonomous_core_internal_NameValueParser_PreemptableMissionModeSelector_T
    parser;
  real_T idx_data[28];
  int32_T tmp_size[2];
  int32_T flagOptimal;
  int32_T idx_size;
  char_T tmp_data[7];
  PreemptableMissionModeSelector_NameValueParser_NameValueParser(&parser);
  parser.ParsedResults = parser.Defaults;
  flagOptimal = 1;
  PreemptableMissionModeSelector_validatestring(parser.ParsedResults.f1,
    tmp_data, tmp_size);
  if (PreemptableMissionModeSelector_strcmp(tmp_data, tmp_size)) {
    flagOptimal = 0;
  }

  PreemptableMissionModeSelector_uavDubinsConnection_findDisabledIndices
    (idx_data, &idx_size);
  PreemptableMissionModeSelector_uavDubinsBuiltins_connect_i(obj, startPoses,
    goalPoses, flagOptimal == 1, obj->MinTurningRadius, idx_data, &idx_size,
    pathSegObjs_data, pathSegObjs_size, pathCosts_data, pathCosts_size, localB);
}

// Function for MATLAB Function: '<S117>/WayPointGenerator'
static void PreemptableMissionModeSelector_strcmp_imet(const
  cell_wrap_10_PreemptableMissionModeSelector_T a[4], boolean_T b_bool[4])
{
  b_bool[0] = false;
  if ((a[0].f1.size[1] == 1) && (!(a[0].f1.data[0] != 'N'))) {
    b_bool[0] = true;
  }

  b_bool[1] = false;
  if ((a[1].f1.size[1] == 1) && (!(a[1].f1.data[0] != 'N'))) {
    b_bool[1] = true;
  }

  b_bool[2] = false;
  if ((a[2].f1.size[1] == 1) && (!(a[2].f1.data[0] != 'N'))) {
    b_bool[2] = true;
  }

  b_bool[3] = false;
  if ((a[3].f1.size[1] == 1) && (!(a[3].f1.data[0] != 'N'))) {
    b_bool[3] = true;
  }
}

// Function for MATLAB Function: '<S117>/WayPointGenerator'
static void PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate_c(
  const real_T b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_10_PreemptableMissionModeSelector_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, emxArray_real_T_PreemptableMissionModeSelector_T *samples,
  emxArray_real_T_PreemptableMissionModeSelector_T *poses)
{
  emxArray_boolean_T_PreemptableMissionModeSelector_T *tempSamplesIndex;
  emxArray_boolean_T_PreemptableMissionModeSelector_T *tempSamplesIndex_0;
  emxArray_int32_T_PreemptableMissionModeSelector_T *ab;
  emxArray_real_T_PreemptableMissionModeSelector_T *S;
  emxArray_real_T_PreemptableMissionModeSelector_T *S_0;
  emxArray_real_T_PreemptableMissionModeSelector_T *e_x;
  emxArray_real_T_PreemptableMissionModeSelector_T *ns;
  emxArray_real_T_PreemptableMissionModeSelector_T *p;
  emxArray_real_T_PreemptableMissionModeSelector_T *tempSamples;
  emxArray_real_T_PreemptableMissionModeSelector_T *z;
  real_T state[6];
  real_T TransformMatrix[4];
  real_T c_x_data[4];
  real_T tempMotionLength_data[4];
  real_T TransformMatrix_tmp;
  real_T b_b_tmp;
  real_T e_b;
  real_T intermediateLength;
  real_T radius;
  real_T samples_0;
  real_T startIndex;
  real_T state_0;
  real_T tempStartPose_idx_2;
  int32_T c_x_size[2];
  int32_T tempMotionLength_size[2];
  int32_T S_idx_0;
  int32_T count;
  int32_T d_k;
  int32_T loop_ub;
  int32_T poses_0;
  int32_T tempMotionLength_data_tmp;
  boolean_T tmp[4];
  poses->size[0] = 0;
  poses->size[1] = 6;
  if ((!std::isnan(b_this_Length)) && (samples->size[1] != 0)) {
    tempStartPose_idx_2 = -b_this_StartPose[2];
    d_k = static_cast<int32_T>(poses->size[0] * poses->size[1]);
    poses->size[0] = samples->size[1];
    poses->size[1] = 6;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(poses, d_k);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(samples->size[1] * 6) -
      1);
    for (d_k = 0; d_k <= loop_ub; d_k++) {
      poses->data[d_k] = 0.0;
    }

    b_b_tmp = std::cos(std::abs(b_this_FlightPathAngle));
    d_k = static_cast<int32_T>(samples->size[0] * samples->size[1]);
    samples->size[0] = 1;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(samples, d_k);
    loop_ub = static_cast<int32_T>(samples->size[1] - 1);
    for (d_k = 0; d_k <= loop_ub; d_k++) {
      samples->data[d_k] *= b_b_tmp;
    }

    TransformMatrix[0] = b_this_MotionLengths[0] * b_b_tmp;
    TransformMatrix[1] = b_this_MotionLengths[1] * b_b_tmp;
    TransformMatrix[2] = b_this_MotionLengths[2] * b_b_tmp;
    tempMotionLength_size[0] = 1;
    tempMotionLength_size[1] = 4;
    tempMotionLength_data[0] = TransformMatrix[0];
    tempMotionLength_data[1] = TransformMatrix[1];
    tempMotionLength_data[2] = TransformMatrix[2];
    tempMotionLength_data[3] = b_this_MotionLengths[3] * b_b_tmp;
    PreemptableMissionModeSelector_strcmp_imet(b_this_MotionTypes, tmp);
    if (PreemptableMissionModeSelector_any(tmp)) {
      tempMotionLength_size[0] = 1;
      tempMotionLength_size[1] = 3;
      tempMotionLength_data[0] = TransformMatrix[0];
      tempMotionLength_data[1] = TransformMatrix[1];
      tempMotionLength_data[2] = TransformMatrix[2];
    }

    PreemptableMissionModeSelector_useConstantDim(tempMotionLength_data,
      tempMotionLength_size, c_x_data, c_x_size);
    PreemptableMissionModeSelector_sort_ps(samples);
    intermediateLength = 0.0;
    startIndex = 1.0;
    state[0] = b_this_StartPose[0];
    state[1] = -b_this_StartPose[1];
    state[3] = -b_this_StartPose[3];
    poses_0 = 0;
    PreemptableMissionModeSelector_emxInit_boolean_T(&tempSamplesIndex, 2);
    PreemptableMissionModeSelector_emxInit_real_T1(&tempSamples, 1);
    PreemptableMissionModeSelector_emxInit_real_T1(&S, 1);
    PreemptableMissionModeSelector_emxInit_real_T_h(&ns, 2);
    PreemptableMissionModeSelector_emxInit_real_T1(&z, 1);
    PreemptableMissionModeSelector_emxInit_real_T_h(&p, 2);
    PreemptableMissionModeSelector_emxInit_real_T1(&e_x, 1);
    PreemptableMissionModeSelector_emxInit_int32_T(&ab, 2);
    PreemptableMissionModeSelector_emxInit_boolean_T(&tempSamplesIndex_0, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&S_0, 2);
    while (poses_0 <= static_cast<int32_T>(tempMotionLength_size[1] - 1)) {
      if (static_cast<int32_T>(poses_0 + 1) == 1) {
        d_k = static_cast<int32_T>(tempSamplesIndex->size[0] *
          tempSamplesIndex->size[1]);
        tempSamplesIndex->size[0] = 1;
        tempSamplesIndex->size[1] = samples->size[1];
        PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T
          (tempSamplesIndex, d_k);
        loop_ub = static_cast<int32_T>(samples->size[1] - 1);
        radius = (intermediateLength + tempMotionLength_data[0]) + 1.0E-6;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          samples_0 = samples->data[d_k];
          tempSamplesIndex->data[d_k] = ((samples_0 >= intermediateLength) &&
            (samples_0 <= radius));
        }
      } else {
        d_k = static_cast<int32_T>(tempSamplesIndex->size[0] *
          tempSamplesIndex->size[1]);
        tempSamplesIndex->size[0] = 1;
        tempSamplesIndex->size[1] = samples->size[1];
        PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T
          (tempSamplesIndex, d_k);
        loop_ub = static_cast<int32_T>(samples->size[1] - 1);
        radius = (intermediateLength + tempMotionLength_data[poses_0]) + 1.0E-6;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          samples_0 = samples->data[d_k];
          tempSamplesIndex->data[d_k] = ((samples_0 > intermediateLength) &&
            (samples_0 <= radius));
        }
      }

      d_k = static_cast<int32_T>(tempSamplesIndex_0->size[0] *
        tempSamplesIndex_0->size[1]);
      tempSamplesIndex_0->size[0] = 1;
      tempSamplesIndex_0->size[1] = tempSamplesIndex->size[1];
      PreemptableMissionModeSelector_emxEnsureCapacity_boolean_T
        (tempSamplesIndex_0, d_k);
      loop_ub = tempSamplesIndex->size[1];
      for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
        tempSamplesIndex_0->data[d_k] = tempSamplesIndex->data[d_k];
      }

      PreemptableMissionModeSelector_eml_find_h(tempSamplesIndex_0, ab);
      if (!PreemptableMissionModeSelector_strcmp_m2ju(b_this_MotionTypes[poses_0]
           .f1.data, b_this_MotionTypes[poses_0].f1.size)) {
        radius = b_this_MinTurningRadius;
        if (PreemptableMissionModeSelector_strcmp_m2juc
            (b_this_MotionTypes[poses_0].f1.data, b_this_MotionTypes[poses_0].
             f1.size)) {
          radius = b_this_HelixRadius;
        } else if (PreemptableMissionModeSelector_strcmp_m2jucf
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          radius = b_this_HelixRadius;
        }

        count = 0;
        d_k = tempSamples->size[0];
        tempSamples->size[0] = 1;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples,
          d_k);
        tempSamples->data[0] = 0.0;
        if (ab->size[1] != 0) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = static_cast<int32_T>(ab->size[1] + 1);
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples,
            d_k);
          loop_ub = ab->size[1];
          for (d_k = 0; d_k <= loop_ub; d_k++) {
            tempSamples->data[d_k] = 0.0;
          }

          loop_ub = ab->size[1];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            tempSamples->data[d_k] = samples->data[static_cast<int32_T>(ab->
              data[d_k] - 1)];
          }

          count = ab->size[1];
          loop_ub = static_cast<int32_T>(ab->size[1] - 1);
          for (d_k = 0; d_k <= loop_ub; d_k++) {
            samples->data[static_cast<int32_T>(ab->data[d_k] - 1)] = -1.0;
          }
        }

        tempSamples->data[count] = c_x_data[poses_0];
        d_k = S->size[0];
        S->size[0] = tempSamples->size[0];
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(S, d_k);
        loop_ub = tempSamples->size[0];
        for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
          S->data[d_k] = (tempSamples->data[d_k] - intermediateLength) / radius;
        }

        d_k = static_cast<int32_T>(ns->size[0] * ns->size[1]);
        ns->size[0] = S->size[0];
        ns->size[1] = 6;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ns, d_k);
        loop_ub = static_cast<int32_T>(static_cast<int32_T>(S->size[0] * 6) - 1);
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          ns->data[d_k] = 0.0;
        }

        d_k = z->size[0];
        z->size[0] = tempSamples->size[0];
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(z, d_k);
        loop_ub = tempSamples->size[0];
        for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
          z->data[d_k] = tempStartPose_idx_2 + tempSamples->data[d_k];
        }

        samples_0 = std::sin(state[3]);
        TransformMatrix_tmp = std::cos(state[3]);
        TransformMatrix[0] = TransformMatrix_tmp;
        TransformMatrix[2] = samples_0;
        TransformMatrix[1] = -samples_0;
        TransformMatrix[3] = TransformMatrix_tmp;
        if (b_this_Length != 0.0) {
          samples_0 = -b_this_GoalPose[2] - tempStartPose_idx_2;
          TransformMatrix_tmp = b_this_Length * b_b_tmp;
          d_k = z->size[0];
          z->size[0] = tempSamples->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(z, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            z->data[d_k] = tempSamples->data[d_k] / TransformMatrix_tmp *
              samples_0 + tempStartPose_idx_2;
          }
        }

        if (PreemptableMissionModeSelector_strcmp_m2juc
            (b_this_MotionTypes[poses_0].f1.data, b_this_MotionTypes[poses_0].
             f1.size) || PreemptableMissionModeSelector_strcmp_m2jucfm
            (b_this_MotionTypes[poses_0].f1.data, b_this_MotionTypes[poses_0].
             f1.size)) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = S->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples,
            d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            tempSamples->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S->size[0] - 1); d_k =
               static_cast<int32_T>(d_k + 1)) {
            tempSamples->data[d_k] = std::sin(tempSamples->data[d_k]);
          }

          d_k = e_x->size[0];
          e_x->size[0] = S->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(e_x, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            e_x->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S->size[0] - 1); d_k =
               static_cast<int32_T>(d_k + 1)) {
            e_x->data[d_k] = std::cos(e_x->data[d_k]);
          }

          d_k = static_cast<int32_T>(S_0->size[0] * S_0->size[1]);
          S_0->size[0] = tempSamples->size[0];
          S_0->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S_0, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[d_k] = tempSamples->data[d_k];
          }

          loop_ub = e_x->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[static_cast<int32_T>(d_k + tempSamples->size[0])] = 1.0 -
              e_x->data[d_k];
          }

          PreemptableMissionModeSelector_mtimes(S_0, TransformMatrix, p);
          e_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          state_0 = state[3];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          loop_ub = p->size[0];
          d_k = static_cast<int32_T>(ns->size[0] * ns->size[1]);
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ns, d_k);
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[static_cast<int32_T>(d_k + ns->size[0])] = p->data[
              static_cast<int32_T>(d_k + p->size[0])] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 1))] = z->data[d_k];
          }

          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 3))] = state_0 + S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(count - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 2))] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(tempMotionLength_data_tmp -
                1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 5))] = -e_b;
          }
        } else if (PreemptableMissionModeSelector_strcmp_m2jucf
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size) ||
                   PreemptableMissionModeSelector_strcmp_m2jucfmm
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = S->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples,
            d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            tempSamples->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S->size[0] - 1); d_k =
               static_cast<int32_T>(d_k + 1)) {
            tempSamples->data[d_k] = std::sin(tempSamples->data[d_k]);
          }

          d_k = e_x->size[0];
          e_x->size[0] = S->size[0];
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(e_x, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            e_x->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S->size[0] - 1); d_k =
               static_cast<int32_T>(d_k + 1)) {
            e_x->data[d_k] = std::cos(e_x->data[d_k]);
          }

          d_k = static_cast<int32_T>(S_0->size[0] * S_0->size[1]);
          S_0->size[0] = tempSamples->size[0];
          S_0->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S_0, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[d_k] = tempSamples->data[d_k];
          }

          loop_ub = e_x->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[static_cast<int32_T>(d_k + tempSamples->size[0])] =
              e_x->data[d_k] - 1.0;
          }

          PreemptableMissionModeSelector_mtimes(S_0, TransformMatrix, p);
          e_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          state_0 = state[3];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          loop_ub = p->size[0];
          d_k = static_cast<int32_T>(ns->size[0] * ns->size[1]);
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ns, d_k);
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[static_cast<int32_T>(d_k + ns->size[0])] = p->data[
              static_cast<int32_T>(d_k + p->size[0])] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 1))] = z->data[d_k];
          }

          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 3))] = state_0 - S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(count - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 2))] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(tempMotionLength_data_tmp -
                1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 5))] = e_b;
          }
        } else if (PreemptableMissionModeSelector_strcmp_m2jucfmmw
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          count = S->size[0];
          d_k = static_cast<int32_T>(S_0->size[0] * S_0->size[1]);
          S_0->size[0] = S->size[0];
          S_0->size[1] = 2;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(S_0, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            S_0->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(count - 1); d_k++) {
            S_0->data[static_cast<int32_T>(d_k + S->size[0])] = 0.0;
          }

          PreemptableMissionModeSelector_mtimes(S_0, TransformMatrix, p);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          S_idx_0 = S->size[0];
          loop_ub = p->size[0];
          d_k = static_cast<int32_T>(ns->size[0] * ns->size[1]);
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(ns, d_k);
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[static_cast<int32_T>(d_k + ns->size[0])] = p->data[
              static_cast<int32_T>(d_k + p->size[0])] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 1))] = z->data[d_k];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(count - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 3))] = state[3];
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(tempMotionLength_data_tmp -
                1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              << 2))] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k <= static_cast<int32_T>(S_idx_0 - 1); d_k++) {
            ns->data[static_cast<int32_T>(d_k + static_cast<int32_T>(ns->size[0]
              * 5))] = 0.0;
          }
        }

        if (ab->size[1] != 0) {
          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k < 6; d_k++) {
            for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                 loop_ub; tempMotionLength_data_tmp++) {
              poses->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
                int32_T>(count + tempMotionLength_data_tmp) +
                static_cast<int32_T>(poses->size[0] * d_k)) - 1)] = ns->data[
                static_cast<int32_T>(tempMotionLength_data_tmp +
                static_cast<int32_T>(ns->size[0] * d_k))];
            }
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[static_cast<int32_T>(static_cast<int32_T>(count + d_k) -
              1)] = ns->data[d_k];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[static_cast<int32_T>(static_cast<int32_T>
              (static_cast<int32_T>(count + d_k) + poses->size[0]) - 1)] =
              -ns->data[static_cast<int32_T>(d_k + ns->size[0])];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[static_cast<int32_T>(static_cast<int32_T>
              (static_cast<int32_T>(count + d_k) + static_cast<int32_T>
               (poses->size[0] << 1)) - 1)] = -ns->data[static_cast<int32_T>(d_k
              + static_cast<int32_T>(ns->size[0] << 1))];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
            loop_ub = -1;
          } else {
            loop_ub = static_cast<int32_T>(ns->size[0] - 2);
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[static_cast<int32_T>(static_cast<int32_T>
              (static_cast<int32_T>(count + d_k) + static_cast<int32_T>
               (poses->size[0] * 3)) - 1)] = -ns->data[static_cast<int32_T>(d_k
              + static_cast<int32_T>(ns->size[0] * 3))];
          }
        }

        count = ns->size[0];
        for (d_k = 0; d_k < 6; d_k++) {
          state[d_k] = ns->data[static_cast<int32_T>(static_cast<int32_T>(count
            + static_cast<int32_T>(ns->size[0] * d_k)) - 1)];
        }

        startIndex += static_cast<real_T>(ab->size[1]);
      }

      intermediateLength += tempMotionLength_data[poses_0];
      poses_0 = static_cast<int32_T>(poses_0 + 1);
    }

    PreemptableMissionModeSelector_emxFree_real_T_n(&S_0);
    PreemptableMissionModeSelector_emxFree_boolean_T(&tempSamplesIndex_0);
    PreemptableMissionModeSelector_emxFree_int32_T(&ab);
    PreemptableMissionModeSelector_emxFree_real_T_n(&e_x);
    PreemptableMissionModeSelector_emxFree_real_T_n(&p);
    PreemptableMissionModeSelector_emxFree_real_T_n(&z);
    PreemptableMissionModeSelector_emxFree_real_T_n(&ns);
    PreemptableMissionModeSelector_emxFree_real_T_n(&S);
    PreemptableMissionModeSelector_emxFree_boolean_T(&tempSamplesIndex);
    loop_ub = poses->size[0];
    d_k = tempSamples->size[0];
    tempSamples->size[0] = poses->size[0];
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T1(tempSamples, d_k);
    for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
      tempSamples->data[d_k] = poses->data[static_cast<int32_T>(d_k +
        static_cast<int32_T>(poses->size[0] * 3))];
    }

    PreemptableMissionModeSelector_wrapToPi(tempSamples);
    loop_ub = tempSamples->size[0];
    for (d_k = 0; d_k <= static_cast<int32_T>(loop_ub - 1); d_k++) {
      poses->data[static_cast<int32_T>(d_k + static_cast<int32_T>(poses->size[0]
        * 3))] = tempSamples->data[d_k];
    }

    PreemptableMissionModeSelector_emxFree_real_T_n(&tempSamples);
  }
}

// Function for MATLAB Function: '<S117>/WayPointGenerator'
static void PreemptableMissionModeSelector_genSegWP_la(const
  uavDubinsConnection_PreemptableMissionModeSelector_T *connectionObj, const
  real_T start[4], const real_T ende[4], real_T b_stepSize,
  emxArray_real_T_PreemptableMissionModeSelector_T *segWayPoints,
  B_PreemptableMissionModeSelector_c_T *localB)
{
  emxArray_real_T_PreemptableMissionModeSelector_T *lengths;
  emxArray_real_T_PreemptableMissionModeSelector_T *poses;
  real_T a__1_data[28];
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T realStepSize;
  int32_T a__1_size;
  int32_T k;
  int32_T nm1d2;
  boolean_T guard1{ false };

  PreemptableMissionModeSelector_uavDubinsConnection_connect_j(connectionObj,
    start, ende, localB->pathSegObj_d.data, &localB->pathSegObj_d.size,
    a__1_data, &a__1_size, localB);
  realStepSize = localB->pathSegObj_d.data[0].Length / std::round
    (localB->pathSegObj_d.data[0].Length / b_stepSize);
  PreemptableMissionModeSelector_emxInit_real_T_h(&lengths, 2);
  if (std::isnan(realStepSize)) {
    nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
    lengths->size[0] = 1;
    lengths->size[1] = 1;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
    lengths->data[0] = (rtNaN);
  } else if (std::isnan(localB->pathSegObj_d.data[0].Length)) {
    nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
    lengths->size[0] = 1;
    lengths->size[1] = 1;
    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
    lengths->data[0] = (rtNaN);
  } else if (realStepSize == 0.0) {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else if ((0.0 < localB->pathSegObj_d.data[0].Length) && (realStepSize < 0.0))
  {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else if ((localB->pathSegObj_d.data[0].Length < 0.0) && (realStepSize > 0.0))
  {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else {
    guard1 = false;
    if (std::isinf(localB->pathSegObj_d.data[0].Length)) {
      if (std::isinf(realStepSize)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
      } else if (0.0 == localB->pathSegObj_d.data[0].Length) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (std::isinf(realStepSize)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = 0.0;
      } else if (std::floor(realStepSize) == realStepSize) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        k = static_cast<int32_T>(std::floor(localB->pathSegObj_d.data[0].Length /
          realStepSize));
        lengths->size[1] = static_cast<int32_T>(k + 1);
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        for (a__1_size = 0; a__1_size <= k; a__1_size++) {
          lengths->data[a__1_size] = realStepSize * static_cast<real_T>
            (a__1_size);
        }
      } else {
        ndbl = std::floor(localB->pathSegObj_d.data[0].Length / realStepSize +
                          0.5);
        apnd = ndbl * realStepSize;
        if (realStepSize > 0.0) {
          cdiff = apnd - localB->pathSegObj_d.data[0].Length;
        } else {
          cdiff = localB->pathSegObj_d.data[0].Length - apnd;
        }

        if (std::abs(cdiff) < 4.4408920985006262E-16 * std::abs
            (localB->pathSegObj_d.data[0].Length)) {
          ndbl++;
          apnd = localB->pathSegObj_d.data[0].Length;
        } else if (cdiff > 0.0) {
          apnd = (ndbl - 1.0) * realStepSize;
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          a__1_size = static_cast<int32_T>(static_cast<int32_T>(ndbl) - 1);
        } else {
          a__1_size = -1;
        }

        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = static_cast<int32_T>(a__1_size + 1);
        PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        if (static_cast<int32_T>(a__1_size + 1) > 0) {
          lengths->data[0] = 0.0;
          if (static_cast<int32_T>(a__1_size + 1) > 1) {
            lengths->data[a__1_size] = apnd;
            nm1d2 = static_cast<int32_T>(a__1_size / 2);
            for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>
                 (nm1d2 - 2); k = static_cast<int32_T>(k + 1)) {
              ndbl = static_cast<real_T>(k) * realStepSize;
              lengths->data[k] = ndbl;
              lengths->data[static_cast<int32_T>(a__1_size - k)] = apnd - ndbl;
            }

            if (static_cast<int32_T>(nm1d2 << 1) == a__1_size) {
              lengths->data[nm1d2] = apnd / 2.0;
            } else {
              ndbl = static_cast<real_T>(nm1d2) * realStepSize;
              lengths->data[nm1d2] = ndbl;
              lengths->data[static_cast<int32_T>(nm1d2 + 1)] = apnd - ndbl;
            }
          }
        }
      }
    }
  }

  PreemptableMissionModeSelector_emxInit_real_T_h(&poses, 2);
  PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate_c
    (localB->pathSegObj_d.data[0].StartPose, localB->pathSegObj_d.data[0].
     GoalPose, localB->pathSegObj_d.data[0].FlightPathAngle,
     localB->pathSegObj_d.data[0].AirSpeed, localB->pathSegObj_d.data[0].
     MinTurningRadius, localB->pathSegObj_d.data[0].HelixRadius,
     localB->pathSegObj_d.data[0].MotionTypes, localB->pathSegObj_d.data[0].
     MotionLengths, localB->pathSegObj_d.data[0].Length, lengths, poses);
  k = poses->size[0];
  nm1d2 = static_cast<int32_T>(segWayPoints->size[0] * segWayPoints->size[1]);
  segWayPoints->size[0] = poses->size[0];
  segWayPoints->size[1] = 3;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(segWayPoints, nm1d2);
  PreemptableMissionModeSelector_emxFree_real_T_n(&lengths);
  for (a__1_size = 0; a__1_size < 3; a__1_size++) {
    for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(k - 1); nm1d2++) {
      segWayPoints->data[static_cast<int32_T>(nm1d2 + static_cast<int32_T>
        (segWayPoints->size[0] * a__1_size))] = poses->data[static_cast<int32_T>
        (nm1d2 + static_cast<int32_T>(poses->size[0] * a__1_size))];
    }
  }

  PreemptableMissionModeSelector_emxFree_real_T_n(&poses);
}

// Function for MATLAB Function: '<S56>/WayPointGenerator'
static void PreemptableMissionModeSelector_repmat(const
  emxArray_real_T_PreemptableMissionModeSelector_T *a, real_T varargin_1,
  emxArray_real_T_PreemptableMissionModeSelector_T *b)
{
  int32_T iacol;
  int32_T ibcol;
  int32_T ibmat;
  int32_T itilerow;
  int32_T k;
  int32_T nrows;
  nrows = static_cast<int32_T>(b->size[0] * b->size[1]);
  b->size[0] = static_cast<int32_T>(a->size[0] * static_cast<int32_T>(varargin_1));
  b->size[1] = 3;
  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(b, nrows);
  nrows = a->size[0];
  for (itilerow = 0; itilerow <= static_cast<int32_T>(static_cast<int32_T>
        (varargin_1) - 1); itilerow = static_cast<int32_T>(itilerow + 1)) {
    ibcol = static_cast<int32_T>(static_cast<int32_T>(itilerow * nrows) + -1);
    for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>(nrows - 1);
         k = static_cast<int32_T>(k + 1)) {
      b->data[static_cast<int32_T>(ibcol + k)] = a->data[static_cast<int32_T>(k
        - 1)];
    }
  }

  ibmat = static_cast<int32_T>(static_cast<int32_T>(a->size[0] *
    static_cast<int32_T>(varargin_1)) - 1);
  for (itilerow = 0; itilerow <= static_cast<int32_T>(static_cast<int32_T>
        (varargin_1) - 1); itilerow = static_cast<int32_T>(itilerow + 1)) {
    ibcol = static_cast<int32_T>(static_cast<int32_T>(itilerow * nrows) + ibmat);
    for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>(nrows - 1);
         k = static_cast<int32_T>(k + 1)) {
      b->data[static_cast<int32_T>(ibcol + k)] = a->data[static_cast<int32_T>(
        static_cast<int32_T>(nrows + k) - 1)];
    }
  }

  iacol = static_cast<int32_T>(a->size[0] << 1);
  ibmat = static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>(a->
    size[0] * static_cast<int32_T>(varargin_1)) << 1) - 1);
  for (itilerow = 0; itilerow <= static_cast<int32_T>(static_cast<int32_T>
        (varargin_1) - 1); itilerow = static_cast<int32_T>(itilerow + 1)) {
    ibcol = static_cast<int32_T>(static_cast<int32_T>(itilerow * nrows) + ibmat);
    for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>(nrows - 1);
         k = static_cast<int32_T>(k + 1)) {
      b->data[static_cast<int32_T>(ibcol + k)] = a->data[static_cast<int32_T>(
        static_cast<int32_T>(iacol + k) - 1)];
    }
  }
}

// System initialize for referenced model: 'PreemptableMissionModeSelector'
void PreemptableMissionModeSelector_Init(FixedWingGuidanceBus *rty_GuidanceCmds,
  real_T rty_InitialState[8], real_T rty_VelShift[2],
  DW_PreemptableMissionModeSelector_f_T *localDW)
{
  // SystemInitialize for Chart: '<Root>/PreemptableMissionModeSelector' incorporates:
  //   Constant: '<S2>/Constant'
  //   Constant: '<S3>/Constant'
  //   Constant: '<S4>/LookAheadDis'
  //   Constant: '<S5>/LookAheadDis'
  //   Constant: '<S6>/LookAheadDis'
  //   Constant: '<S7>/LookAheadDis'

  rty_GuidanceCmds->Height = 0.0;
  rty_GuidanceCmds->AirSpeed = 0.0;
  rty_GuidanceCmds->HeadingAngle = 0.0;
  std::memset(&rty_InitialState[0], 0, static_cast<uint32_T>(sizeof(real_T) <<
    3U));
  rty_VelShift[0] = 0.0;
  rty_VelShift[1] = 0.0;

  // SystemInitialize for IfAction SubSystem: '<S1>/GuidanceLogic.OrbitFollower.CirclingNav' 
  PreemptableMissionModeSelector_OrbitFollower_Init(&localDW->OrbitFollower_b);

  // End of SystemInitialize for SubSystem: '<S1>/GuidanceLogic.OrbitFollower.CirclingNav' 

  // SystemInitialize for IfAction SubSystem: '<S1>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 
  PreemptableMissionModeSelector_OrbitFollower_Init(&localDW->OrbitFollower);

  // End of SystemInitialize for SubSystem: '<S1>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 

  // SystemInitialize for IfAction SubSystem: '<S1>/GuidanceLogic.WaypointFollower.HorizontalFormationNav' 
  // SystemInitialize for Triggered SubSystem: '<S7>/WayPointGenerator'
  PreemptableMissionModeSelector_RotateATMissionHdg_Init
    (&localDW->RotateATMissionHdg_baf);

  // End of SystemInitialize for SubSystem: '<S7>/WayPointGenerator'
  PreemptableMissionModeSelector_WaypointFollower_Init
    (&localDW->WaypointFollower_baf);

  // End of SystemInitialize for SubSystem: '<S1>/GuidanceLogic.WaypointFollower.HorizontalFormationNav' 

  // SystemInitialize for IfAction SubSystem: '<S1>/GuidanceLogic.WaypointFollower.CustomFormationNav' 
  // SystemInitialize for Triggered SubSystem: '<S6>/WayPointGenerator'
  PreemptableMissionModeSelector_RotateATMissionHdg_Init
    (&localDW->RotateATMissionHdg_ba);

  // End of SystemInitialize for SubSystem: '<S6>/WayPointGenerator'
  PreemptableMissionModeSelector_WaypointFollower_Init
    (&localDW->WaypointFollower_ba);

  // End of SystemInitialize for SubSystem: '<S1>/GuidanceLogic.WaypointFollower.CustomFormationNav' 

  // SystemInitialize for IfAction SubSystem: '<S1>/GuidanceLogic.RunWayNav'
  // SystemInitialize for Triggered SubSystem: '<S5>/WayPointGenerator'
  PreemptableMissionModeSelector_RotateATMissionHdg_Init
    (&localDW->RotateATMissionHdg_b);
  PreemptableMissionModeSelector_RotateATMissionHdg_Init
    (&localDW->RotateATRunWayHdg_b);

  // End of SystemInitialize for SubSystem: '<S5>/WayPointGenerator'
  PreemptableMissionModeSelector_WaypointFollower_Init
    (&localDW->WaypointFollower_b);

  // End of SystemInitialize for SubSystem: '<S1>/GuidanceLogic.RunWayNav'

  // SystemInitialize for IfAction SubSystem: '<S1>/GuidanceLogic.ProtectionLine' 
  // SystemInitialize for Triggered SubSystem: '<S4>/WayPointGenerator'
  PreemptableMissionModeSelector_RotateATMissionHdg_Init
    (&localDW->RotateATRunWayHdg);
  PreemptableMissionModeSelector_RotateATMissionHdg_Init
    (&localDW->RotateATMissionHdg);

  // End of SystemInitialize for SubSystem: '<S4>/WayPointGenerator'
  PreemptableMissionModeSelector_WaypointFollower_Init
    (&localDW->WaypointFollower);

  // End of SystemInitialize for SubSystem: '<S1>/GuidanceLogic.ProtectionLine'
}

// Output and update for referenced model: 'PreemptableMissionModeSelector'
void PreemptableMissionModeSelector(const boolean_T *rtu_startFlight, const
  int32_T *rtu_mode, const Location *rtu_PrevLocation, const Location
  *rtu_Location, const Parameters *rtu_Parameters, const Location
  *rtu_StartPosition, const int32_T *rtu_SequenceID, const int32_T
  *rtu_FormationIDX, const int32_T *rtu_MissionUAV, const real_T rtu_Pose[4],
  real_T *rty_thisTaskStatus, FixedWingGuidanceBus *rty_GuidanceCmds, real_T
  *rty_ResetTrigger, real_T rty_InitialState[8], real_T rty_VelShift[2],
  B_PreemptableMissionModeSelector_c_T *localB,
  DW_PreemptableMissionModeSelector_f_T *localDW,
  ZCE_PreemptableMissionModeSelector_T *localZCE)
{
  // local block i/o variables
  real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1[3];
  real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[3];
  real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[3];
  real_T rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[3];
  real_T rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[3];
  real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[3];
  real_T rtb_TmpSignalConversionAtOrbitFollowerInport2[3];
  real_T rtb_Param1_f;
  real_T rtb_Param2_a;
  real_T rtb_Param1_i;
  real_T rtb_TmpSignalConversionAtOrbitFollowerInport2_b[3];
  real_T rtb_Param2_n1;
  emxArray_real_T_PreemptableMissionModeSelector_T *CheckPoints;
  emxArray_real_T_PreemptableMissionModeSelector_T *dummyWayPoint;
  emxArray_real_T_PreemptableMissionModeSelector_T *dummyWayPoint_0;
  emxArray_real_T_PreemptableMissionModeSelector_T *dummyWayPoint_1;
  emxArray_real_T_PreemptableMissionModeSelector_T *dummyWayPoint_2;
  emxArray_real_T_PreemptableMissionModeSelector_T *dummyWayPoint_3;
  emxArray_real_T_PreemptableMissionModeSelector_T *initWayPoint;
  emxArray_real_T_PreemptableMissionModeSelector_T *segWayPoints;
  uavDubinsConnection_PreemptableMissionModeSelector_T connectionObj;
  real_T a__1_data[28];
  real_T midpose_data[6];
  real_T LDp[4];
  real_T LUp[4];
  real_T ende[4];
  real_T rtb_startPose_f[4];
  real_T rtb_ReshapeRowVec[3];
  real_T rtb_Reshape_i[3];
  real_T rtb_startPose_h[3];
  real_T rtb_Abs1_jo;
  real_T rtb_Down;
  real_T rtb_Down_c;
  real_T rtb_Gain1;
  real_T rtb_Param4_e;
  real_T rtb_Sum;
  real_T rtb_SumInitEast_j;
  real_T rtb_Sum_as;
  real_T rtb_Switch;
  real_T rtb_Switch_aa;
  real_T rtb_Switch_e;
  real_T rtb_Switch_p;
  int32_T midpose_size[2];
  int32_T b_nrows;
  int32_T ibmat;
  int32_T loop_ub;
  int32_T nrows;
  int32_T nrowx;
  int32_T rtb_ClockwiseRotation_n;
  uint32_T rtb_Abs;
  int8_T rtb_MatrixConcatenate[9];
  boolean_T guard1{ false };

  boolean_T sf_internal_predicateOutput;
  ZCEventType zcEvent;

  // Chart: '<Root>/PreemptableMissionModeSelector' incorporates:
  //   Constant: '<S2>/Constant'
  //   Constant: '<S3>/Constant'
  //   Constant: '<S4>/LookAheadDis'
  //   Constant: '<S5>/LookAheadDis'
  //   Constant: '<S6>/LookAheadDis'
  //   Constant: '<S7>/LookAheadDis'
  //   MATLAB Function: '<S117>/WayPointGenerator'
  //   MATLAB Function: '<S168>/WayPointGenerator'
  //   MATLAB Function: '<S56>/WayPointGenerator'
  //   MATLAB Function: '<S86>/WayPointGenerator'
  //   Memory: '<S4>/MemoryTriggerWP'
  //   Memory: '<S5>/MemoryTriggerWP'
  //   Memory: '<S6>/MemoryTriggerWP'
  //   Memory: '<S7>/MemoryTriggerWP'

  localDW->SequenceID_prev = localDW->SequenceID_start;
  localDW->SequenceID_start = *rtu_SequenceID;
  if (static_cast<uint32_T>
      (localDW->is_active_c23_PreemptableMissionModeSelector) == 0U) {
    localDW->SequenceID_prev = *rtu_SequenceID;
    localDW->is_active_c23_PreemptableMissionModeSelector = 1U;
    localDW->is_GuidanceLogic = PreemptableMissionModeSelector_IN_WaitToStart;
  } else {
    PreemptableMissionModeSelector_emxInit_real_T_h(&initWayPoint, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&CheckPoints, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&dummyWayPoint, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&segWayPoints, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&dummyWayPoint_0, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&dummyWayPoint_1, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&dummyWayPoint_2, 2);
    PreemptableMissionModeSelector_emxInit_real_T_h(&dummyWayPoint_3, 2);
    guard1 = false;
    if (localDW->SequenceID_prev != localDW->SequenceID_start) {
      sf_internal_predicateOutput = ((*rtu_mode == 1) || (*rtu_mode == 11));
      if (sf_internal_predicateOutput) {
        PreemptableMissionModeSelector_exit_internal_GuidanceLogic(localDW);
        localDW->is_GuidanceLogic =
          PreemptableMissionModeSelector_IN_OrbitFollower;
        *rty_ResetTrigger = 1.0;
        if (*rtu_mode == 1) {
          localDW->is_OrbitFollower =
            PreemptableMissionModeSelector_IN_CirclingNav;

          // Bias: '<S3>/Bias'
          b_nrows = *rtu_MissionUAV;

          // DataTypeConversion: '<S3>/CastToDouble'
          rtb_ClockwiseRotation_n = *rtu_FormationIDX;

          // Product: '<S3>/Divide' incorporates:
          //   Constant: '<S3>/two_pi'

          rtb_Down_c = 6.2831853071795862 / static_cast<real_T>(*rtu_MissionUAV);

          // Product: '<S3>/Map2Radian' incorporates:
          //   Bias: '<S3>/Bias'
          //   Gain: '<S3>/HalveMissionUAV'
          //   Sum: '<S3>/Minus'

          rtb_Down_c *= static_cast<real_T>(rtb_ClockwiseRotation_n) -
            static_cast<real_T>(static_cast<int32_T>(b_nrows + 1)) * 0.5;

          // Switch: '<S45>/Switch' incorporates:
          //   Abs: '<S45>/Abs'
          //   Bias: '<S45>/Bias'
          //   Bias: '<S45>/Bias1'
          //   Constant: '<S45>/Constant2'
          //   Constant: '<S46>/Constant'
          //   DataStoreRead: '<S3>/LatitudeGCS'
          //   Math: '<S45>/Math Function1'
          //   RelationalOperator: '<S46>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            rtb_Down = LatitudeGCS;
          }

          // Abs: '<S42>/Abs1'
          rtb_Switch_aa = std::abs(rtb_Down);

          // Switch: '<S42>/Switch' incorporates:
          //   Bias: '<S42>/Bias'
          //   Bias: '<S42>/Bias1'
          //   Constant: '<S33>/Constant'
          //   Constant: '<S33>/Constant1'
          //   Constant: '<S44>/Constant'
          //   Gain: '<S42>/Gain'
          //   Product: '<S42>/Divide1'
          //   RelationalOperator: '<S44>/Compare'
          //   Switch: '<S33>/Switch1'

          if (rtb_Switch_aa > 90.0) {
            // Signum: '<S42>/Sign1'
            if (rtb_Down < 0.0) {
              rtb_Down = -1.0;
            } else if (rtb_Down > 0.0) {
              rtb_Down = 1.0;
            } else if (rtb_Down == 0.0) {
              rtb_Down = 0.0;
            } else {
              rtb_Down = (rtNaN);
            }

            rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S33>/Sum' incorporates:
          //   DataStoreRead: '<S3>/LongitudeGCS'

          rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

          // Sum: '<S31>/Sum1'
          rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

          // Switch: '<S43>/Switch' incorporates:
          //   Abs: '<S43>/Abs'
          //   Bias: '<S43>/Bias'
          //   Bias: '<S43>/Bias1'
          //   Constant: '<S43>/Constant2'
          //   Constant: '<S47>/Constant'
          //   Math: '<S43>/Math Function1'
          //   RelationalOperator: '<S47>/Compare'

          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S31>/Sum1'
          rtb_Sum = rtu_Location->Lon - rtb_Sum;

          // Switch: '<S39>/Switch' incorporates:
          //   Abs: '<S39>/Abs'
          //   Bias: '<S39>/Bias'
          //   Bias: '<S39>/Bias1'
          //   Constant: '<S39>/Constant2'
          //   Constant: '<S40>/Constant'
          //   Math: '<S39>/Math Function1'
          //   RelationalOperator: '<S40>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S36>/Abs1'
          rtb_Abs1_jo = std::abs(rtb_Switch_aa);

          // Switch: '<S36>/Switch' incorporates:
          //   Bias: '<S36>/Bias'
          //   Bias: '<S36>/Bias1'
          //   Constant: '<S32>/Constant'
          //   Constant: '<S32>/Constant1'
          //   Constant: '<S38>/Constant'
          //   Gain: '<S36>/Gain'
          //   Product: '<S36>/Divide1'
          //   RelationalOperator: '<S38>/Compare'
          //   Switch: '<S32>/Switch1'

          if (rtb_Abs1_jo > 90.0) {
            // Signum: '<S36>/Sign1'
            if (rtb_Switch_aa < 0.0) {
              rtb_Switch_aa = -1.0;
            } else if (rtb_Switch_aa > 0.0) {
              rtb_Switch_aa = 1.0;
            } else if (rtb_Switch_aa == 0.0) {
              rtb_Switch_aa = 0.0;
            } else {
              rtb_Switch_aa = (rtNaN);
            }

            rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
            b_nrows = 180;
          } else {
            rtb_Abs1_jo = rtb_Switch_aa;
            b_nrows = 0;
          }

          // Sum: '<S32>/Sum'
          rtb_Sum += static_cast<real_T>(b_nrows);

          // UnitConversion: '<S35>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

          // UnitConversion: '<S50>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Down *= 0.017453292519943295;

          // Trigonometry: '<S51>/Trigonometric Function1'
          rtb_Param4_e = std::sin(rtb_Down);

          // Sum: '<S51>/Sum1' incorporates:
          //   Constant: '<S51>/Constant'
          //   Product: '<S51>/Product1'

          rtb_Param4_e = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_i *
            PreemptableMissionModeSelector_ConstB.sqrt_i * rtb_Param4_e *
            rtb_Param4_e;

          // Product: '<S49>/Product1' incorporates:
          //   Constant: '<S49>/Constant1'
          //   Sqrt: '<S49>/sqrt'

          rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

          // Product: '<S34>/dNorth' incorporates:
          //   Constant: '<S49>/Constant2'
          //   Product: '<S49>/Product3'
          //   Trigonometry: '<S49>/Trigonometric Function1'

          rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
            PreemptableMissionModeSelector_ConstB.Sum1_fv / rtb_Param4_e);

          // Switch: '<S37>/Switch' incorporates:
          //   Abs: '<S37>/Abs'
          //   Bias: '<S37>/Bias'
          //   Bias: '<S37>/Bias1'
          //   Constant: '<S37>/Constant2'
          //   Constant: '<S41>/Constant'
          //   Math: '<S37>/Math Function1'
          //   RelationalOperator: '<S41>/Compare'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Product: '<S34>/dEast' incorporates:
          //   Constant: '<S49>/Constant3'
          //   Product: '<S49>/Product4'
          //   Trigonometry: '<S49>/Trigonometric Function'
          //   Trigonometry: '<S49>/Trigonometric Function2'
          //   UnitConversion: '<S35>/Unit Conversion'

          rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos(rtb_Down))
            * (0.017453292519943295 * rtb_Sum);

          // Sum: '<S34>/Sum2' incorporates:
          //   Product: '<S34>/x*cos'
          //   Product: '<S34>/y*sin'

          rtb_Down = rtb_Abs1_jo * 0.0 + rtb_Param4_e;

          // Sum: '<S34>/Sum3' incorporates:
          //   Product: '<S34>/x*sin'
          //   Product: '<S34>/y*cos'

          rtb_Switch_aa = rtb_Abs1_jo - rtb_Param4_e * 0.0;

          // Sum: '<S31>/Sum' incorporates:
          //   DataStoreRead: '<S3>/AltitudeGCS'
          //   Gain: '<S3>/inverse'

          rtb_Sum = rtu_Location->Alt + -AltitudeGCS;

          // SignalConversion generated from: '<S3>/Orbit Follower' incorporates:
          //   UnaryMinus: '<S31>/Ze2height'

          rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Down;
          rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Switch_aa;
          rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = -rtb_Sum;

          // DataTypeConversion: '<S3>/Param1'
          rtb_Param1_f = static_cast<real_T>(rtu_Parameters->Param1);

          // DataTypeConversion: '<S3>/Param2'
          rtb_Param2_a = static_cast<real_T>(rtu_Parameters->Param2);
          PreemptableMissionModeSelector_OrbitFollower(rtu_Pose,
            rtb_TmpSignalConversionAtOrbitFollowerInport2, rtb_Param1_f,
            rtb_Param2_a, 1.0, &localB->OrbitFollower_b,
            &localDW->OrbitFollower_b);

          // BusCreator: '<S3>/GuidanceCMDBusCreator' incorporates:
          //   Constant: '<S3>/Constant'
          //   DataTypeConversion: '<S3>/Param3'
          //   Gain: '<S3>/Down2Height'

          rty_GuidanceCmds->Height = -localB->OrbitFollower_b.OrbitFollower_o1[2];
          rty_GuidanceCmds->AirSpeed = static_cast<real_T>
            (rtu_Parameters->Param4);
          rty_GuidanceCmds->HeadingAngle =
            localB->OrbitFollower_b.OrbitFollower_o2;

          // Reshape: '<S3>/Reshape' incorporates:
          //   Bias: '<S3>/ClockwiseRotation'
          //   Constant: '<S3>/InitialFlightPathAngle'
          //   Constant: '<S3>/InitialRollAngle'
          //   Constant: '<S3>/InitialRollAngleRate'
          //   DataTypeConversion: '<S3>/Param3'
          //   Product: '<S3>/EastDis'
          //   Product: '<S3>/NorthDis'
          //   Sum: '<S3>/SumInitEast'
          //   Sum: '<S3>/SumInitNorth'
          //   Trigonometry: '<S3>/Cos'
          //   Trigonometry: '<S3>/Sin'
          //   UnaryMinus: '<S31>/Ze2height'

          rty_InitialState[0] = std::cos(rtb_Down_c) * rtb_Param1_f + rtb_Down;
          rty_InitialState[1] = rtb_Param1_f * std::sin(rtb_Down_c) +
            rtb_Switch_aa;
          rty_InitialState[2] = rtb_Sum;
          rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
          rty_InitialState[4] = rtb_Down_c + 1.5707963267948966;
          rty_InitialState[5] = 0.0;
          rty_InitialState[6] = 0.0;
          rty_InitialState[7] = 0.0;

          // SignalConversion generated from: '<S3>/Orbit Follower'
          *rty_thisTaskStatus = localB->OrbitFollower_b.OrbitFollower_o6;
        } else {
          localDW->is_OrbitFollower =
            PreemptableMissionModeSelector_IN_CircleDisplayNav;

          // DataTypeConversion: '<S2>/Param1'
          rtb_Param1_i = static_cast<real_T>(rtu_Parameters->Param1);

          // Product: '<S2>/Divide'
          rtb_Down_c = rtu_StartPosition->Lat / rtb_Param1_i;

          // Switch: '<S22>/Switch' incorporates:
          //   Abs: '<S22>/Abs'
          //   Bias: '<S22>/Bias'
          //   Bias: '<S22>/Bias1'
          //   Constant: '<S22>/Constant2'
          //   Constant: '<S23>/Constant'
          //   DataStoreRead: '<S2>/LatitudeGCS'
          //   Math: '<S22>/Math Function1'
          //   RelationalOperator: '<S23>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            rtb_Down = LatitudeGCS;
          }

          // Abs: '<S19>/Abs1'
          rtb_Switch_aa = std::abs(rtb_Down);

          // Switch: '<S19>/Switch' incorporates:
          //   Bias: '<S19>/Bias'
          //   Bias: '<S19>/Bias1'
          //   Constant: '<S10>/Constant'
          //   Constant: '<S10>/Constant1'
          //   Constant: '<S21>/Constant'
          //   Gain: '<S19>/Gain'
          //   Product: '<S19>/Divide1'
          //   RelationalOperator: '<S21>/Compare'
          //   Switch: '<S10>/Switch1'

          if (rtb_Switch_aa > 90.0) {
            // Signum: '<S19>/Sign1'
            if (rtb_Down < 0.0) {
              rtb_Down = -1.0;
            } else if (rtb_Down > 0.0) {
              rtb_Down = 1.0;
            } else if (rtb_Down == 0.0) {
              rtb_Down = 0.0;
            } else {
              rtb_Down = (rtNaN);
            }

            rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S10>/Sum' incorporates:
          //   DataStoreRead: '<S2>/LongitudeGCS'

          rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

          // Sum: '<S8>/Sum1'
          rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

          // Switch: '<S20>/Switch' incorporates:
          //   Abs: '<S20>/Abs'
          //   Bias: '<S20>/Bias'
          //   Bias: '<S20>/Bias1'
          //   Constant: '<S20>/Constant2'
          //   Constant: '<S24>/Constant'
          //   Math: '<S20>/Math Function1'
          //   RelationalOperator: '<S24>/Compare'

          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S8>/Sum1'
          rtb_Sum = rtu_Location->Lon - rtb_Sum;

          // Switch: '<S16>/Switch' incorporates:
          //   Abs: '<S16>/Abs'
          //   Bias: '<S16>/Bias'
          //   Bias: '<S16>/Bias1'
          //   Constant: '<S16>/Constant2'
          //   Constant: '<S17>/Constant'
          //   Math: '<S16>/Math Function1'
          //   RelationalOperator: '<S17>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S13>/Abs1'
          rtb_Abs1_jo = std::abs(rtb_Switch_aa);

          // Switch: '<S13>/Switch' incorporates:
          //   Bias: '<S13>/Bias'
          //   Bias: '<S13>/Bias1'
          //   Constant: '<S15>/Constant'
          //   Constant: '<S9>/Constant'
          //   Constant: '<S9>/Constant1'
          //   Gain: '<S13>/Gain'
          //   Product: '<S13>/Divide1'
          //   RelationalOperator: '<S15>/Compare'
          //   Switch: '<S9>/Switch1'

          if (rtb_Abs1_jo > 90.0) {
            // Signum: '<S13>/Sign1'
            if (rtb_Switch_aa < 0.0) {
              rtb_Switch_aa = -1.0;
            } else if (rtb_Switch_aa > 0.0) {
              rtb_Switch_aa = 1.0;
            } else if (rtb_Switch_aa == 0.0) {
              rtb_Switch_aa = 0.0;
            } else {
              rtb_Switch_aa = (rtNaN);
            }

            rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
            b_nrows = 180;
          } else {
            rtb_Abs1_jo = rtb_Switch_aa;
            b_nrows = 0;
          }

          // Sum: '<S9>/Sum'
          rtb_Sum += static_cast<real_T>(b_nrows);

          // UnitConversion: '<S12>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

          // UnitConversion: '<S27>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Down *= 0.017453292519943295;

          // Trigonometry: '<S28>/Trigonometric Function1'
          rtb_Param4_e = std::sin(rtb_Down);

          // Sum: '<S28>/Sum1' incorporates:
          //   Constant: '<S28>/Constant'
          //   Product: '<S28>/Product1'

          rtb_Param4_e = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_g *
            PreemptableMissionModeSelector_ConstB.sqrt_g * rtb_Param4_e *
            rtb_Param4_e;

          // Product: '<S26>/Product1' incorporates:
          //   Constant: '<S26>/Constant1'
          //   Sqrt: '<S26>/sqrt'

          rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

          // Product: '<S11>/dNorth' incorporates:
          //   Constant: '<S26>/Constant2'
          //   Product: '<S26>/Product3'
          //   Trigonometry: '<S26>/Trigonometric Function1'

          rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
            PreemptableMissionModeSelector_ConstB.Sum1_kk / rtb_Param4_e);

          // Switch: '<S14>/Switch' incorporates:
          //   Abs: '<S14>/Abs'
          //   Bias: '<S14>/Bias'
          //   Bias: '<S14>/Bias1'
          //   Constant: '<S14>/Constant2'
          //   Constant: '<S18>/Constant'
          //   Math: '<S14>/Math Function1'
          //   RelationalOperator: '<S18>/Compare'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Product: '<S11>/dEast' incorporates:
          //   Constant: '<S26>/Constant3'
          //   Product: '<S26>/Product4'
          //   Trigonometry: '<S26>/Trigonometric Function'
          //   Trigonometry: '<S26>/Trigonometric Function2'
          //   UnitConversion: '<S12>/Unit Conversion'

          rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos(rtb_Down))
            * (0.017453292519943295 * rtb_Sum);

          // Sum: '<S11>/Sum2' incorporates:
          //   Product: '<S11>/x*cos'
          //   Product: '<S11>/y*sin'

          rtb_Down = rtb_Abs1_jo * 0.0 + rtb_Param4_e;

          // Sum: '<S11>/Sum3' incorporates:
          //   Product: '<S11>/x*sin'
          //   Product: '<S11>/y*cos'

          rtb_Switch_aa = rtb_Abs1_jo - rtb_Param4_e * 0.0;

          // Sum: '<S8>/Sum' incorporates:
          //   DataStoreRead: '<S2>/AltitudeGCS'
          //   Gain: '<S2>/inverse'

          rtb_Sum = rtu_Location->Alt + -AltitudeGCS;

          // Sum: '<S2>/SumUp' incorporates:
          //   UnaryMinus: '<S8>/Ze2height'

          rtb_Sum += rtu_StartPosition->Alt;

          // SignalConversion generated from: '<S2>/Orbit Follower' incorporates:
          //   Gain: '<S2>/Up2Down'

          rtb_TmpSignalConversionAtOrbitFollowerInport2_b[0] = rtb_Down;
          rtb_TmpSignalConversionAtOrbitFollowerInport2_b[1] = rtb_Switch_aa;
          rtb_TmpSignalConversionAtOrbitFollowerInport2_b[2] = -rtb_Sum;

          // DataTypeConversion: '<S2>/Param2'
          rtb_Param2_n1 = static_cast<real_T>(rtu_Parameters->Param2);
          PreemptableMissionModeSelector_OrbitFollower(rtu_Pose,
            rtb_TmpSignalConversionAtOrbitFollowerInport2_b, rtb_Param1_i,
            rtb_Param2_n1, 1.0, &localB->OrbitFollower, &localDW->OrbitFollower);

          // BusCreator: '<S2>/GuidanceCMDBusCreator' incorporates:
          //   Constant: '<S2>/Constant'
          //   DataTypeConversion: '<S2>/Param3'
          //   Gain: '<S2>/Down2Height'

          rty_GuidanceCmds->Height = -localB->OrbitFollower.OrbitFollower_o1[2];
          rty_GuidanceCmds->AirSpeed = static_cast<real_T>
            (rtu_Parameters->Param4);
          rty_GuidanceCmds->HeadingAngle =
            localB->OrbitFollower.OrbitFollower_o2;

          // Reshape: '<S2>/Reshape' incorporates:
          //   Bias: '<S2>/ClockwiseRotation'
          //   Constant: '<S2>/InitialFlightPathAngle'
          //   Constant: '<S2>/InitialRollAngle'
          //   Constant: '<S2>/InitialRollAngleRate'
          //   DataTypeConversion: '<S2>/Param3'
          //   Product: '<S2>/EastDis'
          //   Product: '<S2>/NorthDis'
          //   Sum: '<S2>/SumInitEast'
          //   Sum: '<S2>/SumInitNorth'
          //   Trigonometry: '<S2>/Cos'
          //   Trigonometry: '<S2>/Sin'

          rty_InitialState[0] = std::cos(rtb_Down_c) * rtb_Param1_i + rtb_Down;
          rty_InitialState[1] = rtb_Param1_i * std::sin(rtb_Down_c) +
            rtb_Switch_aa;
          rty_InitialState[2] = rtb_Sum;
          rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
          rty_InitialState[4] = rtb_Down_c + 1.5707963267948966;
          rty_InitialState[5] = 0.0;
          rty_InitialState[6] = 0.0;
          rty_InitialState[7] = 0.0;

          // SignalConversion generated from: '<S2>/Orbit Follower'
          *rty_thisTaskStatus = localB->OrbitFollower.OrbitFollower_o6;
        }
      } else {
        sf_internal_predicateOutput = ((*rtu_mode == 2) || (*rtu_mode == 22));
        if (sf_internal_predicateOutput) {
          PreemptableMissionModeSelector_exit_internal_GuidanceLogic(localDW);
          localDW->is_GuidanceLogic =
            PreemptableMissionModeSelector_IN_WaypointFollower;
          *rty_ResetTrigger = 1.0;
          if (*rtu_mode == 2) {
            localDW->is_WaypointFollower =
              PreemptableMissionModeSelector_IN_HorizontalFormationNav;

            // Sum: '<S166>/Sum' incorporates:
            //   DataStoreRead: '<S7>/AltitudeGCS'
            //   Gain: '<S7>/inverse'

            rtb_Switch_aa = rtu_Location->Alt + -AltitudeGCS;

            // DataTypeConversion: '<S7>/CastToDouble'
            rtb_Switch_e = static_cast<real_T>(*rtu_FormationIDX);

            // Sum: '<S7>/Minus' incorporates:
            //   Constant: '<S7>/One2ZeroIdx'

            rtb_Switch_e--;

            // Gain: '<S7>/Gain' incorporates:
            //   Constant: '<S7>/Three'
            //   Math: '<S7>/ModRunWayLayer'

            rtb_Down_c = 15.0 * rt_modd_snf(rtb_Switch_e, 3.0);

            // Sum: '<S7>/BiasMissionAlt' incorporates:
            //   UnaryMinus: '<S166>/Ze2height'

            rtb_Down = -rtb_Switch_aa - rtb_Down_c;

            // Sum: '<S167>/Sum' incorporates:
            //   DataStoreRead: '<S7>/PrevAltitudeGCS'
            //   Gain: '<S7>/PrevInverse'

            rtb_Switch_aa = rtu_PrevLocation->Alt + -AltitudeGCS;

            // Sum: '<S7>/BiasPrevAlt' incorporates:
            //   UnaryMinus: '<S167>/Ze2height'

            rtb_Down_c = -rtb_Switch_aa - rtb_Down_c;

            // Switch: '<S182>/Switch' incorporates:
            //   Abs: '<S182>/Abs'
            //   Bias: '<S182>/Bias'
            //   Bias: '<S182>/Bias1'
            //   Constant: '<S182>/Constant2'
            //   Constant: '<S183>/Constant'
            //   DataStoreRead: '<S7>/LatitudeGCS'
            //   Math: '<S182>/Math Function1'
            //   RelationalOperator: '<S183>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch = LatitudeGCS;
            }

            // Abs: '<S179>/Abs1'
            rtb_Switch_aa = std::abs(rtb_Switch);

            // Switch: '<S179>/Switch' incorporates:
            //   Bias: '<S179>/Bias'
            //   Bias: '<S179>/Bias1'
            //   Constant: '<S170>/Constant'
            //   Constant: '<S170>/Constant1'
            //   Constant: '<S181>/Constant'
            //   Gain: '<S179>/Gain'
            //   Product: '<S179>/Divide1'
            //   RelationalOperator: '<S181>/Compare'
            //   Switch: '<S170>/Switch1'

            if (rtb_Switch_aa > 90.0) {
              // Signum: '<S179>/Sign1'
              if (rtb_Switch < 0.0) {
                rtb_Switch = -1.0;
              } else if (rtb_Switch > 0.0) {
                rtb_Switch = 1.0;
              } else if (rtb_Switch == 0.0) {
                rtb_Switch = 0.0;
              } else {
                rtb_Switch = (rtNaN);
              }

              rtb_Switch *= -(rtb_Switch_aa + -90.0) + 90.0;
              b_nrows = 180;
            } else {
              b_nrows = 0;
            }

            // Sum: '<S170>/Sum' incorporates:
            //   DataStoreRead: '<S7>/LongitudeGCS'

            rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

            // Sum: '<S166>/Sum1'
            rtb_Switch_aa = rtu_Location->Lat - rtb_Switch;

            // Switch: '<S180>/Switch' incorporates:
            //   Abs: '<S180>/Abs'
            //   Bias: '<S180>/Bias'
            //   Bias: '<S180>/Bias1'
            //   Constant: '<S180>/Constant2'
            //   Constant: '<S184>/Constant'
            //   Math: '<S180>/Math Function1'
            //   RelationalOperator: '<S184>/Compare'

            if (std::abs(rtb_Sum) > 180.0) {
              rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S166>/Sum1'
            rtb_Sum = rtu_Location->Lon - rtb_Sum;

            // Switch: '<S176>/Switch' incorporates:
            //   Abs: '<S176>/Abs'
            //   Bias: '<S176>/Bias'
            //   Bias: '<S176>/Bias1'
            //   Constant: '<S176>/Constant2'
            //   Constant: '<S177>/Constant'
            //   Math: '<S176>/Math Function1'
            //   RelationalOperator: '<S177>/Compare'

            if (std::abs(rtb_Switch_aa) > 180.0) {
              rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S173>/Abs1'
            rtb_Abs1_jo = std::abs(rtb_Switch_aa);

            // Switch: '<S173>/Switch' incorporates:
            //   Bias: '<S173>/Bias'
            //   Bias: '<S173>/Bias1'
            //   Constant: '<S169>/Constant'
            //   Constant: '<S169>/Constant1'
            //   Constant: '<S175>/Constant'
            //   Gain: '<S173>/Gain'
            //   Product: '<S173>/Divide1'
            //   RelationalOperator: '<S175>/Compare'
            //   Switch: '<S169>/Switch1'

            if (rtb_Abs1_jo > 90.0) {
              // Signum: '<S173>/Sign1'
              if (rtb_Switch_aa < 0.0) {
                rtb_Switch_aa = -1.0;
              } else if (rtb_Switch_aa > 0.0) {
                rtb_Switch_aa = 1.0;
              } else if (rtb_Switch_aa == 0.0) {
                rtb_Switch_aa = 0.0;
              } else {
                rtb_Switch_aa = (rtNaN);
              }

              rtb_Param4_e = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
              b_nrows = 180;
            } else {
              rtb_Param4_e = rtb_Switch_aa;
              b_nrows = 0;
            }

            // Sum: '<S169>/Sum'
            rtb_Abs1_jo = static_cast<real_T>(b_nrows) + rtb_Sum;

            // UnitConversion: '<S172>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_aa = 0.017453292519943295 * rtb_Param4_e;

            // UnitConversion: '<S187>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch *= 0.017453292519943295;

            // Trigonometry: '<S188>/Trigonometric Function1'
            rtb_Sum = std::sin(rtb_Switch);

            // Sum: '<S188>/Sum1' incorporates:
            //   Constant: '<S188>/Constant'
            //   Product: '<S188>/Product1'

            rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_b *
              PreemptableMissionModeSelector_ConstB.sqrt_b * rtb_Sum * rtb_Sum;

            // Product: '<S186>/Product1' incorporates:
            //   Constant: '<S186>/Constant1'
            //   Sqrt: '<S186>/sqrt'

            rtb_Param4_e = 6.378137E+6 / std::sqrt(rtb_Sum);

            // Product: '<S171>/dNorth' incorporates:
            //   Constant: '<S186>/Constant2'
            //   Product: '<S186>/Product3'
            //   Trigonometry: '<S186>/Trigonometric Function1'

            rtb_Sum = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Param4_e *
              PreemptableMissionModeSelector_ConstB.Sum1_d / rtb_Sum);

            // Switch: '<S174>/Switch' incorporates:
            //   Abs: '<S174>/Abs'
            //   Bias: '<S174>/Bias'
            //   Bias: '<S174>/Bias1'
            //   Constant: '<S174>/Constant2'
            //   Constant: '<S178>/Constant'
            //   Math: '<S174>/Math Function1'
            //   RelationalOperator: '<S178>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Abs1_jo) > 180.0) {
              rtb_Abs1_jo = rt_modd_snf(rtb_Abs1_jo + 180.0, 360.0) + -180.0;
            }

            // Product: '<S171>/dEast' incorporates:
            //   Constant: '<S186>/Constant3'
            //   Product: '<S186>/Product4'
            //   Trigonometry: '<S186>/Trigonometric Function'
            //   Trigonometry: '<S186>/Trigonometric Function2'
            //   UnitConversion: '<S172>/Unit Conversion'

            rtb_Param4_e = 1.0 / rt_atan2d_snf(1.0, rtb_Param4_e * std::cos
              (rtb_Switch)) * (0.017453292519943295 * rtb_Abs1_jo);

            // Sum: '<S171>/Sum2' incorporates:
            //   Product: '<S171>/x*cos'
            //   Product: '<S171>/y*sin'

            rtb_Abs1_jo = rtb_Param4_e * 0.0 + rtb_Sum;

            // Sum: '<S171>/Sum3' incorporates:
            //   Product: '<S171>/x*sin'
            //   Product: '<S171>/y*cos'

            rtb_Param4_e -= rtb_Sum * 0.0;

            // Product: '<S7>/Map2Radian' incorporates:
            //   DataTypeConversion: '<S7>/Param3'

            rtb_Switch_e *= static_cast<real_T>(rtu_Parameters->Param3);

            // Gain: '<S165>/Gain1'
            rtb_Gain1 = 0.017453292519943295 * rtu_Location->degHDG;

            // Outputs for Triggered SubSystem: '<S7>/WayPointGenerator' incorporates:
            //   TriggerPort: '<S168>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &localZCE->WayPointGenerator_Trig_ZCE,
                               (localDW->MemoryTriggerWP_PreviousInput));
            if (zcEvent != NO_ZCEVENT) {
              // Product: '<S168>/ProductScanWidth' incorporates:
              //   DataTypeConversion: '<S7>/Param3'

              rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) *
                static_cast<real_T>(*rtu_MissionUAV);

              // Reshape: '<S168>/ReshapeRowVec'
              rtb_ReshapeRowVec[0] = rtb_Abs1_jo;
              rtb_ReshapeRowVec[1] = rtb_Param4_e;
              rtb_ReshapeRowVec[2] = rtb_Down;

              // SignalConversion generated from: '<S168>/RotateATMissionHdg' incorporates:
              //   Constant: '<S168>/Zero'

              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = rtb_Gain1;
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] = 0.0;
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
              PreemptableMissionModeSelector_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1,
                 &localB->RotateATMissionHdg_baf);

              // MATLAB Function: '<S168>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S7>/Param2'

              rtb_Switch_aa = std::ceil(static_cast<real_T>
                (rtu_Parameters->Param2) / rtb_Switch_aa);
              rtb_Sum = static_cast<real_T>(rtu_Parameters->Param2) /
                rtb_Switch_aa;
              connectionObj.FlightPathAngleLimit[0] = -0.175;
              connectionObj.FlightPathAngleLimit[1] = 0.175;
              connectionObj.MaxRollAngle = 0.29670597283903605;
              connectionObj.AirSpeed = 35.0;
              connectionObj.MinTurningRadius = 408.85657731051754;
              b_nrows = static_cast<int32_T>(rtb_Switch_aa * 2.0);
              rtb_ClockwiseRotation_n = static_cast<int32_T>(CheckPoints->size[0]
                * CheckPoints->size[1]);

              // MATLAB Function: '<S168>/WayPointGenerator'
              CheckPoints->size[0] = b_nrows;
              CheckPoints->size[1] = 4;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (CheckPoints, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S168>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S7>/Param1'

              ibmat = static_cast<int32_T>(static_cast<int32_T>(b_nrows << 2) -
                1);
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= ibmat;
                   rtb_ClockwiseRotation_n++) {
                CheckPoints->data[rtb_ClockwiseRotation_n] = 0.0;
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                   rtb_ClockwiseRotation_n = static_cast<int32_T>
                   (rtb_ClockwiseRotation_n + 1)) {
                if (rt_remd_snf(static_cast<real_T>(rtb_ClockwiseRotation_n) +
                                1.0, 2.0) == 1.0) {
                  b_nrows = static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 1) << 1);
                  rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n) +
                                 1.0) - 1.0) * rtb_Sum;
                  CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                    rtb_Switch;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + CheckPoints->size[0]) - 2)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1))
                    - 2)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) -
                    2)] = 1.5707963267948966;
                  CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                    rtb_Switch;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + CheckPoints->size[0]) - 1)] = static_cast<real_T>
                    (rtu_Parameters->Param1);
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1))
                    - 1)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) -
                    1)] = 1.5707963267948966;
                } else {
                  b_nrows = static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 1) << 1);
                  rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n) +
                                 1.0) - 1.0) * rtb_Sum;
                  CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                    rtb_Switch;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + CheckPoints->size[0]) - 2)] = static_cast<real_T>
                    (rtu_Parameters->Param1);
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1))
                    - 2)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) -
                    2)] = -1.5707963267948966;
                  CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                    rtb_Switch;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + CheckPoints->size[0]) - 1)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1))
                    - 1)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) -
                    1)] = -1.5707963267948966;
                }
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);

              // MATLAB Function: '<S168>/WayPointGenerator'
              dummyWayPoint->size[0] = 1;
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S168>/WayPointGenerator'
              dummyWayPoint->data[0] = 0.0;
              dummyWayPoint->data[1] = 0.0;
              dummyWayPoint->data[2] = 0.0;
              for (nrowx = 0; nrowx <= static_cast<int32_T>(CheckPoints->size[0]
                    - 2); nrowx = static_cast<int32_T>(nrowx + 1)) {
                LUp[0] = CheckPoints->data[nrowx];
                LDp[0] = CheckPoints->data[static_cast<int32_T>(nrowx + 1)];
                LUp[1] = CheckPoints->data[static_cast<int32_T>(nrowx +
                  CheckPoints->size[0])];
                LDp[1] = CheckPoints->data[static_cast<int32_T>
                  (static_cast<int32_T>(nrowx + CheckPoints->size[0]) + 1)];
                LUp[2] = CheckPoints->data[static_cast<int32_T>(nrowx +
                  static_cast<int32_T>(CheckPoints->size[0] << 1))];
                LDp[2] = CheckPoints->data[static_cast<int32_T>
                  (static_cast<int32_T>(nrowx + static_cast<int32_T>
                    (CheckPoints->size[0] << 1)) + 1)];
                LUp[3] = CheckPoints->data[static_cast<int32_T>(nrowx +
                  static_cast<int32_T>(CheckPoints->size[0] * 3))];
                LDp[3] = CheckPoints->data[static_cast<int32_T>
                  (static_cast<int32_T>(nrowx + static_cast<int32_T>
                    (CheckPoints->size[0] * 3)) + 1)];
                PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp,
                  LDp, 100.0, segWayPoints, localB);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);
                dummyWayPoint_0->size[0] = static_cast<int32_T>
                  (dummyWayPoint->size[0] + segWayPoints->size[0]);
                dummyWayPoint_0->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (dummyWayPoint_0, rtb_ClockwiseRotation_n);
                ibmat = dummyWayPoint->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint_0->size[0] * b_nrows))] =
                      dummyWayPoint->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint->size[0] * b_nrows))];
                  }
                }

                ibmat = segWayPoints->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                      (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                        dummyWayPoint->size[0]) + static_cast<int32_T>
                       (dummyWayPoint_0->size[0] * b_nrows))] =
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] * b_nrows))];
                  }
                }

                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (dummyWayPoint->size[0] * dummyWayPoint->size[1]);
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (dummyWayPoint, rtb_ClockwiseRotation_n);
                ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                     b_nrows++) {
                  dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
                }
              }

              LUp[0] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] - 1)];
              LDp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(CheckPoints->size[0] + CheckPoints->size[0])
                 - 1)];
              LDp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(CheckPoints->size[0] + static_cast<int32_T>
                  (CheckPoints->size[0] << 1)) - 1)];
              LDp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] << 1)];
              LUp[3] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(CheckPoints->size[0] + static_cast<int32_T>
                  (CheckPoints->size[0] * 3)) - 1)];
              LDp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] * 3)];
              PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp,
                LDp, 100.0, segWayPoints, localB);
              rtb_ClockwiseRotation_n = static_cast<int32_T>
                (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

              // MATLAB Function: '<S168>/WayPointGenerator'
              dummyWayPoint_0->size[0] = static_cast<int32_T>
                (dummyWayPoint->size[0] + segWayPoints->size[0]);
              dummyWayPoint_0->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint_0, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S168>/WayPointGenerator'
              ibmat = dummyWayPoint->size[0];
              loop_ub = segWayPoints->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint_0->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint_0->size[0] * b_nrows))] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n
                     ++) {
                  dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                    static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                    segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))];
                }
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);

              // MATLAB Function: '<S168>/WayPointGenerator'
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S168>/WayPointGenerator'
              ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
              for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                   b_nrows++) {
                dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
              }

              nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
              nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
              for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                   (b_nrows + 1)) {
                dummyWayPoint->data[b_nrows] = dummyWayPoint->data
                  [static_cast<int32_T>(b_nrows + 1)];
              }

              for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                   (b_nrows + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                  dummyWayPoint->size[0])] = dummyWayPoint->data
                  [static_cast<int32_T>(static_cast<int32_T>(b_nrows +
                  dummyWayPoint->size[0]) + 1)];
              }

              for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                   (b_nrows + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                  static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                  dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(dummyWayPoint->size[0] << 1))
                  + 1)];
              }

              if (1 > nrows) {
                ibmat = -1;
              } else {
                ibmat = nrowx;
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(segWayPoints->size
                [0] * segWayPoints->size[1]);

              // MATLAB Function: '<S168>/WayPointGenerator'
              segWayPoints->size[0] = static_cast<int32_T>(ibmat + 1);
              segWayPoints->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (segWayPoints, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S168>/WayPointGenerator'
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     ibmat; rtb_ClockwiseRotation_n++) {
                  segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))] = dummyWayPoint->data[
                    static_cast<int32_T>(rtb_ClockwiseRotation_n +
                    static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
                }
              }

              if (1 > nrows) {
                b_nrows = -1;
                nrowx = -1;
              } else {
                b_nrows = nrowx;
              }

              rtb_Switch_aa = std::ceil(10240.0 / static_cast<real_T>(
                static_cast<int32_T>(b_nrows + 1)));
              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);

              // MATLAB Function: '<S168>/WayPointGenerator'
              dummyWayPoint->size[0] = static_cast<int32_T>(static_cast<int32_T>
                (nrowx + 1) * static_cast<int32_T>(rtb_Switch_aa));
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S168>/WayPointGenerator'
              b_nrows = segWayPoints->size[0];
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                   rtb_ClockwiseRotation_n = static_cast<int32_T>
                   (rtb_ClockwiseRotation_n + 1)) {
                nrows = static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n * b_nrows) + -1);
                for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                     static_cast<int32_T>(b_nrows - 1); loop_ub =
                     static_cast<int32_T>(loop_ub + 1)) {
                  dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)] =
                    segWayPoints->data[static_cast<int32_T>(loop_ub - 1)];
                }
              }

              ibmat = static_cast<int32_T>(static_cast<int32_T>
                (segWayPoints->size[0] * static_cast<int32_T>(rtb_Switch_aa)) -
                1);
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                   rtb_ClockwiseRotation_n = static_cast<int32_T>
                   (rtb_ClockwiseRotation_n + 1)) {
                nrows = static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n * b_nrows) + ibmat);
                for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                     static_cast<int32_T>(b_nrows - 1); loop_ub =
                     static_cast<int32_T>(loop_ub + 1)) {
                  dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)] =
                    segWayPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + loop_ub) - 1)];
                }
              }

              nrowx = static_cast<int32_T>(segWayPoints->size[0] << 1);
              ibmat = static_cast<int32_T>(static_cast<int32_T>
                (static_cast<int32_T>(segWayPoints->size[0] *
                static_cast<int32_T>(rtb_Switch_aa)) << 1) - 1);
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                   rtb_ClockwiseRotation_n = static_cast<int32_T>
                   (rtb_ClockwiseRotation_n + 1)) {
                nrows = static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n * b_nrows) + ibmat);
                for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                     static_cast<int32_T>(b_nrows - 1); loop_ub =
                     static_cast<int32_T>(loop_ub + 1)) {
                  dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)] =
                    segWayPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (nrowx + loop_ub) - 1)];
                }
              }

              // Reshape: '<S7>/Reshape2Row' incorporates:
              //   Memory: '<S7>/MemoryPrevRelPos'

              rtb_Reshape_i[0] = localDW->MemoryPrevRelPos_PreviousInput[1];
              rtb_Reshape_i[1] = localDW->MemoryPrevRelPos_PreviousInput[0];
              rtb_Reshape_i[2] = localDW->MemoryPrevRelPos_PreviousInput[2];

              // Product: '<S168>/RotateRelPrevPos' incorporates:
              //   MATLABSystem: '<S168>/RotateATMissionHdg'

              rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtb_Reshape_i,
                localB->RotateATMissionHdg_baf.RotateATMissionHdg,
                rtb_startPose_h);

              // MATLAB Function: '<S168>/WayPointGenerator'
              LDp[0] = rtb_startPose_h[0];
              LDp[1] = rtb_startPose_h[1];
              LDp[2] = rtb_startPose_h[2];
              LDp[3] = 1.5707963267948966;
              LUp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] << 1)];
              LUp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] * 3)];
              PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LDp,
                LUp, 100.0, segWayPoints, localB);
              rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size
                [0] * initWayPoint->size[1]);

              // MATLAB Function: '<S168>/WayPointGenerator'
              initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0]
                + dummyWayPoint->size[0]);
              initWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (initWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S168>/WayPointGenerator'
              ibmat = segWayPoints->size[0];
              loop_ub = dummyWayPoint->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  initWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (initWayPoint->size[0] * b_nrows))] = segWayPoints->data[
                    static_cast<int32_T>(rtb_ClockwiseRotation_n + static_cast<
                    int32_T>(segWayPoints->size[0] * b_nrows))];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n
                     ++) {
                  initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + segWayPoints->size[0]) +
                    static_cast<int32_T>(initWayPoint->size[0] * b_nrows))] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                     10240; rtb_ClockwiseRotation_n++) {
                  localB->WayPoint[static_cast<int32_T>(rtb_ClockwiseRotation_n
                    + static_cast<int32_T>(10240 * b_nrows))] =
                    initWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (initWayPoint->size[0] * b_nrows))];
                }
              }

              // MATLAB Function: '<S168>/biasWayPoint'
              for (b_nrows = 0; b_nrows < 10240; b_nrows++) {
                localB->rtb_WayPoint_m[b_nrows] = localB->WayPoint[b_nrows] +
                  rtb_Switch_e;
                localB->rtb_WayPoint_m[static_cast<int32_T>(b_nrows + 10240)] =
                  localB->WayPoint[static_cast<int32_T>(b_nrows + 10240)];
                localB->rtb_WayPoint_m[static_cast<int32_T>(b_nrows + 20480)] =
                  localB->WayPoint[static_cast<int32_T>(b_nrows + 20480)];
              }

              // Product: '<S168>/RotateIndivWayPoint' incorporates:
              //   MATLABSystem: '<S168>/RotateATMissionHdg'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                     10240; rtb_ClockwiseRotation_n++) {
                  ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                    static_cast<int32_T>(10240 * b_nrows));
                  localB->RotateIndivWayPoint[ibmat] = 0.0;
                  localB->RotateIndivWayPoint[ibmat] +=
                    localB->RotateATMissionHdg_baf.RotateATMissionHdg[
                    static_cast<int32_T>(3 * b_nrows)] * localB->
                    rtb_WayPoint_m[rtb_ClockwiseRotation_n];
                  localB->RotateIndivWayPoint[ibmat] +=
                    localB->RotateATMissionHdg_baf.RotateATMissionHdg[
                    static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)]
                    * localB->rtb_WayPoint_m[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 10240)];
                  localB->RotateIndivWayPoint[ibmat] +=
                    localB->RotateATMissionHdg_baf.RotateATMissionHdg[
                    static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)]
                    * localB->rtb_WayPoint_m[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 20480)];
                }
              }

              // MATLAB Function: '<S168>/biasNED'
              PreemptableMissionModeSelector_biasNED_l(rtb_ReshapeRowVec,
                localB->RotateIndivWayPoint, localB->nedWayPoint,
                &localB->sf_biasNED_j);
            }

            // End of Outputs for SubSystem: '<S7>/WayPointGenerator'
            PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
              localB->nedWayPoint, 200.0, &localB->WaypointFollower_baf,
              &localDW->WaypointFollower_baf);

            // DataTypeConversion: '<S7>/Cast To Double' incorporates:
            //   Constant: '<S7>/LookAheadDis'
            //   MATLAB Function: '<S168>/WayPointGenerator'
            //   Memory: '<S7>/MemoryTriggerWP'

            *rty_thisTaskStatus = static_cast<real_T>
              (localB->WaypointFollower_baf.WaypointFollower_o5);

            // BusCreator: '<S7>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S7>/Param4'
            //   Gain: '<S7>/Down2Height'

            rty_GuidanceCmds->Height =
              -localB->WaypointFollower_baf.WaypointFollower_o1[2];
            rty_GuidanceCmds->AirSpeed = static_cast<real_T>
              (rtu_Parameters->Param4);
            rty_GuidanceCmds->HeadingAngle =
              localB->WaypointFollower_baf.WaypointFollower_o2;

            // Switch: '<S204>/Switch' incorporates:
            //   Abs: '<S204>/Abs'
            //   Bias: '<S204>/Bias'
            //   Bias: '<S204>/Bias1'
            //   Constant: '<S204>/Constant2'
            //   Constant: '<S205>/Constant'
            //   DataStoreRead: '<S7>/PrevLatitudeGCS'
            //   Math: '<S204>/Math Function1'
            //   RelationalOperator: '<S205>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              rtb_Switch_p = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch_p = LatitudeGCS;
            }

            // Abs: '<S201>/Abs1'
            rtb_Switch_aa = std::abs(rtb_Switch_p);

            // Switch: '<S201>/Switch' incorporates:
            //   Bias: '<S201>/Bias'
            //   Bias: '<S201>/Bias1'
            //   Constant: '<S192>/Constant'
            //   Constant: '<S192>/Constant1'
            //   Constant: '<S203>/Constant'
            //   Gain: '<S201>/Gain'
            //   Product: '<S201>/Divide1'
            //   RelationalOperator: '<S203>/Compare'
            //   Switch: '<S192>/Switch1'

            if (rtb_Switch_aa > 90.0) {
              // Signum: '<S201>/Sign1'
              if (rtb_Switch_p < 0.0) {
                rtb_Switch_p = -1.0;
              } else if (rtb_Switch_p > 0.0) {
                rtb_Switch_p = 1.0;
              } else if (rtb_Switch_p == 0.0) {
                rtb_Switch_p = 0.0;
              } else {
                rtb_Switch_p = (rtNaN);
              }

              rtb_Switch_p *= -(rtb_Switch_aa + -90.0) + 90.0;
              b_nrows = 180;
            } else {
              b_nrows = 0;
            }

            // Sum: '<S192>/Sum' incorporates:
            //   DataStoreRead: '<S7>/PrevLongitudeGCS'

            rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

            // Sum: '<S167>/Sum1'
            rtb_Switch_aa = rtu_PrevLocation->Lat - rtb_Switch_p;

            // Switch: '<S202>/Switch' incorporates:
            //   Abs: '<S202>/Abs'
            //   Bias: '<S202>/Bias'
            //   Bias: '<S202>/Bias1'
            //   Constant: '<S202>/Constant2'
            //   Constant: '<S206>/Constant'
            //   Math: '<S202>/Math Function1'
            //   RelationalOperator: '<S206>/Compare'

            if (std::abs(rtb_Sum) > 180.0) {
              rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S167>/Sum1'
            rtb_Sum = rtu_PrevLocation->Lon - rtb_Sum;

            // Switch: '<S198>/Switch' incorporates:
            //   Abs: '<S198>/Abs'
            //   Bias: '<S198>/Bias'
            //   Bias: '<S198>/Bias1'
            //   Constant: '<S198>/Constant2'
            //   Constant: '<S199>/Constant'
            //   Math: '<S198>/Math Function1'
            //   RelationalOperator: '<S199>/Compare'

            if (std::abs(rtb_Switch_aa) > 180.0) {
              rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S195>/Abs1'
            rtb_Switch = std::abs(rtb_Switch_aa);

            // Switch: '<S195>/Switch' incorporates:
            //   Bias: '<S195>/Bias'
            //   Bias: '<S195>/Bias1'
            //   Constant: '<S191>/Constant'
            //   Constant: '<S191>/Constant1'
            //   Constant: '<S197>/Constant'
            //   Gain: '<S195>/Gain'
            //   Product: '<S195>/Divide1'
            //   RelationalOperator: '<S197>/Compare'
            //   Switch: '<S191>/Switch1'

            if (rtb_Switch > 90.0) {
              // Signum: '<S195>/Sign1'
              if (rtb_Switch_aa < 0.0) {
                rtb_Switch_aa = -1.0;
              } else if (rtb_Switch_aa > 0.0) {
                rtb_Switch_aa = 1.0;
              } else if (rtb_Switch_aa == 0.0) {
                rtb_Switch_aa = 0.0;
              } else {
                rtb_Switch_aa = (rtNaN);
              }

              rtb_Switch = (-(rtb_Switch + -90.0) + 90.0) * rtb_Switch_aa;
              b_nrows = 180;
            } else {
              rtb_Switch = rtb_Switch_aa;
              b_nrows = 0;
            }

            // Sum: '<S191>/Sum'
            rtb_Switch_aa = static_cast<real_T>(b_nrows) + rtb_Sum;

            // UnitConversion: '<S209>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_p *= 0.017453292519943295;

            // Trigonometry: '<S210>/Trigonometric Function1'
            rtb_Sum = std::sin(rtb_Switch_p);

            // Sum: '<S210>/Sum1' incorporates:
            //   Constant: '<S210>/Constant'
            //   Product: '<S210>/Product1'

            rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_c *
              PreemptableMissionModeSelector_ConstB.sqrt_c * rtb_Sum * rtb_Sum;

            // Product: '<S208>/Product1' incorporates:
            //   Constant: '<S208>/Constant1'
            //   Sqrt: '<S208>/sqrt'

            rtb_SumInitEast_j = 6.378137E+6 / std::sqrt(rtb_Sum);

            // Product: '<S208>/Product4' incorporates:
            //   Trigonometry: '<S208>/Trigonometric Function'

            rtb_Switch_p = rtb_SumInitEast_j * std::cos(rtb_Switch_p);

            // Product: '<S193>/dNorth' incorporates:
            //   Constant: '<S208>/Constant2'
            //   Product: '<S208>/Product3'
            //   Trigonometry: '<S208>/Trigonometric Function1'
            //   UnitConversion: '<S194>/Unit Conversion'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_SumInitEast_j = 0.017453292519943295 * rtb_Switch /
              rt_atan2d_snf(1.0, rtb_SumInitEast_j *
                            PreemptableMissionModeSelector_ConstB.Sum1_in /
                            rtb_Sum);

            // Switch: '<S196>/Switch' incorporates:
            //   Abs: '<S196>/Abs'
            //   Bias: '<S196>/Bias'
            //   Bias: '<S196>/Bias1'
            //   Constant: '<S196>/Constant2'
            //   Constant: '<S200>/Constant'
            //   Math: '<S196>/Math Function1'
            //   RelationalOperator: '<S200>/Compare'

            if (std::abs(rtb_Switch_aa) > 180.0) {
              rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
            }

            // Product: '<S193>/dEast' incorporates:
            //   Constant: '<S208>/Constant3'
            //   Trigonometry: '<S208>/Trigonometric Function2'
            //   UnitConversion: '<S194>/Unit Conversion'

            rtb_Sum = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_p) *
              (0.017453292519943295 * rtb_Switch_aa);

            // Sum: '<S193>/Sum2' incorporates:
            //   Product: '<S193>/x*cos'
            //   Product: '<S193>/y*sin'

            rtb_Switch = rtb_Sum * 0.0 + rtb_SumInitEast_j;

            // Sum: '<S193>/Sum3' incorporates:
            //   Product: '<S193>/x*sin'
            //   Product: '<S193>/y*cos'

            rtb_SumInitEast_j = rtb_Sum - rtb_SumInitEast_j * 0.0;

            // Reshape: '<S7>/Reshape' incorporates:
            //   Bias: '<S7>/Rotate90deg'
            //   Constant: '<S7>/InitialFlightPathAngle'
            //   Constant: '<S7>/InitialRollAngle'
            //   Constant: '<S7>/InitialRollAngleRate'
            //   DataTypeConversion: '<S7>/Param4'
            //   Gain: '<S7>/Down2Up'
            //   Product: '<S7>/ProductEast'
            //   Product: '<S7>/ProductNorth'
            //   Sum: '<S7>/SumInitEast'
            //   Sum: '<S7>/SumInitNorth'
            //   Trigonometry: '<S7>/Cos'
            //   Trigonometry: '<S7>/Sin'

            rty_InitialState[0] = std::cos(rtb_Gain1 + 1.5707963267948966) *
              rtb_Switch_e + rtb_Switch;
            rty_InitialState[1] = std::sin(rtb_Gain1 + 1.5707963267948966) *
              rtb_Switch_e + rtb_SumInitEast_j;
            rty_InitialState[2] = -rtb_Down_c;
            rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
            rty_InitialState[4] = rtb_Gain1;
            rty_InitialState[5] = 0.0;
            rty_InitialState[6] = 0.0;
            rty_InitialState[7] = 0.0;

            // Update for Memory: '<S7>/MemoryPrevRelPos' incorporates:
            //   Sum: '<S7>/RelPrevPos'

            localDW->MemoryPrevRelPos_PreviousInput[0] = rtb_Switch -
              rtb_Abs1_jo;
            localDW->MemoryPrevRelPos_PreviousInput[1] = rtb_SumInitEast_j -
              rtb_Param4_e;
            localDW->MemoryPrevRelPos_PreviousInput[2] = rtb_Down_c - rtb_Down;

            // Update for Memory: '<S7>/MemoryTriggerWP' incorporates:
            //   Constant: '<S7>/TirggerWayPointGen'

            localDW->MemoryTriggerWP_PreviousInput = 1.0;
          } else {
            localDW->is_WaypointFollower =
              PreemptableMissionModeSelector_IN_CustomFormationNav;

            // Switch: '<S131>/Switch' incorporates:
            //   Abs: '<S131>/Abs'
            //   Bias: '<S131>/Bias'
            //   Bias: '<S131>/Bias1'
            //   Constant: '<S131>/Constant2'
            //   Constant: '<S132>/Constant'
            //   DataStoreRead: '<S6>/LatitudeGCS'
            //   Math: '<S131>/Math Function1'
            //   RelationalOperator: '<S132>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              rtb_Down_c = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Down_c = LatitudeGCS;
            }

            // Abs: '<S128>/Abs1'
            rtb_Switch_aa = std::abs(rtb_Down_c);

            // Switch: '<S128>/Switch' incorporates:
            //   Bias: '<S128>/Bias'
            //   Bias: '<S128>/Bias1'
            //   Constant: '<S119>/Constant'
            //   Constant: '<S119>/Constant1'
            //   Constant: '<S130>/Constant'
            //   Gain: '<S128>/Gain'
            //   Product: '<S128>/Divide1'
            //   RelationalOperator: '<S130>/Compare'
            //   Switch: '<S119>/Switch1'

            if (rtb_Switch_aa > 90.0) {
              // Signum: '<S128>/Sign1'
              if (rtb_Down_c < 0.0) {
                rtb_Down_c = -1.0;
              } else if (rtb_Down_c > 0.0) {
                rtb_Down_c = 1.0;
              } else if (rtb_Down_c == 0.0) {
                rtb_Down_c = 0.0;
              } else {
                rtb_Down_c = (rtNaN);
              }

              rtb_Down_c *= -(rtb_Switch_aa + -90.0) + 90.0;
              b_nrows = 180;
            } else {
              b_nrows = 0;
            }

            // Sum: '<S119>/Sum' incorporates:
            //   DataStoreRead: '<S6>/LongitudeGCS'

            rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

            // Sum: '<S115>/Sum1'
            rtb_Switch_aa = rtu_Location->Lat - rtb_Down_c;

            // Switch: '<S129>/Switch' incorporates:
            //   Abs: '<S129>/Abs'
            //   Bias: '<S129>/Bias'
            //   Bias: '<S129>/Bias1'
            //   Constant: '<S129>/Constant2'
            //   Constant: '<S133>/Constant'
            //   Math: '<S129>/Math Function1'
            //   RelationalOperator: '<S133>/Compare'

            if (std::abs(rtb_Sum) > 180.0) {
              rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S115>/Sum1'
            rtb_Sum = rtu_Location->Lon - rtb_Sum;

            // Switch: '<S125>/Switch' incorporates:
            //   Abs: '<S125>/Abs'
            //   Bias: '<S125>/Bias'
            //   Bias: '<S125>/Bias1'
            //   Constant: '<S125>/Constant2'
            //   Constant: '<S126>/Constant'
            //   Math: '<S125>/Math Function1'
            //   RelationalOperator: '<S126>/Compare'

            if (std::abs(rtb_Switch_aa) > 180.0) {
              rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S122>/Abs1'
            rtb_Down = std::abs(rtb_Switch_aa);

            // Switch: '<S122>/Switch' incorporates:
            //   Bias: '<S122>/Bias'
            //   Bias: '<S122>/Bias1'
            //   Constant: '<S118>/Constant'
            //   Constant: '<S118>/Constant1'
            //   Constant: '<S124>/Constant'
            //   Gain: '<S122>/Gain'
            //   Product: '<S122>/Divide1'
            //   RelationalOperator: '<S124>/Compare'
            //   Switch: '<S118>/Switch1'

            if (rtb_Down > 90.0) {
              // Signum: '<S122>/Sign1'
              if (rtb_Switch_aa < 0.0) {
                rtb_Switch_aa = -1.0;
              } else if (rtb_Switch_aa > 0.0) {
                rtb_Switch_aa = 1.0;
              } else if (rtb_Switch_aa == 0.0) {
                rtb_Switch_aa = 0.0;
              } else {
                rtb_Switch_aa = (rtNaN);
              }

              rtb_Gain1 = (-(rtb_Down + -90.0) + 90.0) * rtb_Switch_aa;
              b_nrows = 180;
            } else {
              rtb_Gain1 = rtb_Switch_aa;
              b_nrows = 0;
            }

            // Sum: '<S118>/Sum'
            rtb_Sum += static_cast<real_T>(b_nrows);

            // UnitConversion: '<S121>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_aa = 0.017453292519943295 * rtb_Gain1;

            // UnitConversion: '<S136>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Down_c *= 0.017453292519943295;

            // Trigonometry: '<S137>/Trigonometric Function1'
            rtb_Switch_p = std::sin(rtb_Down_c);

            // Sum: '<S137>/Sum1' incorporates:
            //   Constant: '<S137>/Constant'
            //   Product: '<S137>/Product1'

            rtb_Switch_p = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_bu *
              PreemptableMissionModeSelector_ConstB.sqrt_bu * rtb_Switch_p *
              rtb_Switch_p;

            // Product: '<S135>/Product1' incorporates:
            //   Constant: '<S135>/Constant1'
            //   Sqrt: '<S135>/sqrt'

            rtb_Gain1 = 6.378137E+6 / std::sqrt(rtb_Switch_p);

            // Product: '<S120>/dNorth' incorporates:
            //   Constant: '<S135>/Constant2'
            //   Product: '<S135>/Product3'
            //   Trigonometry: '<S135>/Trigonometric Function1'

            rtb_Switch_p = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Gain1 *
              PreemptableMissionModeSelector_ConstB.Sum1_c / rtb_Switch_p);

            // Switch: '<S123>/Switch' incorporates:
            //   Abs: '<S123>/Abs'
            //   Bias: '<S123>/Bias'
            //   Bias: '<S123>/Bias1'
            //   Constant: '<S123>/Constant2'
            //   Constant: '<S127>/Constant'
            //   Math: '<S123>/Math Function1'
            //   RelationalOperator: '<S127>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Sum) > 180.0) {
              rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
            }

            // Product: '<S120>/dEast' incorporates:
            //   Constant: '<S135>/Constant3'
            //   Product: '<S135>/Product4'
            //   Trigonometry: '<S135>/Trigonometric Function'
            //   Trigonometry: '<S135>/Trigonometric Function2'
            //   UnitConversion: '<S121>/Unit Conversion'

            rtb_Gain1 = 1.0 / rt_atan2d_snf(1.0, rtb_Gain1 * std::cos(rtb_Down_c))
              * (0.017453292519943295 * rtb_Sum);

            // Sum: '<S120>/Sum2' incorporates:
            //   Product: '<S120>/x*cos'
            //   Product: '<S120>/y*sin'

            rtb_Down = rtb_Gain1 * 0.0 + rtb_Switch_p;

            // Sum: '<S120>/Sum3' incorporates:
            //   Product: '<S120>/x*sin'
            //   Product: '<S120>/y*cos'

            rtb_Abs1_jo = rtb_Gain1 - rtb_Switch_p * 0.0;

            // Sum: '<S115>/Sum' incorporates:
            //   DataStoreRead: '<S6>/AltitudeGCS'
            //   Gain: '<S6>/inverse'

            rtb_Switch_aa = rtu_Location->Alt + -AltitudeGCS;

            // Gain: '<S6>/Up2Down'
            rtb_Switch_p = -rtu_StartPosition->Alt;

            // Sum: '<S6>/Sum' incorporates:
            //   UnaryMinus: '<S115>/Ze2height'

            rtb_Param4_e = -rtb_Switch_aa + rtb_Switch_p;

            // Gain: '<S114>/Gain1'
            rtb_Switch_e = 0.017453292519943295 * rtu_Location->degHDG;

            // Outputs for Triggered SubSystem: '<S6>/WayPointGenerator' incorporates:
            //   TriggerPort: '<S117>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &localZCE->WayPointGenerator_Trig_ZCE_a,
                               (localDW->MemoryTriggerWP_PreviousInput_d));
            if (zcEvent != NO_ZCEVENT) {
              // Product: '<S117>/ProductScanWidth' incorporates:
              //   DataTypeConversion: '<S6>/Param3'

              rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) *
                static_cast<real_T>(*rtu_MissionUAV);

              // Reshape: '<S117>/ReshapeRowVec'
              rtb_ReshapeRowVec[0] = rtb_Down;
              rtb_ReshapeRowVec[1] = rtb_Abs1_jo;
              rtb_ReshapeRowVec[2] = rtb_Param4_e;

              // SignalConversion generated from: '<S117>/RotateATMissionHdg' incorporates:
              //   Constant: '<S117>/Zero'

              rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[0] =
                rtb_Switch_e;
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[1] = 0.0;
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[2] = 0.0;
              PreemptableMissionModeSelector_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b,
                 &localB->RotateATMissionHdg_ba);

              // MATLAB Function: '<S117>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S6>/Param2'

              rtb_Switch_aa = std::ceil(static_cast<real_T>
                (rtu_Parameters->Param2) / rtb_Switch_aa);
              rtb_Sum = static_cast<real_T>(rtu_Parameters->Param2) /
                rtb_Switch_aa;
              connectionObj.FlightPathAngleLimit[0] = -0.175;
              connectionObj.FlightPathAngleLimit[1] = 0.175;
              connectionObj.MaxRollAngle = 0.29670597283903605;
              connectionObj.AirSpeed = 35.0;
              connectionObj.MinTurningRadius = 408.85657731051754;
              b_nrows = static_cast<int32_T>(rtb_Switch_aa * 2.0);
              rtb_ClockwiseRotation_n = static_cast<int32_T>(CheckPoints->size[0]
                * CheckPoints->size[1]);

              // MATLAB Function: '<S117>/WayPointGenerator'
              CheckPoints->size[0] = b_nrows;
              CheckPoints->size[1] = 4;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (CheckPoints, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S117>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S6>/Param1'

              ibmat = static_cast<int32_T>(static_cast<int32_T>(b_nrows << 2) -
                1);
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= ibmat;
                   rtb_ClockwiseRotation_n++) {
                CheckPoints->data[rtb_ClockwiseRotation_n] = 0.0;
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                   rtb_ClockwiseRotation_n = static_cast<int32_T>
                   (rtb_ClockwiseRotation_n + 1)) {
                if (rt_remd_snf(static_cast<real_T>(rtb_ClockwiseRotation_n) +
                                1.0, 2.0) == 1.0) {
                  b_nrows = static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 1) << 1);
                  rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n) +
                                 1.0) - 1.0) * rtb_Sum;
                  CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                    rtb_Switch;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + CheckPoints->size[0]) - 2)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1))
                    - 2)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) -
                    2)] = 1.5707963267948966;
                  CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                    rtb_Switch;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + CheckPoints->size[0]) - 1)] = static_cast<real_T>
                    (rtu_Parameters->Param1);
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1))
                    - 1)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) -
                    1)] = 1.5707963267948966;
                } else {
                  b_nrows = static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 1) << 1);
                  rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n) +
                                 1.0) - 1.0) * rtb_Sum;
                  CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                    rtb_Switch;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + CheckPoints->size[0]) - 2)] = static_cast<real_T>
                    (rtu_Parameters->Param1);
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1))
                    - 2)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) -
                    2)] = -1.5707963267948966;
                  CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                    rtb_Switch;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + CheckPoints->size[0]) - 1)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1))
                    - 1)] = 0.0;
                  CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                    (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) -
                    1)] = -1.5707963267948966;
                }
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);

              // MATLAB Function: '<S117>/WayPointGenerator'
              dummyWayPoint->size[0] = 1;
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S117>/WayPointGenerator'
              dummyWayPoint->data[0] = 0.0;
              dummyWayPoint->data[1] = 0.0;
              dummyWayPoint->data[2] = 0.0;
              for (nrowx = 0; nrowx <= static_cast<int32_T>(CheckPoints->size[0]
                    - 2); nrowx = static_cast<int32_T>(nrowx + 1)) {
                LUp[0] = CheckPoints->data[nrowx];
                LDp[0] = CheckPoints->data[static_cast<int32_T>(nrowx + 1)];
                LUp[1] = CheckPoints->data[static_cast<int32_T>(nrowx +
                  CheckPoints->size[0])];
                LDp[1] = CheckPoints->data[static_cast<int32_T>
                  (static_cast<int32_T>(nrowx + CheckPoints->size[0]) + 1)];
                LUp[2] = CheckPoints->data[static_cast<int32_T>(nrowx +
                  static_cast<int32_T>(CheckPoints->size[0] << 1))];
                LDp[2] = CheckPoints->data[static_cast<int32_T>
                  (static_cast<int32_T>(nrowx + static_cast<int32_T>
                    (CheckPoints->size[0] << 1)) + 1)];
                LUp[3] = CheckPoints->data[static_cast<int32_T>(nrowx +
                  static_cast<int32_T>(CheckPoints->size[0] * 3))];
                LDp[3] = CheckPoints->data[static_cast<int32_T>
                  (static_cast<int32_T>(nrowx + static_cast<int32_T>
                    (CheckPoints->size[0] * 3)) + 1)];
                PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp,
                  LDp, 100.0, segWayPoints, localB);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);
                dummyWayPoint_0->size[0] = static_cast<int32_T>
                  (dummyWayPoint->size[0] + segWayPoints->size[0]);
                dummyWayPoint_0->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (dummyWayPoint_0, rtb_ClockwiseRotation_n);
                ibmat = dummyWayPoint->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint_0->size[0] * b_nrows))] =
                      dummyWayPoint->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint->size[0] * b_nrows))];
                  }
                }

                ibmat = segWayPoints->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                      (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                        dummyWayPoint->size[0]) + static_cast<int32_T>
                       (dummyWayPoint_0->size[0] * b_nrows))] =
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] * b_nrows))];
                  }
                }

                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (dummyWayPoint->size[0] * dummyWayPoint->size[1]);
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (dummyWayPoint, rtb_ClockwiseRotation_n);
                ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                     b_nrows++) {
                  dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
                }
              }

              LUp[0] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] - 1)];
              LDp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(CheckPoints->size[0] + CheckPoints->size[0])
                 - 1)];
              LDp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(CheckPoints->size[0] + static_cast<int32_T>
                  (CheckPoints->size[0] << 1)) - 1)];
              LDp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] << 1)];
              LUp[3] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(CheckPoints->size[0] + static_cast<int32_T>
                  (CheckPoints->size[0] * 3)) - 1)];
              LDp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] * 3)];
              PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp,
                LDp, 100.0, segWayPoints, localB);
              rtb_ClockwiseRotation_n = static_cast<int32_T>
                (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

              // MATLAB Function: '<S117>/WayPointGenerator'
              dummyWayPoint_0->size[0] = static_cast<int32_T>
                (dummyWayPoint->size[0] + segWayPoints->size[0]);
              dummyWayPoint_0->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint_0, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S117>/WayPointGenerator'
              ibmat = dummyWayPoint->size[0];
              loop_ub = segWayPoints->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint_0->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint_0->size[0] * b_nrows))] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n
                     ++) {
                  dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                    static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                    segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))];
                }
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);

              // MATLAB Function: '<S117>/WayPointGenerator'
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S117>/WayPointGenerator'
              ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
              for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                   b_nrows++) {
                dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>
                (dummyWayPoint_3->size[0] * dummyWayPoint_3->size[1]);

              // MATLAB Function: '<S117>/WayPointGenerator'
              dummyWayPoint_3->size[0] = dummyWayPoint->size[0];
              dummyWayPoint_3->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint_3, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S117>/WayPointGenerator'
              loop_ub = static_cast<int32_T>(static_cast<int32_T>
                (dummyWayPoint->size[0] * dummyWayPoint->size[1]) - 1);
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   loop_ub; rtb_ClockwiseRotation_n++) {
                dummyWayPoint_3->data[rtb_ClockwiseRotation_n] =
                  dummyWayPoint->data[rtb_ClockwiseRotation_n];
              }

              PreemptableMissionModeSelector_repmat(dummyWayPoint_3, std::ceil
                (10240.0 / static_cast<real_T>(dummyWayPoint->size[0])),
                dummyWayPoint);
              nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
              nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
              for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                   (b_nrows + 1)) {
                dummyWayPoint->data[b_nrows] = dummyWayPoint->data
                  [static_cast<int32_T>(b_nrows + 1)];
              }

              for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                   (b_nrows + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                  dummyWayPoint->size[0])] = dummyWayPoint->data
                  [static_cast<int32_T>(static_cast<int32_T>(b_nrows +
                  dummyWayPoint->size[0]) + 1)];
              }

              for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                   (b_nrows + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                  static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                  dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(dummyWayPoint->size[0] << 1))
                  + 1)];
              }

              // Reshape: '<S6>/Reshape2Row' incorporates:
              //   Memory: '<S6>/MemoryPrevRelPos'

              rtb_Reshape_i[0] = localDW->MemoryPrevRelPos_PreviousInput_n[1];
              rtb_Reshape_i[1] = localDW->MemoryPrevRelPos_PreviousInput_n[0];
              rtb_Reshape_i[2] = localDW->MemoryPrevRelPos_PreviousInput_n[2];

              // Product: '<S117>/RotateRelPrevPos' incorporates:
              //   MATLABSystem: '<S117>/RotateATMissionHdg'

              rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtb_Reshape_i,
                localB->RotateATMissionHdg_ba.RotateATMissionHdg,
                rtb_startPose_h);

              // MATLAB Function: '<S117>/WayPointGenerator'
              LDp[0] = rtb_startPose_h[0];
              LDp[1] = rtb_startPose_h[1];
              LDp[2] = rtb_startPose_h[2];
              LDp[3] = 1.5707963267948966;
              LUp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] << 1)];
              LUp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size
                [0] * 3)];
              PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LDp,
                LUp, 100.0, segWayPoints, localB);
              if (1 > nrows) {
                nrowx = -1;
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size
                [0] * initWayPoint->size[1]);

              // MATLAB Function: '<S117>/WayPointGenerator'
              initWayPoint->size[0] = static_cast<int32_T>(static_cast<int32_T>
                (segWayPoints->size[0] + nrowx) + 1);
              initWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (initWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S117>/WayPointGenerator'
              ibmat = segWayPoints->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  initWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (initWayPoint->size[0] * b_nrows))] = segWayPoints->data[
                    static_cast<int32_T>(rtb_ClockwiseRotation_n + static_cast<
                    int32_T>(segWayPoints->size[0] * b_nrows))];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     nrowx; rtb_ClockwiseRotation_n++) {
                  initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + segWayPoints->size[0]) +
                    static_cast<int32_T>(initWayPoint->size[0] * b_nrows))] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                     10240; rtb_ClockwiseRotation_n++) {
                  localB->WayPoint[static_cast<int32_T>(rtb_ClockwiseRotation_n
                    + static_cast<int32_T>(10240 * b_nrows))] =
                    initWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (initWayPoint->size[0] * b_nrows))];
                }
              }

              // MATLAB Function: '<S117>/biasWayPoint'
              for (b_nrows = 0; b_nrows < 10240; b_nrows++) {
                localB->RotateIndivWayPoint[b_nrows] = localB->WayPoint[b_nrows]
                  + rtu_StartPosition->Lon;
                localB->RotateIndivWayPoint[static_cast<int32_T>(b_nrows + 10240)]
                  = localB->WayPoint[static_cast<int32_T>(b_nrows + 10240)];
                localB->RotateIndivWayPoint[static_cast<int32_T>(b_nrows + 20480)]
                  = localB->WayPoint[static_cast<int32_T>(b_nrows + 20480)];
              }

              // Product: '<S117>/RotateIndivWayPoint' incorporates:
              //   MATLABSystem: '<S117>/RotateATMissionHdg'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                     10240; rtb_ClockwiseRotation_n++) {
                  ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                    static_cast<int32_T>(10240 * b_nrows));
                  localB->WayPoint[ibmat] = 0.0;
                  localB->WayPoint[ibmat] +=
                    localB->RotateATMissionHdg_ba.RotateATMissionHdg[
                    static_cast<int32_T>(3 * b_nrows)] *
                    localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                  localB->WayPoint[ibmat] +=
                    localB->RotateATMissionHdg_ba.RotateATMissionHdg[
                    static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)]
                    * localB->RotateIndivWayPoint[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 10240)];
                  localB->WayPoint[ibmat] +=
                    localB->RotateATMissionHdg_ba.RotateATMissionHdg[
                    static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)]
                    * localB->RotateIndivWayPoint[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 20480)];
                }
              }

              // MATLAB Function: '<S117>/biasNED'
              PreemptableMissionModeSelector_biasNED_l(rtb_ReshapeRowVec,
                localB->WayPoint, localB->nedWayPoint_a, &localB->sf_biasNED_l);
            }

            // End of Outputs for SubSystem: '<S6>/WayPointGenerator'
            PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
              localB->nedWayPoint_a, 200.0, &localB->WaypointFollower_ba,
              &localDW->WaypointFollower_ba);

            // DataTypeConversion: '<S6>/Cast To Double' incorporates:
            //   Constant: '<S6>/LookAheadDis'
            //   MATLAB Function: '<S117>/WayPointGenerator'
            //   Memory: '<S6>/MemoryTriggerWP'

            *rty_thisTaskStatus = static_cast<real_T>
              (localB->WaypointFollower_ba.WaypointFollower_o5);

            // Sum: '<S116>/Sum' incorporates:
            //   DataStoreRead: '<S6>/PrevAltitudeGCS'
            //   Gain: '<S6>/PrevInverse'

            rtb_Switch = rtu_PrevLocation->Alt + -AltitudeGCS;

            // Product: '<S6>/FrontEast' incorporates:
            //   Trigonometry: '<S6>/FrontSin'

            rtb_Down_c = std::sin(rtb_Switch_e) * rtu_StartPosition->Lat;

            // Product: '<S6>/FrontNorth' incorporates:
            //   Trigonometry: '<S6>/FrontCos'

            rtb_Gain1 = std::cos(rtb_Switch_e) * rtu_StartPosition->Lat;

            // BusCreator: '<S6>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S6>/Param4'
            //   Gain: '<S6>/Down2Height'

            rty_GuidanceCmds->Height =
              -localB->WaypointFollower_ba.WaypointFollower_o1[2];
            rty_GuidanceCmds->AirSpeed = static_cast<real_T>
              (rtu_Parameters->Param4);
            rty_GuidanceCmds->HeadingAngle =
              localB->WaypointFollower_ba.WaypointFollower_o2;

            // Switch: '<S153>/Switch' incorporates:
            //   Abs: '<S153>/Abs'
            //   Bias: '<S153>/Bias'
            //   Bias: '<S153>/Bias1'
            //   Constant: '<S153>/Constant2'
            //   Constant: '<S154>/Constant'
            //   DataStoreRead: '<S6>/PrevLatitudeGCS'
            //   Math: '<S153>/Math Function1'
            //   RelationalOperator: '<S154>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              rtb_Switch_p = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch_p = LatitudeGCS;
            }

            // Abs: '<S150>/Abs1'
            rtb_Switch_aa = std::abs(rtb_Switch_p);

            // Switch: '<S150>/Switch' incorporates:
            //   Bias: '<S150>/Bias'
            //   Bias: '<S150>/Bias1'
            //   Constant: '<S141>/Constant'
            //   Constant: '<S141>/Constant1'
            //   Constant: '<S152>/Constant'
            //   Gain: '<S150>/Gain'
            //   Product: '<S150>/Divide1'
            //   RelationalOperator: '<S152>/Compare'
            //   Switch: '<S141>/Switch1'

            if (rtb_Switch_aa > 90.0) {
              // Signum: '<S150>/Sign1'
              if (rtb_Switch_p < 0.0) {
                rtb_Switch_p = -1.0;
              } else if (rtb_Switch_p > 0.0) {
                rtb_Switch_p = 1.0;
              } else if (rtb_Switch_p == 0.0) {
                rtb_Switch_p = 0.0;
              } else {
                rtb_Switch_p = (rtNaN);
              }

              rtb_Switch_p *= -(rtb_Switch_aa + -90.0) + 90.0;
              b_nrows = 180;
            } else {
              b_nrows = 0;
            }

            // Sum: '<S141>/Sum' incorporates:
            //   DataStoreRead: '<S6>/PrevLongitudeGCS'

            rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

            // Sum: '<S116>/Sum1'
            rtb_Switch_aa = rtu_PrevLocation->Lat - rtb_Switch_p;

            // Switch: '<S151>/Switch' incorporates:
            //   Abs: '<S151>/Abs'
            //   Bias: '<S151>/Bias'
            //   Bias: '<S151>/Bias1'
            //   Constant: '<S151>/Constant2'
            //   Constant: '<S155>/Constant'
            //   Math: '<S151>/Math Function1'
            //   RelationalOperator: '<S155>/Compare'

            if (std::abs(rtb_Sum) > 180.0) {
              rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S116>/Sum1'
            rtb_Sum = rtu_PrevLocation->Lon - rtb_Sum;

            // Switch: '<S147>/Switch' incorporates:
            //   Abs: '<S147>/Abs'
            //   Bias: '<S147>/Bias'
            //   Bias: '<S147>/Bias1'
            //   Constant: '<S147>/Constant2'
            //   Constant: '<S148>/Constant'
            //   Math: '<S147>/Math Function1'
            //   RelationalOperator: '<S148>/Compare'

            if (std::abs(rtb_Switch_aa) > 180.0) {
              rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S144>/Abs1'
            rtb_SumInitEast_j = std::abs(rtb_Switch_aa);

            // Switch: '<S144>/Switch' incorporates:
            //   Bias: '<S144>/Bias'
            //   Bias: '<S144>/Bias1'
            //   Constant: '<S140>/Constant'
            //   Constant: '<S140>/Constant1'
            //   Constant: '<S146>/Constant'
            //   Gain: '<S144>/Gain'
            //   Product: '<S144>/Divide1'
            //   RelationalOperator: '<S146>/Compare'
            //   Switch: '<S140>/Switch1'

            if (rtb_SumInitEast_j > 90.0) {
              // Signum: '<S144>/Sign1'
              if (rtb_Switch_aa < 0.0) {
                rtb_Switch_aa = -1.0;
              } else if (rtb_Switch_aa > 0.0) {
                rtb_Switch_aa = 1.0;
              } else if (rtb_Switch_aa == 0.0) {
                rtb_Switch_aa = 0.0;
              } else {
                rtb_Switch_aa = (rtNaN);
              }

              rtb_Switch_aa *= -(rtb_SumInitEast_j + -90.0) + 90.0;
              b_nrows = 180;
            } else {
              b_nrows = 0;
            }

            // Sum: '<S140>/Sum'
            rtb_Sum_as = static_cast<real_T>(b_nrows) + rtb_Sum;

            // UnitConversion: '<S158>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_p *= 0.017453292519943295;

            // Trigonometry: '<S159>/Trigonometric Function1'
            rtb_Sum = std::sin(rtb_Switch_p);

            // Sum: '<S159>/Sum1' incorporates:
            //   Constant: '<S159>/Constant'
            //   Product: '<S159>/Product1'

            rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_a *
              PreemptableMissionModeSelector_ConstB.sqrt_a * rtb_Sum * rtb_Sum;

            // Product: '<S157>/Product1' incorporates:
            //   Constant: '<S157>/Constant1'
            //   Sqrt: '<S157>/sqrt'

            rtb_SumInitEast_j = 6.378137E+6 / std::sqrt(rtb_Sum);

            // Product: '<S157>/Product4' incorporates:
            //   Trigonometry: '<S157>/Trigonometric Function'

            rtb_Switch_p = rtb_SumInitEast_j * std::cos(rtb_Switch_p);

            // Product: '<S142>/dNorth' incorporates:
            //   Constant: '<S157>/Constant2'
            //   Product: '<S157>/Product3'
            //   Trigonometry: '<S157>/Trigonometric Function1'
            //   UnitConversion: '<S143>/Unit Conversion'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_SumInitEast_j = 0.017453292519943295 * rtb_Switch_aa /
              rt_atan2d_snf(1.0, rtb_SumInitEast_j *
                            PreemptableMissionModeSelector_ConstB.Sum1_l /
                            rtb_Sum);

            // Switch: '<S145>/Switch' incorporates:
            //   Abs: '<S145>/Abs'
            //   Bias: '<S145>/Bias'
            //   Bias: '<S145>/Bias1'
            //   Constant: '<S145>/Constant2'
            //   Constant: '<S149>/Constant'
            //   Math: '<S145>/Math Function1'
            //   RelationalOperator: '<S149>/Compare'

            if (std::abs(rtb_Sum_as) > 180.0) {
              rtb_Sum_as = rt_modd_snf(rtb_Sum_as + 180.0, 360.0) + -180.0;
            }

            // Product: '<S142>/dEast' incorporates:
            //   Constant: '<S157>/Constant3'
            //   Trigonometry: '<S157>/Trigonometric Function2'
            //   UnitConversion: '<S143>/Unit Conversion'

            rtb_Sum = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_p) *
              (0.017453292519943295 * rtb_Sum_as);

            // Sum: '<S142>/Sum2' incorporates:
            //   Product: '<S142>/x*cos'
            //   Product: '<S142>/y*sin'

            rtb_Switch_aa = rtb_Sum * 0.0 + rtb_SumInitEast_j;

            // Sum: '<S142>/Sum3' incorporates:
            //   Product: '<S142>/x*sin'
            //   Product: '<S142>/y*cos'

            rtb_SumInitEast_j = rtb_Sum - rtb_SumInitEast_j * 0.0;

            // Product: '<S6>/RightNorth' incorporates:
            //   Bias: '<S6>/Rotate90deg'
            //   Trigonometry: '<S6>/RightCos'

            rtb_Sum_as = std::cos(rtb_Switch_e + 1.5707963267948966) *
              rtu_StartPosition->Lon;

            // Product: '<S6>/RightEast' incorporates:
            //   Bias: '<S6>/Rotate90deg'
            //   Trigonometry: '<S6>/RightSin'

            rtb_Sum = std::sin(rtb_Switch_e + 1.5707963267948966) *
              rtu_StartPosition->Lon;

            // Sum: '<S6>/SumHeight' incorporates:
            //   UnaryMinus: '<S116>/Ze2height'

            rtb_Switch_p = rtu_StartPosition->Alt + rtb_Switch;

            // Reshape: '<S6>/Reshape' incorporates:
            //   Constant: '<S6>/InitialFlightPathAngle'
            //   Constant: '<S6>/InitialRollAngle'
            //   Constant: '<S6>/InitialRollAngleRate'
            //   DataTypeConversion: '<S6>/Param4'
            //   Sum: '<S6>/SumInitEast'
            //   Sum: '<S6>/SumInitNorth'

            rty_InitialState[0] = (rtb_Switch_aa + rtb_Sum_as) + rtb_Gain1;
            rty_InitialState[1] = (rtb_SumInitEast_j + rtb_Down_c) + rtb_Sum;
            rty_InitialState[2] = rtb_Switch_p;
            rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
            rty_InitialState[4] = rtb_Switch_e;
            rty_InitialState[5] = 0.0;
            rty_InitialState[6] = 0.0;
            rty_InitialState[7] = 0.0;

            // Update for Memory: '<S6>/MemoryPrevRelPos' incorporates:
            //   Sum: '<S6>/RelPrevPos'
            //   UnaryMinus: '<S116>/Ze2height'

            localDW->MemoryPrevRelPos_PreviousInput_n[0] = rtb_Switch_aa -
              rtb_Down;
            localDW->MemoryPrevRelPos_PreviousInput_n[1] = rtb_SumInitEast_j -
              rtb_Abs1_jo;
            localDW->MemoryPrevRelPos_PreviousInput_n[2] = -rtb_Switch -
              rtb_Param4_e;

            // Update for Memory: '<S6>/MemoryTriggerWP' incorporates:
            //   Constant: '<S6>/TirggerWayPointGen'

            localDW->MemoryTriggerWP_PreviousInput_d = 1.0;
          }
        } else {
          sf_internal_predicateOutput = ((*rtu_mode == 3) || (*rtu_mode == 33));
          if (sf_internal_predicateOutput) {
            PreemptableMissionModeSelector_exit_internal_GuidanceLogic(localDW);
            localDW->is_GuidanceLogic =
              PreemptableMissionModeSelector_IN_RunWayNav;

            // Switch: '<S100>/Switch' incorporates:
            //   Abs: '<S100>/Abs'
            //   Bias: '<S100>/Bias'
            //   Bias: '<S100>/Bias1'
            //   Constant: '<S100>/Constant2'
            //   Constant: '<S101>/Constant'
            //   DataStoreRead: '<S5>/LatitudeGCS'
            //   Math: '<S100>/Math Function1'
            //   RelationalOperator: '<S101>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Down = LatitudeGCS;
            }

            // Abs: '<S97>/Abs1'
            rtb_Switch_aa = std::abs(rtb_Down);

            // Switch: '<S97>/Switch' incorporates:
            //   Bias: '<S97>/Bias'
            //   Bias: '<S97>/Bias1'
            //   Constant: '<S88>/Constant'
            //   Constant: '<S88>/Constant1'
            //   Constant: '<S99>/Constant'
            //   Gain: '<S97>/Gain'
            //   Product: '<S97>/Divide1'
            //   RelationalOperator: '<S99>/Compare'
            //   Switch: '<S88>/Switch1'

            if (rtb_Switch_aa > 90.0) {
              // Signum: '<S97>/Sign1'
              if (rtb_Down < 0.0) {
                rtb_Down = -1.0;
              } else if (rtb_Down > 0.0) {
                rtb_Down = 1.0;
              } else if (rtb_Down == 0.0) {
                rtb_Down = 0.0;
              } else {
                rtb_Down = (rtNaN);
              }

              rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
              b_nrows = 180;
            } else {
              b_nrows = 0;
            }

            // Sum: '<S88>/Sum' incorporates:
            //   DataStoreRead: '<S5>/LongitudeGCS'

            rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

            // Sum: '<S85>/Sum1'
            rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

            // Switch: '<S98>/Switch' incorporates:
            //   Abs: '<S98>/Abs'
            //   Bias: '<S98>/Bias'
            //   Bias: '<S98>/Bias1'
            //   Constant: '<S102>/Constant'
            //   Constant: '<S98>/Constant2'
            //   Math: '<S98>/Math Function1'
            //   RelationalOperator: '<S102>/Compare'

            if (std::abs(rtb_Sum) > 180.0) {
              rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S85>/Sum1'
            rtb_Sum = rtu_Location->Lon - rtb_Sum;

            // Switch: '<S94>/Switch' incorporates:
            //   Abs: '<S94>/Abs'
            //   Bias: '<S94>/Bias'
            //   Bias: '<S94>/Bias1'
            //   Constant: '<S94>/Constant2'
            //   Constant: '<S95>/Constant'
            //   Math: '<S94>/Math Function1'
            //   RelationalOperator: '<S95>/Compare'

            if (std::abs(rtb_Switch_aa) > 180.0) {
              rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S91>/Abs1'
            rtb_Down_c = std::abs(rtb_Switch_aa);

            // Switch: '<S91>/Switch' incorporates:
            //   Bias: '<S91>/Bias'
            //   Bias: '<S91>/Bias1'
            //   Constant: '<S87>/Constant'
            //   Constant: '<S87>/Constant1'
            //   Constant: '<S93>/Constant'
            //   Gain: '<S91>/Gain'
            //   Product: '<S91>/Divide1'
            //   RelationalOperator: '<S93>/Compare'
            //   Switch: '<S87>/Switch1'

            if (rtb_Down_c > 90.0) {
              // Signum: '<S91>/Sign1'
              if (rtb_Switch_aa < 0.0) {
                rtb_Switch_aa = -1.0;
              } else if (rtb_Switch_aa > 0.0) {
                rtb_Switch_aa = 1.0;
              } else if (rtb_Switch_aa == 0.0) {
                rtb_Switch_aa = 0.0;
              } else {
                rtb_Switch_aa = (rtNaN);
              }

              rtb_Down_c = (-(rtb_Down_c + -90.0) + 90.0) * rtb_Switch_aa;
              b_nrows = 180;
            } else {
              rtb_Down_c = rtb_Switch_aa;
              b_nrows = 0;
            }

            // Sum: '<S87>/Sum'
            rtb_Sum += static_cast<real_T>(b_nrows);

            // UnitConversion: '<S90>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_aa = 0.017453292519943295 * rtb_Down_c;

            // UnitConversion: '<S105>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Down *= 0.017453292519943295;

            // Trigonometry: '<S106>/Trigonometric Function1'
            rtb_Abs1_jo = std::sin(rtb_Down);

            // Sum: '<S106>/Sum1' incorporates:
            //   Constant: '<S106>/Constant'
            //   Product: '<S106>/Product1'

            rtb_Abs1_jo = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_j *
              PreemptableMissionModeSelector_ConstB.sqrt_j * rtb_Abs1_jo *
              rtb_Abs1_jo;

            // Product: '<S104>/Product1' incorporates:
            //   Constant: '<S104>/Constant1'
            //   Sqrt: '<S104>/sqrt'

            rtb_Down_c = 6.378137E+6 / std::sqrt(rtb_Abs1_jo);

            // Product: '<S89>/dNorth' incorporates:
            //   Constant: '<S104>/Constant2'
            //   Product: '<S104>/Product3'
            //   Trigonometry: '<S104>/Trigonometric Function1'

            rtb_Abs1_jo = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Down_c *
              PreemptableMissionModeSelector_ConstB.Sum1_f / rtb_Abs1_jo);

            // Switch: '<S92>/Switch' incorporates:
            //   Abs: '<S92>/Abs'
            //   Bias: '<S92>/Bias'
            //   Bias: '<S92>/Bias1'
            //   Constant: '<S92>/Constant2'
            //   Constant: '<S96>/Constant'
            //   Math: '<S92>/Math Function1'
            //   RelationalOperator: '<S96>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Sum) > 180.0) {
              rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
            }

            // Product: '<S89>/dEast' incorporates:
            //   Constant: '<S104>/Constant3'
            //   Product: '<S104>/Product4'
            //   Trigonometry: '<S104>/Trigonometric Function'
            //   Trigonometry: '<S104>/Trigonometric Function2'
            //   UnitConversion: '<S90>/Unit Conversion'

            rtb_Down_c = 1.0 / rt_atan2d_snf(1.0, rtb_Down_c * std::cos(rtb_Down))
              * (0.017453292519943295 * rtb_Sum);

            // Sum: '<S85>/Sum' incorporates:
            //   DataStoreRead: '<S5>/AltitudeGCS'
            //   Gain: '<S5>/inverse'

            rtb_Switch_e = rtu_Location->Alt + -AltitudeGCS;

            // Gain: '<S84>/Gain1'
            rtb_Gain1 = 0.017453292519943295 * rtu_Location->degHDG;

            // Outputs for Triggered SubSystem: '<S5>/WayPointGenerator' incorporates:
            //   TriggerPort: '<S86>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &localZCE->WayPointGenerator_Trig_ZCE_e,
                               (localDW->MemoryTriggerWP_PreviousInput_b));
            if (zcEvent != NO_ZCEVENT) {
              // Product: '<S86>/IndivRunwayRotAng' incorporates:
              //   DataTypeConversion: '<S5>/Param2'
              //   DataTypeConversion: '<S5>/Param5'
              //   Gain: '<S109>/Gain1'

              rtb_Switch = 0.017453292519943295 * static_cast<real_T>
                (rtu_Parameters->Param2) * static_cast<real_T>
                (rtu_Parameters->Param5);

              // DataTypeConversion: '<S86>/Cast To Double'
              rtb_Param4_e = static_cast<real_T>(*rtu_FormationIDX);

              // MATLAB Function: '<S86>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S5>/Param3'

              PreemptableMissionModeSelector_uavDubinsConnection_uavDubinsConnection
                (&connectionObj);
              LUp[0] = 0.0;
              rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
              LUp[1] = rtb_Switch_aa;
              LUp[2] = 0.0;
              LUp[3] = 1.5707963267948966;
              LDp[0] = 0.0;
              rtb_Sum = -static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
              LDp[1] = rtb_Sum;
              LDp[2] = 0.0;
              LDp[3] = 1.5707963267948966;
              PreemptableMissionModeSelector_uavDubinsConnection_connect
                (&connectionObj, LUp, LDp, localB->pathSegObj.data,
                 &localB->pathSegObj.size, a__1_data, &b_nrows, localB);
              PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate
                (localB->pathSegObj.data[0].StartPose, localB->pathSegObj.data[0]
                 .GoalPose, localB->pathSegObj.data[0].FlightPathAngle,
                 localB->pathSegObj.data[0].AirSpeed, localB->pathSegObj.data[0]
                 .MinTurningRadius, localB->pathSegObj.data[0].HelixRadius,
                 localB->pathSegObj.data[0].MotionTypes, localB->
                 pathSegObj.data[0].MotionLengths, localB->pathSegObj.data[0].
                 Length, localB->pathSegObj.data[0].Length / 2.0, midpose_data,
                 midpose_size);
              rtb_startPose_f[0] = 0.0;
              rtb_Down = (localB->pathSegObj.data[0].Length + static_cast<real_T>
                          (rtu_Parameters->Param3)) / 3.0 -
                localB->pathSegObj.data[0].Length / 2.0;
              rtb_startPose_f[1] = rtb_Switch_aa - rtb_Down;
              rtb_startPose_f[2] = 0.0;
              rtb_startPose_f[3] = 1.5707963267948966;
              ende[0] = 0.0;
              ende[1] = rtb_Down + rtb_Sum;
              ende[2] = 0.0;
              ende[3] = 1.5707963267948966;
              rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size
                [0] * initWayPoint->size[1]);

              // MATLAB Function: '<S86>/WayPointGenerator'
              initWayPoint->size[0] = 1;
              initWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (initWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S86>/WayPointGenerator' incorporates:
              //   Constant: '<S86>/Three'
              //   Math: '<S86>/ModRunWayPose'

              initWayPoint->data[0] = 0.0;
              initWayPoint->data[1] = 0.0;
              initWayPoint->data[2] = 0.0;
              switch (static_cast<int32_T>(rt_modd_snf(rtb_Param4_e, 3.0))) {
               case 0:
                PreemptableMissionModeSelector_genSegWP(&connectionObj,
                  rtb_startPose_f, LUp, 100.0, segWayPoints, localB);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (initWayPoint->size[0] * initWayPoint->size[1]);
                initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size
                  [0] + 1);
                initWayPoint->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (initWayPoint, rtb_ClockwiseRotation_n);
                ibmat = segWayPoints->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                    b_nrows)] = 0.0;
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (initWayPoint->size[0] * b_nrows)) + 1)] =
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] * b_nrows))];
                  }
                }
                break;

               case 1:
                rtb_startPose_f[0] = midpose_data[0];
                rtb_startPose_f[1] = midpose_data[midpose_size[0]];
                rtb_startPose_f[2] = midpose_data[static_cast<int32_T>
                  (midpose_size[0] << 1)];
                rtb_startPose_f[3] = midpose_data[static_cast<int32_T>
                  (midpose_size[0] * 3)];
                PreemptableMissionModeSelector_genSegWP(&connectionObj,
                  &midpose_data[0], LDp, 100.0, segWayPoints, localB);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (initWayPoint->size[0] * initWayPoint->size[1]);
                initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size
                  [0] + 1);
                initWayPoint->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (initWayPoint, rtb_ClockwiseRotation_n);
                ibmat = segWayPoints->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                    b_nrows)] = 0.0;
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (initWayPoint->size[0] * b_nrows)) + 1)] =
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] * b_nrows))];
                  }
                }
                break;

               case 2:
                rtb_startPose_f[0] = 0.0;
                rtb_startPose_f[1] = ende[1];
                rtb_startPose_f[2] = 0.0;
                rtb_startPose_f[3] = 1.5707963267948966;
                PreemptableMissionModeSelector_genSegWP(&connectionObj, ende,
                  LUp, 100.0, segWayPoints, localB);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (initWayPoint->size[0] * initWayPoint->size[1]);
                initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size
                  [0] + 1);
                initWayPoint->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (initWayPoint, rtb_ClockwiseRotation_n);
                ibmat = segWayPoints->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                    b_nrows)] = 0.0;
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (initWayPoint->size[0] * b_nrows)) + 1)] =
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] * b_nrows))];
                  }
                }
                break;

               default:
                rtb_startPose_f[0] = 0.0;
                rtb_startPose_f[1] = 0.0;
                rtb_startPose_f[2] = 0.0;
                rtb_startPose_f[3] = 0.0;
                break;
              }

              PreemptableMissionModeSelector_genSegWP(&connectionObj, LUp, LDp,
                100.0, segWayPoints, localB);
              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);

              // MATLAB Function: '<S86>/WayPointGenerator'
              dummyWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0]
                + 1);
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S86>/WayPointGenerator'
              ibmat = segWayPoints->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                dummyWayPoint->data[static_cast<int32_T>(dummyWayPoint->size[0] *
                  b_nrows)] = 0.0;
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows)) + 1)] =
                    segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))];
                }
              }

              PreemptableMissionModeSelector_genSegWP(&connectionObj, LDp, LUp,
                100.0, segWayPoints, localB);
              rtb_ClockwiseRotation_n = static_cast<int32_T>
                (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

              // MATLAB Function: '<S86>/WayPointGenerator'
              dummyWayPoint_0->size[0] = static_cast<int32_T>
                (dummyWayPoint->size[0] + segWayPoints->size[0]);
              dummyWayPoint_0->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint_0, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S86>/WayPointGenerator'
              ibmat = dummyWayPoint->size[0];
              loop_ub = segWayPoints->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint_0->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint_0->size[0] * b_nrows))] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n
                     ++) {
                  dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                    static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                    segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))];
                }
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);

              // MATLAB Function: '<S86>/WayPointGenerator'
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S86>/WayPointGenerator'
              ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
              for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                   b_nrows++) {
                dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
              }

              nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
              nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
                   rtb_ClockwiseRotation_n = static_cast<int32_T>
                   (rtb_ClockwiseRotation_n + 1)) {
                dummyWayPoint->data[rtb_ClockwiseRotation_n] =
                  dummyWayPoint->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 1)];
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
                   rtb_ClockwiseRotation_n = static_cast<int32_T>
                   (rtb_ClockwiseRotation_n + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                  + dummyWayPoint->size[0])] = dummyWayPoint->data
                  [static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) + 1)];
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
                   rtb_ClockwiseRotation_n = static_cast<int32_T>
                   (rtb_ClockwiseRotation_n + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                  + static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                  dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (dummyWayPoint->size[0] << 1)) + 1)];
              }

              if (1 > nrows) {
                nrowx = -1;
                b_nrows = -1;
              } else {
                b_nrows = nrowx;
              }

              ibmat = static_cast<int32_T>(b_nrows + 1);
              rtb_ClockwiseRotation_n = static_cast<int32_T>
                (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

              // MATLAB Function: '<S86>/WayPointGenerator'
              dummyWayPoint_0->size[0] = static_cast<int32_T>(nrowx + 1);
              dummyWayPoint_0->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint_0, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S86>/WayPointGenerator'
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint_0->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint_0->size[0] * b_nrows))] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }
              }

              PreemptableMissionModeSelector_repmat(dummyWayPoint_0, std::ceil
                (10240.0 / static_cast<real_T>(static_cast<int32_T>(nrowx + 1))),
                dummyWayPoint);
              if (2 > initWayPoint->size[0]) {
                nrowx = -1;
                nrows = -1;
              } else {
                nrowx = 0;
                nrows = static_cast<int32_T>(initWayPoint->size[0] - 1);
              }

              ibmat = static_cast<int32_T>(nrows - nrowx);
              rtb_ClockwiseRotation_n = static_cast<int32_T>(segWayPoints->size
                [0] * segWayPoints->size[1]);

              // MATLAB Function: '<S86>/WayPointGenerator'
              segWayPoints->size[0] = static_cast<int32_T>(ibmat +
                dummyWayPoint->size[0]);
              segWayPoints->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (segWayPoints, rtb_ClockwiseRotation_n);

              // MATLAB Function: '<S86>/WayPointGenerator'
              loop_ub = dummyWayPoint->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))] = initWayPoint->data[
                    static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(nrowx + rtb_ClockwiseRotation_n) +
                     static_cast<int32_T>(initWayPoint->size[0] * b_nrows)) + 1)];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n
                     ++) {
                  segWayPoints->data[static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(rtb_ClockwiseRotation_n + nrows) -
                    nrowx) + static_cast<int32_T>(segWayPoints->size[0] *
                    b_nrows))] = dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                     10240; rtb_ClockwiseRotation_n++) {
                  localB->WayPoint[static_cast<int32_T>(rtb_ClockwiseRotation_n
                    + static_cast<int32_T>(10240 * b_nrows))] =
                    segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))];
                }
              }

              // Bias: '<S86>/Bias' incorporates:
              //   Sum: '<S86>/Sum'

              localB->Bias = ((rtb_Gain1 + rtb_Switch) + rtb_startPose_f[3]) +
                -1.5707963267948966;

              // Gain: '<S86>/InterLayerDis' incorporates:
              //   Constant: '<S86>/Three'
              //   DataTypeConversion: '<S5>/Param5'
              //   Math: '<S86>/ModRunWayLayer'

              rtb_Param4_e = 15.0 * rt_modd_snf(static_cast<real_T>
                (rtu_Parameters->Param5), 3.0);

              // Reshape: '<S86>/Reshape' incorporates:
              //   Constant: '<S86>/Zero'
              //   DataTypeConversion: '<S5>/Param1'

              rtb_Reshape_i[0] = 0.0;
              rtb_Reshape_i[1] = static_cast<real_T>(rtu_Parameters->Param1);
              rtb_Reshape_i[2] = rtb_Param4_e;

              // Reshape: '<S86>/ReshapeRowVec' incorporates:
              //   Product: '<S89>/x*cos'
              //   Product: '<S89>/x*sin'
              //   Product: '<S89>/y*cos'
              //   Product: '<S89>/y*sin'
              //   Reshape: '<S86>/ReshapeRowVecStartpose'
              //   Sum: '<S89>/Sum2'
              //   Sum: '<S89>/Sum3'
              //   UnaryMinus: '<S85>/Ze2height'

              rtb_ReshapeRowVec[0] = rtb_Down_c * 0.0 + rtb_Abs1_jo;
              rtb_ReshapeRowVec[1] = rtb_Down_c - rtb_Abs1_jo * 0.0;
              rtb_ReshapeRowVec[2] = -rtb_Switch_e;

              // SignalConversion generated from: '<S86>/RotateATMissionHdg' incorporates:
              //   Constant: '<S86>/Zero'

              rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[0] =
                rtb_Gain1;
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[1] = 0.0;
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[2] = 0.0;
              PreemptableMissionModeSelector_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx,
                 &localB->RotateATMissionHdg_b);

              // SignalConversion generated from: '<S86>/RotateATRunWayHdg' incorporates:
              //   Constant: '<S86>/Zero'

              rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[0] = rtb_Switch;
              rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[1] = 0.0;
              rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[2] = 0.0;
              PreemptableMissionModeSelector_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATRunWayHdgInport1,
                 &localB->RotateATRunWayHdg_b);

              // MATLAB Function: '<S86>/minus'
              PreemptableMissionModeSelector_minus(localB->WayPoint,
                rtb_Reshape_i, localB->RotateIndivWayPoint);

              // Product: '<S86>/RotateRunway' incorporates:
              //   MATLABSystem: '<S86>/RotateATRunWayHdg'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                     10240; rtb_ClockwiseRotation_n++) {
                  ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                    static_cast<int32_T>(10240 * b_nrows));
                  localB->rtb_WayPoint_m[ibmat] = 0.0;
                  localB->rtb_WayPoint_m[ibmat] +=
                    localB->RotateATRunWayHdg_b.RotateATMissionHdg
                    [static_cast<int32_T>(3 * b_nrows)] *
                    localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                  localB->rtb_WayPoint_m[ibmat] +=
                    localB->RotateATRunWayHdg_b.RotateATMissionHdg
                    [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)]
                    * localB->RotateIndivWayPoint[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 10240)];
                  localB->rtb_WayPoint_m[ibmat] +=
                    localB->RotateATRunWayHdg_b.RotateATMissionHdg
                    [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)]
                    * localB->RotateIndivWayPoint[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 20480)];
                }
              }

              // Product: '<S86>/RotateIndivWayPoint' incorporates:
              //   MATLABSystem: '<S86>/RotateATMissionHdg'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                     10240; rtb_ClockwiseRotation_n++) {
                  ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                    static_cast<int32_T>(10240 * b_nrows));
                  localB->WayPoint[ibmat] = 0.0;
                  localB->WayPoint[ibmat] +=
                    localB->RotateATMissionHdg_b.RotateATMissionHdg[static_cast<
                    int32_T>(3 * b_nrows)] * localB->
                    rtb_WayPoint_m[rtb_ClockwiseRotation_n];
                  localB->WayPoint[ibmat] +=
                    localB->RotateATMissionHdg_b.RotateATMissionHdg[static_cast<
                    int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)] *
                    localB->rtb_WayPoint_m[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 10240)];
                  localB->WayPoint[ibmat] +=
                    localB->RotateATMissionHdg_b.RotateATMissionHdg[static_cast<
                    int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
                    localB->rtb_WayPoint_m[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 20480)];
                }
              }

              // Sum: '<S86>/BiasStartPose' incorporates:
              //   DataTypeConversion: '<S5>/Param1'

              rtb_Switch_aa = rtb_startPose_f[0];
              rtb_Sum = rtb_startPose_f[1] - static_cast<real_T>
                (rtu_Parameters->Param1);
              rtb_Down_c = rtb_startPose_f[2] - rtb_Param4_e;

              // Product: '<S86>/RotateRunwayStartpose' incorporates:
              //   MATLABSystem: '<S86>/RotateATRunWayHdg'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                rtb_startPose_h[b_nrows] =
                  localB->RotateATRunWayHdg_b.RotateATMissionHdg
                  [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
                  rtb_Down_c + (localB->RotateATRunWayHdg_b.RotateATMissionHdg[
                                static_cast<int32_T>(static_cast<int32_T>(3 *
                  b_nrows) + 1)] * rtb_Sum +
                                localB->RotateATRunWayHdg_b.RotateATMissionHdg[
                                static_cast<int32_T>(3 * b_nrows)] *
                                rtb_Switch_aa);
              }

              // Product: '<S86>/RotateIndivWayPointStartpose' incorporates:
              //   MATLABSystem: '<S86>/RotateATMissionHdg'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                rtb_Reshape_i[b_nrows] =
                  localB->RotateATMissionHdg_b.RotateATMissionHdg
                  [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
                  rtb_startPose_h[2] +
                  (localB->RotateATMissionHdg_b.RotateATMissionHdg
                   [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)]
                   * rtb_startPose_h[1] +
                   localB->RotateATMissionHdg_b.RotateATMissionHdg
                   [static_cast<int32_T>(3 * b_nrows)] * rtb_startPose_h[0]);
              }

              // MATLAB Function: '<S86>/biasNED' incorporates:
              //   Reshape: '<S86>/ReshapeRowVec'

              PreemptableMissionModeSelector_biasNED(rtb_ReshapeRowVec,
                localB->WayPoint, localB->nedWayPoint_k, &localB->sf_biasNED_f);

              // MATLAB Function: '<S86>/biasNEDstartpose'
              PreemptableMissionModeSelector_biasNEDstartpose(rtb_ReshapeRowVec,
                rtb_Reshape_i, localB->nedWayPoint_f);
            }

            // End of Outputs for SubSystem: '<S5>/WayPointGenerator'
            PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
              localB->nedWayPoint_k, 200.0, &localB->WaypointFollower_b,
              &localDW->WaypointFollower_b);

            // DataTypeConversion: '<S5>/Cast To Double' incorporates:
            //   Constant: '<S5>/LookAheadDis'
            //   MATLAB Function: '<S86>/WayPointGenerator'
            //   Memory: '<S5>/MemoryTriggerWP'

            *rty_thisTaskStatus = static_cast<real_T>
              (localB->WaypointFollower_b.WaypointFollower_o5);

            // BusCreator: '<S5>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S5>/Param4'
            //   Gain: '<S5>/Down2Height'

            rty_GuidanceCmds->Height =
              -localB->WaypointFollower_b.WaypointFollower_o1[2];
            rty_GuidanceCmds->AirSpeed = static_cast<real_T>
              (rtu_Parameters->Param4);
            rty_GuidanceCmds->HeadingAngle =
              localB->WaypointFollower_b.WaypointFollower_o2;

            // Reshape: '<S5>/Reshape' incorporates:
            //   Constant: '<S5>/InitialFlightPathAngle'
            //   Constant: '<S5>/InitialRollAngle'
            //   Constant: '<S5>/InitialRollAngleRate'
            //   DataTypeConversion: '<S5>/Param4'
            //   Gain: '<S5>/Down2Up'

            rty_InitialState[0] = localB->nedWayPoint_f[0];
            rty_InitialState[1] = localB->nedWayPoint_f[1];
            rty_InitialState[2] = -localB->nedWayPoint_f[2];
            rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
            rty_InitialState[4] = localB->Bias;
            rty_InitialState[5] = 0.0;
            rty_InitialState[6] = 0.0;
            rty_InitialState[7] = 0.0;

            // Sum: '<S5>/Sum' incorporates:
            //   Memory: '<S5>/MemoryStopTrigger1'
            //   Memory: '<S5>/MemoryTriggerWP'

            *rty_ResetTrigger = localDW->MemoryStopTrigger1_PreviousInput +
              localDW->MemoryTriggerWP_PreviousInput_b;

            // Update for Memory: '<S5>/MemoryTriggerWP' incorporates:
            //   Constant: '<S5>/TirggerWayPointGen'

            localDW->MemoryTriggerWP_PreviousInput_b = 1.0;

            // Update for Memory: '<S5>/MemoryStopTrigger1' incorporates:
            //   Memory: '<S5>/MemoryStopTrigger2'

            localDW->MemoryStopTrigger1_PreviousInput =
              localDW->MemoryStopTrigger2_PreviousInput;

            // Update for Memory: '<S5>/MemoryStopTrigger2' incorporates:
            //   Constant: '<S5>/StopTrigger'

            localDW->MemoryStopTrigger2_PreviousInput = -1.0;
          } else {
            sf_internal_predicateOutput = ((*rtu_mode == 4) || (*rtu_mode == 44));
            if (sf_internal_predicateOutput) {
              PreemptableMissionModeSelector_exit_internal_GuidanceLogic(localDW);
              localDW->is_GuidanceLogic =
                PreemptableMissionModeSelector_IN_ProtectionLine;

              // Abs: '<S4>/Abs' incorporates:
              //   DataTypeConversion: '<S4>/Param4'
              //   DataTypeConversion: '<S4>/Param5'
              //   Gain: '<S4>/HalfDiff'
              //   Sum: '<S4>/Minus'

              rtb_Down_c = std::abs((static_cast<real_T>(rtu_Parameters->Param4)
                - static_cast<real_T>(rtu_Parameters->Param5)) * 0.5);

              // Switch: '<S70>/Switch' incorporates:
              //   Abs: '<S70>/Abs'
              //   Bias: '<S70>/Bias'
              //   Bias: '<S70>/Bias1'
              //   Constant: '<S70>/Constant2'
              //   Constant: '<S71>/Constant'
              //   DataStoreRead: '<S4>/LatitudeGCS'
              //   Math: '<S70>/Math Function1'
              //   RelationalOperator: '<S71>/Compare'

              if (std::abs(LatitudeGCS) > 180.0) {
                rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
              } else {
                rtb_Down = LatitudeGCS;
              }

              // Abs: '<S67>/Abs1'
              rtb_Switch_aa = std::abs(rtb_Down);

              // Switch: '<S67>/Switch' incorporates:
              //   Bias: '<S67>/Bias'
              //   Bias: '<S67>/Bias1'
              //   Constant: '<S58>/Constant'
              //   Constant: '<S58>/Constant1'
              //   Constant: '<S69>/Constant'
              //   Gain: '<S67>/Gain'
              //   Product: '<S67>/Divide1'
              //   RelationalOperator: '<S69>/Compare'
              //   Switch: '<S58>/Switch1'

              if (rtb_Switch_aa > 90.0) {
                // Signum: '<S67>/Sign1'
                if (rtb_Down < 0.0) {
                  rtb_Down = -1.0;
                } else if (rtb_Down > 0.0) {
                  rtb_Down = 1.0;
                } else if (rtb_Down == 0.0) {
                  rtb_Down = 0.0;
                } else {
                  rtb_Down = (rtNaN);
                }

                rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
                b_nrows = 180;
              } else {
                b_nrows = 0;
              }

              // Sum: '<S58>/Sum' incorporates:
              //   DataStoreRead: '<S4>/LongitudeGCS'

              rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

              // Sum: '<S55>/Sum1'
              rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

              // Switch: '<S68>/Switch' incorporates:
              //   Abs: '<S68>/Abs'
              //   Bias: '<S68>/Bias'
              //   Bias: '<S68>/Bias1'
              //   Constant: '<S68>/Constant2'
              //   Constant: '<S72>/Constant'
              //   Math: '<S68>/Math Function1'
              //   RelationalOperator: '<S72>/Compare'

              if (std::abs(rtb_Sum) > 180.0) {
                rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
              }

              // Sum: '<S55>/Sum1'
              rtb_Sum = rtu_Location->Lon - rtb_Sum;

              // Switch: '<S64>/Switch' incorporates:
              //   Abs: '<S64>/Abs'
              //   Bias: '<S64>/Bias'
              //   Bias: '<S64>/Bias1'
              //   Constant: '<S64>/Constant2'
              //   Constant: '<S65>/Constant'
              //   Math: '<S64>/Math Function1'
              //   RelationalOperator: '<S65>/Compare'

              if (std::abs(rtb_Switch_aa) > 180.0) {
                rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                  -180.0;
              }

              // Abs: '<S61>/Abs1'
              rtb_Abs1_jo = std::abs(rtb_Switch_aa);

              // Switch: '<S61>/Switch' incorporates:
              //   Bias: '<S61>/Bias'
              //   Bias: '<S61>/Bias1'
              //   Constant: '<S57>/Constant'
              //   Constant: '<S57>/Constant1'
              //   Constant: '<S63>/Constant'
              //   Gain: '<S61>/Gain'
              //   Product: '<S61>/Divide1'
              //   RelationalOperator: '<S63>/Compare'
              //   Switch: '<S57>/Switch1'

              if (rtb_Abs1_jo > 90.0) {
                // Signum: '<S61>/Sign1'
                if (rtb_Switch_aa < 0.0) {
                  rtb_Switch_aa = -1.0;
                } else if (rtb_Switch_aa > 0.0) {
                  rtb_Switch_aa = 1.0;
                } else if (rtb_Switch_aa == 0.0) {
                  rtb_Switch_aa = 0.0;
                } else {
                  rtb_Switch_aa = (rtNaN);
                }

                rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
                b_nrows = 180;
              } else {
                rtb_Abs1_jo = rtb_Switch_aa;
                b_nrows = 0;
              }

              // Sum: '<S57>/Sum'
              rtb_Sum += static_cast<real_T>(b_nrows);

              // UnitConversion: '<S60>/Unit Conversion'
              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

              // UnitConversion: '<S75>/Unit Conversion'
              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              rtb_Down *= 0.017453292519943295;

              // Trigonometry: '<S76>/Trigonometric Function1'
              rtb_Param4_e = std::sin(rtb_Down);

              // Sum: '<S76>/Sum1' incorporates:
              //   Constant: '<S76>/Constant'
              //   Product: '<S76>/Product1'

              rtb_Param4_e = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_d *
                PreemptableMissionModeSelector_ConstB.sqrt_d * rtb_Param4_e *
                rtb_Param4_e;

              // Product: '<S74>/Product1' incorporates:
              //   Constant: '<S74>/Constant1'
              //   Sqrt: '<S74>/sqrt'

              rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

              // Product: '<S59>/dNorth' incorporates:
              //   Constant: '<S74>/Constant2'
              //   Product: '<S74>/Product3'
              //   Trigonometry: '<S74>/Trigonometric Function1'

              rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
                PreemptableMissionModeSelector_ConstB.Sum1_k / rtb_Param4_e);

              // Switch: '<S62>/Switch' incorporates:
              //   Abs: '<S62>/Abs'
              //   Bias: '<S62>/Bias'
              //   Bias: '<S62>/Bias1'
              //   Constant: '<S62>/Constant2'
              //   Constant: '<S66>/Constant'
              //   Math: '<S62>/Math Function1'
              //   RelationalOperator: '<S66>/Compare'

              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              if (std::abs(rtb_Sum) > 180.0) {
                rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
              }

              // Product: '<S59>/dEast' incorporates:
              //   Constant: '<S74>/Constant3'
              //   Product: '<S74>/Product4'
              //   Trigonometry: '<S74>/Trigonometric Function'
              //   Trigonometry: '<S74>/Trigonometric Function2'
              //   UnitConversion: '<S60>/Unit Conversion'

              rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos
                (rtb_Down)) * (0.017453292519943295 * rtb_Sum);

              // Sum: '<S55>/Sum' incorporates:
              //   DataStoreRead: '<S4>/AltitudeGCS'
              //   Gain: '<S4>/inverse'

              rtb_Gain1 = rtu_Location->Alt + -AltitudeGCS;

              // Gain: '<S54>/Gain1'
              rtb_Switch_e = 0.017453292519943295 * rtu_Location->degHDG;

              // Outputs for Triggered SubSystem: '<S4>/WayPointGenerator' incorporates:
              //   TriggerPort: '<S56>/Trigger'

              zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                                 &localZCE->WayPointGenerator_Trig_ZCE_p,
                                 (localDW->MemoryTriggerWP_PreviousInput_i));
              if (zcEvent != NO_ZCEVENT) {
                // DataTypeConversion: '<S56>/Cast To Double'
                rtb_Switch = static_cast<real_T>(*rtu_FormationIDX);

                // Abs: '<S56>/Abs'
                rtb_Abs = static_cast<uint32_T>(std::abs(rtb_Switch));

                // Signum: '<S56>/Sign'
                if (rtb_Switch < 0.0) {
                  rtb_Switch = -1.0;
                } else if (rtb_Switch > 0.0) {
                  rtb_Switch = 1.0;
                } else {
                  rtb_Switch = 0.0;
                }

                // Gain: '<S56>/HalfRotAng' incorporates:
                //   DataTypeConversion: '<S4>/Param2'
                //   Gain: '<S79>/Gain1'
                //   Product: '<S56>/ProductFlipRotAng'

                rtb_Switch_p = 0.017453292519943295 * static_cast<real_T>
                  (rtu_Parameters->Param2) * rtb_Switch * 0.5;

                // MATLAB Function: '<S56>/WayPointGenerator' incorporates:
                //   DataTypeConversion: '<S4>/Param3'

                PreemptableMissionModeSelector_uavDubinsConnection_uavDubinsConnection
                  (&connectionObj);
                LUp[0] = 0.0;
                rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) /
                  2.0;
                LUp[1] = rtb_Switch_aa;
                LUp[2] = 0.0;
                LUp[3] = 1.5707963267948966;
                LDp[0] = 0.0;
                rtb_Sum = -static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
                LDp[1] = rtb_Sum;
                LDp[2] = 0.0;
                LDp[3] = 1.5707963267948966;
                PreemptableMissionModeSelector_uavDubinsConnection_connect
                  (&connectionObj, LUp, LDp, localB->pathSegObj.data,
                   &localB->pathSegObj.size, a__1_data, &b_nrows, localB);
                PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate
                  (localB->pathSegObj.data[0].StartPose, localB->
                   pathSegObj.data[0].GoalPose, localB->pathSegObj.data[0].
                   FlightPathAngle, localB->pathSegObj.data[0].AirSpeed,
                   localB->pathSegObj.data[0].MinTurningRadius,
                   localB->pathSegObj.data[0].HelixRadius,
                   localB->pathSegObj.data[0].MotionTypes,
                   localB->pathSegObj.data[0].MotionLengths,
                   localB->pathSegObj.data[0].Length, localB->pathSegObj.data[0]
                   .Length / 2.0, midpose_data, midpose_size);
                rtb_startPose_f[0] = 0.0;
                rtb_Down = (localB->pathSegObj.data[0].Length +
                            static_cast<real_T>(rtu_Parameters->Param3)) / 3.0 -
                  localB->pathSegObj.data[0].Length / 2.0;
                rtb_startPose_f[1] = rtb_Switch_aa - rtb_Down;
                rtb_startPose_f[2] = 0.0;
                rtb_startPose_f[3] = 1.5707963267948966;
                ende[0] = 0.0;
                ende[1] = rtb_Down + rtb_Sum;
                ende[2] = 0.0;
                ende[3] = 1.5707963267948966;
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (initWayPoint->size[0] * initWayPoint->size[1]);

                // MATLAB Function: '<S56>/WayPointGenerator'
                initWayPoint->size[0] = 1;
                initWayPoint->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (initWayPoint, rtb_ClockwiseRotation_n);

                // MATLAB Function: '<S56>/WayPointGenerator'
                initWayPoint->data[0] = 0.0;
                initWayPoint->data[1] = 0.0;
                initWayPoint->data[2] = 0.0;
                switch (static_cast<int32_T>(rtb_Abs)) {
                 case 0:
                  PreemptableMissionModeSelector_genSegWP(&connectionObj,
                    rtb_startPose_f, LUp, 100.0, segWayPoints, localB);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (initWayPoint->size[0] * initWayPoint->size[1]);
                  initWayPoint->size[0] = static_cast<int32_T>
                    (segWayPoints->size[0] + 1);
                  initWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (initWayPoint, rtb_ClockwiseRotation_n);
                  ibmat = segWayPoints->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0]
                      * b_nrows)] = 0.0;
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      initWayPoint->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          static_cast<int32_T>(initWayPoint->size[0] * b_nrows))
                         + 1)] = segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }
                  }
                  break;

                 case 1:
                  rtb_startPose_f[0] = midpose_data[0];
                  rtb_startPose_f[1] = midpose_data[midpose_size[0]];
                  rtb_startPose_f[2] = midpose_data[static_cast<int32_T>
                    (midpose_size[0] << 1)];
                  rtb_startPose_f[3] = midpose_data[static_cast<int32_T>
                    (midpose_size[0] * 3)];
                  PreemptableMissionModeSelector_genSegWP(&connectionObj,
                    &midpose_data[0], LDp, 100.0, segWayPoints, localB);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (initWayPoint->size[0] * initWayPoint->size[1]);
                  initWayPoint->size[0] = static_cast<int32_T>
                    (segWayPoints->size[0] + 1);
                  initWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (initWayPoint, rtb_ClockwiseRotation_n);
                  ibmat = segWayPoints->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0]
                      * b_nrows)] = 0.0;
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      initWayPoint->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          static_cast<int32_T>(initWayPoint->size[0] * b_nrows))
                         + 1)] = segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }
                  }
                  break;

                 case 2:
                  rtb_startPose_f[0] = 0.0;
                  rtb_startPose_f[1] = ende[1];
                  rtb_startPose_f[2] = 0.0;
                  rtb_startPose_f[3] = 1.5707963267948966;
                  PreemptableMissionModeSelector_genSegWP(&connectionObj, ende,
                    LUp, 100.0, segWayPoints, localB);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (initWayPoint->size[0] * initWayPoint->size[1]);
                  initWayPoint->size[0] = static_cast<int32_T>
                    (segWayPoints->size[0] + 1);
                  initWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (initWayPoint, rtb_ClockwiseRotation_n);
                  ibmat = segWayPoints->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0]
                      * b_nrows)] = 0.0;
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      initWayPoint->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          static_cast<int32_T>(initWayPoint->size[0] * b_nrows))
                         + 1)] = segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }
                  }
                  break;

                 default:
                  rtb_startPose_f[0] = 0.0;
                  rtb_startPose_f[1] = 0.0;
                  rtb_startPose_f[2] = 0.0;
                  rtb_startPose_f[3] = 0.0;
                  break;
                }

                PreemptableMissionModeSelector_genSegWP(&connectionObj, LUp, LDp,
                  100.0, segWayPoints, localB);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                // MATLAB Function: '<S56>/WayPointGenerator'
                dummyWayPoint->size[0] = static_cast<int32_T>(segWayPoints->
                  size[0] + 1);
                dummyWayPoint->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (dummyWayPoint, rtb_ClockwiseRotation_n);

                // MATLAB Function: '<S56>/WayPointGenerator'
                ibmat = segWayPoints->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  dummyWayPoint->data[static_cast<int32_T>(dummyWayPoint->size[0]
                    * b_nrows)] = 0.0;
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint->size[0] * b_nrows)) + 1)] =
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] * b_nrows))];
                  }
                }

                PreemptableMissionModeSelector_genSegWP(&connectionObj, LDp, LUp,
                  100.0, segWayPoints, localB);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

                // MATLAB Function: '<S56>/WayPointGenerator'
                dummyWayPoint_0->size[0] = static_cast<int32_T>
                  (dummyWayPoint->size[0] + segWayPoints->size[0]);
                dummyWayPoint_0->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (dummyWayPoint_0, rtb_ClockwiseRotation_n);

                // MATLAB Function: '<S56>/WayPointGenerator'
                ibmat = dummyWayPoint->size[0];
                loop_ub = segWayPoints->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint_0->size[0] * b_nrows))] =
                      dummyWayPoint->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint->size[0] * b_nrows))];
                  }

                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(loop_ub - 1);
                       rtb_ClockwiseRotation_n++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                      (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                        dummyWayPoint->size[0]) + static_cast<int32_T>
                       (dummyWayPoint_0->size[0] * b_nrows))] =
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] * b_nrows))];
                  }
                }

                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                // MATLAB Function: '<S56>/WayPointGenerator'
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (dummyWayPoint, rtb_ClockwiseRotation_n);

                // MATLAB Function: '<S56>/WayPointGenerator'
                ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                     b_nrows++) {
                  dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
                }

                nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
                nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                     (rtb_ClockwiseRotation_n + 1)) {
                  dummyWayPoint->data[rtb_ClockwiseRotation_n] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + 1)];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                     (rtb_ClockwiseRotation_n + 1)) {
                  dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + dummyWayPoint->size[0])] =
                    dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) + 1)];
                }

                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                     (rtb_ClockwiseRotation_n + 1)) {
                  dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] << 1))] = dummyWayPoint->data[
                    static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] << 1)) + 1)];
                }

                if (1 > nrows) {
                  nrowx = -1;
                  b_nrows = -1;
                } else {
                  b_nrows = nrowx;
                }

                ibmat = static_cast<int32_T>(b_nrows + 1);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

                // MATLAB Function: '<S56>/WayPointGenerator'
                dummyWayPoint_0->size[0] = static_cast<int32_T>(nrowx + 1);
                dummyWayPoint_0->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (dummyWayPoint_0, rtb_ClockwiseRotation_n);

                // MATLAB Function: '<S56>/WayPointGenerator'
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint_0->size[0] * b_nrows))] =
                      dummyWayPoint->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint->size[0] * b_nrows))];
                  }
                }

                PreemptableMissionModeSelector_repmat(dummyWayPoint_0, std::ceil
                  (10240.0 / static_cast<real_T>(static_cast<int32_T>(nrowx + 1))),
                  dummyWayPoint);
                if (2 > initWayPoint->size[0]) {
                  nrowx = -1;
                  nrows = -1;
                } else {
                  nrowx = 0;
                  nrows = static_cast<int32_T>(initWayPoint->size[0] - 1);
                }

                // Gain: '<S56>/RevFlip'
                b_nrows = static_cast<int32_T>(-static_cast<int32_T>(rtb_Switch));

                // Product: '<S56>/ProductFlipStartPose'
                LUp[0] = rtb_startPose_f[0] * static_cast<real_T>(b_nrows);
                LUp[1] = rtb_startPose_f[1];
                LUp[2] = rtb_startPose_f[2];

                // Bias: '<S56>/Bias' incorporates:
                //   Product: '<S56>/ProductFlipStartPose'
                //   Sum: '<S56>/Sum'

                localB->Bias_g = ((rtb_Switch_e + rtb_Switch_p) +
                                  rtb_startPose_f[3]) + -1.5707963267948966;

                // SignalConversion generated from: '<S56>/RotateATRunWayHdg' incorporates:
                //   Constant: '<S56>/Zero'

                rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[0] =
                  rtb_Switch_p;
                rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[1] = 0.0;
                rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[2] = 0.0;
                PreemptableMissionModeSelector_RotateATMissionHdg
                  (rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c,
                   &localB->RotateATRunWayHdg);

                // Product: '<S56>/ProductFlipXbias' incorporates:
                //   DataTypeConversion: '<S4>/Param1'
                //   Gain: '<S56>/HalfSepDis'

                rtb_Switch *= 0.5 * static_cast<real_T>(rtu_Parameters->Param1);

                // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
                //   Constant: '<S56>/Zeros'

                rtb_MatrixConcatenate[0] = static_cast<int8_T>(b_nrows);
                rtb_MatrixConcatenate[1] = 0;
                rtb_MatrixConcatenate[2] = 0;

                // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
                //   Constant: '<S56>/One'
                //   Constant: '<S56>/Zeros'

                rtb_MatrixConcatenate[3] = 0;
                rtb_MatrixConcatenate[4] = 1;
                rtb_MatrixConcatenate[5] = 0;

                // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
                //   Constant: '<S56>/One'
                //   Constant: '<S56>/Zeros'

                rtb_MatrixConcatenate[6] = 0;
                rtb_MatrixConcatenate[7] = 0;
                rtb_MatrixConcatenate[8] = 1;

                // MATLAB Function: '<S56>/WayPointGenerator'
                ibmat = static_cast<int32_T>(nrows - nrowx);
                rtb_ClockwiseRotation_n = static_cast<int32_T>
                  (segWayPoints->size[0] * segWayPoints->size[1]);

                // MATLAB Function: '<S56>/WayPointGenerator'
                segWayPoints->size[0] = static_cast<int32_T>(ibmat +
                  dummyWayPoint->size[0]);
                segWayPoints->size[1] = 3;
                PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                  (segWayPoints, rtb_ClockwiseRotation_n);

                // MATLAB Function: '<S56>/WayPointGenerator'
                loop_ub = dummyWayPoint->size[0];
                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n
                       ++) {
                    segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] * b_nrows))] = initWayPoint->data[
                      static_cast<int32_T>(static_cast<int32_T>
                      (static_cast<int32_T>(nrowx + rtb_ClockwiseRotation_n) +
                       static_cast<int32_T>(initWayPoint->size[0] * b_nrows)) +
                      1)];
                  }

                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(loop_ub - 1);
                       rtb_ClockwiseRotation_n++) {
                    segWayPoints->data[static_cast<int32_T>(static_cast<int32_T>
                      (static_cast<int32_T>(rtb_ClockwiseRotation_n + nrows) -
                       nrowx) + static_cast<int32_T>(segWayPoints->size[0] *
                      b_nrows))] = dummyWayPoint->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint->size[0] * b_nrows))];
                  }
                }

                // Product: '<S56>/ProductFlipRunWay' incorporates:
                //   Concatenate: '<S56>/Matrix Concatenate'
                //   MATLAB Function: '<S56>/WayPointGenerator'

                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                       10240; rtb_ClockwiseRotation_n++) {
                    ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                      static_cast<int32_T>(10240 * b_nrows));
                    localB->RotateIndivWayPoint[ibmat] = 0.0;
                    localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                      (rtb_MatrixConcatenate[static_cast<int32_T>(3 * b_nrows)])
                      * segWayPoints->data[rtb_ClockwiseRotation_n];
                    localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                      (rtb_MatrixConcatenate[static_cast<int32_T>
                       (static_cast<int32_T>(3 * b_nrows) + 1)]) *
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + segWayPoints->size[0])];
                    localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                      (rtb_MatrixConcatenate[static_cast<int32_T>
                       (static_cast<int32_T>(3 * b_nrows) + 2)]) *
                      segWayPoints->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (segWayPoints->size[0] << 1))];
                  }
                }

                // Reshape: '<S56>/Reshape' incorporates:
                //   Constant: '<S56>/Zero'

                rtb_Reshape_i[0] = rtb_Switch;
                rtb_Reshape_i[1] = 0.0;
                rtb_Reshape_i[2] = 0.0;

                // Reshape: '<S56>/ReshapeRowVec' incorporates:
                //   Product: '<S59>/x*cos'
                //   Product: '<S59>/x*sin'
                //   Product: '<S59>/y*cos'
                //   Product: '<S59>/y*sin'
                //   Reshape: '<S56>/ReshapeRowVecStartpose'
                //   Sum: '<S59>/Sum2'
                //   Sum: '<S59>/Sum3'
                //   UnaryMinus: '<S55>/Ze2height'

                rtb_ReshapeRowVec[0] = rtb_Abs1_jo * 0.0 + rtb_Param4_e;
                rtb_ReshapeRowVec[1] = rtb_Abs1_jo - rtb_Param4_e * 0.0;
                rtb_ReshapeRowVec[2] = -rtb_Gain1;

                // SignalConversion generated from: '<S56>/RotateATMissionHdg' incorporates:
                //   Constant: '<S56>/Zero'

                rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[0] =
                  rtb_Switch_e;
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[1] = 0.0;
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[2] = 0.0;
                PreemptableMissionModeSelector_RotateATMissionHdg
                  (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd,
                   &localB->RotateATMissionHdg);

                // Product: '<S56>/RotateRunway' incorporates:
                //   MATLABSystem: '<S56>/RotateATRunWayHdg'

                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                       10240; rtb_ClockwiseRotation_n++) {
                    ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                      static_cast<int32_T>(10240 * b_nrows));
                    localB->WayPoint[ibmat] = 0.0;
                    localB->WayPoint[ibmat] +=
                      localB->RotateATRunWayHdg.RotateATMissionHdg
                      [static_cast<int32_T>(3 * b_nrows)] *
                      localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                    localB->WayPoint[ibmat] +=
                      localB->RotateATRunWayHdg.RotateATMissionHdg
                      [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                      1)] * localB->RotateIndivWayPoint[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + 10240)];
                    localB->WayPoint[ibmat] +=
                      localB->RotateATRunWayHdg.RotateATMissionHdg
                      [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                      2)] * localB->RotateIndivWayPoint[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + 20480)];
                  }
                }

                // MATLAB Function: '<S56>/minus'
                PreemptableMissionModeSelector_minus(localB->WayPoint,
                  rtb_Reshape_i, localB->RotateIndivWayPoint);

                // Product: '<S56>/RotateIndivWayPoint' incorporates:
                //   MATLABSystem: '<S56>/RotateATMissionHdg'

                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                       10240; rtb_ClockwiseRotation_n++) {
                    ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                      static_cast<int32_T>(10240 * b_nrows));
                    localB->WayPoint[ibmat] = 0.0;
                    localB->WayPoint[ibmat] +=
                      localB->RotateATMissionHdg.RotateATMissionHdg
                      [static_cast<int32_T>(3 * b_nrows)] *
                      localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                    localB->WayPoint[ibmat] +=
                      localB->RotateATMissionHdg.RotateATMissionHdg
                      [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                      1)] * localB->RotateIndivWayPoint[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + 10240)];
                    localB->WayPoint[ibmat] +=
                      localB->RotateATMissionHdg.RotateATMissionHdg
                      [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                      2)] * localB->RotateIndivWayPoint[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + 20480)];
                  }
                }

                // Product: '<S56>/RotateRunwayStartpose' incorporates:
                //   MATLABSystem: '<S56>/RotateATRunWayHdg'

                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  rtb_Reshape_i[b_nrows] =
                    localB->RotateATRunWayHdg.RotateATMissionHdg
                    [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)]
                    * LUp[2] + (localB->RotateATRunWayHdg.RotateATMissionHdg[
                                static_cast<int32_T>(static_cast<int32_T>(3 *
                    b_nrows) + 1)] * LUp[1] +
                                localB->RotateATRunWayHdg.RotateATMissionHdg[
                                static_cast<int32_T>(3 * b_nrows)] * LUp[0]);
                }

                // Sum: '<S56>/BiasStartPose'
                rtb_Switch_aa = rtb_Reshape_i[0] - rtb_Switch;
                rtb_Sum = rtb_Reshape_i[1];
                rtb_Down = rtb_Reshape_i[2];

                // Product: '<S56>/RotateIndivWayPointStartpose' incorporates:
                //   MATLABSystem: '<S56>/RotateATMissionHdg'

                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  rtb_Reshape_i[b_nrows] =
                    localB->RotateATMissionHdg.RotateATMissionHdg
                    [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)]
                    * rtb_Down + (localB->RotateATMissionHdg.RotateATMissionHdg[
                                  static_cast<int32_T>(static_cast<int32_T>(3 *
                    b_nrows) + 1)] * rtb_Sum +
                                  localB->RotateATMissionHdg.RotateATMissionHdg[
                                  static_cast<int32_T>(3 * b_nrows)] *
                                  rtb_Switch_aa);
                }

                // MATLAB Function: '<S56>/biasNED' incorporates:
                //   Reshape: '<S56>/ReshapeRowVec'

                PreemptableMissionModeSelector_biasNED(rtb_ReshapeRowVec,
                  localB->WayPoint, localB->nedWayPoint_j, &localB->sf_biasNED);

                // MATLAB Function: '<S56>/biasNEDstartpose'
                PreemptableMissionModeSelector_biasNEDstartpose
                  (rtb_ReshapeRowVec, rtb_Reshape_i, localB->nedWayPoint_l);
              }

              // End of Outputs for SubSystem: '<S4>/WayPointGenerator'
              PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
                localB->nedWayPoint_j, 200.0, &localB->WaypointFollower,
                &localDW->WaypointFollower);

              // DataTypeConversion: '<S4>/Cast To Double' incorporates:
              //   Constant: '<S4>/LookAheadDis'
              //   MATLAB Function: '<S56>/WayPointGenerator'
              //   Memory: '<S4>/MemoryTriggerWP'

              *rty_thisTaskStatus = static_cast<real_T>
                (localB->WaypointFollower.WaypointFollower_o5);

              // Gain: '<S4>/HalfSum' incorporates:
              //   DataTypeConversion: '<S4>/Param4'
              //   DataTypeConversion: '<S4>/Param5'
              //   Sum: '<S4>/SumSpd'

              rtb_Param4_e = (static_cast<real_T>(rtu_Parameters->Param4) +
                              static_cast<real_T>(rtu_Parameters->Param5)) * 0.5;

              // BusCreator: '<S4>/GuidanceCMDBusCreator' incorporates:
              //   Gain: '<S4>/Down2Height'

              rty_GuidanceCmds->Height =
                -localB->WaypointFollower.WaypointFollower_o1[2];
              rty_GuidanceCmds->AirSpeed = rtb_Param4_e;
              rty_GuidanceCmds->HeadingAngle =
                localB->WaypointFollower.WaypointFollower_o2;

              // Product: '<S4>/ProductEast' incorporates:
              //   Trigonometry: '<S4>/Sin'

              rty_VelShift[1] = rtb_Down_c * std::sin(rtb_Switch_e);

              // Product: '<S4>/ProductNorth' incorporates:
              //   Trigonometry: '<S4>/Cos'

              rty_VelShift[0] = std::cos(rtb_Switch_e) * rtb_Down_c;

              // Reshape: '<S4>/Reshape' incorporates:
              //   Constant: '<S4>/InitialFlightPathAngle'
              //   Constant: '<S4>/InitialRollAngle'
              //   Constant: '<S4>/InitialRollAngleRate'
              //   Gain: '<S4>/Down2Up'

              rty_InitialState[0] = localB->nedWayPoint_l[0];
              rty_InitialState[1] = localB->nedWayPoint_l[1];
              rty_InitialState[2] = -localB->nedWayPoint_l[2];
              rty_InitialState[3] = rtb_Param4_e;
              rty_InitialState[4] = localB->Bias_g;
              rty_InitialState[5] = 0.0;
              rty_InitialState[6] = 0.0;
              rty_InitialState[7] = 0.0;

              // Sum: '<S4>/Sum' incorporates:
              //   Memory: '<S4>/MemoryStopTrigger1'
              //   Memory: '<S4>/MemoryTriggerWP'

              *rty_ResetTrigger = localDW->MemoryStopTrigger1_PreviousInput_o +
                localDW->MemoryTriggerWP_PreviousInput_i;

              // Update for Memory: '<S4>/MemoryTriggerWP' incorporates:
              //   Constant: '<S4>/TirggerWayPointGen'

              localDW->MemoryTriggerWP_PreviousInput_i = 1.0;

              // Update for Memory: '<S4>/MemoryStopTrigger1' incorporates:
              //   Memory: '<S4>/MemoryStopTrigger2'

              localDW->MemoryStopTrigger1_PreviousInput_o =
                localDW->MemoryStopTrigger2_PreviousInput_n;

              // Update for Memory: '<S4>/MemoryStopTrigger2' incorporates:
              //   Constant: '<S4>/StopTrigger'

              localDW->MemoryStopTrigger2_PreviousInput_n = -1.0;
            } else {
              guard1 = true;
            }
          }
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      switch (localDW->is_GuidanceLogic) {
       case PreemptableMissionModeSelector_IN_OrbitFollower:
        *rty_ResetTrigger = 0.0;
        if (static_cast<int32_T>(localDW->is_OrbitFollower) == 1) {
          // DataTypeConversion: '<S2>/Param1'
          rtb_Param1_i = static_cast<real_T>(rtu_Parameters->Param1);

          // Product: '<S2>/Divide'
          rtb_Down_c = rtu_StartPosition->Lat / rtb_Param1_i;

          // Switch: '<S22>/Switch' incorporates:
          //   Abs: '<S22>/Abs'
          //   Bias: '<S22>/Bias'
          //   Bias: '<S22>/Bias1'
          //   Constant: '<S22>/Constant2'
          //   Constant: '<S23>/Constant'
          //   DataStoreRead: '<S2>/LatitudeGCS'
          //   Math: '<S22>/Math Function1'
          //   RelationalOperator: '<S23>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            rtb_Down = LatitudeGCS;
          }

          // Abs: '<S19>/Abs1'
          rtb_Switch_aa = std::abs(rtb_Down);

          // Switch: '<S19>/Switch' incorporates:
          //   Bias: '<S19>/Bias'
          //   Bias: '<S19>/Bias1'
          //   Constant: '<S10>/Constant'
          //   Constant: '<S10>/Constant1'
          //   Constant: '<S21>/Constant'
          //   Gain: '<S19>/Gain'
          //   Product: '<S19>/Divide1'
          //   RelationalOperator: '<S21>/Compare'
          //   Switch: '<S10>/Switch1'

          if (rtb_Switch_aa > 90.0) {
            // Signum: '<S19>/Sign1'
            if (rtb_Down < 0.0) {
              rtb_Down = -1.0;
            } else if (rtb_Down > 0.0) {
              rtb_Down = 1.0;
            } else if (rtb_Down == 0.0) {
              rtb_Down = 0.0;
            } else {
              rtb_Down = (rtNaN);
            }

            rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S10>/Sum' incorporates:
          //   DataStoreRead: '<S2>/LongitudeGCS'

          rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

          // Sum: '<S8>/Sum1'
          rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

          // Switch: '<S20>/Switch' incorporates:
          //   Abs: '<S20>/Abs'
          //   Bias: '<S20>/Bias'
          //   Bias: '<S20>/Bias1'
          //   Constant: '<S20>/Constant2'
          //   Constant: '<S24>/Constant'
          //   Math: '<S20>/Math Function1'
          //   RelationalOperator: '<S24>/Compare'

          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S8>/Sum1'
          rtb_Sum = rtu_Location->Lon - rtb_Sum;

          // Switch: '<S16>/Switch' incorporates:
          //   Abs: '<S16>/Abs'
          //   Bias: '<S16>/Bias'
          //   Bias: '<S16>/Bias1'
          //   Constant: '<S16>/Constant2'
          //   Constant: '<S17>/Constant'
          //   Math: '<S16>/Math Function1'
          //   RelationalOperator: '<S17>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S13>/Abs1'
          rtb_Abs1_jo = std::abs(rtb_Switch_aa);

          // Switch: '<S13>/Switch' incorporates:
          //   Bias: '<S13>/Bias'
          //   Bias: '<S13>/Bias1'
          //   Constant: '<S15>/Constant'
          //   Constant: '<S9>/Constant'
          //   Constant: '<S9>/Constant1'
          //   Gain: '<S13>/Gain'
          //   Product: '<S13>/Divide1'
          //   RelationalOperator: '<S15>/Compare'
          //   Switch: '<S9>/Switch1'

          if (rtb_Abs1_jo > 90.0) {
            // Signum: '<S13>/Sign1'
            if (rtb_Switch_aa < 0.0) {
              rtb_Switch_aa = -1.0;
            } else if (rtb_Switch_aa > 0.0) {
              rtb_Switch_aa = 1.0;
            } else if (rtb_Switch_aa == 0.0) {
              rtb_Switch_aa = 0.0;
            } else {
              rtb_Switch_aa = (rtNaN);
            }

            rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
            b_nrows = 180;
          } else {
            rtb_Abs1_jo = rtb_Switch_aa;
            b_nrows = 0;
          }

          // Sum: '<S9>/Sum'
          rtb_Sum += static_cast<real_T>(b_nrows);

          // UnitConversion: '<S12>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

          // UnitConversion: '<S27>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Down *= 0.017453292519943295;

          // Trigonometry: '<S28>/Trigonometric Function1'
          rtb_Param4_e = std::sin(rtb_Down);

          // Sum: '<S28>/Sum1' incorporates:
          //   Constant: '<S28>/Constant'
          //   Product: '<S28>/Product1'

          rtb_Param4_e = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_g *
            PreemptableMissionModeSelector_ConstB.sqrt_g * rtb_Param4_e *
            rtb_Param4_e;

          // Product: '<S26>/Product1' incorporates:
          //   Constant: '<S26>/Constant1'
          //   Sqrt: '<S26>/sqrt'

          rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

          // Product: '<S11>/dNorth' incorporates:
          //   Constant: '<S26>/Constant2'
          //   Product: '<S26>/Product3'
          //   Trigonometry: '<S26>/Trigonometric Function1'

          rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
            PreemptableMissionModeSelector_ConstB.Sum1_kk / rtb_Param4_e);

          // Switch: '<S14>/Switch' incorporates:
          //   Abs: '<S14>/Abs'
          //   Bias: '<S14>/Bias'
          //   Bias: '<S14>/Bias1'
          //   Constant: '<S14>/Constant2'
          //   Constant: '<S18>/Constant'
          //   Math: '<S14>/Math Function1'
          //   RelationalOperator: '<S18>/Compare'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Product: '<S11>/dEast' incorporates:
          //   Constant: '<S26>/Constant3'
          //   Product: '<S26>/Product4'
          //   Trigonometry: '<S26>/Trigonometric Function'
          //   Trigonometry: '<S26>/Trigonometric Function2'
          //   UnitConversion: '<S12>/Unit Conversion'

          rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos(rtb_Down))
            * (0.017453292519943295 * rtb_Sum);

          // Sum: '<S11>/Sum2' incorporates:
          //   Product: '<S11>/x*cos'
          //   Product: '<S11>/y*sin'

          rtb_Down = rtb_Abs1_jo * 0.0 + rtb_Param4_e;

          // Sum: '<S11>/Sum3' incorporates:
          //   Product: '<S11>/x*sin'
          //   Product: '<S11>/y*cos'

          rtb_Switch_aa = rtb_Abs1_jo - rtb_Param4_e * 0.0;

          // Sum: '<S8>/Sum' incorporates:
          //   DataStoreRead: '<S2>/AltitudeGCS'
          //   Gain: '<S2>/inverse'

          rtb_Sum = rtu_Location->Alt + -AltitudeGCS;

          // Sum: '<S2>/SumUp' incorporates:
          //   UnaryMinus: '<S8>/Ze2height'

          rtb_Sum += rtu_StartPosition->Alt;

          // SignalConversion generated from: '<S2>/Orbit Follower' incorporates:
          //   Gain: '<S2>/Up2Down'

          rtb_TmpSignalConversionAtOrbitFollowerInport2_b[0] = rtb_Down;
          rtb_TmpSignalConversionAtOrbitFollowerInport2_b[1] = rtb_Switch_aa;
          rtb_TmpSignalConversionAtOrbitFollowerInport2_b[2] = -rtb_Sum;

          // DataTypeConversion: '<S2>/Param2'
          rtb_Param2_n1 = static_cast<real_T>(rtu_Parameters->Param2);
          PreemptableMissionModeSelector_OrbitFollower(rtu_Pose,
            rtb_TmpSignalConversionAtOrbitFollowerInport2_b, rtb_Param1_i,
            rtb_Param2_n1, 1.0, &localB->OrbitFollower, &localDW->OrbitFollower);

          // BusCreator: '<S2>/GuidanceCMDBusCreator' incorporates:
          //   Constant: '<S2>/Constant'
          //   DataTypeConversion: '<S2>/Param3'
          //   Gain: '<S2>/Down2Height'

          rty_GuidanceCmds->Height = -localB->OrbitFollower.OrbitFollower_o1[2];
          rty_GuidanceCmds->AirSpeed = static_cast<real_T>
            (rtu_Parameters->Param4);
          rty_GuidanceCmds->HeadingAngle =
            localB->OrbitFollower.OrbitFollower_o2;

          // Reshape: '<S2>/Reshape' incorporates:
          //   Bias: '<S2>/ClockwiseRotation'
          //   Constant: '<S2>/InitialFlightPathAngle'
          //   Constant: '<S2>/InitialRollAngle'
          //   Constant: '<S2>/InitialRollAngleRate'
          //   DataTypeConversion: '<S2>/Param3'
          //   Product: '<S2>/EastDis'
          //   Product: '<S2>/NorthDis'
          //   Sum: '<S2>/SumInitEast'
          //   Sum: '<S2>/SumInitNorth'
          //   Trigonometry: '<S2>/Cos'
          //   Trigonometry: '<S2>/Sin'

          rty_InitialState[0] = std::cos(rtb_Down_c) * rtb_Param1_i + rtb_Down;
          rty_InitialState[1] = rtb_Param1_i * std::sin(rtb_Down_c) +
            rtb_Switch_aa;
          rty_InitialState[2] = rtb_Sum;
          rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
          rty_InitialState[4] = rtb_Down_c + 1.5707963267948966;
          rty_InitialState[5] = 0.0;
          rty_InitialState[6] = 0.0;
          rty_InitialState[7] = 0.0;

          // SignalConversion generated from: '<S2>/Orbit Follower'
          *rty_thisTaskStatus = localB->OrbitFollower.OrbitFollower_o6;
        } else {
          // Bias: '<S3>/Bias'
          // case IN_CirclingNav:
          b_nrows = *rtu_MissionUAV;

          // DataTypeConversion: '<S3>/CastToDouble'
          rtb_ClockwiseRotation_n = *rtu_FormationIDX;

          // Product: '<S3>/Divide' incorporates:
          //   Constant: '<S3>/two_pi'

          rtb_Down_c = 6.2831853071795862 / static_cast<real_T>(*rtu_MissionUAV);

          // Product: '<S3>/Map2Radian' incorporates:
          //   Bias: '<S3>/Bias'
          //   Gain: '<S3>/HalveMissionUAV'
          //   Sum: '<S3>/Minus'

          rtb_Down_c *= static_cast<real_T>(rtb_ClockwiseRotation_n) -
            static_cast<real_T>(static_cast<int32_T>(b_nrows + 1)) * 0.5;

          // Switch: '<S45>/Switch' incorporates:
          //   Abs: '<S45>/Abs'
          //   Bias: '<S45>/Bias'
          //   Bias: '<S45>/Bias1'
          //   Constant: '<S45>/Constant2'
          //   Constant: '<S46>/Constant'
          //   DataStoreRead: '<S3>/LatitudeGCS'
          //   Math: '<S45>/Math Function1'
          //   RelationalOperator: '<S46>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            rtb_Down = LatitudeGCS;
          }

          // Abs: '<S42>/Abs1'
          rtb_Switch_aa = std::abs(rtb_Down);

          // Switch: '<S42>/Switch' incorporates:
          //   Bias: '<S42>/Bias'
          //   Bias: '<S42>/Bias1'
          //   Constant: '<S33>/Constant'
          //   Constant: '<S33>/Constant1'
          //   Constant: '<S44>/Constant'
          //   Gain: '<S42>/Gain'
          //   Product: '<S42>/Divide1'
          //   RelationalOperator: '<S44>/Compare'
          //   Switch: '<S33>/Switch1'

          if (rtb_Switch_aa > 90.0) {
            // Signum: '<S42>/Sign1'
            if (rtb_Down < 0.0) {
              rtb_Down = -1.0;
            } else if (rtb_Down > 0.0) {
              rtb_Down = 1.0;
            } else if (rtb_Down == 0.0) {
              rtb_Down = 0.0;
            } else {
              rtb_Down = (rtNaN);
            }

            rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S33>/Sum' incorporates:
          //   DataStoreRead: '<S3>/LongitudeGCS'

          rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

          // Sum: '<S31>/Sum1'
          rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

          // Switch: '<S43>/Switch' incorporates:
          //   Abs: '<S43>/Abs'
          //   Bias: '<S43>/Bias'
          //   Bias: '<S43>/Bias1'
          //   Constant: '<S43>/Constant2'
          //   Constant: '<S47>/Constant'
          //   Math: '<S43>/Math Function1'
          //   RelationalOperator: '<S47>/Compare'

          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S31>/Sum1'
          rtb_Sum = rtu_Location->Lon - rtb_Sum;

          // Switch: '<S39>/Switch' incorporates:
          //   Abs: '<S39>/Abs'
          //   Bias: '<S39>/Bias'
          //   Bias: '<S39>/Bias1'
          //   Constant: '<S39>/Constant2'
          //   Constant: '<S40>/Constant'
          //   Math: '<S39>/Math Function1'
          //   RelationalOperator: '<S40>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S36>/Abs1'
          rtb_Abs1_jo = std::abs(rtb_Switch_aa);

          // Switch: '<S36>/Switch' incorporates:
          //   Bias: '<S36>/Bias'
          //   Bias: '<S36>/Bias1'
          //   Constant: '<S32>/Constant'
          //   Constant: '<S32>/Constant1'
          //   Constant: '<S38>/Constant'
          //   Gain: '<S36>/Gain'
          //   Product: '<S36>/Divide1'
          //   RelationalOperator: '<S38>/Compare'
          //   Switch: '<S32>/Switch1'

          if (rtb_Abs1_jo > 90.0) {
            // Signum: '<S36>/Sign1'
            if (rtb_Switch_aa < 0.0) {
              rtb_Switch_aa = -1.0;
            } else if (rtb_Switch_aa > 0.0) {
              rtb_Switch_aa = 1.0;
            } else if (rtb_Switch_aa == 0.0) {
              rtb_Switch_aa = 0.0;
            } else {
              rtb_Switch_aa = (rtNaN);
            }

            rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
            b_nrows = 180;
          } else {
            rtb_Abs1_jo = rtb_Switch_aa;
            b_nrows = 0;
          }

          // Sum: '<S32>/Sum'
          rtb_Sum += static_cast<real_T>(b_nrows);

          // UnitConversion: '<S35>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

          // UnitConversion: '<S50>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Down *= 0.017453292519943295;

          // Trigonometry: '<S51>/Trigonometric Function1'
          rtb_Param4_e = std::sin(rtb_Down);

          // Sum: '<S51>/Sum1' incorporates:
          //   Constant: '<S51>/Constant'
          //   Product: '<S51>/Product1'

          rtb_Param4_e = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_i *
            PreemptableMissionModeSelector_ConstB.sqrt_i * rtb_Param4_e *
            rtb_Param4_e;

          // Product: '<S49>/Product1' incorporates:
          //   Constant: '<S49>/Constant1'
          //   Sqrt: '<S49>/sqrt'

          rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

          // Product: '<S34>/dNorth' incorporates:
          //   Constant: '<S49>/Constant2'
          //   Product: '<S49>/Product3'
          //   Trigonometry: '<S49>/Trigonometric Function1'

          rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
            PreemptableMissionModeSelector_ConstB.Sum1_fv / rtb_Param4_e);

          // Switch: '<S37>/Switch' incorporates:
          //   Abs: '<S37>/Abs'
          //   Bias: '<S37>/Bias'
          //   Bias: '<S37>/Bias1'
          //   Constant: '<S37>/Constant2'
          //   Constant: '<S41>/Constant'
          //   Math: '<S37>/Math Function1'
          //   RelationalOperator: '<S41>/Compare'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Product: '<S34>/dEast' incorporates:
          //   Constant: '<S49>/Constant3'
          //   Product: '<S49>/Product4'
          //   Trigonometry: '<S49>/Trigonometric Function'
          //   Trigonometry: '<S49>/Trigonometric Function2'
          //   UnitConversion: '<S35>/Unit Conversion'

          rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos(rtb_Down))
            * (0.017453292519943295 * rtb_Sum);

          // Sum: '<S34>/Sum2' incorporates:
          //   Product: '<S34>/x*cos'
          //   Product: '<S34>/y*sin'

          rtb_Down = rtb_Abs1_jo * 0.0 + rtb_Param4_e;

          // Sum: '<S34>/Sum3' incorporates:
          //   Product: '<S34>/x*sin'
          //   Product: '<S34>/y*cos'

          rtb_Switch_aa = rtb_Abs1_jo - rtb_Param4_e * 0.0;

          // Sum: '<S31>/Sum' incorporates:
          //   DataStoreRead: '<S3>/AltitudeGCS'
          //   Gain: '<S3>/inverse'

          rtb_Sum = rtu_Location->Alt + -AltitudeGCS;

          // SignalConversion generated from: '<S3>/Orbit Follower' incorporates:
          //   UnaryMinus: '<S31>/Ze2height'

          rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Down;
          rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Switch_aa;
          rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = -rtb_Sum;

          // DataTypeConversion: '<S3>/Param1'
          rtb_Param1_f = static_cast<real_T>(rtu_Parameters->Param1);

          // DataTypeConversion: '<S3>/Param2'
          rtb_Param2_a = static_cast<real_T>(rtu_Parameters->Param2);
          PreemptableMissionModeSelector_OrbitFollower(rtu_Pose,
            rtb_TmpSignalConversionAtOrbitFollowerInport2, rtb_Param1_f,
            rtb_Param2_a, 1.0, &localB->OrbitFollower_b,
            &localDW->OrbitFollower_b);

          // BusCreator: '<S3>/GuidanceCMDBusCreator' incorporates:
          //   Constant: '<S3>/Constant'
          //   DataTypeConversion: '<S3>/Param3'
          //   Gain: '<S3>/Down2Height'

          rty_GuidanceCmds->Height = -localB->OrbitFollower_b.OrbitFollower_o1[2];
          rty_GuidanceCmds->AirSpeed = static_cast<real_T>
            (rtu_Parameters->Param4);
          rty_GuidanceCmds->HeadingAngle =
            localB->OrbitFollower_b.OrbitFollower_o2;

          // Reshape: '<S3>/Reshape' incorporates:
          //   Bias: '<S3>/ClockwiseRotation'
          //   Constant: '<S3>/InitialFlightPathAngle'
          //   Constant: '<S3>/InitialRollAngle'
          //   Constant: '<S3>/InitialRollAngleRate'
          //   DataTypeConversion: '<S3>/Param3'
          //   Product: '<S3>/EastDis'
          //   Product: '<S3>/NorthDis'
          //   Sum: '<S3>/SumInitEast'
          //   Sum: '<S3>/SumInitNorth'
          //   Trigonometry: '<S3>/Cos'
          //   Trigonometry: '<S3>/Sin'
          //   UnaryMinus: '<S31>/Ze2height'

          rty_InitialState[0] = std::cos(rtb_Down_c) * rtb_Param1_f + rtb_Down;
          rty_InitialState[1] = rtb_Param1_f * std::sin(rtb_Down_c) +
            rtb_Switch_aa;
          rty_InitialState[2] = rtb_Sum;
          rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
          rty_InitialState[4] = rtb_Down_c + 1.5707963267948966;
          rty_InitialState[5] = 0.0;
          rty_InitialState[6] = 0.0;
          rty_InitialState[7] = 0.0;

          // SignalConversion generated from: '<S3>/Orbit Follower'
          *rty_thisTaskStatus = localB->OrbitFollower_b.OrbitFollower_o6;
        }
        break;

       case PreemptableMissionModeSelector_IN_ProtectionLine:
        // Abs: '<S4>/Abs' incorporates:
        //   DataTypeConversion: '<S4>/Param4'
        //   DataTypeConversion: '<S4>/Param5'
        //   Gain: '<S4>/HalfDiff'
        //   Sum: '<S4>/Minus'

        rtb_Down_c = std::abs((static_cast<real_T>(rtu_Parameters->Param4) -
          static_cast<real_T>(rtu_Parameters->Param5)) * 0.5);

        // Switch: '<S70>/Switch' incorporates:
        //   Abs: '<S70>/Abs'
        //   Bias: '<S70>/Bias'
        //   Bias: '<S70>/Bias1'
        //   Constant: '<S70>/Constant2'
        //   Constant: '<S71>/Constant'
        //   DataStoreRead: '<S4>/LatitudeGCS'
        //   Math: '<S70>/Math Function1'
        //   RelationalOperator: '<S71>/Compare'

        if (std::abs(LatitudeGCS) > 180.0) {
          rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
          rtb_Down = LatitudeGCS;
        }

        // Abs: '<S67>/Abs1'
        rtb_Switch_aa = std::abs(rtb_Down);

        // Switch: '<S67>/Switch' incorporates:
        //   Bias: '<S67>/Bias'
        //   Bias: '<S67>/Bias1'
        //   Constant: '<S58>/Constant'
        //   Constant: '<S58>/Constant1'
        //   Constant: '<S69>/Constant'
        //   Gain: '<S67>/Gain'
        //   Product: '<S67>/Divide1'
        //   RelationalOperator: '<S69>/Compare'
        //   Switch: '<S58>/Switch1'

        if (rtb_Switch_aa > 90.0) {
          // Signum: '<S67>/Sign1'
          if (rtb_Down < 0.0) {
            rtb_Down = -1.0;
          } else if (rtb_Down > 0.0) {
            rtb_Down = 1.0;
          } else if (rtb_Down == 0.0) {
            rtb_Down = 0.0;
          } else {
            rtb_Down = (rtNaN);
          }

          rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
          b_nrows = 180;
        } else {
          b_nrows = 0;
        }

        // Sum: '<S58>/Sum' incorporates:
        //   DataStoreRead: '<S4>/LongitudeGCS'

        rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

        // Sum: '<S55>/Sum1'
        rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

        // Switch: '<S68>/Switch' incorporates:
        //   Abs: '<S68>/Abs'
        //   Bias: '<S68>/Bias'
        //   Bias: '<S68>/Bias1'
        //   Constant: '<S68>/Constant2'
        //   Constant: '<S72>/Constant'
        //   Math: '<S68>/Math Function1'
        //   RelationalOperator: '<S72>/Compare'

        if (std::abs(rtb_Sum) > 180.0) {
          rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
        }

        // Sum: '<S55>/Sum1'
        rtb_Sum = rtu_Location->Lon - rtb_Sum;

        // Switch: '<S64>/Switch' incorporates:
        //   Abs: '<S64>/Abs'
        //   Bias: '<S64>/Bias'
        //   Bias: '<S64>/Bias1'
        //   Constant: '<S64>/Constant2'
        //   Constant: '<S65>/Constant'
        //   Math: '<S64>/Math Function1'
        //   RelationalOperator: '<S65>/Compare'

        if (std::abs(rtb_Switch_aa) > 180.0) {
          rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
        }

        // Abs: '<S61>/Abs1'
        rtb_Abs1_jo = std::abs(rtb_Switch_aa);

        // Switch: '<S61>/Switch' incorporates:
        //   Bias: '<S61>/Bias'
        //   Bias: '<S61>/Bias1'
        //   Constant: '<S57>/Constant'
        //   Constant: '<S57>/Constant1'
        //   Constant: '<S63>/Constant'
        //   Gain: '<S61>/Gain'
        //   Product: '<S61>/Divide1'
        //   RelationalOperator: '<S63>/Compare'
        //   Switch: '<S57>/Switch1'

        if (rtb_Abs1_jo > 90.0) {
          // Signum: '<S61>/Sign1'
          if (rtb_Switch_aa < 0.0) {
            rtb_Switch_aa = -1.0;
          } else if (rtb_Switch_aa > 0.0) {
            rtb_Switch_aa = 1.0;
          } else if (rtb_Switch_aa == 0.0) {
            rtb_Switch_aa = 0.0;
          } else {
            rtb_Switch_aa = (rtNaN);
          }

          rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
          b_nrows = 180;
        } else {
          rtb_Abs1_jo = rtb_Switch_aa;
          b_nrows = 0;
        }

        // Sum: '<S57>/Sum'
        rtb_Sum += static_cast<real_T>(b_nrows);

        // UnitConversion: '<S60>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

        // UnitConversion: '<S75>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Down *= 0.017453292519943295;

        // Trigonometry: '<S76>/Trigonometric Function1'
        rtb_Param4_e = std::sin(rtb_Down);

        // Sum: '<S76>/Sum1' incorporates:
        //   Constant: '<S76>/Constant'
        //   Product: '<S76>/Product1'

        rtb_Param4_e = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_d *
          PreemptableMissionModeSelector_ConstB.sqrt_d * rtb_Param4_e *
          rtb_Param4_e;

        // Product: '<S74>/Product1' incorporates:
        //   Constant: '<S74>/Constant1'
        //   Sqrt: '<S74>/sqrt'

        rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

        // Product: '<S59>/dNorth' incorporates:
        //   Constant: '<S74>/Constant2'
        //   Product: '<S74>/Product3'
        //   Trigonometry: '<S74>/Trigonometric Function1'

        rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
          PreemptableMissionModeSelector_ConstB.Sum1_k / rtb_Param4_e);

        // Switch: '<S62>/Switch' incorporates:
        //   Abs: '<S62>/Abs'
        //   Bias: '<S62>/Bias'
        //   Bias: '<S62>/Bias1'
        //   Constant: '<S62>/Constant2'
        //   Constant: '<S66>/Constant'
        //   Math: '<S62>/Math Function1'
        //   RelationalOperator: '<S66>/Compare'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        if (std::abs(rtb_Sum) > 180.0) {
          rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
        }

        // Product: '<S59>/dEast' incorporates:
        //   Constant: '<S74>/Constant3'
        //   Product: '<S74>/Product4'
        //   Trigonometry: '<S74>/Trigonometric Function'
        //   Trigonometry: '<S74>/Trigonometric Function2'
        //   UnitConversion: '<S60>/Unit Conversion'

        rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos(rtb_Down))
          * (0.017453292519943295 * rtb_Sum);

        // Sum: '<S55>/Sum' incorporates:
        //   DataStoreRead: '<S4>/AltitudeGCS'
        //   Gain: '<S4>/inverse'

        rtb_Gain1 = rtu_Location->Alt + -AltitudeGCS;

        // Gain: '<S54>/Gain1'
        rtb_Switch_e = 0.017453292519943295 * rtu_Location->degHDG;

        // Outputs for Triggered SubSystem: '<S4>/WayPointGenerator' incorporates:
        //   TriggerPort: '<S56>/Trigger'

        zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                           &localZCE->WayPointGenerator_Trig_ZCE_p,
                           (localDW->MemoryTriggerWP_PreviousInput_i));
        if (zcEvent != NO_ZCEVENT) {
          // DataTypeConversion: '<S56>/Cast To Double'
          rtb_Switch = static_cast<real_T>(*rtu_FormationIDX);

          // Abs: '<S56>/Abs'
          rtb_Abs = static_cast<uint32_T>(std::abs(rtb_Switch));

          // Signum: '<S56>/Sign'
          if (rtb_Switch < 0.0) {
            rtb_Switch = -1.0;
          } else if (rtb_Switch > 0.0) {
            rtb_Switch = 1.0;
          } else {
            rtb_Switch = 0.0;
          }

          // Gain: '<S56>/HalfRotAng' incorporates:
          //   DataTypeConversion: '<S4>/Param2'
          //   Gain: '<S79>/Gain1'
          //   Product: '<S56>/ProductFlipRotAng'

          rtb_Switch_p = 0.017453292519943295 * static_cast<real_T>
            (rtu_Parameters->Param2) * rtb_Switch * 0.5;

          // MATLAB Function: '<S56>/WayPointGenerator' incorporates:
          //   DataTypeConversion: '<S4>/Param3'

          PreemptableMissionModeSelector_uavDubinsConnection_uavDubinsConnection
            (&connectionObj);
          LUp[0] = 0.0;
          rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
          LUp[1] = rtb_Switch_aa;
          LUp[2] = 0.0;
          LUp[3] = 1.5707963267948966;
          LDp[0] = 0.0;
          rtb_Sum = -static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
          LDp[1] = rtb_Sum;
          LDp[2] = 0.0;
          LDp[3] = 1.5707963267948966;
          PreemptableMissionModeSelector_uavDubinsConnection_connect
            (&connectionObj, LUp, LDp, localB->pathSegObj.data,
             &localB->pathSegObj.size, a__1_data, &b_nrows, localB);
          PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate
            (localB->pathSegObj.data[0].StartPose, localB->pathSegObj.data[0].
             GoalPose, localB->pathSegObj.data[0].FlightPathAngle,
             localB->pathSegObj.data[0].AirSpeed, localB->pathSegObj.data[0].
             MinTurningRadius, localB->pathSegObj.data[0].HelixRadius,
             localB->pathSegObj.data[0].MotionTypes, localB->pathSegObj.data[0].
             MotionLengths, localB->pathSegObj.data[0].Length,
             localB->pathSegObj.data[0].Length / 2.0, midpose_data, midpose_size);
          rtb_startPose_f[0] = 0.0;
          rtb_Down = (localB->pathSegObj.data[0].Length + static_cast<real_T>
                      (rtu_Parameters->Param3)) / 3.0 - localB->pathSegObj.data
            [0].Length / 2.0;
          rtb_startPose_f[1] = rtb_Switch_aa - rtb_Down;
          rtb_startPose_f[2] = 0.0;
          rtb_startPose_f[3] = 1.5707963267948966;
          ende[0] = 0.0;
          ende[1] = rtb_Down + rtb_Sum;
          ende[2] = 0.0;
          ende[3] = 1.5707963267948966;
          rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0] *
            initWayPoint->size[1]);

          // MATLAB Function: '<S56>/WayPointGenerator'
          initWayPoint->size[0] = 1;
          initWayPoint->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(initWayPoint,
            rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S56>/WayPointGenerator'
          initWayPoint->data[0] = 0.0;
          initWayPoint->data[1] = 0.0;
          initWayPoint->data[2] = 0.0;
          switch (static_cast<int32_T>(rtb_Abs)) {
           case 0:
            PreemptableMissionModeSelector_genSegWP(&connectionObj,
              rtb_startPose_f, LUp, 100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0]
              * initWayPoint->size[1]);
            initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
              1);
            initWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (initWayPoint, rtb_ClockwiseRotation_n);
            ibmat = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                b_nrows)] = 0.0;
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (initWayPoint->size[0] * b_nrows)) + 1)] = segWayPoints->
                  data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
              }
            }
            break;

           case 1:
            rtb_startPose_f[0] = midpose_data[0];
            rtb_startPose_f[1] = midpose_data[midpose_size[0]];
            rtb_startPose_f[2] = midpose_data[static_cast<int32_T>(midpose_size
              [0] << 1)];
            rtb_startPose_f[3] = midpose_data[static_cast<int32_T>(midpose_size
              [0] * 3)];
            PreemptableMissionModeSelector_genSegWP(&connectionObj,
              &midpose_data[0], LDp, 100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0]
              * initWayPoint->size[1]);
            initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
              1);
            initWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (initWayPoint, rtb_ClockwiseRotation_n);
            ibmat = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                b_nrows)] = 0.0;
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (initWayPoint->size[0] * b_nrows)) + 1)] = segWayPoints->
                  data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
              }
            }
            break;

           case 2:
            rtb_startPose_f[0] = 0.0;
            rtb_startPose_f[1] = ende[1];
            rtb_startPose_f[2] = 0.0;
            rtb_startPose_f[3] = 1.5707963267948966;
            PreemptableMissionModeSelector_genSegWP(&connectionObj, ende, LUp,
              100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0]
              * initWayPoint->size[1]);
            initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
              1);
            initWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (initWayPoint, rtb_ClockwiseRotation_n);
            ibmat = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                b_nrows)] = 0.0;
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (initWayPoint->size[0] * b_nrows)) + 1)] = segWayPoints->
                  data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
              }
            }
            break;

           default:
            rtb_startPose_f[0] = 0.0;
            rtb_startPose_f[1] = 0.0;
            rtb_startPose_f[2] = 0.0;
            rtb_startPose_f[3] = 0.0;
            break;
          }

          PreemptableMissionModeSelector_genSegWP(&connectionObj, LUp, LDp,
            100.0, segWayPoints, localB);
          rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0] *
            dummyWayPoint->size[1]);

          // MATLAB Function: '<S56>/WayPointGenerator'
          dummyWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
            1);
          dummyWayPoint->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
            (dummyWayPoint, rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S56>/WayPointGenerator'
          ibmat = segWayPoints->size[0];
          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            dummyWayPoint->data[static_cast<int32_T>(dummyWayPoint->size[0] *
              b_nrows)] = 0.0;
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
              dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                (rtb_ClockwiseRotation_n + static_cast<int32_T>
                 (dummyWayPoint->size[0] * b_nrows)) + 1)] = segWayPoints->data[
                static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
            }
          }

          PreemptableMissionModeSelector_genSegWP(&connectionObj, LDp, LUp,
            100.0, segWayPoints, localB);
          rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint_0->size[0]
            * dummyWayPoint_0->size[1]);

          // MATLAB Function: '<S56>/WayPointGenerator'
          dummyWayPoint_0->size[0] = static_cast<int32_T>(dummyWayPoint->size[0]
            + segWayPoints->size[0]);
          dummyWayPoint_0->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
            (dummyWayPoint_0, rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S56>/WayPointGenerator'
          ibmat = dummyWayPoint->size[0];
          loop_ub = segWayPoints->size[0];
          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
              dummyWayPoint_0->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
            }

            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n++) {
              dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                segWayPoints->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
            }
          }

          rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0] *
            dummyWayPoint->size[1]);

          // MATLAB Function: '<S56>/WayPointGenerator'
          dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
          dummyWayPoint->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
            (dummyWayPoint, rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S56>/WayPointGenerator'
          ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
          for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1); b_nrows
               ++) {
            dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
          }

          nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
          nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
          for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
               rtb_ClockwiseRotation_n = static_cast<int32_T>
               (rtb_ClockwiseRotation_n + 1)) {
            dummyWayPoint->data[rtb_ClockwiseRotation_n] = dummyWayPoint->data[
              static_cast<int32_T>(rtb_ClockwiseRotation_n + 1)];
          }

          for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
               rtb_ClockwiseRotation_n = static_cast<int32_T>
               (rtb_ClockwiseRotation_n + 1)) {
            dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
              dummyWayPoint->size[0])] = dummyWayPoint->data[static_cast<int32_T>
              (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                dummyWayPoint->size[0]) + 1)];
          }

          for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
               rtb_ClockwiseRotation_n = static_cast<int32_T>
               (rtb_ClockwiseRotation_n + 1)) {
            dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
              static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
              dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
              (rtb_ClockwiseRotation_n + static_cast<int32_T>
               (dummyWayPoint->size[0] << 1)) + 1)];
          }

          if (1 > nrows) {
            nrowx = -1;
            b_nrows = -1;
          } else {
            b_nrows = nrowx;
          }

          ibmat = static_cast<int32_T>(b_nrows + 1);
          rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint_0->size[0]
            * dummyWayPoint_0->size[1]);

          // MATLAB Function: '<S56>/WayPointGenerator'
          dummyWayPoint_0->size[0] = static_cast<int32_T>(nrowx + 1);
          dummyWayPoint_0->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
            (dummyWayPoint_0, rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S56>/WayPointGenerator'
          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
              dummyWayPoint_0->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
            }
          }

          PreemptableMissionModeSelector_repmat(dummyWayPoint_0, std::ceil
            (10240.0 / static_cast<real_T>(static_cast<int32_T>(nrowx + 1))),
            dummyWayPoint);
          if (2 > initWayPoint->size[0]) {
            nrowx = -1;
            nrows = -1;
          } else {
            nrowx = 0;
            nrows = static_cast<int32_T>(initWayPoint->size[0] - 1);
          }

          // Gain: '<S56>/RevFlip'
          b_nrows = static_cast<int32_T>(-static_cast<int32_T>(rtb_Switch));

          // Product: '<S56>/ProductFlipStartPose'
          LUp[0] = rtb_startPose_f[0] * static_cast<real_T>(b_nrows);
          LUp[1] = rtb_startPose_f[1];
          LUp[2] = rtb_startPose_f[2];

          // Bias: '<S56>/Bias' incorporates:
          //   Product: '<S56>/ProductFlipStartPose'
          //   Sum: '<S56>/Sum'

          localB->Bias_g = ((rtb_Switch_e + rtb_Switch_p) + rtb_startPose_f[3])
            + -1.5707963267948966;

          // SignalConversion generated from: '<S56>/RotateATRunWayHdg' incorporates:
          //   Constant: '<S56>/Zero'

          rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[0] = rtb_Switch_p;
          rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[1] = 0.0;
          rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[2] = 0.0;
          PreemptableMissionModeSelector_RotateATMissionHdg
            (rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c,
             &localB->RotateATRunWayHdg);

          // Product: '<S56>/ProductFlipXbias' incorporates:
          //   DataTypeConversion: '<S4>/Param1'
          //   Gain: '<S56>/HalfSepDis'

          rtb_Switch *= 0.5 * static_cast<real_T>(rtu_Parameters->Param1);

          // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
          //   Constant: '<S56>/Zeros'

          rtb_MatrixConcatenate[0] = static_cast<int8_T>(b_nrows);
          rtb_MatrixConcatenate[1] = 0;
          rtb_MatrixConcatenate[2] = 0;

          // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
          //   Constant: '<S56>/One'
          //   Constant: '<S56>/Zeros'

          rtb_MatrixConcatenate[3] = 0;
          rtb_MatrixConcatenate[4] = 1;
          rtb_MatrixConcatenate[5] = 0;

          // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
          //   Constant: '<S56>/One'
          //   Constant: '<S56>/Zeros'

          rtb_MatrixConcatenate[6] = 0;
          rtb_MatrixConcatenate[7] = 0;
          rtb_MatrixConcatenate[8] = 1;

          // MATLAB Function: '<S56>/WayPointGenerator'
          ibmat = static_cast<int32_T>(nrows - nrowx);
          rtb_ClockwiseRotation_n = static_cast<int32_T>(segWayPoints->size[0] *
            segWayPoints->size[1]);

          // MATLAB Function: '<S56>/WayPointGenerator'
          segWayPoints->size[0] = static_cast<int32_T>(ibmat +
            dummyWayPoint->size[0]);
          segWayPoints->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(segWayPoints,
            rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S56>/WayPointGenerator'
          loop_ub = dummyWayPoint->size[0];
          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
              segWayPoints->data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(segWayPoints->size[0] * b_nrows))] =
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(nrowx + rtb_ClockwiseRotation_n) +
                static_cast<int32_T>(initWayPoint->size[0] * b_nrows)) + 1)];
            }

            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n++) {
              segWayPoints->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(rtb_ClockwiseRotation_n + nrows) - nrowx) +
                static_cast<int32_T>(segWayPoints->size[0] * b_nrows))] =
                dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
            }
          }

          // Product: '<S56>/ProductFlipRunWay' incorporates:
          //   Concatenate: '<S56>/Matrix Concatenate'
          //   MATLAB Function: '<S56>/WayPointGenerator'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                 rtb_ClockwiseRotation_n++) {
              ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(10240 * b_nrows));
              localB->RotateIndivWayPoint[ibmat] = 0.0;
              localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                (rtb_MatrixConcatenate[static_cast<int32_T>(3 * b_nrows)]) *
                segWayPoints->data[rtb_ClockwiseRotation_n];
              localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                (rtb_MatrixConcatenate[static_cast<int32_T>(static_cast<int32_T>
                  (3 * b_nrows) + 1)]) * segWayPoints->data[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + segWayPoints->size[0])];
              localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                (rtb_MatrixConcatenate[static_cast<int32_T>(static_cast<int32_T>
                  (3 * b_nrows) + 2)]) * segWayPoints->data[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + static_cast<int32_T>
                 (segWayPoints->size[0] << 1))];
            }
          }

          // Reshape: '<S56>/Reshape' incorporates:
          //   Constant: '<S56>/Zero'

          rtb_Reshape_i[0] = rtb_Switch;
          rtb_Reshape_i[1] = 0.0;
          rtb_Reshape_i[2] = 0.0;

          // Reshape: '<S56>/ReshapeRowVec' incorporates:
          //   Product: '<S59>/x*cos'
          //   Product: '<S59>/x*sin'
          //   Product: '<S59>/y*cos'
          //   Product: '<S59>/y*sin'
          //   Reshape: '<S56>/ReshapeRowVecStartpose'
          //   Sum: '<S59>/Sum2'
          //   Sum: '<S59>/Sum3'
          //   UnaryMinus: '<S55>/Ze2height'

          rtb_ReshapeRowVec[0] = rtb_Abs1_jo * 0.0 + rtb_Param4_e;
          rtb_ReshapeRowVec[1] = rtb_Abs1_jo - rtb_Param4_e * 0.0;
          rtb_ReshapeRowVec[2] = -rtb_Gain1;

          // SignalConversion generated from: '<S56>/RotateATMissionHdg' incorporates:
          //   Constant: '<S56>/Zero'

          rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[0] =
            rtb_Switch_e;
          rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[1] = 0.0;
          rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[2] = 0.0;
          PreemptableMissionModeSelector_RotateATMissionHdg
            (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd,
             &localB->RotateATMissionHdg);

          // Product: '<S56>/RotateRunway' incorporates:
          //   MATLABSystem: '<S56>/RotateATRunWayHdg'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                 rtb_ClockwiseRotation_n++) {
              ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(10240 * b_nrows));
              localB->WayPoint[ibmat] = 0.0;
              localB->WayPoint[ibmat] +=
                localB->RotateATRunWayHdg.RotateATMissionHdg[static_cast<int32_T>
                (3 * b_nrows)] * localB->
                RotateIndivWayPoint[rtb_ClockwiseRotation_n];
              localB->WayPoint[ibmat] +=
                localB->RotateATRunWayHdg.RotateATMissionHdg[static_cast<int32_T>
                (static_cast<int32_T>(3 * b_nrows) + 1)] *
                localB->RotateIndivWayPoint[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + 10240)];
              localB->WayPoint[ibmat] +=
                localB->RotateATRunWayHdg.RotateATMissionHdg[static_cast<int32_T>
                (static_cast<int32_T>(3 * b_nrows) + 2)] *
                localB->RotateIndivWayPoint[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + 20480)];
            }
          }

          // MATLAB Function: '<S56>/minus'
          PreemptableMissionModeSelector_minus(localB->WayPoint, rtb_Reshape_i,
            localB->RotateIndivWayPoint);

          // Product: '<S56>/RotateIndivWayPoint' incorporates:
          //   MATLABSystem: '<S56>/RotateATMissionHdg'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                 rtb_ClockwiseRotation_n++) {
              ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(10240 * b_nrows));
              localB->WayPoint[ibmat] = 0.0;
              localB->WayPoint[ibmat] +=
                localB->RotateATMissionHdg.RotateATMissionHdg
                [static_cast<int32_T>(3 * b_nrows)] *
                localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
              localB->WayPoint[ibmat] +=
                localB->RotateATMissionHdg.RotateATMissionHdg
                [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)] *
                localB->RotateIndivWayPoint[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + 10240)];
              localB->WayPoint[ibmat] +=
                localB->RotateATMissionHdg.RotateATMissionHdg
                [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
                localB->RotateIndivWayPoint[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + 20480)];
            }
          }

          // Product: '<S56>/RotateRunwayStartpose' incorporates:
          //   MATLABSystem: '<S56>/RotateATRunWayHdg'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            rtb_Reshape_i[b_nrows] =
              localB->RotateATRunWayHdg.RotateATMissionHdg[static_cast<int32_T>(
              static_cast<int32_T>(3 * b_nrows) + 2)] * LUp[2] +
              (localB->RotateATRunWayHdg.RotateATMissionHdg[static_cast<int32_T>
               (static_cast<int32_T>(3 * b_nrows) + 1)] * LUp[1] +
               localB->RotateATRunWayHdg.RotateATMissionHdg[static_cast<int32_T>
               (3 * b_nrows)] * LUp[0]);
          }

          // Sum: '<S56>/BiasStartPose'
          rtb_Switch_aa = rtb_Reshape_i[0] - rtb_Switch;
          rtb_Sum = rtb_Reshape_i[1];
          rtb_Down = rtb_Reshape_i[2];

          // Product: '<S56>/RotateIndivWayPointStartpose' incorporates:
          //   MATLABSystem: '<S56>/RotateATMissionHdg'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            rtb_Reshape_i[b_nrows] =
              localB->RotateATMissionHdg.RotateATMissionHdg[static_cast<int32_T>
              (static_cast<int32_T>(3 * b_nrows) + 2)] * rtb_Down +
              (localB->RotateATMissionHdg.RotateATMissionHdg[static_cast<int32_T>
               (static_cast<int32_T>(3 * b_nrows) + 1)] * rtb_Sum +
               localB->RotateATMissionHdg.RotateATMissionHdg[static_cast<int32_T>
               (3 * b_nrows)] * rtb_Switch_aa);
          }

          // MATLAB Function: '<S56>/biasNED' incorporates:
          //   Reshape: '<S56>/ReshapeRowVec'

          PreemptableMissionModeSelector_biasNED(rtb_ReshapeRowVec,
            localB->WayPoint, localB->nedWayPoint_j, &localB->sf_biasNED);

          // MATLAB Function: '<S56>/biasNEDstartpose'
          PreemptableMissionModeSelector_biasNEDstartpose(rtb_ReshapeRowVec,
            rtb_Reshape_i, localB->nedWayPoint_l);
        }

        // End of Outputs for SubSystem: '<S4>/WayPointGenerator'
        PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
          localB->nedWayPoint_j, 200.0, &localB->WaypointFollower,
          &localDW->WaypointFollower);

        // DataTypeConversion: '<S4>/Cast To Double' incorporates:
        //   Constant: '<S4>/LookAheadDis'
        //   MATLAB Function: '<S56>/WayPointGenerator'
        //   Memory: '<S4>/MemoryTriggerWP'

        *rty_thisTaskStatus = static_cast<real_T>
          (localB->WaypointFollower.WaypointFollower_o5);

        // Gain: '<S4>/HalfSum' incorporates:
        //   DataTypeConversion: '<S4>/Param4'
        //   DataTypeConversion: '<S4>/Param5'
        //   Sum: '<S4>/SumSpd'

        rtb_Param4_e = (static_cast<real_T>(rtu_Parameters->Param4) +
                        static_cast<real_T>(rtu_Parameters->Param5)) * 0.5;

        // BusCreator: '<S4>/GuidanceCMDBusCreator' incorporates:
        //   Gain: '<S4>/Down2Height'

        rty_GuidanceCmds->Height = -localB->
          WaypointFollower.WaypointFollower_o1[2];
        rty_GuidanceCmds->AirSpeed = rtb_Param4_e;
        rty_GuidanceCmds->HeadingAngle =
          localB->WaypointFollower.WaypointFollower_o2;

        // Product: '<S4>/ProductEast' incorporates:
        //   Trigonometry: '<S4>/Sin'

        rty_VelShift[1] = rtb_Down_c * std::sin(rtb_Switch_e);

        // Product: '<S4>/ProductNorth' incorporates:
        //   Trigonometry: '<S4>/Cos'

        rty_VelShift[0] = std::cos(rtb_Switch_e) * rtb_Down_c;

        // Reshape: '<S4>/Reshape' incorporates:
        //   Constant: '<S4>/InitialFlightPathAngle'
        //   Constant: '<S4>/InitialRollAngle'
        //   Constant: '<S4>/InitialRollAngleRate'
        //   Gain: '<S4>/Down2Up'

        rty_InitialState[0] = localB->nedWayPoint_l[0];
        rty_InitialState[1] = localB->nedWayPoint_l[1];
        rty_InitialState[2] = -localB->nedWayPoint_l[2];
        rty_InitialState[3] = rtb_Param4_e;
        rty_InitialState[4] = localB->Bias_g;
        rty_InitialState[5] = 0.0;
        rty_InitialState[6] = 0.0;
        rty_InitialState[7] = 0.0;

        // Sum: '<S4>/Sum' incorporates:
        //   Memory: '<S4>/MemoryStopTrigger1'
        //   Memory: '<S4>/MemoryTriggerWP'

        *rty_ResetTrigger = localDW->MemoryStopTrigger1_PreviousInput_o +
          localDW->MemoryTriggerWP_PreviousInput_i;

        // Update for Memory: '<S4>/MemoryTriggerWP' incorporates:
        //   Constant: '<S4>/TirggerWayPointGen'

        localDW->MemoryTriggerWP_PreviousInput_i = 1.0;

        // Update for Memory: '<S4>/MemoryStopTrigger1' incorporates:
        //   Memory: '<S4>/MemoryStopTrigger2'

        localDW->MemoryStopTrigger1_PreviousInput_o =
          localDW->MemoryStopTrigger2_PreviousInput_n;

        // Update for Memory: '<S4>/MemoryStopTrigger2' incorporates:
        //   Constant: '<S4>/StopTrigger'

        localDW->MemoryStopTrigger2_PreviousInput_n = -1.0;
        break;

       case PreemptableMissionModeSelector_IN_RunWayNav:
        // Switch: '<S100>/Switch' incorporates:
        //   Abs: '<S100>/Abs'
        //   Bias: '<S100>/Bias'
        //   Bias: '<S100>/Bias1'
        //   Constant: '<S100>/Constant2'
        //   Constant: '<S101>/Constant'
        //   DataStoreRead: '<S5>/LatitudeGCS'
        //   Math: '<S100>/Math Function1'
        //   RelationalOperator: '<S101>/Compare'

        if (std::abs(LatitudeGCS) > 180.0) {
          rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
          rtb_Down = LatitudeGCS;
        }

        // Abs: '<S97>/Abs1'
        rtb_Switch_aa = std::abs(rtb_Down);

        // Switch: '<S97>/Switch' incorporates:
        //   Bias: '<S97>/Bias'
        //   Bias: '<S97>/Bias1'
        //   Constant: '<S88>/Constant'
        //   Constant: '<S88>/Constant1'
        //   Constant: '<S99>/Constant'
        //   Gain: '<S97>/Gain'
        //   Product: '<S97>/Divide1'
        //   RelationalOperator: '<S99>/Compare'
        //   Switch: '<S88>/Switch1'

        if (rtb_Switch_aa > 90.0) {
          // Signum: '<S97>/Sign1'
          if (rtb_Down < 0.0) {
            rtb_Down = -1.0;
          } else if (rtb_Down > 0.0) {
            rtb_Down = 1.0;
          } else if (rtb_Down == 0.0) {
            rtb_Down = 0.0;
          } else {
            rtb_Down = (rtNaN);
          }

          rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
          b_nrows = 180;
        } else {
          b_nrows = 0;
        }

        // Sum: '<S88>/Sum' incorporates:
        //   DataStoreRead: '<S5>/LongitudeGCS'

        rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

        // Sum: '<S85>/Sum1'
        rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

        // Switch: '<S98>/Switch' incorporates:
        //   Abs: '<S98>/Abs'
        //   Bias: '<S98>/Bias'
        //   Bias: '<S98>/Bias1'
        //   Constant: '<S102>/Constant'
        //   Constant: '<S98>/Constant2'
        //   Math: '<S98>/Math Function1'
        //   RelationalOperator: '<S102>/Compare'

        if (std::abs(rtb_Sum) > 180.0) {
          rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
        }

        // Sum: '<S85>/Sum1'
        rtb_Sum = rtu_Location->Lon - rtb_Sum;

        // Switch: '<S94>/Switch' incorporates:
        //   Abs: '<S94>/Abs'
        //   Bias: '<S94>/Bias'
        //   Bias: '<S94>/Bias1'
        //   Constant: '<S94>/Constant2'
        //   Constant: '<S95>/Constant'
        //   Math: '<S94>/Math Function1'
        //   RelationalOperator: '<S95>/Compare'

        if (std::abs(rtb_Switch_aa) > 180.0) {
          rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
        }

        // Abs: '<S91>/Abs1'
        rtb_Down_c = std::abs(rtb_Switch_aa);

        // Switch: '<S91>/Switch' incorporates:
        //   Bias: '<S91>/Bias'
        //   Bias: '<S91>/Bias1'
        //   Constant: '<S87>/Constant'
        //   Constant: '<S87>/Constant1'
        //   Constant: '<S93>/Constant'
        //   Gain: '<S91>/Gain'
        //   Product: '<S91>/Divide1'
        //   RelationalOperator: '<S93>/Compare'
        //   Switch: '<S87>/Switch1'

        if (rtb_Down_c > 90.0) {
          // Signum: '<S91>/Sign1'
          if (rtb_Switch_aa < 0.0) {
            rtb_Switch_aa = -1.0;
          } else if (rtb_Switch_aa > 0.0) {
            rtb_Switch_aa = 1.0;
          } else if (rtb_Switch_aa == 0.0) {
            rtb_Switch_aa = 0.0;
          } else {
            rtb_Switch_aa = (rtNaN);
          }

          rtb_Down_c = (-(rtb_Down_c + -90.0) + 90.0) * rtb_Switch_aa;
          b_nrows = 180;
        } else {
          rtb_Down_c = rtb_Switch_aa;
          b_nrows = 0;
        }

        // Sum: '<S87>/Sum'
        rtb_Sum += static_cast<real_T>(b_nrows);

        // UnitConversion: '<S90>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_aa = 0.017453292519943295 * rtb_Down_c;

        // UnitConversion: '<S105>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Down *= 0.017453292519943295;

        // Trigonometry: '<S106>/Trigonometric Function1'
        rtb_Abs1_jo = std::sin(rtb_Down);

        // Sum: '<S106>/Sum1' incorporates:
        //   Constant: '<S106>/Constant'
        //   Product: '<S106>/Product1'

        rtb_Abs1_jo = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_j *
          PreemptableMissionModeSelector_ConstB.sqrt_j * rtb_Abs1_jo *
          rtb_Abs1_jo;

        // Product: '<S104>/Product1' incorporates:
        //   Constant: '<S104>/Constant1'
        //   Sqrt: '<S104>/sqrt'

        rtb_Down_c = 6.378137E+6 / std::sqrt(rtb_Abs1_jo);

        // Product: '<S89>/dNorth' incorporates:
        //   Constant: '<S104>/Constant2'
        //   Product: '<S104>/Product3'
        //   Trigonometry: '<S104>/Trigonometric Function1'

        rtb_Abs1_jo = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Down_c *
          PreemptableMissionModeSelector_ConstB.Sum1_f / rtb_Abs1_jo);

        // Switch: '<S92>/Switch' incorporates:
        //   Abs: '<S92>/Abs'
        //   Bias: '<S92>/Bias'
        //   Bias: '<S92>/Bias1'
        //   Constant: '<S92>/Constant2'
        //   Constant: '<S96>/Constant'
        //   Math: '<S92>/Math Function1'
        //   RelationalOperator: '<S96>/Compare'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        if (std::abs(rtb_Sum) > 180.0) {
          rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
        }

        // Product: '<S89>/dEast' incorporates:
        //   Constant: '<S104>/Constant3'
        //   Product: '<S104>/Product4'
        //   Trigonometry: '<S104>/Trigonometric Function'
        //   Trigonometry: '<S104>/Trigonometric Function2'
        //   UnitConversion: '<S90>/Unit Conversion'

        rtb_Down_c = 1.0 / rt_atan2d_snf(1.0, rtb_Down_c * std::cos(rtb_Down)) *
          (0.017453292519943295 * rtb_Sum);

        // Sum: '<S85>/Sum' incorporates:
        //   DataStoreRead: '<S5>/AltitudeGCS'
        //   Gain: '<S5>/inverse'

        rtb_Switch_e = rtu_Location->Alt + -AltitudeGCS;

        // Gain: '<S84>/Gain1'
        rtb_Gain1 = 0.017453292519943295 * rtu_Location->degHDG;

        // Outputs for Triggered SubSystem: '<S5>/WayPointGenerator' incorporates:
        //   TriggerPort: '<S86>/Trigger'

        zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                           &localZCE->WayPointGenerator_Trig_ZCE_e,
                           (localDW->MemoryTriggerWP_PreviousInput_b));
        if (zcEvent != NO_ZCEVENT) {
          // Product: '<S86>/IndivRunwayRotAng' incorporates:
          //   DataTypeConversion: '<S5>/Param2'
          //   DataTypeConversion: '<S5>/Param5'
          //   Gain: '<S109>/Gain1'

          rtb_Switch = 0.017453292519943295 * static_cast<real_T>
            (rtu_Parameters->Param2) * static_cast<real_T>
            (rtu_Parameters->Param5);

          // DataTypeConversion: '<S86>/Cast To Double'
          rtb_Param4_e = static_cast<real_T>(*rtu_FormationIDX);

          // MATLAB Function: '<S86>/WayPointGenerator' incorporates:
          //   DataTypeConversion: '<S5>/Param3'

          PreemptableMissionModeSelector_uavDubinsConnection_uavDubinsConnection
            (&connectionObj);
          LUp[0] = 0.0;
          rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
          LUp[1] = rtb_Switch_aa;
          LUp[2] = 0.0;
          LUp[3] = 1.5707963267948966;
          LDp[0] = 0.0;
          rtb_Sum = -static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
          LDp[1] = rtb_Sum;
          LDp[2] = 0.0;
          LDp[3] = 1.5707963267948966;
          PreemptableMissionModeSelector_uavDubinsConnection_connect
            (&connectionObj, LUp, LDp, localB->pathSegObj.data,
             &localB->pathSegObj.size, a__1_data, &b_nrows, localB);
          PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate
            (localB->pathSegObj.data[0].StartPose, localB->pathSegObj.data[0].
             GoalPose, localB->pathSegObj.data[0].FlightPathAngle,
             localB->pathSegObj.data[0].AirSpeed, localB->pathSegObj.data[0].
             MinTurningRadius, localB->pathSegObj.data[0].HelixRadius,
             localB->pathSegObj.data[0].MotionTypes, localB->pathSegObj.data[0].
             MotionLengths, localB->pathSegObj.data[0].Length,
             localB->pathSegObj.data[0].Length / 2.0, midpose_data, midpose_size);
          rtb_startPose_f[0] = 0.0;
          rtb_Down = (localB->pathSegObj.data[0].Length + static_cast<real_T>
                      (rtu_Parameters->Param3)) / 3.0 - localB->pathSegObj.data
            [0].Length / 2.0;
          rtb_startPose_f[1] = rtb_Switch_aa - rtb_Down;
          rtb_startPose_f[2] = 0.0;
          rtb_startPose_f[3] = 1.5707963267948966;
          ende[0] = 0.0;
          ende[1] = rtb_Down + rtb_Sum;
          ende[2] = 0.0;
          ende[3] = 1.5707963267948966;
          rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0] *
            initWayPoint->size[1]);

          // MATLAB Function: '<S86>/WayPointGenerator'
          initWayPoint->size[0] = 1;
          initWayPoint->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(initWayPoint,
            rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S86>/WayPointGenerator' incorporates:
          //   Constant: '<S86>/Three'
          //   Math: '<S86>/ModRunWayPose'

          initWayPoint->data[0] = 0.0;
          initWayPoint->data[1] = 0.0;
          initWayPoint->data[2] = 0.0;
          switch (static_cast<int32_T>(rt_modd_snf(rtb_Param4_e, 3.0))) {
           case 0:
            PreemptableMissionModeSelector_genSegWP(&connectionObj,
              rtb_startPose_f, LUp, 100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0]
              * initWayPoint->size[1]);
            initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
              1);
            initWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (initWayPoint, rtb_ClockwiseRotation_n);
            ibmat = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                b_nrows)] = 0.0;
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (initWayPoint->size[0] * b_nrows)) + 1)] = segWayPoints->
                  data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
              }
            }
            break;

           case 1:
            rtb_startPose_f[0] = midpose_data[0];
            rtb_startPose_f[1] = midpose_data[midpose_size[0]];
            rtb_startPose_f[2] = midpose_data[static_cast<int32_T>(midpose_size
              [0] << 1)];
            rtb_startPose_f[3] = midpose_data[static_cast<int32_T>(midpose_size
              [0] * 3)];
            PreemptableMissionModeSelector_genSegWP(&connectionObj,
              &midpose_data[0], LDp, 100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0]
              * initWayPoint->size[1]);
            initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
              1);
            initWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (initWayPoint, rtb_ClockwiseRotation_n);
            ibmat = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                b_nrows)] = 0.0;
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (initWayPoint->size[0] * b_nrows)) + 1)] = segWayPoints->
                  data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
              }
            }
            break;

           case 2:
            rtb_startPose_f[0] = 0.0;
            rtb_startPose_f[1] = ende[1];
            rtb_startPose_f[2] = 0.0;
            rtb_startPose_f[3] = 1.5707963267948966;
            PreemptableMissionModeSelector_genSegWP(&connectionObj, ende, LUp,
              100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0]
              * initWayPoint->size[1]);
            initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
              1);
            initWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (initWayPoint, rtb_ClockwiseRotation_n);
            ibmat = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              initWayPoint->data[static_cast<int32_T>(initWayPoint->size[0] *
                b_nrows)] = 0.0;
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (initWayPoint->size[0] * b_nrows)) + 1)] = segWayPoints->
                  data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
              }
            }
            break;

           default:
            rtb_startPose_f[0] = 0.0;
            rtb_startPose_f[1] = 0.0;
            rtb_startPose_f[2] = 0.0;
            rtb_startPose_f[3] = 0.0;
            break;
          }

          PreemptableMissionModeSelector_genSegWP(&connectionObj, LUp, LDp,
            100.0, segWayPoints, localB);
          rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0] *
            dummyWayPoint->size[1]);

          // MATLAB Function: '<S86>/WayPointGenerator'
          dummyWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
            1);
          dummyWayPoint->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
            (dummyWayPoint, rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S86>/WayPointGenerator'
          ibmat = segWayPoints->size[0];
          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            dummyWayPoint->data[static_cast<int32_T>(dummyWayPoint->size[0] *
              b_nrows)] = 0.0;
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
              dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                (rtb_ClockwiseRotation_n + static_cast<int32_T>
                 (dummyWayPoint->size[0] * b_nrows)) + 1)] = segWayPoints->data[
                static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
            }
          }

          PreemptableMissionModeSelector_genSegWP(&connectionObj, LDp, LUp,
            100.0, segWayPoints, localB);
          rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint_0->size[0]
            * dummyWayPoint_0->size[1]);

          // MATLAB Function: '<S86>/WayPointGenerator'
          dummyWayPoint_0->size[0] = static_cast<int32_T>(dummyWayPoint->size[0]
            + segWayPoints->size[0]);
          dummyWayPoint_0->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
            (dummyWayPoint_0, rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S86>/WayPointGenerator'
          ibmat = dummyWayPoint->size[0];
          loop_ub = segWayPoints->size[0];
          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
              dummyWayPoint_0->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
            }

            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n++) {
              dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                segWayPoints->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
            }
          }

          rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0] *
            dummyWayPoint->size[1]);

          // MATLAB Function: '<S86>/WayPointGenerator'
          dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
          dummyWayPoint->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
            (dummyWayPoint, rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S86>/WayPointGenerator'
          ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
          for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1); b_nrows
               ++) {
            dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
          }

          nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
          nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
          for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
               rtb_ClockwiseRotation_n = static_cast<int32_T>
               (rtb_ClockwiseRotation_n + 1)) {
            dummyWayPoint->data[rtb_ClockwiseRotation_n] = dummyWayPoint->data[
              static_cast<int32_T>(rtb_ClockwiseRotation_n + 1)];
          }

          for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
               rtb_ClockwiseRotation_n = static_cast<int32_T>
               (rtb_ClockwiseRotation_n + 1)) {
            dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
              dummyWayPoint->size[0])] = dummyWayPoint->data[static_cast<int32_T>
              (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                dummyWayPoint->size[0]) + 1)];
          }

          for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
               rtb_ClockwiseRotation_n = static_cast<int32_T>
               (rtb_ClockwiseRotation_n + 1)) {
            dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
              static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
              dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
              (rtb_ClockwiseRotation_n + static_cast<int32_T>
               (dummyWayPoint->size[0] << 1)) + 1)];
          }

          if (1 > nrows) {
            nrowx = -1;
            b_nrows = -1;
          } else {
            b_nrows = nrowx;
          }

          ibmat = static_cast<int32_T>(b_nrows + 1);
          rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint_0->size[0]
            * dummyWayPoint_0->size[1]);

          // MATLAB Function: '<S86>/WayPointGenerator'
          dummyWayPoint_0->size[0] = static_cast<int32_T>(nrowx + 1);
          dummyWayPoint_0->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
            (dummyWayPoint_0, rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S86>/WayPointGenerator'
          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
              dummyWayPoint_0->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
            }
          }

          PreemptableMissionModeSelector_repmat(dummyWayPoint_0, std::ceil
            (10240.0 / static_cast<real_T>(static_cast<int32_T>(nrowx + 1))),
            dummyWayPoint);
          if (2 > initWayPoint->size[0]) {
            nrowx = -1;
            nrows = -1;
          } else {
            nrowx = 0;
            nrows = static_cast<int32_T>(initWayPoint->size[0] - 1);
          }

          ibmat = static_cast<int32_T>(nrows - nrowx);
          rtb_ClockwiseRotation_n = static_cast<int32_T>(segWayPoints->size[0] *
            segWayPoints->size[1]);

          // MATLAB Function: '<S86>/WayPointGenerator'
          segWayPoints->size[0] = static_cast<int32_T>(ibmat +
            dummyWayPoint->size[0]);
          segWayPoints->size[1] = 3;
          PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c(segWayPoints,
            rtb_ClockwiseRotation_n);

          // MATLAB Function: '<S86>/WayPointGenerator'
          loop_ub = dummyWayPoint->size[0];
          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
              segWayPoints->data[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(segWayPoints->size[0] * b_nrows))] =
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(nrowx + rtb_ClockwiseRotation_n) +
                static_cast<int32_T>(initWayPoint->size[0] * b_nrows)) + 1)];
            }

            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n++) {
              segWayPoints->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(rtb_ClockwiseRotation_n + nrows) - nrowx) +
                static_cast<int32_T>(segWayPoints->size[0] * b_nrows))] =
                dummyWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                + static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
            }

            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                 rtb_ClockwiseRotation_n++) {
              localB->WayPoint[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(10240 * b_nrows))] = segWayPoints->data[
                static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
            }
          }

          // Bias: '<S86>/Bias' incorporates:
          //   Sum: '<S86>/Sum'

          localB->Bias = ((rtb_Gain1 + rtb_Switch) + rtb_startPose_f[3]) +
            -1.5707963267948966;

          // Gain: '<S86>/InterLayerDis' incorporates:
          //   Constant: '<S86>/Three'
          //   DataTypeConversion: '<S5>/Param5'
          //   Math: '<S86>/ModRunWayLayer'

          rtb_Param4_e = 15.0 * rt_modd_snf(static_cast<real_T>
            (rtu_Parameters->Param5), 3.0);

          // Reshape: '<S86>/Reshape' incorporates:
          //   Constant: '<S86>/Zero'
          //   DataTypeConversion: '<S5>/Param1'

          rtb_Reshape_i[0] = 0.0;
          rtb_Reshape_i[1] = static_cast<real_T>(rtu_Parameters->Param1);
          rtb_Reshape_i[2] = rtb_Param4_e;

          // Reshape: '<S86>/ReshapeRowVec' incorporates:
          //   Product: '<S89>/x*cos'
          //   Product: '<S89>/x*sin'
          //   Product: '<S89>/y*cos'
          //   Product: '<S89>/y*sin'
          //   Reshape: '<S86>/ReshapeRowVecStartpose'
          //   Sum: '<S89>/Sum2'
          //   Sum: '<S89>/Sum3'
          //   UnaryMinus: '<S85>/Ze2height'

          rtb_ReshapeRowVec[0] = rtb_Down_c * 0.0 + rtb_Abs1_jo;
          rtb_ReshapeRowVec[1] = rtb_Down_c - rtb_Abs1_jo * 0.0;
          rtb_ReshapeRowVec[2] = -rtb_Switch_e;

          // SignalConversion generated from: '<S86>/RotateATMissionHdg' incorporates:
          //   Constant: '<S86>/Zero'

          rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[0] = rtb_Gain1;
          rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[1] = 0.0;
          rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[2] = 0.0;
          PreemptableMissionModeSelector_RotateATMissionHdg
            (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx,
             &localB->RotateATMissionHdg_b);

          // SignalConversion generated from: '<S86>/RotateATRunWayHdg' incorporates:
          //   Constant: '<S86>/Zero'

          rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[0] = rtb_Switch;
          rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[1] = 0.0;
          rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[2] = 0.0;
          PreemptableMissionModeSelector_RotateATMissionHdg
            (rtb_TmpSignalConversionAtRotateATRunWayHdgInport1,
             &localB->RotateATRunWayHdg_b);

          // MATLAB Function: '<S86>/minus'
          PreemptableMissionModeSelector_minus(localB->WayPoint, rtb_Reshape_i,
            localB->RotateIndivWayPoint);

          // Product: '<S86>/RotateRunway' incorporates:
          //   MATLABSystem: '<S86>/RotateATRunWayHdg'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                 rtb_ClockwiseRotation_n++) {
              ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(10240 * b_nrows));
              localB->rtb_WayPoint_m[ibmat] = 0.0;
              localB->rtb_WayPoint_m[ibmat] +=
                localB->RotateATRunWayHdg_b.RotateATMissionHdg
                [static_cast<int32_T>(3 * b_nrows)] *
                localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
              localB->rtb_WayPoint_m[ibmat] +=
                localB->RotateATRunWayHdg_b.RotateATMissionHdg
                [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)] *
                localB->RotateIndivWayPoint[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + 10240)];
              localB->rtb_WayPoint_m[ibmat] +=
                localB->RotateATRunWayHdg_b.RotateATMissionHdg
                [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
                localB->RotateIndivWayPoint[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + 20480)];
            }
          }

          // Product: '<S86>/RotateIndivWayPoint' incorporates:
          //   MATLABSystem: '<S86>/RotateATMissionHdg'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                 rtb_ClockwiseRotation_n++) {
              ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                static_cast<int32_T>(10240 * b_nrows));
              localB->WayPoint[ibmat] = 0.0;
              localB->WayPoint[ibmat] +=
                localB->RotateATMissionHdg_b.RotateATMissionHdg
                [static_cast<int32_T>(3 * b_nrows)] * localB->
                rtb_WayPoint_m[rtb_ClockwiseRotation_n];
              localB->WayPoint[ibmat] +=
                localB->RotateATMissionHdg_b.RotateATMissionHdg
                [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)] *
                localB->rtb_WayPoint_m[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + 10240)];
              localB->WayPoint[ibmat] +=
                localB->RotateATMissionHdg_b.RotateATMissionHdg
                [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
                localB->rtb_WayPoint_m[static_cast<int32_T>
                (rtb_ClockwiseRotation_n + 20480)];
            }
          }

          // Sum: '<S86>/BiasStartPose' incorporates:
          //   DataTypeConversion: '<S5>/Param1'

          rtb_Switch_aa = rtb_startPose_f[0];
          rtb_Sum = rtb_startPose_f[1] - static_cast<real_T>
            (rtu_Parameters->Param1);
          rtb_Down_c = rtb_startPose_f[2] - rtb_Param4_e;

          // Product: '<S86>/RotateRunwayStartpose' incorporates:
          //   MATLABSystem: '<S86>/RotateATRunWayHdg'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            rtb_startPose_h[b_nrows] =
              localB->RotateATRunWayHdg_b.RotateATMissionHdg[static_cast<int32_T>
              (static_cast<int32_T>(3 * b_nrows) + 2)] * rtb_Down_c +
              (localB->RotateATRunWayHdg_b.RotateATMissionHdg
               [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)] *
               rtb_Sum + localB->RotateATRunWayHdg_b.RotateATMissionHdg[
               static_cast<int32_T>(3 * b_nrows)] * rtb_Switch_aa);
          }

          // Product: '<S86>/RotateIndivWayPointStartpose' incorporates:
          //   MATLABSystem: '<S86>/RotateATMissionHdg'

          for (b_nrows = 0; b_nrows < 3; b_nrows++) {
            rtb_Reshape_i[b_nrows] =
              localB->RotateATMissionHdg_b.RotateATMissionHdg
              [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
              rtb_startPose_h[2] +
              (localB->RotateATMissionHdg_b.RotateATMissionHdg
               [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)] *
               rtb_startPose_h[1] +
               localB->RotateATMissionHdg_b.RotateATMissionHdg
               [static_cast<int32_T>(3 * b_nrows)] * rtb_startPose_h[0]);
          }

          // MATLAB Function: '<S86>/biasNED' incorporates:
          //   Reshape: '<S86>/ReshapeRowVec'

          PreemptableMissionModeSelector_biasNED(rtb_ReshapeRowVec,
            localB->WayPoint, localB->nedWayPoint_k, &localB->sf_biasNED_f);

          // MATLAB Function: '<S86>/biasNEDstartpose'
          PreemptableMissionModeSelector_biasNEDstartpose(rtb_ReshapeRowVec,
            rtb_Reshape_i, localB->nedWayPoint_f);
        }

        // End of Outputs for SubSystem: '<S5>/WayPointGenerator'
        PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
          localB->nedWayPoint_k, 200.0, &localB->WaypointFollower_b,
          &localDW->WaypointFollower_b);

        // DataTypeConversion: '<S5>/Cast To Double' incorporates:
        //   Constant: '<S5>/LookAheadDis'
        //   MATLAB Function: '<S86>/WayPointGenerator'
        //   Memory: '<S5>/MemoryTriggerWP'

        *rty_thisTaskStatus = static_cast<real_T>
          (localB->WaypointFollower_b.WaypointFollower_o5);

        // BusCreator: '<S5>/GuidanceCMDBusCreator' incorporates:
        //   DataTypeConversion: '<S5>/Param4'
        //   Gain: '<S5>/Down2Height'

        rty_GuidanceCmds->Height =
          -localB->WaypointFollower_b.WaypointFollower_o1[2];
        rty_GuidanceCmds->AirSpeed = static_cast<real_T>(rtu_Parameters->Param4);
        rty_GuidanceCmds->HeadingAngle =
          localB->WaypointFollower_b.WaypointFollower_o2;

        // Reshape: '<S5>/Reshape' incorporates:
        //   Constant: '<S5>/InitialFlightPathAngle'
        //   Constant: '<S5>/InitialRollAngle'
        //   Constant: '<S5>/InitialRollAngleRate'
        //   DataTypeConversion: '<S5>/Param4'
        //   Gain: '<S5>/Down2Up'

        rty_InitialState[0] = localB->nedWayPoint_f[0];
        rty_InitialState[1] = localB->nedWayPoint_f[1];
        rty_InitialState[2] = -localB->nedWayPoint_f[2];
        rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
        rty_InitialState[4] = localB->Bias;
        rty_InitialState[5] = 0.0;
        rty_InitialState[6] = 0.0;
        rty_InitialState[7] = 0.0;

        // Sum: '<S5>/Sum' incorporates:
        //   Memory: '<S5>/MemoryStopTrigger1'
        //   Memory: '<S5>/MemoryTriggerWP'

        *rty_ResetTrigger = localDW->MemoryStopTrigger1_PreviousInput +
          localDW->MemoryTriggerWP_PreviousInput_b;

        // Update for Memory: '<S5>/MemoryTriggerWP' incorporates:
        //   Constant: '<S5>/TirggerWayPointGen'

        localDW->MemoryTriggerWP_PreviousInput_b = 1.0;

        // Update for Memory: '<S5>/MemoryStopTrigger1' incorporates:
        //   Memory: '<S5>/MemoryStopTrigger2'

        localDW->MemoryStopTrigger1_PreviousInput =
          localDW->MemoryStopTrigger2_PreviousInput;

        // Update for Memory: '<S5>/MemoryStopTrigger2' incorporates:
        //   Constant: '<S5>/StopTrigger'

        localDW->MemoryStopTrigger2_PreviousInput = -1.0;
        break;

       case PreemptableMissionModeSelector_IN_WaitToStart:
        if (*rtu_startFlight) {
          sf_internal_predicateOutput = ((*rtu_mode == 1) || (*rtu_mode == 11));
          if (sf_internal_predicateOutput) {
            localDW->is_GuidanceLogic =
              PreemptableMissionModeSelector_IN_OrbitFollower;
            *rty_ResetTrigger = 1.0;
            if (*rtu_mode == 1) {
              localDW->is_OrbitFollower =
                PreemptableMissionModeSelector_IN_CirclingNav;

              // Bias: '<S3>/Bias'
              b_nrows = *rtu_MissionUAV;

              // DataTypeConversion: '<S3>/CastToDouble'
              rtb_ClockwiseRotation_n = *rtu_FormationIDX;

              // Product: '<S3>/Divide' incorporates:
              //   Constant: '<S3>/two_pi'

              rtb_Down_c = 6.2831853071795862 / static_cast<real_T>
                (*rtu_MissionUAV);

              // Product: '<S3>/Map2Radian' incorporates:
              //   Bias: '<S3>/Bias'
              //   Gain: '<S3>/HalveMissionUAV'
              //   Sum: '<S3>/Minus'

              rtb_Down_c *= static_cast<real_T>(rtb_ClockwiseRotation_n) -
                static_cast<real_T>(static_cast<int32_T>(b_nrows + 1)) * 0.5;

              // Switch: '<S45>/Switch' incorporates:
              //   Abs: '<S45>/Abs'
              //   Bias: '<S45>/Bias'
              //   Bias: '<S45>/Bias1'
              //   Constant: '<S45>/Constant2'
              //   Constant: '<S46>/Constant'
              //   DataStoreRead: '<S3>/LatitudeGCS'
              //   Math: '<S45>/Math Function1'
              //   RelationalOperator: '<S46>/Compare'

              if (std::abs(LatitudeGCS) > 180.0) {
                rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
              } else {
                rtb_Down = LatitudeGCS;
              }

              // Abs: '<S42>/Abs1'
              rtb_Switch_aa = std::abs(rtb_Down);

              // Switch: '<S42>/Switch' incorporates:
              //   Bias: '<S42>/Bias'
              //   Bias: '<S42>/Bias1'
              //   Constant: '<S33>/Constant'
              //   Constant: '<S33>/Constant1'
              //   Constant: '<S44>/Constant'
              //   Gain: '<S42>/Gain'
              //   Product: '<S42>/Divide1'
              //   RelationalOperator: '<S44>/Compare'
              //   Switch: '<S33>/Switch1'

              if (rtb_Switch_aa > 90.0) {
                // Signum: '<S42>/Sign1'
                if (rtb_Down < 0.0) {
                  rtb_Down = -1.0;
                } else if (rtb_Down > 0.0) {
                  rtb_Down = 1.0;
                } else if (rtb_Down == 0.0) {
                  rtb_Down = 0.0;
                } else {
                  rtb_Down = (rtNaN);
                }

                rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
                b_nrows = 180;
              } else {
                b_nrows = 0;
              }

              // Sum: '<S33>/Sum' incorporates:
              //   DataStoreRead: '<S3>/LongitudeGCS'

              rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

              // Sum: '<S31>/Sum1'
              rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

              // Switch: '<S43>/Switch' incorporates:
              //   Abs: '<S43>/Abs'
              //   Bias: '<S43>/Bias'
              //   Bias: '<S43>/Bias1'
              //   Constant: '<S43>/Constant2'
              //   Constant: '<S47>/Constant'
              //   Math: '<S43>/Math Function1'
              //   RelationalOperator: '<S47>/Compare'

              if (std::abs(rtb_Sum) > 180.0) {
                rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
              }

              // Sum: '<S31>/Sum1'
              rtb_Sum = rtu_Location->Lon - rtb_Sum;

              // Switch: '<S39>/Switch' incorporates:
              //   Abs: '<S39>/Abs'
              //   Bias: '<S39>/Bias'
              //   Bias: '<S39>/Bias1'
              //   Constant: '<S39>/Constant2'
              //   Constant: '<S40>/Constant'
              //   Math: '<S39>/Math Function1'
              //   RelationalOperator: '<S40>/Compare'

              if (std::abs(rtb_Switch_aa) > 180.0) {
                rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                  -180.0;
              }

              // Abs: '<S36>/Abs1'
              rtb_Abs1_jo = std::abs(rtb_Switch_aa);

              // Switch: '<S36>/Switch' incorporates:
              //   Bias: '<S36>/Bias'
              //   Bias: '<S36>/Bias1'
              //   Constant: '<S32>/Constant'
              //   Constant: '<S32>/Constant1'
              //   Constant: '<S38>/Constant'
              //   Gain: '<S36>/Gain'
              //   Product: '<S36>/Divide1'
              //   RelationalOperator: '<S38>/Compare'
              //   Switch: '<S32>/Switch1'

              if (rtb_Abs1_jo > 90.0) {
                // Signum: '<S36>/Sign1'
                if (rtb_Switch_aa < 0.0) {
                  rtb_Switch_aa = -1.0;
                } else if (rtb_Switch_aa > 0.0) {
                  rtb_Switch_aa = 1.0;
                } else if (rtb_Switch_aa == 0.0) {
                  rtb_Switch_aa = 0.0;
                } else {
                  rtb_Switch_aa = (rtNaN);
                }

                rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
                b_nrows = 180;
              } else {
                rtb_Abs1_jo = rtb_Switch_aa;
                b_nrows = 0;
              }

              // Sum: '<S32>/Sum'
              rtb_Sum += static_cast<real_T>(b_nrows);

              // UnitConversion: '<S35>/Unit Conversion'
              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

              // UnitConversion: '<S50>/Unit Conversion'
              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              rtb_Down *= 0.017453292519943295;

              // Trigonometry: '<S51>/Trigonometric Function1'
              rtb_Param4_e = std::sin(rtb_Down);

              // Sum: '<S51>/Sum1' incorporates:
              //   Constant: '<S51>/Constant'
              //   Product: '<S51>/Product1'

              rtb_Param4_e = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_i *
                PreemptableMissionModeSelector_ConstB.sqrt_i * rtb_Param4_e *
                rtb_Param4_e;

              // Product: '<S49>/Product1' incorporates:
              //   Constant: '<S49>/Constant1'
              //   Sqrt: '<S49>/sqrt'

              rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

              // Product: '<S34>/dNorth' incorporates:
              //   Constant: '<S49>/Constant2'
              //   Product: '<S49>/Product3'
              //   Trigonometry: '<S49>/Trigonometric Function1'

              rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
                PreemptableMissionModeSelector_ConstB.Sum1_fv / rtb_Param4_e);

              // Switch: '<S37>/Switch' incorporates:
              //   Abs: '<S37>/Abs'
              //   Bias: '<S37>/Bias'
              //   Bias: '<S37>/Bias1'
              //   Constant: '<S37>/Constant2'
              //   Constant: '<S41>/Constant'
              //   Math: '<S37>/Math Function1'
              //   RelationalOperator: '<S41>/Compare'

              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              if (std::abs(rtb_Sum) > 180.0) {
                rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
              }

              // Product: '<S34>/dEast' incorporates:
              //   Constant: '<S49>/Constant3'
              //   Product: '<S49>/Product4'
              //   Trigonometry: '<S49>/Trigonometric Function'
              //   Trigonometry: '<S49>/Trigonometric Function2'
              //   UnitConversion: '<S35>/Unit Conversion'

              rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos
                (rtb_Down)) * (0.017453292519943295 * rtb_Sum);

              // Sum: '<S34>/Sum2' incorporates:
              //   Product: '<S34>/x*cos'
              //   Product: '<S34>/y*sin'

              rtb_Down = rtb_Abs1_jo * 0.0 + rtb_Param4_e;

              // Sum: '<S34>/Sum3' incorporates:
              //   Product: '<S34>/x*sin'
              //   Product: '<S34>/y*cos'

              rtb_Switch_aa = rtb_Abs1_jo - rtb_Param4_e * 0.0;

              // Sum: '<S31>/Sum' incorporates:
              //   DataStoreRead: '<S3>/AltitudeGCS'
              //   Gain: '<S3>/inverse'

              rtb_Sum = rtu_Location->Alt + -AltitudeGCS;

              // SignalConversion generated from: '<S3>/Orbit Follower' incorporates:
              //   UnaryMinus: '<S31>/Ze2height'

              rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Down;
              rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Switch_aa;
              rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = -rtb_Sum;

              // DataTypeConversion: '<S3>/Param1'
              rtb_Param1_f = static_cast<real_T>(rtu_Parameters->Param1);

              // DataTypeConversion: '<S3>/Param2'
              rtb_Param2_a = static_cast<real_T>(rtu_Parameters->Param2);
              PreemptableMissionModeSelector_OrbitFollower(rtu_Pose,
                rtb_TmpSignalConversionAtOrbitFollowerInport2, rtb_Param1_f,
                rtb_Param2_a, 1.0, &localB->OrbitFollower_b,
                &localDW->OrbitFollower_b);

              // BusCreator: '<S3>/GuidanceCMDBusCreator' incorporates:
              //   Constant: '<S3>/Constant'
              //   DataTypeConversion: '<S3>/Param3'
              //   Gain: '<S3>/Down2Height'

              rty_GuidanceCmds->Height =
                -localB->OrbitFollower_b.OrbitFollower_o1[2];
              rty_GuidanceCmds->AirSpeed = static_cast<real_T>
                (rtu_Parameters->Param4);
              rty_GuidanceCmds->HeadingAngle =
                localB->OrbitFollower_b.OrbitFollower_o2;

              // Reshape: '<S3>/Reshape' incorporates:
              //   Bias: '<S3>/ClockwiseRotation'
              //   Constant: '<S3>/InitialFlightPathAngle'
              //   Constant: '<S3>/InitialRollAngle'
              //   Constant: '<S3>/InitialRollAngleRate'
              //   DataTypeConversion: '<S3>/Param3'
              //   Product: '<S3>/EastDis'
              //   Product: '<S3>/NorthDis'
              //   Sum: '<S3>/SumInitEast'
              //   Sum: '<S3>/SumInitNorth'
              //   Trigonometry: '<S3>/Cos'
              //   Trigonometry: '<S3>/Sin'
              //   UnaryMinus: '<S31>/Ze2height'

              rty_InitialState[0] = std::cos(rtb_Down_c) * rtb_Param1_f +
                rtb_Down;
              rty_InitialState[1] = rtb_Param1_f * std::sin(rtb_Down_c) +
                rtb_Switch_aa;
              rty_InitialState[2] = rtb_Sum;
              rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
              rty_InitialState[4] = rtb_Down_c + 1.5707963267948966;
              rty_InitialState[5] = 0.0;
              rty_InitialState[6] = 0.0;
              rty_InitialState[7] = 0.0;

              // SignalConversion generated from: '<S3>/Orbit Follower'
              *rty_thisTaskStatus = localB->OrbitFollower_b.OrbitFollower_o6;
            } else {
              localDW->is_OrbitFollower =
                PreemptableMissionModeSelector_IN_CircleDisplayNav;

              // DataTypeConversion: '<S2>/Param1'
              rtb_Param1_i = static_cast<real_T>(rtu_Parameters->Param1);

              // Product: '<S2>/Divide'
              rtb_Down_c = rtu_StartPosition->Lat / rtb_Param1_i;

              // Switch: '<S22>/Switch' incorporates:
              //   Abs: '<S22>/Abs'
              //   Bias: '<S22>/Bias'
              //   Bias: '<S22>/Bias1'
              //   Constant: '<S22>/Constant2'
              //   Constant: '<S23>/Constant'
              //   DataStoreRead: '<S2>/LatitudeGCS'
              //   Math: '<S22>/Math Function1'
              //   RelationalOperator: '<S23>/Compare'

              if (std::abs(LatitudeGCS) > 180.0) {
                rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
              } else {
                rtb_Down = LatitudeGCS;
              }

              // Abs: '<S19>/Abs1'
              rtb_Switch_aa = std::abs(rtb_Down);

              // Switch: '<S19>/Switch' incorporates:
              //   Bias: '<S19>/Bias'
              //   Bias: '<S19>/Bias1'
              //   Constant: '<S10>/Constant'
              //   Constant: '<S10>/Constant1'
              //   Constant: '<S21>/Constant'
              //   Gain: '<S19>/Gain'
              //   Product: '<S19>/Divide1'
              //   RelationalOperator: '<S21>/Compare'
              //   Switch: '<S10>/Switch1'

              if (rtb_Switch_aa > 90.0) {
                // Signum: '<S19>/Sign1'
                if (rtb_Down < 0.0) {
                  rtb_Down = -1.0;
                } else if (rtb_Down > 0.0) {
                  rtb_Down = 1.0;
                } else if (rtb_Down == 0.0) {
                  rtb_Down = 0.0;
                } else {
                  rtb_Down = (rtNaN);
                }

                rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
                b_nrows = 180;
              } else {
                b_nrows = 0;
              }

              // Sum: '<S10>/Sum' incorporates:
              //   DataStoreRead: '<S2>/LongitudeGCS'

              rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

              // Sum: '<S8>/Sum1'
              rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

              // Switch: '<S20>/Switch' incorporates:
              //   Abs: '<S20>/Abs'
              //   Bias: '<S20>/Bias'
              //   Bias: '<S20>/Bias1'
              //   Constant: '<S20>/Constant2'
              //   Constant: '<S24>/Constant'
              //   Math: '<S20>/Math Function1'
              //   RelationalOperator: '<S24>/Compare'

              if (std::abs(rtb_Sum) > 180.0) {
                rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
              }

              // Sum: '<S8>/Sum1'
              rtb_Sum = rtu_Location->Lon - rtb_Sum;

              // Switch: '<S16>/Switch' incorporates:
              //   Abs: '<S16>/Abs'
              //   Bias: '<S16>/Bias'
              //   Bias: '<S16>/Bias1'
              //   Constant: '<S16>/Constant2'
              //   Constant: '<S17>/Constant'
              //   Math: '<S16>/Math Function1'
              //   RelationalOperator: '<S17>/Compare'

              if (std::abs(rtb_Switch_aa) > 180.0) {
                rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                  -180.0;
              }

              // Abs: '<S13>/Abs1'
              rtb_Abs1_jo = std::abs(rtb_Switch_aa);

              // Switch: '<S13>/Switch' incorporates:
              //   Bias: '<S13>/Bias'
              //   Bias: '<S13>/Bias1'
              //   Constant: '<S15>/Constant'
              //   Constant: '<S9>/Constant'
              //   Constant: '<S9>/Constant1'
              //   Gain: '<S13>/Gain'
              //   Product: '<S13>/Divide1'
              //   RelationalOperator: '<S15>/Compare'
              //   Switch: '<S9>/Switch1'

              if (rtb_Abs1_jo > 90.0) {
                // Signum: '<S13>/Sign1'
                if (rtb_Switch_aa < 0.0) {
                  rtb_Switch_aa = -1.0;
                } else if (rtb_Switch_aa > 0.0) {
                  rtb_Switch_aa = 1.0;
                } else if (rtb_Switch_aa == 0.0) {
                  rtb_Switch_aa = 0.0;
                } else {
                  rtb_Switch_aa = (rtNaN);
                }

                rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
                b_nrows = 180;
              } else {
                rtb_Abs1_jo = rtb_Switch_aa;
                b_nrows = 0;
              }

              // Sum: '<S9>/Sum'
              rtb_Sum += static_cast<real_T>(b_nrows);

              // UnitConversion: '<S12>/Unit Conversion'
              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

              // UnitConversion: '<S27>/Unit Conversion'
              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              rtb_Down *= 0.017453292519943295;

              // Trigonometry: '<S28>/Trigonometric Function1'
              rtb_Param4_e = std::sin(rtb_Down);

              // Sum: '<S28>/Sum1' incorporates:
              //   Constant: '<S28>/Constant'
              //   Product: '<S28>/Product1'

              rtb_Param4_e = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_g *
                PreemptableMissionModeSelector_ConstB.sqrt_g * rtb_Param4_e *
                rtb_Param4_e;

              // Product: '<S26>/Product1' incorporates:
              //   Constant: '<S26>/Constant1'
              //   Sqrt: '<S26>/sqrt'

              rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

              // Product: '<S11>/dNorth' incorporates:
              //   Constant: '<S26>/Constant2'
              //   Product: '<S26>/Product3'
              //   Trigonometry: '<S26>/Trigonometric Function1'

              rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
                PreemptableMissionModeSelector_ConstB.Sum1_kk / rtb_Param4_e);

              // Switch: '<S14>/Switch' incorporates:
              //   Abs: '<S14>/Abs'
              //   Bias: '<S14>/Bias'
              //   Bias: '<S14>/Bias1'
              //   Constant: '<S14>/Constant2'
              //   Constant: '<S18>/Constant'
              //   Math: '<S14>/Math Function1'
              //   RelationalOperator: '<S18>/Compare'

              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              if (std::abs(rtb_Sum) > 180.0) {
                rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
              }

              // Product: '<S11>/dEast' incorporates:
              //   Constant: '<S26>/Constant3'
              //   Product: '<S26>/Product4'
              //   Trigonometry: '<S26>/Trigonometric Function'
              //   Trigonometry: '<S26>/Trigonometric Function2'
              //   UnitConversion: '<S12>/Unit Conversion'

              rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos
                (rtb_Down)) * (0.017453292519943295 * rtb_Sum);

              // Sum: '<S11>/Sum2' incorporates:
              //   Product: '<S11>/x*cos'
              //   Product: '<S11>/y*sin'

              rtb_Down = rtb_Abs1_jo * 0.0 + rtb_Param4_e;

              // Sum: '<S11>/Sum3' incorporates:
              //   Product: '<S11>/x*sin'
              //   Product: '<S11>/y*cos'

              rtb_Switch_aa = rtb_Abs1_jo - rtb_Param4_e * 0.0;

              // Sum: '<S8>/Sum' incorporates:
              //   DataStoreRead: '<S2>/AltitudeGCS'
              //   Gain: '<S2>/inverse'

              rtb_Sum = rtu_Location->Alt + -AltitudeGCS;

              // Sum: '<S2>/SumUp' incorporates:
              //   UnaryMinus: '<S8>/Ze2height'

              rtb_Sum += rtu_StartPosition->Alt;

              // SignalConversion generated from: '<S2>/Orbit Follower' incorporates:
              //   Gain: '<S2>/Up2Down'

              rtb_TmpSignalConversionAtOrbitFollowerInport2_b[0] = rtb_Down;
              rtb_TmpSignalConversionAtOrbitFollowerInport2_b[1] = rtb_Switch_aa;
              rtb_TmpSignalConversionAtOrbitFollowerInport2_b[2] = -rtb_Sum;

              // DataTypeConversion: '<S2>/Param2'
              rtb_Param2_n1 = static_cast<real_T>(rtu_Parameters->Param2);
              PreemptableMissionModeSelector_OrbitFollower(rtu_Pose,
                rtb_TmpSignalConversionAtOrbitFollowerInport2_b, rtb_Param1_i,
                rtb_Param2_n1, 1.0, &localB->OrbitFollower,
                &localDW->OrbitFollower);

              // BusCreator: '<S2>/GuidanceCMDBusCreator' incorporates:
              //   Constant: '<S2>/Constant'
              //   DataTypeConversion: '<S2>/Param3'
              //   Gain: '<S2>/Down2Height'

              rty_GuidanceCmds->Height = -localB->
                OrbitFollower.OrbitFollower_o1[2];
              rty_GuidanceCmds->AirSpeed = static_cast<real_T>
                (rtu_Parameters->Param4);
              rty_GuidanceCmds->HeadingAngle =
                localB->OrbitFollower.OrbitFollower_o2;

              // Reshape: '<S2>/Reshape' incorporates:
              //   Bias: '<S2>/ClockwiseRotation'
              //   Constant: '<S2>/InitialFlightPathAngle'
              //   Constant: '<S2>/InitialRollAngle'
              //   Constant: '<S2>/InitialRollAngleRate'
              //   DataTypeConversion: '<S2>/Param3'
              //   Product: '<S2>/EastDis'
              //   Product: '<S2>/NorthDis'
              //   Sum: '<S2>/SumInitEast'
              //   Sum: '<S2>/SumInitNorth'
              //   Trigonometry: '<S2>/Cos'
              //   Trigonometry: '<S2>/Sin'

              rty_InitialState[0] = std::cos(rtb_Down_c) * rtb_Param1_i +
                rtb_Down;
              rty_InitialState[1] = rtb_Param1_i * std::sin(rtb_Down_c) +
                rtb_Switch_aa;
              rty_InitialState[2] = rtb_Sum;
              rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
              rty_InitialState[4] = rtb_Down_c + 1.5707963267948966;
              rty_InitialState[5] = 0.0;
              rty_InitialState[6] = 0.0;
              rty_InitialState[7] = 0.0;

              // SignalConversion generated from: '<S2>/Orbit Follower'
              *rty_thisTaskStatus = localB->OrbitFollower.OrbitFollower_o6;
            }
          } else {
            sf_internal_predicateOutput = ((*rtu_mode == 2) || (*rtu_mode == 22));
            if (sf_internal_predicateOutput) {
              localDW->is_GuidanceLogic =
                PreemptableMissionModeSelector_IN_WaypointFollower;
              *rty_ResetTrigger = 1.0;
              if (*rtu_mode == 2) {
                localDW->is_WaypointFollower =
                  PreemptableMissionModeSelector_IN_HorizontalFormationNav;

                // Sum: '<S166>/Sum' incorporates:
                //   DataStoreRead: '<S7>/AltitudeGCS'
                //   Gain: '<S7>/inverse'

                rtb_Switch_aa = rtu_Location->Alt + -AltitudeGCS;

                // DataTypeConversion: '<S7>/CastToDouble'
                rtb_Switch_e = static_cast<real_T>(*rtu_FormationIDX);

                // Sum: '<S7>/Minus' incorporates:
                //   Constant: '<S7>/One2ZeroIdx'

                rtb_Switch_e--;

                // Gain: '<S7>/Gain' incorporates:
                //   Constant: '<S7>/Three'
                //   Math: '<S7>/ModRunWayLayer'

                rtb_Down_c = 15.0 * rt_modd_snf(rtb_Switch_e, 3.0);

                // Sum: '<S7>/BiasMissionAlt' incorporates:
                //   UnaryMinus: '<S166>/Ze2height'

                rtb_Down = -rtb_Switch_aa - rtb_Down_c;

                // Sum: '<S167>/Sum' incorporates:
                //   DataStoreRead: '<S7>/PrevAltitudeGCS'
                //   Gain: '<S7>/PrevInverse'

                rtb_Switch_aa = rtu_PrevLocation->Alt + -AltitudeGCS;

                // Sum: '<S7>/BiasPrevAlt' incorporates:
                //   UnaryMinus: '<S167>/Ze2height'

                rtb_Down_c = -rtb_Switch_aa - rtb_Down_c;

                // Switch: '<S182>/Switch' incorporates:
                //   Abs: '<S182>/Abs'
                //   Bias: '<S182>/Bias'
                //   Bias: '<S182>/Bias1'
                //   Constant: '<S182>/Constant2'
                //   Constant: '<S183>/Constant'
                //   DataStoreRead: '<S7>/LatitudeGCS'
                //   Math: '<S182>/Math Function1'
                //   RelationalOperator: '<S183>/Compare'

                if (std::abs(LatitudeGCS) > 180.0) {
                  rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
                } else {
                  rtb_Switch = LatitudeGCS;
                }

                // Abs: '<S179>/Abs1'
                rtb_Switch_aa = std::abs(rtb_Switch);

                // Switch: '<S179>/Switch' incorporates:
                //   Bias: '<S179>/Bias'
                //   Bias: '<S179>/Bias1'
                //   Constant: '<S170>/Constant'
                //   Constant: '<S170>/Constant1'
                //   Constant: '<S181>/Constant'
                //   Gain: '<S179>/Gain'
                //   Product: '<S179>/Divide1'
                //   RelationalOperator: '<S181>/Compare'
                //   Switch: '<S170>/Switch1'

                if (rtb_Switch_aa > 90.0) {
                  // Signum: '<S179>/Sign1'
                  if (rtb_Switch < 0.0) {
                    rtb_Switch = -1.0;
                  } else if (rtb_Switch > 0.0) {
                    rtb_Switch = 1.0;
                  } else if (rtb_Switch == 0.0) {
                    rtb_Switch = 0.0;
                  } else {
                    rtb_Switch = (rtNaN);
                  }

                  rtb_Switch *= -(rtb_Switch_aa + -90.0) + 90.0;
                  b_nrows = 180;
                } else {
                  b_nrows = 0;
                }

                // Sum: '<S170>/Sum' incorporates:
                //   DataStoreRead: '<S7>/LongitudeGCS'

                rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

                // Sum: '<S166>/Sum1'
                rtb_Switch_aa = rtu_Location->Lat - rtb_Switch;

                // Switch: '<S180>/Switch' incorporates:
                //   Abs: '<S180>/Abs'
                //   Bias: '<S180>/Bias'
                //   Bias: '<S180>/Bias1'
                //   Constant: '<S180>/Constant2'
                //   Constant: '<S184>/Constant'
                //   Math: '<S180>/Math Function1'
                //   RelationalOperator: '<S184>/Compare'

                if (std::abs(rtb_Sum) > 180.0) {
                  rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S166>/Sum1'
                rtb_Sum = rtu_Location->Lon - rtb_Sum;

                // Switch: '<S176>/Switch' incorporates:
                //   Abs: '<S176>/Abs'
                //   Bias: '<S176>/Bias'
                //   Bias: '<S176>/Bias1'
                //   Constant: '<S176>/Constant2'
                //   Constant: '<S177>/Constant'
                //   Math: '<S176>/Math Function1'
                //   RelationalOperator: '<S177>/Compare'

                if (std::abs(rtb_Switch_aa) > 180.0) {
                  rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                    -180.0;
                }

                // Abs: '<S173>/Abs1'
                rtb_Abs1_jo = std::abs(rtb_Switch_aa);

                // Switch: '<S173>/Switch' incorporates:
                //   Bias: '<S173>/Bias'
                //   Bias: '<S173>/Bias1'
                //   Constant: '<S169>/Constant'
                //   Constant: '<S169>/Constant1'
                //   Constant: '<S175>/Constant'
                //   Gain: '<S173>/Gain'
                //   Product: '<S173>/Divide1'
                //   RelationalOperator: '<S175>/Compare'
                //   Switch: '<S169>/Switch1'

                if (rtb_Abs1_jo > 90.0) {
                  // Signum: '<S173>/Sign1'
                  if (rtb_Switch_aa < 0.0) {
                    rtb_Switch_aa = -1.0;
                  } else if (rtb_Switch_aa > 0.0) {
                    rtb_Switch_aa = 1.0;
                  } else if (rtb_Switch_aa == 0.0) {
                    rtb_Switch_aa = 0.0;
                  } else {
                    rtb_Switch_aa = (rtNaN);
                  }

                  rtb_Param4_e = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
                  b_nrows = 180;
                } else {
                  rtb_Param4_e = rtb_Switch_aa;
                  b_nrows = 0;
                }

                // Sum: '<S169>/Sum'
                rtb_Abs1_jo = static_cast<real_T>(b_nrows) + rtb_Sum;

                // UnitConversion: '<S172>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch_aa = 0.017453292519943295 * rtb_Param4_e;

                // UnitConversion: '<S187>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch *= 0.017453292519943295;

                // Trigonometry: '<S188>/Trigonometric Function1'
                rtb_Sum = std::sin(rtb_Switch);

                // Sum: '<S188>/Sum1' incorporates:
                //   Constant: '<S188>/Constant'
                //   Product: '<S188>/Product1'

                rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_b *
                  PreemptableMissionModeSelector_ConstB.sqrt_b * rtb_Sum *
                  rtb_Sum;

                // Product: '<S186>/Product1' incorporates:
                //   Constant: '<S186>/Constant1'
                //   Sqrt: '<S186>/sqrt'

                rtb_Param4_e = 6.378137E+6 / std::sqrt(rtb_Sum);

                // Product: '<S171>/dNorth' incorporates:
                //   Constant: '<S186>/Constant2'
                //   Product: '<S186>/Product3'
                //   Trigonometry: '<S186>/Trigonometric Function1'

                rtb_Sum = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Param4_e *
                  PreemptableMissionModeSelector_ConstB.Sum1_d / rtb_Sum);

                // Switch: '<S174>/Switch' incorporates:
                //   Abs: '<S174>/Abs'
                //   Bias: '<S174>/Bias'
                //   Bias: '<S174>/Bias1'
                //   Constant: '<S174>/Constant2'
                //   Constant: '<S178>/Constant'
                //   Math: '<S174>/Math Function1'
                //   RelationalOperator: '<S178>/Compare'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                if (std::abs(rtb_Abs1_jo) > 180.0) {
                  rtb_Abs1_jo = rt_modd_snf(rtb_Abs1_jo + 180.0, 360.0) + -180.0;
                }

                // Product: '<S171>/dEast' incorporates:
                //   Constant: '<S186>/Constant3'
                //   Product: '<S186>/Product4'
                //   Trigonometry: '<S186>/Trigonometric Function'
                //   Trigonometry: '<S186>/Trigonometric Function2'
                //   UnitConversion: '<S172>/Unit Conversion'

                rtb_Param4_e = 1.0 / rt_atan2d_snf(1.0, rtb_Param4_e * std::cos
                  (rtb_Switch)) * (0.017453292519943295 * rtb_Abs1_jo);

                // Sum: '<S171>/Sum2' incorporates:
                //   Product: '<S171>/x*cos'
                //   Product: '<S171>/y*sin'

                rtb_Abs1_jo = rtb_Param4_e * 0.0 + rtb_Sum;

                // Sum: '<S171>/Sum3' incorporates:
                //   Product: '<S171>/x*sin'
                //   Product: '<S171>/y*cos'

                rtb_Param4_e -= rtb_Sum * 0.0;

                // Product: '<S7>/Map2Radian' incorporates:
                //   DataTypeConversion: '<S7>/Param3'

                rtb_Switch_e *= static_cast<real_T>(rtu_Parameters->Param3);

                // Gain: '<S165>/Gain1'
                rtb_Gain1 = 0.017453292519943295 * rtu_Location->degHDG;

                // Outputs for Triggered SubSystem: '<S7>/WayPointGenerator' incorporates:
                //   TriggerPort: '<S168>/Trigger'

                zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                                   &localZCE->WayPointGenerator_Trig_ZCE,
                                   (localDW->MemoryTriggerWP_PreviousInput));
                if (zcEvent != NO_ZCEVENT) {
                  // Product: '<S168>/ProductScanWidth' incorporates:
                  //   DataTypeConversion: '<S7>/Param3'

                  rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) *
                    static_cast<real_T>(*rtu_MissionUAV);

                  // Reshape: '<S168>/ReshapeRowVec'
                  rtb_ReshapeRowVec[0] = rtb_Abs1_jo;
                  rtb_ReshapeRowVec[1] = rtb_Param4_e;
                  rtb_ReshapeRowVec[2] = rtb_Down;

                  // SignalConversion generated from: '<S168>/RotateATMissionHdg' incorporates:
                  //   Constant: '<S168>/Zero'

                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    rtb_Gain1;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] = 0.0;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                  PreemptableMissionModeSelector_RotateATMissionHdg
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1,
                     &localB->RotateATMissionHdg_baf);

                  // MATLAB Function: '<S168>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S7>/Param2'

                  rtb_Switch_aa = std::ceil(static_cast<real_T>
                    (rtu_Parameters->Param2) / rtb_Switch_aa);
                  rtb_Sum = static_cast<real_T>(rtu_Parameters->Param2) /
                    rtb_Switch_aa;
                  connectionObj.FlightPathAngleLimit[0] = -0.175;
                  connectionObj.FlightPathAngleLimit[1] = 0.175;
                  connectionObj.MaxRollAngle = 0.29670597283903605;
                  connectionObj.AirSpeed = 35.0;
                  connectionObj.MinTurningRadius = 408.85657731051754;
                  b_nrows = static_cast<int32_T>(rtb_Switch_aa * 2.0);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (CheckPoints->size[0] * CheckPoints->size[1]);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  CheckPoints->size[0] = b_nrows;
                  CheckPoints->size[1] = 4;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (CheckPoints, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S168>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S7>/Param1'

                  ibmat = static_cast<int32_T>(static_cast<int32_T>(b_nrows << 2)
                    - 1);
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       ibmat; rtb_ClockwiseRotation_n++) {
                    CheckPoints->data[rtb_ClockwiseRotation_n] = 0.0;
                  }

                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa)
                        - 1); rtb_ClockwiseRotation_n = static_cast<int32_T>
                       (rtb_ClockwiseRotation_n + 1)) {
                    if (rt_remd_snf(static_cast<real_T>(rtb_ClockwiseRotation_n)
                                    + 1.0, 2.0) == 1.0) {
                      b_nrows = static_cast<int32_T>(static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 1) << 1);
                      rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n)
                                     + 1.0) - 1.0) * rtb_Sum;
                      CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                        rtb_Switch;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + CheckPoints->size[0]) - 2)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] <<
                        1)) - 2)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 2)] = 1.5707963267948966;
                      CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                        rtb_Switch;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + CheckPoints->size[0]) - 1)] =
                        static_cast<real_T>(rtu_Parameters->Param1);
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] <<
                        1)) - 1)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 1)] = 1.5707963267948966;
                    } else {
                      b_nrows = static_cast<int32_T>(static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 1) << 1);
                      rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n)
                                     + 1.0) - 1.0) * rtb_Sum;
                      CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                        rtb_Switch;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + CheckPoints->size[0]) - 2)] =
                        static_cast<real_T>(rtu_Parameters->Param1);
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] <<
                        1)) - 2)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 2)] = -1.5707963267948966;
                      CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                        rtb_Switch;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + CheckPoints->size[0]) - 1)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] <<
                        1)) - 1)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 1)] = -1.5707963267948966;
                    }
                  }

                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  dummyWayPoint->size[0] = 1;
                  dummyWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  dummyWayPoint->data[0] = 0.0;
                  dummyWayPoint->data[1] = 0.0;
                  dummyWayPoint->data[2] = 0.0;
                  for (nrowx = 0; nrowx <= static_cast<int32_T>
                       (CheckPoints->size[0] - 2); nrowx = static_cast<int32_T>
                       (nrowx + 1)) {
                    LUp[0] = CheckPoints->data[nrowx];
                    LDp[0] = CheckPoints->data[static_cast<int32_T>(nrowx + 1)];
                    LUp[1] = CheckPoints->data[static_cast<int32_T>(nrowx +
                      CheckPoints->size[0])];
                    LDp[1] = CheckPoints->data[static_cast<int32_T>
                      (static_cast<int32_T>(nrowx + CheckPoints->size[0]) + 1)];
                    LUp[2] = CheckPoints->data[static_cast<int32_T>(nrowx +
                      static_cast<int32_T>(CheckPoints->size[0] << 1))];
                    LDp[2] = CheckPoints->data[static_cast<int32_T>
                      (static_cast<int32_T>(nrowx + static_cast<int32_T>
                        (CheckPoints->size[0] << 1)) + 1)];
                    LUp[3] = CheckPoints->data[static_cast<int32_T>(nrowx +
                      static_cast<int32_T>(CheckPoints->size[0] * 3))];
                    LDp[3] = CheckPoints->data[static_cast<int32_T>
                      (static_cast<int32_T>(nrowx + static_cast<int32_T>
                        (CheckPoints->size[0] * 3)) + 1)];
                    PreemptableMissionModeSelector_genSegWP_la(&connectionObj,
                      LUp, LDp, 100.0, segWayPoints, localB);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);
                    dummyWayPoint_0->size[0] = static_cast<int32_T>
                      (dummyWayPoint->size[0] + segWayPoints->size[0]);
                    dummyWayPoint_0->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (dummyWayPoint_0, rtb_ClockwiseRotation_n);
                    ibmat = dummyWayPoint->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint_0->size[0] * b_nrows))] =
                          dummyWayPoint->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint->size[0] * b_nrows))];
                      }
                    }

                    ibmat = segWayPoints->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                          (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                            dummyWayPoint->size[0]) + static_cast<int32_T>
                           (dummyWayPoint_0->size[0] * b_nrows))] =
                          segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (segWayPoints->size[0] * b_nrows))];
                      }
                    }

                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (dummyWayPoint->size[0] * dummyWayPoint->size[1]);
                    dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                    dummyWayPoint->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (dummyWayPoint, rtb_ClockwiseRotation_n);
                    ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                    for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                         b_nrows++) {
                      dummyWayPoint->data[b_nrows] = dummyWayPoint_0->
                        data[b_nrows];
                    }
                  }

                  LUp[0] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] - 1)];
                  LDp[0] = CheckPoints->data[0];
                  LUp[1] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(CheckPoints->size[0] +
                      CheckPoints->size[0]) - 1)];
                  LDp[1] = CheckPoints->data[CheckPoints->size[0]];
                  LUp[2] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(CheckPoints->size[0] +
                      static_cast<int32_T>(CheckPoints->size[0] << 1)) - 1)];
                  LDp[2] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] << 1)];
                  LUp[3] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(CheckPoints->size[0] +
                      static_cast<int32_T>(CheckPoints->size[0] * 3)) - 1)];
                  LDp[3] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] * 3)];
                  PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp,
                    LDp, 100.0, segWayPoints, localB);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  dummyWayPoint_0->size[0] = static_cast<int32_T>
                    (dummyWayPoint->size[0] + segWayPoints->size[0]);
                  dummyWayPoint_0->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint_0, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  ibmat = dummyWayPoint->size[0];
                  loop_ub = segWayPoints->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      dummyWayPoint_0->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * b_nrows))] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] * b_nrows))];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(loop_ub - 1);
                         rtb_ClockwiseRotation_n++) {
                      dummyWayPoint_0->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          dummyWayPoint->size[0]) + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * b_nrows))] =
                        segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }
                  }

                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                  dummyWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                  for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                       b_nrows++) {
                    dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
                  }

                  nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
                  nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
                  for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<
                       int32_T>(b_nrows + 1)) {
                    dummyWayPoint->data[b_nrows] = dummyWayPoint->data[
                      static_cast<int32_T>(b_nrows + 1)];
                  }

                  for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<
                       int32_T>(b_nrows + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                      dummyWayPoint->size[0])] = dummyWayPoint->data[
                      static_cast<int32_T>(static_cast<int32_T>(b_nrows +
                      dummyWayPoint->size[0]) + 1)];
                  }

                  for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<
                       int32_T>(b_nrows + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                      static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                      dummyWayPoint->data[static_cast<int32_T>
                      (static_cast<int32_T>(b_nrows + static_cast<int32_T>
                        (dummyWayPoint->size[0] << 1)) + 1)];
                  }

                  if (1 > nrows) {
                    ibmat = -1;
                  } else {
                    ibmat = nrowx;
                  }

                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (segWayPoints->size[0] * segWayPoints->size[1]);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  segWayPoints->size[0] = static_cast<int32_T>(ibmat + 1);
                  segWayPoints->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (segWayPoints, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         ibmat; rtb_ClockwiseRotation_n++) {
                      segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] * b_nrows))];
                    }
                  }

                  if (1 > nrows) {
                    b_nrows = -1;
                    nrowx = -1;
                  } else {
                    b_nrows = nrowx;
                  }

                  rtb_Switch_aa = std::ceil(10240.0 / static_cast<real_T>(
                    static_cast<int32_T>(b_nrows + 1)));
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  dummyWayPoint->size[0] = static_cast<int32_T>
                    (static_cast<int32_T>(nrowx + 1) * static_cast<int32_T>
                     (rtb_Switch_aa));
                  dummyWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  b_nrows = segWayPoints->size[0];
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa)
                        - 1); rtb_ClockwiseRotation_n = static_cast<int32_T>
                       (rtb_ClockwiseRotation_n + 1)) {
                    nrows = static_cast<int32_T>(static_cast<int32_T>
                      (rtb_ClockwiseRotation_n * b_nrows) + -1);
                    for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                         static_cast<int32_T>(b_nrows - 1); loop_ub =
                         static_cast<int32_T>(loop_ub + 1)) {
                      dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)]
                        = segWayPoints->data[static_cast<int32_T>(loop_ub - 1)];
                    }
                  }

                  ibmat = static_cast<int32_T>(static_cast<int32_T>
                    (segWayPoints->size[0] * static_cast<int32_T>(rtb_Switch_aa))
                    - 1);
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa)
                        - 1); rtb_ClockwiseRotation_n = static_cast<int32_T>
                       (rtb_ClockwiseRotation_n + 1)) {
                    nrows = static_cast<int32_T>(static_cast<int32_T>
                      (rtb_ClockwiseRotation_n * b_nrows) + ibmat);
                    for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                         static_cast<int32_T>(b_nrows - 1); loop_ub =
                         static_cast<int32_T>(loop_ub + 1)) {
                      dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)]
                        = segWayPoints->data[static_cast<int32_T>
                        (static_cast<int32_T>(b_nrows + loop_ub) - 1)];
                    }
                  }

                  nrowx = static_cast<int32_T>(segWayPoints->size[0] << 1);
                  ibmat = static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(segWayPoints->size[0] *
                    static_cast<int32_T>(rtb_Switch_aa)) << 1) - 1);
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa)
                        - 1); rtb_ClockwiseRotation_n = static_cast<int32_T>
                       (rtb_ClockwiseRotation_n + 1)) {
                    nrows = static_cast<int32_T>(static_cast<int32_T>
                      (rtb_ClockwiseRotation_n * b_nrows) + ibmat);
                    for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                         static_cast<int32_T>(b_nrows - 1); loop_ub =
                         static_cast<int32_T>(loop_ub + 1)) {
                      dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)]
                        = segWayPoints->data[static_cast<int32_T>
                        (static_cast<int32_T>(nrowx + loop_ub) - 1)];
                    }
                  }

                  // Reshape: '<S7>/Reshape2Row' incorporates:
                  //   Memory: '<S7>/MemoryPrevRelPos'

                  rtb_Reshape_i[0] = localDW->MemoryPrevRelPos_PreviousInput[1];
                  rtb_Reshape_i[1] = localDW->MemoryPrevRelPos_PreviousInput[0];
                  rtb_Reshape_i[2] = localDW->MemoryPrevRelPos_PreviousInput[2];

                  // Product: '<S168>/RotateRelPrevPos' incorporates:
                  //   MATLABSystem: '<S168>/RotateATMissionHdg'

                  rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtb_Reshape_i,
                    localB->RotateATMissionHdg_baf.RotateATMissionHdg,
                    rtb_startPose_h);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  LDp[0] = rtb_startPose_h[0];
                  LDp[1] = rtb_startPose_h[1];
                  LDp[2] = rtb_startPose_h[2];
                  LDp[3] = 1.5707963267948966;
                  LUp[0] = CheckPoints->data[0];
                  LUp[1] = CheckPoints->data[CheckPoints->size[0]];
                  LUp[2] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] << 1)];
                  LUp[3] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] * 3)];
                  PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LDp,
                    LUp, 100.0, segWayPoints, localB);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (initWayPoint->size[0] * initWayPoint->size[1]);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  initWayPoint->size[0] = static_cast<int32_T>
                    (segWayPoints->size[0] + dummyWayPoint->size[0]);
                  initWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (initWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S168>/WayPointGenerator'
                  ibmat = segWayPoints->size[0];
                  loop_ub = dummyWayPoint->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      initWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (initWayPoint->size[0] * b_nrows))] =
                        segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(loop_ub - 1);
                         rtb_ClockwiseRotation_n++) {
                      initWayPoint->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          segWayPoints->size[0]) + static_cast<int32_T>
                         (initWayPoint->size[0] * b_nrows))] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] * b_nrows))];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                         10240; rtb_ClockwiseRotation_n++) {
                      localB->WayPoint[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>(10240 *
                          b_nrows))] = initWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (initWayPoint->size[0] * b_nrows))];
                    }
                  }

                  // MATLAB Function: '<S168>/biasWayPoint'
                  for (b_nrows = 0; b_nrows < 10240; b_nrows++) {
                    localB->rtb_WayPoint_m[b_nrows] = localB->WayPoint[b_nrows]
                      + rtb_Switch_e;
                    localB->rtb_WayPoint_m[static_cast<int32_T>(b_nrows + 10240)]
                      = localB->WayPoint[static_cast<int32_T>(b_nrows + 10240)];
                    localB->rtb_WayPoint_m[static_cast<int32_T>(b_nrows + 20480)]
                      = localB->WayPoint[static_cast<int32_T>(b_nrows + 20480)];
                  }

                  // Product: '<S168>/RotateIndivWayPoint' incorporates:
                  //   MATLABSystem: '<S168>/RotateATMissionHdg'

                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                         10240; rtb_ClockwiseRotation_n++) {
                      ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                        static_cast<int32_T>(10240 * b_nrows));
                      localB->RotateIndivWayPoint[ibmat] = 0.0;
                      localB->RotateIndivWayPoint[ibmat] +=
                        localB->RotateATMissionHdg_baf.RotateATMissionHdg[
                        static_cast<int32_T>(3 * b_nrows)] *
                        localB->rtb_WayPoint_m[rtb_ClockwiseRotation_n];
                      localB->RotateIndivWayPoint[ibmat] +=
                        localB->RotateATMissionHdg_baf.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        1)] * localB->rtb_WayPoint_m[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 10240)];
                      localB->RotateIndivWayPoint[ibmat] +=
                        localB->RotateATMissionHdg_baf.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        2)] * localB->rtb_WayPoint_m[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 20480)];
                    }
                  }

                  // MATLAB Function: '<S168>/biasNED'
                  PreemptableMissionModeSelector_biasNED_l(rtb_ReshapeRowVec,
                    localB->RotateIndivWayPoint, localB->nedWayPoint,
                    &localB->sf_biasNED_j);
                }

                // End of Outputs for SubSystem: '<S7>/WayPointGenerator'
                PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
                  localB->nedWayPoint, 200.0, &localB->WaypointFollower_baf,
                  &localDW->WaypointFollower_baf);

                // DataTypeConversion: '<S7>/Cast To Double' incorporates:
                //   Constant: '<S7>/LookAheadDis'
                //   MATLAB Function: '<S168>/WayPointGenerator'
                //   Memory: '<S7>/MemoryTriggerWP'

                *rty_thisTaskStatus = static_cast<real_T>
                  (localB->WaypointFollower_baf.WaypointFollower_o5);

                // BusCreator: '<S7>/GuidanceCMDBusCreator' incorporates:
                //   DataTypeConversion: '<S7>/Param4'
                //   Gain: '<S7>/Down2Height'

                rty_GuidanceCmds->Height =
                  -localB->WaypointFollower_baf.WaypointFollower_o1[2];
                rty_GuidanceCmds->AirSpeed = static_cast<real_T>
                  (rtu_Parameters->Param4);
                rty_GuidanceCmds->HeadingAngle =
                  localB->WaypointFollower_baf.WaypointFollower_o2;

                // Switch: '<S204>/Switch' incorporates:
                //   Abs: '<S204>/Abs'
                //   Bias: '<S204>/Bias'
                //   Bias: '<S204>/Bias1'
                //   Constant: '<S204>/Constant2'
                //   Constant: '<S205>/Constant'
                //   DataStoreRead: '<S7>/PrevLatitudeGCS'
                //   Math: '<S204>/Math Function1'
                //   RelationalOperator: '<S205>/Compare'

                if (std::abs(LatitudeGCS) > 180.0) {
                  rtb_Switch_p = rt_modd_snf(LatitudeGCS + 180.0, 360.0) +
                    -180.0;
                } else {
                  rtb_Switch_p = LatitudeGCS;
                }

                // Abs: '<S201>/Abs1'
                rtb_Switch_aa = std::abs(rtb_Switch_p);

                // Switch: '<S201>/Switch' incorporates:
                //   Bias: '<S201>/Bias'
                //   Bias: '<S201>/Bias1'
                //   Constant: '<S192>/Constant'
                //   Constant: '<S192>/Constant1'
                //   Constant: '<S203>/Constant'
                //   Gain: '<S201>/Gain'
                //   Product: '<S201>/Divide1'
                //   RelationalOperator: '<S203>/Compare'
                //   Switch: '<S192>/Switch1'

                if (rtb_Switch_aa > 90.0) {
                  // Signum: '<S201>/Sign1'
                  if (rtb_Switch_p < 0.0) {
                    rtb_Switch_p = -1.0;
                  } else if (rtb_Switch_p > 0.0) {
                    rtb_Switch_p = 1.0;
                  } else if (rtb_Switch_p == 0.0) {
                    rtb_Switch_p = 0.0;
                  } else {
                    rtb_Switch_p = (rtNaN);
                  }

                  rtb_Switch_p *= -(rtb_Switch_aa + -90.0) + 90.0;
                  b_nrows = 180;
                } else {
                  b_nrows = 0;
                }

                // Sum: '<S192>/Sum' incorporates:
                //   DataStoreRead: '<S7>/PrevLongitudeGCS'

                rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

                // Sum: '<S167>/Sum1'
                rtb_Switch_aa = rtu_PrevLocation->Lat - rtb_Switch_p;

                // Switch: '<S202>/Switch' incorporates:
                //   Abs: '<S202>/Abs'
                //   Bias: '<S202>/Bias'
                //   Bias: '<S202>/Bias1'
                //   Constant: '<S202>/Constant2'
                //   Constant: '<S206>/Constant'
                //   Math: '<S202>/Math Function1'
                //   RelationalOperator: '<S206>/Compare'

                if (std::abs(rtb_Sum) > 180.0) {
                  rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S167>/Sum1'
                rtb_Sum = rtu_PrevLocation->Lon - rtb_Sum;

                // Switch: '<S198>/Switch' incorporates:
                //   Abs: '<S198>/Abs'
                //   Bias: '<S198>/Bias'
                //   Bias: '<S198>/Bias1'
                //   Constant: '<S198>/Constant2'
                //   Constant: '<S199>/Constant'
                //   Math: '<S198>/Math Function1'
                //   RelationalOperator: '<S199>/Compare'

                if (std::abs(rtb_Switch_aa) > 180.0) {
                  rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                    -180.0;
                }

                // Abs: '<S195>/Abs1'
                rtb_Switch = std::abs(rtb_Switch_aa);

                // Switch: '<S195>/Switch' incorporates:
                //   Bias: '<S195>/Bias'
                //   Bias: '<S195>/Bias1'
                //   Constant: '<S191>/Constant'
                //   Constant: '<S191>/Constant1'
                //   Constant: '<S197>/Constant'
                //   Gain: '<S195>/Gain'
                //   Product: '<S195>/Divide1'
                //   RelationalOperator: '<S197>/Compare'
                //   Switch: '<S191>/Switch1'

                if (rtb_Switch > 90.0) {
                  // Signum: '<S195>/Sign1'
                  if (rtb_Switch_aa < 0.0) {
                    rtb_Switch_aa = -1.0;
                  } else if (rtb_Switch_aa > 0.0) {
                    rtb_Switch_aa = 1.0;
                  } else if (rtb_Switch_aa == 0.0) {
                    rtb_Switch_aa = 0.0;
                  } else {
                    rtb_Switch_aa = (rtNaN);
                  }

                  rtb_Switch = (-(rtb_Switch + -90.0) + 90.0) * rtb_Switch_aa;
                  b_nrows = 180;
                } else {
                  rtb_Switch = rtb_Switch_aa;
                  b_nrows = 0;
                }

                // Sum: '<S191>/Sum'
                rtb_Switch_aa = static_cast<real_T>(b_nrows) + rtb_Sum;

                // UnitConversion: '<S209>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch_p *= 0.017453292519943295;

                // Trigonometry: '<S210>/Trigonometric Function1'
                rtb_Sum = std::sin(rtb_Switch_p);

                // Sum: '<S210>/Sum1' incorporates:
                //   Constant: '<S210>/Constant'
                //   Product: '<S210>/Product1'

                rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_c *
                  PreemptableMissionModeSelector_ConstB.sqrt_c * rtb_Sum *
                  rtb_Sum;

                // Product: '<S208>/Product1' incorporates:
                //   Constant: '<S208>/Constant1'
                //   Sqrt: '<S208>/sqrt'

                rtb_SumInitEast_j = 6.378137E+6 / std::sqrt(rtb_Sum);

                // Product: '<S208>/Product4' incorporates:
                //   Trigonometry: '<S208>/Trigonometric Function'

                rtb_Switch_p = rtb_SumInitEast_j * std::cos(rtb_Switch_p);

                // Product: '<S193>/dNorth' incorporates:
                //   Constant: '<S208>/Constant2'
                //   Product: '<S208>/Product3'
                //   Trigonometry: '<S208>/Trigonometric Function1'
                //   UnitConversion: '<S194>/Unit Conversion'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_SumInitEast_j = 0.017453292519943295 * rtb_Switch /
                  rt_atan2d_snf(1.0, rtb_SumInitEast_j *
                                PreemptableMissionModeSelector_ConstB.Sum1_in /
                                rtb_Sum);

                // Switch: '<S196>/Switch' incorporates:
                //   Abs: '<S196>/Abs'
                //   Bias: '<S196>/Bias'
                //   Bias: '<S196>/Bias1'
                //   Constant: '<S196>/Constant2'
                //   Constant: '<S200>/Constant'
                //   Math: '<S196>/Math Function1'
                //   RelationalOperator: '<S200>/Compare'

                if (std::abs(rtb_Switch_aa) > 180.0) {
                  rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                    -180.0;
                }

                // Product: '<S193>/dEast' incorporates:
                //   Constant: '<S208>/Constant3'
                //   Trigonometry: '<S208>/Trigonometric Function2'
                //   UnitConversion: '<S194>/Unit Conversion'

                rtb_Sum = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_p) *
                  (0.017453292519943295 * rtb_Switch_aa);

                // Sum: '<S193>/Sum2' incorporates:
                //   Product: '<S193>/x*cos'
                //   Product: '<S193>/y*sin'

                rtb_Switch = rtb_Sum * 0.0 + rtb_SumInitEast_j;

                // Sum: '<S193>/Sum3' incorporates:
                //   Product: '<S193>/x*sin'
                //   Product: '<S193>/y*cos'

                rtb_SumInitEast_j = rtb_Sum - rtb_SumInitEast_j * 0.0;

                // Reshape: '<S7>/Reshape' incorporates:
                //   Bias: '<S7>/Rotate90deg'
                //   Constant: '<S7>/InitialFlightPathAngle'
                //   Constant: '<S7>/InitialRollAngle'
                //   Constant: '<S7>/InitialRollAngleRate'
                //   DataTypeConversion: '<S7>/Param4'
                //   Gain: '<S7>/Down2Up'
                //   Product: '<S7>/ProductEast'
                //   Product: '<S7>/ProductNorth'
                //   Sum: '<S7>/SumInitEast'
                //   Sum: '<S7>/SumInitNorth'
                //   Trigonometry: '<S7>/Cos'
                //   Trigonometry: '<S7>/Sin'

                rty_InitialState[0] = std::cos(rtb_Gain1 + 1.5707963267948966) *
                  rtb_Switch_e + rtb_Switch;
                rty_InitialState[1] = std::sin(rtb_Gain1 + 1.5707963267948966) *
                  rtb_Switch_e + rtb_SumInitEast_j;
                rty_InitialState[2] = -rtb_Down_c;
                rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
                rty_InitialState[4] = rtb_Gain1;
                rty_InitialState[5] = 0.0;
                rty_InitialState[6] = 0.0;
                rty_InitialState[7] = 0.0;

                // Update for Memory: '<S7>/MemoryPrevRelPos' incorporates:
                //   Sum: '<S7>/RelPrevPos'

                localDW->MemoryPrevRelPos_PreviousInput[0] = rtb_Switch -
                  rtb_Abs1_jo;
                localDW->MemoryPrevRelPos_PreviousInput[1] = rtb_SumInitEast_j -
                  rtb_Param4_e;
                localDW->MemoryPrevRelPos_PreviousInput[2] = rtb_Down_c -
                  rtb_Down;

                // Update for Memory: '<S7>/MemoryTriggerWP' incorporates:
                //   Constant: '<S7>/TirggerWayPointGen'

                localDW->MemoryTriggerWP_PreviousInput = 1.0;
              } else {
                localDW->is_WaypointFollower =
                  PreemptableMissionModeSelector_IN_CustomFormationNav;

                // Switch: '<S131>/Switch' incorporates:
                //   Abs: '<S131>/Abs'
                //   Bias: '<S131>/Bias'
                //   Bias: '<S131>/Bias1'
                //   Constant: '<S131>/Constant2'
                //   Constant: '<S132>/Constant'
                //   DataStoreRead: '<S6>/LatitudeGCS'
                //   Math: '<S131>/Math Function1'
                //   RelationalOperator: '<S132>/Compare'

                if (std::abs(LatitudeGCS) > 180.0) {
                  rtb_Down_c = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
                } else {
                  rtb_Down_c = LatitudeGCS;
                }

                // Abs: '<S128>/Abs1'
                rtb_Switch_aa = std::abs(rtb_Down_c);

                // Switch: '<S128>/Switch' incorporates:
                //   Bias: '<S128>/Bias'
                //   Bias: '<S128>/Bias1'
                //   Constant: '<S119>/Constant'
                //   Constant: '<S119>/Constant1'
                //   Constant: '<S130>/Constant'
                //   Gain: '<S128>/Gain'
                //   Product: '<S128>/Divide1'
                //   RelationalOperator: '<S130>/Compare'
                //   Switch: '<S119>/Switch1'

                if (rtb_Switch_aa > 90.0) {
                  // Signum: '<S128>/Sign1'
                  if (rtb_Down_c < 0.0) {
                    rtb_Down_c = -1.0;
                  } else if (rtb_Down_c > 0.0) {
                    rtb_Down_c = 1.0;
                  } else if (rtb_Down_c == 0.0) {
                    rtb_Down_c = 0.0;
                  } else {
                    rtb_Down_c = (rtNaN);
                  }

                  rtb_Down_c *= -(rtb_Switch_aa + -90.0) + 90.0;
                  b_nrows = 180;
                } else {
                  b_nrows = 0;
                }

                // Sum: '<S119>/Sum' incorporates:
                //   DataStoreRead: '<S6>/LongitudeGCS'

                rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

                // Sum: '<S115>/Sum1'
                rtb_Switch_aa = rtu_Location->Lat - rtb_Down_c;

                // Switch: '<S129>/Switch' incorporates:
                //   Abs: '<S129>/Abs'
                //   Bias: '<S129>/Bias'
                //   Bias: '<S129>/Bias1'
                //   Constant: '<S129>/Constant2'
                //   Constant: '<S133>/Constant'
                //   Math: '<S129>/Math Function1'
                //   RelationalOperator: '<S133>/Compare'

                if (std::abs(rtb_Sum) > 180.0) {
                  rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S115>/Sum1'
                rtb_Sum = rtu_Location->Lon - rtb_Sum;

                // Switch: '<S125>/Switch' incorporates:
                //   Abs: '<S125>/Abs'
                //   Bias: '<S125>/Bias'
                //   Bias: '<S125>/Bias1'
                //   Constant: '<S125>/Constant2'
                //   Constant: '<S126>/Constant'
                //   Math: '<S125>/Math Function1'
                //   RelationalOperator: '<S126>/Compare'

                if (std::abs(rtb_Switch_aa) > 180.0) {
                  rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                    -180.0;
                }

                // Abs: '<S122>/Abs1'
                rtb_Down = std::abs(rtb_Switch_aa);

                // Switch: '<S122>/Switch' incorporates:
                //   Bias: '<S122>/Bias'
                //   Bias: '<S122>/Bias1'
                //   Constant: '<S118>/Constant'
                //   Constant: '<S118>/Constant1'
                //   Constant: '<S124>/Constant'
                //   Gain: '<S122>/Gain'
                //   Product: '<S122>/Divide1'
                //   RelationalOperator: '<S124>/Compare'
                //   Switch: '<S118>/Switch1'

                if (rtb_Down > 90.0) {
                  // Signum: '<S122>/Sign1'
                  if (rtb_Switch_aa < 0.0) {
                    rtb_Switch_aa = -1.0;
                  } else if (rtb_Switch_aa > 0.0) {
                    rtb_Switch_aa = 1.0;
                  } else if (rtb_Switch_aa == 0.0) {
                    rtb_Switch_aa = 0.0;
                  } else {
                    rtb_Switch_aa = (rtNaN);
                  }

                  rtb_Gain1 = (-(rtb_Down + -90.0) + 90.0) * rtb_Switch_aa;
                  b_nrows = 180;
                } else {
                  rtb_Gain1 = rtb_Switch_aa;
                  b_nrows = 0;
                }

                // Sum: '<S118>/Sum'
                rtb_Sum += static_cast<real_T>(b_nrows);

                // UnitConversion: '<S121>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch_aa = 0.017453292519943295 * rtb_Gain1;

                // UnitConversion: '<S136>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Down_c *= 0.017453292519943295;

                // Trigonometry: '<S137>/Trigonometric Function1'
                rtb_Switch_p = std::sin(rtb_Down_c);

                // Sum: '<S137>/Sum1' incorporates:
                //   Constant: '<S137>/Constant'
                //   Product: '<S137>/Product1'

                rtb_Switch_p = 1.0 -
                  PreemptableMissionModeSelector_ConstB.sqrt_bu *
                  PreemptableMissionModeSelector_ConstB.sqrt_bu * rtb_Switch_p *
                  rtb_Switch_p;

                // Product: '<S135>/Product1' incorporates:
                //   Constant: '<S135>/Constant1'
                //   Sqrt: '<S135>/sqrt'

                rtb_Gain1 = 6.378137E+6 / std::sqrt(rtb_Switch_p);

                // Product: '<S120>/dNorth' incorporates:
                //   Constant: '<S135>/Constant2'
                //   Product: '<S135>/Product3'
                //   Trigonometry: '<S135>/Trigonometric Function1'

                rtb_Switch_p = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Gain1 *
                  PreemptableMissionModeSelector_ConstB.Sum1_c / rtb_Switch_p);

                // Switch: '<S123>/Switch' incorporates:
                //   Abs: '<S123>/Abs'
                //   Bias: '<S123>/Bias'
                //   Bias: '<S123>/Bias1'
                //   Constant: '<S123>/Constant2'
                //   Constant: '<S127>/Constant'
                //   Math: '<S123>/Math Function1'
                //   RelationalOperator: '<S127>/Compare'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                if (std::abs(rtb_Sum) > 180.0) {
                  rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                }

                // Product: '<S120>/dEast' incorporates:
                //   Constant: '<S135>/Constant3'
                //   Product: '<S135>/Product4'
                //   Trigonometry: '<S135>/Trigonometric Function'
                //   Trigonometry: '<S135>/Trigonometric Function2'
                //   UnitConversion: '<S121>/Unit Conversion'

                rtb_Gain1 = 1.0 / rt_atan2d_snf(1.0, rtb_Gain1 * std::cos
                  (rtb_Down_c)) * (0.017453292519943295 * rtb_Sum);

                // Sum: '<S120>/Sum2' incorporates:
                //   Product: '<S120>/x*cos'
                //   Product: '<S120>/y*sin'

                rtb_Down = rtb_Gain1 * 0.0 + rtb_Switch_p;

                // Sum: '<S120>/Sum3' incorporates:
                //   Product: '<S120>/x*sin'
                //   Product: '<S120>/y*cos'

                rtb_Abs1_jo = rtb_Gain1 - rtb_Switch_p * 0.0;

                // Sum: '<S115>/Sum' incorporates:
                //   DataStoreRead: '<S6>/AltitudeGCS'
                //   Gain: '<S6>/inverse'

                rtb_Switch_aa = rtu_Location->Alt + -AltitudeGCS;

                // Gain: '<S6>/Up2Down'
                rtb_Switch_p = -rtu_StartPosition->Alt;

                // Sum: '<S6>/Sum' incorporates:
                //   UnaryMinus: '<S115>/Ze2height'

                rtb_Param4_e = -rtb_Switch_aa + rtb_Switch_p;

                // Gain: '<S114>/Gain1'
                rtb_Switch_e = 0.017453292519943295 * rtu_Location->degHDG;

                // Outputs for Triggered SubSystem: '<S6>/WayPointGenerator' incorporates:
                //   TriggerPort: '<S117>/Trigger'

                zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                                   &localZCE->WayPointGenerator_Trig_ZCE_a,
                                   (localDW->MemoryTriggerWP_PreviousInput_d));
                if (zcEvent != NO_ZCEVENT) {
                  // Product: '<S117>/ProductScanWidth' incorporates:
                  //   DataTypeConversion: '<S6>/Param3'

                  rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) *
                    static_cast<real_T>(*rtu_MissionUAV);

                  // Reshape: '<S117>/ReshapeRowVec'
                  rtb_ReshapeRowVec[0] = rtb_Down;
                  rtb_ReshapeRowVec[1] = rtb_Abs1_jo;
                  rtb_ReshapeRowVec[2] = rtb_Param4_e;

                  // SignalConversion generated from: '<S117>/RotateATMissionHdg' incorporates:
                  //   Constant: '<S117>/Zero'

                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[0] =
                    rtb_Switch_e;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[1] = 0.0;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[2] = 0.0;
                  PreemptableMissionModeSelector_RotateATMissionHdg
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b,
                     &localB->RotateATMissionHdg_ba);

                  // MATLAB Function: '<S117>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S6>/Param2'

                  rtb_Switch_aa = std::ceil(static_cast<real_T>
                    (rtu_Parameters->Param2) / rtb_Switch_aa);
                  rtb_Sum = static_cast<real_T>(rtu_Parameters->Param2) /
                    rtb_Switch_aa;
                  connectionObj.FlightPathAngleLimit[0] = -0.175;
                  connectionObj.FlightPathAngleLimit[1] = 0.175;
                  connectionObj.MaxRollAngle = 0.29670597283903605;
                  connectionObj.AirSpeed = 35.0;
                  connectionObj.MinTurningRadius = 408.85657731051754;
                  b_nrows = static_cast<int32_T>(rtb_Switch_aa * 2.0);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (CheckPoints->size[0] * CheckPoints->size[1]);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  CheckPoints->size[0] = b_nrows;
                  CheckPoints->size[1] = 4;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (CheckPoints, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S117>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S6>/Param1'

                  ibmat = static_cast<int32_T>(static_cast<int32_T>(b_nrows << 2)
                    - 1);
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       ibmat; rtb_ClockwiseRotation_n++) {
                    CheckPoints->data[rtb_ClockwiseRotation_n] = 0.0;
                  }

                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa)
                        - 1); rtb_ClockwiseRotation_n = static_cast<int32_T>
                       (rtb_ClockwiseRotation_n + 1)) {
                    if (rt_remd_snf(static_cast<real_T>(rtb_ClockwiseRotation_n)
                                    + 1.0, 2.0) == 1.0) {
                      b_nrows = static_cast<int32_T>(static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 1) << 1);
                      rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n)
                                     + 1.0) - 1.0) * rtb_Sum;
                      CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                        rtb_Switch;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + CheckPoints->size[0]) - 2)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] <<
                        1)) - 2)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 2)] = 1.5707963267948966;
                      CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                        rtb_Switch;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + CheckPoints->size[0]) - 1)] =
                        static_cast<real_T>(rtu_Parameters->Param1);
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] <<
                        1)) - 1)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 1)] = 1.5707963267948966;
                    } else {
                      b_nrows = static_cast<int32_T>(static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 1) << 1);
                      rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n)
                                     + 1.0) - 1.0) * rtb_Sum;
                      CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                        rtb_Switch;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + CheckPoints->size[0]) - 2)] =
                        static_cast<real_T>(rtu_Parameters->Param1);
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] <<
                        1)) - 2)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 2)] = -1.5707963267948966;
                      CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                        rtb_Switch;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + CheckPoints->size[0]) - 1)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] <<
                        1)) - 1)] = 0.0;
                      CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 1)] = -1.5707963267948966;
                    }
                  }

                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  dummyWayPoint->size[0] = 1;
                  dummyWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  dummyWayPoint->data[0] = 0.0;
                  dummyWayPoint->data[1] = 0.0;
                  dummyWayPoint->data[2] = 0.0;
                  for (nrowx = 0; nrowx <= static_cast<int32_T>
                       (CheckPoints->size[0] - 2); nrowx = static_cast<int32_T>
                       (nrowx + 1)) {
                    LUp[0] = CheckPoints->data[nrowx];
                    LDp[0] = CheckPoints->data[static_cast<int32_T>(nrowx + 1)];
                    LUp[1] = CheckPoints->data[static_cast<int32_T>(nrowx +
                      CheckPoints->size[0])];
                    LDp[1] = CheckPoints->data[static_cast<int32_T>
                      (static_cast<int32_T>(nrowx + CheckPoints->size[0]) + 1)];
                    LUp[2] = CheckPoints->data[static_cast<int32_T>(nrowx +
                      static_cast<int32_T>(CheckPoints->size[0] << 1))];
                    LDp[2] = CheckPoints->data[static_cast<int32_T>
                      (static_cast<int32_T>(nrowx + static_cast<int32_T>
                        (CheckPoints->size[0] << 1)) + 1)];
                    LUp[3] = CheckPoints->data[static_cast<int32_T>(nrowx +
                      static_cast<int32_T>(CheckPoints->size[0] * 3))];
                    LDp[3] = CheckPoints->data[static_cast<int32_T>
                      (static_cast<int32_T>(nrowx + static_cast<int32_T>
                        (CheckPoints->size[0] * 3)) + 1)];
                    PreemptableMissionModeSelector_genSegWP_la(&connectionObj,
                      LUp, LDp, 100.0, segWayPoints, localB);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);
                    dummyWayPoint_0->size[0] = static_cast<int32_T>
                      (dummyWayPoint->size[0] + segWayPoints->size[0]);
                    dummyWayPoint_0->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (dummyWayPoint_0, rtb_ClockwiseRotation_n);
                    ibmat = dummyWayPoint->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint_0->size[0] * b_nrows))] =
                          dummyWayPoint->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint->size[0] * b_nrows))];
                      }
                    }

                    ibmat = segWayPoints->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                          (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                            dummyWayPoint->size[0]) + static_cast<int32_T>
                           (dummyWayPoint_0->size[0] * b_nrows))] =
                          segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (segWayPoints->size[0] * b_nrows))];
                      }
                    }

                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (dummyWayPoint->size[0] * dummyWayPoint->size[1]);
                    dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                    dummyWayPoint->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (dummyWayPoint, rtb_ClockwiseRotation_n);
                    ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                    for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                         b_nrows++) {
                      dummyWayPoint->data[b_nrows] = dummyWayPoint_0->
                        data[b_nrows];
                    }
                  }

                  LUp[0] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] - 1)];
                  LDp[0] = CheckPoints->data[0];
                  LUp[1] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(CheckPoints->size[0] +
                      CheckPoints->size[0]) - 1)];
                  LDp[1] = CheckPoints->data[CheckPoints->size[0]];
                  LUp[2] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(CheckPoints->size[0] +
                      static_cast<int32_T>(CheckPoints->size[0] << 1)) - 1)];
                  LDp[2] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] << 1)];
                  LUp[3] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(CheckPoints->size[0] +
                      static_cast<int32_T>(CheckPoints->size[0] * 3)) - 1)];
                  LDp[3] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] * 3)];
                  PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp,
                    LDp, 100.0, segWayPoints, localB);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  dummyWayPoint_0->size[0] = static_cast<int32_T>
                    (dummyWayPoint->size[0] + segWayPoints->size[0]);
                  dummyWayPoint_0->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint_0, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  ibmat = dummyWayPoint->size[0];
                  loop_ub = segWayPoints->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      dummyWayPoint_0->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * b_nrows))] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] * b_nrows))];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(loop_ub - 1);
                         rtb_ClockwiseRotation_n++) {
                      dummyWayPoint_0->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          dummyWayPoint->size[0]) + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * b_nrows))] =
                        segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }
                  }

                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                  dummyWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                  for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                       b_nrows++) {
                    dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
                  }

                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint_2->size[0] * dummyWayPoint_2->size[1]);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  dummyWayPoint_2->size[0] = dummyWayPoint->size[0];
                  dummyWayPoint_2->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint_2, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  loop_ub = static_cast<int32_T>(static_cast<int32_T>
                    (dummyWayPoint->size[0] * dummyWayPoint->size[1]) - 1);
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       loop_ub; rtb_ClockwiseRotation_n++) {
                    dummyWayPoint_2->data[rtb_ClockwiseRotation_n] =
                      dummyWayPoint->data[rtb_ClockwiseRotation_n];
                  }

                  PreemptableMissionModeSelector_repmat(dummyWayPoint_2, std::
                    ceil(10240.0 / static_cast<real_T>(dummyWayPoint->size[0])),
                    dummyWayPoint);
                  nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
                  nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
                  for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<
                       int32_T>(b_nrows + 1)) {
                    dummyWayPoint->data[b_nrows] = dummyWayPoint->data[
                      static_cast<int32_T>(b_nrows + 1)];
                  }

                  for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<
                       int32_T>(b_nrows + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                      dummyWayPoint->size[0])] = dummyWayPoint->data[
                      static_cast<int32_T>(static_cast<int32_T>(b_nrows +
                      dummyWayPoint->size[0]) + 1)];
                  }

                  for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<
                       int32_T>(b_nrows + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                      static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                      dummyWayPoint->data[static_cast<int32_T>
                      (static_cast<int32_T>(b_nrows + static_cast<int32_T>
                        (dummyWayPoint->size[0] << 1)) + 1)];
                  }

                  // Reshape: '<S6>/Reshape2Row' incorporates:
                  //   Memory: '<S6>/MemoryPrevRelPos'

                  rtb_Reshape_i[0] = localDW->MemoryPrevRelPos_PreviousInput_n[1];
                  rtb_Reshape_i[1] = localDW->MemoryPrevRelPos_PreviousInput_n[0];
                  rtb_Reshape_i[2] = localDW->MemoryPrevRelPos_PreviousInput_n[2];

                  // Product: '<S117>/RotateRelPrevPos' incorporates:
                  //   MATLABSystem: '<S117>/RotateATMissionHdg'

                  rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtb_Reshape_i,
                    localB->RotateATMissionHdg_ba.RotateATMissionHdg,
                    rtb_startPose_h);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  LDp[0] = rtb_startPose_h[0];
                  LDp[1] = rtb_startPose_h[1];
                  LDp[2] = rtb_startPose_h[2];
                  LDp[3] = 1.5707963267948966;
                  LUp[0] = CheckPoints->data[0];
                  LUp[1] = CheckPoints->data[CheckPoints->size[0]];
                  LUp[2] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] << 1)];
                  LUp[3] = CheckPoints->data[static_cast<int32_T>
                    (CheckPoints->size[0] * 3)];
                  PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LDp,
                    LUp, 100.0, segWayPoints, localB);
                  if (1 > nrows) {
                    nrowx = -1;
                  }

                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (initWayPoint->size[0] * initWayPoint->size[1]);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  initWayPoint->size[0] = static_cast<int32_T>
                    (static_cast<int32_T>(segWayPoints->size[0] + nrowx) + 1);
                  initWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (initWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S117>/WayPointGenerator'
                  ibmat = segWayPoints->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      initWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (initWayPoint->size[0] * b_nrows))] =
                        segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         nrowx; rtb_ClockwiseRotation_n++) {
                      initWayPoint->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          segWayPoints->size[0]) + static_cast<int32_T>
                         (initWayPoint->size[0] * b_nrows))] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] * b_nrows))];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                         10240; rtb_ClockwiseRotation_n++) {
                      localB->WayPoint[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>(10240 *
                          b_nrows))] = initWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (initWayPoint->size[0] * b_nrows))];
                    }
                  }

                  // MATLAB Function: '<S117>/biasWayPoint'
                  for (b_nrows = 0; b_nrows < 10240; b_nrows++) {
                    localB->RotateIndivWayPoint[b_nrows] = localB->
                      WayPoint[b_nrows] + rtu_StartPosition->Lon;
                    localB->RotateIndivWayPoint[static_cast<int32_T>(b_nrows +
                      10240)] = localB->WayPoint[static_cast<int32_T>(b_nrows +
                      10240)];
                    localB->RotateIndivWayPoint[static_cast<int32_T>(b_nrows +
                      20480)] = localB->WayPoint[static_cast<int32_T>(b_nrows +
                      20480)];
                  }

                  // Product: '<S117>/RotateIndivWayPoint' incorporates:
                  //   MATLABSystem: '<S117>/RotateATMissionHdg'

                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                         10240; rtb_ClockwiseRotation_n++) {
                      ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                        static_cast<int32_T>(10240 * b_nrows));
                      localB->WayPoint[ibmat] = 0.0;
                      localB->WayPoint[ibmat] +=
                        localB->RotateATMissionHdg_ba.RotateATMissionHdg[
                        static_cast<int32_T>(3 * b_nrows)] *
                        localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                      localB->WayPoint[ibmat] +=
                        localB->RotateATMissionHdg_ba.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        1)] * localB->RotateIndivWayPoint[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 10240)];
                      localB->WayPoint[ibmat] +=
                        localB->RotateATMissionHdg_ba.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        2)] * localB->RotateIndivWayPoint[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 20480)];
                    }
                  }

                  // MATLAB Function: '<S117>/biasNED'
                  PreemptableMissionModeSelector_biasNED_l(rtb_ReshapeRowVec,
                    localB->WayPoint, localB->nedWayPoint_a,
                    &localB->sf_biasNED_l);
                }

                // End of Outputs for SubSystem: '<S6>/WayPointGenerator'
                PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
                  localB->nedWayPoint_a, 200.0, &localB->WaypointFollower_ba,
                  &localDW->WaypointFollower_ba);

                // DataTypeConversion: '<S6>/Cast To Double' incorporates:
                //   Constant: '<S6>/LookAheadDis'
                //   MATLAB Function: '<S117>/WayPointGenerator'
                //   Memory: '<S6>/MemoryTriggerWP'

                *rty_thisTaskStatus = static_cast<real_T>
                  (localB->WaypointFollower_ba.WaypointFollower_o5);

                // Sum: '<S116>/Sum' incorporates:
                //   DataStoreRead: '<S6>/PrevAltitudeGCS'
                //   Gain: '<S6>/PrevInverse'

                rtb_Switch = rtu_PrevLocation->Alt + -AltitudeGCS;

                // Product: '<S6>/FrontEast' incorporates:
                //   Trigonometry: '<S6>/FrontSin'

                rtb_Down_c = std::sin(rtb_Switch_e) * rtu_StartPosition->Lat;

                // Product: '<S6>/FrontNorth' incorporates:
                //   Trigonometry: '<S6>/FrontCos'

                rtb_Gain1 = std::cos(rtb_Switch_e) * rtu_StartPosition->Lat;

                // BusCreator: '<S6>/GuidanceCMDBusCreator' incorporates:
                //   DataTypeConversion: '<S6>/Param4'
                //   Gain: '<S6>/Down2Height'

                rty_GuidanceCmds->Height =
                  -localB->WaypointFollower_ba.WaypointFollower_o1[2];
                rty_GuidanceCmds->AirSpeed = static_cast<real_T>
                  (rtu_Parameters->Param4);
                rty_GuidanceCmds->HeadingAngle =
                  localB->WaypointFollower_ba.WaypointFollower_o2;

                // Switch: '<S153>/Switch' incorporates:
                //   Abs: '<S153>/Abs'
                //   Bias: '<S153>/Bias'
                //   Bias: '<S153>/Bias1'
                //   Constant: '<S153>/Constant2'
                //   Constant: '<S154>/Constant'
                //   DataStoreRead: '<S6>/PrevLatitudeGCS'
                //   Math: '<S153>/Math Function1'
                //   RelationalOperator: '<S154>/Compare'

                if (std::abs(LatitudeGCS) > 180.0) {
                  rtb_Switch_p = rt_modd_snf(LatitudeGCS + 180.0, 360.0) +
                    -180.0;
                } else {
                  rtb_Switch_p = LatitudeGCS;
                }

                // Abs: '<S150>/Abs1'
                rtb_Switch_aa = std::abs(rtb_Switch_p);

                // Switch: '<S150>/Switch' incorporates:
                //   Bias: '<S150>/Bias'
                //   Bias: '<S150>/Bias1'
                //   Constant: '<S141>/Constant'
                //   Constant: '<S141>/Constant1'
                //   Constant: '<S152>/Constant'
                //   Gain: '<S150>/Gain'
                //   Product: '<S150>/Divide1'
                //   RelationalOperator: '<S152>/Compare'
                //   Switch: '<S141>/Switch1'

                if (rtb_Switch_aa > 90.0) {
                  // Signum: '<S150>/Sign1'
                  if (rtb_Switch_p < 0.0) {
                    rtb_Switch_p = -1.0;
                  } else if (rtb_Switch_p > 0.0) {
                    rtb_Switch_p = 1.0;
                  } else if (rtb_Switch_p == 0.0) {
                    rtb_Switch_p = 0.0;
                  } else {
                    rtb_Switch_p = (rtNaN);
                  }

                  rtb_Switch_p *= -(rtb_Switch_aa + -90.0) + 90.0;
                  b_nrows = 180;
                } else {
                  b_nrows = 0;
                }

                // Sum: '<S141>/Sum' incorporates:
                //   DataStoreRead: '<S6>/PrevLongitudeGCS'

                rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

                // Sum: '<S116>/Sum1'
                rtb_Switch_aa = rtu_PrevLocation->Lat - rtb_Switch_p;

                // Switch: '<S151>/Switch' incorporates:
                //   Abs: '<S151>/Abs'
                //   Bias: '<S151>/Bias'
                //   Bias: '<S151>/Bias1'
                //   Constant: '<S151>/Constant2'
                //   Constant: '<S155>/Constant'
                //   Math: '<S151>/Math Function1'
                //   RelationalOperator: '<S155>/Compare'

                if (std::abs(rtb_Sum) > 180.0) {
                  rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S116>/Sum1'
                rtb_Sum = rtu_PrevLocation->Lon - rtb_Sum;

                // Switch: '<S147>/Switch' incorporates:
                //   Abs: '<S147>/Abs'
                //   Bias: '<S147>/Bias'
                //   Bias: '<S147>/Bias1'
                //   Constant: '<S147>/Constant2'
                //   Constant: '<S148>/Constant'
                //   Math: '<S147>/Math Function1'
                //   RelationalOperator: '<S148>/Compare'

                if (std::abs(rtb_Switch_aa) > 180.0) {
                  rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                    -180.0;
                }

                // Abs: '<S144>/Abs1'
                rtb_SumInitEast_j = std::abs(rtb_Switch_aa);

                // Switch: '<S144>/Switch' incorporates:
                //   Bias: '<S144>/Bias'
                //   Bias: '<S144>/Bias1'
                //   Constant: '<S140>/Constant'
                //   Constant: '<S140>/Constant1'
                //   Constant: '<S146>/Constant'
                //   Gain: '<S144>/Gain'
                //   Product: '<S144>/Divide1'
                //   RelationalOperator: '<S146>/Compare'
                //   Switch: '<S140>/Switch1'

                if (rtb_SumInitEast_j > 90.0) {
                  // Signum: '<S144>/Sign1'
                  if (rtb_Switch_aa < 0.0) {
                    rtb_Switch_aa = -1.0;
                  } else if (rtb_Switch_aa > 0.0) {
                    rtb_Switch_aa = 1.0;
                  } else if (rtb_Switch_aa == 0.0) {
                    rtb_Switch_aa = 0.0;
                  } else {
                    rtb_Switch_aa = (rtNaN);
                  }

                  rtb_Switch_aa *= -(rtb_SumInitEast_j + -90.0) + 90.0;
                  b_nrows = 180;
                } else {
                  b_nrows = 0;
                }

                // Sum: '<S140>/Sum'
                rtb_Sum_as = static_cast<real_T>(b_nrows) + rtb_Sum;

                // UnitConversion: '<S158>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch_p *= 0.017453292519943295;

                // Trigonometry: '<S159>/Trigonometric Function1'
                rtb_Sum = std::sin(rtb_Switch_p);

                // Sum: '<S159>/Sum1' incorporates:
                //   Constant: '<S159>/Constant'
                //   Product: '<S159>/Product1'

                rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_a *
                  PreemptableMissionModeSelector_ConstB.sqrt_a * rtb_Sum *
                  rtb_Sum;

                // Product: '<S157>/Product1' incorporates:
                //   Constant: '<S157>/Constant1'
                //   Sqrt: '<S157>/sqrt'

                rtb_SumInitEast_j = 6.378137E+6 / std::sqrt(rtb_Sum);

                // Product: '<S157>/Product4' incorporates:
                //   Trigonometry: '<S157>/Trigonometric Function'

                rtb_Switch_p = rtb_SumInitEast_j * std::cos(rtb_Switch_p);

                // Product: '<S142>/dNorth' incorporates:
                //   Constant: '<S157>/Constant2'
                //   Product: '<S157>/Product3'
                //   Trigonometry: '<S157>/Trigonometric Function1'
                //   UnitConversion: '<S143>/Unit Conversion'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_SumInitEast_j = 0.017453292519943295 * rtb_Switch_aa /
                  rt_atan2d_snf(1.0, rtb_SumInitEast_j *
                                PreemptableMissionModeSelector_ConstB.Sum1_l /
                                rtb_Sum);

                // Switch: '<S145>/Switch' incorporates:
                //   Abs: '<S145>/Abs'
                //   Bias: '<S145>/Bias'
                //   Bias: '<S145>/Bias1'
                //   Constant: '<S145>/Constant2'
                //   Constant: '<S149>/Constant'
                //   Math: '<S145>/Math Function1'
                //   RelationalOperator: '<S149>/Compare'

                if (std::abs(rtb_Sum_as) > 180.0) {
                  rtb_Sum_as = rt_modd_snf(rtb_Sum_as + 180.0, 360.0) + -180.0;
                }

                // Product: '<S142>/dEast' incorporates:
                //   Constant: '<S157>/Constant3'
                //   Trigonometry: '<S157>/Trigonometric Function2'
                //   UnitConversion: '<S143>/Unit Conversion'

                rtb_Sum = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_p) *
                  (0.017453292519943295 * rtb_Sum_as);

                // Sum: '<S142>/Sum2' incorporates:
                //   Product: '<S142>/x*cos'
                //   Product: '<S142>/y*sin'

                rtb_Switch_aa = rtb_Sum * 0.0 + rtb_SumInitEast_j;

                // Sum: '<S142>/Sum3' incorporates:
                //   Product: '<S142>/x*sin'
                //   Product: '<S142>/y*cos'

                rtb_SumInitEast_j = rtb_Sum - rtb_SumInitEast_j * 0.0;

                // Product: '<S6>/RightNorth' incorporates:
                //   Bias: '<S6>/Rotate90deg'
                //   Trigonometry: '<S6>/RightCos'

                rtb_Sum_as = std::cos(rtb_Switch_e + 1.5707963267948966) *
                  rtu_StartPosition->Lon;

                // Product: '<S6>/RightEast' incorporates:
                //   Bias: '<S6>/Rotate90deg'
                //   Trigonometry: '<S6>/RightSin'

                rtb_Sum = std::sin(rtb_Switch_e + 1.5707963267948966) *
                  rtu_StartPosition->Lon;

                // Sum: '<S6>/SumHeight' incorporates:
                //   UnaryMinus: '<S116>/Ze2height'

                rtb_Switch_p = rtu_StartPosition->Alt + rtb_Switch;

                // Reshape: '<S6>/Reshape' incorporates:
                //   Constant: '<S6>/InitialFlightPathAngle'
                //   Constant: '<S6>/InitialRollAngle'
                //   Constant: '<S6>/InitialRollAngleRate'
                //   DataTypeConversion: '<S6>/Param4'
                //   Sum: '<S6>/SumInitEast'
                //   Sum: '<S6>/SumInitNorth'

                rty_InitialState[0] = (rtb_Switch_aa + rtb_Sum_as) + rtb_Gain1;
                rty_InitialState[1] = (rtb_SumInitEast_j + rtb_Down_c) + rtb_Sum;
                rty_InitialState[2] = rtb_Switch_p;
                rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
                rty_InitialState[4] = rtb_Switch_e;
                rty_InitialState[5] = 0.0;
                rty_InitialState[6] = 0.0;
                rty_InitialState[7] = 0.0;

                // Update for Memory: '<S6>/MemoryPrevRelPos' incorporates:
                //   Sum: '<S6>/RelPrevPos'
                //   UnaryMinus: '<S116>/Ze2height'

                localDW->MemoryPrevRelPos_PreviousInput_n[0] = rtb_Switch_aa -
                  rtb_Down;
                localDW->MemoryPrevRelPos_PreviousInput_n[1] = rtb_SumInitEast_j
                  - rtb_Abs1_jo;
                localDW->MemoryPrevRelPos_PreviousInput_n[2] = -rtb_Switch -
                  rtb_Param4_e;

                // Update for Memory: '<S6>/MemoryTriggerWP' incorporates:
                //   Constant: '<S6>/TirggerWayPointGen'

                localDW->MemoryTriggerWP_PreviousInput_d = 1.0;
              }
            } else {
              sf_internal_predicateOutput = ((*rtu_mode == 3) || (*rtu_mode ==
                33));
              if (sf_internal_predicateOutput) {
                localDW->is_GuidanceLogic =
                  PreemptableMissionModeSelector_IN_RunWayNav;

                // Switch: '<S100>/Switch' incorporates:
                //   Abs: '<S100>/Abs'
                //   Bias: '<S100>/Bias'
                //   Bias: '<S100>/Bias1'
                //   Constant: '<S100>/Constant2'
                //   Constant: '<S101>/Constant'
                //   DataStoreRead: '<S5>/LatitudeGCS'
                //   Math: '<S100>/Math Function1'
                //   RelationalOperator: '<S101>/Compare'

                if (std::abs(LatitudeGCS) > 180.0) {
                  rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
                } else {
                  rtb_Down = LatitudeGCS;
                }

                // Abs: '<S97>/Abs1'
                rtb_Switch_aa = std::abs(rtb_Down);

                // Switch: '<S97>/Switch' incorporates:
                //   Bias: '<S97>/Bias'
                //   Bias: '<S97>/Bias1'
                //   Constant: '<S88>/Constant'
                //   Constant: '<S88>/Constant1'
                //   Constant: '<S99>/Constant'
                //   Gain: '<S97>/Gain'
                //   Product: '<S97>/Divide1'
                //   RelationalOperator: '<S99>/Compare'
                //   Switch: '<S88>/Switch1'

                if (rtb_Switch_aa > 90.0) {
                  // Signum: '<S97>/Sign1'
                  if (rtb_Down < 0.0) {
                    rtb_Down = -1.0;
                  } else if (rtb_Down > 0.0) {
                    rtb_Down = 1.0;
                  } else if (rtb_Down == 0.0) {
                    rtb_Down = 0.0;
                  } else {
                    rtb_Down = (rtNaN);
                  }

                  rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
                  b_nrows = 180;
                } else {
                  b_nrows = 0;
                }

                // Sum: '<S88>/Sum' incorporates:
                //   DataStoreRead: '<S5>/LongitudeGCS'

                rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

                // Sum: '<S85>/Sum1'
                rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

                // Switch: '<S98>/Switch' incorporates:
                //   Abs: '<S98>/Abs'
                //   Bias: '<S98>/Bias'
                //   Bias: '<S98>/Bias1'
                //   Constant: '<S102>/Constant'
                //   Constant: '<S98>/Constant2'
                //   Math: '<S98>/Math Function1'
                //   RelationalOperator: '<S102>/Compare'

                if (std::abs(rtb_Sum) > 180.0) {
                  rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S85>/Sum1'
                rtb_Sum = rtu_Location->Lon - rtb_Sum;

                // Switch: '<S94>/Switch' incorporates:
                //   Abs: '<S94>/Abs'
                //   Bias: '<S94>/Bias'
                //   Bias: '<S94>/Bias1'
                //   Constant: '<S94>/Constant2'
                //   Constant: '<S95>/Constant'
                //   Math: '<S94>/Math Function1'
                //   RelationalOperator: '<S95>/Compare'

                if (std::abs(rtb_Switch_aa) > 180.0) {
                  rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                    -180.0;
                }

                // Abs: '<S91>/Abs1'
                rtb_Down_c = std::abs(rtb_Switch_aa);

                // Switch: '<S91>/Switch' incorporates:
                //   Bias: '<S91>/Bias'
                //   Bias: '<S91>/Bias1'
                //   Constant: '<S87>/Constant'
                //   Constant: '<S87>/Constant1'
                //   Constant: '<S93>/Constant'
                //   Gain: '<S91>/Gain'
                //   Product: '<S91>/Divide1'
                //   RelationalOperator: '<S93>/Compare'
                //   Switch: '<S87>/Switch1'

                if (rtb_Down_c > 90.0) {
                  // Signum: '<S91>/Sign1'
                  if (rtb_Switch_aa < 0.0) {
                    rtb_Switch_aa = -1.0;
                  } else if (rtb_Switch_aa > 0.0) {
                    rtb_Switch_aa = 1.0;
                  } else if (rtb_Switch_aa == 0.0) {
                    rtb_Switch_aa = 0.0;
                  } else {
                    rtb_Switch_aa = (rtNaN);
                  }

                  rtb_Down_c = (-(rtb_Down_c + -90.0) + 90.0) * rtb_Switch_aa;
                  b_nrows = 180;
                } else {
                  rtb_Down_c = rtb_Switch_aa;
                  b_nrows = 0;
                }

                // Sum: '<S87>/Sum'
                rtb_Sum += static_cast<real_T>(b_nrows);

                // UnitConversion: '<S90>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch_aa = 0.017453292519943295 * rtb_Down_c;

                // UnitConversion: '<S105>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Down *= 0.017453292519943295;

                // Trigonometry: '<S106>/Trigonometric Function1'
                rtb_Abs1_jo = std::sin(rtb_Down);

                // Sum: '<S106>/Sum1' incorporates:
                //   Constant: '<S106>/Constant'
                //   Product: '<S106>/Product1'

                rtb_Abs1_jo = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_j
                  * PreemptableMissionModeSelector_ConstB.sqrt_j * rtb_Abs1_jo *
                  rtb_Abs1_jo;

                // Product: '<S104>/Product1' incorporates:
                //   Constant: '<S104>/Constant1'
                //   Sqrt: '<S104>/sqrt'

                rtb_Down_c = 6.378137E+6 / std::sqrt(rtb_Abs1_jo);

                // Product: '<S89>/dNorth' incorporates:
                //   Constant: '<S104>/Constant2'
                //   Product: '<S104>/Product3'
                //   Trigonometry: '<S104>/Trigonometric Function1'

                rtb_Abs1_jo = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Down_c *
                  PreemptableMissionModeSelector_ConstB.Sum1_f / rtb_Abs1_jo);

                // Switch: '<S92>/Switch' incorporates:
                //   Abs: '<S92>/Abs'
                //   Bias: '<S92>/Bias'
                //   Bias: '<S92>/Bias1'
                //   Constant: '<S92>/Constant2'
                //   Constant: '<S96>/Constant'
                //   Math: '<S92>/Math Function1'
                //   RelationalOperator: '<S96>/Compare'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                if (std::abs(rtb_Sum) > 180.0) {
                  rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                }

                // Product: '<S89>/dEast' incorporates:
                //   Constant: '<S104>/Constant3'
                //   Product: '<S104>/Product4'
                //   Trigonometry: '<S104>/Trigonometric Function'
                //   Trigonometry: '<S104>/Trigonometric Function2'
                //   UnitConversion: '<S90>/Unit Conversion'

                rtb_Down_c = 1.0 / rt_atan2d_snf(1.0, rtb_Down_c * std::cos
                  (rtb_Down)) * (0.017453292519943295 * rtb_Sum);

                // Sum: '<S85>/Sum' incorporates:
                //   DataStoreRead: '<S5>/AltitudeGCS'
                //   Gain: '<S5>/inverse'

                rtb_Switch_e = rtu_Location->Alt + -AltitudeGCS;

                // Gain: '<S84>/Gain1'
                rtb_Gain1 = 0.017453292519943295 * rtu_Location->degHDG;

                // Outputs for Triggered SubSystem: '<S5>/WayPointGenerator' incorporates:
                //   TriggerPort: '<S86>/Trigger'

                zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                                   &localZCE->WayPointGenerator_Trig_ZCE_e,
                                   (localDW->MemoryTriggerWP_PreviousInput_b));
                if (zcEvent != NO_ZCEVENT) {
                  // Product: '<S86>/IndivRunwayRotAng' incorporates:
                  //   DataTypeConversion: '<S5>/Param2'
                  //   DataTypeConversion: '<S5>/Param5'
                  //   Gain: '<S109>/Gain1'

                  rtb_Switch = 0.017453292519943295 * static_cast<real_T>
                    (rtu_Parameters->Param2) * static_cast<real_T>
                    (rtu_Parameters->Param5);

                  // DataTypeConversion: '<S86>/Cast To Double'
                  rtb_Param4_e = static_cast<real_T>(*rtu_FormationIDX);

                  // MATLAB Function: '<S86>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S5>/Param3'

                  PreemptableMissionModeSelector_uavDubinsConnection_uavDubinsConnection
                    (&connectionObj);
                  LUp[0] = 0.0;
                  rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) /
                    2.0;
                  LUp[1] = rtb_Switch_aa;
                  LUp[2] = 0.0;
                  LUp[3] = 1.5707963267948966;
                  LDp[0] = 0.0;
                  rtb_Sum = -static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
                  LDp[1] = rtb_Sum;
                  LDp[2] = 0.0;
                  LDp[3] = 1.5707963267948966;
                  PreemptableMissionModeSelector_uavDubinsConnection_connect
                    (&connectionObj, LUp, LDp, localB->pathSegObj.data,
                     &localB->pathSegObj.size, a__1_data, &b_nrows, localB);
                  PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate
                    (localB->pathSegObj.data[0].StartPose,
                     localB->pathSegObj.data[0].GoalPose,
                     localB->pathSegObj.data[0].FlightPathAngle,
                     localB->pathSegObj.data[0].AirSpeed,
                     localB->pathSegObj.data[0].MinTurningRadius,
                     localB->pathSegObj.data[0].HelixRadius,
                     localB->pathSegObj.data[0].MotionTypes,
                     localB->pathSegObj.data[0].MotionLengths,
                     localB->pathSegObj.data[0].Length, localB->pathSegObj.data
                     [0].Length / 2.0, midpose_data, midpose_size);
                  rtb_startPose_f[0] = 0.0;
                  rtb_Down = (localB->pathSegObj.data[0].Length +
                              static_cast<real_T>(rtu_Parameters->Param3)) / 3.0
                    - localB->pathSegObj.data[0].Length / 2.0;
                  rtb_startPose_f[1] = rtb_Switch_aa - rtb_Down;
                  rtb_startPose_f[2] = 0.0;
                  rtb_startPose_f[3] = 1.5707963267948966;
                  ende[0] = 0.0;
                  ende[1] = rtb_Down + rtb_Sum;
                  ende[2] = 0.0;
                  ende[3] = 1.5707963267948966;
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (initWayPoint->size[0] * initWayPoint->size[1]);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  initWayPoint->size[0] = 1;
                  initWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (initWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S86>/WayPointGenerator' incorporates:
                  //   Constant: '<S86>/Three'
                  //   Math: '<S86>/ModRunWayPose'

                  initWayPoint->data[0] = 0.0;
                  initWayPoint->data[1] = 0.0;
                  initWayPoint->data[2] = 0.0;
                  switch (static_cast<int32_T>(rt_modd_snf(rtb_Param4_e, 3.0)))
              {
                   case 0:
                    PreemptableMissionModeSelector_genSegWP(&connectionObj,
                      rtb_startPose_f, LUp, 100.0, segWayPoints, localB);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (initWayPoint->size[0] * initWayPoint->size[1]);
                    initWayPoint->size[0] = static_cast<int32_T>
                      (segWayPoints->size[0] + 1);
                    initWayPoint->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (initWayPoint, rtb_ClockwiseRotation_n);
                    ibmat = segWayPoints->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      initWayPoint->data[static_cast<int32_T>(initWayPoint->
                        size[0] * b_nrows)] = 0.0;
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        initWayPoint->data[static_cast<int32_T>
                          (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                            static_cast<int32_T>(initWayPoint->size[0] * b_nrows))
                           + 1)] = segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (segWayPoints->size[0] * b_nrows))];
                      }
                    }
                    break;

                   case 1:
                    rtb_startPose_f[0] = midpose_data[0];
                    rtb_startPose_f[1] = midpose_data[midpose_size[0]];
                    rtb_startPose_f[2] = midpose_data[static_cast<int32_T>
                      (midpose_size[0] << 1)];
                    rtb_startPose_f[3] = midpose_data[static_cast<int32_T>
                      (midpose_size[0] * 3)];
                    PreemptableMissionModeSelector_genSegWP(&connectionObj,
                      &midpose_data[0], LDp, 100.0, segWayPoints, localB);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (initWayPoint->size[0] * initWayPoint->size[1]);
                    initWayPoint->size[0] = static_cast<int32_T>
                      (segWayPoints->size[0] + 1);
                    initWayPoint->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (initWayPoint, rtb_ClockwiseRotation_n);
                    ibmat = segWayPoints->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      initWayPoint->data[static_cast<int32_T>(initWayPoint->
                        size[0] * b_nrows)] = 0.0;
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        initWayPoint->data[static_cast<int32_T>
                          (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                            static_cast<int32_T>(initWayPoint->size[0] * b_nrows))
                           + 1)] = segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (segWayPoints->size[0] * b_nrows))];
                      }
                    }
                    break;

                   case 2:
                    rtb_startPose_f[0] = 0.0;
                    rtb_startPose_f[1] = ende[1];
                    rtb_startPose_f[2] = 0.0;
                    rtb_startPose_f[3] = 1.5707963267948966;
                    PreemptableMissionModeSelector_genSegWP(&connectionObj, ende,
                      LUp, 100.0, segWayPoints, localB);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (initWayPoint->size[0] * initWayPoint->size[1]);
                    initWayPoint->size[0] = static_cast<int32_T>
                      (segWayPoints->size[0] + 1);
                    initWayPoint->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (initWayPoint, rtb_ClockwiseRotation_n);
                    ibmat = segWayPoints->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      initWayPoint->data[static_cast<int32_T>(initWayPoint->
                        size[0] * b_nrows)] = 0.0;
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        initWayPoint->data[static_cast<int32_T>
                          (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                            static_cast<int32_T>(initWayPoint->size[0] * b_nrows))
                           + 1)] = segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (segWayPoints->size[0] * b_nrows))];
                      }
                    }
                    break;

                   default:
                    rtb_startPose_f[0] = 0.0;
                    rtb_startPose_f[1] = 0.0;
                    rtb_startPose_f[2] = 0.0;
                    rtb_startPose_f[3] = 0.0;
                    break;
                  }

                  PreemptableMissionModeSelector_genSegWP(&connectionObj, LUp,
                    LDp, 100.0, segWayPoints, localB);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  dummyWayPoint->size[0] = static_cast<int32_T>
                    (segWayPoints->size[0] + 1);
                  dummyWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  ibmat = segWayPoints->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    dummyWayPoint->data[static_cast<int32_T>(dummyWayPoint->
                      size[0] * b_nrows)] = 0.0;
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      dummyWayPoint->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))
                         + 1)] = segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }
                  }

                  PreemptableMissionModeSelector_genSegWP(&connectionObj, LDp,
                    LUp, 100.0, segWayPoints, localB);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  dummyWayPoint_0->size[0] = static_cast<int32_T>
                    (dummyWayPoint->size[0] + segWayPoints->size[0]);
                  dummyWayPoint_0->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint_0, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  ibmat = dummyWayPoint->size[0];
                  loop_ub = segWayPoints->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      dummyWayPoint_0->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * b_nrows))] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] * b_nrows))];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(loop_ub - 1);
                         rtb_ClockwiseRotation_n++) {
                      dummyWayPoint_0->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          dummyWayPoint->size[0]) + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * b_nrows))] =
                        segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }
                  }

                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                  dummyWayPoint->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                  for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                       b_nrows++) {
                    dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
                  }

                  nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
                  nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                       (rtb_ClockwiseRotation_n + 1)) {
                    dummyWayPoint->data[rtb_ClockwiseRotation_n] =
                      dummyWayPoint->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + 1)];
                  }

                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                       (rtb_ClockwiseRotation_n + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + dummyWayPoint->size[0])] =
                      dummyWayPoint->data[static_cast<int32_T>
                      (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                        dummyWayPoint->size[0]) + 1)];
                  }

                  for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                       nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                       (rtb_ClockwiseRotation_n + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint->size[0] << 1))] = dummyWayPoint->data[
                      static_cast<int32_T>(static_cast<int32_T>
                      (rtb_ClockwiseRotation_n + static_cast<int32_T>
                       (dummyWayPoint->size[0] << 1)) + 1)];
                  }

                  if (1 > nrows) {
                    nrowx = -1;
                    b_nrows = -1;
                  } else {
                    b_nrows = nrowx;
                  }

                  ibmat = static_cast<int32_T>(b_nrows + 1);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  dummyWayPoint_0->size[0] = static_cast<int32_T>(nrowx + 1);
                  dummyWayPoint_0->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (dummyWayPoint_0, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      dummyWayPoint_0->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * b_nrows))] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] * b_nrows))];
                    }
                  }

                  PreemptableMissionModeSelector_repmat(dummyWayPoint_0, std::
                    ceil(10240.0 / static_cast<real_T>(static_cast<int32_T>
                    (nrowx + 1))), dummyWayPoint);
                  if (2 > initWayPoint->size[0]) {
                    nrowx = -1;
                    nrows = -1;
                  } else {
                    nrowx = 0;
                    nrows = static_cast<int32_T>(initWayPoint->size[0] - 1);
                  }

                  ibmat = static_cast<int32_T>(nrows - nrowx);
                  rtb_ClockwiseRotation_n = static_cast<int32_T>
                    (segWayPoints->size[0] * segWayPoints->size[1]);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  segWayPoints->size[0] = static_cast<int32_T>(ibmat +
                    dummyWayPoint->size[0]);
                  segWayPoints->size[1] = 3;
                  PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                    (segWayPoints, rtb_ClockwiseRotation_n);

                  // MATLAB Function: '<S86>/WayPointGenerator'
                  loop_ub = dummyWayPoint->size[0];
                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(ibmat - 1);
                         rtb_ClockwiseRotation_n++) {
                      segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))] =
                        initWayPoint->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>(nrowx +
                           rtb_ClockwiseRotation_n) + static_cast<int32_T>
                          (initWayPoint->size[0] * b_nrows)) + 1)];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         static_cast<int32_T>(loop_ub - 1);
                         rtb_ClockwiseRotation_n++) {
                      segWayPoints->data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + nrows) - nrowx) +
                         static_cast<int32_T>(segWayPoints->size[0] * b_nrows))]
                        = dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] * b_nrows))];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                         10240; rtb_ClockwiseRotation_n++) {
                      localB->WayPoint[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>(10240 *
                          b_nrows))] = segWayPoints->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (segWayPoints->size[0] * b_nrows))];
                    }
                  }

                  // Bias: '<S86>/Bias' incorporates:
                  //   Sum: '<S86>/Sum'

                  localB->Bias = ((rtb_Gain1 + rtb_Switch) + rtb_startPose_f[3])
                    + -1.5707963267948966;

                  // Gain: '<S86>/InterLayerDis' incorporates:
                  //   Constant: '<S86>/Three'
                  //   DataTypeConversion: '<S5>/Param5'
                  //   Math: '<S86>/ModRunWayLayer'

                  rtb_Param4_e = 15.0 * rt_modd_snf(static_cast<real_T>
                    (rtu_Parameters->Param5), 3.0);

                  // Reshape: '<S86>/Reshape' incorporates:
                  //   Constant: '<S86>/Zero'
                  //   DataTypeConversion: '<S5>/Param1'

                  rtb_Reshape_i[0] = 0.0;
                  rtb_Reshape_i[1] = static_cast<real_T>(rtu_Parameters->Param1);
                  rtb_Reshape_i[2] = rtb_Param4_e;

                  // Reshape: '<S86>/ReshapeRowVec' incorporates:
                  //   Product: '<S89>/x*cos'
                  //   Product: '<S89>/x*sin'
                  //   Product: '<S89>/y*cos'
                  //   Product: '<S89>/y*sin'
                  //   Reshape: '<S86>/ReshapeRowVecStartpose'
                  //   Sum: '<S89>/Sum2'
                  //   Sum: '<S89>/Sum3'
                  //   UnaryMinus: '<S85>/Ze2height'

                  rtb_ReshapeRowVec[0] = rtb_Down_c * 0.0 + rtb_Abs1_jo;
                  rtb_ReshapeRowVec[1] = rtb_Down_c - rtb_Abs1_jo * 0.0;
                  rtb_ReshapeRowVec[2] = -rtb_Switch_e;

                  // SignalConversion generated from: '<S86>/RotateATMissionHdg' incorporates:
                  //   Constant: '<S86>/Zero'

                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[0] =
                    rtb_Gain1;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[1] = 0.0;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx[2] = 0.0;
                  PreemptableMissionModeSelector_RotateATMissionHdg
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bx,
                     &localB->RotateATMissionHdg_b);

                  // SignalConversion generated from: '<S86>/RotateATRunWayHdg' incorporates:
                  //   Constant: '<S86>/Zero'

                  rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[0] =
                    rtb_Switch;
                  rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[1] = 0.0;
                  rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[2] = 0.0;
                  PreemptableMissionModeSelector_RotateATMissionHdg
                    (rtb_TmpSignalConversionAtRotateATRunWayHdgInport1,
                     &localB->RotateATRunWayHdg_b);

                  // MATLAB Function: '<S86>/minus'
                  PreemptableMissionModeSelector_minus(localB->WayPoint,
                    rtb_Reshape_i, localB->RotateIndivWayPoint);

                  // Product: '<S86>/RotateRunway' incorporates:
                  //   MATLABSystem: '<S86>/RotateATRunWayHdg'

                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                         10240; rtb_ClockwiseRotation_n++) {
                      ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                        static_cast<int32_T>(10240 * b_nrows));
                      localB->rtb_WayPoint_m[ibmat] = 0.0;
                      localB->rtb_WayPoint_m[ibmat] +=
                        localB->RotateATRunWayHdg_b.RotateATMissionHdg[
                        static_cast<int32_T>(3 * b_nrows)] *
                        localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                      localB->rtb_WayPoint_m[ibmat] +=
                        localB->RotateATRunWayHdg_b.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        1)] * localB->RotateIndivWayPoint[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 10240)];
                      localB->rtb_WayPoint_m[ibmat] +=
                        localB->RotateATRunWayHdg_b.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        2)] * localB->RotateIndivWayPoint[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 20480)];
                    }
                  }

                  // Product: '<S86>/RotateIndivWayPoint' incorporates:
                  //   MATLABSystem: '<S86>/RotateATMissionHdg'

                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                         10240; rtb_ClockwiseRotation_n++) {
                      ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                        static_cast<int32_T>(10240 * b_nrows));
                      localB->WayPoint[ibmat] = 0.0;
                      localB->WayPoint[ibmat] +=
                        localB->RotateATMissionHdg_b.RotateATMissionHdg[
                        static_cast<int32_T>(3 * b_nrows)] *
                        localB->rtb_WayPoint_m[rtb_ClockwiseRotation_n];
                      localB->WayPoint[ibmat] +=
                        localB->RotateATMissionHdg_b.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        1)] * localB->rtb_WayPoint_m[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 10240)];
                      localB->WayPoint[ibmat] +=
                        localB->RotateATMissionHdg_b.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        2)] * localB->rtb_WayPoint_m[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 20480)];
                    }
                  }

                  // Sum: '<S86>/BiasStartPose' incorporates:
                  //   DataTypeConversion: '<S5>/Param1'

                  rtb_Switch_aa = rtb_startPose_f[0];
                  rtb_Sum = rtb_startPose_f[1] - static_cast<real_T>
                    (rtu_Parameters->Param1);
                  rtb_Down_c = rtb_startPose_f[2] - rtb_Param4_e;

                  // Product: '<S86>/RotateRunwayStartpose' incorporates:
                  //   MATLABSystem: '<S86>/RotateATRunWayHdg'

                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    rtb_startPose_h[b_nrows] =
                      localB->RotateATRunWayHdg_b.RotateATMissionHdg[
                      static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)]
                      * rtb_Down_c +
                      (localB->RotateATRunWayHdg_b.RotateATMissionHdg[
                       static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        1)] * rtb_Sum +
                       localB->RotateATRunWayHdg_b.RotateATMissionHdg[
                       static_cast<int32_T>(3 * b_nrows)] * rtb_Switch_aa);
                  }

                  // Product: '<S86>/RotateIndivWayPointStartpose' incorporates:
                  //   MATLABSystem: '<S86>/RotateATMissionHdg'

                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    rtb_Reshape_i[b_nrows] =
                      localB->RotateATMissionHdg_b.RotateATMissionHdg[
                      static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)]
                      * rtb_startPose_h[2] +
                      (localB->RotateATMissionHdg_b.RotateATMissionHdg[
                       static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        1)] * rtb_startPose_h[1] +
                       localB->RotateATMissionHdg_b.RotateATMissionHdg[
                       static_cast<int32_T>(3 * b_nrows)] * rtb_startPose_h[0]);
                  }

                  // MATLAB Function: '<S86>/biasNED' incorporates:
                  //   Reshape: '<S86>/ReshapeRowVec'

                  PreemptableMissionModeSelector_biasNED(rtb_ReshapeRowVec,
                    localB->WayPoint, localB->nedWayPoint_k,
                    &localB->sf_biasNED_f);

                  // MATLAB Function: '<S86>/biasNEDstartpose'
                  PreemptableMissionModeSelector_biasNEDstartpose
                    (rtb_ReshapeRowVec, rtb_Reshape_i, localB->nedWayPoint_f);
                }

                // End of Outputs for SubSystem: '<S5>/WayPointGenerator'
                PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
                  localB->nedWayPoint_k, 200.0, &localB->WaypointFollower_b,
                  &localDW->WaypointFollower_b);

                // DataTypeConversion: '<S5>/Cast To Double' incorporates:
                //   Constant: '<S5>/LookAheadDis'
                //   MATLAB Function: '<S86>/WayPointGenerator'
                //   Memory: '<S5>/MemoryTriggerWP'

                *rty_thisTaskStatus = static_cast<real_T>
                  (localB->WaypointFollower_b.WaypointFollower_o5);

                // BusCreator: '<S5>/GuidanceCMDBusCreator' incorporates:
                //   DataTypeConversion: '<S5>/Param4'
                //   Gain: '<S5>/Down2Height'

                rty_GuidanceCmds->Height =
                  -localB->WaypointFollower_b.WaypointFollower_o1[2];
                rty_GuidanceCmds->AirSpeed = static_cast<real_T>
                  (rtu_Parameters->Param4);
                rty_GuidanceCmds->HeadingAngle =
                  localB->WaypointFollower_b.WaypointFollower_o2;

                // Reshape: '<S5>/Reshape' incorporates:
                //   Constant: '<S5>/InitialFlightPathAngle'
                //   Constant: '<S5>/InitialRollAngle'
                //   Constant: '<S5>/InitialRollAngleRate'
                //   DataTypeConversion: '<S5>/Param4'
                //   Gain: '<S5>/Down2Up'

                rty_InitialState[0] = localB->nedWayPoint_f[0];
                rty_InitialState[1] = localB->nedWayPoint_f[1];
                rty_InitialState[2] = -localB->nedWayPoint_f[2];
                rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
                rty_InitialState[4] = localB->Bias;
                rty_InitialState[5] = 0.0;
                rty_InitialState[6] = 0.0;
                rty_InitialState[7] = 0.0;

                // Sum: '<S5>/Sum' incorporates:
                //   Memory: '<S5>/MemoryStopTrigger1'
                //   Memory: '<S5>/MemoryTriggerWP'

                *rty_ResetTrigger = localDW->MemoryStopTrigger1_PreviousInput +
                  localDW->MemoryTriggerWP_PreviousInput_b;

                // Update for Memory: '<S5>/MemoryTriggerWP' incorporates:
                //   Constant: '<S5>/TirggerWayPointGen'

                localDW->MemoryTriggerWP_PreviousInput_b = 1.0;

                // Update for Memory: '<S5>/MemoryStopTrigger1' incorporates:
                //   Memory: '<S5>/MemoryStopTrigger2'

                localDW->MemoryStopTrigger1_PreviousInput =
                  localDW->MemoryStopTrigger2_PreviousInput;

                // Update for Memory: '<S5>/MemoryStopTrigger2' incorporates:
                //   Constant: '<S5>/StopTrigger'

                localDW->MemoryStopTrigger2_PreviousInput = -1.0;
              } else {
                sf_internal_predicateOutput = ((*rtu_mode == 4) || (*rtu_mode ==
                  44));
                if (sf_internal_predicateOutput) {
                  localDW->is_GuidanceLogic =
                    PreemptableMissionModeSelector_IN_ProtectionLine;

                  // Abs: '<S4>/Abs' incorporates:
                  //   DataTypeConversion: '<S4>/Param4'
                  //   DataTypeConversion: '<S4>/Param5'
                  //   Gain: '<S4>/HalfDiff'
                  //   Sum: '<S4>/Minus'

                  rtb_Down_c = std::abs((static_cast<real_T>
                    (rtu_Parameters->Param4) - static_cast<real_T>
                    (rtu_Parameters->Param5)) * 0.5);

                  // Switch: '<S70>/Switch' incorporates:
                  //   Abs: '<S70>/Abs'
                  //   Bias: '<S70>/Bias'
                  //   Bias: '<S70>/Bias1'
                  //   Constant: '<S70>/Constant2'
                  //   Constant: '<S71>/Constant'
                  //   DataStoreRead: '<S4>/LatitudeGCS'
                  //   Math: '<S70>/Math Function1'
                  //   RelationalOperator: '<S71>/Compare'

                  if (std::abs(LatitudeGCS) > 180.0) {
                    rtb_Down = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
                  } else {
                    rtb_Down = LatitudeGCS;
                  }

                  // Abs: '<S67>/Abs1'
                  rtb_Switch_aa = std::abs(rtb_Down);

                  // Switch: '<S67>/Switch' incorporates:
                  //   Bias: '<S67>/Bias'
                  //   Bias: '<S67>/Bias1'
                  //   Constant: '<S58>/Constant'
                  //   Constant: '<S58>/Constant1'
                  //   Constant: '<S69>/Constant'
                  //   Gain: '<S67>/Gain'
                  //   Product: '<S67>/Divide1'
                  //   RelationalOperator: '<S69>/Compare'
                  //   Switch: '<S58>/Switch1'

                  if (rtb_Switch_aa > 90.0) {
                    // Signum: '<S67>/Sign1'
                    if (rtb_Down < 0.0) {
                      rtb_Down = -1.0;
                    } else if (rtb_Down > 0.0) {
                      rtb_Down = 1.0;
                    } else if (rtb_Down == 0.0) {
                      rtb_Down = 0.0;
                    } else {
                      rtb_Down = (rtNaN);
                    }

                    rtb_Down *= -(rtb_Switch_aa + -90.0) + 90.0;
                    b_nrows = 180;
                  } else {
                    b_nrows = 0;
                  }

                  // Sum: '<S58>/Sum' incorporates:
                  //   DataStoreRead: '<S4>/LongitudeGCS'

                  rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

                  // Sum: '<S55>/Sum1'
                  rtb_Switch_aa = rtu_Location->Lat - rtb_Down;

                  // Switch: '<S68>/Switch' incorporates:
                  //   Abs: '<S68>/Abs'
                  //   Bias: '<S68>/Bias'
                  //   Bias: '<S68>/Bias1'
                  //   Constant: '<S68>/Constant2'
                  //   Constant: '<S72>/Constant'
                  //   Math: '<S68>/Math Function1'
                  //   RelationalOperator: '<S72>/Compare'

                  if (std::abs(rtb_Sum) > 180.0) {
                    rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                  }

                  // Sum: '<S55>/Sum1'
                  rtb_Sum = rtu_Location->Lon - rtb_Sum;

                  // Switch: '<S64>/Switch' incorporates:
                  //   Abs: '<S64>/Abs'
                  //   Bias: '<S64>/Bias'
                  //   Bias: '<S64>/Bias1'
                  //   Constant: '<S64>/Constant2'
                  //   Constant: '<S65>/Constant'
                  //   Math: '<S64>/Math Function1'
                  //   RelationalOperator: '<S65>/Compare'

                  if (std::abs(rtb_Switch_aa) > 180.0) {
                    rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) +
                      -180.0;
                  }

                  // Abs: '<S61>/Abs1'
                  rtb_Abs1_jo = std::abs(rtb_Switch_aa);

                  // Switch: '<S61>/Switch' incorporates:
                  //   Bias: '<S61>/Bias'
                  //   Bias: '<S61>/Bias1'
                  //   Constant: '<S57>/Constant'
                  //   Constant: '<S57>/Constant1'
                  //   Constant: '<S63>/Constant'
                  //   Gain: '<S61>/Gain'
                  //   Product: '<S61>/Divide1'
                  //   RelationalOperator: '<S63>/Compare'
                  //   Switch: '<S57>/Switch1'

                  if (rtb_Abs1_jo > 90.0) {
                    // Signum: '<S61>/Sign1'
                    if (rtb_Switch_aa < 0.0) {
                      rtb_Switch_aa = -1.0;
                    } else if (rtb_Switch_aa > 0.0) {
                      rtb_Switch_aa = 1.0;
                    } else if (rtb_Switch_aa == 0.0) {
                      rtb_Switch_aa = 0.0;
                    } else {
                      rtb_Switch_aa = (rtNaN);
                    }

                    rtb_Abs1_jo = (-(rtb_Abs1_jo + -90.0) + 90.0) *
                      rtb_Switch_aa;
                    b_nrows = 180;
                  } else {
                    rtb_Abs1_jo = rtb_Switch_aa;
                    b_nrows = 0;
                  }

                  // Sum: '<S57>/Sum'
                  rtb_Sum += static_cast<real_T>(b_nrows);

                  // UnitConversion: '<S60>/Unit Conversion'
                  // Unit Conversion - from: deg to: rad
                  // Expression: output = (0.0174533*input) + (0)
                  rtb_Switch_aa = 0.017453292519943295 * rtb_Abs1_jo;

                  // UnitConversion: '<S75>/Unit Conversion'
                  // Unit Conversion - from: deg to: rad
                  // Expression: output = (0.0174533*input) + (0)
                  rtb_Down *= 0.017453292519943295;

                  // Trigonometry: '<S76>/Trigonometric Function1'
                  rtb_Param4_e = std::sin(rtb_Down);

                  // Sum: '<S76>/Sum1' incorporates:
                  //   Constant: '<S76>/Constant'
                  //   Product: '<S76>/Product1'

                  rtb_Param4_e = 1.0 -
                    PreemptableMissionModeSelector_ConstB.sqrt_d *
                    PreemptableMissionModeSelector_ConstB.sqrt_d * rtb_Param4_e *
                    rtb_Param4_e;

                  // Product: '<S74>/Product1' incorporates:
                  //   Constant: '<S74>/Constant1'
                  //   Sqrt: '<S74>/sqrt'

                  rtb_Abs1_jo = 6.378137E+6 / std::sqrt(rtb_Param4_e);

                  // Product: '<S59>/dNorth' incorporates:
                  //   Constant: '<S74>/Constant2'
                  //   Product: '<S74>/Product3'
                  //   Trigonometry: '<S74>/Trigonometric Function1'

                  rtb_Param4_e = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Abs1_jo *
                    PreemptableMissionModeSelector_ConstB.Sum1_k / rtb_Param4_e);

                  // Switch: '<S62>/Switch' incorporates:
                  //   Abs: '<S62>/Abs'
                  //   Bias: '<S62>/Bias'
                  //   Bias: '<S62>/Bias1'
                  //   Constant: '<S62>/Constant2'
                  //   Constant: '<S66>/Constant'
                  //   Math: '<S62>/Math Function1'
                  //   RelationalOperator: '<S66>/Compare'

                  // Unit Conversion - from: deg to: rad
                  // Expression: output = (0.0174533*input) + (0)
                  if (std::abs(rtb_Sum) > 180.0) {
                    rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
                  }

                  // Product: '<S59>/dEast' incorporates:
                  //   Constant: '<S74>/Constant3'
                  //   Product: '<S74>/Product4'
                  //   Trigonometry: '<S74>/Trigonometric Function'
                  //   Trigonometry: '<S74>/Trigonometric Function2'
                  //   UnitConversion: '<S60>/Unit Conversion'

                  rtb_Abs1_jo = 1.0 / rt_atan2d_snf(1.0, rtb_Abs1_jo * std::cos
                    (rtb_Down)) * (0.017453292519943295 * rtb_Sum);

                  // Sum: '<S55>/Sum' incorporates:
                  //   DataStoreRead: '<S4>/AltitudeGCS'
                  //   Gain: '<S4>/inverse'

                  rtb_Gain1 = rtu_Location->Alt + -AltitudeGCS;

                  // Gain: '<S54>/Gain1'
                  rtb_Switch_e = 0.017453292519943295 * rtu_Location->degHDG;

                  // Outputs for Triggered SubSystem: '<S4>/WayPointGenerator' incorporates:
                  //   TriggerPort: '<S56>/Trigger'

                  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                                     &localZCE->WayPointGenerator_Trig_ZCE_p,
                                     (localDW->MemoryTriggerWP_PreviousInput_i));
                  if (zcEvent != NO_ZCEVENT) {
                    // DataTypeConversion: '<S56>/Cast To Double'
                    rtb_Switch = static_cast<real_T>(*rtu_FormationIDX);

                    // Abs: '<S56>/Abs'
                    rtb_Abs = static_cast<uint32_T>(std::abs(rtb_Switch));

                    // Signum: '<S56>/Sign'
                    if (rtb_Switch < 0.0) {
                      rtb_Switch = -1.0;
                    } else if (rtb_Switch > 0.0) {
                      rtb_Switch = 1.0;
                    } else {
                      rtb_Switch = 0.0;
                    }

                    // Gain: '<S56>/HalfRotAng' incorporates:
                    //   DataTypeConversion: '<S4>/Param2'
                    //   Gain: '<S79>/Gain1'
                    //   Product: '<S56>/ProductFlipRotAng'

                    rtb_Switch_p = 0.017453292519943295 * static_cast<real_T>
                      (rtu_Parameters->Param2) * rtb_Switch * 0.5;

                    // MATLAB Function: '<S56>/WayPointGenerator' incorporates:
                    //   DataTypeConversion: '<S4>/Param3'

                    PreemptableMissionModeSelector_uavDubinsConnection_uavDubinsConnection
                      (&connectionObj);
                    LUp[0] = 0.0;
                    rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) /
                      2.0;
                    LUp[1] = rtb_Switch_aa;
                    LUp[2] = 0.0;
                    LUp[3] = 1.5707963267948966;
                    LDp[0] = 0.0;
                    rtb_Sum = -static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
                    LDp[1] = rtb_Sum;
                    LDp[2] = 0.0;
                    LDp[3] = 1.5707963267948966;
                    PreemptableMissionModeSelector_uavDubinsConnection_connect
                      (&connectionObj, LUp, LDp, localB->pathSegObj.data,
                       &localB->pathSegObj.size, a__1_data, &b_nrows, localB);
                    PreemptableMissionModeSelector_uavDubinsPathSegment_interpolate
                      (localB->pathSegObj.data[0].StartPose,
                       localB->pathSegObj.data[0].GoalPose,
                       localB->pathSegObj.data[0].FlightPathAngle,
                       localB->pathSegObj.data[0].AirSpeed,
                       localB->pathSegObj.data[0].MinTurningRadius,
                       localB->pathSegObj.data[0].HelixRadius,
                       localB->pathSegObj.data[0].MotionTypes,
                       localB->pathSegObj.data[0].MotionLengths,
                       localB->pathSegObj.data[0].Length,
                       localB->pathSegObj.data[0].Length / 2.0, midpose_data,
                       midpose_size);
                    rtb_startPose_f[0] = 0.0;
                    rtb_Down = (localB->pathSegObj.data[0].Length + static_cast<
                                real_T>(rtu_Parameters->Param3)) / 3.0 -
                      localB->pathSegObj.data[0].Length / 2.0;
                    rtb_startPose_f[1] = rtb_Switch_aa - rtb_Down;
                    rtb_startPose_f[2] = 0.0;
                    rtb_startPose_f[3] = 1.5707963267948966;
                    ende[0] = 0.0;
                    ende[1] = rtb_Down + rtb_Sum;
                    ende[2] = 0.0;
                    ende[3] = 1.5707963267948966;
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (initWayPoint->size[0] * initWayPoint->size[1]);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    initWayPoint->size[0] = 1;
                    initWayPoint->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (initWayPoint, rtb_ClockwiseRotation_n);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    initWayPoint->data[0] = 0.0;
                    initWayPoint->data[1] = 0.0;
                    initWayPoint->data[2] = 0.0;
                    switch (static_cast<int32_T>(rtb_Abs)) {
                     case 0:
                      PreemptableMissionModeSelector_genSegWP(&connectionObj,
                        rtb_startPose_f, LUp, 100.0, segWayPoints, localB);
                      rtb_ClockwiseRotation_n = static_cast<int32_T>
                        (initWayPoint->size[0] * initWayPoint->size[1]);
                      initWayPoint->size[0] = static_cast<int32_T>
                        (segWayPoints->size[0] + 1);
                      initWayPoint->size[1] = 3;
                      PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                        (initWayPoint, rtb_ClockwiseRotation_n);
                      ibmat = segWayPoints->size[0];
                      for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                        initWayPoint->data[static_cast<int32_T>
                          (initWayPoint->size[0] * b_nrows)] = 0.0;
                        for (rtb_ClockwiseRotation_n = 0;
                             rtb_ClockwiseRotation_n <= static_cast<int32_T>
                             (ibmat - 1); rtb_ClockwiseRotation_n++) {
                          initWayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                              static_cast<int32_T>(initWayPoint->size[0] *
                               b_nrows)) + 1)] = segWayPoints->data[static_cast<
                            int32_T>(rtb_ClockwiseRotation_n +
                                     static_cast<int32_T>(segWayPoints->size[0] *
                                      b_nrows))];
                        }
                      }
                      break;

                     case 1:
                      rtb_startPose_f[0] = midpose_data[0];
                      rtb_startPose_f[1] = midpose_data[midpose_size[0]];
                      rtb_startPose_f[2] = midpose_data[static_cast<int32_T>
                        (midpose_size[0] << 1)];
                      rtb_startPose_f[3] = midpose_data[static_cast<int32_T>
                        (midpose_size[0] * 3)];
                      PreemptableMissionModeSelector_genSegWP(&connectionObj,
                        &midpose_data[0], LDp, 100.0, segWayPoints, localB);
                      rtb_ClockwiseRotation_n = static_cast<int32_T>
                        (initWayPoint->size[0] * initWayPoint->size[1]);
                      initWayPoint->size[0] = static_cast<int32_T>
                        (segWayPoints->size[0] + 1);
                      initWayPoint->size[1] = 3;
                      PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                        (initWayPoint, rtb_ClockwiseRotation_n);
                      ibmat = segWayPoints->size[0];
                      for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                        initWayPoint->data[static_cast<int32_T>
                          (initWayPoint->size[0] * b_nrows)] = 0.0;
                        for (rtb_ClockwiseRotation_n = 0;
                             rtb_ClockwiseRotation_n <= static_cast<int32_T>
                             (ibmat - 1); rtb_ClockwiseRotation_n++) {
                          initWayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                              static_cast<int32_T>(initWayPoint->size[0] *
                               b_nrows)) + 1)] = segWayPoints->data[static_cast<
                            int32_T>(rtb_ClockwiseRotation_n +
                                     static_cast<int32_T>(segWayPoints->size[0] *
                                      b_nrows))];
                        }
                      }
                      break;

                     case 2:
                      rtb_startPose_f[0] = 0.0;
                      rtb_startPose_f[1] = ende[1];
                      rtb_startPose_f[2] = 0.0;
                      rtb_startPose_f[3] = 1.5707963267948966;
                      PreemptableMissionModeSelector_genSegWP(&connectionObj,
                        ende, LUp, 100.0, segWayPoints, localB);
                      rtb_ClockwiseRotation_n = static_cast<int32_T>
                        (initWayPoint->size[0] * initWayPoint->size[1]);
                      initWayPoint->size[0] = static_cast<int32_T>
                        (segWayPoints->size[0] + 1);
                      initWayPoint->size[1] = 3;
                      PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                        (initWayPoint, rtb_ClockwiseRotation_n);
                      ibmat = segWayPoints->size[0];
                      for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                        initWayPoint->data[static_cast<int32_T>
                          (initWayPoint->size[0] * b_nrows)] = 0.0;
                        for (rtb_ClockwiseRotation_n = 0;
                             rtb_ClockwiseRotation_n <= static_cast<int32_T>
                             (ibmat - 1); rtb_ClockwiseRotation_n++) {
                          initWayPoint->data[static_cast<int32_T>
                            (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                              static_cast<int32_T>(initWayPoint->size[0] *
                               b_nrows)) + 1)] = segWayPoints->data[static_cast<
                            int32_T>(rtb_ClockwiseRotation_n +
                                     static_cast<int32_T>(segWayPoints->size[0] *
                                      b_nrows))];
                        }
                      }
                      break;

                     default:
                      rtb_startPose_f[0] = 0.0;
                      rtb_startPose_f[1] = 0.0;
                      rtb_startPose_f[2] = 0.0;
                      rtb_startPose_f[3] = 0.0;
                      break;
                    }

                    PreemptableMissionModeSelector_genSegWP(&connectionObj, LUp,
                      LDp, 100.0, segWayPoints, localB);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    dummyWayPoint->size[0] = static_cast<int32_T>
                      (segWayPoints->size[0] + 1);
                    dummyWayPoint->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (dummyWayPoint, rtb_ClockwiseRotation_n);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    ibmat = segWayPoints->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      dummyWayPoint->data[static_cast<int32_T>
                        (dummyWayPoint->size[0] * b_nrows)] = 0.0;
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        dummyWayPoint->data[static_cast<int32_T>
                          (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                            static_cast<int32_T>(dummyWayPoint->size[0] *
                             b_nrows)) + 1)] = segWayPoints->data
                          [static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          static_cast<int32_T>(segWayPoints->size[0] * b_nrows))];
                      }
                    }

                    PreemptableMissionModeSelector_genSegWP(&connectionObj, LDp,
                      LUp, 100.0, segWayPoints, localB);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    dummyWayPoint_0->size[0] = static_cast<int32_T>
                      (dummyWayPoint->size[0] + segWayPoints->size[0]);
                    dummyWayPoint_0->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (dummyWayPoint_0, rtb_ClockwiseRotation_n);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    ibmat = dummyWayPoint->size[0];
                    loop_ub = segWayPoints->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint_0->size[0] * b_nrows))] =
                          dummyWayPoint->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint->size[0] * b_nrows))];
                      }

                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(loop_ub - 1);
                           rtb_ClockwiseRotation_n++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                          (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                            dummyWayPoint->size[0]) + static_cast<int32_T>
                           (dummyWayPoint_0->size[0] * b_nrows))] =
                          segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (segWayPoints->size[0] * b_nrows))];
                      }
                    }

                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (dummyWayPoint->size[0] * dummyWayPoint->size[1]);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                    dummyWayPoint->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (dummyWayPoint, rtb_ClockwiseRotation_n);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                    for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                         b_nrows++) {
                      dummyWayPoint->data[b_nrows] = dummyWayPoint_0->
                        data[b_nrows];
                    }

                    nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
                    nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                         (rtb_ClockwiseRotation_n + 1)) {
                      dummyWayPoint->data[rtb_ClockwiseRotation_n] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + 1)];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                         (rtb_ClockwiseRotation_n + 1)) {
                      dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + dummyWayPoint->size[0])] =
                        dummyWayPoint->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          dummyWayPoint->size[0]) + 1)];
                    }

                    for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                         nrowx; rtb_ClockwiseRotation_n = static_cast<int32_T>
                         (rtb_ClockwiseRotation_n + 1)) {
                      dummyWayPoint->data[static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] << 1))] = dummyWayPoint->data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (rtb_ClockwiseRotation_n + static_cast<int32_T>
                         (dummyWayPoint->size[0] << 1)) + 1)];
                    }

                    if (1 > nrows) {
                      nrowx = -1;
                      b_nrows = -1;
                    } else {
                      b_nrows = nrowx;
                    }

                    ibmat = static_cast<int32_T>(b_nrows + 1);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    dummyWayPoint_0->size[0] = static_cast<int32_T>(nrowx + 1);
                    dummyWayPoint_0->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (dummyWayPoint_0, rtb_ClockwiseRotation_n);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint_0->size[0] * b_nrows))] =
                          dummyWayPoint->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint->size[0] * b_nrows))];
                      }
                    }

                    PreemptableMissionModeSelector_repmat(dummyWayPoint_0, std::
                      ceil(10240.0 / static_cast<real_T>(static_cast<int32_T>
                      (nrowx + 1))), dummyWayPoint);
                    if (2 > initWayPoint->size[0]) {
                      nrowx = -1;
                      nrows = -1;
                    } else {
                      nrowx = 0;
                      nrows = static_cast<int32_T>(initWayPoint->size[0] - 1);
                    }

                    // Gain: '<S56>/RevFlip'
                    b_nrows = static_cast<int32_T>(-static_cast<int32_T>
                      (rtb_Switch));

                    // Product: '<S56>/ProductFlipStartPose'
                    LUp[0] = rtb_startPose_f[0] * static_cast<real_T>(b_nrows);
                    LUp[1] = rtb_startPose_f[1];
                    LUp[2] = rtb_startPose_f[2];

                    // Bias: '<S56>/Bias' incorporates:
                    //   Product: '<S56>/ProductFlipStartPose'
                    //   Sum: '<S56>/Sum'

                    localB->Bias_g = ((rtb_Switch_e + rtb_Switch_p) +
                                      rtb_startPose_f[3]) + -1.5707963267948966;

                    // SignalConversion generated from: '<S56>/RotateATRunWayHdg' incorporates:
                    //   Constant: '<S56>/Zero'

                    rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[0] =
                      rtb_Switch_p;
                    rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[1] = 0.0;
                    rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c[2] = 0.0;
                    PreemptableMissionModeSelector_RotateATMissionHdg
                      (rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_c,
                       &localB->RotateATRunWayHdg);

                    // Product: '<S56>/ProductFlipXbias' incorporates:
                    //   DataTypeConversion: '<S4>/Param1'
                    //   Gain: '<S56>/HalfSepDis'

                    rtb_Switch *= 0.5 * static_cast<real_T>
                      (rtu_Parameters->Param1);

                    // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
                    //   Constant: '<S56>/Zeros'

                    rtb_MatrixConcatenate[0] = static_cast<int8_T>(b_nrows);
                    rtb_MatrixConcatenate[1] = 0;
                    rtb_MatrixConcatenate[2] = 0;

                    // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
                    //   Constant: '<S56>/One'
                    //   Constant: '<S56>/Zeros'

                    rtb_MatrixConcatenate[3] = 0;
                    rtb_MatrixConcatenate[4] = 1;
                    rtb_MatrixConcatenate[5] = 0;

                    // SignalConversion generated from: '<S56>/Matrix Concatenate' incorporates:
                    //   Constant: '<S56>/One'
                    //   Constant: '<S56>/Zeros'

                    rtb_MatrixConcatenate[6] = 0;
                    rtb_MatrixConcatenate[7] = 0;
                    rtb_MatrixConcatenate[8] = 1;

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    ibmat = static_cast<int32_T>(nrows - nrowx);
                    rtb_ClockwiseRotation_n = static_cast<int32_T>
                      (segWayPoints->size[0] * segWayPoints->size[1]);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    segWayPoints->size[0] = static_cast<int32_T>(ibmat +
                      dummyWayPoint->size[0]);
                    segWayPoints->size[1] = 3;
                    PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                      (segWayPoints, rtb_ClockwiseRotation_n);

                    // MATLAB Function: '<S56>/WayPointGenerator'
                    loop_ub = dummyWayPoint->size[0];
                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(ibmat - 1);
                           rtb_ClockwiseRotation_n++) {
                        segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (segWayPoints->size[0] * b_nrows))] =
                          initWayPoint->data[static_cast<int32_T>
                          (static_cast<int32_T>(static_cast<int32_T>(nrowx +
                             rtb_ClockwiseRotation_n) + static_cast<int32_T>
                            (initWayPoint->size[0] * b_nrows)) + 1)];
                      }

                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                           static_cast<int32_T>(loop_ub - 1);
                           rtb_ClockwiseRotation_n++) {
                        segWayPoints->data[static_cast<int32_T>
                          (static_cast<int32_T>(static_cast<int32_T>
                            (rtb_ClockwiseRotation_n + nrows) - nrowx) +
                           static_cast<int32_T>(segWayPoints->size[0] * b_nrows))]
                          = dummyWayPoint->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (dummyWayPoint->size[0] * b_nrows))];
                      }
                    }

                    // Product: '<S56>/ProductFlipRunWay' incorporates:
                    //   Concatenate: '<S56>/Matrix Concatenate'
                    //   MATLAB Function: '<S56>/WayPointGenerator'

                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                           10240; rtb_ClockwiseRotation_n++) {
                        ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          static_cast<int32_T>(10240 * b_nrows));
                        localB->RotateIndivWayPoint[ibmat] = 0.0;
                        localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                          (rtb_MatrixConcatenate[static_cast<int32_T>(3 *
                            b_nrows)]) * segWayPoints->
                          data[rtb_ClockwiseRotation_n];
                        localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                          (rtb_MatrixConcatenate[static_cast<int32_T>(
                            static_cast<int32_T>(3 * b_nrows) + 1)]) *
                          segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + segWayPoints->size[0])];
                        localB->RotateIndivWayPoint[ibmat] += static_cast<real_T>
                          (rtb_MatrixConcatenate[static_cast<int32_T>(
                            static_cast<int32_T>(3 * b_nrows) + 2)]) *
                          segWayPoints->data[static_cast<int32_T>
                          (rtb_ClockwiseRotation_n + static_cast<int32_T>
                           (segWayPoints->size[0] << 1))];
                      }
                    }

                    // Reshape: '<S56>/Reshape' incorporates:
                    //   Constant: '<S56>/Zero'

                    rtb_Reshape_i[0] = rtb_Switch;
                    rtb_Reshape_i[1] = 0.0;
                    rtb_Reshape_i[2] = 0.0;

                    // Reshape: '<S56>/ReshapeRowVec' incorporates:
                    //   Product: '<S59>/x*cos'
                    //   Product: '<S59>/x*sin'
                    //   Product: '<S59>/y*cos'
                    //   Product: '<S59>/y*sin'
                    //   Reshape: '<S56>/ReshapeRowVecStartpose'
                    //   Sum: '<S59>/Sum2'
                    //   Sum: '<S59>/Sum3'
                    //   UnaryMinus: '<S55>/Ze2height'

                    rtb_ReshapeRowVec[0] = rtb_Abs1_jo * 0.0 + rtb_Param4_e;
                    rtb_ReshapeRowVec[1] = rtb_Abs1_jo - rtb_Param4_e * 0.0;
                    rtb_ReshapeRowVec[2] = -rtb_Gain1;

                    // SignalConversion generated from: '<S56>/RotateATMissionHdg' incorporates:
                    //   Constant: '<S56>/Zero'

                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[0] =
                      rtb_Switch_e;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[1] =
                      0.0;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd[2] =
                      0.0;
                    PreemptableMissionModeSelector_RotateATMissionHdg
                      (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_bxd,
                       &localB->RotateATMissionHdg);

                    // Product: '<S56>/RotateRunway' incorporates:
                    //   MATLABSystem: '<S56>/RotateATRunWayHdg'

                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                           10240; rtb_ClockwiseRotation_n++) {
                        ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          static_cast<int32_T>(10240 * b_nrows));
                        localB->WayPoint[ibmat] = 0.0;
                        localB->WayPoint[ibmat] +=
                          localB->RotateATRunWayHdg.RotateATMissionHdg[
                          static_cast<int32_T>(3 * b_nrows)] *
                          localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                        localB->WayPoint[ibmat] +=
                          localB->RotateATRunWayHdg.RotateATMissionHdg[
                          static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows)
                          + 1)] * localB->RotateIndivWayPoint
                          [static_cast<int32_T>(rtb_ClockwiseRotation_n + 10240)];
                        localB->WayPoint[ibmat] +=
                          localB->RotateATRunWayHdg.RotateATMissionHdg[
                          static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows)
                          + 2)] * localB->RotateIndivWayPoint
                          [static_cast<int32_T>(rtb_ClockwiseRotation_n + 20480)];
                      }
                    }

                    // MATLAB Function: '<S56>/minus'
                    PreemptableMissionModeSelector_minus(localB->WayPoint,
                      rtb_Reshape_i, localB->RotateIndivWayPoint);

                    // Product: '<S56>/RotateIndivWayPoint' incorporates:
                    //   MATLABSystem: '<S56>/RotateATMissionHdg'

                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <
                           10240; rtb_ClockwiseRotation_n++) {
                        ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                          static_cast<int32_T>(10240 * b_nrows));
                        localB->WayPoint[ibmat] = 0.0;
                        localB->WayPoint[ibmat] +=
                          localB->RotateATMissionHdg.RotateATMissionHdg[
                          static_cast<int32_T>(3 * b_nrows)] *
                          localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                        localB->WayPoint[ibmat] +=
                          localB->RotateATMissionHdg.RotateATMissionHdg[
                          static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows)
                          + 1)] * localB->RotateIndivWayPoint
                          [static_cast<int32_T>(rtb_ClockwiseRotation_n + 10240)];
                        localB->WayPoint[ibmat] +=
                          localB->RotateATMissionHdg.RotateATMissionHdg[
                          static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows)
                          + 2)] * localB->RotateIndivWayPoint
                          [static_cast<int32_T>(rtb_ClockwiseRotation_n + 20480)];
                      }
                    }

                    // Product: '<S56>/RotateRunwayStartpose' incorporates:
                    //   MATLABSystem: '<S56>/RotateATRunWayHdg'

                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      rtb_Reshape_i[b_nrows] =
                        localB->RotateATRunWayHdg.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        2)] * LUp[2] +
                        (localB->RotateATRunWayHdg.RotateATMissionHdg[
                         static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows)
                          + 1)] * LUp[1] +
                         localB->RotateATRunWayHdg.RotateATMissionHdg[
                         static_cast<int32_T>(3 * b_nrows)] * LUp[0]);
                    }

                    // Sum: '<S56>/BiasStartPose'
                    rtb_Switch_aa = rtb_Reshape_i[0] - rtb_Switch;
                    rtb_Sum = rtb_Reshape_i[1];
                    rtb_Down = rtb_Reshape_i[2];

                    // Product: '<S56>/RotateIndivWayPointStartpose' incorporates:
                    //   MATLABSystem: '<S56>/RotateATMissionHdg'

                    for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                      rtb_Reshape_i[b_nrows] =
                        localB->RotateATMissionHdg.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) +
                        2)] * rtb_Down +
                        (localB->RotateATMissionHdg.RotateATMissionHdg[
                         static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows)
                          + 1)] * rtb_Sum +
                         localB->RotateATMissionHdg.RotateATMissionHdg[
                         static_cast<int32_T>(3 * b_nrows)] * rtb_Switch_aa);
                    }

                    // MATLAB Function: '<S56>/biasNED' incorporates:
                    //   Reshape: '<S56>/ReshapeRowVec'

                    PreemptableMissionModeSelector_biasNED(rtb_ReshapeRowVec,
                      localB->WayPoint, localB->nedWayPoint_j,
                      &localB->sf_biasNED);

                    // MATLAB Function: '<S56>/biasNEDstartpose'
                    PreemptableMissionModeSelector_biasNEDstartpose
                      (rtb_ReshapeRowVec, rtb_Reshape_i, localB->nedWayPoint_l);
                  }

                  // End of Outputs for SubSystem: '<S4>/WayPointGenerator'
                  PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
                    localB->nedWayPoint_j, 200.0, &localB->WaypointFollower,
                    &localDW->WaypointFollower);

                  // DataTypeConversion: '<S4>/Cast To Double' incorporates:
                  //   Constant: '<S4>/LookAheadDis'
                  //   MATLAB Function: '<S56>/WayPointGenerator'
                  //   Memory: '<S4>/MemoryTriggerWP'

                  *rty_thisTaskStatus = static_cast<real_T>
                    (localB->WaypointFollower.WaypointFollower_o5);

                  // Gain: '<S4>/HalfSum' incorporates:
                  //   DataTypeConversion: '<S4>/Param4'
                  //   DataTypeConversion: '<S4>/Param5'
                  //   Sum: '<S4>/SumSpd'

                  rtb_Param4_e = (static_cast<real_T>(rtu_Parameters->Param4) +
                                  static_cast<real_T>(rtu_Parameters->Param5)) *
                    0.5;

                  // BusCreator: '<S4>/GuidanceCMDBusCreator' incorporates:
                  //   Gain: '<S4>/Down2Height'

                  rty_GuidanceCmds->Height =
                    -localB->WaypointFollower.WaypointFollower_o1[2];
                  rty_GuidanceCmds->AirSpeed = rtb_Param4_e;
                  rty_GuidanceCmds->HeadingAngle =
                    localB->WaypointFollower.WaypointFollower_o2;

                  // Product: '<S4>/ProductEast' incorporates:
                  //   Trigonometry: '<S4>/Sin'

                  rty_VelShift[1] = rtb_Down_c * std::sin(rtb_Switch_e);

                  // Product: '<S4>/ProductNorth' incorporates:
                  //   Trigonometry: '<S4>/Cos'

                  rty_VelShift[0] = std::cos(rtb_Switch_e) * rtb_Down_c;

                  // Reshape: '<S4>/Reshape' incorporates:
                  //   Constant: '<S4>/InitialFlightPathAngle'
                  //   Constant: '<S4>/InitialRollAngle'
                  //   Constant: '<S4>/InitialRollAngleRate'
                  //   Gain: '<S4>/Down2Up'

                  rty_InitialState[0] = localB->nedWayPoint_l[0];
                  rty_InitialState[1] = localB->nedWayPoint_l[1];
                  rty_InitialState[2] = -localB->nedWayPoint_l[2];
                  rty_InitialState[3] = rtb_Param4_e;
                  rty_InitialState[4] = localB->Bias_g;
                  rty_InitialState[5] = 0.0;
                  rty_InitialState[6] = 0.0;
                  rty_InitialState[7] = 0.0;

                  // Sum: '<S4>/Sum' incorporates:
                  //   Memory: '<S4>/MemoryStopTrigger1'
                  //   Memory: '<S4>/MemoryTriggerWP'

                  *rty_ResetTrigger =
                    localDW->MemoryStopTrigger1_PreviousInput_o +
                    localDW->MemoryTriggerWP_PreviousInput_i;

                  // Update for Memory: '<S4>/MemoryTriggerWP' incorporates:
                  //   Constant: '<S4>/TirggerWayPointGen'

                  localDW->MemoryTriggerWP_PreviousInput_i = 1.0;

                  // Update for Memory: '<S4>/MemoryStopTrigger1' incorporates:
                  //   Memory: '<S4>/MemoryStopTrigger2'

                  localDW->MemoryStopTrigger1_PreviousInput_o =
                    localDW->MemoryStopTrigger2_PreviousInput_n;

                  // Update for Memory: '<S4>/MemoryStopTrigger2' incorporates:
                  //   Constant: '<S4>/StopTrigger'

                  localDW->MemoryStopTrigger2_PreviousInput_n = -1.0;
                }
              }
            }
          }
        }
        break;

       default:
        // case IN_WaypointFollower:
        *rty_ResetTrigger = 0.0;
        if (static_cast<int32_T>(localDW->is_WaypointFollower) == 1) {
          // Switch: '<S131>/Switch' incorporates:
          //   Abs: '<S131>/Abs'
          //   Bias: '<S131>/Bias'
          //   Bias: '<S131>/Bias1'
          //   Constant: '<S131>/Constant2'
          //   Constant: '<S132>/Constant'
          //   DataStoreRead: '<S6>/LatitudeGCS'
          //   Math: '<S131>/Math Function1'
          //   RelationalOperator: '<S132>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Down_c = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            rtb_Down_c = LatitudeGCS;
          }

          // Abs: '<S128>/Abs1'
          rtb_Switch_aa = std::abs(rtb_Down_c);

          // Switch: '<S128>/Switch' incorporates:
          //   Bias: '<S128>/Bias'
          //   Bias: '<S128>/Bias1'
          //   Constant: '<S119>/Constant'
          //   Constant: '<S119>/Constant1'
          //   Constant: '<S130>/Constant'
          //   Gain: '<S128>/Gain'
          //   Product: '<S128>/Divide1'
          //   RelationalOperator: '<S130>/Compare'
          //   Switch: '<S119>/Switch1'

          if (rtb_Switch_aa > 90.0) {
            // Signum: '<S128>/Sign1'
            if (rtb_Down_c < 0.0) {
              rtb_Down_c = -1.0;
            } else if (rtb_Down_c > 0.0) {
              rtb_Down_c = 1.0;
            } else if (rtb_Down_c == 0.0) {
              rtb_Down_c = 0.0;
            } else {
              rtb_Down_c = (rtNaN);
            }

            rtb_Down_c *= -(rtb_Switch_aa + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S119>/Sum' incorporates:
          //   DataStoreRead: '<S6>/LongitudeGCS'

          rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

          // Sum: '<S115>/Sum1'
          rtb_Switch_aa = rtu_Location->Lat - rtb_Down_c;

          // Switch: '<S129>/Switch' incorporates:
          //   Abs: '<S129>/Abs'
          //   Bias: '<S129>/Bias'
          //   Bias: '<S129>/Bias1'
          //   Constant: '<S129>/Constant2'
          //   Constant: '<S133>/Constant'
          //   Math: '<S129>/Math Function1'
          //   RelationalOperator: '<S133>/Compare'

          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S115>/Sum1'
          rtb_Sum = rtu_Location->Lon - rtb_Sum;

          // Switch: '<S125>/Switch' incorporates:
          //   Abs: '<S125>/Abs'
          //   Bias: '<S125>/Bias'
          //   Bias: '<S125>/Bias1'
          //   Constant: '<S125>/Constant2'
          //   Constant: '<S126>/Constant'
          //   Math: '<S125>/Math Function1'
          //   RelationalOperator: '<S126>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S122>/Abs1'
          rtb_Down = std::abs(rtb_Switch_aa);

          // Switch: '<S122>/Switch' incorporates:
          //   Bias: '<S122>/Bias'
          //   Bias: '<S122>/Bias1'
          //   Constant: '<S118>/Constant'
          //   Constant: '<S118>/Constant1'
          //   Constant: '<S124>/Constant'
          //   Gain: '<S122>/Gain'
          //   Product: '<S122>/Divide1'
          //   RelationalOperator: '<S124>/Compare'
          //   Switch: '<S118>/Switch1'

          if (rtb_Down > 90.0) {
            // Signum: '<S122>/Sign1'
            if (rtb_Switch_aa < 0.0) {
              rtb_Switch_aa = -1.0;
            } else if (rtb_Switch_aa > 0.0) {
              rtb_Switch_aa = 1.0;
            } else if (rtb_Switch_aa == 0.0) {
              rtb_Switch_aa = 0.0;
            } else {
              rtb_Switch_aa = (rtNaN);
            }

            rtb_Gain1 = (-(rtb_Down + -90.0) + 90.0) * rtb_Switch_aa;
            b_nrows = 180;
          } else {
            rtb_Gain1 = rtb_Switch_aa;
            b_nrows = 0;
          }

          // Sum: '<S118>/Sum'
          rtb_Sum += static_cast<real_T>(b_nrows);

          // UnitConversion: '<S121>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch_aa = 0.017453292519943295 * rtb_Gain1;

          // UnitConversion: '<S136>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Down_c *= 0.017453292519943295;

          // Trigonometry: '<S137>/Trigonometric Function1'
          rtb_Switch_p = std::sin(rtb_Down_c);

          // Sum: '<S137>/Sum1' incorporates:
          //   Constant: '<S137>/Constant'
          //   Product: '<S137>/Product1'

          rtb_Switch_p = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_bu *
            PreemptableMissionModeSelector_ConstB.sqrt_bu * rtb_Switch_p *
            rtb_Switch_p;

          // Product: '<S135>/Product1' incorporates:
          //   Constant: '<S135>/Constant1'
          //   Sqrt: '<S135>/sqrt'

          rtb_Gain1 = 6.378137E+6 / std::sqrt(rtb_Switch_p);

          // Product: '<S120>/dNorth' incorporates:
          //   Constant: '<S135>/Constant2'
          //   Product: '<S135>/Product3'
          //   Trigonometry: '<S135>/Trigonometric Function1'

          rtb_Switch_p = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Gain1 *
            PreemptableMissionModeSelector_ConstB.Sum1_c / rtb_Switch_p);

          // Switch: '<S123>/Switch' incorporates:
          //   Abs: '<S123>/Abs'
          //   Bias: '<S123>/Bias'
          //   Bias: '<S123>/Bias1'
          //   Constant: '<S123>/Constant2'
          //   Constant: '<S127>/Constant'
          //   Math: '<S123>/Math Function1'
          //   RelationalOperator: '<S127>/Compare'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Product: '<S120>/dEast' incorporates:
          //   Constant: '<S135>/Constant3'
          //   Product: '<S135>/Product4'
          //   Trigonometry: '<S135>/Trigonometric Function'
          //   Trigonometry: '<S135>/Trigonometric Function2'
          //   UnitConversion: '<S121>/Unit Conversion'

          rtb_Gain1 = 1.0 / rt_atan2d_snf(1.0, rtb_Gain1 * std::cos(rtb_Down_c))
            * (0.017453292519943295 * rtb_Sum);

          // Sum: '<S120>/Sum2' incorporates:
          //   Product: '<S120>/x*cos'
          //   Product: '<S120>/y*sin'

          rtb_Down = rtb_Gain1 * 0.0 + rtb_Switch_p;

          // Sum: '<S120>/Sum3' incorporates:
          //   Product: '<S120>/x*sin'
          //   Product: '<S120>/y*cos'

          rtb_Abs1_jo = rtb_Gain1 - rtb_Switch_p * 0.0;

          // Sum: '<S115>/Sum' incorporates:
          //   DataStoreRead: '<S6>/AltitudeGCS'
          //   Gain: '<S6>/inverse'

          rtb_Switch_aa = rtu_Location->Alt + -AltitudeGCS;

          // Gain: '<S6>/Up2Down'
          rtb_Switch_p = -rtu_StartPosition->Alt;

          // Sum: '<S6>/Sum' incorporates:
          //   UnaryMinus: '<S115>/Ze2height'

          rtb_Param4_e = -rtb_Switch_aa + rtb_Switch_p;

          // Gain: '<S114>/Gain1'
          rtb_Switch_e = 0.017453292519943295 * rtu_Location->degHDG;

          // Outputs for Triggered SubSystem: '<S6>/WayPointGenerator' incorporates:
          //   TriggerPort: '<S117>/Trigger'

          zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                             &localZCE->WayPointGenerator_Trig_ZCE_a,
                             (localDW->MemoryTriggerWP_PreviousInput_d));
          if (zcEvent != NO_ZCEVENT) {
            // Product: '<S117>/ProductScanWidth' incorporates:
            //   DataTypeConversion: '<S6>/Param3'

            rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) *
              static_cast<real_T>(*rtu_MissionUAV);

            // Reshape: '<S117>/ReshapeRowVec'
            rtb_ReshapeRowVec[0] = rtb_Down;
            rtb_ReshapeRowVec[1] = rtb_Abs1_jo;
            rtb_ReshapeRowVec[2] = rtb_Param4_e;

            // SignalConversion generated from: '<S117>/RotateATMissionHdg' incorporates:
            //   Constant: '<S117>/Zero'

            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[0] =
              rtb_Switch_e;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[1] = 0.0;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b[2] = 0.0;
            PreemptableMissionModeSelector_RotateATMissionHdg
              (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_b,
               &localB->RotateATMissionHdg_ba);

            // MATLAB Function: '<S117>/WayPointGenerator' incorporates:
            //   DataTypeConversion: '<S6>/Param2'

            rtb_Switch_aa = std::ceil(static_cast<real_T>(rtu_Parameters->Param2)
              / rtb_Switch_aa);
            rtb_Sum = static_cast<real_T>(rtu_Parameters->Param2) /
              rtb_Switch_aa;
            connectionObj.FlightPathAngleLimit[0] = -0.175;
            connectionObj.FlightPathAngleLimit[1] = 0.175;
            connectionObj.MaxRollAngle = 0.29670597283903605;
            connectionObj.AirSpeed = 35.0;
            connectionObj.MinTurningRadius = 408.85657731051754;
            b_nrows = static_cast<int32_T>(rtb_Switch_aa * 2.0);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(CheckPoints->size[0] *
              CheckPoints->size[1]);

            // MATLAB Function: '<S117>/WayPointGenerator'
            CheckPoints->size[0] = b_nrows;
            CheckPoints->size[1] = 4;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (CheckPoints, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S117>/WayPointGenerator' incorporates:
            //   DataTypeConversion: '<S6>/Param1'

            ibmat = static_cast<int32_T>(static_cast<int32_T>(b_nrows << 2) - 1);
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= ibmat;
                 rtb_ClockwiseRotation_n++) {
              CheckPoints->data[rtb_ClockwiseRotation_n] = 0.0;
            }

            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                 rtb_ClockwiseRotation_n = static_cast<int32_T>
                 (rtb_ClockwiseRotation_n + 1)) {
              if (rt_remd_snf(static_cast<real_T>(rtb_ClockwiseRotation_n) + 1.0,
                              2.0) == 1.0) {
                b_nrows = static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 1) << 1);
                rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n) +
                               1.0) - 1.0) * rtb_Sum;
                CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                  rtb_Switch;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + CheckPoints->size[0]) - 2)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1)) -
                  2)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) - 2)]
                  = 1.5707963267948966;
                CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                  rtb_Switch;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + CheckPoints->size[0]) - 1)] = static_cast<real_T>
                  (rtu_Parameters->Param1);
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1)) -
                  1)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) - 1)]
                  = 1.5707963267948966;
              } else {
                b_nrows = static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 1) << 1);
                rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n) +
                               1.0) - 1.0) * rtb_Sum;
                CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                  rtb_Switch;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + CheckPoints->size[0]) - 2)] = static_cast<real_T>
                  (rtu_Parameters->Param1);
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1)) -
                  2)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) - 2)]
                  = -1.5707963267948966;
                CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                  rtb_Switch;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + CheckPoints->size[0]) - 1)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1)) -
                  1)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) - 1)]
                  = -1.5707963267948966;
              }
            }

            rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0]
              * dummyWayPoint->size[1]);

            // MATLAB Function: '<S117>/WayPointGenerator'
            dummyWayPoint->size[0] = 1;
            dummyWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (dummyWayPoint, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S117>/WayPointGenerator'
            dummyWayPoint->data[0] = 0.0;
            dummyWayPoint->data[1] = 0.0;
            dummyWayPoint->data[2] = 0.0;
            for (nrowx = 0; nrowx <= static_cast<int32_T>(CheckPoints->size[0] -
                  2); nrowx = static_cast<int32_T>(nrowx + 1)) {
              LUp[0] = CheckPoints->data[nrowx];
              LDp[0] = CheckPoints->data[static_cast<int32_T>(nrowx + 1)];
              LUp[1] = CheckPoints->data[static_cast<int32_T>(nrowx +
                CheckPoints->size[0])];
              LDp[1] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(nrowx + CheckPoints->size[0]) + 1)];
              LUp[2] = CheckPoints->data[static_cast<int32_T>(nrowx +
                static_cast<int32_T>(CheckPoints->size[0] << 1))];
              LDp[2] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(nrowx + static_cast<int32_T>
                  (CheckPoints->size[0] << 1)) + 1)];
              LUp[3] = CheckPoints->data[static_cast<int32_T>(nrowx +
                static_cast<int32_T>(CheckPoints->size[0] * 3))];
              LDp[3] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(nrowx + static_cast<int32_T>
                  (CheckPoints->size[0] * 3)) + 1)];
              PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp,
                LDp, 100.0, segWayPoints, localB);
              rtb_ClockwiseRotation_n = static_cast<int32_T>
                (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);
              dummyWayPoint_0->size[0] = static_cast<int32_T>
                (dummyWayPoint->size[0] + segWayPoints->size[0]);
              dummyWayPoint_0->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint_0, rtb_ClockwiseRotation_n);
              ibmat = dummyWayPoint->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint_0->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint_0->size[0] * b_nrows))] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }
              }

              ibmat = segWayPoints->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                    static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                    segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))];
                }
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);
              ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
              for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                   b_nrows++) {
                dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
              }
            }

            LUp[0] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              - 1)];
            LDp[0] = CheckPoints->data[0];
            LUp[1] = CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
              (CheckPoints->size[0] + CheckPoints->size[0]) - 1)];
            LDp[1] = CheckPoints->data[CheckPoints->size[0]];
            LUp[2] = CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
              (CheckPoints->size[0] + static_cast<int32_T>(CheckPoints->size[0] <<
              1)) - 1)];
            LDp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              << 1)];
            LUp[3] = CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
              (CheckPoints->size[0] + static_cast<int32_T>(CheckPoints->size[0] *
              3)) - 1)];
            LDp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              * 3)];
            PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp, LDp,
              100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint_0->
              size[0] * dummyWayPoint_0->size[1]);

            // MATLAB Function: '<S117>/WayPointGenerator'
            dummyWayPoint_0->size[0] = static_cast<int32_T>(dummyWayPoint->size
              [0] + segWayPoints->size[0]);
            dummyWayPoint_0->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (dummyWayPoint_0, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S117>/WayPointGenerator'
            ibmat = dummyWayPoint->size[0];
            loop_ub = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                dummyWayPoint_0->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (dummyWayPoint_0->size[0] * b_nrows))] = dummyWayPoint->data[
                  static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n++)
              {
                dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                  static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                  segWayPoints->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (segWayPoints->size[0] * b_nrows))];
              }
            }

            rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0]
              * dummyWayPoint->size[1]);

            // MATLAB Function: '<S117>/WayPointGenerator'
            dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
            dummyWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (dummyWayPoint, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S117>/WayPointGenerator'
            ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
            for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                 b_nrows++) {
              dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
            }

            rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint_1->
              size[0] * dummyWayPoint_1->size[1]);

            // MATLAB Function: '<S117>/WayPointGenerator'
            dummyWayPoint_1->size[0] = dummyWayPoint->size[0];
            dummyWayPoint_1->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (dummyWayPoint_1, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S117>/WayPointGenerator'
            loop_ub = static_cast<int32_T>(static_cast<int32_T>
              (dummyWayPoint->size[0] * dummyWayPoint->size[1]) - 1);
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= loop_ub;
                 rtb_ClockwiseRotation_n++) {
              dummyWayPoint_1->data[rtb_ClockwiseRotation_n] =
                dummyWayPoint->data[rtb_ClockwiseRotation_n];
            }

            PreemptableMissionModeSelector_repmat(dummyWayPoint_1, std::ceil
              (10240.0 / static_cast<real_T>(dummyWayPoint->size[0])),
              dummyWayPoint);
            nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
            nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
            for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                 (b_nrows + 1)) {
              dummyWayPoint->data[b_nrows] = dummyWayPoint->data
                [static_cast<int32_T>(b_nrows + 1)];
            }

            for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                 (b_nrows + 1)) {
              dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                dummyWayPoint->size[0])] = dummyWayPoint->data
                [static_cast<int32_T>(static_cast<int32_T>(b_nrows +
                dummyWayPoint->size[0]) + 1)];
            }

            for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                 (b_nrows + 1)) {
              dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                (b_nrows + static_cast<int32_T>(dummyWayPoint->size[0] << 1)) +
                1)];
            }

            // Reshape: '<S6>/Reshape2Row' incorporates:
            //   Memory: '<S6>/MemoryPrevRelPos'

            rtb_Reshape_i[0] = localDW->MemoryPrevRelPos_PreviousInput_n[1];
            rtb_Reshape_i[1] = localDW->MemoryPrevRelPos_PreviousInput_n[0];
            rtb_Reshape_i[2] = localDW->MemoryPrevRelPos_PreviousInput_n[2];

            // Product: '<S117>/RotateRelPrevPos' incorporates:
            //   MATLABSystem: '<S117>/RotateATMissionHdg'

            rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtb_Reshape_i,
              localB->RotateATMissionHdg_ba.RotateATMissionHdg, rtb_startPose_h);

            // MATLAB Function: '<S117>/WayPointGenerator'
            LDp[0] = rtb_startPose_h[0];
            LDp[1] = rtb_startPose_h[1];
            LDp[2] = rtb_startPose_h[2];
            LDp[3] = 1.5707963267948966;
            LUp[0] = CheckPoints->data[0];
            LUp[1] = CheckPoints->data[CheckPoints->size[0]];
            LUp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              << 1)];
            LUp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              * 3)];
            PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LDp, LUp,
              100.0, segWayPoints, localB);
            if (1 > nrows) {
              nrowx = -1;
            }

            rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0]
              * initWayPoint->size[1]);

            // MATLAB Function: '<S117>/WayPointGenerator'
            initWayPoint->size[0] = static_cast<int32_T>(static_cast<int32_T>
              (segWayPoints->size[0] + nrowx) + 1);
            initWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (initWayPoint, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S117>/WayPointGenerator'
            ibmat = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                  + static_cast<int32_T>(initWayPoint->size[0] * b_nrows))] =
                  segWayPoints->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (segWayPoints->size[0] * b_nrows))];
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= nrowx;
                   rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + segWayPoints->size[0]) +
                  static_cast<int32_T>(initWayPoint->size[0] * b_nrows))] =
                  dummyWayPoint->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (dummyWayPoint->size[0] * b_nrows))];
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                   rtb_ClockwiseRotation_n++) {
                localB->WayPoint[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(10240 * b_nrows))] = initWayPoint->data[
                  static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(initWayPoint->size[0] * b_nrows))];
              }
            }

            // MATLAB Function: '<S117>/biasWayPoint'
            for (b_nrows = 0; b_nrows < 10240; b_nrows++) {
              localB->RotateIndivWayPoint[b_nrows] = localB->WayPoint[b_nrows] +
                rtu_StartPosition->Lon;
              localB->RotateIndivWayPoint[static_cast<int32_T>(b_nrows + 10240)]
                = localB->WayPoint[static_cast<int32_T>(b_nrows + 10240)];
              localB->RotateIndivWayPoint[static_cast<int32_T>(b_nrows + 20480)]
                = localB->WayPoint[static_cast<int32_T>(b_nrows + 20480)];
            }

            // Product: '<S117>/RotateIndivWayPoint' incorporates:
            //   MATLABSystem: '<S117>/RotateATMissionHdg'

            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                   rtb_ClockwiseRotation_n++) {
                ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(10240 * b_nrows));
                localB->WayPoint[ibmat] = 0.0;
                localB->WayPoint[ibmat] +=
                  localB->RotateATMissionHdg_ba.RotateATMissionHdg
                  [static_cast<int32_T>(3 * b_nrows)] *
                  localB->RotateIndivWayPoint[rtb_ClockwiseRotation_n];
                localB->WayPoint[ibmat] +=
                  localB->RotateATMissionHdg_ba.RotateATMissionHdg
                  [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)] *
                  localB->RotateIndivWayPoint[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 10240)];
                localB->WayPoint[ibmat] +=
                  localB->RotateATMissionHdg_ba.RotateATMissionHdg
                  [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
                  localB->RotateIndivWayPoint[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 20480)];
              }
            }

            // MATLAB Function: '<S117>/biasNED'
            PreemptableMissionModeSelector_biasNED_l(rtb_ReshapeRowVec,
              localB->WayPoint, localB->nedWayPoint_a, &localB->sf_biasNED_l);
          }

          // End of Outputs for SubSystem: '<S6>/WayPointGenerator'
          PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
            localB->nedWayPoint_a, 200.0, &localB->WaypointFollower_ba,
            &localDW->WaypointFollower_ba);

          // DataTypeConversion: '<S6>/Cast To Double' incorporates:
          //   Constant: '<S6>/LookAheadDis'
          //   MATLAB Function: '<S117>/WayPointGenerator'
          //   Memory: '<S6>/MemoryTriggerWP'

          *rty_thisTaskStatus = static_cast<real_T>
            (localB->WaypointFollower_ba.WaypointFollower_o5);

          // Sum: '<S116>/Sum' incorporates:
          //   DataStoreRead: '<S6>/PrevAltitudeGCS'
          //   Gain: '<S6>/PrevInverse'

          rtb_Switch = rtu_PrevLocation->Alt + -AltitudeGCS;

          // Product: '<S6>/FrontEast' incorporates:
          //   Trigonometry: '<S6>/FrontSin'

          rtb_Down_c = std::sin(rtb_Switch_e) * rtu_StartPosition->Lat;

          // Product: '<S6>/FrontNorth' incorporates:
          //   Trigonometry: '<S6>/FrontCos'

          rtb_Gain1 = std::cos(rtb_Switch_e) * rtu_StartPosition->Lat;

          // BusCreator: '<S6>/GuidanceCMDBusCreator' incorporates:
          //   DataTypeConversion: '<S6>/Param4'
          //   Gain: '<S6>/Down2Height'

          rty_GuidanceCmds->Height =
            -localB->WaypointFollower_ba.WaypointFollower_o1[2];
          rty_GuidanceCmds->AirSpeed = static_cast<real_T>
            (rtu_Parameters->Param4);
          rty_GuidanceCmds->HeadingAngle =
            localB->WaypointFollower_ba.WaypointFollower_o2;

          // Switch: '<S153>/Switch' incorporates:
          //   Abs: '<S153>/Abs'
          //   Bias: '<S153>/Bias'
          //   Bias: '<S153>/Bias1'
          //   Constant: '<S153>/Constant2'
          //   Constant: '<S154>/Constant'
          //   DataStoreRead: '<S6>/PrevLatitudeGCS'
          //   Math: '<S153>/Math Function1'
          //   RelationalOperator: '<S154>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Switch_p = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            rtb_Switch_p = LatitudeGCS;
          }

          // Abs: '<S150>/Abs1'
          rtb_Switch_aa = std::abs(rtb_Switch_p);

          // Switch: '<S150>/Switch' incorporates:
          //   Bias: '<S150>/Bias'
          //   Bias: '<S150>/Bias1'
          //   Constant: '<S141>/Constant'
          //   Constant: '<S141>/Constant1'
          //   Constant: '<S152>/Constant'
          //   Gain: '<S150>/Gain'
          //   Product: '<S150>/Divide1'
          //   RelationalOperator: '<S152>/Compare'
          //   Switch: '<S141>/Switch1'

          if (rtb_Switch_aa > 90.0) {
            // Signum: '<S150>/Sign1'
            if (rtb_Switch_p < 0.0) {
              rtb_Switch_p = -1.0;
            } else if (rtb_Switch_p > 0.0) {
              rtb_Switch_p = 1.0;
            } else if (rtb_Switch_p == 0.0) {
              rtb_Switch_p = 0.0;
            } else {
              rtb_Switch_p = (rtNaN);
            }

            rtb_Switch_p *= -(rtb_Switch_aa + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S141>/Sum' incorporates:
          //   DataStoreRead: '<S6>/PrevLongitudeGCS'

          rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

          // Sum: '<S116>/Sum1'
          rtb_Switch_aa = rtu_PrevLocation->Lat - rtb_Switch_p;

          // Switch: '<S151>/Switch' incorporates:
          //   Abs: '<S151>/Abs'
          //   Bias: '<S151>/Bias'
          //   Bias: '<S151>/Bias1'
          //   Constant: '<S151>/Constant2'
          //   Constant: '<S155>/Constant'
          //   Math: '<S151>/Math Function1'
          //   RelationalOperator: '<S155>/Compare'

          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S116>/Sum1'
          rtb_Sum = rtu_PrevLocation->Lon - rtb_Sum;

          // Switch: '<S147>/Switch' incorporates:
          //   Abs: '<S147>/Abs'
          //   Bias: '<S147>/Bias'
          //   Bias: '<S147>/Bias1'
          //   Constant: '<S147>/Constant2'
          //   Constant: '<S148>/Constant'
          //   Math: '<S147>/Math Function1'
          //   RelationalOperator: '<S148>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S144>/Abs1'
          rtb_SumInitEast_j = std::abs(rtb_Switch_aa);

          // Switch: '<S144>/Switch' incorporates:
          //   Bias: '<S144>/Bias'
          //   Bias: '<S144>/Bias1'
          //   Constant: '<S140>/Constant'
          //   Constant: '<S140>/Constant1'
          //   Constant: '<S146>/Constant'
          //   Gain: '<S144>/Gain'
          //   Product: '<S144>/Divide1'
          //   RelationalOperator: '<S146>/Compare'
          //   Switch: '<S140>/Switch1'

          if (rtb_SumInitEast_j > 90.0) {
            // Signum: '<S144>/Sign1'
            if (rtb_Switch_aa < 0.0) {
              rtb_Switch_aa = -1.0;
            } else if (rtb_Switch_aa > 0.0) {
              rtb_Switch_aa = 1.0;
            } else if (rtb_Switch_aa == 0.0) {
              rtb_Switch_aa = 0.0;
            } else {
              rtb_Switch_aa = (rtNaN);
            }

            rtb_Switch_aa *= -(rtb_SumInitEast_j + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S140>/Sum'
          rtb_Sum_as = static_cast<real_T>(b_nrows) + rtb_Sum;

          // UnitConversion: '<S158>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch_p *= 0.017453292519943295;

          // Trigonometry: '<S159>/Trigonometric Function1'
          rtb_Sum = std::sin(rtb_Switch_p);

          // Sum: '<S159>/Sum1' incorporates:
          //   Constant: '<S159>/Constant'
          //   Product: '<S159>/Product1'

          rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_a *
            PreemptableMissionModeSelector_ConstB.sqrt_a * rtb_Sum * rtb_Sum;

          // Product: '<S157>/Product1' incorporates:
          //   Constant: '<S157>/Constant1'
          //   Sqrt: '<S157>/sqrt'

          rtb_SumInitEast_j = 6.378137E+6 / std::sqrt(rtb_Sum);

          // Product: '<S157>/Product4' incorporates:
          //   Trigonometry: '<S157>/Trigonometric Function'

          rtb_Switch_p = rtb_SumInitEast_j * std::cos(rtb_Switch_p);

          // Product: '<S142>/dNorth' incorporates:
          //   Constant: '<S157>/Constant2'
          //   Product: '<S157>/Product3'
          //   Trigonometry: '<S157>/Trigonometric Function1'
          //   UnitConversion: '<S143>/Unit Conversion'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_SumInitEast_j = 0.017453292519943295 * rtb_Switch_aa /
            rt_atan2d_snf(1.0, rtb_SumInitEast_j *
                          PreemptableMissionModeSelector_ConstB.Sum1_l / rtb_Sum);

          // Switch: '<S145>/Switch' incorporates:
          //   Abs: '<S145>/Abs'
          //   Bias: '<S145>/Bias'
          //   Bias: '<S145>/Bias1'
          //   Constant: '<S145>/Constant2'
          //   Constant: '<S149>/Constant'
          //   Math: '<S145>/Math Function1'
          //   RelationalOperator: '<S149>/Compare'

          if (std::abs(rtb_Sum_as) > 180.0) {
            rtb_Sum_as = rt_modd_snf(rtb_Sum_as + 180.0, 360.0) + -180.0;
          }

          // Product: '<S142>/dEast' incorporates:
          //   Constant: '<S157>/Constant3'
          //   Trigonometry: '<S157>/Trigonometric Function2'
          //   UnitConversion: '<S143>/Unit Conversion'

          rtb_Sum = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_p) *
            (0.017453292519943295 * rtb_Sum_as);

          // Sum: '<S142>/Sum2' incorporates:
          //   Product: '<S142>/x*cos'
          //   Product: '<S142>/y*sin'

          rtb_Switch_aa = rtb_Sum * 0.0 + rtb_SumInitEast_j;

          // Sum: '<S142>/Sum3' incorporates:
          //   Product: '<S142>/x*sin'
          //   Product: '<S142>/y*cos'

          rtb_SumInitEast_j = rtb_Sum - rtb_SumInitEast_j * 0.0;

          // Product: '<S6>/RightNorth' incorporates:
          //   Bias: '<S6>/Rotate90deg'
          //   Trigonometry: '<S6>/RightCos'

          rtb_Sum_as = std::cos(rtb_Switch_e + 1.5707963267948966) *
            rtu_StartPosition->Lon;

          // Product: '<S6>/RightEast' incorporates:
          //   Bias: '<S6>/Rotate90deg'
          //   Trigonometry: '<S6>/RightSin'

          rtb_Sum = std::sin(rtb_Switch_e + 1.5707963267948966) *
            rtu_StartPosition->Lon;

          // Sum: '<S6>/SumHeight' incorporates:
          //   UnaryMinus: '<S116>/Ze2height'

          rtb_Switch_p = rtu_StartPosition->Alt + rtb_Switch;

          // Reshape: '<S6>/Reshape' incorporates:
          //   Constant: '<S6>/InitialFlightPathAngle'
          //   Constant: '<S6>/InitialRollAngle'
          //   Constant: '<S6>/InitialRollAngleRate'
          //   DataTypeConversion: '<S6>/Param4'
          //   Sum: '<S6>/SumInitEast'
          //   Sum: '<S6>/SumInitNorth'

          rty_InitialState[0] = (rtb_Switch_aa + rtb_Sum_as) + rtb_Gain1;
          rty_InitialState[1] = (rtb_SumInitEast_j + rtb_Down_c) + rtb_Sum;
          rty_InitialState[2] = rtb_Switch_p;
          rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
          rty_InitialState[4] = rtb_Switch_e;
          rty_InitialState[5] = 0.0;
          rty_InitialState[6] = 0.0;
          rty_InitialState[7] = 0.0;

          // Update for Memory: '<S6>/MemoryPrevRelPos' incorporates:
          //   Sum: '<S6>/RelPrevPos'
          //   UnaryMinus: '<S116>/Ze2height'

          localDW->MemoryPrevRelPos_PreviousInput_n[0] = rtb_Switch_aa -
            rtb_Down;
          localDW->MemoryPrevRelPos_PreviousInput_n[1] = rtb_SumInitEast_j -
            rtb_Abs1_jo;
          localDW->MemoryPrevRelPos_PreviousInput_n[2] = -rtb_Switch -
            rtb_Param4_e;

          // Update for Memory: '<S6>/MemoryTriggerWP' incorporates:
          //   Constant: '<S6>/TirggerWayPointGen'

          localDW->MemoryTriggerWP_PreviousInput_d = 1.0;
        } else {
          // Sum: '<S166>/Sum' incorporates:
          //   DataStoreRead: '<S7>/AltitudeGCS'
          //   Gain: '<S7>/inverse'

          // case IN_HorizontalFormationNav:
          rtb_Switch_aa = rtu_Location->Alt + -AltitudeGCS;

          // DataTypeConversion: '<S7>/CastToDouble'
          rtb_Switch_e = static_cast<real_T>(*rtu_FormationIDX);

          // Sum: '<S7>/Minus' incorporates:
          //   Constant: '<S7>/One2ZeroIdx'

          rtb_Switch_e--;

          // Gain: '<S7>/Gain' incorporates:
          //   Constant: '<S7>/Three'
          //   Math: '<S7>/ModRunWayLayer'

          rtb_Down_c = 15.0 * rt_modd_snf(rtb_Switch_e, 3.0);

          // Sum: '<S7>/BiasMissionAlt' incorporates:
          //   UnaryMinus: '<S166>/Ze2height'

          rtb_Down = -rtb_Switch_aa - rtb_Down_c;

          // Sum: '<S167>/Sum' incorporates:
          //   DataStoreRead: '<S7>/PrevAltitudeGCS'
          //   Gain: '<S7>/PrevInverse'

          rtb_Switch_aa = rtu_PrevLocation->Alt + -AltitudeGCS;

          // Sum: '<S7>/BiasPrevAlt' incorporates:
          //   UnaryMinus: '<S167>/Ze2height'

          rtb_Down_c = -rtb_Switch_aa - rtb_Down_c;

          // Switch: '<S182>/Switch' incorporates:
          //   Abs: '<S182>/Abs'
          //   Bias: '<S182>/Bias'
          //   Bias: '<S182>/Bias1'
          //   Constant: '<S182>/Constant2'
          //   Constant: '<S183>/Constant'
          //   DataStoreRead: '<S7>/LatitudeGCS'
          //   Math: '<S182>/Math Function1'
          //   RelationalOperator: '<S183>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            rtb_Switch = LatitudeGCS;
          }

          // Abs: '<S179>/Abs1'
          rtb_Switch_aa = std::abs(rtb_Switch);

          // Switch: '<S179>/Switch' incorporates:
          //   Bias: '<S179>/Bias'
          //   Bias: '<S179>/Bias1'
          //   Constant: '<S170>/Constant'
          //   Constant: '<S170>/Constant1'
          //   Constant: '<S181>/Constant'
          //   Gain: '<S179>/Gain'
          //   Product: '<S179>/Divide1'
          //   RelationalOperator: '<S181>/Compare'
          //   Switch: '<S170>/Switch1'

          if (rtb_Switch_aa > 90.0) {
            // Signum: '<S179>/Sign1'
            if (rtb_Switch < 0.0) {
              rtb_Switch = -1.0;
            } else if (rtb_Switch > 0.0) {
              rtb_Switch = 1.0;
            } else if (rtb_Switch == 0.0) {
              rtb_Switch = 0.0;
            } else {
              rtb_Switch = (rtNaN);
            }

            rtb_Switch *= -(rtb_Switch_aa + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S170>/Sum' incorporates:
          //   DataStoreRead: '<S7>/LongitudeGCS'

          rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

          // Sum: '<S166>/Sum1'
          rtb_Switch_aa = rtu_Location->Lat - rtb_Switch;

          // Switch: '<S180>/Switch' incorporates:
          //   Abs: '<S180>/Abs'
          //   Bias: '<S180>/Bias'
          //   Bias: '<S180>/Bias1'
          //   Constant: '<S180>/Constant2'
          //   Constant: '<S184>/Constant'
          //   Math: '<S180>/Math Function1'
          //   RelationalOperator: '<S184>/Compare'

          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S166>/Sum1'
          rtb_Sum = rtu_Location->Lon - rtb_Sum;

          // Switch: '<S176>/Switch' incorporates:
          //   Abs: '<S176>/Abs'
          //   Bias: '<S176>/Bias'
          //   Bias: '<S176>/Bias1'
          //   Constant: '<S176>/Constant2'
          //   Constant: '<S177>/Constant'
          //   Math: '<S176>/Math Function1'
          //   RelationalOperator: '<S177>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S173>/Abs1'
          rtb_Abs1_jo = std::abs(rtb_Switch_aa);

          // Switch: '<S173>/Switch' incorporates:
          //   Bias: '<S173>/Bias'
          //   Bias: '<S173>/Bias1'
          //   Constant: '<S169>/Constant'
          //   Constant: '<S169>/Constant1'
          //   Constant: '<S175>/Constant'
          //   Gain: '<S173>/Gain'
          //   Product: '<S173>/Divide1'
          //   RelationalOperator: '<S175>/Compare'
          //   Switch: '<S169>/Switch1'

          if (rtb_Abs1_jo > 90.0) {
            // Signum: '<S173>/Sign1'
            if (rtb_Switch_aa < 0.0) {
              rtb_Switch_aa = -1.0;
            } else if (rtb_Switch_aa > 0.0) {
              rtb_Switch_aa = 1.0;
            } else if (rtb_Switch_aa == 0.0) {
              rtb_Switch_aa = 0.0;
            } else {
              rtb_Switch_aa = (rtNaN);
            }

            rtb_Param4_e = (-(rtb_Abs1_jo + -90.0) + 90.0) * rtb_Switch_aa;
            b_nrows = 180;
          } else {
            rtb_Param4_e = rtb_Switch_aa;
            b_nrows = 0;
          }

          // Sum: '<S169>/Sum'
          rtb_Abs1_jo = static_cast<real_T>(b_nrows) + rtb_Sum;

          // UnitConversion: '<S172>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch_aa = 0.017453292519943295 * rtb_Param4_e;

          // UnitConversion: '<S187>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch *= 0.017453292519943295;

          // Trigonometry: '<S188>/Trigonometric Function1'
          rtb_Sum = std::sin(rtb_Switch);

          // Sum: '<S188>/Sum1' incorporates:
          //   Constant: '<S188>/Constant'
          //   Product: '<S188>/Product1'

          rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_b *
            PreemptableMissionModeSelector_ConstB.sqrt_b * rtb_Sum * rtb_Sum;

          // Product: '<S186>/Product1' incorporates:
          //   Constant: '<S186>/Constant1'
          //   Sqrt: '<S186>/sqrt'

          rtb_Param4_e = 6.378137E+6 / std::sqrt(rtb_Sum);

          // Product: '<S171>/dNorth' incorporates:
          //   Constant: '<S186>/Constant2'
          //   Product: '<S186>/Product3'
          //   Trigonometry: '<S186>/Trigonometric Function1'

          rtb_Sum = rtb_Switch_aa / rt_atan2d_snf(1.0, rtb_Param4_e *
            PreemptableMissionModeSelector_ConstB.Sum1_d / rtb_Sum);

          // Switch: '<S174>/Switch' incorporates:
          //   Abs: '<S174>/Abs'
          //   Bias: '<S174>/Bias'
          //   Bias: '<S174>/Bias1'
          //   Constant: '<S174>/Constant2'
          //   Constant: '<S178>/Constant'
          //   Math: '<S174>/Math Function1'
          //   RelationalOperator: '<S178>/Compare'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          if (std::abs(rtb_Abs1_jo) > 180.0) {
            rtb_Abs1_jo = rt_modd_snf(rtb_Abs1_jo + 180.0, 360.0) + -180.0;
          }

          // Product: '<S171>/dEast' incorporates:
          //   Constant: '<S186>/Constant3'
          //   Product: '<S186>/Product4'
          //   Trigonometry: '<S186>/Trigonometric Function'
          //   Trigonometry: '<S186>/Trigonometric Function2'
          //   UnitConversion: '<S172>/Unit Conversion'

          rtb_Param4_e = 1.0 / rt_atan2d_snf(1.0, rtb_Param4_e * std::cos
            (rtb_Switch)) * (0.017453292519943295 * rtb_Abs1_jo);

          // Sum: '<S171>/Sum2' incorporates:
          //   Product: '<S171>/x*cos'
          //   Product: '<S171>/y*sin'

          rtb_Abs1_jo = rtb_Param4_e * 0.0 + rtb_Sum;

          // Sum: '<S171>/Sum3' incorporates:
          //   Product: '<S171>/x*sin'
          //   Product: '<S171>/y*cos'

          rtb_Param4_e -= rtb_Sum * 0.0;

          // Product: '<S7>/Map2Radian' incorporates:
          //   DataTypeConversion: '<S7>/Param3'

          rtb_Switch_e *= static_cast<real_T>(rtu_Parameters->Param3);

          // Gain: '<S165>/Gain1'
          rtb_Gain1 = 0.017453292519943295 * rtu_Location->degHDG;

          // Outputs for Triggered SubSystem: '<S7>/WayPointGenerator' incorporates:
          //   TriggerPort: '<S168>/Trigger'

          zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                             &localZCE->WayPointGenerator_Trig_ZCE,
                             (localDW->MemoryTriggerWP_PreviousInput));
          if (zcEvent != NO_ZCEVENT) {
            // Product: '<S168>/ProductScanWidth' incorporates:
            //   DataTypeConversion: '<S7>/Param3'

            rtb_Switch_aa = static_cast<real_T>(rtu_Parameters->Param3) *
              static_cast<real_T>(*rtu_MissionUAV);

            // Reshape: '<S168>/ReshapeRowVec'
            rtb_ReshapeRowVec[0] = rtb_Abs1_jo;
            rtb_ReshapeRowVec[1] = rtb_Param4_e;
            rtb_ReshapeRowVec[2] = rtb_Down;

            // SignalConversion generated from: '<S168>/RotateATMissionHdg' incorporates:
            //   Constant: '<S168>/Zero'

            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = rtb_Gain1;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] = 0.0;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
            PreemptableMissionModeSelector_RotateATMissionHdg
              (rtb_TmpSignalConversionAtRotateATMissionHdgInport1,
               &localB->RotateATMissionHdg_baf);

            // MATLAB Function: '<S168>/WayPointGenerator' incorporates:
            //   DataTypeConversion: '<S7>/Param2'

            rtb_Switch_aa = std::ceil(static_cast<real_T>(rtu_Parameters->Param2)
              / rtb_Switch_aa);
            rtb_Sum = static_cast<real_T>(rtu_Parameters->Param2) /
              rtb_Switch_aa;
            connectionObj.FlightPathAngleLimit[0] = -0.175;
            connectionObj.FlightPathAngleLimit[1] = 0.175;
            connectionObj.MaxRollAngle = 0.29670597283903605;
            connectionObj.AirSpeed = 35.0;
            connectionObj.MinTurningRadius = 408.85657731051754;
            b_nrows = static_cast<int32_T>(rtb_Switch_aa * 2.0);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(CheckPoints->size[0] *
              CheckPoints->size[1]);

            // MATLAB Function: '<S168>/WayPointGenerator'
            CheckPoints->size[0] = b_nrows;
            CheckPoints->size[1] = 4;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (CheckPoints, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S168>/WayPointGenerator' incorporates:
            //   DataTypeConversion: '<S7>/Param1'

            ibmat = static_cast<int32_T>(static_cast<int32_T>(b_nrows << 2) - 1);
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= ibmat;
                 rtb_ClockwiseRotation_n++) {
              CheckPoints->data[rtb_ClockwiseRotation_n] = 0.0;
            }

            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                 rtb_ClockwiseRotation_n = static_cast<int32_T>
                 (rtb_ClockwiseRotation_n + 1)) {
              if (rt_remd_snf(static_cast<real_T>(rtb_ClockwiseRotation_n) + 1.0,
                              2.0) == 1.0) {
                b_nrows = static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 1) << 1);
                rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n) +
                               1.0) - 1.0) * rtb_Sum;
                CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                  rtb_Switch;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + CheckPoints->size[0]) - 2)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1)) -
                  2)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) - 2)]
                  = 1.5707963267948966;
                CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                  rtb_Switch;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + CheckPoints->size[0]) - 1)] = static_cast<real_T>
                  (rtu_Parameters->Param1);
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1)) -
                  1)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) - 1)]
                  = 1.5707963267948966;
              } else {
                b_nrows = static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 1) << 1);
                rtb_Switch = ((static_cast<real_T>(rtb_ClockwiseRotation_n) +
                               1.0) - 1.0) * rtb_Sum;
                CheckPoints->data[static_cast<int32_T>(b_nrows - 2)] =
                  rtb_Switch;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + CheckPoints->size[0]) - 2)] = static_cast<real_T>
                  (rtu_Parameters->Param1);
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1)) -
                  2)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) - 2)]
                  = -1.5707963267948966;
                CheckPoints->data[static_cast<int32_T>(b_nrows - 1)] =
                  rtb_Switch;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + CheckPoints->size[0]) - 1)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] << 1)) -
                  1)] = 0.0;
                CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + static_cast<int32_T>(CheckPoints->size[0] * 3)) - 1)]
                  = -1.5707963267948966;
              }
            }

            rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0]
              * dummyWayPoint->size[1]);

            // MATLAB Function: '<S168>/WayPointGenerator'
            dummyWayPoint->size[0] = 1;
            dummyWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (dummyWayPoint, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S168>/WayPointGenerator'
            dummyWayPoint->data[0] = 0.0;
            dummyWayPoint->data[1] = 0.0;
            dummyWayPoint->data[2] = 0.0;
            for (nrowx = 0; nrowx <= static_cast<int32_T>(CheckPoints->size[0] -
                  2); nrowx = static_cast<int32_T>(nrowx + 1)) {
              LUp[0] = CheckPoints->data[nrowx];
              LDp[0] = CheckPoints->data[static_cast<int32_T>(nrowx + 1)];
              LUp[1] = CheckPoints->data[static_cast<int32_T>(nrowx +
                CheckPoints->size[0])];
              LDp[1] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(nrowx + CheckPoints->size[0]) + 1)];
              LUp[2] = CheckPoints->data[static_cast<int32_T>(nrowx +
                static_cast<int32_T>(CheckPoints->size[0] << 1))];
              LDp[2] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(nrowx + static_cast<int32_T>
                  (CheckPoints->size[0] << 1)) + 1)];
              LUp[3] = CheckPoints->data[static_cast<int32_T>(nrowx +
                static_cast<int32_T>(CheckPoints->size[0] * 3))];
              LDp[3] = CheckPoints->data[static_cast<int32_T>
                (static_cast<int32_T>(nrowx + static_cast<int32_T>
                  (CheckPoints->size[0] * 3)) + 1)];
              PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp,
                LDp, 100.0, segWayPoints, localB);
              rtb_ClockwiseRotation_n = static_cast<int32_T>
                (dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1]);
              dummyWayPoint_0->size[0] = static_cast<int32_T>
                (dummyWayPoint->size[0] + segWayPoints->size[0]);
              dummyWayPoint_0->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint_0, rtb_ClockwiseRotation_n);
              ibmat = dummyWayPoint->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint_0->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint_0->size[0] * b_nrows))] =
                    dummyWayPoint->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (dummyWayPoint->size[0] * b_nrows))];
                }
              }

              ibmat = segWayPoints->size[0];
              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                     static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++)
                {
                  dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                    static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                    segWayPoints->data[static_cast<int32_T>
                    (rtb_ClockwiseRotation_n + static_cast<int32_T>
                     (segWayPoints->size[0] * b_nrows))];
                }
              }

              rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->
                size[0] * dummyWayPoint->size[1]);
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
                (dummyWayPoint, rtb_ClockwiseRotation_n);
              ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
              for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                   b_nrows++) {
                dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
              }
            }

            LUp[0] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              - 1)];
            LDp[0] = CheckPoints->data[0];
            LUp[1] = CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
              (CheckPoints->size[0] + CheckPoints->size[0]) - 1)];
            LDp[1] = CheckPoints->data[CheckPoints->size[0]];
            LUp[2] = CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
              (CheckPoints->size[0] + static_cast<int32_T>(CheckPoints->size[0] <<
              1)) - 1)];
            LDp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              << 1)];
            LUp[3] = CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
              (CheckPoints->size[0] + static_cast<int32_T>(CheckPoints->size[0] *
              3)) - 1)];
            LDp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              * 3)];
            PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LUp, LDp,
              100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint_0->
              size[0] * dummyWayPoint_0->size[1]);

            // MATLAB Function: '<S168>/WayPointGenerator'
            dummyWayPoint_0->size[0] = static_cast<int32_T>(dummyWayPoint->size
              [0] + segWayPoints->size[0]);
            dummyWayPoint_0->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (dummyWayPoint_0, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S168>/WayPointGenerator'
            ibmat = dummyWayPoint->size[0];
            loop_ub = segWayPoints->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                dummyWayPoint_0->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (dummyWayPoint_0->size[0] * b_nrows))] = dummyWayPoint->data[
                  static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(dummyWayPoint->size[0] * b_nrows))];
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n++)
              {
                dummyWayPoint_0->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + dummyWayPoint->size[0]) +
                  static_cast<int32_T>(dummyWayPoint_0->size[0] * b_nrows))] =
                  segWayPoints->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (segWayPoints->size[0] * b_nrows))];
              }
            }

            rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0]
              * dummyWayPoint->size[1]);

            // MATLAB Function: '<S168>/WayPointGenerator'
            dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
            dummyWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (dummyWayPoint, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S168>/WayPointGenerator'
            ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
            for (b_nrows = 0; b_nrows <= static_cast<int32_T>(ibmat - 1);
                 b_nrows++) {
              dummyWayPoint->data[b_nrows] = dummyWayPoint_0->data[b_nrows];
            }

            nrowx = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
            nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
            for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                 (b_nrows + 1)) {
              dummyWayPoint->data[b_nrows] = dummyWayPoint->data
                [static_cast<int32_T>(b_nrows + 1)];
            }

            for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                 (b_nrows + 1)) {
              dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                dummyWayPoint->size[0])] = dummyWayPoint->data
                [static_cast<int32_T>(static_cast<int32_T>(b_nrows +
                dummyWayPoint->size[0]) + 1)];
            }

            for (b_nrows = 0; b_nrows <= nrowx; b_nrows = static_cast<int32_T>
                 (b_nrows + 1)) {
              dummyWayPoint->data[static_cast<int32_T>(b_nrows +
                static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                (b_nrows + static_cast<int32_T>(dummyWayPoint->size[0] << 1)) +
                1)];
            }

            if (1 > nrows) {
              ibmat = -1;
            } else {
              ibmat = nrowx;
            }

            rtb_ClockwiseRotation_n = static_cast<int32_T>(segWayPoints->size[0]
              * segWayPoints->size[1]);

            // MATLAB Function: '<S168>/WayPointGenerator'
            segWayPoints->size[0] = static_cast<int32_T>(ibmat + 1);
            segWayPoints->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (segWayPoints, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S168>/WayPointGenerator'
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <= ibmat;
                   rtb_ClockwiseRotation_n++) {
                segWayPoints->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                  + static_cast<int32_T>(segWayPoints->size[0] * b_nrows))] =
                  dummyWayPoint->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (dummyWayPoint->size[0] * b_nrows))];
              }
            }

            if (1 > nrows) {
              b_nrows = -1;
              nrowx = -1;
            } else {
              b_nrows = nrowx;
            }

            rtb_Switch_aa = std::ceil(10240.0 / static_cast<real_T>(static_cast<
              int32_T>(b_nrows + 1)));
            rtb_ClockwiseRotation_n = static_cast<int32_T>(dummyWayPoint->size[0]
              * dummyWayPoint->size[1]);

            // MATLAB Function: '<S168>/WayPointGenerator'
            dummyWayPoint->size[0] = static_cast<int32_T>(static_cast<int32_T>
              (nrowx + 1) * static_cast<int32_T>(rtb_Switch_aa));
            dummyWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (dummyWayPoint, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S168>/WayPointGenerator'
            b_nrows = segWayPoints->size[0];
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                 rtb_ClockwiseRotation_n = static_cast<int32_T>
                 (rtb_ClockwiseRotation_n + 1)) {
              nrows = static_cast<int32_T>(static_cast<int32_T>
                (rtb_ClockwiseRotation_n * b_nrows) + -1);
              for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                   static_cast<int32_T>(b_nrows - 1); loop_ub =
                   static_cast<int32_T>(loop_ub + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)] =
                  segWayPoints->data[static_cast<int32_T>(loop_ub - 1)];
              }
            }

            ibmat = static_cast<int32_T>(static_cast<int32_T>(segWayPoints->
              size[0] * static_cast<int32_T>(rtb_Switch_aa)) - 1);
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                 rtb_ClockwiseRotation_n = static_cast<int32_T>
                 (rtb_ClockwiseRotation_n + 1)) {
              nrows = static_cast<int32_T>(static_cast<int32_T>
                (rtb_ClockwiseRotation_n * b_nrows) + ibmat);
              for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                   static_cast<int32_T>(b_nrows - 1); loop_ub =
                   static_cast<int32_T>(loop_ub + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)] =
                  segWayPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (b_nrows + loop_ub) - 1)];
              }
            }

            nrowx = static_cast<int32_T>(segWayPoints->size[0] << 1);
            ibmat = static_cast<int32_T>(static_cast<int32_T>
              (static_cast<int32_T>(segWayPoints->size[0] * static_cast<int32_T>
              (rtb_Switch_aa)) << 1) - 1);
            for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                 static_cast<int32_T>(static_cast<int32_T>(rtb_Switch_aa) - 1);
                 rtb_ClockwiseRotation_n = static_cast<int32_T>
                 (rtb_ClockwiseRotation_n + 1)) {
              nrows = static_cast<int32_T>(static_cast<int32_T>
                (rtb_ClockwiseRotation_n * b_nrows) + ibmat);
              for (loop_ub = 1; static_cast<int32_T>(loop_ub - 1) <=
                   static_cast<int32_T>(b_nrows - 1); loop_ub =
                   static_cast<int32_T>(loop_ub + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(nrows + loop_ub)] =
                  segWayPoints->data[static_cast<int32_T>(static_cast<int32_T>
                  (nrowx + loop_ub) - 1)];
              }
            }

            // Reshape: '<S7>/Reshape2Row' incorporates:
            //   Memory: '<S7>/MemoryPrevRelPos'

            rtb_Reshape_i[0] = localDW->MemoryPrevRelPos_PreviousInput[1];
            rtb_Reshape_i[1] = localDW->MemoryPrevRelPos_PreviousInput[0];
            rtb_Reshape_i[2] = localDW->MemoryPrevRelPos_PreviousInput[2];

            // Product: '<S168>/RotateRelPrevPos' incorporates:
            //   MATLABSystem: '<S168>/RotateATMissionHdg'

            rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtb_Reshape_i,
              localB->RotateATMissionHdg_baf.RotateATMissionHdg, rtb_startPose_h);

            // MATLAB Function: '<S168>/WayPointGenerator'
            LDp[0] = rtb_startPose_h[0];
            LDp[1] = rtb_startPose_h[1];
            LDp[2] = rtb_startPose_h[2];
            LDp[3] = 1.5707963267948966;
            LUp[0] = CheckPoints->data[0];
            LUp[1] = CheckPoints->data[CheckPoints->size[0]];
            LUp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              << 1)];
            LUp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
              * 3)];
            PreemptableMissionModeSelector_genSegWP_la(&connectionObj, LDp, LUp,
              100.0, segWayPoints, localB);
            rtb_ClockwiseRotation_n = static_cast<int32_T>(initWayPoint->size[0]
              * initWayPoint->size[1]);

            // MATLAB Function: '<S168>/WayPointGenerator'
            initWayPoint->size[0] = static_cast<int32_T>(segWayPoints->size[0] +
              dummyWayPoint->size[0]);
            initWayPoint->size[1] = 3;
            PreemptableMissionModeSelector_emxEnsureCapacity_real_T_c
              (initWayPoint, rtb_ClockwiseRotation_n);

            // MATLAB Function: '<S168>/WayPointGenerator'
            ibmat = segWayPoints->size[0];
            loop_ub = dummyWayPoint->size[0];
            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(ibmat - 1); rtb_ClockwiseRotation_n++) {
                initWayPoint->data[static_cast<int32_T>(rtb_ClockwiseRotation_n
                  + static_cast<int32_T>(initWayPoint->size[0] * b_nrows))] =
                  segWayPoints->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (segWayPoints->size[0] * b_nrows))];
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n <=
                   static_cast<int32_T>(loop_ub - 1); rtb_ClockwiseRotation_n++)
              {
                initWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + segWayPoints->size[0]) +
                  static_cast<int32_T>(initWayPoint->size[0] * b_nrows))] =
                  dummyWayPoint->data[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + static_cast<int32_T>
                   (dummyWayPoint->size[0] * b_nrows))];
              }

              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                   rtb_ClockwiseRotation_n++) {
                localB->WayPoint[static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(10240 * b_nrows))] = initWayPoint->data[
                  static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(initWayPoint->size[0] * b_nrows))];
              }
            }

            // MATLAB Function: '<S168>/biasWayPoint'
            for (b_nrows = 0; b_nrows < 10240; b_nrows++) {
              localB->rtb_WayPoint_m[b_nrows] = localB->WayPoint[b_nrows] +
                rtb_Switch_e;
              localB->rtb_WayPoint_m[static_cast<int32_T>(b_nrows + 10240)] =
                localB->WayPoint[static_cast<int32_T>(b_nrows + 10240)];
              localB->rtb_WayPoint_m[static_cast<int32_T>(b_nrows + 20480)] =
                localB->WayPoint[static_cast<int32_T>(b_nrows + 20480)];
            }

            // Product: '<S168>/RotateIndivWayPoint' incorporates:
            //   MATLABSystem: '<S168>/RotateATMissionHdg'

            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              for (rtb_ClockwiseRotation_n = 0; rtb_ClockwiseRotation_n < 10240;
                   rtb_ClockwiseRotation_n++) {
                ibmat = static_cast<int32_T>(rtb_ClockwiseRotation_n +
                  static_cast<int32_T>(10240 * b_nrows));
                localB->RotateIndivWayPoint[ibmat] = 0.0;
                localB->RotateIndivWayPoint[ibmat] +=
                  localB->RotateATMissionHdg_baf.RotateATMissionHdg
                  [static_cast<int32_T>(3 * b_nrows)] * localB->
                  rtb_WayPoint_m[rtb_ClockwiseRotation_n];
                localB->RotateIndivWayPoint[ibmat] +=
                  localB->RotateATMissionHdg_baf.RotateATMissionHdg
                  [static_cast<int32_T>(static_cast<int32_T>(3 * b_nrows) + 1)] *
                  localB->rtb_WayPoint_m[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 10240)];
                localB->RotateIndivWayPoint[ibmat] +=
                  localB->RotateATMissionHdg_baf.RotateATMissionHdg[static_cast<
                  int32_T>(static_cast<int32_T>(3 * b_nrows) + 2)] *
                  localB->rtb_WayPoint_m[static_cast<int32_T>
                  (rtb_ClockwiseRotation_n + 20480)];
              }
            }

            // MATLAB Function: '<S168>/biasNED'
            PreemptableMissionModeSelector_biasNED_l(rtb_ReshapeRowVec,
              localB->RotateIndivWayPoint, localB->nedWayPoint,
              &localB->sf_biasNED_j);
          }

          // End of Outputs for SubSystem: '<S7>/WayPointGenerator'
          PreemptableMissionModeSelector_WaypointFollower(rtu_Pose,
            localB->nedWayPoint, 200.0, &localB->WaypointFollower_baf,
            &localDW->WaypointFollower_baf);

          // DataTypeConversion: '<S7>/Cast To Double' incorporates:
          //   Constant: '<S7>/LookAheadDis'
          //   MATLAB Function: '<S168>/WayPointGenerator'
          //   Memory: '<S7>/MemoryTriggerWP'

          *rty_thisTaskStatus = static_cast<real_T>
            (localB->WaypointFollower_baf.WaypointFollower_o5);

          // BusCreator: '<S7>/GuidanceCMDBusCreator' incorporates:
          //   DataTypeConversion: '<S7>/Param4'
          //   Gain: '<S7>/Down2Height'

          rty_GuidanceCmds->Height =
            -localB->WaypointFollower_baf.WaypointFollower_o1[2];
          rty_GuidanceCmds->AirSpeed = static_cast<real_T>
            (rtu_Parameters->Param4);
          rty_GuidanceCmds->HeadingAngle =
            localB->WaypointFollower_baf.WaypointFollower_o2;

          // Switch: '<S204>/Switch' incorporates:
          //   Abs: '<S204>/Abs'
          //   Bias: '<S204>/Bias'
          //   Bias: '<S204>/Bias1'
          //   Constant: '<S204>/Constant2'
          //   Constant: '<S205>/Constant'
          //   DataStoreRead: '<S7>/PrevLatitudeGCS'
          //   Math: '<S204>/Math Function1'
          //   RelationalOperator: '<S205>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Switch_p = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            rtb_Switch_p = LatitudeGCS;
          }

          // Abs: '<S201>/Abs1'
          rtb_Switch_aa = std::abs(rtb_Switch_p);

          // Switch: '<S201>/Switch' incorporates:
          //   Bias: '<S201>/Bias'
          //   Bias: '<S201>/Bias1'
          //   Constant: '<S192>/Constant'
          //   Constant: '<S192>/Constant1'
          //   Constant: '<S203>/Constant'
          //   Gain: '<S201>/Gain'
          //   Product: '<S201>/Divide1'
          //   RelationalOperator: '<S203>/Compare'
          //   Switch: '<S192>/Switch1'

          if (rtb_Switch_aa > 90.0) {
            // Signum: '<S201>/Sign1'
            if (rtb_Switch_p < 0.0) {
              rtb_Switch_p = -1.0;
            } else if (rtb_Switch_p > 0.0) {
              rtb_Switch_p = 1.0;
            } else if (rtb_Switch_p == 0.0) {
              rtb_Switch_p = 0.0;
            } else {
              rtb_Switch_p = (rtNaN);
            }

            rtb_Switch_p *= -(rtb_Switch_aa + -90.0) + 90.0;
            b_nrows = 180;
          } else {
            b_nrows = 0;
          }

          // Sum: '<S192>/Sum' incorporates:
          //   DataStoreRead: '<S7>/PrevLongitudeGCS'

          rtb_Sum = static_cast<real_T>(b_nrows) + LongitudeGCS;

          // Sum: '<S167>/Sum1'
          rtb_Switch_aa = rtu_PrevLocation->Lat - rtb_Switch_p;

          // Switch: '<S202>/Switch' incorporates:
          //   Abs: '<S202>/Abs'
          //   Bias: '<S202>/Bias'
          //   Bias: '<S202>/Bias1'
          //   Constant: '<S202>/Constant2'
          //   Constant: '<S206>/Constant'
          //   Math: '<S202>/Math Function1'
          //   RelationalOperator: '<S206>/Compare'

          if (std::abs(rtb_Sum) > 180.0) {
            rtb_Sum = rt_modd_snf(rtb_Sum + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S167>/Sum1'
          rtb_Sum = rtu_PrevLocation->Lon - rtb_Sum;

          // Switch: '<S198>/Switch' incorporates:
          //   Abs: '<S198>/Abs'
          //   Bias: '<S198>/Bias'
          //   Bias: '<S198>/Bias1'
          //   Constant: '<S198>/Constant2'
          //   Constant: '<S199>/Constant'
          //   Math: '<S198>/Math Function1'
          //   RelationalOperator: '<S199>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S195>/Abs1'
          rtb_Switch = std::abs(rtb_Switch_aa);

          // Switch: '<S195>/Switch' incorporates:
          //   Bias: '<S195>/Bias'
          //   Bias: '<S195>/Bias1'
          //   Constant: '<S191>/Constant'
          //   Constant: '<S191>/Constant1'
          //   Constant: '<S197>/Constant'
          //   Gain: '<S195>/Gain'
          //   Product: '<S195>/Divide1'
          //   RelationalOperator: '<S197>/Compare'
          //   Switch: '<S191>/Switch1'

          if (rtb_Switch > 90.0) {
            // Signum: '<S195>/Sign1'
            if (rtb_Switch_aa < 0.0) {
              rtb_Switch_aa = -1.0;
            } else if (rtb_Switch_aa > 0.0) {
              rtb_Switch_aa = 1.0;
            } else if (rtb_Switch_aa == 0.0) {
              rtb_Switch_aa = 0.0;
            } else {
              rtb_Switch_aa = (rtNaN);
            }

            rtb_Switch = (-(rtb_Switch + -90.0) + 90.0) * rtb_Switch_aa;
            b_nrows = 180;
          } else {
            rtb_Switch = rtb_Switch_aa;
            b_nrows = 0;
          }

          // Sum: '<S191>/Sum'
          rtb_Switch_aa = static_cast<real_T>(b_nrows) + rtb_Sum;

          // UnitConversion: '<S209>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Switch_p *= 0.017453292519943295;

          // Trigonometry: '<S210>/Trigonometric Function1'
          rtb_Sum = std::sin(rtb_Switch_p);

          // Sum: '<S210>/Sum1' incorporates:
          //   Constant: '<S210>/Constant'
          //   Product: '<S210>/Product1'

          rtb_Sum = 1.0 - PreemptableMissionModeSelector_ConstB.sqrt_c *
            PreemptableMissionModeSelector_ConstB.sqrt_c * rtb_Sum * rtb_Sum;

          // Product: '<S208>/Product1' incorporates:
          //   Constant: '<S208>/Constant1'
          //   Sqrt: '<S208>/sqrt'

          rtb_SumInitEast_j = 6.378137E+6 / std::sqrt(rtb_Sum);

          // Product: '<S208>/Product4' incorporates:
          //   Trigonometry: '<S208>/Trigonometric Function'

          rtb_Switch_p = rtb_SumInitEast_j * std::cos(rtb_Switch_p);

          // Product: '<S193>/dNorth' incorporates:
          //   Constant: '<S208>/Constant2'
          //   Product: '<S208>/Product3'
          //   Trigonometry: '<S208>/Trigonometric Function1'
          //   UnitConversion: '<S194>/Unit Conversion'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_SumInitEast_j = 0.017453292519943295 * rtb_Switch / rt_atan2d_snf
            (1.0, rtb_SumInitEast_j *
             PreemptableMissionModeSelector_ConstB.Sum1_in / rtb_Sum);

          // Switch: '<S196>/Switch' incorporates:
          //   Abs: '<S196>/Abs'
          //   Bias: '<S196>/Bias'
          //   Bias: '<S196>/Bias1'
          //   Constant: '<S196>/Constant2'
          //   Constant: '<S200>/Constant'
          //   Math: '<S196>/Math Function1'
          //   RelationalOperator: '<S200>/Compare'

          if (std::abs(rtb_Switch_aa) > 180.0) {
            rtb_Switch_aa = rt_modd_snf(rtb_Switch_aa + 180.0, 360.0) + -180.0;
          }

          // Product: '<S193>/dEast' incorporates:
          //   Constant: '<S208>/Constant3'
          //   Trigonometry: '<S208>/Trigonometric Function2'
          //   UnitConversion: '<S194>/Unit Conversion'

          rtb_Sum = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_p) *
            (0.017453292519943295 * rtb_Switch_aa);

          // Sum: '<S193>/Sum2' incorporates:
          //   Product: '<S193>/x*cos'
          //   Product: '<S193>/y*sin'

          rtb_Switch = rtb_Sum * 0.0 + rtb_SumInitEast_j;

          // Sum: '<S193>/Sum3' incorporates:
          //   Product: '<S193>/x*sin'
          //   Product: '<S193>/y*cos'

          rtb_SumInitEast_j = rtb_Sum - rtb_SumInitEast_j * 0.0;

          // Reshape: '<S7>/Reshape' incorporates:
          //   Bias: '<S7>/Rotate90deg'
          //   Constant: '<S7>/InitialFlightPathAngle'
          //   Constant: '<S7>/InitialRollAngle'
          //   Constant: '<S7>/InitialRollAngleRate'
          //   DataTypeConversion: '<S7>/Param4'
          //   Gain: '<S7>/Down2Up'
          //   Product: '<S7>/ProductEast'
          //   Product: '<S7>/ProductNorth'
          //   Sum: '<S7>/SumInitEast'
          //   Sum: '<S7>/SumInitNorth'
          //   Trigonometry: '<S7>/Cos'
          //   Trigonometry: '<S7>/Sin'

          rty_InitialState[0] = std::cos(rtb_Gain1 + 1.5707963267948966) *
            rtb_Switch_e + rtb_Switch;
          rty_InitialState[1] = std::sin(rtb_Gain1 + 1.5707963267948966) *
            rtb_Switch_e + rtb_SumInitEast_j;
          rty_InitialState[2] = -rtb_Down_c;
          rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
          rty_InitialState[4] = rtb_Gain1;
          rty_InitialState[5] = 0.0;
          rty_InitialState[6] = 0.0;
          rty_InitialState[7] = 0.0;

          // Update for Memory: '<S7>/MemoryPrevRelPos' incorporates:
          //   Sum: '<S7>/RelPrevPos'

          localDW->MemoryPrevRelPos_PreviousInput[0] = rtb_Switch - rtb_Abs1_jo;
          localDW->MemoryPrevRelPos_PreviousInput[1] = rtb_SumInitEast_j -
            rtb_Param4_e;
          localDW->MemoryPrevRelPos_PreviousInput[2] = rtb_Down_c - rtb_Down;

          // Update for Memory: '<S7>/MemoryTriggerWP' incorporates:
          //   Constant: '<S7>/TirggerWayPointGen'

          localDW->MemoryTriggerWP_PreviousInput = 1.0;
        }
        break;
      }
    }

    PreemptableMissionModeSelector_emxFree_real_T_n(&dummyWayPoint_3);
    PreemptableMissionModeSelector_emxFree_real_T_n(&dummyWayPoint_2);
    PreemptableMissionModeSelector_emxFree_real_T_n(&dummyWayPoint_1);
    PreemptableMissionModeSelector_emxFree_real_T_n(&dummyWayPoint_0);
    PreemptableMissionModeSelector_emxFree_real_T_n(&segWayPoints);
    PreemptableMissionModeSelector_emxFree_real_T_n(&dummyWayPoint);
    PreemptableMissionModeSelector_emxFree_real_T_n(&CheckPoints);
    PreemptableMissionModeSelector_emxFree_real_T_n(&initWayPoint);
  }

  // End of Chart: '<Root>/PreemptableMissionModeSelector'
}

// Model initialize function
void PreemptableMissionModeSelector_initialize(const char_T **rt_errorStatus,
  RT_MODEL_PreemptableMissionModeSelector_T *const
  PreemptableMissionModeSelector_M, ZCE_PreemptableMissionModeSelector_T
  *localZCE)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatusPointer(PreemptableMissionModeSelector_M, rt_errorStatus);
  localZCE->WayPointGenerator_Trig_ZCE_p = UNINITIALIZED_ZCSIG;
  localZCE->WayPointGenerator_Trig_ZCE_e = UNINITIALIZED_ZCSIG;
  localZCE->WayPointGenerator_Trig_ZCE_a = UNINITIALIZED_ZCSIG;
  localZCE->WayPointGenerator_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

//
// File trailer for generated code.
//
// [EOF]
//
