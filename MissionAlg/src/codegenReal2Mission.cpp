//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 4.332
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jul 14 15:07:38 2022
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
#include "codegenReal2Mission_types.h"
#include "RecvData_IndividualUAVCmdT.h"
#include "rtwtypes.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"
#include <stdio.h>
#include "rtw_linux.h"
#include <cstring>
#include <cmath>
#include "plus_WAUOGGgr.h"
#include "rt_modd_snf.h"
#include "rt_atan2d_snf.h"
#include "isPalindrome_KPAwztvD.h"
#include "validate_print_arguments_sA7pOmrf.h"
#include "validate_print_arguments_Ogsds6Vg.h"
#include "coder_posix_time.h"
#include "split_uvVAOGsE.h"
#include "floor_LKLalLcG.h"
#include <stddef.h>
#include <cstdlib>
#include "zero_crossing_types.h"
#include "div_s32.h"
#include "codegenReal2Mission_private.h"
#include "FlightMissionMode.h"
#include "MissionUAV.h"
#include "ImmedMission.h"
#include "Real2SimGuidance.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Named constants for Chart: '<S93>/TriggerStartSim'
    const uint8_T codegenReal2Mission_IN_Pending
{
    1U
};
const uint8_T codegenReal2Mission_IN_Running{ 2U };

// Named constants for Chart: '<S92>/MisisonCMDTemporalLogic'
const uint8_T codegenReal2Mission_IN_Sending{ 2U };

// Named constants for Chart: '<S92>/NewMission'
const uint8_T codegenReal2Mission_IN_Enter{ 1U };

const uint8_T codegenReal2Mission_IN_New{ 2U };

const uint8_T codegenReal2Mission_IN_Wait{ 3U };

const real_T codegenReal2Mission_RGND{ 0.0 };// real_T ground

// Exported block states
real_T AltitudeGCS;                    // Simulink.Signal object 'AltitudeGCS'
real_T LatitudeGCS;                    // Simulink.Signal object 'LatitudeGCS'
real_T LongitudeGCS;                   // Simulink.Signal object 'LongitudeGCS'
void* AltitudeGCS_m0;                  // synthesized block
void* LatitudeGCS_m0;                  // synthesized block
void* LongitudeGCS_m0;                 // synthesized block

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
    int_T nXc { 15 };

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

// Function for MATLAB Function: '<S123>/PrintOnboardLog'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata_i(void) const
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (codegenReal2Mission_DW.eml_openfiles_j[static_cast<int32_T>(
                static_cast<int32_T>(static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S123>/PrintOnboardLog'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen_o(const char_T *
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
            codegenReal2Mission_DW.eml_openfiles_j[static_cast<int32_T>(
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

// Function for MATLAB Function: '<S123>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_fileManager_f(real_T
    varargin_1, FILE* *f, boolean_T *a)
{
    int8_T fileid;
    fileid = static_cast<int8_T>(std::round(varargin_1));
    if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>(fileid)
           < 0) | (varargin_1 != static_cast<real_T>(fileid))))) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        *f = codegenReal2Mission_DW.eml_openfiles_j[static_cast<int32_T>(
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_string_string
    (MissionModes val, char_T obj_Value_data[], int32_T obj_Value_size[2])
{
    static const char_T ab[15]{ 'F', 'l', 'i', 'g', 'h', 't', 'M', 'i', 's', 's',
        'i', 'o', 'n', 'R', 'H' };

    static const char_T eb[13]{ 'C', 'u', 's', 't', 'o', 'm', 'F', 'r', 'm', 'n',
        'N', 'a', 'v' };

    static const char_T lb[13]{ 'S', 'h', 'i', 'f', 't', 'E', 'a', 'r', 't', 'h',
        'E', 'N', 'U' };

    static const char_T hb[12]{ 'F', 'r', 'm', 'n', 'W', 'a', 'y', 'P', 'o', 'i',
        'n', 't' };

    static const char_T mb[12]{ 'S', 'h', 'i', 'f', 't', 'B', 'o', 'd', 'y', 'X',
        'Y', 'Z' };

    static const char_T x[12]{ 'D', 'e', 't', 'a', 'i', 'l', 'e', 'd', 'I', 'n',
        's', 'p' };

    static const char_T db[11]{ 'C', 'i', 'r', 'c', 'D', 'i', 's', 'p', 'N', 'a',
        'v' };

    static const char_T ib[11]{ 'W', 'a', 'i', 't', 'T', 'o', 'S', 't', 'a', 'r',
        't' };

    static const char_T v[11]{ 'H', 'o', 'r', 'z', 'S', 'c', 'a', 'n', 'N', 'a',
        'v' };

    static const char_T y[11]{ 'A', 'v', 'o', 'i', 'd', 'D', 'a', 'n', 'g', 'e',
        'r' };

    static const char_T fb[10]{ 'F', 'r', 'm', 'n', 'R', 'u', 'n', 'W', 'a', 'y'
    };

    static const char_T w[9]{ 'R', 'u', 'n', 'W', 'a', 'y', 'N', 'a', 'v' };

    static const char_T bb[8]{ 'S', 'q', 'C', 'a', 'l', 'i', 'b', 'r' };

    static const char_T gb[8]{ 'P', 'r', 'o', 't', 'L', 'i', 'n', 'e' };

    static const char_T kb[8]{ 'T', 'u', 'n', 'e', 'A', 'D', 'R', 'C' };

    static const char_T cb[7]{ 'p', 'A', 't', 't', 'a', 'c', 'k' };

    static const char_T u[7]{ 'C', 'i', 'r', 'c', 'N', 'a', 'v' };

    static const MissionModes enumVals[18]{ MissionModes::CircNav, MissionModes::
        HorzScanNav, MissionModes::RunWayNav, MissionModes::DetailedInsp,
        MissionModes::AvoidDanger, MissionModes::FlightMissionRH, MissionModes::
        SqCalibr, MissionModes::pAttack, MissionModes::CircDispNav, MissionModes::
        CustomFrmnNav, MissionModes::FrmnRunWay, MissionModes::ProtLine,
        MissionModes::FrmnWayPoint, MissionModes::WaitToStart, MissionModes::
        None, MissionModes::TuneADRC, MissionModes::ShiftEarthENU, MissionModes::
        ShiftBodyXYZ };

    cell_wrap_1_codegenReal2Mission_T b_0[18];
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
    cell_wrap_1_codegenReal2Mission_T t;
    int32_T enumIdx;
    int32_T k;
    int32_T loop_ub;
    boolean_T exitg1;
    b.f1.size[0] = 1;
    b.f1.size[1] = 7;
    for (k = 0; k < 7; k++) {
        b.f1.data[k] = u[k];
    }

    c.f1.size[0] = 1;
    c.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        c.f1.data[k] = v[k];
    }

    d.f1.size[0] = 1;
    d.f1.size[1] = 9;
    for (k = 0; k < 9; k++) {
        d.f1.data[k] = w[k];
    }

    e.f1.size[0] = 1;
    e.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        e.f1.data[k] = x[k];
    }

    f.f1.size[0] = 1;
    f.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        f.f1.data[k] = y[k];
    }

    g.f1.size[0] = 1;
    g.f1.size[1] = 15;
    for (k = 0; k < 15; k++) {
        g.f1.data[k] = ab[k];
    }

    h.f1.size[0] = 1;
    h.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        h.f1.data[k] = bb[k];
    }

    i.f1.size[0] = 1;
    i.f1.size[1] = 7;
    for (k = 0; k < 7; k++) {
        i.f1.data[k] = cb[k];
    }

    j.f1.size[0] = 1;
    j.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        j.f1.data[k] = db[k];
    }

    l.f1.size[0] = 1;
    l.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        l.f1.data[k] = eb[k];
    }

    m.f1.size[0] = 1;
    m.f1.size[1] = 10;
    for (k = 0; k < 10; k++) {
        m.f1.data[k] = fb[k];
    }

    n.f1.size[0] = 1;
    n.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        n.f1.data[k] = gb[k];
    }

    o.f1.size[0] = 1;
    o.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        o.f1.data[k] = hb[k];
    }

    p.f1.size[0] = 1;
    p.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        p.f1.data[k] = ib[k];
    }

    q.f1.size[0] = 1;
    q.f1.size[1] = 4;
    q.f1.data[0] = 'N';
    q.f1.data[1] = 'o';
    q.f1.data[2] = 'n';
    q.f1.data[3] = 'e';
    r.f1.size[0] = 1;
    r.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        r.f1.data[k] = kb[k];
    }

    s.f1.size[0] = 1;
    s.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        s.f1.data[k] = lb[k];
    }

    t.f1.size[0] = 1;
    t.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        t.f1.data[k] = mb[k];
    }

    enumIdx = -1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
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
    b_0[17] = t;
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
    b_0[17] = t;
    loop_ub = static_cast<int32_T>(b_0[enumIdx].f1.size[1] - 1);
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
    b_0[17] = t;
    for (k = 0; k <= loop_ub; k++) {
        obj_Value_data[k] = b_0[enumIdx].f1.data[k];
    }
}

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_two_prod(real_T a)
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec(const creal_T
    dd, real_T *y, real_T *mo, real_T *d, real_T *h, real_T *m, real_T *s)
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
    t = floor_LKLalLcG(b_thi_0);
    b_thi = t.re + t.im;
    b_thi_0 = codegenReal2Mission_minus(dd, codegenReal2Mission_times(t));
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
    t = floor_LKLalLcG(b_thi_0);
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

// Function for MATLAB Function: '<S123>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_printIndivMissionCMD_f
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
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\n====== Display Mission Command ======\n");
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
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
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
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
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Mission Location: \n");
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLatitude:\t\t%f\n",
                IndivMissionCMD_MissionLocation_Lat);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLongitude:\t\t%f\n",
                IndivMissionCMD_MissionLocation_Lon);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tAltitude:\t\t%f\n",
                IndivMissionCMD_MissionLocation_Alt);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tHeading:\t\t%f\n",
                IndivMissionCMD_MissionLocation_degHDG);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Parameters: \n");
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam1:\t\t%f\n", IndivMissionCMD_params_Param1);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam2:\t\t%f\n", IndivMissionCMD_params_Param2);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam3:\t\t%f\n", IndivMissionCMD_params_Param3);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam4:\t\t%f\n", IndivMissionCMD_params_Param4);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam5:\t\t%f\n", IndivMissionCMD_params_Param5);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam6:\t\t%f\n", IndivMissionCMD_params_Param6);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam7:\t\t%f\n", IndivMissionCMD_params_Param7);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Start Position: \n");
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLatitude:\t\t%f\n",
                IndivMissionCMD_StartPosition.Lat);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLongitude:\t\t%f\n",
                IndivMissionCMD_StartPosition.Lon);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tAltitude:\t\t%f\n",
                IndivMissionCMD_StartPosition.Alt);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tHeading:\t\t%f\n",
                IndivMissionCMD_StartPosition.degHDG);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Number of UAVs:\t\t%d\n", IndivMissionCMD_numUAV);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Formation Position:\t%d\n",
                IndivMissionCMD_FormationPos);
        if (autoflush) {
            fflush(filestar);
        }
    }

    validate_print_arguments_sA7pOmrf(IndivMissionCMD_StartTime.year,
        IndivMissionCMD_StartTime.month, IndivMissionCMD_StartTime.day,
        IndivMissionCMD_StartTime.hour, IndivMissionCMD_StartTime.minute,
        IndivMissionCMD_StartTime.second, IndivMissionCMD_StartTime.millisecond,
        validatedHoleFilling);
    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
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
    codegenReal2Mission_getDateVec(TimeNow_data, &b_varargin_1, &a__1, &a__2,
        &a__3, &a__4, &a__5);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__2, &a__1, &a__3, &a__4,
        &a__5, &a__11);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__3, &a__4, &a__2, &a__5,
        &a__11, &a__17);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__4, &a__5, &a__11, &a__3,
        &a__17, &a__23);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__5, &a__11, &a__17, &a__23,
        &a__4, &a__29);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__11, &a__17, &a__23, &a__29,
        &a__35, &a__5);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__17, &a__23, &a__29, &a__35,
        &b_a__35, &a__11);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__17, &a__23, &a__29, &a__35,
        &b_a__35, &x);
    validate_print_arguments_Ogsds6Vg(b_varargin_1, a__1, a__2, a__3, a__4, std::
        floor(a__5), std::round((a__11 - std::floor(x)) * 1000.0),
        b_validatedHoleFilling);
    b_NULL = NULL;
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
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
    codegenReal2Mission_fileManager_f(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\n");
        if (autoflush) {
            fflush(filestar);
        }
    }
}

// Function for MATLAB Function: '<S123>/PrintOnboardLog'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose_l(real_T fid)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(std::round(fid));
    if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>(fileid)
           < 0) | (fid != static_cast<real_T>(fileid))))) {
        fileid = -1;
    }

    b_fileid = fileid;
    if (static_cast<int32_T>(fileid) < 0) {
        b_fileid = -1;
    }

    if (static_cast<int32_T>(b_fileid) >= 3) {
        filestar = codegenReal2Mission_DW.eml_openfiles_j[static_cast<int32_T>(
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
            codegenReal2Mission_DW.eml_openfiles_j[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = NULL;
            codegenReal2Mission_DW.eml_autoflush[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = true;
        }
    }

    return st;
}

IndividualUAVCmd *codegenReal2MissionModelClass::
    codegenReal2Mission_allocMemPool(MemPool_IndividualUAVCmd *memPool, int32_T
    width)
{
    IndividualUAVCmd *dataPtr;

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    if (memPool->fNumFree > 0) {
        memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree - 1);
        dataPtr = memPool->fFreeList[memPool->fNumFree];
    } else if (memPool->fNumUsed < memPool->fSize) {
        dataPtr = &memPool->fMemArray[memPool->fNumUsed];
        memPool->fNumUsed = static_cast<int32_T>(memPool->fNumUsed + width);
    } else {
        dataPtr = nullptr;
    }

    // End of DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    return dataPtr;
}

Msg_IndividualUAVCmd codegenReal2MissionModelClass::
    codegenReal2Mission_createMsg_p(const IndividualUAVCmd *data)
{
    Msg_IndividualUAVCmd msg;

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    msg.fData = codegenReal2Mission_allocMemPool
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_IndividualUAVCmd, 1);
    if (msg.fData != nullptr) {
        *msg.fData = *data;
    }

    // End of DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    return msg;
}

void codegenReal2MissionModelClass::codegenReal2Mission_freeMemPool
    (MemPool_IndividualUAVCmd *memPool, IndividualUAVCmd *dataPtr)
{
    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    memPool->fFreeList[memPool->fNumFree] = dataPtr;
    memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree + 1);
}

void codegenReal2MissionModelClass::codegenReal2Mission_destroyMsg_m
    (Msg_IndividualUAVCmd *msg)
{
    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    codegenReal2Mission_freeMemPool
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_IndividualUAVCmd, msg->fData);
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push_i
    (Queue_IndividualUAVCmd *q, Msg_IndividualUAVCmd *element)
{
    boolean_T isPush;

    // Queue: '<S110>/Queue'
    q->fTail = static_cast<int32_T>(q->fTail + 1) % q->fCapacity;
    if (q->fTail == q->fHead) {
        codegenReal2Mission_destroyMsg_m(&q->fArray[q->fHead]);
        q->fHead = static_cast<int32_T>(q->fHead + 1) % q->fCapacity;
    } else if (q->fHead == -1) {
        q->fHead = q->fTail;
    }

    q->fArray[q->fTail] = *element;
    isPush = true;

    // End of Queue: '<S110>/Queue'
    return isPush;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Queue_SendData(const
    IndividualUAVCmd *data)
{
    Msg_IndividualUAVCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState' incorporates:
    //   Send: '<S110>/Send'

    msg = codegenReal2Mission_createMsg_p(data);

    // Queue: '<S110>/Queue' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_push_i(&codegenReal2Mission_DW.Queue_Queue, &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg_m(&msg);
    }

    // End of Queue: '<S110>/Queue'
    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop_c
    (Queue_IndividualUAVCmd *q, Msg_IndividualUAVCmd *elementOut)
{
    boolean_T isPop;

    // Queue: '<S110>/Queue'
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

    // End of Queue: '<S110>/Queue'
    return isPop;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Queue_RecvData
    (IndividualUAVCmd *data)
{
    Msg_IndividualUAVCmd msg;
    int32_T status{ 1 };

    // Queue: '<S110>/Queue' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    //   Receive: '<S120>/Receive'

    if (codegenReal2Mission_pop_c(&codegenReal2Mission_DW.Queue_Queue, &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg_m(&msg);
    }

    // End of Queue: '<S110>/Queue'
    return status;
}

DangerInfo *codegenReal2MissionModelClass::codegenReal2Mission_allocMemPool_n
    (MemPool_DangerInfo *memPool, int32_T width)
{
    DangerInfo *dataPtr;

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    if (memPool->fNumFree > 0) {
        memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree - 1);
        dataPtr = memPool->fFreeList[memPool->fNumFree];
    } else if (memPool->fNumUsed < memPool->fSize) {
        dataPtr = &memPool->fMemArray[memPool->fNumUsed];
        memPool->fNumUsed = static_cast<int32_T>(memPool->fNumUsed + width);
    } else {
        dataPtr = nullptr;
    }

    // End of DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    return dataPtr;
}

Msg_DangerInfo codegenReal2MissionModelClass::codegenReal2Mission_createMsg_fl(
    const DangerInfo *data)
{
    Msg_DangerInfo msg;

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    msg.fData = codegenReal2Mission_allocMemPool_n
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_DangerInfo, 1);
    if (msg.fData != nullptr) {
        *msg.fData = *data;
    }

    // End of DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    return msg;
}

void codegenReal2MissionModelClass::codegenReal2Mission_freeMemPool_j
    (MemPool_DangerInfo *memPool, DangerInfo *dataPtr)
{
    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    memPool->fFreeList[memPool->fNumFree] = dataPtr;
    memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree + 1);
}

void codegenReal2MissionModelClass::codegenReal2Mission_destroyMsg_i
    (Msg_DangerInfo *msg)
{
    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    codegenReal2Mission_freeMemPool_j
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_DangerInfo, msg->fData);
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push_j
    (Buffer_DangerInfo *q, Msg_DangerInfo *element)
{
    boolean_T isPush;

    // Queue generated from: '<S3>/DangerLidarScanPoints'
    if (q->fOccupied) {
        codegenReal2Mission_destroyMsg_i(&q->fMsg);
    }

    q->fMsg = *element;
    q->fOccupied = true;
    isPush = true;

    // End of Queue generated from: '<S3>/DangerLidarScanPoints'
    return isPush;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_SendData(
    const DangerInfo *data)
{
    Msg_DangerInfo msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState' incorporates:
    //   Send: '<S110>/SendDanger'

    msg = codegenReal2Mission_createMsg_fl(data);

    // Queue generated from: '<S3>/DangerLidarScanPoints' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_push_j
            (&codegenReal2Mission_DW.Queue_InsertedFor_DangerLidarScanPoints_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg_i(&msg);
    }

    // End of Queue generated from: '<S3>/DangerLidarScanPoints'
    return status;
}

// Function for MATLAB Function: '<S112>/CommandCheck'
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

// Function for MATLAB Function: '<S112>/CommandCheck'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isequaln_n
    (MissionModes varargin_1, MissionModes varargin_2)
{
    boolean_T p;
    p = false;
    if (static_cast<int32_T>(varargin_1) == static_cast<int32_T>(varargin_2)) {
        p = true;
    }

    return p;
}

// Function for MATLAB Function: '<S112>/CommandCheck'
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
                                 & static_cast<int32_T>
                                 (codegenReal2Mission_isequaln_n
                                  (varargin_1_MissionMode,
                                   varargin_2_MissionMode))));
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

// Function for MATLAB Function: '<S112>/CommandCheck'
MissionModes codegenReal2MissionModelClass::
    codegenReal2Mission_convert_to_enum_MissionModes(int32_T input)
{
    MissionModes output;

    // Initialize output value to default value for MissionModes (None)
    output = MissionModes::None;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
              static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                 static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                   (static_cast<boolean_T>(static_cast<int32_T>
                     (static_cast<int32_T>(static_cast<boolean_T>
                       (static_cast<int32_T>(static_cast<int32_T>
                         (static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((input >= 0) & (input <= 3)))) | (input == 11)))) | (input == 22))))
                         | (input == 33)))) | (input == 44)))) | (input == 55))))
                | static_cast<int32_T>(static_cast<boolean_T>
                 (static_cast<int32_T>((input >= 128) & (input <= 130))))))) |
             static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
               ((input >= 132) & (input <= 133))))))) | static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>((input >= 252) & (input <=
              255))))))) {
        // Set output value to input value if it is a member of MissionModes
        output = static_cast<MissionModes>(input);
    }

    return output;
}

// Function for MATLAB Function: '<S112>/CommandCheck'
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
    da = split_uvVAOGsE(c.re);
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

