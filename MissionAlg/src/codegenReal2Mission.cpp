//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 3.201
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Wed Apr 13 04:41:14 2022
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
#include "div_nde_s32_floor.h"
#include "div_s32.h"
#include "div_s32_floor.h"
#include "floor_6aYiD2p8.h"
#include "print_processing_OPmXLPoa.h"
#include "print_processing_mFrJ8Td3.h"
#include "rt_modd_snf.h"
#include "split_lIfqwsQg.h"

// Named constants for Chart: '<S14>/TriggerStartSim'
const uint8_T codegenReal2Mission_IN_Pending{ 1U };

const uint8_T codegenReal2Mission_IN_Running{ 2U };

// Named constants for Chart: '<S13>/MisisonCMDTemporalLogic'
const uint8_T codegenReal2Mission_IN_Sending{ 2U };

// Named constants for Chart: '<S13>/NewMission'
const uint8_T codegenReal2Mission_IN_Enter{ 1U };

const uint8_T codegenReal2Mission_IN_New{ 2U };

const uint8_T codegenReal2Mission_IN_Wait{ 3U };

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

// Function for MATLAB Function: '<S28>/CommandCheck'
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

// Function for MATLAB Function: '<S28>/CommandCheck'
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

// Function for MATLAB Function: '<S28>/CommandCheck'
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

// Function for MATLAB Function: '<S28>/CommandCheck'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isPalindrome
    (MissionModes inputNum)
{
    real_T divisor;
    int32_T b_inputNum;
    boolean_T result;
    b_inputNum = inputNum;
    for (divisor = 1.0; std::round(static_cast<real_T>(inputNum) / divisor) >=
            10.0; divisor *= 10.0) {
    }

    int32_T exitg1;
    do {
        exitg1 = 0;
        if (b_inputNum != 0) {
            real_T r;
            int32_T tmp;
            r = std::round(static_cast<real_T>(b_inputNum) / divisor);
            if (r < 2.147483648E+9) {
                if (r >= -2.147483648E+9) {
                    tmp = static_cast<int32_T>(r);
                } else {
                    tmp = MIN_int32_T;
                }
            } else {
                tmp = MAX_int32_T;
            }

            if (static_cast<int32_T>(b_inputNum - static_cast<int32_T>
                                     (div_nde_s32_floor(b_inputNum, 10) * 10))
                    != tmp) {
                result = false;
                exitg1 = 1;
            } else {
                if (divisor < 2.147483648E+9) {
                    tmp = static_cast<int32_T>(divisor);
                } else {
                    tmp = MAX_int32_T;
                }

                if (static_cast<real_T>(tmp) == divisor) {
                    if (tmp != 0) {
                        b_inputNum = static_cast<int32_T>(b_inputNum -
                            static_cast<int32_T>(div_s32_floor(b_inputNum, tmp) *
                            tmp));
                    }
                } else {
                    r = static_cast<real_T>(b_inputNum);
                    if (divisor == 0.0) {
                        if (b_inputNum == 0) {
                            r = 0.0;
                        }
                    } else if (b_inputNum == 0) {
                        r = 0.0;
                    } else if (std::isinf(divisor)) {
                        if (b_inputNum < 0) {
                            r = divisor;
                        }
                    } else {
                        r = std::fmod(static_cast<real_T>(b_inputNum), divisor);
                        if (r == 0.0) {
                            r = divisor * 0.0;
                        } else if (b_inputNum < 0) {
                            r += divisor;
                        }
                    }

                    if (r < 2.147483648E+9) {
                        b_inputNum = static_cast<int32_T>(r);
                    } else {
                        b_inputNum = MAX_int32_T;
                    }
                }

                b_inputNum = static_cast<int32_T>(std::round(static_cast<real_T>
                    (b_inputNum) / 10.0));
                divisor = std::floor(divisor / 100.0);
            }
        } else {
            result = true;
            exitg1 = 1;
        }
    } while (exitg1 == 0);

    return result;
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

// Function for MATLAB Function: '<S28>/CommandCheck'
MissionModes codegenReal2MissionModelClass::
    codegenReal2Mission_convert_to_enum_MissionModes(int32_T input)
{
    int32_T output;

    // Initialize output value to default value for MissionModes (None)
    output = 0;
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
            ((input >= 0) & (input <= 3)))) | (input == 5)))) | (input == 11))))
                         | (input == 22)))) | (input == 33)))) | (input == 44))))
                | static_cast<int32_T>(static_cast<boolean_T>
                 (static_cast<int32_T>((input >= 128) & (input <= 130))))))) |
             static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
               ((input >= 132) & (input <= 133))))))) | static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>((input >= 252) & (input <=
              255))))))) {
        // Set output value to input value if it is a member of MissionModes
        output = input;
    }

    return output;
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

// Function for MATLAB Function: '<S28>/CommandCheck'
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
    da = split_lIfqwsQg(c.re);
    shi = c.re * 1000.0;
    slo = (da.re * 1000.0 - shi) + da.im * 1000.0;
    trueCount = 0;
    if (std::isnan(slo)) {
        trueCount = 1;
    }

    if (0 <= static_cast<int32_T>(trueCount - 1)) {
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

// Function for MATLAB Function: '<S28>/CommandCheck'
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

// Function for MATLAB Function: '<S28>/CommandCheck'
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

// Function for MATLAB Function: '<S28>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_j(real_T dd,
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
    r = floor_6aYiD2p8(r);
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
    t = floor_6aYiD2p8(c_s);
    c = codegenReal2Mission_minus(c_s, t);
    codegenReal2Mission_days2ymd(r.re + r.im, y, mo, d);
    codegenReal2Mission_secs2hms(t.re + t.im, h, m, &thi);
    *s = (c.re + c.im) + thi;
    if (*s == 60.0) {
        *s = 59.999999999999993;
    }
}

// Function for MATLAB Function: '<S28>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_jr(const
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
    c_s = floor_6aYiD2p8(B);
    t = codegenReal2Mission_divide(codegenReal2Mission_minus(dd,
        codegenReal2Mission_times(c_s)));
    B = floor_6aYiD2p8(t);
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

missionCmd *codegenReal2MissionModelClass::codegenReal2Mission_allocMemPool
    (MemPool_missionCmd *memPool, int32_T width)
{
    missionCmd *dataPtr;

    // DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'
    if (memPool->fNumFree > 0) {
        memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree - 1);
        dataPtr = memPool->fFreeList[memPool->fNumFree];
    } else if (memPool->fNumUsed < memPool->fSize) {
        dataPtr = &memPool->fMemArray[memPool->fNumUsed];
        memPool->fNumUsed = static_cast<int32_T>(memPool->fNumUsed + width);
    } else {
        dataPtr = nullptr;
    }

    // End of DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission' 
    return dataPtr;
}

Msg_missionCmd codegenReal2MissionModelClass::codegenReal2Mission_createMsg(
    const missionCmd *data)
{
    Msg_missionCmd msg;

    // DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'
    msg.fData = codegenReal2Mission_allocMemPool
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd, 1);
    if (msg.fData != nullptr) {
        *msg.fData = *data;
    }

    // End of DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission' 
    return msg;
}

void codegenReal2MissionModelClass::codegenReal2Mission_freeMemPool
    (MemPool_missionCmd *memPool, missionCmd *dataPtr)
{
    // DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'
    memPool->fFreeList[memPool->fNumFree] = dataPtr;
    memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree + 1);
}

