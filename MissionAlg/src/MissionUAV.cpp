//
// File: MissionUAV.cpp
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 3.8
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jul 14 14:57:01 2022
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
#include <cstring>
#include <stdio.h>
#include <cmath>
#include "rt_atan2d_snf.h"
#include <stddef.h>
#include <cstdlib>
#include "MissionUAV_private.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Forward declaration for local functions
    static void MissionUAV_Model_resetImpl
    (robotics_core_internal_system_navigation_Model_MissionUAV_T *obj);

static void MissionUAV_emxInit_char_T(emxArray_char_T_MissionUAV_T **pEmxArray,
    int32_T numDimensions);
static int8_T MissionUAV_filedata_h(DW_MissionUAV_f_T *localDW);
static int8_T MissionUAV_cfopen_d(const char_T *cfilename, const char_T
    *cpermission, DW_MissionUAV_f_T *localDW);
static real_T MissionUAV_fileManager_c(DW_MissionUAV_f_T *localDW);
static void MissionUAV_emxEnsureCapacity_char_T(emxArray_char_T_MissionUAV_T
    *emxArray, int32_T oldNumel);
static void MissionUAV_fread_b(real_T fileID, emxArray_char_T_MissionUAV_T *A,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_emxFree_char_T(emxArray_char_T_MissionUAV_T **pEmxArray);
static boolean_T MissionUAV_copydigits(emxArray_char_T_MissionUAV_T *s1, int32_T
    *idx, const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n,
    boolean_T allowpoint);
static void MissionUAV_readfloat(emxArray_char_T_MissionUAV_T *s1, int32_T *idx,
    const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n, boolean_T
    allowimag, boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T
    *foundsign, boolean_T *success);
static creal_T MissionUAV_str2double(const emxArray_char_T_MissionUAV_T *s);
static int32_T MissionUAV_cfclose_e(real_T fid, DW_MissionUAV_f_T *localDW);
static int8_T MissionUAV_filedata(DW_MissionUAV_f_T *localDW);
static int8_T MissionUAV_cfopen(const char_T *cfilename, const char_T
    *cpermission, DW_MissionUAV_f_T *localDW);
static real_T MissionUAV_fileManager(DW_MissionUAV_f_T *localDW);
static void MissionUAV_fread(real_T fileID, emxArray_char_T_MissionUAV_T *A,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_strtok(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token, emxArray_char_T_MissionUAV_T *remain);
static int32_T MissionUAV_cfclose(real_T fid, DW_MissionUAV_f_T *localDW);
static void MissionUAV_strtok_b(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token);
static void MissionUAV_strtrim(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *y);
static boolean_T MissionUAV_strcmp(const emxArray_char_T_MissionUAV_T *a);
static boolean_T MissionUAV_strcmp_h(const emxArray_char_T_MissionUAV_T *a);
static boolean_T MissionUAV_contains(const emxArray_char_T_MissionUAV_T *str);
static void MissionUAV_find_token(const emxArray_char_T_MissionUAV_T *x, int32_T
    *itoken, int32_T *iremain);
static void MissionUAV_strtok_bd(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token, emxArray_char_T_MissionUAV_T *remain);
static void MissionUAV_readINI_bm(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_readINI_bmo(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_strtok_bdc(const emxArray_char_T_MissionUAV_T *x,
    emxArray_char_T_MissionUAV_T *token);
static boolean_T MissionUAV_strcmp_hh(const emxArray_char_T_MissionUAV_T *a);
static boolean_T MissionUAV_strcmp_hh4(const emxArray_char_T_MissionUAV_T *a);
static uavDubinsConnection_MissionUAV_T
    *MissionUAV_uavDubinsConnection_uavDubinsConnection
    (uavDubinsConnection_MissionUAV_T *b_this, real_T varargin_2, real_T
     varargin_4);
static void MissionUAV_readINI(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW);
static void MissionUAV_readINI_b(emxArray_char_T_MissionUAV_T *ret,
    DW_MissionUAV_f_T *localDW);
static boolean_T MissionUAV_strcmp_hh4i(const emxArray_char_T_MissionUAV_T *a);
static void MissionUAV_Model_resetImpl
    (robotics_core_internal_system_navigation_Model_MissionUAV_T *obj)
{
    obj->ModelImpl.Configuration.PHeight = 3.9;
    obj->ModelImpl.Configuration.PFlightPathAngle = 39.0;
    obj->ModelImpl.Configuration.PAirSpeed = 0.39;
    obj->ModelImpl.Configuration.PHeight = 4.0;
    obj->ModelImpl.Configuration.PFlightPathAngle = 12.0;
    obj->ModelImpl.Configuration.PAirSpeed = 1.0;
    obj->ModelImpl.Configuration.PDRoll[0] = 3402.9722249999991;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -1.5707963267948966;
    obj->ModelImpl.Configuration.PDRoll[0] = 300.0;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -0.17453292519943295;
    obj->ModelImpl.Configuration.PDRoll[1] = 116.66999999999999;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 1.5707963267948966;
    obj->ModelImpl.Configuration.PDRoll[1] = 30.0;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 0.17453292519943295;
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

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static int8_T MissionUAV_cfopen_d(const char_T *cfilename, const char_T
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

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static real_T MissionUAV_fileManager_c(DW_MissionUAV_f_T *localDW)
{
    real_T f;
    int8_T fileid;
    fileid = MissionUAV_cfopen_d("config.ini", "rb", localDW);
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
static void MissionUAV_fread_b(real_T fileID, emxArray_char_T_MissionUAV_T *A,
    DW_MissionUAV_f_T *localDW)
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
        filestar = localDW->eml_openfiles_p[static_cast<int32_T>
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
            MissionUAV_emxEnsureCapacity_char_T(A, i);
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
static void MissionUAV_readfloat(emxArray_char_T_MissionUAV_T *s1, int32_T *idx,
    const emxArray_char_T_MissionUAV_T *s, int32_T *k, int32_T n, boolean_T
    allowimag, boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T
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

    emxArray_char_T_MissionUAV_T *d;
    int32_T b_idx;
    int32_T b_k;
    int32_T g_k;
    char_T c_idx_0;
    boolean_T a__3;
    boolean_T exitg1;
    boolean_T isneg;
    MissionUAV_emxInit_char_T(&d, 2);
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
                    MissionUAV_readfloat(s1, idx, s, k, n, false, &isneg,
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
                MissionUAV_emxEnsureCapacity_char_T(d, b_k);
                loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                for (b_k = 0; b_k <= loop_ub; b_k++) {
                    d->data[b_k] = s1->data[b_k];
                }

                *success = MissionUAV_copydigits(d, &b_idx, s, &g_k, n, true);
                b_k = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                s1->size[0] = 1;
                s1->size[1] = d->size[1];
                MissionUAV_emxEnsureCapacity_char_T(s1, b_k);
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
                        MissionUAV_emxEnsureCapacity_char_T(d, b_k);
                        loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                        for (b_k = 0; b_k <= loop_ub; b_k++) {
                            d->data[b_k] = s1->data[b_k];
                        }

                        b_idx = static_cast<int32_T>(g_k + 1);
                        isneg = MissionUAV_copydigits(d, idx, s, &b_idx, n,
                            false);
                        b_k = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                        s1->size[0] = 1;
                        s1->size[1] = d->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(s1, b_k);
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

    MissionUAV_emxFree_char_T(&d);
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

    emxArray_char_T_MissionUAV_T *d;
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
    MissionUAV_emxInit_char_T(&d, 2);
    x.re = (rtNaN);
    x.im = 0.0;
    if (s->size[1] >= 1) {
        int32_T i;
        int32_T loop_ub;
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

        i = static_cast<int32_T>(d->size[0] * d->size[1]);
        d->size[0] = 1;
        d->size[1] = static_cast<int32_T>(s->size[1] + 2);
        MissionUAV_emxEnsureCapacity_char_T(d, i);
        loop_ub = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub + 1); i++) {
            d->data[i] = '\x00';
        }

        idx = 1;
        MissionUAV_readfloat(d, &idx, s, &k, s->size[1], true, &isimag1,
                             &isfinite1, &scanned1, &a__1, &success);
        i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
        s1->size[0] = 1;
        s1->size[1] = d->size[1];
        MissionUAV_emxEnsureCapacity_char_T(s1, i);
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
                MissionUAV_emxEnsureCapacity_char_T(d, i);
                loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                for (i = 0; i <= loop_ub; i++) {
                    d->data[i] = s1->data[i];
                }

                idx = static_cast<int32_T>(idx + 1);
                MissionUAV_readfloat(d, &idx, s, &k, s->size[1], true, &a__1,
                                     &success, &scanned2, &foundsign, &c_success);
                i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                s1->size[0] = 1;
                s1->size[1] = d->size[1];
                MissionUAV_emxEnsureCapacity_char_T(s1, i);
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

        MissionUAV_emxFree_char_T(&s1);
    }

    MissionUAV_emxFree_char_T(&d);
    return x;
}

// Function for MATLAB Function: '<S1>/Get Speed Limit'
static int32_T MissionUAV_cfclose_e(real_T fid, DW_MissionUAV_f_T *localDW)
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
            MissionUAV_emxEnsureCapacity_char_T(A, i);
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
static int32_T MissionUAV_cfclose(real_T fid, DW_MissionUAV_f_T *localDW)
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
        filestar = localDW->eml_openfiles[static_cast<int32_T>(static_cast<
            int32_T>(b_fileid) - 3)];
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
static void MissionUAV_strtok_b(const emxArray_char_T_MissionUAV_T *x,
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

    MissionUAV_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_strcmp_h(const emxArray_char_T_MissionUAV_T *a)
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
static void MissionUAV_strtok_bd(const emxArray_char_T_MissionUAV_T *x,
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
static void MissionUAV_readINI_bm(emxArray_char_T_MissionUAV_T *ret,
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
    fileid = MissionUAV_cfopen_d("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        MissionUAV_emxInit_char_T(&data, 2);
        MissionUAV_emxInit_char_T(&j, 1);
        MissionUAV_fread_b(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        MissionUAV_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        MissionUAV_emxFree_char_T(&j);
        MissionUAV_emxInit_char_T(&curSection, 2);
        MissionUAV_emxInit_char_T(&curKey, 2);
        MissionUAV_emxInit_char_T(&curVal, 2);
        MissionUAV_cfclose_e(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
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
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_b(curLine, tmp);
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

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection,
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
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_bd(curLine, aTmp, curVal);
                            MissionUAV_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            MissionUAV_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
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
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(aTmp, itoken_0);
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
                        MissionUAV_emxEnsureCapacity_char_T(ret, itoken_0);
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
static void MissionUAV_readINI_bmo(emxArray_char_T_MissionUAV_T *ret,
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
    fileid = MissionUAV_cfopen_d("config.ini", "rb", localDW);
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T itoken_0;
        int32_T loop_ub;
        MissionUAV_emxInit_char_T(&data, 2);
        MissionUAV_emxInit_char_T(&j, 1);
        MissionUAV_fread_b(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        MissionUAV_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        MissionUAV_emxFree_char_T(&j);
        MissionUAV_emxInit_char_T(&curSection, 2);
        MissionUAV_emxInit_char_T(&curKey, 2);
        MissionUAV_emxInit_char_T(&curVal, 2);
        MissionUAV_cfclose_e(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
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
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_b(curLine, tmp);
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

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection,
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
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_bd(curLine, aTmp, curVal);
                            MissionUAV_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            MissionUAV_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
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
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(aTmp, itoken_0);
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
                        MissionUAV_emxEnsureCapacity_char_T(ret, itoken_0);
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
static void MissionUAV_strtok_bdc(const emxArray_char_T_MissionUAV_T *x,
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
static boolean_T MissionUAV_strcmp_hh(const emxArray_char_T_MissionUAV_T *a)
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

    MissionUAV_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/Get Max Bank'
static boolean_T MissionUAV_strcmp_hh4(const emxArray_char_T_MissionUAV_T *a)
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
        int32_T itoken_0;
        int32_T loop_ub;
        MissionUAV_emxInit_char_T(&data, 2);
        MissionUAV_emxInit_char_T(&j, 1);
        MissionUAV_fread(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        MissionUAV_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        MissionUAV_emxFree_char_T(&j);
        MissionUAV_emxInit_char_T(&curSection, 2);
        MissionUAV_emxInit_char_T(&curKey, 2);
        MissionUAV_emxInit_char_T(&curVal, 2);
        MissionUAV_cfclose(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
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
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_b(curLine, tmp);
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

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection,
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
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_bd(curLine, aTmp, curVal);
                            MissionUAV_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            MissionUAV_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
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
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(aTmp, itoken_0);
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
                        MissionUAV_emxEnsureCapacity_char_T(ret, itoken_0);
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
static void MissionUAV_readINI_b(emxArray_char_T_MissionUAV_T *ret,
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
        int32_T itoken_0;
        int32_T loop_ub;
        MissionUAV_emxInit_char_T(&data, 2);
        MissionUAV_emxInit_char_T(&j, 1);
        MissionUAV_fread(static_cast<real_T>(fileid), j, localDW);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        MissionUAV_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        MissionUAV_emxFree_char_T(&j);
        MissionUAV_emxInit_char_T(&curSection, 2);
        MissionUAV_emxInit_char_T(&curKey, 2);
        MissionUAV_emxInit_char_T(&curVal, 2);
        MissionUAV_cfclose(static_cast<real_T>(fileid), localDW);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
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
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                MissionUAV_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
                }

                MissionUAV_strtok(data_0, curLine, data);
                MissionUAV_strtok_b(curLine, tmp);
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

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curSection,
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
                                MissionUAV_contains(curLine)) {
                            MissionUAV_strtok_bd(curLine, aTmp, curVal);
                            MissionUAV_find_token(curVal, &itoken, &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            MissionUAV_strtrim(aTmp, curKey);
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            MissionUAV_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
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
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(aTmp, itoken_0);
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
                        MissionUAV_emxEnsureCapacity_char_T(ret, itoken_0);
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
static boolean_T MissionUAV_strcmp_hh4i(const emxArray_char_T_MissionUAV_T *a)
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

    MissionUAV_emxFree_char_T(&aTmp);
    return b_bool;
}

// System initialize for referenced model: 'MissionUAV'
void MissionUAV_Init(RT_MODEL_MissionUAV_T * const MissionUAV_M,
                     DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX)
{
    FILE* a;

    // InitializeConditions for Integrator: '<S4>/Integrator'
    if (rtmIsFirstInitCond(MissionUAV_M)) {
        std::memset(&localX->Integrator_CSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));
    }

    localDW->Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S4>/Integrator'

    // InitializeConditions for Integrator: '<S8>/TD_Bank'
    localX->TD_Bank_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S8>/dotBankTD'
    localX->dotBankTD_CSTATE = 0.0;

    // SystemInitialize for MATLAB Function: '<S1>/Get Speed Limit'
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles_p[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S1>/Get Speed Limit'

    // SystemInitialize for MATLAB Function: '<S1>/Get Max Bank'
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }

    // End of SystemInitialize for MATLAB Function: '<S1>/Get Max Bank'

    // Start for MATLABSystem: '<S4>/ComputeDerivative'
    localDW->objisempty_a = true;
    localDW->obj_j.isInitialized = 1;
    MissionUAV_Model_resetImpl(&localDW->obj_j);

    // InitializeConditions for MATLABSystem: '<S4>/ComputeDerivative'
    MissionUAV_Model_resetImpl(&localDW->obj_j);

    // Start for MATLABSystem: '<S4>/StateVector2Struct'
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S4>/StateVector2Struct'
    localDW->obj.OutputTemplate.North = 0.0;
    localDW->obj.OutputTemplate.East = 0.0;
    localDW->obj.OutputTemplate.Height = 0.0;
    localDW->obj.OutputTemplate.AirSpeed = 0.0;
    localDW->obj.OutputTemplate.HeadingAngle = 0.0;
    localDW->obj.OutputTemplate.FlightPathAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngleRate = 0.0;
}

// System reset for referenced model: 'MissionUAV'
void MissionUAV_Reset(RT_MODEL_MissionUAV_T * const MissionUAV_M,
                      DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX)
{
    FILE* a;

    // InitializeConditions for Integrator: '<S4>/Integrator'
    if (rtmIsFirstInitCond(MissionUAV_M)) {
        std::memset(&localX->Integrator_CSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));
    }

    localDW->Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S4>/Integrator'

    // InitializeConditions for Integrator: '<S8>/TD_Bank'
    localX->TD_Bank_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S8>/dotBankTD'
    localX->dotBankTD_CSTATE = 0.0;

    // SystemReset for MATLAB Function: '<S1>/Get Speed Limit'
    localDW->SingletonInstance_not_empty = false;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles_p[i] = a;
    }

    // End of SystemReset for MATLAB Function: '<S1>/Get Speed Limit'

    // InitializeConditions for MATLABSystem: '<S4>/ComputeDerivative'
    MissionUAV_Model_resetImpl(&localDW->obj_j);

    // SystemReset for MATLAB Function: '<S1>/Get Max Bank'
    localDW->SingletonInstance_not_empty_m = false;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
        localDW->eml_openfiles[i] = a;
    }

    // End of SystemReset for MATLAB Function: '<S1>/Get Max Bank'

    // InitializeConditions for MATLABSystem: '<S4>/StateVector2Struct'
    localDW->obj.OutputTemplate.North = 0.0;
    localDW->obj.OutputTemplate.East = 0.0;
    localDW->obj.OutputTemplate.Height = 0.0;
    localDW->obj.OutputTemplate.AirSpeed = 0.0;
    localDW->obj.OutputTemplate.HeadingAngle = 0.0;
    localDW->obj.OutputTemplate.FlightPathAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngleRate = 0.0;
}

// Outputs for referenced model: 'MissionUAV'
void MissionUAV(RT_MODEL_MissionUAV_T * const MissionUAV_M, const real_T
                *rtu_ResetState, const real_T rtu_StartPos[8], const real_T
                *rtu_UAVGuidanceCmd_Height, const real_T
                *rtu_UAVGuidanceCmd_AirSpeed, const real_T
                *rtu_UAVGuidanceCmd_HeadingAngle, real_T *rty_SimUAVState_North,
                real_T *rty_SimUAVState_East, real_T *rty_SimUAVState_Height,
                real_T *rty_SimUAVState_AirSpeed, real_T
                *rty_SimUAVState_HeadingAngle, real_T
                *rty_SimUAVState_FlightPathAngle, real_T
                *rty_SimUAVState_RollAngle, real_T
                *rty_SimUAVState_RollAngleRate, DW_MissionUAV_f_T *localDW,
                X_MissionUAV_n_T *localX)
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
    real_T ClimbAngleLimit;
    real_T DiveAngleLimit;
    real_T b_fid;
    real_T c_fid;
    real_T c_fid_tmp;
    real_T d_fid;
    real_T fid;
    real_T fid_tmp;
    real_T rtb_RollAngle_c;
    int32_T c;
    int32_T i;
    int32_T i_0;
    int32_T loop_ub;
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T rtb_LowerRelop1;

    // Integrator: '<S4>/Integrator'
    if (rtsiIsModeUpdateTimeStep(MissionUAV_M->solverInfo) &&
            (static_cast<boolean_T>(static_cast<int32_T>((*rtu_ResetState != 0.0)
           | (localDW->Integrator_IWORK != 0))))) {
        // evaluate the level of the reset signal
        std::memcpy(&localX->Integrator_CSTATE[0], &rtu_StartPos[0],
                    static_cast<uint32_T>(sizeof(real_T) << 3U));
    }

    MissionUAV_emxInit_char_T(&ret, 2);
    MissionUAV_emxInit_char_T(&data, 2);
    MissionUAV_emxInit_char_T(&curSection, 2);
    MissionUAV_emxInit_char_T(&curKey, 2);
    MissionUAV_emxInit_char_T(&curVal, 2);
    MissionUAV_emxInit_char_T(&curLine, 2);
    MissionUAV_emxInit_char_T(&b_remainder, 2);
    MissionUAV_emxInit_char_T(&k, 1);
    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        // BusCreator: '<S1>/FixedWingGuidanceEnvironmentBus' incorporates:
        //   Constant: '<S1>/Gravity'
        //   Constant: '<S1>/NoWind'

        localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_p.WindEast = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_p.WindDown = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_p.Gravity = 9.807;

        // MATLAB Function: '<S1>/Get Speed Limit'
        // MATLAB Function 'MissionUAV/Get Speed Limit': '<S3>:1'
        // '<S3>:1:3'
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
                MissionUAV_fread_b(fid, k, localDW);
                i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                MissionUAV_emxEnsureCapacity_char_T(data, i_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                MissionUAV_cfclose_e(fid, localDW);
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
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                        data_7->data[i_0] = data->data[i_0];
                    }

                    MissionUAV_strtok(data_7, curLine, data);
                    MissionUAV_strtok_b(curLine, tmp_i);
                    MissionUAV_strtrim(tmp_i, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[0] == '[') {
                            rtb_LowerRelop1 = true;
                        }

                        guard1 = false;
                        if (rtb_LowerRelop1) {
                            rtb_LowerRelop1 = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_LowerRelop1 = true;
                            }

                            if (rtb_LowerRelop1) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    c = 0;
                                    i = 0;
                                } else {
                                    c = 1;
                                    i = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i_0 = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(i - c);
                                curSection->size[1] = loop_ub;
                                MissionUAV_emxEnsureCapacity_char_T(curSection,
                                    i_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(c + i)];
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
                                    static_cast<int32_T>(rtb_LowerRelop1) ^ 1)))
                                && MissionUAV_contains(curLine)) {
                                MissionUAV_strtok_bd(curLine, curVal,
                                                     b_remainder);
                                MissionUAV_strtrim(curVal, curKey);
                                MissionUAV_strtok_bdc(b_remainder, tmp_h);
                                MissionUAV_strtrim(tmp_h, curVal);
                            }
                        }
                    }

                    if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_h
                            (curKey)) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
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
                MissionUAV_fread_b(b_fid, k, localDW);
                i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                MissionUAV_emxEnsureCapacity_char_T(data, i_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                MissionUAV_cfclose_e(b_fid, localDW);
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
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                        data_6->data[i_0] = data->data[i_0];
                    }

                    MissionUAV_strtok(data_6, curLine, data);
                    MissionUAV_strtok_b(curLine, tmp_g);
                    MissionUAV_strtrim(tmp_g, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[0] == '[') {
                            rtb_LowerRelop1 = true;
                        }

                        guard1 = false;
                        if (rtb_LowerRelop1) {
                            rtb_LowerRelop1 = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_LowerRelop1 = true;
                            }

                            if (rtb_LowerRelop1) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    c = 0;
                                    i = 0;
                                } else {
                                    c = 1;
                                    i = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i_0 = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(i - c);
                                curSection->size[1] = loop_ub;
                                MissionUAV_emxEnsureCapacity_char_T(curSection,
                                    i_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(c + i)];
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
                                    static_cast<int32_T>(rtb_LowerRelop1) ^ 1)))
                                && MissionUAV_contains(curLine)) {
                                MissionUAV_strtok_bd(curLine, curVal,
                                                     b_remainder);
                                MissionUAV_strtrim(curVal, curKey);
                                MissionUAV_strtok_bdc(b_remainder, tmp_f);
                                MissionUAV_strtrim(tmp_f, curVal);
                            }
                        }
                    }

                    if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_hh
                            (curKey)) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
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
                MissionUAV_fread_b(c_fid, k, localDW);
                i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                MissionUAV_emxEnsureCapacity_char_T(data, i_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                MissionUAV_cfclose_e(c_fid, localDW);
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
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                        data_5->data[i_0] = data->data[i_0];
                    }

                    MissionUAV_strtok(data_5, curLine, data);
                    MissionUAV_strtok_b(curLine, tmp_e);
                    MissionUAV_strtrim(tmp_e, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[0] == '[') {
                            rtb_LowerRelop1 = true;
                        }

                        guard1 = false;
                        if (rtb_LowerRelop1) {
                            rtb_LowerRelop1 = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_LowerRelop1 = true;
                            }

                            if (rtb_LowerRelop1) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    c = 0;
                                    i = 0;
                                } else {
                                    c = 1;
                                    i = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i_0 = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(i - c);
                                curSection->size[1] = loop_ub;
                                MissionUAV_emxEnsureCapacity_char_T(curSection,
                                    i_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(c + i)];
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
                                    static_cast<int32_T>(rtb_LowerRelop1) ^ 1)))
                                && MissionUAV_contains(curLine)) {
                                MissionUAV_strtok_bd(curLine, curVal,
                                                     b_remainder);
                                MissionUAV_strtrim(curVal, curKey);
                                MissionUAV_strtok_bdc(b_remainder, tmp_d);
                                MissionUAV_strtrim(tmp_d, curVal);
                            }
                        }
                    }

                    if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_hh4
                            (curKey)) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
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
                MissionUAV_fread_b(d_fid, k, localDW);
                i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = k->size[0];
                MissionUAV_emxEnsureCapacity_char_T(data, i_0);
                loop_ub = k->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = k->data[i];
                }

                MissionUAV_cfclose_e(d_fid, localDW);
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
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                        data_4->data[i_0] = data->data[i_0];
                    }

                    MissionUAV_strtok(data_4, curLine, data);
                    MissionUAV_strtok_b(curLine, tmp_c);
                    MissionUAV_strtrim(tmp_c, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[0] == '[') {
                            rtb_LowerRelop1 = true;
                        }

                        guard1 = false;
                        if (rtb_LowerRelop1) {
                            rtb_LowerRelop1 = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_LowerRelop1 = true;
                            }

                            if (rtb_LowerRelop1) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    c = 0;
                                    i = 0;
                                } else {
                                    c = 1;
                                    i = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i_0 = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(i - c);
                                curSection->size[1] = loop_ub;
                                MissionUAV_emxEnsureCapacity_char_T(curSection,
                                    i_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(c + i)];
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
                                    static_cast<int32_T>(rtb_LowerRelop1) ^ 1)))
                                && MissionUAV_contains(curLine)) {
                                MissionUAV_strtok_bd(curLine, curVal,
                                                     b_remainder);
                                MissionUAV_strtrim(curVal, curKey);
                                MissionUAV_strtok_bdc(b_remainder, tmp_b);
                                MissionUAV_strtrim(tmp_b, curVal);
                            }
                        }
                    }

                    if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_hh4i
                            (curKey)) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
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
            MissionUAV_readINI_bm(ret, localDW);
            tmp_2 = MissionUAV_str2double(ret);
            ClimbAngleLimit = 0.017453292519943295 * tmp_2.re;
            printf("Set UAV ClimbAngleLimit:\t%f\n", ClimbAngleLimit);
            fflush(stdout);
            MissionUAV_readINI_bmo(ret, localDW);
            tmp_2 = MissionUAV_str2double(ret);
            DiveAngleLimit = 0.017453292519943295 * tmp_2.re;
            printf("Set UAV DiveAngleLimit:\t\t%f\n", DiveAngleLimit);
            fflush(stdout);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(tmp.re)) ^ 1))) {
                localDW->SingletonInstance.AirSpeed = tmp.re;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(d_fid)) ^ 1))) {
                localDW->SingletonInstance.MaxRollAngle = d_fid;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(ClimbAngleLimit)) ^ 1))) &&
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isnan(DiveAngleLimit)) ^ 1)))) {
                localDW->SingletonInstance.FlightPathAngleLimit[0] =
                    DiveAngleLimit;
                localDW->SingletonInstance.FlightPathAngleLimit[1] =
                    ClimbAngleLimit;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(tmp_0.re)) ^ 1))) && (static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan
                    (tmp_1.re)) ^ 1)))) {
                localDW->SingletonInstance.SpdLmt[0] = tmp_1.re;
                localDW->SingletonInstance.SpdLmt[1] = tmp_0.re;
            }

            MissionUAV_uavDubinsConnection_uavDubinsConnection
                (&localDW->SingletonInstance.Connector,
                 localDW->SingletonInstance.AirSpeed,
                 localDW->SingletonInstance.MaxRollAngle);
            localDW->SingletonInstance_not_empty = true;
        }

        localDW->SpdLmt[0] = localDW->SingletonInstance.SpdLmt[0];
        localDW->SpdLmt[1] = localDW->SingletonInstance.SpdLmt[1];

        // End of MATLAB Function: '<S1>/Get Speed Limit'

        // MinMax: '<S1>/Max'
        localDW->Max = std::fmax(localDW->SpdLmt[0], localDW->SpdLmt[1]);

        // MinMax: '<S1>/Min'
        localDW->Min = std::fmin(localDW->SpdLmt[0], localDW->SpdLmt[1]);
    }

    // RelationalOperator: '<S6>/LowerRelop1'
    rtb_LowerRelop1 = (*rtu_UAVGuidanceCmd_AirSpeed > localDW->Max);

    // Switch: '<S6>/Switch2'
    if (rtb_LowerRelop1) {
        b_fid = localDW->Max;
    } else {
        // RelationalOperator: '<S6>/UpperRelop'
        rtb_LowerRelop1 = (*rtu_UAVGuidanceCmd_AirSpeed < localDW->Min);

        // Switch: '<S6>/Switch'
        if (rtb_LowerRelop1) {
            b_fid = localDW->Min;
        } else {
            b_fid = *rtu_UAVGuidanceCmd_AirSpeed;
        }

        // End of Switch: '<S6>/Switch'
    }

    // End of Switch: '<S6>/Switch2'

    // Integrator: '<S8>/TD_Bank'
    if (rtsiIsModeUpdateTimeStep(MissionUAV_M->solverInfo) && (*rtu_ResetState
            != 0.0)) {
        // evaluate the level of the reset signal
        localX->TD_Bank_CSTATE = 0.0;
    }

    // BusCreator: '<S1>/SlewGuidanceBus'
    ClimbAngleLimit = *rtu_UAVGuidanceCmd_Height;

    // MATLABSystem: '<S4>/ComputeDerivative' incorporates:
    //   BusCreator: '<S1>/SlewGuidanceBus'
    //   Integrator: '<S4>/Integrator'
    //   Integrator: '<S8>/TD_Bank'
    //   MATLAB Function: '<S1>/SimHdgControl'

    DiveAngleLimit = std::cos(localX->Integrator_CSTATE[5]);
    c_fid_tmp = std::cos(localX->Integrator_CSTATE[4]);
    d_fid = std::sin(localX->Integrator_CSTATE[4]);
    rtb_RollAngle_c = std::sin(localX->Integrator_CSTATE[5]);
    c_fid = (-(c_fid_tmp * DiveAngleLimit) *
             localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth + -(d_fid *
              DiveAngleLimit) *
             localDW->FixedWingGuidanceEnvironmentBus_p.WindEast) +
        rtb_RollAngle_c * localDW->FixedWingGuidanceEnvironmentBus_p.WindDown;
    fid_tmp = ((localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth *
                localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth +
                localDW->FixedWingGuidanceEnvironmentBus_p.WindEast *
                localDW->FixedWingGuidanceEnvironmentBus_p.WindEast) +
               localDW->FixedWingGuidanceEnvironmentBus_p.WindDown *
               localDW->FixedWingGuidanceEnvironmentBus_p.WindDown) -
        localX->Integrator_CSTATE[3] * localX->Integrator_CSTATE[3];
    fid = std::sqrt(c_fid * c_fid - fid_tmp) + -c_fid;
    localDW->ComputeDerivative[0] = fid * c_fid_tmp * DiveAngleLimit;
    localDW->ComputeDerivative[1] = fid * d_fid * DiveAngleLimit;
    localDW->ComputeDerivative[2] = fid * rtb_RollAngle_c;
    localDW->ComputeDerivative[3] = (b_fid - localX->Integrator_CSTATE[3]) *
        localDW->obj_j.ModelImpl.Configuration.PAirSpeed;
    if (fid == 0.0) {
        localDW->ComputeDerivative[4] = 0.0;
        localDW->ComputeDerivative[5] = 0.0;
    } else {
        if (localX->Integrator_CSTATE[3] == 0.0) {
            localDW->ComputeDerivative[4] = 0.0;
        } else {
            b_fid = 1.0 / (std::cos(std::asin((fid * std::sin
                              (localX->Integrator_CSTATE[5]) +
                              localDW->FixedWingGuidanceEnvironmentBus_p.WindDown)
                             / localX->Integrator_CSTATE[3])) *
                           localX->Integrator_CSTATE[3]);
            localDW->ComputeDerivative[4] = std::cos(std::asin(b_fid *
                localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth * -d_fid +
                b_fid * localDW->FixedWingGuidanceEnvironmentBus_p.WindEast *
                c_fid_tmp)) *
                (localDW->FixedWingGuidanceEnvironmentBus_p.Gravity / fid * std::
                 tan(localX->Integrator_CSTATE[6]));
        }

        localDW->ComputeDerivative[5] = (std::fmax(std::fmin(std::asin(std::fmax
            (std::fmin((ClimbAngleLimit - localX->Integrator_CSTATE[2]) *
                       localDW->obj_j.ModelImpl.Configuration.PHeight / fid, 1.0),
             -1.0)),
            localDW->obj_j.ModelImpl.Configuration.FlightPathAngleLimits[1]),
            localDW->obj_j.ModelImpl.Configuration.FlightPathAngleLimits[0]) -
            localX->Integrator_CSTATE[5]) *
            localDW->obj_j.ModelImpl.Configuration.PFlightPathAngle;
    }

    localDW->ComputeDerivative[6] = localX->Integrator_CSTATE[7];
    localDW->ComputeDerivative[7] = (std::fmax(std::fmin(localX->TD_Bank_CSTATE,
        1.5707963267948966), -1.5707963267948966) - localX->Integrator_CSTATE[6])
        * localDW->obj_j.ModelImpl.Configuration.PDRoll[0] +
        localDW->obj_j.ModelImpl.Configuration.PDRoll[1] *
        -localX->Integrator_CSTATE[7];

    // End of MATLABSystem: '<S4>/ComputeDerivative'
    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        // MATLAB Function: '<S1>/Get Max Bank'
        // MATLAB Function 'MissionUAV/Get Max Bank': '<S2>:1'
        // '<S2>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (localDW->SingletonInstance_not_empty_m) ^ 1))) {
            localDW->SingletonInstance_f.AirSpeed = 35.0;
            localDW->SingletonInstance_f.MaxRollAngle = 0.3490658503988659;
            localDW->SingletonInstance_f.FlightPathAngleLimit[0] = -0.175;
            localDW->SingletonInstance_f.FlightPathAngleLimit[1] = 0.175;
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
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                        data_3->data[i_0] = data->data[i_0];
                    }

                    MissionUAV_strtok(data_3, curLine, data);
                    MissionUAV_strtok_b(curLine, tmp_a);
                    MissionUAV_strtrim(tmp_a, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[0] == '[') {
                            rtb_LowerRelop1 = true;
                        }

                        guard1 = false;
                        if (rtb_LowerRelop1) {
                            rtb_LowerRelop1 = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_LowerRelop1 = true;
                            }

                            if (rtb_LowerRelop1) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    c = 0;
                                    i = 0;
                                } else {
                                    c = 1;
                                    i = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i_0 = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(i - c);
                                curSection->size[1] = loop_ub;
                                MissionUAV_emxEnsureCapacity_char_T(curSection,
                                    i_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(c + i)];
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
                                    static_cast<int32_T>(rtb_LowerRelop1) ^ 1)))
                                && MissionUAV_contains(curLine)) {
                                MissionUAV_strtok_bd(curLine, curVal,
                                                     b_remainder);
                                MissionUAV_strtrim(curVal, curKey);
                                MissionUAV_strtok_bdc(b_remainder, tmp_9);
                                MissionUAV_strtrim(tmp_9, curVal);
                            }
                        }
                    }

                    if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_h
                            (curKey)) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
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
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                        data_2->data[i_0] = data->data[i_0];
                    }

                    MissionUAV_strtok(data_2, curLine, data);
                    MissionUAV_strtok_b(curLine, tmp_8);
                    MissionUAV_strtrim(tmp_8, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[0] == '[') {
                            rtb_LowerRelop1 = true;
                        }

                        guard1 = false;
                        if (rtb_LowerRelop1) {
                            rtb_LowerRelop1 = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_LowerRelop1 = true;
                            }

                            if (rtb_LowerRelop1) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    c = 0;
                                    i = 0;
                                } else {
                                    c = 1;
                                    i = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i_0 = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(i - c);
                                curSection->size[1] = loop_ub;
                                MissionUAV_emxEnsureCapacity_char_T(curSection,
                                    i_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(c + i)];
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
                                    static_cast<int32_T>(rtb_LowerRelop1) ^ 1)))
                                && MissionUAV_contains(curLine)) {
                                MissionUAV_strtok_bd(curLine, curVal,
                                                     b_remainder);
                                MissionUAV_strtrim(curVal, curKey);
                                MissionUAV_strtok_bdc(b_remainder, tmp_7);
                                MissionUAV_strtrim(tmp_7, curVal);
                            }
                        }
                    }

                    if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_hh
                            (curKey)) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
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
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                        data_1->data[i_0] = data->data[i_0];
                    }

                    MissionUAV_strtok(data_1, curLine, data);
                    MissionUAV_strtok_b(curLine, tmp_6);
                    MissionUAV_strtrim(tmp_6, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[0] == '[') {
                            rtb_LowerRelop1 = true;
                        }

                        guard1 = false;
                        if (rtb_LowerRelop1) {
                            rtb_LowerRelop1 = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_LowerRelop1 = true;
                            }

                            if (rtb_LowerRelop1) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    c = 0;
                                    i = 0;
                                } else {
                                    c = 1;
                                    i = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i_0 = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(i - c);
                                curSection->size[1] = loop_ub;
                                MissionUAV_emxEnsureCapacity_char_T(curSection,
                                    i_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(c + i)];
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
                                    static_cast<int32_T>(rtb_LowerRelop1) ^ 1)))
                                && MissionUAV_contains(curLine)) {
                                MissionUAV_strtok_bd(curLine, curVal,
                                                     b_remainder);
                                MissionUAV_strtrim(curVal, curKey);
                                MissionUAV_strtok_bdc(b_remainder, tmp_5);
                                MissionUAV_strtrim(tmp_5, curVal);
                            }
                        }
                    }

                    if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_hh4
                            (curKey)) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
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
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                        data_0->data[i_0] = data->data[i_0];
                    }

                    MissionUAV_strtok(data_0, curLine, data);
                    MissionUAV_strtok_b(curLine, tmp_4);
                    MissionUAV_strtrim(tmp_4, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_LowerRelop1 = false;
                        if (curLine->data[0] == '[') {
                            rtb_LowerRelop1 = true;
                        }

                        guard1 = false;
                        if (rtb_LowerRelop1) {
                            rtb_LowerRelop1 = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_LowerRelop1 = true;
                            }

                            if (rtb_LowerRelop1) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    c = 0;
                                    i = 0;
                                } else {
                                    c = 1;
                                    i = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i_0 = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(i - c);
                                curSection->size[1] = loop_ub;
                                MissionUAV_emxEnsureCapacity_char_T(curSection,
                                    i_0);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(c + i)];
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
                                    static_cast<int32_T>(rtb_LowerRelop1) ^ 1)))
                                && MissionUAV_contains(curLine)) {
                                MissionUAV_strtok_bd(curLine, curVal,
                                                     b_remainder);
                                MissionUAV_strtrim(curVal, curKey);
                                MissionUAV_strtok_bdc(b_remainder, tmp_3);
                                MissionUAV_strtrim(tmp_3, curVal);
                            }
                        }
                    }

                    if (MissionUAV_strcmp(curSection) && MissionUAV_strcmp_hh4i
                            (curKey)) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        MissionUAV_emxEnsureCapacity_char_T(ret, i_0);
                        loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                        for (i = 0; i <= loop_ub; i++) {
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
            ClimbAngleLimit = 0.017453292519943295 * tmp_0.re;
            printf("Set UAV ClimbAngleLimit:\t%f\n", ClimbAngleLimit);
            fflush(stdout);
            MissionUAV_readINI_b(ret, localDW);
            tmp_0 = MissionUAV_str2double(ret);
            DiveAngleLimit = 0.017453292519943295 * tmp_0.re;
            printf("Set UAV DiveAngleLimit:\t\t%f\n", DiveAngleLimit);
            fflush(stdout);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(tmp.re)) ^ 1))) {
                localDW->SingletonInstance_f.AirSpeed = tmp.re;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(d_fid)) ^ 1))) {
                localDW->SingletonInstance_f.MaxRollAngle = d_fid;
            }

            if ((static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (std::isnan(ClimbAngleLimit)) ^ 1))) &&
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isnan(DiveAngleLimit)) ^ 1)))) {
                localDW->SingletonInstance_f.FlightPathAngleLimit[0] =
                    DiveAngleLimit;
                localDW->SingletonInstance_f.FlightPathAngleLimit[1] =
                    ClimbAngleLimit;
            }

            MissionUAV_uavDubinsConnection_uavDubinsConnection
                (&localDW->SingletonInstance_f.Connector,
                 localDW->SingletonInstance_f.AirSpeed,
                 localDW->SingletonInstance_f.MaxRollAngle);
            localDW->SingletonInstance_not_empty_m = true;
        }

        fid = localDW->SingletonInstance_f.Connector.MaxRollAngle;

        // MinMax: '<S1>/MinBankAng' incorporates:
        //   Constant: '<S1>/Constant'
        //   Gain: '<S1>/Gain'
        //   MATLAB Function: '<S1>/Get Max Bank'

        localDW->MinBankAng = std::fmin(0.78539816339744828, 57.295779513082323 *
            fid * 3.0);
    }

    MissionUAV_emxFree_char_T(&k);
    MissionUAV_emxFree_char_T(&b_remainder);
    MissionUAV_emxFree_char_T(&curLine);
    MissionUAV_emxFree_char_T(&curVal);
    MissionUAV_emxFree_char_T(&curKey);
    MissionUAV_emxFree_char_T(&curSection);
    MissionUAV_emxFree_char_T(&data);
    MissionUAV_emxFree_char_T(&ret);

    // MATLAB Function: '<S1>/SimHdgControl' incorporates:
    //   Integrator: '<S4>/Integrator'

    // MATLAB Function 'MissionUAV/SimHdgControl': '<S7>:1'
    // '<S7>:1:3'
    // '<S7>:1:4'
    // '<S7>:1:5'
    // '<S7>:1:7'
    b_fid = 1.0 / localX->Integrator_CSTATE[3];

    // '<S7>:1:8'
    ClimbAngleLimit = (std::cos(localX->Integrator_CSTATE[4]) * std::cos
                       (localX->Integrator_CSTATE[5]) *
                       localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth +
                       std::sin(localX->Integrator_CSTATE[4]) * std::cos
                       (localX->Integrator_CSTATE[5]) *
                       localDW->FixedWingGuidanceEnvironmentBus_p.WindEast) +
        -rtb_RollAngle_c * localDW->FixedWingGuidanceEnvironmentBus_p.WindDown;

    // '<S7>:1:9'
    // '<S7>:1:10'
    // '<S7>:1:12'
    rtb_RollAngle_c = *rtu_UAVGuidanceCmd_HeadingAngle -
        localX->Integrator_CSTATE[4];
    if (std::abs(rtb_RollAngle_c) > 3.1415926535897931) {
        if (std::isnan(rtb_RollAngle_c + 3.1415926535897931)) {
            c_fid = (rtNaN);
        } else if (std::isinf(rtb_RollAngle_c + 3.1415926535897931)) {
            c_fid = (rtNaN);
        } else if (rtb_RollAngle_c + 3.1415926535897931 == 0.0) {
            c_fid = 0.0;
        } else {
            c_fid = std::fmod(rtb_RollAngle_c + 3.1415926535897931,
                              6.2831853071795862);
            rtb_LowerRelop1 = (c_fid == 0.0);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_LowerRelop1) ^ 1))) {
                d_fid = std::abs((rtb_RollAngle_c + 3.1415926535897931) /
                                 6.2831853071795862);
                rtb_LowerRelop1 = static_cast<boolean_T>(static_cast<int32_T>
                    ((std::abs(d_fid - std::floor(d_fid + 0.5)) >
                      2.2204460492503131E-16 * d_fid) ^ 1));
            }

            if (rtb_LowerRelop1) {
                c_fid = 0.0;
            } else if (rtb_RollAngle_c + 3.1415926535897931 < 0.0) {
                c_fid += 6.2831853071795862;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((rtb_RollAngle_c +
                3.1415926535897931 > 0.0) & (c_fid == 0.0)))) {
            c_fid = 6.2831853071795862;
        }

        rtb_RollAngle_c = c_fid - 3.1415926535897931;
    }

    rtb_RollAngle_c = rt_atan2d_snf((std::sqrt(ClimbAngleLimit * ClimbAngleLimit
        - fid_tmp) + -ClimbAngleLimit) * rtb_RollAngle_c, std::cos
        (localX->Integrator_CSTATE[4] - (localX->Integrator_CSTATE[4] - std::
        asin(b_fid * localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth * -std::
             sin(localX->Integrator_CSTATE[4]) + b_fid *
             localDW->FixedWingGuidanceEnvironmentBus_p.WindEast * c_fid_tmp))) *
        localDW->FixedWingGuidanceEnvironmentBus_p.Gravity);
    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        // Gain: '<S1>/Inverse'
        localDW->Inverse = -localDW->MinBankAng;
    }

    // Integrator: '<S8>/dotBankTD'
    if (rtsiIsModeUpdateTimeStep(MissionUAV_M->solverInfo) && (*rtu_ResetState
            != 0.0)) {
        // evaluate the level of the reset signal
        localX->dotBankTD_CSTATE = 0.0;
    }

    // Integrator: '<S8>/dotBankTD'
    localDW->dotBankTD = localX->dotBankTD_CSTATE;

    // MATLAB Function: '<S8>/fhan_Bank' incorporates:
    //   SignalConversion generated from: '<S9>/ SFunction '

    // MATLAB Function 'MissionUAV/TD/fhan_Bank': '<S9>:1'
    // '<S9>:1:3'
    // '<S9>:1:4'
    // '<S9>:1:5'
    // '<S9>:1:6'
    // '<S9>:1:8'
    // '<S9>:1:9'
    fid = localDW->dotBankTD * 0.1;

    // Switch: '<S5>/Switch2' incorporates:
    //   RelationalOperator: '<S5>/LowerRelop1'
    //   RelationalOperator: '<S5>/UpperRelop'
    //   Switch: '<S5>/Switch'

    // '<S9>:1:10'
    if (rtb_RollAngle_c > localDW->MinBankAng) {
        rtb_RollAngle_c = localDW->MinBankAng;
    } else if (rtb_RollAngle_c < localDW->Inverse) {
        // Switch: '<S5>/Switch'
        rtb_RollAngle_c = localDW->Inverse;
    }

    // End of Switch: '<S5>/Switch2'

    // MATLAB Function: '<S8>/fhan_Bank' incorporates:
    //   Integrator: '<S8>/TD_Bank'
    //   Sum: '<S8>/Sum1'

    b_fid = (localX->TD_Bank_CSTATE - rtb_RollAngle_c) + fid;

    // '<S9>:1:11'
    // '<S9>:1:12'
    if (std::isnan(b_fid)) {
        ClimbAngleLimit = b_fid;
    } else if (b_fid < 0.0) {
        ClimbAngleLimit = -1.0;
    } else {
        ClimbAngleLimit = static_cast<real_T>(b_fid > 0.0);
    }

    c_fid = (std::sqrt((8.0 * std::abs(b_fid) + 0.020943951023931956) *
                       0.020943951023931956) - 0.020943951023931956) *
        ClimbAngleLimit / 2.0 + fid;

    // '<S9>:1:13'
    // '<S9>:1:14'
    if (std::isnan(b_fid + 0.020943951023931956)) {
        ClimbAngleLimit = b_fid + 0.020943951023931956;
    } else if (b_fid + 0.020943951023931956 < 0.0) {
        ClimbAngleLimit = -1.0;
    } else {
        ClimbAngleLimit = static_cast<real_T>(b_fid + 0.020943951023931956 > 0.0);
    }

    if (std::isnan(b_fid - 0.020943951023931956)) {
        d_fid = b_fid - 0.020943951023931956;
    } else if (b_fid - 0.020943951023931956 < 0.0) {
        d_fid = -1.0;
    } else {
        d_fid = static_cast<real_T>(b_fid - 0.020943951023931956 > 0.0);
    }

    fid = ((fid + b_fid) - c_fid) * ((ClimbAngleLimit - d_fid) / 2.0) + c_fid;

    // '<S9>:1:15'
    // '<S9>:1:17'
    if (std::isnan(fid)) {
        b_fid = fid;
    } else if (fid < 0.0) {
        b_fid = -1.0;
    } else {
        b_fid = static_cast<real_T>(fid > 0.0);
    }

    if (std::isnan(fid + 0.020943951023931956)) {
        ClimbAngleLimit = fid + 0.020943951023931956;
    } else if (fid + 0.020943951023931956 < 0.0) {
        ClimbAngleLimit = -1.0;
    } else {
        ClimbAngleLimit = static_cast<real_T>(fid + 0.020943951023931956 > 0.0);
    }

    if (std::isnan(fid - 0.020943951023931956)) {
        d_fid = fid - 0.020943951023931956;
    } else if (fid - 0.020943951023931956 < 0.0) {
        d_fid = -1.0;
    } else {
        d_fid = static_cast<real_T>(fid - 0.020943951023931956 > 0.0);
    }

    localDW->fh = (fid / 0.020943951023931956 - b_fid) * -2.0943951023931953 *
        ((ClimbAngleLimit - d_fid) / 2.0) - 2.0943951023931953 * b_fid;

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   Integrator: '<S4>/Integrator'

    *rty_SimUAVState_North = localX->Integrator_CSTATE[0];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   Integrator: '<S4>/Integrator'

    *rty_SimUAVState_East = localX->Integrator_CSTATE[1];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   Integrator: '<S4>/Integrator'

    *rty_SimUAVState_Height = localX->Integrator_CSTATE[2];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   Integrator: '<S4>/Integrator'

    *rty_SimUAVState_AirSpeed = localX->Integrator_CSTATE[3];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   Integrator: '<S4>/Integrator'

    *rty_SimUAVState_HeadingAngle = localX->Integrator_CSTATE[4];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   Integrator: '<S4>/Integrator'

    *rty_SimUAVState_FlightPathAngle = localX->Integrator_CSTATE[5];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   Integrator: '<S4>/Integrator'

    *rty_SimUAVState_RollAngle = localX->Integrator_CSTATE[6];

    // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
    //   Integrator: '<S4>/Integrator'

    *rty_SimUAVState_RollAngleRate = localX->Integrator_CSTATE[7];
}