// Function for MATLAB Function: '<S112>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_days2ymd(real_T days,
    real_T *y, real_T *m, real_T *d)
{
    real_T g;
    if (static_cast<boolean_T>(static_cast<int32_T>(((days + 719529.0) - 61.0 >=
           0.0) & ((days + 719529.0) - 61.0 <= 2.147483647E+9)))) {
        int32_T ia_quot;
        int32_T ib_rem;
        int32_T ic_quot;
        int32_T ic_rem;
        int32_T idn;
        int32_T ig_rem;
        g = std::round((days + 719529.0) - 61.0);
        if (g < 2.147483648E+9) {
            if (g >= -2.147483648E+9) {
                idn = static_cast<int32_T>(g);
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
        g = static_cast<real_T>(idn);
        *d = ((static_cast<real_T>(ig_rem) - std::trunc((static_cast<real_T>(idn)
                 + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    } else {
        real_T a;
        real_T c;
        real_T dc;
        real_T dg;
        g = std::floor(((days + 719529.0) - 61.0) / 146097.0);
        dg = ((days + 719529.0) - 61.0) - g * 146097.0;
        c = std::floor(dg / 36524.0);
        if (c > 3.0) {
            c = 3.0;
        }

        dc = dg - c * 36524.0;
        dg = std::floor(dc / 1461.0);
        dc -= dg * 1461.0;
        a = std::floor(dc / 365.0);
        if (a > 3.0) {
            a = 3.0;
        }

        dc -= a * 365.0;
        *y = ((g * 400.0 + c * 100.0) + dg * 4.0) + a;
        g = std::floor((dc * 5.0 + 308.0) / 153.0) - 2.0;
        *d = ((dc - std::floor((g + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    }

    if (g > 9.0) {
        (*y)++;
        *m = (g + 2.0) - 11.0;
    } else {
        *m = (g + 2.0) + 1.0;
    }
}

// Function for MATLAB Function: '<S112>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_secs2hms(real_T secs,
    real_T *h, real_T *m, real_T *s)
{
    if (static_cast<boolean_T>(static_cast<int32_T>((secs >= 0.0) & (secs <=
            2.147483647E+9)))) {
        int32_T ih_rem;
        int32_T isecs;
        isecs = static_cast<int32_T>(std::round(secs));
        ih_rem = static_cast<int32_T>(isecs - static_cast<int32_T>(3600 *
            div_s32(isecs, 3600)));
        *h = std::trunc(static_cast<real_T>(isecs) / 3600.0);
        *m = std::trunc(static_cast<real_T>(ih_rem) / 60.0);
        *s = static_cast<real_T>(static_cast<int32_T>(ih_rem -
            static_cast<int32_T>(60 * div_s32(ih_rem, 60))));
    } else {
        *h = std::floor(secs / 3600.0);
        *m = std::floor((secs - 3600.0 * *h) / 60.0);
        *s = secs - 60.0 * *m;
    }
}

// Function for MATLAB Function: '<S112>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_o(real_T dd,
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
    r = floor_LKLalLcG(r);
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
    t = floor_LKLalLcG(c_s);
    c = codegenReal2Mission_minus(c_s, t);
    codegenReal2Mission_days2ymd(r.re + r.im, y, mo, d);
    codegenReal2Mission_secs2hms(t.re + t.im, h, m, &thi);
    *s = (c.re + c.im) + thi;
    if (*s == 60.0) {
        *s = 59.999999999999993;
    }
}

// Function for MATLAB Function: '<S112>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_oe(const
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
    c_s = floor_LKLalLcG(B);
    t = codegenReal2Mission_divide(codegenReal2Mission_minus(dd,
        codegenReal2Mission_times(c_s)));
    B = floor_LKLalLcG(t);
    c = codegenReal2Mission_minus(t, B);
    codegenReal2Mission_days2ymd(c_s.re + c_s.im, y, mo, d);
    codegenReal2Mission_secs2hms(B.re + B.im, h, m, &ahi);
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

missionCmd *codegenReal2MissionModelClass::codegenReal2Mission_allocMemPool_c
    (MemPool_missionCmd *memPool, int32_T width)
{
    missionCmd *dataPtr;

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    if (memPool->fNumFree > 0) {
        memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree - 1);
        dataPtr = memPool->fFreeList[memPool->fNumFree];
    } else if (memPool->fNumUsed < memPool->fSize) {
        dataPtr = &memPool->fMemArray[memPool->fNumUsed];
        memPool->fNumUsed = static_cast<int32_T>(memPool->fNumUsed + width);
    } else {
        dataPtr = nullptr;
    }

    // End of DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    return dataPtr;
}

Msg_missionCmd codegenReal2MissionModelClass::codegenReal2Mission_createMsg_f(
    const missionCmd *data)
{
    Msg_missionCmd msg;

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    msg.fData = codegenReal2Mission_allocMemPool_c
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd, 1);
    if (msg.fData != nullptr) {
        *msg.fData = *data;
    }

    // End of DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    return msg;
}

void codegenReal2MissionModelClass::codegenReal2Mission_freeMemPool_h
    (MemPool_missionCmd *memPool, missionCmd *dataPtr)
{
    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    memPool->fFreeList[memPool->fNumFree] = dataPtr;
    memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree + 1);
}

void codegenReal2MissionModelClass::codegenReal2Mission_destroyMsg_g
    (Msg_missionCmd *msg)
{
    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    codegenReal2Mission_freeMemPool_h
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd, msg->fData);
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push_ix
    (Buffer_missionCmd *q, Msg_missionCmd *element)
{
    boolean_T isPush;

    // Queue generated from: '<S3>/RcvNextMission'
    if (q->fOccupied) {
        codegenReal2Mission_destroyMsg_g(&q->fMsg);
    }

    q->fMsg = *element;
    q->fOccupied = true;
    isPush = true;

    // End of Queue generated from: '<S3>/RcvNextMission'
    return isPush;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState' incorporates:
    //   Send: '<S112>/PushCMD'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S3>/RcvNextMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_push_ix
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg_g(&msg);
    }

    // End of Queue generated from: '<S3>/RcvNextMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_MessageMerge_In1_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState' incorporates:
    //   Send: '<S101>/Send'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S3>/FeedbackCurrentMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_push_ix
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_5_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg_g(&msg);
    }

    // End of Queue generated from: '<S3>/FeedbackCurrentMission'
    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_SendData(
    const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState' incorporates:
    //   Send: '<S109>/SndImmedCMD'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S3>/RcvImmedCMD' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_push_ix
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg_g(&msg);
    }

    // End of Queue generated from: '<S3>/RcvImmedCMD'
    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop_h
    (Buffer_missionCmd *q, Msg_missionCmd *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<S3>/RcvNextMission'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<S3>/RcvNextMission'
    return isPop;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S3>/RcvNextMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg_g(&msg);
    }

    // End of Queue generated from: '<S3>/RcvNextMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState' incorporates:
    //   Send: '<S97>/SendMission'

    msg = codegenReal2Mission_createMsg_f(data);

    // Queue generated from: '<S92>/FlightMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_push_ix
            (&codegenReal2Mission_DW.Queue_InsertedFor_FlightMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg_g(&msg);
    }

    // End of Queue generated from: '<S92>/FlightMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveCurrentMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S92>/FlightMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    //   Receive: '<S93>/ReceiveCurrentMission'

    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_FlightMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg_g(&msg);
    }

    // End of Queue generated from: '<S92>/FlightMission'
    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_RecvData
    (missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S3>/RcvImmedCMD' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg_g(&msg);
    }

    // End of Queue generated from: '<S3>/RcvImmedCMD'
    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop_j
    (Buffer_DangerInfo *q, Msg_DangerInfo *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<S3>/DangerLidarScanPoints'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<S3>/DangerLidarScanPoints'
    return isPop;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_h_RecvData
    (DangerInfo *data)
{
    Msg_DangerInfo msg;
    int32_T status{ 1 };

    // Queue generated from: '<S3>/DangerLidarScanPoints' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_pop_j
            (&codegenReal2Mission_DW.Queue_InsertedFor_DangerLidarScanPoints_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg_i(&msg);
    }

    // End of Queue generated from: '<S3>/DangerLidarScanPoints'
    return status;
}

// Function for MATLAB Function: '<S61>/getDangerList'
void codegenReal2MissionModelClass::codegenReal2Mission_int2str(real_T xin,
    char_T s_data[], int32_T s_size[2])
{
    char_T st[311];
    if (xin == 0.0) {
        s_size[0] = 1;
        s_size[1] = 1;
        s_data[0] = '0';
    } else if (std::isinf(xin)) {
        s_size[0] = 1;
        s_size[1] = 3;
        s_data[0] = 'I';
        s_data[1] = 'n';
        s_data[2] = 'f';
    } else if (std::isnan(xin)) {
        s_size[0] = 1;
        s_size[1] = 3;
        s_data[0] = 'N';
        s_data[1] = 'a';
        s_data[2] = 'N';
    } else {
        int32_T resCount;
        resCount = sprintf(&st[0], "%.0f", xin);
        s_size[0] = 1;
        s_size[1] = resCount;
        for (int32_T b_k{0}; b_k <= static_cast<int32_T>(resCount - 1); b_k =
                static_cast<int32_T>(b_k + 1)) {
            s_data[b_k] = st[b_k];
        }
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

// Function for MATLAB Function: '<S61>/getDangerList'
void codegenReal2MissionModelClass::codegenReal2Mission_flipud
    (emxArray_real_T_codegenReal2Mission_T *x)
{
    real_T xtmp;
    int32_T m;
    int32_T md2;
    m = x->size[0];
    md2 = static_cast<int32_T>(x->size[0] >> 1);
    for (int32_T i{0}; i <= static_cast<int32_T>(md2 - 1); i =
            static_cast<int32_T>(i + 1)) {
        xtmp = x->data[i];
        x->data[i] = x->data[static_cast<int32_T>(static_cast<int32_T>(m - i) -
            1)];
        x->data[static_cast<int32_T>(static_cast<int32_T>(m - i) - 1)] = xtmp;
    }

    for (int32_T i{0}; i <= static_cast<int32_T>(md2 - 1); i =
            static_cast<int32_T>(i + 1)) {
        xtmp = x->data[static_cast<int32_T>(i + x->size[0])];
        x->data[static_cast<int32_T>(i + x->size[0])] = x->data
            [static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>(m -
            i) + x->size[0]) - 1)];
        x->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>(m
            - i) + x->size[0]) - 1)] = xtmp;
    }

    for (int32_T i{0}; i <= static_cast<int32_T>(md2 - 1); i =
            static_cast<int32_T>(i + 1)) {
        xtmp = x->data[static_cast<int32_T>(static_cast<int32_T>(x->size[0] << 1)
            + i)];
        x->data[static_cast<int32_T>(i + static_cast<int32_T>(x->size[0] << 1))]
            = x->data[static_cast<int32_T>(static_cast<int32_T>
            (static_cast<int32_T>(m - i) + static_cast<int32_T>(x->size[0] << 1))
            - 1)];
        x->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>(m
            - i) + static_cast<int32_T>(x->size[0] << 1)) - 1)] = xtmp;
    }

    for (int32_T i{0}; i <= static_cast<int32_T>(md2 - 1); i =
            static_cast<int32_T>(i + 1)) {
        xtmp = x->data[static_cast<int32_T>(static_cast<int32_T>(x->size[0] * 3)
            + i)];
        x->data[static_cast<int32_T>(i + static_cast<int32_T>(x->size[0] * 3))] =
            x->data[static_cast<int32_T>(static_cast<int32_T>
            (static_cast<int32_T>(m - i) + static_cast<int32_T>(x->size[0] * 3))
            - 1)];
        x->data[static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>(m
            - i) + static_cast<int32_T>(x->size[0] * 3)) - 1)] = xtmp;
    }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_int32_T
    (emxArray_int32_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
    emxArray_int32_T_codegenReal2Mission_T *emxArray;
    *pEmxArray = static_cast<emxArray_int32_T_codegenReal2Mission_T *>(std::
        malloc(sizeof(emxArray_int32_T_codegenReal2Mission_T)));
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

void codegenReal2MissionModelClass::
    codegenReal2Mission_emxEnsureCapacity_int32_T
    (emxArray_int32_T_codegenReal2Mission_T *emxArray, int32_T oldNumel)
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

void codegenReal2MissionModelClass::codegenReal2Mission_emxFree_int32_T
    (emxArray_int32_T_codegenReal2Mission_T **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_int32_T_codegenReal2Mission_T *>
            (nullptr)) {
        if (((*pEmxArray)->data != static_cast<int32_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_int32_T_codegenReal2Mission_T *>
            (nullptr);
    }
}

// Function for MATLAB Function: '<S61>/getDangerList'
void codegenReal2MissionModelClass::codegenReal2Mission_sortIdx(const
    emxArray_real_T_codegenReal2Mission_T *x,
    emxArray_int32_T_codegenReal2Mission_T *idx)
{
    emxArray_int32_T_codegenReal2Mission_T *iwork;
    int32_T i;
    int32_T i_0;
    int32_T n;
    n = static_cast<int32_T>(x->size[0] + 1);
    i_0 = idx->size[0];
    idx->size[0] = x->size[0];
    codegenReal2Mission_emxEnsureCapacity_int32_T(idx, i_0);
    i = x->size[0];
    for (i_0 = 0; i_0 <= static_cast<int32_T>(i - 1); i_0++) {
        idx->data[i_0] = 0;
    }

    if (x->size[0] != 0) {
        codegenReal2Mission_emxInit_int32_T(&iwork, 1);
        i_0 = iwork->size[0];
        iwork->size[0] = x->size[0];
        codegenReal2Mission_emxEnsureCapacity_int32_T(iwork, i_0);
        for (i = 1; i <= static_cast<int32_T>(n - 2); i = static_cast<int32_T>(i
              + 2)) {
            if (static_cast<boolean_T>(static_cast<int32_T>((x->data[
                    static_cast<int32_T>(i - 1)] <= x->data[i]) |
                    static_cast<int32_T>(std::isnan(x->data[i]))))) {
                idx->data[static_cast<int32_T>(i - 1)] = i;
                idx->data[i] = static_cast<int32_T>(i + 1);
            } else {
                idx->data[static_cast<int32_T>(i - 1)] = static_cast<int32_T>(i
                    + 1);
                idx->data[i] = i;
            }
        }

        if (static_cast<uint32_T>(static_cast<uint32_T>(x->size[0]) & 1U) != 0U)
        {
            idx->data[static_cast<int32_T>(x->size[0] - 1)] = x->size[0];
        }

        i = 2;
        while (i < static_cast<int32_T>(n - 1)) {
            int32_T i2;
            int32_T j;
            int32_T pEnd;
            i2 = static_cast<int32_T>(i << 1);
            j = 1;
            pEnd = static_cast<int32_T>(i + 1);
            while (pEnd < n) {
                int32_T k;
                int32_T kEnd;
                int32_T p;
                int32_T q;
                int32_T qEnd;
                p = j;
                q = static_cast<int32_T>(pEnd - 1);
                qEnd = static_cast<int32_T>(j + i2);
                if (qEnd > n) {
                    qEnd = n;
                }

                k = 0;
                kEnd = static_cast<int32_T>(qEnd - j);
                while (static_cast<int32_T>(k + 1) <= kEnd) {
                    real_T tmp;
                    tmp = x->data[static_cast<int32_T>(idx->data[q] - 1)];
                    i_0 = idx->data[static_cast<int32_T>(p - 1)];
                    if (static_cast<boolean_T>(static_cast<int32_T>((x->data[
                            static_cast<int32_T>(i_0 - 1)] <= tmp) |
                            static_cast<int32_T>(std::isnan(tmp))))) {
                        iwork->data[k] = i_0;
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
                                iwork->data[k] = idx->data[static_cast<int32_T>
                                    (p - 1)];
                                p = static_cast<int32_T>(p + 1);
                            }
                        }
                    }

                    k = static_cast<int32_T>(k + 1);
                }

                for (pEnd = -1; static_cast<int32_T>(pEnd + 1) <=
                        static_cast<int32_T>(kEnd - 1); pEnd =
                        static_cast<int32_T>(pEnd + 1)) {
                    idx->data[static_cast<int32_T>(j + pEnd)] = iwork->data[
                        static_cast<int32_T>(pEnd + 1)];
                }

                j = qEnd;
                pEnd = static_cast<int32_T>(qEnd + i);
            }

            i = i2;
        }

        codegenReal2Mission_emxFree_int32_T(&iwork);
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

// Function for MATLAB Function: '<S61>/getDangerList'
void codegenReal2MissionModelClass::codegenReal2Mission_unique_vector(const
    emxArray_real_T_codegenReal2Mission_T *a,
    emxArray_real_T_codegenReal2Mission_T *b,
    emxArray_int32_T_codegenReal2Mission_T *ndx,
    emxArray_int32_T_codegenReal2Mission_T *pos)
{
    emxArray_int32_T_codegenReal2Mission_T *idx;
    emxArray_int32_T_codegenReal2Mission_T *iwork;
    emxArray_int32_T_codegenReal2Mission_T *r;
    emxArray_real_T_codegenReal2Mission_T *b_0;
    real_T x;
    int32_T e_j;
    int32_T e_k;
    int32_T f_k;
    int32_T i2;
    int32_T n;
    int32_T na;
    int32_T pos_tmp;
    int32_T qEnd;
    int32_T tmp;
    boolean_T exitg1;
    codegenReal2Mission_emxInit_int32_T(&idx, 1);
    na = a->size[0];
    tmp = pos->size[0];
    pos->size[0] = a->size[0];
    codegenReal2Mission_emxEnsureCapacity_int32_T(pos, tmp);
    codegenReal2Mission_sortIdx(a, idx);
    tmp = b->size[0];
    b->size[0] = a->size[0];
    codegenReal2Mission_emxEnsureCapacity_real_T(b, tmp);
    for (n = 0; n <= static_cast<int32_T>(na - 1); n = static_cast<int32_T>(n +
            1)) {
        b->data[n] = a->data[static_cast<int32_T>(idx->data[n] - 1)];
    }

    e_k = 0;
    while ((static_cast<int32_T>(e_k + 1) <= na) && std::isinf(b->data[e_k]) &&
            (b->data[e_k] < 0.0)) {
        e_k = static_cast<int32_T>(e_k + 1);
    }

    n = e_k;
    e_k = a->size[0];
    while ((e_k >= 1) && std::isnan(b->data[static_cast<int32_T>(e_k - 1)])) {
        e_k = static_cast<int32_T>(e_k - 1);
    }

    i2 = static_cast<int32_T>(a->size[0] - e_k);
    exitg1 = false;
    while ((!exitg1) && (e_k >= 1)) {
        x = b->data[static_cast<int32_T>(e_k - 1)];
        if (std::isinf(x) && (x > 0.0)) {
            e_k = static_cast<int32_T>(e_k - 1);
        } else {
            exitg1 = true;
        }
    }

    e_j = static_cast<int32_T>(static_cast<int32_T>(static_cast<int32_T>(a->
        size[0] - e_k) - i2) - 1);
    na = -1;
    if (n > 0) {
        na = 0;
        for (qEnd = 0; qEnd <= static_cast<int32_T>(n - 1); qEnd =
                static_cast<int32_T>(qEnd + 1)) {
            pos->data[static_cast<int32_T>(idx->data[qEnd] - 1)] = 1;
        }
    }

    while (static_cast<int32_T>(n + 1) <= e_k) {
        x = b->data[n];
        qEnd = n;
        do {
            n = static_cast<int32_T>(n + 1);
        } while (!((static_cast<int32_T>(n + 1) > e_k) || (b->data[n] != x)));

        na = static_cast<int32_T>(na + 1);
        b->data[na] = x;
        for (f_k = static_cast<int32_T>(qEnd + 1); f_k <= n; f_k = static_cast<
                int32_T>(f_k + 1)) {
            pos->data[static_cast<int32_T>(idx->data[static_cast<int32_T>(f_k -
                1)] - 1)] = static_cast<int32_T>(na + 1);
        }

        idx->data[na] = idx->data[qEnd];
    }

    if (static_cast<int32_T>(e_j + 1) > 0) {
        na = static_cast<int32_T>(na + 1);
        b->data[na] = b->data[e_k];
        for (n = 0; n <= e_j; n = static_cast<int32_T>(n + 1)) {
            pos->data[static_cast<int32_T>(idx->data[static_cast<int32_T>(e_k +
                n)] - 1)] = static_cast<int32_T>(na + 1);
        }

        idx->data[na] = idx->data[e_k];
    }

    n = static_cast<int32_T>(e_k + e_j);
    for (e_k = 1; static_cast<int32_T>(e_k - 1) <= static_cast<int32_T>(i2 - 1);
         e_k = static_cast<int32_T>(e_k + 1)) {
        na = static_cast<int32_T>(na + 1);
        b->data[na] = b->data[static_cast<int32_T>(n + e_k)];
        pos_tmp = idx->data[static_cast<int32_T>(n + e_k)];
        pos->data[static_cast<int32_T>(pos_tmp - 1)] = static_cast<int32_T>(na +
            1);
        idx->data[na] = pos_tmp;
    }

    if (static_cast<int32_T>(na + 1) < 1) {
        b->size[0] = 0;
    } else {
        tmp = b->size[0];
        b->size[0] = static_cast<int32_T>(na + 1);
        codegenReal2Mission_emxEnsureCapacity_real_T(b, tmp);
    }

    tmp = ndx->size[0];
    ndx->size[0] = static_cast<int32_T>(na + 1);
    codegenReal2Mission_emxEnsureCapacity_int32_T(ndx, tmp);
    for (e_k = 0; e_k <= na; e_k = static_cast<int32_T>(e_k + 1)) {
        ndx->data[e_k] = idx->data[e_k];
    }

    codegenReal2Mission_emxInit_int32_T(&r, 1);
    n = static_cast<int32_T>(ndx->size[0] + 1);
    tmp = r->size[0];
    r->size[0] = ndx->size[0];
    codegenReal2Mission_emxEnsureCapacity_int32_T(r, tmp);
    e_k = ndx->size[0];
    for (pos_tmp = 0; pos_tmp <= static_cast<int32_T>(e_k - 1); pos_tmp++) {
        r->data[pos_tmp] = 0;
    }

    codegenReal2Mission_emxInit_int32_T(&iwork, 1);
    if (ndx->size[0] != 0) {
        tmp = iwork->size[0];
        iwork->size[0] = ndx->size[0];
        codegenReal2Mission_emxEnsureCapacity_int32_T(iwork, tmp);
        for (e_k = 1; e_k <= static_cast<int32_T>(n - 2); e_k =
                static_cast<int32_T>(e_k + 2)) {
            if (ndx->data[static_cast<int32_T>(e_k - 1)] <= ndx->data[e_k]) {
                r->data[static_cast<int32_T>(e_k - 1)] = e_k;
                r->data[e_k] = static_cast<int32_T>(e_k + 1);
            } else {
                r->data[static_cast<int32_T>(e_k - 1)] = static_cast<int32_T>
                    (e_k + 1);
                r->data[e_k] = e_k;
            }
        }

        if (static_cast<uint32_T>(static_cast<uint32_T>(ndx->size[0]) & 1U) !=
                0U) {
            r->data[static_cast<int32_T>(ndx->size[0] - 1)] = ndx->size[0];
        }

        e_k = 2;
        while (e_k < static_cast<int32_T>(n - 1)) {
            int32_T pEnd;
            i2 = static_cast<int32_T>(e_k << 1);
            e_j = 1;
            pEnd = static_cast<int32_T>(e_k + 1);
            while (pEnd < n) {
                int32_T kEnd;
                int32_T p;
                int32_T q;
                p = e_j;
                q = pEnd;
                qEnd = static_cast<int32_T>(e_j + i2);
                if (qEnd > n) {
                    qEnd = n;
                }

                f_k = 0;
                kEnd = static_cast<int32_T>(qEnd - e_j);
                while (static_cast<int32_T>(f_k + 1) <= kEnd) {
                    pos_tmp = r->data[static_cast<int32_T>(q - 1)];
                    tmp = r->data[static_cast<int32_T>(p - 1)];
                    if (ndx->data[static_cast<int32_T>(tmp - 1)] <= ndx->data[
                            static_cast<int32_T>(pos_tmp - 1)]) {
                        iwork->data[f_k] = tmp;
                        p = static_cast<int32_T>(p + 1);
                        if (p == pEnd) {
                            while (q < qEnd) {
                                f_k = static_cast<int32_T>(f_k + 1);
                                iwork->data[f_k] = r->data[static_cast<int32_T>
                                    (q - 1)];
                                q = static_cast<int32_T>(q + 1);
                            }
                        }
                    } else {
                        iwork->data[f_k] = pos_tmp;
                        q = static_cast<int32_T>(q + 1);
                        if (q == qEnd) {
                            while (p < pEnd) {
                                f_k = static_cast<int32_T>(f_k + 1);
                                iwork->data[f_k] = r->data[static_cast<int32_T>
                                    (p - 1)];
                                p = static_cast<int32_T>(p + 1);
                            }
                        }
                    }

                    f_k = static_cast<int32_T>(f_k + 1);
                }

                for (pEnd = -1; static_cast<int32_T>(pEnd + 1) <=
                        static_cast<int32_T>(kEnd - 1); pEnd =
                        static_cast<int32_T>(pEnd + 1)) {
                    r->data[static_cast<int32_T>(e_j + pEnd)] = iwork->data[
                        static_cast<int32_T>(pEnd + 1)];
                }

                e_j = qEnd;
                pEnd = static_cast<int32_T>(qEnd + e_k);
            }

            e_k = i2;
        }
    }

    codegenReal2Mission_emxInit_real_T(&b_0, 1);
    tmp = b_0->size[0];
    b_0->size[0] = r->size[0];
    codegenReal2Mission_emxEnsureCapacity_real_T(b_0, tmp);
    e_k = r->size[0];
    for (pos_tmp = 0; pos_tmp <= static_cast<int32_T>(e_k - 1); pos_tmp++) {
        b_0->data[pos_tmp] = b->data[static_cast<int32_T>(r->data[pos_tmp] - 1)];
    }

    tmp = b->size[0];
    b->size[0] = b_0->size[0];
    codegenReal2Mission_emxEnsureCapacity_real_T(b, tmp);
    e_k = b_0->size[0];
    for (pos_tmp = 0; pos_tmp <= static_cast<int32_T>(e_k - 1); pos_tmp++) {
        b->data[pos_tmp] = b_0->data[pos_tmp];
    }

    codegenReal2Mission_emxFree_real_T(&b_0);
    tmp = iwork->size[0];
    iwork->size[0] = r->size[0];
    codegenReal2Mission_emxEnsureCapacity_int32_T(iwork, tmp);
    for (e_k = 0; e_k <= na; e_k = static_cast<int32_T>(e_k + 1)) {
        ndx->data[e_k] = idx->data[static_cast<int32_T>(r->data[e_k] - 1)];
        iwork->data[static_cast<int32_T>(r->data[e_k] - 1)] =
            static_cast<int32_T>(e_k + 1);
    }

    codegenReal2Mission_emxFree_int32_T(&r);
    codegenReal2Mission_emxFree_int32_T(&idx);
    e_k = pos->size[0];
    for (pos_tmp = 0; pos_tmp <= static_cast<int32_T>(e_k - 1); pos_tmp++) {
        pos->data[pos_tmp] = iwork->data[static_cast<int32_T>(pos->data[pos_tmp]
            - 1)];
    }

    codegenReal2Mission_emxFree_int32_T(&iwork);
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_boolean_T
    (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
    emxArray_boolean_T_codegenReal2Mission_T *emxArray;
    *pEmxArray = static_cast<emxArray_boolean_T_codegenReal2Mission_T *>(std::
        malloc(sizeof(emxArray_boolean_T_codegenReal2Mission_T)));
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

void codegenReal2MissionModelClass::
    codegenReal2Mission_emxEnsureCapacity_boolean_T
    (emxArray_boolean_T_codegenReal2Mission_T *emxArray, int32_T oldNumel)
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

void codegenReal2MissionModelClass::codegenReal2Mission_emxFree_boolean_T
    (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray)
{
    if (*pEmxArray != static_cast<emxArray_boolean_T_codegenReal2Mission_T *>
            (nullptr)) {
        if (((*pEmxArray)->data != static_cast<boolean_T *>(nullptr)) &&
                (*pEmxArray)->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = static_cast<emxArray_boolean_T_codegenReal2Mission_T *>
            (nullptr);
    }
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S3>/FeedbackCurrentMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'

    if (codegenReal2Mission_pop_h
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_5_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg_g(&msg);
    }

    // End of Queue generated from: '<S3>/FeedbackCurrentMission'
    return status;
}

// Function for MATLAB Function: '<S88>/TimeConverter'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_g(real_T dd,
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
    int32_T ic_quot;
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
    c_s = floor_LKLalLcG(c_ahi_0);
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
    c_s = split_uvVAOGsE(b_c.re);
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
    c_s = floor_LKLalLcG(a);
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
        ic_quot = static_cast<int32_T>(idn - static_cast<int32_T>(3600 * div_s32
            (idn, 3600)));
        *h = std::trunc(static_cast<real_T>(idn) / 3600.0);
        *m = std::trunc(static_cast<real_T>(ic_quot) / 60.0);
        b_thi = static_cast<real_T>(static_cast<int32_T>(ic_quot -
            static_cast<int32_T>(60 * div_s32(ic_quot, 60))));
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata(void) const
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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
            codegenReal2Mission_DW.eml_openfiles[static_cast<int32_T>(
                static_cast<int32_T>(j) - 1)] = filestar;
            codegenReal2Mission_DW.eml_autoflush_m[static_cast<int32_T>(
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_fileManager(real_T
    varargin_1, FILE* *f, boolean_T *a)
{
    int8_T fileid;
    fileid = static_cast<int8_T>(std::round(varargin_1));
    if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>(fileid)
           < 0) | (varargin_1 != static_cast<real_T>(fileid))))) {
        fileid = -1;
    }

    if (static_cast<int32_T>(fileid) >= 3) {
        *f = codegenReal2Mission_DW.eml_openfiles[static_cast<int32_T>(
            static_cast<int32_T>(fileid) - 3)];
        *a = codegenReal2Mission_DW.eml_autoflush_m[static_cast<int32_T>(
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
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

    validate_print_arguments_sA7pOmrf(IndivMissionCMD_StartTime.year,
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
    codegenReal2Mission_getDateVec(TimeNow_data, &b_varargin_1, &a__1, &a__2,
        &a__3, &a__4, &a__5);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__2, &a__1, &a__3, &a__4,
        &a__5, &a__11);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__3, &a__4, &a__2, &a__5,
        &a__11, &a__17);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__4, &a__5, &a__11, &a__3,
        &a__17, &a__23);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__5, &a__11, &a__17, &a__23,
        &a__4, &a__29);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__11, &a__17, &a__23, &a__29,
        &a__35, &a__5);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__17, &a__23, &a__29, &a__35,
        &b_a__35, &a__11);
    codegenReal2Mission_getDateVec(TimeNow_data, &a__17, &a__23, &a__29, &a__35,
        &b_a__35, &x);
    validate_print_arguments_Ogsds6Vg(b_varargin_1, a__1, a__2, a__3, a__4, std::
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

// Function for MATLAB Function: '<S88>/PrintOnboardLog'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose(real_T fid)
{
    FILE* filestar;
    int32_T st;
    int8_T b_fileid;
    int8_T fileid;
    st = -1;
    fileid = static_cast<int8_T>(std::round(fid));
    if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>(fileid)
           < 0) | (fid != static_cast<real_T>(fileid))))) {
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
            codegenReal2Mission_DW.eml_autoflush_m[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = true;
        }
    }

    return st;
}