void codegenReal2MissionModelClass::codegenReal2Mission_destroyMsg
    (Msg_missionCmd *msg)
{
    // DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'
    codegenReal2Mission_freeMemPool
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd, msg->fData);
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push
    (Buffer_missionCmd *q, Msg_missionCmd *element)
{
    boolean_T isPush;

    // Queue generated from: '<S1>/RcvNextMission'
    if (q->fOccupied) {
        codegenReal2Mission_destroyMsg(&q->fMsg);
    }

    q->fMsg = *element;
    q->fOccupied = true;
    isPush = true;

    // End of Queue generated from: '<S1>/RcvNextMission'
    return isPush;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission' incorporates:
    //   Send: '<S28>/PushCMD'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<S1>/RcvNextMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'

    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<S1>/RcvNextMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_MessageMerge_In1_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission' incorporates:
    //   Send: '<S22>/Send'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<S1>/FeedbackCurrentMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'

    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_4_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<S1>/FeedbackCurrentMission'
    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_SendData(
    const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission' incorporates:
    //   Send: '<S7>/SndImmedCMD'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<S1>/RcvImmedCMD' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'

    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<S1>/RcvImmedCMD'
    return status;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop
    (Buffer_missionCmd *q, Msg_missionCmd *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<S1>/RcvNextMission'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<S1>/RcvNextMission'
    return isPop;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S1>/RcvNextMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<S1>/RcvNextMission'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission' incorporates:
    //   Send: '<S18>/SendMission'

    msg = codegenReal2Mission_createMsg(data);

    // Queue generated from: '<S13>/FlightMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'

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
    //   DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'
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

    // Queue generated from: '<S1>/RcvImmedCMD' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<S1>/RcvImmedCMD'
    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    // Queue generated from: '<S1>/FeedbackCurrentMission' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/FeedbackCurrentMission'

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_4_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    // End of Queue generated from: '<S1>/FeedbackCurrentMission'
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
    static const MissionModes enumVals[18]{ 1, 2, 3, 5, 128, 129, 130, 132, 133,
        11, 22, 33, 44, 255, 0, 252, 254, 253 };

    static const char_T bb[15]{ 'F', 'l', 'i', 'g', 'h', 't', 'M', 'i', 's', 's',
        'i', 'o', 'n', 'R', 'H' };

    static const char_T ab[13]{ 'C', 'o', 'l', 'l', 'A', 'v', 'o', 'i', 'd', 'a',
        'n', 'c', 'e' };

    static const char_T fb[13]{ 'C', 'u', 's', 't', 'o', 'm', 'F', 'r', 'm', 'n',
        'N', 'a', 'v' };

    static const char_T y[12]{ 'D', 'e', 't', 'a', 'i', 'l', 'e', 'd', 'I', 'n',
        's', 'p' };

    static const char_T eb[11]{ 'C', 'i', 'r', 'c', 'D', 'i', 's', 'p', 'N', 'a',
        'v' };

    static const char_T ib[11]{ 'W', 'a', 'i', 't', 'T', 'o', 'S', 't', 'a', 'r',
        't' };

    static const char_T v[11]{ 'H', 'o', 'r', 'z', 'F', 'r', 'm', 'n', 'N', 'a',
        'v' };

    static const char_T gb[10]{ 'F', 'r', 'm', 'n', 'R', 'u', 'n', 'W', 'a', 'y'
    };

    static const char_T w[9]{ 'R', 'u', 'n', 'W', 'a', 'y', 'N', 'a', 'v' };

    static const char_T x[9]{ 'N', 'e', 'w', 'R', 'u', 'n', 'W', 'a', 'y' };

    static const char_T cb[8]{ 'S', 'q', 'C', 'a', 'l', 'i', 'b', 'r' };

    static const char_T hb[8]{ 'P', 'r', 'o', 't', 'L', 'i', 'n', 'e' };

    static const char_T kb[8]{ 'T', 'u', 'n', 'e', 'A', 'D', 'R', 'C' };

    static const char_T lb[8]{ 'S', 'h', 'i', 'f', 't', 'E', 'N', 'U' };

    static const char_T mb[8]{ 'S', 'h', 'i', 'f', 't', 'X', 'Y', 'Z' };

    static const char_T db[7]{ 'p', 'A', 't', 't', 'a', 'c', 'k' };

    static const char_T u[7]{ 'C', 'i', 'r', 'c', 'N', 'a', 'v' };

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
    e.f1.size[0] = 1;
    e.f1.size[1] = 9;
    for (k = 0; k < 9; k++) {
        d.f1.data[k] = w[k];
        e.f1.data[k] = x[k];
    }

    f.f1.size[0] = 1;
    f.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        f.f1.data[k] = y[k];
    }

    g.f1.size[0] = 1;
    g.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        g.f1.data[k] = ab[k];
    }

    h.f1.size[0] = 1;
    h.f1.size[1] = 15;
    for (k = 0; k < 15; k++) {
        h.f1.data[k] = bb[k];
    }

    i.f1.size[0] = 1;
    i.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        i.f1.data[k] = cb[k];
    }

    j.f1.size[0] = 1;
    j.f1.size[1] = 7;
    for (k = 0; k < 7; k++) {
        j.f1.data[k] = db[k];
    }

    l.f1.size[0] = 1;
    l.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        l.f1.data[k] = eb[k];
    }

    m.f1.size[0] = 1;
    m.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        m.f1.data[k] = fb[k];
    }

    n.f1.size[0] = 1;
    n.f1.size[1] = 10;
    for (k = 0; k < 10; k++) {
        n.f1.data[k] = gb[k];
    }

    o.f1.size[0] = 1;
    o.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
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
    s.f1.size[0] = 1;
    s.f1.size[1] = 8;
    t.f1.size[0] = 1;
    t.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        r.f1.data[k] = kb[k];
        s.f1.data[k] = lb[k];
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
    FlightLogging rtb_Real2SimGuidance_o3;
    int32_T rtb_intFlightStatus;
    int32_T rtb_intImmedStatus;
    IndividualUAVCmd *tmp_4;
    Location rtb_DataStoreRead_p_MissionLocation;
    missionCmd reactor_PrevCMD;
    missionCmd rtb_FeedbackCMD;
    missionCmd rtb_FlightCMD;
    creal_T TimeNow_data;
    creal_T temp_0;
    creal_T temp_1;
    real_T c_tm_year[7];
    real_T c_tm_year_0[7];
    real_T processedInData[7];
    real_T rtb_MemoryPose[4];
    real_T a__17;
    real_T a__23;
    real_T a__29;
    real_T a__35;
    real_T b_a__35;
    real_T b_x;
    real_T c_tm_mday;
    real_T c_tm_mon;
    real_T check;
    real_T da_im;
    real_T fracSecs;
    real_T second;
    real_T temp;
    real_T tmp;
    int32_T followSwitch_prev{ 1 };

    int32_T status;
    int32_T status_0;
    boolean_T rtb_ReceiveCurrentMission_o1;
    boolean_T rtb_ReceivePushedMissionCMD_o1;
    boolean_T rtb_Reset;
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

    // Outputs for Atomic SubSystem: '<Root>/MissionLogic'
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Receive: '<S1>/ReceivePushedMissionCMD'
        followSwitch_prev = 1;
        MissionCMDRecvData.RecvData
            (&codegenReal2Mission_DW.ReceivePushedMissionCMD_o2, sizeof
             (IndividualUAVCmd), &followSwitch_prev);
        rtb_ReceivePushedMissionCMD_o1 = (followSwitch_prev != 1);

        // Outputs for Atomic SubSystem: '<S1>/MissionValidation'
        // Outputs for Enabled SubSystem: '<S7>/TriggerMissionDispatch' incorporates:
        //   EnablePort: '<S28>/Enable'

        if (rtb_ReceivePushedMissionCMD_o1) {
            MissionModes reactor_NewCMD_MissionMode;
            int32_T reactor_NewCMD_FormationPos;
            int32_T reactor_NewCMD_numUAV;

            // MATLAB Function: '<S28>/CommandCheck' incorporates:
            //   DataStoreRead: '<S28>/Data Store Read'
            //   DataStoreWrite: '<S28>/WriteCurrentCMD'
            //   Receive: '<S1>/ReceivePushedMissionCMD'

            // MATLAB Function 'MissionLogic/MissionValidation/TriggerMissionDispatch/CommandCheck': '<S30>:1' 
            // '<S30>:1:6'
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
            check = (codegenReal2Mission_createFromDateVec(processedInData)).re /
                1000.0;
            followSwitch_prev =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.SequenceID;
            reactor_NewCMD_MissionMode =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode;
            reactor_PrevCMD.MissionLocation =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation;
            reactor_PrevCMD.params =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params;
            reactor_PrevCMD.StartPosition =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.StartPosition;
            reactor_NewCMD_numUAV =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.numUAV;
            reactor_NewCMD_FormationPos =
                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.FormationPos;
            rtb_ReceivePushedMissionCMD_o1 = false;
            rtb_FlightCMD.SequenceID = 0;
            rtb_FlightCMD.MissionMode = MissionModes_None;
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
            codegenReal2Mission_DW.ImmedCMD.MissionMode = MissionModes_None;
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
            reactor_PrevCMD.SequenceID = followSwitch_prev;
            reactor_PrevCMD.MissionMode = reactor_NewCMD_MissionMode;
            reactor_PrevCMD.numUAV = reactor_NewCMD_numUAV;
            reactor_PrevCMD.FormationPos = reactor_NewCMD_FormationPos;
            reactor_PrevCMD.StartTime = check;
            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode !=
                MissionModes_TuneADRC) {
                // '<S30>:1:8'
                // '<S30>:1:9'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (codegenReal2Mission_isequaln
                        (&codegenReal2Mission_DW.MissionCMD, followSwitch_prev,
                         reactor_NewCMD_MissionMode,
                         reactor_PrevCMD.MissionLocation.Lat,
                         reactor_PrevCMD.MissionLocation.Lon,
                         reactor_PrevCMD.MissionLocation.Alt,
                         reactor_PrevCMD.MissionLocation.degHDG,
                         reactor_PrevCMD.params.Param1,
                         reactor_PrevCMD.params.Param2,
                         reactor_PrevCMD.params.Param3,
                         reactor_PrevCMD.params.Param4,
                         reactor_PrevCMD.params.Param5,
                         reactor_PrevCMD.params.Param6,
                         reactor_PrevCMD.params.Param7,
                         reactor_PrevCMD.StartPosition, reactor_NewCMD_numUAV,
                         reactor_NewCMD_FormationPos, check)) ^ 1))) {
                    if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param7
                        == 1.0F) {
                        if (static_cast<boolean_T>(static_cast<int32_T>
                                                   ((codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode
                               == MissionModes_None) |
                                                    (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode
                               ==
                                codegenReal2Mission_DW.CurrentFlightMission.MissionMode))))
                        {
                            std::memcpy(&reactor_PrevCMD,
                                        &codegenReal2Mission_DW.CurrentFlightMission,
                                        sizeof(missionCmd));
                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Lat
                                != 0.0) {
                                reactor_PrevCMD.MissionLocation.Lat =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Lat;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Lon
                                != 0.0) {
                                reactor_PrevCMD.MissionLocation.Lon =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Lon;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Alt
                                != 0.0) {
                                reactor_PrevCMD.MissionLocation.Alt =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.Alt;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.degHDG
                                != 0.0) {
                                reactor_PrevCMD.MissionLocation.degHDG =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionLocation.degHDG;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param1
                                != 0.0F) {
                                reactor_PrevCMD.params.Param1 =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param1;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param2
                                != 0.0F) {
                                reactor_PrevCMD.params.Param2 =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param2;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param3
                                != 0.0F) {
                                reactor_PrevCMD.params.Param3 =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param3;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param4
                                != 0.0F) {
                                reactor_PrevCMD.params.Param4 =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param4;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param5
                                != 0.0F) {
                                reactor_PrevCMD.params.Param5 =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param5;
                            }

                            if (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param6
                                != 0.0F) {
                                reactor_PrevCMD.params.Param6 =
                                    codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.params.Param6;
                            }

                            reactor_PrevCMD.params.Param7 = 1.0F;
                            reactor_PrevCMD.SequenceID =
                                codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.SequenceID;
                            reactor_PrevCMD.StartTime = check;
                            printf("Reset flight mission, cancel immediate mission!\n");
                            fflush(stdout);
                            codegenReal2Mission_getLocalTime(&second,
                                &c_tm_year[5], &c_tm_year[4], &c_tm_year[3],
                                &c_tm_year[2], &c_tm_year[1], &c_tm_year[0],
                                &rtb_ReceiveCurrentMission_o1);
                            c_tm_year[6] = second / 1.0E+6;
                            codegenReal2Mission_DW.PushImmed =
                                (codegenReal2Mission_createFromDateVec(c_tm_year))
                                .re / 1000.0 + 1.0;
                            rtb_ReceivePushedMissionCMD_o1 = true;
                            std::memcpy(&rtb_FlightCMD, &reactor_PrevCMD, sizeof
                                        (missionCmd));
                        } else {
                            printf("Can not reset flight mission to a new mode!\n");
                            fflush(stdout);
                        }
                    } else if (codegenReal2Mission_DW.MissionCMD.SequenceID ==
                               codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.SequenceID)
                    {
                        printf("Use a new Sequence ID for each new mission!\n");
                        fflush(stdout);
                        printf("PrevCMD SequenceID: %d\n",
                               codegenReal2Mission_DW.MissionCMD.SequenceID);
                        fflush(stdout);
                        printf("NewCMD SequenceID: %d\n", followSwitch_prev);
                        fflush(stdout);
                    } else {
                        int32_T tmp_0;
                        int32_T tmp_1;
                        int32_T tmp_2;
                        int32_T tmp_3;
                        if ((codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode
                             > 127) && (static_cast<boolean_T>
                                        (static_cast<int32_T>
                                         (static_cast<int32_T>
                                          (codegenReal2Mission_isPalindrome
                                           (codegenReal2Mission_DW.ReceivePushedMissionCMD_o2.MissionMode))
                                          ^ 1)))) {
                            codegenReal2Mission_getLocalTime(&second,
                                &c_tm_year[5], &c_tm_year[4], &c_tm_year[3],
                                &c_tm_year[2], &c_tm_year[1], &c_tm_year[0],
                                &rtb_ReceiveCurrentMission_o1);
                            c_tm_year[6] = second / 1.0E+6;
                            codegenReal2Mission_DW.PushImmed =
                                (codegenReal2Mission_createFromDateVec(c_tm_year))
                                .re / 1000.0 + 1.0;
                            codegenReal2Mission_DW.ImmedCMD.SequenceID =
                                followSwitch_prev;
                            codegenReal2Mission_DW.ImmedCMD.MissionMode =
                                reactor_NewCMD_MissionMode;
                            codegenReal2Mission_DW.ImmedCMD.MissionLocation =
                                reactor_PrevCMD.MissionLocation;
                            codegenReal2Mission_DW.ImmedCMD.params =
                                reactor_PrevCMD.params;
                            codegenReal2Mission_DW.ImmedCMD.StartPosition =
                                reactor_PrevCMD.StartPosition;
                            codegenReal2Mission_DW.ImmedCMD.numUAV =
                                reactor_NewCMD_numUAV;
                            codegenReal2Mission_DW.ImmedCMD.FormationPos =
                                reactor_NewCMD_FormationPos;
                            codegenReal2Mission_DW.ImmedCMD.StartTime = check;
                        } else {
                            codegenReal2Mission_getLocalTime(&second,
                                &c_tm_year[5], &c_tm_year[4], &c_tm_year[3],
                                &c_tm_year[2], &c_tm_year[1], &c_tm_year[0],
                                &rtb_ReceiveCurrentMission_o1);
                            c_tm_year[6] = second / 1.0E+6;
                            if ((codegenReal2Mission_createFromDateVec(c_tm_year))
                                    .re / 1000.0 <= check) {
                                if ((reactor_NewCMD_MissionMode > 10) &&
                                        codegenReal2Mission_isPalindrome
                                        (reactor_NewCMD_MissionMode)) {
                                    rtb_ReceivePushedMissionCMD_o1 = true;
                                    codegenReal2Mission_DW.PushImmed = check;
                                    rtb_FlightCMD.SequenceID = followSwitch_prev;
                                    rtb_FlightCMD.MissionMode =
                                        reactor_NewCMD_MissionMode;
                                    rtb_FlightCMD.MissionLocation =
                                        reactor_PrevCMD.MissionLocation;
                                    rtb_FlightCMD.params =
                                        reactor_PrevCMD.params;
                                    rtb_FlightCMD.StartPosition =
                                        reactor_PrevCMD.StartPosition;
                                    rtb_FlightCMD.numUAV = reactor_NewCMD_numUAV;
                                    rtb_FlightCMD.FormationPos =
                                        reactor_NewCMD_FormationPos;
                                    rtb_FlightCMD.StartTime = check;
                                    codegenReal2Mission_DW.ImmedCMD.SequenceID =
                                        followSwitch_prev;
                                    codegenReal2Mission_DW.ImmedCMD.MissionLocation
                                        = reactor_PrevCMD.MissionLocation;
                                    codegenReal2Mission_DW.ImmedCMD.params =
                                        reactor_PrevCMD.params;
                                    codegenReal2Mission_DW.ImmedCMD.StartPosition
                                        = reactor_PrevCMD.StartPosition;
                                    codegenReal2Mission_DW.ImmedCMD.numUAV =
                                        reactor_NewCMD_numUAV;
                                    codegenReal2Mission_DW.ImmedCMD.FormationPos
                                        = reactor_NewCMD_FormationPos;
                                    codegenReal2Mission_DW.ImmedCMD.StartTime =
                                        check;
                                    codegenReal2Mission_DW.ImmedCMD.MissionMode =
                                        codegenReal2Mission_convert_to_enum_MissionModes
                                        (static_cast<int32_T>
                                         (reactor_PrevCMD.params.Param6));
                                } else {
                                    rtb_ReceivePushedMissionCMD_o1 = true;
                                    codegenReal2Mission_DW.PushImmed = check;
                                    rtb_FlightCMD.SequenceID = followSwitch_prev;
                                    rtb_FlightCMD.MissionMode =
                                        reactor_NewCMD_MissionMode;
                                    rtb_FlightCMD.MissionLocation =
                                        reactor_PrevCMD.MissionLocation;
                                    rtb_FlightCMD.params =
                                        reactor_PrevCMD.params;
                                    rtb_FlightCMD.StartPosition =
                                        reactor_PrevCMD.StartPosition;
                                    rtb_FlightCMD.numUAV = reactor_NewCMD_numUAV;
                                    rtb_FlightCMD.FormationPos =
                                        reactor_NewCMD_FormationPos;
                                    rtb_FlightCMD.StartTime = check;
                                }
                            } else {
                                printf("Mission Start Time has already passed!\n");
                                fflush(stdout);
                            }
                        }

                        second = check * 1000.0;
                        codegenReal2Mission_getDateVec_j(second, &check, &temp,
                            &fracSecs, &tmp, &c_tm_mday, &c_tm_mon);
                        codegenReal2Mission_getDateVec_j(second, &fracSecs,
                            &temp, &tmp, &c_tm_mday, &c_tm_mon, &da_im);
                        codegenReal2Mission_getDateVec_j(second, &tmp,
                            &c_tm_mday, &fracSecs, &c_tm_mon, &da_im, &a__17);
                        codegenReal2Mission_getDateVec_j(second, &c_tm_mday,
                            &c_tm_mon, &da_im, &tmp, &a__17, &a__23);
                        codegenReal2Mission_getDateVec_j(second, &c_tm_mon,
                            &da_im, &a__17, &a__23, &c_tm_mday, &a__29);
                        codegenReal2Mission_getDateVec_j(second, &da_im, &a__17,
                            &a__23, &a__29, &a__35, &c_tm_mon);
                        codegenReal2Mission_getDateVec_j(second, &a__17, &a__23,
                            &a__29, &a__35, &b_a__35, &da_im);
                        codegenReal2Mission_getDateVec_j(second, &a__17, &a__23,
                            &a__29, &a__35, &b_a__35, &b_x);
                        check = std::round(check);
                        second = std::round(temp);
                        fracSecs = std::round(fracSecs);
                        tmp = std::round(tmp);
                        c_tm_mday = std::round(c_tm_mday);
                        c_tm_mon = std::floor(c_tm_mon);
                        da_im = std::round((da_im - std::floor(b_x)) * 1000.0);
                        if (check < 2.147483648E+9) {
                            if (check >= -2.147483648E+9) {
                                followSwitch_prev = static_cast<int32_T>(check);
                            } else {
                                followSwitch_prev = MIN_int32_T;
                            }
                        } else {
                            followSwitch_prev = MAX_int32_T;
                        }

                        if (second < 2.147483648E+9) {
                            if (second >= -2.147483648E+9) {
                                reactor_NewCMD_numUAV = static_cast<int32_T>
                                    (second);
                            } else {
                                reactor_NewCMD_numUAV = MIN_int32_T;
                            }
                        } else {
                            reactor_NewCMD_numUAV = MAX_int32_T;
                        }

                        if (fracSecs < 2.147483648E+9) {
                            if (fracSecs >= -2.147483648E+9) {
                                reactor_NewCMD_FormationPos =
                                    static_cast<int32_T>(fracSecs);
                            } else {
                                reactor_NewCMD_FormationPos = MIN_int32_T;
                            }
                        } else {
                            reactor_NewCMD_FormationPos = MAX_int32_T;
                        }

                        if (tmp < 2.147483648E+9) {
                            if (tmp >= -2.147483648E+9) {
                                tmp_0 = static_cast<int32_T>(tmp);
                            } else {
                                tmp_0 = MIN_int32_T;
                            }
                        } else {
                            tmp_0 = MAX_int32_T;
                        }

                        if (c_tm_mday < 2.147483648E+9) {
                            if (c_tm_mday >= -2.147483648E+9) {
                                tmp_1 = static_cast<int32_T>(c_tm_mday);
                            } else {
                                tmp_1 = MIN_int32_T;
                            }
                        } else {
                            tmp_1 = MAX_int32_T;
                        }

                        if (c_tm_mon < 2.147483648E+9) {
                            if (c_tm_mon >= -2.147483648E+9) {
                                tmp_2 = static_cast<int32_T>(c_tm_mon);
                            } else {
                                tmp_2 = MIN_int32_T;
                            }
                        } else {
                            tmp_2 = MAX_int32_T;
                        }

                        if (da_im < 2.147483648E+9) {
                            if (da_im >= -2.147483648E+9) {
                                tmp_3 = static_cast<int32_T>(da_im);
                            } else {
                                tmp_3 = MIN_int32_T;
                            }
                        } else {
                            tmp_3 = MAX_int32_T;
                        }

                        printf("Start Time:   %04d-%02d-%02d %02d:%02d:%02d.%03d\n",
                               followSwitch_prev, reactor_NewCMD_numUAV,
                               reactor_NewCMD_FormationPos, tmp_0, tmp_1, tmp_2,
                               tmp_3);
                        fflush(stdout);
                        codegenReal2Mission_getLocalTime(&second, &c_tm_year_0[5],
                            &c_tm_year_0[4], &c_tm_year_0[3], &c_tm_year_0[2],
                            &c_tm_year_0[1], &c_tm_year_0[0],
                            &rtb_ReceiveCurrentMission_o1);
                        c_tm_year_0[6] = second / 1.0E+6;
                        TimeNow_data = codegenReal2Mission_createFromDateVec
                            (c_tm_year_0);
                        codegenReal2Mission_getDateVec_jr(TimeNow_data, &b_x,
                            &check, &second, &temp, &fracSecs, &tmp);
                        codegenReal2Mission_getDateVec_jr(TimeNow_data, &check,
                            &a__17, &second, &temp, &fracSecs, &tmp);
                        codegenReal2Mission_getDateVec_jr(TimeNow_data, &check,
                            &second, &a__23, &temp, &fracSecs, &tmp);
                        codegenReal2Mission_getDateVec_jr(TimeNow_data, &check,
                            &second, &temp, &a__29, &fracSecs, &tmp);
                        codegenReal2Mission_getDateVec_jr(TimeNow_data, &check,
                            &second, &temp, &fracSecs, &a__35, &tmp);
                        codegenReal2Mission_getDateVec_jr(TimeNow_data, &second,
                            &temp, &fracSecs, &tmp, &c_tm_mday, &check);
                        codegenReal2Mission_getDateVec_jr(TimeNow_data, &temp,
                            &fracSecs, &tmp, &c_tm_mday, &c_tm_mon, &second);
                        codegenReal2Mission_getDateVec_jr(TimeNow_data, &temp,
                            &fracSecs, &tmp, &c_tm_mday, &c_tm_mon, &da_im);
                        printf("Current Time: %04.0f-%02.0f-%02.0f %02.0f:%02.0f:%02.0f.%03.0f\n",
                               b_x, a__17, a__23, a__29, a__35, std::floor(check),
                               std::round(1000.0 * (second - std::floor(da_im))));
                        fflush(stdout);
                    }
                }

                // '<S30>:1:10'
            } else {
                // '<S30>:1:12'
                codegenReal2Mission_DW.ParamADRC_e.hat_b = static_cast<real_T>
                    (reactor_PrevCMD.params.Param1 / 1000.0F);
                codegenReal2Mission_DW.ParamADRC_e.omega_o = static_cast<real_T>
                    (reactor_PrevCMD.params.Param2 / 1000.0F);
                codegenReal2Mission_DW.ParamADRC_e.omega_b = static_cast<real_T>
                    (reactor_PrevCMD.params.Param3 / 1000.0F);
                codegenReal2Mission_DW.ParamADRC_e.P = static_cast<real_T>
                    (reactor_PrevCMD.params.Param4 / 1000.0F);
                codegenReal2Mission_DW.ParamADRC_e.I = static_cast<real_T>
                    (reactor_PrevCMD.params.Param5 / 1000.0F);
                codegenReal2Mission_DW.ParamADRC_e.D = static_cast<real_T>
                    (reactor_PrevCMD.params.Param6 / 1000.0F);
                codegenReal2Mission_DW.ParamADRC_e.useADRC =
                    (reactor_PrevCMD.params.Param7 != 0.0F);

                // '<S30>:1:14'
            }

            // '<S30>:1:27'
            // '<S30>:1:28'
            std::memcpy(&rtb_FeedbackCMD, &reactor_PrevCMD, sizeof(missionCmd));

            // Send: '<S28>/PushCMD' incorporates:
            //   MATLAB Function: '<S28>/CommandCheck'

            if (rtb_ReceivePushedMissionCMD_o1) {
                codegenReal2Mission_RcvNextMission_SendData(&rtb_FlightCMD);
            }

            // End of Send: '<S28>/PushCMD'

            // Send: '<S28>/SendFeedbackMissionCMD'
            codegenReal2Mission_MessageMerge_In1_SendData(&rtb_FeedbackCMD);
        }

        // End of Outputs for SubSystem: '<S7>/TriggerMissionDispatch'

        // MATLAB Function: '<S7>/getCurrentTime'
        // MATLAB Function 'getCurrentTime': '<S29>:1'
        // '<S29>:1:3'
        codegenReal2Mission_getLocalTime(&second, &temp, &processedInData[4],
            &tmp, &c_tm_mday, &c_tm_mon, &da_im, &rtb_ReceiveCurrentMission_o1);
        processedInData[5] = temp;
        processedInData[6] = second / 1.0E+6;
        second = temp;
        fracSecs = processedInData[6];
        check = (((((da_im + c_tm_mon) + c_tm_mday) + tmp) + processedInData[4])
                 + temp) + processedInData[6];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(check)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(check)) ^ 1)))))) {
            check = da_im;
            temp = c_tm_mon;
            if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
                temp = std::floor((c_tm_mon - 1.0) / 12.0);
                check = da_im + temp;
                temp = ((c_tm_mon - 1.0) - temp * 12.0) + 1.0;
            }

            if (temp < 3.0) {
                check--;
                temp += 9.0;
            } else {
                temp -= 3.0;
            }

            TimeNow_data.re = ((((((365.0 * check + std::floor(check / 4.0)) -
                                   std::floor(check / 100.0)) + std::floor(check
                                   / 400.0)) + std::floor((153.0 * temp + 2.0) /
                                  5.0)) + c_tm_mday) + 60.0) - 719529.0;
            temp = 1.34217729E+8 * TimeNow_data.re;
            temp -= temp - TimeNow_data.re;
            check = TimeNow_data.re * 8.64E+7;
            temp_0.re = check;
            da_im = (TimeNow_data.re - temp) * 8.64E+7 + (temp * 8.64E+7 - check);
            temp_0.im = da_im;
            if (std::isnan(da_im)) {
                temp_0.im = 0.0;
            }

            if ((processedInData[6] < 0.0) || (1000.0 <= processedInData[6])) {
                fracSecs = std::floor(processedInData[6] / 1000.0);
                second = processedInData[5] + fracSecs;
                fracSecs = processedInData[6] - fracSecs * 1000.0;
            }

            TimeNow_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(temp_0, (60.0 * tmp + processedInData
                [4]) * 60000.0), second * 1000.0), fracSecs);
        } else {
            TimeNow_data.re = check;
        }

        // Logic: '<S7>/AND' incorporates:
        //   MATLAB Function: '<S7>/getCurrentTime'
        //   RelationalOperator: '<S7>/Relational Operator'

        rtb_ReceivePushedMissionCMD_o1 = static_cast<boolean_T>
            (static_cast<int32_T>((codegenReal2Mission_DW.PushImmed <
               TimeNow_data.re / 1000.0) & (codegenReal2Mission_DW.PushImmed !=
               0.0)));

        // Send: '<S7>/SndImmedCMD' incorporates:
        //   Constant: '<S27>/Constant'
        //   DataTypeConversion: '<S7>/Cast To Double'
        //   Memory: '<S7>/Memory'
        //   RelationalOperator: '<S27>/Compare'
        //   Sum: '<S7>/Minus'

        if (static_cast<real_T>(rtb_ReceivePushedMissionCMD_o1) -
                codegenReal2Mission_DW.Memory_PreviousInput > 0.0) {
            codegenReal2Mission_RcvImmedCMD_SendData
                (&codegenReal2Mission_DW.ImmedCMD);
        }

        // End of Send: '<S7>/SndImmedCMD'

        // Update for Memory: '<S7>/Memory' incorporates:
        //   DataTypeConversion: '<S7>/Cast To Double'

        codegenReal2Mission_DW.Memory_PreviousInput = static_cast<real_T>
            (rtb_ReceivePushedMissionCMD_o1);

        // End of Outputs for SubSystem: '<S1>/MissionValidation'

        // Receive: '<S1>/RcvNextMission'
        codegenReal2Mission_RcvNextMission_RecvData
            (&codegenReal2Mission_DW.RcvNextMission);

        // MATLAB Function: '<S13>/getCurrentTime'
        // MATLAB Function 'getCurrentTime': '<S19>:1'
        // '<S19>:1:3'
        codegenReal2Mission_getLocalTime(&second, &temp, &processedInData[4],
            &tmp, &c_tm_mday, &c_tm_mon, &da_im, &rtb_ReceiveCurrentMission_o1);
        processedInData[5] = temp;
        processedInData[6] = second / 1.0E+6;
        second = temp;
        fracSecs = processedInData[6];
        check = (((((da_im + c_tm_mon) + c_tm_mday) + tmp) + processedInData[4])
                 + temp) + processedInData[6];
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(check)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(check)) ^ 1)))))) {
            check = da_im;
            temp = c_tm_mon;
            if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
                temp = std::floor((c_tm_mon - 1.0) / 12.0);
                check = da_im + temp;
                temp = ((c_tm_mon - 1.0) - temp * 12.0) + 1.0;
            }

            if (temp < 3.0) {
                check--;
                temp += 9.0;
            } else {
                temp -= 3.0;
            }

            TimeNow_data.re = ((((((365.0 * check + std::floor(check / 4.0)) -
                                   std::floor(check / 100.0)) + std::floor(check
                                   / 400.0)) + std::floor((153.0 * temp + 2.0) /
                                  5.0)) + c_tm_mday) + 60.0) - 719529.0;
            temp = 1.34217729E+8 * TimeNow_data.re;
            temp -= temp - TimeNow_data.re;
            check = TimeNow_data.re * 8.64E+7;
            temp_1.re = check;
            da_im = (TimeNow_data.re - temp) * 8.64E+7 + (temp * 8.64E+7 - check);
            temp_1.im = da_im;
            if (std::isnan(da_im)) {
                temp_1.im = 0.0;
            }

            if ((processedInData[6] < 0.0) || (1000.0 <= processedInData[6])) {
                fracSecs = std::floor(processedInData[6] / 1000.0);
                second = processedInData[5] + fracSecs;
                fracSecs = processedInData[6] - fracSecs * 1000.0;
            }

            TimeNow_data = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(temp_1, (60.0 * tmp + processedInData
                [4]) * 60000.0), second * 1000.0), fracSecs);
        } else {
            TimeNow_data.re = check;
        }

        check = TimeNow_data.re / 1000.0;

        // End of MATLAB Function: '<S13>/getCurrentTime'

        // Chart: '<S13>/MisisonCMDTemporalLogic' incorporates:
        //   Receive: '<S1>/RcvNextMission'

        // Gateway: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
        // During: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c12_codegenReal2Mission) == 0U)
        {
            // Entry: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
            codegenReal2Mission_DW.is_active_c12_codegenReal2Mission = 1U;

            // Entry Internal: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/MisisonCMDTemporalLogic 
            // Transition: '<S16>:2'
            codegenReal2Mission_DW.is_c12_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;

            // Entry 'Pending': '<S16>:1'
            codegenReal2Mission_DW.TriggerSend = 0.0;
        } else if (codegenReal2Mission_DW.is_c12_codegenReal2Mission ==
                   codegenReal2Mission_IN_Pending) {
            // During 'Pending': '<S16>:1'
            if (check >= codegenReal2Mission_DW.RcvNextMission.StartTime) {
                // Transition: '<S16>:5'
                codegenReal2Mission_DW.is_c12_codegenReal2Mission =
                    codegenReal2Mission_IN_Sending;

                // Entry 'Sending': '<S16>:3'
                codegenReal2Mission_DW.TriggerSend = 1.0;
            } else {
                codegenReal2Mission_DW.TriggerSend = 0.0;
            }

            // During 'Sending': '<S16>:3'
        } else if (check <= codegenReal2Mission_DW.RcvNextMission.StartTime) {
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
                //   Receive: '<S1>/RcvNextMission'

                codegenReal2Mission_ReceiveCurrentMission_SendData
                    (&codegenReal2Mission_DW.RcvNextMission);
            }

            codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE =
                static_cast<ZCSigState>(rtb_ReceivePushedMissionCMD_o1);
        }

        // End of Outputs for SubSystem: '<S13>/TriggerBroadcastAtMissionTime'

        // Outputs for Atomic SubSystem: '<S13>/FlightMission'
        // Receive: '<S14>/ReceiveCurrentMission'
        followSwitch_prev = codegenReal2Mission_ReceiveCurrentMission_RecvData
            (&codegenReal2Mission_DW.ReceiveCurrentMission_o2);
        rtb_ReceiveCurrentMission_o1 = (followSwitch_prev != 1);

        // Chart: '<S14>/TriggerStartSim' incorporates:
        //   Constant: '<S20>/Constant'
        //   Constant: '<S21>/Constant'
        //   Logic: '<S14>/AND'
        //   RelationalOperator: '<S20>/Compare'
        //   RelationalOperator: '<S21>/Compare'

        // Gateway: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
        // During: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c4_codegenReal2Mission) == 0U)
        {
            // Entry: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
            codegenReal2Mission_DW.is_active_c4_codegenReal2Mission = 1U;

            // Entry Internal: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/FlightMission/TriggerStartSim 
            // Transition: '<S25>:4'
            codegenReal2Mission_DW.is_c4_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;

            // Entry 'Pending': '<S25>:3'
            codegenReal2Mission_DW.StartSim = false;
        } else if (codegenReal2Mission_DW.is_c4_codegenReal2Mission ==
                   codegenReal2Mission_IN_Pending) {
            // During 'Pending': '<S25>:3'
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode
                   != MissionModes_None) &
                                        (codegenReal2Mission_DW.ReceiveCurrentMission_o2.SequenceID
                   > 0)))) {
                // Transition: '<S25>:6'
                codegenReal2Mission_DW.is_c4_codegenReal2Mission =
                    codegenReal2Mission_IN_Running;

                // Entry 'Running': '<S25>:5'
                codegenReal2Mission_DW.StartSim = true;
            } else {
                codegenReal2Mission_DW.StartSim = false;
            }
        } else {
            // During 'Running': '<S25>:5'
            codegenReal2Mission_DW.StartSim = true;
        }

        // End of Chart: '<S14>/TriggerStartSim'

        // DataStoreRead: '<S14>/Data Store Read'
        rtb_DataStoreRead_p_MissionLocation =
            codegenReal2Mission_DW.CurrentFlightMission.MissionLocation;

        // Logic: '<S14>/Reset' incorporates:
        //   Logic: '<S14>/NOT'

        rtb_Reset = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((codegenReal2Mission_DW.ReceiveCurrentMission_o2.params.Param7 !=
              0.0F) ^ 1))) & static_cast<int32_T>(rtb_ReceiveCurrentMission_o1)));

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
                                        (rtb_ReceiveCurrentMission_o1)))) {
                // DataStoreWrite: '<S22>/Data Store Write' incorporates:
                //   Receive: '<S14>/ReceiveCurrentMission'

                codegenReal2Mission_DW.CurrentFlightMission =
                    codegenReal2Mission_DW.ReceiveCurrentMission_o2;

                // Send: '<S22>/Send' incorporates:
                //   Receive: '<S14>/ReceiveCurrentMission'

                codegenReal2Mission_MessageMerge_In1_SendData
                    (&codegenReal2Mission_DW.ReceiveCurrentMission_o2);
            }

            codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE =
                static_cast<ZCSigState>(rtb_ReceiveCurrentMission_o1);
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
        // Outputs for Atomic SubSystem: '<S14>/SimState2Pose'
        // SignalConversion generated from: '<S24>/Pose' incorporates:
        //   Gain: '<S24>/Gain2'

        codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [0] = codegenReal2Mission_DW.North;
        codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [1] = codegenReal2Mission_DW.East;
        codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [2] = -codegenReal2Mission_DW.Height;
        codegenReal2Mission_DW.TmpSignalConversionAtBufferToMakeInportVirtual_InsertedFor_Pose_at_inport_0Inport1
            [3] = codegenReal2Mission_DW.HeadingAngle;

        // End of Outputs for SubSystem: '<S14>/SimState2Pose'

        // BusCreator generated from: '<S5>/ImmedMission'
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.North
            = codegenReal2Mission_DW.North;
        codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1.East
            = codegenReal2Mission_DW.East;
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

        // Receive: '<S1>/RcvImmedCMD'
        followSwitch_prev = codegenReal2Mission_RcvImmedCMD_RecvData
            (&codegenReal2Mission_DW.RcvImmedCMD_o2);

        // Receive: '<S1>/RcvImmedCMD'
        rtb_ReceiveCurrentMission_o1 = (followSwitch_prev != 1);

        // ModelReference generated from: '<S5>/ImmedMission' incorporates:
        //   Inport: '<Root>/FlightState'
        //   Inport: '<Root>/OtherUAVstate'

        ImmedMission
            (&codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1,
             &codegenReal2Mission_DW.RcvImmedCMD_o2,
             &rtb_ReceiveCurrentMission_o1,
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
             &codegenReal2Mission_U.OtherUAVstate[0],
             &codegenReal2Mission_DW.thisTaskStatus,
             &codegenReal2Mission_DW.ImmedMission_o2,
             &codegenReal2Mission_DW.ImmedMission_o3[0],
             &codegenReal2Mission_DW.ImmedMission_o4,
             &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw),
             &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtzce));

        // Chart: '<S13>/NewMission'
        // Gateway: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
        followSwitch_prev = codegenReal2Mission_DW.followSwitch_start;
        codegenReal2Mission_DW.followSwitch_start =
            codegenReal2Mission_DW.RcvNextMission.SequenceID;

        // During: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c14_codegenReal2Mission) == 0U)
        {
            // Entry: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
            codegenReal2Mission_DW.is_active_c14_codegenReal2Mission = 1U;

            // Entry Internal: MissionLogic/FlightMission_Variant/VariantScheduler/SingleUAV/NewMission 
            // Transition: '<S17>:3'
            codegenReal2Mission_DW.is_c14_codegenReal2Mission =
                codegenReal2Mission_IN_Enter;

            // Entry 'Enter': '<S17>:2'
            codegenReal2Mission_DW.NewMission = false;
        } else {
            switch (codegenReal2Mission_DW.is_c14_codegenReal2Mission) {
              case codegenReal2Mission_IN_Enter:
                codegenReal2Mission_DW.NewMission = false;

                // During 'Enter': '<S17>:2'
                if (followSwitch_prev !=
                        codegenReal2Mission_DW.followSwitch_start) {
                    // Transition: '<S17>:4'
                    codegenReal2Mission_DW.is_c14_codegenReal2Mission =
                        codegenReal2Mission_IN_Wait;
                }
                break;

              case codegenReal2Mission_IN_New:
                // During 'New': '<S17>:9'
                // Transition: '<S17>:10'
                codegenReal2Mission_DW.is_c14_codegenReal2Mission =
                    codegenReal2Mission_IN_Enter;

                // Entry 'Enter': '<S17>:2'
                codegenReal2Mission_DW.NewMission = false;
                break;

              default:
                // During 'Wait': '<S17>:6'
                if (rtb_ReceivePushedMissionCMD_o1) {
                    // Transition: '<S17>:7'
                    codegenReal2Mission_DW.is_c14_codegenReal2Mission =
                        codegenReal2Mission_IN_New;

                    // Entry 'New': '<S17>:9'
                    codegenReal2Mission_DW.NewMission = true;
                }
                break;
            }
        }

        // End of Chart: '<S13>/NewMission'

        // Logic: '<S3>/OR'
        codegenReal2Mission_DW.OR = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(rtb_ReceiveCurrentMission_o1) |
            static_cast<int32_T>(codegenReal2Mission_DW.NewMission)));

        // Memory: '<S1>/Memory'
        codegenReal2Mission_DW.Memory =
            codegenReal2Mission_DW.Memory_PreviousInput_l;

        // Memory: '<S3>/MemoryFlightStatus'
        codegenReal2Mission_Y.MissionFB.FlightStatus =
            codegenReal2Mission_DW.MemoryFlightStatus_PreviousInput;

        // Memory: '<S3>/MemoryImmedStatus'
        codegenReal2Mission_Y.MissionFB.ImmedStatus =
            codegenReal2Mission_DW.MemoryImmedStatus_PreviousInput;

        // Receive: '<S3>/ReceiveThisMission'
        followSwitch_prev = codegenReal2Mission_ReceiveThisMission_RecvData
            (&codegenReal2Mission_DW.ReceiveThisMission_o2);
        rtb_ReceivePushedMissionCMD_o1 = (followSwitch_prev != 1);

        // BusCreator: '<S3>/CreateStatusBus' incorporates:
        //   DataStoreRead: '<S3>/Data Store Read'
        //   Outport: '<Root>/MissionFB'

        codegenReal2Mission_Y.MissionFB.EngagedFlag =
            codegenReal2Mission_DW.Memory;
        codegenReal2Mission_Y.MissionFB.SequenceID =
            codegenReal2Mission_DW.ReceiveThisMission_o2.SequenceID;
        codegenReal2Mission_Y.MissionFB.MissionMode =
            codegenReal2Mission_DW.CurrentFlightMission.MissionMode;
        codegenReal2Mission_Y.MissionFB.numUAV =
            codegenReal2Mission_DW.CurrentFlightMission.numUAV;
        codegenReal2Mission_Y.MissionFB.FormationPos =
            codegenReal2Mission_DW.CurrentFlightMission.FormationPos;

        // Outputs for Triggered SubSystem: '<S3>/TriggerCurrentMisisonFeedback' incorporates:
        //   TriggerPort: '<S9>/Trigger'

        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE
                   != POS_ZCSIG) & static_cast<int32_T>
                                        (rtb_ReceivePushedMissionCMD_o1)))) {
                // MATLAB Function: '<S9>/TimeConverter'
                // MATLAB Function 'MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/TimeConverter': '<S11>:1' 
                // '<S11>:1:3'
                second = codegenReal2Mission_DW.ReceiveThisMission_o2.StartTime *
                    1000.0;
                codegenReal2Mission_getDateVec_m(second, &check, &temp,
                    &fracSecs, &tmp, &c_tm_mday, &c_tm_mon);
                check = std::round(check);
                if (check < 2.147483648E+9) {
                    if (check >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.year =
                            static_cast<int32_T>(check);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.year =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.year = MAX_int32_T;
                }

                codegenReal2Mission_getDateVec_m(second, &fracSecs, &temp, &tmp,
                    &c_tm_mday, &c_tm_mon, &da_im);
                check = std::round(temp);
                if (check < 2.147483648E+9) {
                    if (check >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.month =
                            static_cast<int32_T>(check);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.month =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.month =
                        MAX_int32_T;
                }

                codegenReal2Mission_getDateVec_m(second, &tmp, &c_tm_mday,
                    &fracSecs, &c_tm_mon, &da_im, &a__17);
                check = std::round(fracSecs);
                if (check < 2.147483648E+9) {
                    if (check >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.day =
                            static_cast<int32_T>(check);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.day =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.day = MAX_int32_T;
                }

                codegenReal2Mission_getDateVec_m(second, &c_tm_mday, &c_tm_mon,
                    &da_im, &tmp, &a__17, &a__23);
                check = std::round(tmp);
                if (check < 2.147483648E+9) {
                    if (check >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.hour =
                            static_cast<int32_T>(check);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.hour =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.hour = MAX_int32_T;
                }

                codegenReal2Mission_getDateVec_m(second, &c_tm_mon, &da_im,
                    &a__17, &a__23, &c_tm_mday, &a__29);
                check = std::round(c_tm_mday);
                if (check < 2.147483648E+9) {
                    if (check >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                            static_cast<int32_T>(check);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                        MAX_int32_T;
                }

                codegenReal2Mission_getDateVec_m(second, &da_im, &a__17, &a__23,
                    &a__29, &a__35, &c_tm_mon);
                check = std::floor(c_tm_mon);
                if (check < 2.147483648E+9) {
                    if (check >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.second =
                            static_cast<int32_T>(check);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.second =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.second =
                        MAX_int32_T;
                }

                codegenReal2Mission_getDateVec_m(second, &a__17, &a__23, &a__29,
                    &a__35, &b_a__35, &da_im);
                codegenReal2Mission_getDateVec_m(second, &a__17, &a__23, &a__29,
                    &a__35, &b_a__35, &b_x);
                check = std::round((da_im - std::floor(b_x)) * 1000.0);
                if (check < 2.147483648E+9) {
                    if (check >= -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                            static_cast<int32_T>(check);
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

                // MATLAB Function 'MissionLogic/FeedbackCurrentMission/TriggerCurrentMisisonFeedback/PrintOnboardLog': '<S10>:1' 
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (codegenReal2Mission_DW.NewRun_not_empty)
                      ^ 1))) {
                    int8_T fileid;

                    // '<S10>:1:5'
                    // '<S10>:1:7'
                    fileid = codegenReal2Mission_cfopen("OnboardMissionCMD.log",
                        "wb");
                    followSwitch_prev = static_cast<int32_T>(fileid);

                    // '<S10>:1:7'
                    codegenReal2Mission_DW.NewRun = 1.0;
                    codegenReal2Mission_DW.NewRun_not_empty = true;
                } else {
                    int8_T fileid;

                    // '<S10>:1:9'
                    fileid = codegenReal2Mission_cfopen("OnboardMissionCMD.log",
                        "ab");
                    followSwitch_prev = static_cast<int32_T>(fileid);

                    // '<S10>:1:9'
                    codegenReal2Mission_DW.NewRun++;
                }

                // '<S10>:1:13'
                tmp_4 = &codegenReal2Mission_DW.IndivCMD;
                codegenReal2Mission_printIndivMissionCMD(tmp_4,
                    static_cast<real_T>(followSwitch_prev));

                // '<S10>:1:16'
                codegenReal2Mission_cfclose(static_cast<real_T>
                    (followSwitch_prev));

                // End of MATLAB Function: '<S9>/PrintOnboardLog'

                // Send: '<S9>/Send' incorporates:
                //   BusCreator: '<S9>/IndivCMD'

                CurrentMissionSendData.SendData(&codegenReal2Mission_DW.IndivCMD,
                    sizeof(IndividualUAVCmd), &status_0);
            }

            codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
                static_cast<ZCSigState>(rtb_ReceivePushedMissionCMD_o1);
        }

        // End of Outputs for SubSystem: '<S3>/TriggerCurrentMisisonFeedback'

        // DataTypeConversion: '<S3>/intFlightStatus'
        check = std::floor(codegenReal2Mission_DW.thisTaskStatus_g);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(check)) | static_cast<int32_T>(std::isinf(check))))) {
            check = 0.0;
        } else {
            check = std::fmod(check, 4.294967296E+9);
        }

        // DataTypeConversion: '<S3>/intFlightStatus'
        rtb_intFlightStatus = check < 0.0 ? static_cast<int32_T>
            (-static_cast<int32_T>(static_cast<uint32_T>(-check))) :
            static_cast<int32_T>(static_cast<uint32_T>(check));

        // DataTypeConversion: '<S3>/intImmedStatus'
        check = std::floor(codegenReal2Mission_DW.thisTaskStatus);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(check)) | static_cast<int32_T>(std::isinf(check))))) {
            check = 0.0;
        } else {
            check = std::fmod(check, 4.294967296E+9);
        }

        // DataTypeConversion: '<S3>/intImmedStatus'
        rtb_intImmedStatus = check < 0.0 ? static_cast<int32_T>(-static_cast<
            int32_T>(static_cast<uint32_T>(-check))) : static_cast<int32_T>(
            static_cast<uint32_T>(check));

        // Outputs for Atomic SubSystem: '<S13>/JumpDelay'
        // Outputs for Atomic SubSystem: '<S15>/ComputDelay'
        // Switch: '<S26>/AllPositivePosSwitch' incorporates:
        //   DataTypeConversion: '<S26>/doubleFormPos'
        //   DataTypeConversion: '<S26>/doubleNumUAV'
        //   Sum: '<S26>/Minus'

        if (codegenReal2Mission_DW.RcvNextMission.FormationPos > 0) {
            check = static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.FormationPos);
        } else {
            check = static_cast<real_T>
                (codegenReal2Mission_DW.RcvNextMission.numUAV) - static_cast<
                real_T>(codegenReal2Mission_DW.RcvNextMission.FormationPos);
        }

        // End of Switch: '<S26>/AllPositivePosSwitch'

        // Product: '<S26>/DivideThree' incorporates:
        //   Bias: '<S26>/Bias'
        //   Constant: '<S26>/Three'
        //   Math: '<S26>/ModThree'
        //   Product: '<S26>/DivideByThree'
        //   Rounding: '<S26>/idxCeil'

        codegenReal2Mission_DW.DivideThree = (rt_modd_snf(std::ceil(check / 3.0),
            3.0) + 1.0) / 3.0;

        // End of Outputs for SubSystem: '<S15>/ComputDelay'
        // End of Outputs for SubSystem: '<S13>/JumpDelay'
    }

    // End of Outputs for SubSystem: '<S13>/FlightMission'

    // DataStoreRead: '<S1>/Data Store Read'
    codegenReal2Mission_DW.DataStoreRead = codegenReal2Mission_DW.ParamADRC_e;

    // End of Outputs for SubSystem: '<Root>/MissionLogic'

    // ModelReference generated from: '<S32>/Real2SimGuidance' incorporates:
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
                     &codegenReal2Mission_DW.DataStoreRead.hat_b,
                     &codegenReal2Mission_DW.DataStoreRead.omega_o,
                     &codegenReal2Mission_DW.DataStoreRead.omega_b,
                     &codegenReal2Mission_DW.DataStoreRead.P,
                     &codegenReal2Mission_DW.DataStoreRead.I,
                     &codegenReal2Mission_DW.DataStoreRead.D,
                     &codegenReal2Mission_DW.DataStoreRead.useADRC,
                     &codegenReal2Mission_Y.FlightCMD,
                     &codegenReal2Mission_DW.EngagedFlag_Log,
                     &rtb_Real2SimGuidance_o3,
                     &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
                     &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Send: '<S2>/SendLog'
        FlightLogSendData.SendData(&rtb_Real2SimGuidance_o3, sizeof
            (FlightLogging), &status);
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        // Update for Atomic SubSystem: '<Root>/MissionLogic'
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
            // Update for ModelReference generated from: '<S5>/ImmedMission'
            ImmedMission_Update
                (&codegenReal2Mission_DW.BusConversion_InsertedFor_ImmedMission_at_inport_0_BusCreator1,
                 &codegenReal2Mission_DW.Memory,
                 &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw));

            // Update for Memory: '<S1>/Memory'
            codegenReal2Mission_DW.Memory_PreviousInput_l =
                codegenReal2Mission_DW.EngagedFlag_Log;

            // Update for Memory: '<S3>/MemoryFlightStatus'
            codegenReal2Mission_DW.MemoryFlightStatus_PreviousInput =
                rtb_intFlightStatus;

            // Update for Memory: '<S3>/MemoryImmedStatus'
            codegenReal2Mission_DW.MemoryImmedStatus_PreviousInput =
                rtb_intImmedStatus;
        }

        // End of Update for SubSystem: '<Root>/MissionLogic'

        // Update for ModelReference generated from: '<S32>/Real2SimGuidance'
        Real2SimGuidance_Update
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
             &codegenReal2Mission_DW.OR, &codegenReal2Mission_DW.ImmedMission_o2,
             &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw));
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
    // End of Derivatives for SubSystem: '<Root>/MissionLogic'

    // Derivatives for ModelReference generated from: '<S32>/Real2SimGuidance'
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
        (&codegenReal2Mission_M)->Timing.stepSize0 = 0.1;
        rtmSetFirstInitCond((&codegenReal2Mission_M), 1);
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

    // Model Initialize function for ModelReference Block: '<S14>/PreemptableMissionModeSelector' 
    FlightMissionMode_initialize(rtmGetErrorStatusPointer
        ((&codegenReal2Mission_M)),
        &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S23>/MissionUavModel' 
    MissionUAV_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                          rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
                          &((&codegenReal2Mission_M)->solverInfo),
                          &(&codegenReal2Mission_M)->timingBridge,
                          &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
                          &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtzce));

    // Model Initialize function for ModelReference Block: '<S5>/ImmedMission'
    ImmedMission_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                            &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S32>/Real2SimGuidance' 
    Real2SimGuidance_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
        rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
        &((&codegenReal2Mission_M)->solverInfo), &(&codegenReal2Mission_M)
        ->timingBridge, 0, 1,
        &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm));

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

        // InitializeConditions for DataStoreMemory generated from: '<S6>/DSAltitudeGCS' 
        rtw_pthread_mutex_init(&AltitudeGCS_m0);

        // InitializeConditions for DataStoreMemory generated from: '<S6>/DSLatitudeGCS' 
        rtw_pthread_mutex_init(&LatitudeGCS_m0);

        // InitializeConditions for DataStoreMemory generated from: '<S6>/DSLongitudeGCS' 
        rtw_pthread_mutex_init(&LongitudeGCS_m0);

        // SystemInitialize for Atomic SubSystem: '<Root>/MissionLogic'
        // Start for DataStoreMemory: '<S1>/Data Store Memory'
        codegenReal2Mission_DW.ParamADRC_e =
            codegenReal2Mission_ConstP.DataStoreMemory_InitialValue;

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

        // SystemInitialize for ModelReference generated from: '<S5>/ImmedMission' 
        ImmedMission_Init(&codegenReal2Mission_DW.ImmedMission_o3[0],
                          &codegenReal2Mission_DW.ImmedMission_o4,
                          &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtdw),
                          &(codegenReal2Mission_DW.ImmedMission_InstanceData.rtzce));

        // SystemInitialize for Triggered SubSystem: '<S3>/TriggerCurrentMisisonFeedback' 
        // SystemInitialize for MATLAB Function: '<S9>/PrintOnboardLog'
        a = NULL;
        for (int32_T i{0}; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles[i] = a;
        }

        // End of SystemInitialize for MATLAB Function: '<S9>/PrintOnboardLog'
        // End of SystemInitialize for SubSystem: '<S3>/TriggerCurrentMisisonFeedback' 

        // Outputs for Atomic SubSystem: '<S1>/InitializeSimLocation'
        // DataStoreWrite: '<S6>/DSAltitudeGCS' incorporates:
        //   Constant: '<S6>/AltitudeGCS'

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        AltitudeGCS = GCS_Altitude;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);

        // DataStoreWrite: '<S6>/DSLatitudeGCS' incorporates:
        //   Constant: '<S6>/LatitudeGCS'

        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        LatitudeGCS = GCS_Latitude;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);

        // DataStoreWrite: '<S6>/DSLongitudeGCS' incorporates:
        //   Constant: '<S6>/LongitudeGCS'

        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        LongitudeGCS = GCS_Longitude;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);

        // End of Outputs for SubSystem: '<S1>/InitializeSimLocation'
        // End of SystemInitialize for SubSystem: '<Root>/MissionLogic'

        // SystemInitialize for ModelReference generated from: '<S32>/Real2SimGuidance' 
        Real2SimGuidance_Init
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
             &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));
    }

    // set "at time zero" to false
    if (rtmIsFirstInitCond((&codegenReal2Mission_M))) {
        rtmSetFirstInitCond((&codegenReal2Mission_M), 0);
    }
}

// Model terminate function
void codegenReal2MissionModelClass::terminate()
{
    // Terminate for DataStoreMemory generated from: '<S6>/DSAltitudeGCS'
    rtw_pthread_mutex_destroy(AltitudeGCS_m0);

    // Terminate for DataStoreMemory generated from: '<S6>/DSLatitudeGCS'
    rtw_pthread_mutex_destroy(LatitudeGCS_m0);

    // Terminate for DataStoreMemory generated from: '<S6>/DSLongitudeGCS'
    rtw_pthread_mutex_destroy(LongitudeGCS_m0);
}

// Constructor
codegenReal2MissionModelClass::codegenReal2MissionModelClass
    (SendData_IndividualUAVCmdT& CurrentMissionSendData_arg,
     SendData_FlightLoggingT& FlightLogSendData_arg,RecvData_IndividualUAVCmdT&
     MissionCMDRecvData_arg) :
    codegenReal2Mission_U(),
    codegenReal2Mission_Y(),
    codegenReal2Mission_DW(),
    codegenReal2Mission_X(),
    codegenReal2Mission_PrevZCX(),
    CurrentMissionSendData(CurrentMissionSendData_arg),
    FlightLogSendData(FlightLogSendData_arg),
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
