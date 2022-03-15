//
// File: FlightMissionMode.cpp
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 2.689
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Jul  2 08:01:55 2021
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
#include "FlightMissionMode.h"
#include "FlightMissionMode_private.h"
#include "mod_dBqh4Vat.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf.h"
#include "rt_remd_snf.h"
#include "skip_to_last_equal_value_ZlLNIyBv.h"
#include "wrapToPi_iEuDNbvh.h"

// Named constants for Chart: '<Root>/PreemptableMissionModeSelector'
const uint8_T FlightMissionMode_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T FlightMissionMode_IN_OrbitFollower{ 1U };

const uint8_T FlightMissionMode_IN_ProtLine{ 2U };

const uint8_T FlightMissionMode_IN_RunWayNav{ 3U };

const uint8_T FlightMissionMode_IN_WaitToStart{ 4U };

const uint8_T FlightMissionMode_IN_WaypointFollower{ 5U };

// Named constants for Chart: '<S160>/ModeSwitch'
const uint8_T FlightMissionMode_IN_Bottom{ 1U };

const uint8_T FlightMissionMode_IN_Left{ 2U };

const uint8_T FlightMissionMode_IN_Right{ 3U };

const uint8_T FlightMissionMode_IN_Top{ 4U };

// Named constants for Chart: '<S198>/ModeSwitch'
const uint8_T FlightMissionMode_IN_Init{ 1U };

const uint8_T FlightMissionMode_IN_Running{ 2U };

const FixedWingGuidanceBus FlightMissionMode_rtZFixedWingGuidanceBus{
    0.0,                               // Height
    0.0,                               // AirSpeed
    0.0                                // HeadingAngle
} ;                                    // FixedWingGuidanceBus ground

// Forward declaration for local functions
static real_T FlightMissionMode_norm(const real_T x[2]);
static real_T FlightMissionMode_norm_p(const real_T x[3]);
static real_T FlightMissionMode_angdiff(real_T x, real_T y);

// Forward declaration for local functions
static void FlightMissionMode_emxInit_real_T(emxArray_real_T_FlightMissionMode_T
    **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_real_T
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_WaypointFollowerBase_getDistinctWpts(const real_T
    waypoints[30720], emxArray_real_T_FlightMissionMode_T *distinctWpts,
    DW_WaypointFollower_FlightMissionMode_T *localDW);
static real_T FlightMissionMode_norm_pv(const real_T x[3]);
static void FlightMissionMode_WaypointFollowerBase_createWaypoint
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, real_T
     virtualWaypoint[3]);
static void FlightMissionMode_emxFree_real_T(emxArray_real_T_FlightMissionMode_T
    **pEmxArray);
static void FlightMissionMode_WaypointFollowerBase_getWaypoints
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, const
     emxArray_real_T_FlightMissionMode_T *waypoints, real_T startWaypoint[3],
     real_T endWaypoint[3]);
static void FlightMissionMode_WaypointFollowerBase_endWaypointReached_b
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, const
     emxArray_real_T_FlightMissionMode_T *waypoints, real_T curStartWaypoint[3],
     real_T curEndWaypoint[3], const real_T currentPose[4]);
static real_T FlightMissionMode_WaypointFollowerBase_pointToLine(const real_T
    p1[3], const real_T p2[3], const real_T p[3]);
static real_T FlightMissionMode_WaypointFollowerBase_projectToLine(const real_T
    startWaypoint[3], const real_T endWaypoint[3], const real_T currentPosition
    [3]);
static void FlightMissionMode_WaypointFollowerBase_getLookahead(const
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, const
    real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
    currentPosition[3], real_T lookaheadPoint[3]);
static void FlightMissionMode_WaypointFollowerBase_stepInternal
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, const
     real_T currentPose[4], const real_T waypointsIn[30720], real_T
     lookaheadDist, real_T lookaheadPoint[3], real_T *desiredHeading, real_T
     *desiredYaw, uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T
     *status, DW_WaypointFollower_FlightMissionMode_T *localDW);

// Forward declaration for local functions
static void FlightMissionMode_WaypointFollowerBase_getDistinctWpts_j(const
    real_T waypoints[300], real_T distinctWpts_data[], int32_T
    distinctWpts_size[2]);
static real_T FlightMissionMode_norm_pve(const real_T x[3]);
static void FlightMissionMode_WaypointFollowerBase_createWaypoint_h
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj,
     real_T virtualWaypoint[3]);
static void FlightMissionMode_WaypointFollowerBase_getWaypoints_m
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj,
     const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
     startWaypoint[3], real_T endWaypoint[3]);
static void FlightMissionMode_WaypointFollowerBase_endWaypointReached_b5d
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj,
     const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
     curStartWaypoint[3], real_T curEndWaypoint[3], const real_T currentPose[4]);
static real_T FlightMissionMode_WaypointFollowerBase_pointToLine_k(const real_T
    p1[3], const real_T p2[3], const real_T p[3]);
static real_T FlightMissionMode_WaypointFollowerBase_projectToLine_m(const
    real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
    currentPosition[3]);
static void FlightMissionMode_WaypointFollowerBase_getLookahead_d(const
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj, const
    real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
    currentPosition[3], real_T lookaheadPoint[3]);
static void FlightMissionMode_WaypointFollowerBase_stepInternal_f
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj,
     const real_T currentPose[4], const real_T waypointsIn[300], real_T
     lookaheadDist, real_T lookaheadPoint[3], real_T *desiredHeading, real_T
     *desiredYaw, uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T
     *status);

// Forward declaration for local functions
static void FlightMissionMode_emxInit_real_T_l
    (emxArray_real_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
    *FlightMissionMode_NameValueParser_NameValueParser
    (matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
     *obj);
static void FlightMissionMode_validatestring(const char_T str[7], char_T
    out_data[], int32_T out_size[2]);
static boolean_T FlightMissionMode_strcmp(const char_T a_data[], const int32_T
    a_size[2]);
static void FlightMissionMode_merge(int32_T idx_data[], int32_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T
    xwork_data[]);
static void FlightMissionMode_sort(int32_T x_data[], const int32_T *x_size,
    int32_T idx_data[], int32_T *idx_size);
static void FlightMissionMode_do_vectors(real_T c_data[], int32_T c_size[2],
    int32_T ia_data[], int32_T *ia_size, int32_T *ib_size);
static void FlightMissionMode_do_vectors_g(const real_T b_data[], const int32_T *
    b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[], int32_T
    *ia_size, int32_T *ib_size);
static void FlightMissionMode_merge_l(int32_T idx_data[], real_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
    xwork_data[]);
static void FlightMissionMode_sortIdx(real_T x_data[], int32_T *x_size, int32_T
    idx_data[], int32_T *idx_size);
static void FlightMissionMode_sort_b(real_T x_data[], const int32_T *x_size);
static void FlightMissionMode_uavDubinsConnection_findDisabledIndices(real_T
    idx_data[], int32_T *idx_size);
static void* FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable(real_T
    airSpeed, real_T maxRollAngle, const real_T flightPathAngle[2], const real_T
    disabledPathTypes_data[], const int32_T *disabledPathTypes_size);
static void FlightMissionMode_emxEnsureCapacity_real_T_p
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_emxFree_real_T_j
    (emxArray_real_T_FlightMissionMode_T **pEmxArray);
static boolean_T FlightMissionMode_strcmp_k(const char_T a_data[], const int32_T
    a_size[2]);
static boolean_T FlightMissionMode_strcmp_ka(const char_T a_data[], const
    int32_T a_size[2]);
static void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_i(const
    real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
    varargin_4, real_T varargin_5, real_T varargin_6, const
    cell_wrap_10_FlightMissionMode_T varargin_7[4], const real_T varargin_8[4],
    uavDubinsPathSegment_FlightMissionMode_T *b_this);
static real_T FlightMissionMode_sum(const real_T x_data[]);
static void FlightMissionMode_uavDubinsBuiltins_connect(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPose[4],
    const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
    real_T dpt_data[], const int32_T *dpt_size,
    uavDubinsPathSegment_FlightMissionMode_T pathSegObjs_data[], int32_T
    *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
    DW_WayPointGenerator_FlightMissionMode_T *localDW);
static void FlightMissionMode_uavDubinsConnection_connect(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPoses[4],
    const real_T goalPoses[4], uavDubinsPathSegment_FlightMissionMode_T
    pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
    int32_T *pathCosts_size, DW_WayPointGenerator_FlightMissionMode_T *localDW);
static void FlightMissionMode_strcmp_kav(const cell_wrap_10_FlightMissionMode_T
    a[4], boolean_T b_bool[4]);
static boolean_T FlightMissionMode_any(const boolean_T x[4]);
static void FlightMissionMode_useConstantDim(const real_T varargin_2_data[],
    const int32_T varargin_2_size[2], real_T varargout_1_data[], int32_T
    varargout_1_size[2]);
static void FlightMissionMode_emxInit_int32_T
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_int32_T
    (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_emxInit_real_T1
    (emxArray_real_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_real_T1
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_emxInit_int32_T1
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_int32_T1
    (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_emxFree_int32_T
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray);
static void FlightMissionMode_merge_lv(emxArray_int32_T_FlightMissionMode_T *idx,
    emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T np, int32_T
    nq, emxArray_int32_T_FlightMissionMode_T *iwork,
    emxArray_real_T_FlightMissionMode_T *xwork);
static void FlightMissionMode_merge_block(emxArray_int32_T_FlightMissionMode_T
    *idx, emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T n,
    int32_T preSortLevel, emxArray_int32_T_FlightMissionMode_T *iwork,
    emxArray_real_T_FlightMissionMode_T *xwork);
static void FlightMissionMode_sort_bq(emxArray_real_T_FlightMissionMode_T *x);
static void FlightMissionMode_emxInit_boolean_T
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxFree_boolean_T
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray);
static void FlightMissionMode_emxEnsureCapacity_boolean_T
    (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_emxInit_boolean_T1
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_boolean_T1
    (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_wrapToPi(emxArray_real_T_FlightMissionMode_T
    *theta);
static void FlightMissionMode_eml_find(const
    emxArray_boolean_T_FlightMissionMode_T *x,
    emxArray_int32_T_FlightMissionMode_T *i);
static boolean_T FlightMissionMode_strcmp_kavm(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_kavm1(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_kavm1m(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_kavm1mq(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_kavm1mqe(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_kavm1mqel(const char_T a_data[], const
    int32_T a_size[2]);
static void FlightMissionMode_mtimes(const emxArray_real_T_FlightMissionMode_T
    *A, const real_T B[4], emxArray_real_T_FlightMissionMode_T *C);
static void FlightMissionMode_uavDubinsPathSegment_interpolate(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_10_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length,
    emxArray_real_T_FlightMissionMode_T *samples,
    emxArray_real_T_FlightMissionMode_T *poses);
static void FlightMissionMode_genSegWP(const
    uavDubinsConnection_FlightMissionMode_T *connectionObj, const real_T start[4],
    const real_T ende[4], real_T numWPs, emxArray_real_T_FlightMissionMode_T
    *segWayPoints, DW_WayPointGenerator_FlightMissionMode_T *localDW);

// Forward declaration for local functions
static void FlightMissionMode_exit_internal_GuidanceLogic
    (DW_FlightMissionMode_f_T *localDW);
static void FlightMissionMode_emxInit_real_T_h
    (emxArray_real_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxFree_real_T_n
    (emxArray_real_T_FlightMissionMode_T **pEmxArray);
static uavDubinsConnection_FlightMissionMode_T
    *FlightMissionMode_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_FlightMissionMode_T *b_this);
static matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
    *FlightMissionMode_NameValueParser_NameValueParser_p
    (matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
     *obj);
static void FlightMissionMode_validatestring_o(const char_T str[7], char_T
    out_data[], int32_T out_size[2]);
static boolean_T FlightMissionMode_strcmp_k4(const char_T a_data[], const
    int32_T a_size[2]);
static void FlightMissionMode_merge_a(int32_T idx_data[], int32_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T
    xwork_data[]);
static void FlightMissionMode_sort_o(int32_T x_data[], const int32_T *x_size,
    int32_T idx_data[], int32_T *idx_size);
static void FlightMissionMode_do_vectors_o(real_T c_data[], int32_T c_size[2],
    int32_T ia_data[], int32_T *ia_size, int32_T *ib_size);
static void FlightMissionMode_do_vectors_o2(const real_T b_data[], const int32_T
    *b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[], int32_T
    *ia_size, int32_T *ib_size);
static void FlightMissionMode_merge_a5(int32_T idx_data[], real_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
    xwork_data[]);
static void FlightMissionMode_sortIdx_i(real_T x_data[], int32_T *x_size,
    int32_T idx_data[], int32_T *idx_size);
static void FlightMissionMode_sort_o4(real_T x_data[], const int32_T *x_size);
static void FlightMissionMode_uavDubinsConnection_findDisabledIndices_i(real_T
    idx_data[], int32_T *idx_size);
static void* FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable_o(real_T
    airSpeed, real_T maxRollAngle, const real_T flightPathAngle[2], const real_T
    disabledPathTypes_data[], const int32_T *disabledPathTypes_size);
static void FlightMissionMode_emxEnsureCapacity_real_T_c
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static boolean_T FlightMissionMode_strcmp_k4q(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_k4qz(const char_T a_data[], const
    int32_T a_size[2]);
static void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_ll(const
    real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
    varargin_4, real_T varargin_5, real_T varargin_6, const
    cell_wrap_1_FlightMissionMode_T varargin_7[4], const real_T varargin_8[4],
    uavDubinsPathSegment_FlightMissionMode_b_T *b_this);
static real_T FlightMissionMode_sum_l(const real_T x_data[]);
static void FlightMissionMode_uavDubinsBuiltins_connect_fo(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPose[4],
    const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
    real_T dpt_data[], const int32_T *dpt_size,
    uavDubinsPathSegment_FlightMissionMode_b_T pathSegObjs_data[], int32_T
    *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
    DW_FlightMissionMode_f_T *localDW);
static void FlightMissionMode_uavDubinsConnection_connect_o(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPoses[4],
    const real_T goalPoses[4], uavDubinsPathSegment_FlightMissionMode_b_T
    pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
    int32_T *pathCosts_size, DW_FlightMissionMode_f_T *localDW);
static void FlightMissionMode_strcmp_gfbp(const cell_wrap_1_FlightMissionMode_T
    a[4], boolean_T b_bool[4]);
static boolean_T FlightMissionMode_any_e(const boolean_T x[4]);
static void FlightMissionMode_useConstantDim_h(const real_T varargin_2_data[],
    const int32_T varargin_2_size[2], real_T varargout_1_data[], int32_T
    varargout_1_size[2]);
static void FlightMissionMode_emxInit_real_T1_o
    (emxArray_real_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_eml_find_d(boolean_T x, int32_T i_data[], int32_T
    i_size[2]);
static void FlightMissionMode_emxEnsureCapacity_real_T1_g
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static boolean_T FlightMissionMode_strcmp_k4qzjr(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_k4qzjrh(const char_T a_data[], const
    int32_T a_size[2]);
static void FlightMissionMode_emxInit_boolean_T1_g
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_boolean_T1_j
    (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_emxFree_boolean_T_n
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray);
static void FlightMissionMode_wrapToPi_l(emxArray_real_T_FlightMissionMode_T
    *theta);
static boolean_T FlightMissionMode_strcmp_k4qzjrhe(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_k4qzjrhe2(const char_T a_data[], const
    int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_k4qzjrhe2c(const char_T a_data[],
    const int32_T a_size[2]);
static boolean_T FlightMissionMode_strcmp_k4qzjrhe2c2(const char_T a_data[],
    const int32_T a_size[2]);
static void FlightMissionMode_mtimes_l(const emxArray_real_T_FlightMissionMode_T
    *A, const real_T B[4], emxArray_real_T_FlightMissionMode_T *C);
static void FlightMissionMode_uavDubinsPathSegment_interpolate_g(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_1_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length, real_T samples, real_T
    poses_data[], int32_T poses_size[2]);
static void FlightMissionMode_wrapToPi_d(real_T theta_data[], int32_T
    *theta_size);
static void FlightMissionMode_sin(real_T x_data[], const int32_T *x_size);
static void FlightMissionMode_cos(real_T x_data[], const int32_T *x_size);
static void FlightMissionMode_mtimes_k(const real_T A_data[], const int32_T
    A_size[2], const real_T B[4], real_T C_data[], int32_T C_size[2]);
static void FlightMissionMode_uavDubinsPathSegment_interpolate_f(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_1_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length, real_T samples, real_T
    poses_data[], int32_T poses_size[2]);
static void FlightMissionMode_emxInit_int32_T_k
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_int32_T_j
    (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_emxInit_int32_T1_l
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_int32_T1_k
    (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_emxFree_int32_T_a
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray);
static void FlightMissionMode_merge_a5o(emxArray_int32_T_FlightMissionMode_T
    *idx, emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T np,
    int32_T nq, emxArray_int32_T_FlightMissionMode_T *iwork,
    emxArray_real_T_FlightMissionMode_T *xwork);
static void FlightMissionMode_merge_block_h(emxArray_int32_T_FlightMissionMode_T
    *idx, emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T n,
    int32_T preSortLevel, emxArray_int32_T_FlightMissionMode_T *iwork,
    emxArray_real_T_FlightMissionMode_T *xwork);
static void FlightMissionMode_sort_o4u(emxArray_real_T_FlightMissionMode_T *x);
static void FlightMissionMode_emxInit_boolean_T_c
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
static void FlightMissionMode_emxEnsureCapacity_boolean_T_f
    (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
static void FlightMissionMode_eml_find_f(const
    emxArray_boolean_T_FlightMissionMode_T *x,
    emxArray_int32_T_FlightMissionMode_T *i);
static void FlightMissionMode_uavDubinsPathSegment_interpolate_g1(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_1_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length,
    emxArray_real_T_FlightMissionMode_T *samples,
    emxArray_real_T_FlightMissionMode_T *poses);
static void FlightMissionMode_genSegWP_lm(const
    uavDubinsConnection_FlightMissionMode_T *connectionObj, const real_T start[4],
    const real_T ende[4], emxArray_real_T_FlightMissionMode_T *segWayPoints,
    DW_FlightMissionMode_f_T *localDW);
static void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_nv(const
    real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
    varargin_4, real_T varargin_5, real_T varargin_6, const
    cell_wrap_10_FlightMissionMode_T varargin_7[4], const real_T varargin_8[4],
    uavDubinsPathSegment_FlightMissionMode_T *b_this);
static void FlightMissionMode_uavDubinsBuiltins_connect_n(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPose[4],
    const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
    real_T dpt_data[], const int32_T *dpt_size,
    uavDubinsPathSegment_FlightMissionMode_T pathSegObjs_data[], int32_T
    *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
    DW_FlightMissionMode_f_T *localDW);
static void FlightMissionMode_uavDubinsConnection_connect_c(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPoses[4],
    const real_T goalPoses[4], uavDubinsPathSegment_FlightMissionMode_T
    pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
    int32_T *pathCosts_size, DW_FlightMissionMode_f_T *localDW);
static void FlightMissionMode_strcmp_k4qzj(const
    cell_wrap_10_FlightMissionMode_T a[4], boolean_T b_bool[4]);
static void FlightMissionMode_uavDubinsPathSegment_interpolate_e(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_10_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length,
    emxArray_real_T_FlightMissionMode_T *samples,
    emxArray_real_T_FlightMissionMode_T *poses);
static void FlightMissionMode_genSegWP_j(const
    uavDubinsConnection_FlightMissionMode_T *connectionObj, const real_T start[4],
    const real_T ende[4], real_T b_stepSize, emxArray_real_T_FlightMissionMode_T
    *segWayPoints, DW_FlightMissionMode_f_T *localDW);
static void FlightMissionMode_repmat(const emxArray_real_T_FlightMissionMode_T
    *a, real_T varargin_1, emxArray_real_T_FlightMissionMode_T *b);
static real_T FlightMissionMode_norm(const real_T x[2])
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

static real_T FlightMissionMode_norm_p(const real_T x[3])
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

static real_T FlightMissionMode_angdiff(real_T x, real_T y)
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
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                q = std::abs((delta + 3.1415926535897931) / 6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q -
                    std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
            }

            if (rEQ0) {
                thetaWrap = 0.0;
            } else if (delta + 3.1415926535897931 < 0.0) {
                thetaWrap += 6.2831853071795862;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
                (delta + 3.1415926535897931 > 0.0)))) {
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
void FlightMissionMode_OrbitFollower_Init(DW_OrbitFollower_FlightMissionMode_T
    *localDW)
{
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    localDW->obj.PrevResetSignal = 0.0;
    localDW->obj.NumCircles = 0.0;
    localDW->obj.OrbitRadiusInternal = (rtNaN);
    localDW->obj.PrevResetSignal *= 0.0;
    localDW->obj.NumCircles *= 0.0;
    localDW->obj.PrevPosition[0] = 0.0;
    localDW->obj.OrbitCenterInternal[0] = (rtNaN);
    localDW->obj.PrevPosition[0] *= 0.0;
    localDW->obj.PrevPosition[1] = 0.0;
    localDW->obj.OrbitCenterInternal[1] = (rtNaN);
    localDW->obj.PrevPosition[1] *= 0.0;
    localDW->obj.PrevPosition[2] = 0.0;
    localDW->obj.OrbitCenterInternal[2] = (rtNaN);
    localDW->obj.PrevPosition[2] *= 0.0;
    localDW->obj.StartFlag = true;
    localDW->obj.SelectTurnDirectionFlag = true;
    localDW->obj.TurnDirectionInternal = 1.0;
    localDW->obj.OrbitRadiusFlag = 0U;
    localDW->obj.LookaheadDistFlag = 0U;
}

//
// System reset for atomic system:
//    synthesized block
//    synthesized block
//
void FlightMissionMode_OrbitFollower_Reset(DW_OrbitFollower_FlightMissionMode_T *
    localDW)
{
    localDW->obj.OrbitRadiusInternal = (rtNaN);
    localDW->obj.PrevResetSignal *= 0.0;
    localDW->obj.NumCircles *= 0.0;
    localDW->obj.OrbitCenterInternal[0] = (rtNaN);
    localDW->obj.PrevPosition[0] *= 0.0;
    localDW->obj.OrbitCenterInternal[1] = (rtNaN);
    localDW->obj.PrevPosition[1] *= 0.0;
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
void FlightMissionMode_OrbitFollower(const real_T rtu_0[4], const real_T rtu_1[3],
    real_T rtu_2, real_T rtu_3, real_T rtu_4,
    DW_OrbitFollower_FlightMissionMode_T *localDW)
{
    real_T u[3];
    real_T v[3];
    real_T distToCenter_tmp[2];
    real_T rtu_0_0[2];
    real_T a;
    real_T absx;
    real_T distToCenter;
    real_T distToCenter_tmp_0;
    real_T rtu_0_tmp;
    real_T turnVector_idx_1;
    real_T u_tmp;
    real_T v_tmp;
    real_T x2;
    real_T x2_tmp;
    real_T xyCenter_idx_0;
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T b_exponent_1;
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T p;
    boolean_T p_0;
    x2 = rtu_2;
    localDW->obj.OrbitRadiusFlag = 0U;
    if (rtu_2 <= 220.0) {
        x2 = 220.0;
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
    if (FlightMissionMode_norm(rtu_0_0) < 2.47032822920623E-323) {
        localDW->OrbitFollower_o1[0] = x2 * std::cos(rtu_0[3]) + rtu_0[0];
        localDW->OrbitFollower_o1[1] = x2 * std::sin(rtu_0[3]) + rtu_0[1];
        localDW->OrbitFollower_o1[2] = rtu_1[2];
        localDW->OrbitFollower_o2 = rtu_0[3];
        localDW->OrbitFollower_o6 = localDW->obj.NumCircles;
    } else {
        p = false;
        p_0 = true;
        b_exponent = 0;
        exitg1 = false;
        while ((!exitg1) && (b_exponent < 3)) {
            if ((localDW->obj.OrbitCenterInternal[b_exponent] ==
                    rtu_1[b_exponent]) || (std::isnan
                    (localDW->obj.OrbitCenterInternal[b_exponent]) && std::isnan
                    (rtu_1[b_exponent]))) {
                b_exponent = static_cast<int32_T>(b_exponent + 1);
            } else {
                p_0 = false;
                exitg1 = true;
            }
        }

        if (p_0) {
            p = true;
        }

        guard1 = false;
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(p) ^
              1))) {
            guard1 = true;
        } else {
            p = false;
            if ((localDW->obj.OrbitRadiusInternal == x2) || (std::isnan
                    (localDW->obj.OrbitRadiusInternal) && std::isnan(x2))) {
                p = true;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (p) ^ 1))) {
                guard1 = true;
            }
        }

        if (guard1) {
            localDW->obj.NumCircles = 0.0;
            localDW->obj.OrbitCenterInternal[0] = rtu_1[0];
            localDW->obj.OrbitCenterInternal[1] = rtu_1[1];
            localDW->obj.OrbitCenterInternal[2] = rtu_1[2];
            localDW->obj.OrbitRadiusInternal = x2;
            localDW->obj.SelectTurnDirectionFlag = true;
        }

        if (distToCenter >= x2) {
            localDW->obj.LookaheadDistance = 0.9 * x2;
        } else {
            localDW->obj.LookaheadDistance = distToCenter;
        }

        distToCenter_tmp[0] = xyCenter_idx_0;
        distToCenter_tmp[1] = rtu_0_tmp;
        distToCenter = std::sqrt(rtu_0_tmp * rtu_0_tmp + xyCenter_idx_0 *
            xyCenter_idx_0);
        turnVector_idx_1 = x2 + localDW->obj.LookaheadDistance;
        a = std::abs(turnVector_idx_1);
        p = static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isinf(a)) ^ 1));
        p_0 = static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (std::isnan(a)) ^ 1));
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(p)
                & static_cast<int32_T>(p_0)))) {
            if (a <= 2.2250738585072014E-308) {
                absx = 4.94065645841247E-324;
            } else {
                frexp(a, &b_exponent_0);
                absx = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0 - 53));
            }
        } else {
            absx = (rtNaN);
        }

        guard1 = false;
        if (distToCenter >= turnVector_idx_1 - 5.0 * absx) {
            guard1 = true;
        } else {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (p) & static_cast<int32_T>(p_0)))) {
                if (a <= 2.2250738585072014E-308) {
                    absx = 4.94065645841247E-324;
                } else {
                    frexp(a, &b_exponent_1);
                    absx = std::ldexp(1.0, static_cast<int32_T>(b_exponent_1 -
                                       53));
                }
            } else {
                absx = (rtNaN);
            }

            if (distToCenter <= (x2 - localDW->obj.LookaheadDistance) + 5.0 *
                    absx) {
                guard1 = true;
            } else {
                if (localDW->obj.StartFlag) {
                    localDW->obj.PrevPosition[0] = rtu_0[0];
                    localDW->obj.PrevPosition[1] = rtu_0[1];
                    localDW->obj.StartFlag = false;
                }

                rtu_0_0[0] = xyCenter_idx_0;
                rtu_0_0[1] = rtu_0_tmp;
                absx = FlightMissionMode_norm(rtu_0_0);
                turnVector_idx_1 = localDW->obj.LookaheadDistance *
                    localDW->obj.LookaheadDistance;
                a = ((turnVector_idx_1 - x2 * x2) + absx * absx) / (2.0 * absx);
                x2_tmp = rtu_1[0] - rtu_0[0];
                x2 = x2_tmp * a / absx + rtu_0[0];
                distToCenter_tmp_0 = rtu_1[1] - rtu_0[1];
                distToCenter = distToCenter_tmp_0 * a / absx + rtu_0[1];
                a = std::sqrt(turnVector_idx_1 - a * a);
                turnVector_idx_1 = distToCenter_tmp_0 * a / absx;
                distToCenter_tmp[0] = x2 - turnVector_idx_1;
                distToCenter_tmp[1] = turnVector_idx_1 + x2;
                x2 = x2_tmp * a / absx;
                absx = x2 + distToCenter;
                distToCenter -= x2;
                if ((rtu_3 == 0.0) && (static_cast<boolean_T>
                                       (static_cast<int32_T>(static_cast<int32_T>
                        (localDW->obj.SelectTurnDirectionFlag) ^ 1)))) {
                    x2 = localDW->obj.TurnDirectionInternal;
                } else {
                    x2 = rtu_3;
                }

                a = localDW->obj.PrevPosition[0] - rtu_1[0];
                turnVector_idx_1 = localDW->obj.PrevPosition[1] - rtu_1[1];
                u[0] = a;
                u[1] = turnVector_idx_1;
                u[2] = 0.0;
                v[0] = xyCenter_idx_0;
                v[1] = rtu_0_tmp;
                v[2] = 0.0;
                if (x2 < 0.0) {
                    u[0] = xyCenter_idx_0;
                    v[0] = a;
                    u[1] = rtu_0_tmp;
                    v[1] = turnVector_idx_1;
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

                a = FlightMissionMode_norm_p(u);
                rtu_0_tmp = FlightMissionMode_norm_p(v);
                xyCenter_idx_0 = u[0] / a;
                turnVector_idx_1 = v[0] / rtu_0_tmp;
                u_tmp = u[1] / a;
                v_tmp = v[1] / rtu_0_tmp;
                localDW->obj.PrevPosition[0] = rtu_0[0];
                localDW->obj.PrevPosition[1] = rtu_0[1];
                localDW->obj.PrevPosition[2] = rtu_0[2];
                localDW->obj.NumCircles += rt_atan2d_snf(xyCenter_idx_0 * v_tmp
                    - turnVector_idx_1 * u_tmp, (xyCenter_idx_0 *
                    turnVector_idx_1 + u_tmp * v_tmp) + 0.0 / a * (0.0 /
                    rtu_0_tmp)) / 2.0 / 3.1415926535897931;
                localDW->OrbitFollower_o6 = localDW->obj.NumCircles;
                switch (static_cast<int32_T>(x2)) {
                  case 1:
                    if ((distToCenter_tmp[0] - rtu_0[0]) * distToCenter_tmp_0 -
                            (absx - rtu_0[1]) * x2_tmp > 0.0) {
                        xyCenter_idx_0 = distToCenter_tmp[0];
                        distToCenter = absx;
                    } else {
                        xyCenter_idx_0 = distToCenter_tmp[1];
                    }
                    break;

                  case -1:
                    if ((distToCenter_tmp[0] - rtu_0[0]) * distToCenter_tmp_0 -
                            (absx - rtu_0[1]) * x2_tmp < 0.0) {
                        xyCenter_idx_0 = distToCenter_tmp[0];
                        distToCenter = absx;
                    } else {
                        xyCenter_idx_0 = distToCenter_tmp[1];
                    }
                    break;

                  default:
                    if (std::abs(FlightMissionMode_angdiff(rt_atan2d_snf(absx -
                            rtu_0[1], distToCenter_tmp[0] - rtu_0[0]), rtu_0[3]))
                        < std::abs(FlightMissionMode_angdiff(rt_atan2d_snf
                            (distToCenter - rtu_0[1], distToCenter_tmp[1] -
                             rtu_0[0]), rtu_0[3]))) {
                        xyCenter_idx_0 = distToCenter_tmp[0];
                        distToCenter = absx;
                    } else {
                        xyCenter_idx_0 = distToCenter_tmp[1];
                    }

                    if ((xyCenter_idx_0 - rtu_0[0]) * distToCenter_tmp_0 -
                            (distToCenter - rtu_0[1]) * x2_tmp > 0.0) {
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
            a = FlightMissionMode_norm(distToCenter_tmp);
            xyCenter_idx_0 = xyCenter_idx_0 / a * x2 + rtu_1[0];
            distToCenter = rtu_0_tmp / a * x2 + rtu_1[1];
            localDW->OrbitFollower_o6 = localDW->obj.NumCircles;
        }

        localDW->OrbitFollower_o1[0] = xyCenter_idx_0;
        localDW->OrbitFollower_o1[1] = distToCenter;
        localDW->OrbitFollower_o1[2] = rtu_1[2];
        localDW->OrbitFollower_o2 = rt_atan2d_snf(distToCenter - rtu_0[1],
            xyCenter_idx_0 - rtu_0[0]);
    }
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
void FlightMissionMode_RotateATMissionHdg_Init
    (DW_RotateATMissionHdg_FlightMissionMode_T *localDW)
{
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
void FlightMissionMode_RotateATMissionHdg(const real_T rtu_0[3],
    DW_RotateATMissionHdg_FlightMissionMode_T *localDW)
{
    real_T out[9];
    real_T ct_idx_0;
    real_T ct_idx_1;
    real_T ct_idx_2;
    real_T out_tmp;
    real_T out_tmp_0;
    real_T st_idx_0;
    real_T st_idx_1;
    real_T st_idx_2;
    ct_idx_0 = std::cos(rtu_0[0]);
    ct_idx_1 = std::cos(rtu_0[1]);
    ct_idx_2 = std::cos(rtu_0[2]);
    st_idx_0 = std::sin(rtu_0[0]);
    st_idx_1 = std::sin(rtu_0[1]);
    st_idx_2 = std::sin(rtu_0[2]);
    out[0] = ct_idx_0 * ct_idx_1;
    out_tmp = st_idx_1 * st_idx_2;
    out[3] = out_tmp * ct_idx_0 - st_idx_0 * ct_idx_2;
    out_tmp_0 = st_idx_1 * ct_idx_2;
    out[6] = out_tmp_0 * ct_idx_0 + st_idx_0 * st_idx_2;
    out[1] = st_idx_0 * ct_idx_1;
    out[4] = out_tmp * st_idx_0 + ct_idx_0 * ct_idx_2;
    out[7] = out_tmp_0 * st_idx_0 - ct_idx_0 * st_idx_2;
    out[2] = -st_idx_1;
    out[5] = ct_idx_1 * st_idx_2;
    out[8] = ct_idx_1 * ct_idx_2;
    std::memcpy(&localDW->RotateATMissionHdg[0], &out[0], static_cast<uint32_T>
                (9U * sizeof(real_T)));
}

//
// Output and update for atomic system:
//    '<S109>/biasNED'
//    '<S57>/biasNED'
//
void FlightMissionMode_biasNED(const real_T rtu_MissionNED[3], const real_T
    rtu_IndivRotWP[30720], real_T rty_nedWayPoint[30720],
    DW_biasNED_FlightMissionMode_T *localDW)
{
    int32_T ibmat;
    int32_T itilerow;
    int32_T jcol;
    for (jcol = 0; jcol < 3; jcol++) {
        ibmat = static_cast<int32_T>(jcol * 10240);
        for (itilerow = 0; itilerow < 10240; itilerow++) {
            localDW->b[static_cast<int32_T>(ibmat + itilerow)] =
                rtu_MissionNED[jcol];
        }
    }

    for (jcol = 0; jcol < 10240; jcol++) {
        rty_nedWayPoint[jcol] = rtu_IndivRotWP[static_cast<int32_T>(jcol + 10240)]
            + localDW->b[jcol];
        rty_nedWayPoint[static_cast<int32_T>(jcol + 10240)] = localDW->b[
            static_cast<int32_T>(jcol + 10240)] + rtu_IndivRotWP[jcol];
        rty_nedWayPoint[static_cast<int32_T>(jcol + 20480)] = rtu_IndivRotWP[
            static_cast<int32_T>(jcol + 20480)] + localDW->b[static_cast<int32_T>
            (jcol + 20480)];
    }
}

static void FlightMissionMode_emxInit_real_T(emxArray_real_T_FlightMissionMode_T
    **pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_real_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_real_T_FlightMissionMode_T));
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

static void FlightMissionMode_emxEnsureCapacity_real_T
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

static void FlightMissionMode_WaypointFollowerBase_getDistinctWpts(const real_T
    waypoints[30720], emxArray_real_T_FlightMissionMode_T *distinctWpts,
    DW_WaypointFollower_FlightMissionMode_T *localDW)
{
    int32_T i1;
    int32_T i2;
    int32_T ix;
    int32_T j;
    boolean_T exitg1;
    for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < 10239; i2++) {
            j = static_cast<int32_T>(static_cast<int32_T>(10240 * i1) + i2);
            localDW->x[j] = (waypoints[static_cast<int32_T>(static_cast<int32_T>
                              (static_cast<int32_T>(i2 + 2) +
                               static_cast<int32_T>(10240 * i1)) - 1)] !=
                             waypoints[j]);
        }

        localDW->x[static_cast<int32_T>(static_cast<int32_T>(10240 * i1) + 10239)]
            = true;
    }

    i1 = 0;
    i2 = 20480;
    for (j = 0; j < 10240; j++) {
        localDW->b[j] = false;
        i1 = static_cast<int32_T>(i1 + 1);
        i2 = static_cast<int32_T>(i2 + 1);
        ix = i1;
        exitg1 = false;
        while ((!exitg1) && (ix <= i2)) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->x[static_cast<int32_T>(ix - 1)]) ^ 1))) {
                ix = static_cast<int32_T>(ix + 10240);
            } else {
                localDW->b[j] = true;
                exitg1 = true;
            }
        }
    }

    i1 = 0;
    for (i2 = 0; i2 < 10240; i2++) {
        if (localDW->b[i2]) {
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    j = i1;
    i1 = 0;
    for (i2 = 0; i2 < 10240; i2++) {
        if (localDW->b[i2]) {
            localDW->c_data[i1] = static_cast<int16_T>(static_cast<int32_T>(i2 +
                1));
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    i1 = static_cast<int32_T>(distinctWpts->size[0] * distinctWpts->size[1]);
    distinctWpts->size[0] = j;
    distinctWpts->size[1] = 3;
    FlightMissionMode_emxEnsureCapacity_real_T(distinctWpts, i1);
    for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 <= static_cast<int32_T>(j - 1); i2++) {
            distinctWpts->data[static_cast<int32_T>(i2 + static_cast<int32_T>
                (distinctWpts->size[0] * i1))] = waypoints[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(10240 * i1) +
                static_cast<int32_T>(localDW->c_data[i2])) - 1)];
        }
    }
}

static real_T FlightMissionMode_norm_pv(const real_T x[3])
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

static void FlightMissionMode_WaypointFollowerBase_createWaypoint
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, real_T
     virtualWaypoint[3])
{
    virtualWaypoint[0] = obj->InitialPose[0];
    virtualWaypoint[1] = obj->InitialPose[1];
    virtualWaypoint[2] = obj->InitialPose[2];
    obj->StartFlag = false;
}

static void FlightMissionMode_emxFree_real_T(emxArray_real_T_FlightMissionMode_T
    **pEmxArray)
{
    if (*pEmxArray != (emxArray_real_T_FlightMissionMode_T *)nullptr) {
        if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_real_T_FlightMissionMode_T *)nullptr;
    }
}

static void FlightMissionMode_WaypointFollowerBase_getWaypoints
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, const
     emxArray_real_T_FlightMissionMode_T *waypoints, real_T startWaypoint[3],
     real_T endWaypoint[3])
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
    startWaypoint[1] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>
        (static_cast<int32_T>(obj->WaypointIndex) + waypoints->size[0]) - 1)];
    endWaypoint[1] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex + 1.0) + waypoints->size[0]) - 1)];
    startWaypoint[2] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>
        (static_cast<int32_T>(obj->WaypointIndex) + static_cast<int32_T>
         (waypoints->size[0] << 1)) - 1)];
    endWaypoint[2] = waypoints->data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex + 1.0) + static_cast<int32_T>
        (waypoints->size[0] << 1)) - 1)];
}

static void FlightMissionMode_WaypointFollowerBase_endWaypointReached_b
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, const
     emxArray_real_T_FlightMissionMode_T *waypoints, real_T curStartWaypoint[3],
     real_T curEndWaypoint[3], const real_T currentPose[4])
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
    curEndWaypoint_1 = FlightMissionMode_norm_pv(tmp);
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
        tmp_0 = FlightMissionMode_norm_pv(curEndWaypoint_0);
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

        curStartWaypoint[0] = waypoints->data[static_cast<int32_T>
            (static_cast<int32_T>(obj->WaypointIndex) - 1)];
        curEndWaypoint[0] = waypoints->data[static_cast<int32_T>
            (static_cast<int32_T>(obj->WaypointIndex + 1.0) - 1)];
        curStartWaypoint[1] = waypoints->data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
              waypoints->size[0]) - 1)];
        curEndWaypoint[1] = waypoints->data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex + 1.0)
              + waypoints->size[0]) - 1)];
        curStartWaypoint[2] = waypoints->data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
              static_cast<int32_T>(waypoints->size[0] << 1)) - 1)];
        curEndWaypoint[2] = waypoints->data[static_cast<int32_T>(static_cast<
            int32_T>(static_cast<int32_T>(obj->WaypointIndex + 1.0) +
                     static_cast<int32_T>(waypoints->size[0] << 1)) - 1)];
    }
}

static real_T FlightMissionMode_WaypointFollowerBase_pointToLine(const real_T
    p1[3], const real_T p2[3], const real_T p[3])
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
        dist = FlightMissionMode_norm_pv(p_0);
    } else if (lambda > 1.0) {
        dist = FlightMissionMode_norm_pv(p_1);
    } else {
        dist = FlightMissionMode_norm_pv(p_2);
    }

    return dist;
}

static real_T FlightMissionMode_WaypointFollowerBase_projectToLine(const real_T
    startWaypoint[3], const real_T endWaypoint[3], const real_T currentPosition
    [3])
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
        (lambda_tmp_tmp_1 * lambda_tmp_tmp_1 + (lambda_tmp_tmp_0 *
          lambda_tmp_tmp_0 + lambda_tmp_tmp * lambda_tmp_tmp));
    currentPosition_0[0] = currentPosition[0] - (lambda * lambda_tmp_tmp +
        startWaypoint[0]);
    currentPosition_0[1] = currentPosition[1] - (lambda * lambda_tmp_tmp_0 +
        startWaypoint[1]);
    currentPosition_0[2] = currentPosition[2] - (lambda * lambda_tmp_tmp_1 +
        startWaypoint[2]);
    dist = FlightMissionMode_norm_pv(currentPosition_0);
    return dist;
}

static void FlightMissionMode_WaypointFollowerBase_getLookahead(const
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, const
    real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
    currentPosition[3], real_T lookaheadPoint[3])
{
    real_T a;
    real_T a_tmp_tmp;
    real_T a_tmp_tmp_0;
    real_T b;
    real_T b_tmp_idx_0_tmp;
    real_T b_tmp_idx_1_tmp;
    real_T b_tmp_idx_2_tmp;
    b = endWaypoint[0] - startWaypoint[0];
    b_tmp_idx_0_tmp = startWaypoint[0] - currentPosition[0];
    a_tmp_tmp = endWaypoint[1] - startWaypoint[1];
    b_tmp_idx_1_tmp = startWaypoint[1] - currentPosition[1];
    a_tmp_tmp_0 = endWaypoint[2] - startWaypoint[2];
    a = a_tmp_tmp_0 * a_tmp_tmp_0 + (a_tmp_tmp * a_tmp_tmp + b * b);
    b_tmp_idx_2_tmp = startWaypoint[2] - currentPosition[2];
    b = ((b * b_tmp_idx_0_tmp + a_tmp_tmp * b_tmp_idx_1_tmp) + a_tmp_tmp_0 *
         b_tmp_idx_2_tmp) * 2.0;
    b_tmp_idx_0_tmp = std::sqrt(b * b - (((b_tmp_idx_0_tmp * b_tmp_idx_0_tmp +
        b_tmp_idx_1_tmp * b_tmp_idx_1_tmp) + b_tmp_idx_2_tmp * b_tmp_idx_2_tmp)
        - obj->LookaheadDistance * obj->LookaheadDistance) * (4.0 * a));
    a = std::fmax((-b + b_tmp_idx_0_tmp) / 2.0 / a, (-b - b_tmp_idx_0_tmp) / 2.0
                  / a);
    lookaheadPoint[0] = (1.0 - a) * startWaypoint[0] + a * endWaypoint[0];
    lookaheadPoint[1] = (1.0 - a) * startWaypoint[1] + a * endWaypoint[1];
    lookaheadPoint[2] = (1.0 - a) * startWaypoint[2] + a * endWaypoint[2];
}

static void FlightMissionMode_WaypointFollowerBase_stepInternal
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T *obj, const
     real_T currentPose[4], const real_T waypointsIn[30720], real_T
     lookaheadDist, real_T lookaheadPoint[3], real_T *desiredHeading, real_T
     *desiredYaw, uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T
     *status, DW_WaypointFollower_FlightMissionMode_T *localDW)
{
    emxArray_real_T_FlightMissionMode_T *b_waypointsIn;
    emxArray_real_T_FlightMissionMode_T *waypoints;
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
        localDW->paddedWaypts[b_k] = (rtNaN);
    }

    for (b_k = 0; b_k < 3; b_k++) {
        for (loop_ub = 0; loop_ub < 10240; loop_ub++) {
            localDW->paddedWaypts[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(loop_ub + 1) + static_cast<int32_T>(10240 *
                b_k)) - 1)] = waypointsIn[static_cast<int32_T>
                (static_cast<int32_T>(10240 * b_k) + loop_ub)];
        }
    }

    p = false;
    p_0 = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 30720)) {
        if ((obj->WaypointsInternal[b_k] == localDW->paddedWaypts[b_k]) || (std::
                isnan(obj->WaypointsInternal[b_k]) && std::isnan
                (localDW->paddedWaypts[b_k]))) {
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
        std::memcpy(&obj->WaypointsInternal[0], &localDW->paddedWaypts[0],
                    static_cast<uint32_T>(30720U * sizeof(real_T)));
        obj->WaypointIndex = 1.0;
    }

    FlightMissionMode_emxInit_real_T(&b_waypointsIn, 2);
    FlightMissionMode_WaypointFollowerBase_getDistinctWpts(waypointsIn,
        b_waypointsIn, localDW);
    obj->NumWaypoints = static_cast<real_T>(b_waypointsIn->size[0]);
    obj->LookaheadDistance = lookaheadDist;
    FlightMissionMode_emxInit_real_T(&waypoints, 2);
    if (b_waypointsIn->size[0] == 0) {
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
            if (FlightMissionMode_norm_pv(virtualWaypoint) <
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
                FlightMissionMode_WaypointFollowerBase_createWaypoint(obj,
                    virtualWaypoint);
                for (b_k = 0; b_k < 3; b_k++) {
                    appendedWaypoints_data[static_cast<int32_T>(b_k << 1)] =
                        virtualWaypoint[b_k];
                    appendedWaypoints_data[static_cast<int32_T>(1 + static_cast<
                        int32_T>(b_k << 1))] = b_waypointsIn->data
                        [static_cast<int32_T>(b_waypointsIn->size[0] * b_k)];
                }

                obj->NumWaypoints = 2.0;
                b_k = static_cast<int32_T>(waypoints->size[0] * waypoints->size
                    [1]);
                waypoints->size[0] = 2;
                waypoints->size[1] = 3;
                FlightMissionMode_emxEnsureCapacity_real_T(waypoints, b_k);
                for (b_k = 0; b_k < 6; b_k++) {
                    waypoints->data[b_k] = appendedWaypoints_data[b_k];
                }

                guard1 = true;
            }
        } else {
            b_k = static_cast<int32_T>(waypoints->size[0] * waypoints->size[1]);
            waypoints->size[0] = b_waypointsIn->size[0];
            waypoints->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T(waypoints, b_k);
            loop_ub = static_cast<int32_T>(b_waypointsIn->size[0] * 3);
            for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
                waypoints->data[b_k] = b_waypointsIn->data[b_k];
            }

            guard1 = true;
        }

        if (guard1) {
            FlightMissionMode_WaypointFollowerBase_getWaypoints(obj, waypoints,
                virtualWaypoint, endWaypoint);
            FlightMissionMode_WaypointFollowerBase_endWaypointReached_b(obj,
                waypoints, virtualWaypoint, endWaypoint, currentPose);
            *crossTrackError =
                FlightMissionMode_WaypointFollowerBase_pointToLine
                (virtualWaypoint, endWaypoint, &currentPose[0]);
            if (obj->LastWaypointFlag) {
                *crossTrackError =
                    FlightMissionMode_WaypointFollowerBase_projectToLine
                    (virtualWaypoint, endWaypoint, &currentPose[0]);
            }

            absx_tmp = std::abs(*crossTrackError);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isinf(absx_tmp)) ^ 1))) &
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(std::isnan
                      (absx_tmp)) ^ 1)))))) {
                if (absx_tmp <= 2.2250738585072014E-308) {
                    r = 4.94065645841247E-324;
                    absx_tmp = 4.94065645841247E-324;
                } else {
                    frexp(absx_tmp, &b_exponent);
                    r = std::ldexp(1.0, static_cast<int32_T>(b_exponent - 53));
                    frexp(absx_tmp, &b_exponent_0);
                    absx_tmp = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0
                                           - 53));
                }
            } else {
                r = (rtNaN);
                absx_tmp = (rtNaN);
            }

            if (obj->LookaheadDistance <= std::fmax(std::sqrt(r), 5.0 * absx_tmp)
                + *crossTrackError) {
                obj->LookaheadDistance = obj->LookaheadFactor * *crossTrackError;
            }

            FlightMissionMode_WaypointFollowerBase_getLookahead(obj,
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

    FlightMissionMode_emxFree_real_T(&b_waypointsIn);
    FlightMissionMode_emxFree_real_T(&waypoints);
}

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//
void FlightMissionMode_WaypointFollower_Init
    (DW_WaypointFollower_FlightMissionMode_T *localDW)
{
    int32_T i;
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 30720; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }
}

//
// System reset for atomic system:
//    synthesized block
//    synthesized block
//
void FlightMissionMode_WaypointFollower_Reset
    (DW_WaypointFollower_FlightMissionMode_T *localDW)
{
    int32_T i;
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 30720; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//
void FlightMissionMode_WaypointFollower(const real_T rtu_0[4], const real_T
    rtu_1[30720], real_T rtu_2, DW_WaypointFollower_FlightMissionMode_T *localDW)
{
    real_T crossTrackError;
    real_T desiredYaw;
    uint8_T lookaheadFlag;
    FlightMissionMode_WaypointFollowerBase_stepInternal(&localDW->obj, rtu_0,
        rtu_1, rtu_2, localDW->WaypointFollower_o1,
        &localDW->WaypointFollower_o2, &desiredYaw, &lookaheadFlag,
        &crossTrackError, &localDW->WaypointFollower_o5, localDW);
}

static void FlightMissionMode_WaypointFollowerBase_getDistinctWpts_j(const
    real_T waypoints[300], real_T distinctWpts_data[], int32_T
    distinctWpts_size[2])
{
    int32_T i1;
    int32_T i2;
    int32_T ix;
    int32_T j;
    int8_T c_data[100];
    boolean_T x[300];
    boolean_T b[100];
    boolean_T exitg1;
    for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < 99; i2++) {
            j = static_cast<int32_T>(static_cast<int32_T>(100 * i1) + i2);
            x[j] = (waypoints[static_cast<int32_T>(static_cast<int32_T>(
                      static_cast<int32_T>(i2 + 2) + static_cast<int32_T>(100 *
                       i1)) - 1)] != waypoints[j]);
        }

        x[static_cast<int32_T>(static_cast<int32_T>(100 * i1) + 99)] = true;
    }

    i1 = 0;
    i2 = 200;
    for (j = 0; j < 100; j++) {
        b[j] = false;
        i1 = static_cast<int32_T>(i1 + 1);
        i2 = static_cast<int32_T>(i2 + 1);
        ix = i1;
        exitg1 = false;
        while ((!exitg1) && (ix <= i2)) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (x[static_cast<int32_T>(ix - 1)]) ^ 1))) {
                ix = static_cast<int32_T>(ix + 100);
            } else {
                b[j] = true;
                exitg1 = true;
            }
        }
    }

    i1 = 0;
    for (i2 = 0; i2 < 100; i2++) {
        if (b[i2]) {
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    j = i1;
    i1 = 0;
    for (i2 = 0; i2 < 100; i2++) {
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
                static_cast<int32_T>(100 * i1) + static_cast<int32_T>(c_data[i2]))
                - 1)];
        }
    }
}

static real_T FlightMissionMode_norm_pve(const real_T x[3])
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

static void FlightMissionMode_WaypointFollowerBase_createWaypoint_h
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj,
     real_T virtualWaypoint[3])
{
    virtualWaypoint[0] = obj->InitialPose[0];
    virtualWaypoint[1] = obj->InitialPose[1];
    virtualWaypoint[2] = obj->InitialPose[2];
    obj->StartFlag = false;
}

static void FlightMissionMode_WaypointFollowerBase_getWaypoints_m
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj,
     const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
     startWaypoint[3], real_T endWaypoint[3])
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

    startWaypoint[0] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>
        (obj->WaypointIndex) - 1)];
    endWaypoint[0] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>
        (obj->WaypointIndex + 1.0) - 1)];
    startWaypoint[1] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex) + waypoints_size[0]) - 1)];
    endWaypoint[1] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex + 1.0) + waypoints_size[0]) - 1)];
    startWaypoint[2] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex) + static_cast<int32_T>
        (waypoints_size[0] << 1)) - 1)];
    endWaypoint[2] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex + 1.0) + static_cast<int32_T>
        (waypoints_size[0] << 1)) - 1)];
}

static void FlightMissionMode_WaypointFollowerBase_endWaypointReached_b5d
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj,
     const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
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
    curEndWaypoint_1 = FlightMissionMode_norm_pve(tmp);
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
        tmp_0 = FlightMissionMode_norm_pve(curEndWaypoint_0);
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

static real_T FlightMissionMode_WaypointFollowerBase_pointToLine_k(const real_T
    p1[3], const real_T p2[3], const real_T p[3])
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
        dist = FlightMissionMode_norm_pve(p_0);
    } else if (lambda > 1.0) {
        dist = FlightMissionMode_norm_pve(p_1);
    } else {
        dist = FlightMissionMode_norm_pve(p_2);
    }

    return dist;
}

static real_T FlightMissionMode_WaypointFollowerBase_projectToLine_m(const
    real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
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
        (lambda_tmp_tmp_1 * lambda_tmp_tmp_1 + (lambda_tmp_tmp_0 *
          lambda_tmp_tmp_0 + lambda_tmp_tmp * lambda_tmp_tmp));
    currentPosition_0[0] = currentPosition[0] - (lambda * lambda_tmp_tmp +
        startWaypoint[0]);
    currentPosition_0[1] = currentPosition[1] - (lambda * lambda_tmp_tmp_0 +
        startWaypoint[1]);
    currentPosition_0[2] = currentPosition[2] - (lambda * lambda_tmp_tmp_1 +
        startWaypoint[2]);
    dist = FlightMissionMode_norm_pve(currentPosition_0);
    return dist;
}

static void FlightMissionMode_WaypointFollowerBase_getLookahead_d(const
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj, const
    real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
    currentPosition[3], real_T lookaheadPoint[3])
{
    real_T a;
    real_T a_tmp_tmp;
    real_T a_tmp_tmp_0;
    real_T b;
    real_T b_tmp_idx_0_tmp;
    real_T b_tmp_idx_1_tmp;
    real_T b_tmp_idx_2_tmp;
    b = endWaypoint[0] - startWaypoint[0];
    b_tmp_idx_0_tmp = startWaypoint[0] - currentPosition[0];
    a_tmp_tmp = endWaypoint[1] - startWaypoint[1];
    b_tmp_idx_1_tmp = startWaypoint[1] - currentPosition[1];
    a_tmp_tmp_0 = endWaypoint[2] - startWaypoint[2];
    a = a_tmp_tmp_0 * a_tmp_tmp_0 + (a_tmp_tmp * a_tmp_tmp + b * b);
    b_tmp_idx_2_tmp = startWaypoint[2] - currentPosition[2];
    b = ((b * b_tmp_idx_0_tmp + a_tmp_tmp * b_tmp_idx_1_tmp) + a_tmp_tmp_0 *
         b_tmp_idx_2_tmp) * 2.0;
    b_tmp_idx_0_tmp = std::sqrt(b * b - (((b_tmp_idx_0_tmp * b_tmp_idx_0_tmp +
        b_tmp_idx_1_tmp * b_tmp_idx_1_tmp) + b_tmp_idx_2_tmp * b_tmp_idx_2_tmp)
        - obj->LookaheadDistance * obj->LookaheadDistance) * (4.0 * a));
    a = std::fmax((-b + b_tmp_idx_0_tmp) / 2.0 / a, (-b - b_tmp_idx_0_tmp) / 2.0
                  / a);
    lookaheadPoint[0] = (1.0 - a) * startWaypoint[0] + a * endWaypoint[0];
    lookaheadPoint[1] = (1.0 - a) * startWaypoint[1] + a * endWaypoint[1];
    lookaheadPoint[2] = (1.0 - a) * startWaypoint[2] + a * endWaypoint[2];
}

static void FlightMissionMode_WaypointFollowerBase_stepInternal_f
    (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T *obj,
     const real_T currentPose[4], const real_T waypointsIn[300], real_T
     lookaheadDist, real_T lookaheadPoint[3], real_T *desiredHeading, real_T
     *desiredYaw, uint8_T *lookaheadDistFlag, real_T *crossTrackError, uint8_T
     *status)
{
    real_T b_waypointsIn_data[300];
    real_T waypoints_data[300];
    real_T appendedWaypoints_data[6];
    real_T endWaypoint[3];
    real_T virtualWaypoint[3];
    real_T absx_tmp;
    real_T r;
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
    if (lookaheadDist < 0.1) {
        lookaheadDist = 0.1;
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
    while ((!exitg1) && (b_k < 300)) {
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
                    static_cast<uint32_T>(300U * sizeof(real_T)));
        obj->WaypointIndex = 1.0;
    }

    FlightMissionMode_WaypointFollowerBase_getDistinctWpts_j(waypointsIn,
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
            if (FlightMissionMode_norm_pve(virtualWaypoint) <
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
                FlightMissionMode_WaypointFollowerBase_createWaypoint_h(obj,
                    virtualWaypoint);
                for (b_k = 0; b_k < 3; b_k++) {
                    appendedWaypoints_data[static_cast<int32_T>(b_k << 1)] =
                        virtualWaypoint[b_k];
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
            FlightMissionMode_WaypointFollowerBase_getWaypoints_m(obj,
                waypoints_data, waypoints_size, virtualWaypoint, endWaypoint);
            FlightMissionMode_WaypointFollowerBase_endWaypointReached_b5d(obj,
                waypoints_data, waypoints_size, virtualWaypoint, endWaypoint,
                currentPose);
            *crossTrackError =
                FlightMissionMode_WaypointFollowerBase_pointToLine_k
                (virtualWaypoint, endWaypoint, &currentPose[0]);
            if (obj->LastWaypointFlag) {
                *crossTrackError =
                    FlightMissionMode_WaypointFollowerBase_projectToLine_m
                    (virtualWaypoint, endWaypoint, &currentPose[0]);
            }

            absx_tmp = std::abs(*crossTrackError);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isinf(absx_tmp)) ^ 1))) &
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(std::isnan
                      (absx_tmp)) ^ 1)))))) {
                if (absx_tmp <= 2.2250738585072014E-308) {
                    r = 4.94065645841247E-324;
                    absx_tmp = 4.94065645841247E-324;
                } else {
                    frexp(absx_tmp, &b_exponent);
                    r = std::ldexp(1.0, static_cast<int32_T>(b_exponent - 53));
                    frexp(absx_tmp, &b_exponent_0);
                    absx_tmp = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0
                                           - 53));
                }
            } else {
                r = (rtNaN);
                absx_tmp = (rtNaN);
            }

            if (obj->LookaheadDistance <= std::fmax(std::sqrt(r), 5.0 * absx_tmp)
                + *crossTrackError) {
                obj->LookaheadDistance = obj->LookaheadFactor * *crossTrackError;
            }

            FlightMissionMode_WaypointFollowerBase_getLookahead_d(obj,
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
}

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void FlightMissionMode_WaypointFollower_c_Init
    (DW_WaypointFollower_FlightMissionMode_f_T *localDW)
{
    int32_T i;
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 300; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }
}

//
// System reset for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void FlightMissionMode_WaypointFollower_a_Reset
    (DW_WaypointFollower_FlightMissionMode_f_T *localDW)
{
    int32_T i;
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 300; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void FlightMissionMode_WaypointFollower_p(const real_T rtu_0[4], const real_T
    rtu_1[300], real_T rtu_2, DW_WaypointFollower_FlightMissionMode_f_T *localDW)
{
    real_T crossTrackError;
    FlightMissionMode_WaypointFollowerBase_stepInternal_f(&localDW->obj, rtu_0,
        rtu_1, rtu_2, localDW->WaypointFollower_o1,
        &localDW->WaypointFollower_o2, &localDW->WaypointFollower_o3,
        &localDW->WaypointFollower_o4, &crossTrackError,
        &localDW->WaypointFollower_o5);
}

//
// Output and update for atomic system:
//    '<S191>/minus'
//    '<S230>/minus'
//
void FlightMissionMode_minus(const real_T rtu_uP[300], const real_T rtu_uN[3],
    real_T rty_y[300])
{
    int32_T ibmat;
    int32_T itilerow;
    int32_T jcol;
    for (jcol = 0; jcol < 3; jcol++) {
        ibmat = static_cast<int32_T>(jcol * 100);
        for (itilerow = 0; itilerow < 100; itilerow++) {
            rty_y[static_cast<int32_T>(ibmat + itilerow)] = rtu_uN[jcol];
        }
    }

    for (jcol = 0; jcol < 300; jcol++) {
        rty_y[jcol] = rtu_uP[jcol] - rty_y[jcol];
    }
}

//
// Output and update for atomic system:
//    '<S191>/biasNED'
//    '<S230>/biasNED'
//
void FlightMissionMode_biasNED_c(const real_T rtu_MissionNED[3], const real_T
    rtu_IndivRotWP[300], real_T rty_nedWayPoint[300])
{
    real_T b[300];
    int32_T ibmat;
    int32_T itilerow;
    int32_T jcol;
    for (jcol = 0; jcol < 3; jcol++) {
        ibmat = static_cast<int32_T>(jcol * 100);
        for (itilerow = 0; itilerow < 100; itilerow++) {
            b[static_cast<int32_T>(ibmat + itilerow)] = rtu_MissionNED[jcol];
        }
    }

    for (jcol = 0; jcol < 100; jcol++) {
        rty_nedWayPoint[jcol] = rtu_IndivRotWP[static_cast<int32_T>(jcol + 100)]
            + b[jcol];
        rty_nedWayPoint[static_cast<int32_T>(jcol + 100)] = b
            [static_cast<int32_T>(jcol + 100)] + rtu_IndivRotWP[jcol];
        rty_nedWayPoint[static_cast<int32_T>(jcol + 200)] = rtu_IndivRotWP[
            static_cast<int32_T>(jcol + 200)] + b[static_cast<int32_T>(jcol +
            200)];
    }
}

static void FlightMissionMode_emxInit_real_T_l
    (emxArray_real_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_real_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_real_T_FlightMissionMode_T));
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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
    *FlightMissionMode_NameValueParser_NameValueParser
    (matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
     *obj)
{
    static const char_T c[7]{ 'o', 'p', 't', 'i', 'm', 'a', 'l' };

    cell_wrap_12_FlightMissionMode_T b;
    matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
        *b_obj;
    int32_T i;
    b_obj = obj;
    for (i = 0; i < 7; i++) {
        b.f1[i] = c[i];
    }

    obj->Defaults = b;
    return b_obj;
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_validatestring(const char_T str[7], char_T
    out_data[], int32_T out_size[2])
{
    static const char_T c[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp(const char_T a_data[], const int32_T
    a_size[2])
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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_merge(int32_T idx_data[], int32_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T
    xwork_data[])
{
    int32_T exitg1;
    int32_T iout;
    int32_T n;
    int32_T n_tmp;
    int32_T q;
    if (nq != 0) {
        n_tmp = static_cast<int32_T>(np + nq);
        for (q = 0; q <= static_cast<int32_T>(n_tmp - 1); q =
                static_cast<int32_T>(q + 1)) {
            iout = static_cast<int32_T>(offset + q);
            iwork_data[q] = idx_data[iout];
            xwork_data[q] = x_data[iout];
        }

        n = 0;
        q = np;
        iout = static_cast<int32_T>(offset - 1);
        do {
            exitg1 = 0;
            iout = static_cast<int32_T>(iout + 1);
            if (xwork_data[n] <= xwork_data[q]) {
                idx_data[iout] = iwork_data[n];
                x_data[iout] = xwork_data[n];
                if (static_cast<int32_T>(n + 1) < np) {
                    n = static_cast<int32_T>(n + 1);
                } else {
                    exitg1 = 1;
                }
            } else {
                idx_data[iout] = iwork_data[q];
                x_data[iout] = xwork_data[q];
                if (static_cast<int32_T>(q + 1) < n_tmp) {
                    q = static_cast<int32_T>(q + 1);
                } else {
                    q = static_cast<int32_T>(iout - n);
                    while (static_cast<int32_T>(n + 1) <= np) {
                        iout = static_cast<int32_T>(static_cast<int32_T>(q + n)
                            + 1);
                        idx_data[iout] = iwork_data[n];
                        x_data[iout] = xwork_data[n];
                        n = static_cast<int32_T>(n + 1);
                    }

                    exitg1 = 1;
                }
            }
        } while (exitg1 == 0);
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_sort(int32_T x_data[], const int32_T *x_size,
    int32_T idx_data[], int32_T *idx_size)
{
    int32_T b_idx_data[28];
    int32_T b_x_data[28];
    int32_T iwork_data[28];
    int32_T vwork_data[28];
    int32_T x4[4];
    int32_T b;
    int32_T b_idx_tmp;
    int32_T dim;
    int32_T i3;
    int32_T i4;
    int32_T nLeft;
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
    nQuartets = 0;
    while (nQuartets <= static_cast<int32_T>(dim - 2)) {
        vstride = static_cast<int32_T>(vstride * *x_size);
        nQuartets = 1;
    }

    for (dim = 0; dim <= static_cast<int32_T>(vstride - 1); dim =
            static_cast<int32_T>(dim + 1)) {
        for (nQuartets = 0; nQuartets <= b; nQuartets = static_cast<int32_T>
                (nQuartets + 1)) {
            vwork_data[nQuartets] = x_data[static_cast<int32_T>
                (static_cast<int32_T>(nQuartets * vstride) + dim)];
        }

        nQuartets = static_cast<int32_T>(static_cast<int8_T>(vwork_size_idx_0));
        for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>(nQuartets - 1);
                b_idx_tmp++) {
            b_idx_data[b_idx_tmp] = 0;
        }

        if (vwork_size_idx_0 != 0) {
            for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>
                    (vwork_size_idx_0 - 1); b_idx_tmp++) {
                b_x_data[b_idx_tmp] = vwork_data[b_idx_tmp];
            }

            nQuartets = static_cast<int32_T>(static_cast<int8_T>
                (vwork_size_idx_0));
            for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>(nQuartets - 1);
                 b_idx_tmp++) {
                b_idx_data[b_idx_tmp] = 0;
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
            for (nLeft = 0; nLeft <= static_cast<int32_T>(nQuartets_tmp - 1);
                    nLeft = static_cast<int32_T>(nLeft + 1)) {
                tailOffset = static_cast<int32_T>(nLeft << 2);
                idx4[0] = static_cast<int8_T>(static_cast<int32_T>(tailOffset +
                    1));
                idx4[1] = static_cast<int8_T>(static_cast<int32_T>(tailOffset +
                    2));
                idx4[2] = static_cast<int8_T>(static_cast<int32_T>(tailOffset +
                    3));
                idx4[3] = static_cast<int8_T>(static_cast<int32_T>(tailOffset +
                    4));
                x4[0] = b_x_data[tailOffset];
                x4[1] = b_x_data[static_cast<int32_T>(tailOffset + 1)];
                x4[2] = b_x_data[static_cast<int32_T>(tailOffset + 2)];
                x4[3] = b_x_data[static_cast<int32_T>(tailOffset + 3)];
                if (b_x_data[tailOffset] <= b_x_data[static_cast<int32_T>
                        (tailOffset + 1)]) {
                    nTail = 1;
                    nQuartets = 2;
                } else {
                    nTail = 2;
                    nQuartets = 1;
                }

                if (b_x_data[static_cast<int32_T>(tailOffset + 2)] <= b_x_data[
                        static_cast<int32_T>(tailOffset + 3)]) {
                    i3 = 3;
                    i4 = 4;
                } else {
                    i3 = 4;
                    i4 = 3;
                }

                b_idx_tmp = x4[static_cast<int32_T>(nTail - 1)];
                tmp = x4[static_cast<int32_T>(i3 - 1)];
                if (b_idx_tmp <= tmp) {
                    b_idx_tmp = x4[static_cast<int32_T>(nQuartets - 1)];
                    if (b_idx_tmp <= tmp) {
                        perm[0] = static_cast<int8_T>(nTail);
                        perm[1] = static_cast<int8_T>(nQuartets);
                        perm[2] = static_cast<int8_T>(i3);
                        perm[3] = static_cast<int8_T>(i4);
                    } else if (b_idx_tmp <= x4[static_cast<int32_T>(i4 - 1)]) {
                        perm[0] = static_cast<int8_T>(nTail);
                        perm[1] = static_cast<int8_T>(i3);
                        perm[2] = static_cast<int8_T>(nQuartets);
                        perm[3] = static_cast<int8_T>(i4);
                    } else {
                        perm[0] = static_cast<int8_T>(nTail);
                        perm[1] = static_cast<int8_T>(i3);
                        perm[2] = static_cast<int8_T>(i4);
                        perm[3] = static_cast<int8_T>(nQuartets);
                    }
                } else {
                    tmp = x4[static_cast<int32_T>(i4 - 1)];
                    if (b_idx_tmp <= tmp) {
                        if (x4[static_cast<int32_T>(nQuartets - 1)] <= tmp) {
                            perm[0] = static_cast<int8_T>(i3);
                            perm[1] = static_cast<int8_T>(nTail);
                            perm[2] = static_cast<int8_T>(nQuartets);
                            perm[3] = static_cast<int8_T>(i4);
                        } else {
                            perm[0] = static_cast<int8_T>(i3);
                            perm[1] = static_cast<int8_T>(nTail);
                            perm[2] = static_cast<int8_T>(i4);
                            perm[3] = static_cast<int8_T>(nQuartets);
                        }
                    } else {
                        perm[0] = static_cast<int8_T>(i3);
                        perm[1] = static_cast<int8_T>(i4);
                        perm[2] = static_cast<int8_T>(nTail);
                        perm[3] = static_cast<int8_T>(nQuartets);
                    }
                }

                b_idx_data[tailOffset] = static_cast<int32_T>(idx4
                    [static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)]);
                b_idx_data[static_cast<int32_T>(tailOffset + 1)] =
                    static_cast<int32_T>(idx4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[1]) - 1)]);
                b_idx_data[static_cast<int32_T>(tailOffset + 2)] =
                    static_cast<int32_T>(idx4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[2]) - 1)]);
                b_idx_data[static_cast<int32_T>(tailOffset + 3)] =
                    static_cast<int32_T>(idx4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[3]) - 1)]);
                b_x_data[tailOffset] = x4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[0]) - 1)];
                b_x_data[static_cast<int32_T>(tailOffset + 1)] = x4[static_cast<
                    int32_T>(static_cast<int32_T>(perm[1]) - 1)];
                b_x_data[static_cast<int32_T>(tailOffset + 2)] = x4[static_cast<
                    int32_T>(static_cast<int32_T>(perm[2]) - 1)];
                b_x_data[static_cast<int32_T>(tailOffset + 3)] = x4[static_cast<
                    int32_T>(static_cast<int32_T>(perm[3]) - 1)];
            }

            nQuartets = static_cast<int32_T>(nQuartets_tmp << 2);
            nLeft = static_cast<int32_T>(vwork_size_idx_0 - nQuartets);
            if (nLeft > 0) {
                for (tailOffset = 0; tailOffset <= static_cast<int32_T>(nLeft -
                        1); tailOffset = static_cast<int32_T>(tailOffset + 1)) {
                    b_idx_tmp = static_cast<int32_T>(nQuartets + tailOffset);
                    idx4[tailOffset] = static_cast<int8_T>(static_cast<int32_T>
                        (b_idx_tmp + 1));
                    x4[tailOffset] = b_x_data[b_idx_tmp];
                }

                perm[1] = 0;
                perm[2] = 0;
                perm[3] = 0;
                switch (nLeft) {
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

                for (tailOffset = 0; tailOffset <= static_cast<int32_T>(nLeft -
                        1); tailOffset = static_cast<int32_T>(tailOffset + 1)) {
                    b_idx_tmp = static_cast<int32_T>(static_cast<int32_T>
                        (perm[tailOffset]) - 1);
                    nTail = static_cast<int32_T>(nQuartets + tailOffset);
                    b_idx_data[nTail] = static_cast<int32_T>(idx4[b_idx_tmp]);
                    b_x_data[nTail] = x4[b_idx_tmp];
                }
            }

            if (vwork_size_idx_0 > 1) {
                for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>
                        (vwork_size_idx_0 - 1); b_idx_tmp++) {
                    vwork_data[b_idx_tmp] = 0;
                }

                nQuartets = static_cast<int32_T>(static_cast<int8_T>
                    (vwork_size_idx_0));
                for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>(nQuartets
                        - 1); b_idx_tmp++) {
                    iwork_data[b_idx_tmp] = 0;
                }

                nLeft = nQuartets_tmp;
                nQuartets = 4;
                while (nLeft > 1) {
                    if (static_cast<uint32_T>(static_cast<uint32_T>(nLeft) & 1U)
                        != 0U) {
                        nLeft = static_cast<int32_T>(nLeft - 1);
                        tailOffset = static_cast<int32_T>(nQuartets * nLeft);
                        nTail = static_cast<int32_T>(vwork_size_idx_0 -
                            tailOffset);
                        if (nTail > nQuartets) {
                            FlightMissionMode_merge(b_idx_data, b_x_data,
                                                    tailOffset, nQuartets,
                                                    static_cast<int32_T>(nTail -
                                nQuartets), iwork_data, vwork_data);
                        }
                    }

                    tailOffset = static_cast<int32_T>(nQuartets << 1);
                    nLeft = static_cast<int32_T>(nLeft >> 1);
                    for (nTail = 0; nTail <= static_cast<int32_T>(nLeft - 1);
                            nTail = static_cast<int32_T>(nTail + 1)) {
                        FlightMissionMode_merge(b_idx_data, b_x_data,
                                                static_cast<int32_T>(nTail *
                            tailOffset), nQuartets, nQuartets, iwork_data,
                                                vwork_data);
                    }

                    nQuartets = tailOffset;
                }

                if (vwork_size_idx_0 > nQuartets) {
                    FlightMissionMode_merge(b_idx_data, b_x_data, 0, nQuartets,
                                            static_cast<int32_T>
                                            (vwork_size_idx_0 - nQuartets),
                                            iwork_data, vwork_data);
                }
            }

            for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>
                    (vwork_size_idx_0 - 1); b_idx_tmp++) {
                vwork_data[b_idx_tmp] = b_x_data[b_idx_tmp];
            }
        }

        for (nQuartets = 0; nQuartets <= b; nQuartets = static_cast<int32_T>
                (nQuartets + 1)) {
            b_idx_tmp = static_cast<int32_T>(dim + static_cast<int32_T>
                (nQuartets * vstride));
            x_data[b_idx_tmp] = vwork_data[nQuartets];
            idx_data[b_idx_tmp] = b_idx_data[nQuartets];
        }
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_do_vectors(real_T c_data[], int32_T c_size[2],
    int32_T ia_data[], int32_T *ia_size, int32_T *ib_size)
{
    static const real_T a[28]{ 6.384265086E+9, 6.384265284E+9, 6.384480708E+9,
        6.384480906E+9, 6.384473283E+9, 6.384263997E+9, 2.1067690282E+11,
        2.10676902826E+11, 2.10677124976E+11, 2.10677124982E+11,
        2.10677124751E+11, 2.10676902787E+11, 2.10680747748E+11,
        2.10680754288E+11, 2.10687863274E+11, 2.10687869814E+11,
        2.10687618255E+11, 2.10680711811E+11, 6.384264226E+9, 6.384264232E+9,
        6.384264001E+9, 6.38447332E+9, 6.384473281E+9, 6.384473314E+9,
        6.384265282E+9, 6.384480904E+9, 6.38426509E+9, 6.384480712E+9 };

    static const int32_T aperm[28]{ 6, 21, 19, 20, 1, 27, 25, 2, 23, 5, 24, 22,
        3, 28, 26, 4, 12, 7, 8, 11, 9, 10, 18, 13, 14, 17, 15, 16 };

    static const int8_T e[28]{ 6, 21, 19, 20, 1, 27, 25, 2, 23, 5, 24, 22, 3, 28,
        26, 4, 12, 7, 8, 11, 9, 10, 18, 13, 14, 17, 15, 16 };

    emxArray_int32_T_28_FlightMissionMode_T ia_data_0;
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
    FlightMissionMode_sort(ia_data, ia_size, ia_data_0.data, &ia_data_0.size);
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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_do_vectors_g(const real_T b_data[], const int32_T *
    b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[], int32_T
    *ia_size, int32_T *ib_size)
{
    emxArray_int32_T_28_FlightMissionMode_T ia_data_0;
    real_T tmp[28];
    real_T ak;
    real_T b_absx;
    real_T bk;
    int32_T bperm_data[28];
    int32_T iwork_data[28];
    int32_T b_k;
    int32_T c_k;
    int32_T i;
    int32_T i2;
    int32_T i_0;
    int32_T j;
    int32_T k;
    int32_T kEnd;
    int32_T n;
    int32_T pEnd;
    int32_T q;
    int32_T qEnd;
    int32_T tmp_0;
    boolean_T exitg1;
    c_size[0] = 1;
    *ib_size = 0;
    i = static_cast<int32_T>(static_cast<int8_T>(*b_size));
    for (i_0 = 0; i_0 <= static_cast<int32_T>(i - 1); i_0++) {
        bperm_data[i_0] = 0;
    }

    if (*b_size != 0) {
        for (i = 1; i <= static_cast<int32_T>(static_cast<int32_T>(*b_size + 1)
                - 2); i = static_cast<int32_T>(i + 2)) {
            if (b_data[static_cast<int32_T>(i - 1)] <= b_data[i]) {
                bperm_data[static_cast<int32_T>(i - 1)] = i;
                bperm_data[i] = static_cast<int32_T>(i + 1);
            } else {
                bperm_data[static_cast<int32_T>(i - 1)] = static_cast<int32_T>(i
                    + 1);
                bperm_data[i] = i;
            }
        }

        if (static_cast<uint32_T>(static_cast<uint32_T>(*b_size) & 1U) != 0U) {
            bperm_data[static_cast<int32_T>(*b_size - 1)] = *b_size;
        }

        i = 2;
        while (i < static_cast<int32_T>(static_cast<int32_T>(*b_size + 1) - 1))
        {
            i2 = static_cast<int32_T>(i << 1);
            j = 1;
            pEnd = static_cast<int32_T>(i + 1);
            while (pEnd < static_cast<int32_T>(*b_size + 1)) {
                n = j;
                q = pEnd;
                qEnd = static_cast<int32_T>(j + i2);
                if (qEnd > static_cast<int32_T>(*b_size + 1)) {
                    qEnd = static_cast<int32_T>(*b_size + 1);
                }

                c_k = 0;
                kEnd = static_cast<int32_T>(qEnd - j);
                while (static_cast<int32_T>(c_k + 1) <= kEnd) {
                    i_0 = bperm_data[static_cast<int32_T>(q - 1)];
                    tmp_0 = bperm_data[static_cast<int32_T>(n - 1)];
                    if (b_data[static_cast<int32_T>(tmp_0 - 1)] <= b_data[
                            static_cast<int32_T>(i_0 - 1)]) {
                        iwork_data[c_k] = tmp_0;
                        n = static_cast<int32_T>(n + 1);
                        if (n == pEnd) {
                            while (q < qEnd) {
                                c_k = static_cast<int32_T>(c_k + 1);
                                iwork_data[c_k] = bperm_data[static_cast<int32_T>
                                    (q - 1)];
                                q = static_cast<int32_T>(q + 1);
                            }
                        }
                    } else {
                        iwork_data[c_k] = i_0;
                        q = static_cast<int32_T>(q + 1);
                        if (q == qEnd) {
                            while (n < pEnd) {
                                c_k = static_cast<int32_T>(c_k + 1);
                                iwork_data[c_k] = bperm_data[static_cast<int32_T>
                                    (n - 1)];
                                n = static_cast<int32_T>(n + 1);
                            }
                        }
                    }

                    c_k = static_cast<int32_T>(c_k + 1);
                }

                for (pEnd = 0; pEnd <= static_cast<int32_T>(kEnd - 1); pEnd =
                        static_cast<int32_T>(pEnd + 1)) {
                    bperm_data[static_cast<int32_T>(static_cast<int32_T>(j +
                        pEnd) - 1)] = iwork_data[pEnd];
                }

                j = qEnd;
                pEnd = static_cast<int32_T>(qEnd + i);
            }

            i = i2;
        }
    }

    n = 0;
    i = -1;
    i2 = 0;
    j = 1;
    qEnd = 1;
    while ((j <= 28) && (qEnd <= *b_size)) {
        kEnd = j;
        for (i_0 = 0; i_0 < 28; i_0++) {
            tmp[i_0] = static_cast<real_T>(i_0) + 1.0;
            iwork_data[i_0] = static_cast<int32_T>(i_0 + 1);
        }

        ak = skip_to_last_equal_value_ZlLNIyBv(&kEnd, tmp, iwork_data);
        j = kEnd;
        pEnd = qEnd;
        bk = b_data[static_cast<int32_T>(bperm_data[static_cast<int32_T>(qEnd -
            1)] - 1)];
        exitg1 = false;
        while ((!exitg1) && (pEnd < *b_size)) {
            b_absx = std::abs(bk / 2.0);
            if (b_absx <= 2.2250738585072014E-308) {
                b_absx = 4.94065645841247E-324;
            } else {
                frexp(b_absx, &b_k);
                b_absx = std::ldexp(1.0, static_cast<int32_T>(b_k - 53));
            }

            if (std::abs(bk - b_data[static_cast<int32_T>(bperm_data[pEnd] - 1)])
                < b_absx) {
                pEnd = static_cast<int32_T>(pEnd + 1);
            } else {
                exitg1 = true;
            }
        }

        qEnd = pEnd;
        b_absx = std::abs(bk / 2.0);
        if (b_absx <= 2.2250738585072014E-308) {
            b_absx = 4.94065645841247E-324;
        } else {
            frexp(b_absx, &k);
            b_absx = std::ldexp(1.0, static_cast<int32_T>(k - 53));
        }

        if (std::abs(bk - ak) < b_absx) {
            j = static_cast<int32_T>(kEnd + 1);
            i2 = kEnd;
            qEnd = static_cast<int32_T>(pEnd + 1);
        } else if (ak < bk) {
            n = static_cast<int32_T>(n + 1);
            i = static_cast<int32_T>(i + 1);
            ia_data[i] = static_cast<int32_T>(i2 + 1);
            j = static_cast<int32_T>(kEnd + 1);
            i2 = kEnd;
        } else {
            qEnd = static_cast<int32_T>(pEnd + 1);
        }
    }

    while (j <= 28) {
        b_k = j;
        for (i_0 = 0; i_0 < 28; i_0++) {
            tmp[i_0] = static_cast<real_T>(i_0) + 1.0;
            iwork_data[i_0] = static_cast<int32_T>(i_0 + 1);
        }

        skip_to_last_equal_value_ZlLNIyBv(&b_k, tmp, iwork_data);
        n = static_cast<int32_T>(n + 1);
        i = static_cast<int32_T>(i + 1);
        ia_data[i] = static_cast<int32_T>(i2 + 1);
        j = static_cast<int32_T>(b_k + 1);
        i2 = b_k;
    }

    if (1 > static_cast<int32_T>(i + 1)) {
        i2 = -1;
    } else {
        i2 = i;
    }

    *ia_size = static_cast<int32_T>(i2 + 1);
    FlightMissionMode_sort(ia_data, ia_size, ia_data_0.data, &ia_data_0.size);
    for (b_k = 0; b_k <= i; b_k = static_cast<int32_T>(b_k + 1)) {
        c_data[b_k] = static_cast<real_T>(static_cast<int32_T>(ia_data[b_k] - 1))
            + 1.0;
    }

    if (1 > n) {
        c_size[1] = 0;
    } else {
        c_size[1] = n;
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_merge_l(int32_T idx_data[], real_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
    xwork_data[])
{
    int32_T exitg1;
    int32_T iout;
    int32_T n;
    int32_T n_tmp;
    int32_T q;
    if (nq != 0) {
        n_tmp = static_cast<int32_T>(np + nq);
        for (q = 0; q <= static_cast<int32_T>(n_tmp - 1); q =
                static_cast<int32_T>(q + 1)) {
            iout = static_cast<int32_T>(offset + q);
            iwork_data[q] = idx_data[iout];
            xwork_data[q] = x_data[iout];
        }

        n = 0;
        q = np;
        iout = static_cast<int32_T>(offset - 1);
        do {
            exitg1 = 0;
            iout = static_cast<int32_T>(iout + 1);
            if (xwork_data[n] <= xwork_data[q]) {
                idx_data[iout] = iwork_data[n];
                x_data[iout] = xwork_data[n];
                if (static_cast<int32_T>(n + 1) < np) {
                    n = static_cast<int32_T>(n + 1);
                } else {
                    exitg1 = 1;
                }
            } else {
                idx_data[iout] = iwork_data[q];
                x_data[iout] = xwork_data[q];
                if (static_cast<int32_T>(q + 1) < n_tmp) {
                    q = static_cast<int32_T>(q + 1);
                } else {
                    q = static_cast<int32_T>(iout - n);
                    while (static_cast<int32_T>(n + 1) <= np) {
                        iout = static_cast<int32_T>(static_cast<int32_T>(q + n)
                            + 1);
                        idx_data[iout] = iwork_data[n];
                        x_data[iout] = xwork_data[n];
                        n = static_cast<int32_T>(n + 1);
                    }

                    exitg1 = 1;
                }
            }
        } while (exitg1 == 0);
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_sortIdx(real_T x_data[], int32_T *x_size, int32_T
    idx_data[], int32_T *idx_size)
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
    ib = static_cast<int32_T>(static_cast<int8_T>(*x_size));
    for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
        idx_data[n] = 0;
    }

    if (*x_size != 0) {
        b_x_size = *x_size;
        ib = *x_size;
        for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
            b_x_data[n] = x_data[n];
        }

        *idx_size = static_cast<int32_T>(static_cast<int8_T>(*x_size));
        ib = static_cast<int32_T>(static_cast<int8_T>(*x_size));
        for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
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
            idx4[static_cast<int32_T>(ib - 1)] = static_cast<int8_T>(
                static_cast<int32_T>(nPairs + 1));
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

                idx_data[static_cast<int32_T>(nPairs - 3)] = static_cast<int32_T>
                    (idx4[static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)]);
                idx_data[static_cast<int32_T>(nPairs - 2)] = static_cast<int32_T>
                    (idx4[static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)]);
                idx_data[static_cast<int32_T>(nPairs - 1)] = static_cast<int32_T>
                    (idx4[static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)]);
                idx_data[nPairs] = static_cast<int32_T>(idx4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[3]) - 1)]);
                b_x_data[static_cast<int32_T>(nPairs - 3)] = x4
                    [static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)];
                b_x_data[static_cast<int32_T>(nPairs - 2)] = x4
                    [static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)];
                b_x_data[static_cast<int32_T>(nPairs - 1)] = x4
                    [static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)];
                b_x_data[nPairs] = x4[static_cast<int32_T>(static_cast<int32_T>
                    (perm[3]) - 1)];
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
                nTail = static_cast<int32_T>(static_cast<int32_T>(perm[nPairs])
                    - 1);
                n = static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>(*x_size - 1) - ib)
                     + nPairs) + 1);
                idx_data[n] = static_cast<int32_T>(idx4[nTail]);
                b_x_data[n] = x4[nTail];
            }
        }

        if (*x_size > 1) {
            ib = *x_size;
            for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
                xwork_data[n] = 0.0;
            }

            ib = static_cast<int32_T>(static_cast<int8_T>(*x_size));
            for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
                iwork_data[n] = 0;
            }

            nPairs = static_cast<int32_T>(*x_size >> 2);
            n = 4;
            while (nPairs > 1) {
                if (static_cast<uint32_T>(static_cast<uint32_T>(nPairs) & 1U) !=
                    0U) {
                    nPairs = static_cast<int32_T>(nPairs - 1);
                    ib = static_cast<int32_T>(n * nPairs);
                    nTail = static_cast<int32_T>(*x_size - ib);
                    if (nTail > n) {
                        FlightMissionMode_merge_l(idx_data, b_x_data, ib, n,
                            static_cast<int32_T>(nTail - n), iwork_data,
                            xwork_data);
                    }
                }

                ib = static_cast<int32_T>(n << 1);
                nPairs = static_cast<int32_T>(nPairs >> 1);
                for (nTail = 0; nTail <= static_cast<int32_T>(nPairs - 1); nTail
                     = static_cast<int32_T>(nTail + 1)) {
                    FlightMissionMode_merge_l(idx_data, b_x_data,
                        static_cast<int32_T>(nTail * ib), n, n, iwork_data,
                        xwork_data);
                }

                n = ib;
            }

            if (*x_size > n) {
                FlightMissionMode_merge_l(idx_data, b_x_data, 0, n,
                    static_cast<int32_T>(*x_size - n), iwork_data, xwork_data);
            }
        }

        for (n = 0; n <= static_cast<int32_T>(b_x_size - 1); n++) {
            x_data[n] = b_x_data[n];
        }
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_sort_b(real_T x_data[], const int32_T *x_size)
{
    emxArray_int32_T_28_FlightMissionMode_T vwork_data_0;
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
            vwork_data[c_k] = x_data[static_cast<int32_T>(static_cast<int32_T>
                (c_k * vstride) + dim)];
        }

        FlightMissionMode_sortIdx(vwork_data, &vwork_size, vwork_data_0.data,
            &vwork_data_0.size);
        for (c_k = 0; c_k <= b; c_k = static_cast<int32_T>(c_k + 1)) {
            x_data[static_cast<int32_T>(dim + static_cast<int32_T>(c_k * vstride))]
                = vwork_data[c_k];
        }
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_uavDubinsConnection_findDisabledIndices(real_T
    idx_data[], int32_T *idx_size)
{
    real_T c_data[28];
    real_T ia_data_0[28];
    int32_T ia_data[28];
    int32_T c_size[2];
    int32_T ia_size;
    int32_T ia_size_0;
    int32_T ib_size;
    FlightMissionMode_do_vectors(c_data, c_size, ia_data, &ia_size, &ib_size);
    ia_size_0 = ia_size;
    for (ib_size = 0; ib_size <= static_cast<int32_T>(ia_size - 1); ib_size++) {
        ia_data_0[ib_size] = static_cast<real_T>(ia_data[ib_size]);
    }

    FlightMissionMode_do_vectors_g(ia_data_0, &ia_size_0, c_data, c_size,
        ia_data, &ia_size, &ib_size);
    *idx_size = ia_size;
    for (ib_size = 0; ib_size <= static_cast<int32_T>(ia_size - 1); ib_size++) {
        idx_data[ib_size] = static_cast<real_T>(ia_data[ib_size]);
    }

    FlightMissionMode_sort_b(idx_data, idx_size);
    for (ib_size = 0; ib_size <= static_cast<int32_T>(*idx_size - 1); ib_size++)
    {
        idx_data[ib_size]--;
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void* FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable(real_T
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
        &b_disabledPathTypes_data[0], static_cast<uint32_T>
        (*disabledPathTypes_size));
}

static void FlightMissionMode_emxEnsureCapacity_real_T_p
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

static void FlightMissionMode_emxFree_real_T_j
    (emxArray_real_T_FlightMissionMode_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_real_T_FlightMissionMode_T *)nullptr) {
        if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_real_T_FlightMissionMode_T *)nullptr;
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k(const char_T a_data[], const int32_T
    a_size[2])
{
    static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

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
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(a_data[kstr]))
                                           & 127)] != b[static_cast<int32_T>
                        (c[kstr])]) {
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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_ka(const char_T a_data[], const
    int32_T a_size[2])
{
    static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

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
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(a_data[kstr]))
                                           & 127)] != b[static_cast<int32_T>
                        (c[kstr])]) {
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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_i(const
    real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
    varargin_4, real_T varargin_5, real_T varargin_6, const
    cell_wrap_10_FlightMissionMode_T varargin_7[4], const real_T varargin_8[4],
    uavDubinsPathSegment_FlightMissionMode_T *b_this)
{
    static const char_T d[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
        'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
        'Z', '[', '\\', ']', '^', '_', '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z', '{', '|', '}', '~', '\x7f' };

    real_T thetaWrap;
    int32_T k;
    b_this->MinTurningRadius = varargin_5;
    b_this->StartPose[0] = varargin_1[0];
    b_this->StartPose[1] = varargin_1[1];
    b_this->StartPose[2] = varargin_1[2];
    thetaWrap = mod_dBqh4Vat(varargin_1[3]);
    b_this->StartPose[3] = thetaWrap;
    if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
            (varargin_1[3] > 0.0)))) {
        b_this->StartPose[3] = 6.2831853071795862;
    }

    wrapToPi_iEuDNbvh(&b_this->StartPose[3]);
    b_this->GoalPose[0] = varargin_2[0];
    b_this->GoalPose[1] = varargin_2[1];
    b_this->GoalPose[2] = varargin_2[2];
    thetaWrap = mod_dBqh4Vat(varargin_2[3]);
    b_this->GoalPose[3] = thetaWrap;
    if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
            (varargin_2[3] > 0.0)))) {
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
    b_this->MotionTypes[1].f1.data[0] = d[static_cast<int32_T>
        (static_cast<int32_T>(static_cast<uint8_T>(varargin_7[1].f1.data[0])) &
         127)];
    b_this->MotionTypes[2].f1.size[0] = 1;
    b_this->MotionTypes[2].f1.size[1] = 1;
    b_this->MotionTypes[2].f1.data[0] = d[static_cast<int32_T>
        (static_cast<int32_T>(static_cast<uint8_T>(varargin_7[2].f1.data[0])) &
         127)];
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = varargin_7[3].f1.size[1];
    for (k = 0; k <= static_cast<int32_T>(varargin_7[3].f1.size[1] - 1); k =
            static_cast<int32_T>(k + 1)) {
        b_this->MotionTypes[3].f1.data[k] = d[static_cast<int32_T>
            (static_cast<uint8_T>(varargin_7[3].f1.data[k]))];
    }

    if (FlightMissionMode_strcmp_k(b_this->MotionTypes[0].f1.data,
            b_this->MotionTypes[0].f1.size)) {
        b_this->MotionTypes[0].f1.size[0] = 1;
        b_this->MotionTypes[0].f1.size[1] = 2;
        b_this->MotionTypes[0].f1.data[0] = 'H';
        b_this->MotionTypes[0].f1.data[1] = 'l';
    } else if (FlightMissionMode_strcmp_ka(b_this->MotionTypes[0].f1.data,
                b_this->MotionTypes[0].f1.size)) {
        b_this->MotionTypes[0].f1.size[0] = 1;
        b_this->MotionTypes[0].f1.size[1] = 2;
        b_this->MotionTypes[0].f1.data[0] = 'H';
        b_this->MotionTypes[0].f1.data[1] = 'r';
    } else if (FlightMissionMode_strcmp_ka(b_this->MotionTypes[3].f1.data,
                b_this->MotionTypes[3].f1.size)) {
        b_this->MotionTypes[3].f1.size[0] = 1;
        b_this->MotionTypes[3].f1.size[1] = 2;
        b_this->MotionTypes[3].f1.data[0] = 'H';
        b_this->MotionTypes[3].f1.data[1] = 'r';
    } else if (FlightMissionMode_strcmp_k(b_this->MotionTypes[3].f1.data,
                b_this->MotionTypes[3].f1.size)) {
        b_this->MotionTypes[3].f1.size[0] = 1;
        b_this->MotionTypes[3].f1.size[1] = 2;
        b_this->MotionTypes[3].f1.data[0] = 'H';
        b_this->MotionTypes[3].f1.data[1] = 'l';
    }

    b_this->Length = ((varargin_8[0] + varargin_8[1]) + varargin_8[2]) +
        varargin_8[3];
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static real_T FlightMissionMode_sum(const real_T x_data[])
{
    return ((x_data[0] + x_data[1]) + x_data[2]) + x_data[3];
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_uavDubinsBuiltins_connect(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPose[4],
    const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
    real_T dpt_data[], const int32_T *dpt_size,
    uavDubinsPathSegment_FlightMissionMode_T pathSegObjs_data[], int32_T
    *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
    DW_WayPointGenerator_FlightMissionMode_T *localDW)
{
    void* buildableObj_UAVDubinsBuildableObj;
    cell_wrap_10_FlightMissionMode_T m[4];
    cell_wrap_10_FlightMissionMode_T ac;
    cell_wrap_10_FlightMissionMode_T ad;
    cell_wrap_10_FlightMissionMode_T ae;
    cell_wrap_10_FlightMissionMode_T af;
    cell_wrap_10_FlightMissionMode_T bc;
    cell_wrap_10_FlightMissionMode_T bd;
    cell_wrap_10_FlightMissionMode_T be;
    cell_wrap_10_FlightMissionMode_T bf;
    cell_wrap_10_FlightMissionMode_T cc;
    cell_wrap_10_FlightMissionMode_T cd;
    cell_wrap_10_FlightMissionMode_T ce;
    cell_wrap_10_FlightMissionMode_T cf;
    cell_wrap_10_FlightMissionMode_T dc;
    cell_wrap_10_FlightMissionMode_T dd;
    cell_wrap_10_FlightMissionMode_T de;
    cell_wrap_10_FlightMissionMode_T df;
    cell_wrap_10_FlightMissionMode_T ec;
    cell_wrap_10_FlightMissionMode_T ed;
    cell_wrap_10_FlightMissionMode_T ee;
    cell_wrap_10_FlightMissionMode_T ef;
    cell_wrap_10_FlightMissionMode_T fc;
    cell_wrap_10_FlightMissionMode_T fd;
    cell_wrap_10_FlightMissionMode_T fe;
    cell_wrap_10_FlightMissionMode_T ff;
    cell_wrap_10_FlightMissionMode_T gc;
    cell_wrap_10_FlightMissionMode_T gd;
    cell_wrap_10_FlightMissionMode_T ge;
    cell_wrap_10_FlightMissionMode_T gf;
    cell_wrap_10_FlightMissionMode_T hc;
    cell_wrap_10_FlightMissionMode_T hd;
    cell_wrap_10_FlightMissionMode_T he;
    cell_wrap_10_FlightMissionMode_T hf;
    cell_wrap_10_FlightMissionMode_T ic;
    cell_wrap_10_FlightMissionMode_T id;
    cell_wrap_10_FlightMissionMode_T ie;
    cell_wrap_10_FlightMissionMode_T jc;
    cell_wrap_10_FlightMissionMode_T jd;
    cell_wrap_10_FlightMissionMode_T je;
    cell_wrap_10_FlightMissionMode_T jf;
    cell_wrap_10_FlightMissionMode_T kb;
    cell_wrap_10_FlightMissionMode_T kc;
    cell_wrap_10_FlightMissionMode_T kd;
    cell_wrap_10_FlightMissionMode_T ke;
    cell_wrap_10_FlightMissionMode_T kf;
    cell_wrap_10_FlightMissionMode_T lb;
    cell_wrap_10_FlightMissionMode_T lc;
    cell_wrap_10_FlightMissionMode_T ld;
    cell_wrap_10_FlightMissionMode_T le;
    cell_wrap_10_FlightMissionMode_T lf;
    cell_wrap_10_FlightMissionMode_T mb;
    cell_wrap_10_FlightMissionMode_T mc;
    cell_wrap_10_FlightMissionMode_T md;
    cell_wrap_10_FlightMissionMode_T me;
    cell_wrap_10_FlightMissionMode_T mf;
    cell_wrap_10_FlightMissionMode_T nb;
    cell_wrap_10_FlightMissionMode_T nc;
    cell_wrap_10_FlightMissionMode_T nd;
    cell_wrap_10_FlightMissionMode_T ne;
    cell_wrap_10_FlightMissionMode_T nf;
    cell_wrap_10_FlightMissionMode_T ob;
    cell_wrap_10_FlightMissionMode_T oc;
    cell_wrap_10_FlightMissionMode_T od;
    cell_wrap_10_FlightMissionMode_T oe;
    cell_wrap_10_FlightMissionMode_T of;
    cell_wrap_10_FlightMissionMode_T pb;
    cell_wrap_10_FlightMissionMode_T pc;
    cell_wrap_10_FlightMissionMode_T pd;
    cell_wrap_10_FlightMissionMode_T pe;
    cell_wrap_10_FlightMissionMode_T pf;
    cell_wrap_10_FlightMissionMode_T qb;
    cell_wrap_10_FlightMissionMode_T qc;
    cell_wrap_10_FlightMissionMode_T qd;
    cell_wrap_10_FlightMissionMode_T qe;
    cell_wrap_10_FlightMissionMode_T qf;
    cell_wrap_10_FlightMissionMode_T rb;
    cell_wrap_10_FlightMissionMode_T rc;
    cell_wrap_10_FlightMissionMode_T rd;
    cell_wrap_10_FlightMissionMode_T re;
    cell_wrap_10_FlightMissionMode_T rf;
    cell_wrap_10_FlightMissionMode_T sb;
    cell_wrap_10_FlightMissionMode_T sc;
    cell_wrap_10_FlightMissionMode_T sd;
    cell_wrap_10_FlightMissionMode_T se;
    cell_wrap_10_FlightMissionMode_T sf;
    cell_wrap_10_FlightMissionMode_T tb;
    cell_wrap_10_FlightMissionMode_T tc;
    cell_wrap_10_FlightMissionMode_T td;
    cell_wrap_10_FlightMissionMode_T te;
    cell_wrap_10_FlightMissionMode_T tf;
    cell_wrap_10_FlightMissionMode_T ub;
    cell_wrap_10_FlightMissionMode_T uc;
    cell_wrap_10_FlightMissionMode_T ud;
    cell_wrap_10_FlightMissionMode_T ue;
    cell_wrap_10_FlightMissionMode_T uf;
    cell_wrap_10_FlightMissionMode_T vb;
    cell_wrap_10_FlightMissionMode_T vc;
    cell_wrap_10_FlightMissionMode_T vd;
    cell_wrap_10_FlightMissionMode_T ve;
    cell_wrap_10_FlightMissionMode_T vf;
    cell_wrap_10_FlightMissionMode_T wb;
    cell_wrap_10_FlightMissionMode_T wc;
    cell_wrap_10_FlightMissionMode_T wd;
    cell_wrap_10_FlightMissionMode_T we;
    cell_wrap_10_FlightMissionMode_T wf;
    cell_wrap_10_FlightMissionMode_T xb;
    cell_wrap_10_FlightMissionMode_T xc;
    cell_wrap_10_FlightMissionMode_T xd;
    cell_wrap_10_FlightMissionMode_T xe;
    cell_wrap_10_FlightMissionMode_T yb;
    cell_wrap_10_FlightMissionMode_T yc;
    cell_wrap_10_FlightMissionMode_T yd;
    cell_wrap_10_FlightMissionMode_T ye;
    emxArray_real_T_FlightMissionMode_T *g;
    emxArray_real_T_FlightMissionMode_T *g1;
    emxArray_real_T_FlightMissionMode_T *g_0;
    emxArray_real_T_FlightMissionMode_T *ml;
    emxArray_real_T_FlightMissionMode_T *ml1;
    emxArray_real_T_FlightMissionMode_T *s;
    emxArray_real_T_FlightMissionMode_T *s1;
    real_T b_goalPose[4];
    real_T b_startPose[4];
    real_T ml1_0[4];
    real_T ml1_data[4];
    real_T l;
    real_T ml1_tmp;
    int32_T b_nRows;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
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
        FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable(obj->AirSpeed,
        obj->MaxRollAngle, obj->FlightPathAngleLimit, dpt_data, dpt_size);
    b_startPose[0] = startPose[0];
    b_goalPose[0] = goalPose[0];
    b_startPose[1] = startPose[1];
    b_goalPose[1] = goalPose[1];
    b_startPose[2] = startPose[2];
    b_goalPose[2] = goalPose[2];
    b_startPose[3] = startPose[3];
    b_goalPose[3] = goalPose[3];
    b_nRows = 1;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (flagOptimal) ^ 1))) {
        b_nRows = 28;
    }

    FlightMissionMode_emxInit_real_T_l(&s, 2);
    FlightMissionMode_emxInit_real_T_l(&g, 2);
    FlightMissionMode_emxInit_real_T_l(&ml, 2);
    xf_tmp = static_cast<int32_T>(b_nRows << 2);
    loop_ub_tmp = static_cast<int32_T>(s->size[0] * s->size[1]);
    s->size[0] = xf_tmp;
    s->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_p(s, loop_ub_tmp);
    loop_ub_tmp = static_cast<int32_T>(g->size[0] * g->size[1]);
    g->size[0] = xf_tmp;
    g->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_p(g, loop_ub_tmp);
    mt_size_idx_0 = b_nRows;
    loop_ub_tmp = static_cast<int32_T>(ml->size[0] * ml->size[1]);
    ml->size[0] = xf_tmp;
    ml->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_p(ml, loop_ub_tmp);
    uavDubinsDistanceCodegen_real64(buildableObj_UAVDubinsBuildableObj,
        &b_startPose[0], 1U, &b_goalPose[0], 1U, flagOptimal, turningRadius,
        &s->data[0], &g->data[0], &localDW->b_fpa_data[0], &localDW->b_a_data[0],
        &localDW->mtr_data[0], &localDW->h_data[0], &localDW->mt_data[0],
        &ml->data[0]);
    b_nRows = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (flagOptimal) ^ 1))) {
        b_nRows = 27;
    }

    FlightMissionMode_emxInit_real_T_l(&g1, 2);
    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(s->size[0] * s->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g1->size[0] * g1->size[1]);
    g1->size[0] = static_cast<int32_T>(num_idx_1);
    g1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_p(g1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g1->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g1->size[0] * xf_tmp))] = s->data[static_cast<int32_T>(xf_tmp +
                static_cast<int32_T>(static_cast<int32_T>(tmp[0]) * loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_j(&s);
    FlightMissionMode_emxInit_real_T_l(&s1, 2);
    loop_ub_tmp = static_cast<int32_T>(s1->size[0] * s1->size[1]);
    s1->size[0] = static_cast<int32_T>(num_idx_1);
    s1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_p(s1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
        s1->data[xf_tmp] = g1->data[xf_tmp];
    }

    FlightMissionMode_emxInit_real_T_l(&g_0, 2);
    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(g->size[0] * g->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
    g_0->size[0] = static_cast<int32_T>(num_idx_1);
    g_0->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_p(g_0, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g_0->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g_0->size[0] * xf_tmp))] = g->data[static_cast<int32_T>(xf_tmp
                + static_cast<int32_T>(static_cast<int32_T>(tmp[0]) *
                loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_j(&g);
    loop_ub_tmp = static_cast<int32_T>(g1->size[0] * g1->size[1]);
    g1->size[0] = static_cast<int32_T>(num_idx_1);
    g1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_p(g1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
        g1->data[xf_tmp] = g_0->data[xf_tmp];
    }

    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(ml->size[0] * ml->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
    g_0->size[0] = static_cast<int32_T>(num_idx_1);
    g_0->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_p(g_0, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g_0->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g_0->size[0] * xf_tmp))] = ml->data[static_cast<int32_T>(xf_tmp
                + static_cast<int32_T>(static_cast<int32_T>(tmp[0]) *
                loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_j(&ml);
    FlightMissionMode_emxInit_real_T_l(&ml1, 2);
    loop_ub_tmp = static_cast<int32_T>(ml1->size[0] * ml1->size[1]);
    ml1->size[0] = static_cast<int32_T>(num_idx_1);
    ml1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_p(ml1, loop_ub_tmp);
    loop_ub_tmp = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub_tmp - 1); xf_tmp++)
    {
        ml1->data[xf_tmp] = g_0->data[xf_tmp];
    }

    FlightMissionMode_emxFree_real_T_j(&g_0);
    loop_ub_tmp = static_cast<int32_T>(mt_size_idx_0 * mt_size_idx_0);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub_tmp - 1); xf_tmp++)
    {
        localDW->mt_data[xf_tmp]++;
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
        *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>(
            static_cast<int32_T>(b_nRows + 1)));
        for (loop_ub_tmp = 0; loop_ub_tmp <= b_nRows; loop_ub_tmp = static_cast<
                int32_T>(loop_ub_tmp + 1)) {
            l++;
            ml1_tmp = localDW->mt_data[static_cast<int32_T>(static_cast<int32_T>
                (l) - 1)];
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

            b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>
                (l) - 1)];
            b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l)
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
            ml1_0[0] = ml1_tmp;
            ml1_data[0] = ml1_tmp;
            b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + s1->size[0]) - 1)];
            b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + g1->size[0]) - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + ml1->size[0]) - 1)];
            ml1_0[1] = ml1_tmp;
            ml1_data[1] = ml1_tmp;
            b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1))
                - 1)];
            b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1))
                - 1)];
            ml1_0[2] = ml1_tmp;
            ml1_data[2] = ml1_tmp;
            b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3))
                - 1)];
            b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3))
                - 1)];
            ml1_0[3] = ml1_tmp;
            ml1_data[3] = ml1_tmp;
            FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_i
                (b_startPose, b_goalPose, localDW->b_fpa_data
                 [static_cast<int32_T>(static_cast<int32_T>(l) - 1)],
                 localDW->b_a_data[0], localDW->mtr_data[0], localDW->h_data[
                 static_cast<int32_T>(static_cast<int32_T>(l) - 1)], m, ml1_0,
                 &pathSegObjs_data[loop_ub_tmp]);
            pathCosts_data[loop_ub_tmp] = FlightMissionMode_sum(ml1_data);
        }
    } else {
        *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>(
            static_cast<int32_T>(b_nRows + 1)));
        for (loop_ub_tmp = 1; static_cast<int32_T>(loop_ub_tmp - 1) <= b_nRows;
                loop_ub_tmp = static_cast<int32_T>(loop_ub_tmp + 1)) {
            l++;
            if (1 == loop_ub_tmp) {
                m[0] = kb;
                m[1] = lb;
                m[2] = mb;
                m[3] = nb;
            }

            if (2 == loop_ub_tmp) {
                m[0] = ob;
                m[1] = pb;
                m[2] = qb;
                m[3] = rb;
            }

            if (3 == loop_ub_tmp) {
                m[0] = sb;
                m[1] = tb;
                m[2] = ub;
                m[3] = vb;
            }

            if (4 == loop_ub_tmp) {
                m[0] = wb;
                m[1] = xb;
                m[2] = yb;
                m[3] = ac;
            }

            if (5 == loop_ub_tmp) {
                m[0] = bc;
                m[1] = cc;
                m[2] = dc;
                m[3] = ec;
            }

            if (6 == loop_ub_tmp) {
                m[0] = fc;
                m[1] = gc;
                m[2] = hc;
                m[3] = ic;
            }

            if (7 == loop_ub_tmp) {
                m[0] = jc;
                m[1] = kc;
                m[2] = lc;
                m[3] = mc;
            }

            if (8 == loop_ub_tmp) {
                m[0] = nc;
                m[1] = oc;
                m[2] = pc;
                m[3] = qc;
            }

            if (9 == loop_ub_tmp) {
                m[0] = rc;
                m[1] = sc;
                m[2] = tc;
                m[3] = uc;
            }

            if (10 == loop_ub_tmp) {
                m[0] = vc;
                m[1] = wc;
                m[2] = xc;
                m[3] = yc;
            }

            if (11 == loop_ub_tmp) {
                m[0] = ad;
                m[1] = bd;
                m[2] = cd;
                m[3] = dd;
            }

            if (12 == loop_ub_tmp) {
                m[0] = ed;
                m[1] = fd;
                m[2] = gd;
                m[3] = hd;
            }

            if (13 == loop_ub_tmp) {
                m[0] = id;
                m[1] = jd;
                m[2] = kd;
                m[3] = ld;
            }

            if (14 == loop_ub_tmp) {
                m[0] = md;
                m[1] = nd;
                m[2] = od;
                m[3] = pd;
            }

            if (15 == loop_ub_tmp) {
                m[0] = qd;
                m[1] = rd;
                m[2] = sd;
                m[3] = td;
            }

            if (16 == loop_ub_tmp) {
                m[0] = ud;
                m[1] = vd;
                m[2] = wd;
                m[3] = xd;
            }

            if (17 == loop_ub_tmp) {
                m[0] = yd;
                m[1] = ae;
                m[2] = be;
                m[3] = ce;
            }

            if (18 == loop_ub_tmp) {
                m[0] = de;
                m[1] = ee;
                m[2] = fe;
                m[3] = ge;
            }

            if (19 == loop_ub_tmp) {
                m[0] = he;
                m[1] = ie;
                m[2] = je;
                m[3] = ke;
            }

            if (20 == loop_ub_tmp) {
                m[0] = le;
                m[1] = me;
                m[2] = ne;
                m[3] = oe;
            }

            if (21 == loop_ub_tmp) {
                m[0] = pe;
                m[1] = qe;
                m[2] = re;
                m[3] = se;
            }

            if (22 == loop_ub_tmp) {
                m[0] = te;
                m[1] = ue;
                m[2] = ve;
                m[3] = we;
            }

            if (23 == loop_ub_tmp) {
                m[0] = xe;
                m[1] = ye;
                m[2] = af;
                m[3] = bf;
            }

            if (24 == loop_ub_tmp) {
                m[0] = cf;
                m[1] = df;
                m[2] = ef;
                m[3] = ff;
            }

            if (25 == loop_ub_tmp) {
                m[0] = gf;
                m[1] = hf;
                m[2] = jf;
                m[3] = kf;
            }

            if (26 == loop_ub_tmp) {
                m[0] = lf;
                m[1] = mf;
                m[2] = nf;
                m[3] = of;
            }

            if (27 == loop_ub_tmp) {
                m[0] = pf;
                m[1] = qf;
                m[2] = rf;
                m[3] = sf;
            }

            if (28 == loop_ub_tmp) {
                m[0] = tf;
                m[1] = uf;
                m[2] = vf;
                m[3] = wf;
            }

            b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>
                (l) - 1)];
            b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l)
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
            ml1_0[0] = ml1_tmp;
            ml1_data[0] = ml1_tmp;
            b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + s1->size[0]) - 1)];
            b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + g1->size[0]) - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + ml1->size[0]) - 1)];
            ml1_0[1] = ml1_tmp;
            ml1_data[1] = ml1_tmp;
            b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1))
                - 1)];
            b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1))
                - 1)];
            ml1_0[2] = ml1_tmp;
            ml1_data[2] = ml1_tmp;
            b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3))
                - 1)];
            b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3))
                - 1)];
            ml1_0[3] = ml1_tmp;
            ml1_data[3] = ml1_tmp;
            FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_i
                (b_startPose, b_goalPose, localDW->b_fpa_data
                 [static_cast<int32_T>(static_cast<int32_T>(l) - 1)],
                 localDW->b_a_data[0], localDW->mtr_data[0], localDW->h_data[
                 static_cast<int32_T>(static_cast<int32_T>(l) - 1)], m, ml1_0,
                 &pathSegObjs_data[static_cast<int32_T>(loop_ub_tmp - 1)]);
            pathCosts_data[static_cast<int32_T>(loop_ub_tmp - 1)] =
                FlightMissionMode_sum(ml1_data);
        }
    }

    FlightMissionMode_emxFree_real_T_j(&ml1);
    FlightMissionMode_emxFree_real_T_j(&g1);
    FlightMissionMode_emxFree_real_T_j(&s1);
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_uavDubinsConnection_connect(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPoses[4],
    const real_T goalPoses[4], uavDubinsPathSegment_FlightMissionMode_T
    pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
    int32_T *pathCosts_size, DW_WayPointGenerator_FlightMissionMode_T *localDW)
{
    matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
        parser;
    real_T idx_data[28];
    int32_T tmp_size[2];
    int32_T flagOptimal;
    int32_T idx_size;
    char_T tmp_data[7];
    FlightMissionMode_NameValueParser_NameValueParser(&parser);
    parser.ParsedResults = parser.Defaults;
    flagOptimal = 1;
    FlightMissionMode_validatestring(parser.ParsedResults.f1, tmp_data, tmp_size);
    if (FlightMissionMode_strcmp(tmp_data, tmp_size)) {
        flagOptimal = 0;
    }

    FlightMissionMode_uavDubinsConnection_findDisabledIndices(idx_data,
        &idx_size);
    FlightMissionMode_uavDubinsBuiltins_connect(obj, startPoses, goalPoses,
        flagOptimal == 1, obj->MinTurningRadius, idx_data, &idx_size,
        pathSegObjs_data, pathSegObjs_size, pathCosts_data, pathCosts_size,
        localDW);
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_strcmp_kav(const cell_wrap_10_FlightMissionMode_T
    a[4], boolean_T b_bool[4])
{
    b_bool[0] = false;
    if ((a[0].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[0].f1.data[0] != 'N') ^ 1)))) {
        b_bool[0] = true;
    }

    b_bool[1] = false;
    if ((a[1].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[1].f1.data[0] != 'N') ^ 1)))) {
        b_bool[1] = true;
    }

    b_bool[2] = false;
    if ((a[2].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[2].f1.data[0] != 'N') ^ 1)))) {
        b_bool[2] = true;
    }

    b_bool[3] = false;
    if ((a[3].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[3].f1.data[0] != 'N') ^ 1)))) {
        b_bool[3] = true;
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_any(const boolean_T x[4])
{
    int32_T k;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(x[k])
              ^ 1))) {
            k = static_cast<int32_T>(k + 1);
        } else {
            y = true;
            exitg1 = true;
        }
    }

    return y;
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_useConstantDim(const real_T varargin_2_data[],
    const int32_T varargin_2_size[2], real_T varargout_1_data[], int32_T
    varargout_1_size[2])
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

static void FlightMissionMode_emxInit_int32_T
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_int32_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_int32_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_int32_T_FlightMissionMode_T));
    emxArray = *pEmxArray;
    emxArray->data = (int32_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void FlightMissionMode_emxEnsureCapacity_int32_T
    (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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
            std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
                         (int32_T) * static_cast<uint32_T>(oldNumel)));
            if (emxArray->canFreeData) {
                std::free(emxArray->data);
            }
        }

        emxArray->data = (int32_T *)newData;
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

static void FlightMissionMode_emxInit_real_T1
    (emxArray_real_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_real_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_real_T_FlightMissionMode_T));
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

static void FlightMissionMode_emxEnsureCapacity_real_T1
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

static void FlightMissionMode_emxInit_int32_T1
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_int32_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_int32_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_int32_T_FlightMissionMode_T));
    emxArray = *pEmxArray;
    emxArray->data = (int32_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void FlightMissionMode_emxEnsureCapacity_int32_T1
    (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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
            std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
                         (int32_T) * static_cast<uint32_T>(oldNumel)));
            if (emxArray->canFreeData) {
                std::free(emxArray->data);
            }
        }

        emxArray->data = (int32_T *)newData;
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

static void FlightMissionMode_emxFree_int32_T
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_int32_T_FlightMissionMode_T *)nullptr) {
        if (((*pEmxArray)->data != (int32_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_int32_T_FlightMissionMode_T *)nullptr;
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_merge_lv(emxArray_int32_T_FlightMissionMode_T *idx,
    emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T np, int32_T
    nq, emxArray_int32_T_FlightMissionMode_T *iwork,
    emxArray_real_T_FlightMissionMode_T *xwork)
{
    int32_T exitg1;
    int32_T iout;
    int32_T n;
    int32_T n_tmp;
    int32_T q;
    if (nq != 0) {
        n_tmp = static_cast<int32_T>(np + nq);
        for (q = 0; q <= static_cast<int32_T>(n_tmp - 1); q =
                static_cast<int32_T>(q + 1)) {
            iout = static_cast<int32_T>(offset + q);
            iwork->data[q] = idx->data[iout];
            xwork->data[q] = x->data[iout];
        }

        n = 0;
        q = np;
        iout = static_cast<int32_T>(offset - 1);
        do {
            exitg1 = 0;
            iout = static_cast<int32_T>(iout + 1);
            if (xwork->data[n] <= xwork->data[q]) {
                idx->data[iout] = iwork->data[n];
                x->data[iout] = xwork->data[n];
                if (static_cast<int32_T>(n + 1) < np) {
                    n = static_cast<int32_T>(n + 1);
                } else {
                    exitg1 = 1;
                }
            } else {
                idx->data[iout] = iwork->data[q];
                x->data[iout] = xwork->data[q];
                if (static_cast<int32_T>(q + 1) < n_tmp) {
                    q = static_cast<int32_T>(q + 1);
                } else {
                    q = static_cast<int32_T>(iout - n);
                    while (static_cast<int32_T>(n + 1) <= np) {
                        n_tmp = static_cast<int32_T>(static_cast<int32_T>(q + n)
                            + 1);
                        idx->data[n_tmp] = iwork->data[n];
                        x->data[n_tmp] = xwork->data[n];
                        n = static_cast<int32_T>(n + 1);
                    }

                    exitg1 = 1;
                }
            }
        } while (exitg1 == 0);
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_merge_block(emxArray_int32_T_FlightMissionMode_T
    *idx, emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T n,
    int32_T preSortLevel, emxArray_int32_T_FlightMissionMode_T *iwork,
    emxArray_real_T_FlightMissionMode_T *xwork)
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
                FlightMissionMode_merge_lv(idx, x, static_cast<int32_T>(offset +
                    tailOffset), bLen, static_cast<int32_T>(nTail - bLen), iwork,
                    xwork);
            }
        }

        tailOffset = static_cast<int32_T>(bLen << 1);
        nPairs = static_cast<int32_T>(nPairs >> 1);
        for (nTail = 0; nTail <= static_cast<int32_T>(nPairs - 1); nTail =
                static_cast<int32_T>(nTail + 1)) {
            FlightMissionMode_merge_lv(idx, x, static_cast<int32_T>(offset +
                static_cast<int32_T>(nTail * tailOffset)), bLen, bLen, iwork,
                xwork);
        }

        bLen = tailOffset;
    }

    if (n > bLen) {
        FlightMissionMode_merge_lv(idx, x, offset, bLen, static_cast<int32_T>(n
            - bLen), iwork, xwork);
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_sort_bq(emxArray_real_T_FlightMissionMode_T *x)
{
    emxArray_int32_T_FlightMissionMode_T *idx;
    emxArray_int32_T_FlightMissionMode_T *iwork;
    emxArray_real_T_FlightMissionMode_T *b_x;
    emxArray_real_T_FlightMissionMode_T *xwork;
    real_T b_xwork[256];
    real_T x4[4];
    real_T tmp;
    real_T tmp_0;
    int32_T b_iwork[256];
    int32_T idx4[4];
    int32_T bLen;
    int32_T bLen2;
    int32_T b_iwork_tmp;
    int32_T blockOffset;
    int32_T e_k;
    int32_T exitg1;
    int32_T i1;
    int32_T ib;
    int32_T n;
    int32_T nBlocks;
    int32_T nPairs;
    int32_T p;
    int32_T q;
    int32_T wOffset;
    int8_T perm[4];
    FlightMissionMode_emxInit_real_T_l(&b_x, 2);
    b_iwork_tmp = static_cast<int32_T>(b_x->size[0] * b_x->size[1]);
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    FlightMissionMode_emxEnsureCapacity_real_T_p(b_x, b_iwork_tmp);
    i1 = static_cast<int32_T>(x->size[1] - 1);
    for (ib = 0; ib <= i1; ib++) {
        b_x->data[ib] = x->data[ib];
    }

    if (x->size[1] != 0) {
        b_iwork_tmp = static_cast<int32_T>(b_x->size[0] * b_x->size[1]);
        b_x->size[0] = 1;
        b_x->size[1] = x->size[1];
        FlightMissionMode_emxEnsureCapacity_real_T_p(b_x, b_iwork_tmp);
        i1 = static_cast<int32_T>(x->size[1] - 1);
        for (ib = 0; ib <= i1; ib++) {
            b_x->data[ib] = x->data[ib];
        }

        FlightMissionMode_emxInit_int32_T(&idx, 2);
        b_iwork_tmp = static_cast<int32_T>(idx->size[0] * idx->size[1]);
        idx->size[0] = 1;
        idx->size[1] = x->size[1];
        FlightMissionMode_emxEnsureCapacity_int32_T(idx, b_iwork_tmp);
        i1 = static_cast<int32_T>(x->size[1] - 1);
        for (ib = 0; ib <= i1; ib++) {
            idx->data[ib] = 0;
        }

        FlightMissionMode_emxInit_real_T1(&xwork, 1);
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
        FlightMissionMode_emxEnsureCapacity_real_T1(xwork, b_iwork_tmp);
        i1 = x->size[1];
        for (ib = 0; ib <= static_cast<int32_T>(i1 - 1); ib++) {
            xwork->data[ib] = 0.0;
        }

        nBlocks = 0;
        ib = 0;
        for (wOffset = 0; wOffset <= static_cast<int32_T>(n - 1); wOffset =
                static_cast<int32_T>(wOffset + 1)) {
            if (std::isnan(b_x->data[wOffset])) {
                q = static_cast<int32_T>(static_cast<int32_T>(n - nBlocks) - 1);
                idx->data[q] = static_cast<int32_T>(wOffset + 1);
                xwork->data[q] = b_x->data[wOffset];
                nBlocks = static_cast<int32_T>(nBlocks + 1);
            } else {
                ib = static_cast<int32_T>(ib + 1);
                idx4[static_cast<int32_T>(ib - 1)] = static_cast<int32_T>
                    (wOffset + 1);
                x4[static_cast<int32_T>(ib - 1)] = b_x->data[wOffset];
                if (ib == 4) {
                    ib = static_cast<int32_T>(wOffset - nBlocks);
                    if (x4[0] <= x4[1]) {
                        i1 = 1;
                        bLen = 2;
                    } else {
                        i1 = 2;
                        bLen = 1;
                    }

                    if (x4[2] <= x4[3]) {
                        bLen2 = 3;
                        nPairs = 4;
                    } else {
                        bLen2 = 4;
                        nPairs = 3;
                    }

                    tmp = x4[static_cast<int32_T>(i1 - 1)];
                    tmp_0 = x4[static_cast<int32_T>(bLen2 - 1)];
                    if (tmp <= tmp_0) {
                        tmp = x4[static_cast<int32_T>(bLen - 1)];
                        if (tmp <= tmp_0) {
                            perm[0] = static_cast<int8_T>(i1);
                            perm[1] = static_cast<int8_T>(bLen);
                            perm[2] = static_cast<int8_T>(bLen2);
                            perm[3] = static_cast<int8_T>(nPairs);
                        } else if (tmp <= x4[static_cast<int32_T>(nPairs - 1)])
                        {
                            perm[0] = static_cast<int8_T>(i1);
                            perm[1] = static_cast<int8_T>(bLen2);
                            perm[2] = static_cast<int8_T>(bLen);
                            perm[3] = static_cast<int8_T>(nPairs);
                        } else {
                            perm[0] = static_cast<int8_T>(i1);
                            perm[1] = static_cast<int8_T>(bLen2);
                            perm[2] = static_cast<int8_T>(nPairs);
                            perm[3] = static_cast<int8_T>(bLen);
                        }
                    } else {
                        tmp_0 = x4[static_cast<int32_T>(nPairs - 1)];
                        if (tmp <= tmp_0) {
                            if (x4[static_cast<int32_T>(bLen - 1)] <= tmp_0) {
                                perm[0] = static_cast<int8_T>(bLen2);
                                perm[1] = static_cast<int8_T>(i1);
                                perm[2] = static_cast<int8_T>(bLen);
                                perm[3] = static_cast<int8_T>(nPairs);
                            } else {
                                perm[0] = static_cast<int8_T>(bLen2);
                                perm[1] = static_cast<int8_T>(i1);
                                perm[2] = static_cast<int8_T>(nPairs);
                                perm[3] = static_cast<int8_T>(bLen);
                            }
                        } else {
                            perm[0] = static_cast<int8_T>(bLen2);
                            perm[1] = static_cast<int8_T>(nPairs);
                            perm[2] = static_cast<int8_T>(i1);
                            perm[3] = static_cast<int8_T>(bLen);
                        }
                    }

                    idx->data[static_cast<int32_T>(ib - 3)] = idx4[static_cast<
                        int32_T>(static_cast<int32_T>(perm[0]) - 1)];
                    idx->data[static_cast<int32_T>(ib - 2)] = idx4[static_cast<
                        int32_T>(static_cast<int32_T>(perm[1]) - 1)];
                    idx->data[static_cast<int32_T>(ib - 1)] = idx4[static_cast<
                        int32_T>(static_cast<int32_T>(perm[2]) - 1)];
                    idx->data[ib] = idx4[static_cast<int32_T>
                        (static_cast<int32_T>(perm[3]) - 1)];
                    b_x->data[static_cast<int32_T>(ib - 3)] = x4
                        [static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)];
                    b_x->data[static_cast<int32_T>(ib - 2)] = x4
                        [static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)];
                    b_x->data[static_cast<int32_T>(ib - 1)] = x4
                        [static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)];
                    b_x->data[ib] = x4[static_cast<int32_T>(static_cast<int32_T>
                        (perm[3]) - 1)];
                    ib = 0;
                }
            }
        }

        wOffset = static_cast<int32_T>(static_cast<int32_T>(x->size[1] - nBlocks)
            - 1);
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

            for (i1 = 0; i1 <= static_cast<int32_T>(ib - 1); i1 =
                    static_cast<int32_T>(i1 + 1)) {
                q = static_cast<int32_T>(static_cast<int32_T>(perm[i1]) - 1);
                b_iwork_tmp = static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(wOffset - ib) + i1) + 1);
                idx->data[b_iwork_tmp] = idx4[q];
                b_x->data[b_iwork_tmp] = x4[q];
            }
        }

        ib = static_cast<int32_T>(static_cast<int32_T>(nBlocks >> 1) + 1);
        for (i1 = 1; static_cast<int32_T>(i1 - 1) <= static_cast<int32_T>(ib - 2);
             i1 = static_cast<int32_T>(i1 + 1)) {
            bLen2 = static_cast<int32_T>(wOffset + i1);
            bLen = idx->data[bLen2];
            q = static_cast<int32_T>(n - i1);
            idx->data[bLen2] = idx->data[q];
            idx->data[q] = bLen;
            b_x->data[bLen2] = xwork->data[q];
            b_x->data[q] = xwork->data[bLen2];
        }

        if (static_cast<uint32_T>(static_cast<uint32_T>(nBlocks) & 1U) != 0U) {
            wOffset = static_cast<int32_T>(wOffset + ib);
            b_x->data[wOffset] = xwork->data[wOffset];
        }

        FlightMissionMode_emxInit_int32_T1(&iwork, 1);
        b_iwork_tmp = iwork->size[0];
        iwork->size[0] = x->size[1];
        FlightMissionMode_emxEnsureCapacity_int32_T1(iwork, b_iwork_tmp);
        i1 = x->size[1];
        for (ib = 0; ib <= static_cast<int32_T>(i1 - 1); ib++) {
            iwork->data[ib] = 0;
        }

        n = static_cast<int32_T>(x->size[1] - nBlocks);
        wOffset = 2;
        if (n > 1) {
            if (x->size[1] >= 256) {
                nBlocks = static_cast<int32_T>(n >> 8);
                if (nBlocks > 0) {
                    for (ib = 0; ib <= static_cast<int32_T>(nBlocks - 1); ib =
                            static_cast<int32_T>(ib + 1)) {
                        i1 = static_cast<int32_T>(static_cast<int32_T>(ib << 8)
                            - 1);
                        for (wOffset = 0; wOffset < 6; wOffset++) {
                            bLen = static_cast<int32_T>(1 << static_cast<int32_T>
                                (wOffset + 2));
                            bLen2 = static_cast<int32_T>(bLen << 1);
                            nPairs = static_cast<int32_T>(256 >>
                                static_cast<int32_T>(wOffset + 3));
                            for (e_k = 0; e_k <= static_cast<int32_T>(nPairs - 1);
                                 e_k = static_cast<int32_T>(e_k + 1)) {
                                blockOffset = static_cast<int32_T>
                                    (static_cast<int32_T>(e_k * bLen2) + i1);
                                for (p = 0; p <= static_cast<int32_T>(bLen2 - 1);
                                     p = static_cast<int32_T>(p + 1)) {
                                    b_iwork_tmp = static_cast<int32_T>(
                                        static_cast<int32_T>(blockOffset + p) +
                                        1);
                                    b_iwork[p] = idx->data[b_iwork_tmp];
                                    b_xwork[p] = b_x->data[b_iwork_tmp];
                                }

                                p = 0;
                                q = bLen;
                                do {
                                    exitg1 = 0;
                                    blockOffset = static_cast<int32_T>
                                        (blockOffset + 1);
                                    if (b_xwork[p] <= b_xwork[q]) {
                                        idx->data[blockOffset] = b_iwork[p];
                                        b_x->data[blockOffset] = b_xwork[p];
                                        if (static_cast<int32_T>(p + 1) < bLen)
                                        {
                                            p = static_cast<int32_T>(p + 1);
                                        } else {
                                            exitg1 = 1;
                                        }
                                    } else {
                                        idx->data[blockOffset] = b_iwork[q];
                                        b_x->data[blockOffset] = b_xwork[q];
                                        if (static_cast<int32_T>(q + 1) < bLen2)
                                        {
                                            q = static_cast<int32_T>(q + 1);
                                        } else {
                                            blockOffset = static_cast<int32_T>
                                                (blockOffset - p);
                                            while (static_cast<int32_T>(p + 1) <=
                                                   bLen) {
                                                b_iwork_tmp =
                                                    static_cast<int32_T>(
                                                    static_cast<int32_T>
                                                    (blockOffset + p) + 1);
                                                idx->data[b_iwork_tmp] =
                                                    b_iwork[p];
                                                b_x->data[b_iwork_tmp] =
                                                    b_xwork[p];
                                                p = static_cast<int32_T>(p + 1);
                                            }

                                            exitg1 = 1;
                                        }
                                    }
                                } while (exitg1 == 0);
                            }
                        }
                    }

                    nBlocks = static_cast<int32_T>(nBlocks << 8);
                    wOffset = static_cast<int32_T>(n - nBlocks);
                    if (wOffset > 0) {
                        b_iwork_tmp = iwork->size[0];
                        iwork->size[0] = x->size[1];
                        FlightMissionMode_emxEnsureCapacity_int32_T1(iwork,
                            b_iwork_tmp);
                        i1 = x->size[1];
                        for (ib = 0; ib <= static_cast<int32_T>(i1 - 1); ib++) {
                            iwork->data[ib] = 0;
                        }

                        FlightMissionMode_merge_block(idx, b_x, nBlocks, wOffset,
                            2, iwork, xwork);
                    }

                    wOffset = 8;
                }
            }

            FlightMissionMode_merge_block(idx, b_x, 0, n, wOffset, iwork, xwork);
        }

        FlightMissionMode_emxFree_int32_T(&idx);
        FlightMissionMode_emxFree_real_T_j(&xwork);
        FlightMissionMode_emxFree_int32_T(&iwork);
    }

    b_iwork_tmp = static_cast<int32_T>(x->size[0] * x->size[1]);
    x->size[0] = 1;
    x->size[1] = b_x->size[1];
    FlightMissionMode_emxEnsureCapacity_real_T_p(x, b_iwork_tmp);
    i1 = b_x->size[1];
    for (ib = 0; ib <= static_cast<int32_T>(i1 - 1); ib++) {
        x->data[ib] = b_x->data[ib];
    }

    FlightMissionMode_emxFree_real_T_j(&b_x);
}

static void FlightMissionMode_emxInit_boolean_T
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_boolean_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_boolean_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_boolean_T_FlightMissionMode_T));
    emxArray = *pEmxArray;
    emxArray->data = (boolean_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void FlightMissionMode_emxFree_boolean_T
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_boolean_T_FlightMissionMode_T *)nullptr) {
        if (((*pEmxArray)->data != (boolean_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_boolean_T_FlightMissionMode_T *)nullptr;
    }
}

static void FlightMissionMode_emxEnsureCapacity_boolean_T
    (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

static void FlightMissionMode_emxInit_boolean_T1
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_boolean_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_boolean_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_boolean_T_FlightMissionMode_T));
    emxArray = *pEmxArray;
    emxArray->data = (boolean_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void FlightMissionMode_emxEnsureCapacity_boolean_T1
    (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_wrapToPi(emxArray_real_T_FlightMissionMode_T
    *theta)
{
    emxArray_boolean_T_FlightMissionMode_T *x;
    emxArray_real_T_FlightMissionMode_T *y;
    int32_T b_k;
    int32_T loop_ub;
    boolean_T b_y;
    boolean_T exitg1;
    FlightMissionMode_emxInit_real_T1(&y, 1);
    b_k = y->size[0];
    y->size[0] = theta->size[0];
    FlightMissionMode_emxEnsureCapacity_real_T1(y, b_k);
    for (b_k = 0; b_k <= static_cast<int32_T>(theta->size[0] - 1); b_k =
            static_cast<int32_T>(b_k + 1)) {
        y->data[b_k] = std::abs(theta->data[b_k]);
    }

    FlightMissionMode_emxInit_boolean_T1(&x, 1);
    b_k = x->size[0];
    x->size[0] = y->size[0];
    FlightMissionMode_emxEnsureCapacity_boolean_T1(x, b_k);
    loop_ub = y->size[0];
    for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
        x->data[b_k] = (y->data[b_k] > 3.1415926535897931);
    }

    b_y = false;
    b_k = 1;
    exitg1 = false;
    while ((!exitg1) && (b_k <= x->size[0])) {
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (x->data[static_cast<int32_T>(b_k - 1)]) ^ 1))) {
            b_k = static_cast<int32_T>(b_k + 1);
        } else {
            b_y = true;
            exitg1 = true;
        }
    }

    if (b_y) {
        b_k = y->size[0];
        y->size[0] = theta->size[0];
        FlightMissionMode_emxEnsureCapacity_real_T1(y, b_k);
        loop_ub = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            y->data[b_k] = theta->data[b_k] + 3.1415926535897931;
        }

        b_k = theta->size[0];
        theta->size[0] = y->size[0];
        FlightMissionMode_emxEnsureCapacity_real_T1(theta, b_k);
        for (b_k = 0; b_k <= static_cast<int32_T>(y->size[0] - 1); b_k =
                static_cast<int32_T>(b_k + 1)) {
            theta->data[b_k] = mod_dBqh4Vat(y->data[b_k]);
        }

        b_k = x->size[0];
        x->size[0] = theta->size[0];
        FlightMissionMode_emxEnsureCapacity_boolean_T1(x, b_k);
        loop_ub = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            x->data[b_k] = (theta->data[b_k] == 0.0);
        }

        for (b_k = 0; b_k <= static_cast<int32_T>(x->size[0] - 1); b_k =
                static_cast<int32_T>(b_k + 1)) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (x->data[b_k]) & (y->data[b_k] > 0.0)))) {
                theta->data[b_k] = 6.2831853071795862;
            }
        }

        loop_ub = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            theta->data[b_k] -= 3.1415926535897931;
        }
    }

    FlightMissionMode_emxFree_boolean_T(&x);
    FlightMissionMode_emxFree_real_T_j(&y);
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_eml_find(const
    emxArray_boolean_T_FlightMissionMode_T *x,
    emxArray_int32_T_FlightMissionMode_T *i)
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
    FlightMissionMode_emxEnsureCapacity_int32_T(i, ii);
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
        FlightMissionMode_emxEnsureCapacity_int32_T(i, ii);
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_kavm(const char_T a_data[], const
    int32_T a_size[2])
{
    boolean_T b_bool;
    b_bool = false;
    if ((a_size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a_data[0] != 'N') ^ 1)))) {
        b_bool = true;
    }

    return b_bool;
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_kavm1(const char_T a_data[], const
    int32_T a_size[2])
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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_kavm1m(const char_T a_data[], const
    int32_T a_size[2])
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

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_kavm1mq(const char_T a_data[], const
    int32_T a_size[2])
{
    boolean_T b_bool;
    b_bool = false;
    if ((a_size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a_data[0] != 'L') ^ 1)))) {
        b_bool = true;
    }

    return b_bool;
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_kavm1mqe(const char_T a_data[], const
    int32_T a_size[2])
{
    boolean_T b_bool;
    b_bool = false;
    if ((a_size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a_data[0] != 'R') ^ 1)))) {
        b_bool = true;
    }

    return b_bool;
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_kavm1mqel(const char_T a_data[], const
    int32_T a_size[2])
{
    boolean_T b_bool;
    b_bool = false;
    if ((a_size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a_data[0] != 'S') ^ 1)))) {
        b_bool = true;
    }

    return b_bool;
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_mtimes(const emxArray_real_T_FlightMissionMode_T
    *A, const real_T B[4], emxArray_real_T_FlightMissionMode_T *C)
{
    int32_T i;
    int32_T m;
    m = A->size[0];
    i = static_cast<int32_T>(C->size[0] * C->size[1]);
    C->size[0] = A->size[0];
    C->size[1] = 2;
    FlightMissionMode_emxEnsureCapacity_real_T_p(C, i);
    for (i = 0; i <= static_cast<int32_T>(m - 1); i = static_cast<int32_T>(i + 1))
    {
        C->data[i] = A->data[i] * B[0] + A->data[static_cast<int32_T>(A->size[0]
            + i)] * B[1];
    }

    for (i = 0; i <= static_cast<int32_T>(m - 1); i = static_cast<int32_T>(i + 1))
    {
        C->data[static_cast<int32_T>(m + i)] = A->data[i] * B[2] + A->data[
            static_cast<int32_T>(A->size[0] + i)] * B[3];
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_uavDubinsPathSegment_interpolate(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_10_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length,
    emxArray_real_T_FlightMissionMode_T *samples,
    emxArray_real_T_FlightMissionMode_T *poses)
{
    emxArray_boolean_T_FlightMissionMode_T *tempSamplesIndex;
    emxArray_boolean_T_FlightMissionMode_T *tempSamplesIndex_0;
    emxArray_int32_T_FlightMissionMode_T *ab;
    emxArray_real_T_FlightMissionMode_T *S;
    emxArray_real_T_FlightMissionMode_T *S_0;
    emxArray_real_T_FlightMissionMode_T *e_x;
    emxArray_real_T_FlightMissionMode_T *ns;
    emxArray_real_T_FlightMissionMode_T *p;
    emxArray_real_T_FlightMissionMode_T *tempSamples;
    emxArray_real_T_FlightMissionMode_T *z;
    real_T state[6];
    real_T TransformMatrix[4];
    real_T c_x_data[4];
    real_T tempMotionLength_data[4];
    real_T TransformMatrix_tmp;
    real_T b_b_tmp;
    real_T intermediateLength;
    real_T radius;
    real_T samples_0;
    real_T startIndex;
    real_T state_0;
    real_T state_1;
    real_T tempStartPose_idx_2;
    int32_T c_x_size[2];
    int32_T tempMotionLength_size[2];
    int32_T S_idx_0;
    int32_T count;
    int32_T loop_ub;
    int32_T poses_0;
    int32_T tempMotionLength_data_tmp;
    int32_T tempMotionLength_data_tmp_0;
    boolean_T tmp[4];
    poses->size[0] = 0;
    poses->size[1] = 6;
    if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isnan(b_this_Length)) ^ 1))) && (samples->size[1] != 0)) {
        tempStartPose_idx_2 = -b_this_StartPose[2];
        tempMotionLength_data_tmp = static_cast<int32_T>(poses->size[0] *
            poses->size[1]);
        poses->size[0] = samples->size[1];
        poses->size[1] = 6;
        FlightMissionMode_emxEnsureCapacity_real_T_p(poses,
            tempMotionLength_data_tmp);
        loop_ub = static_cast<int32_T>(static_cast<int32_T>(samples->size[1] * 6)
            - 1);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <= loop_ub;
             tempMotionLength_data_tmp++) {
            poses->data[tempMotionLength_data_tmp] = 0.0;
        }

        b_b_tmp = std::cos(std::abs(b_this_FlightPathAngle));
        tempMotionLength_data_tmp = static_cast<int32_T>(samples->size[0] *
            samples->size[1]);
        samples->size[0] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_p(samples,
            tempMotionLength_data_tmp);
        loop_ub = static_cast<int32_T>(samples->size[1] - 1);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <= loop_ub;
             tempMotionLength_data_tmp++) {
            samples->data[tempMotionLength_data_tmp] *= b_b_tmp;
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
        FlightMissionMode_strcmp_kav(b_this_MotionTypes, tmp);
        if (FlightMissionMode_any(tmp)) {
            tempMotionLength_size[0] = 1;
            tempMotionLength_size[1] = 3;
            tempMotionLength_data[0] = TransformMatrix[0];
            tempMotionLength_data[1] = TransformMatrix[1];
            tempMotionLength_data[2] = TransformMatrix[2];
        }

        FlightMissionMode_useConstantDim(tempMotionLength_data,
            tempMotionLength_size, c_x_data, c_x_size);
        FlightMissionMode_sort_bq(samples);
        intermediateLength = 0.0;
        startIndex = 1.0;
        state[0] = b_this_StartPose[0];
        state[1] = -b_this_StartPose[1];
        state[3] = -b_this_StartPose[3];
        poses_0 = 0;
        FlightMissionMode_emxInit_boolean_T(&tempSamplesIndex, 2);
        FlightMissionMode_emxInit_real_T1(&tempSamples, 1);
        FlightMissionMode_emxInit_real_T1(&S, 1);
        FlightMissionMode_emxInit_real_T_l(&ns, 2);
        FlightMissionMode_emxInit_real_T1(&z, 1);
        FlightMissionMode_emxInit_real_T_l(&p, 2);
        FlightMissionMode_emxInit_real_T1(&e_x, 1);
        FlightMissionMode_emxInit_int32_T(&ab, 2);
        FlightMissionMode_emxInit_boolean_T(&tempSamplesIndex_0, 2);
        FlightMissionMode_emxInit_real_T_l(&S_0, 2);
        while (poses_0 <= static_cast<int32_T>(tempMotionLength_size[1] - 1)) {
            if (static_cast<int32_T>(poses_0 + 1) == 1) {
                tempMotionLength_data_tmp = static_cast<int32_T>
                    (tempSamplesIndex->size[0] * tempSamplesIndex->size[1]);
                tempSamplesIndex->size[0] = 1;
                tempSamplesIndex->size[1] = samples->size[1];
                FlightMissionMode_emxEnsureCapacity_boolean_T(tempSamplesIndex,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(samples->size[1] - 1);
                radius = (intermediateLength + tempMotionLength_data[0]) +
                    1.0E-6;
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    samples_0 = samples->data[tempMotionLength_data_tmp];
                    tempSamplesIndex->data[tempMotionLength_data_tmp] =
                        static_cast<boolean_T>(static_cast<int32_T>((samples_0 >=
                        intermediateLength) & (samples_0 <= radius)));
                }
            } else {
                tempMotionLength_data_tmp = static_cast<int32_T>
                    (tempSamplesIndex->size[0] * tempSamplesIndex->size[1]);
                tempSamplesIndex->size[0] = 1;
                tempSamplesIndex->size[1] = samples->size[1];
                FlightMissionMode_emxEnsureCapacity_boolean_T(tempSamplesIndex,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(samples->size[1] - 1);
                radius = (intermediateLength + tempMotionLength_data[poses_0]) +
                    1.0E-6;
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    samples_0 = samples->data[tempMotionLength_data_tmp];
                    tempSamplesIndex->data[tempMotionLength_data_tmp] =
                        static_cast<boolean_T>(static_cast<int32_T>((samples_0 >
                        intermediateLength) & (samples_0 <= radius)));
                }
            }

            tempMotionLength_data_tmp = static_cast<int32_T>
                (tempSamplesIndex_0->size[0] * tempSamplesIndex_0->size[1]);
            tempSamplesIndex_0->size[0] = 1;
            tempSamplesIndex_0->size[1] = tempSamplesIndex->size[1];
            FlightMissionMode_emxEnsureCapacity_boolean_T(tempSamplesIndex_0,
                tempMotionLength_data_tmp);
            loop_ub = tempSamplesIndex->size[1];
            for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                    static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp
                    ++) {
                tempSamplesIndex_0->data[tempMotionLength_data_tmp] =
                    tempSamplesIndex->data[tempMotionLength_data_tmp];
            }

            FlightMissionMode_eml_find(tempSamplesIndex_0, ab);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (FlightMissionMode_strcmp_kavm(b_this_MotionTypes[poses_0].
                    f1.data, b_this_MotionTypes[poses_0].f1.size)) ^ 1))) {
                radius = b_this_MinTurningRadius;
                if (FlightMissionMode_strcmp_kavm1(b_this_MotionTypes[poses_0].
                        f1.data, b_this_MotionTypes[poses_0].f1.size)) {
                    radius = b_this_HelixRadius;
                } else if (FlightMissionMode_strcmp_kavm1m
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    radius = b_this_HelixRadius;
                }

                count = 0;
                tempMotionLength_data_tmp = tempSamples->size[0];
                tempSamples->size[0] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T1(tempSamples,
                    tempMotionLength_data_tmp);
                tempSamples->data[0] = 0.0;
                if (ab->size[1] != 0) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = static_cast<int32_T>(ab->size[1] + 1);
                    FlightMissionMode_emxEnsureCapacity_real_T1(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = ab->size[1];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = 0.0;
                    }

                    count = ab->size[1];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] =
                            samples->data[static_cast<int32_T>(ab->
                            data[tempMotionLength_data_tmp] - 1)];
                    }

                    count = ab->size[1];
                    loop_ub = static_cast<int32_T>(ab->size[1] - 1);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        samples->data[static_cast<int32_T>(ab->
                            data[tempMotionLength_data_tmp] - 1)] = -1.0;
                    }
                }

                tempSamples->data[count] = c_x_data[poses_0];
                tempMotionLength_data_tmp = S->size[0];
                S->size[0] = tempSamples->size[0];
                FlightMissionMode_emxEnsureCapacity_real_T1(S,
                    tempMotionLength_data_tmp);
                loop_ub = tempSamples->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     static_cast<int32_T>(loop_ub - 1);
                        tempMotionLength_data_tmp++) {
                    S->data[tempMotionLength_data_tmp] = (tempSamples->
                        data[tempMotionLength_data_tmp] - intermediateLength) /
                        radius;
                }

                tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0] *
                    ns->size[1]);
                ns->size[0] = S->size[0];
                ns->size[1] = 6;
                FlightMissionMode_emxEnsureCapacity_real_T_p(ns,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(S->size[0] *
                    6) - 1);
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    ns->data[tempMotionLength_data_tmp] = 0.0;
                }

                tempMotionLength_data_tmp = z->size[0];
                z->size[0] = tempSamples->size[0];
                FlightMissionMode_emxEnsureCapacity_real_T1(z,
                    tempMotionLength_data_tmp);
                loop_ub = tempSamples->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     static_cast<int32_T>(loop_ub - 1);
                        tempMotionLength_data_tmp++) {
                    z->data[tempMotionLength_data_tmp] = tempStartPose_idx_2 +
                        tempSamples->data[tempMotionLength_data_tmp];
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
                    tempMotionLength_data_tmp = z->size[0];
                    z->size[0] = tempSamples->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1(z,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        z->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp] /
                            TransformMatrix_tmp * samples_0 +
                            tempStartPose_idx_2;
                    }
                }

                if (FlightMissionMode_strcmp_kavm1(b_this_MotionTypes[poses_0].
                        f1.data, b_this_MotionTypes[poses_0].f1.size) ||
                        FlightMissionMode_strcmp_kavm1mq
                        (b_this_MotionTypes[poses_0].f1.data,
                         b_this_MotionTypes[poses_0].f1.size)) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        tempSamples->data[count] = std::sin(tempSamples->
                            data[count]);
                    }

                    tempMotionLength_data_tmp = e_x->size[0];
                    e_x->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1(e_x,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        e_x->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        e_x->data[count] = std::cos(e_x->data[count]);
                    }

                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = tempSamples->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_p(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = e_x->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + tempSamples->size[0])] = 1.0 - e_x->
                            data[tempMotionLength_data_tmp];
                    }

                    FlightMissionMode_mtimes(S_0, TransformMatrix, p);
                    samples_0 = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed,
                        9.8 * radius);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_p(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state_1
                            + S->data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] =
                            -samples_0;
                    }
                } else if (FlightMissionMode_strcmp_kavm1m
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size) ||
                           FlightMissionMode_strcmp_kavm1mqe
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        tempSamples->data[count] = std::sin(tempSamples->
                            data[count]);
                    }

                    tempMotionLength_data_tmp = e_x->size[0];
                    e_x->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1(e_x,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        e_x->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        e_x->data[count] = std::cos(e_x->data[count]);
                    }

                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = tempSamples->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_p(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = e_x->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + tempSamples->size[0])] = e_x->
                            data[tempMotionLength_data_tmp] - 1.0;
                    }

                    FlightMissionMode_mtimes(S_0, TransformMatrix, p);
                    samples_0 = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed,
                        9.8 * radius);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_p(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state_1
                            - S->data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] =
                            samples_0;
                    }
                } else if (FlightMissionMode_strcmp_kavm1mqel
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    count = S->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = S->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_p(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + S->size[0])] = 0.0;
                    }

                    FlightMissionMode_mtimes(S_0, TransformMatrix, p);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    S_idx_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_p(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state[3];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (S_idx_0 - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] = 0.0;
                    }
                }

                if (ab->size[1] != 0) {
                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp < 6;
                            tempMotionLength_data_tmp++) {
                        for (tempMotionLength_data_tmp_0 = 0;
                                tempMotionLength_data_tmp_0 <= loop_ub;
                                tempMotionLength_data_tmp_0++) {
                            poses->data[static_cast<int32_T>(static_cast<int32_T>
                                (static_cast<int32_T>(count +
                                tempMotionLength_data_tmp_0) +
                                 static_cast<int32_T>(poses->size[0] *
                                tempMotionLength_data_tmp)) - 1)] = ns->data[
                                static_cast<int32_T>(tempMotionLength_data_tmp_0
                                + static_cast<int32_T>(ns->size[0] *
                                tempMotionLength_data_tmp))];
                        }
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>
                            (count + tempMotionLength_data_tmp) - 1)] = ns->
                            data[tempMotionLength_data_tmp];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + poses->size[0]) - 1)] =
                            -ns->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + ns->size[0])];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + static_cast<int32_T>
                            (poses->size[0] << 1)) - 1)] = -ns->data[
                            static_cast<int32_T>(tempMotionLength_data_tmp +
                            static_cast<int32_T>(ns->size[0] << 1))];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + static_cast<int32_T>
                            (poses->size[0] * 3)) - 1)] = -ns->data
                            [static_cast<int32_T>(tempMotionLength_data_tmp +
                            static_cast<int32_T>(ns->size[0] * 3))];
                    }
                }

                count = ns->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <
                        6; tempMotionLength_data_tmp++) {
                    state[tempMotionLength_data_tmp] = ns->data
                        [static_cast<int32_T>(static_cast<int32_T>(count +
                        static_cast<int32_T>(ns->size[0] *
                        tempMotionLength_data_tmp)) - 1)];
                }

                startIndex += static_cast<real_T>(ab->size[1]);
            }

            intermediateLength += tempMotionLength_data[poses_0];
            poses_0 = static_cast<int32_T>(poses_0 + 1);
        }

        FlightMissionMode_emxFree_real_T_j(&S_0);
        FlightMissionMode_emxFree_boolean_T(&tempSamplesIndex_0);
        FlightMissionMode_emxFree_int32_T(&ab);
        FlightMissionMode_emxFree_real_T_j(&e_x);
        FlightMissionMode_emxFree_real_T_j(&p);
        FlightMissionMode_emxFree_real_T_j(&z);
        FlightMissionMode_emxFree_real_T_j(&ns);
        FlightMissionMode_emxFree_real_T_j(&S);
        FlightMissionMode_emxFree_boolean_T(&tempSamplesIndex);
        loop_ub = poses->size[0];
        tempMotionLength_data_tmp = tempSamples->size[0];
        tempSamples->size[0] = poses->size[0];
        FlightMissionMode_emxEnsureCapacity_real_T1(tempSamples,
            tempMotionLength_data_tmp);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp++)
        {
            tempSamples->data[tempMotionLength_data_tmp] = poses->data[
                static_cast<int32_T>(tempMotionLength_data_tmp +
                static_cast<int32_T>(poses->size[0] * 3))];
        }

        FlightMissionMode_wrapToPi(tempSamples);
        loop_ub = tempSamples->size[0];
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp++)
        {
            poses->data[static_cast<int32_T>(tempMotionLength_data_tmp +
                static_cast<int32_T>(poses->size[0] * 3))] = tempSamples->
                data[tempMotionLength_data_tmp];
        }

        FlightMissionMode_emxFree_real_T_j(&tempSamples);
    }
}

// Function for MATLAB Function: '<S161>/WayPointGenerator'
static void FlightMissionMode_genSegWP(const
    uavDubinsConnection_FlightMissionMode_T *connectionObj, const real_T start[4],
    const real_T ende[4], real_T numWPs, emxArray_real_T_FlightMissionMode_T
    *segWayPoints, DW_WayPointGenerator_FlightMissionMode_T *localDW)
{
    emxArray_real_T_FlightMissionMode_T *lengths;
    emxArray_real_T_FlightMissionMode_T *poses;
    real_T a__1_data[28];
    real_T apnd;
    real_T cdiff;
    real_T ndbl;
    real_T realStepSize;
    int32_T a__1_size;
    int32_T k;
    int32_T nm1d2;
    boolean_T guard1{ false };

    FlightMissionMode_uavDubinsConnection_connect(connectionObj, start, ende,
        localDW->pathSegObj.data, &localDW->pathSegObj.size, a__1_data,
        &a__1_size, localDW);
    realStepSize = localDW->pathSegObj.data[0].Length / numWPs;
    FlightMissionMode_emxInit_real_T_l(&lengths, 2);
    if (std::isnan(realStepSize)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_p(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
    } else if (std::isnan(localDW->pathSegObj.data[0].Length)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_p(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
    } else if (realStepSize == 0.0) {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else if ((0.0 < localDW->pathSegObj.data[0].Length) && (realStepSize < 0.0))
    {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else if ((localDW->pathSegObj.data[0].Length < 0.0) && (realStepSize > 0.0))
    {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else {
        guard1 = false;
        if (std::isinf(localDW->pathSegObj.data[0].Length)) {
            if (std::isinf(realStepSize)) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T_p(lengths, nm1d2);
                lengths->data[0] = (rtNaN);
            } else if (0.0 == localDW->pathSegObj.data[0].Length) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T_p(lengths, nm1d2);
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
                FlightMissionMode_emxEnsureCapacity_real_T_p(lengths, nm1d2);
                lengths->data[0] = 0.0;
            } else if (std::floor(realStepSize) == realStepSize) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                k = static_cast<int32_T>(std::floor(localDW->pathSegObj.data[0].
                    Length / realStepSize));
                lengths->size[1] = static_cast<int32_T>(k + 1);
                FlightMissionMode_emxEnsureCapacity_real_T_p(lengths, nm1d2);
                for (a__1_size = 0; a__1_size <= k; a__1_size++) {
                    lengths->data[a__1_size] = realStepSize * static_cast<real_T>
                        (a__1_size);
                }
            } else {
                ndbl = std::floor(localDW->pathSegObj.data[0].Length /
                                  realStepSize + 0.5);
                apnd = ndbl * realStepSize;
                if (realStepSize > 0.0) {
                    cdiff = apnd - localDW->pathSegObj.data[0].Length;
                } else {
                    cdiff = localDW->pathSegObj.data[0].Length - apnd;
                }

                if (std::abs(cdiff) < 4.4408920985006262E-16 * std::abs
                        (localDW->pathSegObj.data[0].Length)) {
                    ndbl++;
                    apnd = localDW->pathSegObj.data[0].Length;
                } else if (cdiff > 0.0) {
                    apnd = (ndbl - 1.0) * realStepSize;
                } else {
                    ndbl++;
                }

                if (ndbl >= 0.0) {
                    a__1_size = static_cast<int32_T>(static_cast<int32_T>(ndbl)
                        - 1);
                } else {
                    a__1_size = -1;
                }

                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = static_cast<int32_T>(a__1_size + 1);
                FlightMissionMode_emxEnsureCapacity_real_T_p(lengths, nm1d2);
                if (static_cast<int32_T>(a__1_size + 1) > 0) {
                    lengths->data[0] = 0.0;
                    if (static_cast<int32_T>(a__1_size + 1) > 1) {
                        lengths->data[a__1_size] = apnd;
                        nm1d2 = static_cast<int32_T>(a__1_size / 2);
                        for (k = 1; static_cast<int32_T>(k - 1) <=
                                static_cast<int32_T>(nm1d2 - 2); k =
                                static_cast<int32_T>(k + 1)) {
                            ndbl = static_cast<real_T>(k) * realStepSize;
                            lengths->data[k] = ndbl;
                            lengths->data[static_cast<int32_T>(a__1_size - k)] =
                                apnd - ndbl;
                        }

                        if (static_cast<int32_T>(nm1d2 << 1) == a__1_size) {
                            lengths->data[nm1d2] = apnd / 2.0;
                        } else {
                            ndbl = static_cast<real_T>(nm1d2) * realStepSize;
                            lengths->data[nm1d2] = ndbl;
                            lengths->data[static_cast<int32_T>(nm1d2 + 1)] =
                                apnd - ndbl;
                        }
                    }
                }
            }
        }
    }

    FlightMissionMode_emxInit_real_T_l(&poses, 2);
    FlightMissionMode_uavDubinsPathSegment_interpolate(localDW->pathSegObj.data
        [0].StartPose, localDW->pathSegObj.data[0].GoalPose,
        localDW->pathSegObj.data[0].FlightPathAngle, localDW->pathSegObj.data[0]
        .AirSpeed, localDW->pathSegObj.data[0].MinTurningRadius,
        localDW->pathSegObj.data[0].HelixRadius, localDW->pathSegObj.data[0].
        MotionTypes, localDW->pathSegObj.data[0].MotionLengths,
        localDW->pathSegObj.data[0].Length, lengths, poses);
    k = poses->size[0];
    nm1d2 = static_cast<int32_T>(segWayPoints->size[0] * segWayPoints->size[1]);
    segWayPoints->size[0] = poses->size[0];
    segWayPoints->size[1] = 3;
    FlightMissionMode_emxEnsureCapacity_real_T_p(segWayPoints, nm1d2);
    FlightMissionMode_emxFree_real_T_j(&lengths);
    for (a__1_size = 0; a__1_size < 3; a__1_size++) {
        for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(k - 1); nm1d2++) {
            segWayPoints->data[static_cast<int32_T>(nm1d2 + static_cast<int32_T>
                (segWayPoints->size[0] * a__1_size))] = poses->data
                [static_cast<int32_T>(nm1d2 + static_cast<int32_T>(poses->size[0]
                * a__1_size))];
        }
    }

    FlightMissionMode_emxFree_real_T_j(&poses);
}

//
// Output and update for atomic system:
//    '<S161>/WayPointGenerator'
//    '<S199>/WayPointGenerator'
//
void FlightMissionMode_WayPointGenerator(real_T rtu_Length, real_T rty_left[300],
    real_T rty_top[300], real_T rty_right[300], real_T rty_bottom[300], real_T
    rtp_numSegWP, DW_WayPointGenerator_FlightMissionMode_T *localDW)
{
    emxArray_real_T_FlightMissionMode_T *SegWP;
    uavDubinsConnection_FlightMissionMode_T connectionObj;
    real_T LDp[4];
    real_T LUp[4];
    real_T RDp[4];
    real_T RUp[4];
    real_T LDp_tmp;
    int32_T i;
    int32_T i_0;
    FlightMissionMode_emxInit_real_T_l(&SegWP, 2);
    connectionObj.FlightPathAngleLimit[0] = -0.175;
    connectionObj.FlightPathAngleLimit[1] = 0.175;
    connectionObj.MaxRollAngle = 0.3490658503988659;
    connectionObj.AirSpeed = 35.0;
    connectionObj.MinTurningRadius = 343.43467743182782;
    LUp[0] = 0.0;
    LUp[1] = rtu_Length / 2.0;
    LUp[2] = 0.0;
    LUp[3] = 1.5707963267948966;
    LDp[0] = 0.0;
    LDp_tmp = -rtu_Length / 2.0;
    LDp[1] = LDp_tmp;
    LDp[2] = 0.0;
    LDp[3] = 1.5707963267948966;
    RUp[0] = 686.86935486365564;
    RUp[1] = rtu_Length / 2.0;
    RUp[2] = 0.0;
    RUp[3] = -1.5707963267948966;
    RDp[0] = 686.86935486365564;
    RDp[1] = LDp_tmp;
    RDp[2] = 0.0;
    RDp[3] = -1.5707963267948966;
    FlightMissionMode_genSegWP(&connectionObj, LDp, LUp, rtp_numSegWP, SegWP,
        localDW);
    for (i_0 = 0; i_0 < 3; i_0++) {
        for (i = 0; i < 100; i++) {
            rty_left[static_cast<int32_T>(i + static_cast<int32_T>(100 * i_0))] =
                SegWP->data[static_cast<int32_T>(i + static_cast<int32_T>
                (SegWP->size[0] * i_0))];
        }
    }

    FlightMissionMode_genSegWP(&connectionObj, LUp, RUp, rtp_numSegWP, SegWP,
        localDW);
    for (i_0 = 0; i_0 < 3; i_0++) {
        for (i = 0; i < 100; i++) {
            rty_top[static_cast<int32_T>(i + static_cast<int32_T>(100 * i_0))] =
                SegWP->data[static_cast<int32_T>(i + static_cast<int32_T>
                (SegWP->size[0] * i_0))];
        }
    }

    FlightMissionMode_genSegWP(&connectionObj, RUp, RDp, rtp_numSegWP, SegWP,
        localDW);
    for (i_0 = 0; i_0 < 3; i_0++) {
        for (i = 0; i < 100; i++) {
            rty_right[static_cast<int32_T>(i + static_cast<int32_T>(100 * i_0))]
                = SegWP->data[static_cast<int32_T>(i + static_cast<int32_T>
                (SegWP->size[0] * i_0))];
        }
    }

    FlightMissionMode_genSegWP(&connectionObj, RDp, LDp, rtp_numSegWP, SegWP,
        localDW);
    for (i_0 = 0; i_0 < 3; i_0++) {
        for (i = 0; i < 100; i++) {
            rty_bottom[static_cast<int32_T>(i + static_cast<int32_T>(100 * i_0))]
                = SegWP->data[static_cast<int32_T>(i + static_cast<int32_T>
                (SegWP->size[0] * i_0))];
        }
    }

    FlightMissionMode_emxFree_real_T_j(&SegWP);
}

//
// Output and update for atomic system:
//    '<S161>/biasNEDstartpose'
//    '<S199>/biasNEDstartpose'
//
void FlightMissionMode_biasNEDstartpose(const real_T rtu_MissionNED[3], const
    real_T rtu_IndivRotWP[3], real_T rty_nedWayPoint[3])
{
    rty_nedWayPoint[0] = rtu_MissionNED[0] + rtu_IndivRotWP[1];
    rty_nedWayPoint[1] = rtu_IndivRotWP[0] + rtu_MissionNED[1];
    rty_nedWayPoint[2] = rtu_IndivRotWP[2] + rtu_MissionNED[2];
}

// Function for Chart: '<Root>/PreemptableMissionModeSelector'
static void FlightMissionMode_exit_internal_GuidanceLogic
    (DW_FlightMissionMode_f_T *localDW)
{
    localDW->PreemptableMissionModeSelectorMode = None;
    localDW->is_GuidanceLogic = FlightMissionMode_IN_NO_ACTIVE_CHILD;
}

static void FlightMissionMode_emxInit_real_T_h
    (emxArray_real_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_real_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_real_T_FlightMissionMode_T));
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

static void FlightMissionMode_emxFree_real_T_n
    (emxArray_real_T_FlightMissionMode_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_real_T_FlightMissionMode_T *)nullptr) {
        if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_real_T_FlightMissionMode_T *)nullptr;
    }
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static uavDubinsConnection_FlightMissionMode_T
    *FlightMissionMode_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_FlightMissionMode_T *b_this)
{
    uavDubinsConnection_FlightMissionMode_T *c_this;
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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
    *FlightMissionMode_NameValueParser_NameValueParser_p
    (matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
     *obj)
{
    static const char_T c[7]{ 'o', 'p', 't', 'i', 'm', 'a', 'l' };

    cell_wrap_12_FlightMissionMode_T b;
    matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
        *b_obj;
    int32_T i;
    b_obj = obj;
    for (i = 0; i < 7; i++) {
        b.f1[i] = c[i];
    }

    obj->Defaults = b;
    return b_obj;
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_validatestring_o(const char_T str[7], char_T
    out_data[], int32_T out_size[2])
{
    static const char_T c[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4(const char_T a_data[], const
    int32_T a_size[2])
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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_merge_a(int32_T idx_data[], int32_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T
    xwork_data[])
{
    int32_T exitg1;
    int32_T iout;
    int32_T n;
    int32_T n_tmp;
    int32_T q;
    if (nq != 0) {
        n_tmp = static_cast<int32_T>(np + nq);
        for (q = 0; q <= static_cast<int32_T>(n_tmp - 1); q =
                static_cast<int32_T>(q + 1)) {
            iout = static_cast<int32_T>(offset + q);
            iwork_data[q] = idx_data[iout];
            xwork_data[q] = x_data[iout];
        }

        n = 0;
        q = np;
        iout = static_cast<int32_T>(offset - 1);
        do {
            exitg1 = 0;
            iout = static_cast<int32_T>(iout + 1);
            if (xwork_data[n] <= xwork_data[q]) {
                idx_data[iout] = iwork_data[n];
                x_data[iout] = xwork_data[n];
                if (static_cast<int32_T>(n + 1) < np) {
                    n = static_cast<int32_T>(n + 1);
                } else {
                    exitg1 = 1;
                }
            } else {
                idx_data[iout] = iwork_data[q];
                x_data[iout] = xwork_data[q];
                if (static_cast<int32_T>(q + 1) < n_tmp) {
                    q = static_cast<int32_T>(q + 1);
                } else {
                    q = static_cast<int32_T>(iout - n);
                    while (static_cast<int32_T>(n + 1) <= np) {
                        iout = static_cast<int32_T>(static_cast<int32_T>(q + n)
                            + 1);
                        idx_data[iout] = iwork_data[n];
                        x_data[iout] = xwork_data[n];
                        n = static_cast<int32_T>(n + 1);
                    }

                    exitg1 = 1;
                }
            }
        } while (exitg1 == 0);
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_sort_o(int32_T x_data[], const int32_T *x_size,
    int32_T idx_data[], int32_T *idx_size)
{
    int32_T b_idx_data[28];
    int32_T b_x_data[28];
    int32_T iwork_data[28];
    int32_T vwork_data[28];
    int32_T x4[4];
    int32_T b;
    int32_T b_idx_tmp;
    int32_T dim;
    int32_T i3;
    int32_T i4;
    int32_T nLeft;
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
    nQuartets = 0;
    while (nQuartets <= static_cast<int32_T>(dim - 2)) {
        vstride = static_cast<int32_T>(vstride * *x_size);
        nQuartets = 1;
    }

    for (dim = 0; dim <= static_cast<int32_T>(vstride - 1); dim =
            static_cast<int32_T>(dim + 1)) {
        for (nQuartets = 0; nQuartets <= b; nQuartets = static_cast<int32_T>
                (nQuartets + 1)) {
            vwork_data[nQuartets] = x_data[static_cast<int32_T>
                (static_cast<int32_T>(nQuartets * vstride) + dim)];
        }

        nQuartets = static_cast<int32_T>(static_cast<int8_T>(vwork_size_idx_0));
        for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>(nQuartets - 1);
                b_idx_tmp++) {
            b_idx_data[b_idx_tmp] = 0;
        }

        if (vwork_size_idx_0 != 0) {
            for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>
                    (vwork_size_idx_0 - 1); b_idx_tmp++) {
                b_x_data[b_idx_tmp] = vwork_data[b_idx_tmp];
            }

            nQuartets = static_cast<int32_T>(static_cast<int8_T>
                (vwork_size_idx_0));
            for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>(nQuartets - 1);
                 b_idx_tmp++) {
                b_idx_data[b_idx_tmp] = 0;
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
            for (nLeft = 0; nLeft <= static_cast<int32_T>(nQuartets_tmp - 1);
                    nLeft = static_cast<int32_T>(nLeft + 1)) {
                tailOffset = static_cast<int32_T>(nLeft << 2);
                idx4[0] = static_cast<int8_T>(static_cast<int32_T>(tailOffset +
                    1));
                idx4[1] = static_cast<int8_T>(static_cast<int32_T>(tailOffset +
                    2));
                idx4[2] = static_cast<int8_T>(static_cast<int32_T>(tailOffset +
                    3));
                idx4[3] = static_cast<int8_T>(static_cast<int32_T>(tailOffset +
                    4));
                x4[0] = b_x_data[tailOffset];
                x4[1] = b_x_data[static_cast<int32_T>(tailOffset + 1)];
                x4[2] = b_x_data[static_cast<int32_T>(tailOffset + 2)];
                x4[3] = b_x_data[static_cast<int32_T>(tailOffset + 3)];
                if (b_x_data[tailOffset] <= b_x_data[static_cast<int32_T>
                        (tailOffset + 1)]) {
                    nTail = 1;
                    nQuartets = 2;
                } else {
                    nTail = 2;
                    nQuartets = 1;
                }

                if (b_x_data[static_cast<int32_T>(tailOffset + 2)] <= b_x_data[
                        static_cast<int32_T>(tailOffset + 3)]) {
                    i3 = 3;
                    i4 = 4;
                } else {
                    i3 = 4;
                    i4 = 3;
                }

                b_idx_tmp = x4[static_cast<int32_T>(nTail - 1)];
                tmp = x4[static_cast<int32_T>(i3 - 1)];
                if (b_idx_tmp <= tmp) {
                    b_idx_tmp = x4[static_cast<int32_T>(nQuartets - 1)];
                    if (b_idx_tmp <= tmp) {
                        perm[0] = static_cast<int8_T>(nTail);
                        perm[1] = static_cast<int8_T>(nQuartets);
                        perm[2] = static_cast<int8_T>(i3);
                        perm[3] = static_cast<int8_T>(i4);
                    } else if (b_idx_tmp <= x4[static_cast<int32_T>(i4 - 1)]) {
                        perm[0] = static_cast<int8_T>(nTail);
                        perm[1] = static_cast<int8_T>(i3);
                        perm[2] = static_cast<int8_T>(nQuartets);
                        perm[3] = static_cast<int8_T>(i4);
                    } else {
                        perm[0] = static_cast<int8_T>(nTail);
                        perm[1] = static_cast<int8_T>(i3);
                        perm[2] = static_cast<int8_T>(i4);
                        perm[3] = static_cast<int8_T>(nQuartets);
                    }
                } else {
                    tmp = x4[static_cast<int32_T>(i4 - 1)];
                    if (b_idx_tmp <= tmp) {
                        if (x4[static_cast<int32_T>(nQuartets - 1)] <= tmp) {
                            perm[0] = static_cast<int8_T>(i3);
                            perm[1] = static_cast<int8_T>(nTail);
                            perm[2] = static_cast<int8_T>(nQuartets);
                            perm[3] = static_cast<int8_T>(i4);
                        } else {
                            perm[0] = static_cast<int8_T>(i3);
                            perm[1] = static_cast<int8_T>(nTail);
                            perm[2] = static_cast<int8_T>(i4);
                            perm[3] = static_cast<int8_T>(nQuartets);
                        }
                    } else {
                        perm[0] = static_cast<int8_T>(i3);
                        perm[1] = static_cast<int8_T>(i4);
                        perm[2] = static_cast<int8_T>(nTail);
                        perm[3] = static_cast<int8_T>(nQuartets);
                    }
                }

                b_idx_data[tailOffset] = static_cast<int32_T>(idx4
                    [static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)]);
                b_idx_data[static_cast<int32_T>(tailOffset + 1)] =
                    static_cast<int32_T>(idx4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[1]) - 1)]);
                b_idx_data[static_cast<int32_T>(tailOffset + 2)] =
                    static_cast<int32_T>(idx4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[2]) - 1)]);
                b_idx_data[static_cast<int32_T>(tailOffset + 3)] =
                    static_cast<int32_T>(idx4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[3]) - 1)]);
                b_x_data[tailOffset] = x4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[0]) - 1)];
                b_x_data[static_cast<int32_T>(tailOffset + 1)] = x4[static_cast<
                    int32_T>(static_cast<int32_T>(perm[1]) - 1)];
                b_x_data[static_cast<int32_T>(tailOffset + 2)] = x4[static_cast<
                    int32_T>(static_cast<int32_T>(perm[2]) - 1)];
                b_x_data[static_cast<int32_T>(tailOffset + 3)] = x4[static_cast<
                    int32_T>(static_cast<int32_T>(perm[3]) - 1)];
            }

            nQuartets = static_cast<int32_T>(nQuartets_tmp << 2);
            nLeft = static_cast<int32_T>(vwork_size_idx_0 - nQuartets);
            if (nLeft > 0) {
                for (tailOffset = 0; tailOffset <= static_cast<int32_T>(nLeft -
                        1); tailOffset = static_cast<int32_T>(tailOffset + 1)) {
                    b_idx_tmp = static_cast<int32_T>(nQuartets + tailOffset);
                    idx4[tailOffset] = static_cast<int8_T>(static_cast<int32_T>
                        (b_idx_tmp + 1));
                    x4[tailOffset] = b_x_data[b_idx_tmp];
                }

                perm[1] = 0;
                perm[2] = 0;
                perm[3] = 0;
                switch (nLeft) {
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

                for (tailOffset = 0; tailOffset <= static_cast<int32_T>(nLeft -
                        1); tailOffset = static_cast<int32_T>(tailOffset + 1)) {
                    b_idx_tmp = static_cast<int32_T>(static_cast<int32_T>
                        (perm[tailOffset]) - 1);
                    nTail = static_cast<int32_T>(nQuartets + tailOffset);
                    b_idx_data[nTail] = static_cast<int32_T>(idx4[b_idx_tmp]);
                    b_x_data[nTail] = x4[b_idx_tmp];
                }
            }

            if (vwork_size_idx_0 > 1) {
                for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>
                        (vwork_size_idx_0 - 1); b_idx_tmp++) {
                    vwork_data[b_idx_tmp] = 0;
                }

                nQuartets = static_cast<int32_T>(static_cast<int8_T>
                    (vwork_size_idx_0));
                for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>(nQuartets
                        - 1); b_idx_tmp++) {
                    iwork_data[b_idx_tmp] = 0;
                }

                nLeft = nQuartets_tmp;
                nQuartets = 4;
                while (nLeft > 1) {
                    if (static_cast<uint32_T>(static_cast<uint32_T>(nLeft) & 1U)
                        != 0U) {
                        nLeft = static_cast<int32_T>(nLeft - 1);
                        tailOffset = static_cast<int32_T>(nQuartets * nLeft);
                        nTail = static_cast<int32_T>(vwork_size_idx_0 -
                            tailOffset);
                        if (nTail > nQuartets) {
                            FlightMissionMode_merge_a(b_idx_data, b_x_data,
                                tailOffset, nQuartets, static_cast<int32_T>
                                (nTail - nQuartets), iwork_data, vwork_data);
                        }
                    }

                    tailOffset = static_cast<int32_T>(nQuartets << 1);
                    nLeft = static_cast<int32_T>(nLeft >> 1);
                    for (nTail = 0; nTail <= static_cast<int32_T>(nLeft - 1);
                            nTail = static_cast<int32_T>(nTail + 1)) {
                        FlightMissionMode_merge_a(b_idx_data, b_x_data,
                            static_cast<int32_T>(nTail * tailOffset), nQuartets,
                            nQuartets, iwork_data, vwork_data);
                    }

                    nQuartets = tailOffset;
                }

                if (vwork_size_idx_0 > nQuartets) {
                    FlightMissionMode_merge_a(b_idx_data, b_x_data, 0, nQuartets,
                        static_cast<int32_T>(vwork_size_idx_0 - nQuartets),
                        iwork_data, vwork_data);
                }
            }

            for (b_idx_tmp = 0; b_idx_tmp <= static_cast<int32_T>
                    (vwork_size_idx_0 - 1); b_idx_tmp++) {
                vwork_data[b_idx_tmp] = b_x_data[b_idx_tmp];
            }
        }

        for (nQuartets = 0; nQuartets <= b; nQuartets = static_cast<int32_T>
                (nQuartets + 1)) {
            b_idx_tmp = static_cast<int32_T>(dim + static_cast<int32_T>
                (nQuartets * vstride));
            x_data[b_idx_tmp] = vwork_data[nQuartets];
            idx_data[b_idx_tmp] = b_idx_data[nQuartets];
        }
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_do_vectors_o(real_T c_data[], int32_T c_size[2],
    int32_T ia_data[], int32_T *ia_size, int32_T *ib_size)
{
    static const real_T a[28]{ 6.384265086E+9, 6.384265284E+9, 6.384480708E+9,
        6.384480906E+9, 6.384473283E+9, 6.384263997E+9, 2.1067690282E+11,
        2.10676902826E+11, 2.10677124976E+11, 2.10677124982E+11,
        2.10677124751E+11, 2.10676902787E+11, 2.10680747748E+11,
        2.10680754288E+11, 2.10687863274E+11, 2.10687869814E+11,
        2.10687618255E+11, 2.10680711811E+11, 6.384264226E+9, 6.384264232E+9,
        6.384264001E+9, 6.38447332E+9, 6.384473281E+9, 6.384473314E+9,
        6.384265282E+9, 6.384480904E+9, 6.38426509E+9, 6.384480712E+9 };

    static const int32_T aperm[28]{ 6, 21, 19, 20, 1, 27, 25, 2, 23, 5, 24, 22,
        3, 28, 26, 4, 12, 7, 8, 11, 9, 10, 18, 13, 14, 17, 15, 16 };

    static const int8_T e[28]{ 6, 21, 19, 20, 1, 27, 25, 2, 23, 5, 24, 22, 3, 28,
        26, 4, 12, 7, 8, 11, 9, 10, 18, 13, 14, 17, 15, 16 };

    emxArray_int32_T_28_FlightMissionMode_T ia_data_0;
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
    FlightMissionMode_sort_o(ia_data, ia_size, ia_data_0.data, &ia_data_0.size);
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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_do_vectors_o2(const real_T b_data[], const int32_T
    *b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[], int32_T
    *ia_size, int32_T *ib_size)
{
    emxArray_int32_T_28_FlightMissionMode_T ia_data_0;
    real_T tmp[28];
    real_T ak;
    real_T b_absx;
    real_T bk;
    int32_T bperm_data[28];
    int32_T iwork_data[28];
    int32_T b_k;
    int32_T c_k;
    int32_T i;
    int32_T i2;
    int32_T i_0;
    int32_T j;
    int32_T k;
    int32_T kEnd;
    int32_T n;
    int32_T pEnd;
    int32_T q;
    int32_T qEnd;
    int32_T tmp_0;
    boolean_T exitg1;
    c_size[0] = 1;
    *ib_size = 0;
    i = static_cast<int32_T>(static_cast<int8_T>(*b_size));
    for (i_0 = 0; i_0 <= static_cast<int32_T>(i - 1); i_0++) {
        bperm_data[i_0] = 0;
    }

    if (*b_size != 0) {
        for (i = 1; i <= static_cast<int32_T>(static_cast<int32_T>(*b_size + 1)
                - 2); i = static_cast<int32_T>(i + 2)) {
            if (b_data[static_cast<int32_T>(i - 1)] <= b_data[i]) {
                bperm_data[static_cast<int32_T>(i - 1)] = i;
                bperm_data[i] = static_cast<int32_T>(i + 1);
            } else {
                bperm_data[static_cast<int32_T>(i - 1)] = static_cast<int32_T>(i
                    + 1);
                bperm_data[i] = i;
            }
        }

        if (static_cast<uint32_T>(static_cast<uint32_T>(*b_size) & 1U) != 0U) {
            bperm_data[static_cast<int32_T>(*b_size - 1)] = *b_size;
        }

        i = 2;
        while (i < static_cast<int32_T>(static_cast<int32_T>(*b_size + 1) - 1))
        {
            i2 = static_cast<int32_T>(i << 1);
            j = 1;
            pEnd = static_cast<int32_T>(i + 1);
            while (pEnd < static_cast<int32_T>(*b_size + 1)) {
                n = j;
                q = pEnd;
                qEnd = static_cast<int32_T>(j + i2);
                if (qEnd > static_cast<int32_T>(*b_size + 1)) {
                    qEnd = static_cast<int32_T>(*b_size + 1);
                }

                c_k = 0;
                kEnd = static_cast<int32_T>(qEnd - j);
                while (static_cast<int32_T>(c_k + 1) <= kEnd) {
                    i_0 = bperm_data[static_cast<int32_T>(q - 1)];
                    tmp_0 = bperm_data[static_cast<int32_T>(n - 1)];
                    if (b_data[static_cast<int32_T>(tmp_0 - 1)] <= b_data[
                            static_cast<int32_T>(i_0 - 1)]) {
                        iwork_data[c_k] = tmp_0;
                        n = static_cast<int32_T>(n + 1);
                        if (n == pEnd) {
                            while (q < qEnd) {
                                c_k = static_cast<int32_T>(c_k + 1);
                                iwork_data[c_k] = bperm_data[static_cast<int32_T>
                                    (q - 1)];
                                q = static_cast<int32_T>(q + 1);
                            }
                        }
                    } else {
                        iwork_data[c_k] = i_0;
                        q = static_cast<int32_T>(q + 1);
                        if (q == qEnd) {
                            while (n < pEnd) {
                                c_k = static_cast<int32_T>(c_k + 1);
                                iwork_data[c_k] = bperm_data[static_cast<int32_T>
                                    (n - 1)];
                                n = static_cast<int32_T>(n + 1);
                            }
                        }
                    }

                    c_k = static_cast<int32_T>(c_k + 1);
                }

                for (pEnd = 0; pEnd <= static_cast<int32_T>(kEnd - 1); pEnd =
                        static_cast<int32_T>(pEnd + 1)) {
                    bperm_data[static_cast<int32_T>(static_cast<int32_T>(j +
                        pEnd) - 1)] = iwork_data[pEnd];
                }

                j = qEnd;
                pEnd = static_cast<int32_T>(qEnd + i);
            }

            i = i2;
        }
    }

    n = 0;
    i = -1;
    i2 = 0;
    j = 1;
    qEnd = 1;
    while ((j <= 28) && (qEnd <= *b_size)) {
        kEnd = j;
        for (i_0 = 0; i_0 < 28; i_0++) {
            tmp[i_0] = static_cast<real_T>(i_0) + 1.0;
            iwork_data[i_0] = static_cast<int32_T>(i_0 + 1);
        }

        ak = skip_to_last_equal_value_ZlLNIyBv(&kEnd, tmp, iwork_data);
        j = kEnd;
        pEnd = qEnd;
        bk = b_data[static_cast<int32_T>(bperm_data[static_cast<int32_T>(qEnd -
            1)] - 1)];
        exitg1 = false;
        while ((!exitg1) && (pEnd < *b_size)) {
            b_absx = std::abs(bk / 2.0);
            if (b_absx <= 2.2250738585072014E-308) {
                b_absx = 4.94065645841247E-324;
            } else {
                frexp(b_absx, &b_k);
                b_absx = std::ldexp(1.0, static_cast<int32_T>(b_k - 53));
            }

            if (std::abs(bk - b_data[static_cast<int32_T>(bperm_data[pEnd] - 1)])
                < b_absx) {
                pEnd = static_cast<int32_T>(pEnd + 1);
            } else {
                exitg1 = true;
            }
        }

        qEnd = pEnd;
        b_absx = std::abs(bk / 2.0);
        if (b_absx <= 2.2250738585072014E-308) {
            b_absx = 4.94065645841247E-324;
        } else {
            frexp(b_absx, &k);
            b_absx = std::ldexp(1.0, static_cast<int32_T>(k - 53));
        }

        if (std::abs(bk - ak) < b_absx) {
            j = static_cast<int32_T>(kEnd + 1);
            i2 = kEnd;
            qEnd = static_cast<int32_T>(pEnd + 1);
        } else if (ak < bk) {
            n = static_cast<int32_T>(n + 1);
            i = static_cast<int32_T>(i + 1);
            ia_data[i] = static_cast<int32_T>(i2 + 1);
            j = static_cast<int32_T>(kEnd + 1);
            i2 = kEnd;
        } else {
            qEnd = static_cast<int32_T>(pEnd + 1);
        }
    }

    while (j <= 28) {
        b_k = j;
        for (i_0 = 0; i_0 < 28; i_0++) {
            tmp[i_0] = static_cast<real_T>(i_0) + 1.0;
            iwork_data[i_0] = static_cast<int32_T>(i_0 + 1);
        }

        skip_to_last_equal_value_ZlLNIyBv(&b_k, tmp, iwork_data);
        n = static_cast<int32_T>(n + 1);
        i = static_cast<int32_T>(i + 1);
        ia_data[i] = static_cast<int32_T>(i2 + 1);
        j = static_cast<int32_T>(b_k + 1);
        i2 = b_k;
    }

    if (1 > static_cast<int32_T>(i + 1)) {
        i2 = -1;
    } else {
        i2 = i;
    }

    *ia_size = static_cast<int32_T>(i2 + 1);
    FlightMissionMode_sort_o(ia_data, ia_size, ia_data_0.data, &ia_data_0.size);
    for (b_k = 0; b_k <= i; b_k = static_cast<int32_T>(b_k + 1)) {
        c_data[b_k] = static_cast<real_T>(static_cast<int32_T>(ia_data[b_k] - 1))
            + 1.0;
    }

    if (1 > n) {
        c_size[1] = 0;
    } else {
        c_size[1] = n;
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_merge_a5(int32_T idx_data[], real_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
    xwork_data[])
{
    int32_T exitg1;
    int32_T iout;
    int32_T n;
    int32_T n_tmp;
    int32_T q;
    if (nq != 0) {
        n_tmp = static_cast<int32_T>(np + nq);
        for (q = 0; q <= static_cast<int32_T>(n_tmp - 1); q =
                static_cast<int32_T>(q + 1)) {
            iout = static_cast<int32_T>(offset + q);
            iwork_data[q] = idx_data[iout];
            xwork_data[q] = x_data[iout];
        }

        n = 0;
        q = np;
        iout = static_cast<int32_T>(offset - 1);
        do {
            exitg1 = 0;
            iout = static_cast<int32_T>(iout + 1);
            if (xwork_data[n] <= xwork_data[q]) {
                idx_data[iout] = iwork_data[n];
                x_data[iout] = xwork_data[n];
                if (static_cast<int32_T>(n + 1) < np) {
                    n = static_cast<int32_T>(n + 1);
                } else {
                    exitg1 = 1;
                }
            } else {
                idx_data[iout] = iwork_data[q];
                x_data[iout] = xwork_data[q];
                if (static_cast<int32_T>(q + 1) < n_tmp) {
                    q = static_cast<int32_T>(q + 1);
                } else {
                    q = static_cast<int32_T>(iout - n);
                    while (static_cast<int32_T>(n + 1) <= np) {
                        iout = static_cast<int32_T>(static_cast<int32_T>(q + n)
                            + 1);
                        idx_data[iout] = iwork_data[n];
                        x_data[iout] = xwork_data[n];
                        n = static_cast<int32_T>(n + 1);
                    }

                    exitg1 = 1;
                }
            }
        } while (exitg1 == 0);
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_sortIdx_i(real_T x_data[], int32_T *x_size,
    int32_T idx_data[], int32_T *idx_size)
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
    ib = static_cast<int32_T>(static_cast<int8_T>(*x_size));
    for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
        idx_data[n] = 0;
    }

    if (*x_size != 0) {
        b_x_size = *x_size;
        ib = *x_size;
        for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
            b_x_data[n] = x_data[n];
        }

        *idx_size = static_cast<int32_T>(static_cast<int8_T>(*x_size));
        ib = static_cast<int32_T>(static_cast<int8_T>(*x_size));
        for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
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
            idx4[static_cast<int32_T>(ib - 1)] = static_cast<int8_T>(
                static_cast<int32_T>(nPairs + 1));
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

                idx_data[static_cast<int32_T>(nPairs - 3)] = static_cast<int32_T>
                    (idx4[static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)]);
                idx_data[static_cast<int32_T>(nPairs - 2)] = static_cast<int32_T>
                    (idx4[static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)]);
                idx_data[static_cast<int32_T>(nPairs - 1)] = static_cast<int32_T>
                    (idx4[static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)]);
                idx_data[nPairs] = static_cast<int32_T>(idx4[static_cast<int32_T>
                    (static_cast<int32_T>(perm[3]) - 1)]);
                b_x_data[static_cast<int32_T>(nPairs - 3)] = x4
                    [static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)];
                b_x_data[static_cast<int32_T>(nPairs - 2)] = x4
                    [static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)];
                b_x_data[static_cast<int32_T>(nPairs - 1)] = x4
                    [static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)];
                b_x_data[nPairs] = x4[static_cast<int32_T>(static_cast<int32_T>
                    (perm[3]) - 1)];
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
                nTail = static_cast<int32_T>(static_cast<int32_T>(perm[nPairs])
                    - 1);
                n = static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int32_T>(*x_size - 1) - ib)
                     + nPairs) + 1);
                idx_data[n] = static_cast<int32_T>(idx4[nTail]);
                b_x_data[n] = x4[nTail];
            }
        }

        if (*x_size > 1) {
            ib = *x_size;
            for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
                xwork_data[n] = 0.0;
            }

            ib = static_cast<int32_T>(static_cast<int8_T>(*x_size));
            for (n = 0; n <= static_cast<int32_T>(ib - 1); n++) {
                iwork_data[n] = 0;
            }

            nPairs = static_cast<int32_T>(*x_size >> 2);
            n = 4;
            while (nPairs > 1) {
                if (static_cast<uint32_T>(static_cast<uint32_T>(nPairs) & 1U) !=
                    0U) {
                    nPairs = static_cast<int32_T>(nPairs - 1);
                    ib = static_cast<int32_T>(n * nPairs);
                    nTail = static_cast<int32_T>(*x_size - ib);
                    if (nTail > n) {
                        FlightMissionMode_merge_a5(idx_data, b_x_data, ib, n,
                            static_cast<int32_T>(nTail - n), iwork_data,
                            xwork_data);
                    }
                }

                ib = static_cast<int32_T>(n << 1);
                nPairs = static_cast<int32_T>(nPairs >> 1);
                for (nTail = 0; nTail <= static_cast<int32_T>(nPairs - 1); nTail
                     = static_cast<int32_T>(nTail + 1)) {
                    FlightMissionMode_merge_a5(idx_data, b_x_data,
                        static_cast<int32_T>(nTail * ib), n, n, iwork_data,
                        xwork_data);
                }

                n = ib;
            }

            if (*x_size > n) {
                FlightMissionMode_merge_a5(idx_data, b_x_data, 0, n,
                    static_cast<int32_T>(*x_size - n), iwork_data, xwork_data);
            }
        }

        for (n = 0; n <= static_cast<int32_T>(b_x_size - 1); n++) {
            x_data[n] = b_x_data[n];
        }
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_sort_o4(real_T x_data[], const int32_T *x_size)
{
    emxArray_int32_T_28_FlightMissionMode_T vwork_data_0;
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

    for (dim = 0; dim <= static_cast<int32_T>(vstride - 1); dim = static_cast<
            int32_T>(dim + 1)) {
        for (c_k = 0; c_k <= b; c_k = static_cast<int32_T>(c_k + 1)) {
            vwork_data[c_k] = x_data[static_cast<int32_T>(static_cast<int32_T>
                (c_k * vstride) + dim)];
        }

        FlightMissionMode_sortIdx_i(vwork_data, &vwork_size, vwork_data_0.data,
            &vwork_data_0.size);
        for (c_k = 0; c_k <= b; c_k = static_cast<int32_T>(c_k + 1)) {
            x_data[static_cast<int32_T>(dim + static_cast<int32_T>(c_k * vstride))]
                = vwork_data[c_k];
        }
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_uavDubinsConnection_findDisabledIndices_i(real_T
    idx_data[], int32_T *idx_size)
{
    real_T c_data[28];
    real_T ia_data_0[28];
    int32_T ia_data[28];
    int32_T c_size[2];
    int32_T ia_size;
    int32_T ia_size_0;
    int32_T ib_size;
    FlightMissionMode_do_vectors_o(c_data, c_size, ia_data, &ia_size, &ib_size);
    ia_size_0 = ia_size;
    for (ib_size = 0; ib_size <= static_cast<int32_T>(ia_size - 1); ib_size++) {
        ia_data_0[ib_size] = static_cast<real_T>(ia_data[ib_size]);
    }

    FlightMissionMode_do_vectors_o2(ia_data_0, &ia_size_0, c_data, c_size,
        ia_data, &ia_size, &ib_size);
    *idx_size = ia_size;
    for (ib_size = 0; ib_size <= static_cast<int32_T>(ia_size - 1); ib_size++) {
        idx_data[ib_size] = static_cast<real_T>(ia_data[ib_size]);
    }

    FlightMissionMode_sort_o4(idx_data, idx_size);
    for (ib_size = 0; ib_size <= static_cast<int32_T>(*idx_size - 1); ib_size++)
    {
        idx_data[ib_size]--;
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void* FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable_o(real_T
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
        &b_disabledPathTypes_data[0], static_cast<uint32_T>
        (*disabledPathTypes_size));
}

static void FlightMissionMode_emxEnsureCapacity_real_T_c
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4q(const char_T a_data[], const
    int32_T a_size[2])
{
    static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

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
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(a_data[kstr]))
                                           & 127)] != b[static_cast<int32_T>
                        (c[kstr])]) {
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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4qz(const char_T a_data[], const
    int32_T a_size[2])
{
    static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
        'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

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
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(a_data[kstr]))
                                           & 127)] != b[static_cast<int32_T>
                        (c[kstr])]) {
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

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_ll(const
    real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
    varargin_4, real_T varargin_5, real_T varargin_6, const
    cell_wrap_1_FlightMissionMode_T varargin_7[4], const real_T varargin_8[4],
    uavDubinsPathSegment_FlightMissionMode_b_T *b_this)
{
    static const char_T d[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
        'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
        'Z', '[', '\\', ']', '^', '_', '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z', '{', '|', '}', '~', '\x7f' };

    real_T thetaWrap;
    int32_T k;
    b_this->MinTurningRadius = varargin_5;
    b_this->StartPose[0] = varargin_1[0];
    b_this->StartPose[1] = varargin_1[1];
    b_this->StartPose[2] = varargin_1[2];
    thetaWrap = mod_dBqh4Vat(varargin_1[3]);
    b_this->StartPose[3] = thetaWrap;
    if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
            (varargin_1[3] > 0.0)))) {
        b_this->StartPose[3] = 6.2831853071795862;
    }

    wrapToPi_iEuDNbvh(&b_this->StartPose[3]);
    b_this->GoalPose[0] = varargin_2[0];
    b_this->GoalPose[1] = varargin_2[1];
    b_this->GoalPose[2] = varargin_2[2];
    thetaWrap = mod_dBqh4Vat(varargin_2[3]);
    b_this->GoalPose[3] = thetaWrap;
    if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
            (varargin_2[3] > 0.0)))) {
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
    b_this->MotionTypes[1].f1.data[0] = d[static_cast<int32_T>
        (static_cast<int32_T>(static_cast<uint8_T>(varargin_7[1].f1.data[0])) &
         127)];
    b_this->MotionTypes[2].f1.size[0] = 1;
    b_this->MotionTypes[2].f1.size[1] = 1;
    b_this->MotionTypes[2].f1.data[0] = d[static_cast<int32_T>
        (static_cast<int32_T>(static_cast<uint8_T>(varargin_7[2].f1.data[0])) &
         127)];
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = varargin_7[3].f1.size[1];
    for (k = 0; k <= static_cast<int32_T>(varargin_7[3].f1.size[1] - 1); k =
            static_cast<int32_T>(k + 1)) {
        b_this->MotionTypes[3].f1.data[k] = d[static_cast<int32_T>
            (static_cast<uint8_T>(varargin_7[3].f1.data[k]))];
    }

    if (FlightMissionMode_strcmp_k4q(b_this->MotionTypes[0].f1.data,
            b_this->MotionTypes[0].f1.size)) {
        b_this->MotionTypes[0].f1.size[0] = 1;
        b_this->MotionTypes[0].f1.size[1] = 2;
        b_this->MotionTypes[0].f1.data[0] = 'H';
        b_this->MotionTypes[0].f1.data[1] = 'l';
    } else if (FlightMissionMode_strcmp_k4qz(b_this->MotionTypes[0].f1.data,
                b_this->MotionTypes[0].f1.size)) {
        b_this->MotionTypes[0].f1.size[0] = 1;
        b_this->MotionTypes[0].f1.size[1] = 2;
        b_this->MotionTypes[0].f1.data[0] = 'H';
        b_this->MotionTypes[0].f1.data[1] = 'r';
    } else if (FlightMissionMode_strcmp_k4qz(b_this->MotionTypes[3].f1.data,
                b_this->MotionTypes[3].f1.size)) {
        b_this->MotionTypes[3].f1.size[0] = 1;
        b_this->MotionTypes[3].f1.size[1] = 2;
        b_this->MotionTypes[3].f1.data[0] = 'H';
        b_this->MotionTypes[3].f1.data[1] = 'r';
    } else if (FlightMissionMode_strcmp_k4q(b_this->MotionTypes[3].f1.data,
                b_this->MotionTypes[3].f1.size)) {
        b_this->MotionTypes[3].f1.size[0] = 1;
        b_this->MotionTypes[3].f1.size[1] = 2;
        b_this->MotionTypes[3].f1.data[0] = 'H';
        b_this->MotionTypes[3].f1.data[1] = 'l';
    }

    b_this->Length = ((varargin_8[0] + varargin_8[1]) + varargin_8[2]) +
        varargin_8[3];
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static real_T FlightMissionMode_sum_l(const real_T x_data[])
{
    return ((x_data[0] + x_data[1]) + x_data[2]) + x_data[3];
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_uavDubinsBuiltins_connect_fo(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPose[4],
    const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
    real_T dpt_data[], const int32_T *dpt_size,
    uavDubinsPathSegment_FlightMissionMode_b_T pathSegObjs_data[], int32_T
    *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
    DW_FlightMissionMode_f_T *localDW)
{
    void* buildableObj_UAVDubinsBuildableObj;
    cell_wrap_1_FlightMissionMode_T m[4];
    cell_wrap_1_FlightMissionMode_T ac;
    cell_wrap_1_FlightMissionMode_T ad;
    cell_wrap_1_FlightMissionMode_T ae;
    cell_wrap_1_FlightMissionMode_T af;
    cell_wrap_1_FlightMissionMode_T bc;
    cell_wrap_1_FlightMissionMode_T bd;
    cell_wrap_1_FlightMissionMode_T be;
    cell_wrap_1_FlightMissionMode_T bf;
    cell_wrap_1_FlightMissionMode_T cc;
    cell_wrap_1_FlightMissionMode_T cd;
    cell_wrap_1_FlightMissionMode_T ce;
    cell_wrap_1_FlightMissionMode_T cf;
    cell_wrap_1_FlightMissionMode_T dc;
    cell_wrap_1_FlightMissionMode_T dd;
    cell_wrap_1_FlightMissionMode_T de;
    cell_wrap_1_FlightMissionMode_T df;
    cell_wrap_1_FlightMissionMode_T ec;
    cell_wrap_1_FlightMissionMode_T ed;
    cell_wrap_1_FlightMissionMode_T ee;
    cell_wrap_1_FlightMissionMode_T ef;
    cell_wrap_1_FlightMissionMode_T fc;
    cell_wrap_1_FlightMissionMode_T fd;
    cell_wrap_1_FlightMissionMode_T fe;
    cell_wrap_1_FlightMissionMode_T ff;
    cell_wrap_1_FlightMissionMode_T gc;
    cell_wrap_1_FlightMissionMode_T gd;
    cell_wrap_1_FlightMissionMode_T ge;
    cell_wrap_1_FlightMissionMode_T gf;
    cell_wrap_1_FlightMissionMode_T hc;
    cell_wrap_1_FlightMissionMode_T hd;
    cell_wrap_1_FlightMissionMode_T he;
    cell_wrap_1_FlightMissionMode_T hf;
    cell_wrap_1_FlightMissionMode_T ic;
    cell_wrap_1_FlightMissionMode_T id;
    cell_wrap_1_FlightMissionMode_T ie;
    cell_wrap_1_FlightMissionMode_T jc;
    cell_wrap_1_FlightMissionMode_T jd;
    cell_wrap_1_FlightMissionMode_T je;
    cell_wrap_1_FlightMissionMode_T jf;
    cell_wrap_1_FlightMissionMode_T kb;
    cell_wrap_1_FlightMissionMode_T kc;
    cell_wrap_1_FlightMissionMode_T kd;
    cell_wrap_1_FlightMissionMode_T ke;
    cell_wrap_1_FlightMissionMode_T kf;
    cell_wrap_1_FlightMissionMode_T lb;
    cell_wrap_1_FlightMissionMode_T lc;
    cell_wrap_1_FlightMissionMode_T ld;
    cell_wrap_1_FlightMissionMode_T le;
    cell_wrap_1_FlightMissionMode_T lf;
    cell_wrap_1_FlightMissionMode_T mb;
    cell_wrap_1_FlightMissionMode_T mc;
    cell_wrap_1_FlightMissionMode_T md;
    cell_wrap_1_FlightMissionMode_T me;
    cell_wrap_1_FlightMissionMode_T mf;
    cell_wrap_1_FlightMissionMode_T nb;
    cell_wrap_1_FlightMissionMode_T nc;
    cell_wrap_1_FlightMissionMode_T nd;
    cell_wrap_1_FlightMissionMode_T ne;
    cell_wrap_1_FlightMissionMode_T nf;
    cell_wrap_1_FlightMissionMode_T ob;
    cell_wrap_1_FlightMissionMode_T oc;
    cell_wrap_1_FlightMissionMode_T od;
    cell_wrap_1_FlightMissionMode_T oe;
    cell_wrap_1_FlightMissionMode_T of;
    cell_wrap_1_FlightMissionMode_T pb;
    cell_wrap_1_FlightMissionMode_T pc;
    cell_wrap_1_FlightMissionMode_T pd;
    cell_wrap_1_FlightMissionMode_T pe;
    cell_wrap_1_FlightMissionMode_T pf;
    cell_wrap_1_FlightMissionMode_T qb;
    cell_wrap_1_FlightMissionMode_T qc;
    cell_wrap_1_FlightMissionMode_T qd;
    cell_wrap_1_FlightMissionMode_T qe;
    cell_wrap_1_FlightMissionMode_T qf;
    cell_wrap_1_FlightMissionMode_T rb;
    cell_wrap_1_FlightMissionMode_T rc;
    cell_wrap_1_FlightMissionMode_T rd;
    cell_wrap_1_FlightMissionMode_T re;
    cell_wrap_1_FlightMissionMode_T rf;
    cell_wrap_1_FlightMissionMode_T sb;
    cell_wrap_1_FlightMissionMode_T sc;
    cell_wrap_1_FlightMissionMode_T sd;
    cell_wrap_1_FlightMissionMode_T se;
    cell_wrap_1_FlightMissionMode_T sf;
    cell_wrap_1_FlightMissionMode_T tb;
    cell_wrap_1_FlightMissionMode_T tc;
    cell_wrap_1_FlightMissionMode_T td;
    cell_wrap_1_FlightMissionMode_T te;
    cell_wrap_1_FlightMissionMode_T tf;
    cell_wrap_1_FlightMissionMode_T ub;
    cell_wrap_1_FlightMissionMode_T uc;
    cell_wrap_1_FlightMissionMode_T ud;
    cell_wrap_1_FlightMissionMode_T ue;
    cell_wrap_1_FlightMissionMode_T uf;
    cell_wrap_1_FlightMissionMode_T vb;
    cell_wrap_1_FlightMissionMode_T vc;
    cell_wrap_1_FlightMissionMode_T vd;
    cell_wrap_1_FlightMissionMode_T ve;
    cell_wrap_1_FlightMissionMode_T vf;
    cell_wrap_1_FlightMissionMode_T wb;
    cell_wrap_1_FlightMissionMode_T wc;
    cell_wrap_1_FlightMissionMode_T wd;
    cell_wrap_1_FlightMissionMode_T we;
    cell_wrap_1_FlightMissionMode_T wf;
    cell_wrap_1_FlightMissionMode_T xb;
    cell_wrap_1_FlightMissionMode_T xc;
    cell_wrap_1_FlightMissionMode_T xd;
    cell_wrap_1_FlightMissionMode_T xe;
    cell_wrap_1_FlightMissionMode_T yb;
    cell_wrap_1_FlightMissionMode_T yc;
    cell_wrap_1_FlightMissionMode_T yd;
    cell_wrap_1_FlightMissionMode_T ye;
    emxArray_real_T_FlightMissionMode_T *g;
    emxArray_real_T_FlightMissionMode_T *g1;
    emxArray_real_T_FlightMissionMode_T *g_0;
    emxArray_real_T_FlightMissionMode_T *ml;
    emxArray_real_T_FlightMissionMode_T *ml1;
    emxArray_real_T_FlightMissionMode_T *s;
    emxArray_real_T_FlightMissionMode_T *s1;
    real_T b_goalPose[4];
    real_T b_startPose[4];
    real_T ml1_0[4];
    real_T ml1_data[4];
    real_T l;
    real_T ml1_tmp;
    int32_T b_nRows;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
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
        FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable_o(obj->AirSpeed,
        obj->MaxRollAngle, obj->FlightPathAngleLimit, dpt_data, dpt_size);
    b_startPose[0] = startPose[0];
    b_goalPose[0] = goalPose[0];
    b_startPose[1] = startPose[1];
    b_goalPose[1] = goalPose[1];
    b_startPose[2] = startPose[2];
    b_goalPose[2] = goalPose[2];
    b_startPose[3] = startPose[3];
    b_goalPose[3] = goalPose[3];
    b_nRows = 1;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (flagOptimal) ^ 1))) {
        b_nRows = 28;
    }

    FlightMissionMode_emxInit_real_T_h(&s, 2);
    FlightMissionMode_emxInit_real_T_h(&g, 2);
    FlightMissionMode_emxInit_real_T_h(&ml, 2);
    xf_tmp = static_cast<int32_T>(b_nRows << 2);
    loop_ub_tmp = static_cast<int32_T>(s->size[0] * s->size[1]);
    s->size[0] = xf_tmp;
    s->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_c(s, loop_ub_tmp);
    loop_ub_tmp = static_cast<int32_T>(g->size[0] * g->size[1]);
    g->size[0] = xf_tmp;
    g->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g, loop_ub_tmp);
    mt_size_idx_0 = b_nRows;
    loop_ub_tmp = static_cast<int32_T>(ml->size[0] * ml->size[1]);
    ml->size[0] = xf_tmp;
    ml->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_c(ml, loop_ub_tmp);
    uavDubinsDistanceCodegen_real64(buildableObj_UAVDubinsBuildableObj,
        &b_startPose[0], 1U, &b_goalPose[0], 1U, flagOptimal, turningRadius,
        &s->data[0], &g->data[0], &localDW->b_fpa_data_m[0],
        &localDW->b_a_data_n[0], &localDW->mtr_data_p[0], &localDW->h_data_l[0],
        &localDW->mt_data_g[0], &ml->data[0]);
    b_nRows = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (flagOptimal) ^ 1))) {
        b_nRows = 27;
    }

    FlightMissionMode_emxInit_real_T_h(&g1, 2);
    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(s->size[0] * s->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g1->size[0] * g1->size[1]);
    g1->size[0] = static_cast<int32_T>(num_idx_1);
    g1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g1->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g1->size[0] * xf_tmp))] = s->data[static_cast<int32_T>(xf_tmp +
                static_cast<int32_T>(static_cast<int32_T>(tmp[0]) * loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_n(&s);
    FlightMissionMode_emxInit_real_T_h(&s1, 2);
    loop_ub_tmp = static_cast<int32_T>(s1->size[0] * s1->size[1]);
    s1->size[0] = static_cast<int32_T>(num_idx_1);
    s1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(s1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
        s1->data[xf_tmp] = g1->data[xf_tmp];
    }

    FlightMissionMode_emxInit_real_T_h(&g_0, 2);
    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(g->size[0] * g->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
    g_0->size[0] = static_cast<int32_T>(num_idx_1);
    g_0->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g_0, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g_0->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g_0->size[0] * xf_tmp))] = g->data[static_cast<int32_T>(xf_tmp
                + static_cast<int32_T>(static_cast<int32_T>(tmp[0]) *
                loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_n(&g);
    loop_ub_tmp = static_cast<int32_T>(g1->size[0] * g1->size[1]);
    g1->size[0] = static_cast<int32_T>(num_idx_1);
    g1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
        g1->data[xf_tmp] = g_0->data[xf_tmp];
    }

    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(ml->size[0] * ml->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
    g_0->size[0] = static_cast<int32_T>(num_idx_1);
    g_0->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g_0, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g_0->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g_0->size[0] * xf_tmp))] = ml->data[static_cast<int32_T>(xf_tmp
                + static_cast<int32_T>(static_cast<int32_T>(tmp[0]) *
                loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_n(&ml);
    FlightMissionMode_emxInit_real_T_h(&ml1, 2);
    loop_ub_tmp = static_cast<int32_T>(ml1->size[0] * ml1->size[1]);
    ml1->size[0] = static_cast<int32_T>(num_idx_1);
    ml1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(ml1, loop_ub_tmp);
    loop_ub_tmp = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub_tmp - 1); xf_tmp++)
    {
        ml1->data[xf_tmp] = g_0->data[xf_tmp];
    }

    FlightMissionMode_emxFree_real_T_n(&g_0);
    loop_ub_tmp = static_cast<int32_T>(mt_size_idx_0 * mt_size_idx_0);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub_tmp - 1); xf_tmp++)
    {
        localDW->mt_data_g[xf_tmp]++;
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
        *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>(
            static_cast<int32_T>(b_nRows + 1)));
        for (loop_ub_tmp = 0; loop_ub_tmp <= b_nRows; loop_ub_tmp = static_cast<
                int32_T>(loop_ub_tmp + 1)) {
            l++;
            ml1_tmp = localDW->mt_data_g[static_cast<int32_T>
                (static_cast<int32_T>(l) - 1)];
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

            b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>
                (l) - 1)];
            b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l)
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
            ml1_0[0] = ml1_tmp;
            ml1_data[0] = ml1_tmp;
            b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + s1->size[0]) - 1)];
            b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + g1->size[0]) - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + ml1->size[0]) - 1)];
            ml1_0[1] = ml1_tmp;
            ml1_data[1] = ml1_tmp;
            b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1))
                - 1)];
            b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1))
                - 1)];
            ml1_0[2] = ml1_tmp;
            ml1_data[2] = ml1_tmp;
            b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3))
                - 1)];
            b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3))
                - 1)];
            ml1_0[3] = ml1_tmp;
            ml1_data[3] = ml1_tmp;
            FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_ll
                (b_startPose, b_goalPose, localDW->b_fpa_data_m
                 [static_cast<int32_T>(static_cast<int32_T>(l) - 1)],
                 localDW->b_a_data_n[0], localDW->mtr_data_p[0],
                 localDW->h_data_l[static_cast<int32_T>(static_cast<int32_T>(l)
                  - 1)], m, ml1_0, &pathSegObjs_data[loop_ub_tmp]);
            pathCosts_data[loop_ub_tmp] = FlightMissionMode_sum_l(ml1_data);
        }
    } else {
        *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>(
            static_cast<int32_T>(b_nRows + 1)));
        for (loop_ub_tmp = 1; static_cast<int32_T>(loop_ub_tmp - 1) <= b_nRows;
                loop_ub_tmp = static_cast<int32_T>(loop_ub_tmp + 1)) {
            l++;
            if (1 == loop_ub_tmp) {
                m[0] = kb;
                m[1] = lb;
                m[2] = mb;
                m[3] = nb;
            }

            if (2 == loop_ub_tmp) {
                m[0] = ob;
                m[1] = pb;
                m[2] = qb;
                m[3] = rb;
            }

            if (3 == loop_ub_tmp) {
                m[0] = sb;
                m[1] = tb;
                m[2] = ub;
                m[3] = vb;
            }

            if (4 == loop_ub_tmp) {
                m[0] = wb;
                m[1] = xb;
                m[2] = yb;
                m[3] = ac;
            }

            if (5 == loop_ub_tmp) {
                m[0] = bc;
                m[1] = cc;
                m[2] = dc;
                m[3] = ec;
            }

            if (6 == loop_ub_tmp) {
                m[0] = fc;
                m[1] = gc;
                m[2] = hc;
                m[3] = ic;
            }

            if (7 == loop_ub_tmp) {
                m[0] = jc;
                m[1] = kc;
                m[2] = lc;
                m[3] = mc;
            }

            if (8 == loop_ub_tmp) {
                m[0] = nc;
                m[1] = oc;
                m[2] = pc;
                m[3] = qc;
            }

            if (9 == loop_ub_tmp) {
                m[0] = rc;
                m[1] = sc;
                m[2] = tc;
                m[3] = uc;
            }

            if (10 == loop_ub_tmp) {
                m[0] = vc;
                m[1] = wc;
                m[2] = xc;
                m[3] = yc;
            }

            if (11 == loop_ub_tmp) {
                m[0] = ad;
                m[1] = bd;
                m[2] = cd;
                m[3] = dd;
            }

            if (12 == loop_ub_tmp) {
                m[0] = ed;
                m[1] = fd;
                m[2] = gd;
                m[3] = hd;
            }

            if (13 == loop_ub_tmp) {
                m[0] = id;
                m[1] = jd;
                m[2] = kd;
                m[3] = ld;
            }

            if (14 == loop_ub_tmp) {
                m[0] = md;
                m[1] = nd;
                m[2] = od;
                m[3] = pd;
            }

            if (15 == loop_ub_tmp) {
                m[0] = qd;
                m[1] = rd;
                m[2] = sd;
                m[3] = td;
            }

            if (16 == loop_ub_tmp) {
                m[0] = ud;
                m[1] = vd;
                m[2] = wd;
                m[3] = xd;
            }

            if (17 == loop_ub_tmp) {
                m[0] = yd;
                m[1] = ae;
                m[2] = be;
                m[3] = ce;
            }

            if (18 == loop_ub_tmp) {
                m[0] = de;
                m[1] = ee;
                m[2] = fe;
                m[3] = ge;
            }

            if (19 == loop_ub_tmp) {
                m[0] = he;
                m[1] = ie;
                m[2] = je;
                m[3] = ke;
            }

            if (20 == loop_ub_tmp) {
                m[0] = le;
                m[1] = me;
                m[2] = ne;
                m[3] = oe;
            }

            if (21 == loop_ub_tmp) {
                m[0] = pe;
                m[1] = qe;
                m[2] = re;
                m[3] = se;
            }

            if (22 == loop_ub_tmp) {
                m[0] = te;
                m[1] = ue;
                m[2] = ve;
                m[3] = we;
            }

            if (23 == loop_ub_tmp) {
                m[0] = xe;
                m[1] = ye;
                m[2] = af;
                m[3] = bf;
            }

            if (24 == loop_ub_tmp) {
                m[0] = cf;
                m[1] = df;
                m[2] = ef;
                m[3] = ff;
            }

            if (25 == loop_ub_tmp) {
                m[0] = gf;
                m[1] = hf;
                m[2] = jf;
                m[3] = kf;
            }

            if (26 == loop_ub_tmp) {
                m[0] = lf;
                m[1] = mf;
                m[2] = nf;
                m[3] = of;
            }

            if (27 == loop_ub_tmp) {
                m[0] = pf;
                m[1] = qf;
                m[2] = rf;
                m[3] = sf;
            }

            if (28 == loop_ub_tmp) {
                m[0] = tf;
                m[1] = uf;
                m[2] = vf;
                m[3] = wf;
            }

            b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>
                (l) - 1)];
            b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l)
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
            ml1_0[0] = ml1_tmp;
            ml1_data[0] = ml1_tmp;
            b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + s1->size[0]) - 1)];
            b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + g1->size[0]) - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + ml1->size[0]) - 1)];
            ml1_0[1] = ml1_tmp;
            ml1_data[1] = ml1_tmp;
            b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1))
                - 1)];
            b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1))
                - 1)];
            ml1_0[2] = ml1_tmp;
            ml1_data[2] = ml1_tmp;
            b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3))
                - 1)];
            b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3))
                - 1)];
            ml1_0[3] = ml1_tmp;
            ml1_data[3] = ml1_tmp;
            FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_ll
                (b_startPose, b_goalPose, localDW->b_fpa_data_m
                 [static_cast<int32_T>(static_cast<int32_T>(l) - 1)],
                 localDW->b_a_data_n[0], localDW->mtr_data_p[0],
                 localDW->h_data_l[static_cast<int32_T>(static_cast<int32_T>(l)
                  - 1)], m, ml1_0, &pathSegObjs_data[static_cast<int32_T>
                 (loop_ub_tmp - 1)]);
            pathCosts_data[static_cast<int32_T>(loop_ub_tmp - 1)] =
                FlightMissionMode_sum_l(ml1_data);
        }
    }

    FlightMissionMode_emxFree_real_T_n(&ml1);
    FlightMissionMode_emxFree_real_T_n(&g1);
    FlightMissionMode_emxFree_real_T_n(&s1);
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_uavDubinsConnection_connect_o(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPoses[4],
    const real_T goalPoses[4], uavDubinsPathSegment_FlightMissionMode_b_T
    pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
    int32_T *pathCosts_size, DW_FlightMissionMode_f_T *localDW)
{
    matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
        parser;
    real_T idx_data[28];
    int32_T tmp_size[2];
    int32_T flagOptimal;
    int32_T idx_size;
    char_T tmp_data[7];
    FlightMissionMode_NameValueParser_NameValueParser_p(&parser);
    parser.ParsedResults = parser.Defaults;
    flagOptimal = 1;
    FlightMissionMode_validatestring_o(parser.ParsedResults.f1, tmp_data,
        tmp_size);
    if (FlightMissionMode_strcmp_k4(tmp_data, tmp_size)) {
        flagOptimal = 0;
    }

    FlightMissionMode_uavDubinsConnection_findDisabledIndices_i(idx_data,
        &idx_size);
    FlightMissionMode_uavDubinsBuiltins_connect_fo(obj, startPoses, goalPoses,
        flagOptimal == 1, obj->MinTurningRadius, idx_data, &idx_size,
        pathSegObjs_data, pathSegObjs_size, pathCosts_data, pathCosts_size,
        localDW);
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_strcmp_gfbp(const cell_wrap_1_FlightMissionMode_T
    a[4], boolean_T b_bool[4])
{
    b_bool[0] = false;
    if ((a[0].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[0].f1.data[0] != 'N') ^ 1)))) {
        b_bool[0] = true;
    }

    b_bool[1] = false;
    if ((a[1].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[1].f1.data[0] != 'N') ^ 1)))) {
        b_bool[1] = true;
    }

    b_bool[2] = false;
    if ((a[2].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[2].f1.data[0] != 'N') ^ 1)))) {
        b_bool[2] = true;
    }

    b_bool[3] = false;
    if ((a[3].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[3].f1.data[0] != 'N') ^ 1)))) {
        b_bool[3] = true;
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_any_e(const boolean_T x[4])
{
    int32_T k;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(x[k])
              ^ 1))) {
            k = static_cast<int32_T>(k + 1);
        } else {
            y = true;
            exitg1 = true;
        }
    }

    return y;
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_useConstantDim_h(const real_T varargin_2_data[],
    const int32_T varargin_2_size[2], real_T varargout_1_data[], int32_T
    varargout_1_size[2])
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

static void FlightMissionMode_emxInit_real_T1_o
    (emxArray_real_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_real_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_real_T_FlightMissionMode_T));
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

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_eml_find_d(boolean_T x, int32_T i_data[], int32_T
    i_size[2])
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

static void FlightMissionMode_emxEnsureCapacity_real_T1_g
    (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4qzjr(const char_T a_data[], const
    int32_T a_size[2])
{
    boolean_T b_bool;
    b_bool = false;
    if ((a_size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a_data[0] != 'N') ^ 1)))) {
        b_bool = true;
    }

    return b_bool;
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4qzjrh(const char_T a_data[], const
    int32_T a_size[2])
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

static void FlightMissionMode_emxInit_boolean_T1_g
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_boolean_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_boolean_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_boolean_T_FlightMissionMode_T));
    emxArray = *pEmxArray;
    emxArray->data = (boolean_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void FlightMissionMode_emxEnsureCapacity_boolean_T1_j
    (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

static void FlightMissionMode_emxFree_boolean_T_n
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_boolean_T_FlightMissionMode_T *)nullptr) {
        if (((*pEmxArray)->data != (boolean_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_boolean_T_FlightMissionMode_T *)nullptr;
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_wrapToPi_l(emxArray_real_T_FlightMissionMode_T
    *theta)
{
    emxArray_boolean_T_FlightMissionMode_T *x;
    emxArray_real_T_FlightMissionMode_T *y;
    int32_T b_k;
    int32_T loop_ub;
    boolean_T b_y;
    boolean_T exitg1;
    FlightMissionMode_emxInit_real_T1_o(&y, 1);
    b_k = y->size[0];
    y->size[0] = theta->size[0];
    FlightMissionMode_emxEnsureCapacity_real_T1_g(y, b_k);
    for (b_k = 0; b_k <= static_cast<int32_T>(theta->size[0] - 1); b_k =
            static_cast<int32_T>(b_k + 1)) {
        y->data[b_k] = std::abs(theta->data[b_k]);
    }

    FlightMissionMode_emxInit_boolean_T1_g(&x, 1);
    b_k = x->size[0];
    x->size[0] = y->size[0];
    FlightMissionMode_emxEnsureCapacity_boolean_T1_j(x, b_k);
    loop_ub = y->size[0];
    for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
        x->data[b_k] = (y->data[b_k] > 3.1415926535897931);
    }

    b_y = false;
    b_k = 1;
    exitg1 = false;
    while ((!exitg1) && (b_k <= x->size[0])) {
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (x->data[static_cast<int32_T>(b_k - 1)]) ^ 1))) {
            b_k = static_cast<int32_T>(b_k + 1);
        } else {
            b_y = true;
            exitg1 = true;
        }
    }

    if (b_y) {
        b_k = y->size[0];
        y->size[0] = theta->size[0];
        FlightMissionMode_emxEnsureCapacity_real_T1_g(y, b_k);
        loop_ub = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            y->data[b_k] = theta->data[b_k] + 3.1415926535897931;
        }

        b_k = theta->size[0];
        theta->size[0] = y->size[0];
        FlightMissionMode_emxEnsureCapacity_real_T1_g(theta, b_k);
        for (b_k = 0; b_k <= static_cast<int32_T>(y->size[0] - 1); b_k =
                static_cast<int32_T>(b_k + 1)) {
            theta->data[b_k] = mod_dBqh4Vat(y->data[b_k]);
        }

        b_k = x->size[0];
        x->size[0] = theta->size[0];
        FlightMissionMode_emxEnsureCapacity_boolean_T1_j(x, b_k);
        loop_ub = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            x->data[b_k] = (theta->data[b_k] == 0.0);
        }

        for (b_k = 0; b_k <= static_cast<int32_T>(x->size[0] - 1); b_k =
                static_cast<int32_T>(b_k + 1)) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (x->data[b_k]) & (y->data[b_k] > 0.0)))) {
                theta->data[b_k] = 6.2831853071795862;
            }
        }

        loop_ub = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            theta->data[b_k] -= 3.1415926535897931;
        }
    }

    FlightMissionMode_emxFree_boolean_T_n(&x);
    FlightMissionMode_emxFree_real_T_n(&y);
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4qzjrhe(const char_T a_data[], const
    int32_T a_size[2])
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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4qzjrhe2(const char_T a_data[], const
    int32_T a_size[2])
{
    boolean_T b_bool;
    b_bool = false;
    if ((a_size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a_data[0] != 'L') ^ 1)))) {
        b_bool = true;
    }

    return b_bool;
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4qzjrhe2c(const char_T a_data[],
    const int32_T a_size[2])
{
    boolean_T b_bool;
    b_bool = false;
    if ((a_size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a_data[0] != 'R') ^ 1)))) {
        b_bool = true;
    }

    return b_bool;
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static boolean_T FlightMissionMode_strcmp_k4qzjrhe2c2(const char_T a_data[],
    const int32_T a_size[2])
{
    boolean_T b_bool;
    b_bool = false;
    if ((a_size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a_data[0] != 'S') ^ 1)))) {
        b_bool = true;
    }

    return b_bool;
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_mtimes_l(const emxArray_real_T_FlightMissionMode_T
    *A, const real_T B[4], emxArray_real_T_FlightMissionMode_T *C)
{
    int32_T i;
    int32_T m;
    m = A->size[0];
    i = static_cast<int32_T>(C->size[0] * C->size[1]);
    C->size[0] = A->size[0];
    C->size[1] = 2;
    FlightMissionMode_emxEnsureCapacity_real_T_c(C, i);
    for (i = 0; i <= static_cast<int32_T>(m - 1); i = static_cast<int32_T>(i + 1))
    {
        C->data[i] = A->data[i] * B[0] + A->data[static_cast<int32_T>(A->size[0]
            + i)] * B[1];
    }

    for (i = 0; i <= static_cast<int32_T>(m - 1); i = static_cast<int32_T>(i + 1))
    {
        C->data[static_cast<int32_T>(m + i)] = A->data[i] * B[2] + A->data[
            static_cast<int32_T>(A->size[0] + i)] * B[3];
    }
}

// Function for MATLAB Function: '<S199>/StartPointGenerator'
static void FlightMissionMode_uavDubinsPathSegment_interpolate_g(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_1_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length, real_T samples, real_T
    poses_data[], int32_T poses_size[2])
{
    emxArray_real_T_FlightMissionMode_T *S;
    emxArray_real_T_FlightMissionMode_T *b_y;
    emxArray_real_T_FlightMissionMode_T *c_x;
    emxArray_real_T_FlightMissionMode_T *d_x;
    emxArray_real_T_FlightMissionMode_T *y;
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
    real_T intermediateLength;
    real_T radius;
    real_T samples_tmp;
    real_T state_0;
    real_T state_1;
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
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isnan(b_this_Length)) ^ 1))) {
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
        FlightMissionMode_strcmp_gfbp(b_this_MotionTypes, tmp);
        if (FlightMissionMode_any_e(tmp)) {
            tempMotionLength_size[0] = 1;
            tempMotionLength_size[1] = 3;
            tempMotionLength_data[0] = TransformMatrix[0];
            tempMotionLength_data[1] = TransformMatrix[1];
            tempMotionLength_data[2] = TransformMatrix[2];
        }

        FlightMissionMode_useConstantDim_h(tempMotionLength_data,
            tempMotionLength_size, x_data, x_size);
        intermediateLength = 0.0;
        state[0] = b_this_StartPose[0];
        state[1] = -b_this_StartPose[1];
        state[3] = -b_this_StartPose[3];
        tempMotionLength_data_tmp = 0;
        FlightMissionMode_emxInit_real_T1_o(&y, 1);
        FlightMissionMode_emxInit_real_T_h(&b_y, 2);
        FlightMissionMode_emxInit_real_T1_o(&c_x, 1);
        FlightMissionMode_emxInit_real_T1_o(&d_x, 1);
        FlightMissionMode_emxInit_real_T_h(&S, 2);
        while (tempMotionLength_data_tmp <= static_cast<int32_T>
                (tempMotionLength_size[1] - 1)) {
            if (static_cast<int32_T>(tempMotionLength_data_tmp + 1) == 1) {
                tempSamplesIndex = static_cast<boolean_T>(static_cast<int32_T>
                    ((samples >= intermediateLength) & (samples <=
                    (intermediateLength + tempMotionLength_data[0]) + 1.0E-6)));
            } else {
                tempSamplesIndex = static_cast<boolean_T>(static_cast<int32_T>
                    ((samples > intermediateLength) & (samples <=
                    (intermediateLength +
                     tempMotionLength_data[tempMotionLength_data_tmp]) + 1.0E-6)));
            }

            FlightMissionMode_eml_find_d(tempSamplesIndex, &o_data, x_size);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (FlightMissionMode_strcmp_k4qzjr
                     (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                      b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) ^
                    1))) {
                radius = b_this_MinTurningRadius;
                if (FlightMissionMode_strcmp_k4qzjrh
                        (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                         b_this_MotionTypes[tempMotionLength_data_tmp].f1.size))
                {
                    radius = b_this_HelixRadius;
                } else if (FlightMissionMode_strcmp_k4qzjrhe
                           (b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.data,
                            b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.size)) {
                    radius = b_this_HelixRadius;
                }

                count = 0;
                tempSamples_size_idx_0 = 1;
                tempSamples_data[0] = 0.0;
                if (static_cast<boolean_T>(static_cast<int32_T>((x_size[0] != 0)
                      & (x_size[1] != 0)))) {
                    tempSamples_size_idx_0 = 2;
                    tempSamples_data[1] = 0.0;
                    count = 1;
                    tempSamples_data[0] = samples;
                    samples = -1.0;
                }

                tempSamples_data[count] = x_data[tempMotionLength_data_tmp];
                for (count = 0; count <= static_cast<int32_T>
                        (tempSamples_size_idx_0 - 1); count++) {
                    S_data[count] = (tempSamples_data[count] -
                                     intermediateLength) / radius;
                }

                ns_size_idx_0 = tempSamples_size_idx_0;
                loop_ub = static_cast<int32_T>(static_cast<int32_T>
                    (tempSamples_size_idx_0 * 6) - 1);
                for (count = 0; count <= loop_ub; count++) {
                    ns_data[count] = 0.0;
                }

                for (count = 0; count <= static_cast<int32_T>
                        (tempSamples_size_idx_0 - 1); count++) {
                    z_data[count] = tempStartPose_idx_2 + tempSamples_data[count];
                }

                TransformMatrix_tmp = std::sin(state[3]);
                TransformMatrix_tmp_0 = std::cos(state[3]);
                TransformMatrix[0] = TransformMatrix_tmp_0;
                TransformMatrix[2] = TransformMatrix_tmp;
                TransformMatrix[1] = -TransformMatrix_tmp;
                TransformMatrix[3] = TransformMatrix_tmp_0;
                if (b_this_Length != 0.0) {
                    TransformMatrix_tmp = -b_this_GoalPose[2] -
                        tempStartPose_idx_2;
                    TransformMatrix_tmp_0 = b_this_Length * samples_tmp;
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        z_data[count] = tempSamples_data[count] /
                            TransformMatrix_tmp_0 * TransformMatrix_tmp +
                            tempStartPose_idx_2;
                    }
                }

                count = y->size[0];
                y->size[0] = tempSamples_size_idx_0;
                FlightMissionMode_emxEnsureCapacity_real_T1_g(y, count);
                for (count = 0; count <= static_cast<int32_T>
                        (tempSamples_size_idx_0 - 1); count++) {
                    y->data[count] = b_this_FlightPathAngle;
                }

                if (FlightMissionMode_strcmp_k4qzjrh
                        (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                         b_this_MotionTypes[tempMotionLength_data_tmp].f1.size) ||
                    FlightMissionMode_strcmp_k4qzjrhe2
                        (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                         b_this_MotionTypes[tempMotionLength_data_tmp].f1.size))
                {
                    count = c_x->size[0];
                    c_x->size[0] = tempSamples_size_idx_0;
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(c_x, count);
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        c_x->data[count] = S_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count =
                            static_cast<int32_T>(count + 1)) {
                        c_x->data[count] = std::sin(c_x->data[count]);
                    }

                    count = d_x->size[0];
                    d_x->size[0] = tempSamples_size_idx_0;
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(d_x, count);
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        d_x->data[count] = S_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count =
                            static_cast<int32_T>(count + 1)) {
                        d_x->data[count] = std::cos(d_x->data[count]);
                    }

                    count = static_cast<int32_T>(S->size[0] * S->size[1]);
                    S->size[0] = c_x->size[0];
                    S->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S, count);
                    loop_ub = c_x->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        S->data[count] = c_x->data[count];
                    }

                    loop_ub = d_x->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        S->data[static_cast<int32_T>(count + c_x->size[0])] =
                            1.0 - d_x->data[count];
                    }

                    FlightMissionMode_mtimes_l(S, TransformMatrix, b_y);
                    TransformMatrix_tmp = rt_atan2d_snf(b_this_AirSpeed *
                        b_this_AirSpeed, 9.8 * radius);
                    TransformMatrix_tmp_0 = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    loop_ub = b_y->size[0];
                    ns_size_idx_0 = b_y->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[count] = b_y->data[count] * radius +
                            TransformMatrix_tmp_0;
                        ns_data[static_cast<int32_T>(count + ns_size_idx_0)] =
                            b_y->data[static_cast<int32_T>(count + b_y->size[0])]
                            * radius + state_0;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 1))] = z_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 3))] = state_1 + S_data[count];
                    }

                    loop_ub = y->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 2))] = y->data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 5))] = -TransformMatrix_tmp;
                    }
                } else if (FlightMissionMode_strcmp_k4qzjrhe
                           (b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.data,
                            b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.size) || FlightMissionMode_strcmp_k4qzjrhe2c
                           (b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.data,
                            b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.size)) {
                    count = c_x->size[0];
                    c_x->size[0] = tempSamples_size_idx_0;
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(c_x, count);
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        c_x->data[count] = S_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count =
                            static_cast<int32_T>(count + 1)) {
                        c_x->data[count] = std::sin(c_x->data[count]);
                    }

                    count = d_x->size[0];
                    d_x->size[0] = tempSamples_size_idx_0;
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(d_x, count);
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        d_x->data[count] = S_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count =
                            static_cast<int32_T>(count + 1)) {
                        d_x->data[count] = std::cos(d_x->data[count]);
                    }

                    count = static_cast<int32_T>(S->size[0] * S->size[1]);
                    S->size[0] = c_x->size[0];
                    S->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S, count);
                    loop_ub = c_x->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        S->data[count] = c_x->data[count];
                    }

                    loop_ub = d_x->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        S->data[static_cast<int32_T>(count + c_x->size[0])] =
                            d_x->data[count] - 1.0;
                    }

                    FlightMissionMode_mtimes_l(S, TransformMatrix, b_y);
                    TransformMatrix_tmp = rt_atan2d_snf(b_this_AirSpeed *
                        b_this_AirSpeed, 9.8 * radius);
                    TransformMatrix_tmp_0 = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    loop_ub = b_y->size[0];
                    ns_size_idx_0 = b_y->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[count] = b_y->data[count] * radius +
                            TransformMatrix_tmp_0;
                        ns_data[static_cast<int32_T>(count + ns_size_idx_0)] =
                            b_y->data[static_cast<int32_T>(count + b_y->size[0])]
                            * radius + state_0;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 1))] = z_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 3))] = state_1 - S_data[count];
                    }

                    loop_ub = y->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 2))] = y->data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 5))] = TransformMatrix_tmp;
                    }
                } else if (FlightMissionMode_strcmp_k4qzjrhe2c2
                           (b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.data,
                            b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.size)) {
                    count = static_cast<int32_T>(S->size[0] * S->size[1]);
                    S->size[0] = tempSamples_size_idx_0;
                    S->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S, count);
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        S->data[count] = S_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        S->data[static_cast<int32_T>(count +
                            tempSamples_size_idx_0)] = 0.0;
                    }

                    FlightMissionMode_mtimes_l(S, TransformMatrix, b_y);
                    TransformMatrix_tmp_0 = state[0];
                    state_0 = state[1];
                    loop_ub = b_y->size[0];
                    ns_size_idx_0 = b_y->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[count] = b_y->data[count] * radius +
                            TransformMatrix_tmp_0;
                        ns_data[static_cast<int32_T>(count + ns_size_idx_0)] =
                            b_y->data[static_cast<int32_T>(count + b_y->size[0])]
                            * radius + state_0;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 1))] = z_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 3))] = state[3];
                    }

                    loop_ub = y->size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 2))] = y->data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size_idx_0 - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 5))] = 0.0;
                    }
                }

                if (static_cast<boolean_T>(static_cast<int32_T>((x_size[0] != 0)
                      & (x_size[1] != 0)))) {
                    if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = 0;
                    }

                    if (0 <= loop_ub) {
                        for (count = 0; count < 6; count++) {
                            poses_data[count] = ns_data[static_cast<int32_T>
                                (ns_size_idx_0 * count)];
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
                        poses_data[2] = -ns_data[static_cast<int32_T>
                            (ns_size_idx_0 << 1)];
                    }

                    if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = 0;
                    }

                    if (0 <= loop_ub) {
                        poses_data[3] = -ns_data[static_cast<int32_T>
                            (ns_size_idx_0 * 3)];
                    }
                }

                for (count = 0; count < 6; count++) {
                    state[count] = ns_data[static_cast<int32_T>
                        (static_cast<int32_T>(ns_size_idx_0 +
                          static_cast<int32_T>(ns_size_idx_0 * count)) - 1)];
                }
            }

            intermediateLength +=
                tempMotionLength_data[tempMotionLength_data_tmp];
            tempMotionLength_data_tmp = static_cast<int32_T>
                (tempMotionLength_data_tmp + 1);
        }

        FlightMissionMode_emxFree_real_T_n(&S);
        FlightMissionMode_emxFree_real_T_n(&d_x);
        FlightMissionMode_emxFree_real_T_n(&c_x);
        FlightMissionMode_emxFree_real_T_n(&b_y);
        count = y->size[0];
        y->size[0] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T1_g(y, count);
        y->data[0] = poses_data[3];
        FlightMissionMode_wrapToPi_l(y);
        loop_ub = y->size[0];
        for (count = 0; count <= static_cast<int32_T>(loop_ub - 1); count++) {
            poses_data[3] = y->data[count];
        }

        FlightMissionMode_emxFree_real_T_n(&y);
    }
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_wrapToPi_d(real_T theta_data[], int32_T
    *theta_size)
{
    real_T y_data_idx_0;
    boolean_T b_y;
    b_y = false;
    if (std::abs(theta_data[0]) > 3.1415926535897931) {
        b_y = true;
    }

    if (b_y) {
        y_data_idx_0 = theta_data[0] + 3.1415926535897931;
        *theta_size = 1;
        theta_data[0] = mod_dBqh4Vat(theta_data[0] + 3.1415926535897931);
        if (static_cast<boolean_T>(static_cast<int32_T>((theta_data[0] == 0.0) &
              (y_data_idx_0 > 0.0)))) {
            theta_data[0] = 6.2831853071795862;
        }

        *theta_size = 1;
        theta_data[0] -= 3.1415926535897931;
    }
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_sin(real_T x_data[], const int32_T *x_size)
{
    int32_T k;
    for (k = 0; k <= static_cast<int32_T>(*x_size - 1); k = static_cast<int32_T>
            (k + 1)) {
        x_data[k] = std::sin(x_data[k]);
    }
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_cos(real_T x_data[], const int32_T *x_size)
{
    int32_T k;
    for (k = 0; k <= static_cast<int32_T>(*x_size - 1); k = static_cast<int32_T>
            (k + 1)) {
        x_data[k] = std::cos(x_data[k]);
    }
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_mtimes_k(const real_T A_data[], const int32_T
    A_size[2], const real_T B[4], real_T C_data[], int32_T C_size[2])
{
    int32_T C_data_tmp;
    int32_T i;
    int32_T m;
    m = A_size[0];
    C_size[0] = A_size[0];
    C_size[1] = 2;
    for (i = 0; i <= static_cast<int32_T>(m - 1); i = static_cast<int32_T>(i + 1))
    {
        C_data[i] = A_data[i] * B[0] + A_data[static_cast<int32_T>(A_size[0] + i)]
            * B[1];
    }

    for (i = 0; i <= static_cast<int32_T>(m - 1); i = static_cast<int32_T>(i + 1))
    {
        C_data_tmp = static_cast<int32_T>(A_size[0] + i);
        C_data[C_data_tmp] = A_data[i] * B[2] + A_data[C_data_tmp] * B[3];
    }
}

// Function for MATLAB Function: '<S161>/StartPointGenerator'
static void FlightMissionMode_uavDubinsPathSegment_interpolate_f(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_1_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length, real_T samples, real_T
    poses_data[], int32_T poses_size[2])
{
    real_T ns_data[12];
    real_T state[6];
    real_T S_data_0[4];
    real_T TransformMatrix[4];
    real_T p_data[4];
    real_T tempMotionLength_data[4];
    real_T x_data[4];
    real_T S_data[2];
    real_T s_data[2];
    real_T tempSamples_data[2];
    real_T z_data[2];
    real_T TransformMatrix_tmp;
    real_T TransformMatrix_tmp_0;
    real_T intermediateLength;
    real_T radius;
    real_T samples_tmp;
    real_T state_0;
    real_T state_1;
    real_T tempStartPose_idx_2;
    int32_T S_size[2];
    int32_T p_size[2];
    int32_T tempMotionLength_size[2];
    int32_T x_size[2];
    int32_T count;
    int32_T loop_ub;
    int32_T ns_size_idx_0;
    int32_T t_size;
    int32_T tempMotionLength_data_tmp;
    int32_T tempSamples_size;
    boolean_T tmp[4];
    boolean_T tempSamplesIndex;
    poses_size[0] = 0;
    poses_size[1] = 6;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isnan(b_this_Length)) ^ 1))) {
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
        FlightMissionMode_strcmp_gfbp(b_this_MotionTypes, tmp);
        if (FlightMissionMode_any_e(tmp)) {
            tempMotionLength_size[0] = 1;
            tempMotionLength_size[1] = 3;
            tempMotionLength_data[0] = TransformMatrix[0];
            tempMotionLength_data[1] = TransformMatrix[1];
            tempMotionLength_data[2] = TransformMatrix[2];
        }

        FlightMissionMode_useConstantDim_h(tempMotionLength_data,
            tempMotionLength_size, x_data, x_size);
        intermediateLength = 0.0;
        state[0] = b_this_StartPose[0];
        state[1] = -b_this_StartPose[1];
        state[3] = -b_this_StartPose[3];
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                static_cast<int32_T>(tempMotionLength_size[1] - 1);
                tempMotionLength_data_tmp = static_cast<int32_T>
                (tempMotionLength_data_tmp + 1)) {
            if (static_cast<int32_T>(tempMotionLength_data_tmp + 1) == 1) {
                tempSamplesIndex = static_cast<boolean_T>(static_cast<int32_T>
                    ((samples >= intermediateLength) & (samples <=
                    (intermediateLength + tempMotionLength_data[0]) + 1.0E-6)));
            } else {
                tempSamplesIndex = static_cast<boolean_T>(static_cast<int32_T>
                    ((samples > intermediateLength) & (samples <=
                    (intermediateLength +
                     tempMotionLength_data[tempMotionLength_data_tmp]) + 1.0E-6)));
            }

            FlightMissionMode_eml_find_d(tempSamplesIndex, &t_size, x_size);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (FlightMissionMode_strcmp_k4qzjr
                     (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                      b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) ^
                    1))) {
                radius = b_this_MinTurningRadius;
                if (FlightMissionMode_strcmp_k4qzjrh
                        (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                         b_this_MotionTypes[tempMotionLength_data_tmp].f1.size))
                {
                    radius = b_this_HelixRadius;
                } else if (FlightMissionMode_strcmp_k4qzjrhe
                           (b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.data,
                            b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.size)) {
                    radius = b_this_HelixRadius;
                }

                count = 0;
                tempSamples_size = 1;
                tempSamples_data[0] = 0.0;
                if (static_cast<boolean_T>(static_cast<int32_T>((x_size[0] != 0)
                      & (x_size[1] != 0)))) {
                    tempSamples_size = 2;
                    tempSamples_data[1] = 0.0;
                    count = 1;
                    tempSamples_data[0] = samples;
                    samples = -1.0;
                }

                tempSamples_data[count] = x_data[tempMotionLength_data_tmp];
                for (count = 0; count <= static_cast<int32_T>(tempSamples_size -
                      1); count++) {
                    S_data[count] = (tempSamples_data[count] -
                                     intermediateLength) / radius;
                }

                ns_size_idx_0 = tempSamples_size;
                loop_ub = static_cast<int32_T>(static_cast<int32_T>
                    (tempSamples_size * 6) - 1);
                for (count = 0; count <= loop_ub; count++) {
                    ns_data[count] = 0.0;
                }

                for (count = 0; count <= static_cast<int32_T>(tempSamples_size -
                      1); count++) {
                    z_data[count] = tempStartPose_idx_2 + tempSamples_data[count];
                }

                TransformMatrix_tmp = std::sin(state[3]);
                TransformMatrix_tmp_0 = std::cos(state[3]);
                TransformMatrix[0] = TransformMatrix_tmp_0;
                TransformMatrix[2] = TransformMatrix_tmp;
                TransformMatrix[1] = -TransformMatrix_tmp;
                TransformMatrix[3] = TransformMatrix_tmp_0;
                if (b_this_Length != 0.0) {
                    TransformMatrix_tmp = -b_this_GoalPose[2] -
                        tempStartPose_idx_2;
                    TransformMatrix_tmp_0 = b_this_Length * samples_tmp;
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        z_data[count] = tempSamples_data[count] /
                            TransformMatrix_tmp_0 * TransformMatrix_tmp +
                            tempStartPose_idx_2;
                    }
                }

                if (FlightMissionMode_strcmp_k4qzjrh
                        (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                         b_this_MotionTypes[tempMotionLength_data_tmp].f1.size) ||
                    FlightMissionMode_strcmp_k4qzjrhe2
                        (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                         b_this_MotionTypes[tempMotionLength_data_tmp].f1.size))
                {
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        tempSamples_data[count] = S_data[count];
                    }

                    FlightMissionMode_sin(tempSamples_data, &tempSamples_size);
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        s_data[count] = S_data[count];
                    }

                    FlightMissionMode_cos(s_data, &tempSamples_size);
                    S_size[0] = tempSamples_size;
                    S_size[1] = 2;
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        S_data_0[count] = tempSamples_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        S_data_0[static_cast<int32_T>(count + tempSamples_size)]
                            = 1.0 - s_data[count];
                    }

                    FlightMissionMode_mtimes_k(S_data_0, S_size, TransformMatrix,
                        p_data, p_size);
                    TransformMatrix_tmp = rt_atan2d_snf(b_this_AirSpeed *
                        b_this_AirSpeed, 9.8 * radius);
                    TransformMatrix_tmp_0 = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    loop_ub = p_size[0];
                    ns_size_idx_0 = p_size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[count] = p_data[count] * radius +
                            TransformMatrix_tmp_0;
                        ns_data[static_cast<int32_T>(count + ns_size_idx_0)] =
                            p_data[static_cast<int32_T>(count + p_size[0])] *
                            radius + state_0;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 1))] = z_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 3))] = state_1 + S_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 2))] = b_this_FlightPathAngle;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 5))] = -TransformMatrix_tmp;
                    }
                } else if (FlightMissionMode_strcmp_k4qzjrhe
                           (b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.data,
                            b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.size) || FlightMissionMode_strcmp_k4qzjrhe2c
                           (b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.data,
                            b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.size)) {
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        tempSamples_data[count] = S_data[count];
                    }

                    FlightMissionMode_sin(tempSamples_data, &tempSamples_size);
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        s_data[count] = S_data[count];
                    }

                    FlightMissionMode_cos(s_data, &tempSamples_size);
                    S_size[0] = tempSamples_size;
                    S_size[1] = 2;
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        S_data_0[count] = tempSamples_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        S_data_0[static_cast<int32_T>(count + tempSamples_size)]
                            = s_data[count] - 1.0;
                    }

                    FlightMissionMode_mtimes_k(S_data_0, S_size, TransformMatrix,
                        p_data, p_size);
                    TransformMatrix_tmp = rt_atan2d_snf(b_this_AirSpeed *
                        b_this_AirSpeed, 9.8 * radius);
                    TransformMatrix_tmp_0 = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    loop_ub = p_size[0];
                    ns_size_idx_0 = p_size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[count] = p_data[count] * radius +
                            TransformMatrix_tmp_0;
                        ns_data[static_cast<int32_T>(count + ns_size_idx_0)] =
                            p_data[static_cast<int32_T>(count + p_size[0])] *
                            radius + state_0;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 1))] = z_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 3))] = state_1 - S_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 2))] = b_this_FlightPathAngle;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 5))] = TransformMatrix_tmp;
                    }
                } else if (FlightMissionMode_strcmp_k4qzjrhe2c2
                           (b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.data,
                            b_this_MotionTypes[tempMotionLength_data_tmp].
                            f1.size)) {
                    S_size[0] = tempSamples_size;
                    S_size[1] = 2;
                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        S_data_0[count] = S_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        S_data_0[static_cast<int32_T>(count + tempSamples_size)]
                            = 0.0;
                    }

                    FlightMissionMode_mtimes_k(S_data_0, S_size, TransformMatrix,
                        p_data, p_size);
                    TransformMatrix_tmp_0 = state[0];
                    state_0 = state[1];
                    loop_ub = p_size[0];
                    ns_size_idx_0 = p_size[0];
                    for (count = 0; count <= static_cast<int32_T>(loop_ub - 1);
                            count++) {
                        ns_data[count] = p_data[count] * radius +
                            TransformMatrix_tmp_0;
                        ns_data[static_cast<int32_T>(count + ns_size_idx_0)] =
                            p_data[static_cast<int32_T>(count + p_size[0])] *
                            radius + state_0;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 1))] = z_data[count];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 3))] = state[3];
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 << 2))] = b_this_FlightPathAngle;
                    }

                    for (count = 0; count <= static_cast<int32_T>
                            (tempSamples_size - 1); count++) {
                        ns_data[static_cast<int32_T>(count + static_cast<int32_T>
                            (ns_size_idx_0 * 5))] = 0.0;
                    }
                }

                if (static_cast<boolean_T>(static_cast<int32_T>((x_size[0] != 0)
                      & (x_size[1] != 0)))) {
                    if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = 0;
                    }

                    if (0 <= loop_ub) {
                        for (count = 0; count < 6; count++) {
                            poses_data[count] = ns_data[static_cast<int32_T>
                                (ns_size_idx_0 * count)];
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
                        poses_data[2] = -ns_data[static_cast<int32_T>
                            (ns_size_idx_0 << 1)];
                    }

                    if (1 > static_cast<int32_T>(ns_size_idx_0 - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = 0;
                    }

                    if (0 <= loop_ub) {
                        poses_data[3] = -ns_data[static_cast<int32_T>
                            (ns_size_idx_0 * 3)];
                    }
                }

                for (count = 0; count < 6; count++) {
                    state[count] = ns_data[static_cast<int32_T>
                        (static_cast<int32_T>(ns_size_idx_0 +
                          static_cast<int32_T>(ns_size_idx_0 * count)) - 1)];
                }
            }

            intermediateLength +=
                tempMotionLength_data[tempMotionLength_data_tmp];
        }

        t_size = 1;
        tempStartPose_idx_2 = poses_data[3];
        FlightMissionMode_wrapToPi_d(&tempStartPose_idx_2, &t_size);
        poses_data[3] = tempStartPose_idx_2;
    }
}

static void FlightMissionMode_emxInit_int32_T_k
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_int32_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_int32_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_int32_T_FlightMissionMode_T));
    emxArray = *pEmxArray;
    emxArray->data = (int32_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void FlightMissionMode_emxEnsureCapacity_int32_T_j
    (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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
            std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
                         (int32_T) * static_cast<uint32_T>(oldNumel)));
            if (emxArray->canFreeData) {
                std::free(emxArray->data);
            }
        }

        emxArray->data = (int32_T *)newData;
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

static void FlightMissionMode_emxInit_int32_T1_l
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_int32_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_int32_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_int32_T_FlightMissionMode_T));
    emxArray = *pEmxArray;
    emxArray->data = (int32_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void FlightMissionMode_emxEnsureCapacity_int32_T1_k
    (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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
            std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
                         (int32_T) * static_cast<uint32_T>(oldNumel)));
            if (emxArray->canFreeData) {
                std::free(emxArray->data);
            }
        }

        emxArray->data = (int32_T *)newData;
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

static void FlightMissionMode_emxFree_int32_T_a
    (emxArray_int32_T_FlightMissionMode_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_int32_T_FlightMissionMode_T *)nullptr) {
        if (((*pEmxArray)->data != (int32_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_int32_T_FlightMissionMode_T *)nullptr;
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_merge_a5o(emxArray_int32_T_FlightMissionMode_T
    *idx, emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T np,
    int32_T nq, emxArray_int32_T_FlightMissionMode_T *iwork,
    emxArray_real_T_FlightMissionMode_T *xwork)
{
    int32_T exitg1;
    int32_T iout;
    int32_T n;
    int32_T n_tmp;
    int32_T q;
    if (nq != 0) {
        n_tmp = static_cast<int32_T>(np + nq);
        for (q = 0; q <= static_cast<int32_T>(n_tmp - 1); q =
                static_cast<int32_T>(q + 1)) {
            iout = static_cast<int32_T>(offset + q);
            iwork->data[q] = idx->data[iout];
            xwork->data[q] = x->data[iout];
        }

        n = 0;
        q = np;
        iout = static_cast<int32_T>(offset - 1);
        do {
            exitg1 = 0;
            iout = static_cast<int32_T>(iout + 1);
            if (xwork->data[n] <= xwork->data[q]) {
                idx->data[iout] = iwork->data[n];
                x->data[iout] = xwork->data[n];
                if (static_cast<int32_T>(n + 1) < np) {
                    n = static_cast<int32_T>(n + 1);
                } else {
                    exitg1 = 1;
                }
            } else {
                idx->data[iout] = iwork->data[q];
                x->data[iout] = xwork->data[q];
                if (static_cast<int32_T>(q + 1) < n_tmp) {
                    q = static_cast<int32_T>(q + 1);
                } else {
                    q = static_cast<int32_T>(iout - n);
                    while (static_cast<int32_T>(n + 1) <= np) {
                        n_tmp = static_cast<int32_T>(static_cast<int32_T>(q + n)
                            + 1);
                        idx->data[n_tmp] = iwork->data[n];
                        x->data[n_tmp] = xwork->data[n];
                        n = static_cast<int32_T>(n + 1);
                    }

                    exitg1 = 1;
                }
            }
        } while (exitg1 == 0);
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_merge_block_h(emxArray_int32_T_FlightMissionMode_T
    *idx, emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T n,
    int32_T preSortLevel, emxArray_int32_T_FlightMissionMode_T *iwork,
    emxArray_real_T_FlightMissionMode_T *xwork)
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
                FlightMissionMode_merge_a5o(idx, x, static_cast<int32_T>(offset
                    + tailOffset), bLen, static_cast<int32_T>(nTail - bLen),
                    iwork, xwork);
            }
        }

        tailOffset = static_cast<int32_T>(bLen << 1);
        nPairs = static_cast<int32_T>(nPairs >> 1);
        for (nTail = 0; nTail <= static_cast<int32_T>(nPairs - 1); nTail =
                static_cast<int32_T>(nTail + 1)) {
            FlightMissionMode_merge_a5o(idx, x, static_cast<int32_T>(offset +
                static_cast<int32_T>(nTail * tailOffset)), bLen, bLen, iwork,
                xwork);
        }

        bLen = tailOffset;
    }

    if (n > bLen) {
        FlightMissionMode_merge_a5o(idx, x, offset, bLen, static_cast<int32_T>(n
            - bLen), iwork, xwork);
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_sort_o4u(emxArray_real_T_FlightMissionMode_T *x)
{
    emxArray_int32_T_FlightMissionMode_T *idx;
    emxArray_int32_T_FlightMissionMode_T *iwork;
    emxArray_real_T_FlightMissionMode_T *b_x;
    emxArray_real_T_FlightMissionMode_T *xwork;
    real_T b_xwork[256];
    real_T x4[4];
    real_T tmp;
    real_T tmp_0;
    int32_T b_iwork[256];
    int32_T idx4[4];
    int32_T bLen;
    int32_T bLen2;
    int32_T b_iwork_tmp;
    int32_T blockOffset;
    int32_T e_k;
    int32_T exitg1;
    int32_T i1;
    int32_T ib;
    int32_T n;
    int32_T nBlocks;
    int32_T nPairs;
    int32_T p;
    int32_T q;
    int32_T wOffset;
    int8_T perm[4];
    FlightMissionMode_emxInit_real_T_h(&b_x, 2);
    b_iwork_tmp = static_cast<int32_T>(b_x->size[0] * b_x->size[1]);
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    FlightMissionMode_emxEnsureCapacity_real_T_c(b_x, b_iwork_tmp);
    i1 = static_cast<int32_T>(x->size[1] - 1);
    for (ib = 0; ib <= i1; ib++) {
        b_x->data[ib] = x->data[ib];
    }

    if (x->size[1] != 0) {
        b_iwork_tmp = static_cast<int32_T>(b_x->size[0] * b_x->size[1]);
        b_x->size[0] = 1;
        b_x->size[1] = x->size[1];
        FlightMissionMode_emxEnsureCapacity_real_T_c(b_x, b_iwork_tmp);
        i1 = static_cast<int32_T>(x->size[1] - 1);
        for (ib = 0; ib <= i1; ib++) {
            b_x->data[ib] = x->data[ib];
        }

        FlightMissionMode_emxInit_int32_T_k(&idx, 2);
        b_iwork_tmp = static_cast<int32_T>(idx->size[0] * idx->size[1]);
        idx->size[0] = 1;
        idx->size[1] = x->size[1];
        FlightMissionMode_emxEnsureCapacity_int32_T_j(idx, b_iwork_tmp);
        i1 = static_cast<int32_T>(x->size[1] - 1);
        for (ib = 0; ib <= i1; ib++) {
            idx->data[ib] = 0;
        }

        FlightMissionMode_emxInit_real_T1_o(&xwork, 1);
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
        FlightMissionMode_emxEnsureCapacity_real_T1_g(xwork, b_iwork_tmp);
        i1 = x->size[1];
        for (ib = 0; ib <= static_cast<int32_T>(i1 - 1); ib++) {
            xwork->data[ib] = 0.0;
        }

        nBlocks = 0;
        ib = 0;
        for (wOffset = 0; wOffset <= static_cast<int32_T>(n - 1); wOffset =
                static_cast<int32_T>(wOffset + 1)) {
            if (std::isnan(b_x->data[wOffset])) {
                q = static_cast<int32_T>(static_cast<int32_T>(n - nBlocks) - 1);
                idx->data[q] = static_cast<int32_T>(wOffset + 1);
                xwork->data[q] = b_x->data[wOffset];
                nBlocks = static_cast<int32_T>(nBlocks + 1);
            } else {
                ib = static_cast<int32_T>(ib + 1);
                idx4[static_cast<int32_T>(ib - 1)] = static_cast<int32_T>
                    (wOffset + 1);
                x4[static_cast<int32_T>(ib - 1)] = b_x->data[wOffset];
                if (ib == 4) {
                    ib = static_cast<int32_T>(wOffset - nBlocks);
                    if (x4[0] <= x4[1]) {
                        i1 = 1;
                        bLen = 2;
                    } else {
                        i1 = 2;
                        bLen = 1;
                    }

                    if (x4[2] <= x4[3]) {
                        bLen2 = 3;
                        nPairs = 4;
                    } else {
                        bLen2 = 4;
                        nPairs = 3;
                    }

                    tmp = x4[static_cast<int32_T>(i1 - 1)];
                    tmp_0 = x4[static_cast<int32_T>(bLen2 - 1)];
                    if (tmp <= tmp_0) {
                        tmp = x4[static_cast<int32_T>(bLen - 1)];
                        if (tmp <= tmp_0) {
                            perm[0] = static_cast<int8_T>(i1);
                            perm[1] = static_cast<int8_T>(bLen);
                            perm[2] = static_cast<int8_T>(bLen2);
                            perm[3] = static_cast<int8_T>(nPairs);
                        } else if (tmp <= x4[static_cast<int32_T>(nPairs - 1)])
                        {
                            perm[0] = static_cast<int8_T>(i1);
                            perm[1] = static_cast<int8_T>(bLen2);
                            perm[2] = static_cast<int8_T>(bLen);
                            perm[3] = static_cast<int8_T>(nPairs);
                        } else {
                            perm[0] = static_cast<int8_T>(i1);
                            perm[1] = static_cast<int8_T>(bLen2);
                            perm[2] = static_cast<int8_T>(nPairs);
                            perm[3] = static_cast<int8_T>(bLen);
                        }
                    } else {
                        tmp_0 = x4[static_cast<int32_T>(nPairs - 1)];
                        if (tmp <= tmp_0) {
                            if (x4[static_cast<int32_T>(bLen - 1)] <= tmp_0) {
                                perm[0] = static_cast<int8_T>(bLen2);
                                perm[1] = static_cast<int8_T>(i1);
                                perm[2] = static_cast<int8_T>(bLen);
                                perm[3] = static_cast<int8_T>(nPairs);
                            } else {
                                perm[0] = static_cast<int8_T>(bLen2);
                                perm[1] = static_cast<int8_T>(i1);
                                perm[2] = static_cast<int8_T>(nPairs);
                                perm[3] = static_cast<int8_T>(bLen);
                            }
                        } else {
                            perm[0] = static_cast<int8_T>(bLen2);
                            perm[1] = static_cast<int8_T>(nPairs);
                            perm[2] = static_cast<int8_T>(i1);
                            perm[3] = static_cast<int8_T>(bLen);
                        }
                    }

                    idx->data[static_cast<int32_T>(ib - 3)] = idx4[static_cast<
                        int32_T>(static_cast<int32_T>(perm[0]) - 1)];
                    idx->data[static_cast<int32_T>(ib - 2)] = idx4[static_cast<
                        int32_T>(static_cast<int32_T>(perm[1]) - 1)];
                    idx->data[static_cast<int32_T>(ib - 1)] = idx4[static_cast<
                        int32_T>(static_cast<int32_T>(perm[2]) - 1)];
                    idx->data[ib] = idx4[static_cast<int32_T>
                        (static_cast<int32_T>(perm[3]) - 1)];
                    b_x->data[static_cast<int32_T>(ib - 3)] = x4
                        [static_cast<int32_T>(static_cast<int32_T>(perm[0]) - 1)];
                    b_x->data[static_cast<int32_T>(ib - 2)] = x4
                        [static_cast<int32_T>(static_cast<int32_T>(perm[1]) - 1)];
                    b_x->data[static_cast<int32_T>(ib - 1)] = x4
                        [static_cast<int32_T>(static_cast<int32_T>(perm[2]) - 1)];
                    b_x->data[ib] = x4[static_cast<int32_T>(static_cast<int32_T>
                        (perm[3]) - 1)];
                    ib = 0;
                }
            }
        }

        wOffset = static_cast<int32_T>(static_cast<int32_T>(x->size[1] - nBlocks)
            - 1);
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

            for (i1 = 0; i1 <= static_cast<int32_T>(ib - 1); i1 =
                    static_cast<int32_T>(i1 + 1)) {
                q = static_cast<int32_T>(static_cast<int32_T>(perm[i1]) - 1);
                b_iwork_tmp = static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(wOffset - ib) + i1) + 1);
                idx->data[b_iwork_tmp] = idx4[q];
                b_x->data[b_iwork_tmp] = x4[q];
            }
        }

        ib = static_cast<int32_T>(static_cast<int32_T>(nBlocks >> 1) + 1);
        for (i1 = 1; static_cast<int32_T>(i1 - 1) <= static_cast<int32_T>(ib - 2);
             i1 = static_cast<int32_T>(i1 + 1)) {
            bLen2 = static_cast<int32_T>(wOffset + i1);
            bLen = idx->data[bLen2];
            q = static_cast<int32_T>(n - i1);
            idx->data[bLen2] = idx->data[q];
            idx->data[q] = bLen;
            b_x->data[bLen2] = xwork->data[q];
            b_x->data[q] = xwork->data[bLen2];
        }

        if (static_cast<uint32_T>(static_cast<uint32_T>(nBlocks) & 1U) != 0U) {
            wOffset = static_cast<int32_T>(wOffset + ib);
            b_x->data[wOffset] = xwork->data[wOffset];
        }

        FlightMissionMode_emxInit_int32_T1_l(&iwork, 1);
        b_iwork_tmp = iwork->size[0];
        iwork->size[0] = x->size[1];
        FlightMissionMode_emxEnsureCapacity_int32_T1_k(iwork, b_iwork_tmp);
        i1 = x->size[1];
        for (ib = 0; ib <= static_cast<int32_T>(i1 - 1); ib++) {
            iwork->data[ib] = 0;
        }

        n = static_cast<int32_T>(x->size[1] - nBlocks);
        wOffset = 2;
        if (n > 1) {
            if (x->size[1] >= 256) {
                nBlocks = static_cast<int32_T>(n >> 8);
                if (nBlocks > 0) {
                    for (ib = 0; ib <= static_cast<int32_T>(nBlocks - 1); ib =
                            static_cast<int32_T>(ib + 1)) {
                        i1 = static_cast<int32_T>(static_cast<int32_T>(ib << 8)
                            - 1);
                        for (wOffset = 0; wOffset < 6; wOffset++) {
                            bLen = static_cast<int32_T>(1 << static_cast<int32_T>
                                (wOffset + 2));
                            bLen2 = static_cast<int32_T>(bLen << 1);
                            nPairs = static_cast<int32_T>(256 >>
                                static_cast<int32_T>(wOffset + 3));
                            for (e_k = 0; e_k <= static_cast<int32_T>(nPairs - 1);
                                 e_k = static_cast<int32_T>(e_k + 1)) {
                                blockOffset = static_cast<int32_T>
                                    (static_cast<int32_T>(e_k * bLen2) + i1);
                                for (p = 0; p <= static_cast<int32_T>(bLen2 - 1);
                                     p = static_cast<int32_T>(p + 1)) {
                                    b_iwork_tmp = static_cast<int32_T>(
                                        static_cast<int32_T>(blockOffset + p) +
                                        1);
                                    b_iwork[p] = idx->data[b_iwork_tmp];
                                    b_xwork[p] = b_x->data[b_iwork_tmp];
                                }

                                p = 0;
                                q = bLen;
                                do {
                                    exitg1 = 0;
                                    blockOffset = static_cast<int32_T>
                                        (blockOffset + 1);
                                    if (b_xwork[p] <= b_xwork[q]) {
                                        idx->data[blockOffset] = b_iwork[p];
                                        b_x->data[blockOffset] = b_xwork[p];
                                        if (static_cast<int32_T>(p + 1) < bLen)
                                        {
                                            p = static_cast<int32_T>(p + 1);
                                        } else {
                                            exitg1 = 1;
                                        }
                                    } else {
                                        idx->data[blockOffset] = b_iwork[q];
                                        b_x->data[blockOffset] = b_xwork[q];
                                        if (static_cast<int32_T>(q + 1) < bLen2)
                                        {
                                            q = static_cast<int32_T>(q + 1);
                                        } else {
                                            blockOffset = static_cast<int32_T>
                                                (blockOffset - p);
                                            while (static_cast<int32_T>(p + 1) <=
                                                   bLen) {
                                                b_iwork_tmp =
                                                    static_cast<int32_T>(
                                                    static_cast<int32_T>
                                                    (blockOffset + p) + 1);
                                                idx->data[b_iwork_tmp] =
                                                    b_iwork[p];
                                                b_x->data[b_iwork_tmp] =
                                                    b_xwork[p];
                                                p = static_cast<int32_T>(p + 1);
                                            }

                                            exitg1 = 1;
                                        }
                                    }
                                } while (exitg1 == 0);
                            }
                        }
                    }

                    nBlocks = static_cast<int32_T>(nBlocks << 8);
                    wOffset = static_cast<int32_T>(n - nBlocks);
                    if (wOffset > 0) {
                        b_iwork_tmp = iwork->size[0];
                        iwork->size[0] = x->size[1];
                        FlightMissionMode_emxEnsureCapacity_int32_T1_k(iwork,
                            b_iwork_tmp);
                        i1 = x->size[1];
                        for (ib = 0; ib <= static_cast<int32_T>(i1 - 1); ib++) {
                            iwork->data[ib] = 0;
                        }

                        FlightMissionMode_merge_block_h(idx, b_x, nBlocks,
                            wOffset, 2, iwork, xwork);
                    }

                    wOffset = 8;
                }
            }

            FlightMissionMode_merge_block_h(idx, b_x, 0, n, wOffset, iwork,
                xwork);
        }

        FlightMissionMode_emxFree_int32_T_a(&idx);
        FlightMissionMode_emxFree_real_T_n(&xwork);
        FlightMissionMode_emxFree_int32_T_a(&iwork);
    }

    b_iwork_tmp = static_cast<int32_T>(x->size[0] * x->size[1]);
    x->size[0] = 1;
    x->size[1] = b_x->size[1];
    FlightMissionMode_emxEnsureCapacity_real_T_c(x, b_iwork_tmp);
    i1 = b_x->size[1];
    for (ib = 0; ib <= static_cast<int32_T>(i1 - 1); ib++) {
        x->data[ib] = b_x->data[ib];
    }

    FlightMissionMode_emxFree_real_T_n(&b_x);
}

static void FlightMissionMode_emxInit_boolean_T_c
    (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions)
{
    emxArray_boolean_T_FlightMissionMode_T *emxArray;
    int32_T i;
    *pEmxArray = (emxArray_boolean_T_FlightMissionMode_T *)std::malloc(sizeof
        (emxArray_boolean_T_FlightMissionMode_T));
    emxArray = *pEmxArray;
    emxArray->data = (boolean_T *)nullptr;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void FlightMissionMode_emxEnsureCapacity_boolean_T_f
    (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel)
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

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_eml_find_f(const
    emxArray_boolean_T_FlightMissionMode_T *x,
    emxArray_int32_T_FlightMissionMode_T *i)
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
    FlightMissionMode_emxEnsureCapacity_int32_T_j(i, ii);
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
        FlightMissionMode_emxEnsureCapacity_int32_T_j(i, ii);
    }
}

// Function for MATLAB Function: '<S199>/StartPointGenerator'
static void FlightMissionMode_uavDubinsPathSegment_interpolate_g1(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_1_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length,
    emxArray_real_T_FlightMissionMode_T *samples,
    emxArray_real_T_FlightMissionMode_T *poses)
{
    emxArray_boolean_T_FlightMissionMode_T *tempSamplesIndex;
    emxArray_boolean_T_FlightMissionMode_T *tempSamplesIndex_0;
    emxArray_int32_T_FlightMissionMode_T *ab;
    emxArray_real_T_FlightMissionMode_T *S;
    emxArray_real_T_FlightMissionMode_T *S_0;
    emxArray_real_T_FlightMissionMode_T *e_x;
    emxArray_real_T_FlightMissionMode_T *ns;
    emxArray_real_T_FlightMissionMode_T *p;
    emxArray_real_T_FlightMissionMode_T *tempSamples;
    emxArray_real_T_FlightMissionMode_T *z;
    real_T state[6];
    real_T TransformMatrix[4];
    real_T c_x_data[4];
    real_T tempMotionLength_data[4];
    real_T TransformMatrix_tmp;
    real_T b_b_tmp;
    real_T intermediateLength;
    real_T radius;
    real_T samples_0;
    real_T startIndex;
    real_T state_0;
    real_T state_1;
    real_T tempStartPose_idx_2;
    int32_T c_x_size[2];
    int32_T tempMotionLength_size[2];
    int32_T S_idx_0;
    int32_T count;
    int32_T loop_ub;
    int32_T poses_0;
    int32_T tempMotionLength_data_tmp;
    int32_T tempMotionLength_data_tmp_0;
    boolean_T tmp[4];
    poses->size[0] = 0;
    poses->size[1] = 6;
    if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isnan(b_this_Length)) ^ 1))) && (samples->size[1] != 0)) {
        tempStartPose_idx_2 = -b_this_StartPose[2];
        tempMotionLength_data_tmp = static_cast<int32_T>(poses->size[0] *
            poses->size[1]);
        poses->size[0] = samples->size[1];
        poses->size[1] = 6;
        FlightMissionMode_emxEnsureCapacity_real_T_c(poses,
            tempMotionLength_data_tmp);
        loop_ub = static_cast<int32_T>(static_cast<int32_T>(samples->size[1] * 6)
            - 1);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <= loop_ub;
             tempMotionLength_data_tmp++) {
            poses->data[tempMotionLength_data_tmp] = 0.0;
        }

        b_b_tmp = std::cos(std::abs(b_this_FlightPathAngle));
        tempMotionLength_data_tmp = static_cast<int32_T>(samples->size[0] *
            samples->size[1]);
        samples->size[0] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_c(samples,
            tempMotionLength_data_tmp);
        loop_ub = static_cast<int32_T>(samples->size[1] - 1);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <= loop_ub;
             tempMotionLength_data_tmp++) {
            samples->data[tempMotionLength_data_tmp] *= b_b_tmp;
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
        FlightMissionMode_strcmp_gfbp(b_this_MotionTypes, tmp);
        if (FlightMissionMode_any_e(tmp)) {
            tempMotionLength_size[0] = 1;
            tempMotionLength_size[1] = 3;
            tempMotionLength_data[0] = TransformMatrix[0];
            tempMotionLength_data[1] = TransformMatrix[1];
            tempMotionLength_data[2] = TransformMatrix[2];
        }

        FlightMissionMode_useConstantDim_h(tempMotionLength_data,
            tempMotionLength_size, c_x_data, c_x_size);
        FlightMissionMode_sort_o4u(samples);
        intermediateLength = 0.0;
        startIndex = 1.0;
        state[0] = b_this_StartPose[0];
        state[1] = -b_this_StartPose[1];
        state[3] = -b_this_StartPose[3];
        poses_0 = 0;
        FlightMissionMode_emxInit_boolean_T_c(&tempSamplesIndex, 2);
        FlightMissionMode_emxInit_real_T1_o(&tempSamples, 1);
        FlightMissionMode_emxInit_real_T1_o(&S, 1);
        FlightMissionMode_emxInit_real_T_h(&ns, 2);
        FlightMissionMode_emxInit_real_T1_o(&z, 1);
        FlightMissionMode_emxInit_real_T_h(&p, 2);
        FlightMissionMode_emxInit_real_T1_o(&e_x, 1);
        FlightMissionMode_emxInit_int32_T_k(&ab, 2);
        FlightMissionMode_emxInit_boolean_T_c(&tempSamplesIndex_0, 2);
        FlightMissionMode_emxInit_real_T_h(&S_0, 2);
        while (poses_0 <= static_cast<int32_T>(tempMotionLength_size[1] - 1)) {
            if (static_cast<int32_T>(poses_0 + 1) == 1) {
                tempMotionLength_data_tmp = static_cast<int32_T>
                    (tempSamplesIndex->size[0] * tempSamplesIndex->size[1]);
                tempSamplesIndex->size[0] = 1;
                tempSamplesIndex->size[1] = samples->size[1];
                FlightMissionMode_emxEnsureCapacity_boolean_T_f(tempSamplesIndex,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(samples->size[1] - 1);
                radius = (intermediateLength + tempMotionLength_data[0]) +
                    1.0E-6;
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    samples_0 = samples->data[tempMotionLength_data_tmp];
                    tempSamplesIndex->data[tempMotionLength_data_tmp] =
                        static_cast<boolean_T>(static_cast<int32_T>((samples_0 >=
                        intermediateLength) & (samples_0 <= radius)));
                }
            } else {
                tempMotionLength_data_tmp = static_cast<int32_T>
                    (tempSamplesIndex->size[0] * tempSamplesIndex->size[1]);
                tempSamplesIndex->size[0] = 1;
                tempSamplesIndex->size[1] = samples->size[1];
                FlightMissionMode_emxEnsureCapacity_boolean_T_f(tempSamplesIndex,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(samples->size[1] - 1);
                radius = (intermediateLength + tempMotionLength_data[poses_0]) +
                    1.0E-6;
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    samples_0 = samples->data[tempMotionLength_data_tmp];
                    tempSamplesIndex->data[tempMotionLength_data_tmp] =
                        static_cast<boolean_T>(static_cast<int32_T>((samples_0 >
                        intermediateLength) & (samples_0 <= radius)));
                }
            }

            tempMotionLength_data_tmp = static_cast<int32_T>
                (tempSamplesIndex_0->size[0] * tempSamplesIndex_0->size[1]);
            tempSamplesIndex_0->size[0] = 1;
            tempSamplesIndex_0->size[1] = tempSamplesIndex->size[1];
            FlightMissionMode_emxEnsureCapacity_boolean_T_f(tempSamplesIndex_0,
                tempMotionLength_data_tmp);
            loop_ub = tempSamplesIndex->size[1];
            for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                    static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp
                    ++) {
                tempSamplesIndex_0->data[tempMotionLength_data_tmp] =
                    tempSamplesIndex->data[tempMotionLength_data_tmp];
            }

            FlightMissionMode_eml_find_f(tempSamplesIndex_0, ab);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (FlightMissionMode_strcmp_k4qzjr(b_this_MotionTypes[poses_0]
                    .f1.data, b_this_MotionTypes[poses_0].f1.size)) ^ 1))) {
                radius = b_this_MinTurningRadius;
                if (FlightMissionMode_strcmp_k4qzjrh(b_this_MotionTypes[poses_0]
                        .f1.data, b_this_MotionTypes[poses_0].f1.size)) {
                    radius = b_this_HelixRadius;
                } else if (FlightMissionMode_strcmp_k4qzjrhe
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    radius = b_this_HelixRadius;
                }

                count = 0;
                tempMotionLength_data_tmp = tempSamples->size[0];
                tempSamples->size[0] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
                    tempMotionLength_data_tmp);
                tempSamples->data[0] = 0.0;
                if (ab->size[1] != 0) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = static_cast<int32_T>(ab->size[1] + 1);
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = ab->size[1];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = 0.0;
                    }

                    count = ab->size[1];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] =
                            samples->data[static_cast<int32_T>(ab->
                            data[tempMotionLength_data_tmp] - 1)];
                    }

                    count = ab->size[1];
                    loop_ub = static_cast<int32_T>(ab->size[1] - 1);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        samples->data[static_cast<int32_T>(ab->
                            data[tempMotionLength_data_tmp] - 1)] = -1.0;
                    }
                }

                tempSamples->data[count] = c_x_data[poses_0];
                tempMotionLength_data_tmp = S->size[0];
                S->size[0] = tempSamples->size[0];
                FlightMissionMode_emxEnsureCapacity_real_T1_g(S,
                    tempMotionLength_data_tmp);
                loop_ub = tempSamples->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     static_cast<int32_T>(loop_ub - 1);
                        tempMotionLength_data_tmp++) {
                    S->data[tempMotionLength_data_tmp] = (tempSamples->
                        data[tempMotionLength_data_tmp] - intermediateLength) /
                        radius;
                }

                tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0] *
                    ns->size[1]);
                ns->size[0] = S->size[0];
                ns->size[1] = 6;
                FlightMissionMode_emxEnsureCapacity_real_T_c(ns,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(S->size[0] *
                    6) - 1);
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    ns->data[tempMotionLength_data_tmp] = 0.0;
                }

                tempMotionLength_data_tmp = z->size[0];
                z->size[0] = tempSamples->size[0];
                FlightMissionMode_emxEnsureCapacity_real_T1_g(z,
                    tempMotionLength_data_tmp);
                loop_ub = tempSamples->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     static_cast<int32_T>(loop_ub - 1);
                        tempMotionLength_data_tmp++) {
                    z->data[tempMotionLength_data_tmp] = tempStartPose_idx_2 +
                        tempSamples->data[tempMotionLength_data_tmp];
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
                    tempMotionLength_data_tmp = z->size[0];
                    z->size[0] = tempSamples->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(z,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        z->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp] /
                            TransformMatrix_tmp * samples_0 +
                            tempStartPose_idx_2;
                    }
                }

                if (FlightMissionMode_strcmp_k4qzjrh(b_this_MotionTypes[poses_0]
                        .f1.data, b_this_MotionTypes[poses_0].f1.size) ||
                        FlightMissionMode_strcmp_k4qzjrhe2
                        (b_this_MotionTypes[poses_0].f1.data,
                         b_this_MotionTypes[poses_0].f1.size)) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        tempSamples->data[count] = std::sin(tempSamples->
                            data[count]);
                    }

                    tempMotionLength_data_tmp = e_x->size[0];
                    e_x->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(e_x,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        e_x->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        e_x->data[count] = std::cos(e_x->data[count]);
                    }

                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = tempSamples->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = e_x->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + tempSamples->size[0])] = 1.0 - e_x->
                            data[tempMotionLength_data_tmp];
                    }

                    FlightMissionMode_mtimes_l(S_0, TransformMatrix, p);
                    samples_0 = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed,
                        9.8 * radius);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state_1
                            + S->data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] =
                            -samples_0;
                    }
                } else if (FlightMissionMode_strcmp_k4qzjrhe
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size) ||
                           FlightMissionMode_strcmp_k4qzjrhe2c
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        tempSamples->data[count] = std::sin(tempSamples->
                            data[count]);
                    }

                    tempMotionLength_data_tmp = e_x->size[0];
                    e_x->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(e_x,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        e_x->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        e_x->data[count] = std::cos(e_x->data[count]);
                    }

                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = tempSamples->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = e_x->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + tempSamples->size[0])] = e_x->
                            data[tempMotionLength_data_tmp] - 1.0;
                    }

                    FlightMissionMode_mtimes_l(S_0, TransformMatrix, p);
                    samples_0 = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed,
                        9.8 * radius);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state_1
                            - S->data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] =
                            samples_0;
                    }
                } else if (FlightMissionMode_strcmp_k4qzjrhe2c2
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    count = S->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = S->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + S->size[0])] = 0.0;
                    }

                    FlightMissionMode_mtimes_l(S_0, TransformMatrix, p);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    S_idx_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state[3];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (S_idx_0 - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] = 0.0;
                    }
                }

                if (ab->size[1] != 0) {
                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp < 6;
                            tempMotionLength_data_tmp++) {
                        for (tempMotionLength_data_tmp_0 = 0;
                                tempMotionLength_data_tmp_0 <= loop_ub;
                                tempMotionLength_data_tmp_0++) {
                            poses->data[static_cast<int32_T>(static_cast<int32_T>
                                (static_cast<int32_T>(count +
                                tempMotionLength_data_tmp_0) +
                                 static_cast<int32_T>(poses->size[0] *
                                tempMotionLength_data_tmp)) - 1)] = ns->data[
                                static_cast<int32_T>(tempMotionLength_data_tmp_0
                                + static_cast<int32_T>(ns->size[0] *
                                tempMotionLength_data_tmp))];
                        }
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>
                            (count + tempMotionLength_data_tmp) - 1)] = ns->
                            data[tempMotionLength_data_tmp];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + poses->size[0]) - 1)] =
                            -ns->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + ns->size[0])];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + static_cast<int32_T>
                            (poses->size[0] << 1)) - 1)] = -ns->data[
                            static_cast<int32_T>(tempMotionLength_data_tmp +
                            static_cast<int32_T>(ns->size[0] << 1))];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + static_cast<int32_T>
                            (poses->size[0] * 3)) - 1)] = -ns->data
                            [static_cast<int32_T>(tempMotionLength_data_tmp +
                            static_cast<int32_T>(ns->size[0] * 3))];
                    }
                }

                count = ns->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <
                        6; tempMotionLength_data_tmp++) {
                    state[tempMotionLength_data_tmp] = ns->data
                        [static_cast<int32_T>(static_cast<int32_T>(count +
                        static_cast<int32_T>(ns->size[0] *
                        tempMotionLength_data_tmp)) - 1)];
                }

                startIndex += static_cast<real_T>(ab->size[1]);
            }

            intermediateLength += tempMotionLength_data[poses_0];
            poses_0 = static_cast<int32_T>(poses_0 + 1);
        }

        FlightMissionMode_emxFree_real_T_n(&S_0);
        FlightMissionMode_emxFree_boolean_T_n(&tempSamplesIndex_0);
        FlightMissionMode_emxFree_int32_T_a(&ab);
        FlightMissionMode_emxFree_real_T_n(&e_x);
        FlightMissionMode_emxFree_real_T_n(&p);
        FlightMissionMode_emxFree_real_T_n(&z);
        FlightMissionMode_emxFree_real_T_n(&ns);
        FlightMissionMode_emxFree_real_T_n(&S);
        FlightMissionMode_emxFree_boolean_T_n(&tempSamplesIndex);
        loop_ub = poses->size[0];
        tempMotionLength_data_tmp = tempSamples->size[0];
        tempSamples->size[0] = poses->size[0];
        FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
            tempMotionLength_data_tmp);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp++)
        {
            tempSamples->data[tempMotionLength_data_tmp] = poses->data[
                static_cast<int32_T>(tempMotionLength_data_tmp +
                static_cast<int32_T>(poses->size[0] * 3))];
        }

        FlightMissionMode_wrapToPi_l(tempSamples);
        loop_ub = tempSamples->size[0];
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp++)
        {
            poses->data[static_cast<int32_T>(tempMotionLength_data_tmp +
                static_cast<int32_T>(poses->size[0] * 3))] = tempSamples->
                data[tempMotionLength_data_tmp];
        }

        FlightMissionMode_emxFree_real_T_n(&tempSamples);
    }
}

// Function for MATLAB Function: '<S199>/StartPointGenerator'
static void FlightMissionMode_genSegWP_lm(const
    uavDubinsConnection_FlightMissionMode_T *connectionObj, const real_T start[4],
    const real_T ende[4], emxArray_real_T_FlightMissionMode_T *segWayPoints,
    DW_FlightMissionMode_f_T *localDW)
{
    emxArray_real_T_FlightMissionMode_T *lengths;
    emxArray_real_T_FlightMissionMode_T *poses;
    real_T a__2_data[28];
    real_T apnd;
    real_T cdiff;
    real_T ndbl;
    real_T realStepSize;
    int32_T a__2_size;
    int32_T k;
    int32_T nm1d2;
    boolean_T guard1{ false };

    FlightMissionMode_uavDubinsConnection_connect_o(connectionObj, start, ende,
        localDW->pathSegObj_m.data, &localDW->pathSegObj_m.size, a__2_data,
        &a__2_size, localDW);
    realStepSize = localDW->pathSegObj_m.data[0].Length / 100.0;
    FlightMissionMode_emxInit_real_T_h(&lengths, 2);
    if (std::isnan(realStepSize)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
    } else if (std::isnan(localDW->pathSegObj_m.data[0].Length)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
    } else if (realStepSize == 0.0) {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else if ((0.0 < localDW->pathSegObj_m.data[0].Length) && (realStepSize <
                0.0)) {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else if ((localDW->pathSegObj_m.data[0].Length < 0.0) && (realStepSize >
                0.0)) {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else {
        guard1 = false;
        if (std::isinf(localDW->pathSegObj_m.data[0].Length)) {
            if (std::isinf(realStepSize)) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
                lengths->data[0] = (rtNaN);
            } else if (0.0 == localDW->pathSegObj_m.data[0].Length) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
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
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
                lengths->data[0] = 0.0;
            } else if (std::floor(realStepSize) == realStepSize) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                k = static_cast<int32_T>(std::floor(localDW->pathSegObj_m.data[0]
                    .Length / realStepSize));
                lengths->size[1] = static_cast<int32_T>(k + 1);
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
                for (a__2_size = 0; a__2_size <= k; a__2_size++) {
                    lengths->data[a__2_size] = realStepSize * static_cast<real_T>
                        (a__2_size);
                }
            } else {
                ndbl = std::floor(localDW->pathSegObj_m.data[0].Length /
                                  realStepSize + 0.5);
                apnd = ndbl * realStepSize;
                if (realStepSize > 0.0) {
                    cdiff = apnd - localDW->pathSegObj_m.data[0].Length;
                } else {
                    cdiff = localDW->pathSegObj_m.data[0].Length - apnd;
                }

                if (std::abs(cdiff) < 4.4408920985006262E-16 * std::abs
                        (localDW->pathSegObj_m.data[0].Length)) {
                    ndbl++;
                    apnd = localDW->pathSegObj_m.data[0].Length;
                } else if (cdiff > 0.0) {
                    apnd = (ndbl - 1.0) * realStepSize;
                } else {
                    ndbl++;
                }

                if (ndbl >= 0.0) {
                    a__2_size = static_cast<int32_T>(static_cast<int32_T>(ndbl)
                        - 1);
                } else {
                    a__2_size = -1;
                }

                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = static_cast<int32_T>(a__2_size + 1);
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
                if (static_cast<int32_T>(a__2_size + 1) > 0) {
                    lengths->data[0] = 0.0;
                    if (static_cast<int32_T>(a__2_size + 1) > 1) {
                        lengths->data[a__2_size] = apnd;
                        nm1d2 = static_cast<int32_T>(a__2_size / 2);
                        for (k = 1; static_cast<int32_T>(k - 1) <=
                                static_cast<int32_T>(nm1d2 - 2); k =
                                static_cast<int32_T>(k + 1)) {
                            ndbl = static_cast<real_T>(k) * realStepSize;
                            lengths->data[k] = ndbl;
                            lengths->data[static_cast<int32_T>(a__2_size - k)] =
                                apnd - ndbl;
                        }

                        if (static_cast<int32_T>(nm1d2 << 1) == a__2_size) {
                            lengths->data[nm1d2] = apnd / 2.0;
                        } else {
                            ndbl = static_cast<real_T>(nm1d2) * realStepSize;
                            lengths->data[nm1d2] = ndbl;
                            lengths->data[static_cast<int32_T>(nm1d2 + 1)] =
                                apnd - ndbl;
                        }
                    }
                }
            }
        }
    }

    FlightMissionMode_emxInit_real_T_h(&poses, 2);
    FlightMissionMode_uavDubinsPathSegment_interpolate_g1
        (localDW->pathSegObj_m.data[0].StartPose, localDW->pathSegObj_m.data[0].
         GoalPose, localDW->pathSegObj_m.data[0].FlightPathAngle,
         localDW->pathSegObj_m.data[0].AirSpeed, localDW->pathSegObj_m.data[0].
         MinTurningRadius, localDW->pathSegObj_m.data[0].HelixRadius,
         localDW->pathSegObj_m.data[0].MotionTypes, localDW->pathSegObj_m.data[0]
         .MotionLengths, localDW->pathSegObj_m.data[0].Length, lengths, poses);
    k = poses->size[0];
    nm1d2 = static_cast<int32_T>(segWayPoints->size[0] * segWayPoints->size[1]);
    segWayPoints->size[0] = poses->size[0];
    segWayPoints->size[1] = 3;
    FlightMissionMode_emxEnsureCapacity_real_T_c(segWayPoints, nm1d2);
    FlightMissionMode_emxFree_real_T_n(&lengths);
    for (a__2_size = 0; a__2_size < 3; a__2_size++) {
        for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(k - 1); nm1d2++) {
            segWayPoints->data[static_cast<int32_T>(nm1d2 + static_cast<int32_T>
                (segWayPoints->size[0] * a__2_size))] = poses->data
                [static_cast<int32_T>(nm1d2 + static_cast<int32_T>(poses->size[0]
                * a__2_size))];
        }
    }

    FlightMissionMode_emxFree_real_T_n(&poses);
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_nv(const
    real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
    varargin_4, real_T varargin_5, real_T varargin_6, const
    cell_wrap_10_FlightMissionMode_T varargin_7[4], const real_T varargin_8[4],
    uavDubinsPathSegment_FlightMissionMode_T *b_this)
{
    static const char_T d[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
        '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
        '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
        '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
        '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
        'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
        'Z', '[', '\\', ']', '^', '_', '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z', '{', '|', '}', '~', '\x7f' };

    real_T thetaWrap;
    int32_T k;
    b_this->MinTurningRadius = varargin_5;
    b_this->StartPose[0] = varargin_1[0];
    b_this->StartPose[1] = varargin_1[1];
    b_this->StartPose[2] = varargin_1[2];
    thetaWrap = mod_dBqh4Vat(varargin_1[3]);
    b_this->StartPose[3] = thetaWrap;
    if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
            (varargin_1[3] > 0.0)))) {
        b_this->StartPose[3] = 6.2831853071795862;
    }

    wrapToPi_iEuDNbvh(&b_this->StartPose[3]);
    b_this->GoalPose[0] = varargin_2[0];
    b_this->GoalPose[1] = varargin_2[1];
    b_this->GoalPose[2] = varargin_2[2];
    thetaWrap = mod_dBqh4Vat(varargin_2[3]);
    b_this->GoalPose[3] = thetaWrap;
    if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
            (varargin_2[3] > 0.0)))) {
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
    b_this->MotionTypes[1].f1.data[0] = d[static_cast<int32_T>
        (static_cast<int32_T>(static_cast<uint8_T>(varargin_7[1].f1.data[0])) &
         127)];
    b_this->MotionTypes[2].f1.size[0] = 1;
    b_this->MotionTypes[2].f1.size[1] = 1;
    b_this->MotionTypes[2].f1.data[0] = d[static_cast<int32_T>
        (static_cast<int32_T>(static_cast<uint8_T>(varargin_7[2].f1.data[0])) &
         127)];
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = varargin_7[3].f1.size[1];
    for (k = 0; k <= static_cast<int32_T>(varargin_7[3].f1.size[1] - 1); k =
            static_cast<int32_T>(k + 1)) {
        b_this->MotionTypes[3].f1.data[k] = d[static_cast<int32_T>
            (static_cast<uint8_T>(varargin_7[3].f1.data[k]))];
    }

    if (FlightMissionMode_strcmp_k4q(b_this->MotionTypes[0].f1.data,
            b_this->MotionTypes[0].f1.size)) {
        b_this->MotionTypes[0].f1.size[0] = 1;
        b_this->MotionTypes[0].f1.size[1] = 2;
        b_this->MotionTypes[0].f1.data[0] = 'H';
        b_this->MotionTypes[0].f1.data[1] = 'l';
    } else if (FlightMissionMode_strcmp_k4qz(b_this->MotionTypes[0].f1.data,
                b_this->MotionTypes[0].f1.size)) {
        b_this->MotionTypes[0].f1.size[0] = 1;
        b_this->MotionTypes[0].f1.size[1] = 2;
        b_this->MotionTypes[0].f1.data[0] = 'H';
        b_this->MotionTypes[0].f1.data[1] = 'r';
    } else if (FlightMissionMode_strcmp_k4qz(b_this->MotionTypes[3].f1.data,
                b_this->MotionTypes[3].f1.size)) {
        b_this->MotionTypes[3].f1.size[0] = 1;
        b_this->MotionTypes[3].f1.size[1] = 2;
        b_this->MotionTypes[3].f1.data[0] = 'H';
        b_this->MotionTypes[3].f1.data[1] = 'r';
    } else if (FlightMissionMode_strcmp_k4q(b_this->MotionTypes[3].f1.data,
                b_this->MotionTypes[3].f1.size)) {
        b_this->MotionTypes[3].f1.size[0] = 1;
        b_this->MotionTypes[3].f1.size[1] = 2;
        b_this->MotionTypes[3].f1.data[0] = 'H';
        b_this->MotionTypes[3].f1.data[1] = 'l';
    }

    b_this->Length = ((varargin_8[0] + varargin_8[1]) + varargin_8[2]) +
        varargin_8[3];
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_uavDubinsBuiltins_connect_n(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPose[4],
    const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
    real_T dpt_data[], const int32_T *dpt_size,
    uavDubinsPathSegment_FlightMissionMode_T pathSegObjs_data[], int32_T
    *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size,
    DW_FlightMissionMode_f_T *localDW)
{
    void* buildableObj_UAVDubinsBuildableObj;
    cell_wrap_10_FlightMissionMode_T m[4];
    cell_wrap_10_FlightMissionMode_T ac;
    cell_wrap_10_FlightMissionMode_T ad;
    cell_wrap_10_FlightMissionMode_T ae;
    cell_wrap_10_FlightMissionMode_T af;
    cell_wrap_10_FlightMissionMode_T bc;
    cell_wrap_10_FlightMissionMode_T bd;
    cell_wrap_10_FlightMissionMode_T be;
    cell_wrap_10_FlightMissionMode_T bf;
    cell_wrap_10_FlightMissionMode_T cc;
    cell_wrap_10_FlightMissionMode_T cd;
    cell_wrap_10_FlightMissionMode_T ce;
    cell_wrap_10_FlightMissionMode_T cf;
    cell_wrap_10_FlightMissionMode_T dc;
    cell_wrap_10_FlightMissionMode_T dd;
    cell_wrap_10_FlightMissionMode_T de;
    cell_wrap_10_FlightMissionMode_T df;
    cell_wrap_10_FlightMissionMode_T ec;
    cell_wrap_10_FlightMissionMode_T ed;
    cell_wrap_10_FlightMissionMode_T ee;
    cell_wrap_10_FlightMissionMode_T ef;
    cell_wrap_10_FlightMissionMode_T fc;
    cell_wrap_10_FlightMissionMode_T fd;
    cell_wrap_10_FlightMissionMode_T fe;
    cell_wrap_10_FlightMissionMode_T ff;
    cell_wrap_10_FlightMissionMode_T gc;
    cell_wrap_10_FlightMissionMode_T gd;
    cell_wrap_10_FlightMissionMode_T ge;
    cell_wrap_10_FlightMissionMode_T gf;
    cell_wrap_10_FlightMissionMode_T hc;
    cell_wrap_10_FlightMissionMode_T hd;
    cell_wrap_10_FlightMissionMode_T he;
    cell_wrap_10_FlightMissionMode_T hf;
    cell_wrap_10_FlightMissionMode_T ic;
    cell_wrap_10_FlightMissionMode_T id;
    cell_wrap_10_FlightMissionMode_T ie;
    cell_wrap_10_FlightMissionMode_T jc;
    cell_wrap_10_FlightMissionMode_T jd;
    cell_wrap_10_FlightMissionMode_T je;
    cell_wrap_10_FlightMissionMode_T jf;
    cell_wrap_10_FlightMissionMode_T kb;
    cell_wrap_10_FlightMissionMode_T kc;
    cell_wrap_10_FlightMissionMode_T kd;
    cell_wrap_10_FlightMissionMode_T ke;
    cell_wrap_10_FlightMissionMode_T kf;
    cell_wrap_10_FlightMissionMode_T lb;
    cell_wrap_10_FlightMissionMode_T lc;
    cell_wrap_10_FlightMissionMode_T ld;
    cell_wrap_10_FlightMissionMode_T le;
    cell_wrap_10_FlightMissionMode_T lf;
    cell_wrap_10_FlightMissionMode_T mb;
    cell_wrap_10_FlightMissionMode_T mc;
    cell_wrap_10_FlightMissionMode_T md;
    cell_wrap_10_FlightMissionMode_T me;
    cell_wrap_10_FlightMissionMode_T mf;
    cell_wrap_10_FlightMissionMode_T nb;
    cell_wrap_10_FlightMissionMode_T nc;
    cell_wrap_10_FlightMissionMode_T nd;
    cell_wrap_10_FlightMissionMode_T ne;
    cell_wrap_10_FlightMissionMode_T nf;
    cell_wrap_10_FlightMissionMode_T ob;
    cell_wrap_10_FlightMissionMode_T oc;
    cell_wrap_10_FlightMissionMode_T od;
    cell_wrap_10_FlightMissionMode_T oe;
    cell_wrap_10_FlightMissionMode_T of;
    cell_wrap_10_FlightMissionMode_T pb;
    cell_wrap_10_FlightMissionMode_T pc;
    cell_wrap_10_FlightMissionMode_T pd;
    cell_wrap_10_FlightMissionMode_T pe;
    cell_wrap_10_FlightMissionMode_T pf;
    cell_wrap_10_FlightMissionMode_T qb;
    cell_wrap_10_FlightMissionMode_T qc;
    cell_wrap_10_FlightMissionMode_T qd;
    cell_wrap_10_FlightMissionMode_T qe;
    cell_wrap_10_FlightMissionMode_T qf;
    cell_wrap_10_FlightMissionMode_T rb;
    cell_wrap_10_FlightMissionMode_T rc;
    cell_wrap_10_FlightMissionMode_T rd;
    cell_wrap_10_FlightMissionMode_T re;
    cell_wrap_10_FlightMissionMode_T rf;
    cell_wrap_10_FlightMissionMode_T sb;
    cell_wrap_10_FlightMissionMode_T sc;
    cell_wrap_10_FlightMissionMode_T sd;
    cell_wrap_10_FlightMissionMode_T se;
    cell_wrap_10_FlightMissionMode_T sf;
    cell_wrap_10_FlightMissionMode_T tb;
    cell_wrap_10_FlightMissionMode_T tc;
    cell_wrap_10_FlightMissionMode_T td;
    cell_wrap_10_FlightMissionMode_T te;
    cell_wrap_10_FlightMissionMode_T tf;
    cell_wrap_10_FlightMissionMode_T ub;
    cell_wrap_10_FlightMissionMode_T uc;
    cell_wrap_10_FlightMissionMode_T ud;
    cell_wrap_10_FlightMissionMode_T ue;
    cell_wrap_10_FlightMissionMode_T uf;
    cell_wrap_10_FlightMissionMode_T vb;
    cell_wrap_10_FlightMissionMode_T vc;
    cell_wrap_10_FlightMissionMode_T vd;
    cell_wrap_10_FlightMissionMode_T ve;
    cell_wrap_10_FlightMissionMode_T vf;
    cell_wrap_10_FlightMissionMode_T wb;
    cell_wrap_10_FlightMissionMode_T wc;
    cell_wrap_10_FlightMissionMode_T wd;
    cell_wrap_10_FlightMissionMode_T we;
    cell_wrap_10_FlightMissionMode_T wf;
    cell_wrap_10_FlightMissionMode_T xb;
    cell_wrap_10_FlightMissionMode_T xc;
    cell_wrap_10_FlightMissionMode_T xd;
    cell_wrap_10_FlightMissionMode_T xe;
    cell_wrap_10_FlightMissionMode_T yb;
    cell_wrap_10_FlightMissionMode_T yc;
    cell_wrap_10_FlightMissionMode_T yd;
    cell_wrap_10_FlightMissionMode_T ye;
    emxArray_real_T_FlightMissionMode_T *g;
    emxArray_real_T_FlightMissionMode_T *g1;
    emxArray_real_T_FlightMissionMode_T *g_0;
    emxArray_real_T_FlightMissionMode_T *ml;
    emxArray_real_T_FlightMissionMode_T *ml1;
    emxArray_real_T_FlightMissionMode_T *s;
    emxArray_real_T_FlightMissionMode_T *s1;
    real_T b_goalPose[4];
    real_T b_startPose[4];
    real_T ml1_0[4];
    real_T ml1_data[4];
    real_T l;
    real_T ml1_tmp;
    int32_T b_nRows;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
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
        FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable_o(obj->AirSpeed,
        obj->MaxRollAngle, obj->FlightPathAngleLimit, dpt_data, dpt_size);
    b_startPose[0] = startPose[0];
    b_goalPose[0] = goalPose[0];
    b_startPose[1] = startPose[1];
    b_goalPose[1] = goalPose[1];
    b_startPose[2] = startPose[2];
    b_goalPose[2] = goalPose[2];
    b_startPose[3] = startPose[3];
    b_goalPose[3] = goalPose[3];
    b_nRows = 1;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (flagOptimal) ^ 1))) {
        b_nRows = 28;
    }

    FlightMissionMode_emxInit_real_T_h(&s, 2);
    FlightMissionMode_emxInit_real_T_h(&g, 2);
    FlightMissionMode_emxInit_real_T_h(&ml, 2);
    xf_tmp = static_cast<int32_T>(b_nRows << 2);
    loop_ub_tmp = static_cast<int32_T>(s->size[0] * s->size[1]);
    s->size[0] = xf_tmp;
    s->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_c(s, loop_ub_tmp);
    loop_ub_tmp = static_cast<int32_T>(g->size[0] * g->size[1]);
    g->size[0] = xf_tmp;
    g->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g, loop_ub_tmp);
    mt_size_idx_0 = b_nRows;
    loop_ub_tmp = static_cast<int32_T>(ml->size[0] * ml->size[1]);
    ml->size[0] = xf_tmp;
    ml->size[1] = xf_tmp;
    FlightMissionMode_emxEnsureCapacity_real_T_c(ml, loop_ub_tmp);
    uavDubinsDistanceCodegen_real64(buildableObj_UAVDubinsBuildableObj,
        &b_startPose[0], 1U, &b_goalPose[0], 1U, flagOptimal, turningRadius,
        &s->data[0], &g->data[0], &localDW->b_fpa_data[0], &localDW->b_a_data[0],
        &localDW->mtr_data[0], &localDW->h_data[0], &localDW->mt_data[0],
        &ml->data[0]);
    b_nRows = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (flagOptimal) ^ 1))) {
        b_nRows = 27;
    }

    FlightMissionMode_emxInit_real_T_h(&g1, 2);
    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(s->size[0] * s->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g1->size[0] * g1->size[1]);
    g1->size[0] = static_cast<int32_T>(num_idx_1);
    g1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g1->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g1->size[0] * xf_tmp))] = s->data[static_cast<int32_T>(xf_tmp +
                static_cast<int32_T>(static_cast<int32_T>(tmp[0]) * loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_n(&s);
    FlightMissionMode_emxInit_real_T_h(&s1, 2);
    loop_ub_tmp = static_cast<int32_T>(s1->size[0] * s1->size[1]);
    s1->size[0] = static_cast<int32_T>(num_idx_1);
    s1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(s1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
        s1->data[xf_tmp] = g1->data[xf_tmp];
    }

    FlightMissionMode_emxInit_real_T_h(&g_0, 2);
    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(g->size[0] * g->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
    g_0->size[0] = static_cast<int32_T>(num_idx_1);
    g_0->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g_0, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g_0->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g_0->size[0] * xf_tmp))] = g->data[static_cast<int32_T>(xf_tmp
                + static_cast<int32_T>(static_cast<int32_T>(tmp[0]) *
                loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_n(&g);
    loop_ub_tmp = static_cast<int32_T>(g1->size[0] * g1->size[1]);
    g1->size[0] = static_cast<int32_T>(num_idx_1);
    g1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g1, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub - 1); xf_tmp++) {
        g1->data[xf_tmp] = g_0->data[xf_tmp];
    }

    num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>(
        static_cast<int32_T>(ml->size[0] * ml->size[1])) / 4.0));
    tmp[0] = 4;
    tmp[1] = num_idx_1;
    loop_ub_tmp = static_cast<int32_T>(g_0->size[0] * g_0->size[1]);
    g_0->size[0] = static_cast<int32_T>(num_idx_1);
    g_0->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(g_0, loop_ub_tmp);
    loop_ub = static_cast<int32_T>(num_idx_1);
    for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= static_cast<int32_T>(loop_ub - 1);
                loop_ub_tmp++) {
            g_0->data[static_cast<int32_T>(loop_ub_tmp + static_cast<int32_T>
                (g_0->size[0] * xf_tmp))] = ml->data[static_cast<int32_T>(xf_tmp
                + static_cast<int32_T>(static_cast<int32_T>(tmp[0]) *
                loop_ub_tmp))];
        }
    }

    FlightMissionMode_emxFree_real_T_n(&ml);
    FlightMissionMode_emxInit_real_T_h(&ml1, 2);
    loop_ub_tmp = static_cast<int32_T>(ml1->size[0] * ml1->size[1]);
    ml1->size[0] = static_cast<int32_T>(num_idx_1);
    ml1->size[1] = 4;
    FlightMissionMode_emxEnsureCapacity_real_T_c(ml1, loop_ub_tmp);
    loop_ub_tmp = static_cast<int32_T>(static_cast<int32_T>(num_idx_1) << 2);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub_tmp - 1); xf_tmp++)
    {
        ml1->data[xf_tmp] = g_0->data[xf_tmp];
    }

    FlightMissionMode_emxFree_real_T_n(&g_0);
    loop_ub_tmp = static_cast<int32_T>(mt_size_idx_0 * mt_size_idx_0);
    for (xf_tmp = 0; xf_tmp <= static_cast<int32_T>(loop_ub_tmp - 1); xf_tmp++)
    {
        localDW->mt_data[xf_tmp]++;
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
        *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>(
            static_cast<int32_T>(b_nRows + 1)));
        for (loop_ub_tmp = 0; loop_ub_tmp <= b_nRows; loop_ub_tmp = static_cast<
                int32_T>(loop_ub_tmp + 1)) {
            l++;
            ml1_tmp = localDW->mt_data[static_cast<int32_T>(static_cast<int32_T>
                (l) - 1)];
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

            b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>
                (l) - 1)];
            b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l)
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
            ml1_0[0] = ml1_tmp;
            ml1_data[0] = ml1_tmp;
            b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + s1->size[0]) - 1)];
            b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + g1->size[0]) - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + ml1->size[0]) - 1)];
            ml1_0[1] = ml1_tmp;
            ml1_data[1] = ml1_tmp;
            b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1))
                - 1)];
            b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1))
                - 1)];
            ml1_0[2] = ml1_tmp;
            ml1_data[2] = ml1_tmp;
            b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3))
                - 1)];
            b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3))
                - 1)];
            ml1_0[3] = ml1_tmp;
            ml1_data[3] = ml1_tmp;
            FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_nv
                (b_startPose, b_goalPose, localDW->b_fpa_data
                 [static_cast<int32_T>(static_cast<int32_T>(l) - 1)],
                 localDW->b_a_data[0], localDW->mtr_data[0], localDW->h_data[
                 static_cast<int32_T>(static_cast<int32_T>(l) - 1)], m, ml1_0,
                 &pathSegObjs_data[loop_ub_tmp]);
            pathCosts_data[loop_ub_tmp] = FlightMissionMode_sum_l(ml1_data);
        }
    } else {
        *pathSegObjs_size = static_cast<int32_T>(static_cast<int16_T>(
            static_cast<int32_T>(b_nRows + 1)));
        for (loop_ub_tmp = 1; static_cast<int32_T>(loop_ub_tmp - 1) <= b_nRows;
                loop_ub_tmp = static_cast<int32_T>(loop_ub_tmp + 1)) {
            l++;
            if (1 == loop_ub_tmp) {
                m[0] = kb;
                m[1] = lb;
                m[2] = mb;
                m[3] = nb;
            }

            if (2 == loop_ub_tmp) {
                m[0] = ob;
                m[1] = pb;
                m[2] = qb;
                m[3] = rb;
            }

            if (3 == loop_ub_tmp) {
                m[0] = sb;
                m[1] = tb;
                m[2] = ub;
                m[3] = vb;
            }

            if (4 == loop_ub_tmp) {
                m[0] = wb;
                m[1] = xb;
                m[2] = yb;
                m[3] = ac;
            }

            if (5 == loop_ub_tmp) {
                m[0] = bc;
                m[1] = cc;
                m[2] = dc;
                m[3] = ec;
            }

            if (6 == loop_ub_tmp) {
                m[0] = fc;
                m[1] = gc;
                m[2] = hc;
                m[3] = ic;
            }

            if (7 == loop_ub_tmp) {
                m[0] = jc;
                m[1] = kc;
                m[2] = lc;
                m[3] = mc;
            }

            if (8 == loop_ub_tmp) {
                m[0] = nc;
                m[1] = oc;
                m[2] = pc;
                m[3] = qc;
            }

            if (9 == loop_ub_tmp) {
                m[0] = rc;
                m[1] = sc;
                m[2] = tc;
                m[3] = uc;
            }

            if (10 == loop_ub_tmp) {
                m[0] = vc;
                m[1] = wc;
                m[2] = xc;
                m[3] = yc;
            }

            if (11 == loop_ub_tmp) {
                m[0] = ad;
                m[1] = bd;
                m[2] = cd;
                m[3] = dd;
            }

            if (12 == loop_ub_tmp) {
                m[0] = ed;
                m[1] = fd;
                m[2] = gd;
                m[3] = hd;
            }

            if (13 == loop_ub_tmp) {
                m[0] = id;
                m[1] = jd;
                m[2] = kd;
                m[3] = ld;
            }

            if (14 == loop_ub_tmp) {
                m[0] = md;
                m[1] = nd;
                m[2] = od;
                m[3] = pd;
            }

            if (15 == loop_ub_tmp) {
                m[0] = qd;
                m[1] = rd;
                m[2] = sd;
                m[3] = td;
            }

            if (16 == loop_ub_tmp) {
                m[0] = ud;
                m[1] = vd;
                m[2] = wd;
                m[3] = xd;
            }

            if (17 == loop_ub_tmp) {
                m[0] = yd;
                m[1] = ae;
                m[2] = be;
                m[3] = ce;
            }

            if (18 == loop_ub_tmp) {
                m[0] = de;
                m[1] = ee;
                m[2] = fe;
                m[3] = ge;
            }

            if (19 == loop_ub_tmp) {
                m[0] = he;
                m[1] = ie;
                m[2] = je;
                m[3] = ke;
            }

            if (20 == loop_ub_tmp) {
                m[0] = le;
                m[1] = me;
                m[2] = ne;
                m[3] = oe;
            }

            if (21 == loop_ub_tmp) {
                m[0] = pe;
                m[1] = qe;
                m[2] = re;
                m[3] = se;
            }

            if (22 == loop_ub_tmp) {
                m[0] = te;
                m[1] = ue;
                m[2] = ve;
                m[3] = we;
            }

            if (23 == loop_ub_tmp) {
                m[0] = xe;
                m[1] = ye;
                m[2] = af;
                m[3] = bf;
            }

            if (24 == loop_ub_tmp) {
                m[0] = cf;
                m[1] = df;
                m[2] = ef;
                m[3] = ff;
            }

            if (25 == loop_ub_tmp) {
                m[0] = gf;
                m[1] = hf;
                m[2] = jf;
                m[3] = kf;
            }

            if (26 == loop_ub_tmp) {
                m[0] = lf;
                m[1] = mf;
                m[2] = nf;
                m[3] = of;
            }

            if (27 == loop_ub_tmp) {
                m[0] = pf;
                m[1] = qf;
                m[2] = rf;
                m[3] = sf;
            }

            if (28 == loop_ub_tmp) {
                m[0] = tf;
                m[1] = uf;
                m[2] = vf;
                m[3] = wf;
            }

            b_startPose[0] = s1->data[static_cast<int32_T>(static_cast<int32_T>
                (l) - 1)];
            b_goalPose[0] = g1->data[static_cast<int32_T>(static_cast<int32_T>(l)
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(l) - 1)];
            ml1_0[0] = ml1_tmp;
            ml1_data[0] = ml1_tmp;
            b_startPose[1] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + s1->size[0]) - 1)];
            b_goalPose[1] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + g1->size[0]) - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + ml1->size[0]) - 1)];
            ml1_0[1] = ml1_tmp;
            ml1_data[1] = ml1_tmp;
            b_startPose[2] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] << 1))
                - 1)];
            b_goalPose[2] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] << 1))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] << 1))
                - 1)];
            ml1_0[2] = ml1_tmp;
            ml1_data[2] = ml1_tmp;
            b_startPose[3] = s1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(s1->size[0] * 3))
                - 1)];
            b_goalPose[3] = g1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(g1->size[0] * 3))
                - 1)];
            ml1_tmp = ml1->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(l) + static_cast<int32_T>(ml1->size[0] * 3))
                - 1)];
            ml1_0[3] = ml1_tmp;
            ml1_data[3] = ml1_tmp;
            FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_nv
                (b_startPose, b_goalPose, localDW->b_fpa_data
                 [static_cast<int32_T>(static_cast<int32_T>(l) - 1)],
                 localDW->b_a_data[0], localDW->mtr_data[0], localDW->h_data[
                 static_cast<int32_T>(static_cast<int32_T>(l) - 1)], m, ml1_0,
                 &pathSegObjs_data[static_cast<int32_T>(loop_ub_tmp - 1)]);
            pathCosts_data[static_cast<int32_T>(loop_ub_tmp - 1)] =
                FlightMissionMode_sum_l(ml1_data);
        }
    }

    FlightMissionMode_emxFree_real_T_n(&ml1);
    FlightMissionMode_emxFree_real_T_n(&g1);
    FlightMissionMode_emxFree_real_T_n(&s1);
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_uavDubinsConnection_connect_c(const
    uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPoses[4],
    const real_T goalPoses[4], uavDubinsPathSegment_FlightMissionMode_T
    pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
    int32_T *pathCosts_size, DW_FlightMissionMode_f_T *localDW)
{
    matlabshared_autonomous_core_internal_NameValueParser_FlightMissionMode_T
        parser;
    real_T idx_data[28];
    int32_T tmp_size[2];
    int32_T flagOptimal;
    int32_T idx_size;
    char_T tmp_data[7];
    FlightMissionMode_NameValueParser_NameValueParser_p(&parser);
    parser.ParsedResults = parser.Defaults;
    flagOptimal = 1;
    FlightMissionMode_validatestring_o(parser.ParsedResults.f1, tmp_data,
        tmp_size);
    if (FlightMissionMode_strcmp_k4(tmp_data, tmp_size)) {
        flagOptimal = 0;
    }

    FlightMissionMode_uavDubinsConnection_findDisabledIndices_i(idx_data,
        &idx_size);
    FlightMissionMode_uavDubinsBuiltins_connect_n(obj, startPoses, goalPoses,
        flagOptimal == 1, obj->MinTurningRadius, idx_data, &idx_size,
        pathSegObjs_data, pathSegObjs_size, pathCosts_data, pathCosts_size,
        localDW);
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_strcmp_k4qzj(const
    cell_wrap_10_FlightMissionMode_T a[4], boolean_T b_bool[4])
{
    b_bool[0] = false;
    if ((a[0].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[0].f1.data[0] != 'N') ^ 1)))) {
        b_bool[0] = true;
    }

    b_bool[1] = false;
    if ((a[1].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[1].f1.data[0] != 'N') ^ 1)))) {
        b_bool[1] = true;
    }

    b_bool[2] = false;
    if ((a[2].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[2].f1.data[0] != 'N') ^ 1)))) {
        b_bool[2] = true;
    }

    b_bool[3] = false;
    if ((a[3].f1.size[1] == 1) && (static_cast<boolean_T>(static_cast<int32_T>
            ((a[3].f1.data[0] != 'N') ^ 1)))) {
        b_bool[3] = true;
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_uavDubinsPathSegment_interpolate_e(const real_T
    b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
    b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
    b_this_MinTurningRadius, real_T b_this_HelixRadius, const
    cell_wrap_10_FlightMissionMode_T b_this_MotionTypes[4], const real_T
    b_this_MotionLengths[4], real_T b_this_Length,
    emxArray_real_T_FlightMissionMode_T *samples,
    emxArray_real_T_FlightMissionMode_T *poses)
{
    emxArray_boolean_T_FlightMissionMode_T *tempSamplesIndex;
    emxArray_boolean_T_FlightMissionMode_T *tempSamplesIndex_0;
    emxArray_int32_T_FlightMissionMode_T *ab;
    emxArray_real_T_FlightMissionMode_T *S;
    emxArray_real_T_FlightMissionMode_T *S_0;
    emxArray_real_T_FlightMissionMode_T *e_x;
    emxArray_real_T_FlightMissionMode_T *ns;
    emxArray_real_T_FlightMissionMode_T *p;
    emxArray_real_T_FlightMissionMode_T *tempSamples;
    emxArray_real_T_FlightMissionMode_T *z;
    real_T state[6];
    real_T TransformMatrix[4];
    real_T c_x_data[4];
    real_T tempMotionLength_data[4];
    real_T TransformMatrix_tmp;
    real_T b_b_tmp;
    real_T intermediateLength;
    real_T radius;
    real_T samples_0;
    real_T startIndex;
    real_T state_0;
    real_T state_1;
    real_T tempStartPose_idx_2;
    int32_T c_x_size[2];
    int32_T tempMotionLength_size[2];
    int32_T S_idx_0;
    int32_T count;
    int32_T loop_ub;
    int32_T poses_0;
    int32_T tempMotionLength_data_tmp;
    int32_T tempMotionLength_data_tmp_0;
    boolean_T tmp[4];
    poses->size[0] = 0;
    poses->size[1] = 6;
    if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
            isnan(b_this_Length)) ^ 1))) && (samples->size[1] != 0)) {
        tempStartPose_idx_2 = -b_this_StartPose[2];
        tempMotionLength_data_tmp = static_cast<int32_T>(poses->size[0] *
            poses->size[1]);
        poses->size[0] = samples->size[1];
        poses->size[1] = 6;
        FlightMissionMode_emxEnsureCapacity_real_T_c(poses,
            tempMotionLength_data_tmp);
        loop_ub = static_cast<int32_T>(static_cast<int32_T>(samples->size[1] * 6)
            - 1);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <= loop_ub;
             tempMotionLength_data_tmp++) {
            poses->data[tempMotionLength_data_tmp] = 0.0;
        }

        b_b_tmp = std::cos(std::abs(b_this_FlightPathAngle));
        tempMotionLength_data_tmp = static_cast<int32_T>(samples->size[0] *
            samples->size[1]);
        samples->size[0] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_c(samples,
            tempMotionLength_data_tmp);
        loop_ub = static_cast<int32_T>(samples->size[1] - 1);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <= loop_ub;
             tempMotionLength_data_tmp++) {
            samples->data[tempMotionLength_data_tmp] *= b_b_tmp;
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
        FlightMissionMode_strcmp_k4qzj(b_this_MotionTypes, tmp);
        if (FlightMissionMode_any_e(tmp)) {
            tempMotionLength_size[0] = 1;
            tempMotionLength_size[1] = 3;
            tempMotionLength_data[0] = TransformMatrix[0];
            tempMotionLength_data[1] = TransformMatrix[1];
            tempMotionLength_data[2] = TransformMatrix[2];
        }

        FlightMissionMode_useConstantDim_h(tempMotionLength_data,
            tempMotionLength_size, c_x_data, c_x_size);
        FlightMissionMode_sort_o4u(samples);
        intermediateLength = 0.0;
        startIndex = 1.0;
        state[0] = b_this_StartPose[0];
        state[1] = -b_this_StartPose[1];
        state[3] = -b_this_StartPose[3];
        poses_0 = 0;
        FlightMissionMode_emxInit_boolean_T_c(&tempSamplesIndex, 2);
        FlightMissionMode_emxInit_real_T1_o(&tempSamples, 1);
        FlightMissionMode_emxInit_real_T1_o(&S, 1);
        FlightMissionMode_emxInit_real_T_h(&ns, 2);
        FlightMissionMode_emxInit_real_T1_o(&z, 1);
        FlightMissionMode_emxInit_real_T_h(&p, 2);
        FlightMissionMode_emxInit_real_T1_o(&e_x, 1);
        FlightMissionMode_emxInit_int32_T_k(&ab, 2);
        FlightMissionMode_emxInit_boolean_T_c(&tempSamplesIndex_0, 2);
        FlightMissionMode_emxInit_real_T_h(&S_0, 2);
        while (poses_0 <= static_cast<int32_T>(tempMotionLength_size[1] - 1)) {
            if (static_cast<int32_T>(poses_0 + 1) == 1) {
                tempMotionLength_data_tmp = static_cast<int32_T>
                    (tempSamplesIndex->size[0] * tempSamplesIndex->size[1]);
                tempSamplesIndex->size[0] = 1;
                tempSamplesIndex->size[1] = samples->size[1];
                FlightMissionMode_emxEnsureCapacity_boolean_T_f(tempSamplesIndex,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(samples->size[1] - 1);
                radius = (intermediateLength + tempMotionLength_data[0]) +
                    1.0E-6;
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    samples_0 = samples->data[tempMotionLength_data_tmp];
                    tempSamplesIndex->data[tempMotionLength_data_tmp] =
                        static_cast<boolean_T>(static_cast<int32_T>((samples_0 >=
                        intermediateLength) & (samples_0 <= radius)));
                }
            } else {
                tempMotionLength_data_tmp = static_cast<int32_T>
                    (tempSamplesIndex->size[0] * tempSamplesIndex->size[1]);
                tempSamplesIndex->size[0] = 1;
                tempSamplesIndex->size[1] = samples->size[1];
                FlightMissionMode_emxEnsureCapacity_boolean_T_f(tempSamplesIndex,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(samples->size[1] - 1);
                radius = (intermediateLength + tempMotionLength_data[poses_0]) +
                    1.0E-6;
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    samples_0 = samples->data[tempMotionLength_data_tmp];
                    tempSamplesIndex->data[tempMotionLength_data_tmp] =
                        static_cast<boolean_T>(static_cast<int32_T>((samples_0 >
                        intermediateLength) & (samples_0 <= radius)));
                }
            }

            tempMotionLength_data_tmp = static_cast<int32_T>
                (tempSamplesIndex_0->size[0] * tempSamplesIndex_0->size[1]);
            tempSamplesIndex_0->size[0] = 1;
            tempSamplesIndex_0->size[1] = tempSamplesIndex->size[1];
            FlightMissionMode_emxEnsureCapacity_boolean_T_f(tempSamplesIndex_0,
                tempMotionLength_data_tmp);
            loop_ub = tempSamplesIndex->size[1];
            for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                    static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp
                    ++) {
                tempSamplesIndex_0->data[tempMotionLength_data_tmp] =
                    tempSamplesIndex->data[tempMotionLength_data_tmp];
            }

            FlightMissionMode_eml_find_f(tempSamplesIndex_0, ab);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (FlightMissionMode_strcmp_k4qzjr(b_this_MotionTypes[poses_0]
                    .f1.data, b_this_MotionTypes[poses_0].f1.size)) ^ 1))) {
                radius = b_this_MinTurningRadius;
                if (FlightMissionMode_strcmp_k4qzjrh(b_this_MotionTypes[poses_0]
                        .f1.data, b_this_MotionTypes[poses_0].f1.size)) {
                    radius = b_this_HelixRadius;
                } else if (FlightMissionMode_strcmp_k4qzjrhe
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    radius = b_this_HelixRadius;
                }

                count = 0;
                tempMotionLength_data_tmp = tempSamples->size[0];
                tempSamples->size[0] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
                    tempMotionLength_data_tmp);
                tempSamples->data[0] = 0.0;
                if (ab->size[1] != 0) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = static_cast<int32_T>(ab->size[1] + 1);
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = ab->size[1];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = 0.0;
                    }

                    count = ab->size[1];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] =
                            samples->data[static_cast<int32_T>(ab->
                            data[tempMotionLength_data_tmp] - 1)];
                    }

                    count = ab->size[1];
                    loop_ub = static_cast<int32_T>(ab->size[1] - 1);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        samples->data[static_cast<int32_T>(ab->
                            data[tempMotionLength_data_tmp] - 1)] = -1.0;
                    }
                }

                tempSamples->data[count] = c_x_data[poses_0];
                tempMotionLength_data_tmp = S->size[0];
                S->size[0] = tempSamples->size[0];
                FlightMissionMode_emxEnsureCapacity_real_T1_g(S,
                    tempMotionLength_data_tmp);
                loop_ub = tempSamples->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     static_cast<int32_T>(loop_ub - 1);
                        tempMotionLength_data_tmp++) {
                    S->data[tempMotionLength_data_tmp] = (tempSamples->
                        data[tempMotionLength_data_tmp] - intermediateLength) /
                        radius;
                }

                tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0] *
                    ns->size[1]);
                ns->size[0] = S->size[0];
                ns->size[1] = 6;
                FlightMissionMode_emxEnsureCapacity_real_T_c(ns,
                    tempMotionLength_data_tmp);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(S->size[0] *
                    6) - 1);
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     loop_ub; tempMotionLength_data_tmp++) {
                    ns->data[tempMotionLength_data_tmp] = 0.0;
                }

                tempMotionLength_data_tmp = z->size[0];
                z->size[0] = tempSamples->size[0];
                FlightMissionMode_emxEnsureCapacity_real_T1_g(z,
                    tempMotionLength_data_tmp);
                loop_ub = tempSamples->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                     static_cast<int32_T>(loop_ub - 1);
                        tempMotionLength_data_tmp++) {
                    z->data[tempMotionLength_data_tmp] = tempStartPose_idx_2 +
                        tempSamples->data[tempMotionLength_data_tmp];
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
                    tempMotionLength_data_tmp = z->size[0];
                    z->size[0] = tempSamples->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(z,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        z->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp] /
                            TransformMatrix_tmp * samples_0 +
                            tempStartPose_idx_2;
                    }
                }

                if (FlightMissionMode_strcmp_k4qzjrh(b_this_MotionTypes[poses_0]
                        .f1.data, b_this_MotionTypes[poses_0].f1.size) ||
                        FlightMissionMode_strcmp_k4qzjrhe2
                        (b_this_MotionTypes[poses_0].f1.data,
                         b_this_MotionTypes[poses_0].f1.size)) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        tempSamples->data[count] = std::sin(tempSamples->
                            data[count]);
                    }

                    tempMotionLength_data_tmp = e_x->size[0];
                    e_x->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(e_x,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        e_x->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        e_x->data[count] = std::cos(e_x->data[count]);
                    }

                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = tempSamples->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = e_x->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + tempSamples->size[0])] = 1.0 - e_x->
                            data[tempMotionLength_data_tmp];
                    }

                    FlightMissionMode_mtimes_l(S_0, TransformMatrix, p);
                    samples_0 = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed,
                        9.8 * radius);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state_1
                            + S->data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] =
                            -samples_0;
                    }
                } else if (FlightMissionMode_strcmp_k4qzjrhe
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size) ||
                           FlightMissionMode_strcmp_k4qzjrhe2c
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    tempMotionLength_data_tmp = tempSamples->size[0];
                    tempSamples->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        tempSamples->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        tempSamples->data[count] = std::sin(tempSamples->
                            data[count]);
                    }

                    tempMotionLength_data_tmp = e_x->size[0];
                    e_x->size[0] = S->size[0];
                    FlightMissionMode_emxEnsureCapacity_real_T1_g(e_x,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        e_x->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (count = 0; count <= static_cast<int32_T>(S->size[0] - 1);
                         count = static_cast<int32_T>(count + 1)) {
                        e_x->data[count] = std::cos(e_x->data[count]);
                    }

                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = tempSamples->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = tempSamples->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = tempSamples->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = e_x->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + tempSamples->size[0])] = e_x->
                            data[tempMotionLength_data_tmp] - 1.0;
                    }

                    FlightMissionMode_mtimes_l(S_0, TransformMatrix, p);
                    samples_0 = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed,
                        9.8 * radius);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    state_1 = state[3];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state_1
                            - S->data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] =
                            samples_0;
                    }
                } else if (FlightMissionMode_strcmp_k4qzjrhe2c2
                           (b_this_MotionTypes[poses_0].f1.data,
                            b_this_MotionTypes[poses_0].f1.size)) {
                    count = S->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(S_0->size[0]
                        * S_0->size[1]);
                    S_0->size[0] = S->size[0];
                    S_0->size[1] = 2;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(S_0,
                        tempMotionLength_data_tmp);
                    loop_ub = S->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        S_0->data[tempMotionLength_data_tmp] = S->
                            data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        S_0->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + S->size[0])] = 0.0;
                    }

                    FlightMissionMode_mtimes_l(S_0, TransformMatrix, p);
                    TransformMatrix_tmp = state[0];
                    state_0 = state[1];
                    count = S->size[0];
                    tempMotionLength_data_tmp_0 = S->size[0];
                    S_idx_0 = S->size[0];
                    loop_ub = p->size[0];
                    tempMotionLength_data_tmp = static_cast<int32_T>(ns->size[0]
                        * ns->size[1]);
                    ns->size[0] = p->size[0];
                    ns->size[1] = 6;
                    FlightMissionMode_emxEnsureCapacity_real_T_c(ns,
                        tempMotionLength_data_tmp);
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[tempMotionLength_data_tmp] = p->
                            data[tempMotionLength_data_tmp] * radius +
                            TransformMatrix_tmp;
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + ns->size[0])] = p->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + p->size[0])] * radius +
                            state_0;
                    }

                    loop_ub = z->size[0];
                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (loop_ub - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 1))] = z->
                            data[tempMotionLength_data_tmp];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (count - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 3))] = state[3];
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (tempMotionLength_data_tmp_0 - 1);
                            tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] << 2))] =
                            b_this_FlightPathAngle;
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= static_cast<int32_T>
                            (S_idx_0 - 1); tempMotionLength_data_tmp++) {
                        ns->data[static_cast<int32_T>(tempMotionLength_data_tmp
                            + static_cast<int32_T>(ns->size[0] * 5))] = 0.0;
                    }
                }

                if (ab->size[1] != 0) {
                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp < 6;
                            tempMotionLength_data_tmp++) {
                        for (tempMotionLength_data_tmp_0 = 0;
                                tempMotionLength_data_tmp_0 <= loop_ub;
                                tempMotionLength_data_tmp_0++) {
                            poses->data[static_cast<int32_T>(static_cast<int32_T>
                                (static_cast<int32_T>(count +
                                tempMotionLength_data_tmp_0) +
                                 static_cast<int32_T>(poses->size[0] *
                                tempMotionLength_data_tmp)) - 1)] = ns->data[
                                static_cast<int32_T>(tempMotionLength_data_tmp_0
                                + static_cast<int32_T>(ns->size[0] *
                                tempMotionLength_data_tmp))];
                        }
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>
                            (count + tempMotionLength_data_tmp) - 1)] = ns->
                            data[tempMotionLength_data_tmp];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + poses->size[0]) - 1)] =
                            -ns->data[static_cast<int32_T>
                            (tempMotionLength_data_tmp + ns->size[0])];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + static_cast<int32_T>
                            (poses->size[0] << 1)) - 1)] = -ns->data[
                            static_cast<int32_T>(tempMotionLength_data_tmp +
                            static_cast<int32_T>(ns->size[0] << 1))];
                    }

                    if (startIndex > (startIndex + static_cast<real_T>(ab->size
                            [1])) - 1.0) {
                        count = 1;
                    } else {
                        count = static_cast<int32_T>(startIndex);
                    }

                    if (1 > static_cast<int32_T>(ns->size[0] - 1)) {
                        loop_ub = -1;
                    } else {
                        loop_ub = static_cast<int32_T>(ns->size[0] - 2);
                    }

                    for (tempMotionLength_data_tmp = 0;
                            tempMotionLength_data_tmp <= loop_ub;
                            tempMotionLength_data_tmp++) {
                        poses->data[static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(count +
                            tempMotionLength_data_tmp) + static_cast<int32_T>
                            (poses->size[0] * 3)) - 1)] = -ns->data
                            [static_cast<int32_T>(tempMotionLength_data_tmp +
                            static_cast<int32_T>(ns->size[0] * 3))];
                    }
                }

                count = ns->size[0];
                for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <
                        6; tempMotionLength_data_tmp++) {
                    state[tempMotionLength_data_tmp] = ns->data
                        [static_cast<int32_T>(static_cast<int32_T>(count +
                        static_cast<int32_T>(ns->size[0] *
                        tempMotionLength_data_tmp)) - 1)];
                }

                startIndex += static_cast<real_T>(ab->size[1]);
            }

            intermediateLength += tempMotionLength_data[poses_0];
            poses_0 = static_cast<int32_T>(poses_0 + 1);
        }

        FlightMissionMode_emxFree_real_T_n(&S_0);
        FlightMissionMode_emxFree_boolean_T_n(&tempSamplesIndex_0);
        FlightMissionMode_emxFree_int32_T_a(&ab);
        FlightMissionMode_emxFree_real_T_n(&e_x);
        FlightMissionMode_emxFree_real_T_n(&p);
        FlightMissionMode_emxFree_real_T_n(&z);
        FlightMissionMode_emxFree_real_T_n(&ns);
        FlightMissionMode_emxFree_real_T_n(&S);
        FlightMissionMode_emxFree_boolean_T_n(&tempSamplesIndex);
        loop_ub = poses->size[0];
        tempMotionLength_data_tmp = tempSamples->size[0];
        tempSamples->size[0] = poses->size[0];
        FlightMissionMode_emxEnsureCapacity_real_T1_g(tempSamples,
            tempMotionLength_data_tmp);
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp++)
        {
            tempSamples->data[tempMotionLength_data_tmp] = poses->data[
                static_cast<int32_T>(tempMotionLength_data_tmp +
                static_cast<int32_T>(poses->size[0] * 3))];
        }

        FlightMissionMode_wrapToPi_l(tempSamples);
        loop_ub = tempSamples->size[0];
        for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                static_cast<int32_T>(loop_ub - 1); tempMotionLength_data_tmp++)
        {
            poses->data[static_cast<int32_T>(tempMotionLength_data_tmp +
                static_cast<int32_T>(poses->size[0] * 3))] = tempSamples->
                data[tempMotionLength_data_tmp];
        }

        FlightMissionMode_emxFree_real_T_n(&tempSamples);
    }
}

// Function for MATLAB Function: '<S109>/WayPointGenerator'
static void FlightMissionMode_genSegWP_j(const
    uavDubinsConnection_FlightMissionMode_T *connectionObj, const real_T start[4],
    const real_T ende[4], real_T b_stepSize, emxArray_real_T_FlightMissionMode_T
    *segWayPoints, DW_FlightMissionMode_f_T *localDW)
{
    emxArray_real_T_FlightMissionMode_T *lengths;
    emxArray_real_T_FlightMissionMode_T *poses;
    real_T a__1_data[28];
    real_T apnd;
    real_T cdiff;
    real_T ndbl;
    real_T realStepSize;
    int32_T a__1_size;
    int32_T k;
    int32_T nm1d2;
    boolean_T guard1{ false };

    FlightMissionMode_uavDubinsConnection_connect_c(connectionObj, start, ende,
        localDW->pathSegObj_c.data, &localDW->pathSegObj_c.size, a__1_data,
        &a__1_size, localDW);
    realStepSize = localDW->pathSegObj_c.data[0].Length / std::round
        (localDW->pathSegObj_c.data[0].Length / b_stepSize);
    FlightMissionMode_emxInit_real_T_h(&lengths, 2);
    if (std::isnan(realStepSize)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
    } else if (std::isnan(localDW->pathSegObj_c.data[0].Length)) {
        nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
    } else if (realStepSize == 0.0) {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else if ((0.0 < localDW->pathSegObj_c.data[0].Length) && (realStepSize <
                0.0)) {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else if ((localDW->pathSegObj_c.data[0].Length < 0.0) && (realStepSize >
                0.0)) {
        lengths->size[0] = 1;
        lengths->size[1] = 0;
    } else {
        guard1 = false;
        if (std::isinf(localDW->pathSegObj_c.data[0].Length)) {
            if (std::isinf(realStepSize)) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
                lengths->data[0] = (rtNaN);
            } else if (0.0 == localDW->pathSegObj_c.data[0].Length) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = 1;
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
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
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
                lengths->data[0] = 0.0;
            } else if (std::floor(realStepSize) == realStepSize) {
                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                k = static_cast<int32_T>(std::floor(localDW->pathSegObj_c.data[0]
                    .Length / realStepSize));
                lengths->size[1] = static_cast<int32_T>(k + 1);
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
                for (a__1_size = 0; a__1_size <= k; a__1_size++) {
                    lengths->data[a__1_size] = realStepSize * static_cast<real_T>
                        (a__1_size);
                }
            } else {
                ndbl = std::floor(localDW->pathSegObj_c.data[0].Length /
                                  realStepSize + 0.5);
                apnd = ndbl * realStepSize;
                if (realStepSize > 0.0) {
                    cdiff = apnd - localDW->pathSegObj_c.data[0].Length;
                } else {
                    cdiff = localDW->pathSegObj_c.data[0].Length - apnd;
                }

                if (std::abs(cdiff) < 4.4408920985006262E-16 * std::abs
                        (localDW->pathSegObj_c.data[0].Length)) {
                    ndbl++;
                    apnd = localDW->pathSegObj_c.data[0].Length;
                } else if (cdiff > 0.0) {
                    apnd = (ndbl - 1.0) * realStepSize;
                } else {
                    ndbl++;
                }

                if (ndbl >= 0.0) {
                    a__1_size = static_cast<int32_T>(static_cast<int32_T>(ndbl)
                        - 1);
                } else {
                    a__1_size = -1;
                }

                nm1d2 = static_cast<int32_T>(lengths->size[0] * lengths->size[1]);
                lengths->size[0] = 1;
                lengths->size[1] = static_cast<int32_T>(a__1_size + 1);
                FlightMissionMode_emxEnsureCapacity_real_T_c(lengths, nm1d2);
                if (static_cast<int32_T>(a__1_size + 1) > 0) {
                    lengths->data[0] = 0.0;
                    if (static_cast<int32_T>(a__1_size + 1) > 1) {
                        lengths->data[a__1_size] = apnd;
                        nm1d2 = static_cast<int32_T>(a__1_size / 2);
                        for (k = 1; static_cast<int32_T>(k - 1) <=
                                static_cast<int32_T>(nm1d2 - 2); k =
                                static_cast<int32_T>(k + 1)) {
                            ndbl = static_cast<real_T>(k) * realStepSize;
                            lengths->data[k] = ndbl;
                            lengths->data[static_cast<int32_T>(a__1_size - k)] =
                                apnd - ndbl;
                        }

                        if (static_cast<int32_T>(nm1d2 << 1) == a__1_size) {
                            lengths->data[nm1d2] = apnd / 2.0;
                        } else {
                            ndbl = static_cast<real_T>(nm1d2) * realStepSize;
                            lengths->data[nm1d2] = ndbl;
                            lengths->data[static_cast<int32_T>(nm1d2 + 1)] =
                                apnd - ndbl;
                        }
                    }
                }
            }
        }
    }

    FlightMissionMode_emxInit_real_T_h(&poses, 2);
    FlightMissionMode_uavDubinsPathSegment_interpolate_e
        (localDW->pathSegObj_c.data[0].StartPose, localDW->pathSegObj_c.data[0].
         GoalPose, localDW->pathSegObj_c.data[0].FlightPathAngle,
         localDW->pathSegObj_c.data[0].AirSpeed, localDW->pathSegObj_c.data[0].
         MinTurningRadius, localDW->pathSegObj_c.data[0].HelixRadius,
         localDW->pathSegObj_c.data[0].MotionTypes, localDW->pathSegObj_c.data[0]
         .MotionLengths, localDW->pathSegObj_c.data[0].Length, lengths, poses);
    k = poses->size[0];
    nm1d2 = static_cast<int32_T>(segWayPoints->size[0] * segWayPoints->size[1]);
    segWayPoints->size[0] = poses->size[0];
    segWayPoints->size[1] = 3;
    FlightMissionMode_emxEnsureCapacity_real_T_c(segWayPoints, nm1d2);
    FlightMissionMode_emxFree_real_T_n(&lengths);
    for (a__1_size = 0; a__1_size < 3; a__1_size++) {
        for (nm1d2 = 0; nm1d2 <= static_cast<int32_T>(k - 1); nm1d2++) {
            segWayPoints->data[static_cast<int32_T>(nm1d2 + static_cast<int32_T>
                (segWayPoints->size[0] * a__1_size))] = poses->data
                [static_cast<int32_T>(nm1d2 + static_cast<int32_T>(poses->size[0]
                * a__1_size))];
        }
    }

    FlightMissionMode_emxFree_real_T_n(&poses);
}

// Function for MATLAB Function: '<S57>/WayPointGenerator'
static void FlightMissionMode_repmat(const emxArray_real_T_FlightMissionMode_T
    *a, real_T varargin_1, emxArray_real_T_FlightMissionMode_T *b)
{
    int32_T iacol;
    int32_T ibcol;
    int32_T ibmat;
    int32_T itilerow;
    int32_T k;
    int32_T nrows;
    nrows = static_cast<int32_T>(b->size[0] * b->size[1]);
    b->size[0] = static_cast<int32_T>(a->size[0] * static_cast<int32_T>
        (varargin_1));
    b->size[1] = 3;
    FlightMissionMode_emxEnsureCapacity_real_T_c(b, nrows);
    nrows = a->size[0];
    for (itilerow = 0; itilerow <= static_cast<int32_T>(static_cast<int32_T>
            (varargin_1) - 1); itilerow = static_cast<int32_T>(itilerow + 1)) {
        ibcol = static_cast<int32_T>(static_cast<int32_T>(itilerow * nrows) + -1);
        for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>(nrows -
                1); k = static_cast<int32_T>(k + 1)) {
            b->data[static_cast<int32_T>(ibcol + k)] = a->data
                [static_cast<int32_T>(k - 1)];
        }
    }

    ibmat = static_cast<int32_T>(static_cast<int32_T>(a->size[0] *
        static_cast<int32_T>(varargin_1)) - 1);
    for (itilerow = 0; itilerow <= static_cast<int32_T>(static_cast<int32_T>
            (varargin_1) - 1); itilerow = static_cast<int32_T>(itilerow + 1)) {
        ibcol = static_cast<int32_T>(static_cast<int32_T>(itilerow * nrows) +
            ibmat);
        for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>(nrows -
                1); k = static_cast<int32_T>(k + 1)) {
            b->data[static_cast<int32_T>(ibcol + k)] = a->data
                [static_cast<int32_T>(static_cast<int32_T>(nrows + k) - 1)];
        }
    }

    iacol = static_cast<int32_T>(a->size[0] << 1);
    ibmat = static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
        (a->size[0] * static_cast<int32_T>(varargin_1)) << 1) - 1);
    for (itilerow = 0; itilerow <= static_cast<int32_T>(static_cast<int32_T>
            (varargin_1) - 1); itilerow = static_cast<int32_T>(itilerow + 1)) {
        ibcol = static_cast<int32_T>(static_cast<int32_T>(itilerow * nrows) +
            ibmat);
        for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>(nrows -
                1); k = static_cast<int32_T>(k + 1)) {
            b->data[static_cast<int32_T>(ibcol + k)] = a->data
                [static_cast<int32_T>(static_cast<int32_T>(iacol + k) - 1)];
        }
    }
}

// System initialize for referenced model: 'FlightMissionMode'
void FlightMissionMode_Init(FixedWingGuidanceBus *rty_GuidanceCmds, real_T
    rty_InitialState[8], DW_FlightMissionMode_f_T *localDW)
{
    localDW->SwitchCase_ActiveSubsystem = -1;
    FlightMissionMode_OrbitFollower_Init(&localDW->OrbitFollower);
    FlightMissionMode_OrbitFollower_Init(&localDW->OrbitFollower_p);
    FlightMissionMode_RotateATMissionHdg_Init(&localDW->RotateATMissionHdg);
    FlightMissionMode_WaypointFollower_Init(&localDW->WaypointFollower);
    FlightMissionMode_RotateATMissionHdg_Init(&localDW->RotateATMissionHdg_p);
    FlightMissionMode_WaypointFollower_Init(&localDW->WaypointFollower_p);
    FlightMissionMode_RotateATMissionHdg_Init(&localDW->RotateATMissionHdg_pn);
    FlightMissionMode_RotateATMissionHdg_Init(&localDW->RotateATRunWayHdg);
    localDW->SwitchCase_ActiveSubsystem_k = -1;
    FlightMissionMode_WaypointFollower_c_Init(&localDW->WaypointFollower_pn);
    FlightMissionMode_WaypointFollower_c_Init(&localDW->WaypointFollower_pna);
    FlightMissionMode_WaypointFollower_c_Init(&localDW->WaypointFollower_pnae);
    FlightMissionMode_WaypointFollower_c_Init(&localDW->WaypointFollower_pnaev);
    FlightMissionMode_RotateATMissionHdg_Init(&localDW->RotateATRunWayHdg_p);
    FlightMissionMode_RotateATMissionHdg_Init(&localDW->RotateATMissionHdg_pna);
    localDW->SwitchCase_ActiveSubsystem_h = -1;
    FlightMissionMode_WaypointFollower_c_Init(&localDW->WaypointFollower_pnaevv);
    FlightMissionMode_WaypointFollower_c_Init(&localDW->WaypointFollower_pnaevvf);
    FlightMissionMode_WaypointFollower_c_Init
        (&localDW->WaypointFollower_pnaevvfp);
    FlightMissionMode_WaypointFollower_c_Init
        (&localDW->WaypointFollower_pnaevvfpg);
    FlightMissionMode_WaypointFollower_c_Init
        (&localDW->WaypointFollower_pnaevvfpgh);
    *rty_GuidanceCmds = FlightMissionMode_rtZFixedWingGuidanceBus;
    std::memset(&rty_InitialState[0], 0, static_cast<uint32_T>(sizeof(real_T) <<
                 3U));
}

// Disable for referenced model: 'FlightMissionMode'
void FlightMissionMode_Disable(DW_FlightMissionMode_f_T *localDW)
{
    switch (localDW->SwitchCase_ActiveSubsystem) {
      case 0:
      case 1:
      case 6:
        break;

      case 2:
        localDW->WayPointGenerator_MODE_l = false;
        break;

      case 3:
        localDW->WayPointGenerator_MODE_f = false;
        break;

      case 4:
        localDW->WayPointGenerator_MODE_a = false;
        localDW->SwitchCase_ActiveSubsystem_k = -1;
        break;

      case 5:
        localDW->WayPointGenerator_MODE = false;
        localDW->SwitchCase_ActiveSubsystem_h = -1;
        break;
    }

    localDW->SwitchCase_ActiveSubsystem = -1;
}

// Output and update for referenced model: 'FlightMissionMode'
void FlightMissionMode(const boolean_T *rtu_startFlight, const MissionModes
                       *rtu_mode, const Location *rtu_PrevLocation, const
                       Location *rtu_Location, const Parameters *rtu_Parameters,
                       const Location *rtu_StartPosition, const int32_T
                       *rtu_Reset, const int32_T *rtu_FormationIDX, const
                       int32_T *rtu_MissionUAV, const real_T rtu_Pose[4], real_T
                       *rty_thisTaskStatus, FixedWingGuidanceBus
                       *rty_GuidanceCmds, real_T rty_InitialState[8],
                       DW_FlightMissionMode_f_T *localDW)
{
    // local block i/o variables
    real_T rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[3];
    real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1[3];
    real_T rtb_nedWayPoint_CoreSubsysCanOut[300];
    real_T rtb_RotateRunway[300];
    real_T rtb_RotateIndivWayPoint[300];
    real_T rtb_Selector[300];
    real_T rtb_Selector_h[300];
    real_T rtb_Selector_k[300];
    real_T rtb_Selector_m[300];
    real_T rtb_Selector_b[300];
    real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m[3];
    real_T rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_o[3];
    real_T rtb_ImpSel_InsertedFor_RawRunWay_at_outport_0_b[300];
    real_T rtb_nedWayPoint_CoreSubsysCanOut_f[300];
    real_T rtb_RotateIndivWayPoint_m[300];
    real_T rtb_y[300];
    real_T rtb_Selector_c[300];
    real_T rtb_Selector_g[300];
    real_T rtb_Selector_a[300];
    real_T rtb_Selector_at[300];
    real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m5[3];
    real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m52[3];
    real_T rtb_Param1_n;
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport2[3];
    real_T rtb_Param2_dy;
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport2_l[3];
    real_T rtb_Param1_nh;
    real_T rtb_Param2_e;
    real_T rtb_y_b[300];
    static const int8_T b[5]{ 0, 1, 2, 3, 5 };

    emxArray_real_T_FlightMissionMode_T *CheckPoints;
    emxArray_real_T_FlightMissionMode_T *dummyWayPoint;
    emxArray_real_T_FlightMissionMode_T *dummyWayPoint_0;
    emxArray_real_T_FlightMissionMode_T *dummyWayPoint_1;
    emxArray_real_T_FlightMissionMode_T *segWayPoints;
    uavDubinsConnection_FlightMissionMode_T connectionObj;
    real_T segWayPoints_0[300];
    real_T a__1_data[28];
    real_T midpose_data[6];
    real_T rtb_startPose[5];
    real_T rtb_startPose_e[5];
    real_T tmp_0[5];
    real_T LDp[4];
    real_T rtb_startPose_i[4];
    real_T tmp[4];
    real_T rtb_RelPrevPos_n_0[3];
    real_T rtb_ReshapeRowVecStartpose_c[3];
    real_T rtb_ReshapeRowVec_ec[3];
    real_T rtb_RotateIndivWayPointStartpose1[3];
    real_T rtb_Abs1_o2;
    real_T rtb_AltitudeGCS_e;
    real_T rtb_ClockwiseRotation_l;
    real_T rtb_Cos_g;
    real_T rtb_Down2Up_n;
    real_T rtb_LatitudeGCS_n;
    real_T rtb_Map2Radian;
    real_T rtb_RelPrevPos_n_idx_2;
    real_T rtb_Sum1_j_idx_0;
    real_T rtb_Sum1_j_idx_1;
    real_T rtb_Sum_f;
    real_T rtb_Switch_f;
    int32_T midpose_size[2];
    int32_T CheckPoints_0;
    int32_T iacol;
    int32_T ibmat;
    int32_T k;
    int32_T nrows;
    int32_T rtb_Bias_fd;
    int8_T rtb_MatrixConcatenate[9];
    int8_T rtAction;
    int8_T rtPrevAction;
    boolean_T guard1{ false };

    if (static_cast<uint32_T>(localDW->is_active_c23_FlightMissionMode) == 0U) {
        localDW->is_active_c23_FlightMissionMode = 1U;
        localDW->is_GuidanceLogic = FlightMissionMode_IN_WaitToStart;
        localDW->PreemptableMissionModeSelectorMode = WaitToStart;
    } else {
        guard1 = false;
        if (*rtu_Reset != 0) {
            if (static_cast<boolean_T>(static_cast<int32_T>((*rtu_mode ==
                    CircNav) | (*rtu_mode == CircDispNav)))) {
                FlightMissionMode_exit_internal_GuidanceLogic(localDW);
                localDW->is_GuidanceLogic = FlightMissionMode_IN_OrbitFollower;
                if (*rtu_mode == CircNav) {
                    localDW->PreemptableMissionModeSelectorMode = CircNav;
                } else {
                    localDW->PreemptableMissionModeSelectorMode = CircDispNav;
                }
            } else if (static_cast<boolean_T>(static_cast<int32_T>((*rtu_mode ==
                          HorzFrmnNav) | (*rtu_mode == CustomFrmnNav)))) {
                FlightMissionMode_exit_internal_GuidanceLogic(localDW);
                localDW->is_GuidanceLogic =
                    FlightMissionMode_IN_WaypointFollower;
                if (*rtu_mode == HorzFrmnNav) {
                    localDW->PreemptableMissionModeSelectorMode = HorzFrmnNav;
                } else {
                    localDW->PreemptableMissionModeSelectorMode = CustomFrmnNav;
                }
            } else if (*rtu_mode == RunWayNav) {
                FlightMissionMode_exit_internal_GuidanceLogic(localDW);
                localDW->is_GuidanceLogic = FlightMissionMode_IN_RunWayNav;
                localDW->PreemptableMissionModeSelectorMode = RunWayNav;
            } else if (*rtu_mode == ProtLine) {
                FlightMissionMode_exit_internal_GuidanceLogic(localDW);
                localDW->is_GuidanceLogic = FlightMissionMode_IN_ProtLine;
                localDW->PreemptableMissionModeSelectorMode = ProtLine;
            } else {
                guard1 = true;
            }
        } else {
            guard1 = true;
        }

        if (guard1) {
            switch (localDW->is_GuidanceLogic) {
              case FlightMissionMode_IN_OrbitFollower:
              case FlightMissionMode_IN_ProtLine:
              case FlightMissionMode_IN_RunWayNav:
                break;

              case FlightMissionMode_IN_WaitToStart:
                if (*rtu_startFlight) {
                    if (static_cast<boolean_T>(static_cast<int32_T>((*rtu_mode ==
                           CircNav) | (*rtu_mode == CircDispNav)))) {
                        localDW->PreemptableMissionModeSelectorMode = None;
                        localDW->is_GuidanceLogic =
                            FlightMissionMode_IN_OrbitFollower;
                        if (*rtu_mode == CircNav) {
                            localDW->PreemptableMissionModeSelectorMode =
                                CircNav;
                        } else {
                            localDW->PreemptableMissionModeSelectorMode =
                                CircDispNav;
                        }
                    } else if (static_cast<boolean_T>(static_cast<int32_T>
                                ((*rtu_mode == HorzFrmnNav) | (*rtu_mode ==
                                  CustomFrmnNav)))) {
                        localDW->PreemptableMissionModeSelectorMode = None;
                        localDW->is_GuidanceLogic =
                            FlightMissionMode_IN_WaypointFollower;
                        if (*rtu_mode == HorzFrmnNav) {
                            localDW->PreemptableMissionModeSelectorMode =
                                HorzFrmnNav;
                        } else {
                            localDW->PreemptableMissionModeSelectorMode =
                                CustomFrmnNav;
                        }
                    } else {
                        switch (*rtu_mode) {
                          case RunWayNav:
                            localDW->is_GuidanceLogic =
                                FlightMissionMode_IN_RunWayNav;
                            localDW->PreemptableMissionModeSelectorMode =
                                RunWayNav;
                            break;

                          case ProtLine:
                            localDW->is_GuidanceLogic =
                                FlightMissionMode_IN_ProtLine;
                            localDW->PreemptableMissionModeSelectorMode =
                                ProtLine;
                            break;
                        }
                    }
                }
                break;

              default:
                // case IN_WaypointFollower:
                break;
            }
        }
    }

    rtPrevAction = localDW->SwitchCase_ActiveSubsystem;
    switch (localDW->PreemptableMissionModeSelectorMode) {
      case CircNav:
        rtAction = 0;
        break;

      case CircDispNav:
        rtAction = 1;
        break;

      case HorzFrmnNav:
        rtAction = 2;
        break;

      case CustomFrmnNav:
        rtAction = 3;
        break;

      case RunWayNav:
        rtAction = 4;
        break;

      case ProtLine:
        rtAction = 5;
        break;

      default:
        rtAction = 6;
        break;
    }

    localDW->SwitchCase_ActiveSubsystem = rtAction;
    if (static_cast<int32_T>(rtPrevAction) != static_cast<int32_T>(rtAction)) {
        switch (rtPrevAction) {
          case 0:
          case 1:
          case 6:
            break;

          case 2:
            localDW->WayPointGenerator_MODE_l = false;
            break;

          case 3:
            localDW->WayPointGenerator_MODE_f = false;
            break;

          case 4:
            localDW->WayPointGenerator_MODE_a = false;
            localDW->SwitchCase_ActiveSubsystem_k = -1;
            break;

          case 5:
            localDW->WayPointGenerator_MODE = false;
            localDW->SwitchCase_ActiveSubsystem_h = -1;
            break;
        }
    }

    FlightMissionMode_emxInit_real_T_h(&CheckPoints, 2);
    FlightMissionMode_emxInit_real_T_h(&dummyWayPoint, 2);
    FlightMissionMode_emxInit_real_T_h(&segWayPoints, 2);
    FlightMissionMode_emxInit_real_T_h(&dummyWayPoint_0, 2);
    switch (rtAction) {
      case 0:
        if (static_cast<int32_T>(rtAction) != static_cast<int32_T>(rtPrevAction))
        {
            FlightMissionMode_OrbitFollower_Reset(&localDW->OrbitFollower);
        }

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_AltitudeGCS_e = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtb_Bias_fd = *rtu_MissionUAV;
        rtb_ClockwiseRotation_l = static_cast<real_T>(*rtu_FormationIDX);
        rtb_Map2Radian = 6.2831853071795862 / static_cast<real_T>
            (*rtu_MissionUAV);
        rtb_Map2Radian *= rtb_ClockwiseRotation_l - static_cast<real_T>(
            static_cast<int32_T>(rtb_Bias_fd + 1)) * 0.5;
        rtb_ClockwiseRotation_l = rtb_Map2Radian + 1.5707963267948966;
        rtb_Cos_g = std::cos(rtb_Map2Radian);
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_LatitudeGCS_n = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_Abs1_o2 = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_j_idx_0 = rtu_Location->Lat - rtb_LatitudeGCS_n;
        rtb_Sum1_j_idx_1 = rtu_Location->Lon - rtb_Abs1_o2;
        if (std::abs(rtb_Sum1_j_idx_0) > 180.0) {
            rtb_Switch_f = rt_modd_snf(rtb_Sum1_j_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch_f = rtb_Sum1_j_idx_0;
        }

        rtb_Abs1_o2 = std::abs(rtb_Switch_f);
        if (rtb_Abs1_o2 > 90.0) {
            if (rtb_Switch_f < 0.0) {
                rtb_Switch_f = -1.0;
            } else if (rtb_Switch_f > 0.0) {
                rtb_Switch_f = 1.0;
            } else if (rtb_Switch_f == 0.0) {
                rtb_Switch_f = 0.0;
            } else {
                rtb_Switch_f = (rtNaN);
            }

            rtb_Switch_f *= -(rtb_Abs1_o2 + -90.0) + 90.0;
            iacol = 180;
        } else {
            iacol = 0;
        }

        rtb_Sum_f = static_cast<real_T>(iacol) + rtb_Sum1_j_idx_1;
        if (std::abs(rtb_Sum_f) > 180.0) {
            rtb_Sum_f = rt_modd_snf(rtb_Sum_f + 180.0, 360.0) + -180.0;
        }

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_j_idx_0 = 0.017453292519943295 * rtb_Switch_f;
        rtb_Sum1_j_idx_1 = 0.017453292519943295 * rtb_Sum_f;

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_LatitudeGCS_n *= 0.017453292519943295;
        rtb_Sum_f = std::sin(rtb_LatitudeGCS_n);
        rtb_Sum_f = 1.0 - 0.0066943799901413295 * rtb_Sum_f * rtb_Sum_f;
        rtb_Switch_f = 6.378137E+6 / std::sqrt(rtb_Sum_f);
        rtb_Sum_f = rtb_Sum1_j_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_f *
            0.99330562000985867 / rtb_Sum_f);

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_f = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_f * std::cos
            (rtb_LatitudeGCS_n)) * rtb_Sum1_j_idx_1;
        rtb_LatitudeGCS_n = rtb_Switch_f * 0.0 + rtb_Sum_f;
        rtb_Abs1_o2 = rtb_Switch_f - rtb_Sum_f * 0.0;
        rtb_Down2Up_n = rtu_Location->Alt + -rtb_AltitudeGCS_e;
        rtb_TmpSignalConversionAtOrbitFollowerInport2_l[0] = rtb_LatitudeGCS_n;
        rtb_TmpSignalConversionAtOrbitFollowerInport2_l[1] = rtb_Abs1_o2;
        rtb_TmpSignalConversionAtOrbitFollowerInport2_l[2] = -rtb_Down2Up_n;
        rtb_Param1_nh = static_cast<real_T>(rtu_Parameters->Param1);
        rtb_Param2_e = static_cast<real_T>(rtu_Parameters->Param2);
        FlightMissionMode_OrbitFollower(rtu_Pose,
            rtb_TmpSignalConversionAtOrbitFollowerInport2_l, rtb_Param1_nh,
            rtb_Param2_e, 1.0, &localDW->OrbitFollower);
        rty_GuidanceCmds->Height = -localDW->OrbitFollower.OrbitFollower_o1[2];
        rty_GuidanceCmds->AirSpeed = static_cast<real_T>(rtu_Parameters->Param4);
        rty_GuidanceCmds->HeadingAngle = localDW->OrbitFollower.OrbitFollower_o2;
        rty_InitialState[0] = rtb_Cos_g * rtb_Param1_nh + rtb_LatitudeGCS_n;
        rty_InitialState[1] = rtb_Param1_nh * std::sin(rtb_Map2Radian) +
            rtb_Abs1_o2;
        rty_InitialState[2] = rtb_Down2Up_n;
        rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
        rty_InitialState[4] = rtb_ClockwiseRotation_l;
        rty_InitialState[5] = 0.0;
        rty_InitialState[6] = 0.0;
        rty_InitialState[7] = 0.0;
        *rty_thisTaskStatus = localDW->OrbitFollower.OrbitFollower_o6;
        break;

      case 1:
        if (static_cast<int32_T>(rtAction) != static_cast<int32_T>(rtPrevAction))
        {
            FlightMissionMode_OrbitFollower_Reset(&localDW->OrbitFollower_p);
        }

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_AltitudeGCS_e = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtb_Param1_n = static_cast<real_T>(rtu_Parameters->Param1);
        rtb_ClockwiseRotation_l = rtu_StartPosition->Lat / rtb_Param1_n;
        rtb_Map2Radian = rtb_ClockwiseRotation_l + 1.5707963267948966;
        rtb_Cos_g = std::cos(rtb_ClockwiseRotation_l);
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_LatitudeGCS_n = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_Abs1_o2 = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_j_idx_0 = rtu_Location->Lat - rtb_LatitudeGCS_n;
        rtb_Sum1_j_idx_1 = rtu_Location->Lon - rtb_Abs1_o2;
        if (std::abs(rtb_Sum1_j_idx_0) > 180.0) {
            rtb_Switch_f = rt_modd_snf(rtb_Sum1_j_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch_f = rtb_Sum1_j_idx_0;
        }

        rtb_Abs1_o2 = std::abs(rtb_Switch_f);
        if (rtb_Abs1_o2 > 90.0) {
            if (rtb_Switch_f < 0.0) {
                rtb_Switch_f = -1.0;
            } else if (rtb_Switch_f > 0.0) {
                rtb_Switch_f = 1.0;
            } else if (rtb_Switch_f == 0.0) {
                rtb_Switch_f = 0.0;
            } else {
                rtb_Switch_f = (rtNaN);
            }

            rtb_Switch_f *= -(rtb_Abs1_o2 + -90.0) + 90.0;
            iacol = 180;
        } else {
            iacol = 0;
        }

        rtb_Sum_f = static_cast<real_T>(iacol) + rtb_Sum1_j_idx_1;
        if (std::abs(rtb_Sum_f) > 180.0) {
            rtb_Sum_f = rt_modd_snf(rtb_Sum_f + 180.0, 360.0) + -180.0;
        }

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_j_idx_0 = 0.017453292519943295 * rtb_Switch_f;
        rtb_Sum1_j_idx_1 = 0.017453292519943295 * rtb_Sum_f;

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_LatitudeGCS_n *= 0.017453292519943295;
        rtb_Sum_f = std::sin(rtb_LatitudeGCS_n);
        rtb_Sum_f = 1.0 - 0.0066943799901413295 * rtb_Sum_f * rtb_Sum_f;
        rtb_Switch_f = 6.378137E+6 / std::sqrt(rtb_Sum_f);
        rtb_Sum_f = rtb_Sum1_j_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_f *
            0.99330562000985867 / rtb_Sum_f);

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_f = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_f * std::cos
            (rtb_LatitudeGCS_n)) * rtb_Sum1_j_idx_1;
        rtb_LatitudeGCS_n = rtb_Switch_f * 0.0 + rtb_Sum_f;
        rtb_Abs1_o2 = rtb_Switch_f - rtb_Sum_f * 0.0;
        rtb_Down2Up_n = rtu_Location->Alt + -rtb_AltitudeGCS_e;
        rtb_Down2Up_n += rtu_StartPosition->Alt;
        rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_LatitudeGCS_n;
        rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Abs1_o2;
        rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = -rtb_Down2Up_n;
        rtb_Param2_dy = static_cast<real_T>(rtu_Parameters->Param2);
        FlightMissionMode_OrbitFollower(rtu_Pose,
            rtb_TmpSignalConversionAtOrbitFollowerInport2, rtb_Param1_n,
            rtb_Param2_dy, 1.0, &localDW->OrbitFollower_p);
        rty_GuidanceCmds->Height = -localDW->OrbitFollower_p.OrbitFollower_o1[2];
        rty_GuidanceCmds->AirSpeed = static_cast<real_T>(rtu_Parameters->Param4);
        rty_GuidanceCmds->HeadingAngle =
            localDW->OrbitFollower_p.OrbitFollower_o2;
        rty_InitialState[0] = rtb_Cos_g * rtb_Param1_n + rtb_LatitudeGCS_n;
        rty_InitialState[1] = rtb_Param1_n * std::sin(rtb_ClockwiseRotation_l) +
            rtb_Abs1_o2;
        rty_InitialState[2] = rtb_Down2Up_n;
        rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
        rty_InitialState[4] = rtb_Map2Radian;
        rty_InitialState[5] = 0.0;
        rty_InitialState[6] = 0.0;
        rty_InitialState[7] = 0.0;
        *rty_thisTaskStatus = localDW->OrbitFollower_p.OrbitFollower_o6;
        break;

      case 2:
        if (static_cast<int32_T>(rtAction) != static_cast<int32_T>(rtPrevAction))
        {
            FlightMissionMode_WaypointFollower_Reset(&localDW->WaypointFollower);
        }

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_Abs1_o2 = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtb_Abs1_o2 = rtu_Location->Alt + -rtb_Abs1_o2;
        rtb_LatitudeGCS_n = static_cast<real_T>(*rtu_FormationIDX);
        rtb_LatitudeGCS_n--;
        rtb_AltitudeGCS_e = 15.0 * rt_modd_snf(rtb_LatitudeGCS_n, 3.0);
        rtb_Map2Radian = -rtb_Abs1_o2 - rtb_AltitudeGCS_e;
        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_Abs1_o2 = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtb_Abs1_o2 = rtu_PrevLocation->Alt + -rtb_Abs1_o2;
        rtb_AltitudeGCS_e = -rtb_Abs1_o2 - rtb_AltitudeGCS_e;
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_ClockwiseRotation_l = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_Abs1_o2 = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_j_idx_0 = rtu_PrevLocation->Lat - rtb_ClockwiseRotation_l;
        rtb_Sum1_j_idx_1 = rtu_PrevLocation->Lon - rtb_Abs1_o2;
        if (std::abs(rtb_Sum1_j_idx_0) > 180.0) {
            rtb_Down2Up_n = rt_modd_snf(rtb_Sum1_j_idx_0 + 180.0, 360.0) +
                -180.0;
        } else {
            rtb_Down2Up_n = rtb_Sum1_j_idx_0;
        }

        rtb_Abs1_o2 = std::abs(rtb_Down2Up_n);
        if (rtb_Abs1_o2 > 90.0) {
            if (rtb_Down2Up_n < 0.0) {
                rtb_Down2Up_n = -1.0;
            } else if (rtb_Down2Up_n > 0.0) {
                rtb_Down2Up_n = 1.0;
            } else if (rtb_Down2Up_n == 0.0) {
                rtb_Down2Up_n = 0.0;
            } else {
                rtb_Down2Up_n = (rtNaN);
            }

            rtb_Down2Up_n *= -(rtb_Abs1_o2 + -90.0) + 90.0;
            iacol = 180;
        } else {
            iacol = 0;
        }

        rtb_Sum_f = static_cast<real_T>(iacol) + rtb_Sum1_j_idx_1;
        if (std::abs(rtb_Sum_f) > 180.0) {
            rtb_Sum_f = rt_modd_snf(rtb_Sum_f + 180.0, 360.0) + -180.0;
        }

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_j_idx_0 = 0.017453292519943295 * rtb_Down2Up_n;
        rtb_Sum1_j_idx_1 = 0.017453292519943295 * rtb_Sum_f;

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_ClockwiseRotation_l *= 0.017453292519943295;
        rtb_Sum_f = std::sin(rtb_ClockwiseRotation_l);
        rtb_Sum_f = 1.0 - 0.0066943799901413295 * rtb_Sum_f * rtb_Sum_f;
        rtb_Down2Up_n = 6.378137E+6 / std::sqrt(rtb_Sum_f);
        rtb_Sum_f = rtb_Sum1_j_idx_0 / rt_atan2d_snf(1.0, rtb_Down2Up_n *
            0.99330562000985867 / rtb_Sum_f);

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Down2Up_n = 1.0 / rt_atan2d_snf(1.0, rtb_Down2Up_n * std::cos
            (rtb_ClockwiseRotation_l)) * rtb_Sum1_j_idx_1;
        rtb_ClockwiseRotation_l = rtb_Down2Up_n * 0.0 + rtb_Sum_f;
        rtb_Cos_g = rtb_Down2Up_n - rtb_Sum_f * 0.0;
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_Switch_f = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_Abs1_o2 = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_j_idx_0 = rtu_Location->Lat - rtb_Switch_f;
        rtb_Sum1_j_idx_1 = rtu_Location->Lon - rtb_Abs1_o2;
        if (std::abs(rtb_Sum1_j_idx_0) > 180.0) {
            rtb_Sum_f = rt_modd_snf(rtb_Sum1_j_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Sum_f = rtb_Sum1_j_idx_0;
        }

        rtb_Abs1_o2 = std::abs(rtb_Sum_f);
        if (rtb_Abs1_o2 > 90.0) {
            if (rtb_Sum_f < 0.0) {
                rtb_Sum_f = -1.0;
            } else if (rtb_Sum_f > 0.0) {
                rtb_Sum_f = 1.0;
            } else if (rtb_Sum_f == 0.0) {
                rtb_Sum_f = 0.0;
            } else {
                rtb_Sum_f = (rtNaN);
            }

            rtb_Sum_f *= -(rtb_Abs1_o2 + -90.0) + 90.0;
            iacol = 180;
        } else {
            iacol = 0;
        }

        rtb_Down2Up_n = static_cast<real_T>(iacol) + rtb_Sum1_j_idx_1;
        if (std::abs(rtb_Down2Up_n) > 180.0) {
            rtb_Down2Up_n = rt_modd_snf(rtb_Down2Up_n + 180.0, 360.0) + -180.0;
        }

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_j_idx_0 = 0.017453292519943295 * rtb_Sum_f;
        rtb_Sum1_j_idx_1 = 0.017453292519943295 * rtb_Down2Up_n;

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_f *= 0.017453292519943295;
        rtb_Sum_f = std::sin(rtb_Switch_f);
        rtb_Sum_f = 1.0 - 0.0066943799901413295 * rtb_Sum_f * rtb_Sum_f;
        rtb_Down2Up_n = 6.378137E+6 / std::sqrt(rtb_Sum_f);
        rtb_Sum_f = rtb_Sum1_j_idx_0 / rt_atan2d_snf(1.0, rtb_Down2Up_n *
            0.99330562000985867 / rtb_Sum_f);

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_f = 1.0 / rt_atan2d_snf(1.0, rtb_Down2Up_n * std::cos
            (rtb_Switch_f)) * rtb_Sum1_j_idx_1;
        rtb_Down2Up_n = rtb_Switch_f * 0.0 + rtb_Sum_f;
        rtb_Switch_f -= rtb_Sum_f * 0.0;
        rtb_Sum1_j_idx_0 = rtb_ClockwiseRotation_l - rtb_Down2Up_n;
        rtb_Sum1_j_idx_1 = rtb_Cos_g - rtb_Switch_f;
        rtb_RelPrevPos_n_idx_2 = rtb_AltitudeGCS_e - rtb_Map2Radian;
        rtb_Abs1_o2 = static_cast<real_T>(rtu_Parameters->Param3) *
            rtb_LatitudeGCS_n;
        rtb_LatitudeGCS_n = 0.017453292519943295 * rtu_Location->degHDG;
        if (*rtu_Reset > 0) {
            localDW->WayPointGenerator_MODE_l = true;
            rtb_Sum_f = static_cast<real_T>(rtu_Parameters->Param3) *
                static_cast<real_T>(*rtu_MissionUAV);
            rtb_ReshapeRowVec_ec[0] = rtb_Down2Up_n;
            rtb_ReshapeRowVec_ec[1] = rtb_Switch_f;
            rtb_ReshapeRowVec_ec[2] = rtb_Map2Radian;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m52[0] =
                rtb_LatitudeGCS_n;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m52[1] = 0.0;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m52[2] = 0.0;
            FlightMissionMode_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m52,
                 &localDW->RotateATMissionHdg);
            rtb_Switch_f = std::ceil(static_cast<real_T>(rtu_Parameters->Param2)
                / rtb_Sum_f);
            rtb_Down2Up_n = static_cast<real_T>(rtu_Parameters->Param2) /
                rtb_Switch_f;
            connectionObj.FlightPathAngleLimit[0] = -0.175;
            connectionObj.FlightPathAngleLimit[1] = 0.175;
            connectionObj.MaxRollAngle = 0.29670597283903605;
            connectionObj.AirSpeed = 35.0;
            connectionObj.MinTurningRadius = 408.85657731051754;
            CheckPoints_0 = static_cast<int32_T>(CheckPoints->size[0] *
                CheckPoints->size[1]);
            iacol = static_cast<int32_T>(rtb_Switch_f * 2.0);
            CheckPoints->size[0] = iacol;
            CheckPoints->size[1] = 4;
            FlightMissionMode_emxEnsureCapacity_real_T_c(CheckPoints,
                CheckPoints_0);
            ibmat = static_cast<int32_T>(static_cast<int32_T>(iacol << 2) - 1);
            for (iacol = 0; iacol <= ibmat; iacol++) {
                CheckPoints->data[iacol] = 0.0;
            }

            for (rtb_Bias_fd = 0; rtb_Bias_fd <= static_cast<int32_T>(
                    static_cast<int32_T>(rtb_Switch_f) - 1); rtb_Bias_fd =
                    static_cast<int32_T>(rtb_Bias_fd + 1)) {
                if (rt_remd_snf(static_cast<real_T>(rtb_Bias_fd) + 1.0, 2.0) ==
                        1.0) {
                    iacol = static_cast<int32_T>(static_cast<int32_T>
                        (rtb_Bias_fd + 1) << 1);
                    rtb_Sum_f = ((static_cast<real_T>(rtb_Bias_fd) + 1.0) - 1.0)
                        * rtb_Down2Up_n;
                    CheckPoints->data[static_cast<int32_T>(iacol - 2)] =
                        rtb_Sum_f;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + CheckPoints->size[0]) - 2)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] << 1))
                        - 2)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 2)] = 1.5707963267948966;
                    CheckPoints->data[static_cast<int32_T>(iacol - 1)] =
                        rtb_Sum_f;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + CheckPoints->size[0]) - 1)] =
                        static_cast<real_T>(rtu_Parameters->Param1);
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] << 1))
                        - 1)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 1)] = 1.5707963267948966;
                } else {
                    iacol = static_cast<int32_T>(static_cast<int32_T>
                        (rtb_Bias_fd + 1) << 1);
                    rtb_Sum_f = ((static_cast<real_T>(rtb_Bias_fd) + 1.0) - 1.0)
                        * rtb_Down2Up_n;
                    CheckPoints->data[static_cast<int32_T>(iacol - 2)] =
                        rtb_Sum_f;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + CheckPoints->size[0]) - 2)] =
                        static_cast<real_T>(rtu_Parameters->Param1);
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] << 1))
                        - 2)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 2)] = -1.5707963267948966;
                    CheckPoints->data[static_cast<int32_T>(iacol - 1)] =
                        rtb_Sum_f;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + CheckPoints->size[0]) - 1)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] << 1))
                        - 1)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 1)] = -1.5707963267948966;
                }
            }

            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint->size[0] *
                dummyWayPoint->size[1]);
            dummyWayPoint->size[0] = 1;
            dummyWayPoint->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint,
                CheckPoints_0);
            dummyWayPoint->data[0] = 0.0;
            dummyWayPoint->data[1] = 0.0;
            dummyWayPoint->data[2] = 0.0;
            for (rtb_Bias_fd = 0; rtb_Bias_fd <= static_cast<int32_T>
                    (CheckPoints->size[0] - 2); rtb_Bias_fd =
                    static_cast<int32_T>(rtb_Bias_fd + 1)) {
                rtb_startPose_i[0] = CheckPoints->data[rtb_Bias_fd];
                LDp[0] = CheckPoints->data[static_cast<int32_T>(rtb_Bias_fd + 1)];
                rtb_startPose_i[1] = CheckPoints->data[static_cast<int32_T>
                    (rtb_Bias_fd + CheckPoints->size[0])];
                LDp[1] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(rtb_Bias_fd + CheckPoints->size[0]) +
                     1)];
                rtb_startPose_i[2] = CheckPoints->data[static_cast<int32_T>
                    (rtb_Bias_fd + static_cast<int32_T>(CheckPoints->size[0] <<
                      1))];
                LDp[2] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(rtb_Bias_fd + static_cast<int32_T>
                      (CheckPoints->size[0] << 1)) + 1)];
                rtb_startPose_i[3] = CheckPoints->data[static_cast<int32_T>
                    (rtb_Bias_fd + static_cast<int32_T>(CheckPoints->size[0] * 3))];
                LDp[3] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(rtb_Bias_fd + static_cast<int32_T>
                      (CheckPoints->size[0] * 3)) + 1)];
                FlightMissionMode_genSegWP_j(&connectionObj, rtb_startPose_i,
                    LDp, 100.0, segWayPoints, localDW);
                CheckPoints_0 = static_cast<int32_T>(dummyWayPoint_0->size[0] *
                    dummyWayPoint_0->size[1]);
                dummyWayPoint_0->size[0] = static_cast<int32_T>
                    (dummyWayPoint->size[0] + segWayPoints->size[0]);
                dummyWayPoint_0->size[1] = 3;
                FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint_0,
                    CheckPoints_0);
                ibmat = dummyWayPoint->size[0];
                for (iacol = 0; iacol < 3; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                            (ibmat - 1); CheckPoints_0++) {
                        dummyWayPoint_0->data[static_cast<int32_T>(CheckPoints_0
                            + static_cast<int32_T>(dummyWayPoint_0->size[0] *
                            iacol))] = dummyWayPoint->data[static_cast<int32_T>
                            (CheckPoints_0 + static_cast<int32_T>
                             (dummyWayPoint->size[0] * iacol))];
                    }
                }

                ibmat = segWayPoints->size[0];
                for (iacol = 0; iacol < 3; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                            (ibmat - 1); CheckPoints_0++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                            (static_cast<int32_T>(CheckPoints_0 +
                              dummyWayPoint->size[0]) + static_cast<int32_T>
                             (dummyWayPoint_0->size[0] * iacol))] =
                            segWayPoints->data[static_cast<int32_T>
                            (CheckPoints_0 + static_cast<int32_T>
                             (segWayPoints->size[0] * iacol))];
                    }
                }

                CheckPoints_0 = static_cast<int32_T>(dummyWayPoint->size[0] *
                    dummyWayPoint->size[1]);
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint,
                    CheckPoints_0);
                ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                for (iacol = 0; iacol <= static_cast<int32_T>(ibmat - 1); iacol
                        ++) {
                    dummyWayPoint->data[iacol] = dummyWayPoint_0->data[iacol];
                }
            }

            rtb_startPose_i[0] = CheckPoints->data[static_cast<int32_T>
                (CheckPoints->size[0] - 1)];
            LDp[0] = CheckPoints->data[0];
            rtb_startPose_i[1] = CheckPoints->data[static_cast<int32_T>(
                static_cast<int32_T>(CheckPoints->size[0] + CheckPoints->size[0])
                - 1)];
            LDp[1] = CheckPoints->data[CheckPoints->size[0]];
            rtb_startPose_i[2] = CheckPoints->data[static_cast<int32_T>(
                static_cast<int32_T>(CheckPoints->size[0] + static_cast<int32_T>
                (CheckPoints->size[0] << 1)) - 1)];
            LDp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
                << 1)];
            rtb_startPose_i[3] = CheckPoints->data[static_cast<int32_T>(
                static_cast<int32_T>(CheckPoints->size[0] + static_cast<int32_T>
                (CheckPoints->size[0] * 3)) - 1)];
            LDp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
                * 3)];
            FlightMissionMode_genSegWP_j(&connectionObj, rtb_startPose_i, LDp,
                100.0, segWayPoints, localDW);
            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint_0->size[0] *
                dummyWayPoint_0->size[1]);
            dummyWayPoint_0->size[0] = static_cast<int32_T>(dummyWayPoint->size
                [0] + segWayPoints->size[0]);
            dummyWayPoint_0->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint_0,
                CheckPoints_0);
            ibmat = dummyWayPoint->size[0];
            rtb_Bias_fd = segWayPoints->size[0];
            for (iacol = 0; iacol < 3; iacol++) {
                for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                        (ibmat - 1); CheckPoints_0++) {
                    dummyWayPoint_0->data[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(dummyWayPoint_0->size[0] * iacol))]
                        = dummyWayPoint->data[static_cast<int32_T>(CheckPoints_0
                        + static_cast<int32_T>(dummyWayPoint->size[0] * iacol))];
                }

                for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                        (rtb_Bias_fd - 1); CheckPoints_0++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                        (static_cast<int32_T>(CheckPoints_0 +
                          dummyWayPoint->size[0]) + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * iacol))] =
                        segWayPoints->data[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(segWayPoints->size[0] * iacol))];
                }
            }

            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint->size[0] *
                dummyWayPoint->size[1]);
            dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
            dummyWayPoint->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint,
                CheckPoints_0);
            ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
            for (iacol = 0; iacol <= static_cast<int32_T>(ibmat - 1); iacol++) {
                dummyWayPoint->data[iacol] = dummyWayPoint_0->data[iacol];
            }

            rtb_Bias_fd = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
            nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
            for (iacol = 0; iacol <= rtb_Bias_fd; iacol = static_cast<int32_T>
                    (iacol + 1)) {
                dummyWayPoint->data[iacol] = dummyWayPoint->data
                    [static_cast<int32_T>(iacol + 1)];
            }

            for (iacol = 0; iacol <= rtb_Bias_fd; iacol = static_cast<int32_T>
                    (iacol + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(iacol +
                    dummyWayPoint->size[0])] = dummyWayPoint->data
                    [static_cast<int32_T>(static_cast<int32_T>(iacol +
                    dummyWayPoint->size[0]) + 1)];
            }

            for (iacol = 0; iacol <= rtb_Bias_fd; iacol = static_cast<int32_T>
                    (iacol + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(iacol +
                    static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                    dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                    (iacol + static_cast<int32_T>(dummyWayPoint->size[0] << 1))
                    + 1)];
            }

            if (1 > nrows) {
                ibmat = -1;
            } else {
                ibmat = rtb_Bias_fd;
            }

            CheckPoints_0 = static_cast<int32_T>(segWayPoints->size[0] *
                segWayPoints->size[1]);
            segWayPoints->size[0] = static_cast<int32_T>(ibmat + 1);
            segWayPoints->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(segWayPoints,
                CheckPoints_0);
            for (iacol = 0; iacol < 3; iacol++) {
                for (CheckPoints_0 = 0; CheckPoints_0 <= ibmat; CheckPoints_0++)
                {
                    segWayPoints->data[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(segWayPoints->size[0] * iacol))] =
                        dummyWayPoint->data[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(dummyWayPoint->size[0] * iacol))];
                }
            }

            if (1 > nrows) {
                iacol = -1;
                rtb_Bias_fd = -1;
            } else {
                iacol = rtb_Bias_fd;
            }

            rtb_Map2Radian = std::ceil(10240.0 / static_cast<real_T>(
                static_cast<int32_T>(iacol + 1)));
            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint->size[0] *
                dummyWayPoint->size[1]);
            dummyWayPoint->size[0] = static_cast<int32_T>(static_cast<int32_T>
                (rtb_Bias_fd + 1) * static_cast<int32_T>(rtb_Map2Radian));
            dummyWayPoint->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint,
                CheckPoints_0);
            rtb_Bias_fd = segWayPoints->size[0];
            for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>(
                    static_cast<int32_T>(rtb_Map2Radian) - 1); CheckPoints_0 =
                    static_cast<int32_T>(CheckPoints_0 + 1)) {
                nrows = static_cast<int32_T>(static_cast<int32_T>(CheckPoints_0 *
                    rtb_Bias_fd) + -1);
                for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>
                        (rtb_Bias_fd - 1); k = static_cast<int32_T>(k + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>(nrows + k)] =
                        segWayPoints->data[static_cast<int32_T>(k - 1)];
                }
            }

            ibmat = static_cast<int32_T>(static_cast<int32_T>(segWayPoints->
                size[0] * static_cast<int32_T>(rtb_Map2Radian)) - 1);
            for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>(
                    static_cast<int32_T>(rtb_Map2Radian) - 1); CheckPoints_0 =
                    static_cast<int32_T>(CheckPoints_0 + 1)) {
                nrows = static_cast<int32_T>(static_cast<int32_T>(CheckPoints_0 *
                    rtb_Bias_fd) + ibmat);
                for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>
                        (rtb_Bias_fd - 1); k = static_cast<int32_T>(k + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>(nrows + k)] =
                        segWayPoints->data[static_cast<int32_T>
                        (static_cast<int32_T>(rtb_Bias_fd + k) - 1)];
                }
            }

            iacol = static_cast<int32_T>(segWayPoints->size[0] << 1);
            ibmat = static_cast<int32_T>(static_cast<int32_T>
                (static_cast<int32_T>(segWayPoints->size[0] *
                static_cast<int32_T>(rtb_Map2Radian)) << 1) - 1);
            for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>(
                    static_cast<int32_T>(rtb_Map2Radian) - 1); CheckPoints_0 =
                    static_cast<int32_T>(CheckPoints_0 + 1)) {
                nrows = static_cast<int32_T>(static_cast<int32_T>(CheckPoints_0 *
                    rtb_Bias_fd) + ibmat);
                for (k = 1; static_cast<int32_T>(k - 1) <= static_cast<int32_T>
                        (rtb_Bias_fd - 1); k = static_cast<int32_T>(k + 1)) {
                    dummyWayPoint->data[static_cast<int32_T>(nrows + k)] =
                        segWayPoints->data[static_cast<int32_T>
                        (static_cast<int32_T>(iacol + k) - 1)];
                }
            }

            rtb_RelPrevPos_n_0[0] = rtb_Sum1_j_idx_1;
            rtb_RelPrevPos_n_0[1] = rtb_Sum1_j_idx_0;
            rtb_RelPrevPos_n_0[2] = rtb_RelPrevPos_n_idx_2;
            rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtb_RelPrevPos_n_0,
                localDW->RotateATMissionHdg.RotateATMissionHdg,
                rtb_RotateIndivWayPointStartpose1);
            LDp[0] = rtb_RotateIndivWayPointStartpose1[0];
            LDp[1] = rtb_RotateIndivWayPointStartpose1[1];
            LDp[2] = rtb_RotateIndivWayPointStartpose1[2];
            LDp[3] = 1.5707963267948966;
            rtb_startPose_i[0] = CheckPoints->data[0];
            rtb_startPose_i[1] = CheckPoints->data[CheckPoints->size[0]];
            rtb_startPose_i[2] = CheckPoints->data[static_cast<int32_T>
                (CheckPoints->size[0] << 1)];
            rtb_startPose_i[3] = CheckPoints->data[static_cast<int32_T>
                (CheckPoints->size[0] * 3)];
            FlightMissionMode_genSegWP_j(&connectionObj, LDp, rtb_startPose_i,
                100.0, segWayPoints, localDW);
            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint_0->size[0] *
                dummyWayPoint_0->size[1]);
            dummyWayPoint_0->size[0] = static_cast<int32_T>(segWayPoints->size[0]
                + dummyWayPoint->size[0]);
            dummyWayPoint_0->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint_0,
                CheckPoints_0);
            ibmat = segWayPoints->size[0];
            rtb_Bias_fd = dummyWayPoint->size[0];
            for (iacol = 0; iacol < 3; iacol++) {
                for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                        (ibmat - 1); CheckPoints_0++) {
                    dummyWayPoint_0->data[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(dummyWayPoint_0->size[0] * iacol))]
                        = segWayPoints->data[static_cast<int32_T>(CheckPoints_0
                        + static_cast<int32_T>(segWayPoints->size[0] * iacol))];
                }

                for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                        (rtb_Bias_fd - 1); CheckPoints_0++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                        (static_cast<int32_T>(CheckPoints_0 + segWayPoints->
                          size[0]) + static_cast<int32_T>(dummyWayPoint_0->size
                          [0] * iacol))] = dummyWayPoint->data
                        [static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(dummyWayPoint->size[0] * iacol))];
                }

                for (CheckPoints_0 = 0; CheckPoints_0 < 10240; CheckPoints_0++)
                {
                    localDW->WayPoint_h[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(10240 * iacol))] =
                        dummyWayPoint_0->data[static_cast<int32_T>(CheckPoints_0
                        + static_cast<int32_T>(dummyWayPoint_0->size[0] * iacol))];
                }
            }

            for (iacol = 0; iacol < 10240; iacol++) {
                localDW->rtb_WayPoint_h_c[iacol] = localDW->WayPoint_h[iacol] +
                    rtb_Abs1_o2;
                localDW->rtb_WayPoint_h_c[static_cast<int32_T>(iacol + 10240)] =
                    localDW->WayPoint_h[static_cast<int32_T>(iacol + 10240)];
                localDW->rtb_WayPoint_h_c[static_cast<int32_T>(iacol + 20480)] =
                    localDW->WayPoint_h[static_cast<int32_T>(iacol + 20480)];
            }

            for (iacol = 0; iacol < 3; iacol++) {
                for (CheckPoints_0 = 0; CheckPoints_0 < 10240; CheckPoints_0++)
                {
                    rtb_Bias_fd = static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(10240 * iacol));
                    localDW->RotateIndivWayPoint_n[rtb_Bias_fd] = 0.0;
                    localDW->RotateIndivWayPoint_n[rtb_Bias_fd] +=
                        localDW->RotateATMissionHdg.RotateATMissionHdg[
                        static_cast<int32_T>(3 * iacol)] *
                        localDW->rtb_WayPoint_h_c[CheckPoints_0];
                    localDW->RotateIndivWayPoint_n[rtb_Bias_fd] +=
                        localDW->RotateATMissionHdg.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 1)]
                        * localDW->rtb_WayPoint_h_c[static_cast<int32_T>
                        (CheckPoints_0 + 10240)];
                    localDW->RotateIndivWayPoint_n[rtb_Bias_fd] +=
                        localDW->RotateATMissionHdg.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 2)]
                        * localDW->rtb_WayPoint_h_c[static_cast<int32_T>
                        (CheckPoints_0 + 20480)];
                }
            }

            FlightMissionMode_biasNED(rtb_ReshapeRowVec_ec,
                localDW->RotateIndivWayPoint_n, localDW->nedWayPoint_e,
                &localDW->sf_biasNED);
        } else {
            localDW->WayPointGenerator_MODE_l = false;
        }

        FlightMissionMode_WaypointFollower(rtu_Pose, localDW->nedWayPoint_e,
            200.0, &localDW->WaypointFollower);
        *rty_thisTaskStatus = static_cast<real_T>
            (localDW->WaypointFollower.WaypointFollower_o5);
        rty_GuidanceCmds->Height =
            -localDW->WaypointFollower.WaypointFollower_o1[2];
        rty_GuidanceCmds->AirSpeed = static_cast<real_T>(rtu_Parameters->Param4);
        rty_GuidanceCmds->HeadingAngle =
            localDW->WaypointFollower.WaypointFollower_o2;
        rty_InitialState[0] = std::cos(rtb_LatitudeGCS_n + 1.5707963267948966) *
            rtb_Abs1_o2 + rtb_ClockwiseRotation_l;
        rty_InitialState[1] = std::sin(rtb_LatitudeGCS_n + 1.5707963267948966) *
            rtb_Abs1_o2 + rtb_Cos_g;
        rty_InitialState[2] = -rtb_AltitudeGCS_e;
        rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
        rty_InitialState[4] = rtb_LatitudeGCS_n;
        rty_InitialState[5] = 0.0;
        rty_InitialState[6] = 0.0;
        rty_InitialState[7] = 0.0;
        break;

      case 3:
        if (static_cast<int32_T>(rtAction) != static_cast<int32_T>(rtPrevAction))
        {
            std::memset(&localDW->Memory_PreviousInput_h[0], 0,
                        static_cast<uint32_T>(sizeof(real_T) << 3U));
            FlightMissionMode_WaypointFollower_Reset
                (&localDW->WaypointFollower_p);
        }

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_Cos_g = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_AltitudeGCS_e = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_Abs1_o2 = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_j_idx_0 = rtu_PrevLocation->Lat - rtb_AltitudeGCS_e;
        rtb_Sum1_j_idx_1 = rtu_PrevLocation->Lon - rtb_Abs1_o2;
        if (std::abs(rtb_Sum1_j_idx_0) > 180.0) {
            rtb_Switch_f = rt_modd_snf(rtb_Sum1_j_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch_f = rtb_Sum1_j_idx_0;
        }

        rtb_Abs1_o2 = std::abs(rtb_Switch_f);
        if (rtb_Abs1_o2 > 90.0) {
            if (rtb_Switch_f < 0.0) {
                rtb_Switch_f = -1.0;
            } else if (rtb_Switch_f > 0.0) {
                rtb_Switch_f = 1.0;
            } else if (rtb_Switch_f == 0.0) {
                rtb_Switch_f = 0.0;
            } else {
                rtb_Switch_f = (rtNaN);
            }

            rtb_Switch_f *= -(rtb_Abs1_o2 + -90.0) + 90.0;
            iacol = 180;
        } else {
            iacol = 0;
        }

        rtb_Down2Up_n = static_cast<real_T>(iacol) + rtb_Sum1_j_idx_1;
        if (std::abs(rtb_Down2Up_n) > 180.0) {
            rtb_Down2Up_n = rt_modd_snf(rtb_Down2Up_n + 180.0, 360.0) + -180.0;
        }

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_j_idx_0 = 0.017453292519943295 * rtb_Switch_f;
        rtb_Sum1_j_idx_1 = 0.017453292519943295 * rtb_Down2Up_n;

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_AltitudeGCS_e *= 0.017453292519943295;
        rtb_Down2Up_n = std::sin(rtb_AltitudeGCS_e);
        rtb_Down2Up_n = 1.0 - 0.0066943799901413295 * rtb_Down2Up_n *
            rtb_Down2Up_n;
        rtb_Switch_f = 6.378137E+6 / std::sqrt(rtb_Down2Up_n);
        rtb_Down2Up_n = rtb_Sum1_j_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_f *
            0.99330562000985867 / rtb_Down2Up_n);

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_f = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_f * std::cos
            (rtb_AltitudeGCS_e)) * rtb_Sum1_j_idx_1;
        rtb_AltitudeGCS_e = rtb_Switch_f * 0.0 + rtb_Down2Up_n;
        rtb_ClockwiseRotation_l = rtb_Switch_f - rtb_Down2Up_n * 0.0;
        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_Abs1_o2 = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtb_Map2Radian = rtu_PrevLocation->Alt + -rtb_Abs1_o2;
        rtb_Map2Radian = -rtb_Map2Radian;
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_Down2Up_n = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_Abs1_o2 = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_j_idx_0 = rtu_Location->Lat - rtb_Down2Up_n;
        rtb_Sum1_j_idx_1 = rtu_Location->Lon - rtb_Abs1_o2;
        if (std::abs(rtb_Sum1_j_idx_0) > 180.0) {
            rtb_Switch_f = rt_modd_snf(rtb_Sum1_j_idx_0 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch_f = rtb_Sum1_j_idx_0;
        }

        rtb_Abs1_o2 = std::abs(rtb_Switch_f);
        if (rtb_Abs1_o2 > 90.0) {
            if (rtb_Switch_f < 0.0) {
                rtb_Switch_f = -1.0;
            } else if (rtb_Switch_f > 0.0) {
                rtb_Switch_f = 1.0;
            } else if (rtb_Switch_f == 0.0) {
                rtb_Switch_f = 0.0;
            } else {
                rtb_Switch_f = (rtNaN);
            }

            rtb_Switch_f *= -(rtb_Abs1_o2 + -90.0) + 90.0;
            iacol = 180;
        } else {
            iacol = 0;
        }

        rtb_Sum_f = static_cast<real_T>(iacol) + rtb_Sum1_j_idx_1;
        if (std::abs(rtb_Sum_f) > 180.0) {
            rtb_Sum_f = rt_modd_snf(rtb_Sum_f + 180.0, 360.0) + -180.0;
        }

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_j_idx_0 = 0.017453292519943295 * rtb_Switch_f;
        rtb_Sum1_j_idx_1 = 0.017453292519943295 * rtb_Sum_f;

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Down2Up_n *= 0.017453292519943295;
        rtb_Sum_f = std::sin(rtb_Down2Up_n);
        rtb_Sum_f = 1.0 - 0.0066943799901413295 * rtb_Sum_f * rtb_Sum_f;
        rtb_Switch_f = 6.378137E+6 / std::sqrt(rtb_Sum_f);
        rtb_Sum_f = rtb_Sum1_j_idx_0 / rt_atan2d_snf(1.0, rtb_Switch_f *
            0.99330562000985867 / rtb_Sum_f);

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Down2Up_n = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_f * std::cos
            (rtb_Down2Up_n)) * rtb_Sum1_j_idx_1;
        rtb_Switch_f = rtb_Down2Up_n * 0.0 + rtb_Sum_f;
        rtb_LatitudeGCS_n = rtb_Down2Up_n - rtb_Sum_f * 0.0;
        rtb_Cos_g = rtu_Location->Alt + -rtb_Cos_g;
        rtb_Down2Up_n = -rtu_StartPosition->Alt;
        rtb_Cos_g = -rtb_Cos_g + rtb_Down2Up_n;
        rtb_Sum1_j_idx_0 = rtb_AltitudeGCS_e - rtb_Switch_f;
        rtb_Abs1_o2 = 0.017453292519943295 * rtu_Location->degHDG;
        if (*rtu_Reset > 0) {
            localDW->WayPointGenerator_MODE_f = true;
            rtb_Down2Up_n = static_cast<real_T>(rtu_Parameters->Param3) *
                static_cast<real_T>(*rtu_MissionUAV);
            rtb_ReshapeRowVec_ec[0] = rtb_Switch_f;
            rtb_ReshapeRowVec_ec[1] = rtb_LatitudeGCS_n;
            rtb_ReshapeRowVec_ec[2] = rtb_Cos_g;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m5[0] =
                rtb_Abs1_o2;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m5[1] = 0.0;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m5[2] = 0.0;
            FlightMissionMode_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m5,
                 &localDW->RotateATMissionHdg_p);
            rtb_Switch_f = std::ceil(static_cast<real_T>(rtu_Parameters->Param2)
                / rtb_Down2Up_n);
            rtb_Down2Up_n = static_cast<real_T>(rtu_Parameters->Param2) /
                rtb_Switch_f;
            connectionObj.FlightPathAngleLimit[0] = -0.175;
            connectionObj.FlightPathAngleLimit[1] = 0.175;
            connectionObj.MaxRollAngle = 0.29670597283903605;
            connectionObj.AirSpeed = 35.0;
            connectionObj.MinTurningRadius = 408.85657731051754;
            iacol = static_cast<int32_T>(rtb_Switch_f * 2.0);
            CheckPoints_0 = static_cast<int32_T>(CheckPoints->size[0] *
                CheckPoints->size[1]);
            CheckPoints->size[0] = iacol;
            CheckPoints->size[1] = 4;
            FlightMissionMode_emxEnsureCapacity_real_T_c(CheckPoints,
                CheckPoints_0);
            ibmat = static_cast<int32_T>(static_cast<int32_T>(iacol << 2) - 1);
            for (CheckPoints_0 = 0; CheckPoints_0 <= ibmat; CheckPoints_0++) {
                CheckPoints->data[CheckPoints_0] = 0.0;
            }

            for (rtb_Bias_fd = 0; rtb_Bias_fd <= static_cast<int32_T>(
                    static_cast<int32_T>(rtb_Switch_f) - 1); rtb_Bias_fd =
                    static_cast<int32_T>(rtb_Bias_fd + 1)) {
                if (rt_remd_snf(static_cast<real_T>(rtb_Bias_fd) + 1.0, 2.0) ==
                        1.0) {
                    iacol = static_cast<int32_T>(static_cast<int32_T>
                        (rtb_Bias_fd + 1) << 1);
                    rtb_Sum_f = ((static_cast<real_T>(rtb_Bias_fd) + 1.0) - 1.0)
                        * rtb_Down2Up_n;
                    CheckPoints->data[static_cast<int32_T>(iacol - 2)] =
                        rtb_Sum_f;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + CheckPoints->size[0]) - 2)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] << 1))
                        - 2)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 2)] = 1.5707963267948966;
                    CheckPoints->data[static_cast<int32_T>(iacol - 1)] =
                        rtb_Sum_f;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + CheckPoints->size[0]) - 1)] =
                        static_cast<real_T>(rtu_Parameters->Param1);
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] << 1))
                        - 1)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 1)] = 1.5707963267948966;
                } else {
                    iacol = static_cast<int32_T>(static_cast<int32_T>
                        (rtb_Bias_fd + 1) << 1);
                    rtb_Sum_f = ((static_cast<real_T>(rtb_Bias_fd) + 1.0) - 1.0)
                        * rtb_Down2Up_n;
                    CheckPoints->data[static_cast<int32_T>(iacol - 2)] =
                        rtb_Sum_f;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + CheckPoints->size[0]) - 2)] =
                        static_cast<real_T>(rtu_Parameters->Param1);
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] << 1))
                        - 2)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 2)] = -1.5707963267948966;
                    CheckPoints->data[static_cast<int32_T>(iacol - 1)] =
                        rtb_Sum_f;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + CheckPoints->size[0]) - 1)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] << 1))
                        - 1)] = 0.0;
                    CheckPoints->data[static_cast<int32_T>(static_cast<int32_T>
                        (iacol + static_cast<int32_T>(CheckPoints->size[0] * 3))
                        - 1)] = -1.5707963267948966;
                }
            }

            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint->size[0] *
                dummyWayPoint->size[1]);
            dummyWayPoint->size[0] = 1;
            dummyWayPoint->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint,
                CheckPoints_0);
            dummyWayPoint->data[0] = 0.0;
            dummyWayPoint->data[1] = 0.0;
            dummyWayPoint->data[2] = 0.0;
            for (rtb_Bias_fd = 0; rtb_Bias_fd <= static_cast<int32_T>
                    (CheckPoints->size[0] - 2); rtb_Bias_fd =
                    static_cast<int32_T>(rtb_Bias_fd + 1)) {
                rtb_startPose_i[0] = CheckPoints->data[rtb_Bias_fd];
                LDp[0] = CheckPoints->data[static_cast<int32_T>(rtb_Bias_fd + 1)];
                rtb_startPose_i[1] = CheckPoints->data[static_cast<int32_T>
                    (rtb_Bias_fd + CheckPoints->size[0])];
                LDp[1] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(rtb_Bias_fd + CheckPoints->size[0]) +
                     1)];
                rtb_startPose_i[2] = CheckPoints->data[static_cast<int32_T>
                    (rtb_Bias_fd + static_cast<int32_T>(CheckPoints->size[0] <<
                      1))];
                LDp[2] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(rtb_Bias_fd + static_cast<int32_T>
                      (CheckPoints->size[0] << 1)) + 1)];
                rtb_startPose_i[3] = CheckPoints->data[static_cast<int32_T>
                    (rtb_Bias_fd + static_cast<int32_T>(CheckPoints->size[0] * 3))];
                LDp[3] = CheckPoints->data[static_cast<int32_T>
                    (static_cast<int32_T>(rtb_Bias_fd + static_cast<int32_T>
                      (CheckPoints->size[0] * 3)) + 1)];
                FlightMissionMode_genSegWP_j(&connectionObj, rtb_startPose_i,
                    LDp, 100.0, segWayPoints, localDW);
                CheckPoints_0 = static_cast<int32_T>(dummyWayPoint_0->size[0] *
                    dummyWayPoint_0->size[1]);
                dummyWayPoint_0->size[0] = static_cast<int32_T>
                    (dummyWayPoint->size[0] + segWayPoints->size[0]);
                dummyWayPoint_0->size[1] = 3;
                FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint_0,
                    CheckPoints_0);
                ibmat = dummyWayPoint->size[0];
                for (iacol = 0; iacol < 3; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                            (ibmat - 1); CheckPoints_0++) {
                        dummyWayPoint_0->data[static_cast<int32_T>(CheckPoints_0
                            + static_cast<int32_T>(dummyWayPoint_0->size[0] *
                            iacol))] = dummyWayPoint->data[static_cast<int32_T>
                            (CheckPoints_0 + static_cast<int32_T>
                             (dummyWayPoint->size[0] * iacol))];
                    }
                }

                ibmat = segWayPoints->size[0];
                for (iacol = 0; iacol < 3; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                            (ibmat - 1); CheckPoints_0++) {
                        dummyWayPoint_0->data[static_cast<int32_T>
                            (static_cast<int32_T>(CheckPoints_0 +
                              dummyWayPoint->size[0]) + static_cast<int32_T>
                             (dummyWayPoint_0->size[0] * iacol))] =
                            segWayPoints->data[static_cast<int32_T>
                            (CheckPoints_0 + static_cast<int32_T>
                             (segWayPoints->size[0] * iacol))];
                    }
                }

                CheckPoints_0 = static_cast<int32_T>(dummyWayPoint->size[0] *
                    dummyWayPoint->size[1]);
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint,
                    CheckPoints_0);
                ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
                for (iacol = 0; iacol <= static_cast<int32_T>(ibmat - 1); iacol
                        ++) {
                    dummyWayPoint->data[iacol] = dummyWayPoint_0->data[iacol];
                }
            }

            rtb_startPose_i[0] = CheckPoints->data[static_cast<int32_T>
                (CheckPoints->size[0] - 1)];
            LDp[0] = CheckPoints->data[0];
            rtb_startPose_i[1] = CheckPoints->data[static_cast<int32_T>(
                static_cast<int32_T>(CheckPoints->size[0] + CheckPoints->size[0])
                - 1)];
            LDp[1] = CheckPoints->data[CheckPoints->size[0]];
            rtb_startPose_i[2] = CheckPoints->data[static_cast<int32_T>(
                static_cast<int32_T>(CheckPoints->size[0] + static_cast<int32_T>
                (CheckPoints->size[0] << 1)) - 1)];
            LDp[2] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
                << 1)];
            rtb_startPose_i[3] = CheckPoints->data[static_cast<int32_T>(
                static_cast<int32_T>(CheckPoints->size[0] + static_cast<int32_T>
                (CheckPoints->size[0] * 3)) - 1)];
            LDp[3] = CheckPoints->data[static_cast<int32_T>(CheckPoints->size[0]
                * 3)];
            FlightMissionMode_genSegWP_j(&connectionObj, rtb_startPose_i, LDp,
                100.0, segWayPoints, localDW);
            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint_0->size[0] *
                dummyWayPoint_0->size[1]);
            dummyWayPoint_0->size[0] = static_cast<int32_T>(dummyWayPoint->size
                [0] + segWayPoints->size[0]);
            dummyWayPoint_0->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint_0,
                CheckPoints_0);
            ibmat = dummyWayPoint->size[0];
            rtb_Bias_fd = segWayPoints->size[0];
            for (iacol = 0; iacol < 3; iacol++) {
                for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                        (ibmat - 1); CheckPoints_0++) {
                    dummyWayPoint_0->data[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(dummyWayPoint_0->size[0] * iacol))]
                        = dummyWayPoint->data[static_cast<int32_T>(CheckPoints_0
                        + static_cast<int32_T>(dummyWayPoint->size[0] * iacol))];
                }

                for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                        (rtb_Bias_fd - 1); CheckPoints_0++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                        (static_cast<int32_T>(CheckPoints_0 +
                          dummyWayPoint->size[0]) + static_cast<int32_T>
                         (dummyWayPoint_0->size[0] * iacol))] =
                        segWayPoints->data[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(segWayPoints->size[0] * iacol))];
                }
            }

            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint->size[0] *
                dummyWayPoint->size[1]);
            dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
            dummyWayPoint->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint,
                CheckPoints_0);
            ibmat = static_cast<int32_T>(dummyWayPoint_0->size[0] * 3);
            for (iacol = 0; iacol <= static_cast<int32_T>(ibmat - 1); iacol++) {
                dummyWayPoint->data[iacol] = dummyWayPoint_0->data[iacol];
            }

            FlightMissionMode_emxInit_real_T_h(&dummyWayPoint_1, 2);
            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint_1->size[0] *
                dummyWayPoint_1->size[1]);
            dummyWayPoint_1->size[0] = dummyWayPoint->size[0];
            dummyWayPoint_1->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint_1,
                CheckPoints_0);
            iacol = static_cast<int32_T>(static_cast<int32_T>
                (dummyWayPoint->size[0] * dummyWayPoint->size[1]) - 1);
            for (CheckPoints_0 = 0; CheckPoints_0 <= iacol; CheckPoints_0++) {
                dummyWayPoint_1->data[CheckPoints_0] = dummyWayPoint->
                    data[CheckPoints_0];
            }

            FlightMissionMode_repmat(dummyWayPoint_1, std::ceil(10240.0 /
                static_cast<real_T>(dummyWayPoint->size[0])), dummyWayPoint);
            rtb_Bias_fd = static_cast<int32_T>(dummyWayPoint->size[0] - 2);
            nrows = static_cast<int32_T>(dummyWayPoint->size[0] - 1);
            iacol = 0;
            FlightMissionMode_emxFree_real_T_n(&dummyWayPoint_1);
            while (iacol <= rtb_Bias_fd) {
                dummyWayPoint->data[iacol] = dummyWayPoint->data
                    [static_cast<int32_T>(iacol + 1)];
                iacol = static_cast<int32_T>(iacol + 1);
            }

            for (iacol = 0; iacol <= rtb_Bias_fd; iacol = static_cast<int32_T>
                    (iacol + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(iacol +
                    dummyWayPoint->size[0])] = dummyWayPoint->data
                    [static_cast<int32_T>(static_cast<int32_T>(iacol +
                    dummyWayPoint->size[0]) + 1)];
            }

            for (iacol = 0; iacol <= rtb_Bias_fd; iacol = static_cast<int32_T>
                    (iacol + 1)) {
                dummyWayPoint->data[static_cast<int32_T>(iacol +
                    static_cast<int32_T>(dummyWayPoint->size[0] << 1))] =
                    dummyWayPoint->data[static_cast<int32_T>(static_cast<int32_T>
                    (iacol + static_cast<int32_T>(dummyWayPoint->size[0] << 1))
                    + 1)];
            }

            rtb_RelPrevPos_n_0[0] = rtb_ClockwiseRotation_l - rtb_LatitudeGCS_n;
            rtb_RelPrevPos_n_0[1] = rtb_Sum1_j_idx_0;
            rtb_RelPrevPos_n_0[2] = rtb_Map2Radian - rtb_Cos_g;
            rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtb_RelPrevPos_n_0,
                localDW->RotateATMissionHdg_p.RotateATMissionHdg,
                rtb_RotateIndivWayPointStartpose1);
            LDp[0] = rtb_RotateIndivWayPointStartpose1[0];
            LDp[1] = rtb_RotateIndivWayPointStartpose1[1];
            LDp[2] = rtb_RotateIndivWayPointStartpose1[2];
            LDp[3] = 1.5707963267948966;
            rtb_startPose_i[0] = CheckPoints->data[0];
            rtb_startPose_i[1] = CheckPoints->data[CheckPoints->size[0]];
            rtb_startPose_i[2] = CheckPoints->data[static_cast<int32_T>
                (CheckPoints->size[0] << 1)];
            rtb_startPose_i[3] = CheckPoints->data[static_cast<int32_T>
                (CheckPoints->size[0] * 3)];
            FlightMissionMode_genSegWP_j(&connectionObj, LDp, rtb_startPose_i,
                100.0, segWayPoints, localDW);
            if (1 > nrows) {
                rtb_Bias_fd = -1;
            }

            CheckPoints_0 = static_cast<int32_T>(dummyWayPoint_0->size[0] *
                dummyWayPoint_0->size[1]);
            dummyWayPoint_0->size[0] = static_cast<int32_T>(static_cast<int32_T>
                (segWayPoints->size[0] + rtb_Bias_fd) + 1);
            dummyWayPoint_0->size[1] = 3;
            FlightMissionMode_emxEnsureCapacity_real_T_c(dummyWayPoint_0,
                CheckPoints_0);
            ibmat = segWayPoints->size[0];
            for (iacol = 0; iacol < 3; iacol++) {
                for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                        (ibmat - 1); CheckPoints_0++) {
                    dummyWayPoint_0->data[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(dummyWayPoint_0->size[0] * iacol))]
                        = segWayPoints->data[static_cast<int32_T>(CheckPoints_0
                        + static_cast<int32_T>(segWayPoints->size[0] * iacol))];
                }

                for (CheckPoints_0 = 0; CheckPoints_0 <= rtb_Bias_fd;
                        CheckPoints_0++) {
                    dummyWayPoint_0->data[static_cast<int32_T>
                        (static_cast<int32_T>(CheckPoints_0 + segWayPoints->
                          size[0]) + static_cast<int32_T>(dummyWayPoint_0->size
                          [0] * iacol))] = dummyWayPoint->data
                        [static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(dummyWayPoint->size[0] * iacol))];
                }

                for (CheckPoints_0 = 0; CheckPoints_0 < 10240; CheckPoints_0++)
                {
                    localDW->RotateIndivWayPoint_n[static_cast<int32_T>
                        (CheckPoints_0 + static_cast<int32_T>(10240 * iacol))] =
                        dummyWayPoint_0->data[static_cast<int32_T>(CheckPoints_0
                        + static_cast<int32_T>(dummyWayPoint_0->size[0] * iacol))];
                }
            }

            for (iacol = 0; iacol < 10240; iacol++) {
                localDW->WayPoint_h[iacol] = localDW->
                    RotateIndivWayPoint_n[iacol] + rtu_StartPosition->Lon;
                localDW->WayPoint_h[static_cast<int32_T>(iacol + 10240)] =
                    localDW->RotateIndivWayPoint_n[static_cast<int32_T>(iacol +
                    10240)];
                localDW->WayPoint_h[static_cast<int32_T>(iacol + 20480)] =
                    localDW->RotateIndivWayPoint_n[static_cast<int32_T>(iacol +
                    20480)];
            }

            for (iacol = 0; iacol < 3; iacol++) {
                for (CheckPoints_0 = 0; CheckPoints_0 < 10240; CheckPoints_0++)
                {
                    rtb_Bias_fd = static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(10240 * iacol));
                    localDW->RotateIndivWayPoint_n[rtb_Bias_fd] = 0.0;
                    localDW->RotateIndivWayPoint_n[rtb_Bias_fd] +=
                        localDW->RotateATMissionHdg_p.RotateATMissionHdg[
                        static_cast<int32_T>(3 * iacol)] * localDW->
                        WayPoint_h[CheckPoints_0];
                    localDW->RotateIndivWayPoint_n[rtb_Bias_fd] +=
                        localDW->RotateATMissionHdg_p.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 1)]
                        * localDW->WayPoint_h[static_cast<int32_T>(CheckPoints_0
                        + 10240)];
                    localDW->RotateIndivWayPoint_n[rtb_Bias_fd] +=
                        localDW->RotateATMissionHdg_p.RotateATMissionHdg[
                        static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 2)]
                        * localDW->WayPoint_h[static_cast<int32_T>(CheckPoints_0
                        + 20480)];
                }
            }

            FlightMissionMode_biasNED(rtb_ReshapeRowVec_ec,
                localDW->RotateIndivWayPoint_n, localDW->nedWayPoint_m,
                &localDW->sf_biasNED_f);
        } else {
            localDW->WayPointGenerator_MODE_f = false;
        }

        FlightMissionMode_WaypointFollower(rtu_Pose, localDW->nedWayPoint_m,
            200.0, &localDW->WaypointFollower_p);
        *rty_thisTaskStatus = static_cast<real_T>
            (localDW->WaypointFollower_p.WaypointFollower_o5);
        rtb_Switch_f = std::sin(rtb_Abs1_o2) * rtu_StartPosition->Lat;
        rtb_LatitudeGCS_n = std::cos(rtb_Abs1_o2) * rtu_StartPosition->Lat;
        rty_GuidanceCmds->Height =
            -localDW->WaypointFollower_p.WaypointFollower_o1[2];
        rty_GuidanceCmds->AirSpeed = static_cast<real_T>(rtu_Parameters->Param4);
        rty_GuidanceCmds->HeadingAngle =
            localDW->WaypointFollower_p.WaypointFollower_o2;
        std::memcpy(&rty_InitialState[0], &localDW->Memory_PreviousInput_h[0],
                    static_cast<uint32_T>(sizeof(real_T) << 3U));
        rtb_Sum_f = std::cos(rtb_Abs1_o2 + 1.5707963267948966) *
            rtu_StartPosition->Lon;
        rtb_Cos_g = std::sin(rtb_Abs1_o2 + 1.5707963267948966) *
            rtu_StartPosition->Lon;
        localDW->Memory_PreviousInput_h[2] = rtu_StartPosition->Alt +
            -rtb_Map2Radian;
        localDW->Memory_PreviousInput_h[0] = (rtb_AltitudeGCS_e + rtb_Sum_f) +
            rtb_LatitudeGCS_n;
        localDW->Memory_PreviousInput_h[1] = (rtb_ClockwiseRotation_l +
            rtb_Switch_f) + rtb_Cos_g;
        localDW->Memory_PreviousInput_h[3] = static_cast<real_T>
            (rtu_Parameters->Param4);
        localDW->Memory_PreviousInput_h[4] = rtb_Abs1_o2;
        localDW->Memory_PreviousInput_h[5] = 0.0;
        localDW->Memory_PreviousInput_h[6] = 0.0;
        localDW->Memory_PreviousInput_h[7] = 0.0;
        break;

      case 4:
        if (static_cast<int32_T>(rtAction) != static_cast<int32_T>(rtPrevAction))
        {
            localDW->Memory_PreviousInput_f = 0.0;
            localDW->is_Running_f = FlightMissionMode_IN_NO_ACTIVE_CHILD;
            localDW->is_active_c3_FlightMissionMode = 0U;
            localDW->RunWayMode = RunWaySegment_None;
        }

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_Cos_g = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_LatitudeGCS_n = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_Abs1_o2 = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_j_idx_0 = rtu_Location->Lat - rtb_LatitudeGCS_n;
        rtb_Sum1_j_idx_1 = rtu_Location->Lon - rtb_Abs1_o2;
        if (std::abs(rtb_Sum1_j_idx_0) > 180.0) {
            rtb_AltitudeGCS_e = rt_modd_snf(rtb_Sum1_j_idx_0 + 180.0, 360.0) +
                -180.0;
        } else {
            rtb_AltitudeGCS_e = rtb_Sum1_j_idx_0;
        }

        rtb_Abs1_o2 = std::abs(rtb_AltitudeGCS_e);
        if (rtb_Abs1_o2 > 90.0) {
            if (rtb_AltitudeGCS_e < 0.0) {
                rtb_AltitudeGCS_e = -1.0;
            } else if (rtb_AltitudeGCS_e > 0.0) {
                rtb_AltitudeGCS_e = 1.0;
            } else if (rtb_AltitudeGCS_e == 0.0) {
                rtb_AltitudeGCS_e = 0.0;
            } else {
                rtb_AltitudeGCS_e = (rtNaN);
            }

            rtb_AltitudeGCS_e *= -(rtb_Abs1_o2 + -90.0) + 90.0;
            iacol = 180;
        } else {
            iacol = 0;
        }

        rtb_ClockwiseRotation_l = static_cast<real_T>(iacol) + rtb_Sum1_j_idx_1;
        if (std::abs(rtb_ClockwiseRotation_l) > 180.0) {
            rtb_ClockwiseRotation_l = rt_modd_snf(rtb_ClockwiseRotation_l +
                180.0, 360.0) + -180.0;
        }

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_j_idx_0 = 0.017453292519943295 * rtb_AltitudeGCS_e;
        rtb_Sum1_j_idx_1 = 0.017453292519943295 * rtb_ClockwiseRotation_l;

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_LatitudeGCS_n *= 0.017453292519943295;
        rtb_ClockwiseRotation_l = std::sin(rtb_LatitudeGCS_n);
        rtb_ClockwiseRotation_l = 1.0 - 0.0066943799901413295 *
            rtb_ClockwiseRotation_l * rtb_ClockwiseRotation_l;
        rtb_AltitudeGCS_e = 6.378137E+6 / std::sqrt(rtb_ClockwiseRotation_l);
        rtb_ClockwiseRotation_l = rtb_Sum1_j_idx_0 / rt_atan2d_snf(1.0,
            rtb_AltitudeGCS_e * 0.99330562000985867 / rtb_ClockwiseRotation_l);

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_AltitudeGCS_e = 1.0 / rt_atan2d_snf(1.0, rtb_AltitudeGCS_e * std::
            cos(rtb_LatitudeGCS_n)) * rtb_Sum1_j_idx_1;
        rtb_Cos_g = rtu_Location->Alt + -rtb_Cos_g;
        rtb_LatitudeGCS_n = 0.017453292519943295 * rtu_Location->degHDG;
        if (*rtu_Reset > 0) {
            localDW->WayPointGenerator_MODE_a = true;
            rtb_Switch_f = 0.017453292519943295 * static_cast<real_T>
                (rtu_Parameters->Param2) * static_cast<real_T>
                (rtu_Parameters->Param5);
            rtb_Down2Up_n = static_cast<real_T>(*rtu_FormationIDX);
            localDW->ModRunWayPose = rt_modd_snf(rtb_Down2Up_n, 3.0);
            FlightMissionMode_uavDubinsConnection_uavDubinsConnection
                (&connectionObj);
            LDp[0] = 0.0;
            rtb_Map2Radian = static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
            LDp[1] = rtb_Map2Radian;
            LDp[2] = 0.0;
            LDp[3] = 1.5707963267948966;
            tmp[0] = 0.0;
            rtb_Abs1_o2 = -static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
            tmp[1] = rtb_Abs1_o2;
            tmp[2] = 0.0;
            tmp[3] = 1.5707963267948966;
            FlightMissionMode_uavDubinsConnection_connect_o(&connectionObj, LDp,
                tmp, localDW->pathSegObj.data, &localDW->pathSegObj.size,
                a__1_data, &iacol, localDW);
            FlightMissionMode_uavDubinsPathSegment_interpolate_f
                (localDW->pathSegObj.data[0].StartPose, localDW->
                 pathSegObj.data[0].GoalPose, localDW->pathSegObj.data[0].
                 FlightPathAngle, localDW->pathSegObj.data[0].AirSpeed,
                 localDW->pathSegObj.data[0].MinTurningRadius,
                 localDW->pathSegObj.data[0].HelixRadius,
                 localDW->pathSegObj.data[0].MotionTypes,
                 localDW->pathSegObj.data[0].MotionLengths,
                 localDW->pathSegObj.data[0].Length, localDW->pathSegObj.data[0]
                 .Length / 2.0, midpose_data, midpose_size);
            switch (static_cast<int32_T>(localDW->ModRunWayPose)) {
              case 0:
                rtb_startPose_i[0] = 0.0;
                rtb_startPose_i[1] = rtb_Map2Radian - ((localDW->
                    pathSegObj.data[0].Length + static_cast<real_T>
                    (rtu_Parameters->Param3)) / 3.0 - localDW->pathSegObj.data[0]
                    .Length / 2.0);
                rtb_startPose_i[2] = 0.0;
                rtb_startPose_i[3] = 1.5707963267948966;
                break;

              case 1:
                rtb_startPose_i[0] = midpose_data[0];
                rtb_startPose_i[1] = midpose_data[midpose_size[0]];
                rtb_startPose_i[2] = midpose_data[static_cast<int32_T>
                    (midpose_size[0] << 1)];
                rtb_startPose_i[3] = midpose_data[static_cast<int32_T>
                    (midpose_size[0] * 3)];
                break;

              case 2:
                rtb_startPose_i[0] = 0.0;
                rtb_startPose_i[1] = ((localDW->pathSegObj.data[0].Length +
                                       static_cast<real_T>
                                       (rtu_Parameters->Param3)) / 3.0 -
                                      localDW->pathSegObj.data[0].Length / 2.0)
                    + rtb_Abs1_o2;
                rtb_startPose_i[2] = 0.0;
                rtb_startPose_i[3] = 1.5707963267948966;
                break;

              default:
                rtb_startPose_i[0] = 0.0;
                rtb_startPose_i[1] = 0.0;
                rtb_startPose_i[2] = 0.0;
                rtb_startPose_i[3] = 0.0;
                break;
            }

            localDW->Bias1 = ((rtb_LatitudeGCS_n + rtb_Switch_f) +
                              rtb_startPose_i[3]) + -1.5707963267948966;
            rtb_Down2Up_n = 15.0 * rt_modd_snf(static_cast<real_T>
                (rtu_Parameters->Param5), 3.0);
            rtb_Sum1_j_idx_0 = rtb_startPose_i[0];
            rtb_Sum1_j_idx_1 = rtb_startPose_i[1] - static_cast<real_T>
                (rtu_Parameters->Param1);
            rtb_RelPrevPos_n_idx_2 = rtb_startPose_i[2] - rtb_Down2Up_n;
            FlightMissionMode_WayPointGenerator(static_cast<real_T>
                (rtu_Parameters->Param3), &localDW->MatrixConcatenateWayPoint_d
                [0], &localDW->MatrixConcatenateWayPoint_d[300],
                &localDW->MatrixConcatenateWayPoint_d[600],
                &localDW->MatrixConcatenateWayPoint_d[900], 100.0,
                &localDW->sf_WayPointGenerator_a);
            rtb_ReshapeRowVec_ec[0] = 0.0;
            rtb_ReshapeRowVec_ec[1] = static_cast<real_T>(rtu_Parameters->Param1);
            rtb_ReshapeRowVec_ec[2] = rtb_Down2Up_n;
            rtb_ReshapeRowVecStartpose_c[0] = rtb_AltitudeGCS_e * 0.0 +
                rtb_ClockwiseRotation_l;
            rtb_ReshapeRowVecStartpose_c[1] = rtb_AltitudeGCS_e -
                rtb_ClockwiseRotation_l * 0.0;
            rtb_ReshapeRowVecStartpose_c[2] = -rtb_Cos_g;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m[0] =
                rtb_LatitudeGCS_n;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m[1] = 0.0;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m[2] = 0.0;
            FlightMissionMode_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1_m,
                 &localDW->RotateATMissionHdg_pn);
            rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_o[0] =
                rtb_Switch_f;
            rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_o[1] = 0.0;
            rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_o[2] = 0.0;
            FlightMissionMode_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATRunWayHdgInport1_o,
                 &localDW->RotateATRunWayHdg);
            for (iacol = 0; iacol < 3; iacol++) {
                rtb_RelPrevPos_n_0[iacol] =
                    localDW->RotateATRunWayHdg.RotateATMissionHdg
                    [static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 2)] *
                    rtb_RelPrevPos_n_idx_2 +
                    (localDW->RotateATRunWayHdg.RotateATMissionHdg
                     [static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 1)]
                     * rtb_Sum1_j_idx_1 +
                     localDW->RotateATRunWayHdg.RotateATMissionHdg
                     [static_cast<int32_T>(3 * iacol)] * rtb_Sum1_j_idx_0);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                rtb_RotateIndivWayPointStartpose1[iacol] =
                    localDW->RotateATMissionHdg_pn.RotateATMissionHdg[
                    static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 2)] *
                    rtb_RelPrevPos_n_0[2] +
                    (localDW->RotateATMissionHdg_pn.RotateATMissionHdg[
                     static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 1)] *
                     rtb_RelPrevPos_n_0[1] +
                     localDW->RotateATMissionHdg_pn.RotateATMissionHdg[
                     static_cast<int32_T>(3 * iacol)] * rtb_RelPrevPos_n_0[0]);
            }

            for (nrows = 0; nrows < 4; nrows++) {
                for (iacol = 0; iacol < 3; iacol++) {
                    std::memcpy
                        (&rtb_ImpSel_InsertedFor_RawRunWay_at_outport_0_b[
                         static_cast<int32_T>(iacol * 100)],
                         &localDW->MatrixConcatenateWayPoint_d[static_cast<
                         int32_T>(static_cast<int32_T>(nrows * 300) +
                                  static_cast<int32_T>(iacol * 100))],
                         static_cast<uint32_T>(100U * sizeof(real_T)));
                }

                FlightMissionMode_minus
                    (rtb_ImpSel_InsertedFor_RawRunWay_at_outport_0_b,
                     rtb_ReshapeRowVec_ec, rtb_y);
                for (iacol = 0; iacol < 100; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 < 3; CheckPoints_0++)
                    {
                        rtb_Bias_fd = static_cast<int32_T>(iacol +
                            static_cast<int32_T>(100 * CheckPoints_0));
                        segWayPoints_0[rtb_Bias_fd] = 0.0;
                        segWayPoints_0[rtb_Bias_fd] +=
                            localDW->RotateATRunWayHdg.RotateATMissionHdg[
                            static_cast<int32_T>(3 * CheckPoints_0)] *
                            rtb_y[iacol];
                        segWayPoints_0[rtb_Bias_fd] +=
                            localDW->RotateATRunWayHdg.RotateATMissionHdg[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            CheckPoints_0) + 1)] * rtb_y[static_cast<int32_T>
                            (iacol + 100)];
                        segWayPoints_0[rtb_Bias_fd] +=
                            localDW->RotateATRunWayHdg.RotateATMissionHdg[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            CheckPoints_0) + 2)] * rtb_y[static_cast<int32_T>
                            (iacol + 200)];
                    }
                }

                for (iacol = 0; iacol < 100; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 < 3; CheckPoints_0++)
                    {
                        rtb_Bias_fd = static_cast<int32_T>(iacol +
                            static_cast<int32_T>(100 * CheckPoints_0));
                        rtb_RotateIndivWayPoint_m[rtb_Bias_fd] = 0.0;
                        rtb_RotateIndivWayPoint_m[rtb_Bias_fd] +=
                            localDW->RotateATMissionHdg_pn.RotateATMissionHdg[
                            static_cast<int32_T>(3 * CheckPoints_0)] *
                            segWayPoints_0[iacol];
                        rtb_RotateIndivWayPoint_m[rtb_Bias_fd] +=
                            localDW->RotateATMissionHdg_pn.RotateATMissionHdg[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            CheckPoints_0) + 1)] * segWayPoints_0
                            [static_cast<int32_T>(iacol + 100)];
                        rtb_RotateIndivWayPoint_m[rtb_Bias_fd] +=
                            localDW->RotateATMissionHdg_pn.RotateATMissionHdg[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            CheckPoints_0) + 2)] * segWayPoints_0
                            [static_cast<int32_T>(iacol + 200)];
                    }
                }

                FlightMissionMode_biasNED_c(rtb_ReshapeRowVecStartpose_c,
                    rtb_RotateIndivWayPoint_m,
                    rtb_nedWayPoint_CoreSubsysCanOut_f);
                for (iacol = 0; iacol < 3; iacol++) {
                    std::memcpy
                        (&localDW->ImpAsg_InsertedFor_nedWayPoint_at_inport_0_l[
                         static_cast<int32_T>(static_cast<int32_T>(nrows * 300)
                          + static_cast<int32_T>(iacol * 100))],
                         &rtb_nedWayPoint_CoreSubsysCanOut_f[static_cast<int32_T>
                         (iacol * 100)], static_cast<uint32_T>(100U * sizeof
                          (real_T)));
                }
            }

            FlightMissionMode_biasNEDstartpose(rtb_ReshapeRowVecStartpose_c,
                rtb_RotateIndivWayPointStartpose1, localDW->nedWayPoint_g);
        } else {
            localDW->WayPointGenerator_MODE_a = false;
        }

        if (static_cast<uint32_T>(localDW->is_active_c3_FlightMissionMode) == 0U)
        {
            localDW->is_active_c3_FlightMissionMode = 1U;
            if (localDW->ModRunWayPose == 1.0) {
                localDW->is_Running_f = FlightMissionMode_IN_Bottom;
                localDW->RunWayMode = RunWaySegment_Bottom;
            } else {
                localDW->is_Running_f = FlightMissionMode_IN_Top;
                localDW->RunWayMode = RunWaySegment_Top;
            }
        } else if (*rtu_Reset != 0) {
            localDW->RunWayMode = RunWaySegment_None;
            localDW->is_Running_f = FlightMissionMode_IN_NO_ACTIVE_CHILD;
            if (localDW->ModRunWayPose == 1.0) {
                localDW->is_Running_f = FlightMissionMode_IN_Bottom;
                localDW->RunWayMode = RunWaySegment_Bottom;
            } else {
                localDW->is_Running_f = FlightMissionMode_IN_Top;
                localDW->RunWayMode = RunWaySegment_Top;
            }
        } else {
            switch (localDW->is_Running_f) {
              case FlightMissionMode_IN_Bottom:
                if (localDW->Memory_PreviousInput_f == 1.0) {
                    localDW->is_Running_f = FlightMissionMode_IN_Left;
                    localDW->RunWayMode = RunWaySegment_Left;
                }
                break;

              case FlightMissionMode_IN_Left:
                if (localDW->Memory_PreviousInput_f == 1.0) {
                    localDW->is_Running_f = FlightMissionMode_IN_Top;
                    localDW->RunWayMode = RunWaySegment_Top;
                }
                break;

              case FlightMissionMode_IN_Right:
                if (localDW->Memory_PreviousInput_f == 1.0) {
                    localDW->is_Running_f = FlightMissionMode_IN_Bottom;
                    localDW->RunWayMode = RunWaySegment_Bottom;
                }
                break;

              default:
                // case IN_Top:
                if (localDW->Memory_PreviousInput_f == 1.0) {
                    localDW->is_Running_f = FlightMissionMode_IN_Right;
                    localDW->RunWayMode = RunWaySegment_Right;
                }
                break;
            }
        }

        rtPrevAction = localDW->SwitchCase_ActiveSubsystem_k;
        switch (localDW->RunWayMode) {
          case RunWaySegment_Left:
            rtAction = 0;
            break;

          case RunWaySegment_Top:
            rtAction = 1;
            break;

          case RunWaySegment_Right:
            rtAction = 2;
            break;

          case RunWaySegment_Bottom:
            rtAction = 3;
            break;

          default:
            rtAction = 4;
            break;
        }

        localDW->SwitchCase_ActiveSubsystem_k = rtAction;
        switch (rtAction) {
          case 0:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pn);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector_at[static_cast<int32_T>(iacol * 100)],
                            &localDW->ImpAsg_InsertedFor_nedWayPoint_at_inport_0_l
                            [static_cast<int32_T>(iacol * 100)],
                            static_cast<uint32_T>(100U * sizeof(real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector_at,
                200.0, &localDW->WaypointFollower_pn);
            localDW->MergeStatus_e = static_cast<real_T>
                (localDW->WaypointFollower_pn.WaypointFollower_o5);
            localDW->MergeLookAheadP_k[0] =
                localDW->WaypointFollower_pn.WaypointFollower_o1[0];
            localDW->MergeLookAheadP_k[1] =
                localDW->WaypointFollower_pn.WaypointFollower_o1[1];
            localDW->MergeLookAheadP_k[2] =
                localDW->WaypointFollower_pn.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse_h =
                localDW->WaypointFollower_pn.WaypointFollower_o2;
            break;

          case 1:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pna);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector_a[static_cast<int32_T>(iacol * 100)],
                            &localDW->ImpAsg_InsertedFor_nedWayPoint_at_inport_0_l
                            [static_cast<int32_T>(static_cast<int32_T>(iacol *
                              100) + 300)], static_cast<uint32_T>(100U * sizeof
                             (real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector_a, 200.0,
                &localDW->WaypointFollower_pna);
            localDW->MergeStatus_e = static_cast<real_T>
                (localDW->WaypointFollower_pna.WaypointFollower_o5);
            localDW->MergeLookAheadP_k[0] =
                localDW->WaypointFollower_pna.WaypointFollower_o1[0];
            localDW->MergeLookAheadP_k[1] =
                localDW->WaypointFollower_pna.WaypointFollower_o1[1];
            localDW->MergeLookAheadP_k[2] =
                localDW->WaypointFollower_pna.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse_h =
                localDW->WaypointFollower_pna.WaypointFollower_o2;
            break;

          case 2:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pnae);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector_g[static_cast<int32_T>(iacol * 100)],
                            &localDW->ImpAsg_InsertedFor_nedWayPoint_at_inport_0_l
                            [static_cast<int32_T>(static_cast<int32_T>(iacol *
                              100) + 600)], static_cast<uint32_T>(100U * sizeof
                             (real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector_g, 200.0,
                &localDW->WaypointFollower_pnae);
            localDW->MergeStatus_e = static_cast<real_T>
                (localDW->WaypointFollower_pnae.WaypointFollower_o5);
            localDW->MergeLookAheadP_k[0] =
                localDW->WaypointFollower_pnae.WaypointFollower_o1[0];
            localDW->MergeLookAheadP_k[1] =
                localDW->WaypointFollower_pnae.WaypointFollower_o1[1];
            localDW->MergeLookAheadP_k[2] =
                localDW->WaypointFollower_pnae.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse_h =
                localDW->WaypointFollower_pnae.WaypointFollower_o2;
            break;

          case 3:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pnaev);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector_c[static_cast<int32_T>(iacol * 100)],
                            &localDW->ImpAsg_InsertedFor_nedWayPoint_at_inport_0_l
                            [static_cast<int32_T>(static_cast<int32_T>(iacol *
                              100) + 900)], static_cast<uint32_T>(100U * sizeof
                             (real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector_c, 200.0,
                &localDW->WaypointFollower_pnaev);
            localDW->MergeStatus_e = static_cast<real_T>
                (localDW->WaypointFollower_pnaev.WaypointFollower_o5);
            localDW->MergeLookAheadP_k[0] =
                localDW->WaypointFollower_pnaev.WaypointFollower_o1[0];
            localDW->MergeLookAheadP_k[1] =
                localDW->WaypointFollower_pnaev.WaypointFollower_o1[1];
            localDW->MergeLookAheadP_k[2] =
                localDW->WaypointFollower_pnaev.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse_h =
                localDW->WaypointFollower_pnaev.WaypointFollower_o2;
            break;
        }

        localDW->Memory_PreviousInput_f = localDW->MergeStatus_e;
        *rty_thisTaskStatus = static_cast<real_T>(static_cast<int32_T>
            (localDW->RunWayMode));
        rty_GuidanceCmds->Height = -localDW->MergeLookAheadP_k[2];
        rty_GuidanceCmds->AirSpeed = static_cast<real_T>(rtu_Parameters->Param4);
        rty_GuidanceCmds->HeadingAngle = localDW->MergeDesiredCourse_h;
        rty_InitialState[0] = localDW->nedWayPoint_g[0];
        rty_InitialState[1] = localDW->nedWayPoint_g[1];
        rty_InitialState[2] = -localDW->nedWayPoint_g[2];
        rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param4);
        rty_InitialState[4] = localDW->Bias1;
        rty_InitialState[5] = 0.0;
        rty_InitialState[6] = 0.0;
        rty_InitialState[7] = 0.0;
        break;

      case 5:
        if (static_cast<int32_T>(rtAction) != static_cast<int32_T>(rtPrevAction))
        {
            localDW->Memory_PreviousInput = 0.0;
            localDW->temporalCounter_i1 = 0U;
            localDW->is_Running = FlightMissionMode_IN_NO_ACTIVE_CHILD;
            localDW->is_active_c20_FlightMissionMode = 0U;
            localDW->is_c20_FlightMissionMode =
                FlightMissionMode_IN_NO_ACTIVE_CHILD;
            localDW->ProtectionLineMode = ProtectionLineSegment_None;
        }

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_Cos_g = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_LatitudeGCS_n = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_Abs1_o2 = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
        rtb_Sum1_j_idx_0 = rtu_Location->Lat - rtb_LatitudeGCS_n;
        rtb_Sum1_j_idx_1 = rtu_Location->Lon - rtb_Abs1_o2;
        if (std::abs(rtb_Sum1_j_idx_0) > 180.0) {
            rtb_AltitudeGCS_e = rt_modd_snf(rtb_Sum1_j_idx_0 + 180.0, 360.0) +
                -180.0;
        } else {
            rtb_AltitudeGCS_e = rtb_Sum1_j_idx_0;
        }

        rtb_Abs1_o2 = std::abs(rtb_AltitudeGCS_e);
        if (rtb_Abs1_o2 > 90.0) {
            if (rtb_AltitudeGCS_e < 0.0) {
                rtb_AltitudeGCS_e = -1.0;
            } else if (rtb_AltitudeGCS_e > 0.0) {
                rtb_AltitudeGCS_e = 1.0;
            } else if (rtb_AltitudeGCS_e == 0.0) {
                rtb_AltitudeGCS_e = 0.0;
            } else {
                rtb_AltitudeGCS_e = (rtNaN);
            }

            rtb_AltitudeGCS_e *= -(rtb_Abs1_o2 + -90.0) + 90.0;
            iacol = 180;
        } else {
            iacol = 0;
        }

        rtb_ClockwiseRotation_l = static_cast<real_T>(iacol) + rtb_Sum1_j_idx_1;
        if (std::abs(rtb_ClockwiseRotation_l) > 180.0) {
            rtb_ClockwiseRotation_l = rt_modd_snf(rtb_ClockwiseRotation_l +
                180.0, 360.0) + -180.0;
        }

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_j_idx_0 = 0.017453292519943295 * rtb_AltitudeGCS_e;
        rtb_Sum1_j_idx_1 = 0.017453292519943295 * rtb_ClockwiseRotation_l;

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_LatitudeGCS_n *= 0.017453292519943295;
        rtb_ClockwiseRotation_l = std::sin(rtb_LatitudeGCS_n);
        rtb_ClockwiseRotation_l = 1.0 - 0.0066943799901413295 *
            rtb_ClockwiseRotation_l * rtb_ClockwiseRotation_l;
        rtb_AltitudeGCS_e = 6.378137E+6 / std::sqrt(rtb_ClockwiseRotation_l);
        rtb_ClockwiseRotation_l = rtb_Sum1_j_idx_0 / rt_atan2d_snf(1.0,
            rtb_AltitudeGCS_e * 0.99330562000985867 / rtb_ClockwiseRotation_l);

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_AltitudeGCS_e = 1.0 / rt_atan2d_snf(1.0, rtb_AltitudeGCS_e * std::
            cos(rtb_LatitudeGCS_n)) * rtb_Sum1_j_idx_1;
        rtb_Cos_g = rtu_Location->Alt + -rtb_Cos_g;
        rtb_LatitudeGCS_n = 0.017453292519943295 * rtu_Location->degHDG;
        if (*rtu_Reset > 0) {
            localDW->WayPointGenerator_MODE = true;
            rtb_Switch_f = static_cast<real_T>(*rtu_FormationIDX);
            rtb_Down2Up_n = static_cast<real_T>(*rtu_MissionUAV);
            rtb_Sum_f = 0.5 * rtb_Down2Up_n;
            FlightMissionMode_uavDubinsConnection_uavDubinsConnection
                (&connectionObj);
            rtb_startPose_i[0] = 0.0;
            rtb_startPose_i[1] = static_cast<real_T>(rtu_Parameters->Param3) /
                2.0;
            rtb_startPose_i[2] = 0.0;
            rtb_startPose_i[3] = 1.5707963267948966;
            LDp[0] = 0.0;
            LDp[1] = -static_cast<real_T>(rtu_Parameters->Param3) / 2.0;
            LDp[2] = 0.0;
            LDp[3] = 1.5707963267948966;
            FlightMissionMode_uavDubinsConnection_connect_o(&connectionObj,
                rtb_startPose_i, LDp, localDW->pathSegObj.data,
                &localDW->pathSegObj.size, a__1_data, &iacol, localDW);
            rtb_Down2Up_n = (localDW->pathSegObj.data[0].Length +
                             static_cast<real_T>(rtu_Parameters->Param3)) /
                rtb_Sum_f;
            rtb_Sum_f = (std::abs(rtb_Switch_f) - ((rtb_Sum_f - std::floor
                           (localDW->pathSegObj.data[0].Length / rtb_Down2Up_n))
                          - 1.0)) - 1.0;
            if (rtb_Sum_f > 0.0) {
                FlightMissionMode_uavDubinsPathSegment_interpolate_g
                    (localDW->pathSegObj.data[0].StartPose,
                     localDW->pathSegObj.data[0].GoalPose,
                     localDW->pathSegObj.data[0].FlightPathAngle,
                     localDW->pathSegObj.data[0].AirSpeed,
                     localDW->pathSegObj.data[0].MinTurningRadius,
                     localDW->pathSegObj.data[0].HelixRadius,
                     localDW->pathSegObj.data[0].MotionTypes,
                     localDW->pathSegObj.data[0].MotionLengths,
                     localDW->pathSegObj.data[0].Length, rtb_Down2Up_n *
                     rtb_Sum_f, midpose_data, midpose_size);
                for (iacol = 0; iacol < 5; iacol++) {
                    rtb_startPose[iacol] = midpose_data[static_cast<int32_T>
                        (midpose_size[0] * static_cast<int32_T>(b[iacol]))];
                }

                FlightMissionMode_genSegWP_lm(&connectionObj, &rtb_startPose[0],
                    LDp, dummyWayPoint, localDW);
                CheckPoints_0 = static_cast<int32_T>(segWayPoints->size[0] *
                    segWayPoints->size[1]);
                segWayPoints->size[0] = static_cast<int32_T>(dummyWayPoint->
                    size[0] + 1);
                segWayPoints->size[1] = 3;
                FlightMissionMode_emxEnsureCapacity_real_T_c(segWayPoints,
                    CheckPoints_0);
                ibmat = dummyWayPoint->size[0];
                for (iacol = 0; iacol < 3; iacol++) {
                    segWayPoints->data[static_cast<int32_T>(segWayPoints->size[0]
                        * iacol)] = 0.0;
                    for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                            (ibmat - 1); CheckPoints_0++) {
                        segWayPoints->data[static_cast<int32_T>
                            (static_cast<int32_T>(CheckPoints_0 +
                              static_cast<int32_T>(segWayPoints->size[0] * iacol))
                             + 1)] = dummyWayPoint->data[static_cast<int32_T>
                            (CheckPoints_0 + static_cast<int32_T>
                             (dummyWayPoint->size[0] * iacol))];
                    }
                }
            } else {
                rtb_startPose_e[0] = 0.0;
                rtb_startPose_e[1] = rtb_startPose_i[1];
                rtb_startPose_e[2] = 0.0;
                rtb_startPose_e[3] = 1.5707963267948966;
                rtb_startPose_e[4] = 0.0;
                tmp_0[0] = 0.0;
                tmp_0[1] = rtb_Sum_f * rtb_Down2Up_n;
                tmp_0[2] = 0.0;
                tmp_0[3] = 0.0;
                tmp_0[4] = 0.0;
                for (iacol = 0; iacol < 5; iacol++) {
                    rtb_startPose[iacol] = rtb_startPose_e[iacol] + tmp_0[iacol];
                }

                FlightMissionMode_genSegWP_lm(&connectionObj, rtb_startPose_i,
                    LDp, dummyWayPoint, localDW);
                CheckPoints_0 = static_cast<int32_T>(segWayPoints->size[0] *
                    segWayPoints->size[1]);
                segWayPoints->size[0] = static_cast<int32_T>(dummyWayPoint->
                    size[0] + 1);
                segWayPoints->size[1] = 3;
                FlightMissionMode_emxEnsureCapacity_real_T_c(segWayPoints,
                    CheckPoints_0);
                ibmat = dummyWayPoint->size[0];
                for (iacol = 0; iacol < 3; iacol++) {
                    segWayPoints->data[static_cast<int32_T>(segWayPoints->size[0]
                        * iacol)] = 0.0;
                    for (CheckPoints_0 = 0; CheckPoints_0 <= static_cast<int32_T>
                            (ibmat - 1); CheckPoints_0++) {
                        segWayPoints->data[static_cast<int32_T>
                            (static_cast<int32_T>(CheckPoints_0 +
                              static_cast<int32_T>(segWayPoints->size[0] * iacol))
                             + 1)] = dummyWayPoint->data[static_cast<int32_T>
                            (CheckPoints_0 + static_cast<int32_T>
                             (dummyWayPoint->size[0] * iacol))];
                    }
                }
            }

            rtb_Bias_fd = static_cast<int32_T>(segWayPoints->size[0] - 100);
            for (iacol = 0; iacol < 3; iacol++) {
                for (CheckPoints_0 = 0; CheckPoints_0 < 100; CheckPoints_0++) {
                    segWayPoints_0[static_cast<int32_T>(CheckPoints_0 +
                        static_cast<int32_T>(100 * iacol))] = segWayPoints->
                        data[static_cast<int32_T>(static_cast<int32_T>
                        (CheckPoints_0 + rtb_Bias_fd) + static_cast<int32_T>
                        (segWayPoints->size[0] * iacol))];
                }
            }

            std::memcpy(&localDW->MatrixConcatenateWayPoint[1200],
                        &segWayPoints_0[0], static_cast<uint32_T>(300U * sizeof
                         (real_T)));
            if (rtb_Switch_f < 0.0) {
                rtb_Switch_f = -1.0;
            } else if (rtb_Switch_f > 0.0) {
                rtb_Switch_f = 1.0;
            } else {
                rtb_Switch_f = 0.0;
            }

            localDW->ProductFlipStartPose[0] = rtb_startPose[0] * -rtb_Switch_f;
            localDW->ProductFlipStartPose[1] = rtb_startPose[1];
            localDW->ProductFlipStartPose[2] = rtb_startPose[2];
            localDW->ProductFlipStartPose[3] = rtb_startPose[3];
            localDW->ProductFlipStartPose[4] = rtb_startPose[4];
            rtb_Map2Radian = 0.017453292519943295 * static_cast<real_T>
                (rtu_Parameters->Param2) * rtb_Switch_f * 0.5;
            rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[0] =
                rtb_Map2Radian;
            rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[1] = 0.0;
            rtb_TmpSignalConversionAtRotateATRunWayHdgInport1[2] = 0.0;
            FlightMissionMode_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATRunWayHdgInport1,
                 &localDW->RotateATRunWayHdg_p);
            rtb_Abs1_o2 = 0.5 * static_cast<real_T>(rtu_Parameters->Param1) *
                rtb_Switch_f;
            for (iacol = 0; iacol < 3; iacol++) {
                rtb_RotateIndivWayPointStartpose1[iacol] =
                    localDW->RotateATRunWayHdg_p.RotateATMissionHdg
                    [static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 2)] *
                    localDW->ProductFlipStartPose[2] +
                    (localDW->RotateATRunWayHdg_p.RotateATMissionHdg[
                     static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 1)] *
                     localDW->ProductFlipStartPose[1] +
                     localDW->RotateATRunWayHdg_p.RotateATMissionHdg[
                     static_cast<int32_T>(3 * iacol)] *
                     localDW->ProductFlipStartPose[0]);
            }

            rtb_Sum1_j_idx_0 = rtb_RotateIndivWayPointStartpose1[0] -
                rtb_Abs1_o2;
            rtb_Sum1_j_idx_1 = rtb_RotateIndivWayPointStartpose1[1];
            rtb_RelPrevPos_n_idx_2 = rtb_RotateIndivWayPointStartpose1[2];
            rtb_MatrixConcatenate[0] = static_cast<int8_T>(-rtb_Switch_f);
            rtb_MatrixConcatenate[1] = 0;
            rtb_MatrixConcatenate[2] = 0;
            rtb_MatrixConcatenate[3] = 0;
            rtb_MatrixConcatenate[4] = 1;
            rtb_MatrixConcatenate[5] = 0;
            rtb_MatrixConcatenate[6] = 0;
            rtb_MatrixConcatenate[7] = 0;
            rtb_MatrixConcatenate[8] = 1;
            FlightMissionMode_WayPointGenerator(static_cast<real_T>
                (rtu_Parameters->Param3), &localDW->MatrixConcatenateWayPoint[0],
                &localDW->MatrixConcatenateWayPoint[300],
                &localDW->MatrixConcatenateWayPoint[600],
                &localDW->MatrixConcatenateWayPoint[900], 100.0,
                &localDW->sf_WayPointGenerator_f);
            rtb_ReshapeRowVec_ec[0] = rtb_Abs1_o2;
            rtb_ReshapeRowVec_ec[1] = 0.0;
            rtb_ReshapeRowVec_ec[2] = 0.0;
            rtb_ReshapeRowVecStartpose_c[0] = rtb_AltitudeGCS_e * 0.0 +
                rtb_ClockwiseRotation_l;
            rtb_ReshapeRowVecStartpose_c[1] = rtb_AltitudeGCS_e -
                rtb_ClockwiseRotation_l * 0.0;
            rtb_ReshapeRowVecStartpose_c[2] = -rtb_Cos_g;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                rtb_LatitudeGCS_n;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] = 0.0;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
            FlightMissionMode_RotateATMissionHdg
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1,
                 &localDW->RotateATMissionHdg_pna);
            for (iacol = 0; iacol < 3; iacol++) {
                rtb_RotateIndivWayPointStartpose1[iacol] =
                    localDW->RotateATMissionHdg_pna.RotateATMissionHdg[
                    static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 2)] *
                    rtb_RelPrevPos_n_idx_2 +
                    (localDW->RotateATMissionHdg_pna.RotateATMissionHdg[
                     static_cast<int32_T>(static_cast<int32_T>(3 * iacol) + 1)] *
                     rtb_Sum1_j_idx_1 +
                     localDW->RotateATMissionHdg_pna.RotateATMissionHdg[
                     static_cast<int32_T>(3 * iacol)] * rtb_Sum1_j_idx_0);
            }

            localDW->Sum = (localDW->ProductFlipStartPose[3] +
                            -1.5707963267948966) * rtb_Switch_f +
                (rtb_LatitudeGCS_n + rtb_Map2Radian);
            for (nrows = 0; nrows < 5; nrows++) {
                for (iacol = 0; iacol < 100; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 < 3; CheckPoints_0++)
                    {
                        rtb_Bias_fd = static_cast<int32_T>(iacol +
                            static_cast<int32_T>(100 * CheckPoints_0));
                        rtb_y_b[rtb_Bias_fd] = 0.0;
                        ibmat = static_cast<int32_T>(static_cast<int32_T>(300 *
                            nrows) + iacol);
                        rtb_y_b[rtb_Bias_fd] +=
                            localDW->MatrixConcatenateWayPoint[ibmat] *
                            static_cast<real_T>(rtb_MatrixConcatenate[
                                                static_cast<int32_T>(3 *
                            CheckPoints_0)]);
                        rtb_y_b[rtb_Bias_fd] +=
                            localDW->MatrixConcatenateWayPoint
                            [static_cast<int32_T>(ibmat + 100)] *
                            static_cast<real_T>(rtb_MatrixConcatenate[
                                                static_cast<int32_T>(
                            static_cast<int32_T>(3 * CheckPoints_0) + 1)]);
                        rtb_y_b[rtb_Bias_fd] +=
                            localDW->MatrixConcatenateWayPoint
                            [static_cast<int32_T>(ibmat + 200)] *
                            static_cast<real_T>(rtb_MatrixConcatenate[
                                                static_cast<int32_T>(
                            static_cast<int32_T>(3 * CheckPoints_0) + 2)]);
                    }
                }

                for (iacol = 0; iacol < 100; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 < 3; CheckPoints_0++)
                    {
                        rtb_Bias_fd = static_cast<int32_T>(iacol +
                            static_cast<int32_T>(100 * CheckPoints_0));
                        rtb_RotateRunway[rtb_Bias_fd] = 0.0;
                        rtb_RotateRunway[rtb_Bias_fd] +=
                            localDW->RotateATRunWayHdg_p.RotateATMissionHdg[
                            static_cast<int32_T>(3 * CheckPoints_0)] *
                            rtb_y_b[iacol];
                        rtb_RotateRunway[rtb_Bias_fd] +=
                            localDW->RotateATRunWayHdg_p.RotateATMissionHdg[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            CheckPoints_0) + 1)] * rtb_y_b[static_cast<int32_T>
                            (iacol + 100)];
                        rtb_RotateRunway[rtb_Bias_fd] +=
                            localDW->RotateATRunWayHdg_p.RotateATMissionHdg[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            CheckPoints_0) + 2)] * rtb_y_b[static_cast<int32_T>
                            (iacol + 200)];
                    }
                }

                FlightMissionMode_minus(rtb_RotateRunway, rtb_ReshapeRowVec_ec,
                                        rtb_y_b);
                for (iacol = 0; iacol < 100; iacol++) {
                    for (CheckPoints_0 = 0; CheckPoints_0 < 3; CheckPoints_0++)
                    {
                        rtb_Bias_fd = static_cast<int32_T>(iacol +
                            static_cast<int32_T>(100 * CheckPoints_0));
                        rtb_RotateIndivWayPoint[rtb_Bias_fd] = 0.0;
                        rtb_RotateIndivWayPoint[rtb_Bias_fd] +=
                            localDW->RotateATMissionHdg_pna.RotateATMissionHdg[
                            static_cast<int32_T>(3 * CheckPoints_0)] *
                            rtb_y_b[iacol];
                        rtb_RotateIndivWayPoint[rtb_Bias_fd] +=
                            localDW->RotateATMissionHdg_pna.RotateATMissionHdg[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            CheckPoints_0) + 1)] * rtb_y_b[static_cast<int32_T>
                            (iacol + 100)];
                        rtb_RotateIndivWayPoint[rtb_Bias_fd] +=
                            localDW->RotateATMissionHdg_pna.RotateATMissionHdg[
                            static_cast<int32_T>(static_cast<int32_T>(3 *
                            CheckPoints_0) + 2)] * rtb_y_b[static_cast<int32_T>
                            (iacol + 200)];
                    }
                }

                FlightMissionMode_biasNED_c(rtb_ReshapeRowVecStartpose_c,
                    rtb_RotateIndivWayPoint, rtb_nedWayPoint_CoreSubsysCanOut);
                for (iacol = 0; iacol < 3; iacol++) {
                    std::memcpy
                        (&localDW->ImpAsg_InsertedFor_nedWayPoint_at_inport_0[
                         static_cast<int32_T>(static_cast<int32_T>(nrows * 300)
                          + static_cast<int32_T>(iacol * 100))],
                         &rtb_nedWayPoint_CoreSubsysCanOut[static_cast<int32_T>
                         (iacol * 100)], static_cast<uint32_T>(100U * sizeof
                          (real_T)));
                }
            }

            FlightMissionMode_biasNEDstartpose(rtb_ReshapeRowVecStartpose_c,
                rtb_RotateIndivWayPointStartpose1, localDW->nedWayPoint);
        } else {
            localDW->WayPointGenerator_MODE = false;
        }

        if (static_cast<uint32_T>(localDW->temporalCounter_i1) < 7U) {
            localDW->temporalCounter_i1 = static_cast<uint8_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i1) + 1U));
        }

        if (static_cast<uint32_T>(localDW->is_active_c20_FlightMissionMode) ==
                0U) {
            localDW->is_active_c20_FlightMissionMode = 1U;
            localDW->is_c20_FlightMissionMode = FlightMissionMode_IN_Init;
            localDW->temporalCounter_i1 = 0U;
            localDW->ProtectionLineMode = ProtectionLineSegment_Init;
        } else if (static_cast<int32_T>(localDW->is_c20_FlightMissionMode) == 1)
        {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((static_cast<uint32_T>
                    (localDW->temporalCounter_i1) >= 5U) &
                                        (localDW->Memory_PreviousInput == 1.0))))
            {
                localDW->is_c20_FlightMissionMode = FlightMissionMode_IN_Running;
                localDW->is_Running = FlightMissionMode_IN_Left;
                localDW->ProtectionLineMode = ProtectionLineSegment_Left;
            }

            // case IN_Running:
        } else if (*rtu_Reset != 0) {
            localDW->is_Running = FlightMissionMode_IN_NO_ACTIVE_CHILD;
            localDW->is_c20_FlightMissionMode = FlightMissionMode_IN_Init;
            localDW->temporalCounter_i1 = 0U;
            localDW->ProtectionLineMode = ProtectionLineSegment_Init;
        } else {
            switch (localDW->is_Running) {
              case FlightMissionMode_IN_Bottom:
                if (localDW->Memory_PreviousInput == 1.0) {
                    localDW->is_Running = FlightMissionMode_IN_Left;
                    localDW->ProtectionLineMode = ProtectionLineSegment_Left;
                }
                break;

              case FlightMissionMode_IN_Left:
                if (localDW->Memory_PreviousInput == 1.0) {
                    localDW->is_Running = FlightMissionMode_IN_Top;
                    localDW->ProtectionLineMode = ProtectionLineSegment_Top;
                }
                break;

              case FlightMissionMode_IN_Right:
                if (localDW->Memory_PreviousInput == 1.0) {
                    localDW->is_Running = FlightMissionMode_IN_Bottom;
                    localDW->ProtectionLineMode = ProtectionLineSegment_Bottom;
                }
                break;

              default:
                // case IN_Top:
                if (localDW->Memory_PreviousInput == 1.0) {
                    localDW->is_Running = FlightMissionMode_IN_Right;
                    localDW->ProtectionLineMode = ProtectionLineSegment_Right;
                }
                break;
            }
        }

        rtPrevAction = localDW->SwitchCase_ActiveSubsystem_h;
        switch (localDW->ProtectionLineMode) {
          case ProtectionLineSegment_Left:
            rtAction = 0;
            break;

          case ProtectionLineSegment_Top:
            rtAction = 1;
            break;

          case ProtectionLineSegment_Right:
            rtAction = 2;
            break;

          case ProtectionLineSegment_Bottom:
            rtAction = 3;
            break;

          case ProtectionLineSegment_Init:
            rtAction = 4;
            break;

          default:
            rtAction = 5;
            break;
        }

        localDW->SwitchCase_ActiveSubsystem_h = rtAction;
        switch (rtAction) {
          case 0:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pnaevv);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector_b[static_cast<int32_T>(iacol * 100)],
                            &localDW->
                            ImpAsg_InsertedFor_nedWayPoint_at_inport_0[
                            static_cast<int32_T>(iacol * 100)],
                            static_cast<uint32_T>(100U * sizeof(real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector_b, 200.0,
                &localDW->WaypointFollower_pnaevv);
            localDW->MergeStatus = static_cast<real_T>
                (localDW->WaypointFollower_pnaevv.WaypointFollower_o5);
            localDW->MergeLookAheadP[0] =
                localDW->WaypointFollower_pnaevv.WaypointFollower_o1[0];
            localDW->MergeLookAheadP[1] =
                localDW->WaypointFollower_pnaevv.WaypointFollower_o1[1];
            localDW->MergeLookAheadP[2] =
                localDW->WaypointFollower_pnaevv.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse =
                localDW->WaypointFollower_pnaevv.WaypointFollower_o2;
            break;

          case 1:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pnaevvf);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector_m[static_cast<int32_T>(iacol * 100)],
                            &localDW->
                            ImpAsg_InsertedFor_nedWayPoint_at_inport_0[
                            static_cast<int32_T>(static_cast<int32_T>(iacol *
                              100) + 300)], static_cast<uint32_T>(100U * sizeof
                             (real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector_m, 200.0,
                &localDW->WaypointFollower_pnaevvf);
            localDW->MergeStatus = static_cast<real_T>
                (localDW->WaypointFollower_pnaevvf.WaypointFollower_o5);
            localDW->MergeLookAheadP[0] =
                localDW->WaypointFollower_pnaevvf.WaypointFollower_o1[0];
            localDW->MergeLookAheadP[1] =
                localDW->WaypointFollower_pnaevvf.WaypointFollower_o1[1];
            localDW->MergeLookAheadP[2] =
                localDW->WaypointFollower_pnaevvf.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse =
                localDW->WaypointFollower_pnaevvf.WaypointFollower_o2;
            break;

          case 2:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pnaevvfp);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector_k[static_cast<int32_T>(iacol * 100)],
                            &localDW->
                            ImpAsg_InsertedFor_nedWayPoint_at_inport_0[
                            static_cast<int32_T>(static_cast<int32_T>(iacol *
                              100) + 600)], static_cast<uint32_T>(100U * sizeof
                             (real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector_k, 200.0,
                &localDW->WaypointFollower_pnaevvfp);
            localDW->MergeStatus = static_cast<real_T>
                (localDW->WaypointFollower_pnaevvfp.WaypointFollower_o5);
            localDW->MergeLookAheadP[0] =
                localDW->WaypointFollower_pnaevvfp.WaypointFollower_o1[0];
            localDW->MergeLookAheadP[1] =
                localDW->WaypointFollower_pnaevvfp.WaypointFollower_o1[1];
            localDW->MergeLookAheadP[2] =
                localDW->WaypointFollower_pnaevvfp.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse =
                localDW->WaypointFollower_pnaevvfp.WaypointFollower_o2;
            break;

          case 3:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pnaevvfpg);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector_h[static_cast<int32_T>(iacol * 100)],
                            &localDW->
                            ImpAsg_InsertedFor_nedWayPoint_at_inport_0[
                            static_cast<int32_T>(static_cast<int32_T>(iacol *
                              100) + 900)], static_cast<uint32_T>(100U * sizeof
                             (real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector_h, 200.0,
                &localDW->WaypointFollower_pnaevvfpg);
            localDW->MergeStatus = static_cast<real_T>
                (localDW->WaypointFollower_pnaevvfpg.WaypointFollower_o5);
            localDW->MergeLookAheadP[0] =
                localDW->WaypointFollower_pnaevvfpg.WaypointFollower_o1[0];
            localDW->MergeLookAheadP[1] =
                localDW->WaypointFollower_pnaevvfpg.WaypointFollower_o1[1];
            localDW->MergeLookAheadP[2] =
                localDW->WaypointFollower_pnaevvfpg.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse =
                localDW->WaypointFollower_pnaevvfpg.WaypointFollower_o2;
            break;

          case 4:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                FlightMissionMode_WaypointFollower_a_Reset
                    (&localDW->WaypointFollower_pnaevvfpgh);
            }

            for (iacol = 0; iacol < 3; iacol++) {
                std::memcpy(&rtb_Selector[static_cast<int32_T>(iacol * 100)],
                            &localDW->
                            ImpAsg_InsertedFor_nedWayPoint_at_inport_0[
                            static_cast<int32_T>(static_cast<int32_T>(iacol *
                              100) + 1200)], static_cast<uint32_T>(100U * sizeof
                             (real_T)));
            }

            FlightMissionMode_WaypointFollower_p(rtu_Pose, rtb_Selector, 200.0,
                &localDW->WaypointFollower_pnaevvfpgh);
            localDW->MergeStatus = static_cast<real_T>
                (localDW->WaypointFollower_pnaevvfpgh.WaypointFollower_o5);
            localDW->MergeLookAheadP[0] =
                localDW->WaypointFollower_pnaevvfpgh.WaypointFollower_o1[0];
            localDW->MergeLookAheadP[1] =
                localDW->WaypointFollower_pnaevvfpgh.WaypointFollower_o1[1];
            localDW->MergeLookAheadP[2] =
                localDW->WaypointFollower_pnaevvfpgh.WaypointFollower_o1[2];
            localDW->MergeDesiredCourse =
                localDW->WaypointFollower_pnaevvfpgh.WaypointFollower_o2;
            break;
        }

        localDW->Memory_PreviousInput = localDW->MergeStatus;
        *rty_thisTaskStatus = static_cast<real_T>(static_cast<int32_T>
            (localDW->ProtectionLineMode));
        rty_GuidanceCmds->Height = -localDW->MergeLookAheadP[2];
        rty_GuidanceCmds->AirSpeed = static_cast<real_T>(rtu_Parameters->Param5);
        rty_GuidanceCmds->HeadingAngle = localDW->MergeDesiredCourse;
        rty_InitialState[0] = localDW->nedWayPoint[0];
        rty_InitialState[1] = localDW->nedWayPoint[1];
        rty_InitialState[2] = -localDW->nedWayPoint[2];
        rty_InitialState[3] = static_cast<real_T>(rtu_Parameters->Param5);
        rty_InitialState[4] = localDW->Sum;
        rty_InitialState[5] = 0.0;
        rty_InitialState[6] = localDW->ProductFlipStartPose[4];
        rty_InitialState[7] = 0.0;
        break;
    }

    FlightMissionMode_emxFree_real_T_n(&dummyWayPoint_0);
    FlightMissionMode_emxFree_real_T_n(&segWayPoints);
    FlightMissionMode_emxFree_real_T_n(&dummyWayPoint);
    FlightMissionMode_emxFree_real_T_n(&CheckPoints);
}

// Model initialize function
void FlightMissionMode_initialize(const char_T **rt_errorStatus,
    RT_MODEL_FlightMissionMode_T *const FlightMissionMode_M)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));

    // initialize error status
    rtmSetErrorStatusPointer(FlightMissionMode_M, rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
