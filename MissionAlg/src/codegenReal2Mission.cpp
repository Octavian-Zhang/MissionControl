//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.91
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Wed Feb 23 00:38:39 2022
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
#include "div_s32.h"
#include "floor_6aYiD2p8.h"
#include "print_processing_OPmXLPoa.h"
#include "print_processing_mFrJ8Td3.h"
#include "rt_modd_snf.h"
#include "split_lIfqwsQg.h"

// Named constants for Chart: '<S24>/EnableSailShift'
const uint8_T codegenReal2Mission_IN_NotShift{ 1U };

const uint8_T codegenReal2Mission_IN_Shift{ 2U };

// Named constants for Chart: '<S14>/TriggerStartSim'
const uint8_T codegenReal2Mission_IN_Pending{ 1U };

const uint8_T codegenReal2Mission_IN_Running{ 2U };

// Named constants for Chart: '<S13>/MisisonCMDTemporalLogic'
const uint8_T codegenReal2Mission_IN_Sending{ 2U };

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
    int_T nXc { 17 };

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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

    if (0 <= static_cast<int32_T>(trueCount - 1)) {
        bb = 0.0;
    }

    c.re = shi;
    c.im = bb;
    return c;
}

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_two_prod(real_T a)
{
    creal_T c;
    creal_T da;
    real_T shi;
    real_T slo;
    int32_T trueCount;
    da = split_lIfqwsQg(a);
    shi = a * 8.64E+7;
    slo = (da.re * 8.64E+7 - shi) + da.im * 8.64E+7;
    trueCount = 0;
    if (std::isnan(slo)) {
        trueCount = 1;
    }

    if (0 <= static_cast<int32_T>(trueCount - 1)) {
        slo = 0.0;
    }

    c.re = shi;
    c.im = slo;
    return c;
}

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S6>/CommandCheck'
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

        if ((inData[6] < 0.0) || (1000.0 <= inData[6])) {
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

// Function for MATLAB Function: '<S6>/CommandCheck'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isequaln_f
    (MissionModes varargin_1, MissionModes varargin_2)
{
    boolean_T p;
    p = false;
    if (varargin_1 == varargin_2) {
        p = true;
    }

    return p;
}

// Function for MATLAB Function: '<S6>/CommandCheck'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isequaln(const
    missionCmd *varargin_1, int32_T varargin_2_SequenceID, MissionModes
    varargin_2_MissionMode, real_T varargin_2_MissionLocation_Lat, real_T
    varargin_2_MissionLocation_Lon, real_T varargin_2_MissionLocation_Alt,
    real_T varargin_2_MissionLocation_degHDG, real32_T varargin_2_params_Param1,
    real32_T varargin_2_params_Param2, real32_T varargin_2_params_Param3,
    real32_T varargin_2_params_Param4, real32_T varargin_2_params_Param5,
    real32_T varargin_2_params_Param6, real32_T varargin_2_params_Param7, const
    Location varargin_2_StartPosition, int32_T varargin_2_numUAV, int32_T
    varargin_2_FormationPos, real_T varargin_2_StartTime)
{
    boolean_T e_p;
    boolean_T p;
    p = false;
    if (static_cast<boolean_T>(static_cast<int32_T>((varargin_1->StartTime ==
            varargin_2_StartTime) | static_cast<int32_T>(static_cast<boolean_T>(
            static_cast<int32_T>(static_cast<int32_T>(std::isnan
              (varargin_1->StartTime)) & static_cast<int32_T>(std::isnan
              (varargin_2_StartTime)))))))) {
        if (varargin_1->FormationPos == varargin_2_FormationPos) {
            if (varargin_1->numUAV == varargin_2_numUAV) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((varargin_1->StartPosition.degHDG ==
                       varargin_2_StartPosition.degHDG) | static_cast<int32_T>(
                        static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                         int32_T>(std::isnan(varargin_1->StartPosition.degHDG))
                         & static_cast<int32_T>(std::isnan
                          (varargin_2_StartPosition.degHDG)))))))) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((varargin_1->StartPosition.Alt ==
                           varargin_2_StartPosition.Alt) | static_cast<int32_T>(
                            static_cast<boolean_T>(static_cast<int32_T>(
                             static_cast<int32_T>(std::isnan
                              (varargin_1->StartPosition.Alt)) &
                             static_cast<int32_T>(std::isnan
                              (varargin_2_StartPosition.Alt)))))))) {
                        e_p = static_cast<boolean_T>(static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<boolean_T>(
                            static_cast<int32_T>((varargin_1->StartPosition.Lon ==
                            varargin_2_StartPosition.Lon) | static_cast<int32_T>
                            (static_cast<boolean_T>(static_cast<int32_T>(
                            static_cast<int32_T>(std::isnan
                            (varargin_1->StartPosition.Lon)) &
                            static_cast<int32_T>(std::isnan
                            (varargin_2_StartPosition.Lon)))))))) & static_cast<
                            int32_T>(static_cast<boolean_T>(static_cast<int32_T>
                            ((varargin_1->StartPosition.Lat ==
                              varargin_2_StartPosition.Lat) |
                             static_cast<int32_T>(static_cast<boolean_T>(
                            static_cast<int32_T>(static_cast<int32_T>(std::isnan
                            (varargin_1->StartPosition.Lat)) &
                            static_cast<int32_T>(std::isnan
                            (varargin_2_StartPosition.Lat))))))))));
                    } else {
                        e_p = false;
                    }
                } else {
                    e_p = false;
                }

                if (e_p) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((varargin_1->params.Param7 ==
                            varargin_2_params_Param7) | static_cast<int32_T>(
                            static_cast<boolean_T>(static_cast<int32_T>(
                             static_cast<int32_T>(std::isnan
                              (varargin_1->params.Param7)) & static_cast<int32_T>
                             (std::isnan(varargin_2_params_Param7)))))))) {
                        if (static_cast<boolean_T>(static_cast<int32_T>
                                                   ((varargin_1->params.Param6 ==
                               varargin_2_params_Param6) | static_cast<int32_T>(
                                static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(std::isnan
                                  (varargin_1->params.Param6)) & static_cast<
                                 int32_T>(std::isnan(varargin_2_params_Param6))))))))
                        {
                            if (static_cast<boolean_T>(static_cast<int32_T>
                                                       ((varargin_1->params.Param5
                                   == varargin_2_params_Param5) |
                                                        static_cast<int32_T>(
                                    static_cast<boolean_T>(static_cast<int32_T>(
                                     static_cast<int32_T>(std::isnan
                                      (varargin_1->params.Param5)) &
                                     static_cast<int32_T>(std::isnan
                                      (varargin_2_params_Param5)))))))) {
                                if (static_cast<boolean_T>(static_cast<int32_T>
                                                           ((varargin_1->params.Param4
                                       == varargin_2_params_Param4) |
                                                            static_cast<int32_T>
                                                            (static_cast<boolean_T>
                                        (static_cast<int32_T>
                                         (static_cast<int32_T>(std::isnan
                                          (varargin_1->params.Param4)) &
                                          static_cast<int32_T>(std::isnan
                                          (varargin_2_params_Param4)))))))) {
                                    if (static_cast<boolean_T>
                                            (static_cast<int32_T>
                                             ((varargin_1->params.Param3 ==
                                               varargin_2_params_Param3) |
                                              static_cast<int32_T>
                                              (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            (static_cast<int32_T>(std::isnan
                                              (varargin_1->params.Param3)) &
                                             static_cast<int32_T>(std::isnan
                                              (varargin_2_params_Param3))))))))
                                    {
                                        e_p = static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            (static_cast<int32_T>
                                             (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            ((varargin_1->params.Param2 ==
                                              varargin_2_params_Param2) |
                                             static_cast<int32_T>
                                             (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            (static_cast<int32_T>(std::isnan
                                            (varargin_1->params.Param2)) &
                                             static_cast<int32_T>(std::isnan
                                            (varargin_2_params_Param2)))))))) &
                                             static_cast<int32_T>
                                             (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            ((varargin_1->params.Param1 ==
                                              varargin_2_params_Param1) |
                                             static_cast<int32_T>
                                             (static_cast<boolean_T>(
                                            static_cast<int32_T>
                                            (static_cast<int32_T>(std::isnan
                                            (varargin_1->params.Param1)) &
                                             static_cast<int32_T>(std::isnan
                                            (varargin_2_params_Param1))))))))));
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
                                                   ((varargin_1->MissionLocation.degHDG
                               == varargin_2_MissionLocation_degHDG) |
                                                    static_cast<int32_T>(
                                static_cast<boolean_T>(static_cast<int32_T>(
                                 static_cast<int32_T>(std::isnan
                                  (varargin_1->MissionLocation.degHDG)) &
                                 static_cast<int32_T>(std::isnan
                                  (varargin_2_MissionLocation_degHDG)))))))) {
                            if (static_cast<boolean_T>(static_cast<int32_T>
                                                       ((varargin_1->MissionLocation.Alt
                                   == varargin_2_MissionLocation_Alt) |
                                                        static_cast<int32_T>(
                                    static_cast<boolean_T>(static_cast<int32_T>(
                                     static_cast<int32_T>(std::isnan
                                      (varargin_1->MissionLocation.Alt)) &
                                     static_cast<int32_T>(std::isnan
                                      (varargin_2_MissionLocation_Alt)))))))) {
                                e_p = static_cast<boolean_T>(static_cast<int32_T>
                                    (static_cast<int32_T>(static_cast<boolean_T>
                                    (static_cast<int32_T>
                                     ((varargin_1->MissionLocation.Lon ==
                                       varargin_2_MissionLocation_Lon) |
                                      static_cast<int32_T>(static_cast<boolean_T>
                                    (static_cast<int32_T>(static_cast<int32_T>
                                    (std::isnan(varargin_1->MissionLocation.Lon))
                                    & static_cast<int32_T>(std::isnan
                                    (varargin_2_MissionLocation_Lon)))))))) &
                                     static_cast<int32_T>(static_cast<boolean_T>
                                    (static_cast<int32_T>
                                     ((varargin_1->MissionLocation.Lat ==
                                       varargin_2_MissionLocation_Lat) |
                                      static_cast<int32_T>(static_cast<boolean_T>
                                    (static_cast<int32_T>(static_cast<int32_T>
                                    (std::isnan(varargin_1->MissionLocation.Lat))
                                    & static_cast<int32_T>(std::isnan
                                    (varargin_2_MissionLocation_Lat))))))))));
                            } else {
                                e_p = false;
                            }
                        } else {
                            e_p = false;
                        }

                        if (e_p) {
                            e_p = static_cast<boolean_T>(static_cast<int32_T>
                                ((varargin_1->SequenceID ==
                                  varargin_2_SequenceID) & static_cast<int32_T>
                                 (codegenReal2Mission_isequaln_f
                                  (varargin_1->MissionMode,
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

    if (0 <= static_cast<int32_T>(trueCount - 1)) {
        bb = 0.0;
    }

    c.re = shi;
    c.im = bb;
    return c;
}

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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
    t = floor_6aYiD2p8(b_thi_0);
    b_thi = t.re + t.im;
    b_thi_0 = codegenReal2Mission_minus(dd, codegenReal2Mission_times(t));
    b_c.re = b_thi_0.re / 1000.0;
    t = split_lIfqwsQg(b_c.re);
    b_tmp = b_c.re * 1000.0;
    slo = (t.re * 1000.0 - b_tmp) + t.im * 1000.0;
    idn = 0;
    if (std::isnan(slo)) {
        idn = 1;
    }

    if (0 <= static_cast<int32_T>(idn - 1)) {
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
    t = floor_6aYiD2p8(b_thi_0);
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

missionCmd *codegenReal2MissionModelClass::codegenReal2Mission_allocMemPool
    (MemPool_missionCmd *memPool, int32_T width)
{
    missionCmd *dataPtr;

    // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'
    if (memPool->fNumFree > 0) {
        memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree - 1);
        dataPtr = memPool->fFreeList[memPool->fNumFree];
    } else if (memPool->fNumUsed < memPool->fSize) {
        dataPtr = &memPool->fMemArray[memPool->fNumUsed];
        memPool->fNumUsed = static_cast<int32_T>(memPool->fNumUsed + width);
    } else {
        dataPtr = nullptr;
    }

    // End of DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' 
    return dataPtr;
}

Msg_missionCmd codegenReal2MissionModelClass::codegenReal2Mission_createMsg(
    const missionCmd *data)
{
    Msg_missionCmd msg;

    // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'
    msg.fData = codegenReal2Mission_allocMemPool
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd, 1);
    if (msg.fData != nullptr) {
        *msg.fData = *data;
    }

    // End of DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' 
    return msg;
}

void codegenReal2MissionModelClass::codegenReal2Mission_freeMemPool
    (MemPool_missionCmd *memPool, missionCmd *dataPtr)
{
    // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'
    memPool->fFreeList[memPool->fNumFree] = dataPtr;
    memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree + 1);
}

void codegenReal2MissionModelClass::codegenReal2Mission_destroyMsg
    (Msg_missionCmd *msg)
{
    // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'
    codegenReal2Mission_freeMemPool
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd, msg->fData);
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push
    (Buffer_missionCmd *q, Msg_missionCmd *element)
{
    boolean_T isPush;

    // Queue generated from: '<Root>/RcvNextMission'
    if (q->fOccupied) {
        codegenReal2Mission_destroyMsg(&q->fMsg);
    }

    q->fMsg = *element;
    q->fOccupied = true;
    isPush = true;

    // End of Queue generated from: '<Root>/RcvNextMission'
    return isPush;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' incorporates:
    //   Send: '<S6>/PushCMD'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<Root>/RcvNextMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<Root>/RcvNextMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveThisMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' incorporates:
    //   Send: '<S22>/Send'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<Root>/FeedbackCurrentMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_3_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<Root>/FeedbackCurrentMission'
    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_SendData(
    const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' incorporates:
    //   Send: '<S6>/SndImmedCMD'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<Root>/RcvImmedCMD' incorporates:
    //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<Root>/RcvImmedCMD'
    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop
    (Buffer_missionCmd *q, Msg_missionCmd *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<Root>/RcvNextMission'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<Root>/RcvNextMission'
    return isPop;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<Root>/RcvNextMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<Root>/RcvNextMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' incorporates:
    //   Send: '<S18>/SendMission'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<S13>/FlightMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_FlightMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<S13>/FlightMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveCurrentMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S13>/FlightMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'
    //   Receive: '<S14>/ReceiveCurrentMission'

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_FlightMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<S13>/FlightMission'
    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_RecvData
    (missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<Root>/RcvImmedCMD' incorporates:
    //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<Root>/RcvImmedCMD'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<Root>/FeedbackCurrentMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_3_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<Root>/FeedbackCurrentMission'
    return status;
}

// Function for MATLAB Function: '<S9>/TimeConverter'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_m(real_T dd,
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
    c_s = floor_6aYiD2p8(c_ahi_0);
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
    c_s = split_lIfqwsQg(b_c.re);
    b_tmp = b_c.re * 1000.0;
    c_tmp = (c_s.re * 1000.0 - b_tmp) + c_s.im * 1000.0;
    idn = 0;
    if (std::isnan(c_tmp)) {
        idn = 1;
    }

    if (0 <= static_cast<int32_T>(idn - 1)) {
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
    c_s = floor_6aYiD2p8(a);
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_string_string
    (MissionModes val, char_T obj_Value_data[], int32_T obj_Value_size[2])
{
    static const MissionModes enumVals[14]{ 1, 11, 2, 22, 3, 4, 5, 128, 129, 130,
        131, 132, 255, 0 };

    static const char_T ab[15]{ 'F', 'l', 'i', 'g', 'h', 't', 'M', 'i', 's', 's',
        'i', 'o', 'n', 'R', 'H' };

    static const char_T t[13]{ 'C', 'u', 's', 't', 'o', 'm', 'F', 'r', 'm', 'n',
        'N', 'a', 'v' };

    static const char_T y[13]{ 'C', 'o', 'l', 'l', 'A', 'v', 'o', 'i', 'd', 'a',
        'n', 'c', 'e' };

    static const char_T x[12]{ 'D', 'e', 't', 'a', 'i', 'l', 'e', 'd', 'I', 'n',
        's', 'p' };

    static const char_T db[11]{ 'W', 'a', 'i', 't', 'T', 'o', 'S', 't', 'a', 'r',
        't' };

    static const char_T r[11]{ 'C', 'i', 'r', 'c', 'D', 'i', 's', 'p', 'N', 'a',
        'v' };

    static const char_T s[11]{ 'H', 'o', 'r', 'z', 'F', 'r', 'm', 'n', 'N', 'a',
        'v' };

    static const char_T u[9]{ 'R', 'u', 'n', 'W', 'a', 'y', 'N', 'a', 'v' };

    static const char_T w[9]{ 'N', 'e', 'w', 'R', 'u', 'n', 'W', 'a', 'y' };

    static const char_T bb[8]{ 'S', 'q', 'C', 'a', 'l', 'i', 'b', 'r' };

    static const char_T v[8]{ 'P', 'r', 'o', 't', 'L', 'i', 'n', 'e' };

    static const char_T cb[7]{ 'p', 'A', 't', 't', 'a', 'c', 'k' };

    static const char_T q[7]{ 'C', 'i', 'r', 'c', 'N', 'a', 'v' };

    cell_wrap_1_codegenReal2Mission_T b_0[14];
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
    int32_T enumIdx;
    int32_T k;
    int32_T loop_ub;
    boolean_T exitg1;
    b.f1.size[0] = 1;
    b.f1.size[1] = 7;
    for (k = 0; k < 7; k++) {
        b.f1.data[k] = q[k];
    }

    c.f1.size[0] = 1;
    c.f1.size[1] = 11;
    d.f1.size[0] = 1;
    d.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        c.f1.data[k] = r[k];
        d.f1.data[k] = s[k];
    }

    e.f1.size[0] = 1;
    e.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        e.f1.data[k] = t[k];
    }

    f.f1.size[0] = 1;
    f.f1.size[1] = 9;
    for (k = 0; k < 9; k++) {
        f.f1.data[k] = u[k];
    }

    g.f1.size[0] = 1;
    g.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        g.f1.data[k] = v[k];
    }

    h.f1.size[0] = 1;
    h.f1.size[1] = 9;
    for (k = 0; k < 9; k++) {
        h.f1.data[k] = w[k];
    }

    i.f1.size[0] = 1;
    i.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        i.f1.data[k] = x[k];
    }

    j.f1.size[0] = 1;
    j.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        j.f1.data[k] = y[k];
    }

    l.f1.size[0] = 1;
    l.f1.size[1] = 15;
    for (k = 0; k < 15; k++) {
        l.f1.data[k] = ab[k];
    }

    m.f1.size[0] = 1;
    m.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        m.f1.data[k] = bb[k];
    }

    n.f1.size[0] = 1;
    n.f1.size[1] = 7;
    for (k = 0; k < 7; k++) {
        n.f1.data[k] = cb[k];
    }

    o.f1.size[0] = 1;
    o.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        o.f1.data[k] = db[k];
    }

    p.f1.size[0] = 1;
    p.f1.size[1] = 4;
    p.f1.data[0] = 'N';
    p.f1.data[1] = 'o';
    p.f1.data[2] = 'n';
    p.f1.data[3] = 'e';
    enumIdx = -1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
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
    for (k = 0; k <= loop_ub; k++) {
        obj_Value_data[k] = b_0[enumIdx].f1.data[k];
    }
}

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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

        if ((fieldValues_idx_6 < 0.0) || (1000.0 <= fieldValues_idx_6)) {
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
void codegenReal2MissionModelClass::codegenReal2Mission_printIndivMissionCMD(
    const IndividualUAVCmd *IndivMissionCMD, real_T fileID)
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
    real_T varargin_1;
    real_T x;
    int32_T validatedHoleFilling[7];
    int32_T obj_Value_size[2];
    char_T b_varargin_1_data[16];
    char_T obj_Value_data[15];
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
        fprintf(filestar, "Sequence ID:\t\t%d\n", IndivMissionCMD->SequenceID);
        if (autoflush) {
            fflush(filestar);
        }
    }

    codegenReal2Mission_string_string(IndivMissionCMD->MissionMode,
        obj_Value_data, obj_Value_size);
    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        int32_T loop_ub;
        loop_ub = obj_Value_size[1];
        for (int32_T b_varargin_1_data_tmp{0}; b_varargin_1_data_tmp <=
                static_cast<int32_T>(loop_ub - 1); b_varargin_1_data_tmp++) {
            b_varargin_1_data[b_varargin_1_data_tmp] =
                obj_Value_data[b_varargin_1_data_tmp];
        }

        b_varargin_1_data[obj_Value_size[1]] = '\x00';
        fprintf(filestar, "Mission Mode:\t\t%s\n", &b_varargin_1_data[0]);
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
                IndivMissionCMD->MissionLocation.Lat);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLongitude:\t\t%f\n",
                IndivMissionCMD->MissionLocation.Lon);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tAltitude:\t\t%f\n",
                IndivMissionCMD->MissionLocation.Alt);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tHeading:\t\t%f\n",
                IndivMissionCMD->MissionLocation.degHDG);
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
        fprintf(filestar, "\tparam1:\t\t\t%f\n", IndivMissionCMD->params.Param1);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam2:\t\t\t%f\n", IndivMissionCMD->params.Param2);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam3:\t\t\t%f\n", IndivMissionCMD->params.Param3);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam4:\t\t\t%f\n", IndivMissionCMD->params.Param4);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam5:\t\t\t%f\n", IndivMissionCMD->params.Param5);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam6:\t\t\t%f\n", IndivMissionCMD->params.Param6);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam7:\t\t\t%f\n", IndivMissionCMD->params.Param7);
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
                IndivMissionCMD->StartPosition.Lat);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tLongitude:\t\t%f\n",
                IndivMissionCMD->StartPosition.Lon);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tAltitude:\t\t%f\n",
                IndivMissionCMD->StartPosition.Alt);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tHeading:\t\t%f\n",
                IndivMissionCMD->StartPosition.degHDG);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Number of UAVs:\t\t%d\n", IndivMissionCMD->numUAV);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "Formation Position:\t%d\n",
                IndivMissionCMD->FormationPos);
        if (autoflush) {
            fflush(filestar);
        }
    }

    print_processing_OPmXLPoa(IndivMissionCMD->StartTime.year,
        IndivMissionCMD->StartTime.month, IndivMissionCMD->StartTime.day,
        IndivMissionCMD->StartTime.hour, IndivMissionCMD->StartTime.minute,
        IndivMissionCMD->StartTime.second,
        IndivMissionCMD->StartTime.millisecond, validatedHoleFilling);
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
    codegenReal2Mission_getDateVec(TimeNow_data, &varargin_1, &a__1, &a__2,
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
    print_processing_mFrJ8Td3(varargin_1, a__1, a__2, a__3, a__4, std::floor
        (a__5), std::round((a__11 - std::floor(x)) * 1000.0),
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

// Function for MATLAB Function: '<S9>/PrintOnboardLog'
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
            codegenReal2Mission_DW.eml_autoflush[static_cast<int32_T>(
                static_cast<int32_T>(fileid) - 3)] = true;
        }
    }

    return st;
}

