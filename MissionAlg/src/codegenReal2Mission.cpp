//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 5.28
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Nov 25 19:38:09 2022
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
#include "SendData_IndividualUAVCmdT.h"
#include "SendData_FCUCMDT.h"
#include "codegenReal2Mission_types.h"
#include "RecvData_uint8_T.h"
#include "RecvData_RealUAVStateBusT.h"
#include "RecvData_IndividualUAVCmdT.h"
#include "SendData_TaskStatusT.h"
#include "RecvData_VectorSpeedT.h"
#include "rtwtypes.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"
#include <stdio.h>
#include "rtw_linux.h"
#include <cmath>
#include "plus_bEdW4Zmk.h"
#include "rt_modd_snf.h"
#include "rt_powd_snf.h"
#include "rt_atan2d_snf.h"
#include <cstring>
#include <stddef.h>
#include "floor_0EeG1Grp.h"
#include "split_JEzbX7NR.h"
#include "coder_posix_time.h"
#include "isequaln_OcM3ORTV.h"
#include "days2ymd_PW1eFTC1.h"
#include "secs2hms_laMW7jUK.h"
#include "validate_print_arguments_K2cMgYpT.h"
#include "validate_print_arguments_csk21eNA.h"
#include <cstdlib>
#include "div_s32.h"
#include "codegenReal2Mission_private.h"
#include "FlightMissionIterator.h"
#include "DeSerOtherUAV.h"
#include "ImmedMission.h"
#include "Real2SimGuidance.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<S7>/MissionUAVScheduling'
const uint8_T codegenReal2Mission_IN_A2B{ 1U };

const uint8_T codegenReal2Mission_IN_B2A{ 2U };

const uint8_T codegenReal2Mission_IN_FollowA{ 1U };

const uint8_T codegenReal2Mission_IN_FollowB{ 2U };

const uint8_T codegenReal2Mission_IN_MissionA{ 3U };

const uint8_T codegenReal2Mission_IN_MissionB{ 4U };

const int32_T codegenReal2Mission_event_shiftFollow{ 0 };

//
// This function updates continuous states using the ODE4 fixed-step
// solver algorithm
//
void codegenReal2MissionModelClass::rt_ertODEUpdateContinuousStates
    (RTWSolverInfo *si )
{
    time_T t { rtsiGetT(si) };

    time_T tnew { rtsiGetSolverStopTime(si) };

    time_T h { rtsiGetStepSize(si) };

    real_T *x { rtsiGetContStates(si) };

    ODE4_IntgData *id { static_cast<ODE4_IntgData *>(rtsiGetSolverData(si)) };

    real_T *y { id->y };

    real_T *f0 { id->f[0] };

    real_T *f1 { id->f[1] };

    real_T *f2 { id->f[2] };

    real_T *f3 { id->f[3] };

    real_T temp;
    int_T i;
    int_T nXc { 5 };

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

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_char_T
    (emxArray_char_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
    emxArray_char_T_codegenReal2Mission_T *emxArray;
    *pEmxArray = static_cast<emxArray_char_T_codegenReal2Mission_T *>(std::
        malloc(sizeof(emxArray_char_T_codegenReal2Mission_T)));
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata(void) const
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (codegenReal2Mission_DW.eml_openfiles_mq[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen(const char_T
    *cfilename, const char_T *cpermission)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata();
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            codegenReal2Mission_DW.eml_openfiles_mq[static_cast<int32_T>(
                static_cast<int32_T>(j) - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxEnsureCapacity_char_T
    (emxArray_char_T_codegenReal2Mission_T *emxArray, int32_T oldNumel)
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_fread(real_T fileID,
    emxArray_char_T_codegenReal2Mission_T *A)
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
        filestar = codegenReal2Mission_DW.eml_openfiles_mq[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
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
            codegenReal2Mission_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose(real_T fid)
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
        filestar = codegenReal2Mission_DW.eml_openfiles_mq[static_cast<int32_T>(
            static_cast<int32_T>(b_fileid) - 3)];
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
            codegenReal2Mission_DW.eml_openfiles_mq[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_strtok(const
    emxArray_char_T_codegenReal2Mission_T *x,
    emxArray_char_T_codegenReal2Mission_T *token,
    emxArray_char_T_codegenReal2Mission_T *remain)
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
    codegenReal2Mission_emxEnsureCapacity_char_T(remain, i);
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
    codegenReal2Mission_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_strtok_p(const
    emxArray_char_T_codegenReal2Mission_T *x,
    emxArray_char_T_codegenReal2Mission_T *token)
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
    codegenReal2Mission_emxEnsureCapacity_char_T(token, itoken);
    for (itoken = 0; itoken <= static_cast<int32_T>(k - 1); itoken++) {
        token->data[itoken] = x->data[static_cast<int32_T>(n + itoken)];
    }
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_strtrim(const
    emxArray_char_T_codegenReal2Mission_T *x,
    emxArray_char_T_codegenReal2Mission_T *y)
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
    codegenReal2Mission_emxEnsureCapacity_char_T(y, i);
    for (i = 0; i <= j2; i++) {
        y->data[i] = x->data[static_cast<int32_T>(b_j1 + i)];
    }
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_contains(const
    emxArray_char_T_codegenReal2Mission_T *str)
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_find_token(const
    emxArray_char_T_codegenReal2Mission_T *x, int32_T *itoken, int32_T *iremain)
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_strtok_ph(const
    emxArray_char_T_codegenReal2Mission_T *x,
    emxArray_char_T_codegenReal2Mission_T *token,
    emxArray_char_T_codegenReal2Mission_T *remain)
{
    int32_T b;
    int32_T c;
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    codegenReal2Mission_find_token(x, &itoken, &iremain);
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
    codegenReal2Mission_emxEnsureCapacity_char_T(remain, i);
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
    codegenReal2Mission_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(b - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxFree_char_T
    (emxArray_char_T_codegenReal2Mission_T **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_char_T_codegenReal2Mission_T *>
            (nullptr)) {
        if (((*pEmxArray)->data != static_cast<char_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_char_T_codegenReal2Mission_T *>
            (nullptr);
    }
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_p(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_copysign
    (emxArray_char_T_codegenReal2Mission_T *s1, int32_T *idx, const
     emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n, boolean_T *
     foundsign, boolean_T *success)
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isUnitImag(const
    emxArray_char_T_codegenReal2Mission_T *s, int32_T k, int32_T n)
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_readNonFinite(const
    emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n, boolean_T
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_copydigits
    (emxArray_char_T_codegenReal2Mission_T *s1, int32_T *idx, const
     emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n, boolean_T
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_copyexponent
    (emxArray_char_T_codegenReal2Mission_T *s1, int32_T *idx, const
     emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n)
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
            b_success = codegenReal2Mission_copydigits(s1, idx, s, &b_k, n,
                false);
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_readfloat
    (emxArray_char_T_codegenReal2Mission_T *s1, int32_T *idx, const
     emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n, boolean_T *
     isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
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
    codegenReal2Mission_copysign(s1, &b_idx, s, &b_k, n, foundsign, success);
    *idx = b_idx;
    *k = b_k;
    if (*success) {
        char_T tmp;
        boolean_T exitg1;
        if (codegenReal2Mission_isUnitImag(s, b_k, n)) {
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
                codegenReal2Mission_copysign(s1, &b_idx, s, &b_k, n, &a__3,
                    success);
                *idx = b_idx;
                if (*success) {
                    if (codegenReal2Mission_isUnitImag(s, b_k, n)) {
                        *success = false;
                    } else {
                        codegenReal2Mission_readNonFinite(s, &b_k, n, b_finite,
                            nfv);
                        if (*b_finite) {
                            *success = codegenReal2Mission_copydigits(s1, idx, s,
                                &b_k, n, true);
                            if (*success) {
                                *success = codegenReal2Mission_copyexponent(s1,
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
            codegenReal2Mission_readNonFinite(s, &b_k, n, b_finite, nfv);
            *k = b_k;
            if (*b_finite) {
                *success = codegenReal2Mission_copydigits(s1, idx, s, k, n, true);
                if (*success) {
                    *success = codegenReal2Mission_copyexponent(s1, idx, s, k, n);
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

// Function for MATLAB Function: '<S1>/ReadHomePoint'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_str2double(const
    emxArray_char_T_codegenReal2Mission_T *s)
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

    emxArray_char_T_codegenReal2Mission_T *s1;
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
        codegenReal2Mission_emxInit_char_T(&s1, 2);
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
        codegenReal2Mission_emxEnsureCapacity_char_T(s1, i);
        idx = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(idx + 1); i++) {
            s1->data[i] = '\x00';
        }

        idx = 1;
        codegenReal2Mission_readfloat(s1, &idx, s, &k, s->size[1], &isimag1,
            &isfinite1, &scanned1, &a__1, &success);
        if (isfinite1) {
            ntoread = 1;
        }

        if (success) {
            if (k <= s->size[1]) {
                s1->data[static_cast<int32_T>(idx - 1)] = ' ';
                idx = static_cast<int32_T>(idx + 1);
                codegenReal2Mission_readfloat(s1, &idx, s, &k, s->size[1], &a__1,
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

        codegenReal2Mission_emxFree_char_T(&s1);
    }

    return x;
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_p4(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S1>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_p4a(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata_g(void) const
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (codegenReal2Mission_DW.eml_openfiles_f[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen_j(const char_T *
    cfilename, const char_T *cpermission)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata_g();
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            codegenReal2Mission_DW.eml_openfiles_f[static_cast<int32_T>(
                static_cast<int32_T>(j) - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
real_T codegenReal2MissionModelClass::codegenReal2Mission_fileManager_d(void)
{
    int8_T fileid;
    fileid = codegenReal2Mission_cfopen_j("config.ini", "rb");
    return static_cast<real_T>(fileid);
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_fread_eg(real_T fileID,
    emxArray_char_T_codegenReal2Mission_T *A)
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
        filestar = codegenReal2Mission_DW.eml_openfiles_f[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
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
            codegenReal2Mission_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose_p(real_T fid)
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
        filestar = codegenReal2Mission_DW.eml_openfiles_f[static_cast<int32_T>(
            static_cast<int32_T>(b_fileid) - 3)];
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
            codegenReal2Mission_DW.eml_openfiles_f[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_strtok_cxm4(const
    emxArray_char_T_codegenReal2Mission_T *x,
    emxArray_char_T_codegenReal2Mission_T *token)
{
    int32_T i;
    int32_T iremain;
    int32_T itoken;
    codegenReal2Mission_find_token(x, &itoken, &iremain);
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
    codegenReal2Mission_emxEnsureCapacity_char_T(token, i);
    for (i = 0; i <= static_cast<int32_T>(iremain - 1); i++) {
        token->data[i] = x->data[static_cast<int32_T>(itoken + i)];
    }
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_a(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    static const char_T d[4]{ 'A', 'D', 'R', 'C' };

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 4) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 4) {
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_a5(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    static const char_T d[5]{ 'h', 'a', 't', '_', 'b' };

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 5) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 5) {
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_a5y(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    static const char_T d[7]{ 'o', 'm', 'e', 'g', 'a', '_', 'o' };

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 7) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 7) {
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_a5y5(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    static const char_T d[7]{ 'o', 'm', 'e', 'g', 'a', '_', 'c' };

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    int32_T loop_ub;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if (aTmp->size[1] == 7) {
        loop_ub = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (loop_ub < 7) {
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_a5y50(const
    emxArray_char_T_codegenReal2Mission_T *a)
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

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    boolean_T b_bool;
    codegenReal2Mission_emxInit_char_T(&aTmp, 2);
    if (a->size[1] == 0) {
        aTmp->size[0] = 1;
        aTmp->size[1] = 0;
    } else {
        int32_T i;
        int32_T loop_ub;
        i = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
        aTmp->size[0] = 1;
        aTmp->size[1] = a->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i);
        loop_ub = a->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            aTmp->data[i] = a->data[i];
        }
    }

    b_bool = false;
    if ((aTmp->size[1] == 1) && (c[static_cast<int32_T>(static_cast<int32_T>(
            static_cast<uint8_T>(aTmp->data[0])) & 127)] == 'p')) {
        b_bool = true;
    }

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_readINI
    (emxArray_char_T_codegenReal2Mission_T *ret)
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

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    emxArray_char_T_codegenReal2Mission_T *curKey;
    emxArray_char_T_codegenReal2Mission_T *curLine;
    emxArray_char_T_codegenReal2Mission_T *curSection;
    emxArray_char_T_codegenReal2Mission_T *curVal;
    emxArray_char_T_codegenReal2Mission_T *data;
    emxArray_char_T_codegenReal2Mission_T *data_0;
    emxArray_char_T_codegenReal2Mission_T *i;
    emxArray_char_T_codegenReal2Mission_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = codegenReal2Mission_cfopen_j("config.ini", "rb");
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        codegenReal2Mission_emxInit_char_T(&i, 1);
        codegenReal2Mission_fread_eg(static_cast<real_T>(fileid), i);
        codegenReal2Mission_emxInit_char_T(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = i->size[0];
        codegenReal2Mission_emxEnsureCapacity_char_T(data, i_0);
        loop_ub = i->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = i->data[i_0];
        }

        codegenReal2Mission_emxFree_char_T(&i);
        codegenReal2Mission_cfclose_p(static_cast<real_T>(fileid));
        codegenReal2Mission_emxInit_char_T(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curLine, 2);
        codegenReal2Mission_emxInit_char_T(&aTmp, 2);
        codegenReal2Mission_emxInit_char_T(&tmp, 2);
        codegenReal2Mission_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                codegenReal2Mission_strtok(data_0, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp);
                codegenReal2Mission_strtrim(tmp, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
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
                                codegenReal2Mission_contains(curLine)) {
                            codegenReal2Mission_strtok_ph(curLine, aTmp, curVal);
                            codegenReal2Mission_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            codegenReal2Mission_strtrim(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_a(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
                        }
                    }

                    b_bool = false;
                    if ((aTmp->size[1] == 1) && (h[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<uint8_T>(aTmp->
                            data[0])) & 127)] == 'i')) {
                        b_bool = true;
                    }

                    if (b_bool) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i_0);
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

        codegenReal2Mission_emxFree_char_T(&data_0);
        codegenReal2Mission_emxFree_char_T(&tmp);
        codegenReal2Mission_emxFree_char_T(&aTmp);
        codegenReal2Mission_emxFree_char_T(&curLine);
        codegenReal2Mission_emxFree_char_T(&curVal);
        codegenReal2Mission_emxFree_char_T(&curKey);
        codegenReal2Mission_emxFree_char_T(&curSection);
        codegenReal2Mission_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_readINI_p
    (emxArray_char_T_codegenReal2Mission_T *ret)
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

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    emxArray_char_T_codegenReal2Mission_T *curKey;
    emxArray_char_T_codegenReal2Mission_T *curLine;
    emxArray_char_T_codegenReal2Mission_T *curSection;
    emxArray_char_T_codegenReal2Mission_T *curVal;
    emxArray_char_T_codegenReal2Mission_T *data;
    emxArray_char_T_codegenReal2Mission_T *data_0;
    emxArray_char_T_codegenReal2Mission_T *i;
    emxArray_char_T_codegenReal2Mission_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = codegenReal2Mission_cfopen_j("config.ini", "rb");
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        codegenReal2Mission_emxInit_char_T(&i, 1);
        codegenReal2Mission_fread_eg(static_cast<real_T>(fileid), i);
        codegenReal2Mission_emxInit_char_T(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = i->size[0];
        codegenReal2Mission_emxEnsureCapacity_char_T(data, i_0);
        loop_ub = i->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = i->data[i_0];
        }

        codegenReal2Mission_emxFree_char_T(&i);
        codegenReal2Mission_cfclose_p(static_cast<real_T>(fileid));
        codegenReal2Mission_emxInit_char_T(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curLine, 2);
        codegenReal2Mission_emxInit_char_T(&aTmp, 2);
        codegenReal2Mission_emxInit_char_T(&tmp, 2);
        codegenReal2Mission_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                codegenReal2Mission_strtok(data_0, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp);
                codegenReal2Mission_strtrim(tmp, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
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
                                codegenReal2Mission_contains(curLine)) {
                            codegenReal2Mission_strtok_ph(curLine, aTmp, curVal);
                            codegenReal2Mission_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            codegenReal2Mission_strtrim(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_a(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
                        }
                    }

                    b_bool = false;
                    if ((aTmp->size[1] == 1) && (h[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<uint8_T>(aTmp->
                            data[0])) & 127)] == 'd')) {
                        b_bool = true;
                    }

                    if (b_bool) {
                        i_0 = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i_0);
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

        codegenReal2Mission_emxFree_char_T(&data_0);
        codegenReal2Mission_emxFree_char_T(&tmp);
        codegenReal2Mission_emxFree_char_T(&aTmp);
        codegenReal2Mission_emxFree_char_T(&curLine);
        codegenReal2Mission_emxFree_char_T(&curVal);
        codegenReal2Mission_emxFree_char_T(&curKey);
        codegenReal2Mission_emxFree_char_T(&curSection);
        codegenReal2Mission_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_readINI_pw
    (emxArray_char_T_codegenReal2Mission_T *ret)
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

    static const char_T i[7]{ 'u', 's', 'e', 'A', 'D', 'R', 'C' };

    emxArray_char_T_codegenReal2Mission_T *aTmp;
    emxArray_char_T_codegenReal2Mission_T *curKey;
    emxArray_char_T_codegenReal2Mission_T *curLine;
    emxArray_char_T_codegenReal2Mission_T *curSection;
    emxArray_char_T_codegenReal2Mission_T *curVal;
    emxArray_char_T_codegenReal2Mission_T *data;
    emxArray_char_T_codegenReal2Mission_T *data_0;
    emxArray_char_T_codegenReal2Mission_T *j;
    emxArray_char_T_codegenReal2Mission_T *tmp;
    int32_T iremain;
    int32_T itoken;
    int8_T fileid;
    ret->size[0] = 1;
    ret->size[1] = 0;
    fileid = codegenReal2Mission_cfopen_j("config.ini", "rb");
    if (static_cast<int32_T>(fileid) < 0) {
        printf("INI-file \"%s\" was not found or could not be read.\n",
               "config.ini");
        fflush(stdout);
    } else {
        int32_T i_0;
        int32_T loop_ub;
        codegenReal2Mission_emxInit_char_T(&j, 1);
        codegenReal2Mission_fread_eg(static_cast<real_T>(fileid), j);
        codegenReal2Mission_emxInit_char_T(&data, 2);
        i_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        codegenReal2Mission_emxEnsureCapacity_char_T(data, i_0);
        loop_ub = j->size[0];
        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1); i_0++) {
            data->data[i_0] = j->data[i_0];
        }

        codegenReal2Mission_emxFree_char_T(&j);
        codegenReal2Mission_cfclose_p(static_cast<real_T>(fileid));
        codegenReal2Mission_emxInit_char_T(&curSection, 2);
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curKey, 2);
        curKey->size[0] = 1;
        curKey->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curVal, 2);
        curVal->size[0] = 1;
        curVal->size[1] = 0;
        codegenReal2Mission_emxInit_char_T(&curLine, 2);
        codegenReal2Mission_emxInit_char_T(&aTmp, 2);
        codegenReal2Mission_emxInit_char_T(&tmp, 2);
        codegenReal2Mission_emxInit_char_T(&data_0, 2);
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (data->size[1] != 0) {
                boolean_T b_bool;
                i_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_0, i_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i_0 = 0; i_0 <= loop_ub; i_0++) {
                    data_0->data[i_0] = data->data[i_0];
                }

                codegenReal2Mission_strtok(data_0, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp);
                codegenReal2Mission_strtrim(tmp, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
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
                                codegenReal2Mission_contains(curLine)) {
                            codegenReal2Mission_strtok_ph(curLine, aTmp, curVal);
                            codegenReal2Mission_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            codegenReal2Mission_strtrim(aTmp, curKey);
                            i_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                i_0);
                            for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub -
                                    1); i_0++) {
                                curLine->data[i_0] = curVal->data
                                    [static_cast<int32_T>(itoken + i_0)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_a(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        i_0 = static_cast<int32_T>(aTmp->size[0] * aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp, i_0);
                        loop_ub = curKey->size[1];
                        for (i_0 = 0; i_0 <= static_cast<int32_T>(loop_ub - 1);
                                i_0++) {
                            aTmp->data[i_0] = curKey->data[i_0];
                        }
                    }

                    b_bool = false;
                    if (aTmp->size[1] == 7) {
                        iremain = 0;
                        int32_T exitg2;
                        do {
                            exitg2 = 0;
                            if (iremain < 7) {
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
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i_0);
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

        codegenReal2Mission_emxFree_char_T(&data_0);
        codegenReal2Mission_emxFree_char_T(&tmp);
        codegenReal2Mission_emxFree_char_T(&aTmp);
        codegenReal2Mission_emxFree_char_T(&curLine);
        codegenReal2Mission_emxFree_char_T(&curVal);
        codegenReal2Mission_emxFree_char_T(&curKey);
        codegenReal2Mission_emxFree_char_T(&curSection);
        codegenReal2Mission_emxFree_char_T(&data);
    }
}

// Function for MATLAB Function: '<S2>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_a5y50m(const
    emxArray_char_T_codegenReal2Mission_T *a)
{
    static const char_T b[5]{ 'f', 'a', 'l', 's', 'e' };

    boolean_T b_bool;
    b_bool = false;
    if (a->size[1] == 5) {
        int32_T kstr;
        kstr = 0;
        int32_T exitg1;
        do {
            exitg1 = 0;
            if (kstr < 5) {
                if (a->data[kstr] != b[kstr]) {
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

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop_k
    (Buffer_IndividualUAVCmd *q, Msg_IndividualUAVCmd *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<S10>/MissionValidation'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<S10>/MissionValidation'
    return isPop;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_RecvData
    (IndividualUAVCmd *data)
{
    Msg_IndividualUAVCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S10>/MissionValidation' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'
    //   Receive: '<S82>/Receive'

    if (codegenReal2Mission_pop_k
            (&codegenReal2Mission_DW.Queue_InsertedFor_MissionValidation_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S10>/MissionValidation'
    return status;
}

// Function for MATLAB Function: '<S42>/TimeConverter'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_two_prod(real_T a)
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

// Function for MATLAB Function: '<S84>/CommandCheck'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_times(const creal_T a)
{
    creal_T c;
    real_T ahi;
    real_T alo;
    real_T tmp;
    c = codegenReal2Mission_two_prod(a.re);
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

// Function for MATLAB Function: '<S51>/CurrentTime'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_two_sum(real_T a,
    real_T b)
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

// Function for MATLAB Function: '<S51>/CurrentTime'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_plus(const creal_T a,
    real_T b)
{
    creal_T c;
    creal_T t;
    real_T ahi;
    real_T alo;
    c = codegenReal2Mission_two_sum(a.re, b);
    t = codegenReal2Mission_two_sum(a.im, 0.0);
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

// Function for MATLAB Function: '<S84>/CommandCheck'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_createFromDateVec(
    const real_T inData[7])
{
    creal_T t;
    creal_T tmp;
    real_T check;
    real_T fracSecs;
    real_T second;
    second = inData[5];
    fracSecs = inData[6];
    check = (((((inData[0] + inData[1]) + inData[2]) + inData[3]) + inData[4]) +
             inData[5]) + inData[6];
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
              isinf(check)) ^ 1))) & static_cast<int32_T>(static_cast<boolean_T>
            (static_cast<int32_T>(static_cast<int32_T>(std::isnan(check)) ^ 1))))))
    {
        real_T mo;
        check = inData[0];
        mo = inData[1];
        if ((inData[1] < 1.0) || (inData[1] > 12.0)) {
            mo = std::floor((inData[1] - 1.0) / 12.0);
            check = inData[0] + mo;
            mo = ((inData[1] - 1.0) - mo * 12.0) + 1.0;
        }

        if (mo < 3.0) {
            check--;
            mo += 9.0;
        } else {
            mo -= 3.0;
        }

        if ((inData[6] < 0.0) || (inData[6] >= 1000.0)) {
            fracSecs = std::floor(inData[6] / 1000.0);
            second = inData[5] + fracSecs;
            fracSecs = inData[6] - fracSecs * 1000.0;
        }

        tmp.re = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor
                      (check / 100.0)) + std::floor(check / 400.0)) + std::floor
                    ((153.0 * mo + 2.0) / 5.0)) + inData[2]) + 60.0) - 719529.0;
        tmp.im = 0.0;
        t = codegenReal2Mission_plus(codegenReal2Mission_plus
            (codegenReal2Mission_plus(codegenReal2Mission_times(tmp), (60.0 *
            inData[3] + inData[4]) * 60000.0), second * 1000.0), fracSecs);
    } else {
        t.re = check;
        t.im = 0.0;
    }

    return t;
}

// Function for MATLAB Function: '<S84>/CommandCheck'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isequaln(int32_T
    varargin_1_SequenceID, MissionModes varargin_1_MissionMode, real_T
    varargin_1_MissionLocation_Lat, real_T varargin_1_MissionLocation_Lon,
    real_T varargin_1_MissionLocation_Alt, real_T
    varargin_1_MissionLocation_degHDG, real32_T varargin_1_params_Param1,
    real32_T varargin_1_params_Param2, real32_T varargin_1_params_Param3,
    real32_T varargin_1_params_Param4, real32_T varargin_1_params_Param5,
    real32_T varargin_1_params_Param6, real32_T varargin_1_params_Param7, const
    Location varargin_1_StartPosition, int32_T varargin_1_numUAV, int32_T
    varargin_1_FormationPos, real_T varargin_1_StartTime, int32_T
    varargin_2_SequenceID, MissionModes varargin_2_MissionMode, const Location
    varargin_2_MissionLocation, const Parameters varargin_2_params, const
    Location varargin_2_StartPosition, int32_T varargin_2_numUAV, int32_T
    varargin_2_FormationPos, real_T varargin_2_StartTime)
{
    boolean_T e_p;
    boolean_T p;
    p = false;
    if (static_cast<boolean_T>(static_cast<int32_T>((varargin_1_StartTime ==
            varargin_2_StartTime) | static_cast<int32_T>(static_cast<boolean_T>(
            static_cast<int32_T>(static_cast<int32_T>(std::isnan
              (varargin_1_StartTime)) & static_cast<int32_T>(std::isnan
              (varargin_2_StartTime)))))))) {
        if (varargin_1_FormationPos == varargin_2_FormationPos) {
            if (varargin_1_numUAV == varargin_2_numUAV) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((varargin_1_StartPosition.degHDG ==
                        varargin_2_StartPosition.degHDG) | static_cast<int32_T>(
                        static_cast<boolean_T>(static_cast<int32_T>
                        (static_cast<int32_T>(std::isnan
                          (varargin_1_StartPosition.degHDG)) &
                         static_cast<int32_T>(std::isnan
                          (varargin_2_StartPosition.degHDG)))))))) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((varargin_1_StartPosition.Alt ==
                           varargin_2_StartPosition.Alt) | static_cast<int32_T>(
                            static_cast<boolean_T>(static_cast<int32_T>(
                             static_cast<int32_T>(std::isnan
                              (varargin_1_StartPosition.Alt)) &
                             static_cast<int32_T>(std::isnan
                              (varargin_2_StartPosition.Alt)))))))) {
                        e_p = static_cast<boolean_T>(static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<boolean_T>(
                            static_cast<int32_T>((varargin_1_StartPosition.Lon ==
                            varargin_2_StartPosition.Lon) | static_cast<int32_T>
                            (static_cast<boolean_T>(static_cast<int32_T>(
                            static_cast<int32_T>(std::isnan
                            (varargin_1_StartPosition.Lon)) & static_cast<
                            int32_T>(std::isnan(varargin_2_StartPosition.Lon))))))))
                            & static_cast<int32_T>(static_cast<boolean_T>(
                            static_cast<int32_T>((varargin_1_StartPosition.Lat ==
                            varargin_2_StartPosition.Lat) | static_cast<int32_T>
                            (static_cast<boolean_T>(static_cast<int32_T>(
                            static_cast<int32_T>(std::isnan
                            (varargin_1_StartPosition.Lat)) & static_cast<
                            int32_T>(std::isnan(varargin_2_StartPosition.Lat))))))))));
                    } else {
                        e_p = false;
                    }
                } else {
                    e_p = false;
                }

                if (e_p) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((varargin_1_params_Param7 ==
                            varargin_2_params.Param7) | static_cast<int32_T>(
                            static_cast<boolean_T>(static_cast<int32_T>(
                             static_cast<int32_T>(std::isnan
                              (varargin_1_params_Param7)) & static_cast<int32_T>
                             (std::isnan(varargin_2_params.Param7)))))))) {
                        if (static_cast<boolean_T>(static_cast<int32_T>
                                                   ((varargin_1_params_Param6 ==
                               varargin_2_params.Param6) | static_cast<int32_T>(
                                static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(std::isnan
                                  (varargin_1_params_Param6)) &
                                 static_cast<int32_T>(std::isnan
                                  (varargin_2_params.Param6)))))))) {
                            if (static_cast<boolean_T>(static_cast<int32_T>
                                                       ((varargin_1_params_Param5
                                   == varargin_2_params.Param5) |
                                                        static_cast<int32_T>(
                                    static_cast<boolean_T>(static_cast<int32_T>(
                                     static_cast<int32_T>(std::isnan
                                      (varargin_1_params_Param5)) &
                                     static_cast<int32_T>(std::isnan
                                      (varargin_2_params.Param5)))))))) {
                                if (static_cast<boolean_T>(static_cast<int32_T>
                                                           ((varargin_1_params_Param4
                                       == varargin_2_params.Param4) |
                                                            static_cast<int32_T>
                                                            (static_cast<boolean_T>
                                        (static_cast<int32_T>
                                         (static_cast<int32_T>(std::isnan
                                          (varargin_1_params_Param4)) &
                                          static_cast<int32_T>(std::isnan
                                          (varargin_2_params.Param4)))))))) {
                                    if (static_cast<boolean_T>
                                            (static_cast<int32_T>
                                             ((varargin_1_params_Param3 ==
                                               varargin_2_params.Param3) |
                                              static_cast<int32_T>
                                              (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            (static_cast<int32_T>(std::isnan
                                              (varargin_1_params_Param3)) &
                                             static_cast<int32_T>(std::isnan
                                              (varargin_2_params.Param3))))))))
                                    {
                                        e_p = static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            (static_cast<int32_T>
                                             (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            ((varargin_1_params_Param2 ==
                                              varargin_2_params.Param2) |
                                             static_cast<int32_T>
                                             (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            (static_cast<int32_T>(std::isnan
                                            (varargin_1_params_Param2)) &
                                             static_cast<int32_T>(std::isnan
                                            (varargin_2_params.Param2)))))))) &
                                             static_cast<int32_T>
                                             (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            ((varargin_1_params_Param1 ==
                                              varargin_2_params.Param1) |
                                             static_cast<int32_T>
                                             (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            (static_cast<int32_T>(std::isnan
                                            (varargin_1_params_Param1)) &
                                             static_cast<int32_T>(std::isnan
                                            (varargin_2_params.Param1))))))))));
                                    } else {
                                        e_p = false;
                                    }
                                } else {
                                    e_p = false;
                                }
                            } else {
                                e_p = false;
                            }
                        } else {
                            e_p = false;
                        }
                    } else {
                        e_p = false;
                    }

                    if (e_p) {
                        if (static_cast<boolean_T>(static_cast<int32_T>
                                                   ((varargin_1_MissionLocation_degHDG
                               == varargin_2_MissionLocation.degHDG) |
                                                    static_cast<int32_T>(
                                static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(std::isnan
                                  (varargin_1_MissionLocation_degHDG)) &
                                 static_cast<int32_T>(std::isnan
                                  (varargin_2_MissionLocation.degHDG)))))))) {
                            if (static_cast<boolean_T>(static_cast<int32_T>
                                                       ((varargin_1_MissionLocation_Alt
                                   == varargin_2_MissionLocation.Alt) |
                                                        static_cast<int32_T>(
                                    static_cast<boolean_T>(static_cast<int32_T>(
                                     static_cast<int32_T>(std::isnan
                                      (varargin_1_MissionLocation_Alt)) &
                                     static_cast<int32_T>(std::isnan
                                      (varargin_2_MissionLocation.Alt)))))))) {
                                e_p = static_cast<boolean_T>(static_cast<int32_T>
                                    (static_cast<int32_T>(static_cast<boolean_T>
                                    (static_cast<int32_T>
                                     ((varargin_1_MissionLocation_Lon ==
                                       varargin_2_MissionLocation.Lon) |
                                      static_cast<int32_T>(static_cast<boolean_T>
                                    (static_cast<int32_T>(static_cast<int32_T>
                                    (std::isnan(varargin_1_MissionLocation_Lon))
                                    & static_cast<int32_T>(std::isnan
                                    (varargin_2_MissionLocation.Lon)))))))) &
                                     static_cast<int32_T>(static_cast<boolean_T>
                                    (static_cast<int32_T>
                                     ((varargin_1_MissionLocation_Lat ==
                                       varargin_2_MissionLocation.Lat) |
                                      static_cast<int32_T>(static_cast<boolean_T>
                                    (static_cast<int32_T>(static_cast<int32_T>
                                    (std::isnan(varargin_1_MissionLocation_Lat))
                                    & static_cast<int32_T>(std::isnan
                                    (varargin_2_MissionLocation.Lat))))))))));
                            } else {
                                e_p = false;
                            }
                        } else {
                            e_p = false;
                        }

                        if (e_p) {
                            e_p = static_cast<boolean_T>(static_cast<int32_T>
                                ((varargin_1_SequenceID == varargin_2_SequenceID)
                                 & static_cast<int32_T>(isequaln_OcM3ORTV
                                (varargin_1_MissionMode, varargin_2_MissionMode))));
                        }
                    }
                }
            } else {
                e_p = false;
            }
        } else {
            e_p = false;
        }
    } else {
        e_p = false;
    }

    if (e_p) {
        p = true;
    }

    return p;
}

// Function for MATLAB Function: '<S42>/TimeConverter'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_two_diff(real_T a,
    real_T b)
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

// Function for MATLAB Function: '<S84>/CommandCheck'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_divide(const creal_T
    a)
{
    creal_T c;
    creal_T da;
    creal_T s;
    real_T ahi;
    real_T shi;
    real_T slo;
    int32_T trueCount;
    c.re = a.re / 1000.0;
    da = split_JEzbX7NR(c.re);
    shi = c.re * 1000.0;
    slo = (da.re * 1000.0 - shi) + da.im * 1000.0;
    trueCount = 0;
    if (std::isnan(slo)) {
        trueCount = 1;
    }

    if (static_cast<int32_T>(trueCount - 1) >= 0) {
        slo = 0.0;
    }

    s.re = 0.0;
    s.im = 0.0;
    if (a.re != shi) {
        s = codegenReal2Mission_two_diff(a.re, shi);
    }

    s.re = (0.0 * a.im + s.re) - 0.0 * slo;
    s.im = (s.im + a.im) - slo;
    slo = (s.re + s.im) / 1000.0;
    ahi = 0.0;
    shi = c.re;
    if (slo != 0.0) {
        shi = c.re + slo;
        ahi = slo - (shi - c.re);
    }

    if (std::isnan(ahi)) {
        ahi = 0.0;
    }

    c.re = shi;
    c.im = ahi;
    return c;
}

// Function for MATLAB Function: '<S84>/CommandCheck'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_minus(const creal_T a,
    const creal_T b)
{
    creal_T c;
    creal_T cout;
    creal_T t;
    real_T ahi;
    real_T alo;
    c = codegenReal2Mission_two_diff(a.re, b.re);
    t = codegenReal2Mission_two_diff(a.im, b.im);
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

// Function for MATLAB Function: '<S84>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_i(real_T dd,
    real_T *y, real_T *mo, real_T *d, real_T *h, real_T *m, real_T *s)
{
    creal_T ahi_0;
    creal_T c;
    creal_T c_s;
    creal_T r;
    creal_T t;
    real_T ahi;
    real_T thi;
    real_T tmp;
    c.re = dd / 8.64E+7;
    t = codegenReal2Mission_two_prod(c.re);
    c_s.re = 0.0;
    c_s.im = 0.0;
    if (dd != t.re) {
        c_s = codegenReal2Mission_two_diff(dd, t.re);
    }

    c_s.re -= 0.0 * t.im;
    c_s.im -= t.im;
    tmp = (c_s.re + c_s.im) / 8.64E+7;
    thi = 0.0;
    ahi = c.re;
    if (tmp != 0.0) {
        ahi = c.re + tmp;
        thi = tmp - (ahi - c.re);
    }

    if (std::isnan(thi)) {
        thi = 0.0;
    }

    r.re = ahi;
    r.im = thi;
    r = floor_0EeG1Grp(r);
    c_s = codegenReal2Mission_times(r);
    c = codegenReal2Mission_two_diff(dd, c_s.re);
    t = codegenReal2Mission_two_diff(0.0, c_s.im);
    thi = c.im;
    ahi = c.re;
    if (t.re != 0.0) {
        thi = c.im + t.re;
        ahi = c.re + thi;
        thi -= ahi - c.re;
    }

    if (std::isnan(thi)) {
        thi = 0.0;
    }

    c.re = ahi;
    if (t.im != 0.0) {
        thi += t.im;
        ahi += thi;
        thi -= ahi - c.re;
    }

    if (std::isnan(thi)) {
        thi = 0.0;
    }

    ahi_0.re = ahi;
    ahi_0.im = thi;
    c_s = codegenReal2Mission_divide(ahi_0);
    t = floor_0EeG1Grp(c_s);
    c = codegenReal2Mission_minus(c_s, t);
    days2ymd_PW1eFTC1(r.re + r.im, y, mo, d);
    secs2hms_laMW7jUK(t.re + t.im, h, m, &thi);
    *s = (c.re + c.im) + thi;
    if (*s == 60.0) {
        *s = 59.999999999999993;
    }
}