// Update for referenced model: 'MissionUAV'
void MissionUAV_Update(DW_MissionUAV_f_T *localDW)
{
    // Update for Integrator: '<S4>/Integrator'
    localDW->Integrator_IWORK = 0;
}

// Derivatives for referenced model: 'MissionUAV'
void MissionUAV_Deriv(const real_T *rtu_ResetState, DW_MissionUAV_f_T *localDW,
                      XDot_MissionUAV_n_T *localXdot)
{
    // Derivatives for Integrator: '<S4>/Integrator' incorporates:
    //   Integrator: '<S8>/TD_Bank'
    //   Integrator: '<S8>/dotBankTD'
    //   MATLABSystem: '<S4>/ComputeDerivative'

    if (*rtu_ResetState == 0.0) {
        std::memcpy(&localXdot->Integrator_CSTATE[0],
                    &localDW->ComputeDerivative[0], static_cast<uint32_T>(sizeof
                     (real_T) << 3U));
        localXdot->TD_Bank_CSTATE = localDW->dotBankTD;
        localXdot->dotBankTD_CSTATE = localDW->fh;
    } else {
        // level reset is active
        std::memset(&localXdot->Integrator_CSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));

        // level reset is active
        localXdot->TD_Bank_CSTATE = 0.0;

        // level reset is active
        localXdot->dotBankTD_CSTATE = 0.0;
    }

    // End of Derivatives for Integrator: '<S4>/Integrator'
}

// Model initialize function
void MissionUAV_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
    *timingBridge, RT_MODEL_MissionUAV_T *const MissionUAV_M, ZCE_MissionUAV_T
    *localZCE)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));
    MissionUAV_M->timingBridge = (timingBridge);

    // initialize error status
    rtmSetErrorStatusPointer(MissionUAV_M, rt_errorStatus);

    // initialize stop requested flag
    rtmSetStopRequestedPtr(MissionUAV_M, rt_stopRequested);

    // initialize RTWSolverInfo
    MissionUAV_M->solverInfo = (rt_solverInfo);

    // Set the Timing fields to the appropriate data in the RTWSolverInfo
    rtmSetSimTimeStepPointer(MissionUAV_M, rtsiGetSimTimeStepPtr
        (MissionUAV_M->solverInfo));
    MissionUAV_M->Timing.stepSize0 = (rtsiGetStepSize(MissionUAV_M->solverInfo));
    localZCE->Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
    localZCE->TD_Bank_Reset_ZCE = UNINITIALIZED_ZCSIG;
    localZCE->dotBankTD_Reset_ZCE = UNINITIALIZED_ZCSIG;
}

//
// File trailer for generated code.
//
// [EOF]
//
