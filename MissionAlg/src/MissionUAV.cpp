//
// File: MissionUAV.cpp
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 4.1
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 16:44:56 2022
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
#include "MissionUAV.h"
#include "rtwtypes.h"
#include "MissionUAV_types.h"
#include <stdio.h>
#include <cmath>
#include <cstring>
#include "rt_atan2d_snf.h"
#include <stddef.h>
#include <cstdlib>
#include "zero_crossing_types.h"
#include "MissionUAV_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Forward declaration for local functions
static void MissionUAV_Model_resetImpl
    (robotics_core_internal_system_navigation_Model_MissionUAV_T *obj);
static void MissionUAV_emxInit_char_T(emxArray_char_T_MissionUAV_T **pEmxArray,
    int32_T numDimensions);
static int8_T MissionUAV_filedata_h(DW_MissionUAV_f_T *localDW);
static int8_T MissionUAV_cfopen_b(const char_T *cfilename, const char_T
    *cpermission, DW_MissionUAV_f_T *localDW);
static real_T MissionUAV_fileManager_c(DW_MissionUAV_f_T *localDW);
static void MissionUAV_emxEnsureCapacity_char_T(emxArray_char_T_MissionUAV_T
    *emxArray, int32_T oldNumel);
static void MissionUAV_fread_j(real_T fileID, emxArray_char_T_MissionUAV_T *A,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_copysign(emxArray_char_T_MissionUAV_T *s1, int32_T *idx,
    const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n, boolean_T
    *foundsign, boolean_T *success);
static boolean_T MissionUAV_isUnitImag(const emxArray_char_T_MissionUAV_T *s,
    int32_T k, int32_T n);
static void MissionUAV_readNonFinite(const emxArray_char_T_MissionUAV_T *s,
    int32_T *k, int32_T n, boolean_T *b_finite, real_T *fv);
static boolean_T MissionUAV_copydigits(emxArray_char_T_MissionUAV_T *s1, int32_T
    *idx, const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n,
    boolean_T allowpoint);
static boolean_T MissionUAV_copyexponent(emxArray_char_T_MissionUAV_T *s1,
    int32_T *idx, const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n);
static void MissionUAV_readfloat(emxArray_char_T_MissionUAV_T *s1, int32_T *idx,
    const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n, boolean_T
    *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
    *success);
static void MissionUAV_emxFree_char_T(emxArray_char_T_MissionUAV_T **pEmxArray);
static creal_T MissionUAV_str2double(const emxArray_char_T_MissionUAV_T *s);
static int32_T MissionUAV_cfclose_g(real_T fid, DW_MissionUAV_f_T *localDW);
static void MissionUAV_strtok(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token, emxArray_char_T_MissionUAV_T *remain);
static void MissionUAV_strtok_l(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token);
static void MissionUAV_strtrim(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *y);
static boolean_T MissionUAV_strcmp(const emxArray_char_T_MissionUAV_T *a);
static boolean_T MissionUAV_strcmp_j(const emxArray_char_T_MissionUAV_T *a);
static boolean_T MissionUAV_contains(const emxArray_char_T_MissionUAV_T *str);
static void MissionUAV_find_token(const emxArray_char_T_MissionUAV_T *x, int32_T
    *itoken, int32_T *iremain);
static void MissionUAV_strtok_ls(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token, emxArray_char_T_MissionUAV_T *remain);
static void MissionUAV_readINI_o(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_readINI_oa(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_strtok_lse(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token);
static boolean_T MissionUAV_strcmp_jn(const emxArray_char_T_MissionUAV_T *a);
static boolean_T MissionUAV_strcmp_jng(const emxArray_char_T_MissionUAV_T *a);
static uavDubinsConnection_MissionUAV_T
    *MissionUAV_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_MissionUAV_T *b_this, real_T varargin_2, real_T
     varargin_4);
static int8_T MissionUAV_filedata(DW_MissionUAV_f_T *localDW);
static int8_T MissionUAV_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_MissionUAV_f_T *localDW);
static real_T MissionUAV_fileManager(DW_MissionUAV_f_T *localDW);
static void MissionUAV_fread(real_T fileID, emxArray_char_T_MissionUAV_T *A,
    DW_MissionUAV_f_T *localDW);
static boolean_T MissionUAV_strcmp_jngk(const emxArray_char_T_MissionUAV_T *a);
static int32_T MissionUAV_cfclose(real_T fid, DW_MissionUAV_f_T *localDW);
static void MissionUAV_readINI(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_readINI_k(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW);

//
// Outputs for atomic system:
//    '<S8>/TD_Bank'
//    '<S8>/dotBankTD'
//
void MissionUAV_TD_Bank(const real_T *rtu_Reset, real_T *rty_OutputY, real_T
                        rtp_deltaT, DW_TD_Bank_MissionUAV_T *localDW,
                        ZCE_TD_Bank_MissionUAV_T *localZCE)
{
    real_T rtb_Gain_b;
    boolean_T rtb_NOT_a;

    // Delay: '<S10>/DelayInput'
    if (static_cast<boolean_T>(static_cast<int32_T>((rt_ZCFcn(ANY_ZERO_CROSSING,
            &localZCE->DelayInput_Reset_ZCE,
            (*rtu_Reset)) != NO_ZCEVENT) | (*rtu_Reset != 0.0)))) {
        localDW->DelayInput_DSTATE = 0.0;
    }

    // Gain: '<S10>/Gain' incorporates:
    //   Delay: '<S10>/DelayInput'

    rtb_Gain_b = rtp_deltaT * localDW->DelayInput_DSTATE;

    // Logic: '<S10>/NOT'
    rtb_NOT_a = static_cast<boolean_T>(static_cast<int32_T>((*rtu_Reset != 0.0) ^
        1));

    // Delay: '<S10>/DelayOutput'
    if (static_cast<boolean_T>(static_cast<int32_T>((rt_ZCFcn(ANY_ZERO_CROSSING,
            &localZCE->DelayOutput_Reset_ZCE,
            (*rtu_Reset)) != NO_ZCEVENT) | (*rtu_Reset != 0.0)))) {
        localDW->DelayOutput_DSTATE = 0.0;
    }

    // Sum: '<S10>/AddY' incorporates:
    //   Delay: '<S10>/DelayOutput'
    //   Product: '<S10>/Product'

    *rty_OutputY = rtb_Gain_b * static_cast<real_T>(rtb_NOT_a) +
        localDW->DelayOutput_DSTATE;
}

//
// Update for atomic system:
//    '<S8>/TD_Bank'
//    '<S8>/dotBankTD'
//
void MissionUAV_TD_Bank_Update(real_T rtu_InputU, real_T *rty_OutputY,
    DW_TD_Bank_MissionUAV_T *localDW)
{
    // Update for Delay: '<S10>/DelayInput'
    localDW->DelayInput_DSTATE = rtu_InputU;

    // Update for Delay: '<S10>/DelayOutput'
    localDW->DelayOutput_DSTATE = *rty_OutputY;
}

static void MissionUAV_Model_resetImpl
    (robotics_core_internal_system_navigation_Model_MissionUAV_T *obj)
{
    obj->ModelImpl.Configuration.PHeight = 4.0;
    obj->ModelImpl.Configuration.PFlightPathAngle = 12.0;
    obj->ModelImpl.Configuration.PAirSpeed = 1.0;
    obj->ModelImpl.Configuration.PDRoll[0] = 300.0;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -0.3490658503988659;
    obj->ModelImpl.Configuration.PDRoll[1] = 30.0;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 0.3490658503988659;
}

static void MissionUAV_emxInit_char_T(emxArray_char_T_MissionUAV_T **pEmxArray,
    int32_T numDimensions)
{
    emxArray_char_T_MissionUAV_T *emxArray;
    *pEmxArray = static_cast<emxArray_char_T_MissionUAV_T *>(std::malloc(sizeof
        (emxArray_char_T_MissionUAV_T)));
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

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static int8_T MissionUAV_filedata_h(DW_MissionUAV_f_T *localDW)
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (localDW->eml_openfiles_a[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static int8_T MissionUAV_cfopen_b(const char_T *cfilename, const char_T
    *cpermission, DW_MissionUAV_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = MissionUAV_filedata_h(localDW);
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            localDW->eml_openfiles_a[static_cast<int32_T>(static_cast<int32_T>(j)
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

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static real_T MissionUAV_fileManager_c(DW_MissionUAV_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = MissionUAV_cfopen_b("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
}

static void MissionUAV_emxEnsureCapacity_char_T(emxArray_char_T_MissionUAV_T
    *emxArray, int32_T oldNumel)
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

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static void MissionUAV_fread_j(real_T fileID, emxArray_char_T_MissionUAV_T *A,
    DW_MissionUAV_f_T *localDW)
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
        filestar = localDW->eml_openfiles_a[static_cast<int32_T>
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
            MissionUAV_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_copysign(emxArray_char_T_MissionUAV_T *s1, int32_T *idx,
    const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n, boolean_T
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_isUnitImag(const emxArray_char_T_MissionUAV_T *s,
    int32_T k, int32_T n)
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_readNonFinite(const emxArray_char_T_MissionUAV_T *s,
    int32_T *k, int32_T n, boolean_T *b_finite, real_T *fv)
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_copydigits(emxArray_char_T_MissionUAV_T *s1, int32_T
    *idx, const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n,
    boolean_T allowpoint)
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_copyexponent(emxArray_char_T_MissionUAV_T *s1,
    int32_T *idx, const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n)
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
            b_success = MissionUAV_copydigits(s1, idx, s, &b_k, n, false);
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_readfloat(emxArray_char_T_MissionUAV_T *s1, int32_T *idx,
    const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n, boolean_T
    *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
    *success)
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
    MissionUAV_copysign(s1, &b_idx, s, &b_k, n, foundsign, success);
    *idx = b_idx;
    *k = b_k;
    if (*success) {
        char_T tmp;
        boolean_T exitg1;
        if (MissionUAV_isUnitImag(s, b_k, n)) {
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
                MissionUAV_copysign(s1, &b_idx, s, &b_k, n, &a__3, success);
                *idx = b_idx;
                if (*success) {
                    if (MissionUAV_isUnitImag(s, b_k, n)) {
                        *success = false;
                    } else {
                        MissionUAV_readNonFinite(s, &b_k, n, b_finite, nfv);
                        if (*b_finite) {
                            *success = MissionUAV_copydigits(s1, idx, s, &b_k, n,
                                true);
                            if (*success) {
                                *success = MissionUAV_copyexponent(s1, idx, s,
                                    &b_k, n);
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
            MissionUAV_readNonFinite(s, &b_k, n, b_finite, nfv);
            *k = b_k;
            if (*b_finite) {
                *success = MissionUAV_copydigits(s1, idx, s, k, n, true);
                if (*success) {
                    *success = MissionUAV_copyexponent(s1, idx, s, k, n);
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

static void MissionUAV_emxFree_char_T(emxArray_char_T_MissionUAV_T **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_char_T_MissionUAV_T *>(nullptr)) {
        if (((*pEmxArray)->data != static_cast<char_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_char_T_MissionUAV_T *>(nullptr);
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static creal_T MissionUAV_str2double(const emxArray_char_T_MissionUAV_T *s)
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

    emxArray_char_T_MissionUAV_T *s1;
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
        MissionUAV_emxInit_char_T(&s1, 2);
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
        MissionUAV_emxEnsureCapacity_char_T(s1, i);
        idx = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(idx + 1); i++) {
            s1->data[i] = '\x00';
        }

        idx = 1;
        MissionUAV_readfloat(s1, &idx, s, &k, s->size[1], &isimag1, &isfinite1,
                             &scanned1, &a__1, &success);
        if (isfinite1) {
            ntoread = 1;
        }

        if (success) {
            if (k <= s->size[1]) {
                s1->data[static_cast<int32_T>(idx - 1)] = ' ';
                idx = static_cast<int32_T>(idx + 1);
                MissionUAV_readfloat(s1, &idx, s, &k, s->size[1], &a__1,
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

        MissionUAV_emxFree_char_T(&s1);
    }

    return x;
}

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static int32_T MissionUAV_cfclose_g(real_T fid, DW_MissionUAV_f_T *localDW)
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
        filestar = localDW->eml_openfiles_a[static_cast<int32_T>
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
            localDW->eml_openfiles_a[static_cast<int32_T>(static_cast<int32_T>
                (fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_strtok(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token, emxArray_char_T_MissionUAV_T *remain)
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
    MissionUAV_emxEnsureCapacity_char_T(remain, i);
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
    MissionUAV_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_strtok_l(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token)
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
    MissionUAV_emxEnsureCapacity_char_T(token, itoken);
    for (itoken = 0; itoken <= static_cast<int32_T>(k - 1); itoken++) {
        token->data[itoken] = x->data[static_cast<int32_T>(n + itoken)];
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_strtrim(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *y)
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
    MissionUAV_emxEnsureCapacity_char_T(y, i);
    for (i = 0; i <= j2; i++) {
        y->data[i] = x->data[static_cast<int32_T>(b_j1 + i)];
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_strcmp(const emxArray_char_T_MissionUAV_T *a)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    MissionUAV_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        MissionUAV_emxEnsureCapacity_char_T(aTmp, i);
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

    MissionUAV_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_strcmp_j(const emxArray_char_T_MissionUAV_T *a)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    MissionUAV_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        MissionUAV_emxEnsureCapacity_char_T(aTmp, i);
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

    MissionUAV_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_contains(const emxArray_char_T_MissionUAV_T *str)
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_find_token(const emxArray_char_T_MissionUAV_T *x, int32_T
    *itoken, int32_T *iremain)
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_strtok_ls(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token, emxArray_char_T_MissionUAV_T *remain)
{
    int32_T b;
    int32_T c;
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    MissionUAV_find_token(x, &itoken, &iremain);
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
    MissionUAV_emxEnsureCapacity_char_T(remain, i);
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
    MissionUAV_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static void MissionUAV_readINI_o(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    emxArray_char_T_MissionUAV_T *curKey;
    emxArray_char_T_MissionUAV_T *curLine;
    emxArray_char_T_MissionUAV_T *curSection;
    emxArray_char_T_MissionUAV_T *curVal;
    emxArray_char_T_MissionUAV_T *data;
    emxArray_char_T_MissionUAV_T *data_0;
    emxArray_char_T_MissionUAV_T *j;
    emxArray_char_T_MissionUAV_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = MissionUAV_cfopen_b("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        MissionUAV_emxInit_char_T(&j, 1);
        MissionUAV_fread_j(static_cast<real_T>(fileid), j, localDW);
        MissionUAV_emxInit_char_T(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        MissionUAV_emxEnsureCapacity_char_T(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        MissionUAV_emxFree_char_T(&j);
        MissionUAV_cfclose_g(static_cast<real_T>(fileid), localDW);
        MissionUAV_emxInit_char_T(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        MissionUAV_emxInit_char_T(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        MissionUAV_emxInit_char_T(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        MissionUAV_emxInit_char_T(&curLine, 2);
        MissionUAV_emxInit_char_T(&aTmp, 2);
        MissionUAV_emxInit_char_T(&tmp, 2);
        MissionUAV_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_l(curLine, tmp);
                MissionUAV_strtrim(tmp, curLine);
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
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
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
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, aTmp, curVal);
                            MissionUAV_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            MissionUAV_strtrim(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curLine, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            MissionUAV_strtrim(curLine, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(aTmp, i_0);
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
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
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

        MissionUAV_emxFree_char_T(&data_0);
        MissionUAV_emxFree_char_T(&tmp);
        MissionUAV_emxFree_char_T(&aTmp);
        MissionUAV_emxFree_char_T(&curLine);
        MissionUAV_emxFree_char_T(&curVal);
        MissionUAV_emxFree_char_T(&curKey);
        MissionUAV_emxFree_char_T(&curSection);
        MissionUAV_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static void MissionUAV_readINI_oa(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    emxArray_char_T_MissionUAV_T *curKey;
    emxArray_char_T_MissionUAV_T *curLine;
    emxArray_char_T_MissionUAV_T *curSection;
    emxArray_char_T_MissionUAV_T *curVal;
    emxArray_char_T_MissionUAV_T *data;
    emxArray_char_T_MissionUAV_T *data_0;
    emxArray_char_T_MissionUAV_T *j;
    emxArray_char_T_MissionUAV_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = MissionUAV_cfopen_b("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        MissionUAV_emxInit_char_T(&j, 1);
        MissionUAV_fread_j(static_cast<real_T>(fileid), j, localDW);
        MissionUAV_emxInit_char_T(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        MissionUAV_emxEnsureCapacity_char_T(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        MissionUAV_emxFree_char_T(&j);
        MissionUAV_cfclose_g(static_cast<real_T>(fileid), localDW);
        MissionUAV_emxInit_char_T(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        MissionUAV_emxInit_char_T(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        MissionUAV_emxInit_char_T(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        MissionUAV_emxInit_char_T(&curLine, 2);
        MissionUAV_emxInit_char_T(&aTmp, 2);
        MissionUAV_emxInit_char_T(&tmp, 2);
        MissionUAV_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_l(curLine, tmp);
                MissionUAV_strtrim(tmp, curLine);
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
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
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
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, aTmp, curVal);
                            MissionUAV_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            MissionUAV_strtrim(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curLine, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            MissionUAV_strtrim(curLine, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(aTmp, i_0);
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
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
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

        MissionUAV_emxFree_char_T(&data_0);
        MissionUAV_emxFree_char_T(&tmp);
        MissionUAV_emxFree_char_T(&aTmp);
        MissionUAV_emxFree_char_T(&curLine);
        MissionUAV_emxFree_char_T(&curVal);
        MissionUAV_emxFree_char_T(&curKey);
        MissionUAV_emxFree_char_T(&curSection);
        MissionUAV_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_strtok_lse(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token)
{
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    MissionUAV_find_token(x, &itoken, &iremain);
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
    MissionUAV_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(iremain - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_strcmp_jn(const emxArray_char_T_MissionUAV_T *a)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    MissionUAV_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        MissionUAV_emxEnsureCapacity_char_T(aTmp, i);
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

    MissionUAV_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_strcmp_jng(const emxArray_char_T_MissionUAV_T *a)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    MissionUAV_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        MissionUAV_emxEnsureCapacity_char_T(aTmp, i);
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

    MissionUAV_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static uavDubinsConnection_MissionUAV_T
    *MissionUAV_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_MissionUAV_T *b_this, real_T varargin_2, real_T
     varargin_4)
{
    uavDubinsConnection_MissionUAV_T *c_this;
    c_this = b_this;
    b_this->AirSpeed = 10.0;
    b_this->MaxRollAngle = varargin_4;
    b_this->AirSpeed = varargin_2;
    return c_this;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static int8_T MissionUAV_filedata(DW_MissionUAV_f_T *localDW)
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static int8_T MissionUAV_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_MissionUAV_f_T *localDW)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = MissionUAV_filedata(localDW);
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static real_T MissionUAV_fileManager(DW_MissionUAV_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = MissionUAV_cfopen("config.ini", "rb", localDW);
    f = static_cast<real_T>(fileid);
    return f;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_fread(real_T fileID, emxArray_char_T_MissionUAV_T *A,
    DW_MissionUAV_f_T *localDW)
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
            MissionUAV_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_strcmp_jngk(const emxArray_char_T_MissionUAV_T *a)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    MissionUAV_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        MissionUAV_emxEnsureCapacity_char_T(aTmp, i);
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

    MissionUAV_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static int32_T MissionUAV_cfclose(real_T fid, DW_MissionUAV_f_T *localDW)
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

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_readINI(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    emxArray_char_T_MissionUAV_T *curKey;
    emxArray_char_T_MissionUAV_T *curLine;
    emxArray_char_T_MissionUAV_T *curSection;
    emxArray_char_T_MissionUAV_T *curVal;
    emxArray_char_T_MissionUAV_T *data;
    emxArray_char_T_MissionUAV_T *data_0;
    emxArray_char_T_MissionUAV_T *j;
    emxArray_char_T_MissionUAV_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = MissionUAV_cfopen("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        MissionUAV_emxInit_char_T(&j, 1);
        MissionUAV_fread(static_cast<real_T>(fileid), j, localDW);
        MissionUAV_emxInit_char_T(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        MissionUAV_emxEnsureCapacity_char_T(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        MissionUAV_emxFree_char_T(&j);
        MissionUAV_cfclose(static_cast<real_T>(fileid), localDW);
        MissionUAV_emxInit_char_T(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        MissionUAV_emxInit_char_T(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        MissionUAV_emxInit_char_T(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        MissionUAV_emxInit_char_T(&curLine, 2);
        MissionUAV_emxInit_char_T(&aTmp, 2);
        MissionUAV_emxInit_char_T(&tmp, 2);
        MissionUAV_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_l(curLine, tmp);
                MissionUAV_strtrim(tmp, curLine);
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
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
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
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, aTmp, curVal);
                            MissionUAV_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            MissionUAV_strtrim(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curLine, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            MissionUAV_strtrim(curLine, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(aTmp, i_0);
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
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
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

        MissionUAV_emxFree_char_T(&data_0);
        MissionUAV_emxFree_char_T(&tmp);
        MissionUAV_emxFree_char_T(&aTmp);
        MissionUAV_emxFree_char_T(&curLine);
        MissionUAV_emxFree_char_T(&curVal);
        MissionUAV_emxFree_char_T(&curKey);
        MissionUAV_emxFree_char_T(&curSection);
        MissionUAV_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static void MissionUAV_readINI_k(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW)
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

    emxArray_char_T_MissionUAV_T *aTmp;
    emxArray_char_T_MissionUAV_T *curKey;
    emxArray_char_T_MissionUAV_T *curLine;
    emxArray_char_T_MissionUAV_T *curSection;
    emxArray_char_T_MissionUAV_T *curVal;
    emxArray_char_T_MissionUAV_T *data;
    emxArray_char_T_MissionUAV_T *data_0;
    emxArray_char_T_MissionUAV_T *j;
    emxArray_char_T_MissionUAV_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = MissionUAV_cfopen("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        MissionUAV_emxInit_char_T(&j, 1);
        MissionUAV_fread(static_cast<real_T>(fileid), j, localDW);
        MissionUAV_emxInit_char_T(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        MissionUAV_emxEnsureCapacity_char_T(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        MissionUAV_emxFree_char_T(&j);
        MissionUAV_cfclose(static_cast<real_T>(fileid), localDW);
        MissionUAV_emxInit_char_T(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        MissionUAV_emxInit_char_T(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        MissionUAV_emxInit_char_T(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        MissionUAV_emxInit_char_T(&curLine, 2);
        MissionUAV_emxInit_char_T(&aTmp, 2);
        MissionUAV_emxInit_char_T(&tmp, 2);
        MissionUAV_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_l(curLine, tmp);
                MissionUAV_strtrim(tmp, curLine);
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
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
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
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, aTmp, curVal);
                            MissionUAV_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            MissionUAV_strtrim(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curLine, i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            MissionUAV_strtrim(curLine, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(aTmp, i_0);
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
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
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

        MissionUAV_emxFree_char_T(&data_0);
        MissionUAV_emxFree_char_T(&tmp);
        MissionUAV_emxFree_char_T(&aTmp);
        MissionUAV_emxFree_char_T(&curLine);
        MissionUAV_emxFree_char_T(&curVal);
        MissionUAV_emxFree_char_T(&curKey);
        MissionUAV_emxFree_char_T(&curSection);
        MissionUAV_emxFree_char_T(&data);
    }
}

// System initialize for referenced model: 'MissionUAV'
void MissionUAV_Init(DW_MissionUAV_f_T *localDW)
{
    FILE* a;

    // SystemInitialize for MATLAB Function: '<S1>/Get Speed Limit'
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles_a[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S1>/Get Speed Limit'

    // SystemInitialize for Atomic SubSystem: '<S1>/MissionUAV'
    // SystemInitialize for Atomic SubSystem: '<S5>/DiscreteIntegrator'
    // InitializeConditions for Delay: '<S9>/DelayOutput'
    localDW->icLoad = true;

    // End of SystemInitialize for SubSystem: '<S5>/DiscreteIntegrator'

    // Start for MATLABSystem: '<S5>/ComputeDerivative'
    localDW->objisempty_a = true;
    localDW->obj_j.isInitialized = 1;
    MissionUAV_Model_resetImpl(&localDW->obj_j);

    // InitializeConditions for MATLABSystem: '<S5>/ComputeDerivative'
    MissionUAV_Model_resetImpl(&localDW->obj_j);

    // Start for MATLABSystem: '<S5>/StateVector2Struct'
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S5>/StateVector2Struct'
    localDW->obj.OutputTemplate.North = 0.0;
    localDW->obj.OutputTemplate.East = 0.0;
    localDW->obj.OutputTemplate.Height = 0.0;
    localDW->obj.OutputTemplate.AirSpeed = 0.0;
    localDW->obj.OutputTemplate.HeadingAngle = 0.0;
    localDW->obj.OutputTemplate.FlightPathAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngleRate = 0.0;

    // End of SystemInitialize for SubSystem: '<S1>/MissionUAV'

    // SystemInitialize for MATLAB Function: '<S1>/Get Max Bank'
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S1>/Get Max Bank'
}

// Output and update for referenced model: 'MissionUAV'
void MissionUAV(const real_T *rtu_ResetState, const real_T rtu_StartPos[8],
                const real_T *rtu_UAVGuidanceCmd_Height, const real_T
                *rtu_UAVGuidanceCmd_AirSpeed, const real_T
                *rtu_UAVGuidanceCmd_HeadingAngle, real_T *rty_SimUAVState_North,
                real_T *rty_SimUAVState_East, real_T *rty_SimUAVState_Height,
                real_T *rty_SimUAVState_AirSpeed, real_T
                *rty_SimUAVState_HeadingAngle, real_T
                *rty_SimUAVState_FlightPathAngle, real_T
                *rty_SimUAVState_RollAngle, real_T
                *rty_SimUAVState_RollAngleRate, DW_MissionUAV_f_T *localDW,
                ZCE_MissionUAV_T *localZCE)
{
    emxArray_char_T_MissionUAV_T *b_remainder;
    emxArray_char_T_MissionUAV_T *curKey;
    emxArray_char_T_MissionUAV_T *curLine;
    emxArray_char_T_MissionUAV_T *curSection;
    emxArray_char_T_MissionUAV_T *curVal;
    emxArray_char_T_MissionUAV_T *data;
    emxArray_char_T_MissionUAV_T *data_0;
    emxArray_char_T_MissionUAV_T *data_1;
    emxArray_char_T_MissionUAV_T *data_2;
    emxArray_char_T_MissionUAV_T *data_3;
    emxArray_char_T_MissionUAV_T *data_4;
    emxArray_char_T_MissionUAV_T *data_5;
    emxArray_char_T_MissionUAV_T *data_6;
    emxArray_char_T_MissionUAV_T *data_7;
    emxArray_char_T_MissionUAV_T *k;
    emxArray_char_T_MissionUAV_T *ret;
    emxArray_char_T_MissionUAV_T *tmp_3;
    emxArray_char_T_MissionUAV_T *tmp_4;
    emxArray_char_T_MissionUAV_T *tmp_5;
    emxArray_char_T_MissionUAV_T *tmp_6;
    emxArray_char_T_MissionUAV_T *tmp_7;
    emxArray_char_T_MissionUAV_T *tmp_8;
    emxArray_char_T_MissionUAV_T *tmp_9;
    emxArray_char_T_MissionUAV_T *tmp_a;
    emxArray_char_T_MissionUAV_T *tmp_b;
    emxArray_char_T_MissionUAV_T *tmp_c;
    emxArray_char_T_MissionUAV_T *tmp_d;
    emxArray_char_T_MissionUAV_T *tmp_e;
    emxArray_char_T_MissionUAV_T *tmp_f;
    emxArray_char_T_MissionUAV_T *tmp_g;
    emxArray_char_T_MissionUAV_T *tmp_h;
    emxArray_char_T_MissionUAV_T *tmp_i;
    creal_T tmp;
    creal_T tmp_0;
    real_T rtb_AddY[8];
    real_T AddY_p;
    real_T DiveAngleLimit;
    real_T SpdLmt_idx_0;
    real_T b_fid;
    real_T b_fid_tmp;
    real_T b_tmp;
    real_T c_fid;
    real_T c_fid_tmp;
    real_T d_fid;
    real_T fid;
    int32_T c;
    int32_T i;
    int32_T i_0;
    int32_T loop_ub;
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T rtb_LowerRelop1;

    // MATLAB Function 'MissionUAV/Get Speed Limit': '<S3>:1'
    // '<S3>:1:3'
    MissionUAV_emxInit_char_T(&ret, 2);
    MissionUAV_emxInit_char_T(&data, 2);
    MissionUAV_emxInit_char_T(&curSection, 2);
    MissionUAV_emxInit_char_T(&curKey, 2);
    MissionUAV_emxInit_char_T(&curVal, 2);
    MissionUAV_emxInit_char_T(&curLine, 2);
    MissionUAV_emxInit_char_T(&b_remainder, 2);
    MissionUAV_emxInit_char_T(&k, 1);

    // MATLAB Function: '<S1>/Get Speed Limit'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (localDW->SingletonInstance_not_empty) ^ 1))) {
        creal_T tmp_1;
        creal_T tmp_2;
        localDW->SingletonInstance.AirSpeed = 35.0;
        localDW->SingletonInstance.MaxRollAngle = 0.3490658503988659;
        localDW->SingletonInstance.FlightPathAngleLimit[0] = -0.175;
        localDW->SingletonInstance.FlightPathAngleLimit[1] = 0.175;
        localDW->SingletonInstance.SpdLmt[0] = 29.0;
        localDW->SingletonInstance.SpdLmt[1] = 46.0;
        ret->size[0] = 1;
        ret->size[1] = 0;
        fid = MissionUAV_fileManager_c(localDW);
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            MissionUAV_fread_j(fid, k, localDW);
            i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            MissionUAV_emxEnsureCapacity_char_T(data, i_0);
            loop_ub = k->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = k->data[i];
            }

            MissionUAV_cfclose_g(fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            MissionUAV_emxInit_char_T(&tmp_h, 2);
            MissionUAV_emxInit_char_T(&tmp_i, 2);
            MissionUAV_emxInit_char_T(&data_7, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i_0 = static_cast<int32_T>(data_7->size[0] * data_7->size[1]);
                data_7->size[0] = 1;
                data_7->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_7, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_7->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_7, curLine, data);
                MissionUAV_strtok_l(curLine, tmp_i);
                MissionUAV_strtrim(tmp_i, curLine);
                if (curLine->size[1] >= 2) {
                    rtb_LowerRelop1 = false;
                    if (curLine->data[0] == '[') {
                        rtb_LowerRelop1 = true;
                    }

                    guard1 = false;
                    if (rtb_LowerRelop1) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            rtb_LowerRelop1 = true;
                        }

                        if (rtb_LowerRelop1) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                i = 0;
                            } else {
                                c = 1;
                                i = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(i - c);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(c + i)];
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
                            rtb_LowerRelop1 = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_LowerRelop1) ^ 1))) &&
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, curVal, b_remainder);
                            MissionUAV_strtrim(curVal, curKey);
                            MissionUAV_strtok_lse(b_remainder, tmp_h);
                            MissionUAV_strtrim(tmp_h, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_j(curKey))
                {
                    i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            MissionUAV_emxFree_char_T(&data_7);
            MissionUAV_emxFree_char_T(&tmp_i);
            MissionUAV_emxFree_char_T(&tmp_h);
        }

        tmp = MissionUAV_str2double(ret);
        printf("Set UAV NormAirSpeed:\t\t%f\n", tmp.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        b_fid = MissionUAV_fileManager_c(localDW);
        if (b_fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            MissionUAV_fread_j(b_fid, k, localDW);
            i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            MissionUAV_emxEnsureCapacity_char_T(data, i_0);
            loop_ub = k->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = k->data[i];
            }

            MissionUAV_cfclose_g(b_fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            MissionUAV_emxInit_char_T(&tmp_f, 2);
            MissionUAV_emxInit_char_T(&tmp_g, 2);
            MissionUAV_emxInit_char_T(&data_6, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i_0 = static_cast<int32_T>(data_6->size[0] * data_6->size[1]);
                data_6->size[0] = 1;
                data_6->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_6, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_6->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_6, curLine, data);
                MissionUAV_strtok_l(curLine, tmp_g);
                MissionUAV_strtrim(tmp_g, curLine);
                if (curLine->size[1] >= 2) {
                    rtb_LowerRelop1 = false;
                    if (curLine->data[0] == '[') {
                        rtb_LowerRelop1 = true;
                    }

                    guard1 = false;
                    if (rtb_LowerRelop1) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            rtb_LowerRelop1 = true;
                        }

                        if (rtb_LowerRelop1) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                i = 0;
                            } else {
                                c = 1;
                                i = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(i - c);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(c + i)];
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
                            rtb_LowerRelop1 = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_LowerRelop1) ^ 1))) &&
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, curVal, b_remainder);
                            MissionUAV_strtrim(curVal, curKey);
                            MissionUAV_strtok_lse(b_remainder, tmp_f);
                            MissionUAV_strtrim(tmp_f, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_jn(curKey))
                {
                    i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            MissionUAV_emxFree_char_T(&data_6);
            MissionUAV_emxFree_char_T(&tmp_g);
            MissionUAV_emxFree_char_T(&tmp_f);
        }

        tmp_0 = MissionUAV_str2double(ret);
        printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_0.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        c_fid = MissionUAV_fileManager_c(localDW);
        if (c_fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            MissionUAV_fread_j(c_fid, k, localDW);
            i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            MissionUAV_emxEnsureCapacity_char_T(data, i_0);
            loop_ub = k->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = k->data[i];
            }

            MissionUAV_cfclose_g(c_fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            MissionUAV_emxInit_char_T(&tmp_d, 2);
            MissionUAV_emxInit_char_T(&tmp_e, 2);
            MissionUAV_emxInit_char_T(&data_5, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i_0 = static_cast<int32_T>(data_5->size[0] * data_5->size[1]);
                data_5->size[0] = 1;
                data_5->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_5, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_5->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_5, curLine, data);
                MissionUAV_strtok_l(curLine, tmp_e);
                MissionUAV_strtrim(tmp_e, curLine);
                if (curLine->size[1] >= 2) {
                    rtb_LowerRelop1 = false;
                    if (curLine->data[0] == '[') {
                        rtb_LowerRelop1 = true;
                    }

                    guard1 = false;
                    if (rtb_LowerRelop1) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            rtb_LowerRelop1 = true;
                        }

                        if (rtb_LowerRelop1) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                i = 0;
                            } else {
                                c = 1;
                                i = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(i - c);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(c + i)];
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
                            rtb_LowerRelop1 = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_LowerRelop1) ^ 1))) &&
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, curVal, b_remainder);
                            MissionUAV_strtrim(curVal, curKey);
                            MissionUAV_strtok_lse(b_remainder, tmp_d);
                            MissionUAV_strtrim(tmp_d, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_jng
                        (curKey)) {
                    i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            MissionUAV_emxFree_char_T(&data_5);
            MissionUAV_emxFree_char_T(&tmp_e);
            MissionUAV_emxFree_char_T(&tmp_d);
        }

        tmp_1 = MissionUAV_str2double(ret);
        printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_1.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        d_fid = MissionUAV_fileManager_c(localDW);
        if (d_fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            MissionUAV_fread_j(d_fid, k, localDW);
            i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            MissionUAV_emxEnsureCapacity_char_T(data, i_0);
            loop_ub = k->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = k->data[i];
            }

            MissionUAV_cfclose_g(d_fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            MissionUAV_emxInit_char_T(&tmp_b, 2);
            MissionUAV_emxInit_char_T(&tmp_c, 2);
            MissionUAV_emxInit_char_T(&data_4, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i_0 = static_cast<int32_T>(data_4->size[0] * data_4->size[1]);
                data_4->size[0] = 1;
                data_4->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_4, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_4->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_4, curLine, data);
                MissionUAV_strtok_l(curLine, tmp_c);
                MissionUAV_strtrim(tmp_c, curLine);
                if (curLine->size[1] >= 2) {
                    rtb_LowerRelop1 = false;
                    if (curLine->data[0] == '[') {
                        rtb_LowerRelop1 = true;
                    }

                    guard1 = false;
                    if (rtb_LowerRelop1) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            rtb_LowerRelop1 = true;
                        }

                        if (rtb_LowerRelop1) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                i = 0;
                            } else {
                                c = 1;
                                i = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(i - c);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(c + i)];
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
                            rtb_LowerRelop1 = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_LowerRelop1) ^ 1))) &&
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, curVal, b_remainder);
                            MissionUAV_strtrim(curVal, curKey);
                            MissionUAV_strtok_lse(b_remainder, tmp_b);
                            MissionUAV_strtrim(tmp_b, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_jngk
                        (curKey)) {
                    i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            MissionUAV_emxFree_char_T(&data_4);
            MissionUAV_emxFree_char_T(&tmp_c);
            MissionUAV_emxFree_char_T(&tmp_b);
        }

        tmp_2 = MissionUAV_str2double(ret);
        d_fid = 0.017453292519943295 * tmp_2.re;
        printf("Set UAV MaxRollAngle:\t\t%f\n", d_fid);
        fflush(stdout);
        MissionUAV_readINI_o(ret, localDW);
        tmp_2 = MissionUAV_str2double(ret);
        b_fid = 0.017453292519943295 * tmp_2.re;
        printf("Set UAV ClimbAngleLimit:\t%f\n", b_fid);
        fflush(stdout);
        MissionUAV_readINI_oa(ret, localDW);
        tmp_2 = MissionUAV_str2double(ret);
        DiveAngleLimit = 0.017453292519943295 * tmp_2.re;
        printf("Set UAV DiveAngleLimit:\t\t%f\n", DiveAngleLimit);
        fflush(stdout);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(tmp.re)) ^ 1))) {
            localDW->SingletonInstance.AirSpeed = tmp.re;
        }

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(d_fid)) ^ 1))) {
            localDW->SingletonInstance.MaxRollAngle = d_fid;
        }

        if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (std::isnan(b_fid)) ^ 1))) && (static_cast<boolean_T>(
                static_cast<int32_T>(static_cast<int32_T>(std::isnan
                (DiveAngleLimit)) ^ 1)))) {
            localDW->SingletonInstance.FlightPathAngleLimit[0] = DiveAngleLimit;
            localDW->SingletonInstance.FlightPathAngleLimit[1] = b_fid;
        }

        if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (std::isnan(tmp_0.re)) ^ 1))) && (static_cast<boolean_T>(
                static_cast<int32_T>(static_cast<int32_T>(std::isnan(tmp_1.re)) ^
               1)))) {
            localDW->SingletonInstance.SpdLmt[0] = tmp_1.re;
            localDW->SingletonInstance.SpdLmt[1] = tmp_0.re;
        }

        MissionUAV_uavDubinsConnection_uavDubinsConnection
            (&localDW->SingletonInstance.Connector,
             localDW->SingletonInstance.AirSpeed,
             localDW->SingletonInstance.MaxRollAngle);
        localDW->SingletonInstance_not_empty = true;
    }

    SpdLmt_idx_0 = localDW->SingletonInstance.SpdLmt[0];
    c_fid = localDW->SingletonInstance.SpdLmt[1];

    // End of MATLAB Function: '<S1>/Get Speed Limit'

    // MinMax: '<S1>/Max'
    fid = std::fmax(SpdLmt_idx_0, c_fid);

    // RelationalOperator: '<S7>/LowerRelop1' incorporates:
    //   MinMax: '<S1>/Max'

    rtb_LowerRelop1 = (*rtu_UAVGuidanceCmd_AirSpeed > fid);

    // Switch: '<S7>/Switch2'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (rtb_LowerRelop1) ^ 1))) {
        // MinMax: '<S1>/Min'
        AddY_p = std::fmin(SpdLmt_idx_0, c_fid);

        // RelationalOperator: '<S7>/UpperRelop' incorporates:
        //   MinMax: '<S1>/Min'

        rtb_LowerRelop1 = (*rtu_UAVGuidanceCmd_AirSpeed < AddY_p);

        // Switch: '<S7>/Switch' incorporates:
        //   MinMax: '<S1>/Min'

        if (rtb_LowerRelop1) {
            fid = AddY_p;
        } else {
            fid = *rtu_UAVGuidanceCmd_AirSpeed;
        }

        // End of Switch: '<S7>/Switch'
    }

    // End of Switch: '<S7>/Switch2'

    // Outputs for Atomic SubSystem: '<S8>/TD_Bank'
    MissionUAV_TD_Bank(rtu_ResetState, &AddY_p, 0.1, &localDW->TD_Bank,
                       &localZCE->TD_Bank);

    // End of Outputs for SubSystem: '<S8>/TD_Bank'

    // BusCreator: '<S1>/SlewGuidanceBus'
    b_fid = *rtu_UAVGuidanceCmd_Height;

    // Outputs for Atomic SubSystem: '<S1>/MissionUAV'
    // Outputs for Atomic SubSystem: '<S5>/DiscreteIntegrator'
    // Delay: '<S9>/DelayInput'
    if (static_cast<boolean_T>(static_cast<int32_T>((rt_ZCFcn(ANY_ZERO_CROSSING,
            &localZCE->DelayInput_Reset_ZCE_g,
            (*rtu_ResetState)) != NO_ZCEVENT) | (*rtu_ResetState != 0.0)))) {
        std::memset(&localDW->DelayInput_DSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));
    }

    // Logic: '<S9>/NOT'
    rtb_LowerRelop1 = static_cast<boolean_T>(static_cast<int32_T>
        ((*rtu_ResetState != 0.0) ^ 1));

    // Delay: '<S9>/DelayOutput'
    if (static_cast<boolean_T>(static_cast<int32_T>((rt_ZCFcn(ANY_ZERO_CROSSING,
            &localZCE->DelayOutput_Reset_ZCE_a,
            (*rtu_ResetState)) != NO_ZCEVENT) | (*rtu_ResetState != 0.0)))) {
        localDW->icLoad = true;
    }

    for (i = 0; i < 8; i++) {
        if (localDW->icLoad) {
            localDW->DelayOutput_DSTATE[i] = rtu_StartPos[i];
        }

        // Sum: '<S9>/AddY' incorporates:
        //   Delay: '<S9>/DelayInput'
        //   Gain: '<S9>/Gain'
        //   Product: '<S9>/Product'

        rtb_AddY[i] = 0.1 * localDW->DelayInput_DSTATE[i] * static_cast<real_T>
            (rtb_LowerRelop1) + localDW->DelayOutput_DSTATE[i];
    }

    // End of Delay: '<S9>/DelayOutput'
    // End of Outputs for SubSystem: '<S5>/DiscreteIntegrator'

    // MATLABSystem: '<S5>/ComputeDerivative' incorporates:
    //   BusCreator: '<S1>/FixedWingGuidanceEnvironmentBus'
    //   BusCreator: '<S1>/SlewGuidanceBus'
    //   Constant: '<S1>/Gravity'
    //   Constant: '<S1>/NoWind'
    //   Delay: '<S9>/DelayInput'
    //   MATLAB Function: '<S1>/Heading Control'
    //   Sum: '<S9>/AddY'

    DiveAngleLimit = std::cos(rtb_AddY[5]);
    c_fid_tmp = std::cos(rtb_AddY[4]);
    d_fid = std::sin(rtb_AddY[4]);
    b_fid_tmp = std::sin(rtb_AddY[5]);
    c_fid = (-(c_fid_tmp * DiveAngleLimit) * 0.0 + -(d_fid * DiveAngleLimit) *
             0.0) + b_fid_tmp * 0.0;
    b_tmp = 0.0 - rtb_AddY[3] * rtb_AddY[3];
    SpdLmt_idx_0 = std::sqrt(c_fid * c_fid - b_tmp) - c_fid;

    // Update for Atomic SubSystem: '<S5>/DiscreteIntegrator'
    localDW->DelayInput_DSTATE[0] = SpdLmt_idx_0 * c_fid_tmp * DiveAngleLimit;
    localDW->DelayInput_DSTATE[1] = SpdLmt_idx_0 * d_fid * DiveAngleLimit;

    // End of Update for SubSystem: '<S5>/DiscreteIntegrator'
    c_fid = SpdLmt_idx_0 * b_fid_tmp;

    // Update for Atomic SubSystem: '<S5>/DiscreteIntegrator'
    localDW->DelayInput_DSTATE[2] = c_fid;
    localDW->DelayInput_DSTATE[3] = (fid - rtb_AddY[3]) *
        localDW->obj_j.ModelImpl.Configuration.PAirSpeed;

    // End of Update for SubSystem: '<S5>/DiscreteIntegrator'
    if (SpdLmt_idx_0 == 0.0) {
        // Update for Atomic SubSystem: '<S5>/DiscreteIntegrator'
        localDW->DelayInput_DSTATE[4] = 0.0;
        localDW->DelayInput_DSTATE[5] = 0.0;

        // End of Update for SubSystem: '<S5>/DiscreteIntegrator'
    } else {
        if (rtb_AddY[3] == 0.0) {
            // Update for Atomic SubSystem: '<S5>/DiscreteIntegrator'
            localDW->DelayInput_DSTATE[4] = 0.0;

            // End of Update for SubSystem: '<S5>/DiscreteIntegrator'
        } else {
            fid = 1.0 / (std::cos(std::asin(c_fid / rtb_AddY[3])) * rtb_AddY[3]);

            // Update for Atomic SubSystem: '<S5>/DiscreteIntegrator'
            localDW->DelayInput_DSTATE[4] = std::cos(std::asin(fid * 0.0 *
                -d_fid + fid * 0.0 * c_fid_tmp)) * (9.807 / SpdLmt_idx_0 * std::
                tan(rtb_AddY[6]));

            // End of Update for SubSystem: '<S5>/DiscreteIntegrator'
        }

        // Update for Atomic SubSystem: '<S5>/DiscreteIntegrator'
        localDW->DelayInput_DSTATE[5] = (std::fmax(std::fmin(std::asin(std::fmax
            (std::fmin((b_fid - rtb_AddY[2]) *
                       localDW->obj_j.ModelImpl.Configuration.PHeight /
                       SpdLmt_idx_0, 1.0), -1.0)),
            localDW->obj_j.ModelImpl.Configuration.FlightPathAngleLimits[1]),
            localDW->obj_j.ModelImpl.Configuration.FlightPathAngleLimits[0]) -
            rtb_AddY[5]) *
            localDW->obj_j.ModelImpl.Configuration.PFlightPathAngle;

        // End of Update for SubSystem: '<S5>/DiscreteIntegrator'
    }

    // Update for Atomic SubSystem: '<S5>/DiscreteIntegrator'
    localDW->DelayInput_DSTATE[6] = rtb_AddY[7];
    localDW->DelayInput_DSTATE[7] = (std::fmax(std::fmin(AddY_p,
        1.5707963267948966), -1.5707963267948966) - rtb_AddY[6]) *
        localDW->obj_j.ModelImpl.Configuration.PDRoll[0] +
        localDW->obj_j.ModelImpl.Configuration.PDRoll[1] * -rtb_AddY[7];

    // Update for Delay: '<S9>/DelayOutput' incorporates:
    //   Sum: '<S9>/AddY'

    localDW->icLoad = false;
    std::memcpy(&localDW->DelayOutput_DSTATE[0], &rtb_AddY[0],
                static_cast<uint32_T>(sizeof(real_T) << 3U));

    // End of Update for SubSystem: '<S5>/DiscreteIntegrator'

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    *rty_SimUAVState_North = rtb_AddY[0];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    *rty_SimUAVState_East = rtb_AddY[1];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    *rty_SimUAVState_Height = rtb_AddY[2];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    *rty_SimUAVState_AirSpeed = rtb_AddY[3];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    *rty_SimUAVState_HeadingAngle = rtb_AddY[4];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    *rty_SimUAVState_FlightPathAngle = rtb_AddY[5];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    *rty_SimUAVState_RollAngle = rtb_AddY[6];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    *rty_SimUAVState_RollAngleRate = rtb_AddY[7];

    // MATLAB Function: '<S1>/Heading Control' incorporates:
    //   BusCreator: '<S1>/FixedWingGuidanceEnvironmentBus'
    //   Constant: '<S1>/Gravity'
    //   Constant: '<S1>/NoWind'
    //   MATLABSystem: '<S5>/ComputeDerivative'
    //   MATLABSystem: '<S5>/StateVector2Struct'
    //   Sum: '<S9>/AddY'

    // MATLAB Function 'Heading Control': '<S4>:1'
    // '<S4>:1:3'
    // '<S4>:1:4'
    // '<S4>:1:5'
    // '<S4>:1:7'
    fid = 1.0 / rtb_AddY[3];

    // '<S4>:1:8'
    DiveAngleLimit = (std::cos(rtb_AddY[4]) * std::cos(rtb_AddY[5]) * 0.0 + std::
                      sin(rtb_AddY[4]) * std::cos(rtb_AddY[5]) * 0.0) +
        -b_fid_tmp * 0.0;

    // '<S4>:1:9'
    // '<S4>:1:10'
    // '<S4>:1:12'
    b_fid = *rtu_UAVGuidanceCmd_HeadingAngle - rtb_AddY[4];

    // End of Outputs for SubSystem: '<S1>/MissionUAV'
    if (std::abs(b_fid) > 3.1415926535897931) {
        if (std::isnan(b_fid + 3.1415926535897931)) {
            c_fid = (rtNaN);
        } else if (std::isinf(b_fid + 3.1415926535897931)) {
            c_fid = (rtNaN);
        } else if (b_fid + 3.1415926535897931 == 0.0) {
            c_fid = 0.0;
        } else {
            c_fid = std::fmod(b_fid + 3.1415926535897931, 6.2831853071795862);
            rtb_LowerRelop1 = (c_fid == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_LowerRelop1) ^ 1))) {
                d_fid = std::abs((b_fid + 3.1415926535897931) /
                                 6.2831853071795862);
                rtb_LowerRelop1 = static_cast<boolean_T>(static_cast<int32_T>
                    ((std::abs(d_fid - std::floor(d_fid + 0.5)) >
                      2.2204460492503131E-16 * d_fid) ^ 1));
            }

            if (rtb_LowerRelop1) {
                c_fid = 0.0;
            } else if (b_fid + 3.1415926535897931 < 0.0) {
                c_fid += 6.2831853071795862;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((b_fid +
                3.1415926535897931 > 0.0) & (c_fid == 0.0)))) {
            c_fid = 6.2831853071795862;
        }

        b_fid = c_fid - 3.1415926535897931;
    }

    // Outputs for Atomic SubSystem: '<S1>/MissionUAV'
    SpdLmt_idx_0 = rt_atan2d_snf((std::sqrt(std::fmax(0.0, DiveAngleLimit *
        DiveAngleLimit - b_tmp)) - DiveAngleLimit) * b_fid, std::cos(rtb_AddY[4]
        - (rtb_AddY[4] - std::asin(fid * 0.0 * -std::sin(rtb_AddY[4]) + fid *
        0.0 * c_fid_tmp))) * 9.807);

    // End of Outputs for SubSystem: '<S1>/MissionUAV'

    // MATLAB Function: '<S1>/Get Max Bank'
    // MATLAB Function 'MissionUAV/Get Max Bank': '<S2>:1'
    // '<S2>:1:3'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (localDW->SingletonInstance_not_empty_p) ^ 1))) {
        localDW->SingletonInstance_p.AirSpeed = 35.0;
        localDW->SingletonInstance_p.MaxRollAngle = 0.3490658503988659;
        localDW->SingletonInstance_p.FlightPathAngleLimit[0] = -0.175;
        localDW->SingletonInstance_p.FlightPathAngleLimit[1] = 0.175;
        ret->size[0] = 1;
        ret->size[1] = 0;
        fid = MissionUAV_fileManager(localDW);
        if (fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            MissionUAV_fread(fid, k, localDW);
            i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            MissionUAV_emxEnsureCapacity_char_T(data, i_0);
            loop_ub = k->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = k->data[i];
            }

            MissionUAV_cfclose(fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            MissionUAV_emxInit_char_T(&tmp_9, 2);
            MissionUAV_emxInit_char_T(&tmp_a, 2);
            MissionUAV_emxInit_char_T(&data_3, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i_0 = static_cast<int32_T>(data_3->size[0] * data_3->size[1]);
                data_3->size[0] = 1;
                data_3->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_3, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_3->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_3, curLine, data);
                MissionUAV_strtok_l(curLine, tmp_a);
                MissionUAV_strtrim(tmp_a, curLine);
                if (curLine->size[1] >= 2) {
                    rtb_LowerRelop1 = false;
                    if (curLine->data[0] == '[') {
                        rtb_LowerRelop1 = true;
                    }

                    guard1 = false;
                    if (rtb_LowerRelop1) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            rtb_LowerRelop1 = true;
                        }

                        if (rtb_LowerRelop1) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                i = 0;
                            } else {
                                c = 1;
                                i = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(i - c);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(c + i)];
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
                            rtb_LowerRelop1 = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_LowerRelop1) ^ 1))) &&
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, curVal, b_remainder);
                            MissionUAV_strtrim(curVal, curKey);
                            MissionUAV_strtok_lse(b_remainder, tmp_9);
                            MissionUAV_strtrim(tmp_9, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_j(curKey))
                {
                    i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            MissionUAV_emxFree_char_T(&data_3);
            MissionUAV_emxFree_char_T(&tmp_a);
            MissionUAV_emxFree_char_T(&tmp_9);
        }

        tmp = MissionUAV_str2double(ret);
        printf("Set UAV NormAirSpeed:\t\t%f\n", tmp.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        b_fid = MissionUAV_fileManager(localDW);
        if (b_fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            MissionUAV_fread(b_fid, k, localDW);
            i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            MissionUAV_emxEnsureCapacity_char_T(data, i_0);
            loop_ub = k->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = k->data[i];
            }

            MissionUAV_cfclose(b_fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            MissionUAV_emxInit_char_T(&tmp_7, 2);
            MissionUAV_emxInit_char_T(&tmp_8, 2);
            MissionUAV_emxInit_char_T(&data_2, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i_0 = static_cast<int32_T>(data_2->size[0] * data_2->size[1]);
                data_2->size[0] = 1;
                data_2->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_2, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_2->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_2, curLine, data);
                MissionUAV_strtok_l(curLine, tmp_8);
                MissionUAV_strtrim(tmp_8, curLine);
                if (curLine->size[1] >= 2) {
                    rtb_LowerRelop1 = false;
                    if (curLine->data[0] == '[') {
                        rtb_LowerRelop1 = true;
                    }

                    guard1 = false;
                    if (rtb_LowerRelop1) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            rtb_LowerRelop1 = true;
                        }

                        if (rtb_LowerRelop1) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                i = 0;
                            } else {
                                c = 1;
                                i = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(i - c);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(c + i)];
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
                            rtb_LowerRelop1 = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_LowerRelop1) ^ 1))) &&
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, curVal, b_remainder);
                            MissionUAV_strtrim(curVal, curKey);
                            MissionUAV_strtok_lse(b_remainder, tmp_7);
                            MissionUAV_strtrim(tmp_7, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_jn(curKey))
                {
                    i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            MissionUAV_emxFree_char_T(&data_2);
            MissionUAV_emxFree_char_T(&tmp_8);
            MissionUAV_emxFree_char_T(&tmp_7);
        }

        tmp_0 = MissionUAV_str2double(ret);
        printf("Set UAV MaxAirSpeed:\t\t%f\n", tmp_0.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        c_fid = MissionUAV_fileManager(localDW);
        if (c_fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            MissionUAV_fread(c_fid, k, localDW);
            i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            MissionUAV_emxEnsureCapacity_char_T(data, i_0);
            loop_ub = k->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = k->data[i];
            }

            MissionUAV_cfclose(c_fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            MissionUAV_emxInit_char_T(&tmp_5, 2);
            MissionUAV_emxInit_char_T(&tmp_6, 2);
            MissionUAV_emxInit_char_T(&data_1, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i_0 = static_cast<int32_T>(data_1->size[0] * data_1->size[1]);
                data_1->size[0] = 1;
                data_1->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_1, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_1->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_1, curLine, data);
                MissionUAV_strtok_l(curLine, tmp_6);
                MissionUAV_strtrim(tmp_6, curLine);
                if (curLine->size[1] >= 2) {
                    rtb_LowerRelop1 = false;
                    if (curLine->data[0] == '[') {
                        rtb_LowerRelop1 = true;
                    }

                    guard1 = false;
                    if (rtb_LowerRelop1) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            rtb_LowerRelop1 = true;
                        }

                        if (rtb_LowerRelop1) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                i = 0;
                            } else {
                                c = 1;
                                i = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(i - c);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(c + i)];
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
                            rtb_LowerRelop1 = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_LowerRelop1) ^ 1))) &&
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, curVal, b_remainder);
                            MissionUAV_strtrim(curVal, curKey);
                            MissionUAV_strtok_lse(b_remainder, tmp_5);
                            MissionUAV_strtrim(tmp_5, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_jng
                        (curKey)) {
                    i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            MissionUAV_emxFree_char_T(&data_1);
            MissionUAV_emxFree_char_T(&tmp_6);
            MissionUAV_emxFree_char_T(&tmp_5);
        }

        tmp_0 = MissionUAV_str2double(ret);
        printf("Set UAV MinAirSpeed:\t\t%f\n", tmp_0.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        d_fid = MissionUAV_fileManager(localDW);
        if (d_fid < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            MissionUAV_fread(d_fid, k, localDW);
            i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = k->size[0];
            MissionUAV_emxEnsureCapacity_char_T(data, i_0);
            loop_ub = k->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = k->data[i];
            }

            MissionUAV_cfclose(d_fid, localDW);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            MissionUAV_emxInit_char_T(&tmp_3, 2);
            MissionUAV_emxInit_char_T(&tmp_4, 2);
            MissionUAV_emxInit_char_T(&data_0, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_l(curLine, tmp_4);
                MissionUAV_strtrim(tmp_4, curLine);
                if (curLine->size[1] >= 2) {
                    rtb_LowerRelop1 = false;
                    if (curLine->data[0] == '[') {
                        rtb_LowerRelop1 = true;
                    }

                    guard1 = false;
                    if (rtb_LowerRelop1) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[static_cast<int32_T>(curLine->size[1]
                                - 1)] == ']') {
                            rtb_LowerRelop1 = true;
                        }

                        if (rtb_LowerRelop1) {
                            if (static_cast<int32_T>(curLine->size[1] - 1) < 2)
                            {
                                c = 0;
                                i = 0;
                            } else {
                                c = 1;
                                i = static_cast<int32_T>(curLine->size[1] - 1);
                            }

                            i_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(i - c);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection, i_0);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(c + i)];
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
                            rtb_LowerRelop1 = true;
                        }

                        if ((static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_LowerRelop1) ^ 1))) &&
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_ls(curLine, curVal, b_remainder);
                            MissionUAV_strtrim(curVal, curKey);
                            MissionUAV_strtok_lse(b_remainder, tmp_3);
                            MissionUAV_strtrim(tmp_3, curVal);
                        }
                    }
                }

                if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_jngk
                        (curKey)) {
                    i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                    loop_ub = curVal->size[1];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            MissionUAV_emxFree_char_T(&data_0);
            MissionUAV_emxFree_char_T(&tmp_4);
            MissionUAV_emxFree_char_T(&tmp_3);
        }

        tmp_0 = MissionUAV_str2double(ret);
        d_fid = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV MaxRollAngle:\t\t%f\n", d_fid);
        fflush(stdout);
        MissionUAV_readINI(ret, localDW);
        tmp_0 = MissionUAV_str2double(ret);
        b_fid = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV ClimbAngleLimit:\t%f\n", b_fid);
        fflush(stdout);
        MissionUAV_readINI_k(ret, localDW);
        tmp_0 = MissionUAV_str2double(ret);
        DiveAngleLimit = 0.017453292519943295 * tmp_0.re;
        printf("Set UAV DiveAngleLimit:\t\t%f\n", DiveAngleLimit);
        fflush(stdout);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(tmp.re)) ^ 1))) {
            localDW->SingletonInstance_p.AirSpeed = tmp.re;
        }

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(d_fid)) ^ 1))) {
            localDW->SingletonInstance_p.MaxRollAngle = d_fid;
        }

        if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (std::isnan(b_fid)) ^ 1))) && (static_cast<boolean_T>(
                static_cast<int32_T>(static_cast<int32_T>(std::isnan
                (DiveAngleLimit)) ^ 1)))) {
            localDW->SingletonInstance_p.FlightPathAngleLimit[0] =
                DiveAngleLimit;
            localDW->SingletonInstance_p.FlightPathAngleLimit[1] = b_fid;
        }

        MissionUAV_uavDubinsConnection_uavDubinsConnection
            (&localDW->SingletonInstance_p.Connector,
             localDW->SingletonInstance_p.AirSpeed,
             localDW->SingletonInstance_p.MaxRollAngle);
        localDW->SingletonInstance_not_empty_p = true;
    }

    MissionUAV_emxFree_char_T(&k);
    MissionUAV_emxFree_char_T(&b_remainder);
    MissionUAV_emxFree_char_T(&curLine);
    MissionUAV_emxFree_char_T(&curVal);
    MissionUAV_emxFree_char_T(&curKey);
    MissionUAV_emxFree_char_T(&curSection);
    MissionUAV_emxFree_char_T(&data);
    MissionUAV_emxFree_char_T(&ret);

    // MATLAB Function: '<S1>/Get Max Bank'
    fid = localDW->SingletonInstance_p.Connector.MaxRollAngle;

    // MinMax: '<S1>/MinBankAng' incorporates:
    //   Constant: '<S1>/Constant'
    //   Gain: '<S1>/Gain'
    //   MATLAB Function: '<S1>/Get Max Bank'

    fid = std::fmin(0.78539816339744828, 57.295779513082323 * fid * 3.0);

    // Switch: '<S6>/Switch2' incorporates:
    //   RelationalOperator: '<S6>/LowerRelop1'

    if (static_cast<boolean_T>(static_cast<int32_T>((SpdLmt_idx_0 > fid) ^ 1)))
    {
        // Gain: '<S1>/Inverse'
        fid = -fid;

        // Switch: '<S6>/Switch' incorporates:
        //   RelationalOperator: '<S6>/UpperRelop'

        if (static_cast<boolean_T>(static_cast<int32_T>((SpdLmt_idx_0 < fid) ^ 1)))
        {
            fid = SpdLmt_idx_0;
        }

        // End of Switch: '<S6>/Switch'
    }

    // End of Switch: '<S6>/Switch2'

    // Outputs for Atomic SubSystem: '<S8>/dotBankTD'
    MissionUAV_TD_Bank(rtu_ResetState, &SpdLmt_idx_0, 0.1, &localDW->dotBankTD,
                       &localZCE->dotBankTD);

    // End of Outputs for SubSystem: '<S8>/dotBankTD'

    // MATLAB Function: '<S8>/fhan_Bank' incorporates:
    //   SignalConversion generated from: '<S12>/ SFunction '
    //   Sum: '<S8>/Sum1'

    // MATLAB Function 'MissionUAV/TD/fhan_Bank': '<S12>:1'
    // '<S12>:1:3'
    // '<S12>:1:4'
    // '<S12>:1:5'
    // '<S12>:1:6'
    // '<S12>:1:8'
    // '<S12>:1:9'
    b_fid = SpdLmt_idx_0 * 0.1;

    // '<S12>:1:10'
    c_fid = (AddY_p - fid) + b_fid;

    // '<S12>:1:11'
    // '<S12>:1:12'
    if (std::isnan(c_fid)) {
        DiveAngleLimit = (rtNaN);
    } else if (c_fid < 0.0) {
        DiveAngleLimit = -1.0;
    } else {
        DiveAngleLimit = static_cast<real_T>(c_fid > 0.0);
    }

    d_fid = (std::sqrt((8.0 * std::abs(c_fid) + 0.020943951023931956) *
                       0.020943951023931956) - 0.020943951023931956) *
        DiveAngleLimit / 2.0 + b_fid;

    // '<S12>:1:13'
    // '<S12>:1:14'
    if (std::isnan(c_fid + 0.020943951023931956)) {
        DiveAngleLimit = (rtNaN);
    } else if (c_fid + 0.020943951023931956 < 0.0) {
        DiveAngleLimit = -1.0;
    } else {
        DiveAngleLimit = static_cast<real_T>(c_fid + 0.020943951023931956 > 0.0);
    }

    if (std::isnan(c_fid - 0.020943951023931956)) {
        fid = (rtNaN);
    } else if (c_fid - 0.020943951023931956 < 0.0) {
        fid = -1.0;
    } else {
        fid = static_cast<real_T>(c_fid - 0.020943951023931956 > 0.0);
    }

    b_fid = ((b_fid + c_fid) - d_fid) * ((DiveAngleLimit - fid) / 2.0) + d_fid;

    // Update for Atomic SubSystem: '<S8>/TD_Bank'
    // '<S12>:1:15'
    // '<S12>:1:17'
    MissionUAV_TD_Bank_Update(SpdLmt_idx_0, &AddY_p, &localDW->TD_Bank);

    // End of Update for SubSystem: '<S8>/TD_Bank'

    // MATLAB Function: '<S8>/fhan_Bank'
    if (std::isnan(b_fid)) {
        DiveAngleLimit = (rtNaN);
    } else if (b_fid < 0.0) {
        DiveAngleLimit = -1.0;
    } else {
        DiveAngleLimit = static_cast<real_T>(b_fid > 0.0);
    }

    if (std::isnan(b_fid + 0.020943951023931956)) {
        fid = (rtNaN);
    } else if (b_fid + 0.020943951023931956 < 0.0) {
        fid = -1.0;
    } else {
        fid = static_cast<real_T>(b_fid + 0.020943951023931956 > 0.0);
    }

    if (std::isnan(b_fid - 0.020943951023931956)) {
        c_fid = (rtNaN);
    } else if (b_fid - 0.020943951023931956 < 0.0) {
        c_fid = -1.0;
    } else {
        c_fid = static_cast<real_T>(b_fid - 0.020943951023931956 > 0.0);
    }

    if (std::isnan(b_fid)) {
        d_fid = (rtNaN);
    } else if (b_fid < 0.0) {
        d_fid = -1.0;
    } else {
        d_fid = static_cast<real_T>(b_fid > 0.0);
    }

    // Update for Atomic SubSystem: '<S8>/dotBankTD'
    MissionUAV_TD_Bank_Update(-2.0943951023931953 * (b_fid /
        0.020943951023931956 - DiveAngleLimit) * ((fid - c_fid) / 2.0) -
        2.0943951023931953 * d_fid, &SpdLmt_idx_0, &localDW->dotBankTD);

    // End of Update for SubSystem: '<S8>/dotBankTD'
}

// Model initialize function
void MissionUAV_initialize(const char_T **rt_errorStatus, RT_MODEL_MissionUAV_T *
    const MissionUAV_M, ZCE_MissionUAV_T *localZCE)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));

    // initialize error status
    rtmSetErrorStatusPointer(MissionUAV_M, rt_errorStatus);
    localZCE->DelayInput_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
    localZCE->DelayOutput_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
    localZCE->dotBankTD.DelayInput_Reset_ZCE = UNINITIALIZED_ZCSIG;
    localZCE->dotBankTD.DelayOutput_Reset_ZCE = UNINITIALIZED_ZCSIG;
    localZCE->TD_Bank.DelayInput_Reset_ZCE = UNINITIALIZED_ZCSIG;
    localZCE->TD_Bank.DelayOutput_Reset_ZCE = UNINITIALIZED_ZCSIG;
}

//
// File trailer for generated code.
//
// [EOF]
//
