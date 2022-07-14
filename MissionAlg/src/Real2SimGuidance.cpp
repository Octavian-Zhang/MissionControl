//
// File: Real2SimGuidance.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 4.175
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jul 14 15:00:22 2022
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
#include "rtwtypes.h"
#include "Real2SimGuidance_types.h"
#include <cstring>
#include <stdio.h>
#include <cmath>
#include "rt_modd_snf.h"
#include "rt_atan2d_snf.h"
#include "angdiff_WJjwZrD2.h"
#include <stddef.h>
#include "rt_hypotd_snf.h"
#include <math.h>
#include "coder_posix_time.h"
#include "split_uvVAOGsE.h"
#include "floor_LKLalLcG.h"
#include <cstdlib>
#include "Real2SimGuidance_private.h"
#include "div_s32.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Named constants for Chart: '<Root>/EngagementDebouncer'
    const uint8_T Real2SimGuidance_IN_Debounce
{
    1U
};
const uint8_T Real2SimGuidance_IN_Fault{ 1U };

const uint8_T Real2SimGuidance_IN_L0Default{ 2U };

const uint8_T Real2SimGuidance_IN_L0Engaged{ 2U };

const uint8_T Real2SimGuidance_IN_L1Engaged{ 3U };

const uint8_T Real2SimGuidance_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T Real2SimGuidance_IN_Normal{ 2U };

const uint8_T Real2SimGuidance_IN_Off{ 1U };

const uint8_T Real2SimGuidance_IN_On{ 2U };

const uint8_T Real2SimGuidance_IN_Persuit{ 3U };

// Named constants for Chart: '<S9>/Chart'
const uint8_T Real2SimGuidance_IN_NoBias{ 1U };

const uint8_T Real2SimGuidance_IN_hasBias{ 2U };

// Named constants for Chart: '<S100>/MissionSwitchInitialPersuit'
const uint8_T Real2SimGuidance_IN_Initial{ 1U };

const uint8_T Real2SimGuidance_IN_L1Hdg{ 2U };

const uint8_T Real2SimGuidance_IN_L1Hdg_n{ 1U };

const uint8_T Real2SimGuidance_IN_SimPnt{ 3U };

const uint8_T Real2SimGuidance_IN_SimPnt_a{ 2U };

// Named constants for Chart: '<S115>/ControlLogic'
const uint8_T Real2SimGuidance_IN_ADRC{ 1U };

const uint8_T Real2SimGuidance_IN_ADRC2PID{ 1U };

const uint8_T Real2SimGuidance_IN_Debounce_j{ 2U };

const uint8_T Real2SimGuidance_IN_PID{ 1U };

const uint8_T Real2SimGuidance_IN_PID2ADRC{ 2U };

const uint8_T Real2SimGuidance_IN_useADRC{ 2U };

// Named constants for Chart: '<Root>/TASgreaterthan15for1Sec'
const uint8_T Real2SimGuidance_IN_InAir{ 1U };

const uint8_T Real2SimGuidance_IN_NotTakeOff{ 2U };

// Forward declaration for local functions
static real_T Real2SimGuidance_minimum(const real_T x[2]);
static real_T Real2SimGuidance_wrapToPi_p(real_T theta);
static void Real2SimGuidance_VectorFieldHistogramBase_setupImpl
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj);
static void Real2SimGuidance_emxInit_char_T(emxArray_char_T_Real2SimGuidance_T **
    pEmxArray, int32_T numDimensions);
static void Real2SimGuidance_emxFree_char_T(emxArray_char_T_Real2SimGuidance_T **
    pEmxArray);
static int8_T Real2SimGuidance_filedata_j(DW_Real2SimGuidance_f_T *localDW);
static int8_T Real2SimGuidance_cfopen_pf(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_fileManager_d(DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_emxEnsureCapacity_char_T
    (emxArray_char_T_Real2SimGuidance_T *emxArray, int32_T oldNumel);
static void Real2SimGuidance_fread_j0(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW);
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
static boolean_T Real2SimGuidance_copydigits(emxArray_char_T_Real2SimGuidance_T *
    s1, int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T allowpoint);
static void Real2SimGuidance_readfloat(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
    real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T Real2SimGuidance_str2double(const
    emxArray_char_T_Real2SimGuidance_T *s);
static int8_T Real2SimGuidance_filedata_b(DW_Real2SimGuidance_f_T *localDW);
static int8_T Real2SimGuidance_cfopen_d(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_fileManager_i(DW_Real2SimGuidance_f_T *localDW);
static int32_T Real2SimGuidance_cfclose_i(real_T fid, DW_Real2SimGuidance_f_T
    *localDW);
static void Real2SimGuidance_fread_k(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW);
static int32_T Real2SimGuidance_cfclose_c(real_T fid, DW_Real2SimGuidance_f_T
    *localDW);
static void Real2SimGuidance_strtok(const emxArray_char_T_Real2SimGuidance_T *x,
    emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain);
static void Real2SimGuidance_strtok_a(const emxArray_char_T_Real2SimGuidance_T
    *x, emxArray_char_T_Real2SimGuidance_T *token);
static void Real2SimGuidance_strtrim(const emxArray_char_T_Real2SimGuidance_T *x,
    emxArray_char_T_Real2SimGuidance_T *y);
static boolean_T Real2SimGuidance_strcmp_g(const
    emxArray_char_T_Real2SimGuidance_T *a);
static boolean_T Real2SimGuidance_strcmp_gh(const
    emxArray_char_T_Real2SimGuidance_T *a);
static boolean_T Real2SimGuidance_contains(const
    emxArray_char_T_Real2SimGuidance_T *str);
static void Real2SimGuidance_find_token(const emxArray_char_T_Real2SimGuidance_T
    *x, int32_T *itoken, int32_T *iremain);
static void Real2SimGuidance_strtok_ay(const emxArray_char_T_Real2SimGuidance_T *
    x, emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain);
static void Real2SimGuidance_readINI_m(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_hypot_p(const real_T x_data[], const int32_T
    *x_size, const real_T y_data[], const int32_T *y_size, real_T r_data[],
    int32_T *r_size);
static void Real2SimGuidance_readINI_mh(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_strtok_gdxx(const
    emxArray_char_T_Real2SimGuidance_T *x, emxArray_char_T_Real2SimGuidance_T
    *token);
static boolean_T Real2SimGuidance_strcmp_ghb(const
    emxArray_char_T_Real2SimGuidance_T *a);
static void Real2SimGuidance_readINI_n(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_repmat(const real_T a[2], real_T varargin_1,
    emxArray_real_T_Real2SimGuidance_T *b);
static void Real2SimGuidance_binary_expand_op_pu
    (emxArray_real_T_Real2SimGuidance_T *in1, const real_T in2[2097152], const
     int32_T in3[2], const emxArray_real_T_Real2SimGuidance_T *in4);
static void Real2SimGuidance_readINI_ng(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static boolean_T Real2SimGuidance_strcmp_ghbx(const
    emxArray_char_T_Real2SimGuidance_T *a);
static uavDubinsConnection_Real2SimGuidance_T
    *Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_Real2SimGuidance_T *b_this, real_T varargin_2, real_T
     varargin_4);
static boolean_T Real2SimGuidance_strcmp_ghbx5(const
    emxArray_char_T_Real2SimGuidance_T *a);
static real_T Real2SimGuidance_sum(const real_T x_data[], const int32_T *x_size);
static real_T Real2SimGuidance_binary_expand_op_puh(const real_T in1_data[],
    const int32_T *in1_size, const real_T in2_data[], const int32_T *in2_size,
    const real_T in3_data[], const int32_T *in3_size);
static void Real2SimGuidance_expand_atan2(const
    emxArray_real_T_Real2SimGuidance_T *a, const
    emxArray_real_T_Real2SimGuidance_T *b, emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_expand_hypot(const
    emxArray_real_T_Real2SimGuidance_T *a, const
    emxArray_real_T_Real2SimGuidance_T *b, emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_hypot(const emxArray_real_T_Real2SimGuidance_T *x,
    const emxArray_real_T_Real2SimGuidance_T *y,
    emxArray_real_T_Real2SimGuidance_T *r);
static void Real2SimGuidance_cart2pol(const emxArray_real_T_Real2SimGuidance_T
    *x, const emxArray_real_T_Real2SimGuidance_T *y,
    emxArray_real_T_Real2SimGuidance_T *th, emxArray_real_T_Real2SimGuidance_T
    *r);
static void Real2SimGuidance_abs(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y);
static void Real2SimGuidance_emxInit_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T **pEmxArray, int32_T numDimensions);
static void Real2SimGuidance_emxEnsureCapacity_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T *emxArray, int32_T oldNumel);
static void Real2SimGuidance_binary_expand_op_p
    (emxArray_boolean_T_Real2SimGuidance_T *in1, const
     emxArray_real_T_Real2SimGuidance_T *in2, real_T in3, const
     emxArray_real_T_Real2SimGuidance_T *in4, const real_T in5[2]);
static void Real2SimGuidance_emxFree_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T **pEmxArray);
static void Real2SimGuidance_emxInit_int32_T(emxArray_int32_T_Real2SimGuidance_T
    **pEmxArray, int32_T numDimensions);
static void Real2SimGuidance_emxEnsureCapacity_int32_T
    (emxArray_int32_T_Real2SimGuidance_T *emxArray, int32_T oldNumel);
static void Real2SimGuidance_emxFree_int32_T(emxArray_int32_T_Real2SimGuidance_T
    **pEmxArray);
static void Real2SimGuidance_mergesort(emxArray_int32_T_Real2SimGuidance_T *idx,
    const emxArray_real_T_Real2SimGuidance_T *x, int32_T n);
static void Real2SimGuidance_sortIdx(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_int32_T_Real2SimGuidance_T *idx);
static void Real2SimGuidance_unique_vector(const
    emxArray_real_T_Real2SimGuidance_T *a, emxArray_real_T_Real2SimGuidance_T *b);
static int8_T Real2SimGuidance_filedata(DW_Real2SimGuidance_f_T *localDW);
static int8_T Real2SimGuidance_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_fread(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW);
static int32_T Real2SimGuidance_cfclose(real_T fid, DW_Real2SimGuidance_f_T
    *localDW);
static void Real2SimGuidance_SystemCore_initializeInputSizes
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2);
static void Real2SimGuidance_SystemCore_systemblock_prestep
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2);
static boolean_T Real2SimGuidance_SystemCore_detectInputSizeChange
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2);
static boolean_T Real2SimGuidance_allOrAny_anonFcn1(const boolean_T x_data[],
    const int32_T *x_size);
static real_T Real2SimGuidance_sxfun_anonFcn2(real_T x);
static void Real2SimGuidance_binary_expand_op_l(boolean_T in1_data[], int32_T
    *in1_size, const emxArray_real_T_Real2SimGuidance_T *in2, const
    emxArray_real_T_Real2SimGuidance_T *in3);
static void Real2SimGuidance_wrapToPi_p34cmpaz
    (emxArray_real_T_Real2SimGuidance_T *theta, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_lidarScan_lidarScan(const
    emxArray_real_T_Real2SimGuidance_T *varargin_1, const
    emxArray_real_T_Real2SimGuidance_T *varargin_2,
    emxArray_real_T_Real2SimGuidance_T *obj_InternalRanges,
    emxArray_real_T_Real2SimGuidance_T *obj_InternalAngles, boolean_T
    *obj_ContainsOnlyFiniteData, DW_Real2SimGuidance_f_T *localDW);
static robotics_core_internal_NameValueParser_Real2SimGuidance_T
    *Real2SimGuidance_NameValueParser_NameValueParser
    (robotics_core_internal_NameValueParser_Real2SimGuidance_T *obj);
static void Real2SimGuidance_wrapToPi_p3(const real_T theta[2], real_T b_theta[2]);
static void Real2SimGuidance_isfinite(const emxArray_real_T_Real2SimGuidance_T
    *x, boolean_T b_data[], int32_T *b_size, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_sort(const real_T x[2], real_T b_x[2]);
static void Real2SimGuidance_binary_expand_op_puhaq5(boolean_T in1_data[],
    int32_T *in1_size, const boolean_T in2_data[], const int32_T *in2_size,
    const boolean_T in3_data[], const int32_T *in3_size, const boolean_T
    in4_data[], const int32_T *in4_size, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_nullAssignment_bg
    (emxArray_real_T_Real2SimGuidance_T *x, const boolean_T idx_data[], const
     int32_T *idx_size);
static void Real2SimGuidance_lidarScan_extractValidData(const
    emxArray_real_T_Real2SimGuidance_T *objIn_InternalRanges, const
    emxArray_real_T_Real2SimGuidance_T *objIn_InternalAngles, const boolean_T
    validIndices_data[], const int32_T *validIndices_size,
    emxArray_real_T_Real2SimGuidance_T *objOut_InternalRanges,
    emxArray_real_T_Real2SimGuidance_T *objOut_InternalAngles, boolean_T
    *objOut_ContainsOnlyFiniteData, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_lidarScan_removeInvalidData(const
    emxArray_real_T_Real2SimGuidance_T *obj_InternalRanges, const
    emxArray_real_T_Real2SimGuidance_T *obj_InternalAngles, const real_T
    varargin_2[2], emxArray_real_T_Real2SimGuidance_T *objOut_InternalRanges,
    emxArray_real_T_Real2SimGuidance_T *objOut_InternalAngles, boolean_T
    *objOut_ContainsOnlyFiniteData, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_histc(const emxArray_real_T_Real2SimGuidance_T *X,
    const real_T edges[180], real_T N[180], emxArray_real_T_Real2SimGuidance_T
    *BIN);
static void Real2SimGuidance_plus_o(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2, const
    emxArray_real_T_Real2SimGuidance_T *in3);
static void Real2SimGuidance_minus_l(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2);
static void Real2SimGuidance_cross(const emxArray_real_T_Real2SimGuidance_T *a,
    const emxArray_real_T_Real2SimGuidance_T *b,
    emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_repmat_c(const real_T a[3], real_T varargin_1,
    emxArray_real_T_Real2SimGuidance_T *b);
static void Real2SimGuidance_abs_p(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y);
static void Real2SimGuidance_binary_expand_op_puhaq
    (emxArray_real_T_Real2SimGuidance_T *in1, const
     emxArray_real_T_Real2SimGuidance_T *in2, const
     emxArray_real_T_Real2SimGuidance_T *in3);
static void Real2SimGuidance_VectorFieldHistogramBase_buildPolarObstacleDensity
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *scan_InternalRanges, const
     emxArray_real_T_Real2SimGuidance_T *scan_InternalAngles,
     DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_VectorFieldHistogramBase_buildBinaryHistogram
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj);
static void Real2SimGuidance_times_n(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2);
static void Real2SimGuidance_power(const emxArray_real_T_Real2SimGuidance_T *a,
    emxArray_real_T_Real2SimGuidance_T *y);
static void Real2SimGuidance_binary_expand_op_puhaq5rox
    (emxArray_real_T_Real2SimGuidance_T *in1, const
     emxArray_real_T_Real2SimGuidance_T *in2);
static void Real2SimGuidance_plus_owq(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2);
static void Real2SimGuidance_plus_ow(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2);
static void Real2SimGuidance_binary_expand_op_puhaq5ro(boolean_T in1_data[],
    int32_T *in1_size, const emxArray_real_T_Real2SimGuidance_T *in2, const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in3, const
    emxArray_real_T_Real2SimGuidance_T *in4);
static void Real2SimGuidance_binary_expand_op_puhaq5r(boolean_T in1_data[],
    int32_T *in1_size, const emxArray_real_T_Real2SimGuidance_T *in2, const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in3, const
    emxArray_real_T_Real2SimGuidance_T *in4);
static void Real2SimGuidance_VectorFieldHistogramBase_buildMaskedPolarHistogram
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *scan_InternalRanges, const
     emxArray_real_T_Real2SimGuidance_T *scan_InternalAngles,
     DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_diff(const real_T x[182], real_T y[181]);
static boolean_T Real2SimGuidance_any(const real_T x[181]);
static void Real2SimGuidance_eml_find(const real_T x[181], int32_T i_data[],
    int32_T i_size[2]);
static void Real2SimGuidance_binary_expand_op_puhaq5roxr0o(real_T in1_data[],
    const real_T in3_data[], const int32_T in4[2], int32_T in5);
static void Real2SimGuidance_diff_f(const real_T x_data[], const int32_T x_size
    [2], real_T y_data[], int32_T y_size[2]);
static void Real2SimGuidance_wrapToPi_p34(const real_T theta_data[], const
    int32_T theta_size[2], real_T b_theta_data[], int32_T b_theta_size[2]);
static void Real2SimGuidance_binary_expand_op_puhaq5roxr0oy(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], const int32_T in2_size[2],
    const real_T in3_data[], const int32_T in3_size[2]);
static void Real2SimGuidance_bisectAngles(real_T theta1_data[], int32_T
    theta1_size[2], real_T theta2_data[], int32_T theta2_size[2], real_T
    bisect_data[], int32_T bisect_size[2]);
static void Real2SimGuidance_binary_expand_op_puhaq5roxr(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], const int32_T in4_data[],
    const int32_T in4_size[2], const real_T in5[2], const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in6, const
    real_T in7[2]);
static void Real2SimGuidance_bsxfun(const real_T a[180], const real_T b_data[],
    const int32_T *b_size, emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_minimum_p(const emxArray_real_T_Real2SimGuidance_T *
    x, real_T ex_data[], int32_T *ex_size);
static void Real2SimGuidance_bsxfun_p(const emxArray_real_T_Real2SimGuidance_T
    *a, const real_T b_data[], const int32_T *b_size,
    emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_binary_expand_op_puhaq5roxr0oylw(real_T in1_data[],
    int32_T in1_size[2], const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in2, const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], real_T in5);
static void Real2SimGuidance_VectorFieldHistogramBase_computeCost(const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
    real_T c_data[], const int32_T c_size[2], real_T targetDir, real_T prevDir,
    real_T cost_data[], int32_T cost_size[2]);
static real_T Real2SimGuidance_minimum_p0(const real_T x_data[], const int32_T
    x_size[2]);
static boolean_T Real2SimGuidance_any_m(const boolean_T x_data[], const int32_T
    x_size[2]);
static real_T Real2SimGuidance_VectorFieldHistogramBase_selectHeadingDirection
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, real_T
     targetDir, DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_VectorFieldHistogramBase_stepImpl
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2, real_T varargin_3,
     DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_SystemCore_step
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2, real_T varargin_3,
     DW_Real2SimGuidance_f_T *localDW);
static boolean_T Real2SimGuidance_strcmp(const
    emxArray_char_T_Real2SimGuidance_T *a);
static real_T Real2SimGuidance_mean(const emxArray_real_T_Real2SimGuidance_T *x);
static int32_T Real2SimGuidance_thirdOfFive(const
    emxArray_real_T_Real2SimGuidance_T *v, int32_T ia, int32_T ib);
static void Real2SimGuidance_quickselect(emxArray_real_T_Real2SimGuidance_T *v,
    int32_T n, int32_T vlen, real_T *vn, int32_T *nfirst, int32_T *nlast);
static real_T Real2SimGuidance_vmedian(emxArray_real_T_Real2SimGuidance_T *v,
    int32_T n);
static real_T Real2SimGuidance_median(const emxArray_real_T_Real2SimGuidance_T
    *x);
static void Real2SimGuidance_binary_expand_op
    (emxArray_boolean_T_Real2SimGuidance_T *in1, const real_T in2[1048576],
     int32_T in3, real_T in4, const emxArray_real_T_Real2SimGuidance_T *in5,
     const emxArray_real_T_Real2SimGuidance_T *in6, int32_T in7);
static int8_T Real2SimGuidance_filedata_i(DW_Real2SimGuidance_f_T *localDW);
static int8_T Real2SimGuidance_cfopen_p(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_fileManager(DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_fread_j(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW);
static int32_T Real2SimGuidance_cfclose_l(real_T fid, DW_Real2SimGuidance_f_T
    *localDW);
static void Real2SimGuidance_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
    real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
    real_T *t_tm_year, boolean_T *t_tm_isdst);
static creal_T Real2SimGuidance_two_prod(real_T a);
static creal_T Real2SimGuidance_two_diff(real_T a, real_T b);
static creal_T Real2SimGuidance_times(const creal_T a);
static creal_T Real2SimGuidance_minus(const creal_T a, const creal_T b);
static void Real2SimGuidance_getDateVec(const creal_T dd, real_T *y, real_T *mo,
    real_T *d, real_T *h, real_T *m, real_T *s);
static creal_T Real2SimGuidance_two_sum(real_T a, real_T b);
static creal_T Real2SimGuidance_plus(const creal_T a, real_T b);
static void Real2SimGuidance_readINI(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_readINI_p(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_minimum(const real_T x[2])
{
    real_T ex;
    if ((x[0] > x[1]) || (std::isnan(x[0]) && (static_cast<boolean_T>(
            static_cast<int32_T>(static_cast<int32_T>(std::isnan(x[1])) ^ 1)))))
    {
        ex = x[1];
    } else {
        ex = x[0];
    }

    return ex;
}

static real_T Real2SimGuidance_wrapToPi_p(real_T theta)
{
    real_T b_theta;
    b_theta = theta;
    if (std::abs(theta) > 3.1415926535897931) {
        real_T thetaWrap;
        if (std::isnan(theta + 3.1415926535897931) || std::isinf(theta +
                3.1415926535897931)) {
            thetaWrap = (rtNaN);
        } else if (theta + 3.1415926535897931 == 0.0) {
            thetaWrap = 0.0;
        } else {
            boolean_T rEQ0;
            thetaWrap = std::fmod(theta + 3.1415926535897931, 6.2831853071795862);
            rEQ0 = (thetaWrap == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                real_T q;
                q = std::abs((theta + 3.1415926535897931) / 6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q -
                    std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
            }

            if (rEQ0) {
                thetaWrap = 0.0;
            } else if (theta + 3.1415926535897931 < 0.0) {
                thetaWrap += 6.2831853071795862;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((theta +
                3.1415926535897931 > 0.0) & (thetaWrap == 0.0)))) {
            thetaWrap = 6.2831853071795862;
        }

        b_theta = thetaWrap - 3.1415926535897931;
    }

    return b_theta;
}

static void Real2SimGuidance_VectorFieldHistogramBase_setupImpl
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj)
{
    real_T d2scaled;
    obj->PreviousDirection = 0.0;
    d2scaled = obj->AngularLimits[0] + 0.017453292519943295;
    obj->AngularSectorMidPoints[179] = obj->AngularLimits[1] -
        0.017453292519943295;
    obj->AngularSectorMidPoints[0] = obj->AngularLimits[0] +
        0.017453292519943295;
    if (obj->AngularLimits[0] + 0.017453292519943295 == -(obj->AngularLimits[1]
            - 0.017453292519943295)) {
        d2scaled = (obj->AngularLimits[1] - 0.017453292519943295) / 179.0;
        for (int32_T d_k{0}; d_k < 178; d_k++) {
            obj->AngularSectorMidPoints[static_cast<int32_T>(d_k + 1)] = (
                static_cast<real_T>(static_cast<int32_T>(static_cast<int32_T>
                (d_k + 2) << 1)) - 181.0) * d2scaled;
        }
    } else if (((obj->AngularLimits[0] + 0.017453292519943295 < 0.0) !=
                (obj->AngularLimits[1] - 0.017453292519943295 < 0.0)) && ((std::
                 abs(obj->AngularLimits[0] + 0.017453292519943295) >
                 8.9884656743115785E+307) || (std::abs(obj->AngularLimits[1] -
                  0.017453292519943295) > 8.9884656743115785E+307))) {
        real_T delta1;
        real_T delta2;
        delta1 = (obj->AngularLimits[0] + 0.017453292519943295) / 179.0;
        delta2 = (obj->AngularLimits[1] - 0.017453292519943295) / 179.0;
        for (int32_T d_k{0}; d_k < 178; d_k++) {
            obj->AngularSectorMidPoints[static_cast<int32_T>(d_k + 1)] = ((
                static_cast<real_T>(d_k) + 1.0) * delta2 + d2scaled) - (
                static_cast<real_T>(d_k) + 1.0) * delta1;
        }
    } else {
        real_T delta1;
        delta1 = ((obj->AngularLimits[1] - 0.017453292519943295) -
                  (obj->AngularLimits[0] + 0.017453292519943295)) / 179.0;
        for (int32_T d_k{0}; d_k < 178; d_k++) {
            obj->AngularSectorMidPoints[static_cast<int32_T>(d_k + 1)] = (
                static_cast<real_T>(d_k) + 1.0) * delta1 + d2scaled;
        }
    }

    obj->AngularDifference = std::abs(Real2SimGuidance_wrapToPi_p
        (obj->AngularSectorMidPoints[1] - obj->AngularSectorMidPoints[0]));
    d2scaled = obj->AngularDifference / 2.0;
    for (int32_T d_k{0}; d_k < 180; d_k++) {
        obj->AngularSectorStartPoints[d_k] = obj->AngularSectorMidPoints[d_k] -
            d2scaled;
        obj->BinaryHistogram[d_k] = false;
    }
}

static void Real2SimGuidance_emxInit_char_T(emxArray_char_T_Real2SimGuidance_T **
    pEmxArray, int32_T numDimensions)
{
    emxArray_char_T_Real2SimGuidance_T *emxArray;
    *pEmxArray = static_cast<emxArray_char_T_Real2SimGuidance_T *>(std::malloc
        (sizeof(emxArray_char_T_Real2SimGuidance_T)));
    emxArray = *pEmxArray;
    emxArray->data = static_cast<char_T *>(nullptr);
    emxArray->numDimensions = numDimensions;
    emxArray->size = static_cast<int32_T *>(std::malloc(static_cast<uint32_T>
        (sizeof(int32_T) * static_cast<uint32_T>(numDimensions))));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (int32_T i{0}; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void Real2SimGuidance_emxFree_char_T(emxArray_char_T_Real2SimGuidance_T **
    pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_char_T_Real2SimGuidance_T *>(nullptr))
    {
        if (((*pEmxArray)->data != static_cast<char_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_char_T_Real2SimGuidance_T *>(nullptr);
    }
}

// Function for MATLAB Function: '<S96>/getSpeedLimit'
static int8_T Real2SimGuidance_filedata_j(DW_Real2SimGuidance_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles_f[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S96>/getSpeedLimit'
static int8_T Real2SimGuidance_cfopen_pf(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = Real2SimGuidance_filedata_j(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles_f[static_cast<int32_T>(static_cast<int32_T>(j)
                - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S96>/getSpeedLimit'
static real_T Real2SimGuidance_fileManager_d(DW_Real2SimGuidance_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = Real2SimGuidance_cfopen_pf("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
}

static void Real2SimGuidance_emxEnsureCapacity_char_T
    (emxArray_char_T_Real2SimGuidance_T *emxArray, int32_T oldNumel)
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

        newData = std::calloc(static_cast<uint32_T>(i), sizeof(char_T));
        if (emxArray->data != nullptr) {
            std::memcpy(newData, emxArray->data, static_cast<uint32_T>(sizeof
                         (char_T) * static_cast<uint32_T>(oldNumel)));
            if (emxArray->canFreeData) {
                std::free(emxArray->data);
            }
        }

        emxArray->data = static_cast<char_T *>(newData);
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

// Function for MATLAB Function: '<S96>/getSpeedLimit'
static void Real2SimGuidance_fread_j0(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(std::round(fileID));
    if (fileID != static_cast<real_T>(fileid)) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        filestar = localDW->eml_openfiles_f[static_cast<int32_T>(static_cast<
            int32_T>(fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
              static_cast<boolean_T>(static_cast<int32_T>((fileID != 0.0) ^ 1)))
             | static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
               ((fileID != 1.0) ^ 1)))))) | static_cast<int32_T>
            (static_cast<boolean_T>(static_cast<int32_T>((fileID != 2.0) ^ 1))))))
    {
        filestar = NULL;
    }

    A->size[0] = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == NULL) ^ 1))) {
        int32_T c;
        c = 1;
        while (c > 0) {
            int32_T c_0;
            int32_T i;
            int32_T numRead;
            c = 0;
            numRead = 1;
            while (static_cast<boolean_T>(static_cast<int32_T>((c < 1024) &
                     (numRead > 0)))) {
                size_t numReadSizeT;
                numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c),
                                     filestar);
                numRead = (int32_T)numReadSizeT;
                c = static_cast<int32_T>(c + (int32_T)numReadSizeT);
            }

            numRead = A->size[0];
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            i = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(c_0 + A->
                size[0]) + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T(A, i);
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            for (i = 0; i <= c_0; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

static void Real2SimGuidance_emxInit_real_T(emxArray_real_T_Real2SimGuidance_T **
    pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_Real2SimGuidance_T *emxArray;
    *pEmxArray = static_cast<emxArray_real_T_Real2SimGuidance_T *>(std::malloc
        (sizeof(emxArray_real_T_Real2SimGuidance_T)));
    emxArray = *pEmxArray;
    emxArray->data = static_cast<real_T *>(nullptr);
    emxArray->numDimensions = numDimensions;
    emxArray->size = static_cast<int32_T *>(std::malloc(static_cast<uint32_T>
        (sizeof(int32_T) * static_cast<uint32_T>(numDimensions))));
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
    if (*pEmxArray != static_cast<emxArray_real_T_Real2SimGuidance_T *>(nullptr))
    {
        if (((*pEmxArray)->data != static_cast<real_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_real_T_Real2SimGuidance_T *>(nullptr);
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

        emxArray->data = static_cast<real_T *>(newData);
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
    real_T virtualWaypoint[3];
    real_T waypoints_0[3];
    real_T lambda;
    real_T virtualWaypoint_tmp_tmp;
    real_T virtualWaypoint_tmp_tmp_0;
    real_T virtualWaypoint_tmp_tmp_1;
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T i1;
    int32_T i2;
    int32_T iy;
    int32_T j;
    int32_T waypoints_size_idx_0;
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

    iy = 0;
    for (j = 0; j < 3; j++) {
        for (i1 = 0; i1 < 216; i1++) {
            i2 = static_cast<int32_T>(i1 + iy);
            x[i2] = (waypoints[static_cast<int32_T>(i2 + 1)] != waypoints[i2]);
        }

        x[static_cast<int32_T>(iy + 216)] = true;
        iy = static_cast<int32_T>(iy + 217);
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

    i2 = i1;
    i1 = 0;
    for (iy = 0; iy < 217; iy++) {
        if (b[iy]) {
            c_data[i1] = static_cast<uint8_T>(static_cast<int32_T>(iy + 1));
            i1 = static_cast<int32_T>(i1 + 1);
        }
    }

    for (iy = 0; iy < 3; iy++) {
        for (j = 0; j <= static_cast<int32_T>(i2 - 1); j++) {
            localDW->b_waypointsIn_data[static_cast<int32_T>(j + static_cast<
                int32_T>(i2 * iy))] = waypoints[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(217 * iy) +
                static_cast<int32_T>(c_data[j])) - 1)];
        }
    }

    obj->NumWaypoints = static_cast<real_T>(i2);
    obj->LookaheadDistance = lambda;
    Real2SimGuidance_emxInit_real_T(&d, 2);
    if (i2 == 0) {
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
        if (i2 == 1) {
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
                obj->NumWaypoints = 2.0;
                waypoints_size_idx_0 = static_cast<int32_T>(i2 + 1);
                for (iy = 0; iy < 3; iy++) {
                    i1 = static_cast<int32_T>(static_cast<int32_T>(i2 + 1) * iy);
                    localDW->waypoints_data[i1] = obj->InitialPose[iy];
                    for (j = 0; j <= static_cast<int32_T>(i2 - 1); j++) {
                        localDW->waypoints_data[static_cast<int32_T>(
                            static_cast<int32_T>(j + i1) + 1)] =
                            localDW->b_waypointsIn_data[static_cast<int32_T>(
                            static_cast<int32_T>(i2 * iy) + j)];
                    }
                }

                guard1 = true;
            }
        } else {
            waypoints_size_idx_0 = i2;
            i1 = static_cast<int32_T>(i2 * 3);
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
                        1.0) + waypoints_size_idx_0) - 1)];
                    virtualWaypoint_tmp_tmp_3 = localDW->waypoints_data[
                        static_cast<int32_T>(iy + waypoints_size_idx_0)];
                    virtualWaypoint_tmp_0 = virtualWaypoint_tmp_tmp_0 -
                        virtualWaypoint_tmp_tmp_3;
                    virtualWaypoint_tmp_tmp_1 = localDW->waypoints_data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>((static_cast<real_T>(iy) + 1.0) +
                        1.0) + static_cast<int32_T>(waypoints_size_idx_0 << 1))
                        - 1)];
                    virtualWaypoint_tmp_tmp_4 = localDW->waypoints_data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (waypoints_size_idx_0 << 1) + iy)];
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
                (obj->WaypointIndex + 1.0) + waypoints_size_idx_0) - 1)];
            virtualWaypoint[1] = currentPose[1] - virtualWaypoint_tmp_tmp_3;
            virtualWaypoint_tmp_tmp_4 = localDW->waypoints_data
                [static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
                (obj->WaypointIndex + 1.0) + static_cast<int32_T>
                (waypoints_size_idx_0 << 1)) - 1)];
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
                              (obj->WaypointIndex) + waypoints_size_idx_0) - 1)];
                lambda_tmp_0 = virtualWaypoint_tmp_tmp_3 -
                    virtualWaypoint_tmp_tmp_0;
                waypoints_0[1] = lambda_tmp_0;
                virtualWaypoint_tmp_tmp = localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(waypoints_size_idx_0 << 1) +
                     static_cast<int32_T>(obj->WaypointIndex)) - 1)];
                waypoints_tmp = virtualWaypoint_tmp_tmp_4 -
                    virtualWaypoint_tmp_tmp;
                waypoints_0[2] = waypoints_tmp;
                b_0 = Real2SimGuidance_norm(waypoints_0);
                lambda = (lambda_tmp / b_0 * (virtualWaypoint[0] / lambda) +
                          lambda_tmp_0 / b_0 * (virtualWaypoint[1] / lambda)) +
                    waypoints_tmp / b_0 * (virtualWaypoint[2] / lambda);
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (lambda)) ^ 1))) {
                    if (lambda < 0.0) {
                        lambda = -1.0;
                    } else {
                        lambda = static_cast<real_T>(lambda > 0.0);
                    }
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
                              (obj->WaypointIndex) + waypoints_size_idx_0) - 1)];
                varargout_1[1] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + waypoints_size_idx_0) - 1)];
                virtualWaypoint_tmp_tmp = localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(waypoints_size_idx_0 << 1) +
                     static_cast<int32_T>(obj->WaypointIndex)) - 1)];
                varargout_1[2] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex
                    + 1.0) + static_cast<int32_T>(waypoints_size_idx_0 << 1)) -
                    1)];
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

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static boolean_T Real2SimGuidance_copydigits(emxArray_char_T_Real2SimGuidance_T *
    s1, int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T allowpoint)
{
    boolean_T exitg1;
    boolean_T haspoint;
    boolean_T success;
    success = (*k <= n);
    haspoint = false;
    exitg1 = false;
    while ((!exitg1) && (static_cast<boolean_T>(static_cast<int32_T>((*k <= n) &
              static_cast<int32_T>(success))))) {
        char_T tmp;
        tmp = s->data[static_cast<int32_T>(*k - 1)];
        if ((tmp >= '0') && (tmp <= '9')) {
            s1->data[static_cast<int32_T>(*idx - 1)] = tmp;
            *idx = static_cast<int32_T>(*idx + 1);
            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == '.') {
            success = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(haspoint) ^ 1))) & static_cast<int32_T>
                 (allowpoint)));
            if (success) {
                s1->data[static_cast<int32_T>(*idx - 1)] = '.';
                *idx = static_cast<int32_T>(*idx + 1);
                haspoint = true;
            }

            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == ',') {
            *k = static_cast<int32_T>(*k + 1);
        } else {
            exitg1 = true;
        }
    }

    return success;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_readfloat(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
    real_T *nfv, boolean_T *foundsign, boolean_T *success)
{
    static const boolean_T b[128]{ false, false, false, false, false, false,
        false, false, false, true, true, true, true, true, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, true, true, true, true, true, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false };

    emxArray_char_T_Real2SimGuidance_T *d;
    int32_T b_idx;
    int32_T b_k;
    int32_T g_k;
    char_T c_idx_0;
    boolean_T a__3;
    boolean_T exitg1;
    boolean_T isneg;
    Real2SimGuidance_emxInit_char_T(&d, 2);
    *isimag = false;
    *b_finite = true;
    *nfv = 0.0;
    b_idx = *idx;
    b_k = *k;
    isneg = false;
    *foundsign = false;
    exitg1 = false;
    while ((!exitg1) && (b_k <= n)) {
        c_idx_0 = s->data[static_cast<int32_T>(b_k - 1)];
        if (c_idx_0 == '-') {
            isneg = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(isneg) ^ 1));
            *foundsign = true;
            b_k = static_cast<int32_T>(b_k + 1);
        } else if (c_idx_0 == ',') {
            b_k = static_cast<int32_T>(b_k + 1);
        } else if (c_idx_0 == '+') {
            *foundsign = true;
            b_k = static_cast<int32_T>(b_k + 1);
        } else if (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(b[static_cast<int32_T>
                      (static_cast<int32_T>(static_cast<uint8_T>(c_idx_0)) & 127)])
                     ^ 1))) {
            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 1);
        }
    }

    *success = (b_k <= n);
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (*success) & static_cast<int32_T>(isneg)))) {
        if ((*idx >= 2) && (s1->data[static_cast<int32_T>(*idx - 2)] == '-')) {
            s1->data[static_cast<int32_T>(*idx - 2)] = ' ';
        } else {
            s1->data[static_cast<int32_T>(*idx - 1)] = '-';
            b_idx = static_cast<int32_T>(*idx + 1);
        }
    }

    *idx = b_idx;
    *k = b_k;
    if (*success) {
        char_T c_idx_1;
        char_T c_idx_2;
        isneg = false;
        if (b_k <= n) {
            c_idx_0 = s->data[static_cast<int32_T>(b_k - 1)];
            if (c_idx_0 == 'j') {
                isneg = true;
            } else if (c_idx_0 == 'i') {
                if (b_k >= static_cast<int32_T>(n - 1)) {
                    isneg = true;
                } else {
                    g_k = b_k;
                    c_idx_0 = '\x00';
                    while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)]
                                          == ',')) {
                        g_k = static_cast<int32_T>(g_k + 1);
                    }

                    if (g_k <= n) {
                        c_idx_0 = s->data[static_cast<int32_T>(g_k - 1)];
                    }

                    g_k = static_cast<int32_T>(g_k + 1);
                    c_idx_1 = '\x00';
                    while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)]
                                          == ',')) {
                        g_k = static_cast<int32_T>(g_k + 1);
                    }

                    if (g_k <= n) {
                        c_idx_1 = s->data[static_cast<int32_T>(g_k - 1)];
                    }

                    g_k = static_cast<int32_T>(g_k + 1);
                    c_idx_2 = '\x00';
                    while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)]
                                          == ',')) {
                        g_k = static_cast<int32_T>(g_k + 1);
                    }

                    if (g_k <= n) {
                        c_idx_2 = s->data[static_cast<int32_T>(g_k - 1)];
                    }

                    if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 ==
                            'N') || (c_idx_1 == 'n')) && ((c_idx_2 == 'F') ||
                            (c_idx_2 == 'f'))) {
                    } else if ((c_idx_0 == 'N') || (c_idx_0 == 'n')) {
                        if ((c_idx_1 == 'A') || (c_idx_1 == 'a')) {
                            if ((c_idx_2 != 'N') && (c_idx_2 != 'n')) {
                                isneg = true;
                            }
                        } else {
                            isneg = true;
                        }
                    } else {
                        isneg = true;
                    }
                }
            }
        }

        if (isneg) {
            if (allowimag) {
                *isimag = true;
                *k = static_cast<int32_T>(b_k + 1);
                exitg1 = false;
                while ((!exitg1) && (*k <= n)) {
                    if (b[static_cast<int32_T>(static_cast<int32_T>
                                               (static_cast<uint8_T>(s->data[
                            static_cast<int32_T>(*k - 1)])) & 127)]) {
                        *k = static_cast<int32_T>(*k + 1);
                    } else {
                        c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
                        if ((c_idx_0 == '\x00') || (c_idx_0 == ',')) {
                            *k = static_cast<int32_T>(*k + 1);
                        } else {
                            exitg1 = true;
                        }
                    }
                }

                if ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == '*'))
                {
                    *k = static_cast<int32_T>(*k + 1);
                    Real2SimGuidance_readfloat(s1, idx, s, k, n, false, &isneg,
                        b_finite, nfv, &a__3, success);
                } else {
                    s1->data[static_cast<int32_T>(b_idx - 1)] = '1';
                    *idx = static_cast<int32_T>(b_idx + 1);
                }
            } else {
                *success = false;
            }
        } else {
            g_k = b_k;
            c_idx_0 = '\x00';
            while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)] == ','))
            {
                g_k = static_cast<int32_T>(g_k + 1);
            }

            if (g_k <= n) {
                c_idx_0 = s->data[static_cast<int32_T>(g_k - 1)];
            }

            g_k = static_cast<int32_T>(g_k + 1);
            c_idx_1 = '\x00';
            while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)] == ','))
            {
                g_k = static_cast<int32_T>(g_k + 1);
            }

            if (g_k <= n) {
                c_idx_1 = s->data[static_cast<int32_T>(g_k - 1)];
            }

            g_k = static_cast<int32_T>(g_k + 1);
            c_idx_2 = '\x00';
            while ((g_k <= n) && (s->data[static_cast<int32_T>(g_k - 1)] == ','))
            {
                g_k = static_cast<int32_T>(g_k + 1);
            }

            if (g_k <= n) {
                c_idx_2 = s->data[static_cast<int32_T>(g_k - 1)];
            }

            g_k = static_cast<int32_T>(g_k + 1);
            if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
                    (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f')))
            {
                *b_finite = false;
                *nfv = (rtInf);
            } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 ==
                         'A') || (c_idx_1 == 'a')) && ((c_idx_2 == 'N') ||
                        (c_idx_2 == 'n'))) {
                *b_finite = false;
                *nfv = (rtNaN);
            } else {
                g_k = b_k;
            }

            *k = g_k;
            if (*b_finite) {
                int32_T loop_ub;
                b_k = static_cast<int32_T>(d->size[0] * d->size[1]);
                d->size[0] = 1;
                d->size[1] = s1->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(d, b_k);
                loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                for (b_k = 0; b_k <= loop_ub; b_k++) {
                    d->data[b_k] = s1->data[b_k];
                }

                *success = Real2SimGuidance_copydigits(d, &b_idx, s, &g_k, n,
                    true);
                b_k = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                s1->size[0] = 1;
                s1->size[1] = d->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(s1, b_k);
                loop_ub = d->size[1];
                for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
                    s1->data[b_k] = d->data[b_k];
                }

                *idx = b_idx;
                *k = g_k;
                if ((*success) && (g_k <= n)) {
                    c_idx_0 = s->data[static_cast<int32_T>(g_k - 1)];
                    if ((c_idx_0 == 'E') || (c_idx_0 == 'e')) {
                        s1->data[static_cast<int32_T>(b_idx - 1)] = 'e';
                        *idx = static_cast<int32_T>(b_idx + 1);
                        while ((static_cast<int32_T>(g_k + 1) <= n) && (s->
                                data[g_k] == ',')) {
                            g_k = static_cast<int32_T>(g_k + 1);
                        }

                        if (static_cast<int32_T>(g_k + 1) <= n) {
                            if (s->data[g_k] == '-') {
                                s1->data[b_idx] = '-';
                                *idx = static_cast<int32_T>(b_idx + 2);
                                g_k = static_cast<int32_T>(g_k + 1);
                            } else if (s->data[g_k] == '+') {
                                g_k = static_cast<int32_T>(g_k + 1);
                            }
                        }

                        b_k = static_cast<int32_T>(d->size[0] * d->size[1]);
                        d->size[0] = 1;
                        d->size[1] = s1->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(d, b_k);
                        loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                        for (b_k = 0; b_k <= loop_ub; b_k++) {
                            d->data[b_k] = s1->data[b_k];
                        }

                        b_idx = static_cast<int32_T>(g_k + 1);
                        isneg = Real2SimGuidance_copydigits(d, idx, s, &b_idx, n,
                            false);
                        b_k = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                        s1->size[0] = 1;
                        s1->size[1] = d->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(s1, b_k);
                        loop_ub = d->size[1];
                        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1);
                                b_k++) {
                            s1->data[b_k] = d->data[b_k];
                        }

                        *k = b_idx;
                        if (static_cast<boolean_T>(static_cast<int32_T>((b_idx <=
                               static_cast<int32_T>(g_k + 1)) |
                                static_cast<int32_T>(static_cast<boolean_T>(
                                static_cast<int32_T>(static_cast<int32_T>(isneg)
                                 ^ 1)))))) {
                            *success = false;
                        }
                    }
                }
            } else if ((b_idx >= 2) && (s1->data[static_cast<int32_T>(b_idx - 2)]
                        == '-')) {
                *idx = static_cast<int32_T>(b_idx - 1);
                s1->data[static_cast<int32_T>(b_idx - 2)] = ' ';
                *nfv = -*nfv;
            }

            exitg1 = false;
            while ((!exitg1) && (*k <= n)) {
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(s->data[
                        static_cast<int32_T>(*k - 1)])) & 127)]) {
                    *k = static_cast<int32_T>(*k + 1);
                } else {
                    c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
                    if ((c_idx_0 == '\x00') || (c_idx_0 == ',')) {
                        *k = static_cast<int32_T>(*k + 1);
                    } else {
                        exitg1 = true;
                    }
                }
            }

            if ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == '*')) {
                *k = static_cast<int32_T>(*k + 1);
                while ((*k <= n) && (b[static_cast<int32_T>(static_cast<int32_T>
                         (static_cast<uint8_T>(s->data[static_cast<int32_T>(*k -
                            1)])) & 127)] || (s->data[static_cast<int32_T>(*k -
                          1)] == '\x00') || (s->data[static_cast<int32_T>(*k - 1)]
                         == ','))) {
                    *k = static_cast<int32_T>(*k + 1);
                }
            }

            if (*k <= n) {
                c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
                if ((c_idx_0 == 'i') || (c_idx_0 == 'j')) {
                    *k = static_cast<int32_T>(*k + 1);
                    *isimag = true;
                }
            }
        }

        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
            c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
            if (b[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                    (c_idx_0)) & 127)] || (c_idx_0 == '\x00') || (c_idx_0 == ','))
            {
                *k = static_cast<int32_T>(*k + 1);
            } else {
                exitg1 = true;
            }
        }
    }

    Real2SimGuidance_emxFree_char_T(&d);
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static creal_T Real2SimGuidance_str2double(const
    emxArray_char_T_Real2SimGuidance_T *s)
{
    static const boolean_T c[128]{ false, false, false, false, false, false,
        false, false, false, true, true, true, true, true, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, true, true, true, true, true, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false };

    emxArray_char_T_Real2SimGuidance_T *d;
    emxArray_char_T_Real2SimGuidance_T *s1;
    creal_T x;
    real_T b_scanned1;
    real_T scanned1;
    real_T scanned2;
    int32_T idx;
    int32_T k;
    boolean_T a__1;
    boolean_T c_success;
    boolean_T foundsign;
    boolean_T isfinite1;
    boolean_T isimag1;
    boolean_T success;
    Real2SimGuidance_emxInit_char_T(&d, 2);
    x.re = (rtNaN);
    x.im = 0.0;
    if (s->size[1] >= 1) {
        int32_T i;
        int32_T loop_ub;
        int32_T ntoread;
        boolean_T exitg1;
        Real2SimGuidance_emxInit_char_T(&s1, 2);
        ntoread = 0;
        k = 1;
        exitg1 = false;
        while ((!exitg1) && (k <= s->size[1])) {
            char_T tmp;
            tmp = s->data[static_cast<int32_T>(k - 1)];
            if (c[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                    (tmp)) & 127)] || (tmp == '\x00')) {
                k = static_cast<int32_T>(k + 1);
            } else {
                exitg1 = true;
            }
        }

        i = static_cast<int32_T>(d->size[0] * d->size[1]);
        d->size[0] = 1;
        d->size[1] = static_cast<int32_T>(s->size[1] + 2);
        Real2SimGuidance_emxEnsureCapacity_char_T(d, i);
        loop_ub = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub + 1); i++) {
            d->data[i] = '\x00';
        }

        idx = 1;
        Real2SimGuidance_readfloat(d, &idx, s, &k, s->size[1], true, &isimag1,
            &isfinite1, &scanned1, &a__1, &success);
        i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
        s1->size[0] = 1;
        s1->size[1] = d->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T(s1, i);
        loop_ub = static_cast<int32_T>(d->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            s1->data[i] = d->data[i];
        }

        if (isfinite1) {
            ntoread = 1;
        }

        if (success) {
            if (k <= s->size[1]) {
                s1->data[static_cast<int32_T>(idx - 1)] = ' ';
                i = static_cast<int32_T>(d->size[0] * d->size[1]);
                d->size[0] = 1;
                d->size[1] = s1->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(d, i);
                loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                for (i = 0; i <= loop_ub; i++) {
                    d->data[i] = s1->data[i];
                }

                idx = static_cast<int32_T>(idx + 1);
                Real2SimGuidance_readfloat(d, &idx, s, &k, s->size[1], true,
                    &a__1, &success, &scanned2, &foundsign, &c_success);
                i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                s1->size[0] = 1;
                s1->size[1] = d->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(s1, i);
                loop_ub = static_cast<int32_T>(d->size[1] - 1);
                for (i = 0; i <= loop_ub; i++) {
                    s1->data[i] = d->data[i];
                }

                if (success) {
                    ntoread = static_cast<int32_T>(ntoread + 1);
                }

                success = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(isimag1) ^
                    static_cast<int32_T>(a__1)))) & static_cast<int32_T>
                     (foundsign)))) & (k > s->size[1])))) & static_cast<int32_T>
                    (c_success)));
            } else {
                scanned2 = 0.0;
            }
        } else {
            scanned2 = 0.0;
        }

        if (success) {
            s1->data[static_cast<int32_T>(idx - 1)] = '\x00';
            switch (ntoread) {
              case 2:
                ntoread = sscanf(&s1->data[0], "%lf %lf", &scanned1, &scanned2);
                if (ntoread != 2) {
                    scanned1 = (rtNaN);
                    scanned2 = (rtNaN);
                }
                break;

              case 1:
                ntoread = sscanf(&s1->data[0], "%lf", &b_scanned1);
                if (isfinite1) {
                    if (ntoread == 1) {
                        scanned1 = b_scanned1;
                    } else {
                        scanned1 = (rtNaN);
                    }
                } else if (ntoread == 1) {
                    scanned2 = b_scanned1;
                } else {
                    scanned2 = (rtNaN);
                }
                break;
            }

            if (isimag1) {
                x.re = scanned2;
                x.im = scanned1;
            } else {
                x.re = scanned1;
                x.im = scanned2;
            }
        }

        Real2SimGuidance_emxFree_char_T(&s1);
    }

    Real2SimGuidance_emxFree_char_T(&d);
    return x;
}

// Function for MATLAB Function: '<S98>/getSpeedLimit'
static int8_T Real2SimGuidance_filedata_b(DW_Real2SimGuidance_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles_k[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S98>/getSpeedLimit'
static int8_T Real2SimGuidance_cfopen_d(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = Real2SimGuidance_filedata_b(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles_k[static_cast<int32_T>(static_cast<int32_T>(j)
                - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S98>/getSpeedLimit'
static real_T Real2SimGuidance_fileManager_i(DW_Real2SimGuidance_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = Real2SimGuidance_cfopen_d("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
}

// Function for MATLAB Function: '<S96>/getSpeedLimit'
static int32_T Real2SimGuidance_cfclose_i(real_T fid, DW_Real2SimGuidance_f_T
    *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(std::round(fid));
    if (fid != static_cast<real_T>(fileid)) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = localDW->eml_openfiles_f[static_cast<int32_T>
            (static_cast<int32_T>(b_fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(b_fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((filestar != NULL) & (
            static_cast<int32_T>(fileid) >= 3)))) {
        int32_T cst;
        cst = fclose(filestar);
        if (cst == 0) {
            st = 0;
            localDW->eml_openfiles_f[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S98>/getSpeedLimit'
static void Real2SimGuidance_fread_k(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(std::round(fileID));
    if (fileID != static_cast<real_T>(fileid)) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        filestar = localDW->eml_openfiles_k[static_cast<int32_T>(static_cast<
            int32_T>(fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
              static_cast<boolean_T>(static_cast<int32_T>((fileID != 0.0) ^ 1)))
             | static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
               ((fileID != 1.0) ^ 1)))))) | static_cast<int32_T>
            (static_cast<boolean_T>(static_cast<int32_T>((fileID != 2.0) ^ 1))))))
    {
        filestar = NULL;
    }

    A->size[0] = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == NULL) ^ 1))) {
        int32_T c;
        c = 1;
        while (c > 0) {
            int32_T c_0;
            int32_T i;
            int32_T numRead;
            c = 0;
            numRead = 1;
            while (static_cast<boolean_T>(static_cast<int32_T>((c < 1024) &
                     (numRead > 0)))) {
                size_t numReadSizeT;
                numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c),
                                     filestar);
                numRead = (int32_T)numReadSizeT;
                c = static_cast<int32_T>(c + (int32_T)numReadSizeT);
            }

            numRead = A->size[0];
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            i = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(c_0 + A->
                size[0]) + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T(A, i);
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            for (i = 0; i <= c_0; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S98>/getSpeedLimit'
static int32_T Real2SimGuidance_cfclose_c(real_T fid, DW_Real2SimGuidance_f_T
    *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(std::round(fid));
    if (fid != static_cast<real_T>(fileid)) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = localDW->eml_openfiles_k[static_cast<int32_T>
            (static_cast<int32_T>(b_fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(b_fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((filestar != NULL) & (
            static_cast<int32_T>(fileid) >= 3)))) {
        int32_T cst;
        cst = fclose(filestar);
        if (cst == 0) {
            st = 0;
            localDW->eml_openfiles_k[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_strtok(const emxArray_char_T_Real2SimGuidance_T *x,
    emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain)
{
    int32_T b;
    int32_T i;
    int32_T itoken;
    int32_T k;
    int32_T n;
    n = x->size[1];
    k = 0;
    while ((static_cast<int32_T>(k + 1) <= n) && (x->data[k] == '\x0a')) {
        k = static_cast<int32_T>(k + 1);
    }

    itoken = static_cast<int32_T>(k + 1);
    while ((static_cast<int32_T>(k + 1) <= n) && (x->data[k] != '\x0a')) {
        k = static_cast<int32_T>(k + 1);
    }

    if (static_cast<int32_T>(k + 1) > x->size[1]) {
        n = 0;
        b = 0;
    } else {
        n = k;
        b = x->size[1];
    }

    i = static_cast<int32_T>(remain->size[0] * remain->size[1]);
    remain->size[0] = 1;
    b = static_cast<int32_T>(b - n);
    remain->size[1] = b;
    Real2SimGuidance_emxEnsureCapacity_char_T(remain, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        remain->data[i] = x->data[static_cast<int32_T>(n + i)];
    }

    if (itoken > k) {
        itoken = 0;
        k = 0;
    } else {
        itoken = static_cast<int32_T>(itoken - 1);
    }

    i = static_cast<int32_T>(token->size[0] * token->size[1]);
    token->size[0] = 1;
    b = static_cast<int32_T>(k - itoken);
    token->size[1] = b;
    Real2SimGuidance_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_strtok_a(const emxArray_char_T_Real2SimGuidance_T
    *x, emxArray_char_T_Real2SimGuidance_T *token)
{
    int32_T itoken;
    int32_T k;
    int32_T n;
    n = x->size[1];
    k = 1;
    while ((k <= n) && (x->data[static_cast<int32_T>(k - 1)] == ';')) {
        k = static_cast<int32_T>(k + 1);
    }

    itoken = k;
    while ((k <= n) && (x->data[static_cast<int32_T>(k - 1)] != ';')) {
        k = static_cast<int32_T>(k + 1);
    }

    if (itoken > static_cast<int32_T>(k - 1)) {
        n = 0;
        k = 0;
    } else {
        n = static_cast<int32_T>(itoken - 1);
        k = static_cast<int32_T>(k - 1);
    }

    itoken = static_cast<int32_T>(token->size[0] * token->size[1]);
    token->size[0] = 1;
    k = static_cast<int32_T>(k - n);
    token->size[1] = k;
    Real2SimGuidance_emxEnsureCapacity_char_T(token, itoken);
    for (itoken = 0; itoken <= static_cast<int32_T>(k - 1); itoken++) {
        token->data[itoken] = x->data[static_cast<int32_T>(n + itoken)];
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_strtrim(const emxArray_char_T_Real2SimGuidance_T *x,
    emxArray_char_T_Real2SimGuidance_T *y)
{
    static const boolean_T d[128]{ false, false, false, false, false, false,
        false, false, false, true, true, true, true, true, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, true, true, true, true, true, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false };

    int32_T b_j1;
    int32_T i;
    int32_T j2;
    b_j1 = 0;
    while ((static_cast<int32_T>(b_j1 + 1) <= x->size[1]) &&
            (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(d[
               static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                 (x->data[b_j1])) & 127)]) & (x->data[b_j1] != '\x00'))))) {
        b_j1 = static_cast<int32_T>(b_j1 + 1);
    }

    j2 = static_cast<int32_T>(x->size[1] - 1);
    while ((static_cast<int32_T>(j2 + 1) > 0) && (static_cast<boolean_T>(
             static_cast<int32_T>(static_cast<int32_T>(d[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<uint8_T>(x->data[j2])) & 127)])
              & (x->data[j2] != '\x00'))))) {
        j2 = static_cast<int32_T>(j2 - 1);
    }

    if (static_cast<int32_T>(b_j1 + 1) > static_cast<int32_T>(j2 + 1)) {
        b_j1 = 0;
        j2 = -1;
    }

    i = static_cast<int32_T>(y->size[0] * y->size[1]);
    y->size[0] = 1;
    j2 = static_cast<int32_T>(j2 - b_j1);
    y->size[1] = static_cast<int32_T>(j2 + 1);
    Real2SimGuidance_emxEnsureCapacity_char_T(y, i);
    for (i = 0; i <= j2; i++) {
        y->data[i] = x->data[static_cast<int32_T>(b_j1 + i)];
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_g(const
    emxArray_char_T_Real2SimGuidance_T *a)
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

    static const char_T d[3]{ 'U', 'A', 'V' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    Real2SimGuidance_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 3) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 3) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    Real2SimGuidance_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_gh(const
    emxArray_char_T_Real2SimGuidance_T *a)
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

    static const char_T d[10]{ 'N', 'o', 'r', 'm', 'A', 'i', 'r', 'S', 'p', 'd'
    };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    Real2SimGuidance_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 10) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 10) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    Real2SimGuidance_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static boolean_T Real2SimGuidance_contains(const
    emxArray_char_T_Real2SimGuidance_T *str)
{
    int32_T matchPos;
    matchPos = 0;
    int32_T exitg1;
    do {
        exitg1 = 0;
        if (matchPos <= static_cast<int32_T>(str->size[1] - 1)) {
            if (str->data[matchPos] == '=') {
                exitg1 = 1;
            } else {
                matchPos = static_cast<int32_T>(matchPos + 1);
            }
        } else {
            matchPos = -1;
            exitg1 = 1;
        }
    } while (exitg1 == 0);

    return static_cast<int32_T>(matchPos + 1) > 0;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_find_token(const emxArray_char_T_Real2SimGuidance_T
    *x, int32_T *itoken, int32_T *iremain)
{
    int32_T n;
    n = x->size[1];
    *iremain = 1;
    while ((*iremain <= n) && (x->data[static_cast<int32_T>(*iremain - 1)] ==
                               '=')) {
        *iremain = static_cast<int32_T>(*iremain + 1);
    }

    *itoken = *iremain;
    while ((*iremain <= n) && (x->data[static_cast<int32_T>(*iremain - 1)] !=
                               '=')) {
        *iremain = static_cast<int32_T>(*iremain + 1);
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_strtok_ay(const emxArray_char_T_Real2SimGuidance_T *
    x, emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain)
{
    int32_T b;
    int32_T c;
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    Real2SimGuidance_find_token(x, &itoken, &iremain);
    if (iremain > x->size[1]) {
        c = 0;
        b = 0;
    } else {
        c = static_cast<int32_T>(iremain - 1);
        b = x->size[1];
    }

    i = static_cast<int32_T>(remain->size[0] * remain->size[1]);
    remain->size[0] = 1;
    b = static_cast<int32_T>(b - c);
    remain->size[1] = b;
    Real2SimGuidance_emxEnsureCapacity_char_T(remain, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        remain->data[i] = x->data[static_cast<int32_T>(c + i)];
    }

    if (itoken > static_cast<int32_T>(iremain - 1)) {
        itoken = 0;
        iremain = 0;
    } else {
        itoken = static_cast<int32_T>(itoken - 1);
        iremain = static_cast<int32_T>(iremain - 1);
    }

    i = static_cast<int32_T>(token->size[0] * token->size[1]);
    token->size[0] = 1;
    b = static_cast<int32_T>(iremain - itoken);
    token->size[1] = b;
    Real2SimGuidance_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S96>/getSpeedLimit'
static void Real2SimGuidance_readINI_m(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW)
{
    static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T i[15]{ 'C', 'l', 'i', 'm', 'b', 'A', 'n', 'g', 'l', 'e',
        'L', 'i', 'm', 'i', 't' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    emxArray_char_T_Real2SimGuidance_T *curKey;
    emxArray_char_T_Real2SimGuidance_T *curLine;
    emxArray_char_T_Real2SimGuidance_T *curSection;
    emxArray_char_T_Real2SimGuidance_T *curVal;
    emxArray_char_T_Real2SimGuidance_T *data;
    emxArray_char_T_Real2SimGuidance_T *data_0;
    emxArray_char_T_Real2SimGuidance_T *j;
    emxArray_char_T_Real2SimGuidance_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = Real2SimGuidance_cfopen_pf("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T(&data, 2);
        Real2SimGuidance_emxInit_char_T(&j, 1);
        Real2SimGuidance_fread_j0(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        Real2SimGuidance_emxFree_char_T(&j);
        Real2SimGuidance_emxInit_char_T(&curSection, 2);
        Real2SimGuidance_emxInit_char_T(&curKey, 2);
        Real2SimGuidance_emxInit_char_T(&curVal, 2);
        Real2SimGuidance_cfclose_i(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T(&curLine, 2);
        Real2SimGuidance_emxInit_char_T(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T(&tmp, 2);
        Real2SimGuidance_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                Real2SimGuidance_strtok(data_0, curLine, data);
                Real2SimGuidance_strtok_a(curLine, tmp);
                Real2SimGuidance_strtrim(tmp, curLine);
                if (curLine->size[1] >= 2) {
                    boolean_T guard1{ false };

                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                iremain = 0;
                                itoken = 0;
                            } else {
                                iremain = 1;
                                itoken = static_cast<int32_T>(curLine->size[1] -
                                    1);
                            }

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curSection->data[itoken_0] = curLine->data[
                                    static_cast<int32_T>(iremain + itoken_0)];
                            }

                            curKey->size[0] = 1;
                            curKey->size[1] = 0;
                        } else {
                            guard1 = true;
                        }
                    } else {
                        guard1 = true;
                    }

                    if (guard1) {
                        if (curLine->data[0] == ';') {
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                Real2SimGuidance_contains(curLine)) {
                            Real2SimGuidance_strtok_ay(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_g(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 15) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 15) {
                                if (h[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(aTmp->data[iremain]))
                                     & 127)] != h[static_cast<int32_T>(i[iremain])])
                                {
                                    exitg2 = 1;
                                } else {
                                    iremain = static_cast<int32_T>(iremain + 1);
                                }
                            } else {
                                b_bool = true;
                                exitg2 = 1;
                            }
                        } while (exitg2 == 0);
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret, itoken_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            ret->data[itoken_0] = curVal->data[itoken_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T(&data_0);
        Real2SimGuidance_emxFree_char_T(&tmp);
        Real2SimGuidance_emxFree_char_T(&aTmp);
        Real2SimGuidance_emxFree_char_T(&curLine);
        Real2SimGuidance_emxFree_char_T(&curVal);
        Real2SimGuidance_emxFree_char_T(&curKey);
        Real2SimGuidance_emxFree_char_T(&curSection);
        Real2SimGuidance_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<Root>/RepulDir'
static void Real2SimGuidance_hypot_p(const real_T x_data[], const int32_T
    *x_size, const real_T y_data[], const int32_T *y_size, real_T r_data[],
    int32_T *r_size)
{
    int8_T csz_idx_0;
    if (*x_size <= *y_size) {
        csz_idx_0 = static_cast<int8_T>(*x_size);
    } else {
        csz_idx_0 = static_cast<int8_T>(*y_size);
    }

    *r_size = static_cast<int32_T>(csz_idx_0);
    for (int32_T k{0}; k <= static_cast<int32_T>(static_cast<int32_T>(csz_idx_0)
          - 1); k = static_cast<int32_T>(k + 1)) {
        r_data[k] = rt_hypotd_snf(x_data[k], y_data[k]);
    }
}

// Function for MATLAB Function: '<S96>/getSpeedLimit'
static void Real2SimGuidance_readINI_mh(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW)
{
    static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T i[14]{ 'D', 'i', 'v', 'e', 'A', 'n', 'g', 'l', 'e', 'L',
        'i', 'm', 'i', 't' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    emxArray_char_T_Real2SimGuidance_T *curKey;
    emxArray_char_T_Real2SimGuidance_T *curLine;
    emxArray_char_T_Real2SimGuidance_T *curSection;
    emxArray_char_T_Real2SimGuidance_T *curVal;
    emxArray_char_T_Real2SimGuidance_T *data;
    emxArray_char_T_Real2SimGuidance_T *data_0;
    emxArray_char_T_Real2SimGuidance_T *j;
    emxArray_char_T_Real2SimGuidance_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = Real2SimGuidance_cfopen_pf("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T(&data, 2);
        Real2SimGuidance_emxInit_char_T(&j, 1);
        Real2SimGuidance_fread_j0(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        Real2SimGuidance_emxFree_char_T(&j);
        Real2SimGuidance_emxInit_char_T(&curSection, 2);
        Real2SimGuidance_emxInit_char_T(&curKey, 2);
        Real2SimGuidance_emxInit_char_T(&curVal, 2);
        Real2SimGuidance_cfclose_i(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T(&curLine, 2);
        Real2SimGuidance_emxInit_char_T(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T(&tmp, 2);
        Real2SimGuidance_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                Real2SimGuidance_strtok(data_0, curLine, data);
                Real2SimGuidance_strtok_a(curLine, tmp);
                Real2SimGuidance_strtrim(tmp, curLine);
                if (curLine->size[1] >= 2) {
                    boolean_T guard1{ false };

                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                iremain = 0;
                                itoken = 0;
                            } else {
                                iremain = 1;
                                itoken = static_cast<int32_T>(curLine->size[1] -
                                    1);
                            }

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curSection->data[itoken_0] = curLine->data[
                                    static_cast<int32_T>(iremain + itoken_0)];
                            }

                            curKey->size[0] = 1;
                            curKey->size[1] = 0;
                        } else {
                            guard1 = true;
                        }
                    } else {
                        guard1 = true;
                    }

                    if (guard1) {
                        if (curLine->data[0] == ';') {
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                Real2SimGuidance_contains(curLine)) {
                            Real2SimGuidance_strtok_ay(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_g(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 14) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 14) {
                                if (h[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(aTmp->data[iremain]))
                                     & 127)] != h[static_cast<int32_T>(i[iremain])])
                                {
                                    exitg2 = 1;
                                } else {
                                    iremain = static_cast<int32_T>(iremain + 1);
                                }
                            } else {
                                b_bool = true;
                                exitg2 = 1;
                            }
                        } while (exitg2 == 0);
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret, itoken_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            ret->data[itoken_0] = curVal->data[itoken_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T(&data_0);
        Real2SimGuidance_emxFree_char_T(&tmp);
        Real2SimGuidance_emxFree_char_T(&aTmp);
        Real2SimGuidance_emxFree_char_T(&curLine);
        Real2SimGuidance_emxFree_char_T(&curVal);
        Real2SimGuidance_emxFree_char_T(&curKey);
        Real2SimGuidance_emxFree_char_T(&curSection);
        Real2SimGuidance_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static void Real2SimGuidance_strtok_gdxx(const
    emxArray_char_T_Real2SimGuidance_T *x, emxArray_char_T_Real2SimGuidance_T
    *token)
{
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    Real2SimGuidance_find_token(x, &itoken, &iremain);
    if (itoken > static_cast<int32_T>(iremain - 1)) {
        itoken = 0;
        iremain = 0;
    } else {
        itoken = static_cast<int32_T>(itoken - 1);
        iremain = static_cast<int32_T>(iremain - 1);
    }

    i = static_cast<int32_T>(token->size[0] * token->size[1]);
    token->size[0] = 1;
    iremain = static_cast<int32_T>(iremain - itoken);
    token->size[1] = iremain;
    Real2SimGuidance_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(iremain - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_ghb(const
    emxArray_char_T_Real2SimGuidance_T *a)
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

    static const char_T d[9]{ 'M', 'a', 'x', 'A', 'i', 'r', 'S', 'p', 'd' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    Real2SimGuidance_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 9) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 9) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    Real2SimGuidance_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S98>/getSpeedLimit'
static void Real2SimGuidance_readINI_n(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW)
{
    static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T i[15]{ 'C', 'l', 'i', 'm', 'b', 'A', 'n', 'g', 'l', 'e',
        'L', 'i', 'm', 'i', 't' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    emxArray_char_T_Real2SimGuidance_T *curKey;
    emxArray_char_T_Real2SimGuidance_T *curLine;
    emxArray_char_T_Real2SimGuidance_T *curSection;
    emxArray_char_T_Real2SimGuidance_T *curVal;
    emxArray_char_T_Real2SimGuidance_T *data;
    emxArray_char_T_Real2SimGuidance_T *data_0;
    emxArray_char_T_Real2SimGuidance_T *j;
    emxArray_char_T_Real2SimGuidance_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = Real2SimGuidance_cfopen_d("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T(&data, 2);
        Real2SimGuidance_emxInit_char_T(&j, 1);
        Real2SimGuidance_fread_k(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        Real2SimGuidance_emxFree_char_T(&j);
        Real2SimGuidance_emxInit_char_T(&curSection, 2);
        Real2SimGuidance_emxInit_char_T(&curKey, 2);
        Real2SimGuidance_emxInit_char_T(&curVal, 2);
        Real2SimGuidance_cfclose_c(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T(&curLine, 2);
        Real2SimGuidance_emxInit_char_T(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T(&tmp, 2);
        Real2SimGuidance_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                Real2SimGuidance_strtok(data_0, curLine, data);
                Real2SimGuidance_strtok_a(curLine, tmp);
                Real2SimGuidance_strtrim(tmp, curLine);
                if (curLine->size[1] >= 2) {
                    boolean_T guard1{ false };

                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                iremain = 0;
                                itoken = 0;
                            } else {
                                iremain = 1;
                                itoken = static_cast<int32_T>(curLine->size[1] -
                                    1);
                            }

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curSection->data[itoken_0] = curLine->data[
                                    static_cast<int32_T>(iremain + itoken_0)];
                            }

                            curKey->size[0] = 1;
                            curKey->size[1] = 0;
                        } else {
                            guard1 = true;
                        }
                    } else {
                        guard1 = true;
                    }

                    if (guard1) {
                        if (curLine->data[0] == ';') {
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                Real2SimGuidance_contains(curLine)) {
                            Real2SimGuidance_strtok_ay(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_g(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 15) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 15) {
                                if (h[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(aTmp->data[iremain]))
                                     & 127)] != h[static_cast<int32_T>(i[iremain])])
                                {
                                    exitg2 = 1;
                                } else {
                                    iremain = static_cast<int32_T>(iremain + 1);
                                }
                            } else {
                                b_bool = true;
                                exitg2 = 1;
                            }
                        } while (exitg2 == 0);
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret, itoken_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            ret->data[itoken_0] = curVal->data[itoken_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T(&data_0);
        Real2SimGuidance_emxFree_char_T(&tmp);
        Real2SimGuidance_emxFree_char_T(&aTmp);
        Real2SimGuidance_emxFree_char_T(&curLine);
        Real2SimGuidance_emxFree_char_T(&curVal);
        Real2SimGuidance_emxFree_char_T(&curKey);
        Real2SimGuidance_emxFree_char_T(&curSection);
        Real2SimGuidance_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S16>/minus'
static void Real2SimGuidance_repmat(const real_T a[2], real_T varargin_1,
    emxArray_real_T_Real2SimGuidance_T *b)
{
    int32_T itilerow;
    itilerow = static_cast<int32_T>(b->size[0] * b->size[1]);
    b->size[0] = static_cast<int32_T>(varargin_1);
    b->size[1] = 2;
    Real2SimGuidance_emxEnsureCapacity_real_T(b, itilerow);
    for (itilerow = 0; itilerow <= static_cast<int32_T>(static_cast<int32_T>
            (varargin_1) - 1); itilerow = static_cast<int32_T>(itilerow + 1)) {
        b->data[itilerow] = a[0];
    }

    for (itilerow = 0; itilerow <= static_cast<int32_T>(static_cast<int32_T>
            (varargin_1) - 1); itilerow = static_cast<int32_T>(itilerow + 1)) {
        b->data[static_cast<int32_T>(static_cast<int32_T>(varargin_1) + itilerow)]
            = a[1];
    }
}

static void Real2SimGuidance_binary_expand_op_pu
    (emxArray_real_T_Real2SimGuidance_T *in1, const real_T in2[2097152], const
     int32_T in3[2], const emxArray_real_T_Real2SimGuidance_T *in4)
{
    int32_T aux_0_1;
    int32_T i_0;
    int32_T in3_idx_0;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_0_1;
    int32_T stride_1_0;

    // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
    // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
    // MATLAB Function: '<S16>/minus'
    in3_idx_0 = in3[0];
    i_0 = static_cast<int32_T>(in1->size[0] * in1->size[1]);
    in1->size[0] = in4->size[0] == 1 ? in3[0] : in4->size[0];
    in1->size[1] = 2;
    Real2SimGuidance_emxEnsureCapacity_real_T(in1, i_0);
    stride_0_0 = (in3[0] != 1);
    stride_0_1 = (in3[1] != 1);
    stride_1_0 = (in4->size[0] != 1);
    aux_0_1 = 0;
    loop_ub = in4->size[0] == 1 ? in3[0] : in4->size[0];
    for (i_0 = 0; i_0 < 2; i_0++) {
        for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            in1->data[static_cast<int32_T>(i + static_cast<int32_T>(in1->size[0]
                * i_0))] = in2[static_cast<int32_T>(static_cast<int32_T>(i *
                stride_0_0) + static_cast<int32_T>(in3_idx_0 * aux_0_1))] -
                in4->data[static_cast<int32_T>(static_cast<int32_T>(i *
                stride_1_0) + static_cast<int32_T>(in4->size[0] * i_0))];
        }

        aux_0_1 = static_cast<int32_T>(aux_0_1 + stride_0_1);
    }

    // End of MATLAB Function: '<S16>/minus'
    // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
    // End of Outputs for SubSystem: '<Root>/AvoidDanger'
}

// Function for MATLAB Function: '<S98>/getSpeedLimit'
static void Real2SimGuidance_readINI_ng(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW)
{
    static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T i[14]{ 'D', 'i', 'v', 'e', 'A', 'n', 'g', 'l', 'e', 'L',
        'i', 'm', 'i', 't' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    emxArray_char_T_Real2SimGuidance_T *curKey;
    emxArray_char_T_Real2SimGuidance_T *curLine;
    emxArray_char_T_Real2SimGuidance_T *curSection;
    emxArray_char_T_Real2SimGuidance_T *curVal;
    emxArray_char_T_Real2SimGuidance_T *data;
    emxArray_char_T_Real2SimGuidance_T *data_0;
    emxArray_char_T_Real2SimGuidance_T *j;
    emxArray_char_T_Real2SimGuidance_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = Real2SimGuidance_cfopen_d("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T(&data, 2);
        Real2SimGuidance_emxInit_char_T(&j, 1);
        Real2SimGuidance_fread_k(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        Real2SimGuidance_emxFree_char_T(&j);
        Real2SimGuidance_emxInit_char_T(&curSection, 2);
        Real2SimGuidance_emxInit_char_T(&curKey, 2);
        Real2SimGuidance_emxInit_char_T(&curVal, 2);
        Real2SimGuidance_cfclose_c(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T(&curLine, 2);
        Real2SimGuidance_emxInit_char_T(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T(&tmp, 2);
        Real2SimGuidance_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                Real2SimGuidance_strtok(data_0, curLine, data);
                Real2SimGuidance_strtok_a(curLine, tmp);
                Real2SimGuidance_strtrim(tmp, curLine);
                if (curLine->size[1] >= 2) {
                    boolean_T guard1{ false };

                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                iremain = 0;
                                itoken = 0;
                            } else {
                                iremain = 1;
                                itoken = static_cast<int32_T>(curLine->size[1] -
                                    1);
                            }

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curSection->data[itoken_0] = curLine->data[
                                    static_cast<int32_T>(iremain + itoken_0)];
                            }

                            curKey->size[0] = 1;
                            curKey->size[1] = 0;
                        } else {
                            guard1 = true;
                        }
                    } else {
                        guard1 = true;
                    }

                    if (guard1) {
                        if (curLine->data[0] == ';') {
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                Real2SimGuidance_contains(curLine)) {
                            Real2SimGuidance_strtok_ay(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_g(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 14) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 14) {
                                if (h[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(aTmp->data[iremain]))
                                     & 127)] != h[static_cast<int32_T>(i[iremain])])
                                {
                                    exitg2 = 1;
                                } else {
                                    iremain = static_cast<int32_T>(iremain + 1);
                                }
                            } else {
                                b_bool = true;
                                exitg2 = 1;
                            }
                        } while (exitg2 == 0);
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret, itoken_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            ret->data[itoken_0] = curVal->data[itoken_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T(&data_0);
        Real2SimGuidance_emxFree_char_T(&tmp);
        Real2SimGuidance_emxFree_char_T(&aTmp);
        Real2SimGuidance_emxFree_char_T(&curLine);
        Real2SimGuidance_emxFree_char_T(&curVal);
        Real2SimGuidance_emxFree_char_T(&curKey);
        Real2SimGuidance_emxFree_char_T(&curSection);
        Real2SimGuidance_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_ghbx(const
    emxArray_char_T_Real2SimGuidance_T *a)
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

    static const char_T d[9]{ 'M', 'i', 'n', 'A', 'i', 'r', 'S', 'p', 'd' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    Real2SimGuidance_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 9) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 9) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    Real2SimGuidance_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static uavDubinsConnection_Real2SimGuidance_T
    *Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_Real2SimGuidance_T *b_this, real_T varargin_2, real_T
     varargin_4)
{
    uavDubinsConnection_Real2SimGuidance_T *c_this;
    c_this = b_this;
    b_this->AirSpeed = 10.0;
    b_this->MaxRollAngle = varargin_4;
    b_this->AirSpeed = varargin_2;
    return c_this;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_ghbx5(const
    emxArray_char_T_Real2SimGuidance_T *a)
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

    static const char_T d[12]{ 'M', 'a', 'x', 'R', 'o', 'l', 'l', 'A', 'n', 'g',
        'l', 'e' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    Real2SimGuidance_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 12) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 12) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    Real2SimGuidance_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<Root>/RepulDir'
static real_T Real2SimGuidance_sum(const real_T x_data[], const int32_T *x_size)
{
    real_T y;
    if (*x_size == 0) {
        y = 0.0;
    } else {
        y = x_data[0];
        for (int32_T k{2}; k <= *x_size; k = static_cast<int32_T>(k + 1)) {
            y += x_data[static_cast<int32_T>(k - 1)];
        }
    }

    return y;
}

static real_T Real2SimGuidance_binary_expand_op_puh(const real_T in1_data[],
    const int32_T *in1_size, const real_T in2_data[], const int32_T *in2_size,
    const real_T in3_data[], const int32_T *in3_size)
{
    real_T in1_data_0[64];
    real_T in1_data_1[64];
    real_T out1;
    int32_T in1_size_0;
    int32_T in1_size_1;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;

    // MATLAB Function: '<Root>/RepulDir'
    in1_size_0 = *in2_size == 1 ? *in1_size : *in2_size;
    stride_0_0 = (*in1_size != 1);
    stride_1_0 = (*in2_size != 1);
    loop_ub = *in2_size == 1 ? *in1_size : *in2_size;
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_data_0[i] = in1_data[static_cast<int32_T>(i * stride_0_0)] *
            in2_data[static_cast<int32_T>(i * stride_1_0)];
    }

    in1_size_1 = *in3_size == 1 ? *in1_size : *in3_size;
    stride_0_0 = (*in1_size != 1);
    stride_1_0 = (*in3_size != 1);
    loop_ub = *in3_size == 1 ? *in1_size : *in3_size;
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_data_1[i] = in1_data[static_cast<int32_T>(i * stride_0_0)] *
            in3_data[static_cast<int32_T>(i * stride_1_0)];
    }

    out1 = rt_atan2d_snf(Real2SimGuidance_sum(in1_data_0, &in1_size_0),
                         Real2SimGuidance_sum(in1_data_1, &in1_size_1));

    // End of MATLAB Function: '<Root>/RepulDir'
    return out1;
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_expand_atan2(const
    emxArray_real_T_Real2SimGuidance_T *a, const
    emxArray_real_T_Real2SimGuidance_T *b, emxArray_real_T_Real2SimGuidance_T *c)
{
    int32_T acoef;
    int32_T csz_idx_0;
    if (b->size[0] == 1) {
        csz_idx_0 = a->size[0];
    } else if (a->size[0] == 1) {
        csz_idx_0 = b->size[0];
    } else if (a->size[0] <= b->size[0]) {
        csz_idx_0 = a->size[0];
    } else {
        csz_idx_0 = b->size[0];
    }

    acoef = c->size[0];
    c->size[0] = csz_idx_0;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, acoef);
    if (csz_idx_0 != 0) {
        int32_T bcoef;
        acoef = (a->size[0] != 1);
        bcoef = (b->size[0] != 1);
        for (int32_T k{0}; k <= static_cast<int32_T>(csz_idx_0 - 1); k =
                static_cast<int32_T>(k + 1)) {
            c->data[k] = rt_atan2d_snf(a->data[static_cast<int32_T>(acoef * k)],
                b->data[static_cast<int32_T>(bcoef * k)]);
        }
    }
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_expand_hypot(const
    emxArray_real_T_Real2SimGuidance_T *a, const
    emxArray_real_T_Real2SimGuidance_T *b, emxArray_real_T_Real2SimGuidance_T *c)
{
    int32_T acoef;
    int32_T csz_idx_0;
    if (b->size[0] == 1) {
        csz_idx_0 = a->size[0];
    } else if (a->size[0] == 1) {
        csz_idx_0 = b->size[0];
    } else if (a->size[0] <= b->size[0]) {
        csz_idx_0 = a->size[0];
    } else {
        csz_idx_0 = b->size[0];
    }

    acoef = c->size[0];
    c->size[0] = csz_idx_0;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, acoef);
    if (csz_idx_0 != 0) {
        int32_T bcoef;
        acoef = (a->size[0] != 1);
        bcoef = (b->size[0] != 1);
        for (int32_T k{0}; k <= static_cast<int32_T>(csz_idx_0 - 1); k =
                static_cast<int32_T>(k + 1)) {
            c->data[k] = rt_hypotd_snf(a->data[static_cast<int32_T>(acoef * k)],
                b->data[static_cast<int32_T>(bcoef * k)]);
        }
    }
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_hypot(const emxArray_real_T_Real2SimGuidance_T *x,
    const emxArray_real_T_Real2SimGuidance_T *y,
    emxArray_real_T_Real2SimGuidance_T *r)
{
    if (x->size[0] == y->size[0]) {
        int32_T csz_idx_0;
        int32_T k;
        if (x->size[0] <= y->size[0]) {
            csz_idx_0 = x->size[0];
        } else {
            csz_idx_0 = y->size[0];
        }

        k = r->size[0];
        r->size[0] = csz_idx_0;
        Real2SimGuidance_emxEnsureCapacity_real_T(r, k);
        for (k = 0; k <= static_cast<int32_T>(csz_idx_0 - 1); k =
                static_cast<int32_T>(k + 1)) {
            r->data[k] = rt_hypotd_snf(x->data[k], y->data[k]);
        }
    } else {
        Real2SimGuidance_expand_hypot(x, y, r);
    }
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_cart2pol(const emxArray_real_T_Real2SimGuidance_T
    *x, const emxArray_real_T_Real2SimGuidance_T *y,
    emxArray_real_T_Real2SimGuidance_T *th, emxArray_real_T_Real2SimGuidance_T
    *r)
{
    if (y->size[0] == x->size[0]) {
        int32_T csz_idx_0;
        int32_T k;
        if (y->size[0] <= x->size[0]) {
            csz_idx_0 = y->size[0];
        } else {
            csz_idx_0 = x->size[0];
        }

        k = th->size[0];
        th->size[0] = csz_idx_0;
        Real2SimGuidance_emxEnsureCapacity_real_T(th, k);
        for (k = 0; k <= static_cast<int32_T>(csz_idx_0 - 1); k =
                static_cast<int32_T>(k + 1)) {
            th->data[k] = rt_atan2d_snf(y->data[k], x->data[k]);
        }
    } else {
        Real2SimGuidance_expand_atan2(y, x, th);
    }

    Real2SimGuidance_hypot(x, y, r);
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_abs(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y)
{
    int32_T k;
    k = y->size[0];
    y->size[0] = x->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(y, k);
    for (k = 0; k <= static_cast<int32_T>(x->size[0] - 1); k =
            static_cast<int32_T>(k + 1)) {
        y->data[k] = std::abs(x->data[k]);
    }
}

static void Real2SimGuidance_emxInit_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T **pEmxArray, int32_T numDimensions)
{
    emxArray_boolean_T_Real2SimGuidance_T *emxArray;
    *pEmxArray = static_cast<emxArray_boolean_T_Real2SimGuidance_T *>(std::
        malloc(sizeof(emxArray_boolean_T_Real2SimGuidance_T)));
    emxArray = *pEmxArray;
    emxArray->data = static_cast<boolean_T *>(nullptr);
    emxArray->numDimensions = numDimensions;
    emxArray->size = static_cast<int32_T *>(std::malloc(static_cast<uint32_T>
        (sizeof(int32_T) * static_cast<uint32_T>(numDimensions))));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (int32_T i{0}; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void Real2SimGuidance_emxEnsureCapacity_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T *emxArray, int32_T oldNumel)
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

        emxArray->data = static_cast<boolean_T *>(newData);
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

static void Real2SimGuidance_binary_expand_op_p
    (emxArray_boolean_T_Real2SimGuidance_T *in1, const
     emxArray_real_T_Real2SimGuidance_T *in2, real_T in3, const
     emxArray_real_T_Real2SimGuidance_T *in4, const real_T in5[2])
{
    real_T in5_0;
    real_T in5_1;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;

    // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
    // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
    // MATLAB Function: '<S16>/Cartesian2Polar'
    in5_0 = in5[1];
    in5_1 = in5[0];
    i = in1->size[0];
    in1->size[0] = in4->size[0] == 1 ? in2->size[0] : in4->size[0];
    Real2SimGuidance_emxEnsureCapacity_boolean_T(in1, i);
    stride_0_0 = (in2->size[0] != 1);
    stride_1_0 = (in4->size[0] != 1);
    loop_ub = in4->size[0] == 1 ? in2->size[0] : in4->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        real_T tmp;
        tmp = in4->data[static_cast<int32_T>(i * stride_1_0)];
        in1->data[i] = static_cast<boolean_T>(static_cast<int32_T>((in2->data[
            static_cast<int32_T>(i * stride_0_0)] <= in3) & static_cast<int32_T>
            (static_cast<boolean_T>(static_cast<int32_T>((tmp < in5_0) & (tmp >
            in5_1))))));
    }

    // End of MATLAB Function: '<S16>/Cartesian2Polar'
    // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
    // End of Outputs for SubSystem: '<Root>/AvoidDanger'
}

static void Real2SimGuidance_emxFree_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_boolean_T_Real2SimGuidance_T *>
            (nullptr)) {
        if (((*pEmxArray)->data != static_cast<boolean_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_boolean_T_Real2SimGuidance_T *>
            (nullptr);
    }
}

static void Real2SimGuidance_emxInit_int32_T(emxArray_int32_T_Real2SimGuidance_T
    **pEmxArray, int32_T numDimensions)
{
    emxArray_int32_T_Real2SimGuidance_T *emxArray;
    *pEmxArray = static_cast<emxArray_int32_T_Real2SimGuidance_T *>(std::malloc
        (sizeof(emxArray_int32_T_Real2SimGuidance_T)));
    emxArray = *pEmxArray;
    emxArray->data = static_cast<int32_T *>(nullptr);
    emxArray->numDimensions = numDimensions;
    emxArray->size = static_cast<int32_T *>(std::malloc(static_cast<uint32_T>
        (sizeof(int32_T) * static_cast<uint32_T>(numDimensions))));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (int32_T i{0}; i <= static_cast<int32_T>(numDimensions - 1); i++) {
        emxArray->size[i] = 0;
    }
}

static void Real2SimGuidance_emxEnsureCapacity_int32_T
    (emxArray_int32_T_Real2SimGuidance_T *emxArray, int32_T oldNumel)
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

        emxArray->data = static_cast<int32_T *>(newData);
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

static void Real2SimGuidance_emxFree_int32_T(emxArray_int32_T_Real2SimGuidance_T
    **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_int32_T_Real2SimGuidance_T *>(nullptr))
    {
        if (((*pEmxArray)->data != static_cast<int32_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_int32_T_Real2SimGuidance_T *>(nullptr);
    }
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_mergesort(emxArray_int32_T_Real2SimGuidance_T *idx,
    const emxArray_real_T_Real2SimGuidance_T *x, int32_T n)
{
    emxArray_int32_T_Real2SimGuidance_T *iwork;
    int32_T i;
    int32_T tmp_0;
    Real2SimGuidance_emxInit_int32_T(&iwork, 1);
    tmp_0 = iwork->size[0];
    iwork->size[0] = idx->size[0];
    Real2SimGuidance_emxEnsureCapacity_int32_T(iwork, tmp_0);
    for (i = 1; i <= static_cast<int32_T>(n - 1); i = static_cast<int32_T>(i + 2))
    {
        if (static_cast<boolean_T>(static_cast<int32_T>((x->data
                [static_cast<int32_T>(i - 1)] <= x->data[i]) |
                static_cast<int32_T>(std::isnan(x->data[i]))))) {
            idx->data[static_cast<int32_T>(i - 1)] = i;
            idx->data[i] = static_cast<int32_T>(i + 1);
        } else {
            idx->data[static_cast<int32_T>(i - 1)] = static_cast<int32_T>(i + 1);
            idx->data[i] = i;
        }
    }

    if (static_cast<uint32_T>(static_cast<uint32_T>(n) & 1U) != 0U) {
        idx->data[static_cast<int32_T>(n - 1)] = n;
    }

    i = 2;
    while (i < n) {
        int32_T i2;
        int32_T j;
        int32_T pEnd;
        i2 = static_cast<int32_T>(i << 1);
        j = 1;
        pEnd = static_cast<int32_T>(i + 1);
        while (pEnd < static_cast<int32_T>(n + 1)) {
            int32_T k;
            int32_T kEnd;
            int32_T p;
            int32_T q;
            int32_T qEnd;
            p = j;
            q = static_cast<int32_T>(pEnd - 1);
            qEnd = static_cast<int32_T>(j + i2);
            if (qEnd > static_cast<int32_T>(n + 1)) {
                qEnd = static_cast<int32_T>(n + 1);
            }

            k = 0;
            kEnd = static_cast<int32_T>(qEnd - j);
            while (static_cast<int32_T>(k + 1) <= kEnd) {
                real_T tmp;
                tmp = x->data[static_cast<int32_T>(idx->data[q] - 1)];
                tmp_0 = idx->data[static_cast<int32_T>(p - 1)];
                if (static_cast<boolean_T>(static_cast<int32_T>((x->data[
                        static_cast<int32_T>(tmp_0 - 1)] <= tmp) |
                        static_cast<int32_T>(std::isnan(tmp))))) {
                    iwork->data[k] = tmp_0;
                    p = static_cast<int32_T>(p + 1);
                    if (p == pEnd) {
                        while (static_cast<int32_T>(q + 1) < qEnd) {
                            k = static_cast<int32_T>(k + 1);
                            iwork->data[k] = idx->data[q];
                            q = static_cast<int32_T>(q + 1);
                        }
                    }
                } else {
                    iwork->data[k] = idx->data[q];
                    q = static_cast<int32_T>(q + 1);
                    if (static_cast<int32_T>(q + 1) == qEnd) {
                        while (p < pEnd) {
                            k = static_cast<int32_T>(k + 1);
                            iwork->data[k] = idx->data[static_cast<int32_T>(p -
                                1)];
                            p = static_cast<int32_T>(p + 1);
                        }
                    }
                }

                k = static_cast<int32_T>(k + 1);
            }

            for (pEnd = -1; static_cast<int32_T>(pEnd + 1) <=
                    static_cast<int32_T>(kEnd - 1); pEnd = static_cast<int32_T>
                    (pEnd + 1)) {
                idx->data[static_cast<int32_T>(j + pEnd)] = iwork->data[
                    static_cast<int32_T>(pEnd + 1)];
            }

            j = qEnd;
            pEnd = static_cast<int32_T>(qEnd + i);
        }

        i = i2;
    }

    Real2SimGuidance_emxFree_int32_T(&iwork);
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_sortIdx(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_int32_T_Real2SimGuidance_T *idx)
{
    int32_T b_idx_0;
    int32_T i;
    b_idx_0 = x->size[0];
    i = idx->size[0];
    idx->size[0] = x->size[0];
    Real2SimGuidance_emxEnsureCapacity_int32_T(idx, i);
    for (i = 0; i <= static_cast<int32_T>(b_idx_0 - 1); i++) {
        idx->data[i] = 0;
    }

    Real2SimGuidance_mergesort(idx, x, x->size[0]);
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_unique_vector(const
    emxArray_real_T_Real2SimGuidance_T *a, emxArray_real_T_Real2SimGuidance_T *b)
{
    emxArray_int32_T_Real2SimGuidance_T *idx;
    real_T x;
    int32_T c_k;
    int32_T nInf;
    int32_T nNaN;
    int32_T na;
    int32_T nb;
    boolean_T exitg1;
    Real2SimGuidance_emxInit_int32_T(&idx, 1);
    na = a->size[0];
    Real2SimGuidance_sortIdx(a, idx);
    c_k = b->size[0];
    b->size[0] = a->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(b, c_k);
    for (c_k = 0; c_k <= static_cast<int32_T>(na - 1); c_k = static_cast<int32_T>
            (c_k + 1)) {
        b->data[c_k] = a->data[static_cast<int32_T>(idx->data[c_k] - 1)];
    }

    Real2SimGuidance_emxFree_int32_T(&idx);
    c_k = 0;
    while ((static_cast<int32_T>(c_k + 1) <= na) && std::isinf(b->data[c_k]) &&
            (b->data[c_k] < 0.0)) {
        c_k = static_cast<int32_T>(c_k + 1);
    }

    na = c_k;
    c_k = a->size[0];
    while ((c_k >= 1) && std::isnan(b->data[static_cast<int32_T>(c_k - 1)])) {
        c_k = static_cast<int32_T>(c_k - 1);
    }

    nNaN = static_cast<int32_T>(a->size[0] - c_k);
    exitg1 = false;
    while ((!exitg1) && (c_k >= 1)) {
        x = b->data[static_cast<int32_T>(c_k - 1)];
        if (std::isinf(x) && (x > 0.0)) {
            c_k = static_cast<int32_T>(c_k - 1);
        } else {
            exitg1 = true;
        }
    }

    nInf = static_cast<int32_T>(static_cast<int32_T>(a->size[0] - c_k) - nNaN);
    nb = -1;
    if (na > 0) {
        nb = 0;
    }

    while (static_cast<int32_T>(na + 1) <= c_k) {
        x = b->data[na];
        do {
            na = static_cast<int32_T>(na + 1);
        } while (!((static_cast<int32_T>(na + 1) > c_k) || (b->data[na] != x)));

        nb = static_cast<int32_T>(nb + 1);
        b->data[nb] = x;
    }

    if (nInf > 0) {
        nb = static_cast<int32_T>(nb + 1);
        b->data[nb] = b->data[c_k];
    }

    na = static_cast<int32_T>(c_k + nInf);
    for (c_k = 0; c_k <= static_cast<int32_T>(nNaN - 1); c_k =
            static_cast<int32_T>(c_k + 1)) {
        nb = static_cast<int32_T>(nb + 1);
        b->data[nb] = b->data[static_cast<int32_T>(na + c_k)];
    }

    if (static_cast<int32_T>(nb + 1) < 1) {
        b->size[0] = 0;
    } else {
        c_k = b->size[0];
        b->size[0] = static_cast<int32_T>(nb + 1);
        Real2SimGuidance_emxEnsureCapacity_real_T(b, c_k);
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static int8_T Real2SimGuidance_filedata(DW_Real2SimGuidance_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static int8_T Real2SimGuidance_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = Real2SimGuidance_filedata(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles[static_cast<int32_T>(static_cast<int32_T>(j)
                - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_fread(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(std::round(fileID));
    if (fileID != static_cast<real_T>(fileid)) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        filestar = localDW->eml_openfiles[static_cast<int32_T>
            (static_cast<int32_T>(fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
              static_cast<boolean_T>(static_cast<int32_T>((fileID != 0.0) ^ 1)))
             | static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
               ((fileID != 1.0) ^ 1)))))) | static_cast<int32_T>
            (static_cast<boolean_T>(static_cast<int32_T>((fileID != 2.0) ^ 1))))))
    {
        filestar = NULL;
    }

    A->size[0] = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == NULL) ^ 1))) {
        int32_T c;
        c = 1;
        while (c > 0) {
            int32_T c_0;
            int32_T i;
            int32_T numRead;
            c = 0;
            numRead = 1;
            while (static_cast<boolean_T>(static_cast<int32_T>((c < 1024) &
                     (numRead > 0)))) {
                size_t numReadSizeT;
                numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c),
                                     filestar);
                numRead = (int32_T)numReadSizeT;
                c = static_cast<int32_T>(c + (int32_T)numReadSizeT);
            }

            numRead = A->size[0];
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            i = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(c_0 + A->
                size[0]) + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T(A, i);
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            for (i = 0; i <= c_0; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static int32_T Real2SimGuidance_cfclose(real_T fid, DW_Real2SimGuidance_f_T
    *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(std::round(fid));
    if (fid != static_cast<real_T>(fileid)) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = localDW->eml_openfiles[static_cast<int32_T>
            (static_cast<int32_T>(b_fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(b_fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((filestar != NULL) & (
            static_cast<int32_T>(fileid) >= 3)))) {
        int32_T cst;
        cst = fclose(filestar);
        if (cst == 0) {
            st = 0;
            localDW->eml_openfiles[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

static void Real2SimGuidance_SystemCore_initializeInputSizes
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2)
{
    obj->inputVarSize[0].f1[0] = static_cast<uint32_T>(varargin_1->size[0]);
    obj->inputVarSize[0].f1[1] = 1U;
    obj->inputVarSize[1].f1[0] = static_cast<uint32_T>(varargin_2->size[0]);
    obj->inputVarSize[1].f1[1] = 1U;
    for (int32_T i{0}; i < 6; i++) {
        obj->inputVarSize[0].f1[static_cast<int32_T>(i + 2)] = 1U;
        obj->inputVarSize[1].f1[static_cast<int32_T>(i + 2)] = 1U;
    }

    for (int32_T i{0}; i < 8; i++) {
        obj->inputVarSize[2].f1[i] = 1U;
    }
}

static void Real2SimGuidance_SystemCore_systemblock_prestep
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2)
{
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (obj->CacheInputSizes) ^ 1))) {
        obj->CacheInputSizes = true;
        Real2SimGuidance_SystemCore_initializeInputSizes(obj, varargin_1,
            varargin_2);
    }
}

static boolean_T Real2SimGuidance_SystemCore_detectInputSizeChange
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2)
{
    int32_T b_k;
    uint32_T inSize[8];
    boolean_T anyInputSizeChanged;
    boolean_T exitg1;
    anyInputSizeChanged = false;
    inSize[0] = static_cast<uint32_T>(varargin_1->size[0]);
    inSize[1] = 1U;
    for (b_k = 0; b_k < 6; b_k++) {
        inSize[static_cast<int32_T>(b_k + 2)] = 1U;
    }

    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 8)) {
        if (obj->inputVarSize[0].f1[b_k] != inSize[b_k]) {
            anyInputSizeChanged = true;
            for (b_k = 0; b_k < 8; b_k++) {
                obj->inputVarSize[0].f1[b_k] = inSize[b_k];
            }

            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 1);
        }
    }

    inSize[0] = static_cast<uint32_T>(varargin_2->size[0]);
    inSize[1] = 1U;
    for (b_k = 0; b_k < 6; b_k++) {
        inSize[static_cast<int32_T>(b_k + 2)] = 1U;
    }

    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 8)) {
        if (obj->inputVarSize[1].f1[b_k] != inSize[b_k]) {
            anyInputSizeChanged = true;
            for (b_k = 0; b_k < 8; b_k++) {
                obj->inputVarSize[1].f1[b_k] = inSize[b_k];
            }

            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 1);
        }
    }

    return anyInputSizeChanged;
}

static boolean_T Real2SimGuidance_allOrAny_anonFcn1(const boolean_T x_data[],
    const int32_T *x_size)
{
    int32_T ix;
    boolean_T exitg1;
    boolean_T varargout_1;
    varargout_1 = false;
    ix = 0;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(ix + 1) <= *x_size)) {
        if (x_data[ix]) {
            varargout_1 = true;
            exitg1 = true;
        } else {
            ix = static_cast<int32_T>(ix + 1);
        }
    }

    return varargout_1;
}

static real_T Real2SimGuidance_sxfun_anonFcn2(real_T x)
{
    real_T varargout_1;
    if (std::isnan(x) || std::isinf(x)) {
        varargout_1 = (rtNaN);
    } else if (x == 0.0) {
        varargout_1 = 0.0;
    } else {
        boolean_T rEQ0;
        varargout_1 = std::fmod(x, 6.2831853071795862);
        rEQ0 = (varargout_1 == 0.0);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rEQ0) ^ 1))) {
            real_T q;
            q = std::abs(x / 6.2831853071795862);
            rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q - std::
                floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
        }

        if (rEQ0) {
            varargout_1 = 0.0;
        } else if (x < 0.0) {
            varargout_1 += 6.2831853071795862;
        }
    }

    return varargout_1;
}

static void Real2SimGuidance_binary_expand_op_l(boolean_T in1_data[], int32_T
    *in1_size, const emxArray_real_T_Real2SimGuidance_T *in2, const
    emxArray_real_T_Real2SimGuidance_T *in3)
{
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    *in1_size = in3->size[0] == 1 ? in2->size[0] : in3->size[0];
    stride_0_0 = (in2->size[0] != 1);
    stride_1_0 = (in3->size[0] != 1);
    loop_ub = in3->size[0] == 1 ? in2->size[0] : in3->size[0];
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_data[i] = static_cast<boolean_T>(static_cast<int32_T>((in2->data[
            static_cast<int32_T>(i * stride_0_0)] == 0.0) & (in3->data[
            static_cast<int32_T>(i * stride_1_0)] > 0.0)));
    }
}

static void Real2SimGuidance_wrapToPi_p34cmpaz
    (emxArray_real_T_Real2SimGuidance_T *theta, DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_real_T_Real2SimGuidance_T *y;
    int32_T b_k;
    int32_T nx;
    int32_T y_size;
    Real2SimGuidance_emxInit_real_T(&y, 1);
    nx = static_cast<int32_T>(theta->size[0] - 1);
    b_k = y->size[0];
    y->size[0] = theta->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(y, b_k);
    for (b_k = 0; b_k <= nx; b_k++) {
        y->data[b_k] = std::abs(theta->data[b_k]);
    }

    y_size = y->size[0];
    nx = y->size[0];
    for (b_k = 0; b_k <= static_cast<int32_T>(nx - 1); b_k++) {
        localDW->y_data[b_k] = (y->data[b_k] > 3.1415926535897931);
    }

    if (Real2SimGuidance_allOrAny_anonFcn1(localDW->y_data, &y_size)) {
        b_k = y->size[0];
        y->size[0] = theta->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(y, b_k);
        nx = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(nx - 1); b_k++) {
            y->data[b_k] = theta->data[b_k] + 3.1415926535897931;
        }

        b_k = theta->size[0];
        theta->size[0] = y->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(theta, b_k);
        nx = static_cast<int32_T>(y->size[0] - 1);
        for (b_k = 0; b_k <= nx; b_k++) {
            theta->data[b_k] = Real2SimGuidance_sxfun_anonFcn2(y->data[b_k]);
        }

        if (theta->size[0] == y->size[0]) {
            y_size = theta->size[0];
            nx = theta->size[0];
            for (b_k = 0; b_k <= static_cast<int32_T>(nx - 1); b_k++) {
                localDW->c_data[b_k] = static_cast<boolean_T>
                    (static_cast<int32_T>((theta->data[b_k] == 0.0) & (y->
                       data[b_k] > 0.0)));
            }
        } else {
            Real2SimGuidance_binary_expand_op_l(localDW->c_data, &y_size, theta,
                y);
        }

        nx = static_cast<int32_T>(y_size - 1);
        for (b_k = 0; b_k <= nx; b_k++) {
            if (localDW->c_data[b_k]) {
                theta->data[b_k] = 6.2831853071795862;
            }
        }

        nx = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(nx - 1); b_k++) {
            theta->data[b_k] -= 3.1415926535897931;
        }
    }

    Real2SimGuidance_emxFree_real_T(&y);
}

static void Real2SimGuidance_lidarScan_lidarScan(const
    emxArray_real_T_Real2SimGuidance_T *varargin_1, const
    emxArray_real_T_Real2SimGuidance_T *varargin_2,
    emxArray_real_T_Real2SimGuidance_T *obj_InternalRanges,
    emxArray_real_T_Real2SimGuidance_T *obj_InternalAngles, boolean_T
    *obj_ContainsOnlyFiniteData, DW_Real2SimGuidance_f_T *localDW)
{
    int32_T i;
    int32_T loop_ub;
    i = obj_InternalRanges->size[0];
    obj_InternalRanges->size[0] = varargin_1->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(obj_InternalRanges, i);
    loop_ub = varargin_1->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        obj_InternalRanges->data[i] = varargin_1->data[i];
    }

    i = obj_InternalAngles->size[0];
    obj_InternalAngles->size[0] = varargin_2->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(obj_InternalAngles, i);
    loop_ub = varargin_2->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        obj_InternalAngles->data[i] = varargin_2->data[i];
    }

    Real2SimGuidance_wrapToPi_p34cmpaz(obj_InternalAngles, localDW);
    *obj_ContainsOnlyFiniteData = false;
}

static robotics_core_internal_NameValueParser_Real2SimGuidance_T
    *Real2SimGuidance_NameValueParser_NameValueParser
    (robotics_core_internal_NameValueParser_Real2SimGuidance_T *obj)
{
    d_cell_wrap_Real2SimGuidance_T c;
    d_cell_wrap_Real2SimGuidance_T d;
    robotics_core_internal_NameValueParser_Real2SimGuidance_T *b_obj;
    c.f1[0] = 0.0;
    d.f1[0] = -3.1415926535897931;
    c.f1[1] = (rtInf);
    d.f1[1] = 3.1415926535897931;
    b_obj = obj;
    obj->Defaults[0] = c;
    obj->Defaults[1] = d;
    return b_obj;
}

static void Real2SimGuidance_wrapToPi_p3(const real_T theta[2], real_T b_theta[2])
{
    real_T y[2];
    int32_T b_k;
    boolean_T exitg1;
    boolean_T rEQ0;
    b_theta[0] = theta[0];
    y[0] = std::abs(theta[0]);
    b_theta[1] = theta[1];
    y[1] = std::abs(theta[1]);
    rEQ0 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 2)) {
        if (y[b_k] > 3.1415926535897931) {
            rEQ0 = true;
            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 1);
        }
    }

    if (rEQ0) {
        real_T q;
        real_T r;
        y[0] = theta[0] + 3.1415926535897931;
        y[1] = theta[1] + 3.1415926535897931;
        if (std::isnan(theta[0] + 3.1415926535897931) || std::isinf(theta[0] +
                3.1415926535897931)) {
            r = (rtNaN);
        } else if (theta[0] + 3.1415926535897931 == 0.0) {
            r = 0.0;
        } else {
            r = std::fmod(theta[0] + 3.1415926535897931, 6.2831853071795862);
            rEQ0 = (r == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                q = std::abs((theta[0] + 3.1415926535897931) /
                             6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q -
                    std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
            }

            if (rEQ0) {
                r = 0.0;
            } else if (theta[0] + 3.1415926535897931 < 0.0) {
                r += 6.2831853071795862;
            }
        }

        b_theta[0] = r;
        if (std::isnan(theta[1] + 3.1415926535897931) || std::isinf(theta[1] +
                3.1415926535897931)) {
            r = (rtNaN);
        } else if (theta[1] + 3.1415926535897931 == 0.0) {
            r = 0.0;
        } else {
            r = std::fmod(theta[1] + 3.1415926535897931, 6.2831853071795862);
            rEQ0 = (r == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                q = std::abs((theta[1] + 3.1415926535897931) /
                             6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q -
                    std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
            }

            if (rEQ0) {
                r = 0.0;
            } else if (theta[1] + 3.1415926535897931 < 0.0) {
                r += 6.2831853071795862;
            }
        }

        b_theta[1] = r;
        for (b_k = 0; b_k < 2; b_k++) {
            r = b_theta[b_k];
            if (static_cast<boolean_T>(static_cast<int32_T>((r == 0.0) & (y[b_k]
                   > 0.0)))) {
                r = 6.2831853071795862;
            }

            b_theta[b_k] = r;
        }

        b_theta[0] -= 3.1415926535897931;
        b_theta[1] -= 3.1415926535897931;
    }
}

static void Real2SimGuidance_isfinite(const emxArray_real_T_Real2SimGuidance_T
    *x, boolean_T b_data[], int32_T *b_size, DW_Real2SimGuidance_f_T *localDW)
{
    int32_T loop_ub;
    *b_size = x->size[0];
    loop_ub = x->size[0];
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        b_data[i] = std::isinf(x->data[i]);
    }

    loop_ub = x->size[0];
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        localDW->tmp_data_k[i] = std::isnan(x->data[i]);
    }

    loop_ub = *b_size;
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        b_data[i] = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(b_data[i]) ^ 1))) & static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (localDW->tmp_data_k[i]) ^ 1)))));
    }
}

static void Real2SimGuidance_sort(const real_T x[2], real_T b_x[2])
{
    b_x[0] = x[0];
    b_x[1] = x[1];
    if ((x[0] <= x[1]) || std::isnan(x[1])) {
    } else {
        b_x[0] = x[1];
        b_x[1] = x[0];
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq5(boolean_T in1_data[],
    int32_T *in1_size, const boolean_T in2_data[], const int32_T *in2_size,
    const boolean_T in3_data[], const int32_T *in3_size, const boolean_T
    in4_data[], const int32_T *in4_size, DW_Real2SimGuidance_f_T *localDW)
{
    int32_T in2_size_idx_0;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    int32_T stride_3_0;
    in2_size_idx_0 = *in4_size == 1 ? *in1_size == 1 ? *in3_size == 1 ?
        *in2_size : *in3_size : *in1_size : *in4_size;
    stride_0_0 = (*in2_size != 1);
    stride_1_0 = (*in3_size != 1);
    stride_2_0 = (*in1_size != 1);
    stride_3_0 = (*in4_size != 1);
    loop_ub = *in4_size == 1 ? *in1_size == 1 ? *in3_size == 1 ? *in2_size :
        *in3_size : *in1_size : *in4_size;
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        localDW->in2_data[i] = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(in2_data[static_cast<int32_T>(i * stride_0_0)])
            & static_cast<int32_T>(in3_data[static_cast<int32_T>(i * stride_1_0)]))))
            & static_cast<int32_T>(in1_data[static_cast<int32_T>(i * stride_2_0)]))))
            & static_cast<int32_T>(in4_data[static_cast<int32_T>(i * stride_3_0)])));
    }

    *in1_size = in2_size_idx_0;
    for (int32_T i{0}; i <= static_cast<int32_T>(in2_size_idx_0 - 1); i++) {
        in1_data[i] = localDW->in2_data[i];
    }
}

static void Real2SimGuidance_nullAssignment_bg
    (emxArray_real_T_Real2SimGuidance_T *x, const boolean_T idx_data[], const
     int32_T *idx_size)
{
    int32_T b_k;
    int32_T k0;
    int32_T nxin;
    int32_T nxout;
    nxin = static_cast<int32_T>(x->size[0] - 1);
    nxout = 0;
    k0 = static_cast<int32_T>(*idx_size - 1);
    for (b_k = 0; b_k <= k0; b_k++) {
        nxout = static_cast<int32_T>(nxout + static_cast<int32_T>(idx_data[b_k]));
    }

    nxout = static_cast<int32_T>(x->size[0] - nxout);
    k0 = -1;
    for (b_k = 0; b_k <= nxin; b_k++) {
        if ((static_cast<int32_T>(b_k + 1) > *idx_size) ||
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (idx_data[b_k]) ^ 1)))) {
            k0 = static_cast<int32_T>(k0 + 1);
            x->data[k0] = x->data[b_k];
        }
    }

    if (nxout < 1) {
        x->size[0] = 0;
    } else {
        b_k = x->size[0];
        x->size[0] = nxout;
        Real2SimGuidance_emxEnsureCapacity_real_T(x, b_k);
    }
}

static void Real2SimGuidance_lidarScan_extractValidData(const
    emxArray_real_T_Real2SimGuidance_T *objIn_InternalRanges, const
    emxArray_real_T_Real2SimGuidance_T *objIn_InternalAngles, const boolean_T
    validIndices_data[], const int32_T *validIndices_size,
    emxArray_real_T_Real2SimGuidance_T *objOut_InternalRanges,
    emxArray_real_T_Real2SimGuidance_T *objOut_InternalAngles, boolean_T
    *objOut_ContainsOnlyFiniteData, DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_real_T_Real2SimGuidance_T *tmp;
    emxArray_real_T_Real2SimGuidance_T *tmp_0;
    int32_T i;
    int32_T loop_ub;
    Real2SimGuidance_emxInit_real_T(&tmp, 1);
    i = tmp->size[0];
    tmp->size[0] = objIn_InternalRanges->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(tmp, i);
    loop_ub = objIn_InternalRanges->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        tmp->data[i] = objIn_InternalRanges->data[i];
    }

    loop_ub = *validIndices_size;
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        localDW->validIndices_data[i] = static_cast<boolean_T>
            (static_cast<int32_T>(static_cast<int32_T>(validIndices_data[i]) ^ 1));
    }

    Real2SimGuidance_emxInit_real_T(&tmp_0, 1);
    Real2SimGuidance_nullAssignment_bg(tmp, localDW->validIndices_data,
        validIndices_size);
    i = tmp_0->size[0];
    tmp_0->size[0] = objIn_InternalAngles->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(tmp_0, i);
    loop_ub = objIn_InternalAngles->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        tmp_0->data[i] = objIn_InternalAngles->data[i];
    }

    loop_ub = *validIndices_size;
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        localDW->validIndices_data[i] = static_cast<boolean_T>
            (static_cast<int32_T>(static_cast<int32_T>(validIndices_data[i]) ^ 1));
    }

    Real2SimGuidance_nullAssignment_bg(tmp_0, localDW->validIndices_data,
        validIndices_size);
    Real2SimGuidance_lidarScan_lidarScan(tmp, tmp_0, objOut_InternalRanges,
        objOut_InternalAngles, objOut_ContainsOnlyFiniteData, localDW);
    Real2SimGuidance_emxFree_real_T(&tmp_0);
    Real2SimGuidance_emxFree_real_T(&tmp);
}

static void Real2SimGuidance_lidarScan_removeInvalidData(const
    emxArray_real_T_Real2SimGuidance_T *obj_InternalRanges, const
    emxArray_real_T_Real2SimGuidance_T *obj_InternalAngles, const real_T
    varargin_2[2], emxArray_real_T_Real2SimGuidance_T *objOut_InternalRanges,
    emxArray_real_T_Real2SimGuidance_T *objOut_InternalAngles, boolean_T
    *objOut_ContainsOnlyFiniteData, DW_Real2SimGuidance_f_T *localDW)
{
    static real_T tmp[2]{ 0.0, 0.0 };

    emxArray_real_T_Real2SimGuidance_T *objOut_InternalAngles_0;
    emxArray_real_T_Real2SimGuidance_T *objOut_InternalRanges_1;
    robotics_core_internal_NameValueParser_Real2SimGuidance_T parser;
    real_T d[2];
    real_T objOut_InternalRanges_0;
    real_T parser_0;
    real_T parser_1;
    int32_T loop_ub;
    int32_T tmp_size;
    int32_T validAngleLimitIndices_size;
    int32_T validRangeLimitIndices_size;
    boolean_T exitg1;
    boolean_T objIn_ContainsOnlyFiniteData;
    boolean_T p;
    tmp[1U] = (rtInf);
    Real2SimGuidance_lidarScan_lidarScan(obj_InternalRanges, obj_InternalAngles,
        objOut_InternalRanges, objOut_InternalAngles,
        &objIn_ContainsOnlyFiniteData, localDW);
    validRangeLimitIndices_size = objOut_InternalRanges->size[0];
    loop_ub = objOut_InternalRanges->size[0];
    for (tmp_size = 0; tmp_size <= static_cast<int32_T>(loop_ub - 1); tmp_size++)
    {
        localDW->validRangeLimitIndices_data[tmp_size] = true;
    }

    validAngleLimitIndices_size = objOut_InternalRanges->size[0];
    loop_ub = objOut_InternalRanges->size[0];
    for (tmp_size = 0; tmp_size <= static_cast<int32_T>(loop_ub - 1); tmp_size++)
    {
        localDW->validAngleLimitIndices_data[tmp_size] = true;
    }

    Real2SimGuidance_NameValueParser_NameValueParser(&parser);
    parser.Defaults[0].f1[0] = varargin_2[0];
    parser.Defaults[0].f1[1] = varargin_2[1];
    parser.ParsedResults[0] = parser.Defaults[0];
    parser.ParsedResults[1] = parser.Defaults[1];
    objIn_ContainsOnlyFiniteData = false;
    p = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
        if (static_cast<boolean_T>(static_cast<int32_T>((parser.ParsedResults[0]
                .f1[loop_ub] == tmp[loop_ub]) ^ 1))) {
            p = false;
            exitg1 = true;
        } else {
            loop_ub = static_cast<int32_T>(loop_ub + 1);
        }
    }

    if (p) {
        objIn_ContainsOnlyFiniteData = true;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (objIn_ContainsOnlyFiniteData) ^ 1))) {
        parser_0 = parser.ParsedResults[0].f1[0];
        parser_1 = parser.ParsedResults[0].f1[1];
        validRangeLimitIndices_size = objOut_InternalRanges->size[0];
        loop_ub = objOut_InternalRanges->size[0];
        for (tmp_size = 0; tmp_size <= static_cast<int32_T>(loop_ub - 1);
                tmp_size++) {
            objOut_InternalRanges_0 = objOut_InternalRanges->data[tmp_size];
            localDW->validRangeLimitIndices_data[tmp_size] =
                static_cast<boolean_T>(static_cast<int32_T>
                ((objOut_InternalRanges_0 >= parser_0) &
                 (objOut_InternalRanges_0 <= parser_1)));
        }
    }

    objIn_ContainsOnlyFiniteData = false;
    p = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
        if (static_cast<boolean_T>(static_cast<int32_T>((6.2831853071795862 *
                static_cast<real_T>(loop_ub) + -3.1415926535897931 ==
                parser.ParsedResults[1].f1[loop_ub]) ^ 1))) {
            p = false;
            exitg1 = true;
        } else {
            loop_ub = static_cast<int32_T>(loop_ub + 1);
        }
    }

    if (p) {
        objIn_ContainsOnlyFiniteData = true;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (objIn_ContainsOnlyFiniteData) ^ 1))) {
        Real2SimGuidance_wrapToPi_p3(parser.ParsedResults[1].f1, d);
        Real2SimGuidance_sort(d, parser.ParsedResults[1].f1);
        parser_0 = parser.ParsedResults[1].f1[0];
        parser_1 = parser.ParsedResults[1].f1[1];
        validAngleLimitIndices_size = objOut_InternalAngles->size[0];
        loop_ub = objOut_InternalAngles->size[0];
        for (tmp_size = 0; tmp_size <= static_cast<int32_T>(loop_ub - 1);
                tmp_size++) {
            objOut_InternalRanges_0 = objOut_InternalAngles->data[tmp_size];
            localDW->validAngleLimitIndices_data[tmp_size] =
                static_cast<boolean_T>(static_cast<int32_T>
                ((objOut_InternalRanges_0 >= parser_0) &
                 (objOut_InternalRanges_0 <= parser_1)));
        }
    }

    Real2SimGuidance_isfinite(objOut_InternalRanges, localDW->tmp_data, &loop_ub,
        localDW);
    Real2SimGuidance_isfinite(objOut_InternalAngles, localDW->tmp_data_c,
        &tmp_size, localDW);
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(((loop_ub == 1 ?
               tmp_size : loop_ub) == validRangeLimitIndices_size) & (loop_ub ==
              tmp_size)))) & (((loop_ub == 1 ? tmp_size : loop_ub) == 1 ?
                               validRangeLimitIndices_size : loop_ub == 1 ?
                               tmp_size : loop_ub) ==
                              validAngleLimitIndices_size)))) {
        validRangeLimitIndices_size = loop_ub;
        for (tmp_size = 0; tmp_size <= static_cast<int32_T>(loop_ub - 1);
                tmp_size++) {
            localDW->validRangeLimitIndices_data[tmp_size] =
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->tmp_data[tmp_size]) & static_cast<int32_T>
                (localDW->tmp_data_c[tmp_size])))) & static_cast<int32_T>
                (localDW->validRangeLimitIndices_data[tmp_size])))) &
                static_cast<int32_T>(localDW->
                validAngleLimitIndices_data[tmp_size])));
        }
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5
            (localDW->validRangeLimitIndices_data, &validRangeLimitIndices_size,
             localDW->tmp_data, &loop_ub, localDW->tmp_data_c, &tmp_size,
             localDW->validAngleLimitIndices_data, &validAngleLimitIndices_size,
             localDW);
    }

    objIn_ContainsOnlyFiniteData = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(loop_ub + 1) <=
                         validRangeLimitIndices_size)) {
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->validRangeLimitIndices_data[loop_ub]) ^ 1))) {
            objIn_ContainsOnlyFiniteData = false;
            exitg1 = true;
        } else {
            loop_ub = static_cast<int32_T>(loop_ub + 1);
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (objIn_ContainsOnlyFiniteData) ^ 1))) {
        Real2SimGuidance_emxInit_real_T(&objOut_InternalRanges_1, 1);
        tmp_size = objOut_InternalRanges_1->size[0];
        objOut_InternalRanges_1->size[0] = objOut_InternalRanges->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(objOut_InternalRanges_1,
            tmp_size);
        loop_ub = static_cast<int32_T>(objOut_InternalRanges->size[0] - 1);
        for (tmp_size = 0; tmp_size <= loop_ub; tmp_size++) {
            objOut_InternalRanges_1->data[tmp_size] =
                objOut_InternalRanges->data[tmp_size];
        }

        Real2SimGuidance_emxInit_real_T(&objOut_InternalAngles_0, 1);
        tmp_size = objOut_InternalAngles_0->size[0];
        objOut_InternalAngles_0->size[0] = objOut_InternalAngles->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(objOut_InternalAngles_0,
            tmp_size);
        loop_ub = static_cast<int32_T>(objOut_InternalAngles->size[0] - 1);
        for (tmp_size = 0; tmp_size <= loop_ub; tmp_size++) {
            objOut_InternalAngles_0->data[tmp_size] =
                objOut_InternalAngles->data[tmp_size];
        }

        Real2SimGuidance_lidarScan_extractValidData(objOut_InternalRanges_1,
            objOut_InternalAngles_0, localDW->validRangeLimitIndices_data,
            &validRangeLimitIndices_size, objOut_InternalRanges,
            objOut_InternalAngles, objOut_ContainsOnlyFiniteData, localDW);
        *objOut_ContainsOnlyFiniteData = true;
        Real2SimGuidance_emxFree_real_T(&objOut_InternalAngles_0);
        Real2SimGuidance_emxFree_real_T(&objOut_InternalRanges_1);
    } else {
        *objOut_ContainsOnlyFiniteData = true;
    }
}

static void Real2SimGuidance_histc(const emxArray_real_T_Real2SimGuidance_T *X,
    const real_T edges[180], real_T N[180], emxArray_real_T_Real2SimGuidance_T
    *BIN)
{
    int32_T i;
    int32_T k;
    std::memset(&N[0], 0, static_cast<uint32_T>(180U * sizeof(real_T)));
    i = X->size[0];
    k = BIN->size[0];
    BIN->size[0] = X->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(BIN, k);
    for (k = 0; k <= static_cast<int32_T>(i - 1); k++) {
        BIN->data[k] = 0.0;
    }

    i = X->size[0];
    for (k = 0; k <= static_cast<int32_T>(i - 1); k++) {
        int32_T low_i;
        low_i = 0;
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(X->data[k])) ^ 1))) {
            if ((X->data[k] >= edges[0]) && (X->data[k] < edges[179])) {
                int32_T high_i;
                int32_T low_ip1;
                low_i = 1;
                low_ip1 = 1;
                high_i = 180;
                while (high_i > static_cast<int32_T>(low_ip1 + 1)) {
                    int32_T mid_i;
                    mid_i = static_cast<int32_T>(static_cast<int32_T>(low_i +
                        high_i) >> 1);
                    if (X->data[k] >= edges[static_cast<int32_T>(mid_i - 1)]) {
                        low_i = mid_i;
                        low_ip1 = mid_i;
                    } else {
                        high_i = mid_i;
                    }
                }
            }

            if (X->data[k] == edges[179]) {
                low_i = 180;
            }
        }

        if (low_i > 0) {
            N[static_cast<int32_T>(low_i - 1)]++;
        }

        BIN->data[k] = static_cast<real_T>(low_i);
    }
}

static void Real2SimGuidance_plus_o(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2, const
    emxArray_real_T_Real2SimGuidance_T *in3)
{
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    i = in1->size[0];
    in1->size[0] = in3->size[0] == 1 ? in2->size[0] : in3->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in1, i);
    stride_0_0 = (in2->size[0] != 1);
    stride_1_0 = (in3->size[0] != 1);
    loop_ub = in3->size[0] == 1 ? in2->size[0] : in3->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1->data[i] = in2->data[static_cast<int32_T>(i * stride_0_0)] +
            in3->data[static_cast<int32_T>(i * stride_1_0)];
    }
}

static void Real2SimGuidance_minus_l(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2)
{
    emxArray_real_T_Real2SimGuidance_T *in1_0;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    Real2SimGuidance_emxInit_real_T(&in1_0, 1);
    i = in1_0->size[0];
    in1_0->size[0] = in2->size[0] == 1 ? in1->size[0] : in2->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in1_0, i);
    stride_0_0 = (in1->size[0] != 1);
    stride_1_0 = (in2->size[0] != 1);
    loop_ub = in2->size[0] == 1 ? in1->size[0] : in2->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_0->data[i] = in1->data[static_cast<int32_T>(i * stride_0_0)] -
            in2->data[static_cast<int32_T>(i * stride_1_0)];
    }

    i = in1->size[0];
    in1->size[0] = in1_0->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in1, i);
    loop_ub = in1_0->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1->data[i] = in1_0->data[i];
    }

    Real2SimGuidance_emxFree_real_T(&in1_0);
}

static void Real2SimGuidance_cross(const emxArray_real_T_Real2SimGuidance_T *a,
    const emxArray_real_T_Real2SimGuidance_T *b,
    emxArray_real_T_Real2SimGuidance_T *c)
{
    int32_T k;
    k = static_cast<int32_T>(c->size[0] * c->size[1]);
    c->size[0] = a->size[0];
    c->size[1] = 3;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    if (a->size[0] != 0) {
        int32_T dim;
        int32_T iNext;
        int32_T stride;
        int32_T stridem1;
        boolean_T exitg1;
        dim = 0;
        stride = 1;
        exitg1 = false;
        while ((!exitg1) && (static_cast<int32_T>(stride - 1) < 2)) {
            if (a->size[static_cast<int32_T>(stride - 1)] == 3) {
                dim = stride;
                exitg1 = true;
            } else {
                stride = static_cast<int32_T>(stride + 1);
            }
        }

        if (dim >= 2) {
            stride = a->size[0];
            stridem1 = a->size[0];
        } else {
            stride = 1;
            stridem1 = 1;
        }

        iNext = static_cast<int32_T>(stride * 3);
        if (dim >= 2) {
            dim = 0;
        } else {
            dim = static_cast<int32_T>(iNext << 1);
        }

        for (k = 1; iNext < 0 ? k >= static_cast<int32_T>(dim + 1) : k <=
                static_cast<int32_T>(dim + 1); k += iNext) {
            int32_T iEnd;
            iEnd = static_cast<int32_T>(static_cast<int32_T>(k + stridem1) - 1);
            for (int32_T i1{k}; i1 <= iEnd; i1++) {
                int32_T i2;
                int32_T i3;
                i2 = static_cast<int32_T>(static_cast<int32_T>(i1 + stride) - 1);
                i3 = static_cast<int32_T>(i2 + stride);
                c->data[static_cast<int32_T>(i1 - 1)] = a->data[i2] * b->data[i3]
                    - a->data[i3] * b->data[i2];
                c->data[i2] = b->data[static_cast<int32_T>(i1 - 1)] * a->data[i3]
                    - a->data[static_cast<int32_T>(i1 - 1)] * b->data[i3];
                c->data[i3] = a->data[static_cast<int32_T>(i1 - 1)] * b->data[i2]
                    - b->data[static_cast<int32_T>(i1 - 1)] * a->data[i2];
            }
        }
    }
}

static void Real2SimGuidance_repmat_c(const real_T a[3], real_T varargin_1,
    emxArray_real_T_Real2SimGuidance_T *b)
{
    int32_T b_jcol;
    int32_T tmp;
    tmp = static_cast<int32_T>(varargin_1);
    b_jcol = static_cast<int32_T>(b->size[0] * b->size[1]);
    b->size[0] = static_cast<int32_T>(varargin_1);
    b->size[1] = 3;
    Real2SimGuidance_emxEnsureCapacity_real_T(b, b_jcol);
    for (b_jcol = 0; b_jcol < 3; b_jcol++) {
        int32_T ibmat;
        ibmat = static_cast<int32_T>(b_jcol * static_cast<int32_T>(varargin_1));
        for (int32_T b_itilerow{0}; b_itilerow <= static_cast<int32_T>(tmp - 1);
             b_itilerow++) {
            b->data[static_cast<int32_T>(ibmat + b_itilerow)] = a[b_jcol];
        }
    }
}

static void Real2SimGuidance_abs_p(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y)
{
    int32_T b_k;
    int32_T nx;
    nx = static_cast<int32_T>(x->size[0] - 1);
    b_k = y->size[0];
    y->size[0] = x->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(y, b_k);
    for (b_k = 0; b_k <= nx; b_k++) {
        y->data[b_k] = std::abs(x->data[b_k]);
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq
    (emxArray_real_T_Real2SimGuidance_T *in1, const
     emxArray_real_T_Real2SimGuidance_T *in2, const
     emxArray_real_T_Real2SimGuidance_T *in3)
{
    emxArray_real_T_Real2SimGuidance_T *in2_0;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    Real2SimGuidance_emxInit_real_T(&in2_0, 1);
    i = in2_0->size[0];
    in2_0->size[0] = in1->size[0] == 1 ? in3->size[0] == 1 ? in2->size[0] :
        in3->size[0] : in1->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in2_0, i);
    stride_0_0 = (in2->size[0] != 1);
    stride_1_0 = (in3->size[0] != 1);
    stride_2_0 = (in1->size[0] != 1);
    loop_ub = in1->size[0] == 1 ? in3->size[0] == 1 ? in2->size[0] : in3->size[0]
        : in1->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_0->data[i] = (in2->data[static_cast<int32_T>(i * stride_0_0)] +
                          in3->data[static_cast<int32_T>(i * stride_1_0)]) +
            in1->data[static_cast<int32_T>(i * stride_2_0)];
    }

    Real2SimGuidance_abs_p(in2_0, in1);
    Real2SimGuidance_emxFree_real_T(&in2_0);
}

static void Real2SimGuidance_VectorFieldHistogramBase_buildPolarObstacleDensity
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *scan_InternalRanges, const
     emxArray_real_T_Real2SimGuidance_T *scan_InternalAngles,
     DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_boolean_T_Real2SimGuidance_T *validWeights;
    emxArray_real_T_Real2SimGuidance_T *higherAng;
    emxArray_real_T_Real2SimGuidance_T *higherVec;
    emxArray_real_T_Real2SimGuidance_T *kalphaVec;
    emxArray_real_T_Real2SimGuidance_T *kh;
    emxArray_real_T_Real2SimGuidance_T *lh;
    emxArray_real_T_Real2SimGuidance_T *lk;
    emxArray_real_T_Real2SimGuidance_T *lowerAng;
    emxArray_real_T_Real2SimGuidance_T *lowerVec;
    emxArray_real_T_Real2SimGuidance_T *sinOfEnlargement;
    emxArray_real_T_Real2SimGuidance_T *varargin_2;
    emxArray_real_T_Real2SimGuidance_T *weightedRanges;
    real_T b_x[180];
    real_T b_x_0[180];
    real_T kalpha[3];
    real_T obj_0[2];
    real_T obj_1;
    int32_T e_i;
    int32_T loop_ub;
    boolean_T expl_temp;
    Real2SimGuidance_emxInit_real_T(&weightedRanges, 1);
    Real2SimGuidance_emxInit_real_T(&sinOfEnlargement, 1);
    Real2SimGuidance_emxInit_real_T(&lowerAng, 1);
    obj_0[0] = obj->DistanceLimits[0];
    obj_0[1] = obj->DistanceLimits[1];
    Real2SimGuidance_lidarScan_removeInvalidData(scan_InternalRanges,
        scan_InternalAngles, obj_0, sinOfEnlargement, lowerAng, &expl_temp,
        localDW);
    obj_1 = obj->DistanceLimits[1];
    e_i = weightedRanges->size[0];
    weightedRanges->size[0] = sinOfEnlargement->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(weightedRanges, e_i);
    loop_ub = sinOfEnlargement->size[0];
    for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
        weightedRanges->data[e_i] = obj_1 - sinOfEnlargement->data[e_i];
    }

    obj_1 = obj->RobotRadius + obj->SafetyDistance;
    Real2SimGuidance_emxInit_real_T(&higherAng, 1);
    if (obj_1 == 0.0) {
        int32_T nx;
        Real2SimGuidance_histc(lowerAng, obj->AngularSectorMidPoints, b_x,
                               higherAng);
        std::memset(&obj->PolarObstacleDensity[0], 0, static_cast<uint32_T>(180U
                     * sizeof(real_T)));
        nx = static_cast<int32_T>(higherAng->size[0] - 1);
        for (e_i = 0; e_i <= nx; e_i++) {
            obj_1 = higherAng->data[e_i];
            obj->PolarObstacleDensity[static_cast<int32_T>(static_cast<int32_T>
                (obj_1) - 1)] += weightedRanges->data[e_i];
        }
    } else {
        int32_T loop_ub_0;
        int32_T nx;
        loop_ub = sinOfEnlargement->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            sinOfEnlargement->data[e_i] = obj_1 / sinOfEnlargement->data[e_i];
        }

        nx = static_cast<int32_T>(sinOfEnlargement->size[0] - 1);
        for (e_i = 0; e_i <= nx; e_i++) {
            obj_1 = sinOfEnlargement->data[e_i];
            if (obj_1 >= 1.0) {
                obj_1 = 0.99999999999999978;
            }

            sinOfEnlargement->data[e_i] = obj_1;
        }

        nx = static_cast<int32_T>(sinOfEnlargement->size[0] - 1);
        for (e_i = 0; e_i <= nx; e_i++) {
            sinOfEnlargement->data[e_i] = std::asin(sinOfEnlargement->data[e_i]);
        }

        if (lowerAng->size[0] == sinOfEnlargement->size[0]) {
            e_i = higherAng->size[0];
            higherAng->size[0] = lowerAng->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(higherAng, e_i);
            loop_ub = lowerAng->size[0];
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
                higherAng->data[e_i] = lowerAng->data[e_i] +
                    sinOfEnlargement->data[e_i];
            }
        } else {
            Real2SimGuidance_plus_o(higherAng, lowerAng, sinOfEnlargement);
        }

        if (lowerAng->size[0] == sinOfEnlargement->size[0]) {
            loop_ub = lowerAng->size[0];
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
                lowerAng->data[e_i] -= sinOfEnlargement->data[e_i];
            }
        } else {
            Real2SimGuidance_minus_l(lowerAng, sinOfEnlargement);
        }

        e_i = sinOfEnlargement->size[0];
        sinOfEnlargement->size[0] = lowerAng->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(sinOfEnlargement, e_i);
        loop_ub = lowerAng->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            sinOfEnlargement->data[e_i] = lowerAng->data[e_i];
        }

        nx = static_cast<int32_T>(lowerAng->size[0] - 1);
        for (e_i = 0; e_i <= nx; e_i++) {
            sinOfEnlargement->data[e_i] = std::cos(sinOfEnlargement->data[e_i]);
        }

        Real2SimGuidance_emxInit_real_T(&varargin_2, 1);
        e_i = varargin_2->size[0];
        varargin_2->size[0] = lowerAng->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(varargin_2, e_i);
        loop_ub = lowerAng->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            varargin_2->data[e_i] = lowerAng->data[e_i];
        }

        for (e_i = 0; e_i <= nx; e_i++) {
            varargin_2->data[e_i] = std::sin(varargin_2->data[e_i]);
        }

        Real2SimGuidance_emxInit_real_T(&lowerVec, 2);
        e_i = static_cast<int32_T>(lowerVec->size[0] * lowerVec->size[1]);
        lowerVec->size[0] = sinOfEnlargement->size[0];
        lowerVec->size[1] = 3;
        Real2SimGuidance_emxEnsureCapacity_real_T(lowerVec, e_i);
        loop_ub = static_cast<int32_T>(lowerAng->size[0] - 1);
        loop_ub_0 = sinOfEnlargement->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
            lowerVec->data[e_i] = sinOfEnlargement->data[e_i];
        }

        loop_ub_0 = varargin_2->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
            lowerVec->data[static_cast<int32_T>(e_i + sinOfEnlargement->size[0])]
                = varargin_2->data[e_i];
        }

        for (e_i = 0; e_i <= loop_ub; e_i++) {
            lowerVec->data[static_cast<int32_T>(static_cast<int32_T>(e_i +
                sinOfEnlargement->size[0]) + varargin_2->size[0])] = 0.0;
        }

        e_i = sinOfEnlargement->size[0];
        sinOfEnlargement->size[0] = higherAng->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(sinOfEnlargement, e_i);
        loop_ub = higherAng->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            sinOfEnlargement->data[e_i] = higherAng->data[e_i];
        }

        nx = static_cast<int32_T>(higherAng->size[0] - 1);
        for (e_i = 0; e_i <= nx; e_i++) {
            sinOfEnlargement->data[e_i] = std::cos(sinOfEnlargement->data[e_i]);
        }

        e_i = varargin_2->size[0];
        varargin_2->size[0] = higherAng->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(varargin_2, e_i);
        loop_ub = higherAng->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            varargin_2->data[e_i] = higherAng->data[e_i];
        }

        for (e_i = 0; e_i <= nx; e_i++) {
            varargin_2->data[e_i] = std::sin(varargin_2->data[e_i]);
        }

        Real2SimGuidance_emxInit_real_T(&higherVec, 2);
        e_i = static_cast<int32_T>(higherVec->size[0] * higherVec->size[1]);
        higherVec->size[0] = sinOfEnlargement->size[0];
        higherVec->size[1] = 3;
        Real2SimGuidance_emxEnsureCapacity_real_T(higherVec, e_i);
        loop_ub = static_cast<int32_T>(higherAng->size[0] - 1);
        loop_ub_0 = sinOfEnlargement->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
            higherVec->data[e_i] = sinOfEnlargement->data[e_i];
        }

        loop_ub_0 = varargin_2->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
            higherVec->data[static_cast<int32_T>(e_i + sinOfEnlargement->size[0])]
                = varargin_2->data[e_i];
        }

        for (e_i = 0; e_i <= loop_ub; e_i++) {
            higherVec->data[static_cast<int32_T>(static_cast<int32_T>(e_i +
                sinOfEnlargement->size[0]) + varargin_2->size[0])] = 0.0;
        }

        Real2SimGuidance_emxInit_boolean_T(&validWeights, 2);
        e_i = static_cast<int32_T>(validWeights->size[0] * validWeights->size[1]);
        validWeights->size[0] = 180;
        validWeights->size[1] = lowerVec->size[0];
        Real2SimGuidance_emxEnsureCapacity_boolean_T(validWeights, e_i);
        loop_ub = static_cast<int32_T>(static_cast<int32_T>(180 * lowerVec->
            size[0]) - 1);
        for (e_i = 0; e_i <= loop_ub; e_i++) {
            validWeights->data[e_i] = true;
        }

        Real2SimGuidance_emxInit_real_T(&lh, 2);
        Real2SimGuidance_cross(lowerVec, higherVec, lh);
        for (e_i = 0; e_i < 180; e_i++) {
            b_x[e_i] = obj->AngularSectorMidPoints[e_i];
            b_x[e_i] = std::cos(b_x[e_i]);
            b_x_0[e_i] = obj->AngularSectorMidPoints[e_i];
            b_x_0[e_i] = std::sin(b_x_0[e_i]);
            localDW->kalpha[e_i] = b_x[e_i];
            localDW->kalpha[static_cast<int32_T>(e_i + 180)] = b_x_0[e_i];
            localDW->kalpha[static_cast<int32_T>(e_i + 360)] = 0.0;
        }

        loop_ub = lh->size[0];
        Real2SimGuidance_emxInit_real_T(&kalphaVec, 2);
        Real2SimGuidance_emxInit_real_T(&lk, 2);
        Real2SimGuidance_emxInit_real_T(&kh, 2);
        for (nx = 0; nx < 180; nx++) {
            kalpha[0] = localDW->kalpha[nx];
            kalpha[1] = localDW->kalpha[static_cast<int32_T>(nx + 180)];
            kalpha[2] = localDW->kalpha[static_cast<int32_T>(nx + 360)];
            Real2SimGuidance_repmat_c(kalpha, static_cast<real_T>(lowerVec->
                size[0]), kalphaVec);
            Real2SimGuidance_cross(lowerVec, kalphaVec, lk);
            Real2SimGuidance_cross(kalphaVec, higherVec, kh);
            loop_ub_0 = lk->size[0];
            e_i = lowerAng->size[0];
            lowerAng->size[0] = lk->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(lowerAng, e_i);
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
                obj_1 = lk->data[static_cast<int32_T>(static_cast<int32_T>
                    (lk->size[0] << 1) + e_i)];
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (obj_1)) ^ 1))) {
                    if (obj_1 < 0.0) {
                        obj_1 = -1.0;
                    } else {
                        obj_1 = static_cast<real_T>(obj_1 > 0.0);
                    }
                }

                lowerAng->data[e_i] = obj_1;
            }

            loop_ub_0 = kh->size[0];
            e_i = higherAng->size[0];
            higherAng->size[0] = kh->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(higherAng, e_i);
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
                obj_1 = kh->data[static_cast<int32_T>(static_cast<int32_T>
                    (kh->size[0] << 1) + e_i)];
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (obj_1)) ^ 1))) {
                    if (obj_1 < 0.0) {
                        obj_1 = -1.0;
                    } else {
                        obj_1 = static_cast<real_T>(obj_1 > 0.0);
                    }
                }

                higherAng->data[e_i] = obj_1;
            }

            e_i = sinOfEnlargement->size[0];
            sinOfEnlargement->size[0] = lh->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(sinOfEnlargement, e_i);
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
                obj_1 = lh->data[static_cast<int32_T>(static_cast<int32_T>
                    (lh->size[0] << 1) + e_i)];
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (obj_1)) ^ 1))) {
                    if (obj_1 < 0.0) {
                        obj_1 = -1.0;
                    } else {
                        obj_1 = static_cast<real_T>(obj_1 > 0.0);
                    }
                }

                sinOfEnlargement->data[e_i] = obj_1;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(((lowerAng->size[0] ==
                    1 ? higherAng->size[0] : lowerAng->size[0]) ==
                    sinOfEnlargement->size[0]) & (lowerAng->size[0] ==
                    higherAng->size[0])))) {
                e_i = varargin_2->size[0];
                varargin_2->size[0] = lowerAng->size[0];
                Real2SimGuidance_emxEnsureCapacity_real_T(varargin_2, e_i);
                loop_ub_0 = lowerAng->size[0];
                for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++)
                {
                    varargin_2->data[e_i] = (lowerAng->data[e_i] +
                        higherAng->data[e_i]) + sinOfEnlargement->data[e_i];
                }

                Real2SimGuidance_abs_p(varargin_2, sinOfEnlargement);
            } else {
                Real2SimGuidance_binary_expand_op_puhaq(sinOfEnlargement,
                    lowerAng, higherAng);
            }

            loop_ub_0 = validWeights->size[1];
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
                validWeights->data[static_cast<int32_T>(nx + static_cast<int32_T>
                    (180 * e_i))] = (sinOfEnlargement->data[e_i] > 1.0);
            }
        }

        Real2SimGuidance_emxFree_real_T(&varargin_2);
        Real2SimGuidance_emxFree_real_T(&kh);
        Real2SimGuidance_emxFree_real_T(&lk);
        Real2SimGuidance_emxFree_real_T(&kalphaVec);
        Real2SimGuidance_emxFree_real_T(&lh);
        Real2SimGuidance_emxFree_real_T(&higherVec);
        Real2SimGuidance_emxFree_real_T(&lowerVec);
        loop_ub = validWeights->size[1];
        for (e_i = 0; e_i < 180; e_i++) {
            obj->PolarObstacleDensity[e_i] = 0.0;
            for (nx = 0; nx <= static_cast<int32_T>(loop_ub - 1); nx++) {
                obj->PolarObstacleDensity[e_i] += static_cast<real_T>
                    (validWeights->data[static_cast<int32_T>(static_cast<int32_T>
                      (180 * nx) + e_i)]) * weightedRanges->data[nx];
            }
        }

        Real2SimGuidance_emxFree_boolean_T(&validWeights);
    }

    Real2SimGuidance_emxFree_real_T(&lowerAng);
    Real2SimGuidance_emxFree_real_T(&higherAng);
    Real2SimGuidance_emxFree_real_T(&sinOfEnlargement);
    Real2SimGuidance_emxFree_real_T(&weightedRanges);
}

static void Real2SimGuidance_VectorFieldHistogramBase_buildBinaryHistogram
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj)
{
    real_T obj_0;
    int32_T b_size_idx_1;
    int32_T trueCount;
    uint8_T b_data[180];
    uint8_T c_data[180];
    boolean_T d[180];
    boolean_T d_0;
    obj_0 = obj->HistogramThresholds[1];
    trueCount = 0;
    for (int32_T i{0}; i < 180; i++) {
        d_0 = (obj->PolarObstacleDensity[i] > obj_0);
        if (d_0) {
            trueCount = static_cast<int32_T>(trueCount + 1);
        }

        d[i] = d_0;
    }

    b_size_idx_1 = trueCount;
    trueCount = 0;
    for (int32_T i{0}; i < 180; i++) {
        if (d[i]) {
            b_data[trueCount] = static_cast<uint8_T>(static_cast<int32_T>(i + 1));
            trueCount = static_cast<int32_T>(trueCount + 1);
        }
    }

    for (int32_T i{0}; i <= static_cast<int32_T>(b_size_idx_1 - 1); i++) {
        obj->BinaryHistogram[static_cast<int32_T>(static_cast<int32_T>(b_data[i])
            - 1)] = true;
    }

    obj_0 = obj->HistogramThresholds[0];
    trueCount = 0;
    for (int32_T i{0}; i < 180; i++) {
        d_0 = (obj->PolarObstacleDensity[i] < obj_0);
        if (d_0) {
            trueCount = static_cast<int32_T>(trueCount + 1);
        }

        d[i] = d_0;
    }

    b_size_idx_1 = trueCount;
    trueCount = 0;
    for (int32_T i{0}; i < 180; i++) {
        if (d[i]) {
            c_data[trueCount] = static_cast<uint8_T>(static_cast<int32_T>(i + 1));
            trueCount = static_cast<int32_T>(trueCount + 1);
        }
    }

    for (int32_T i{0}; i <= static_cast<int32_T>(b_size_idx_1 - 1); i++) {
        obj->BinaryHistogram[static_cast<int32_T>(static_cast<int32_T>(c_data[i])
            - 1)] = false;
    }
}

static void Real2SimGuidance_times_n(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2)
{
    emxArray_real_T_Real2SimGuidance_T *in2_0;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    Real2SimGuidance_emxInit_real_T(&in2_0, 1);
    i = in2_0->size[0];
    in2_0->size[0] = in1->size[0] == 1 ? in2->size[0] : in1->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in2_0, i);
    stride_0_0 = (in2->size[0] != 1);
    stride_1_0 = (in1->size[0] != 1);
    loop_ub = in1->size[0] == 1 ? in2->size[0] : in1->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_0->data[i] = in2->data[static_cast<int32_T>(i * stride_0_0)] *
            in1->data[static_cast<int32_T>(i * stride_1_0)];
    }

    i = in1->size[0];
    in1->size[0] = in2_0->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in1, i);
    loop_ub = in2_0->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1->data[i] = in2_0->data[i];
    }

    Real2SimGuidance_emxFree_real_T(&in2_0);
}

static void Real2SimGuidance_power(const emxArray_real_T_Real2SimGuidance_T *a,
    emxArray_real_T_Real2SimGuidance_T *y)
{
    int32_T b_k;
    int32_T nx;
    b_k = y->size[0];
    y->size[0] = a->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(y, b_k);
    nx = static_cast<int32_T>(a->size[0] - 1);
    for (b_k = 0; b_k <= nx; b_k++) {
        y->data[b_k] = a->data[b_k] * a->data[b_k];
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq5rox
    (emxArray_real_T_Real2SimGuidance_T *in1, const
     emxArray_real_T_Real2SimGuidance_T *in2)
{
    emxArray_real_T_Real2SimGuidance_T *tmp;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    Real2SimGuidance_emxInit_real_T(&tmp, 1);
    i = tmp->size[0];
    tmp->size[0] = in2->size[0] == 1 ? in1->size[0] : in2->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(tmp, i);
    stride_0_0 = (in1->size[0] != 1);
    stride_1_0 = (in2->size[0] != 1);
    loop_ub = in2->size[0] == 1 ? in1->size[0] : in2->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        tmp->data[i] = 0.0 - in1->data[static_cast<int32_T>(i * stride_0_0)] *
            in2->data[static_cast<int32_T>(i * stride_1_0)];
    }

    Real2SimGuidance_power(tmp, in1);
    Real2SimGuidance_emxFree_real_T(&tmp);
}

static void Real2SimGuidance_plus_owq(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2)
{
    emxArray_real_T_Real2SimGuidance_T *in2_0;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    Real2SimGuidance_emxInit_real_T(&in2_0, 1);
    i = in2_0->size[0];
    in2_0->size[0] = in1->size[0] == 1 ? in2->size[0] : in1->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in2_0, i);
    stride_0_0 = (in2->size[0] != 1);
    stride_1_0 = (in1->size[0] != 1);
    loop_ub = in1->size[0] == 1 ? in2->size[0] : in1->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_0->data[i] = in2->data[static_cast<int32_T>(i * stride_0_0)] +
            in1->data[static_cast<int32_T>(i * stride_1_0)];
    }

    i = in1->size[0];
    in1->size[0] = in2_0->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in1, i);
    loop_ub = in2_0->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1->data[i] = in2_0->data[i];
    }

    Real2SimGuidance_emxFree_real_T(&in2_0);
}

static void Real2SimGuidance_plus_ow(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2)
{
    emxArray_real_T_Real2SimGuidance_T *in1_0;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    Real2SimGuidance_emxInit_real_T(&in1_0, 1);
    i = in1_0->size[0];
    in1_0->size[0] = in2->size[0] == 1 ? in1->size[0] : in2->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in1_0, i);
    stride_0_0 = (in1->size[0] != 1);
    stride_1_0 = (in2->size[0] != 1);
    loop_ub = in2->size[0] == 1 ? in1->size[0] : in2->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_0->data[i] = in1->data[static_cast<int32_T>(i * stride_0_0)] +
            in2->data[static_cast<int32_T>(i * stride_1_0)];
    }

    i = in1->size[0];
    in1->size[0] = in1_0->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(in1, i);
    loop_ub = in1_0->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1->data[i] = in1_0->data[i];
    }

    Real2SimGuidance_emxFree_real_T(&in1_0);
}

static void Real2SimGuidance_binary_expand_op_puhaq5ro(boolean_T in1_data[],
    int32_T *in1_size, const emxArray_real_T_Real2SimGuidance_T *in2, const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in3, const
    emxArray_real_T_Real2SimGuidance_T *in4)
{
    real_T in3_0;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    in3_0 = (in3->MinTurningRadius + in3->RobotRadius) + in3->SafetyDistance;
    *in1_size = in4->size[0] == 1 ? in2->size[0] : in4->size[0];
    stride_0_0 = (in2->size[0] != 1);
    stride_1_0 = (in4->size[0] != 1);
    loop_ub = in4->size[0] == 1 ? in2->size[0] : in4->size[0];
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_data[i] = static_cast<boolean_T>(static_cast<int32_T>((in2->data[
            static_cast<int32_T>(i * stride_0_0)] < in3_0) & (in4->data[
            static_cast<int32_T>(i * stride_1_0)] <= 0.0)));
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq5r(boolean_T in1_data[],
    int32_T *in1_size, const emxArray_real_T_Real2SimGuidance_T *in2, const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in3, const
    emxArray_real_T_Real2SimGuidance_T *in4)
{
    real_T in3_0;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    in3_0 = (in3->MinTurningRadius + in3->RobotRadius) + in3->SafetyDistance;
    *in1_size = in4->size[0] == 1 ? in2->size[0] : in4->size[0];
    stride_0_0 = (in2->size[0] != 1);
    stride_1_0 = (in4->size[0] != 1);
    loop_ub = in4->size[0] == 1 ? in2->size[0] : in4->size[0];
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_data[i] = static_cast<boolean_T>(static_cast<int32_T>((in2->data[
            static_cast<int32_T>(i * stride_0_0)] < in3_0) & (in4->data[
            static_cast<int32_T>(i * stride_1_0)] >= 0.0)));
    }
}

static void Real2SimGuidance_VectorFieldHistogramBase_buildMaskedPolarHistogram
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *scan_InternalRanges, const
     emxArray_real_T_Real2SimGuidance_T *scan_InternalAngles,
     DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_real_T_Real2SimGuidance_T *DYj;
    emxArray_real_T_Real2SimGuidance_T *c;
    emxArray_real_T_Real2SimGuidance_T *obj_1;
    emxArray_real_T_Real2SimGuidance_T *validScan_InternalAngles;
    emxArray_real_T_Real2SimGuidance_T *validScan_InternalRanges;
    real_T obj_0[2];
    real_T obj_2;
    real_T phiL_data;
    real_T phiR_data;
    int32_T blockedL_size;
    int32_T idx;
    int32_T ii_data_idx_0_0;
    int32_T ii_size_idx_0;
    int32_T loop_ub;
    int32_T nx;
    uint16_T ii_data_idx_0;
    boolean_T exitg1;
    boolean_T expl_temp;
    Real2SimGuidance_emxInit_real_T(&validScan_InternalRanges, 1);
    Real2SimGuidance_emxInit_real_T(&validScan_InternalAngles, 1);
    Real2SimGuidance_emxInit_real_T(&c, 1);
    obj_0[0] = obj->DistanceLimits[0];
    obj_0[1] = obj->DistanceLimits[1];
    Real2SimGuidance_lidarScan_removeInvalidData(scan_InternalRanges,
        scan_InternalAngles, obj_0, validScan_InternalRanges,
        validScan_InternalAngles, &expl_temp, localDW);
    loop_ub = c->size[0];
    c->size[0] = validScan_InternalAngles->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(c, loop_ub);
    loop_ub = validScan_InternalAngles->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        c->data[idx] = validScan_InternalAngles->data[idx];
    }

    nx = static_cast<int32_T>(validScan_InternalAngles->size[0] - 1);
    for (idx = 0; idx <= nx; idx++) {
        c->data[idx] = std::cos(c->data[idx]);
    }

    Real2SimGuidance_emxInit_real_T(&DYj, 1);
    loop_ub = DYj->size[0];
    DYj->size[0] = validScan_InternalAngles->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(DYj, loop_ub);
    loop_ub = validScan_InternalAngles->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        DYj->data[idx] = validScan_InternalAngles->data[idx];
    }

    for (idx = 0; idx <= nx; idx++) {
        DYj->data[idx] = std::sin(DYj->data[idx]);
    }

    if (validScan_InternalRanges->size[0] == DYj->size[0]) {
        loop_ub = DYj->size[0];
        DYj->size[0] = validScan_InternalRanges->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(DYj, loop_ub);
        loop_ub = validScan_InternalRanges->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            DYj->data[idx] *= validScan_InternalRanges->data[idx];
        }
    } else {
        Real2SimGuidance_times_n(DYj, validScan_InternalRanges);
    }

    Real2SimGuidance_emxInit_real_T(&obj_1, 1);
    if (validScan_InternalRanges->size[0] == c->size[0]) {
        loop_ub = obj_1->size[0];
        obj_1->size[0] = validScan_InternalRanges->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(obj_1, loop_ub);
        loop_ub = validScan_InternalRanges->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            obj_1->data[idx] = 0.0 - validScan_InternalRanges->data[idx] *
                c->data[idx];
        }

        Real2SimGuidance_power(obj_1, validScan_InternalRanges);
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5rox(validScan_InternalRanges, c);
    }

    loop_ub = obj_1->size[0];
    obj_1->size[0] = DYj->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(obj_1, loop_ub);
    loop_ub = DYj->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        obj_1->data[idx] = -obj->MinTurningRadius - DYj->data[idx];
    }

    Real2SimGuidance_power(obj_1, c);
    if (validScan_InternalRanges->size[0] == c->size[0]) {
        loop_ub = c->size[0];
        c->size[0] = validScan_InternalRanges->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(c, loop_ub);
        loop_ub = validScan_InternalRanges->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            c->data[idx] += validScan_InternalRanges->data[idx];
        }
    } else {
        Real2SimGuidance_plus_owq(c, validScan_InternalRanges);
    }

    nx = static_cast<int32_T>(c->size[0] - 1);
    for (idx = 0; idx <= nx; idx++) {
        c->data[idx] = std::sqrt(c->data[idx]);
    }

    loop_ub = obj_1->size[0];
    obj_1->size[0] = DYj->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(obj_1, loop_ub);
    loop_ub = DYj->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        obj_1->data[idx] = obj->MinTurningRadius - DYj->data[idx];
    }

    Real2SimGuidance_power(obj_1, DYj);
    Real2SimGuidance_emxFree_real_T(&obj_1);
    if (validScan_InternalRanges->size[0] == DYj->size[0]) {
        loop_ub = validScan_InternalRanges->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            validScan_InternalRanges->data[idx] += DYj->data[idx];
        }
    } else {
        Real2SimGuidance_plus_ow(validScan_InternalRanges, DYj);
    }

    Real2SimGuidance_emxFree_real_T(&DYj);
    nx = static_cast<int32_T>(validScan_InternalRanges->size[0] - 1);
    for (idx = 0; idx <= nx; idx++) {
        validScan_InternalRanges->data[idx] = std::sqrt
            (validScan_InternalRanges->data[idx]);
    }

    if (c->size[0] == validScan_InternalAngles->size[0]) {
        obj_2 = (obj->MinTurningRadius + obj->RobotRadius) + obj->SafetyDistance;
        nx = c->size[0];
        loop_ub = c->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            localDW->blockedR_data[idx] = static_cast<boolean_T>
                (static_cast<int32_T>((c->data[idx] < obj_2) &
                  (validScan_InternalAngles->data[idx] <= 0.0)));
        }
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5ro(localDW->blockedR_data, &nx,
            c, obj, validScan_InternalAngles);
    }

    Real2SimGuidance_emxFree_real_T(&c);
    if (validScan_InternalRanges->size[0] == validScan_InternalAngles->size[0])
    {
        obj_2 = (obj->MinTurningRadius + obj->RobotRadius) + obj->SafetyDistance;
        blockedL_size = validScan_InternalRanges->size[0];
        loop_ub = validScan_InternalRanges->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            localDW->blockedL_data[idx] = static_cast<boolean_T>
                (static_cast<int32_T>((validScan_InternalRanges->data[idx] <
                   obj_2) & (validScan_InternalAngles->data[idx] >= 0.0)));
        }
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5r(localDW->blockedL_data,
            &blockedL_size, validScan_InternalRanges, obj,
            validScan_InternalAngles);
    }

    Real2SimGuidance_emxFree_real_T(&validScan_InternalRanges);
    loop_ub = (nx >= 1);
    idx = 0;
    ii_size_idx_0 = loop_ub;
    exitg1 = false;
    while ((!exitg1) && (nx > 0)) {
        if (localDW->blockedR_data[static_cast<int32_T>(nx - 1)]) {
            idx = 1;
            ii_data_idx_0 = static_cast<uint16_T>(nx);
            exitg1 = true;
        } else {
            nx = static_cast<int32_T>(nx - 1);
        }
    }

    if (loop_ub == 1) {
        if (idx == 0) {
            ii_size_idx_0 = 0;
        }
    } else {
        ii_size_idx_0 = (idx >= 1);
    }

    if (static_cast<int32_T>(ii_size_idx_0 - 1) >= 0) {
        phiR_data = validScan_InternalAngles->data[static_cast<int32_T>(
            static_cast<int32_T>(ii_data_idx_0) - 1)];
    }

    loop_ub = (blockedL_size >= 1);
    idx = 0;
    nx = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(nx - 1) <= static_cast<int32_T>
                         (blockedL_size - 1))) {
        if (localDW->blockedL_data[static_cast<int32_T>(nx - 1)]) {
            idx = 1;
            ii_data_idx_0_0 = nx;
            exitg1 = true;
        } else {
            nx = static_cast<int32_T>(nx + 1);
        }
    }

    if (loop_ub == 1) {
        if (idx == 0) {
            loop_ub = 0;
        }
    } else {
        loop_ub = (idx >= 1);
    }

    if (static_cast<int32_T>(loop_ub - 1) >= 0) {
        phiL_data = validScan_InternalAngles->data[static_cast<int32_T>
            (ii_data_idx_0_0 - 1)];
    }

    Real2SimGuidance_emxFree_real_T(&validScan_InternalAngles);
    if (ii_size_idx_0 == 0) {
        phiR_data = obj->AngularSectorMidPoints[0];
    } else if (phiR_data <= obj->AngularSectorMidPoints[0]) {
        phiR_data = obj->AngularSectorMidPoints[1];
    }

    if (loop_ub == 0) {
        phiL_data = obj->AngularSectorMidPoints[179];
    } else if (phiL_data >= obj->AngularSectorMidPoints[179]) {
        phiL_data = obj->AngularSectorMidPoints[178];
    }

    for (idx = 0; idx < 180; idx++) {
        obj->MaskedHistogram[idx] = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((obj->AngularSectorMidPoints[idx] < phiR_data) |
             (obj->AngularSectorMidPoints[idx] > phiL_data)))) |
            static_cast<int32_T>(obj->BinaryHistogram[idx])));
    }
}

static void Real2SimGuidance_diff(const real_T x[182], real_T y[181])
{
    real_T work;
    work = x[0];
    for (int32_T m{0}; m < 181; m++) {
        real_T tmp2;
        tmp2 = work;
        work = x[static_cast<int32_T>(m + 1)];
        y[m] = work - tmp2;
    }
}

static boolean_T Real2SimGuidance_any(const real_T x[181])
{
    int32_T b_k;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 181)) {
        if ((x[b_k] == 0.0) || std::isnan(x[b_k])) {
            b_k = static_cast<int32_T>(b_k + 1);
        } else {
            y = true;
            exitg1 = true;
        }
    }

    return y;
}

static void Real2SimGuidance_eml_find(const real_T x[181], int32_T i_data[],
    int32_T i_size[2])
{
    int32_T b_ii;
    int32_T idx;
    boolean_T exitg1;
    idx = 0;
    b_ii = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(b_ii - 1) < 181)) {
        if (x[static_cast<int32_T>(b_ii - 1)] != 0.0) {
            idx = static_cast<int32_T>(idx + 1);
            i_data[static_cast<int32_T>(idx - 1)] = b_ii;
            if (idx >= 181) {
                exitg1 = true;
            } else {
                b_ii = static_cast<int32_T>(b_ii + 1);
            }
        } else {
            b_ii = static_cast<int32_T>(b_ii + 1);
        }
    }

    if (idx < 1) {
        idx = 0;
    }

    i_size[0] = 1;
    i_size[1] = idx;
}

static void Real2SimGuidance_binary_expand_op_puhaq5roxr0o(real_T in1_data[],
    const real_T in3_data[], const int32_T in4[2], int32_T in5)
{
    int32_T loop_ub;
    int32_T stride_0_1;
    stride_0_1 = (in5 != 1);
    loop_ub = in4[1] == 1 ? in5 : in4[1];
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_data[static_cast<int32_T>(1 + static_cast<int32_T>(i << 1))] =
            in3_data[static_cast<int32_T>(static_cast<int32_T>
            (static_cast<int32_T>(i * stride_0_1) << 1) + 1)] - 1.0;
    }
}

static void Real2SimGuidance_diff_f(const real_T x_data[], const int32_T x_size
    [2], real_T y_data[], int32_T y_size[2])
{
    real_T b_y1_data[90];
    int32_T nHigh;
    int32_T r_0;
    if (x_size[1] != 0) {
        nHigh = x_size[1];
        r_0 = 0;
        for (int32_T r{0}; r <= static_cast<int32_T>(nHigh - 1); r++) {
            b_y1_data[r] = x_data[static_cast<int32_T>(r_0 + 1)] - x_data[r_0];
            r_0 = static_cast<int32_T>(r_0 + 2);
        }
    }

    y_size[0] = 1;
    y_size[1] = x_size[1];
    nHigh = static_cast<int32_T>(x_size[1] - 1);
    for (r_0 = 0; r_0 <= nHigh; r_0++) {
        y_data[r_0] = b_y1_data[r_0];
    }
}

static void Real2SimGuidance_wrapToPi_p34(const real_T theta_data[], const
    int32_T theta_size[2], real_T b_theta_data[], int32_T b_theta_size[2])
{
    real_T theta_data_0[273];
    real_T y_data[273];
    int32_T x_size[2];
    int32_T b_k;
    int32_T nx;
    int32_T nx_tmp;
    boolean_T x_data[273];
    b_theta_size[0] = 1;
    b_theta_size[1] = theta_size[1];
    nx_tmp = static_cast<int32_T>(theta_size[1] - 1);
    for (b_k = 0; b_k <= nx_tmp; b_k++) {
        b_theta_data[b_k] = theta_data[b_k];
    }

    for (b_k = 0; b_k <= nx_tmp; b_k++) {
        y_data[b_k] = std::abs(theta_data[b_k]);
    }

    x_size[0] = 1;
    nx = static_cast<int32_T>(theta_size[1] - 1);
    for (b_k = 0; b_k <= nx; b_k++) {
        x_data[b_k] = (y_data[b_k] > 3.1415926535897931);
    }

    b_k = theta_size[1];
    if (Real2SimGuidance_allOrAny_anonFcn1(x_data, &b_k)) {
        for (b_k = 0; b_k <= nx_tmp; b_k++) {
            theta_data_0[b_k] = theta_data[b_k] + 3.1415926535897931;
        }

        nx = static_cast<int32_T>(theta_size[1] - 1);
        for (b_k = 0; b_k <= nx; b_k++) {
            y_data[b_k] = Real2SimGuidance_sxfun_anonFcn2(theta_data_0[b_k]);
        }

        x_size[1] = theta_size[1];
        nx = theta_size[1];
        for (b_k = 0; b_k <= static_cast<int32_T>(nx - 1); b_k++) {
            x_data[b_k] = static_cast<boolean_T>(static_cast<int32_T>
                ((y_data[b_k] == 0.0) & (theta_data_0[b_k] > 0.0)));
        }

        nx = static_cast<int32_T>(x_size[1] - 1);
        for (b_k = 0; b_k <= nx; b_k++) {
            if (x_data[b_k]) {
                y_data[b_k] = 6.2831853071795862;
            }
        }

        b_theta_size[0] = 1;
        b_theta_size[1] = theta_size[1];
        nx = static_cast<int32_T>(theta_size[1] - 1);
        for (b_k = 0; b_k <= nx; b_k++) {
            b_theta_data[b_k] = y_data[b_k] - 3.1415926535897931;
        }
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq5roxr0oy(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], const int32_T in2_size[2],
    const real_T in3_data[], const int32_T in3_size[2])
{
    real_T in2_data_0[90];
    int32_T in2_size_0[2];
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    int32_T stride_2_1;
    in2_size_0[0] = 1;
    in2_size_0[1] = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ?
        in2_size[1] : in3_size[1] == 1 ? in2_size[1] : in3_size[1];
    stride_0_1 = (in2_size[1] != 1);
    stride_1_1 = (in2_size[1] != 1);
    stride_2_1 = (in3_size[1] != 1);
    loop_ub = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in2_size[1] :
        in3_size[1] == 1 ? in2_size[1] : in3_size[1];
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_data_0[i] = in2_data[static_cast<int32_T>(i * stride_0_1)] -
            (in2_data[static_cast<int32_T>(i * stride_1_1)] - in3_data[
             static_cast<int32_T>(i * stride_2_1)]) / 2.0;
    }

    Real2SimGuidance_wrapToPi_p34(in2_data_0, in2_size_0, in1_data, in1_size);
}

static void Real2SimGuidance_bisectAngles(real_T theta1_data[], int32_T
    theta1_size[2], real_T theta2_data[], int32_T theta2_size[2], real_T
    bisect_data[], int32_T bisect_size[2])
{
    real_T tmp_data[273];
    real_T theta1_data_0[90];
    int32_T theta1_size_0[2];
    int32_T tmp_size[2];
    int32_T loop_ub;
    Real2SimGuidance_wrapToPi_p34(theta1_data, theta1_size, tmp_data, tmp_size);
    theta1_size[0] = 1;
    theta1_size[1] = tmp_size[1];
    loop_ub = tmp_size[1];
    for (int32_T theta1_tmp{0}; theta1_tmp <= static_cast<int32_T>(loop_ub - 1);
         theta1_tmp++) {
        theta1_data[theta1_tmp] = tmp_data[theta1_tmp];
    }

    Real2SimGuidance_wrapToPi_p34(theta2_data, theta2_size, tmp_data, tmp_size);
    theta2_size[0] = 1;
    theta2_size[1] = tmp_size[1];
    loop_ub = tmp_size[1];
    for (int32_T theta1_tmp{0}; theta1_tmp <= static_cast<int32_T>(loop_ub - 1);
         theta1_tmp++) {
        theta2_data[theta1_tmp] = tmp_data[theta1_tmp];
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(((theta1_size[1] == 1 ?
            tmp_size[1] : theta1_size[1]) == theta1_size[1]) & (theta1_size[1] ==
           tmp_size[1])))) {
        theta1_size_0[0] = 1;
        theta1_size_0[1] = theta1_size[1];
        loop_ub = theta1_size[1];
        for (int32_T theta1_tmp{0}; theta1_tmp <= static_cast<int32_T>(loop_ub -
              1); theta1_tmp++) {
            real_T theta1;
            theta1 = theta1_data[theta1_tmp];
            theta1_data_0[theta1_tmp] = theta1 - (theta1 -
                theta2_data[theta1_tmp]) / 2.0;
        }

        Real2SimGuidance_wrapToPi_p34(theta1_data_0, theta1_size_0, tmp_data,
            tmp_size);
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5roxr0oy(tmp_data, tmp_size,
            theta1_data, theta1_size, theta2_data, theta2_size);
    }

    bisect_size[0] = 1;
    bisect_size[1] = tmp_size[1];
    loop_ub = tmp_size[1];
    for (int32_T theta1_tmp{0}; theta1_tmp <= static_cast<int32_T>(loop_ub - 1);
         theta1_tmp++) {
        bisect_data[theta1_tmp] = tmp_data[theta1_tmp];
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq5roxr(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], const int32_T in4_data[],
    const int32_T in4_size[2], const real_T in5[2], const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in6, const
    real_T in7[2])
{
    real_T in2_data_0[90];
    real_T in2_data_1[90];
    int32_T in2_size_idx_1;
    int32_T in2_size_idx_1_0;
    int32_T loop_ub;
    int32_T stride_0_1_0;
    in2_size_idx_1 = static_cast<int32_T>(in5[1]) == 1 ? in4_size[1] :
        static_cast<int32_T>(in5[1]);
    stride_0_1_0 = (in4_size[1] != 1);
    loop_ub = static_cast<int32_T>(in5[1]) == 1 ? in4_size[1] : static_cast<
        int32_T>(in5[1]);
    for (int32_T stride_0_1{0}; stride_0_1 <= static_cast<int32_T>(loop_ub - 1);
         stride_0_1++) {
        in2_data_0[stride_0_1] = in2_data[static_cast<int32_T>
            (static_cast<int32_T>(in4_data[static_cast<int32_T>(stride_0_1 *
               stride_0_1_0)] - 1) << 1)] + in6->NarrowOpeningThreshold / 2.0;
    }

    in2_size_idx_1_0 = static_cast<int32_T>(in7[1]) == 1 ? in4_size[1] :
        static_cast<int32_T>(in7[1]);
    stride_0_1_0 = (in4_size[1] != 1);
    loop_ub = static_cast<int32_T>(in7[1]) == 1 ? in4_size[1] :
        static_cast<int32_T>(in7[1]);
    for (int32_T stride_0_1{0}; stride_0_1 <= static_cast<int32_T>(loop_ub - 1);
         stride_0_1++) {
        in2_data_1[stride_0_1] = in2_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(in4_data
               [static_cast<int32_T>(stride_0_1 * stride_0_1_0)] - 1) << 1) + 1)]
            - in6->NarrowOpeningThreshold / 2.0;
    }

    in1_size[0] = 1;
    in1_size[1] = static_cast<int32_T>(in2_size_idx_1 + in2_size_idx_1_0);
    for (int32_T stride_0_1{0}; stride_0_1 <= static_cast<int32_T>
            (in2_size_idx_1 - 1); stride_0_1++) {
        in1_data[stride_0_1] = in2_data_0[stride_0_1];
    }

    for (int32_T stride_0_1{0}; stride_0_1 <= static_cast<int32_T>
            (in2_size_idx_1_0 - 1); stride_0_1++) {
        in1_data[static_cast<int32_T>(stride_0_1 + in2_size_idx_1)] =
            in2_data_1[stride_0_1];
    }
}

static void Real2SimGuidance_bsxfun(const real_T a[180], const real_T b_data[],
    const int32_T *b_size, emxArray_real_T_Real2SimGuidance_T *c)
{
    int32_T k;
    k = static_cast<int32_T>(c->size[0] * c->size[1]);
    c->size[0] = *b_size;
    c->size[1] = 180;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    for (k = 0; k < 180; k++) {
        int32_T d;
        d = c->size[0];
        for (int32_T k_0{0}; k_0 <= static_cast<int32_T>(d - 1); k_0++) {
            c->data[static_cast<int32_T>(k_0 + static_cast<int32_T>(c->size[0] *
                k))] = Real2SimGuidance_wrapToPi_p(b_data[k_0] - a[k]);
        }
    }
}

static void Real2SimGuidance_minimum_p(const emxArray_real_T_Real2SimGuidance_T *
    x, real_T ex_data[], int32_T *ex_size)
{
    int32_T m;
    m = static_cast<int32_T>(x->size[0] - 1);
    *ex_size = x->size[0];
    for (int32_T b_i{0}; b_i <= m; b_i++) {
        ex_data[b_i] = x->data[b_i];
    }

    for (int32_T b_i{0}; b_i < 179; b_i++) {
        for (int32_T c_i{0}; c_i <= m; c_i++) {
            real_T b_tmp;
            real_T ex;
            boolean_T p;
            ex = ex_data[c_i];
            b_tmp = x->data[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int32_T>(b_i + 1) * x->size[0]) + c_i)];
            if (std::isnan(b_tmp)) {
                p = false;
            } else if (std::isnan(ex)) {
                p = true;
            } else {
                p = (ex > b_tmp);
            }

            if (p) {
                ex = b_tmp;
            }

            ex_data[c_i] = ex;
        }
    }
}

static void Real2SimGuidance_bsxfun_p(const emxArray_real_T_Real2SimGuidance_T
    *a, const real_T b_data[], const int32_T *b_size,
    emxArray_real_T_Real2SimGuidance_T *c)
{
    int32_T k;
    if (a->size[0] == *b_size) {
        k = static_cast<int32_T>(c->size[0] * c->size[1]);
        c->size[0] = a->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    } else if (*b_size <= a->size[0]) {
        k = static_cast<int32_T>(c->size[0] * c->size[1]);
        c->size[0] = *b_size;
        Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    } else {
        k = static_cast<int32_T>(c->size[0] * c->size[1]);
        c->size[0] = a->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    }

    k = static_cast<int32_T>(c->size[0] * c->size[1]);
    c->size[1] = 180;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    for (k = 0; k < 180; k++) {
        int32_T d;
        d = c->size[0];
        for (int32_T k_0{0}; k_0 <= static_cast<int32_T>(d - 1); k_0++) {
            c->data[static_cast<int32_T>(k_0 + static_cast<int32_T>(c->size[0] *
                k))] = a->data[static_cast<int32_T>(static_cast<int32_T>(a->
                size[0] * k) + k_0)] - b_data[k_0];
        }
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq5roxr0oylw(real_T in1_data[],
    int32_T in1_size[2], const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in2, const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], real_T in5)
{
    real_T in2_data[273];
    int32_T in2_size_idx_1;
    int32_T loop_ub;
    int32_T stride_0_1_0;
    int32_T stride_1_1;
    int32_T stride_2_1;
    in2_size_idx_1 = in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] :
        in3_size[1] : in4_size[1];
    stride_0_1_0 = (in1_size[1] != 1);
    stride_1_1 = (in3_size[1] != 1);
    stride_2_1 = (in4_size[1] != 1);
    loop_ub = in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] : in3_size[1] :
        in4_size[1];
    for (int32_T stride_0_1{0}; stride_0_1 <= static_cast<int32_T>(loop_ub - 1);
         stride_0_1++) {
        in2_data[stride_0_1] = ((in1_data[static_cast<int32_T>(stride_0_1 *
            stride_0_1_0)] * in2->TargetDirectionWeight + in3_data
            [static_cast<int32_T>(stride_0_1 * stride_1_1)] *
            in2->CurrentDirectionWeight) + in4_data[static_cast<int32_T>
                                (stride_0_1 * stride_2_1)] *
                                in2->PreviousDirectionWeight) / 3.0 * in5;
    }

    in1_size[0] = 1;
    in1_size[1] = in2_size_idx_1;
    for (int32_T stride_0_1{0}; stride_0_1 <= static_cast<int32_T>
            (in2_size_idx_1 - 1); stride_0_1++) {
        in1_data[stride_0_1] = in2_data[stride_0_1];
    }
}

static void Real2SimGuidance_VectorFieldHistogramBase_computeCost(const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
    real_T c_data[], const int32_T c_size[2], real_T targetDir, real_T prevDir,
    real_T cost_data[], int32_T cost_size[2])
{
    real_T delta_data[273];
    real_T prevDir_data[273];
    real_T targetDir_data[273];
    real_T totalWeight;
    int32_T delta_size[2];
    int32_T prevDir_size[2];
    int32_T targetDir_size[2];
    int32_T nx;
    totalWeight = (obj->TargetDirectionWeight + obj->CurrentDirectionWeight) +
        obj->PreviousDirectionWeight;
    nx = c_size[1];
    targetDir_size[0] = 1;
    targetDir_size[1] = c_size[1];
    for (int32_T b_k{0}; b_k <= static_cast<int32_T>(nx - 1); b_k++) {
        targetDir_data[b_k] = targetDir - c_data[b_k];
    }

    Real2SimGuidance_wrapToPi_p34(targetDir_data, targetDir_size, delta_data,
        delta_size);
    nx = static_cast<int32_T>(delta_size[1] - 1);
    cost_size[0] = 1;
    cost_size[1] = delta_size[1];
    for (int32_T b_k{0}; b_k <= nx; b_k++) {
        cost_data[b_k] = std::abs(delta_data[b_k]);
    }

    nx = c_size[1];
    targetDir_size[0] = 1;
    targetDir_size[1] = c_size[1];
    for (int32_T b_k{0}; b_k <= static_cast<int32_T>(nx - 1); b_k++) {
        targetDir_data[b_k] = 0.0 - c_data[b_k];
    }

    Real2SimGuidance_wrapToPi_p34(targetDir_data, targetDir_size, delta_data,
        delta_size);
    nx = static_cast<int32_T>(delta_size[1] - 1);
    targetDir_size[0] = 1;
    targetDir_size[1] = delta_size[1];
    for (int32_T b_k{0}; b_k <= nx; b_k++) {
        targetDir_data[b_k] = std::abs(delta_data[b_k]);
    }

    nx = c_size[1];
    prevDir_size[0] = 1;
    prevDir_size[1] = c_size[1];
    for (int32_T b_k{0}; b_k <= static_cast<int32_T>(nx - 1); b_k++) {
        prevDir_data[b_k] = prevDir - c_data[b_k];
    }

    Real2SimGuidance_wrapToPi_p34(prevDir_data, prevDir_size, delta_data,
        delta_size);
    nx = static_cast<int32_T>(delta_size[1] - 1);
    prevDir_size[0] = 1;
    prevDir_size[1] = delta_size[1];
    for (int32_T b_k{0}; b_k <= nx; b_k++) {
        prevDir_data[b_k] = std::abs(delta_data[b_k]);
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(((cost_size[1] == 1 ?
            targetDir_size[1] : cost_size[1]) == delta_size[1]) & (cost_size[1] ==
           targetDir_size[1])))) {
        nx = static_cast<int32_T>(cost_size[1] - 1);
        cost_size[0] = 1;
        for (int32_T b_k{0}; b_k <= nx; b_k++) {
            cost_data[b_k] = ((obj->TargetDirectionWeight * cost_data[b_k] +
                               obj->CurrentDirectionWeight * targetDir_data[b_k])
                              + obj->PreviousDirectionWeight * prevDir_data[b_k])
                / 3.0 * totalWeight;
        }
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5roxr0oylw(cost_data, cost_size,
            obj, targetDir_data, targetDir_size, prevDir_data, prevDir_size,
            totalWeight);
    }
}

static real_T Real2SimGuidance_minimum_p0(const real_T x_data[], const int32_T
    x_size[2])
{
    real_T ex;
    int32_T last;
    last = x_size[1];
    if (x_size[1] <= 2) {
        if (x_size[1] == 1) {
            ex = x_data[0];
        } else {
            real_T tmp;
            tmp = x_data[static_cast<int32_T>(x_size[1] - 1)];
            ex = x_data[0];
            if ((ex > tmp) || (std::isnan(x_data[0]) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan(tmp)) ^
                    1))))) {
                ex = tmp;
            }
        }
    } else {
        int32_T b_idx;
        int32_T k;
        ex = x_data[0];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(ex)) ^ 1))) {
            b_idx = 1;
        } else {
            boolean_T exitg1;
            b_idx = 0;
            k = 2;
            exitg1 = false;
            while ((!exitg1) && (k <= last)) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (x_data[static_cast<int32_T>(k - 1)])) ^ 1))) {
                    b_idx = k;
                    exitg1 = true;
                } else {
                    k = static_cast<int32_T>(k + 1);
                }
            }
        }

        if (b_idx == 0) {
        } else {
            ex = x_data[static_cast<int32_T>(b_idx - 1)];
            for (k = static_cast<int32_T>(b_idx + 1); k <= last; k++) {
                real_T tmp;
                tmp = x_data[static_cast<int32_T>(k - 1)];
                if (ex > tmp) {
                    ex = tmp;
                }
            }
        }
    }

    return ex;
}

static boolean_T Real2SimGuidance_any_m(const boolean_T x_data[], const int32_T
    x_size[2])
{
    int32_T ix;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    ix = 0;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(ix + 1) <= x_size[1])) {
        if (x_data[ix]) {
            y = true;
            exitg1 = true;
        } else {
            ix = static_cast<int32_T>(ix + 1);
        }
    }

    return y;
}

static real_T Real2SimGuidance_VectorFieldHistogramBase_selectHeadingDirection
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, real_T
     targetDir, DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_real_T_Real2SimGuidance_T *candToSectDiff;
    emxArray_real_T_Real2SimGuidance_T *x;
    real_T cDiff_data[273];
    real_T candidateDirections_data[273];
    real_T candidateDirs_data[273];
    real_T tmp[182];
    real_T changes[181];
    real_T angles_data[180];
    real_T nonNarrowDirs_data[180];
    real_T sectors_data[180];
    real_T angles_data_0[90];
    real_T angles_data_1[90];
    real_T sectorSizes_data[90];
    real_T eb[2];
    real_T l[2];
    real_T thetaSteer;
    int32_T tmp_data[181];
    int32_T vb_data[180];
    int32_T ub_data[90];
    int32_T angles_size[2];
    int32_T angles_size_0[2];
    int32_T candidateDirections_size[2];
    int32_T nonNarrowDirs_size[2];
    int32_T obj_size[2];
    int32_T sectors_size[2];
    int32_T sz[2];
    int32_T tmp_size[2];
    int32_T ub_size[2];
    int32_T calclen;
    int32_T trueCount;
    int16_T wb_data[273];
    int8_T pb_data[90];
    boolean_T freeDirs_data[273];
    boolean_T obj_data[180];
    boolean_T narrowIdx_data[90];
    tmp[0] = 0.0;
    for (trueCount = 0; trueCount < 180; trueCount++) {
        tmp[static_cast<int32_T>(trueCount + 1)] = static_cast<real_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(obj->MaskedHistogram[trueCount]) ^ 1))));
    }

    tmp[181] = 0.0;
    Real2SimGuidance_diff(tmp, changes);
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (Real2SimGuidance_any(changes)) ^ 1))) {
        thetaSteer = (rtNaN);
        obj->PreviousDirection = (rtNaN);
    } else {
        real_T cVal;
        int32_T h;
        int32_T nx;
        int32_T sb_size_idx_1;
        Real2SimGuidance_eml_find(changes, tmp_data, tmp_size);
        nx = tmp_size[1];
        for (trueCount = 0; trueCount <= static_cast<int32_T>(nx - 1); trueCount
                ++) {
            changes[trueCount] = static_cast<real_T>(tmp_data[trueCount]);
        }

        sz[1] = static_cast<int32_T>(tmp_size[1] / 2);
        sectors_size[0] = 2;
        sectors_size[1] = static_cast<int32_T>(tmp_size[1] / 2);
        nx = static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
            (tmp_size[1] / 2) << 1) - 1);
        for (trueCount = 0; trueCount <= nx; trueCount++) {
            sectors_data[trueCount] = changes[trueCount];
        }

        if (static_cast<int32_T>(tmp_size[1] / 2) < 1) {
            calclen = -1;
        } else {
            calclen = static_cast<int32_T>(sz[1] - 1);
        }

        if (static_cast<int32_T>(calclen + 1) == sz[1]) {
            for (trueCount = 0; trueCount <= calclen; trueCount++) {
                nx = static_cast<int32_T>(static_cast<int32_T>(trueCount << 1) +
                    1);
                sectors_data[nx] = static_cast<real_T>(static_cast<int32_T>
                    (changes[nx])) - 1.0;
            }
        } else {
            Real2SimGuidance_binary_expand_op_puhaq5roxr0o(sectors_data, changes,
                sz, static_cast<int32_T>(calclen + 1));
        }

        nx = static_cast<int32_T>(static_cast<int32_T>(sectors_size[1] << 1) - 1);
        for (trueCount = 0; trueCount <= nx; trueCount++) {
            angles_data[trueCount] = 0.0;
        }

        if (sectors_size[1] < 1) {
            calclen = -1;
        } else {
            calclen = static_cast<int32_T>(sectors_size[1] - 1);
        }

        for (trueCount = 0; trueCount <= calclen; trueCount++) {
            nx = static_cast<int32_T>(trueCount << 1);
            angles_data[nx] = obj->AngularSectorMidPoints[static_cast<int32_T>(
                static_cast<int32_T>(sectors_data[nx]) - 1)];
        }

        if (sectors_size[1] < 1) {
            calclen = -1;
        } else {
            calclen = static_cast<int32_T>(sectors_size[1] - 1);
        }

        for (trueCount = 0; trueCount <= calclen; trueCount++) {
            nx = static_cast<int32_T>(static_cast<int32_T>(trueCount << 1) + 1);
            angles_data[nx] = obj->AngularSectorMidPoints[static_cast<int32_T>(
                static_cast<int32_T>(sectors_data[nx]) - 1)];
        }

        Real2SimGuidance_diff_f(sectors_data, sectors_size, sectorSizes_data,
                                tmp_size);
        nx = static_cast<int32_T>(tmp_size[1] - 1);
        for (trueCount = 0; trueCount <= nx; trueCount++) {
            sectorSizes_data[trueCount] *= obj->AngularDifference;
        }

        nx = tmp_size[1];
        for (trueCount = 0; trueCount <= static_cast<int32_T>(nx - 1); trueCount
                ++) {
            narrowIdx_data[trueCount] = (sectorSizes_data[trueCount] <
                obj->NarrowOpeningThreshold);
        }

        h = static_cast<int32_T>(tmp_size[1] - 1);
        trueCount = 0;
        for (nx = 0; nx <= h; nx++) {
            if (narrowIdx_data[nx]) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        calclen = trueCount;
        trueCount = 0;
        for (nx = 0; nx <= h; nx++) {
            if (narrowIdx_data[nx]) {
                pb_data[trueCount] = static_cast<int8_T>(static_cast<int32_T>(nx
                    + 1));
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        angles_size[0] = 1;
        angles_size[1] = calclen;
        for (trueCount = 0; trueCount <= static_cast<int32_T>(calclen - 1);
                trueCount++) {
            angles_data_0[trueCount] = angles_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(pb_data[trueCount]) -
                1) << 1)];
        }

        angles_size_0[0] = 1;
        angles_size_0[1] = calclen;
        for (trueCount = 0; trueCount <= static_cast<int32_T>(calclen - 1);
                trueCount++) {
            angles_data_1[trueCount] = angles_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
                (pb_data[trueCount]) - 1) << 1) + 1)];
        }

        Real2SimGuidance_bisectAngles(angles_data_0, angles_size, angles_data_1,
            angles_size_0, sectorSizes_data, tmp_size);
        trueCount = 0;
        for (nx = 0; nx <= h; nx++) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (narrowIdx_data[nx]) ^ 1))) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        calclen = trueCount;
        l[0] = 1.0;
        l[1] = static_cast<real_T>(trueCount);
        trueCount = 0;
        for (nx = 0; nx <= h; nx++) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (narrowIdx_data[nx]) ^ 1))) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        sb_size_idx_1 = trueCount;
        eb[0] = 1.0;
        eb[1] = static_cast<real_T>(trueCount);
        trueCount = 0;
        for (nx = 0; nx <= h; nx++) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (narrowIdx_data[nx]) ^ 1))) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        ub_size[0] = 1;
        ub_size[1] = trueCount;
        trueCount = 0;
        for (nx = 0; nx <= h; nx++) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (narrowIdx_data[nx]) ^ 1))) {
                ub_data[trueCount] = static_cast<int32_T>(nx + 1);
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((ub_size[1] == calclen)
                & (ub_size[1] == sb_size_idx_1)))) {
            nonNarrowDirs_size[1] = static_cast<int32_T>(ub_size[1] + ub_size[1]);
            nx = ub_size[1];
            for (trueCount = 0; trueCount <= static_cast<int32_T>(nx - 1);
                    trueCount++) {
                nonNarrowDirs_data[trueCount] = angles_data[static_cast<int32_T>
                    (static_cast<int32_T>(ub_data[trueCount] - 1) << 1)] +
                    obj->NarrowOpeningThreshold / 2.0;
            }

            nx = ub_size[1];
            for (trueCount = 0; trueCount <= static_cast<int32_T>(nx - 1);
                    trueCount++) {
                nonNarrowDirs_data[static_cast<int32_T>(trueCount + ub_size[1])]
                    = angles_data[static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(ub_data[trueCount] - 1) << 1) + 1)] -
                    obj->NarrowOpeningThreshold / 2.0;
            }
        } else {
            Real2SimGuidance_binary_expand_op_puhaq5roxr(nonNarrowDirs_data,
                nonNarrowDirs_size, angles_data, ub_data, ub_size, l, obj, eb);
        }

        if (std::isnan(obj->PreviousDirection)) {
            obj->PreviousDirection = 0.0;
        }

        nx = nonNarrowDirs_size[1];
        calclen = tmp_size[1];
        sb_size_idx_1 = static_cast<int32_T>(nonNarrowDirs_size[1] + tmp_size[1]);
        for (trueCount = 0; trueCount <= static_cast<int32_T>(nx - 1); trueCount
                ++) {
            candidateDirs_data[trueCount] = nonNarrowDirs_data[trueCount];
        }

        for (trueCount = 0; trueCount <= static_cast<int32_T>(calclen - 1);
                trueCount++) {
            candidateDirs_data[static_cast<int32_T>(trueCount + nx)] =
                sectorSizes_data[trueCount];
        }

        candidateDirs_data[sb_size_idx_1] = targetDir;
        candidateDirs_data[static_cast<int32_T>(sb_size_idx_1 + 1)] = 0.0;
        candidateDirs_data[static_cast<int32_T>(sb_size_idx_1 + 2)] =
            obj->PreviousDirection;
        calclen = static_cast<int32_T>(sb_size_idx_1 + 3);
        nx = static_cast<int32_T>(sb_size_idx_1 + 3);
        for (trueCount = 0; trueCount <= static_cast<int32_T>(nx - 1); trueCount
                ++) {
            cDiff_data[trueCount] = candidateDirs_data[trueCount];
        }

        Real2SimGuidance_emxInit_real_T(&candToSectDiff, 2);
        Real2SimGuidance_emxInit_real_T(&x, 2);
        Real2SimGuidance_bsxfun(obj->AngularSectorMidPoints, cDiff_data,
                                &calclen, x);
        nx = static_cast<int32_T>(static_cast<int32_T>(x->size[0] * 180) - 1);
        trueCount = static_cast<int32_T>(candToSectDiff->size[0] *
            candToSectDiff->size[1]);
        candToSectDiff->size[0] = x->size[0];
        candToSectDiff->size[1] = 180;
        Real2SimGuidance_emxEnsureCapacity_real_T(candToSectDiff, trueCount);
        for (h = 0; h <= nx; h++) {
            candToSectDiff->data[h] = std::abs(x->data[h]);
        }

        Real2SimGuidance_minimum_p(candToSectDiff, cDiff_data, &calclen);
        Real2SimGuidance_bsxfun_p(candToSectDiff, cDiff_data, &calclen, x);
        h = x->size[0];
        nx = static_cast<int32_T>(x->size[0] * 180);
        Real2SimGuidance_emxFree_real_T(&candToSectDiff);
        for (trueCount = 0; trueCount <= static_cast<int32_T>(nx - 1); trueCount
                ++) {
            localDW->nearIdx_data[trueCount] = (x->data[trueCount] <
                1.4901161193847656E-8);
        }

        Real2SimGuidance_emxFree_real_T(&x);
        sb_size_idx_1 = static_cast<int32_T>(h - 1);
        for (trueCount = 0; trueCount <= sb_size_idx_1; trueCount++) {
            freeDirs_data[trueCount] = true;
        }

        for (calclen = 0; calclen <= sb_size_idx_1; calclen++) {
            int32_T vb_size_idx_1;
            nx = 0;
            for (trueCount = 0; trueCount < 180; trueCount++) {
                if (localDW->nearIdx_data[static_cast<int32_T>
                        (static_cast<int32_T>(h * trueCount) + calclen)]) {
                    nx = static_cast<int32_T>(nx + 1);
                }
            }

            vb_size_idx_1 = nx;
            nx = 0;
            for (trueCount = 0; trueCount < 180; trueCount++) {
                if (localDW->nearIdx_data[static_cast<int32_T>
                        (static_cast<int32_T>(h * trueCount) + calclen)]) {
                    vb_data[nx] = static_cast<int32_T>(trueCount + 1);
                    nx = static_cast<int32_T>(nx + 1);
                }
            }

            obj_size[0] = 1;
            obj_size[1] = vb_size_idx_1;
            for (trueCount = 0; trueCount <= static_cast<int32_T>(vb_size_idx_1
                    - 1); trueCount++) {
                obj_data[trueCount] = obj->MaskedHistogram[static_cast<int32_T>
                    (vb_data[trueCount] - 1)];
            }

            freeDirs_data[calclen] = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(Real2SimGuidance_any_m(obj_data, obj_size))
                 ^ 1));
        }

        h = static_cast<int32_T>(h - 1);
        nx = 0;
        for (calclen = 0; calclen <= h; calclen++) {
            if (freeDirs_data[calclen]) {
                nx = static_cast<int32_T>(nx + 1);
            }
        }

        candidateDirections_size[0] = 1;
        candidateDirections_size[1] = nx;
        trueCount = 0;
        for (nx = 0; nx <= h; nx++) {
            if (freeDirs_data[nx]) {
                candidateDirections_data[trueCount] = candidateDirs_data[nx];
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        Real2SimGuidance_VectorFieldHistogramBase_computeCost(obj,
            candidateDirections_data, candidateDirections_size, targetDir,
            obj->PreviousDirection, candidateDirs_data, sectors_size);
        cVal = Real2SimGuidance_minimum_p0(candidateDirs_data, sectors_size);
        nx = static_cast<int32_T>(sectors_size[1] - 1);
        for (trueCount = 0; trueCount <= nx; trueCount++) {
            cDiff_data[trueCount] = candidateDirs_data[trueCount] - cVal;
        }

        calclen = static_cast<int32_T>(sectors_size[1] - 1);
        nx = 0;
        for (h = 0; h <= calclen; h++) {
            if (cDiff_data[h] < 1.4901161193847656E-8) {
                nx = static_cast<int32_T>(nx + 1);
            }
        }

        sb_size_idx_1 = nx;
        nx = 0;
        for (h = 0; h <= calclen; h++) {
            if (cDiff_data[h] < 1.4901161193847656E-8) {
                wb_data[nx] = static_cast<int16_T>(static_cast<int32_T>(h + 1));
                nx = static_cast<int32_T>(nx + 1);
            }
        }

        sectors_size[0] = 1;
        sectors_size[1] = sb_size_idx_1;
        for (trueCount = 0; trueCount <= static_cast<int32_T>(sb_size_idx_1 - 1);
             trueCount++) {
            candidateDirs_data[trueCount] = candidateDirections_data[
                static_cast<int32_T>(static_cast<int32_T>(wb_data[trueCount]) -
                1)];
        }

        thetaSteer = Real2SimGuidance_minimum_p0(candidateDirs_data,
            sectors_size);
        obj->PreviousDirection = thetaSteer;
    }

    return thetaSteer;
}

static real_T Real2SimGuidance_VectorFieldHistogramBase_stepImpl
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2, real_T varargin_3,
     DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_real_T_Real2SimGuidance_T *scan_InternalAngles;
    emxArray_real_T_Real2SimGuidance_T *scan_InternalRanges;
    real_T steeringDir;
    real_T target;
    boolean_T expl_temp;
    Real2SimGuidance_emxInit_real_T(&scan_InternalRanges, 1);
    Real2SimGuidance_emxInit_real_T(&scan_InternalAngles, 1);
    Real2SimGuidance_lidarScan_lidarScan(varargin_1, varargin_2,
        scan_InternalRanges, scan_InternalAngles, &expl_temp, localDW);
    target = varargin_3;
    if (std::abs(varargin_3) > 3.1415926535897931) {
        target = Real2SimGuidance_wrapToPi_p(varargin_3);
    }

    Real2SimGuidance_VectorFieldHistogramBase_buildPolarObstacleDensity(obj,
        scan_InternalRanges, scan_InternalAngles, localDW);
    Real2SimGuidance_VectorFieldHistogramBase_buildBinaryHistogram(obj);
    Real2SimGuidance_VectorFieldHistogramBase_buildMaskedPolarHistogram(obj,
        scan_InternalRanges, scan_InternalAngles, localDW);
    steeringDir =
        Real2SimGuidance_VectorFieldHistogramBase_selectHeadingDirection(obj,
        target, localDW);
    Real2SimGuidance_emxFree_real_T(&scan_InternalAngles);
    Real2SimGuidance_emxFree_real_T(&scan_InternalRanges);
    return steeringDir;
}

static real_T Real2SimGuidance_SystemCore_step
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
     emxArray_real_T_Real2SimGuidance_T *varargin_1, const
     emxArray_real_T_Real2SimGuidance_T *varargin_2, real_T varargin_3,
     DW_Real2SimGuidance_f_T *localDW)
{
    real_T varargout_1;
    Real2SimGuidance_SystemCore_systemblock_prestep(obj, varargin_1, varargin_2);
    Real2SimGuidance_SystemCore_detectInputSizeChange(obj, varargin_1,
        varargin_2);
    varargout_1 = Real2SimGuidance_VectorFieldHistogramBase_stepImpl(obj,
        varargin_1, varargin_2, varargin_3, localDW);
    return varargout_1;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static boolean_T Real2SimGuidance_strcmp(const
    emxArray_char_T_Real2SimGuidance_T *a)
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

    static const char_T d[3]{ 'L', 'A', 'P' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    Real2SimGuidance_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 3) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 3) {
                if (c[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(aTmp->
                        data[loop_ub])) & 127)] != c[static_cast<int32_T>
                        (d[loop_ub])]) {
                    exitg1 = 1;
                } else {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            } else {
                b_bool = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    }

    Real2SimGuidance_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static real_T Real2SimGuidance_mean(const emxArray_real_T_Real2SimGuidance_T *x)
{
    real_T b_y;
    if (x->size[0] == 0) {
        b_y = 0.0;
    } else {
        int32_T firstBlockLength;
        int32_T lastBlockLength;
        int32_T nblocks;
        int32_T xblockoffset;
        if (x->size[0] <= 1024) {
            firstBlockLength = x->size[0];
            lastBlockLength = 0;
            nblocks = 1;
        } else {
            firstBlockLength = 1024;
            nblocks = static_cast<int32_T>(x->size[0] / 1024);
            lastBlockLength = static_cast<int32_T>(x->size[0] -
                static_cast<int32_T>(nblocks << 10));
            if (lastBlockLength > 0) {
                nblocks = static_cast<int32_T>(nblocks + 1);
            } else {
                lastBlockLength = 1024;
            }
        }

        b_y = x->data[0];
        for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset =
                static_cast<int32_T>(xblockoffset + 1)) {
            b_y += x->data[static_cast<int32_T>(xblockoffset - 1)];
        }

        for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength
             = static_cast<int32_T>(firstBlockLength + 1)) {
            real_T bsum;
            int32_T hi;
            xblockoffset = static_cast<int32_T>(static_cast<int32_T>
                (firstBlockLength - 1) << 10);
            bsum = x->data[xblockoffset];
            if (firstBlockLength == nblocks) {
                hi = lastBlockLength;
            } else {
                hi = 1024;
            }

            for (int32_T b_k{2}; b_k <= hi; b_k = static_cast<int32_T>(b_k + 1))
            {
                bsum += x->data[static_cast<int32_T>(static_cast<int32_T>
                    (xblockoffset + b_k) - 1)];
            }

            b_y += bsum;
        }
    }

    return b_y / static_cast<real_T>(x->size[0]);
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static int32_T Real2SimGuidance_thirdOfFive(const
    emxArray_real_T_Real2SimGuidance_T *v, int32_T ia, int32_T ib)
{
    int32_T im;
    if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>(ia + 1)
           == ib) | (ia == ib)))) {
        im = ia;
    } else if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                  (ia + 2) == ib) | (static_cast<int32_T>(ia + 3) == ib)))) {
        real_T v4;
        v4 = v->data[static_cast<int32_T>(ia - 1)];
        if (v4 < v->data[ia]) {
            real_T v5;
            v5 = v->data[static_cast<int32_T>(ia + 1)];
            if (v->data[ia] < v5) {
                im = static_cast<int32_T>(ia + 1);
            } else if (v4 < v5) {
                im = static_cast<int32_T>(ia + 2);
            } else {
                im = ia;
            }
        } else {
            real_T v5;
            v5 = v->data[static_cast<int32_T>(ia + 1)];
            if (v4 < v5) {
                im = ia;
            } else if (v->data[ia] < v5) {
                im = static_cast<int32_T>(ia + 2);
            } else {
                im = static_cast<int32_T>(ia + 1);
            }
        }
    } else {
        real_T v4;
        real_T v5;
        int32_T b_j1;
        int32_T j2;
        int32_T j4;
        int32_T j5;
        v4 = v->data[static_cast<int32_T>(ia - 1)];
        if (v4 < v->data[ia]) {
            v5 = v->data[static_cast<int32_T>(ia + 1)];
            if (v->data[ia] < v5) {
                b_j1 = ia;
                j2 = ia;
                im = static_cast<int32_T>(ia + 2);
            } else if (v4 < v5) {
                b_j1 = ia;
                j2 = static_cast<int32_T>(ia + 1);
                im = static_cast<int32_T>(ia + 1);
            } else {
                b_j1 = static_cast<int32_T>(ia + 2);
                j2 = static_cast<int32_T>(ia - 1);
                im = static_cast<int32_T>(ia + 1);
            }
        } else {
            v5 = v->data[static_cast<int32_T>(ia + 1)];
            if (v4 < v5) {
                b_j1 = static_cast<int32_T>(ia + 1);
                j2 = static_cast<int32_T>(ia - 1);
                im = static_cast<int32_T>(ia + 2);
            } else if (v->data[ia] < v5) {
                b_j1 = static_cast<int32_T>(ia + 1);
                j2 = static_cast<int32_T>(ia + 1);
                im = ia;
            } else {
                b_j1 = static_cast<int32_T>(ia + 2);
                j2 = ia;
                im = ia;
            }
        }

        j4 = ia;
        j5 = static_cast<int32_T>(ia + 1);
        v4 = v->data[static_cast<int32_T>(ia + 2)];
        v5 = v->data[static_cast<int32_T>(ia + 3)];
        if (v5 < v4) {
            j4 = static_cast<int32_T>(ia + 1);
            j5 = ia;
            v5 = v4;
            v4 = v->data[static_cast<int32_T>(ia + 3)];
        }

        if (v5 < v->data[static_cast<int32_T>(b_j1 - 1)]) {
            im = b_j1;
        } else if (v5 < v->data[j2]) {
            im = static_cast<int32_T>(j5 + 3);
        } else if (v4 < v->data[j2]) {
            im = static_cast<int32_T>(j2 + 1);
        } else if (v4 < v->data[static_cast<int32_T>(im - 1)]) {
            im = static_cast<int32_T>(j4 + 3);
        }
    }

    return im;
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_quickselect(emxArray_real_T_Real2SimGuidance_T *v,
    int32_T n, int32_T vlen, real_T *vn, int32_T *nfirst, int32_T *nlast)
{
    emxArray_real_T_Real2SimGuidance_T *b_v;
    if (n > vlen) {
        *vn = (rtNaN);
        *nfirst = 0;
        *nlast = 0;
    } else {
        int32_T ia;
        int32_T ib;
        int32_T ipiv;
        int32_T oldnv;
        boolean_T checkspeed;
        boolean_T exitg1;
        boolean_T isslow;
        ipiv = static_cast<int32_T>(n - 1);
        ia = 0;
        ib = static_cast<int32_T>(vlen - 1);
        *nfirst = 1;
        *nlast = vlen;
        oldnv = vlen;
        checkspeed = false;
        isslow = false;
        Real2SimGuidance_emxInit_real_T(&b_v, 1);
        exitg1 = false;
        while ((!exitg1) && (static_cast<int32_T>(ia + 1) < static_cast<int32_T>
                             (ib + 1))) {
            real_T vref;
            int32_T b_nlast;
            int32_T i1;
            int32_T k;
            int32_T ngroupsof5;
            boolean_T guard1{ false };

            k = b_v->size[0];
            b_v->size[0] = v->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(b_v, k);
            i1 = v->size[0];
            for (k = 0; k <= static_cast<int32_T>(i1 - 1); k++) {
                b_v->data[k] = v->data[k];
            }

            vref = v->data[ipiv];
            b_v->data[ipiv] = v->data[ib];
            b_v->data[ib] = v->data[ipiv];
            ngroupsof5 = ia;
            b_nlast = -1;
            for (k = ia; static_cast<int32_T>(k + 1) <= ib; k =
                    static_cast<int32_T>(k + 1)) {
                real_T vk;
                vk = b_v->data[k];
                if (b_v->data[k] == vref) {
                    b_v->data[k] = b_v->data[ngroupsof5];
                    b_v->data[ngroupsof5] = vk;
                    b_nlast = static_cast<int32_T>(b_nlast + 1);
                    ngroupsof5 = static_cast<int32_T>(ngroupsof5 + 1);
                } else if (b_v->data[k] < vref) {
                    b_v->data[k] = b_v->data[ngroupsof5];
                    b_v->data[ngroupsof5] = vk;
                    ngroupsof5 = static_cast<int32_T>(ngroupsof5 + 1);
                }
            }

            b_v->data[ib] = b_v->data[ngroupsof5];
            b_v->data[ngroupsof5] = v->data[ipiv];
            k = v->size[0];
            v->size[0] = b_v->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(v, k);
            i1 = b_v->size[0];
            for (k = 0; k <= static_cast<int32_T>(i1 - 1); k++) {
                v->data[k] = b_v->data[k];
            }

            *nlast = static_cast<int32_T>(ngroupsof5 + 1);
            guard1 = false;
            if (n <= static_cast<int32_T>(ngroupsof5 + 1)) {
                *nfirst = static_cast<int32_T>(ngroupsof5 - b_nlast);
                if (n >= *nfirst) {
                    exitg1 = true;
                } else {
                    ib = static_cast<int32_T>(ngroupsof5 - 1);
                    guard1 = true;
                }
            } else {
                ia = static_cast<int32_T>(ngroupsof5 + 1);
                guard1 = true;
            }

            if (guard1) {
                ipiv = static_cast<int32_T>(static_cast<int32_T>(ib - ia) + 1);
                if (checkspeed) {
                    isslow = (ipiv > static_cast<int32_T>(oldnv / 2));
                    oldnv = ipiv;
                }

                checkspeed = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(checkspeed) ^ 1));
                if (isslow) {
                    while (ipiv > 1) {
                        int32_T destidx;
                        ngroupsof5 = static_cast<int32_T>(ipiv / 5);
                        b_nlast = static_cast<int32_T>(ipiv - static_cast<
                            int32_T>(ngroupsof5 * 5));
                        ipiv = ngroupsof5;
                        for (k = 0; k <= static_cast<int32_T>(ngroupsof5 - 1); k
                             = static_cast<int32_T>(k + 1)) {
                            i1 = static_cast<int32_T>(static_cast<int32_T>(
                                static_cast<int32_T>(k * 5) + ia) + 1);
                            i1 = static_cast<int32_T>
                                (Real2SimGuidance_thirdOfFive(v, i1,
                                  static_cast<int32_T>(i1 + 4)) - 1);
                            destidx = static_cast<int32_T>(ia + k);
                            vref = v->data[destidx];
                            v->data[destidx] = v->data[i1];
                            v->data[i1] = vref;
                        }

                        if (b_nlast > 0) {
                            i1 = static_cast<int32_T>(static_cast<int32_T>(
                                static_cast<int32_T>(ngroupsof5 * 5) + ia) + 1);
                            i1 = static_cast<int32_T>
                                (Real2SimGuidance_thirdOfFive(v, i1,
                                  static_cast<int32_T>(static_cast<int32_T>(i1 +
                                    b_nlast) - 1)) - 1);
                            destidx = static_cast<int32_T>(ia + ngroupsof5);
                            vref = v->data[destidx];
                            v->data[destidx] = v->data[i1];
                            v->data[i1] = vref;
                            ipiv = static_cast<int32_T>(ngroupsof5 + 1);
                        }
                    }
                } else if (ipiv >= 3) {
                    ipiv = static_cast<int32_T>(static_cast<int32_T>(
                        static_cast<int32_T>(ipiv - 1) / 2) + ia);
                    if (b_v->data[ia] < b_v->data[ipiv]) {
                        if (b_v->data[ipiv] < b_v->data[ib]) {
                            ipiv = static_cast<int32_T>(ipiv + 1);
                        } else if (b_v->data[ia] < b_v->data[ib]) {
                            ipiv = static_cast<int32_T>(ib + 1);
                        } else {
                            ipiv = static_cast<int32_T>(ia + 1);
                        }
                    } else if (b_v->data[ia] < b_v->data[ib]) {
                        ipiv = static_cast<int32_T>(ia + 1);
                    } else if (b_v->data[ipiv] < b_v->data[ib]) {
                        ipiv = static_cast<int32_T>(ib + 1);
                    } else {
                        ipiv = static_cast<int32_T>(ipiv + 1);
                    }

                    if (ipiv > static_cast<int32_T>(ia + 1)) {
                        v->data[ia] = b_v->data[static_cast<int32_T>(ipiv - 1)];
                        v->data[static_cast<int32_T>(ipiv - 1)] = b_v->data[ia];
                    }
                }

                ipiv = ia;
                *nfirst = static_cast<int32_T>(ia + 1);
                *nlast = static_cast<int32_T>(ib + 1);
            }
        }

        Real2SimGuidance_emxFree_real_T(&b_v);
        *vn = v->data[static_cast<int32_T>(*nlast - 1)];
    }
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static real_T Real2SimGuidance_vmedian(emxArray_real_T_Real2SimGuidance_T *v,
    int32_T n)
{
    emxArray_real_T_Real2SimGuidance_T *c;
    real_T b;
    real_T m;
    int32_T a__3;
    int32_T a__5;
    int32_T a__6;
    int32_T midm1;
    Real2SimGuidance_emxInit_real_T(&c, 1);
    midm1 = 0;
    int32_T exitg1;
    do {
        exitg1 = 0;
        if (midm1 <= static_cast<int32_T>(n - 1)) {
            if (std::isnan(v->data[midm1])) {
                m = (rtNaN);
                exitg1 = 1;
            } else {
                midm1 = static_cast<int32_T>(midm1 + 1);
            }
        } else {
            if (n <= 4) {
                switch (n) {
                  case 0:
                    m = (rtNaN);
                    break;

                  case 1:
                    m = v->data[0];
                    break;

                  case 2:
                    if (std::isinf(v->data[0])) {
                        m = (v->data[0] + v->data[1]) / 2.0;
                    } else {
                        m = (v->data[1] - v->data[0]) / 2.0 + v->data[0];
                    }
                    break;

                  case 3:
                    if (v->data[0] < v->data[1]) {
                        if (v->data[1] < v->data[2]) {
                            midm1 = 1;
                        } else if (v->data[0] < v->data[2]) {
                            midm1 = 2;
                        } else {
                            midm1 = 0;
                        }
                    } else if (v->data[0] < v->data[2]) {
                        midm1 = 0;
                    } else if (v->data[1] < v->data[2]) {
                        midm1 = 2;
                    } else {
                        midm1 = 1;
                    }

                    m = v->data[midm1];
                    break;

                  default:
                    if (v->data[0] < v->data[1]) {
                        if (v->data[1] < v->data[2]) {
                            midm1 = 0;
                            a__5 = 1;
                            a__6 = 2;
                        } else if (v->data[0] < v->data[2]) {
                            midm1 = 0;
                            a__5 = 2;
                            a__6 = 1;
                        } else {
                            midm1 = 2;
                            a__5 = 0;
                            a__6 = 1;
                        }
                    } else if (v->data[0] < v->data[2]) {
                        midm1 = 1;
                        a__5 = 0;
                        a__6 = 2;
                    } else if (v->data[1] < v->data[2]) {
                        midm1 = 1;
                        a__5 = 2;
                        a__6 = 0;
                    } else {
                        midm1 = 2;
                        a__5 = 1;
                        a__6 = 0;
                    }

                    if (v->data[midm1] < v->data[3]) {
                        if (v->data[3] < v->data[a__6]) {
                            if (std::isinf(v->data[a__5])) {
                                m = (v->data[a__5] + v->data[3]) / 2.0;
                            } else {
                                m = (v->data[3] - v->data[a__5]) / 2.0 + v->
                                    data[a__5];
                            }
                        } else if (std::isinf(v->data[a__5])) {
                            m = (v->data[a__5] + v->data[a__6]) / 2.0;
                        } else {
                            m = (v->data[a__6] - v->data[a__5]) / 2.0 + v->
                                data[a__5];
                        }
                    } else if (std::isinf(v->data[midm1])) {
                        m = (v->data[midm1] + v->data[a__5]) / 2.0;
                    } else {
                        m = (v->data[a__5] - v->data[midm1]) / 2.0 + v->
                            data[midm1];
                    }
                    break;
                }
            } else {
                midm1 = static_cast<int32_T>(n >> 1);
                if (static_cast<uint32_T>(static_cast<uint32_T>(n) & 1U) == 0U)
                {
                    int32_T loop_ub;
                    a__3 = c->size[0];
                    c->size[0] = v->size[0];
                    Real2SimGuidance_emxEnsureCapacity_real_T(c, a__3);
                    loop_ub = v->size[0];
                    for (a__3 = 0; a__3 <= static_cast<int32_T>(loop_ub - 1);
                            a__3++) {
                        c->data[a__3] = v->data[a__3];
                    }

                    Real2SimGuidance_quickselect(c, static_cast<int32_T>(midm1 +
                        1), n, &m, &a__6, &a__5);
                    a__3 = v->size[0];
                    v->size[0] = c->size[0];
                    Real2SimGuidance_emxEnsureCapacity_real_T(v, a__3);
                    loop_ub = c->size[0];
                    for (a__3 = 0; a__3 <= static_cast<int32_T>(loop_ub - 1);
                            a__3++) {
                        v->data[a__3] = c->data[a__3];
                    }

                    if (midm1 < a__6) {
                        a__3 = c->size[0];
                        c->size[0] = v->size[0];
                        Real2SimGuidance_emxEnsureCapacity_real_T(c, a__3);
                        loop_ub = v->size[0];
                        for (a__3 = 0; a__3 <= static_cast<int32_T>(loop_ub - 1);
                             a__3++) {
                            c->data[a__3] = v->data[a__3];
                        }

                        Real2SimGuidance_quickselect(c, midm1,
                            static_cast<int32_T>(a__5 - 1), &b, &a__6, &a__3);
                        if (std::isinf(m)) {
                            m = (m + b) / 2.0;
                        } else {
                            m += (b - m) / 2.0;
                        }
                    }
                } else {
                    int32_T loop_ub;
                    a__3 = c->size[0];
                    c->size[0] = v->size[0];
                    Real2SimGuidance_emxEnsureCapacity_real_T(c, a__3);
                    loop_ub = v->size[0];
                    for (a__3 = 0; a__3 <= static_cast<int32_T>(loop_ub - 1);
                            a__3++) {
                        c->data[a__3] = v->data[a__3];
                    }

                    Real2SimGuidance_quickselect(c, static_cast<int32_T>(midm1 +
                        1), n, &m, &a__5, &a__6);
                }
            }

            exitg1 = 1;
        }
    } while (exitg1 == 0);

    Real2SimGuidance_emxFree_real_T(&c);
    return m;
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static real_T Real2SimGuidance_median(const emxArray_real_T_Real2SimGuidance_T
    *x)
{
    emxArray_real_T_Real2SimGuidance_T *b;
    real_T y;
    Real2SimGuidance_emxInit_real_T(&b, 1);
    if (x->size[0] == 0) {
        y = (rtNaN);
    } else {
        int32_T i;
        int32_T loop_ub;
        i = b->size[0];
        b->size[0] = x->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(b, i);
        loop_ub = x->size[0];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            b->data[i] = x->data[i];
        }

        y = Real2SimGuidance_vmedian(b, x->size[0]);
    }

    Real2SimGuidance_emxFree_real_T(&b);
    return y;
}

static void Real2SimGuidance_binary_expand_op
    (emxArray_boolean_T_Real2SimGuidance_T *in1, const real_T in2[1048576],
     int32_T in3, real_T in4, const emxArray_real_T_Real2SimGuidance_T *in5,
     const emxArray_real_T_Real2SimGuidance_T *in6, int32_T in7)
{
    emxArray_boolean_T_Real2SimGuidance_T *in1_0;
    real_T in6_0;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    Real2SimGuidance_emxInit_boolean_T(&in1_0, 1);

    // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
    // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
    // MATLAB Function: '<S16>/Cartesian2Polar'
    in6_0 = in6->data[in7];
    i = in1_0->size[0];
    in1_0->size[0] = (in5->size[0] == 1 ? in3 : in5->size[0]) == 1 ? in1->size[0]
        : in5->size[0] == 1 ? in3 : in5->size[0];
    Real2SimGuidance_emxEnsureCapacity_boolean_T(in1_0, i);
    stride_0_0 = (in1->size[0] != 1);
    stride_1_0 = (in3 != 1);
    stride_2_0 = (in5->size[0] != 1);
    loop_ub = (in5->size[0] == 1 ? in3 : in5->size[0]) == 1 ? in1->size[0] :
        in5->size[0] == 1 ? in3 : in5->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_0->data[i] = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((in2[static_cast<int32_T>(i * stride_1_0)] <= in4) & (in5->data[
            static_cast<int32_T>(i * stride_2_0)] == in6_0)))) |
            static_cast<int32_T>(in1->data[static_cast<int32_T>(i * stride_0_0)])));
    }

    i = in1->size[0];
    in1->size[0] = in1_0->size[0];
    Real2SimGuidance_emxEnsureCapacity_boolean_T(in1, i);
    loop_ub = in1_0->size[0];
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1->data[i] = in1_0->data[i];
    }

    // End of MATLAB Function: '<S16>/Cartesian2Polar'
    // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
    // End of Outputs for SubSystem: '<Root>/AvoidDanger'
    Real2SimGuidance_emxFree_boolean_T(&in1_0);
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static int8_T Real2SimGuidance_filedata_i(DW_Real2SimGuidance_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles_o[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static int8_T Real2SimGuidance_cfopen_p(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = Real2SimGuidance_filedata_i(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles_o[static_cast<int32_T>(static_cast<int32_T>(j)
                - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static real_T Real2SimGuidance_fileManager(DW_Real2SimGuidance_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = Real2SimGuidance_cfopen_p("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static void Real2SimGuidance_fread_j(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(std::round(fileID));
    if (fileID != static_cast<real_T>(fileid)) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        filestar = localDW->eml_openfiles_o[static_cast<int32_T>(static_cast<
            int32_T>(fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
              static_cast<boolean_T>(static_cast<int32_T>((fileID != 0.0) ^ 1)))
             | static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
               ((fileID != 1.0) ^ 1)))))) | static_cast<int32_T>
            (static_cast<boolean_T>(static_cast<int32_T>((fileID != 2.0) ^ 1))))))
    {
        filestar = NULL;
    }

    A->size[0] = 0;
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == NULL) ^ 1))) {
        int32_T c;
        c = 1;
        while (c > 0) {
            int32_T c_0;
            int32_T i;
            int32_T numRead;
            c = 0;
            numRead = 1;
            while (static_cast<boolean_T>(static_cast<int32_T>((c < 1024) &
                     (numRead > 0)))) {
                size_t numReadSizeT;
                numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c),
                                     filestar);
                numRead = (int32_T)numReadSizeT;
                c = static_cast<int32_T>(c + (int32_T)numReadSizeT);
            }

            numRead = A->size[0];
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            i = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(c_0 + A->
                size[0]) + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T(A, i);
            if (c < 1) {
                c_0 = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
            }

            for (i = 0; i <= c_0; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static int32_T Real2SimGuidance_cfclose_l(real_T fid, DW_Real2SimGuidance_f_T
    *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(std::round(fid));
    if (fid != static_cast<real_T>(fileid)) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = localDW->eml_openfiles_o[static_cast<int32_T>
            (static_cast<int32_T>(b_fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(b_fileid)) {
          case 0:
            filestar = stdin;
            break;

          case 1:
            filestar = stdout;
            break;

          case 2:
            filestar = stderr;
            break;

          default:
            filestar = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((filestar != NULL) & (
            static_cast<int32_T>(fileid) >= 3)))) {
        int32_T cst;
        cst = fclose(filestar);
        if (cst == 0) {
            st = 0;
            localDW->eml_openfiles_o[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static void Real2SimGuidance_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
    real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
    real_T *t_tm_year, boolean_T *t_tm_isdst)
{
    coderTm origStructTm;
    coderLocalTime(&origStructTm);
    *t_tm_nsec = (real_T)origStructTm.tm_nsec;
    *t_tm_sec = static_cast<real_T>(origStructTm.tm_sec);
    *t_tm_min = static_cast<real_T>(origStructTm.tm_min);
    *t_tm_hour = static_cast<real_T>(origStructTm.tm_hour);
    *t_tm_mday = static_cast<real_T>(origStructTm.tm_mday);
    *t_tm_mon = static_cast<real_T>(origStructTm.tm_mon);
    *t_tm_year = static_cast<real_T>(origStructTm.tm_year);
    *t_tm_isdst = (origStructTm.tm_isdst != 0);
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_two_prod(real_T a)
{
    creal_T c;
    creal_T da;
    real_T shi;
    real_T slo;
    int32_T trueCount;
    da = split_uvVAOGsE(a);
    shi = a * 8.64E+7;
    slo = (da.re * 8.64E+7 - shi) + da.im * 8.64E+7;
    trueCount = 0;
    if (std::isnan(slo)) {
        trueCount = 1;
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        slo = 0.0;
    }

    c.re = shi;
    c.im = slo;
    return c;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_two_diff(real_T a, real_T b)
{
    creal_T c;
    real_T bb;
    real_T shi;
    int32_T trueCount;
    shi = a - b;
    bb = shi - a;
    bb = (a - (shi - bb)) - (b + bb);
    trueCount = 0;
    if (std::isnan(bb)) {
        trueCount = 1;
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        bb = 0.0;
    }

    c.re = shi;
    c.im = bb;
    return c;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_times(const creal_T a)
{
    creal_T c;
    real_T ahi;
    real_T alo;
    real_T tmp;
    c = Real2SimGuidance_two_prod(a.re);
    tmp = a.im * 8.64E+7;
    alo = c.im;
    ahi = c.re;
    if (tmp != 0.0) {
        alo = c.im + tmp;
        ahi = c.re + alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    c.re = ahi;
    c.im = alo;
    return c;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_minus(const creal_T a, const creal_T b)
{
    creal_T c;
    creal_T cout;
    creal_T t;
    real_T ahi;
    real_T alo;
    c = Real2SimGuidance_two_diff(a.re, b.re);
    t = Real2SimGuidance_two_diff(a.im, b.im);
    alo = c.im;
    ahi = c.re;
    if (t.re != 0.0) {
        alo = c.im + t.re;
        ahi = c.re + alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    c.re = ahi;
    if (t.im != 0.0) {
        alo += t.im;
        ahi += alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    cout.re = ahi;
    cout.im = alo;
    return cout;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static void Real2SimGuidance_getDateVec(const creal_T dd, real_T *y, real_T *mo,
    real_T *d, real_T *h, real_T *m, real_T *s)
{
    creal_T b_c;
    creal_T b_thi_0;
    creal_T c_s;
    creal_T t;
    real_T b_ahi;
    real_T b_thi;
    real_T b_tmp;
    real_T slo;
    int32_T ic_quot;
    int32_T idn;
    b_c.re = dd.re / 8.64E+7;
    t = Real2SimGuidance_two_prod(b_c.re);
    c_s.re = 0.0;
    c_s.im = 0.0;
    if (dd.re != t.re) {
        c_s = Real2SimGuidance_two_diff(dd.re, t.re);
    }

    c_s.re = (0.0 * dd.im + c_s.re) - 0.0 * t.im;
    c_s.im = (c_s.im + dd.im) - t.im;
    b_tmp = (c_s.re + c_s.im) / 8.64E+7;
    b_ahi = 0.0;
    b_thi = b_c.re;
    if (b_tmp != 0.0) {
        b_thi = b_c.re + b_tmp;
        b_ahi = b_tmp - (b_thi - b_c.re);
    }

    if (std::isnan(b_ahi)) {
        b_ahi = 0.0;
    }

    b_thi_0.re = b_thi;
    b_thi_0.im = b_ahi;
    t = floor_LKLalLcG(b_thi_0);
    b_thi = t.re + t.im;
    b_thi_0 = Real2SimGuidance_minus(dd, Real2SimGuidance_times(t));
    b_c.re = b_thi_0.re / 1000.0;
    t = split_uvVAOGsE(b_c.re);
    b_tmp = b_c.re * 1000.0;
    slo = (t.re * 1000.0 - b_tmp) + t.im * 1000.0;
    idn = 0;
    if (std::isnan(slo)) {
        idn = 1;
    }

    if (static_cast<int32_T>(idn - 1) >= 0) {
        slo = 0.0;
    }

    c_s.re = 0.0;
    c_s.im = 0.0;
    if (b_thi_0.re != b_tmp) {
        c_s = Real2SimGuidance_two_diff(b_thi_0.re, b_tmp);
    }

    c_s.re = (0.0 * b_thi_0.im + c_s.re) - 0.0 * slo;
    c_s.im = (c_s.im + b_thi_0.im) - slo;
    slo = (c_s.re + c_s.im) / 1000.0;
    b_ahi = 0.0;
    b_tmp = b_c.re;
    if (slo != 0.0) {
        b_tmp = b_c.re + slo;
        b_ahi = slo - (b_tmp - b_c.re);
    }

    if (std::isnan(b_ahi)) {
        b_ahi = 0.0;
    }

    b_thi_0.re = b_tmp;
    b_thi_0.im = b_ahi;
    t = floor_LKLalLcG(b_thi_0);
    b_c = Real2SimGuidance_minus(b_thi_0, t);
    b_ahi = t.re + t.im;
    if (static_cast<boolean_T>(static_cast<int32_T>(((b_thi + 719529.0) - 61.0 >=
           0.0) & ((b_thi + 719529.0) - 61.0 <= 2.147483647E+9)))) {
        int32_T ia_quot;
        int32_T ib_rem;
        int32_T ic_rem;
        int32_T ig_rem;
        b_thi = std::round((b_thi + 719529.0) - 61.0);
        if (b_thi < 2.147483648E+9) {
            if (b_thi >= -2.147483648E+9) {
                idn = static_cast<int32_T>(b_thi);
            } else {
                idn = MIN_int32_T;
            }
        } else {
            idn = MAX_int32_T;
        }

        ig_rem = static_cast<int32_T>(idn - static_cast<int32_T>(146097 *
            div_s32(idn, 146097)));
        ic_quot = static_cast<int32_T>(std::trunc(static_cast<real_T>(ig_rem) /
            36524.0));
        ic_rem = static_cast<int32_T>(ig_rem - static_cast<int32_T>(36524 *
            div_s32(ig_rem, 36524)));
        if (ic_quot > 3) {
            ic_quot = 3;
            ic_rem = static_cast<int32_T>(ig_rem - 109572);
        }

        ib_rem = static_cast<int32_T>(ic_rem - static_cast<int32_T>(1461 *
            div_s32(ic_rem, 1461)));
        ia_quot = static_cast<int32_T>(std::trunc(static_cast<real_T>(ib_rem) /
            365.0));
        ig_rem = static_cast<int32_T>(ib_rem - static_cast<int32_T>(365 *
            div_s32(ib_rem, 365)));
        if (ia_quot > 3) {
            ia_quot = 3;
            ig_rem = static_cast<int32_T>(ib_rem - 1095);
        }

        *y = ((std::trunc(static_cast<real_T>(idn) / 146097.0) * 400.0 +
               static_cast<real_T>(ic_quot) * 100.0) + std::trunc
              (static_cast<real_T>(ic_rem) / 1461.0) * 4.0) + static_cast<real_T>
            (ia_quot);
        idn = static_cast<int32_T>(static_cast<int32_T>(std::trunc((static_cast<
            real_T>(ig_rem) * 5.0 + 308.0) / 153.0)) - 2);
        b_thi = static_cast<real_T>(idn);
        *d = ((static_cast<real_T>(ig_rem) - std::trunc((static_cast<real_T>(idn)
                 + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    } else {
        real_T b_a;
        real_T dc;
        b_tmp = std::floor(((b_thi + 719529.0) - 61.0) / 146097.0);
        slo = ((b_thi + 719529.0) - 61.0) - b_tmp * 146097.0;
        b_thi = std::floor(slo / 36524.0);
        if (b_thi > 3.0) {
            b_thi = 3.0;
        }

        dc = slo - b_thi * 36524.0;
        slo = std::floor(dc / 1461.0);
        dc -= slo * 1461.0;
        b_a = std::floor(dc / 365.0);
        if (b_a > 3.0) {
            b_a = 3.0;
        }

        dc -= b_a * 365.0;
        *y = ((b_tmp * 400.0 + b_thi * 100.0) + slo * 4.0) + b_a;
        b_thi = std::floor((dc * 5.0 + 308.0) / 153.0) - 2.0;
        *d = ((dc - std::floor((b_thi + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    }

    if (b_thi > 9.0) {
        (*y)++;
        *mo = (b_thi + 2.0) - 11.0;
    } else {
        *mo = (b_thi + 2.0) + 1.0;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((b_ahi >= 0.0) & (b_ahi <=
            2.147483647E+9)))) {
        idn = static_cast<int32_T>(std::round(b_ahi));
        ic_quot = static_cast<int32_T>(idn - static_cast<int32_T>(3600 * div_s32
            (idn, 3600)));
        *h = std::trunc(static_cast<real_T>(idn) / 3600.0);
        *m = std::trunc(static_cast<real_T>(ic_quot) / 60.0);
        b_ahi = static_cast<real_T>(static_cast<int32_T>(ic_quot -
            static_cast<int32_T>(60 * div_s32(ic_quot, 60))));
    } else {
        *h = std::floor(b_ahi / 3600.0);
        *m = std::floor((b_ahi - 3600.0 * *h) / 60.0);
        b_ahi -= 60.0 * *m;
    }

    *s = (b_c.re + b_c.im) + b_ahi;
    if (*s == 60.0) {
        *s = 59.999999999999993;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((dd.re == (rtInf)) & (dd.im ==
           0.0)))) {
        *y = (rtInf);
    } else if (static_cast<boolean_T>(static_cast<int32_T>((dd.re == (rtMinusInf))
                 & (dd.im == 0.0)))) {
        *y = (rtMinusInf);
    }
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_two_sum(real_T a, real_T b)
{
    creal_T c;
    real_T bb;
    real_T shi;
    int32_T trueCount;
    shi = a + b;
    bb = shi - a;
    bb = (a - (shi - bb)) + (b - bb);
    trueCount = 0;
    if (std::isnan(bb)) {
        trueCount = 1;
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        bb = 0.0;
    }

    c.re = shi;
    c.im = bb;
    return c;
}

// Function for MATLAB Function: '<Root>/TimeNow'
static creal_T Real2SimGuidance_plus(const creal_T a, real_T b)
{
    creal_T c;
    creal_T t;
    real_T ahi;
    real_T alo;
    c = Real2SimGuidance_two_sum(a.re, b);
    t = Real2SimGuidance_two_sum(a.im, 0.0);
    alo = c.im;
    ahi = c.re;
    if (t.re != 0.0) {
        alo = c.im + t.re;
        ahi = c.re + alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    c.re = ahi;
    if (t.im != 0.0) {
        alo += t.im;
        ahi += alo;
        alo -= ahi - c.re;
    }

    if (std::isnan(alo)) {
        alo = 0.0;
    }

    c.re = ahi;
    c.im = alo;
    return c;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static void Real2SimGuidance_readINI(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW)
{
    static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T i[15]{ 'C', 'l', 'i', 'm', 'b', 'A', 'n', 'g', 'l', 'e',
        'L', 'i', 'm', 'i', 't' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    emxArray_char_T_Real2SimGuidance_T *curKey;
    emxArray_char_T_Real2SimGuidance_T *curLine;
    emxArray_char_T_Real2SimGuidance_T *curSection;
    emxArray_char_T_Real2SimGuidance_T *curVal;
    emxArray_char_T_Real2SimGuidance_T *data;
    emxArray_char_T_Real2SimGuidance_T *data_0;
    emxArray_char_T_Real2SimGuidance_T *j;
    emxArray_char_T_Real2SimGuidance_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = Real2SimGuidance_cfopen_p("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T(&data, 2);
        Real2SimGuidance_emxInit_char_T(&j, 1);
        Real2SimGuidance_fread_j(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        Real2SimGuidance_emxFree_char_T(&j);
        Real2SimGuidance_emxInit_char_T(&curSection, 2);
        Real2SimGuidance_emxInit_char_T(&curKey, 2);
        Real2SimGuidance_emxInit_char_T(&curVal, 2);
        Real2SimGuidance_cfclose_l(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T(&curLine, 2);
        Real2SimGuidance_emxInit_char_T(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T(&tmp, 2);
        Real2SimGuidance_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                Real2SimGuidance_strtok(data_0, curLine, data);
                Real2SimGuidance_strtok_a(curLine, tmp);
                Real2SimGuidance_strtrim(tmp, curLine);
                if (curLine->size[1] >= 2) {
                    boolean_T guard1{ false };

                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                iremain = 0;
                                itoken = 0;
                            } else {
                                iremain = 1;
                                itoken = static_cast<int32_T>(curLine->size[1] -
                                    1);
                            }

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curSection->data[itoken_0] = curLine->data[
                                    static_cast<int32_T>(iremain + itoken_0)];
                            }

                            curKey->size[0] = 1;
                            curKey->size[1] = 0;
                        } else {
                            guard1 = true;
                        }
                    } else {
                        guard1 = true;
                    }

                    if (guard1) {
                        if (curLine->data[0] == ';') {
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                Real2SimGuidance_contains(curLine)) {
                            Real2SimGuidance_strtok_ay(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_g(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 15) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 15) {
                                if (h[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(aTmp->data[iremain]))
                                     & 127)] != h[static_cast<int32_T>(i[iremain])])
                                {
                                    exitg2 = 1;
                                } else {
                                    iremain = static_cast<int32_T>(iremain + 1);
                                }
                            } else {
                                b_bool = true;
                                exitg2 = 1;
                            }
                        } while (exitg2 == 0);
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret, itoken_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            ret->data[itoken_0] = curVal->data[itoken_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T(&data_0);
        Real2SimGuidance_emxFree_char_T(&tmp);
        Real2SimGuidance_emxFree_char_T(&aTmp);
        Real2SimGuidance_emxFree_char_T(&curLine);
        Real2SimGuidance_emxFree_char_T(&curVal);
        Real2SimGuidance_emxFree_char_T(&curKey);
        Real2SimGuidance_emxFree_char_T(&curSection);
        Real2SimGuidance_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static void Real2SimGuidance_readINI_p(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW)
{
    static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T i[14]{ 'D', 'i', 'v', 'e', 'A', 'n', 'g', 'l', 'e', 'L',
        'i', 'm', 'i', 't' };

    emxArray_char_T_Real2SimGuidance_T *aTmp;
    emxArray_char_T_Real2SimGuidance_T *curKey;
    emxArray_char_T_Real2SimGuidance_T *curLine;
    emxArray_char_T_Real2SimGuidance_T *curSection;
    emxArray_char_T_Real2SimGuidance_T *curVal;
    emxArray_char_T_Real2SimGuidance_T *data;
    emxArray_char_T_Real2SimGuidance_T *data_0;
    emxArray_char_T_Real2SimGuidance_T *j;
    emxArray_char_T_Real2SimGuidance_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = Real2SimGuidance_cfopen_p("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T(&data, 2);
        Real2SimGuidance_emxInit_char_T(&j, 1);
        Real2SimGuidance_fread_j(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        Real2SimGuidance_emxFree_char_T(&j);
        Real2SimGuidance_emxInit_char_T(&curSection, 2);
        Real2SimGuidance_emxInit_char_T(&curKey, 2);
        Real2SimGuidance_emxInit_char_T(&curVal, 2);
        Real2SimGuidance_cfclose_l(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T(&curLine, 2);
        Real2SimGuidance_emxInit_char_T(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T(&tmp, 2);
        Real2SimGuidance_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                Real2SimGuidance_strtok(data_0, curLine, data);
                Real2SimGuidance_strtok_a(curLine, tmp);
                Real2SimGuidance_strtrim(tmp, curLine);
                if (curLine->size[1] >= 2) {
                    boolean_T guard1{ false };

                    b_bool = false;
                    if (curLine->data[0] == '[') {
                        b_bool = true;
                    }

                    guard1 = false;
                    if (b_bool) {
                        b_bool = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            b_bool = true;
                        }

                        if (b_bool) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                iremain = 0;
                                itoken = 0;
                            } else {
                                iremain = 1;
                                itoken = static_cast<int32_T>(curLine->size[1] -
                                    1);
                            }

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curSection->data[itoken_0] = curLine->data[
                                    static_cast<int32_T>(iremain + itoken_0)];
                            }

                            curKey->size[0] = 1;
                            curKey->size[1] = 0;
                        } else {
                            guard1 = true;
                        }
                    } else {
                        guard1 = true;
                    }

                    if (guard1) {
                        if (curLine->data[0] == ';') {
                            b_bool = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(b_bool) ^ 1))) &&
                                Real2SimGuidance_contains(curLine)) {
                            Real2SimGuidance_strtok_ay(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_g(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(aTmp, itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 14) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 14) {
                                if (h[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(aTmp->data[iremain]))
                                     & 127)] != h[static_cast<int32_T>(i[iremain])])
                                {
                                    exitg2 = 1;
                                } else {
                                    iremain = static_cast<int32_T>(iremain + 1);
                                }
                            } else {
                                b_bool = true;
                                exitg2 = 1;
                            }
                        } while (exitg2 == 0);
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret, itoken_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            ret->data[itoken_0] = curVal->data[itoken_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T(&data_0);
        Real2SimGuidance_emxFree_char_T(&tmp);
        Real2SimGuidance_emxFree_char_T(&aTmp);
        Real2SimGuidance_emxFree_char_T(&curLine);
        Real2SimGuidance_emxFree_char_T(&curVal);
        Real2SimGuidance_emxFree_char_T(&curKey);
        Real2SimGuidance_emxFree_char_T(&curSection);
        Real2SimGuidance_emxFree_char_T(&data);
    }
}

// System initialize for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    FILE* a;
    int32_T i;

    // SystemInitialize for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Integrator: '<S99>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S99>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<S9>/GenerateTrack'
    for (i = 0; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S93>/HeightSequence' incorporates:
        //   S-Function (sfix_udelay): '<S93>/EastSequence'

        localDW->HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<S9>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<S9>/SpeedControl'
    // SystemInitialize for MATLAB Function: '<S98>/getSpeedLimit'
    a = NULL;
    for (i = 0; i < 20; i++) {
        localDW->eml_openfiles_k[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S98>/getSpeedLimit'

    // SystemInitialize for Enabled SubSystem: '<S98>/SpdFBControl'
    // SystemInitialize for Enabled SubSystem: '<S115>/ADRC'
    // InitializeConditions for Integrator: '<S121>/Integrator'
    localX->Integrator_CSTATE[0] = 0.0;
    localX->Integrator_CSTATE[1] = 0.0;
    localX->Integrator_CSTATE[2] = 0.0;

    // End of SystemInitialize for SubSystem: '<S115>/ADRC'
    // End of SystemInitialize for SubSystem: '<S98>/SpdFBControl'
    // End of SystemInitialize for SubSystem: '<S9>/SpeedControl'

    // SystemInitialize for Atomic SubSystem: '<S9>/MaxBrake'
    // SystemInitialize for MATLAB Function: '<S96>/getSpeedLimit'
    a = NULL;
    for (i = 0; i < 20; i++) {
        localDW->eml_openfiles_f[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S96>/getSpeedLimit'
    // End of SystemInitialize for SubSystem: '<S9>/MaxBrake'

    // SystemInitialize for Atomic SubSystem: '<S9>/HeadingLogic'
    // SystemInitialize for Atomic SubSystem: '<S94>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // End of SystemInitialize for SubSystem: '<S94>/NewMissionHdg'

    // Start for MATLABSystem: '<S94>/TrackSimPath'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.SearchFlag = true;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S94>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 651; i++) {
        // InitializeConditions for MATLABSystem: '<S94>/TrackSimPath'
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S9>/HeadingLogic'
    // End of SystemInitialize for SubSystem: '<Root>/Real2SimNav'

    // SystemInitialize for Atomic SubSystem: '<Root>/AvoidDanger'
    // SystemInitialize for Atomic SubSystem: '<S1>/ProcessCloudPoint'
    // Start for MATLABSystem: '<S16>/Coordinate Transformation Conversion'
    localDW->objisempty_k = true;
    localDW->obj_h.isInitialized = 1;

    // End of SystemInitialize for SubSystem: '<S1>/ProcessCloudPoint'

    // SystemInitialize for Enabled SubSystem: '<S1>/TieredVFH+'
    // SystemInitialize for Enabled SubSystem: '<S17>/VFH+10'
    // Start for MATLABSystem: '<S39>/VectorFieldHistogram10'
    localDW->obj_n.NarrowOpeningThreshold = 0.8;
    localDW->obj_n.AngularLimits[0] = -3.1415926535897931;
    localDW->obj_n.AngularLimits[1] = 3.1415926535897931;
    localDW->obj_n.CacheInputSizes = false;
    localDW->objisempty_f4 = true;
    localDW->obj_n.DistanceLimits[0] = Real2SimGuidance_minimum
        (rtCP_VectorFieldHistogram10_DistanceLimits);
    localDW->obj_n.DistanceLimits[1] = 1623.8550613183404;
    localDW->obj_n.HistogramThresholds[0] = Real2SimGuidance_minimum
        (rtCP_VectorFieldHistogram10_HistogramThresholds);
    localDW->obj_n.HistogramThresholds[1] = 6495.4202452733625;
    localDW->obj_n.RobotRadius = 4.2;
    localDW->obj_n.SafetyDistance = 21.0;
    localDW->obj_n.MinTurningRadius = 405.9637653295851;
    localDW->obj_n.TargetDirectionWeight = 5.0;
    localDW->obj_n.CurrentDirectionWeight = 2.0;
    localDW->obj_n.PreviousDirectionWeight = 2.0;
    localDW->obj_n.isInitialized = 1;
    i = localDW->SFunction_DIMS3;
    if (localDW->SFunction_DIMS3 < 0) {
        i = 0;
    }

    localDW->obj_n.inputVarSize[0].f1[0] = static_cast<uint32_T>(i);
    localDW->obj_n.inputVarSize[0].f1[1] = 1U;
    i = localDW->Inverse_DIMS1;
    if (localDW->Inverse_DIMS1 < 0) {
        i = 0;
    }

    localDW->obj_n.inputVarSize[1].f1[0] = static_cast<uint32_T>(i);
    localDW->obj_n.inputVarSize[1].f1[1] = 1U;
    for (i = 0; i < 6; i++) {
        localDW->obj_n.inputVarSize[0].f1[static_cast<int32_T>(i + 2)] = 1U;
        localDW->obj_n.inputVarSize[1].f1[static_cast<int32_T>(i + 2)] = 1U;
    }

    for (i = 0; i < 8; i++) {
        localDW->obj_n.inputVarSize[2].f1[i] = 1U;
    }

    Real2SimGuidance_VectorFieldHistogramBase_setupImpl(&localDW->obj_n);

    // End of Start for MATLABSystem: '<S39>/VectorFieldHistogram10'

    // InitializeConditions for MATLABSystem: '<S39>/VectorFieldHistogram10'
    std::memset(&localDW->obj_n.BinaryHistogram[0], 0, static_cast<uint32_T>
                (180U * sizeof(boolean_T)));
    localDW->obj_n.PreviousDirection *= 0.0;

    // End of SystemInitialize for SubSystem: '<S17>/VFH+10'

    // Start for MATLABSystem: '<S17>/Vector Field Histogram'
    localDW->obj_p.NarrowOpeningThreshold = 0.8;
    localDW->obj_p.AngularLimits[0] = -3.1415926535897931;
    localDW->obj_p.AngularLimits[1] = 3.1415926535897931;
    localDW->obj_p.CacheInputSizes = false;
    localDW->objisempty_f = true;
    localDW->obj_p.DistanceLimits[0] = Real2SimGuidance_minimum
        (rtCP_VectorFieldHistogram_DistanceLimits);
    localDW->obj_p.DistanceLimits[1] = 1623.8550613183404;
    localDW->obj_p.HistogramThresholds[0] = Real2SimGuidance_minimum
        (rtCP_VectorFieldHistogram_HistogramThresholds);
    localDW->obj_p.HistogramThresholds[1] = 649.54202452733625;
    localDW->obj_p.RobotRadius = 4.2;
    localDW->obj_p.SafetyDistance = 21.0;
    localDW->obj_p.MinTurningRadius = 405.9637653295851;
    localDW->obj_p.TargetDirectionWeight = 5.0;
    localDW->obj_p.CurrentDirectionWeight = 2.0;
    localDW->obj_p.PreviousDirectionWeight = 2.0;
    localDW->obj_p.isInitialized = 1;
    i = localDW->SFunction_DIMS3;
    if (localDW->SFunction_DIMS3 < 0) {
        i = 0;
    }

    localDW->obj_p.inputVarSize[0].f1[0] = static_cast<uint32_T>(i);
    localDW->obj_p.inputVarSize[0].f1[1] = 1U;
    i = localDW->Inverse_DIMS1;
    if (localDW->Inverse_DIMS1 < 0) {
        i = 0;
    }

    localDW->obj_p.inputVarSize[1].f1[0] = static_cast<uint32_T>(i);
    localDW->obj_p.inputVarSize[1].f1[1] = 1U;
    for (i = 0; i < 6; i++) {
        localDW->obj_p.inputVarSize[0].f1[static_cast<int32_T>(i + 2)] = 1U;
        localDW->obj_p.inputVarSize[1].f1[static_cast<int32_T>(i + 2)] = 1U;
    }

    for (i = 0; i < 8; i++) {
        localDW->obj_p.inputVarSize[2].f1[i] = 1U;
    }

    Real2SimGuidance_VectorFieldHistogramBase_setupImpl(&localDW->obj_p);

    // End of Start for MATLABSystem: '<S17>/Vector Field Histogram'

    // InitializeConditions for MATLABSystem: '<S17>/Vector Field Histogram'
    std::memset(&localDW->obj_p.BinaryHistogram[0], 0, static_cast<uint32_T>
                (180U * sizeof(boolean_T)));
    localDW->obj_p.PreviousDirection *= 0.0;

    // End of SystemInitialize for SubSystem: '<S1>/TieredVFH+'

    // SystemInitialize for Atomic SubSystem: '<S1>/Hdg2LAP'
    // InitializeConditions for UnitDelay: '<S22>/Delay Input1'
    //
    //  Block description for '<S22>/Delay Input1':
    //
    //   Store in Global RAM

    localDW->DelayInput1_DSTATE_o = true;

    // SystemInitialize for MATLAB Function: '<S15>/getLAPGainBias'
    a = NULL;
    for (i = 0; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S15>/getLAPGainBias'
    // End of SystemInitialize for SubSystem: '<S1>/Hdg2LAP'
    // End of SystemInitialize for SubSystem: '<Root>/AvoidDanger'

    // SystemInitialize for MATLAB Function: '<Root>/Get Nominal Flight Speed'
    a = NULL;
    for (i = 0; i < 20; i++) {
        localDW->eml_openfiles_o[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<Root>/Get Nominal Flight Speed' 
}

// System reset for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Reset(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    FILE* a;

    // SystemReset for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Memory: '<S9>/MemoryNotInBrake'
    localDW->MemoryNotInBrake_PreviousInput = false;

    // InitializeConditions for Memory: '<S9>/Memory'
    localDW->Memory_PreviousInput = 0U;

    // InitializeConditions for Integrator: '<S99>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S99>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemReset for Atomic SubSystem: '<S9>/HeadingNaNProtection'
    // InitializeConditions for Memory: '<S95>/MemoryRefHeight'
    localDW->MemoryRefHeight_PreviousInput = 0.0;

    // End of SystemReset for SubSystem: '<S9>/HeadingNaNProtection'

    // SystemReset for Atomic SubSystem: '<S9>/GenerateTrack'
    for (int32_T i{0}; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S93>/EastSequence' 
        localDW->EastSequence_X[i] = 0.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S93>/HeightSequence' incorporates:
        //   S-Function (sfix_udelay): '<S93>/EastSequence'

        localDW->HeightSequence_X[i] = -150.0;

        // InitializeConditions for S-Function (sfix_udelay): '<S93>/NorthSequence' incorporates:
        //   S-Function (sfix_udelay): '<S93>/EastSequence'

        localDW->NorthSequence_X[i] = 0.0;
    }

    // End of SystemReset for SubSystem: '<S9>/GenerateTrack'

    // SystemReset for Atomic SubSystem: '<S9>/SpeedControl'
    // SystemReset for MATLAB Function: '<S98>/getSpeedLimit'
    localDW->SingletonInstance_not_empty = false;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles_k[i] = a;
    }

    // End of SystemReset for MATLAB Function: '<S98>/getSpeedLimit'
    // End of SystemReset for SubSystem: '<S9>/SpeedControl'

    // SystemReset for Atomic SubSystem: '<S9>/MaxBrake'
    // SystemReset for MATLAB Function: '<S96>/getSpeedLimit'
    localDW->SingletonInstance_not_empty_b = false;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles_f[i] = a;
    }

    // End of SystemReset for MATLAB Function: '<S96>/getSpeedLimit'
    // End of SystemReset for SubSystem: '<S9>/MaxBrake'

    // SystemReset for Atomic SubSystem: '<S9>/HeadingLogic'
    // InitializeConditions for MATLABSystem: '<S94>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (int32_T i{0}; i < 651; i++) {
        localDW->obj.WaypointsInternal[i] = (rtNaN);
    }

    // End of InitializeConditions for MATLABSystem: '<S94>/TrackSimPath'

    // SystemReset for Atomic SubSystem: '<S94>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // SystemReset for Chart: '<S100>/MissionSwitchInitialPersuit'
    localDW->temporalCounter_i1 = 0U;
    localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce_m = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2 = 0U;
    localDW->is_active_c3_Real2SimGuidance = 0U;
    localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->SimHdg = 0.0;

    // End of SystemReset for SubSystem: '<S94>/NewMissionHdg'
    // End of SystemReset for SubSystem: '<S9>/HeadingLogic'

    // SystemReset for Chart: '<S9>/Chart'
    localDW->is_active_c2_Real2SimGuidance = 0U;
    localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

    // End of SystemReset for SubSystem: '<Root>/Real2SimNav'

    // SystemReset for Chart: '<Root>/TASgreaterthan15for1Sec'
    localDW->is_active_c16_Real2SimGuidance = 0U;
    localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

    // SystemReset for Chart: '<Root>/EngagementDebouncer'
    localDW->is_Debounce_m4 = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_L0Engaged = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Debounce_b = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i2_f = 0U;
    localDW->is_L0Default = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->temporalCounter_i1_i = 0U;
    localDW->is_active_c34_Real2SimGuidance = 0U;
    localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
    localDW->Execution = 0.0;

    // SystemReset for Atomic SubSystem: '<Root>/AvoidDanger'
    // SystemReset for Atomic SubSystem: '<S1>/Hdg2LAP'
    // InitializeConditions for UnitDelay: '<S20>/Delay Input1'
    //
    //  Block description for '<S20>/Delay Input1':
    //
    //   Store in Global RAM

    localDW->DelayInput1_DSTATE = false;

    // InitializeConditions for UnitDelay: '<S22>/Delay Input1'
    //
    //  Block description for '<S22>/Delay Input1':
    //
    //   Store in Global RAM

    localDW->DelayInput1_DSTATE_o = true;

    // InitializeConditions for UnitDelay: '<S23>/Delay Input1'
    //
    //  Block description for '<S23>/Delay Input1':
    //
    //   Store in Global RAM

    localDW->DelayInput1_DSTATE_p = false;

    // SystemReset for MATLAB Function: '<S15>/getLAPGainBias'
    localDW->LAPGainBias_not_empty = false;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }

    // End of SystemReset for MATLAB Function: '<S15>/getLAPGainBias'
    // End of SystemReset for SubSystem: '<S1>/Hdg2LAP'
    // End of SystemReset for SubSystem: '<Root>/AvoidDanger'

    // SystemReset for MATLAB Function: '<Root>/Get Nominal Flight Speed'
    localDW->SingletonInstance_not_empty_a = false;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles_o[i] = a;
    }

    // End of SystemReset for MATLAB Function: '<Root>/Get Nominal Flight Speed' 
}

// Disable for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW)
{
    // Disable for Atomic SubSystem: '<Root>/Real2SimNav'
    // Disable for Atomic SubSystem: '<S9>/SpeedControl'
    // Disable for Enabled SubSystem: '<S98>/SpdFBControl'
    if (localDW->SpdFBControl_MODE) {
        // Disable for Enabled SubSystem: '<S115>/ADRC'
        localDW->ADRC_MODE = false;

        // End of Disable for SubSystem: '<S115>/ADRC'

        // Disable for Enabled SubSystem: '<S115>/PID'
        localDW->PID_MODE = false;

        // End of Disable for SubSystem: '<S115>/PID'
        localDW->SpdFBControl_MODE = false;
    }

    // End of Disable for SubSystem: '<S98>/SpdFBControl'
    // End of Disable for SubSystem: '<S9>/SpeedControl'
    // End of Disable for SubSystem: '<Root>/Real2SimNav'

    // Disable for Atomic SubSystem: '<Root>/AvoidDanger'
    // Disable for Enabled SubSystem: '<S1>/TieredVFH+'
    if (localDW->TieredVFH_MODE) {
        // Disable for Enabled SubSystem: '<S17>/VFH+10'
        localDW->VFH10_MODE = false;

        // End of Disable for SubSystem: '<S17>/VFH+10'
        localDW->TieredVFH_MODE = false;
    }

    // End of Disable for SubSystem: '<S1>/TieredVFH+'
    // End of Disable for SubSystem: '<Root>/AvoidDanger'
}

// Outputs for referenced model: 'Real2SimGuidance'
void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const Real2SimGuidance_M,
                      const boolean_T *rtu_NewMission, const uint8_T
                      *rtu_FlightMode, const StateFCU *rtu_StateFCU, const
                      boolean_T rtu_ControlSwitch[2], const
                      FixedWingGuidanceStateBus *rtu_SimUAVState, const
                      FixedWingGuidanceBus *rtu_ImmedGuidanceCMD, const real_T
                      *rtu_BiasRatio, const real_T *rtu_ParamADRC_hat_b, const
                      real_T *rtu_ParamADRC_omega_o, const real_T
                      *rtu_ParamADRC_omega_c, const real_T *rtu_ParamADRC_P,
                      const real_T *rtu_ParamADRC_I, const real_T
                      *rtu_ParamADRC_D, const boolean_T *rtu_ParamADRC_useADRC,
                      const real_T rtu_PntCldData[2097152], const int32_T
                      rtu_PntCldData_DIMS1[2], const real_T rtu_DngrListNER[192],
                      const int32_T rtu_DngrListNER_DIMS1[2], FCUCMD *rty_FCUCMD,
                      uint8_T *rty_EngagedFlag, FlightLogging *rty_FlightLogging,
                      DW_Real2SimGuidance_f_T *localDW, X_Real2SimGuidance_n_T
                      *localX)
{
    // local block i/o variables
    FixedWingGuidanceStateBus rtb_FixedWingGuidanceStateBus;
    boolean_T rtb_NotInDngr;
    boolean_T rtb_IsNaN;
    static const char_T l[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T m[4]{ 'G', 'a', 'i', 'n' };

    static const char_T n[4]{ 'B', 'i', 'a', 's' };

    static const int8_T a_0[9]{ 0, 0, 0, 1, 0, 0, 0, 1, 0 };

    emxArray_boolean_T_Real2SimGuidance_T *b_0;
    emxArray_boolean_T_Real2SimGuidance_T *front;
    emxArray_boolean_T_Real2SimGuidance_T *inRng;
    emxArray_char_T_Real2SimGuidance_T *aTmp;
    emxArray_char_T_Real2SimGuidance_T *curKey;
    emxArray_char_T_Real2SimGuidance_T *curLine;
    emxArray_char_T_Real2SimGuidance_T *curSection;
    emxArray_char_T_Real2SimGuidance_T *curVal;
    emxArray_char_T_Real2SimGuidance_T *data;
    emxArray_char_T_Real2SimGuidance_T *data_0;
    emxArray_char_T_Real2SimGuidance_T *data_1;
    emxArray_char_T_Real2SimGuidance_T *data_2;
    emxArray_char_T_Real2SimGuidance_T *data_3;
    emxArray_char_T_Real2SimGuidance_T *data_4;
    emxArray_char_T_Real2SimGuidance_T *data_5;
    emxArray_char_T_Real2SimGuidance_T *data_6;
    emxArray_char_T_Real2SimGuidance_T *data_7;
    emxArray_char_T_Real2SimGuidance_T *data_8;
    emxArray_char_T_Real2SimGuidance_T *data_9;
    emxArray_char_T_Real2SimGuidance_T *data_a;
    emxArray_char_T_Real2SimGuidance_T *data_b;
    emxArray_char_T_Real2SimGuidance_T *data_c;
    emxArray_char_T_Real2SimGuidance_T *data_d;
    emxArray_char_T_Real2SimGuidance_T *k;
    emxArray_char_T_Real2SimGuidance_T *ret;
    emxArray_char_T_Real2SimGuidance_T *tmp_7;
    emxArray_char_T_Real2SimGuidance_T *tmp_8;
    emxArray_char_T_Real2SimGuidance_T *tmp_9;
    emxArray_char_T_Real2SimGuidance_T *tmp_a;
    emxArray_char_T_Real2SimGuidance_T *tmp_b;
    emxArray_char_T_Real2SimGuidance_T *tmp_c;
    emxArray_char_T_Real2SimGuidance_T *tmp_d;
    emxArray_char_T_Real2SimGuidance_T *tmp_e;
    emxArray_char_T_Real2SimGuidance_T *tmp_f;
    emxArray_char_T_Real2SimGuidance_T *tmp_g;
    emxArray_char_T_Real2SimGuidance_T *tmp_h;
    emxArray_char_T_Real2SimGuidance_T *tmp_i;
    emxArray_char_T_Real2SimGuidance_T *tmp_j;
    emxArray_char_T_Real2SimGuidance_T *tmp_k;
    emxArray_char_T_Real2SimGuidance_T *tmp_l;
    emxArray_char_T_Real2SimGuidance_T *tmp_m;
    emxArray_char_T_Real2SimGuidance_T *tmp_n;
    emxArray_char_T_Real2SimGuidance_T *tmp_o;
    emxArray_char_T_Real2SimGuidance_T *tmp_p;
    emxArray_char_T_Real2SimGuidance_T *tmp_q;
    emxArray_char_T_Real2SimGuidance_T *tmp_r;
    emxArray_char_T_Real2SimGuidance_T *tmp_s;
    emxArray_char_T_Real2SimGuidance_T *tmp_t;
    emxArray_char_T_Real2SimGuidance_T *tmp_u;
    emxArray_char_T_Real2SimGuidance_T *tmp_v;
    emxArray_char_T_Real2SimGuidance_T *tmp_w;
    emxArray_int32_T_Real2SimGuidance_T *c;
    emxArray_int32_T_Real2SimGuidance_T *d;
    emxArray_real_T_Real2SimGuidance_T rtb_SelectEast_0;
    emxArray_real_T_Real2SimGuidance_T rtb_SelectNorth_0;
    emxArray_real_T_Real2SimGuidance_T rtb_rho_2;
    emxArray_real_T_Real2SimGuidance_T rtb_rho_3;
    emxArray_real_T_Real2SimGuidance_T rtb_theta_0;
    emxArray_real_T_Real2SimGuidance_T rtb_theta_1;
    emxArray_real_T_Real2SimGuidance_T *AngSec;
    emxArray_real_T_Real2SimGuidance_T *NewPC;
    emxArray_real_T_Real2SimGuidance_T *catAngSec;
    emxArray_real_T_Real2SimGuidance_T *rtb_rho_0;
    emxArray_real_T_Real2SimGuidance_T *rtb_rho_1;
    emxArray_real_T_Real2SimGuidance_T *tmp;
    emxArray_real_T_Real2SimGuidance_T *tmp_0;
    creal_T inputArg_data;
    creal_T tmp_3;
    creal_T tmp_4;
    creal_T tmp_5;
    creal_T tmp_6;
    real_T NormdNdE_data[128];
    real_T NormdNdE_data_0[64];
    real_T NormdNdE_data_1[64];
    real_T theta_data[64];
    real_T z_data[64];
    real_T rtb_TmpSignalConversionAtSFunctionInport1[4];
    real_T a[3];
    real_T rtb_Sum_k[3];
    real_T tmp_1[3];
    real_T tmp_2[2];
    real_T Switch;
    real_T c_fid;
    real_T d_fid;
    real_T fid;
    real_T rtb_Abs1;
    real_T rtb_Gain_p;
    real_T rtb_LowerBound;
    real_T rtb_RefGndSpd;
    real_T rtb_RefRngmMinRng;
    real_T rtb_Sum1_idx_1;
    real_T rtb_SumBiasH_idx_2;
    real_T rtb_Sum_e;
    real_T rtb_Sum_o;
    real_T rtb_Switch;
    real_T rtb_Switch_b;
    real_T rtb_UpperBound;
    real_T rtb_UpperBound_e;
    int32_T NormdNdE_size_idx_0;
    int32_T b;
    int32_T i;
    int32_T loop_ub;
    int32_T nx;
    int32_T rtu_DngrListNER_DIMS1_idx_0;
    int32_T tmp_10;
    int32_T tmp_11;
    int32_T tmp_12;
    int32_T tmp_x;
    int32_T tmp_y;
    int32_T tmp_z;
    int32_T z_size;
    uint8_T b_varargout_4;
    uint8_T b_varargout_6;
    uint8_T rtb_Memory;
    boolean_T x_data[64];
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T rtb_GreaterThanOrEqual_h;
    boolean_T rtb_RelationalOperator;
    Real2SimGuidance_emxInit_char_T(&ret, 2);
    Real2SimGuidance_emxInit_char_T(&data, 2);
    Real2SimGuidance_emxInit_char_T(&curSection, 2);
    Real2SimGuidance_emxInit_char_T(&curKey, 2);
    Real2SimGuidance_emxInit_char_T(&curVal, 2);
    Real2SimGuidance_emxInit_char_T(&curLine, 2);
    Real2SimGuidance_emxInit_char_T(&k, 1);
    Real2SimGuidance_emxInit_char_T(&aTmp, 2);
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Switch: '<S57>/Switch' incorporates:
        //   Abs: '<S57>/Abs'
        //   Bias: '<S57>/Bias'
        //   Bias: '<S57>/Bias1'
        //   Constant: '<S57>/Constant2'
        //   Constant: '<S58>/Constant'
        //   DataStoreRead: '<S6>/LatitudeGCS'
        //   Math: '<S57>/Math Function1'
        //   RelationalOperator: '<S58>/Compare'

        if (std::abs(LatitudeGCS) > 180.0) {
            rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch = LatitudeGCS;
        }

        // End of Switch: '<S57>/Switch'

        // Abs: '<S54>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch);

        // Switch: '<S54>/Switch' incorporates:
        //   Bias: '<S54>/Bias'
        //   Bias: '<S54>/Bias1'
        //   Constant: '<S45>/Constant'
        //   Constant: '<S45>/Constant1'
        //   Constant: '<S56>/Constant'
        //   Gain: '<S54>/Gain'
        //   Product: '<S54>/Divide1'
        //   RelationalOperator: '<S56>/Compare'
        //   Switch: '<S45>/Switch1'

        if (rtb_Abs1 > 90.0) {
            // Signum: '<S54>/Sign1'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Switch)) ^ 1))) {
                if (rtb_Switch < 0.0) {
                    rtb_Switch = -1.0;
                } else {
                    rtb_Switch = static_cast<real_T>(rtb_Switch > 0.0);
                }
            }

            // End of Signum: '<S54>/Sign1'
            rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S54>/Switch'

        // Sum: '<S45>/Sum' incorporates:
        //   DataStoreRead: '<S6>/LongitudeGCS'

        rtb_Switch_b = static_cast<real_T>(i) + LongitudeGCS;

        // Switch: '<S55>/Switch' incorporates:
        //   Abs: '<S55>/Abs'
        //   Bias: '<S55>/Bias'
        //   Bias: '<S55>/Bias1'
        //   Constant: '<S55>/Constant2'
        //   Constant: '<S59>/Constant'
        //   Math: '<S55>/Math Function1'
        //   RelationalOperator: '<S59>/Compare'

        if (std::abs(rtb_Switch_b) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Switch_b + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S55>/Switch'

        // Sum: '<S43>/Sum1'
        rtb_Abs1 = rtu_StateFCU->RealUAVState.Latitude_deg - rtb_Switch;
        rtb_Sum1_idx_1 = rtu_StateFCU->RealUAVState.Longitude_deg - rtb_Switch_b;

        // Switch: '<S51>/Switch' incorporates:
        //   Abs: '<S51>/Abs'
        //   Bias: '<S51>/Bias'
        //   Bias: '<S51>/Bias1'
        //   Constant: '<S51>/Constant2'
        //   Constant: '<S52>/Constant'
        //   Math: '<S51>/Math Function1'
        //   RelationalOperator: '<S52>/Compare'

        if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Switch_b = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Switch_b = rtb_Abs1;
        }

        // End of Switch: '<S51>/Switch'

        // Abs: '<S48>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch_b);

        // Switch: '<S48>/Switch' incorporates:
        //   Bias: '<S48>/Bias'
        //   Bias: '<S48>/Bias1'
        //   Constant: '<S44>/Constant'
        //   Constant: '<S44>/Constant1'
        //   Constant: '<S50>/Constant'
        //   Gain: '<S48>/Gain'
        //   Product: '<S48>/Divide1'
        //   RelationalOperator: '<S50>/Compare'
        //   Switch: '<S44>/Switch1'

        if (rtb_Abs1 > 90.0) {
            // Signum: '<S48>/Sign1'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Switch_b)) ^ 1))) {
                if (rtb_Switch_b < 0.0) {
                    rtb_Switch_b = -1.0;
                } else {
                    rtb_Switch_b = static_cast<real_T>(rtb_Switch_b > 0.0);
                }
            }

            // End of Signum: '<S48>/Sign1'
            rtb_Switch_b *= -(rtb_Abs1 + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S48>/Switch'

        // Sum: '<S44>/Sum'
        rtb_Sum_o = static_cast<real_T>(i) + rtb_Sum1_idx_1;

        // Switch: '<S49>/Switch' incorporates:
        //   Abs: '<S49>/Abs'
        //   Bias: '<S49>/Bias'
        //   Bias: '<S49>/Bias1'
        //   Constant: '<S49>/Constant2'
        //   Constant: '<S53>/Constant'
        //   Math: '<S49>/Math Function1'
        //   RelationalOperator: '<S53>/Compare'

        if (std::abs(rtb_Sum_o) > 180.0) {
            rtb_Sum_o = rt_modd_snf(rtb_Sum_o + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S49>/Switch'

        // UnitConversion: '<S47>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Abs1 = 0.017453292519943295 * rtb_Switch_b;
        rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Sum_o;

        // UnitConversion: '<S62>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch *= 0.017453292519943295;

        // Trigonometry: '<S63>/Trigonometric Function1'
        rtb_Sum_o = std::sin(rtb_Switch);

        // Sum: '<S63>/Sum1' incorporates:
        //   Constant: '<S63>/Constant'
        //   Product: '<S63>/Product1'

        rtb_Sum_o = 1.0 - 0.0066943799901413295 * rtb_Sum_o * rtb_Sum_o;

        // Product: '<S61>/Product1' incorporates:
        //   Constant: '<S61>/Constant1'
        //   Sqrt: '<S61>/sqrt'

        rtb_Switch_b = 6.378137E+6 / std::sqrt(rtb_Sum_o);

        // Product: '<S46>/dNorth' incorporates:
        //   Constant: '<S61>/Constant2'
        //   Product: '<S61>/Product3'
        //   Trigonometry: '<S61>/Trigonometric Function1'

        rtb_Sum_o = rtb_Abs1 / rt_atan2d_snf(1.0, rtb_Switch_b *
            0.99330562000985867 / rtb_Sum_o);

        // Product: '<S46>/dEast' incorporates:
        //   Constant: '<S61>/Constant3'
        //   Product: '<S61>/Product4'
        //   Trigonometry: '<S61>/Trigonometric Function'
        //   Trigonometry: '<S61>/Trigonometric Function2'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch_b = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_b * std::cos
            (rtb_Switch)) * rtb_Sum1_idx_1;

        // BusCreator: '<S6>/FixedWingGuidanceStateBus' incorporates:
        //   Constant: '<S6>/dummyRollAngleRate'
        //   DataStoreRead: '<S6>/AltitudeGCS'
        //   Gain: '<S40>/Gain1'
        //   Gain: '<S41>/Gain1'
        //   Gain: '<S42>/Gain1'
        //   Gain: '<S6>/inverse'
        //   Product: '<S46>/x*cos'
        //   Product: '<S46>/x*sin'
        //   Product: '<S46>/y*cos'
        //   Product: '<S46>/y*sin'
        //   Sum: '<S43>/Sum'
        //   Sum: '<S46>/Sum2'
        //   Sum: '<S46>/Sum3'

        rtb_FixedWingGuidanceStateBus.North = rtb_Switch_b * 0.0 + rtb_Sum_o;
        rtb_FixedWingGuidanceStateBus.East = rtb_Switch_b - rtb_Sum_o * 0.0;
        rtb_FixedWingGuidanceStateBus.Height =
            rtu_StateFCU->RealUAVState.Height_meter + -AltitudeGCS;
        rtb_FixedWingGuidanceStateBus.AirSpeed =
            rtu_StateFCU->RealUAVState.AirSpeed_mps;
        rtb_FixedWingGuidanceStateBus.HeadingAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.HeadingAngle_deg;
        rtb_FixedWingGuidanceStateBus.FlightPathAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.FlightPathAngle_deg;
        rtb_FixedWingGuidanceStateBus.RollAngle = 0.017453292519943295 *
            rtu_StateFCU->RealUAVState.RollAngle_deg;
        rtb_FixedWingGuidanceStateBus.RollAngleRate = 0.0;

        // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
        // Outputs for Atomic SubSystem: '<S9>/HeadingNaNProtection'
        // Memory: '<S95>/MemoryRefHeight'
        rtb_Switch_b = localDW->MemoryRefHeight_PreviousInput;

        // End of Outputs for SubSystem: '<S9>/HeadingNaNProtection'

        // Sum: '<S9>/Minus'
        rtb_Sum1_idx_1 = rtb_FixedWingGuidanceStateBus.AirSpeed -
            rtu_StateFCU->RealUAVState.GndSpd_mps;

        // Outputs for Atomic SubSystem: '<S9>/GenerateTrack'
        // S-Function (sfix_udelay): '<S93>/EastSequence'
        localDW->MatrixConcatenate[433] = rtu_SimUAVState->East;

        // S-Function (sfix_udelay): '<S93>/HeightSequence'
        localDW->MatrixConcatenate[650] = rtu_SimUAVState->Height;
        for (i = 0; i < 216; i++) {
            // S-Function (sfix_udelay): '<S93>/EastSequence'
            localDW->MatrixConcatenate[static_cast<int_T>(i + 217)] =
                localDW->EastSequence_X[i];

            // S-Function (sfix_udelay): '<S93>/HeightSequence' incorporates:
            //   S-Function (sfix_udelay): '<S93>/EastSequence'

            localDW->MatrixConcatenate[static_cast<int_T>(i + 434)] =
                localDW->HeightSequence_X[i];

            // S-Function (sfix_udelay): '<S93>/NorthSequence' incorporates:
            //   S-Function (sfix_udelay): '<S93>/EastSequence'

            localDW->MatrixConcatenate[i] = localDW->NorthSequence_X[i];
        }

        // S-Function (sfix_udelay): '<S93>/NorthSequence'
        localDW->MatrixConcatenate[216] = rtu_SimUAVState->North;

        // End of Outputs for SubSystem: '<S9>/GenerateTrack'

        // Memory: '<S9>/Memory'
        rtb_Memory = localDW->Memory_PreviousInput;

        // Outputs for Atomic SubSystem: '<S9>/SpeedControl'
        // Sum: '<S113>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/TargetLocation'

        rtb_Sum_e = localDW->MatrixConcatenate[60] - rtu_SimUAVState->North;

        // DotProduct: '<S113>/Dot Product'
        rtb_Sum_o = rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S113>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/TargetLocation'

        rtb_Sum_e = localDW->MatrixConcatenate[277] - rtu_SimUAVState->East;

        // DotProduct: '<S113>/Dot Product'
        rtb_Sum_o += rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S113>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/TargetLocation'

        rtb_Sum_e = localDW->MatrixConcatenate[494] - rtu_SimUAVState->Height;

        // Sqrt: '<S113>/sqrt' incorporates:
        //   DotProduct: '<S113>/Dot Product'

        rtb_Abs1 = std::sqrt(rtb_Sum_e * rtb_Sum_e + rtb_Sum_o);

        // Sum: '<S112>/Sum'
        rtb_Sum_k[0] = rtu_SimUAVState->North -
            rtb_FixedWingGuidanceStateBus.North;
        rtb_Sum_k[1] = rtu_SimUAVState->East -
            rtb_FixedWingGuidanceStateBus.East;
        rtb_Sum_k[2] = rtu_SimUAVState->Height - rtu_SimUAVState->Height;

        // Sqrt: '<S112>/sqrt' incorporates:
        //   DotProduct: '<S112>/Dot Product'

        rtb_Switch = std::sqrt((rtb_Sum_k[0] * rtb_Sum_k[0] + rtb_Sum_k[1] *
                                rtb_Sum_k[1]) + rtb_Sum_k[2] * rtb_Sum_k[2]);

        // Gain: '<S98>/Gain' incorporates:
        //   Sum: '<S98>/LagDistanceSum'

        localDW->Gain = -(rtb_Abs1 - rtb_Switch);

        // DataStoreWrite: '<S98>/WriteLagDistance'
        localDW->LagDistance = localDW->Gain;

        // MATLAB Function: '<S98>/getSpeedLimit'
        // MATLAB Function 'Real2SimNav/SpeedControl/getSpeedLimit': '<S116>:1'
        // '<S116>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->SingletonInstance_not_empty) ^ 1))) {
            localDW->SingletonInstance_n.AirSpeed = 35.0;
            localDW->SingletonInstance_n.MaxRollAngle = 0.3490658503988659;
            localDW->SingletonInstance_n.FlightPathAngleLimit[0] = -0.175;
            localDW->SingletonInstance_n.FlightPathAngleLimit[1] = 0.175;
            localDW->SingletonInstance_n.SpdLmt[0] = 29.0;
            localDW->SingletonInstance_n.SpdLmt[1] = 46.0;
            ret->size[0] = 1;
            ret->size[1] = 0;
            fid = Real2SimGuidance_fileManager_i(localDW);
            if (fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_k(fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_c(fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_v, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_w, 2);
                Real2SimGuidance_emxInit_char_T(&data_d, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_d->size[0] *
                        data_d->size[1]);
                    data_d->size[0] = 1;
                    data_d->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_d,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_d->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_d, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_w);
                    Real2SimGuidance_strtrim(tmp_w, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    nx = 0;
                                    b = 0;
                                } else {
                                    nx = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - nx);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(nx + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_v);
                                Real2SimGuidance_strtrim(tmp_v, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_gh(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_d);
                Real2SimGuidance_emxFree_char_T(&tmp_w);
                Real2SimGuidance_emxFree_char_T(&tmp_v);
            }

            inputArg_data = Real2SimGuidance_str2double(ret);
            printf("Set UAV NormAirSpeed:\t\t%f\n", inputArg_data.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Sum_o = Real2SimGuidance_fileManager_i(localDW);
            if (rtb_Sum_o < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_k(rtb_Sum_o, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_c(rtb_Sum_o, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_t, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_u, 2);
                Real2SimGuidance_emxInit_char_T(&data_c, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_c->size[0] *
                        data_c->size[1]);
                    data_c->size[0] = 1;
                    data_c->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_c,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_c->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_c, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_u);
                    Real2SimGuidance_strtrim(tmp_u, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    nx = 0;
                                    b = 0;
                                } else {
                                    nx = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - nx);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(nx + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_t);
                                Real2SimGuidance_strtrim(tmp_t, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghb(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_c);
                Real2SimGuidance_emxFree_char_T(&tmp_u);
                Real2SimGuidance_emxFree_char_T(&tmp_t);
            }

            tmp_3 = Real2SimGuidance_str2double(ret);
            printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_3.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            c_fid = Real2SimGuidance_fileManager_i(localDW);
            if (c_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_k(c_fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_c(c_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_r, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_s, 2);
                Real2SimGuidance_emxInit_char_T(&data_b, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_b->size[0] *
                        data_b->size[1]);
                    data_b->size[0] = 1;
                    data_b->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_b,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_b->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_b, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_s);
                    Real2SimGuidance_strtrim(tmp_s, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    nx = 0;
                                } else {
                                    b = 1;
                                    nx = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(nx - b);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(b + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_r);
                                Real2SimGuidance_strtrim(tmp_r, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghbx(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_b);
                Real2SimGuidance_emxFree_char_T(&tmp_s);
                Real2SimGuidance_emxFree_char_T(&tmp_r);
            }

            tmp_4 = Real2SimGuidance_str2double(ret);
            printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_4.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            d_fid = Real2SimGuidance_fileManager_i(localDW);
            if (d_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_k(d_fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_c(d_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_p, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_q, 2);
                Real2SimGuidance_emxInit_char_T(&data_a, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_a->size[0] *
                        data_a->size[1]);
                    data_a->size[0] = 1;
                    data_a->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_a,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_a->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_a, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_q);
                    Real2SimGuidance_strtrim(tmp_q, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    nx = 0;
                                } else {
                                    b = 1;
                                    nx = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(nx - b);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(b + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_p);
                                Real2SimGuidance_strtrim(tmp_p, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghbx5(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_a);
                Real2SimGuidance_emxFree_char_T(&tmp_q);
                Real2SimGuidance_emxFree_char_T(&tmp_p);
            }

            tmp_5 = Real2SimGuidance_str2double(ret);
            d_fid = 0.017453292519943295 * tmp_5.re;
            printf("Set UAV MaxRollAngle:\t\t%f\n", d_fid);
            fflush(stdout);
            Real2SimGuidance_readINI_n(ret, localDW);
            tmp_5 = Real2SimGuidance_str2double(ret);
            rtb_Sum_o = 0.017453292519943295 * tmp_5.re;
            printf("Set UAV ClimbAngleLimit:\t%f\n", rtb_Sum_o);
            fflush(stdout);
            Real2SimGuidance_readINI_ng(ret, localDW);
            tmp_5 = Real2SimGuidance_str2double(ret);
            fid = 0.017453292519943295 * tmp_5.re;
            printf("Set UAV DiveAngleLimit:\t\t%f\n", fid);
            fflush(stdout);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(inputArg_data.re)) ^ 1))) {
                localDW->SingletonInstance_n.AirSpeed = inputArg_data.re;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(d_fid)) ^ 1))) {
                localDW->SingletonInstance_n.MaxRollAngle = d_fid;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Sum_o)) ^ 1))) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan(fid)) ^
                   1)))) {
                localDW->SingletonInstance_n.FlightPathAngleLimit[0] = fid;
                localDW->SingletonInstance_n.FlightPathAngleLimit[1] = rtb_Sum_o;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(tmp_3.re)) ^ 1))) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan
                    (tmp_4.re)) ^ 1)))) {
                localDW->SingletonInstance_n.SpdLmt[0] = tmp_4.re;
                localDW->SingletonInstance_n.SpdLmt[1] = tmp_3.re;
            }

            Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
                (&localDW->SingletonInstance_n.Connector,
                 localDW->SingletonInstance_n.AirSpeed,
                 localDW->SingletonInstance_n.MaxRollAngle);
            localDW->SingletonInstance_not_empty = true;
        }

        localDW->SpeedLimit[0] = localDW->SingletonInstance_n.SpdLmt[0];
        localDW->SpeedLimit[1] = localDW->SingletonInstance_n.SpdLmt[1];

        // End of MATLAB Function: '<S98>/getSpeedLimit'

        // MinMax: '<S98>/Max'
        fid = std::fmax(localDW->SpeedLimit[0], localDW->SpeedLimit[1]);

        // Outputs for Enabled SubSystem: '<S98>/SpdFBControl' incorporates:
        //   EnablePort: '<S115>/Enable'

        if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
            // Logic: '<S9>/AND' incorporates:
            //   Constant: '<S97>/Constant'
            //   DataStoreRead: '<S9>/ReadFlightMode_Log'
            //   Memory: '<S9>/MemoryNotInBrake'
            //   RelationalOperator: '<S97>/Compare'

            if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                    (localDW->FlightMode_Log) == 3) & static_cast<int32_T>
                    (localDW->MemoryNotInBrake_PreviousInput)))) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (localDW->SpdFBControl_MODE) ^ 1)))
                {
                    // SystemReset for Chart: '<S115>/ControlLogic'
                    localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->temporalCounter_i1_n = 0U;
                    localDW->is_active_c6_Real2SimGuidance = 0U;
                    localDW->is_c6_Real2SimGuidance =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->PID_U = false;
                    localDW->EnableADRC = false;
                    localDW->EnablePID = false;
                    localDW->SpdFBControl_MODE = true;
                }
            } else if (localDW->SpdFBControl_MODE) {
                // Disable for Enabled SubSystem: '<S115>/ADRC'
                localDW->ADRC_MODE = false;

                // End of Disable for SubSystem: '<S115>/ADRC'

                // Disable for Enabled SubSystem: '<S115>/PID'
                localDW->PID_MODE = false;

                // End of Disable for SubSystem: '<S115>/PID'
                localDW->SpdFBControl_MODE = false;
            }

            // End of Logic: '<S9>/AND'
        }

        // End of Outputs for SubSystem: '<S98>/SpdFBControl'
        // End of Outputs for SubSystem: '<S9>/SpeedControl'
        // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    }

    // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S9>/SpeedControl'
    // Outputs for Enabled SubSystem: '<S98>/SpdFBControl' incorporates:
    //   EnablePort: '<S115>/Enable'

    if (localDW->SpdFBControl_MODE) {
        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Chart: '<S115>/ControlLogic'
            if (static_cast<uint32_T>(localDW->temporalCounter_i1_n) < 15U) {
                localDW->temporalCounter_i1_n = static_cast<uint8_T>(
                    static_cast<uint32_T>(static_cast<uint32_T>
                    (localDW->temporalCounter_i1_n) + 1U));
            }

            // Gateway: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
            // During: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
            if (static_cast<uint32_T>(localDW->is_active_c6_Real2SimGuidance) ==
                0U) {
                // Entry: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
                localDW->is_active_c6_Real2SimGuidance = 1U;

                // Entry Internal: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic 
                // Transition: '<S118>:81'
                localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                // Entry 'PID': '<S118>:53'
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;
            } else if (localDW->is_c6_Real2SimGuidance ==
                       Real2SimGuidance_IN_PID) {
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;

                // During 'PID': '<S118>:53'
                rtb_RelationalOperator = static_cast<boolean_T>
                    (static_cast<int32_T>((static_cast<int32_T>(rtb_Memory) != 0)
                      & static_cast<int32_T>(*rtu_ParamADRC_useADRC)));
                if (rtb_RelationalOperator) {
                    // Transition: '<S118>:83'
                    localDW->is_c6_Real2SimGuidance =
                        Real2SimGuidance_IN_useADRC;
                    localDW->is_useADRC = Real2SimGuidance_IN_Debounce_j;
                    localDW->is_Debounce = Real2SimGuidance_IN_PID2ADRC;
                    localDW->temporalCounter_i1_n = 0U;

                    // Entry 'PID2ADRC': '<S118>:62'
                    localDW->EnableADRC = true;
                }

                // During 'useADRC': '<S118>:92'
            } else if (static_cast<boolean_T>(static_cast<int32_T>
                        (static_cast<int32_T>(*rtu_ParamADRC_useADRC) ^ 1))) {
                // Transition: '<S118>:98'
                // Exit Internal 'useADRC': '<S118>:92'
                // Exit Internal 'Debounce': '<S118>:58'
                localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                // Entry 'PID': '<S118>:53'
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;
            } else if (localDW->is_useADRC == Real2SimGuidance_IN_ADRC) {
                localDW->EnablePID = false;
                localDW->EnableADRC = true;
                localDW->PID_U = false;

                // During 'ADRC': '<S118>:63'
                if (static_cast<int32_T>(rtb_Memory) == 0) {
                    // Transition: '<S118>:84'
                    localDW->is_useADRC = Real2SimGuidance_IN_Debounce_j;
                    localDW->is_Debounce = Real2SimGuidance_IN_ADRC2PID;
                    localDW->temporalCounter_i1_n = 0U;

                    // Entry 'ADRC2PID': '<S118>:61'
                    localDW->EnablePID = true;
                }

                // During 'Debounce': '<S118>:58'
            } else if (localDW->is_Debounce == Real2SimGuidance_IN_ADRC2PID) {
                localDW->EnablePID = true;

                // During 'ADRC2PID': '<S118>:61'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_n) >= 10U)
                {
                    // Transition: '<S118>:86'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                    // Entry 'PID': '<S118>:53'
                    localDW->EnableADRC = false;
                    localDW->PID_U = true;
                } else if (static_cast<int32_T>(rtb_Memory) != 0) {
                    // Transition: '<S118>:59'
                    localDW->is_Debounce = Real2SimGuidance_IN_PID2ADRC;
                    localDW->temporalCounter_i1_n = 0U;

                    // Entry 'PID2ADRC': '<S118>:62'
                    localDW->EnableADRC = true;
                }
            } else {
                localDW->EnableADRC = true;

                // During 'PID2ADRC': '<S118>:62'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_n) >= 10U)
                {
                    // Transition: '<S118>:85'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_useADRC = Real2SimGuidance_IN_ADRC;

                    // Entry 'ADRC': '<S118>:63'
                    localDW->EnablePID = false;
                    localDW->PID_U = false;
                } else if (static_cast<int32_T>(rtb_Memory) == 0) {
                    // Transition: '<S118>:60'
                    localDW->is_Debounce = Real2SimGuidance_IN_ADRC2PID;
                    localDW->temporalCounter_i1_n = 0U;

                    // Entry 'ADRC2PID': '<S118>:61'
                    localDW->EnablePID = true;
                }
            }

            // End of Chart: '<S115>/ControlLogic'

            // Outputs for Enabled SubSystem: '<S115>/ADRC' incorporates:
            //   EnablePort: '<S117>/Enable'

            if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
                if (localDW->EnableADRC) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(localDW->ADRC_MODE) ^ 1))) {
                        // InitializeConditions for Integrator: '<S121>/Integrator' 
                        localX->Integrator_CSTATE[0] = 0.0;
                        localX->Integrator_CSTATE[1] = 0.0;
                        localX->Integrator_CSTATE[2] = 0.0;
                        localDW->ADRC_MODE = true;
                    }
                } else {
                    localDW->ADRC_MODE = false;
                }
            }

            // End of Outputs for SubSystem: '<S115>/ADRC'
        }

        // Outputs for Enabled SubSystem: '<S115>/ADRC' incorporates:
        //   EnablePort: '<S117>/Enable'

        if (localDW->ADRC_MODE) {
            // RateTransition: '<S117>/RThat_b' incorporates:
            //   RateTransition: '<S117>/RTomega_b'

            if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
                // RateTransition: '<S117>/RThat_b'
                localDW->RThat_b = *rtu_ParamADRC_hat_b;

                // RateTransition: '<S117>/RTomega_b'
                localDW->RTomega_b = *rtu_ParamADRC_omega_c;
            }

            // End of RateTransition: '<S117>/RThat_b'

            // MATLAB Function: '<S123>/Extended state feedback robust controller' 
            // MATLAB Function 'ADRC controller/State feedback robust controller/Extended state feedback robust controller': '<S127>:1' 
            // '<S127>:1:8'
            if (localDW->RThat_b == 0.0) {
                // '<S127>:1:17'
                // '<S127>:1:18'
                rtb_Sum_o = 1.0;
            } else {
                // '<S127>:1:20'
                rtb_Sum_o = localDW->RThat_b;
            }

            // '<S127>:1:9'
            if (localDW->RTomega_b == 0.0) {
                // '<S127>:1:17'
                // '<S127>:1:18'
                c_fid = 5.0;
            } else {
                // '<S127>:1:20'
                c_fid = localDW->RTomega_b;
            }

            // Product: '<S129>/Product' incorporates:
            //   Integrator: '<S121>/Integrator'
            //   MATLAB Function: '<S123>/Extended state feedback robust controller'
            //   Step: '<S129>/Step'

            // '<S127>:1:10'
            // '<S127>:1:25'
            // '<S127>:1:26'
            // '<S127>:1:12'
            rtb_Sum_o = ((c_fid * c_fid * localX->Integrator_CSTATE[0] + (c_fid
                           - (-c_fid)) * localX->Integrator_CSTATE[1]) +
                         localX->Integrator_CSTATE[2]) * (1.0 / rtb_Sum_o) *
                static_cast<real_T>(static_cast<int32_T>(static_cast<boolean_T>(
                static_cast<int32_T>(((*(Real2SimGuidance_M->
                timingBridge->taskTime
                [Real2SimGuidance_M->Timing.mdlref_GlobalTID[0]])) < 0.2) ^ 1))));

            // RateTransition: '<S117>/RTomega_o'
            if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
                // RateTransition: '<S117>/RTomega_o'
                localDW->RTomega_o = *rtu_ParamADRC_omega_o;
            }

            // End of RateTransition: '<S117>/RTomega_o'

            // MATLAB Function: '<S121>/Linear extended state observer' incorporates:
            //   Integrator: '<S121>/Integrator'

            // MATLAB Function 'ADRC controller/Linear extended state observer/Linear extended state observer': '<S124>:1' 
            // '<S124>:1:16'
            // '<S124>:1:10'
            if (localDW->RThat_b == 0.0) {
                // '<S124>:1:22'
                // '<S124>:1:23'
                c_fid = 1.0;
            } else {
                // '<S124>:1:25'
                c_fid = localDW->RThat_b;
            }

            // '<S124>:1:11'
            if (localDW->RTomega_o == 0.0) {
                // '<S124>:1:22'
                // '<S124>:1:23'
                d_fid = 25.0;
            } else {
                // '<S124>:1:25'
                d_fid = localDW->RTomega_o;
            }

            // '<S124>:1:13'
            // '<S124>:1:35'
            // '<S124>:1:14'
            // '<S124>:1:39'
            rtb_TmpSignalConversionAtSFunctionInport1[0] = 1.0;
            rtb_TmpSignalConversionAtSFunctionInport1[1] = d_fid;
            rtb_TmpSignalConversionAtSFunctionInport1[2] = d_fid * d_fid;
            for (loop_ub = 1; static_cast<int32_T>(loop_ub + 1) > 1; loop_ub =
                    static_cast<int32_T>(loop_ub - 1)) {
                rtb_TmpSignalConversionAtSFunctionInport1[loop_ub] -=
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(loop_ub - 1)] * -d_fid;
            }

            rtb_TmpSignalConversionAtSFunctionInport1[3] = d_fid *
                rtb_TmpSignalConversionAtSFunctionInport1[2];
            for (loop_ub = 2; static_cast<int32_T>(loop_ub + 1) > 1; loop_ub =
                    static_cast<int32_T>(loop_ub - 1)) {
                rtb_TmpSignalConversionAtSFunctionInport1[loop_ub] -=
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(loop_ub - 1)] * -d_fid;
            }

            // '<S124>:1:40'
            // '<S124>:1:16'
            d_fid = localDW->Gain - localX->Integrator_CSTATE[0];
            tmp_1[0] = 0.0 * rtb_Sum_o;
            tmp_1[1] = -c_fid * rtb_Sum_o;
            tmp_1[2] = 0.0 * rtb_Sum_o;
            for (i = 0; i < 3; i++) {
                a[i] = 0.0;
                a[i] += 0.0 * localX->Integrator_CSTATE[0];
                a[i] += static_cast<real_T>(a_0[static_cast<int32_T>(i + 3)]) *
                    localX->Integrator_CSTATE[1];
                a[i] += static_cast<real_T>(a_0[static_cast<int32_T>(i + 6)]) *
                    localX->Integrator_CSTATE[2];
                localDW->estimatedExtendedStateDerivative[i] =
                    rtb_TmpSignalConversionAtSFunctionInport1
                    [static_cast<int32_T>(i + 1)] * d_fid + (a[i] + tmp_1[i]);
            }

            // End of MATLAB Function: '<S121>/Linear extended state observer'

            // RateTransition: '<S117>/RThat_z' incorporates:
            //   Concatenate: '<S115>/Vector Concatenate'
            //   Integrator: '<S121>/Integrator'
            //   RateTransition: '<S117>/RTu'

            if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
                localDW->VectorConcatenate[0] = localX->Integrator_CSTATE[0];
                localDW->VectorConcatenate[1] = localX->Integrator_CSTATE[1];
                localDW->VectorConcatenate[2] = localX->Integrator_CSTATE[2];

                // RateTransition: '<S117>/RTu' incorporates:
                //   Concatenate: '<S115>/Vector Concatenate'
                //   Integrator: '<S121>/Integrator'

                localDW->RTu = rtb_Sum_o;
            }

            // End of RateTransition: '<S117>/RThat_z'
        }

        // End of Outputs for SubSystem: '<S115>/ADRC'
        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Outputs for Enabled SubSystem: '<S115>/PID' incorporates:
            //   EnablePort: '<S119>/Enable'

            if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
                if (localDW->EnablePID) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(localDW->PID_MODE) ^ 1))) {
                        // InitializeConditions for Delay: '<S158>/UD'
                        localDW->UD_DSTATE = 0.0;

                        // InitializeConditions for DiscreteIntegrator: '<S165>/Integrator' 
                        localDW->Integrator_DSTATE = 0.0;
                        localDW->PID_MODE = true;
                    }
                } else {
                    localDW->PID_MODE = false;
                }
            }

            if (localDW->PID_MODE) {
                // Product: '<S157>/DProd Out'
                rtb_Sum_o = localDW->Gain * *rtu_ParamADRC_D;

                // SampleTimeMath: '<S160>/Tsamp'
                //
                //  About '<S160>/Tsamp':
                //   y = u * K where K = 1 / ( w * Ts )

                localDW->Tsamp = rtb_Sum_o * 10.0;

                // Product: '<S162>/IProd Out'
                localDW->IProdOut = localDW->Gain * *rtu_ParamADRC_I;

                // Product: '<S170>/PProd Out'
                rtb_Sum_o = localDW->Gain * *rtu_ParamADRC_P;

                // Sum: '<S174>/Sum' incorporates:
                //   Delay: '<S158>/UD'
                //   DiscreteIntegrator: '<S165>/Integrator'
                //   Sum: '<S158>/Diff'

                localDW->Sum = (rtb_Sum_o + localDW->Integrator_DSTATE) +
                    (localDW->Tsamp - localDW->UD_DSTATE);
            }

            // End of Outputs for SubSystem: '<S115>/PID'

            // Switch: '<S115>/Switch'
            if (localDW->PID_U) {
                // Switch: '<S115>/Switch'
                localDW->Switch_p = localDW->Sum;
            } else {
                // Switch: '<S115>/Switch'
                localDW->Switch_p = localDW->RTu;
            }

            // End of Switch: '<S115>/Switch'

            // SignalConversion generated from: '<S115>/Vector Concatenate' incorporates:
            //   Concatenate: '<S115>/Vector Concatenate'

            localDW->VectorConcatenate[3] = localDW->Switch_p;

            // DataStoreWrite: '<S115>/WriteADRC_Log'
            localDW->ADRC_Log[0] = localDW->VectorConcatenate[0];
            localDW->ADRC_Log[1] = localDW->VectorConcatenate[1];
            localDW->ADRC_Log[2] = localDW->VectorConcatenate[2];
            localDW->ADRC_Log[3] = localDW->VectorConcatenate[3];
        }
    }

    // End of Outputs for SubSystem: '<S98>/SpdFBControl'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Sum: '<S98>/SumSpd'
        rtb_RefGndSpd = localDW->Switch_p + rtu_SimUAVState->AirSpeed;

        // Switch: '<S114>/Switch2' incorporates:
        //   DataStoreWrite: '<S98>/WriteRefGndSpd'
        //   RelationalOperator: '<S114>/LowerRelop1'

        if (rtb_RefGndSpd > fid) {
            localDW->RefGndSpd = fid;
        } else {
            // MinMax: '<S98>/Min'
            fid = std::fmin(localDW->SpeedLimit[0], localDW->SpeedLimit[1]);

            // Switch: '<S114>/Switch' incorporates:
            //   DataStoreWrite: '<S98>/WriteRefGndSpd'
            //   MinMax: '<S98>/Min'
            //   RelationalOperator: '<S114>/UpperRelop'

            if (rtb_RefGndSpd < fid) {
                localDW->RefGndSpd = fid;
            } else {
                localDW->RefGndSpd = rtb_RefGndSpd;
            }

            // End of Switch: '<S114>/Switch'
        }

        // End of Switch: '<S114>/Switch2'

        // Sum: '<S108>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/FrontBound'

        rtb_Sum_e = localDW->MatrixConcatenate[108] - rtu_SimUAVState->North;

        // DotProduct: '<S108>/Dot Product'
        rtb_Sum_o = rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S108>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/FrontBound'

        rtb_Sum_e = localDW->MatrixConcatenate[325] - rtu_SimUAVState->East;

        // DotProduct: '<S108>/Dot Product'
        rtb_Sum_o += rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S108>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/FrontBound'

        rtb_Sum_e = localDW->MatrixConcatenate[542] - rtu_SimUAVState->Height;

        // Sqrt: '<S108>/sqrt' incorporates:
        //   DotProduct: '<S108>/Dot Product'

        fid = std::sqrt(rtb_Sum_e * rtb_Sum_e + rtb_Sum_o);

        // Sum: '<S98>/ActRngmMinRng'
        rtb_Switch -= fid;

        // Sum: '<S98>/RefRngmMinRng'
        rtb_RefRngmMinRng = rtb_Abs1 - fid;

        // Sum: '<S98>/ComputeLB'
        rtb_LowerBound = fid - rtb_Abs1;

        // Sum: '<S109>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/TailBound'

        rtb_Sum_e = localDW->MatrixConcatenate[12] - rtu_SimUAVState->North;

        // DotProduct: '<S109>/Dot Product'
        rtb_Sum_o = rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S109>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/TailBound'

        rtb_Sum_e = localDW->MatrixConcatenate[229] - rtu_SimUAVState->East;

        // DotProduct: '<S109>/Dot Product'
        rtb_Sum_o += rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S109>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/TailBound'

        rtb_Sum_e = localDW->MatrixConcatenate[446] - rtu_SimUAVState->Height;

        // Sum: '<S98>/ComputeUB' incorporates:
        //   DotProduct: '<S109>/Dot Product'
        //   Sqrt: '<S109>/sqrt'

        rtb_UpperBound = std::sqrt(rtb_Sum_e * rtb_Sum_e + rtb_Sum_o) - rtb_Abs1;

        // Outputs for Enabled SubSystem: '<S98>/EnableBias' incorporates:
        //   EnablePort: '<S107>/Enable'

        // Math: '<S98>/Square' incorporates:
        //   Math: '<S107>/Square'

        rtb_UpperBound_e = rtb_RefRngmMinRng * rtb_RefRngmMinRng;

        // End of Outputs for SubSystem: '<S98>/EnableBias'

        // Product: '<S98>/DivideLB' incorporates:
        //   Bias: '<S98>/Bias'
        //   Math: '<S98>/Square'

        fid = rtb_UpperBound_e / (rtb_RefRngmMinRng + 10.0);

        // Switch: '<S98>/Switch' incorporates:
        //   RelationalOperator: '<S98>/GreaterThanOrEqual'

        if (rtb_Switch >= fid) {
            // Switch: '<S98>/Switch'
            Switch = rtb_Switch;
        } else {
            // Switch: '<S98>/Switch'
            Switch = fid;
        }

        // End of Switch: '<S98>/Switch'

        // Outputs for Enabled SubSystem: '<S98>/EnableBias' incorporates:
        //   EnablePort: '<S107>/Enable'

        if (Switch > 0.0) {
            // Sum: '<S107>/biasHm70' incorporates:
            //   Product: '<S107>/Divide'

            localDW->biasHm70 = rtb_UpperBound_e / Switch - rtb_RefRngmMinRng;
        }

        // End of Outputs for SubSystem: '<S98>/EnableBias'

        // Sum: '<S110>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/L1FrontBound'

        rtb_Sum_e = localDW->MatrixConcatenate[78] - rtu_SimUAVState->North;

        // DotProduct: '<S110>/Dot Product'
        rtb_Sum_o = rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S110>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/L1FrontBound'

        rtb_Sum_e = localDW->MatrixConcatenate[295] - rtu_SimUAVState->East;

        // DotProduct: '<S110>/Dot Product'
        rtb_Sum_o += rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S110>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/L1FrontBound'

        rtb_Sum_e = localDW->MatrixConcatenate[512] - rtu_SimUAVState->Height;

        // Sum: '<S98>/L1ComputeLB' incorporates:
        //   DotProduct: '<S110>/Dot Product'
        //   Sqrt: '<S110>/sqrt'

        Switch = std::sqrt(rtb_Sum_e * rtb_Sum_e + rtb_Sum_o) - rtb_Abs1;

        // Sum: '<S111>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/L1TailBound'

        rtb_Sum_e = localDW->MatrixConcatenate[42] - rtu_SimUAVState->North;

        // DotProduct: '<S111>/Dot Product'
        rtb_Sum_o = rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S111>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/L1TailBound'

        rtb_Sum_e = localDW->MatrixConcatenate[259] - rtu_SimUAVState->East;

        // DotProduct: '<S111>/Dot Product'
        rtb_Sum_o += rtb_Sum_e * rtb_Sum_e;

        // Sum: '<S111>/Sum' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S98>/L1TailBound'

        rtb_Sum_e = localDW->MatrixConcatenate[476] - rtu_SimUAVState->Height;

        // Sum: '<S98>/L1ComputeUB' incorporates:
        //   DotProduct: '<S111>/Dot Product'
        //   Sqrt: '<S111>/sqrt'

        rtb_UpperBound_e = std::sqrt(rtb_Sum_e * rtb_Sum_e + rtb_Sum_o) -
            rtb_Abs1;

        // Outputs for Atomic SubSystem: '<S9>/MaxBrake'
        // Sum: '<S104>/Sum'
        rtb_Sum_k[0] = rtu_SimUAVState->North -
            rtb_FixedWingGuidanceStateBus.North;
        rtb_Sum_k[1] = rtu_SimUAVState->East -
            rtb_FixedWingGuidanceStateBus.East;
        rtb_Sum_k[2] = rtu_SimUAVState->Height - rtb_Switch_b;

        // Outputs for Atomic SubSystem: '<S9>/HeadingLogic'
        // Outputs for Atomic SubSystem: '<S94>/NewMissionHdg'
        // Product: '<S96>/BrkRng' incorporates:
        //   Constant: '<S96>/SampleTime'
        //   Gain: '<S100>/Ts'

        rtb_Sum_e = rtu_SimUAVState->AirSpeed * 0.1;

        // End of Outputs for SubSystem: '<S94>/NewMissionHdg'
        // End of Outputs for SubSystem: '<S9>/HeadingLogic'

        // Sum: '<S96>/Minus' incorporates:
        //   Constant: '<S96>/TrackDP'
        //   DotProduct: '<S104>/Dot Product'
        //   Product: '<S96>/BrkRng'
        //   Sqrt: '<S104>/sqrt'

        rtb_Switch = std::sqrt((rtb_Sum_k[0] * rtb_Sum_k[0] + rtb_Sum_k[1] *
                                rtb_Sum_k[1]) + rtb_Sum_k[2] * rtb_Sum_k[2]) -
            rtb_Sum_e * 132.0;

        // Switch: '<S96>/BrkSwitch' incorporates:
        //   Constant: '<S96>/MaxBrake'
        //   Sum: '<S98>/Sum'

        if (rtb_Switch >= 0.0) {
            rtb_RefRngmMinRng = rtb_Sum1_idx_1 + rtb_RefGndSpd;
        } else {
            rtb_RefRngmMinRng = 0.0;
        }

        // End of Switch: '<S96>/BrkSwitch'

        // Gain: '<S96>/Gain'
        rtb_Gain_p = -rtb_Switch;

        // MATLAB Function: '<S96>/getSpeedLimit'
        // MATLAB Function 'Real2SimNav/MaxBrake/getSpeedLimit': '<S106>:1'
        // '<S106>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->SingletonInstance_not_empty_b) ^ 1))) {
            localDW->SingletonInstance.AirSpeed = 35.0;
            localDW->SingletonInstance.MaxRollAngle = 0.3490658503988659;
            localDW->SingletonInstance.FlightPathAngleLimit[0] = -0.175;
            localDW->SingletonInstance.FlightPathAngleLimit[1] = 0.175;
            localDW->SingletonInstance.SpdLmt[0] = 29.0;
            localDW->SingletonInstance.SpdLmt[1] = 46.0;
            ret->size[0] = 1;
            ret->size[1] = 0;
            fid = Real2SimGuidance_fileManager_d(localDW);
            if (fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j0(fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_i(fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_n, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_o, 2);
                Real2SimGuidance_emxInit_char_T(&data_9, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_9->size[0] *
                        data_9->size[1]);
                    data_9->size[0] = 1;
                    data_9->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_9,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_9->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_9, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_o);
                    Real2SimGuidance_strtrim(tmp_o, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    nx = 0;
                                    b = 0;
                                } else {
                                    nx = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - nx);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(nx + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_n);
                                Real2SimGuidance_strtrim(tmp_n, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_gh(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_9);
                Real2SimGuidance_emxFree_char_T(&tmp_o);
                Real2SimGuidance_emxFree_char_T(&tmp_n);
            }

            inputArg_data = Real2SimGuidance_str2double(ret);
            printf("Set UAV NormAirSpeed:\t\t%f\n", inputArg_data.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Sum_o = Real2SimGuidance_fileManager_d(localDW);
            if (rtb_Sum_o < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j0(rtb_Sum_o, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_i(rtb_Sum_o, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_l, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_m, 2);
                Real2SimGuidance_emxInit_char_T(&data_8, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_8->size[0] *
                        data_8->size[1]);
                    data_8->size[0] = 1;
                    data_8->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_8,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_8->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_8, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_m);
                    Real2SimGuidance_strtrim(tmp_m, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    nx = 0;
                                    b = 0;
                                } else {
                                    nx = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - nx);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(nx + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_l);
                                Real2SimGuidance_strtrim(tmp_l, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghb(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_8);
                Real2SimGuidance_emxFree_char_T(&tmp_m);
                Real2SimGuidance_emxFree_char_T(&tmp_l);
            }

            tmp_3 = Real2SimGuidance_str2double(ret);
            printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_3.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            c_fid = Real2SimGuidance_fileManager_d(localDW);
            if (c_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j0(c_fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_i(c_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_j, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_k, 2);
                Real2SimGuidance_emxInit_char_T(&data_7, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_7->size[0] *
                        data_7->size[1]);
                    data_7->size[0] = 1;
                    data_7->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_7,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_7->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_7, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_k);
                    Real2SimGuidance_strtrim(tmp_k, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    nx = 0;
                                } else {
                                    b = 1;
                                    nx = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(nx - b);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(b + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_j);
                                Real2SimGuidance_strtrim(tmp_j, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghbx(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_7);
                Real2SimGuidance_emxFree_char_T(&tmp_k);
                Real2SimGuidance_emxFree_char_T(&tmp_j);
            }

            tmp_4 = Real2SimGuidance_str2double(ret);
            printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_4.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            d_fid = Real2SimGuidance_fileManager_d(localDW);
            if (d_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j0(d_fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_i(d_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_h, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_i, 2);
                Real2SimGuidance_emxInit_char_T(&data_6, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_6->size[0] *
                        data_6->size[1]);
                    data_6->size[0] = 1;
                    data_6->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_6,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_6->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_6, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_i);
                    Real2SimGuidance_strtrim(tmp_i, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    nx = 0;
                                } else {
                                    b = 1;
                                    nx = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(nx - b);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(b + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_h);
                                Real2SimGuidance_strtrim(tmp_h, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghbx5(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_6);
                Real2SimGuidance_emxFree_char_T(&tmp_i);
                Real2SimGuidance_emxFree_char_T(&tmp_h);
            }

            tmp_5 = Real2SimGuidance_str2double(ret);
            d_fid = 0.017453292519943295 * tmp_5.re;
            printf("Set UAV MaxRollAngle:\t\t%f\n", d_fid);
            fflush(stdout);
            Real2SimGuidance_readINI_m(ret, localDW);
            tmp_5 = Real2SimGuidance_str2double(ret);
            rtb_Sum_o = 0.017453292519943295 * tmp_5.re;
            printf("Set UAV ClimbAngleLimit:\t%f\n", rtb_Sum_o);
            fflush(stdout);
            Real2SimGuidance_readINI_mh(ret, localDW);
            tmp_5 = Real2SimGuidance_str2double(ret);
            fid = 0.017453292519943295 * tmp_5.re;
            printf("Set UAV DiveAngleLimit:\t\t%f\n", fid);
            fflush(stdout);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(inputArg_data.re)) ^ 1))) {
                localDW->SingletonInstance.AirSpeed = inputArg_data.re;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(d_fid)) ^ 1))) {
                localDW->SingletonInstance.MaxRollAngle = d_fid;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Sum_o)) ^ 1))) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan(fid)) ^
                   1)))) {
                localDW->SingletonInstance.FlightPathAngleLimit[0] = fid;
                localDW->SingletonInstance.FlightPathAngleLimit[1] = rtb_Sum_o;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(tmp_3.re)) ^ 1))) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan
                    (tmp_4.re)) ^ 1)))) {
                localDW->SingletonInstance.SpdLmt[0] = tmp_4.re;
                localDW->SingletonInstance.SpdLmt[1] = tmp_3.re;
            }

            Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
                (&localDW->SingletonInstance.Connector,
                 localDW->SingletonInstance.AirSpeed,
                 localDW->SingletonInstance.MaxRollAngle);
            localDW->SingletonInstance_not_empty_b = true;
        }

        rtb_Abs1 = localDW->SingletonInstance.SpdLmt[0];
        rtb_Sum1_idx_1 = localDW->SingletonInstance.SpdLmt[1];

        // End of MATLAB Function: '<S96>/getSpeedLimit'

        // MinMax: '<S96>/Max'
        rtb_RefGndSpd = std::fmax(rtb_Abs1, rtb_Sum1_idx_1);

        // Switch: '<S105>/Switch2' incorporates:
        //   MinMax: '<S96>/Max'
        //   RelationalOperator: '<S105>/LowerRelop1'

        if (static_cast<boolean_T>(static_cast<int32_T>((rtb_RefRngmMinRng >
                rtb_RefGndSpd) ^ 1))) {
            // MinMax: '<S96>/Min'
            fid = std::fmin(rtb_Abs1, rtb_Sum1_idx_1);

            // Switch: '<S105>/Switch' incorporates:
            //   MinMax: '<S96>/Min'
            //   RelationalOperator: '<S105>/UpperRelop'

            if (rtb_RefRngmMinRng < fid) {
                rtb_RefGndSpd = fid;
            } else {
                rtb_RefGndSpd = rtb_RefRngmMinRng;
            }

            // End of Switch: '<S105>/Switch'
        }

        // End of Switch: '<S105>/Switch2'
        // End of Outputs for SubSystem: '<S9>/MaxBrake'

        // Outputs for Atomic SubSystem: '<S9>/HeadingLogic'
        // Gain: '<S94>/LookaheadT'
        rtb_Abs1 = 3.6 * rtu_SimUAVState->AirSpeed;

        // SignalConversion generated from: '<S94>/TrackSimPath'
        rtb_TmpSignalConversionAtSFunctionInport1[0] =
            rtb_FixedWingGuidanceStateBus.North;
        rtb_TmpSignalConversionAtSFunctionInport1[1] =
            rtb_FixedWingGuidanceStateBus.East;
        rtb_TmpSignalConversionAtSFunctionInport1[2] = rtb_Switch_b;
        rtb_TmpSignalConversionAtSFunctionInport1[3] =
            rtb_FixedWingGuidanceStateBus.HeadingAngle;

        // MATLABSystem: '<S94>/TrackSimPath' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   DataStoreWrite: '<S94>/WriteCrossTrackError'

        Real2SimGuidance_WaypointFollower_stepImpl(&localDW->obj,
            rtb_TmpSignalConversionAtSFunctionInport1,
            localDW->MatrixConcatenate, rtb_Abs1, rtb_Sum_k, &rtb_Switch,
            &rtb_RefRngmMinRng, &b_varargout_4, &localDW->CrossTrackError,
            &b_varargout_6, localDW);

        // RelationalOperator: '<S94>/Relational Operator' incorporates:
        //   DataStoreWrite: '<S94>/WriteCrossTrackError'
        //   Gain: '<S94>/Gain'

        rtb_RelationalOperator = (localDW->CrossTrackError <= 0.5 * rtb_Abs1);

        // Outputs for Atomic SubSystem: '<S94>/NewMissionHdg'
        // Outputs for Enabled SubSystem: '<S100>/CalForwardShift' incorporates:
        //   EnablePort: '<S102>/Enable'

        if (rtu_SimUAVState->AirSpeed > 0.0) {
            // Saturate: '<S100>/Saturation'
            if (rtb_Gain_p <= 0.0) {
                rtb_Abs1 = 0.0;
            } else {
                rtb_Abs1 = rtb_Gain_p;
            }

            // End of Saturate: '<S100>/Saturation'

            // Gain: '<S102>/Gain' incorporates:
            //   Product: '<S102>/Divide'

            localDW->Gain_b = rtb_Abs1 / rtu_SimUAVState->AirSpeed * 10.0;
        }

        // End of Outputs for SubSystem: '<S100>/CalForwardShift'

        // DiscreteIntegrator: '<S100>/Discrete-Time Integrator'
        if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                (localDW->DiscreteTimeIntegrator_PrevResetState) <= 0) &
                static_cast<int32_T>(*rtu_NewMission)))) {
            localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
        }

        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        }

        // RelationalOperator: '<S100>/GreaterThanOrEqual' incorporates:
        //   Constant: '<S100>/PenetrationDepthThreshold'
        //   Product: '<S100>/Product'

        rtb_GreaterThanOrEqual_h = (rtb_Gain_p >= rtb_Sum_e * 72.0);

        // Chart: '<S100>/MissionSwitchInitialPersuit'
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
            // Transition: '<S103>:14'
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S103>:12'
            localDW->SimHdg = 1.0;
        } else if (localDW->is_c3_Real2SimGuidance ==
                   Real2SimGuidance_IN_Initial) {
            // During 'Initial': '<S103>:12'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((localDW->temporalCounter_i1 >= 216U) &
                                        (static_cast<int32_T>(rtb_Memory) != 0))))
            {
                // Transition: '<S103>:15'
                localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Normal;

                // Entry Internal 'Normal': '<S103>:13'
                // Transition: '<S103>:53'
                localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                // Entry 'SimPnt': '<S103>:37'
                localDW->SimHdg = 1.0;
            } else {
                localDW->SimHdg = 1.0;
            }

            // During 'Normal': '<S103>:13'
        } else if (*rtu_NewMission) {
            // Transition: '<S103>:16'
            // Exit Internal 'Normal': '<S103>:13'
            // Exit Internal 'Debounce': '<S103>:38'
            localDW->is_Debounce_m = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S103>:12'
            localDW->SimHdg = 1.0;
        } else {
            switch (localDW->is_Normal) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S103>:38'
                if (localDW->is_Debounce_m == Real2SimGuidance_IN_L1Hdg_n) {
                    // During 'L1Hdg': '<S103>:49'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                            10U) {
                        // Transition: '<S103>:46'
                        localDW->is_Debounce_m =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_Normal = Real2SimGuidance_IN_L1Hdg;

                        // Entry 'L1Hdg': '<S103>:42'
                        localDW->SimHdg = 0.0;
                    } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(static_cast<boolean_T>(
                                   static_cast<int32_T>(static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &
                                 static_cast<int32_T>(rtb_RelationalOperator))))
                    {
                        // Transition: '<S103>:50'
                        localDW->is_Debounce_m = Real2SimGuidance_IN_SimPnt_a;
                        localDW->temporalCounter_i2 = 0U;
                    }

                    // During 'SimPnt': '<S103>:44'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                           10U) {
                    // Transition: '<S103>:48'
                    localDW->is_Debounce_m = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                    // Entry 'SimPnt': '<S103>:37'
                    localDW->SimHdg = 1.0;
                } else if (rtb_GreaterThanOrEqual_h) {
                    // Transition: '<S103>:51'
                    localDW->is_Debounce_m = Real2SimGuidance_IN_L1Hdg_n;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              case Real2SimGuidance_IN_L1Hdg:
                // During 'L1Hdg': '<S103>:42'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (static_cast<boolean_T>(static_cast<
                        int32_T>(static_cast<int32_T>(rtb_GreaterThanOrEqual_h) ^
                                 1))) & static_cast<int32_T>
                                            (rtb_RelationalOperator)))) {
                    // Transition: '<S103>:45'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce_m = Real2SimGuidance_IN_SimPnt_a;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              default:
                // During 'SimPnt': '<S103>:37'
                if (rtb_GreaterThanOrEqual_h) {
                    // Transition: '<S103>:47'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce_m = Real2SimGuidance_IN_L1Hdg_n;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;
            }
        }

        // End of Chart: '<S100>/MissionSwitchInitialPersuit'

        // Logic: '<S100>/OR' incorporates:
        //   DataStoreWrite: '<S94>/WriteStatus_Log'
        //   MATLABSystem: '<S94>/TrackSimPath'

        localDW->HdgStatus_Log = static_cast<boolean_T>(static_cast<int32_T>((
            static_cast<int32_T>(b_varargout_6) != 0) | (localDW->SimHdg != 0.0)));

        // Selector: '<S94>/WayPoint3d3' incorporates:
        //   Constant: '<S100>/NewestPoint'
        //   DiscreteIntegrator: '<S100>/Discrete-Time Integrator'
        //   Gain: '<S100>/Gain'
        //   MinMax: '<S100>/Min'
        //   Rounding: '<S100>/Round'
        //   Sum: '<S100>/Minus'

        i = static_cast<int32_T>(std::fmin(217.0, std::round((217.0 -
            localDW->DiscreteTimeIntegrator_DSTATE) + 1.5 * localDW->Gain_b)));

        // End of Outputs for SubSystem: '<S94>/NewMissionHdg'

        // Trigonometry: '<S101>/HdgCmd' incorporates:
        //   Concatenate: '<S93>/Matrix Concatenate'
        //   Selector: '<S94>/WayPoint3d3'
        //   Sum: '<S101>/EastArrow'
        //   Sum: '<S101>/NorthArrow'

        rtb_Abs1 = rt_atan2d_snf(localDW->MatrixConcatenate[static_cast<int32_T>
            (i + 216)] - rtb_FixedWingGuidanceStateBus.East,
            localDW->MatrixConcatenate[static_cast<int32_T>(i - 1)] -
            rtb_FixedWingGuidanceStateBus.North);

        // Switch: '<S94>/SwitchDesiredYaw' incorporates:
        //   DataStoreWrite: '<S94>/WriteStatus_Log'
        //   MATLABSystem: '<S94>/TrackSimPath'
        //   Switch: '<S94>/SwitchLookAheadNED'
        //   Switch: '<S94>/SwitchTargetHDG'

        if (localDW->HdgStatus_Log) {
            rtb_RefRngmMinRng = rtb_Abs1;

            // Switch: '<S94>/SwitchLookAheadNED' incorporates:
            //   Concatenate: '<S93>/Matrix Concatenate'
            //   Selector: '<S94>/WayPoint3d3'

            localDW->SwitchLookAheadNED[0] = localDW->MatrixConcatenate[
                static_cast<int32_T>(i - 1)];
            localDW->SwitchLookAheadNED[1] = localDW->MatrixConcatenate[
                static_cast<int32_T>(i + 216)];
            localDW->SwitchLookAheadNED[2] = localDW->MatrixConcatenate[
                static_cast<int32_T>(i + 433)];
        } else {
            // Switch: '<S94>/SwitchLookAheadNED' incorporates:
            //   MATLABSystem: '<S94>/TrackSimPath'

            localDW->SwitchLookAheadNED[0] = rtb_Sum_k[0];
            localDW->SwitchLookAheadNED[1] = rtb_Sum_k[1];
            localDW->SwitchLookAheadNED[2] = rtb_Sum_k[2];
            rtb_Abs1 = rtb_Switch;
        }

        // End of Switch: '<S94>/SwitchDesiredYaw'
        // End of Outputs for SubSystem: '<S9>/HeadingLogic'

        // DataStoreWrite: '<S9>/WriteHeading_Log' incorporates:
        //   MATLAB Function: '<S9>/AngLog'

        // MATLAB Function 'Real2SimNav/AngLog': '<S89>:1'
        // '<S89>:1:2'
        // '<S89>:1:3'
        // '<S89>:1:4'
        localDW->Heading_Log[0] = angdiff_WJjwZrD2
            (rtb_FixedWingGuidanceStateBus.HeadingAngle, rtb_Abs1);
        localDW->Heading_Log[1] = angdiff_WJjwZrD2(0.0,
            rtb_FixedWingGuidanceStateBus.HeadingAngle);
        localDW->Heading_Log[2] = angdiff_WJjwZrD2(0.0, rtb_Abs1);
    }

    // End of Outputs for SubSystem: '<S9>/SpeedControl'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // DataStoreWrite: '<S9>/WritebiasH_Log' incorporates:
        //   Integrator: '<S99>/TD_Alt'

        localDW->biasH_Log = localX->TD_Alt_CSTATE;

        // Chart: '<S9>/Chart'
        // Gateway: Real2SimNav/Chart
        // During: Real2SimNav/Chart
        if (static_cast<uint32_T>(localDW->is_active_c2_Real2SimGuidance) == 0U)
        {
            // Entry: Real2SimNav/Chart
            localDW->is_active_c2_Real2SimGuidance = 1U;

            // Entry Internal: Real2SimNav/Chart
            // Transition: '<S90>:6'
            localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

            // Entry 'hasBias': '<S90>:5'
            // Switch: '<S9>/BiasHSwitch' incorporates:
            //   Gain: '<S9>/Gain'
            //   Product: '<S9>/Product'

            localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
        } else if (localDW->is_c2_Real2SimGuidance == Real2SimGuidance_IN_NoBias)
        {
            // During 'NoBias': '<S90>:7'
            if (*rtu_NewMission) {
                // Transition: '<S90>:9'
                localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

                // Entry 'hasBias': '<S90>:5'
                // Switch: '<S9>/BiasHSwitch' incorporates:
                //   Gain: '<S9>/Gain'
                //   Product: '<S9>/Product'

                localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
            } else {
                // Switch: '<S9>/BiasHSwitch' incorporates:
                //   Constant: '<S9>/ZeroBias'

                localDW->BiasHSwitch = 0.0;
            }

            // During 'hasBias': '<S90>:5'
        } else if (localDW->EngagedFlag > 1.0) {
            // Transition: '<S90>:8'
            localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NoBias;

            // Entry 'NoBias': '<S90>:7'
            // Switch: '<S9>/BiasHSwitch' incorporates:
            //   Constant: '<S9>/ZeroBias'

            localDW->BiasHSwitch = 0.0;
        } else {
            // Switch: '<S9>/BiasHSwitch' incorporates:
            //   Gain: '<S9>/Gain'
            //   Product: '<S9>/Product'

            localDW->BiasHSwitch = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
        }

        // End of Chart: '<S9>/Chart'

        // RelationalOperator: '<S91>/Compare' incorporates:
        //   Constant: '<S91>/Constant'

        localDW->Compare = (rtb_Gain_p < 0.0);

        // Truth Table: '<S9>/Engagement' incorporates:
        //   DataStoreRead: '<S9>/ReadLagDistance'
        //   DataStoreWrite: '<S94>/WriteCrossTrackError'

        // Truth Table Function 'Real2SimNav/Engagement': '<S92>:1'
        //  Front Distance within L1 Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_UpperBound_e) & (localDW->LagDistance > Switch)))) {
            // Condition '#1': '<S92>:1:11'
            rtb_RelationalOperator = true;
        } else {
            rtb_RelationalOperator = false;
        }

        //  Front Distance within L0 Upper &  Lower Bound
        if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
                rtb_UpperBound) & (localDW->LagDistance > rtb_LowerBound)))) {
            // Condition '#2': '<S92>:1:15'
            rtb_GreaterThanOrEqual_h = true;
        } else {
            rtb_GreaterThanOrEqual_h = false;
        }

        //  CrossTrack Error within L1 Bound
        // Condition '#3': '<S92>:1:19'
        //  CrossTrack Error within L0 Bound
        // Condition '#4': '<S92>:1:23'
        if (rtb_RelationalOperator && (localDW->CrossTrackError < std::abs
                (rtb_UpperBound_e - Switch) / 2.0)) {
            // Decision 'D1': '<S92>:1:25'
            //  Real UAV Deeply Engaged with Simulation UAV
            // Action '1': '<S92>:1:37'
            localDW->Engaged = 2U;
        } else if (rtb_GreaterThanOrEqual_h) {
            if (localDW->CrossTrackError < std::abs(rtb_UpperBound -
                    rtb_LowerBound) / 2.0) {
                // Decision 'D2': '<S92>:1:27'
                //  Real UAV Engaged with Simulation UAV
                // Action '2': '<S92>:1:43'
                localDW->Engaged = 1U;
            } else {
                // Decision 'D3': '<S92>:1:29'
                //  Default
                //  Real UAV Not Engaged with Simulation UAV
                // Action '3': '<S92>:1:49'
                localDW->Engaged = 0U;
            }
        } else {
            // Decision 'D3': '<S92>:1:29'
            //  Default
            //  Real UAV Not Engaged with Simulation UAV
            // Action '3': '<S92>:1:49'
            localDW->Engaged = 0U;
        }

        // End of Truth Table: '<S9>/Engagement'

        // Sum: '<S9>/SumBiasH' incorporates:
        //   Integrator: '<S99>/TD_Alt'
        //   Switch: '<S94>/SwitchLookAheadNED'

        rtb_SumBiasH_idx_2 = localDW->SwitchLookAheadNED[2] +
            localX->TD_Alt_CSTATE;
    }

    // Integrator: '<S99>/dotAltTD'
    localDW->dotAltTD = localX->dotAltTD_CSTATE;

    // MATLAB Function: '<S99>/fhan_Alt' incorporates:
    //   Integrator: '<S99>/TD_Alt'
    //   SignalConversion generated from: '<S182>/ SFunction '
    //   Sum: '<S99>/Sum1'

    // MATLAB Function 'Real2SimNav/TD/fhan_Alt': '<S182>:1'
    // '<S182>:1:3'
    // '<S182>:1:4'
    // '<S182>:1:5'
    // '<S182>:1:6'
    // '<S182>:1:8'
    // '<S182>:1:9'
    rtb_UpperBound = localDW->dotAltTD * 0.1;

    // '<S182>:1:10'
    rtb_Abs1 = (localX->TD_Alt_CSTATE - localDW->BiasHSwitch) + rtb_UpperBound;

    // '<S182>:1:11'
    // '<S182>:1:12'
    if (std::isnan(rtb_Abs1)) {
        rtb_Switch = rtb_Abs1;
    } else if (rtb_Abs1 < 0.0) {
        rtb_Switch = -1.0;
    } else {
        rtb_Switch = static_cast<real_T>(rtb_Abs1 > 0.0);
    }

    Switch = (std::sqrt((8.0 * std::abs(rtb_Abs1) + 0.004000000000000001) *
                        0.004000000000000001) - 0.004000000000000001) *
        rtb_Switch / 2.0 + rtb_UpperBound;

    // '<S182>:1:13'
    // '<S182>:1:14'
    if (std::isnan(rtb_Abs1 + 0.004000000000000001)) {
        rtb_Switch = rtb_Abs1 + 0.004000000000000001;
    } else if (rtb_Abs1 + 0.004000000000000001 < 0.0) {
        rtb_Switch = -1.0;
    } else {
        rtb_Switch = static_cast<real_T>(rtb_Abs1 + 0.004000000000000001 > 0.0);
    }

    if (std::isnan(rtb_Abs1 - 0.004000000000000001)) {
        rtb_LowerBound = rtb_Abs1 - 0.004000000000000001;
    } else if (rtb_Abs1 - 0.004000000000000001 < 0.0) {
        rtb_LowerBound = -1.0;
    } else {
        rtb_LowerBound = static_cast<real_T>(rtb_Abs1 - 0.004000000000000001 >
            0.0);
    }

    rtb_Abs1 = ((rtb_UpperBound + rtb_Abs1) - Switch) * ((rtb_Switch -
        rtb_LowerBound) / 2.0) + Switch;

    // '<S182>:1:15'
    // '<S182>:1:17'
    if (std::isnan(rtb_Abs1)) {
        rtb_UpperBound = rtb_Abs1;
    } else if (rtb_Abs1 < 0.0) {
        rtb_UpperBound = -1.0;
    } else {
        rtb_UpperBound = static_cast<real_T>(rtb_Abs1 > 0.0);
    }

    if (std::isnan(rtb_Abs1 + 0.004000000000000001)) {
        rtb_Switch = rtb_Abs1 + 0.004000000000000001;
    } else if (rtb_Abs1 + 0.004000000000000001 < 0.0) {
        rtb_Switch = -1.0;
    } else {
        rtb_Switch = static_cast<real_T>(rtb_Abs1 + 0.004000000000000001 > 0.0);
    }

    if (std::isnan(rtb_Abs1 - 0.004000000000000001)) {
        rtb_LowerBound = rtb_Abs1 - 0.004000000000000001;
    } else if (rtb_Abs1 - 0.004000000000000001 < 0.0) {
        rtb_LowerBound = -1.0;
    } else {
        rtb_LowerBound = static_cast<real_T>(rtb_Abs1 - 0.004000000000000001 >
            0.0);
    }

    localDW->fh = (rtb_Abs1 / 0.004000000000000001 - rtb_UpperBound) * -0.4 *
        ((rtb_Switch - rtb_LowerBound) / 2.0) - 0.4 * rtb_UpperBound;

    // End of MATLAB Function: '<S99>/fhan_Alt'
    // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        boolean_T rEQ0;
        boolean_T rtb_Compare_i;

        // Chart: '<Root>/TASgreaterthan15for1Sec'
        // Gateway: TASgreaterthan15for1Sec
        // During: TASgreaterthan15for1Sec
        if (static_cast<uint32_T>(localDW->is_active_c16_Real2SimGuidance) == 0U)
        {
            // Entry: TASgreaterthan15for1Sec
            localDW->is_active_c16_Real2SimGuidance = 1U;

            // Entry Internal: TASgreaterthan15for1Sec
            // Transition: '<S11>:3'
            localDW->durationCounter_1 = 0;
            localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NotTakeOff;

            // Entry 'NotTakeOff': '<S11>:2'
            rtb_RelationalOperator = false;
        } else if (localDW->is_c16_Real2SimGuidance == Real2SimGuidance_IN_InAir)
        {
            // During 'InAir': '<S11>:4'
            rtb_RelationalOperator = true;
        } else {
            // During 'NotTakeOff': '<S11>:2'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((rtb_FixedWingGuidanceStateBus.AirSpeed >
                   15.0) & (rtu_StateFCU->RealUAVState.Height_meter > 30.0)))) {
                // '<S11>:5:2'
                rtb_RelationalOperator = true;
            } else {
                rtb_RelationalOperator = false;
            }

            // '<S11>:5:2'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_RelationalOperator) ^ 1))) {
                localDW->durationCounter_1 = 0;
            }

            if (localDW->durationCounter_1 > 10) {
                // Transition: '<S11>:5'
                localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_InAir;

                // Entry 'InAir': '<S11>:4'
                rtb_RelationalOperator = true;
            } else {
                rtb_RelationalOperator = false;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((rtb_FixedWingGuidanceStateBus.AirSpeed >
                15.0) & (rtu_StateFCU->RealUAVState.Height_meter > 30.0)))) {
            // '<S11>:5:2'
            rtb_GreaterThanOrEqual_h = true;
        } else {
            rtb_GreaterThanOrEqual_h = false;
        }

        // '<S11>:5:2'
        if (rtb_GreaterThanOrEqual_h) {
            localDW->durationCounter_1 = static_cast<int32_T>
                (localDW->durationCounter_1 + 1);
        } else {
            localDW->durationCounter_1 = 0;
        }

        // End of Chart: '<Root>/TASgreaterthan15for1Sec'

        // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
        //   EnablePort: '<S3>/Enable'

        if (rtb_RelationalOperator) {
            // SignalConversion generated from: '<S3>/InPlace'
            *rty_EngagedFlag = localDW->Engaged;
        }

        // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'

        // Chart: '<Root>/EngagementDebouncer'
        if (static_cast<uint32_T>(localDW->temporalCounter_i1_i) < 1023U) {
            localDW->temporalCounter_i1_i = static_cast<uint16_T>(static_cast<
                uint32_T>(static_cast<uint32_T>(localDW->temporalCounter_i1_i) +
                          1U));
        }

        if (static_cast<uint32_T>(localDW->temporalCounter_i2_f) < 63U) {
            localDW->temporalCounter_i2_f = static_cast<uint8_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i2_f) + 1U));
        }

        // Gateway: EngagementDebouncer
        // During: EngagementDebouncer
        if (static_cast<uint32_T>(localDW->is_active_c34_Real2SimGuidance) == 0U)
        {
            // Entry: EngagementDebouncer
            localDW->is_active_c34_Real2SimGuidance = 1U;

            // Entry Internal: EngagementDebouncer
            // Transition: '<S4>:97'
            localDW->is_c34_Real2SimGuidance = Real2SimGuidance_IN_Persuit;

            // Entry 'Persuit': '<S4>:95'
            localDW->Execution = 0.0;

            // Entry Internal 'Persuit': '<S4>:95'
            // Transition: '<S4>:100'
            localDW->is_Persuit = Real2SimGuidance_IN_Normal;
        } else {
            switch (localDW->is_c34_Real2SimGuidance) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S4>:90'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_i) >= 180U)
                {
                    // Transition: '<S4>:93'
                    // Exit Internal 'Debounce': '<S4>:90'
                    localDW->is_Debounce_m4 =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Persuit;

                    // Entry 'Persuit': '<S4>:95'
                    localDW->Execution = 0.0;
                    localDW->is_Persuit = Real2SimGuidance_IN_Fault;
                    localDW->temporalCounter_i1_i = 0U;

                    // Entry 'Fault': '<S4>:94'
                } else if (localDW->is_Debounce_m4 == Real2SimGuidance_IN_Off) {
                    // During 'Off': '<S4>:103'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2_f) >=
                            40U) {
                        // Transition: '<S4>:87'
                        localDW->is_Debounce_m4 =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_c34_Real2SimGuidance =
                            Real2SimGuidance_IN_Persuit;

                        // Entry 'Persuit': '<S4>:95'
                        localDW->Execution = 0.0;

                        // Entry Internal 'Persuit': '<S4>:95'
                        // Transition: '<S4>:100'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    } else if (static_cast<int32_T>(*rty_EngagedFlag) > 0) {
                        // Transition: '<S4>:102'
                        localDW->is_Debounce_m4 = Real2SimGuidance_IN_On;
                        localDW->temporalCounter_i2_f = 0U;
                    }

                    // During 'On': '<S4>:92'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2_f) >=
                           40U) {
                    // Transition: '<S4>:99'
                    localDW->is_Debounce_m4 =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_L0Engaged;

                    // Entry Internal 'L0Engaged': '<S4>:101'
                    // Transition: '<S4>:120'
                    localDW->is_L0Engaged = Real2SimGuidance_IN_L0Default;

                    // Entry 'L0Default': '<S4>:106'
                    localDW->Execution = 1.0;

                    // Entry Internal 'L0Default': '<S4>:106'
                    // Transition: '<S4>:108'
                    localDW->is_L0Default = Real2SimGuidance_IN_Normal;
                } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S4>:96'
                    localDW->is_Debounce_m4 = Real2SimGuidance_IN_Off;
                    localDW->temporalCounter_i2_f = 0U;
                }
                break;

              case Real2SimGuidance_IN_L0Engaged:
                // During 'L0Engaged': '<S4>:101'
                if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S4>:91'
                    // Exit Internal 'L0Engaged': '<S4>:101'
                    // Exit Internal 'Debounce': '<S4>:111'
                    localDW->is_Debounce_b = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

                    // Exit Internal 'L0Default': '<S4>:106'
                    localDW->is_L0Default = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_L0Engaged = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_i = 0U;
                    localDW->is_Debounce_m4 = Real2SimGuidance_IN_Off;
                    localDW->temporalCounter_i2_f = 0U;
                } else {
                    switch (localDW->is_L0Engaged) {
                      case Real2SimGuidance_IN_Debounce:
                        // During 'Debounce': '<S4>:111'
                        if (static_cast<uint32_T>(localDW->temporalCounter_i1_i)
                            >= 60U) {
                            // Transition: '<S4>:119'
                            // Exit Internal 'Debounce': '<S4>:111'
                            localDW->is_Debounce_b =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged =
                                Real2SimGuidance_IN_L0Default;

                            // Entry 'L0Default': '<S4>:106'
                            localDW->Execution = 1.0;
                            localDW->is_L0Default = Real2SimGuidance_IN_Fault;
                            localDW->temporalCounter_i1_i = 0U;

                            // Entry 'Fault': '<S4>:109'
                        } else if (localDW->is_Debounce_b ==
                                   Real2SimGuidance_IN_Off) {
                            // During 'Off': '<S4>:114'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i2_f) >= 30U) {
                                // Transition: '<S4>:122'
                                localDW->is_Debounce_b =
                                    Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                                localDW->is_L0Engaged =
                                    Real2SimGuidance_IN_L0Default;

                                // Entry 'L0Default': '<S4>:106'
                                localDW->Execution = 1.0;

                                // Entry Internal 'L0Default': '<S4>:106'
                                // Transition: '<S4>:108'
                                localDW->is_L0Default =
                                    Real2SimGuidance_IN_Normal;
                            } else if (static_cast<int32_T>(*rty_EngagedFlag) >
                                       1) {
                                // Transition: '<S4>:115'
                                localDW->is_Debounce_b = Real2SimGuidance_IN_On;
                                localDW->temporalCounter_i2_f = 0U;
                            }

                            // During 'On': '<S4>:113'
                        } else if (static_cast<uint32_T>
                                   (localDW->temporalCounter_i2_f) >= 30U) {
                            // Transition: '<S4>:118'
                            localDW->is_Debounce_b =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged =
                                Real2SimGuidance_IN_L1Engaged;

                            // Entry 'L1Engaged': '<S4>:112'
                            localDW->Execution = 2.0;
                        } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 1)
                        {
                            // Transition: '<S4>:116'
                            localDW->is_Debounce_b = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_f = 0U;
                        }
                        break;

                      case Real2SimGuidance_IN_L0Default:
                        localDW->Execution = 1.0;

                        // During 'L0Default': '<S4>:106'
                        if (localDW->is_L0Default == Real2SimGuidance_IN_Fault)
                        {
                            // During 'Fault': '<S4>:109'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i1_i) >= 600U) {
                                // Transition: '<S4>:107'
                                localDW->is_L0Default =
                                    Real2SimGuidance_IN_Normal;
                            }

                            // During 'Normal': '<S4>:110'
                        } else if (static_cast<int32_T>(*rty_EngagedFlag) > 1) {
                            // Transition: '<S4>:117'
                            localDW->is_L0Default =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged = Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1_i = 0U;
                            localDW->is_Debounce_b = Real2SimGuidance_IN_On;
                            localDW->temporalCounter_i2_f = 0U;
                        }
                        break;

                      default:
                        localDW->Execution = 2.0;

                        // During 'L1Engaged': '<S4>:112'
                        if (static_cast<int32_T>(*rty_EngagedFlag) <= 1) {
                            // Transition: '<S4>:121'
                            localDW->is_L0Engaged = Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1_i = 0U;
                            localDW->is_Debounce_b = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_f = 0U;
                        }
                        break;
                    }
                }
                break;

              default:
                localDW->Execution = 0.0;

                // During 'Persuit': '<S4>:95'
                if (localDW->is_Persuit == Real2SimGuidance_IN_Fault) {
                    // During 'Fault': '<S4>:94'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i1_i) >=
                            600U) {
                        // Transition: '<S4>:89'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    }

                    // During 'Normal': '<S4>:88'
                } else if (static_cast<boolean_T>(static_cast<int32_T>((
                              static_cast<int32_T>(*rty_EngagedFlag) > 0) &
                             static_cast<int32_T>(rtb_RelationalOperator)))) {
                    // Transition: '<S4>:98'
                    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_i = 0U;
                    localDW->is_Debounce_m4 = Real2SimGuidance_IN_On;
                    localDW->temporalCounter_i2_f = 0U;
                }
                break;
            }
        }

        // End of Chart: '<Root>/EngagementDebouncer'

        // DataStoreWrite: '<Root>/WriteEngagedFlag_Log'
        localDW->EngagedFlag = localDW->Execution;

        // Logic: '<Root>/NoNewMission'
        rtb_RelationalOperator = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(*rtu_NewMission) ^ 1));

        // Reshape: '<Root>/Reshape'
        rtb_Sum_k[0] = rtb_FixedWingGuidanceStateBus.North;
        rtb_Sum_k[1] = rtb_FixedWingGuidanceStateBus.East;
        rtb_Sum_k[2] = rtb_FixedWingGuidanceStateBus.HeadingAngle;

        // MATLAB Function: '<Root>/RepulDir' incorporates:
        //   Reshape: '<Root>/Reshape'

        // MATLAB Function 'RepulDir': '<S10>:1'
        if (static_cast<boolean_T>(static_cast<int32_T>((rtu_DngrListNER_DIMS1[0]
               != 0) & (rtu_DngrListNER_DIMS1[1] != 0)))) {
            // '<S10>:1:3'
            b = rtu_DngrListNER_DIMS1[0];
            rtu_DngrListNER_DIMS1_idx_0 = rtu_DngrListNER_DIMS1[0];
            loop_ub = rtu_DngrListNER_DIMS1[0];
            NormdNdE_size_idx_0 = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i < 2; i++) {
                for (nx = 0; nx <= static_cast<int32_T>(loop_ub - 1); nx++) {
                    NormdNdE_data[static_cast<int32_T>(nx + static_cast<int32_T>
                        (NormdNdE_size_idx_0 * i))] = (rtb_Sum_k[i] -
                        rtu_DngrListNER[static_cast<int32_T>(static_cast<int32_T>
                        (b * i) + nx)]) / rtu_DngrListNER[static_cast<int32_T>(
                        static_cast<int32_T>(rtu_DngrListNER_DIMS1_idx_0 << 1) +
                        nx)];
                }
            }

            // '<S10>:1:4'
            b = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(NormdNdE_size_idx_0 - 1); i++)
            {
                NormdNdE_data_0[i] = NormdNdE_data[i];
            }

            rtu_DngrListNER_DIMS1_idx_0 = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(NormdNdE_size_idx_0 - 1); i++)
            {
                NormdNdE_data_1[i] = NormdNdE_data[static_cast<int32_T>(i +
                    NormdNdE_size_idx_0)];
            }

            Real2SimGuidance_hypot_p(NormdNdE_data_0, &b, NormdNdE_data_1,
                &rtu_DngrListNER_DIMS1_idx_0, z_data, &z_size);
            for (i = 0; i <= static_cast<int32_T>(z_size - 1); i++) {
                x_data[i] = (z_data[i] < 1.0);
            }

            rtb_GreaterThanOrEqual_h = false;
            nx = 1;
            exitg1 = false;
            while ((!exitg1) && (nx <= z_size)) {
                if (x_data[static_cast<int32_T>(nx - 1)]) {
                    rtb_GreaterThanOrEqual_h = true;
                    exitg1 = true;
                } else {
                    nx = static_cast<int32_T>(nx + 1);
                }
            }

            // '<S10>:1:5'
            for (loop_ub = 0; loop_ub <= static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<int8_T>
                    (NormdNdE_size_idx_0)) - 1); loop_ub = static_cast<int32_T>
                    (loop_ub + 1)) {
                theta_data[loop_ub] = rt_atan2d_snf(NormdNdE_data
                    [static_cast<int32_T>(loop_ub + NormdNdE_size_idx_0)],
                    NormdNdE_data[loop_ub]);
            }

            // '<S10>:1:6'
            b = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(NormdNdE_size_idx_0 - 1); i++)
            {
                NormdNdE_data_0[i] = NormdNdE_data[i];
            }

            rtu_DngrListNER_DIMS1_idx_0 = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(NormdNdE_size_idx_0 - 1); i++)
            {
                NormdNdE_data_1[i] = NormdNdE_data[static_cast<int32_T>(i +
                    NormdNdE_size_idx_0)];
            }

            Real2SimGuidance_hypot_p(NormdNdE_data_0, &b, NormdNdE_data_1,
                &rtu_DngrListNER_DIMS1_idx_0, z_data, &z_size);
            for (i = 0; i <= static_cast<int32_T>(z_size - 1); i++) {
                z_data[i] = 1.0 / z_data[i];
            }

            // '<S10>:1:6'
            b = static_cast<int32_T>(static_cast<int8_T>(rtu_DngrListNER_DIMS1[0]));
            loop_ub = static_cast<int32_T>(static_cast<int8_T>
                (rtu_DngrListNER_DIMS1[0]));
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                NormdNdE_data_0[i] = theta_data[i];
            }

            for (nx = 0; nx <= static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int8_T>(NormdNdE_size_idx_0)) - 1); nx =
                    static_cast<int32_T>(nx + 1)) {
                NormdNdE_data_0[nx] = std::cos(NormdNdE_data_0[nx]);
            }

            rtu_DngrListNER_DIMS1_idx_0 = static_cast<int32_T>
                (static_cast<int8_T>(rtu_DngrListNER_DIMS1[0]));
            loop_ub = static_cast<int32_T>(static_cast<int8_T>
                (rtu_DngrListNER_DIMS1[0]));
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                NormdNdE_data_1[i] = theta_data[i];
            }

            for (nx = 0; nx <= static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int8_T>(NormdNdE_size_idx_0)) - 1); nx =
                    static_cast<int32_T>(nx + 1)) {
                NormdNdE_data_1[nx] = std::sin(NormdNdE_data_1[nx]);
            }

            // '<S10>:1:7'
            if (z_size == static_cast<int32_T>(static_cast<int8_T>
                    (rtu_DngrListNER_DIMS1[0]))) {
                for (i = 0; i <= static_cast<int32_T>(z_size - 1); i++) {
                    theta_data[i] = z_data[i] * NormdNdE_data_1[i];
                }

                for (i = 0; i <= static_cast<int32_T>(z_size - 1); i++) {
                    NormdNdE_data_1[i] = z_data[i] * NormdNdE_data_0[i];
                }

                rtb_Abs1 = rt_atan2d_snf(Real2SimGuidance_sum(theta_data,
                    &z_size), Real2SimGuidance_sum(NormdNdE_data_1, &z_size));
            } else {
                rtb_Abs1 = Real2SimGuidance_binary_expand_op_puh(z_data, &z_size,
                    NormdNdE_data_1, &rtu_DngrListNER_DIMS1_idx_0,
                    NormdNdE_data_0, &b);
            }
        } else {
            // '<S10>:1:9'
            rtb_Abs1 = rtb_FixedWingGuidanceStateBus.HeadingAngle;

            // '<S10>:1:10'
            rtb_GreaterThanOrEqual_h = false;
        }

        // End of MATLAB Function: '<Root>/RepulDir'

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Switch: '<S1>/SwitchLookAheadPoint' incorporates:
        //   BusCreator: '<S1>/BusCMD'
        //   Constant: '<S1>/AirSpd'

        if (rtu_ControlSwitch[0]) {
            rtb_UpperBound = rtu_ImmedGuidanceCMD->Height;
            rtb_LowerBound = rtu_ImmedGuidanceCMD->AirSpeed;
            rtb_RefRngmMinRng = rtu_ImmedGuidanceCMD->HeadingAngle;
        } else {
            rtb_UpperBound = rtb_SumBiasH_idx_2;
            rtb_LowerBound = 0.0;
        }

        // End of Switch: '<S1>/SwitchLookAheadPoint'

        // Outputs for Atomic SubSystem: '<S1>/CalTgtDir'
        // Sum: '<S14>/Minus' incorporates:
        //   Switch: '<S1>/SwitchLookAheadPoint'

        Switch = rtb_FixedWingGuidanceStateBus.HeadingAngle - rtb_RefRngmMinRng;

        // MATLAB Function: '<S14>/wrap2pi'
        // MATLAB Function 'AvoidDanger/CalTgtDir/wrap2pi': '<S18>:1'
        // '<S18>:1:3'
        if (std::abs(Switch) > 3.1415926535897931) {
            if (std::isnan(Switch + 3.1415926535897931)) {
                rtb_UpperBound_e = (rtNaN);
            } else if (std::isinf(Switch + 3.1415926535897931)) {
                rtb_UpperBound_e = (rtNaN);
            } else if (Switch + 3.1415926535897931 == 0.0) {
                rtb_UpperBound_e = 0.0;
            } else {
                rtb_UpperBound_e = std::fmod(Switch + 3.1415926535897931,
                    6.2831853071795862);
                rEQ0 = (rtb_UpperBound_e == 0.0);
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rEQ0) ^ 1))) {
                    rtb_Gain_p = std::abs((Switch + 3.1415926535897931) /
                                          6.2831853071795862);
                    rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs
                        (rtb_Gain_p - std::floor(rtb_Gain_p + 0.5)) >
                        2.2204460492503131E-16 * rtb_Gain_p) ^ 1));
                }

                if (rEQ0) {
                    rtb_UpperBound_e = 0.0;
                } else if (Switch + 3.1415926535897931 < 0.0) {
                    rtb_UpperBound_e += 6.2831853071795862;
                }
            }

            if (static_cast<boolean_T>(static_cast<int32_T>((Switch +
                    3.1415926535897931 > 0.0) & (rtb_UpperBound_e == 0.0)))) {
                rtb_UpperBound_e = 6.2831853071795862;
            }

            Switch = rtb_UpperBound_e - 3.1415926535897931;
        }

        // End of MATLAB Function: '<S14>/wrap2pi'
        // End of Outputs for SubSystem: '<S1>/CalTgtDir'

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/minus'
        localDW->SFunction_DIMS2[0] = rtu_PntCldData_DIMS1[0];
        localDW->SFunction_DIMS2[1] = rtu_PntCldData_DIMS1[1];
        loop_ub = static_cast<int32_T>(rtu_PntCldData_DIMS1[0] *
            rtu_PntCldData_DIMS1[1]);
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            localDW->y[i] = rtu_PntCldData[i];
        }

        // MATLAB Function 'AvoidDanger/ProcessCloudPoint/minus': '<S37>:1'
        if (static_cast<boolean_T>(static_cast<int32_T>((rtu_PntCldData_DIMS1[0]
               == 0) | (rtu_PntCldData_DIMS1[1] == 0)))) {
            // '<S37>:1:3'
            localDW->SFunction_DIMS2[0] = 0;
            localDW->SFunction_DIMS2[1] = 2;
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        Real2SimGuidance_emxInit_real_T(&tmp_0, 2);

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/minus' incorporates:
        //   Reshape: '<S16>/Reshape'

        // '<S37>:1:6'
        tmp_2[0] = rtb_FixedWingGuidanceStateBus.North;
        tmp_2[1] = rtb_FixedWingGuidanceStateBus.East;
        Real2SimGuidance_repmat(tmp_2, static_cast<real_T>
                                (localDW->SFunction_DIMS2[0]), tmp_0);

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        Real2SimGuidance_emxInit_real_T(&tmp, 2);

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/minus'
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((localDW->SFunction_DIMS2[0] == tmp_0->size
                [0]) & (localDW->SFunction_DIMS2[1] == 2)))) {
            NormdNdE_size_idx_0 = static_cast<int32_T>(tmp->size[0] * tmp->size
                [1]);
            tmp->size[0] = localDW->SFunction_DIMS2[0];
            tmp->size[1] = 2;
            Real2SimGuidance_emxEnsureCapacity_real_T(tmp, NormdNdE_size_idx_0);
            loop_ub = static_cast<int32_T>(localDW->SFunction_DIMS2[0] << 1);
            for (nx = 0; nx <= static_cast<int32_T>(loop_ub - 1); nx++) {
                tmp->data[nx] = localDW->y[nx] - tmp_0->data[nx];
            }
        } else {
            Real2SimGuidance_binary_expand_op_pu(tmp, localDW->y,
                localDW->SFunction_DIMS2, tmp_0);
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        Real2SimGuidance_emxFree_real_T(&tmp_0);

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/minus'
        localDW->SFunction_DIMS2[0] = tmp->size[0];
        localDW->SFunction_DIMS2[1] = tmp->size[1];
        loop_ub = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            localDW->y[i] = tmp->data[i];
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        Real2SimGuidance_emxFree_real_T(&tmp);
        Real2SimGuidance_emxInit_real_T(&NewPC, 2);

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLABSystem: '<S16>/Coordinate Transformation Conversion' incorporates:
        //   SignalConversion generated from: '<S16>/Coordinate Transformation Conversion'

        rtb_Sum_k[0] = std::cos(rtb_FixedWingGuidanceStateBus.HeadingAngle);
        rtb_UpperBound_e = std::sin(rtb_FixedWingGuidanceStateBus.HeadingAngle);

        // Selector: '<S16>/Selector' incorporates:
        //   MATLABSystem: '<S16>/Coordinate Transformation Conversion'

        rtb_TmpSignalConversionAtSFunctionInport1[0] = rtb_Sum_k[0];
        rtb_TmpSignalConversionAtSFunctionInport1[1] = rtb_UpperBound_e;
        rtb_TmpSignalConversionAtSFunctionInport1[2] = 0.0 * rtb_Sum_k[0] -
            rtb_UpperBound_e;
        rtb_TmpSignalConversionAtSFunctionInport1[3] = 0.0 * rtb_UpperBound_e +
            rtb_Sum_k[0];

        // MATLAB Function: '<S16>/MatrixProduct' incorporates:
        //   Selector: '<S16>/Selector'

        // MATLAB Function 'AvoidDanger/ProcessCloudPoint/MatrixProduct': '<S35>:1' 
        rtu_DngrListNER_DIMS1_idx_0 = localDW->SFunction_DIMS2[0];
        NormdNdE_size_idx_0 = static_cast<int32_T>(NewPC->size[0] * NewPC->size
            [1]);
        NewPC->size[0] = localDW->SFunction_DIMS2[0];
        NewPC->size[1] = 2;
        Real2SimGuidance_emxEnsureCapacity_real_T(NewPC, NormdNdE_size_idx_0);
        for (b = 0; b <= static_cast<int32_T>(rtu_DngrListNER_DIMS1_idx_0 - 1);
                b = static_cast<int32_T>(b + 1)) {
            NewPC->data[b] = 0.0;
        }

        for (loop_ub = 0; loop_ub <= static_cast<int32_T>
                (localDW->SFunction_DIMS2[1] - 1); loop_ub = static_cast<int32_T>
                (loop_ub + 1)) {
            nx = static_cast<int32_T>(loop_ub * localDW->SFunction_DIMS2[0]);
            rtb_UpperBound_e = rtb_TmpSignalConversionAtSFunctionInport1[loop_ub];
            for (NormdNdE_size_idx_0 = 1; static_cast<int32_T>
                    (NormdNdE_size_idx_0 - 1) <= static_cast<int32_T>
                    (rtu_DngrListNER_DIMS1_idx_0 - 1); NormdNdE_size_idx_0 =
                    static_cast<int32_T>(NormdNdE_size_idx_0 + 1)) {
                NewPC->data[static_cast<int32_T>(NormdNdE_size_idx_0 - 1)] +=
                    localDW->y[static_cast<int32_T>(static_cast<int32_T>(nx +
                    NormdNdE_size_idx_0) - 1)] * rtb_UpperBound_e;
            }
        }

        for (b = 0; b <= static_cast<int32_T>(rtu_DngrListNER_DIMS1_idx_0 - 1);
                b = static_cast<int32_T>(b + 1)) {
            NewPC->data[static_cast<int32_T>(rtu_DngrListNER_DIMS1_idx_0 + b)] =
                0.0;
        }

        for (loop_ub = 0; loop_ub <= static_cast<int32_T>
                (localDW->SFunction_DIMS2[1] - 1); loop_ub = static_cast<int32_T>
                (loop_ub + 1)) {
            nx = static_cast<int32_T>(loop_ub * localDW->SFunction_DIMS2[0]);
            rtb_UpperBound_e = rtb_TmpSignalConversionAtSFunctionInport1[
                static_cast<int32_T>(loop_ub + 2)];
            for (NormdNdE_size_idx_0 = 1; static_cast<int32_T>
                    (NormdNdE_size_idx_0 - 1) <= static_cast<int32_T>
                    (rtu_DngrListNER_DIMS1_idx_0 - 1); NormdNdE_size_idx_0 =
                    static_cast<int32_T>(NormdNdE_size_idx_0 + 1)) {
                i = static_cast<int32_T>(static_cast<int32_T>
                    (rtu_DngrListNER_DIMS1_idx_0 + NormdNdE_size_idx_0) - 1);
                NewPC->data[i] += localDW->y[static_cast<int32_T>(static_cast<
                    int32_T>(nx + NormdNdE_size_idx_0) - 1)] * rtb_UpperBound_e;
            }
        }

        // '<S35>:1:3'
        localDW->SFunction_DIMS2_c[0] = NewPC->size[0];
        localDW->SFunction_DIMS2_c[1] = 2;

        // Selector: '<S16>/SelectNorth' incorporates:
        //   MATLAB Function: '<S16>/MatrixProduct'

        localDW->SelectNorth_DIMS1[0] = localDW->SFunction_DIMS2_c[0];
        localDW->SelectNorth_DIMS1[1] = 1;
        nx = localDW->SFunction_DIMS2_c[0];
        for (i = 0; i <= static_cast<int32_T>(nx - 1); i++) {
            localDW->SelectNorth[i] = NewPC->data[i];
        }

        // End of Selector: '<S16>/SelectNorth'

        // Selector: '<S16>/SelectEast' incorporates:
        //   MATLAB Function: '<S16>/MatrixProduct'

        localDW->SelectEast_DIMS1[0] = localDW->SFunction_DIMS2_c[0];
        localDW->SelectEast_DIMS1[1] = 1;
        nx = localDW->SFunction_DIMS2_c[0];
        for (i = 0; i <= static_cast<int32_T>(nx - 1); i++) {
            localDW->SelectEast[i] = NewPC->data[static_cast<int32_T>(i +
                NewPC->size[0])];
        }

        // End of Selector: '<S16>/SelectEast'
        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        Real2SimGuidance_emxFree_real_T(&NewPC);
        Real2SimGuidance_emxInit_real_T(&AngSec, 1);
        Real2SimGuidance_emxInit_real_T(&catAngSec, 1);
        Real2SimGuidance_emxInit_real_T(&rtb_rho_0, 1);

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar' incorporates:
        //   Selector: '<S16>/SelectNorth'

        // MATLAB Function 'AvoidDanger/ProcessCloudPoint/Cartesian2Polar': '<S34>:1' 
        // '<S34>:1:3'
        rtb_SelectNorth_0.data = &localDW->SelectNorth[0];
        tmp_x = localDW->SelectNorth_DIMS1[0];

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        rtb_SelectNorth_0.size = &tmp_x;
        rtb_SelectNorth_0.allocatedSize = 1048576;
        rtb_SelectNorth_0.numDimensions = 1;
        rtb_SelectNorth_0.canFreeData = false;

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar' incorporates:
        //   Selector: '<S16>/SelectEast'

        rtb_SelectEast_0.data = &localDW->SelectEast[0];
        tmp_y = localDW->SelectEast_DIMS1[0];

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        rtb_SelectEast_0.size = &tmp_y;
        rtb_SelectEast_0.allocatedSize = 1048576;
        rtb_SelectEast_0.numDimensions = 1;
        rtb_SelectEast_0.canFreeData = false;

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar'
        Real2SimGuidance_cart2pol(&rtb_SelectNorth_0, &rtb_SelectEast_0, AngSec,
            catAngSec);

        // '<S34>:1:6'
        // '<S34>:1:7'
        // '<S34>:1:8'
        Real2SimGuidance_abs(AngSec, rtb_rho_0);

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        Real2SimGuidance_emxInit_boolean_T(&front, 1);

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar' incorporates:
        //   MATLAB Function: '<S16>/MatrixProduct'
        //   Sum: '<S15>/SumNorth'
        //   Sum: '<S98>/L1ComputeUB'

        if (rtb_rho_0->size[0] == catAngSec->size[0]) {
            NormdNdE_size_idx_0 = front->size[0];
            front->size[0] = rtb_rho_0->size[0];
            Real2SimGuidance_emxEnsureCapacity_boolean_T(front,
                NormdNdE_size_idx_0);
            loop_ub = rtb_rho_0->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                rtb_SumBiasH_idx_2 = catAngSec->data[i];
                front->data[i] = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>((rtb_SumBiasH_idx_2 <
                    1623.8550613183404) & (rtb_SumBiasH_idx_2 > 2.1)))) &
                    (rtb_rho_0->data[i] <= 2.0943951023931953)));
            }
        } else {
            Real2SimGuidance_binary_expand_op_p(front, rtb_rho_0,
                2.0943951023931953, catAngSec, rtCP_Cartesian2Polar_RngLmt);
        }

        nx = static_cast<int32_T>(front->size[0] - 1);
        b = 0;
        for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= nx;
                NormdNdE_size_idx_0 = static_cast<int32_T>(NormdNdE_size_idx_0 +
              1)) {
            if (front->data[NormdNdE_size_idx_0]) {
                b = static_cast<int32_T>(b + 1);
            }
        }

        localDW->SFunction_DIMS4 = b;
        b = 0;
        for (loop_ub = 0; loop_ub <= nx; loop_ub = static_cast<int32_T>(loop_ub
                + 1)) {
            if (front->data[loop_ub]) {
                // '<S34>:1:8'
                localDW->theta[b] = AngSec->data[loop_ub];
                b = static_cast<int32_T>(b + 1);
            }
        }

        // '<S34>:1:8'
        b = 0;
        for (loop_ub = 0; loop_ub <= nx; loop_ub = static_cast<int32_T>(loop_ub
                + 1)) {
            if (front->data[loop_ub]) {
                b = static_cast<int32_T>(b + 1);
            }
        }

        localDW->SFunction_DIMS3 = b;
        b = 0;
        for (loop_ub = 0; loop_ub <= nx; loop_ub = static_cast<int32_T>(loop_ub
                + 1)) {
            if (front->data[loop_ub]) {
                // '<S34>:1:8'
                localDW->rho[b] = catAngSec->data[loop_ub];
                b = static_cast<int32_T>(b + 1);
            }
        }

        if (localDW->SFunction_DIMS4 != 0) {
            // '<S34>:1:12'
            NormdNdE_size_idx_0 = front->size[0];
            front->size[0] = localDW->SFunction_DIMS4;
            Real2SimGuidance_emxEnsureCapacity_boolean_T(front,
                NormdNdE_size_idx_0);
            for (i = 0; i <= static_cast<int32_T>(localDW->SFunction_DIMS4 - 1);
                 i++) {
                front->data[i] = false;
            }

            // '<S34>:1:13'
            NormdNdE_size_idx_0 = AngSec->size[0];
            AngSec->size[0] = localDW->SFunction_DIMS4;
            Real2SimGuidance_emxEnsureCapacity_real_T(AngSec,
                NormdNdE_size_idx_0);
            for (i = 0; i <= static_cast<int32_T>(localDW->SFunction_DIMS4 - 1);
                 i++) {
                AngSec->data[i] = localDW->theta[i] / 0.034906585039886591;
            }

            nx = AngSec->size[0];
            for (loop_ub = 0; loop_ub <= static_cast<int32_T>(nx - 1); loop_ub =
                 static_cast<int32_T>(loop_ub + 1)) {
                AngSec->data[loop_ub] = std::round(AngSec->data[loop_ub]);
            }

            // '<S34>:1:13'
            Real2SimGuidance_unique_vector(AngSec, catAngSec);

            // '<S34>:1:14'
            b = 0;
            Real2SimGuidance_emxInit_boolean_T(&inRng, 1);
            Real2SimGuidance_emxInit_boolean_T(&b_0, 1);
            Real2SimGuidance_emxInit_int32_T(&c, 1);
            Real2SimGuidance_emxInit_int32_T(&d, 1);
            Real2SimGuidance_emxInit_real_T(&rtb_rho_1, 1);
            while (b <= static_cast<int32_T>(catAngSec->size[0] - 1)) {
                // '<S34>:1:14'
                // '<S34>:1:15'
                rtb_SumBiasH_idx_2 = catAngSec->data[b];
                NormdNdE_size_idx_0 = b_0->size[0];
                b_0->size[0] = AngSec->size[0];
                Real2SimGuidance_emxEnsureCapacity_boolean_T(b_0,
                    NormdNdE_size_idx_0);
                loop_ub = AngSec->size[0];

                // '<S34>:1:16'
                rtb_UpperBound_e = catAngSec->data[b];
                NormdNdE_size_idx_0 = inRng->size[0];
                inRng->size[0] = AngSec->size[0];
                Real2SimGuidance_emxEnsureCapacity_boolean_T(inRng,
                    NormdNdE_size_idx_0);
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    rtb_Switch = AngSec->data[i];
                    b_0->data[i] = (rtb_Switch == rtb_SumBiasH_idx_2);
                    inRng->data[i] = (rtb_Switch == rtb_UpperBound_e);
                }

                nx = static_cast<int32_T>(b_0->size[0] - 1);
                loop_ub = 0;
                for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= nx;
                        NormdNdE_size_idx_0 = static_cast<int32_T>
                        (NormdNdE_size_idx_0 + 1)) {
                    if (b_0->data[NormdNdE_size_idx_0]) {
                        loop_ub = static_cast<int32_T>(loop_ub + 1);
                    }
                }

                NormdNdE_size_idx_0 = c->size[0];
                c->size[0] = loop_ub;
                Real2SimGuidance_emxEnsureCapacity_int32_T(c,
                    NormdNdE_size_idx_0);
                loop_ub = 0;
                for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= nx;
                        NormdNdE_size_idx_0 = static_cast<int32_T>
                        (NormdNdE_size_idx_0 + 1)) {
                    if (b_0->data[NormdNdE_size_idx_0]) {
                        c->data[loop_ub] = static_cast<int32_T>
                            (NormdNdE_size_idx_0 + 1);
                        loop_ub = static_cast<int32_T>(loop_ub + 1);
                    }
                }

                nx = static_cast<int32_T>(inRng->size[0] - 1);
                loop_ub = 0;
                for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= nx;
                        NormdNdE_size_idx_0 = static_cast<int32_T>
                        (NormdNdE_size_idx_0 + 1)) {
                    if (inRng->data[NormdNdE_size_idx_0]) {
                        loop_ub = static_cast<int32_T>(loop_ub + 1);
                    }
                }

                NormdNdE_size_idx_0 = d->size[0];
                d->size[0] = loop_ub;
                Real2SimGuidance_emxEnsureCapacity_int32_T(d,
                    NormdNdE_size_idx_0);
                loop_ub = 0;
                for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= nx;
                        NormdNdE_size_idx_0 = static_cast<int32_T>
                        (NormdNdE_size_idx_0 + 1)) {
                    if (inRng->data[NormdNdE_size_idx_0]) {
                        d->data[loop_ub] = static_cast<int32_T>
                            (NormdNdE_size_idx_0 + 1);
                        loop_ub = static_cast<int32_T>(loop_ub + 1);
                    }
                }

                NormdNdE_size_idx_0 = rtb_rho_0->size[0];
                rtb_rho_0->size[0] = c->size[0];
                Real2SimGuidance_emxEnsureCapacity_real_T(rtb_rho_0,
                    NormdNdE_size_idx_0);
                loop_ub = c->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    rtb_rho_0->data[i] = localDW->rho[static_cast<int32_T>
                        (c->data[i] - 1)];
                }

                NormdNdE_size_idx_0 = rtb_rho_1->size[0];
                rtb_rho_1->size[0] = d->size[0];
                Real2SimGuidance_emxEnsureCapacity_real_T(rtb_rho_1,
                    NormdNdE_size_idx_0);
                loop_ub = d->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    rtb_rho_1->data[i] = localDW->rho[static_cast<int32_T>
                        (d->data[i] - 1)];
                }

                rtb_UpperBound_e = std::fmin(Real2SimGuidance_mean(rtb_rho_0),
                    Real2SimGuidance_median(rtb_rho_1));

                // '<S34>:1:15'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (((localDW->SFunction_DIMS3 == 1 ?
                        AngSec->size[0] : localDW->SFunction_DIMS3) ==
                        front->size[0]) & (localDW->SFunction_DIMS3 ==
                                           AngSec->size[0])))) {
                    rtb_SumBiasH_idx_2 = catAngSec->data[b];
                    loop_ub = front->size[0];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        front->data[i] = static_cast<boolean_T>
                            (static_cast<int32_T>(static_cast<int32_T>(
                               static_cast<boolean_T>(static_cast<int32_T>
                                ((localDW->rho[i] <= rtb_UpperBound_e) &
                                 (AngSec->data[i] == rtb_SumBiasH_idx_2)))) |
                              static_cast<int32_T>(front->data[i])));
                    }
                } else {
                    Real2SimGuidance_binary_expand_op(front, localDW->rho,
                        localDW->SFunction_DIMS3, rtb_UpperBound_e, AngSec,
                        catAngSec, b);
                }

                b = static_cast<int32_T>(b + 1);
            }

            Real2SimGuidance_emxFree_real_T(&rtb_rho_1);
            Real2SimGuidance_emxFree_int32_T(&d);
            Real2SimGuidance_emxFree_int32_T(&c);
            Real2SimGuidance_emxFree_boolean_T(&b_0);
            Real2SimGuidance_emxFree_boolean_T(&inRng);
            nx = static_cast<int32_T>(front->size[0] - 1);
            loop_ub = 0;
            for (b = 0; b <= nx; b = static_cast<int32_T>(b + 1)) {
                if (front->data[b]) {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            }

            NormdNdE_size_idx_0 = 0;
            for (rtu_DngrListNER_DIMS1_idx_0 = 0; rtu_DngrListNER_DIMS1_idx_0 <=
                 nx; rtu_DngrListNER_DIMS1_idx_0 = static_cast<int32_T>
                    (rtu_DngrListNER_DIMS1_idx_0 + 1)) {
                if (front->data[rtu_DngrListNER_DIMS1_idx_0]) {
                    // '<S34>:1:18'
                    localDW->theta[NormdNdE_size_idx_0] = localDW->
                        theta[rtu_DngrListNER_DIMS1_idx_0];
                    NormdNdE_size_idx_0 = static_cast<int32_T>
                        (NormdNdE_size_idx_0 + 1);
                }
            }

            localDW->SFunction_DIMS4 = loop_ub;
            loop_ub = 0;
            for (b = 0; b <= nx; b = static_cast<int32_T>(b + 1)) {
                if (front->data[b]) {
                    loop_ub = static_cast<int32_T>(loop_ub + 1);
                }
            }

            NormdNdE_size_idx_0 = 0;
            for (rtu_DngrListNER_DIMS1_idx_0 = 0; rtu_DngrListNER_DIMS1_idx_0 <=
                 nx; rtu_DngrListNER_DIMS1_idx_0 = static_cast<int32_T>
                    (rtu_DngrListNER_DIMS1_idx_0 + 1)) {
                if (front->data[rtu_DngrListNER_DIMS1_idx_0]) {
                    // '<S34>:1:18'
                    localDW->rho[NormdNdE_size_idx_0] = localDW->
                        rho[rtu_DngrListNER_DIMS1_idx_0];
                    NormdNdE_size_idx_0 = static_cast<int32_T>
                        (NormdNdE_size_idx_0 + 1);
                }
            }

            localDW->SFunction_DIMS3 = loop_ub;
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        Real2SimGuidance_emxFree_real_T(&rtb_rho_0);
        Real2SimGuidance_emxFree_real_T(&catAngSec);
        Real2SimGuidance_emxFree_real_T(&AngSec);
        Real2SimGuidance_emxFree_boolean_T(&front);

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar' incorporates:
        //   DataStoreWrite: '<S16>/Data Store Write'

        localDW->AvoidDanger = static_cast<boolean_T>(static_cast<int32_T>
            ((localDW->SFunction_DIMS4 != 0) & (localDW->SFunction_DIMS3 != 0)));

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'

        // Gain: '<S1>/Inverse'
        // '<S34>:1:22'
        localDW->Inverse_DIMS1 = localDW->SFunction_DIMS4;
        loop_ub = static_cast<int32_T>(localDW->SFunction_DIMS4 - 1);
        for (i = 0; i <= loop_ub; i++) {
            localDW->theta[i] = -localDW->theta[i];
        }

        // End of Gain: '<S1>/Inverse'

        // Outputs for Atomic SubSystem: '<S1>/Hdg2LAP'
        // Logic: '<S1>/NotInDngr' incorporates:
        //   Logic: '<S15>/OR'

        rtb_GreaterThanOrEqual_h = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(rtb_GreaterThanOrEqual_h) ^ 1));

        // End of Outputs for SubSystem: '<S1>/Hdg2LAP'

        // Logic: '<S1>/NotInDngr'
        rtb_NotInDngr = rtb_GreaterThanOrEqual_h;

        // Outputs for Enabled SubSystem: '<S1>/TieredVFH+' incorporates:
        //   EnablePort: '<S17>/Enable'

        if (rtb_NotInDngr) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (localDW->TieredVFH_MODE) ^ 1))) {
                // InitializeConditions for MATLABSystem: '<S17>/Vector Field Histogram' 
                std::memset(&localDW->obj_p.BinaryHistogram[0], 0,
                            static_cast<uint32_T>(180U * sizeof(boolean_T)));
                localDW->obj_p.PreviousDirection *= 0.0;
                localDW->TieredVFH_MODE = true;
            }

            // MATLABSystem: '<S17>/Vector Field Histogram'
            rtb_Compare_i = false;
            rEQ0 = true;
            nx = 0;
            exitg1 = false;
            while ((!exitg1) && (nx < 2)) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((localDW->obj_p.DistanceLimits[nx] ==
                       rtCP_VectorFieldHistogram_DistanceLimits[nx]) ^ 1))) {
                    rEQ0 = false;
                    exitg1 = true;
                } else {
                    nx = static_cast<int32_T>(nx + 1);
                }
            }

            if (rEQ0) {
                rtb_Compare_i = true;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_Compare_i) ^ 1))) {
                localDW->obj_p.DistanceLimits[0] = Real2SimGuidance_minimum
                    (rtCP_VectorFieldHistogram_DistanceLimits);
                localDW->obj_p.DistanceLimits[1] = 1623.8550613183404;
            }

            rtb_Compare_i = false;
            rEQ0 = true;
            nx = 0;
            exitg1 = false;
            while ((!exitg1) && (nx < 2)) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((localDW->
                        obj_p.HistogramThresholds[nx] ==
                        rtCP_VectorFieldHistogram_HistogramThresholds[nx]) ^ 1)))
                {
                    rEQ0 = false;
                    exitg1 = true;
                } else {
                    nx = static_cast<int32_T>(nx + 1);
                }
            }

            if (rEQ0) {
                rtb_Compare_i = true;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_Compare_i) ^ 1))) {
                localDW->obj_p.HistogramThresholds[0] = Real2SimGuidance_minimum
                    (rtCP_VectorFieldHistogram_HistogramThresholds);
                localDW->obj_p.HistogramThresholds[1] = 649.54202452733625;
            }

            if (localDW->obj_p.RobotRadius != 4.2) {
                localDW->obj_p.RobotRadius = 4.2;
            }

            if (localDW->obj_p.SafetyDistance != 21.0) {
                localDW->obj_p.SafetyDistance = 21.0;
            }

            if (localDW->obj_p.MinTurningRadius != 405.9637653295851) {
                localDW->obj_p.MinTurningRadius = 405.9637653295851;
            }

            if (localDW->obj_p.TargetDirectionWeight != 5.0) {
                localDW->obj_p.TargetDirectionWeight = 5.0;
            }

            if (localDW->obj_p.CurrentDirectionWeight != 2.0) {
                localDW->obj_p.CurrentDirectionWeight = 2.0;
            }

            if (localDW->obj_p.PreviousDirectionWeight != 2.0) {
                localDW->obj_p.PreviousDirectionWeight = 2.0;
            }

            rtb_rho_2.data = &localDW->rho[0];
            tmp_z = localDW->SFunction_DIMS3;
            rtb_rho_2.size = &tmp_z;
            rtb_rho_2.allocatedSize = 1048576;
            rtb_rho_2.numDimensions = 1;
            rtb_rho_2.canFreeData = false;

            // MATLABSystem: '<S17>/Vector Field Histogram' incorporates:
            //   Gain: '<S1>/Inverse'

            rtb_theta_0.data = &localDW->theta[0];
            tmp_10 = localDW->Inverse_DIMS1;
            rtb_theta_0.size = &tmp_10;
            rtb_theta_0.allocatedSize = 1048576;
            rtb_theta_0.numDimensions = 1;
            rtb_theta_0.canFreeData = false;

            // MATLABSystem: '<S17>/Vector Field Histogram'
            rtb_Gain_p = Real2SimGuidance_SystemCore_step(&localDW->obj_p,
                &rtb_rho_2, &rtb_theta_0, Switch, localDW);

            // RelationalOperator: '<S17>/IsNaN' incorporates:
            //   MATLABSystem: '<S17>/Vector Field Histogram'

            rtb_IsNaN = std::isnan(rtb_Gain_p);

            // Outputs for Enabled SubSystem: '<S17>/VFH+10' incorporates:
            //   EnablePort: '<S39>/Enable'

            if (rtb_IsNaN) {
                if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                        int32_T>(localDW->VFH10_MODE) ^ 1))) {
                    // InitializeConditions for MATLABSystem: '<S39>/VectorFieldHistogram10' 
                    std::memset(&localDW->obj_n.BinaryHistogram[0], 0,
                                static_cast<uint32_T>(180U * sizeof(boolean_T)));
                    localDW->obj_n.PreviousDirection *= 0.0;
                    localDW->VFH10_MODE = true;
                }

                // MATLABSystem: '<S39>/VectorFieldHistogram10'
                rtb_Compare_i = false;
                rEQ0 = true;
                nx = 0;
                exitg1 = false;
                while ((!exitg1) && (nx < 2)) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((localDW->
                            obj_n.DistanceLimits[nx] ==
                            rtCP_VectorFieldHistogram10_DistanceLimits[nx]) ^ 1)))
                    {
                        rEQ0 = false;
                        exitg1 = true;
                    } else {
                        nx = static_cast<int32_T>(nx + 1);
                    }
                }

                if (rEQ0) {
                    rtb_Compare_i = true;
                }

                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rtb_Compare_i) ^
                      1))) {
                    localDW->obj_n.DistanceLimits[0] = Real2SimGuidance_minimum
                        (rtCP_VectorFieldHistogram10_DistanceLimits);
                    localDW->obj_n.DistanceLimits[1] = 1623.8550613183404;
                }

                rtb_Compare_i = false;
                rEQ0 = true;
                nx = 0;
                exitg1 = false;
                while ((!exitg1) && (nx < 2)) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((localDW->obj_n.HistogramThresholds
                            [nx] ==
                            rtCP_VectorFieldHistogram10_HistogramThresholds[nx])
                          ^ 1))) {
                        rEQ0 = false;
                        exitg1 = true;
                    } else {
                        nx = static_cast<int32_T>(nx + 1);
                    }
                }

                if (rEQ0) {
                    rtb_Compare_i = true;
                }

                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rtb_Compare_i) ^
                      1))) {
                    localDW->obj_n.HistogramThresholds[0] =
                        Real2SimGuidance_minimum
                        (rtCP_VectorFieldHistogram10_HistogramThresholds);
                    localDW->obj_n.HistogramThresholds[1] = 6495.4202452733625;
                }

                if (localDW->obj_n.RobotRadius != 4.2) {
                    localDW->obj_n.RobotRadius = 4.2;
                }

                if (localDW->obj_n.SafetyDistance != 21.0) {
                    localDW->obj_n.SafetyDistance = 21.0;
                }

                if (localDW->obj_n.MinTurningRadius != 405.9637653295851) {
                    localDW->obj_n.MinTurningRadius = 405.9637653295851;
                }

                if (localDW->obj_n.TargetDirectionWeight != 5.0) {
                    localDW->obj_n.TargetDirectionWeight = 5.0;
                }

                if (localDW->obj_n.CurrentDirectionWeight != 2.0) {
                    localDW->obj_n.CurrentDirectionWeight = 2.0;
                }

                if (localDW->obj_n.PreviousDirectionWeight != 2.0) {
                    localDW->obj_n.PreviousDirectionWeight = 2.0;
                }

                rtb_rho_3.data = &localDW->rho[0];
                tmp_11 = localDW->SFunction_DIMS3;
                rtb_rho_3.size = &tmp_11;
                rtb_rho_3.allocatedSize = 1048576;
                rtb_rho_3.numDimensions = 1;
                rtb_rho_3.canFreeData = false;

                // MATLABSystem: '<S39>/VectorFieldHistogram10' incorporates:
                //   Gain: '<S1>/Inverse'

                rtb_theta_1.data = &localDW->theta[0];
                tmp_12 = localDW->Inverse_DIMS1;
                rtb_theta_1.size = &tmp_12;
                rtb_theta_1.allocatedSize = 1048576;
                rtb_theta_1.numDimensions = 1;
                rtb_theta_1.canFreeData = false;

                // MATLABSystem: '<S39>/VectorFieldHistogram10'
                localDW->VectorFieldHistogram10 =
                    Real2SimGuidance_SystemCore_step(&localDW->obj_n, &rtb_rho_3,
                    &rtb_theta_1, Switch, localDW);

                // Switch: '<S17>/Switch'
                localDW->Switch_c = localDW->VectorFieldHistogram10;
            } else {
                localDW->VFH10_MODE = false;

                // Switch: '<S17>/Switch' incorporates:
                //   MATLABSystem: '<S17>/Vector Field Histogram'

                localDW->Switch_c = rtb_Gain_p;
            }

            // End of Outputs for SubSystem: '<S17>/VFH+10'
        } else if (localDW->TieredVFH_MODE) {
            // Disable for Enabled SubSystem: '<S17>/VFH+10'
            localDW->VFH10_MODE = false;

            // End of Disable for SubSystem: '<S17>/VFH+10'
            localDW->TieredVFH_MODE = false;
        }

        // End of Outputs for SubSystem: '<S1>/TieredVFH+'

        // Outputs for Atomic SubSystem: '<S1>/Hdg2LAP'
        // Sum: '<S15>/Minus'
        Switch = rtb_FixedWingGuidanceStateBus.HeadingAngle - localDW->Switch_c;

        // RelationalOperator: '<S15>/IsNaN'
        rtb_Compare_i = std::isnan(Switch);

        // RelationalOperator: '<S28>/Compare'
        localDW->Compare_o = rtb_Compare_i;

        // Outputs for Enabled SubSystem: '<S15>/FailDangerAvoidance' incorporates:
        //   EnablePort: '<S24>/Enable'

        // RelationalOperator: '<S20>/FixPt Relational Operator' incorporates:
        //   UnitDelay: '<S20>/Delay Input1'
        //
        //  Block description for '<S20>/Delay Input1':
        //
        //   Store in Global RAM

        if (static_cast<int32_T>(localDW->Compare_o) > static_cast<int32_T>
                (localDW->DelayInput1_DSTATE)) {
            // MATLAB Function: '<S24>/printFail'
            // MATLAB Function 'AvoidDanger/Hdg2LAP/FailDangerAvoidance/printFail': '<S31>:1' 
            // '<S31>:1:3'
            printf("Danger Avoidance Failed.\n");
            fflush(stdout);
        }

        // End of RelationalOperator: '<S20>/FixPt Relational Operator'
        // End of Outputs for SubSystem: '<S15>/FailDangerAvoidance'

        // MATLAB Function: '<S15>/AngDiff' incorporates:
        //   Switch: '<S1>/SwitchLookAheadPoint'

        // MATLAB Function 'AvoidDanger/Hdg2LAP/AngDiff': '<S19>:1'
        // '<S19>:1:3'
        rtb_RefRngmMinRng -= Switch;
        if (std::abs(rtb_RefRngmMinRng) > 3.1415926535897931) {
            if (std::isnan(rtb_RefRngmMinRng + 3.1415926535897931)) {
                rtb_UpperBound_e = (rtNaN);
            } else if (std::isinf(rtb_RefRngmMinRng + 3.1415926535897931)) {
                rtb_UpperBound_e = (rtNaN);
            } else if (rtb_RefRngmMinRng + 3.1415926535897931 == 0.0) {
                rtb_UpperBound_e = 0.0;
            } else {
                rtb_UpperBound_e = std::fmod(rtb_RefRngmMinRng +
                    3.1415926535897931, 6.2831853071795862);
                rEQ0 = (rtb_UpperBound_e == 0.0);
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rEQ0) ^ 1))) {
                    rtb_Gain_p = std::abs((rtb_RefRngmMinRng +
                                           3.1415926535897931) /
                                          6.2831853071795862);
                    rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs
                        (rtb_Gain_p - std::floor(rtb_Gain_p + 0.5)) >
                        2.2204460492503131E-16 * rtb_Gain_p) ^ 1));
                }

                if (rEQ0) {
                    rtb_UpperBound_e = 0.0;
                } else if (rtb_RefRngmMinRng + 3.1415926535897931 < 0.0) {
                    rtb_UpperBound_e += 6.2831853071795862;
                }
            }

            if (static_cast<boolean_T>(static_cast<int32_T>((rtb_RefRngmMinRng +
                   3.1415926535897931 > 0.0) & (rtb_UpperBound_e == 0.0)))) {
                rtb_UpperBound_e = 6.2831853071795862;
            }

            rtb_RefRngmMinRng = rtb_UpperBound_e - 3.1415926535897931;
        }

        // End of MATLAB Function: '<S15>/AngDiff'

        // RelationalOperator: '<S21>/Compare' incorporates:
        //   Constant: '<S21>/Constant'

        rEQ0 = (rtb_RefRngmMinRng > 1.0E-6);

        // RelationalOperator: '<S29>/Compare' incorporates:
        //   Constant: '<S29>/Constant'

        localDW->Compare_l = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(rEQ0) ^ 1));

        // Outputs for Enabled SubSystem: '<S15>/FinishDangerAvoidance' incorporates:
        //   EnablePort: '<S25>/Enable'

        // RelationalOperator: '<S22>/FixPt Relational Operator' incorporates:
        //   UnitDelay: '<S22>/Delay Input1'
        //
        //  Block description for '<S22>/Delay Input1':
        //
        //   Store in Global RAM

        if (static_cast<int32_T>(localDW->Compare_l) > static_cast<int32_T>
                (localDW->DelayInput1_DSTATE_o)) {
            // MATLAB Function: '<S25>/printFinish'
            // MATLAB Function 'AvoidDanger/Hdg2LAP/FinishDangerAvoidance/printFinish': '<S32>:1' 
            // '<S32>:1:3'
            printf("Finish Danger Avoidance.\n");
            fflush(stdout);
        }

        // End of RelationalOperator: '<S22>/FixPt Relational Operator'
        // End of Outputs for SubSystem: '<S15>/FinishDangerAvoidance'

        // RelationalOperator: '<S30>/Compare'
        localDW->Compare_k = rEQ0;

        // Outputs for Enabled SubSystem: '<S15>/StartDangerAvoidance' incorporates:
        //   EnablePort: '<S26>/Enable'

        // RelationalOperator: '<S23>/FixPt Relational Operator' incorporates:
        //   UnitDelay: '<S23>/Delay Input1'
        //
        //  Block description for '<S23>/Delay Input1':
        //
        //   Store in Global RAM

        if (static_cast<int32_T>(localDW->Compare_k) > static_cast<int32_T>
                (localDW->DelayInput1_DSTATE_p)) {
            // MATLAB Function: '<S26>/printStart'
            // MATLAB Function 'AvoidDanger/Hdg2LAP/StartDangerAvoidance/printStart': '<S33>:1' 
            // '<S33>:1:3'
            printf("Start Danger Avoidance.\n");
            fflush(stdout);
        }

        // End of RelationalOperator: '<S23>/FixPt Relational Operator'
        // End of Outputs for SubSystem: '<S15>/StartDangerAvoidance'

        // Switch: '<S15>/Switch' incorporates:
        //   Logic: '<S15>/OR'

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (rtb_Compare_i) ^ 1))) & static_cast<int32_T>
                (rtb_GreaterThanOrEqual_h)))) {
            rtb_Abs1 = Switch;
        }

        // End of Switch: '<S15>/Switch'

        // BusAssignment: '<S15>/Bus Assignment'
        rtb_RefRngmMinRng = rtb_Abs1;

        // Trigonometry: '<S15>/Cos' incorporates:
        //   BusAssignment: '<S15>/Bus Assignment'

        rtb_Abs1 = std::cos(rtb_Abs1);

        // MATLAB Function: '<S15>/getLAPGainBias'
        // MATLAB Function 'AvoidDanger/Hdg2LAP/getLAPGainBias': '<S27>:1'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->LAPGainBias_not_empty) ^ 1))) {
            int32_T exitg2;
            int32_T exitg3;
            int8_T csz_idx_0;

            // '<S27>:1:3'
            // '<S27>:1:4'
            ret->size[0] = 1;
            ret->size[1] = 0;
            csz_idx_0 = Real2SimGuidance_cfopen("config.ini", "rb", localDW);
            if (static_cast<int32_T>(csz_idx_0) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread(static_cast<real_T>(csz_idx_0), k,
                                       localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose(static_cast<real_T>(csz_idx_0), localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_g, 2);
                Real2SimGuidance_emxInit_char_T(&data_5, 2);
                do {
                    exitg2 = 0;
                    if (data->size[1] != 0) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(data_5->size
                            [0] * data_5->size[1]);
                        data_5->size[0] = 1;
                        data_5->size[1] = data->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(data_5,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(static_cast<int32_T>
                            (data->size[0] * data->size[1]) - 1);
                        for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <=
                                loop_ub; NormdNdE_size_idx_0++) {
                            data_5->data[NormdNdE_size_idx_0] = data->
                                data[NormdNdE_size_idx_0];
                        }

                        Real2SimGuidance_strtok(data_5, curLine, data);
                        Real2SimGuidance_strtok_a(curLine, tmp_g);
                        Real2SimGuidance_strtrim(tmp_g, curLine);
                        if (curLine->size[1] >= 2) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[0] == '[') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            guard1 = false;
                            if (rtb_GreaterThanOrEqual_h) {
                                rtb_GreaterThanOrEqual_h = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    rtb_GreaterThanOrEqual_h = true;
                                }

                                if (rtb_GreaterThanOrEqual_h) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        nx = 0;
                                        b = 0;
                                    } else {
                                        nx = 1;
                                        b = static_cast<int32_T>(curLine->size[1]
                                            - 1);
                                    }

                                    NormdNdE_size_idx_0 = static_cast<int32_T>
                                        (curSection->size[0] * curSection->size
                                         [1]);
                                    curSection->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(b - nx);
                                    curSection->size[1] = loop_ub;
                                    Real2SimGuidance_emxEnsureCapacity_char_T
                                        (curSection, NormdNdE_size_idx_0);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
                                        curSection->data[i] = curLine->data[
                                            static_cast<int32_T>(nx + i)];
                                    }

                                    curKey->size[0] = 1;
                                    curKey->size[1] = 0;
                                } else {
                                    guard1 = true;
                                }
                            } else {
                                guard1 = true;
                            }

                            if (guard1) {
                                if (curLine->data[0] == ';') {
                                    rtb_GreaterThanOrEqual_h = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                        Real2SimGuidance_contains(curLine)) {
                                    Real2SimGuidance_strtok_ay(curLine, aTmp,
                                        curVal);
                                    Real2SimGuidance_find_token(curVal, &nx, &b);
                                    if (nx > static_cast<int32_T>(b - 1)) {
                                        nx = 0;
                                        b = 0;
                                    } else {
                                        nx = static_cast<int32_T>(nx - 1);
                                        b = static_cast<int32_T>(b - 1);
                                    }

                                    Real2SimGuidance_strtrim(aTmp, curKey);
                                    NormdNdE_size_idx_0 = static_cast<int32_T>
                                        (curLine->size[0] * curLine->size[1]);
                                    curLine->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(b - nx);
                                    curLine->size[1] = loop_ub;
                                    Real2SimGuidance_emxEnsureCapacity_char_T
                                        (curLine, NormdNdE_size_idx_0);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
                                        curLine->data[i] = curVal->data[
                                            static_cast<int32_T>(nx + i)];
                                    }

                                    Real2SimGuidance_strtrim(curLine, curVal);
                                }
                            }
                        }

                        if (Real2SimGuidance_strcmp(curSection)) {
                            if (curKey->size[1] == 0) {
                                aTmp->size[0] = 1;
                                aTmp->size[1] = 0;
                            } else {
                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (aTmp->size[0] * aTmp->size[1]);
                                aTmp->size[0] = 1;
                                aTmp->size[1] = curKey->size[1];
                                Real2SimGuidance_emxEnsureCapacity_char_T(aTmp,
                                    NormdNdE_size_idx_0);
                                loop_ub = static_cast<int32_T>(curKey->size[1] -
                                    1);
                                for (i = 0; i <= loop_ub; i++) {
                                    aTmp->data[i] = curKey->data[i];
                                }
                            }

                            rtb_GreaterThanOrEqual_h = false;
                            if (aTmp->size[1] == 4) {
                                nx = 0;
                                do {
                                    exitg3 = 0;
                                    if (nx < 4) {
                                        if (l[static_cast<int32_T>
                                                (static_cast<int32_T>(
                                                static_cast<uint8_T>(aTmp->
                                                data[nx])) & 127)] != l[
                                                static_cast<int32_T>(m[nx])]) {
                                            exitg3 = 1;
                                        } else {
                                            nx = static_cast<int32_T>(nx + 1);
                                        }
                                    } else {
                                        rtb_GreaterThanOrEqual_h = true;
                                        exitg3 = 1;
                                    }
                                } while (exitg3 == 0);
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (ret->size[0] * ret->size[1]);
                                ret->size[0] = 1;
                                ret->size[1] = curVal->size[1];
                                Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                                    NormdNdE_size_idx_0);
                                loop_ub = static_cast<int32_T>(curVal->size[1] -
                                    1);
                                for (i = 0; i <= loop_ub; i++) {
                                    ret->data[i] = curVal->data[i];
                                }

                                exitg2 = 1;
                            }
                        }
                    } else {
                        exitg2 = 1;
                    }
                } while (exitg2 == 0);

                Real2SimGuidance_emxFree_char_T(&data_5);
                Real2SimGuidance_emxFree_char_T(&tmp_g);
            }

            inputArg_data = Real2SimGuidance_str2double(ret);
            printf("Set LAP Gain:%f\n", inputArg_data.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            csz_idx_0 = Real2SimGuidance_cfopen("config.ini", "rb", localDW);
            if (static_cast<int32_T>(csz_idx_0) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread(static_cast<real_T>(csz_idx_0), k,
                                       localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose(static_cast<real_T>(csz_idx_0), localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_f, 2);
                Real2SimGuidance_emxInit_char_T(&data_4, 2);
                do {
                    exitg2 = 0;
                    if (data->size[1] != 0) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(data_4->size
                            [0] * data_4->size[1]);
                        data_4->size[0] = 1;
                        data_4->size[1] = data->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(data_4,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(static_cast<int32_T>
                            (data->size[0] * data->size[1]) - 1);
                        for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <=
                                loop_ub; NormdNdE_size_idx_0++) {
                            data_4->data[NormdNdE_size_idx_0] = data->
                                data[NormdNdE_size_idx_0];
                        }

                        Real2SimGuidance_strtok(data_4, curLine, data);
                        Real2SimGuidance_strtok_a(curLine, tmp_f);
                        Real2SimGuidance_strtrim(tmp_f, curLine);
                        if (curLine->size[1] >= 2) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[0] == '[') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            guard1 = false;
                            if (rtb_GreaterThanOrEqual_h) {
                                rtb_GreaterThanOrEqual_h = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    rtb_GreaterThanOrEqual_h = true;
                                }

                                if (rtb_GreaterThanOrEqual_h) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        nx = 0;
                                        b = 0;
                                    } else {
                                        nx = 1;
                                        b = static_cast<int32_T>(curLine->size[1]
                                            - 1);
                                    }

                                    NormdNdE_size_idx_0 = static_cast<int32_T>
                                        (curSection->size[0] * curSection->size
                                         [1]);
                                    curSection->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(b - nx);
                                    curSection->size[1] = loop_ub;
                                    Real2SimGuidance_emxEnsureCapacity_char_T
                                        (curSection, NormdNdE_size_idx_0);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
                                        curSection->data[i] = curLine->data[
                                            static_cast<int32_T>(nx + i)];
                                    }

                                    curKey->size[0] = 1;
                                    curKey->size[1] = 0;
                                } else {
                                    guard1 = true;
                                }
                            } else {
                                guard1 = true;
                            }

                            if (guard1) {
                                if (curLine->data[0] == ';') {
                                    rtb_GreaterThanOrEqual_h = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                        Real2SimGuidance_contains(curLine)) {
                                    Real2SimGuidance_strtok_ay(curLine, aTmp,
                                        curVal);
                                    Real2SimGuidance_find_token(curVal, &nx, &b);
                                    if (nx > static_cast<int32_T>(b - 1)) {
                                        nx = 0;
                                        b = 0;
                                    } else {
                                        nx = static_cast<int32_T>(nx - 1);
                                        b = static_cast<int32_T>(b - 1);
                                    }

                                    Real2SimGuidance_strtrim(aTmp, curKey);
                                    NormdNdE_size_idx_0 = static_cast<int32_T>
                                        (curLine->size[0] * curLine->size[1]);
                                    curLine->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(b - nx);
                                    curLine->size[1] = loop_ub;
                                    Real2SimGuidance_emxEnsureCapacity_char_T
                                        (curLine, NormdNdE_size_idx_0);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
                                        curLine->data[i] = curVal->data[
                                            static_cast<int32_T>(nx + i)];
                                    }

                                    Real2SimGuidance_strtrim(curLine, curVal);
                                }
                            }
                        }

                        if (Real2SimGuidance_strcmp(curSection)) {
                            if (curKey->size[1] == 0) {
                                aTmp->size[0] = 1;
                                aTmp->size[1] = 0;
                            } else {
                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (aTmp->size[0] * aTmp->size[1]);
                                aTmp->size[0] = 1;
                                aTmp->size[1] = curKey->size[1];
                                Real2SimGuidance_emxEnsureCapacity_char_T(aTmp,
                                    NormdNdE_size_idx_0);
                                loop_ub = static_cast<int32_T>(curKey->size[1] -
                                    1);
                                for (i = 0; i <= loop_ub; i++) {
                                    aTmp->data[i] = curKey->data[i];
                                }
                            }

                            rtb_GreaterThanOrEqual_h = false;
                            if (aTmp->size[1] == 4) {
                                nx = 0;
                                do {
                                    exitg3 = 0;
                                    if (nx < 4) {
                                        if (l[static_cast<int32_T>
                                                (static_cast<int32_T>(
                                                static_cast<uint8_T>(aTmp->
                                                data[nx])) & 127)] != l[
                                                static_cast<int32_T>(n[nx])]) {
                                            exitg3 = 1;
                                        } else {
                                            nx = static_cast<int32_T>(nx + 1);
                                        }
                                    } else {
                                        rtb_GreaterThanOrEqual_h = true;
                                        exitg3 = 1;
                                    }
                                } while (exitg3 == 0);
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (ret->size[0] * ret->size[1]);
                                ret->size[0] = 1;
                                ret->size[1] = curVal->size[1];
                                Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                                    NormdNdE_size_idx_0);
                                loop_ub = static_cast<int32_T>(curVal->size[1] -
                                    1);
                                for (i = 0; i <= loop_ub; i++) {
                                    ret->data[i] = curVal->data[i];
                                }

                                exitg2 = 1;
                            }
                        }
                    } else {
                        exitg2 = 1;
                    }
                } while (exitg2 == 0);

                Real2SimGuidance_emxFree_char_T(&data_4);
                Real2SimGuidance_emxFree_char_T(&tmp_f);
            }

            tmp_3 = Real2SimGuidance_str2double(ret);
            printf("Set LAP Bias:%f\n", tmp_3.re);
            fflush(stdout);
            localDW->LAPGainBias.Gain = inputArg_data.re;
            localDW->LAPGainBias.Bias = tmp_3.re;
            localDW->LAPGainBias_not_empty = true;
        }

        // Sum: '<S15>/Sum' incorporates:
        //   DataStoreRead: '<S15>/ReadRefGndSpd'
        //   MATLAB Function: '<S15>/getLAPGainBias'
        //   Product: '<S15>/Product'

        // '<S27>:1:6'
        // '<S27>:1:7'
        rtb_Switch = localDW->LAPGainBias.Gain * localDW->RefGndSpd +
            localDW->LAPGainBias.Bias;

        // Sum: '<S15>/SumEast' incorporates:
        //   BusAssignment: '<S15>/Bus Assignment'
        //   Product: '<S15>/ProductEast'
        //   Trigonometry: '<S15>/Sin'

        Switch = rtb_Switch * std::sin(rtb_RefRngmMinRng) +
            rtb_FixedWingGuidanceStateBus.East;

        // Sum: '<S15>/SumNorth' incorporates:
        //   Product: '<S15>/ProductNorth'

        rtb_UpperBound_e = rtb_Abs1 * rtb_Switch +
            rtb_FixedWingGuidanceStateBus.North;

        // End of Outputs for SubSystem: '<S1>/Hdg2LAP'

        // Product: '<Root>/Product' incorporates:
        //   DataStoreWrite: '<Root>/WriteFlightMode_Log'
        //   Logic: '<Root>/AND'
        //   Logic: '<S1>/NOT'

        localDW->FlightMode_Log = static_cast<uint8_T>(static_cast<boolean_T>(
            static_cast<int32_T>(static_cast<int32_T>(static_cast<boolean_T>(
            static_cast<int32_T>(static_cast<int32_T>(rtu_ControlSwitch[1]) ^ 1)))
            & static_cast<int32_T>(rtb_RelationalOperator))) ?
            static_cast<int32_T>(*rtu_FlightMode) : 0);

        // End of Outputs for SubSystem: '<Root>/AvoidDanger'

        // RelationalOperator: '<S2>/Compare' incorporates:
        //   Constant: '<S2>/Constant'

        rtb_RelationalOperator = (static_cast<int32_T>(*rtu_FlightMode) != 3);

        // BusCreator: '<Root>/CreatADRC' incorporates:
        //   DataStoreRead: '<Root>/ReadADRC_Log'

        rty_FlightLogging->ADRC_Log.x1_ControlError = localDW->ADRC_Log[0];
        rty_FlightLogging->ADRC_Log.x2 = localDW->ADRC_Log[1];
        rty_FlightLogging->ADRC_Log.x3_TotalDisturbance = localDW->ADRC_Log[2];
        rty_FlightLogging->ADRC_Log.u = localDW->ADRC_Log[3];

        // DataStoreRead: '<Root>/Data Store Read'
        rty_FCUCMD->RefGndSpd_mps = localDW->RefGndSpd;

        // Switch: '<S80>/Switch' incorporates:
        //   Abs: '<S80>/Abs'
        //   Bias: '<S80>/Bias'
        //   Bias: '<S80>/Bias1'
        //   Constant: '<S80>/Constant2'
        //   Constant: '<S81>/Constant'
        //   DataStoreRead: '<S7>/LatitudeGCS'
        //   Math: '<S80>/Math Function1'
        //   RelationalOperator: '<S81>/Compare'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        if (std::abs(LatitudeGCS) > 180.0) {
            fid = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
        } else {
            fid = LatitudeGCS;
        }

        // End of Switch: '<S80>/Switch'

        // Abs: '<S77>/Abs1'
        rtb_Gain_p = std::abs(fid);

        // Switch: '<S77>/Switch' incorporates:
        //   Bias: '<S77>/Bias'
        //   Bias: '<S77>/Bias1'
        //   Constant: '<S68>/Constant'
        //   Constant: '<S68>/Constant1'
        //   Constant: '<S79>/Constant'
        //   Gain: '<S77>/Gain'
        //   Product: '<S77>/Divide1'
        //   RelationalOperator: '<S79>/Compare'
        //   Switch: '<S68>/Switch1'

        if (rtb_Gain_p > 90.0) {
            // Signum: '<S77>/Sign1'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(fid)) ^ 1))) {
                if (fid < 0.0) {
                    fid = -1.0;
                } else {
                    fid = static_cast<real_T>(fid > 0.0);
                }
            }

            // End of Signum: '<S77>/Sign1'
            fid *= -(rtb_Gain_p + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S77>/Switch'

        // UnitConversion: '<S85>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum_o = 0.017453292519943295 * fid;

        // Trigonometry: '<S86>/Trigonometric Function1'
        rtb_Switch_b = std::sin(rtb_Sum_o);

        // Sum: '<S86>/Sum1' incorporates:
        //   Constant: '<S86>/Constant'
        //   Product: '<S86>/Product1'

        rtb_Switch_b = 1.0 - 0.0066943799901413295 * rtb_Switch_b * rtb_Switch_b;

        // Product: '<S83>/Product1' incorporates:
        //   Constant: '<S83>/Constant1'
        //   Sqrt: '<S83>/sqrt'

        rtb_Switch = 6.378137E+6 / std::sqrt(rtb_Switch_b);

        // Sum: '<S68>/Sum' incorporates:
        //   DataStoreRead: '<S7>/LongitudeGCS'

        // Unit Conversion - from: rad to: deg
        // Expression: output = (57.2958*input) + (0)
        rtb_Abs1 = static_cast<real_T>(i) + LongitudeGCS;

        // Switch: '<S78>/Switch' incorporates:
        //   Abs: '<S78>/Abs'
        //   Bias: '<S78>/Bias'
        //   Bias: '<S78>/Bias1'
        //   Constant: '<S78>/Constant2'
        //   Constant: '<S82>/Constant'
        //   Math: '<S78>/Math Function1'
        //   RelationalOperator: '<S82>/Compare'

        if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S78>/Switch'

        // Sum: '<S66>/Sum' incorporates:
        //   Constant: '<S83>/Constant2'
        //   Constant: '<S83>/Constant3'
        //   Product: '<S69>/rad lat'
        //   Product: '<S69>/rad long '
        //   Product: '<S69>/x*cos'
        //   Product: '<S69>/x*sin'
        //   Product: '<S69>/y*cos'
        //   Product: '<S69>/y*sin'
        //   Product: '<S83>/Product3'
        //   Product: '<S83>/Product4'
        //   Sum: '<S69>/Sum'
        //   Sum: '<S69>/Sum1'
        //   Trigonometry: '<S83>/Trigonometric Function'
        //   Trigonometry: '<S83>/Trigonometric Function1'
        //   Trigonometry: '<S83>/Trigonometric Function2'
        //   UnitConversion: '<S70>/Unit Conversion'

        rtb_SumBiasH_idx_2 = (rtb_UpperBound_e - Switch * 0.0) * rt_atan2d_snf
            (1.0, rtb_Switch * 0.99330562000985867 / rtb_Switch_b) *
            57.295779513082323 + fid;
        rtb_UpperBound_e = (rtb_UpperBound_e * 0.0 + Switch) * rt_atan2d_snf(1.0,
            rtb_Switch * std::cos(rtb_Sum_o)) * 57.295779513082323 + rtb_Abs1;

        // Switch: '<S74>/Switch' incorporates:
        //   Abs: '<S74>/Abs'
        //   Bias: '<S74>/Bias'
        //   Bias: '<S74>/Bias1'
        //   Constant: '<S74>/Constant2'
        //   Constant: '<S75>/Constant'
        //   Math: '<S74>/Math Function1'
        //   RelationalOperator: '<S75>/Compare'

        if (std::abs(rtb_SumBiasH_idx_2) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_SumBiasH_idx_2 + 180.0, 360.0) + -180.0;
        } else {
            rtb_Abs1 = rtb_SumBiasH_idx_2;
        }

        // End of Switch: '<S74>/Switch'

        // Abs: '<S71>/Abs1'
        Switch = std::abs(rtb_Abs1);

        // Switch: '<S71>/Switch' incorporates:
        //   Bias: '<S71>/Bias'
        //   Bias: '<S71>/Bias1'
        //   Constant: '<S67>/Constant'
        //   Constant: '<S67>/Constant1'
        //   Constant: '<S73>/Constant'
        //   Gain: '<S71>/Gain'
        //   Product: '<S71>/Divide1'
        //   RelationalOperator: '<S73>/Compare'
        //   Switch: '<S67>/Switch1'

        if (Switch > 90.0) {
            // Signum: '<S71>/Sign1'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Abs1)) ^ 1))) {
                if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                } else {
                    rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                }
            }

            // End of Signum: '<S71>/Sign1'
            rtb_Abs1 *= -(Switch + -90.0) + 90.0;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S71>/Switch'

        // Sum: '<S67>/Sum'
        rtb_Switch = static_cast<real_T>(i) + rtb_UpperBound_e;

        // Switch: '<S72>/Switch' incorporates:
        //   Abs: '<S72>/Abs'
        //   Bias: '<S72>/Bias'
        //   Bias: '<S72>/Bias1'
        //   Constant: '<S72>/Constant2'
        //   Constant: '<S76>/Constant'
        //   Math: '<S72>/Math Function1'
        //   RelationalOperator: '<S76>/Compare'

        if (std::abs(rtb_Switch) > 180.0) {
            rtb_Switch = rt_modd_snf(rtb_Switch + 180.0, 360.0) + -180.0;
        }

        // End of Switch: '<S72>/Switch'

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        // Outputs for Atomic SubSystem: '<S1>/Hdg2LAP'
        // Sum: '<S66>/Sum1' incorporates:
        //   BusAssignment: '<S15>/Bus Assignment'
        //   DataStoreRead: '<S7>/AltitudeGCS'
        //   Gain: '<S7>/inverse'
        //   Switch: '<S1>/SwitchLookAheadPoint'

        fid = rtb_UpperBound - (-AltitudeGCS);

        // End of Outputs for SubSystem: '<S1>/Hdg2LAP'
        // End of Outputs for SubSystem: '<Root>/AvoidDanger'

        // Saturate: '<Root>/Saturation'
        if (fid <= 80.0) {
            rty_FCUCMD->Height_meter = 80.0;
        } else {
            rty_FCUCMD->Height_meter = fid;
        }

        // End of Saturate: '<Root>/Saturation'

        // MATLAB Function: '<Root>/WrapAngle' incorporates:
        //   BusAssignment: '<S15>/Bus Assignment'

        // MATLAB Function 'WrapAngle': '<S13>:1'
        // '<S13>:1:2'
        if (std::abs(rtb_RefRngmMinRng) > 3.1415926535897931) {
            if (std::isnan(rtb_RefRngmMinRng + 3.1415926535897931)) {
                rtb_UpperBound_e = (rtNaN);
            } else if (std::isinf(rtb_RefRngmMinRng + 3.1415926535897931)) {
                rtb_UpperBound_e = (rtNaN);
            } else if (rtb_RefRngmMinRng + 3.1415926535897931 == 0.0) {
                rtb_UpperBound_e = 0.0;
            } else {
                rtb_UpperBound_e = std::fmod(rtb_RefRngmMinRng +
                    3.1415926535897931, 6.2831853071795862);
                rEQ0 = (rtb_UpperBound_e == 0.0);
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rEQ0) ^ 1))) {
                    rtb_Gain_p = std::abs((rtb_RefRngmMinRng +
                                           3.1415926535897931) /
                                          6.2831853071795862);
                    rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs
                        (rtb_Gain_p - std::floor(rtb_Gain_p + 0.5)) >
                        2.2204460492503131E-16 * rtb_Gain_p) ^ 1));
                }

                if (rEQ0) {
                    rtb_UpperBound_e = 0.0;
                } else if (rtb_RefRngmMinRng + 3.1415926535897931 < 0.0) {
                    rtb_UpperBound_e += 6.2831853071795862;
                }
            }

            if (static_cast<boolean_T>(static_cast<int32_T>((rtb_RefRngmMinRng +
                   3.1415926535897931 > 0.0) & (rtb_UpperBound_e == 0.0)))) {
                rtb_UpperBound_e = 6.2831853071795862;
            }

            rtb_RefRngmMinRng = rtb_UpperBound_e - 3.1415926535897931;
        }

        // End of MATLAB Function: '<Root>/WrapAngle'

        // Gain: '<S8>/Gain'
        rty_FCUCMD->RefHdg_deg = 57.295779513082323 * rtb_RefRngmMinRng;

        // MATLAB Function: '<Root>/Get Nominal Flight Speed'
        // MATLAB Function 'Get Nominal Flight Speed': '<S5>:1'
        // '<S5>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->SingletonInstance_not_empty_a) ^ 1))) {
            localDW->SingletonInstance_e.AirSpeed = 35.0;
            localDW->SingletonInstance_e.MaxRollAngle = 0.3490658503988659;
            localDW->SingletonInstance_e.FlightPathAngleLimit[0] = -0.175;
            localDW->SingletonInstance_e.FlightPathAngleLimit[1] = 0.175;
            ret->size[0] = 1;
            ret->size[1] = 0;
            fid = Real2SimGuidance_fileManager(localDW);
            if (fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j(fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_l(fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_d, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_e, 2);
                Real2SimGuidance_emxInit_char_T(&data_3, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_3->size[0] *
                        data_3->size[1]);
                    data_3->size[0] = 1;
                    data_3->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_3,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_3->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_3, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_e);
                    Real2SimGuidance_strtrim(tmp_e, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    nx = 0;
                                    b = 0;
                                } else {
                                    nx = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - nx);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(nx + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_d);
                                Real2SimGuidance_strtrim(tmp_d, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_gh(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_3);
                Real2SimGuidance_emxFree_char_T(&tmp_e);
                Real2SimGuidance_emxFree_char_T(&tmp_d);
            }

            inputArg_data = Real2SimGuidance_str2double(ret);
            printf("Set UAV NormAirSpeed:\t\t%f\n", inputArg_data.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Sum_o = Real2SimGuidance_fileManager(localDW);
            if (rtb_Sum_o < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j(rtb_Sum_o, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_l(rtb_Sum_o, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_b, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_c, 2);
                Real2SimGuidance_emxInit_char_T(&data_2, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_2->size[0] *
                        data_2->size[1]);
                    data_2->size[0] = 1;
                    data_2->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_2,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_2->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_2, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_c);
                    Real2SimGuidance_strtrim(tmp_c, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    nx = 0;
                                    b = 0;
                                } else {
                                    nx = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - nx);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(nx + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_b);
                                Real2SimGuidance_strtrim(tmp_b, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghb(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_2);
                Real2SimGuidance_emxFree_char_T(&tmp_c);
                Real2SimGuidance_emxFree_char_T(&tmp_b);
            }

            tmp_3 = Real2SimGuidance_str2double(ret);
            printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_3.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            c_fid = Real2SimGuidance_fileManager(localDW);
            if (c_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j(c_fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_l(c_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_9, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_a, 2);
                Real2SimGuidance_emxInit_char_T(&data_1, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_1->size[0] *
                        data_1->size[1]);
                    data_1->size[0] = 1;
                    data_1->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_1,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_1->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_1, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_a);
                    Real2SimGuidance_strtrim(tmp_a, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    nx = 0;
                                } else {
                                    b = 1;
                                    nx = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(nx - b);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(b + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_9);
                                Real2SimGuidance_strtrim(tmp_9, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghbx(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_1);
                Real2SimGuidance_emxFree_char_T(&tmp_a);
                Real2SimGuidance_emxFree_char_T(&tmp_9);
            }

            tmp_3 = Real2SimGuidance_str2double(ret);
            printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_3.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            d_fid = Real2SimGuidance_fileManager(localDW);
            if (d_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j(d_fid, k, localDW);
                NormdNdE_size_idx_0 = static_cast<int32_T>(data->size[0] *
                    data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T(data,
                    NormdNdE_size_idx_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_l(d_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T(&tmp_7, 2);
                Real2SimGuidance_emxInit_char_T(&tmp_8, 2);
                Real2SimGuidance_emxInit_char_T(&data_0, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    NormdNdE_size_idx_0 = static_cast<int32_T>(data_0->size[0] *
                        data_0->size[1]);
                    data_0->size[0] = 1;
                    data_0->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(data_0,
                        NormdNdE_size_idx_0);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (NormdNdE_size_idx_0 = 0; NormdNdE_size_idx_0 <= loop_ub;
                         NormdNdE_size_idx_0++) {
                        data_0->data[NormdNdE_size_idx_0] = data->
                            data[NormdNdE_size_idx_0];
                    }

                    Real2SimGuidance_strtok(data_0, curLine, data);
                    Real2SimGuidance_strtok_a(curLine, tmp_8);
                    Real2SimGuidance_strtrim(tmp_8, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_GreaterThanOrEqual_h = false;
                        if (curLine->data[0] == '[') {
                            rtb_GreaterThanOrEqual_h = true;
                        }

                        guard1 = false;
                        if (rtb_GreaterThanOrEqual_h) {
                            rtb_GreaterThanOrEqual_h = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if (rtb_GreaterThanOrEqual_h) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    nx = 0;
                                } else {
                                    b = 1;
                                    nx = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                NormdNdE_size_idx_0 = static_cast<int32_T>
                                    (curSection->size[0] * curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(nx - b);
                                curSection->size[1] = loop_ub;
                                Real2SimGuidance_emxEnsureCapacity_char_T
                                    (curSection, NormdNdE_size_idx_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(b + i)];
                                }

                                curKey->size[0] = 1;
                                curKey->size[1] = 0;
                            } else {
                                guard1 = true;
                            }
                        } else {
                            guard1 = true;
                        }

                        if (guard1) {
                            if (curLine->data[0] == ';') {
                                rtb_GreaterThanOrEqual_h = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>
                                    (rtb_GreaterThanOrEqual_h) ^ 1))) &&
                                    Real2SimGuidance_contains(curLine)) {
                                Real2SimGuidance_strtok_ay(curLine, curVal, aTmp);
                                Real2SimGuidance_strtrim(curVal, curKey);
                                Real2SimGuidance_strtok_gdxx(aTmp, tmp_7);
                                Real2SimGuidance_strtrim(tmp_7, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_g(curSection) &&
                            Real2SimGuidance_strcmp_ghbx5(curKey)) {
                        NormdNdE_size_idx_0 = static_cast<int32_T>(ret->size[0] *
                            ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T(ret,
                            NormdNdE_size_idx_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T(&data_0);
                Real2SimGuidance_emxFree_char_T(&tmp_8);
                Real2SimGuidance_emxFree_char_T(&tmp_7);
            }

            tmp_3 = Real2SimGuidance_str2double(ret);
            d_fid = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV MaxRollAngle:\t\t%f\n", d_fid);
            fflush(stdout);
            Real2SimGuidance_readINI(ret, localDW);
            tmp_3 = Real2SimGuidance_str2double(ret);
            rtb_Sum_o = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV ClimbAngleLimit:\t%f\n", rtb_Sum_o);
            fflush(stdout);
            Real2SimGuidance_readINI_p(ret, localDW);
            tmp_3 = Real2SimGuidance_str2double(ret);
            fid = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV DiveAngleLimit:\t\t%f\n", fid);
            fflush(stdout);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(inputArg_data.re)) ^ 1))) {
                localDW->SingletonInstance_e.AirSpeed = inputArg_data.re;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(d_fid)) ^ 1))) {
                localDW->SingletonInstance_e.MaxRollAngle = d_fid;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Sum_o)) ^ 1))) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan(fid)) ^
                   1)))) {
                localDW->SingletonInstance_e.FlightPathAngleLimit[0] = fid;
                localDW->SingletonInstance_e.FlightPathAngleLimit[1] = rtb_Sum_o;
            }

            Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
                (&localDW->SingletonInstance_e.Connector,
                 localDW->SingletonInstance_e.AirSpeed,
                 localDW->SingletonInstance_e.MaxRollAngle);
            localDW->SingletonInstance_not_empty_a = true;
        }

        rtb_RefRngmMinRng = localDW->SingletonInstance_e.Connector.AirSpeed;

        // End of MATLAB Function: '<Root>/Get Nominal Flight Speed'

        // BusCreator: '<Root>/FcuCmdBus'
        rty_FCUCMD->Latitude_deg = rtb_Abs1;
        rty_FCUCMD->Longitude_deg = rtb_Switch;

        // Switch: '<Root>/Switch' incorporates:
        //   Switch: '<S1>/SwitchSpdControl'

        if (rtb_RelationalOperator) {
            // BusCreator: '<Root>/FcuCmdBus'
            rty_FCUCMD->RefAirSpd_mps = rtb_RefRngmMinRng;

            // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
        } else if (rtu_ControlSwitch[1]) {
            // Outputs for Atomic SubSystem: '<S1>/Hdg2LAP'
            // Switch: '<S1>/SwitchSpdControl' incorporates:
            //   BusAssignment: '<S15>/Bus Assignment'
            //   BusCreator: '<Root>/FcuCmdBus'
            //   Switch: '<S1>/SwitchLookAheadPoint'

            rty_FCUCMD->RefAirSpd_mps = rtb_LowerBound;

            // End of Outputs for SubSystem: '<S1>/Hdg2LAP'
        } else {
            // BusCreator: '<Root>/FcuCmdBus' incorporates:
            //   Switch: '<S1>/SwitchSpdControl'

            rty_FCUCMD->RefAirSpd_mps = rtb_RefGndSpd;

            // End of Outputs for SubSystem: '<Root>/AvoidDanger'
        }

        // End of Switch: '<Root>/Switch'

        // DataStoreRead: '<Root>/ReadLagDistance'
        rty_FlightLogging->InnerState.LagDistance = localDW->LagDistance;

        // DataStoreRead: '<Root>/ReadCrossTrackError'
        rty_FlightLogging->InnerState.CrossTrackError = localDW->CrossTrackError;

        // DataStoreRead: '<Root>/ReadEngagedFlag_Log'
        rty_FlightLogging->InnerState.EngagedFlag = localDW->EngagedFlag;

        // DataStoreRead: '<Root>/ReadbiasH_Log'
        rty_FlightLogging->InnerState.biasH = localDW->biasH_Log;

        // DataStoreRead: '<Root>/ReadStatus_Log'
        rty_FlightLogging->InnerState.HdgStatus = localDW->HdgStatus_Log;

        // DataStoreRead: '<Root>/ReadFlightMode_Log'
        rty_FlightLogging->InnerState.FlightMode = localDW->FlightMode_Log;

        // DataStoreRead: '<Root>/ReadAvoidDanger'
        rty_FlightLogging->InnerState.AvoidDanger = localDW->AvoidDanger;

        // BusCreator: '<Root>/InnerStateBus' incorporates:
        //   DataStoreRead: '<Root>/ReadHeading_Log'

        rty_FlightLogging->InnerState.RealHeading = localDW->Heading_Log[1];
        rty_FlightLogging->InnerState.TargetHeading = localDW->Heading_Log[2];
        rty_FlightLogging->InnerState.HeadingDiff = localDW->Heading_Log[0];

        // MATLAB Function: '<Root>/TimeNow'
        // MATLAB Function 'TimeNow': '<S12>:1'
        // '<S12>:1:3'
        Real2SimGuidance_getLocalTime(&rtb_RefGndSpd, &rtb_RefRngmMinRng,
            &rtb_Abs1, &rtb_LowerBound, &rtb_UpperBound, &Switch,
            &rtb_UpperBound_e, &rtb_RelationalOperator);
        rtb_SumBiasH_idx_2 = rtb_LowerBound;
        rtb_Switch = rtb_Abs1;
        rtb_Gain_p = rtb_RefRngmMinRng;
        rtb_Switch_b = rtb_RefGndSpd / 1.0E+6;
        rtb_RefGndSpd = rtb_RefRngmMinRng;
        rtb_RefRngmMinRng = rtb_Switch_b;
        rtb_Abs1 = (((((rtb_UpperBound_e + Switch) + rtb_UpperBound) +
                      rtb_LowerBound) + rtb_Abs1) + rtb_Gain_p) + rtb_Switch_b;
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(rtb_Abs1)) ^ 1))) & static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(rtb_Abs1)) ^ 1)))))) {
            rtb_Abs1 = rtb_UpperBound_e;
            rtb_LowerBound = Switch;
            if ((Switch < 1.0) || (Switch > 12.0)) {
                rtb_LowerBound = std::floor((Switch - 1.0) / 12.0);
                rtb_Abs1 = rtb_UpperBound_e + rtb_LowerBound;
                rtb_LowerBound = ((Switch - 1.0) - rtb_LowerBound * 12.0) + 1.0;
            }

            if (rtb_LowerBound < 3.0) {
                rtb_Abs1--;
                rtb_LowerBound += 9.0;
            } else {
                rtb_LowerBound -= 3.0;
            }

            if ((rtb_Switch_b < 0.0) || (rtb_Switch_b >= 1000.0)) {
                rtb_RefRngmMinRng = std::floor(rtb_Switch_b / 1000.0);
                rtb_RefGndSpd = rtb_Gain_p + rtb_RefRngmMinRng;
                rtb_RefRngmMinRng = rtb_Switch_b - rtb_RefRngmMinRng * 1000.0;
            }

            tmp_6.re = ((((((365.0 * rtb_Abs1 + std::floor(rtb_Abs1 / 4.0)) -
                            std::floor(rtb_Abs1 / 100.0)) + std::floor(rtb_Abs1 /
                            400.0)) + std::floor((153.0 * rtb_LowerBound + 2.0) /
                           5.0)) + rtb_UpperBound) + 60.0) - 719529.0;
            tmp_6.im = 0.0;
            inputArg_data = Real2SimGuidance_plus(Real2SimGuidance_plus
                (Real2SimGuidance_plus(Real2SimGuidance_times(tmp_6), (60.0 *
                rtb_SumBiasH_idx_2 + rtb_Switch) * 60000.0), rtb_RefGndSpd *
                 1000.0), rtb_RefRngmMinRng);
        } else {
            inputArg_data.re = rtb_Abs1;
            inputArg_data.im = 0.0;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &rtb_RefGndSpd,
            &rtb_RefRngmMinRng, &rtb_Abs1, &rtb_LowerBound, &rtb_UpperBound,
            &Switch);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Abs1, &rtb_RefRngmMinRng,
            &rtb_LowerBound, &rtb_UpperBound, &Switch, &rtb_UpperBound_e);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_LowerBound,
            &rtb_UpperBound, &rtb_Abs1, &Switch, &rtb_UpperBound_e, &rtb_Gain_p);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_UpperBound, &Switch,
            &rtb_UpperBound_e, &rtb_LowerBound, &rtb_Gain_p, &rtb_Switch);
        Real2SimGuidance_getDateVec(inputArg_data, &Switch, &rtb_UpperBound_e,
            &rtb_Gain_p, &rtb_Switch, &rtb_UpperBound, &rtb_Switch_b);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_UpperBound_e,
            &rtb_Gain_p, &rtb_Switch, &rtb_Switch_b, &rtb_Sum1_idx_1, &Switch);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Gain_p, &rtb_Switch,
            &rtb_Switch_b, &rtb_Sum1_idx_1, &fid, &rtb_UpperBound_e);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Gain_p, &rtb_Switch,
            &rtb_Switch_b, &rtb_Sum1_idx_1, &fid, &rtb_Sum_o);

        // BusCreator: '<Root>/LoggingBus'
        rty_FlightLogging->RealUAVState = rtu_StateFCU->RealUAVState;
        rty_FlightLogging->SimUAVState = *rtu_SimUAVState;
        rty_FlightLogging->FlightCMD = *rty_FCUCMD;
        rty_FlightLogging->VectorSpd = rtu_StateFCU->VecSpd;

        // MATLAB Function: '<Root>/TimeNow'
        rtb_Switch = std::round(rtb_RefGndSpd);
        if (rtb_Switch < 2.147483648E+9) {
            if (rtb_Switch >= -2.147483648E+9) {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.year = static_cast<int32_T>
                    (rtb_Switch);
            } else {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.year = MIN_int32_T;
            }
        } else {
            // BusCreator: '<Root>/LoggingBus'
            rty_FlightLogging->TimeNow.year = MAX_int32_T;
        }

        rtb_Switch = std::round(rtb_RefRngmMinRng);
        if (rtb_Switch < 2.147483648E+9) {
            if (rtb_Switch >= -2.147483648E+9) {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.month = static_cast<int32_T>
                    (rtb_Switch);
            } else {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.month = MIN_int32_T;
            }
        } else {
            // BusCreator: '<Root>/LoggingBus'
            rty_FlightLogging->TimeNow.month = MAX_int32_T;
        }

        rtb_Switch = std::round(rtb_Abs1);
        if (rtb_Switch < 2.147483648E+9) {
            if (rtb_Switch >= -2.147483648E+9) {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.day = static_cast<int32_T>(rtb_Switch);
            } else {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.day = MIN_int32_T;
            }
        } else {
            // BusCreator: '<Root>/LoggingBus'
            rty_FlightLogging->TimeNow.day = MAX_int32_T;
        }

        rtb_Switch = std::round(rtb_LowerBound);
        if (rtb_Switch < 2.147483648E+9) {
            if (rtb_Switch >= -2.147483648E+9) {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.hour = static_cast<int32_T>
                    (rtb_Switch);
            } else {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.hour = MIN_int32_T;
            }
        } else {
            // BusCreator: '<Root>/LoggingBus'
            rty_FlightLogging->TimeNow.hour = MAX_int32_T;
        }

        rtb_Switch = std::round(rtb_UpperBound);
        if (rtb_Switch < 2.147483648E+9) {
            if (rtb_Switch >= -2.147483648E+9) {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.minute = static_cast<int32_T>
                    (rtb_Switch);
            } else {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.minute = MIN_int32_T;
            }
        } else {
            // BusCreator: '<Root>/LoggingBus'
            rty_FlightLogging->TimeNow.minute = MAX_int32_T;
        }

        rtb_Switch = std::floor(Switch);
        if (rtb_Switch < 2.147483648E+9) {
            if (rtb_Switch >= -2.147483648E+9) {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.second = static_cast<int32_T>
                    (rtb_Switch);
            } else {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.second = MIN_int32_T;
            }
        } else {
            // BusCreator: '<Root>/LoggingBus'
            rty_FlightLogging->TimeNow.second = MAX_int32_T;
        }

        rtb_Switch = std::round((rtb_UpperBound_e - std::floor(rtb_Sum_o)) *
                                1000.0);
        if (rtb_Switch < 2.147483648E+9) {
            if (rtb_Switch >= -2.147483648E+9) {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.millisecond = static_cast<int32_T>
                    (rtb_Switch);
            } else {
                // BusCreator: '<Root>/LoggingBus'
                rty_FlightLogging->TimeNow.millisecond = MIN_int32_T;
            }
        } else {
            // BusCreator: '<Root>/LoggingBus'
            rty_FlightLogging->TimeNow.millisecond = MAX_int32_T;
        }
    }

    Real2SimGuidance_emxFree_char_T(&aTmp);
    Real2SimGuidance_emxFree_char_T(&k);
    Real2SimGuidance_emxFree_char_T(&curLine);
    Real2SimGuidance_emxFree_char_T(&curVal);
    Real2SimGuidance_emxFree_char_T(&curKey);
    Real2SimGuidance_emxFree_char_T(&curSection);
    Real2SimGuidance_emxFree_char_T(&data);
    Real2SimGuidance_emxFree_char_T(&ret);
}

// Update for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const boolean_T *rtu_NewMission, const
    FixedWingGuidanceStateBus *rtu_SimUAVState, DW_Real2SimGuidance_f_T *localDW)
{
    // Update for Atomic SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Update for Atomic SubSystem: '<S9>/HeadingNaNProtection'
        // Switch: '<S95>/HeightSwitch' incorporates:
        //   RelationalOperator: '<S95>/IsNaN'

        if (std::isnan(localDW->SwitchLookAheadNED[2])) {
            // Update for Memory: '<S95>/MemoryRefHeight' incorporates:
            //   Constant: '<S95>/DefaultHeight'

            localDW->MemoryRefHeight_PreviousInput = -150.0;
        } else {
            // Update for Memory: '<S95>/MemoryRefHeight'
            localDW->MemoryRefHeight_PreviousInput = localDW->
                SwitchLookAheadNED[2];
        }

        // End of Switch: '<S95>/HeightSwitch'
        // End of Update for SubSystem: '<S9>/HeadingNaNProtection'

        // Update for Memory: '<S9>/MemoryNotInBrake'
        localDW->MemoryNotInBrake_PreviousInput = localDW->Compare;

        // Update for Atomic SubSystem: '<S9>/GenerateTrack'
        for (int_T i{0}; i < 215; i++) {
            // Update for S-Function (sfix_udelay): '<S93>/EastSequence' incorporates:
            //   S-Function (sfix_udelay): '<S93>/HeightSequence'
            //   S-Function (sfix_udelay): '<S93>/NorthSequence'

            localDW->EastSequence_X[i] = localDW->EastSequence_X
                [static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S93>/HeightSequence' incorporates:
            //   S-Function (sfix_udelay): '<S93>/EastSequence'
            //   S-Function (sfix_udelay): '<S93>/NorthSequence'

            localDW->HeightSequence_X[i] = localDW->HeightSequence_X[
                static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S93>/NorthSequence' incorporates:
            //   S-Function (sfix_udelay): '<S93>/EastSequence'
            //   S-Function (sfix_udelay): '<S93>/HeightSequence'

            localDW->NorthSequence_X[i] = localDW->NorthSequence_X
                [static_cast<int_T>(i + 1)];
        }

        // Update for S-Function (sfix_udelay): '<S93>/EastSequence'
        localDW->EastSequence_X[215] = rtu_SimUAVState->East;

        // Update for S-Function (sfix_udelay): '<S93>/HeightSequence'
        localDW->HeightSequence_X[215] = rtu_SimUAVState->Height;

        // Update for S-Function (sfix_udelay): '<S93>/NorthSequence'
        localDW->NorthSequence_X[215] = rtu_SimUAVState->North;

        // End of Update for SubSystem: '<S9>/GenerateTrack'

        // Update for Memory: '<S9>/Memory'
        localDW->Memory_PreviousInput = localDW->Engaged;

        // Update for Atomic SubSystem: '<S9>/HeadingLogic'
        // Update for Atomic SubSystem: '<S94>/NewMissionHdg'
        // Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S100>/Constant'

        localDW->DiscreteTimeIntegrator_DSTATE += 0.5;
        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        }

        localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
            (*rtu_NewMission);

        // End of Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' 
        // End of Update for SubSystem: '<S94>/NewMissionHdg'
        // End of Update for SubSystem: '<S9>/HeadingLogic'

        // Update for Atomic SubSystem: '<Root>/AvoidDanger'
        // Update for Atomic SubSystem: '<S1>/Hdg2LAP'
        // Update for UnitDelay: '<S20>/Delay Input1'
        //
        //  Block description for '<S20>/Delay Input1':
        //
        //   Store in Global RAM

        localDW->DelayInput1_DSTATE = localDW->Compare_o;

        // Update for UnitDelay: '<S22>/Delay Input1'
        //
        //  Block description for '<S22>/Delay Input1':
        //
        //   Store in Global RAM

        localDW->DelayInput1_DSTATE_o = localDW->Compare_l;

        // Update for UnitDelay: '<S23>/Delay Input1'
        //
        //  Block description for '<S23>/Delay Input1':
        //
        //   Store in Global RAM

        localDW->DelayInput1_DSTATE_p = localDW->Compare_k;

        // End of Update for SubSystem: '<S1>/Hdg2LAP'
        // End of Update for SubSystem: '<Root>/AvoidDanger'
    }

    // Update for Atomic SubSystem: '<S9>/SpeedControl'
    // Update for Enabled SubSystem: '<S98>/SpdFBControl' incorporates:
    //   EnablePort: '<S115>/Enable'

    if (localDW->SpdFBControl_MODE && rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Update for Enabled SubSystem: '<S115>/PID' incorporates:
        //   EnablePort: '<S119>/Enable'

        if (localDW->PID_MODE) {
            // Update for Delay: '<S158>/UD'
            localDW->UD_DSTATE = localDW->Tsamp;

            // Update for DiscreteIntegrator: '<S165>/Integrator'
            localDW->Integrator_DSTATE += 0.1 * localDW->IProdOut;
        }

        // End of Update for SubSystem: '<S115>/PID'
    }

    // End of Update for SubSystem: '<S98>/SpdFBControl'
    // End of Update for SubSystem: '<S9>/SpeedControl'
    // End of Update for SubSystem: '<Root>/Real2SimNav'
}

// Derivatives for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot)
{
    // Derivatives for Atomic SubSystem: '<Root>/Real2SimNav'
    // Derivatives for Atomic SubSystem: '<S9>/SpeedControl'
    // Derivatives for Enabled SubSystem: '<S98>/SpdFBControl'
    if (localDW->SpdFBControl_MODE) {
        // Derivatives for Enabled SubSystem: '<S115>/ADRC'
        if (localDW->ADRC_MODE) {
            // Derivatives for Integrator: '<S121>/Integrator'
            localXdot->Integrator_CSTATE[0] =
                localDW->estimatedExtendedStateDerivative[0];
            localXdot->Integrator_CSTATE[1] =
                localDW->estimatedExtendedStateDerivative[1];
            localXdot->Integrator_CSTATE[2] =
                localDW->estimatedExtendedStateDerivative[2];
        } else {
            {
                real_T *dx;
                int_T i;
                dx = &(localXdot->Integrator_CSTATE[0]);
                for (i=0; i < 3; i++) {
                    dx[i] = 0.0;
                }
            }
        }

        // End of Derivatives for SubSystem: '<S115>/ADRC'
    } else {
        {
            real_T *dx;
            int_T i;
            dx = &(localXdot->Integrator_CSTATE[0]);
            for (i=0; i < 3; i++) {
                dx[i] = 0.0;
            }
        }
    }

    // End of Derivatives for SubSystem: '<S98>/SpdFBControl'
    // End of Derivatives for SubSystem: '<S9>/SpeedControl'

    // Derivatives for Integrator: '<S99>/TD_Alt'
    localXdot->TD_Alt_CSTATE = localDW->dotAltTD;

    // Derivatives for Integrator: '<S99>/dotAltTD'
    localXdot->dotAltTD_CSTATE = localDW->fh;

    // End of Derivatives for SubSystem: '<Root>/Real2SimNav'
}

// Model initialize function
void Real2SimGuidance_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
    *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
    RT_MODEL_Real2SimGuidance_T *const Real2SimGuidance_M)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));

    // setup the global timing engine
    Real2SimGuidance_M->Timing.mdlref_GlobalTID[0] = mdlref_TID0;
    Real2SimGuidance_M->Timing.mdlref_GlobalTID[1] = mdlref_TID1;
    Real2SimGuidance_M->timingBridge = (timingBridge);

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
