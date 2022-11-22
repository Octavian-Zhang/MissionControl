//
// File: Real2SimGuidance.cpp
//
// Code generated for Simulink model 'Real2SimGuidance'.
//
// Model version                  : 5.10
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:19:22 2022
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
#include "DatalinkInterface.h"
#include <cmath>
#include <stdio.h>
#include <stddef.h>
#include <cstdlib>
#include <cstring>
#include "rt_modd_snf.h"
#include "rt_atan2d_snf.h"
#include "rt_hypotd_snf.h"
#include "coder_posix_time.h"
#include "split_JEzbX7NR.h"
#include "floor_0EeG1Grp.h"
#include "Real2SimGuidance_private.h"
#include "div_s32.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<Root>/EngagementDebouncer'
const uint8_T Real2SimGuidance_IN_Debounce{ 1U };

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

// Named constants for Chart: '<S103>/MissionSwitchInitialPersuit'
const uint8_T Real2SimGuidance_IN_Initial{ 1U };

const uint8_T Real2SimGuidance_IN_L1Hdg{ 2U };

const uint8_T Real2SimGuidance_IN_L1Hdg_d{ 1U };

const uint8_T Real2SimGuidance_IN_SimPnt{ 3U };

const uint8_T Real2SimGuidance_IN_SimPnt_o{ 2U };

// Named constants for Chart: '<S118>/ControlLogic'
const uint8_T Real2SimGuidance_IN_ADRC{ 1U };

const uint8_T Real2SimGuidance_IN_ADRC2PID{ 1U };

const uint8_T Real2SimGuidance_IN_Debounce_l{ 2U };

const uint8_T Real2SimGuidance_IN_PID{ 1U };

const uint8_T Real2SimGuidance_IN_PID2ADRC{ 2U };

const uint8_T Real2SimGuidance_IN_useADRC{ 2U };

// Named constants for Chart: '<Root>/TASgreaterthan15for1Sec'
const uint8_T Real2SimGuidance_IN_InAir{ 1U };

const uint8_T Real2SimGuidance_IN_NotTakeOff{ 2U };

// Forward declaration for local functions
static void Real2SimGuidance_emxInit_char_T(emxArray_char_T_Real2SimGuidance_T **
    pEmxArray, int32_T numDimensions);
static int8_T Real2SimGuidance_filedata(DW_ReadHomePoint_Real2SimGuidance_T
    *localDW);
static int8_T Real2SimGuidance_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_ReadHomePoint_Real2SimGuidance_T *localDW);
static void Real2SimGuidance_emxEnsureCapacity_char_T
    (emxArray_char_T_Real2SimGuidance_T *emxArray, int32_T oldNumel);
static void Real2SimGuidance_fread(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_ReadHomePoint_Real2SimGuidance_T
    *localDW);
static void Real2SimGuidance_copysign(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T *foundsign, boolean_T *success);
static boolean_T Real2SimGuidance_isUnitImag(const
    emxArray_char_T_Real2SimGuidance_T *s, int32_T k, int32_T n);
static void Real2SimGuidance_readNonFinite(const
    emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n, boolean_T
    *b_finite, real_T *fv);
static boolean_T Real2SimGuidance_copydigits(emxArray_char_T_Real2SimGuidance_T *
    s1, int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T allowpoint);
static boolean_T Real2SimGuidance_copyexponent
    (emxArray_char_T_Real2SimGuidance_T *s1, int32_T *idx, const
     emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n);
static void Real2SimGuidance_readfloat(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T
    *foundsign, boolean_T *success);
static void Real2SimGuidance_emxFree_char_T(emxArray_char_T_Real2SimGuidance_T **
    pEmxArray);
static creal_T Real2SimGuidance_str2double(const
    emxArray_char_T_Real2SimGuidance_T *s);
static int32_T Real2SimGuidance_cfclose(real_T fid,
    DW_ReadHomePoint_Real2SimGuidance_T *localDW);
static void Real2SimGuidance_strtok(const emxArray_char_T_Real2SimGuidance_T *x,
    emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain);
static void Real2SimGuidance_strtok_j(const emxArray_char_T_Real2SimGuidance_T
    *x, emxArray_char_T_Real2SimGuidance_T *token);
static void Real2SimGuidance_strtrim(const emxArray_char_T_Real2SimGuidance_T *x,
    emxArray_char_T_Real2SimGuidance_T *y);
static boolean_T Real2SimGuidance_strcmp(const
    emxArray_char_T_Real2SimGuidance_T *a);
static boolean_T Real2SimGuidance_strcmp_h(const
    emxArray_char_T_Real2SimGuidance_T *a);
static boolean_T Real2SimGuidance_contains(const
    emxArray_char_T_Real2SimGuidance_T *str);
static void Real2SimGuidance_find_token(const emxArray_char_T_Real2SimGuidance_T
    *x, int32_T *itoken, int32_T *iremain);
static void Real2SimGuidance_strtok_jy(const emxArray_char_T_Real2SimGuidance_T *
    x, emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain);
static boolean_T Real2SimGuidance_strcmp_hd(const
    emxArray_char_T_Real2SimGuidance_T *a);
static boolean_T Real2SimGuidance_strcmp_hdl(const
    emxArray_char_T_Real2SimGuidance_T *a);

// Forward declaration for local functions
static real_T Real2SimGuidance_minimum(const real_T x[2]);
static real_T Real2SimGuidance_wrapToPi_p(real_T theta);
static void Real2SimGuidance_VectorFieldHistogramBase_setupImpl
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj);
static void Real2SimGuidance_emxInit_char_T_e(emxArray_char_T_Real2SimGuidance_T
    **pEmxArray, int32_T numDimensions);
static int8_T Real2SimGuidance_filedata_k(DW_Real2SimGuidance_f_T *localDW);
static int8_T Real2SimGuidance_cfopen_is(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_fileManager_b(DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_emxEnsureCapacity_char_T_g
    (emxArray_char_T_Real2SimGuidance_T *emxArray, int32_T oldNumel);
static void Real2SimGuidance_fread_h(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_copysign_l(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T *foundsign, boolean_T *success);
static boolean_T Real2SimGuidance_isUnitImag_g(const
    emxArray_char_T_Real2SimGuidance_T *s, int32_T k, int32_T n);
static void Real2SimGuidance_readNonFinite_m(const
    emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n, boolean_T
    *b_finite, real_T *fv);
static boolean_T Real2SimGuidance_copydigits_e
    (emxArray_char_T_Real2SimGuidance_T *s1, int32_T *idx, const
     emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n, boolean_T
     allowpoint);
static boolean_T Real2SimGuidance_copyexponent_j
    (emxArray_char_T_Real2SimGuidance_T *s1, int32_T *idx, const
     emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n);
static void Real2SimGuidance_readfloat_n(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T
    *foundsign, boolean_T *success);
static void Real2SimGuidance_emxFree_char_T_o(emxArray_char_T_Real2SimGuidance_T
    **pEmxArray);
static creal_T Real2SimGuidance_str2double_k(const
    emxArray_char_T_Real2SimGuidance_T *s);
static int32_T Real2SimGuidance_cfclose_m(real_T fid, DW_Real2SimGuidance_f_T
    *localDW);
static void Real2SimGuidance_strtok_o(const emxArray_char_T_Real2SimGuidance_T
    *x, emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain);
static void Real2SimGuidance_strtok_ow(const emxArray_char_T_Real2SimGuidance_T *
    x, emxArray_char_T_Real2SimGuidance_T *token);
static void Real2SimGuidance_strtrim_o(const emxArray_char_T_Real2SimGuidance_T *
    x, emxArray_char_T_Real2SimGuidance_T *y);
static boolean_T Real2SimGuidance_strcmp_b(const
    emxArray_char_T_Real2SimGuidance_T *a);
static boolean_T Real2SimGuidance_strcmp_bg(const
    emxArray_char_T_Real2SimGuidance_T *a);
static boolean_T Real2SimGuidance_contains_f(const
    emxArray_char_T_Real2SimGuidance_T *str);
static void Real2SimGuidance_find_token_m(const
    emxArray_char_T_Real2SimGuidance_T *x, int32_T *itoken, int32_T *iremain);
static void Real2SimGuidance_strtok_owf(const emxArray_char_T_Real2SimGuidance_T
    *x, emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain);
static void Real2SimGuidance_readINI_o(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_readINI_or(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_strtok_ilmz(const
    emxArray_char_T_Real2SimGuidance_T *x, emxArray_char_T_Real2SimGuidance_T
    *token);
static boolean_T Real2SimGuidance_strcmp_bgl(const
    emxArray_char_T_Real2SimGuidance_T *a);
static int8_T Real2SimGuidance_filedata_jv(DW_Real2SimGuidance_f_T *localDW);
static int8_T Real2SimGuidance_cfopen_i(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_fileManager_p(DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_fread_j(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW);
static boolean_T Real2SimGuidance_strcmp_bglv(const
    emxArray_char_T_Real2SimGuidance_T *a);
static uavDubinsConnection_Real2SimGuidance_T
    *Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_Real2SimGuidance_T *b_this, real_T varargin_2, real_T
     varargin_4);
static int32_T Real2SimGuidance_cfclose_a(real_T fid, DW_Real2SimGuidance_f_T
    *localDW);
static boolean_T Real2SimGuidance_strcmp_bglv3(const
    emxArray_char_T_Real2SimGuidance_T *a);
static void Real2SimGuidance_readINI_e(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_readINI_ew(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
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
static void Real2SimGuidance_repmat(const real_T a[2], real_T varargin_1,
    emxArray_real_T_Real2SimGuidance_T *b);
static void Real2SimGuidance_binary_expand_op_puh
    (emxArray_real_T_Real2SimGuidance_T *in1, const real_T in2[2097152], const
     int32_T in3[2], const emxArray_real_T_Real2SimGuidance_T *in4);
static int8_T Real2SimGuidance_filedata_j(DW_Real2SimGuidance_f_T *localDW);
static int8_T Real2SimGuidance_cfopen_e(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_fread_o(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_hypot(const real_T x_data[], const int32_T *x_size,
    const real_T y_data[], const int32_T *y_size, real_T r_data[], int32_T
    *r_size);
static int32_T Real2SimGuidance_cfclose_e(real_T fid, DW_Real2SimGuidance_f_T
    *localDW);
static boolean_T Real2SimGuidance_strcmp_f(const
    emxArray_char_T_Real2SimGuidance_T *a);
static void Real2SimGuidance_times_na(real_T in1_data[], int32_T *in1_size,
    const real_T in2_data[], const int32_T *in2_size);
static int8_T Real2SimGuidance_filedata_h(DW_Real2SimGuidance_f_T *localDW);
static int8_T Real2SimGuidance_cfopen_m(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW);
static real_T Real2SimGuidance_fileManager(DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_fread_b(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW);
static void Real2SimGuidance_expand_atan2(const
    emxArray_real_T_Real2SimGuidance_T *a, const
    emxArray_real_T_Real2SimGuidance_T *b, emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_times_n(real_T in1_data[], int32_T *in1_size, const
    real_T in2_data[], const int32_T *in2_size);
static int32_T Real2SimGuidance_cfclose_n(real_T fid, DW_Real2SimGuidance_f_T
    *localDW);
static void Real2SimGuidance_abs(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y);
static void Real2SimGuidance_expand_hypot(const
    emxArray_real_T_Real2SimGuidance_T *a, const
    emxArray_real_T_Real2SimGuidance_T *b, emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_emxInit_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T **pEmxArray, int32_T numDimensions);
static void Real2SimGuidance_emxEnsureCapacity_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T *emxArray, int32_T oldNumel);
static void Real2SimGuidance_binary_expand_op_pu
    (emxArray_boolean_T_Real2SimGuidance_T *in1, const
     emxArray_real_T_Real2SimGuidance_T *in2, real_T in3, const
     emxArray_real_T_Real2SimGuidance_T *in4, const real_T in5[2]);
static void Real2SimGuidance_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec,
    real_T *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon,
    real_T *t_tm_year, boolean_T *t_tm_isdst);
static creal_T Real2SimGuidance_two_prod(real_T a);
static creal_T Real2SimGuidance_two_diff(real_T a, real_T b);
static creal_T Real2SimGuidance_times(const creal_T a);
static creal_T Real2SimGuidance_minus(const creal_T a, const creal_T b);
static void Real2SimGuidance_getDateVec(const creal_T dd, real_T *y, real_T *mo,
    real_T *d, real_T *h, real_T *m, real_T *s);
static void Real2SimGuidance_emxFree_boolean_T
    (emxArray_boolean_T_Real2SimGuidance_T **pEmxArray);
static void Real2SimGuidance_readINI(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
static creal_T Real2SimGuidance_two_sum(real_T a, real_T b);
static creal_T Real2SimGuidance_plus(const creal_T a, real_T b);
static void Real2SimGuidance_readINI_p(emxArray_char_T_Real2SimGuidance_T *ret,
    DW_Real2SimGuidance_f_T *localDW);
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
static real_T Real2SimGuidance_floatmod(real_T x);
static void Real2SimGuidance_binary_expand_op_f(boolean_T in1_data[], int32_T
    *in1_size, const emxArray_real_T_Real2SimGuidance_T *in2, const
    emxArray_real_T_Real2SimGuidance_T *in3);
static void Real2SimGuidance_wrapToPi_p34c(emxArray_real_T_Real2SimGuidance_T
    *theta, DW_Real2SimGuidance_f_T *localDW);
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
static void Real2SimGuidance_nullAssignment_b(emxArray_real_T_Real2SimGuidance_T
    *x, const boolean_T idx_data[], const int32_T *idx_size);
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
    const real_T edges[120], real_T N[120], emxArray_real_T_Real2SimGuidance_T
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
static void Real2SimGuidance_times_nall(emxArray_real_T_Real2SimGuidance_T *in1,
    const emxArray_real_T_Real2SimGuidance_T *in2);
static void Real2SimGuidance_times_nal(emxArray_real_T_Real2SimGuidance_T *in1,
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
static void Real2SimGuidance_diff(const real_T x[122], real_T y[121]);
static boolean_T Real2SimGuidance_any(const real_T x[121]);
static void Real2SimGuidance_eml_find(const real_T x[121], int32_T i_data[],
    int32_T i_size[2]);
static void Real2SimGuidance_binary_expand_op_puhaq5roxr0(real_T in1_data[],
    const real_T in3_data[], const int32_T in3_size[2], int32_T in4);
static void Real2SimGuidance_diff_f(const real_T x_data[], const int32_T x_size
    [2], real_T y_data[], int32_T y_size[2]);
static void Real2SimGuidance_wrapToPi_p34(const real_T theta_data[], const
    int32_T theta_size[2], real_T b_theta_data[], int32_T b_theta_size[2]);
static void Real2SimGuidance_binary_expand_op_puhaq5roxr0o(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], const int32_T in2_size[2],
    const real_T in3_data[], const int32_T in3_size[2]);
static void Real2SimGuidance_bisectAngles(real_T theta1_data[], int32_T
    theta1_size[2], real_T theta2_data[], int32_T theta2_size[2], real_T
    bisect_data[], int32_T bisect_size[2]);
static void Real2SimGuidance_binary_expand_op_puhaq5rox(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], const int32_T in4_data[],
    const int32_T in4_size[2], const real_T in5[2], const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in6, const
    real_T in7[2]);
static void Real2SimGuidance_bsxfun(const real_T a[120], const real_T b_data[],
    const int32_T *b_size, emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_abs_pj(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y);
static void Real2SimGuidance_minimum_p(const emxArray_real_T_Real2SimGuidance_T *
    x, real_T ex_data[], int32_T *ex_size);
static void Real2SimGuidance_bsxfun_p(const emxArray_real_T_Real2SimGuidance_T
    *a, const real_T b_data[], const int32_T *b_size,
    emxArray_real_T_Real2SimGuidance_T *c);
static void Real2SimGuidance_binary_expand_op_puhaq5roxr0oyl(real_T in1_data[],
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
static int32_T Real2SimGuidance_thirdOfFive(const
    emxArray_real_T_Real2SimGuidance_T *v, int32_T ia, int32_T ib);
static void Real2SimGuidance_quickselect(emxArray_real_T_Real2SimGuidance_T *v,
    int32_T n, int32_T vlen, real_T *vn, int32_T *nfirst, int32_T *nlast);
static real_T Real2SimGuidance_vmedian(emxArray_real_T_Real2SimGuidance_T *v,
    int32_T n);
static real_T Real2SimGuidance_median(const emxArray_real_T_Real2SimGuidance_T
    *x);
static void Real2SimGuidance_binary_expand_op_p
    (emxArray_boolean_T_Real2SimGuidance_T *in1, const real_T in2[1048576],
     int32_T in3, real_T in4, const emxArray_real_T_Real2SimGuidance_T *in5,
     const emxArray_real_T_Real2SimGuidance_T *in6, int32_T in7);

//
// Output and update for atomic system:
//    '<S14>/wrap2Pi'
//    '<S9>/wrap2PiRealHdg'
//    '<S9>/wrap2PiTgtHdg'
//    '<Root>/wrap2Pi'
//
void Real2SimGuidance_wrap2Pi(real_T rtu_lambda, real_T *rty_lambdaWrapped)
{
    real_T varargout_1;
    int32_T trueCount;
    boolean_T positiveInput_data;
    boolean_T q;

    // MATLAB Function 'wrap2Pi': '<S18>:1'
    // '<S18>:1:3'
    q = static_cast<boolean_T>(static_cast<int32_T>((rtu_lambda <
        -3.1415926535897931) | (rtu_lambda > 3.1415926535897931)));
    trueCount = 0;
    if (q) {
        trueCount = 1;
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        if (std::isnan(rtu_lambda + 3.1415926535897931)) {
            varargout_1 = (rtNaN);
        } else if (std::isinf(rtu_lambda + 3.1415926535897931)) {
            varargout_1 = (rtNaN);
        } else if (rtu_lambda + 3.1415926535897931 == 0.0) {
            varargout_1 = 0.0;
        } else {
            boolean_T rEQ0;
            varargout_1 = std::fmod(rtu_lambda + 3.1415926535897931,
                                    6.2831853071795862);
            rEQ0 = (varargout_1 == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                real_T q_0;
                q_0 = std::abs((rtu_lambda + 3.1415926535897931) /
                               6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q_0
                    - std::floor(q_0 + 0.5)) > 2.2204460492503131E-16 * q_0) ^ 1));
            }

            if (rEQ0) {
                varargout_1 = 0.0;
            } else if (rtu_lambda + 3.1415926535897931 < 0.0) {
                varargout_1 += 6.2831853071795862;
            }
        }
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        positiveInput_data = static_cast<boolean_T>(static_cast<int32_T>
            ((rtu_lambda + 3.1415926535897931 > 0.0) & (varargout_1 == 0.0)));
    }

    if (positiveInput_data && (static_cast<int32_T>(trueCount - 1) >= 0)) {
        varargout_1 = 6.2831853071795862;
    }

    *rty_lambdaWrapped = rtu_lambda;
    if (q) {
        *rty_lambdaWrapped = varargout_1 - 3.1415926535897931;
    }
}

//
// Output and update for atomic system:
//    '<S15>/AngDiff'
//    '<S9>/AngDiff'
//
void Real2SimGuidance_AngDiff(real_T rtu_alpha, real_T rtu_beta, real_T
    *rty_delta)
{
    // MATLAB Function 'AngDiff': '<S19>:1'
    // '<S19>:1:3'
    *rty_delta = rtu_beta - rtu_alpha;
    if (std::abs(*rty_delta) > 3.1415926535897931) {
        real_T thetaWrap;
        if (std::isnan(*rty_delta + 3.1415926535897931)) {
            thetaWrap = (rtNaN);
        } else if (std::isinf(*rty_delta + 3.1415926535897931)) {
            thetaWrap = (rtNaN);
        } else if (*rty_delta + 3.1415926535897931 == 0.0) {
            thetaWrap = 0.0;
        } else {
            boolean_T rEQ0;
            thetaWrap = std::fmod(*rty_delta + 3.1415926535897931,
                                  6.2831853071795862);
            rEQ0 = (thetaWrap == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                real_T q;
                q = std::abs((*rty_delta + 3.1415926535897931) /
                             6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q -
                    std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
            }

            if (rEQ0) {
                thetaWrap = 0.0;
            } else if (*rty_delta + 3.1415926535897931 < 0.0) {
                thetaWrap += 6.2831853071795862;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((*rty_delta +
                3.1415926535897931 > 0.0) & (thetaWrap == 0.0)))) {
            thetaWrap = 6.2831853071795862;
        }

        *rty_delta = thetaWrap - 3.1415926535897931;
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static int8_T Real2SimGuidance_filedata(DW_ReadHomePoint_Real2SimGuidance_T
    *localDW)
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static int8_T Real2SimGuidance_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_ReadHomePoint_Real2SimGuidance_T *localDW)
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static void Real2SimGuidance_fread(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_ReadHomePoint_Real2SimGuidance_T
    *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(fileID);
    if (fileID != static_cast<real_T>(static_cast<int8_T>(fileID))) {
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
            int32_T i;
            int32_T loop_ub;
            int32_T numRead;
            int32_T tmp;
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
                i = -1;
                loop_ub = -1;
            } else {
                i = static_cast<int32_T>(c - 1);
                loop_ub = static_cast<int32_T>(c - 1);
            }

            tmp = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(i + A->size[0])
                + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static void Real2SimGuidance_copysign(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T *foundsign, boolean_T *success)
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

    boolean_T exitg1;
    boolean_T isneg;
    isneg = false;
    *foundsign = false;
    exitg1 = false;
    while ((!exitg1) && (*k <= n)) {
        char_T tmp;
        tmp = s->data[static_cast<int32_T>(*k - 1)];
        if (tmp == '-') {
            isneg = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(isneg) ^ 1));
            *foundsign = true;
            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == ',') {
            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == '+') {
            *foundsign = true;
            *k = static_cast<int32_T>(*k + 1);
        } else if (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(b[static_cast<int32_T>
                      (static_cast<int32_T>(static_cast<uint8_T>(tmp)) & 127)]) ^
                     1))) {
            exitg1 = true;
        } else {
            *k = static_cast<int32_T>(*k + 1);
        }
    }

    *success = (*k <= n);
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (*success) & static_cast<int32_T>(isneg)))) {
        if ((*idx >= 2) && (s1->data[static_cast<int32_T>(*idx - 2)] == '-')) {
            s1->data[static_cast<int32_T>(*idx - 2)] = ' ';
        } else {
            s1->data[static_cast<int32_T>(*idx - 1)] = '-';
            *idx = static_cast<int32_T>(*idx + 1);
        }
    }
}

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static boolean_T Real2SimGuidance_isUnitImag(const
    emxArray_char_T_Real2SimGuidance_T *s, int32_T k, int32_T n)
{
    boolean_T p;
    p = false;
    if (k <= n) {
        char_T c_idx_0;
        c_idx_0 = s->data[static_cast<int32_T>(k - 1)];
        if (c_idx_0 == 'j') {
            p = true;
        } else if (c_idx_0 == 'i') {
            if (k >= static_cast<int32_T>(n - 1)) {
                p = true;
            } else {
                int32_T b_k;
                char_T c_idx_1;
                char_T c_idx_2;
                b_k = k;
                c_idx_0 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_0 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                b_k = static_cast<int32_T>(b_k + 1);
                c_idx_1 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_1 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                b_k = static_cast<int32_T>(b_k + 1);
                c_idx_2 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_2 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
                     (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f')))
                {
                } else if ((c_idx_0 == 'N') || (c_idx_0 == 'n')) {
                    if ((c_idx_1 == 'A') || (c_idx_1 == 'a')) {
                        if ((c_idx_2 != 'N') && (c_idx_2 != 'n')) {
                            p = true;
                        }
                    } else {
                        p = true;
                    }
                } else {
                    p = true;
                }
            }
        }
    }

    return p;
}

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static void Real2SimGuidance_readNonFinite(const
    emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n, boolean_T
    *b_finite, real_T *fv)
{
    int32_T ksaved;
    char_T c_idx_0;
    char_T c_idx_1;
    char_T c_idx_2;
    ksaved = *k;
    c_idx_0 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    c_idx_1 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_1 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    c_idx_2 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_2 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') || (c_idx_1 ==
          'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
        *b_finite = false;
        *fv = (rtInf);
    } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
                (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
        *b_finite = false;
        *fv = (rtNaN);
    } else {
        *b_finite = true;
        *fv = 0.0;
        *k = ksaved;
    }
}

// Function for MATLAB Function: '<S6>/ReadHomePoint'
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static boolean_T Real2SimGuidance_copyexponent
    (emxArray_char_T_Real2SimGuidance_T *s1, int32_T *idx, const
     emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n)
{
    int32_T b_k;
    boolean_T success;
    success = true;
    if (*k <= n) {
        char_T tmp;
        tmp = s->data[static_cast<int32_T>(*k - 1)];
        if ((tmp == 'E') || (tmp == 'e')) {
            int32_T kexp;
            boolean_T b_success;
            s1->data[static_cast<int32_T>(*idx - 1)] = 'e';
            *idx = static_cast<int32_T>(*idx + 1);
            *k = static_cast<int32_T>(*k + 1);
            while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ','))
            {
                *k = static_cast<int32_T>(*k + 1);
            }

            if (*k <= n) {
                if (s->data[static_cast<int32_T>(*k - 1)] == '-') {
                    s1->data[static_cast<int32_T>(*idx - 1)] = '-';
                    *idx = static_cast<int32_T>(*idx + 1);
                    *k = static_cast<int32_T>(*k + 1);
                } else if (s->data[static_cast<int32_T>(*k - 1)] == '+') {
                    *k = static_cast<int32_T>(*k + 1);
                }
            }

            kexp = *k;
            b_k = *k;
            b_success = Real2SimGuidance_copydigits(s1, idx, s, &b_k, n, false);
            *k = b_k;
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(b_success) ^ 1))) | (b_k <= kexp)))) {
                success = false;
            }
        }
    }

    return success;
}

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static void Real2SimGuidance_readfloat(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T
    *foundsign, boolean_T *success)
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

    int32_T b_idx;
    int32_T b_k;
    boolean_T a__3;
    *isimag = false;
    *b_finite = true;
    *nfv = 0.0;
    b_idx = *idx;
    b_k = *k;
    Real2SimGuidance_copysign(s1, &b_idx, s, &b_k, n, foundsign, success);
    *idx = b_idx;
    *k = b_k;
    if (*success) {
        char_T tmp;
        boolean_T exitg1;
        if (Real2SimGuidance_isUnitImag(s, b_k, n)) {
            *isimag = true;
            *k = static_cast<int32_T>(b_k + 1);
            exitg1 = false;
            while ((!exitg1) && (*k <= n)) {
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(tmp)) & 127)] ||
                    (tmp == '\x00') || (tmp == ',')) {
                    *k = static_cast<int32_T>(*k + 1);
                } else {
                    exitg1 = true;
                }
            }

            if ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == '*')) {
                b_k = static_cast<int32_T>(*k + 1);
                Real2SimGuidance_copysign(s1, &b_idx, s, &b_k, n, &a__3, success);
                *idx = b_idx;
                if (*success) {
                    if (Real2SimGuidance_isUnitImag(s, b_k, n)) {
                        *success = false;
                    } else {
                        Real2SimGuidance_readNonFinite(s, &b_k, n, b_finite, nfv);
                        if (*b_finite) {
                            *success = Real2SimGuidance_copydigits(s1, idx, s,
                                &b_k, n, true);
                            if (*success) {
                                *success = Real2SimGuidance_copyexponent(s1, idx,
                                    s, &b_k, n);
                            }
                        } else if ((b_idx >= 2) && (s1->data[static_cast<int32_T>
                                                    (b_idx - 2)] == '-')) {
                            *idx = static_cast<int32_T>(b_idx - 1);
                            s1->data[static_cast<int32_T>(b_idx - 2)] = ' ';
                            *nfv = -*nfv;
                        }

                        exitg1 = false;
                        while ((!exitg1) && (b_k <= n)) {
                            tmp = s->data[static_cast<int32_T>(b_k - 1)];
                            if (b[static_cast<int32_T>(static_cast<int32_T>(
                                    static_cast<uint8_T>(tmp)) & 127)] || (tmp ==
                                 '\x00') || (tmp == ',')) {
                                b_k = static_cast<int32_T>(b_k + 1);
                            } else {
                                exitg1 = true;
                            }
                        }

                        if ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)]
                                           == '*')) {
                            b_k = static_cast<int32_T>(b_k + 1);
                            exitg1 = false;
                            while ((!exitg1) && (b_k <= n)) {
                                tmp = s->data[static_cast<int32_T>(b_k - 1)];
                                if (b[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(tmp)) & 127)] ||
                                        (tmp == '\x00') || (tmp == ',')) {
                                    b_k = static_cast<int32_T>(b_k + 1);
                                } else {
                                    exitg1 = true;
                                }
                            }
                        }

                        if (b_k <= n) {
                            tmp = s->data[static_cast<int32_T>(b_k - 1)];
                            if ((tmp == 'i') || (tmp == 'j')) {
                                b_k = static_cast<int32_T>(b_k + 1);
                            }
                        }
                    }

                    exitg1 = false;
                    while ((!exitg1) && (b_k <= n)) {
                        tmp = s->data[static_cast<int32_T>(b_k - 1)];
                        if (b[static_cast<int32_T>(static_cast<int32_T>(
                                static_cast<uint8_T>(tmp)) & 127)] || (tmp ==
                                '\x00') || (tmp == ',')) {
                            b_k = static_cast<int32_T>(b_k + 1);
                        } else {
                            exitg1 = true;
                        }
                    }
                }

                *k = b_k;
            } else {
                s1->data[static_cast<int32_T>(b_idx - 1)] = '1';
                *idx = static_cast<int32_T>(b_idx + 1);
            }
        } else {
            Real2SimGuidance_readNonFinite(s, &b_k, n, b_finite, nfv);
            *k = b_k;
            if (*b_finite) {
                *success = Real2SimGuidance_copydigits(s1, idx, s, k, n, true);
                if (*success) {
                    *success = Real2SimGuidance_copyexponent(s1, idx, s, k, n);
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
                    tmp = s->data[static_cast<int32_T>(*k - 1)];
                    if ((tmp == '\x00') || (tmp == ',')) {
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
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if ((tmp == 'i') || (tmp == 'j')) {
                    *k = static_cast<int32_T>(*k + 1);
                    *isimag = true;
                }
            }
        }

        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
            if (b[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                    (s->data[static_cast<int32_T>(*k - 1)])) & 127)]) {
                *k = static_cast<int32_T>(*k + 1);
            } else {
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if ((tmp == '\x00') || (tmp == ',')) {
                    *k = static_cast<int32_T>(*k + 1);
                } else {
                    exitg1 = true;
                }
            }
        }
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
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
    x.re = (rtNaN);
    x.im = 0.0;
    if (s->size[1] >= 1) {
        int32_T i;
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

        i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
        s1->size[0] = 1;
        s1->size[1] = static_cast<int32_T>(s->size[1] + 2);
        Real2SimGuidance_emxEnsureCapacity_char_T(s1, i);
        idx = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(idx + 1); i++) {
            s1->data[i] = '\x00';
        }

        idx = 1;
        Real2SimGuidance_readfloat(s1, &idx, s, &k, s->size[1], &isimag1,
            &isfinite1, &scanned1, &a__1, &success);
        if (isfinite1) {
            ntoread = 1;
        }

        if (success) {
            if (k <= s->size[1]) {
                s1->data[static_cast<int32_T>(idx - 1)] = ' ';
                idx = static_cast<int32_T>(idx + 1);
                Real2SimGuidance_readfloat(s1, &idx, s, &k, s->size[1], &a__1,
                    &success, &scanned2, &foundsign, &c_success);
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

    return x;
}

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static int32_T Real2SimGuidance_cfclose(real_T fid,
    DW_ReadHomePoint_Real2SimGuidance_T *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(fid);
    if (fid != static_cast<real_T>(static_cast<int8_T>(fid))) {
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static void Real2SimGuidance_strtok_j(const emxArray_char_T_Real2SimGuidance_T
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
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

    static const char_T d[9]{ 'H', 'o', 'm', 'e', 'P', 'o', 'i', 'n', 't' };

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
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static boolean_T Real2SimGuidance_strcmp_h(const
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

    static const char_T d[3]{ 'L', 'a', 't' };

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
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static void Real2SimGuidance_strtok_jy(const emxArray_char_T_Real2SimGuidance_T *
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static boolean_T Real2SimGuidance_strcmp_hd(const
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

    static const char_T d[3]{ 'L', 'o', 'n' };

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
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

// Function for MATLAB Function: '<S6>/ReadHomePoint'
static boolean_T Real2SimGuidance_strcmp_hdl(const
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

    static const char_T d[3]{ 'A', 'l', 't' };

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
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

//
// System initialize for atomic system:
//    '<S6>/ReadHomePoint'
//    '<S7>/ReadHomePoint'
//
void Real2SimGuidance_ReadHomePoint_Init(DW_ReadHomePoint_Real2SimGuidance_T
    *localDW)
{
    FILE* a;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }
}

//
// Output and update for atomic system:
//    '<S6>/ReadHomePoint'
//    '<S7>/ReadHomePoint'
//
void Real2SimGuidance_ReadHomePoint(real_T rty_LLA0[3],
    DW_ReadHomePoint_Real2SimGuidance_T *localDW)
{
    emxArray_char_T_Real2SimGuidance_T *curKey;
    emxArray_char_T_Real2SimGuidance_T *curLine;
    emxArray_char_T_Real2SimGuidance_T *curSection;
    emxArray_char_T_Real2SimGuidance_T *curVal;
    emxArray_char_T_Real2SimGuidance_T *data;
    emxArray_char_T_Real2SimGuidance_T *data_0;
    emxArray_char_T_Real2SimGuidance_T *data_1;
    emxArray_char_T_Real2SimGuidance_T *data_2;
    emxArray_char_T_Real2SimGuidance_T *q;
    emxArray_char_T_Real2SimGuidance_T *ret;
    emxArray_char_T_Real2SimGuidance_T *tmp_2;
    emxArray_char_T_Real2SimGuidance_T *tmp_3;
    emxArray_char_T_Real2SimGuidance_T *tmp_4;
    emxArray_char_T_Real2SimGuidance_T *x;
    int32_T iremain;
    int32_T itoken;
    boolean_T b_x[3];

    // MATLAB Function 'ReadHomePoint': '<S43>:1'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (localDW->HomePoint_not_empty) ^ 1))) {
        creal_T tmp;
        creal_T tmp_0;
        creal_T tmp_1;
        int32_T i;
        int32_T loop_ub;
        int8_T fileid;
        boolean_T b_bool;
        boolean_T exitg1;
        boolean_T guard1{ false };

        // '<S43>:1:5'
        // '<S43>:1:6'
        Real2SimGuidance_emxInit_char_T(&ret, 2);
        ret->size[0] = 1;
        ret->size[1] = 0;
        fileid = Real2SimGuidance_cfopen("config.ini", "rb", localDW);
        Real2SimGuidance_emxInit_char_T(&data, 2);
        Real2SimGuidance_emxInit_char_T(&curSection, 2);
        Real2SimGuidance_emxInit_char_T(&curKey, 2);
        Real2SimGuidance_emxInit_char_T(&curVal, 2);
        Real2SimGuidance_emxInit_char_T(&curLine, 2);
        Real2SimGuidance_emxInit_char_T(&x, 2);
        Real2SimGuidance_emxInit_char_T(&q, 1);
        if (static_cast<int32_T>(fileid) < 0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            Real2SimGuidance_fread(static_cast<real_T>(fileid), q, localDW);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            Real2SimGuidance_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            Real2SimGuidance_cfclose(static_cast<real_T>(fileid), localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            Real2SimGuidance_emxInit_char_T(&tmp_4, 2);
            Real2SimGuidance_emxInit_char_T(&data_2, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_2->size[0] * data_2->size[1]);
                data_2->size[0] = 1;
                data_2->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_2, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_2->data[i] = data->data[i];
                }

                Real2SimGuidance_strtok(data_2, curLine, data);
                Real2SimGuidance_strtok_j(curLine, tmp_4);
                Real2SimGuidance_strtrim(tmp_4, curLine);
                if (curLine->size[1] >= 2) {
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

                            i = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(iremain + i)];
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
                            Real2SimGuidance_strtok_jy(curLine, curVal, x);
                            Real2SimGuidance_find_token(x, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(curVal, curKey);
                            i = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curLine->data[i] = x->data[static_cast<int32_T>
                                    (itoken + i)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp(curSection) &&
                        Real2SimGuidance_strcmp_h(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            Real2SimGuidance_emxFree_char_T(&data_2);
            Real2SimGuidance_emxFree_char_T(&tmp_4);
        }

        tmp = Real2SimGuidance_str2double(ret);
        printf("Set Home Point Latitude:\t%f\n", tmp.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        fileid = Real2SimGuidance_cfopen("config.ini", "rb", localDW);
        if (static_cast<int32_T>(fileid) < 0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            Real2SimGuidance_fread(static_cast<real_T>(fileid), q, localDW);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            Real2SimGuidance_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            Real2SimGuidance_cfclose(static_cast<real_T>(fileid), localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            Real2SimGuidance_emxInit_char_T(&tmp_3, 2);
            Real2SimGuidance_emxInit_char_T(&data_1, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_1->size[0] * data_1->size[1]);
                data_1->size[0] = 1;
                data_1->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_1, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_1->data[i] = data->data[i];
                }

                Real2SimGuidance_strtok(data_1, curLine, data);
                Real2SimGuidance_strtok_j(curLine, tmp_3);
                Real2SimGuidance_strtrim(tmp_3, curLine);
                if (curLine->size[1] >= 2) {
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

                            i = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(iremain + i)];
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
                            Real2SimGuidance_strtok_jy(curLine, curVal, x);
                            Real2SimGuidance_find_token(x, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(curVal, curKey);
                            i = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curLine->data[i] = x->data[static_cast<int32_T>
                                    (itoken + i)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp(curSection) &&
                        Real2SimGuidance_strcmp_hd(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            Real2SimGuidance_emxFree_char_T(&data_1);
            Real2SimGuidance_emxFree_char_T(&tmp_3);
        }

        tmp_0 = Real2SimGuidance_str2double(ret);
        printf("Set Home Point Longitude:\t%f\n", tmp_0.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        fileid = Real2SimGuidance_cfopen("config.ini", "rb", localDW);
        if (static_cast<int32_T>(fileid) < 0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            Real2SimGuidance_fread(static_cast<real_T>(fileid), q, localDW);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            Real2SimGuidance_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            Real2SimGuidance_cfclose(static_cast<real_T>(fileid), localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            Real2SimGuidance_emxInit_char_T(&tmp_2, 2);
            Real2SimGuidance_emxInit_char_T(&data_0, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T(data_0, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_0->data[i] = data->data[i];
                }

                Real2SimGuidance_strtok(data_0, curLine, data);
                Real2SimGuidance_strtok_j(curLine, tmp_2);
                Real2SimGuidance_strtrim(tmp_2, curLine);
                if (curLine->size[1] >= 2) {
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

                            i = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curSection,
                                i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(iremain + i)];
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
                            Real2SimGuidance_strtok_jy(curLine, curVal, x);
                            Real2SimGuidance_find_token(x, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim(curVal, curKey);
                            i = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T(curLine, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curLine->data[i] = x->data[static_cast<int32_T>
                                    (itoken + i)];
                            }

                            Real2SimGuidance_strtrim(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp(curSection) &&
                        Real2SimGuidance_strcmp_hdl(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            Real2SimGuidance_emxFree_char_T(&data_0);
            Real2SimGuidance_emxFree_char_T(&tmp_2);
        }

        Real2SimGuidance_emxFree_char_T(&q);
        Real2SimGuidance_emxFree_char_T(&x);
        Real2SimGuidance_emxFree_char_T(&curLine);
        Real2SimGuidance_emxFree_char_T(&curVal);
        Real2SimGuidance_emxFree_char_T(&curKey);
        Real2SimGuidance_emxFree_char_T(&curSection);
        Real2SimGuidance_emxFree_char_T(&data);
        tmp_1 = Real2SimGuidance_str2double(ret);
        Real2SimGuidance_emxFree_char_T(&ret);
        printf("Set Home Point Altitude:\t%f\n", tmp_1.re);
        fflush(stdout);
        localDW->HomePoint[0] = tmp.re;
        localDW->HomePoint[1] = tmp_0.re;
        localDW->HomePoint[2] = tmp_1.re;
        localDW->HomePoint_not_empty = true;
        b_x[0] = std::isnan(localDW->HomePoint[0]);
        b_x[1] = std::isnan(localDW->HomePoint[1]);
        b_x[2] = std::isnan(localDW->HomePoint[2]);
        b_bool = false;
        iremain = 0;
        exitg1 = false;
        while ((!exitg1) && (iremain < 3)) {
            if (b_x[iremain]) {
                b_bool = true;
                exitg1 = true;
            } else {
                iremain = static_cast<int32_T>(iremain + 1);
            }
        }

        if (b_bool) {
            // '<S43>:1:7'
            // '<S43>:1:8'
            localDW->HomePoint[0] = 35.8617;
            localDW->HomePoint[1] = 104.1954;
            localDW->HomePoint[2] = 0.0;
        }
    }

    // '<S43>:1:12'
    rty_LLA0[0] = localDW->HomePoint[0];
    rty_LLA0[1] = localDW->HomePoint[1];
    rty_LLA0[2] = localDW->HomePoint[2];
}

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
    d2scaled = obj->AngularLimits[0] + 0.026179938779914941;
    obj->AngularSectorMidPoints[119] = obj->AngularLimits[1] -
        0.026179938779914941;
    obj->AngularSectorMidPoints[0] = obj->AngularLimits[0] +
        0.026179938779914941;
    if (obj->AngularLimits[0] + 0.026179938779914941 == -(obj->AngularLimits[1]
            - 0.026179938779914941)) {
        d2scaled = (obj->AngularLimits[1] - 0.026179938779914941) / 119.0;
        for (int32_T d_k{0}; d_k < 118; d_k++) {
            obj->AngularSectorMidPoints[static_cast<int32_T>(d_k + 1)] = (
                static_cast<real_T>(static_cast<int32_T>(static_cast<int32_T>
                (d_k + 2) << 1)) - 121.0) * d2scaled;
        }
    } else if (((obj->AngularLimits[0] + 0.026179938779914941 < 0.0) !=
                (obj->AngularLimits[1] - 0.026179938779914941 < 0.0)) && ((std::
                 abs(obj->AngularLimits[0] + 0.026179938779914941) >
                 8.9884656743115785E+307) || (std::abs(obj->AngularLimits[1] -
                  0.026179938779914941) > 8.9884656743115785E+307))) {
        real_T delta1;
        real_T delta2;
        delta1 = (obj->AngularLimits[0] + 0.026179938779914941) / 119.0;
        delta2 = (obj->AngularLimits[1] - 0.026179938779914941) / 119.0;
        for (int32_T d_k{0}; d_k < 118; d_k++) {
            obj->AngularSectorMidPoints[static_cast<int32_T>(d_k + 1)] = ((
                static_cast<real_T>(d_k) + 1.0) * delta2 + d2scaled) - (
                static_cast<real_T>(d_k) + 1.0) * delta1;
        }
    } else {
        real_T delta1;
        delta1 = ((obj->AngularLimits[1] - 0.026179938779914941) -
                  (obj->AngularLimits[0] + 0.026179938779914941)) / 119.0;
        for (int32_T d_k{0}; d_k < 118; d_k++) {
            obj->AngularSectorMidPoints[static_cast<int32_T>(d_k + 1)] = (
                static_cast<real_T>(d_k) + 1.0) * delta1 + d2scaled;
        }
    }

    obj->AngularDifference = std::abs(Real2SimGuidance_wrapToPi_p
        (obj->AngularSectorMidPoints[1] - obj->AngularSectorMidPoints[0]));
    d2scaled = obj->AngularDifference / 2.0;
    for (int32_T d_k{0}; d_k < 120; d_k++) {
        obj->AngularSectorStartPoints[d_k] = obj->AngularSectorMidPoints[d_k] -
            d2scaled;
        obj->BinaryHistogram[d_k] = false;
    }
}

static void Real2SimGuidance_emxInit_char_T_e(emxArray_char_T_Real2SimGuidance_T
    **pEmxArray, int32_T numDimensions)
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

// Function for MATLAB Function: '<S99>/getSpeedLimit'
static int8_T Real2SimGuidance_filedata_k(DW_Real2SimGuidance_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles_p[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S99>/getSpeedLimit'
static int8_T Real2SimGuidance_cfopen_is(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = Real2SimGuidance_filedata_k(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles_p[static_cast<int32_T>(static_cast<int32_T>(j)
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

// Function for MATLAB Function: '<S99>/getSpeedLimit'
static real_T Real2SimGuidance_fileManager_b(DW_Real2SimGuidance_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = Real2SimGuidance_cfopen_is("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
}

static void Real2SimGuidance_emxEnsureCapacity_char_T_g
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

// Function for MATLAB Function: '<S99>/getSpeedLimit'
static void Real2SimGuidance_fread_h(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(fileID);
    if (fileID != static_cast<real_T>(static_cast<int8_T>(fileID))) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        filestar = localDW->eml_openfiles_p[static_cast<int32_T>(static_cast<
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
            int32_T i;
            int32_T loop_ub;
            int32_T numRead;
            int32_T tmp;
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
                i = -1;
                loop_ub = -1;
            } else {
                i = static_cast<int32_T>(c - 1);
                loop_ub = static_cast<int32_T>(c - 1);
            }

            tmp = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(i + A->size[0])
                + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T_g(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_copysign_l(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T *foundsign, boolean_T *success)
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

    boolean_T exitg1;
    boolean_T isneg;
    isneg = false;
    *foundsign = false;
    exitg1 = false;
    while ((!exitg1) && (*k <= n)) {
        char_T tmp;
        tmp = s->data[static_cast<int32_T>(*k - 1)];
        if (tmp == '-') {
            isneg = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(isneg) ^ 1));
            *foundsign = true;
            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == ',') {
            *k = static_cast<int32_T>(*k + 1);
        } else if (tmp == '+') {
            *foundsign = true;
            *k = static_cast<int32_T>(*k + 1);
        } else if (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(b[static_cast<int32_T>
                      (static_cast<int32_T>(static_cast<uint8_T>(tmp)) & 127)]) ^
                     1))) {
            exitg1 = true;
        } else {
            *k = static_cast<int32_T>(*k + 1);
        }
    }

    *success = (*k <= n);
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (*success) & static_cast<int32_T>(isneg)))) {
        if ((*idx >= 2) && (s1->data[static_cast<int32_T>(*idx - 2)] == '-')) {
            s1->data[static_cast<int32_T>(*idx - 2)] = ' ';
        } else {
            s1->data[static_cast<int32_T>(*idx - 1)] = '-';
            *idx = static_cast<int32_T>(*idx + 1);
        }
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static boolean_T Real2SimGuidance_isUnitImag_g(const
    emxArray_char_T_Real2SimGuidance_T *s, int32_T k, int32_T n)
{
    boolean_T p;
    p = false;
    if (k <= n) {
        char_T c_idx_0;
        c_idx_0 = s->data[static_cast<int32_T>(k - 1)];
        if (c_idx_0 == 'j') {
            p = true;
        } else if (c_idx_0 == 'i') {
            if (k >= static_cast<int32_T>(n - 1)) {
                p = true;
            } else {
                int32_T b_k;
                char_T c_idx_1;
                char_T c_idx_2;
                b_k = k;
                c_idx_0 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_0 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                b_k = static_cast<int32_T>(b_k + 1);
                c_idx_1 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_1 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                b_k = static_cast<int32_T>(b_k + 1);
                c_idx_2 = '\x00';
                while ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)] ==
                                      ',')) {
                    b_k = static_cast<int32_T>(b_k + 1);
                }

                if (b_k <= n) {
                    c_idx_2 = s->data[static_cast<int32_T>(b_k - 1)];
                }

                if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
                     (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f')))
                {
                } else if ((c_idx_0 == 'N') || (c_idx_0 == 'n')) {
                    if ((c_idx_1 == 'A') || (c_idx_1 == 'a')) {
                        if ((c_idx_2 != 'N') && (c_idx_2 != 'n')) {
                            p = true;
                        }
                    } else {
                        p = true;
                    }
                } else {
                    p = true;
                }
            }
        }
    }

    return p;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_readNonFinite_m(const
    emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n, boolean_T
    *b_finite, real_T *fv)
{
    int32_T ksaved;
    char_T c_idx_0;
    char_T c_idx_1;
    char_T c_idx_2;
    ksaved = *k;
    c_idx_0 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_0 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    c_idx_1 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_1 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    c_idx_2 = '\x00';
    while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ',')) {
        *k = static_cast<int32_T>(*k + 1);
    }

    if (*k <= n) {
        c_idx_2 = s->data[static_cast<int32_T>(*k - 1)];
    }

    *k = static_cast<int32_T>(*k + 1);
    if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') || (c_idx_1 ==
          'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
        *b_finite = false;
        *fv = (rtInf);
    } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
                (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
        *b_finite = false;
        *fv = (rtNaN);
    } else {
        *b_finite = true;
        *fv = 0.0;
        *k = ksaved;
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static boolean_T Real2SimGuidance_copydigits_e
    (emxArray_char_T_Real2SimGuidance_T *s1, int32_T *idx, const
     emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n, boolean_T
     allowpoint)
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
static boolean_T Real2SimGuidance_copyexponent_j
    (emxArray_char_T_Real2SimGuidance_T *s1, int32_T *idx, const
     emxArray_char_T_Real2SimGuidance_T *s, int32_T *k, int32_T n)
{
    int32_T b_k;
    boolean_T success;
    success = true;
    if (*k <= n) {
        char_T tmp;
        tmp = s->data[static_cast<int32_T>(*k - 1)];
        if ((tmp == 'E') || (tmp == 'e')) {
            int32_T kexp;
            boolean_T b_success;
            s1->data[static_cast<int32_T>(*idx - 1)] = 'e';
            *idx = static_cast<int32_T>(*idx + 1);
            *k = static_cast<int32_T>(*k + 1);
            while ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == ','))
            {
                *k = static_cast<int32_T>(*k + 1);
            }

            if (*k <= n) {
                if (s->data[static_cast<int32_T>(*k - 1)] == '-') {
                    s1->data[static_cast<int32_T>(*idx - 1)] = '-';
                    *idx = static_cast<int32_T>(*idx + 1);
                    *k = static_cast<int32_T>(*k + 1);
                } else if (s->data[static_cast<int32_T>(*k - 1)] == '+') {
                    *k = static_cast<int32_T>(*k + 1);
                }
            }

            kexp = *k;
            b_k = *k;
            b_success = Real2SimGuidance_copydigits_e(s1, idx, s, &b_k, n, false);
            *k = b_k;
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(b_success) ^ 1))) | (b_k <= kexp)))) {
                success = false;
            }
        }
    }

    return success;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_readfloat_n(emxArray_char_T_Real2SimGuidance_T *s1,
    int32_T *idx, const emxArray_char_T_Real2SimGuidance_T *s, int32_T *k,
    int32_T n, boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T
    *foundsign, boolean_T *success)
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

    int32_T b_idx;
    int32_T b_k;
    boolean_T a__3;
    *isimag = false;
    *b_finite = true;
    *nfv = 0.0;
    b_idx = *idx;
    b_k = *k;
    Real2SimGuidance_copysign_l(s1, &b_idx, s, &b_k, n, foundsign, success);
    *idx = b_idx;
    *k = b_k;
    if (*success) {
        char_T tmp;
        boolean_T exitg1;
        if (Real2SimGuidance_isUnitImag_g(s, b_k, n)) {
            *isimag = true;
            *k = static_cast<int32_T>(b_k + 1);
            exitg1 = false;
            while ((!exitg1) && (*k <= n)) {
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if (b[static_cast<int32_T>(static_cast<int32_T>
                                           (static_cast<uint8_T>(tmp)) & 127)] ||
                    (tmp == '\x00') || (tmp == ',')) {
                    *k = static_cast<int32_T>(*k + 1);
                } else {
                    exitg1 = true;
                }
            }

            if ((*k <= n) && (s->data[static_cast<int32_T>(*k - 1)] == '*')) {
                b_k = static_cast<int32_T>(*k + 1);
                Real2SimGuidance_copysign_l(s1, &b_idx, s, &b_k, n, &a__3,
                    success);
                *idx = b_idx;
                if (*success) {
                    if (Real2SimGuidance_isUnitImag_g(s, b_k, n)) {
                        *success = false;
                    } else {
                        Real2SimGuidance_readNonFinite_m(s, &b_k, n, b_finite,
                            nfv);
                        if (*b_finite) {
                            *success = Real2SimGuidance_copydigits_e(s1, idx, s,
                                &b_k, n, true);
                            if (*success) {
                                *success = Real2SimGuidance_copyexponent_j(s1,
                                    idx, s, &b_k, n);
                            }
                        } else if ((b_idx >= 2) && (s1->data[static_cast<int32_T>
                                                    (b_idx - 2)] == '-')) {
                            *idx = static_cast<int32_T>(b_idx - 1);
                            s1->data[static_cast<int32_T>(b_idx - 2)] = ' ';
                            *nfv = -*nfv;
                        }

                        exitg1 = false;
                        while ((!exitg1) && (b_k <= n)) {
                            tmp = s->data[static_cast<int32_T>(b_k - 1)];
                            if (b[static_cast<int32_T>(static_cast<int32_T>(
                                    static_cast<uint8_T>(tmp)) & 127)] || (tmp ==
                                 '\x00') || (tmp == ',')) {
                                b_k = static_cast<int32_T>(b_k + 1);
                            } else {
                                exitg1 = true;
                            }
                        }

                        if ((b_k <= n) && (s->data[static_cast<int32_T>(b_k - 1)]
                                           == '*')) {
                            b_k = static_cast<int32_T>(b_k + 1);
                            exitg1 = false;
                            while ((!exitg1) && (b_k <= n)) {
                                tmp = s->data[static_cast<int32_T>(b_k - 1)];
                                if (b[static_cast<int32_T>(static_cast<int32_T>(
                                        static_cast<uint8_T>(tmp)) & 127)] ||
                                        (tmp == '\x00') || (tmp == ',')) {
                                    b_k = static_cast<int32_T>(b_k + 1);
                                } else {
                                    exitg1 = true;
                                }
                            }
                        }

                        if (b_k <= n) {
                            tmp = s->data[static_cast<int32_T>(b_k - 1)];
                            if ((tmp == 'i') || (tmp == 'j')) {
                                b_k = static_cast<int32_T>(b_k + 1);
                            }
                        }
                    }

                    exitg1 = false;
                    while ((!exitg1) && (b_k <= n)) {
                        tmp = s->data[static_cast<int32_T>(b_k - 1)];
                        if (b[static_cast<int32_T>(static_cast<int32_T>(
                                static_cast<uint8_T>(tmp)) & 127)] || (tmp ==
                                '\x00') || (tmp == ',')) {
                            b_k = static_cast<int32_T>(b_k + 1);
                        } else {
                            exitg1 = true;
                        }
                    }
                }

                *k = b_k;
            } else {
                s1->data[static_cast<int32_T>(b_idx - 1)] = '1';
                *idx = static_cast<int32_T>(b_idx + 1);
            }
        } else {
            Real2SimGuidance_readNonFinite_m(s, &b_k, n, b_finite, nfv);
            *k = b_k;
            if (*b_finite) {
                *success = Real2SimGuidance_copydigits_e(s1, idx, s, k, n, true);
                if (*success) {
                    *success = Real2SimGuidance_copyexponent_j(s1, idx, s, k, n);
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
                    tmp = s->data[static_cast<int32_T>(*k - 1)];
                    if ((tmp == '\x00') || (tmp == ',')) {
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
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if ((tmp == 'i') || (tmp == 'j')) {
                    *k = static_cast<int32_T>(*k + 1);
                    *isimag = true;
                }
            }
        }

        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
            if (b[static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>
                    (s->data[static_cast<int32_T>(*k - 1)])) & 127)]) {
                *k = static_cast<int32_T>(*k + 1);
            } else {
                tmp = s->data[static_cast<int32_T>(*k - 1)];
                if ((tmp == '\x00') || (tmp == ',')) {
                    *k = static_cast<int32_T>(*k + 1);
                } else {
                    exitg1 = true;
                }
            }
        }
    }
}

static void Real2SimGuidance_emxFree_char_T_o(emxArray_char_T_Real2SimGuidance_T
    **pEmxArray)
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

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static creal_T Real2SimGuidance_str2double_k(const
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
    x.re = (rtNaN);
    x.im = 0.0;
    if (s->size[1] >= 1) {
        int32_T i;
        int32_T ntoread;
        boolean_T exitg1;
        Real2SimGuidance_emxInit_char_T_e(&s1, 2);
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

        i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
        s1->size[0] = 1;
        s1->size[1] = static_cast<int32_T>(s->size[1] + 2);
        Real2SimGuidance_emxEnsureCapacity_char_T_g(s1, i);
        idx = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(idx + 1); i++) {
            s1->data[i] = '\x00';
        }

        idx = 1;
        Real2SimGuidance_readfloat_n(s1, &idx, s, &k, s->size[1], &isimag1,
            &isfinite1, &scanned1, &a__1, &success);
        if (isfinite1) {
            ntoread = 1;
        }

        if (success) {
            if (k <= s->size[1]) {
                s1->data[static_cast<int32_T>(idx - 1)] = ' ';
                idx = static_cast<int32_T>(idx + 1);
                Real2SimGuidance_readfloat_n(s1, &idx, s, &k, s->size[1], &a__1,
                    &success, &scanned2, &foundsign, &c_success);
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

        Real2SimGuidance_emxFree_char_T_o(&s1);
    }

    return x;
}

// Function for MATLAB Function: '<S99>/getSpeedLimit'
static int32_T Real2SimGuidance_cfclose_m(real_T fid, DW_Real2SimGuidance_f_T
    *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(fid);
    if (fid != static_cast<real_T>(static_cast<int8_T>(fid))) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = localDW->eml_openfiles_p[static_cast<int32_T>
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
            localDW->eml_openfiles_p[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_strtok_o(const emxArray_char_T_Real2SimGuidance_T
    *x, emxArray_char_T_Real2SimGuidance_T *token,
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
    Real2SimGuidance_emxEnsureCapacity_char_T_g(remain, i);
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
    Real2SimGuidance_emxEnsureCapacity_char_T_g(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_strtok_ow(const emxArray_char_T_Real2SimGuidance_T *
    x, emxArray_char_T_Real2SimGuidance_T *token)
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
    Real2SimGuidance_emxEnsureCapacity_char_T_g(token, itoken);
    for (itoken = 0; itoken <= static_cast<int32_T>(k - 1); itoken++) {
        token->data[itoken] = x->data[static_cast<int32_T>(n + itoken)];
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static void Real2SimGuidance_strtrim_o(const emxArray_char_T_Real2SimGuidance_T *
    x, emxArray_char_T_Real2SimGuidance_T *y)
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
    Real2SimGuidance_emxEnsureCapacity_char_T_g(y, i);
    for (i = 0; i <= j2; i++) {
        y->data[i] = x->data[static_cast<int32_T>(b_j1 + i)];
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_b(const
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
    Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

    Real2SimGuidance_emxFree_char_T_o(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_bg(const
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
    Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

    Real2SimGuidance_emxFree_char_T_o(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static boolean_T Real2SimGuidance_contains_f(const
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
static void Real2SimGuidance_find_token_m(const
    emxArray_char_T_Real2SimGuidance_T *x, int32_T *itoken, int32_T *iremain)
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
static void Real2SimGuidance_strtok_owf(const emxArray_char_T_Real2SimGuidance_T
    *x, emxArray_char_T_Real2SimGuidance_T *token,
    emxArray_char_T_Real2SimGuidance_T *remain)
{
    int32_T b;
    int32_T c;
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    Real2SimGuidance_find_token_m(x, &itoken, &iremain);
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
    Real2SimGuidance_emxEnsureCapacity_char_T_g(remain, i);
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
    Real2SimGuidance_emxEnsureCapacity_char_T_g(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S99>/getSpeedLimit'
static void Real2SimGuidance_readINI_o(emxArray_char_T_Real2SimGuidance_T *ret,
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
    fileid = Real2SimGuidance_cfopen_is("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T_e(&j, 1);
        Real2SimGuidance_fread_h(static_cast<real_T>(fileid), j, localDW);
        Real2SimGuidance_emxInit_char_T_e(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        Real2SimGuidance_emxFree_char_T_o(&j);
        Real2SimGuidance_cfclose_m(static_cast<real_T>(fileid), localDW);
        Real2SimGuidance_emxInit_char_T_e(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curLine, 2);
        Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&tmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                Real2SimGuidance_strtok_o(data_0, curLine, data);
                Real2SimGuidance_strtok_ow(curLine, tmp);
                Real2SimGuidance_strtrim_o(tmp, curLine);
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

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g
                                (curSection, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curSection->data[i_0] = curLine->data[
                                    static_cast<int32_T>(iremain + i_0)];
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
                                Real2SimGuidance_contains_f(curLine)) {
                            Real2SimGuidance_strtok_owf(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token_m(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim_o(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            Real2SimGuidance_strtrim_o(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
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
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i_0);
                        loop_ub = curVal->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            ret->data[i_0] = curVal->data[i_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T_o(&data_0);
        Real2SimGuidance_emxFree_char_T_o(&tmp);
        Real2SimGuidance_emxFree_char_T_o(&aTmp);
        Real2SimGuidance_emxFree_char_T_o(&curLine);
        Real2SimGuidance_emxFree_char_T_o(&curVal);
        Real2SimGuidance_emxFree_char_T_o(&curKey);
        Real2SimGuidance_emxFree_char_T_o(&curSection);
        Real2SimGuidance_emxFree_char_T_o(&data);
    }
}

// Function for MATLAB Function: '<S99>/getSpeedLimit'
static void Real2SimGuidance_readINI_or(emxArray_char_T_Real2SimGuidance_T *ret,
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
    fileid = Real2SimGuidance_cfopen_is("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T_e(&j, 1);
        Real2SimGuidance_fread_h(static_cast<real_T>(fileid), j, localDW);
        Real2SimGuidance_emxInit_char_T_e(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        Real2SimGuidance_emxFree_char_T_o(&j);
        Real2SimGuidance_cfclose_m(static_cast<real_T>(fileid), localDW);
        Real2SimGuidance_emxInit_char_T_e(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curLine, 2);
        Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&tmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                Real2SimGuidance_strtok_o(data_0, curLine, data);
                Real2SimGuidance_strtok_ow(curLine, tmp);
                Real2SimGuidance_strtrim_o(tmp, curLine);
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

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g
                                (curSection, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curSection->data[i_0] = curLine->data[
                                    static_cast<int32_T>(iremain + i_0)];
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
                                Real2SimGuidance_contains_f(curLine)) {
                            Real2SimGuidance_strtok_owf(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token_m(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim_o(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            Real2SimGuidance_strtrim_o(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
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
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i_0);
                        loop_ub = curVal->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            ret->data[i_0] = curVal->data[i_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T_o(&data_0);
        Real2SimGuidance_emxFree_char_T_o(&tmp);
        Real2SimGuidance_emxFree_char_T_o(&aTmp);
        Real2SimGuidance_emxFree_char_T_o(&curLine);
        Real2SimGuidance_emxFree_char_T_o(&curVal);
        Real2SimGuidance_emxFree_char_T_o(&curKey);
        Real2SimGuidance_emxFree_char_T_o(&curSection);
        Real2SimGuidance_emxFree_char_T_o(&data);
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static void Real2SimGuidance_strtok_ilmz(const
    emxArray_char_T_Real2SimGuidance_T *x, emxArray_char_T_Real2SimGuidance_T
    *token)
{
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    Real2SimGuidance_find_token_m(x, &itoken, &iremain);
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
    Real2SimGuidance_emxEnsureCapacity_char_T_g(token, i);
    for (i = 0; i <= static_cast<int32_T>(iremain - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_bgl(const
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
    Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

    Real2SimGuidance_emxFree_char_T_o(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S97>/getSpeedLimit'
static int8_T Real2SimGuidance_filedata_jv(DW_Real2SimGuidance_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles_i[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S97>/getSpeedLimit'
static int8_T Real2SimGuidance_cfopen_i(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = Real2SimGuidance_filedata_jv(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles_i[static_cast<int32_T>(static_cast<int32_T>(j)
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

// Function for MATLAB Function: '<S97>/getSpeedLimit'
static real_T Real2SimGuidance_fileManager_p(DW_Real2SimGuidance_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = Real2SimGuidance_cfopen_i("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
}

// Function for MATLAB Function: '<S97>/getSpeedLimit'
static void Real2SimGuidance_fread_j(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(fileID);
    if (fileID != static_cast<real_T>(static_cast<int8_T>(fileID))) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        filestar = localDW->eml_openfiles_i[static_cast<int32_T>(static_cast<
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
            int32_T i;
            int32_T loop_ub;
            int32_T numRead;
            int32_T tmp;
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
                i = -1;
                loop_ub = -1;
            } else {
                i = static_cast<int32_T>(c - 1);
                loop_ub = static_cast<int32_T>(c - 1);
            }

            tmp = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(i + A->size[0])
                + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T_g(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_bglv(const
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
    Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

    Real2SimGuidance_emxFree_char_T_o(&aTmp);
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

// Function for MATLAB Function: '<S97>/getSpeedLimit'
static int32_T Real2SimGuidance_cfclose_a(real_T fid, DW_Real2SimGuidance_f_T
    *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(fid);
    if (fid != static_cast<real_T>(static_cast<int8_T>(fid))) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = localDW->eml_openfiles_i[static_cast<int32_T>
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
            localDW->eml_openfiles_i[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static boolean_T Real2SimGuidance_strcmp_bglv3(const
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
    Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

    Real2SimGuidance_emxFree_char_T_o(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S97>/getSpeedLimit'
static void Real2SimGuidance_readINI_e(emxArray_char_T_Real2SimGuidance_T *ret,
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
    fileid = Real2SimGuidance_cfopen_i("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T_e(&j, 1);
        Real2SimGuidance_fread_j(static_cast<real_T>(fileid), j, localDW);
        Real2SimGuidance_emxInit_char_T_e(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        Real2SimGuidance_emxFree_char_T_o(&j);
        Real2SimGuidance_cfclose_a(static_cast<real_T>(fileid), localDW);
        Real2SimGuidance_emxInit_char_T_e(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curLine, 2);
        Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&tmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                Real2SimGuidance_strtok_o(data_0, curLine, data);
                Real2SimGuidance_strtok_ow(curLine, tmp);
                Real2SimGuidance_strtrim_o(tmp, curLine);
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

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g
                                (curSection, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curSection->data[i_0] = curLine->data[
                                    static_cast<int32_T>(iremain + i_0)];
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
                                Real2SimGuidance_contains_f(curLine)) {
                            Real2SimGuidance_strtok_owf(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token_m(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim_o(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            Real2SimGuidance_strtrim_o(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
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
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i_0);
                        loop_ub = curVal->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            ret->data[i_0] = curVal->data[i_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T_o(&data_0);
        Real2SimGuidance_emxFree_char_T_o(&tmp);
        Real2SimGuidance_emxFree_char_T_o(&aTmp);
        Real2SimGuidance_emxFree_char_T_o(&curLine);
        Real2SimGuidance_emxFree_char_T_o(&curVal);
        Real2SimGuidance_emxFree_char_T_o(&curKey);
        Real2SimGuidance_emxFree_char_T_o(&curSection);
        Real2SimGuidance_emxFree_char_T_o(&data);
    }
}

// Function for MATLAB Function: '<S97>/getSpeedLimit'
static void Real2SimGuidance_readINI_ew(emxArray_char_T_Real2SimGuidance_T *ret,
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
    fileid = Real2SimGuidance_cfopen_i("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T_e(&j, 1);
        Real2SimGuidance_fread_j(static_cast<real_T>(fileid), j, localDW);
        Real2SimGuidance_emxInit_char_T_e(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        Real2SimGuidance_emxFree_char_T_o(&j);
        Real2SimGuidance_cfclose_a(static_cast<real_T>(fileid), localDW);
        Real2SimGuidance_emxInit_char_T_e(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curLine, 2);
        Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&tmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                Real2SimGuidance_strtok_o(data_0, curLine, data);
                Real2SimGuidance_strtok_ow(curLine, tmp);
                Real2SimGuidance_strtrim_o(tmp, curLine);
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

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g
                                (curSection, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curSection->data[i_0] = curLine->data[
                                    static_cast<int32_T>(iremain + i_0)];
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
                                Real2SimGuidance_contains_f(curLine)) {
                            Real2SimGuidance_strtok_owf(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token_m(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim_o(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            Real2SimGuidance_strtrim_o(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
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
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i_0);
                        loop_ub = curVal->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            ret->data[i_0] = curVal->data[i_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T_o(&data_0);
        Real2SimGuidance_emxFree_char_T_o(&tmp);
        Real2SimGuidance_emxFree_char_T_o(&aTmp);
        Real2SimGuidance_emxFree_char_T_o(&curLine);
        Real2SimGuidance_emxFree_char_T_o(&curVal);
        Real2SimGuidance_emxFree_char_T_o(&curKey);
        Real2SimGuidance_emxFree_char_T_o(&curSection);
        Real2SimGuidance_emxFree_char_T_o(&data);
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

static void Real2SimGuidance_WaypointFollowerBase_searchClosestPath
    (uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T *obj, const
     real_T waypoints_data[], const int32_T waypoints_size[2], const real_T
     currentPose[4])
{
    emxArray_real_T_Real2SimGuidance_T *d;
    real_T currentPose_0[3];
    real_T lambda;
    real_T lambda_tmp_tmp;
    int32_T b_idx;
    int32_T b_k;
    int32_T last;
    Real2SimGuidance_emxInit_real_T(&d, 2);
    b_k = static_cast<int32_T>(d->size[0] * d->size[1]);
    d->size[0] = 1;
    last = static_cast<int32_T>(obj->NumWaypoints - 1.0);
    d->size[1] = static_cast<int32_T>(obj->NumWaypoints - 1.0);
    Real2SimGuidance_emxEnsureCapacity_real_T(d, b_k);
    for (b_k = 0; b_k <= static_cast<int32_T>(last - 1); b_k++) {
        d->data[b_k] = 0.0;
    }

    last = static_cast<int32_T>(static_cast<int32_T>(obj->NumWaypoints - 1.0) -
        1);
    for (b_k = 0; b_k <= last; b_k++) {
        real_T lambda_tmp;
        real_T lambda_tmp_0;
        real_T lambda_tmp_1;
        real_T lambda_tmp_2;
        real_T lambda_tmp_tmp_0;
        real_T lambda_tmp_tmp_1;
        real_T lambda_tmp_tmp_2;
        real_T lambda_tmp_tmp_tmp;
        real_T lambda_tmp_tmp_tmp_0;
        lambda_tmp_tmp = waypoints_data[static_cast<int32_T>(static_cast<int32_T>
            ((static_cast<real_T>(b_k) + 1.0) + 1.0) - 1)] - waypoints_data[b_k];
        lambda_tmp_tmp_1 = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>((static_cast<real_T>(b_k)
                + 1.0) + 1.0) + waypoints_size[0]) - 1)];
        lambda_tmp = lambda_tmp_tmp_1 - waypoints_data[static_cast<int32_T>(b_k
            + waypoints_size[0])];
        lambda_tmp_tmp_tmp = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>((static_cast<real_T>(b_k)
                + 1.0) + 1.0) + static_cast<int32_T>(waypoints_size[0] << 1)) -
             1)];
        lambda_tmp_tmp_tmp_0 = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(waypoints_size[0] << 1) + b_k)];
        lambda_tmp_tmp_0 = lambda_tmp_tmp_tmp - lambda_tmp_tmp_tmp_0;
        lambda_tmp_tmp_tmp_0 = currentPose[2] - lambda_tmp_tmp_tmp_0;
        lambda_tmp_0 = waypoints_data[static_cast<int32_T>(b_k + waypoints_size
            [0])];
        lambda_tmp_tmp_2 = waypoints_data[b_k];
        lambda_tmp_1 = currentPose[0] - lambda_tmp_tmp_2;
        lambda_tmp_2 = currentPose[1] - lambda_tmp_0;
        lambda = ((lambda_tmp_2 * lambda_tmp + lambda_tmp_1 * lambda_tmp_tmp) +
                  lambda_tmp_tmp_tmp_0 * lambda_tmp_tmp_0) / (((lambda_tmp_tmp_1
            - lambda_tmp_0) * lambda_tmp + lambda_tmp_tmp * lambda_tmp_tmp) +
            lambda_tmp_tmp_0 * lambda_tmp_tmp_0);
        if (lambda < 0.0) {
            currentPose_0[0] = lambda_tmp_1;
            currentPose_0[1] = lambda_tmp_2;
            currentPose_0[2] = lambda_tmp_tmp_tmp_0;
            d->data[b_k] = Real2SimGuidance_norm(currentPose_0);
        } else if (lambda > 1.0) {
            currentPose_0[0] = currentPose[0] - waypoints_data
                [static_cast<int32_T>(static_cast<int32_T>((static_cast<real_T>
                (b_k) + 1.0) + 1.0) - 1)];
            currentPose_0[1] = currentPose[1] - lambda_tmp_tmp_1;
            currentPose_0[2] = currentPose[2] - lambda_tmp_tmp_tmp;
            d->data[b_k] = Real2SimGuidance_norm(currentPose_0);
        } else {
            currentPose_0[0] = currentPose[0] - (lambda * lambda_tmp_tmp +
                lambda_tmp_tmp_2);
            currentPose_0[1] = currentPose[1] - (lambda * lambda_tmp +
                lambda_tmp_0);
            currentPose_0[2] = currentPose[2] - (waypoints_data
                [static_cast<int32_T>(static_cast<int32_T>(waypoints_size[0] <<
                1) + b_k)] + lambda * lambda_tmp_tmp_0);
            d->data[b_k] = Real2SimGuidance_norm(currentPose_0);
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
            boolean_T exitg1;
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
            int32_T b;
            lambda = d->data[static_cast<int32_T>(b_idx - 1)];
            b = b_idx;
            for (b_k = static_cast<int32_T>(b + 1); b_k <= last; b_k++) {
                lambda_tmp_tmp = d->data[static_cast<int32_T>(b_k - 1)];
                if (lambda > lambda_tmp_tmp) {
                    lambda = lambda_tmp_tmp;
                    b_idx = b_k;
                }
            }
        }
    }

    Real2SimGuidance_emxFree_real_T(&d);
    obj->WaypointIndex = static_cast<real_T>(b_idx);
    obj->SearchFlag = false;
}

// Function for MATLAB Function: '<S16>/minus'
static void Real2SimGuidance_repmat(const real_T a[2], real_T varargin_1,
    emxArray_real_T_Real2SimGuidance_T *b)
{
    int32_T jcol;
    int32_T ntilerows;
    jcol = static_cast<int32_T>(b->size[0] * b->size[1]);
    b->size[0] = static_cast<int32_T>(varargin_1);
    b->size[1] = 2;
    Real2SimGuidance_emxEnsureCapacity_real_T(b, jcol);
    ntilerows = static_cast<int32_T>(static_cast<int32_T>(varargin_1) - 1);
    for (jcol = 0; jcol < 2; jcol++) {
        int32_T ibmat;
        ibmat = static_cast<int32_T>(jcol * static_cast<int32_T>(varargin_1));
        for (int32_T itilerow{0}; itilerow <= ntilerows; itilerow++) {
            b->data[static_cast<int32_T>(ibmat + itilerow)] = a[jcol];
        }
    }
}

static void Real2SimGuidance_binary_expand_op_puh
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

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static int8_T Real2SimGuidance_filedata_j(DW_Real2SimGuidance_f_T *localDW)
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
static int8_T Real2SimGuidance_cfopen_e(const char_T *cfilename, const char_T
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
static void Real2SimGuidance_fread_o(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(fileID);
    if (fileID != static_cast<real_T>(static_cast<int8_T>(fileID))) {
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
            int32_T i;
            int32_T loop_ub;
            int32_T numRead;
            int32_T tmp;
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
                i = -1;
                loop_ub = -1;
            } else {
                i = static_cast<int32_T>(c - 1);
                loop_ub = static_cast<int32_T>(c - 1);
            }

            tmp = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(i + A->size[0])
                + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T_g(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<Root>/RepulDir'
static void Real2SimGuidance_hypot(const real_T x_data[], const int32_T *x_size,
    const real_T y_data[], const int32_T *y_size, real_T r_data[], int32_T
    *r_size)
{
    int32_T b;
    int8_T csz_idx_0;
    if (*x_size <= *y_size) {
        csz_idx_0 = static_cast<int8_T>(*x_size);
    } else {
        csz_idx_0 = static_cast<int8_T>(*y_size);
    }

    *r_size = static_cast<int32_T>(csz_idx_0);
    b = static_cast<int32_T>(csz_idx_0);
    for (int32_T k{0}; k <= static_cast<int32_T>(b - 1); k++) {
        r_data[k] = rt_hypotd_snf(x_data[k], y_data[k]);
    }
}

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static int32_T Real2SimGuidance_cfclose_e(real_T fid, DW_Real2SimGuidance_f_T
    *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(fid);
    if (fid != static_cast<real_T>(static_cast<int8_T>(fid))) {
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

// Function for MATLAB Function: '<S15>/getLAPGainBias'
static boolean_T Real2SimGuidance_strcmp_f(const
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
    Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
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

    Real2SimGuidance_emxFree_char_T_o(&aTmp);
    return b_bool;
}

static void Real2SimGuidance_times_na(real_T in1_data[], int32_T *in1_size,
    const real_T in2_data[], const int32_T *in2_size)
{
    real_T in2_data_0[64];
    int32_T in2_size_idx_0;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;

    // MATLAB Function: '<Root>/RepulDir'
    in2_size_idx_0 = *in1_size == 1 ? *in2_size : *in1_size;
    stride_0_0 = (*in2_size != 1);
    stride_1_0 = (*in1_size != 1);
    loop_ub = *in1_size == 1 ? *in2_size : *in1_size;
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_data_0[i] = in2_data[static_cast<int32_T>(i * stride_0_0)] *
            in1_data[static_cast<int32_T>(i * stride_1_0)];
    }

    *in1_size = in2_size_idx_0;
    for (int32_T i{0}; i <= static_cast<int32_T>(in2_size_idx_0 - 1); i++) {
        in1_data[i] = in2_data_0[i];
    }

    // End of MATLAB Function: '<Root>/RepulDir'
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static int8_T Real2SimGuidance_filedata_h(DW_Real2SimGuidance_f_T *localDW)
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

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static int8_T Real2SimGuidance_cfopen_m(const char_T *cfilename, const char_T
    *cpermission, DW_Real2SimGuidance_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = Real2SimGuidance_filedata_h(localDW);
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

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static real_T Real2SimGuidance_fileManager(DW_Real2SimGuidance_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = Real2SimGuidance_cfopen_m("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static void Real2SimGuidance_fread_b(real_T fileID,
    emxArray_char_T_Real2SimGuidance_T *A, DW_Real2SimGuidance_f_T *localDW)
{
    FILE* filestar;
    size_t nBytes;
    char_T tbuf[1024];
    int8_T fileid;
    nBytes = sizeof(char_T);
    fileid = static_cast<int8_T>(fileID);
    if (fileID != static_cast<real_T>(static_cast<int8_T>(fileID))) {
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
            int32_T i;
            int32_T loop_ub;
            int32_T numRead;
            int32_T tmp;
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
                i = -1;
                loop_ub = -1;
            } else {
                i = static_cast<int32_T>(c - 1);
                loop_ub = static_cast<int32_T>(c - 1);
            }

            tmp = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(i + A->size[0])
                + 1);
            Real2SimGuidance_emxEnsureCapacity_char_T_g(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_expand_atan2(const
    emxArray_real_T_Real2SimGuidance_T *a, const
    emxArray_real_T_Real2SimGuidance_T *b, emxArray_real_T_Real2SimGuidance_T *c)
{
    int32_T csz_idx_0;
    int32_T k;
    if (b->size[0] == 1) {
        csz_idx_0 = a->size[0];
    } else if (a->size[0] == 1) {
        csz_idx_0 = b->size[0];
    } else if (a->size[0] <= b->size[0]) {
        csz_idx_0 = a->size[0];
    } else {
        csz_idx_0 = b->size[0];
    }

    k = c->size[0];
    c->size[0] = csz_idx_0;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    if (csz_idx_0 != 0) {
        boolean_T d;
        boolean_T e;
        d = (a->size[0] != 1);
        e = (b->size[0] != 1);
        csz_idx_0 = static_cast<int32_T>(csz_idx_0 - 1);
        for (k = 0; k <= csz_idx_0; k++) {
            c->data[k] = rt_atan2d_snf(a->data[static_cast<int32_T>(static_cast<
                int32_T>(d) * k)], b->data[static_cast<int32_T>
                (static_cast<int32_T>(e) * k)]);
        }
    }
}

static void Real2SimGuidance_times_n(real_T in1_data[], int32_T *in1_size, const
    real_T in2_data[], const int32_T *in2_size)
{
    real_T in1_data_0[64];
    int32_T in1_size_idx_0;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;

    // MATLAB Function: '<Root>/RepulDir'
    in1_size_idx_0 = *in2_size == 1 ? *in1_size : *in2_size;
    stride_0_0 = (*in1_size != 1);
    stride_1_0 = (*in2_size != 1);
    loop_ub = *in2_size == 1 ? *in1_size : *in2_size;
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_data_0[i] = in1_data[static_cast<int32_T>(i * stride_0_0)] *
            in2_data[static_cast<int32_T>(i * stride_1_0)];
    }

    *in1_size = in1_size_idx_0;
    for (int32_T i{0}; i <= static_cast<int32_T>(in1_size_idx_0 - 1); i++) {
        in1_data[i] = in1_data_0[i];
    }

    // End of MATLAB Function: '<Root>/RepulDir'
}

// Function for MATLAB Function: '<Root>/Get Nominal Flight Speed'
static int32_T Real2SimGuidance_cfclose_n(real_T fid, DW_Real2SimGuidance_f_T
    *localDW)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(fid);
    if (fid != static_cast<real_T>(static_cast<int8_T>(fid))) {
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

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_abs(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y)
{
    int32_T k;
    int32_T nx;
    nx = x->size[0];
    k = y->size[0];
    y->size[0] = x->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(y, k);
    for (k = 0; k <= static_cast<int32_T>(nx - 1); k++) {
        y->data[k] = std::abs(x->data[k]);
    }
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static void Real2SimGuidance_expand_hypot(const
    emxArray_real_T_Real2SimGuidance_T *a, const
    emxArray_real_T_Real2SimGuidance_T *b, emxArray_real_T_Real2SimGuidance_T *c)
{
    int32_T csz_idx_0;
    int32_T k;
    if (b->size[0] == 1) {
        csz_idx_0 = a->size[0];
    } else if (a->size[0] == 1) {
        csz_idx_0 = b->size[0];
    } else if (a->size[0] <= b->size[0]) {
        csz_idx_0 = a->size[0];
    } else {
        csz_idx_0 = b->size[0];
    }

    k = c->size[0];
    c->size[0] = csz_idx_0;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    if (csz_idx_0 != 0) {
        boolean_T d;
        boolean_T e;
        d = (a->size[0] != 1);
        e = (b->size[0] != 1);
        csz_idx_0 = static_cast<int32_T>(csz_idx_0 - 1);
        for (k = 0; k <= csz_idx_0; k++) {
            c->data[k] = rt_hypotd_snf(a->data[static_cast<int32_T>(static_cast<
                int32_T>(d) * k)], b->data[static_cast<int32_T>
                (static_cast<int32_T>(e) * k)]);
        }
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

static void Real2SimGuidance_binary_expand_op_pu
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
    da = split_JEzbX7NR(a);
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
    int32_T i;
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
    t = floor_0EeG1Grp(b_thi_0);
    b_thi = t.re + t.im;
    b_thi_0 = Real2SimGuidance_minus(dd, Real2SimGuidance_times(t));
    b_c.re = b_thi_0.re / 1000.0;
    t = split_JEzbX7NR(b_c.re);
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
    t = floor_0EeG1Grp(b_thi_0);
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
        i = static_cast<int32_T>(std::trunc(static_cast<real_T>(ig_rem) /
            36524.0));
        ic_rem = static_cast<int32_T>(ig_rem - static_cast<int32_T>(36524 *
            div_s32(ig_rem, 36524)));
        if (i > 3) {
            i = 3;
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
               static_cast<real_T>(i) * 100.0) + std::trunc(static_cast<real_T>
               (ic_rem) / 1461.0) * 4.0) + static_cast<real_T>(ia_quot);
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
        i = static_cast<int32_T>(idn - static_cast<int32_T>(3600 * div_s32(idn,
            3600)));
        *h = std::trunc(static_cast<real_T>(idn) / 3600.0);
        *m = std::trunc(static_cast<real_T>(i) / 60.0);
        b_ahi = static_cast<real_T>(static_cast<int32_T>(i - static_cast<int32_T>
            (60 * div_s32(i, 60))));
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
    fileid = Real2SimGuidance_cfopen_m("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T_e(&j, 1);
        Real2SimGuidance_fread_b(static_cast<real_T>(fileid), j, localDW);
        Real2SimGuidance_emxInit_char_T_e(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        Real2SimGuidance_emxFree_char_T_o(&j);
        Real2SimGuidance_cfclose_n(static_cast<real_T>(fileid), localDW);
        Real2SimGuidance_emxInit_char_T_e(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curLine, 2);
        Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&tmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                Real2SimGuidance_strtok_o(data_0, curLine, data);
                Real2SimGuidance_strtok_ow(curLine, tmp);
                Real2SimGuidance_strtrim_o(tmp, curLine);
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

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g
                                (curSection, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curSection->data[i_0] = curLine->data[
                                    static_cast<int32_T>(iremain + i_0)];
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
                                Real2SimGuidance_contains_f(curLine)) {
                            Real2SimGuidance_strtok_owf(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token_m(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim_o(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            Real2SimGuidance_strtrim_o(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
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
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i_0);
                        loop_ub = curVal->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            ret->data[i_0] = curVal->data[i_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T_o(&data_0);
        Real2SimGuidance_emxFree_char_T_o(&tmp);
        Real2SimGuidance_emxFree_char_T_o(&aTmp);
        Real2SimGuidance_emxFree_char_T_o(&curLine);
        Real2SimGuidance_emxFree_char_T_o(&curVal);
        Real2SimGuidance_emxFree_char_T_o(&curKey);
        Real2SimGuidance_emxFree_char_T_o(&curSection);
        Real2SimGuidance_emxFree_char_T_o(&data);
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
    fileid = Real2SimGuidance_cfopen_m("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_char_T_e(&j, 1);
        Real2SimGuidance_fread_b(static_cast<real_T>(fileid), j, localDW);
        Real2SimGuidance_emxInit_char_T_e(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        Real2SimGuidance_emxFree_char_T_o(&j);
        Real2SimGuidance_cfclose_n(static_cast<real_T>(fileid), localDW);
        Real2SimGuidance_emxInit_char_T_e(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        Real2SimGuidance_emxInit_char_T_e(&curLine, 2);
        Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&tmp, 2);
        Real2SimGuidance_emxInit_char_T_e(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                Real2SimGuidance_strtok_o(data_0, curLine, data);
                Real2SimGuidance_strtok_ow(curLine, tmp);
                Real2SimGuidance_strtrim_o(tmp, curLine);
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

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g
                                (curSection, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curSection->data[i_0] = curLine->data[
                                    static_cast<int32_T>(iremain + i_0)];
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
                                Real2SimGuidance_contains_f(curLine)) {
                            Real2SimGuidance_strtok_owf(curLine, aTmp, curVal);
                            Real2SimGuidance_find_token_m(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            Real2SimGuidance_strtrim_o(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            Real2SimGuidance_emxEnsureCapacity_char_T_g(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            Real2SimGuidance_strtrim_o(curLine, curVal);
                        }
                    }
                }

                if (Real2SimGuidance_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
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
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i_0);
                        loop_ub = curVal->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            ret->data[i_0] = curVal->data[i_0];
                        }

                        exitg1 = 1;
                    }
                }
            } else {
                exitg1 = 1;
            }
        } while (exitg1 == 0);

        Real2SimGuidance_emxFree_char_T_o(&data_0);
        Real2SimGuidance_emxFree_char_T_o(&tmp);
        Real2SimGuidance_emxFree_char_T_o(&aTmp);
        Real2SimGuidance_emxFree_char_T_o(&curLine);
        Real2SimGuidance_emxFree_char_T_o(&curVal);
        Real2SimGuidance_emxFree_char_T_o(&curKey);
        Real2SimGuidance_emxFree_char_T_o(&curSection);
        Real2SimGuidance_emxFree_char_T_o(&data);
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
    for (i = 1; i <= static_cast<int32_T>(n - 1); i += 2) {
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

            for (pEnd = 0; pEnd <= static_cast<int32_T>(kEnd - 1); pEnd++) {
                idx->data[static_cast<int32_T>(static_cast<int32_T>(j + pEnd) -
                    1)] = iwork->data[pEnd];
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
    na = a->size[0];
    Real2SimGuidance_emxInit_int32_T(&idx, 1);
    Real2SimGuidance_sortIdx(a, idx);
    c_k = b->size[0];
    b->size[0] = a->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(b, c_k);
    for (c_k = 0; c_k <= static_cast<int32_T>(na - 1); c_k++) {
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
    for (c_k = 0; c_k <= static_cast<int32_T>(nNaN - 1); c_k++) {
        b->data[static_cast<int32_T>(static_cast<int32_T>(nb + c_k) + 1)] =
            b->data[static_cast<int32_T>(na + c_k)];
    }

    nb = static_cast<int32_T>(static_cast<int32_T>(nb + nNaN) + 1);
    if (nb < 1) {
        b->size[0] = 0;
    } else {
        c_k = b->size[0];
        b->size[0] = nb;
        Real2SimGuidance_emxEnsureCapacity_real_T(b, c_k);
    }
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

static real_T Real2SimGuidance_floatmod(real_T x)
{
    real_T r;
    if (std::isnan(x) || std::isinf(x)) {
        r = (rtNaN);
    } else if (x == 0.0) {
        r = 0.0;
    } else {
        boolean_T rEQ0;
        r = std::fmod(x, 6.2831853071795862);
        rEQ0 = (r == 0.0);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rEQ0) ^ 1))) {
            real_T q;
            q = std::abs(x / 6.2831853071795862);
            rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q - std::
                floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
        }

        if (rEQ0) {
            r = 0.0;
        } else if (x < 0.0) {
            r += 6.2831853071795862;
        }
    }

    return r;
}

static void Real2SimGuidance_binary_expand_op_f(boolean_T in1_data[], int32_T
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

static void Real2SimGuidance_wrapToPi_p34c(emxArray_real_T_Real2SimGuidance_T
    *theta, DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_real_T_Real2SimGuidance_T *y;
    int32_T b_k;
    int32_T c;
    int32_T y_size;
    Real2SimGuidance_emxInit_real_T(&y, 1);
    b_k = y->size[0];
    y->size[0] = theta->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(y, b_k);
    c = static_cast<int32_T>(theta->size[0] - 1);
    for (b_k = 0; b_k <= c; b_k++) {
        y->data[b_k] = std::abs(theta->data[b_k]);
    }

    y_size = y->size[0];
    c = y->size[0];
    for (b_k = 0; b_k <= static_cast<int32_T>(c - 1); b_k++) {
        localDW->y_data[b_k] = (y->data[b_k] > 3.1415926535897931);
    }

    if (Real2SimGuidance_allOrAny_anonFcn1(localDW->y_data, &y_size)) {
        b_k = y->size[0];
        y->size[0] = theta->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(y, b_k);
        c = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(c - 1); b_k++) {
            y->data[b_k] = theta->data[b_k] + 3.1415926535897931;
        }

        b_k = theta->size[0];
        theta->size[0] = y->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(theta, b_k);
        c = y->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(c - 1); b_k++) {
            theta->data[b_k] = Real2SimGuidance_floatmod(y->data[b_k]);
        }

        if (theta->size[0] == y->size[0]) {
            y_size = theta->size[0];
            c = theta->size[0];
            for (b_k = 0; b_k <= static_cast<int32_T>(c - 1); b_k++) {
                localDW->c_data[b_k] = static_cast<boolean_T>
                    (static_cast<int32_T>((theta->data[b_k] == 0.0) & (y->
                       data[b_k] > 0.0)));
            }
        } else {
            Real2SimGuidance_binary_expand_op_f(localDW->c_data, &y_size, theta,
                y);
        }

        c = static_cast<int32_T>(y_size - 1);
        for (b_k = 0; b_k <= c; b_k++) {
            if (localDW->c_data[b_k]) {
                theta->data[b_k] = 6.2831853071795862;
            }
        }

        c = theta->size[0];
        for (b_k = 0; b_k <= static_cast<int32_T>(c - 1); b_k++) {
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

    Real2SimGuidance_wrapToPi_p34c(obj_InternalAngles, localDW);
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
    boolean_T y_0;
    b_theta[0] = theta[0];
    y[0] = std::abs(theta[0]);
    b_theta[1] = theta[1];
    y[1] = std::abs(theta[1]);
    y_0 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 2)) {
        if (y[b_k] > 3.1415926535897931) {
            y_0 = true;
            exitg1 = true;
        } else {
            b_k = static_cast<int32_T>(b_k + 1);
        }
    }

    if (y_0) {
        y[0] = theta[0] + 3.1415926535897931;
        y[1] = theta[1] + 3.1415926535897931;
        b_theta[0] = Real2SimGuidance_floatmod(theta[0] + 3.1415926535897931);
        b_theta[1] = Real2SimGuidance_floatmod(theta[1] + 3.1415926535897931);
        for (b_k = 0; b_k < 2; b_k++) {
            real_T b_theta_0;
            b_theta_0 = b_theta[b_k];
            if (static_cast<boolean_T>(static_cast<int32_T>((b_theta_0 == 0.0) &
                  (y[b_k] > 0.0)))) {
                b_theta_0 = 6.2831853071795862;
            }

            b_theta[b_k] = b_theta_0;
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
        localDW->tmp_data_c[i] = std::isnan(x->data[i]);
    }

    loop_ub = *b_size;
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        b_data[i] = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(b_data[i]) ^ 1))) & static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (localDW->tmp_data_c[i]) ^ 1)))));
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

static void Real2SimGuidance_nullAssignment_b(emxArray_real_T_Real2SimGuidance_T
    *x, const boolean_T idx_data[], const int32_T *idx_size)
{
    int32_T b;
    int32_T b_k;
    int32_T k0;
    int32_T nxout;
    nxout = 0;
    k0 = static_cast<int32_T>(*idx_size - 1);
    for (b_k = 0; b_k <= k0; b_k++) {
        nxout = static_cast<int32_T>(nxout + static_cast<int32_T>(idx_data[b_k]));
    }

    nxout = static_cast<int32_T>(x->size[0] - nxout);
    k0 = -1;
    b = static_cast<int32_T>(x->size[0] - 1);
    for (b_k = 0; b_k <= b; b_k++) {
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

    Real2SimGuidance_nullAssignment_b(tmp, localDW->validIndices_data,
        validIndices_size);
    Real2SimGuidance_emxInit_real_T(&tmp_0, 1);
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

    Real2SimGuidance_nullAssignment_b(tmp_0, localDW->validIndices_data,
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
                static_cast<real_T>(loop_ub) - 3.1415926535897931 ==
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
    Real2SimGuidance_isfinite(objOut_InternalAngles, localDW->tmp_data_m,
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
                (localDW->tmp_data_m[tmp_size])))) & static_cast<int32_T>
                (localDW->validRangeLimitIndices_data[tmp_size])))) &
                static_cast<int32_T>(localDW->
                validAngleLimitIndices_data[tmp_size])));
        }
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5
            (localDW->validRangeLimitIndices_data, &validRangeLimitIndices_size,
             localDW->tmp_data, &loop_ub, localDW->tmp_data_m, &tmp_size,
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
        Real2SimGuidance_emxFree_real_T(&objOut_InternalAngles_0);
        Real2SimGuidance_emxFree_real_T(&objOut_InternalRanges_1);
        *objOut_ContainsOnlyFiniteData = true;
    } else {
        *objOut_ContainsOnlyFiniteData = true;
    }
}

static void Real2SimGuidance_histc(const emxArray_real_T_Real2SimGuidance_T *X,
    const real_T edges[120], real_T N[120], emxArray_real_T_Real2SimGuidance_T
    *BIN)
{
    int32_T i;
    int32_T k;
    std::memset(&N[0], 0, static_cast<uint32_T>(120U * sizeof(real_T)));
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
            if ((X->data[k] >= edges[0]) && (X->data[k] < edges[119])) {
                int32_T high_i;
                int32_T low_ip1;
                low_i = 1;
                low_ip1 = 1;
                high_i = 120;
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

            if (X->data[k] == edges[119]) {
                low_i = 120;
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
    int32_T c;
    b_jcol = static_cast<int32_T>(b->size[0] * b->size[1]);
    b->size[0] = static_cast<int32_T>(varargin_1);
    b->size[1] = 3;
    Real2SimGuidance_emxEnsureCapacity_real_T(b, b_jcol);
    c = static_cast<int32_T>(static_cast<int32_T>(static_cast<uint16_T>(
        static_cast<int32_T>(varargin_1))) - 1);
    for (b_jcol = 0; b_jcol < 3; b_jcol++) {
        int32_T ibmat;
        ibmat = static_cast<int32_T>(b_jcol * static_cast<int32_T>(varargin_1));
        for (int32_T b_itilerow{0}; b_itilerow <= c; b_itilerow++) {
            b->data[static_cast<int32_T>(ibmat + b_itilerow)] = a[b_jcol];
        }
    }
}

static void Real2SimGuidance_abs_p(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y)
{
    int32_T b_k;
    int32_T c;
    b_k = y->size[0];
    y->size[0] = x->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(y, b_k);
    c = static_cast<int32_T>(x->size[0] - 1);
    for (b_k = 0; b_k <= c; b_k++) {
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
    real_T kalpha[360];
    real_T b_x[120];
    real_T b_x_0[120];
    real_T kalpha_0[3];
    real_T obj_0[2];
    real_T obj_1;
    int32_T e_i;
    int32_T loop_ub;
    boolean_T expl_temp;
    obj_0[0] = obj->DistanceLimits[0];
    obj_0[1] = obj->DistanceLimits[1];
    Real2SimGuidance_emxInit_real_T(&sinOfEnlargement, 1);
    Real2SimGuidance_emxInit_real_T(&lowerAng, 1);
    Real2SimGuidance_lidarScan_removeInvalidData(scan_InternalRanges,
        scan_InternalAngles, obj_0, sinOfEnlargement, lowerAng, &expl_temp,
        localDW);
    obj_1 = obj->DistanceLimits[1];
    Real2SimGuidance_emxInit_real_T(&weightedRanges, 1);
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
        int32_T end;
        Real2SimGuidance_histc(lowerAng, obj->AngularSectorMidPoints, b_x,
                               higherAng);
        std::memset(&obj->PolarObstacleDensity[0], 0, static_cast<uint32_T>(120U
                     * sizeof(real_T)));
        end = static_cast<int32_T>(higherAng->size[0] - 1);
        for (e_i = 0; e_i <= end; e_i++) {
            obj_1 = higherAng->data[e_i];
            obj->PolarObstacleDensity[static_cast<int32_T>(static_cast<int32_T>
                (obj_1) - 1)] += weightedRanges->data[e_i];
        }
    } else {
        int32_T end;
        loop_ub = sinOfEnlargement->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            sinOfEnlargement->data[e_i] = obj_1 / sinOfEnlargement->data[e_i];
        }

        end = static_cast<int32_T>(sinOfEnlargement->size[0] - 1);
        for (e_i = 0; e_i <= end; e_i++) {
            obj_1 = sinOfEnlargement->data[e_i];
            if (obj_1 >= 1.0) {
                obj_1 = 0.99999999999999978;
            }

            sinOfEnlargement->data[e_i] = obj_1;
        }

        end = static_cast<int32_T>(sinOfEnlargement->size[0] - 1);
        for (e_i = 0; e_i <= end; e_i++) {
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

        end = static_cast<int32_T>(lowerAng->size[0] - 1);
        for (e_i = 0; e_i <= end; e_i++) {
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

        for (e_i = 0; e_i <= end; e_i++) {
            varargin_2->data[e_i] = std::sin(varargin_2->data[e_i]);
        }

        Real2SimGuidance_emxInit_real_T(&lowerVec, 2);
        e_i = static_cast<int32_T>(lowerVec->size[0] * lowerVec->size[1]);
        lowerVec->size[0] = sinOfEnlargement->size[0];
        lowerVec->size[1] = 3;
        Real2SimGuidance_emxEnsureCapacity_real_T(lowerVec, e_i);
        loop_ub = sinOfEnlargement->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            lowerVec->data[e_i] = sinOfEnlargement->data[e_i];
        }

        loop_ub = varargin_2->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            lowerVec->data[static_cast<int32_T>(e_i + sinOfEnlargement->size[0])]
                = varargin_2->data[e_i];
        }

        loop_ub = lowerAng->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
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

        end = static_cast<int32_T>(higherAng->size[0] - 1);
        for (e_i = 0; e_i <= end; e_i++) {
            sinOfEnlargement->data[e_i] = std::cos(sinOfEnlargement->data[e_i]);
        }

        e_i = varargin_2->size[0];
        varargin_2->size[0] = higherAng->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(varargin_2, e_i);
        loop_ub = higherAng->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            varargin_2->data[e_i] = higherAng->data[e_i];
        }

        for (e_i = 0; e_i <= end; e_i++) {
            varargin_2->data[e_i] = std::sin(varargin_2->data[e_i]);
        }

        Real2SimGuidance_emxInit_real_T(&higherVec, 2);
        e_i = static_cast<int32_T>(higherVec->size[0] * higherVec->size[1]);
        higherVec->size[0] = sinOfEnlargement->size[0];
        higherVec->size[1] = 3;
        Real2SimGuidance_emxEnsureCapacity_real_T(higherVec, e_i);
        loop_ub = sinOfEnlargement->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            higherVec->data[e_i] = sinOfEnlargement->data[e_i];
        }

        loop_ub = varargin_2->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            higherVec->data[static_cast<int32_T>(e_i + sinOfEnlargement->size[0])]
                = varargin_2->data[e_i];
        }

        loop_ub = higherAng->size[0];
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            higherVec->data[static_cast<int32_T>(static_cast<int32_T>(e_i +
                sinOfEnlargement->size[0]) + varargin_2->size[0])] = 0.0;
        }

        Real2SimGuidance_emxInit_boolean_T(&validWeights, 2);
        e_i = static_cast<int32_T>(validWeights->size[0] * validWeights->size[1]);
        validWeights->size[0] = 120;
        validWeights->size[1] = lowerVec->size[0];
        Real2SimGuidance_emxEnsureCapacity_boolean_T(validWeights, e_i);
        loop_ub = static_cast<int32_T>(120 * lowerVec->size[0]);
        for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
            validWeights->data[e_i] = true;
        }

        Real2SimGuidance_emxInit_real_T(&lh, 2);
        Real2SimGuidance_cross(lowerVec, higherVec, lh);
        for (e_i = 0; e_i < 120; e_i++) {
            b_x[e_i] = obj->AngularSectorMidPoints[e_i];
            b_x[e_i] = std::cos(b_x[e_i]);
            b_x_0[e_i] = obj->AngularSectorMidPoints[e_i];
            b_x_0[e_i] = std::sin(b_x_0[e_i]);
            kalpha[e_i] = b_x[e_i];
            kalpha[static_cast<int32_T>(e_i + 120)] = b_x_0[e_i];
            kalpha[static_cast<int32_T>(e_i + 240)] = 0.0;
        }

        loop_ub = lh->size[0];
        Real2SimGuidance_emxInit_real_T(&kalphaVec, 2);
        Real2SimGuidance_emxInit_real_T(&lk, 2);
        Real2SimGuidance_emxInit_real_T(&kh, 2);
        for (end = 0; end < 120; end++) {
            int32_T loop_ub_0;
            kalpha_0[0] = kalpha[end];
            kalpha_0[1] = kalpha[static_cast<int32_T>(end + 120)];
            kalpha_0[2] = kalpha[static_cast<int32_T>(end + 240)];
            Real2SimGuidance_repmat_c(kalpha_0, static_cast<real_T>
                (lowerVec->size[0]), kalphaVec);
            Real2SimGuidance_cross(lowerVec, kalphaVec, lk);
            Real2SimGuidance_cross(kalphaVec, higherVec, kh);
            e_i = lowerAng->size[0];
            lowerAng->size[0] = lk->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(lowerAng, e_i);
            loop_ub_0 = lk->size[0];
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
                obj_1 = lk->data[static_cast<int32_T>(static_cast<int32_T>
                    (lk->size[0] << 1) + e_i)];
                if (std::isnan(obj_1)) {
                    obj_1 = (rtNaN);
                } else if (obj_1 < 0.0) {
                    obj_1 = -1.0;
                } else {
                    obj_1 = static_cast<real_T>(obj_1 > 0.0);
                }

                lowerAng->data[e_i] = obj_1;
            }

            e_i = higherAng->size[0];
            higherAng->size[0] = kh->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(higherAng, e_i);
            loop_ub_0 = kh->size[0];
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub_0 - 1); e_i++) {
                obj_1 = kh->data[static_cast<int32_T>(static_cast<int32_T>
                    (kh->size[0] << 1) + e_i)];
                if (std::isnan(obj_1)) {
                    obj_1 = (rtNaN);
                } else if (obj_1 < 0.0) {
                    obj_1 = -1.0;
                } else {
                    obj_1 = static_cast<real_T>(obj_1 > 0.0);
                }

                higherAng->data[e_i] = obj_1;
            }

            e_i = sinOfEnlargement->size[0];
            sinOfEnlargement->size[0] = lh->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(sinOfEnlargement, e_i);
            for (e_i = 0; e_i <= static_cast<int32_T>(loop_ub - 1); e_i++) {
                obj_1 = lh->data[static_cast<int32_T>(static_cast<int32_T>
                    (lh->size[0] << 1) + e_i)];
                if (std::isnan(obj_1)) {
                    obj_1 = (rtNaN);
                } else if (obj_1 < 0.0) {
                    obj_1 = -1.0;
                } else {
                    obj_1 = static_cast<real_T>(obj_1 > 0.0);
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
                validWeights->data[static_cast<int32_T>(end +
                    static_cast<int32_T>(120 * e_i))] = (sinOfEnlargement->
                    data[e_i] > 1.0);
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
        for (e_i = 0; e_i < 120; e_i++) {
            obj->PolarObstacleDensity[e_i] = 0.0;
            for (end = 0; end <= static_cast<int32_T>(loop_ub - 1); end++) {
                obj->PolarObstacleDensity[e_i] += static_cast<real_T>
                    (validWeights->data[static_cast<int32_T>(static_cast<int32_T>
                      (120 * end) + e_i)]) * weightedRanges->data[end];
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
    int8_T b_data[120];
    int8_T c_data[120];
    boolean_T d[120];
    boolean_T d_0;
    obj_0 = obj->HistogramThresholds[1];
    trueCount = 0;
    for (int32_T i{0}; i < 120; i++) {
        d_0 = (obj->PolarObstacleDensity[i] > obj_0);
        if (d_0) {
            trueCount = static_cast<int32_T>(trueCount + 1);
        }

        d[i] = d_0;
    }

    b_size_idx_1 = trueCount;
    trueCount = 0;
    for (int32_T i{0}; i < 120; i++) {
        if (d[i]) {
            b_data[trueCount] = static_cast<int8_T>(static_cast<int32_T>(i + 1));
            trueCount = static_cast<int32_T>(trueCount + 1);
        }
    }

    for (int32_T i{0}; i <= static_cast<int32_T>(b_size_idx_1 - 1); i++) {
        obj->BinaryHistogram[static_cast<int32_T>(static_cast<int32_T>(b_data[i])
            - 1)] = true;
    }

    obj_0 = obj->HistogramThresholds[0];
    trueCount = 0;
    for (int32_T i{0}; i < 120; i++) {
        d_0 = (obj->PolarObstacleDensity[i] < obj_0);
        if (d_0) {
            trueCount = static_cast<int32_T>(trueCount + 1);
        }

        d[i] = d_0;
    }

    b_size_idx_1 = trueCount;
    trueCount = 0;
    for (int32_T i{0}; i < 120; i++) {
        if (d[i]) {
            c_data[trueCount] = static_cast<int8_T>(static_cast<int32_T>(i + 1));
            trueCount = static_cast<int32_T>(trueCount + 1);
        }
    }

    for (int32_T i{0}; i <= static_cast<int32_T>(b_size_idx_1 - 1); i++) {
        obj->BinaryHistogram[static_cast<int32_T>(static_cast<int32_T>(c_data[i])
            - 1)] = false;
    }
}

static void Real2SimGuidance_times_nall(emxArray_real_T_Real2SimGuidance_T *in1,
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

static void Real2SimGuidance_times_nal(emxArray_real_T_Real2SimGuidance_T *in1,
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
        in1_0->data[i] = in1->data[static_cast<int32_T>(i * stride_0_0)] *
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
    emxArray_real_T_Real2SimGuidance_T *DXj;
    emxArray_real_T_Real2SimGuidance_T *DYj;
    emxArray_real_T_Real2SimGuidance_T *e;
    emxArray_real_T_Real2SimGuidance_T *tmp;
    emxArray_real_T_Real2SimGuidance_T *validScan_InternalAngles;
    real_T obj_0[2];
    real_T phiL_data;
    real_T phiR_data;
    real_T varargin_1;
    int32_T blockedL_size;
    int32_T blockedR_size;
    int32_T idx;
    int32_T ii_data_idx_0_0;
    int32_T ii_size_idx_0;
    int32_T loop_ub;
    uint16_T ii_data_idx_0;
    boolean_T exitg1;
    boolean_T expl_temp;
    obj_0[0] = obj->DistanceLimits[0];
    obj_0[1] = obj->DistanceLimits[1];
    Real2SimGuidance_emxInit_real_T(&validScan_InternalAngles, 1);
    Real2SimGuidance_emxInit_real_T(&DYj, 1);
    Real2SimGuidance_lidarScan_removeInvalidData(scan_InternalRanges,
        scan_InternalAngles, obj_0, DYj, validScan_InternalAngles, &expl_temp,
        localDW);
    Real2SimGuidance_emxInit_real_T(&DXj, 1);
    loop_ub = DXj->size[0];
    DXj->size[0] = validScan_InternalAngles->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(DXj, loop_ub);
    loop_ub = validScan_InternalAngles->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        DXj->data[idx] = validScan_InternalAngles->data[idx];
    }

    blockedR_size = static_cast<int32_T>(validScan_InternalAngles->size[0] - 1);
    for (idx = 0; idx <= blockedR_size; idx++) {
        DXj->data[idx] = std::cos(DXj->data[idx]);
    }

    if (DYj->size[0] == DXj->size[0]) {
        loop_ub = DXj->size[0];
        DXj->size[0] = DYj->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(DXj, loop_ub);
        loop_ub = DYj->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            DXj->data[idx] *= DYj->data[idx];
        }
    } else {
        Real2SimGuidance_times_nall(DXj, DYj);
    }

    Real2SimGuidance_emxInit_real_T(&e, 1);
    loop_ub = e->size[0];
    e->size[0] = validScan_InternalAngles->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(e, loop_ub);
    loop_ub = validScan_InternalAngles->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        e->data[idx] = validScan_InternalAngles->data[idx];
    }

    for (idx = 0; idx <= blockedR_size; idx++) {
        e->data[idx] = std::sin(e->data[idx]);
    }

    if (DYj->size[0] == e->size[0]) {
        loop_ub = DYj->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            DYj->data[idx] *= e->data[idx];
        }
    } else {
        Real2SimGuidance_times_nal(DYj, e);
    }

    loop_ub = e->size[0];
    e->size[0] = DXj->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(e, loop_ub);
    loop_ub = DXj->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        varargin_1 = 0.0 - DXj->data[idx];
        e->data[idx] = varargin_1 * varargin_1;
    }

    Real2SimGuidance_emxInit_real_T(&tmp, 1);
    loop_ub = tmp->size[0];
    tmp->size[0] = DYj->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(tmp, loop_ub);
    loop_ub = DYj->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        varargin_1 = -obj->MinTurningRadius - DYj->data[idx];
        tmp->data[idx] = varargin_1 * varargin_1;
    }

    if (e->size[0] == tmp->size[0]) {
        loop_ub = e->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            e->data[idx] += tmp->data[idx];
        }
    } else {
        Real2SimGuidance_plus_ow(e, tmp);
    }

    blockedR_size = static_cast<int32_T>(e->size[0] - 1);
    for (idx = 0; idx <= blockedR_size; idx++) {
        e->data[idx] = std::sqrt(e->data[idx]);
    }

    loop_ub = DXj->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        varargin_1 = 0.0 - DXj->data[idx];
        DXj->data[idx] = varargin_1 * varargin_1;
    }

    loop_ub = tmp->size[0];
    tmp->size[0] = DYj->size[0];
    Real2SimGuidance_emxEnsureCapacity_real_T(tmp, loop_ub);
    loop_ub = DYj->size[0];
    for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
        varargin_1 = obj->MinTurningRadius - DYj->data[idx];
        tmp->data[idx] = varargin_1 * varargin_1;
    }

    Real2SimGuidance_emxFree_real_T(&DYj);
    if (DXj->size[0] == tmp->size[0]) {
        loop_ub = DXj->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            DXj->data[idx] += tmp->data[idx];
        }
    } else {
        Real2SimGuidance_plus_ow(DXj, tmp);
    }

    Real2SimGuidance_emxFree_real_T(&tmp);
    blockedR_size = static_cast<int32_T>(DXj->size[0] - 1);
    for (idx = 0; idx <= blockedR_size; idx++) {
        DXj->data[idx] = std::sqrt(DXj->data[idx]);
    }

    if (e->size[0] == validScan_InternalAngles->size[0]) {
        varargin_1 = (obj->MinTurningRadius + obj->RobotRadius) +
            obj->SafetyDistance;
        blockedR_size = e->size[0];
        loop_ub = e->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            localDW->blockedR_data[idx] = static_cast<boolean_T>
                (static_cast<int32_T>((e->data[idx] < varargin_1) &
                  (validScan_InternalAngles->data[idx] <= 0.0)));
        }
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5ro(localDW->blockedR_data,
            &blockedR_size, e, obj, validScan_InternalAngles);
    }

    Real2SimGuidance_emxFree_real_T(&e);
    if (DXj->size[0] == validScan_InternalAngles->size[0]) {
        varargin_1 = (obj->MinTurningRadius + obj->RobotRadius) +
            obj->SafetyDistance;
        blockedL_size = DXj->size[0];
        loop_ub = DXj->size[0];
        for (idx = 0; idx <= static_cast<int32_T>(loop_ub - 1); idx++) {
            localDW->blockedL_data[idx] = static_cast<boolean_T>
                (static_cast<int32_T>((DXj->data[idx] < varargin_1) &
                  (validScan_InternalAngles->data[idx] >= 0.0)));
        }
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5r(localDW->blockedL_data,
            &blockedL_size, DXj, obj, validScan_InternalAngles);
    }

    Real2SimGuidance_emxFree_real_T(&DXj);
    loop_ub = (blockedR_size >= 1);
    idx = 0;
    ii_size_idx_0 = loop_ub;
    exitg1 = false;
    while ((!exitg1) && (blockedR_size > 0)) {
        if (localDW->blockedR_data[static_cast<int32_T>(blockedR_size - 1)]) {
            idx = 1;
            ii_data_idx_0 = static_cast<uint16_T>(blockedR_size);
            exitg1 = true;
        } else {
            blockedR_size = static_cast<int32_T>(blockedR_size - 1);
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
    blockedR_size = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(blockedR_size - 1) <=
                         static_cast<int32_T>(blockedL_size - 1))) {
        if (localDW->blockedL_data[static_cast<int32_T>(blockedR_size - 1)]) {
            idx = 1;
            ii_data_idx_0_0 = blockedR_size;
            exitg1 = true;
        } else {
            blockedR_size = static_cast<int32_T>(blockedR_size + 1);
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
        phiL_data = obj->AngularSectorMidPoints[119];
    } else if (phiL_data >= obj->AngularSectorMidPoints[119]) {
        phiL_data = obj->AngularSectorMidPoints[118];
    }

    for (idx = 0; idx < 120; idx++) {
        obj->MaskedHistogram[idx] = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((obj->AngularSectorMidPoints[idx] < phiR_data) |
             (obj->AngularSectorMidPoints[idx] > phiL_data)))) |
            static_cast<int32_T>(obj->BinaryHistogram[idx])));
    }
}

static void Real2SimGuidance_diff(const real_T x[122], real_T y[121])
{
    real_T work;
    work = x[0];
    for (int32_T m{0}; m < 121; m++) {
        real_T tmp2;
        tmp2 = work;
        work = x[static_cast<int32_T>(m + 1)];
        y[m] = work - tmp2;
    }
}

static boolean_T Real2SimGuidance_any(const real_T x[121])
{
    int32_T b_k;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 121)) {
        if ((x[b_k] == 0.0) || std::isnan(x[b_k])) {
            b_k = static_cast<int32_T>(b_k + 1);
        } else {
            y = true;
            exitg1 = true;
        }
    }

    return y;
}

static void Real2SimGuidance_eml_find(const real_T x[121], int32_T i_data[],
    int32_T i_size[2])
{
    int32_T b_ii;
    int32_T idx;
    boolean_T exitg1;
    idx = 0;
    b_ii = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(b_ii - 1) < 121)) {
        if (x[static_cast<int32_T>(b_ii - 1)] != 0.0) {
            idx = static_cast<int32_T>(idx + 1);
            i_data[static_cast<int32_T>(idx - 1)] = b_ii;
            if (idx >= 121) {
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

static void Real2SimGuidance_binary_expand_op_puhaq5roxr0(real_T in1_data[],
    const real_T in3_data[], const int32_T in3_size[2], int32_T in4)
{
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_1;
    i = static_cast<int32_T>(static_cast<uint32_T>(static_cast<uint32_T>
        (in3_size[1]) >> 1));
    stride_0_1 = (in4 != 1);
    loop_ub = i == 1 ? in4 : i;
    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in1_data[static_cast<int32_T>(1 + static_cast<int32_T>(i << 1))] =
            in3_data[static_cast<int32_T>(static_cast<int32_T>(static_cast<
            int32_T>(i * stride_0_1) << 1) + 1)] - 1.0;
    }
}

static void Real2SimGuidance_diff_f(const real_T x_data[], const int32_T x_size
    [2], real_T y_data[], int32_T y_size[2])
{
    real_T b_y1_data[60];
    int32_T b_y1_size_idx_1;
    int32_T r_0;
    b_y1_size_idx_1 = x_size[1];
    if (x_size[1] != 0) {
        int32_T b;
        b = x_size[1];
        r_0 = 0;
        for (int32_T r{0}; r <= static_cast<int32_T>(b - 1); r++) {
            b_y1_data[r] = x_data[static_cast<int32_T>(r_0 + 1)] - x_data[r_0];
            r_0 = static_cast<int32_T>(r_0 + 2);
        }
    }

    y_size[0] = 1;
    y_size[1] = x_size[1];
    for (r_0 = 0; r_0 <= static_cast<int32_T>(b_y1_size_idx_1 - 1); r_0++) {
        y_data[r_0] = b_y1_data[r_0];
    }
}

static void Real2SimGuidance_wrapToPi_p34(const real_T theta_data[], const
    int32_T theta_size[2], real_T b_theta_data[], int32_T b_theta_size[2])
{
    real_T theta_data_0[183];
    real_T y_data[183];
    int32_T x_size[2];
    int32_T b_k;
    int32_T loop_ub;
    boolean_T x_data[183];
    b_theta_size[0] = 1;
    b_theta_size[1] = theta_size[1];
    loop_ub = theta_size[1];
    for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
        b_theta_data[b_k] = theta_data[b_k];
    }

    loop_ub = static_cast<int32_T>(theta_size[1] - 1);
    for (b_k = 0; b_k <= loop_ub; b_k++) {
        y_data[b_k] = std::abs(theta_data[b_k]);
    }

    loop_ub = theta_size[1];
    for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
        x_data[b_k] = (y_data[b_k] > 3.1415926535897931);
    }

    b_k = theta_size[1];
    if (Real2SimGuidance_allOrAny_anonFcn1(x_data, &b_k)) {
        loop_ub = theta_size[1];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            theta_data_0[b_k] = theta_data[b_k] + 3.1415926535897931;
        }

        loop_ub = theta_size[1];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            y_data[b_k] = Real2SimGuidance_floatmod(theta_data_0[b_k]);
        }

        x_size[1] = theta_size[1];
        loop_ub = theta_size[1];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            x_data[b_k] = static_cast<boolean_T>(static_cast<int32_T>
                ((y_data[b_k] == 0.0) & (theta_data_0[b_k] > 0.0)));
        }

        loop_ub = static_cast<int32_T>(x_size[1] - 1);
        for (b_k = 0; b_k <= loop_ub; b_k++) {
            if (x_data[b_k]) {
                y_data[b_k] = 6.2831853071795862;
            }
        }

        b_theta_size[0] = 1;
        b_theta_size[1] = theta_size[1];
        loop_ub = theta_size[1];
        for (b_k = 0; b_k <= static_cast<int32_T>(loop_ub - 1); b_k++) {
            b_theta_data[b_k] = y_data[b_k] - 3.1415926535897931;
        }
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq5roxr0o(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], const int32_T in2_size[2],
    const real_T in3_data[], const int32_T in3_size[2])
{
    real_T in2_data_0[60];
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
    real_T tmp_data[183];
    real_T theta1_data_0[60];
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
        Real2SimGuidance_binary_expand_op_puhaq5roxr0o(tmp_data, tmp_size,
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

static void Real2SimGuidance_binary_expand_op_puhaq5rox(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], const int32_T in4_data[],
    const int32_T in4_size[2], const real_T in5[2], const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in6, const
    real_T in7[2])
{
    real_T in2_data_0[60];
    real_T in2_data_1[60];
    int32_T in2_size_idx_1;
    int32_T in2_size_idx_1_0;
    int32_T loop_ub;
    int32_T stride_0_1;
    in2_size_idx_1 = static_cast<int32_T>(in5[1]) == 1 ? in4_size[1] :
        static_cast<int32_T>(in5[1]);
    stride_0_1 = (in4_size[1] != 1);
    loop_ub = static_cast<int32_T>(in5[1]) == 1 ? in4_size[1] : static_cast<
        int32_T>(in5[1]);
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_data_0[i] = in2_data[static_cast<int32_T>(static_cast<int32_T>
            (in4_data[static_cast<int32_T>(i * stride_0_1)] - 1) << 1)] +
            in6->NarrowOpeningThreshold / 2.0;
    }

    in2_size_idx_1_0 = static_cast<int32_T>(in7[1]) == 1 ? in4_size[1] :
        static_cast<int32_T>(in7[1]);
    stride_0_1 = (in4_size[1] != 1);
    loop_ub = static_cast<int32_T>(in7[1]) == 1 ? in4_size[1] :
        static_cast<int32_T>(in7[1]);
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_data_1[i] = in2_data[static_cast<int32_T>(static_cast<int32_T>(
            static_cast<int32_T>(in4_data[static_cast<int32_T>(i * stride_0_1)]
            - 1) << 1) + 1)] - in6->NarrowOpeningThreshold / 2.0;
    }

    in1_size[0] = 1;
    in1_size[1] = static_cast<int32_T>(in2_size_idx_1 + in2_size_idx_1_0);
    for (int32_T i{0}; i <= static_cast<int32_T>(in2_size_idx_1 - 1); i++) {
        in1_data[i] = in2_data_0[i];
    }

    for (int32_T i{0}; i <= static_cast<int32_T>(in2_size_idx_1_0 - 1); i++) {
        in1_data[static_cast<int32_T>(i + in2_size_idx_1)] = in2_data_1[i];
    }
}

static void Real2SimGuidance_bsxfun(const real_T a[120], const real_T b_data[],
    const int32_T *b_size, emxArray_real_T_Real2SimGuidance_T *c)
{
    int32_T k;
    k = static_cast<int32_T>(c->size[0] * c->size[1]);
    c->size[0] = *b_size;
    c->size[1] = 120;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    for (k = 0; k < 120; k++) {
        int32_T d;
        d = c->size[0];
        for (int32_T k_0{0}; k_0 <= static_cast<int32_T>(d - 1); k_0++) {
            c->data[static_cast<int32_T>(k_0 + static_cast<int32_T>(c->size[0] *
                k))] = Real2SimGuidance_wrapToPi_p(b_data[k_0] - a[k]);
        }
    }
}

static void Real2SimGuidance_abs_pj(const emxArray_real_T_Real2SimGuidance_T *x,
    emxArray_real_T_Real2SimGuidance_T *y)
{
    int32_T b_k;
    int32_T c;
    b_k = static_cast<int32_T>(y->size[0] * y->size[1]);
    y->size[0] = x->size[0];
    y->size[1] = 120;
    Real2SimGuidance_emxEnsureCapacity_real_T(y, b_k);
    c = static_cast<int32_T>(static_cast<int32_T>(x->size[0] * 120) - 1);
    for (b_k = 0; b_k <= c; b_k++) {
        y->data[b_k] = std::abs(x->data[b_k]);
    }
}

static void Real2SimGuidance_minimum_p(const emxArray_real_T_Real2SimGuidance_T *
    x, real_T ex_data[], int32_T *ex_size)
{
    int32_T b_i;
    int32_T c;
    *ex_size = x->size[0];
    c = static_cast<int32_T>(x->size[0] - 1);
    for (b_i = 0; b_i <= c; b_i++) {
        ex_data[b_i] = x->data[b_i];
    }

    b_i = static_cast<int32_T>(x->size[0] - 1);
    for (c = 0; c < 119; c++) {
        for (int32_T c_i{0}; c_i <= b_i; c_i++) {
            real_T b;
            real_T ex;
            boolean_T p;
            ex = ex_data[c_i];
            b = x->data[static_cast<int32_T>(static_cast<int32_T>
                (static_cast<int32_T>(c + 1) * x->size[0]) + c_i)];
            if (std::isnan(b)) {
                p = false;
            } else if (std::isnan(ex)) {
                p = true;
            } else {
                p = (ex > b);
            }

            if (p) {
                ex = x->data[static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(c + 1) * x->size[0]) + c_i)];
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
    c->size[1] = 120;
    Real2SimGuidance_emxEnsureCapacity_real_T(c, k);
    for (k = 0; k < 120; k++) {
        int32_T d;
        d = c->size[0];
        for (int32_T k_0{0}; k_0 <= static_cast<int32_T>(d - 1); k_0++) {
            c->data[static_cast<int32_T>(k_0 + static_cast<int32_T>(c->size[0] *
                k))] = a->data[static_cast<int32_T>(static_cast<int32_T>(a->
                size[0] * k) + k_0)] - b_data[k_0];
        }
    }
}

static void Real2SimGuidance_binary_expand_op_puhaq5roxr0oyl(real_T in1_data[],
    int32_T in1_size[2], const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *in2, const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], real_T in5)
{
    real_T in2_data[183];
    int32_T in2_size_idx_1;
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    int32_T stride_2_1;
    in2_size_idx_1 = in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] :
        in3_size[1] : in4_size[1];
    stride_0_1 = (in1_size[1] != 1);
    stride_1_1 = (in3_size[1] != 1);
    stride_2_1 = (in4_size[1] != 1);
    loop_ub = in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] : in3_size[1] :
        in4_size[1];
    for (int32_T i{0}; i <= static_cast<int32_T>(loop_ub - 1); i++) {
        in2_data[i] = ((in1_data[static_cast<int32_T>(i * stride_0_1)] *
                        in2->TargetDirectionWeight + in3_data
                        [static_cast<int32_T>(i * stride_1_1)] *
                        in2->CurrentDirectionWeight) + in4_data
                       [static_cast<int32_T>(i * stride_2_1)] *
                       in2->PreviousDirectionWeight) / 3.0 * in5;
    }

    in1_size[0] = 1;
    in1_size[1] = in2_size_idx_1;
    for (int32_T i{0}; i <= static_cast<int32_T>(in2_size_idx_1 - 1); i++) {
        in1_data[i] = in2_data[i];
    }
}

static void Real2SimGuidance_VectorFieldHistogramBase_computeCost(const
    nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, const
    real_T c_data[], const int32_T c_size[2], real_T targetDir, real_T prevDir,
    real_T cost_data[], int32_T cost_size[2])
{
    real_T delta_data[183];
    real_T prevDir_data[183];
    real_T targetDir_data[183];
    real_T totalWeight;
    int32_T delta_size[2];
    int32_T prevDir_size[2];
    int32_T targetDir_size[2];
    int32_T tmp;
    totalWeight = (obj->TargetDirectionWeight + obj->CurrentDirectionWeight) +
        obj->PreviousDirectionWeight;
    tmp = c_size[1];
    targetDir_size[0] = 1;
    targetDir_size[1] = c_size[1];
    for (int32_T b_k{0}; b_k <= static_cast<int32_T>(tmp - 1); b_k++) {
        targetDir_data[b_k] = targetDir - c_data[b_k];
    }

    Real2SimGuidance_wrapToPi_p34(targetDir_data, targetDir_size, delta_data,
        delta_size);
    cost_size[0] = 1;
    cost_size[1] = delta_size[1];
    tmp = static_cast<int32_T>(delta_size[1] - 1);
    for (int32_T b_k{0}; b_k <= tmp; b_k++) {
        cost_data[b_k] = std::abs(delta_data[b_k]);
    }

    tmp = c_size[1];
    targetDir_size[0] = 1;
    targetDir_size[1] = c_size[1];
    for (int32_T b_k{0}; b_k <= static_cast<int32_T>(tmp - 1); b_k++) {
        targetDir_data[b_k] = 0.0 - c_data[b_k];
    }

    Real2SimGuidance_wrapToPi_p34(targetDir_data, targetDir_size, delta_data,
        delta_size);
    targetDir_size[0] = 1;
    targetDir_size[1] = delta_size[1];
    tmp = static_cast<int32_T>(delta_size[1] - 1);
    for (int32_T b_k{0}; b_k <= tmp; b_k++) {
        targetDir_data[b_k] = std::abs(delta_data[b_k]);
    }

    tmp = c_size[1];
    prevDir_size[0] = 1;
    prevDir_size[1] = c_size[1];
    for (int32_T b_k{0}; b_k <= static_cast<int32_T>(tmp - 1); b_k++) {
        prevDir_data[b_k] = prevDir - c_data[b_k];
    }

    Real2SimGuidance_wrapToPi_p34(prevDir_data, prevDir_size, delta_data,
        delta_size);
    prevDir_size[0] = 1;
    prevDir_size[1] = delta_size[1];
    tmp = static_cast<int32_T>(delta_size[1] - 1);
    for (int32_T b_k{0}; b_k <= tmp; b_k++) {
        prevDir_data[b_k] = std::abs(delta_data[b_k]);
    }

    if (static_cast<boolean_T>(static_cast<int32_T>(((cost_size[1] == 1 ?
            targetDir_size[1] : cost_size[1]) == delta_size[1]) & (cost_size[1] ==
           targetDir_size[1])))) {
        tmp = static_cast<int32_T>(cost_size[1] - 1);
        cost_size[0] = 1;
        for (int32_T b_k{0}; b_k <= tmp; b_k++) {
            cost_data[b_k] = ((obj->TargetDirectionWeight * cost_data[b_k] +
                               obj->CurrentDirectionWeight * targetDir_data[b_k])
                              + obj->PreviousDirectionWeight * prevDir_data[b_k])
                / 3.0 * totalWeight;
        }
    } else {
        Real2SimGuidance_binary_expand_op_puhaq5roxr0oyl(cost_data, cost_size,
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
    if (static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>(
            static_cast<int32_T>(x_size[1] - 1))) + 1) <= 2) {
        if (static_cast<int32_T>(static_cast<int32_T>(static_cast<uint8_T>(
                static_cast<int32_T>(x_size[1] - 1))) + 1) == 1) {
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

static real_T Real2SimGuidance_VectorFieldHistogramBase_selectHeadingDirection
    (nav_slalgs_internal_VectorFieldHistogram_Real2SimGuidance_T *obj, real_T
     targetDir, DW_Real2SimGuidance_f_T *localDW)
{
    emxArray_real_T_Real2SimGuidance_T *candToSectDiff;
    emxArray_real_T_Real2SimGuidance_T *tmp;
    emxArray_real_T_Real2SimGuidance_T *tmp_1;
    real_T cDiff_data[183];
    real_T candidateDirections_data[183];
    real_T candidateDirs_data[183];
    real_T tmp_0[122];
    real_T changes[121];
    real_T angles_data[120];
    real_T nonNarrowDirs_data[120];
    real_T sectors_data[120];
    real_T angles_data_0[60];
    real_T angles_data_1[60];
    real_T sectorSizes_data[60];
    real_T cb[2];
    real_T k[2];
    real_T thetaSteer;
    int32_T tmp_data[121];
    int32_T tb_data[120];
    int32_T sb_data[60];
    int32_T angles_size[2];
    int32_T angles_size_0[2];
    int32_T candidateDirections_size[2];
    int32_T foundSectors_size[2];
    int32_T nonNarrowDirs_size[2];
    int32_T sb_size[2];
    int32_T sectors_size[2];
    int32_T tmp_size[2];
    int32_T d_i;
    int32_T trueCount;
    int8_T nb_data[60];
    uint8_T ub_data[183];
    boolean_T freeDirs_data[183];
    boolean_T narrowIdx_data[60];
    tmp_0[0] = 0.0;
    for (trueCount = 0; trueCount < 120; trueCount++) {
        tmp_0[static_cast<int32_T>(trueCount + 1)] = static_cast<real_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(obj->MaskedHistogram[trueCount]) ^ 1))));
    }

    tmp_0[121] = 0.0;
    Real2SimGuidance_diff(tmp_0, changes);
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (Real2SimGuidance_any(changes)) ^ 1))) {
        thetaSteer = (rtNaN);
        obj->PreviousDirection = (rtNaN);
    } else {
        real_T cVal;
        int32_T loop_ub;
        int32_T qb_size_idx_1;
        int32_T sectors_data_tmp;
        Real2SimGuidance_eml_find(changes, tmp_data, tmp_size);
        foundSectors_size[0] = 1;
        foundSectors_size[1] = tmp_size[1];
        loop_ub = tmp_size[1];
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            changes[trueCount] = static_cast<real_T>(tmp_data[trueCount]);
        }

        sectors_size[0] = 2;
        sectors_size[1] = static_cast<int32_T>(static_cast<uint32_T>(
            static_cast<uint32_T>(tmp_size[1]) >> 1));
        loop_ub = static_cast<int32_T>(static_cast<int32_T>(static_cast<uint32_T>
            (static_cast<uint32_T>(tmp_size[1]) >> 1)) << 1);
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            sectors_data[trueCount] = changes[trueCount];
        }

        if (static_cast<int32_T>(static_cast<uint32_T>(static_cast<uint32_T>
                (tmp_size[1]) >> 1)) < 1) {
            loop_ub = 0;
        } else {
            loop_ub = static_cast<int32_T>(static_cast<uint32_T>(static_cast<
                uint32_T>(tmp_size[1]) >> 1));
        }

        if (static_cast<int32_T>(static_cast<uint32_T>(static_cast<uint32_T>
                (tmp_size[1]) >> 1)) == loop_ub) {
            for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                    trueCount++) {
                sectors_data_tmp = static_cast<int32_T>(static_cast<int32_T>
                    (trueCount << 1) + 1);
                sectors_data[sectors_data_tmp] = static_cast<real_T>(
                    static_cast<int32_T>(changes[sectors_data_tmp])) - 1.0;
            }
        } else {
            Real2SimGuidance_binary_expand_op_puhaq5roxr0(sectors_data, changes,
                foundSectors_size, loop_ub);
        }

        loop_ub = static_cast<int32_T>(sectors_size[1] << 1);
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            angles_data[trueCount] = 0.0;
        }

        if (sectors_size[1] < 1) {
            loop_ub = -1;
        } else {
            loop_ub = static_cast<int32_T>(sectors_size[1] - 1);
        }

        for (trueCount = 0; trueCount <= loop_ub; trueCount++) {
            sectors_data_tmp = static_cast<int32_T>(trueCount << 1);
            angles_data[sectors_data_tmp] = obj->AngularSectorMidPoints[
                static_cast<int32_T>(static_cast<int32_T>
                (sectors_data[sectors_data_tmp]) - 1)];
        }

        if (sectors_size[1] < 1) {
            loop_ub = -1;
        } else {
            loop_ub = static_cast<int32_T>(sectors_size[1] - 1);
        }

        for (trueCount = 0; trueCount <= loop_ub; trueCount++) {
            sectors_data_tmp = static_cast<int32_T>(static_cast<int32_T>
                (trueCount << 1) + 1);
            angles_data[sectors_data_tmp] = obj->AngularSectorMidPoints[
                static_cast<int32_T>(static_cast<int32_T>
                (sectors_data[sectors_data_tmp]) - 1)];
        }

        Real2SimGuidance_diff_f(sectors_data, sectors_size, sectorSizes_data,
                                tmp_size);
        loop_ub = static_cast<int32_T>(tmp_size[1] - 1);
        for (trueCount = 0; trueCount <= loop_ub; trueCount++) {
            sectorSizes_data[trueCount] *= obj->AngularDifference;
        }

        loop_ub = tmp_size[1];
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            narrowIdx_data[trueCount] = (sectorSizes_data[trueCount] <
                obj->NarrowOpeningThreshold);
        }

        sectors_data_tmp = static_cast<int32_T>(tmp_size[1] - 1);
        trueCount = 0;
        for (d_i = 0; d_i <= sectors_data_tmp; d_i++) {
            if (narrowIdx_data[d_i]) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        loop_ub = trueCount;
        trueCount = 0;
        for (d_i = 0; d_i <= sectors_data_tmp; d_i++) {
            if (narrowIdx_data[d_i]) {
                nb_data[trueCount] = static_cast<int8_T>(static_cast<int32_T>
                    (d_i + 1));
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        angles_size[0] = 1;
        angles_size[1] = loop_ub;
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            angles_data_0[trueCount] = angles_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(nb_data[trueCount]) -
                1) << 1)];
        }

        angles_size_0[0] = 1;
        angles_size_0[1] = loop_ub;
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            angles_data_1[trueCount] = angles_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
                (nb_data[trueCount]) - 1) << 1) + 1)];
        }

        Real2SimGuidance_bisectAngles(angles_data_0, angles_size, angles_data_1,
            angles_size_0, sectorSizes_data, tmp_size);
        trueCount = 0;
        for (d_i = 0; d_i <= sectors_data_tmp; d_i++) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (narrowIdx_data[d_i]) ^ 1))) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        loop_ub = trueCount;
        k[0] = 1.0;
        k[1] = static_cast<real_T>(trueCount);
        trueCount = 0;
        for (d_i = 0; d_i <= sectors_data_tmp; d_i++) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (narrowIdx_data[d_i]) ^ 1))) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        qb_size_idx_1 = trueCount;
        cb[0] = 1.0;
        cb[1] = static_cast<real_T>(trueCount);
        trueCount = 0;
        for (d_i = 0; d_i <= sectors_data_tmp; d_i++) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (narrowIdx_data[d_i]) ^ 1))) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        sb_size[0] = 1;
        sb_size[1] = trueCount;
        trueCount = 0;
        for (d_i = 0; d_i <= sectors_data_tmp; d_i++) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (narrowIdx_data[d_i]) ^ 1))) {
                sb_data[trueCount] = static_cast<int32_T>(d_i + 1);
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((sb_size[1] == loop_ub)
                & (sb_size[1] == qb_size_idx_1)))) {
            nonNarrowDirs_size[1] = static_cast<int32_T>(sb_size[1] + sb_size[1]);
            loop_ub = sb_size[1];
            for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                    trueCount++) {
                nonNarrowDirs_data[trueCount] = angles_data[static_cast<int32_T>
                    (static_cast<int32_T>(sb_data[trueCount] - 1) << 1)] +
                    obj->NarrowOpeningThreshold / 2.0;
            }

            loop_ub = sb_size[1];
            for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                    trueCount++) {
                nonNarrowDirs_data[static_cast<int32_T>(trueCount + sb_size[1])]
                    = angles_data[static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(sb_data[trueCount] - 1) << 1) + 1)] -
                    obj->NarrowOpeningThreshold / 2.0;
            }
        } else {
            Real2SimGuidance_binary_expand_op_puhaq5rox(nonNarrowDirs_data,
                nonNarrowDirs_size, angles_data, sb_data, sb_size, k, obj, cb);
        }

        if (std::isnan(obj->PreviousDirection)) {
            obj->PreviousDirection = 0.0;
        }

        sectors_data_tmp = static_cast<int32_T>(nonNarrowDirs_size[1] +
            tmp_size[1]);
        loop_ub = nonNarrowDirs_size[1];
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            candidateDirs_data[trueCount] = nonNarrowDirs_data[trueCount];
        }

        loop_ub = tmp_size[1];
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            candidateDirs_data[static_cast<int32_T>(trueCount +
                nonNarrowDirs_size[1])] = sectorSizes_data[trueCount];
        }

        candidateDirs_data[sectors_data_tmp] = targetDir;
        candidateDirs_data[static_cast<int32_T>(sectors_data_tmp + 1)] = 0.0;
        candidateDirs_data[static_cast<int32_T>(sectors_data_tmp + 2)] =
            obj->PreviousDirection;
        d_i = static_cast<int32_T>(sectors_data_tmp + 3);
        loop_ub = static_cast<int32_T>(sectors_data_tmp + 3);
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            cDiff_data[trueCount] = candidateDirs_data[trueCount];
        }

        Real2SimGuidance_emxInit_real_T(&tmp_1, 2);
        Real2SimGuidance_bsxfun(obj->AngularSectorMidPoints, cDiff_data, &d_i,
                                tmp_1);
        Real2SimGuidance_emxInit_real_T(&candToSectDiff, 2);
        Real2SimGuidance_abs_pj(tmp_1, candToSectDiff);
        Real2SimGuidance_emxFree_real_T(&tmp_1);
        Real2SimGuidance_minimum_p(candToSectDiff, cDiff_data, &d_i);
        Real2SimGuidance_emxInit_real_T(&tmp, 2);
        Real2SimGuidance_bsxfun_p(candToSectDiff, cDiff_data, &d_i, tmp);
        Real2SimGuidance_emxFree_real_T(&candToSectDiff);
        qb_size_idx_1 = tmp->size[0];
        loop_ub = static_cast<int32_T>(tmp->size[0] * 120);
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            localDW->nearIdx_data[trueCount] = (tmp->data[trueCount] <
                1.4901161193847656E-8);
        }

        Real2SimGuidance_emxFree_real_T(&tmp);
        for (trueCount = 0; trueCount <= static_cast<int32_T>(qb_size_idx_1 - 1);
             trueCount++) {
            freeDirs_data[trueCount] = true;
        }

        sectors_data_tmp = static_cast<int32_T>(qb_size_idx_1 - 1);
        for (loop_ub = 0; loop_ub <= sectors_data_tmp; loop_ub++) {
            int32_T tb_size_idx_1;
            boolean_T exitg1;
            boolean_T y;
            d_i = 0;
            for (trueCount = 0; trueCount < 120; trueCount++) {
                if (localDW->nearIdx_data[static_cast<int32_T>
                        (static_cast<int32_T>(qb_size_idx_1 * trueCount) +
                         loop_ub)]) {
                    d_i = static_cast<int32_T>(d_i + 1);
                }
            }

            tb_size_idx_1 = d_i;
            d_i = 0;
            for (trueCount = 0; trueCount < 120; trueCount++) {
                if (localDW->nearIdx_data[static_cast<int32_T>(static_cast<
                        int32_T>(qb_size_idx_1 * trueCount) + loop_ub)]) {
                    tb_data[d_i] = static_cast<int32_T>(trueCount + 1);
                    d_i = static_cast<int32_T>(d_i + 1);
                }
            }

            y = false;
            d_i = 0;
            exitg1 = false;
            while ((!exitg1) && (static_cast<int32_T>(d_i + 1) <= tb_size_idx_1))
            {
                if (obj->MaskedHistogram[static_cast<int32_T>(tb_data[d_i] - 1)])
                {
                    y = true;
                    exitg1 = true;
                } else {
                    d_i = static_cast<int32_T>(d_i + 1);
                }
            }

            freeDirs_data[loop_ub] = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(y) ^ 1));
        }

        loop_ub = static_cast<int32_T>(qb_size_idx_1 - 1);
        d_i = 0;
        for (sectors_data_tmp = 0; sectors_data_tmp <= loop_ub; sectors_data_tmp
                ++) {
            if (freeDirs_data[sectors_data_tmp]) {
                d_i = static_cast<int32_T>(d_i + 1);
            }
        }

        candidateDirections_size[0] = 1;
        candidateDirections_size[1] = d_i;
        d_i = 0;
        for (sectors_data_tmp = 0; sectors_data_tmp <= loop_ub; sectors_data_tmp
                ++) {
            if (freeDirs_data[sectors_data_tmp]) {
                candidateDirections_data[d_i] =
                    candidateDirs_data[sectors_data_tmp];
                d_i = static_cast<int32_T>(d_i + 1);
            }
        }

        Real2SimGuidance_VectorFieldHistogramBase_computeCost(obj,
            candidateDirections_data, candidateDirections_size, targetDir,
            obj->PreviousDirection, candidateDirs_data, sectors_size);
        cVal = Real2SimGuidance_minimum_p0(candidateDirs_data, sectors_size);
        loop_ub = sectors_size[1];
        for (trueCount = 0; trueCount <= static_cast<int32_T>(loop_ub - 1);
                trueCount++) {
            cDiff_data[trueCount] = candidateDirs_data[trueCount] - cVal;
        }

        loop_ub = static_cast<int32_T>(sectors_size[1] - 1);
        d_i = 0;
        for (sectors_data_tmp = 0; sectors_data_tmp <= loop_ub; sectors_data_tmp
                ++) {
            if (cDiff_data[sectors_data_tmp] < 1.4901161193847656E-8) {
                d_i = static_cast<int32_T>(d_i + 1);
            }
        }

        qb_size_idx_1 = d_i;
        d_i = 0;
        for (sectors_data_tmp = 0; sectors_data_tmp <= loop_ub; sectors_data_tmp
                ++) {
            if (cDiff_data[sectors_data_tmp] < 1.4901161193847656E-8) {
                ub_data[d_i] = static_cast<uint8_T>(static_cast<int32_T>
                    (sectors_data_tmp + 1));
                d_i = static_cast<int32_T>(d_i + 1);
            }
        }

        sectors_size[0] = 1;
        sectors_size[1] = qb_size_idx_1;
        for (trueCount = 0; trueCount <= static_cast<int32_T>(qb_size_idx_1 - 1);
             trueCount++) {
            candidateDirs_data[trueCount] = candidateDirections_data[
                static_cast<int32_T>(static_cast<int32_T>(ub_data[trueCount]) -
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
    Real2SimGuidance_emxFree_real_T(&scan_InternalAngles);
    Real2SimGuidance_emxFree_real_T(&scan_InternalRanges);
    steeringDir =
        Real2SimGuidance_VectorFieldHistogramBase_selectHeadingDirection(obj,
        target, localDW);
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
            int32_T b_ilast;
            int32_T b_nlast;
            int32_T i1;
            int32_T ngroupsof5;
            boolean_T guard1{ false };

            b_nlast = b_v->size[0];
            b_v->size[0] = v->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(b_v, b_nlast);
            i1 = v->size[0];
            for (b_nlast = 0; b_nlast <= static_cast<int32_T>(i1 - 1); b_nlast++)
            {
                b_v->data[b_nlast] = v->data[b_nlast];
            }

            vref = v->data[ipiv];
            b_v->data[ipiv] = v->data[ib];
            b_v->data[ib] = v->data[ipiv];
            b_ilast = ia;
            ngroupsof5 = -1;
            for (b_nlast = static_cast<int32_T>(ia + 1); b_nlast <= ib; b_nlast
                    ++) {
                real_T vk_tmp;
                vk_tmp = b_v->data[static_cast<int32_T>(b_nlast - 1)];
                if (vk_tmp == vref) {
                    b_v->data[static_cast<int32_T>(b_nlast - 1)] = b_v->
                        data[b_ilast];
                    b_v->data[b_ilast] = vk_tmp;
                    ngroupsof5 = static_cast<int32_T>(ngroupsof5 + 1);
                    b_ilast = static_cast<int32_T>(b_ilast + 1);
                } else if (vk_tmp < vref) {
                    b_v->data[static_cast<int32_T>(b_nlast - 1)] = b_v->
                        data[b_ilast];
                    b_v->data[b_ilast] = vk_tmp;
                    b_ilast = static_cast<int32_T>(b_ilast + 1);
                }
            }

            b_v->data[ib] = b_v->data[b_ilast];
            b_v->data[b_ilast] = v->data[ipiv];
            b_nlast = v->size[0];
            v->size[0] = b_v->size[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(v, b_nlast);
            i1 = b_v->size[0];
            for (b_nlast = 0; b_nlast <= static_cast<int32_T>(i1 - 1); b_nlast++)
            {
                v->data[b_nlast] = b_v->data[b_nlast];
            }

            *nlast = static_cast<int32_T>(b_ilast + 1);
            guard1 = false;
            if (n <= static_cast<int32_T>(b_ilast + 1)) {
                *nfirst = static_cast<int32_T>(b_ilast - ngroupsof5);
                if (n >= *nfirst) {
                    exitg1 = true;
                } else {
                    ib = static_cast<int32_T>(b_ilast - 1);
                    guard1 = true;
                }
            } else {
                ia = static_cast<int32_T>(b_ilast + 1);
                guard1 = true;
            }

            if (guard1) {
                b_ilast = static_cast<int32_T>(static_cast<int32_T>(ib - ia) + 1);
                if (checkspeed) {
                    isslow = (b_ilast > static_cast<int32_T>(oldnv / 2));
                    oldnv = b_ilast;
                }

                checkspeed = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(checkspeed) ^ 1));
                if (isslow) {
                    while (b_ilast > 1) {
                        int32_T destidx;
                        ngroupsof5 = static_cast<int32_T>(b_ilast / 5);
                        b_nlast = static_cast<int32_T>(b_ilast -
                            static_cast<int32_T>(ngroupsof5 * 5));
                        b_ilast = ngroupsof5;
                        for (ipiv = 0; ipiv <= static_cast<int32_T>(ngroupsof5 -
                              1); ipiv++) {
                            i1 = static_cast<int32_T>(static_cast<int32_T>(
                                static_cast<int32_T>(ipiv * 5) + ia) + 1);
                            i1 = static_cast<int32_T>
                                (Real2SimGuidance_thirdOfFive(v, i1,
                                  static_cast<int32_T>(i1 + 4)) - 1);
                            destidx = static_cast<int32_T>(ia + ipiv);
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
                            b_ilast = static_cast<int32_T>(ngroupsof5 + 1);
                        }
                    }
                } else if (b_ilast >= 3) {
                    ipiv = static_cast<int32_T>(static_cast<int32_T>(
                        static_cast<int32_T>(b_ilast - 1) / 2) + ia);
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
    emxArray_real_T_Real2SimGuidance_T *a__4;
    real_T b;
    real_T m;
    int32_T a__5;
    int32_T a__6;
    int32_T loop_ub;
    int32_T midm1;
    midm1 = 0;
    Real2SimGuidance_emxInit_real_T(&a__4, 1);
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
                    Real2SimGuidance_quickselect(v, static_cast<int32_T>(midm1 +
                        1), n, &m, &a__6, &a__5);
                    if (midm1 < a__6) {
                        a__6 = a__4->size[0];
                        a__4->size[0] = v->size[0];
                        Real2SimGuidance_emxEnsureCapacity_real_T(a__4, a__6);
                        loop_ub = v->size[0];
                        for (a__6 = 0; a__6 <= static_cast<int32_T>(loop_ub - 1);
                             a__6++) {
                            a__4->data[a__6] = v->data[a__6];
                        }

                        Real2SimGuidance_quickselect(a__4, midm1,
                            static_cast<int32_T>(a__5 - 1), &b, &a__6, &loop_ub);
                        if (std::isinf(m)) {
                            m = (m + b) / 2.0;
                        } else {
                            m += (b - m) / 2.0;
                        }
                    }
                } else {
                    a__6 = a__4->size[0];
                    a__4->size[0] = v->size[0];
                    Real2SimGuidance_emxEnsureCapacity_real_T(a__4, a__6);
                    loop_ub = v->size[0];
                    for (a__6 = 0; a__6 <= static_cast<int32_T>(loop_ub - 1);
                            a__6++) {
                        a__4->data[a__6] = v->data[a__6];
                    }

                    Real2SimGuidance_quickselect(a__4, static_cast<int32_T>
                        (midm1 + 1), n, &m, &a__5, &a__6);
                }
            }

            exitg1 = 1;
        }
    } while (exitg1 == 0);

    Real2SimGuidance_emxFree_real_T(&a__4);
    return m;
}

// Function for MATLAB Function: '<S16>/Cartesian2Polar'
static real_T Real2SimGuidance_median(const emxArray_real_T_Real2SimGuidance_T
    *x)
{
    emxArray_real_T_Real2SimGuidance_T *b_x;
    real_T y;
    if (x->size[0] == 0) {
        y = (rtNaN);
    } else {
        int32_T i;
        int32_T loop_ub;
        Real2SimGuidance_emxInit_real_T(&b_x, 1);
        i = b_x->size[0];
        b_x->size[0] = x->size[0];
        Real2SimGuidance_emxEnsureCapacity_real_T(b_x, i);
        loop_ub = x->size[0];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            b_x->data[i] = x->data[i];
        }

        y = Real2SimGuidance_vmedian(b_x, x->size[0]);
        Real2SimGuidance_emxFree_real_T(&b_x);
    }

    return y;
}

static void Real2SimGuidance_binary_expand_op_p
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

    // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
    // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
    // MATLAB Function: '<S16>/Cartesian2Polar'
    in6_0 = in6->data[in7];

    // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
    // End of Outputs for SubSystem: '<Root>/AvoidDanger'
    Real2SimGuidance_emxInit_boolean_T(&in1_0, 1);

    // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
    // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
    // MATLAB Function: '<S16>/Cartesian2Polar'
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

    // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
    // End of Outputs for SubSystem: '<Root>/AvoidDanger'
    Real2SimGuidance_emxFree_boolean_T(&in1_0);
}

// System initialize for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX)
{
    FILE* a;
    int32_T i;

    // SystemInitialize for MATLAB Function: '<S6>/ReadHomePoint'
    Real2SimGuidance_ReadHomePoint_Init(&localDW->sf_ReadHomePoint);

    // SystemInitialize for Atomic SubSystem: '<Root>/Real2SimNav'
    // InitializeConditions for Integrator: '<S100>/TD_Alt'
    localX->TD_Alt_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S100>/dotAltTD'
    localX->dotAltTD_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<S9>/GenerateTrack'
    for (i = 0; i < 216; i++) {
        // InitializeConditions for S-Function (sfix_udelay): '<S94>/HeightSequence' incorporates:
        //   S-Function (sfix_udelay): '<S94>/EastSequence'

        localDW->HeightSequence_X[i] = -150.0;
    }

    // End of SystemInitialize for SubSystem: '<S9>/GenerateTrack'

    // SystemInitialize for Atomic SubSystem: '<S9>/SpeedControl'
    // SystemInitialize for MATLAB Function: '<S99>/getSpeedLimit'
    a = NULL;
    for (i = 0; i < 20; i++) {
        localDW->eml_openfiles_p[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S99>/getSpeedLimit'

    // SystemInitialize for Enabled SubSystem: '<S99>/SpdFBControl'
    // SystemInitialize for Enabled SubSystem: '<S118>/ADRC'
    // InitializeConditions for Integrator: '<S124>/Integrator'
    localX->Integrator_CSTATE[0] = 0.0;
    localX->Integrator_CSTATE[1] = 0.0;
    localX->Integrator_CSTATE[2] = 0.0;

    // End of SystemInitialize for SubSystem: '<S118>/ADRC'
    // End of SystemInitialize for SubSystem: '<S99>/SpdFBControl'
    // End of SystemInitialize for SubSystem: '<S9>/SpeedControl'

    // SystemInitialize for Atomic SubSystem: '<S9>/MaxBrake'
    // SystemInitialize for MATLAB Function: '<S97>/getSpeedLimit'
    a = NULL;
    for (i = 0; i < 20; i++) {
        localDW->eml_openfiles_i[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S97>/getSpeedLimit'
    // End of SystemInitialize for SubSystem: '<S9>/MaxBrake'

    // SystemInitialize for Atomic SubSystem: '<S9>/HeadingLogic'
    // SystemInitialize for Atomic SubSystem: '<S95>/NewMissionHdg'
    // InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;

    // End of SystemInitialize for SubSystem: '<S95>/NewMissionHdg'

    // Start for MATLABSystem: '<S95>/TrackSimPath'
    localDW->obj.LastWaypointFlag = false;
    localDW->obj.StartFlag = true;
    localDW->obj.LookaheadFactor = 1.01;
    localDW->obj.SearchFlag = true;
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    localDW->obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S95>/TrackSimPath'
    localDW->obj.WaypointIndex = 1.0;
    for (i = 0; i < 651; i++) {
        // Start for MATLABSystem: '<S95>/TrackSimPath'
        localDW->obj.WaypointsInternal[i] = 0.0;

        // InitializeConditions for MATLABSystem: '<S95>/TrackSimPath'
        localDW->obj.WaypointsInternal[i] *= 0.0;
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
    // Start for MATLABSystem: '<S17>/Vector Field Histogram'
    localDW->obj_p.NarrowOpeningThreshold = 0.8;
    localDW->obj_p.AngularLimits[0] = -3.1415926535897931;
    localDW->obj_p.AngularLimits[1] = 3.1415926535897931;
    localDW->obj_p.CacheInputSizes = false;
    localDW->objisempty_f = true;
    localDW->obj_p.DistanceLimits[0] = Real2SimGuidance_minimum
        (rtCP_VectorFieldHistogram_DistanceLimits);
    localDW->obj_p.DistanceLimits[1] = 686.86935486365564;
    localDW->obj_p.HistogramThresholds[0] = Real2SimGuidance_minimum
        (rtCP_VectorFieldHistogram_HistogramThresholds);
    localDW->obj_p.HistogramThresholds[1] = 1717.1733871591391;
    localDW->obj_p.RobotRadius = 35.0;
    localDW->obj_p.SafetyDistance = 35.0;
    localDW->obj_p.MinTurningRadius = 171.71733871591391;
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
                (120U * sizeof(boolean_T)));
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

    // SystemInitialize for MATLAB Function: '<S7>/ReadHomePoint'
    Real2SimGuidance_ReadHomePoint_Init(&localDW->sf_ReadHomePoint_p);

    // SystemInitialize for MATLAB Function: '<Root>/Get Nominal Flight Speed'
    a = NULL;
    for (i = 0; i < 20; i++) {
        localDW->eml_openfiles_k[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<Root>/Get Nominal Flight Speed' 
}

// Disable for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW)
{
    // Disable for Atomic SubSystem: '<Root>/Real2SimNav'
    // Disable for Atomic SubSystem: '<S9>/SpeedControl'
    // Disable for Enabled SubSystem: '<S99>/SpdFBControl'
    if (localDW->SpdFBControl_MODE) {
        // Disable for Enabled SubSystem: '<S118>/ADRC'
        localDW->ADRC_MODE = false;

        // End of Disable for SubSystem: '<S118>/ADRC'

        // Disable for Enabled SubSystem: '<S118>/PID'
        localDW->PID_MODE = false;

        // End of Disable for SubSystem: '<S118>/PID'
        localDW->SpdFBControl_MODE = false;
    }

    // End of Disable for SubSystem: '<S99>/SpdFBControl'

    // Disable for Enabled SubSystem: '<S99>/EnableBias'
    localDW->EnableBias_MODE = false;

    // End of Disable for SubSystem: '<S99>/EnableBias'
    // End of Disable for SubSystem: '<S9>/SpeedControl'

    // Disable for Atomic SubSystem: '<S9>/HeadingLogic'
    // Disable for Atomic SubSystem: '<S95>/NewMissionHdg'
    // Disable for Enabled SubSystem: '<S103>/CalForwardShift'
    localDW->CalForwardShift_MODE = false;

    // End of Disable for SubSystem: '<S103>/CalForwardShift'
    // End of Disable for SubSystem: '<S95>/NewMissionHdg'
    // End of Disable for SubSystem: '<S9>/HeadingLogic'
    // End of Disable for SubSystem: '<Root>/Real2SimNav'

    // Disable for Enabled SubSystem: '<Root>/Enabled Subsystem'
    localDW->EnabledSubsystem_MODE = false;

    // End of Disable for SubSystem: '<Root>/Enabled Subsystem'

    // Disable for Atomic SubSystem: '<Root>/AvoidDanger'
    // Disable for Enabled SubSystem: '<S1>/TieredVFH+'
    localDW->TieredVFH_MODE = false;

    // End of Disable for SubSystem: '<S1>/TieredVFH+'
    // End of Disable for SubSystem: '<Root>/AvoidDanger'
}

// Outputs for referenced model: 'Real2SimGuidance'
void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const Real2SimGuidance_M,
                      const boolean_T *rtu_NewMission, const uint8_T
                      *rtu_FlightMode, const RealUAVStateBus *rtu_FlightState,
                      const boolean_T rtu_ControlSwitch[2], const
                      FixedWingGuidanceStateBus *rtu_SimUAVState, const
                      FixedWingGuidanceBus *rtu_ImmedGuidanceCMD, const real_T
                      *rtu_BiasRatio, const real_T *rtu_ParamADRC_hat_b, const
                      real_T *rtu_ParamADRC_omega_o, const real_T
                      *rtu_ParamADRC_omega_c, const real_T *rtu_ParamADRC_P,
                      const real_T *rtu_ParamADRC_I, const real_T
                      *rtu_ParamADRC_D, const boolean_T *rtu_ParamADRC_useADRC,
                      const real_T rtu_PntCldData[2097152], const int32_T
                      rtu_PntCldData_DIMS1[2], const real_T rtu_DngrListNER[192],
                      const int32_T rtu_DngrListNER_DIMS1[2], const real_T
                      *rtu_VecSpd_eastSpeed, const real_T *rtu_VecSpd_northSpeed,
                      const real_T *rtu_VecSpd_skySpeed, FCUCMD *rty_FCUCMD,
                      uint8_T *rty_EngagedFlag, FlightLogging *rty_FlightLogging,
                      DW_Real2SimGuidance_f_T *localDW, X_Real2SimGuidance_n_T
                      *localX)
{
    // local block i/o variables
    FixedWingGuidanceBus rtb_SwitchLookAheadPoint;
    FixedWingGuidanceBus rtb_BusAssignment;
    real_T rtb_lambdaWrapped;
    real_T rtb_lambdaWrapped_c;
    real_T rtb_lambdaWrapped_k;
    real_T rtb_Switch_l;
    real_T rtb_SwitchTargetHDG;
    real_T rtb_Minus;
    real_T rtb_Minus_i;
    real_T rtb_LagDistance;
    boolean_T rtb_NotInDngr;
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

    emxArray_boolean_T_Real2SimGuidance_T *c;
    emxArray_boolean_T_Real2SimGuidance_T *f;
    emxArray_boolean_T_Real2SimGuidance_T *slctTF;
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
    emxArray_char_T_Real2SimGuidance_T *tmp_5;
    emxArray_char_T_Real2SimGuidance_T *tmp_6;
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
    emxArray_int32_T_Real2SimGuidance_T *d;
    emxArray_int32_T_Real2SimGuidance_T *e;
    emxArray_real_T_Real2SimGuidance_T rtb_SelectEast_0;
    emxArray_real_T_Real2SimGuidance_T rtb_SelectEast_1;
    emxArray_real_T_Real2SimGuidance_T rtb_SelectNorth_0;
    emxArray_real_T_Real2SimGuidance_T rtb_SelectNorth_1;
    emxArray_real_T_Real2SimGuidance_T rtb_rho_1;
    emxArray_real_T_Real2SimGuidance_T rtb_theta_0;
    emxArray_real_T_Real2SimGuidance_T *AngSec;
    emxArray_real_T_Real2SimGuidance_T *NewPC;
    emxArray_real_T_Real2SimGuidance_T *catAngSec;
    emxArray_real_T_Real2SimGuidance_T *rtb_rho_0;
    emxArray_real_T_Real2SimGuidance_T *tmp;
    emxArray_real_T_Real2SimGuidance_T *tmp_0;
    creal_T inputArg_data;
    creal_T tmp_1;
    creal_T tmp_2;
    creal_T tmp_3;
    creal_T tmp_4;
    real_T NormdNdE_data[128];
    real_T NormdNdE_data_0[64];
    real_T NormdNdE_data_1[64];
    real_T r_data[64];
    real_T theta_data[64];
    real_T rtb_TmpSignalConversionAtTrackSimPathInport1[4];
    real_T a[3];
    real_T rtb_Heading[3];
    real_T rtb_biasH_0[2];
    real_T Gain;
    real_T K_idx_0;
    real_T b_fid;
    real_T ct_idx_0;
    real_T d_fid;
    real_T rtb_Abs1;
    real_T rtb_EngagedFlag;
    real_T rtb_Gain_p;
    real_T rtb_RefRngmMinRng;
    real_T rtb_Sum1_idx_0;
    real_T rtb_Sum1_idx_1;
    real_T rtb_Switch;
    real_T rtb_Switch_b;
    real_T rtb_UpperBound;
    real_T rtb_biasH;
    real_T usedInputGain;
    int32_T waypoints_size[2];
    int32_T boffset;
    int32_T coffset;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T iy;
    int32_T j;
    int32_T nblocks;
    int32_T tmp_10;
    int32_T tmp_v;
    int32_T tmp_w;
    int32_T tmp_x;
    int32_T tmp_y;
    int32_T tmp_z;
    uint8_T b_data[217];
    uint8_T rtb_Memory;
    uint8_T status;
    boolean_T x[648];
    boolean_T distinctWptsIdx[217];
    boolean_T y[216];
    boolean_T x_data[64];
    boolean_T RelationalOperator;
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T rtb_AvoidDanger;
    boolean_T rtb_Compare_j;
    boolean_T rtb_HdgStatus;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // MATLAB Function: '<S6>/ReadHomePoint'
        Real2SimGuidance_ReadHomePoint(localDW->LLA0_g,
            &localDW->sf_ReadHomePoint);

        // Switch: '<S57>/Switch' incorporates:
        //   Abs: '<S57>/Abs'
        //   Bias: '<S57>/Bias'
        //   Bias: '<S57>/Bias1'
        //   Constant: '<S57>/Constant2'
        //   Constant: '<S58>/Constant'
        //   Math: '<S57>/Math Function1'
        //   RelationalOperator: '<S58>/Compare'

        if (std::abs(localDW->LLA0_g[0]) > 180.0) {
            rtb_Switch = rt_modd_snf(localDW->LLA0_g[0] + 180.0, 360.0) - 180.0;
        } else {
            rtb_Switch = localDW->LLA0_g[0];
        }

        // End of Switch: '<S57>/Switch'

        // Abs: '<S54>/Abs1'
        rtb_Abs1 = std::abs(rtb_Switch);

        // RelationalOperator: '<S56>/Compare' incorporates:
        //   Constant: '<S56>/Constant'

        rtb_Compare_j = (rtb_Abs1 > 90.0);

        // Switch: '<S54>/Switch' incorporates:
        //   Constant: '<S45>/Constant'
        //   Constant: '<S45>/Constant1'
        //   Switch: '<S45>/Switch1'

        if (rtb_Compare_j) {
            // Signum: '<S54>/Sign1'
            if (std::isnan(rtb_Switch)) {
                rtb_Sum1_idx_0 = (rtNaN);
            } else if (rtb_Switch < 0.0) {
                rtb_Sum1_idx_0 = -1.0;
            } else {
                rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Switch > 0.0);
            }

            // Switch: '<S54>/Switch' incorporates:
            //   Bias: '<S54>/Bias'
            //   Bias: '<S54>/Bias1'
            //   Gain: '<S54>/Gain'
            //   Product: '<S54>/Divide1'
            //   Signum: '<S54>/Sign1'

            localDW->Switch = (-(rtb_Abs1 - 90.0) + 90.0) * rtb_Sum1_idx_0;
            i = 180;
        } else {
            // Switch: '<S54>/Switch'
            localDW->Switch = rtb_Switch;
            i = 0;
        }

        // End of Switch: '<S54>/Switch'

        // Sum: '<S45>/Sum' incorporates:
        //   Switch: '<S45>/Switch1'

        rtb_Abs1 = static_cast<real_T>(i) + localDW->LLA0_g[1];

        // Switch: '<S55>/Switch' incorporates:
        //   Abs: '<S55>/Abs'
        //   Constant: '<S59>/Constant'
        //   RelationalOperator: '<S59>/Compare'

        if (std::abs(rtb_Abs1) > 180.0) {
            // Switch: '<S55>/Switch' incorporates:
            //   Bias: '<S55>/Bias'
            //   Bias: '<S55>/Bias1'
            //   Constant: '<S55>/Constant2'
            //   Math: '<S55>/Math Function1'

            localDW->Switch_o = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) - 180.0;
        } else {
            // Switch: '<S55>/Switch'
            localDW->Switch_o = rtb_Abs1;
        }

        // End of Switch: '<S55>/Switch'
    }

    // Sum: '<S42>/Sum1'
    rtb_Sum1_idx_0 = rtu_FlightState->Latitude_deg - localDW->Switch;

    // Switch: '<S51>/Switch' incorporates:
    //   Abs: '<S51>/Abs'
    //   Bias: '<S51>/Bias'
    //   Bias: '<S51>/Bias1'
    //   Constant: '<S51>/Constant2'
    //   Constant: '<S52>/Constant'
    //   Math: '<S51>/Math Function1'
    //   RelationalOperator: '<S52>/Compare'

    if (std::abs(rtb_Sum1_idx_0) > 180.0) {
        rtb_Switch_b = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) - 180.0;
    } else {
        rtb_Switch_b = rtb_Sum1_idx_0;
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
    //   Signum: '<S48>/Sign1'
    //   Switch: '<S44>/Switch1'

    if (rtb_Abs1 > 90.0) {
        // Signum: '<S48>/Sign1'
        if (std::isnan(rtb_Switch_b)) {
            rtb_Sum1_idx_0 = (rtNaN);
        } else if (rtb_Switch_b < 0.0) {
            rtb_Sum1_idx_0 = -1.0;
        } else {
            rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Switch_b > 0.0);
        }

        rtb_Switch_b = (-(rtb_Abs1 - 90.0) + 90.0) * rtb_Sum1_idx_0;
        i = 180;
    } else {
        i = 0;
    }

    // End of Switch: '<S48>/Switch'

    // Sum: '<S44>/Sum' incorporates:
    //   Sum: '<S42>/Sum1'
    //   Switch: '<S44>/Switch1'

    rtb_Abs1 = (rtu_FlightState->Longitude_deg - localDW->Switch_o) +
        static_cast<real_T>(i);

    // Switch: '<S49>/Switch' incorporates:
    //   Abs: '<S49>/Abs'
    //   Bias: '<S49>/Bias'
    //   Bias: '<S49>/Bias1'
    //   Constant: '<S49>/Constant2'
    //   Constant: '<S53>/Constant'
    //   Math: '<S49>/Math Function1'
    //   RelationalOperator: '<S53>/Compare'

    if (std::abs(rtb_Abs1) > 180.0) {
        rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) - 180.0;
    }

    // End of Switch: '<S49>/Switch'

    // UnitConversion: '<S47>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    rtb_Sum1_idx_0 = 0.017453292519943295 * rtb_Switch_b;
    rtb_Sum1_idx_1 = 0.017453292519943295 * rtb_Abs1;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // UnitConversion: '<S62>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Switch = 0.017453292519943295 * localDW->Switch;

        // Trigonometry: '<S63>/Trigonometric Function1'
        rtb_Switch_b = std::sin(rtb_Switch);

        // Sum: '<S63>/Sum1' incorporates:
        //   Constant: '<S63>/Constant'
        //   Product: '<S63>/Product1'

        rtb_Switch_b = 1.0 - 0.0066943799901413295 * rtb_Switch_b * rtb_Switch_b;

        // Product: '<S61>/Product1' incorporates:
        //   Constant: '<S61>/Constant1'
        //   Sqrt: '<S61>/sqrt'

        K_idx_0 = 6.378137E+6 / std::sqrt(rtb_Switch_b);

        // Trigonometry: '<S61>/Trigonometric Function1' incorporates:
        //   Constant: '<S61>/Constant2'
        //   Product: '<S61>/Product3'

        localDW->TrigonometricFunction1 = rt_atan2d_snf(1.0, K_idx_0 *
            0.99330562000985867 / rtb_Switch_b);

        // Trigonometry: '<S46>/SinCos'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        localDW->SinCos_o1 = 0.0;

        // Trigonometry: '<S46>/SinCos'
        localDW->SinCos_o2 = 1.0;

        // Trigonometry: '<S61>/Trigonometric Function2' incorporates:
        //   Constant: '<S61>/Constant3'
        //   Product: '<S61>/Product4'
        //   Trigonometry: '<S61>/Trigonometric Function'

        localDW->TrigonometricFunction2 = rt_atan2d_snf(1.0, K_idx_0 * std::cos
            (rtb_Switch));
    }

    // Product: '<S46>/dNorth'
    rtb_Abs1 = rtb_Sum1_idx_0 / localDW->TrigonometricFunction1;

    // Product: '<S46>/dEast'
    rtb_Switch_b = 1.0 / localDW->TrigonometricFunction2 * rtb_Sum1_idx_1;

    // Sum: '<S46>/Sum2' incorporates:
    //   Product: '<S46>/x*cos'
    //   Product: '<S46>/y*sin'

    rtb_biasH = rtb_Abs1 * localDW->SinCos_o2 + rtb_Switch_b *
        localDW->SinCos_o1;

    // Sum: '<S46>/Sum3' incorporates:
    //   Product: '<S46>/x*sin'
    //   Product: '<S46>/y*cos'

    rtb_Abs1 = rtb_Switch_b * localDW->SinCos_o2 - rtb_Abs1 * localDW->SinCos_o1;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Gain: '<S6>/inverse'
        localDW->minusAltitudeGCS = -localDW->LLA0_g[2];
    }

    // BusCreator: '<S6>/FixedWingGuidanceStateBus' incorporates:
    //   Gain: '<S39>/Gain1'

    rtb_Switch_b = 0.017453292519943295 * rtu_FlightState->HeadingAngle_deg;

    // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S9>/HeadingNaNProtection'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Memory: '<S96>/MemoryRefHeight'
        localDW->OverwriteHeight = localDW->MemoryRefHeight_PreviousInput;
    }

    // End of Outputs for SubSystem: '<S9>/HeadingNaNProtection'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Memory: '<S9>/MemoryNotInBrake'
        rtb_Compare_j = localDW->MemoryNotInBrake_PreviousInput;

        // Logic: '<S9>/AND' incorporates:
        //   Constant: '<S98>/Constant'
        //   DataStoreRead: '<S9>/ReadFlightMode_Log'
        //   Memory: '<S9>/MemoryNotInBrake'
        //   RelationalOperator: '<S98>/Compare'

        localDW->AND = static_cast<boolean_T>(static_cast<int32_T>((static_cast<
            int32_T>(localDW->FlightMode_Log) == 3) & static_cast<int32_T>
            (localDW->MemoryNotInBrake_PreviousInput)));

        // Outputs for Atomic SubSystem: '<S9>/GenerateTrack'
        // S-Function (sfix_udelay): '<S94>/EastSequence' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'

        localDW->MatrixConcatenate[433] = rtu_SimUAVState->East;

        // S-Function (sfix_udelay): '<S94>/HeightSequence' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'

        localDW->MatrixConcatenate[650] = rtu_SimUAVState->Height;
        for (i = 0; i < 216; i++) {
            // S-Function (sfix_udelay): '<S94>/EastSequence' incorporates:
            //   Concatenate: '<S94>/Matrix Concatenate'

            localDW->MatrixConcatenate[static_cast<int_T>(i + 217)] =
                localDW->EastSequence_X[i];

            // S-Function (sfix_udelay): '<S94>/HeightSequence' incorporates:
            //   Concatenate: '<S94>/Matrix Concatenate'
            //   S-Function (sfix_udelay): '<S94>/EastSequence'

            localDW->MatrixConcatenate[static_cast<int_T>(i + 434)] =
                localDW->HeightSequence_X[i];

            // S-Function (sfix_udelay): '<S94>/NorthSequence' incorporates:
            //   Concatenate: '<S94>/Matrix Concatenate'
            //   S-Function (sfix_udelay): '<S94>/EastSequence'

            localDW->MatrixConcatenate[i] = localDW->NorthSequence_X[i];
        }

        // S-Function (sfix_udelay): '<S94>/NorthSequence' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'

        localDW->MatrixConcatenate[216] = rtu_SimUAVState->North;

        // End of Outputs for SubSystem: '<S9>/GenerateTrack'

        // Memory: '<S9>/Memory'
        rtb_Memory = localDW->Memory_PreviousInput;

        // Outputs for Atomic SubSystem: '<S9>/SpeedControl'
        // Selector: '<S99>/TargetLocation' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'

        localDW->TargetLocation[0] = localDW->MatrixConcatenate[60];
        localDW->TargetLocation[1] = localDW->MatrixConcatenate[277];
        localDW->TargetLocation[2] = localDW->MatrixConcatenate[494];

        // End of Outputs for SubSystem: '<S9>/SpeedControl'
    }

    // Outputs for Atomic SubSystem: '<S9>/SpeedControl'
    // Sum: '<S116>/Sum' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   Selector: '<S99>/TargetLocation'

    rtb_Heading[0] = localDW->TargetLocation[0] - rtu_SimUAVState->North;
    rtb_Heading[1] = localDW->TargetLocation[1] - rtu_SimUAVState->East;
    rtb_Heading[2] = localDW->TargetLocation[2] - rtu_SimUAVState->Height;

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   DotProduct: '<S116>/Dot Product'
    //   Sqrt: '<S116>/sqrt'

    rtb_LagDistance = (rtb_Heading[0] * rtb_Heading[0] + rtb_Heading[1] *
                       rtb_Heading[1]) + rtb_Heading[2] * rtb_Heading[2];
    rtb_LagDistance = std::sqrt(rtb_LagDistance);

    // Outputs for Atomic SubSystem: '<S9>/MaxBrake'
    // Sum: '<S115>/Sum' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
    //   Sum: '<S107>/Sum'

    rtb_Sum1_idx_0 = rtu_SimUAVState->North - rtb_biasH;
    ct_idx_0 = rtu_SimUAVState->East - rtb_Abs1;

    // End of Outputs for SubSystem: '<S9>/MaxBrake'
    rtb_Heading[2] = rtu_SimUAVState->Height - rtu_SimUAVState->Height;

    // Outputs for Atomic SubSystem: '<S9>/MaxBrake'
    // DotProduct: '<S115>/Dot Product' incorporates:
    //   DotProduct: '<S107>/Dot Product'
    //   Sum: '<S115>/Sum'

    rtb_Sum1_idx_0 = rtb_Sum1_idx_0 * rtb_Sum1_idx_0 + ct_idx_0 * ct_idx_0;

    // End of Outputs for SubSystem: '<S9>/MaxBrake'

    // Sqrt: '<S115>/sqrt' incorporates:
    //   DotProduct: '<S115>/Dot Product'

    rtb_Gain_p = std::sqrt(rtb_Heading[2] * rtb_Heading[2] + rtb_Sum1_idx_0);

    // Gain: '<S99>/Gain' incorporates:
    //   Sum: '<S99>/LagDistanceSum'

    Gain = -(rtb_LagDistance - rtb_Gain_p);

    // DataStoreWrite: '<S99>/WriteLagDistance'
    localDW->LagDistance = Gain;

    // End of Outputs for SubSystem: '<S9>/SpeedControl'
    // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    Real2SimGuidance_emxInit_char_T_e(&aTmp, 2);
    Real2SimGuidance_emxInit_char_T_e(&ret, 2);
    Real2SimGuidance_emxInit_char_T_e(&data, 2);
    Real2SimGuidance_emxInit_char_T_e(&curSection, 2);
    Real2SimGuidance_emxInit_char_T_e(&curKey, 2);
    Real2SimGuidance_emxInit_char_T_e(&curVal, 2);
    Real2SimGuidance_emxInit_char_T_e(&curLine, 2);
    Real2SimGuidance_emxInit_char_T_e(&k, 1);

    // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
    // Outputs for Atomic SubSystem: '<S9>/SpeedControl'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // MATLAB Function: '<S99>/getSpeedLimit'
        // MATLAB Function 'Real2SimNav/SpeedControl/getSpeedLimit': '<S119>:1'
        // '<S119>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->SingletonInstance_not_empty) ^ 1))) {
            localDW->SingletonInstance_p.AirSpeed = 35.0;
            localDW->SingletonInstance_p.MaxRollAngle = 0.3490658503988659;
            localDW->SingletonInstance_p.FlightPathAngleLimit[0] = -0.175;
            localDW->SingletonInstance_p.FlightPathAngleLimit[1] = 0.175;
            localDW->SingletonInstance_p.SpdLmt[0] = 29.0;
            localDW->SingletonInstance_p.SpdLmt[1] = 46.0;
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Sum1_idx_1 = Real2SimGuidance_fileManager_b(localDW);
            if (rtb_Sum1_idx_1 < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_h(rtb_Sum1_idx_1, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_m(rtb_Sum1_idx_1, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_t, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_u, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_d, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_d->size[0] * data_d->size[1]);
                    data_d->size[0] = 1;
                    data_d->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_d, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_d->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_d, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_u);
                    Real2SimGuidance_strtrim_o(tmp_u, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    i2 = 0;
                                    i1 = 0;
                                } else {
                                    i2 = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - i2);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(i2 + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_t);
                                Real2SimGuidance_strtrim_o(tmp_t, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bg(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_d);
                Real2SimGuidance_emxFree_char_T_o(&tmp_u);
                Real2SimGuidance_emxFree_char_T_o(&tmp_t);
            }

            inputArg_data = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV NormAirSpeed:\t\t%f\n", inputArg_data.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            b_fid = Real2SimGuidance_fileManager_b(localDW);
            if (b_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_h(b_fid, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_m(b_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_r, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_s, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_c, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_c->size[0] * data_c->size[1]);
                    data_c->size[0] = 1;
                    data_c->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_c, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_c->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_c, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_s);
                    Real2SimGuidance_strtrim_o(tmp_s, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_r);
                                Real2SimGuidance_strtrim_o(tmp_r, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bgl(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_c);
                Real2SimGuidance_emxFree_char_T_o(&tmp_s);
                Real2SimGuidance_emxFree_char_T_o(&tmp_r);
            }

            tmp_1 = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_1.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Switch = Real2SimGuidance_fileManager_b(localDW);
            if (rtb_Switch < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_h(rtb_Switch, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_m(rtb_Switch, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_p, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_q, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_b, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_b->size[0] * data_b->size[1]);
                    data_b->size[0] = 1;
                    data_b->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_b, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_b->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_b, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_q);
                    Real2SimGuidance_strtrim_o(tmp_q, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_p);
                                Real2SimGuidance_strtrim_o(tmp_p, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bglv(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_b);
                Real2SimGuidance_emxFree_char_T_o(&tmp_q);
                Real2SimGuidance_emxFree_char_T_o(&tmp_p);
            }

            tmp_2 = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_2.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            d_fid = Real2SimGuidance_fileManager_b(localDW);
            if (d_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_h(d_fid, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_m(d_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_n, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_o, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_a, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_a->size[0] * data_a->size[1]);
                    data_a->size[0] = 1;
                    data_a->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_a, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_a->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_a, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_o);
                    Real2SimGuidance_strtrim_o(tmp_o, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_n);
                                Real2SimGuidance_strtrim_o(tmp_n, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bglv3(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_a);
                Real2SimGuidance_emxFree_char_T_o(&tmp_o);
                Real2SimGuidance_emxFree_char_T_o(&tmp_n);
            }

            tmp_3 = Real2SimGuidance_str2double_k(ret);
            d_fid = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV MaxRollAngle:\t\t%f\n", d_fid);
            fflush(stdout);
            Real2SimGuidance_readINI_o(ret, localDW);
            tmp_3 = Real2SimGuidance_str2double_k(ret);
            rtb_Sum1_idx_1 = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV ClimbAngleLimit:\t%f\n", rtb_Sum1_idx_1);
            fflush(stdout);
            Real2SimGuidance_readINI_or(ret, localDW);
            tmp_3 = Real2SimGuidance_str2double_k(ret);
            b_fid = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV DiveAngleLimit:\t\t%f\n", b_fid);
            fflush(stdout);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(inputArg_data.re)) ^ 1))) {
                localDW->SingletonInstance_p.AirSpeed = inputArg_data.re;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(d_fid)) ^ 1))) {
                localDW->SingletonInstance_p.MaxRollAngle = d_fid;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(rtb_Sum1_idx_1)) ^ 1))) &&
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isnan(b_fid)) ^ 1)))) {
                localDW->SingletonInstance_p.FlightPathAngleLimit[0] = b_fid;
                localDW->SingletonInstance_p.FlightPathAngleLimit[1] =
                    rtb_Sum1_idx_1;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(tmp_1.re)) ^ 1))) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan
                    (tmp_2.re)) ^ 1)))) {
                localDW->SingletonInstance_p.SpdLmt[0] = tmp_2.re;
                localDW->SingletonInstance_p.SpdLmt[1] = tmp_1.re;
            }

            Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
                (&localDW->SingletonInstance_p.Connector,
                 localDW->SingletonInstance_p.AirSpeed,
                 localDW->SingletonInstance_p.MaxRollAngle);
            localDW->SingletonInstance_not_empty = true;
        }

        localDW->SpeedLimit[0] = localDW->SingletonInstance_p.SpdLmt[0];
        localDW->SpeedLimit[1] = localDW->SingletonInstance_p.SpdLmt[1];

        // End of MATLAB Function: '<S99>/getSpeedLimit'

        // MinMax: '<S99>/Max'
        localDW->Max = std::fmax(localDW->SpeedLimit[0], localDW->SpeedLimit[1]);

        // Outputs for Enabled SubSystem: '<S99>/SpdFBControl' incorporates:
        //   EnablePort: '<S118>/Enable'

        if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
            if (localDW->AND) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (localDW->SpdFBControl_MODE) ^ 1)))
                {
                    // SystemReset for Chart: '<S118>/ControlLogic'
                    localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->temporalCounter_i1_h = 0U;
                    localDW->is_active_c6_Real2SimGuidance = 0U;
                    localDW->is_c6_Real2SimGuidance =
                        Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->PID_U = false;
                    localDW->EnableADRC = false;
                    localDW->EnablePID = false;
                    localDW->SpdFBControl_MODE = true;
                }
            } else if (localDW->SpdFBControl_MODE) {
                // Disable for Enabled SubSystem: '<S118>/ADRC'
                localDW->ADRC_MODE = false;

                // End of Disable for SubSystem: '<S118>/ADRC'

                // Disable for Enabled SubSystem: '<S118>/PID'
                localDW->PID_MODE = false;

                // End of Disable for SubSystem: '<S118>/PID'
                localDW->SpdFBControl_MODE = false;
            }
        }

        // End of Outputs for SubSystem: '<S99>/SpdFBControl'
    }

    // Outputs for Enabled SubSystem: '<S99>/SpdFBControl' incorporates:
    //   EnablePort: '<S118>/Enable'

    if (localDW->SpdFBControl_MODE) {
        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Chart: '<S118>/ControlLogic'
            if (static_cast<uint32_T>(localDW->temporalCounter_i1_h) < 15U) {
                localDW->temporalCounter_i1_h = static_cast<uint8_T>(
                    static_cast<uint32_T>(static_cast<uint32_T>
                    (localDW->temporalCounter_i1_h) + 1U));
            }

            // Gateway: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
            // During: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
            if (static_cast<uint32_T>(localDW->is_active_c6_Real2SimGuidance) ==
                0U) {
                // Entry: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic
                localDW->is_active_c6_Real2SimGuidance = 1U;

                // Entry Internal: Real2SimNav/SpeedControl/SpdFBControl/ControlLogic 
                // Transition: '<S121>:81'
                localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                // Entry 'PID': '<S121>:53'
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;
            } else if (localDW->is_c6_Real2SimGuidance ==
                       Real2SimGuidance_IN_PID) {
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;

                // During 'PID': '<S121>:53'
                RelationalOperator = static_cast<boolean_T>(static_cast<int32_T>
                    ((static_cast<int32_T>(rtb_Memory) != 0) &
                     static_cast<int32_T>(*rtu_ParamADRC_useADRC)));
                if (RelationalOperator) {
                    // Transition: '<S121>:83'
                    localDW->is_c6_Real2SimGuidance =
                        Real2SimGuidance_IN_useADRC;
                    localDW->is_useADRC = Real2SimGuidance_IN_Debounce_l;
                    localDW->is_Debounce = Real2SimGuidance_IN_PID2ADRC;
                    localDW->temporalCounter_i1_h = 0U;

                    // Entry 'PID2ADRC': '<S121>:62'
                    localDW->EnableADRC = true;
                }

                // During 'useADRC': '<S121>:92'
            } else if (static_cast<boolean_T>(static_cast<int32_T>
                        (static_cast<int32_T>(*rtu_ParamADRC_useADRC) ^ 1))) {
                // Transition: '<S121>:98'
                // Exit Internal 'useADRC': '<S121>:92'
                // Exit Internal 'Debounce': '<S121>:58'
                localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                // Entry 'PID': '<S121>:53'
                localDW->EnablePID = true;
                localDW->EnableADRC = false;
                localDW->PID_U = true;
            } else if (localDW->is_useADRC == Real2SimGuidance_IN_ADRC) {
                localDW->EnablePID = false;
                localDW->EnableADRC = true;
                localDW->PID_U = false;

                // During 'ADRC': '<S121>:63'
                if (static_cast<int32_T>(rtb_Memory) == 0) {
                    // Transition: '<S121>:84'
                    localDW->is_useADRC = Real2SimGuidance_IN_Debounce_l;
                    localDW->is_Debounce = Real2SimGuidance_IN_ADRC2PID;
                    localDW->temporalCounter_i1_h = 0U;

                    // Entry 'ADRC2PID': '<S121>:61'
                    localDW->EnablePID = true;
                }

                // During 'Debounce': '<S121>:58'
            } else if (localDW->is_Debounce == Real2SimGuidance_IN_ADRC2PID) {
                localDW->EnablePID = true;

                // During 'ADRC2PID': '<S121>:61'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_h) >= 10U)
                {
                    // Transition: '<S121>:86'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_useADRC = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c6_Real2SimGuidance = Real2SimGuidance_IN_PID;

                    // Entry 'PID': '<S121>:53'
                    localDW->EnableADRC = false;
                    localDW->PID_U = true;
                } else if (static_cast<int32_T>(rtb_Memory) != 0) {
                    // Transition: '<S121>:59'
                    localDW->is_Debounce = Real2SimGuidance_IN_PID2ADRC;
                    localDW->temporalCounter_i1_h = 0U;

                    // Entry 'PID2ADRC': '<S121>:62'
                    localDW->EnableADRC = true;
                }
            } else {
                localDW->EnableADRC = true;

                // During 'PID2ADRC': '<S121>:62'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_h) >= 10U)
                {
                    // Transition: '<S121>:85'
                    localDW->is_Debounce = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_useADRC = Real2SimGuidance_IN_ADRC;

                    // Entry 'ADRC': '<S121>:63'
                    localDW->EnablePID = false;
                    localDW->PID_U = false;
                } else if (static_cast<int32_T>(rtb_Memory) == 0) {
                    // Transition: '<S121>:60'
                    localDW->is_Debounce = Real2SimGuidance_IN_ADRC2PID;
                    localDW->temporalCounter_i1_h = 0U;

                    // Entry 'ADRC2PID': '<S121>:61'
                    localDW->EnablePID = true;
                }
            }

            // End of Chart: '<S118>/ControlLogic'

            // Outputs for Enabled SubSystem: '<S118>/ADRC' incorporates:
            //   EnablePort: '<S120>/Enable'

            if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
                if (localDW->EnableADRC) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(localDW->ADRC_MODE) ^ 1))) {
                        // InitializeConditions for Integrator: '<S124>/Integrator' 
                        localX->Integrator_CSTATE[0] = 0.0;
                        localX->Integrator_CSTATE[1] = 0.0;
                        localX->Integrator_CSTATE[2] = 0.0;
                        localDW->ADRC_MODE = true;
                    }
                } else {
                    localDW->ADRC_MODE = false;
                }
            }

            // End of Outputs for SubSystem: '<S118>/ADRC'
        }

        // Outputs for Enabled SubSystem: '<S118>/ADRC' incorporates:
        //   EnablePort: '<S120>/Enable'

        if (localDW->ADRC_MODE) {
            // Integrator: '<S124>/Integrator'
            localDW->Integrator[0] = localX->Integrator_CSTATE[0];
            localDW->Integrator[1] = localX->Integrator_CSTATE[1];
            localDW->Integrator[2] = localX->Integrator_CSTATE[2];

            // MATLAB Function: '<S126>/Extended state feedback robust controller' 
            // MATLAB Function 'ADRC controller/State feedback robust controller/Extended state feedback robust controller': '<S130>:1' 
            // '<S130>:1:8'
            if (*rtu_ParamADRC_hat_b == 0.0) {
                // '<S130>:1:17'
                // '<S130>:1:18'
                usedInputGain = 1.0;
            } else {
                // '<S130>:1:20'
                usedInputGain = *rtu_ParamADRC_hat_b;
            }

            // '<S130>:1:9'
            if (*rtu_ParamADRC_omega_c == 0.0) {
                // '<S130>:1:17'
                // '<S130>:1:18'
                rtb_UpperBound = 5.0;
            } else {
                // '<S130>:1:20'
                rtb_UpperBound = *rtu_ParamADRC_omega_c;
            }

            // '<S130>:1:10'
            // '<S130>:1:25'
            rtb_Heading[0] = 1.0;
            for (j = 0; j < 2; j++) {
                rtb_Heading[static_cast<int32_T>(j + 1)] = rtb_UpperBound *
                    rtb_Heading[j];
                for (iy = static_cast<int32_T>(j + 1); iy >= 2; iy--) {
                    rtb_Heading[1] -= -rtb_UpperBound;
                }
            }

            // Product: '<S132>/Product' incorporates:
            //   MATLAB Function: '<S126>/Extended state feedback robust controller'
            //   Step: '<S132>/Step'

            // '<S130>:1:26'
            // '<S130>:1:12'
            localDW->Product = ((localDW->Integrator[0] * rtb_Heading[2] +
                                 rtb_Heading[1] * localDW->Integrator[1]) +
                                localDW->Integrator[2]) * (1.0 / usedInputGain) *
                static_cast<real_T>(static_cast<int32_T>(static_cast<boolean_T>(
                static_cast<int32_T>(((*(Real2SimGuidance_M->
                timingBridge->taskTime
                [Real2SimGuidance_M->Timing.mdlref_GlobalTID[0]])) < 0.2) ^ 1))));

            // MATLAB Function: '<S124>/Linear extended state observer' incorporates:
            //   MinMax: '<S97>/Max'
            //   MinMax: '<S97>/Min'
            //   MinMax: '<S99>/Max'
            //   MinMax: '<S99>/Min'

            // MATLAB Function 'ADRC controller/Linear extended state observer/Linear extended state observer': '<S127>:1' 
            // '<S127>:1:16'
            // '<S127>:1:10'
            if (*rtu_ParamADRC_hat_b == 0.0) {
                // '<S127>:1:22'
                // '<S127>:1:23'
                usedInputGain = 1.0;
            } else {
                // '<S127>:1:25'
                usedInputGain = *rtu_ParamADRC_hat_b;
            }

            // '<S127>:1:11'
            if (*rtu_ParamADRC_omega_o == 0.0) {
                // '<S127>:1:22'
                // '<S127>:1:23'
                rtb_UpperBound = 25.0;
            } else {
                // '<S127>:1:25'
                rtb_UpperBound = *rtu_ParamADRC_omega_o;
            }

            // '<S127>:1:13'
            // '<S127>:1:35'
            // '<S127>:1:14'
            // '<S127>:1:39'
            rtb_TmpSignalConversionAtTrackSimPathInport1[0] = 1.0;

            // '<S127>:1:40'
            // '<S127>:1:16'
            rtb_Switch = Gain - localDW->Integrator[0];
            for (j = 0; j < 3; j++) {
                rtb_TmpSignalConversionAtTrackSimPathInport1[static_cast<int32_T>
                    (j + 1)] = rtb_UpperBound *
                    rtb_TmpSignalConversionAtTrackSimPathInport1[j];
                for (iy = static_cast<int32_T>(j + 1); iy >= 2; iy--) {
                    rtb_TmpSignalConversionAtTrackSimPathInport1
                        [static_cast<int32_T>(iy - 1)] -=
                        rtb_TmpSignalConversionAtTrackSimPathInport1[
                        static_cast<int32_T>(iy - 2)] * -rtb_UpperBound;
                }

                a[j] = 0.0;
                a[j] += 0.0 * localDW->Integrator[0];
                a[j] += static_cast<real_T>(a_0[static_cast<int32_T>(j + 3)]) *
                    localDW->Integrator[1];
                a[j] += static_cast<real_T>(a_0[static_cast<int32_T>(j + 6)]) *
                    localDW->Integrator[2];
            }

            localDW->estimatedExtendedStateDerivative[0] = (0.0 *
                localDW->Product + a[0]) +
                rtb_TmpSignalConversionAtTrackSimPathInport1[1] * rtb_Switch;
            localDW->estimatedExtendedStateDerivative[1] = (-usedInputGain *
                localDW->Product + a[1]) +
                rtb_TmpSignalConversionAtTrackSimPathInport1[2] * rtb_Switch;
            localDW->estimatedExtendedStateDerivative[2] = (0.0 *
                localDW->Product + a[2]) +
                rtb_TmpSignalConversionAtTrackSimPathInport1[3] * rtb_Switch;

            // End of MATLAB Function: '<S124>/Linear extended state observer'
        }

        // End of Outputs for SubSystem: '<S118>/ADRC'

        // SignalConversion generated from: '<S118>/Vector Concatenate' incorporates:
        //   DataStoreWrite: '<S118>/WriteADRC_Log'

        localDW->ADRC_Log[0] = localDW->Integrator[0];
        localDW->ADRC_Log[1] = localDW->Integrator[1];
        localDW->ADRC_Log[2] = localDW->Integrator[2];
        if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
            // Outputs for Enabled SubSystem: '<S118>/PID' incorporates:
            //   EnablePort: '<S122>/Enable'

            if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
                if (localDW->EnablePID) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(localDW->PID_MODE) ^ 1))) {
                        // InitializeConditions for Delay: '<S161>/UD'
                        localDW->UD_DSTATE = 0.0;

                        // InitializeConditions for DiscreteIntegrator: '<S168>/Integrator' 
                        localDW->Integrator_DSTATE = 0.0;
                        localDW->PID_MODE = true;
                    }
                } else {
                    localDW->PID_MODE = false;
                }
            }

            if (localDW->PID_MODE) {
                // Product: '<S160>/DProd Out'
                K_idx_0 = Gain * *rtu_ParamADRC_D;

                // SampleTimeMath: '<S163>/Tsamp'
                //
                //  About '<S163>/Tsamp':
                //   y = u * K where K = 1 / ( w * Ts )

                localDW->Tsamp = K_idx_0 * 10.0;

                // Product: '<S165>/IProd Out'
                localDW->IProdOut = Gain * *rtu_ParamADRC_I;

                // Product: '<S173>/PProd Out'
                usedInputGain = Gain * *rtu_ParamADRC_P;

                // Sum: '<S177>/Sum' incorporates:
                //   Delay: '<S161>/UD'
                //   DiscreteIntegrator: '<S168>/Integrator'
                //   Sum: '<S161>/Diff'

                localDW->Sum = (usedInputGain + localDW->Integrator_DSTATE) +
                    (localDW->Tsamp - localDW->UD_DSTATE);
            }

            // End of Outputs for SubSystem: '<S118>/PID'
        }

        // Switch: '<S118>/Switch'
        if (localDW->PID_U) {
            // Switch: '<S118>/Switch'
            localDW->Switch_p = localDW->Sum;
        } else {
            // Switch: '<S118>/Switch'
            localDW->Switch_p = localDW->Product;
        }

        // End of Switch: '<S118>/Switch'

        // SignalConversion generated from: '<S118>/Vector Concatenate' incorporates:
        //   DataStoreWrite: '<S118>/WriteADRC_Log'

        localDW->ADRC_Log[3] = localDW->Switch_p;
    }

    // End of Outputs for SubSystem: '<S99>/SpdFBControl'

    // Sum: '<S99>/SumSpd'
    usedInputGain = localDW->Switch_p + rtu_SimUAVState->AirSpeed;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // MinMax: '<S99>/Min'
        localDW->Min = std::fmin(localDW->SpeedLimit[0], localDW->SpeedLimit[1]);

        // Selector: '<S99>/FrontBound' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'

        localDW->FrontBound[0] = localDW->MatrixConcatenate[108];
        localDW->FrontBound[1] = localDW->MatrixConcatenate[325];
        localDW->FrontBound[2] = localDW->MatrixConcatenate[542];
    }

    // Switch: '<S117>/Switch2' incorporates:
    //   DataStoreWrite: '<S99>/WriteRefGndSpd'
    //   RelationalOperator: '<S117>/LowerRelop1'
    //   RelationalOperator: '<S117>/UpperRelop'
    //   Switch: '<S117>/Switch'

    if (usedInputGain > localDW->Max) {
        localDW->RefGndSpd = localDW->Max;
    } else if (usedInputGain < localDW->Min) {
        // Switch: '<S117>/Switch' incorporates:
        //   DataStoreWrite: '<S99>/WriteRefGndSpd'

        localDW->RefGndSpd = localDW->Min;
    } else {
        localDW->RefGndSpd = usedInputGain;
    }

    // End of Switch: '<S117>/Switch2'

    // Sum: '<S111>/Sum' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   Selector: '<S99>/FrontBound'

    rtb_Heading[0] = localDW->FrontBound[0] - rtu_SimUAVState->North;
    rtb_Heading[1] = localDW->FrontBound[1] - rtu_SimUAVState->East;
    rtb_Heading[2] = localDW->FrontBound[2] - rtu_SimUAVState->Height;

    // Sqrt: '<S111>/sqrt' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   DotProduct: '<S111>/Dot Product'

    rtb_EngagedFlag = std::sqrt((rtb_Heading[0] * rtb_Heading[0] + rtb_Heading[1]
        * rtb_Heading[1]) + rtb_Heading[2] * rtb_Heading[2]);

    // Sum: '<S99>/ActRngmMinRng'
    rtb_Gain_p -= rtb_EngagedFlag;

    // Sum: '<S99>/RefRngmMinRng'
    rtb_RefRngmMinRng = rtb_LagDistance - rtb_EngagedFlag;

    // Sum: '<S99>/ComputeLB'
    Gain = rtb_EngagedFlag - rtb_LagDistance;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Selector: '<S99>/TailBound' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'

        localDW->TailBound[0] = localDW->MatrixConcatenate[12];
        localDW->TailBound[1] = localDW->MatrixConcatenate[229];
        localDW->TailBound[2] = localDW->MatrixConcatenate[446];
    }

    // Sum: '<S112>/Sum' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   Selector: '<S99>/TailBound'

    rtb_Heading[0] = localDW->TailBound[0] - rtu_SimUAVState->North;
    rtb_Heading[1] = localDW->TailBound[1] - rtu_SimUAVState->East;
    rtb_Heading[2] = localDW->TailBound[2] - rtu_SimUAVState->Height;

    // Sum: '<S99>/ComputeUB' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   DotProduct: '<S112>/Dot Product'
    //   Sqrt: '<S112>/sqrt'

    rtb_UpperBound = std::sqrt((rtb_Heading[0] * rtb_Heading[0] + rtb_Heading[1]
        * rtb_Heading[1]) + rtb_Heading[2] * rtb_Heading[2]) - rtb_LagDistance;

    // Outputs for Enabled SubSystem: '<S99>/EnableBias' incorporates:
    //   EnablePort: '<S110>/Enable'

    // Math: '<S99>/Square' incorporates:
    //   Math: '<S110>/Square'

    K_idx_0 = rtb_RefRngmMinRng * rtb_RefRngmMinRng;

    // End of Outputs for SubSystem: '<S99>/EnableBias'

    // Product: '<S99>/DivideLB' incorporates:
    //   Bias: '<S99>/Bias'
    //   Math: '<S99>/Square'

    rtb_EngagedFlag = K_idx_0 / (rtb_RefRngmMinRng + 10.0);

    // Switch: '<S99>/Switch' incorporates:
    //   RelationalOperator: '<S99>/GreaterThanOrEqual'

    if (rtb_Gain_p >= rtb_EngagedFlag) {
        // Switch: '<S99>/Switch'
        rtb_Switch_l = rtb_Gain_p;
    } else {
        // Switch: '<S99>/Switch'
        rtb_Switch_l = rtb_EngagedFlag;
    }

    // End of Switch: '<S99>/Switch'

    // Outputs for Enabled SubSystem: '<S99>/EnableBias' incorporates:
    //   EnablePort: '<S110>/Enable'

    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
            localDW->EnableBias_MODE = (rtb_Switch_l > 0.0);
        }

        // Selector: '<S99>/L1FrontBound' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'

        localDW->L1FrontBound[0] = localDW->MatrixConcatenate[78];
        localDW->L1FrontBound[1] = localDW->MatrixConcatenate[295];
        localDW->L1FrontBound[2] = localDW->MatrixConcatenate[512];
    }

    if (localDW->EnableBias_MODE) {
        // Sum: '<S110>/biasHm70' incorporates:
        //   Product: '<S110>/Divide'

        localDW->biasHm70 = K_idx_0 / rtb_Switch_l - rtb_RefRngmMinRng;
    }

    // End of Outputs for SubSystem: '<S99>/EnableBias'

    // Sum: '<S113>/Sum' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   Selector: '<S99>/L1FrontBound'

    rtb_Heading[0] = localDW->L1FrontBound[0] - rtu_SimUAVState->North;
    rtb_Heading[1] = localDW->L1FrontBound[1] - rtu_SimUAVState->East;
    rtb_Heading[2] = localDW->L1FrontBound[2] - rtu_SimUAVState->Height;

    // Sum: '<S99>/L1ComputeLB' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   DotProduct: '<S113>/Dot Product'
    //   Sqrt: '<S113>/sqrt'

    rtb_EngagedFlag = std::sqrt((rtb_Heading[0] * rtb_Heading[0] + rtb_Heading[1]
        * rtb_Heading[1]) + rtb_Heading[2] * rtb_Heading[2]) - rtb_LagDistance;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Selector: '<S99>/L1TailBound' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'

        localDW->L1TailBound[0] = localDW->MatrixConcatenate[42];
        localDW->L1TailBound[1] = localDW->MatrixConcatenate[259];
        localDW->L1TailBound[2] = localDW->MatrixConcatenate[476];
    }

    // Sum: '<S114>/Sum' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   Selector: '<S99>/L1TailBound'

    rtb_Heading[0] = localDW->L1TailBound[0] - rtu_SimUAVState->North;
    rtb_Heading[1] = localDW->L1TailBound[1] - rtu_SimUAVState->East;
    rtb_Heading[2] = localDW->L1TailBound[2] - rtu_SimUAVState->Height;

    // Sum: '<S99>/L1ComputeUB' incorporates:
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   DotProduct: '<S114>/Dot Product'
    //   Sqrt: '<S114>/sqrt'

    rtb_RefRngmMinRng = std::sqrt((rtb_Heading[0] * rtb_Heading[0] +
        rtb_Heading[1] * rtb_Heading[1]) + rtb_Heading[2] * rtb_Heading[2]) -
        rtb_LagDistance;

    // End of Outputs for SubSystem: '<S9>/SpeedControl'

    // Outputs for Atomic SubSystem: '<S9>/HeadingLogic'
    // Outputs for Atomic SubSystem: '<S95>/NewMissionHdg'
    // Outputs for Atomic SubSystem: '<S9>/MaxBrake'
    // Product: '<S97>/BrkRng' incorporates:
    //   Constant: '<S97>/SampleTime'
    //   Gain: '<S103>/Ts'

    K_idx_0 = rtu_SimUAVState->AirSpeed * 0.1;

    // End of Outputs for SubSystem: '<S95>/NewMissionHdg'
    // End of Outputs for SubSystem: '<S9>/HeadingLogic'

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   Constant: '<S97>/TrackDP'
    //   Product: '<S97>/BrkRng'

    rtb_LagDistance = K_idx_0 * 132.0;

    // Sum: '<S107>/Sum'
    rtb_Heading[2] = rtu_SimUAVState->Height - localDW->OverwriteHeight;

    // Sum: '<S97>/Minus' incorporates:
    //   DotProduct: '<S107>/Dot Product'
    //   Sqrt: '<S107>/sqrt'

    rtb_Gain_p = std::sqrt(rtb_Heading[2] * rtb_Heading[2] + rtb_Sum1_idx_0) -
        rtb_LagDistance;

    // Switch: '<S97>/BrkSwitch' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
    //   Constant: '<S97>/MaxBrake'
    //   Sum: '<S99>/Sum'
    //   Sum: '<S9>/Minus'

    if (rtb_Gain_p >= 0.0) {
        // Outputs for Atomic SubSystem: '<S9>/SpeedControl'
        usedInputGain += rtu_FlightState->AirSpeed_mps -
            rtu_FlightState->GndSpd_mps;

        // End of Outputs for SubSystem: '<S9>/SpeedControl'
    } else {
        usedInputGain = 0.0;
    }

    // End of Switch: '<S97>/BrkSwitch'

    // Gain: '<S97>/Gain'
    rtb_Gain_p = -rtb_Gain_p;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // MATLAB Function: '<S97>/getSpeedLimit'
        // MATLAB Function 'Real2SimNav/MaxBrake/getSpeedLimit': '<S109>:1'
        // '<S109>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->SingletonInstance_not_empty_c) ^ 1))) {
            localDW->SingletonInstance.AirSpeed = 35.0;
            localDW->SingletonInstance.MaxRollAngle = 0.3490658503988659;
            localDW->SingletonInstance.FlightPathAngleLimit[0] = -0.175;
            localDW->SingletonInstance.FlightPathAngleLimit[1] = 0.175;
            localDW->SingletonInstance.SpdLmt[0] = 29.0;
            localDW->SingletonInstance.SpdLmt[1] = 46.0;
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Sum1_idx_1 = Real2SimGuidance_fileManager_p(localDW);
            if (rtb_Sum1_idx_1 < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j(rtb_Sum1_idx_1, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_a(rtb_Sum1_idx_1, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_l, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_m, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_9, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_9->size[0] * data_9->size[1]);
                    data_9->size[0] = 1;
                    data_9->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_9, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_9->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_9, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_m);
                    Real2SimGuidance_strtrim_o(tmp_m, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    i2 = 0;
                                    i1 = 0;
                                } else {
                                    i2 = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - i2);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(i2 + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_l);
                                Real2SimGuidance_strtrim_o(tmp_l, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bg(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_9);
                Real2SimGuidance_emxFree_char_T_o(&tmp_m);
                Real2SimGuidance_emxFree_char_T_o(&tmp_l);
            }

            inputArg_data = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV NormAirSpeed:\t\t%f\n", inputArg_data.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            b_fid = Real2SimGuidance_fileManager_p(localDW);
            if (b_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j(b_fid, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_a(b_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_j, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_k, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_8, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_8->size[0] * data_8->size[1]);
                    data_8->size[0] = 1;
                    data_8->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_8, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_8->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_8, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_k);
                    Real2SimGuidance_strtrim_o(tmp_k, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_j);
                                Real2SimGuidance_strtrim_o(tmp_j, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bgl(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_8);
                Real2SimGuidance_emxFree_char_T_o(&tmp_k);
                Real2SimGuidance_emxFree_char_T_o(&tmp_j);
            }

            tmp_1 = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_1.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Switch = Real2SimGuidance_fileManager_p(localDW);
            if (rtb_Switch < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j(rtb_Switch, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_a(rtb_Switch, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_h, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_i, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_7, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_7->size[0] * data_7->size[1]);
                    data_7->size[0] = 1;
                    data_7->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_7, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_7->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_7, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_i);
                    Real2SimGuidance_strtrim_o(tmp_i, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_h);
                                Real2SimGuidance_strtrim_o(tmp_h, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bglv(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_7);
                Real2SimGuidance_emxFree_char_T_o(&tmp_i);
                Real2SimGuidance_emxFree_char_T_o(&tmp_h);
            }

            tmp_2 = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_2.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            d_fid = Real2SimGuidance_fileManager_p(localDW);
            if (d_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_j(d_fid, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_a(d_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_f, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_g, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_6, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_6->size[0] * data_6->size[1]);
                    data_6->size[0] = 1;
                    data_6->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_6, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_6->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_6, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_g);
                    Real2SimGuidance_strtrim_o(tmp_g, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_f);
                                Real2SimGuidance_strtrim_o(tmp_f, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bglv3(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_6);
                Real2SimGuidance_emxFree_char_T_o(&tmp_g);
                Real2SimGuidance_emxFree_char_T_o(&tmp_f);
            }

            tmp_3 = Real2SimGuidance_str2double_k(ret);
            d_fid = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV MaxRollAngle:\t\t%f\n", d_fid);
            fflush(stdout);
            Real2SimGuidance_readINI_e(ret, localDW);
            tmp_3 = Real2SimGuidance_str2double_k(ret);
            rtb_Sum1_idx_1 = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV ClimbAngleLimit:\t%f\n", rtb_Sum1_idx_1);
            fflush(stdout);
            Real2SimGuidance_readINI_ew(ret, localDW);
            tmp_3 = Real2SimGuidance_str2double_k(ret);
            b_fid = 0.017453292519943295 * tmp_3.re;
            printf("Set UAV DiveAngleLimit:\t\t%f\n", b_fid);
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
                    (std::isnan(rtb_Sum1_idx_1)) ^ 1))) &&
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isnan(b_fid)) ^ 1)))) {
                localDW->SingletonInstance.FlightPathAngleLimit[0] = b_fid;
                localDW->SingletonInstance.FlightPathAngleLimit[1] =
                    rtb_Sum1_idx_1;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(tmp_1.re)) ^ 1))) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan
                    (tmp_2.re)) ^ 1)))) {
                localDW->SingletonInstance.SpdLmt[0] = tmp_2.re;
                localDW->SingletonInstance.SpdLmt[1] = tmp_1.re;
            }

            Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
                (&localDW->SingletonInstance.Connector,
                 localDW->SingletonInstance.AirSpeed,
                 localDW->SingletonInstance.MaxRollAngle);
            localDW->SingletonInstance_not_empty_c = true;
        }

        rtb_Sum1_idx_0 = localDW->SingletonInstance.SpdLmt[0];
        rtb_Sum1_idx_1 = localDW->SingletonInstance.SpdLmt[1];

        // End of MATLAB Function: '<S97>/getSpeedLimit'

        // MinMax: '<S97>/Max'
        localDW->Max_g = std::fmax(rtb_Sum1_idx_0, rtb_Sum1_idx_1);

        // MinMax: '<S97>/Min'
        localDW->Min_a = std::fmin(rtb_Sum1_idx_0, rtb_Sum1_idx_1);
    }

    // Switch: '<S108>/Switch2' incorporates:
    //   RelationalOperator: '<S108>/LowerRelop1'
    //   RelationalOperator: '<S108>/UpperRelop'
    //   Switch: '<S108>/Switch'

    if (usedInputGain > localDW->Max_g) {
        usedInputGain = localDW->Max_g;
    } else if (usedInputGain < localDW->Min_a) {
        // Switch: '<S108>/Switch'
        usedInputGain = localDW->Min_a;
    }

    // End of Switch: '<S108>/Switch2'
    // End of Outputs for SubSystem: '<S9>/MaxBrake'

    // Outputs for Atomic SubSystem: '<S9>/HeadingLogic'
    // SignalConversion generated from: '<S95>/TrackSimPath' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'

    rtb_TmpSignalConversionAtTrackSimPathInport1[0] = rtb_biasH;
    rtb_TmpSignalConversionAtTrackSimPathInport1[1] = rtb_Abs1;
    rtb_TmpSignalConversionAtTrackSimPathInport1[2] = localDW->OverwriteHeight;
    rtb_TmpSignalConversionAtTrackSimPathInport1[3] = rtb_Switch_b;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // SampleTimeMath: '<S95>/LookaheadT'
        //
        //  About '<S95>/LookaheadT':
        //   y = u * K where K = ( w * Ts )

        localDW->LookaheadT = rtu_SimUAVState->AirSpeed * 3.6;
    }

    // MATLABSystem: '<S95>/TrackSimPath' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
    //   Concatenate: '<S94>/Matrix Concatenate'
    //   SignalConversion generated from: '<S95>/TrackSimPath'

    rtb_Sum1_idx_1 = localDW->LookaheadT;
    localDW->obj.LookaheadDistFlag = 0U;
    if (localDW->LookaheadT < 10.0) {
        rtb_Sum1_idx_1 = 10.0;
        localDW->obj.LookaheadDistFlag = 1U;
    }

    localDW->obj.InitialPose[0] = 0.0;
    localDW->obj.InitialPose[1] = 0.0;
    localDW->obj.InitialPose[2] = 0.0;
    localDW->obj.InitialPose[3] = 0.0;
    localDW->obj.NumWaypoints = 217.0;
    guard1 = false;
    if (localDW->obj.NumWaypoints != 217.0) {
        guard1 = true;
    } else {
        if (localDW->obj.NumWaypoints < 1.0) {
            i2 = 0;
        } else {
            i2 = static_cast<int32_T>(localDW->obj.NumWaypoints);
        }

        if (localDW->obj.NumWaypoints < 1.0) {
            iy = 0;
        } else {
            iy = static_cast<int32_T>(localDW->obj.NumWaypoints);
        }

        rtb_HdgStatus = false;
        rtb_AvoidDanger = false;
        if (i2 == iy) {
            rtb_AvoidDanger = true;
        }

        if (rtb_AvoidDanger && (i2 != 0) && (iy != 0)) {
            j = 0;
            exitg1 = false;
            while ((!exitg1) && (j <= static_cast<int32_T>(static_cast<int32_T>
                     (iy * 3) - 1))) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((localDW->obj.WaypointsInternal[
                        static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(j / i2) * 217) + j % i2)] ==
                        localDW->MatrixConcatenate[static_cast<int32_T>(
                        static_cast<int32_T>(static_cast<int32_T>(j / iy) * 217)
                        + j % iy)]) ^ 1))) {
                    rtb_AvoidDanger = false;
                    exitg1 = true;
                } else {
                    j = static_cast<int32_T>(j + 1);
                }
            }
        }

        if (rtb_AvoidDanger) {
            rtb_HdgStatus = true;
        }

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rtb_HdgStatus) ^ 1))) {
            guard1 = true;
        }
    }

    if (guard1) {
        std::memcpy(&localDW->obj.WaypointsInternal[0],
                    &localDW->MatrixConcatenate[0], static_cast<uint32_T>(651U *
                     sizeof(real_T)));
        localDW->obj.WaypointIndex = 1.0;
        localDW->obj.SearchFlag = true;
    }

    for (i = 0; i < 217; i++) {
        distinctWptsIdx[i] = true;
    }

    for (j = 0; j < 216; j++) {
        i = 0;
        i2 = 0;
        for (iy = 0; iy < 3; iy++) {
            i1 = static_cast<int32_T>(i2 + j);
            x[static_cast<int32_T>(i + j)] = (localDW->MatrixConcatenate[
                static_cast<int32_T>(i1 + 1)] != localDW->MatrixConcatenate[i1]);
            i = static_cast<int32_T>(i + 216);
            i2 = static_cast<int32_T>(i2 + 217);
        }
    }

    i1 = 0;
    i2 = 432;
    for (j = 0; j < 216; j++) {
        y[j] = false;
        i1 = static_cast<int32_T>(i1 + 1);
        i2 = static_cast<int32_T>(i2 + 1);
        coffset = i1;
        exitg1 = false;
        while ((!exitg1) && (coffset <= i2)) {
            if (x[static_cast<int32_T>(coffset - 1)]) {
                y[j] = true;
                exitg1 = true;
            } else {
                coffset = static_cast<int32_T>(coffset + 216);
            }
        }

        distinctWptsIdx[j] = y[j];
    }

    j = 0;
    for (iy = 0; iy < 217; iy++) {
        if (distinctWptsIdx[iy]) {
            j = static_cast<int32_T>(j + 1);
        }
    }

    iy = j;
    j = 0;
    for (i2 = 0; i2 < 217; i2++) {
        if (distinctWptsIdx[i2]) {
            b_data[j] = static_cast<uint8_T>(static_cast<int32_T>(i2 + 1));
            j = static_cast<int32_T>(j + 1);
        }
    }

    for (i = 0; i < 3; i++) {
        for (i2 = 0; i2 <= static_cast<int32_T>(iy - 1); i2++) {
            localDW->b_waypointsIn_data[static_cast<int32_T>(i2 +
                static_cast<int32_T>(iy * i))] = localDW->MatrixConcatenate[
                static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
                (217 * i) + static_cast<int32_T>(b_data[i2])) - 1)];
        }
    }

    localDW->obj.LookaheadDistance = rtb_Sum1_idx_1;
    if (iy == 0) {
        localDW->SwitchLookAheadNED[0] = rtb_Sum1_idx_1 * std::cos(rtb_Switch_b)
            + rtb_biasH;
        localDW->SwitchLookAheadNED[1] = rtb_Sum1_idx_1 * std::sin(rtb_Switch_b)
            + rtb_Abs1;
        localDW->SwitchLookAheadNED[2] = rtb_Sum1_idx_1 * 0.0 +
            localDW->OverwriteHeight;
        rtb_Sum1_idx_1 = rtb_Switch_b;
        rtb_Switch = rtb_Switch_b;

        // DataStoreWrite: '<S95>/WriteCrossTrackError' incorporates:
        //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
        //   SignalConversion generated from: '<S95>/TrackSimPath'

        localDW->CrossTrackError = 0.0;
        status = 1U;
    } else {
        guard1 = false;
        if (iy == 1) {
            if (localDW->obj.StartFlag) {
                localDW->obj.InitialPose[0] = rtb_biasH;
                localDW->obj.InitialPose[1] = rtb_Abs1;
                localDW->obj.InitialPose[2] = localDW->OverwriteHeight;
                localDW->obj.InitialPose[3] = rtb_Switch_b;
            }

            a[0] = localDW->b_waypointsIn_data[0] - rtb_biasH;
            a[1] = localDW->b_waypointsIn_data[1] - rtb_Abs1;
            a[2] = localDW->b_waypointsIn_data[2] - localDW->OverwriteHeight;
            if (Real2SimGuidance_norm(a) < 1.4901161193847656E-8) {
                localDW->SwitchLookAheadNED[0] = rtb_Sum1_idx_1 * std::cos
                    (rtb_Switch_b) + rtb_biasH;
                localDW->SwitchLookAheadNED[1] = rtb_Sum1_idx_1 * std::sin
                    (rtb_Switch_b) + rtb_Abs1;
                localDW->SwitchLookAheadNED[2] = rtb_Sum1_idx_1 * 0.0 +
                    localDW->OverwriteHeight;
                rtb_Sum1_idx_1 = rtb_Switch_b;
                rtb_Switch = rtb_Switch_b;

                // DataStoreWrite: '<S95>/WriteCrossTrackError' incorporates:
                //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
                //   SignalConversion generated from: '<S95>/TrackSimPath'

                localDW->CrossTrackError = 0.0;
                status = 1U;
                localDW->obj.StartFlag = false;
            } else {
                localDW->obj.StartFlag = false;
                localDW->obj.NumWaypoints = 2.0;
                waypoints_size[0] = static_cast<int32_T>(iy + 1);
                waypoints_size[1] = 3;
                for (i = 0; i < 3; i++) {
                    j = static_cast<int32_T>(static_cast<int32_T>(iy + 1) * i);
                    localDW->waypoints_data[j] = localDW->obj.InitialPose[i];
                    for (i2 = 0; i2 <= static_cast<int32_T>(iy - 1); i2++) {
                        localDW->waypoints_data[static_cast<int32_T>(
                            static_cast<int32_T>(i2 + j) + 1)] =
                            localDW->b_waypointsIn_data[static_cast<int32_T>(
                            static_cast<int32_T>(iy * i) + i2)];
                    }
                }

                guard1 = true;
            }
        } else {
            waypoints_size[0] = iy;
            waypoints_size[1] = 3;
            coffset = static_cast<int32_T>(iy * 3);
            for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                localDW->waypoints_data[i] = localDW->b_waypointsIn_data[i];
            }

            guard1 = true;
        }

        if (guard1) {
            real_T a_tmp;
            real_T rtb_Heading_tmp;
            real_T rtb_TmpSignalConversionAtTrackS_tmp;
            boolean_T guard2{ false };

            if (localDW->obj.SearchFlag) {
                Real2SimGuidance_WaypointFollowerBase_searchClosestPath
                    (&localDW->obj, localDW->waypoints_data, waypoints_size,
                     rtb_TmpSignalConversionAtTrackSimPathInport1);
            }

            rtb_HdgStatus = false;
            if (localDW->obj.WaypointIndex == localDW->obj.NumWaypoints) {
                rtb_HdgStatus = true;
            }

            if (rtb_HdgStatus) {
                localDW->obj.LastWaypointFlag = true;
                localDW->obj.WaypointIndex--;
            }

            a[0] = rtb_biasH - localDW->waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0) - 1)];
            a[1] = rtb_Abs1 - localDW->waypoints_data[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int32_T>
                (localDW->obj.WaypointIndex + 1.0) + waypoints_size[0]) - 1)];
            a[2] = localDW->OverwriteHeight - localDW->waypoints_data[
                static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->obj.WaypointIndex + 1.0) + static_cast<int32_T>
                (waypoints_size[0] << 1)) - 1)];
            guard2 = false;
            if (Real2SimGuidance_norm(a) <= 1.0) {
                guard2 = true;
            } else {
                rtb_Sum1_idx_0 = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0) - 1)];
                rtb_Heading[0] = rtb_biasH - rtb_Sum1_idx_0;
                a[0] = rtb_Sum1_idx_0 - localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex) - 1)];
                rtb_Sum1_idx_0 = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex + 1.0) + waypoints_size[0]) - 1)];
                rtb_Heading[1] = rtb_Abs1 - rtb_Sum1_idx_0;
                a[1] = rtb_Sum1_idx_0 - localDW->waypoints_data
                    [static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(localDW->obj.WaypointIndex) +
                     waypoints_size[0]) - 1)];
                rtb_Heading_tmp = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex + 1.0) + static_cast<int32_T>
                    (waypoints_size[0] << 1)) - 1)];
                rtb_Heading[2] = localDW->OverwriteHeight - rtb_Heading_tmp;
                a_tmp = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(waypoints_size[0] <<
                    1) + static_cast<int32_T>(localDW->obj.WaypointIndex)) - 1)];
                a[2] = rtb_Heading_tmp - a_tmp;
                rtb_Sum1_idx_0 = Real2SimGuidance_norm(a);
                rtb_Switch = Real2SimGuidance_norm(rtb_Heading);
                rtb_Sum1_idx_1 = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(localDW->obj.WaypointIndex) - 1)];
                b_fid = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(localDW->obj.WaypointIndex + 1.0) - 1)];
                d_fid = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex) + waypoints_size[0]) - 1)];
                ct_idx_0 = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex + 1.0) + waypoints_size[0]) - 1)];
                rtb_Sum1_idx_0 = ((b_fid - rtb_Sum1_idx_1) / rtb_Sum1_idx_0 *
                                  (rtb_Heading[0] / rtb_Switch) + (ct_idx_0 -
                                   d_fid) / rtb_Sum1_idx_0 * (rtb_Heading[1] /
                                   rtb_Switch)) + (rtb_Heading_tmp - a_tmp) /
                    rtb_Sum1_idx_0 * (rtb_Heading[2] / rtb_Switch);
                if (std::isnan(rtb_Sum1_idx_0)) {
                    rtb_Sum1_idx_0 = (rtNaN);
                } else if (rtb_Sum1_idx_0 < 0.0) {
                    rtb_Sum1_idx_0 = -1.0;
                } else {
                    rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Sum1_idx_0 > 0.0);
                }

                if (rtb_Sum1_idx_0 >= 0.0) {
                    guard2 = true;
                } else {
                    rtb_Heading[0] = rtb_Sum1_idx_1;
                    localDW->SwitchLookAheadNED[0] = b_fid;
                    rtb_Heading[1] = d_fid;
                    localDW->SwitchLookAheadNED[1] = ct_idx_0;
                    rtb_Heading[2] = a_tmp;
                    localDW->SwitchLookAheadNED[2] = rtb_Heading_tmp;
                }
            }

            if (guard2) {
                localDW->obj.WaypointIndex++;
                rtb_HdgStatus = false;
                if (localDW->obj.WaypointIndex == localDW->obj.NumWaypoints) {
                    rtb_HdgStatus = true;
                }

                if (rtb_HdgStatus) {
                    localDW->obj.LastWaypointFlag = true;
                    localDW->obj.WaypointIndex--;
                }

                rtb_Heading[0] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(localDW->obj.WaypointIndex) - 1)];
                localDW->SwitchLookAheadNED[0] = localDW->waypoints_data[
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex + 1.0) - 1)];
                rtb_Heading[1] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>
                    (localDW->obj.WaypointIndex) + waypoints_size[0]) - 1)];
                localDW->SwitchLookAheadNED[1] = localDW->waypoints_data[
                    static_cast<int32_T>(static_cast<int32_T>(static_cast<
                    int32_T>(localDW->obj.WaypointIndex + 1.0) + waypoints_size
                    [0]) - 1)];
                rtb_Heading[2] = localDW->waypoints_data[static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<int32_T>(waypoints_size[0] <<
                    1) + static_cast<int32_T>(localDW->obj.WaypointIndex)) - 1)];
                localDW->SwitchLookAheadNED[2] = localDW->waypoints_data[
                    static_cast<int32_T>(static_cast<int32_T>(static_cast<
                    int32_T>(localDW->obj.WaypointIndex + 1.0) +
                    static_cast<int32_T>(waypoints_size[0] << 1)) - 1)];
            }

            d_fid = localDW->SwitchLookAheadNED[0] - rtb_Heading[0];
            ct_idx_0 = rtb_biasH - rtb_Heading[0];
            rtb_Heading_tmp = localDW->SwitchLookAheadNED[1] - rtb_Heading[1];
            rtb_TmpSignalConversionAtTrackS_tmp = rtb_Abs1 - rtb_Heading[1];
            a_tmp = localDW->SwitchLookAheadNED[2] - rtb_Heading[2];
            rtb_Sum1_idx_0 = localDW->OverwriteHeight - rtb_Heading[2];
            rtb_Sum1_idx_1 = ((rtb_TmpSignalConversionAtTrackS_tmp *
                               rtb_Heading_tmp + ct_idx_0 * d_fid) +
                              rtb_Sum1_idx_0 * a_tmp) / ((rtb_Heading_tmp *
                rtb_Heading_tmp + d_fid * d_fid) + a_tmp * a_tmp);
            if (rtb_Sum1_idx_1 < 0.0) {
                a[0] = ct_idx_0;
                a[1] = rtb_TmpSignalConversionAtTrackS_tmp;
                a[2] = rtb_Sum1_idx_0;
                b_fid = Real2SimGuidance_norm(a);
            } else if (rtb_Sum1_idx_1 > 1.0) {
                a[0] = rtb_biasH - localDW->SwitchLookAheadNED[0];
                a[1] = rtb_Abs1 - localDW->SwitchLookAheadNED[1];
                a[2] = localDW->OverwriteHeight - localDW->SwitchLookAheadNED[2];
                b_fid = Real2SimGuidance_norm(a);
            } else {
                a[0] = rtb_biasH - (rtb_Sum1_idx_1 * d_fid + rtb_Heading[0]);
                a[1] = rtb_Abs1 - (rtb_Sum1_idx_1 * rtb_Heading_tmp +
                                   rtb_Heading[1]);
                a[2] = localDW->OverwriteHeight - (rtb_Sum1_idx_1 * a_tmp +
                    rtb_Heading[2]);
                b_fid = Real2SimGuidance_norm(a);
            }

            if (localDW->obj.LastWaypointFlag) {
                b_fid = localDW->SwitchLookAheadNED[0] - rtb_Heading[0];
                rtb_Sum1_idx_1 = localDW->SwitchLookAheadNED[2] - rtb_Heading[2];
                rtb_Sum1_idx_1 = ((ct_idx_0 * b_fid +
                                   rtb_TmpSignalConversionAtTrackS_tmp *
                                   rtb_Heading_tmp) + rtb_Sum1_idx_0 *
                                  rtb_Sum1_idx_1) / ((b_fid * b_fid +
                    rtb_Heading_tmp * rtb_Heading_tmp) + rtb_Sum1_idx_1 *
                    rtb_Sum1_idx_1);
                a[0] = rtb_biasH - (rtb_Sum1_idx_1 * d_fid + rtb_Heading[0]);
                a[1] = rtb_Abs1 - (rtb_Sum1_idx_1 * rtb_Heading_tmp +
                                   rtb_Heading[1]);
                a[2] = localDW->OverwriteHeight - (rtb_Sum1_idx_1 * a_tmp +
                    rtb_Heading[2]);
                b_fid = Real2SimGuidance_norm(a);
            }

            rtb_Switch = std::abs(b_fid);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isinf(rtb_Switch)) | static_cast<int32_T>(std::isnan
                    (rtb_Switch))))) {
                rtb_Sum1_idx_1 = (rtNaN);
                rtb_Switch = (rtNaN);
            } else if (rtb_Switch < 4.4501477170144028E-308) {
                rtb_Sum1_idx_1 = 4.94065645841247E-324;
                rtb_Switch = 4.94065645841247E-324;
            } else {
                std::frexp(rtb_Switch, &boffset);
                rtb_Sum1_idx_1 = std::ldexp(1.0, static_cast<int32_T>(boffset -
                    53));
                std::frexp(rtb_Switch, &nblocks);
                rtb_Switch = std::ldexp(1.0, static_cast<int32_T>(nblocks - 53));
            }

            if (localDW->obj.LookaheadDistance <= std::fmax(std::sqrt
                    (rtb_Sum1_idx_1), 5.0 * rtb_Switch) + b_fid) {
                localDW->obj.LookaheadDistance = localDW->obj.LookaheadFactor *
                    b_fid;
            }

            rtb_Sum1_idx_1 = rtb_Heading[0] - rtb_biasH;
            ct_idx_0 = rtb_Heading[1] - rtb_Abs1;
            rtb_Sum1_idx_0 = localDW->SwitchLookAheadNED[1] - rtb_Heading[1];
            rtb_Sum1_idx_0 = ((localDW->SwitchLookAheadNED[0] - rtb_Heading[0]) *
                              (localDW->SwitchLookAheadNED[0] - rtb_Heading[0])
                              + rtb_Sum1_idx_0 * rtb_Sum1_idx_0) +
                (localDW->SwitchLookAheadNED[2] - rtb_Heading[2]) *
                (localDW->SwitchLookAheadNED[2] - rtb_Heading[2]);
            rtb_TmpSignalConversionAtTrackS_tmp = rtb_Heading[2] -
                localDW->OverwriteHeight;
            rtb_Switch = ((d_fid * rtb_Sum1_idx_1 + rtb_Heading_tmp * ct_idx_0)
                          + a_tmp * rtb_TmpSignalConversionAtTrackS_tmp) * 2.0;
            d_fid = std::sqrt(rtb_Switch * rtb_Switch - (((rtb_Sum1_idx_1 *
                                 rtb_Sum1_idx_1 + ct_idx_0 * ct_idx_0) +
                                rtb_TmpSignalConversionAtTrackS_tmp *
                                rtb_TmpSignalConversionAtTrackS_tmp) -
                               localDW->obj.LookaheadDistance *
                               localDW->obj.LookaheadDistance) * (4.0 *
                               rtb_Sum1_idx_0));
            rtb_Sum1_idx_1 = std::fmax((-rtb_Switch + d_fid) / 2.0 /
                rtb_Sum1_idx_0, (-rtb_Switch - d_fid) / 2.0 / rtb_Sum1_idx_0);
            localDW->SwitchLookAheadNED[0] = (1.0 - rtb_Sum1_idx_1) *
                rtb_Heading[0] + rtb_Sum1_idx_1 * localDW->SwitchLookAheadNED[0];
            localDW->SwitchLookAheadNED[1] = (1.0 - rtb_Sum1_idx_1) *
                rtb_Heading[1] + rtb_Sum1_idx_1 * localDW->SwitchLookAheadNED[1];
            localDW->SwitchLookAheadNED[2] = (1.0 - rtb_Sum1_idx_1) *
                rtb_Heading[2] + rtb_Sum1_idx_1 * localDW->SwitchLookAheadNED[2];
            rtb_Sum1_idx_1 = rt_atan2d_snf(localDW->SwitchLookAheadNED[1] -
                rtb_Abs1, localDW->SwitchLookAheadNED[0] - rtb_biasH);
            rtb_Switch = rtb_Sum1_idx_1;
            status = 0U;
            rtb_HdgStatus = false;
            if (localDW->obj.LastWaypointFlag) {
                rtb_HdgStatus = true;
            }

            if (rtb_HdgStatus) {
                status = 1U;
            }

            localDW->obj.LastWaypointFlag = false;

            // DataStoreWrite: '<S95>/WriteCrossTrackError' incorporates:
            //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
            //   SignalConversion generated from: '<S95>/TrackSimPath'

            localDW->CrossTrackError = b_fid;
        }
    }

    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Gain: '<S95>/Gain'
        localDW->Gain_m = 0.5 * localDW->LookaheadT;
    }

    // RelationalOperator: '<S95>/Relational Operator' incorporates:
    //   DataStoreWrite: '<S95>/WriteCrossTrackError'

    RelationalOperator = (localDW->CrossTrackError <= localDW->Gain_m);

    // Outputs for Atomic SubSystem: '<S95>/NewMissionHdg'
    // Outputs for Enabled SubSystem: '<S103>/CalForwardShift' incorporates:
    //   EnablePort: '<S105>/Enable'

    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
            localDW->CalForwardShift_MODE = (rtu_SimUAVState->AirSpeed > 0.0);
        }

        // DiscreteIntegrator: '<S103>/Discrete-Time Integrator'
        if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                (localDW->DiscreteTimeIntegrator_PrevResetState) <= 0) &
                static_cast<int32_T>(*rtu_NewMission)))) {
            localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
        }

        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        }

        // DiscreteIntegrator: '<S103>/Discrete-Time Integrator'
        localDW->DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;
    }

    if (localDW->CalForwardShift_MODE) {
        // Saturate: '<S103>/Saturation'
        if (rtb_Gain_p <= 0.0) {
            rtb_Sum1_idx_0 = 0.0;
        } else {
            rtb_Sum1_idx_0 = rtb_Gain_p;
        }

        // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
        //   Product: '<S105>/Divide'
        //   Saturate: '<S103>/Saturation'

        rtb_LagDistance = rtb_Sum1_idx_0 / rtu_SimUAVState->AirSpeed;

        // Gain: '<S105>/Gain'
        localDW->Gain_b = 10.0 * rtb_LagDistance;
    }

    // End of Outputs for SubSystem: '<S103>/CalForwardShift'

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   Gain: '<S103>/Ts'

    rtb_LagDistance = K_idx_0;

    // RelationalOperator: '<S103>/GreaterThanOrEqual' incorporates:
    //   Constant: '<S103>/PenetrationDepthThreshold'
    //   Product: '<S103>/Product'

    rtb_HdgStatus = (rtb_Gain_p >= 72.0 * rtb_LagDistance);

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   Constant: '<S103>/NewestPoint'
    //   Gain: '<S103>/Gain'
    //   Rounding: '<S103>/Round'
    //   Sum: '<S103>/Minus'

    rtb_LagDistance = (217.0 - localDW->DiscreteTimeIntegrator) + 1.5 *
        localDW->Gain_b;
    rtb_LagDistance = std::round(rtb_LagDistance);

    // MinMax: '<S103>/Min' incorporates:
    //   Constant: '<S103>/NewestPoint'

    d_fid = std::fmin(217.0, rtb_LagDistance);
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Chart: '<S103>/MissionSwitchInitialPersuit'
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
            // Transition: '<S106>:14'
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S106>:12'
            localDW->SimHdg = 1.0;
        } else if (localDW->is_c3_Real2SimGuidance ==
                   Real2SimGuidance_IN_Initial) {
            // During 'Initial': '<S106>:12'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((localDW->temporalCounter_i1 >= 216U) &
                                        (static_cast<int32_T>(rtb_Memory) != 0))))
            {
                // Transition: '<S106>:15'
                localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Normal;

                // Entry Internal 'Normal': '<S106>:13'
                // Transition: '<S106>:53'
                localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                // Entry 'SimPnt': '<S106>:37'
                localDW->SimHdg = 1.0;
            } else {
                localDW->SimHdg = 1.0;
            }

            // During 'Normal': '<S106>:13'
        } else if (*rtu_NewMission) {
            // Transition: '<S106>:16'
            // Exit Internal 'Normal': '<S106>:13'
            // Exit Internal 'Debounce': '<S106>:38'
            localDW->is_Debounce_b = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_Normal = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
            localDW->is_c3_Real2SimGuidance = Real2SimGuidance_IN_Initial;
            localDW->temporalCounter_i1 = 0U;

            // Entry 'Initial': '<S106>:12'
            localDW->SimHdg = 1.0;
        } else {
            switch (localDW->is_Normal) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S106>:38'
                if (localDW->is_Debounce_b == Real2SimGuidance_IN_L1Hdg_d) {
                    // During 'L1Hdg': '<S106>:49'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                            10U) {
                        // Transition: '<S106>:46'
                        localDW->is_Debounce_b =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_Normal = Real2SimGuidance_IN_L1Hdg;

                        // Entry 'L1Hdg': '<S106>:42'
                        localDW->SimHdg = 0.0;
                    } else if (static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(static_cast<boolean_T>(
                                   static_cast<int32_T>(static_cast<int32_T>
                                    (rtb_HdgStatus) ^ 1))) & static_cast<int32_T>
                                 (RelationalOperator)))) {
                        // Transition: '<S106>:50'
                        localDW->is_Debounce_b = Real2SimGuidance_IN_SimPnt_o;
                        localDW->temporalCounter_i2 = 0U;
                    }

                    // During 'SimPnt': '<S106>:44'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2) >=
                           10U) {
                    // Transition: '<S106>:48'
                    localDW->is_Debounce_b = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_Normal = Real2SimGuidance_IN_SimPnt;

                    // Entry 'SimPnt': '<S106>:37'
                    localDW->SimHdg = 1.0;
                } else if (rtb_HdgStatus) {
                    // Transition: '<S106>:51'
                    localDW->is_Debounce_b = Real2SimGuidance_IN_L1Hdg_d;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              case Real2SimGuidance_IN_L1Hdg:
                // During 'L1Hdg': '<S106>:42'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (static_cast<boolean_T>(static_cast<
                        int32_T>(static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &
                                            static_cast<int32_T>
                                            (RelationalOperator)))) {
                    // Transition: '<S106>:45'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce_b = Real2SimGuidance_IN_SimPnt_o;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              default:
                // During 'SimPnt': '<S106>:37'
                if (rtb_HdgStatus) {
                    // Transition: '<S106>:47'
                    localDW->is_Normal = Real2SimGuidance_IN_Debounce;
                    localDW->is_Debounce_b = Real2SimGuidance_IN_L1Hdg_d;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;
            }
        }

        // End of Chart: '<S103>/MissionSwitchInitialPersuit'
    }

    // Logic: '<S103>/OR' incorporates:
    //   DataStoreWrite: '<S95>/WriteStatus_Log'
    //   MATLABSystem: '<S95>/TrackSimPath'

    localDW->HdgStatus_Log = static_cast<boolean_T>(static_cast<int32_T>((
        static_cast<int32_T>(status) != 0) | (localDW->SimHdg != 0.0)));

    // Selector: '<S95>/WayPoint3d3' incorporates:
    //   Concatenate: '<S94>/Matrix Concatenate'
    //   MinMax: '<S103>/Min'
    //   Sum: '<S104>/EastArrow'

    K_idx_0 = localDW->MatrixConcatenate[static_cast<int32_T>
        (static_cast<int32_T>(d_fid) + 216)];

    // End of Outputs for SubSystem: '<S95>/NewMissionHdg'

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
    //   Selector: '<S95>/WayPoint3d3'
    //   Sum: '<S104>/EastArrow'

    rtb_LagDistance = K_idx_0 - rtb_Abs1;

    // Outputs for Atomic SubSystem: '<S95>/NewMissionHdg'
    // Selector: '<S95>/WayPoint3d3' incorporates:
    //   Concatenate: '<S94>/Matrix Concatenate'
    //   Sum: '<S104>/NorthArrow'

    rtb_Sum1_idx_0 = localDW->MatrixConcatenate[static_cast<int32_T>(
        static_cast<int32_T>(d_fid) - 1)];

    // End of Outputs for SubSystem: '<S95>/NewMissionHdg'

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
    //   Selector: '<S95>/WayPoint3d3'
    //   Sum: '<S104>/NorthArrow'
    //   Trigonometry: '<S104>/HdgCmd'

    rtb_LagDistance = rt_atan2d_snf(rtb_LagDistance, rtb_Sum1_idx_0 - rtb_biasH);

    // Switch: '<S95>/SwitchDesiredYaw' incorporates:
    //   DataStoreWrite: '<S95>/WriteStatus_Log'
    //   MATLABSystem: '<S95>/TrackSimPath'
    //   Switch: '<S95>/SwitchLookAheadNED'
    //   Switch: '<S95>/SwitchTargetHDG'

    if (localDW->HdgStatus_Log) {
        b_fid = rtb_LagDistance;

        // Switch: '<S95>/SwitchLookAheadNED' incorporates:
        //   Concatenate: '<S94>/Matrix Concatenate'
        //   MinMax: '<S103>/Min'
        //   Selector: '<S95>/WayPoint3d3'

        localDW->SwitchLookAheadNED[0] = rtb_Sum1_idx_0;
        localDW->SwitchLookAheadNED[1] = K_idx_0;

        // Outputs for Atomic SubSystem: '<S95>/NewMissionHdg'
        localDW->SwitchLookAheadNED[2] = localDW->MatrixConcatenate[static_cast<
            int32_T>(static_cast<int32_T>(d_fid) + 433)];

        // End of Outputs for SubSystem: '<S95>/NewMissionHdg'

        // Switch: '<S95>/SwitchTargetHDG'
        rtb_SwitchTargetHDG = rtb_LagDistance;
    } else {
        b_fid = rtb_Switch;

        // Switch: '<S95>/SwitchTargetHDG' incorporates:
        //   MATLABSystem: '<S95>/TrackSimPath'

        rtb_SwitchTargetHDG = rtb_Sum1_idx_1;
    }

    // End of Switch: '<S95>/SwitchDesiredYaw'
    // End of Outputs for SubSystem: '<S9>/HeadingLogic'

    // MATLAB Function: '<S9>/AngDiff'
    Real2SimGuidance_AngDiff(rtb_Switch_b, rtb_SwitchTargetHDG, &rtb_LagDistance);

    // MATLAB Function: '<S9>/wrap2PiRealHdg'
    Real2SimGuidance_wrap2Pi(rtb_Switch_b, &rtb_lambdaWrapped_k);

    // MATLAB Function: '<S9>/wrap2PiTgtHdg'
    Real2SimGuidance_wrap2Pi(rtb_SwitchTargetHDG, &rtb_lambdaWrapped_c);

    // DataStoreWrite: '<S9>/WriteHeading_Log'
    localDW->Heading_Log[0] = rtb_LagDistance;
    localDW->Heading_Log[1] = rtb_lambdaWrapped_k;
    localDW->Heading_Log[2] = rtb_lambdaWrapped_c;

    // Integrator: '<S100>/TD_Alt' incorporates:
    //   DataStoreWrite: '<S9>/WritebiasH_Log'

    localDW->biasH_Log = localX->TD_Alt_CSTATE;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Chart: '<S9>/Chart' incorporates:
        //   DataStoreRead: '<S9>/ReadEngagedFlag_Log'

        // Gateway: Real2SimNav/Chart
        // During: Real2SimNav/Chart
        if (static_cast<uint32_T>(localDW->is_active_c2_Real2SimGuidance) == 0U)
        {
            // Entry: Real2SimNav/Chart
            localDW->is_active_c2_Real2SimGuidance = 1U;

            // Entry Internal: Real2SimNav/Chart
            // Transition: '<S91>:6'
            localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

            // Entry 'hasBias': '<S91>:5'
            localDW->BiasHSwitch = true;
        } else if (localDW->is_c2_Real2SimGuidance == Real2SimGuidance_IN_NoBias)
        {
            localDW->BiasHSwitch = false;

            // During 'NoBias': '<S91>:7'
            if (*rtu_NewMission) {
                // Transition: '<S91>:9'
                localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_hasBias;

                // Entry 'hasBias': '<S91>:5'
                localDW->BiasHSwitch = true;
            }
        } else {
            localDW->BiasHSwitch = true;

            // During 'hasBias': '<S91>:5'
            if (localDW->EngagedFlag > 1.0) {
                // Transition: '<S91>:8'
                localDW->is_c2_Real2SimGuidance = Real2SimGuidance_IN_NoBias;

                // Entry 'NoBias': '<S91>:7'
                localDW->BiasHSwitch = false;
            }
        }

        // End of Chart: '<S9>/Chart'
    }

    // Switch: '<S9>/BiasHSwitch'
    if (localDW->BiasHSwitch) {
        // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
        //   Gain: '<S9>/Gain'
        //   Product: '<S9>/Product'

        rtb_LagDistance = 0.5 * localDW->biasHm70 * *rtu_BiasRatio;
    } else {
        // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
        //   Constant: '<S9>/ZeroBias'

        rtb_LagDistance = 0.0;
    }

    // End of Switch: '<S9>/BiasHSwitch'

    // RelationalOperator: '<S92>/Compare' incorporates:
    //   Constant: '<S92>/Constant'

    localDW->Compare = (rtb_Gain_p < 0.0);

    // Truth Table: '<S9>/Engagement' incorporates:
    //   DataStoreRead: '<S9>/ReadLagDistance'
    //   DataStoreWrite: '<S95>/WriteCrossTrackError'

    // Truth Table Function 'Real2SimNav/Engagement': '<S93>:1'
    //  Front Distance within L1 Upper &  Lower Bound
    if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
            rtb_RefRngmMinRng) & (localDW->LagDistance > rtb_EngagedFlag)))) {
        // Condition '#1': '<S93>:1:11'
        RelationalOperator = true;
    } else {
        RelationalOperator = false;
    }

    //  Front Distance within L0 Upper &  Lower Bound
    if (static_cast<boolean_T>(static_cast<int32_T>((localDW->LagDistance <
            rtb_UpperBound) & (localDW->LagDistance > Gain)))) {
        // Condition '#2': '<S93>:1:15'
        rtb_HdgStatus = true;
    } else {
        rtb_HdgStatus = false;
    }

    //  CrossTrack Error within L1 Bound
    // Condition '#3': '<S93>:1:19'
    //  CrossTrack Error within L0 Bound
    // Condition '#4': '<S93>:1:23'
    if (RelationalOperator && (localDW->CrossTrackError < std::abs
                               (rtb_RefRngmMinRng - rtb_EngagedFlag) / 2.0)) {
        // Decision 'D1': '<S93>:1:25'
        //  Real UAV Deeply Engaged with Simulation UAV
        // Action '1': '<S93>:1:37'
        localDW->Engaged = 2U;
    } else if (rtb_HdgStatus) {
        if (localDW->CrossTrackError < std::abs(rtb_UpperBound - Gain) / 2.0) {
            // Decision 'D2': '<S93>:1:27'
            //  Real UAV Engaged with Simulation UAV
            // Action '2': '<S93>:1:43'
            localDW->Engaged = 1U;
        } else {
            // Decision 'D3': '<S93>:1:29'
            //  Default
            //  Real UAV Not Engaged with Simulation UAV
            // Action '3': '<S93>:1:49'
            localDW->Engaged = 0U;
        }
    } else {
        // Decision 'D3': '<S93>:1:29'
        //  Default
        //  Real UAV Not Engaged with Simulation UAV
        // Action '3': '<S93>:1:49'
        localDW->Engaged = 0U;
    }

    // End of Truth Table: '<S9>/Engagement'

    // Integrator: '<S100>/dotAltTD'
    localDW->dotAltTD = localX->dotAltTD_CSTATE;

    // MATLAB Function: '<S100>/fhan_Alt' incorporates:
    //   DataStoreWrite: '<S9>/WritebiasH_Log'
    //   SignalConversion generated from: '<S185>/ SFunction '
    //   Sum: '<S100>/Sum1'

    // MATLAB Function 'Real2SimNav/TD/fhan_Alt': '<S185>:1'
    // '<S185>:1:3'
    // '<S185>:1:4'
    // '<S185>:1:5'
    // '<S185>:1:6'
    // '<S185>:1:8'
    // '<S185>:1:9'
    rtb_UpperBound = localDW->dotAltTD * 0.1;

    // '<S185>:1:10'
    rtb_Sum1_idx_1 = (localDW->biasH_Log - rtb_LagDistance) + rtb_UpperBound;

    // '<S185>:1:11'
    // '<S185>:1:12'
    if (std::isnan(rtb_Sum1_idx_1)) {
        rtb_Sum1_idx_0 = (rtNaN);
    } else if (rtb_Sum1_idx_1 < 0.0) {
        rtb_Sum1_idx_0 = -1.0;
    } else {
        rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Sum1_idx_1 > 0.0);
    }

    rtb_EngagedFlag = (std::sqrt((8.0 * std::abs(rtb_Sum1_idx_1) +
                         0.004000000000000001) * 0.004000000000000001) -
                       0.004000000000000001) * rtb_Sum1_idx_0 / 2.0 +
        rtb_UpperBound;

    // '<S185>:1:13'
    // '<S185>:1:14'
    if (std::isnan(rtb_Sum1_idx_1 + 0.004000000000000001)) {
        rtb_Sum1_idx_0 = (rtNaN);
    } else if (rtb_Sum1_idx_1 + 0.004000000000000001 < 0.0) {
        rtb_Sum1_idx_0 = -1.0;
    } else {
        rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Sum1_idx_1 +
            0.004000000000000001 > 0.0);
    }

    if (std::isnan(rtb_Sum1_idx_1 - 0.004000000000000001)) {
        rtb_Switch = (rtNaN);
    } else if (rtb_Sum1_idx_1 - 0.004000000000000001 < 0.0) {
        rtb_Switch = -1.0;
    } else {
        rtb_Switch = static_cast<real_T>(rtb_Sum1_idx_1 - 0.004000000000000001 >
            0.0);
    }

    rtb_Sum1_idx_1 = ((rtb_UpperBound + rtb_Sum1_idx_1) - rtb_EngagedFlag) *
        ((rtb_Sum1_idx_0 - rtb_Switch) / 2.0) + rtb_EngagedFlag;

    // '<S185>:1:15'
    // '<S185>:1:17'
    if (std::isnan(rtb_Sum1_idx_1)) {
        rtb_UpperBound = (rtNaN);
    } else if (rtb_Sum1_idx_1 < 0.0) {
        rtb_UpperBound = -1.0;
    } else {
        rtb_UpperBound = static_cast<real_T>(rtb_Sum1_idx_1 > 0.0);
    }

    if (std::isnan(rtb_Sum1_idx_1 + 0.004000000000000001)) {
        rtb_Sum1_idx_0 = (rtNaN);
    } else if (rtb_Sum1_idx_1 + 0.004000000000000001 < 0.0) {
        rtb_Sum1_idx_0 = -1.0;
    } else {
        rtb_Sum1_idx_0 = static_cast<real_T>(rtb_Sum1_idx_1 +
            0.004000000000000001 > 0.0);
    }

    if (std::isnan(rtb_Sum1_idx_1 - 0.004000000000000001)) {
        rtb_Switch = (rtNaN);
    } else if (rtb_Sum1_idx_1 - 0.004000000000000001 < 0.0) {
        rtb_Switch = -1.0;
    } else {
        rtb_Switch = static_cast<real_T>(rtb_Sum1_idx_1 - 0.004000000000000001 >
            0.0);
    }

    localDW->fh = (rtb_Sum1_idx_1 / 0.004000000000000001 - rtb_UpperBound) *
        -0.4 * ((rtb_Sum1_idx_0 - rtb_Switch) / 2.0) - 0.4 * rtb_UpperBound;

    // End of MATLAB Function: '<S100>/fhan_Alt'
    // End of Outputs for SubSystem: '<Root>/Real2SimNav'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Chart: '<Root>/TASgreaterthan15for1Sec' incorporates:
        //   BusCreator: '<S6>/FixedWingGuidanceStateBus'

        // Gateway: TASgreaterthan15for1Sec
        // During: TASgreaterthan15for1Sec
        if (static_cast<uint32_T>(localDW->is_active_c16_Real2SimGuidance) == 0U)
        {
            // Entry: TASgreaterthan15for1Sec
            localDW->is_active_c16_Real2SimGuidance = 1U;

            // Entry Internal: TASgreaterthan15for1Sec
            // Transition: '<S11>:3'
            localDW->durationCounter_1 = 0U;
            localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_NotTakeOff;

            // Entry 'NotTakeOff': '<S11>:2'
            localDW->TakeOffTrigger = false;
        } else if (localDW->is_c16_Real2SimGuidance == Real2SimGuidance_IN_InAir)
        {
            // During 'InAir': '<S11>:4'
            localDW->TakeOffTrigger = true;
        } else {
            // During 'NotTakeOff': '<S11>:2'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((rtu_FlightState->AirSpeed_mps > 15.0) &
                  (rtu_FlightState->Height_meter > 30.0)))) {
                // '<S11>:5:2'
                RelationalOperator = true;
            } else {
                RelationalOperator = false;
            }

            // '<S11>:5:2'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (RelationalOperator) ^ 1))) {
                localDW->durationCounter_1 = 0U;
            }

            if (localDW->durationCounter_1 > 10U) {
                // Transition: '<S11>:5'
                localDW->is_c16_Real2SimGuidance = Real2SimGuidance_IN_InAir;

                // Entry 'InAir': '<S11>:4'
                localDW->TakeOffTrigger = true;
            } else {
                localDW->TakeOffTrigger = false;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((rtu_FlightState->AirSpeed_mps > 15.0) &
                                    (rtu_FlightState->Height_meter > 30.0)))) {
            // '<S11>:5:2'
            RelationalOperator = true;
        } else {
            RelationalOperator = false;
        }

        // '<S11>:5:2'
        if (RelationalOperator) {
            localDW->durationCounter_1 = static_cast<uint32_T>
                (localDW->durationCounter_1 + 1U);
        } else {
            localDW->durationCounter_1 = 0U;
        }

        // End of Chart: '<Root>/TASgreaterthan15for1Sec'

        // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
        //   EnablePort: '<S3>/Enable'

        if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
            localDW->EnabledSubsystem_MODE = localDW->TakeOffTrigger;
        }

        // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'
    }

    // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S3>/Enable'

    if (localDW->EnabledSubsystem_MODE) {
        // SignalConversion generated from: '<S3>/InPlace'
        *rty_EngagedFlag = localDW->Engaged;
    }

    // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'

    // Logic: '<Root>/NoNewMission'
    RelationalOperator = static_cast<boolean_T>(static_cast<int32_T>(
        static_cast<int32_T>(*rtu_NewMission) ^ 1));

    // Reshape: '<Root>/Reshape' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'

    rtb_Heading[0] = rtb_biasH;
    rtb_Heading[1] = rtb_Abs1;
    rtb_Heading[2] = rtb_Switch_b;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Chart: '<Root>/EngagementDebouncer' incorporates:
        //   DataStoreWrite: '<Root>/WriteEngagedFlag_Log'

        if (static_cast<uint32_T>(localDW->temporalCounter_i1_o) < 1023U) {
            localDW->temporalCounter_i1_o = static_cast<uint16_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i1_o) + 1U));
        }

        if (static_cast<uint32_T>(localDW->temporalCounter_i2_i) < 63U) {
            localDW->temporalCounter_i2_i = static_cast<uint8_T>
                (static_cast<uint32_T>(static_cast<uint32_T>
                  (localDW->temporalCounter_i2_i) + 1U));
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
            localDW->EngagedFlag = 0.0;

            // Entry Internal 'Persuit': '<S4>:95'
            // Transition: '<S4>:100'
            localDW->is_Persuit = Real2SimGuidance_IN_Normal;
        } else {
            switch (localDW->is_c34_Real2SimGuidance) {
              case Real2SimGuidance_IN_Debounce:
                // During 'Debounce': '<S4>:90'
                if (static_cast<uint32_T>(localDW->temporalCounter_i1_o) >= 180U)
                {
                    // Transition: '<S4>:93'
                    // Exit Internal 'Debounce': '<S4>:90'
                    localDW->is_Debounce_o = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Persuit;

                    // Entry 'Persuit': '<S4>:95'
                    localDW->EngagedFlag = 0.0;
                    localDW->is_Persuit = Real2SimGuidance_IN_Fault;
                    localDW->temporalCounter_i1_o = 0U;

                    // Entry 'Fault': '<S4>:94'
                } else if (localDW->is_Debounce_o == Real2SimGuidance_IN_Off) {
                    // During 'Off': '<S4>:103'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i2_i) >=
                            40U) {
                        // Transition: '<S4>:87'
                        localDW->is_Debounce_o =
                            Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                        localDW->is_c34_Real2SimGuidance =
                            Real2SimGuidance_IN_Persuit;

                        // Entry 'Persuit': '<S4>:95'
                        localDW->EngagedFlag = 0.0;

                        // Entry Internal 'Persuit': '<S4>:95'
                        // Transition: '<S4>:100'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    } else if (static_cast<int32_T>(*rty_EngagedFlag) > 0) {
                        // Transition: '<S4>:102'
                        localDW->is_Debounce_o = Real2SimGuidance_IN_On;
                        localDW->temporalCounter_i2_i = 0U;
                    }

                    // During 'On': '<S4>:92'
                } else if (static_cast<uint32_T>(localDW->temporalCounter_i2_i) >=
                           40U) {
                    // Transition: '<S4>:99'
                    localDW->is_Debounce_o = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_L0Engaged;

                    // Entry Internal 'L0Engaged': '<S4>:101'
                    // Transition: '<S4>:120'
                    localDW->is_L0Engaged = Real2SimGuidance_IN_L0Default;

                    // Entry 'L0Default': '<S4>:106'
                    localDW->EngagedFlag = 1.0;

                    // Entry Internal 'L0Default': '<S4>:106'
                    // Transition: '<S4>:108'
                    localDW->is_L0Default = Real2SimGuidance_IN_Normal;
                } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S4>:96'
                    localDW->is_Debounce_o = Real2SimGuidance_IN_Off;
                    localDW->temporalCounter_i2_i = 0U;
                }
                break;

              case Real2SimGuidance_IN_L0Engaged:
                // During 'L0Engaged': '<S4>:101'
                if (static_cast<int32_T>(*rty_EngagedFlag) <= 0) {
                    // Transition: '<S4>:91'
                    // Exit Internal 'L0Engaged': '<S4>:101'
                    // Exit Internal 'Debounce': '<S4>:111'
                    localDW->is_Debounce_g = Real2SimGuidance_IN_NO_ACTIVE_CHILD;

                    // Exit Internal 'L0Default': '<S4>:106'
                    localDW->is_L0Default = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_L0Engaged = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_o = 0U;
                    localDW->is_Debounce_o = Real2SimGuidance_IN_Off;
                    localDW->temporalCounter_i2_i = 0U;
                } else {
                    switch (localDW->is_L0Engaged) {
                      case Real2SimGuidance_IN_Debounce:
                        // During 'Debounce': '<S4>:111'
                        if (static_cast<uint32_T>(localDW->temporalCounter_i1_o)
                            >= 60U) {
                            // Transition: '<S4>:119'
                            // Exit Internal 'Debounce': '<S4>:111'
                            localDW->is_Debounce_g =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged =
                                Real2SimGuidance_IN_L0Default;

                            // Entry 'L0Default': '<S4>:106'
                            localDW->EngagedFlag = 1.0;
                            localDW->is_L0Default = Real2SimGuidance_IN_Fault;
                            localDW->temporalCounter_i1_o = 0U;

                            // Entry 'Fault': '<S4>:109'
                        } else if (localDW->is_Debounce_g ==
                                   Real2SimGuidance_IN_Off) {
                            // During 'Off': '<S4>:114'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i2_i) >= 30U) {
                                // Transition: '<S4>:122'
                                localDW->is_Debounce_g =
                                    Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                                localDW->is_L0Engaged =
                                    Real2SimGuidance_IN_L0Default;

                                // Entry 'L0Default': '<S4>:106'
                                localDW->EngagedFlag = 1.0;

                                // Entry Internal 'L0Default': '<S4>:106'
                                // Transition: '<S4>:108'
                                localDW->is_L0Default =
                                    Real2SimGuidance_IN_Normal;
                            } else if (static_cast<int32_T>(*rty_EngagedFlag) >
                                       1) {
                                // Transition: '<S4>:115'
                                localDW->is_Debounce_g = Real2SimGuidance_IN_On;
                                localDW->temporalCounter_i2_i = 0U;
                            }

                            // During 'On': '<S4>:113'
                        } else if (static_cast<uint32_T>
                                   (localDW->temporalCounter_i2_i) >= 30U) {
                            // Transition: '<S4>:118'
                            localDW->is_Debounce_g =
                                Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                            localDW->is_L0Engaged =
                                Real2SimGuidance_IN_L1Engaged;

                            // Entry 'L1Engaged': '<S4>:112'
                            localDW->EngagedFlag = 2.0;
                        } else if (static_cast<int32_T>(*rty_EngagedFlag) <= 1)
                        {
                            // Transition: '<S4>:116'
                            localDW->is_Debounce_g = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_i = 0U;
                        }
                        break;

                      case Real2SimGuidance_IN_L0Default:
                        localDW->EngagedFlag = 1.0;

                        // During 'L0Default': '<S4>:106'
                        if (localDW->is_L0Default == Real2SimGuidance_IN_Fault)
                        {
                            // During 'Fault': '<S4>:109'
                            if (static_cast<uint32_T>
                                    (localDW->temporalCounter_i1_o) >= 600U) {
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
                            localDW->temporalCounter_i1_o = 0U;
                            localDW->is_Debounce_g = Real2SimGuidance_IN_On;
                            localDW->temporalCounter_i2_i = 0U;
                        }
                        break;

                      default:
                        localDW->EngagedFlag = 2.0;

                        // During 'L1Engaged': '<S4>:112'
                        if (static_cast<int32_T>(*rty_EngagedFlag) <= 1) {
                            // Transition: '<S4>:121'
                            localDW->is_L0Engaged = Real2SimGuidance_IN_Debounce;
                            localDW->temporalCounter_i1_o = 0U;
                            localDW->is_Debounce_g = Real2SimGuidance_IN_Off;
                            localDW->temporalCounter_i2_i = 0U;
                        }
                        break;
                    }
                }
                break;

              default:
                localDW->EngagedFlag = 0.0;

                // During 'Persuit': '<S4>:95'
                if (localDW->is_Persuit == Real2SimGuidance_IN_Fault) {
                    // During 'Fault': '<S4>:94'
                    if (static_cast<uint32_T>(localDW->temporalCounter_i1_o) >=
                            600U) {
                        // Transition: '<S4>:89'
                        localDW->is_Persuit = Real2SimGuidance_IN_Normal;
                    }

                    // During 'Normal': '<S4>:88'
                } else if (static_cast<boolean_T>(static_cast<int32_T>((
                              static_cast<int32_T>(*rty_EngagedFlag) > 0) &
                             static_cast<int32_T>(localDW->TakeOffTrigger)))) {
                    // Transition: '<S4>:98'
                    localDW->is_Persuit = Real2SimGuidance_IN_NO_ACTIVE_CHILD;
                    localDW->is_c34_Real2SimGuidance =
                        Real2SimGuidance_IN_Debounce;
                    localDW->temporalCounter_i1_o = 0U;
                    localDW->is_Debounce_o = Real2SimGuidance_IN_On;
                    localDW->temporalCounter_i2_i = 0U;
                }
                break;
            }
        }

        // End of Chart: '<Root>/EngagementDebouncer'

        // MATLAB Function: '<Root>/RepulDir' incorporates:
        //   MinMax: '<S97>/Max'
        //   MinMax: '<S97>/Min'
        //   MinMax: '<S99>/Max'
        //   MinMax: '<S99>/Min'
        //   Reshape: '<Root>/Reshape'

        // MATLAB Function 'RepulDir': '<S10>:1'
        if (static_cast<boolean_T>(static_cast<int32_T>((rtu_DngrListNER_DIMS1[0]
               != 0) & (rtu_DngrListNER_DIMS1[1] != 0)))) {
            // '<S10>:1:3'
            iy = rtu_DngrListNER_DIMS1[0];
            boffset = rtu_DngrListNER_DIMS1[0];
            coffset = rtu_DngrListNER_DIMS1[0];
            j = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i < 2; i++) {
                for (i2 = 0; i2 <= static_cast<int32_T>(coffset - 1); i2++) {
                    NormdNdE_data[static_cast<int32_T>(i2 + static_cast<int32_T>
                        (j * i))] = (rtb_Heading[i] - rtu_DngrListNER[
                                     static_cast<int32_T>(static_cast<int32_T>
                                      (iy * i) + i2)]) / rtu_DngrListNER[
                        static_cast<int32_T>(static_cast<int32_T>(boffset << 1)
                        + i2)];
                }
            }

            // '<S10>:1:4'
            i2 = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(j - 1); i++) {
                NormdNdE_data_0[i] = NormdNdE_data[i];
            }

            iy = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(j - 1); i++) {
                NormdNdE_data_1[i] = NormdNdE_data[static_cast<int32_T>(i + j)];
            }

            Real2SimGuidance_hypot(NormdNdE_data_0, &i2, NormdNdE_data_1, &iy,
                                   r_data, &nblocks);
            for (i = 0; i <= static_cast<int32_T>(nblocks - 1); i++) {
                x_data[i] = (r_data[i] < 1.0);
            }

            localDW->inDngr = false;
            coffset = 1;
            exitg1 = false;
            while ((!exitg1) && (coffset <= nblocks)) {
                if (x_data[static_cast<int32_T>(coffset - 1)]) {
                    localDW->inDngr = true;
                    exitg1 = true;
                } else {
                    coffset = static_cast<int32_T>(coffset + 1);
                }
            }

            // '<S10>:1:5'
            boffset = static_cast<int32_T>(static_cast<int8_T>
                (rtu_DngrListNER_DIMS1[0]));
            i2 = static_cast<int32_T>(static_cast<int8_T>(rtu_DngrListNER_DIMS1
                [0]));
            for (iy = 0; iy <= static_cast<int32_T>(i2 - 1); iy++) {
                theta_data[iy] = rt_atan2d_snf(NormdNdE_data[static_cast<int32_T>
                    (iy + j)], NormdNdE_data[iy]);
            }

            // '<S10>:1:6'
            i2 = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(j - 1); i++) {
                NormdNdE_data_0[i] = NormdNdE_data[i];
            }

            iy = rtu_DngrListNER_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(j - 1); i++) {
                NormdNdE_data_1[i] = NormdNdE_data[static_cast<int32_T>(i + j)];
            }

            Real2SimGuidance_hypot(NormdNdE_data_0, &i2, NormdNdE_data_1, &iy,
                                   r_data, &nblocks);
            for (i = 0; i <= static_cast<int32_T>(nblocks - 1); i++) {
                r_data[i] = 1.0 / r_data[i];
            }

            // '<S10>:1:6'
            i2 = static_cast<int32_T>(static_cast<int8_T>(rtu_DngrListNER_DIMS1
                [0]));
            coffset = static_cast<int32_T>(static_cast<int8_T>
                (rtu_DngrListNER_DIMS1[0]));
            for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                NormdNdE_data_0[i] = theta_data[i];
            }

            i1 = static_cast<int32_T>(static_cast<int8_T>(rtu_DngrListNER_DIMS1
                [0]));
            for (j = 0; j <= static_cast<int32_T>(i1 - 1); j++) {
                NormdNdE_data_0[j] = std::cos(NormdNdE_data_0[j]);
            }

            if (nblocks == static_cast<int32_T>(static_cast<int8_T>
                    (rtu_DngrListNER_DIMS1[0]))) {
                i2 = nblocks;
                for (i = 0; i <= static_cast<int32_T>(nblocks - 1); i++) {
                    NormdNdE_data_0[i] *= r_data[i];
                }
            } else {
                Real2SimGuidance_times_na(NormdNdE_data_0, &i2, r_data, &nblocks);
            }

            iy = static_cast<int32_T>(static_cast<int8_T>(rtu_DngrListNER_DIMS1
                [0]));
            for (j = 0; j <= static_cast<int32_T>(iy - 1); j++) {
                theta_data[j] = std::sin(theta_data[j]);
            }

            if (nblocks == static_cast<int32_T>(static_cast<int8_T>
                    (rtu_DngrListNER_DIMS1[0]))) {
                for (i = 0; i <= static_cast<int32_T>(nblocks - 1); i++) {
                    r_data[i] *= theta_data[i];
                }
            } else {
                Real2SimGuidance_times_n(r_data, &nblocks, theta_data, &boffset);
            }

            // '<S10>:1:7'
            if (nblocks == 0) {
                rtb_Sum1_idx_1 = 0.0;
            } else {
                rtb_Sum1_idx_1 = r_data[0];
                for (iy = 2; iy <= nblocks; iy++) {
                    rtb_Sum1_idx_1 += r_data[static_cast<int32_T>(iy - 1)];
                }
            }

            i1 = i2;
            if (i2 == 0) {
                Gain = 0.0;
            } else {
                Gain = NormdNdE_data_0[0];
                for (iy = 2; iy <= i2; iy++) {
                    Gain += NormdNdE_data_0[static_cast<int32_T>(iy - 1)];
                }
            }

            localDW->RetDir = rt_atan2d_snf(rtb_Sum1_idx_1, Gain);
        } else {
            // '<S10>:1:9'
            localDW->RetDir = rtb_Switch_b;

            // '<S10>:1:10'
            localDW->inDngr = false;
        }

        // End of MATLAB Function: '<Root>/RepulDir'
    }

    // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
    // Switch: '<S1>/SwitchLookAheadPoint'
    if (rtu_ControlSwitch[0]) {
        // Switch: '<S1>/SwitchLookAheadPoint'
        rtb_SwitchLookAheadPoint = *rtu_ImmedGuidanceCMD;
    } else {
        // Outputs for Atomic SubSystem: '<Root>/Real2SimNav'
        // Switch: '<S1>/SwitchLookAheadPoint' incorporates:
        //   BusCreator: '<S1>/BusCMD'
        //   Constant: '<S1>/AirSpd'
        //   DataStoreWrite: '<S9>/WritebiasH_Log'
        //   Sum: '<S9>/SumBiasH'
        //   Switch: '<S95>/SwitchLookAheadNED'

        rtb_SwitchLookAheadPoint.Height = localDW->SwitchLookAheadNED[2] +
            localDW->biasH_Log;

        // End of Outputs for SubSystem: '<Root>/Real2SimNav'
        rtb_SwitchLookAheadPoint.AirSpeed = 0.0;
        rtb_SwitchLookAheadPoint.HeadingAngle = b_fid;
    }

    // End of Switch: '<S1>/SwitchLookAheadPoint'

    // Outputs for Atomic SubSystem: '<S1>/CalTgtDir'
    // Sum: '<S14>/Minus'
    rtb_Minus_i = rtb_Switch_b - rtb_SwitchLookAheadPoint.HeadingAngle;

    // MATLAB Function: '<S14>/wrap2Pi'
    Real2SimGuidance_wrap2Pi(rtb_Minus_i, &localDW->lambdaWrapped);

    // End of Outputs for SubSystem: '<S1>/CalTgtDir'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        int32_T aoffset;

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/minus' incorporates:
        //   BusCreator: '<S6>/FixedWingGuidanceStateBus'

        localDW->SFunction_DIMS2[0] = rtu_PntCldData_DIMS1[0];
        localDW->SFunction_DIMS2[1] = rtu_PntCldData_DIMS1[1];
        coffset = static_cast<int32_T>(rtu_PntCldData_DIMS1[0] *
            rtu_PntCldData_DIMS1[1]);
        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
            localDW->y[i] = rtu_PntCldData[i];
        }

        // MATLAB Function 'AvoidDanger/ProcessCloudPoint/minus': '<S37>:1'
        if (static_cast<boolean_T>(static_cast<int32_T>((rtu_PntCldData_DIMS1[0]
               == 0) | (rtu_PntCldData_DIMS1[1] == 0)))) {
            // '<S37>:1:3'
            localDW->SFunction_DIMS2[0] = 0;
            localDW->SFunction_DIMS2[1] = 2;
        }

        // '<S37>:1:6'
        rtb_biasH_0[0] = rtb_biasH;
        rtb_biasH_0[1] = rtb_Abs1;

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxInit_real_T(&tmp_0, 2);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/minus'
        Real2SimGuidance_repmat(rtb_biasH_0, static_cast<real_T>
                                (localDW->SFunction_DIMS2[0]), tmp_0);

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxInit_real_T(&tmp, 2);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/minus'
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((localDW->SFunction_DIMS2[0] == tmp_0->size
                [0]) & (localDW->SFunction_DIMS2[1] == 2)))) {
            i = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
            tmp->size[0] = localDW->SFunction_DIMS2[0];
            tmp->size[1] = 2;
            Real2SimGuidance_emxEnsureCapacity_real_T(tmp, i);
            coffset = static_cast<int32_T>(localDW->SFunction_DIMS2[0] << 1);
            for (i2 = 0; i2 <= static_cast<int32_T>(coffset - 1); i2++) {
                tmp->data[i2] = localDW->y[i2] - tmp_0->data[i2];
            }
        } else {
            Real2SimGuidance_binary_expand_op_puh(tmp, localDW->y,
                localDW->SFunction_DIMS2, tmp_0);
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxFree_real_T(&tmp_0);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/minus'
        localDW->SFunction_DIMS2[0] = tmp->size[0];
        localDW->SFunction_DIMS2[1] = tmp->size[1];
        coffset = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
            localDW->y[i] = tmp->data[i];
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxFree_real_T(&tmp);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLABSystem: '<S16>/Coordinate Transformation Conversion' incorporates:
        //   SignalConversion generated from: '<S16>/Coordinate Transformation Conversion'

        ct_idx_0 = std::cos(rtb_Switch_b);
        rtb_Heading[0] = std::sin(rtb_Switch_b);

        // Selector: '<S16>/Selector' incorporates:
        //   MATLABSystem: '<S16>/Coordinate Transformation Conversion'

        rtb_TmpSignalConversionAtTrackSimPathInport1[0] = ct_idx_0;
        rtb_TmpSignalConversionAtTrackSimPathInport1[1] = rtb_Heading[0];
        rtb_TmpSignalConversionAtTrackSimPathInport1[2] = 0.0 * ct_idx_0 -
            rtb_Heading[0];
        rtb_TmpSignalConversionAtTrackSimPathInport1[3] = 0.0 * rtb_Heading[0] +
            ct_idx_0;

        // MATLAB Function: '<S16>/MatrixProduct'
        // MATLAB Function 'AvoidDanger/ProcessCloudPoint/MatrixProduct': '<S35>:1' 
        nblocks = localDW->SFunction_DIMS2[0];

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxInit_real_T(&NewPC, 2);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/MatrixProduct' incorporates:
        //   Selector: '<S16>/Selector'

        i = static_cast<int32_T>(NewPC->size[0] * NewPC->size[1]);
        NewPC->size[0] = localDW->SFunction_DIMS2[0];
        NewPC->size[1] = 2;
        Real2SimGuidance_emxEnsureCapacity_real_T(NewPC, i);
        for (j = 0; j < 2; j++) {
            coffset = static_cast<int32_T>(j * nblocks);
            boffset = static_cast<int32_T>(j << 1);
            for (iy = 0; iy <= static_cast<int32_T>(nblocks - 1); iy++) {
                NewPC->data[static_cast<int32_T>(coffset + iy)] = 0.0;
            }

            i1 = localDW->SFunction_DIMS2[1];
            for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                aoffset = static_cast<int32_T>(iy * localDW->SFunction_DIMS2[0]);
                Gain = rtb_TmpSignalConversionAtTrackSimPathInport1[static_cast<
                    int32_T>(boffset + iy)];
                for (i2 = 0; i2 <= static_cast<int32_T>(nblocks - 1); i2++) {
                    i = static_cast<int32_T>(coffset + i2);
                    NewPC->data[i] += localDW->y[static_cast<int32_T>(aoffset +
                        i2)] * Gain;
                }
            }
        }

        // '<S35>:1:3'
        localDW->SFunction_DIMS2_l[0] = NewPC->size[0];
        localDW->SFunction_DIMS2_l[1] = 2;

        // Selector: '<S16>/SelectNorth' incorporates:
        //   MATLAB Function: '<S16>/MatrixProduct'

        localDW->SelectNorth_DIMS1[0] = localDW->SFunction_DIMS2_l[0];
        localDW->SelectNorth_DIMS1[1] = 1;
        j = localDW->SFunction_DIMS2_l[0];
        for (i = 0; i <= static_cast<int32_T>(j - 1); i++) {
            localDW->SelectNorth[i] = NewPC->data[i];
        }

        // End of Selector: '<S16>/SelectNorth'

        // Selector: '<S16>/SelectEast' incorporates:
        //   MATLAB Function: '<S16>/MatrixProduct'

        localDW->SelectEast_DIMS1[0] = localDW->SFunction_DIMS2_l[0];
        localDW->SelectEast_DIMS1[1] = 1;
        j = localDW->SFunction_DIMS2_l[0];
        for (i = 0; i <= static_cast<int32_T>(j - 1); i++) {
            localDW->SelectEast[i] = NewPC->data[static_cast<int32_T>(i +
                NewPC->size[0])];
        }

        // End of Selector: '<S16>/SelectEast'
        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxFree_real_T(&NewPC);

        // MATLAB Function 'AvoidDanger/ProcessCloudPoint/Cartesian2Polar': '<S34>:1' 
        // '<S34>:1:3'
        Real2SimGuidance_emxInit_real_T(&AngSec, 1);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar' incorporates:
        //   Selector: '<S16>/SelectEast'
        //   Selector: '<S16>/SelectNorth'

        if (localDW->SelectEast_DIMS1[0] == localDW->SelectNorth_DIMS1[0]) {
            i = AngSec->size[0];
            AngSec->size[0] = localDW->SelectEast_DIMS1[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(AngSec, i);
            coffset = localDW->SelectEast_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                AngSec->data[i] = rt_atan2d_snf(localDW->SelectEast[i],
                    localDW->SelectNorth[i]);
            }
        } else {
            rtb_SelectEast_0.data = &localDW->SelectEast[0];
            tmp_v = localDW->SelectEast_DIMS1[0];
            rtb_SelectEast_0.size = &tmp_v;
            rtb_SelectEast_0.allocatedSize = 1048576;
            rtb_SelectEast_0.numDimensions = 1;
            rtb_SelectEast_0.canFreeData = false;
            rtb_SelectNorth_0.data = &localDW->SelectNorth[0];
            tmp_w = localDW->SelectNorth_DIMS1[0];
            rtb_SelectNorth_0.size = &tmp_w;
            rtb_SelectNorth_0.allocatedSize = 1048576;
            rtb_SelectNorth_0.numDimensions = 1;
            rtb_SelectNorth_0.canFreeData = false;
            Real2SimGuidance_expand_atan2(&rtb_SelectEast_0, &rtb_SelectNorth_0,
                AngSec);
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxInit_real_T(&catAngSec, 1);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar' incorporates:
        //   Selector: '<S16>/SelectEast'
        //   Selector: '<S16>/SelectNorth'

        if (localDW->SelectNorth_DIMS1[0] == localDW->SelectEast_DIMS1[0]) {
            i = catAngSec->size[0];
            catAngSec->size[0] = localDW->SelectNorth_DIMS1[0];
            Real2SimGuidance_emxEnsureCapacity_real_T(catAngSec, i);
            coffset = localDW->SelectNorth_DIMS1[0];
            for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                catAngSec->data[i] = rt_hypotd_snf(localDW->SelectNorth[i],
                    localDW->SelectEast[i]);
            }
        } else {
            rtb_SelectNorth_1.data = &localDW->SelectNorth[0];
            tmp_x = localDW->SelectNorth_DIMS1[0];
            rtb_SelectNorth_1.size = &tmp_x;
            rtb_SelectNorth_1.allocatedSize = 1048576;
            rtb_SelectNorth_1.numDimensions = 1;
            rtb_SelectNorth_1.canFreeData = false;
            rtb_SelectEast_1.data = &localDW->SelectEast[0];
            tmp_y = localDW->SelectEast_DIMS1[0];
            rtb_SelectEast_1.size = &tmp_y;
            rtb_SelectEast_1.allocatedSize = 1048576;
            rtb_SelectEast_1.numDimensions = 1;
            rtb_SelectEast_1.canFreeData = false;
            Real2SimGuidance_expand_hypot(&rtb_SelectNorth_1, &rtb_SelectEast_1,
                catAngSec);
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        // '<S34>:1:6'
        // '<S34>:1:7'
        // '<S34>:1:8'
        Real2SimGuidance_emxInit_real_T(&rtb_rho_0, 1);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar'
        Real2SimGuidance_abs(AngSec, rtb_rho_0);

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxInit_boolean_T(&f, 1);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar' incorporates:
        //   MinMax: '<S97>/Max'
        //   MinMax: '<S97>/Min'
        //   MinMax: '<S99>/Max'
        //   MinMax: '<S99>/Min'
        //   Sum: '<S99>/ComputeLB'

        if (rtb_rho_0->size[0] == catAngSec->size[0]) {
            i = f->size[0];
            f->size[0] = rtb_rho_0->size[0];
            Real2SimGuidance_emxEnsureCapacity_boolean_T(f, i);
            coffset = rtb_rho_0->size[0];
            for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                rtb_Gain_p = catAngSec->data[i];
                f->data[i] = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>((rtb_Gain_p < 686.86935486365564) &
                    (rtb_Gain_p > 1.75)))) & (rtb_rho_0->data[i] <=
                    2.0943951023931953)));
            }
        } else {
            Real2SimGuidance_binary_expand_op_pu(f, rtb_rho_0,
                2.0943951023931953, catAngSec, rtCP_Cartesian2Polar_RngLmt);
        }

        // '<S34>:1:8'
        i1 = static_cast<int32_T>(f->size[0] - 1);
        j = 0;
        for (i2 = 0; i2 <= i1; i2++) {
            if (f->data[i2]) {
                j = static_cast<int32_T>(j + 1);
            }
        }

        localDW->SFunction_DIMS4 = j;
        j = 0;
        for (iy = 0; iy <= i1; iy++) {
            if (f->data[iy]) {
                // '<S34>:1:8'
                localDW->theta[j] = AngSec->data[iy];
                j = static_cast<int32_T>(j + 1);
            }
        }

        // '<S34>:1:8'
        j = 0;
        for (iy = 0; iy <= i1; iy++) {
            if (f->data[iy]) {
                j = static_cast<int32_T>(j + 1);
            }
        }

        localDW->SFunction_DIMS3 = j;
        j = 0;
        for (iy = 0; iy <= i1; iy++) {
            if (f->data[iy]) {
                // '<S34>:1:8'
                localDW->rho[j] = catAngSec->data[iy];
                j = static_cast<int32_T>(j + 1);
            }
        }

        if (localDW->SFunction_DIMS4 != 0) {
            // '<S34>:1:12'
            Real2SimGuidance_emxInit_boolean_T(&slctTF, 1);
            i = slctTF->size[0];
            slctTF->size[0] = localDW->SFunction_DIMS4;
            Real2SimGuidance_emxEnsureCapacity_boolean_T(slctTF, i);
            for (i = 0; i <= static_cast<int32_T>(localDW->SFunction_DIMS4 - 1);
                 i++) {
                slctTF->data[i] = false;
            }

            // '<S34>:1:13'
            i = AngSec->size[0];
            AngSec->size[0] = localDW->SFunction_DIMS4;
            Real2SimGuidance_emxEnsureCapacity_real_T(AngSec, i);
            for (i = 0; i <= static_cast<int32_T>(localDW->SFunction_DIMS4 - 1);
                 i++) {
                AngSec->data[i] = localDW->theta[i] / 0.034906585039886591;
            }

            i1 = AngSec->size[0];
            for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                AngSec->data[iy] = std::round(AngSec->data[iy]);
            }

            // '<S34>:1:13'
            Real2SimGuidance_unique_vector(AngSec, catAngSec);
            i1 = catAngSec->size[0];

            // '<S34>:1:14'
            Real2SimGuidance_emxInit_boolean_T(&c, 1);
            Real2SimGuidance_emxInit_int32_T(&d, 1);
            Real2SimGuidance_emxInit_int32_T(&e, 1);
            for (iy = 0; iy <= static_cast<int32_T>(i1 - 1); iy++) {
                // '<S34>:1:15'
                rtb_Gain_p = catAngSec->data[iy];
                i = f->size[0];
                f->size[0] = AngSec->size[0];
                Real2SimGuidance_emxEnsureCapacity_boolean_T(f, i);
                coffset = AngSec->size[0];

                // '<S34>:1:16'
                Gain = catAngSec->data[iy];
                i = c->size[0];
                c->size[0] = AngSec->size[0];
                Real2SimGuidance_emxEnsureCapacity_boolean_T(c, i);
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    rtb_UpperBound = AngSec->data[i];
                    f->data[i] = (rtb_UpperBound == rtb_Gain_p);
                    c->data[i] = (rtb_UpperBound == Gain);
                }

                boffset = static_cast<int32_T>(f->size[0] - 1);
                i2 = 0;
                for (j = 0; j <= boffset; j++) {
                    if (f->data[j]) {
                        i2 = static_cast<int32_T>(i2 + 1);
                    }
                }

                i = d->size[0];
                d->size[0] = i2;
                Real2SimGuidance_emxEnsureCapacity_int32_T(d, i);
                i2 = 0;
                for (j = 0; j <= boffset; j++) {
                    if (f->data[j]) {
                        d->data[i2] = static_cast<int32_T>(j + 1);
                        i2 = static_cast<int32_T>(i2 + 1);
                    }
                }

                boffset = static_cast<int32_T>(c->size[0] - 1);
                i2 = 0;
                for (j = 0; j <= boffset; j++) {
                    if (c->data[j]) {
                        i2 = static_cast<int32_T>(i2 + 1);
                    }
                }

                i = e->size[0];
                e->size[0] = i2;
                Real2SimGuidance_emxEnsureCapacity_int32_T(e, i);
                i2 = 0;
                for (j = 0; j <= boffset; j++) {
                    if (c->data[j]) {
                        e->data[i2] = static_cast<int32_T>(j + 1);
                        i2 = static_cast<int32_T>(i2 + 1);
                    }
                }

                if (d->size[0] == 0) {
                    rtb_Sum1_idx_1 = 0.0;
                } else {
                    if (d->size[0] <= 1024) {
                        i2 = d->size[0];
                        coffset = 0;
                        nblocks = 1;
                    } else {
                        i2 = 1024;
                        nblocks = static_cast<int32_T>(static_cast<uint32_T>(
                            static_cast<uint32_T>(d->size[0]) >> 10));
                        coffset = static_cast<int32_T>(d->size[0] -
                            static_cast<int32_T>(nblocks << 10));
                        if (coffset > 0) {
                            nblocks = static_cast<int32_T>(nblocks + 1);
                        } else {
                            coffset = 1024;
                        }
                    }

                    rtb_Sum1_idx_1 = localDW->rho[static_cast<int32_T>(d->data[0]
                        - 1)];
                    for (j = 2; j <= i2; j++) {
                        rtb_Sum1_idx_1 += localDW->rho[static_cast<int32_T>
                            (d->data[static_cast<int32_T>(j - 1)] - 1)];
                    }

                    for (i2 = 2; i2 <= nblocks; i2++) {
                        boffset = static_cast<int32_T>(static_cast<int32_T>(i2 -
                            1) << 10);
                        Gain = localDW->rho[static_cast<int32_T>(d->data[boffset]
                            - 1)];
                        if (i2 == nblocks) {
                            aoffset = coffset;
                        } else {
                            aoffset = 1024;
                        }

                        for (j = 2; j <= aoffset; j++) {
                            Gain += localDW->rho[static_cast<int32_T>(d->data[
                                static_cast<int32_T>(static_cast<int32_T>
                                (boffset + j) - 1)] - 1)];
                        }

                        rtb_Sum1_idx_1 += Gain;
                    }
                }

                i = rtb_rho_0->size[0];
                rtb_rho_0->size[0] = e->size[0];
                Real2SimGuidance_emxEnsureCapacity_real_T(rtb_rho_0, i);
                coffset = e->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    rtb_rho_0->data[i] = localDW->rho[static_cast<int32_T>
                        (e->data[i] - 1)];
                }

                Gain = std::fmin(rtb_Sum1_idx_1 / static_cast<real_T>(d->size[0]),
                                 Real2SimGuidance_median(rtb_rho_0));

                // '<S34>:1:15'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (((localDW->SFunction_DIMS3 == 1 ?
                        AngSec->size[0] : localDW->SFunction_DIMS3) ==
                        slctTF->size[0]) & (localDW->SFunction_DIMS3 ==
                                            AngSec->size[0])))) {
                    rtb_Gain_p = catAngSec->data[iy];
                    coffset = slctTF->size[0];
                    for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                        slctTF->data[i] = static_cast<boolean_T>
                            (static_cast<int32_T>(static_cast<int32_T>(
                               static_cast<boolean_T>(static_cast<int32_T>
                                ((localDW->rho[i] <= Gain) & (AngSec->data[i] ==
                                  rtb_Gain_p)))) | static_cast<int32_T>
                              (slctTF->data[i])));
                    }
                } else {
                    Real2SimGuidance_binary_expand_op_p(slctTF, localDW->rho,
                        localDW->SFunction_DIMS3, Gain, AngSec, catAngSec, iy);
                }
            }

            Real2SimGuidance_emxFree_int32_T(&e);
            Real2SimGuidance_emxFree_int32_T(&d);
            Real2SimGuidance_emxFree_boolean_T(&c);
            i1 = static_cast<int32_T>(slctTF->size[0] - 1);
            j = 0;
            i2 = 0;
            for (iy = 0; iy <= i1; iy++) {
                if (slctTF->data[iy]) {
                    j = static_cast<int32_T>(j + 1);

                    // '<S34>:1:18'
                    localDW->theta[i2] = localDW->theta[iy];
                    i2 = static_cast<int32_T>(i2 + 1);
                }
            }

            localDW->SFunction_DIMS4 = j;
            j = 0;
            i2 = 0;
            for (iy = 0; iy <= i1; iy++) {
                if (slctTF->data[iy]) {
                    j = static_cast<int32_T>(j + 1);

                    // '<S34>:1:18'
                    localDW->rho[i2] = localDW->rho[iy];
                    i2 = static_cast<int32_T>(i2 + 1);
                }
            }

            Real2SimGuidance_emxFree_boolean_T(&slctTF);
            localDW->SFunction_DIMS3 = j;
        }

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'
        Real2SimGuidance_emxFree_real_T(&rtb_rho_0);
        Real2SimGuidance_emxFree_boolean_T(&f);
        Real2SimGuidance_emxFree_real_T(&catAngSec);
        Real2SimGuidance_emxFree_real_T(&AngSec);

        // Outputs for Atomic SubSystem: '<S1>/ProcessCloudPoint'
        // MATLAB Function: '<S16>/Cartesian2Polar' incorporates:
        //   DataStoreWrite: '<S16>/Data Store Write'

        localDW->AvoidDanger = static_cast<boolean_T>(static_cast<int32_T>
            ((localDW->SFunction_DIMS4 != 0) & (localDW->SFunction_DIMS3 != 0)));

        // End of Outputs for SubSystem: '<S1>/ProcessCloudPoint'

        // Gain: '<S1>/Inverse'
        // '<S34>:1:22'
        localDW->Inverse_DIMS1 = localDW->SFunction_DIMS4;
        coffset = static_cast<int32_T>(localDW->SFunction_DIMS4 - 1);
        for (i = 0; i <= coffset; i++) {
            localDW->theta[i] = -localDW->theta[i];
        }

        // End of Gain: '<S1>/Inverse'

        // Logic: '<S1>/NotInDngr'
        rtb_NotInDngr = static_cast<boolean_T>(static_cast<int32_T>(static_cast<
            int32_T>(localDW->inDngr) ^ 1));

        // Outputs for Enabled SubSystem: '<S1>/TieredVFH+' incorporates:
        //   EnablePort: '<S17>/Enable'

        if (rtsiIsModeUpdateTimeStep(Real2SimGuidance_M->solverInfo)) {
            if (rtb_NotInDngr) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (localDW->TieredVFH_MODE) ^ 1))) {
                    // InitializeConditions for MATLABSystem: '<S17>/Vector Field Histogram' 
                    std::memset(&localDW->obj_p.BinaryHistogram[0], 0,
                                static_cast<uint32_T>(120U * sizeof(boolean_T)));
                    localDW->obj_p.PreviousDirection *= 0.0;
                    localDW->TieredVFH_MODE = true;
                }
            } else {
                localDW->TieredVFH_MODE = false;
            }
        }

        if (localDW->TieredVFH_MODE) {
            // MATLABSystem: '<S17>/Vector Field Histogram'
            rtb_HdgStatus = false;
            rtb_AvoidDanger = true;
            j = 0;
            exitg1 = false;
            while ((!exitg1) && (j < 2)) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((localDW->obj_p.DistanceLimits[j] ==
                       rtCP_VectorFieldHistogram_DistanceLimits[j]) ^ 1))) {
                    rtb_AvoidDanger = false;
                    exitg1 = true;
                } else {
                    j = static_cast<int32_T>(j + 1);
                }
            }

            if (rtb_AvoidDanger) {
                rtb_HdgStatus = true;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_HdgStatus) ^ 1))) {
                localDW->obj_p.DistanceLimits[0] = Real2SimGuidance_minimum
                    (rtCP_VectorFieldHistogram_DistanceLimits);
                localDW->obj_p.DistanceLimits[1] = 686.86935486365564;
            }

            rtb_HdgStatus = false;
            rtb_AvoidDanger = true;
            j = 0;
            exitg1 = false;
            while ((!exitg1) && (j < 2)) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((localDW->
                        obj_p.HistogramThresholds[j] ==
                        rtCP_VectorFieldHistogram_HistogramThresholds[j]) ^ 1)))
                {
                    rtb_AvoidDanger = false;
                    exitg1 = true;
                } else {
                    j = static_cast<int32_T>(j + 1);
                }
            }

            if (rtb_AvoidDanger) {
                rtb_HdgStatus = true;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_HdgStatus) ^ 1))) {
                localDW->obj_p.HistogramThresholds[0] = Real2SimGuidance_minimum
                    (rtCP_VectorFieldHistogram_HistogramThresholds);
                localDW->obj_p.HistogramThresholds[1] = 1717.1733871591391;
            }

            if (localDW->obj_p.RobotRadius != 35.0) {
                localDW->obj_p.RobotRadius = 35.0;
            }

            if (localDW->obj_p.SafetyDistance != 35.0) {
                localDW->obj_p.SafetyDistance = 35.0;
            }

            if (localDW->obj_p.MinTurningRadius != 171.71733871591391) {
                localDW->obj_p.MinTurningRadius = 171.71733871591391;
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

            rtb_rho_1.data = &localDW->rho[0];
            tmp_z = localDW->SFunction_DIMS3;
            rtb_rho_1.size = &tmp_z;
            rtb_rho_1.allocatedSize = 1048576;
            rtb_rho_1.numDimensions = 1;
            rtb_rho_1.canFreeData = false;

            // MATLABSystem: '<S17>/Vector Field Histogram' incorporates:
            //   Gain: '<S1>/Inverse'

            rtb_theta_0.data = &localDW->theta[0];
            tmp_10 = localDW->Inverse_DIMS1;
            rtb_theta_0.size = &tmp_10;
            rtb_theta_0.allocatedSize = 1048576;
            rtb_theta_0.numDimensions = 1;
            rtb_theta_0.canFreeData = false;

            // MATLABSystem: '<S17>/Vector Field Histogram'
            localDW->VectorFieldHistogram = Real2SimGuidance_SystemCore_step
                (&localDW->obj_p, &rtb_rho_1, &rtb_theta_0,
                 localDW->lambdaWrapped, localDW);
        }

        // End of Outputs for SubSystem: '<S1>/TieredVFH+'
    }

    // Outputs for Atomic SubSystem: '<S1>/Hdg2LAP'
    // Sum: '<S15>/Minus'
    rtb_Minus = rtb_Switch_b - localDW->VectorFieldHistogram;

    // RelationalOperator: '<S15>/IsNaN'
    rtb_AvoidDanger = std::isnan(rtb_Minus);

    // RelationalOperator: '<S28>/Compare'
    localDW->Compare_o = rtb_AvoidDanger;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
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
    }

    // MATLAB Function: '<S15>/AngDiff'
    Real2SimGuidance_AngDiff(rtb_Minus, rtb_SwitchLookAheadPoint.HeadingAngle,
        &rtb_LagDistance);

    // RelationalOperator: '<S21>/Compare' incorporates:
    //   Constant: '<S21>/Constant'

    rtb_HdgStatus = (rtb_LagDistance > 1.0E-6);

    // RelationalOperator: '<S29>/Compare' incorporates:
    //   Constant: '<S29>/Constant'

    localDW->Compare_l = static_cast<boolean_T>(static_cast<int32_T>(
        static_cast<int32_T>(rtb_HdgStatus) ^ 1));
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
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
    }

    // RelationalOperator: '<S30>/Compare'
    localDW->Compare_k = rtb_HdgStatus;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
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
    }

    // Switch: '<S15>/Switch' incorporates:
    //   Logic: '<S15>/OR'

    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (localDW->inDngr) | static_cast<int32_T>(rtb_AvoidDanger)))) {
        // DataStoreRead: '<Root>/ReadLagDistance'
        rtb_LagDistance = localDW->RetDir;
    } else {
        // DataStoreRead: '<Root>/ReadLagDistance'
        rtb_LagDistance = rtb_Minus;
    }

    // End of Switch: '<S15>/Switch'

    // BusAssignment: '<S15>/Bus Assignment'
    rtb_BusAssignment = rtb_SwitchLookAheadPoint;

    // BusAssignment: '<S15>/Bus Assignment'
    rtb_BusAssignment.HeadingAngle = rtb_LagDistance;

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   Trigonometry: '<S15>/Cos'

    rtb_LagDistance = std::cos(rtb_BusAssignment.HeadingAngle);
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // MATLAB Function: '<S15>/getLAPGainBias'
        // MATLAB Function 'AvoidDanger/Hdg2LAP/getLAPGainBias': '<S27>:1'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->LAPGainBias_not_empty) ^ 1))) {
            int32_T exitg2;
            int32_T exitg3;
            int8_T fileid;

            // '<S27>:1:3'
            // '<S27>:1:4'
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = Real2SimGuidance_cfopen_e("config.ini", "rb", localDW);
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_o(static_cast<real_T>(fileid), k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_e(static_cast<real_T>(fileid), localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_e, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_5, 2);
                do {
                    exitg2 = 0;
                    if (data->size[1] != 0) {
                        i = static_cast<int32_T>(data_5->size[0] * data_5->size
                            [1]);
                        data_5->size[0] = 1;
                        data_5->size[1] = data->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(data_5, i);
                        i2 = static_cast<int32_T>(static_cast<int32_T>
                            (data->size[0] * data->size[1]) - 1);
                        for (i = 0; i <= i2; i++) {
                            data_5->data[i] = data->data[i];
                        }

                        Real2SimGuidance_strtok_o(data_5, curLine, data);
                        Real2SimGuidance_strtok_ow(curLine, tmp_e);
                        Real2SimGuidance_strtrim_o(tmp_e, curLine);
                        if (curLine->size[1] >= 2) {
                            rtb_HdgStatus = false;
                            if (curLine->data[0] == '[') {
                                rtb_HdgStatus = true;
                            }

                            guard1 = false;
                            if (rtb_HdgStatus) {
                                rtb_HdgStatus = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    rtb_HdgStatus = true;
                                }

                                if (rtb_HdgStatus) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        i2 = 0;
                                        i1 = 0;
                                    } else {
                                        i2 = 1;
                                        i1 = static_cast<int32_T>(curLine->size
                                            [1] - 1);
                                    }

                                    i = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    coffset = static_cast<int32_T>(i1 - i2);
                                    curSection->size[1] = coffset;
                                    Real2SimGuidance_emxEnsureCapacity_char_T_g
                                        (curSection, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (coffset - 1); i++) {
                                        curSection->data[i] = curLine->data[
                                            static_cast<int32_T>(i2 + i)];
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
                                    rtb_HdgStatus = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (rtb_HdgStatus) ^ 1))) &&
                                        Real2SimGuidance_contains_f(curLine)) {
                                    Real2SimGuidance_strtok_owf(curLine, aTmp,
                                        curVal);
                                    Real2SimGuidance_find_token_m(curVal, &i1,
                                        &iy);
                                    if (i1 > static_cast<int32_T>(iy - 1)) {
                                        i1 = 0;
                                        iy = 0;
                                    } else {
                                        i1 = static_cast<int32_T>(i1 - 1);
                                        iy = static_cast<int32_T>(iy - 1);
                                    }

                                    Real2SimGuidance_strtrim_o(aTmp, curKey);
                                    i = static_cast<int32_T>(curLine->size[0] *
                                        curLine->size[1]);
                                    curLine->size[0] = 1;
                                    coffset = static_cast<int32_T>(iy - i1);
                                    curLine->size[1] = coffset;
                                    Real2SimGuidance_emxEnsureCapacity_char_T_g
                                        (curLine, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (coffset - 1); i++) {
                                        curLine->data[i] = curVal->data[
                                            static_cast<int32_T>(i1 + i)];
                                    }

                                    Real2SimGuidance_strtrim_o(curLine, curVal);
                                }
                            }
                        }

                        if (Real2SimGuidance_strcmp_f(curSection)) {
                            if (curKey->size[1] == 0) {
                                aTmp->size[0] = 1;
                                aTmp->size[1] = 0;
                            } else {
                                i = static_cast<int32_T>(aTmp->size[0] *
                                    aTmp->size[1]);
                                aTmp->size[0] = 1;
                                aTmp->size[1] = curKey->size[1];
                                Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp,
                                    i);
                                coffset = curKey->size[1];
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    aTmp->data[i] = curKey->data[i];
                                }
                            }

                            rtb_HdgStatus = false;
                            if (aTmp->size[1] == 4) {
                                iy = 0;
                                do {
                                    exitg3 = 0;
                                    if (iy < 4) {
                                        if (l[static_cast<int32_T>
                                                (static_cast<int32_T>(
                                                static_cast<uint8_T>(aTmp->
                                                data[iy])) & 127)] != l[
                                                static_cast<int32_T>(m[iy])]) {
                                            exitg3 = 1;
                                        } else {
                                            iy = static_cast<int32_T>(iy + 1);
                                        }
                                    } else {
                                        rtb_HdgStatus = true;
                                        exitg3 = 1;
                                    }
                                } while (exitg3 == 0);
                            }

                            if (rtb_HdgStatus) {
                                i = static_cast<int32_T>(ret->size[0] *
                                    ret->size[1]);
                                ret->size[0] = 1;
                                ret->size[1] = curVal->size[1];
                                Real2SimGuidance_emxEnsureCapacity_char_T_g(ret,
                                    i);
                                coffset = curVal->size[1];
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    ret->data[i] = curVal->data[i];
                                }

                                exitg2 = 1;
                            }
                        }
                    } else {
                        exitg2 = 1;
                    }
                } while (exitg2 == 0);

                Real2SimGuidance_emxFree_char_T_o(&data_5);
                Real2SimGuidance_emxFree_char_T_o(&tmp_e);
            }

            inputArg_data = Real2SimGuidance_str2double_k(ret);
            printf("Set LAP Gain:%f\n", inputArg_data.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = Real2SimGuidance_cfopen_e("config.ini", "rb", localDW);
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_o(static_cast<real_T>(fileid), k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_e(static_cast<real_T>(fileid), localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_d, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_4, 2);
                do {
                    exitg2 = 0;
                    if (data->size[1] != 0) {
                        i = static_cast<int32_T>(data_4->size[0] * data_4->size
                            [1]);
                        data_4->size[0] = 1;
                        data_4->size[1] = data->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(data_4, i);
                        i2 = static_cast<int32_T>(static_cast<int32_T>
                            (data->size[0] * data->size[1]) - 1);
                        for (i = 0; i <= i2; i++) {
                            data_4->data[i] = data->data[i];
                        }

                        Real2SimGuidance_strtok_o(data_4, curLine, data);
                        Real2SimGuidance_strtok_ow(curLine, tmp_d);
                        Real2SimGuidance_strtrim_o(tmp_d, curLine);
                        if (curLine->size[1] >= 2) {
                            rtb_HdgStatus = false;
                            if (curLine->data[0] == '[') {
                                rtb_HdgStatus = true;
                            }

                            guard1 = false;
                            if (rtb_HdgStatus) {
                                rtb_HdgStatus = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    rtb_HdgStatus = true;
                                }

                                if (rtb_HdgStatus) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        iy = 0;
                                        i1 = 0;
                                    } else {
                                        iy = 1;
                                        i1 = static_cast<int32_T>(curLine->size
                                            [1] - 1);
                                    }

                                    i = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    coffset = static_cast<int32_T>(i1 - iy);
                                    curSection->size[1] = coffset;
                                    Real2SimGuidance_emxEnsureCapacity_char_T_g
                                        (curSection, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (coffset - 1); i++) {
                                        curSection->data[i] = curLine->data[
                                            static_cast<int32_T>(iy + i)];
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
                                    rtb_HdgStatus = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (rtb_HdgStatus) ^ 1))) &&
                                        Real2SimGuidance_contains_f(curLine)) {
                                    Real2SimGuidance_strtok_owf(curLine, aTmp,
                                        curVal);
                                    Real2SimGuidance_find_token_m(curVal, &i1,
                                        &iy);
                                    if (i1 > static_cast<int32_T>(iy - 1)) {
                                        j = 0;
                                        iy = 0;
                                    } else {
                                        j = static_cast<int32_T>(i1 - 1);
                                        iy = static_cast<int32_T>(iy - 1);
                                    }

                                    Real2SimGuidance_strtrim_o(aTmp, curKey);
                                    i = static_cast<int32_T>(curLine->size[0] *
                                        curLine->size[1]);
                                    curLine->size[0] = 1;
                                    coffset = static_cast<int32_T>(iy - j);
                                    curLine->size[1] = coffset;
                                    Real2SimGuidance_emxEnsureCapacity_char_T_g
                                        (curLine, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (coffset - 1); i++) {
                                        curLine->data[i] = curVal->data[
                                            static_cast<int32_T>(j + i)];
                                    }

                                    Real2SimGuidance_strtrim_o(curLine, curVal);
                                }
                            }
                        }

                        if (Real2SimGuidance_strcmp_f(curSection)) {
                            if (curKey->size[1] == 0) {
                                aTmp->size[0] = 1;
                                aTmp->size[1] = 0;
                            } else {
                                i = static_cast<int32_T>(aTmp->size[0] *
                                    aTmp->size[1]);
                                aTmp->size[0] = 1;
                                aTmp->size[1] = curKey->size[1];
                                Real2SimGuidance_emxEnsureCapacity_char_T_g(aTmp,
                                    i);
                                coffset = curKey->size[1];
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    aTmp->data[i] = curKey->data[i];
                                }
                            }

                            rtb_HdgStatus = false;
                            if (aTmp->size[1] == 4) {
                                iy = 0;
                                do {
                                    exitg3 = 0;
                                    if (iy < 4) {
                                        if (l[static_cast<int32_T>
                                                (static_cast<int32_T>(
                                                static_cast<uint8_T>(aTmp->
                                                data[iy])) & 127)] != l[
                                                static_cast<int32_T>(n[iy])]) {
                                            exitg3 = 1;
                                        } else {
                                            iy = static_cast<int32_T>(iy + 1);
                                        }
                                    } else {
                                        rtb_HdgStatus = true;
                                        exitg3 = 1;
                                    }
                                } while (exitg3 == 0);
                            }

                            if (rtb_HdgStatus) {
                                i = static_cast<int32_T>(ret->size[0] *
                                    ret->size[1]);
                                ret->size[0] = 1;
                                ret->size[1] = curVal->size[1];
                                Real2SimGuidance_emxEnsureCapacity_char_T_g(ret,
                                    i);
                                coffset = curVal->size[1];
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    ret->data[i] = curVal->data[i];
                                }

                                exitg2 = 1;
                            }
                        }
                    } else {
                        exitg2 = 1;
                    }
                } while (exitg2 == 0);

                Real2SimGuidance_emxFree_char_T_o(&data_4);
                Real2SimGuidance_emxFree_char_T_o(&tmp_d);
            }

            tmp_1 = Real2SimGuidance_str2double_k(ret);
            printf("Set LAP Bias:%f\n", tmp_1.re);
            fflush(stdout);
            localDW->LAPGainBias.Gain = inputArg_data.re;
            localDW->LAPGainBias.Bias = tmp_1.re;
            localDW->LAPGainBias_not_empty = true;
        }

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(localDW->LAPGainBias.Gain)) ^ 1))) {
            // '<S27>:1:6'
            // '<S27>:1:7'
            localDW->Gain_i = localDW->LAPGainBias.Gain;
        } else {
            // '<S27>:1:9'
            localDW->Gain_i = 0.0;
        }

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(localDW->LAPGainBias.Bias)) ^ 1))) {
            // '<S27>:1:11'
            // '<S27>:1:12'
            localDW->Bias = localDW->LAPGainBias.Bias;
        } else {
            // '<S27>:1:14'
            localDW->Bias = 5000.0;
        }

        // End of MATLAB Function: '<S15>/getLAPGainBias'
    }

    // Sum: '<S15>/Sum' incorporates:
    //   DataStoreRead: '<S15>/ReadRefGndSpd'
    //   Product: '<S15>/Product'

    rtb_Gain_p = localDW->Gain_i * localDW->RefGndSpd + localDW->Bias;

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   Product: '<S15>/ProductNorth'

    rtb_LagDistance *= rtb_Gain_p;

    // Sum: '<S15>/SumEast' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'
    //   Product: '<S15>/ProductEast'
    //   Trigonometry: '<S15>/Sin'

    rtb_Abs1 += rtb_Gain_p * std::sin(rtb_BusAssignment.HeadingAngle);

    // Sum: '<S15>/SumNorth' incorporates:
    //   BusCreator: '<S6>/FixedWingGuidanceStateBus'

    rtb_biasH += rtb_LagDistance;

    // End of Outputs for SubSystem: '<S1>/Hdg2LAP'

    // Product: '<Root>/Product' incorporates:
    //   DataStoreWrite: '<Root>/WriteFlightMode_Log'
    //   Logic: '<Root>/AND'
    //   Logic: '<S1>/NOT'

    localDW->FlightMode_Log = static_cast<uint8_T>(static_cast<boolean_T>(
        static_cast<int32_T>(static_cast<int32_T>(static_cast<boolean_T>(
        static_cast<int32_T>(static_cast<int32_T>(rtu_ControlSwitch[1]) ^ 1))) &
        static_cast<int32_T>(RelationalOperator))) ? static_cast<int32_T>
        (*rtu_FlightMode) : 0);

    // End of Outputs for SubSystem: '<Root>/AvoidDanger'

    // BusCreator generated from: '<Root>/LoggingBus'
    rty_FlightLogging->VectorSpd.eastSpeed = *rtu_VecSpd_eastSpeed;
    rty_FlightLogging->VectorSpd.northSpeed = *rtu_VecSpd_northSpeed;
    rty_FlightLogging->VectorSpd.skySpeed = *rtu_VecSpd_skySpeed;

    // RelationalOperator: '<S2>/Compare' incorporates:
    //   Constant: '<S2>/Constant'

    RelationalOperator = (static_cast<int32_T>(*rtu_FlightMode) != 3);

    // BusCreator: '<Root>/CreatADRC' incorporates:
    //   DataStoreRead: '<Root>/ReadADRC_Log'

    rty_FlightLogging->ADRC_Log.x1_ControlError = localDW->ADRC_Log[0];
    rty_FlightLogging->ADRC_Log.x2 = localDW->ADRC_Log[1];
    rty_FlightLogging->ADRC_Log.x3_TotalDisturbance = localDW->ADRC_Log[2];
    rty_FlightLogging->ADRC_Log.u = localDW->ADRC_Log[3];

    // DataStoreRead: '<Root>/Data Store Read'
    rty_FCUCMD->RefGndSpd_mps = localDW->RefGndSpd;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Trigonometry: '<S70>/SinCos'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        localDW->SinCos_o1_f = 0.0;

        // Trigonometry: '<S70>/SinCos'
        localDW->SinCos_o2_b = 1.0;

        // MATLAB Function: '<S7>/ReadHomePoint'
        Real2SimGuidance_ReadHomePoint(localDW->LLA0,
            &localDW->sf_ReadHomePoint_p);

        // Switch: '<S81>/Switch' incorporates:
        //   Abs: '<S81>/Abs'
        //   Bias: '<S81>/Bias'
        //   Bias: '<S81>/Bias1'
        //   Constant: '<S81>/Constant2'
        //   Constant: '<S82>/Constant'
        //   Math: '<S81>/Math Function1'
        //   RelationalOperator: '<S82>/Compare'

        if (std::abs(localDW->LLA0[0]) > 180.0) {
            K_idx_0 = rt_modd_snf(localDW->LLA0[0] + 180.0, 360.0) - 180.0;
        } else {
            K_idx_0 = localDW->LLA0[0];
        }

        // End of Switch: '<S81>/Switch'

        // Abs: '<S78>/Abs1'
        rtb_Switch = std::abs(K_idx_0);

        // RelationalOperator: '<S80>/Compare' incorporates:
        //   Constant: '<S80>/Constant'

        rtb_Compare_j = (rtb_Switch > 90.0);

        // Switch: '<S78>/Switch'
        if (rtb_Compare_j) {
            // Signum: '<S78>/Sign1'
            if (std::isnan(K_idx_0)) {
                rtb_Sum1_idx_0 = (rtNaN);
            } else if (K_idx_0 < 0.0) {
                rtb_Sum1_idx_0 = -1.0;
            } else {
                rtb_Sum1_idx_0 = static_cast<real_T>(K_idx_0 > 0.0);
            }

            // Switch: '<S78>/Switch' incorporates:
            //   Bias: '<S78>/Bias'
            //   Bias: '<S78>/Bias1'
            //   Gain: '<S78>/Gain'
            //   Product: '<S78>/Divide1'
            //   Signum: '<S78>/Sign1'

            localDW->Switch_n = (-(rtb_Switch - 90.0) + 90.0) * rtb_Sum1_idx_0;
        } else {
            // Switch: '<S78>/Switch'
            localDW->Switch_n = K_idx_0;
        }

        // End of Switch: '<S78>/Switch'

        // UnitConversion: '<S86>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        K_idx_0 = 0.017453292519943295 * localDW->Switch_n;

        // Trigonometry: '<S87>/Trigonometric Function1'
        rtb_Switch_b = std::sin(K_idx_0);

        // Sum: '<S87>/Sum1' incorporates:
        //   Constant: '<S87>/Constant'
        //   Product: '<S87>/Product1'

        rtb_Switch_b = 1.0 - 0.0066943799901413295 * rtb_Switch_b * rtb_Switch_b;

        // Product: '<S84>/Product1' incorporates:
        //   Constant: '<S84>/Constant1'
        //   Sqrt: '<S84>/sqrt'

        rtb_Switch = 6.378137E+6 / std::sqrt(rtb_Switch_b);

        // Trigonometry: '<S84>/Trigonometric Function1' incorporates:
        //   Constant: '<S84>/Constant2'
        //   Product: '<S84>/Product3'

        localDW->TrigonometricFunction1_l = rt_atan2d_snf(1.0, rtb_Switch *
            0.99330562000985867 / rtb_Switch_b);

        // Trigonometry: '<S84>/Trigonometric Function2' incorporates:
        //   Constant: '<S84>/Constant3'
        //   Product: '<S84>/Product4'
        //   Trigonometry: '<S84>/Trigonometric Function'

        localDW->TrigonometricFunction2_o = rt_atan2d_snf(1.0, rtb_Switch * std::
            cos(K_idx_0));
    }

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   Product: '<S70>/rad lat'
    //   Product: '<S70>/x*cos'
    //   Product: '<S70>/y*sin'
    //   Sum: '<S70>/Sum'

    rtb_LagDistance = (rtb_biasH * localDW->SinCos_o2_b - rtb_Abs1 *
                       localDW->SinCos_o1_f) * localDW->TrigonometricFunction1_l;

    // Unit Conversion - from: rad to: deg
    // Expression: output = (57.2958*input) + (0)
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Switch: '<S69>/Switch1' incorporates:
        //   Constant: '<S69>/Constant'
        //   Constant: '<S69>/Constant1'

        if (rtb_Compare_j) {
            i = 180;
        } else {
            i = 0;
        }

        // Sum: '<S69>/Sum' incorporates:
        //   Switch: '<S69>/Switch1'

        K_idx_0 = static_cast<real_T>(i) + localDW->LLA0[1];

        // Switch: '<S79>/Switch' incorporates:
        //   Abs: '<S79>/Abs'
        //   Constant: '<S83>/Constant'
        //   RelationalOperator: '<S83>/Compare'

        if (std::abs(K_idx_0) > 180.0) {
            // Switch: '<S79>/Switch' incorporates:
            //   Bias: '<S79>/Bias'
            //   Bias: '<S79>/Bias1'
            //   Constant: '<S79>/Constant2'
            //   Math: '<S79>/Math Function1'

            localDW->Switch_m = rt_modd_snf(K_idx_0 + 180.0, 360.0) - 180.0;
        } else {
            // Switch: '<S79>/Switch'
            localDW->Switch_m = K_idx_0;
        }

        // End of Switch: '<S79>/Switch'
    }

    // Sum: '<S66>/Sum' incorporates:
    //   UnitConversion: '<S71>/Unit Conversion'

    K_idx_0 = 57.295779513082323 * rtb_LagDistance + localDW->Switch_n;

    // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
    //   Abs: '<S75>/Abs'

    rtb_LagDistance = std::abs(K_idx_0);

    // Switch: '<S75>/Switch' incorporates:
    //   Bias: '<S75>/Bias'
    //   Bias: '<S75>/Bias1'
    //   Constant: '<S75>/Constant2'
    //   Constant: '<S76>/Constant'
    //   Math: '<S75>/Math Function1'
    //   RelationalOperator: '<S76>/Compare'

    if (rtb_LagDistance > 180.0) {
        K_idx_0 = rt_modd_snf(K_idx_0 + 180.0, 360.0) - 180.0;
    }

    // End of Switch: '<S75>/Switch'

    // Abs: '<S72>/Abs1'
    rtb_Switch = std::abs(K_idx_0);

    // Switch: '<S72>/Switch' incorporates:
    //   Constant: '<S68>/Constant'
    //   Constant: '<S68>/Constant1'
    //   Constant: '<S74>/Constant'
    //   RelationalOperator: '<S74>/Compare'
    //   Switch: '<S68>/Switch1'

    if (rtb_Switch > 90.0) {
        // Signum: '<S72>/Sign1'
        if (std::isnan(K_idx_0)) {
            rtb_Sum1_idx_0 = (rtNaN);
        } else if (K_idx_0 < 0.0) {
            rtb_Sum1_idx_0 = -1.0;
        } else {
            rtb_Sum1_idx_0 = static_cast<real_T>(K_idx_0 > 0.0);
        }

        // DataStoreRead: '<Root>/ReadLagDistance' incorporates:
        //   Bias: '<S72>/Bias'
        //   Bias: '<S72>/Bias1'
        //   Gain: '<S72>/Gain'
        //   Product: '<S72>/Divide1'
        //   Signum: '<S72>/Sign1'

        rtb_LagDistance = (-(rtb_Switch - 90.0) + 90.0) * rtb_Sum1_idx_0;
        i = 180;
    } else {
        // DataStoreRead: '<Root>/ReadLagDistance'
        rtb_LagDistance = K_idx_0;
        i = 0;
    }

    // End of Switch: '<S72>/Switch'

    // Sum: '<S68>/Sum' incorporates:
    //   Product: '<S70>/rad long '
    //   Product: '<S70>/x*sin'
    //   Product: '<S70>/y*cos'
    //   Sum: '<S66>/Sum'
    //   Sum: '<S70>/Sum1'
    //   Switch: '<S68>/Switch1'
    //   UnitConversion: '<S71>/Unit Conversion'

    rtb_Gain_p = ((rtb_biasH * localDW->SinCos_o1_f + rtb_Abs1 *
                   localDW->SinCos_o2_b) * localDW->TrigonometricFunction2_o *
                  57.295779513082323 + localDW->Switch_m) + static_cast<real_T>
        (i);

    // Switch: '<S73>/Switch' incorporates:
    //   Abs: '<S73>/Abs'
    //   Bias: '<S73>/Bias'
    //   Bias: '<S73>/Bias1'
    //   Constant: '<S73>/Constant2'
    //   Constant: '<S77>/Constant'
    //   Math: '<S73>/Math Function1'
    //   RelationalOperator: '<S77>/Compare'

    if (std::abs(rtb_Gain_p) > 180.0) {
        rtb_Gain_p = rt_modd_snf(rtb_Gain_p + 180.0, 360.0) - 180.0;
    }

    // End of Switch: '<S73>/Switch'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Gain: '<S7>/inverse'
        localDW->minusAltitudeGCS_l = -localDW->LLA0[2];
    }

    // Sum: '<S66>/Sum1' incorporates:
    //   Gain: '<S7>/Up2Down'

    rtb_EngagedFlag = rtb_BusAssignment.Height - localDW->minusAltitudeGCS_l;

    // Saturate: '<Root>/Saturation'
    if (rtb_EngagedFlag <= 80.0) {
        rtb_EngagedFlag = 80.0;
    }

    // End of Saturate: '<Root>/Saturation'

    // MATLAB Function: '<Root>/wrap2Pi'
    Real2SimGuidance_wrap2Pi(rtb_BusAssignment.HeadingAngle, &rtb_lambdaWrapped);

    // Gain: '<S8>/Gain'
    rty_FCUCMD->RefHdg_deg = 57.295779513082323 * rtb_lambdaWrapped;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // MATLAB Function: '<Root>/Get Nominal Flight Speed'
        // MATLAB Function 'Get Nominal Flight Speed': '<S5>:1'
        // '<S5>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->SingletonInstance_not_empty_e) ^ 1))) {
            localDW->SingletonInstance_n.AirSpeed = 35.0;
            localDW->SingletonInstance_n.MaxRollAngle = 0.3490658503988659;
            localDW->SingletonInstance_n.FlightPathAngleLimit[0] = -0.175;
            localDW->SingletonInstance_n.FlightPathAngleLimit[1] = 0.175;
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Sum1_idx_1 = Real2SimGuidance_fileManager(localDW);
            if (rtb_Sum1_idx_1 < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_b(rtb_Sum1_idx_1, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_n(rtb_Sum1_idx_1, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_b, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_c, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_3, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_3->size[0] * data_3->size[1]);
                    data_3->size[0] = 1;
                    data_3->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_3, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_3->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_3, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_c);
                    Real2SimGuidance_strtrim_o(tmp_c, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    i2 = 0;
                                    i1 = 0;
                                } else {
                                    i2 = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - i2);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(i2 + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_b);
                                Real2SimGuidance_strtrim_o(tmp_b, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bg(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_3);
                Real2SimGuidance_emxFree_char_T_o(&tmp_c);
                Real2SimGuidance_emxFree_char_T_o(&tmp_b);
            }

            inputArg_data = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV NormAirSpeed:\t\t%f\n", inputArg_data.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            b_fid = Real2SimGuidance_fileManager(localDW);
            if (b_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_b(b_fid, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_n(b_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_9, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_a, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_2, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_2->size[0] * data_2->size[1]);
                    data_2->size[0] = 1;
                    data_2->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_2, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_2->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_2, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_a);
                    Real2SimGuidance_strtrim_o(tmp_a, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_9);
                                Real2SimGuidance_strtrim_o(tmp_9, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bgl(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_2);
                Real2SimGuidance_emxFree_char_T_o(&tmp_a);
                Real2SimGuidance_emxFree_char_T_o(&tmp_9);
            }

            tmp_1 = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_1.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            rtb_Switch = Real2SimGuidance_fileManager(localDW);
            if (rtb_Switch < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_b(rtb_Switch, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_n(rtb_Switch, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_7, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_8, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_1, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_1->size[0] * data_1->size[1]);
                    data_1->size[0] = 1;
                    data_1->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_1, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_1->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_1, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_8);
                    Real2SimGuidance_strtrim_o(tmp_8, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_7);
                                Real2SimGuidance_strtrim_o(tmp_7, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bglv(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_1);
                Real2SimGuidance_emxFree_char_T_o(&tmp_8);
                Real2SimGuidance_emxFree_char_T_o(&tmp_7);
            }

            tmp_1 = Real2SimGuidance_str2double_k(ret);
            printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_1.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            d_fid = Real2SimGuidance_fileManager(localDW);
            if (d_fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                Real2SimGuidance_fread_b(d_fid, k, localDW);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                Real2SimGuidance_emxEnsureCapacity_char_T_g(data, i);
                coffset = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++) {
                    data->data[i] = k->data[i];
                }

                Real2SimGuidance_cfclose_n(d_fid, localDW);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                Real2SimGuidance_emxInit_char_T_e(&tmp_5, 2);
                Real2SimGuidance_emxInit_char_T_e(&tmp_6, 2);
                Real2SimGuidance_emxInit_char_T_e(&data_0, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                    data_0->size[0] = 1;
                    data_0->size[1] = data->size[1];
                    Real2SimGuidance_emxEnsureCapacity_char_T_g(data_0, i);
                    i2 = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                        * data->size[1]) - 1);
                    for (i = 0; i <= i2; i++) {
                        data_0->data[i] = data->data[i];
                    }

                    Real2SimGuidance_strtok_o(data_0, curLine, data);
                    Real2SimGuidance_strtok_ow(curLine, tmp_6);
                    Real2SimGuidance_strtrim_o(tmp_6, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_HdgStatus = false;
                        if (curLine->data[0] == '[') {
                            rtb_HdgStatus = true;
                        }

                        guard1 = false;
                        if (rtb_HdgStatus) {
                            rtb_HdgStatus = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_HdgStatus = true;
                            }

                            if (rtb_HdgStatus) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    iy = 0;
                                    i1 = 0;
                                } else {
                                    iy = 1;
                                    i1 = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                coffset = static_cast<int32_T>(i1 - iy);
                                curSection->size[1] = coffset;
                                Real2SimGuidance_emxEnsureCapacity_char_T_g
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(coffset -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(iy + i)];
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
                                rtb_HdgStatus = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_HdgStatus) ^ 1))) &&
                                Real2SimGuidance_contains_f(curLine)) {
                                Real2SimGuidance_strtok_owf(curLine, curVal,
                                    aTmp);
                                Real2SimGuidance_strtrim_o(curVal, curKey);
                                Real2SimGuidance_strtok_ilmz(aTmp, tmp_5);
                                Real2SimGuidance_strtrim_o(tmp_5, curVal);
                            }
                        }
                    }

                    if (Real2SimGuidance_strcmp_b(curSection) &&
                            Real2SimGuidance_strcmp_bglv3(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        Real2SimGuidance_emxEnsureCapacity_char_T_g(ret, i);
                        coffset = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(coffset - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                Real2SimGuidance_emxFree_char_T_o(&data_0);
                Real2SimGuidance_emxFree_char_T_o(&tmp_6);
                Real2SimGuidance_emxFree_char_T_o(&tmp_5);
            }

            tmp_1 = Real2SimGuidance_str2double_k(ret);
            d_fid = 0.017453292519943295 * tmp_1.re;
            printf("Set UAV MaxRollAngle:\t\t%f\n", d_fid);
            fflush(stdout);
            Real2SimGuidance_readINI(ret, localDW);
            tmp_1 = Real2SimGuidance_str2double_k(ret);
            rtb_Sum1_idx_1 = 0.017453292519943295 * tmp_1.re;
            printf("Set UAV ClimbAngleLimit:\t%f\n", rtb_Sum1_idx_1);
            fflush(stdout);
            Real2SimGuidance_readINI_p(ret, localDW);
            tmp_1 = Real2SimGuidance_str2double_k(ret);
            b_fid = 0.017453292519943295 * tmp_1.re;
            printf("Set UAV DiveAngleLimit:\t\t%f\n", b_fid);
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
                    (std::isnan(rtb_Sum1_idx_1)) ^ 1))) &&
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isnan(b_fid)) ^ 1)))) {
                localDW->SingletonInstance_n.FlightPathAngleLimit[0] = b_fid;
                localDW->SingletonInstance_n.FlightPathAngleLimit[1] =
                    rtb_Sum1_idx_1;
            }

            Real2SimGuidance_uavDubinsConnection_uavDubinsConnection
                (&localDW->SingletonInstance_n.Connector,
                 localDW->SingletonInstance_n.AirSpeed,
                 localDW->SingletonInstance_n.MaxRollAngle);
            localDW->SingletonInstance_not_empty_e = true;
        }

        localDW->NominalSpeed = localDW->SingletonInstance_n.Connector.AirSpeed;

        // End of MATLAB Function: '<Root>/Get Nominal Flight Speed'
    }

    Real2SimGuidance_emxFree_char_T_o(&k);
    Real2SimGuidance_emxFree_char_T_o(&curLine);
    Real2SimGuidance_emxFree_char_T_o(&curVal);
    Real2SimGuidance_emxFree_char_T_o(&curKey);
    Real2SimGuidance_emxFree_char_T_o(&curSection);
    Real2SimGuidance_emxFree_char_T_o(&data);
    Real2SimGuidance_emxFree_char_T_o(&ret);
    Real2SimGuidance_emxFree_char_T_o(&aTmp);

    // BusCreator: '<Root>/FcuCmdBus'
    rty_FCUCMD->RefLatitude_deg = rtb_LagDistance;
    rty_FCUCMD->RefLongitude_deg = rtb_Gain_p;
    rty_FCUCMD->RefHeight_meter = rtb_EngagedFlag;

    // Switch: '<Root>/Switch' incorporates:
    //   Switch: '<S1>/SwitchSpdControl'

    if (RelationalOperator) {
        // BusCreator: '<Root>/FcuCmdBus'
        rty_FCUCMD->RefAirSpd_mps = localDW->NominalSpeed;

        // Outputs for Atomic SubSystem: '<Root>/AvoidDanger'
    } else if (rtu_ControlSwitch[1]) {
        // Switch: '<S1>/SwitchSpdControl' incorporates:
        //   BusCreator: '<Root>/FcuCmdBus'

        rty_FCUCMD->RefAirSpd_mps = rtb_BusAssignment.AirSpeed;
    } else {
        // BusCreator: '<Root>/FcuCmdBus' incorporates:
        //   Switch: '<S1>/SwitchSpdControl'

        rty_FCUCMD->RefAirSpd_mps = usedInputGain;

        // End of Outputs for SubSystem: '<Root>/AvoidDanger'
    }

    // End of Switch: '<Root>/Switch'

    // DataStoreRead: '<Root>/ReadLagDistance'
    rtb_LagDistance = localDW->LagDistance;

    // DataStoreRead: '<Root>/ReadFlightMode_Log'
    rty_FlightLogging->InnerState.FlightMode = localDW->FlightMode_Log;

    // BusCreator: '<Root>/InnerStateBus' incorporates:
    //   DataStoreRead: '<Root>/ReadAvoidDanger'
    //   DataStoreRead: '<Root>/ReadCrossTrackError'
    //   DataStoreRead: '<Root>/ReadEngagedFlag_Log'
    //   DataStoreRead: '<Root>/ReadHeading_Log'
    //   DataStoreRead: '<Root>/ReadStatus_Log'
    //   DataStoreRead: '<Root>/ReadbiasH_Log'

    rty_FlightLogging->InnerState.LagDistance = rtb_LagDistance;
    rty_FlightLogging->InnerState.CrossTrackError = localDW->CrossTrackError;
    rty_FlightLogging->InnerState.EngagedFlag = localDW->EngagedFlag;
    rty_FlightLogging->InnerState.RealHeading = localDW->Heading_Log[1];
    rty_FlightLogging->InnerState.TargetHeading = localDW->Heading_Log[2];
    rty_FlightLogging->InnerState.HeadingDiff = localDW->Heading_Log[0];
    rty_FlightLogging->InnerState.biasH = localDW->biasH_Log;
    rty_FlightLogging->InnerState.HdgStatus = localDW->HdgStatus_Log;
    rty_FlightLogging->InnerState.AvoidDanger = localDW->AvoidDanger;
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // MATLAB Function: '<Root>/TimeNow'
        // MATLAB Function 'TimeNow': '<S12>:1'
        // '<S12>:1:3'
        Real2SimGuidance_getLocalTime(&K_idx_0, &rtb_Switch, &rtb_Abs1,
            &rtb_biasH, &rtb_Switch_b, &usedInputGain, &Gain, &rtb_Compare_j);
        rtb_Gain_p = rtb_Abs1;
        rtb_UpperBound = rtb_Switch;
        rtb_EngagedFlag = K_idx_0 / 1.0E+6;
        K_idx_0 = rtb_Switch;
        rtb_Switch = rtb_EngagedFlag;
        rtb_Abs1 = (((((Gain + usedInputGain) + rtb_Switch_b) + rtb_biasH) +
                     rtb_Abs1) + rtb_UpperBound) + rtb_EngagedFlag;
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(rtb_Abs1)) ^ 1))) & static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(rtb_Abs1)) ^ 1)))))) {
            rtb_Sum1_idx_1 = Gain;
            rtb_Abs1 = usedInputGain;
            if ((usedInputGain < 1.0) || (usedInputGain > 12.0)) {
                rtb_Abs1 = std::floor((usedInputGain - 1.0) / 12.0);
                rtb_Sum1_idx_1 = Gain + rtb_Abs1;
                rtb_Abs1 = ((usedInputGain - 1.0) - rtb_Abs1 * 12.0) + 1.0;
            }

            if (rtb_Abs1 < 3.0) {
                rtb_Sum1_idx_1--;
                rtb_Abs1 += 9.0;
            } else {
                rtb_Abs1 -= 3.0;
            }

            if ((rtb_EngagedFlag < 0.0) || (rtb_EngagedFlag >= 1000.0)) {
                rtb_Switch = std::floor(rtb_EngagedFlag / 1000.0);
                K_idx_0 = rtb_UpperBound + rtb_Switch;
                rtb_Switch = rtb_EngagedFlag - rtb_Switch * 1000.0;
            }

            tmp_4.re = ((((((365.0 * rtb_Sum1_idx_1 + std::floor(rtb_Sum1_idx_1 /
                              4.0)) - std::floor(rtb_Sum1_idx_1 / 100.0)) + std::
                           floor(rtb_Sum1_idx_1 / 400.0)) + std::floor((153.0 *
                            rtb_Abs1 + 2.0) / 5.0)) + rtb_Switch_b) + 60.0) -
                719529.0;
            tmp_4.im = 0.0;
            inputArg_data = Real2SimGuidance_plus(Real2SimGuidance_plus
                (Real2SimGuidance_plus(Real2SimGuidance_times(tmp_4), (60.0 *
                rtb_biasH + rtb_Gain_p) * 60000.0), K_idx_0 * 1000.0),
                rtb_Switch);
        } else {
            inputArg_data.re = rtb_Abs1;
            inputArg_data.im = 0.0;
        }

        Real2SimGuidance_getDateVec(inputArg_data, &Gain, &K_idx_0, &rtb_Switch,
            &rtb_Abs1, &rtb_biasH, &rtb_Switch_b);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Switch, &K_idx_0,
            &rtb_Abs1, &rtb_biasH, &rtb_Switch_b, &usedInputGain);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Abs1, &rtb_biasH,
            &rtb_Switch, &rtb_Switch_b, &usedInputGain, &rtb_UpperBound);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_biasH, &rtb_Switch_b,
            &usedInputGain, &rtb_Abs1, &rtb_UpperBound, &rtb_EngagedFlag);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_Switch_b, &usedInputGain,
            &rtb_UpperBound, &rtb_EngagedFlag, &rtb_biasH, &rtb_RefRngmMinRng);
        Real2SimGuidance_getDateVec(inputArg_data, &usedInputGain,
            &rtb_UpperBound, &rtb_EngagedFlag, &rtb_RefRngmMinRng, &rtb_Gain_p,
            &rtb_Switch_b);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_UpperBound,
            &rtb_EngagedFlag, &rtb_RefRngmMinRng, &rtb_Gain_p, &rtb_Sum1_idx_1,
            &usedInputGain);
        Real2SimGuidance_getDateVec(inputArg_data, &rtb_UpperBound,
            &rtb_EngagedFlag, &rtb_RefRngmMinRng, &rtb_Gain_p, &rtb_Sum1_idx_1,
            &b_fid);
        rtb_Sum1_idx_0 = std::round(Gain);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                localDW->CurrentTime.year = static_cast<int32_T>(rtb_Sum1_idx_0);
            } else {
                localDW->CurrentTime.year = MIN_int32_T;
            }
        } else {
            localDW->CurrentTime.year = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round(K_idx_0);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                localDW->CurrentTime.month = static_cast<int32_T>(rtb_Sum1_idx_0);
            } else {
                localDW->CurrentTime.month = MIN_int32_T;
            }
        } else {
            localDW->CurrentTime.month = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round(rtb_Switch);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                localDW->CurrentTime.day = static_cast<int32_T>(rtb_Sum1_idx_0);
            } else {
                localDW->CurrentTime.day = MIN_int32_T;
            }
        } else {
            localDW->CurrentTime.day = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round(rtb_Abs1);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                localDW->CurrentTime.hour = static_cast<int32_T>(rtb_Sum1_idx_0);
            } else {
                localDW->CurrentTime.hour = MIN_int32_T;
            }
        } else {
            localDW->CurrentTime.hour = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round(rtb_biasH);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                localDW->CurrentTime.minute = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                localDW->CurrentTime.minute = MIN_int32_T;
            }
        } else {
            localDW->CurrentTime.minute = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::floor(rtb_Switch_b);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                localDW->CurrentTime.second = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                localDW->CurrentTime.second = MIN_int32_T;
            }
        } else {
            localDW->CurrentTime.second = MAX_int32_T;
        }

        rtb_Sum1_idx_0 = std::round((usedInputGain - std::floor(b_fid)) * 1000.0);
        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                localDW->CurrentTime.millisecond = static_cast<int32_T>
                    (rtb_Sum1_idx_0);
            } else {
                localDW->CurrentTime.millisecond = MIN_int32_T;
            }
        } else {
            localDW->CurrentTime.millisecond = MAX_int32_T;
        }

        // End of MATLAB Function: '<Root>/TimeNow'
    }

    // BusCreator: '<Root>/LoggingBus'
    rty_FlightLogging->RealUAVState = *rtu_FlightState;
    rty_FlightLogging->SimUAVState = *rtu_SimUAVState;
    rty_FlightLogging->FlightCMD = *rty_FCUCMD;
    rty_FlightLogging->TimeNow = localDW->CurrentTime;
}

// Update for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const boolean_T *rtu_NewMission, const
    FixedWingGuidanceStateBus *rtu_SimUAVState, DW_Real2SimGuidance_f_T *localDW)
{
    // Update for Atomic SubSystem: '<Root>/Real2SimNav'
    // Update for Atomic SubSystem: '<S9>/HeadingNaNProtection'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Switch: '<S96>/HeightSwitch' incorporates:
        //   RelationalOperator: '<S96>/IsNaN'

        if (std::isnan(localDW->SwitchLookAheadNED[2])) {
            // Update for Memory: '<S96>/MemoryRefHeight' incorporates:
            //   Constant: '<S96>/DefaultHeight'

            localDW->MemoryRefHeight_PreviousInput = -150.0;
        } else {
            // Update for Memory: '<S96>/MemoryRefHeight'
            localDW->MemoryRefHeight_PreviousInput = localDW->
                SwitchLookAheadNED[2];
        }

        // End of Switch: '<S96>/HeightSwitch'

        // Update for Memory: '<S9>/MemoryNotInBrake'
        localDW->MemoryNotInBrake_PreviousInput = localDW->Compare;

        // Update for Atomic SubSystem: '<S9>/GenerateTrack'
        for (int_T i{0}; i < 215; i++) {
            // Update for S-Function (sfix_udelay): '<S94>/EastSequence' incorporates:
            //   S-Function (sfix_udelay): '<S94>/HeightSequence'
            //   S-Function (sfix_udelay): '<S94>/NorthSequence'

            localDW->EastSequence_X[i] = localDW->EastSequence_X
                [static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S94>/HeightSequence' incorporates:
            //   S-Function (sfix_udelay): '<S94>/EastSequence'
            //   S-Function (sfix_udelay): '<S94>/NorthSequence'

            localDW->HeightSequence_X[i] = localDW->HeightSequence_X[
                static_cast<int_T>(i + 1)];

            // Update for S-Function (sfix_udelay): '<S94>/NorthSequence' incorporates:
            //   S-Function (sfix_udelay): '<S94>/EastSequence'
            //   S-Function (sfix_udelay): '<S94>/HeightSequence'

            localDW->NorthSequence_X[i] = localDW->NorthSequence_X
                [static_cast<int_T>(i + 1)];
        }

        // Update for S-Function (sfix_udelay): '<S94>/EastSequence'
        localDW->EastSequence_X[215] = rtu_SimUAVState->East;

        // Update for S-Function (sfix_udelay): '<S94>/HeightSequence'
        localDW->HeightSequence_X[215] = rtu_SimUAVState->Height;

        // Update for S-Function (sfix_udelay): '<S94>/NorthSequence'
        localDW->NorthSequence_X[215] = rtu_SimUAVState->North;

        // End of Update for SubSystem: '<S9>/GenerateTrack'

        // Update for Memory: '<S9>/Memory'
        localDW->Memory_PreviousInput = localDW->Engaged;
    }

    // End of Update for SubSystem: '<S9>/HeadingNaNProtection'

    // Update for Atomic SubSystem: '<S9>/SpeedControl'
    // Update for Enabled SubSystem: '<S99>/SpdFBControl' incorporates:
    //   EnablePort: '<S118>/Enable'

    if (localDW->SpdFBControl_MODE && rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Update for Enabled SubSystem: '<S118>/PID' incorporates:
        //   EnablePort: '<S122>/Enable'

        if (localDW->PID_MODE) {
            // Update for Delay: '<S161>/UD'
            localDW->UD_DSTATE = localDW->Tsamp;

            // Update for DiscreteIntegrator: '<S168>/Integrator'
            localDW->Integrator_DSTATE += 0.1 * localDW->IProdOut;
        }

        // End of Update for SubSystem: '<S118>/PID'
    }

    // End of Update for SubSystem: '<S99>/SpdFBControl'
    // End of Update for SubSystem: '<S9>/SpeedControl'

    // Update for Atomic SubSystem: '<S9>/HeadingLogic'
    // Update for Atomic SubSystem: '<S95>/NewMissionHdg'
    if (rtmIsMajorTimeStep(Real2SimGuidance_M)) {
        // Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S103>/Constant'

        localDW->DiscreteTimeIntegrator_DSTATE += 0.5;
        if (localDW->DiscreteTimeIntegrator_DSTATE >= 108.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = 108.0;
        }

        localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
            (*rtu_NewMission);

        // End of Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' 

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

    // End of Update for SubSystem: '<S95>/NewMissionHdg'
    // End of Update for SubSystem: '<S9>/HeadingLogic'
    // End of Update for SubSystem: '<Root>/Real2SimNav'
}

// Derivatives for referenced model: 'Real2SimGuidance'
void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot)
{
    // Derivatives for Atomic SubSystem: '<Root>/Real2SimNav'
    // Derivatives for Atomic SubSystem: '<S9>/SpeedControl'
    // Derivatives for Enabled SubSystem: '<S99>/SpdFBControl'
    if (localDW->SpdFBControl_MODE) {
        // Derivatives for Enabled SubSystem: '<S118>/ADRC'
        if (localDW->ADRC_MODE) {
            // Derivatives for Integrator: '<S124>/Integrator'
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

        // End of Derivatives for SubSystem: '<S118>/ADRC'
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

    // End of Derivatives for SubSystem: '<S99>/SpdFBControl'
    // End of Derivatives for SubSystem: '<S9>/SpeedControl'

    // Derivatives for Integrator: '<S100>/TD_Alt'
    localXdot->TD_Alt_CSTATE = localDW->dotAltTD;

    // Derivatives for Integrator: '<S100>/dotAltTD'
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