Msg_real_T codegenReal2MissionModelClass::codegenReal2Mission_createMsg(const
    real_T *data)
{
    Msg_real_T msg;

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState'
    msg.fData = *data;
    return msg;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push(Buffer_real_T *
    q, const Msg_real_T *element)
{
    // Queue generated from: '<S5>/ProcessIndivState'
    q->fMsg = *element;
    q->fOccupied = true;
    return true;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_c_SendData(
    const real_T *data)
{
    Msg_real_T msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S5>/ProcessIndivState' incorporates:
    //   Send: '<S10>/Send'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<S5>/ProcessIndivState'
    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_ProcessIndivState_at_inport_0_Queue,
             &msg)) {
        status = 0;
    }

    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop(Buffer_real_T
    *q, Msg_real_T *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<S5>/ProcessIndivState'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<S5>/ProcessIndivState'
    return isPop;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_Receive_RecvData
    (real_T *data)
{
    Msg_real_T msg;
    int32_T status{ 1 };

    // Queue generated from: '<S5>/ProcessIndivState' incorporates:
    //   Receive: '<S9>/Receive'

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_ProcessIndivState_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S5>/ProcessIndivState'
    return status;
}

void codegenReal2MissionModelClass::
    codegenReal2Mission_emxFreeStruct_DangerArray
    (DangerArray_codegenReal2Mission_T *pStruct)
{
    codegenReal2Mission_emxFree_real_T(&pStruct->DangerList);
}

void codegenReal2MissionModelClass::codegenReal2Mission_initMemPool
    (MemPool_IndividualUAVCmd *memPool, IndividualUAVCmd *memArray,
     IndividualUAVCmd **freeList, int32_T size)
{
    // Start for slMsgMgr: '<Root>/slMsgMgr'
    memPool->fMemArray = memArray;
    memPool->fNumUsed = 0;
    memPool->fFreeList = freeList;
    memPool->fNumFree = 0;
    memPool->fSize = size;
}

void codegenReal2MissionModelClass::codegenReal2Mission_initMemPool_o
    (MemPool_missionCmd *memPool, missionCmd *memArray, missionCmd **freeList,
     int32_T size)
{
    // Start for slMsgMgr: '<Root>/slMsgMgr'
    memPool->fMemArray = memArray;
    memPool->fNumUsed = 0;
    memPool->fFreeList = freeList;
    memPool->fNumFree = 0;
    memPool->fSize = size;
}

void codegenReal2MissionModelClass::codegenReal2Mission_initMemPool_d
    (MemPool_DangerInfo *memPool, DangerInfo *memArray, DangerInfo **freeList,
     int32_T size)
{
    // Start for slMsgMgr: '<Root>/slMsgMgr'
    memPool->fMemArray = memArray;
    memPool->fNumUsed = 0;
    memPool->fFreeList = freeList;
    memPool->fNumFree = 0;
    memPool->fSize = size;
}

void codegenReal2MissionModelClass::codegenReal2Mission_initQueue
    (Queue_IndividualUAVCmd *q, QueuePolicy_T policy, int32_T capacity,
     Msg_IndividualUAVCmd *qPool)
{
    // Start for Queue: '<S110>/Queue'
    q->fPolicy = policy;
    q->fCapacity = capacity;
    q->fHead = -1;
    q->fTail = -1;
    q->fArray = qPool;
}

void codegenReal2MissionModelClass::
    codegenReal2Mission_emxInitStruct_DangerArray
    (DangerArray_codegenReal2Mission_T *pStruct)
{
    codegenReal2Mission_emxInit_real_T(&pStruct->DangerList, 2);
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata_k(const FILE*
    eml_openfiles_g[20])
{
    int32_T k;
    int8_T f;
    boolean_T exitg1;
    f = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (static_cast<int32_T>(k - 1) < 20)) {
        if (eml_openfiles_g[static_cast<int32_T>(static_cast<int32_T>(
                static_cast<int8_T>(k)) - 1)] == NULL) {
            f = static_cast<int8_T>(k);
            exitg1 = true;
        } else {
            k = static_cast<int32_T>(k + 1);
        }
    }

    return f;
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen_g(const char_T *
    cfilename, const char_T *cpermission, FILE* eml_openfiles_g[20])
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata_k(const_cast<const FILE**>(eml_openfiles_g));
    if (static_cast<int32_T>(j) >= 1) {
        FILE* filestar;
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
            int32_T tmp;
            eml_openfiles_g[static_cast<int32_T>(static_cast<int32_T>(j) - 1)] =
                filestar;
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_fread(real_T fileID,
    FILE* eml_openfiles_g[20], emxArray_char_T_codegenReal2Mission_T *A)
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
        filestar = eml_openfiles_g[static_cast<int32_T>(static_cast<int32_T>
            (fileid) - 3)];
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
                c_0 = -1;
                loop_ub = -1;
            } else {
                c_0 = static_cast<int32_T>(c - 1);
                loop_ub = static_cast<int32_T>(c - 1);
            }

            tmp = A->size[0];
            A->size[0] = static_cast<int32_T>(static_cast<int32_T>(c_0 + A->
                size[0]) + 1);
            codegenReal2Mission_emxEnsureCapacity_char_T(A, tmp);
            for (c_0 = 0; c_0 <= loop_ub; c_0++) {
                A->data[static_cast<int32_T>(numRead + c_0)] = tbuf[c_0];
            }
        }
    }
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose_e(real_T fid,
    FILE* eml_openfiles_g[20])
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
        filestar = eml_openfiles_g[static_cast<int32_T>(static_cast<int32_T>
            (b_fileid) - 3)];
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
            eml_openfiles_g[static_cast<int32_T>(static_cast<int32_T>(fileid) -
                3)] = NULL;
        }
    }

    return st;
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_i(const
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

// Function for MATLAB Function: '<S57>/ReadHomePoint'
void codegenReal2MissionModelClass::codegenReal2Mission_readfloat
    (emxArray_char_T_codegenReal2Mission_T *s1, int32_T *idx, const
     emxArray_char_T_codegenReal2Mission_T *s, int32_T *k, int32_T n, boolean_T
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

    emxArray_char_T_codegenReal2Mission_T *d;
    int32_T b_idx;
    int32_T b_k;
    int32_T g_k;
    char_T c_idx_0;
    boolean_T a__3;
    boolean_T exitg1;
    boolean_T isneg;
    codegenReal2Mission_emxInit_char_T(&d, 2);
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
                    codegenReal2Mission_readfloat(s1, idx, s, k, n, false,
                        &isneg, b_finite, nfv, &a__3, success);
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
                codegenReal2Mission_emxEnsureCapacity_char_T(d, b_k);
                loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                for (b_k = 0; b_k <= loop_ub; b_k++) {
                    d->data[b_k] = s1->data[b_k];
                }

                *success = codegenReal2Mission_copydigits(d, &b_idx, s, &g_k, n,
                    true);
                b_k = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                s1->size[0] = 1;
                s1->size[1] = d->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(s1, b_k);
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
                        codegenReal2Mission_emxEnsureCapacity_char_T(d, b_k);
                        loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                        for (b_k = 0; b_k <= loop_ub; b_k++) {
                            d->data[b_k] = s1->data[b_k];
                        }

                        b_idx = static_cast<int32_T>(g_k + 1);
                        isneg = codegenReal2Mission_copydigits(d, idx, s, &b_idx,
                            n, false);
                        b_k = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                        s1->size[0] = 1;
                        s1->size[1] = d->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(s1, b_k);
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

    codegenReal2Mission_emxFree_char_T(&d);
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
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

    emxArray_char_T_codegenReal2Mission_T *d;
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
    codegenReal2Mission_emxInit_char_T(&d, 2);
    x.re = (rtNaN);
    x.im = 0.0;
    if (s->size[1] >= 1) {
        int32_T i;
        int32_T loop_ub;
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

        i = static_cast<int32_T>(d->size[0] * d->size[1]);
        d->size[0] = 1;
        d->size[1] = static_cast<int32_T>(s->size[1] + 2);
        codegenReal2Mission_emxEnsureCapacity_char_T(d, i);
        loop_ub = s->size[1];
        for (i = 0; i <= static_cast<int32_T>(loop_ub + 1); i++) {
            d->data[i] = '\x00';
        }

        idx = 1;
        codegenReal2Mission_readfloat(d, &idx, s, &k, s->size[1], true, &isimag1,
            &isfinite1, &scanned1, &a__1, &success);
        i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
        s1->size[0] = 1;
        s1->size[1] = d->size[1];
        codegenReal2Mission_emxEnsureCapacity_char_T(s1, i);
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
                codegenReal2Mission_emxEnsureCapacity_char_T(d, i);
                loop_ub = static_cast<int32_T>(s1->size[1] - 1);
                for (i = 0; i <= loop_ub; i++) {
                    d->data[i] = s1->data[i];
                }

                idx = static_cast<int32_T>(idx + 1);
                codegenReal2Mission_readfloat(d, &idx, s, &k, s->size[1], true,
                    &a__1, &success, &scanned2, &foundsign, &c_success);
                i = static_cast<int32_T>(s1->size[0] * s1->size[1]);
                s1->size[0] = 1;
                s1->size[1] = d->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(s1, i);
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

        codegenReal2Mission_emxFree_char_T(&s1);
    }

    codegenReal2Mission_emxFree_char_T(&d);
    return x;
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_i1(const
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S57>/ReadHomePoint'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_i15(const
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

    codegenReal2Mission_emxFree_char_T(&aTmp);
    return b_bool;
}

// Function for MATLAB Function: '<S57>/ReadParADRC'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata_e(void) const
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen_j(const char_T *
    cfilename, const char_T *cpermission)
{
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata_e();
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
real_T codegenReal2MissionModelClass::codegenReal2Mission_fileManager_p(void)
{
    int8_T fileid;
    fileid = codegenReal2Mission_cfopen_j("config.ini", "rb");
    return static_cast<real_T>(fileid);
}

// Function for MATLAB Function: '<S57>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_fread_n(real_T fileID,
    emxArray_char_T_codegenReal2Mission_T *A)
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
            codegenReal2Mission_emxEnsureCapacity_char_T(A, i);
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose_g(real_T fid)
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_strtok_e2sz(const
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_b(const
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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_by(const
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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_byv(const
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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_byvm(const
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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_byvm0(const
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
        loop_ub = static_cast<int32_T>(a->size[1] - 1);
        for (i = 0; i <= loop_ub; i++) {
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
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
        int32_T itoken_0;
        int32_T loop_ub;
        codegenReal2Mission_emxInit_char_T(&data, 2);
        codegenReal2Mission_emxInit_char_T(&i, 1);
        codegenReal2Mission_fread_n(static_cast<real_T>(fileid), i);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = i->size[0];
        codegenReal2Mission_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = i->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = i->data[itoken_0];
        }

        codegenReal2Mission_emxFree_char_T(&i);
        codegenReal2Mission_emxInit_char_T(&curSection, 2);
        codegenReal2Mission_emxInit_char_T(&curKey, 2);
        codegenReal2Mission_emxInit_char_T(&curVal, 2);
        codegenReal2Mission_cfclose_g(static_cast<real_T>(fileid));
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
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
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
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

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, itoken_0);
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
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp,
                            itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if ((aTmp->size[1] == 1) && (h[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<uint8_T>(aTmp->
                            data[0])) & 127)] == 'i')) {
                        b_bool = true;
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret,
                            itoken_0);
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_readINI_g
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
        int32_T itoken_0;
        int32_T loop_ub;
        codegenReal2Mission_emxInit_char_T(&data, 2);
        codegenReal2Mission_emxInit_char_T(&i, 1);
        codegenReal2Mission_fread_n(static_cast<real_T>(fileid), i);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = i->size[0];
        codegenReal2Mission_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = i->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = i->data[itoken_0];
        }

        codegenReal2Mission_emxFree_char_T(&i);
        codegenReal2Mission_emxInit_char_T(&curSection, 2);
        codegenReal2Mission_emxInit_char_T(&curKey, 2);
        codegenReal2Mission_emxInit_char_T(&curVal, 2);
        codegenReal2Mission_cfclose_g(static_cast<real_T>(fileid));
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
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
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
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

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, itoken_0);
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
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp,
                            itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
                        }
                    }

                    b_bool = false;
                    if ((aTmp->size[1] == 1) && (h[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<uint8_T>(aTmp->
                            data[0])) & 127)] == 'd')) {
                        b_bool = true;
                    }

                    if (b_bool) {
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret,
                            itoken_0);
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
void codegenReal2MissionModelClass::codegenReal2Mission_readINI_gx
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
        int32_T itoken_0;
        int32_T loop_ub;
        codegenReal2Mission_emxInit_char_T(&data, 2);
        codegenReal2Mission_emxInit_char_T(&j, 1);
        codegenReal2Mission_fread_n(static_cast<real_T>(fileid), j);
        itoken_0 = static_cast<int32_T>(data->size[0] * data->size[1]);
        data->size[0] = 1;
        data->size[1] = j->size[0];
        codegenReal2Mission_emxEnsureCapacity_char_T(data, itoken_0);
        loop_ub = j->size[0];
        for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>(loop_ub - 1);
                itoken_0++) {
            data->data[itoken_0] = j->data[itoken_0];
        }

        codegenReal2Mission_emxFree_char_T(&j);
        codegenReal2Mission_emxInit_char_T(&curSection, 2);
        codegenReal2Mission_emxInit_char_T(&curKey, 2);
        codegenReal2Mission_emxInit_char_T(&curVal, 2);
        codegenReal2Mission_cfclose_g(static_cast<real_T>(fileid));
        curSection->size[0] = 1;
        curSection->size[1] = 0;
        curKey->size[0] = 1;
        curKey->size[1] = 0;
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
                itoken_0 = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_0, itoken_0);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                    itoken = itoken_0;
                    data_0->data[itoken_0] = data->data[itoken_0];
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

                            itoken_0 = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(itoken - iremain);
                            curSection->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, itoken_0);
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
                            itoken_0 = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                itoken_0);
                            for (itoken_0 = 0; itoken_0 <= static_cast<int32_T>
                                    (loop_ub - 1); itoken_0++) {
                                curLine->data[itoken_0] = curVal->data[
                                    static_cast<int32_T>(itoken + itoken_0)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_b(curSection)) {
                    if (curKey->size[1] == 0) {
                        aTmp->size[0] = 1;
                        aTmp->size[1] = 0;
                    } else {
                        itoken_0 = static_cast<int32_T>(aTmp->size[0] *
                            aTmp->size[1]);
                        aTmp->size[0] = 1;
                        aTmp->size[1] = curKey->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(aTmp,
                            itoken_0);
                        loop_ub = static_cast<int32_T>(curKey->size[1] - 1);
                        for (itoken_0 = 0; itoken_0 <= loop_ub; itoken_0++) {
                            itoken = itoken_0;
                            aTmp->data[itoken_0] = curKey->data[itoken_0];
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
                        itoken_0 = static_cast<int32_T>(ret->size[0] * ret->
                            size[1]);
                        ret->size[0] = 1;
                        ret->size[1] = curVal->size[1];
                        codegenReal2Mission_emxEnsureCapacity_char_T(ret,
                            itoken_0);
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

// Function for MATLAB Function: '<S57>/ReadParADRC'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_byvm0m(const
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

// Model step function
void codegenReal2MissionModelClass::step()
{
    // local block i/o variables
    real_T rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[4];
    int32_T rtb_intFlightStatus;
    int32_T rtb_intImmedStatus;
    DangerInfo rtb_CreatDanger;
    FixedWingGuidanceStateBus
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1;
    Location rtb_Switch;
    emxArray_boolean_T_codegenReal2Mission_T *b;
    emxArray_char_T_1x10_codegenReal2Mission_T SFunction_DIMS2_h;
    emxArray_int32_T_codegenReal2Mission_T *c;
    emxArray_int32_T_codegenReal2Mission_T *indx;
    emxArray_int32_T_codegenReal2Mission_T *ipos;
    emxArray_real_T_codegenReal2Mission_T *a__1;
    emxArray_real_T_codegenReal2Mission_T *b_b;
    emxArray_real_T_codegenReal2Mission_T *g;
    emxArray_real_T_codegenReal2Mission_T *outputArg_DangerList;
    emxArray_real_T_codegenReal2Mission_T *outputArg_DangerList_0;
    emxArray_real_T_codegenReal2Mission_T *second_0;
    emxArray_real_T_codegenReal2Mission_T *theta;
    emxArray_real_T_codegenReal2Mission_T *tmp_0;
    emxArray_real_T_codegenReal2Mission_T *varargin_2;
    missionCmd rtb_FeedbackCMD;
    missionCmd rtb_FlightCMD;
    creal_T b_this_data;
    creal_T temp_0;
    creal_T temp_1;
    creal_T temp_2;
    creal_T temp_3;
    real_T c_tm_year[7];
    real_T c_tm_year_0[7];
    real_T processedInData[7];
    real_T obj2_DangerList_data[4];
    real_T rtb_MemoryPose[4];
    real_T tmp_data[2];
    real_T a__17;
    real_T a__23;
    real_T a__29;
    real_T a__35;
    real_T b_a__35;
    real_T b_x;
    real_T c_tm_mon;
    real_T check;
    real_T da_im;
    real_T fracSecs;
    real_T rtb_AltitudeGCS_o;
    real_T rtb_LatitudeGCS_i;
    real_T rtb_LongitudeGCS_h;
    real_T rtb_Sum1_o_idx_1;
    real_T rtb_posixTime_e;
    real_T second;
    real_T temp;
    real_T tmp;
    int32_T i;
    int32_T i2;
    int32_T ix;
    int32_T j;
    int32_T status;
    int32_T status_0;
    int32_T tmp_2;
    int32_T tmp_6;
    int32_T wholeSecsFromMillis{ 1 };

    int16_T c_data[1024];
    char_T st[12];
    int8_T fileid;
    boolean_T x[4096];
    boolean_T y[1024];
    boolean_T ANDAvoidDanger;
    boolean_T rtb_Compare_dv;
    boolean_T rtb_Compare_j2;
    boolean_T rtb_Receive_o1;
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
    }                                  // end MajorTimeStep

    // Update absolute time of base rate at minor time step
    if (rtmIsMinorTimeStep((&codegenReal2Mission_M))) {
        (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetT
            (&(&codegenReal2Mission_M)->solverInfo);
    }

    codegenReal2Mission_emxInit_real_T(&g, 2);
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        real32_T tmp_1;

        // Outputs for Atomic SubSystem: '<Root>/GCSLLA'
        // DataStoreRead: '<S2>/AltitudeGCS'
        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        rtb_LongitudeGCS_h = AltitudeGCS;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);

        // DataStoreRead: '<S2>/LatitudeGCS'
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        rtb_AltitudeGCS_o = LatitudeGCS;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);

        // DataStoreRead: '<S2>/LongitudeGCS'
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        rtb_LatitudeGCS_i = LongitudeGCS;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);

        // End of Outputs for SubSystem: '<Root>/GCSLLA'

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
                codegenReal2Mission_DW.RateTransition[i] =
                    codegenReal2Mission_DW.RateTransition_Buf0[i];
            }
            break;

          case 1:
            for (i = 0; i < 4096; i++) {
                codegenReal2Mission_DW.RateTransition[i] =
                    codegenReal2Mission_DW.RateTransition_Buf1[i];
            }
            break;

          case 2:
            for (i = 0; i < 4096; i++) {
                codegenReal2Mission_DW.RateTransition[i] =
                    codegenReal2Mission_DW.RateTransition_Buf2[i];
            }
            break;
        }

        // End of RateTransition: '<Root>/Rate Transition'

        // Outputs for Atomic SubSystem: '<Root>/MissionLogic'
        // Outputs for Atomic SubSystem: '<S3>/PreProcessMissionCMD'
        // Outputs for Atomic SubSystem: '<S58>/QueueCMD'
        // Receive: '<S110>/Receive'
        wholeSecsFromMillis = 1;
        MissionCMDRecvData.RecvData(&codegenReal2Mission_DW.Receive_o2, sizeof
            (IndividualUAVCmd), &wholeSecsFromMillis);
        rtb_Receive_o1 = (wholeSecsFromMillis != 1);

        // Outputs for Enabled SubSystem: '<S110>/UplinkLog' incorporates:
        //   EnablePort: '<S123>/Enable'

        if (rtb_Receive_o1) {
            // MATLAB Function: '<S123>/PrintOnboardLog'
            // MATLAB Function 'MissionLogic/PreProcessMissionCMD/QueueCMD/UplinkLog/PrintOnboardLog': '<S127>:1' 
            // '<S127>:1:3'
            fileid = codegenReal2Mission_cfopen_o("OnboardUplinkRcvCMD.log",
                "ab");

            // '<S127>:1:4'
            codegenReal2Mission_printIndivMissionCMD_f
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

            // '<S127>:1:5'
            codegenReal2Mission_cfclose_l(static_cast<real_T>(fileid));
        }

        // End of Outputs for SubSystem: '<S110>/UplinkLog'

        // RelationalOperator: '<S118>/Compare' incorporates:
        //   Constant: '<S118>/Constant'

        rtb_Compare_j2 = (codegenReal2Mission_DW.Receive_o2.MissionMode !=
                          MissionModes::AvoidDanger);

        // Logic: '<S110>/ANDAvoidDanger'
        ANDAvoidDanger = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(rtb_Compare_j2) & static_cast<int32_T>
            (rtb_Receive_o1)));

        // RelationalOperator: '<S116>/FixPt Relational Operator' incorporates:
        //   UnitDelay: '<S116>/Delay Input1'
        //
        //  Block description for '<S116>/Delay Input1':
        //
        //   Store in Global RAM

        rtb_Compare_j2 = (codegenReal2Mission_DW.Receive_o2.SequenceID !=
                          codegenReal2Mission_DW.DelayInput1_DSTATE);

        // RelationalOperator: '<S117>/Compare' incorporates:
        //   Constant: '<S117>/Constant'

        rtb_Compare_dv = (codegenReal2Mission_DW.Receive_o2.MissionMode ==
                          MissionModes::AvoidDanger);

        // MATLAB Function: '<S110>/getCurrentTime'
        // MATLAB Function 'getCurrentTime': '<S124>:1'
        // '<S124>:1:3'
        codegenReal2Mission_getLocalTime(&check, &fracSecs, &temp,
            &rtb_posixTime_e, &tmp, &c_tm_mon, &rtb_Sum1_o_idx_1,
            &rtb_Receive_o1);
        processedInData[4] = temp;
        processedInData[5] = fracSecs;
        processedInData[6] = check / 1.0E+6;
        second = fracSecs;
        fracSecs = processedInData[6];
        check = (((((rtb_Sum1_o_idx_1 + c_tm_mon) + tmp) + rtb_posixTime_e) +
                  temp) + processedInData[5]) + processedInData[6];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(check)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(check)) ^ 1)))))) {
            check = rtb_Sum1_o_idx_1;
            temp = c_tm_mon;
            if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
                temp = std::floor((c_tm_mon - 1.0) / 12.0);
                check = rtb_Sum1_o_idx_1 + temp;
                temp = ((c_tm_mon - 1.0) - temp * 12.0) + 1.0;
            }

            if (temp < 3.0) {
                check--;
                temp += 9.0;
            } else {
                temp -= 3.0;
            }

            da_im = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor
                         (check / 100.0)) + std::floor(check / 400.0)) + std::
                       floor((153.0 * temp + 2.0) / 5.0)) + tmp) + 60.0) -
                719529.0;
            temp = 1.34217729E+8 * da_im;
            temp -= temp - da_im;
            check = da_im * 8.64E+7;
            b_this_data.re = check;
            da_im = (da_im - temp) * 8.64E+7 + (temp * 8.64E+7 - check);
            b_this_data.im = da_im;
            if (std::isnan(da_im)) {
                b_this_data.im = 0.0;
            }

            if ((processedInData[6] < 0.0) || (processedInData[6] >= 1000.0)) {
                fracSecs = std::floor(processedInData[6] / 1000.0);
                second = processedInData[5] + fracSecs;
                fracSecs = processedInData[6] - fracSecs * 1000.0;
            }

            b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(b_this_data, (60.0 * rtb_posixTime_e +
                processedInData[4]) * 60000.0), second * 1000.0), fracSecs);
        } else {
            b_this_data.re = check;
        }

        // Send: '<S110>/Send'
        if (ANDAvoidDanger) {
            codegenReal2Mission_Queue_SendData
                (&codegenReal2Mission_DW.Receive_o2);
        }

        // End of Send: '<S110>/Send'

        // Logic: '<S110>/OR' incorporates:
        //   Logic: '<S110>/AND'
        //   Memory: '<S110>/InitMemory'
        //   Memory: '<S110>/Memory'
        //   Memory: '<S110>/MemoryPreemption'

        ANDAvoidDanger = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(codegenReal2Mission_DW.InitMemory_PreviousInput)
            & static_cast<int32_T>(ANDAvoidDanger)))) | static_cast<int32_T>
            (codegenReal2Mission_DW.Memory_PreviousInput_e)))) |
            static_cast<int32_T>
            (codegenReal2Mission_DW.MemoryPreemption_PreviousInput)));

        // Outputs for Enabled SubSystem: '<S110>/ReadOne' incorporates:
        //   EnablePort: '<S120>/Enable'

        if (ANDAvoidDanger) {
            // Receive: '<S120>/Receive'
            codegenReal2Mission_Queue_RecvData(&codegenReal2Mission_DW.Receive);
        }

        // End of Outputs for SubSystem: '<S110>/ReadOne'

        // MATLAB Function: '<S110>/Struct2PosixCurr'
        // MATLAB Function 'Struct2Posix': '<S121>:1'
        // '<S121>:1:3'
        check = static_cast<real_T>
            (codegenReal2Mission_DW.Receive.StartTime.year);
        temp = static_cast<real_T>
            (codegenReal2Mission_DW.Receive.StartTime.month);
        second = static_cast<real_T>
            (codegenReal2Mission_DW.Receive.StartTime.second);
        fracSecs = static_cast<real_T>
            (codegenReal2Mission_DW.Receive.StartTime.millisecond);
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Receive.StartTime.month
               < 1) | (codegenReal2Mission_DW.Receive.StartTime.month > 12)))) {
            wholeSecsFromMillis = static_cast<int32_T>(std::floor
                ((static_cast<real_T>
                  (codegenReal2Mission_DW.Receive.StartTime.month) - 1.0) / 12.0));
            check = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.year) +
                static_cast<real_T>(wholeSecsFromMillis);
            temp = ((static_cast<real_T>
                     (codegenReal2Mission_DW.Receive.StartTime.month) - 1.0) -
                    static_cast<real_T>(wholeSecsFromMillis) * 12.0) + 1.0;
        }

        if (temp < 3.0) {
            check--;
            temp += 9.0;
        } else {
            temp -= 3.0;
        }

        da_im = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor
                     (check / 100.0)) + std::floor(check / 400.0)) + std::floor
                   ((153.0 * temp + 2.0) / 5.0)) + static_cast<real_T>
                  (codegenReal2Mission_DW.Receive.StartTime.day)) + 60.0) -
            719529.0;
        temp = 1.34217729E+8 * da_im;
        temp -= temp - da_im;
        check = da_im * 8.64E+7;
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Receive.StartTime.millisecond
               < 0) | (codegenReal2Mission_DW.Receive.StartTime.millisecond >=
                       1000)))) {
            wholeSecsFromMillis = static_cast<int32_T>(std::floor
                (static_cast<real_T>
                 (codegenReal2Mission_DW.Receive.StartTime.millisecond) / 1000.0));
            second = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.second) + static_cast<
                real_T>(wholeSecsFromMillis);
            fracSecs = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.millisecond) -
                static_cast<real_T>(wholeSecsFromMillis) * 1000.0;
        }

        temp_0.re = check;
        temp_0.im = (da_im - temp) * 8.64E+7 + (temp * 8.64E+7 - check);
        rtb_posixTime_e = (plus_WAUOGGgr(plus_WAUOGGgr(plus_WAUOGGgr(temp_0,
                              (60.0 * static_cast<real_T>
                               (codegenReal2Mission_DW.Receive.StartTime.hour) +
                               static_cast<real_T>
                               (codegenReal2Mission_DW.Receive.StartTime.minute))
                              * 60000.0), second * 1000.0), fracSecs)).re /
            1000.0;

        // BusCreator: '<S119>/CreatDanger' incorporates:
        //   DataTypeConversion: '<S119>/Cast To Double'

        rtb_CreatDanger.Radius = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.params.Param1);

        // DataTypeConversion: '<S119>/Cast To int32'
        tmp_1 = std::floor(codegenReal2Mission_DW.Receive_o2.params.Param3);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(tmp_1)) | static_cast<int32_T>(std::isinf(tmp_1))))) {
            tmp_1 = 0.0F;
        } else {
            tmp_1 = std::fmod(tmp_1, 4.2949673E+9F);
        }

        // BusCreator: '<S119>/CreatDanger' incorporates:
        //   DataTypeConversion: '<S119>/Cast To int32'

        rtb_CreatDanger.DangerID = tmp_1 < 0.0F ? static_cast<int32_T>(-
            static_cast<int32_T>(static_cast<uint32_T>(-tmp_1))) :
            static_cast<int32_T>(static_cast<uint32_T>(tmp_1));
        rtb_CreatDanger.DangerLoc =
            codegenReal2Mission_DW.Receive_o2.MissionLocation;

        // MATLAB Function: '<S110>/Struct2PosixUplink'
        // MATLAB Function 'Struct2Posix': '<S122>:1'
        // '<S122>:1:3'
        check = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.StartTime.year);
        temp = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.StartTime.month);
        second = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.StartTime.second);
        fracSecs = static_cast<real_T>
            (codegenReal2Mission_DW.Receive_o2.StartTime.millisecond);
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Receive_o2.StartTime.month
               < 1) | (codegenReal2Mission_DW.Receive_o2.StartTime.month > 12))))
        {
            wholeSecsFromMillis = static_cast<int32_T>(std::floor
                ((static_cast<real_T>
                  (codegenReal2Mission_DW.Receive_o2.StartTime.month) - 1.0) /
                 12.0));
            check = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2.StartTime.year) +
                static_cast<real_T>(wholeSecsFromMillis);
            temp = ((static_cast<real_T>
                     (codegenReal2Mission_DW.Receive_o2.StartTime.month) - 1.0)
                    - static_cast<real_T>(wholeSecsFromMillis) * 12.0) + 1.0;
        }

        if (temp < 3.0) {
            check--;
            temp += 9.0;
        } else {
            temp -= 3.0;
        }

        da_im = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor
                     (check / 100.0)) + std::floor(check / 400.0)) + std::floor
                   ((153.0 * temp + 2.0) / 5.0)) + static_cast<real_T>
                  (codegenReal2Mission_DW.Receive_o2.StartTime.day)) + 60.0) -
            719529.0;
        temp = 1.34217729E+8 * da_im;
        temp -= temp - da_im;
        check = da_im * 8.64E+7;
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.Receive_o2.StartTime.millisecond
               < 0) | (codegenReal2Mission_DW.Receive_o2.StartTime.millisecond >=
                       1000)))) {
            wholeSecsFromMillis = static_cast<int32_T>(std::floor
                (static_cast<real_T>
                 (codegenReal2Mission_DW.Receive_o2.StartTime.millisecond) /
                 1000.0));
            second = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2.StartTime.second) +
                static_cast<real_T>(wholeSecsFromMillis);
            fracSecs = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2.StartTime.millisecond) -
                static_cast<real_T>(wholeSecsFromMillis) * 1000.0;
        }

        temp_1.re = check;
        temp_1.im = (da_im - temp) * 8.64E+7 + (temp * 8.64E+7 - check);
        temp_0 = plus_WAUOGGgr(temp_1, (60.0 * static_cast<real_T>
                                (codegenReal2Mission_DW.Receive_o2.StartTime.hour)
                                + static_cast<real_T>
                                (codegenReal2Mission_DW.Receive_o2.StartTime.minute))
                               * 60000.0);

        // Send: '<S110>/SendDanger' incorporates:
        //   Logic: '<S110>/AndSndDanger'

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                (rtb_Compare_j2) & static_cast<int32_T>(rtb_Compare_dv)))) {
            codegenReal2Mission_Receive_SendData(&rtb_CreatDanger);
        }

        // End of Send: '<S110>/SendDanger'

        // Update for Memory: '<S110>/InitMemory' incorporates:
        //   Constant: '<S126>/Constant'
        //   RelationalOperator: '<S126>/Compare'

        codegenReal2Mission_DW.InitMemory_PreviousInput = (rtb_posixTime_e < 0.0);

        // Update for UnitDelay: '<S116>/Delay Input1'
        //
        //  Block description for '<S116>/Delay Input1':
        //
        //   Store in Global RAM

        codegenReal2Mission_DW.DelayInput1_DSTATE =
            codegenReal2Mission_DW.Receive_o2.SequenceID;

        // Update for Memory: '<S110>/Memory' incorporates:
        //   Bias: '<S110>/Bias'
        //   Constant: '<S125>/Constant'
        //   Logic: '<S110>/SndAND'
        //   MATLAB Function: '<S110>/getCurrentTime'
        //   RelationalOperator: '<S110>/GreaterThanOrEqual'
        //   RelationalOperator: '<S125>/Compare'

        codegenReal2Mission_DW.Memory_PreviousInput_e = static_cast<boolean_T>(
            static_cast<int32_T>((b_this_data.re / 1000.0 + -1.0 >
            rtb_posixTime_e) & (rtb_posixTime_e >= 0.0)));

        // Update for Memory: '<S110>/MemoryPreemption' incorporates:
        //   MATLAB Function: '<S110>/Struct2PosixUplink'
        //   RelationalOperator: '<S110>/Relational Operator'

        codegenReal2Mission_DW.MemoryPreemption_PreviousInput = (rtb_posixTime_e
            > (plus_WAUOGGgr(plus_WAUOGGgr(temp_0, second * 1000.0), fracSecs)).
            re / 1000.0);

        // End of Outputs for SubSystem: '<S58>/QueueCMD'

        // Outputs for Atomic SubSystem: '<S58>/MissionValidation'
        // Outputs for Triggered SubSystem: '<S109>/TriggerMissionDispatch' incorporates:
        //   TriggerPort: '<S112>/Trigger'

        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (ANDAvoidDanger) ^ 1))) &
                (codegenReal2Mission_PrevZCX.TriggerMissionDispatch_Trig_ZCE !=
                 ZERO_ZCSIG)))) {
            MissionModes reactor_FeedbackCMD_MissionMode;

            // Outputs for Atomic SubSystem: '<S58>/QueueCMD'
            // MATLAB Function: '<S112>/CommandCheck' incorporates:
            //   DataStoreRead: '<S112>/Data Store Read'
            //   DataStoreRead: '<S112>/ReadPreviousCMD'
            //   MATLAB Function: '<S110>/Struct2PosixCurr'

            // MATLAB Function 'MissionLogic/PreProcessMissionCMD/MissionValidation/TriggerMissionDispatch/CommandCheck': '<S115>:1' 
            // '<S115>:1:6'
            processedInData[0] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.year);
            processedInData[1] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.month);

            // End of Outputs for SubSystem: '<S58>/QueueCMD'
            processedInData[2] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.day);
            processedInData[3] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.hour);
            processedInData[4] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.minute);

            // Outputs for Atomic SubSystem: '<S58>/QueueCMD'
            processedInData[5] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.second);
            processedInData[6] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive.StartTime.millisecond);

            // End of Outputs for SubSystem: '<S58>/QueueCMD'
            second = (codegenReal2Mission_createFromDateVec(processedInData)).re
                / 1000.0;
            rtb_Compare_j2 = false;
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
            codegenReal2Mission_DW.PushImmed = 0.0;
            codegenReal2Mission_DW.ImmedCMD.SequenceID = 0;
            codegenReal2Mission_DW.ImmedCMD.MissionMode = MissionModes::None;
            codegenReal2Mission_DW.ImmedCMD.MissionLocation.Lat = 0.0;
            codegenReal2Mission_DW.ImmedCMD.MissionLocation.Lon = 0.0;
            codegenReal2Mission_DW.ImmedCMD.MissionLocation.Alt = 0.0;
            codegenReal2Mission_DW.ImmedCMD.MissionLocation.degHDG = 0.0;
            codegenReal2Mission_DW.ImmedCMD.params.Param1 = 0.0F;
            codegenReal2Mission_DW.ImmedCMD.params.Param2 = 0.0F;
            codegenReal2Mission_DW.ImmedCMD.params.Param3 = 0.0F;
            codegenReal2Mission_DW.ImmedCMD.params.Param4 = 0.0F;
            codegenReal2Mission_DW.ImmedCMD.params.Param5 = 0.0F;
            codegenReal2Mission_DW.ImmedCMD.params.Param6 = 0.0F;
            codegenReal2Mission_DW.ImmedCMD.params.Param7 = 0.0F;
            codegenReal2Mission_DW.ImmedCMD.StartPosition.Lat = 0.0;
            codegenReal2Mission_DW.ImmedCMD.StartPosition.Lon = 0.0;
            codegenReal2Mission_DW.ImmedCMD.StartPosition.Alt = 0.0;
            codegenReal2Mission_DW.ImmedCMD.StartPosition.degHDG = 0.0;
            codegenReal2Mission_DW.ImmedCMD.numUAV = 0;
            codegenReal2Mission_DW.ImmedCMD.FormationPos = 0;
            codegenReal2Mission_DW.ImmedCMD.StartTime = 0.0;
            wholeSecsFromMillis = codegenReal2Mission_DW.Receive.SequenceID;
            reactor_FeedbackCMD_MissionMode =
                codegenReal2Mission_DW.Receive.MissionMode;
            rtb_FeedbackCMD.MissionLocation =
                codegenReal2Mission_DW.Receive.MissionLocation;
            rtb_FeedbackCMD.params = codegenReal2Mission_DW.Receive.params;
            rtb_FeedbackCMD.StartPosition =
                codegenReal2Mission_DW.Receive.StartPosition;
            i = codegenReal2Mission_DW.Receive.numUAV;
            i2 = codegenReal2Mission_DW.Receive.FormationPos;
            if (codegenReal2Mission_DW.Receive.MissionMode != MissionModes::
                    TuneADRC) {
                // '<S115>:1:8'
                // '<S115>:1:9'
                if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                        int32_T>(codegenReal2Mission_isequaln
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
                                  codegenReal2Mission_DW.Receive.SequenceID,
                                  codegenReal2Mission_DW.Receive.MissionMode,
                                  codegenReal2Mission_DW.Receive.MissionLocation,
                                  codegenReal2Mission_DW.Receive.params,
                                  codegenReal2Mission_DW.Receive.StartPosition,
                                  codegenReal2Mission_DW.Receive.numUAV,
                                  codegenReal2Mission_DW.Receive.FormationPos,
                                  second)) ^ 1))) {
                    if (codegenReal2Mission_DW.MissionCMD.SequenceID ==
                            codegenReal2Mission_DW.Receive.SequenceID) {
                        printf("Use a new Sequence ID for each new mission!\n");
                        fflush(stdout);
                        printf("PrevCMD SequenceID: %d\n",
                               codegenReal2Mission_DW.MissionCMD.SequenceID);
                        fflush(stdout);
                        printf("NewCMD SequenceID: %d\n",
                               codegenReal2Mission_DW.Receive.SequenceID);
                        fflush(stdout);
                    } else {
                        int32_T tmp_3;
                        int32_T tmp_4;
                        int32_T tmp_5;
                        if ((static_cast<int32_T>
                                (codegenReal2Mission_DW.Receive.MissionMode) >
                                127) && (static_cast<boolean_T>
                                         (static_cast<int32_T>
                                          (static_cast<int32_T>
                                           (isPalindrome_KPAwztvD
                                            (static_cast<real_T>
                                             (codegenReal2Mission_DW.Receive.MissionMode)))
                                           ^ 1)))) {
                            codegenReal2Mission_getLocalTime(&check, &c_tm_year
                                [5], &c_tm_year[4], &c_tm_year[3], &c_tm_year[2],
                                &c_tm_year[1], &c_tm_year[0], &rtb_Receive_o1);
                            c_tm_year[6] = check / 1.0E+6;
                            codegenReal2Mission_DW.PushImmed =
                                (codegenReal2Mission_createFromDateVec(c_tm_year))
                                .re / 1000.0 + 1.0;
                            codegenReal2Mission_DW.ImmedCMD.SequenceID =
                                codegenReal2Mission_DW.Receive.SequenceID;
                            codegenReal2Mission_DW.ImmedCMD.MissionMode =
                                codegenReal2Mission_DW.Receive.MissionMode;
                            codegenReal2Mission_DW.ImmedCMD.MissionLocation =
                                codegenReal2Mission_DW.Receive.MissionLocation;
                            codegenReal2Mission_DW.ImmedCMD.params =
                                codegenReal2Mission_DW.Receive.params;
                            codegenReal2Mission_DW.ImmedCMD.StartPosition =
                                codegenReal2Mission_DW.Receive.StartPosition;
                            codegenReal2Mission_DW.ImmedCMD.numUAV =
                                codegenReal2Mission_DW.Receive.numUAV;
                            codegenReal2Mission_DW.ImmedCMD.FormationPos =
                                codegenReal2Mission_DW.Receive.FormationPos;
                            codegenReal2Mission_DW.ImmedCMD.StartTime = second;
                        } else if (codegenReal2Mission_DW.Receive.params.Param7 ==
                                   1.0F) {
                            if (static_cast<boolean_T>(static_cast<int32_T>
                                                       ((codegenReal2Mission_DW.Receive.MissionMode
                                   == MissionModes::None) |
                                                        (codegenReal2Mission_DW.Receive.MissionMode
                                   ==
                                    codegenReal2Mission_DW.CurrentFlightMission.MissionMode))))
                            {
                                printf("Reset flight mission, cancel immediate mission!\n");
                                fflush(stdout);
                                wholeSecsFromMillis =
                                    codegenReal2Mission_DW.Receive.SequenceID;
                                reactor_FeedbackCMD_MissionMode =
                                    codegenReal2Mission_DW.CurrentFlightMission.MissionMode;
                                rtb_FeedbackCMD.MissionLocation =
                                    codegenReal2Mission_DW.Receive.MissionLocation;
                                rtb_FeedbackCMD.params =
                                    codegenReal2Mission_DW.Receive.params;
                                rtb_FeedbackCMD.StartPosition =
                                    codegenReal2Mission_DW.Receive.StartPosition;
                                i = codegenReal2Mission_DW.CurrentFlightMission.numUAV;
                                i2 =
                                    codegenReal2Mission_DW.CurrentFlightMission.FormationPos;
                                rtb_Compare_j2 = true;
                                rtb_FlightCMD.SequenceID =
                                    codegenReal2Mission_DW.Receive.SequenceID;
                                rtb_FlightCMD.MissionMode =
                                    codegenReal2Mission_DW.CurrentFlightMission.MissionMode;
                                rtb_FlightCMD.MissionLocation =
                                    codegenReal2Mission_DW.Receive.MissionLocation;
                                rtb_FlightCMD.params =
                                    codegenReal2Mission_DW.Receive.params;
                                rtb_FlightCMD.StartPosition =
                                    codegenReal2Mission_DW.Receive.StartPosition;
                                rtb_FlightCMD.numUAV =
                                    codegenReal2Mission_DW.CurrentFlightMission.numUAV;
                                rtb_FlightCMD.FormationPos =
                                    codegenReal2Mission_DW.CurrentFlightMission.FormationPos;
                                rtb_FlightCMD.StartTime = second;
                                codegenReal2Mission_getLocalTime(&check,
                                    &fracSecs, &temp, &rtb_posixTime_e, &tmp,
                                    &c_tm_mon, &rtb_Sum1_o_idx_1,
                                    &rtb_Receive_o1);
                                codegenReal2Mission_DW.ImmedCMD.SequenceID =
                                    codegenReal2Mission_DW.Receive.SequenceID;
                                codegenReal2Mission_DW.ImmedCMD.MissionLocation =
                                    codegenReal2Mission_DW.Receive.MissionLocation;
                                codegenReal2Mission_DW.ImmedCMD.params =
                                    codegenReal2Mission_DW.Receive.params;
                                codegenReal2Mission_DW.ImmedCMD.StartPosition =
                                    codegenReal2Mission_DW.Receive.StartPosition;
                                codegenReal2Mission_DW.ImmedCMD.numUAV =
                                    codegenReal2Mission_DW.CurrentFlightMission.numUAV;
                                codegenReal2Mission_DW.ImmedCMD.FormationPos =
                                    codegenReal2Mission_DW.CurrentFlightMission.FormationPos;
                                codegenReal2Mission_DW.ImmedCMD.StartTime =
                                    second;
                                codegenReal2Mission_DW.ImmedCMD.MissionMode =
                                    codegenReal2Mission_convert_to_enum_MissionModes
                                    (static_cast<int32_T>
                                     (codegenReal2Mission_DW.Receive.params.Param6));
                                codegenReal2Mission_getLocalTime(&check,
                                    &c_tm_year[5], &c_tm_year[4], &c_tm_year[3],
                                    &c_tm_year[2], &c_tm_year[1], &c_tm_year[0],
                                    &rtb_Receive_o1);
                                c_tm_year[6] = check / 1.0E+6;
                                codegenReal2Mission_DW.PushImmed =
                                    (codegenReal2Mission_createFromDateVec
                                     (c_tm_year)).re / 1000.0 + 1.0;
                            } else {
                                printf("Can not reset flight mission to a new mode!\n");
                                fflush(stdout);
                            }
                        } else {
                            codegenReal2Mission_getLocalTime(&check, &c_tm_year
                                [5], &c_tm_year[4], &c_tm_year[3], &c_tm_year[2],
                                &c_tm_year[1], &c_tm_year[0], &rtb_Receive_o1);
                            c_tm_year[6] = check / 1.0E+6;
                            if ((codegenReal2Mission_createFromDateVec(c_tm_year))
                                    .re / 1000.0 <= second) {
                                if ((static_cast<int32_T>
                                        (codegenReal2Mission_DW.Receive.MissionMode)
                                     > 10) && isPalindrome_KPAwztvD(static_cast<
                                        real_T>
                                        (codegenReal2Mission_DW.Receive.MissionMode)))
                                {
                                    rtb_Compare_j2 = true;
                                    rtb_FlightCMD.SequenceID =
                                        codegenReal2Mission_DW.Receive.SequenceID;
                                    rtb_FlightCMD.MissionMode =
                                        codegenReal2Mission_DW.Receive.MissionMode;
                                    rtb_FlightCMD.MissionLocation =
                                        codegenReal2Mission_DW.Receive.MissionLocation;
                                    rtb_FlightCMD.params =
                                        codegenReal2Mission_DW.Receive.params;
                                    rtb_FlightCMD.StartPosition =
                                        codegenReal2Mission_DW.Receive.StartPosition;
                                    rtb_FlightCMD.numUAV =
                                        codegenReal2Mission_DW.Receive.numUAV;
                                    rtb_FlightCMD.FormationPos =
                                        codegenReal2Mission_DW.Receive.FormationPos;
                                    rtb_FlightCMD.StartTime = second;
                                    codegenReal2Mission_getLocalTime(&check,
                                        &fracSecs, &temp, &rtb_posixTime_e, &tmp,
                                        &c_tm_mon, &rtb_Sum1_o_idx_1,
                                        &rtb_Receive_o1);
                                    codegenReal2Mission_DW.ImmedCMD.SequenceID =
                                        codegenReal2Mission_DW.Receive.SequenceID;
                                    codegenReal2Mission_DW.ImmedCMD.MissionLocation
                                        =
                                        codegenReal2Mission_DW.Receive.MissionLocation;
                                    codegenReal2Mission_DW.ImmedCMD.params =
                                        codegenReal2Mission_DW.Receive.params;
                                    codegenReal2Mission_DW.ImmedCMD.StartPosition
                                        =
                                        codegenReal2Mission_DW.Receive.StartPosition;
                                    codegenReal2Mission_DW.ImmedCMD.numUAV =
                                        codegenReal2Mission_DW.Receive.numUAV;
                                    codegenReal2Mission_DW.ImmedCMD.FormationPos
                                        =
                                        codegenReal2Mission_DW.Receive.FormationPos;
                                    codegenReal2Mission_DW.ImmedCMD.StartTime =
                                        second;
                                    codegenReal2Mission_DW.PushImmed = second;
                                    codegenReal2Mission_DW.ImmedCMD.MissionMode =
                                        codegenReal2Mission_convert_to_enum_MissionModes
                                        (static_cast<int32_T>
                                         (codegenReal2Mission_DW.Receive.params.Param6));
                                } else {
                                    rtb_Compare_j2 = true;
                                    rtb_FlightCMD.SequenceID =
                                        codegenReal2Mission_DW.Receive.SequenceID;
                                    rtb_FlightCMD.MissionMode =
                                        codegenReal2Mission_DW.Receive.MissionMode;
                                    rtb_FlightCMD.MissionLocation =
                                        codegenReal2Mission_DW.Receive.MissionLocation;
                                    rtb_FlightCMD.params =
                                        codegenReal2Mission_DW.Receive.params;
                                    rtb_FlightCMD.StartPosition =
                                        codegenReal2Mission_DW.Receive.StartPosition;
                                    rtb_FlightCMD.numUAV =
                                        codegenReal2Mission_DW.Receive.numUAV;
                                    rtb_FlightCMD.FormationPos =
                                        codegenReal2Mission_DW.Receive.FormationPos;
                                    rtb_FlightCMD.StartTime = second;
                                }
                            } else {
                                printf("Mission Start Time has already passed!\n");
                                fflush(stdout);
                            }
                        }

                        fracSecs = second * 1000.0;
                        codegenReal2Mission_getDateVec_o(fracSecs, &check, &temp,
                            &rtb_posixTime_e, &tmp, &c_tm_mon, &rtb_Sum1_o_idx_1);
                        codegenReal2Mission_getDateVec_o(fracSecs,
                            &rtb_posixTime_e, &temp, &tmp, &c_tm_mon,
                            &rtb_Sum1_o_idx_1, &da_im);
                        codegenReal2Mission_getDateVec_o(fracSecs, &tmp,
                            &c_tm_mon, &rtb_posixTime_e, &rtb_Sum1_o_idx_1,
                            &da_im, &a__17);
                        codegenReal2Mission_getDateVec_o(fracSecs, &c_tm_mon,
                            &rtb_Sum1_o_idx_1, &da_im, &tmp, &a__17, &a__23);
                        codegenReal2Mission_getDateVec_o(fracSecs,
                            &rtb_Sum1_o_idx_1, &da_im, &a__17, &a__23, &c_tm_mon,
                            &a__29);
                        codegenReal2Mission_getDateVec_o(fracSecs, &da_im,
                            &a__17, &a__23, &a__29, &a__35, &rtb_Sum1_o_idx_1);
                        codegenReal2Mission_getDateVec_o(fracSecs, &a__17,
                            &a__23, &a__29, &a__35, &b_a__35, &da_im);
                        codegenReal2Mission_getDateVec_o(fracSecs, &a__17,
                            &a__23, &a__29, &a__35, &b_a__35, &b_x);
                        fracSecs = std::round(check);
                        check = std::round(temp);
                        rtb_posixTime_e = std::round(rtb_posixTime_e);
                        tmp = std::round(tmp);
                        c_tm_mon = std::round(c_tm_mon);
                        rtb_Sum1_o_idx_1 = std::floor(rtb_Sum1_o_idx_1);
                        da_im = std::round((da_im - std::floor(b_x)) * 1000.0);
                        if (fracSecs < 2.147483648E+9) {
                            if (fracSecs >= -2.147483648E+9) {
                                j = static_cast<int32_T>(fracSecs);
                            } else {
                                j = MIN_int32_T;
                            }
                        } else {
                            j = MAX_int32_T;
                        }

                        if (check < 2.147483648E+9) {
                            if (check >= -2.147483648E+9) {
                                ix = static_cast<int32_T>(check);
                            } else {
                                ix = MIN_int32_T;
                            }
                        } else {
                            ix = MAX_int32_T;
                        }

                        if (rtb_posixTime_e < 2.147483648E+9) {
                            if (rtb_posixTime_e >= -2.147483648E+9) {
                                tmp_2 = static_cast<int32_T>(rtb_posixTime_e);
                            } else {
                                tmp_2 = MIN_int32_T;
                            }
                        } else {
                            tmp_2 = MAX_int32_T;
                        }

                        if (tmp < 2.147483648E+9) {
                            if (tmp >= -2.147483648E+9) {
                                tmp_6 = static_cast<int32_T>(tmp);
                            } else {
                                tmp_6 = MIN_int32_T;
                            }
                        } else {
                            tmp_6 = MAX_int32_T;
                        }

                        if (c_tm_mon < 2.147483648E+9) {
                            if (c_tm_mon >= -2.147483648E+9) {
                                tmp_3 = static_cast<int32_T>(c_tm_mon);
                            } else {
                                tmp_3 = MIN_int32_T;
                            }
                        } else {
                            tmp_3 = MAX_int32_T;
                        }

                        if (rtb_Sum1_o_idx_1 < 2.147483648E+9) {
                            if (rtb_Sum1_o_idx_1 >= -2.147483648E+9) {
                                tmp_4 = static_cast<int32_T>(rtb_Sum1_o_idx_1);
                            } else {
                                tmp_4 = MIN_int32_T;
                            }
                        } else {
                            tmp_4 = MAX_int32_T;
                        }

                        if (da_im < 2.147483648E+9) {
                            if (da_im >= -2.147483648E+9) {
                                tmp_5 = static_cast<int32_T>(da_im);
                            } else {
                                tmp_5 = MIN_int32_T;
                            }
                        } else {
                            tmp_5 = MAX_int32_T;
                        }

                        printf("Start Time:   %04d-%02d-%02d %02d:%02d:%02d.%03d\n",
                               j, ix, tmp_2, tmp_6, tmp_3, tmp_4, tmp_5);
                        fflush(stdout);
                        codegenReal2Mission_getLocalTime(&check, &c_tm_year_0[5],
                            &c_tm_year_0[4], &c_tm_year_0[3], &c_tm_year_0[2],
                            &c_tm_year_0[1], &c_tm_year_0[0], &rtb_Receive_o1);
                        c_tm_year_0[6] = check / 1.0E+6;
                        b_this_data = codegenReal2Mission_createFromDateVec
                            (c_tm_year_0);
                        codegenReal2Mission_getDateVec_oe(b_this_data, &b_x,
                            &check, &fracSecs, &temp, &rtb_posixTime_e, &tmp);
                        codegenReal2Mission_getDateVec_oe(b_this_data, &check,
                            &a__17, &fracSecs, &temp, &rtb_posixTime_e, &tmp);
                        codegenReal2Mission_getDateVec_oe(b_this_data, &check,
                            &fracSecs, &a__23, &temp, &rtb_posixTime_e, &tmp);
                        codegenReal2Mission_getDateVec_oe(b_this_data, &check,
                            &fracSecs, &temp, &a__29, &rtb_posixTime_e, &tmp);
                        codegenReal2Mission_getDateVec_oe(b_this_data, &check,
                            &fracSecs, &temp, &rtb_posixTime_e, &a__35, &tmp);
                        codegenReal2Mission_getDateVec_oe(b_this_data, &fracSecs,
                            &temp, &rtb_posixTime_e, &tmp, &c_tm_mon, &check);
                        codegenReal2Mission_getDateVec_oe(b_this_data, &temp,
                            &rtb_posixTime_e, &tmp, &c_tm_mon, &rtb_Sum1_o_idx_1,
                            &fracSecs);
                        codegenReal2Mission_getDateVec_oe(b_this_data, &temp,
                            &rtb_posixTime_e, &tmp, &c_tm_mon, &rtb_Sum1_o_idx_1,
                            &da_im);
                        printf("Current Time: %04.0f-%02.0f-%02.0f %02.0f:%02.0f:%02.0f.%03.0f\n",
                               b_x, a__17, a__23, a__29, a__35, std::floor(check),
                               std::round(1000.0 * (fracSecs - std::floor(da_im))));
                        fflush(stdout);
                    }
                }

                // '<S115>:1:10'
                rtb_FeedbackCMD.SequenceID = wholeSecsFromMillis;
                rtb_FeedbackCMD.MissionMode = reactor_FeedbackCMD_MissionMode;
                rtb_FeedbackCMD.numUAV = i;
                rtb_FeedbackCMD.FormationPos = i2;
                rtb_FeedbackCMD.StartTime = second;
            } else {
                // '<S115>:1:12'
                rtb_FeedbackCMD.SequenceID =
                    codegenReal2Mission_DW.Receive.SequenceID;
                rtb_FeedbackCMD.MissionMode =
                    codegenReal2Mission_DW.Receive.MissionMode;
                rtb_FeedbackCMD.MissionLocation =
                    codegenReal2Mission_DW.Receive.MissionLocation;
                rtb_FeedbackCMD.params = codegenReal2Mission_DW.Receive.params;
                rtb_FeedbackCMD.StartPosition =
                    codegenReal2Mission_DW.Receive.StartPosition;
                rtb_FeedbackCMD.numUAV = codegenReal2Mission_DW.Receive.numUAV;
                rtb_FeedbackCMD.FormationPos =
                    codegenReal2Mission_DW.Receive.FormationPos;
                rtb_FeedbackCMD.StartTime = second;
                codegenReal2Mission_DW.ParamADRC_e.hat_b = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive.params.Param1 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.omega_o = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive.params.Param2 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.omega_c = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive.params.Param3 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.P = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive.params.Param4 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.I = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive.params.Param5 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.D = static_cast<real_T>
                    (codegenReal2Mission_DW.Receive.params.Param6 / 100.0F);
                codegenReal2Mission_DW.ParamADRC_e.useADRC =
                    (codegenReal2Mission_DW.Receive.params.Param7 != 0.0F);

                // '<S115>:1:14'
            }

            // DataStoreWrite: '<S112>/WriteCurrentCMD'
            // '<S115>:1:27'
            // '<S115>:1:28'
            codegenReal2Mission_DW.MissionCMD = rtb_FeedbackCMD;

            // Send: '<S112>/PushCMD' incorporates:
            //   MATLAB Function: '<S112>/CommandCheck'

            if (rtb_Compare_j2) {
                codegenReal2Mission_RcvNextMission_SendData(&rtb_FlightCMD);
            }

            // End of Send: '<S112>/PushCMD'

            // Send: '<S112>/SendFeedbackMissionCMD'
            codegenReal2Mission_MessageMerge_In1_SendData(&rtb_FeedbackCMD);
        }

        codegenReal2Mission_PrevZCX.TriggerMissionDispatch_Trig_ZCE =
            static_cast<ZCSigState>(ANDAvoidDanger);

        // End of Outputs for SubSystem: '<S109>/TriggerMissionDispatch'

        // MATLAB Function: '<S109>/getCurrentTime'
        // MATLAB Function 'getCurrentTime': '<S113>:1'
        // '<S113>:1:3'
        codegenReal2Mission_getLocalTime(&check, &fracSecs, &temp,
            &rtb_posixTime_e, &tmp, &c_tm_mon, &rtb_Sum1_o_idx_1,
            &rtb_Receive_o1);
        processedInData[4] = temp;
        processedInData[5] = fracSecs;
        processedInData[6] = check / 1.0E+6;
        second = fracSecs;
        fracSecs = processedInData[6];
        check = (((((rtb_Sum1_o_idx_1 + c_tm_mon) + tmp) + rtb_posixTime_e) +
                  temp) + processedInData[5]) + processedInData[6];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(check)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(check)) ^ 1)))))) {
            check = rtb_Sum1_o_idx_1;
            temp = c_tm_mon;
            if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
                temp = std::floor((c_tm_mon - 1.0) / 12.0);
                check = rtb_Sum1_o_idx_1 + temp;
                temp = ((c_tm_mon - 1.0) - temp * 12.0) + 1.0;
            }

            if (temp < 3.0) {
                check--;
                temp += 9.0;
            } else {
                temp -= 3.0;
            }

            da_im = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor
                         (check / 100.0)) + std::floor(check / 400.0)) + std::
                       floor((153.0 * temp + 2.0) / 5.0)) + tmp) + 60.0) -
                719529.0;
            temp = 1.34217729E+8 * da_im;
            temp -= temp - da_im;
            check = da_im * 8.64E+7;
            temp_2.re = check;
            da_im = (da_im - temp) * 8.64E+7 + (temp * 8.64E+7 - check);
            temp_2.im = da_im;
            if (std::isnan(da_im)) {
                temp_2.im = 0.0;
            }

            if ((processedInData[6] < 0.0) || (processedInData[6] >= 1000.0)) {
                fracSecs = std::floor(processedInData[6] / 1000.0);
                second = processedInData[5] + fracSecs;
                fracSecs = processedInData[6] - fracSecs * 1000.0;
            }

            b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(temp_2, (60.0 * rtb_posixTime_e +
                processedInData[4]) * 60000.0), second * 1000.0), fracSecs);
        } else {
            b_this_data.re = check;
        }

        // RelationalOperator: '<S114>/Compare' incorporates:
        //   Constant: '<S114>/Constant'
        //   Logic: '<S109>/AND'
        //   MATLAB Function: '<S109>/getCurrentTime'
        //   RelationalOperator: '<S109>/Relational Operator'

        rtb_Compare_j2 = static_cast<boolean_T>(static_cast<int32_T>
            ((codegenReal2Mission_DW.PushImmed < b_this_data.re / 1000.0) &
             (codegenReal2Mission_DW.PushImmed != 0.0)));

        // Send: '<S109>/SndImmedCMD' incorporates:
        //   RelationalOperator: '<S111>/FixPt Relational Operator'
        //   UnitDelay: '<S111>/Delay Input1'
        //
        //  Block description for '<S111>/Delay Input1':
        //
        //   Store in Global RAM

        if (static_cast<int32_T>(rtb_Compare_j2) > static_cast<int32_T>
                (codegenReal2Mission_DW.DelayInput1_DSTATE_k)) {
            codegenReal2Mission_RcvImmedCMD_SendData
                (&codegenReal2Mission_DW.ImmedCMD);
        }

        // End of Send: '<S109>/SndImmedCMD'

        // Update for UnitDelay: '<S111>/Delay Input1'
        //
        //  Block description for '<S111>/Delay Input1':
        //
        //   Store in Global RAM

        codegenReal2Mission_DW.DelayInput1_DSTATE_k = rtb_Compare_j2;

        // End of Outputs for SubSystem: '<S58>/MissionValidation'
        // End of Outputs for SubSystem: '<S3>/PreProcessMissionCMD'

        // Receive: '<S3>/RcvNextMission'
        codegenReal2Mission_RcvNextMission_RecvData
            (&codegenReal2Mission_DW.RcvNextMission);

        // MATLAB Function: '<S92>/getCurrentTime'
        // MATLAB Function 'getCurrentTime': '<S98>:1'
        // '<S98>:1:3'
        codegenReal2Mission_getLocalTime(&check, &fracSecs, &temp,
            &rtb_posixTime_e, &tmp, &c_tm_mon, &rtb_Sum1_o_idx_1,
            &rtb_Receive_o1);
        processedInData[4] = temp;
        processedInData[5] = fracSecs;
        processedInData[6] = check / 1.0E+6;
        second = fracSecs;
        fracSecs = processedInData[6];
        check = (((((rtb_Sum1_o_idx_1 + c_tm_mon) + tmp) + rtb_posixTime_e) +
                  temp) + processedInData[5]) + processedInData[6];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(check)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(check)) ^ 1)))))) {
            check = rtb_Sum1_o_idx_1;
            temp = c_tm_mon;
            if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
                temp = std::floor((c_tm_mon - 1.0) / 12.0);
                check = rtb_Sum1_o_idx_1 + temp;
                temp = ((c_tm_mon - 1.0) - temp * 12.0) + 1.0;
            }

            if (temp < 3.0) {
                check--;
                temp += 9.0;
            } else {
                temp -= 3.0;
            }

            da_im = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor
                         (check / 100.0)) + std::floor(check / 400.0)) + std::
                       floor((153.0 * temp + 2.0) / 5.0)) + tmp) + 60.0) -
                719529.0;
            temp = 1.34217729E+8 * da_im;
            temp -= temp - da_im;
            check = da_im * 8.64E+7;
            temp_3.re = check;
            da_im = (da_im - temp) * 8.64E+7 + (temp * 8.64E+7 - check);
            temp_3.im = da_im;
            if (std::isnan(da_im)) {
                temp_3.im = 0.0;
            }

            if ((processedInData[6] < 0.0) || (processedInData[6] >= 1000.0)) {
                fracSecs = std::floor(processedInData[6] / 1000.0);
                second = processedInData[5] + fracSecs;
                fracSecs = processedInData[6] - fracSecs * 1000.0;
            }

            b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(temp_3, (60.0 * rtb_posixTime_e +
                processedInData[4]) * 60000.0), second * 1000.0), fracSecs);
        } else {
            b_this_data.re = check;
        }

        second = b_this_data.re / 1000.0;

        // End of MATLAB Function: '<S92>/getCurrentTime'

        // Chart: '<S92>/MisisonCMDTemporalLogic'
        // Gateway: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
        // During: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c12_codegenReal2Mission) == 0U)
        {
            // Entry: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
            codegenReal2Mission_DW.is_active_c12_codegenReal2Mission = 1U;

            // Entry Internal: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
            // Transition: '<S95>:2'
            codegenReal2Mission_DW.is_c12_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;

            // Entry 'Pending': '<S95>:1'
            codegenReal2Mission_DW.TriggerSend = 0.0;
        } else if (codegenReal2Mission_DW.is_c12_codegenReal2Mission ==
                   codegenReal2Mission_IN_Pending) {
            // During 'Pending': '<S95>:1'
            if (second >= codegenReal2Mission_DW.RcvNextMission.StartTime) {
                // Transition: '<S95>:5'
                codegenReal2Mission_DW.is_c12_codegenReal2Mission =
                    codegenReal2Mission_IN_Sending;

                // Entry 'Sending': '<S95>:3'
                codegenReal2Mission_DW.TriggerSend = 1.0;
            } else {
                codegenReal2Mission_DW.TriggerSend = 0.0;
            }

            // During 'Sending': '<S95>:3'
        } else if (second <= codegenReal2Mission_DW.RcvNextMission.StartTime) {
            // Transition: '<S95>:6'
            codegenReal2Mission_DW.is_c12_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;

            // Entry 'Pending': '<S95>:1'
            codegenReal2Mission_DW.TriggerSend = 0.0;
        }

        // End of Chart: '<S92>/MisisonCMDTemporalLogic'

        // Logic: '<S92>/AND'
        rtb_Receive_o1 = static_cast<boolean_T>(static_cast<int32_T>
            ((codegenReal2Mission_DW.TriggerSend != 0.0) &
             (codegenReal2Mission_DW.RcvNextMission.SequenceID != 0)));

        // Outputs for Triggered SubSystem: '<S92>/TriggerBroadcastAtMissionTime' incorporates:
        //   TriggerPort: '<S97>/ReachMissionTime'

        if (rtsiIsModeUpdateTimeStep(&(&codegenReal2Mission_M)->solverInfo)) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE
                   != POS_ZCSIG) & static_cast<int32_T>(rtb_Receive_o1)))) {
                // Send: '<S97>/SendMission'
                codegenReal2Mission_ReceiveCurrentMission_SendData
                    (&codegenReal2Mission_DW.RcvNextMission);
            }

            codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE =
                static_cast<ZCSigState>(rtb_Receive_o1);
        }

        // End of Outputs for SubSystem: '<S92>/TriggerBroadcastAtMissionTime'

        // Outputs for Atomic SubSystem: '<S92>/FlightMission'
        // Receive: '<S93>/ReceiveCurrentMission'
        wholeSecsFromMillis = codegenReal2Mission_ReceiveCurrentMission_RecvData
            (&codegenReal2Mission_DW.ReceiveCurrentMission_o2);
        rtb_Compare_j2 = (wholeSecsFromMillis != 1);

        // Chart: '<S93>/TriggerStartSim' incorporates:
        //   Constant: '<S100>/Constant'
        //   Constant: '<S99>/Constant'
        //   Logic: '<S93>/AND'
        //   RelationalOperator: '<S100>/Compare'
        //   RelationalOperator: '<S99>/Compare'

        // Gateway: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
        // During: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c5_codegenReal2Mission) == 0U)
        {
            // Entry: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
            codegenReal2Mission_DW.is_active_c5_codegenReal2Mission = 1U;

            // Entry Internal: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
            // Transition: '<S105>:4'
            codegenReal2Mission_DW.is_c5_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;

            // Entry 'Pending': '<S105>:3'
            codegenReal2Mission_DW.StartSim = false;
        } else if (codegenReal2Mission_DW.is_c5_codegenReal2Mission ==
                   codegenReal2Mission_IN_Pending) {
            // During 'Pending': '<S105>:3'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode
                   != MissionModes::None) &
                                        (codegenReal2Mission_DW.ReceiveCurrentMission_o2.SequenceID
                   > 0)))) {
                // Transition: '<S105>:6'
                codegenReal2Mission_DW.is_c5_codegenReal2Mission =
                    codegenReal2Mission_IN_Running;

                // Entry 'Running': '<S105>:5'
                codegenReal2Mission_DW.StartSim = true;
            } else {
                codegenReal2Mission_DW.StartSim = false;
            }
        } else {
            // During 'Running': '<S105>:5'
            codegenReal2Mission_DW.StartSim = true;
        }

        // End of Chart: '<S93>/TriggerStartSim'

        // Switch: '<S93>/Switch' incorporates:
        //   Constant: '<S93>/Constant'
        //   RelationalOperator: '<S93>/Equal'

        if (codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode ==
                MissionModes::CustomFrmnNav) {
            // Outputs for Atomic SubSystem: '<S93>/NullLoc'
            // Switch: '<S93>/Switch' incorporates:
            //   BusCreator: '<S103>/Bus Creator'
            //   Constant: '<S103>/Alt'
            //   Constant: '<S103>/Lat'
            //   Constant: '<S103>/Lon'
            //   Constant: '<S103>/degHDG'

            rtb_Switch.Lat = 0.0;
            rtb_Switch.Lon = 0.0;
            rtb_Switch.Alt = 0.0;
            rtb_Switch.degHDG = 0.0;

            // End of Outputs for SubSystem: '<S93>/NullLoc'
        } else {
            // Switch: '<S93>/Switch' incorporates:
            //   DataStoreRead: '<S93>/Data Store Read'

            rtb_Switch =
                codegenReal2Mission_DW.CurrentFlightMission.MissionLocation;
        }

        // End of Switch: '<S93>/Switch'

        // Logic: '<S93>/Reset' incorporates:
        //   Logic: '<S93>/NOT'

        rtb_Compare_dv = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((codegenReal2Mission_DW.ReceiveCurrentMission_o2.params.Param7 !=
              0.0F) ^ 1))) & static_cast<int32_T>(rtb_Compare_j2)));

        // DataTypeConversion: '<S93>/Cast To int32'
        codegenReal2Mission_DW.Reset = static_cast<int32_T>(rtb_Compare_dv);

        // Memory: '<S93>/MemoryPose'
        rtb_MemoryPose[0] = codegenReal2Mission_DW.MemoryPose_PreviousInput[0];
        rtb_MemoryPose[1] = codegenReal2Mission_DW.MemoryPose_PreviousInput[1];
        rtb_MemoryPose[2] = codegenReal2Mission_DW.MemoryPose_PreviousInput[2];
        rtb_MemoryPose[3] = codegenReal2Mission_DW.MemoryPose_PreviousInput[3];

        // ModelReference: '<S93>/PreemptableMissionModeSelector'
        FlightMissionMode(&codegenReal2Mission_DW.StartSim,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode,
                          &rtb_Switch,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionLocation,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.params,
                          &codegenReal2Mission_DW.Reset,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.FormationPos,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.numUAV,
                          &rtb_MemoryPose[0],
                          &codegenReal2Mission_DW.thisTaskStatus_g,
                          &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2,
                          &codegenReal2Mission_DW.PreemptableMissionModeSelector_o3
                          [0],
                          &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));

        // Outputs for Enabled SubSystem: '<S93>/MissionSimUAV' incorporates:
        //   EnablePort: '<S102>/Enable'

        // Outputs for Triggered SubSystem: '<S93>/FeedbackMissionCMD' incorporates:
        //   TriggerPort: '<S101>/Trigger'

        if (rtsiIsModeUpdateTimeStep(&(&codegenReal2Mission_M)->solverInfo)) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE
                   != POS_ZCSIG) & static_cast<int32_T>(rtb_Compare_j2)))) {
                // DataStoreWrite: '<S101>/Data Store Write'
                codegenReal2Mission_DW.CurrentFlightMission =
                    codegenReal2Mission_DW.ReceiveCurrentMission_o2;

                // Send: '<S101>/Send'
                codegenReal2Mission_MessageMerge_In1_SendData
                    (&codegenReal2Mission_DW.ReceiveCurrentMission_o2);
            }

            codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE =
                static_cast<ZCSigState>(rtb_Compare_j2);
            codegenReal2Mission_DW.MissionSimUAV_MODE =
                codegenReal2Mission_DW.StartSim;
        }

        // End of Outputs for SubSystem: '<S93>/FeedbackMissionCMD'
        // End of Outputs for SubSystem: '<S93>/MissionSimUAV'
        // End of Outputs for SubSystem: '<S92>/FlightMission'
        // End of Outputs for SubSystem: '<Root>/MissionLogic'
    }

    // Outputs for Atomic SubSystem: '<Root>/MissionLogic'
    // Outputs for Atomic SubSystem: '<S92>/FlightMission'
    // Outputs for Enabled SubSystem: '<S93>/MissionSimUAV' incorporates:
    //   EnablePort: '<S102>/Enable'

    if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            // DataTypeConversion: '<S102>/Cast To Double'
            codegenReal2Mission_DW.CastToDouble = static_cast<real_T>
                (rtb_Compare_dv);
        }

        // ModelReference generated from: '<S102>/MissionUavModel'
        MissionUAV(&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
                   &codegenReal2Mission_DW.CastToDouble,
                   &codegenReal2Mission_DW.PreemptableMissionModeSelector_o3[0],
                   &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2.Height,
                   &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2.AirSpeed,
                   &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2.HeadingAngle,
                   &codegenReal2Mission_DW.North, &codegenReal2Mission_DW.East,
                   &codegenReal2Mission_DW.Height,
                   &codegenReal2Mission_DW.AirSpeed,
                   &codegenReal2Mission_DW.HeadingAngle,
                   &codegenReal2Mission_DW.FlightPathAngle,
                   &codegenReal2Mission_DW.RollAngle,
                   &codegenReal2Mission_DW.RollAngleRate,
                   &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw),
                   &(codegenReal2Mission_X.MissionUavModel_CSTATE));
    }

    // End of Outputs for SubSystem: '<S93>/MissionSimUAV'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Outputs for Atomic SubSystem: '<S93>/SimState2Pose'
        // SignalConversion generated from: '<S104>/Pose' incorporates:
        //   Gain: '<S104>/Gain2'

        rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[0] =
            codegenReal2Mission_DW.North;
        rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[1] =
            codegenReal2Mission_DW.East;
        rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[2] =
            -codegenReal2Mission_DW.Height;
        rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[3] =
            codegenReal2Mission_DW.HeadingAngle;

        // End of Outputs for SubSystem: '<S93>/SimState2Pose'

        // BusCreator generated from: '<S56>/ImmedMission'
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.North
            = codegenReal2Mission_DW.North;
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.East =
            codegenReal2Mission_DW.East;
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.Height
            = codegenReal2Mission_DW.Height;
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.AirSpeed
            = codegenReal2Mission_DW.AirSpeed;
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.HeadingAngle
            = codegenReal2Mission_DW.HeadingAngle;
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.FlightPathAngle
            = codegenReal2Mission_DW.FlightPathAngle;
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.RollAngle
            = codegenReal2Mission_DW.RollAngle;
        rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.RollAngleRate
            = codegenReal2Mission_DW.RollAngleRate;

        // Receive: '<S3>/RcvImmedCMD'
        wholeSecsFromMillis = codegenReal2Mission_RcvImmedCMD_RecvData
            (&codegenReal2Mission_DW.RcvImmedCMD_o2);

        // Receive: '<S3>/RcvImmedCMD'
        rtb_Compare_dv = (wholeSecsFromMillis != 1);

        // MATLAB Function: '<S3>/RemoveNaN' incorporates:
        //   Inport: '<Root>/FlightState'
        //   RateTransition: '<Root>/Rate Transition'

        // MATLAB Function 'MissionLogic/RemoveNaN': '<S59>:1'
        // '<S59>:1:3'
        for (j = 0; j < 4096; j++) {
            x[j] = std::isnan(codegenReal2Mission_DW.RateTransition[j]);
        }

        std::memset(&y[0], 0, static_cast<uint32_T>(sizeof(boolean_T) << 10U));
        wholeSecsFromMillis = -1;
        i = 0;
        i2 = 3072;
        for (j = 0; j < 1024; j++) {
            boolean_T exitg1;
            i = static_cast<int32_T>(i + 1);
            i2 = static_cast<int32_T>(i2 + 1);
            wholeSecsFromMillis = static_cast<int32_T>(wholeSecsFromMillis + 1);
            ix = i;
            exitg1 = false;
            while ((!exitg1) && (ix <= i2)) {
                if (x[static_cast<int32_T>(ix - 1)]) {
                    y[wholeSecsFromMillis] = true;
                    exitg1 = true;
                } else {
                    ix = static_cast<int32_T>(ix + 1024);
                }
            }
        }

        i2 = 0;
        for (i = 0; i < 1024; i++) {
            rtb_Compare_j2 = static_cast<boolean_T>(static_cast<int32_T>(
                static_cast<int32_T>(y[i]) ^ 1));
            if (rtb_Compare_j2) {
                i2 = static_cast<int32_T>(i2 + 1);
            }

            y[i] = rtb_Compare_j2;
        }

        ix = i2;
        i = 0;
        for (i2 = 0; i2 < 1024; i2++) {
            if (y[i2]) {
                c_data[i] = static_cast<int16_T>(static_cast<int32_T>(i2 + 1));
                i = static_cast<int32_T>(i + 1);
            }
        }

        // '<S59>:1:3'
        // '<S59>:1:4'
        wholeSecsFromMillis = ix;
        for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++) {
            y[j] = (codegenReal2Mission_DW.RateTransition[static_cast<int32_T>(
                     static_cast<int32_T>(c_data[j]) - 1)] != static_cast<real_T>
                    (codegenReal2Mission_U.FlightState.RealUAVState.UAV_ID));
        }

        wholeSecsFromMillis = static_cast<int32_T>(ix - 1);
        i = 0;
        for (i2 = 0; i2 <= wholeSecsFromMillis; i2 = static_cast<int32_T>(i2 + 1))
        {
            if (y[i2]) {
                i = static_cast<int32_T>(i + 1);
            }
        }

        // '<S59>:1:4'
        codegenReal2Mission_DW.SFunction_DIMS2[0] = i;
        codegenReal2Mission_DW.SFunction_DIMS2[1] = 3;

        // End of MATLAB Function: '<S3>/RemoveNaN'

        // Memory: '<S3>/Memory'
        codegenReal2Mission_DW.Memory =
            codegenReal2Mission_DW.Memory_PreviousInput;

        // BusCreator: '<S54>/CreateStatusBus' incorporates:
        //   DataStoreRead: '<S54>/Data Store Read'
        //   Memory: '<S54>/MemoryFlightStatus'
        //   Memory: '<S54>/MemoryImmedStatus'
        //   Outport: '<Root>/MissionFB'

        codegenReal2Mission_Y.MissionFB.EngagedFlag =
            codegenReal2Mission_DW.Memory;
        codegenReal2Mission_Y.MissionFB.FlightStatus =
            codegenReal2Mission_DW.MemoryFlightStatus_PreviousInput;
        codegenReal2Mission_Y.MissionFB.ImmedStatus =
            codegenReal2Mission_DW.MemoryImmedStatus_PreviousInput;
        codegenReal2Mission_Y.MissionFB.SequenceID =
            codegenReal2Mission_DW.Receive_o2.SequenceID;
        codegenReal2Mission_Y.MissionFB.MissionMode =
            codegenReal2Mission_DW.CurrentFlightMission.MissionMode;
        codegenReal2Mission_Y.MissionFB.numUAV =
            codegenReal2Mission_DW.CurrentFlightMission.numUAV;
        codegenReal2Mission_Y.MissionFB.FormationPos =
            codegenReal2Mission_DW.CurrentFlightMission.FormationPos;

        // ModelReference generated from: '<S56>/ImmedMission' incorporates:
        //   Inport: '<Root>/FlightState'
        //   Outport: '<Root>/MissionFB'

        ImmedMission
            (&rtb_BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1,
             &codegenReal2Mission_DW.RcvImmedCMD_o2, &rtb_Compare_dv,
             &codegenReal2Mission_U.FlightState.RealUAVState,
             &codegenReal2Mission_DW.RcvNextMission.SequenceID,
             &codegenReal2Mission_DW.RcvNextMission.MissionMode,
             &codegenReal2Mission_DW.RcvNextMission.MissionLocation.Lat,
             &codegenReal2Mission_DW.RcvNextMission.MissionLocation.Lon,
             &codegenReal2Mission_DW.RcvNextMission.MissionLocation.Alt,
             &codegenReal2Mission_DW.RcvNextMission.MissionLocation.degHDG,
             &codegenReal2Mission_DW.RcvNextMission.params.Param3,
             &codegenReal2Mission_DW.RcvNextMission.numUAV,
             &codegenReal2Mission_DW.RcvNextMission.FormationPos,
             &codegenReal2Mission_DW.SFunction_DIMS2[0],
             &codegenReal2Mission_Y.MissionFB.MissionMode,
             &codegenReal2Mission_DW.thisTaskStatus,
             &codegenReal2Mission_DW.ImmedMission_o2,
             &codegenReal2Mission_DW.ImmedMission_o3[0],
             &codegenReal2Mission_DW.ImmedMission_o4,
             &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw),
             &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtzce));

        // Receive: '<S53>/Receive' incorporates:
        //   MATLAB Function: '<S61>/getDangerList'

        wholeSecsFromMillis = codegenReal2Mission_Receive_h_RecvData
            (&codegenReal2Mission_DW.Receive_o2_a);

        // Outputs for Enabled SubSystem: '<S53>/GenPCD' incorporates:
        //   EnablePort: '<S61>/Enable'

        if (wholeSecsFromMillis != 1) {
            boolean_T hasMismatchingDims;

            // DataStoreRead: '<S61>/LatitudeGCS'
            rtw_pthread_mutex_lock(LatitudeGCS_m0);
            second = LatitudeGCS;
            rtw_pthread_mutex_unlock(LatitudeGCS_m0);

            // DataStoreRead: '<S61>/LongitudeGCS'
            rtw_pthread_mutex_lock(LongitudeGCS_m0);
            fracSecs = LongitudeGCS;
            rtw_pthread_mutex_unlock(LongitudeGCS_m0);

            // Sum: '<S63>/Sum1' incorporates:
            //   Sum: '<S67>/Sum'

            da_im = codegenReal2Mission_DW.Receive_o2_a.DangerLoc.Lat - second;
            rtb_Sum1_o_idx_1 = codegenReal2Mission_DW.Receive_o2_a.DangerLoc.Lon
                - fracSecs;

            // Switch: '<S73>/Switch' incorporates:
            //   Abs: '<S73>/Abs'
            //   Bias: '<S73>/Bias'
            //   Bias: '<S73>/Bias1'
            //   Constant: '<S73>/Constant2'
            //   Constant: '<S74>/Constant'
            //   Math: '<S73>/Math Function1'
            //   RelationalOperator: '<S74>/Compare'

            if (std::abs(da_im) > 180.0) {
                check = rt_modd_snf(da_im + 180.0, 360.0) + -180.0;
            } else {
                check = da_im;
            }

            // End of Switch: '<S73>/Switch'

            // Abs: '<S70>/Abs1'
            fracSecs = std::abs(check);

            // Switch: '<S70>/Switch' incorporates:
            //   Bias: '<S70>/Bias'
            //   Bias: '<S70>/Bias1'
            //   Constant: '<S66>/Constant'
            //   Constant: '<S66>/Constant1'
            //   Constant: '<S72>/Constant'
            //   Gain: '<S70>/Gain'
            //   Product: '<S70>/Divide1'
            //   RelationalOperator: '<S72>/Compare'
            //   Switch: '<S66>/Switch1'

            if (fracSecs > 90.0) {
                // Signum: '<S70>/Sign1'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(std::isnan
                        (check)) ^ 1))) {
                    if (check < 0.0) {
                        check = -1.0;
                    } else {
                        check = static_cast<real_T>(check > 0.0);
                    }
                }

                // End of Signum: '<S70>/Sign1'
                check *= -(fracSecs + -90.0) + 90.0;
                i = 180;
            } else {
                i = 0;
            }

            // End of Switch: '<S70>/Switch'

            // Sum: '<S66>/Sum'
            fracSecs = static_cast<real_T>(i) + rtb_Sum1_o_idx_1;

            // Switch: '<S71>/Switch' incorporates:
            //   Abs: '<S71>/Abs'
            //   Bias: '<S71>/Bias'
            //   Bias: '<S71>/Bias1'
            //   Constant: '<S71>/Constant2'
            //   Constant: '<S75>/Constant'
            //   Math: '<S71>/Math Function1'
            //   RelationalOperator: '<S75>/Compare'

            if (std::abs(fracSecs) > 180.0) {
                fracSecs = rt_modd_snf(fracSecs + 180.0, 360.0) + -180.0;
            }

            // End of Switch: '<S71>/Switch'

            // UnitConversion: '<S69>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            da_im = 0.017453292519943295 * check;
            rtb_Sum1_o_idx_1 = 0.017453292519943295 * fracSecs;

            // UnitConversion: '<S84>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            second *= 0.017453292519943295;

            // Trigonometry: '<S85>/Trigonometric Function1'
            fracSecs = std::sin(second);

            // Sum: '<S85>/Sum1' incorporates:
            //   Constant: '<S85>/Constant'
            //   Product: '<S85>/Product1'

            fracSecs = 1.0 - 0.0066943799901413295 * fracSecs * fracSecs;

            // Product: '<S83>/Product1' incorporates:
            //   Constant: '<S83>/Constant1'
            //   Sqrt: '<S83>/sqrt'

            check = 6.378137E+6 / std::sqrt(fracSecs);

            // Product: '<S68>/dNorth' incorporates:
            //   Constant: '<S83>/Constant2'
            //   Product: '<S83>/Product3'
            //   Trigonometry: '<S83>/Trigonometric Function1'

            fracSecs = da_im / rt_atan2d_snf(1.0, check * 0.99330562000985867 /
                fracSecs);

            // Product: '<S68>/dEast' incorporates:
            //   Constant: '<S83>/Constant3'
            //   Product: '<S83>/Product4'
            //   Trigonometry: '<S83>/Trigonometric Function'
            //   Trigonometry: '<S83>/Trigonometric Function2'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            check = 1.0 / rt_atan2d_snf(1.0, check * std::cos(second)) *
                rtb_Sum1_o_idx_1;

            // SignalConversion generated from: '<S61>/Vector Concatenate' incorporates:
            //   Product: '<S68>/x*cos'
            //   Product: '<S68>/x*sin'
            //   Product: '<S68>/y*cos'
            //   Product: '<S68>/y*sin'
            //   Sum: '<S68>/Sum2'
            //   Sum: '<S68>/Sum3'

            rtb_MemoryPose[1] = check * 0.0 + fracSecs;
            rtb_MemoryPose[2] = check - fracSecs * 0.0;

            // DataTypeConversion: '<S61>/DangerID'
            rtb_MemoryPose[0] = static_cast<real_T>
                (codegenReal2Mission_DW.Receive_o2_a.DangerID);

            // DataTypeConversion: '<S61>/DangerRadius'
            rtb_MemoryPose[3] = codegenReal2Mission_DW.Receive_o2_a.Radius;

            // MATLAB Function: '<S61>/sizeconversion'
            // MATLAB Function 'MissionLogic/DangerLidarScanPoints/GenPCD/sizeconversion': '<S65>:1' 
            // '<S65>:1:3'
            codegenReal2Mission_DW.SFunction_DIMS2_h[0] = 1;
            codegenReal2Mission_DW.SFunction_DIMS2_h[1] = 4;

            // MATLAB Function: '<S61>/getDangerList'
            // MATLAB Function 'MissionLogic/DangerLidarScanPoints/GenPCD/getDangerList': '<S64>:1' 
            // '<S64>:1:3'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (codegenReal2Mission_DW.localObj_not_empty) ^ 1))) {
                codegenReal2Mission_DW.localObj.DangerList->size[0] = 0;
                codegenReal2Mission_DW.localObj.DangerList->size[1] = 4;
                codegenReal2Mission_DW.localObj_not_empty = true;
            }

            rtb_Compare_j2 = (codegenReal2Mission_DW.SFunction_DIMS2_h[1] == 1);
            ANDAvoidDanger = (codegenReal2Mission_DW.SFunction_DIMS2_h[1] == 0);
            hasMismatchingDims = false;
            if (ANDAvoidDanger) {
                hasMismatchingDims = (codegenReal2Mission_DW.SFunction_DIMS2_h[1]
                                      != 4);
            }

            if (rtb_Compare_j2) {
                fileid = 1;
            } else {
                fileid = static_cast<int8_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(ANDAvoidDanger) ^
                    1))) | static_cast<int32_T>(static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(hasMismatchingDims)
                    ^ 1)))))));
            }

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(ANDAvoidDanger) ^ 1))) &
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(rtb_Compare_j2) ^
                     1)))))) {
                if (static_cast<int32_T>(fileid) != 1) {
                    sprintf(&st[0], "%d", 0);
                }

                if (codegenReal2Mission_DW.SFunction_DIMS2_h[1] != 4) {
                    codegenReal2Mission_int2str(static_cast<real_T>
                        (codegenReal2Mission_DW.SFunction_DIMS2_h[1]),
                        SFunction_DIMS2_h.data, SFunction_DIMS2_h.size);
                }
            }

            if (rtb_Compare_j2) {
                i = static_cast<int32_T>(fileid);
                wholeSecsFromMillis = static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(fileid) << 2) - 1);
                for (j = 0; j <= wholeSecsFromMillis; j++) {
                    obj2_DangerList_data[j] = rtb_MemoryPose[0];
                }
            } else {
                i = static_cast<int32_T>(fileid);
                wholeSecsFromMillis = static_cast<int32_T>(static_cast<int32_T>(
                    static_cast<int32_T>(fileid) << 2) - 1);
                for (j = 0; j <= wholeSecsFromMillis; j++) {
                    obj2_DangerList_data[j] = rtb_MemoryPose[j];
                }
            }

            tmp_2 = static_cast<int32_T>(g->size[0] * g->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            g->size[0] = static_cast<int32_T>
                (codegenReal2Mission_DW.localObj.DangerList->size[0] + i);
            g->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(g, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis =
                codegenReal2Mission_DW.localObj.DangerList->size[0];
            for (j = 0; j < 4; j++) {
                for (ix = 0; ix <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                     ix++) {
                    g->data[static_cast<int32_T>(ix + static_cast<int32_T>
                        (g->size[0] * j))] =
                        codegenReal2Mission_DW.localObj.DangerList->data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (codegenReal2Mission_DW.localObj.DangerList->size[0] * j)
                        + ix)];
                }
            }

            wholeSecsFromMillis = i;
            for (j = 0; j < 4; j++) {
                for (ix = 0; ix <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                     ix++) {
                    g->data[static_cast<int32_T>
                        (codegenReal2Mission_DW.localObj.DangerList->size[0] +
                         static_cast<int32_T>(g->size[0] * j))] =
                        obj2_DangerList_data[static_cast<int32_T>(i * j)];
                }
            }

            codegenReal2Mission_emxInit_real_T(&outputArg_DangerList, 2);
            tmp_2 = static_cast<int32_T>(outputArg_DangerList->size[0] *
                outputArg_DangerList->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            outputArg_DangerList->size[0] = g->size[0];
            outputArg_DangerList->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(outputArg_DangerList,
                tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>(g->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                outputArg_DangerList->data[j] = g->data[j];
            }

            tmp_2 = static_cast<int32_T>(g->size[0] * g->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            g->size[0] = outputArg_DangerList->size[0];
            g->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(g, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>
                (outputArg_DangerList->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                g->data[j] = outputArg_DangerList->data[j];
            }

            codegenReal2Mission_flipud(g);
            tmp_2 = static_cast<int32_T>(outputArg_DangerList->size[0] *
                outputArg_DangerList->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            outputArg_DangerList->size[0] = g->size[0];
            outputArg_DangerList->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(outputArg_DangerList,
                tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>(g->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                outputArg_DangerList->data[j] = g->data[j];
            }

            tmp_2 = static_cast<int32_T>(g->size[0] * g->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            g->size[0] = outputArg_DangerList->size[0];
            g->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(g, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>
                (outputArg_DangerList->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                g->data[j] = outputArg_DangerList->data[j];
            }

            tmp_2 = static_cast<int32_T>(outputArg_DangerList->size[0] *
                outputArg_DangerList->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            outputArg_DangerList->size[0] = g->size[0];
            outputArg_DangerList->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(outputArg_DangerList,
                tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>(g->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                outputArg_DangerList->data[j] = g->data[j];
            }

            codegenReal2Mission_emxInit_real_T(&outputArg_DangerList_0, 1);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = outputArg_DangerList->size[0];
            tmp_2 = outputArg_DangerList_0->size[0];

            // MATLAB Function: '<S61>/getDangerList'
            outputArg_DangerList_0->size[0] = outputArg_DangerList->size[0];
            codegenReal2Mission_emxEnsureCapacity_real_T(outputArg_DangerList_0,
                tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                outputArg_DangerList_0->data[j] = outputArg_DangerList->data[j];
            }

            codegenReal2Mission_emxInit_real_T(&a__1, 1);
            codegenReal2Mission_emxInit_int32_T(&indx, 1);
            codegenReal2Mission_emxInit_int32_T(&ipos, 1);

            // MATLAB Function: '<S61>/getDangerList'
            codegenReal2Mission_unique_vector(outputArg_DangerList_0, a__1, indx,
                ipos);
            tmp_2 = static_cast<int32_T>(g->size[0] * g->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            g->size[0] = indx->size[0];
            g->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(g, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = indx->size[0];
            codegenReal2Mission_emxFree_int32_T(&ipos);

            // MATLAB Function: '<S61>/getDangerList'
            for (j = 0; j < 4; j++) {
                for (ix = 0; ix <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                     ix++) {
                    g->data[static_cast<int32_T>(ix + static_cast<int32_T>
                        (g->size[0] * j))] = outputArg_DangerList->data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(outputArg_DangerList->size[0] * j)
                         + indx->data[ix]) - 1)];
                }
            }

            codegenReal2Mission_emxFree_int32_T(&indx);
            tmp_2 = static_cast<int32_T>(outputArg_DangerList->size[0] *
                outputArg_DangerList->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            outputArg_DangerList->size[0] = g->size[0];
            outputArg_DangerList->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(outputArg_DangerList,
                tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>(g->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                outputArg_DangerList->data[j] = g->data[j];
            }

            tmp_2 = static_cast<int32_T>(g->size[0] * g->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            g->size[0] = outputArg_DangerList->size[0];
            g->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(g, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>
                (outputArg_DangerList->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                g->data[j] = outputArg_DangerList->data[j];
            }

            codegenReal2Mission_flipud(g);
            tmp_2 = static_cast<int32_T>(outputArg_DangerList->size[0] *
                outputArg_DangerList->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            outputArg_DangerList->size[0] = g->size[0];
            outputArg_DangerList->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(outputArg_DangerList,
                tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>(g->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                outputArg_DangerList->data[j] = g->data[j];
            }

            tmp_2 = static_cast<int32_T>(g->size[0] * g->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            g->size[0] = outputArg_DangerList->size[0];
            g->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(g, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>
                (outputArg_DangerList->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                g->data[j] = outputArg_DangerList->data[j];
            }

            tmp_2 = static_cast<int32_T>(outputArg_DangerList->size[0] *
                outputArg_DangerList->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            outputArg_DangerList->size[0] = g->size[0];
            outputArg_DangerList->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(outputArg_DangerList,
                tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>(g->size[0] << 2);
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                outputArg_DangerList->data[j] = g->data[j];
            }

            codegenReal2Mission_emxInit_boolean_T(&b, 1);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = outputArg_DangerList->size[0];
            tmp_2 = b->size[0];

            // MATLAB Function: '<S61>/getDangerList'
            b->size[0] = outputArg_DangerList->size[0];
            codegenReal2Mission_emxEnsureCapacity_boolean_T(b, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1); j++)
            {
                b->data[j] = (outputArg_DangerList->data[static_cast<int32_T>(
                               static_cast<int32_T>(outputArg_DangerList->size[0]
                                * 3) + j)] != 0.0);
            }

            wholeSecsFromMillis = static_cast<int32_T>(b->size[0] - 1);
            i2 = 0;
            for (i = 0; i <= wholeSecsFromMillis; i = static_cast<int32_T>(i + 1))
            {
                if (b->data[i]) {
                    i2 = static_cast<int32_T>(i2 + 1);
                }
            }

            codegenReal2Mission_emxInit_int32_T(&c, 1);
            tmp_2 = c->size[0];

            // MATLAB Function: '<S61>/getDangerList'
            c->size[0] = i2;
            codegenReal2Mission_emxEnsureCapacity_int32_T(c, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            i = 0;
            for (i2 = 0; i2 <= wholeSecsFromMillis; i2 = static_cast<int32_T>(i2
                  + 1)) {
                if (b->data[i2]) {
                    c->data[i] = static_cast<int32_T>(i2 + 1);
                    i = static_cast<int32_T>(i + 1);
                }
            }

            codegenReal2Mission_emxFree_boolean_T(&b);
            tmp_2 = static_cast<int32_T>(g->size[0] * g->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            g->size[0] = c->size[0];
            g->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T(g, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = c->size[0];
            for (j = 0; j < 4; j++) {
                for (ix = 0; ix <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                     ix++) {
                    g->data[static_cast<int32_T>(ix + static_cast<int32_T>
                        (g->size[0] * j))] = outputArg_DangerList->data[
                        static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<int32_T>(outputArg_DangerList->size[0] * j)
                         + c->data[ix]) - 1)];
                }
            }

            codegenReal2Mission_emxFree_int32_T(&c);
            codegenReal2Mission_emxFree_real_T(&outputArg_DangerList);
            tmp_2 = static_cast<int32_T>
                (codegenReal2Mission_DW.localObj.DangerList->size[0] *
                 codegenReal2Mission_DW.localObj.DangerList->size[1]);

            // MATLAB Function: '<S61>/getDangerList'
            codegenReal2Mission_DW.localObj.DangerList->size[0] = g->size[0];
            codegenReal2Mission_DW.localObj.DangerList->size[1] = 4;
            codegenReal2Mission_emxEnsureCapacity_real_T
                (codegenReal2Mission_DW.localObj.DangerList, tmp_2);

            // MATLAB Function: '<S61>/getDangerList'
            wholeSecsFromMillis = static_cast<int32_T>(g->size[0] << 2);
            for (ix = 0; ix <= static_cast<int32_T>(wholeSecsFromMillis - 1); ix
                    ++) {
                codegenReal2Mission_DW.localObj.DangerList->data[ix] = g->
                    data[ix];
            }

            // '<S64>:1:4'
            codegenReal2Mission_DW.SFunction_DIMS2_p[0] =
                codegenReal2Mission_DW.localObj.DangerList->size[0];
            codegenReal2Mission_DW.SFunction_DIMS2_p[1] = 4;

            // Selector: '<S61>/SelectNorthEastRadius' incorporates:
            //   MATLAB Function: '<S61>/getDangerList'

            codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0] =
                codegenReal2Mission_DW.SFunction_DIMS2_p[0];
            codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[1] = 3;
            wholeSecsFromMillis = codegenReal2Mission_DW.SFunction_DIMS2_p[0];
            for (j = 0; j < 3; j++) {
                for (ix = 0; ix <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                     ix++) {
                    codegenReal2Mission_DW.SelectNorthEastRadius
                        [static_cast<int32_T>(ix + static_cast<int32_T>
                        (codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0] *
                         j))] = codegenReal2Mission_DW.localObj.DangerList->
                        data[static_cast<int32_T>(static_cast<int32_T>(
                        static_cast<int32_T>(j + 1) *
                        codegenReal2Mission_DW.localObj.DangerList->size[0]) +
                        ix)];
                }
            }

            // End of Selector: '<S61>/SelectNorthEastRadius'

            // MATLAB Function: '<S61>/InterpCircle'
            // MATLAB Function 'MissionLogic/DangerLidarScanPoints/GenPCD/InterpCircle': '<S62>:1' 
            // '<S62>:1:2'
            codegenReal2Mission_DW.SFunction_DIMS2_e[0] = 0;
            codegenReal2Mission_DW.SFunction_DIMS2_e[1] = 2;

            // '<S62>:1:5'
            i = 0;
            codegenReal2Mission_emxInit_real_T(&varargin_2, 2);
            codegenReal2Mission_emxInit_real_T(&theta, 2);
            codegenReal2Mission_emxInit_real_T(&b_b, 1);
            codegenReal2Mission_emxInit_real_T(&tmp_0, 2);
            codegenReal2Mission_emxInit_real_T(&second_0, 2);

            // MATLAB Function: '<S61>/InterpCircle' incorporates:
            //   Selector: '<S61>/SelectNorthEastRadius'

            while (i <= static_cast<int32_T>
                    (codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0] - 1))
            {
                // '<S62>:1:5'
                // '<S62>:1:6'
                second = codegenReal2Mission_DW.SelectNorthEastRadius[
                    static_cast<int32_T>(static_cast<int32_T>
                    (codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0] << 1)
                    + i)];

                // '<S62>:1:16'
                check = std::ceil(360.0 / (3.0 / second * 57.295779513082323));
                if (static_cast<boolean_T>(static_cast<int32_T>((check >= 0.0) ^
                      1))) {
                    theta->size[0] = 1;
                    theta->size[1] = 0;
                } else {
                    tmp_2 = static_cast<int32_T>(theta->size[0] * theta->size[1]);
                    theta->size[0] = 1;
                    theta->size[1] = static_cast<int32_T>(check);
                    codegenReal2Mission_emxEnsureCapacity_real_T(theta, tmp_2);
                    if (static_cast<int32_T>(check) >= 1) {
                        theta->data[static_cast<int32_T>(static_cast<int32_T>
                            (check) - 1)] = 6.2831853071795862;
                        if (theta->size[1] >= 2) {
                            theta->data[0] = 0.0;
                            if (theta->size[1] >= 3) {
                                check = 6.2831853071795862 / (static_cast<real_T>
                                    (theta->size[1]) - 1.0);
                                i2 = theta->size[1];
                                for (wholeSecsFromMillis = 0;
                                        wholeSecsFromMillis <=
                                        static_cast<int32_T>(i2 - 3);
                                        wholeSecsFromMillis =
                                        static_cast<int32_T>(wholeSecsFromMillis
                                      + 1)) {
                                    theta->data[static_cast<int32_T>
                                        (wholeSecsFromMillis + 1)] = (
                                        static_cast<real_T>(wholeSecsFromMillis)
                                        + 1.0) * check;
                                }
                            }
                        }
                    }
                }

                // '<S62>:1:17'
                tmp_2 = a__1->size[0];
                a__1->size[0] = theta->size[1];
                codegenReal2Mission_emxEnsureCapacity_real_T(a__1, tmp_2);
                wholeSecsFromMillis = theta->size[1];
                for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                        j++) {
                    a__1->data[j] = theta->data[j];
                }

                tmp_2 = outputArg_DangerList_0->size[0];
                outputArg_DangerList_0->size[0] = a__1->size[0];
                codegenReal2Mission_emxEnsureCapacity_real_T
                    (outputArg_DangerList_0, tmp_2);
                wholeSecsFromMillis = a__1->size[0];
                for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                        j++) {
                    outputArg_DangerList_0->data[j] = a__1->data[j];
                }

                for (wholeSecsFromMillis = 1; static_cast<int32_T>
                        (wholeSecsFromMillis - 1) <= static_cast<int32_T>
                        (a__1->size[0] - 1); wholeSecsFromMillis =
                        static_cast<int32_T>(wholeSecsFromMillis + 1)) {
                    outputArg_DangerList_0->data[static_cast<int32_T>
                        (wholeSecsFromMillis - 1)] = std::cos
                        (outputArg_DangerList_0->data[static_cast<int32_T>
                         (wholeSecsFromMillis - 1)]);
                }

                tmp_2 = b_b->size[0];
                b_b->size[0] = a__1->size[0];
                codegenReal2Mission_emxEnsureCapacity_real_T(b_b, tmp_2);
                wholeSecsFromMillis = a__1->size[0];
                for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                        j++) {
                    b_b->data[j] = a__1->data[j];
                }

                for (wholeSecsFromMillis = 1; static_cast<int32_T>
                        (wholeSecsFromMillis - 1) <= static_cast<int32_T>
                        (a__1->size[0] - 1); wholeSecsFromMillis =
                        static_cast<int32_T>(wholeSecsFromMillis + 1)) {
                    b_b->data[static_cast<int32_T>(wholeSecsFromMillis - 1)] =
                        std::sin(b_b->data[static_cast<int32_T>
                                 (wholeSecsFromMillis - 1)]);
                }

                tmp_2 = static_cast<int32_T>(second_0->size[0] * second_0->size
                    [1]);
                second_0->size[0] = outputArg_DangerList_0->size[0];
                second_0->size[1] = 2;
                codegenReal2Mission_emxEnsureCapacity_real_T(second_0, tmp_2);
                wholeSecsFromMillis = outputArg_DangerList_0->size[0];
                for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                        j++) {
                    second_0->data[j] = second * outputArg_DangerList_0->data[j];
                }

                wholeSecsFromMillis = b_b->size[0];
                for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                        j++) {
                    second_0->data[static_cast<int32_T>(j +
                        outputArg_DangerList_0->size[0])] = second * b_b->data[j];
                }

                tmp_data[0] = codegenReal2Mission_DW.SelectNorthEastRadius[i];
                tmp_data[1] = codegenReal2Mission_DW.SelectNorthEastRadius[
                    static_cast<int32_T>(i +
                    codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0])];
                tmp_2 = static_cast<int32_T>(varargin_2->size[0] *
                    varargin_2->size[1]);
                varargin_2->size[0] = second_0->size[0];
                varargin_2->size[1] = 2;
                codegenReal2Mission_emxEnsureCapacity_real_T(varargin_2, tmp_2);
                wholeSecsFromMillis = second_0->size[0];
                for (j = 0; j < 2; j++) {
                    for (ix = 0; ix <= static_cast<int32_T>(wholeSecsFromMillis
                            - 1); ix++) {
                        varargin_2->data[static_cast<int32_T>(ix +
                            static_cast<int32_T>(varargin_2->size[0] * j))] =
                            second_0->data[static_cast<int32_T>
                            (static_cast<int32_T>(second_0->size[0] * j) + ix)]
                            + tmp_data[j];
                    }
                }

                // '<S62>:1:11'
                if (codegenReal2Mission_DW.SFunction_DIMS2_e[0] != 0) {
                    tmp_6 = codegenReal2Mission_DW.SFunction_DIMS2_e[0];
                } else {
                    tmp_6 = 0;
                }

                if (varargin_2->size[0] != 0) {
                    i2 = varargin_2->size[0];
                } else {
                    i2 = 0;
                }

                tmp_2 = static_cast<int32_T>(tmp_0->size[0] * tmp_0->size[1]);
                tmp_0->size[0] = static_cast<int32_T>(tmp_6 + i2);
                tmp_0->size[1] = 2;
                codegenReal2Mission_emxEnsureCapacity_real_T(tmp_0, tmp_2);
                wholeSecsFromMillis = tmp_6;
                for (j = 0; j < 2; j++) {
                    for (ix = 0; ix <= static_cast<int32_T>(wholeSecsFromMillis
                            - 1); ix++) {
                        tmp_0->data[static_cast<int32_T>(ix +
                            static_cast<int32_T>(tmp_0->size[0] * j))] =
                            codegenReal2Mission_DW.PointCloud
                            [static_cast<int32_T>(static_cast<int32_T>(tmp_6 * j)
                            + ix)];
                    }
                }

                for (j = 0; j < 2; j++) {
                    for (ix = 0; ix <= static_cast<int32_T>(i2 - 1); ix++) {
                        tmp_0->data[static_cast<int32_T>(static_cast<int32_T>(ix
                            + tmp_6) + static_cast<int32_T>(tmp_0->size[0] * j))]
                            = varargin_2->data[static_cast<int32_T>(static_cast<
                            int32_T>(varargin_2->size[0] * j) + ix)];
                    }
                }

                codegenReal2Mission_DW.SFunction_DIMS2_e[0] = tmp_0->size[0];
                codegenReal2Mission_DW.SFunction_DIMS2_e[1] = 2;
                wholeSecsFromMillis = static_cast<int32_T>(tmp_0->size[0] << 1);
                for (j = 0; j <= static_cast<int32_T>(wholeSecsFromMillis - 1);
                        j++) {
                    codegenReal2Mission_DW.PointCloud[j] = tmp_0->data[j];
                }

                i = static_cast<int32_T>(i + 1);
            }

            codegenReal2Mission_emxFree_real_T(&second_0);
            codegenReal2Mission_emxFree_real_T(&outputArg_DangerList_0);
            codegenReal2Mission_emxFree_real_T(&tmp_0);
            codegenReal2Mission_emxFree_real_T(&b_b);
            codegenReal2Mission_emxFree_real_T(&theta);
            codegenReal2Mission_emxFree_real_T(&varargin_2);
            codegenReal2Mission_emxFree_real_T(&a__1);

            // DataStoreRead: '<S61>/AltitudeGCS'
            rtw_pthread_mutex_lock(AltitudeGCS_m0);
            rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        }

        // End of Receive: '<S53>/Receive'
        // End of Outputs for SubSystem: '<S53>/GenPCD'

        // Chart: '<S92>/NewMission'
        // Gateway: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
        wholeSecsFromMillis = codegenReal2Mission_DW.followSwitch_start;
        codegenReal2Mission_DW.followSwitch_start =
            codegenReal2Mission_DW.RcvNextMission.SequenceID;

        // During: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c14_codegenReal2Mission) == 0U)
        {
            // Entry: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
            codegenReal2Mission_DW.is_active_c14_codegenReal2Mission = 1U;

            // Entry Internal: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
            // Transition: '<S96>:3'
            codegenReal2Mission_DW.is_c14_codegenReal2Mission =
                codegenReal2Mission_IN_Enter;

            // Entry 'Enter': '<S96>:2'
            codegenReal2Mission_DW.NewMission = false;
        } else {
            switch (codegenReal2Mission_DW.is_c14_codegenReal2Mission) {
              case codegenReal2Mission_IN_Enter:
                codegenReal2Mission_DW.NewMission = false;

                // During 'Enter': '<S96>:2'
                if (wholeSecsFromMillis !=
                        codegenReal2Mission_DW.followSwitch_start) {
                    // Transition: '<S96>:4'
                    codegenReal2Mission_DW.is_c14_codegenReal2Mission =
                        codegenReal2Mission_IN_Wait;
                }
                break;

              case codegenReal2Mission_IN_New:
                // During 'New': '<S96>:9'
                // Transition: '<S96>:10'
                codegenReal2Mission_DW.is_c14_codegenReal2Mission =
                    codegenReal2Mission_IN_Enter;

                // Entry 'Enter': '<S96>:2'
                codegenReal2Mission_DW.NewMission = false;
                break;

              default:
                // During 'Wait': '<S96>:6'
                if (rtb_Receive_o1) {
                    // Transition: '<S96>:7'
                    codegenReal2Mission_DW.is_c14_codegenReal2Mission =
                        codegenReal2Mission_IN_New;

                    // Entry 'New': '<S96>:9'
                    codegenReal2Mission_DW.NewMission = true;
                }
                break;
            }
        }

        // End of Chart: '<S92>/NewMission'

        // Logic: '<S54>/OR'
        codegenReal2Mission_DW.OR = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(rtb_Compare_dv) | static_cast<int32_T>
            (codegenReal2Mission_DW.NewMission)));

        // Receive: '<S54>/ReceiveThisMission'
        wholeSecsFromMillis = codegenReal2Mission_ReceiveThisMission_RecvData
            (&codegenReal2Mission_DW.ReceiveThisMission_o2);
        rtb_Compare_j2 = (wholeSecsFromMillis != 1);

        // Outputs for Triggered SubSystem: '<S54>/TriggerCurrentMisisonFeedback' incorporates:
        //   TriggerPort: '<S88>/Trigger'

        if (rtsiIsModeUpdateTimeStep(&(&codegenReal2Mission_M)->solverInfo)) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE
                   != POS_ZCSIG) & static_cast<int32_T>(rtb_Compare_j2)))) {
                // MATLAB Function: '<S88>/TimeConverter'
                // MATLAB Function 'MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/TimeConverter': '<S90>:1' 
                // '<S90>:1:3'
                second = codegenReal2Mission_DW.ReceiveThisMission_o2.StartTime *
                    1000.0;
                codegenReal2Mission_getDateVec_g(second, &check, &temp,
                    &rtb_posixTime_e, &tmp, &c_tm_mon, &rtb_Sum1_o_idx_1);
                codegenReal2Mission_getDateVec_g(second, &rtb_posixTime_e, &temp,
                    &tmp, &c_tm_mon, &rtb_Sum1_o_idx_1, &da_im);
                codegenReal2Mission_getDateVec_g(second, &tmp, &c_tm_mon,
                    &rtb_posixTime_e, &rtb_Sum1_o_idx_1, &da_im, &a__17);
                codegenReal2Mission_getDateVec_g(second, &c_tm_mon,
                    &rtb_Sum1_o_idx_1, &da_im, &tmp, &a__17, &a__23);
                codegenReal2Mission_getDateVec_g(second, &rtb_Sum1_o_idx_1,
                    &da_im, &a__17, &a__23, &c_tm_mon, &a__29);
                codegenReal2Mission_getDateVec_g(second, &da_im, &a__17, &a__23,
                    &a__29, &a__35, &rtb_Sum1_o_idx_1);
                codegenReal2Mission_getDateVec_g(second, &a__17, &a__23, &a__29,
                    &a__35, &b_a__35, &da_im);
                codegenReal2Mission_getDateVec_g(second, &a__17, &a__23, &a__29,
                    &a__35, &b_a__35, &b_x);

                // BusCreator: '<S88>/IndivCMD'
                codegenReal2Mission_DW.IndivCMD.SequenceID =
                    codegenReal2Mission_DW.ReceiveThisMission_o2.SequenceID;
                codegenReal2Mission_DW.IndivCMD.MissionMode =
                    codegenReal2Mission_DW.ReceiveThisMission_o2.MissionMode;
                codegenReal2Mission_DW.IndivCMD.MissionLocation =
                    codegenReal2Mission_DW.ReceiveThisMission_o2.MissionLocation;
                codegenReal2Mission_DW.IndivCMD.params =
                    codegenReal2Mission_DW.ReceiveThisMission_o2.params;
                codegenReal2Mission_DW.IndivCMD.StartPosition =
                    codegenReal2Mission_DW.ReceiveThisMission_o2.StartPosition;
                codegenReal2Mission_DW.IndivCMD.numUAV =
                    codegenReal2Mission_DW.ReceiveThisMission_o2.numUAV;
                codegenReal2Mission_DW.IndivCMD.FormationPos =
                    codegenReal2Mission_DW.ReceiveThisMission_o2.FormationPos;

                // MATLAB Function: '<S88>/TimeConverter'
                fracSecs = std::round(check);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.year =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.year =
                            MIN_int32_T;
                    }
                } else {
                    // BusCreator: '<S88>/IndivCMD'
                    codegenReal2Mission_DW.IndivCMD.StartTime.year = MAX_int32_T;
                }

                fracSecs = std::round(temp);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.month =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.month =
                            MIN_int32_T;
                    }
                } else {
                    // BusCreator: '<S88>/IndivCMD'
                    codegenReal2Mission_DW.IndivCMD.StartTime.month =
                        MAX_int32_T;
                }

                fracSecs = std::round(rtb_posixTime_e);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.day =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.day =
                            MIN_int32_T;
                    }
                } else {
                    // BusCreator: '<S88>/IndivCMD'
                    codegenReal2Mission_DW.IndivCMD.StartTime.day = MAX_int32_T;
                }

                fracSecs = std::round(tmp);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.hour =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.hour =
                            MIN_int32_T;
                    }
                } else {
                    // BusCreator: '<S88>/IndivCMD'
                    codegenReal2Mission_DW.IndivCMD.StartTime.hour = MAX_int32_T;
                }

                fracSecs = std::round(c_tm_mon);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                            MIN_int32_T;
                    }
                } else {
                    // BusCreator: '<S88>/IndivCMD'
                    codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                        MAX_int32_T;
                }

                fracSecs = std::floor(rtb_Sum1_o_idx_1);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.second =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.second =
                            MIN_int32_T;
                    }
                } else {
                    // BusCreator: '<S88>/IndivCMD'
                    codegenReal2Mission_DW.IndivCMD.StartTime.second =
                        MAX_int32_T;
                }

                fracSecs = std::round((da_im - std::floor(b_x)) * 1000.0);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        // BusCreator: '<S88>/IndivCMD'
                        codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                            MIN_int32_T;
                    }
                } else {
                    // BusCreator: '<S88>/IndivCMD'
                    codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                        MAX_int32_T;
                }

                // MATLAB Function: '<S88>/PrintOnboardLog'
                // MATLAB Function 'MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/PrintOnboardLog': '<S89>:1' 
                // '<S89>:1:3'
                fileid = codegenReal2Mission_cfopen("OnboardMissionCMD.log",
                    "ab");

                // '<S89>:1:4'
                codegenReal2Mission_printIndivMissionCMD
                    (codegenReal2Mission_DW.IndivCMD.SequenceID,
                     codegenReal2Mission_DW.IndivCMD.MissionMode,
                     codegenReal2Mission_DW.IndivCMD.MissionLocation.Lat,
                     codegenReal2Mission_DW.IndivCMD.MissionLocation.Lon,
                     codegenReal2Mission_DW.IndivCMD.MissionLocation.Alt,
                     codegenReal2Mission_DW.IndivCMD.MissionLocation.degHDG,
                     codegenReal2Mission_DW.IndivCMD.params.Param1,
                     codegenReal2Mission_DW.IndivCMD.params.Param2,
                     codegenReal2Mission_DW.IndivCMD.params.Param3,
                     codegenReal2Mission_DW.IndivCMD.params.Param4,
                     codegenReal2Mission_DW.IndivCMD.params.Param5,
                     codegenReal2Mission_DW.IndivCMD.params.Param6,
                     codegenReal2Mission_DW.IndivCMD.params.Param7,
                     codegenReal2Mission_DW.IndivCMD.StartPosition,
                     codegenReal2Mission_DW.IndivCMD.numUAV,
                     codegenReal2Mission_DW.IndivCMD.FormationPos,
                     codegenReal2Mission_DW.IndivCMD.StartTime,
                     static_cast<real_T>(fileid));

                // '<S89>:1:5'
                codegenReal2Mission_cfclose(static_cast<real_T>(fileid));

                // Send: '<S88>/Send'
                CurrentMissionSendData.SendData(&codegenReal2Mission_DW.IndivCMD,
                    sizeof(IndividualUAVCmd), &status_0);
            }

            codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
                static_cast<ZCSigState>(rtb_Compare_j2);
        }

        // End of Outputs for SubSystem: '<S54>/TriggerCurrentMisisonFeedback'

        // DataTypeConversion: '<S54>/intFlightStatus'
        fracSecs = std::floor(codegenReal2Mission_DW.thisTaskStatus_g);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(fracSecs)) | static_cast<int32_T>(std::isinf(fracSecs)))))
        {
            fracSecs = 0.0;
        } else {
            fracSecs = std::fmod(fracSecs, 4.294967296E+9);
        }

        // DataTypeConversion: '<S54>/intFlightStatus'
        rtb_intFlightStatus = fracSecs < 0.0 ? static_cast<int32_T>(-
            static_cast<int32_T>(static_cast<uint32_T>(-fracSecs))) :
            static_cast<int32_T>(static_cast<uint32_T>(fracSecs));

        // DataTypeConversion: '<S54>/intImmedStatus'
        fracSecs = std::floor(codegenReal2Mission_DW.thisTaskStatus);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(fracSecs)) | static_cast<int32_T>(std::isinf(fracSecs)))))
        {
            fracSecs = 0.0;
        } else {
            fracSecs = std::fmod(fracSecs, 4.294967296E+9);
        }

        // DataTypeConversion: '<S54>/intImmedStatus'
        rtb_intImmedStatus = fracSecs < 0.0 ? static_cast<int32_T>
            (-static_cast<int32_T>(static_cast<uint32_T>(-fracSecs))) :
            static_cast<int32_T>(static_cast<uint32_T>(fracSecs));

        // Outputs for Atomic SubSystem: '<S92>/JumpDelay'
        // Outputs for Atomic SubSystem: '<S94>/ComputDelay'
        // Switch: '<S106>/AllPositivePosSwitch' incorporates:
        //   DataTypeConversion: '<S106>/doubleFormPos'
        //   DataTypeConversion: '<S106>/doubleNumUAV'
        //   Sum: '<S106>/Minus'

        if (codegenReal2Mission_DW.RcvNextMission.FormationPos > 0) {
            fracSecs = static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.FormationPos);
        } else {
            fracSecs = static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.numUAV) -
                static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.FormationPos);
        }

        // End of Switch: '<S106>/AllPositivePosSwitch'

        // Product: '<S106>/DivideThree' incorporates:
        //   Bias: '<S106>/Bias'
        //   Constant: '<S106>/Three'
        //   Math: '<S106>/ModThree'
        //   Product: '<S106>/DivideByThree'
        //   Rounding: '<S106>/idxCeil'

        codegenReal2Mission_DW.DivideThree = (rt_modd_snf(std::ceil(fracSecs /
            3.0), 3.0) + 1.0) / 3.0;

        // End of Outputs for SubSystem: '<S94>/ComputDelay'
        // End of Outputs for SubSystem: '<S92>/JumpDelay'

        // RateTransition: '<Root>/RTLLA'
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
        j = static_cast<int32_T>(static_cast<int32_T>(fileid) * 3);
        codegenReal2Mission_DW.RTLLA_Buf[j] = rtb_AltitudeGCS_o;
        codegenReal2Mission_DW.RTLLA_Buf[static_cast<int32_T>(j + 1)] =
            rtb_LatitudeGCS_i;
        codegenReal2Mission_DW.RTLLA_Buf[static_cast<int32_T>(j + 2)] =
            rtb_LongitudeGCS_h;
        codegenReal2Mission_DW.RTLLA_LstBufWR = fileid;

        // End of RateTransition: '<Root>/RTLLA'
    }

    // End of Outputs for SubSystem: '<S92>/FlightMission'
    // End of Outputs for SubSystem: '<Root>/MissionLogic'

    // Outputs for Atomic SubSystem: '<Root>/TrackingControl'
    // ModelReference generated from: '<S129>/Real2SimGuidance' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read'
    //   Inport: '<Root>/FlightMode'
    //   Inport: '<Root>/FlightState'
    //   Outport: '<Root>/FlightCMD'

    Real2SimGuidance(&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
                     &codegenReal2Mission_DW.OR,
                     &codegenReal2Mission_U.FlightMode,
                     &codegenReal2Mission_U.FlightState,
                     &codegenReal2Mission_DW.ImmedMission_o3[0],
                     &codegenReal2Mission_DW.ImmedMission_o2,
                     &codegenReal2Mission_DW.ImmedMission_o4,
                     &codegenReal2Mission_DW.DivideThree,
                     &codegenReal2Mission_DW.ParamADRC_e.hat_b,
                     &codegenReal2Mission_DW.ParamADRC_e.omega_o,
                     &codegenReal2Mission_DW.ParamADRC_e.omega_c,
                     &codegenReal2Mission_DW.ParamADRC_e.P,
                     &codegenReal2Mission_DW.ParamADRC_e.I,
                     &codegenReal2Mission_DW.ParamADRC_e.D,
                     &codegenReal2Mission_DW.ParamADRC_e.useADRC,
                     &codegenReal2Mission_DW.PointCloud[0],
                     &codegenReal2Mission_DW.SFunction_DIMS2_e[0],
                     &codegenReal2Mission_DW.SelectNorthEastRadius[0],
                     &codegenReal2Mission_DW.SelectNorthEastRadius_DIMS1[0],
                     &codegenReal2Mission_Y.FlightCMD,
                     &codegenReal2Mission_DW.EngagedFlag_Log,
                     &codegenReal2Mission_DW.Real2SimGuidance_o3,
                     &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
                     &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Send: '<S4>/SendLog'
        FlightLogSendData.SendData(&codegenReal2Mission_DW.Real2SimGuidance_o3,
            sizeof(FlightLogging), &status);

        // Update for Atomic SubSystem: '<Root>/MissionLogic'
        // Update for Atomic SubSystem: '<S92>/FlightMission'
        // Update for Memory: '<S93>/MemoryPose'
        codegenReal2Mission_DW.MemoryPose_PreviousInput[0] =
            rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[0];
        codegenReal2Mission_DW.MemoryPose_PreviousInput[1] =
            rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[1];
        codegenReal2Mission_DW.MemoryPose_PreviousInput[2] =
            rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[2];
        codegenReal2Mission_DW.MemoryPose_PreviousInput[3] =
            rtb_BufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0[3];

        // Update for ModelReference: '<S93>/PreemptableMissionModeSelector'
        FlightMissionMode_Update
            (&(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));

        // End of Update for SubSystem: '<S92>/FlightMission'
        // End of Update for SubSystem: '<Root>/MissionLogic'
    }

    // End of Outputs for SubSystem: '<Root>/TrackingControl'

    // Update for Atomic SubSystem: '<Root>/MissionLogic'
    // Update for Atomic SubSystem: '<S92>/FlightMission'
    // Update for Enabled SubSystem: '<S93>/MissionSimUAV' incorporates:
    //   EnablePort: '<S102>/Enable'

    if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
        // Update for ModelReference generated from: '<S102>/MissionUavModel'
        MissionUAV_Update
            (&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw));
    }

    // End of Update for SubSystem: '<S93>/MissionSimUAV'
    // End of Update for SubSystem: '<S92>/FlightMission'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Update for Memory: '<S3>/Memory'
        codegenReal2Mission_DW.Memory_PreviousInput =
            codegenReal2Mission_DW.EngagedFlag_Log;

        // Update for Memory: '<S54>/MemoryFlightStatus'
        codegenReal2Mission_DW.MemoryFlightStatus_PreviousInput =
            rtb_intFlightStatus;

        // Update for Memory: '<S54>/MemoryImmedStatus'
        codegenReal2Mission_DW.MemoryImmedStatus_PreviousInput =
            rtb_intImmedStatus;

        // Update for ModelReference generated from: '<S56>/ImmedMission'
        ImmedMission_Update(&codegenReal2Mission_DW.Memory,
                            &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw));
    }

    // End of Update for SubSystem: '<Root>/MissionLogic'

    // Update for Atomic SubSystem: '<Root>/TrackingControl'
    // Update for ModelReference generated from: '<S129>/Real2SimGuidance'
    Real2SimGuidance_Update
        (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
         &codegenReal2Mission_DW.OR, &codegenReal2Mission_DW.ImmedMission_o2,
         &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw));

    // End of Update for SubSystem: '<Root>/TrackingControl'
    codegenReal2Mission_emxFree_real_T(&g);
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output 
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
                    (&(&codegenReal2Mission_M)->solverInfo)) {
                rtsiSetSimTimeStep(&(&codegenReal2Mission_M)->solverInfo,
                                   MINOR_TIME_STEP);
                rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
                    (&(&codegenReal2Mission_M)->solverInfo, false);
                codegenReal2MissionModelClass::step();
                rtsiSetSimTimeStep(&(&codegenReal2Mission_M)->solverInfo,
                                   MAJOR_TIME_STEP);
            }
        }
    }                                  // end MajorTimeStep

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        rt_ertODEUpdateContinuousStates(&(&codegenReal2Mission_M)->solverInfo);

        // Update absolute time for base rate
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

        {
            // Update absolute timer for sample time: [0.1s, 0.0s]
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
        }
    }                                  // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void codegenReal2MissionModelClass::codegenReal2Mission_derivatives()
{
    // Derivatives for Atomic SubSystem: '<Root>/MissionLogic'
    // Derivatives for Atomic SubSystem: '<S92>/FlightMission'
    // Derivatives for Enabled SubSystem: '<S93>/MissionSimUAV'
    if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
        // Derivatives for ModelReference generated from: '<S102>/MissionUavModel' 
        MissionUAV_Deriv(&codegenReal2Mission_DW.CastToDouble,
                         &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw),
                         &(((XDot_codegenReal2Mission_T *)
                            (&codegenReal2Mission_M)->derivs)
                           ->MissionUavModel_CSTATE));
    } else {
        {
            real_T *dx;
            int_T i;
            dx = (real_T *) &(((XDot_codegenReal2Mission_T *)
                               (&codegenReal2Mission_M)->derivs)
                              ->MissionUavModel_CSTATE);
            for (i=0; i < 10; i++) {
                dx[i] = 0.0;
            }
        }
    }

    // End of Derivatives for SubSystem: '<S93>/MissionSimUAV'
    // End of Derivatives for SubSystem: '<S92>/FlightMission'
    // End of Derivatives for SubSystem: '<Root>/MissionLogic'

    // Derivatives for Atomic SubSystem: '<Root>/TrackingControl'
    // Derivatives for ModelReference generated from: '<S129>/Real2SimGuidance'
    Real2SimGuidance_Deriv
        (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
         &(((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs)
           ->Real2SimGuidance_CSTATE));

    // End of Derivatives for SubSystem: '<Root>/TrackingControl'
}