void codegenReal2MissionModelClass::codegenReal2Mission_initMemPool
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

// Model step function
void codegenReal2MissionModelClass::step()
{
    // local block i/o variables
    missionCmd rtb_DataStoreRead;
    VectorSpeed rtb_Real2SimGuidance_o16;
    real_T rtb_Real2SimGuidance_o5;
    real_T rtb_Real2SimGuidance_o6;
    real_T rtb_Real2SimGuidance_o7[3];
    real_T rtb_Real2SimGuidance_o8;
    real_T rtb_Real2SimGuidance_o10[3];
    real_T rtb_Real2SimGuidance_o11;
    real_T rtb_Real2SimGuidance_o12;
    real_T rtb_Real2SimGuidance_o13;
    real_T rtb_Real2SimGuidance_o14;
    real_T rtb_Real2SimGuidance_o17;
    real_T rtb_Real2SimGuidance_o18;
    int32_T rtb_intFlightStatus;
    int32_T rtb_intImmedStatus;
    uint8_T rtb_Real2SimGuidance_o15;
    boolean_T rtb_Real2SimGuidance_o9;
    boolean_T rtb_Reset;
    IndividualUAVCmd *tmp_0;
    Location rtb_DataStoreRead_p_MissionLocation;
    missionCmd NewCMD;
    missionCmd rtb_SndCMD;
    missionCmd rtb_ThisCMD;
    creal_T b_this_data;
    creal_T temp_0;
    creal_T temp_1;
    real_T c_tm_year_0[7];
    real_T processedInData[7];
    real_T rtb_MemoryPose[4];
    real_T c_a__35;
    real_T c_tm_mday;
    real_T c_tm_mon;
    real_T c_tm_year;
    real_T check;
    real_T fracSecs;
    real_T second;
    real_T temp;
    real_T tmp;
    real_T validatedHoleFilling_idx_0;
    real_T validatedHoleFilling_idx_1;
    real_T validatedHoleFilling_idx_2;
    real_T validatedHoleFilling_idx_3;
    real_T validatedHoleFilling_idx_4;
    int32_T Y{ 1 };

    int32_T status;
    boolean_T rtb_ReceivePushedMissionCMD_o1;
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

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Receive: '<Root>/ReceivePushedMissionCMD'
        Y = 1;
        MissionCMDRecvData.RecvData
            (&codegenReal2Mission_DW.ReceivePushedMissionCMD_o2, sizeof
             (IndividualUAVCmd), &Y);
        rtb_ReceivePushedMissionCMD_o1 = (Y != 1);

        // DataStoreRead: '<S1>/Data Store Read'
        rtb_DataStoreRead = codegenReal2Mission_DW.cmdFlightMission;

        // Outputs for Enabled SubSystem: '<Root>/MissionValidation' incorporates:
        //   EnablePort: '<S6>/Enable'

        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            codegenReal2Mission_DW.MissionValidation_MODE =
                rtb_ReceivePushedMissionCMD_o1;
        }

        if (codegenReal2Mission_DW.MissionValidation_MODE) {
            int32_T D;
            int32_T H;
            int32_T M;
            int32_T MI;
            int32_T MS;
            int32_T S;

            // MATLAB Function: '<S6>/getCurrentTime'
            // MATLAB Function 'getCurrentTime': '<S32>:1'
            // '<S32>:1:3'
            codegenReal2Mission_getLocalTime(&fracSecs, &check, &temp, &tmp,
                &c_tm_mday, &c_tm_mon, &c_tm_year,
                &rtb_ReceivePushedMissionCMD_o1);
            processedInData[4] = temp;
            processedInData[5] = check;
            processedInData[6] = fracSecs / 1.0E+6;
            second = check;
            fracSecs = processedInData[6];
            check = (((((c_tm_year + c_tm_mon) + c_tm_mday) + tmp) + temp) +
                     check) + processedInData[6];
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isinf(check)) ^ 1))) &
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(std::isnan(check))
                     ^ 1)))))) {
                check = c_tm_year;
                temp = c_tm_mon;
                if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
                    temp = std::floor((c_tm_mon - 1.0) / 12.0);
                    check = c_tm_year + temp;
                    temp = ((c_tm_mon - 1.0) - temp * 12.0) + 1.0;
                }

                if (temp < 3.0) {
                    check--;
                    temp += 9.0;
                } else {
                    temp -= 3.0;
                }

                b_this_data.re = ((((((365.0 * check + std::floor(check / 4.0))
                                      - std::floor(check / 100.0)) + std::floor
                                     (check / 400.0)) + std::floor((153.0 * temp
                                      + 2.0) / 5.0)) + c_tm_mday) + 60.0) -
                    719529.0;
                temp = 1.34217729E+8 * b_this_data.re;
                temp -= temp - b_this_data.re;
                check = b_this_data.re * 8.64E+7;
                temp_0.re = check;
                check = (b_this_data.re - temp) * 8.64E+7 + (temp * 8.64E+7 -
                    check);
                temp_0.im = check;
                if (std::isnan(check)) {
                    temp_0.im = 0.0;
                }

                if ((processedInData[6] < 0.0) || (1000.0 <= processedInData[6]))
                {
                    fracSecs = std::floor(processedInData[6] / 1000.0);
                    second = processedInData[5] + fracSecs;
                    fracSecs = processedInData[6] - fracSecs * 1000.0;
                }

                b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                    (codegenReal2Mission_plus(temp_0, (60.0 * tmp +
                    processedInData[4]) * 60000.0), second * 1000.0), fracSecs);
            } else {
                b_this_data.re = check;
            }

            // MATLAB Function: '<S6>/CommandCheck' incorporates:
            //   DataStoreRead: '<S1>/Data Store Read'
            //   DataStoreRead: '<S6>/ReadPreviousCMD'
            //   MATLAB Function: '<S6>/getCurrentTime'
            //   Receive: '<Root>/ReceivePushedMissionCMD'

            // MATLAB Function 'MissionValidation/CommandCheck': '<S31>:1'
            // '<S31>:1:3'
            codegenReal2Mission_DW.endImmed = false;

            // '<S31>:1:4'
            second = 0.0;

            // '<S31>:1:5'
            rtb_ThisCMD = codegenReal2Mission_DW.MissionCMD;

            // '<S31>:1:6'
            rtb_SndCMD = codegenReal2Mission_DW.MissionCMD;

            // '<S31>:1:10'
            Y = codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.year;

            // '<S31>:1:11'
            M = codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.month;

            // '<S31>:1:12'
            D = codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.day;

            // '<S31>:1:13'
            H = codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.hour;

            // '<S31>:1:14'
            MI =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.minute;

            // '<S31>:1:15'
            S = codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.second;

            // '<S31>:1:16'
            MS =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.millisecond;

            // '<S31>:1:17'
            processedInData[0] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.year);
            processedInData[1] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.month);
            processedInData[2] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.day);
            processedInData[3] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.hour);
            processedInData[4] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.minute);
            processedInData[5] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.second);
            processedInData[6] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartTime.millisecond);
            NewCMD.StartTime = (codegenReal2Mission_createFromDateVec
                                (processedInData)).re / 1000.0;

            // '<S31>:1:19'
            NewCMD.SequenceID =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.SequenceID;

            // '<S31>:1:20'
            NewCMD.MissionMode =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode;

            // '<S31>:1:21'
            NewCMD.MissionLocation =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation;

            // '<S31>:1:22'
            NewCMD.params =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params;

            // '<S31>:1:23'
            NewCMD.StartPosition =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartPosition;

            // '<S31>:1:24'
            NewCMD.numUAV =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.numUAV;

            // '<S31>:1:25'
            NewCMD.FormationPos =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.FormationPos;

            // '<S31>:1:26'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (codegenReal2Mission_isequaln
                     (&codegenReal2Mission_DW.MissionCMD, NewCMD.SequenceID,
                      NewCMD.MissionMode, NewCMD.MissionLocation.Lat,
                      NewCMD.MissionLocation.Lon, NewCMD.MissionLocation.Alt,
                      NewCMD.MissionLocation.degHDG, NewCMD.params.Param1,
                      NewCMD.params.Param2, NewCMD.params.Param3,
                      NewCMD.params.Param4, NewCMD.params.Param5,
                      NewCMD.params.Param6, NewCMD.params.Param7,
                      NewCMD.StartPosition, NewCMD.numUAV, NewCMD.FormationPos,
                      NewCMD.StartTime)) ^ 1))) {
                // '<S31>:1:29'
                if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param7
                    == 1.0F) {
                    // '<S31>:1:31'
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode
                           == MissionModes_None) |
                                                (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode
                           == rtb_DataStoreRead.MissionMode)))) {
                        // '<S31>:1:32'
                        // '<S31>:1:33'
                        // '<S31>:1:35'
                        rtb_ThisCMD = rtb_DataStoreRead;
                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Lat
                            != 0.0) {
                            // '<S31>:1:41'
                            rtb_ThisCMD.MissionLocation.Lat =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Lat;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Lon
                            != 0.0) {
                            // '<S31>:1:41'
                            rtb_ThisCMD.MissionLocation.Lon =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Lon;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Alt
                            != 0.0) {
                            // '<S31>:1:41'
                            rtb_ThisCMD.MissionLocation.Alt =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Alt;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.degHDG
                            != 0.0) {
                            // '<S31>:1:41'
                            rtb_ThisCMD.MissionLocation.degHDG =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.degHDG;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param1
                            != 0.0F) {
                            // '<S31>:1:49'
                            rtb_ThisCMD.params.Param1 =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param1;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param2
                            != 0.0F) {
                            // '<S31>:1:49'
                            rtb_ThisCMD.params.Param2 =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param2;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param3
                            != 0.0F) {
                            // '<S31>:1:49'
                            rtb_ThisCMD.params.Param3 =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param3;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param4
                            != 0.0F) {
                            // '<S31>:1:49'
                            rtb_ThisCMD.params.Param4 =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param4;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param5
                            != 0.0F) {
                            // '<S31>:1:49'
                            rtb_ThisCMD.params.Param5 =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param5;
                        }

                        if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param6
                            != 0.0F) {
                            // '<S31>:1:49'
                            rtb_ThisCMD.params.Param6 =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param6;
                        }

                        // '<S31>:1:49'
                        rtb_ThisCMD.params.Param7 = 1.0F;

                        // '<S31>:1:52'
                        rtb_ThisCMD.SequenceID =
                            codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.SequenceID;

                        // '<S31>:1:53'
                        rtb_ThisCMD.StartTime = NewCMD.StartTime;

                        // '<S31>:1:54'
                        rtb_SndCMD = rtb_ThisCMD;

                        // '<S31>:1:55'
                        printf("Reset flight mission, cancel immediate mission!\n");
                        fflush(stdout);

                        // '<S31>:1:56'
                        codegenReal2Mission_DW.endImmed = true;
                    } else {
                        // '<S31>:1:58'
                        printf("Can not reset flight mission to a new mode!\n");
                        fflush(stdout);
                    }
                } else if (codegenReal2Mission_DW.MissionCMD.SequenceID ==
                           codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.SequenceID)
                {
                    // '<S31>:1:60'
                    // '<S31>:1:61'
                    printf("Use a new Sequence ID for each new mission!\n");
                    fflush(stdout);

                    // '<S31>:1:62'
                    printf("PrevCMD SequenceID: %d\n",
                           codegenReal2Mission_DW.MissionCMD.SequenceID);
                    fflush(stdout);

                    // '<S31>:1:63'
                    printf("NewCMD SequenceID: %d\n", NewCMD.SequenceID);
                    fflush(stdout);
                } else {
                    if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode
                        > 127) {
                        // '<S31>:1:65'
                        // '<S31>:1:66'
                        second = 1.0;

                        // '<S31>:1:67'
                        std::memcpy(&rtb_SndCMD, &NewCMD, sizeof(missionCmd));
                    } else if (b_this_data.re / 1000.0 <= NewCMD.StartTime) {
                        // '<S31>:1:68'
                        // '<S31>:1:70'
                        std::memcpy(&rtb_ThisCMD, &NewCMD, sizeof(missionCmd));

                        // '<S31>:1:71'
                        std::memcpy(&rtb_SndCMD, &NewCMD, sizeof(missionCmd));
                    } else {
                        // '<S31>:1:73'
                        printf("Mission Start Time has already passed!\n");
                        fflush(stdout);
                    }

                    // '<S31>:1:76'
                    printf("Start Time:   %04d-%02d-%02d %02d:%02d:%02d.%03d\n",
                           Y, M, D, H, MI, S, MS);
                    fflush(stdout);

                    // '<S31>:1:78'
                    codegenReal2Mission_getLocalTime(&fracSecs, &c_tm_year_0[5],
                        &c_tm_year_0[4], &c_tm_year_0[3], &c_tm_year_0[2],
                        &c_tm_year_0[1], &c_tm_year_0[0],
                        &rtb_ReceivePushedMissionCMD_o1);
                    c_tm_year_0[6] = fracSecs / 1.0E+6;
                    b_this_data = codegenReal2Mission_createFromDateVec
                        (c_tm_year_0);

                    // '<S31>:1:79'
                    codegenReal2Mission_getDateVec(b_this_data,
                        &validatedHoleFilling_idx_0, &fracSecs, &temp, &tmp,
                        &c_tm_mday, &c_tm_mon);
                    codegenReal2Mission_getDateVec(b_this_data, &fracSecs,
                        &validatedHoleFilling_idx_1, &check, &tmp, &c_tm_mday,
                        &c_tm_mon);
                    codegenReal2Mission_getDateVec(b_this_data, &fracSecs,
                        &check, &validatedHoleFilling_idx_2, &temp, &tmp,
                        &c_tm_mday);
                    codegenReal2Mission_getDateVec(b_this_data, &fracSecs,
                        &check, &temp, &validatedHoleFilling_idx_3, &tmp,
                        &c_tm_mday);
                    codegenReal2Mission_getDateVec(b_this_data, &fracSecs,
                        &check, &temp, &tmp, &validatedHoleFilling_idx_4,
                        &c_tm_mday);
                    codegenReal2Mission_getDateVec(b_this_data, &check, &tmp,
                        &c_tm_mday, &c_tm_mon, &c_tm_year, &fracSecs);
                    codegenReal2Mission_getDateVec(b_this_data, &temp, &tmp,
                        &c_tm_mday, &c_tm_mon, &c_tm_year, &check);
                    codegenReal2Mission_getDateVec(b_this_data, &tmp, &c_tm_mday,
                        &c_tm_mon, &c_tm_year, &c_a__35, &temp);
                    printf("Current Time: %04.0f-%02.0f-%02.0f %02.0f:%02.0f:%02.0f.%03.0f\n",
                           validatedHoleFilling_idx_0,
                           validatedHoleFilling_idx_1,
                           validatedHoleFilling_idx_2,
                           validatedHoleFilling_idx_3,
                           validatedHoleFilling_idx_4, std::floor(fracSecs), std::
                           round(1000.0 * (check - std::floor(temp))));
                    fflush(stdout);
                }
            }

            // End of MATLAB Function: '<S6>/CommandCheck'

            // DataStoreWrite: '<S6>/WriteCurrentCMD'
            codegenReal2Mission_DW.MissionCMD = rtb_ThisCMD;

            // Send: '<S6>/PushCMD' incorporates:
            //   Logic: '<S6>/NOT'

            if (static_cast<boolean_T>(static_cast<int32_T>((second != 0.0) ^ 1)))
            {
                codegenReal2Mission_RcvNextMission_SendData(&rtb_SndCMD);
            }

            // End of Send: '<S6>/PushCMD'

            // Send: '<S6>/SendFeedbackMissionCMD'
            codegenReal2Mission_ReceiveThisMission_SendData(&rtb_SndCMD);

            // Send: '<S6>/SndImmedCMD'
            if (second > 0.0) {
                codegenReal2Mission_RcvImmedCMD_SendData(&rtb_SndCMD);
            }

            // End of Send: '<S6>/SndImmedCMD'
        }

        // End of Outputs for SubSystem: '<Root>/MissionValidation'

        // Receive: '<Root>/RcvNextMission'
        codegenReal2Mission_RcvNextMission_RecvData
            (&codegenReal2Mission_DW.RcvNextMission);

        // MATLAB Function: '<S13>/getCurrentTime'
        // MATLAB Function 'getCurrentTime': '<S19>:1'
        // '<S19>:1:3'
        codegenReal2Mission_getLocalTime(&fracSecs, &check, &temp, &tmp,
            &c_tm_mday, &c_tm_mon, &c_tm_year, &rtb_ReceivePushedMissionCMD_o1);
        processedInData[4] = temp;
        processedInData[5] = check;
        processedInData[6] = fracSecs / 1.0E+6;
        second = check;
        fracSecs = processedInData[6];
        check = (((((c_tm_year + c_tm_mon) + c_tm_mday) + tmp) + temp) + check)
            + processedInData[6];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(check)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(check)) ^ 1)))))) {
            check = c_tm_year;
            temp = c_tm_mon;
            if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
                temp = std::floor((c_tm_mon - 1.0) / 12.0);
                check = c_tm_year + temp;
                temp = ((c_tm_mon - 1.0) - temp * 12.0) + 1.0;
            }

            if (temp < 3.0) {
                check--;
                temp += 9.0;
            } else {
                temp -= 3.0;
            }

            b_this_data.re = ((((((365.0 * check + std::floor(check / 4.0)) -
                                  std::floor(check / 100.0)) + std::floor(check /
                                  400.0)) + std::floor((153.0 * temp + 2.0) /
                                 5.0)) + c_tm_mday) + 60.0) - 719529.0;
            temp = 1.34217729E+8 * b_this_data.re;
            temp -= temp - b_this_data.re;
            check = b_this_data.re * 8.64E+7;
            temp_1.re = check;
            check = (b_this_data.re - temp) * 8.64E+7 + (temp * 8.64E+7 - check);
            temp_1.im = check;
            if (std::isnan(check)) {
                temp_1.im = 0.0;
            }

            if ((processedInData[6] < 0.0) || (1000.0 <= processedInData[6])) {
                fracSecs = std::floor(processedInData[6] / 1000.0);
                second = processedInData[5] + fracSecs;
                fracSecs = processedInData[6] - fracSecs * 1000.0;
            }

            b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(temp_1, (60.0 * tmp + processedInData
                [4]) * 60000.0), second * 1000.0), fracSecs);
        } else {
            b_this_data.re = check;
        }

        second = b_this_data.re / 1000.0;

        // End of MATLAB Function: '<S13>/getCurrentTime'

        // Chart: '<S13>/MisisonCMDTemporalLogic' incorporates:
        //   Receive: '<Root>/RcvNextMission'

        // Gateway: FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
        // During: FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c12_codegenReal2Mission) == 0U)
        {
            // Entry: FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
            codegenReal2Mission_DW.is_active_c12_codegenReal2Mission = 1U;

            // Entry Internal: FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
            // Transition: '<S16>:2'
            codegenReal2Mission_DW.is_c12_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;

            // Entry 'Pending': '<S16>:1'
            codegenReal2Mission_DW.TriggerSend = 0.0;
        } else if (codegenReal2Mission_DW.is_c12_codegenReal2Mission ==
                   codegenReal2Mission_IN_Pending) {
            // During 'Pending': '<S16>:1'
            if (second >= codegenReal2Mission_DW.RcvNextMission.StartTime) {
                // Transition: '<S16>:5'
                codegenReal2Mission_DW.is_c12_codegenReal2Mission =
                    codegenReal2Mission_IN_Sending;

                // Entry 'Sending': '<S16>:3'
                codegenReal2Mission_DW.TriggerSend = 1.0;
            } else {
                codegenReal2Mission_DW.TriggerSend = 0.0;
            }

            // During 'Sending': '<S16>:3'
        } else if (second <= codegenReal2Mission_DW.RcvNextMission.StartTime) {
            // Transition: '<S16>:6'
            codegenReal2Mission_DW.is_c12_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;

            // Entry 'Pending': '<S16>:1'
            codegenReal2Mission_DW.TriggerSend = 0.0;
        }

        // End of Chart: '<S13>/MisisonCMDTemporalLogic'

        // Logic: '<S13>/AND'
        rtb_ReceivePushedMissionCMD_o1 = static_cast<boolean_T>
            (static_cast<int32_T>((codegenReal2Mission_DW.TriggerSend != 0.0) &
              (codegenReal2Mission_DW.RcvNextMission.SequenceID != 0)));

        // Outputs for Triggered SubSystem: '<S13>/TriggerBroadcastAtMissionTime' incorporates:
        //   TriggerPort: '<S18>/ReachMissionTime'

        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE
                   != POS_ZCSIG) & static_cast<int32_T>
                                        (rtb_ReceivePushedMissionCMD_o1)))) {
                // Send: '<S18>/SendMission' incorporates:
                //   Receive: '<Root>/RcvNextMission'

                codegenReal2Mission_ReceiveCurrentMission_SendData
                    (&codegenReal2Mission_DW.RcvNextMission);
            }

            codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE =
                static_cast<ZCSigState>(rtb_ReceivePushedMissionCMD_o1);
        }

        // End of Outputs for SubSystem: '<S13>/TriggerBroadcastAtMissionTime'

        // Outputs for Atomic SubSystem: '<S13>/FlightMission'
        // Receive: '<S14>/ReceiveCurrentMission'
        Y = codegenReal2Mission_ReceiveCurrentMission_RecvData
            (&codegenReal2Mission_DW.ReceiveCurrentMission_o2);
        rtb_ReceivePushedMissionCMD_o1 = (Y != 1);

        // Chart: '<S14>/TriggerStartSim' incorporates:
        //   Constant: '<S20>/Constant'
        //   Constant: '<S21>/Constant'
        //   Logic: '<S14>/AND'
        //   RelationalOperator: '<S20>/Compare'
        //   RelationalOperator: '<S21>/Compare'

        // Gateway: FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
        // During: FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c8_codegenReal2Mission) == 0U)
        {
            // Entry: FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
            codegenReal2Mission_DW.is_active_c8_codegenReal2Mission = 1U;

            // Entry Internal: FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
            // Transition: '<S26>:4'
            codegenReal2Mission_DW.is_c8_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;

            // Entry 'Pending': '<S26>:3'
            codegenReal2Mission_DW.StartSim = false;
        } else if (codegenReal2Mission_DW.is_c8_codegenReal2Mission ==
                   codegenReal2Mission_IN_Pending) {
            // During 'Pending': '<S26>:3'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode
                   != MissionModes_None) &
                                        (codegenReal2Mission_DW.ReceiveCurrentMission_o2.SequenceID
                   > 0)))) {
                // Transition: '<S26>:6'
                codegenReal2Mission_DW.is_c8_codegenReal2Mission =
                    codegenReal2Mission_IN_Running;

                // Entry 'Running': '<S26>:5'
                codegenReal2Mission_DW.StartSim = true;
            } else {
                codegenReal2Mission_DW.StartSim = false;
            }
        } else {
            // During 'Running': '<S26>:5'
            codegenReal2Mission_DW.StartSim = true;
        }

        // End of Chart: '<S14>/TriggerStartSim'

        // DataStoreRead: '<S14>/Data Store Read'
        rtb_DataStoreRead_p_MissionLocation =
            codegenReal2Mission_DW.cmdFlightMission.MissionLocation;

        // Logic: '<S14>/Reset' incorporates:
        //   Logic: '<S14>/NOT'

        rtb_Reset = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((codegenReal2Mission_DW.ReceiveCurrentMission_o2.params.Param7 !=
              0.0F) ^ 1))) & static_cast<int32_T>(rtb_ReceivePushedMissionCMD_o1)));

        // DataTypeConversion: '<S14>/Cast To int32'
        codegenReal2Mission_DW.Reset = static_cast<int32_T>(rtb_Reset);

        // Memory: '<S14>/MemoryPose'
        rtb_MemoryPose[0] = codegenReal2Mission_DW.MemoryPose_PreviousInput[0];
        rtb_MemoryPose[1] = codegenReal2Mission_DW.MemoryPose_PreviousInput[1];
        rtb_MemoryPose[2] = codegenReal2Mission_DW.MemoryPose_PreviousInput[2];
        rtb_MemoryPose[3] = codegenReal2Mission_DW.MemoryPose_PreviousInput[3];

        // ModelReference: '<S14>/PreemptableMissionModeSelector'
        FlightMissionMode(&codegenReal2Mission_DW.StartSim,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode,
                          &rtb_DataStoreRead_p_MissionLocation,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionLocation,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.params,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.StartPosition,
                          &codegenReal2Mission_DW.Reset,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.FormationPos,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.numUAV,
                          &rtb_MemoryPose[0],
                          &codegenReal2Mission_DW.thisTaskStatus_g,
                          &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2,
                          &codegenReal2Mission_DW.PreemptableMissionModeSelector_o3
                          [0],
                          &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));

        // Outputs for Enabled SubSystem: '<S14>/MissionSimUAV' incorporates:
        //   EnablePort: '<S23>/Enable'

        // Outputs for Triggered SubSystem: '<S14>/FeedbackMissionCMD' incorporates:
        //   TriggerPort: '<S22>/Trigger'

        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE
                   != POS_ZCSIG) & static_cast<int32_T>
                                        (rtb_ReceivePushedMissionCMD_o1)))) {
                // DataStoreWrite: '<S22>/Data Store Write' incorporates:
                //   Receive: '<S14>/ReceiveCurrentMission'

                codegenReal2Mission_DW.cmdFlightMission =
                    codegenReal2Mission_DW.ReceiveCurrentMission_o2;

                // Send: '<S22>/Send' incorporates:
                //   Receive: '<S14>/ReceiveCurrentMission'

                codegenReal2Mission_ReceiveThisMission_SendData
                    (&codegenReal2Mission_DW.ReceiveCurrentMission_o2);
            }

            codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE =
                static_cast<ZCSigState>(rtb_ReceivePushedMissionCMD_o1);
            codegenReal2Mission_DW.MissionSimUAV_MODE =
                codegenReal2Mission_DW.StartSim;
        }

        // End of Outputs for SubSystem: '<S14>/FeedbackMissionCMD'
        // End of Outputs for SubSystem: '<S14>/MissionSimUAV'
        // End of Outputs for SubSystem: '<S13>/FlightMission'
    }

    // Outputs for Atomic SubSystem: '<S13>/FlightMission'
    // Outputs for Enabled SubSystem: '<S14>/MissionSimUAV' incorporates:
    //   EnablePort: '<S23>/Enable'

    if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            // DataTypeConversion: '<S23>/Cast To Double'
            codegenReal2Mission_DW.CastToDouble = static_cast<real_T>(rtb_Reset);
        }

        // ModelReference generated from: '<S23>/MissionUavModel'
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

    // End of Outputs for SubSystem: '<S14>/MissionSimUAV'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        boolean_T guard1{ false };

        boolean_T guard2{ false };

        // Outputs for Atomic SubSystem: '<S14>/SailDistance'
        // Chart: '<S24>/EnableSailShift'
        if (static_cast<uint32_T>(codegenReal2Mission_DW.temporalCounter_i1) <
                127U) {
            codegenReal2Mission_DW.temporalCounter_i1 = static_cast<uint8_T>(
                static_cast<uint32_T>(static_cast<uint32_T>
                (codegenReal2Mission_DW.temporalCounter_i1) + 1U));
        }

        // Gateway: FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/SailDistance/EnableSailShift 
        // During: FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/SailDistance/EnableSailShift 
        guard1 = false;
        guard2 = false;
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c7_codegenReal2Mission) == 0U)
        {
            // Entry: FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/SailDistance/EnableSailShift 
            codegenReal2Mission_DW.is_active_c7_codegenReal2Mission = 1U;

            // Entry Internal: FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/SailDistance/EnableSailShift 
            // Transition: '<S27>:5'
            codegenReal2Mission_DW.is_c7_codegenReal2Mission =
                codegenReal2Mission_IN_NotShift;
            codegenReal2Mission_DW.temporalCounter_i1 = 0U;

            // Entry 'NotShift': '<S27>:4'
            guard1 = true;
        } else if (codegenReal2Mission_DW.is_c7_codegenReal2Mission ==
                   codegenReal2Mission_IN_NotShift) {
            // During 'NotShift': '<S27>:4'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((static_cast<uint32_T>
                    (codegenReal2Mission_DW.temporalCounter_i1) >= 100U) &
                                        (codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode
                   == 4)))) {
                // Transition: '<S27>:8'
                codegenReal2Mission_DW.is_c7_codegenReal2Mission =
                    codegenReal2Mission_IN_Shift;

                // Entry 'Shift': '<S27>:6'
                guard2 = true;
            } else {
                guard1 = true;
            }

            // During 'Shift': '<S27>:6'
        } else if (codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode
                   != 4) {
            // Transition: '<S27>:9'
            codegenReal2Mission_DW.is_c7_codegenReal2Mission =
                codegenReal2Mission_IN_NotShift;
            codegenReal2Mission_DW.temporalCounter_i1 = 0U;

            // Entry 'NotShift': '<S27>:4'
            guard1 = true;
        } else {
            guard2 = true;
        }

        if (guard2) {
            // Outputs for Enabled SubSystem: '<S24>/SailShift' incorporates:
            //   EnablePort: '<S28>/Enable'

            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (codegenReal2Mission_DW.SailShift_MODE) ^ 1))) {
                // InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' 
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0;
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0;
                codegenReal2Mission_DW.DiscreteTimeIntegrator_PrevResetState = 0;
                codegenReal2Mission_DW.SailShift_MODE = true;
            }

            // Gain: '<S29>/Gain1'
            fracSecs = 0.017453292519943295 *
                codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionLocation.degHDG;

            // DiscreteIntegrator: '<S28>/Discrete-Time Integrator' incorporates:
            //   Product: '<S28>/Product'
            //   Trigonometry: '<S28>/Cos'
            //   Trigonometry: '<S28>/Sin'

            if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                    (codegenReal2Mission_DW.DiscreteTimeIntegrator_PrevResetState)
                   != 0) | static_cast<int32_T>(rtb_Reset)))) {
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0;
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0;
            }

            second = static_cast<real_T>
                (codegenReal2Mission_DW.ReceiveCurrentMission_o2.params.Param4) *
                std::cos(fracSecs) * 0.05;
            fracSecs = static_cast<real_T>
                (codegenReal2Mission_DW.ReceiveCurrentMission_o2.params.Param4) *
                std::sin(fracSecs) * 0.05;

            // DiscreteIntegrator: '<S28>/Discrete-Time Integrator'
            codegenReal2Mission_DW.DiscreteTimeIntegrator[0] =
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[0] + second;

            // Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator'
            codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[0] =
                codegenReal2Mission_DW.DiscreteTimeIntegrator[0] + second;

            // DiscreteIntegrator: '<S28>/Discrete-Time Integrator'
            codegenReal2Mission_DW.DiscreteTimeIntegrator[1] =
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[1] +
                fracSecs;

            // Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator'
            codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[1] =
                codegenReal2Mission_DW.DiscreteTimeIntegrator[1] + fracSecs;
            codegenReal2Mission_DW.DiscreteTimeIntegrator_PrevResetState =
                static_cast<int8_T>(rtb_Reset);

            // End of Outputs for SubSystem: '<S24>/SailShift'

            // Switch: '<S24>/Switch'
            second = codegenReal2Mission_DW.DiscreteTimeIntegrator[0];
            fracSecs = codegenReal2Mission_DW.DiscreteTimeIntegrator[1];
        }

        if (guard1) {
            // Outputs for Enabled SubSystem: '<S24>/SailShift' incorporates:
            //   EnablePort: '<S28>/Enable'

            codegenReal2Mission_DW.SailShift_MODE = false;

            // End of Outputs for SubSystem: '<S24>/SailShift'

            // Switch: '<S24>/Switch' incorporates:
            //   Constant: '<S24>/Zero'

            second = 0.0;
            fracSecs = 0.0;
        }

        // End of Chart: '<S24>/EnableSailShift'
        // End of Outputs for SubSystem: '<S14>/SailDistance'

        // Outputs for Atomic SubSystem: '<S14>/SimState2Pose'
        // SignalConversion generated from: '<S25>/Pose' incorporates:
        //   Gain: '<S25>/Gain2'

        codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [0] = codegenReal2Mission_DW.North;
        codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [1] = codegenReal2Mission_DW.East;
        codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [2] = -codegenReal2Mission_DW.Height;
        codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [3] = codegenReal2Mission_DW.HeadingAngle;

        // End of Outputs for SubSystem: '<S14>/SimState2Pose'

        // Sum: '<S14>/SumEast'
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.East
            = codegenReal2Mission_DW.East + fracSecs;

        // Sum: '<S14>/SumNorth'
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.North
            = codegenReal2Mission_DW.North + second;

        // BusCreator generated from: '<S4>/ImmedMission'
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.Height
            = codegenReal2Mission_DW.Height;
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.AirSpeed
            = codegenReal2Mission_DW.AirSpeed;
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.HeadingAngle
            = codegenReal2Mission_DW.HeadingAngle;
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.FlightPathAngle
            = codegenReal2Mission_DW.FlightPathAngle;
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.RollAngle
            = codegenReal2Mission_DW.RollAngle;
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.RollAngleRate
            = codegenReal2Mission_DW.RollAngleRate;

        // Receive: '<Root>/RcvImmedCMD'
        Y = codegenReal2Mission_RcvImmedCMD_RecvData
            (&codegenReal2Mission_DW.RcvImmedCMD_o2);

        // Receive: '<Root>/RcvImmedCMD'
        codegenReal2Mission_DW.RcvImmedCMD_o1 = (Y != 1);

        // ModelReference generated from: '<S4>/ImmedMission' incorporates:
        //   Inport: '<Root>/OtherUAVstate'
        //   Inport: '<Root>/StateFCU'

        ImmedMission
            (&codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1,
             &codegenReal2Mission_DW.RcvImmedCMD_o2,
             &codegenReal2Mission_DW.endImmed,
             &codegenReal2Mission_DW.RcvImmedCMD_o1,
             &codegenReal2Mission_U.StateFCU_b.RealUAVState,
             &rtb_DataStoreRead.MissionMode,
             &rtb_DataStoreRead.MissionLocation.Lat,
             &rtb_DataStoreRead.MissionLocation.Lon,
             &rtb_DataStoreRead.MissionLocation.Alt,
             &rtb_DataStoreRead.MissionLocation.degHDG,
             &rtb_DataStoreRead.params.Param3, &rtb_DataStoreRead.numUAV,
             &rtb_DataStoreRead.FormationPos,
             &codegenReal2Mission_U.OtherUAVstate[0],
             &codegenReal2Mission_DW.thisTaskStatus,
             &codegenReal2Mission_DW.ImmedMission_o2,
             &codegenReal2Mission_DW.ImmedMission_o3[0],
             &codegenReal2Mission_DW.ImmedMission_o4,
             &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw),
             &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtzce));

        // Chart: '<S13>/NewMission'
        // Gateway: FlightMission_Variant/VariantScheduler/SingleUAV/NewMission
        Y = codegenReal2Mission_DW.followSwitch_start;
        codegenReal2Mission_DW.followSwitch_start =
            codegenReal2Mission_DW.RcvNextMission.SequenceID;

        // During: FlightMission_Variant/VariantScheduler/SingleUAV/NewMission
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c14_codegenReal2Mission) == 0U)
        {
            // Entry: FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
            codegenReal2Mission_DW.is_active_c14_codegenReal2Mission = 1U;

            // Entry Internal: FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
            // Transition: '<S17>:3'
            // Entry 'TriggerNewMission': '<S17>:2'
            codegenReal2Mission_DW.NewMission = true;

            // During 'TriggerNewMission': '<S17>:2'
        } else if (Y != codegenReal2Mission_DW.followSwitch_start) {
            // Transition: '<S17>:4'
            // Entry 'TriggerNewMission': '<S17>:2'
            codegenReal2Mission_DW.NewMission = true;
        } else {
            codegenReal2Mission_DW.NewMission = false;
        }

        // End of Chart: '<S13>/NewMission'

        // Outputs for Atomic SubSystem: '<S13>/JumpDelay'
        // Outputs for Atomic SubSystem: '<S15>/ComputDelay'
        // Switch: '<S30>/AllPositivePosSwitch' incorporates:
        //   DataTypeConversion: '<S30>/doubleFormPos'
        //   DataTypeConversion: '<S30>/doubleNumUAV'
        //   Sum: '<S30>/Minus'

        if (codegenReal2Mission_DW.RcvNextMission.FormationPos > 0) {
            fracSecs = static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.FormationPos);
        } else {
            fracSecs = static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.numUAV) -
                static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.FormationPos);
        }

        // End of Switch: '<S30>/AllPositivePosSwitch'

        // Product: '<S30>/DivideThree' incorporates:
        //   Bias: '<S30>/Bias'
        //   Constant: '<S30>/Three'
        //   Math: '<S30>/ModThree'
        //   Product: '<S30>/DivideByThree'
        //   Rounding: '<S30>/idxCeil'

        codegenReal2Mission_DW.DivideThree = (rt_modd_snf(std::ceil(fracSecs /
            3.0), 3.0) + 1.0) / 3.0;

        // End of Outputs for SubSystem: '<S15>/ComputDelay'
        // End of Outputs for SubSystem: '<S13>/JumpDelay'
    }

    // End of Outputs for SubSystem: '<S13>/FlightMission'

    // ModelReference: '<S7>/Real2SimGuidance' incorporates:
    //   Inport: '<Root>/FlightMode'
    //   Inport: '<Root>/StateFCU'
    //   Outport: '<Root>/FCUCMD'

    Real2SimGuidance(&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
                     &codegenReal2Mission_DW.NewMission,
                     &codegenReal2Mission_U.FlightMode,
                     &codegenReal2Mission_U.StateFCU_b,
                     &codegenReal2Mission_DW.ImmedMission_o3[0],
                     &codegenReal2Mission_DW.ImmedMission_o2,
                     &codegenReal2Mission_DW.ImmedMission_o4,
                     &codegenReal2Mission_DW.DivideThree,
                     &codegenReal2Mission_Y.FCUCMD_i,
                     &codegenReal2Mission_DW.EngagedFlag_Log,
                     &codegenReal2Mission_DW.Real2SimGuidance_o3,
                     &codegenReal2Mission_DW.Real2SimGuidance_o4,
                     &rtb_Real2SimGuidance_o5, &rtb_Real2SimGuidance_o6,
                     &rtb_Real2SimGuidance_o7[0], &rtb_Real2SimGuidance_o8,
                     &rtb_Real2SimGuidance_o9, &rtb_Real2SimGuidance_o10[0],
                     &rtb_Real2SimGuidance_o11, &rtb_Real2SimGuidance_o12,
                     &rtb_Real2SimGuidance_o13, &rtb_Real2SimGuidance_o14,
                     &rtb_Real2SimGuidance_o15, &rtb_Real2SimGuidance_o16,
                     &rtb_Real2SimGuidance_o17, &rtb_Real2SimGuidance_o18,
                     &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
                     &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Receive: '<S1>/ReceiveThisMission'
        Y = codegenReal2Mission_ReceiveThisMission_RecvData
            (&codegenReal2Mission_DW.ReceiveThisMission_o2);
        rtb_ReceivePushedMissionCMD_o1 = (Y != 1);

        // Outputs for Triggered SubSystem: '<S1>/TriggerCurrentMisisonFeedback' incorporates:
        //   TriggerPort: '<S9>/Trigger'

        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE
                   != POS_ZCSIG) & static_cast<int32_T>
                                        (rtb_ReceivePushedMissionCMD_o1)))) {
                // MATLAB Function: '<S9>/TimeConverter'
                // MATLAB Function 'FeedbackCurrentMission/TriggerCurrentMisisonFeedback/TimeConverter': '<S11>:1' 
                // '<S11>:1:7'
                second = codegenReal2Mission_DW.ReceiveThisMission_o2.StartTime *
                    1000.0;

                // '<S11>:1:9'
                codegenReal2Mission_getDateVec_m(second, &check, &fracSecs,
                    &temp, &tmp, &c_tm_mday, &c_tm_mon);
                fracSecs = std::round(check);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.year =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.year =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.year = MAX_int32_T;
                }

                // '<S11>:1:10'
                codegenReal2Mission_getDateVec_m(second, &fracSecs, &temp,
                    &check, &tmp, &c_tm_mday, &c_tm_mon);
                fracSecs = std::round(temp);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.month =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.month =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.month =
                        MAX_int32_T;
                }

                // '<S11>:1:11'
                codegenReal2Mission_getDateVec_m(second, &fracSecs, &check,
                    &c_tm_mon, &temp, &tmp, &c_tm_mday);
                fracSecs = std::round(c_tm_mon);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.day =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.day =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.day = MAX_int32_T;
                }

                // '<S11>:1:12'
                codegenReal2Mission_getDateVec_m(second, &fracSecs, &check,
                    &temp, &c_tm_mon, &tmp, &c_tm_mday);
                fracSecs = std::round(c_tm_mon);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.hour =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.hour =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.hour = MAX_int32_T;
                }

                // '<S11>:1:13'
                codegenReal2Mission_getDateVec_m(second, &fracSecs, &check,
                    &temp, &tmp, &c_tm_mon, &c_tm_mday);
                fracSecs = std::round(c_tm_mon);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                        MAX_int32_T;
                }

                // '<S11>:1:14'
                codegenReal2Mission_getDateVec_m(second, &check, &tmp,
                    &c_tm_mday, &c_tm_mon, &c_tm_year, &temp);
                fracSecs = std::floor(temp);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.second =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.second =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.second =
                        MAX_int32_T;
                }

                // '<S11>:1:15'
                codegenReal2Mission_getDateVec_m(second, &temp, &tmp, &c_tm_mday,
                    &c_tm_mon, &c_tm_year, &check);
                codegenReal2Mission_getDateVec_m(second, &tmp, &c_tm_mday,
                    &c_tm_mon, &c_tm_year, &c_a__35, &fracSecs);
                fracSecs = std::round((check - std::floor(fracSecs)) * 1000.0);
                if (fracSecs < 2.147483648E+9) {
                    if (fracSecs >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                            static_cast<int32_T>(fracSecs);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                        MAX_int32_T;
                }

                // End of MATLAB Function: '<S9>/TimeConverter'

                // BusCreator: '<S9>/IndivCMD'
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

                // MATLAB Function: '<S9>/PrintOnboardLog' incorporates:
                //   BusCreator: '<S9>/IndivCMD'

                // MATLAB Function 'FeedbackCurrentMission/TriggerCurrentMisisonFeedback/PrintOnboardLog': '<S10>:1' 
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (codegenReal2Mission_DW.NewRun_not_empty)
                      ^ 1))) {
                    int8_T fileid;

                    // '<S10>:1:5'
                    // '<S10>:1:7'
                    fileid = codegenReal2Mission_cfopen("OnboardMissionCMD.log",
                        "wb");
                    Y = static_cast<int32_T>(fileid);

                    // '<S10>:1:7'
                    codegenReal2Mission_DW.NewRun = 1.0;
                    codegenReal2Mission_DW.NewRun_not_empty = true;
                } else {
                    int8_T fileid;

                    // '<S10>:1:9'
                    fileid = codegenReal2Mission_cfopen("OnboardMissionCMD.log",
                        "ab");
                    Y = static_cast<int32_T>(fileid);

                    // '<S10>:1:9'
                    codegenReal2Mission_DW.NewRun++;
                }

                // '<S10>:1:13'
                tmp_0 = &codegenReal2Mission_DW.IndivCMD;
                codegenReal2Mission_printIndivMissionCMD(tmp_0,
                    static_cast<real_T>(Y));

                // '<S10>:1:16'
                codegenReal2Mission_cfclose(static_cast<real_T>(Y));

                // End of MATLAB Function: '<S9>/PrintOnboardLog'

                // Send: '<S9>/Send' incorporates:
                //   BusCreator: '<S9>/IndivCMD'

                CurrentMissionSendData.SendData(&codegenReal2Mission_DW.IndivCMD,
                    sizeof(IndividualUAVCmd), &status);
            }

            codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
                static_cast<ZCSigState>(rtb_ReceivePushedMissionCMD_o1);
        }

        // End of Outputs for SubSystem: '<S1>/TriggerCurrentMisisonFeedback'

        // Memory: '<S1>/MemoryFlightStatus'
        codegenReal2Mission_Y.MissionFB.FlightStatus =
            codegenReal2Mission_DW.MemoryFlightStatus_PreviousInput;

        // Memory: '<S1>/MemoryImmedStatus'
        codegenReal2Mission_Y.MissionFB.ImmedStatus =
            codegenReal2Mission_DW.MemoryImmedStatus_PreviousInput;

        // BusCreator: '<S1>/CreateStatusBus' incorporates:
        //   Outport: '<Root>/MissionFB'

        codegenReal2Mission_Y.MissionFB.EngagedFlag =
            codegenReal2Mission_DW.EngagedFlag_Log;
        codegenReal2Mission_Y.MissionFB.SequenceID =
            codegenReal2Mission_DW.ReceiveThisMission_o2.SequenceID;
        codegenReal2Mission_Y.MissionFB.MissionMode =
            rtb_DataStoreRead.MissionMode;
        codegenReal2Mission_Y.MissionFB.numUAV = rtb_DataStoreRead.numUAV;
        codegenReal2Mission_Y.MissionFB.FormationPos =
            rtb_DataStoreRead.FormationPos;

        // DataTypeConversion: '<S1>/intFlightStatus'
        fracSecs = std::floor(codegenReal2Mission_DW.thisTaskStatus_g);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(fracSecs)) | static_cast<int32_T>(std::isinf(fracSecs)))))
        {
            fracSecs = 0.0;
        } else {
            fracSecs = std::fmod(fracSecs, 4.294967296E+9);
        }

        // DataTypeConversion: '<S1>/intFlightStatus'
        rtb_intFlightStatus = fracSecs < 0.0 ? static_cast<int32_T>(-
            static_cast<int32_T>(static_cast<uint32_T>(-fracSecs))) :
            static_cast<int32_T>(static_cast<uint32_T>(fracSecs));

        // DataTypeConversion: '<S1>/intImmedStatus'
        fracSecs = std::floor(codegenReal2Mission_DW.thisTaskStatus);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(fracSecs)) | static_cast<int32_T>(std::isinf(fracSecs)))))
        {
            fracSecs = 0.0;
        } else {
            fracSecs = std::fmod(fracSecs, 4.294967296E+9);
        }

        // DataTypeConversion: '<S1>/intImmedStatus'
        rtb_intImmedStatus = fracSecs < 0.0 ? static_cast<int32_T>
            (-static_cast<int32_T>(static_cast<uint32_T>(-fracSecs))) :
            static_cast<int32_T>(static_cast<uint32_T>(fracSecs));
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Matfile logging
        rt_UpdateTXYLogVars((&codegenReal2Mission_M)->rtwLogInfo,
                            ((&codegenReal2Mission_M)->Timing.t));
    }                                  // end MajorTimeStep

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Update for Atomic SubSystem: '<S13>/FlightMission'
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            // Update for Memory: '<S14>/MemoryPose'
            codegenReal2Mission_DW.MemoryPose_PreviousInput[0] =
                codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
                [0];
            codegenReal2Mission_DW.MemoryPose_PreviousInput[1] =
                codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
                [1];
            codegenReal2Mission_DW.MemoryPose_PreviousInput[2] =
                codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
                [2];
            codegenReal2Mission_DW.MemoryPose_PreviousInput[3] =
                codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
                [3];

            // Update for ModelReference: '<S14>/PreemptableMissionModeSelector' 
            FlightMissionMode_Update
                (&(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));
        }

        // Update for Enabled SubSystem: '<S14>/MissionSimUAV' incorporates:
        //   EnablePort: '<S23>/Enable'

        if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
            // Update for ModelReference generated from: '<S23>/MissionUavModel' 
            MissionUAV_Update
                (&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw));
        }

        // End of Update for SubSystem: '<S14>/MissionSimUAV'
        // End of Update for SubSystem: '<S13>/FlightMission'
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            // Update for ModelReference generated from: '<S4>/ImmedMission'
            ImmedMission_Update
                (&codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1,
                 &codegenReal2Mission_DW.EngagedFlag_Log,
                 &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw));
        }

        // Update for ModelReference: '<S7>/Real2SimGuidance'
        Real2SimGuidance_Update
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
             &codegenReal2Mission_DW.Real2SimGuidance_o4,
             &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw));
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            // Update for Memory: '<S1>/MemoryFlightStatus'
            codegenReal2Mission_DW.MemoryFlightStatus_PreviousInput =
                rtb_intFlightStatus;

            // Update for Memory: '<S1>/MemoryImmedStatus'
            codegenReal2Mission_DW.MemoryImmedStatus_PreviousInput =
                rtb_intImmedStatus;
        }
    }                                  // end MajorTimeStep

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // signal main to stop simulation
        {                              // Sample time: [0.0s, 0.0s]
            if ((rtmGetTFinal((&codegenReal2Mission_M))!=-1) &&
                !((rtmGetTFinal((&codegenReal2Mission_M))-
                    ((((&codegenReal2Mission_M)->Timing.clockTick1+
                       (&codegenReal2Mission_M)->Timing.clockTickH1*
                       4294967296.0)) * 0.1)) > ((((&codegenReal2Mission_M)
                    ->Timing.clockTick1+(&codegenReal2Mission_M)
                    ->Timing.clockTickH1* 4294967296.0)) * 0.1) * (DBL_EPSILON)))
            {
                rtmSetErrorStatus((&codegenReal2Mission_M),
                                  "Simulation finished");
            }
        }

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
    // Derivatives for Atomic SubSystem: '<S13>/FlightMission'
    // Derivatives for Enabled SubSystem: '<S14>/MissionSimUAV'
    if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
        // Derivatives for ModelReference generated from: '<S23>/MissionUavModel' 
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

    // End of Derivatives for SubSystem: '<S14>/MissionSimUAV'
    // End of Derivatives for SubSystem: '<S13>/FlightMission'

    // Derivatives for ModelReference: '<S7>/Real2SimGuidance'
    Real2SimGuidance_Deriv
        (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
         &(((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs)
           ->Real2SimGuidance_CSTATE));
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
        rtsiSetSolverName(&(&codegenReal2Mission_M)->solverInfo,"ode4");
        rtmSetTPtr((&codegenReal2Mission_M), &(&codegenReal2Mission_M)
                   ->Timing.tArray[0]);
        rtmSetTFinal((&codegenReal2Mission_M), -1);
        (&codegenReal2Mission_M)->Timing.stepSize0 = 0.1;
        rtmSetFirstInitCond((&codegenReal2Mission_M), 1);

        // Setup for data logging
        {
            static RTWLogInfo rt_DataLoggingInfo;
            rt_DataLoggingInfo.loggingInterval = (nullptr);
            (&codegenReal2Mission_M)->rtwLogInfo = &rt_DataLoggingInfo;
        }

        // Setup for data logging
        {
            rtliSetLogXSignalInfo((&codegenReal2Mission_M)->rtwLogInfo, (nullptr));
            rtliSetLogXSignalPtrs((&codegenReal2Mission_M)->rtwLogInfo, (nullptr));
            rtliSetLogT((&codegenReal2Mission_M)->rtwLogInfo, "");
            rtliSetLogX((&codegenReal2Mission_M)->rtwLogInfo, "");
            rtliSetLogXFinal((&codegenReal2Mission_M)->rtwLogInfo, "");
            rtliSetLogVarNameModifier((&codegenReal2Mission_M)->rtwLogInfo,
                "rt_");
            rtliSetLogFormat((&codegenReal2Mission_M)->rtwLogInfo, 4);
            rtliSetLogMaxRows((&codegenReal2Mission_M)->rtwLogInfo, 0);
            rtliSetLogDecimation((&codegenReal2Mission_M)->rtwLogInfo, 1);
            rtliSetLogY((&codegenReal2Mission_M)->rtwLogInfo, "");
            rtliSetLogYSignalInfo((&codegenReal2Mission_M)->rtwLogInfo, (nullptr));
            rtliSetLogYSignalPtrs((&codegenReal2Mission_M)->rtwLogInfo, (nullptr));
        }
    }

    {
        static uint32_T *clockTickPtrs[3];
        static uint32_T *clockTickHPtrs[3];
        static real_T *taskTimePtrs[3];
        (&codegenReal2Mission_M)->timingBridge.nTasks = 3;
        clockTickPtrs[0] = &((&codegenReal2Mission_M)->Timing.clockTick0);
        clockTickHPtrs[0] = &((&codegenReal2Mission_M)->Timing.clockTickH0);
        clockTickPtrs[1] = &((&codegenReal2Mission_M)->Timing.clockTick1);
        clockTickHPtrs[1] = &((&codegenReal2Mission_M)->Timing.clockTickH1);
        clockTickPtrs[2] = (nullptr);
        clockTickHPtrs[2] = (nullptr);
        (&codegenReal2Mission_M)->timingBridge.clockTick = clockTickPtrs;
        (&codegenReal2Mission_M)->timingBridge.clockTickH = clockTickHPtrs;
        taskTimePtrs[0] = &((&codegenReal2Mission_M)->Timing.t[0]);
        taskTimePtrs[1] = (nullptr);
        taskTimePtrs[2] = (nullptr);
        (&codegenReal2Mission_M)->timingBridge.taskTime = taskTimePtrs;
        (&codegenReal2Mission_M)->timingBridge.firstInitCond =
            &rtmIsFirstInitCond((&codegenReal2Mission_M));
    }

    // Model Initialize function for ModelReference Block: '<S2>/CodegenLogging' 
    codegenLogging_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
        &(codegenReal2Mission_DW.CodegenLogging_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S14>/PreemptableMissionModeSelector' 
    FlightMissionMode_initialize(rtmGetErrorStatusPointer
        ((&codegenReal2Mission_M)),
        &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S7>/Real2SimGuidance' 
    Real2SimGuidance_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
        rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
        &((&codegenReal2Mission_M)->solverInfo),
        &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S23>/MissionUavModel' 
    MissionUAV_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                          rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
                          &((&codegenReal2Mission_M)->solverInfo),
                          &(&codegenReal2Mission_M)->timingBridge,
                          &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
                          &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtzce));

    // Model Initialize function for ModelReference Block: '<S4>/ImmedMission'
    ImmedMission_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                            &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtm));

    // Matfile logging
    rt_StartDataLoggingWithStartTime((&codegenReal2Mission_M)->rtwLogInfo, 0.0,
        rtmGetTFinal((&codegenReal2Mission_M)), (&codegenReal2Mission_M)
        ->Timing.stepSize0, (&rtmGetErrorStatus((&codegenReal2Mission_M))));

    {
        FILE* a;

        // Start for slMsgMgr: '<Root>/slMsgMgr'
        codegenReal2Mission_initMemPool
            (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd,
             &codegenReal2Mission_DW.slMsgMgr_memArray_missionCmd[0],
             &codegenReal2Mission_DW.slMsgMgr_freeList_missionCmd[0], 9);
        codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
            POS_ZCSIG;
        codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE = POS_ZCSIG;
        codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE =
            POS_ZCSIG;

        // InitializeConditions for DataStoreMemory generated from: '<S5>/DSAltitudeGCS' 
        rtw_pthread_mutex_init(&AltitudeGCS_m0);

        // InitializeConditions for DataStoreMemory generated from: '<S5>/DSLatitudeGCS' 
        rtw_pthread_mutex_init(&LatitudeGCS_m0);

        // InitializeConditions for DataStoreMemory generated from: '<S5>/DSLongitudeGCS' 
        rtw_pthread_mutex_init(&LongitudeGCS_m0);

        // SystemInitialize for Atomic SubSystem: '<S13>/FlightMission'
        // SystemInitialize for ModelReference: '<S14>/PreemptableMissionModeSelector' 
        FlightMissionMode_Init
            (&codegenReal2Mission_DW.PreemptableMissionModeSelector_o2,
             &codegenReal2Mission_DW.PreemptableMissionModeSelector_o3[0],
             &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));

        // SystemInitialize for Enabled SubSystem: '<S14>/MissionSimUAV'
        // SystemInitialize for ModelReference generated from: '<S23>/MissionUavModel' 
        MissionUAV_Init
            (&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
             &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw),
             &(codegenReal2Mission_X.MissionUavModel_CSTATE));

        // End of SystemInitialize for SubSystem: '<S14>/MissionSimUAV'
        // End of SystemInitialize for SubSystem: '<S13>/FlightMission'

        // SystemInitialize for ModelReference generated from: '<S4>/ImmedMission' 
        ImmedMission_Init(&codegenReal2Mission_DW.ImmedMission_o3[0],
                          &codegenReal2Mission_DW.ImmedMission_o4,
                          &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw),
                          &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtzce));

        // SystemInitialize for ModelReference: '<S7>/Real2SimGuidance'
        Real2SimGuidance_Init
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
             &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));

        // SystemInitialize for Triggered SubSystem: '<S1>/TriggerCurrentMisisonFeedback' 
        // SystemInitialize for MATLAB Function: '<S9>/PrintOnboardLog'
        a = NULL;
        for (int32_T i{0}; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S9>/PrintOnboardLog'
        // End of SystemInitialize for SubSystem: '<S1>/TriggerCurrentMisisonFeedback' 

        // Outputs for Atomic SubSystem: '<Root>/InitializeSimLocation'
        // DataStoreWrite: '<S5>/DSAltitudeGCS' incorporates:
        //   Constant: '<S5>/AltitudeGCS'

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        AltitudeGCS = GCS_Altitude;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);

        // DataStoreWrite: '<S5>/DSLatitudeGCS' incorporates:
        //   Constant: '<S5>/LatitudeGCS'

        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        LatitudeGCS = GCS_Latitude;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);

        // DataStoreWrite: '<S5>/DSLongitudeGCS' incorporates:
        //   Constant: '<S5>/LongitudeGCS'

        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        LongitudeGCS = GCS_Longitude;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);

        // End of Outputs for SubSystem: '<Root>/InitializeSimLocation'
    }

    // set "at time zero" to false
    if (rtmIsFirstInitCond((&codegenReal2Mission_M))) {
        rtmSetFirstInitCond((&codegenReal2Mission_M), 0);
    }
}

// Model terminate function
void codegenReal2MissionModelClass::terminate()
{
    // Terminate for DataStoreMemory generated from: '<S5>/DSAltitudeGCS'
    rtw_pthread_mutex_destroy(AltitudeGCS_m0);

    // Terminate for DataStoreMemory generated from: '<S5>/DSLatitudeGCS'
    rtw_pthread_mutex_destroy(LatitudeGCS_m0);

    // Terminate for DataStoreMemory generated from: '<S5>/DSLongitudeGCS'
    rtw_pthread_mutex_destroy(LongitudeGCS_m0);
}

// Constructor
codegenReal2MissionModelClass::codegenReal2MissionModelClass
    (SendData_IndividualUAVCmdT& CurrentMissionSendData_arg,
     RecvData_IndividualUAVCmdT& MissionCMDRecvData_arg) :
    codegenReal2Mission_U(),
    codegenReal2Mission_Y(),
    codegenReal2Mission_DW(),
    codegenReal2Mission_X(),
    codegenReal2Mission_PrevZCX(),
    CurrentMissionSendData(CurrentMissionSendData_arg),
    MissionCMDRecvData(MissionCMDRecvData_arg),
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
