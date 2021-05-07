//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.411
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri May  7 10:23:40 2021
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
#include "codegenReal2Mission.h"
#include "codegenReal2Mission_private.h"
#include "div_s32.h"
#include "floor_jeUa7tf2.h"
#include "split_MzIWb6Db.h"

// Named constants for Chart: '<S2>/MisisonCMDTemporalLogic'
const uint8_T codegenReal2Mission_IN_Pending{ 1U };

const uint8_T codegenReal2Mission_IN_Sending{ 2U };

// Named constants for Chart: '<S2>/TriggerStartSim'
const uint8_T codegenReal2Mission_IN_Running{ 2U };

// Exported block states
real_T AltitudeGCS;                    // Simulink.Signal object 'AltitudeGCS'
real_T LatitudeGCS;                    // Simulink.Signal object 'LatitudeGCS'
real_T LongitudeGCS;                   // Simulink.Signal object 'LongitudeGCS'

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
  int_T nXc { 19 };

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

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop
  (Buffer_missionCmd *q, Msg_missionCmd *elementOut)
{
  boolean_T isPop;

  // Queue generated from: '<Root>/ReceiveNextMission'
  if (!q->fOccupied) {
    isPop = false;
  } else {
    *elementOut = q->fMsg;
    q->fOccupied = false;
    isPop = true;
  }

  // End of Queue generated from: '<Root>/ReceiveNextMission'
  return isPop;
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

int32_T codegenReal2MissionModelClass::
  codegenReal2Mission_ReceiveNextMission_RecvData(missionCmd *data)
{
  Msg_missionCmd msg;
  int32_T status{ 1 };

  // Queue generated from: '<Root>/ReceiveNextMission' incorporates:
  //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

  if (codegenReal2Mission_pop
      (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveNextMission_at_inport_0_Queue,
       &msg)) {
    status = 0;
    *data = *msg.fData;
    codegenReal2Mission_destroyMsg(&msg);
  }

  // End of Queue generated from: '<Root>/ReceiveNextMission'
  return status;
}

// Function for MATLAB Function: '<S1>/getCurrentTime'
void codegenReal2MissionModelClass::codegenReal2Mission_getLocalTime(real_T
  *t_tm_nsec, real_T *t_tm_sec, real_T *t_tm_min, real_T *t_tm_hour, real_T
  *t_tm_mday, real_T *t_tm_mon, real_T *t_tm_year, boolean_T *t_tm_isdst)
{
  coderTm structTm;
  coderLocalTime(&structTm);
  *t_tm_nsec = (real_T)structTm.tm_nsec;
  *t_tm_sec = static_cast<real_T>(structTm.tm_sec);
  *t_tm_min = static_cast<real_T>(structTm.tm_min);
  *t_tm_hour = static_cast<real_T>(structTm.tm_hour);
  *t_tm_mday = static_cast<real_T>(structTm.tm_mday);
  *t_tm_mon = static_cast<real_T>(structTm.tm_mon);
  *t_tm_year = static_cast<real_T>(structTm.tm_year);
  *t_tm_isdst = (structTm.tm_isdst != 0);
}

// Function for MATLAB Function: '<S1>/getCurrentTime'
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

// Function for MATLAB Function: '<S1>/getCurrentTime'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_plus(const creal_T a,
  real_T b)
{
  creal_T c;
  creal_T t;
  real_T ahi;
  real_T alo;
  real_T b_ahi;
  t = codegenReal2Mission_two_sum(a.im, 0.0);
  c = codegenReal2Mission_two_sum(a.re, b);
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

  b_ahi = ahi;
  if (t.im != 0.0) {
    alo += t.im;
    b_ahi = ahi + alo;
    alo -= b_ahi - ahi;
  }

  if (std::isnan(alo)) {
    alo = 0.0;
  }

  c.re = b_ahi;
  c.im = alo;
  return c;
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
  *msg.fData = *data;
  return msg;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push
  (Buffer_missionCmd *q, Msg_missionCmd *element)
{
  boolean_T isPush;

  // Queue generated from: '<Root>/ReceiveNextMission'
  if (q->fOccupied) {
    codegenReal2Mission_destroyMsg(&q->fMsg);
  }

  q->fMsg = *element;
  q->fOccupied = true;
  isPush = true;

  // End of Queue generated from: '<Root>/ReceiveNextMission'
  return isPush;
}

int32_T codegenReal2MissionModelClass::
  codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd *data)
{
  Msg_missionCmd msg;
  int32_T status{ 1 };

  // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' incorporates:
  //   Send: '<S15>/SendMission'

  msg = codegenReal2Mission_createMsg(data);

  // Queue generated from: '<S2>/ReceiveCurrentMission' incorporates:
  //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

  if (codegenReal2Mission_push
      (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveCurrentMission_at_inport_0_Queue,
       &msg)) {
    status = 0;
  } else {
    codegenReal2Mission_destroyMsg(&msg);
  }

  // End of Queue generated from: '<S2>/ReceiveCurrentMission'
  return status;
}

int32_T codegenReal2MissionModelClass::
  codegenReal2Mission_ReceiveCurrentMission_RecvData(missionCmd *data)
{
  Msg_missionCmd msg;
  int32_T status{ 1 };

  // Queue generated from: '<S2>/ReceiveCurrentMission' incorporates:
  //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

  if (codegenReal2Mission_pop
      (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveCurrentMission_at_inport_0_Queue,
       &msg)) {
    status = 0;
    *data = *msg.fData;
    codegenReal2Mission_destroyMsg(&msg);
  }

  // End of Queue generated from: '<S2>/ReceiveCurrentMission'
  return status;
}

int32_T codegenReal2MissionModelClass::
  codegenReal2Mission_ReceiveThisMission_SendData(const missionCmd *data)
{
  Msg_missionCmd msg;
  int32_T status{ 1 };

  // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' incorporates:
  //   Send: '<S10>/Send'

  msg = codegenReal2Mission_createMsg(data);

  // Queue generated from: '<Root>/FeedbackCurrentMission' incorporates:
  //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

  if (codegenReal2Mission_push
      (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_0_Queue,
       &msg)) {
    status = 0;
  } else {
    codegenReal2Mission_destroyMsg(&msg);
  }

  // End of Queue generated from: '<Root>/FeedbackCurrentMission'
  return status;
}

// Function for MATLAB Function: '<S1>/getCurrentTime'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_two_prod(real_T a)
{
  creal_T c;
  creal_T da;
  real_T shi;
  real_T slo;
  int32_T trueCount;
  da = split_MzIWb6Db(a);
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

// Function for MATLAB Function: '<S1>/getCurrentTime'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_times(const creal_T a)
{
  creal_T c;
  real_T ahi;
  real_T alo;
  real_T b;
  b = a.im * 8.64E+7;
  c = codegenReal2Mission_two_prod(a.re);
  alo = c.im;
  ahi = c.re;
  if (b != 0.0) {
    alo = c.im + b;
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

// Function for MATLAB Function: '<S1>/getCurrentTime'
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

// Function for MATLAB Function: '<S1>/getCurrentTime'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_minus(const creal_T a,
  const creal_T b)
{
  creal_T c;
  creal_T cout;
  creal_T t;
  real_T ahi;
  real_T alo;
  real_T b_ahi;
  t = codegenReal2Mission_two_diff(a.im, b.im);
  c = codegenReal2Mission_two_diff(a.re, b.re);
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

  b_ahi = ahi;
  if (t.im != 0.0) {
    alo += t.im;
    b_ahi = ahi + alo;
    alo -= b_ahi - ahi;
  }

  if (std::isnan(alo)) {
    alo = 0.0;
  }

  cout.re = b_ahi;
  cout.im = alo;
  return cout;
}

int32_T codegenReal2MissionModelClass::
  codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data)
{
  Msg_missionCmd msg;
  int32_T status{ 1 };

  // Queue generated from: '<Root>/FeedbackCurrentMission' incorporates:
  //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

  if (codegenReal2Mission_pop
      (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_0_Queue,
       &msg)) {
    status = 0;
    *data = *msg.fData;
    codegenReal2Mission_destroyMsg(&msg);
  }

  // End of Queue generated from: '<Root>/FeedbackCurrentMission'
  return status;
}

// Function for MATLAB Function: '<S3>/CommandCheck'
creal_T codegenReal2MissionModelClass::codegenReal2Mission_createFromDateVec(
  const real_T inData[7])
{
  creal_T t;
  creal_T tmp;
  real_T check;
  real_T fracSecs;
  real_T mo;
  real_T second;
  second = inData[5];
  fracSecs = inData[6];
  check = (((((inData[0] + inData[1]) + inData[2]) + inData[3]) + inData[4]) +
           inData[5]) + inData[6];
  if ((!std::isinf(check)) && (!std::isnan(check))) {
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

    tmp.re = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor(check /
      100.0)) + std::floor(check / 400.0)) + std::floor((153.0 * mo + 2.0) / 5.0))
               + inData[2]) + 60.0) - 719529.0;
    tmp.im = 0.0;
    t = codegenReal2Mission_plus(codegenReal2Mission_plus
      (codegenReal2Mission_plus(codegenReal2Mission_times(tmp), (60.0 * inData[3]
      + inData[4]) * 60000.0), second * 1000.0), fracSecs);
  } else {
    t.re = check;
    t.im = 0.0;
  }

  return t;
}