// Function for MATLAB Function: '<S51>/CurrentTime'
void codegenReal2MissionModelClass::codegenReal2Mission_getLocalTime(real_T
    *t_tm_nsec, real_T *t_tm_sec, real_T *t_tm_min, real_T *t_tm_hour, real_T
    *t_tm_mday, real_T *t_tm_mon, real_T *t_tm_year, boolean_T *t_tm_isdst)
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

// Function for MATLAB Function: '<S84>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_ii(const
    creal_T dd, real_T *y, real_T *mo, real_T *d, real_T *h, real_T *m, real_T
    *s)
{
    creal_T B;
    creal_T c;
    creal_T c_s;
    creal_T t;
    real_T ahi;
    real_T thi;
    real_T tmp;
    c.re = dd.re / 8.64E+7;
    t = codegenReal2Mission_two_prod(c.re);
    c_s.re = 0.0;
    c_s.im = 0.0;
    if (dd.re != t.re) {
        c_s = codegenReal2Mission_two_diff(dd.re, t.re);
    }

    c_s.re = (0.0 * dd.im + c_s.re) - 0.0 * t.im;
    c_s.im = (c_s.im + dd.im) - t.im;
    tmp = (c_s.re + c_s.im) / 8.64E+7;
    ahi = 0.0;
    thi = c.re;
    if (tmp != 0.0) {
        thi = c.re + tmp;
        ahi = tmp - (thi - c.re);
    }

    if (std::isnan(ahi)) {
        ahi = 0.0;
    }

    B.re = thi;
    B.im = ahi;
    c_s = floor_0EeG1Grp(B);
    t = codegenReal2Mission_divide(codegenReal2Mission_minus(dd,
        codegenReal2Mission_times(c_s)));
    B = floor_0EeG1Grp(t);
    c = codegenReal2Mission_minus(t, B);
    days2ymd_PW1eFTC1(c_s.re + c_s.im, y, mo, d);
    secs2hms_laMW7jUK(B.re + B.im, h, m, &ahi);
    *s = (c.re + c.im) + ahi;
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

Msg_missionCmd codegenReal2MissionModelClass::codegenReal2Mission_createMsg_f(
    const missionCmd *data)
{
    Msg_missionCmd msg;

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'
    msg.fData = *data;
    return msg;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push_i
    (Buffer_missionCmd *q, const Msg_missionCmd *element)
{
    // Queue generated from: '<S7>/MissionUAVScheduling'
    q->fMsg = *element;
    q->fOccupied = true;
    return true;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S84>/PushCMD'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S2>/RcvNextMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_push_i
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    }

    // End of Queue generated from: '<S2>/RcvNextMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveThisMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S84>/SendFeedbackMissionCMD'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S2>/FeedbackCurrentMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_push_i
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_4_Queue,
             &msg)) {
        status = 0;
    }

    // End of Queue generated from: '<S2>/FeedbackCurrentMission'
    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_SendData(
    const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S84>/SndImmedCMD'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S2>/RcvImmedCMD' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_push_i
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
    }

    // End of Queue generated from: '<S2>/RcvImmedCMD'
    return status;
}

// Function for MATLAB Function: '<S94>/PrintOnboardLog'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata_i(void) const
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (codegenReal2Mission_DW.eml_openfiles_h[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S94>/PrintOnboardLog'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen_h(const char_T *
    cfilename, const char_T *cpermission)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata_i();
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            codegenReal2Mission_DW.eml_openfiles_h[static_cast<int32_T>(
                static_cast<int32_T>(j) - 1)] = filestar;
            codegenReal2Mission_DW.eml_autoflush[static_cast<int32_T>(
                static_cast<int32_T>(j) - 1)] = true;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S94>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_fileManager(real_T
    varargin_1, FILE* *f, boolean_T *a)
{
    int8_T fileid;
    fileid = static_cast<int8_T>(varargin_1);
    if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>(
            static_cast<int8_T>(varargin_1)) < 0) | (varargin_1 !=
            static_cast<real_T>(static_cast<int8_T>(varargin_1)))))) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        *f = codegenReal2Mission_DW.eml_openfiles_h[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
        *a = codegenReal2Mission_DW.eml_autoflush[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(fileid)) {
          case 0:
            *f = stdin;
            *a = true;
            break;

          case 1:
            *f = stdout;
            *a = true;
            break;

          case 2:
            *f = stderr;
            *a = true;
            break;

          default:
            *f = NULL;
            *a = true;
            break;
        }
    }
}

// Function for MATLAB Function: '<S94>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_string_string
    (MissionModes val, char_T obj_Value_data[], int32_T obj_Value_size[2])
{
    static const char_T y[15]{ 'F', 'l', 'i', 'g', 'h', 't', 'M', 'i', 's', 's',
        'i', 'o', 'n', 'R', 'H' };

    static const char_T cb[13]{ 'C', 'u', 's', 't', 'o', 'm', 'F', 'r', 'm', 'n',
        'N', 'a', 'v' };

    static const char_T jb[13]{ 'S', 'h', 'i', 'f', 't', 'E', 'a', 'r', 't', 'h',
        'E', 'N', 'U' };

    static const char_T fb[12]{ 'F', 'r', 'm', 'n', 'W', 'a', 'y', 'P', 'o', 'i',
        'n', 't' };

    static const char_T kb[12]{ 'S', 'h', 'i', 'f', 't', 'B', 'o', 'd', 'y', 'X',
        'Y', 'Z' };

    static const char_T w[12]{ 'D', 'e', 't', 'a', 'i', 'l', 'e', 'd', 'I', 'n',
        's', 'p' };

    static const char_T bb[11]{ 'C', 'i', 'r', 'c', 'D', 'i', 's', 'p', 'N', 'a',
        'v' };

    static const char_T gb[11]{ 'W', 'a', 'i', 't', 'T', 'o', 'S', 't', 'a', 'r',
        't' };

    static const char_T u[11]{ 'H', 'o', 'r', 'z', 'S', 'c', 'a', 'n', 'N', 'a',
        'v' };

    static const char_T x[11]{ 'A', 'v', 'o', 'i', 'd', 'D', 'a', 'n', 'g', 'e',
        'r' };

    static const char_T db[10]{ 'F', 'r', 'm', 'n', 'R', 'u', 'n', 'W', 'a', 'y'
    };

    static const char_T v[9]{ 'R', 'u', 'n', 'W', 'a', 'y', 'N', 'a', 'v' };

    static const char_T eb[8]{ 'P', 'r', 'o', 't', 'L', 'i', 'n', 'e' };

    static const char_T ib[8]{ 'T', 'u', 'n', 'e', 'A', 'D', 'R', 'C' };

    static const char_T ab[7]{ 'p', 'A', 't', 't', 'a', 'c', 'k' };

    static const char_T t[7]{ 'C', 'i', 'r', 'c', 'N', 'a', 'v' };

    static const MissionModes enumVals[17]{ MissionModes::CircNav, MissionModes::
        HorzScanNav, MissionModes::RunWayNav, MissionModes::DetailedInsp,
        MissionModes::AvoidDanger, MissionModes::FlightMissionRH, MissionModes::
        pAttack, MissionModes::CircDispNav, MissionModes::CustomFrmnNav,
        MissionModes::FrmnRunWay, MissionModes::ProtLine, MissionModes::
        FrmnWayPoint, MissionModes::WaitToStart, MissionModes::None,
        MissionModes::TuneADRC, MissionModes::ShiftEarthENU, MissionModes::
        ShiftBodyXYZ };

    cell_wrap_1_codegenReal2Mission_T b_0[17];
    cell_wrap_1_codegenReal2Mission_T b_1[17];
    cell_wrap_1_codegenReal2Mission_T b;
    cell_wrap_1_codegenReal2Mission_T c;
    cell_wrap_1_codegenReal2Mission_T d;
    cell_wrap_1_codegenReal2Mission_T e;
    cell_wrap_1_codegenReal2Mission_T f;
    cell_wrap_1_codegenReal2Mission_T g;
    cell_wrap_1_codegenReal2Mission_T h;
    cell_wrap_1_codegenReal2Mission_T i;
    cell_wrap_1_codegenReal2Mission_T j;
    cell_wrap_1_codegenReal2Mission_T l;
    cell_wrap_1_codegenReal2Mission_T m;
    cell_wrap_1_codegenReal2Mission_T n;
    cell_wrap_1_codegenReal2Mission_T o;
    cell_wrap_1_codegenReal2Mission_T p;
    cell_wrap_1_codegenReal2Mission_T q;
    cell_wrap_1_codegenReal2Mission_T r;
    cell_wrap_1_codegenReal2Mission_T s;
    int32_T enumIdx;
    int32_T k;
    int32_T loop_ub;
    boolean_T exitg1;
    b.f1.size[0] = 1;
    b.f1.size[1] = 7;
    for (k = 0; k < 7; k++) {
        b.f1.data[k] = t[k];
    }

    c.f1.size[0] = 1;
    c.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        c.f1.data[k] = u[k];
    }

    d.f1.size[0] = 1;
    d.f1.size[1] = 9;
    for (k = 0; k < 9; k++) {
        d.f1.data[k] = v[k];
    }

    e.f1.size[0] = 1;
    e.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        e.f1.data[k] = w[k];
    }

    f.f1.size[0] = 1;
    f.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        f.f1.data[k] = x[k];
    }

    g.f1.size[0] = 1;
    g.f1.size[1] = 15;
    for (k = 0; k < 15; k++) {
        g.f1.data[k] = y[k];
    }

    h.f1.size[0] = 1;
    h.f1.size[1] = 7;
    for (k = 0; k < 7; k++) {
        h.f1.data[k] = ab[k];
    }

    i.f1.size[0] = 1;
    i.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        i.f1.data[k] = bb[k];
    }

    j.f1.size[0] = 1;
    j.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        j.f1.data[k] = cb[k];
    }

    l.f1.size[0] = 1;
    l.f1.size[1] = 10;
    for (k = 0; k < 10; k++) {
        l.f1.data[k] = db[k];
    }

    m.f1.size[0] = 1;
    m.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        m.f1.data[k] = eb[k];
    }

    n.f1.size[0] = 1;
    n.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        n.f1.data[k] = fb[k];
    }

    o.f1.size[0] = 1;
    o.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        o.f1.data[k] = gb[k];
    }

    p.f1.size[0] = 1;
    p.f1.size[1] = 4;
    p.f1.data[0] = 'N';
    p.f1.data[1] = 'o';
    p.f1.data[2] = 'n';
    p.f1.data[3] = 'e';
    q.f1.size[0] = 1;
    q.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        q.f1.data[k] = ib[k];
    }

    r.f1.size[0] = 1;
    r.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        r.f1.data[k] = jb[k];
    }

    s.f1.size[0] = 1;
    s.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        s.f1.data[k] = kb[k];
    }

    enumIdx = -1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
        if (val == enumVals[k]) {
            enumIdx = k;
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    obj_Value_size[0] = 1;
    b_0[0] = b;
    b_0[1] = c;
    b_0[2] = d;
    b_0[3] = e;
    b_0[4] = f;
    b_0[5] = g;
    b_0[6] = h;
    b_0[7] = i;
    b_0[8] = j;
    b_0[9] = l;
    b_0[10] = m;
    b_0[11] = n;
    b_0[12] = o;
    b_0[13] = p;
    b_0[14] = q;
    b_0[15] = r;
    b_0[16] = s;
    obj_Value_size[1] = b_0[enumIdx].f1.size[1];
    b_0[0] = b;
    b_0[1] = c;
    b_0[2] = d;
    b_0[3] = e;
    b_0[4] = f;
    b_0[5] = g;
    b_0[6] = h;
    b_0[7] = i;
    b_0[8] = j;
    b_0[9] = l;
    b_0[10] = m;
    b_0[11] = n;
    b_0[12] = o;
    b_0[13] = p;
    b_0[14] = q;
    b_0[15] = r;
    b_0[16] = s;
    b_1[0] = b;
    b_1[1] = c;
    b_1[2] = d;
    b_1[3] = e;
    b_1[4] = f;
    b_1[5] = g;
    b_1[6] = h;
    b_1[7] = i;
    b_1[8] = j;
    b_1[9] = l;
    b_1[10] = m;
    b_1[11] = n;
    b_1[12] = o;
    b_1[13] = p;
    b_1[14] = q;
    b_1[15] = r;
    b_1[16] = s;
    loop_ub = b_1[enumIdx].f1.size[1];
    for (k = 0; k <= static_cast<int32_T>(loop_ub - 1); k++) {
        obj_Value_data[k] = b_0[enumIdx].f1.data[k];
    }
}

// Function for MATLAB Function: '<S94>/PrintOnboardLog'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_datetime_datetime
    (void)
{
    creal_T b_this_data;
    creal_T tmp;
    real_T c_tm_hour;
    real_T c_tm_mday;
    real_T c_tm_mon;
    real_T c_tm_year;
    real_T check;
    real_T fieldValues_idx_3;
    real_T fieldValues_idx_4;
    real_T fieldValues_idx_5;
    real_T fieldValues_idx_6;
    real_T fracSecs;
    real_T second;
    boolean_T expl_temp;
    codegenReal2Mission_getLocalTime(&second, &fracSecs, &check, &c_tm_hour,
        &c_tm_mday, &c_tm_mon, &c_tm_year, &expl_temp);
    fieldValues_idx_3 = c_tm_hour;
    fieldValues_idx_4 = check;
    fieldValues_idx_5 = fracSecs;
    fieldValues_idx_6 = second / 1.0E+6;
    second = fracSecs;
    fracSecs = fieldValues_idx_6;
    check = (((((c_tm_year + c_tm_mon) + c_tm_mday) + c_tm_hour) + check) +
             fieldValues_idx_5) + fieldValues_idx_6;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
              isinf(check)) ^ 1))) & static_cast<int32_T>(static_cast<boolean_T>
            (static_cast<int32_T>(static_cast<int32_T>(std::isnan(check)) ^ 1))))))
    {
        check = c_tm_year;
        c_tm_hour = c_tm_mon;
        if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
            c_tm_hour = std::floor((c_tm_mon - 1.0) / 12.0);
            check = c_tm_year + c_tm_hour;
            c_tm_hour = ((c_tm_mon - 1.0) - c_tm_hour * 12.0) + 1.0;
        }

        if (c_tm_hour < 3.0) {
            check--;
            c_tm_hour += 9.0;
        } else {
            c_tm_hour -= 3.0;
        }

        if ((fieldValues_idx_6 < 0.0) || (fieldValues_idx_6 >= 1000.0)) {
            fracSecs = std::floor(fieldValues_idx_6 / 1000.0);
            second = fieldValues_idx_5 + fracSecs;
            fracSecs = fieldValues_idx_6 - fracSecs * 1000.0;
        }

        tmp.re = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor
                      (check / 100.0)) + std::floor(check / 400.0)) + std::floor
                    ((153.0 * c_tm_hour + 2.0) / 5.0)) + c_tm_mday) + 60.0) -
            719529.0;
        tmp.im = 0.0;
        b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
            (codegenReal2Mission_plus(codegenReal2Mission_times(tmp), (60.0 *
            fieldValues_idx_3 + fieldValues_idx_4) * 60000.0), second * 1000.0),
            fracSecs);
    } else {
        b_this_data.re = check;
        b_this_data.im = 0.0;
    }

    return b_this_data;
}

// Function for MATLAB Function: '<S94>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_b(const
    creal_T dd, real_T *y, real_T *mo, real_T *d, real_T *h, real_T *m, real_T
    *s)
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
    t = codegenReal2Mission_two_prod(b_c.re);
    c_s.re = 0.0;
    c_s.im = 0.0;
    if (dd.re != t.re) {
        c_s = codegenReal2Mission_two_diff(dd.re, t.re);
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
    b_thi_0 = codegenReal2Mission_minus(dd, codegenReal2Mission_times(t));
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
        c_s = codegenReal2Mission_two_diff(b_thi_0.re, b_tmp);
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
    b_c = codegenReal2Mission_minus(b_thi_0, t);
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

// Function for MATLAB Function: '<S94>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_printIndivMissionCMD
    (int32_T IndivMissionCMD_SequenceID, MissionModes
     IndivMissionCMD_MissionMode, real_T IndivMissionCMD_MissionLocation_Lat,
     real_T IndivMissionCMD_MissionLocation_Lon, real_T
     IndivMissionCMD_MissionLocation_Alt, real_T
     IndivMissionCMD_MissionLocation_degHDG, real32_T
     IndivMissionCMD_params_Param1, real32_T IndivMissionCMD_params_Param2,
     real32_T IndivMissionCMD_params_Param3, real32_T
     IndivMissionCMD_params_Param4, real32_T IndivMissionCMD_params_Param5,
     real32_T IndivMissionCMD_params_Param6, real32_T
     IndivMissionCMD_params_Param7, const Location IndivMissionCMD_StartPosition,
     int32_T IndivMissionCMD_numUAV, int32_T IndivMissionCMD_FormationPos, const
     Time IndivMissionCMD_StartTime, real_T fileID)
{
    FILE* b_NULL;
    FILE* filestar;
    creal_T TimeNow_data;
    real_T b_validatedHoleFilling[7];
    real_T a__1;
    real_T a__11;
    real_T a__17;
    real_T a__2;
    real_T a__23;
    real_T a__29;
    real_T a__3;
    real_T a__35;
    real_T a__4;
    real_T a__5;
    real_T b_a__35;
    real_T b_varargin_1;
    real_T x;
    int32_T validatedHoleFilling[7];
    int32_T b_Value_size[2];
    char_T varargin_1_data[16];
    char_T b_Value_data[15];
    boolean_T autoflush;
    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\n====== Display Mission Command ======\n");
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Sequence ID:\t\t%d\n", IndivMissionCMD_SequenceID);
        if (autoflush) {
            fflush(filestar);
        }
    }

    codegenReal2Mission_string_string(IndivMissionCMD_MissionMode, b_Value_data,
        b_Value_size);
    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        int32_T b_Value_idx_0;
        b_Value_idx_0 = b_Value_size[1];
        for (int32_T varargin_1_data_tmp{0}; varargin_1_data_tmp <= static_cast<
                int32_T>(b_Value_idx_0 - 1); varargin_1_data_tmp++) {
            varargin_1_data[varargin_1_data_tmp] =
                b_Value_data[varargin_1_data_tmp];
        }

        varargin_1_data[b_Value_size[1]] = '\x00';
        fprintf(filestar, "Mission Mode:\t\t%s\n", &varargin_1_data[0]);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Mission Location: \n");
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLatitude:\t\t%f\n",
                IndivMissionCMD_MissionLocation_Lat);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLongitude:\t\t%f\n",
                IndivMissionCMD_MissionLocation_Lon);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tAltitude:\t\t%f\n",
                IndivMissionCMD_MissionLocation_Alt);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tHeading:\t\t%f\n",
                IndivMissionCMD_MissionLocation_degHDG);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Parameters: \n");
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam1:\t\t%f\n", IndivMissionCMD_params_Param1);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam2:\t\t%f\n", IndivMissionCMD_params_Param2);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam3:\t\t%f\n", IndivMissionCMD_params_Param3);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam4:\t\t%f\n", IndivMissionCMD_params_Param4);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam5:\t\t%f\n", IndivMissionCMD_params_Param5);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam6:\t\t%f\n", IndivMissionCMD_params_Param6);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam7:\t\t%f\n", IndivMissionCMD_params_Param7);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Start Position: \n");
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLatitude:\t\t%f\n",
                IndivMissionCMD_StartPosition.Lat);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLongitude:\t\t%f\n",
                IndivMissionCMD_StartPosition.Lon);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tAltitude:\t\t%f\n",
                IndivMissionCMD_StartPosition.Alt);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tHeading:\t\t%f\n",
                IndivMissionCMD_StartPosition.degHDG);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Number of UAVs:\t\t%d\n", IndivMissionCMD_numUAV);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Formation Position:\t%d\n",
                IndivMissionCMD_FormationPos);
        if (autoflush) {
            fflush(filestar);
        }
    }

    validate_print_arguments_K2cMgYpT(IndivMissionCMD_StartTime.year,
        IndivMissionCMD_StartTime.month, IndivMissionCMD_StartTime.day,
        IndivMissionCMD_StartTime.hour, IndivMissionCMD_StartTime.minute,
        IndivMissionCMD_StartTime.second, IndivMissionCMD_StartTime.millisecond,
        validatedHoleFilling);
    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Start Time:   %04d-%02d-%02d %02d:%02d:%02d.%03d\n",
                validatedHoleFilling[0], validatedHoleFilling[1],
                validatedHoleFilling[2], validatedHoleFilling[3],
                validatedHoleFilling[4], validatedHoleFilling[5],
                validatedHoleFilling[6]);
        if (autoflush) {
            fflush(filestar);
        }
    }

    TimeNow_data = codegenReal2Mission_datetime_datetime();
    codegenReal2Mission_getDateVec_b(TimeNow_data, &b_varargin_1, &a__1, &a__2,
        &a__3, &a__4, &a__5);
    codegenReal2Mission_getDateVec_b(TimeNow_data, &a__2, &a__1, &a__3, &a__4,
        &a__5, &a__11);
    codegenReal2Mission_getDateVec_b(TimeNow_data, &a__3, &a__4, &a__2, &a__5,
        &a__11, &a__17);
    codegenReal2Mission_getDateVec_b(TimeNow_data, &a__4, &a__5, &a__11, &a__3,
        &a__17, &a__23);
    codegenReal2Mission_getDateVec_b(TimeNow_data, &a__5, &a__11, &a__17, &a__23,
        &a__4, &a__29);
    codegenReal2Mission_getDateVec_b(TimeNow_data, &a__11, &a__17, &a__23,
        &a__29, &a__35, &a__5);
    codegenReal2Mission_getDateVec_b(TimeNow_data, &a__17, &a__23, &a__29,
        &a__35, &b_a__35, &a__11);
    codegenReal2Mission_getDateVec_b(TimeNow_data, &a__17, &a__23, &a__29,
        &a__35, &b_a__35, &x);
    validate_print_arguments_csk21eNA(b_varargin_1, a__1, a__2, a__3, a__4, std::
        floor(a__5), std::round((a__11 - std::floor(x)) * 1000.0),
        b_validatedHoleFilling);
    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar,
                "Current Time: %04.0f-%02.0f-%02.0f %02.0f:%02.0f:%02.0f.%03.0f\n",
                b_validatedHoleFilling[0], b_validatedHoleFilling[1],
                b_validatedHoleFilling[2], b_validatedHoleFilling[3],
                b_validatedHoleFilling[4], b_validatedHoleFilling[5],
                b_validatedHoleFilling[6]);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\n");
        if (autoflush) {
            fflush(filestar);
        }
    }
}

// Function for MATLAB Function: '<S94>/PrintOnboardLog'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose_n(real_T fid)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(fid);
    if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>(
            static_cast<int8_T>(fid)) < 0) | (fid != static_cast<real_T>(
            static_cast<int8_T>(fid)))))) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = codegenReal2Mission_DW.eml_openfiles_h[static_cast<int32_T>(
            static_cast<int32_T>(b_fileid) - 3)];
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
            codegenReal2Mission_DW.eml_openfiles_h[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = NULL;
            codegenReal2Mission_DW.eml_autoflush[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = true;
        }
    }

    return st;
}