// Model step function
void codegenReal2MissionModelClass::codegenReal2Mission_PushNbrUAV() // Explicit Task: PushNbrUAV 
{
    RealUAVStateBus b;
    real_T rtb_VectorConcatenate_f[9];
    real_T rtb_Reshape[4];
    real_T rtb_sincos_o1[3];
    real_T RTLLA_idx_0;
    real_T RTLLA_idx_1;
    real_T RTLLA_idx_2;
    real_T Receive_f;
    real_T b_data_0;
    int32_T x[2];
    int32_T i;
    int32_T j;
    int32_T s13_iter{ 1 };

    int32_T s5_iter;
    int16_T b_data[1024];
    int16_T ii_data_idx_0;
    int8_T ii_data;
    boolean_T c[1024];

    // RateTransition: '<Root>/RTLLA'
    rtw_pthread_mutex_lock(codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);
    codegenReal2Mission_DW.RTLLA_RDBuf = codegenReal2Mission_DW.RTLLA_LstBufWR;
    rtw_pthread_mutex_unlock(codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);
    j = static_cast<int32_T>(static_cast<int32_T>
        (codegenReal2Mission_DW.RTLLA_RDBuf) * 3);

    // RateTransition: '<Root>/RTLLA'
    RTLLA_idx_0 = codegenReal2Mission_DW.RTLLA_Buf[j];
    RTLLA_idx_1 = codegenReal2Mission_DW.RTLLA_Buf[static_cast<int32_T>(j + 1)];
    RTLLA_idx_2 = codegenReal2Mission_DW.RTLLA_Buf[static_cast<int32_T>(j + 2)];

    // RootInportFunctionCallGenerator generated from: '<Root>/PushNbrUAV' incorporates:
    //   SubSystem: '<Root>/DeSerOtherUAV'

    // Outputs for Iterator SubSystem: '<S1>/While Iterator Serializer' incorporates:
    //   WhileIterator: '<S5>/While Iterator'

    s5_iter = 1;
    boolean_T rtb_Receive_o1;
    do {
        real_T SW;
        real_T rtb_Abs1;
        real_T rtb_Abs1_e;
        real_T rtb_Gain1_c;
        real_T rtb_Gain1_h;
        real_T rtb_HorizSpd;
        real_T rtb_Switch_b;
        real_T rtb_dEast;
        boolean_T exitg1;
        boolean_T rtb_rcv;
        if (s5_iter == 1) {
            for (i = 0; i < 4096; i++) {
                codegenReal2Mission_DW.CatPos[i] = (rtNaN);
            }
        }

        s13_iter = 1;
        NbrUAVstateRecvData.RecvData(&codegenReal2Mission_DW.Receive_o2_j,
            sizeof(RealUAVStateBus), &s13_iter);
        if (s13_iter == 1) {
            std::memset(&codegenReal2Mission_DW.Receive_o2_j, 0, sizeof
                        (RealUAVStateBus));
        }

        rtb_Receive_o1 = (s13_iter != 1);
        if (rtb_Receive_o1) {
            codegenReal2Mission_Receive_c_SendData((const_cast<real_T*>
                (&codegenReal2Mission_RGND)));

            // MATLAB Function 'DeSerOtherUAV/While Iterator Serializer/WriteBuff/WriteBuff': '<S52>:1' 
            // '<S52>:1:5'
            s13_iter = codegenReal2Mission_DW.MsgBuff[0].UAV_ID;
            Receive_f = codegenReal2Mission_DW.MsgBuff[0].Latitude_deg;
            rtb_dEast = codegenReal2Mission_DW.MsgBuff[0].Longitude_deg;
            rtb_HorizSpd = codegenReal2Mission_DW.MsgBuff[0].Height_meter;
            rtb_Gain1_c = codegenReal2Mission_DW.MsgBuff[0].Altitude_meter;
            rtb_Abs1_e = codegenReal2Mission_DW.MsgBuff[0].AirSpeed_mps;
            rtb_Gain1_h = codegenReal2Mission_DW.MsgBuff[0].GndSpd_mps;
            rtb_Abs1 = codegenReal2Mission_DW.MsgBuff[0].HeadingAngle_deg;
            SW = codegenReal2Mission_DW.MsgBuff[0].FlightPathAngle_deg;
            rtb_Switch_b = codegenReal2Mission_DW.MsgBuff[0].RollAngle_deg;
            codegenReal2Mission_DW.MsgBuff[0] = codegenReal2Mission_DW.MsgBuff[1];
            codegenReal2Mission_DW.MsgBuff[1].UAV_ID = s13_iter;
            codegenReal2Mission_DW.MsgBuff[1].Latitude_deg = Receive_f;
            codegenReal2Mission_DW.MsgBuff[1].Longitude_deg = rtb_dEast;
            codegenReal2Mission_DW.MsgBuff[1].Height_meter = rtb_HorizSpd;
            codegenReal2Mission_DW.MsgBuff[1].Altitude_meter = rtb_Gain1_c;
            codegenReal2Mission_DW.MsgBuff[1].AirSpeed_mps = rtb_Abs1_e;
            codegenReal2Mission_DW.MsgBuff[1].GndSpd_mps = rtb_Gain1_h;
            codegenReal2Mission_DW.MsgBuff[1].HeadingAngle_deg = rtb_Abs1;
            codegenReal2Mission_DW.MsgBuff[1].FlightPathAngle_deg = SW;
            codegenReal2Mission_DW.MsgBuff[1].RollAngle_deg = rtb_Switch_b;

            // '<S52>:1:7'
            codegenReal2Mission_DW.MsgBuff[0] =
                codegenReal2Mission_DW.Receive_o2_j;
        }

        // MATLAB Function 'DeSerOtherUAV/While Iterator Serializer/testUniq': '<S11>:1' 
        // '<S11>:1:3'
        j = 0;
        for (i = 0; i < 1024; i++) {
            rtb_rcv = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(std::isnan(codegenReal2Mission_DW.CatPos[i]))
                 ^ 1));
            if (rtb_rcv) {
                j = static_cast<int32_T>(j + 1);
            }

            c[i] = rtb_rcv;
        }

        s13_iter = 0;
        for (i = 0; i < 1024; i++) {
            if (c[i]) {
                b_data[s13_iter] = static_cast<int16_T>(static_cast<int32_T>(i +
                    1));
                s13_iter = static_cast<int32_T>(s13_iter + 1);
            }
        }

        // '<S11>:1:3'
        rtb_rcv = false;
        s13_iter = 0;
        exitg1 = false;
        while ((!exitg1) && (s13_iter <= static_cast<int32_T>(j - 1))) {
            if (codegenReal2Mission_DW.CatPos[static_cast<int32_T>
                    (static_cast<int32_T>(b_data[s13_iter]) - 1)] ==
                    static_cast<real_T>
                    (codegenReal2Mission_DW.Receive_o2_j.UAV_ID)) {
                rtb_rcv = true;
                exitg1 = true;
            } else {
                s13_iter = static_cast<int32_T>(s13_iter + 1);
            }
        }

        rtb_Receive_o1 = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(rtb_rcv) ^ 1))) & static_cast<int32_T>
            (rtb_Receive_o1)));
        if (rtb_Receive_o1) {
            codegenReal2Mission_Receive_RecvData(&Receive_f);
            s13_iter = 1;
            b.UAV_ID = 0;
            b.Latitude_deg = 0.0;
            b.Longitude_deg = 0.0;
            b.Height_meter = 0.0;
            b.Altitude_meter = 0.0;
            b.AirSpeed_mps = 0.0;
            b.GndSpd_mps = 0.0;
            b.HeadingAngle_deg = 0.0;
            b.FlightPathAngle_deg = 0.0;
            b.RollAngle_deg = 0.0;
            int32_T b_ii;
            int32_T ii_size_idx_1;
            do {
                real_T rtb_Sum_b;
                real_T rtb_VectorConcatenate_f_tmp;
                real_T rtb_VectorConcatenate_f_tmp_0;
                real_T rtb_sincos_o1_j;

                // MATLAB Function 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ReadBuff': '<S18>:1' 
                // '<S18>:1:5'
                x[0] = codegenReal2Mission_DW.MsgBuff[0].UAV_ID;
                x[1] = codegenReal2Mission_DW.MsgBuff[1].UAV_ID;
                j = 0;
                ii_size_idx_1 = 1;
                b_ii = 2;
                exitg1 = false;
                while ((!exitg1) && (b_ii > 0)) {
                    if (x[static_cast<int32_T>(b_ii - 1)] != 0) {
                        j = 1;
                        ii_data = static_cast<int8_T>(b_ii);
                        exitg1 = true;
                    } else {
                        b_ii = static_cast<int32_T>(b_ii - 1);
                    }
                }

                if (j == 0) {
                    ii_size_idx_1 = 0;
                    i = 0;
                    rtb_Abs1_e = 0.0;
                    rtb_dEast = 0.0;
                    Receive_f = 0.0;
                    rtb_HorizSpd = 0.0;
                    SW = 0.0;
                    rtb_Gain1_h = 0.0;
                    rtb_Gain1_c = 0.0;

                    // '<S18>:1:10'
                    // '<S18>:1:15'
                    rtb_rcv = false;
                } else {
                    // '<S18>:1:6'
                    // '<S18>:1:7'
                    i = codegenReal2Mission_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].UAV_ID;
                    rtb_Abs1_e = codegenReal2Mission_DW.MsgBuff
                        [static_cast<int32_T>(static_cast<int32_T>(ii_data) - 1)]
                        .Latitude_deg;
                    rtb_dEast = codegenReal2Mission_DW.MsgBuff
                        [static_cast<int32_T>(static_cast<int32_T>(ii_data) - 1)]
                        .Longitude_deg;
                    Receive_f = codegenReal2Mission_DW.MsgBuff
                        [static_cast<int32_T>(static_cast<int32_T>(ii_data) - 1)]
                        .Height_meter;
                    rtb_HorizSpd = codegenReal2Mission_DW.MsgBuff
                        [static_cast<int32_T>(static_cast<int32_T>(ii_data) - 1)]
                        .AirSpeed_mps;
                    SW = codegenReal2Mission_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].HeadingAngle_deg;
                    rtb_Gain1_h = codegenReal2Mission_DW.MsgBuff
                        [static_cast<int32_T>(static_cast<int32_T>(ii_data) - 1)]
                        .FlightPathAngle_deg;
                    rtb_Gain1_c = codegenReal2Mission_DW.MsgBuff
                        [static_cast<int32_T>(static_cast<int32_T>(ii_data) - 1)]
                        .RollAngle_deg;

                    // '<S18>:1:8'
                    rtb_rcv = true;
                }

                // '<S18>:1:18'
                if (static_cast<int32_T>(ii_size_idx_1 - 1) >= 0) {
                    codegenReal2Mission_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)] = b;
                }

                rtb_Gain1_h *= 0.017453292519943295;
                rtb_Gain1_c *= 0.017453292519943295;
                if (std::abs(RTLLA_idx_0) > 180.0) {
                    rtb_Switch_b = rt_modd_snf(RTLLA_idx_0 + 180.0, 360.0) +
                        -180.0;
                } else {
                    rtb_Switch_b = RTLLA_idx_0;
                }

                rtb_Abs1 = std::abs(rtb_Switch_b);
                if (rtb_Abs1 > 90.0) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(std::isnan(rtb_Switch_b)) ^ 1))) {
                        if (rtb_Switch_b < 0.0) {
                            rtb_Switch_b = -1.0;
                        } else {
                            rtb_Switch_b = static_cast<real_T>(rtb_Switch_b >
                                0.0);
                        }
                    }

                    rtb_Switch_b *= -(rtb_Abs1 + -90.0) + 90.0;
                    j = 180;
                } else {
                    j = 0;
                }

                rtb_Abs1 = static_cast<real_T>(j) + RTLLA_idx_1;
                if (std::abs(rtb_Abs1) > 180.0) {
                    rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                rtb_Abs1_e -= rtb_Switch_b;
                rtb_dEast -= rtb_Abs1;
                if (std::abs(rtb_Abs1_e) > 180.0) {
                    rtb_Abs1 = rt_modd_snf(rtb_Abs1_e + 180.0, 360.0) + -180.0;
                } else {
                    rtb_Abs1 = rtb_Abs1_e;
                }

                rtb_Abs1_e = std::abs(rtb_Abs1);
                if (rtb_Abs1_e > 90.0) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(std::isnan(rtb_Abs1)) ^ 1))) {
                        if (rtb_Abs1 < 0.0) {
                            rtb_Abs1 = -1.0;
                        } else {
                            rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                        }
                    }

                    rtb_Abs1 *= -(rtb_Abs1_e + -90.0) + 90.0;
                    j = 180;
                } else {
                    j = 0;
                }

                rtb_Sum_b = static_cast<real_T>(j) + rtb_dEast;
                if (std::abs(rtb_Sum_b) > 180.0) {
                    rtb_Sum_b = rt_modd_snf(rtb_Sum_b + 180.0, 360.0) + -180.0;
                }

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch_b *= 0.017453292519943295;
                rtb_dEast = std::sin(rtb_Switch_b);
                rtb_dEast = 1.0 - 0.0066943799901413295 * rtb_dEast * rtb_dEast;
                rtb_Abs1_e = 6.378137E+6 / std::sqrt(rtb_dEast);
                rtb_Switch_b = rtb_Abs1_e * std::cos(rtb_Switch_b);

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Abs1_e = 0.017453292519943295 * rtb_Abs1 / rt_atan2d_snf(1.0,
                    rtb_Abs1_e * 0.99330562000985867 / rtb_dEast);
                rtb_dEast = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_b) *
                    (0.017453292519943295 * rtb_Sum_b);
                rtb_sincos_o1[0] = 0.017453292519943295 * SW;
                SW = std::cos(rtb_sincos_o1[0]);
                rtb_Switch_b = std::sin(rtb_sincos_o1[0]);
                rtb_Sum_b = std::cos(rtb_Gain1_h);
                rtb_Gain1_h = std::sin(rtb_Gain1_h);
                rtb_Abs1 = std::cos(rtb_Gain1_c);
                rtb_sincos_o1_j = std::sin(rtb_Gain1_c);
                rtb_VectorConcatenate_f[0] = SW * rtb_Sum_b;
                rtb_VectorConcatenate_f_tmp = rtb_Gain1_h * rtb_sincos_o1_j;
                rtb_VectorConcatenate_f[1] = rtb_VectorConcatenate_f_tmp * SW -
                    rtb_Switch_b * rtb_Abs1;
                rtb_VectorConcatenate_f_tmp_0 = rtb_Gain1_h * rtb_Abs1;
                rtb_VectorConcatenate_f[2] = rtb_VectorConcatenate_f_tmp_0 * SW
                    + rtb_Switch_b * rtb_sincos_o1_j;
                rtb_VectorConcatenate_f[3] = rtb_Switch_b * rtb_Sum_b;
                rtb_VectorConcatenate_f[4] = rtb_VectorConcatenate_f_tmp *
                    rtb_Switch_b + SW * rtb_Abs1;
                rtb_VectorConcatenate_f[5] = rtb_VectorConcatenate_f_tmp_0 *
                    rtb_Switch_b - SW * rtb_sincos_o1_j;
                rtb_VectorConcatenate_f[6] = -rtb_Gain1_h;
                rtb_VectorConcatenate_f[7] = rtb_Sum_b * rtb_sincos_o1_j;
                rtb_VectorConcatenate_f[8] = rtb_Sum_b * rtb_Abs1;
                j = 0;
                for (b_ii = 0; b_ii < 3; b_ii++) {
                    rtb_sincos_o1[b_ii] = 0.0;
                    rtb_sincos_o1[b_ii] += rtb_VectorConcatenate_f[j] *
                        rtb_HorizSpd;
                    rtb_sincos_o1[b_ii] += rtb_VectorConcatenate_f
                        [static_cast<int32_T>(j + 1)] * 0.0;
                    rtb_sincos_o1[b_ii] += rtb_VectorConcatenate_f
                        [static_cast<int32_T>(j + 2)] * 0.0;
                    j = static_cast<int32_T>(j + 3);
                }

                rtb_HorizSpd *= rtb_Sum_b;
                if (rtb_HorizSpd > 0.0) {
                    codegenReal2Mission_DW.Omega = 1.0 / rtb_HorizSpd * (9.81 *
                        std::tan(rtb_Gain1_c));
                }

                rtb_Abs1 = -(Receive_f + -RTLLA_idx_2);

                // MATLAB Function 'ConstTurnPredState/MATLAB Function': '<S20>:1' 
                // '<S20>:1:2'
                rtb_Gain1_c = 57.295779513082323 * codegenReal2Mission_DW.Omega;

                // '<S20>:1:4'
                Receive_f = std::fmax(std::abs(0.017453292519943295 *
                                       rtb_Gain1_c), 2.2204460492503131E-16);
                j = 0;
                if (rtb_Gain1_c < 0.0) {
                    j = 1;
                }

                if (static_cast<int32_T>(j - 1) >= 0) {
                    b_data_0 = -Receive_f;
                }

                rtb_HorizSpd = Receive_f;
                if (rtb_Gain1_c < 0.0) {
                    rtb_HorizSpd = b_data_0;
                }

                Receive_f = std::sin(rtb_HorizSpd);
                SW = Receive_f / rtb_HorizSpd;
                rtb_Gain1_h = (1.0 - std::cos(rtb_HorizSpd)) / rtb_HorizSpd;

                // '<S20>:1:5'
                rtb_Reshape[0] = static_cast<real_T>(i);
                rtb_Reshape[1] = ((rtb_dEast * 0.0 + rtb_Abs1_e) + SW *
                                  rtb_sincos_o1[0]) - rtb_Gain1_h *
                    rtb_sincos_o1[1];
                rtb_Reshape[2] = ((rtb_dEast - rtb_Abs1_e * 0.0) + rtb_Gain1_h *
                                  rtb_sincos_o1[0]) + SW * rtb_sincos_o1[1];
                rtb_Reshape[3] = -(rtb_Abs1 + rtb_sincos_o1[2]);

                // MATLAB Function 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConcatenateUAVPos': '<S14>:1' 
                // '<S14>:1:8'
                // '<S14>:1:5'
                // '<S14>:1:6'
                if (static_cast<int32_T>(1 - static_cast<int32_T>
                                         (static_cast<boolean_T>
                                          (static_cast<int32_T>
                                           ((static_cast<real_T>(i) != 0.0) ^ 1))))
                    >= 1) {
                    // '<S14>:1:7'
                    for (j = 0; j < 1024; j++) {
                        c[j] = std::isnan(codegenReal2Mission_DW.CatPos[j]);
                    }

                    b_ii = 0;
                    exitg1 = false;
                    while ((!exitg1) && (b_ii < 1024)) {
                        if (c[b_ii]) {
                            ii_data_idx_0 = static_cast<int16_T>(static_cast<
                                int32_T>(b_ii + 1));
                            exitg1 = true;
                        } else {
                            b_ii = static_cast<int32_T>(b_ii + 1);
                        }
                    }

                    // '<S14>:1:8'
                    for (j = 0; j < 4; j++) {
                        codegenReal2Mission_DW.CatPos[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<int32_T>
                            (ii_data_idx_0) + static_cast<int32_T>(j << 10)) - 1)]
                            = rtb_Reshape[j];
                    }
                }

                // MATLAB Function 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/PrintNbrID/PrintNbrID': '<S51>:1' 
                if (i != 0) {
                    // '<S51>:1:3'
                    // '<S51>:1:4'
                    printf("UAV%i", i);
                    fflush(stdout);
                }

                s13_iter = static_cast<int32_T>(s13_iter + 1);
            } while (static_cast<boolean_T>(static_cast<int32_T>((s13_iter <= 5)
                       & static_cast<int32_T>(rtb_rcv))));
        }

        rtb_rcv = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(rtb_Receive_o1) ^ 1));
        for (i = 0; i < 4096; i++) {
            if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                    (rtb_rcv) > static_cast<int32_T>
                    (codegenReal2Mission_DW.DelayInput1_DSTATE_d)) |
                    static_cast<int32_T>(rtb_Receive_o1)))) {
                codegenReal2Mission_DW.Switch_m[i] =
                    codegenReal2Mission_DW.CatPos[i];
            } else {
                codegenReal2Mission_DW.Switch_m[i] = (rtNaN);
            }
        }

        codegenReal2Mission_DW.DelayInput1_DSTATE_d = rtb_rcv;
        s5_iter = static_cast<int32_T>(s5_iter + 1);
    } while (static_cast<boolean_T>(static_cast<int32_T>((s5_iter <= 1024) &
                    static_cast<int32_T>(rtb_Receive_o1))));

    // End of Outputs for SubSystem: '<S1>/While Iterator Serializer'
    // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PushNbrUAV' 

    // RateTransition: '<Root>/Rate Transition' incorporates:
    //   Switch: '<S5>/Switch'

    rtw_pthread_mutex_lock(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
    ii_data = static_cast<int8_T>(static_cast<int32_T>(static_cast<int32_T>
        (codegenReal2Mission_DW.RateTransition_LstBufWR) + 1));
    if (static_cast<int32_T>(ii_data) == 3) {
        ii_data = 0;
    }

    if (static_cast<int32_T>(ii_data) == static_cast<int32_T>
            (codegenReal2Mission_DW.RateTransition_RDBuf)) {
        ii_data = static_cast<int8_T>(static_cast<int32_T>(static_cast<int32_T>
            (ii_data) + 1));
        if (static_cast<int32_T>(ii_data) == 3) {
            ii_data = 0;
        }
    }

    rtw_pthread_mutex_unlock(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
    for (i = 0; i < 4096; i++) {
        switch (ii_data) {
          case 0:
            codegenReal2Mission_DW.RateTransition_Buf0[i] =
                codegenReal2Mission_DW.Switch_m[i];
            break;

          case 1:
            codegenReal2Mission_DW.RateTransition_Buf1[i] =
                codegenReal2Mission_DW.Switch_m[i];
            break;

          case 2:
            codegenReal2Mission_DW.RateTransition_Buf2[i] =
                codegenReal2Mission_DW.Switch_m[i];
            break;
        }
    }

    codegenReal2Mission_DW.RateTransition_LstBufWR = ii_data;

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
        rtmSetFirstInitCond((&codegenReal2Mission_M), 1);
    }

    {
        static uint32_T *clockTickPtrs[4];
        static uint32_T *clockTickHPtrs[4];
        static real_T *taskTimePtrs[4];
        (&codegenReal2Mission_M)->timingBridge.nTasks = 4;
        clockTickPtrs[0] = &((&codegenReal2Mission_M)->Timing.clockTick0);
        clockTickHPtrs[0] = &((&codegenReal2Mission_M)->Timing.clockTickH0);
        clockTickPtrs[1] = &((&codegenReal2Mission_M)->Timing.clockTick1);
        clockTickHPtrs[1] = &((&codegenReal2Mission_M)->Timing.clockTickH1);
        clockTickPtrs[2] = (nullptr);
        clockTickHPtrs[2] = (nullptr);
        clockTickPtrs[3] = (nullptr);
        clockTickHPtrs[3] = (nullptr);
        (&codegenReal2Mission_M)->timingBridge.clockTick = clockTickPtrs;
        (&codegenReal2Mission_M)->timingBridge.clockTickH = clockTickHPtrs;
        taskTimePtrs[0] = &((&codegenReal2Mission_M)->Timing.t[0]);
        taskTimePtrs[1] = (nullptr);
        taskTimePtrs[2] = (nullptr);
        taskTimePtrs[3] = (nullptr);
        (&codegenReal2Mission_M)->timingBridge.taskTime = taskTimePtrs;
        (&codegenReal2Mission_M)->timingBridge.firstInitCond =
            &rtmIsFirstInitCond((&codegenReal2Mission_M));
    }

    // Model Initialize function for ModelReference Block: '<S93>/PreemptableMissionModeSelector' 
    FlightMissionMode_initialize(rtmGetErrorStatusPointer
        ((&codegenReal2Mission_M)),
        &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S102>/MissionUavModel' 
    MissionUAV_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                          rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
                          &((&codegenReal2Mission_M)->solverInfo),
                          &(&codegenReal2Mission_M)->timingBridge,
                          &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
                          &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtzce));

    // Model Initialize function for ModelReference Block: '<S56>/ImmedMission'
    ImmedMission_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                            &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S129>/Real2SimGuidance' 
    Real2SimGuidance_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
        rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
        &((&codegenReal2Mission_M)->solverInfo), &(&codegenReal2Mission_M)
        ->timingBridge, 0, 1,
        &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm));

    {
        FILE* eml_openfiles_g[20];
        FILE* a;
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
        emxArray_char_T_codegenReal2Mission_T *q;
        emxArray_char_T_codegenReal2Mission_T *ret;
        emxArray_char_T_codegenReal2Mission_T *tmp_5;
        emxArray_char_T_codegenReal2Mission_T *tmp_6;
        emxArray_char_T_codegenReal2Mission_T *tmp_7;
        emxArray_char_T_codegenReal2Mission_T *tmp_8;
        emxArray_char_T_codegenReal2Mission_T *tmp_9;
        emxArray_char_T_codegenReal2Mission_T *tmp_a;
        emxArray_char_T_codegenReal2Mission_T *tmp_b;
        emxArray_char_T_codegenReal2Mission_T *tmp_c;
        emxArray_char_T_codegenReal2Mission_T *tmp_d;
        emxArray_char_T_codegenReal2Mission_T *tmp_e;
        emxArray_char_T_codegenReal2Mission_T *tmp_f;
        creal_T tmp;
        creal_T tmp_0;
        creal_T tmp_1;
        creal_T tmp_2;
        creal_T tmp_3;
        creal_T tmp_4;
        real_T LLA0_idx_0;
        real_T LLA0_idx_1;
        real_T LLA0_idx_2;
        int32_T i;
        int32_T iremain;
        int32_T itoken;
        int32_T loop_ub;
        int8_T fileid;
        boolean_T b_x[3];
        boolean_T b_bool;
        boolean_T exitg1;
        boolean_T guard1{ false };

        // Start for slMsgMgr: '<Root>/slMsgMgr'
        codegenReal2Mission_initMemPool
            (&codegenReal2Mission_DW.slMsgMgr_MemPool_IndividualUAVCmd,
             &codegenReal2Mission_DW.slMsgMgr_memArray_IndividualUAVCmd[0],
             &codegenReal2Mission_DW.slMsgMgr_freeList_IndividualUAVCmd[0], 17);
        codegenReal2Mission_initMemPool_o
            (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd,
             &codegenReal2Mission_DW.slMsgMgr_memArray_missionCmd[0],
             &codegenReal2Mission_DW.slMsgMgr_freeList_missionCmd[0], 9);
        codegenReal2Mission_initMemPool_d
            (&codegenReal2Mission_DW.slMsgMgr_MemPool_DangerInfo,
             &codegenReal2Mission_DW.slMsgMgr_memArray_DangerInfo[0],
             &codegenReal2Mission_DW.slMsgMgr_freeList_DangerInfo[0], 2);

        // Start for RateTransition: '<Root>/Rate Transition'
        rtw_pthread_mutex_init
            (&codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);

        // Start for RateTransition: '<Root>/RTLLA'
        rtw_pthread_mutex_init(&codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);
        codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
            POS_ZCSIG;
        codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE = POS_ZCSIG;
        codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE =
            POS_ZCSIG;

        // InitializeConditions for DataStoreMemory generated from: '<S2>/AltitudeGCS' 
        rtw_pthread_mutex_init(&AltitudeGCS_m0);

        // InitializeConditions for DataStoreMemory generated from: '<S2>/LatitudeGCS' 
        rtw_pthread_mutex_init(&LatitudeGCS_m0);

        // InitializeConditions for DataStoreMemory generated from: '<S2>/LongitudeGCS' 
        rtw_pthread_mutex_init(&LongitudeGCS_m0);

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // SystemInitialize for Atomic SubSystem: '<S3>/PreProcessMissionCMD'
        // SystemInitialize for Atomic SubSystem: '<S58>/QueueCMD'
        // Start for Queue: '<S110>/Queue'
        codegenReal2Mission_initQueue(&codegenReal2Mission_DW.Queue_Queue,
            QueuePolicy_T::MSG_FIFO_QUEUE, 16,
            &codegenReal2Mission_DW.Queue_Msg[0]);

        // SystemInitialize for Enabled SubSystem: '<S110>/UplinkLog'
        // SystemInitialize for MATLAB Function: '<S123>/PrintOnboardLog'
        a = NULL;
        for (i = 0; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles_j[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S123>/PrintOnboardLog' 
        // End of SystemInitialize for SubSystem: '<S110>/UplinkLog'
        // End of SystemInitialize for SubSystem: '<S58>/QueueCMD'
        // End of SystemInitialize for SubSystem: '<S3>/PreProcessMissionCMD'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'

        // Start for Receive: '<S120>/Receive'
        std::memset(&codegenReal2Mission_DW.Receive, 0, sizeof(IndividualUAVCmd));

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // SystemInitialize for Atomic SubSystem: '<S92>/FlightMission'
        // SystemInitialize for ModelReference: '<S93>/PreemptableMissionModeSelector' 
        FlightMissionMode_Init
            (&codegenReal2Mission_DW.PreemptableMissionModeSelector_o2,
             &codegenReal2Mission_DW.PreemptableMissionModeSelector_o3[0],
             &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));

        // SystemInitialize for Enabled SubSystem: '<S93>/MissionSimUAV'
        // SystemInitialize for ModelReference generated from: '<S102>/MissionUavModel' 
        MissionUAV_Init
            (&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
             &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw),
             &(codegenReal2Mission_X.MissionUavModel_CSTATE));

        // End of SystemInitialize for SubSystem: '<S93>/MissionSimUAV'
        // End of SystemInitialize for SubSystem: '<S92>/FlightMission'

        // SystemInitialize for ModelReference generated from: '<S56>/ImmedMission' 
        ImmedMission_Init(&codegenReal2Mission_DW.ImmedMission_o3[0],
                          &codegenReal2Mission_DW.ImmedMission_o4,
                          &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw),
                          &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtzce));

        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'
        codegenReal2Mission_emxInitStruct_DangerArray
            (&codegenReal2Mission_DW.localObj);

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // SystemInitialize for Triggered SubSystem: '<S54>/TriggerCurrentMisisonFeedback' 
        // SystemInitialize for MATLAB Function: '<S88>/PrintOnboardLog'
        a = NULL;
        for (i = 0; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S88>/PrintOnboardLog'
        // End of SystemInitialize for SubSystem: '<S54>/TriggerCurrentMisisonFeedback' 

        // SystemInitialize for Atomic SubSystem: '<S3>/InitializeSimLocation'
        // SystemInitialize for MATLAB Function: '<S57>/ReadHomePoint'
        a = NULL;
        for (i = 0; i < 20; i++) {
            eml_openfiles_g[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S57>/ReadHomePoint'

        // SystemInitialize for MATLAB Function: '<S57>/ReadParADRC'
        a = NULL;
        for (i = 0; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles_b[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S57>/ReadParADRC'
        // End of SystemInitialize for SubSystem: '<S3>/InitializeSimLocation'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'
        codegenReal2Mission_emxInit_char_T(&ret, 2);

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // Outputs for Atomic SubSystem: '<S3>/InitializeSimLocation'
        // MATLAB Function: '<S57>/ReadHomePoint'
        // MATLAB Function 'MissionLogic/InitializeSimLocation/ReadHomePoint': '<S107>:1' 
        // '<S107>:1:3'
        ret->size[0] = 1;
        ret->size[1] = 0;
        fileid = codegenReal2Mission_cfopen_g("config.ini", "rb",
            eml_openfiles_g);

        // End of Outputs for SubSystem: '<S3>/InitializeSimLocation'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'
        codegenReal2Mission_emxInit_char_T(&data, 2);
        codegenReal2Mission_emxInit_char_T(&curSection, 2);
        codegenReal2Mission_emxInit_char_T(&curKey, 2);
        codegenReal2Mission_emxInit_char_T(&curVal, 2);
        codegenReal2Mission_emxInit_char_T(&curLine, 2);
        codegenReal2Mission_emxInit_char_T(&b_curKey, 2);
        codegenReal2Mission_emxInit_char_T(&q, 1);

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // Outputs for Atomic SubSystem: '<S3>/InitializeSimLocation'
        // MATLAB Function: '<S57>/ReadHomePoint'
        if (static_cast<int32_T>(fileid) < 0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            codegenReal2Mission_fread(static_cast<real_T>(fileid),
                eml_openfiles_g, q);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            codegenReal2Mission_cfclose_e(static_cast<real_T>(fileid),
                eml_openfiles_g);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            codegenReal2Mission_emxInit_char_T(&tmp_f, 2);
            codegenReal2Mission_emxInit_char_T(&data_6, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_6->size[0] * data_6->size[1]);
                data_6->size[0] = 1;
                data_6->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_6, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_6->data[i] = data->data[i];
                }

                codegenReal2Mission_strtok(data_6, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp_f);
                codegenReal2Mission_strtrim(tmp_f, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data
                                    [static_cast<int32_T>(iremain + i)];
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
                            codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                curVal);
                            codegenReal2Mission_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            codegenReal2Mission_strtrim(b_curKey, curKey);
                            i = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curLine->data[i] = curVal->data
                                    [static_cast<int32_T>(itoken + i)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp(curSection) &&
                        codegenReal2Mission_strcmp_i(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            codegenReal2Mission_emxFree_char_T(&data_6);
            codegenReal2Mission_emxFree_char_T(&tmp_f);
        }

        tmp = codegenReal2Mission_str2double(ret);
        printf("Set Home Point Latitude:\t%f\n", tmp.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        fileid = codegenReal2Mission_cfopen_g("config.ini", "rb",
            eml_openfiles_g);
        if (static_cast<int32_T>(fileid) < 0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            codegenReal2Mission_fread(static_cast<real_T>(fileid),
                eml_openfiles_g, q);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            codegenReal2Mission_cfclose_e(static_cast<real_T>(fileid),
                eml_openfiles_g);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            codegenReal2Mission_emxInit_char_T(&tmp_e, 2);
            codegenReal2Mission_emxInit_char_T(&data_5, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_5->size[0] * data_5->size[1]);
                data_5->size[0] = 1;
                data_5->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_5, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_5->data[i] = data->data[i];
                }

                codegenReal2Mission_strtok(data_5, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp_e);
                codegenReal2Mission_strtrim(tmp_e, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data
                                    [static_cast<int32_T>(iremain + i)];
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
                            codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                curVal);
                            codegenReal2Mission_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            codegenReal2Mission_strtrim(b_curKey, curKey);
                            i = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curLine->data[i] = curVal->data
                                    [static_cast<int32_T>(itoken + i)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp(curSection) &&
                        codegenReal2Mission_strcmp_i1(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            codegenReal2Mission_emxFree_char_T(&data_5);
            codegenReal2Mission_emxFree_char_T(&tmp_e);
        }

        tmp_0 = codegenReal2Mission_str2double(ret);
        printf("Set Home Point Longitude:\t%f\n", tmp_0.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        fileid = codegenReal2Mission_cfopen_g("config.ini", "rb",
            eml_openfiles_g);
        if (static_cast<int32_T>(fileid) < 0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            codegenReal2Mission_fread(static_cast<real_T>(fileid),
                eml_openfiles_g, q);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            codegenReal2Mission_cfclose_e(static_cast<real_T>(fileid),
                eml_openfiles_g);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            codegenReal2Mission_emxInit_char_T(&tmp_d, 2);
            codegenReal2Mission_emxInit_char_T(&data_4, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_4->size[0] * data_4->size[1]);
                data_4->size[0] = 1;
                data_4->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_4, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_4->data[i] = data->data[i];
                }

                codegenReal2Mission_strtok(data_4, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp_d);
                codegenReal2Mission_strtrim(tmp_d, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data
                                    [static_cast<int32_T>(iremain + i)];
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
                            codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                curVal);
                            codegenReal2Mission_find_token(curVal, &itoken,
                                &iremain);
                            if (itoken > static_cast<int32_T>(iremain - 1)) {
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = static_cast<int32_T>(itoken - 1);
                                iremain = static_cast<int32_T>(iremain - 1);
                            }

                            codegenReal2Mission_strtrim(b_curKey, curKey);
                            i = static_cast<int32_T>(curLine->size[0] *
                                curLine->size[1]);
                            curLine->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curLine->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T(curLine,
                                i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curLine->data[i] = curVal->data
                                    [static_cast<int32_T>(itoken + i)];
                            }

                            codegenReal2Mission_strtrim(curLine, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp(curSection) &&
                        codegenReal2Mission_strcmp_i15(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            codegenReal2Mission_emxFree_char_T(&data_4);
            codegenReal2Mission_emxFree_char_T(&tmp_d);
        }

        tmp_1 = codegenReal2Mission_str2double(ret);
        printf("Set Home Point Altitude:\t%f\n", tmp_1.re);
        fflush(stdout);
        LLA0_idx_0 = tmp.re;
        LLA0_idx_1 = tmp_0.re;
        LLA0_idx_2 = tmp_1.re;
        b_x[0] = std::isnan(tmp.re);
        b_x[1] = std::isnan(tmp_0.re);
        b_x[2] = std::isnan(tmp_1.re);
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
            // '<S107>:1:5'
            // '<S107>:1:6'
            LLA0_idx_0 = 39.9042;
            LLA0_idx_1 = 116.4074;
            LLA0_idx_2 = 0.0;
        }

        // DataStoreWrite: '<S57>/DSAltitudeGCS'
        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        AltitudeGCS = LLA0_idx_2;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);

        // DataStoreWrite: '<S57>/DSLatitudeGCS'
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        LatitudeGCS = LLA0_idx_0;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);

        // DataStoreWrite: '<S57>/DSLongitudeGCS'
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        LongitudeGCS = LLA0_idx_1;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);

        // MATLAB Function: '<S57>/ReadParADRC'
        // MATLAB Function 'MissionLogic/InitializeSimLocation/ReadParADRC': '<S108>:1' 
        // '<S108>:1:3'
        ret->size[0] = 1;
        ret->size[1] = 0;
        LLA0_idx_0 = codegenReal2Mission_fileManager_p();
        if (LLA0_idx_0 < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            codegenReal2Mission_fread_n(LLA0_idx_0, q);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            codegenReal2Mission_cfclose_g(LLA0_idx_0);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            codegenReal2Mission_emxInit_char_T(&tmp_b, 2);
            codegenReal2Mission_emxInit_char_T(&tmp_c, 2);
            codegenReal2Mission_emxInit_char_T(&data_3, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_3->size[0] * data_3->size[1]);
                data_3->size[0] = 1;
                data_3->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_3, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_3->data[i] = data->data[i];
                }

                codegenReal2Mission_strtok(data_3, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp_c);
                codegenReal2Mission_strtrim(tmp_c, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data
                                    [static_cast<int32_T>(iremain + i)];
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
                            codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                curVal);
                            codegenReal2Mission_strtrim(b_curKey, curKey);
                            codegenReal2Mission_strtok_e2sz(curVal, tmp_b);
                            codegenReal2Mission_strtrim(tmp_b, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_b(curSection) &&
                        codegenReal2Mission_strcmp_by(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            codegenReal2Mission_emxFree_char_T(&data_3);
            codegenReal2Mission_emxFree_char_T(&tmp_c);
            codegenReal2Mission_emxFree_char_T(&tmp_b);
        }

        tmp = codegenReal2Mission_str2double(ret);
        printf("ADRC control input gain:\t%f\n", tmp.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        LLA0_idx_0 = codegenReal2Mission_fileManager_p();
        if (LLA0_idx_0 < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            codegenReal2Mission_fread_n(LLA0_idx_0, q);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            codegenReal2Mission_cfclose_g(LLA0_idx_0);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            codegenReal2Mission_emxInit_char_T(&tmp_9, 2);
            codegenReal2Mission_emxInit_char_T(&tmp_a, 2);
            codegenReal2Mission_emxInit_char_T(&data_2, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_2->size[0] * data_2->size[1]);
                data_2->size[0] = 1;
                data_2->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_2, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_2->data[i] = data->data[i];
                }

                codegenReal2Mission_strtok(data_2, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp_a);
                codegenReal2Mission_strtrim(tmp_a, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data
                                    [static_cast<int32_T>(iremain + i)];
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
                            codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                curVal);
                            codegenReal2Mission_strtrim(b_curKey, curKey);
                            codegenReal2Mission_strtok_e2sz(curVal, tmp_9);
                            codegenReal2Mission_strtrim(tmp_9, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_b(curSection) &&
                        codegenReal2Mission_strcmp_byv(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            codegenReal2Mission_emxFree_char_T(&data_2);
            codegenReal2Mission_emxFree_char_T(&tmp_a);
            codegenReal2Mission_emxFree_char_T(&tmp_9);
        }

        tmp_0 = codegenReal2Mission_str2double(ret);
        printf("ADRC observer bandwidth:\t%f\n", tmp_0.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        LLA0_idx_0 = codegenReal2Mission_fileManager_p();
        if (LLA0_idx_0 < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            codegenReal2Mission_fread_n(LLA0_idx_0, q);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            codegenReal2Mission_cfclose_g(LLA0_idx_0);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            codegenReal2Mission_emxInit_char_T(&tmp_7, 2);
            codegenReal2Mission_emxInit_char_T(&tmp_8, 2);
            codegenReal2Mission_emxInit_char_T(&data_1, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_1->size[0] * data_1->size[1]);
                data_1->size[0] = 1;
                data_1->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_1, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_1->data[i] = data->data[i];
                }

                codegenReal2Mission_strtok(data_1, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp_8);
                codegenReal2Mission_strtrim(tmp_8, curLine);
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
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data
                                    [static_cast<int32_T>(iremain + i)];
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
                            codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                curVal);
                            codegenReal2Mission_strtrim(b_curKey, curKey);
                            codegenReal2Mission_strtok_e2sz(curVal, tmp_7);
                            codegenReal2Mission_strtrim(tmp_7, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_b(curSection) &&
                        codegenReal2Mission_strcmp_byvm(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            codegenReal2Mission_emxFree_char_T(&data_1);
            codegenReal2Mission_emxFree_char_T(&tmp_8);
            codegenReal2Mission_emxFree_char_T(&tmp_7);
        }

        tmp_1 = codegenReal2Mission_str2double(ret);
        printf("ADRC controller bandwidth:\t%f\n", tmp_1.re);
        fflush(stdout);
        ret->size[0] = 1;
        ret->size[1] = 0;
        LLA0_idx_0 = codegenReal2Mission_fileManager_p();
        if (LLA0_idx_0 < 0.0) {
            printf("INI-file \"%s\" was not found or could not be read.\n",
                   "config.ini");
            fflush(stdout);
        } else {
            codegenReal2Mission_fread_n(LLA0_idx_0, q);
            i = static_cast<int32_T>(data->size[0] * data->size[1]);
            data->size[0] = 1;
            data->size[1] = q->size[0];
            codegenReal2Mission_emxEnsureCapacity_char_T(data, i);
            loop_ub = q->size[0];
            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
                data->data[i] = q->data[i];
            }

            codegenReal2Mission_cfclose_g(LLA0_idx_0);
            curSection->size[0] = 1;
            curSection->size[1] = 0;
            curKey->size[0] = 1;
            curKey->size[1] = 0;
            curVal->size[0] = 1;
            curVal->size[1] = 0;
            codegenReal2Mission_emxInit_char_T(&tmp_5, 2);
            codegenReal2Mission_emxInit_char_T(&tmp_6, 2);
            codegenReal2Mission_emxInit_char_T(&data_0, 2);
            exitg1 = false;
            while ((!exitg1) && (data->size[1] != 0)) {
                i = static_cast<int32_T>(data_0->size[0] * data_0->size[1]);
                data_0->size[0] = 1;
                data_0->size[1] = data->size[1];
                codegenReal2Mission_emxEnsureCapacity_char_T(data_0, i);
                loop_ub = static_cast<int32_T>(static_cast<int32_T>(data->size[0]
                    * data->size[1]) - 1);
                for (i = 0; i <= loop_ub; i++) {
                    data_0->data[i] = data->data[i];
                }

                codegenReal2Mission_strtok(data_0, curLine, data);
                codegenReal2Mission_strtok_p(curLine, tmp_6);
                codegenReal2Mission_strtrim(tmp_6, curLine);
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
                                itoken = 0;
                                iremain = 0;
                            } else {
                                itoken = 1;
                                iremain = static_cast<int32_T>(curLine->size[1]
                                    - 1);
                            }

                            i = static_cast<int32_T>(curSection->size[0] *
                                curSection->size[1]);
                            curSection->size[0] = 1;
                            loop_ub = static_cast<int32_T>(iremain - itoken);
                            curSection->size[1] = loop_ub;
                            codegenReal2Mission_emxEnsureCapacity_char_T
                                (curSection, i);
                            for (i = 0; i <= static_cast<int32_T>(loop_ub - 1);
                                    i++) {
                                curSection->data[i] = curLine->data[static_cast<
                                    int32_T>(itoken + i)];
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
                            codegenReal2Mission_strtok_ph(curLine, b_curKey,
                                curVal);
                            codegenReal2Mission_strtrim(b_curKey, curKey);
                            codegenReal2Mission_strtok_e2sz(curVal, tmp_5);
                            codegenReal2Mission_strtrim(tmp_5, curVal);
                        }
                    }
                }

                if (codegenReal2Mission_strcmp_b(curSection) &&
                        codegenReal2Mission_strcmp_byvm0(curKey)) {
                    i = static_cast<int32_T>(ret->size[0] * ret->size[1]);
                    ret->size[0] = 1;
                    ret->size[1] = curVal->size[1];
                    codegenReal2Mission_emxEnsureCapacity_char_T(ret, i);
                    loop_ub = static_cast<int32_T>(curVal->size[1] - 1);
                    for (i = 0; i <= loop_ub; i++) {
                        ret->data[i] = curVal->data[i];
                    }

                    exitg1 = true;
                }
            }

            codegenReal2Mission_emxFree_char_T(&data_0);
            codegenReal2Mission_emxFree_char_T(&tmp_6);
            codegenReal2Mission_emxFree_char_T(&tmp_5);
        }

        // End of Outputs for SubSystem: '<S3>/InitializeSimLocation'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'
        codegenReal2Mission_emxFree_char_T(&q);
        codegenReal2Mission_emxFree_char_T(&curLine);
        codegenReal2Mission_emxFree_char_T(&curKey);
        codegenReal2Mission_emxFree_char_T(&curSection);
        codegenReal2Mission_emxFree_char_T(&data);

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // Outputs for Atomic SubSystem: '<S3>/InitializeSimLocation'
        // MATLAB Function: '<S57>/ReadParADRC'
        tmp_2 = codegenReal2Mission_str2double(ret);
        printf("PID proportional gain:\t\t%f\n", tmp_2.re);
        fflush(stdout);
        codegenReal2Mission_readINI(b_curKey);
        tmp_3 = codegenReal2Mission_str2double(b_curKey);
        printf("PID integrational gain:\t\t%f\n", tmp_3.re);
        fflush(stdout);
        codegenReal2Mission_readINI_g(b_curKey);
        tmp_4 = codegenReal2Mission_str2double(b_curKey);
        printf("PID differential gain:\t\t%f\n", tmp_4.re);
        fflush(stdout);
        codegenReal2Mission_readINI_gx(curVal);
        loop_ub = curVal->size[1];
        i = static_cast<int32_T>(b_curKey->size[0] * b_curKey->size[1]);
        b_curKey->size[0] = 1;
        b_curKey->size[1] = static_cast<int32_T>(curVal->size[1] + 1);
        codegenReal2Mission_emxEnsureCapacity_char_T(b_curKey, i);

        // End of Outputs for SubSystem: '<S3>/InitializeSimLocation'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'
        codegenReal2Mission_emxFree_char_T(&ret);

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // Outputs for Atomic SubSystem: '<S3>/InitializeSimLocation'
        // MATLAB Function: '<S57>/ReadParADRC' incorporates:
        //   DataStoreWrite: '<S57>/Data Store Write'

        for (i = 0; i <= static_cast<int32_T>(loop_ub - 1); i++) {
            b_curKey->data[i] = curVal->data[i];
        }

        b_curKey->data[curVal->size[1]] = '\x00';
        printf("Use ADRC after engaged:\t\t%s\n", &b_curKey->data[0]);
        fflush(stdout);
        codegenReal2Mission_DW.ParamADRC_e.hat_b = tmp.re;
        codegenReal2Mission_DW.ParamADRC_e.omega_o = tmp_0.re;
        codegenReal2Mission_DW.ParamADRC_e.omega_c = tmp_1.re;
        codegenReal2Mission_DW.ParamADRC_e.P = tmp_2.re;
        codegenReal2Mission_DW.ParamADRC_e.I = tmp_3.re;
        codegenReal2Mission_DW.ParamADRC_e.D = tmp_4.re;
        codegenReal2Mission_DW.ParamADRC_e.useADRC = static_cast<boolean_T>(
            static_cast<int32_T>(static_cast<int32_T>
            (codegenReal2Mission_strcmp_byvm0m(curVal)) ^ 1));

        // End of Outputs for SubSystem: '<S3>/InitializeSimLocation'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'
        codegenReal2Mission_emxFree_char_T(&b_curKey);
        codegenReal2Mission_emxFree_char_T(&curVal);

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // Outputs for Atomic SubSystem: '<S3>/InitializeSimLocation'
        // DataStoreWrite: '<S57>/Data Store Write'
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
                (&(&codegenReal2Mission_M)->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
                (&(&codegenReal2Mission_M)->solverInfo, true);
        }

        // End of Outputs for SubSystem: '<S3>/InitializeSimLocation'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'

        // SystemInitialize for Atomic SubSystem: '<Root>/TrackingControl'
        // SystemInitialize for ModelReference generated from: '<S129>/Real2SimGuidance' 
        Real2SimGuidance_Init
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
             &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));

        // End of SystemInitialize for SubSystem: '<Root>/TrackingControl'

        // SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/PushNbrUAV' incorporates:
        //   SubSystem: '<Root>/DeSerOtherUAV'

        // SystemInitialize for Iterator SubSystem: '<S1>/While Iterator Serializer' 
        // Start for DataStoreMemory: '<S5>/Data Store Memory'
        for (i = 0; i < 4096; i++) {
            codegenReal2Mission_DW.CatPos[i] = (rtNaN);
        }

        // End of Start for DataStoreMemory: '<S5>/Data Store Memory'
        // End of SystemInitialize for SubSystem: '<S1>/While Iterator Serializer' 
        // End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/PushNbrUAV' 
    }

    // set "at time zero" to false
    if (rtmIsFirstInitCond((&codegenReal2Mission_M))) {
        rtmSetFirstInitCond((&codegenReal2Mission_M), 0);
    }
}

// Model terminate function
void codegenReal2MissionModelClass::terminate()
{
    // Terminate for RateTransition: '<Root>/Rate Transition'
    rtw_pthread_mutex_destroy(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);

    // Terminate for RateTransition: '<Root>/RTLLA'
    rtw_pthread_mutex_destroy(codegenReal2Mission_DW.RTLLA_d0_SEMAPHORE);

    // Terminate for DataStoreMemory generated from: '<S2>/AltitudeGCS'
    rtw_pthread_mutex_destroy(AltitudeGCS_m0);

    // Terminate for DataStoreMemory generated from: '<S2>/LatitudeGCS'
    rtw_pthread_mutex_destroy(LatitudeGCS_m0);

    // Terminate for DataStoreMemory generated from: '<S2>/LongitudeGCS'
    rtw_pthread_mutex_destroy(LongitudeGCS_m0);
    codegenReal2Mission_emxFreeStruct_DangerArray
        (&codegenReal2Mission_DW.localObj);
}

// Constructor
codegenReal2MissionModelClass::codegenReal2MissionModelClass
    (SendData_IndividualUAVCmdT& CurrentMissionSendData_arg,
     SendData_FlightLoggingT& FlightLogSendData_arg,RecvData_IndividualUAVCmdT&
     MissionCMDRecvData_arg,RecvData_RealUAVStateBusT& NbrUAVstateRecvData_arg) :
    codegenReal2Mission_U(),
    codegenReal2Mission_Y(),
    codegenReal2Mission_DW(),
    codegenReal2Mission_X(),
    codegenReal2Mission_PrevZCX(),
    CurrentMissionSendData(CurrentMissionSendData_arg),
    FlightLogSendData(FlightLogSendData_arg),
    MissionCMDRecvData(MissionCMDRecvData_arg),
    NbrUAVstateRecvData(NbrUAVstateRecvData_arg),
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