// Function for MATLAB Function: '<S3>/CommandCheck'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isequaln(int32_T
  varargin_1_SequenceId, int32_T varargin_1_MissionMode, real_T
  varargin_1_MissionLocation_Lat, real_T varargin_1_MissionLocation_Lon, real_T
  varargin_1_MissionLocation_Alt, real_T varargin_1_MissionLocation_degHDG,
  real32_T varargin_1_params_Param1, real32_T varargin_1_params_Param2, real32_T
  varargin_1_params_Param3, real32_T varargin_1_params_Param4, real32_T
  varargin_1_params_Param5, real32_T varargin_1_params_Param6, real32_T
  varargin_1_params_Param7, const Location varargin_1_StartPosition, int32_T
  varargin_1_numUAV, int32_T varargin_1_FormationPos, real_T
  varargin_1_StartTime, int32_T varargin_2_SequenceId, int32_T
  varargin_2_MissionMode, const Location varargin_2_MissionLocation, const
  Parameters varargin_2_params, const Location varargin_2_StartPosition, int32_T
  varargin_2_numUAV, int32_T varargin_2_FormationPos, real_T
  varargin_2_StartTime)
{
  boolean_T e_p;
  boolean_T p;
  p = false;
  if ((varargin_1_StartTime == varargin_2_StartTime) || (std::isnan
       (varargin_1_StartTime) && std::isnan(varargin_2_StartTime))) {
    if (varargin_1_FormationPos == varargin_2_FormationPos) {
      if (varargin_1_numUAV == varargin_2_numUAV) {
        if ((varargin_1_StartPosition.degHDG == varargin_2_StartPosition.degHDG)
            || (std::isnan(varargin_1_StartPosition.degHDG) && std::isnan
                (varargin_2_StartPosition.degHDG))) {
          if ((varargin_1_StartPosition.Alt == varargin_2_StartPosition.Alt) ||
              (std::isnan(varargin_1_StartPosition.Alt) && std::isnan
               (varargin_2_StartPosition.Alt))) {
            e_p = (((varargin_1_StartPosition.Lon ==
                     varargin_2_StartPosition.Lon) || (std::isnan
                     (varargin_1_StartPosition.Lon) && std::isnan
                     (varargin_2_StartPosition.Lon))) &&
                   ((varargin_1_StartPosition.Lat ==
                     varargin_2_StartPosition.Lat) || (std::isnan
                     (varargin_1_StartPosition.Lat) && std::isnan
                     (varargin_2_StartPosition.Lat))));
          } else {
            e_p = false;
          }
        } else {
          e_p = false;
        }

        if (e_p) {
          if ((varargin_1_params_Param7 == varargin_2_params.Param7) || (std::
               isnan(varargin_1_params_Param7) && std::isnan
               (varargin_2_params.Param7))) {
            if ((varargin_1_params_Param6 == varargin_2_params.Param6) || (std::
                 isnan(varargin_1_params_Param6) && std::isnan
                 (varargin_2_params.Param6))) {
              if ((varargin_1_params_Param5 == varargin_2_params.Param5) || (std::
                   isnan(varargin_1_params_Param5) && std::isnan
                   (varargin_2_params.Param5))) {
                if ((varargin_1_params_Param4 == varargin_2_params.Param4) ||
                    (std::isnan(varargin_1_params_Param4) && std::isnan
                     (varargin_2_params.Param4))) {
                  if ((varargin_1_params_Param3 == varargin_2_params.Param3) ||
                      (std::isnan(varargin_1_params_Param3) && std::isnan
                       (varargin_2_params.Param3))) {
                    e_p = (((varargin_1_params_Param2 ==
                             varargin_2_params.Param2) || (std::isnan
                             (varargin_1_params_Param2) && std::isnan
                             (varargin_2_params.Param2))) &&
                           ((varargin_1_params_Param1 ==
                             varargin_2_params.Param1) || (std::isnan
                             (varargin_1_params_Param1) && std::isnan
                             (varargin_2_params.Param1))));
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
            if ((varargin_1_MissionLocation_degHDG ==
                 varargin_2_MissionLocation.degHDG) || (std::isnan
                 (varargin_1_MissionLocation_degHDG) && std::isnan
                 (varargin_2_MissionLocation.degHDG))) {
              if ((varargin_1_MissionLocation_Alt ==
                   varargin_2_MissionLocation.Alt) || (std::isnan
                   (varargin_1_MissionLocation_Alt) && std::isnan
                   (varargin_2_MissionLocation.Alt))) {
                e_p = (((varargin_1_MissionLocation_Lon ==
                         varargin_2_MissionLocation.Lon) || (std::isnan
                         (varargin_1_MissionLocation_Lon) && std::isnan
                         (varargin_2_MissionLocation.Lon))) &&
                       ((varargin_1_MissionLocation_Lat ==
                         varargin_2_MissionLocation.Lat) || (std::isnan
                         (varargin_1_MissionLocation_Lat) && std::isnan
                         (varargin_2_MissionLocation.Lat))));
              } else {
                e_p = false;
              }
            } else {
              e_p = false;
            }

            if (e_p) {
              e_p = ((varargin_1_MissionMode == varargin_2_MissionMode) &&
                     (varargin_1_SequenceId == varargin_2_SequenceId));
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
  } else {
    e_p = false;
  }

  if (e_p) {
    p = true;
  }

  return p;
}

// Function for MATLAB Function: '<S3>/CommandCheck'
void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec(const creal_T
  dd, real_T *y, real_T *mo, real_T *d, real_T *h, real_T *m, real_T *s)
{
  creal_T b_c;
  creal_T c_s;
  creal_T msOfDay;
  creal_T r;
  creal_T t;
  real_T a;
  real_T b_alo;
  real_T c_ahi;
  real_T d_ahi;
  real_T dc;
  real_T shi;
  int32_T b_r_tmp;
  int32_T c_r_tmp;
  int32_T ia_quot_tmp;
  int32_T ic_quot_tmp;
  int32_T ic_rem;
  int32_T imo;
  b_c.re = dd.re / 8.64E+7;
  t = codegenReal2Mission_two_prod(b_c.re);
  c_s.re = 0.0;
  c_s.im = 0.0;
  if (dd.re != t.re) {
    c_s = codegenReal2Mission_two_diff(dd.re, t.re);
  }

  c_s.re = (0.0 * dd.im + c_s.re) - 0.0 * t.im;
  c_s.im = (c_s.im + dd.im) - t.im;
  shi = (c_s.re + c_s.im) / 8.64E+7;
  b_alo = 0.0;
  d_ahi = b_c.re;
  if (shi != 0.0) {
    d_ahi = b_c.re + shi;
    b_alo = shi - (d_ahi - b_c.re);
  }

  if (std::isnan(b_alo)) {
    b_alo = 0.0;
  }

  r.re = d_ahi;
  r.im = b_alo;
  r = floor_jeUa7tf2(r);
  d_ahi = r.re + r.im;
  msOfDay = codegenReal2Mission_minus(dd, codegenReal2Mission_times(r));
  b_c.re = msOfDay.re / 1000.0;
  t = split_MzIWb6Db(b_c.re);
  shi = b_c.re * 1000.0;
  b_alo = (t.re * 1000.0 - shi) + t.im * 1000.0;
  imo = 0;
  if (std::isnan(b_alo)) {
    imo = 1;
  }

  if (0 <= static_cast<int32_T>(imo - 1)) {
    b_alo = 0.0;
  }

  c_s.re = 0.0;
  c_s.im = 0.0;
  if (msOfDay.re != shi) {
    c_s = codegenReal2Mission_two_diff(msOfDay.re, shi);
  }

  c_s.re = (0.0 * msOfDay.im + c_s.re) - 0.0 * b_alo;
  c_s.im = (c_s.im + msOfDay.im) - b_alo;
  shi = (c_s.re + c_s.im) / 1000.0;
  b_alo = 0.0;
  c_ahi = b_c.re;
  if (shi != 0.0) {
    c_ahi = b_c.re + shi;
    b_alo = shi - (c_ahi - b_c.re);
  }

  if (std::isnan(b_alo)) {
    b_alo = 0.0;
  }

  b_c.re = c_ahi;
  b_c.im = b_alo;
  t = floor_jeUa7tf2(b_c);
  b_c = codegenReal2Mission_minus(b_c, t);
  shi = t.re + t.im;
  if (((d_ahi + 719529.0) - 61.0 >= 0.0) && ((d_ahi + 719529.0) - 61.0 <=
       2.147483647E+9)) {
    b_alo = std::round((d_ahi + 719529.0) - 61.0);
    if (b_alo < 2.147483648E+9) {
      if (b_alo >= -2.147483648E+9) {
        imo = static_cast<int32_T>(b_alo);
      } else {
        imo = MIN_int32_T;
      }
    } else {
      imo = MAX_int32_T;
    }

    b_r_tmp = static_cast<int32_T>(imo - static_cast<int32_T>(146097 * div_s32
      (imo, 146097)));
    ic_quot_tmp = static_cast<int32_T>(std::trunc(static_cast<real_T>(b_r_tmp) /
      36524.0));
    ic_rem = static_cast<int32_T>(b_r_tmp - static_cast<int32_T>(36524 * div_s32
      (b_r_tmp, 36524)));
    if (ic_quot_tmp > 3) {
      ic_quot_tmp = 3;
      ic_rem = static_cast<int32_T>(b_r_tmp - 109572);
    }

    c_r_tmp = static_cast<int32_T>(ic_rem - static_cast<int32_T>(1461 * div_s32
      (ic_rem, 1461)));
    ia_quot_tmp = static_cast<int32_T>(std::trunc(static_cast<real_T>(c_r_tmp) /
      365.0));
    b_r_tmp = static_cast<int32_T>(c_r_tmp - static_cast<int32_T>(365 * div_s32
      (c_r_tmp, 365)));
    if (ia_quot_tmp > 3) {
      ia_quot_tmp = 3;
      b_r_tmp = static_cast<int32_T>(c_r_tmp - 1095);
    }

    *y = ((std::trunc(static_cast<real_T>(imo) / 146097.0) * 400.0 +
           static_cast<real_T>(ic_quot_tmp) * 100.0) + std::trunc
          (static_cast<real_T>(ic_rem) / 1461.0) * 4.0) + static_cast<real_T>
      (ia_quot_tmp);
    imo = static_cast<int32_T>(static_cast<int32_T>(std::trunc
      ((static_cast<real_T>(b_r_tmp) * 5.0 + 308.0) / 153.0)) - 2);
    b_alo = static_cast<real_T>(imo);
    *d = ((static_cast<real_T>(b_r_tmp) - std::trunc((static_cast<real_T>(imo) +
             4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
  } else {
    b_alo = std::floor((((r.re + r.im) + 719529.0) - 61.0) / 146097.0);
    c_ahi = ((d_ahi + 719529.0) - 61.0) - b_alo * 146097.0;
    d_ahi = std::floor(c_ahi / 36524.0);
    if (d_ahi > 3.0) {
      d_ahi = 3.0;
    }

    dc = c_ahi - d_ahi * 36524.0;
    c_ahi = std::floor(dc / 1461.0);
    dc -= c_ahi * 1461.0;
    a = std::floor(dc / 365.0);
    if (a > 3.0) {
      a = 3.0;
    }

    dc -= a * 365.0;
    *y = ((b_alo * 400.0 + d_ahi * 100.0) + c_ahi * 4.0) + a;
    b_alo = std::floor((dc * 5.0 + 308.0) / 153.0) - 2.0;
    *d = ((dc - std::floor((b_alo + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
  }

  if (b_alo > 9.0) {
    (*y)++;
    *mo = (b_alo + 2.0) - 11.0;
  } else {
    *mo = (b_alo + 2.0) + 1.0;
  }

  if ((shi >= 0.0) && (shi <= 2.147483647E+9)) {
    imo = static_cast<int32_T>(std::round(shi));
    ic_quot_tmp = static_cast<int32_T>(imo - static_cast<int32_T>(3600 * div_s32
      (imo, 3600)));
    *h = std::trunc(static_cast<real_T>(imo) / 3600.0);
    *m = std::trunc(static_cast<real_T>(ic_quot_tmp) / 60.0);
    shi = static_cast<real_T>(static_cast<int32_T>(ic_quot_tmp -
      static_cast<int32_T>(60 * div_s32(ic_quot_tmp, 60))));
  } else {
    *h = std::floor(shi / 3600.0);
    *m = std::floor((shi - 3600.0 * *h) / 60.0);
    shi -= 60.0 * *m;
  }

  *s = (b_c.re + b_c.im) + shi;
  if (*s == 60.0) {
    *s = 59.999999999999993;
  }

  if ((dd.re == (rtInf)) && (dd.im == 0.0)) {
    *y = (rtInf);
  } else if ((dd.re == (rtMinusInf)) && (dd.im == 0.0)) {
    *y = (rtMinusInf);
  }
}

int32_T codegenReal2MissionModelClass::
  codegenReal2Mission_ReceiveNextMission_SendData(const missionCmd *data)
{
  Msg_missionCmd msg;
  int32_T status{ 1 };

  // DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission' incorporates:
  //   Send: '<S3>/SendPushedMissionCMD'

  msg = codegenReal2Mission_createMsg(data);

  // Queue generated from: '<Root>/ReceiveNextMission' incorporates:
  //   DiscreteEventSubgraph generated from: '<Root>/FeedbackCurrentMission'

  if (codegenReal2Mission_push
      (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveNextMission_at_inport_0_Queue,
       &msg)) {
    status = 0;
  } else {
    codegenReal2Mission_destroyMsg(&msg);
  }

  // End of Queue generated from: '<Root>/ReceiveNextMission'
  return status;
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
  real_T rtb_Down;
  IndividualUAVCmd rtb_IndividualUAVCmd;
  creal_T c_s;
  creal_T da;
  creal_T msOfDay;
  creal_T r;
  creal_T t;
  creal_T thisData;
  real_T a;
  real_T b_shi;
  real_T check;
  real_T fracSecs;
  real_T rtb_Integrator_idx_0;
  real_T rtb_Integrator_idx_1;
  real_T second;
  real_T temp;
  int32_T b_r_tmp;
  int32_T c_r_tmp;
  int32_T ia_quot_tmp;
  int32_T ic_quot_tmp;
  int32_T ic_rem;
  int32_T imo;
  int32_T status;
  boolean_T rtb_ReceiveCurrentMission_o1;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // set solver stop time
    rtsiSetSolverStopTime(&(&codegenReal2Mission_M)->solverInfo,
                          (((&codegenReal2Mission_M)->Timing.clockTick0+1)*
      (&codegenReal2Mission_M)->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep((&codegenReal2Mission_M))) {
    (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetT(&(&codegenReal2Mission_M)
      ->solverInfo);
  }

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Receive: '<Root>/ReceiveNextMission'
    codegenReal2Mission_ReceiveNextMission_RecvData
      (&codegenReal2Mission_B.ReceiveNextMission);

    // MATLAB Function: '<Root>/getCurrentTime' incorporates:
    //   DataStoreWrite: '<Root>/WriteClock'

    codegenReal2Mission_getLocalTime(&fracSecs, &second, &rtb_Integrator_idx_0,
      &rtb_Integrator_idx_1, &temp, &a, &b_shi, &rtb_ReceiveCurrentMission_o1);
    fracSecs /= 1.0E+6;
    check = (((((b_shi + a) + temp) + rtb_Integrator_idx_1) +
              rtb_Integrator_idx_0) + second) + fracSecs;
    if ((!std::isinf(check)) && (!std::isnan(check))) {
      if ((a < 1.0) || (a > 12.0)) {
        check = std::floor((a - 1.0) / 12.0);
        b_shi += check;
        a = ((a - 1.0) - check * 12.0) + 1.0;
      }

      if (a < 3.0) {
        b_shi--;
        a += 9.0;
      } else {
        a -= 3.0;
      }

      a = ((((((365.0 * b_shi + std::floor(b_shi / 4.0)) - std::floor(b_shi /
                100.0)) + std::floor(b_shi / 400.0)) + std::floor((153.0 * a +
               2.0) / 5.0)) + temp) + 60.0) - 719529.0;
      temp = 1.34217729E+8 * a;
      b_shi = temp - (temp - a);
      temp = a * 8.64E+7;
      a = (a - b_shi) * 8.64E+7 + (b_shi * 8.64E+7 - temp);
      thisData.im = a;
      if (std::isnan(a)) {
        thisData.im = 0.0;
      }

      if ((fracSecs < 0.0) || (1000.0 <= fracSecs)) {
        check = std::floor(fracSecs / 1000.0);
        second += check;
        fracSecs -= check * 1000.0;
      }

      thisData.re = temp;
      thisData = codegenReal2Mission_plus(codegenReal2Mission_plus
        (codegenReal2Mission_plus(thisData, (60.0 * rtb_Integrator_idx_1 +
        rtb_Integrator_idx_0) * 60000.0), second * 1000.0), fracSecs);
    } else {
      thisData.re = check;
    }

    codegenReal2Mission_DW.Clock = thisData.re / 1000.0;

    // End of MATLAB Function: '<Root>/getCurrentTime'

    // Chart: '<S2>/MisisonCMDTemporalLogic' incorporates:
    //   DataStoreWrite: '<Root>/WriteClock'

    if (static_cast<uint32_T>
        (codegenReal2Mission_DW.is_active_c20_codegenReal2Mission) == 0U) {
      codegenReal2Mission_DW.is_active_c20_codegenReal2Mission = 1U;
      codegenReal2Mission_DW.is_c20_codegenReal2Mission =
        codegenReal2Mission_IN_Pending;
      codegenReal2Mission_B.TriggerSend = 0.0;
    } else if (static_cast<int32_T>
               (codegenReal2Mission_DW.is_c20_codegenReal2Mission) == 1) {
      if (codegenReal2Mission_DW.Clock >=
          codegenReal2Mission_B.ReceiveNextMission.StartTime) {
        codegenReal2Mission_DW.is_c20_codegenReal2Mission =
          codegenReal2Mission_IN_Sending;
        codegenReal2Mission_B.TriggerSend = 1.0;
      } else {
        codegenReal2Mission_B.TriggerSend = 0.0;
      }

      // case IN_Sending:
    } else if (codegenReal2Mission_DW.Clock <=
               codegenReal2Mission_B.ReceiveNextMission.StartTime) {
      codegenReal2Mission_DW.is_c20_codegenReal2Mission =
        codegenReal2Mission_IN_Pending;
      codegenReal2Mission_B.TriggerSend = 0.0;
    }

    // End of Chart: '<S2>/MisisonCMDTemporalLogic'

    // Outputs for Triggered SubSystem: '<S2>/TriggerBroadcastAtMissionTime' incorporates:
    //   TriggerPort: '<S15>/ReachMissionTime'

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE,
                         (codegenReal2Mission_B.TriggerSend));
      if (zcEvent != NO_ZCEVENT) {
        // Send: '<S15>/SendMission'
        codegenReal2Mission_ReceiveCurrentMission_SendData
          (&codegenReal2Mission_B.ReceiveNextMission);
      }
    }

    // End of Outputs for SubSystem: '<S2>/TriggerBroadcastAtMissionTime'

    // Receive: '<S2>/ReceiveCurrentMission'
    imo = codegenReal2Mission_ReceiveCurrentMission_RecvData
      (&codegenReal2Mission_B.ReceiveCurrentMission_o2);
    rtb_ReceiveCurrentMission_o1 = (imo != 1);

    // Outputs for Triggered SubSystem: '<S2>/FeedbackMissionCMD' incorporates:
    //   TriggerPort: '<S10>/Trigger'

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      if (rtb_ReceiveCurrentMission_o1 && (static_cast<int32_T>
           (codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE) != 1)) {
        // Send: '<S10>/Send'
        codegenReal2Mission_ReceiveThisMission_SendData
          (&codegenReal2Mission_B.ReceiveCurrentMission_o2);
      }

      codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE =
        static_cast<ZCSigState>(rtb_ReceiveCurrentMission_o1);
    }

    // End of Outputs for SubSystem: '<S2>/FeedbackMissionCMD'

    // Memory: '<S2>/MemoryCurrentMission'
    codegenReal2Mission_B.MemoryCurrentMission =
      codegenReal2Mission_DW.MemoryCurrentMission_PreviousInput;

    // Chart: '<S2>/TriggerStartSim' incorporates:
    //   Constant: '<S8>/Constant'
    //   Constant: '<S9>/Constant'
    //   Logic: '<S2>/AND'
    //   RelationalOperator: '<S8>/Compare'
    //   RelationalOperator: '<S9>/Compare'

    if (static_cast<uint32_T>
        (codegenReal2Mission_DW.is_active_c24_codegenReal2Mission) == 0U) {
      codegenReal2Mission_DW.is_active_c24_codegenReal2Mission = 1U;
      codegenReal2Mission_DW.is_c24_codegenReal2Mission =
        codegenReal2Mission_IN_Pending;
      codegenReal2Mission_B.StartSim = false;
    } else if (static_cast<int32_T>
               (codegenReal2Mission_DW.is_c24_codegenReal2Mission) == 1) {
      if ((codegenReal2Mission_B.MemoryCurrentMission.MissionMode > 0) &&
          (codegenReal2Mission_B.MemoryCurrentMission.SequenceId > 0)) {
        codegenReal2Mission_DW.is_c24_codegenReal2Mission =
          codegenReal2Mission_IN_Running;
        codegenReal2Mission_B.StartSim = true;
      } else {
        codegenReal2Mission_B.StartSim = false;
      }
    } else {
      // case IN_Running:
      codegenReal2Mission_B.StartSim = true;
    }

    // End of Chart: '<S2>/TriggerStartSim'

    // Memory: '<S2>/MemoryPrevMissionLocation'
    codegenReal2Mission_B.MemoryPrevMissionLocation =
      codegenReal2Mission_DW.MemoryPrevMissionLocation_PreviousInput;

    // Memory: '<S2>/DelayPose'
    codegenReal2Mission_B.DelayPose[0] =
      codegenReal2Mission_DW.DelayPose_PreviousInput[0];
    codegenReal2Mission_B.DelayPose[1] =
      codegenReal2Mission_DW.DelayPose_PreviousInput[1];
    codegenReal2Mission_B.DelayPose[2] =
      codegenReal2Mission_DW.DelayPose_PreviousInput[2];
    codegenReal2Mission_B.DelayPose[3] =
      codegenReal2Mission_DW.DelayPose_PreviousInput[3];

    // ModelReference: '<S2>/PreemptableMissionModeSelector' incorporates:
    //   Outport: '<Root>/thisTaskStatus'

    PreemptableMissionModeSelector(&codegenReal2Mission_B.StartSim,
      &codegenReal2Mission_B.MemoryCurrentMission.MissionMode,
      &codegenReal2Mission_B.MemoryPrevMissionLocation,
      &codegenReal2Mission_B.MemoryCurrentMission.MissionLocation,
      &codegenReal2Mission_B.MemoryCurrentMission.params,
      &codegenReal2Mission_B.MemoryCurrentMission.StartPosition,
      &codegenReal2Mission_B.MemoryCurrentMission.SequenceId,
      &codegenReal2Mission_B.MemoryCurrentMission.FormationPos,
      &codegenReal2Mission_B.MemoryCurrentMission.numUAV,
      &codegenReal2Mission_B.DelayPose[0], &codegenReal2Mission_Y.thisTaskStatus,
      &codegenReal2Mission_B.PreemptableMissionModeSelector_o2,
      &codegenReal2Mission_B.PreemptableMissionModeSelector_o3,
      &codegenReal2Mission_B.PreemptableMissionModeSelector_o4[0],
      &codegenReal2Mission_B.PreemptableMissionModeSelector_o5[0],
      &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtb),
      &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw),
      &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtzce));
  }

  // Integrator: '<S2>/Integrator'
  rtb_ReceiveCurrentMission_o1 = rtsiGetIsOkayToUpdateMode
    (&(&codegenReal2Mission_M)->solverInfo);
  if (rtb_ReceiveCurrentMission_o1 &&
      (codegenReal2Mission_B.PreemptableMissionModeSelector_o3 != 0.0)) {
    // evaluate the level of the reset signal
    codegenReal2Mission_X.Integrator_CSTATE[0] = 0.0;
    codegenReal2Mission_X.Integrator_CSTATE[1] = 0.0;
  }

  rtb_Integrator_idx_0 = codegenReal2Mission_X.Integrator_CSTATE[0];
  rtb_Integrator_idx_1 = codegenReal2Mission_X.Integrator_CSTATE[1];

  // End of Integrator: '<S2>/Integrator'

  // Outputs for Enabled SubSystem: '<S2>/MissionSimUAV' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M)) && rtmIsMajorTimeStep
      ((&codegenReal2Mission_M))) {
    codegenReal2Mission_DW.MissionSimUAV_MODE = codegenReal2Mission_B.StartSim;
  }

  if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
    // ModelReference generated from: '<S13>/MissionUavModel'
    MissionUAV(&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
               &codegenReal2Mission_B.PreemptableMissionModeSelector_o3,
               &codegenReal2Mission_B.PreemptableMissionModeSelector_o4[0],
               &codegenReal2Mission_B.PreemptableMissionModeSelector_o2.Height,
               &codegenReal2Mission_B.PreemptableMissionModeSelector_o2.AirSpeed,
               &codegenReal2Mission_B.PreemptableMissionModeSelector_o2.HeadingAngle,
               &codegenReal2Mission_B.North, &codegenReal2Mission_B.East,
               &codegenReal2Mission_B.Height, &codegenReal2Mission_B.AirSpeed,
               &codegenReal2Mission_B.HeadingAngle,
               &codegenReal2Mission_B.FlightPathAngle,
               &codegenReal2Mission_B.RollAngle,
               &codegenReal2Mission_B.RollAngleRate,
               &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtb),
               &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw),
               &(codegenReal2Mission_X.MissionUavModel_CSTATE));
  }

  // End of Outputs for SubSystem: '<S2>/MissionSimUAV'
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Gain: '<S14>/Gain2'
    rtb_Down = -codegenReal2Mission_B.Height;
  }

  // Sum: '<S2>/SumEast'
  codegenReal2Mission_B.SumEast = rtb_Integrator_idx_1 +
    codegenReal2Mission_B.East;

  // Sum: '<S2>/SumNorth'
  codegenReal2Mission_B.SumNorth = rtb_Integrator_idx_0 +
    codegenReal2Mission_B.North;

  // ModelReference generated from: '<Root>/Real2SimGuidance' incorporates:
  //   Inport: '<Root>/Altitude'
  //   Inport: '<Root>/FlightMode'
  //   Inport: '<Root>/GroundSpeed'
  //   Inport: '<Root>/RealUAVLatLonState'
  //   Inport: '<Root>/VectorSpd'
  //   Outport: '<Root>/EngagedFlag'
  //   Outport: '<Root>/LookAheadPoint'
  //   Outport: '<Root>/RefAirspeed'

  Real2SimGuidance(&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
                   &codegenReal2Mission_B.SumNorth,
                   &codegenReal2Mission_B.SumEast, &codegenReal2Mission_B.Height,
                   &codegenReal2Mission_B.AirSpeed,
                   &codegenReal2Mission_B.HeadingAngle,
                   &codegenReal2Mission_U.RealUAVLatLonState,
                   &codegenReal2Mission_U.FlightMode,
                   &codegenReal2Mission_U.GroundSpeed,
                   &codegenReal2Mission_Y.LookAheadPoint_i,
                   &codegenReal2Mission_Y.RefAirspeed,
                   &codegenReal2Mission_B.ExecutionTrigger,
                   &codegenReal2Mission_Y.EngagedFlag,
                   &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtb),
                   &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
                   &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));
  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // MATLAB Function: '<S1>/getCurrentTime'
    codegenReal2Mission_getLocalTime(&fracSecs, &second, &rtb_Integrator_idx_0,
      &rtb_Integrator_idx_1, &temp, &a, &b_shi, &rtb_ReceiveCurrentMission_o1);
    fracSecs /= 1.0E+6;
    check = (((((b_shi + a) + temp) + rtb_Integrator_idx_1) +
              rtb_Integrator_idx_0) + second) + fracSecs;
    if ((!std::isinf(check)) && (!std::isnan(check))) {
      if ((a < 1.0) || (a > 12.0)) {
        check = std::floor((a - 1.0) / 12.0);
        b_shi += check;
        a = ((a - 1.0) - check * 12.0) + 1.0;
      }

      if (a < 3.0) {
        b_shi--;
        a += 9.0;
      } else {
        a -= 3.0;
      }

      if ((fracSecs < 0.0) || (1000.0 <= fracSecs)) {
        check = std::floor(fracSecs / 1000.0);
        second += check;
        fracSecs -= check * 1000.0;
      }

      t.re = ((((((365.0 * b_shi + std::floor(b_shi / 4.0)) - std::floor(b_shi /
        100.0)) + std::floor(b_shi / 400.0)) + std::floor((153.0 * a + 2.0) /
                 5.0)) + temp) + 60.0) - 719529.0;
      t.im = 0.0;
      thisData = codegenReal2Mission_plus(codegenReal2Mission_plus
        (codegenReal2Mission_plus(codegenReal2Mission_times(t), (60.0 *
        rtb_Integrator_idx_1 + rtb_Integrator_idx_0) * 60000.0), second * 1000.0),
        fracSecs);
    } else {
      thisData.re = check;
      thisData.im = 0.0;
    }

    da.re = thisData.re / 8.64E+7;
    t = codegenReal2Mission_two_prod(da.re);
    c_s.re = 0.0;
    c_s.im = 0.0;
    if (thisData.re != t.re) {
      c_s = codegenReal2Mission_two_diff(thisData.re, t.re);
    }

    c_s.re = (0.0 * thisData.im + c_s.re) - 0.0 * t.im;
    c_s.im = (c_s.im + thisData.im) - t.im;
    rtb_Integrator_idx_0 = (c_s.re + c_s.im) / 8.64E+7;
    rtb_Integrator_idx_1 = 0.0;
    second = da.re;
    if (rtb_Integrator_idx_0 != 0.0) {
      second = da.re + rtb_Integrator_idx_0;
      rtb_Integrator_idx_1 = rtb_Integrator_idx_0 - (second - da.re);
    }

    if (std::isnan(rtb_Integrator_idx_1)) {
      rtb_Integrator_idx_1 = 0.0;
    }

    r.re = second;
    r.im = rtb_Integrator_idx_1;
    r = floor_jeUa7tf2(r);
    second = r.re + r.im;
    msOfDay = codegenReal2Mission_minus(thisData, codegenReal2Mission_times(r));
    da.re = msOfDay.re / 1000.0;
    t = split_MzIWb6Db(da.re);
    temp = da.re * 1000.0;
    rtb_Integrator_idx_0 = (t.re * 1000.0 - temp) + t.im * 1000.0;
    imo = 0;
    if (std::isnan(rtb_Integrator_idx_0)) {
      imo = 1;
    }

    if (0 <= static_cast<int32_T>(imo - 1)) {
      rtb_Integrator_idx_0 = 0.0;
    }

    c_s.re = 0.0;
    c_s.im = 0.0;
    if (msOfDay.re != temp) {
      c_s = codegenReal2Mission_two_diff(msOfDay.re, temp);
    }

    c_s.re = (0.0 * msOfDay.im + c_s.re) - 0.0 * rtb_Integrator_idx_0;
    c_s.im = (c_s.im + msOfDay.im) - rtb_Integrator_idx_0;
    rtb_Integrator_idx_0 = (c_s.re + c_s.im) / 1000.0;
    rtb_Integrator_idx_1 = 0.0;
    fracSecs = da.re;
    if (rtb_Integrator_idx_0 != 0.0) {
      fracSecs = da.re + rtb_Integrator_idx_0;
      rtb_Integrator_idx_1 = rtb_Integrator_idx_0 - (fracSecs - da.re);
    }

    if (std::isnan(rtb_Integrator_idx_1)) {
      rtb_Integrator_idx_1 = 0.0;
    }

    da.re = fracSecs;
    da.im = rtb_Integrator_idx_1;
    t = floor_jeUa7tf2(da);
    da = codegenReal2Mission_minus(da, t);
    rtb_Integrator_idx_0 = t.re + t.im;
    if (((second + 719529.0) - 61.0 >= 0.0) && ((second + 719529.0) - 61.0 <=
         2.147483647E+9)) {
      rtb_Integrator_idx_1 = std::round((second + 719529.0) - 61.0);
      if (rtb_Integrator_idx_1 < 2.147483648E+9) {
        if (rtb_Integrator_idx_1 >= -2.147483648E+9) {
          imo = static_cast<int32_T>(rtb_Integrator_idx_1);
        } else {
          imo = MIN_int32_T;
        }
      } else {
        imo = MAX_int32_T;
      }

      b_r_tmp = static_cast<int32_T>(imo - static_cast<int32_T>(146097 * div_s32
        (imo, 146097)));
      ic_quot_tmp = static_cast<int32_T>(std::trunc(static_cast<real_T>(b_r_tmp)
        / 36524.0));
      ic_rem = static_cast<int32_T>(b_r_tmp - static_cast<int32_T>(36524 *
        div_s32(b_r_tmp, 36524)));
      if (ic_quot_tmp > 3) {
        ic_quot_tmp = 3;
        ic_rem = static_cast<int32_T>(b_r_tmp - 109572);
      }

      c_r_tmp = static_cast<int32_T>(ic_rem - static_cast<int32_T>(1461 *
        div_s32(ic_rem, 1461)));
      ia_quot_tmp = static_cast<int32_T>(std::trunc(static_cast<real_T>(c_r_tmp)
        / 365.0));
      b_r_tmp = static_cast<int32_T>(c_r_tmp - static_cast<int32_T>(365 *
        div_s32(c_r_tmp, 365)));
      if (ia_quot_tmp > 3) {
        ia_quot_tmp = 3;
        b_r_tmp = static_cast<int32_T>(c_r_tmp - 1095);
      }

      rtb_Integrator_idx_1 = ((std::trunc(static_cast<real_T>(imo) / 146097.0) *
        400.0 + static_cast<real_T>(ic_quot_tmp) * 100.0) + std::trunc(
        static_cast<real_T>(ic_rem) / 1461.0) * 4.0) + static_cast<real_T>
        (ia_quot_tmp);
      imo = static_cast<int32_T>(static_cast<int32_T>(std::trunc
        ((static_cast<real_T>(b_r_tmp) * 5.0 + 308.0) / 153.0)) - 2);
      fracSecs = static_cast<real_T>(imo);
      second = ((static_cast<real_T>(b_r_tmp) - std::trunc((static_cast<real_T>
        (imo) + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    } else {
      rtb_Integrator_idx_1 = std::floor((((r.re + r.im) + 719529.0) - 61.0) /
        146097.0);
      fracSecs = ((second + 719529.0) - 61.0) - rtb_Integrator_idx_1 * 146097.0;
      second = std::floor(fracSecs / 36524.0);
      if (second > 3.0) {
        second = 3.0;
      }

      temp = fracSecs - second * 36524.0;
      fracSecs = std::floor(temp / 1461.0);
      temp -= fracSecs * 1461.0;
      a = std::floor(temp / 365.0);
      if (a > 3.0) {
        a = 3.0;
      }

      temp -= a * 365.0;
      rtb_Integrator_idx_1 = ((rtb_Integrator_idx_1 * 400.0 + second * 100.0) +
        fracSecs * 4.0) + a;
      fracSecs = std::floor((temp * 5.0 + 308.0) / 153.0) - 2.0;
      second = ((temp - std::floor((fracSecs + 4.0) * 153.0 / 5.0)) + 122.0) +
        1.0;
    }

    if (fracSecs > 9.0) {
      rtb_Integrator_idx_1++;
      fracSecs = (fracSecs + 2.0) - 11.0;
    } else {
      fracSecs = (fracSecs + 2.0) + 1.0;
    }

    if ((rtb_Integrator_idx_0 >= 0.0) && (rtb_Integrator_idx_0 <= 2.147483647E+9))
    {
      imo = static_cast<int32_T>(std::round(rtb_Integrator_idx_0));
      ic_quot_tmp = static_cast<int32_T>(imo - static_cast<int32_T>(3600 *
        div_s32(imo, 3600)));
      temp = std::trunc(static_cast<real_T>(imo) / 3600.0);
      a = std::trunc(static_cast<real_T>(ic_quot_tmp) / 60.0);
      rtb_Integrator_idx_0 = static_cast<real_T>(static_cast<int32_T>
        (ic_quot_tmp - static_cast<int32_T>(60 * div_s32(ic_quot_tmp, 60))));
    } else {
      temp = std::floor(rtb_Integrator_idx_0 / 3600.0);
      a = std::floor((rtb_Integrator_idx_0 - 3600.0 * temp) / 60.0);
      rtb_Integrator_idx_0 -= 60.0 * a;
    }

    b_shi = (da.re + da.im) + rtb_Integrator_idx_0;
    if (b_shi == 60.0) {
      b_shi = 59.999999999999993;
    }

    if ((thisData.re == (rtInf)) && (thisData.im == 0.0)) {
      rtb_Integrator_idx_1 = (rtInf);
    } else if ((thisData.re == (rtMinusInf)) && (thisData.im == 0.0)) {
      rtb_Integrator_idx_1 = (rtMinusInf);
    }

    rtb_Integrator_idx_0 = std::floor(b_shi);
    b_shi = std::round((b_shi - rtb_Integrator_idx_0) * 1000.0);

    // Receive: '<S1>/ReceiveThisMission'
    imo = codegenReal2Mission_ReceiveThisMission_RecvData
      (&codegenReal2Mission_B.ReceiveThisMission_o2);
    rtb_ReceiveCurrentMission_o1 = (imo != 1);

    // BusCreator: '<S1>/IndividualUAVCmd'
    rtb_IndividualUAVCmd.SequenceId =
      codegenReal2Mission_B.ReceiveThisMission_o2.SequenceId;
    rtb_IndividualUAVCmd.MissionMode =
      codegenReal2Mission_B.ReceiveThisMission_o2.MissionMode;
    rtb_IndividualUAVCmd.MissionLocation =
      codegenReal2Mission_B.ReceiveThisMission_o2.MissionLocation;
    rtb_IndividualUAVCmd.params =
      codegenReal2Mission_B.ReceiveThisMission_o2.params;
    rtb_IndividualUAVCmd.StartPosition =
      codegenReal2Mission_B.ReceiveThisMission_o2.StartPosition;
    rtb_IndividualUAVCmd.numUAV =
      codegenReal2Mission_B.ReceiveThisMission_o2.numUAV;
    rtb_IndividualUAVCmd.FormationPos =
      codegenReal2Mission_B.ReceiveThisMission_o2.FormationPos;

    // DataTypeConversion: '<S1>/year' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    if (std::isnan(rtb_Integrator_idx_1) || std::isinf(rtb_Integrator_idx_1)) {
      rtb_Integrator_idx_1 = 0.0;
    } else {
      rtb_Integrator_idx_1 = std::fmod(rtb_Integrator_idx_1, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/year'

    rtb_IndividualUAVCmd.StartTime.year = rtb_Integrator_idx_1 < 0.0 ?
      static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
      (-rtb_Integrator_idx_1))) : static_cast<int32_T>(static_cast<uint32_T>
      (rtb_Integrator_idx_1));

    // DataTypeConversion: '<S1>/month' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    if (std::isnan(fracSecs) || std::isinf(fracSecs)) {
      rtb_Integrator_idx_1 = 0.0;
    } else {
      rtb_Integrator_idx_1 = std::fmod(fracSecs, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/month'

    rtb_IndividualUAVCmd.StartTime.month = rtb_Integrator_idx_1 < 0.0 ?
      static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
      (-rtb_Integrator_idx_1))) : static_cast<int32_T>(static_cast<uint32_T>
      (rtb_Integrator_idx_1));

    // DataTypeConversion: '<S1>/day' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    rtb_Integrator_idx_1 = std::floor(second);
    if (std::isnan(rtb_Integrator_idx_1) || std::isinf(rtb_Integrator_idx_1)) {
      rtb_Integrator_idx_1 = 0.0;
    } else {
      rtb_Integrator_idx_1 = std::fmod(rtb_Integrator_idx_1, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/day'

    rtb_IndividualUAVCmd.StartTime.day = rtb_Integrator_idx_1 < 0.0 ?
      static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
      (-rtb_Integrator_idx_1))) : static_cast<int32_T>(static_cast<uint32_T>
      (rtb_Integrator_idx_1));

    // DataTypeConversion: '<S1>/hour' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    if (std::isnan(temp) || std::isinf(temp)) {
      rtb_Integrator_idx_1 = 0.0;
    } else {
      rtb_Integrator_idx_1 = std::fmod(temp, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/hour'

    rtb_IndividualUAVCmd.StartTime.hour = rtb_Integrator_idx_1 < 0.0 ?
      static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
      (-rtb_Integrator_idx_1))) : static_cast<int32_T>(static_cast<uint32_T>
      (rtb_Integrator_idx_1));

    // DataTypeConversion: '<S1>/minute' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    if (std::isnan(a) || std::isinf(a)) {
      rtb_Integrator_idx_1 = 0.0;
    } else {
      rtb_Integrator_idx_1 = std::fmod(a, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/minute'

    rtb_IndividualUAVCmd.StartTime.minute = rtb_Integrator_idx_1 < 0.0 ?
      static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
      (-rtb_Integrator_idx_1))) : static_cast<int32_T>(static_cast<uint32_T>
      (rtb_Integrator_idx_1));

    // DataTypeConversion: '<S1>/second'
    if (std::isnan(rtb_Integrator_idx_0) || std::isinf(rtb_Integrator_idx_0)) {
      rtb_Integrator_idx_1 = 0.0;
    } else {
      rtb_Integrator_idx_1 = std::fmod(rtb_Integrator_idx_0, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/second'

    rtb_IndividualUAVCmd.StartTime.second = rtb_Integrator_idx_1 < 0.0 ?
      static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
      (-rtb_Integrator_idx_1))) : static_cast<int32_T>(static_cast<uint32_T>
      (rtb_Integrator_idx_1));

    // DataTypeConversion: '<S1>/millisecond'
    if (std::isnan(b_shi) || std::isinf(b_shi)) {
      rtb_Integrator_idx_1 = 0.0;
    } else {
      rtb_Integrator_idx_1 = std::fmod(b_shi, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/millisecond'

    rtb_IndividualUAVCmd.StartTime.millisecond = rtb_Integrator_idx_1 < 0.0 ?
      static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
      (-rtb_Integrator_idx_1))) : static_cast<int32_T>(static_cast<uint32_T>
      (rtb_Integrator_idx_1));

    // Outputs for Triggered SubSystem: '<S1>/TriggerCurrentMisisonFeedback' incorporates:
    //   TriggerPort: '<S6>/Trigger'

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      if (rtb_ReceiveCurrentMission_o1 && (static_cast<int32_T>
           (codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE)
           != 1)) {
        // Send: '<S6>/Send'
        CurrentMissionSendData.SendData(&rtb_IndividualUAVCmd, sizeof
          (IndividualUAVCmd), &status);
      }

      codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
        static_cast<ZCSigState>(rtb_ReceiveCurrentMission_o1);
    }

    // End of Outputs for SubSystem: '<S1>/TriggerCurrentMisisonFeedback'

    // RateTransition: '<Root>/NonDeterministic' incorporates:
    //   DataStoreRead: '<Root>/ReadClock'

    codegenReal2Mission_DW.NonDeterministic_Buffer0 =
      codegenReal2Mission_DW.Clock;
  }

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // Matfile logging
    rt_UpdateTXYLogVars((&codegenReal2Mission_M)->rtwLogInfo,
                        ((&codegenReal2Mission_M)->Timing.t));
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      // Update for Memory: '<S2>/MemoryCurrentMission'
      codegenReal2Mission_DW.MemoryCurrentMission_PreviousInput =
        codegenReal2Mission_B.ReceiveCurrentMission_o2;

      // Update for Memory: '<S2>/MemoryPrevMissionLocation'
      codegenReal2Mission_DW.MemoryPrevMissionLocation_PreviousInput =
        codegenReal2Mission_B.MemoryCurrentMission.MissionLocation;

      // Update for Memory: '<S2>/DelayPose'
      codegenReal2Mission_DW.DelayPose_PreviousInput[0] =
        codegenReal2Mission_B.North;
      codegenReal2Mission_DW.DelayPose_PreviousInput[1] =
        codegenReal2Mission_B.East;
      codegenReal2Mission_DW.DelayPose_PreviousInput[2] = rtb_Down;
      codegenReal2Mission_DW.DelayPose_PreviousInput[3] =
        codegenReal2Mission_B.HeadingAngle;
    }

    // Update for Enabled SubSystem: '<S2>/MissionSimUAV' incorporates:
    //   EnablePort: '<S13>/Enable'

    if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
      // Update for ModelReference generated from: '<S13>/MissionUavModel'
      MissionUAV_Update
        (&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw));
    }

    // End of Update for SubSystem: '<S2>/MissionSimUAV'

    // Update for ModelReference generated from: '<Root>/Real2SimGuidance' incorporates:
    //   Inport: '<Root>/Altitude'
    //   Inport: '<Root>/FlightMode'
    //   Inport: '<Root>/GroundSpeed'
    //   Inport: '<Root>/RealUAVLatLonState'
    //   Inport: '<Root>/VectorSpd'
    //   Outport: '<Root>/EngagedFlag'
    //   Outport: '<Root>/LookAheadPoint'
    //   Outport: '<Root>/RefAirspeed'

    Real2SimGuidance_Update
      (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
       &codegenReal2Mission_B.ExecutionTrigger,
       &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtb),
       &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw));
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
    // signal main to stop simulation
    {                                  // Sample time: [0.0s, 0.0s]
      if ((rtmGetTFinal((&codegenReal2Mission_M))!=-1) &&
          !((rtmGetTFinal((&codegenReal2Mission_M))-(((&codegenReal2Mission_M)
              ->Timing.clockTick1) * 0.1)) > (((&codegenReal2Mission_M)
             ->Timing.clockTick1) * 0.1) * (DBL_EPSILON))) {
        rtmSetErrorStatus((&codegenReal2Mission_M), "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&(&codegenReal2Mission_M)->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++(&codegenReal2Mission_M)->Timing.clockTick0;
    (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&codegenReal2Mission_M)->solverInfo);

    {
      // Update absolute timer for sample time: [0.1s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.1, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      (&codegenReal2Mission_M)->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void codegenReal2MissionModelClass::codegenReal2Mission_derivatives()
{
  codegenReal2MissionModelClass::XDot_codegenReal2Mission_T *_rtXdot;
  _rtXdot = ((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs);

  // Derivatives for Integrator: '<S2>/Integrator'
  if (codegenReal2Mission_B.PreemptableMissionModeSelector_o3 == 0.0) {
    _rtXdot->Integrator_CSTATE[0] =
      codegenReal2Mission_B.PreemptableMissionModeSelector_o5[0];
    _rtXdot->Integrator_CSTATE[1] =
      codegenReal2Mission_B.PreemptableMissionModeSelector_o5[1];
  } else {
    // level reset is active
    _rtXdot->Integrator_CSTATE[0] = 0.0;
    _rtXdot->Integrator_CSTATE[1] = 0.0;
  }

  // End of Derivatives for Integrator: '<S2>/Integrator'

  // Derivatives for Enabled SubSystem: '<S2>/MissionSimUAV'
  if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
    // Derivatives for ModelReference generated from: '<S13>/MissionUavModel'
    MissionUAV_Deriv(&codegenReal2Mission_B.PreemptableMissionModeSelector_o3,
                     &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtb),
                     &(((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M
                        )->derivs)->MissionUavModel_CSTATE));
  } else {
    {
      real_T *dx;
      int_T i;
      dx = (real_T *) &(((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M
                         )->derivs)->MissionUavModel_CSTATE);
      for (i=0; i < 10; i++) {
        dx[i] = 0.0;
      }
    }
  }

  // End of Derivatives for SubSystem: '<S2>/MissionSimUAV'

  // Derivatives for ModelReference generated from: '<Root>/Real2SimGuidance' incorporates:
  //   Inport: '<Root>/Altitude'
  //   Inport: '<Root>/FlightMode'
  //   Inport: '<Root>/GroundSpeed'
  //   Inport: '<Root>/RealUAVLatLonState'
  //   Inport: '<Root>/VectorSpd'
  //   Outport: '<Root>/EngagedFlag'
  //   Outport: '<Root>/LookAheadPoint'
  //   Outport: '<Root>/RefAirspeed'

  Real2SimGuidance_Deriv
    (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtb),
     &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
     &(((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs)
       ->Real2SimGuidance_CSTATE));
}

// Model step function
void codegenReal2MissionModelClass::codegenReal2Mission_PushNewMission() // Explicit Task: PushNewMission 
{
  missionCmd rtb_SndCMD;
  creal_T thisData;
  real_T c_tm_year[7];
  real_T processedInData[7];
  real_T NewCMD_StartTime_tmp;
  real_T NonDeterministic;
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
  real_T c_s;
  int32_T D;
  int32_T H;
  int32_T M;
  int32_T MI;
  int32_T MS;
  int32_T NewCMD_FormationPos;
  int32_T NewCMD_MissionMode;
  int32_T NewCMD_SequenceId;
  int32_T NewCMD_numUAV;
  int32_T S;
  int32_T Y{ 1 };

  boolean_T expl_temp;

  // RateTransition: '<Root>/NonDeterministic'
  NonDeterministic = codegenReal2Mission_DW.NonDeterministic_Buffer0;

  // RootInportFunctionCallGenerator generated from: '<Root>/PushNewMission' incorporates:
  //   SubSystem: '<Root>/MissionValidation'

  // Receive: '<S3>/ReceivePushedMissionCMD'
  Y = 1;
  MissionCMDRecvData.RecvData(&codegenReal2Mission_B.ReceivePushedMissionCMD,
    sizeof(IndividualUAVCmd), &Y);

  // MATLAB Function: '<S3>/CommandCheck' incorporates:
  //   DataStoreRead: '<S3>/ReadPreviousCMD'

  rtb_SndCMD = codegenReal2Mission_DW.missionCmd_k;
  Y = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.year;
  M = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.month;
  D = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.day;
  H = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.hour;
  MI = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.minute;
  S = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.second;
  MS = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.millisecond;
  processedInData[0] = static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.year);
  processedInData[1] = static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.month);
  processedInData[2] = static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.day);
  processedInData[3] = static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.hour);
  processedInData[4] = static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.minute);
  processedInData[5] = static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.second);
  processedInData[6] = static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.millisecond);
  NewCMD_SequenceId = codegenReal2Mission_B.ReceivePushedMissionCMD.SequenceId;
  NewCMD_MissionMode = codegenReal2Mission_B.ReceivePushedMissionCMD.MissionMode;
  NewCMD_numUAV = codegenReal2Mission_B.ReceivePushedMissionCMD.numUAV;
  NewCMD_FormationPos =
    codegenReal2Mission_B.ReceivePushedMissionCMD.FormationPos;
  NewCMD_StartTime_tmp = (codegenReal2Mission_createFromDateVec(processedInData))
    .re / 1000.0;
  if (!codegenReal2Mission_isequaln
      (codegenReal2Mission_DW.missionCmd_k.SequenceId,
       codegenReal2Mission_DW.missionCmd_k.MissionMode,
       codegenReal2Mission_DW.missionCmd_k.MissionLocation.Lat,
       codegenReal2Mission_DW.missionCmd_k.MissionLocation.Lon,
       codegenReal2Mission_DW.missionCmd_k.MissionLocation.Alt,
       codegenReal2Mission_DW.missionCmd_k.MissionLocation.degHDG,
       codegenReal2Mission_DW.missionCmd_k.params.Param1,
       codegenReal2Mission_DW.missionCmd_k.params.Param2,
       codegenReal2Mission_DW.missionCmd_k.params.Param3,
       codegenReal2Mission_DW.missionCmd_k.params.Param4,
       codegenReal2Mission_DW.missionCmd_k.params.Param5,
       codegenReal2Mission_DW.missionCmd_k.params.Param6,
       codegenReal2Mission_DW.missionCmd_k.params.Param7,
       codegenReal2Mission_DW.missionCmd_k.StartPosition,
       codegenReal2Mission_DW.missionCmd_k.numUAV,
       codegenReal2Mission_DW.missionCmd_k.FormationPos,
       codegenReal2Mission_DW.missionCmd_k.StartTime, NewCMD_SequenceId,
       NewCMD_MissionMode,
       codegenReal2Mission_B.ReceivePushedMissionCMD.MissionLocation,
       codegenReal2Mission_B.ReceivePushedMissionCMD.params,
       codegenReal2Mission_B.ReceivePushedMissionCMD.StartPosition,
       NewCMD_numUAV, NewCMD_FormationPos, NewCMD_StartTime_tmp)) {
    if (codegenReal2Mission_DW.missionCmd_k.SequenceId ==
        codegenReal2Mission_B.ReceivePushedMissionCMD.SequenceId) {
      printf("Use a new Sequence ID for each new mission!\n");
      fflush(stdout);
      printf("PrevCMD SequenceID: %d\n",
             codegenReal2Mission_DW.missionCmd_k.SequenceId);
      fflush(stdout);
      printf("NewCMD SequenceID: %d\n", NewCMD_SequenceId);
      fflush(stdout);
    } else {
      if (NonDeterministic > NewCMD_StartTime_tmp) {
        printf("Mission Start Time has already passed!\n");
        fflush(stdout);
      } else {
        codegenReal2Mission_DW.missionCmd_k.SequenceId = NewCMD_SequenceId;
        codegenReal2Mission_DW.missionCmd_k.MissionMode = NewCMD_MissionMode;
        codegenReal2Mission_DW.missionCmd_k.MissionLocation =
          codegenReal2Mission_B.ReceivePushedMissionCMD.MissionLocation;
        codegenReal2Mission_DW.missionCmd_k.params =
          codegenReal2Mission_B.ReceivePushedMissionCMD.params;
        codegenReal2Mission_DW.missionCmd_k.StartPosition =
          codegenReal2Mission_B.ReceivePushedMissionCMD.StartPosition;
        codegenReal2Mission_DW.missionCmd_k.numUAV = NewCMD_numUAV;
        codegenReal2Mission_DW.missionCmd_k.FormationPos = NewCMD_FormationPos;
        codegenReal2Mission_DW.missionCmd_k.StartTime = NewCMD_StartTime_tmp;
        rtb_SndCMD.SequenceId = NewCMD_SequenceId;
        rtb_SndCMD.MissionMode = NewCMD_MissionMode;
        rtb_SndCMD.MissionLocation =
          codegenReal2Mission_B.ReceivePushedMissionCMD.MissionLocation;
        rtb_SndCMD.params = codegenReal2Mission_B.ReceivePushedMissionCMD.params;
        rtb_SndCMD.StartPosition =
          codegenReal2Mission_B.ReceivePushedMissionCMD.StartPosition;
        rtb_SndCMD.numUAV = NewCMD_numUAV;
        rtb_SndCMD.FormationPos = NewCMD_FormationPos;
        rtb_SndCMD.StartTime = NewCMD_StartTime_tmp;
      }

      printf("Start Time:   %04d-%02d-%02d %02d:%02d:%02d.%03d\n", Y, M, D, H,
             MI, S, MS);
      fflush(stdout);
      codegenReal2Mission_getLocalTime(&NonDeterministic, &c_tm_year[5],
        &c_tm_year[4], &c_tm_year[3], &c_tm_year[2], &c_tm_year[1], &c_tm_year[0],
        &expl_temp);
      c_tm_year[6] = NonDeterministic / 1.0E+6;
      thisData = codegenReal2Mission_createFromDateVec(c_tm_year);
      codegenReal2Mission_getDateVec(thisData, &NonDeterministic,
        &NewCMD_StartTime_tmp, &a__2, &a__3, &a__4, &a__5);
      codegenReal2Mission_getDateVec(thisData, &a__2, &NewCMD_StartTime_tmp,
        &a__3, &a__4, &a__5, &a__11);
      codegenReal2Mission_getDateVec(thisData, &a__3, &a__4, &a__2, &a__5,
        &a__11, &a__17);
      codegenReal2Mission_getDateVec(thisData, &a__4, &a__5, &a__11, &a__3,
        &a__17, &a__23);
      codegenReal2Mission_getDateVec(thisData, &a__5, &a__11, &a__17, &a__23,
        &a__4, &a__29);
      codegenReal2Mission_getDateVec(thisData, &a__11, &a__17, &a__23, &a__29,
        &a__35, &a__5);
      codegenReal2Mission_getDateVec(thisData, &a__17, &a__23, &a__29, &a__35,
        &b_a__35, &a__11);
      codegenReal2Mission_getDateVec(thisData, &a__17, &a__23, &a__29, &a__35,
        &b_a__35, &c_s);
      printf("Current Time: %04.0f-%02.0f-%02.0f %02.0f:%02.0f:%02.0f.%03.0f\n",
             NonDeterministic, NewCMD_StartTime_tmp, a__2, a__3, a__4, std::
             floor(a__5), std::round(1000.0 * (a__11 - std::floor(c_s))));
      fflush(stdout);
    }
  }

  // End of MATLAB Function: '<S3>/CommandCheck'

  // Send: '<S3>/SendPushedMissionCMD'
  codegenReal2Mission_ReceiveNextMission_SendData(&rtb_SndCMD);

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PushNewMission' 
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
      rtsiSetContStatesPtr(&(&codegenReal2Mission_M)->solverInfo, (real_T **) &(
        &codegenReal2Mission_M)->contStates);
      rtsiSetNumContStatesPtr(&(&codegenReal2Mission_M)->solverInfo,
        &(&codegenReal2Mission_M)->Sizes.numContStates);
      rtsiSetNumPeriodicContStatesPtr(&(&codegenReal2Mission_M)->solverInfo,
        &(&codegenReal2Mission_M)->Sizes.numPeriodicContStates);
      rtsiSetPeriodicContStateIndicesPtr(&(&codegenReal2Mission_M)->solverInfo,
        &(&codegenReal2Mission_M)->periodicContStateIndices);
      rtsiSetPeriodicContStateRangesPtr(&(&codegenReal2Mission_M)->solverInfo,
        &(&codegenReal2Mission_M)->periodicContStateRanges);
      rtsiSetErrorStatusPtr(&(&codegenReal2Mission_M)->solverInfo,
                            (&rtmGetErrorStatus((&codegenReal2Mission_M))));
      rtsiSetRTModelPtr(&(&codegenReal2Mission_M)->solverInfo,
                        (&codegenReal2Mission_M));
    }

    rtsiSetSimTimeStep(&(&codegenReal2Mission_M)->solverInfo, MAJOR_TIME_STEP);
    (&codegenReal2Mission_M)->intgData.y = (&codegenReal2Mission_M)->odeY;
    (&codegenReal2Mission_M)->intgData.f[0] = (&codegenReal2Mission_M)->odeF[0];
    (&codegenReal2Mission_M)->intgData.f[1] = (&codegenReal2Mission_M)->odeF[1];
    (&codegenReal2Mission_M)->intgData.f[2] = (&codegenReal2Mission_M)->odeF[2];
    (&codegenReal2Mission_M)->intgData.f[3] = (&codegenReal2Mission_M)->odeF[3];
    (&codegenReal2Mission_M)->contStates = ((X_codegenReal2Mission_T *)
      &codegenReal2Mission_X);
    rtsiSetSolverData(&(&codegenReal2Mission_M)->solverInfo, static_cast<void *>
                      (&(&codegenReal2Mission_M)->intgData));
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
      rtliSetLogVarNameModifier((&codegenReal2Mission_M)->rtwLogInfo, "rt_");
      rtliSetLogFormat((&codegenReal2Mission_M)->rtwLogInfo, 4);
      rtliSetLogMaxRows((&codegenReal2Mission_M)->rtwLogInfo, 0);
      rtliSetLogDecimation((&codegenReal2Mission_M)->rtwLogInfo, 1);
      rtliSetLogY((&codegenReal2Mission_M)->rtwLogInfo, "");
      rtliSetLogYSignalInfo((&codegenReal2Mission_M)->rtwLogInfo, (nullptr));
      rtliSetLogYSignalPtrs((&codegenReal2Mission_M)->rtwLogInfo, (nullptr));
    }
  }

  {
    static uint32_T *clockTickPtrs[4];
    static real_T *taskTimePtrs[4];
    (&codegenReal2Mission_M)->timingBridge.nTasks = 4;
    clockTickPtrs[0] = &((&codegenReal2Mission_M)->Timing.clockTick0);
    clockTickPtrs[1] = &((&codegenReal2Mission_M)->Timing.clockTick1);
    clockTickPtrs[2] = (nullptr);
    clockTickPtrs[3] = (nullptr);
    (&codegenReal2Mission_M)->timingBridge.clockTick = clockTickPtrs;
    (&codegenReal2Mission_M)->timingBridge.clockTickH = (nullptr);
    taskTimePtrs[0] = &((&codegenReal2Mission_M)->Timing.t[0]);
    taskTimePtrs[1] = (nullptr);
    taskTimePtrs[2] = (nullptr);
    taskTimePtrs[3] = (nullptr);
    (&codegenReal2Mission_M)->timingBridge.taskTime = taskTimePtrs;
    (&codegenReal2Mission_M)->timingBridge.firstInitCond = &rtmIsFirstInitCond((
      &codegenReal2Mission_M));
  }

  // Model Initialize function for ModelReference Block: '<S2>/PreemptableMissionModeSelector' 
  PreemptableMissionModeSelector_initialize(rtmGetErrorStatusPointer
    ((&codegenReal2Mission_M)),
    &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtm),
    &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtzce));

  // Model Initialize function for ModelReference Block: '<S13>/MissionUavModel' 
  MissionUAV_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                        rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
                        &((&codegenReal2Mission_M)->solverInfo),
                        &(&codegenReal2Mission_M)->timingBridge,
                        &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
                        &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtzce));

  // Model Initialize function for ModelReference Block: '<Root>/Real2SimGuidance' 
  Real2SimGuidance_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
    rtmGetStopRequestedPtr((&codegenReal2Mission_M)), &((&codegenReal2Mission_M
    )->solverInfo), &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm));

  // Matfile logging
  rt_StartDataLoggingWithStartTime((&codegenReal2Mission_M)->rtwLogInfo, 0.0,
    rtmGetTFinal((&codegenReal2Mission_M)), (&codegenReal2Mission_M)
    ->Timing.stepSize0, (&rtmGetErrorStatus((&codegenReal2Mission_M))));

  // Start for slMsgMgr: '<Root>/slMsgMgr'
  codegenReal2Mission_initMemPool
    (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd,
     &codegenReal2Mission_DW.slMsgMgr_memArray_missionCmd[0],
     &codegenReal2Mission_DW.slMsgMgr_freeList_missionCmd[0], 6);
  codegenReal2Mission_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE = POS_ZCSIG;
  codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE = POS_ZCSIG;
  codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE =
    UNINITIALIZED_ZCSIG;

  // InitializeConditions for Integrator: '<S2>/Integrator'
  codegenReal2Mission_X.Integrator_CSTATE[0] = 0.0;
  codegenReal2Mission_X.Integrator_CSTATE[1] = 0.0;

  // SystemInitialize for ModelReference: '<S2>/PreemptableMissionModeSelector' incorporates:
  //   Outport: '<Root>/thisTaskStatus'

  PreemptableMissionModeSelector_Init
    (&codegenReal2Mission_B.PreemptableMissionModeSelector_o2,
     &codegenReal2Mission_B.PreemptableMissionModeSelector_o4[0],
     &codegenReal2Mission_B.PreemptableMissionModeSelector_o5[0],
     &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));

  // SystemInitialize for Enabled SubSystem: '<S2>/MissionSimUAV'

  // SystemInitialize for ModelReference generated from: '<S13>/MissionUavModel' 
  MissionUAV_Init(&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
                  &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw),
                  &(codegenReal2Mission_X.MissionUavModel_CSTATE));

  // End of SystemInitialize for SubSystem: '<S2>/MissionSimUAV'

  // SystemInitialize for ModelReference generated from: '<Root>/Real2SimGuidance' incorporates:
  //   Inport: '<Root>/Altitude'
  //   Inport: '<Root>/FlightMode'
  //   Inport: '<Root>/GroundSpeed'
  //   Inport: '<Root>/RealUAVLatLonState'
  //   Inport: '<Root>/VectorSpd'
  //   Outport: '<Root>/EngagedFlag'
  //   Outport: '<Root>/LookAheadPoint'
  //   Outport: '<Root>/RefAirspeed'

  Real2SimGuidance_Init
    (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
     &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));

  // Outputs for Atomic SubSystem: '<S2>/InitializeSimLocation'
  // DataStoreWrite: '<S11>/DSAltitudeGCS' incorporates:
  //   Constant: '<S11>/AltitudeGCS'

  AltitudeGCS = GCS_Altitude;

  // DataStoreWrite: '<S11>/DSLatitudeGCS' incorporates:
  //   Constant: '<S11>/LatitudeGCS'

  LatitudeGCS = GCS_Latitude;

  // DataStoreWrite: '<S11>/DSLongitudeGCS' incorporates:
  //   Constant: '<S11>/LongitudeGCS'

  LongitudeGCS = GCS_Longitude;

  // End of Outputs for SubSystem: '<S2>/InitializeSimLocation'

  // set "at time zero" to false
  if (rtmIsFirstInitCond((&codegenReal2Mission_M))) {
    rtmSetFirstInitCond((&codegenReal2Mission_M), 0);
  }
}

// Model terminate function
void codegenReal2MissionModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
codegenReal2MissionModelClass::codegenReal2MissionModelClass
  (SendData_IndividualUAVCmdT& CurrentMissionSendData_arg,
   RecvData_IndividualUAVCmdT& MissionCMDRecvData_arg) :
  codegenReal2Mission_B(),
  codegenReal2Mission_DW(),
  codegenReal2Mission_X(),
  codegenReal2Mission_PrevZCX(),
  codegenReal2Mission_U(),
  codegenReal2Mission_Y(),
  codegenReal2Mission_M(),
  CurrentMissionSendData(CurrentMissionSendData_arg),
  MissionCMDRecvData(MissionCMDRecvData_arg)
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