Msg_IndividualUAVCmd codegenReal2MissionModelClass::
    codegenReal2Mission_createMsg(const IndividualUAVCmd *data)
{
    Msg_IndividualUAVCmd msg;

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'
    msg.fData = *data;
    return msg;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push
    (Queue_IndividualUAVCmd *q, const Msg_IndividualUAVCmd *element)
{
    // Queue: '<S83>/Queue'
    q->fTail = static_cast<int32_T>(q->fTail + 1) % q->fCapacity;
    if (q->fTail == q->fHead) {
        q->fHead = static_cast<int32_T>(q->fHead + 1) % q->fCapacity;
    } else if (q->fHead == -1) {
        q->fHead = q->fTail;
    }

    q->fArray[q->fTail] = *element;
    return true;

    // End of Queue: '<S83>/Queue'
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Queue_SendData(const
    IndividualUAVCmd *data)
{
    Msg_IndividualUAVCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S83>/Send'

    msg = codegenReal2Mission_createMsg(data);

    // Queue: '<S83>/Queue' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_push(&codegenReal2Mission_DW.Queue_Queue, &msg)) {
        status = 0;
    }

    // End of Queue: '<S83>/Queue'
    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop
    (Queue_IndividualUAVCmd *q, Msg_IndividualUAVCmd *elementOut)
{
    boolean_T isPop;

    // Queue: '<S83>/Queue'
    if (q->fHead == -1) {
        isPop = false;
    } else {
        *elementOut = q->fArray[q->fHead];
        isPop = true;
        if (q->fHead == q->fTail) {
            q->fHead = -1;
            q->fTail = -1;
        } else {
            q->fHead = static_cast<int32_T>(q->fHead + 1) % q->fCapacity;
        }
    }

    // End of Queue: '<S83>/Queue'
    return isPop;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Queue_RecvData
    (IndividualUAVCmd *data)
{
    Msg_IndividualUAVCmd msg;
    int32_T status{ 1 };

    // Queue: '<S83>/Queue' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'
    //   Receive: '<S91>/Receive'

    if (codegenReal2Mission_pop(&codegenReal2Mission_DW.Queue_Queue, &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue: '<S83>/Queue'
    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push_b
    (Buffer_IndividualUAVCmd *q, const Msg_IndividualUAVCmd *element)
{
    // Queue generated from: '<S10>/MissionValidation'
    q->fMsg = *element;
    q->fOccupied = true;
    return true;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_b_SendData(
    const IndividualUAVCmd *data)
{
    Msg_IndividualUAVCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S83>/SendCMD'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<S10>/MissionValidation' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_push_b
            (&codegenReal2Mission_DW.Queue_InsertedFor_MissionValidation_at_inport_0_Queue,
             &msg)) {
        status = 0;
    }

    // End of Queue generated from: '<S10>/MissionValidation'
    return status;
}

Msg_DangerInfo codegenReal2MissionModelClass::codegenReal2Mission_createMsg_fl(
    const DangerInfo *data)
{
    Msg_DangerInfo msg;

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'
    msg.fData = *data;
    return msg;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push_j
    (Buffer_DangerInfo *q, const Msg_DangerInfo *element)
{
    // Queue generated from: '<S2>/DangerLidarScanPoints'
    q->fMsg = *element;
    q->fOccupied = true;
    return true;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_SendData(
    const DangerInfo *data)
{
    Msg_DangerInfo msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S83>/SendDanger'

    msg = codegenReal2Mission_createMsg_fl(data);

    // Queue generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_push_j
            (&codegenReal2Mission_DW.Queue_InsertedFor_DangerLidarScanPoints_at_inport_0_Queue,
             &msg)) {
        status = 0;
    }

    // End of Queue generated from: '<S2>/DangerLidarScanPoints'
    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop_h
    (Buffer_missionCmd *q, Msg_missionCmd *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<S7>/MissionUAVScheduling'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<S7>/MissionUAVScheduling'
    return isPop;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S2>/RcvNextMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S2>/RcvNextMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_MissionUAVScheduling_In3_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S50>/SendMission'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S7>/MissionUAVScheduling'
    if (codegenReal2Mission_push_i
            (&codegenReal2Mission_DW.Queue_InsertedFor_MissionUAVScheduling_at_inport_2_Queue,
             &msg)) {
        status = 0;
    }

    return status;
}

// Function for Chart: '<S7>/MissionUAVScheduling'
void codegenReal2MissionModelClass::codegenReal2Mission_FollowSwitch(const
    int32_T *sfEvent)
{
    // During 'FollowSwitch': '<S46>:48'
    switch (codegenReal2Mission_DW.is_FollowSwitch) {
      case codegenReal2Mission_IN_FollowA:
        // During 'FollowA': '<S46>:49'
        if (*sfEvent == codegenReal2Mission_event_shiftFollow) {
            // Transition: '<S46>:52'
            codegenReal2Mission_DW.is_FollowSwitch =
                codegenReal2Mission_IN_FollowB;

            // Entry 'FollowB': '<S46>:51'
            codegenReal2Mission_DW.followSwitch = false;
        } else {
            codegenReal2Mission_DW.followSwitch = true;
        }
        break;

      case codegenReal2Mission_IN_FollowB:
        // During 'FollowB': '<S46>:51'
        if (*sfEvent == codegenReal2Mission_event_shiftFollow) {
            // Transition: '<S46>:53'
            codegenReal2Mission_DW.is_FollowSwitch =
                codegenReal2Mission_IN_FollowA;

            // Entry 'FollowA': '<S46>:49'
            codegenReal2Mission_DW.followSwitch = true;
        } else {
            codegenReal2Mission_DW.followSwitch = false;
        }
        break;
    }
}

Msg_missionCmd *codegenReal2MissionModelClass::
    codegenReal2Mission_MissionUAVScheduling_In3_RecvMsg(void)
{
    Msg_missionCmd *msg;

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'
    msg =
        &codegenReal2Mission_DW.Queue_InsertedFor_MissionUAVScheduling_at_inport_2_Out1RecvBuffer;

    // Queue generated from: '<S7>/MissionUAVScheduling'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (codegenReal2Mission_pop_h
             (&codegenReal2Mission_DW.Queue_InsertedFor_MissionUAVScheduling_at_inport_2_Queue,
              &codegenReal2Mission_DW.Queue_InsertedFor_MissionUAVScheduling_at_inport_2_Out1RecvBuffer))
          ^ 1))) {
        msg = nullptr;
    }

    return msg;
}

// Function for Chart: '<S7>/MissionUAVScheduling'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_sf_msg_pop_ExecMsg
    (boolean_T *ExecMsg_isValid)
{
    boolean_T isPresent;
    if (*ExecMsg_isValid) {
        isPresent = true;
    } else {
        codegenReal2Mission_DW.ExecMsg_msgHandle =
            codegenReal2Mission_MissionUAVScheduling_In3_RecvMsg();
        if (codegenReal2Mission_DW.ExecMsg_msgHandle != nullptr) {
            codegenReal2Mission_DW.ExecMsg_msgDataPtr =
                &(static_cast<Msg_missionCmd *>
                  (codegenReal2Mission_DW.ExecMsg_msgHandle))->fData;
            isPresent = true;
        } else {
            isPresent = false;
        }

        *ExecMsg_isValid = isPresent;
    }

    return isPresent;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_SendMsg(const
    Msg_missionCmd *msg)
{
    int32_T status{ 1 };

    // Queue generated from: '<S7>/MsgRateTransitionA'
    if (codegenReal2Mission_push_i
            (&codegenReal2Mission_DW.Queue_InsertedFor_MsgRateTransitionA_at_inport_0_Queue,
             msg)) {
        status = 0;
    }

    // End of Queue generated from: '<S7>/MsgRateTransitionA'
    return status;
}

// Function for Chart: '<S7>/MissionUAVScheduling'
void codegenReal2MissionModelClass::
    codegenReal2Mission_sf_msg_forward_ExecMsg_ExecMsgA(boolean_T
    *ExecMsg_isValid)
{
    if (*ExecMsg_isValid) {
        codegenReal2Mission_Receive_SendMsg(static_cast<Msg_missionCmd *>
            (codegenReal2Mission_DW.ExecMsg_msgHandle));
        *ExecMsg_isValid = false;
    }
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_e_SendMsg(
    const Msg_missionCmd *msg)
{
    int32_T status{ 1 };

    // Queue generated from: '<S7>/MsgRateTransitionB'
    if (codegenReal2Mission_push_i
            (&codegenReal2Mission_DW.Queue_InsertedFor_MsgRateTransitionB_at_inport_0_Queue,
             msg)) {
        status = 0;
    }

    // End of Queue generated from: '<S7>/MsgRateTransitionB'
    return status;
}

// Function for Chart: '<S7>/MissionUAVScheduling'
void codegenReal2MissionModelClass::
    codegenReal2Mission_sf_msg_forward_ExecMsg_ExecMsgB(boolean_T
    *ExecMsg_isValid)
{
    if (*ExecMsg_isValid) {
        codegenReal2Mission_Receive_e_SendMsg(static_cast<Msg_missionCmd *>
            (codegenReal2Mission_DW.ExecMsg_msgHandle));
        *ExecMsg_isValid = false;
    }
}

// Function for Chart: '<S7>/MissionUAVScheduling'
void codegenReal2MissionModelClass::codegenReal2Mission_sf_msg_discard_ExecMsg
    (boolean_T *ExecMsg_isValid)
{
    *ExecMsg_isValid = false;
}

// Function for MATLAB Function: '<S52>/ReadPursuitShiftPercentage'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata_hj(void)
    const
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (codegenReal2Mission_DW.eml_openfiles_b[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S52>/ReadPursuitShiftPercentage'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen_k(const char_T *
    cfilename, const char_T *cpermission)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata_hj();
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            codegenReal2Mission_DW.eml_openfiles_b[static_cast<int32_T>(
                static_cast<int32_T>(j) - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S52>/ReadPursuitShiftPercentage'
void codegenReal2MissionModelClass::codegenReal2Mission_fread_e(real_T fileID,
    emxArray_char_T_codegenReal2Mission_T *A)
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
        filestar = codegenReal2Mission_DW.eml_openfiles_b[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
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
            codegenReal2Mission_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S52>/ReadPursuitShiftPercentage'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose_l(real_T fid)
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
        filestar = codegenReal2Mission_DW.eml_openfiles_b[static_cast<int32_T>(
            static_cast<int32_T>(b_fileid) - 3)];
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
            codegenReal2Mission_DW.eml_openfiles_b[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = NULL;
        }
    }

    return st;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_d_RecvData
    (missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S7>/MsgRateTransitionA'
    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_MsgRateTransitionA_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S7>/MsgRateTransitionA'
    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_e_RecvData
    (missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S7>/MsgRateTransitionB'
    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_MsgRateTransitionB_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S7>/MsgRateTransitionB'
    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_RecvData
    (missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S2>/RcvImmedCMD' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S2>/RcvImmedCMD'
    return status;
}

// Function for MATLAB Function: '<S9>/ReadHomePoint'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata_p(void) const
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (codegenReal2Mission_DW.eml_openfiles[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S9>/ReadHomePoint'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen_o(const char_T *
    cfilename, const char_T *cpermission)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata_p();
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            codegenReal2Mission_DW.eml_openfiles[static_cast<int32_T>(
                static_cast<int32_T>(j) - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S9>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_fread_i(real_T fileID,
    emxArray_char_T_codegenReal2Mission_T *A)
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
        filestar = codegenReal2Mission_DW.eml_openfiles[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
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
            codegenReal2Mission_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S9>/ReadHomePoint'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose_m(real_T fid)
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
        filestar = codegenReal2Mission_DW.eml_openfiles[static_cast<int32_T>(
            static_cast<int32_T>(b_fileid) - 3)];
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
            codegenReal2Mission_DW.eml_openfiles[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = NULL;
        }
    }

    return st;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop_j
    (Buffer_DangerInfo *q, Msg_DangerInfo *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<S2>/DangerLidarScanPoints'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<S2>/DangerLidarScanPoints'
    return isPop;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_h_RecvData
    (DangerInfo *data)
{
    Msg_DangerInfo msg;
    int32_T status{ 1 };

    // Queue generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'

    if (codegenReal2Mission_pop_j
            (&codegenReal2Mission_DW.Queue_InsertedFor_DangerLidarScanPoints_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S2>/DangerLidarScanPoints'
    return status;
}

// Function for MATLAB Function: '<S13>/ReadHomePoint'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata_h(void) const
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (codegenReal2Mission_DW.eml_openfiles_m[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S13>/ReadHomePoint'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen_p(const char_T *
    cfilename, const char_T *cpermission)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata_h();
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            codegenReal2Mission_DW.eml_openfiles_m[static_cast<int32_T>(
                static_cast<int32_T>(j) - 1)] = filestar;
            tmp = static_cast<int32_T>(static_cast<int32_T>(j) + 2);
            if (static_cast<int32_T>(static_cast<int32_T>(j) + 2) > 127) {
                tmp = 127;
            }

            fileid = static_cast<int8_T>(tmp);
        }
    }

    return fileid;
}

// Function for MATLAB Function: '<S13>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_fread_j(real_T fileID,
    emxArray_char_T_codegenReal2Mission_T *A)
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
        filestar = codegenReal2Mission_DW.eml_openfiles_m[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
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
            codegenReal2Mission_emxEnsureCapacity_char_T(A, tmp);
            for (i = 0; i <= loop_ub; i++) {
                A->data[static_cast<int32_T>(numRead + i)] = tbuf[i];
            }
        }
    }
}

// Function for MATLAB Function: '<S13>/ReadHomePoint'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose_g(real_T fid)
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
        filestar = codegenReal2Mission_DW.eml_openfiles_m[static_cast<int32_T>(
            static_cast<int32_T>(b_fileid) - 3)];
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
            codegenReal2Mission_DW.eml_openfiles_m[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S13>/getDangerList'
void codegenReal2MissionModelClass::codegenReal2Mission_unique_vector(const
    real_T a_data[], const int32_T *a_size, real_T b_data[], int32_T *b_size,
    int32_T ndx_data[], int32_T *ndx_size, int32_T pos_data[], int32_T *pos_size)
{
    real_T b_data_0[64];
    real_T x;
    int32_T b_iwork_data[64];
    int32_T idx_data[64];
    int32_T iwork_data[64];
    int32_T r_data[64];
    int32_T b_i;
    int32_T b_tmp_tmp;
    int32_T e_j;
    int32_T f_k;
    int32_T i2;
    int32_T kEnd;
    int32_T n;
    int32_T p;
    int32_T pEnd;
    int32_T q;
    int32_T qEnd;
    boolean_T exitg1;
    *pos_size = *a_size;
    b_i = static_cast<int32_T>(static_cast<int8_T>(*a_size));
    for (pEnd = 0; pEnd <= static_cast<int32_T>(b_i - 1); pEnd++) {
        idx_data[pEnd] = 0;
    }

    if (*a_size != 0) {
        b_i = static_cast<int32_T>(*a_size - 1);
        for (i2 = 1; i2 <= b_i; i2 += 2) {
            if (static_cast<boolean_T>(static_cast<int32_T>((a_data[static_cast<
                    int32_T>(i2 - 1)] <= a_data[i2]) | static_cast<int32_T>(std::
                    isnan(a_data[i2]))))) {
                idx_data[static_cast<int32_T>(i2 - 1)] = i2;
                idx_data[i2] = static_cast<int32_T>(i2 + 1);
            } else {
                idx_data[static_cast<int32_T>(i2 - 1)] = static_cast<int32_T>(i2
                    + 1);
                idx_data[i2] = i2;
            }
        }

        if (static_cast<uint32_T>(static_cast<uint32_T>(*a_size) & 1U) != 0U) {
            idx_data[static_cast<int32_T>(*a_size - 1)] = *a_size;
        }

        b_i = 2;
        while (b_i < static_cast<int32_T>(static_cast<int32_T>(*a_size + 1) - 1))
        {
            i2 = static_cast<int32_T>(b_i << 1);
            e_j = 1;
            pEnd = static_cast<int32_T>(b_i + 1);
            while (pEnd < static_cast<int32_T>(*a_size + 1)) {
                p = e_j;
                q = static_cast<int32_T>(pEnd - 1);
                qEnd = static_cast<int32_T>(e_j + i2);
                if (qEnd > static_cast<int32_T>(*a_size + 1)) {
                    qEnd = static_cast<int32_T>(*a_size + 1);
                }

                f_k = 0;
                kEnd = static_cast<int32_T>(qEnd - e_j);
                while (static_cast<int32_T>(f_k + 1) <= kEnd) {
                    x = a_data[static_cast<int32_T>(idx_data[q] - 1)];
                    b_tmp_tmp = idx_data[static_cast<int32_T>(p - 1)];
                    if (static_cast<boolean_T>(static_cast<int32_T>((a_data[
                            static_cast<int32_T>(b_tmp_tmp - 1)] <= x) |
                            static_cast<int32_T>(std::isnan(x))))) {
                        iwork_data[f_k] = b_tmp_tmp;
                        p = static_cast<int32_T>(p + 1);
                        if (p == pEnd) {
                            while (static_cast<int32_T>(q + 1) < qEnd) {
                                f_k = static_cast<int32_T>(f_k + 1);
                                iwork_data[f_k] = idx_data[q];
                                q = static_cast<int32_T>(q + 1);
                            }
                        }
                    } else {
                        iwork_data[f_k] = idx_data[q];
                        q = static_cast<int32_T>(q + 1);
                        if (static_cast<int32_T>(q + 1) == qEnd) {
                            while (p < pEnd) {
                                f_k = static_cast<int32_T>(f_k + 1);
                                iwork_data[f_k] = idx_data[static_cast<int32_T>
                                    (p - 1)];
                                p = static_cast<int32_T>(p + 1);
                            }
                        }
                    }

                    f_k = static_cast<int32_T>(f_k + 1);
                }

                for (pEnd = 0; pEnd <= static_cast<int32_T>(kEnd - 1); pEnd++) {
                    idx_data[static_cast<int32_T>(static_cast<int32_T>(e_j +
                        pEnd) - 1)] = iwork_data[pEnd];
                }

                e_j = qEnd;
                pEnd = static_cast<int32_T>(qEnd + b_i);
            }

            b_i = i2;
        }
    }

    n = *a_size;
    for (b_i = 0; b_i <= static_cast<int32_T>(n - 1); b_i++) {
        b_data[b_i] = a_data[static_cast<int32_T>(idx_data[b_i] - 1)];
    }

    i2 = 0;
    while ((static_cast<int32_T>(i2 + 1) <= *a_size) && std::isinf(b_data[i2]) &&
           (b_data[i2] < 0.0)) {
        i2 = static_cast<int32_T>(i2 + 1);
    }

    qEnd = i2;
    i2 = *a_size;
    while ((i2 >= 1) && std::isnan(b_data[static_cast<int32_T>(i2 - 1)])) {
        i2 = static_cast<int32_T>(i2 - 1);
    }

    b_i = static_cast<int32_T>(*a_size - i2);
    exitg1 = false;
    while ((!exitg1) && (i2 >= 1)) {
        x = b_data[static_cast<int32_T>(i2 - 1)];
        if (std::isinf(x) && (x > 0.0)) {
            i2 = static_cast<int32_T>(i2 - 1);
        } else {
            exitg1 = true;
        }
    }

    e_j = static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>(*a_size
        - i2) - b_i) - 1);
    n = -1;
    if (qEnd > 0) {
        n = 0;
        for (pEnd = 0; pEnd <= static_cast<int32_T>(qEnd - 1); pEnd++) {
            pos_data[static_cast<int32_T>(idx_data[pEnd] - 1)] = 1;
        }
    }

    while (static_cast<int32_T>(qEnd + 1) <= i2) {
        x = b_data[qEnd];
        kEnd = qEnd;
        do {
            qEnd = static_cast<int32_T>(qEnd + 1);
        } while (!((static_cast<int32_T>(qEnd + 1) > i2) || (b_data[qEnd] != x)));

        n = static_cast<int32_T>(n + 1);
        b_data[n] = x;
        for (pEnd = static_cast<int32_T>(kEnd + 1); pEnd <= qEnd; pEnd++) {
            pos_data[static_cast<int32_T>(idx_data[static_cast<int32_T>(pEnd - 1)]
                - 1)] = static_cast<int32_T>(n + 1);
        }

        idx_data[n] = idx_data[kEnd];
    }

    if (static_cast<int32_T>(e_j + 1) > 0) {
        n = static_cast<int32_T>(n + 1);
        b_data[n] = b_data[i2];
        for (kEnd = 0; kEnd <= e_j; kEnd++) {
            pos_data[static_cast<int32_T>(idx_data[static_cast<int32_T>(i2 +
                kEnd)] - 1)] = static_cast<int32_T>(n + 1);
        }

        idx_data[n] = idx_data[i2];
    }

    qEnd = static_cast<int32_T>(static_cast<int32_T>(i2 + e_j) + 1);
    for (i2 = 0; i2 <= static_cast<int32_T>(b_i - 1); i2++) {
        pEnd = static_cast<int32_T>(n + i2);
        e_j = static_cast<int32_T>(qEnd + i2);
        b_data[static_cast<int32_T>(pEnd + 1)] = b_data[e_j];
        e_j = idx_data[e_j];
        pos_data[static_cast<int32_T>(e_j - 1)] = static_cast<int32_T>(pEnd + 2);
        idx_data[static_cast<int32_T>(pEnd + 1)] = e_j;
    }

    n = static_cast<int32_T>(static_cast<int32_T>(n + b_i) + 1);
    *ndx_size = n;
    n = static_cast<int32_T>(static_cast<uint8_T>(n));
    for (i2 = 0; i2 <= static_cast<int32_T>(n - 1); i2++) {
        ndx_data[i2] = idx_data[i2];
    }

    b_i = static_cast<int32_T>(static_cast<int8_T>(*ndx_size));
    for (pEnd = 0; pEnd <= static_cast<int32_T>(b_i - 1); pEnd++) {
        r_data[pEnd] = 0;
    }

    if (*ndx_size != 0) {
        i2 = static_cast<int32_T>(*ndx_size - 1);
        for (e_j = 1; e_j <= i2; e_j += 2) {
            if (ndx_data[static_cast<int32_T>(e_j - 1)] <= ndx_data[e_j]) {
                r_data[static_cast<int32_T>(e_j - 1)] = e_j;
                r_data[e_j] = static_cast<int32_T>(e_j + 1);
            } else {
                r_data[static_cast<int32_T>(e_j - 1)] = static_cast<int32_T>(e_j
                    + 1);
                r_data[e_j] = e_j;
            }
        }

        if (static_cast<uint32_T>(static_cast<uint32_T>(*ndx_size) & 1U) != 0U)
        {
            r_data[static_cast<int32_T>(*ndx_size - 1)] = *ndx_size;
        }

        i2 = 2;
        while (i2 < static_cast<int32_T>(static_cast<int32_T>(*ndx_size + 1) - 1))
        {
            e_j = static_cast<int32_T>(i2 << 1);
            qEnd = 1;
            p = static_cast<int32_T>(i2 + 1);
            while (p < static_cast<int32_T>(*ndx_size + 1)) {
                int32_T j_k;
                q = qEnd;
                f_k = p;
                kEnd = static_cast<int32_T>(qEnd + e_j);
                if (kEnd > static_cast<int32_T>(*ndx_size + 1)) {
                    kEnd = static_cast<int32_T>(*ndx_size + 1);
                }

                j_k = 0;
                pEnd = static_cast<int32_T>(kEnd - qEnd);
                while (static_cast<int32_T>(j_k + 1) <= pEnd) {
                    int32_T tmp;
                    b_tmp_tmp = r_data[static_cast<int32_T>(f_k - 1)];
                    tmp = r_data[static_cast<int32_T>(q - 1)];
                    if (ndx_data[static_cast<int32_T>(tmp - 1)] <= ndx_data[
                            static_cast<int32_T>(b_tmp_tmp - 1)]) {
                        b_iwork_data[j_k] = tmp;
                        q = static_cast<int32_T>(q + 1);
                        if (q == p) {
                            while (f_k < kEnd) {
                                j_k = static_cast<int32_T>(j_k + 1);
                                b_iwork_data[j_k] = r_data[static_cast<int32_T>
                                    (f_k - 1)];
                                f_k = static_cast<int32_T>(f_k + 1);
                            }
                        }
                    } else {
                        b_iwork_data[j_k] = b_tmp_tmp;
                        f_k = static_cast<int32_T>(f_k + 1);
                        if (f_k == kEnd) {
                            while (q < p) {
                                j_k = static_cast<int32_T>(j_k + 1);
                                b_iwork_data[j_k] = r_data[static_cast<int32_T>
                                    (q - 1)];
                                q = static_cast<int32_T>(q + 1);
                            }
                        }
                    }

                    j_k = static_cast<int32_T>(j_k + 1);
                }

                for (p = 0; p <= static_cast<int32_T>(pEnd - 1); p++) {
                    r_data[static_cast<int32_T>(static_cast<int32_T>(qEnd + p) -
                        1)] = b_iwork_data[p];
                }

                qEnd = kEnd;
                p = static_cast<int32_T>(kEnd + i2);
            }

            i2 = e_j;
        }
    }

    for (pEnd = 0; pEnd <= static_cast<int32_T>(b_i - 1); pEnd++) {
        b_data_0[pEnd] = b_data[static_cast<int32_T>(r_data[pEnd] - 1)];
    }

    *b_size = static_cast<int32_T>(static_cast<int8_T>(*ndx_size));
    for (pEnd = 0; pEnd <= static_cast<int32_T>(b_i - 1); pEnd++) {
        b_data[pEnd] = b_data_0[pEnd];
    }

    for (b_i = 0; b_i <= static_cast<int32_T>(n - 1); b_i++) {
        i2 = r_data[b_i];
        ndx_data[b_i] = idx_data[static_cast<int32_T>(i2 - 1)];
        iwork_data[static_cast<int32_T>(i2 - 1)] = static_cast<int32_T>(b_i + 1);
    }

    i2 = *a_size;
    for (pEnd = 0; pEnd <= static_cast<int32_T>(i2 - 1); pEnd++) {
        pos_data[pEnd] = iwork_data[static_cast<int32_T>(pos_data[pEnd] - 1)];
    }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_real_T
    (emxArray_real_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
    emxArray_real_T_codegenReal2Mission_T *emxArray;
    *pEmxArray = static_cast<emxArray_real_T_codegenReal2Mission_T *>(std::
        malloc(sizeof(emxArray_real_T_codegenReal2Mission_T)));
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

void codegenReal2MissionModelClass::codegenReal2Mission_emxEnsureCapacity_real_T
    (emxArray_real_T_codegenReal2Mission_T *emxArray, int32_T oldNumel)
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

void codegenReal2MissionModelClass::codegenReal2Mission_emxFree_real_T
    (emxArray_real_T_codegenReal2Mission_T **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_real_T_codegenReal2Mission_T *>
            (nullptr)) {
        if (((*pEmxArray)->data != static_cast<real_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_real_T_codegenReal2Mission_T *>
            (nullptr);
    }
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S2>/FeedbackCurrentMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints'
    //   Receive: '<S6>/ReceiveThisMission'

    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_4_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S2>/FeedbackCurrentMission'
    return status;
}

// Function for MATLAB Function: '<S42>/TimeConverter'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec(real_T dd,
    real_T *y, real_T *mo, real_T *d, real_T *h, real_T *m, real_T *s)
{
    creal_T a;
    creal_T b_c;
    creal_T c_ahi_0;
    creal_T c_s;
    creal_T t;
    real_T b_thi;
    real_T b_tmp;
    real_T c_ahi;
    real_T c_tmp;
    int32_T i;
    int32_T idn;
    b_c.re = dd / 8.64E+7;
    t = codegenReal2Mission_two_prod(b_c.re);
    c_s.re = 0.0;
    c_s.im = 0.0;
    if (dd != t.re) {
        c_s = codegenReal2Mission_two_diff(dd, t.re);
    }

    c_s.re -= 0.0 * t.im;
    c_s.im -= t.im;
    b_tmp = (c_s.re + c_s.im) / 8.64E+7;
    b_thi = 0.0;
    c_ahi = b_c.re;
    if (b_tmp != 0.0) {
        c_ahi = b_c.re + b_tmp;
        b_thi = b_tmp - (c_ahi - b_c.re);
    }

    if (std::isnan(b_thi)) {
        b_thi = 0.0;
    }

    c_ahi_0.re = c_ahi;
    c_ahi_0.im = b_thi;
    c_s = floor_0EeG1Grp(c_ahi_0);
    b_thi = c_s.re + c_s.im;
    b_c = codegenReal2Mission_two_prod(c_s.re);
    c_tmp = c_s.im * 8.64E+7;
    c_ahi = b_c.im;
    b_tmp = b_c.re;
    if (c_tmp != 0.0) {
        c_ahi = b_c.im + c_tmp;
        b_tmp = b_c.re + c_ahi;
        c_ahi -= b_tmp - b_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    b_c = codegenReal2Mission_two_diff(dd, b_tmp);
    t = codegenReal2Mission_two_diff(0.0, c_ahi);
    c_ahi = b_c.im;
    b_tmp = b_c.re;
    if (t.re != 0.0) {
        c_ahi = b_c.im + t.re;
        b_tmp = b_c.re + c_ahi;
        c_ahi -= b_tmp - b_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    b_c.re = b_tmp;
    if (t.im != 0.0) {
        c_ahi += t.im;
        b_tmp += c_ahi;
        c_ahi -= b_tmp - b_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    a.re = b_tmp;
    b_c.re = b_tmp / 1000.0;
    c_s = split_JEzbX7NR(b_c.re);
    b_tmp = b_c.re * 1000.0;
    c_tmp = (c_s.re * 1000.0 - b_tmp) + c_s.im * 1000.0;
    idn = 0;
    if (std::isnan(c_tmp)) {
        idn = 1;
    }

    if (static_cast<int32_T>(idn - 1) >= 0) {
        c_tmp = 0.0;
    }

    c_s.re = 0.0;
    c_s.im = 0.0;
    if (a.re != b_tmp) {
        c_s = codegenReal2Mission_two_diff(a.re, b_tmp);
    }

    c_s.re = (0.0 * c_ahi + c_s.re) - 0.0 * c_tmp;
    c_s.im = (c_s.im + c_ahi) - c_tmp;
    c_tmp = (c_s.re + c_s.im) / 1000.0;
    c_ahi = 0.0;
    b_tmp = b_c.re;
    if (c_tmp != 0.0) {
        b_tmp = b_c.re + c_tmp;
        c_ahi = c_tmp - (b_tmp - b_c.re);
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    a.re = b_tmp;
    a.im = c_ahi;
    c_s = floor_0EeG1Grp(a);
    b_c = codegenReal2Mission_two_diff(b_tmp, c_s.re);
    t = codegenReal2Mission_two_diff(c_ahi, c_s.im);
    c_ahi = b_c.im;
    b_tmp = b_c.re;
    if (t.re != 0.0) {
        c_ahi = b_c.im + t.re;
        b_tmp = b_c.re + c_ahi;
        c_ahi -= b_tmp - b_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    b_c.re = b_tmp;
    if (t.im != 0.0) {
        c_ahi += t.im;
        b_tmp += c_ahi;
        c_ahi -= b_tmp - b_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    b_c.re = b_tmp;
    b_c.im = c_ahi;
    c_ahi = c_s.re + c_s.im;
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
        c_tmp = ((b_thi + 719529.0) - 61.0) - b_tmp * 146097.0;
        b_thi = std::floor(c_tmp / 36524.0);
        if (b_thi > 3.0) {
            b_thi = 3.0;
        }

        dc = c_tmp - b_thi * 36524.0;
        c_tmp = std::floor(dc / 1461.0);
        dc -= c_tmp * 1461.0;
        b_a = std::floor(dc / 365.0);
        if (b_a > 3.0) {
            b_a = 3.0;
        }

        dc -= b_a * 365.0;
        *y = ((b_tmp * 400.0 + b_thi * 100.0) + c_tmp * 4.0) + b_a;
        b_thi = std::floor((dc * 5.0 + 308.0) / 153.0) - 2.0;
        *d = ((dc - std::floor((b_thi + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    }

    if (b_thi > 9.0) {
        (*y)++;
        *mo = (b_thi + 2.0) - 11.0;
    } else {
        *mo = (b_thi + 2.0) + 1.0;
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((c_ahi >= 0.0) & (c_ahi <=
            2.147483647E+9)))) {
        idn = static_cast<int32_T>(std::round(c_ahi));
        i = static_cast<int32_T>(idn - static_cast<int32_T>(3600 * div_s32(idn,
            3600)));
        *h = std::trunc(static_cast<real_T>(idn) / 3600.0);
        *m = std::trunc(static_cast<real_T>(i) / 60.0);
        b_thi = static_cast<real_T>(static_cast<int32_T>(i - static_cast<int32_T>
            (60 * div_s32(i, 60))));
    } else {
        *h = std::floor(c_ahi / 3600.0);
        *m = std::floor((c_ahi - 3600.0 * *h) / 60.0);
        b_thi = c_ahi - 60.0 * *m;
    }

    *s = (b_c.re + b_c.im) + b_thi;
    if (*s == 60.0) {
        *s = 59.999999999999993;
    }

    if (dd == (rtInf)) {
        *y = (rtInf);
    } else if (dd == (rtMinusInf)) {
        *y = (rtMinusInf);
    }
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveMissionA_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S47>/Send'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S7>/ReceiveMissionA'
    if (codegenReal2Mission_push_i
            (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveMissionA_at_inport_0_Queue,
             &msg)) {
        status = 0;
    }

    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveMissionA_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S7>/ReceiveMissionA'
    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveMissionA_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S7>/ReceiveMissionA'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveMissionB_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S2>/DangerLidarScanPoints' incorporates:
    //   Send: '<S48>/Send'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S7>/ReceiveMissionB'
    if (codegenReal2Mission_push_i
            (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveMissionB_at_inport_0_Queue,
             &msg)) {
        status = 0;
    }

    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveMissionB_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S7>/ReceiveMissionB'
    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveMissionB_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S7>/ReceiveMissionB'
    return status;
}

void codegenReal2MissionModelClass::codegenReal2Mission_initQueue
    (Queue_IndividualUAVCmd *q, QueuePolicy_T policy, int32_T capacity,
     Msg_IndividualUAVCmd *qPool)
{
    // Start for Queue: '<S83>/Queue'
    q->fPolicy = policy;
    q->fCapacity = capacity;
    q->fHead = -1;
    q->fTail = -1;
    q->fArray = qPool;
}

// Model step function for TID0
void codegenReal2MissionModelClass::step() // Sample time: [0.0s, 0.0s]
{
    static const char_T u[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

    static const char_T w[15]{ 'S', 'h', 'i', 'f', 't', 'P', 'e', 'r', 'c', 'e',
        'n', 't', 'a', 'g', 'e' };

    static const char_T v[12]{ 'P', 'u', 'r', 's', 'u', 'i', 't', 'S', 'h', 'i',
        'f', 't' };

    DangerInfo rtb_CreatDanger;
    FixedWingGuidanceStateBus rtb_FixedWingGuidanceStateBus;
    FixedWingGuidanceStateBus rtb_SwitchMissionUAVState;
    IndividualUAVCmd rtb_IndivCMD;
    TaskStatus rtb_CreateStatusBus;
    emxArray_char_T_codegenReal2Mission_T *b_curKey;
    emxArray_char_T_codegenReal2Mission_T *curKey;
    emxArray_char_T_codegenReal2Mission_T *curLine;
    emxArray_char_T_codegenReal2Mission_T *curSection;
    emxArray_char_T_codegenReal2Mission_T *curVal;
    emxArray_char_T_codegenReal2Mission_T *data;
    emxArray_char_T_codegenReal2Mission_T *data_0;
    emxArray_char_T_codegenReal2Mission_T *data_1;
    emxArray_char_T_codegenReal2Mission_T *data_2;
    emxArray_char_T_codegenReal2Mission_T *data_3;
    emxArray_char_T_codegenReal2Mission_T *data_4;
    emxArray_char_T_codegenReal2Mission_T *data_5;
    emxArray_char_T_codegenReal2Mission_T *data_6;
    emxArray_char_T_codegenReal2Mission_T *data_7;
    emxArray_char_T_codegenReal2Mission_T *data_8;
    emxArray_char_T_codegenReal2Mission_T *data_9;
    emxArray_char_T_codegenReal2Mission_T *data_a;
    emxArray_char_T_codegenReal2Mission_T *data_b;
    emxArray_char_T_codegenReal2Mission_T *data_c;
    emxArray_char_T_codegenReal2Mission_T *q;
    emxArray_char_T_codegenReal2Mission_T *ret;
    emxArray_char_T_codegenReal2Mission_T *tmp_8;
    emxArray_char_T_codegenReal2Mission_T *tmp_9;
    emxArray_char_T_codegenReal2Mission_T *tmp_a;
    emxArray_char_T_codegenReal2Mission_T *tmp_b;
    emxArray_char_T_codegenReal2Mission_T *tmp_c;
    emxArray_char_T_codegenReal2Mission_T *tmp_d;
    emxArray_char_T_codegenReal2Mission_T *tmp_e;
    emxArray_char_T_codegenReal2Mission_T *tmp_f;
    emxArray_char_T_codegenReal2Mission_T *tmp_g;
    emxArray_char_T_codegenReal2Mission_T *tmp_h;
    emxArray_char_T_codegenReal2Mission_T *tmp_i;
    emxArray_char_T_codegenReal2Mission_T *tmp_j;
    emxArray_char_T_codegenReal2Mission_T *tmp_k;
    emxArray_char_T_codegenReal2Mission_T *tmp_l;
    emxArray_char_T_codegenReal2Mission_T *tmp_m;
    emxArray_char_T_codegenReal2Mission_T *tmp_n;
    emxArray_char_T_codegenReal2Mission_T *tmp_o;
    emxArray_char_T_codegenReal2Mission_T *x;
    emxArray_real_T_codegenReal2Mission_T *Lat_0;
    emxArray_real_T_codegenReal2Mission_T *b_b;
    emxArray_real_T_codegenReal2Mission_T *b_tmp;
    emxArray_real_T_codegenReal2Mission_T *theta;
    emxArray_real_T_codegenReal2Mission_T *tmp;
    emxArray_real_T_codegenReal2Mission_T *varargin_2;
    missionCmd rtb_FeedbackCMD;
    missionCmd rtb_FlightCMD;
    missionCmd rtb_ImmedCMD;
    creal_T Alt_0;
    creal_T Alt_1;
    creal_T Alt_2;
    creal_T TimeNow_data;
    creal_T b_this_data;
    real_T DangerList_data[256];
    real_T DangerList_data_1[256];
    real_T Output[256];
    real_T DangerList_data_0[64];
    real_T a__1_data[64];
    real_T a__5[7];
    real_T processedInData[7];
    real_T rtb_VectorConcatenate[4];
    real_T tmp_0[2];
    real_T Alt;
    real_T D;
    real_T Lat;
    real_T Lon;
    real_T a__17;
    real_T a__23;
    real_T a__29;
    real_T a__35;
    real_T a__4;
    real_T b_I;
    real_T b_a__35;
    real_T b_x_0;
    real_T da_im;
    real_T rtb_Sum1_idx_0;
    int32_T indx_data[64];
    int32_T ipos_data[64];
    int32_T b;
    int32_T b_md2;
    int32_T i;
    int32_T indx_size;
    int32_T md2;
    int32_T status;
    int32_T status_0;
    int32_T status_1;
    int32_T status_2;
    int32_T wholeSecsFromMillis{ 1 };

    int8_T b_data[64];
    int8_T e_data[64];
    int8_T fileid;
    int8_T ii_data;
    uint8_T rtb_Memory_m;
    boolean_T x_0[64];
    boolean_T b_x[3];
    boolean_T NichtAvoidDanger;
    boolean_T rtb_Receive_o1_m;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // set solver stop time
        if (!((&codegenReal2Mission_M)->Timing.clockTick0+1)) {
            rtsiSetSolverStopTime(&(&codegenReal2Mission_M)->solverInfo,
                                  (((&codegenReal2Mission_M)->Timing.clockTickH0
                                    + 1) * (&codegenReal2Mission_M)
                                   ->Timing.stepSize0 * 4294967296.0));
        } else {
            rtsiSetSolverStopTime(&(&codegenReal2Mission_M)->solverInfo,
                                  (((&codegenReal2Mission_M)->Timing.clockTick0
                                    + 1) * (&codegenReal2Mission_M)
                                   ->Timing.stepSize0 + (&codegenReal2Mission_M
                                   )->Timing.clockTickH0 *
                                   (&codegenReal2Mission_M)->Timing.stepSize0 *
                                   4294967296.0));
        }

        // Update the flag to indicate when data transfers from
        //   Sample time: [0.1s, 0.0s] to Sample time: [0.2s, 0.0s]
        (&codegenReal2Mission_M)->Timing.RateInteraction.b_TID1_2 =
            ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 0);
        ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2)++;
        if (((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2) > 1) {
            (&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 = 0;
        }

        // Update the flag to indicate when data transfers from
        //   Sample time: [0.1s, 0.0s] to Sample time: [1.0s, 0.0s]
        (&codegenReal2Mission_M)->Timing.RateInteraction.b_TID1_3 =
            ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_3 == 0);
        ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_3)++;
        if (((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_3) > 9) {
            (&codegenReal2Mission_M)->Timing.RateInteraction.TID1_3 = 0;
        }
    }                                  // end MajorTimeStep

    // Update absolute time of base rate at minor time step
    if (rtmIsMinorTimeStep((&codegenReal2Mission_M))) {
        (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetT
            (&(&codegenReal2Mission_M)->solverInfo);
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        creal_T tmp_1;
        creal_T tmp_2;
        creal_T tmp_3;
        real_T fid;
        int32_T b_n;
        int32_T exitg2;
        int32_T loop_ub;
        real32_T tmp_7;
        boolean_T exitg1;
        boolean_T guard1{ false };

        boolean_T rtb_AND_p;
        boolean_T rtb_NotEqual;

        // MATLAB Function 'ReadHomePoint': '<S4>:1'
        codegenReal2Mission_emxInit_char_T(&ret, 2);
        codegenReal2Mission_emxInit_char_T(&data, 2);
        codegenReal2Mission_emxInit_char_T(&curSection, 2);
        codegenReal2Mission_emxInit_char_T(&curKey, 2);
        codegenReal2Mission_emxInit_char_T(&curVal, 2);
        codegenReal2Mission_emxInit_char_T(&curLine, 2);
        codegenReal2Mission_emxInit_char_T(&b_curKey, 2);
        codegenReal2Mission_emxInit_char_T(&x, 2);
        codegenReal2Mission_emxInit_char_T(&q, 1);

        // Outputs for Atomic SubSystem: '<Root>/GCSLLA'
        // MATLAB Function: '<S1>/ReadHomePoint'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (codegenReal2Mission_DW.HomePoint_not_empty_o) ^ 1))) {
            // '<S4>:1:5'
            // '<S4>:1:6'
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = codegenReal2Mission_cfopen("config.ini", "rb");
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread(static_cast<real_T>(fileid), q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose(static_cast<real_T>(fileid));
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_o, 2);
                codegenReal2Mission_emxInit_char_T(&data_c, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_c->size[0] * data_c->size[1]);
                    data_c->size[0] = 1;
                    data_c->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_c, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_c->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_c, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_o);
                    codegenReal2Mission_strtrim(tmp_o, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    md2 = 0;
                                    b = 0;
                                } else {
                                    md2 = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - md2);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(md2 + i)];
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    x);
                                codegenReal2Mission_find_token(x,
                                    &wholeSecsFromMillis, &md2);
                                if (wholeSecsFromMillis > static_cast<int32_T>
                                        (md2 - 1)) {
                                    wholeSecsFromMillis = 0;
                                    md2 = 0;
                                } else {
                                    wholeSecsFromMillis = static_cast<int32_T>
                                        (wholeSecsFromMillis - 1);
                                    md2 = static_cast<int32_T>(md2 - 1);
                                }

                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                i = static_cast<int32_T>(b_curKey->size[0] *
                                    b_curKey->size[1]);
                                b_curKey->size[0] = 1;
                                b_curKey->size[1] = static_cast<int32_T>(md2 -
                                    wholeSecsFromMillis);
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (b_curKey, i);
                                loop_ub = static_cast<int32_T>(md2 -
                                    wholeSecsFromMillis);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    b_curKey->data[i] = x->data
                                        [static_cast<int32_T>
                                        (wholeSecsFromMillis + i)];
                                }

                                codegenReal2Mission_strtrim(b_curKey, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp(curSection) &&
                            codegenReal2Mission_strcmp_p(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_c);
                codegenReal2Mission_emxFree_char_T(&tmp_o);
            }

            tmp_1 = codegenReal2Mission_str2double(ret);
            printf("Set Home Point Latitude:\t%f\n", tmp_1.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = codegenReal2Mission_cfopen("config.ini", "rb");
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread(static_cast<real_T>(fileid), q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose(static_cast<real_T>(fileid));
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_n, 2);
                codegenReal2Mission_emxInit_char_T(&data_b, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_b->size[0] * data_b->size[1]);
                    data_b->size[0] = 1;
                    data_b->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_b, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_b->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_b, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_n);
                    codegenReal2Mission_strtrim(tmp_n, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    md2 = 0;
                                } else {
                                    b = 1;
                                    md2 = static_cast<int32_T>(curLine->size[1]
                                        - 1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(md2 - b);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    x);
                                codegenReal2Mission_find_token(x,
                                    &wholeSecsFromMillis, &md2);
                                if (wholeSecsFromMillis > static_cast<int32_T>
                                        (md2 - 1)) {
                                    b_md2 = 0;
                                    b = 0;
                                } else {
                                    b_md2 = static_cast<int32_T>
                                        (wholeSecsFromMillis - 1);
                                    b = static_cast<int32_T>(md2 - 1);
                                }

                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                i = static_cast<int32_T>(b_curKey->size[0] *
                                    b_curKey->size[1]);
                                b_curKey->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - b_md2);
                                b_curKey->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (b_curKey, i);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    b_curKey->data[i] = x->data
                                        [static_cast<int32_T>(b_md2 + i)];
                                }

                                codegenReal2Mission_strtrim(b_curKey, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp(curSection) &&
                            codegenReal2Mission_strcmp_p4(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_b);
                codegenReal2Mission_emxFree_char_T(&tmp_n);
            }

            tmp_2 = codegenReal2Mission_str2double(ret);
            printf("Set Home Point Longitude:\t%f\n", tmp_2.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = codegenReal2Mission_cfopen("config.ini", "rb");
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread(static_cast<real_T>(fileid), q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose(static_cast<real_T>(fileid));
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_m, 2);
                codegenReal2Mission_emxInit_char_T(&data_a, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_a->size[0] * data_a->size[1]);
                    data_a->size[0] = 1;
                    data_a->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_a, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_a->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_a, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_m);
                    codegenReal2Mission_strtrim(tmp_m, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    b_md2 = 0;
                                } else {
                                    b = 1;
                                    b_md2 = static_cast<int32_T>(curLine->size[1]
                                        - 1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b_md2 - b);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    x);
                                codegenReal2Mission_find_token(x, &b_md2,
                                    &wholeSecsFromMillis);
                                if (b_md2 > static_cast<int32_T>
                                        (wholeSecsFromMillis - 1)) {
                                    b = 0;
                                    wholeSecsFromMillis = -1;
                                } else {
                                    b = static_cast<int32_T>(b_md2 - 1);
                                    wholeSecsFromMillis = static_cast<int32_T>
                                        (wholeSecsFromMillis - 2);
                                }

                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                i = static_cast<int32_T>(b_curKey->size[0] *
                                    b_curKey->size[1]);
                                b_curKey->size[0] = 1;
                                b_curKey->size[1] = static_cast<int32_T>(
                                    static_cast<int32_T>(wholeSecsFromMillis - b)
                                    + 1);
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (b_curKey, i);
                                loop_ub = static_cast<int32_T>
                                    (wholeSecsFromMillis - b);
                                for (i = 0; i <= loop_ub; i++) {
                                    b_curKey->data[i] = x->data
                                        [static_cast<int32_T>(b + i)];
                                }

                                codegenReal2Mission_strtrim(b_curKey, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp(curSection) &&
                            codegenReal2Mission_strcmp_p4a(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_a);
                codegenReal2Mission_emxFree_char_T(&tmp_m);
            }

            tmp_3 = codegenReal2Mission_str2double(ret);
            printf("Set Home Point Altitude:\t%f\n", tmp_3.re);
            fflush(stdout);
            codegenReal2Mission_DW.HomePoint_l[0] = tmp_1.re;
            codegenReal2Mission_DW.HomePoint_l[1] = tmp_2.re;
            codegenReal2Mission_DW.HomePoint_l[2] = tmp_3.re;
            codegenReal2Mission_DW.HomePoint_not_empty_o = true;
            b_x[0] = std::isnan(codegenReal2Mission_DW.HomePoint_l[0]);
            b_x[1] = std::isnan(codegenReal2Mission_DW.HomePoint_l[1]);
            b_x[2] = std::isnan(codegenReal2Mission_DW.HomePoint_l[2]);
            rtb_NotEqual = false;
            md2 = 0;
            exitg1 = false;
            while ((!exitg1) && (md2 < 3)) {
                if (b_x[md2]) {
                    rtb_NotEqual = true;
                    exitg1 = true;
                } else {
                    md2 = static_cast<int32_T>(md2 + 1);
                }
            }

            if (rtb_NotEqual) {
                // '<S4>:1:7'
                // '<S4>:1:8'
                codegenReal2Mission_DW.HomePoint_l[0] = 35.8617;
                codegenReal2Mission_DW.HomePoint_l[1] = 104.1954;
                codegenReal2Mission_DW.HomePoint_l[2] = 0.0;
            }
        }

        // '<S4>:1:12'
        codegenReal2Mission_DW.LLA0_c[0] = codegenReal2Mission_DW.HomePoint_l[0];
        codegenReal2Mission_DW.LLA0_c[1] = codegenReal2Mission_DW.HomePoint_l[1];
        codegenReal2Mission_DW.LLA0_c[2] = codegenReal2Mission_DW.HomePoint_l[2];

        // End of MATLAB Function: '<S1>/ReadHomePoint'
        // End of Outputs for SubSystem: '<Root>/GCSLLA'

        // Receive: '<Root>/Receive'
        wholeSecsFromMillis = 1;
        FlightStateRecvData.RecvData(&codegenReal2Mission_DW.Receive_m, sizeof
            (RealUAVStateBus), &wholeSecsFromMillis);

        // RateTransition: '<Root>/Rate Transition'
        rtw_pthread_mutex_lock
            (codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
        codegenReal2Mission_DW.RateTransition_RDBuf =
            codegenReal2Mission_DW.RateTransition_LstBufWR;
        rtw_pthread_mutex_unlock
            (codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
        switch (codegenReal2Mission_DW.RateTransition_RDBuf) {
          case 0:
            for (i = 0; i < 4096; i++) {
                codegenReal2Mission_DW.RateTransition_c[i] =
                    codegenReal2Mission_DW.RateTransition_Buf0[i];
            }
            break;

          case 1:
            for (i = 0; i < 4096; i++) {
                codegenReal2Mission_DW.RateTransition_c[i] =
                    codegenReal2Mission_DW.RateTransition_Buf1[i];
            }
            break;

          case 2:
            for (i = 0; i < 4096; i++) {
                codegenReal2Mission_DW.RateTransition_c[i] =
                    codegenReal2Mission_DW.RateTransition_Buf2[i];
            }
            break;
        }

        // End of RateTransition: '<Root>/Rate Transition'

        // Outputs for Atomic SubSystem: '<Root>/MissionLogic'
        // MATLAB Function: '<S2>/ReadParADRC'
        // MATLAB Function 'MissionLogic/ReadParADRC': '<S11>:1'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (codegenReal2Mission_DW.ParADRC_not_empty) ^ 1))) {
            creal_T tmp_4;
            creal_T tmp_5;
            creal_T tmp_6;

            // '<S11>:1:6'
            // '<S11>:1:7'
            ret->size[0] = 1;
            ret->size[1] = 0;
            fid = codegenReal2Mission_fileManager_d();
            if (fid < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread_eg(fid, q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose_p(fid);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_k, 2);
                codegenReal2Mission_emxInit_char_T(&tmp_l, 2);
                codegenReal2Mission_emxInit_char_T(&data_9, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_9->size[0] * data_9->size[1]);
                    data_9->size[0] = 1;
                    data_9->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_9, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_9->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_9, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_l);
                    codegenReal2Mission_strtrim(tmp_l, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    md2 = 0;
                                    b = 0;
                                } else {
                                    md2 = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - md2);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(md2 + i)];
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    curVal);
                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                codegenReal2Mission_strtok_cxm4(curVal, tmp_k);
                                codegenReal2Mission_strtrim(tmp_k, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp_a(curSection) &&
                            codegenReal2Mission_strcmp_a5(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_9);
                codegenReal2Mission_emxFree_char_T(&tmp_l);
                codegenReal2Mission_emxFree_char_T(&tmp_k);
            }

            tmp_1 = codegenReal2Mission_str2double(ret);
            printf("ADRC control input gain:\t%f\n", tmp_1.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            Lat = codegenReal2Mission_fileManager_d();
            if (Lat < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread_eg(Lat, q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose_p(Lat);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_i, 2);
                codegenReal2Mission_emxInit_char_T(&tmp_j, 2);
                codegenReal2Mission_emxInit_char_T(&data_8, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_8->size[0] * data_8->size[1]);
                    data_8->size[0] = 1;
                    data_8->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_8, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_8->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_8, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_j);
                    codegenReal2Mission_strtrim(tmp_j, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    md2 = 0;
                                } else {
                                    b = 1;
                                    md2 = static_cast<int32_T>(curLine->size[1]
                                        - 1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(md2 - b);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    curVal);
                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                codegenReal2Mission_strtok_cxm4(curVal, tmp_i);
                                codegenReal2Mission_strtrim(tmp_i, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp_a(curSection) &&
                            codegenReal2Mission_strcmp_a5y(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_8);
                codegenReal2Mission_emxFree_char_T(&tmp_j);
                codegenReal2Mission_emxFree_char_T(&tmp_i);
            }

            tmp_2 = codegenReal2Mission_str2double(ret);
            printf("ADRC observer bandwidth:\t%f\n", tmp_2.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            Lon = codegenReal2Mission_fileManager_d();
            if (Lon < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread_eg(Lon, q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose_p(Lon);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_g, 2);
                codegenReal2Mission_emxInit_char_T(&tmp_h, 2);
                codegenReal2Mission_emxInit_char_T(&data_7, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_7->size[0] * data_7->size[1]);
                    data_7->size[0] = 1;
                    data_7->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_7, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_7->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_7, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_h);
                    codegenReal2Mission_strtrim(tmp_h, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    b_md2 = 0;
                                } else {
                                    b = 1;
                                    b_md2 = static_cast<int32_T>(curLine->size[1]
                                        - 1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b_md2 - b);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    curVal);
                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                codegenReal2Mission_strtok_cxm4(curVal, tmp_g);
                                codegenReal2Mission_strtrim(tmp_g, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp_a(curSection) &&
                            codegenReal2Mission_strcmp_a5y5(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_7);
                codegenReal2Mission_emxFree_char_T(&tmp_h);
                codegenReal2Mission_emxFree_char_T(&tmp_g);
            }

            tmp_3 = codegenReal2Mission_str2double(ret);
            printf("ADRC controller bandwidth:\t%f\n", tmp_3.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            Alt = codegenReal2Mission_fileManager_d();
            if (Alt < 0.0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread_eg(Alt, q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose_p(Alt);
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_e, 2);
                codegenReal2Mission_emxInit_char_T(&tmp_f, 2);
                codegenReal2Mission_emxInit_char_T(&data_6, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_6->size[0] * data_6->size[1]);
                    data_6->size[0] = 1;
                    data_6->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_6, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_6->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_6, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_f);
                    codegenReal2Mission_strtrim(tmp_f, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_Receive_o1_m = false;
                        if (curLine->data[0] == '[') {
                            rtb_Receive_o1_m = true;
                        }

                        guard1 = false;
                        if (rtb_Receive_o1_m) {
                            rtb_Receive_o1_m = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_Receive_o1_m = true;
                            }

                            if (rtb_Receive_o1_m) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    wholeSecsFromMillis = 0;
                                    md2 = 0;
                                } else {
                                    wholeSecsFromMillis = 1;
                                    md2 = static_cast<int32_T>(curLine->size[1]
                                        - 1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                curSection->size[1] = static_cast<int32_T>(md2 -
                                    wholeSecsFromMillis);
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
                                loop_ub = static_cast<int32_T>(md2 -
                                    wholeSecsFromMillis);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(wholeSecsFromMillis
                                        + i)];
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
                                rtb_Receive_o1_m = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_Receive_o1_m) ^ 1)))
                                && codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    curVal);
                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                codegenReal2Mission_strtok_cxm4(curVal, tmp_e);
                                codegenReal2Mission_strtrim(tmp_e, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp_a(curSection) &&
                            codegenReal2Mission_strcmp_a5y50(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_6);
                codegenReal2Mission_emxFree_char_T(&tmp_f);
                codegenReal2Mission_emxFree_char_T(&tmp_e);
            }

            tmp_4 = codegenReal2Mission_str2double(ret);
            printf("PID proportional gain:\t\t%f\n", tmp_4.re);
            fflush(stdout);
            codegenReal2Mission_readINI(b_curKey);
            tmp_5 = codegenReal2Mission_str2double(b_curKey);
            printf("PID integrational gain:\t\t%f\n", tmp_5.re);
            fflush(stdout);
            codegenReal2Mission_readINI_p(b_curKey);
            tmp_6 = codegenReal2Mission_str2double(b_curKey);
            printf("PID differential gain:\t\t%f\n", tmp_6.re);
            fflush(stdout);
            codegenReal2Mission_readINI_pw(curVal);
            wholeSecsFromMillis = curVal->size[1];
            i = static_cast<int32_T>(b_curKey->size[0] * b_curKey->size[1]);
            b_curKey->size[0] = 1;
            b_curKey->size[1] = static_cast<int32_T>(curVal->size[1] + 1);
            codegenReal2Mission_emxEnsureCapacity_char_T(b_curKey, i);
            for (i = 0; i <= static_cast<int32_T>(wholeSecsFromMillis - 1); i++)
            {
                b_curKey->data[i] = curVal->data[i];
            }

            b_curKey->data[curVal->size[1]] = '\x00';
            printf("Use ADRC after engaged:\t\t%s\n", &b_curKey->data[0]);
            fflush(stdout);
            codegenReal2Mission_DW.ParADRC.hat_b = tmp_1.re;
            codegenReal2Mission_DW.ParADRC.omega_o = tmp_2.re;
            codegenReal2Mission_DW.ParADRC.omega_c = tmp_3.re;
            codegenReal2Mission_DW.ParADRC.P = tmp_4.re;
            codegenReal2Mission_DW.ParADRC.I = tmp_5.re;
            codegenReal2Mission_DW.ParADRC.D = tmp_6.re;
            codegenReal2Mission_DW.ParADRC.useADRC = static_cast<boolean_T>(
                static_cast<int32_T>(static_cast<int32_T>
                (codegenReal2Mission_strcmp_a5y50m(curVal)) ^ 1));
            codegenReal2Mission_DW.ParADRC_not_empty = true;

            // '<S11>:1:8'
            codegenReal2Mission_DW.ParamADRC_e = codegenReal2Mission_DW.ParADRC;
        }

        // End of MATLAB Function: '<S2>/ReadParADRC'

        // Outputs for Atomic SubSystem: '<S2>/PreProcessMissionCMD'
        // Outputs for Atomic SubSystem: '<S10>/MissionValidation'
        // Receive: '<S82>/Receive'
        wholeSecsFromMillis = codegenReal2Mission_Receive_RecvData
            (&codegenReal2Mission_DW.Receive_o2_m);

        // Outputs for Enabled SubSystem: '<S82>/TriggerMissionDispatch' incorporates:
        //   EnablePort: '<S84>/Enable'

        if (wholeSecsFromMillis != 1) {
            // MATLAB Function: '<S84>/CommandCheck' incorporates:
            //   DataStoreRead: '<S84>/ReadPreviousCMD'

            // MATLAB Function 'MissionLogic/PreProcessMissionCMD/MissionValidation/TriggerMissionDispatch/CommandCheck': '<S85>:1' 
            // '<S85>:1:6'
            processedInData[0] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_m.StartTime.year);
            processedInData[1] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_m.StartTime.month);
            processedInData[2] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_m.StartTime.day);
            processedInData[3] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_m.StartTime.hour);
            processedInData[4] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_m.StartTime.minute);
            processedInData[5] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_m.StartTime.second);
            processedInData[6] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_m.StartTime.millisecond);
            fid = (codegenReal2Mission_createFromDateVec(processedInData)).re /
                1000.0;
            NichtAvoidDanger = false;
            rtb_FlightCMD.SequenceID = 0;
            rtb_FlightCMD.MissionMode = MissionModes::None;
            rtb_FlightCMD.MissionLocation.Lat = 0.0;
            rtb_FlightCMD.MissionLocation.Lon = 0.0;
            rtb_FlightCMD.MissionLocation.Alt = 0.0;
            rtb_FlightCMD.MissionLocation.degHDG = 0.0;
            rtb_FlightCMD.params.Param1 = 0.0F;
            rtb_FlightCMD.params.Param2 = 0.0F;
            rtb_FlightCMD.params.Param3 = 0.0F;
            rtb_FlightCMD.params.Param4 = 0.0F;
            rtb_FlightCMD.params.Param5 = 0.0F;
            rtb_FlightCMD.params.Param6 = 0.0F;
            rtb_FlightCMD.params.Param7 = 0.0F;
            rtb_FlightCMD.StartPosition.Lat = 0.0;
            rtb_FlightCMD.StartPosition.Lon = 0.0;
            rtb_FlightCMD.StartPosition.Alt = 0.0;
            rtb_FlightCMD.StartPosition.degHDG = 0.0;
            rtb_FlightCMD.numUAV = 0;
            rtb_FlightCMD.FormationPos = 0;
            rtb_FlightCMD.StartTime = 0.0;
            rtb_NotEqual = false;
            rtb_ImmedCMD.SequenceID = 0;
            rtb_ImmedCMD.MissionMode = MissionModes::None;
            rtb_ImmedCMD.MissionLocation.Lat = 0.0;
            rtb_ImmedCMD.MissionLocation.Lon = 0.0;
            rtb_ImmedCMD.MissionLocation.Alt = 0.0;
            rtb_ImmedCMD.MissionLocation.degHDG = 0.0;
            rtb_ImmedCMD.params.Param1 = 0.0F;
            rtb_ImmedCMD.params.Param2 = 0.0F;
            rtb_ImmedCMD.params.Param3 = 0.0F;
            rtb_ImmedCMD.params.Param4 = 0.0F;
            rtb_ImmedCMD.params.Param5 = 0.0F;
            rtb_ImmedCMD.params.Param6 = 0.0F;
            rtb_ImmedCMD.params.Param7 = 0.0F;
            rtb_ImmedCMD.StartPosition.Lat = 0.0;
            rtb_ImmedCMD.StartPosition.Lon = 0.0;
            rtb_ImmedCMD.StartPosition.Alt = 0.0;
            rtb_ImmedCMD.StartPosition.degHDG = 0.0;
            rtb_ImmedCMD.numUAV = 0;
            rtb_ImmedCMD.FormationPos = 0;
            rtb_ImmedCMD.StartTime = 0.0;
            if (codegenReal2Mission_DW.Receive_o2_m.MissionMode != MissionModes::
                    TuneADRC) {
                // '<S85>:1:8'
                // '<S85>:1:9'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (codegenReal2Mission_isequaln
                        (codegenReal2Mission_DW.MissionCMD.SequenceID,
                         codegenReal2Mission_DW.MissionCMD.MissionMode,
                         codegenReal2Mission_DW.MissionCMD.MissionLocation.Lat,
                         codegenReal2Mission_DW.MissionCMD.MissionLocation.Lon,
                         codegenReal2Mission_DW.MissionCMD.MissionLocation.Alt,
                         codegenReal2Mission_DW.MissionCMD.MissionLocation.degHDG,
                         codegenReal2Mission_DW.MissionCMD.params.Param1,
                         codegenReal2Mission_DW.MissionCMD.params.Param2,
                         codegenReal2Mission_DW.MissionCMD.params.Param3,
                         codegenReal2Mission_DW.MissionCMD.params.Param4,
                         codegenReal2Mission_DW.MissionCMD.params.Param5,
                         codegenReal2Mission_DW.MissionCMD.params.Param6,
                         codegenReal2Mission_DW.MissionCMD.params.Param7,
                         codegenReal2Mission_DW.MissionCMD.StartPosition,
                         codegenReal2Mission_DW.MissionCMD.numUAV,
                         codegenReal2Mission_DW.MissionCMD.FormationPos,
                         codegenReal2Mission_DW.MissionCMD.StartTime,
                         codegenReal2Mission_DW.Receive_o2_m.SequenceID,
                         codegenReal2Mission_DW.Receive_o2_m.MissionMode,
                         codegenReal2Mission_DW.Receive_o2_m.MissionLocation,
                         codegenReal2Mission_DW.Receive_o2_m.params,
                         codegenReal2Mission_DW.Receive_o2_m.StartPosition,
                         codegenReal2Mission_DW.Receive_o2_m.numUAV,
                         codegenReal2Mission_DW.Receive_o2_m.FormationPos, fid))
                      ^ 1))) {
                    if (codegenReal2Mission_DW.MissionCMD.SequenceID ==
                            codegenReal2Mission_DW.Receive_o2_m.SequenceID) {
                        printf("Use a new Sequence ID for each new mission!\n");
                        fflush(stdout);
                        printf("PrevCMD SequenceID: %d\n",
                               codegenReal2Mission_DW.MissionCMD.SequenceID);
                        fflush(stdout);
                        printf("NewCMD SequenceID: %d\n",
                               codegenReal2Mission_DW.Receive_o2_m.SequenceID);
                        fflush(stdout);
                    } else {
                        boolean_T guard2{ false };

                        guard1 = false;
                        guard2 = false;
                        if (codegenReal2Mission_DW.Receive_o2_m.MissionMode ==
                                MissionModes::None) {
                            guard2 = true;
                        } else if (static_cast<int32_T>
                                   (codegenReal2Mission_DW.Receive_o2_m.MissionMode)
                                   > 127) {
                            Lat = static_cast<real_T>
                                (codegenReal2Mission_DW.Receive_o2_m.MissionMode);
                            for (Lon = 1.0; Lat / Lon >= 10.0; Lon *= 10.0) {
                            }

                            do {
                                exitg2 = 0;
                                if (Lat != 0.0) {
                                    if (std::isnan(Lat)) {
                                        a__17 = (rtNaN);
                                    } else {
                                        a__17 = std::fmod(Lat, 10.0);
                                    }

                                    if (std::floor(Lat / Lon) != a__17) {
                                        guard2 = true;
                                        exitg2 = 1;
                                    } else {
                                        if ((static_cast<boolean_T>(static_cast<
                                                int32_T>((Lon == 0.0) ^ 1))) &&
                                                (static_cast<boolean_T>(
                                                static_cast<int32_T>(
                                                static_cast<int32_T>(std::isnan
                                                (Lat)) ^ 1))) &&
                                                (static_cast<boolean_T>(
                                                static_cast<int32_T>(
                                                static_cast<int32_T>(std::isinf
                                                (Lon)) ^ 1)))) {
                                            Lat = std::fmod(Lat, Lon);
                                            if (Lat == 0.0) {
                                                Lat = Lon * 0.0;
                                            }
                                        }

                                        Lat = std::floor(Lat / 10.0);
                                        Lon = std::floor(Lon / 100.0);
                                    }
                                } else {
                                    guard1 = true;
                                    exitg2 = 1;
                                }
                            } while (exitg2 == 0);
                        } else {
                            guard1 = true;
                        }

                        if (guard2) {
                            rtb_NotEqual = true;
                            rtb_ImmedCMD.SequenceID =
                                codegenReal2Mission_DW.Receive_o2_m.SequenceID;
                            rtb_ImmedCMD.MissionMode =
                                codegenReal2Mission_DW.Receive_o2_m.MissionMode;
                            rtb_ImmedCMD.MissionLocation =
                                codegenReal2Mission_DW.Receive_o2_m.MissionLocation;
                            rtb_ImmedCMD.params =
                                codegenReal2Mission_DW.Receive_o2_m.params;
                            rtb_ImmedCMD.StartPosition =
                                codegenReal2Mission_DW.Receive_o2_m.StartPosition;
                            rtb_ImmedCMD.numUAV =
                                codegenReal2Mission_DW.Receive_o2_m.numUAV;
                            rtb_ImmedCMD.FormationPos =
                                codegenReal2Mission_DW.Receive_o2_m.FormationPos;
                            rtb_ImmedCMD.StartTime = fid;
                        }

                        if (guard1) {
                            NichtAvoidDanger = true;
                            rtb_FlightCMD.SequenceID =
                                codegenReal2Mission_DW.Receive_o2_m.SequenceID;
                            rtb_FlightCMD.MissionMode =
                                codegenReal2Mission_DW.Receive_o2_m.MissionMode;
                            rtb_FlightCMD.MissionLocation =
                                codegenReal2Mission_DW.Receive_o2_m.MissionLocation;
                            rtb_FlightCMD.params =
                                codegenReal2Mission_DW.Receive_o2_m.params;
                            rtb_FlightCMD.StartPosition =
                                codegenReal2Mission_DW.Receive_o2_m.StartPosition;
                            rtb_FlightCMD.numUAV =
                                codegenReal2Mission_DW.Receive_o2_m.numUAV;
                            rtb_FlightCMD.FormationPos =
                                codegenReal2Mission_DW.Receive_o2_m.FormationPos;
                            rtb_FlightCMD.StartTime = fid;
                        }

                        Lon = fid * 1000.0;
                        codegenReal2Mission_getDateVec_i(Lon, &Lat, &Alt, &b_I,
                            &D, &a__4, &rtb_Sum1_idx_0);
                        codegenReal2Mission_getDateVec_i(Lon, &b_I, &Alt, &D,
                            &a__4, &rtb_Sum1_idx_0, &da_im);
                        codegenReal2Mission_getDateVec_i(Lon, &D, &a__4, &b_I,
                            &rtb_Sum1_idx_0, &da_im, &a__17);
                        codegenReal2Mission_getDateVec_i(Lon, &a__4,
                            &rtb_Sum1_idx_0, &da_im, &D, &a__17, &a__23);
                        codegenReal2Mission_getDateVec_i(Lon, &rtb_Sum1_idx_0,
                            &da_im, &a__17, &a__23, &a__4, &a__29);
                        codegenReal2Mission_getDateVec_i(Lon, &da_im, &a__17,
                            &a__23, &a__29, &a__35, &rtb_Sum1_idx_0);
                        codegenReal2Mission_getDateVec_i(Lon, &a__17, &a__23,
                            &a__29, &a__35, &b_a__35, &da_im);
                        codegenReal2Mission_getDateVec_i(Lon, &a__17, &a__23,
                            &a__29, &a__35, &b_a__35, &b_x_0);
                        a__17 = std::round(Lat);
                        Lat = std::round(Alt);
                        b_I = std::round(b_I);
                        D = std::round(D);
                        a__4 = std::round(a__4);
                        rtb_Sum1_idx_0 = std::floor(rtb_Sum1_idx_0);
                        da_im = std::round((da_im - std::floor(b_x_0)) * 1000.0);
                        if (a__17 < 2.147483648E+9) {
                            if (a__17 >= -2.147483648E+9) {
                                i = static_cast<int32_T>(a__17);
                            } else {
                                i = MIN_int32_T;
                            }
                        } else {
                            i = MAX_int32_T;
                        }

                        if (Lat < 2.147483648E+9) {
                            if (Lat >= -2.147483648E+9) {
                                b_md2 = static_cast<int32_T>(Lat);
                            } else {
                                b_md2 = MIN_int32_T;
                            }
                        } else {
                            b_md2 = MAX_int32_T;
                        }

                        if (b_I < 2.147483648E+9) {
                            if (b_I >= -2.147483648E+9) {
                                wholeSecsFromMillis = static_cast<int32_T>(b_I);
                            } else {
                                wholeSecsFromMillis = MIN_int32_T;
                            }
                        } else {
                            wholeSecsFromMillis = MAX_int32_T;
                        }

                        if (D < 2.147483648E+9) {
                            if (D >= -2.147483648E+9) {
                                loop_ub = static_cast<int32_T>(D);
                            } else {
                                loop_ub = MIN_int32_T;
                            }
                        } else {
                            loop_ub = MAX_int32_T;
                        }

                        if (a__4 < 2.147483648E+9) {
                            if (a__4 >= -2.147483648E+9) {
                                b = static_cast<int32_T>(a__4);
                            } else {
                                b = MIN_int32_T;
                            }
                        } else {
                            b = MAX_int32_T;
                        }

                        if (rtb_Sum1_idx_0 < 2.147483648E+9) {
                            if (rtb_Sum1_idx_0 >= -2.147483648E+9) {
                                md2 = static_cast<int32_T>(rtb_Sum1_idx_0);
                            } else {
                                md2 = MIN_int32_T;
                            }
                        } else {
                            md2 = MAX_int32_T;
                        }

                        if (da_im < 2.147483648E+9) {
                            if (da_im >= -2.147483648E+9) {
                                b_n = static_cast<int32_T>(da_im);
                            } else {
                                b_n = MIN_int32_T;
                            }
                        } else {
                            b_n = MAX_int32_T;
                        }

                        printf("Start Time:   %04d-%02d-%02d %02d:%02d:%02d.%03d\n",
                               i, b_md2, wholeSecsFromMillis, loop_ub, b, md2,
                               b_n);
                        fflush(stdout);
                        codegenReal2Mission_getLocalTime(&Lat, &a__5[5], &a__5[4],
                            &a__5[3], &a__5[2], &a__5[1], &a__5[0],
                            &rtb_Receive_o1_m);
                        a__5[6] = Lat / 1.0E+6;
                        TimeNow_data = codegenReal2Mission_createFromDateVec
                            (a__5);
                        codegenReal2Mission_getDateVec_ii(TimeNow_data, &b_x_0,
                            &Lat, &Lon, &Alt, &b_I, &D);
                        codegenReal2Mission_getDateVec_ii(TimeNow_data, &Lat,
                            &a__17, &Lon, &Alt, &b_I, &D);
                        codegenReal2Mission_getDateVec_ii(TimeNow_data, &Lat,
                            &Lon, &a__23, &Alt, &b_I, &D);
                        codegenReal2Mission_getDateVec_ii(TimeNow_data, &Lat,
                            &Lon, &Alt, &a__29, &b_I, &D);
                        codegenReal2Mission_getDateVec_ii(TimeNow_data, &Lat,
                            &Lon, &Alt, &b_I, &a__35, &D);
                        codegenReal2Mission_getDateVec_ii(TimeNow_data, &Lon,
                            &Alt, &b_I, &D, &a__4, &Lat);
                        codegenReal2Mission_getDateVec_ii(TimeNow_data, &Alt,
                            &b_I, &D, &a__4, &rtb_Sum1_idx_0, &Lon);
                        codegenReal2Mission_getDateVec_ii(TimeNow_data, &Alt,
                            &b_I, &D, &a__4, &rtb_Sum1_idx_0, &da_im);
                        printf("Current Time: %04.0f-%02.0f-%02.0f %02.0f:%02.0f:%02.0f.%03.0f\n",
                               b_x_0, a__17, a__23, a__29, a__35, std::floor(Lat),
                               std::round(1000.0 * (Lon - std::floor(da_im))));
                        fflush(stdout);
                    }
                }

                // '<S85>:1:10'
                rtb_FeedbackCMD.SequenceID =
                    codegenReal2Mission_DW.Receive_o2_m.SequenceID;
                rtb_FeedbackCMD.MissionMode =
                    codegenReal2Mission_DW.Receive_o2_m.MissionMode;
                rtb_FeedbackCMD.MissionLocation =
                    codegenReal2Mission_DW.Receive_o2_m.MissionLocation;
                rtb_FeedbackCMD.params =
                    codegenReal2Mission_DW.Receive_o2_m.params;
                rtb_FeedbackCMD.StartPosition =
                    codegenReal2Mission_DW.Receive_o2_m.StartPosition;
                rtb_FeedbackCMD.numUAV =
                    codegenReal2Mission_DW.Receive_o2_m.numUAV;
                rtb_FeedbackCMD.FormationPos =
                    codegenReal2Mission_DW.Receive_o2_m.FormationPos;
                rtb_FeedbackCMD.StartTime = fid;
            } else {
                // '<S85>:1:12'
                rtb_FeedbackCMD.SequenceID =
                    codegenReal2Mission_DW.Receive_o2_m.SequenceID;
                rtb_FeedbackCMD.MissionMode =
                    codegenReal2Mission_DW.Receive_o2_m.MissionMode;
                rtb_FeedbackCMD.MissionLocation =
                    codegenReal2Mission_DW.Receive_o2_m.MissionLocation;
                rtb_FeedbackCMD.params =
                    codegenReal2Mission_DW.Receive_o2_m.params;
                rtb_FeedbackCMD.StartPosition =
                    codegenReal2Mission_DW.Receive_o2_m.StartPosition;
                rtb_FeedbackCMD.numUAV =
                    codegenReal2Mission_DW.Receive_o2_m.numUAV;
                rtb_FeedbackCMD.FormationPos =
                    codegenReal2Mission_DW.Receive_o2_m.FormationPos;
                rtb_FeedbackCMD.StartTime = fid;
                codegenReal2Mission_DW.ParamADRC_e.hat_b = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive_o2_m.params.Param1 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.omega_o = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive_o2_m.params.Param2 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.omega_c = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive_o2_m.params.Param3 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.P = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive_o2_m.params.Param4 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.I = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive_o2_m.params.Param5 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.D = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive_o2_m.params.Param6 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.useADRC =
                    (codegenReal2Mission_DW.Receive_o2_m.params.Param7 != 0.0F);

                // '<S85>:1:14'
            }

            // DataStoreWrite: '<S84>/WriteCurrentCMD'
            // '<S85>:1:27'
            // '<S85>:1:28'
            codegenReal2Mission_DW.MissionCMD = rtb_FeedbackCMD;

            // Send: '<S84>/PushCMD' incorporates:
            //   MATLAB Function: '<S84>/CommandCheck'

            if (NichtAvoidDanger) {
                codegenReal2Mission_RcvNextMission_SendData(&rtb_FlightCMD);
            }

            // End of Send: '<S84>/PushCMD'

            // Send: '<S84>/SendFeedbackMissionCMD'
            codegenReal2Mission_ReceiveThisMission_SendData(&rtb_FeedbackCMD);

            // Send: '<S84>/SndImmedCMD' incorporates:
            //   MATLAB Function: '<S84>/CommandCheck'

            if (rtb_NotEqual) {
                codegenReal2Mission_RcvImmedCMD_SendData(&rtb_ImmedCMD);
            }

            // End of Send: '<S84>/SndImmedCMD'
        }

        // End of Receive: '<S82>/Receive'
        // End of Outputs for SubSystem: '<S82>/TriggerMissionDispatch'
        // End of Outputs for SubSystem: '<S10>/MissionValidation'

        // Outputs for Atomic SubSystem: '<S10>/QueueCMD'
        // Receive: '<S83>/Receive'
        wholeSecsFromMillis = 1;
        MissionCMDRecvData.RecvData(&codegenReal2Mission_DW.Receive_o2, sizeof
            (IndividualUAVCmd), &wholeSecsFromMillis);
        rtb_Receive_o1_m = (wholeSecsFromMillis != 1);

        // Outputs for Enabled SubSystem: '<S83>/UplinkLog' incorporates:
        //   EnablePort: '<S94>/Enable'

        if (rtb_Receive_o1_m) {
            // MATLAB Function: '<S94>/PrintOnboardLog'
            // MATLAB Function 'MissionLogic/PreProcessMissionCMD/QueueCMD/UplinkLog/PrintOnboardLog': '<S97>:1' 
            // '<S97>:1:3'
            fileid = codegenReal2Mission_cfopen_h("OnboardUplinkRcvCMD.log",
                "ab");

            // '<S97>:1:4'
            codegenReal2Mission_printIndivMissionCMD
                (codegenReal2Mission_DW.Receive_o2.SequenceID,
                 codegenReal2Mission_DW.Receive_o2.MissionMode,
                 codegenReal2Mission_DW.Receive_o2.MissionLocation.Lat,
                 codegenReal2Mission_DW.Receive_o2.MissionLocation.Lon,
                 codegenReal2Mission_DW.Receive_o2.MissionLocation.Alt,
                 codegenReal2Mission_DW.Receive_o2.MissionLocation.degHDG,
                 codegenReal2Mission_DW.Receive_o2.params.Param1,
                 codegenReal2Mission_DW.Receive_o2.params.Param2,
                 codegenReal2Mission_DW.Receive_o2.params.Param3,
                 codegenReal2Mission_DW.Receive_o2.params.Param4,
                 codegenReal2Mission_DW.Receive_o2.params.Param5,
                 codegenReal2Mission_DW.Receive_o2.params.Param6,
                 codegenReal2Mission_DW.Receive_o2.params.Param7,
                 codegenReal2Mission_DW.Receive_o2.StartPosition,
                 codegenReal2Mission_DW.Receive_o2.numUAV,
                 codegenReal2Mission_DW.Receive_o2.FormationPos,
                 codegenReal2Mission_DW.Receive_o2.StartTime, static_cast<real_T>
                 (fileid));

            // '<S97>:1:5'
            codegenReal2Mission_cfclose_n(static_cast<real_T>(fileid));
        }

        // End of Outputs for SubSystem: '<S83>/UplinkLog'

        // MATLAB Function: '<S83>/Struct2PosixCurr' incorporates:
        //   Memory: '<S83>/Memory'

        // MATLAB Function 'Struct2Posix': '<S92>:1'
        // '<S92>:1:3'
        Lat = static_cast<real_T>
            (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.year);
        Alt = static_cast<real_T>
            (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.month);
        Lon = static_cast<real_T>
            (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.second);
        b_I = static_cast<real_T>
            (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.millisecond);
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Memory_PreviousInput.StartTime.month
               < 1) | (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.month
                       > 12)))) {
            b_md2 = static_cast<int32_T>(std::floor((static_cast<real_T>
                (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.month) -
                1.0) / 12.0));
            Lat = static_cast<real_T>
                (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.year) +
                static_cast<real_T>(b_md2);
            Alt = ((static_cast<real_T>
                    (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.month)
                    - 1.0) - static_cast<real_T>(b_md2) * 12.0) + 1.0;
        }

        if (Alt < 3.0) {
            Lat--;
            Alt += 9.0;
        } else {
            Alt -= 3.0;
        }

        TimeNow_data.re = ((((((365.0 * Lat + std::floor(Lat / 4.0)) - std::
                               floor(Lat / 100.0)) + std::floor(Lat / 400.0)) +
                             std::floor((153.0 * Alt + 2.0) / 5.0)) +
                            static_cast<real_T>
                            (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.day))
                           + 60.0) - 719529.0;
        Alt = 1.34217729E+8 * TimeNow_data.re;
        Alt -= Alt - TimeNow_data.re;
        Lat = TimeNow_data.re * 8.64E+7;
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Memory_PreviousInput.StartTime.millisecond
               < 0) | (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.millisecond
                       >= 1000)))) {
            wholeSecsFromMillis = static_cast<int32_T>(std::floor
                (static_cast<real_T>
                 (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.millisecond)
                 / 1000.0));
            Lon = static_cast<real_T>
                (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.second) +
                static_cast<real_T>(wholeSecsFromMillis);
            b_I = static_cast<real_T>
                (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.millisecond)
                - static_cast<real_T>(wholeSecsFromMillis) * 1000.0;
        }

        Alt_0.re = Lat;
        Alt_0.im = (TimeNow_data.re - Alt) * 8.64E+7 + (Alt * 8.64E+7 - Lat);
        fid = (plus_bEdW4Zmk(plus_bEdW4Zmk(plus_bEdW4Zmk(Alt_0, (60.0 *
                   static_cast<real_T>
                   (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.hour)
                   + static_cast<real_T>
                   (codegenReal2Mission_DW.Memory_PreviousInput.StartTime.minute))
                  * 60000.0), Lon * 1000.0), b_I)).re / 1000.0;

        // End of MATLAB Function: '<S83>/Struct2PosixCurr'

        // RelationalOperator: '<S89>/Compare' incorporates:
        //   Constant: '<S89>/Constant'

        rtb_NotEqual = (codegenReal2Mission_DW.Receive_o2.MissionMode !=
                        MissionModes::AvoidDanger);

        // Logic: '<S83>/NichtAvoidDanger'
        NichtAvoidDanger = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(rtb_NotEqual) & static_cast<int32_T>
            (rtb_Receive_o1_m)));

        // RelationalOperator: '<S87>/FixPt Relational Operator' incorporates:
        //   UnitDelay: '<S87>/Delay Input1'
        //
        //  Block description for '<S87>/Delay Input1':
        //
        //   Store in Global RAM

        rtb_NotEqual = (codegenReal2Mission_DW.Receive_o2.SequenceID !=
                        codegenReal2Mission_DW.DelayInput1_DSTATE);

        // RelationalOperator: '<S88>/Compare' incorporates:
        //   Constant: '<S88>/Constant'

        rtb_AND_p = (codegenReal2Mission_DW.Receive_o2.MissionMode ==
                     MissionModes::AvoidDanger);

        // MATLAB Function: '<S95>/CurrentTime'
        // MATLAB Function 'CurrentTime/CurrentTime': '<S98>:1'
        // '<S98>:1:3'
        codegenReal2Mission_getLocalTime(&Lat, &Lon, &Alt, &processedInData[3],
            &D, &a__4, &rtb_Sum1_idx_0, &rtb_Receive_o1_m);
        processedInData[4] = Alt;
        processedInData[6] = Lat / 1.0E+6;
        b_I = processedInData[6];
        Lat = (((((rtb_Sum1_idx_0 + a__4) + D) + processedInData[3]) + Alt) +
               Lon) + processedInData[6];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(Lat)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(Lat)) ^ 1)))))) {
            Lat = rtb_Sum1_idx_0;
            Alt = a__4;
            if ((a__4 < 1.0) || (a__4 > 12.0)) {
                Alt = std::floor((a__4 - 1.0) / 12.0);
                Lat = rtb_Sum1_idx_0 + Alt;
                Alt = ((a__4 - 1.0) - Alt * 12.0) + 1.0;
            }

            if (Alt < 3.0) {
                Lat--;
                Alt += 9.0;
            } else {
                Alt -= 3.0;
            }

            TimeNow_data.re = ((((((365.0 * Lat + std::floor(Lat / 4.0)) - std::
                                   floor(Lat / 100.0)) + std::floor(Lat / 400.0))
                                 + std::floor((153.0 * Alt + 2.0) / 5.0)) + D) +
                               60.0) - 719529.0;
            Alt = 1.34217729E+8 * TimeNow_data.re;
            Alt -= Alt - TimeNow_data.re;
            Lat = TimeNow_data.re * 8.64E+7;
            b_this_data.re = Lat;
            da_im = (TimeNow_data.re - Alt) * 8.64E+7 + (Alt * 8.64E+7 - Lat);
            b_this_data.im = da_im;
            if (std::isnan(da_im)) {
                b_this_data.im = 0.0;
            }

            if ((processedInData[6] < 0.0) || (processedInData[6] >= 1000.0)) {
                b_I = std::floor(processedInData[6] / 1000.0);
                Lon += b_I;
                b_I = processedInData[6] - b_I * 1000.0;
            }

            b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(b_this_data, (60.0 * processedInData[3]
                + processedInData[4]) * 60000.0), Lon * 1000.0), b_I);
        } else {
            b_this_data.re = Lat;
        }

        // MATLAB Function: '<S83>/Struct2PosixUplink'
        // MATLAB Function 'Struct2Posix': '<S93>:1'
        // '<S93>:1:3'
        Lat = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.StartTime.year);
        Alt = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.StartTime.month);
        Lon = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.StartTime.second);
        b_I = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.StartTime.millisecond);
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Receive_o2.StartTime.month
               < 1) | (codegenReal2Mission_DW.Receive_o2.StartTime.month > 12))))
        {
            b_md2 = static_cast<int32_T>(std::floor((static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2.StartTime.month) - 1.0) /
                12.0));
            Lat = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2.StartTime.year) +
                static_cast<real_T>(b_md2);
            Alt = ((static_cast<real_T>
                    (codegenReal2Mission_DW.Receive_o2.StartTime.month) - 1.0) -
                   static_cast<real_T>(b_md2) * 12.0) + 1.0;
        }

        if (Alt < 3.0) {
            Lat--;
            Alt += 9.0;
        } else {
            Alt -= 3.0;
        }

        TimeNow_data.re = ((((((365.0 * Lat + std::floor(Lat / 4.0)) - std::
                               floor(Lat / 100.0)) + std::floor(Lat / 400.0)) +
                             std::floor((153.0 * Alt + 2.0) / 5.0)) +
                            static_cast<real_T>
                            (codegenReal2Mission_DW.Receive_o2.StartTime.day)) +
                           60.0) - 719529.0;
        Alt = 1.34217729E+8 * TimeNow_data.re;
        Alt -= Alt - TimeNow_data.re;
        Lat = TimeNow_data.re * 8.64E+7;
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Receive_o2.StartTime.millisecond
               < 0) | (codegenReal2Mission_DW.Receive_o2.StartTime.millisecond >=
                       1000)))) {
            wholeSecsFromMillis = static_cast<int32_T>(std::floor
                (static_cast<real_T>
                 (codegenReal2Mission_DW.Receive_o2.StartTime.millisecond) /
                 1000.0));
            Lon = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2.StartTime.second) +
                static_cast<real_T>(wholeSecsFromMillis);
            b_I = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2.StartTime.millisecond) -
                static_cast<real_T>(wholeSecsFromMillis) * 1000.0;
        }

        Alt_1.re = Lat;
        Alt_1.im = (TimeNow_data.re - Alt) * 8.64E+7 + (Alt * 8.64E+7 - Lat);
        tmp_1 = plus_bEdW4Zmk(Alt_1, (60.0 * static_cast<real_T>
                               (codegenReal2Mission_DW.Receive_o2.StartTime.hour)
                               + static_cast<real_T>
                               (codegenReal2Mission_DW.Receive_o2.StartTime.minute))
                              * 60000.0);

        // Logic: '<S83>/OR' incorporates:
        //   Constant: '<S86>/Constant'
        //   Constant: '<S96>/Constant'
        //   Logic: '<S83>/AND'
        //   Logic: '<S83>/SndAND'
        //   MATLAB Function: '<S83>/Struct2PosixUplink'
        //   MATLAB Function: '<S95>/CurrentTime'
        //   RelationalOperator: '<S83>/GreaterThanOrEqual'
        //   RelationalOperator: '<S83>/Relational Operator'
        //   RelationalOperator: '<S86>/Compare'
        //   RelationalOperator: '<S96>/Compare'

        rtb_Receive_o1_m = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((b_this_data.re / 1000.0 > fid) & (fid > 0.0)))) |
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((fid < 0.0) & static_cast<int32_T>(NichtAvoidDanger))))))) | (fid >
            (plus_bEdW4Zmk(plus_bEdW4Zmk(tmp_1, Lon * 1000.0), b_I)).re / 1000.0)));

        // BusCreator: '<S90>/CreatDanger' incorporates:
        //   DataTypeConversion: '<S90>/Cast To Double'

        rtb_CreatDanger.Radius = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.params.Param1);

        // DataTypeConversion: '<S90>/Cast To int32'
        tmp_7 = std::floor(codegenReal2Mission_DW.Receive_o2.params.Param3);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(tmp_7)) | static_cast<int32_T>(std::isinf(tmp_7))))) {
            tmp_7 = 0.0F;
        } else {
            tmp_7 = std::fmod(tmp_7, 4.2949673E+9F);
        }

        // BusCreator: '<S90>/CreatDanger' incorporates:
        //   DataTypeConversion: '<S90>/Cast To int32'

        rtb_CreatDanger.DangerID = tmp_7 < 0.0F ? static_cast<int32_T>(-
            static_cast<int32_T>(static_cast<uint32_T>(-tmp_7))) :
            static_cast<int32_T>(static_cast<uint32_T>(tmp_7));
        rtb_CreatDanger.DangerLoc =
            codegenReal2Mission_DW.Receive_o2.MissionLocation;

        // Send: '<S83>/Send'
        if (NichtAvoidDanger) {
            codegenReal2Mission_Queue_SendData
                (&codegenReal2Mission_DW.Receive_o2);
        }

        // End of Send: '<S83>/Send'

        // Outputs for Enabled SubSystem: '<S83>/ReadOne' incorporates:
        //   EnablePort: '<S91>/Enable'

        if (rtb_Receive_o1_m) {
            // Receive: '<S91>/Receive'
            codegenReal2Mission_Queue_RecvData(&codegenReal2Mission_DW.Receive);
        }

        // End of Outputs for SubSystem: '<S83>/ReadOne'

        // Send: '<S83>/SendCMD' incorporates:
        //   Logic: '<S83>/MsgSndAND'
        //   Memory: '<S83>/Memory'
        //   RelationalOperator: '<S83>/NotEqual'

        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Receive_o2_m.SequenceID
               != codegenReal2Mission_DW.Memory_PreviousInput.SequenceID) &
                                    static_cast<int32_T>(rtb_Receive_o1_m)))) {
            codegenReal2Mission_Receive_b_SendData
                (&codegenReal2Mission_DW.Memory_PreviousInput);
        }

        // End of Send: '<S83>/SendCMD'

        // Send: '<S83>/SendDanger' incorporates:
        //   Logic: '<S83>/AndSndDanger'

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rtb_NotEqual) & static_cast<int32_T>(rtb_AND_p)))) {
            codegenReal2Mission_Receive_SendData(&rtb_CreatDanger);
        }

        // End of Send: '<S83>/SendDanger'

        // Update for Memory: '<S83>/Memory'
        codegenReal2Mission_DW.Memory_PreviousInput =
            codegenReal2Mission_DW.Receive;

        // Update for UnitDelay: '<S87>/Delay Input1'
        //
        //  Block description for '<S87>/Delay Input1':
        //
        //   Store in Global RAM

        codegenReal2Mission_DW.DelayInput1_DSTATE =
            codegenReal2Mission_DW.Receive_o2.SequenceID;

        // End of Outputs for SubSystem: '<S10>/QueueCMD'
        // End of Outputs for SubSystem: '<S2>/PreProcessMissionCMD'

        // Receive: '<S2>/RcvNextMission'
        codegenReal2Mission_RcvNextMission_RecvData
            (&codegenReal2Mission_DW.RcvNextMission);

        // Outputs for Atomic SubSystem: '<S2>/FlightMission'
        // Logic: '<S7>/NOT'
        rtb_Receive_o1_m = static_cast<boolean_T>(static_cast<int32_T>
            ((codegenReal2Mission_DW.RcvNextMission.params.Param7 != 0.0F) ^ 1));

        // Outputs for Enabled SubSystem: '<S7>/TriggerNewMissionBroadcast' incorporates:
        //   EnablePort: '<S50>/Enable'

        // RelationalOperator: '<S44>/FixPt Relational Operator' incorporates:
        //   UnitDelay: '<S44>/Delay Input1'
        //
        //  Block description for '<S44>/Delay Input1':
        //
        //   Store in Global RAM

        if (codegenReal2Mission_DW.RcvNextMission.SequenceID !=
                codegenReal2Mission_DW.DelayInput1_DSTATE_e) {
            // DataStoreWrite: '<S50>/Data Store Write'
            codegenReal2Mission_DW.CurrentFlightMission =
                codegenReal2Mission_DW.RcvNextMission;

            // Send: '<S50>/SendMission'
            codegenReal2Mission_MissionUAVScheduling_In3_SendData
                (&codegenReal2Mission_DW.RcvNextMission);
        }

        // End of RelationalOperator: '<S44>/FixPt Relational Operator'
        // End of Outputs for SubSystem: '<S7>/TriggerNewMissionBroadcast'

        // Chart: '<S7>/MissionUAVScheduling' incorporates:
        //   Memory: '<S7>/Memory'

        // Gateway: MissionLogic/FlightMission/MissionUAVScheduling
        wholeSecsFromMillis = -1;
        NichtAvoidDanger = false;

        // During: MissionLogic/FlightMission/MissionUAVScheduling
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c15_codegenReal2Mission) == 0U)
        {
            // Entry: MissionLogic/FlightMission/MissionUAVScheduling
            codegenReal2Mission_DW.is_active_c15_codegenReal2Mission = 1U;

            // Entry Internal: MissionLogic/FlightMission/MissionUAVScheduling
            codegenReal2Mission_DW.is_active_MissionSwitch = 1U;

            // Entry Internal 'MissionSwitch': '<S46>:47'
            // Transition: '<S46>:16'
            codegenReal2Mission_DW.is_MissionSwitch =
                codegenReal2Mission_IN_MissionA;

            // Entry 'MissionA': '<S46>:12'
            codegenReal2Mission_DW.EnableA = 1.0;
            codegenReal2Mission_DW.EnableB = 0.0;
            codegenReal2Mission_DW.is_active_FollowSwitch = 1U;

            // Entry Internal 'FollowSwitch': '<S46>:48'
            // Transition: '<S46>:50'
            codegenReal2Mission_DW.is_FollowSwitch =
                codegenReal2Mission_IN_FollowA;

            // Entry 'FollowA': '<S46>:49'
            codegenReal2Mission_DW.followSwitch = true;
        } else {
            if (static_cast<uint32_T>
                    (codegenReal2Mission_DW.is_active_MissionSwitch) != 0U) {
                // During 'MissionSwitch': '<S46>:47'
                switch (codegenReal2Mission_DW.is_MissionSwitch) {
                  case codegenReal2Mission_IN_A2B:
                    // During 'A2B': '<S46>:42'
                    if (codegenReal2Mission_DW.Memory_PreviousInput_f) {
                        // Transition: '<S46>:44'
                        // Event: '<S46>:55'
                        wholeSecsFromMillis =
                            codegenReal2Mission_event_shiftFollow;
                        if (static_cast<uint32_T>
                                (codegenReal2Mission_DW.is_active_FollowSwitch)
                                != 0U) {
                            codegenReal2Mission_FollowSwitch
                                (&wholeSecsFromMillis);
                        }

                        wholeSecsFromMillis = -1;
                        codegenReal2Mission_DW.is_MissionSwitch =
                            codegenReal2Mission_IN_MissionB;

                        // Entry 'MissionB': '<S46>:10'
                        codegenReal2Mission_DW.EnableA = 0.0;
                        codegenReal2Mission_DW.EnableB = 1.0;
                    }
                    break;

                  case codegenReal2Mission_IN_B2A:
                    // During 'B2A': '<S46>:77'
                    if (codegenReal2Mission_DW.Memory_PreviousInput_f) {
                        // Transition: '<S46>:73'
                        // Event: '<S46>:55'
                        wholeSecsFromMillis =
                            codegenReal2Mission_event_shiftFollow;
                        if (static_cast<uint32_T>
                                (codegenReal2Mission_DW.is_active_FollowSwitch)
                                != 0U) {
                            codegenReal2Mission_FollowSwitch
                                (&wholeSecsFromMillis);
                        }

                        wholeSecsFromMillis = -1;
                        codegenReal2Mission_DW.is_MissionSwitch =
                            codegenReal2Mission_IN_MissionA;

                        // Entry 'MissionA': '<S46>:12'
                        codegenReal2Mission_DW.EnableA = 1.0;
                        codegenReal2Mission_DW.EnableB = 0.0;
                    }
                    break;

                  case codegenReal2Mission_IN_MissionA:
                    // During 'MissionA': '<S46>:12'
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(codegenReal2Mission_sf_msg_pop_ExecMsg
                                     (&NichtAvoidDanger)) ^ 1))) {
                        rtb_Receive_o1_m = false;
                    }

                    if (rtb_Receive_o1_m) {
                        // Transition: '<S46>:7'
                        codegenReal2Mission_sf_msg_forward_ExecMsg_ExecMsgB
                            (&NichtAvoidDanger);

                        // Exit 'MissionA': '<S46>:12'
                        codegenReal2Mission_DW.EnableA = 0.0;
                        codegenReal2Mission_DW.EnableB = 1.0;
                        codegenReal2Mission_DW.is_MissionSwitch =
                            codegenReal2Mission_IN_A2B;
                    } else if (codegenReal2Mission_sf_msg_pop_ExecMsg
                               (&NichtAvoidDanger)) {
                        // Transition: '<S46>:79'
                        codegenReal2Mission_sf_msg_forward_ExecMsg_ExecMsgA
                            (&NichtAvoidDanger);

                        // Exit 'MissionA': '<S46>:12'
                        codegenReal2Mission_DW.is_MissionSwitch =
                            codegenReal2Mission_IN_MissionA;

                        // Entry 'MissionA': '<S46>:12'
                        codegenReal2Mission_DW.EnableA = 1.0;
                        codegenReal2Mission_DW.EnableB = 0.0;
                    }
                    break;

                  case codegenReal2Mission_IN_MissionB:
                    // During 'MissionB': '<S46>:10'
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               (static_cast<int32_T>
                                                (codegenReal2Mission_sf_msg_pop_ExecMsg
                            (&NichtAvoidDanger)) ^ 1))) {
                        rtb_Receive_o1_m = false;
                    }

                    if (rtb_Receive_o1_m) {
                        // Transition: '<S46>:11'
                        codegenReal2Mission_sf_msg_forward_ExecMsg_ExecMsgA
                            (&NichtAvoidDanger);

                        // Exit 'MissionB': '<S46>:10'
                        codegenReal2Mission_DW.EnableA = 1.0;
                        codegenReal2Mission_DW.EnableB = 0.0;
                        codegenReal2Mission_DW.is_MissionSwitch =
                            codegenReal2Mission_IN_B2A;
                    } else if (codegenReal2Mission_sf_msg_pop_ExecMsg
                               (&NichtAvoidDanger)) {
                        // Transition: '<S46>:80'
                        codegenReal2Mission_sf_msg_forward_ExecMsg_ExecMsgB
                            (&NichtAvoidDanger);

                        // Exit 'MissionB': '<S46>:10'
                        codegenReal2Mission_DW.is_MissionSwitch =
                            codegenReal2Mission_IN_MissionB;

                        // Entry 'MissionB': '<S46>:10'
                        codegenReal2Mission_DW.EnableA = 0.0;
                        codegenReal2Mission_DW.EnableB = 1.0;
                    }
                    break;
                }
            }

            if (static_cast<uint32_T>
                    (codegenReal2Mission_DW.is_active_FollowSwitch) != 0U) {
                codegenReal2Mission_FollowSwitch(&wholeSecsFromMillis);
            }
        }

        codegenReal2Mission_sf_msg_discard_ExecMsg(&NichtAvoidDanger);

        // End of Chart: '<S7>/MissionUAVScheduling'

        // RateTransition generated from: '<S7>/ModelA'
        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.EnableA_WrBufIdx = static_cast<int8_T>(
                static_cast<int32_T>(codegenReal2Mission_DW.EnableA_WrBufIdx) ==
                0);
        }

        codegenReal2Mission_DW.EnableA_Buf[static_cast<int32_T>
            (codegenReal2Mission_DW.EnableA_WrBufIdx)] =
            codegenReal2Mission_DW.EnableA;

        // RateTransition generated from: '<S7>/ModelB'
        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.EnableB_WrBufIdx = static_cast<int8_T>(
                static_cast<int32_T>(codegenReal2Mission_DW.EnableB_WrBufIdx) ==
                0);
        }

        codegenReal2Mission_DW.EnableB_Buf[static_cast<int32_T>
            (codegenReal2Mission_DW.EnableB_WrBufIdx)] =
            codegenReal2Mission_DW.EnableB;

        // Outputs for Atomic SubSystem: '<S7>/JumpDelay'
        // Outputs for Atomic SubSystem: '<S45>/ComputDelay'
        // MATLAB Function: '<S52>/ReadPursuitShiftPercentage'
        // MATLAB Function 'ComputShift/ReadPursuitShiftPercentage': '<S53>:1'
        // '<S53>:1:3'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (codegenReal2Mission_DW.PursuitShift_not_empty) ^ 1))) {
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = codegenReal2Mission_cfopen_k("config.ini", "rb");
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread_e(static_cast<real_T>(fileid), q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose_l(static_cast<real_T>(fileid));
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                do {
                    exitg2 = 0;
                    if (data->size[1] != 0) {
                        int32_T exitg3;
                        i = static_cast<int32_T>(x->size[0] * x->size[1]);
                        x->size[0] = 1;
                        x->size[1] = data->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(x, i);
                        loop_ub = data->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            x->data[i] = data->data[i];
                        }

                        b = data->size[1];
                        b_md2 = 0;
                        while ((static_cast<int32_T>(b_md2 + 1) <= b) &&
                                (data->data[b_md2] == '\x0a')) {
                            b_md2 = static_cast<int32_T>(b_md2 + 1);
                        }

                        wholeSecsFromMillis = static_cast<int32_T>(b_md2 + 1);
                        while ((static_cast<int32_T>(b_md2 + 1) <= b) &&
                                (data->data[b_md2] != '\x0a')) {
                            b_md2 = static_cast<int32_T>(b_md2 + 1);
                        }

                        if (static_cast<int32_T>(b_md2 + 1) > data->size[1]) {
                            b = 0;
                            md2 = 0;
                        } else {
                            b = b_md2;
                            md2 = data->size[1];
                        }

                        loop_ub = static_cast<int32_T>(md2 - b);
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            data->data[i] = data->data[static_cast<int32_T>(b +
                                i)];
                        }

                        i = static_cast<int32_T>(data->size[0] * data->size[1]);
                        data->size[0] = 1;
                        data->size[1] = loop_ub;
                        codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                        if (wholeSecsFromMillis > b_md2) {
                            b = 0;
                            b_md2 = 0;
                        } else {
                            b = static_cast<int32_T>(wholeSecsFromMillis - 1);
                        }

                        b_n = static_cast<int32_T>(b_md2 - b);
                        md2 = 1;
                        while ((md2 <= b_n) && (x->data[static_cast<int32_T>(
                                 static_cast<int32_T>(b + md2) - 1)] == ';')) {
                            md2 = static_cast<int32_T>(md2 + 1);
                        }

                        wholeSecsFromMillis = md2;
                        while ((md2 <= b_n) && (x->data[static_cast<int32_T>(
                                 static_cast<int32_T>(b + md2) - 1)] != ';')) {
                            md2 = static_cast<int32_T>(md2 + 1);
                        }

                        if (wholeSecsFromMillis > static_cast<int32_T>(md2 - 1))
                        {
                            wholeSecsFromMillis = 0;
                            md2 = 0;
                        } else {
                            wholeSecsFromMillis = static_cast<int32_T>
                                (wholeSecsFromMillis - 1);
                            md2 = static_cast<int32_T>(md2 - 1);
                        }

                        i = static_cast<int32_T>(b_curKey->size[0] *
                            b_curKey->size[1]);
                        b_curKey->size[0] = 1;
                        b_curKey->size[1] = static_cast<int32_T>(md2 -
                            wholeSecsFromMillis);
                        codegenReal2Mission_emxEnsureCapacity_char_T(b_curKey, i);
                        loop_ub = static_cast<int32_T>(md2 - wholeSecsFromMillis);
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            b_curKey->data[i] = x->data[static_cast<int32_T>(
                                static_cast<int32_T>(b + wholeSecsFromMillis) +
                                i)];
                        }

                        codegenReal2Mission_strtrim(b_curKey, curLine);
                        if (curLine->size[1] >= 2) {
                            rtb_NotEqual = false;
                            if (curLine->data[0] == '[') {
                                rtb_NotEqual = true;
                            }

                            guard1 = false;
                            if (rtb_NotEqual) {
                                rtb_NotEqual = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    rtb_NotEqual = true;
                                }

                                if (rtb_NotEqual) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        md2 = 0;
                                        b = 0;
                                    } else {
                                        md2 = 1;
                                        b = static_cast<int32_T>(curLine->size[1]
                                            - 1);
                                    }

                                    i = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(b - md2);
                                    curSection->size[1] = loop_ub;
                                    codegenReal2Mission_emxEnsureCapacity_char_T
                                        (curSection, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
                                        curSection->data[i] = curLine->data[
                                            static_cast<int32_T>(md2 + i)];
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
                                    rtb_NotEqual = true;
                                }

                                if (static_cast<boolean_T>(static_cast<int32_T>(
                                        static_cast<int32_T>(rtb_NotEqual) ^ 1)))
                                {
                                    wholeSecsFromMillis = 1;
                                    do {
                                        exitg3 = 0;
                                        if (static_cast<int32_T>
                                                (wholeSecsFromMillis - 1) <=
                                                static_cast<int32_T>
                                                (curLine->size[1] - 1)) {
                                            if (curLine->data[static_cast<
                                                    int32_T>(wholeSecsFromMillis
                                                 - 1)] == '=') {
                                                exitg3 = 1;
                                            } else {
                                                wholeSecsFromMillis =
                                                    static_cast<int32_T>
                                                    (wholeSecsFromMillis + 1);
                                            }
                                        } else {
                                            wholeSecsFromMillis = 0;
                                            exitg3 = 1;
                                        }
                                    } while (exitg3 == 0);

                                    if (wholeSecsFromMillis > 0) {
                                        codegenReal2Mission_find_token(curLine,
                                            &b_md2, &md2);
                                        if (md2 > curLine->size[1]) {
                                            wholeSecsFromMillis = 0;
                                            b = 0;
                                        } else {
                                            wholeSecsFromMillis =
                                                static_cast<int32_T>(md2 - 1);
                                            b = curLine->size[1];
                                        }

                                        if (b_md2 > static_cast<int32_T>(md2 - 1))
                                        {
                                            b_md2 = 0;
                                            b_n = 0;
                                        } else {
                                            b_md2 = static_cast<int32_T>(b_md2 -
                                                1);
                                            b_n = static_cast<int32_T>(md2 - 1);
                                        }

                                        i = static_cast<int32_T>(x->size[0] *
                                            x->size[1]);
                                        x->size[0] = 1;
                                        x->size[1] = static_cast<int32_T>(b -
                                            wholeSecsFromMillis);
                                        codegenReal2Mission_emxEnsureCapacity_char_T
                                            (x, i);
                                        loop_ub = static_cast<int32_T>(b -
                                            wholeSecsFromMillis);
                                        for (i = 0; i <= static_cast<int32_T>
                                                (loop_ub - 1); i++) {
                                            x->data[i] = curLine->data[
                                                static_cast<int32_T>
                                                (wholeSecsFromMillis + i)];
                                        }

                                        codegenReal2Mission_find_token(x, &b,
                                            &md2);
                                        if (b > static_cast<int32_T>(md2 - 1)) {
                                            b = 0;
                                            md2 = 0;
                                        } else {
                                            b = static_cast<int32_T>(b - 1);
                                            md2 = static_cast<int32_T>(md2 - 1);
                                        }

                                        i = static_cast<int32_T>(x->size[0] *
                                            x->size[1]);
                                        x->size[0] = 1;
                                        loop_ub = static_cast<int32_T>(b_n -
                                            b_md2);
                                        x->size[1] = loop_ub;
                                        codegenReal2Mission_emxEnsureCapacity_char_T
                                            (x, i);
                                        for (i = 0; i <= static_cast<int32_T>
                                                (loop_ub - 1); i++) {
                                            x->data[i] = curLine->data[
                                                static_cast<int32_T>(b_md2 + i)];
                                        }

                                        codegenReal2Mission_strtrim(x, curKey);
                                        i = static_cast<int32_T>(x->size[0] *
                                            x->size[1]);
                                        x->size[0] = 1;
                                        loop_ub = static_cast<int32_T>(md2 - b);
                                        x->size[1] = loop_ub;
                                        codegenReal2Mission_emxEnsureCapacity_char_T
                                            (x, i);
                                        for (i = 0; i <= static_cast<int32_T>
                                                (loop_ub - 1); i++) {
                                            x->data[i] = curLine->data[
                                                static_cast<int32_T>(
                                                static_cast<int32_T>
                                                (wholeSecsFromMillis + b) + i)];
                                        }

                                        codegenReal2Mission_strtrim(x, curVal);
                                    }
                                }
                            }
                        }

                        rtb_NotEqual = false;
                        if (curSection->size[1] == 12) {
                            wholeSecsFromMillis = 1;
                            do {
                                exitg3 = 0;
                                if (static_cast<int32_T>(wholeSecsFromMillis - 1)
                                    < 12) {
                                    if (u[static_cast<int32_T>
                                            (static_cast<int32_T>
                                             (static_cast<uint8_T>
                                              (curSection->data
                                               [static_cast<int32_T>
                                               (wholeSecsFromMillis - 1)])) &
                                             127)] != u[static_cast<int32_T>(v[
                                            static_cast<int32_T>
                                            (wholeSecsFromMillis - 1)])]) {
                                        exitg3 = 1;
                                    } else {
                                        wholeSecsFromMillis =
                                            static_cast<int32_T>
                                            (wholeSecsFromMillis + 1);
                                    }
                                } else {
                                    rtb_NotEqual = true;
                                    exitg3 = 1;
                                }
                            } while (exitg3 == 0);
                        }

                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curKey->size[1] == 15) {
                                wholeSecsFromMillis = 1;
                                do {
                                    exitg3 = 0;
                                    if (static_cast<int32_T>(wholeSecsFromMillis
                                         - 1) < 15) {
                                        if (u[static_cast<int32_T>
                                                (static_cast<int32_T>(
                                                static_cast<uint8_T>
                                                (curKey->data
                                                 [static_cast<int32_T>
                                                 (wholeSecsFromMillis - 1)])) &
                                                 127)] != u[static_cast<int32_T>
                                                (w[static_cast<int32_T>
                                                 (wholeSecsFromMillis - 1)])]) {
                                            exitg3 = 1;
                                        } else {
                                            wholeSecsFromMillis =
                                                static_cast<int32_T>
                                                (wholeSecsFromMillis + 1);
                                        }
                                    } else {
                                        rtb_NotEqual = true;
                                        exitg3 = 1;
                                    }
                                } while (exitg3 == 0);
                            }

                            if (rtb_NotEqual) {
                                i = static_cast<int32_T>(ret->size[0] *
                                    ret->size[1]);
                                ret->size[0] = 1;
                                ret->size[1] = curVal->size[1];
                                codegenReal2Mission_emxEnsureCapacity_char_T(ret,
                                    i);
                                loop_ub = curVal->size[1];
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
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
            }

            tmp_1 = codegenReal2Mission_str2double(ret);
            codegenReal2Mission_DW.PursuitShift = tmp_1.re;
            codegenReal2Mission_DW.PursuitShift_not_empty = true;
            printf("Pursuit Shift Percentage: \t%f\n",
                   codegenReal2Mission_DW.PursuitShift);
            fflush(stdout);
        }

        // Switch: '<S52>/AllPositivePosSwitch' incorporates:
        //   Bias: '<S52>/plusOne'
        //   DataTypeConversion: '<S52>/doubleFormPos'
        //   DataTypeConversion: '<S52>/doubleNumUAV'
        //   Sum: '<S52>/Minus'

        if (codegenReal2Mission_DW.RcvNextMission.FormationPos > 0) {
            D = static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.FormationPos);
        } else {
            D = (static_cast<real_T>
                 (codegenReal2Mission_DW.RcvNextMission.numUAV) + 1.0) +
                static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.FormationPos);
        }

        // End of Switch: '<S52>/AllPositivePosSwitch'

        // Signum: '<S52>/Sign' incorporates:
        //   MATLAB Function: '<S52>/ReadPursuitShiftPercentage'

        if (std::isnan(codegenReal2Mission_DW.PursuitShift)) {
            a__17 = (rtNaN);
        } else if (codegenReal2Mission_DW.PursuitShift < 0.0) {
            a__17 = -1.0;
        } else {
            a__17 = static_cast<real_T>(codegenReal2Mission_DW.PursuitShift >
                0.0);
        }

        // Product: '<S52>/DivideThree' incorporates:
        //   Abs: '<S52>/Abs'
        //   Bias: '<S52>/Bias'
        //   Constant: '<S52>/Three'
        //   MATLAB Function: '<S52>/ReadPursuitShiftPercentage'
        //   Math: '<S52>/ModThree'
        //   Math: '<S52>/Pow'
        //   Product: '<S52>/DivideByThree'
        //   Rounding: '<S52>/idxCeil'
        //   Signum: '<S52>/Sign'

        codegenReal2Mission_DW.DivideThree = (rt_modd_snf(std::ceil(D / 3.0),
            3.0) + 1.0) / 3.0 * rt_powd_snf(a__17, D) * std::abs
            (codegenReal2Mission_DW.PursuitShift);

        // End of Outputs for SubSystem: '<S45>/ComputDelay'
        // End of Outputs for SubSystem: '<S7>/JumpDelay'

        // MATLAB Function: '<S51>/CurrentTime'
        // MATLAB Function 'CurrentTime/CurrentTime': '<S54>:1'
        // '<S54>:1:3'
        codegenReal2Mission_getLocalTime(&Lat, &Lon, &Alt, &processedInData[3],
            &D, &a__4, &rtb_Sum1_idx_0, &rtb_Receive_o1_m);
        processedInData[4] = Alt;
        processedInData[6] = Lat / 1.0E+6;
        b_I = processedInData[6];
        Lat = (((((rtb_Sum1_idx_0 + a__4) + D) + processedInData[3]) + Alt) +
               Lon) + processedInData[6];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(Lat)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(Lat)) ^ 1)))))) {
            Lat = rtb_Sum1_idx_0;
            Alt = a__4;
            if ((a__4 < 1.0) || (a__4 > 12.0)) {
                Alt = std::floor((a__4 - 1.0) / 12.0);
                Lat = rtb_Sum1_idx_0 + Alt;
                Alt = ((a__4 - 1.0) - Alt * 12.0) + 1.0;
            }

            if (Alt < 3.0) {
                Lat--;
                Alt += 9.0;
            } else {
                Alt -= 3.0;
            }

            TimeNow_data.re = ((((((365.0 * Lat + std::floor(Lat / 4.0)) - std::
                                   floor(Lat / 100.0)) + std::floor(Lat / 400.0))
                                 + std::floor((153.0 * Alt + 2.0) / 5.0)) + D) +
                               60.0) - 719529.0;
            Alt = 1.34217729E+8 * TimeNow_data.re;
            Alt -= Alt - TimeNow_data.re;
            Lat = TimeNow_data.re * 8.64E+7;
            Alt_2.re = Lat;
            da_im = (TimeNow_data.re - Alt) * 8.64E+7 + (Alt * 8.64E+7 - Lat);
            Alt_2.im = da_im;
            if (std::isnan(da_im)) {
                Alt_2.im = 0.0;
            }

            if ((processedInData[6] < 0.0) || (processedInData[6] >= 1000.0)) {
                b_I = std::floor(processedInData[6] / 1000.0);
                Lon += b_I;
                b_I = processedInData[6] - b_I * 1000.0;
            }

            b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(Alt_2, (60.0 * processedInData[3] +
                processedInData[4]) * 60000.0), Lon * 1000.0), b_I);
        } else {
            b_this_data.re = Lat;
        }

        // Receive: '<S47>/Receive'
        wholeSecsFromMillis = codegenReal2Mission_Receive_d_RecvData
            (&codegenReal2Mission_DW.Receive_o2_d);
        NichtAvoidDanger = (wholeSecsFromMillis != 1);

        // RateTransition: '<S47>/MsgRT'
        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.MsgRT_WrBufIdx = static_cast<int8_T>(
                static_cast<int32_T>(codegenReal2Mission_DW.MsgRT_WrBufIdx) == 0);
        }

        codegenReal2Mission_DW.MsgRT_Buf[static_cast<int32_T>
            (codegenReal2Mission_DW.MsgRT_WrBufIdx)] =
            codegenReal2Mission_DW.Receive_o2_d;

        // End of RateTransition: '<S47>/MsgRT'

        // RateTransition: '<S47>/Rate Transition' incorporates:
        //   Logic: '<S47>/OR'
        //   Memory: '<S47>/Memory'

        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.RateTransition_WrBufIdx_j =
                static_cast<int8_T>(static_cast<int32_T>
                                    (codegenReal2Mission_DW.RateTransition_WrBufIdx_j)
                                    == 0);
        }

        codegenReal2Mission_DW.RateTransition_Buf_c[static_cast<int32_T>
            (codegenReal2Mission_DW.RateTransition_WrBufIdx_j)] =
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (codegenReal2Mission_DW.Memory_PreviousInput_j) |
            static_cast<int32_T>(NichtAvoidDanger)));

        // End of RateTransition: '<S47>/Rate Transition'

        // Receive: '<S48>/Receive'
        wholeSecsFromMillis = codegenReal2Mission_Receive_e_RecvData
            (&codegenReal2Mission_DW.Receive_o2_p);
        rtb_NotEqual = (wholeSecsFromMillis != 1);

        // RateTransition: '<S48>/MsgRT'
        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.MsgRT_WrBufIdx_b = static_cast<int8_T>(
                static_cast<int32_T>(codegenReal2Mission_DW.MsgRT_WrBufIdx_b) ==
                0);
        }

        codegenReal2Mission_DW.MsgRT_Buf_a[static_cast<int32_T>
            (codegenReal2Mission_DW.MsgRT_WrBufIdx_b)] =
            codegenReal2Mission_DW.Receive_o2_p;

        // End of RateTransition: '<S48>/MsgRT'

        // RateTransition: '<S48>/Rate Transition' incorporates:
        //   Logic: '<S48>/OR'
        //   Memory: '<S48>/Memory'

        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.RateTransition_WrBufIdx_h =
                static_cast<int8_T>(static_cast<int32_T>
                                    (codegenReal2Mission_DW.RateTransition_WrBufIdx_h)
                                    == 0);
        }

        codegenReal2Mission_DW.RateTransition_Buf_l[static_cast<int32_T>
            (codegenReal2Mission_DW.RateTransition_WrBufIdx_h)] =
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (codegenReal2Mission_DW.Memory_PreviousInput_p) |
            static_cast<int32_T>(rtb_NotEqual)));

        // End of RateTransition: '<S48>/Rate Transition'

        // Chart: '<S7>/NewMission'
        // Gateway: MissionLogic/FlightMission/NewMission
        rtb_Receive_o1_m = codegenReal2Mission_DW.followSwitch_start;
        codegenReal2Mission_DW.followSwitch_start =
            codegenReal2Mission_DW.followSwitch;

        // During: MissionLogic/FlightMission/NewMission
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c18_codegenReal2Mission) == 0U)
        {
            // Entry: MissionLogic/FlightMission/NewMission
            codegenReal2Mission_DW.is_active_c18_codegenReal2Mission = 1U;

            // Entry Internal: MissionLogic/FlightMission/NewMission
            // Transition: '<S49>:3'
            // Entry 'TriggerNewMission': '<S49>:2'
            rtb_Receive_o1_m = true;

            // During 'TriggerNewMission': '<S49>:2'
        } else if (rtb_Receive_o1_m != codegenReal2Mission_DW.followSwitch_start)
        {
            // Transition: '<S49>:4'
            // Entry 'TriggerNewMission': '<S49>:2'
            rtb_Receive_o1_m = true;
        } else {
            rtb_Receive_o1_m = false;
        }

        // End of Chart: '<S7>/NewMission'

        // Signum: '<S7>/Sign'
        if (std::isnan(codegenReal2Mission_DW.RcvNextMission.StartTime)) {
            a__17 = (rtNaN);
        } else if (codegenReal2Mission_DW.RcvNextMission.StartTime < 0.0) {
            a__17 = -1.0;
        } else {
            a__17 = static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.StartTime > 0.0);
        }

        // Product: '<S7>/Product' incorporates:
        //   MATLAB Function: '<S51>/CurrentTime'
        //   SampleTimeMath: '<S7>/Weighted Sample Time Math'
        //   Signum: '<S7>/Sign'
        //   Sum: '<S7>/Minus'
        //
        //  About '<S7>/Weighted Sample Time Math':
        //   y = u * K where K = 1 / ( w * Ts )

        D = (b_this_data.re / 1000.0 -
             codegenReal2Mission_DW.RcvNextMission.StartTime) * 10.0 * a__17;

        // Update for Memory: '<S7>/Memory' incorporates:
        //   RateTransition: '<S7>/Rate Transition'

        codegenReal2Mission_DW.Memory_PreviousInput_f =
            codegenReal2Mission_DW.RateTransition_Buffer0;

        // RateTransition generated from: '<S7>/SwitchMissionUAVState'
        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_RdBufIdx
                = static_cast<int8_T>(static_cast<int32_T>
                (codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_RdBufIdx)
                == 0);
            codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_RdBufIdx
                = static_cast<int8_T>(static_cast<int32_T>
                (codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_RdBufIdx)
                == 0);
        }

        // Switch: '<S7>/SwitchMissionUAVState' incorporates:
        //   RateTransition generated from: '<S7>/SwitchMissionUAVState'

        if (codegenReal2Mission_DW.followSwitch) {
            rtb_SwitchMissionUAVState =
                codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_Buf[codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_RdBufIdx];
        } else {
            rtb_SwitchMissionUAVState =
                codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_Buf[codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_RdBufIdx];
        }

        // End of Switch: '<S7>/SwitchMissionUAVState'

        // RateTransition generated from: '<S7>/SwitchTaskStatus'
        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_RdBufIdx =
                static_cast<int8_T>(static_cast<int32_T>
                                    (codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_RdBufIdx)
                                    == 0);
            codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_RdBufIdx =
                static_cast<int8_T>(static_cast<int32_T>
                                    (codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_RdBufIdx)
                                    == 0);
        }

        // Switch: '<S7>/SwitchTaskStatus' incorporates:
        //   RateTransition generated from: '<S7>/SwitchTaskStatus'

        if (codegenReal2Mission_DW.followSwitch) {
            fid =
                codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_Buf[codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_RdBufIdx];
        } else {
            fid =
                codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_Buf[codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_RdBufIdx];
        }

        // End of Switch: '<S7>/SwitchTaskStatus'

        // RateTransition generated from: '<S7>/ModelA' incorporates:
        //   Product: '<S7>/ProductA'

        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.TmpRTBAtModelAInport3_WrBufIdx = static_cast<
                int8_T>(static_cast<int32_T>
                        (codegenReal2Mission_DW.TmpRTBAtModelAInport3_WrBufIdx) ==
                        0);
        }

        codegenReal2Mission_DW.TmpRTBAtModelAInport3_Buf[static_cast<int32_T>
            (codegenReal2Mission_DW.TmpRTBAtModelAInport3_WrBufIdx)] = D *
            codegenReal2Mission_DW.EnableA;

        // RateTransition generated from: '<S7>/ModelB' incorporates:
        //   Product: '<S7>/ProductB'

        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_2 == 1) {
            codegenReal2Mission_DW.TmpRTBAtModelBInport3_WrBufIdx = static_cast<
                int8_T>(static_cast<int32_T>
                        (codegenReal2Mission_DW.TmpRTBAtModelBInport3_WrBufIdx) ==
                        0);
        }

        codegenReal2Mission_DW.TmpRTBAtModelBInport3_Buf[static_cast<int32_T>
            (codegenReal2Mission_DW.TmpRTBAtModelBInport3_WrBufIdx)] = D *
            codegenReal2Mission_DW.EnableB;

        // Update for UnitDelay: '<S44>/Delay Input1'
        //
        //  Block description for '<S44>/Delay Input1':
        //
        //   Store in Global RAM

        codegenReal2Mission_DW.DelayInput1_DSTATE_e =
            codegenReal2Mission_DW.RcvNextMission.SequenceID;

        // Update for Memory: '<S47>/Memory'
        codegenReal2Mission_DW.Memory_PreviousInput_j = NichtAvoidDanger;

        // Update for Memory: '<S48>/Memory'
        codegenReal2Mission_DW.Memory_PreviousInput_p = rtb_NotEqual;

        // End of Outputs for SubSystem: '<S2>/FlightMission'

        // Receive: '<S2>/RcvImmedCMD'
        wholeSecsFromMillis = codegenReal2Mission_RcvImmedCMD_RecvData
            (&codegenReal2Mission_DW.RcvImmedCMD_o2);
        NichtAvoidDanger = (wholeSecsFromMillis != 1);

        // MATLAB Function: '<S9>/ReadHomePoint'
        // MATLAB Function 'ReadHomePoint': '<S59>:1'
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (codegenReal2Mission_DW.HomePoint_not_empty) ^ 1))) {
            // '<S59>:1:5'
            // '<S59>:1:6'
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = codegenReal2Mission_cfopen_o("config.ini", "rb");
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread_i(static_cast<real_T>(fileid), q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose_m(static_cast<real_T>(fileid));
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_d, 2);
                codegenReal2Mission_emxInit_char_T(&data_5, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_5->size[0] * data_5->size[1]);
                    data_5->size[0] = 1;
                    data_5->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_5, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_5->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_5, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_d);
                    codegenReal2Mission_strtrim(tmp_d, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    md2 = 0;
                                    b = 0;
                                } else {
                                    md2 = 1;
                                    b = static_cast<int32_T>(curLine->size[1] -
                                        1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - md2);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    curSection->data[i] = curLine->data[
                                        static_cast<int32_T>(md2 + i)];
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    x);
                                codegenReal2Mission_find_token(x,
                                    &wholeSecsFromMillis, &md2);
                                if (wholeSecsFromMillis > static_cast<int32_T>
                                        (md2 - 1)) {
                                    wholeSecsFromMillis = 0;
                                    md2 = 0;
                                } else {
                                    wholeSecsFromMillis = static_cast<int32_T>
                                        (wholeSecsFromMillis - 1);
                                    md2 = static_cast<int32_T>(md2 - 1);
                                }

                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                i = static_cast<int32_T>(b_curKey->size[0] *
                                    b_curKey->size[1]);
                                b_curKey->size[0] = 1;
                                b_curKey->size[1] = static_cast<int32_T>(md2 -
                                    wholeSecsFromMillis);
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (b_curKey, i);
                                loop_ub = static_cast<int32_T>(md2 -
                                    wholeSecsFromMillis);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    b_curKey->data[i] = x->data
                                        [static_cast<int32_T>
                                        (wholeSecsFromMillis + i)];
                                }

                                codegenReal2Mission_strtrim(b_curKey, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp(curSection) &&
                            codegenReal2Mission_strcmp_p(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_5);
                codegenReal2Mission_emxFree_char_T(&tmp_d);
            }

            tmp_1 = codegenReal2Mission_str2double(ret);
            printf("Set Home Point Latitude:\t%f\n", tmp_1.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = codegenReal2Mission_cfopen_o("config.ini", "rb");
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread_i(static_cast<real_T>(fileid), q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose_m(static_cast<real_T>(fileid));
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_c, 2);
                codegenReal2Mission_emxInit_char_T(&data_4, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_4->size[0] * data_4->size[1]);
                    data_4->size[0] = 1;
                    data_4->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_4, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_4->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_4, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_c);
                    codegenReal2Mission_strtrim(tmp_c, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    md2 = 0;
                                } else {
                                    b = 1;
                                    md2 = static_cast<int32_T>(curLine->size[1]
                                        - 1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(md2 - b);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    x);
                                codegenReal2Mission_find_token(x,
                                    &wholeSecsFromMillis, &md2);
                                if (wholeSecsFromMillis > static_cast<int32_T>
                                        (md2 - 1)) {
                                    b_md2 = 0;
                                    b = 0;
                                } else {
                                    b_md2 = static_cast<int32_T>
                                        (wholeSecsFromMillis - 1);
                                    b = static_cast<int32_T>(md2 - 1);
                                }

                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                i = static_cast<int32_T>(b_curKey->size[0] *
                                    b_curKey->size[1]);
                                b_curKey->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b - b_md2);
                                b_curKey->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (b_curKey, i);
                                for (i = 0; i <= static_cast<int32_T>(loop_ub -
                                        1); i++) {
                                    b_curKey->data[i] = x->data
                                        [static_cast<int32_T>(b_md2 + i)];
                                }

                                codegenReal2Mission_strtrim(b_curKey, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp(curSection) &&
                            codegenReal2Mission_strcmp_p4(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_4);
                codegenReal2Mission_emxFree_char_T(&tmp_c);
            }

            tmp_2 = codegenReal2Mission_str2double(ret);
            printf("Set Home Point Longitude:\t%f\n", tmp_2.re);
            fflush(stdout);
            ret->size[0] = 1;
            ret->size[1] = 0;
            fileid = codegenReal2Mission_cfopen_o("config.ini", "rb");
            if (static_cast<int32_T>(fileid) < 0) {
                printf("INI-file \"%s\" was not found or could not be read.\n",
                       "config.ini");
                fflush(stdout);
            } else {
                codegenReal2Mission_fread_i(static_cast<real_T>(fileid), q);
                i = static_cast<int32_T>(data->size[0] * data->size[1]);
                data->size[0] = 1;
                data->size[1] = q->size[0];
                codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                loop_ub = q->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    data->data[i] = q->data[i];
                }

                codegenReal2Mission_cfclose_m(static_cast<real_T>(fileid));
                curSection->size[0] = 1;
                curSection->size[1] = 0;
                curKey->size[0] = 1;
                curKey->size[1] = 0;
                curVal->size[0] = 1;
                curVal->size[1] = 0;
                codegenReal2Mission_emxInit_char_T(&tmp_b, 2);
                codegenReal2Mission_emxInit_char_T(&data_3, 2);
                exitg1 = false;
                while ((!exitg1) && (data->size[1] != 0)) {
                    i = static_cast<int32_T>(data_3->size[0] * data_3->size[1]);
                    data_3->size[0] = 1;
                    data_3->size[1] = data->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data_3, i);
                    loop_ub = static_cast<int32_T>(static_cast<int32_T>
                        (data->size[0] * data->size[1]) - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        data_3->data[i] = data->data[i];
                    }

                    codegenReal2Mission_strtok(data_3, curLine, data);
                    codegenReal2Mission_strtok_p(curLine, tmp_b);
                    codegenReal2Mission_strtrim(tmp_b, curLine);
                    if (curLine->size[1] >= 2) {
                        rtb_NotEqual = false;
                        if (curLine->data[0] == '[') {
                            rtb_NotEqual = true;
                        }

                        guard1 = false;
                        if (rtb_NotEqual) {
                            rtb_NotEqual = false;
                            if (curLine->data[static_cast<int32_T>(curLine->
                                    size[1] - 1)] == ']') {
                                rtb_NotEqual = true;
                            }

                            if (rtb_NotEqual) {
                                if (static_cast<int32_T>(curLine->size[1] - 1) <
                                    2) {
                                    b = 0;
                                    b_md2 = 0;
                                } else {
                                    b = 1;
                                    b_md2 = static_cast<int32_T>(curLine->size[1]
                                        - 1);
                                }

                                i = static_cast<int32_T>(curSection->size[0] *
                                    curSection->size[1]);
                                curSection->size[0] = 1;
                                loop_ub = static_cast<int32_T>(b_md2 - b);
                                curSection->size[1] = loop_ub;
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (curSection, i);
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
                                rtb_NotEqual = true;
                            }

                            if ((static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(rtb_NotEqual) ^ 1))) &&
                                codegenReal2Mission_contains(curLine)) {
                                codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                    x);
                                codegenReal2Mission_find_token(x, &b_md2,
                                    &wholeSecsFromMillis);
                                if (b_md2 > static_cast<int32_T>
                                        (wholeSecsFromMillis - 1)) {
                                    b = 0;
                                    wholeSecsFromMillis = -1;
                                } else {
                                    b = static_cast<int32_T>(b_md2 - 1);
                                    wholeSecsFromMillis = static_cast<int32_T>
                                        (wholeSecsFromMillis - 2);
                                }

                                codegenReal2Mission_strtrim(b_curKey, curKey);
                                i = static_cast<int32_T>(b_curKey->size[0] *
                                    b_curKey->size[1]);
                                b_curKey->size[0] = 1;
                                b_curKey->size[1] = static_cast<int32_T>(
                                    static_cast<int32_T>(wholeSecsFromMillis - b)
                                    + 1);
                                codegenReal2Mission_emxEnsureCapacity_char_T
                                    (b_curKey, i);
                                loop_ub = static_cast<int32_T>
                                    (wholeSecsFromMillis - b);
                                for (i = 0; i <= loop_ub; i++) {
                                    b_curKey->data[i] = x->data
                                        [static_cast<int32_T>(b + i)];
                                }

                                codegenReal2Mission_strtrim(b_curKey, curVal);
                            }
                        }
                    }

                    if (codegenReal2Mission_strcmp(curSection) &&
                            codegenReal2Mission_strcmp_p4a(curKey)) {
                        i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                        loop_ub = curVal->size[1];
                        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++)
                        {
                            ret->data[i] = curVal->data[i];
                        }

                        exitg1 = true;
                    }
                }

                codegenReal2Mission_emxFree_char_T(&data_3);
                codegenReal2Mission_emxFree_char_T(&tmp_b);
            }

            tmp_3 = codegenReal2Mission_str2double(ret);
            printf("Set Home Point Altitude:\t%f\n", tmp_3.re);
            fflush(stdout);
            codegenReal2Mission_DW.HomePoint[0] = tmp_1.re;
            codegenReal2Mission_DW.HomePoint[1] = tmp_2.re;
            codegenReal2Mission_DW.HomePoint[2] = tmp_3.re;
            codegenReal2Mission_DW.HomePoint_not_empty = true;
            b_x[0] = std::isnan(codegenReal2Mission_DW.HomePoint[0]);
            b_x[1] = std::isnan(codegenReal2Mission_DW.HomePoint[1]);
            b_x[2] = std::isnan(codegenReal2Mission_DW.HomePoint[2]);
            rtb_NotEqual = false;
            md2 = 0;
            exitg1 = false;
            while ((!exitg1) && (md2 < 3)) {
                if (b_x[md2]) {
                    rtb_NotEqual = true;
                    exitg1 = true;
                } else {
                    md2 = static_cast<int32_T>(md2 + 1);
                }
            }

            if (rtb_NotEqual) {
                // '<S59>:1:7'
                // '<S59>:1:8'
                codegenReal2Mission_DW.HomePoint[0] = 35.8617;
                codegenReal2Mission_DW.HomePoint[1] = 104.1954;
                codegenReal2Mission_DW.HomePoint[2] = 0.0;
            }
        }

        // Switch: '<S73>/Switch' incorporates:
        //   Abs: '<S73>/Abs'
        //   Bias: '<S73>/Bias'
        //   Bias: '<S73>/Bias1'
        //   Constant: '<S73>/Constant2'
        //   Constant: '<S74>/Constant'
        //   MATLAB Function: '<S9>/ReadHomePoint'
        //   Math: '<S73>/Math Function1'
        //   RelationalOperator: '<S74>/Compare'

        // '<S59>:1:12'
        if (std::abs(codegenReal2Mission_DW.HomePoint[0]) > 180.0) {
            b_I = rt_modd_snf(codegenReal2Mission_DW.HomePoint[0] + 180.0, 360.0)
                - 180.0;
        } else {
            b_I = codegenReal2Mission_DW.HomePoint[0];
        }

        // End of Switch: '<S73>/Switch'

        // Abs: '<S70>/Abs1'
        Lat = std::abs(b_I);

        // Switch: '<S70>/Switch' incorporates:
        //   Bias: '<S70>/Bias'
        //   Bias: '<S70>/Bias1'
        //   Constant: '<S61>/Constant'
        //   Constant: '<S61>/Constant1'
        //   Constant: '<S72>/Constant'
        //   Gain: '<S70>/Gain'
        //   Product: '<S70>/Divide1'
        //   RelationalOperator: '<S72>/Compare'
        //   Signum: '<S70>/Sign1'
        //   Switch: '<S61>/Switch1'

        if (Lat > 90.0) {
            // Signum: '<S70>/Sign1'
            if (std::isnan(b_I)) {
                a__17 = (rtNaN);
            } else if (b_I < 0.0) {
                a__17 = -1.0;
            } else {
                a__17 = static_cast<real_T>(b_I > 0.0);
            }

            b_I = (-(Lat - 90.0) + 90.0) * a__17;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S70>/Switch'

        // Sum: '<S61>/Sum' incorporates:
        //   MATLAB Function: '<S9>/ReadHomePoint'
        //   Switch: '<S61>/Switch1'

        D = static_cast<real_T>(i) + codegenReal2Mission_DW.HomePoint[1];

        // Switch: '<S71>/Switch' incorporates:
        //   Abs: '<S71>/Abs'
        //   Bias: '<S71>/Bias'
        //   Bias: '<S71>/Bias1'
        //   Constant: '<S71>/Constant2'
        //   Constant: '<S75>/Constant'
        //   Math: '<S71>/Math Function1'
        //   RelationalOperator: '<S75>/Compare'

        if (std::abs(D) > 180.0) {
            D = rt_modd_snf(D + 180.0, 360.0) - 180.0;
        }

        // End of Switch: '<S71>/Switch'

        // Sum: '<S58>/Sum1'
        rtb_Sum1_idx_0 = codegenReal2Mission_DW.Receive_m.Latitude_deg - b_I;
        da_im = codegenReal2Mission_DW.Receive_m.Longitude_deg - D;

        // Switch: '<S67>/Switch' incorporates:
        //   Abs: '<S67>/Abs'
        //   Bias: '<S67>/Bias'
        //   Bias: '<S67>/Bias1'
        //   Constant: '<S67>/Constant2'
        //   Constant: '<S68>/Constant'
        //   Math: '<S67>/Math Function1'
        //   RelationalOperator: '<S68>/Compare'

        if (std::abs(rtb_Sum1_idx_0) > 180.0) {
            D = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) - 180.0;
        } else {
            D = rtb_Sum1_idx_0;
        }

        // End of Switch: '<S67>/Switch'

        // Abs: '<S64>/Abs1'
        Lat = std::abs(D);

        // Switch: '<S64>/Switch' incorporates:
        //   Bias: '<S64>/Bias'
        //   Bias: '<S64>/Bias1'
        //   Constant: '<S60>/Constant'
        //   Constant: '<S60>/Constant1'
        //   Constant: '<S66>/Constant'
        //   Gain: '<S64>/Gain'
        //   Product: '<S64>/Divide1'
        //   RelationalOperator: '<S66>/Compare'
        //   Signum: '<S64>/Sign1'
        //   Switch: '<S60>/Switch1'

        if (Lat > 90.0) {
            // Signum: '<S64>/Sign1'
            if (std::isnan(D)) {
                a__17 = (rtNaN);
            } else if (D < 0.0) {
                a__17 = -1.0;
            } else {
                a__17 = static_cast<real_T>(D > 0.0);
            }

            D = (-(Lat - 90.0) + 90.0) * a__17;
            i = 180;
        } else {
            i = 0;
        }

        // End of Switch: '<S64>/Switch'

        // Sum: '<S60>/Sum' incorporates:
        //   Switch: '<S60>/Switch1'

        Lat = static_cast<real_T>(i) + da_im;

        // Switch: '<S65>/Switch' incorporates:
        //   Abs: '<S65>/Abs'
        //   Bias: '<S65>/Bias'
        //   Bias: '<S65>/Bias1'
        //   Constant: '<S65>/Constant2'
        //   Constant: '<S69>/Constant'
        //   Math: '<S65>/Math Function1'
        //   RelationalOperator: '<S69>/Compare'

        if (std::abs(Lat) > 180.0) {
            Lat = rt_modd_snf(Lat + 180.0, 360.0) - 180.0;
        }

        // End of Switch: '<S65>/Switch'

        // UnitConversion: '<S63>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        rtb_Sum1_idx_0 = 0.017453292519943295 * D;
        da_im = 0.017453292519943295 * Lat;

        // UnitConversion: '<S78>/Unit Conversion'
        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        b_I *= 0.017453292519943295;

        // Trigonometry: '<S79>/Trigonometric Function1'
        Lat = std::sin(b_I);

        // Sum: '<S79>/Sum1' incorporates:
        //   Constant: '<S79>/Constant'
        //   Product: '<S79>/Product1'

        Lat = 1.0 - 0.0066943799901413295 * Lat * Lat;

        // Product: '<S77>/Product1' incorporates:
        //   Constant: '<S77>/Constant1'
        //   Sqrt: '<S77>/sqrt'

        D = 6.378137E+6 / std::sqrt(Lat);

        // Product: '<S62>/dNorth' incorporates:
        //   Constant: '<S77>/Constant2'
        //   Product: '<S77>/Product3'
        //   Trigonometry: '<S77>/Trigonometric Function1'

        Lat = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, D * 0.99330562000985867 / Lat);

        // Product: '<S62>/dEast' incorporates:
        //   Constant: '<S77>/Constant3'
        //   Product: '<S77>/Product4'
        //   Trigonometry: '<S77>/Trigonometric Function'
        //   Trigonometry: '<S77>/Trigonometric Function2'

        // Unit Conversion - from: deg to: rad
        // Expression: output = (0.0174533*input) + (0)
        D = 1.0 / rt_atan2d_snf(1.0, D * std::cos(b_I)) * da_im;

        // BusCreator: '<S9>/FixedWingGuidanceStateBus' incorporates:
        //   Constant: '<S9>/dummyRollAngleRate'
        //   Gain: '<S55>/Gain1'
        //   Gain: '<S56>/Gain1'
        //   Gain: '<S57>/Gain1'
        //   MATLAB Function: '<S9>/ReadHomePoint'
        //   Product: '<S62>/x*cos'
        //   Product: '<S62>/x*sin'
        //   Product: '<S62>/y*cos'
        //   Product: '<S62>/y*sin'
        //   Sum: '<S58>/Sum'
        //   Sum: '<S62>/Sum2'
        //   Sum: '<S62>/Sum3'

        rtb_FixedWingGuidanceStateBus.Height =
            codegenReal2Mission_DW.Receive_m.Height_meter -
            codegenReal2Mission_DW.HomePoint[2];
        rtb_FixedWingGuidanceStateBus.HeadingAngle = 0.017453292519943295 *
            codegenReal2Mission_DW.Receive_m.HeadingAngle_deg;
        rtb_FixedWingGuidanceStateBus.FlightPathAngle = 0.017453292519943295 *
            codegenReal2Mission_DW.Receive_m.FlightPathAngle_deg;
        rtb_FixedWingGuidanceStateBus.RollAngle = 0.017453292519943295 *
            codegenReal2Mission_DW.Receive_m.RollAngle_deg;
        rtb_FixedWingGuidanceStateBus.North = D * 0.0 + Lat;
        rtb_FixedWingGuidanceStateBus.East = D - Lat * 0.0;
        rtb_FixedWingGuidanceStateBus.AirSpeed =
            codegenReal2Mission_DW.Receive_m.AirSpeed_mps;
        rtb_FixedWingGuidanceStateBus.RollAngleRate = 0.0;

        // Memory: '<S2>/Memory'
        rtb_Memory_m = codegenReal2Mission_DW.Memory_PreviousInput_l;

        // ModelReference generated from: '<S8>/ImmedMission'
        ImmedMission(&rtb_SwitchMissionUAVState,
                     &codegenReal2Mission_DW.RcvImmedCMD_o2, &NichtAvoidDanger,
                     &rtb_FixedWingGuidanceStateBus,
                     &codegenReal2Mission_DW.RcvNextMission.MissionMode,
                     &codegenReal2Mission_DW.RcvNextMission.MissionLocation.degHDG,
                     &codegenReal2Mission_DW.RcvNextMission.params.Param3,
                     &codegenReal2Mission_DW.RcvNextMission.numUAV,
                     &codegenReal2Mission_DW.RcvNextMission.FormationPos,
                     &codegenReal2Mission_DW.RateTransition_c[0], &rtb_Memory_m,
                     &codegenReal2Mission_DW.Receive_m.UAV_ID,
                     &codegenReal2Mission_DW.thisTaskStatus,
                     &codegenReal2Mission_DW.ImmedMission_o2,
                     &codegenReal2Mission_DW.ImmedMission_o3[0],
                     &codegenReal2Mission_DW.ImmedMission_o4,
                     &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw),
                     &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtzce));

        // Outputs for Atomic SubSystem: '<S12>/VisualizeUAV'
        // RateTransition: '<S99>/Rate Transition'
        if ((&codegenReal2Mission_M)->Timing.RateInteraction.TID1_3 == 1) {
            codegenReal2Mission_DW.RateTransition_WrBufIdx = static_cast<int8_T>
                (static_cast<int32_T>
                 (codegenReal2Mission_DW.RateTransition_WrBufIdx) == 0);
        }

        // End of RateTransition: '<S99>/Rate Transition'
        // End of Outputs for SubSystem: '<S12>/VisualizeUAV'

        // Receive: '<S5>/Receive'
        wholeSecsFromMillis = codegenReal2Mission_Receive_h_RecvData
            (&codegenReal2Mission_DW.Receive_o2_a);

        // Outputs for Enabled SubSystem: '<S5>/GenPCD' incorporates:
        //   EnablePort: '<S13>/Enable'

        if (wholeSecsFromMillis != 1) {
            int32_T DangerList_size_idx_0;

            // MATLAB Function: '<S13>/ReadHomePoint'
            // MATLAB Function 'ReadHomePoint': '<S16>:1'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (codegenReal2Mission_DW.HomePoint_not_empty_k) ^ 1))) {
                // '<S16>:1:5'
                // '<S16>:1:6'
                ret->size[0] = 1;
                ret->size[1] = 0;
                fileid = codegenReal2Mission_cfopen_p("config.ini", "rb");
                if (static_cast<int32_T>(fileid) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    codegenReal2Mission_fread_j(static_cast<real_T>(fileid), q);
                    i = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                    loop_ub = q->size[0];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        data->data[i] = q->data[i];
                    }

                    codegenReal2Mission_cfclose_g(static_cast<real_T>(fileid));
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    codegenReal2Mission_emxInit_char_T(&tmp_a, 2);
                    codegenReal2Mission_emxInit_char_T(&data_2, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i = static_cast<int32_T>(data_2->size[0] * data_2->size
                            [1]);
                        data_2->size[0] = 1;
                        data_2->size[1] = data->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(data_2, i);
                        loop_ub = static_cast<int32_T>(static_cast<int32_T>
                            (data->size[0] * data->size[1]) - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            data_2->data[i] = data->data[i];
                        }

                        codegenReal2Mission_strtok(data_2, curLine, data);
                        codegenReal2Mission_strtok_p(curLine, tmp_a);
                        codegenReal2Mission_strtrim(tmp_a, curLine);
                        if (curLine->size[1] >= 2) {
                            rtb_NotEqual = false;
                            if (curLine->data[0] == '[') {
                                rtb_NotEqual = true;
                            }

                            guard1 = false;
                            if (rtb_NotEqual) {
                                rtb_NotEqual = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    rtb_NotEqual = true;
                                }

                                if (rtb_NotEqual) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        md2 = 0;
                                        b = 0;
                                    } else {
                                        md2 = 1;
                                        b = static_cast<int32_T>(curLine->size[1]
                                            - 1);
                                    }

                                    i = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(b - md2);
                                    curSection->size[1] = loop_ub;
                                    codegenReal2Mission_emxEnsureCapacity_char_T
                                        (curSection, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
                                        curSection->data[i] = curLine->data[
                                            static_cast<int32_T>(md2 + i)];
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
                                    rtb_NotEqual = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (rtb_NotEqual) ^ 1))) &&
                                        codegenReal2Mission_contains(curLine)) {
                                    codegenReal2Mission_strtok_ph(curLine,
                                        b_curKey, x);
                                    codegenReal2Mission_find_token(x,
                                        &wholeSecsFromMillis, &md2);
                                    if (wholeSecsFromMillis >
                                            static_cast<int32_T>(md2 - 1)) {
                                        wholeSecsFromMillis = 0;
                                        md2 = 0;
                                    } else {
                                        wholeSecsFromMillis =
                                            static_cast<int32_T>
                                            (wholeSecsFromMillis - 1);
                                        md2 = static_cast<int32_T>(md2 - 1);
                                    }

                                    codegenReal2Mission_strtrim(b_curKey, curKey);
                                    i = static_cast<int32_T>(b_curKey->size[0] *
                                        b_curKey->size[1]);
                                    b_curKey->size[0] = 1;
                                    b_curKey->size[1] = static_cast<int32_T>(md2
                                        - wholeSecsFromMillis);
                                    codegenReal2Mission_emxEnsureCapacity_char_T
                                        (b_curKey, i);
                                    loop_ub = static_cast<int32_T>(md2 -
                                        wholeSecsFromMillis);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
                                        b_curKey->data[i] = x->data
                                            [static_cast<int32_T>
                                            (wholeSecsFromMillis + i)];
                                    }

                                    codegenReal2Mission_strtrim(b_curKey, curVal);
                                }
                            }
                        }

                        if (codegenReal2Mission_strcmp(curSection) &&
                                codegenReal2Mission_strcmp_p(curKey)) {
                            i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                            loop_ub = curVal->size[1];
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                ret->data[i] = curVal->data[i];
                            }

                            exitg1 = true;
                        }
                    }

                    codegenReal2Mission_emxFree_char_T(&data_2);
                    codegenReal2Mission_emxFree_char_T(&tmp_a);
                }

                tmp_1 = codegenReal2Mission_str2double(ret);
                printf("Set Home Point Latitude:\t%f\n", tmp_1.re);
                fflush(stdout);
                ret->size[0] = 1;
                ret->size[1] = 0;
                fileid = codegenReal2Mission_cfopen_p("config.ini", "rb");
                if (static_cast<int32_T>(fileid) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    codegenReal2Mission_fread_j(static_cast<real_T>(fileid), q);
                    i = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                    loop_ub = q->size[0];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        data->data[i] = q->data[i];
                    }

                    codegenReal2Mission_cfclose_g(static_cast<real_T>(fileid));
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    codegenReal2Mission_emxInit_char_T(&tmp_9, 2);
                    codegenReal2Mission_emxInit_char_T(&data_1, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i = static_cast<int32_T>(data_1->size[0] * data_1->size
                            [1]);
                        data_1->size[0] = 1;
                        data_1->size[1] = data->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(data_1, i);
                        loop_ub = static_cast<int32_T>(static_cast<int32_T>
                            (data->size[0] * data->size[1]) - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            data_1->data[i] = data->data[i];
                        }

                        codegenReal2Mission_strtok(data_1, curLine, data);
                        codegenReal2Mission_strtok_p(curLine, tmp_9);
                        codegenReal2Mission_strtrim(tmp_9, curLine);
                        if (curLine->size[1] >= 2) {
                            rtb_NotEqual = false;
                            if (curLine->data[0] == '[') {
                                rtb_NotEqual = true;
                            }

                            guard1 = false;
                            if (rtb_NotEqual) {
                                rtb_NotEqual = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    rtb_NotEqual = true;
                                }

                                if (rtb_NotEqual) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        b = 0;
                                        md2 = 0;
                                    } else {
                                        b = 1;
                                        md2 = static_cast<int32_T>(curLine->
                                            size[1] - 1);
                                    }

                                    i = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(md2 - b);
                                    curSection->size[1] = loop_ub;
                                    codegenReal2Mission_emxEnsureCapacity_char_T
                                        (curSection, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
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
                                    rtb_NotEqual = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (rtb_NotEqual) ^ 1))) &&
                                        codegenReal2Mission_contains(curLine)) {
                                    codegenReal2Mission_strtok_ph(curLine,
                                        b_curKey, x);
                                    codegenReal2Mission_find_token(x,
                                        &wholeSecsFromMillis, &md2);
                                    if (wholeSecsFromMillis >
                                            static_cast<int32_T>(md2 - 1)) {
                                        b_md2 = 0;
                                        b = 0;
                                    } else {
                                        b_md2 = static_cast<int32_T>
                                            (wholeSecsFromMillis - 1);
                                        b = static_cast<int32_T>(md2 - 1);
                                    }

                                    codegenReal2Mission_strtrim(b_curKey, curKey);
                                    i = static_cast<int32_T>(b_curKey->size[0] *
                                        b_curKey->size[1]);
                                    b_curKey->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(b - b_md2);
                                    b_curKey->size[1] = loop_ub;
                                    codegenReal2Mission_emxEnsureCapacity_char_T
                                        (b_curKey, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
                                        b_curKey->data[i] = x->data
                                            [static_cast<int32_T>(b_md2 + i)];
                                    }

                                    codegenReal2Mission_strtrim(b_curKey, curVal);
                                }
                            }
                        }

                        if (codegenReal2Mission_strcmp(curSection) &&
                                codegenReal2Mission_strcmp_p4(curKey)) {
                            i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                            loop_ub = curVal->size[1];
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                ret->data[i] = curVal->data[i];
                            }

                            exitg1 = true;
                        }
                    }

                    codegenReal2Mission_emxFree_char_T(&data_1);
                    codegenReal2Mission_emxFree_char_T(&tmp_9);
                }

                tmp_2 = codegenReal2Mission_str2double(ret);
                printf("Set Home Point Longitude:\t%f\n", tmp_2.re);
                fflush(stdout);
                ret->size[0] = 1;
                ret->size[1] = 0;
                fileid = codegenReal2Mission_cfopen_p("config.ini", "rb");
                if (static_cast<int32_T>(fileid) < 0) {
                    printf("INI-file \"%s\" was not found or could not be read.\n",
                           "config.ini");
                    fflush(stdout);
                } else {
                    codegenReal2Mission_fread_j(static_cast<real_T>(fileid), q);
                    i = static_cast<int32_T>(data->size[0] * data->size[1]);
                    data->size[0] = 1;
                    data->size[1] = q->size[0];
                    codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
                    loop_ub = q->size[0];
                    for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                        data->data[i] = q->data[i];
                    }

                    codegenReal2Mission_cfclose_g(static_cast<real_T>(fileid));
                    curSection->size[0] = 1;
                    curSection->size[1] = 0;
                    curKey->size[0] = 1;
                    curKey->size[1] = 0;
                    curVal->size[0] = 1;
                    curVal->size[1] = 0;
                    codegenReal2Mission_emxInit_char_T(&tmp_8, 2);
                    codegenReal2Mission_emxInit_char_T(&data_0, 2);
                    exitg1 = false;
                    while ((!exitg1) && (data->size[1] != 0)) {
                        i = static_cast<int32_T>(data_0->size[0] * data_0->size
                            [1]);
                        data_0->size[0] = 1;
                        data_0->size[1] = data->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(data_0, i);
                        loop_ub = static_cast<int32_T>(static_cast<int32_T>
                            (data->size[0] * data->size[1]) - 1);
                        for (i = 0; i <= loop_ub; i++) {
                            data_0->data[i] = data->data[i];
                        }

                        codegenReal2Mission_strtok(data_0, curLine, data);
                        codegenReal2Mission_strtok_p(curLine, tmp_8);
                        codegenReal2Mission_strtrim(tmp_8, curLine);
                        if (curLine->size[1] >= 2) {
                            rtb_NotEqual = false;
                            if (curLine->data[0] == '[') {
                                rtb_NotEqual = true;
                            }

                            guard1 = false;
                            if (rtb_NotEqual) {
                                rtb_NotEqual = false;
                                if (curLine->data[static_cast<int32_T>
                                        (curLine->size[1] - 1)] == ']') {
                                    rtb_NotEqual = true;
                                }

                                if (rtb_NotEqual) {
                                    if (static_cast<int32_T>(curLine->size[1] -
                                            1) < 2) {
                                        b = 0;
                                        b_md2 = 0;
                                    } else {
                                        b = 1;
                                        b_md2 = static_cast<int32_T>
                                            (curLine->size[1] - 1);
                                    }

                                    i = static_cast<int32_T>(curSection->size[0]
                                        * curSection->size[1]);
                                    curSection->size[0] = 1;
                                    loop_ub = static_cast<int32_T>(b_md2 - b);
                                    curSection->size[1] = loop_ub;
                                    codegenReal2Mission_emxEnsureCapacity_char_T
                                        (curSection, i);
                                    for (i = 0; i <= static_cast<int32_T>
                                            (loop_ub - 1); i++) {
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
                                    rtb_NotEqual = true;
                                }

                                if ((static_cast<boolean_T>(static_cast<int32_T>
                                                            (static_cast<int32_T>
                                        (rtb_NotEqual) ^ 1))) &&
                                        codegenReal2Mission_contains(curLine)) {
                                    codegenReal2Mission_strtok_ph(curLine,
                                        b_curKey, x);
                                    codegenReal2Mission_find_token(x, &b_md2,
                                        &wholeSecsFromMillis);
                                    if (b_md2 > static_cast<int32_T>
                                            (wholeSecsFromMillis - 1)) {
                                        b = 0;
                                        wholeSecsFromMillis = -1;
                                    } else {
                                        b = static_cast<int32_T>(b_md2 - 1);
                                        wholeSecsFromMillis =
                                            static_cast<int32_T>
                                            (wholeSecsFromMillis - 2);
                                    }

                                    codegenReal2Mission_strtrim(b_curKey, curKey);
                                    i = static_cast<int32_T>(b_curKey->size[0] *
                                        b_curKey->size[1]);
                                    b_curKey->size[0] = 1;
                                    b_curKey->size[1] = static_cast<int32_T>(
                                        static_cast<int32_T>(wholeSecsFromMillis
                                        - b) + 1);
                                    codegenReal2Mission_emxEnsureCapacity_char_T
                                        (b_curKey, i);
                                    loop_ub = static_cast<int32_T>
                                        (wholeSecsFromMillis - b);
                                    for (i = 0; i <= loop_ub; i++) {
                                        b_curKey->data[i] = x->data
                                            [static_cast<int32_T>(b + i)];
                                    }

                                    codegenReal2Mission_strtrim(b_curKey, curVal);
                                }
                            }
                        }

                        if (codegenReal2Mission_strcmp(curSection) &&
                                codegenReal2Mission_strcmp_p4a(curKey)) {
                            i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                            ret->size[0] = 1;
                            ret->size[1] = curVal->size[1];
                            codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                            loop_ub = curVal->size[1];
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                ret->data[i] = curVal->data[i];
                            }

                            exitg1 = true;
                        }
                    }

                    codegenReal2Mission_emxFree_char_T(&data_0);
                    codegenReal2Mission_emxFree_char_T(&tmp_8);
                }

                tmp_3 = codegenReal2Mission_str2double(ret);
                printf("Set Home Point Altitude:\t%f\n", tmp_3.re);
                fflush(stdout);
                codegenReal2Mission_DW.HomePoint_g[0] = tmp_1.re;
                codegenReal2Mission_DW.HomePoint_g[1] = tmp_2.re;
                codegenReal2Mission_DW.HomePoint_g[2] = tmp_3.re;
                codegenReal2Mission_DW.HomePoint_not_empty_k = true;
                b_x[0] = std::isnan(codegenReal2Mission_DW.HomePoint_g[0]);
                b_x[1] = std::isnan(codegenReal2Mission_DW.HomePoint_g[1]);
                b_x[2] = std::isnan(codegenReal2Mission_DW.HomePoint_g[2]);
                rtb_NotEqual = false;
                md2 = 0;
                exitg1 = false;
                while ((!exitg1) && (md2 < 3)) {
                    if (b_x[md2]) {
                        rtb_NotEqual = true;
                        exitg1 = true;
                    } else {
                        md2 = static_cast<int32_T>(md2 + 1);
                    }
                }

                if (rtb_NotEqual) {
                    // '<S16>:1:7'
                    // '<S16>:1:8'
                    codegenReal2Mission_DW.HomePoint_g[0] = 35.8617;
                    codegenReal2Mission_DW.HomePoint_g[1] = 104.1954;
                    codegenReal2Mission_DW.HomePoint_g[2] = 0.0;
                }
            }

            // Switch: '<S32>/Switch' incorporates:
            //   Abs: '<S32>/Abs'
            //   Bias: '<S32>/Bias'
            //   Bias: '<S32>/Bias1'
            //   Constant: '<S32>/Constant2'
            //   Constant: '<S33>/Constant'
            //   MATLAB Function: '<S13>/ReadHomePoint'
            //   Math: '<S32>/Math Function1'
            //   RelationalOperator: '<S33>/Compare'

            // '<S16>:1:12'
            if (std::abs(codegenReal2Mission_DW.HomePoint_g[0]) > 180.0) {
                b_I = rt_modd_snf(codegenReal2Mission_DW.HomePoint_g[0] + 180.0,
                                  360.0) - 180.0;
            } else {
                b_I = codegenReal2Mission_DW.HomePoint_g[0];
            }

            // End of Switch: '<S32>/Switch'

            // Abs: '<S29>/Abs1'
            Lat = std::abs(b_I);

            // Switch: '<S29>/Switch' incorporates:
            //   Bias: '<S29>/Bias'
            //   Bias: '<S29>/Bias1'
            //   Constant: '<S20>/Constant'
            //   Constant: '<S20>/Constant1'
            //   Constant: '<S31>/Constant'
            //   Gain: '<S29>/Gain'
            //   Product: '<S29>/Divide1'
            //   RelationalOperator: '<S31>/Compare'
            //   Signum: '<S29>/Sign1'
            //   Switch: '<S20>/Switch1'

            if (Lat > 90.0) {
                // Signum: '<S29>/Sign1'
                if (std::isnan(b_I)) {
                    a__17 = (rtNaN);
                } else if (b_I < 0.0) {
                    a__17 = -1.0;
                } else {
                    a__17 = static_cast<real_T>(b_I > 0.0);
                }

                b_I = (-(Lat - 90.0) + 90.0) * a__17;
                i = 180;
            } else {
                i = 0;
            }

            // End of Switch: '<S29>/Switch'

            // Sum: '<S20>/Sum' incorporates:
            //   MATLAB Function: '<S13>/ReadHomePoint'
            //   Switch: '<S20>/Switch1'

            D = static_cast<real_T>(i) + codegenReal2Mission_DW.HomePoint_g[1];

            // Switch: '<S30>/Switch' incorporates:
            //   Abs: '<S30>/Abs'
            //   Bias: '<S30>/Bias'
            //   Bias: '<S30>/Bias1'
            //   Constant: '<S30>/Constant2'
            //   Constant: '<S34>/Constant'
            //   Math: '<S30>/Math Function1'
            //   RelationalOperator: '<S34>/Compare'

            if (std::abs(D) > 180.0) {
                D = rt_modd_snf(D + 180.0, 360.0) - 180.0;
            }

            // End of Switch: '<S30>/Switch'

            // Sum: '<S15>/Sum1'
            rtb_Sum1_idx_0 = codegenReal2Mission_DW.Receive_o2_a.DangerLoc.Lat -
                b_I;
            da_im = codegenReal2Mission_DW.Receive_o2_a.DangerLoc.Lon - D;

            // Switch: '<S26>/Switch' incorporates:
            //   Abs: '<S26>/Abs'
            //   Bias: '<S26>/Bias'
            //   Bias: '<S26>/Bias1'
            //   Constant: '<S26>/Constant2'
            //   Constant: '<S27>/Constant'
            //   Math: '<S26>/Math Function1'
            //   RelationalOperator: '<S27>/Compare'

            if (std::abs(rtb_Sum1_idx_0) > 180.0) {
                D = rt_modd_snf(rtb_Sum1_idx_0 + 180.0, 360.0) - 180.0;
            } else {
                D = rtb_Sum1_idx_0;
            }

            // End of Switch: '<S26>/Switch'

            // Abs: '<S23>/Abs1'
            Lat = std::abs(D);

            // Switch: '<S23>/Switch' incorporates:
            //   Bias: '<S23>/Bias'
            //   Bias: '<S23>/Bias1'
            //   Constant: '<S19>/Constant'
            //   Constant: '<S19>/Constant1'
            //   Constant: '<S25>/Constant'
            //   Gain: '<S23>/Gain'
            //   Product: '<S23>/Divide1'
            //   RelationalOperator: '<S25>/Compare'
            //   Signum: '<S23>/Sign1'
            //   Switch: '<S19>/Switch1'

            if (Lat > 90.0) {
                // Signum: '<S23>/Sign1'
                if (std::isnan(D)) {
                    a__17 = (rtNaN);
                } else if (D < 0.0) {
                    a__17 = -1.0;
                } else {
                    a__17 = static_cast<real_T>(D > 0.0);
                }

                D = (-(Lat - 90.0) + 90.0) * a__17;
                i = 180;
            } else {
                i = 0;
            }

            // End of Switch: '<S23>/Switch'

            // Sum: '<S19>/Sum' incorporates:
            //   Switch: '<S19>/Switch1'

            Alt = static_cast<real_T>(i) + da_im;

            // Switch: '<S24>/Switch' incorporates:
            //   Abs: '<S24>/Abs'
            //   Bias: '<S24>/Bias'
            //   Bias: '<S24>/Bias1'
            //   Constant: '<S24>/Constant2'
            //   Constant: '<S28>/Constant'
            //   Math: '<S24>/Math Function1'
            //   RelationalOperator: '<S28>/Compare'

            if (std::abs(Alt) > 180.0) {
                Alt = rt_modd_snf(Alt + 180.0, 360.0) - 180.0;
            }

            // End of Switch: '<S24>/Switch'

            // UnitConversion: '<S22>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Sum1_idx_0 = 0.017453292519943295 * D;
            da_im = 0.017453292519943295 * Alt;

            // UnitConversion: '<S37>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            b_I *= 0.017453292519943295;

            // Trigonometry: '<S38>/Trigonometric Function1'
            D = std::sin(b_I);

            // Sum: '<S38>/Sum1' incorporates:
            //   Constant: '<S38>/Constant'
            //   Product: '<S38>/Product1'

            D = 1.0 - 0.0066943799901413295 * D * D;

            // Product: '<S36>/Product1' incorporates:
            //   Constant: '<S36>/Constant1'
            //   Sqrt: '<S36>/sqrt'

            Alt = 6.378137E+6 / std::sqrt(D);

            // Product: '<S21>/dNorth' incorporates:
            //   Constant: '<S36>/Constant2'
            //   Product: '<S36>/Product3'
            //   Trigonometry: '<S36>/Trigonometric Function1'

            D = rtb_Sum1_idx_0 / rt_atan2d_snf(1.0, Alt * 0.99330562000985867 /
                D);

            // Product: '<S21>/dEast' incorporates:
            //   Constant: '<S36>/Constant3'
            //   Product: '<S36>/Product4'
            //   Trigonometry: '<S36>/Trigonometric Function'
            //   Trigonometry: '<S36>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            b_I = 1.0 / rt_atan2d_snf(1.0, Alt * std::cos(b_I)) * da_im;

            // SignalConversion generated from: '<S13>/Vector Concatenate' incorporates:
            //   Product: '<S21>/x*cos'
            //   Product: '<S21>/x*sin'
            //   Product: '<S21>/y*cos'
            //   Product: '<S21>/y*sin'
            //   Sum: '<S21>/Sum2'
            //   Sum: '<S21>/Sum3'

            rtb_VectorConcatenate[1] = b_I * 0.0 + D;
            rtb_VectorConcatenate[2] = b_I - D * 0.0;

            // DataTypeConversion: '<S13>/DangerID'
            rtb_VectorConcatenate[0] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_a.DangerID);

            // DataTypeConversion: '<S13>/DangerRadius'
            rtb_VectorConcatenate[3] =
                codegenReal2Mission_DW.Receive_o2_a.Radius;

            // MATLAB Function: '<S13>/sizeconversion'
            // MATLAB Function 'MissionLogic/DangerLidarScanPoints/GenPCD/sizeconversion': '<S18>:1' 
            // '<S18>:1:3'
            codegenReal2Mission_DW.SFunction_DIMS2[0] = 1;
            codegenReal2Mission_DW.SFunction_DIMS2[1] = 4;

            // MATLAB Function: '<S13>/getDangerList'
            // MATLAB Function 'MissionLogic/DangerLidarScanPoints/GenPCD/getDangerList': '<S17>:1' 
            // '<S17>:1:5'
            for (i = 0; i < 64; i++) {
                x_0[i] = std::isnan(codegenReal2Mission_DW.DangerList[i]);
            }

            wholeSecsFromMillis = 0;
            b = 0;
            exitg1 = false;
            while ((!exitg1) && (b < 64)) {
                if (x_0[b]) {
                    wholeSecsFromMillis = 1;
                    ii_data = static_cast<int8_T>(static_cast<int32_T>(b + 1));
                    exitg1 = true;
                } else {
                    b = static_cast<int32_T>(b + 1);
                }
            }

            // '<S17>:1:5'
            loop_ub = codegenReal2Mission_DW.SFunction_DIMS2[0];
            for (i = 0; i < 4; i++) {
                for (b_md2 = 0; b_md2 <= static_cast<int32_T>(loop_ub - 1);
                        b_md2++) {
                    codegenReal2Mission_DW.DangerList[static_cast<int32_T>(
                        static_cast<int32_T>(static_cast<int32_T>(ii_data) +
                        static_cast<int32_T>(i << 6)) - 1)] =
                        rtb_VectorConcatenate[static_cast<int32_T>
                        (static_cast<int32_T>
                         (codegenReal2Mission_DW.SFunction_DIMS2[0] * i) + b_md2)];
                }
            }

            // '<S17>:1:6'
            // '<S17>:1:15'
            // '<S17>:1:14'
            for (i = 0; i < 256; i++) {
                Output[i] = (rtNaN);
            }

            // '<S17>:1:15'
            for (i = 0; i < 64; i++) {
                x_0[i] = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(std::isnan
                    (codegenReal2Mission_DW.DangerList[i])) ^ 1));
            }

            wholeSecsFromMillis = 0;
            for (b = 0; b < 64; b++) {
                if (x_0[b]) {
                    wholeSecsFromMillis = static_cast<int32_T>
                        (wholeSecsFromMillis + 1);
                }
            }

            indx_size = wholeSecsFromMillis;
            wholeSecsFromMillis = 0;
            for (b = 0; b < 64; b++) {
                if (x_0[b]) {
                    indx_data[wholeSecsFromMillis] = static_cast<int32_T>(b + 1);
                    wholeSecsFromMillis = static_cast<int32_T>
                        (wholeSecsFromMillis + 1);
                }
            }

            // '<S17>:1:15'
            DangerList_size_idx_0 = indx_size;
            for (i = 0; i < 4; i++) {
                for (b_md2 = 0; b_md2 <= static_cast<int32_T>(indx_size - 1);
                        b_md2++) {
                    DangerList_data[static_cast<int32_T>(b_md2 +
                        static_cast<int32_T>(indx_size * i))] =
                        codegenReal2Mission_DW.DangerList[static_cast<int32_T>(
                        static_cast<int32_T>(static_cast<int32_T>(i << 6) +
                        indx_data[b_md2]) - 1)];
                }
            }

            // '<S17>:1:18'
            wholeSecsFromMillis = indx_size;
            md2 = static_cast<int32_T>(static_cast<int32_T>(indx_size >> 1) - 1);
            for (b = 0; b < 4; b++) {
                for (b_n = 0; b_n <= md2; b_n++) {
                    i = static_cast<int32_T>(indx_size * b);
                    loop_ub = static_cast<int32_T>(b_n + i);
                    Lat = DangerList_data[loop_ub];
                    DangerList_data[loop_ub] = DangerList_data
                        [static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(wholeSecsFromMillis - b_n) + i) -
                        1)];
                    DangerList_data[static_cast<int32_T>(static_cast<int32_T>(
                        static_cast<int32_T>(wholeSecsFromMillis - b_n) +
                        static_cast<int32_T>(indx_size * b)) - 1)] = Lat;
                }
            }

            // '<S17>:1:19'
            wholeSecsFromMillis = indx_size;
            for (i = 0; i <= static_cast<int32_T>(indx_size - 1); i++) {
                DangerList_data_0[i] = DangerList_data[i];
            }

            codegenReal2Mission_unique_vector(DangerList_data_0,
                &wholeSecsFromMillis, a__1_data, &i, indx_data, &indx_size,
                ipos_data, &md2);

            // '<S17>:1:20'
            for (i = 0; i < 4; i++) {
                for (b_md2 = 0; b_md2 <= static_cast<int32_T>(indx_size - 1);
                        b_md2++) {
                    DangerList_data_1[static_cast<int32_T>(b_md2 + static_cast<
                        int32_T>(indx_size * i))] = DangerList_data[static_cast<
                        int32_T>(static_cast<int32_T>(static_cast<int32_T>
                                  (DangerList_size_idx_0 * i) + indx_data[b_md2])
                                 - 1)];
                }
            }

            wholeSecsFromMillis = indx_size;
            loop_ub = static_cast<int32_T>(indx_size << 2);
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                DangerList_data[i] = DangerList_data_1[i];
            }

            // '<S17>:1:21'
            wholeSecsFromMillis = indx_size;
            b_md2 = static_cast<int32_T>(static_cast<int32_T>(indx_size >> 1) -
                1);
            for (md2 = 0; md2 < 4; md2++) {
                for (b_n = 0; b_n <= b_md2; b_n++) {
                    i = static_cast<int32_T>(indx_size * md2);
                    loop_ub = static_cast<int32_T>(b_n + i);
                    Lat = DangerList_data[loop_ub];
                    DangerList_data[loop_ub] = DangerList_data
                        [static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(wholeSecsFromMillis - b_n) + i) -
                        1)];
                    DangerList_data[static_cast<int32_T>(static_cast<int32_T>(
                        static_cast<int32_T>(wholeSecsFromMillis - b_n) +
                        static_cast<int32_T>(indx_size * md2)) - 1)] = Lat;
                }
            }

            // '<S17>:1:23'
            for (i = 0; i <= static_cast<int32_T>(indx_size - 1); i++) {
                x_0[i] = (DangerList_data[static_cast<int32_T>
                          (static_cast<int32_T>(indx_size * 3) + i)] != 0.0);
            }

            wholeSecsFromMillis = static_cast<int32_T>(indx_size - 1);
            b = 0;
            for (b_md2 = 0; b_md2 <= wholeSecsFromMillis; b_md2++) {
                if (x_0[b_md2]) {
                    b = static_cast<int32_T>(b + 1);
                }
            }

            md2 = b;
            b = 0;
            for (b_md2 = 0; b_md2 <= wholeSecsFromMillis; b_md2++) {
                if (x_0[b_md2]) {
                    e_data[b] = static_cast<int8_T>(static_cast<int32_T>(b_md2 +
                        1));
                    b = static_cast<int32_T>(b + 1);
                }
            }

            // '<S17>:1:23'
            // '<S17>:1:25'
            for (i = 0; i < 4; i++) {
                for (b_md2 = 0; b_md2 <= static_cast<int32_T>(md2 - 1); b_md2++)
                {
                    Output[static_cast<int32_T>(b_md2 + static_cast<int32_T>(i <<
                        6))] = DangerList_data[static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>(indx_size * i)
                          + static_cast<int32_T>(e_data[b_md2])) - 1)];
                }
            }

            std::memcpy(&codegenReal2Mission_DW.DangerList[0], &Output[0],
                        static_cast<uint32_T>(sizeof(real_T) << 8U));

            // '<S17>:1:8'
            b = 0;
            for (wholeSecsFromMillis = 0; wholeSecsFromMillis < 64;
                    wholeSecsFromMillis++) {
                rtb_NotEqual = static_cast<boolean_T>(static_cast<int32_T>(
                    static_cast<int32_T>(std::isnan
                    (codegenReal2Mission_DW.DangerList[wholeSecsFromMillis])) ^
                    1));
                if (rtb_NotEqual) {
                    b = static_cast<int32_T>(b + 1);
                }

                x_0[wholeSecsFromMillis] = rtb_NotEqual;
            }

            b_md2 = b;
            wholeSecsFromMillis = 0;
            for (b = 0; b < 64; b++) {
                if (x_0[b]) {
                    b_data[wholeSecsFromMillis] = static_cast<int8_T>(
                        static_cast<int32_T>(b + 1));
                    wholeSecsFromMillis = static_cast<int32_T>
                        (wholeSecsFromMillis + 1);
                }
            }

            // '<S17>:1:8'
            codegenReal2Mission_DW.SFunction_DIMS2_c[0] = b_md2;
            codegenReal2Mission_DW.SFunction_DIMS2_c[1] = 4;

            // Selector: '<S13>/SelectNorthEastRadius' incorporates:
            //   MATLAB Function: '<S13>/getDangerList'

            codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0] =
                codegenReal2Mission_DW.SFunction_DIMS2_c[0];
            codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[1] = 3;
            loop_ub = codegenReal2Mission_DW.SFunction_DIMS2_c[0];
            for (i = 0; i < 3; i++) {
                for (b_md2 = 0; b_md2 <= static_cast<int32_T>(loop_ub - 1);
                        b_md2++) {
                    codegenReal2Mission_DW.SelectNorthEastRadius
                        [static_cast<int32_T>(b_md2 + static_cast<int32_T>
                        (codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0] *
                         i))] = codegenReal2Mission_DW.DangerList
                        [static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(static_cast<int32_T>(i + 1) << 6)
                         + static_cast<int32_T>(b_data[b_md2])) - 1)];
                }
            }

            // End of Selector: '<S13>/SelectNorthEastRadius'

            // MATLAB Function: '<S13>/InterpCircle'
            // MATLAB Function 'MissionLogic/DangerLidarScanPoints/GenPCD/InterpCircle': '<S14>:1' 
            // '<S14>:1:2'
            codegenReal2Mission_DW.SFunction_DIMS2_i[0] = 0;
            codegenReal2Mission_DW.SFunction_DIMS2_i[1] = 2;
            b = codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0];

            // '<S14>:1:5'
            codegenReal2Mission_emxInit_real_T(&varargin_2, 2);
            codegenReal2Mission_emxInit_real_T(&theta, 2);
            codegenReal2Mission_emxInit_real_T(&b_b, 1);
            codegenReal2Mission_emxInit_real_T(&b_tmp, 1);
            codegenReal2Mission_emxInit_real_T(&tmp, 2);
            codegenReal2Mission_emxInit_real_T(&Lat_0, 2);

            // MATLAB Function: '<S13>/InterpCircle' incorporates:
            //   Selector: '<S13>/SelectNorthEastRadius'

            for (wholeSecsFromMillis = 0; wholeSecsFromMillis <=
                    static_cast<int32_T>(b - 1); wholeSecsFromMillis++) {
                // '<S14>:1:6'
                Lat = codegenReal2Mission_DW.SelectNorthEastRadius
                    [static_cast<int32_T>(static_cast<int32_T>
                    (codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0] << 1)
                    + wholeSecsFromMillis)];

                // '<S14>:1:16'
                Lon = std::ceil(360.0 / (3.0 / Lat * 57.295779513082323));
                if (static_cast<boolean_T>(static_cast<int32_T>((Lon >= 0.0) ^ 1)))
                {
                    theta->size[0] = 1;
                    theta->size[1] = 0;
                } else {
                    i = static_cast<int32_T>(theta->size[0] * theta->size[1]);
                    theta->size[0] = 1;
                    theta->size[1] = static_cast<int32_T>(Lon);
                    codegenReal2Mission_emxEnsureCapacity_real_T(theta, i);
                    if (static_cast<int32_T>(Lon) >= 1) {
                        theta->data[static_cast<int32_T>(static_cast<int32_T>
                            (Lon) - 1)] = 6.2831853071795862;
                        if (theta->size[1] >= 2) {
                            theta->data[0] = 0.0;
                            if (theta->size[1] >= 3) {
                                Lon = 6.2831853071795862 / (static_cast<real_T>
                                    (theta->size[1]) - 1.0);
                                md2 = theta->size[1];
                                for (b_md2 = 0; b_md2 <= static_cast<int32_T>
                                        (md2 - 3); b_md2++) {
                                    theta->data[static_cast<int32_T>(b_md2 + 1)]
                                        = (static_cast<real_T>(b_md2) + 1.0) *
                                        Lon;
                                }
                            }
                        }
                    }
                }

                // '<S14>:1:17'
                i = b_tmp->size[0];
                b_tmp->size[0] = theta->size[1];
                codegenReal2Mission_emxEnsureCapacity_real_T(b_tmp, i);
                loop_ub = theta->size[1];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    b_tmp->data[i] = theta->data[i];
                }

                i = b_b->size[0];
                b_b->size[0] = b_tmp->size[0];
                codegenReal2Mission_emxEnsureCapacity_real_T(b_b, i);
                loop_ub = b_tmp->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    b_b->data[i] = b_tmp->data[i];
                }

                b_md2 = b_tmp->size[0];
                for (md2 = 0; md2 <= static_cast<int32_T>(b_md2 - 1); md2++) {
                    b_b->data[md2] = std::cos(b_b->data[md2]);
                }

                b_md2 = b_tmp->size[0];
                for (md2 = 0; md2 <= static_cast<int32_T>(b_md2 - 1); md2++) {
                    b_tmp->data[md2] = std::sin(b_tmp->data[md2]);
                }

                i = static_cast<int32_T>(Lat_0->size[0] * Lat_0->size[1]);
                Lat_0->size[0] = b_b->size[0];
                Lat_0->size[1] = 2;
                codegenReal2Mission_emxEnsureCapacity_real_T(Lat_0, i);
                loop_ub = b_b->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    Lat_0->data[i] = Lat * b_b->data[i];
                }

                loop_ub = b_tmp->size[0];
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    Lat_0->data[static_cast<int32_T>(i + b_b->size[0])] = Lat *
                        b_tmp->data[i];
                }

                tmp_0[0] =
                    codegenReal2Mission_DW.SelectNorthEastRadius[wholeSecsFromMillis];
                tmp_0[1] = codegenReal2Mission_DW.SelectNorthEastRadius[
                    static_cast<int32_T>(wholeSecsFromMillis +
                    codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0])];
                i = static_cast<int32_T>(varargin_2->size[0] * varargin_2->size
                    [1]);
                varargin_2->size[0] = Lat_0->size[0];
                varargin_2->size[1] = 2;
                codegenReal2Mission_emxEnsureCapacity_real_T(varargin_2, i);
                loop_ub = Lat_0->size[0];
                for (i = 0; i < 2; i++) {
                    for (b_md2 = 0; b_md2 <= static_cast<int32_T>(loop_ub - 1);
                            b_md2++) {
                        varargin_2->data[static_cast<int32_T>(b_md2 +
                            static_cast<int32_T>(varargin_2->size[0] * i))] =
                            Lat_0->data[static_cast<int32_T>(static_cast<int32_T>
                            (Lat_0->size[0] * i) + b_md2)] + tmp_0[i];
                    }
                }

                // '<S14>:1:11'
                if (codegenReal2Mission_DW.SFunction_DIMS2_i[0] != 0) {
                    b_n = codegenReal2Mission_DW.SFunction_DIMS2_i[0];
                } else {
                    b_n = 0;
                }

                if (varargin_2->size[0] != 0) {
                    md2 = varargin_2->size[0];
                } else {
                    md2 = 0;
                }

                i = static_cast<int32_T>(tmp->size[0] * tmp->size[1]);
                tmp->size[0] = static_cast<int32_T>(b_n + md2);
                tmp->size[1] = 2;
                codegenReal2Mission_emxEnsureCapacity_real_T(tmp, i);
                for (i = 0; i < 2; i++) {
                    for (b_md2 = 0; b_md2 <= static_cast<int32_T>(b_n - 1);
                            b_md2++) {
                        tmp->data[static_cast<int32_T>(b_md2 +
                            static_cast<int32_T>(tmp->size[0] * i))] =
                            codegenReal2Mission_DW.PointCloud
                            [static_cast<int32_T>(static_cast<int32_T>(b_n * i)
                            + b_md2)];
                    }
                }

                for (i = 0; i < 2; i++) {
                    for (b_md2 = 0; b_md2 <= static_cast<int32_T>(md2 - 1);
                            b_md2++) {
                        tmp->data[static_cast<int32_T>(static_cast<int32_T>
                            (b_md2 + b_n) + static_cast<int32_T>(tmp->size[0] *
                            i))] = varargin_2->data[static_cast<int32_T>(
                            static_cast<int32_T>(varargin_2->size[0] * i) +
                            b_md2)];
                    }
                }

                codegenReal2Mission_DW.SFunction_DIMS2_i[0] = tmp->size[0];
                codegenReal2Mission_DW.SFunction_DIMS2_i[1] = 2;
                loop_ub = static_cast<int32_T>(tmp->size[0] << 1);
                for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                    codegenReal2Mission_DW.PointCloud[i] = tmp->data[i];
                }
            }

            codegenReal2Mission_emxFree_real_T(&Lat_0);
            codegenReal2Mission_emxFree_real_T(&tmp);
            codegenReal2Mission_emxFree_real_T(&b_tmp);
            codegenReal2Mission_emxFree_real_T(&b_b);
            codegenReal2Mission_emxFree_real_T(&theta);
            codegenReal2Mission_emxFree_real_T(&varargin_2);
        }

        // End of Receive: '<S5>/Receive'
        // End of Outputs for SubSystem: '<S5>/GenPCD'
        // End of Outputs for SubSystem: '<Root>/MissionLogic'
        codegenReal2Mission_emxFree_char_T(&q);
        codegenReal2Mission_emxFree_char_T(&x);
        codegenReal2Mission_emxFree_char_T(&b_curKey);
        codegenReal2Mission_emxFree_char_T(&curLine);
        codegenReal2Mission_emxFree_char_T(&curVal);
        codegenReal2Mission_emxFree_char_T(&curKey);
        codegenReal2Mission_emxFree_char_T(&curSection);
        codegenReal2Mission_emxFree_char_T(&data);
        codegenReal2Mission_emxFree_char_T(&ret);

        // Outputs for Atomic SubSystem: '<Root>/MissionLogic'
        // Outputs for Atomic SubSystem: '<S2>/FeedbackCurrentMission'
        // Logic: '<S6>/OR'
        codegenReal2Mission_DW.OR = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(NichtAvoidDanger) | static_cast<int32_T>
            (rtb_Receive_o1_m)));

        // Receive: '<S6>/ReceiveThisMission'
        wholeSecsFromMillis = codegenReal2Mission_ReceiveThisMission_RecvData
            (&codegenReal2Mission_DW.ReceiveThisMission_o2);

        // BusCreator: '<S6>/CreateStatusBus' incorporates:
        //   Memory: '<S6>/MemoryFlightStatus'
        //   Memory: '<S6>/MemoryImmedStatus'

        rtb_CreateStatusBus.EngagedFlag = rtb_Memory_m;
        rtb_CreateStatusBus.FlightStatus =
            codegenReal2Mission_DW.MemoryFlightStatus_PreviousInput;
        rtb_CreateStatusBus.ImmedStatus =
            codegenReal2Mission_DW.MemoryImmedStatus_PreviousInput;
        rtb_CreateStatusBus.SequenceID =
            codegenReal2Mission_DW.ReceiveThisMission_o2.SequenceID;

        // Switch: '<S6>/Switch' incorporates:
        //   Constant: '<S41>/Constant'
        //   DataStoreRead: '<S6>/Data Store Read'
        //   DataTypeConversion: '<S6>/Data Type Conversion'
        //   Logic: '<S6>/AND'
        //   Logic: '<S6>/NOT'
        //   RelationalOperator: '<S41>/Compare'
        //   RelationalOperator: '<S6>/NotEqual'

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (static_cast<boolean_T>(static_cast<int32_T>
                   ((codegenReal2Mission_DW.ReceiveThisMission_o2.params.Param7
                     != 0.0F) ^ 1))) & (static_cast<int32_T>
                  (codegenReal2Mission_DW.ReceiveThisMission_o2.MissionMode) <
                  128)))) &
                (codegenReal2Mission_DW.ReceiveThisMission_o2.SequenceID !=
                 codegenReal2Mission_DW.CurrentFlightMission.SequenceID)))) {
            // BusCreator: '<S6>/CreateStatusBus' incorporates:
            //   Constant: '<S6>/WaitToStart'

            rtb_CreateStatusBus.MissionMode = MissionModes::WaitToStart;
        } else {
            // BusCreator: '<S6>/CreateStatusBus'
            rtb_CreateStatusBus.MissionMode =
                codegenReal2Mission_DW.CurrentFlightMission.MissionMode;
        }

        // End of Switch: '<S6>/Switch'

        // BusCreator: '<S6>/CreateStatusBus' incorporates:
        //   DataStoreRead: '<S6>/Data Store Read'

        rtb_CreateStatusBus.numUAV =
            codegenReal2Mission_DW.CurrentFlightMission.numUAV;
        rtb_CreateStatusBus.FormationPos =
            codegenReal2Mission_DW.CurrentFlightMission.FormationPos;

        // Send: '<S6>/Send'
        MissionFBSendData.SendData(&rtb_CreateStatusBus, sizeof(TaskStatus),
            &status_1);

        // Outputs for Enabled SubSystem: '<S6>/TriggerCurrentMisisonFeedback' incorporates:
        //   EnablePort: '<S42>/Enable'

        // Receive: '<S6>/ReceiveThisMission'
        if (wholeSecsFromMillis != 1) {
            // MATLAB Function: '<S42>/TimeConverter'
            // MATLAB Function 'MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/TimeConverter': '<S43>:1' 
            // '<S43>:1:3'
            Lon = codegenReal2Mission_DW.ReceiveThisMission_o2.StartTime *
                1000.0;
            codegenReal2Mission_getDateVec(Lon, &Lat, &Alt, &b_I, &D, &a__4,
                &rtb_Sum1_idx_0);
            codegenReal2Mission_getDateVec(Lon, &b_I, &Alt, &D, &a__4,
                &rtb_Sum1_idx_0, &da_im);
            codegenReal2Mission_getDateVec(Lon, &D, &a__4, &b_I, &rtb_Sum1_idx_0,
                &da_im, &a__17);
            codegenReal2Mission_getDateVec(Lon, &a__4, &rtb_Sum1_idx_0, &da_im,
                &D, &a__17, &a__23);
            codegenReal2Mission_getDateVec(Lon, &rtb_Sum1_idx_0, &da_im, &a__17,
                &a__23, &a__4, &a__29);
            codegenReal2Mission_getDateVec(Lon, &da_im, &a__17, &a__23, &a__29,
                &a__35, &rtb_Sum1_idx_0);
            codegenReal2Mission_getDateVec(Lon, &a__17, &a__23, &a__29, &a__35,
                &b_a__35, &da_im);
            codegenReal2Mission_getDateVec(Lon, &a__17, &a__23, &a__29, &a__35,
                &b_a__35, &b_x_0);

            // BusCreator: '<S42>/IndivCMD'
            rtb_IndivCMD.SequenceID =
                codegenReal2Mission_DW.ReceiveThisMission_o2.SequenceID;
            rtb_IndivCMD.MissionMode =
                codegenReal2Mission_DW.ReceiveThisMission_o2.MissionMode;
            rtb_IndivCMD.MissionLocation =
                codegenReal2Mission_DW.ReceiveThisMission_o2.MissionLocation;
            rtb_IndivCMD.params =
                codegenReal2Mission_DW.ReceiveThisMission_o2.params;
            rtb_IndivCMD.StartPosition =
                codegenReal2Mission_DW.ReceiveThisMission_o2.StartPosition;
            rtb_IndivCMD.numUAV =
                codegenReal2Mission_DW.ReceiveThisMission_o2.numUAV;
            rtb_IndivCMD.FormationPos =
                codegenReal2Mission_DW.ReceiveThisMission_o2.FormationPos;

            // MATLAB Function: '<S42>/TimeConverter'
            a__17 = std::round(Lat);
            if (a__17 < 2.147483648E+9) {
                if (a__17 >= -2.147483648E+9) {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.year = static_cast<int32_T>(a__17);
                } else {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.year = MIN_int32_T;
                }
            } else {
                // BusCreator: '<S42>/IndivCMD'
                rtb_IndivCMD.StartTime.year = MAX_int32_T;
            }

            a__17 = std::round(Alt);
            if (a__17 < 2.147483648E+9) {
                if (a__17 >= -2.147483648E+9) {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.month = static_cast<int32_T>(a__17);
                } else {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.month = MIN_int32_T;
                }
            } else {
                // BusCreator: '<S42>/IndivCMD'
                rtb_IndivCMD.StartTime.month = MAX_int32_T;
            }

            a__17 = std::round(b_I);
            if (a__17 < 2.147483648E+9) {
                if (a__17 >= -2.147483648E+9) {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.day = static_cast<int32_T>(a__17);
                } else {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.day = MIN_int32_T;
                }
            } else {
                // BusCreator: '<S42>/IndivCMD'
                rtb_IndivCMD.StartTime.day = MAX_int32_T;
            }

            a__17 = std::round(D);
            if (a__17 < 2.147483648E+9) {
                if (a__17 >= -2.147483648E+9) {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.hour = static_cast<int32_T>(a__17);
                } else {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.hour = MIN_int32_T;
                }
            } else {
                // BusCreator: '<S42>/IndivCMD'
                rtb_IndivCMD.StartTime.hour = MAX_int32_T;
            }

            a__17 = std::round(a__4);
            if (a__17 < 2.147483648E+9) {
                if (a__17 >= -2.147483648E+9) {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.minute = static_cast<int32_T>(a__17);
                } else {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.minute = MIN_int32_T;
                }
            } else {
                // BusCreator: '<S42>/IndivCMD'
                rtb_IndivCMD.StartTime.minute = MAX_int32_T;
            }

            a__17 = std::floor(rtb_Sum1_idx_0);
            if (a__17 < 2.147483648E+9) {
                if (a__17 >= -2.147483648E+9) {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.second = static_cast<int32_T>(a__17);
                } else {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.second = MIN_int32_T;
                }
            } else {
                // BusCreator: '<S42>/IndivCMD'
                rtb_IndivCMD.StartTime.second = MAX_int32_T;
            }

            a__17 = std::round((da_im - std::floor(b_x_0)) * 1000.0);
            if (a__17 < 2.147483648E+9) {
                if (a__17 >= -2.147483648E+9) {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.millisecond = static_cast<int32_T>
                        (a__17);
                } else {
                    // BusCreator: '<S42>/IndivCMD'
                    rtb_IndivCMD.StartTime.millisecond = MIN_int32_T;
                }
            } else {
                // BusCreator: '<S42>/IndivCMD'
                rtb_IndivCMD.StartTime.millisecond = MAX_int32_T;
            }

            // Send: '<S42>/Send'
            CurrentMissionSendData.SendData(&rtb_IndivCMD, sizeof
                (IndividualUAVCmd), &status_2);
        }

        // End of Outputs for SubSystem: '<S6>/TriggerCurrentMisisonFeedback'

        // DataTypeConversion: '<S6>/intFlightStatus'
        a__17 = std::floor(fid);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(a__17)) | static_cast<int32_T>(std::isinf(a__17))))) {
            a__17 = 0.0;
        } else {
            a__17 = std::fmod(a__17, 4.294967296E+9);
        }

        // Update for Memory: '<S6>/MemoryFlightStatus' incorporates:
        //   DataTypeConversion: '<S6>/intFlightStatus'

        codegenReal2Mission_DW.MemoryFlightStatus_PreviousInput = a__17 < 0.0 ?
            static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
            (-a__17))) : static_cast<int32_T>(static_cast<uint32_T>(a__17));

        // DataTypeConversion: '<S6>/intImmedStatus'
        a__17 = std::floor(codegenReal2Mission_DW.thisTaskStatus);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(a__17)) | static_cast<int32_T>(std::isinf(a__17))))) {
            a__17 = 0.0;
        } else {
            a__17 = std::fmod(a__17, 4.294967296E+9);
        }

        // Update for Memory: '<S6>/MemoryImmedStatus' incorporates:
        //   DataTypeConversion: '<S6>/intImmedStatus'

        codegenReal2Mission_DW.MemoryImmedStatus_PreviousInput = a__17 < 0.0 ?
            static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
            (-a__17))) : static_cast<int32_T>(static_cast<uint32_T>(a__17));

        // End of Outputs for SubSystem: '<S2>/FeedbackCurrentMission'
        // End of Outputs for SubSystem: '<Root>/MissionLogic'
    }

    // Outputs for Atomic SubSystem: '<Root>/MissionLogic'
    // DataStoreRead: '<S2>/Data Store Read'
    codegenReal2Mission_DW.DataStoreRead = codegenReal2Mission_DW.ParamADRC_e;

    // End of Outputs for SubSystem: '<Root>/MissionLogic'

    // RateTransition: '<Root>/RTLLA'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        rtw_pthread_mutex_lock(codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);
        fileid = static_cast<int8_T>(static_cast<int32_T>(static_cast<int32_T>
            (codegenReal2Mission_DW.RTLLA_LstBufWR) + 1));
        if (static_cast<int32_T>(fileid) == 3) {
            fileid = 0;
        }

        if (static_cast<int32_T>(fileid) == static_cast<int32_T>
                (codegenReal2Mission_DW.RTLLA_RDBuf)) {
            fileid = static_cast<int8_T>(static_cast<int32_T>
                (static_cast<int32_T>(fileid) + 1));
            if (static_cast<int32_T>(fileid) == 3) {
                fileid = 0;
            }
        }

        rtw_pthread_mutex_unlock(codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);
        i = static_cast<int32_T>(static_cast<int32_T>(fileid) * 3);
        codegenReal2Mission_DW.RTLLA_Buf[i] = codegenReal2Mission_DW.LLA0_c[0];
        codegenReal2Mission_DW.RTLLA_Buf[static_cast<int32_T>(i + 1)] =
            codegenReal2Mission_DW.LLA0_c[1];
        codegenReal2Mission_DW.RTLLA_Buf[static_cast<int32_T>(i + 2)] =
            codegenReal2Mission_DW.LLA0_c[2];
        codegenReal2Mission_DW.RTLLA_LstBufWR = fileid;

        // Outputs for Atomic SubSystem: '<Root>/TrackingControl'
        // Receive: '<S3>/ReceiveFlightMode'
        wholeSecsFromMillis = 1;
        FlightModeRecvData.RecvData(&codegenReal2Mission_DW.ReceiveFlightMode,
            sizeof(uint8_T), &wholeSecsFromMillis);

        // Receive: '<S3>/Receive'
        wholeSecsFromMillis = 1;
        VecSpdRecvData.RecvData(&codegenReal2Mission_DW.Receive_e, sizeof
                                (VectorSpeed), &wholeSecsFromMillis);

        // End of Outputs for SubSystem: '<Root>/TrackingControl'
    }

    // End of RateTransition: '<Root>/RTLLA'

    // Outputs for Atomic SubSystem: '<Root>/TrackingControl'
    // ModelReference generated from: '<S100>/Real2SimGuidance'
    Real2SimGuidance(&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
                     &codegenReal2Mission_DW.OR,
                     &codegenReal2Mission_DW.ReceiveFlightMode,
                     &codegenReal2Mission_DW.Receive_m,
                     &codegenReal2Mission_DW.ImmedMission_o3[0],
                     &codegenReal2Mission_DW.ImmedMission_o2,
                     &codegenReal2Mission_DW.ImmedMission_o4,
                     &codegenReal2Mission_DW.DivideThree,
                     &codegenReal2Mission_DW.DataStoreRead.hat_b,
                     &codegenReal2Mission_DW.DataStoreRead.omega_o,
                     &codegenReal2Mission_DW.DataStoreRead.omega_c,
                     &codegenReal2Mission_DW.DataStoreRead.P,
                     &codegenReal2Mission_DW.DataStoreRead.I,
                     &codegenReal2Mission_DW.DataStoreRead.D,
                     &codegenReal2Mission_DW.DataStoreRead.useADRC,
                     &codegenReal2Mission_DW.PointCloud[0],
                     &codegenReal2Mission_DW.SFunction_DIMS2_i[0],
                     &codegenReal2Mission_DW.SelectNorthEastRadius[0],
                     &codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0],
                     &codegenReal2Mission_DW.Receive_e.eastSpeed,
                     &codegenReal2Mission_DW.Receive_e.northSpeed,
                     &codegenReal2Mission_DW.Receive_e.skySpeed,
                     &codegenReal2Mission_DW.Real2SimGuidance_o1,
                     &codegenReal2Mission_DW.EngagedFlag_Log,
                     &codegenReal2Mission_DW.Real2SimGuidance_o3,
                     &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
                     &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Send: '<S3>/SendFCUCMD'
        FlightCMDSendData.SendData(&codegenReal2Mission_DW.Real2SimGuidance_o1,
            sizeof(FCUCMD), &status);

        // Send: '<S3>/SendLog'
        FlightLogSendData.SendData(&codegenReal2Mission_DW.Real2SimGuidance_o3,
            sizeof(FlightLogging), &status_0);
    }

    // End of Outputs for SubSystem: '<Root>/TrackingControl'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Update for Atomic SubSystem: '<Root>/MissionLogic'
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            // Update for Memory: '<S2>/Memory'
            codegenReal2Mission_DW.Memory_PreviousInput_l =
                codegenReal2Mission_DW.EngagedFlag_Log;
        }

        // End of Update for SubSystem: '<Root>/MissionLogic'

        // Update for Atomic SubSystem: '<Root>/TrackingControl'
        // Update for ModelReference generated from: '<S100>/Real2SimGuidance'
        Real2SimGuidance_Update
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
             &codegenReal2Mission_DW.OR, &codegenReal2Mission_DW.ImmedMission_o2,
             &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw));

        // End of Update for SubSystem: '<Root>/TrackingControl'
    }                                  // end MajorTimeStep

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        rt_ertODEUpdateContinuousStates(&(&codegenReal2Mission_M)->solverInfo);

        // Update absolute time
        // The "clockTick0" counts the number of times the code of this task has
        //  been executed. The absolute time is the multiplication of "clockTick0"
        //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
        //  overflow during the application lifespan selected.
        //  Timer of this task consists of two 32 bit unsigned integers.
        //  The two integers represent the low bits Timing.clockTick0 and the high bits
        //  Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.

        if (!(++(&codegenReal2Mission_M)->Timing.clockTick0)) {
            ++(&codegenReal2Mission_M)->Timing.clockTickH0;
        }

        (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetSolverStopTime
            (&(&codegenReal2Mission_M)->solverInfo);

        // Update absolute time
        // The "clockTick1" counts the number of times the code of this task has
        //  been executed. The resolution of this integer timer is 0.1, which is the step size
        //  of the task. Size of "clockTick1" ensures timer will not overflow during the
        //  application lifespan selected.
        //  Timer of this task consists of two 32 bit unsigned integers.
        //  The two integers represent the low bits Timing.clockTick1 and the high bits
        //  Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.

        (&codegenReal2Mission_M)->Timing.clockTick1++;
        if (!(&codegenReal2Mission_M)->Timing.clockTick1) {
            (&codegenReal2Mission_M)->Timing.clockTickH1++;
        }
    }                                  // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void codegenReal2MissionModelClass::codegenReal2Mission_derivatives()
{
    // Derivatives for Atomic SubSystem: '<Root>/TrackingControl'

    // Derivatives for ModelReference generated from: '<S100>/Real2SimGuidance'
    Real2SimGuidance_Deriv
        (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
         &(((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs)
           ->Real2SimGuidance_CSTATE));

    // End of Derivatives for SubSystem: '<Root>/TrackingControl'
}

// Model step function for TID2
void codegenReal2MissionModelClass::step2() // Sample time: [0.2s, 0.0s]
{
    real_T rtb_EnableA;
    real_T rtb_EnableB;
    real_T rtb_TmpRTBAtModelAInport3;
    int32_T status;
    boolean_T rtb_ReceiveMissionA_o1;
    boolean_T rtb_ReceiveMissionB_o1;

    // Outputs for Atomic SubSystem: '<Root>/MissionLogic'
    // Outputs for Atomic SubSystem: '<S2>/FlightMission'
    // RateTransition generated from: '<S7>/ModelA'
    codegenReal2Mission_DW.EnableA_RdBufIdx = static_cast<int8_T>
        (static_cast<int32_T>(codegenReal2Mission_DW.EnableA_RdBufIdx) == 0);
    rtb_EnableA =
        codegenReal2Mission_DW.EnableA_Buf[codegenReal2Mission_DW.EnableA_RdBufIdx];

    // RateTransition generated from: '<S7>/ModelB'
    codegenReal2Mission_DW.EnableB_RdBufIdx = static_cast<int8_T>(static_cast<
        int32_T>(codegenReal2Mission_DW.EnableB_RdBufIdx) == 0);
    rtb_EnableB =
        codegenReal2Mission_DW.EnableB_Buf[codegenReal2Mission_DW.EnableB_RdBufIdx];

    // RateTransition: '<S47>/Rate Transition'
    codegenReal2Mission_DW.RateTransition_RdBufIdx_c = static_cast<int8_T>(
        static_cast<int32_T>(codegenReal2Mission_DW.RateTransition_RdBufIdx_c) ==
        0);

    // RateTransition: '<S47>/MsgRT'
    codegenReal2Mission_DW.MsgRT_RdBufIdx = static_cast<int8_T>
        (static_cast<int32_T>(codegenReal2Mission_DW.MsgRT_RdBufIdx) == 0);

    // Send: '<S47>/Send' incorporates:
    //   RateTransition: '<S47>/MsgRT'
    //   RateTransition: '<S47>/Rate Transition'

    if (codegenReal2Mission_DW.RateTransition_Buf_c[codegenReal2Mission_DW.RateTransition_RdBufIdx_c])
    {
        codegenReal2Mission_ReceiveMissionA_SendData
            (&codegenReal2Mission_DW.MsgRT_Buf[static_cast<int32_T>
             (codegenReal2Mission_DW.MsgRT_RdBufIdx)]);
    }

    // End of Send: '<S47>/Send'

    // Receive: '<S7>/ReceiveMissionA'
    status = codegenReal2Mission_ReceiveMissionA_RecvData
        (&codegenReal2Mission_DW.ReceiveMissionA_o2);
    rtb_ReceiveMissionA_o1 = (status != 1);

    // RateTransition generated from: '<S7>/ModelA'
    codegenReal2Mission_DW.TmpRTBAtModelAInport3_RdBufIdx = static_cast<int8_T>(
        static_cast<int32_T>
        (codegenReal2Mission_DW.TmpRTBAtModelAInport3_RdBufIdx) == 0);
    rtb_TmpRTBAtModelAInport3 =
        codegenReal2Mission_DW.TmpRTBAtModelAInport3_Buf[codegenReal2Mission_DW.TmpRTBAtModelAInport3_RdBufIdx];

    // ModelReference: '<S7>/ModelA'
    FlightMissionIterator(&rtb_ReceiveMissionA_o1,
                          &codegenReal2Mission_DW.ReceiveMissionA_o2,
                          &rtb_TmpRTBAtModelAInport3, &rtb_EnableA,
                          &codegenReal2Mission_DW.ModelA_o1,
                          &codegenReal2Mission_DW.ModelA_o2,
                          &(codegenReal2Mission_DW.ModelA_InstanceData.rtdw),
                          &(codegenReal2Mission_DW.ModelA_InstanceData.rtzce));

    // RateTransition: '<S48>/Rate Transition'
    codegenReal2Mission_DW.RateTransition_RdBufIdx_o = static_cast<int8_T>(
        static_cast<int32_T>(codegenReal2Mission_DW.RateTransition_RdBufIdx_o) ==
        0);

    // RateTransition: '<S48>/MsgRT'
    codegenReal2Mission_DW.MsgRT_RdBufIdx_b = static_cast<int8_T>
        (static_cast<int32_T>(codegenReal2Mission_DW.MsgRT_RdBufIdx_b) == 0);

    // Send: '<S48>/Send' incorporates:
    //   RateTransition: '<S48>/MsgRT'
    //   RateTransition: '<S48>/Rate Transition'

    if (codegenReal2Mission_DW.RateTransition_Buf_l[codegenReal2Mission_DW.RateTransition_RdBufIdx_o])
    {
        codegenReal2Mission_ReceiveMissionB_SendData
            (&codegenReal2Mission_DW.MsgRT_Buf_a[static_cast<int32_T>
             (codegenReal2Mission_DW.MsgRT_RdBufIdx_b)]);
    }

    // End of Send: '<S48>/Send'

    // Receive: '<S7>/ReceiveMissionB'
    status = codegenReal2Mission_ReceiveMissionB_RecvData
        (&codegenReal2Mission_DW.ReceiveMissionB_o2);
    rtb_ReceiveMissionB_o1 = (status != 1);

    // RateTransition generated from: '<S7>/ModelB'
    codegenReal2Mission_DW.TmpRTBAtModelBInport3_RdBufIdx = static_cast<int8_T>(
        static_cast<int32_T>
        (codegenReal2Mission_DW.TmpRTBAtModelBInport3_RdBufIdx) == 0);
    rtb_EnableA =
        codegenReal2Mission_DW.TmpRTBAtModelBInport3_Buf[codegenReal2Mission_DW.TmpRTBAtModelBInport3_RdBufIdx];

    // ModelReference: '<S7>/ModelB'
    FlightMissionIterator(&rtb_ReceiveMissionB_o1,
                          &codegenReal2Mission_DW.ReceiveMissionB_o2,
                          &rtb_EnableA, &rtb_EnableB,
                          &codegenReal2Mission_DW.ModelB_o1,
                          &codegenReal2Mission_DW.ModelB_o2,
                          &(codegenReal2Mission_DW.ModelB_InstanceData.rtdw),
                          &(codegenReal2Mission_DW.ModelB_InstanceData.rtzce));

    // RateTransition: '<S7>/Rate Transition' incorporates:
    //   Logic: '<S7>/OR'

    codegenReal2Mission_DW.RateTransition_Buffer0 = static_cast<boolean_T>(
        static_cast<int32_T>(static_cast<int32_T>(rtb_ReceiveMissionA_o1) |
        static_cast<int32_T>(rtb_ReceiveMissionB_o1)));

    // RateTransition generated from: '<S7>/SwitchMissionUAVState'
    codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_WrBufIdx =
        static_cast<int8_T>(static_cast<int32_T>
                            (codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_WrBufIdx)
                            == 0);
    codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_Buf[static_cast<
        int32_T>
        (codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_WrBufIdx)] =
        codegenReal2Mission_DW.ModelA_o1;

    // RateTransition generated from: '<S7>/SwitchMissionUAVState'
    codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_WrBufIdx =
        static_cast<int8_T>(static_cast<int32_T>
                            (codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_WrBufIdx)
                            == 0);
    codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_Buf[static_cast<
        int32_T>
        (codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_WrBufIdx)] =
        codegenReal2Mission_DW.ModelB_o1;

    // RateTransition generated from: '<S7>/SwitchTaskStatus'
    codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_WrBufIdx =
        static_cast<int8_T>(static_cast<int32_T>
                            (codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_WrBufIdx)
                            == 0);
    codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_Buf
        [static_cast<int32_T>
        (codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_WrBufIdx)] =
        codegenReal2Mission_DW.ModelA_o2;

    // RateTransition generated from: '<S7>/SwitchTaskStatus'
    codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_WrBufIdx =
        static_cast<int8_T>(static_cast<int32_T>
                            (codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_WrBufIdx)
                            == 0);
    codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_Buf
        [static_cast<int32_T>
        (codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_WrBufIdx)] =
        codegenReal2Mission_DW.ModelB_o2;

    // End of Outputs for SubSystem: '<S2>/FlightMission'
    // End of Outputs for SubSystem: '<Root>/MissionLogic'
}

// Model step function for TID3
void codegenReal2MissionModelClass::step3() // Sample time: [1.0s, 0.0s]
{
    // Outputs for Atomic SubSystem: '<Root>/MissionLogic'
    // Outputs for Atomic SubSystem: '<S12>/VisualizeUAV'
    // RateTransition: '<S99>/Rate Transition'
    codegenReal2Mission_DW.RateTransition_RdBufIdx = static_cast<int8_T>(
        static_cast<int32_T>(codegenReal2Mission_DW.RateTransition_RdBufIdx) ==
        0);

    // End of Outputs for SubSystem: '<S12>/VisualizeUAV'
    // End of Outputs for SubSystem: '<Root>/MissionLogic'
}

// Output function
void codegenReal2MissionModelClass::codegenReal2Mission_PushNbrUAV() // Explicit Task: PushNbrUAV 
{
    int32_T i;
    int8_T wrBufIdx;

    // RateTransition: '<Root>/RTLLA'
    rtw_pthread_mutex_lock(codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);
    codegenReal2Mission_DW.RTLLA_RDBuf = codegenReal2Mission_DW.RTLLA_LstBufWR;
    rtw_pthread_mutex_unlock(codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);
    i = static_cast<int32_T>(static_cast<int32_T>
        (codegenReal2Mission_DW.RTLLA_RDBuf) * 3);

    // RateTransition: '<Root>/RTLLA'
    codegenReal2Mission_DW.RTLLA[0] = codegenReal2Mission_DW.RTLLA_Buf[i];
    codegenReal2Mission_DW.RTLLA[1] = codegenReal2Mission_DW.RTLLA_Buf[
        static_cast<int32_T>(i + 1)];
    codegenReal2Mission_DW.RTLLA[2] = codegenReal2Mission_DW.RTLLA_Buf[
        static_cast<int32_T>(i + 2)];

    // RootInportFunctionCallGenerator generated from: '<Root>/PushNbrUAV'
    // ModelReference generated from: '<Root>/DeSerOtherUAV'
    DeSerOtherUAVMDLOBJ2.step(&codegenReal2Mission_DW.RTLLA[0],
        &codegenReal2Mission_DW.DeSerOtherUAV_m[0]);

    // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PushNbrUAV' 

    // RateTransition: '<Root>/Rate Transition' incorporates:
    //   ModelReference generated from: '<Root>/DeSerOtherUAV'

    rtw_pthread_mutex_lock(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
    wrBufIdx = static_cast<int8_T>(static_cast<int32_T>(static_cast<int32_T>
        (codegenReal2Mission_DW.RateTransition_LstBufWR) + 1));
    if (static_cast<int32_T>(wrBufIdx) == 3) {
        wrBufIdx = 0;
    }

    if (static_cast<int32_T>(wrBufIdx) == static_cast<int32_T>
            (codegenReal2Mission_DW.RateTransition_RDBuf)) {
        wrBufIdx = static_cast<int8_T>(static_cast<int32_T>(static_cast<int32_T>
            (wrBufIdx) + 1));
        if (static_cast<int32_T>(wrBufIdx) == 3) {
            wrBufIdx = 0;
        }
    }

    rtw_pthread_mutex_unlock(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
    switch (wrBufIdx) {
      case 0:
        for (i = 0; i < 4096; i++) {
            codegenReal2Mission_DW.RateTransition_Buf0[i] =
                codegenReal2Mission_DW.DeSerOtherUAV_m[i];
        }
        break;

      case 1:
        for (i = 0; i < 4096; i++) {
            codegenReal2Mission_DW.RateTransition_Buf1[i] =
                codegenReal2Mission_DW.DeSerOtherUAV_m[i];
        }
        break;

      case 2:
        for (i = 0; i < 4096; i++) {
            codegenReal2Mission_DW.RateTransition_Buf2[i] =
                codegenReal2Mission_DW.DeSerOtherUAV_m[i];
        }
        break;
    }

    codegenReal2Mission_DW.RateTransition_LstBufWR = wrBufIdx;

    // End of RateTransition: '<Root>/Rate Transition'
}

// Model initialize function
void codegenReal2MissionModelClass::initialize()
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));

    {
        {
            // Setup solver object
            rtsiSetSimTimeStepPtr(&(&codegenReal2Mission_M)->solverInfo,
                                  &(&codegenReal2Mission_M)->Timing.simTimeStep);
            rtsiSetTPtr(&(&codegenReal2Mission_M)->solverInfo, &rtmGetTPtr
                        ((&codegenReal2Mission_M)));
            rtsiSetStepSizePtr(&(&codegenReal2Mission_M)->solverInfo,
                               &(&codegenReal2Mission_M)->Timing.stepSize0);
            rtsiSetdXPtr(&(&codegenReal2Mission_M)->solverInfo,
                         &(&codegenReal2Mission_M)->derivs);
            rtsiSetContStatesPtr(&(&codegenReal2Mission_M)->solverInfo, (real_T **)
                                 &(&codegenReal2Mission_M)->contStates);
            rtsiSetNumContStatesPtr(&(&codegenReal2Mission_M)->solverInfo,
                                    &(&codegenReal2Mission_M)
                                    ->Sizes.numContStates);
            rtsiSetNumPeriodicContStatesPtr(&(&codegenReal2Mission_M)
                ->solverInfo, &(&codegenReal2Mission_M)
                ->Sizes.numPeriodicContStates);
            rtsiSetPeriodicContStateIndicesPtr(&(&codegenReal2Mission_M)
                ->solverInfo, &(&codegenReal2Mission_M)
                ->periodicContStateIndices);
            rtsiSetPeriodicContStateRangesPtr(&(&codegenReal2Mission_M)
                ->solverInfo, &(&codegenReal2Mission_M)->periodicContStateRanges);
            rtsiSetErrorStatusPtr(&(&codegenReal2Mission_M)->solverInfo,
                                  (&rtmGetErrorStatus((&codegenReal2Mission_M))));
            rtsiSetRTModelPtr(&(&codegenReal2Mission_M)->solverInfo,
                              (&codegenReal2Mission_M));
        }

        rtsiSetSimTimeStep(&(&codegenReal2Mission_M)->solverInfo,
                           MAJOR_TIME_STEP);
        (&codegenReal2Mission_M)->intgData.y = (&codegenReal2Mission_M)->odeY;
        (&codegenReal2Mission_M)->intgData.f[0] = (&codegenReal2Mission_M)->
            odeF[0];
        (&codegenReal2Mission_M)->intgData.f[1] = (&codegenReal2Mission_M)->
            odeF[1];
        (&codegenReal2Mission_M)->intgData.f[2] = (&codegenReal2Mission_M)->
            odeF[2];
        (&codegenReal2Mission_M)->intgData.f[3] = (&codegenReal2Mission_M)->
            odeF[3];
        (&codegenReal2Mission_M)->contStates = ((X_codegenReal2Mission_T *)
            &codegenReal2Mission_X);
        rtsiSetSolverData(&(&codegenReal2Mission_M)->solverInfo, static_cast<
                          void *>(&(&codegenReal2Mission_M)->intgData));
        rtsiSetIsMinorTimeStepWithModeChange(&(&codegenReal2Mission_M)
            ->solverInfo, false);
        rtsiSetSolverName(&(&codegenReal2Mission_M)->solverInfo,"ode4");
        rtmSetTPtr((&codegenReal2Mission_M), &(&codegenReal2Mission_M)
                   ->Timing.tArray[0]);
        (&codegenReal2Mission_M)->Timing.stepSize0 = 0.1;
    }

    {
        static uint32_T *clockTickPtrs[5];
        static uint32_T *clockTickHPtrs[5];
        static real_T *taskTimePtrs[5];
        static uint32_T *taskCounterPtrs;
        static boolean_T *rateTransitionPtrs[(5 * 5)];
        (&codegenReal2Mission_M)->timingBridge.nTasks = 5;
        clockTickPtrs[0] = &((&codegenReal2Mission_M)->Timing.clockTick0);
        clockTickHPtrs[0] = &((&codegenReal2Mission_M)->Timing.clockTickH0);
        clockTickPtrs[1] = &((&codegenReal2Mission_M)->Timing.clockTick1);
        clockTickHPtrs[1] = &((&codegenReal2Mission_M)->Timing.clockTickH1);
        clockTickPtrs[2] = (nullptr);
        clockTickHPtrs[2] = (nullptr);
        clockTickPtrs[3] = (nullptr);
        clockTickHPtrs[3] = (nullptr);
        clockTickPtrs[4] = (nullptr);
        clockTickHPtrs[4] = (nullptr);
        (&codegenReal2Mission_M)->timingBridge.clockTick = clockTickPtrs;
        (&codegenReal2Mission_M)->timingBridge.clockTickH = clockTickHPtrs;
        taskCounterPtrs = &((&codegenReal2Mission_M)->Timing.TaskCounters.TID[0]);
        (&codegenReal2Mission_M)->timingBridge.taskCounter = taskCounterPtrs;
        rateTransitionPtrs[1*5 + 2] = &((&codegenReal2Mission_M)
            ->Timing.RateInteraction.b_TID1_2);
        rateTransitionPtrs[1*5 + 3] = &((&codegenReal2Mission_M)
            ->Timing.RateInteraction.b_TID1_3);
        (&codegenReal2Mission_M)->timingBridge.rateTransition =
            rateTransitionPtrs;
        taskTimePtrs[0] = &((&codegenReal2Mission_M)->Timing.t[0]);
        taskTimePtrs[1] = (nullptr);
        taskTimePtrs[2] = (nullptr);
        taskTimePtrs[3] = (nullptr);
        taskTimePtrs[4] = (nullptr);
        (&codegenReal2Mission_M)->timingBridge.taskTime = taskTimePtrs;
    }

    // Model Initialize function for ModelReference Block: '<S7>/ModelA'
    FlightMissionIterator_initialize(rtmGetErrorStatusPointer
        ((&codegenReal2Mission_M)),
        &(codegenReal2Mission_DW.ModelA_InstanceData.rtm),
        &(codegenReal2Mission_DW.ModelA_InstanceData.rtdw),
        &(codegenReal2Mission_DW.ModelA_InstanceData.rtzce));

    // Model Initialize function for ModelReference Block: '<S7>/ModelB'
    FlightMissionIterator_initialize(rtmGetErrorStatusPointer
        ((&codegenReal2Mission_M)),
        &(codegenReal2Mission_DW.ModelB_InstanceData.rtm),
        &(codegenReal2Mission_DW.ModelB_InstanceData.rtdw),
        &(codegenReal2Mission_DW.ModelB_InstanceData.rtzce));

    // Model Initialize function for ModelReference Block: '<Root>/DeSerOtherUAV' 

    // Set error status pointer for ModelReference Block: '<Root>/DeSerOtherUAV' 
    DeSerOtherUAVMDLOBJ2.setErrorStatusPointer(rtmGetErrorStatusPointer
        ((&codegenReal2Mission_M)));
    DeSerOtherUAVMDLOBJ2.initialize();

    // Model Initialize function for ModelReference Block: '<S8>/ImmedMission'
    ImmedMission_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                            &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S100>/Real2SimGuidance' 
    Real2SimGuidance_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
        rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
        &((&codegenReal2Mission_M)->solverInfo), &(&codegenReal2Mission_M)
        ->timingBridge, 0, 1,
        &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm));

    {
        FILE* a;

        // Start for RateTransition: '<Root>/Rate Transition'
        rtw_pthread_mutex_init
            (&codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);

        // Start for RateTransition: '<Root>/RTLLA'
        rtw_pthread_mutex_init(&codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);

        // SystemInitialize for Atomic SubSystem: '<Root>/GCSLLA'
        // SystemInitialize for MATLAB Function: '<S1>/ReadHomePoint'
        a = NULL;
        for (int32_T i{0}; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles_mq[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S1>/ReadHomePoint'
        // End of SystemInitialize for SubSystem: '<Root>/GCSLLA'

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // SystemInitialize for MATLAB Function: '<S2>/ReadParADRC'
        a = NULL;
        for (int32_T i{0}; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles_f[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S2>/ReadParADRC'

        // SystemInitialize for Atomic SubSystem: '<S12>/VisualizeUAV'
        // InitializeConditions for RateTransition: '<S99>/Rate Transition'
        codegenReal2Mission_DW.RateTransition_RdBufIdx = 1;

        // End of SystemInitialize for SubSystem: '<S12>/VisualizeUAV'

        // SystemInitialize for Enabled SubSystem: '<S5>/GenPCD'
        // Start for DataStoreMemory: '<S13>/Data Store Memory'
        for (int32_T i{0}; i < 256; i++) {
            codegenReal2Mission_DW.DangerList[i] = (rtNaN);
        }

        // End of Start for DataStoreMemory: '<S13>/Data Store Memory'

        // SystemInitialize for MATLAB Function: '<S13>/ReadHomePoint'
        a = NULL;
        for (int32_T i{0}; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles_m[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S13>/ReadHomePoint'
        // End of SystemInitialize for SubSystem: '<S5>/GenPCD'

        // SystemInitialize for Atomic SubSystem: '<S2>/FlightMission'
        // InitializeConditions for RateTransition generated from: '<S7>/ModelA' 
        codegenReal2Mission_DW.EnableA_RdBufIdx = 1;

        // InitializeConditions for RateTransition generated from: '<S7>/ModelB' 
        codegenReal2Mission_DW.EnableB_RdBufIdx = 1;

        // InitializeConditions for RateTransition: '<S47>/MsgRT'
        codegenReal2Mission_DW.MsgRT_RdBufIdx = 1;

        // InitializeConditions for RateTransition: '<S47>/Rate Transition'
        codegenReal2Mission_DW.RateTransition_RdBufIdx_c = 1;

        // InitializeConditions for RateTransition: '<S48>/MsgRT'
        codegenReal2Mission_DW.MsgRT_RdBufIdx_b = 1;

        // InitializeConditions for RateTransition: '<S48>/Rate Transition'
        codegenReal2Mission_DW.RateTransition_RdBufIdx_o = 1;

        // InitializeConditions for RateTransition generated from: '<S7>/SwitchMissionUAVState' 
        codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport1_RdBufIdx = 1;

        // InitializeConditions for RateTransition generated from: '<S7>/SwitchMissionUAVState' 
        codegenReal2Mission_DW.TmpRTBAtSwitchMissionUAVStateInport3_RdBufIdx = 1;

        // InitializeConditions for RateTransition generated from: '<S7>/SwitchTaskStatus' 
        codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport1_RdBufIdx = 1;

        // InitializeConditions for RateTransition generated from: '<S7>/SwitchTaskStatus' 
        codegenReal2Mission_DW.TmpRTBAtSwitchTaskStatusInport3_RdBufIdx = 1;

        // InitializeConditions for RateTransition generated from: '<S7>/ModelA' 
        codegenReal2Mission_DW.TmpRTBAtModelAInport3_RdBufIdx = 1;

        // InitializeConditions for RateTransition generated from: '<S7>/ModelB' 
        codegenReal2Mission_DW.TmpRTBAtModelBInport3_RdBufIdx = 1;

        // SystemInitialize for Atomic SubSystem: '<S7>/JumpDelay'
        // SystemInitialize for Atomic SubSystem: '<S45>/ComputDelay'
        // SystemInitialize for MATLAB Function: '<S52>/ReadPursuitShiftPercentage' 
        a = NULL;
        for (int32_T i{0}; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles_b[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S52>/ReadPursuitShiftPercentage' 
        // End of SystemInitialize for SubSystem: '<S45>/ComputDelay'
        // End of SystemInitialize for SubSystem: '<S7>/JumpDelay'

        // SystemInitialize for ModelReference: '<S7>/ModelA'
        FlightMissionIterator_Init(&codegenReal2Mission_DW.ModelA_o1,
            &(codegenReal2Mission_DW.ModelA_InstanceData.rtdw));

        // SystemInitialize for ModelReference: '<S7>/ModelB'
        FlightMissionIterator_Init(&codegenReal2Mission_DW.ModelB_o1,
            &(codegenReal2Mission_DW.ModelB_InstanceData.rtdw));

        // End of SystemInitialize for SubSystem: '<S2>/FlightMission'

        // SystemInitialize for ModelReference generated from: '<S8>/ImmedMission' 
        ImmedMission_Init(&codegenReal2Mission_DW.ImmedMission_o3[0],
                          &codegenReal2Mission_DW.ImmedMission_o4,
                          &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw),
                          &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtzce));

        // SystemInitialize for MATLAB Function: '<S9>/ReadHomePoint'
        a = NULL;
        for (int32_T i{0}; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S9>/ReadHomePoint'

        // SystemInitialize for Atomic SubSystem: '<S2>/PreProcessMissionCMD'
        // SystemInitialize for Atomic SubSystem: '<S10>/QueueCMD'
        // Start for Queue: '<S83>/Queue'
        codegenReal2Mission_initQueue(&codegenReal2Mission_DW.Queue_Queue,
            QueuePolicy_T::MSG_FIFO_QUEUE, 16,
            &codegenReal2Mission_DW.Queue_Msg[0]);

        // SystemInitialize for Enabled SubSystem: '<S83>/UplinkLog'
        // SystemInitialize for MATLAB Function: '<S94>/PrintOnboardLog'
        a = NULL;
        for (int32_T i{0}; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles_h[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S94>/PrintOnboardLog'
        // End of SystemInitialize for SubSystem: '<S83>/UplinkLog'
        // End of SystemInitialize for SubSystem: '<S10>/QueueCMD'
        // End of SystemInitialize for SubSystem: '<S2>/PreProcessMissionCMD'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'

        // Start for Receive: '<S91>/Receive'
        std::memset(&codegenReal2Mission_DW.Receive, 0, sizeof(IndividualUAVCmd));

        // SystemInitialize for Atomic SubSystem: '<Root>/TrackingControl'
        // SystemInitialize for ModelReference generated from: '<S100>/Real2SimGuidance' 
        Real2SimGuidance_Init
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
             &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));

        // End of SystemInitialize for SubSystem: '<Root>/TrackingControl'

        // SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/PushNbrUAV' 
        // SystemInitialize for ModelReference generated from: '<Root>/DeSerOtherUAV' 
        DeSerOtherUAVMDLOBJ2.init();

        // End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/PushNbrUAV' 
    }
}

// Model terminate function
void codegenReal2MissionModelClass::terminate()
{
    // Terminate for RateTransition: '<Root>/Rate Transition'
    rtw_pthread_mutex_destroy(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);

    // Terminate for RateTransition: '<Root>/RTLLA'
    rtw_pthread_mutex_destroy(codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);
}

// Constructor
codegenReal2MissionModelClass::codegenReal2MissionModelClass
    (SendData_IndividualUAVCmdT& CurrentMissionSendData_arg,SendData_FCUCMDT&
     FlightCMDSendData_arg,SendData_FlightLoggingT& FlightLogSendData_arg,
     RecvData_uint8_T& FlightModeRecvData_arg,RecvData_RealUAVStateBusT&
     FlightStateRecvData_arg,RecvData_IndividualUAVCmdT& MissionCMDRecvData_arg,
     SendData_TaskStatusT& MissionFBSendData_arg,RecvData_RealUAVStateBusT&
     NbrUAVstateRecvData_arg,RecvData_VectorSpeedT& VecSpdRecvData_arg) :
    codegenReal2Mission_DW(),
    codegenReal2Mission_X(),
    CurrentMissionSendData(CurrentMissionSendData_arg),
    FlightCMDSendData(FlightCMDSendData_arg),
    FlightLogSendData(FlightLogSendData_arg),
    FlightModeRecvData(FlightModeRecvData_arg),
    FlightStateRecvData(FlightStateRecvData_arg),
    MissionCMDRecvData(MissionCMDRecvData_arg),
    MissionFBSendData(MissionFBSendData_arg),
    NbrUAVstateRecvData(NbrUAVstateRecvData_arg),
    VecSpdRecvData(VecSpdRecvData_arg),
    DeSerOtherUAVMDLOBJ2(get_NbrUAVstateRecvData()),
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

RecvData_RealUAVStateBusT & codegenReal2MissionModelClass::
    get_NbrUAVstateRecvData()
{
    return NbrUAVstateRecvData;
}

//
// File trailer for generated code.
//
// [EOF]
//
