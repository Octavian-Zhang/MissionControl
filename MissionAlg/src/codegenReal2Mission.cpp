//
// File: codegenReal2Mission.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.374
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 26 14:14:32 2021
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
#include "floor_jeUa7tf2.h"
#include "mod_dBqh4Vat.h"
#include "plus_aAYNoTqG.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf.h"
#include "rt_remd_snf.h"
#include "skip_to_last_equal_value_ZlLNIyBv.h"
#include "split_MzIWb6Db.h"
#include "wrapToPi_iEuDNbvh.h"

// Named constants for Chart: '<S2>/MisisonCMDTemporalLogic'
const uint8_T codegenReal2Mission_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T codegenReal2Mission_IN_Pending{ 1U };

const uint8_T codegenReal2Mission_IN_Sending{ 2U };

// Named constants for Chart: '<S2>/PreemptableMissionModeSelector'
const uint8_T codegenReal2Mission_IN_CircleDisplayNav{ 1U };

const uint8_T codegenReal2Mission_IN_CirclingNav{ 2U };

const uint8_T codegenReal2Mission_IN_CustomFormationNav{ 1U };

const uint8_T codegenReal2Mission_IN_HorizontalFormationNav{ 2U };

const uint8_T codegenReal2Mission_IN_OrbitFollower{ 1U };

const uint8_T codegenReal2Mission_IN_RunWayNav{ 2U };

const uint8_T codegenReal2Mission_IN_WaitToStart{ 3U };

const uint8_T codegenReal2Mission_IN_WaypointFollower{ 4U };

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
  memPool->fNumFree++;
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
  *t_tm_sec = structTm.tm_sec;
  *t_tm_min = structTm.tm_min;
  *t_tm_hour = structTm.tm_hour;
  *t_tm_mday = structTm.tm_mday;
  *t_tm_mon = structTm.tm_mon;
  *t_tm_year = structTm.tm_year;
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

  if (0 <= trueCount - 1) {
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
    memPool->fNumFree--;
    dataPtr = memPool->fFreeList[memPool->fNumFree];
  } else if (memPool->fNumUsed < memPool->fSize) {
    dataPtr = &memPool->fMemArray[memPool->fNumUsed];
    memPool->fNumUsed += width;
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
  //   Send: '<S16>/SendMission'

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

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_real_T
  (emxArray_real_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_codegenReal2Mission_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_codegenReal2Mission_T *)std::malloc(sizeof
    (emxArray_real_T_codegenReal2Mission_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
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
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
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
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(real_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
matlabshared_autonomous_core_internal_NameValueParser_codegenReal2Mission_T
  *codegenReal2MissionModelClass::
  codegenReal2Mission_NameValueParser_NameValueParser
  (matlabshared_autonomous_core_internal_NameValueParser_codegenReal2Mission_T
   *obj)
{
  static const char_T c[7]{ 'o', 'p', 't', 'i', 'm', 'a', 'l' };

  cell_wrap_12_codegenReal2Mission_T b;
  matlabshared_autonomous_core_internal_NameValueParser_codegenReal2Mission_T
    *b_obj;
  int32_T i;
  b_obj = obj;
  for (i = 0; i < 7; i++) {
    b.f1[i] = c[i];
  }

  obj->Defaults = b;
  return b_obj;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_validatestring(const
  char_T str[7], char_T out_data[], int32_T out_size[2])
{
  static const char_T c[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~', '\x7f' };

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
      if (c[static_cast<uint8_T>(str[kstr]) & 127] != c[static_cast<int32_T>
          (d[kstr])]) {
        exitg1 = 1;
      } else {
        kstr++;
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

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp(const char_T
  a_data[], const int32_T a_size[2])
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
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_merge(int32_T idx_data[],
  int32_T x_data[], int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[],
  int32_T xwork_data[])
{
  int32_T exitg1;
  int32_T iout;
  int32_T offset1;
  int32_T p;
  int32_T q;
  if (nq != 0) {
    offset1 = np + nq;
    for (p = 0; p < offset1; p++) {
      q = offset + p;
      iwork_data[p] = idx_data[q];
      xwork_data[p] = x_data[q];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          while (p + 1 <= np) {
            q = (offset1 + p) + 1;
            idx_data[q] = iwork_data[p];
            x_data[q] = xwork_data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_sort(int32_T x_data[],
  const int32_T *x_size, int32_T idx_data[], int32_T *idx_size)
{
  int32_T b_idx_data[28];
  int32_T b_x_data[28];
  int32_T iwork_data[28];
  int32_T vwork_data[28];
  int32_T x4[4];
  int32_T b;
  int32_T dim;
  int32_T i1;
  int32_T i2;
  int32_T i4;
  int32_T nDone;
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
    b = *x_size - 1;
  } else {
    b = 0;
  }

  vwork_size_idx_0 = b + 1;
  *idx_size = *x_size;
  vstride = 1;
  nDone = 0;
  while (nDone <= dim - 2) {
    vstride *= *x_size;
    nDone = 1;
  }

  for (dim = 0; dim < vstride; dim++) {
    for (nDone = 0; nDone <= b; nDone++) {
      vwork_data[nDone] = x_data[nDone * vstride + dim];
    }

    if (0 <= static_cast<int8_T>(vwork_size_idx_0) - 1) {
      std::memset(&b_idx_data[0], 0, static_cast<int8_T>(vwork_size_idx_0) *
                  sizeof(int32_T));
    }

    if (vwork_size_idx_0 != 0) {
      if (0 <= vwork_size_idx_0 - 1) {
        std::memcpy(&b_x_data[0], &vwork_data[0], vwork_size_idx_0 * sizeof
                    (int32_T));
      }

      x4[0] = 0;
      idx4[0] = 0;
      x4[1] = 0;
      idx4[1] = 0;
      x4[2] = 0;
      idx4[2] = 0;
      x4[3] = 0;
      idx4[3] = 0;
      nQuartets_tmp = vwork_size_idx_0 >> 2;
      for (tailOffset = 0; tailOffset < nQuartets_tmp; tailOffset++) {
        nTail = tailOffset << 2;
        idx4[0] = static_cast<int8_T>(nTail + 1);
        idx4[1] = static_cast<int8_T>(nTail + 2);
        idx4[2] = static_cast<int8_T>(nTail + 3);
        idx4[3] = static_cast<int8_T>(nTail + 4);
        x4[0] = b_x_data[nTail];
        i1 = b_x_data[nTail + 1];
        x4[1] = i1;
        nDone = b_x_data[nTail + 2];
        x4[2] = nDone;
        nQuartets = b_x_data[nTail + 3];
        x4[3] = nQuartets;
        if (b_x_data[nTail] <= i1) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (nDone <= nQuartets) {
          nQuartets = 3;
          i4 = 4;
        } else {
          nQuartets = 4;
          i4 = 3;
        }

        nDone = x4[i1 - 1];
        tmp = x4[nQuartets - 1];
        if (nDone <= tmp) {
          nDone = x4[i2 - 1];
          if (nDone <= tmp) {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(i2);
            perm[2] = static_cast<int8_T>(nQuartets);
            perm[3] = static_cast<int8_T>(i4);
          } else if (nDone <= x4[i4 - 1]) {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(nQuartets);
            perm[2] = static_cast<int8_T>(i2);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(nQuartets);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(i2);
          }
        } else {
          tmp = x4[i4 - 1];
          if (nDone <= tmp) {
            if (x4[i2 - 1] <= tmp) {
              perm[0] = static_cast<int8_T>(nQuartets);
              perm[1] = static_cast<int8_T>(i1);
              perm[2] = static_cast<int8_T>(i2);
              perm[3] = static_cast<int8_T>(i4);
            } else {
              perm[0] = static_cast<int8_T>(nQuartets);
              perm[1] = static_cast<int8_T>(i1);
              perm[2] = static_cast<int8_T>(i4);
              perm[3] = static_cast<int8_T>(i2);
            }
          } else {
            perm[0] = static_cast<int8_T>(nQuartets);
            perm[1] = static_cast<int8_T>(i4);
            perm[2] = static_cast<int8_T>(i1);
            perm[3] = static_cast<int8_T>(i2);
          }
        }

        b_idx_data[nTail] = idx4[perm[0] - 1];
        b_idx_data[nTail + 1] = idx4[perm[1] - 1];
        b_idx_data[nTail + 2] = idx4[perm[2] - 1];
        b_idx_data[nTail + 3] = idx4[perm[3] - 1];
        b_x_data[nTail] = x4[perm[0] - 1];
        b_x_data[nTail + 1] = x4[perm[1] - 1];
        b_x_data[nTail + 2] = x4[perm[2] - 1];
        b_x_data[nTail + 3] = x4[perm[3] - 1];
      }

      nDone = nQuartets_tmp << 2;
      nQuartets = vwork_size_idx_0 - nDone;
      if (nQuartets > 0) {
        for (tailOffset = 0; tailOffset < nQuartets; tailOffset++) {
          nTail = nDone + tailOffset;
          idx4[tailOffset] = static_cast<int8_T>(nTail + 1);
          x4[tailOffset] = b_x_data[nTail];
        }

        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        switch (nQuartets) {
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

        for (tailOffset = 0; tailOffset < nQuartets; tailOffset++) {
          nTail = perm[tailOffset] - 1;
          i1 = nDone + tailOffset;
          b_idx_data[i1] = idx4[nTail];
          b_x_data[i1] = x4[nTail];
        }
      }

      if (vwork_size_idx_0 > 1) {
        if (0 <= vwork_size_idx_0 - 1) {
          std::memset(&vwork_data[0], 0, vwork_size_idx_0 * sizeof(int32_T));
        }

        if (0 <= static_cast<int8_T>(vwork_size_idx_0) - 1) {
          std::memset(&iwork_data[0], 0, static_cast<int8_T>(vwork_size_idx_0) *
                      sizeof(int32_T));
        }

        nQuartets = nQuartets_tmp;
        nDone = 4;
        while (nQuartets > 1) {
          if ((nQuartets & 1U) != 0U) {
            nQuartets--;
            tailOffset = nDone * nQuartets;
            nTail = vwork_size_idx_0 - tailOffset;
            if (nTail > nDone) {
              codegenReal2Mission_merge(b_idx_data, b_x_data, tailOffset, nDone,
                nTail - nDone, iwork_data, vwork_data);
            }
          }

          tailOffset = nDone << 1;
          nQuartets >>= 1;
          for (nTail = 0; nTail < nQuartets; nTail++) {
            codegenReal2Mission_merge(b_idx_data, b_x_data, nTail * tailOffset,
              nDone, nDone, iwork_data, vwork_data);
          }

          nDone = tailOffset;
        }

        if (vwork_size_idx_0 > nDone) {
          codegenReal2Mission_merge(b_idx_data, b_x_data, 0, nDone,
            vwork_size_idx_0 - nDone, iwork_data, vwork_data);
        }
      }

      if (0 <= vwork_size_idx_0 - 1) {
        std::memcpy(&vwork_data[0], &b_x_data[0], vwork_size_idx_0 * sizeof
                    (int32_T));
      }
    }

    for (nQuartets = 0; nQuartets <= b; nQuartets++) {
      nDone = dim + nQuartets * vstride;
      x_data[nDone] = vwork_data[nQuartets];
      idx_data[nDone] = b_idx_data[nQuartets];
    }
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_do_vectors(real_T
  c_data[], int32_T c_size[2], int32_T ia_data[], int32_T *ia_size, int32_T
  *ib_size)
{
  static const real_T a[28]{ 6.384265086E+9, 6.384265284E+9, 6.384480708E+9,
    6.384480906E+9, 6.384473283E+9, 6.384263997E+9, 2.1067690282E+11,
    2.10676902826E+11, 2.10677124976E+11, 2.10677124982E+11, 2.10677124751E+11,
    2.10676902787E+11, 2.10680747748E+11, 2.10680754288E+11, 2.10687863274E+11,
    2.10687869814E+11, 2.10687618255E+11, 2.10680711811E+11, 6.384264226E+9,
    6.384264232E+9, 6.384264001E+9, 6.38447332E+9, 6.384473281E+9,
    6.384473314E+9, 6.384265282E+9, 6.384480904E+9, 6.38426509E+9,
    6.384480712E+9 };

  static const int32_T aperm[28]{ 6, 21, 19, 20, 1, 27, 25, 2, 23, 5, 24, 22, 3,
    28, 26, 4, 12, 7, 8, 11, 9, 10, 18, 13, 14, 17, 15, 16 };

  static const int8_T e[28]{ 6, 21, 19, 20, 1, 27, 25, 2, 23, 5, 24, 22, 3, 28,
    26, 4, 12, 7, 8, 11, 9, 10, 18, 13, 14, 17, 15, 16 };

  emxArray_int32_T_28_codegenReal2Mission_T ia_data_0;
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
    nc++;
    nia++;
    ia_data[nia] = e[iafirst];
    ialast = b_ialast + 1;
    iafirst = b_ialast;
  }

  if (1 > nia + 1) {
    iafirst = -1;
  } else {
    iafirst = nia;
  }

  *ia_size = iafirst + 1;
  codegenReal2Mission_sort(ia_data, ia_size, ia_data_0.data, &ia_data_0.size);
  for (iafirst = 0; iafirst <= nia; iafirst++) {
    c_data[iafirst] = a[ia_data[iafirst] - 1];
  }

  if (1 > nc) {
    c_size[1] = 0;
  } else {
    c_size[1] = nc;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_do_vectors_o(const
  real_T b_data[], const int32_T *b_size, real_T c_data[], int32_T c_size[2],
  int32_T ia_data[], int32_T *ia_size, int32_T *ib_size)
{
  emxArray_int32_T_28_codegenReal2Mission_T ia_data_0;
  real_T tmp[28];
  real_T ak;
  real_T b_absx;
  real_T bk;
  int32_T bperm_data[28];
  int32_T iwork_data[28];
  int32_T b_k;
  int32_T c_k;
  int32_T exponent;
  int32_T i;
  int32_T i2;
  int32_T ialast;
  int32_T ialast_tmp;
  int32_T j;
  int32_T kEnd;
  int32_T n;
  int32_T q;
  int32_T qEnd;
  int32_T tmp_0;
  boolean_T exitg1;
  c_size[0] = 1;
  *ib_size = 0;
  if (0 <= static_cast<int8_T>(*b_size) - 1) {
    std::memset(&bperm_data[0], 0, static_cast<int8_T>(*b_size) * sizeof(int32_T));
  }

  if (*b_size != 0) {
    for (ialast = 1; ialast <= (*b_size + 1) - 2; ialast += 2) {
      if (b_data[ialast - 1] <= b_data[ialast]) {
        bperm_data[ialast - 1] = ialast;
        bperm_data[ialast] = ialast + 1;
      } else {
        bperm_data[ialast - 1] = ialast + 1;
        bperm_data[ialast] = ialast;
      }
    }

    if ((*b_size & 1U) != 0U) {
      bperm_data[*b_size - 1] = *b_size;
    }

    i = 2;
    while (i < (*b_size + 1) - 1) {
      i2 = i << 1;
      j = 1;
      ialast = i + 1;
      while (ialast < *b_size + 1) {
        n = j;
        q = ialast;
        qEnd = j + i2;
        if (qEnd > *b_size + 1) {
          qEnd = *b_size + 1;
        }

        c_k = 0;
        kEnd = qEnd - j;
        while (c_k + 1 <= kEnd) {
          ialast_tmp = bperm_data[q - 1];
          tmp_0 = bperm_data[n - 1];
          if (b_data[tmp_0 - 1] <= b_data[ialast_tmp - 1]) {
            iwork_data[c_k] = tmp_0;
            n++;
            if (n == ialast) {
              while (q < qEnd) {
                c_k++;
                iwork_data[c_k] = bperm_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[c_k] = ialast_tmp;
            q++;
            if (q == qEnd) {
              while (n < ialast) {
                c_k++;
                iwork_data[c_k] = bperm_data[n - 1];
                n++;
              }
            }
          }

          c_k++;
        }

        for (ialast = 0; ialast < kEnd; ialast++) {
          bperm_data[(j + ialast) - 1] = iwork_data[ialast];
        }

        j = qEnd;
        ialast = qEnd + i;
      }

      i = i2;
    }
  }

  n = 0;
  i = -1;
  i2 = 0;
  ialast = 1;
  j = 1;
  while ((ialast <= 28) && (j <= *b_size)) {
    qEnd = ialast;
    for (ialast = 0; ialast < 28; ialast++) {
      tmp[ialast] = static_cast<real_T>(ialast) + 1.0;
      iwork_data[ialast] = ialast + 1;
    }

    ak = skip_to_last_equal_value_ZlLNIyBv(&qEnd, tmp, iwork_data);
    ialast = qEnd;
    bk = b_data[bperm_data[j - 1] - 1];
    exitg1 = false;
    while ((!exitg1) && (j < *b_size)) {
      b_absx = std::abs(bk / 2.0);
      if (b_absx <= 2.2250738585072014E-308) {
        b_absx = 4.94065645841247E-324;
      } else {
        frexp(b_absx, &b_k);
        b_absx = std::ldexp(1.0, b_k - 53);
      }

      if (std::abs(bk - b_data[bperm_data[j] - 1]) < b_absx) {
        j++;
      } else {
        exitg1 = true;
      }
    }

    b_absx = std::abs(bk / 2.0);
    if (b_absx <= 2.2250738585072014E-308) {
      b_absx = 4.94065645841247E-324;
    } else {
      frexp(b_absx, &exponent);
      b_absx = std::ldexp(1.0, exponent - 53);
    }

    if (std::abs(bk - ak) < b_absx) {
      ialast = qEnd + 1;
      i2 = qEnd;
      j++;
    } else if (ak < bk) {
      n++;
      i++;
      ia_data[i] = i2 + 1;
      ialast = qEnd + 1;
      i2 = qEnd;
    } else {
      j++;
    }
  }

  while (ialast <= 28) {
    b_k = ialast;
    for (ialast = 0; ialast < 28; ialast++) {
      tmp[ialast] = static_cast<real_T>(ialast) + 1.0;
      iwork_data[ialast] = ialast + 1;
    }

    skip_to_last_equal_value_ZlLNIyBv(&b_k, tmp, iwork_data);
    n++;
    i++;
    ia_data[i] = i2 + 1;
    ialast = b_k + 1;
    i2 = b_k;
  }

  if (1 > i + 1) {
    i2 = -1;
  } else {
    i2 = i;
  }

  *ia_size = i2 + 1;
  codegenReal2Mission_sort(ia_data, ia_size, ia_data_0.data, &ia_data_0.size);
  for (b_k = 0; b_k <= i; b_k++) {
    c_data[b_k] = static_cast<real_T>(ia_data[b_k] - 1) + 1.0;
  }

  if (1 > n) {
    c_size[1] = 0;
  } else {
    c_size[1] = n;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_merge_m(int32_T
  idx_data[], real_T x_data[], int32_T offset, int32_T np, int32_T nq, int32_T
  iwork_data[], real_T xwork_data[])
{
  int32_T exitg1;
  int32_T iout;
  int32_T offset1;
  int32_T p;
  int32_T q;
  if (nq != 0) {
    offset1 = np + nq;
    for (p = 0; p < offset1; p++) {
      q = offset + p;
      iwork_data[p] = idx_data[q];
      xwork_data[p] = x_data[q];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          while (p + 1 <= np) {
            q = (offset1 + p) + 1;
            idx_data[q] = iwork_data[p];
            x_data[q] = xwork_data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_sortIdx(real_T x_data[],
  int32_T *x_size, int32_T idx_data[], int32_T *idx_size)
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
  *idx_size = static_cast<int8_T>(*x_size);
  if (0 <= static_cast<int8_T>(*x_size) - 1) {
    std::memset(&idx_data[0], 0, static_cast<int8_T>(*x_size) * sizeof(int32_T));
  }

  if (*x_size != 0) {
    b_x_size = *x_size;
    if (0 <= *x_size - 1) {
      std::memcpy(&b_x_data[0], &x_data[0], *x_size * sizeof(real_T));
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
    for (nPairs = 0; nPairs < *x_size; nPairs++) {
      ib++;
      idx4[ib - 1] = static_cast<int8_T>(nPairs + 1);
      x4[ib - 1] = b_x_data[nPairs];
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

        tmp = x4[ib - 1];
        tmp_0 = x4[n - 1];
        if (tmp <= tmp_0) {
          tmp = x4[nTail - 1];
          if (tmp <= tmp_0) {
            perm[0] = static_cast<int8_T>(ib);
            perm[1] = static_cast<int8_T>(nTail);
            perm[2] = static_cast<int8_T>(n);
            perm[3] = static_cast<int8_T>(i4);
          } else if (tmp <= x4[i4 - 1]) {
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
          tmp_0 = x4[i4 - 1];
          if (tmp <= tmp_0) {
            if (x4[nTail - 1] <= tmp_0) {
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

        idx_data[nPairs - 3] = idx4[perm[0] - 1];
        idx_data[nPairs - 2] = idx4[perm[1] - 1];
        idx_data[nPairs - 1] = idx4[perm[2] - 1];
        idx_data[nPairs] = idx4[perm[3] - 1];
        b_x_data[nPairs - 3] = x4[perm[0] - 1];
        b_x_data[nPairs - 2] = x4[perm[1] - 1];
        b_x_data[nPairs - 1] = x4[perm[2] - 1];
        b_x_data[nPairs] = x4[perm[3] - 1];
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

      for (nPairs = 0; nPairs < ib; nPairs++) {
        nTail = perm[nPairs] - 1;
        n = (((*x_size - 1) - ib) + nPairs) + 1;
        idx_data[n] = idx4[nTail];
        b_x_data[n] = x4[nTail];
      }
    }

    if (*x_size > 1) {
      if (0 <= *x_size - 1) {
        std::memset(&xwork_data[0], 0, *x_size * sizeof(real_T));
      }

      if (0 <= static_cast<int8_T>(*x_size) - 1) {
        std::memset(&iwork_data[0], 0, static_cast<int8_T>(*x_size) * sizeof
                    (int32_T));
      }

      nPairs = *x_size >> 2;
      n = 4;
      while (nPairs > 1) {
        if ((nPairs & 1U) != 0U) {
          nPairs--;
          ib = n * nPairs;
          nTail = *x_size - ib;
          if (nTail > n) {
            codegenReal2Mission_merge_m(idx_data, b_x_data, ib, n, nTail - n,
              iwork_data, xwork_data);
          }
        }

        ib = n << 1;
        nPairs >>= 1;
        for (nTail = 0; nTail < nPairs; nTail++) {
          codegenReal2Mission_merge_m(idx_data, b_x_data, nTail * ib, n, n,
            iwork_data, xwork_data);
        }

        n = ib;
      }

      if (*x_size > n) {
        codegenReal2Mission_merge_m(idx_data, b_x_data, 0, n, *x_size - n,
          iwork_data, xwork_data);
      }
    }

    if (0 <= b_x_size - 1) {
      std::memcpy(&x_data[0], &b_x_data[0], b_x_size * sizeof(real_T));
    }
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_sort_k(real_T x_data[],
  const int32_T *x_size)
{
  emxArray_int32_T_28_codegenReal2Mission_T vwork_data_0;
  real_T vwork_data[28];
  int32_T b;
  int32_T c_k;
  int32_T dim;
  int32_T vstride;
  int32_T vwork_size;
  dim = 2;
  if (*x_size != 1) {
    dim = 1;
    b = *x_size - 1;
  } else {
    b = 0;
  }

  vwork_size = b + 1;
  vstride = 1;
  c_k = 0;
  while (c_k <= dim - 2) {
    vstride *= *x_size;
    c_k = 1;
  }

  for (dim = 0; dim < vstride; dim++) {
    for (c_k = 0; c_k <= b; c_k++) {
      vwork_data[c_k] = x_data[c_k * vstride + dim];
    }

    codegenReal2Mission_sortIdx(vwork_data, &vwork_size, vwork_data_0.data,
      &vwork_data_0.size);
    for (c_k = 0; c_k <= b; c_k++) {
      x_data[dim + c_k * vstride] = vwork_data[c_k];
    }
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsConnection_findDisabledIndices(real_T idx_data[],
  int32_T *idx_size)
{
  real_T c_data[28];
  real_T ia_data_0[28];
  int32_T ia_data[28];
  int32_T c_size[2];
  int32_T ia_size;
  int32_T ia_size_0;
  int32_T ib_size;
  codegenReal2Mission_do_vectors(c_data, c_size, ia_data, &ia_size, &ib_size);
  ia_size_0 = ia_size;
  for (ib_size = 0; ib_size < ia_size; ib_size++) {
    ia_data_0[ib_size] = ia_data[ib_size];
  }

  codegenReal2Mission_do_vectors_o(ia_data_0, &ia_size_0, c_data, c_size,
    ia_data, &ia_size, &ib_size);
  *idx_size = ia_size;
  for (ib_size = 0; ib_size < ia_size; ib_size++) {
    idx_data[ib_size] = ia_data[ib_size];
  }

  codegenReal2Mission_sort_k(idx_data, idx_size);
  for (ib_size = 0; ib_size < *idx_size; ib_size++) {
    idx_data[ib_size]--;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void* codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsBuildable_uavDubinsBuildable(real_T airSpeed,
  real_T maxRollAngle, const real_T flightPathAngle[2], const real_T
  disabledPathTypes_data[], const int32_T *disabledPathTypes_size)
{
  real_T b_disabledPathTypes_data[28];
  real_T b_flightPathAngle[2];
  b_flightPathAngle[0] = flightPathAngle[0];
  b_flightPathAngle[1] = flightPathAngle[1];
  if (0 <= *disabledPathTypes_size - 1) {
    std::memcpy(&b_disabledPathTypes_data[0], &disabledPathTypes_data[0],
                *disabledPathTypes_size * sizeof(real_T));
  }

  return uavDubinsConnectionObj(airSpeed, maxRollAngle, &b_flightPathAngle[0],
    &b_disabledPathTypes_data[0], static_cast<uint32_T>(*disabledPathTypes_size));
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxFree_real_T
  (emxArray_real_T_codegenReal2Mission_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_codegenReal2Mission_T *)nullptr) {
    if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_codegenReal2Mission_T *)nullptr;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_o(const
  char_T a_data[], const int32_T a_size[2])
{
  static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~', '\x7f' };

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
        if (b[static_cast<uint8_T>(a_data[kstr]) & 127] != b[static_cast<int32_T>
            (c[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_ol(const
  char_T a_data[], const int32_T a_size[2])
{
  static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~', '\x7f' };

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
        if (b[static_cast<uint8_T>(a_data[kstr]) & 127] != b[static_cast<int32_T>
            (c[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S102>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsPathSegment_uavDubinsPathSegment_g0(const real_T
  varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
  varargin_4, real_T varargin_5, real_T varargin_6, const
  cell_wrap_10_codegenReal2Mission_T varargin_7[4], const real_T varargin_8[4],
  uavDubinsPathSegment_codegenReal2Mission_j_T *b_this)
{
  static const char_T d[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A',
    'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
    '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '{', '|', '}',
    '~', '\x7f' };

  real_T thetaWrap;
  int32_T k;
  b_this->MinTurningRadius = varargin_5;
  b_this->StartPose[0] = varargin_1[0];
  b_this->StartPose[1] = varargin_1[1];
  b_this->StartPose[2] = varargin_1[2];
  thetaWrap = mod_dBqh4Vat(varargin_1[3]);
  b_this->StartPose[3] = thetaWrap;
  if ((thetaWrap == 0.0) && (varargin_1[3] > 0.0)) {
    b_this->StartPose[3] = 6.2831853071795862;
  }

  wrapToPi_iEuDNbvh(&b_this->StartPose[3]);
  b_this->GoalPose[0] = varargin_2[0];
  b_this->GoalPose[1] = varargin_2[1];
  b_this->GoalPose[2] = varargin_2[2];
  thetaWrap = mod_dBqh4Vat(varargin_2[3]);
  b_this->GoalPose[3] = thetaWrap;
  if ((thetaWrap == 0.0) && (varargin_2[3] > 0.0)) {
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
  for (k = 0; k < varargin_7[0].f1.size[1]; k++) {
    b_this->MotionTypes[0].f1.data[k] = d[static_cast<uint8_T>(varargin_7[0].
      f1.data[k])];
  }

  b_this->MotionTypes[1].f1.size[0] = 1;
  b_this->MotionTypes[1].f1.size[1] = 1;
  b_this->MotionTypes[1].f1.data[0] = d[static_cast<uint8_T>(varargin_7[1].
    f1.data[0]) & 127];
  b_this->MotionTypes[2].f1.size[0] = 1;
  b_this->MotionTypes[2].f1.size[1] = 1;
  b_this->MotionTypes[2].f1.data[0] = d[static_cast<uint8_T>(varargin_7[2].
    f1.data[0]) & 127];
  b_this->MotionTypes[3].f1.size[0] = 1;
  b_this->MotionTypes[3].f1.size[1] = varargin_7[3].f1.size[1];
  for (k = 0; k < varargin_7[3].f1.size[1]; k++) {
    b_this->MotionTypes[3].f1.data[k] = d[static_cast<uint8_T>(varargin_7[3].
      f1.data[k])];
  }

  if (codegenReal2Mission_strcmp_o(b_this->MotionTypes[0].f1.data,
       b_this->MotionTypes[0].f1.size)) {
    b_this->MotionTypes[0].f1.size[0] = 1;
    b_this->MotionTypes[0].f1.size[1] = 2;
    b_this->MotionTypes[0].f1.data[0] = 'H';
    b_this->MotionTypes[0].f1.data[1] = 'l';
  } else if (codegenReal2Mission_strcmp_ol(b_this->MotionTypes[0].f1.data,
              b_this->MotionTypes[0].f1.size)) {
    b_this->MotionTypes[0].f1.size[0] = 1;
    b_this->MotionTypes[0].f1.size[1] = 2;
    b_this->MotionTypes[0].f1.data[0] = 'H';
    b_this->MotionTypes[0].f1.data[1] = 'r';
  } else if (codegenReal2Mission_strcmp_ol(b_this->MotionTypes[3].f1.data,
              b_this->MotionTypes[3].f1.size)) {
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = 2;
    b_this->MotionTypes[3].f1.data[0] = 'H';
    b_this->MotionTypes[3].f1.data[1] = 'r';
  } else if (codegenReal2Mission_strcmp_o(b_this->MotionTypes[3].f1.data,
              b_this->MotionTypes[3].f1.size)) {
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = 2;
    b_this->MotionTypes[3].f1.data[0] = 'H';
    b_this->MotionTypes[3].f1.data[1] = 'l';
  }

  b_this->Length = ((varargin_8[0] + varargin_8[1]) + varargin_8[2]) +
    varargin_8[3];
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
real_T codegenReal2MissionModelClass::codegenReal2Mission_sum(const real_T
  x_data[])
{
  return ((x_data[0] + x_data[1]) + x_data[2]) + x_data[3];
}

// Function for MATLAB Function: '<S102>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsBuiltins_connect_l(const
  uavDubinsConnection_codegenReal2Mission_T *obj, const real_T startPose[4],
  const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
  real_T dpt_data[], const int32_T *dpt_size,
  uavDubinsPathSegment_codegenReal2Mission_j_T pathSegObjs_data[], int32_T
  *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size)
{
  void* buildableObj_UAVDubinsBuildableObj;
  cell_wrap_10_codegenReal2Mission_T m[4];
  cell_wrap_10_codegenReal2Mission_T ac;
  cell_wrap_10_codegenReal2Mission_T ad;
  cell_wrap_10_codegenReal2Mission_T ae;
  cell_wrap_10_codegenReal2Mission_T af;
  cell_wrap_10_codegenReal2Mission_T bc;
  cell_wrap_10_codegenReal2Mission_T bd;
  cell_wrap_10_codegenReal2Mission_T be;
  cell_wrap_10_codegenReal2Mission_T bf;
  cell_wrap_10_codegenReal2Mission_T cc;
  cell_wrap_10_codegenReal2Mission_T cd;
  cell_wrap_10_codegenReal2Mission_T ce;
  cell_wrap_10_codegenReal2Mission_T cf;
  cell_wrap_10_codegenReal2Mission_T dc;
  cell_wrap_10_codegenReal2Mission_T dd;
  cell_wrap_10_codegenReal2Mission_T de;
  cell_wrap_10_codegenReal2Mission_T df;
  cell_wrap_10_codegenReal2Mission_T ec;
  cell_wrap_10_codegenReal2Mission_T ed;
  cell_wrap_10_codegenReal2Mission_T ee;
  cell_wrap_10_codegenReal2Mission_T ef;
  cell_wrap_10_codegenReal2Mission_T fc;
  cell_wrap_10_codegenReal2Mission_T fd;
  cell_wrap_10_codegenReal2Mission_T fe;
  cell_wrap_10_codegenReal2Mission_T ff;
  cell_wrap_10_codegenReal2Mission_T gc;
  cell_wrap_10_codegenReal2Mission_T gd;
  cell_wrap_10_codegenReal2Mission_T ge;
  cell_wrap_10_codegenReal2Mission_T gf;
  cell_wrap_10_codegenReal2Mission_T hc;
  cell_wrap_10_codegenReal2Mission_T hd;
  cell_wrap_10_codegenReal2Mission_T he;
  cell_wrap_10_codegenReal2Mission_T hf;
  cell_wrap_10_codegenReal2Mission_T ic;
  cell_wrap_10_codegenReal2Mission_T id;
  cell_wrap_10_codegenReal2Mission_T ie;
  cell_wrap_10_codegenReal2Mission_T jc;
  cell_wrap_10_codegenReal2Mission_T jd;
  cell_wrap_10_codegenReal2Mission_T je;
  cell_wrap_10_codegenReal2Mission_T jf;
  cell_wrap_10_codegenReal2Mission_T kb;
  cell_wrap_10_codegenReal2Mission_T kc;
  cell_wrap_10_codegenReal2Mission_T kd;
  cell_wrap_10_codegenReal2Mission_T ke;
  cell_wrap_10_codegenReal2Mission_T kf;
  cell_wrap_10_codegenReal2Mission_T lb;
  cell_wrap_10_codegenReal2Mission_T lc;
  cell_wrap_10_codegenReal2Mission_T ld;
  cell_wrap_10_codegenReal2Mission_T le;
  cell_wrap_10_codegenReal2Mission_T lf;
  cell_wrap_10_codegenReal2Mission_T mb;
  cell_wrap_10_codegenReal2Mission_T mc;
  cell_wrap_10_codegenReal2Mission_T md;
  cell_wrap_10_codegenReal2Mission_T me;
  cell_wrap_10_codegenReal2Mission_T mf;
  cell_wrap_10_codegenReal2Mission_T nb;
  cell_wrap_10_codegenReal2Mission_T nc;
  cell_wrap_10_codegenReal2Mission_T nd;
  cell_wrap_10_codegenReal2Mission_T ne;
  cell_wrap_10_codegenReal2Mission_T nf;
  cell_wrap_10_codegenReal2Mission_T ob;
  cell_wrap_10_codegenReal2Mission_T oc;
  cell_wrap_10_codegenReal2Mission_T od;
  cell_wrap_10_codegenReal2Mission_T oe;
  cell_wrap_10_codegenReal2Mission_T of;
  cell_wrap_10_codegenReal2Mission_T pb;
  cell_wrap_10_codegenReal2Mission_T pc;
  cell_wrap_10_codegenReal2Mission_T pd;
  cell_wrap_10_codegenReal2Mission_T pe;
  cell_wrap_10_codegenReal2Mission_T pf;
  cell_wrap_10_codegenReal2Mission_T qb;
  cell_wrap_10_codegenReal2Mission_T qc;
  cell_wrap_10_codegenReal2Mission_T qd;
  cell_wrap_10_codegenReal2Mission_T qe;
  cell_wrap_10_codegenReal2Mission_T qf;
  cell_wrap_10_codegenReal2Mission_T rb;
  cell_wrap_10_codegenReal2Mission_T rc;
  cell_wrap_10_codegenReal2Mission_T rd;
  cell_wrap_10_codegenReal2Mission_T re;
  cell_wrap_10_codegenReal2Mission_T rf;
  cell_wrap_10_codegenReal2Mission_T sb;
  cell_wrap_10_codegenReal2Mission_T sc;
  cell_wrap_10_codegenReal2Mission_T sd;
  cell_wrap_10_codegenReal2Mission_T se;
  cell_wrap_10_codegenReal2Mission_T sf;
  cell_wrap_10_codegenReal2Mission_T tb;
  cell_wrap_10_codegenReal2Mission_T tc;
  cell_wrap_10_codegenReal2Mission_T td;
  cell_wrap_10_codegenReal2Mission_T te;
  cell_wrap_10_codegenReal2Mission_T tf;
  cell_wrap_10_codegenReal2Mission_T ub;
  cell_wrap_10_codegenReal2Mission_T uc;
  cell_wrap_10_codegenReal2Mission_T ud;
  cell_wrap_10_codegenReal2Mission_T ue;
  cell_wrap_10_codegenReal2Mission_T uf;
  cell_wrap_10_codegenReal2Mission_T vb;
  cell_wrap_10_codegenReal2Mission_T vc;
  cell_wrap_10_codegenReal2Mission_T vd;
  cell_wrap_10_codegenReal2Mission_T ve;
  cell_wrap_10_codegenReal2Mission_T vf;
  cell_wrap_10_codegenReal2Mission_T wb;
  cell_wrap_10_codegenReal2Mission_T wc;
  cell_wrap_10_codegenReal2Mission_T wd;
  cell_wrap_10_codegenReal2Mission_T we;
  cell_wrap_10_codegenReal2Mission_T wf;
  cell_wrap_10_codegenReal2Mission_T xb;
  cell_wrap_10_codegenReal2Mission_T xc;
  cell_wrap_10_codegenReal2Mission_T xd;
  cell_wrap_10_codegenReal2Mission_T xe;
  cell_wrap_10_codegenReal2Mission_T yb;
  cell_wrap_10_codegenReal2Mission_T yc;
  cell_wrap_10_codegenReal2Mission_T yd;
  cell_wrap_10_codegenReal2Mission_T ye;
  emxArray_real_T_codegenReal2Mission_T *g;
  emxArray_real_T_codegenReal2Mission_T *g1;
  emxArray_real_T_codegenReal2Mission_T *g_0;
  emxArray_real_T_codegenReal2Mission_T *ml;
  emxArray_real_T_codegenReal2Mission_T *ml1;
  emxArray_real_T_codegenReal2Mission_T *s;
  emxArray_real_T_codegenReal2Mission_T *s1;
  real_T b_goalPose[4];
  real_T b_startPose[4];
  real_T ml1_0[4];
  real_T ml1_data[4];
  real_T l;
  real_T ml1_tmp;
  int32_T b_nRows;
  int32_T loop_ub;
  int32_T mt;
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
    codegenReal2Mission_uavDubinsBuildable_uavDubinsBuildable(obj->AirSpeed,
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
  if (!flagOptimal) {
    b_nRows = 28;
  }

  codegenReal2Mission_emxInit_real_T(&s, 2);
  codegenReal2Mission_emxInit_real_T(&g, 2);
  codegenReal2Mission_emxInit_real_T(&ml, 2);
  xf_tmp = b_nRows << 2;
  mt = s->size[0] * s->size[1];
  s->size[0] = xf_tmp;
  s->size[1] = xf_tmp;
  codegenReal2Mission_emxEnsureCapacity_real_T(s, mt);
  mt = g->size[0] * g->size[1];
  g->size[0] = xf_tmp;
  g->size[1] = xf_tmp;
  codegenReal2Mission_emxEnsureCapacity_real_T(g, mt);
  mt_size_idx_0 = b_nRows;
  mt = ml->size[0] * ml->size[1];
  ml->size[0] = xf_tmp;
  ml->size[1] = xf_tmp;
  codegenReal2Mission_emxEnsureCapacity_real_T(ml, mt);
  uavDubinsDistanceCodegen_real64(buildableObj_UAVDubinsBuildableObj,
    &b_startPose[0], 1U, &b_goalPose[0], 1U, flagOptimal, turningRadius,
    &s->data[0], &g->data[0], &codegenReal2Mission_B.b_fpa_data_m[0],
    &codegenReal2Mission_B.b_a_data_n[0], &codegenReal2Mission_B.mtr_data_p[0],
    &codegenReal2Mission_B.h_data_l[0], &codegenReal2Mission_B.mt_data_g[0],
    &ml->data[0]);
  b_nRows = 0;
  if (!flagOptimal) {
    b_nRows = 27;
  }

  codegenReal2Mission_emxInit_real_T(&g1, 2);
  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>
    (s->size[0] * s->size[1]) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = g1->size[0] * g1->size[1];
  g1->size[0] = num_idx_1;
  g1->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(g1, mt);
  loop_ub = num_idx_1;
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt < loop_ub; mt++) {
      g1->data[mt + g1->size[0] * xf_tmp] = s->data[xf_tmp + tmp[0] * mt];
    }
  }

  codegenReal2Mission_emxFree_real_T(&s);
  codegenReal2Mission_emxInit_real_T(&s1, 2);
  mt = s1->size[0] * s1->size[1];
  s1->size[0] = num_idx_1;
  s1->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(s1, mt);
  loop_ub = num_idx_1 << 2;
  for (xf_tmp = 0; xf_tmp < loop_ub; xf_tmp++) {
    s1->data[xf_tmp] = g1->data[xf_tmp];
  }

  codegenReal2Mission_emxInit_real_T(&g_0, 2);
  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>
    (g->size[0] * g->size[1]) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = g_0->size[0] * g_0->size[1];
  g_0->size[0] = num_idx_1;
  g_0->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(g_0, mt);
  loop_ub = num_idx_1;
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt < loop_ub; mt++) {
      g_0->data[mt + g_0->size[0] * xf_tmp] = g->data[xf_tmp + tmp[0] * mt];
    }
  }

  codegenReal2Mission_emxFree_real_T(&g);
  mt = g1->size[0] * g1->size[1];
  g1->size[0] = num_idx_1;
  g1->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(g1, mt);
  loop_ub = num_idx_1 << 2;
  for (xf_tmp = 0; xf_tmp < loop_ub; xf_tmp++) {
    g1->data[xf_tmp] = g_0->data[xf_tmp];
  }

  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>
    (ml->size[0] * ml->size[1]) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = g_0->size[0] * g_0->size[1];
  g_0->size[0] = num_idx_1;
  g_0->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(g_0, mt);
  loop_ub = num_idx_1;
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt < loop_ub; mt++) {
      g_0->data[mt + g_0->size[0] * xf_tmp] = ml->data[xf_tmp + tmp[0] * mt];
    }
  }

  codegenReal2Mission_emxFree_real_T(&ml);
  codegenReal2Mission_emxInit_real_T(&ml1, 2);
  mt = ml1->size[0] * ml1->size[1];
  ml1->size[0] = num_idx_1;
  ml1->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(ml1, mt);
  loop_ub = num_idx_1 << 2;
  for (xf_tmp = 0; xf_tmp < loop_ub; xf_tmp++) {
    ml1->data[xf_tmp] = g_0->data[xf_tmp];
  }

  codegenReal2Mission_emxFree_real_T(&g_0);
  loop_ub = mt_size_idx_0 * mt_size_idx_0;
  for (xf_tmp = 0; xf_tmp < loop_ub; xf_tmp++) {
    codegenReal2Mission_B.mt_data_g[xf_tmp]++;
  }

  l = 0.0;
  *pathCosts_size = b_nRows + 1;
  for (xf_tmp = 0; xf_tmp <= b_nRows; xf_tmp++) {
    pathCosts_data[xf_tmp] = (rtNaN);
  }

  m[0] = kb;
  m[1] = lb;
  m[2] = mb;
  m[3] = nb;
  if (flagOptimal) {
    *pathSegObjs_size = static_cast<int16_T>(b_nRows + 1);
    for (xf_tmp = 0; xf_tmp <= b_nRows; xf_tmp++) {
      l++;
      ml1_tmp = codegenReal2Mission_B.mt_data_g[static_cast<int32_T>(l) - 1];
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

      b_startPose[0] = s1->data[static_cast<int32_T>(l) - 1];
      b_goalPose[0] = g1->data[static_cast<int32_T>(l) - 1];
      ml1_tmp = ml1->data[static_cast<int32_T>(l) - 1];
      ml1_0[0] = ml1_tmp;
      ml1_data[0] = ml1_tmp;
      b_startPose[1] = s1->data[(static_cast<int32_T>(l) + s1->size[0]) - 1];
      b_goalPose[1] = g1->data[(static_cast<int32_T>(l) + g1->size[0]) - 1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + ml1->size[0]) - 1];
      ml1_0[1] = ml1_tmp;
      ml1_data[1] = ml1_tmp;
      b_startPose[2] = s1->data[(static_cast<int32_T>(l) + (s1->size[0] << 1)) -
        1];
      b_goalPose[2] = g1->data[(static_cast<int32_T>(l) + (g1->size[0] << 1)) -
        1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + (ml1->size[0] << 1)) - 1];
      ml1_0[2] = ml1_tmp;
      ml1_data[2] = ml1_tmp;
      b_startPose[3] = s1->data[(static_cast<int32_T>(l) + s1->size[0] * 3) - 1];
      b_goalPose[3] = g1->data[(static_cast<int32_T>(l) + g1->size[0] * 3) - 1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + ml1->size[0] * 3) - 1];
      ml1_0[3] = ml1_tmp;
      ml1_data[3] = ml1_tmp;
      codegenReal2Mission_uavDubinsPathSegment_uavDubinsPathSegment_g0
        (b_startPose, b_goalPose, codegenReal2Mission_B.b_fpa_data_m[
         static_cast<int32_T>(l) - 1], codegenReal2Mission_B.b_a_data_n[0],
         codegenReal2Mission_B.mtr_data_p[0], codegenReal2Mission_B.h_data_l[
         static_cast<int32_T>(l) - 1], m, ml1_0, &pathSegObjs_data[xf_tmp]);
      pathCosts_data[xf_tmp] = codegenReal2Mission_sum(ml1_data);
    }
  } else {
    *pathSegObjs_size = static_cast<int16_T>(b_nRows + 1);
    for (xf_tmp = 1; xf_tmp - 1 <= b_nRows; xf_tmp++) {
      l++;
      if (1 == xf_tmp) {
        m[0] = kb;
        m[1] = lb;
        m[2] = mb;
        m[3] = nb;
      }

      if (2 == xf_tmp) {
        m[0] = ob;
        m[1] = pb;
        m[2] = qb;
        m[3] = rb;
      }

      if (3 == xf_tmp) {
        m[0] = sb;
        m[1] = tb;
        m[2] = ub;
        m[3] = vb;
      }

      if (4 == xf_tmp) {
        m[0] = wb;
        m[1] = xb;
        m[2] = yb;
        m[3] = ac;
      }

      if (5 == xf_tmp) {
        m[0] = bc;
        m[1] = cc;
        m[2] = dc;
        m[3] = ec;
      }

      if (6 == xf_tmp) {
        m[0] = fc;
        m[1] = gc;
        m[2] = hc;
        m[3] = ic;
      }

      if (7 == xf_tmp) {
        m[0] = jc;
        m[1] = kc;
        m[2] = lc;
        m[3] = mc;
      }

      if (8 == xf_tmp) {
        m[0] = nc;
        m[1] = oc;
        m[2] = pc;
        m[3] = qc;
      }

      if (9 == xf_tmp) {
        m[0] = rc;
        m[1] = sc;
        m[2] = tc;
        m[3] = uc;
      }

      if (10 == xf_tmp) {
        m[0] = vc;
        m[1] = wc;
        m[2] = xc;
        m[3] = yc;
      }

      if (11 == xf_tmp) {
        m[0] = ad;
        m[1] = bd;
        m[2] = cd;
        m[3] = dd;
      }

      if (12 == xf_tmp) {
        m[0] = ed;
        m[1] = fd;
        m[2] = gd;
        m[3] = hd;
      }

      if (13 == xf_tmp) {
        m[0] = id;
        m[1] = jd;
        m[2] = kd;
        m[3] = ld;
      }

      if (14 == xf_tmp) {
        m[0] = md;
        m[1] = nd;
        m[2] = od;
        m[3] = pd;
      }

      if (15 == xf_tmp) {
        m[0] = qd;
        m[1] = rd;
        m[2] = sd;
        m[3] = td;
      }

      if (16 == xf_tmp) {
        m[0] = ud;
        m[1] = vd;
        m[2] = wd;
        m[3] = xd;
      }

      if (17 == xf_tmp) {
        m[0] = yd;
        m[1] = ae;
        m[2] = be;
        m[3] = ce;
      }

      if (18 == xf_tmp) {
        m[0] = de;
        m[1] = ee;
        m[2] = fe;
        m[3] = ge;
      }

      if (19 == xf_tmp) {
        m[0] = he;
        m[1] = ie;
        m[2] = je;
        m[3] = ke;
      }

      if (20 == xf_tmp) {
        m[0] = le;
        m[1] = me;
        m[2] = ne;
        m[3] = oe;
      }

      if (21 == xf_tmp) {
        m[0] = pe;
        m[1] = qe;
        m[2] = re;
        m[3] = se;
      }

      if (22 == xf_tmp) {
        m[0] = te;
        m[1] = ue;
        m[2] = ve;
        m[3] = we;
      }

      if (23 == xf_tmp) {
        m[0] = xe;
        m[1] = ye;
        m[2] = af;
        m[3] = bf;
      }

      if (24 == xf_tmp) {
        m[0] = cf;
        m[1] = df;
        m[2] = ef;
        m[3] = ff;
      }

      if (25 == xf_tmp) {
        m[0] = gf;
        m[1] = hf;
        m[2] = jf;
        m[3] = kf;
      }

      if (26 == xf_tmp) {
        m[0] = lf;
        m[1] = mf;
        m[2] = nf;
        m[3] = of;
      }

      if (27 == xf_tmp) {
        m[0] = pf;
        m[1] = qf;
        m[2] = rf;
        m[3] = sf;
      }

      if (28 == xf_tmp) {
        m[0] = tf;
        m[1] = uf;
        m[2] = vf;
        m[3] = wf;
      }

      b_startPose[0] = s1->data[static_cast<int32_T>(l) - 1];
      b_goalPose[0] = g1->data[static_cast<int32_T>(l) - 1];
      ml1_tmp = ml1->data[static_cast<int32_T>(l) - 1];
      ml1_0[0] = ml1_tmp;
      ml1_data[0] = ml1_tmp;
      b_startPose[1] = s1->data[(static_cast<int32_T>(l) + s1->size[0]) - 1];
      b_goalPose[1] = g1->data[(static_cast<int32_T>(l) + g1->size[0]) - 1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + ml1->size[0]) - 1];
      ml1_0[1] = ml1_tmp;
      ml1_data[1] = ml1_tmp;
      b_startPose[2] = s1->data[(static_cast<int32_T>(l) + (s1->size[0] << 1)) -
        1];
      b_goalPose[2] = g1->data[(static_cast<int32_T>(l) + (g1->size[0] << 1)) -
        1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + (ml1->size[0] << 1)) - 1];
      ml1_0[2] = ml1_tmp;
      ml1_data[2] = ml1_tmp;
      b_startPose[3] = s1->data[(static_cast<int32_T>(l) + s1->size[0] * 3) - 1];
      b_goalPose[3] = g1->data[(static_cast<int32_T>(l) + g1->size[0] * 3) - 1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + ml1->size[0] * 3) - 1];
      ml1_0[3] = ml1_tmp;
      ml1_data[3] = ml1_tmp;
      codegenReal2Mission_uavDubinsPathSegment_uavDubinsPathSegment_g0
        (b_startPose, b_goalPose, codegenReal2Mission_B.b_fpa_data_m[
         static_cast<int32_T>(l) - 1], codegenReal2Mission_B.b_a_data_n[0],
         codegenReal2Mission_B.mtr_data_p[0], codegenReal2Mission_B.h_data_l[
         static_cast<int32_T>(l) - 1], m, ml1_0, &pathSegObjs_data[xf_tmp - 1]);
      pathCosts_data[xf_tmp - 1] = codegenReal2Mission_sum(ml1_data);
    }
  }

  codegenReal2Mission_emxFree_real_T(&ml1);
  codegenReal2Mission_emxFree_real_T(&g1);
  codegenReal2Mission_emxFree_real_T(&s1);
}

// Function for MATLAB Function: '<S102>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsConnection_connect_f(const
  uavDubinsConnection_codegenReal2Mission_T *obj, const real_T startPoses[4],
  const real_T goalPoses[4], uavDubinsPathSegment_codegenReal2Mission_j_T
  pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
  int32_T *pathCosts_size)
{
  matlabshared_autonomous_core_internal_NameValueParser_codegenReal2Mission_T
    parser;
  real_T idx_data[28];
  int32_T tmp_size[2];
  int32_T flagOptimal;
  int32_T idx_size;
  char_T tmp_data[7];
  codegenReal2Mission_NameValueParser_NameValueParser(&parser);
  parser.ParsedResults = parser.Defaults;
  flagOptimal = 1;
  codegenReal2Mission_validatestring(parser.ParsedResults.f1, tmp_data, tmp_size);
  if (codegenReal2Mission_strcmp(tmp_data, tmp_size)) {
    flagOptimal = 0;
  }

  codegenReal2Mission_uavDubinsConnection_findDisabledIndices(idx_data,
    &idx_size);
  codegenReal2Mission_uavDubinsBuiltins_connect_l(obj, startPoses, goalPoses,
    flagOptimal == 1, obj->MinTurningRadius, idx_data, &idx_size,
    pathSegObjs_data, pathSegObjs_size, pathCosts_data, pathCosts_size);
}

// Function for MATLAB Function: '<S102>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_strcmp_abl2(const
  cell_wrap_10_codegenReal2Mission_T a[4], boolean_T b_bool[4])
{
  b_bool[0] = false;
  if ((a[0].f1.size[1] == 1) && (!(a[0].f1.data[0] != 'N'))) {
    b_bool[0] = true;
  }

  b_bool[1] = false;
  if ((a[1].f1.size[1] == 1) && (!(a[1].f1.data[0] != 'N'))) {
    b_bool[1] = true;
  }

  b_bool[2] = false;
  if ((a[2].f1.size[1] == 1) && (!(a[2].f1.data[0] != 'N'))) {
    b_bool[2] = true;
  }

  b_bool[3] = false;
  if ((a[3].f1.size[1] == 1) && (!(a[3].f1.data[0] != 'N'))) {
    b_bool[3] = true;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_any(const boolean_T
  x[4])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (!x[k]) {
      k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_useConstantDim(const
  real_T varargin_2_data[], const int32_T varargin_2_size[2], real_T
  varargout_1_data[], int32_T varargout_1_size[2])
{
  int32_T loop_ub;
  varargout_1_size[0] = 1;
  varargout_1_size[1] = varargin_2_size[1];
  loop_ub = varargin_2_size[1] - 1;
  if (0 <= loop_ub) {
    std::memcpy(&varargout_1_data[0], &varargin_2_data[0], (loop_ub + 1) *
                sizeof(real_T));
  }

  for (loop_ub = 0; loop_ub <= varargin_2_size[1] - 2; loop_ub++) {
    varargout_1_data[loop_ub + 1] += varargout_1_data[loop_ub];
  }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_int32_T
  (emxArray_int32_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T_codegenReal2Mission_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T_codegenReal2Mission_T *)std::malloc(sizeof
    (emxArray_int32_T_codegenReal2Mission_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
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
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
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
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(int32_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_real_T1
  (emxArray_real_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_codegenReal2Mission_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_codegenReal2Mission_T *)std::malloc(sizeof
    (emxArray_real_T_codegenReal2Mission_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void codegenReal2MissionModelClass::
  codegenReal2Mission_emxEnsureCapacity_real_T1
  (emxArray_real_T_codegenReal2Mission_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
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
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(real_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_int32_T1
  (emxArray_int32_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T_codegenReal2Mission_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T_codegenReal2Mission_T *)std::malloc(sizeof
    (emxArray_int32_T_codegenReal2Mission_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void codegenReal2MissionModelClass::
  codegenReal2Mission_emxEnsureCapacity_int32_T1
  (emxArray_int32_T_codegenReal2Mission_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
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
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(int32_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_merge_mm
  (emxArray_int32_T_codegenReal2Mission_T *idx,
   emxArray_real_T_codegenReal2Mission_T *x, int32_T offset, int32_T np, int32_T
   nq, emxArray_int32_T_codegenReal2Mission_T *iwork,
   emxArray_real_T_codegenReal2Mission_T *xwork)
{
  int32_T exitg1;
  int32_T iout;
  int32_T offset1;
  int32_T p;
  int32_T q;
  if (nq != 0) {
    offset1 = np + nq;
    for (p = 0; p < offset1; p++) {
      q = offset + p;
      iwork->data[p] = idx->data[q];
      xwork->data[p] = x->data[q];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[q]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[q];
        x->data[iout] = xwork->data[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          while (p + 1 <= np) {
            q = (offset1 + p) + 1;
            idx->data[q] = iwork->data[p];
            x->data[q] = xwork->data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_merge_block
  (emxArray_int32_T_codegenReal2Mission_T *idx,
   emxArray_real_T_codegenReal2Mission_T *x, int32_T offset, int32_T n, int32_T
   preSortLevel, emxArray_int32_T_codegenReal2Mission_T *iwork,
   emxArray_real_T_codegenReal2Mission_T *xwork)
{
  int32_T bLen;
  int32_T nPairs;
  int32_T nTail;
  int32_T tailOffset;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1U) != 0U) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        codegenReal2Mission_merge_mm(idx, x, offset + tailOffset, bLen, nTail -
          bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      codegenReal2Mission_merge_mm(idx, x, offset + nTail * tailOffset, bLen,
        bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    codegenReal2Mission_merge_mm(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxFree_int32_T
  (emxArray_int32_T_codegenReal2Mission_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T_codegenReal2Mission_T *)nullptr) {
    if (((*pEmxArray)->data != (int32_T *)nullptr) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T_codegenReal2Mission_T *)nullptr;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_sort_k5
  (emxArray_real_T_codegenReal2Mission_T *x)
{
  emxArray_int32_T_codegenReal2Mission_T *idx;
  emxArray_int32_T_codegenReal2Mission_T *iwork;
  emxArray_real_T_codegenReal2Mission_T *b_x;
  emxArray_real_T_codegenReal2Mission_T *xwork;
  real_T b_xwork[256];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T b_iwork[256];
  int32_T idx4[4];
  int32_T bLen;
  int32_T bLen2;
  int32_T b_iwork_tmp;
  int32_T e_k;
  int32_T exitg1;
  int32_T i2;
  int32_T ib;
  int32_T n;
  int32_T nNonNaN;
  int32_T nPairs;
  int32_T p;
  int32_T preSortLevel;
  int32_T q;
  int32_T wOffset;
  int8_T perm[4];
  codegenReal2Mission_emxInit_real_T(&b_x, 2);
  b_iwork_tmp = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  codegenReal2Mission_emxEnsureCapacity_real_T(b_x, b_iwork_tmp);
  wOffset = x->size[1] - 1;
  for (preSortLevel = 0; preSortLevel <= wOffset; preSortLevel++) {
    b_x->data[preSortLevel] = x->data[preSortLevel];
  }

  if (x->size[1] != 0) {
    b_iwork_tmp = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    codegenReal2Mission_emxEnsureCapacity_real_T(b_x, b_iwork_tmp);
    wOffset = x->size[1] - 1;
    for (preSortLevel = 0; preSortLevel <= wOffset; preSortLevel++) {
      b_x->data[preSortLevel] = x->data[preSortLevel];
    }

    codegenReal2Mission_emxInit_int32_T(&idx, 2);
    b_iwork_tmp = idx->size[0] * idx->size[1];
    idx->size[0] = 1;
    idx->size[1] = x->size[1];
    codegenReal2Mission_emxEnsureCapacity_int32_T(idx, b_iwork_tmp);
    wOffset = x->size[1] - 1;
    for (preSortLevel = 0; preSortLevel <= wOffset; preSortLevel++) {
      idx->data[preSortLevel] = 0;
    }

    codegenReal2Mission_emxInit_real_T1(&xwork, 1);
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
    codegenReal2Mission_emxEnsureCapacity_real_T1(xwork, b_iwork_tmp);
    wOffset = x->size[1];
    for (preSortLevel = 0; preSortLevel < wOffset; preSortLevel++) {
      xwork->data[preSortLevel] = 0.0;
    }

    nNonNaN = 0;
    ib = 0;
    for (wOffset = 0; wOffset < n; wOffset++) {
      if (std::isnan(b_x->data[wOffset])) {
        preSortLevel = (n - nNonNaN) - 1;
        idx->data[preSortLevel] = wOffset + 1;
        xwork->data[preSortLevel] = b_x->data[wOffset];
        nNonNaN++;
      } else {
        ib++;
        idx4[ib - 1] = wOffset + 1;
        x4[ib - 1] = b_x->data[wOffset];
        if (ib == 4) {
          preSortLevel = wOffset - nNonNaN;
          if (x4[0] <= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }

          if (x4[2] <= x4[3]) {
            bLen = 3;
            bLen2 = 4;
          } else {
            bLen = 4;
            bLen2 = 3;
          }

          tmp = x4[ib - 1];
          tmp_0 = x4[bLen - 1];
          if (tmp <= tmp_0) {
            tmp = x4[i2 - 1];
            if (tmp <= tmp_0) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i2);
              perm[2] = static_cast<int8_T>(bLen);
              perm[3] = static_cast<int8_T>(bLen2);
            } else if (tmp <= x4[bLen2 - 1]) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(bLen);
              perm[2] = static_cast<int8_T>(i2);
              perm[3] = static_cast<int8_T>(bLen2);
            } else {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(bLen);
              perm[2] = static_cast<int8_T>(bLen2);
              perm[3] = static_cast<int8_T>(i2);
            }
          } else {
            tmp_0 = x4[bLen2 - 1];
            if (tmp <= tmp_0) {
              if (x4[i2 - 1] <= tmp_0) {
                perm[0] = static_cast<int8_T>(bLen);
                perm[1] = static_cast<int8_T>(ib);
                perm[2] = static_cast<int8_T>(i2);
                perm[3] = static_cast<int8_T>(bLen2);
              } else {
                perm[0] = static_cast<int8_T>(bLen);
                perm[1] = static_cast<int8_T>(ib);
                perm[2] = static_cast<int8_T>(bLen2);
                perm[3] = static_cast<int8_T>(i2);
              }
            } else {
              perm[0] = static_cast<int8_T>(bLen);
              perm[1] = static_cast<int8_T>(bLen2);
              perm[2] = static_cast<int8_T>(ib);
              perm[3] = static_cast<int8_T>(i2);
            }
          }

          idx->data[preSortLevel - 3] = idx4[perm[0] - 1];
          idx->data[preSortLevel - 2] = idx4[perm[1] - 1];
          idx->data[preSortLevel - 1] = idx4[perm[2] - 1];
          idx->data[preSortLevel] = idx4[perm[3] - 1];
          b_x->data[preSortLevel - 3] = x4[perm[0] - 1];
          b_x->data[preSortLevel - 2] = x4[perm[1] - 1];
          b_x->data[preSortLevel - 1] = x4[perm[2] - 1];
          b_x->data[preSortLevel] = x4[perm[3] - 1];
          ib = 0;
        }
      }
    }

    wOffset = (x->size[1] - nNonNaN) - 1;
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

      for (i2 = 0; i2 < ib; i2++) {
        preSortLevel = perm[i2] - 1;
        b_iwork_tmp = ((wOffset - ib) + i2) + 1;
        idx->data[b_iwork_tmp] = idx4[preSortLevel];
        b_x->data[b_iwork_tmp] = x4[preSortLevel];
      }
    }

    ib = (nNonNaN >> 1) + 1;
    for (i2 = 1; i2 - 1 <= ib - 2; i2++) {
      bLen = wOffset + i2;
      bLen2 = idx->data[bLen];
      preSortLevel = n - i2;
      idx->data[bLen] = idx->data[preSortLevel];
      idx->data[preSortLevel] = bLen2;
      b_x->data[bLen] = xwork->data[preSortLevel];
      b_x->data[preSortLevel] = xwork->data[bLen];
    }

    if ((nNonNaN & 1U) != 0U) {
      preSortLevel = wOffset + ib;
      b_x->data[preSortLevel] = xwork->data[preSortLevel];
    }

    codegenReal2Mission_emxInit_int32_T1(&iwork, 1);
    b_iwork_tmp = iwork->size[0];
    iwork->size[0] = x->size[1];
    codegenReal2Mission_emxEnsureCapacity_int32_T1(iwork, b_iwork_tmp);
    wOffset = x->size[1];
    for (preSortLevel = 0; preSortLevel < wOffset; preSortLevel++) {
      iwork->data[preSortLevel] = 0;
    }

    nNonNaN = x->size[1] - nNonNaN;
    preSortLevel = 2;
    if (nNonNaN > 1) {
      if (x->size[1] >= 256) {
        n = nNonNaN >> 8;
        if (n > 0) {
          for (ib = 0; ib < n; ib++) {
            i2 = (ib << 8) - 1;
            for (wOffset = 0; wOffset < 6; wOffset++) {
              bLen = 1 << (wOffset + 2);
              bLen2 = bLen << 1;
              nPairs = 256 >> (wOffset + 3);
              for (e_k = 0; e_k < nPairs; e_k++) {
                preSortLevel = e_k * bLen2 + i2;
                for (p = 0; p < bLen2; p++) {
                  b_iwork_tmp = (preSortLevel + p) + 1;
                  b_iwork[p] = idx->data[b_iwork_tmp];
                  b_xwork[p] = b_x->data[b_iwork_tmp];
                }

                p = 0;
                q = bLen;
                do {
                  exitg1 = 0;
                  preSortLevel++;
                  if (b_xwork[p] <= b_xwork[q]) {
                    idx->data[preSortLevel] = b_iwork[p];
                    b_x->data[preSortLevel] = b_xwork[p];
                    if (p + 1 < bLen) {
                      p++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx->data[preSortLevel] = b_iwork[q];
                    b_x->data[preSortLevel] = b_xwork[q];
                    if (q + 1 < bLen2) {
                      q++;
                    } else {
                      q = preSortLevel - p;
                      while (p + 1 <= bLen) {
                        b_iwork_tmp = (q + p) + 1;
                        idx->data[b_iwork_tmp] = b_iwork[p];
                        b_x->data[b_iwork_tmp] = b_xwork[p];
                        p++;
                      }

                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }

          preSortLevel = n << 8;
          n = nNonNaN - preSortLevel;
          if (n > 0) {
            codegenReal2Mission_merge_block(idx, b_x, preSortLevel, n, 2, iwork,
              xwork);
          }

          preSortLevel = 8;
        }
      }

      codegenReal2Mission_merge_block(idx, b_x, 0, nNonNaN, preSortLevel, iwork,
        xwork);
    }

    codegenReal2Mission_emxFree_int32_T(&idx);
    codegenReal2Mission_emxFree_real_T(&xwork);
    codegenReal2Mission_emxFree_int32_T(&iwork);
  }

  b_iwork_tmp = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = b_x->size[1];
  codegenReal2Mission_emxEnsureCapacity_real_T(x, b_iwork_tmp);
  wOffset = b_x->size[1];
  for (preSortLevel = 0; preSortLevel < wOffset; preSortLevel++) {
    x->data[preSortLevel] = b_x->data[preSortLevel];
  }

  codegenReal2Mission_emxFree_real_T(&b_x);
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_boolean_T
  (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
  emxArray_boolean_T_codegenReal2Mission_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_codegenReal2Mission_T *)std::malloc(sizeof
    (emxArray_boolean_T_codegenReal2Mission_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxFree_boolean_T
  (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T_codegenReal2Mission_T *)nullptr) {
    if (((*pEmxArray)->data != (boolean_T *)nullptr) && (*pEmxArray)
        ->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T_codegenReal2Mission_T *)nullptr;
  }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxInit_boolean_T1
  (emxArray_boolean_T_codegenReal2Mission_T **pEmxArray, int32_T numDimensions)
{
  emxArray_boolean_T_codegenReal2Mission_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_codegenReal2Mission_T *)std::malloc(sizeof
    (emxArray_boolean_T_codegenReal2Mission_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void codegenReal2MissionModelClass::
  codegenReal2Mission_emxEnsureCapacity_boolean_T1
  (emxArray_boolean_T_codegenReal2Mission_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
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
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(boolean_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_wrapToPi
  (emxArray_real_T_codegenReal2Mission_T *theta)
{
  emxArray_boolean_T_codegenReal2Mission_T *x;
  emxArray_real_T_codegenReal2Mission_T *y;
  int32_T b_k;
  int32_T loop_ub;
  boolean_T b_y;
  boolean_T exitg1;
  codegenReal2Mission_emxInit_real_T1(&y, 1);
  b_k = y->size[0];
  y->size[0] = theta->size[0];
  codegenReal2Mission_emxEnsureCapacity_real_T1(y, b_k);
  for (b_k = 0; b_k < theta->size[0]; b_k++) {
    y->data[b_k] = std::abs(theta->data[b_k]);
  }

  codegenReal2Mission_emxInit_boolean_T1(&x, 1);
  b_k = x->size[0];
  x->size[0] = y->size[0];
  codegenReal2Mission_emxEnsureCapacity_boolean_T1(x, b_k);
  loop_ub = y->size[0];
  for (b_k = 0; b_k < loop_ub; b_k++) {
    x->data[b_k] = (y->data[b_k] > 3.1415926535897931);
  }

  b_y = false;
  b_k = 1;
  exitg1 = false;
  while ((!exitg1) && (b_k <= x->size[0])) {
    if (!x->data[b_k - 1]) {
      b_k++;
    } else {
      b_y = true;
      exitg1 = true;
    }
  }

  if (b_y) {
    b_k = y->size[0];
    y->size[0] = theta->size[0];
    codegenReal2Mission_emxEnsureCapacity_real_T1(y, b_k);
    loop_ub = theta->size[0];
    for (b_k = 0; b_k < loop_ub; b_k++) {
      y->data[b_k] = theta->data[b_k] + 3.1415926535897931;
    }

    b_k = theta->size[0];
    theta->size[0] = y->size[0];
    codegenReal2Mission_emxEnsureCapacity_real_T1(theta, b_k);
    for (b_k = 0; b_k < y->size[0]; b_k++) {
      theta->data[b_k] = mod_dBqh4Vat(y->data[b_k]);
    }

    b_k = x->size[0];
    x->size[0] = theta->size[0];
    codegenReal2Mission_emxEnsureCapacity_boolean_T1(x, b_k);
    loop_ub = theta->size[0];
    for (b_k = 0; b_k < loop_ub; b_k++) {
      x->data[b_k] = (theta->data[b_k] == 0.0);
    }

    for (b_k = 0; b_k < x->size[0]; b_k++) {
      if (x->data[b_k] && (y->data[b_k] > 0.0)) {
        theta->data[b_k] = 6.2831853071795862;
      }
    }

    loop_ub = theta->size[0];
    for (b_k = 0; b_k < loop_ub; b_k++) {
      theta->data[b_k] -= 3.1415926535897931;
    }
  }

  codegenReal2Mission_emxFree_boolean_T(&x);
  codegenReal2Mission_emxFree_real_T(&y);
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
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
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
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(boolean_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_eml_find_g(const
  emxArray_boolean_T_codegenReal2Mission_T *x,
  emxArray_int32_T_codegenReal2Mission_T *i)
{
  int32_T idx;
  int32_T ii;
  int32_T nx;
  boolean_T exitg1;
  nx = x->size[1];
  idx = 0;
  ii = i->size[0] * i->size[1];
  i->size[0] = 1;
  i->size[1] = x->size[1];
  codegenReal2Mission_emxEnsureCapacity_int32_T(i, ii);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x->data[ii]) {
      idx++;
      i->data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
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
    ii = i->size[0] * i->size[1];
    i->size[1] = idx;
    codegenReal2Mission_emxEnsureCapacity_int32_T(i, ii);
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_ol2u(const
  char_T a_data[], const int32_T a_size[2])
{
  boolean_T b_bool;
  b_bool = false;
  if ((a_size[1] == 1) && (!(a_data[0] != 'N'))) {
    b_bool = true;
  }

  return b_bool;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_ol2ud(const
  char_T a_data[], const int32_T a_size[2])
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
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_ol2udr(const
  char_T a_data[], const int32_T a_size[2])
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
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_ol2udrg(
  const char_T a_data[], const int32_T a_size[2])
{
  boolean_T b_bool;
  b_bool = false;
  if ((a_size[1] == 1) && (!(a_data[0] != 'L'))) {
    b_bool = true;
  }

  return b_bool;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_ol2udrgv(
  const char_T a_data[], const int32_T a_size[2])
{
  boolean_T b_bool;
  b_bool = false;
  if ((a_size[1] == 1) && (!(a_data[0] != 'R'))) {
    b_bool = true;
  }

  return b_bool;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
boolean_T codegenReal2MissionModelClass::codegenReal2Mission_strcmp_ol2udrgv2(
  const char_T a_data[], const int32_T a_size[2])
{
  boolean_T b_bool;
  b_bool = false;
  if ((a_size[1] == 1) && (!(a_data[0] != 'S'))) {
    b_bool = true;
  }

  return b_bool;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_mtimes(const
  emxArray_real_T_codegenReal2Mission_T *A, const real_T B[4],
  emxArray_real_T_codegenReal2Mission_T *C)
{
  int32_T i;
  int32_T m;
  m = A->size[0];
  i = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = 2;
  codegenReal2Mission_emxEnsureCapacity_real_T(C, i);
  for (i = 0; i < m; i++) {
    C->data[i] = A->data[i] * B[0] + A->data[A->size[0] + i] * B[1];
  }

  for (i = 0; i < m; i++) {
    C->data[m + i] = A->data[i] * B[2] + A->data[A->size[0] + i] * B[3];
  }
}

// Function for MATLAB Function: '<S102>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsPathSegment_interpolate_d(const real_T
  b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_10_codegenReal2Mission_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, emxArray_real_T_codegenReal2Mission_T *samples,
  emxArray_real_T_codegenReal2Mission_T *poses)
{
  emxArray_boolean_T_codegenReal2Mission_T *tempSamplesIndex;
  emxArray_boolean_T_codegenReal2Mission_T *tempSamplesIndex_0;
  emxArray_int32_T_codegenReal2Mission_T *ab;
  emxArray_real_T_codegenReal2Mission_T *S;
  emxArray_real_T_codegenReal2Mission_T *S_0;
  emxArray_real_T_codegenReal2Mission_T *e_x;
  emxArray_real_T_codegenReal2Mission_T *ns;
  emxArray_real_T_codegenReal2Mission_T *p;
  emxArray_real_T_codegenReal2Mission_T *tempSamples;
  emxArray_real_T_codegenReal2Mission_T *z;
  real_T state[6];
  real_T TransformMatrix[4];
  real_T c_x_data[4];
  real_T tempMotionLength_data[4];
  real_T TransformMatrix_tmp;
  real_T b_b_tmp;
  real_T e_b;
  real_T intermediateLength;
  real_T radius;
  real_T samples_0;
  real_T startIndex;
  real_T state_0;
  real_T tempStartPose_idx_2;
  int32_T c_x_size[2];
  int32_T tempMotionLength_size[2];
  int32_T S_idx_0;
  int32_T count;
  int32_T d_k;
  int32_T loop_ub;
  int32_T poses_0;
  int32_T tempMotionLength_data_tmp;
  boolean_T tmp[4];
  poses->size[0] = 0;
  poses->size[1] = 6;
  if ((!std::isnan(b_this_Length)) && (samples->size[1] != 0)) {
    tempStartPose_idx_2 = -b_this_StartPose[2];
    d_k = poses->size[0] * poses->size[1];
    poses->size[0] = samples->size[1];
    poses->size[1] = 6;
    codegenReal2Mission_emxEnsureCapacity_real_T(poses, d_k);
    loop_ub = samples->size[1] * 6 - 1;
    for (d_k = 0; d_k <= loop_ub; d_k++) {
      poses->data[d_k] = 0.0;
    }

    b_b_tmp = std::cos(std::abs(b_this_FlightPathAngle));
    d_k = samples->size[0] * samples->size[1];
    samples->size[0] = 1;
    codegenReal2Mission_emxEnsureCapacity_real_T(samples, d_k);
    loop_ub = samples->size[1] - 1;
    for (d_k = 0; d_k <= loop_ub; d_k++) {
      samples->data[d_k] *= b_b_tmp;
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
    codegenReal2Mission_strcmp_abl2(b_this_MotionTypes, tmp);
    if (codegenReal2Mission_any(tmp)) {
      tempMotionLength_size[0] = 1;
      tempMotionLength_size[1] = 3;
      tempMotionLength_data[0] = TransformMatrix[0];
      tempMotionLength_data[1] = TransformMatrix[1];
      tempMotionLength_data[2] = TransformMatrix[2];
    }

    codegenReal2Mission_useConstantDim(tempMotionLength_data,
      tempMotionLength_size, c_x_data, c_x_size);
    codegenReal2Mission_sort_k5(samples);
    intermediateLength = 0.0;
    startIndex = 1.0;
    state[0] = b_this_StartPose[0];
    state[1] = -b_this_StartPose[1];
    state[3] = -b_this_StartPose[3];
    poses_0 = 0;
    codegenReal2Mission_emxInit_boolean_T(&tempSamplesIndex, 2);
    codegenReal2Mission_emxInit_real_T1(&tempSamples, 1);
    codegenReal2Mission_emxInit_real_T1(&S, 1);
    codegenReal2Mission_emxInit_real_T(&ns, 2);
    codegenReal2Mission_emxInit_real_T1(&z, 1);
    codegenReal2Mission_emxInit_real_T(&p, 2);
    codegenReal2Mission_emxInit_real_T1(&e_x, 1);
    codegenReal2Mission_emxInit_int32_T(&ab, 2);
    codegenReal2Mission_emxInit_boolean_T(&tempSamplesIndex_0, 2);
    codegenReal2Mission_emxInit_real_T(&S_0, 2);
    while (poses_0 <= tempMotionLength_size[1] - 1) {
      if (poses_0 + 1 == 1) {
        d_k = tempSamplesIndex->size[0] * tempSamplesIndex->size[1];
        tempSamplesIndex->size[0] = 1;
        tempSamplesIndex->size[1] = samples->size[1];
        codegenReal2Mission_emxEnsureCapacity_boolean_T(tempSamplesIndex, d_k);
        loop_ub = samples->size[1] - 1;
        radius = (intermediateLength + tempMotionLength_data[0]) + 1.0E-6;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          samples_0 = samples->data[d_k];
          tempSamplesIndex->data[d_k] = ((samples_0 >= intermediateLength) &&
            (samples_0 <= radius));
        }
      } else {
        d_k = tempSamplesIndex->size[0] * tempSamplesIndex->size[1];
        tempSamplesIndex->size[0] = 1;
        tempSamplesIndex->size[1] = samples->size[1];
        codegenReal2Mission_emxEnsureCapacity_boolean_T(tempSamplesIndex, d_k);
        loop_ub = samples->size[1] - 1;
        radius = (intermediateLength + tempMotionLength_data[poses_0]) + 1.0E-6;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          samples_0 = samples->data[d_k];
          tempSamplesIndex->data[d_k] = ((samples_0 > intermediateLength) &&
            (samples_0 <= radius));
        }
      }

      d_k = tempSamplesIndex_0->size[0] * tempSamplesIndex_0->size[1];
      tempSamplesIndex_0->size[0] = 1;
      tempSamplesIndex_0->size[1] = tempSamplesIndex->size[1];
      codegenReal2Mission_emxEnsureCapacity_boolean_T(tempSamplesIndex_0, d_k);
      loop_ub = tempSamplesIndex->size[1];
      for (d_k = 0; d_k < loop_ub; d_k++) {
        tempSamplesIndex_0->data[d_k] = tempSamplesIndex->data[d_k];
      }

      codegenReal2Mission_eml_find_g(tempSamplesIndex_0, ab);
      if (!codegenReal2Mission_strcmp_ol2u(b_this_MotionTypes[poses_0].f1.data,
           b_this_MotionTypes[poses_0].f1.size)) {
        radius = b_this_MinTurningRadius;
        if (codegenReal2Mission_strcmp_ol2ud(b_this_MotionTypes[poses_0].f1.data,
             b_this_MotionTypes[poses_0].f1.size)) {
          radius = b_this_HelixRadius;
        } else if (codegenReal2Mission_strcmp_ol2udr(b_this_MotionTypes[poses_0]
                    .f1.data, b_this_MotionTypes[poses_0].f1.size)) {
          radius = b_this_HelixRadius;
        }

        count = 0;
        d_k = tempSamples->size[0];
        tempSamples->size[0] = 1;
        codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
        tempSamples->data[0] = 0.0;
        if (ab->size[1] != 0) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = ab->size[1] + 1;
          codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
          loop_ub = ab->size[1];
          for (d_k = 0; d_k <= loop_ub; d_k++) {
            tempSamples->data[d_k] = 0.0;
          }

          loop_ub = ab->size[1];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            tempSamples->data[d_k] = samples->data[ab->data[d_k] - 1];
          }

          count = ab->size[1];
          loop_ub = ab->size[1] - 1;
          for (d_k = 0; d_k <= loop_ub; d_k++) {
            samples->data[ab->data[d_k] - 1] = -1.0;
          }
        }

        tempSamples->data[count] = c_x_data[poses_0];
        d_k = S->size[0];
        S->size[0] = tempSamples->size[0];
        codegenReal2Mission_emxEnsureCapacity_real_T1(S, d_k);
        loop_ub = tempSamples->size[0];
        for (d_k = 0; d_k < loop_ub; d_k++) {
          S->data[d_k] = (tempSamples->data[d_k] - intermediateLength) / radius;
        }

        d_k = ns->size[0] * ns->size[1];
        ns->size[0] = S->size[0];
        ns->size[1] = 6;
        codegenReal2Mission_emxEnsureCapacity_real_T(ns, d_k);
        loop_ub = S->size[0] * 6 - 1;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          ns->data[d_k] = 0.0;
        }

        d_k = z->size[0];
        z->size[0] = tempSamples->size[0];
        codegenReal2Mission_emxEnsureCapacity_real_T1(z, d_k);
        loop_ub = tempSamples->size[0];
        for (d_k = 0; d_k < loop_ub; d_k++) {
          z->data[d_k] = tempStartPose_idx_2 + tempSamples->data[d_k];
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
          d_k = z->size[0];
          z->size[0] = tempSamples->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(z, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            z->data[d_k] = tempSamples->data[d_k] / TransformMatrix_tmp *
              samples_0 + tempStartPose_idx_2;
          }
        }

        if (codegenReal2Mission_strcmp_ol2ud(b_this_MotionTypes[poses_0].f1.data,
             b_this_MotionTypes[poses_0].f1.size) ||
            codegenReal2Mission_strcmp_ol2udrg(b_this_MotionTypes[poses_0].
             f1.data, b_this_MotionTypes[poses_0].f1.size)) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = S->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            tempSamples->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < S->size[0]; d_k++) {
            tempSamples->data[d_k] = std::sin(tempSamples->data[d_k]);
          }

          d_k = e_x->size[0];
          e_x->size[0] = S->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(e_x, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            e_x->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < S->size[0]; d_k++) {
            e_x->data[d_k] = std::cos(e_x->data[d_k]);
          }

          d_k = S_0->size[0] * S_0->size[1];
          S_0->size[0] = tempSamples->size[0];
          S_0->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S_0, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k] = tempSamples->data[d_k];
          }

          loop_ub = e_x->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k + tempSamples->size[0]] = 1.0 - e_x->data[d_k];
          }

          codegenReal2Mission_mtimes(S_0, TransformMatrix, p);
          e_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          state_0 = state[3];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          loop_ub = p->size[0];
          d_k = ns->size[0] * ns->size[1];
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          codegenReal2Mission_emxEnsureCapacity_real_T(ns, d_k);
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[d_k + ns->size[0]] = p->data[d_k + p->size[0]] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + (ns->size[0] << 1)] = z->data[d_k];
          }

          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + ns->size[0] * 3] = state_0 + S->data[d_k];
          }

          for (d_k = 0; d_k < count; d_k++) {
            ns->data[d_k + (ns->size[0] << 2)] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k < tempMotionLength_data_tmp; d_k++) {
            ns->data[d_k + ns->size[0] * 5] = -e_b;
          }
        } else if (codegenReal2Mission_strcmp_ol2udr(b_this_MotionTypes[poses_0]
                    .f1.data, b_this_MotionTypes[poses_0].f1.size) ||
                   codegenReal2Mission_strcmp_ol2udrgv
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = S->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            tempSamples->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < S->size[0]; d_k++) {
            tempSamples->data[d_k] = std::sin(tempSamples->data[d_k]);
          }

          d_k = e_x->size[0];
          e_x->size[0] = S->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(e_x, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            e_x->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < S->size[0]; d_k++) {
            e_x->data[d_k] = std::cos(e_x->data[d_k]);
          }

          d_k = S_0->size[0] * S_0->size[1];
          S_0->size[0] = tempSamples->size[0];
          S_0->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S_0, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k] = tempSamples->data[d_k];
          }

          loop_ub = e_x->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k + tempSamples->size[0]] = e_x->data[d_k] - 1.0;
          }

          codegenReal2Mission_mtimes(S_0, TransformMatrix, p);
          e_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          state_0 = state[3];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          loop_ub = p->size[0];
          d_k = ns->size[0] * ns->size[1];
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          codegenReal2Mission_emxEnsureCapacity_real_T(ns, d_k);
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[d_k + ns->size[0]] = p->data[d_k + p->size[0]] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + (ns->size[0] << 1)] = z->data[d_k];
          }

          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + ns->size[0] * 3] = state_0 - S->data[d_k];
          }

          for (d_k = 0; d_k < count; d_k++) {
            ns->data[d_k + (ns->size[0] << 2)] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k < tempMotionLength_data_tmp; d_k++) {
            ns->data[d_k + ns->size[0] * 5] = e_b;
          }
        } else if (codegenReal2Mission_strcmp_ol2udrgv2
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          count = S->size[0];
          d_k = S_0->size[0] * S_0->size[1];
          S_0->size[0] = S->size[0];
          S_0->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S_0, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < count; d_k++) {
            S_0->data[d_k + S->size[0]] = 0.0;
          }

          codegenReal2Mission_mtimes(S_0, TransformMatrix, p);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          S_idx_0 = S->size[0];
          loop_ub = p->size[0];
          d_k = ns->size[0] * ns->size[1];
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          codegenReal2Mission_emxEnsureCapacity_real_T(ns, d_k);
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[d_k + ns->size[0]] = p->data[d_k + p->size[0]] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + (ns->size[0] << 1)] = z->data[d_k];
          }

          for (d_k = 0; d_k < count; d_k++) {
            ns->data[d_k + ns->size[0] * 3] = state[3];
          }

          for (d_k = 0; d_k < tempMotionLength_data_tmp; d_k++) {
            ns->data[d_k + (ns->size[0] << 2)] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k < S_idx_0; d_k++) {
            ns->data[d_k + ns->size[0] * 5] = 0.0;
          }
        }

        if (ab->size[1] != 0) {
          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k < 6; d_k++) {
            for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                 loop_ub; tempMotionLength_data_tmp++) {
              poses->data[((count + tempMotionLength_data_tmp) + poses->size[0] *
                           d_k) - 1] = ns->data[tempMotionLength_data_tmp +
                ns->size[0] * d_k];
            }
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[(count + d_k) - 1] = ns->data[d_k];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[((count + d_k) + poses->size[0]) - 1] = -ns->data[d_k +
              ns->size[0]];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[((count + d_k) + (poses->size[0] << 1)) - 1] = -ns->
              data[d_k + (ns->size[0] << 1)];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[((count + d_k) + poses->size[0] * 3) - 1] = -ns->
              data[d_k + ns->size[0] * 3];
          }
        }

        count = ns->size[0];
        for (d_k = 0; d_k < 6; d_k++) {
          state[d_k] = ns->data[(count + ns->size[0] * d_k) - 1];
        }

        startIndex += static_cast<real_T>(ab->size[1]);
      }

      intermediateLength += tempMotionLength_data[poses_0];
      poses_0++;
    }

    codegenReal2Mission_emxFree_real_T(&S_0);
    codegenReal2Mission_emxFree_boolean_T(&tempSamplesIndex_0);
    codegenReal2Mission_emxFree_int32_T(&ab);
    codegenReal2Mission_emxFree_real_T(&e_x);
    codegenReal2Mission_emxFree_real_T(&p);
    codegenReal2Mission_emxFree_real_T(&z);
    codegenReal2Mission_emxFree_real_T(&ns);
    codegenReal2Mission_emxFree_real_T(&S);
    codegenReal2Mission_emxFree_boolean_T(&tempSamplesIndex);
    loop_ub = poses->size[0];
    d_k = tempSamples->size[0];
    tempSamples->size[0] = poses->size[0];
    codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
    for (d_k = 0; d_k < loop_ub; d_k++) {
      tempSamples->data[d_k] = poses->data[d_k + poses->size[0] * 3];
    }

    codegenReal2Mission_wrapToPi(tempSamples);
    loop_ub = tempSamples->size[0];
    for (d_k = 0; d_k < loop_ub; d_k++) {
      poses->data[d_k + poses->size[0] * 3] = tempSamples->data[d_k];
    }

    codegenReal2Mission_emxFree_real_T(&tempSamples);
  }
}

// Function for MATLAB Function: '<S102>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_genSegWP_i(const
  uavDubinsConnection_codegenReal2Mission_T *connectionObj, const real_T start[4],
  const real_T ende[4], real_T b_stepSize, emxArray_real_T_codegenReal2Mission_T
  *segWayPoints)
{
  emxArray_real_T_codegenReal2Mission_T *lengths;
  emxArray_real_T_codegenReal2Mission_T *poses;
  real_T a__1_data[28];
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T realStepSize;
  int32_T a__1_size;
  int32_T k;
  int32_T nm1d2;
  boolean_T guard1{ false };

  codegenReal2Mission_uavDubinsConnection_connect_f(connectionObj, start, ende,
    codegenReal2Mission_B.pathSegObj_l.data,
    &codegenReal2Mission_B.pathSegObj_l.size, a__1_data, &a__1_size);
  realStepSize = codegenReal2Mission_B.pathSegObj_l.data[0].Length / std::round
    (codegenReal2Mission_B.pathSegObj_l.data[0].Length / b_stepSize);
  codegenReal2Mission_emxInit_real_T(&lengths, 2);
  if (std::isnan(realStepSize)) {
    nm1d2 = lengths->size[0] * lengths->size[1];
    lengths->size[0] = 1;
    lengths->size[1] = 1;
    codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
    lengths->data[0] = (rtNaN);
  } else if (std::isnan(codegenReal2Mission_B.pathSegObj_l.data[0].Length)) {
    nm1d2 = lengths->size[0] * lengths->size[1];
    lengths->size[0] = 1;
    lengths->size[1] = 1;
    codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
    lengths->data[0] = (rtNaN);
  } else if (realStepSize == 0.0) {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else if ((0.0 < codegenReal2Mission_B.pathSegObj_l.data[0].Length) &&
             (realStepSize < 0.0)) {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else if ((codegenReal2Mission_B.pathSegObj_l.data[0].Length < 0.0) &&
             (realStepSize > 0.0)) {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else {
    guard1 = false;
    if (std::isinf(codegenReal2Mission_B.pathSegObj_l.data[0].Length)) {
      if (std::isinf(realStepSize)) {
        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
      } else if (0.0 == codegenReal2Mission_B.pathSegObj_l.data[0].Length) {
        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (std::isinf(realStepSize)) {
        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        lengths->data[0] = 0.0;
      } else if (std::floor(realStepSize) == realStepSize) {
        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        k = static_cast<int32_T>(std::floor
          (codegenReal2Mission_B.pathSegObj_l.data[0].Length / realStepSize));
        lengths->size[1] = k + 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        for (a__1_size = 0; a__1_size <= k; a__1_size++) {
          lengths->data[a__1_size] = realStepSize * static_cast<real_T>
            (a__1_size);
        }
      } else {
        ndbl = std::floor(codegenReal2Mission_B.pathSegObj_l.data[0].Length /
                          realStepSize + 0.5);
        apnd = ndbl * realStepSize;
        if (realStepSize > 0.0) {
          cdiff = apnd - codegenReal2Mission_B.pathSegObj_l.data[0].Length;
        } else {
          cdiff = codegenReal2Mission_B.pathSegObj_l.data[0].Length - apnd;
        }

        if (std::abs(cdiff) < 4.4408920985006262E-16 * std::abs
            (codegenReal2Mission_B.pathSegObj_l.data[0].Length)) {
          ndbl++;
          apnd = codegenReal2Mission_B.pathSegObj_l.data[0].Length;
        } else if (cdiff > 0.0) {
          apnd = (ndbl - 1.0) * realStepSize;
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          a__1_size = static_cast<int32_T>(ndbl) - 1;
        } else {
          a__1_size = -1;
        }

        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        lengths->size[1] = a__1_size + 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        if (a__1_size + 1 > 0) {
          lengths->data[0] = 0.0;
          if (a__1_size + 1 > 1) {
            lengths->data[a__1_size] = apnd;
            nm1d2 = a__1_size / 2;
            for (k = 1; k - 1 <= nm1d2 - 2; k++) {
              ndbl = static_cast<real_T>(k) * realStepSize;
              lengths->data[k] = ndbl;
              lengths->data[a__1_size - k] = apnd - ndbl;
            }

            if (nm1d2 << 1 == a__1_size) {
              lengths->data[nm1d2] = apnd / 2.0;
            } else {
              ndbl = static_cast<real_T>(nm1d2) * realStepSize;
              lengths->data[nm1d2] = ndbl;
              lengths->data[nm1d2 + 1] = apnd - ndbl;
            }
          }
        }
      }
    }
  }

  codegenReal2Mission_emxInit_real_T(&poses, 2);
  codegenReal2Mission_uavDubinsPathSegment_interpolate_d
    (codegenReal2Mission_B.pathSegObj_l.data[0].StartPose,
     codegenReal2Mission_B.pathSegObj_l.data[0].GoalPose,
     codegenReal2Mission_B.pathSegObj_l.data[0].FlightPathAngle,
     codegenReal2Mission_B.pathSegObj_l.data[0].AirSpeed,
     codegenReal2Mission_B.pathSegObj_l.data[0].MinTurningRadius,
     codegenReal2Mission_B.pathSegObj_l.data[0].HelixRadius,
     codegenReal2Mission_B.pathSegObj_l.data[0].MotionTypes,
     codegenReal2Mission_B.pathSegObj_l.data[0].MotionLengths,
     codegenReal2Mission_B.pathSegObj_l.data[0].Length, lengths, poses);
  k = poses->size[0];
  nm1d2 = segWayPoints->size[0] * segWayPoints->size[1];
  segWayPoints->size[0] = poses->size[0];
  segWayPoints->size[1] = 3;
  codegenReal2Mission_emxEnsureCapacity_real_T(segWayPoints, nm1d2);
  codegenReal2Mission_emxFree_real_T(&lengths);
  for (a__1_size = 0; a__1_size < 3; a__1_size++) {
    for (nm1d2 = 0; nm1d2 < k; nm1d2++) {
      segWayPoints->data[nm1d2 + segWayPoints->size[0] * a__1_size] =
        poses->data[nm1d2 + poses->size[0] * a__1_size];
    }
  }

  codegenReal2Mission_emxFree_real_T(&poses);
}

void codegenReal2MissionModelClass::
  codegenReal2Mission_WaypointFollowerBase_getDistinctWpts(const real_T
  waypoints[30720], emxArray_real_T_codegenReal2Mission_T *distinctWpts)
{
  int32_T i1;
  int32_T i2;
  int32_T ix;
  int32_T j;
  int32_T x_tmp;
  boolean_T exitg1;
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < 10239; i2++) {
      x_tmp = 10240 * i1 + i2;
      codegenReal2Mission_B.x[x_tmp] = (waypoints[((i2 + 2) + 10240 * i1) - 1]
        != waypoints[x_tmp]);
    }

    codegenReal2Mission_B.x[10240 * i1 + 10239] = true;
  }

  i1 = 0;
  i2 = 20480;
  x_tmp = 0;
  for (j = 0; j < 10240; j++) {
    codegenReal2Mission_B.b[j] = false;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!codegenReal2Mission_B.x[ix - 1]) {
        ix += 10240;
      } else {
        codegenReal2Mission_B.b[j] = true;
        exitg1 = true;
      }
    }

    if (codegenReal2Mission_B.b[j]) {
      x_tmp++;
    }
  }

  i1 = 0;
  for (i2 = 0; i2 < 10240; i2++) {
    if (codegenReal2Mission_B.b[i2]) {
      codegenReal2Mission_B.c_data[i1] = static_cast<int16_T>(i2 + 1);
      i1++;
    }
  }

  i1 = distinctWpts->size[0] * distinctWpts->size[1];
  distinctWpts->size[0] = x_tmp;
  distinctWpts->size[1] = 3;
  codegenReal2Mission_emxEnsureCapacity_real_T(distinctWpts, i1);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < x_tmp; i2++) {
      distinctWpts->data[i2 + distinctWpts->size[0] * i1] = waypoints[(10240 *
        i1 + codegenReal2Mission_B.c_data[i2]) - 1];
    }
  }
}

real_T codegenReal2MissionModelClass::codegenReal2Mission_norm_b(const real_T x
  [3])
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

void codegenReal2MissionModelClass::
  codegenReal2Mission_WaypointFollowerBase_createWaypoint
  (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj, real_T
   virtualWaypoint[3])
{
  virtualWaypoint[0] = obj->InitialPose[0];
  virtualWaypoint[1] = obj->InitialPose[1];
  virtualWaypoint[2] = obj->InitialPose[2];
  obj->StartFlag = false;
}

void codegenReal2MissionModelClass::
  codegenReal2Mission_WaypointFollowerBase_getWaypoints
  (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj, const
   emxArray_real_T_codegenReal2Mission_T *waypoints, real_T startWaypoint[3],
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

  startWaypoint[0] = waypoints->data[static_cast<int32_T>(obj->WaypointIndex) -
    1];
  endWaypoint[0] = waypoints->data[static_cast<int32_T>(obj->WaypointIndex + 1.0)
    - 1];
  startWaypoint[1] = waypoints->data[(static_cast<int32_T>(obj->WaypointIndex) +
    waypoints->size[0]) - 1];
  endWaypoint[1] = waypoints->data[(static_cast<int32_T>(obj->WaypointIndex +
    1.0) + waypoints->size[0]) - 1];
  startWaypoint[2] = waypoints->data[(static_cast<int32_T>(obj->WaypointIndex) +
    (waypoints->size[0] << 1)) - 1];
  endWaypoint[2] = waypoints->data[(static_cast<int32_T>(obj->WaypointIndex +
    1.0) + (waypoints->size[0] << 1)) - 1];
}

void codegenReal2MissionModelClass::
  codegenReal2Mission_WaypointFollowerBase_endWaypointReached_brd
  (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj, const
   emxArray_real_T_codegenReal2Mission_T *waypoints, real_T curStartWaypoint[3],
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
  curEndWaypoint_1 = codegenReal2Mission_norm_b(tmp);
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
    tmp_0 = codegenReal2Mission_norm_b(curEndWaypoint_0);
    curEndWaypoint_1 = (curEndWaypoint_tmp / tmp_0 * (tmp[0] / curEndWaypoint_1)
                        + curEndWaypoint_tmp_0 / tmp_0 * (tmp[1] /
      curEndWaypoint_1)) + curEndWaypoint_tmp_1 / tmp_0 * (tmp[2] /
      curEndWaypoint_1);
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
      (obj->WaypointIndex) - 1];
    curEndWaypoint[0] = waypoints->data[static_cast<int32_T>(obj->WaypointIndex
      + 1.0) - 1];
    curStartWaypoint[1] = waypoints->data[(static_cast<int32_T>
      (obj->WaypointIndex) + waypoints->size[0]) - 1];
    curEndWaypoint[1] = waypoints->data[(static_cast<int32_T>(obj->WaypointIndex
      + 1.0) + waypoints->size[0]) - 1];
    curStartWaypoint[2] = waypoints->data[(static_cast<int32_T>
      (obj->WaypointIndex) + (waypoints->size[0] << 1)) - 1];
    curEndWaypoint[2] = waypoints->data[(static_cast<int32_T>(obj->WaypointIndex
      + 1.0) + (waypoints->size[0] << 1)) - 1];
  }
}

real_T codegenReal2MissionModelClass::
  codegenReal2Mission_WaypointFollowerBase_pointToLine(const real_T p1[3], const
  real_T p2[3], const real_T p[3])
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
    dist = codegenReal2Mission_norm_b(p_0);
  } else if (lambda > 1.0) {
    dist = codegenReal2Mission_norm_b(p_1);
  } else {
    dist = codegenReal2Mission_norm_b(p_2);
  }

  return dist;
}

real_T codegenReal2MissionModelClass::
  codegenReal2Mission_WaypointFollowerBase_projectToLine(const real_T
  startWaypoint[3], const real_T endWaypoint[3], const real_T currentPosition[3])
{
  real_T currentPosition_0[3];
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
    (lambda_tmp_tmp_1 * lambda_tmp_tmp_1 + (lambda_tmp_tmp_0 * lambda_tmp_tmp_0
      + lambda_tmp_tmp * lambda_tmp_tmp));
  currentPosition_0[0] = currentPosition[0] - (lambda * lambda_tmp_tmp +
    startWaypoint[0]);
  currentPosition_0[1] = currentPosition[1] - (lambda * lambda_tmp_tmp_0 +
    startWaypoint[1]);
  currentPosition_0[2] = currentPosition[2] - (lambda * lambda_tmp_tmp_1 +
    startWaypoint[2]);
  return codegenReal2Mission_norm_b(currentPosition_0);
}

void codegenReal2MissionModelClass::
  codegenReal2Mission_WaypointFollowerBase_getLookahead(const
  uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj, const
  real_T startWaypoint[3], const real_T endWaypoint[3], const real_T
  currentPosition[3], real_T lookaheadPoint[3])
{
  real_T a_tmp_tmp;
  real_T a_tmp_tmp_0;
  real_T b;
  real_T b_tmp_idx_0_tmp;
  real_T b_tmp_idx_1_tmp;
  real_T b_tmp_idx_2_tmp;
  real_T y;
  b = endWaypoint[0] - startWaypoint[0];
  b_tmp_idx_0_tmp = startWaypoint[0] - currentPosition[0];
  a_tmp_tmp = endWaypoint[1] - startWaypoint[1];
  b_tmp_idx_1_tmp = startWaypoint[1] - currentPosition[1];
  a_tmp_tmp_0 = endWaypoint[2] - startWaypoint[2];
  y = a_tmp_tmp_0 * a_tmp_tmp_0 + (a_tmp_tmp * a_tmp_tmp + b * b);
  b_tmp_idx_2_tmp = startWaypoint[2] - currentPosition[2];
  b = ((b * b_tmp_idx_0_tmp + a_tmp_tmp * b_tmp_idx_1_tmp) + a_tmp_tmp_0 *
       b_tmp_idx_2_tmp) * 2.0;
  b_tmp_idx_0_tmp = std::sqrt(b * b - (((b_tmp_idx_0_tmp * b_tmp_idx_0_tmp +
    b_tmp_idx_1_tmp * b_tmp_idx_1_tmp) + b_tmp_idx_2_tmp * b_tmp_idx_2_tmp) -
    obj->LookaheadDistance * obj->LookaheadDistance) * (4.0 * y));
  y = std::fmax((-b + b_tmp_idx_0_tmp) / 2.0 / y, (-b - b_tmp_idx_0_tmp) / 2.0 /
                y);
  lookaheadPoint[0] = (1.0 - y) * startWaypoint[0] + y * endWaypoint[0];
  lookaheadPoint[1] = (1.0 - y) * startWaypoint[1] + y * endWaypoint[1];
  lookaheadPoint[2] = (1.0 - y) * startWaypoint[2] + y * endWaypoint[2];
}

void codegenReal2MissionModelClass::
  codegenReal2Mission_WaypointFollowerBase_stepInternal
  (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj, const
   real_T currentPose[4], const real_T waypointsIn[30720], real_T lookaheadDist,
   real_T lookaheadPoint[3], real_T *desiredHeading, real_T *desiredYaw, uint8_T
   *lookaheadDistFlag, real_T *crossTrackError, uint8_T *status)
{
  emxArray_real_T_codegenReal2Mission_T *b_waypointsIn;
  emxArray_real_T_codegenReal2Mission_T *waypoints;
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
    codegenReal2Mission_B.paddedWaypts[b_k] = (rtNaN);
  }

  for (b_k = 0; b_k < 3; b_k++) {
    for (loop_ub = 0; loop_ub < 10240; loop_ub++) {
      codegenReal2Mission_B.paddedWaypts[((loop_ub + 1) + 10240 * b_k) - 1] =
        waypointsIn[10240 * b_k + loop_ub];
    }
  }

  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 30720)) {
    if ((obj->WaypointsInternal[b_k] == codegenReal2Mission_B.paddedWaypts[b_k])
        || (std::isnan(obj->WaypointsInternal[b_k]) && std::isnan
            (codegenReal2Mission_B.paddedWaypts[b_k]))) {
      b_k++;
    } else {
      p_0 = false;
      exitg1 = true;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    std::memcpy(&obj->WaypointsInternal[0], &codegenReal2Mission_B.paddedWaypts
                [0], 30720U * sizeof(real_T));
    obj->WaypointIndex = 1.0;
  }

  codegenReal2Mission_emxInit_real_T(&b_waypointsIn, 2);
  codegenReal2Mission_WaypointFollowerBase_getDistinctWpts(waypointsIn,
    b_waypointsIn);
  obj->NumWaypoints = b_waypointsIn->size[0];
  obj->LookaheadDistance = lookaheadDist;
  codegenReal2Mission_emxInit_real_T(&waypoints, 2);
  if (b_waypointsIn->size[0] == 0) {
    lookaheadPoint[0] = lookaheadDist * std::cos(currentPose[3]) + currentPose[0];
    lookaheadPoint[1] = lookaheadDist * std::sin(currentPose[3]) + currentPose[1];
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
      if (codegenReal2Mission_norm_b(virtualWaypoint) < 1.4901161193847656E-8) {
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
        codegenReal2Mission_WaypointFollowerBase_createWaypoint(obj,
          virtualWaypoint);
        for (b_k = 0; b_k < 3; b_k++) {
          appendedWaypoints_data[b_k << 1] = virtualWaypoint[b_k];
          appendedWaypoints_data[1 + (b_k << 1)] = b_waypointsIn->
            data[b_waypointsIn->size[0] * b_k];
        }

        obj->NumWaypoints = 2.0;
        b_k = waypoints->size[0] * waypoints->size[1];
        waypoints->size[0] = 2;
        waypoints->size[1] = 3;
        codegenReal2Mission_emxEnsureCapacity_real_T(waypoints, b_k);
        for (b_k = 0; b_k < 6; b_k++) {
          waypoints->data[b_k] = appendedWaypoints_data[b_k];
        }

        guard1 = true;
      }
    } else {
      b_k = waypoints->size[0] * waypoints->size[1];
      waypoints->size[0] = b_waypointsIn->size[0];
      waypoints->size[1] = 3;
      codegenReal2Mission_emxEnsureCapacity_real_T(waypoints, b_k);
      loop_ub = b_waypointsIn->size[0] * 3;
      for (b_k = 0; b_k < loop_ub; b_k++) {
        waypoints->data[b_k] = b_waypointsIn->data[b_k];
      }

      guard1 = true;
    }

    if (guard1) {
      codegenReal2Mission_WaypointFollowerBase_getWaypoints(obj, waypoints,
        virtualWaypoint, endWaypoint);
      codegenReal2Mission_WaypointFollowerBase_endWaypointReached_brd(obj,
        waypoints, virtualWaypoint, endWaypoint, currentPose);
      *crossTrackError = codegenReal2Mission_WaypointFollowerBase_pointToLine
        (virtualWaypoint, endWaypoint, &currentPose[0]);
      if (obj->LastWaypointFlag) {
        *crossTrackError =
          codegenReal2Mission_WaypointFollowerBase_projectToLine(virtualWaypoint,
          endWaypoint, &currentPose[0]);
      }

      absx_tmp = std::abs(*crossTrackError);
      if ((!std::isinf(absx_tmp)) && (!std::isnan(absx_tmp))) {
        if (absx_tmp <= 2.2250738585072014E-308) {
          r = 4.94065645841247E-324;
          absx_tmp = 4.94065645841247E-324;
        } else {
          frexp(absx_tmp, &b_exponent);
          r = std::ldexp(1.0, b_exponent - 53);
          frexp(absx_tmp, &b_exponent_0);
          absx_tmp = std::ldexp(1.0, b_exponent_0 - 53);
        }
      } else {
        r = (rtNaN);
        absx_tmp = (rtNaN);
      }

      if (obj->LookaheadDistance <= std::fmax(std::sqrt(r), 5.0 * absx_tmp) +
          *crossTrackError) {
        obj->LookaheadDistance = obj->LookaheadFactor * *crossTrackError;
      }

      codegenReal2Mission_WaypointFollowerBase_getLookahead(obj, virtualWaypoint,
        endWaypoint, &currentPose[0], lookaheadPoint);
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

  codegenReal2Mission_emxFree_real_T(&b_waypointsIn);
  codegenReal2Mission_emxFree_real_T(&waypoints);
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_repmat(const
  emxArray_real_T_codegenReal2Mission_T *a, real_T varargin_1,
  emxArray_real_T_codegenReal2Mission_T *b)
{
  int32_T iacol;
  int32_T ibcol;
  int32_T ibmat;
  int32_T itilerow;
  int32_T k;
  int32_T nrows;
  nrows = b->size[0] * b->size[1];
  b->size[0] = a->size[0] * static_cast<int32_T>(varargin_1);
  b->size[1] = 3;
  codegenReal2Mission_emxEnsureCapacity_real_T(b, nrows);
  nrows = a->size[0];
  for (itilerow = 0; itilerow < static_cast<int32_T>(varargin_1); itilerow++) {
    ibcol = itilerow * nrows + -1;
    for (k = 1; k - 1 < nrows; k++) {
      b->data[ibcol + k] = a->data[k - 1];
    }
  }

  ibmat = a->size[0] * static_cast<int32_T>(varargin_1) - 1;
  for (itilerow = 0; itilerow < static_cast<int32_T>(varargin_1); itilerow++) {
    ibcol = itilerow * nrows + ibmat;
    for (k = 1; k - 1 < nrows; k++) {
      b->data[ibcol + k] = a->data[(nrows + k) - 1];
    }
  }

  iacol = a->size[0] << 1;
  ibmat = ((a->size[0] * static_cast<int32_T>(varargin_1)) << 1) - 1;
  for (itilerow = 0; itilerow < static_cast<int32_T>(varargin_1); itilerow++) {
    ibcol = itilerow * nrows + ibmat;
    for (k = 1; k - 1 < nrows; k++) {
      b->data[ibcol + k] = a->data[(iacol + k) - 1];
    }
  }
}

real_T codegenReal2MissionModelClass::codegenReal2Mission_norm(const real_T x[2])
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

real_T codegenReal2MissionModelClass::codegenReal2Mission_angdiff(real_T x,
  real_T y)
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
      if (!rEQ0) {
        q = std::abs((delta + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (delta + 3.1415926535897931 < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }

    if ((thetaWrap == 0.0) && (delta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    delta = thetaWrap - 3.1415926535897931;
  }

  return delta;
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
uavDubinsConnection_codegenReal2Mission_T *codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsConnection_uavDubinsConnection
  (uavDubinsConnection_codegenReal2Mission_T *b_this)
{
  uavDubinsConnection_codegenReal2Mission_T *c_this;
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

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsPathSegment_uavDubinsPathSegment_a(const real_T
  varargin_1[4], const real_T varargin_2[4], real_T varargin_3, real_T
  varargin_4, real_T varargin_5, real_T varargin_6, const
  cell_wrap_1_codegenReal2Mission_T varargin_7[4], const real_T varargin_8[4],
  uavDubinsPathSegment_codegenReal2Mission_T *b_this)
{
  static const char_T d[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A',
    'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
    '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '{', '|', '}',
    '~', '\x7f' };

  real_T thetaWrap;
  int32_T k;
  b_this->MinTurningRadius = varargin_5;
  b_this->StartPose[0] = varargin_1[0];
  b_this->StartPose[1] = varargin_1[1];
  b_this->StartPose[2] = varargin_1[2];
  thetaWrap = mod_dBqh4Vat(varargin_1[3]);
  b_this->StartPose[3] = thetaWrap;
  if ((thetaWrap == 0.0) && (varargin_1[3] > 0.0)) {
    b_this->StartPose[3] = 6.2831853071795862;
  }

  wrapToPi_iEuDNbvh(&b_this->StartPose[3]);
  b_this->GoalPose[0] = varargin_2[0];
  b_this->GoalPose[1] = varargin_2[1];
  b_this->GoalPose[2] = varargin_2[2];
  thetaWrap = mod_dBqh4Vat(varargin_2[3]);
  b_this->GoalPose[3] = thetaWrap;
  if ((thetaWrap == 0.0) && (varargin_2[3] > 0.0)) {
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
  for (k = 0; k < varargin_7[0].f1.size[1]; k++) {
    b_this->MotionTypes[0].f1.data[k] = d[static_cast<uint8_T>(varargin_7[0].
      f1.data[k])];
  }

  b_this->MotionTypes[1].f1.size[0] = 1;
  b_this->MotionTypes[1].f1.size[1] = 1;
  b_this->MotionTypes[1].f1.data[0] = d[static_cast<uint8_T>(varargin_7[1].
    f1.data[0]) & 127];
  b_this->MotionTypes[2].f1.size[0] = 1;
  b_this->MotionTypes[2].f1.size[1] = 1;
  b_this->MotionTypes[2].f1.data[0] = d[static_cast<uint8_T>(varargin_7[2].
    f1.data[0]) & 127];
  b_this->MotionTypes[3].f1.size[0] = 1;
  b_this->MotionTypes[3].f1.size[1] = varargin_7[3].f1.size[1];
  for (k = 0; k < varargin_7[3].f1.size[1]; k++) {
    b_this->MotionTypes[3].f1.data[k] = d[static_cast<uint8_T>(varargin_7[3].
      f1.data[k])];
  }

  if (codegenReal2Mission_strcmp_o(b_this->MotionTypes[0].f1.data,
       b_this->MotionTypes[0].f1.size)) {
    b_this->MotionTypes[0].f1.size[0] = 1;
    b_this->MotionTypes[0].f1.size[1] = 2;
    b_this->MotionTypes[0].f1.data[0] = 'H';
    b_this->MotionTypes[0].f1.data[1] = 'l';
  } else if (codegenReal2Mission_strcmp_ol(b_this->MotionTypes[0].f1.data,
              b_this->MotionTypes[0].f1.size)) {
    b_this->MotionTypes[0].f1.size[0] = 1;
    b_this->MotionTypes[0].f1.size[1] = 2;
    b_this->MotionTypes[0].f1.data[0] = 'H';
    b_this->MotionTypes[0].f1.data[1] = 'r';
  } else if (codegenReal2Mission_strcmp_ol(b_this->MotionTypes[3].f1.data,
              b_this->MotionTypes[3].f1.size)) {
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = 2;
    b_this->MotionTypes[3].f1.data[0] = 'H';
    b_this->MotionTypes[3].f1.data[1] = 'r';
  } else if (codegenReal2Mission_strcmp_o(b_this->MotionTypes[3].f1.data,
              b_this->MotionTypes[3].f1.size)) {
    b_this->MotionTypes[3].f1.size[0] = 1;
    b_this->MotionTypes[3].f1.size[1] = 2;
    b_this->MotionTypes[3].f1.data[0] = 'H';
    b_this->MotionTypes[3].f1.data[1] = 'l';
  }

  b_this->Length = ((varargin_8[0] + varargin_8[1]) + varargin_8[2]) +
    varargin_8[3];
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsBuiltins_connect(const
  uavDubinsConnection_codegenReal2Mission_T *obj, const real_T startPose[4],
  const real_T goalPose[4], boolean_T flagOptimal, real_T turningRadius, const
  real_T dpt_data[], const int32_T *dpt_size,
  uavDubinsPathSegment_codegenReal2Mission_T pathSegObjs_data[], int32_T
  *pathSegObjs_size, real_T pathCosts_data[], int32_T *pathCosts_size)
{
  void* buildableObj_UAVDubinsBuildableObj;
  cell_wrap_1_codegenReal2Mission_T m[4];
  cell_wrap_1_codegenReal2Mission_T ac;
  cell_wrap_1_codegenReal2Mission_T ad;
  cell_wrap_1_codegenReal2Mission_T ae;
  cell_wrap_1_codegenReal2Mission_T af;
  cell_wrap_1_codegenReal2Mission_T bc;
  cell_wrap_1_codegenReal2Mission_T bd;
  cell_wrap_1_codegenReal2Mission_T be;
  cell_wrap_1_codegenReal2Mission_T bf;
  cell_wrap_1_codegenReal2Mission_T cc;
  cell_wrap_1_codegenReal2Mission_T cd;
  cell_wrap_1_codegenReal2Mission_T ce;
  cell_wrap_1_codegenReal2Mission_T cf;
  cell_wrap_1_codegenReal2Mission_T dc;
  cell_wrap_1_codegenReal2Mission_T dd;
  cell_wrap_1_codegenReal2Mission_T de;
  cell_wrap_1_codegenReal2Mission_T df;
  cell_wrap_1_codegenReal2Mission_T ec;
  cell_wrap_1_codegenReal2Mission_T ed;
  cell_wrap_1_codegenReal2Mission_T ee;
  cell_wrap_1_codegenReal2Mission_T ef;
  cell_wrap_1_codegenReal2Mission_T fc;
  cell_wrap_1_codegenReal2Mission_T fd;
  cell_wrap_1_codegenReal2Mission_T fe;
  cell_wrap_1_codegenReal2Mission_T ff;
  cell_wrap_1_codegenReal2Mission_T gc;
  cell_wrap_1_codegenReal2Mission_T gd;
  cell_wrap_1_codegenReal2Mission_T ge;
  cell_wrap_1_codegenReal2Mission_T gf;
  cell_wrap_1_codegenReal2Mission_T hc;
  cell_wrap_1_codegenReal2Mission_T hd;
  cell_wrap_1_codegenReal2Mission_T he;
  cell_wrap_1_codegenReal2Mission_T hf;
  cell_wrap_1_codegenReal2Mission_T ic;
  cell_wrap_1_codegenReal2Mission_T id;
  cell_wrap_1_codegenReal2Mission_T ie;
  cell_wrap_1_codegenReal2Mission_T jc;
  cell_wrap_1_codegenReal2Mission_T jd;
  cell_wrap_1_codegenReal2Mission_T je;
  cell_wrap_1_codegenReal2Mission_T jf;
  cell_wrap_1_codegenReal2Mission_T kb;
  cell_wrap_1_codegenReal2Mission_T kc;
  cell_wrap_1_codegenReal2Mission_T kd;
  cell_wrap_1_codegenReal2Mission_T ke;
  cell_wrap_1_codegenReal2Mission_T kf;
  cell_wrap_1_codegenReal2Mission_T lb;
  cell_wrap_1_codegenReal2Mission_T lc;
  cell_wrap_1_codegenReal2Mission_T ld;
  cell_wrap_1_codegenReal2Mission_T le;
  cell_wrap_1_codegenReal2Mission_T lf;
  cell_wrap_1_codegenReal2Mission_T mb;
  cell_wrap_1_codegenReal2Mission_T mc;
  cell_wrap_1_codegenReal2Mission_T md;
  cell_wrap_1_codegenReal2Mission_T me;
  cell_wrap_1_codegenReal2Mission_T mf;
  cell_wrap_1_codegenReal2Mission_T nb;
  cell_wrap_1_codegenReal2Mission_T nc;
  cell_wrap_1_codegenReal2Mission_T nd;
  cell_wrap_1_codegenReal2Mission_T ne;
  cell_wrap_1_codegenReal2Mission_T nf;
  cell_wrap_1_codegenReal2Mission_T ob;
  cell_wrap_1_codegenReal2Mission_T oc;
  cell_wrap_1_codegenReal2Mission_T od;
  cell_wrap_1_codegenReal2Mission_T oe;
  cell_wrap_1_codegenReal2Mission_T of;
  cell_wrap_1_codegenReal2Mission_T pb;
  cell_wrap_1_codegenReal2Mission_T pc;
  cell_wrap_1_codegenReal2Mission_T pd;
  cell_wrap_1_codegenReal2Mission_T pe;
  cell_wrap_1_codegenReal2Mission_T pf;
  cell_wrap_1_codegenReal2Mission_T qb;
  cell_wrap_1_codegenReal2Mission_T qc;
  cell_wrap_1_codegenReal2Mission_T qd;
  cell_wrap_1_codegenReal2Mission_T qe;
  cell_wrap_1_codegenReal2Mission_T qf;
  cell_wrap_1_codegenReal2Mission_T rb;
  cell_wrap_1_codegenReal2Mission_T rc;
  cell_wrap_1_codegenReal2Mission_T rd;
  cell_wrap_1_codegenReal2Mission_T re;
  cell_wrap_1_codegenReal2Mission_T rf;
  cell_wrap_1_codegenReal2Mission_T sb;
  cell_wrap_1_codegenReal2Mission_T sc;
  cell_wrap_1_codegenReal2Mission_T sd;
  cell_wrap_1_codegenReal2Mission_T se;
  cell_wrap_1_codegenReal2Mission_T sf;
  cell_wrap_1_codegenReal2Mission_T tb;
  cell_wrap_1_codegenReal2Mission_T tc;
  cell_wrap_1_codegenReal2Mission_T td;
  cell_wrap_1_codegenReal2Mission_T te;
  cell_wrap_1_codegenReal2Mission_T tf;
  cell_wrap_1_codegenReal2Mission_T ub;
  cell_wrap_1_codegenReal2Mission_T uc;
  cell_wrap_1_codegenReal2Mission_T ud;
  cell_wrap_1_codegenReal2Mission_T ue;
  cell_wrap_1_codegenReal2Mission_T uf;
  cell_wrap_1_codegenReal2Mission_T vb;
  cell_wrap_1_codegenReal2Mission_T vc;
  cell_wrap_1_codegenReal2Mission_T vd;
  cell_wrap_1_codegenReal2Mission_T ve;
  cell_wrap_1_codegenReal2Mission_T vf;
  cell_wrap_1_codegenReal2Mission_T wb;
  cell_wrap_1_codegenReal2Mission_T wc;
  cell_wrap_1_codegenReal2Mission_T wd;
  cell_wrap_1_codegenReal2Mission_T we;
  cell_wrap_1_codegenReal2Mission_T wf;
  cell_wrap_1_codegenReal2Mission_T xb;
  cell_wrap_1_codegenReal2Mission_T xc;
  cell_wrap_1_codegenReal2Mission_T xd;
  cell_wrap_1_codegenReal2Mission_T xe;
  cell_wrap_1_codegenReal2Mission_T yb;
  cell_wrap_1_codegenReal2Mission_T yc;
  cell_wrap_1_codegenReal2Mission_T yd;
  cell_wrap_1_codegenReal2Mission_T ye;
  emxArray_real_T_codegenReal2Mission_T *g;
  emxArray_real_T_codegenReal2Mission_T *g1;
  emxArray_real_T_codegenReal2Mission_T *g_0;
  emxArray_real_T_codegenReal2Mission_T *ml;
  emxArray_real_T_codegenReal2Mission_T *ml1;
  emxArray_real_T_codegenReal2Mission_T *s;
  emxArray_real_T_codegenReal2Mission_T *s1;
  real_T b_goalPose[4];
  real_T b_startPose[4];
  real_T ml1_0[4];
  real_T ml1_data[4];
  real_T l;
  real_T ml1_tmp;
  int32_T b_nRows;
  int32_T loop_ub;
  int32_T mt;
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
    codegenReal2Mission_uavDubinsBuildable_uavDubinsBuildable(obj->AirSpeed,
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
  if (!flagOptimal) {
    b_nRows = 28;
  }

  codegenReal2Mission_emxInit_real_T(&s, 2);
  codegenReal2Mission_emxInit_real_T(&g, 2);
  codegenReal2Mission_emxInit_real_T(&ml, 2);
  xf_tmp = b_nRows << 2;
  mt = s->size[0] * s->size[1];
  s->size[0] = xf_tmp;
  s->size[1] = xf_tmp;
  codegenReal2Mission_emxEnsureCapacity_real_T(s, mt);
  mt = g->size[0] * g->size[1];
  g->size[0] = xf_tmp;
  g->size[1] = xf_tmp;
  codegenReal2Mission_emxEnsureCapacity_real_T(g, mt);
  mt_size_idx_0 = b_nRows;
  mt = ml->size[0] * ml->size[1];
  ml->size[0] = xf_tmp;
  ml->size[1] = xf_tmp;
  codegenReal2Mission_emxEnsureCapacity_real_T(ml, mt);
  uavDubinsDistanceCodegen_real64(buildableObj_UAVDubinsBuildableObj,
    &b_startPose[0], 1U, &b_goalPose[0], 1U, flagOptimal, turningRadius,
    &s->data[0], &g->data[0], &codegenReal2Mission_B.b_fpa_data[0],
    &codegenReal2Mission_B.b_a_data[0], &codegenReal2Mission_B.mtr_data[0],
    &codegenReal2Mission_B.h_data[0], &codegenReal2Mission_B.mt_data[0],
    &ml->data[0]);
  b_nRows = 0;
  if (!flagOptimal) {
    b_nRows = 27;
  }

  codegenReal2Mission_emxInit_real_T(&g1, 2);
  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>
    (s->size[0] * s->size[1]) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = g1->size[0] * g1->size[1];
  g1->size[0] = num_idx_1;
  g1->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(g1, mt);
  loop_ub = num_idx_1;
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt < loop_ub; mt++) {
      g1->data[mt + g1->size[0] * xf_tmp] = s->data[xf_tmp + tmp[0] * mt];
    }
  }

  codegenReal2Mission_emxFree_real_T(&s);
  codegenReal2Mission_emxInit_real_T(&s1, 2);
  mt = s1->size[0] * s1->size[1];
  s1->size[0] = num_idx_1;
  s1->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(s1, mt);
  loop_ub = num_idx_1 << 2;
  for (xf_tmp = 0; xf_tmp < loop_ub; xf_tmp++) {
    s1->data[xf_tmp] = g1->data[xf_tmp];
  }

  codegenReal2Mission_emxInit_real_T(&g_0, 2);
  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>
    (g->size[0] * g->size[1]) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = g_0->size[0] * g_0->size[1];
  g_0->size[0] = num_idx_1;
  g_0->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(g_0, mt);
  loop_ub = num_idx_1;
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt < loop_ub; mt++) {
      g_0->data[mt + g_0->size[0] * xf_tmp] = g->data[xf_tmp + tmp[0] * mt];
    }
  }

  codegenReal2Mission_emxFree_real_T(&g);
  mt = g1->size[0] * g1->size[1];
  g1->size[0] = num_idx_1;
  g1->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(g1, mt);
  loop_ub = num_idx_1 << 2;
  for (xf_tmp = 0; xf_tmp < loop_ub; xf_tmp++) {
    g1->data[xf_tmp] = g_0->data[xf_tmp];
  }

  num_idx_1 = static_cast<int16_T>(static_cast<int32_T>(static_cast<real_T>
    (ml->size[0] * ml->size[1]) / 4.0));
  tmp[0] = 4;
  tmp[1] = num_idx_1;
  mt = g_0->size[0] * g_0->size[1];
  g_0->size[0] = num_idx_1;
  g_0->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(g_0, mt);
  loop_ub = num_idx_1;
  for (xf_tmp = 0; xf_tmp < 4; xf_tmp++) {
    for (mt = 0; mt < loop_ub; mt++) {
      g_0->data[mt + g_0->size[0] * xf_tmp] = ml->data[xf_tmp + tmp[0] * mt];
    }
  }

  codegenReal2Mission_emxFree_real_T(&ml);
  codegenReal2Mission_emxInit_real_T(&ml1, 2);
  mt = ml1->size[0] * ml1->size[1];
  ml1->size[0] = num_idx_1;
  ml1->size[1] = 4;
  codegenReal2Mission_emxEnsureCapacity_real_T(ml1, mt);
  loop_ub = num_idx_1 << 2;
  for (xf_tmp = 0; xf_tmp < loop_ub; xf_tmp++) {
    ml1->data[xf_tmp] = g_0->data[xf_tmp];
  }

  codegenReal2Mission_emxFree_real_T(&g_0);
  loop_ub = mt_size_idx_0 * mt_size_idx_0;
  for (xf_tmp = 0; xf_tmp < loop_ub; xf_tmp++) {
    codegenReal2Mission_B.mt_data[xf_tmp]++;
  }

  l = 0.0;
  *pathCosts_size = b_nRows + 1;
  for (xf_tmp = 0; xf_tmp <= b_nRows; xf_tmp++) {
    pathCosts_data[xf_tmp] = (rtNaN);
  }

  m[0] = kb;
  m[1] = lb;
  m[2] = mb;
  m[3] = nb;
  if (flagOptimal) {
    *pathSegObjs_size = static_cast<int16_T>(b_nRows + 1);
    for (xf_tmp = 0; xf_tmp <= b_nRows; xf_tmp++) {
      l++;
      ml1_tmp = codegenReal2Mission_B.mt_data[static_cast<int32_T>(l) - 1];
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

      b_startPose[0] = s1->data[static_cast<int32_T>(l) - 1];
      b_goalPose[0] = g1->data[static_cast<int32_T>(l) - 1];
      ml1_tmp = ml1->data[static_cast<int32_T>(l) - 1];
      ml1_0[0] = ml1_tmp;
      ml1_data[0] = ml1_tmp;
      b_startPose[1] = s1->data[(static_cast<int32_T>(l) + s1->size[0]) - 1];
      b_goalPose[1] = g1->data[(static_cast<int32_T>(l) + g1->size[0]) - 1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + ml1->size[0]) - 1];
      ml1_0[1] = ml1_tmp;
      ml1_data[1] = ml1_tmp;
      b_startPose[2] = s1->data[(static_cast<int32_T>(l) + (s1->size[0] << 1)) -
        1];
      b_goalPose[2] = g1->data[(static_cast<int32_T>(l) + (g1->size[0] << 1)) -
        1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + (ml1->size[0] << 1)) - 1];
      ml1_0[2] = ml1_tmp;
      ml1_data[2] = ml1_tmp;
      b_startPose[3] = s1->data[(static_cast<int32_T>(l) + s1->size[0] * 3) - 1];
      b_goalPose[3] = g1->data[(static_cast<int32_T>(l) + g1->size[0] * 3) - 1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + ml1->size[0] * 3) - 1];
      ml1_0[3] = ml1_tmp;
      ml1_data[3] = ml1_tmp;
      codegenReal2Mission_uavDubinsPathSegment_uavDubinsPathSegment_a
        (b_startPose, b_goalPose, codegenReal2Mission_B.b_fpa_data
         [static_cast<int32_T>(l) - 1], codegenReal2Mission_B.b_a_data[0],
         codegenReal2Mission_B.mtr_data[0], codegenReal2Mission_B.h_data[
         static_cast<int32_T>(l) - 1], m, ml1_0, &pathSegObjs_data[xf_tmp]);
      pathCosts_data[xf_tmp] = codegenReal2Mission_sum(ml1_data);
    }
  } else {
    *pathSegObjs_size = static_cast<int16_T>(b_nRows + 1);
    for (xf_tmp = 1; xf_tmp - 1 <= b_nRows; xf_tmp++) {
      l++;
      if (1 == xf_tmp) {
        m[0] = kb;
        m[1] = lb;
        m[2] = mb;
        m[3] = nb;
      }

      if (2 == xf_tmp) {
        m[0] = ob;
        m[1] = pb;
        m[2] = qb;
        m[3] = rb;
      }

      if (3 == xf_tmp) {
        m[0] = sb;
        m[1] = tb;
        m[2] = ub;
        m[3] = vb;
      }

      if (4 == xf_tmp) {
        m[0] = wb;
        m[1] = xb;
        m[2] = yb;
        m[3] = ac;
      }

      if (5 == xf_tmp) {
        m[0] = bc;
        m[1] = cc;
        m[2] = dc;
        m[3] = ec;
      }

      if (6 == xf_tmp) {
        m[0] = fc;
        m[1] = gc;
        m[2] = hc;
        m[3] = ic;
      }

      if (7 == xf_tmp) {
        m[0] = jc;
        m[1] = kc;
        m[2] = lc;
        m[3] = mc;
      }

      if (8 == xf_tmp) {
        m[0] = nc;
        m[1] = oc;
        m[2] = pc;
        m[3] = qc;
      }

      if (9 == xf_tmp) {
        m[0] = rc;
        m[1] = sc;
        m[2] = tc;
        m[3] = uc;
      }

      if (10 == xf_tmp) {
        m[0] = vc;
        m[1] = wc;
        m[2] = xc;
        m[3] = yc;
      }

      if (11 == xf_tmp) {
        m[0] = ad;
        m[1] = bd;
        m[2] = cd;
        m[3] = dd;
      }

      if (12 == xf_tmp) {
        m[0] = ed;
        m[1] = fd;
        m[2] = gd;
        m[3] = hd;
      }

      if (13 == xf_tmp) {
        m[0] = id;
        m[1] = jd;
        m[2] = kd;
        m[3] = ld;
      }

      if (14 == xf_tmp) {
        m[0] = md;
        m[1] = nd;
        m[2] = od;
        m[3] = pd;
      }

      if (15 == xf_tmp) {
        m[0] = qd;
        m[1] = rd;
        m[2] = sd;
        m[3] = td;
      }

      if (16 == xf_tmp) {
        m[0] = ud;
        m[1] = vd;
        m[2] = wd;
        m[3] = xd;
      }

      if (17 == xf_tmp) {
        m[0] = yd;
        m[1] = ae;
        m[2] = be;
        m[3] = ce;
      }

      if (18 == xf_tmp) {
        m[0] = de;
        m[1] = ee;
        m[2] = fe;
        m[3] = ge;
      }

      if (19 == xf_tmp) {
        m[0] = he;
        m[1] = ie;
        m[2] = je;
        m[3] = ke;
      }

      if (20 == xf_tmp) {
        m[0] = le;
        m[1] = me;
        m[2] = ne;
        m[3] = oe;
      }

      if (21 == xf_tmp) {
        m[0] = pe;
        m[1] = qe;
        m[2] = re;
        m[3] = se;
      }

      if (22 == xf_tmp) {
        m[0] = te;
        m[1] = ue;
        m[2] = ve;
        m[3] = we;
      }

      if (23 == xf_tmp) {
        m[0] = xe;
        m[1] = ye;
        m[2] = af;
        m[3] = bf;
      }

      if (24 == xf_tmp) {
        m[0] = cf;
        m[1] = df;
        m[2] = ef;
        m[3] = ff;
      }

      if (25 == xf_tmp) {
        m[0] = gf;
        m[1] = hf;
        m[2] = jf;
        m[3] = kf;
      }

      if (26 == xf_tmp) {
        m[0] = lf;
        m[1] = mf;
        m[2] = nf;
        m[3] = of;
      }

      if (27 == xf_tmp) {
        m[0] = pf;
        m[1] = qf;
        m[2] = rf;
        m[3] = sf;
      }

      if (28 == xf_tmp) {
        m[0] = tf;
        m[1] = uf;
        m[2] = vf;
        m[3] = wf;
      }

      b_startPose[0] = s1->data[static_cast<int32_T>(l) - 1];
      b_goalPose[0] = g1->data[static_cast<int32_T>(l) - 1];
      ml1_tmp = ml1->data[static_cast<int32_T>(l) - 1];
      ml1_0[0] = ml1_tmp;
      ml1_data[0] = ml1_tmp;
      b_startPose[1] = s1->data[(static_cast<int32_T>(l) + s1->size[0]) - 1];
      b_goalPose[1] = g1->data[(static_cast<int32_T>(l) + g1->size[0]) - 1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + ml1->size[0]) - 1];
      ml1_0[1] = ml1_tmp;
      ml1_data[1] = ml1_tmp;
      b_startPose[2] = s1->data[(static_cast<int32_T>(l) + (s1->size[0] << 1)) -
        1];
      b_goalPose[2] = g1->data[(static_cast<int32_T>(l) + (g1->size[0] << 1)) -
        1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + (ml1->size[0] << 1)) - 1];
      ml1_0[2] = ml1_tmp;
      ml1_data[2] = ml1_tmp;
      b_startPose[3] = s1->data[(static_cast<int32_T>(l) + s1->size[0] * 3) - 1];
      b_goalPose[3] = g1->data[(static_cast<int32_T>(l) + g1->size[0] * 3) - 1];
      ml1_tmp = ml1->data[(static_cast<int32_T>(l) + ml1->size[0] * 3) - 1];
      ml1_0[3] = ml1_tmp;
      ml1_data[3] = ml1_tmp;
      codegenReal2Mission_uavDubinsPathSegment_uavDubinsPathSegment_a
        (b_startPose, b_goalPose, codegenReal2Mission_B.b_fpa_data
         [static_cast<int32_T>(l) - 1], codegenReal2Mission_B.b_a_data[0],
         codegenReal2Mission_B.mtr_data[0], codegenReal2Mission_B.h_data[
         static_cast<int32_T>(l) - 1], m, ml1_0, &pathSegObjs_data[xf_tmp - 1]);
      pathCosts_data[xf_tmp - 1] = codegenReal2Mission_sum(ml1_data);
    }
  }

  codegenReal2Mission_emxFree_real_T(&ml1);
  codegenReal2Mission_emxFree_real_T(&g1);
  codegenReal2Mission_emxFree_real_T(&s1);
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsConnection_connect(const
  uavDubinsConnection_codegenReal2Mission_T *obj, const real_T startPoses[4],
  const real_T goalPoses[4], uavDubinsPathSegment_codegenReal2Mission_T
  pathSegObjs_data[], int32_T *pathSegObjs_size, real_T pathCosts_data[],
  int32_T *pathCosts_size)
{
  matlabshared_autonomous_core_internal_NameValueParser_codegenReal2Mission_T
    parser;
  real_T idx_data[28];
  int32_T tmp_size[2];
  int32_T flagOptimal;
  int32_T idx_size;
  char_T tmp_data[7];
  codegenReal2Mission_NameValueParser_NameValueParser(&parser);
  parser.ParsedResults = parser.Defaults;
  flagOptimal = 1;
  codegenReal2Mission_validatestring(parser.ParsedResults.f1, tmp_data, tmp_size);
  if (codegenReal2Mission_strcmp(tmp_data, tmp_size)) {
    flagOptimal = 0;
  }

  codegenReal2Mission_uavDubinsConnection_findDisabledIndices(idx_data,
    &idx_size);
  codegenReal2Mission_uavDubinsBuiltins_connect(obj, startPoses, goalPoses,
    flagOptimal == 1, obj->MinTurningRadius, idx_data, &idx_size,
    pathSegObjs_data, pathSegObjs_size, pathCosts_data, pathCosts_size);
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_strcmp_ol2(const
  cell_wrap_1_codegenReal2Mission_T a[4], boolean_T b_bool[4])
{
  b_bool[0] = false;
  if ((a[0].f1.size[1] == 1) && (!(a[0].f1.data[0] != 'N'))) {
    b_bool[0] = true;
  }

  b_bool[1] = false;
  if ((a[1].f1.size[1] == 1) && (!(a[1].f1.data[0] != 'N'))) {
    b_bool[1] = true;
  }

  b_bool[2] = false;
  if ((a[2].f1.size[1] == 1) && (!(a[2].f1.data[0] != 'N'))) {
    b_bool[2] = true;
  }

  b_bool[3] = false;
  if ((a[3].f1.size[1] == 1) && (!(a[3].f1.data[0] != 'N'))) {
    b_bool[3] = true;
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_eml_find(boolean_T x,
  int32_T i_data[], int32_T i_size[2])
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

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsPathSegment_interpolate(const real_T
  b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_1_codegenReal2Mission_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, real_T samples, real_T poses_data[], int32_T poses_size[2])
{
  emxArray_real_T_codegenReal2Mission_T *S;
  emxArray_real_T_codegenReal2Mission_T *b_y;
  emxArray_real_T_codegenReal2Mission_T *c_x;
  emxArray_real_T_codegenReal2Mission_T *d_x;
  emxArray_real_T_codegenReal2Mission_T *y;
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
  real_T d_b;
  real_T intermediateLength;
  real_T radius;
  real_T samples_tmp;
  real_T state_0;
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
  if (!std::isnan(b_this_Length)) {
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
    codegenReal2Mission_strcmp_ol2(b_this_MotionTypes, tmp);
    if (codegenReal2Mission_any(tmp)) {
      tempMotionLength_size[0] = 1;
      tempMotionLength_size[1] = 3;
      tempMotionLength_data[0] = TransformMatrix[0];
      tempMotionLength_data[1] = TransformMatrix[1];
      tempMotionLength_data[2] = TransformMatrix[2];
    }

    codegenReal2Mission_useConstantDim(tempMotionLength_data,
      tempMotionLength_size, x_data, x_size);
    intermediateLength = 0.0;
    state[0] = b_this_StartPose[0];
    state[1] = -b_this_StartPose[1];
    state[3] = -b_this_StartPose[3];
    tempMotionLength_data_tmp = 0;
    codegenReal2Mission_emxInit_real_T1(&y, 1);
    codegenReal2Mission_emxInit_real_T(&b_y, 2);
    codegenReal2Mission_emxInit_real_T1(&c_x, 1);
    codegenReal2Mission_emxInit_real_T1(&d_x, 1);
    codegenReal2Mission_emxInit_real_T(&S, 2);
    while (tempMotionLength_data_tmp <= tempMotionLength_size[1] - 1) {
      if (tempMotionLength_data_tmp + 1 == 1) {
        tempSamplesIndex = ((samples >= intermediateLength) && (samples <=
          (intermediateLength + tempMotionLength_data[0]) + 1.0E-6));
      } else {
        tempSamplesIndex = ((samples > intermediateLength) && (samples <=
          (intermediateLength + tempMotionLength_data[tempMotionLength_data_tmp])
          + 1.0E-6));
      }

      codegenReal2Mission_eml_find(tempSamplesIndex, &o_data, x_size);
      if (!codegenReal2Mission_strcmp_ol2u
          (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
           b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
        radius = b_this_MinTurningRadius;
        if (codegenReal2Mission_strcmp_ol2ud
            (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
             b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          radius = b_this_HelixRadius;
        } else if (codegenReal2Mission_strcmp_ol2udr
                   (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                    b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          radius = b_this_HelixRadius;
        }

        count = 0;
        tempSamples_size_idx_0 = 1;
        tempSamples_data[0] = 0.0;
        if ((x_size[0] != 0) && (x_size[1] != 0)) {
          tempSamples_size_idx_0 = 2;
          tempSamples_data[1] = 0.0;
          count = 1;
          tempSamples_data[0] = samples;
          samples = -1.0;
        }

        tempSamples_data[count] = x_data[tempMotionLength_data_tmp];
        for (count = 0; count < tempSamples_size_idx_0; count++) {
          S_data[count] = (tempSamples_data[count] - intermediateLength) /
            radius;
        }

        ns_size_idx_0 = tempSamples_size_idx_0;
        loop_ub = tempSamples_size_idx_0 * 6 - 1;
        if (0 <= loop_ub) {
          std::memset(&ns_data[0], 0, (loop_ub + 1) * sizeof(real_T));
        }

        for (count = 0; count < tempSamples_size_idx_0; count++) {
          z_data[count] = tempStartPose_idx_2 + tempSamples_data[count];
        }

        TransformMatrix_tmp = std::sin(state[3]);
        TransformMatrix_tmp_0 = std::cos(state[3]);
        TransformMatrix[0] = TransformMatrix_tmp_0;
        TransformMatrix[2] = TransformMatrix_tmp;
        TransformMatrix[1] = -TransformMatrix_tmp;
        TransformMatrix[3] = TransformMatrix_tmp_0;
        if (b_this_Length != 0.0) {
          TransformMatrix_tmp = -b_this_GoalPose[2] - tempStartPose_idx_2;
          TransformMatrix_tmp_0 = b_this_Length * samples_tmp;
          for (count = 0; count < tempSamples_size_idx_0; count++) {
            z_data[count] = tempSamples_data[count] / TransformMatrix_tmp_0 *
              TransformMatrix_tmp + tempStartPose_idx_2;
          }
        }

        count = y->size[0];
        y->size[0] = tempSamples_size_idx_0;
        codegenReal2Mission_emxEnsureCapacity_real_T1(y, count);
        for (count = 0; count < tempSamples_size_idx_0; count++) {
          y->data[count] = b_this_FlightPathAngle;
        }

        if (codegenReal2Mission_strcmp_ol2ud
            (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
             b_this_MotionTypes[tempMotionLength_data_tmp].f1.size) ||
            codegenReal2Mission_strcmp_ol2udrg
            (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
             b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          count = c_x->size[0];
          c_x->size[0] = tempSamples_size_idx_0;
          codegenReal2Mission_emxEnsureCapacity_real_T1(c_x, count);
          for (count = 0; count < tempSamples_size_idx_0; count++) {
            c_x->data[count] = S_data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            c_x->data[count] = std::sin(c_x->data[count]);
          }

          count = d_x->size[0];
          d_x->size[0] = tempSamples_size_idx_0;
          codegenReal2Mission_emxEnsureCapacity_real_T1(d_x, count);
          for (count = 0; count < tempSamples_size_idx_0; count++) {
            d_x->data[count] = S_data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            d_x->data[count] = std::cos(d_x->data[count]);
          }

          count = S->size[0] * S->size[1];
          S->size[0] = c_x->size[0];
          S->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S, count);
          loop_ub = c_x->size[0];
          for (count = 0; count < loop_ub; count++) {
            S->data[count] = c_x->data[count];
          }

          loop_ub = d_x->size[0];
          for (count = 0; count < loop_ub; count++) {
            S->data[count + c_x->size[0]] = 1.0 - d_x->data[count];
          }

          codegenReal2Mission_mtimes(S, TransformMatrix, b_y);
          d_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          TransformMatrix_tmp = state[0];
          TransformMatrix_tmp_0 = state[1];
          state_0 = state[3];
          loop_ub = b_y->size[0];
          ns_size_idx_0 = b_y->size[0];
          for (count = 0; count < loop_ub; count++) {
            ns_data[count] = b_y->data[count] * radius + TransformMatrix_tmp;
            ns_data[count + ns_size_idx_0] = b_y->data[count + b_y->size[0]] *
              radius + TransformMatrix_tmp_0;
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            ns_data[count + (ns_size_idx_0 << 1)] = z_data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            ns_data[count + ns_size_idx_0 * 3] = state_0 + S_data[count];
          }

          loop_ub = y->size[0];
          for (count = 0; count < loop_ub; count++) {
            ns_data[count + (ns_size_idx_0 << 2)] = y->data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            ns_data[count + ns_size_idx_0 * 5] = -d_b;
          }
        } else if (codegenReal2Mission_strcmp_ol2udr
                   (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                    b_this_MotionTypes[tempMotionLength_data_tmp].f1.size) ||
                   codegenReal2Mission_strcmp_ol2udrgv
                   (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                    b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          count = c_x->size[0];
          c_x->size[0] = tempSamples_size_idx_0;
          codegenReal2Mission_emxEnsureCapacity_real_T1(c_x, count);
          for (count = 0; count < tempSamples_size_idx_0; count++) {
            c_x->data[count] = S_data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            c_x->data[count] = std::sin(c_x->data[count]);
          }

          count = d_x->size[0];
          d_x->size[0] = tempSamples_size_idx_0;
          codegenReal2Mission_emxEnsureCapacity_real_T1(d_x, count);
          for (count = 0; count < tempSamples_size_idx_0; count++) {
            d_x->data[count] = S_data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            d_x->data[count] = std::cos(d_x->data[count]);
          }

          count = S->size[0] * S->size[1];
          S->size[0] = c_x->size[0];
          S->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S, count);
          loop_ub = c_x->size[0];
          for (count = 0; count < loop_ub; count++) {
            S->data[count] = c_x->data[count];
          }

          loop_ub = d_x->size[0];
          for (count = 0; count < loop_ub; count++) {
            S->data[count + c_x->size[0]] = d_x->data[count] - 1.0;
          }

          codegenReal2Mission_mtimes(S, TransformMatrix, b_y);
          d_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          TransformMatrix_tmp = state[0];
          TransformMatrix_tmp_0 = state[1];
          state_0 = state[3];
          loop_ub = b_y->size[0];
          ns_size_idx_0 = b_y->size[0];
          for (count = 0; count < loop_ub; count++) {
            ns_data[count] = b_y->data[count] * radius + TransformMatrix_tmp;
            ns_data[count + ns_size_idx_0] = b_y->data[count + b_y->size[0]] *
              radius + TransformMatrix_tmp_0;
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            ns_data[count + (ns_size_idx_0 << 1)] = z_data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            ns_data[count + ns_size_idx_0 * 3] = state_0 - S_data[count];
          }

          loop_ub = y->size[0];
          for (count = 0; count < loop_ub; count++) {
            ns_data[count + (ns_size_idx_0 << 2)] = y->data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            ns_data[count + ns_size_idx_0 * 5] = d_b;
          }
        } else if (codegenReal2Mission_strcmp_ol2udrgv2
                   (b_this_MotionTypes[tempMotionLength_data_tmp].f1.data,
                    b_this_MotionTypes[tempMotionLength_data_tmp].f1.size)) {
          count = S->size[0] * S->size[1];
          S->size[0] = tempSamples_size_idx_0;
          S->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S, count);
          for (count = 0; count < tempSamples_size_idx_0; count++) {
            S->data[count] = S_data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            S->data[count + tempSamples_size_idx_0] = 0.0;
          }

          codegenReal2Mission_mtimes(S, TransformMatrix, b_y);
          TransformMatrix_tmp = state[0];
          TransformMatrix_tmp_0 = state[1];
          loop_ub = b_y->size[0];
          ns_size_idx_0 = b_y->size[0];
          for (count = 0; count < loop_ub; count++) {
            ns_data[count] = b_y->data[count] * radius + TransformMatrix_tmp;
            ns_data[count + ns_size_idx_0] = b_y->data[count + b_y->size[0]] *
              radius + TransformMatrix_tmp_0;
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            ns_data[count + (ns_size_idx_0 << 1)] = z_data[count];
          }

          for (count = 0; count < tempSamples_size_idx_0; count++) {
            ns_data[count + ns_size_idx_0 * 3] = state[3];
          }

          loop_ub = y->size[0];
          for (count = 0; count < loop_ub; count++) {
            ns_data[count + (ns_size_idx_0 << 2)] = y->data[count];
          }

          if (0 <= tempSamples_size_idx_0 - 1) {
            std::memset(&ns_data[ns_size_idx_0 * 5], 0, ((tempSamples_size_idx_0
              + ns_size_idx_0 * 5) - ns_size_idx_0 * 5) * sizeof(real_T));
          }
        }

        if ((x_size[0] != 0) && (x_size[1] != 0)) {
          if (1 > ns_size_idx_0 - 1) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            for (count = 0; count < 6; count++) {
              poses_data[count] = ns_data[ns_size_idx_0 * count];
            }
          }

          if (1 > ns_size_idx_0 - 1) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            poses_data[0] = ns_data[0];
          }

          if (1 > ns_size_idx_0 - 1) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            poses_data[1] = -ns_data[ns_size_idx_0];
          }

          if (1 > ns_size_idx_0 - 1) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            poses_data[2] = -ns_data[ns_size_idx_0 << 1];
          }

          if (1 > ns_size_idx_0 - 1) {
            loop_ub = -1;
          } else {
            loop_ub = 0;
          }

          if (0 <= loop_ub) {
            poses_data[3] = -ns_data[ns_size_idx_0 * 3];
          }
        }

        for (count = 0; count < 6; count++) {
          state[count] = ns_data[(ns_size_idx_0 + ns_size_idx_0 * count) - 1];
        }
      }

      intermediateLength += tempMotionLength_data[tempMotionLength_data_tmp];
      tempMotionLength_data_tmp++;
    }

    codegenReal2Mission_emxFree_real_T(&S);
    codegenReal2Mission_emxFree_real_T(&d_x);
    codegenReal2Mission_emxFree_real_T(&c_x);
    codegenReal2Mission_emxFree_real_T(&b_y);
    count = y->size[0];
    y->size[0] = 1;
    codegenReal2Mission_emxEnsureCapacity_real_T1(y, count);
    y->data[0] = poses_data[3];
    codegenReal2Mission_wrapToPi(y);
    loop_ub = y->size[0];
    for (count = 0; count < loop_ub; count++) {
      poses_data[3] = y->data[count];
    }

    codegenReal2Mission_emxFree_real_T(&y);
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::
  codegenReal2Mission_uavDubinsPathSegment_interpolate_n(const real_T
  b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
  b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T b_this_MinTurningRadius,
  real_T b_this_HelixRadius, const cell_wrap_1_codegenReal2Mission_T
  b_this_MotionTypes[4], const real_T b_this_MotionLengths[4], real_T
  b_this_Length, emxArray_real_T_codegenReal2Mission_T *samples,
  emxArray_real_T_codegenReal2Mission_T *poses)
{
  emxArray_boolean_T_codegenReal2Mission_T *tempSamplesIndex;
  emxArray_boolean_T_codegenReal2Mission_T *tempSamplesIndex_0;
  emxArray_int32_T_codegenReal2Mission_T *ab;
  emxArray_real_T_codegenReal2Mission_T *S;
  emxArray_real_T_codegenReal2Mission_T *S_0;
  emxArray_real_T_codegenReal2Mission_T *e_x;
  emxArray_real_T_codegenReal2Mission_T *ns;
  emxArray_real_T_codegenReal2Mission_T *p;
  emxArray_real_T_codegenReal2Mission_T *tempSamples;
  emxArray_real_T_codegenReal2Mission_T *z;
  real_T state[6];
  real_T TransformMatrix[4];
  real_T c_x_data[4];
  real_T tempMotionLength_data[4];
  real_T TransformMatrix_tmp;
  real_T b_b_tmp;
  real_T e_b;
  real_T intermediateLength;
  real_T radius;
  real_T samples_0;
  real_T startIndex;
  real_T state_0;
  real_T tempStartPose_idx_2;
  int32_T c_x_size[2];
  int32_T tempMotionLength_size[2];
  int32_T S_idx_0;
  int32_T count;
  int32_T d_k;
  int32_T loop_ub;
  int32_T poses_0;
  int32_T tempMotionLength_data_tmp;
  boolean_T tmp[4];
  poses->size[0] = 0;
  poses->size[1] = 6;
  if ((!std::isnan(b_this_Length)) && (samples->size[1] != 0)) {
    tempStartPose_idx_2 = -b_this_StartPose[2];
    d_k = poses->size[0] * poses->size[1];
    poses->size[0] = samples->size[1];
    poses->size[1] = 6;
    codegenReal2Mission_emxEnsureCapacity_real_T(poses, d_k);
    loop_ub = samples->size[1] * 6 - 1;
    for (d_k = 0; d_k <= loop_ub; d_k++) {
      poses->data[d_k] = 0.0;
    }

    b_b_tmp = std::cos(std::abs(b_this_FlightPathAngle));
    d_k = samples->size[0] * samples->size[1];
    samples->size[0] = 1;
    codegenReal2Mission_emxEnsureCapacity_real_T(samples, d_k);
    loop_ub = samples->size[1] - 1;
    for (d_k = 0; d_k <= loop_ub; d_k++) {
      samples->data[d_k] *= b_b_tmp;
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
    codegenReal2Mission_strcmp_ol2(b_this_MotionTypes, tmp);
    if (codegenReal2Mission_any(tmp)) {
      tempMotionLength_size[0] = 1;
      tempMotionLength_size[1] = 3;
      tempMotionLength_data[0] = TransformMatrix[0];
      tempMotionLength_data[1] = TransformMatrix[1];
      tempMotionLength_data[2] = TransformMatrix[2];
    }

    codegenReal2Mission_useConstantDim(tempMotionLength_data,
      tempMotionLength_size, c_x_data, c_x_size);
    codegenReal2Mission_sort_k5(samples);
    intermediateLength = 0.0;
    startIndex = 1.0;
    state[0] = b_this_StartPose[0];
    state[1] = -b_this_StartPose[1];
    state[3] = -b_this_StartPose[3];
    poses_0 = 0;
    codegenReal2Mission_emxInit_boolean_T(&tempSamplesIndex, 2);
    codegenReal2Mission_emxInit_real_T1(&tempSamples, 1);
    codegenReal2Mission_emxInit_real_T1(&S, 1);
    codegenReal2Mission_emxInit_real_T(&ns, 2);
    codegenReal2Mission_emxInit_real_T1(&z, 1);
    codegenReal2Mission_emxInit_real_T(&p, 2);
    codegenReal2Mission_emxInit_real_T1(&e_x, 1);
    codegenReal2Mission_emxInit_int32_T(&ab, 2);
    codegenReal2Mission_emxInit_boolean_T(&tempSamplesIndex_0, 2);
    codegenReal2Mission_emxInit_real_T(&S_0, 2);
    while (poses_0 <= tempMotionLength_size[1] - 1) {
      if (poses_0 + 1 == 1) {
        d_k = tempSamplesIndex->size[0] * tempSamplesIndex->size[1];
        tempSamplesIndex->size[0] = 1;
        tempSamplesIndex->size[1] = samples->size[1];
        codegenReal2Mission_emxEnsureCapacity_boolean_T(tempSamplesIndex, d_k);
        loop_ub = samples->size[1] - 1;
        radius = (intermediateLength + tempMotionLength_data[0]) + 1.0E-6;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          samples_0 = samples->data[d_k];
          tempSamplesIndex->data[d_k] = ((samples_0 >= intermediateLength) &&
            (samples_0 <= radius));
        }
      } else {
        d_k = tempSamplesIndex->size[0] * tempSamplesIndex->size[1];
        tempSamplesIndex->size[0] = 1;
        tempSamplesIndex->size[1] = samples->size[1];
        codegenReal2Mission_emxEnsureCapacity_boolean_T(tempSamplesIndex, d_k);
        loop_ub = samples->size[1] - 1;
        radius = (intermediateLength + tempMotionLength_data[poses_0]) + 1.0E-6;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          samples_0 = samples->data[d_k];
          tempSamplesIndex->data[d_k] = ((samples_0 > intermediateLength) &&
            (samples_0 <= radius));
        }
      }

      d_k = tempSamplesIndex_0->size[0] * tempSamplesIndex_0->size[1];
      tempSamplesIndex_0->size[0] = 1;
      tempSamplesIndex_0->size[1] = tempSamplesIndex->size[1];
      codegenReal2Mission_emxEnsureCapacity_boolean_T(tempSamplesIndex_0, d_k);
      loop_ub = tempSamplesIndex->size[1];
      for (d_k = 0; d_k < loop_ub; d_k++) {
        tempSamplesIndex_0->data[d_k] = tempSamplesIndex->data[d_k];
      }

      codegenReal2Mission_eml_find_g(tempSamplesIndex_0, ab);
      if (!codegenReal2Mission_strcmp_ol2u(b_this_MotionTypes[poses_0].f1.data,
           b_this_MotionTypes[poses_0].f1.size)) {
        radius = b_this_MinTurningRadius;
        if (codegenReal2Mission_strcmp_ol2ud(b_this_MotionTypes[poses_0].f1.data,
             b_this_MotionTypes[poses_0].f1.size)) {
          radius = b_this_HelixRadius;
        } else if (codegenReal2Mission_strcmp_ol2udr(b_this_MotionTypes[poses_0]
                    .f1.data, b_this_MotionTypes[poses_0].f1.size)) {
          radius = b_this_HelixRadius;
        }

        count = 0;
        d_k = tempSamples->size[0];
        tempSamples->size[0] = 1;
        codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
        tempSamples->data[0] = 0.0;
        if (ab->size[1] != 0) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = ab->size[1] + 1;
          codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
          loop_ub = ab->size[1];
          for (d_k = 0; d_k <= loop_ub; d_k++) {
            tempSamples->data[d_k] = 0.0;
          }

          loop_ub = ab->size[1];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            tempSamples->data[d_k] = samples->data[ab->data[d_k] - 1];
          }

          count = ab->size[1];
          loop_ub = ab->size[1] - 1;
          for (d_k = 0; d_k <= loop_ub; d_k++) {
            samples->data[ab->data[d_k] - 1] = -1.0;
          }
        }

        tempSamples->data[count] = c_x_data[poses_0];
        d_k = S->size[0];
        S->size[0] = tempSamples->size[0];
        codegenReal2Mission_emxEnsureCapacity_real_T1(S, d_k);
        loop_ub = tempSamples->size[0];
        for (d_k = 0; d_k < loop_ub; d_k++) {
          S->data[d_k] = (tempSamples->data[d_k] - intermediateLength) / radius;
        }

        d_k = ns->size[0] * ns->size[1];
        ns->size[0] = S->size[0];
        ns->size[1] = 6;
        codegenReal2Mission_emxEnsureCapacity_real_T(ns, d_k);
        loop_ub = S->size[0] * 6 - 1;
        for (d_k = 0; d_k <= loop_ub; d_k++) {
          ns->data[d_k] = 0.0;
        }

        d_k = z->size[0];
        z->size[0] = tempSamples->size[0];
        codegenReal2Mission_emxEnsureCapacity_real_T1(z, d_k);
        loop_ub = tempSamples->size[0];
        for (d_k = 0; d_k < loop_ub; d_k++) {
          z->data[d_k] = tempStartPose_idx_2 + tempSamples->data[d_k];
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
          d_k = z->size[0];
          z->size[0] = tempSamples->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(z, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            z->data[d_k] = tempSamples->data[d_k] / TransformMatrix_tmp *
              samples_0 + tempStartPose_idx_2;
          }
        }

        if (codegenReal2Mission_strcmp_ol2ud(b_this_MotionTypes[poses_0].f1.data,
             b_this_MotionTypes[poses_0].f1.size) ||
            codegenReal2Mission_strcmp_ol2udrg(b_this_MotionTypes[poses_0].
             f1.data, b_this_MotionTypes[poses_0].f1.size)) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = S->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            tempSamples->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < S->size[0]; d_k++) {
            tempSamples->data[d_k] = std::sin(tempSamples->data[d_k]);
          }

          d_k = e_x->size[0];
          e_x->size[0] = S->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(e_x, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            e_x->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < S->size[0]; d_k++) {
            e_x->data[d_k] = std::cos(e_x->data[d_k]);
          }

          d_k = S_0->size[0] * S_0->size[1];
          S_0->size[0] = tempSamples->size[0];
          S_0->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S_0, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k] = tempSamples->data[d_k];
          }

          loop_ub = e_x->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k + tempSamples->size[0]] = 1.0 - e_x->data[d_k];
          }

          codegenReal2Mission_mtimes(S_0, TransformMatrix, p);
          e_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          state_0 = state[3];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          loop_ub = p->size[0];
          d_k = ns->size[0] * ns->size[1];
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          codegenReal2Mission_emxEnsureCapacity_real_T(ns, d_k);
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[d_k + ns->size[0]] = p->data[d_k + p->size[0]] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + (ns->size[0] << 1)] = z->data[d_k];
          }

          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + ns->size[0] * 3] = state_0 + S->data[d_k];
          }

          for (d_k = 0; d_k < count; d_k++) {
            ns->data[d_k + (ns->size[0] << 2)] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k < tempMotionLength_data_tmp; d_k++) {
            ns->data[d_k + ns->size[0] * 5] = -e_b;
          }
        } else if (codegenReal2Mission_strcmp_ol2udr(b_this_MotionTypes[poses_0]
                    .f1.data, b_this_MotionTypes[poses_0].f1.size) ||
                   codegenReal2Mission_strcmp_ol2udrgv
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          d_k = tempSamples->size[0];
          tempSamples->size[0] = S->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            tempSamples->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < S->size[0]; d_k++) {
            tempSamples->data[d_k] = std::sin(tempSamples->data[d_k]);
          }

          d_k = e_x->size[0];
          e_x->size[0] = S->size[0];
          codegenReal2Mission_emxEnsureCapacity_real_T1(e_x, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            e_x->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < S->size[0]; d_k++) {
            e_x->data[d_k] = std::cos(e_x->data[d_k]);
          }

          d_k = S_0->size[0] * S_0->size[1];
          S_0->size[0] = tempSamples->size[0];
          S_0->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S_0, d_k);
          loop_ub = tempSamples->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k] = tempSamples->data[d_k];
          }

          loop_ub = e_x->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k + tempSamples->size[0]] = e_x->data[d_k] - 1.0;
          }

          codegenReal2Mission_mtimes(S_0, TransformMatrix, p);
          e_b = rt_atan2d_snf(b_this_AirSpeed * b_this_AirSpeed, 9.8 * radius);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          state_0 = state[3];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          loop_ub = p->size[0];
          d_k = ns->size[0] * ns->size[1];
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          codegenReal2Mission_emxEnsureCapacity_real_T(ns, d_k);
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[d_k + ns->size[0]] = p->data[d_k + p->size[0]] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + (ns->size[0] << 1)] = z->data[d_k];
          }

          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + ns->size[0] * 3] = state_0 - S->data[d_k];
          }

          for (d_k = 0; d_k < count; d_k++) {
            ns->data[d_k + (ns->size[0] << 2)] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k < tempMotionLength_data_tmp; d_k++) {
            ns->data[d_k + ns->size[0] * 5] = e_b;
          }
        } else if (codegenReal2Mission_strcmp_ol2udrgv2
                   (b_this_MotionTypes[poses_0].f1.data,
                    b_this_MotionTypes[poses_0].f1.size)) {
          count = S->size[0];
          d_k = S_0->size[0] * S_0->size[1];
          S_0->size[0] = S->size[0];
          S_0->size[1] = 2;
          codegenReal2Mission_emxEnsureCapacity_real_T(S_0, d_k);
          loop_ub = S->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            S_0->data[d_k] = S->data[d_k];
          }

          for (d_k = 0; d_k < count; d_k++) {
            S_0->data[d_k + S->size[0]] = 0.0;
          }

          codegenReal2Mission_mtimes(S_0, TransformMatrix, p);
          samples_0 = state[0];
          TransformMatrix_tmp = state[1];
          count = S->size[0];
          tempMotionLength_data_tmp = S->size[0];
          S_idx_0 = S->size[0];
          loop_ub = p->size[0];
          d_k = ns->size[0] * ns->size[1];
          ns->size[0] = p->size[0];
          ns->size[1] = 6;
          codegenReal2Mission_emxEnsureCapacity_real_T(ns, d_k);
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k] = p->data[d_k] * radius + samples_0;
            ns->data[d_k + ns->size[0]] = p->data[d_k + p->size[0]] * radius +
              TransformMatrix_tmp;
          }

          loop_ub = z->size[0];
          for (d_k = 0; d_k < loop_ub; d_k++) {
            ns->data[d_k + (ns->size[0] << 1)] = z->data[d_k];
          }

          for (d_k = 0; d_k < count; d_k++) {
            ns->data[d_k + ns->size[0] * 3] = state[3];
          }

          for (d_k = 0; d_k < tempMotionLength_data_tmp; d_k++) {
            ns->data[d_k + (ns->size[0] << 2)] = b_this_FlightPathAngle;
          }

          for (d_k = 0; d_k < S_idx_0; d_k++) {
            ns->data[d_k + ns->size[0] * 5] = 0.0;
          }
        }

        if (ab->size[1] != 0) {
          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k < 6; d_k++) {
            for (tempMotionLength_data_tmp = 0; tempMotionLength_data_tmp <=
                 loop_ub; tempMotionLength_data_tmp++) {
              poses->data[((count + tempMotionLength_data_tmp) + poses->size[0] *
                           d_k) - 1] = ns->data[tempMotionLength_data_tmp +
                ns->size[0] * d_k];
            }
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[(count + d_k) - 1] = ns->data[d_k];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[((count + d_k) + poses->size[0]) - 1] = -ns->data[d_k +
              ns->size[0]];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[((count + d_k) + (poses->size[0] << 1)) - 1] = -ns->
              data[d_k + (ns->size[0] << 1)];
          }

          if (startIndex > (startIndex + static_cast<real_T>(ab->size[1])) - 1.0)
          {
            count = 1;
          } else {
            count = static_cast<int32_T>(startIndex);
          }

          if (1 > ns->size[0] - 1) {
            loop_ub = -1;
          } else {
            loop_ub = ns->size[0] - 2;
          }

          for (d_k = 0; d_k <= loop_ub; d_k++) {
            poses->data[((count + d_k) + poses->size[0] * 3) - 1] = -ns->
              data[d_k + ns->size[0] * 3];
          }
        }

        count = ns->size[0];
        for (d_k = 0; d_k < 6; d_k++) {
          state[d_k] = ns->data[(count + ns->size[0] * d_k) - 1];
        }

        startIndex += static_cast<real_T>(ab->size[1]);
      }

      intermediateLength += tempMotionLength_data[poses_0];
      poses_0++;
    }

    codegenReal2Mission_emxFree_real_T(&S_0);
    codegenReal2Mission_emxFree_boolean_T(&tempSamplesIndex_0);
    codegenReal2Mission_emxFree_int32_T(&ab);
    codegenReal2Mission_emxFree_real_T(&e_x);
    codegenReal2Mission_emxFree_real_T(&p);
    codegenReal2Mission_emxFree_real_T(&z);
    codegenReal2Mission_emxFree_real_T(&ns);
    codegenReal2Mission_emxFree_real_T(&S);
    codegenReal2Mission_emxFree_boolean_T(&tempSamplesIndex);
    loop_ub = poses->size[0];
    d_k = tempSamples->size[0];
    tempSamples->size[0] = poses->size[0];
    codegenReal2Mission_emxEnsureCapacity_real_T1(tempSamples, d_k);
    for (d_k = 0; d_k < loop_ub; d_k++) {
      tempSamples->data[d_k] = poses->data[d_k + poses->size[0] * 3];
    }

    codegenReal2Mission_wrapToPi(tempSamples);
    loop_ub = tempSamples->size[0];
    for (d_k = 0; d_k < loop_ub; d_k++) {
      poses->data[d_k + poses->size[0] * 3] = tempSamples->data[d_k];
    }

    codegenReal2Mission_emxFree_real_T(&tempSamples);
  }
}

// Function for MATLAB Function: '<S71>/WayPointGenerator'
void codegenReal2MissionModelClass::codegenReal2Mission_genSegWP(const
  uavDubinsConnection_codegenReal2Mission_T *connectionObj, const real_T start[4],
  const real_T ende[4], real_T b_stepSize, emxArray_real_T_codegenReal2Mission_T
  *segWayPoints)
{
  emxArray_real_T_codegenReal2Mission_T *lengths;
  emxArray_real_T_codegenReal2Mission_T *poses;
  real_T a__2_data[28];
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T realStepSize;
  int32_T a__2_size;
  int32_T k;
  int32_T nm1d2;
  boolean_T guard1{ false };

  codegenReal2Mission_uavDubinsConnection_connect(connectionObj, start, ende,
    codegenReal2Mission_B.pathSegObj_d.data,
    &codegenReal2Mission_B.pathSegObj_d.size, a__2_data, &a__2_size);
  realStepSize = codegenReal2Mission_B.pathSegObj_d.data[0].Length / std::round
    (codegenReal2Mission_B.pathSegObj_d.data[0].Length / b_stepSize);
  codegenReal2Mission_emxInit_real_T(&lengths, 2);
  if (std::isnan(realStepSize)) {
    nm1d2 = lengths->size[0] * lengths->size[1];
    lengths->size[0] = 1;
    lengths->size[1] = 1;
    codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
    lengths->data[0] = (rtNaN);
  } else if (std::isnan(codegenReal2Mission_B.pathSegObj_d.data[0].Length)) {
    nm1d2 = lengths->size[0] * lengths->size[1];
    lengths->size[0] = 1;
    lengths->size[1] = 1;
    codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
    lengths->data[0] = (rtNaN);
  } else if (realStepSize == 0.0) {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else if ((0.0 < codegenReal2Mission_B.pathSegObj_d.data[0].Length) &&
             (realStepSize < 0.0)) {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else if ((codegenReal2Mission_B.pathSegObj_d.data[0].Length < 0.0) &&
             (realStepSize > 0.0)) {
    lengths->size[0] = 1;
    lengths->size[1] = 0;
  } else {
    guard1 = false;
    if (std::isinf(codegenReal2Mission_B.pathSegObj_d.data[0].Length)) {
      if (std::isinf(realStepSize)) {
        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
      } else if (0.0 == codegenReal2Mission_B.pathSegObj_d.data[0].Length) {
        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        lengths->data[0] = (rtNaN);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (std::isinf(realStepSize)) {
        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        lengths->size[1] = 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        lengths->data[0] = 0.0;
      } else if (std::floor(realStepSize) == realStepSize) {
        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        k = static_cast<int32_T>(std::floor
          (codegenReal2Mission_B.pathSegObj_d.data[0].Length / realStepSize));
        lengths->size[1] = k + 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        for (a__2_size = 0; a__2_size <= k; a__2_size++) {
          lengths->data[a__2_size] = realStepSize * static_cast<real_T>
            (a__2_size);
        }
      } else {
        ndbl = std::floor(codegenReal2Mission_B.pathSegObj_d.data[0].Length /
                          realStepSize + 0.5);
        apnd = ndbl * realStepSize;
        if (realStepSize > 0.0) {
          cdiff = apnd - codegenReal2Mission_B.pathSegObj_d.data[0].Length;
        } else {
          cdiff = codegenReal2Mission_B.pathSegObj_d.data[0].Length - apnd;
        }

        if (std::abs(cdiff) < 4.4408920985006262E-16 * std::abs
            (codegenReal2Mission_B.pathSegObj_d.data[0].Length)) {
          ndbl++;
          apnd = codegenReal2Mission_B.pathSegObj_d.data[0].Length;
        } else if (cdiff > 0.0) {
          apnd = (ndbl - 1.0) * realStepSize;
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          a__2_size = static_cast<int32_T>(ndbl) - 1;
        } else {
          a__2_size = -1;
        }

        nm1d2 = lengths->size[0] * lengths->size[1];
        lengths->size[0] = 1;
        lengths->size[1] = a__2_size + 1;
        codegenReal2Mission_emxEnsureCapacity_real_T(lengths, nm1d2);
        if (a__2_size + 1 > 0) {
          lengths->data[0] = 0.0;
          if (a__2_size + 1 > 1) {
            lengths->data[a__2_size] = apnd;
            nm1d2 = a__2_size / 2;
            for (k = 1; k - 1 <= nm1d2 - 2; k++) {
              ndbl = static_cast<real_T>(k) * realStepSize;
              lengths->data[k] = ndbl;
              lengths->data[a__2_size - k] = apnd - ndbl;
            }

            if (nm1d2 << 1 == a__2_size) {
              lengths->data[nm1d2] = apnd / 2.0;
            } else {
              ndbl = static_cast<real_T>(nm1d2) * realStepSize;
              lengths->data[nm1d2] = ndbl;
              lengths->data[nm1d2 + 1] = apnd - ndbl;
            }
          }
        }
      }
    }
  }

  codegenReal2Mission_emxInit_real_T(&poses, 2);
  codegenReal2Mission_uavDubinsPathSegment_interpolate_n
    (codegenReal2Mission_B.pathSegObj_d.data[0].StartPose,
     codegenReal2Mission_B.pathSegObj_d.data[0].GoalPose,
     codegenReal2Mission_B.pathSegObj_d.data[0].FlightPathAngle,
     codegenReal2Mission_B.pathSegObj_d.data[0].AirSpeed,
     codegenReal2Mission_B.pathSegObj_d.data[0].MinTurningRadius,
     codegenReal2Mission_B.pathSegObj_d.data[0].HelixRadius,
     codegenReal2Mission_B.pathSegObj_d.data[0].MotionTypes,
     codegenReal2Mission_B.pathSegObj_d.data[0].MotionLengths,
     codegenReal2Mission_B.pathSegObj_d.data[0].Length, lengths, poses);
  k = poses->size[0];
  nm1d2 = segWayPoints->size[0] * segWayPoints->size[1];
  segWayPoints->size[0] = poses->size[0];
  segWayPoints->size[1] = 3;
  codegenReal2Mission_emxEnsureCapacity_real_T(segWayPoints, nm1d2);
  codegenReal2Mission_emxFree_real_T(&lengths);
  for (a__2_size = 0; a__2_size < 3; a__2_size++) {
    for (nm1d2 = 0; nm1d2 < k; nm1d2++) {
      segWayPoints->data[nm1d2 + segWayPoints->size[0] * a__2_size] =
        poses->data[nm1d2 + poses->size[0] * a__2_size];
    }
  }

  codegenReal2Mission_emxFree_real_T(&poses);
}

// Function for Chart: '<S2>/PreemptableMissionModeSelector'
void codegenReal2MissionModelClass::
  codegenReal2Mission_exit_internal_GuidanceLogic(void)
{
  codegenReal2Mission_DW.is_OrbitFollower =
    codegenReal2Mission_IN_NO_ACTIVE_CHILD;
  codegenReal2Mission_DW.is_WaypointFollower =
    codegenReal2Mission_IN_NO_ACTIVE_CHILD;
  codegenReal2Mission_DW.is_GuidanceLogic =
    codegenReal2Mission_IN_NO_ACTIVE_CHILD;
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

  if (0 <= trueCount - 1) {
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

  if (0 <= trueCount - 1) {
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
  emxArray_real_T_codegenReal2Mission_T *CheckPoints;
  emxArray_real_T_codegenReal2Mission_T *dummyWayPoint;
  emxArray_real_T_codegenReal2Mission_T *dummyWayPoint_0;
  emxArray_real_T_codegenReal2Mission_T *dummyWayPoint_1;
  emxArray_real_T_codegenReal2Mission_T *dummyWayPoint_2;
  emxArray_real_T_codegenReal2Mission_T *dummyWayPoint_3;
  emxArray_real_T_codegenReal2Mission_T *initWayPoint;
  emxArray_real_T_codegenReal2Mission_T *segWayPoints;
  uavDubinsConnection_codegenReal2Mission_T connectionObj;
  creal_T c_s;
  creal_T da;
  creal_T r;
  creal_T t;
  creal_T thisData;
  real_T a__1_data[28];
  real_T out[9];
  real_T out_0[9];
  real_T midpose_data[6];
  real_T LDp[4];
  real_T LUp[4];
  real_T ende[4];
  real_T rtb_startPose[4];
  real_T ct[3];
  real_T rtb_ReshapeRowVec[3];
  real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1[3];
  real_T turnVector[3];
  real_T distToCenter_tmp[2];
  real_T rtb_Sum1_0[2];
  real_T b_shi;
  real_T check;
  real_T fracSecs;
  real_T rtb_Abs1;
  real_T rtb_Down2Up_e;
  real_T rtb_Down_b;
  real_T rtb_Gain1;
  real_T rtb_ReshapeRowVec_tmp;
  real_T rtb_Sum_j;
  real_T rtb_Switch;
  real_T rtb_Switch_fe;
  real_T rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp;
  real_T second;
  real_T temp;
  real_T x2;
  int32_T midpose_size[2];
  int32_T SequenceID_prev;
  int32_T b;
  int32_T b_nrows;
  int32_T imo;
  int32_T initWayPoint_tmp;
  int32_T k;
  int32_T nrows;
  int32_T nrowx;
  int32_T status;
  uint8_T lookaheadFlag;
  uint8_T status_0;
  boolean_T exitg1;
  boolean_T guard1{ false };

  boolean_T guard2{ false };

  boolean_T p;
  boolean_T p_0;
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

    codegenReal2Mission_getLocalTime(&fracSecs, &second, &rtb_Switch_fe,
      &rtb_Abs1, &temp, &rtb_Down_b, &b_shi, &rtb_ReceiveCurrentMission_o1);
    fracSecs /= 1.0E+6;
    check = (((((b_shi + rtb_Down_b) + temp) + rtb_Abs1) + rtb_Switch_fe) +
             second) + fracSecs;
    if ((!std::isinf(check)) && (!std::isnan(check))) {
      if ((rtb_Down_b < 1.0) || (rtb_Down_b > 12.0)) {
        check = std::floor((rtb_Down_b - 1.0) / 12.0);
        b_shi += check;
        rtb_Down_b = ((rtb_Down_b - 1.0) - check * 12.0) + 1.0;
      }

      if (rtb_Down_b < 3.0) {
        b_shi--;
        rtb_Down_b += 9.0;
      } else {
        rtb_Down_b -= 3.0;
      }

      rtb_Down_b = ((((((365.0 * b_shi + std::floor(b_shi / 4.0)) - std::floor
                        (b_shi / 100.0)) + std::floor(b_shi / 400.0)) + std::
                      floor((153.0 * rtb_Down_b + 2.0) / 5.0)) + temp) + 60.0) -
        719529.0;
      temp = 1.34217729E+8 * rtb_Down_b;
      b_shi = temp - (temp - rtb_Down_b);
      temp = rtb_Down_b * 8.64E+7;
      check = b_shi * 8.64E+7 - temp;
      rtb_Down_b = (rtb_Down_b - b_shi) * 8.64E+7;
      thisData.im = rtb_Down_b + check;
      if (std::isnan(rtb_Down_b + check)) {
        thisData.im = 0.0;
      }

      if ((fracSecs < 0.0) || (1000.0 <= fracSecs)) {
        check = std::floor(fracSecs / 1000.0);
        second += check;
        fracSecs -= check * 1000.0;
      }

      thisData.re = temp;
      thisData = codegenReal2Mission_plus(codegenReal2Mission_plus
        (codegenReal2Mission_plus(thisData, (60.0 * rtb_Abs1 + rtb_Switch_fe) *
        60000.0), second * 1000.0), fracSecs);
    } else {
      thisData.re = check;
    }

    codegenReal2Mission_DW.Clock = thisData.re / 1000.0;

    // End of MATLAB Function: '<Root>/getCurrentTime'

    // Chart: '<S2>/MisisonCMDTemporalLogic' incorporates:
    //   DataStoreWrite: '<Root>/WriteClock'

    if (codegenReal2Mission_DW.is_active_c20_codegenReal2Mission == 0U) {
      codegenReal2Mission_DW.is_active_c20_codegenReal2Mission = 1U;
      codegenReal2Mission_DW.is_c20_codegenReal2Mission =
        codegenReal2Mission_IN_Pending;
      codegenReal2Mission_B.TriggerSend = 0.0;
    } else if (codegenReal2Mission_DW.is_c20_codegenReal2Mission == 1) {
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
    //   TriggerPort: '<S16>/ReachMissionTime'

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE,
                         (codegenReal2Mission_B.TriggerSend));
      if (zcEvent != NO_ZCEVENT) {
        // Send: '<S16>/SendMission'
        codegenReal2Mission_ReceiveCurrentMission_SendData
          (&codegenReal2Mission_B.ReceiveNextMission);
      }
    }

    // End of Outputs for SubSystem: '<S2>/TriggerBroadcastAtMissionTime'

    // Receive: '<S2>/ReceiveCurrentMission'
    SequenceID_prev = codegenReal2Mission_ReceiveCurrentMission_RecvData
      (&codegenReal2Mission_B.ReceiveCurrentMission_o2);
    rtb_ReceiveCurrentMission_o1 = (SequenceID_prev != 1);

    // Outputs for Triggered SubSystem: '<S2>/FeedbackMissionCMD' incorporates:
    //   TriggerPort: '<S10>/Trigger'

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      if (rtb_ReceiveCurrentMission_o1 &&
          (codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE != 1)) {
        // Send: '<S10>/Send'
        codegenReal2Mission_ReceiveThisMission_SendData
          (&codegenReal2Mission_B.ReceiveCurrentMission_o2);
      }

      codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE =
        rtb_ReceiveCurrentMission_o1;
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

    if (codegenReal2Mission_DW.is_active_c24_codegenReal2Mission == 0U) {
      codegenReal2Mission_DW.is_active_c24_codegenReal2Mission = 1U;
      codegenReal2Mission_DW.is_c24_codegenReal2Mission =
        codegenReal2Mission_IN_Pending;
      rtb_ReceiveCurrentMission_o1 = false;
    } else if (codegenReal2Mission_DW.is_c24_codegenReal2Mission == 1) {
      if ((codegenReal2Mission_B.MemoryCurrentMission.MissionMode > 0) &&
          (codegenReal2Mission_B.MemoryCurrentMission.SequenceId > 0)) {
        codegenReal2Mission_DW.is_c24_codegenReal2Mission =
          codegenReal2Mission_IN_Running;
        rtb_ReceiveCurrentMission_o1 = true;
      } else {
        rtb_ReceiveCurrentMission_o1 = false;
      }
    } else {
      // case IN_Running:
      rtb_ReceiveCurrentMission_o1 = true;
    }

    // End of Chart: '<S2>/TriggerStartSim'

    // Memory: '<S2>/MemoryPrevMissionLocation'
    fracSecs =
      codegenReal2Mission_DW.MemoryPrevMissionLocation_PreviousInput.Lat;
    second = codegenReal2Mission_DW.MemoryPrevMissionLocation_PreviousInput.Lon;
    temp = codegenReal2Mission_DW.MemoryPrevMissionLocation_PreviousInput.Alt;

    // Chart: '<S2>/PreemptableMissionModeSelector' incorporates:
    //   MATLAB Function: '<S102>/WayPointGenerator'
    //   MATLAB Function: '<S153>/WayPointGenerator'
    //   MATLAB Function: '<S71>/WayPointGenerator'
    //   Memory: '<S20>/MemoryTriggerWP'
    //   Memory: '<S21>/MemoryTriggerWP'
    //   Memory: '<S22>/MemoryTriggerWP'

    SequenceID_prev = codegenReal2Mission_DW.SequenceID_start;
    codegenReal2Mission_DW.SequenceID_start =
      codegenReal2Mission_B.MemoryCurrentMission.SequenceId;
    if (codegenReal2Mission_DW.is_active_c23_codegenReal2Mission == 0U) {
      codegenReal2Mission_DW.is_active_c23_codegenReal2Mission = 1U;
      codegenReal2Mission_DW.is_GuidanceLogic =
        codegenReal2Mission_IN_WaitToStart;
    } else {
      codegenReal2Mission_emxInit_real_T(&initWayPoint, 2);
      codegenReal2Mission_emxInit_real_T(&CheckPoints, 2);
      codegenReal2Mission_emxInit_real_T(&dummyWayPoint, 2);
      codegenReal2Mission_emxInit_real_T(&segWayPoints, 2);
      codegenReal2Mission_emxInit_real_T(&dummyWayPoint_0, 2);
      codegenReal2Mission_emxInit_real_T(&dummyWayPoint_1, 2);
      codegenReal2Mission_emxInit_real_T(&dummyWayPoint_2, 2);
      codegenReal2Mission_emxInit_real_T(&dummyWayPoint_3, 2);
      guard1 = false;
      if (SequenceID_prev != codegenReal2Mission_DW.SequenceID_start) {
        if ((codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 1) ||
            (codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 11)) {
          codegenReal2Mission_exit_internal_GuidanceLogic();
          codegenReal2Mission_DW.is_GuidanceLogic =
            codegenReal2Mission_IN_OrbitFollower;

          // Merge: '<S14>/ Merge 2'
          codegenReal2Mission_B.ResetTrigger = 1.0;
          if (codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 1) {
            codegenReal2Mission_DW.is_OrbitFollower =
              codegenReal2Mission_IN_CirclingNav;

            // Product: '<S19>/Map2Radian' incorporates:
            //   Bias: '<S19>/Bias'
            //   Constant: '<S19>/two_pi'
            //   DataTypeConversion: '<S19>/CastToDouble'
            //   Gain: '<S19>/HalveMissionUAV'
            //   Product: '<S19>/Divide'
            //   Sum: '<S19>/Minus'

            second = (static_cast<real_T>
                      (codegenReal2Mission_B.MemoryCurrentMission.FormationPos)
                      - static_cast<real_T>
                      (codegenReal2Mission_B.MemoryCurrentMission.numUAV + 1) *
                      0.5) * (6.2831853071795862 / static_cast<real_T>
                              (codegenReal2Mission_B.MemoryCurrentMission.numUAV));

            // Switch: '<S60>/Switch' incorporates:
            //   Abs: '<S60>/Abs'
            //   Bias: '<S60>/Bias'
            //   Bias: '<S60>/Bias1'
            //   Constant: '<S60>/Constant2'
            //   Constant: '<S61>/Constant'
            //   DataStoreRead: '<S19>/LatitudeGCS'
            //   Math: '<S60>/Math Function1'
            //   RelationalOperator: '<S61>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              fracSecs = LatitudeGCS;
            }

            // Abs: '<S57>/Abs1'
            rtb_Switch_fe = std::abs(fracSecs);

            // Switch: '<S57>/Switch' incorporates:
            //   Bias: '<S57>/Bias'
            //   Bias: '<S57>/Bias1'
            //   Constant: '<S48>/Constant'
            //   Constant: '<S48>/Constant1'
            //   Constant: '<S59>/Constant'
            //   Gain: '<S57>/Gain'
            //   Product: '<S57>/Divide1'
            //   RelationalOperator: '<S59>/Compare'
            //   Switch: '<S48>/Switch1'

            if (rtb_Switch_fe > 90.0) {
              // Signum: '<S57>/Sign1'
              if (fracSecs < 0.0) {
                fracSecs = -1.0;
              } else if (fracSecs > 0.0) {
                fracSecs = 1.0;
              } else if (fracSecs == 0.0) {
                fracSecs = 0.0;
              } else {
                fracSecs = (rtNaN);
              }

              fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
              SequenceID_prev = 180;
            } else {
              SequenceID_prev = 0;
            }

            // Sum: '<S48>/Sum' incorporates:
            //   DataStoreRead: '<S19>/LongitudeGCS'

            rtb_Switch_fe = static_cast<real_T>(SequenceID_prev) + LongitudeGCS;

            // Sum: '<S46>/Sum1'
            rtb_Abs1 =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
              fracSecs;

            // Switch: '<S54>/Switch' incorporates:
            //   Abs: '<S54>/Abs'
            //   Bias: '<S54>/Bias'
            //   Bias: '<S54>/Bias1'
            //   Constant: '<S54>/Constant2'
            //   Constant: '<S55>/Constant'
            //   Math: '<S54>/Math Function1'
            //   RelationalOperator: '<S55>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S51>/Abs1'
            temp = std::abs(rtb_Abs1);

            // Switch: '<S51>/Switch' incorporates:
            //   Bias: '<S51>/Bias'
            //   Bias: '<S51>/Bias1'
            //   Constant: '<S47>/Constant'
            //   Constant: '<S47>/Constant1'
            //   Constant: '<S53>/Constant'
            //   Gain: '<S51>/Gain'
            //   Product: '<S51>/Divide1'
            //   RelationalOperator: '<S53>/Compare'
            //   Switch: '<S47>/Switch1'

            if (temp > 90.0) {
              // Signum: '<S51>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              temp = (-(temp + -90.0) + 90.0) * rtb_Abs1;
              SequenceID_prev = 180;
            } else {
              temp = rtb_Abs1;
              SequenceID_prev = 0;
            }

            // Switch: '<S58>/Switch' incorporates:
            //   Abs: '<S58>/Abs'
            //   Bias: '<S58>/Bias'
            //   Bias: '<S58>/Bias1'
            //   Constant: '<S58>/Constant2'
            //   Constant: '<S62>/Constant'
            //   Math: '<S58>/Math Function1'
            //   RelationalOperator: '<S62>/Compare'

            if (std::abs(rtb_Switch_fe) > 180.0) {
              rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S47>/Sum' incorporates:
            //   Sum: '<S46>/Sum1'

            rtb_Switch_fe =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon -
               rtb_Switch_fe) + static_cast<real_T>(SequenceID_prev);

            // UnitConversion: '<S50>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 0.017453292519943295 * temp;

            // UnitConversion: '<S65>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            fracSecs *= 0.017453292519943295;

            // Trigonometry: '<S66>/Trigonometric Function1'
            rtb_Down_b = std::sin(fracSecs);

            // Sum: '<S66>/Sum1' incorporates:
            //   Constant: '<S66>/Constant'
            //   Product: '<S66>/Product1'

            rtb_Down_b = 1.0 - codegenReal2Mission_ConstB.sqrt_g *
              codegenReal2Mission_ConstB.sqrt_g * rtb_Down_b * rtb_Down_b;

            // Product: '<S64>/Product1' incorporates:
            //   Constant: '<S64>/Constant1'
            //   Sqrt: '<S64>/sqrt'

            temp = 6.378137E+6 / std::sqrt(rtb_Down_b);

            // Product: '<S49>/dNorth' incorporates:
            //   Constant: '<S64>/Constant2'
            //   Product: '<S64>/Product3'
            //   Trigonometry: '<S64>/Trigonometric Function1'

            rtb_Down_b = rtb_Abs1 / rt_atan2d_snf(1.0, temp *
              codegenReal2Mission_ConstB.Sum1_fi / rtb_Down_b);

            // Switch: '<S52>/Switch' incorporates:
            //   Abs: '<S52>/Abs'
            //   Bias: '<S52>/Bias'
            //   Bias: '<S52>/Bias1'
            //   Constant: '<S52>/Constant2'
            //   Constant: '<S56>/Constant'
            //   Math: '<S52>/Math Function1'
            //   RelationalOperator: '<S56>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Switch_fe) > 180.0) {
              rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) + -180.0;
            }

            // Product: '<S49>/dEast' incorporates:
            //   Constant: '<S64>/Constant3'
            //   Product: '<S64>/Product4'
            //   Trigonometry: '<S64>/Trigonometric Function'
            //   Trigonometry: '<S64>/Trigonometric Function2'
            //   UnitConversion: '<S50>/Unit Conversion'

            temp = 1.0 / rt_atan2d_snf(1.0, temp * std::cos(fracSecs)) *
              (0.017453292519943295 * rtb_Switch_fe);

            // Sum: '<S49>/Sum2' incorporates:
            //   Product: '<S49>/x*cos'
            //   Product: '<S49>/y*sin'

            fracSecs = temp * 0.0 + rtb_Down_b;

            // Sum: '<S49>/Sum3' incorporates:
            //   Product: '<S49>/x*sin'
            //   Product: '<S49>/y*cos'

            rtb_Abs1 = temp - rtb_Down_b * 0.0;

            // SignalConversion generated from: '<S19>/Orbit Follower' incorporates:
            //   DataStoreRead: '<S19>/AltitudeGCS'
            //   Gain: '<S19>/inverse'
            //   Sum: '<S46>/Sum'
            //   UnaryMinus: '<S46>/Ze2height'

            ct[0] = fracSecs;
            ct[1] = rtb_Abs1;
            ct[2] =
              -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
                -AltitudeGCS);

            // MATLABSystem: '<S19>/Orbit Follower' incorporates:
            //   DataTypeConversion: '<S19>/Param1'
            //   DataTypeConversion: '<S19>/Param2'
            //   Memory: '<S2>/DelayPose'
            //   SignalConversion generated from: '<S19>/Orbit Follower'

            b_shi = codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
            codegenReal2Mission_DW.obj_a.OrbitRadiusFlag = 0U;
            if (codegenReal2Mission_B.MemoryCurrentMission.params.Param1 <=
                220.0F) {
              b_shi = 220.0;
              codegenReal2Mission_DW.obj_a.OrbitRadiusFlag = 1U;
            }

            codegenReal2Mission_DW.obj_a.LookaheadDistFlag = 0U;
            codegenReal2Mission_DW.obj_a.LookaheadDistFlag = 1U;
            rtb_Gain1 = codegenReal2Mission_DW.DelayPose_PreviousInput[0] -
              fracSecs;
            rtb_Sum1_0[0] = rtb_Gain1;
            rtb_Down2Up_e = codegenReal2Mission_DW.DelayPose_PreviousInput[1] -
              rtb_Abs1;
            rtb_Sum1_0[1] = rtb_Down2Up_e;
            if (codegenReal2Mission_norm(rtb_Sum1_0) < 2.47032822920623E-323) {
              rtb_ReshapeRowVec[2] = ct[2];

              // BusCreator: '<S19>/GuidanceCMDBusCreator'
              codegenReal2Mission_B.GuidanceCmds.HeadingAngle =
                codegenReal2Mission_DW.DelayPose_PreviousInput[3];

              // Merge: '<S14>/ Merge '
              codegenReal2Mission_B.thisTaskStatus =
                codegenReal2Mission_DW.obj_a.NumCircles;
            } else {
              p = false;
              p_0 = true;
              nrowx = 0;
              exitg1 = false;
              while ((!exitg1) && (nrowx < 3)) {
                if ((codegenReal2Mission_DW.obj_a.OrbitCenterInternal[nrowx] ==
                     ct[nrowx]) || (std::isnan
                                    (codegenReal2Mission_DW.obj_a.OrbitCenterInternal
                                     [nrowx]) && std::isnan(ct[nrowx]))) {
                  nrowx++;
                } else {
                  p_0 = false;
                  exitg1 = true;
                }
              }

              if (p_0) {
                p = true;
              }

              guard2 = false;
              if (!p) {
                guard2 = true;
              } else {
                p = false;
                if ((codegenReal2Mission_DW.obj_a.OrbitRadiusInternal == b_shi) ||
                    (std::isnan(codegenReal2Mission_DW.obj_a.OrbitRadiusInternal)
                     && std::isnan(b_shi))) {
                  p = true;
                }

                if (!p) {
                  guard2 = true;
                }
              }

              if (guard2) {
                codegenReal2Mission_DW.obj_a.NumCircles = 0.0;
                codegenReal2Mission_DW.obj_a.OrbitCenterInternal[0] = fracSecs;
                codegenReal2Mission_DW.obj_a.OrbitCenterInternal[1] = rtb_Abs1;
                codegenReal2Mission_DW.obj_a.OrbitCenterInternal[2] = ct[2];
                codegenReal2Mission_DW.obj_a.OrbitRadiusInternal = b_shi;
                codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag = true;
              }

              if (35.0 >= b_shi) {
                codegenReal2Mission_DW.obj_a.LookaheadDistance = 0.9 * b_shi;
              } else {
                codegenReal2Mission_DW.obj_a.LookaheadDistance = 35.0;
              }

              distToCenter_tmp[0] = rtb_Gain1;
              distToCenter_tmp[1] = rtb_Down2Up_e;
              rtb_Switch_fe = std::sqrt(rtb_Down2Up_e * rtb_Down2Up_e +
                rtb_Gain1 * rtb_Gain1);
              check = b_shi + codegenReal2Mission_DW.obj_a.LookaheadDistance;
              rtb_Switch = std::abs(check);
              p = !std::isinf(rtb_Switch);
              p_0 = !std::isnan(rtb_Switch);
              if (p && p_0) {
                if (rtb_Switch <= 2.2250738585072014E-308) {
                  rtb_Down_b = 4.94065645841247E-324;
                } else {
                  frexp(rtb_Switch, &imo);
                  rtb_Down_b = std::ldexp(1.0, imo - 53);
                }
              } else {
                rtb_Down_b = (rtNaN);
              }

              guard2 = false;
              if (rtb_Switch_fe >= check - 5.0 * rtb_Down_b) {
                guard2 = true;
              } else {
                if (p && p_0) {
                  if (rtb_Switch <= 2.2250738585072014E-308) {
                    rtb_Down_b = 4.94065645841247E-324;
                  } else {
                    frexp(rtb_Switch, &b_nrows);
                    rtb_Down_b = std::ldexp(1.0, b_nrows - 53);
                  }
                } else {
                  rtb_Down_b = (rtNaN);
                }

                if (rtb_Switch_fe <= (b_shi -
                                      codegenReal2Mission_DW.obj_a.LookaheadDistance)
                    + 5.0 * rtb_Down_b) {
                  guard2 = true;
                } else {
                  if (codegenReal2Mission_DW.obj_a.StartFlag) {
                    codegenReal2Mission_DW.obj_a.PrevPosition[0] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                    codegenReal2Mission_DW.obj_a.PrevPosition[1] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                    codegenReal2Mission_DW.obj_a.PrevPosition[2] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                    codegenReal2Mission_DW.obj_a.StartFlag = false;
                  }

                  rtb_Sum1_0[0] = rtb_Gain1;
                  rtb_Sum1_0[1] = rtb_Down2Up_e;
                  rtb_Down_b = codegenReal2Mission_norm(rtb_Sum1_0);
                  rtb_Switch = codegenReal2Mission_DW.obj_a.LookaheadDistance *
                    codegenReal2Mission_DW.obj_a.LookaheadDistance;
                  rtb_Switch_fe = ((rtb_Switch - b_shi * b_shi) + rtb_Down_b *
                                   rtb_Down_b) / (2.0 * rtb_Down_b);
                  b_shi = fracSecs -
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  x2 = b_shi * rtb_Switch_fe / rtb_Down_b +
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  check = rtb_Abs1 -
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  rtb_Sum_j = check * rtb_Switch_fe / rtb_Down_b +
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  rtb_Switch = std::sqrt(rtb_Switch - rtb_Switch_fe *
                    rtb_Switch_fe);
                  rtb_Switch_fe = check * rtb_Switch / rtb_Down_b;
                  distToCenter_tmp[0] = x2 - rtb_Switch_fe;
                  distToCenter_tmp[1] = rtb_Switch_fe + x2;
                  rtb_Switch_fe = b_shi * rtb_Switch / rtb_Down_b;
                  rtb_Down_b = rtb_Switch_fe + rtb_Sum_j;
                  rtb_Switch = rtb_Sum_j - rtb_Switch_fe;
                  if ((codegenReal2Mission_B.MemoryCurrentMission.params.Param2 ==
                       0.0F) &&
                      (!codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag)) {
                    rtb_Sum_j =
                      codegenReal2Mission_DW.obj_a.TurnDirectionInternal;
                  } else {
                    rtb_Sum_j =
                      codegenReal2Mission_B.MemoryCurrentMission.params.Param2;
                  }

                  turnVector[0] = codegenReal2Mission_DW.obj_a.PrevPosition[0] -
                    fracSecs;
                  turnVector[1] = codegenReal2Mission_DW.obj_a.PrevPosition[1] -
                    rtb_Abs1;
                  rtb_ReshapeRowVec[0] = turnVector[0];
                  rtb_ReshapeRowVec[1] = turnVector[1];
                  rtb_ReshapeRowVec[2] = 0.0;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    rtb_Gain1;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                    rtb_Down2Up_e;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                  if (rtb_Sum_j < 0.0) {
                    rtb_ReshapeRowVec[0] = rtb_Gain1;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                      turnVector[0];
                    rtb_ReshapeRowVec[1] = rtb_Down2Up_e;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                      turnVector[1];
                    rtb_ReshapeRowVec[2] = 0.0;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                    rtb_Sum_j = -1.0;
                  } else if (rtb_Sum_j > 0.0) {
                    rtb_Sum_j = 1.0;
                  } else if (rtb_Sum_j == 0.0) {
                    rtb_Sum_j = 0.0;
                  } else {
                    rtb_Sum_j = (rtNaN);
                  }

                  rtb_Switch_fe = codegenReal2Mission_norm_b(rtb_ReshapeRowVec);
                  rtb_Down2Up_e = codegenReal2Mission_norm_b
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1);
                  rtb_Gain1 = rtb_ReshapeRowVec[0] / rtb_Switch_fe;
                  x2 = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] /
                    rtb_Down2Up_e;
                  rtb_ReshapeRowVec_tmp = rtb_ReshapeRowVec[1] / rtb_Switch_fe;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp =
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] /
                    rtb_Down2Up_e;
                  codegenReal2Mission_DW.obj_a.PrevPosition[0] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  codegenReal2Mission_DW.obj_a.PrevPosition[1] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  codegenReal2Mission_DW.obj_a.PrevPosition[2] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                  codegenReal2Mission_DW.obj_a.NumCircles += rt_atan2d_snf
                    (rtb_Gain1 *
                     rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp - x2
                     * rtb_ReshapeRowVec_tmp, (rtb_Gain1 * x2 +
                      rtb_ReshapeRowVec_tmp *
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp) +
                     0.0 / rtb_Switch_fe * (0.0 / rtb_Down2Up_e)) / 2.0 /
                    3.1415926535897931;

                  // Merge: '<S14>/ Merge ' incorporates:
                  //   DataTypeConversion: '<S19>/Param2'

                  codegenReal2Mission_B.thisTaskStatus =
                    codegenReal2Mission_DW.obj_a.NumCircles;
                  switch (static_cast<int32_T>(rtb_Sum_j)) {
                   case 1:
                    if ((distToCenter_tmp[0] -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Down_b -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi > 0.0) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }
                    break;

                   case -1:
                    if ((distToCenter_tmp[0] -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Down_b -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi < 0.0) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }
                    break;

                   default:
                    if (std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                          (rtb_Down_b -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                           distToCenter_tmp[0] -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                          codegenReal2Mission_DW.DelayPose_PreviousInput[3])) <
                        std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                          (rtb_Switch -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                           distToCenter_tmp[1] -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                          codegenReal2Mission_DW.DelayPose_PreviousInput[3]))) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }

                    if ((rtb_Gain1 -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Switch -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi > 0.0) {
                      codegenReal2Mission_DW.obj_a.TurnDirectionInternal = 1.0;
                    } else {
                      codegenReal2Mission_DW.obj_a.TurnDirectionInternal = -1.0;
                    }

                    codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag = false;
                    break;
                  }
                }
              }

              if (guard2) {
                rtb_Switch_fe = codegenReal2Mission_norm(distToCenter_tmp);
                rtb_Gain1 = rtb_Gain1 / rtb_Switch_fe * b_shi + fracSecs;
                rtb_Switch = rtb_Down2Up_e / rtb_Switch_fe * b_shi + rtb_Abs1;

                // Merge: '<S14>/ Merge '
                codegenReal2Mission_B.thisTaskStatus =
                  codegenReal2Mission_DW.obj_a.NumCircles;
              }

              rtb_ReshapeRowVec[2] = ct[2];

              // BusCreator: '<S19>/GuidanceCMDBusCreator' incorporates:
              //   DataTypeConversion: '<S19>/Param2'

              codegenReal2Mission_B.GuidanceCmds.HeadingAngle = rt_atan2d_snf
                (rtb_Switch - codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                 rtb_Gain1 - codegenReal2Mission_DW.DelayPose_PreviousInput[0]);
            }

            // BusCreator: '<S19>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S19>/Param3'
            //   Gain: '<S19>/Down2Height'
            //   MATLABSystem: '<S19>/Orbit Follower'

            codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
            codegenReal2Mission_B.GuidanceCmds.AirSpeed =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Bias: '<S19>/ClockwiseRotation'
            //   Constant: '<S19>/InitialFlightPathAngle'
            //   Constant: '<S19>/InitialRollAngle'
            //   Constant: '<S19>/InitialRollAngleRate'
            //   DataStoreRead: '<S19>/AltitudeGCS'
            //   DataTypeConversion: '<S19>/Param1'
            //   DataTypeConversion: '<S19>/Param3'
            //   Gain: '<S19>/inverse'
            //   Product: '<S19>/EastDis'
            //   Product: '<S19>/NorthDis'
            //   Reshape: '<S19>/Reshape'
            //   Sum: '<S19>/SumInitEast'
            //   Sum: '<S19>/SumInitNorth'
            //   Sum: '<S46>/Sum'
            //   Trigonometry: '<S19>/Cos'
            //   Trigonometry: '<S19>/Sin'

            codegenReal2Mission_B.InitialState[0] = std::cos(second) *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1 +
              fracSecs;
            codegenReal2Mission_B.InitialState[1] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1 * std::
              sin(second) + rtb_Abs1;
            codegenReal2Mission_B.InitialState[2] =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
              -AltitudeGCS;
            codegenReal2Mission_B.InitialState[3] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
            codegenReal2Mission_B.InitialState[4] = second + 1.5707963267948966;
            codegenReal2Mission_B.InitialState[5] = 0.0;
            codegenReal2Mission_B.InitialState[6] = 0.0;
            codegenReal2Mission_B.InitialState[7] = 0.0;
          } else {
            codegenReal2Mission_DW.is_OrbitFollower =
              codegenReal2Mission_IN_CircleDisplayNav;

            // Product: '<S18>/Divide' incorporates:
            //   DataTypeConversion: '<S18>/Param1'

            second =
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat /
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1;

            // Switch: '<S37>/Switch' incorporates:
            //   Abs: '<S37>/Abs'
            //   Bias: '<S37>/Bias'
            //   Bias: '<S37>/Bias1'
            //   Constant: '<S37>/Constant2'
            //   Constant: '<S38>/Constant'
            //   DataStoreRead: '<S18>/LatitudeGCS'
            //   Math: '<S37>/Math Function1'
            //   RelationalOperator: '<S38>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              fracSecs = LatitudeGCS;
            }

            // Abs: '<S34>/Abs1'
            rtb_Switch_fe = std::abs(fracSecs);

            // Switch: '<S34>/Switch' incorporates:
            //   Bias: '<S34>/Bias'
            //   Bias: '<S34>/Bias1'
            //   Constant: '<S25>/Constant'
            //   Constant: '<S25>/Constant1'
            //   Constant: '<S36>/Constant'
            //   Gain: '<S34>/Gain'
            //   Product: '<S34>/Divide1'
            //   RelationalOperator: '<S36>/Compare'
            //   Switch: '<S25>/Switch1'

            if (rtb_Switch_fe > 90.0) {
              // Signum: '<S34>/Sign1'
              if (fracSecs < 0.0) {
                fracSecs = -1.0;
              } else if (fracSecs > 0.0) {
                fracSecs = 1.0;
              } else if (fracSecs == 0.0) {
                fracSecs = 0.0;
              } else {
                fracSecs = (rtNaN);
              }

              fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
              SequenceID_prev = 180;
            } else {
              SequenceID_prev = 0;
            }

            // Sum: '<S25>/Sum' incorporates:
            //   DataStoreRead: '<S18>/LongitudeGCS'

            rtb_Switch_fe = static_cast<real_T>(SequenceID_prev) + LongitudeGCS;

            // Sum: '<S23>/Sum1'
            rtb_Abs1 =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
              fracSecs;

            // Switch: '<S31>/Switch' incorporates:
            //   Abs: '<S31>/Abs'
            //   Bias: '<S31>/Bias'
            //   Bias: '<S31>/Bias1'
            //   Constant: '<S31>/Constant2'
            //   Constant: '<S32>/Constant'
            //   Math: '<S31>/Math Function1'
            //   RelationalOperator: '<S32>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S28>/Abs1'
            temp = std::abs(rtb_Abs1);

            // Switch: '<S28>/Switch' incorporates:
            //   Bias: '<S28>/Bias'
            //   Bias: '<S28>/Bias1'
            //   Constant: '<S24>/Constant'
            //   Constant: '<S24>/Constant1'
            //   Constant: '<S30>/Constant'
            //   Gain: '<S28>/Gain'
            //   Product: '<S28>/Divide1'
            //   RelationalOperator: '<S30>/Compare'
            //   Switch: '<S24>/Switch1'

            if (temp > 90.0) {
              // Signum: '<S28>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              temp = (-(temp + -90.0) + 90.0) * rtb_Abs1;
              SequenceID_prev = 180;
            } else {
              temp = rtb_Abs1;
              SequenceID_prev = 0;
            }

            // Switch: '<S35>/Switch' incorporates:
            //   Abs: '<S35>/Abs'
            //   Bias: '<S35>/Bias'
            //   Bias: '<S35>/Bias1'
            //   Constant: '<S35>/Constant2'
            //   Constant: '<S39>/Constant'
            //   Math: '<S35>/Math Function1'
            //   RelationalOperator: '<S39>/Compare'

            if (std::abs(rtb_Switch_fe) > 180.0) {
              rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S24>/Sum' incorporates:
            //   Sum: '<S23>/Sum1'

            rtb_Switch_fe =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon -
               rtb_Switch_fe) + static_cast<real_T>(SequenceID_prev);

            // UnitConversion: '<S27>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 0.017453292519943295 * temp;

            // UnitConversion: '<S42>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            fracSecs *= 0.017453292519943295;

            // Trigonometry: '<S43>/Trigonometric Function1'
            rtb_Down_b = std::sin(fracSecs);

            // Sum: '<S43>/Sum1' incorporates:
            //   Constant: '<S43>/Constant'
            //   Product: '<S43>/Product1'

            rtb_Down_b = 1.0 - codegenReal2Mission_ConstB.sqrt_mc *
              codegenReal2Mission_ConstB.sqrt_mc * rtb_Down_b * rtb_Down_b;

            // Product: '<S41>/Product1' incorporates:
            //   Constant: '<S41>/Constant1'
            //   Sqrt: '<S41>/sqrt'

            temp = 6.378137E+6 / std::sqrt(rtb_Down_b);

            // Product: '<S26>/dNorth' incorporates:
            //   Constant: '<S41>/Constant2'
            //   Product: '<S41>/Product3'
            //   Trigonometry: '<S41>/Trigonometric Function1'

            rtb_Down_b = rtb_Abs1 / rt_atan2d_snf(1.0, temp *
              codegenReal2Mission_ConstB.Sum1_a / rtb_Down_b);

            // Switch: '<S29>/Switch' incorporates:
            //   Abs: '<S29>/Abs'
            //   Bias: '<S29>/Bias'
            //   Bias: '<S29>/Bias1'
            //   Constant: '<S29>/Constant2'
            //   Constant: '<S33>/Constant'
            //   Math: '<S29>/Math Function1'
            //   RelationalOperator: '<S33>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Switch_fe) > 180.0) {
              rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) + -180.0;
            }

            // Product: '<S26>/dEast' incorporates:
            //   Constant: '<S41>/Constant3'
            //   Product: '<S41>/Product4'
            //   Trigonometry: '<S41>/Trigonometric Function'
            //   Trigonometry: '<S41>/Trigonometric Function2'
            //   UnitConversion: '<S27>/Unit Conversion'

            temp = 1.0 / rt_atan2d_snf(1.0, temp * std::cos(fracSecs)) *
              (0.017453292519943295 * rtb_Switch_fe);

            // Sum: '<S26>/Sum2' incorporates:
            //   Product: '<S26>/x*cos'
            //   Product: '<S26>/y*sin'

            fracSecs = temp * 0.0 + rtb_Down_b;

            // Sum: '<S26>/Sum3' incorporates:
            //   Product: '<S26>/x*sin'
            //   Product: '<S26>/y*cos'

            rtb_Abs1 = temp - rtb_Down_b * 0.0;

            // Sum: '<S18>/SumUp' incorporates:
            //   DataStoreRead: '<S18>/AltitudeGCS'
            //   Gain: '<S18>/inverse'
            //   Sum: '<S23>/Sum'

            temp =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
               -AltitudeGCS) +
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;

            // SignalConversion generated from: '<S18>/Orbit Follower' incorporates:
            //   Gain: '<S18>/Up2Down'

            ct[0] = fracSecs;
            ct[1] = rtb_Abs1;
            ct[2] = -temp;

            // MATLABSystem: '<S18>/Orbit Follower' incorporates:
            //   DataTypeConversion: '<S18>/Param1'
            //   DataTypeConversion: '<S18>/Param2'
            //   Gain: '<S18>/Up2Down'
            //   Memory: '<S2>/DelayPose'
            //   SignalConversion generated from: '<S18>/Orbit Follower'

            b_shi = codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
            codegenReal2Mission_DW.obj_n.OrbitRadiusFlag = 0U;
            if (codegenReal2Mission_B.MemoryCurrentMission.params.Param1 <=
                220.0F) {
              b_shi = 220.0;
              codegenReal2Mission_DW.obj_n.OrbitRadiusFlag = 1U;
            }

            codegenReal2Mission_DW.obj_n.LookaheadDistFlag = 0U;
            codegenReal2Mission_DW.obj_n.LookaheadDistFlag = 1U;
            rtb_Gain1 = codegenReal2Mission_DW.DelayPose_PreviousInput[0] -
              fracSecs;
            rtb_Sum1_0[0] = rtb_Gain1;
            rtb_Down2Up_e = codegenReal2Mission_DW.DelayPose_PreviousInput[1] -
              rtb_Abs1;
            rtb_Sum1_0[1] = rtb_Down2Up_e;
            if (codegenReal2Mission_norm(rtb_Sum1_0) < 2.47032822920623E-323) {
              rtb_ReshapeRowVec[2] = -temp;

              // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
              //   Gain: '<S18>/Up2Down'

              codegenReal2Mission_B.GuidanceCmds.HeadingAngle =
                codegenReal2Mission_DW.DelayPose_PreviousInput[3];

              // Merge: '<S14>/ Merge '
              codegenReal2Mission_B.thisTaskStatus =
                codegenReal2Mission_DW.obj_n.NumCircles;
            } else {
              p = false;
              p_0 = true;
              nrowx = 0;
              exitg1 = false;
              while ((!exitg1) && (nrowx < 3)) {
                if ((codegenReal2Mission_DW.obj_n.OrbitCenterInternal[nrowx] ==
                     ct[nrowx]) || (std::isnan
                                    (codegenReal2Mission_DW.obj_n.OrbitCenterInternal
                                     [nrowx]) && std::isnan(ct[nrowx]))) {
                  nrowx++;
                } else {
                  p_0 = false;
                  exitg1 = true;
                }
              }

              if (p_0) {
                p = true;
              }

              guard2 = false;
              if (!p) {
                guard2 = true;
              } else {
                p = false;
                if ((codegenReal2Mission_DW.obj_n.OrbitRadiusInternal == b_shi) ||
                    (std::isnan(codegenReal2Mission_DW.obj_n.OrbitRadiusInternal)
                     && std::isnan(b_shi))) {
                  p = true;
                }

                if (!p) {
                  guard2 = true;
                }
              }

              if (guard2) {
                codegenReal2Mission_DW.obj_n.NumCircles = 0.0;
                codegenReal2Mission_DW.obj_n.OrbitCenterInternal[0] = fracSecs;
                codegenReal2Mission_DW.obj_n.OrbitCenterInternal[1] = rtb_Abs1;
                codegenReal2Mission_DW.obj_n.OrbitCenterInternal[2] = -temp;
                codegenReal2Mission_DW.obj_n.OrbitRadiusInternal = b_shi;
                codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag = true;
              }

              if (35.0 >= b_shi) {
                codegenReal2Mission_DW.obj_n.LookaheadDistance = 0.9 * b_shi;
              } else {
                codegenReal2Mission_DW.obj_n.LookaheadDistance = 35.0;
              }

              distToCenter_tmp[0] = rtb_Gain1;
              distToCenter_tmp[1] = rtb_Down2Up_e;
              rtb_Switch_fe = std::sqrt(rtb_Down2Up_e * rtb_Down2Up_e +
                rtb_Gain1 * rtb_Gain1);
              check = b_shi + codegenReal2Mission_DW.obj_n.LookaheadDistance;
              rtb_Switch = std::abs(check);
              p = !std::isinf(rtb_Switch);
              p_0 = !std::isnan(rtb_Switch);
              if (p && p_0) {
                if (rtb_Switch <= 2.2250738585072014E-308) {
                  rtb_Down_b = 4.94065645841247E-324;
                } else {
                  frexp(rtb_Switch, &imo);
                  rtb_Down_b = std::ldexp(1.0, imo - 53);
                }
              } else {
                rtb_Down_b = (rtNaN);
              }

              guard2 = false;
              if (rtb_Switch_fe >= check - 5.0 * rtb_Down_b) {
                guard2 = true;
              } else {
                if (p && p_0) {
                  if (rtb_Switch <= 2.2250738585072014E-308) {
                    rtb_Down_b = 4.94065645841247E-324;
                  } else {
                    frexp(rtb_Switch, &b_nrows);
                    rtb_Down_b = std::ldexp(1.0, b_nrows - 53);
                  }
                } else {
                  rtb_Down_b = (rtNaN);
                }

                if (rtb_Switch_fe <= (b_shi -
                                      codegenReal2Mission_DW.obj_n.LookaheadDistance)
                    + 5.0 * rtb_Down_b) {
                  guard2 = true;
                } else {
                  if (codegenReal2Mission_DW.obj_n.StartFlag) {
                    codegenReal2Mission_DW.obj_n.PrevPosition[0] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                    codegenReal2Mission_DW.obj_n.PrevPosition[1] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                    codegenReal2Mission_DW.obj_n.PrevPosition[2] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                    codegenReal2Mission_DW.obj_n.StartFlag = false;
                  }

                  rtb_Sum1_0[0] = rtb_Gain1;
                  rtb_Sum1_0[1] = rtb_Down2Up_e;
                  rtb_Down_b = codegenReal2Mission_norm(rtb_Sum1_0);
                  rtb_Switch = codegenReal2Mission_DW.obj_n.LookaheadDistance *
                    codegenReal2Mission_DW.obj_n.LookaheadDistance;
                  rtb_Switch_fe = ((rtb_Switch - b_shi * b_shi) + rtb_Down_b *
                                   rtb_Down_b) / (2.0 * rtb_Down_b);
                  b_shi = fracSecs -
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  x2 = b_shi * rtb_Switch_fe / rtb_Down_b +
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  check = rtb_Abs1 -
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  rtb_Sum_j = check * rtb_Switch_fe / rtb_Down_b +
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  rtb_Switch = std::sqrt(rtb_Switch - rtb_Switch_fe *
                    rtb_Switch_fe);
                  rtb_Switch_fe = check * rtb_Switch / rtb_Down_b;
                  distToCenter_tmp[0] = x2 - rtb_Switch_fe;
                  distToCenter_tmp[1] = rtb_Switch_fe + x2;
                  rtb_Switch_fe = b_shi * rtb_Switch / rtb_Down_b;
                  rtb_Down_b = rtb_Switch_fe + rtb_Sum_j;
                  rtb_Switch = rtb_Sum_j - rtb_Switch_fe;
                  if ((codegenReal2Mission_B.MemoryCurrentMission.params.Param2 ==
                       0.0F) &&
                      (!codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag)) {
                    rtb_Sum_j =
                      codegenReal2Mission_DW.obj_n.TurnDirectionInternal;
                  } else {
                    rtb_Sum_j =
                      codegenReal2Mission_B.MemoryCurrentMission.params.Param2;
                  }

                  turnVector[0] = codegenReal2Mission_DW.obj_n.PrevPosition[0] -
                    fracSecs;
                  turnVector[1] = codegenReal2Mission_DW.obj_n.PrevPosition[1] -
                    rtb_Abs1;
                  rtb_ReshapeRowVec[0] = turnVector[0];
                  rtb_ReshapeRowVec[1] = turnVector[1];
                  rtb_ReshapeRowVec[2] = 0.0;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    rtb_Gain1;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                    rtb_Down2Up_e;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                  if (rtb_Sum_j < 0.0) {
                    rtb_ReshapeRowVec[0] = rtb_Gain1;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                      turnVector[0];
                    rtb_ReshapeRowVec[1] = rtb_Down2Up_e;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                      turnVector[1];
                    rtb_ReshapeRowVec[2] = 0.0;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                    rtb_Sum_j = -1.0;
                  } else if (rtb_Sum_j > 0.0) {
                    rtb_Sum_j = 1.0;
                  } else if (rtb_Sum_j == 0.0) {
                    rtb_Sum_j = 0.0;
                  } else {
                    rtb_Sum_j = (rtNaN);
                  }

                  rtb_Switch_fe = codegenReal2Mission_norm_b(rtb_ReshapeRowVec);
                  rtb_Down2Up_e = codegenReal2Mission_norm_b
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1);
                  rtb_Gain1 = rtb_ReshapeRowVec[0] / rtb_Switch_fe;
                  x2 = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] /
                    rtb_Down2Up_e;
                  rtb_ReshapeRowVec_tmp = rtb_ReshapeRowVec[1] / rtb_Switch_fe;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp =
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] /
                    rtb_Down2Up_e;
                  codegenReal2Mission_DW.obj_n.PrevPosition[0] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  codegenReal2Mission_DW.obj_n.PrevPosition[1] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  codegenReal2Mission_DW.obj_n.PrevPosition[2] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                  codegenReal2Mission_DW.obj_n.NumCircles += rt_atan2d_snf
                    (rtb_Gain1 *
                     rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp - x2
                     * rtb_ReshapeRowVec_tmp, (rtb_Gain1 * x2 +
                      rtb_ReshapeRowVec_tmp *
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp) +
                     0.0 / rtb_Switch_fe * (0.0 / rtb_Down2Up_e)) / 2.0 /
                    3.1415926535897931;

                  // Merge: '<S14>/ Merge ' incorporates:
                  //   DataTypeConversion: '<S18>/Param2'

                  codegenReal2Mission_B.thisTaskStatus =
                    codegenReal2Mission_DW.obj_n.NumCircles;
                  switch (static_cast<int32_T>(rtb_Sum_j)) {
                   case 1:
                    if ((distToCenter_tmp[0] -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Down_b -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi > 0.0) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }
                    break;

                   case -1:
                    if ((distToCenter_tmp[0] -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Down_b -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi < 0.0) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }
                    break;

                   default:
                    if (std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                          (rtb_Down_b -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                           distToCenter_tmp[0] -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                          codegenReal2Mission_DW.DelayPose_PreviousInput[3])) <
                        std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                          (rtb_Switch -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                           distToCenter_tmp[1] -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                          codegenReal2Mission_DW.DelayPose_PreviousInput[3]))) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }

                    if ((rtb_Gain1 -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Switch -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi > 0.0) {
                      codegenReal2Mission_DW.obj_n.TurnDirectionInternal = 1.0;
                    } else {
                      codegenReal2Mission_DW.obj_n.TurnDirectionInternal = -1.0;
                    }

                    codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag = false;
                    break;
                  }
                }
              }

              if (guard2) {
                rtb_Switch_fe = codegenReal2Mission_norm(distToCenter_tmp);
                rtb_Gain1 = rtb_Gain1 / rtb_Switch_fe * b_shi + fracSecs;
                rtb_Switch = rtb_Down2Up_e / rtb_Switch_fe * b_shi + rtb_Abs1;

                // Merge: '<S14>/ Merge '
                codegenReal2Mission_B.thisTaskStatus =
                  codegenReal2Mission_DW.obj_n.NumCircles;
              }

              rtb_ReshapeRowVec[2] = -temp;

              // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
              //   DataTypeConversion: '<S18>/Param2'
              //   Gain: '<S18>/Up2Down'

              codegenReal2Mission_B.GuidanceCmds.HeadingAngle = rt_atan2d_snf
                (rtb_Switch - codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                 rtb_Gain1 - codegenReal2Mission_DW.DelayPose_PreviousInput[0]);
            }

            // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S18>/Param3'
            //   Gain: '<S18>/Down2Height'
            //   MATLABSystem: '<S18>/Orbit Follower'

            codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
            codegenReal2Mission_B.GuidanceCmds.AirSpeed =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Bias: '<S18>/ClockwiseRotation'
            //   Constant: '<S18>/InitialFlightPathAngle'
            //   Constant: '<S18>/InitialRollAngle'
            //   Constant: '<S18>/InitialRollAngleRate'
            //   DataTypeConversion: '<S18>/Param1'
            //   DataTypeConversion: '<S18>/Param3'
            //   Product: '<S18>/EastDis'
            //   Product: '<S18>/NorthDis'
            //   Reshape: '<S18>/Reshape'
            //   Sum: '<S18>/SumInitEast'
            //   Sum: '<S18>/SumInitNorth'
            //   Trigonometry: '<S18>/Cos'
            //   Trigonometry: '<S18>/Sin'

            codegenReal2Mission_B.InitialState[0] = std::cos(second) *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1 +
              fracSecs;
            codegenReal2Mission_B.InitialState[1] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1 * std::
              sin(second) + rtb_Abs1;
            codegenReal2Mission_B.InitialState[2] = temp;
            codegenReal2Mission_B.InitialState[3] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
            codegenReal2Mission_B.InitialState[4] = second + 1.5707963267948966;
            codegenReal2Mission_B.InitialState[5] = 0.0;
            codegenReal2Mission_B.InitialState[6] = 0.0;
            codegenReal2Mission_B.InitialState[7] = 0.0;
          }
        } else if ((codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 2)
                   || (codegenReal2Mission_B.MemoryCurrentMission.MissionMode ==
                       22)) {
          codegenReal2Mission_exit_internal_GuidanceLogic();
          codegenReal2Mission_DW.is_GuidanceLogic =
            codegenReal2Mission_IN_WaypointFollower;

          // Merge: '<S14>/ Merge 2'
          codegenReal2Mission_B.ResetTrigger = 1.0;
          if (codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 2) {
            codegenReal2Mission_DW.is_WaypointFollower =
              codegenReal2Mission_IN_HorizontalFormationNav;

            // Gain: '<S22>/Gain' incorporates:
            //   Constant: '<S22>/One2ZeroIdx'
            //   Constant: '<S22>/Three'
            //   DataTypeConversion: '<S22>/CastToDouble'
            //   Math: '<S22>/ModRunWayLayer'
            //   Sum: '<S22>/Minus'

            rtb_Down_b = rt_modd_snf(static_cast<real_T>
              (codegenReal2Mission_B.MemoryCurrentMission.FormationPos) - 1.0,
              3.0) * 15.0;

            // Sum: '<S22>/BiasMissionAlt' incorporates:
            //   DataStoreRead: '<S22>/AltitudeGCS'
            //   Gain: '<S22>/inverse'
            //   Sum: '<S151>/Sum'
            //   UnaryMinus: '<S151>/Ze2height'

            b_shi =
              -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
                -AltitudeGCS) - rtb_Down_b;

            // Sum: '<S22>/BiasPrevAlt' incorporates:
            //   DataStoreRead: '<S22>/PrevAltitudeGCS'
            //   Gain: '<S22>/PrevInverse'
            //   Sum: '<S152>/Sum'
            //   UnaryMinus: '<S152>/Ze2height'

            rtb_Down_b = -(temp + -AltitudeGCS) - rtb_Down_b;

            // Abs: '<S167>/Abs' incorporates:
            //   Abs: '<S189>/Abs'
            //   DataStoreRead: '<S22>/LatitudeGCS'

            rtb_Switch_fe = std::abs(LatitudeGCS);

            // Switch: '<S167>/Switch' incorporates:
            //   Abs: '<S167>/Abs'
            //   Bias: '<S167>/Bias'
            //   Bias: '<S167>/Bias1'
            //   Constant: '<S167>/Constant2'
            //   Constant: '<S168>/Constant'
            //   DataStoreRead: '<S22>/LatitudeGCS'
            //   Math: '<S167>/Math Function1'
            //   RelationalOperator: '<S168>/Compare'

            if (rtb_Switch_fe > 180.0) {
              rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch = LatitudeGCS;
            }

            // Abs: '<S164>/Abs1'
            rtb_Abs1 = std::abs(rtb_Switch);

            // Switch: '<S164>/Switch' incorporates:
            //   Bias: '<S164>/Bias'
            //   Bias: '<S164>/Bias1'
            //   Constant: '<S155>/Constant'
            //   Constant: '<S155>/Constant1'
            //   Constant: '<S166>/Constant'
            //   Gain: '<S164>/Gain'
            //   Product: '<S164>/Divide1'
            //   RelationalOperator: '<S166>/Compare'
            //   Switch: '<S155>/Switch1'

            if (rtb_Abs1 > 90.0) {
              // Signum: '<S164>/Sign1'
              if (rtb_Switch < 0.0) {
                rtb_Switch = -1.0;
              } else if (rtb_Switch > 0.0) {
                rtb_Switch = 1.0;
              } else if (rtb_Switch == 0.0) {
                rtb_Switch = 0.0;
              } else {
                rtb_Switch = (rtNaN);
              }

              rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Sum: '<S155>/Sum' incorporates:
            //   DataStoreRead: '<S22>/LongitudeGCS'

            temp = static_cast<real_T>(imo) + LongitudeGCS;

            // Sum: '<S151>/Sum1'
            rtb_Abs1 =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
              rtb_Switch;

            // Switch: '<S161>/Switch' incorporates:
            //   Abs: '<S161>/Abs'
            //   Bias: '<S161>/Bias'
            //   Bias: '<S161>/Bias1'
            //   Constant: '<S161>/Constant2'
            //   Constant: '<S162>/Constant'
            //   Math: '<S161>/Math Function1'
            //   RelationalOperator: '<S162>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S158>/Abs1'
            check = std::abs(rtb_Abs1);

            // Switch: '<S158>/Switch' incorporates:
            //   Bias: '<S158>/Bias'
            //   Bias: '<S158>/Bias1'
            //   Constant: '<S154>/Constant'
            //   Constant: '<S154>/Constant1'
            //   Constant: '<S160>/Constant'
            //   Gain: '<S158>/Gain'
            //   Product: '<S158>/Divide1'
            //   RelationalOperator: '<S160>/Compare'
            //   Switch: '<S154>/Switch1'

            if (check > 90.0) {
              // Signum: '<S158>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              check = (-(check + -90.0) + 90.0) * rtb_Abs1;
              imo = 180;
            } else {
              check = rtb_Abs1;
              imo = 0;
            }

            // Switch: '<S165>/Switch' incorporates:
            //   Abs: '<S165>/Abs'
            //   Bias: '<S165>/Bias'
            //   Bias: '<S165>/Bias1'
            //   Constant: '<S165>/Constant2'
            //   Constant: '<S169>/Constant'
            //   Math: '<S165>/Math Function1'
            //   RelationalOperator: '<S169>/Compare'

            if (std::abs(temp) > 180.0) {
              temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S154>/Sum' incorporates:
            //   Sum: '<S151>/Sum1'

            temp =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon -
               temp) + static_cast<real_T>(imo);

            // UnitConversion: '<S157>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 0.017453292519943295 * check;

            // UnitConversion: '<S172>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch *= 0.017453292519943295;

            // Trigonometry: '<S173>/Trigonometric Function1'
            rtb_Down2Up_e = std::sin(rtb_Switch);

            // Sum: '<S173>/Sum1' incorporates:
            //   Constant: '<S173>/Constant'
            //   Product: '<S173>/Product1'

            rtb_Down2Up_e = 1.0 - codegenReal2Mission_ConstB.sqrt_m *
              codegenReal2Mission_ConstB.sqrt_m * rtb_Down2Up_e * rtb_Down2Up_e;

            // Product: '<S171>/Product1' incorporates:
            //   Constant: '<S171>/Constant1'
            //   Sqrt: '<S171>/sqrt'

            check = 6.378137E+6 / std::sqrt(rtb_Down2Up_e);

            // Product: '<S156>/dNorth' incorporates:
            //   Constant: '<S171>/Constant2'
            //   Product: '<S171>/Product3'
            //   Trigonometry: '<S171>/Trigonometric Function1'

            rtb_Down2Up_e = rtb_Abs1 / rt_atan2d_snf(1.0, check *
              codegenReal2Mission_ConstB.Sum1_m / rtb_Down2Up_e);

            // Switch: '<S159>/Switch' incorporates:
            //   Abs: '<S159>/Abs'
            //   Bias: '<S159>/Bias'
            //   Bias: '<S159>/Bias1'
            //   Constant: '<S159>/Constant2'
            //   Constant: '<S163>/Constant'
            //   Math: '<S159>/Math Function1'
            //   RelationalOperator: '<S163>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(temp) > 180.0) {
              temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
            }

            // Product: '<S156>/dEast' incorporates:
            //   Constant: '<S171>/Constant3'
            //   Product: '<S171>/Product4'
            //   Trigonometry: '<S171>/Trigonometric Function'
            //   Trigonometry: '<S171>/Trigonometric Function2'
            //   UnitConversion: '<S157>/Unit Conversion'

            check = 1.0 / rt_atan2d_snf(1.0, check * std::cos(rtb_Switch)) *
              (0.017453292519943295 * temp);

            // Sum: '<S156>/Sum2' incorporates:
            //   Product: '<S156>/x*cos'
            //   Product: '<S156>/y*sin'

            temp = check * 0.0 + rtb_Down2Up_e;

            // Sum: '<S156>/Sum3' incorporates:
            //   Product: '<S156>/x*sin'
            //   Product: '<S156>/y*cos'

            check -= rtb_Down2Up_e * 0.0;

            // Product: '<S22>/Map2Radian' incorporates:
            //   Constant: '<S22>/One2ZeroIdx'
            //   DataTypeConversion: '<S22>/CastToDouble'
            //   DataTypeConversion: '<S22>/Param3'
            //   Sum: '<S22>/Minus'

            rtb_Down2Up_e = (static_cast<real_T>
                             (codegenReal2Mission_B.MemoryCurrentMission.FormationPos)
                             - 1.0) *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param3;

            // Gain: '<S150>/Gain1'
            rtb_Gain1 = 0.017453292519943295 *
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

            // Outputs for Triggered SubSystem: '<S22>/WayPointGenerator' incorporates:
            //   TriggerPort: '<S153>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE,
                               (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput));
            if (zcEvent != NO_ZCEVENT) {
              // Reshape: '<S153>/ReshapeRowVec'
              rtb_ReshapeRowVec[0] = temp;
              rtb_ReshapeRowVec[1] = check;
              rtb_ReshapeRowVec[2] = b_shi;

              // MATLABSystem: '<S153>/RotateATMissionHdg' incorporates:
              //   SignalConversion generated from: '<S153>/RotateATMissionHdg'

              ct[0] = std::cos(rtb_Gain1);
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = std::sin
                (rtb_Gain1);
              out[0] = ct[0];
              out[3] = 0.0 * ct[0] -
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
              out[6] = 0.0 * ct[0] +
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] * 0.0;
              out[1] = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
              out[4] = 0.0 * rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                [0] + ct[0];
              out[7] = 0.0 * rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                [0] - ct[0] * 0.0;
              out[2] = -0.0;
              out[5] = 0.0;
              out[8] = 1.0;

              // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S22>/Param2'
              //   DataTypeConversion: '<S22>/Param3'
              //   Product: '<S153>/ProductScanWidth'

              rtb_Abs1 = std::ceil
                (codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                 (codegenReal2Mission_B.MemoryCurrentMission.params.Param3 *
                  static_cast<real_T>
                  (codegenReal2Mission_B.MemoryCurrentMission.numUAV)));
              rtb_Switch =
                codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                rtb_Abs1;
              connectionObj.FlightPathAngleLimit[0] = -0.175;
              connectionObj.FlightPathAngleLimit[1] = 0.175;
              connectionObj.MaxRollAngle = 0.29670597283903605;
              connectionObj.AirSpeed = 35.0;
              connectionObj.MinTurningRadius = 408.85657731051754;
              imo = static_cast<int32_T>(rtb_Abs1 * 2.0);
              SequenceID_prev = CheckPoints->size[0] * CheckPoints->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              CheckPoints->size[0] = imo;
              CheckPoints->size[1] = 4;
              codegenReal2Mission_emxEnsureCapacity_real_T(CheckPoints,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S22>/Param1'

              b_nrows = (imo << 2) - 1;
              for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                   SequenceID_prev++) {
                CheckPoints->data[SequenceID_prev] = 0.0;
              }

              for (b_nrows = 0; b_nrows < static_cast<int32_T>(rtb_Abs1);
                   b_nrows++) {
                if (rt_remd_snf(static_cast<real_T>(b_nrows) + 1.0, 2.0) == 1.0)
                {
                  imo = (b_nrows + 1) << 1;
                  rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                    rtb_Switch;
                  CheckPoints->data[imo - 2] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 2] = 0.0;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                    1.5707963267948966;
                  CheckPoints->data[imo - 1] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 1] =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                    1.5707963267948966;
                } else {
                  imo = (b_nrows + 1) << 1;
                  rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                    rtb_Switch;
                  CheckPoints->data[imo - 2] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 2] =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                    -1.5707963267948966;
                  CheckPoints->data[imo - 1] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 1] = 0.0;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                    -1.5707963267948966;
                }
              }

              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint->size[0] = 1;
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint->data[0] = 0.0;
              dummyWayPoint->data[1] = 0.0;
              dummyWayPoint->data[2] = 0.0;
              for (nrowx = 0; nrowx <= CheckPoints->size[0] - 2; nrowx++) {
                LUp[0] = CheckPoints->data[nrowx];
                LDp[0] = CheckPoints->data[nrowx + 1];
                LUp[1] = CheckPoints->data[nrowx + CheckPoints->size[0]];
                LDp[1] = CheckPoints->data[(nrowx + CheckPoints->size[0]) + 1];
                LUp[2] = CheckPoints->data[nrowx + (CheckPoints->size[0] << 1)];
                LDp[2] = CheckPoints->data[(nrowx + (CheckPoints->size[0] << 1))
                  + 1];
                LUp[3] = CheckPoints->data[nrowx + CheckPoints->size[0] * 3];
                LDp[3] = CheckPoints->data[(nrowx + CheckPoints->size[0] * 3) +
                  1];
                codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                  segWayPoints);
                SequenceID_prev = dummyWayPoint_0->size[0] *
                  dummyWayPoint_0->size[1];
                dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                  segWayPoints->size[0];
                dummyWayPoint_0->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                  SequenceID_prev);
                b_nrows = dummyWayPoint->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[SequenceID_prev +
                      dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                      data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                  }
                }

                b_nrows = segWayPoints->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->
                      size[0]) + dummyWayPoint_0->size[0] * imo] =
                      segWayPoints->data[SequenceID_prev + segWayPoints->size[0]
                      * imo];
                  }
                }

                SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                  SequenceID_prev);
                b_nrows = dummyWayPoint_0->size[0] * 3;
                for (imo = 0; imo < b_nrows; imo++) {
                  dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                }
              }

              LUp[0] = CheckPoints->data[CheckPoints->size[0] - 1];
              LDp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[(CheckPoints->size[0] +
                CheckPoints->size[0]) - 1];
              LDp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[(CheckPoints->size[0] +
                (CheckPoints->size[0] << 1)) - 1];
              LDp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
              LUp[3] = CheckPoints->data[(CheckPoints->size[0] +
                CheckPoints->size[0] * 3) - 1];
              LDp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
              codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                segWayPoints);
              SequenceID_prev = dummyWayPoint_0->size[0] * dummyWayPoint_0->
                size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                segWayPoints->size[0];
              dummyWayPoint_0->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              b_nrows = dummyWayPoint->size[0];
              nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  dummyWayPoint_0->data[SequenceID_prev + dummyWayPoint_0->size
                    [0] * imo] = dummyWayPoint->data[SequenceID_prev +
                    dummyWayPoint->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < nrows;
                     SequenceID_prev++) {
                  dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->size[0])
                    + dummyWayPoint_0->size[0] * imo] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }

              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              b_nrows = dummyWayPoint_0->size[0] * 3;
              for (imo = 0; imo < b_nrows; imo++) {
                dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
              }

              nrowx = dummyWayPoint->size[0] - 2;
              nrows = dummyWayPoint->size[0] - 1;
              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo] = dummyWayPoint->data[imo + 1];
              }

              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo + dummyWayPoint->size[0]] =
                  dummyWayPoint->data[(imo + dummyWayPoint->size[0]) + 1];
              }

              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo + (dummyWayPoint->size[0] << 1)] =
                  dummyWayPoint->data[(imo + (dummyWayPoint->size[0] << 1)) + 1];
              }

              if (1 > nrows) {
                b_nrows = -1;
              } else {
                b_nrows = nrowx;
              }

              SequenceID_prev = segWayPoints->size[0] * segWayPoints->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              segWayPoints->size[0] = b_nrows + 1;
              segWayPoints->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(segWayPoints,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                     SequenceID_prev++) {
                  segWayPoints->data[SequenceID_prev + segWayPoints->size[0] *
                    imo] = dummyWayPoint->data[SequenceID_prev +
                    dummyWayPoint->size[0] * imo];
                }
              }

              if (1 > nrows) {
                imo = -1;
                nrowx = -1;
              } else {
                imo = nrowx;
              }

              rtb_Abs1 = std::ceil(10240.0 / static_cast<real_T>(imo + 1));
              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint->size[0] = (nrowx + 1) * static_cast<int32_T>
                (rtb_Abs1);
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              b_nrows = segWayPoints->size[0];

              // Reshape: '<S22>/Reshape2Row' incorporates:
              //   Memory: '<S22>/MemoryPrevRelPos'

              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[1];
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[0];
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[2];

              // Product: '<S153>/RotateRelPrevPos' incorporates:
              //   MATLABSystem: '<S153>/RotateATMissionHdg'

              rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1, out, ct);

              // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
              //   Product: '<S153>/RotateRelPrevPos'

              for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                nrows = imo * b_nrows + -1;
                for (k = 1; k - 1 < b_nrows; k++) {
                  dummyWayPoint->data[nrows + k] = segWayPoints->data[k - 1];
                }
              }

              LDp[0] = ct[0];
              SequenceID_prev = segWayPoints->size[0] * static_cast<int32_T>
                (rtb_Abs1) - 1;
              for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                nrows = imo * b_nrows + SequenceID_prev;
                for (k = 1; k - 1 < b_nrows; k++) {
                  dummyWayPoint->data[nrows + k] = segWayPoints->data[(b_nrows +
                    k) - 1];
                }
              }

              LDp[1] = ct[1];
              nrowx = segWayPoints->size[0] << 1;
              SequenceID_prev = ((segWayPoints->size[0] * static_cast<int32_T>
                                  (rtb_Abs1)) << 1) - 1;
              for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                nrows = imo * b_nrows + SequenceID_prev;
                for (k = 1; k - 1 < b_nrows; k++) {
                  dummyWayPoint->data[nrows + k] = segWayPoints->data[(nrowx + k)
                    - 1];
                }
              }

              LDp[2] = ct[2];
              LDp[3] = 1.5707963267948966;
              LUp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
              LUp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
              codegenReal2Mission_genSegWP_i(&connectionObj, LDp, LUp, 100.0,
                segWayPoints);
              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              initWayPoint->size[0] = segWayPoints->size[0] +
                dummyWayPoint->size[0];
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              b_nrows = segWayPoints->size[0];
              nrows = dummyWayPoint->size[0];
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[SequenceID_prev + initWayPoint->size[0] *
                    imo] = segWayPoints->data[SequenceID_prev +
                    segWayPoints->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + segWayPoints->size[0]) +
                    initWayPoint->size[0] * imo] = dummyWayPoint->
                    data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < 10240;
                     SequenceID_prev++) {
                  codegenReal2Mission_B.WayPoint[SequenceID_prev + 10240 * imo] =
                    initWayPoint->data[SequenceID_prev + initWayPoint->size[0] *
                    imo];
                }
              }

              for (imo = 0; imo < 10240; imo++) {
                // MATLAB Function: '<S153>/biasWayPoint'
                codegenReal2Mission_B.rtb_WayPoint_m[imo] =
                  codegenReal2Mission_B.WayPoint[imo] + rtb_Down2Up_e;
                codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240] =
                  codegenReal2Mission_B.WayPoint[imo + 10240];
                codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480] =
                  codegenReal2Mission_B.WayPoint[imo + 20480];

                // Product: '<S153>/RotateIndivWayPoint' incorporates:
                //   MATLABSystem: '<S153>/RotateATMissionHdg'

                for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev++)
                {
                  b_nrows = imo + 10240 * SequenceID_prev;
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev] * codegenReal2Mission_B.rtb_WayPoint_m[imo];
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev + 1] *
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev + 2] *
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
                }
              }

              // MATLAB Function: '<S153>/biasNED' incorporates:
              //   Product: '<S153>/RotateIndivWayPoint'
              //   Reshape: '<S153>/ReshapeRowVec'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                SequenceID_prev = b_nrows * 10240;
                for (imo = 0; imo < 10240; imo++) {
                  codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                    rtb_ReshapeRowVec[b_nrows];
                }
              }

              for (imo = 0; imo < 10240; imo++) {
                codegenReal2Mission_B.nedWayPoint[imo] =
                  codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                  codegenReal2Mission_B.WayPoint[imo];
                codegenReal2Mission_B.nedWayPoint[imo + 10240] =
                  codegenReal2Mission_B.WayPoint[imo + 10240] +
                  codegenReal2Mission_B.RotateIndivWayPoint[imo];
                codegenReal2Mission_B.nedWayPoint[imo + 20480] =
                  codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                  codegenReal2Mission_B.WayPoint[imo + 20480];
              }
            }

            // End of Outputs for SubSystem: '<S22>/WayPointGenerator'

            // BusCreator: '<S22>/GuidanceCMDBusCreator' incorporates:
            //   Constant: '<S22>/LookAheadDis'
            //   MATLAB Function: '<S153>/WayPointGenerator'
            //   MATLABSystem: '<S22>/Waypoint Follower'
            //   Memory: '<S22>/MemoryTriggerWP'
            //   Memory: '<S2>/DelayPose'

            codegenReal2Mission_WaypointFollowerBase_stepInternal
              (&codegenReal2Mission_DW.obj,
               codegenReal2Mission_DW.DelayPose_PreviousInput,
               codegenReal2Mission_B.nedWayPoint, 200.0, rtb_ReshapeRowVec,
               &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
               &lookaheadFlag, &rtb_Switch, &status_0);

            // Merge: '<S14>/ Merge ' incorporates:
            //   DataTypeConversion: '<S22>/Cast To Double'
            //   MATLABSystem: '<S22>/Waypoint Follower'

            codegenReal2Mission_B.thisTaskStatus = status_0;

            // BusCreator: '<S22>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S22>/Param4'
            //   Gain: '<S22>/Down2Height'
            //   MATLABSystem: '<S22>/Waypoint Follower'

            codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
            codegenReal2Mission_B.GuidanceCmds.AirSpeed =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

            // Switch: '<S189>/Switch' incorporates:
            //   Bias: '<S189>/Bias'
            //   Bias: '<S189>/Bias1'
            //   Constant: '<S189>/Constant2'
            //   Constant: '<S190>/Constant'
            //   DataStoreRead: '<S22>/PrevLatitudeGCS'
            //   Math: '<S189>/Math Function1'
            //   RelationalOperator: '<S190>/Compare'

            if (rtb_Switch_fe > 180.0) {
              rtb_Switch_fe = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch_fe = LatitudeGCS;
            }

            // Abs: '<S186>/Abs1'
            rtb_Abs1 = std::abs(rtb_Switch_fe);

            // Switch: '<S186>/Switch' incorporates:
            //   Bias: '<S186>/Bias'
            //   Bias: '<S186>/Bias1'
            //   Constant: '<S177>/Constant'
            //   Constant: '<S177>/Constant1'
            //   Constant: '<S188>/Constant'
            //   Gain: '<S186>/Gain'
            //   Product: '<S186>/Divide1'
            //   RelationalOperator: '<S188>/Compare'
            //   Switch: '<S177>/Switch1'

            if (rtb_Abs1 > 90.0) {
              // Signum: '<S186>/Sign1'
              if (rtb_Switch_fe < 0.0) {
                rtb_Switch_fe = -1.0;
              } else if (rtb_Switch_fe > 0.0) {
                rtb_Switch_fe = 1.0;
              } else if (rtb_Switch_fe == 0.0) {
                rtb_Switch_fe = 0.0;
              } else {
                rtb_Switch_fe = (rtNaN);
              }

              rtb_Switch_fe *= -(rtb_Abs1 + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Sum: '<S177>/Sum' incorporates:
            //   DataStoreRead: '<S22>/PrevLongitudeGCS'

            rtb_Sum_j = static_cast<real_T>(imo) + LongitudeGCS;

            // Sum: '<S152>/Sum1'
            rtb_Abs1 = fracSecs - rtb_Switch_fe;

            // Switch: '<S183>/Switch' incorporates:
            //   Abs: '<S183>/Abs'
            //   Bias: '<S183>/Bias'
            //   Bias: '<S183>/Bias1'
            //   Constant: '<S183>/Constant2'
            //   Constant: '<S184>/Constant'
            //   Math: '<S183>/Math Function1'
            //   RelationalOperator: '<S184>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S180>/Abs1'
            fracSecs = std::abs(rtb_Abs1);

            // Switch: '<S180>/Switch' incorporates:
            //   Bias: '<S180>/Bias'
            //   Bias: '<S180>/Bias1'
            //   Constant: '<S176>/Constant'
            //   Constant: '<S176>/Constant1'
            //   Constant: '<S182>/Constant'
            //   Gain: '<S180>/Gain'
            //   Product: '<S180>/Divide1'
            //   RelationalOperator: '<S182>/Compare'
            //   Switch: '<S176>/Switch1'

            if (fracSecs > 90.0) {
              // Signum: '<S180>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              rtb_Switch = (-(fracSecs + -90.0) + 90.0) * rtb_Abs1;
              imo = 180;
            } else {
              rtb_Switch = rtb_Abs1;
              imo = 0;
            }

            // Switch: '<S187>/Switch' incorporates:
            //   Abs: '<S187>/Abs'
            //   Bias: '<S187>/Bias'
            //   Bias: '<S187>/Bias1'
            //   Constant: '<S187>/Constant2'
            //   Constant: '<S191>/Constant'
            //   Math: '<S187>/Math Function1'
            //   RelationalOperator: '<S191>/Compare'

            if (std::abs(rtb_Sum_j) > 180.0) {
              rtb_Sum_j = rt_modd_snf(rtb_Sum_j + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S176>/Sum' incorporates:
            //   Sum: '<S152>/Sum1'

            rtb_Abs1 = (second - rtb_Sum_j) + static_cast<real_T>(imo);

            // UnitConversion: '<S194>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_fe *= 0.017453292519943295;

            // Trigonometry: '<S195>/Trigonometric Function1'
            second = std::sin(rtb_Switch_fe);

            // Sum: '<S195>/Sum1' incorporates:
            //   Constant: '<S195>/Constant'
            //   Product: '<S195>/Product1'

            second = 1.0 - codegenReal2Mission_ConstB.sqrt_c *
              codegenReal2Mission_ConstB.sqrt_c * second * second;

            // Product: '<S193>/Product1' incorporates:
            //   Constant: '<S193>/Constant1'
            //   Sqrt: '<S193>/sqrt'

            fracSecs = 6.378137E+6 / std::sqrt(second);

            // Product: '<S193>/Product4' incorporates:
            //   Trigonometry: '<S193>/Trigonometric Function'

            rtb_Switch_fe = fracSecs * std::cos(rtb_Switch_fe);

            // Product: '<S178>/dNorth' incorporates:
            //   Constant: '<S193>/Constant2'
            //   Product: '<S193>/Product3'
            //   Trigonometry: '<S193>/Trigonometric Function1'
            //   UnitConversion: '<S179>/Unit Conversion'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            fracSecs = 0.017453292519943295 * rtb_Switch / rt_atan2d_snf(1.0,
              fracSecs * codegenReal2Mission_ConstB.Sum1_c / second);

            // Switch: '<S181>/Switch' incorporates:
            //   Abs: '<S181>/Abs'
            //   Bias: '<S181>/Bias'
            //   Bias: '<S181>/Bias1'
            //   Constant: '<S181>/Constant2'
            //   Constant: '<S185>/Constant'
            //   Math: '<S181>/Math Function1'
            //   RelationalOperator: '<S185>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Product: '<S178>/dEast' incorporates:
            //   Constant: '<S193>/Constant3'
            //   Trigonometry: '<S193>/Trigonometric Function2'
            //   UnitConversion: '<S179>/Unit Conversion'

            second = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe) *
              (0.017453292519943295 * rtb_Abs1);

            // Sum: '<S178>/Sum2' incorporates:
            //   Product: '<S178>/x*cos'
            //   Product: '<S178>/y*sin'

            rtb_Switch = second * 0.0 + fracSecs;

            // Sum: '<S178>/Sum3' incorporates:
            //   Product: '<S178>/x*sin'
            //   Product: '<S178>/y*cos'

            fracSecs = second - fracSecs * 0.0;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Bias: '<S22>/Rotate90deg'
            //   Constant: '<S22>/InitialFlightPathAngle'
            //   Constant: '<S22>/InitialRollAngle'
            //   Constant: '<S22>/InitialRollAngleRate'
            //   DataTypeConversion: '<S22>/Param4'
            //   Gain: '<S22>/Down2Up'
            //   Product: '<S22>/ProductEast'
            //   Product: '<S22>/ProductNorth'
            //   Reshape: '<S22>/Reshape'
            //   Sum: '<S22>/SumInitEast'
            //   Sum: '<S22>/SumInitNorth'
            //   Trigonometry: '<S22>/Cos'
            //   Trigonometry: '<S22>/Sin'

            codegenReal2Mission_B.InitialState[0] = std::cos(rtb_Gain1 +
              1.5707963267948966) * rtb_Down2Up_e + rtb_Switch;
            codegenReal2Mission_B.InitialState[1] = std::sin(rtb_Gain1 +
              1.5707963267948966) * rtb_Down2Up_e + fracSecs;
            codegenReal2Mission_B.InitialState[2] = -rtb_Down_b;
            codegenReal2Mission_B.InitialState[3] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
            codegenReal2Mission_B.InitialState[4] = rtb_Gain1;
            codegenReal2Mission_B.InitialState[5] = 0.0;
            codegenReal2Mission_B.InitialState[6] = 0.0;
            codegenReal2Mission_B.InitialState[7] = 0.0;

            // Update for Memory: '<S22>/MemoryPrevRelPos' incorporates:
            //   Sum: '<S22>/RelPrevPos'

            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[0] =
              rtb_Switch - temp;
            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[1] = fracSecs
              - check;
            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[2] =
              rtb_Down_b - b_shi;

            // Update for Memory: '<S22>/MemoryTriggerWP' incorporates:
            //   Constant: '<S22>/TirggerWayPointGen'

            codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput = 1.0;
          } else {
            codegenReal2Mission_DW.is_WaypointFollower =
              codegenReal2Mission_IN_CustomFormationNav;

            // Abs: '<S116>/Abs' incorporates:
            //   Abs: '<S138>/Abs'
            //   DataStoreRead: '<S21>/LatitudeGCS'

            rtb_Switch_fe = std::abs(LatitudeGCS);

            // Switch: '<S116>/Switch' incorporates:
            //   Abs: '<S116>/Abs'
            //   Bias: '<S116>/Bias'
            //   Bias: '<S116>/Bias1'
            //   Constant: '<S116>/Constant2'
            //   Constant: '<S117>/Constant'
            //   DataStoreRead: '<S21>/LatitudeGCS'
            //   Math: '<S116>/Math Function1'
            //   RelationalOperator: '<S117>/Compare'

            if (rtb_Switch_fe > 180.0) {
              rtb_Down_b = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Down_b = LatitudeGCS;
            }

            // Abs: '<S113>/Abs1'
            rtb_Abs1 = std::abs(rtb_Down_b);

            // Switch: '<S113>/Switch' incorporates:
            //   Bias: '<S113>/Bias'
            //   Bias: '<S113>/Bias1'
            //   Constant: '<S104>/Constant'
            //   Constant: '<S104>/Constant1'
            //   Constant: '<S115>/Constant'
            //   Gain: '<S113>/Gain'
            //   Product: '<S113>/Divide1'
            //   RelationalOperator: '<S115>/Compare'
            //   Switch: '<S104>/Switch1'

            if (rtb_Abs1 > 90.0) {
              // Signum: '<S113>/Sign1'
              if (rtb_Down_b < 0.0) {
                rtb_Down_b = -1.0;
              } else if (rtb_Down_b > 0.0) {
                rtb_Down_b = 1.0;
              } else if (rtb_Down_b == 0.0) {
                rtb_Down_b = 0.0;
              } else {
                rtb_Down_b = (rtNaN);
              }

              rtb_Down_b *= -(rtb_Abs1 + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Sum: '<S104>/Sum' incorporates:
            //   DataStoreRead: '<S21>/LongitudeGCS'

            check = static_cast<real_T>(imo) + LongitudeGCS;

            // Sum: '<S100>/Sum1'
            rtb_Abs1 =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
              rtb_Down_b;

            // Switch: '<S110>/Switch' incorporates:
            //   Abs: '<S110>/Abs'
            //   Bias: '<S110>/Bias'
            //   Bias: '<S110>/Bias1'
            //   Constant: '<S110>/Constant2'
            //   Constant: '<S111>/Constant'
            //   Math: '<S110>/Math Function1'
            //   RelationalOperator: '<S111>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S107>/Abs1'
            b_shi = std::abs(rtb_Abs1);

            // Switch: '<S107>/Switch' incorporates:
            //   Bias: '<S107>/Bias'
            //   Bias: '<S107>/Bias1'
            //   Constant: '<S103>/Constant'
            //   Constant: '<S103>/Constant1'
            //   Constant: '<S109>/Constant'
            //   Gain: '<S107>/Gain'
            //   Product: '<S107>/Divide1'
            //   RelationalOperator: '<S109>/Compare'
            //   Switch: '<S103>/Switch1'

            if (b_shi > 90.0) {
              // Signum: '<S107>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              b_shi = (-(b_shi + -90.0) + 90.0) * rtb_Abs1;
              imo = 180;
            } else {
              b_shi = rtb_Abs1;
              imo = 0;
            }

            // Switch: '<S114>/Switch' incorporates:
            //   Abs: '<S114>/Abs'
            //   Bias: '<S114>/Bias'
            //   Bias: '<S114>/Bias1'
            //   Constant: '<S114>/Constant2'
            //   Constant: '<S118>/Constant'
            //   Math: '<S114>/Math Function1'
            //   RelationalOperator: '<S118>/Compare'

            if (std::abs(check) > 180.0) {
              check = rt_modd_snf(check + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S103>/Sum' incorporates:
            //   Sum: '<S100>/Sum1'

            rtb_Down2Up_e =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon -
               check) + static_cast<real_T>(imo);

            // UnitConversion: '<S106>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 0.017453292519943295 * b_shi;

            // UnitConversion: '<S121>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Down_b *= 0.017453292519943295;

            // Trigonometry: '<S122>/Trigonometric Function1'
            check = std::sin(rtb_Down_b);

            // Sum: '<S122>/Sum1' incorporates:
            //   Constant: '<S122>/Constant'
            //   Product: '<S122>/Product1'

            check = 1.0 - codegenReal2Mission_ConstB.sqrt_cy *
              codegenReal2Mission_ConstB.sqrt_cy * check * check;

            // Product: '<S120>/Product1' incorporates:
            //   Constant: '<S120>/Constant1'
            //   Sqrt: '<S120>/sqrt'

            b_shi = 6.378137E+6 / std::sqrt(check);

            // Product: '<S105>/dNorth' incorporates:
            //   Constant: '<S120>/Constant2'
            //   Product: '<S120>/Product3'
            //   Trigonometry: '<S120>/Trigonometric Function1'

            check = rtb_Abs1 / rt_atan2d_snf(1.0, b_shi *
              codegenReal2Mission_ConstB.Sum1_e / check);

            // Switch: '<S108>/Switch' incorporates:
            //   Abs: '<S108>/Abs'
            //   Bias: '<S108>/Bias'
            //   Bias: '<S108>/Bias1'
            //   Constant: '<S108>/Constant2'
            //   Constant: '<S112>/Constant'
            //   Math: '<S108>/Math Function1'
            //   RelationalOperator: '<S112>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Down2Up_e) > 180.0) {
              rtb_Down2Up_e = rt_modd_snf(rtb_Down2Up_e + 180.0, 360.0) + -180.0;
            }

            // Product: '<S105>/dEast' incorporates:
            //   Constant: '<S120>/Constant3'
            //   Product: '<S120>/Product4'
            //   Trigonometry: '<S120>/Trigonometric Function'
            //   Trigonometry: '<S120>/Trigonometric Function2'
            //   UnitConversion: '<S106>/Unit Conversion'

            b_shi = 1.0 / rt_atan2d_snf(1.0, b_shi * std::cos(rtb_Down_b)) *
              (0.017453292519943295 * rtb_Down2Up_e);

            // Sum: '<S105>/Sum2' incorporates:
            //   Product: '<S105>/x*cos'
            //   Product: '<S105>/y*sin'

            rtb_Down_b = b_shi * 0.0 + check;

            // Sum: '<S105>/Sum3' incorporates:
            //   Product: '<S105>/x*sin'
            //   Product: '<S105>/y*cos'

            b_shi -= check * 0.0;

            // Sum: '<S21>/Sum' incorporates:
            //   DataStoreRead: '<S21>/AltitudeGCS'
            //   Gain: '<S21>/Up2Down'
            //   Gain: '<S21>/inverse'
            //   Sum: '<S100>/Sum'
            //   UnaryMinus: '<S100>/Ze2height'

            check =
              -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
                -AltitudeGCS) +
              -codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;

            // Gain: '<S99>/Gain1'
            rtb_Down2Up_e = 0.017453292519943295 *
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

            // Outputs for Triggered SubSystem: '<S21>/WayPointGenerator' incorporates:
            //   TriggerPort: '<S102>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE_b,
                               (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_k));
            if (zcEvent != NO_ZCEVENT) {
              // Reshape: '<S102>/ReshapeRowVec'
              rtb_ReshapeRowVec[0] = rtb_Down_b;
              rtb_ReshapeRowVec[1] = b_shi;
              rtb_ReshapeRowVec[2] = check;

              // MATLABSystem: '<S102>/RotateATMissionHdg' incorporates:
              //   SignalConversion generated from: '<S102>/RotateATMissionHdg'

              ct[0] = std::cos(rtb_Down2Up_e);
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = std::sin
                (rtb_Down2Up_e);
              out[0] = ct[0];
              out[3] = 0.0 * ct[0] -
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
              out[6] = 0.0 * ct[0] +
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] * 0.0;
              out[1] = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
              out[4] = 0.0 * rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                [0] + ct[0];
              out[7] = 0.0 * rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                [0] - ct[0] * 0.0;
              out[2] = -0.0;
              out[5] = 0.0;
              out[8] = 1.0;

              // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S21>/Param2'
              //   DataTypeConversion: '<S21>/Param3'
              //   Product: '<S102>/ProductScanWidth'

              rtb_Abs1 = std::ceil
                (codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                 (codegenReal2Mission_B.MemoryCurrentMission.params.Param3 *
                  static_cast<real_T>
                  (codegenReal2Mission_B.MemoryCurrentMission.numUAV)));
              rtb_Switch =
                codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                rtb_Abs1;
              connectionObj.FlightPathAngleLimit[0] = -0.175;
              connectionObj.FlightPathAngleLimit[1] = 0.175;
              connectionObj.MaxRollAngle = 0.29670597283903605;
              connectionObj.AirSpeed = 35.0;
              connectionObj.MinTurningRadius = 408.85657731051754;
              imo = static_cast<int32_T>(rtb_Abs1 * 2.0);
              SequenceID_prev = CheckPoints->size[0] * CheckPoints->size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              CheckPoints->size[0] = imo;
              CheckPoints->size[1] = 4;
              codegenReal2Mission_emxEnsureCapacity_real_T(CheckPoints,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S21>/Param1'

              b_nrows = (imo << 2) - 1;
              for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                   SequenceID_prev++) {
                CheckPoints->data[SequenceID_prev] = 0.0;
              }

              for (b_nrows = 0; b_nrows < static_cast<int32_T>(rtb_Abs1);
                   b_nrows++) {
                if (rt_remd_snf(static_cast<real_T>(b_nrows) + 1.0, 2.0) == 1.0)
                {
                  imo = (b_nrows + 1) << 1;
                  rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                    rtb_Switch;
                  CheckPoints->data[imo - 2] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 2] = 0.0;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                    1.5707963267948966;
                  CheckPoints->data[imo - 1] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 1] =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                    1.5707963267948966;
                } else {
                  imo = (b_nrows + 1) << 1;
                  rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                    rtb_Switch;
                  CheckPoints->data[imo - 2] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 2] =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                    -1.5707963267948966;
                  CheckPoints->data[imo - 1] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 1] = 0.0;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                    -1.5707963267948966;
                }
              }

              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint->size[0] = 1;
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint->data[0] = 0.0;
              dummyWayPoint->data[1] = 0.0;
              dummyWayPoint->data[2] = 0.0;
              for (nrowx = 0; nrowx <= CheckPoints->size[0] - 2; nrowx++) {
                LUp[0] = CheckPoints->data[nrowx];
                LDp[0] = CheckPoints->data[nrowx + 1];
                LUp[1] = CheckPoints->data[nrowx + CheckPoints->size[0]];
                LDp[1] = CheckPoints->data[(nrowx + CheckPoints->size[0]) + 1];
                LUp[2] = CheckPoints->data[nrowx + (CheckPoints->size[0] << 1)];
                LDp[2] = CheckPoints->data[(nrowx + (CheckPoints->size[0] << 1))
                  + 1];
                LUp[3] = CheckPoints->data[nrowx + CheckPoints->size[0] * 3];
                LDp[3] = CheckPoints->data[(nrowx + CheckPoints->size[0] * 3) +
                  1];
                codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                  segWayPoints);
                SequenceID_prev = dummyWayPoint_0->size[0] *
                  dummyWayPoint_0->size[1];
                dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                  segWayPoints->size[0];
                dummyWayPoint_0->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                  SequenceID_prev);
                b_nrows = dummyWayPoint->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[SequenceID_prev +
                      dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                      data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                  }
                }

                b_nrows = segWayPoints->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->
                      size[0]) + dummyWayPoint_0->size[0] * imo] =
                      segWayPoints->data[SequenceID_prev + segWayPoints->size[0]
                      * imo];
                  }
                }

                SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                  SequenceID_prev);
                b_nrows = dummyWayPoint_0->size[0] * 3;
                for (imo = 0; imo < b_nrows; imo++) {
                  dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                }
              }

              LUp[0] = CheckPoints->data[CheckPoints->size[0] - 1];
              LDp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[(CheckPoints->size[0] +
                CheckPoints->size[0]) - 1];
              LDp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[(CheckPoints->size[0] +
                (CheckPoints->size[0] << 1)) - 1];
              LDp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
              LUp[3] = CheckPoints->data[(CheckPoints->size[0] +
                CheckPoints->size[0] * 3) - 1];
              LDp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
              codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                segWayPoints);
              SequenceID_prev = dummyWayPoint_0->size[0] * dummyWayPoint_0->
                size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                segWayPoints->size[0];
              dummyWayPoint_0->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              b_nrows = dummyWayPoint->size[0];
              nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  dummyWayPoint_0->data[SequenceID_prev + dummyWayPoint_0->size
                    [0] * imo] = dummyWayPoint->data[SequenceID_prev +
                    dummyWayPoint->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < nrows;
                     SequenceID_prev++) {
                  dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->size[0])
                    + dummyWayPoint_0->size[0] * imo] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }

              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              b_nrows = dummyWayPoint_0->size[0] * 3;
              for (imo = 0; imo < b_nrows; imo++) {
                dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
              }

              SequenceID_prev = dummyWayPoint_3->size[0] * dummyWayPoint_3->
                size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint_3->size[0] = dummyWayPoint->size[0];
              dummyWayPoint_3->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_3,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              b_nrows = dummyWayPoint->size[0] * dummyWayPoint->size[1] - 1;
              for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                   SequenceID_prev++) {
                dummyWayPoint_3->data[SequenceID_prev] = dummyWayPoint->
                  data[SequenceID_prev];
              }

              codegenReal2Mission_repmat(dummyWayPoint_3, std::ceil(10240.0 /
                static_cast<real_T>(dummyWayPoint->size[0])), dummyWayPoint);
              nrowx = dummyWayPoint->size[0] - 2;
              nrows = dummyWayPoint->size[0] - 1;

              // Reshape: '<S21>/Reshape2Row' incorporates:
              //   Memory: '<S21>/MemoryPrevRelPos'

              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[1];
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[0];
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[2];

              // Product: '<S102>/RotateRelPrevPos' incorporates:
              //   MATLABSystem: '<S102>/RotateATMissionHdg'

              rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1, out, ct);

              // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
              //   Product: '<S102>/RotateRelPrevPos'

              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo] = dummyWayPoint->data[imo + 1];
              }

              LDp[0] = ct[0];
              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo + dummyWayPoint->size[0]] =
                  dummyWayPoint->data[(imo + dummyWayPoint->size[0]) + 1];
              }

              LDp[1] = ct[1];
              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo + (dummyWayPoint->size[0] << 1)] =
                  dummyWayPoint->data[(imo + (dummyWayPoint->size[0] << 1)) + 1];
              }

              LDp[2] = ct[2];
              LDp[3] = 1.5707963267948966;
              LUp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
              LUp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
              codegenReal2Mission_genSegWP_i(&connectionObj, LDp, LUp, 100.0,
                segWayPoints);
              if (1 > nrows) {
                nrowx = -1;
              }

              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              initWayPoint->size[0] = (segWayPoints->size[0] + nrowx) + 1;
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              b_nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[SequenceID_prev + initWayPoint->size[0] *
                    imo] = segWayPoints->data[SequenceID_prev +
                    segWayPoints->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev <= nrowx;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + segWayPoints->size[0]) +
                    initWayPoint->size[0] * imo] = dummyWayPoint->
                    data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < 10240;
                     SequenceID_prev++) {
                  codegenReal2Mission_B.WayPoint[SequenceID_prev + 10240 * imo] =
                    initWayPoint->data[SequenceID_prev + initWayPoint->size[0] *
                    imo];
                }
              }

              for (imo = 0; imo < 10240; imo++) {
                // MATLAB Function: '<S102>/biasWayPoint'
                codegenReal2Mission_B.rtb_WayPoint_m[imo] =
                  codegenReal2Mission_B.WayPoint[imo] +
                  codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon;
                codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240] =
                  codegenReal2Mission_B.WayPoint[imo + 10240];
                codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480] =
                  codegenReal2Mission_B.WayPoint[imo + 20480];

                // Product: '<S102>/RotateIndivWayPoint' incorporates:
                //   MATLABSystem: '<S102>/RotateATMissionHdg'

                for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev++)
                {
                  b_nrows = imo + 10240 * SequenceID_prev;
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev] * codegenReal2Mission_B.rtb_WayPoint_m[imo];
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev + 1] *
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev + 2] *
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
                }
              }

              // MATLAB Function: '<S102>/biasNED' incorporates:
              //   Product: '<S102>/RotateIndivWayPoint'
              //   Reshape: '<S102>/ReshapeRowVec'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                SequenceID_prev = b_nrows * 10240;
                for (imo = 0; imo < 10240; imo++) {
                  codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                    rtb_ReshapeRowVec[b_nrows];
                }
              }

              for (imo = 0; imo < 10240; imo++) {
                codegenReal2Mission_B.nedWayPoint_a[imo] =
                  codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                  codegenReal2Mission_B.WayPoint[imo];
                codegenReal2Mission_B.nedWayPoint_a[imo + 10240] =
                  codegenReal2Mission_B.WayPoint[imo + 10240] +
                  codegenReal2Mission_B.RotateIndivWayPoint[imo];
                codegenReal2Mission_B.nedWayPoint_a[imo + 20480] =
                  codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                  codegenReal2Mission_B.WayPoint[imo + 20480];
              }
            }

            // End of Outputs for SubSystem: '<S21>/WayPointGenerator'

            // BusCreator: '<S21>/GuidanceCMDBusCreator' incorporates:
            //   Constant: '<S21>/LookAheadDis'
            //   MATLAB Function: '<S102>/WayPointGenerator'
            //   MATLABSystem: '<S21>/Waypoint Follower'
            //   Memory: '<S21>/MemoryTriggerWP'
            //   Memory: '<S2>/DelayPose'

            codegenReal2Mission_WaypointFollowerBase_stepInternal
              (&codegenReal2Mission_DW.obj_i,
               codegenReal2Mission_DW.DelayPose_PreviousInput,
               codegenReal2Mission_B.nedWayPoint_a, 200.0, rtb_ReshapeRowVec,
               &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
               &lookaheadFlag, &rtb_Switch, &status_0);

            // Merge: '<S14>/ Merge ' incorporates:
            //   DataTypeConversion: '<S21>/Cast To Double'
            //   MATLABSystem: '<S21>/Waypoint Follower'

            codegenReal2Mission_B.thisTaskStatus = status_0;

            // BusCreator: '<S21>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S21>/Param4'
            //   Gain: '<S21>/Down2Height'
            //   MATLABSystem: '<S21>/Waypoint Follower'

            codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
            codegenReal2Mission_B.GuidanceCmds.AirSpeed =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

            // Switch: '<S138>/Switch' incorporates:
            //   Bias: '<S138>/Bias'
            //   Bias: '<S138>/Bias1'
            //   Constant: '<S138>/Constant2'
            //   Constant: '<S139>/Constant'
            //   DataStoreRead: '<S21>/PrevLatitudeGCS'
            //   Math: '<S138>/Math Function1'
            //   RelationalOperator: '<S139>/Compare'

            if (rtb_Switch_fe > 180.0) {
              rtb_Switch_fe = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch_fe = LatitudeGCS;
            }

            // Abs: '<S135>/Abs1'
            rtb_Abs1 = std::abs(rtb_Switch_fe);

            // Switch: '<S135>/Switch' incorporates:
            //   Bias: '<S135>/Bias'
            //   Bias: '<S135>/Bias1'
            //   Constant: '<S126>/Constant'
            //   Constant: '<S126>/Constant1'
            //   Constant: '<S137>/Constant'
            //   Gain: '<S135>/Gain'
            //   Product: '<S135>/Divide1'
            //   RelationalOperator: '<S137>/Compare'
            //   Switch: '<S126>/Switch1'

            if (rtb_Abs1 > 90.0) {
              // Signum: '<S135>/Sign1'
              if (rtb_Switch_fe < 0.0) {
                rtb_Switch_fe = -1.0;
              } else if (rtb_Switch_fe > 0.0) {
                rtb_Switch_fe = 1.0;
              } else if (rtb_Switch_fe == 0.0) {
                rtb_Switch_fe = 0.0;
              } else {
                rtb_Switch_fe = (rtNaN);
              }

              rtb_Switch_fe *= -(rtb_Abs1 + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Sum: '<S126>/Sum' incorporates:
            //   DataStoreRead: '<S21>/PrevLongitudeGCS'

            rtb_Gain1 = static_cast<real_T>(imo) + LongitudeGCS;

            // Sum: '<S101>/Sum1'
            rtb_Abs1 = fracSecs - rtb_Switch_fe;

            // Switch: '<S132>/Switch' incorporates:
            //   Abs: '<S132>/Abs'
            //   Bias: '<S132>/Bias'
            //   Bias: '<S132>/Bias1'
            //   Constant: '<S132>/Constant2'
            //   Constant: '<S133>/Constant'
            //   Math: '<S132>/Math Function1'
            //   RelationalOperator: '<S133>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S129>/Abs1'
            fracSecs = std::abs(rtb_Abs1);

            // Switch: '<S129>/Switch' incorporates:
            //   Bias: '<S129>/Bias'
            //   Bias: '<S129>/Bias1'
            //   Constant: '<S125>/Constant'
            //   Constant: '<S125>/Constant1'
            //   Constant: '<S131>/Constant'
            //   Gain: '<S129>/Gain'
            //   Product: '<S129>/Divide1'
            //   RelationalOperator: '<S131>/Compare'
            //   Switch: '<S125>/Switch1'

            if (fracSecs > 90.0) {
              // Signum: '<S129>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              rtb_Abs1 *= -(fracSecs + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Switch: '<S136>/Switch' incorporates:
            //   Abs: '<S136>/Abs'
            //   Bias: '<S136>/Bias'
            //   Bias: '<S136>/Bias1'
            //   Constant: '<S136>/Constant2'
            //   Constant: '<S140>/Constant'
            //   Math: '<S136>/Math Function1'
            //   RelationalOperator: '<S140>/Compare'

            if (std::abs(rtb_Gain1) > 180.0) {
              rtb_Gain1 = rt_modd_snf(rtb_Gain1 + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S125>/Sum' incorporates:
            //   Sum: '<S101>/Sum1'

            rtb_Gain1 = (second - rtb_Gain1) + static_cast<real_T>(imo);

            // UnitConversion: '<S143>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_fe *= 0.017453292519943295;

            // Trigonometry: '<S144>/Trigonometric Function1'
            second = std::sin(rtb_Switch_fe);

            // Sum: '<S144>/Sum1' incorporates:
            //   Constant: '<S144>/Constant'
            //   Product: '<S144>/Product1'

            second = 1.0 - codegenReal2Mission_ConstB.sqrt_cp *
              codegenReal2Mission_ConstB.sqrt_cp * second * second;

            // Product: '<S142>/Product1' incorporates:
            //   Constant: '<S142>/Constant1'
            //   Sqrt: '<S142>/sqrt'

            fracSecs = 6.378137E+6 / std::sqrt(second);

            // Product: '<S142>/Product4' incorporates:
            //   Trigonometry: '<S142>/Trigonometric Function'

            rtb_Switch_fe = fracSecs * std::cos(rtb_Switch_fe);

            // Product: '<S127>/dNorth' incorporates:
            //   Constant: '<S142>/Constant2'
            //   Product: '<S142>/Product3'
            //   Trigonometry: '<S142>/Trigonometric Function1'
            //   UnitConversion: '<S128>/Unit Conversion'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            fracSecs = 0.017453292519943295 * rtb_Abs1 / rt_atan2d_snf(1.0,
              fracSecs * codegenReal2Mission_ConstB.Sum1_h / second);

            // Switch: '<S130>/Switch' incorporates:
            //   Abs: '<S130>/Abs'
            //   Bias: '<S130>/Bias'
            //   Bias: '<S130>/Bias1'
            //   Constant: '<S130>/Constant2'
            //   Constant: '<S134>/Constant'
            //   Math: '<S130>/Math Function1'
            //   RelationalOperator: '<S134>/Compare'

            if (std::abs(rtb_Gain1) > 180.0) {
              rtb_Gain1 = rt_modd_snf(rtb_Gain1 + 180.0, 360.0) + -180.0;
            }

            // Product: '<S127>/dEast' incorporates:
            //   Constant: '<S142>/Constant3'
            //   Trigonometry: '<S142>/Trigonometric Function2'
            //   UnitConversion: '<S128>/Unit Conversion'

            second = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe) *
              (0.017453292519943295 * rtb_Gain1);

            // Sum: '<S127>/Sum2' incorporates:
            //   Product: '<S127>/x*cos'
            //   Product: '<S127>/y*sin'

            rtb_Switch_fe = second * 0.0 + fracSecs;

            // Sum: '<S127>/Sum3' incorporates:
            //   Product: '<S127>/x*sin'
            //   Product: '<S127>/y*cos'

            fracSecs = second - fracSecs * 0.0;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Bias: '<S21>/Rotate90deg'
            //   Constant: '<S21>/InitialFlightPathAngle'
            //   Constant: '<S21>/InitialRollAngle'
            //   Constant: '<S21>/InitialRollAngleRate'
            //   DataStoreRead: '<S21>/PrevAltitudeGCS'
            //   DataTypeConversion: '<S21>/Param4'
            //   Gain: '<S21>/PrevInverse'
            //   Product: '<S21>/FrontEast'
            //   Product: '<S21>/FrontNorth'
            //   Product: '<S21>/RightEast'
            //   Product: '<S21>/RightNorth'
            //   Reshape: '<S21>/Reshape'
            //   Sum: '<S101>/Sum'
            //   Sum: '<S21>/SumHeight'
            //   Sum: '<S21>/SumInitEast'
            //   Sum: '<S21>/SumInitNorth'
            //   Trigonometry: '<S21>/FrontCos'
            //   Trigonometry: '<S21>/FrontSin'
            //   Trigonometry: '<S21>/RightCos'
            //   Trigonometry: '<S21>/RightSin'

            codegenReal2Mission_B.InitialState[0] = (std::cos(rtb_Down2Up_e +
              1.5707963267948966) *
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon +
              rtb_Switch_fe) + std::cos(rtb_Down2Up_e) *
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat;
            codegenReal2Mission_B.InitialState[1] = (std::sin(rtb_Down2Up_e) *
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat +
              fracSecs) + std::sin(rtb_Down2Up_e + 1.5707963267948966) *
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon;
            codegenReal2Mission_B.InitialState[2] = (temp + -AltitudeGCS) +
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;
            codegenReal2Mission_B.InitialState[3] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
            codegenReal2Mission_B.InitialState[4] = rtb_Down2Up_e;
            codegenReal2Mission_B.InitialState[5] = 0.0;
            codegenReal2Mission_B.InitialState[6] = 0.0;
            codegenReal2Mission_B.InitialState[7] = 0.0;

            // Update for Memory: '<S21>/MemoryPrevRelPos' incorporates:
            //   DataStoreRead: '<S21>/PrevAltitudeGCS'
            //   Gain: '<S21>/PrevInverse'
            //   Sum: '<S101>/Sum'
            //   Sum: '<S21>/RelPrevPos'
            //   UnaryMinus: '<S101>/Ze2height'

            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[0] =
              rtb_Switch_fe - rtb_Down_b;
            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[1] =
              fracSecs - b_shi;
            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[2] = -(temp
              + -AltitudeGCS) - check;

            // Update for Memory: '<S21>/MemoryTriggerWP' incorporates:
            //   Constant: '<S21>/TirggerWayPointGen'

            codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_k = 1.0;
          }
        } else if ((codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 3)
                   || (codegenReal2Mission_B.MemoryCurrentMission.MissionMode ==
                       33)) {
          codegenReal2Mission_exit_internal_GuidanceLogic();
          codegenReal2Mission_DW.is_GuidanceLogic =
            codegenReal2Mission_IN_RunWayNav;

          // Switch: '<S85>/Switch' incorporates:
          //   Abs: '<S85>/Abs'
          //   Bias: '<S85>/Bias'
          //   Bias: '<S85>/Bias1'
          //   Constant: '<S85>/Constant2'
          //   Constant: '<S86>/Constant'
          //   DataStoreRead: '<S20>/LatitudeGCS'
          //   Math: '<S85>/Math Function1'
          //   RelationalOperator: '<S86>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            fracSecs = LatitudeGCS;
          }

          // Abs: '<S82>/Abs1'
          rtb_Switch_fe = std::abs(fracSecs);

          // Switch: '<S82>/Switch' incorporates:
          //   Bias: '<S82>/Bias'
          //   Bias: '<S82>/Bias1'
          //   Constant: '<S73>/Constant'
          //   Constant: '<S73>/Constant1'
          //   Constant: '<S84>/Constant'
          //   Gain: '<S82>/Gain'
          //   Product: '<S82>/Divide1'
          //   RelationalOperator: '<S84>/Compare'
          //   Switch: '<S73>/Switch1'

          if (rtb_Switch_fe > 90.0) {
            // Signum: '<S82>/Sign1'
            if (fracSecs < 0.0) {
              fracSecs = -1.0;
            } else if (fracSecs > 0.0) {
              fracSecs = 1.0;
            } else if (fracSecs == 0.0) {
              fracSecs = 0.0;
            } else {
              fracSecs = (rtNaN);
            }

            fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
            imo = 180;
          } else {
            imo = 0;
          }

          // Sum: '<S73>/Sum' incorporates:
          //   DataStoreRead: '<S20>/LongitudeGCS'

          second = static_cast<real_T>(imo) + LongitudeGCS;

          // Sum: '<S70>/Sum1'
          rtb_Abs1 =
            codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
            fracSecs;

          // Switch: '<S79>/Switch' incorporates:
          //   Abs: '<S79>/Abs'
          //   Bias: '<S79>/Bias'
          //   Bias: '<S79>/Bias1'
          //   Constant: '<S79>/Constant2'
          //   Constant: '<S80>/Constant'
          //   Math: '<S79>/Math Function1'
          //   RelationalOperator: '<S80>/Compare'

          if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S76>/Abs1'
          rtb_Switch_fe = std::abs(rtb_Abs1);

          // Switch: '<S76>/Switch' incorporates:
          //   Bias: '<S76>/Bias'
          //   Bias: '<S76>/Bias1'
          //   Constant: '<S72>/Constant'
          //   Constant: '<S72>/Constant1'
          //   Constant: '<S78>/Constant'
          //   Gain: '<S76>/Gain'
          //   Product: '<S76>/Divide1'
          //   RelationalOperator: '<S78>/Compare'
          //   Switch: '<S72>/Switch1'

          if (rtb_Switch_fe > 90.0) {
            // Signum: '<S76>/Sign1'
            if (rtb_Abs1 < 0.0) {
              rtb_Abs1 = -1.0;
            } else if (rtb_Abs1 > 0.0) {
              rtb_Abs1 = 1.0;
            } else if (rtb_Abs1 == 0.0) {
              rtb_Abs1 = 0.0;
            } else {
              rtb_Abs1 = (rtNaN);
            }

            rtb_Switch_fe = (-(rtb_Switch_fe + -90.0) + 90.0) * rtb_Abs1;
            imo = 180;
          } else {
            rtb_Switch_fe = rtb_Abs1;
            imo = 0;
          }

          // Switch: '<S83>/Switch' incorporates:
          //   Abs: '<S83>/Abs'
          //   Bias: '<S83>/Bias'
          //   Bias: '<S83>/Bias1'
          //   Constant: '<S83>/Constant2'
          //   Constant: '<S87>/Constant'
          //   Math: '<S83>/Math Function1'
          //   RelationalOperator: '<S87>/Compare'

          if (std::abs(second) > 180.0) {
            second = rt_modd_snf(second + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S72>/Sum' incorporates:
          //   Sum: '<S70>/Sum1'

          temp = (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon
                  - second) + static_cast<real_T>(imo);

          // UnitConversion: '<S75>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Abs1 = 0.017453292519943295 * rtb_Switch_fe;

          // UnitConversion: '<S90>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          fracSecs *= 0.017453292519943295;

          // Trigonometry: '<S91>/Trigonometric Function1'
          second = std::sin(fracSecs);

          // Sum: '<S91>/Sum1' incorporates:
          //   Constant: '<S91>/Constant'
          //   Product: '<S91>/Product1'

          second = 1.0 - codegenReal2Mission_ConstB.sqrt_o *
            codegenReal2Mission_ConstB.sqrt_o * second * second;

          // Product: '<S89>/Product1' incorporates:
          //   Constant: '<S89>/Constant1'
          //   Sqrt: '<S89>/sqrt'

          rtb_Switch_fe = 6.378137E+6 / std::sqrt(second);

          // Product: '<S74>/dNorth' incorporates:
          //   Constant: '<S89>/Constant2'
          //   Product: '<S89>/Product3'
          //   Trigonometry: '<S89>/Trigonometric Function1'

          second = rtb_Abs1 / rt_atan2d_snf(1.0, rtb_Switch_fe *
            codegenReal2Mission_ConstB.Sum1_j / second);

          // Switch: '<S77>/Switch' incorporates:
          //   Abs: '<S77>/Abs'
          //   Bias: '<S77>/Bias'
          //   Bias: '<S77>/Bias1'
          //   Constant: '<S77>/Constant2'
          //   Constant: '<S81>/Constant'
          //   Math: '<S77>/Math Function1'
          //   RelationalOperator: '<S81>/Compare'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          if (std::abs(temp) > 180.0) {
            temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
          }

          // Product: '<S74>/dEast' incorporates:
          //   Constant: '<S89>/Constant3'
          //   Product: '<S89>/Product4'
          //   Trigonometry: '<S89>/Trigonometric Function'
          //   Trigonometry: '<S89>/Trigonometric Function2'
          //   UnitConversion: '<S75>/Unit Conversion'

          rtb_Switch_fe = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe * std::cos
            (fracSecs)) * (0.017453292519943295 * temp);

          // Gain: '<S69>/Gain1'
          fracSecs = 0.017453292519943295 *
            codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

          // Outputs for Triggered SubSystem: '<S20>/WayPointGenerator' incorporates:
          //   TriggerPort: '<S71>/Trigger'

          zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                             &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE_o,
                             (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n));
          if (zcEvent != NO_ZCEVENT) {
            // Product: '<S71>/IndivRunwayRotAng' incorporates:
            //   DataTypeConversion: '<S20>/Param2'
            //   DataTypeConversion: '<S20>/Param5'
            //   Gain: '<S94>/Gain1'

            temp = 0.017453292519943295 *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param2 *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param5;

            // MATLAB Function: '<S71>/WayPointGenerator' incorporates:
            //   DataTypeConversion: '<S20>/Param3'

            codegenReal2Mission_uavDubinsConnection_uavDubinsConnection
              (&connectionObj);
            LUp[0] = 0.0;
            rtb_Abs1 = codegenReal2Mission_B.MemoryCurrentMission.params.Param3 /
              2.0;
            LUp[1] = rtb_Abs1;
            LUp[2] = 0.0;
            LUp[3] = 1.5707963267948966;
            LDp[0] = 0.0;
            rtb_Down_b = -static_cast<real_T>
              (codegenReal2Mission_B.MemoryCurrentMission.params.Param3) / 2.0;
            LDp[1] = rtb_Down_b;
            LDp[2] = 0.0;
            LDp[3] = 1.5707963267948966;
            codegenReal2Mission_uavDubinsConnection_connect(&connectionObj, LUp,
              LDp, codegenReal2Mission_B.pathSegObj.data,
              &codegenReal2Mission_B.pathSegObj.size, a__1_data,
              &SequenceID_prev);
            codegenReal2Mission_uavDubinsPathSegment_interpolate
              (codegenReal2Mission_B.pathSegObj.data[0].StartPose,
               codegenReal2Mission_B.pathSegObj.data[0].GoalPose,
               codegenReal2Mission_B.pathSegObj.data[0].FlightPathAngle,
               codegenReal2Mission_B.pathSegObj.data[0].AirSpeed,
               codegenReal2Mission_B.pathSegObj.data[0].MinTurningRadius,
               codegenReal2Mission_B.pathSegObj.data[0].HelixRadius,
               codegenReal2Mission_B.pathSegObj.data[0].MotionTypes,
               codegenReal2Mission_B.pathSegObj.data[0].MotionLengths,
               codegenReal2Mission_B.pathSegObj.data[0].Length,
               codegenReal2Mission_B.pathSegObj.data[0].Length / 2.0,
               midpose_data, midpose_size);
            rtb_startPose[0] = 0.0;
            b_shi = (codegenReal2Mission_B.pathSegObj.data[0].Length +
                     codegenReal2Mission_B.MemoryCurrentMission.params.Param3) /
              3.0 - codegenReal2Mission_B.pathSegObj.data[0].Length / 2.0;
            rtb_startPose[1] = rtb_Abs1 - b_shi;
            rtb_startPose[2] = 0.0;
            rtb_startPose[3] = 1.5707963267948966;
            ende[0] = 0.0;
            ende[1] = b_shi + rtb_Down_b;
            ende[2] = 0.0;
            ende[3] = 1.5707963267948966;
            SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            initWayPoint->size[0] = 1;
            initWayPoint->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator' incorporates:
            //   Constant: '<S71>/Three'
            //   DataTypeConversion: '<S71>/Cast To Double'
            //   Math: '<S71>/ModRunWayPose'

            initWayPoint->data[0] = 0.0;
            initWayPoint->data[1] = 0.0;
            initWayPoint->data[2] = 0.0;
            switch (static_cast<int32_T>(rt_modd_snf(static_cast<real_T>
                      (codegenReal2Mission_B.MemoryCurrentMission.FormationPos),
                      3.0))) {
             case 0:
              codegenReal2Mission_genSegWP(&connectionObj, rtb_startPose, LUp,
                100.0, segWayPoints);
              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
              initWayPoint->size[0] = segWayPoints->size[0] + 1;
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);
              b_nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + initWayPoint->size[0] *
                                      imo) + 1] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }
              break;

             case 1:
              rtb_startPose[0] = midpose_data[0];
              rtb_startPose[1] = midpose_data[midpose_size[0]];
              rtb_startPose[2] = midpose_data[midpose_size[0] << 1];
              rtb_startPose[3] = midpose_data[midpose_size[0] * 3];
              codegenReal2Mission_genSegWP(&connectionObj, &midpose_data[0], LDp,
                100.0, segWayPoints);
              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
              initWayPoint->size[0] = segWayPoints->size[0] + 1;
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);
              b_nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + initWayPoint->size[0] *
                                      imo) + 1] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }
              break;

             case 2:
              rtb_startPose[0] = 0.0;
              rtb_startPose[1] = ende[1];
              rtb_startPose[2] = 0.0;
              rtb_startPose[3] = 1.5707963267948966;
              codegenReal2Mission_genSegWP(&connectionObj, ende, LUp, 100.0,
                segWayPoints);
              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
              initWayPoint->size[0] = segWayPoints->size[0] + 1;
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);
              b_nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + initWayPoint->size[0] *
                                      imo) + 1] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }
              break;

             default:
              rtb_startPose[0] = 0.0;
              rtb_startPose[1] = 0.0;
              rtb_startPose[2] = 0.0;
              rtb_startPose[3] = 0.0;
              break;
            }

            codegenReal2Mission_genSegWP(&connectionObj, LUp, LDp, 100.0,
              segWayPoints);
            SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            dummyWayPoint->size[0] = segWayPoints->size[0] + 1;
            dummyWayPoint->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            b_nrows = segWayPoints->size[0];
            for (imo = 0; imo < 3; imo++) {
              dummyWayPoint->data[dummyWayPoint->size[0] * imo] = 0.0;
              for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                   SequenceID_prev++) {
                dummyWayPoint->data[(SequenceID_prev + dummyWayPoint->size[0] *
                                     imo) + 1] = segWayPoints->
                  data[SequenceID_prev + segWayPoints->size[0] * imo];
              }
            }

            codegenReal2Mission_genSegWP(&connectionObj, LDp, LUp, 100.0,
              segWayPoints);
            SequenceID_prev = dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
              segWayPoints->size[0];
            dummyWayPoint_0->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            b_nrows = dummyWayPoint->size[0];
            nrows = segWayPoints->size[0];
            for (imo = 0; imo < 3; imo++) {
              for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                   SequenceID_prev++) {
                dummyWayPoint_0->data[SequenceID_prev + dummyWayPoint_0->size[0]
                  * imo] = dummyWayPoint->data[SequenceID_prev +
                  dummyWayPoint->size[0] * imo];
              }

              for (SequenceID_prev = 0; SequenceID_prev < nrows; SequenceID_prev
                   ++) {
                dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->size[0])
                  + dummyWayPoint_0->size[0] * imo] = segWayPoints->
                  data[SequenceID_prev + segWayPoints->size[0] * imo];
              }
            }

            SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
            dummyWayPoint->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            b_nrows = dummyWayPoint_0->size[0] * 3;
            for (imo = 0; imo < b_nrows; imo++) {
              dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
            }

            nrowx = dummyWayPoint->size[0] - 2;
            nrows = dummyWayPoint->size[0] - 1;
            for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
              dummyWayPoint->data[b_nrows] = dummyWayPoint->data[b_nrows + 1];
            }

            for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
              dummyWayPoint->data[b_nrows + dummyWayPoint->size[0]] =
                dummyWayPoint->data[(b_nrows + dummyWayPoint->size[0]) + 1];
            }

            for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
              dummyWayPoint->data[b_nrows + (dummyWayPoint->size[0] << 1)] =
                dummyWayPoint->data[(b_nrows + (dummyWayPoint->size[0] << 1)) +
                1];
            }

            if (1 > nrows) {
              nrowx = -1;
              imo = -1;
            } else {
              imo = nrowx;
            }

            b_nrows = imo + 1;
            SequenceID_prev = dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            dummyWayPoint_0->size[0] = nrowx + 1;
            dummyWayPoint_0->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            for (imo = 0; imo < 3; imo++) {
              for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                   SequenceID_prev++) {
                dummyWayPoint_0->data[SequenceID_prev + dummyWayPoint_0->size[0]
                  * imo] = dummyWayPoint->data[SequenceID_prev +
                  dummyWayPoint->size[0] * imo];
              }
            }

            codegenReal2Mission_repmat(dummyWayPoint_0, std::ceil(10240.0 /
              static_cast<real_T>(nrowx + 1)), dummyWayPoint);
            if (2 > initWayPoint->size[0]) {
              k = -1;
              b = -1;
            } else {
              k = 0;
              b = initWayPoint->size[0] - 1;
            }

            // Bias: '<S71>/Bias' incorporates:
            //   Sum: '<S71>/Sum'

            codegenReal2Mission_B.Bias = ((fracSecs + temp) + rtb_startPose[3])
              + -1.5707963267948966;

            // Gain: '<S71>/InterLayerDis' incorporates:
            //   Constant: '<S71>/Three'
            //   DataTypeConversion: '<S20>/Param5'
            //   Math: '<S71>/ModRunWayLayer'

            rtb_Abs1 = 15.0 * rt_modd_snf(static_cast<real_T>
              (codegenReal2Mission_B.MemoryCurrentMission.params.Param5), 3.0);

            // Reshape: '<S71>/Reshape' incorporates:
            //   Constant: '<S71>/Zero'
            //   DataTypeConversion: '<S20>/Param1'

            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = 0.0;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = rtb_Abs1;

            // Reshape: '<S71>/ReshapeRowVec' incorporates:
            //   DataStoreRead: '<S20>/AltitudeGCS'
            //   Gain: '<S20>/inverse'
            //   Product: '<S74>/x*cos'
            //   Product: '<S74>/x*sin'
            //   Product: '<S74>/y*cos'
            //   Product: '<S74>/y*sin'
            //   Reshape: '<S71>/ReshapeRowVecStartpose'
            //   Sum: '<S70>/Sum'
            //   Sum: '<S74>/Sum2'
            //   Sum: '<S74>/Sum3'
            //   UnaryMinus: '<S70>/Ze2height'

            rtb_ReshapeRowVec[0] = rtb_Switch_fe * 0.0 + second;
            rtb_ReshapeRowVec[1] = rtb_Switch_fe - second * 0.0;
            rtb_ReshapeRowVec[2] =
              -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
                -AltitudeGCS);

            // MATLABSystem: '<S71>/RotateATMissionHdg' incorporates:
            //   SignalConversion generated from: '<S71>/RotateATMissionHdg'

            ct[0] = std::cos(fracSecs);
            turnVector[0] = std::sin(fracSecs);
            out[0] = ct[0];
            out[3] = 0.0 * ct[0] - turnVector[0];
            out[6] = 0.0 * ct[0] + turnVector[0] * 0.0;
            out[1] = turnVector[0];
            out[4] = 0.0 * turnVector[0] + ct[0];
            out[7] = 0.0 * turnVector[0] - ct[0] * 0.0;
            out[2] = -0.0;
            out[5] = 0.0;
            out[8] = 1.0;

            // SignalConversion generated from: '<S71>/RotateATRunWayHdg' incorporates:
            //   Constant: '<S71>/Zero'

            turnVector[0] = temp;
            turnVector[1] = 0.0;
            turnVector[2] = 0.0;

            // MATLABSystem: '<S71>/RotateATRunWayHdg' incorporates:
            //   SignalConversion generated from: '<S71>/RotateATRunWayHdg'

            ct[0] = temp;
            ct[1] = 0.0;
            ct[2] = 0.0;

            // MATLAB Function: '<S71>/WayPointGenerator'
            b_nrows = b - k;
            SequenceID_prev = segWayPoints->size[0] * segWayPoints->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            segWayPoints->size[0] = b_nrows + dummyWayPoint->size[0];
            segWayPoints->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(segWayPoints,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            nrows = dummyWayPoint->size[0];
            for (nrowx = 0; nrowx < 3; nrowx++) {
              // MATLAB Function: '<S71>/minus' incorporates:
              //   Reshape: '<S71>/Reshape'

              SequenceID_prev = nrowx * 10240;
              for (imo = 0; imo < 10240; imo++) {
                codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[nrowx];
              }

              // MATLAB Function: '<S71>/WayPointGenerator'
              for (imo = 0; imo < b_nrows; imo++) {
                segWayPoints->data[imo + segWayPoints->size[0] * nrowx] =
                  initWayPoint->data[((k + imo) + initWayPoint->size[0] * nrowx)
                  + 1];
              }

              for (imo = 0; imo < nrows; imo++) {
                segWayPoints->data[((imo + b) - k) + segWayPoints->size[0] *
                  nrowx] = dummyWayPoint->data[imo + dummyWayPoint->size[0] *
                  nrowx];
              }

              // MATLAB Function: '<S71>/minus' incorporates:
              //   MATLAB Function: '<S71>/WayPointGenerator'

              for (imo = 0; imo < 10240; imo++) {
                initWayPoint_tmp = 10240 * nrowx + imo;
                codegenReal2Mission_B.rtb_WayPoint_m[initWayPoint_tmp] =
                  segWayPoints->data[imo + segWayPoints->size[0] * nrowx] -
                  codegenReal2Mission_B.WayPoint[initWayPoint_tmp];
              }

              ct[nrowx] = std::cos(ct[nrowx]);
              turnVector[nrowx] = std::sin(turnVector[nrowx]);
            }

            // MATLABSystem: '<S71>/RotateATRunWayHdg'
            out_0[0] = ct[0] * ct[1];
            rtb_Switch_fe = turnVector[1] * turnVector[2];
            out_0[3] = rtb_Switch_fe * ct[0] - turnVector[0] * ct[2];
            second = turnVector[1] * ct[2];
            out_0[6] = second * ct[0] + turnVector[0] * turnVector[2];
            out_0[1] = turnVector[0] * ct[1];
            out_0[4] = rtb_Switch_fe * turnVector[0] + ct[0] * ct[2];
            out_0[7] = second * turnVector[0] - ct[0] * turnVector[2];
            out_0[2] = -turnVector[1];
            out_0[5] = ct[1] * turnVector[2];
            out_0[8] = ct[1] * ct[2];
            for (imo = 0; imo < 10240; imo++) {
              // Product: '<S71>/RotateRunway' incorporates:
              //   MATLABSystem: '<S71>/RotateATRunWayHdg'

              for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev++)
              {
                initWayPoint_tmp = imo + 10240 * SequenceID_prev;
                codegenReal2Mission_B.WayPoint[initWayPoint_tmp] = 0.0;
                codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                  SequenceID_prev] * codegenReal2Mission_B.rtb_WayPoint_m[imo];
                codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                  SequenceID_prev + 1] *
                  codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                  SequenceID_prev + 2] *
                  codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
              }

              // Product: '<S71>/RotateIndivWayPoint' incorporates:
              //   MATLABSystem: '<S71>/RotateATMissionHdg'

              for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev++)
              {
                b_nrows = imo + 10240 * SequenceID_prev;
                codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                  SequenceID_prev] * codegenReal2Mission_B.WayPoint[imo];
                codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                  SequenceID_prev + 1] * codegenReal2Mission_B.WayPoint[imo +
                  10240];
                codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                  SequenceID_prev + 2] * codegenReal2Mission_B.WayPoint[imo +
                  20480];
              }
            }

            // Sum: '<S71>/BiasStartPose' incorporates:
            //   DataTypeConversion: '<S20>/Param1'

            rtb_Switch_fe = rtb_startPose[0];
            second = rtb_startPose[1] -
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
            rtb_Abs1 = rtb_startPose[2] - rtb_Abs1;

            // Product: '<S71>/RotateRunwayStartpose' incorporates:
            //   MATLABSystem: '<S71>/RotateATRunWayHdg'

            for (imo = 0; imo < 3; imo++) {
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[imo] = out_0[3 *
                imo + 2] * rtb_Abs1 + (out_0[3 * imo + 1] * second + out_0[3 *
                imo] * rtb_Switch_fe);
            }

            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              // MATLAB Function: '<S71>/biasNED' incorporates:
              //   Reshape: '<S71>/ReshapeRowVec'

              SequenceID_prev = b_nrows * 10240;
              for (imo = 0; imo < 10240; imo++) {
                codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                  rtb_ReshapeRowVec[b_nrows];
              }

              ct[b_nrows] = out[3 * b_nrows + 2] *
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] + (out[3 *
                b_nrows + 1] *
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] + out[3 *
                b_nrows] * rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
            }

            // MATLAB Function: '<S71>/biasNED' incorporates:
            //   MATLABSystem: '<S71>/RotateATMissionHdg'
            //   Product: '<S71>/RotateIndivWayPoint'
            //   Product: '<S71>/RotateIndivWayPointStartpose'

            for (imo = 0; imo < 10240; imo++) {
              codegenReal2Mission_B.nedWayPoint_m[imo] =
                codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                codegenReal2Mission_B.WayPoint[imo];
              codegenReal2Mission_B.nedWayPoint_m[imo + 10240] =
                codegenReal2Mission_B.WayPoint[imo + 10240] +
                codegenReal2Mission_B.RotateIndivWayPoint[imo];
              codegenReal2Mission_B.nedWayPoint_m[imo + 20480] =
                codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                codegenReal2Mission_B.WayPoint[imo + 20480];
            }

            // MATLAB Function: '<S71>/biasNEDstartpose' incorporates:
            //   Product: '<S71>/RotateIndivWayPointStartpose'
            //   Reshape: '<S71>/ReshapeRowVecStartpose'

            codegenReal2Mission_B.nedWayPoint_d[0] = rtb_ReshapeRowVec[0] + ct[1];
            codegenReal2Mission_B.nedWayPoint_d[1] = ct[0] + rtb_ReshapeRowVec[1];
            codegenReal2Mission_B.nedWayPoint_d[2] = ct[2] + rtb_ReshapeRowVec[2];
          }

          // End of Outputs for SubSystem: '<S20>/WayPointGenerator'

          // BusCreator: '<S20>/GuidanceCMDBusCreator' incorporates:
          //   Constant: '<S20>/LookAheadDis'
          //   MATLAB Function: '<S71>/WayPointGenerator'
          //   MATLABSystem: '<S20>/Waypoint Follower'
          //   Memory: '<S20>/MemoryTriggerWP'
          //   Memory: '<S2>/DelayPose'

          codegenReal2Mission_WaypointFollowerBase_stepInternal
            (&codegenReal2Mission_DW.obj_e,
             codegenReal2Mission_DW.DelayPose_PreviousInput,
             codegenReal2Mission_B.nedWayPoint_m, 200.0, rtb_ReshapeRowVec,
             &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
             &lookaheadFlag, &rtb_Switch, &status_0);

          // Merge: '<S14>/ Merge ' incorporates:
          //   DataTypeConversion: '<S20>/Cast To Double'
          //   MATLABSystem: '<S20>/Waypoint Follower'

          codegenReal2Mission_B.thisTaskStatus = status_0;

          // BusCreator: '<S20>/GuidanceCMDBusCreator' incorporates:
          //   DataTypeConversion: '<S20>/Param4'
          //   Gain: '<S20>/Down2Height'
          //   MATLABSystem: '<S20>/Waypoint Follower'

          codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
          codegenReal2Mission_B.GuidanceCmds.AirSpeed =
            codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

          // Merge: '<S14>/ Merge 3' incorporates:
          //   Constant: '<S20>/InitialFlightPathAngle'
          //   Constant: '<S20>/InitialRollAngle'
          //   Constant: '<S20>/InitialRollAngleRate'
          //   DataTypeConversion: '<S20>/Param4'
          //   Gain: '<S20>/Down2Up'
          //   Reshape: '<S20>/Reshape'

          codegenReal2Mission_B.InitialState[0] =
            codegenReal2Mission_B.nedWayPoint_d[0];
          codegenReal2Mission_B.InitialState[1] =
            codegenReal2Mission_B.nedWayPoint_d[1];
          codegenReal2Mission_B.InitialState[2] =
            -codegenReal2Mission_B.nedWayPoint_d[2];
          codegenReal2Mission_B.InitialState[3] =
            codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
          codegenReal2Mission_B.InitialState[4] = codegenReal2Mission_B.Bias;
          codegenReal2Mission_B.InitialState[5] = 0.0;
          codegenReal2Mission_B.InitialState[6] = 0.0;
          codegenReal2Mission_B.InitialState[7] = 0.0;

          // Merge: '<S14>/ Merge 2' incorporates:
          //   Memory: '<S20>/MemoryStopTrigger1'
          //   Memory: '<S20>/MemoryTriggerWP'
          //   Sum: '<S20>/Sum'

          codegenReal2Mission_B.ResetTrigger =
            codegenReal2Mission_DW.MemoryStopTrigger1_PreviousInput +
            codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n;

          // Update for Memory: '<S20>/MemoryTriggerWP' incorporates:
          //   Constant: '<S20>/TirggerWayPointGen'

          codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n = 1.0;

          // Update for Memory: '<S20>/MemoryStopTrigger1' incorporates:
          //   Memory: '<S20>/MemoryStopTrigger2'

          codegenReal2Mission_DW.MemoryStopTrigger1_PreviousInput =
            codegenReal2Mission_DW.MemoryStopTrigger2_PreviousInput;

          // Update for Memory: '<S20>/MemoryStopTrigger2' incorporates:
          //   Constant: '<S20>/StopTrigger'

          codegenReal2Mission_DW.MemoryStopTrigger2_PreviousInput = -1.0;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        switch (codegenReal2Mission_DW.is_GuidanceLogic) {
         case codegenReal2Mission_IN_OrbitFollower:
          // Merge: '<S14>/ Merge 2'
          codegenReal2Mission_B.ResetTrigger = 0.0;
          if (codegenReal2Mission_DW.is_OrbitFollower == 1) {
            // Product: '<S18>/Divide' incorporates:
            //   DataTypeConversion: '<S18>/Param1'

            second =
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat /
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1;

            // Switch: '<S37>/Switch' incorporates:
            //   Abs: '<S37>/Abs'
            //   Bias: '<S37>/Bias'
            //   Bias: '<S37>/Bias1'
            //   Constant: '<S37>/Constant2'
            //   Constant: '<S38>/Constant'
            //   DataStoreRead: '<S18>/LatitudeGCS'
            //   Math: '<S37>/Math Function1'
            //   RelationalOperator: '<S38>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              fracSecs = LatitudeGCS;
            }

            // Abs: '<S34>/Abs1'
            rtb_Switch_fe = std::abs(fracSecs);

            // Switch: '<S34>/Switch' incorporates:
            //   Bias: '<S34>/Bias'
            //   Bias: '<S34>/Bias1'
            //   Constant: '<S25>/Constant'
            //   Constant: '<S25>/Constant1'
            //   Constant: '<S36>/Constant'
            //   Gain: '<S34>/Gain'
            //   Product: '<S34>/Divide1'
            //   RelationalOperator: '<S36>/Compare'
            //   Switch: '<S25>/Switch1'

            if (rtb_Switch_fe > 90.0) {
              // Signum: '<S34>/Sign1'
              if (fracSecs < 0.0) {
                fracSecs = -1.0;
              } else if (fracSecs > 0.0) {
                fracSecs = 1.0;
              } else if (fracSecs == 0.0) {
                fracSecs = 0.0;
              } else {
                fracSecs = (rtNaN);
              }

              fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
              SequenceID_prev = 180;
            } else {
              SequenceID_prev = 0;
            }

            // Sum: '<S25>/Sum' incorporates:
            //   DataStoreRead: '<S18>/LongitudeGCS'

            rtb_Switch_fe = static_cast<real_T>(SequenceID_prev) + LongitudeGCS;

            // Sum: '<S23>/Sum1'
            rtb_Abs1 =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
              fracSecs;

            // Switch: '<S31>/Switch' incorporates:
            //   Abs: '<S31>/Abs'
            //   Bias: '<S31>/Bias'
            //   Bias: '<S31>/Bias1'
            //   Constant: '<S31>/Constant2'
            //   Constant: '<S32>/Constant'
            //   Math: '<S31>/Math Function1'
            //   RelationalOperator: '<S32>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S28>/Abs1'
            temp = std::abs(rtb_Abs1);

            // Switch: '<S28>/Switch' incorporates:
            //   Bias: '<S28>/Bias'
            //   Bias: '<S28>/Bias1'
            //   Constant: '<S24>/Constant'
            //   Constant: '<S24>/Constant1'
            //   Constant: '<S30>/Constant'
            //   Gain: '<S28>/Gain'
            //   Product: '<S28>/Divide1'
            //   RelationalOperator: '<S30>/Compare'
            //   Switch: '<S24>/Switch1'

            if (temp > 90.0) {
              // Signum: '<S28>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              temp = (-(temp + -90.0) + 90.0) * rtb_Abs1;
              SequenceID_prev = 180;
            } else {
              temp = rtb_Abs1;
              SequenceID_prev = 0;
            }

            // Switch: '<S35>/Switch' incorporates:
            //   Abs: '<S35>/Abs'
            //   Bias: '<S35>/Bias'
            //   Bias: '<S35>/Bias1'
            //   Constant: '<S35>/Constant2'
            //   Constant: '<S39>/Constant'
            //   Math: '<S35>/Math Function1'
            //   RelationalOperator: '<S39>/Compare'

            if (std::abs(rtb_Switch_fe) > 180.0) {
              rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S24>/Sum' incorporates:
            //   Sum: '<S23>/Sum1'

            rtb_Switch_fe =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon -
               rtb_Switch_fe) + static_cast<real_T>(SequenceID_prev);

            // UnitConversion: '<S27>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 0.017453292519943295 * temp;

            // UnitConversion: '<S42>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            fracSecs *= 0.017453292519943295;

            // Trigonometry: '<S43>/Trigonometric Function1'
            rtb_Down_b = std::sin(fracSecs);

            // Sum: '<S43>/Sum1' incorporates:
            //   Constant: '<S43>/Constant'
            //   Product: '<S43>/Product1'

            rtb_Down_b = 1.0 - codegenReal2Mission_ConstB.sqrt_mc *
              codegenReal2Mission_ConstB.sqrt_mc * rtb_Down_b * rtb_Down_b;

            // Product: '<S41>/Product1' incorporates:
            //   Constant: '<S41>/Constant1'
            //   Sqrt: '<S41>/sqrt'

            temp = 6.378137E+6 / std::sqrt(rtb_Down_b);

            // Product: '<S26>/dNorth' incorporates:
            //   Constant: '<S41>/Constant2'
            //   Product: '<S41>/Product3'
            //   Trigonometry: '<S41>/Trigonometric Function1'

            rtb_Down_b = rtb_Abs1 / rt_atan2d_snf(1.0, temp *
              codegenReal2Mission_ConstB.Sum1_a / rtb_Down_b);

            // Switch: '<S29>/Switch' incorporates:
            //   Abs: '<S29>/Abs'
            //   Bias: '<S29>/Bias'
            //   Bias: '<S29>/Bias1'
            //   Constant: '<S29>/Constant2'
            //   Constant: '<S33>/Constant'
            //   Math: '<S29>/Math Function1'
            //   RelationalOperator: '<S33>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Switch_fe) > 180.0) {
              rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) + -180.0;
            }

            // Product: '<S26>/dEast' incorporates:
            //   Constant: '<S41>/Constant3'
            //   Product: '<S41>/Product4'
            //   Trigonometry: '<S41>/Trigonometric Function'
            //   Trigonometry: '<S41>/Trigonometric Function2'
            //   UnitConversion: '<S27>/Unit Conversion'

            temp = 1.0 / rt_atan2d_snf(1.0, temp * std::cos(fracSecs)) *
              (0.017453292519943295 * rtb_Switch_fe);

            // Sum: '<S26>/Sum2' incorporates:
            //   Product: '<S26>/x*cos'
            //   Product: '<S26>/y*sin'

            fracSecs = temp * 0.0 + rtb_Down_b;

            // Sum: '<S26>/Sum3' incorporates:
            //   Product: '<S26>/x*sin'
            //   Product: '<S26>/y*cos'

            rtb_Abs1 = temp - rtb_Down_b * 0.0;

            // Sum: '<S18>/SumUp' incorporates:
            //   DataStoreRead: '<S18>/AltitudeGCS'
            //   Gain: '<S18>/inverse'
            //   Sum: '<S23>/Sum'

            temp =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
               -AltitudeGCS) +
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;

            // SignalConversion generated from: '<S18>/Orbit Follower' incorporates:
            //   Gain: '<S18>/Up2Down'

            ct[0] = fracSecs;
            ct[1] = rtb_Abs1;
            ct[2] = -temp;

            // MATLABSystem: '<S18>/Orbit Follower' incorporates:
            //   DataTypeConversion: '<S18>/Param1'
            //   DataTypeConversion: '<S18>/Param2'
            //   Gain: '<S18>/Up2Down'
            //   Memory: '<S2>/DelayPose'
            //   SignalConversion generated from: '<S18>/Orbit Follower'

            b_shi = codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
            codegenReal2Mission_DW.obj_n.OrbitRadiusFlag = 0U;
            if (codegenReal2Mission_B.MemoryCurrentMission.params.Param1 <=
                220.0F) {
              b_shi = 220.0;
              codegenReal2Mission_DW.obj_n.OrbitRadiusFlag = 1U;
            }

            codegenReal2Mission_DW.obj_n.LookaheadDistFlag = 0U;
            codegenReal2Mission_DW.obj_n.LookaheadDistFlag = 1U;
            rtb_Gain1 = codegenReal2Mission_DW.DelayPose_PreviousInput[0] -
              fracSecs;
            rtb_Sum1_0[0] = rtb_Gain1;
            rtb_Down2Up_e = codegenReal2Mission_DW.DelayPose_PreviousInput[1] -
              rtb_Abs1;
            rtb_Sum1_0[1] = rtb_Down2Up_e;
            if (codegenReal2Mission_norm(rtb_Sum1_0) < 2.47032822920623E-323) {
              rtb_ReshapeRowVec[2] = -temp;

              // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
              //   Gain: '<S18>/Up2Down'

              codegenReal2Mission_B.GuidanceCmds.HeadingAngle =
                codegenReal2Mission_DW.DelayPose_PreviousInput[3];

              // Merge: '<S14>/ Merge '
              codegenReal2Mission_B.thisTaskStatus =
                codegenReal2Mission_DW.obj_n.NumCircles;
            } else {
              p = false;
              p_0 = true;
              nrowx = 0;
              exitg1 = false;
              while ((!exitg1) && (nrowx < 3)) {
                if ((codegenReal2Mission_DW.obj_n.OrbitCenterInternal[nrowx] ==
                     ct[nrowx]) || (std::isnan
                                    (codegenReal2Mission_DW.obj_n.OrbitCenterInternal
                                     [nrowx]) && std::isnan(ct[nrowx]))) {
                  nrowx++;
                } else {
                  p_0 = false;
                  exitg1 = true;
                }
              }

              if (p_0) {
                p = true;
              }

              guard2 = false;
              if (!p) {
                guard2 = true;
              } else {
                p = false;
                if ((codegenReal2Mission_DW.obj_n.OrbitRadiusInternal == b_shi) ||
                    (std::isnan(codegenReal2Mission_DW.obj_n.OrbitRadiusInternal)
                     && std::isnan(b_shi))) {
                  p = true;
                }

                if (!p) {
                  guard2 = true;
                }
              }

              if (guard2) {
                codegenReal2Mission_DW.obj_n.NumCircles = 0.0;
                codegenReal2Mission_DW.obj_n.OrbitCenterInternal[0] = fracSecs;
                codegenReal2Mission_DW.obj_n.OrbitCenterInternal[1] = rtb_Abs1;
                codegenReal2Mission_DW.obj_n.OrbitCenterInternal[2] = -temp;
                codegenReal2Mission_DW.obj_n.OrbitRadiusInternal = b_shi;
                codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag = true;
              }

              if (35.0 >= b_shi) {
                codegenReal2Mission_DW.obj_n.LookaheadDistance = 0.9 * b_shi;
              } else {
                codegenReal2Mission_DW.obj_n.LookaheadDistance = 35.0;
              }

              distToCenter_tmp[0] = rtb_Gain1;
              distToCenter_tmp[1] = rtb_Down2Up_e;
              rtb_Switch_fe = std::sqrt(rtb_Down2Up_e * rtb_Down2Up_e +
                rtb_Gain1 * rtb_Gain1);
              check = b_shi + codegenReal2Mission_DW.obj_n.LookaheadDistance;
              rtb_Switch = std::abs(check);
              p = !std::isinf(rtb_Switch);
              p_0 = !std::isnan(rtb_Switch);
              if (p && p_0) {
                if (rtb_Switch <= 2.2250738585072014E-308) {
                  rtb_Down_b = 4.94065645841247E-324;
                } else {
                  frexp(rtb_Switch, &imo);
                  rtb_Down_b = std::ldexp(1.0, imo - 53);
                }
              } else {
                rtb_Down_b = (rtNaN);
              }

              guard2 = false;
              if (rtb_Switch_fe >= check - 5.0 * rtb_Down_b) {
                guard2 = true;
              } else {
                if (p && p_0) {
                  if (rtb_Switch <= 2.2250738585072014E-308) {
                    rtb_Down_b = 4.94065645841247E-324;
                  } else {
                    frexp(rtb_Switch, &b_nrows);
                    rtb_Down_b = std::ldexp(1.0, b_nrows - 53);
                  }
                } else {
                  rtb_Down_b = (rtNaN);
                }

                if (rtb_Switch_fe <= (b_shi -
                                      codegenReal2Mission_DW.obj_n.LookaheadDistance)
                    + 5.0 * rtb_Down_b) {
                  guard2 = true;
                } else {
                  if (codegenReal2Mission_DW.obj_n.StartFlag) {
                    codegenReal2Mission_DW.obj_n.PrevPosition[0] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                    codegenReal2Mission_DW.obj_n.PrevPosition[1] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                    codegenReal2Mission_DW.obj_n.PrevPosition[2] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                    codegenReal2Mission_DW.obj_n.StartFlag = false;
                  }

                  rtb_Sum1_0[0] = rtb_Gain1;
                  rtb_Sum1_0[1] = rtb_Down2Up_e;
                  rtb_Down_b = codegenReal2Mission_norm(rtb_Sum1_0);
                  rtb_Switch_fe =
                    ((codegenReal2Mission_DW.obj_n.LookaheadDistance *
                      codegenReal2Mission_DW.obj_n.LookaheadDistance - b_shi *
                      b_shi) + rtb_Down_b * rtb_Down_b) / (2.0 * rtb_Down_b);
                  b_shi = fracSecs -
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  x2 = b_shi * rtb_Switch_fe / rtb_Down_b +
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  check = rtb_Abs1 -
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  rtb_Sum_j = check * rtb_Switch_fe / rtb_Down_b +
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  rtb_Switch = std::sqrt
                    (codegenReal2Mission_DW.obj_n.LookaheadDistance *
                     codegenReal2Mission_DW.obj_n.LookaheadDistance -
                     rtb_Switch_fe * rtb_Switch_fe);
                  rtb_Switch_fe = check * rtb_Switch / rtb_Down_b;
                  distToCenter_tmp[0] = x2 - rtb_Switch_fe;
                  distToCenter_tmp[1] = rtb_Switch_fe + x2;
                  rtb_Switch_fe = b_shi * rtb_Switch / rtb_Down_b;
                  rtb_Down_b = rtb_Switch_fe + rtb_Sum_j;
                  rtb_Switch = rtb_Sum_j - rtb_Switch_fe;
                  if ((codegenReal2Mission_B.MemoryCurrentMission.params.Param2 ==
                       0.0F) &&
                      (!codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag)) {
                    rtb_Sum_j =
                      codegenReal2Mission_DW.obj_n.TurnDirectionInternal;
                  } else {
                    rtb_Sum_j =
                      codegenReal2Mission_B.MemoryCurrentMission.params.Param2;
                  }

                  turnVector[0] = codegenReal2Mission_DW.obj_n.PrevPosition[0] -
                    fracSecs;
                  turnVector[1] = codegenReal2Mission_DW.obj_n.PrevPosition[1] -
                    rtb_Abs1;
                  rtb_ReshapeRowVec[0] = turnVector[0];
                  rtb_ReshapeRowVec[1] = turnVector[1];
                  rtb_ReshapeRowVec[2] = 0.0;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    rtb_Gain1;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                    rtb_Down2Up_e;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                  if (rtb_Sum_j < 0.0) {
                    rtb_ReshapeRowVec[0] = rtb_Gain1;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                      turnVector[0];
                    rtb_ReshapeRowVec[1] = rtb_Down2Up_e;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                      turnVector[1];
                    rtb_ReshapeRowVec[2] = 0.0;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                    rtb_Sum_j = -1.0;
                  } else if (rtb_Sum_j > 0.0) {
                    rtb_Sum_j = 1.0;
                  } else if (rtb_Sum_j == 0.0) {
                    rtb_Sum_j = 0.0;
                  } else {
                    rtb_Sum_j = (rtNaN);
                  }

                  rtb_Switch_fe = codegenReal2Mission_norm_b(rtb_ReshapeRowVec);
                  rtb_Down2Up_e = codegenReal2Mission_norm_b
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1);
                  rtb_Gain1 = rtb_ReshapeRowVec[0] / rtb_Switch_fe;
                  x2 = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] /
                    rtb_Down2Up_e;
                  rtb_ReshapeRowVec_tmp = rtb_ReshapeRowVec[1] / rtb_Switch_fe;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp =
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] /
                    rtb_Down2Up_e;
                  codegenReal2Mission_DW.obj_n.PrevPosition[0] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  codegenReal2Mission_DW.obj_n.PrevPosition[1] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  codegenReal2Mission_DW.obj_n.PrevPosition[2] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                  codegenReal2Mission_DW.obj_n.NumCircles += rt_atan2d_snf
                    (rtb_Gain1 *
                     rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp - x2
                     * rtb_ReshapeRowVec_tmp, (rtb_Gain1 * x2 +
                      rtb_ReshapeRowVec_tmp *
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp) +
                     0.0 / rtb_Switch_fe * (0.0 / rtb_Down2Up_e)) / 2.0 /
                    3.1415926535897931;

                  // Merge: '<S14>/ Merge ' incorporates:
                  //   DataTypeConversion: '<S18>/Param2'

                  codegenReal2Mission_B.thisTaskStatus =
                    codegenReal2Mission_DW.obj_n.NumCircles;
                  switch (static_cast<int32_T>(rtb_Sum_j)) {
                   case 1:
                    if ((distToCenter_tmp[0] -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Down_b -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi > 0.0) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }
                    break;

                   case -1:
                    if ((distToCenter_tmp[0] -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Down_b -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi < 0.0) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }
                    break;

                   default:
                    if (std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                          (rtb_Down_b -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                           distToCenter_tmp[0] -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                          codegenReal2Mission_DW.DelayPose_PreviousInput[3])) <
                        std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                          (rtb_Switch -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                           distToCenter_tmp[1] -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                          codegenReal2Mission_DW.DelayPose_PreviousInput[3]))) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }

                    if ((rtb_Gain1 -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Switch -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi > 0.0) {
                      codegenReal2Mission_DW.obj_n.TurnDirectionInternal = 1.0;
                    } else {
                      codegenReal2Mission_DW.obj_n.TurnDirectionInternal = -1.0;
                    }

                    codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag = false;
                    break;
                  }
                }
              }

              if (guard2) {
                rtb_Switch_fe = codegenReal2Mission_norm(distToCenter_tmp);
                rtb_Gain1 = rtb_Gain1 / rtb_Switch_fe * b_shi + fracSecs;
                rtb_Switch = rtb_Down2Up_e / rtb_Switch_fe * b_shi + rtb_Abs1;

                // Merge: '<S14>/ Merge '
                codegenReal2Mission_B.thisTaskStatus =
                  codegenReal2Mission_DW.obj_n.NumCircles;
              }

              rtb_ReshapeRowVec[2] = -temp;

              // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
              //   DataTypeConversion: '<S18>/Param2'
              //   Gain: '<S18>/Up2Down'

              codegenReal2Mission_B.GuidanceCmds.HeadingAngle = rt_atan2d_snf
                (rtb_Switch - codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                 rtb_Gain1 - codegenReal2Mission_DW.DelayPose_PreviousInput[0]);
            }

            // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S18>/Param3'
            //   Gain: '<S18>/Down2Height'
            //   MATLABSystem: '<S18>/Orbit Follower'

            codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
            codegenReal2Mission_B.GuidanceCmds.AirSpeed =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Bias: '<S18>/ClockwiseRotation'
            //   Constant: '<S18>/InitialFlightPathAngle'
            //   Constant: '<S18>/InitialRollAngle'
            //   Constant: '<S18>/InitialRollAngleRate'
            //   DataTypeConversion: '<S18>/Param1'
            //   DataTypeConversion: '<S18>/Param3'
            //   Product: '<S18>/EastDis'
            //   Product: '<S18>/NorthDis'
            //   Reshape: '<S18>/Reshape'
            //   Sum: '<S18>/SumInitEast'
            //   Sum: '<S18>/SumInitNorth'
            //   Trigonometry: '<S18>/Cos'
            //   Trigonometry: '<S18>/Sin'

            codegenReal2Mission_B.InitialState[0] = std::cos(second) *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1 +
              fracSecs;
            codegenReal2Mission_B.InitialState[1] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1 * std::
              sin(second) + rtb_Abs1;
            codegenReal2Mission_B.InitialState[2] = temp;
            codegenReal2Mission_B.InitialState[3] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
            codegenReal2Mission_B.InitialState[4] = second + 1.5707963267948966;
            codegenReal2Mission_B.InitialState[5] = 0.0;
            codegenReal2Mission_B.InitialState[6] = 0.0;
            codegenReal2Mission_B.InitialState[7] = 0.0;
          } else {
            // Product: '<S19>/Map2Radian' incorporates:
            //   Bias: '<S19>/Bias'
            //   Constant: '<S19>/two_pi'
            //   DataTypeConversion: '<S19>/CastToDouble'
            //   Gain: '<S19>/HalveMissionUAV'
            //   Product: '<S19>/Divide'
            //   Sum: '<S19>/Minus'

            // case IN_CirclingNav:
            second = (static_cast<real_T>
                      (codegenReal2Mission_B.MemoryCurrentMission.FormationPos)
                      - static_cast<real_T>
                      (codegenReal2Mission_B.MemoryCurrentMission.numUAV + 1) *
                      0.5) * (6.2831853071795862 / static_cast<real_T>
                              (codegenReal2Mission_B.MemoryCurrentMission.numUAV));

            // Switch: '<S60>/Switch' incorporates:
            //   Abs: '<S60>/Abs'
            //   Bias: '<S60>/Bias'
            //   Bias: '<S60>/Bias1'
            //   Constant: '<S60>/Constant2'
            //   Constant: '<S61>/Constant'
            //   DataStoreRead: '<S19>/LatitudeGCS'
            //   Math: '<S60>/Math Function1'
            //   RelationalOperator: '<S61>/Compare'

            if (std::abs(LatitudeGCS) > 180.0) {
              fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              fracSecs = LatitudeGCS;
            }

            // Abs: '<S57>/Abs1'
            rtb_Switch_fe = std::abs(fracSecs);

            // Switch: '<S57>/Switch' incorporates:
            //   Bias: '<S57>/Bias'
            //   Bias: '<S57>/Bias1'
            //   Constant: '<S48>/Constant'
            //   Constant: '<S48>/Constant1'
            //   Constant: '<S59>/Constant'
            //   Gain: '<S57>/Gain'
            //   Product: '<S57>/Divide1'
            //   RelationalOperator: '<S59>/Compare'
            //   Switch: '<S48>/Switch1'

            if (rtb_Switch_fe > 90.0) {
              // Signum: '<S57>/Sign1'
              if (fracSecs < 0.0) {
                fracSecs = -1.0;
              } else if (fracSecs > 0.0) {
                fracSecs = 1.0;
              } else if (fracSecs == 0.0) {
                fracSecs = 0.0;
              } else {
                fracSecs = (rtNaN);
              }

              fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
              SequenceID_prev = 180;
            } else {
              SequenceID_prev = 0;
            }

            // Sum: '<S48>/Sum' incorporates:
            //   DataStoreRead: '<S19>/LongitudeGCS'

            rtb_Switch_fe = static_cast<real_T>(SequenceID_prev) + LongitudeGCS;

            // Sum: '<S46>/Sum1'
            rtb_Abs1 =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
              fracSecs;

            // Switch: '<S54>/Switch' incorporates:
            //   Abs: '<S54>/Abs'
            //   Bias: '<S54>/Bias'
            //   Bias: '<S54>/Bias1'
            //   Constant: '<S54>/Constant2'
            //   Constant: '<S55>/Constant'
            //   Math: '<S54>/Math Function1'
            //   RelationalOperator: '<S55>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S51>/Abs1'
            temp = std::abs(rtb_Abs1);

            // Switch: '<S51>/Switch' incorporates:
            //   Bias: '<S51>/Bias'
            //   Bias: '<S51>/Bias1'
            //   Constant: '<S47>/Constant'
            //   Constant: '<S47>/Constant1'
            //   Constant: '<S53>/Constant'
            //   Gain: '<S51>/Gain'
            //   Product: '<S51>/Divide1'
            //   RelationalOperator: '<S53>/Compare'
            //   Switch: '<S47>/Switch1'

            if (temp > 90.0) {
              // Signum: '<S51>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              temp = (-(temp + -90.0) + 90.0) * rtb_Abs1;
              SequenceID_prev = 180;
            } else {
              temp = rtb_Abs1;
              SequenceID_prev = 0;
            }

            // Switch: '<S58>/Switch' incorporates:
            //   Abs: '<S58>/Abs'
            //   Bias: '<S58>/Bias'
            //   Bias: '<S58>/Bias1'
            //   Constant: '<S58>/Constant2'
            //   Constant: '<S62>/Constant'
            //   Math: '<S58>/Math Function1'
            //   RelationalOperator: '<S62>/Compare'

            if (std::abs(rtb_Switch_fe) > 180.0) {
              rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S47>/Sum' incorporates:
            //   Sum: '<S46>/Sum1'

            rtb_Switch_fe =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon -
               rtb_Switch_fe) + static_cast<real_T>(SequenceID_prev);

            // UnitConversion: '<S50>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 0.017453292519943295 * temp;

            // UnitConversion: '<S65>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            fracSecs *= 0.017453292519943295;

            // Trigonometry: '<S66>/Trigonometric Function1'
            rtb_Down_b = std::sin(fracSecs);

            // Sum: '<S66>/Sum1' incorporates:
            //   Constant: '<S66>/Constant'
            //   Product: '<S66>/Product1'

            rtb_Down_b = 1.0 - codegenReal2Mission_ConstB.sqrt_g *
              codegenReal2Mission_ConstB.sqrt_g * rtb_Down_b * rtb_Down_b;

            // Product: '<S64>/Product1' incorporates:
            //   Constant: '<S64>/Constant1'
            //   Sqrt: '<S64>/sqrt'

            temp = 6.378137E+6 / std::sqrt(rtb_Down_b);

            // Product: '<S49>/dNorth' incorporates:
            //   Constant: '<S64>/Constant2'
            //   Product: '<S64>/Product3'
            //   Trigonometry: '<S64>/Trigonometric Function1'

            rtb_Down_b = rtb_Abs1 / rt_atan2d_snf(1.0, temp *
              codegenReal2Mission_ConstB.Sum1_fi / rtb_Down_b);

            // Switch: '<S52>/Switch' incorporates:
            //   Abs: '<S52>/Abs'
            //   Bias: '<S52>/Bias'
            //   Bias: '<S52>/Bias1'
            //   Constant: '<S52>/Constant2'
            //   Constant: '<S56>/Constant'
            //   Math: '<S52>/Math Function1'
            //   RelationalOperator: '<S56>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Switch_fe) > 180.0) {
              rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) + -180.0;
            }

            // Product: '<S49>/dEast' incorporates:
            //   Constant: '<S64>/Constant3'
            //   Product: '<S64>/Product4'
            //   Trigonometry: '<S64>/Trigonometric Function'
            //   Trigonometry: '<S64>/Trigonometric Function2'
            //   UnitConversion: '<S50>/Unit Conversion'

            temp = 1.0 / rt_atan2d_snf(1.0, temp * std::cos(fracSecs)) *
              (0.017453292519943295 * rtb_Switch_fe);

            // Sum: '<S49>/Sum2' incorporates:
            //   Product: '<S49>/x*cos'
            //   Product: '<S49>/y*sin'

            fracSecs = temp * 0.0 + rtb_Down_b;

            // Sum: '<S49>/Sum3' incorporates:
            //   Product: '<S49>/x*sin'
            //   Product: '<S49>/y*cos'

            rtb_Abs1 = temp - rtb_Down_b * 0.0;

            // SignalConversion generated from: '<S19>/Orbit Follower' incorporates:
            //   DataStoreRead: '<S19>/AltitudeGCS'
            //   Gain: '<S19>/inverse'
            //   Sum: '<S46>/Sum'
            //   UnaryMinus: '<S46>/Ze2height'

            ct[0] = fracSecs;
            ct[1] = rtb_Abs1;
            ct[2] =
              -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
                -AltitudeGCS);

            // MATLABSystem: '<S19>/Orbit Follower' incorporates:
            //   DataTypeConversion: '<S19>/Param1'
            //   DataTypeConversion: '<S19>/Param2'
            //   Memory: '<S2>/DelayPose'
            //   SignalConversion generated from: '<S19>/Orbit Follower'

            b_shi = codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
            codegenReal2Mission_DW.obj_a.OrbitRadiusFlag = 0U;
            if (codegenReal2Mission_B.MemoryCurrentMission.params.Param1 <=
                220.0F) {
              b_shi = 220.0;
              codegenReal2Mission_DW.obj_a.OrbitRadiusFlag = 1U;
            }

            codegenReal2Mission_DW.obj_a.LookaheadDistFlag = 0U;
            codegenReal2Mission_DW.obj_a.LookaheadDistFlag = 1U;
            rtb_Gain1 = codegenReal2Mission_DW.DelayPose_PreviousInput[0] -
              fracSecs;
            rtb_Sum1_0[0] = rtb_Gain1;
            rtb_Down2Up_e = codegenReal2Mission_DW.DelayPose_PreviousInput[1] -
              rtb_Abs1;
            rtb_Sum1_0[1] = rtb_Down2Up_e;
            if (codegenReal2Mission_norm(rtb_Sum1_0) < 2.47032822920623E-323) {
              rtb_ReshapeRowVec[2] = ct[2];

              // BusCreator: '<S19>/GuidanceCMDBusCreator'
              codegenReal2Mission_B.GuidanceCmds.HeadingAngle =
                codegenReal2Mission_DW.DelayPose_PreviousInput[3];

              // Merge: '<S14>/ Merge '
              codegenReal2Mission_B.thisTaskStatus =
                codegenReal2Mission_DW.obj_a.NumCircles;
            } else {
              p = false;
              p_0 = true;
              nrowx = 0;
              exitg1 = false;
              while ((!exitg1) && (nrowx < 3)) {
                if ((codegenReal2Mission_DW.obj_a.OrbitCenterInternal[nrowx] ==
                     ct[nrowx]) || (std::isnan
                                    (codegenReal2Mission_DW.obj_a.OrbitCenterInternal
                                     [nrowx]) && std::isnan(ct[nrowx]))) {
                  nrowx++;
                } else {
                  p_0 = false;
                  exitg1 = true;
                }
              }

              if (p_0) {
                p = true;
              }

              guard2 = false;
              if (!p) {
                guard2 = true;
              } else {
                p = false;
                if ((codegenReal2Mission_DW.obj_a.OrbitRadiusInternal == b_shi) ||
                    (std::isnan(codegenReal2Mission_DW.obj_a.OrbitRadiusInternal)
                     && std::isnan(b_shi))) {
                  p = true;
                }

                if (!p) {
                  guard2 = true;
                }
              }

              if (guard2) {
                codegenReal2Mission_DW.obj_a.NumCircles = 0.0;
                codegenReal2Mission_DW.obj_a.OrbitCenterInternal[0] = fracSecs;
                codegenReal2Mission_DW.obj_a.OrbitCenterInternal[1] = rtb_Abs1;
                codegenReal2Mission_DW.obj_a.OrbitCenterInternal[2] = ct[2];
                codegenReal2Mission_DW.obj_a.OrbitRadiusInternal = b_shi;
                codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag = true;
              }

              if (35.0 >= b_shi) {
                codegenReal2Mission_DW.obj_a.LookaheadDistance = 0.9 * b_shi;
              } else {
                codegenReal2Mission_DW.obj_a.LookaheadDistance = 35.0;
              }

              distToCenter_tmp[0] = rtb_Gain1;
              distToCenter_tmp[1] = rtb_Down2Up_e;
              rtb_Switch_fe = std::sqrt(rtb_Down2Up_e * rtb_Down2Up_e +
                rtb_Gain1 * rtb_Gain1);
              check = b_shi + codegenReal2Mission_DW.obj_a.LookaheadDistance;
              rtb_Switch = std::abs(check);
              p = !std::isinf(rtb_Switch);
              p_0 = !std::isnan(rtb_Switch);
              if (p && p_0) {
                if (rtb_Switch <= 2.2250738585072014E-308) {
                  rtb_Down_b = 4.94065645841247E-324;
                } else {
                  frexp(rtb_Switch, &imo);
                  rtb_Down_b = std::ldexp(1.0, imo - 53);
                }
              } else {
                rtb_Down_b = (rtNaN);
              }

              guard2 = false;
              if (rtb_Switch_fe >= check - 5.0 * rtb_Down_b) {
                guard2 = true;
              } else {
                if (p && p_0) {
                  if (rtb_Switch <= 2.2250738585072014E-308) {
                    rtb_Down_b = 4.94065645841247E-324;
                  } else {
                    frexp(rtb_Switch, &b_nrows);
                    rtb_Down_b = std::ldexp(1.0, b_nrows - 53);
                  }
                } else {
                  rtb_Down_b = (rtNaN);
                }

                if (rtb_Switch_fe <= (b_shi -
                                      codegenReal2Mission_DW.obj_a.LookaheadDistance)
                    + 5.0 * rtb_Down_b) {
                  guard2 = true;
                } else {
                  if (codegenReal2Mission_DW.obj_a.StartFlag) {
                    codegenReal2Mission_DW.obj_a.PrevPosition[0] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                    codegenReal2Mission_DW.obj_a.PrevPosition[1] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                    codegenReal2Mission_DW.obj_a.PrevPosition[2] =
                      codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                    codegenReal2Mission_DW.obj_a.StartFlag = false;
                  }

                  rtb_Sum1_0[0] = rtb_Gain1;
                  rtb_Sum1_0[1] = rtb_Down2Up_e;
                  rtb_Down_b = codegenReal2Mission_norm(rtb_Sum1_0);
                  rtb_Switch_fe =
                    ((codegenReal2Mission_DW.obj_a.LookaheadDistance *
                      codegenReal2Mission_DW.obj_a.LookaheadDistance - b_shi *
                      b_shi) + rtb_Down_b * rtb_Down_b) / (2.0 * rtb_Down_b);
                  b_shi = fracSecs -
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  x2 = b_shi * rtb_Switch_fe / rtb_Down_b +
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  check = rtb_Abs1 -
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  rtb_Sum_j = check * rtb_Switch_fe / rtb_Down_b +
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  rtb_Switch = std::sqrt
                    (codegenReal2Mission_DW.obj_a.LookaheadDistance *
                     codegenReal2Mission_DW.obj_a.LookaheadDistance -
                     rtb_Switch_fe * rtb_Switch_fe);
                  rtb_Switch_fe = check * rtb_Switch / rtb_Down_b;
                  distToCenter_tmp[0] = x2 - rtb_Switch_fe;
                  distToCenter_tmp[1] = rtb_Switch_fe + x2;
                  rtb_Switch_fe = b_shi * rtb_Switch / rtb_Down_b;
                  rtb_Down_b = rtb_Switch_fe + rtb_Sum_j;
                  rtb_Switch = rtb_Sum_j - rtb_Switch_fe;
                  if ((codegenReal2Mission_B.MemoryCurrentMission.params.Param2 ==
                       0.0F) &&
                      (!codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag)) {
                    rtb_Sum_j =
                      codegenReal2Mission_DW.obj_a.TurnDirectionInternal;
                  } else {
                    rtb_Sum_j =
                      codegenReal2Mission_B.MemoryCurrentMission.params.Param2;
                  }

                  turnVector[0] = codegenReal2Mission_DW.obj_a.PrevPosition[0] -
                    fracSecs;
                  turnVector[1] = codegenReal2Mission_DW.obj_a.PrevPosition[1] -
                    rtb_Abs1;
                  rtb_ReshapeRowVec[0] = turnVector[0];
                  rtb_ReshapeRowVec[1] = turnVector[1];
                  rtb_ReshapeRowVec[2] = 0.0;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    rtb_Gain1;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                    rtb_Down2Up_e;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                  if (rtb_Sum_j < 0.0) {
                    rtb_ReshapeRowVec[0] = rtb_Gain1;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                      turnVector[0];
                    rtb_ReshapeRowVec[1] = rtb_Down2Up_e;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                      turnVector[1];
                    rtb_ReshapeRowVec[2] = 0.0;
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = 0.0;
                    rtb_Sum_j = -1.0;
                  } else if (rtb_Sum_j > 0.0) {
                    rtb_Sum_j = 1.0;
                  } else if (rtb_Sum_j == 0.0) {
                    rtb_Sum_j = 0.0;
                  } else {
                    rtb_Sum_j = (rtNaN);
                  }

                  rtb_Switch_fe = codegenReal2Mission_norm_b(rtb_ReshapeRowVec);
                  rtb_Down2Up_e = codegenReal2Mission_norm_b
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1);
                  rtb_Gain1 = rtb_ReshapeRowVec[0] / rtb_Switch_fe;
                  x2 = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] /
                    rtb_Down2Up_e;
                  rtb_ReshapeRowVec_tmp = rtb_ReshapeRowVec[1] / rtb_Switch_fe;
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp =
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] /
                    rtb_Down2Up_e;
                  codegenReal2Mission_DW.obj_a.PrevPosition[0] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                  codegenReal2Mission_DW.obj_a.PrevPosition[1] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                  codegenReal2Mission_DW.obj_a.PrevPosition[2] =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                  codegenReal2Mission_DW.obj_a.NumCircles += rt_atan2d_snf
                    (rtb_Gain1 *
                     rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp - x2
                     * rtb_ReshapeRowVec_tmp, (rtb_Gain1 * x2 +
                      rtb_ReshapeRowVec_tmp *
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp) +
                     0.0 / rtb_Switch_fe * (0.0 / rtb_Down2Up_e)) / 2.0 /
                    3.1415926535897931;

                  // Merge: '<S14>/ Merge ' incorporates:
                  //   DataTypeConversion: '<S19>/Param2'

                  codegenReal2Mission_B.thisTaskStatus =
                    codegenReal2Mission_DW.obj_a.NumCircles;
                  switch (static_cast<int32_T>(rtb_Sum_j)) {
                   case 1:
                    if ((distToCenter_tmp[0] -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Down_b -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi > 0.0) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }
                    break;

                   case -1:
                    if ((distToCenter_tmp[0] -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Down_b -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi < 0.0) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }
                    break;

                   default:
                    if (std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                          (rtb_Down_b -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                           distToCenter_tmp[0] -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                          codegenReal2Mission_DW.DelayPose_PreviousInput[3])) <
                        std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                          (rtb_Switch -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                           distToCenter_tmp[1] -
                           codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                          codegenReal2Mission_DW.DelayPose_PreviousInput[3]))) {
                      rtb_Gain1 = distToCenter_tmp[0];
                      rtb_Switch = rtb_Down_b;
                    } else {
                      rtb_Gain1 = distToCenter_tmp[1];
                    }

                    if ((rtb_Gain1 -
                         codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                        check - (rtb_Switch -
                                 codegenReal2Mission_DW.DelayPose_PreviousInput
                                 [1]) * b_shi > 0.0) {
                      codegenReal2Mission_DW.obj_a.TurnDirectionInternal = 1.0;
                    } else {
                      codegenReal2Mission_DW.obj_a.TurnDirectionInternal = -1.0;
                    }

                    codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag = false;
                    break;
                  }
                }
              }

              if (guard2) {
                rtb_Switch_fe = codegenReal2Mission_norm(distToCenter_tmp);
                rtb_Gain1 = rtb_Gain1 / rtb_Switch_fe * b_shi + fracSecs;
                rtb_Switch = rtb_Down2Up_e / rtb_Switch_fe * b_shi + rtb_Abs1;

                // Merge: '<S14>/ Merge '
                codegenReal2Mission_B.thisTaskStatus =
                  codegenReal2Mission_DW.obj_a.NumCircles;
              }

              rtb_ReshapeRowVec[2] = ct[2];

              // BusCreator: '<S19>/GuidanceCMDBusCreator' incorporates:
              //   DataTypeConversion: '<S19>/Param2'

              codegenReal2Mission_B.GuidanceCmds.HeadingAngle = rt_atan2d_snf
                (rtb_Switch - codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                 rtb_Gain1 - codegenReal2Mission_DW.DelayPose_PreviousInput[0]);
            }

            // BusCreator: '<S19>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S19>/Param3'
            //   Gain: '<S19>/Down2Height'
            //   MATLABSystem: '<S19>/Orbit Follower'

            codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
            codegenReal2Mission_B.GuidanceCmds.AirSpeed =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Bias: '<S19>/ClockwiseRotation'
            //   Constant: '<S19>/InitialFlightPathAngle'
            //   Constant: '<S19>/InitialRollAngle'
            //   Constant: '<S19>/InitialRollAngleRate'
            //   DataStoreRead: '<S19>/AltitudeGCS'
            //   DataTypeConversion: '<S19>/Param1'
            //   DataTypeConversion: '<S19>/Param3'
            //   Gain: '<S19>/inverse'
            //   Product: '<S19>/EastDis'
            //   Product: '<S19>/NorthDis'
            //   Reshape: '<S19>/Reshape'
            //   Sum: '<S19>/SumInitEast'
            //   Sum: '<S19>/SumInitNorth'
            //   Sum: '<S46>/Sum'
            //   Trigonometry: '<S19>/Cos'
            //   Trigonometry: '<S19>/Sin'

            codegenReal2Mission_B.InitialState[0] = std::cos(second) *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1 +
              fracSecs;
            codegenReal2Mission_B.InitialState[1] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1 * std::
              sin(second) + rtb_Abs1;
            codegenReal2Mission_B.InitialState[2] =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
              -AltitudeGCS;
            codegenReal2Mission_B.InitialState[3] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
            codegenReal2Mission_B.InitialState[4] = second + 1.5707963267948966;
            codegenReal2Mission_B.InitialState[5] = 0.0;
            codegenReal2Mission_B.InitialState[6] = 0.0;
            codegenReal2Mission_B.InitialState[7] = 0.0;
          }
          break;

         case codegenReal2Mission_IN_RunWayNav:
          // Switch: '<S85>/Switch' incorporates:
          //   Abs: '<S85>/Abs'
          //   Bias: '<S85>/Bias'
          //   Bias: '<S85>/Bias1'
          //   Constant: '<S85>/Constant2'
          //   Constant: '<S86>/Constant'
          //   DataStoreRead: '<S20>/LatitudeGCS'
          //   Math: '<S85>/Math Function1'
          //   RelationalOperator: '<S86>/Compare'

          if (std::abs(LatitudeGCS) > 180.0) {
            fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
          } else {
            fracSecs = LatitudeGCS;
          }

          // Abs: '<S82>/Abs1'
          rtb_Switch_fe = std::abs(fracSecs);

          // Switch: '<S82>/Switch' incorporates:
          //   Bias: '<S82>/Bias'
          //   Bias: '<S82>/Bias1'
          //   Constant: '<S73>/Constant'
          //   Constant: '<S73>/Constant1'
          //   Constant: '<S84>/Constant'
          //   Gain: '<S82>/Gain'
          //   Product: '<S82>/Divide1'
          //   RelationalOperator: '<S84>/Compare'
          //   Switch: '<S73>/Switch1'

          if (rtb_Switch_fe > 90.0) {
            // Signum: '<S82>/Sign1'
            if (fracSecs < 0.0) {
              fracSecs = -1.0;
            } else if (fracSecs > 0.0) {
              fracSecs = 1.0;
            } else if (fracSecs == 0.0) {
              fracSecs = 0.0;
            } else {
              fracSecs = (rtNaN);
            }

            fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
            imo = 180;
          } else {
            imo = 0;
          }

          // Sum: '<S73>/Sum' incorporates:
          //   DataStoreRead: '<S20>/LongitudeGCS'

          second = static_cast<real_T>(imo) + LongitudeGCS;

          // Sum: '<S70>/Sum1'
          rtb_Abs1 =
            codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
            fracSecs;

          // Switch: '<S79>/Switch' incorporates:
          //   Abs: '<S79>/Abs'
          //   Bias: '<S79>/Bias'
          //   Bias: '<S79>/Bias1'
          //   Constant: '<S79>/Constant2'
          //   Constant: '<S80>/Constant'
          //   Math: '<S79>/Math Function1'
          //   RelationalOperator: '<S80>/Compare'

          if (std::abs(rtb_Abs1) > 180.0) {
            rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
          }

          // Abs: '<S76>/Abs1'
          rtb_Switch_fe = std::abs(rtb_Abs1);

          // Switch: '<S76>/Switch' incorporates:
          //   Bias: '<S76>/Bias'
          //   Bias: '<S76>/Bias1'
          //   Constant: '<S72>/Constant'
          //   Constant: '<S72>/Constant1'
          //   Constant: '<S78>/Constant'
          //   Gain: '<S76>/Gain'
          //   Product: '<S76>/Divide1'
          //   RelationalOperator: '<S78>/Compare'
          //   Switch: '<S72>/Switch1'

          if (rtb_Switch_fe > 90.0) {
            // Signum: '<S76>/Sign1'
            if (rtb_Abs1 < 0.0) {
              rtb_Abs1 = -1.0;
            } else if (rtb_Abs1 > 0.0) {
              rtb_Abs1 = 1.0;
            } else if (rtb_Abs1 == 0.0) {
              rtb_Abs1 = 0.0;
            } else {
              rtb_Abs1 = (rtNaN);
            }

            rtb_Switch_fe = (-(rtb_Switch_fe + -90.0) + 90.0) * rtb_Abs1;
            imo = 180;
          } else {
            rtb_Switch_fe = rtb_Abs1;
            imo = 0;
          }

          // Switch: '<S83>/Switch' incorporates:
          //   Abs: '<S83>/Abs'
          //   Bias: '<S83>/Bias'
          //   Bias: '<S83>/Bias1'
          //   Constant: '<S83>/Constant2'
          //   Constant: '<S87>/Constant'
          //   Math: '<S83>/Math Function1'
          //   RelationalOperator: '<S87>/Compare'

          if (std::abs(second) > 180.0) {
            second = rt_modd_snf(second + 180.0, 360.0) + -180.0;
          }

          // Sum: '<S72>/Sum' incorporates:
          //   Sum: '<S70>/Sum1'

          temp = (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon
                  - second) + static_cast<real_T>(imo);

          // UnitConversion: '<S75>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          rtb_Abs1 = 0.017453292519943295 * rtb_Switch_fe;

          // UnitConversion: '<S90>/Unit Conversion'
          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          fracSecs *= 0.017453292519943295;

          // Trigonometry: '<S91>/Trigonometric Function1'
          second = std::sin(fracSecs);

          // Sum: '<S91>/Sum1' incorporates:
          //   Constant: '<S91>/Constant'
          //   Product: '<S91>/Product1'

          second = 1.0 - codegenReal2Mission_ConstB.sqrt_o *
            codegenReal2Mission_ConstB.sqrt_o * second * second;

          // Product: '<S89>/Product1' incorporates:
          //   Constant: '<S89>/Constant1'
          //   Sqrt: '<S89>/sqrt'

          rtb_Switch_fe = 6.378137E+6 / std::sqrt(second);

          // Product: '<S74>/dNorth' incorporates:
          //   Constant: '<S89>/Constant2'
          //   Product: '<S89>/Product3'
          //   Trigonometry: '<S89>/Trigonometric Function1'

          second = rtb_Abs1 / rt_atan2d_snf(1.0, rtb_Switch_fe *
            codegenReal2Mission_ConstB.Sum1_j / second);

          // Switch: '<S77>/Switch' incorporates:
          //   Abs: '<S77>/Abs'
          //   Bias: '<S77>/Bias'
          //   Bias: '<S77>/Bias1'
          //   Constant: '<S77>/Constant2'
          //   Constant: '<S81>/Constant'
          //   Math: '<S77>/Math Function1'
          //   RelationalOperator: '<S81>/Compare'

          // Unit Conversion - from: deg to: rad
          // Expression: output = (0.0174533*input) + (0)
          if (std::abs(temp) > 180.0) {
            temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
          }

          // Product: '<S74>/dEast' incorporates:
          //   Constant: '<S89>/Constant3'
          //   Product: '<S89>/Product4'
          //   Trigonometry: '<S89>/Trigonometric Function'
          //   Trigonometry: '<S89>/Trigonometric Function2'
          //   UnitConversion: '<S75>/Unit Conversion'

          rtb_Switch_fe = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe * std::cos
            (fracSecs)) * (0.017453292519943295 * temp);

          // Gain: '<S69>/Gain1'
          fracSecs = 0.017453292519943295 *
            codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

          // Outputs for Triggered SubSystem: '<S20>/WayPointGenerator' incorporates:
          //   TriggerPort: '<S71>/Trigger'

          zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                             &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE_o,
                             (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n));
          if (zcEvent != NO_ZCEVENT) {
            // Product: '<S71>/IndivRunwayRotAng' incorporates:
            //   DataTypeConversion: '<S20>/Param2'
            //   DataTypeConversion: '<S20>/Param5'
            //   Gain: '<S94>/Gain1'

            temp = 0.017453292519943295 *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param2 *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param5;

            // MATLAB Function: '<S71>/WayPointGenerator' incorporates:
            //   DataTypeConversion: '<S20>/Param3'

            codegenReal2Mission_uavDubinsConnection_uavDubinsConnection
              (&connectionObj);
            LUp[0] = 0.0;
            rtb_Abs1 = codegenReal2Mission_B.MemoryCurrentMission.params.Param3 /
              2.0;
            LUp[1] = rtb_Abs1;
            LUp[2] = 0.0;
            LUp[3] = 1.5707963267948966;
            LDp[0] = 0.0;
            rtb_Down_b = -static_cast<real_T>
              (codegenReal2Mission_B.MemoryCurrentMission.params.Param3) / 2.0;
            LDp[1] = rtb_Down_b;
            LDp[2] = 0.0;
            LDp[3] = 1.5707963267948966;
            codegenReal2Mission_uavDubinsConnection_connect(&connectionObj, LUp,
              LDp, codegenReal2Mission_B.pathSegObj.data,
              &codegenReal2Mission_B.pathSegObj.size, a__1_data,
              &SequenceID_prev);
            codegenReal2Mission_uavDubinsPathSegment_interpolate
              (codegenReal2Mission_B.pathSegObj.data[0].StartPose,
               codegenReal2Mission_B.pathSegObj.data[0].GoalPose,
               codegenReal2Mission_B.pathSegObj.data[0].FlightPathAngle,
               codegenReal2Mission_B.pathSegObj.data[0].AirSpeed,
               codegenReal2Mission_B.pathSegObj.data[0].MinTurningRadius,
               codegenReal2Mission_B.pathSegObj.data[0].HelixRadius,
               codegenReal2Mission_B.pathSegObj.data[0].MotionTypes,
               codegenReal2Mission_B.pathSegObj.data[0].MotionLengths,
               codegenReal2Mission_B.pathSegObj.data[0].Length,
               codegenReal2Mission_B.pathSegObj.data[0].Length / 2.0,
               midpose_data, midpose_size);
            rtb_startPose[0] = 0.0;
            b_shi = (codegenReal2Mission_B.pathSegObj.data[0].Length +
                     codegenReal2Mission_B.MemoryCurrentMission.params.Param3) /
              3.0 - codegenReal2Mission_B.pathSegObj.data[0].Length / 2.0;
            rtb_startPose[1] = rtb_Abs1 - b_shi;
            rtb_startPose[2] = 0.0;
            rtb_startPose[3] = 1.5707963267948966;
            ende[0] = 0.0;
            ende[1] = b_shi + rtb_Down_b;
            ende[2] = 0.0;
            ende[3] = 1.5707963267948966;
            SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            initWayPoint->size[0] = 1;
            initWayPoint->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator' incorporates:
            //   Constant: '<S71>/Three'
            //   DataTypeConversion: '<S71>/Cast To Double'
            //   Math: '<S71>/ModRunWayPose'

            initWayPoint->data[0] = 0.0;
            initWayPoint->data[1] = 0.0;
            initWayPoint->data[2] = 0.0;
            switch (static_cast<int32_T>(rt_modd_snf(static_cast<real_T>
                      (codegenReal2Mission_B.MemoryCurrentMission.FormationPos),
                      3.0))) {
             case 0:
              codegenReal2Mission_genSegWP(&connectionObj, rtb_startPose, LUp,
                100.0, segWayPoints);
              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
              initWayPoint->size[0] = segWayPoints->size[0] + 1;
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);
              b_nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + initWayPoint->size[0] *
                                      imo) + 1] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }
              break;

             case 1:
              rtb_startPose[0] = midpose_data[0];
              rtb_startPose[1] = midpose_data[midpose_size[0]];
              rtb_startPose[2] = midpose_data[midpose_size[0] << 1];
              rtb_startPose[3] = midpose_data[midpose_size[0] * 3];
              codegenReal2Mission_genSegWP(&connectionObj, &midpose_data[0], LDp,
                100.0, segWayPoints);
              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
              initWayPoint->size[0] = segWayPoints->size[0] + 1;
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);
              b_nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + initWayPoint->size[0] *
                                      imo) + 1] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }
              break;

             case 2:
              rtb_startPose[0] = 0.0;
              rtb_startPose[1] = ende[1];
              rtb_startPose[2] = 0.0;
              rtb_startPose[3] = 1.5707963267948966;
              codegenReal2Mission_genSegWP(&connectionObj, ende, LUp, 100.0,
                segWayPoints);
              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
              initWayPoint->size[0] = segWayPoints->size[0] + 1;
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);
              b_nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + initWayPoint->size[0] *
                                      imo) + 1] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }
              break;

             default:
              rtb_startPose[0] = 0.0;
              rtb_startPose[1] = 0.0;
              rtb_startPose[2] = 0.0;
              rtb_startPose[3] = 0.0;
              break;
            }

            codegenReal2Mission_genSegWP(&connectionObj, LUp, LDp, 100.0,
              segWayPoints);
            SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            dummyWayPoint->size[0] = segWayPoints->size[0] + 1;
            dummyWayPoint->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            b_nrows = segWayPoints->size[0];
            for (imo = 0; imo < 3; imo++) {
              dummyWayPoint->data[dummyWayPoint->size[0] * imo] = 0.0;
              for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                   SequenceID_prev++) {
                dummyWayPoint->data[(SequenceID_prev + dummyWayPoint->size[0] *
                                     imo) + 1] = segWayPoints->
                  data[SequenceID_prev + segWayPoints->size[0] * imo];
              }
            }

            codegenReal2Mission_genSegWP(&connectionObj, LDp, LUp, 100.0,
              segWayPoints);
            SequenceID_prev = dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
              segWayPoints->size[0];
            dummyWayPoint_0->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            b_nrows = dummyWayPoint->size[0];
            nrows = segWayPoints->size[0];
            for (imo = 0; imo < 3; imo++) {
              for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                   SequenceID_prev++) {
                dummyWayPoint_0->data[SequenceID_prev + dummyWayPoint_0->size[0]
                  * imo] = dummyWayPoint->data[SequenceID_prev +
                  dummyWayPoint->size[0] * imo];
              }

              for (SequenceID_prev = 0; SequenceID_prev < nrows; SequenceID_prev
                   ++) {
                dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->size[0])
                  + dummyWayPoint_0->size[0] * imo] = segWayPoints->
                  data[SequenceID_prev + segWayPoints->size[0] * imo];
              }
            }

            SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
            dummyWayPoint->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            b_nrows = dummyWayPoint_0->size[0] * 3;
            for (imo = 0; imo < b_nrows; imo++) {
              dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
            }

            nrowx = dummyWayPoint->size[0] - 2;
            nrows = dummyWayPoint->size[0] - 1;
            for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
              dummyWayPoint->data[b_nrows] = dummyWayPoint->data[b_nrows + 1];
            }

            for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
              dummyWayPoint->data[b_nrows + dummyWayPoint->size[0]] =
                dummyWayPoint->data[(b_nrows + dummyWayPoint->size[0]) + 1];
            }

            for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
              dummyWayPoint->data[b_nrows + (dummyWayPoint->size[0] << 1)] =
                dummyWayPoint->data[(b_nrows + (dummyWayPoint->size[0] << 1)) +
                1];
            }

            if (1 > nrows) {
              nrowx = -1;
              imo = -1;
            } else {
              imo = nrowx;
            }

            b_nrows = imo + 1;
            SequenceID_prev = dummyWayPoint_0->size[0] * dummyWayPoint_0->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            dummyWayPoint_0->size[0] = nrowx + 1;
            dummyWayPoint_0->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            for (imo = 0; imo < 3; imo++) {
              for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                   SequenceID_prev++) {
                dummyWayPoint_0->data[SequenceID_prev + dummyWayPoint_0->size[0]
                  * imo] = dummyWayPoint->data[SequenceID_prev +
                  dummyWayPoint->size[0] * imo];
              }
            }

            codegenReal2Mission_repmat(dummyWayPoint_0, std::ceil(10240.0 /
              static_cast<real_T>(nrowx + 1)), dummyWayPoint);
            if (2 > initWayPoint->size[0]) {
              k = -1;
              b = -1;
            } else {
              k = 0;
              b = initWayPoint->size[0] - 1;
            }

            // Bias: '<S71>/Bias' incorporates:
            //   Sum: '<S71>/Sum'

            codegenReal2Mission_B.Bias = ((fracSecs + temp) + rtb_startPose[3])
              + -1.5707963267948966;

            // Gain: '<S71>/InterLayerDis' incorporates:
            //   Constant: '<S71>/Three'
            //   DataTypeConversion: '<S20>/Param5'
            //   Math: '<S71>/ModRunWayLayer'

            rtb_Abs1 = 15.0 * rt_modd_snf(static_cast<real_T>
              (codegenReal2Mission_B.MemoryCurrentMission.params.Param5), 3.0);

            // Reshape: '<S71>/Reshape' incorporates:
            //   Constant: '<S71>/Zero'
            //   DataTypeConversion: '<S20>/Param1'

            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = 0.0;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
            rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = rtb_Abs1;

            // Reshape: '<S71>/ReshapeRowVec' incorporates:
            //   DataStoreRead: '<S20>/AltitudeGCS'
            //   Gain: '<S20>/inverse'
            //   Product: '<S74>/x*cos'
            //   Product: '<S74>/x*sin'
            //   Product: '<S74>/y*cos'
            //   Product: '<S74>/y*sin'
            //   Reshape: '<S71>/ReshapeRowVecStartpose'
            //   Sum: '<S70>/Sum'
            //   Sum: '<S74>/Sum2'
            //   Sum: '<S74>/Sum3'
            //   UnaryMinus: '<S70>/Ze2height'

            rtb_ReshapeRowVec[0] = rtb_Switch_fe * 0.0 + second;
            rtb_ReshapeRowVec[1] = rtb_Switch_fe - second * 0.0;
            rtb_ReshapeRowVec[2] =
              -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
                -AltitudeGCS);

            // MATLABSystem: '<S71>/RotateATMissionHdg' incorporates:
            //   SignalConversion generated from: '<S71>/RotateATMissionHdg'

            ct[0] = std::cos(fracSecs);
            turnVector[0] = std::sin(fracSecs);
            out[0] = ct[0];
            out[3] = 0.0 * ct[0] - turnVector[0];
            out[6] = 0.0 * ct[0] + turnVector[0] * 0.0;
            out[1] = turnVector[0];
            out[4] = 0.0 * turnVector[0] + ct[0];
            out[7] = 0.0 * turnVector[0] - ct[0] * 0.0;
            out[2] = -0.0;
            out[5] = 0.0;
            out[8] = 1.0;

            // SignalConversion generated from: '<S71>/RotateATRunWayHdg' incorporates:
            //   Constant: '<S71>/Zero'

            turnVector[0] = temp;
            turnVector[1] = 0.0;
            turnVector[2] = 0.0;

            // MATLABSystem: '<S71>/RotateATRunWayHdg' incorporates:
            //   SignalConversion generated from: '<S71>/RotateATRunWayHdg'

            ct[0] = temp;
            ct[1] = 0.0;
            ct[2] = 0.0;

            // MATLAB Function: '<S71>/WayPointGenerator'
            b_nrows = b - k;
            SequenceID_prev = segWayPoints->size[0] * segWayPoints->size[1];

            // MATLAB Function: '<S71>/WayPointGenerator'
            segWayPoints->size[0] = b_nrows + dummyWayPoint->size[0];
            segWayPoints->size[1] = 3;
            codegenReal2Mission_emxEnsureCapacity_real_T(segWayPoints,
              SequenceID_prev);

            // MATLAB Function: '<S71>/WayPointGenerator'
            nrows = dummyWayPoint->size[0];
            for (nrowx = 0; nrowx < 3; nrowx++) {
              // MATLAB Function: '<S71>/minus' incorporates:
              //   Reshape: '<S71>/Reshape'

              SequenceID_prev = nrowx * 10240;
              for (imo = 0; imo < 10240; imo++) {
                codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[nrowx];
              }

              // MATLAB Function: '<S71>/WayPointGenerator'
              for (imo = 0; imo < b_nrows; imo++) {
                segWayPoints->data[imo + segWayPoints->size[0] * nrowx] =
                  initWayPoint->data[((k + imo) + initWayPoint->size[0] * nrowx)
                  + 1];
              }

              for (imo = 0; imo < nrows; imo++) {
                segWayPoints->data[((imo + b) - k) + segWayPoints->size[0] *
                  nrowx] = dummyWayPoint->data[imo + dummyWayPoint->size[0] *
                  nrowx];
              }

              // MATLAB Function: '<S71>/minus' incorporates:
              //   MATLAB Function: '<S71>/WayPointGenerator'

              for (imo = 0; imo < 10240; imo++) {
                initWayPoint_tmp = 10240 * nrowx + imo;
                codegenReal2Mission_B.rtb_WayPoint_m[initWayPoint_tmp] =
                  segWayPoints->data[imo + segWayPoints->size[0] * nrowx] -
                  codegenReal2Mission_B.WayPoint[initWayPoint_tmp];
              }

              ct[nrowx] = std::cos(ct[nrowx]);
              turnVector[nrowx] = std::sin(turnVector[nrowx]);
            }

            // MATLABSystem: '<S71>/RotateATRunWayHdg'
            out_0[0] = ct[0] * ct[1];
            rtb_Switch_fe = turnVector[1] * turnVector[2];
            out_0[3] = rtb_Switch_fe * ct[0] - turnVector[0] * ct[2];
            second = turnVector[1] * ct[2];
            out_0[6] = second * ct[0] + turnVector[0] * turnVector[2];
            out_0[1] = turnVector[0] * ct[1];
            out_0[4] = rtb_Switch_fe * turnVector[0] + ct[0] * ct[2];
            out_0[7] = second * turnVector[0] - ct[0] * turnVector[2];
            out_0[2] = -turnVector[1];
            out_0[5] = ct[1] * turnVector[2];
            out_0[8] = ct[1] * ct[2];
            for (imo = 0; imo < 10240; imo++) {
              // Product: '<S71>/RotateRunway' incorporates:
              //   MATLABSystem: '<S71>/RotateATRunWayHdg'

              for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev++)
              {
                initWayPoint_tmp = imo + 10240 * SequenceID_prev;
                codegenReal2Mission_B.WayPoint[initWayPoint_tmp] = 0.0;
                codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                  SequenceID_prev] * codegenReal2Mission_B.rtb_WayPoint_m[imo];
                codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                  SequenceID_prev + 1] *
                  codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                  SequenceID_prev + 2] *
                  codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
              }

              // Product: '<S71>/RotateIndivWayPoint' incorporates:
              //   MATLABSystem: '<S71>/RotateATMissionHdg'

              for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev++)
              {
                b_nrows = imo + 10240 * SequenceID_prev;
                codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                  SequenceID_prev] * codegenReal2Mission_B.WayPoint[imo];
                codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                  SequenceID_prev + 1] * codegenReal2Mission_B.WayPoint[imo +
                  10240];
                codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                  SequenceID_prev + 2] * codegenReal2Mission_B.WayPoint[imo +
                  20480];
              }
            }

            // Sum: '<S71>/BiasStartPose' incorporates:
            //   DataTypeConversion: '<S20>/Param1'

            rtb_Switch_fe = rtb_startPose[0];
            second = rtb_startPose[1] -
              codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
            rtb_Abs1 = rtb_startPose[2] - rtb_Abs1;

            // Product: '<S71>/RotateRunwayStartpose' incorporates:
            //   MATLABSystem: '<S71>/RotateATRunWayHdg'

            for (imo = 0; imo < 3; imo++) {
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[imo] = out_0[3 *
                imo + 2] * rtb_Abs1 + (out_0[3 * imo + 1] * second + out_0[3 *
                imo] * rtb_Switch_fe);
            }

            for (b_nrows = 0; b_nrows < 3; b_nrows++) {
              // MATLAB Function: '<S71>/biasNED' incorporates:
              //   Reshape: '<S71>/ReshapeRowVec'

              SequenceID_prev = b_nrows * 10240;
              for (imo = 0; imo < 10240; imo++) {
                codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                  rtb_ReshapeRowVec[b_nrows];
              }

              ct[b_nrows] = out[3 * b_nrows + 2] *
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] + (out[3 *
                b_nrows + 1] *
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] + out[3 *
                b_nrows] * rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
            }

            // MATLAB Function: '<S71>/biasNED' incorporates:
            //   MATLABSystem: '<S71>/RotateATMissionHdg'
            //   Product: '<S71>/RotateIndivWayPoint'
            //   Product: '<S71>/RotateIndivWayPointStartpose'

            for (imo = 0; imo < 10240; imo++) {
              codegenReal2Mission_B.nedWayPoint_m[imo] =
                codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                codegenReal2Mission_B.WayPoint[imo];
              codegenReal2Mission_B.nedWayPoint_m[imo + 10240] =
                codegenReal2Mission_B.WayPoint[imo + 10240] +
                codegenReal2Mission_B.RotateIndivWayPoint[imo];
              codegenReal2Mission_B.nedWayPoint_m[imo + 20480] =
                codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                codegenReal2Mission_B.WayPoint[imo + 20480];
            }

            // MATLAB Function: '<S71>/biasNEDstartpose' incorporates:
            //   Product: '<S71>/RotateIndivWayPointStartpose'
            //   Reshape: '<S71>/ReshapeRowVecStartpose'

            codegenReal2Mission_B.nedWayPoint_d[0] = rtb_ReshapeRowVec[0] + ct[1];
            codegenReal2Mission_B.nedWayPoint_d[1] = ct[0] + rtb_ReshapeRowVec[1];
            codegenReal2Mission_B.nedWayPoint_d[2] = ct[2] + rtb_ReshapeRowVec[2];
          }

          // End of Outputs for SubSystem: '<S20>/WayPointGenerator'

          // BusCreator: '<S20>/GuidanceCMDBusCreator' incorporates:
          //   Constant: '<S20>/LookAheadDis'
          //   MATLAB Function: '<S71>/WayPointGenerator'
          //   MATLABSystem: '<S20>/Waypoint Follower'
          //   Memory: '<S20>/MemoryTriggerWP'
          //   Memory: '<S2>/DelayPose'

          codegenReal2Mission_WaypointFollowerBase_stepInternal
            (&codegenReal2Mission_DW.obj_e,
             codegenReal2Mission_DW.DelayPose_PreviousInput,
             codegenReal2Mission_B.nedWayPoint_m, 200.0, rtb_ReshapeRowVec,
             &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
             &lookaheadFlag, &rtb_Switch, &status_0);

          // Merge: '<S14>/ Merge ' incorporates:
          //   DataTypeConversion: '<S20>/Cast To Double'
          //   MATLABSystem: '<S20>/Waypoint Follower'

          codegenReal2Mission_B.thisTaskStatus = status_0;

          // BusCreator: '<S20>/GuidanceCMDBusCreator' incorporates:
          //   DataTypeConversion: '<S20>/Param4'
          //   Gain: '<S20>/Down2Height'
          //   MATLABSystem: '<S20>/Waypoint Follower'

          codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
          codegenReal2Mission_B.GuidanceCmds.AirSpeed =
            codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

          // Merge: '<S14>/ Merge 3' incorporates:
          //   Constant: '<S20>/InitialFlightPathAngle'
          //   Constant: '<S20>/InitialRollAngle'
          //   Constant: '<S20>/InitialRollAngleRate'
          //   DataTypeConversion: '<S20>/Param4'
          //   Gain: '<S20>/Down2Up'
          //   Reshape: '<S20>/Reshape'

          codegenReal2Mission_B.InitialState[0] =
            codegenReal2Mission_B.nedWayPoint_d[0];
          codegenReal2Mission_B.InitialState[1] =
            codegenReal2Mission_B.nedWayPoint_d[1];
          codegenReal2Mission_B.InitialState[2] =
            -codegenReal2Mission_B.nedWayPoint_d[2];
          codegenReal2Mission_B.InitialState[3] =
            codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
          codegenReal2Mission_B.InitialState[4] = codegenReal2Mission_B.Bias;
          codegenReal2Mission_B.InitialState[5] = 0.0;
          codegenReal2Mission_B.InitialState[6] = 0.0;
          codegenReal2Mission_B.InitialState[7] = 0.0;

          // Merge: '<S14>/ Merge 2' incorporates:
          //   Memory: '<S20>/MemoryStopTrigger1'
          //   Memory: '<S20>/MemoryTriggerWP'
          //   Sum: '<S20>/Sum'

          codegenReal2Mission_B.ResetTrigger =
            codegenReal2Mission_DW.MemoryStopTrigger1_PreviousInput +
            codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n;

          // Update for Memory: '<S20>/MemoryTriggerWP' incorporates:
          //   Constant: '<S20>/TirggerWayPointGen'

          codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n = 1.0;

          // Update for Memory: '<S20>/MemoryStopTrigger1' incorporates:
          //   Memory: '<S20>/MemoryStopTrigger2'

          codegenReal2Mission_DW.MemoryStopTrigger1_PreviousInput =
            codegenReal2Mission_DW.MemoryStopTrigger2_PreviousInput;

          // Update for Memory: '<S20>/MemoryStopTrigger2' incorporates:
          //   Constant: '<S20>/StopTrigger'

          codegenReal2Mission_DW.MemoryStopTrigger2_PreviousInput = -1.0;
          break;

         case codegenReal2Mission_IN_WaitToStart:
          if (rtb_ReceiveCurrentMission_o1) {
            if ((codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 1) ||
                (codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 11))
            {
              codegenReal2Mission_DW.is_GuidanceLogic =
                codegenReal2Mission_IN_OrbitFollower;

              // Merge: '<S14>/ Merge 2'
              codegenReal2Mission_B.ResetTrigger = 1.0;
              if (codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 1) {
                codegenReal2Mission_DW.is_OrbitFollower =
                  codegenReal2Mission_IN_CirclingNav;

                // Product: '<S19>/Map2Radian' incorporates:
                //   Bias: '<S19>/Bias'
                //   Constant: '<S19>/two_pi'
                //   DataTypeConversion: '<S19>/CastToDouble'
                //   Gain: '<S19>/HalveMissionUAV'
                //   Product: '<S19>/Divide'
                //   Sum: '<S19>/Minus'

                second = (static_cast<real_T>
                          (codegenReal2Mission_B.MemoryCurrentMission.FormationPos)
                          - static_cast<real_T>
                          (codegenReal2Mission_B.MemoryCurrentMission.numUAV + 1)
                          * 0.5) * (6.2831853071795862 / static_cast<real_T>
                                    (codegenReal2Mission_B.MemoryCurrentMission.numUAV));

                // Switch: '<S60>/Switch' incorporates:
                //   Abs: '<S60>/Abs'
                //   Bias: '<S60>/Bias'
                //   Bias: '<S60>/Bias1'
                //   Constant: '<S60>/Constant2'
                //   Constant: '<S61>/Constant'
                //   DataStoreRead: '<S19>/LatitudeGCS'
                //   Math: '<S60>/Math Function1'
                //   RelationalOperator: '<S61>/Compare'

                if (std::abs(LatitudeGCS) > 180.0) {
                  fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
                } else {
                  fracSecs = LatitudeGCS;
                }

                // Abs: '<S57>/Abs1'
                rtb_Switch_fe = std::abs(fracSecs);

                // Switch: '<S57>/Switch' incorporates:
                //   Bias: '<S57>/Bias'
                //   Bias: '<S57>/Bias1'
                //   Constant: '<S48>/Constant'
                //   Constant: '<S48>/Constant1'
                //   Constant: '<S59>/Constant'
                //   Gain: '<S57>/Gain'
                //   Product: '<S57>/Divide1'
                //   RelationalOperator: '<S59>/Compare'
                //   Switch: '<S48>/Switch1'

                if (rtb_Switch_fe > 90.0) {
                  // Signum: '<S57>/Sign1'
                  if (fracSecs < 0.0) {
                    fracSecs = -1.0;
                  } else if (fracSecs > 0.0) {
                    fracSecs = 1.0;
                  } else if (fracSecs == 0.0) {
                    fracSecs = 0.0;
                  } else {
                    fracSecs = (rtNaN);
                  }

                  fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
                  SequenceID_prev = 180;
                } else {
                  SequenceID_prev = 0;
                }

                // Sum: '<S48>/Sum' incorporates:
                //   DataStoreRead: '<S19>/LongitudeGCS'

                rtb_Switch_fe = static_cast<real_T>(SequenceID_prev) +
                  LongitudeGCS;

                // Sum: '<S46>/Sum1'
                rtb_Abs1 =
                  codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat
                  - fracSecs;

                // Switch: '<S54>/Switch' incorporates:
                //   Abs: '<S54>/Abs'
                //   Bias: '<S54>/Bias'
                //   Bias: '<S54>/Bias1'
                //   Constant: '<S54>/Constant2'
                //   Constant: '<S55>/Constant'
                //   Math: '<S54>/Math Function1'
                //   RelationalOperator: '<S55>/Compare'

                if (std::abs(rtb_Abs1) > 180.0) {
                  rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                // Abs: '<S51>/Abs1'
                temp = std::abs(rtb_Abs1);

                // Switch: '<S51>/Switch' incorporates:
                //   Bias: '<S51>/Bias'
                //   Bias: '<S51>/Bias1'
                //   Constant: '<S47>/Constant'
                //   Constant: '<S47>/Constant1'
                //   Constant: '<S53>/Constant'
                //   Gain: '<S51>/Gain'
                //   Product: '<S51>/Divide1'
                //   RelationalOperator: '<S53>/Compare'
                //   Switch: '<S47>/Switch1'

                if (temp > 90.0) {
                  // Signum: '<S51>/Sign1'
                  if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                  } else if (rtb_Abs1 > 0.0) {
                    rtb_Abs1 = 1.0;
                  } else if (rtb_Abs1 == 0.0) {
                    rtb_Abs1 = 0.0;
                  } else {
                    rtb_Abs1 = (rtNaN);
                  }

                  temp = (-(temp + -90.0) + 90.0) * rtb_Abs1;
                  SequenceID_prev = 180;
                } else {
                  temp = rtb_Abs1;
                  SequenceID_prev = 0;
                }

                // Switch: '<S58>/Switch' incorporates:
                //   Abs: '<S58>/Abs'
                //   Bias: '<S58>/Bias'
                //   Bias: '<S58>/Bias1'
                //   Constant: '<S58>/Constant2'
                //   Constant: '<S62>/Constant'
                //   Math: '<S58>/Math Function1'
                //   RelationalOperator: '<S62>/Compare'

                if (std::abs(rtb_Switch_fe) > 180.0) {
                  rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) +
                    -180.0;
                }

                // Sum: '<S47>/Sum' incorporates:
                //   Sum: '<S46>/Sum1'

                rtb_Switch_fe =
                  (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon
                   - rtb_Switch_fe) + static_cast<real_T>(SequenceID_prev);

                // UnitConversion: '<S50>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Abs1 = 0.017453292519943295 * temp;

                // UnitConversion: '<S65>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                fracSecs *= 0.017453292519943295;

                // Trigonometry: '<S66>/Trigonometric Function1'
                rtb_Down_b = std::sin(fracSecs);

                // Sum: '<S66>/Sum1' incorporates:
                //   Constant: '<S66>/Constant'
                //   Product: '<S66>/Product1'

                rtb_Down_b = 1.0 - codegenReal2Mission_ConstB.sqrt_g *
                  codegenReal2Mission_ConstB.sqrt_g * rtb_Down_b * rtb_Down_b;

                // Product: '<S64>/Product1' incorporates:
                //   Constant: '<S64>/Constant1'
                //   Sqrt: '<S64>/sqrt'

                temp = 6.378137E+6 / std::sqrt(rtb_Down_b);

                // Product: '<S49>/dNorth' incorporates:
                //   Constant: '<S64>/Constant2'
                //   Product: '<S64>/Product3'
                //   Trigonometry: '<S64>/Trigonometric Function1'

                rtb_Down_b = rtb_Abs1 / rt_atan2d_snf(1.0, temp *
                  codegenReal2Mission_ConstB.Sum1_fi / rtb_Down_b);

                // Switch: '<S52>/Switch' incorporates:
                //   Abs: '<S52>/Abs'
                //   Bias: '<S52>/Bias'
                //   Bias: '<S52>/Bias1'
                //   Constant: '<S52>/Constant2'
                //   Constant: '<S56>/Constant'
                //   Math: '<S52>/Math Function1'
                //   RelationalOperator: '<S56>/Compare'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                if (std::abs(rtb_Switch_fe) > 180.0) {
                  rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) +
                    -180.0;
                }

                // Product: '<S49>/dEast' incorporates:
                //   Constant: '<S64>/Constant3'
                //   Product: '<S64>/Product4'
                //   Trigonometry: '<S64>/Trigonometric Function'
                //   Trigonometry: '<S64>/Trigonometric Function2'
                //   UnitConversion: '<S50>/Unit Conversion'

                temp = 1.0 / rt_atan2d_snf(1.0, temp * std::cos(fracSecs)) *
                  (0.017453292519943295 * rtb_Switch_fe);

                // Sum: '<S49>/Sum2' incorporates:
                //   Product: '<S49>/x*cos'
                //   Product: '<S49>/y*sin'

                fracSecs = temp * 0.0 + rtb_Down_b;

                // Sum: '<S49>/Sum3' incorporates:
                //   Product: '<S49>/x*sin'
                //   Product: '<S49>/y*cos'

                rtb_Abs1 = temp - rtb_Down_b * 0.0;

                // SignalConversion generated from: '<S19>/Orbit Follower' incorporates:
                //   DataStoreRead: '<S19>/AltitudeGCS'
                //   Gain: '<S19>/inverse'
                //   Sum: '<S46>/Sum'
                //   UnaryMinus: '<S46>/Ze2height'

                ct[0] = fracSecs;
                ct[1] = rtb_Abs1;
                ct[2] =
                  -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt
                    + -AltitudeGCS);

                // MATLABSystem: '<S19>/Orbit Follower' incorporates:
                //   DataTypeConversion: '<S19>/Param1'
                //   DataTypeConversion: '<S19>/Param2'
                //   Memory: '<S2>/DelayPose'
                //   SignalConversion generated from: '<S19>/Orbit Follower'

                b_shi = codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                codegenReal2Mission_DW.obj_a.OrbitRadiusFlag = 0U;
                if (codegenReal2Mission_B.MemoryCurrentMission.params.Param1 <=
                    220.0F) {
                  b_shi = 220.0;
                  codegenReal2Mission_DW.obj_a.OrbitRadiusFlag = 1U;
                }

                codegenReal2Mission_DW.obj_a.LookaheadDistFlag = 0U;
                codegenReal2Mission_DW.obj_a.LookaheadDistFlag = 1U;
                rtb_Gain1 = codegenReal2Mission_DW.DelayPose_PreviousInput[0] -
                  fracSecs;
                rtb_Sum1_0[0] = rtb_Gain1;
                rtb_Down2Up_e = codegenReal2Mission_DW.DelayPose_PreviousInput[1]
                  - rtb_Abs1;
                rtb_Sum1_0[1] = rtb_Down2Up_e;
                if (codegenReal2Mission_norm(rtb_Sum1_0) < 2.47032822920623E-323)
                {
                  rtb_ReshapeRowVec[2] = ct[2];

                  // BusCreator: '<S19>/GuidanceCMDBusCreator'
                  codegenReal2Mission_B.GuidanceCmds.HeadingAngle =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[3];

                  // Merge: '<S14>/ Merge '
                  codegenReal2Mission_B.thisTaskStatus =
                    codegenReal2Mission_DW.obj_a.NumCircles;
                } else {
                  p = false;
                  p_0 = true;
                  nrowx = 0;
                  exitg1 = false;
                  while ((!exitg1) && (nrowx < 3)) {
                    if ((codegenReal2Mission_DW.obj_a.OrbitCenterInternal[nrowx]
                         == ct[nrowx]) || (std::isnan
                                           (codegenReal2Mission_DW.obj_a.OrbitCenterInternal
                                            [nrowx]) && std::isnan(ct[nrowx])))
                    {
                      nrowx++;
                    } else {
                      p_0 = false;
                      exitg1 = true;
                    }
                  }

                  if (p_0) {
                    p = true;
                  }

                  guard2 = false;
                  if (!p) {
                    guard2 = true;
                  } else {
                    p = false;
                    if ((codegenReal2Mission_DW.obj_a.OrbitRadiusInternal ==
                         b_shi) || (std::isnan
                                    (codegenReal2Mission_DW.obj_a.OrbitRadiusInternal)
                                    && std::isnan(b_shi))) {
                      p = true;
                    }

                    if (!p) {
                      guard2 = true;
                    }
                  }

                  if (guard2) {
                    codegenReal2Mission_DW.obj_a.NumCircles = 0.0;
                    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[0] =
                      fracSecs;
                    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[1] =
                      rtb_Abs1;
                    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[2] = ct[2];
                    codegenReal2Mission_DW.obj_a.OrbitRadiusInternal = b_shi;
                    codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag = true;
                  }

                  if (35.0 >= b_shi) {
                    codegenReal2Mission_DW.obj_a.LookaheadDistance = 0.9 * b_shi;
                  } else {
                    codegenReal2Mission_DW.obj_a.LookaheadDistance = 35.0;
                  }

                  distToCenter_tmp[0] = rtb_Gain1;
                  distToCenter_tmp[1] = rtb_Down2Up_e;
                  rtb_Switch_fe = std::sqrt(rtb_Down2Up_e * rtb_Down2Up_e +
                    rtb_Gain1 * rtb_Gain1);
                  check = b_shi + codegenReal2Mission_DW.obj_a.LookaheadDistance;
                  rtb_Switch = std::abs(check);
                  p = !std::isinf(rtb_Switch);
                  p_0 = !std::isnan(rtb_Switch);
                  if (p && p_0) {
                    if (rtb_Switch <= 2.2250738585072014E-308) {
                      rtb_Down_b = 4.94065645841247E-324;
                    } else {
                      frexp(rtb_Switch, &imo);
                      rtb_Down_b = std::ldexp(1.0, imo - 53);
                    }
                  } else {
                    rtb_Down_b = (rtNaN);
                  }

                  guard2 = false;
                  if (rtb_Switch_fe >= check - 5.0 * rtb_Down_b) {
                    guard2 = true;
                  } else {
                    if (p && p_0) {
                      if (rtb_Switch <= 2.2250738585072014E-308) {
                        rtb_Down_b = 4.94065645841247E-324;
                      } else {
                        frexp(rtb_Switch, &b_nrows);
                        rtb_Down_b = std::ldexp(1.0, b_nrows - 53);
                      }
                    } else {
                      rtb_Down_b = (rtNaN);
                    }

                    if (rtb_Switch_fe <= (b_shi -
                                          codegenReal2Mission_DW.obj_a.LookaheadDistance)
                        + 5.0 * rtb_Down_b) {
                      guard2 = true;
                    } else {
                      if (codegenReal2Mission_DW.obj_a.StartFlag) {
                        codegenReal2Mission_DW.obj_a.PrevPosition[0] =
                          codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                        codegenReal2Mission_DW.obj_a.PrevPosition[1] =
                          codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                        codegenReal2Mission_DW.obj_a.PrevPosition[2] =
                          codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                        codegenReal2Mission_DW.obj_a.StartFlag = false;
                      }

                      rtb_Sum1_0[0] = rtb_Gain1;
                      rtb_Sum1_0[1] = rtb_Down2Up_e;
                      rtb_Down_b = codegenReal2Mission_norm(rtb_Sum1_0);
                      rtb_Switch =
                        codegenReal2Mission_DW.obj_a.LookaheadDistance *
                        codegenReal2Mission_DW.obj_a.LookaheadDistance;
                      rtb_Switch_fe = ((rtb_Switch - b_shi * b_shi) + rtb_Down_b
                                       * rtb_Down_b) / (2.0 * rtb_Down_b);
                      b_shi = fracSecs -
                        codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                      x2 = b_shi * rtb_Switch_fe / rtb_Down_b +
                        codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                      check = rtb_Abs1 -
                        codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                      rtb_Sum_j = check * rtb_Switch_fe / rtb_Down_b +
                        codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                      rtb_Switch = std::sqrt(rtb_Switch - rtb_Switch_fe *
                        rtb_Switch_fe);
                      rtb_Switch_fe = check * rtb_Switch / rtb_Down_b;
                      distToCenter_tmp[0] = x2 - rtb_Switch_fe;
                      distToCenter_tmp[1] = rtb_Switch_fe + x2;
                      rtb_Switch_fe = b_shi * rtb_Switch / rtb_Down_b;
                      rtb_Down_b = rtb_Switch_fe + rtb_Sum_j;
                      rtb_Switch = rtb_Sum_j - rtb_Switch_fe;
                      if ((codegenReal2Mission_B.MemoryCurrentMission.params.Param2
                           == 0.0F) &&
                          (!codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag))
                      {
                        rtb_Sum_j =
                          codegenReal2Mission_DW.obj_a.TurnDirectionInternal;
                      } else {
                        rtb_Sum_j =
                          codegenReal2Mission_B.MemoryCurrentMission.params.Param2;
                      }

                      turnVector[0] = codegenReal2Mission_DW.obj_a.PrevPosition
                        [0] - fracSecs;
                      turnVector[1] = codegenReal2Mission_DW.obj_a.PrevPosition
                        [1] - rtb_Abs1;
                      rtb_ReshapeRowVec[0] = turnVector[0];
                      rtb_ReshapeRowVec[1] = turnVector[1];
                      rtb_ReshapeRowVec[2] = 0.0;
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                        rtb_Gain1;
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                        rtb_Down2Up_e;
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                        0.0;
                      if (rtb_Sum_j < 0.0) {
                        rtb_ReshapeRowVec[0] = rtb_Gain1;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                          turnVector[0];
                        rtb_ReshapeRowVec[1] = rtb_Down2Up_e;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                          turnVector[1];
                        rtb_ReshapeRowVec[2] = 0.0;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                          0.0;
                        rtb_Sum_j = -1.0;
                      } else if (rtb_Sum_j > 0.0) {
                        rtb_Sum_j = 1.0;
                      } else if (rtb_Sum_j == 0.0) {
                        rtb_Sum_j = 0.0;
                      } else {
                        rtb_Sum_j = (rtNaN);
                      }

                      rtb_Switch_fe = codegenReal2Mission_norm_b
                        (rtb_ReshapeRowVec);
                      rtb_Down2Up_e = codegenReal2Mission_norm_b
                        (rtb_TmpSignalConversionAtRotateATMissionHdgInport1);
                      rtb_Gain1 = rtb_ReshapeRowVec[0] / rtb_Switch_fe;
                      x2 = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]
                        / rtb_Down2Up_e;
                      rtb_ReshapeRowVec_tmp = rtb_ReshapeRowVec[1] /
                        rtb_Switch_fe;
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] /
                        rtb_Down2Up_e;
                      codegenReal2Mission_DW.obj_a.PrevPosition[0] =
                        codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                      codegenReal2Mission_DW.obj_a.PrevPosition[1] =
                        codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                      codegenReal2Mission_DW.obj_a.PrevPosition[2] =
                        codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                      codegenReal2Mission_DW.obj_a.NumCircles += rt_atan2d_snf
                        (rtb_Gain1 *
                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp
                         - x2 * rtb_ReshapeRowVec_tmp, (rtb_Gain1 * x2 +
                          rtb_ReshapeRowVec_tmp *
                          rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp)
                         + 0.0 / rtb_Switch_fe * (0.0 / rtb_Down2Up_e)) / 2.0 /
                        3.1415926535897931;

                      // Merge: '<S14>/ Merge ' incorporates:
                      //   DataTypeConversion: '<S19>/Param2'

                      codegenReal2Mission_B.thisTaskStatus =
                        codegenReal2Mission_DW.obj_a.NumCircles;
                      switch (static_cast<int32_T>(rtb_Sum_j)) {
                       case 1:
                        if ((distToCenter_tmp[0] -
                             codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                            check - (rtb_Down_b -
                                     codegenReal2Mission_DW.DelayPose_PreviousInput
                                     [1]) * b_shi > 0.0) {
                          rtb_Gain1 = distToCenter_tmp[0];
                          rtb_Switch = rtb_Down_b;
                        } else {
                          rtb_Gain1 = distToCenter_tmp[1];
                        }
                        break;

                       case -1:
                        if ((distToCenter_tmp[0] -
                             codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                            check - (rtb_Down_b -
                                     codegenReal2Mission_DW.DelayPose_PreviousInput
                                     [1]) * b_shi < 0.0) {
                          rtb_Gain1 = distToCenter_tmp[0];
                          rtb_Switch = rtb_Down_b;
                        } else {
                          rtb_Gain1 = distToCenter_tmp[1];
                        }
                        break;

                       default:
                        if (std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                              (rtb_Down_b -
                               codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                               distToCenter_tmp[0] -
                               codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                              codegenReal2Mission_DW.DelayPose_PreviousInput[3]))
                            < std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                              (rtb_Switch -
                               codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                               distToCenter_tmp[1] -
                               codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                              codegenReal2Mission_DW.DelayPose_PreviousInput[3])))
                        {
                          rtb_Gain1 = distToCenter_tmp[0];
                          rtb_Switch = rtb_Down_b;
                        } else {
                          rtb_Gain1 = distToCenter_tmp[1];
                        }

                        if ((rtb_Gain1 -
                             codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                            check - (rtb_Switch -
                                     codegenReal2Mission_DW.DelayPose_PreviousInput
                                     [1]) * b_shi > 0.0) {
                          codegenReal2Mission_DW.obj_a.TurnDirectionInternal =
                            1.0;
                        } else {
                          codegenReal2Mission_DW.obj_a.TurnDirectionInternal =
                            -1.0;
                        }

                        codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag =
                          false;
                        break;
                      }
                    }
                  }

                  if (guard2) {
                    rtb_Switch_fe = codegenReal2Mission_norm(distToCenter_tmp);
                    rtb_Gain1 = rtb_Gain1 / rtb_Switch_fe * b_shi + fracSecs;
                    rtb_Switch = rtb_Down2Up_e / rtb_Switch_fe * b_shi +
                      rtb_Abs1;

                    // Merge: '<S14>/ Merge '
                    codegenReal2Mission_B.thisTaskStatus =
                      codegenReal2Mission_DW.obj_a.NumCircles;
                  }

                  rtb_ReshapeRowVec[2] = ct[2];

                  // BusCreator: '<S19>/GuidanceCMDBusCreator' incorporates:
                  //   DataTypeConversion: '<S19>/Param2'

                  codegenReal2Mission_B.GuidanceCmds.HeadingAngle =
                    rt_atan2d_snf(rtb_Switch -
                                  codegenReal2Mission_DW.DelayPose_PreviousInput[
                                  1], rtb_Gain1 -
                                  codegenReal2Mission_DW.DelayPose_PreviousInput[
                                  0]);
                }

                // BusCreator: '<S19>/GuidanceCMDBusCreator' incorporates:
                //   DataTypeConversion: '<S19>/Param3'
                //   Gain: '<S19>/Down2Height'
                //   MATLABSystem: '<S19>/Orbit Follower'

                codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
                codegenReal2Mission_B.GuidanceCmds.AirSpeed =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

                // Merge: '<S14>/ Merge 3' incorporates:
                //   Bias: '<S19>/ClockwiseRotation'
                //   Constant: '<S19>/InitialFlightPathAngle'
                //   Constant: '<S19>/InitialRollAngle'
                //   Constant: '<S19>/InitialRollAngleRate'
                //   DataStoreRead: '<S19>/AltitudeGCS'
                //   DataTypeConversion: '<S19>/Param1'
                //   DataTypeConversion: '<S19>/Param3'
                //   Gain: '<S19>/inverse'
                //   Product: '<S19>/EastDis'
                //   Product: '<S19>/NorthDis'
                //   Reshape: '<S19>/Reshape'
                //   Sum: '<S19>/SumInitEast'
                //   Sum: '<S19>/SumInitNorth'
                //   Sum: '<S46>/Sum'
                //   Trigonometry: '<S19>/Cos'
                //   Trigonometry: '<S19>/Sin'

                codegenReal2Mission_B.InitialState[0] = std::cos(second) *
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param1 +
                  fracSecs;
                codegenReal2Mission_B.InitialState[1] =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param1 * std::
                  sin(second) + rtb_Abs1;
                codegenReal2Mission_B.InitialState[2] =
                  codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt
                  + -AltitudeGCS;
                codegenReal2Mission_B.InitialState[3] =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
                codegenReal2Mission_B.InitialState[4] = second +
                  1.5707963267948966;
                codegenReal2Mission_B.InitialState[5] = 0.0;
                codegenReal2Mission_B.InitialState[6] = 0.0;
                codegenReal2Mission_B.InitialState[7] = 0.0;
              } else {
                codegenReal2Mission_DW.is_OrbitFollower =
                  codegenReal2Mission_IN_CircleDisplayNav;

                // Product: '<S18>/Divide' incorporates:
                //   DataTypeConversion: '<S18>/Param1'

                second =
                  codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat /
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param1;

                // Switch: '<S37>/Switch' incorporates:
                //   Abs: '<S37>/Abs'
                //   Bias: '<S37>/Bias'
                //   Bias: '<S37>/Bias1'
                //   Constant: '<S37>/Constant2'
                //   Constant: '<S38>/Constant'
                //   DataStoreRead: '<S18>/LatitudeGCS'
                //   Math: '<S37>/Math Function1'
                //   RelationalOperator: '<S38>/Compare'

                if (std::abs(LatitudeGCS) > 180.0) {
                  fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
                } else {
                  fracSecs = LatitudeGCS;
                }

                // Abs: '<S34>/Abs1'
                rtb_Switch_fe = std::abs(fracSecs);

                // Switch: '<S34>/Switch' incorporates:
                //   Bias: '<S34>/Bias'
                //   Bias: '<S34>/Bias1'
                //   Constant: '<S25>/Constant'
                //   Constant: '<S25>/Constant1'
                //   Constant: '<S36>/Constant'
                //   Gain: '<S34>/Gain'
                //   Product: '<S34>/Divide1'
                //   RelationalOperator: '<S36>/Compare'
                //   Switch: '<S25>/Switch1'

                if (rtb_Switch_fe > 90.0) {
                  // Signum: '<S34>/Sign1'
                  if (fracSecs < 0.0) {
                    fracSecs = -1.0;
                  } else if (fracSecs > 0.0) {
                    fracSecs = 1.0;
                  } else if (fracSecs == 0.0) {
                    fracSecs = 0.0;
                  } else {
                    fracSecs = (rtNaN);
                  }

                  fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
                  SequenceID_prev = 180;
                } else {
                  SequenceID_prev = 0;
                }

                // Sum: '<S25>/Sum' incorporates:
                //   DataStoreRead: '<S18>/LongitudeGCS'

                rtb_Switch_fe = static_cast<real_T>(SequenceID_prev) +
                  LongitudeGCS;

                // Sum: '<S23>/Sum1'
                rtb_Abs1 =
                  codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat
                  - fracSecs;

                // Switch: '<S31>/Switch' incorporates:
                //   Abs: '<S31>/Abs'
                //   Bias: '<S31>/Bias'
                //   Bias: '<S31>/Bias1'
                //   Constant: '<S31>/Constant2'
                //   Constant: '<S32>/Constant'
                //   Math: '<S31>/Math Function1'
                //   RelationalOperator: '<S32>/Compare'

                if (std::abs(rtb_Abs1) > 180.0) {
                  rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                // Abs: '<S28>/Abs1'
                temp = std::abs(rtb_Abs1);

                // Switch: '<S28>/Switch' incorporates:
                //   Bias: '<S28>/Bias'
                //   Bias: '<S28>/Bias1'
                //   Constant: '<S24>/Constant'
                //   Constant: '<S24>/Constant1'
                //   Constant: '<S30>/Constant'
                //   Gain: '<S28>/Gain'
                //   Product: '<S28>/Divide1'
                //   RelationalOperator: '<S30>/Compare'
                //   Switch: '<S24>/Switch1'

                if (temp > 90.0) {
                  // Signum: '<S28>/Sign1'
                  if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                  } else if (rtb_Abs1 > 0.0) {
                    rtb_Abs1 = 1.0;
                  } else if (rtb_Abs1 == 0.0) {
                    rtb_Abs1 = 0.0;
                  } else {
                    rtb_Abs1 = (rtNaN);
                  }

                  temp = (-(temp + -90.0) + 90.0) * rtb_Abs1;
                  SequenceID_prev = 180;
                } else {
                  temp = rtb_Abs1;
                  SequenceID_prev = 0;
                }

                // Switch: '<S35>/Switch' incorporates:
                //   Abs: '<S35>/Abs'
                //   Bias: '<S35>/Bias'
                //   Bias: '<S35>/Bias1'
                //   Constant: '<S35>/Constant2'
                //   Constant: '<S39>/Constant'
                //   Math: '<S35>/Math Function1'
                //   RelationalOperator: '<S39>/Compare'

                if (std::abs(rtb_Switch_fe) > 180.0) {
                  rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) +
                    -180.0;
                }

                // Sum: '<S24>/Sum' incorporates:
                //   Sum: '<S23>/Sum1'

                rtb_Switch_fe =
                  (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon
                   - rtb_Switch_fe) + static_cast<real_T>(SequenceID_prev);

                // UnitConversion: '<S27>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Abs1 = 0.017453292519943295 * temp;

                // UnitConversion: '<S42>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                fracSecs *= 0.017453292519943295;

                // Trigonometry: '<S43>/Trigonometric Function1'
                rtb_Down_b = std::sin(fracSecs);

                // Sum: '<S43>/Sum1' incorporates:
                //   Constant: '<S43>/Constant'
                //   Product: '<S43>/Product1'

                rtb_Down_b = 1.0 - codegenReal2Mission_ConstB.sqrt_mc *
                  codegenReal2Mission_ConstB.sqrt_mc * rtb_Down_b * rtb_Down_b;

                // Product: '<S41>/Product1' incorporates:
                //   Constant: '<S41>/Constant1'
                //   Sqrt: '<S41>/sqrt'

                temp = 6.378137E+6 / std::sqrt(rtb_Down_b);

                // Product: '<S26>/dNorth' incorporates:
                //   Constant: '<S41>/Constant2'
                //   Product: '<S41>/Product3'
                //   Trigonometry: '<S41>/Trigonometric Function1'

                rtb_Down_b = rtb_Abs1 / rt_atan2d_snf(1.0, temp *
                  codegenReal2Mission_ConstB.Sum1_a / rtb_Down_b);

                // Switch: '<S29>/Switch' incorporates:
                //   Abs: '<S29>/Abs'
                //   Bias: '<S29>/Bias'
                //   Bias: '<S29>/Bias1'
                //   Constant: '<S29>/Constant2'
                //   Constant: '<S33>/Constant'
                //   Math: '<S29>/Math Function1'
                //   RelationalOperator: '<S33>/Compare'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                if (std::abs(rtb_Switch_fe) > 180.0) {
                  rtb_Switch_fe = rt_modd_snf(rtb_Switch_fe + 180.0, 360.0) +
                    -180.0;
                }

                // Product: '<S26>/dEast' incorporates:
                //   Constant: '<S41>/Constant3'
                //   Product: '<S41>/Product4'
                //   Trigonometry: '<S41>/Trigonometric Function'
                //   Trigonometry: '<S41>/Trigonometric Function2'
                //   UnitConversion: '<S27>/Unit Conversion'

                temp = 1.0 / rt_atan2d_snf(1.0, temp * std::cos(fracSecs)) *
                  (0.017453292519943295 * rtb_Switch_fe);

                // Sum: '<S26>/Sum2' incorporates:
                //   Product: '<S26>/x*cos'
                //   Product: '<S26>/y*sin'

                fracSecs = temp * 0.0 + rtb_Down_b;

                // Sum: '<S26>/Sum3' incorporates:
                //   Product: '<S26>/x*sin'
                //   Product: '<S26>/y*cos'

                rtb_Abs1 = temp - rtb_Down_b * 0.0;

                // Sum: '<S18>/SumUp' incorporates:
                //   DataStoreRead: '<S18>/AltitudeGCS'
                //   Gain: '<S18>/inverse'
                //   Sum: '<S23>/Sum'

                temp =
                  (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt
                   + -AltitudeGCS) +
                  codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;

                // SignalConversion generated from: '<S18>/Orbit Follower' incorporates:
                //   Gain: '<S18>/Up2Down'

                ct[0] = fracSecs;
                ct[1] = rtb_Abs1;
                ct[2] = -temp;

                // MATLABSystem: '<S18>/Orbit Follower' incorporates:
                //   DataTypeConversion: '<S18>/Param1'
                //   DataTypeConversion: '<S18>/Param2'
                //   Gain: '<S18>/Up2Down'
                //   Memory: '<S2>/DelayPose'
                //   SignalConversion generated from: '<S18>/Orbit Follower'

                b_shi = codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                codegenReal2Mission_DW.obj_n.OrbitRadiusFlag = 0U;
                if (codegenReal2Mission_B.MemoryCurrentMission.params.Param1 <=
                    220.0F) {
                  b_shi = 220.0;
                  codegenReal2Mission_DW.obj_n.OrbitRadiusFlag = 1U;
                }

                codegenReal2Mission_DW.obj_n.LookaheadDistFlag = 0U;
                codegenReal2Mission_DW.obj_n.LookaheadDistFlag = 1U;
                rtb_Gain1 = codegenReal2Mission_DW.DelayPose_PreviousInput[0] -
                  fracSecs;
                rtb_Sum1_0[0] = rtb_Gain1;
                rtb_Down2Up_e = codegenReal2Mission_DW.DelayPose_PreviousInput[1]
                  - rtb_Abs1;
                rtb_Sum1_0[1] = rtb_Down2Up_e;
                if (codegenReal2Mission_norm(rtb_Sum1_0) < 2.47032822920623E-323)
                {
                  rtb_ReshapeRowVec[2] = -temp;

                  // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
                  //   Gain: '<S18>/Up2Down'

                  codegenReal2Mission_B.GuidanceCmds.HeadingAngle =
                    codegenReal2Mission_DW.DelayPose_PreviousInput[3];

                  // Merge: '<S14>/ Merge '
                  codegenReal2Mission_B.thisTaskStatus =
                    codegenReal2Mission_DW.obj_n.NumCircles;
                } else {
                  p = false;
                  p_0 = true;
                  nrowx = 0;
                  exitg1 = false;
                  while ((!exitg1) && (nrowx < 3)) {
                    if ((codegenReal2Mission_DW.obj_n.OrbitCenterInternal[nrowx]
                         == ct[nrowx]) || (std::isnan
                                           (codegenReal2Mission_DW.obj_n.OrbitCenterInternal
                                            [nrowx]) && std::isnan(ct[nrowx])))
                    {
                      nrowx++;
                    } else {
                      p_0 = false;
                      exitg1 = true;
                    }
                  }

                  if (p_0) {
                    p = true;
                  }

                  guard2 = false;
                  if (!p) {
                    guard2 = true;
                  } else {
                    p = false;
                    if ((codegenReal2Mission_DW.obj_n.OrbitRadiusInternal ==
                         b_shi) || (std::isnan
                                    (codegenReal2Mission_DW.obj_n.OrbitRadiusInternal)
                                    && std::isnan(b_shi))) {
                      p = true;
                    }

                    if (!p) {
                      guard2 = true;
                    }
                  }

                  if (guard2) {
                    codegenReal2Mission_DW.obj_n.NumCircles = 0.0;
                    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[0] =
                      fracSecs;
                    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[1] =
                      rtb_Abs1;
                    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[2] = -temp;
                    codegenReal2Mission_DW.obj_n.OrbitRadiusInternal = b_shi;
                    codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag = true;
                  }

                  if (35.0 >= b_shi) {
                    codegenReal2Mission_DW.obj_n.LookaheadDistance = 0.9 * b_shi;
                  } else {
                    codegenReal2Mission_DW.obj_n.LookaheadDistance = 35.0;
                  }

                  distToCenter_tmp[0] = rtb_Gain1;
                  distToCenter_tmp[1] = rtb_Down2Up_e;
                  rtb_Switch_fe = std::sqrt(rtb_Down2Up_e * rtb_Down2Up_e +
                    rtb_Gain1 * rtb_Gain1);
                  check = b_shi + codegenReal2Mission_DW.obj_n.LookaheadDistance;
                  rtb_Switch = std::abs(check);
                  p = !std::isinf(rtb_Switch);
                  p_0 = !std::isnan(rtb_Switch);
                  if (p && p_0) {
                    if (rtb_Switch <= 2.2250738585072014E-308) {
                      rtb_Down_b = 4.94065645841247E-324;
                    } else {
                      frexp(rtb_Switch, &imo);
                      rtb_Down_b = std::ldexp(1.0, imo - 53);
                    }
                  } else {
                    rtb_Down_b = (rtNaN);
                  }

                  guard2 = false;
                  if (rtb_Switch_fe >= check - 5.0 * rtb_Down_b) {
                    guard2 = true;
                  } else {
                    if (p && p_0) {
                      if (rtb_Switch <= 2.2250738585072014E-308) {
                        rtb_Down_b = 4.94065645841247E-324;
                      } else {
                        frexp(rtb_Switch, &b_nrows);
                        rtb_Down_b = std::ldexp(1.0, b_nrows - 53);
                      }
                    } else {
                      rtb_Down_b = (rtNaN);
                    }

                    if (rtb_Switch_fe <= (b_shi -
                                          codegenReal2Mission_DW.obj_n.LookaheadDistance)
                        + 5.0 * rtb_Down_b) {
                      guard2 = true;
                    } else {
                      if (codegenReal2Mission_DW.obj_n.StartFlag) {
                        codegenReal2Mission_DW.obj_n.PrevPosition[0] =
                          codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                        codegenReal2Mission_DW.obj_n.PrevPosition[1] =
                          codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                        codegenReal2Mission_DW.obj_n.PrevPosition[2] =
                          codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                        codegenReal2Mission_DW.obj_n.StartFlag = false;
                      }

                      rtb_Sum1_0[0] = rtb_Gain1;
                      rtb_Sum1_0[1] = rtb_Down2Up_e;
                      rtb_Down_b = codegenReal2Mission_norm(rtb_Sum1_0);
                      rtb_Switch =
                        codegenReal2Mission_DW.obj_n.LookaheadDistance *
                        codegenReal2Mission_DW.obj_n.LookaheadDistance;
                      rtb_Switch_fe = ((rtb_Switch - b_shi * b_shi) + rtb_Down_b
                                       * rtb_Down_b) / (2.0 * rtb_Down_b);
                      b_shi = fracSecs -
                        codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                      x2 = b_shi * rtb_Switch_fe / rtb_Down_b +
                        codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                      check = rtb_Abs1 -
                        codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                      rtb_Sum_j = check * rtb_Switch_fe / rtb_Down_b +
                        codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                      rtb_Switch = std::sqrt(rtb_Switch - rtb_Switch_fe *
                        rtb_Switch_fe);
                      rtb_Switch_fe = check * rtb_Switch / rtb_Down_b;
                      distToCenter_tmp[0] = x2 - rtb_Switch_fe;
                      distToCenter_tmp[1] = rtb_Switch_fe + x2;
                      rtb_Switch_fe = b_shi * rtb_Switch / rtb_Down_b;
                      rtb_Down_b = rtb_Switch_fe + rtb_Sum_j;
                      rtb_Switch = rtb_Sum_j - rtb_Switch_fe;
                      if ((codegenReal2Mission_B.MemoryCurrentMission.params.Param2
                           == 0.0F) &&
                          (!codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag))
                      {
                        rtb_Sum_j =
                          codegenReal2Mission_DW.obj_n.TurnDirectionInternal;
                      } else {
                        rtb_Sum_j =
                          codegenReal2Mission_B.MemoryCurrentMission.params.Param2;
                      }

                      turnVector[0] = codegenReal2Mission_DW.obj_n.PrevPosition
                        [0] - fracSecs;
                      turnVector[1] = codegenReal2Mission_DW.obj_n.PrevPosition
                        [1] - rtb_Abs1;
                      rtb_ReshapeRowVec[0] = turnVector[0];
                      rtb_ReshapeRowVec[1] = turnVector[1];
                      rtb_ReshapeRowVec[2] = 0.0;
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                        rtb_Gain1;
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                        rtb_Down2Up_e;
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                        0.0;
                      if (rtb_Sum_j < 0.0) {
                        rtb_ReshapeRowVec[0] = rtb_Gain1;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                          turnVector[0];
                        rtb_ReshapeRowVec[1] = rtb_Down2Up_e;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                          turnVector[1];
                        rtb_ReshapeRowVec[2] = 0.0;
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                          0.0;
                        rtb_Sum_j = -1.0;
                      } else if (rtb_Sum_j > 0.0) {
                        rtb_Sum_j = 1.0;
                      } else if (rtb_Sum_j == 0.0) {
                        rtb_Sum_j = 0.0;
                      } else {
                        rtb_Sum_j = (rtNaN);
                      }

                      rtb_Switch_fe = codegenReal2Mission_norm_b
                        (rtb_ReshapeRowVec);
                      rtb_Down2Up_e = codegenReal2Mission_norm_b
                        (rtb_TmpSignalConversionAtRotateATMissionHdgInport1);
                      rtb_Gain1 = rtb_ReshapeRowVec[0] / rtb_Switch_fe;
                      x2 = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]
                        / rtb_Down2Up_e;
                      rtb_ReshapeRowVec_tmp = rtb_ReshapeRowVec[1] /
                        rtb_Switch_fe;
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp =
                        rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] /
                        rtb_Down2Up_e;
                      codegenReal2Mission_DW.obj_n.PrevPosition[0] =
                        codegenReal2Mission_DW.DelayPose_PreviousInput[0];
                      codegenReal2Mission_DW.obj_n.PrevPosition[1] =
                        codegenReal2Mission_DW.DelayPose_PreviousInput[1];
                      codegenReal2Mission_DW.obj_n.PrevPosition[2] =
                        codegenReal2Mission_DW.DelayPose_PreviousInput[2];
                      codegenReal2Mission_DW.obj_n.NumCircles += rt_atan2d_snf
                        (rtb_Gain1 *
                         rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp
                         - x2 * rtb_ReshapeRowVec_tmp, (rtb_Gain1 * x2 +
                          rtb_ReshapeRowVec_tmp *
                          rtb_TmpSignalConversionAtRotateATMissionHdgInport1_tmp)
                         + 0.0 / rtb_Switch_fe * (0.0 / rtb_Down2Up_e)) / 2.0 /
                        3.1415926535897931;

                      // Merge: '<S14>/ Merge ' incorporates:
                      //   DataTypeConversion: '<S18>/Param2'

                      codegenReal2Mission_B.thisTaskStatus =
                        codegenReal2Mission_DW.obj_n.NumCircles;
                      switch (static_cast<int32_T>(rtb_Sum_j)) {
                       case 1:
                        if ((distToCenter_tmp[0] -
                             codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                            check - (rtb_Down_b -
                                     codegenReal2Mission_DW.DelayPose_PreviousInput
                                     [1]) * b_shi > 0.0) {
                          rtb_Gain1 = distToCenter_tmp[0];
                          rtb_Switch = rtb_Down_b;
                        } else {
                          rtb_Gain1 = distToCenter_tmp[1];
                        }
                        break;

                       case -1:
                        if ((distToCenter_tmp[0] -
                             codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                            check - (rtb_Down_b -
                                     codegenReal2Mission_DW.DelayPose_PreviousInput
                                     [1]) * b_shi < 0.0) {
                          rtb_Gain1 = distToCenter_tmp[0];
                          rtb_Switch = rtb_Down_b;
                        } else {
                          rtb_Gain1 = distToCenter_tmp[1];
                        }
                        break;

                       default:
                        if (std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                              (rtb_Down_b -
                               codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                               distToCenter_tmp[0] -
                               codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                              codegenReal2Mission_DW.DelayPose_PreviousInput[3]))
                            < std::abs(codegenReal2Mission_angdiff(rt_atan2d_snf
                              (rtb_Switch -
                               codegenReal2Mission_DW.DelayPose_PreviousInput[1],
                               distToCenter_tmp[1] -
                               codegenReal2Mission_DW.DelayPose_PreviousInput[0]),
                              codegenReal2Mission_DW.DelayPose_PreviousInput[3])))
                        {
                          rtb_Gain1 = distToCenter_tmp[0];
                          rtb_Switch = rtb_Down_b;
                        } else {
                          rtb_Gain1 = distToCenter_tmp[1];
                        }

                        if ((rtb_Gain1 -
                             codegenReal2Mission_DW.DelayPose_PreviousInput[0]) *
                            check - (rtb_Switch -
                                     codegenReal2Mission_DW.DelayPose_PreviousInput
                                     [1]) * b_shi > 0.0) {
                          codegenReal2Mission_DW.obj_n.TurnDirectionInternal =
                            1.0;
                        } else {
                          codegenReal2Mission_DW.obj_n.TurnDirectionInternal =
                            -1.0;
                        }

                        codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag =
                          false;
                        break;
                      }
                    }
                  }

                  if (guard2) {
                    rtb_Switch_fe = codegenReal2Mission_norm(distToCenter_tmp);
                    rtb_Gain1 = rtb_Gain1 / rtb_Switch_fe * b_shi + fracSecs;
                    rtb_Switch = rtb_Down2Up_e / rtb_Switch_fe * b_shi +
                      rtb_Abs1;

                    // Merge: '<S14>/ Merge '
                    codegenReal2Mission_B.thisTaskStatus =
                      codegenReal2Mission_DW.obj_n.NumCircles;
                  }

                  rtb_ReshapeRowVec[2] = -temp;

                  // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
                  //   DataTypeConversion: '<S18>/Param2'
                  //   Gain: '<S18>/Up2Down'

                  codegenReal2Mission_B.GuidanceCmds.HeadingAngle =
                    rt_atan2d_snf(rtb_Switch -
                                  codegenReal2Mission_DW.DelayPose_PreviousInput[
                                  1], rtb_Gain1 -
                                  codegenReal2Mission_DW.DelayPose_PreviousInput[
                                  0]);
                }

                // BusCreator: '<S18>/GuidanceCMDBusCreator' incorporates:
                //   DataTypeConversion: '<S18>/Param3'
                //   Gain: '<S18>/Down2Height'
                //   MATLABSystem: '<S18>/Orbit Follower'

                codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
                codegenReal2Mission_B.GuidanceCmds.AirSpeed =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

                // Merge: '<S14>/ Merge 3' incorporates:
                //   Bias: '<S18>/ClockwiseRotation'
                //   Constant: '<S18>/InitialFlightPathAngle'
                //   Constant: '<S18>/InitialRollAngle'
                //   Constant: '<S18>/InitialRollAngleRate'
                //   DataTypeConversion: '<S18>/Param1'
                //   DataTypeConversion: '<S18>/Param3'
                //   Product: '<S18>/EastDis'
                //   Product: '<S18>/NorthDis'
                //   Reshape: '<S18>/Reshape'
                //   Sum: '<S18>/SumInitEast'
                //   Sum: '<S18>/SumInitNorth'
                //   Trigonometry: '<S18>/Cos'
                //   Trigonometry: '<S18>/Sin'

                codegenReal2Mission_B.InitialState[0] = std::cos(second) *
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param1 +
                  fracSecs;
                codegenReal2Mission_B.InitialState[1] =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param1 * std::
                  sin(second) + rtb_Abs1;
                codegenReal2Mission_B.InitialState[2] = temp;
                codegenReal2Mission_B.InitialState[3] =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
                codegenReal2Mission_B.InitialState[4] = second +
                  1.5707963267948966;
                codegenReal2Mission_B.InitialState[5] = 0.0;
                codegenReal2Mission_B.InitialState[6] = 0.0;
                codegenReal2Mission_B.InitialState[7] = 0.0;
              }
            } else if ((codegenReal2Mission_B.MemoryCurrentMission.MissionMode ==
                        2) ||
                       (codegenReal2Mission_B.MemoryCurrentMission.MissionMode ==
                        22)) {
              codegenReal2Mission_DW.is_GuidanceLogic =
                codegenReal2Mission_IN_WaypointFollower;

              // Merge: '<S14>/ Merge 2'
              codegenReal2Mission_B.ResetTrigger = 1.0;
              if (codegenReal2Mission_B.MemoryCurrentMission.MissionMode == 2) {
                codegenReal2Mission_DW.is_WaypointFollower =
                  codegenReal2Mission_IN_HorizontalFormationNav;

                // Gain: '<S22>/Gain' incorporates:
                //   Constant: '<S22>/One2ZeroIdx'
                //   Constant: '<S22>/Three'
                //   DataTypeConversion: '<S22>/CastToDouble'
                //   Math: '<S22>/ModRunWayLayer'
                //   Sum: '<S22>/Minus'

                rtb_Down_b = rt_modd_snf(static_cast<real_T>
                  (codegenReal2Mission_B.MemoryCurrentMission.FormationPos) -
                  1.0, 3.0) * 15.0;

                // Sum: '<S22>/BiasMissionAlt' incorporates:
                //   DataStoreRead: '<S22>/AltitudeGCS'
                //   Gain: '<S22>/inverse'
                //   Sum: '<S151>/Sum'
                //   UnaryMinus: '<S151>/Ze2height'

                b_shi =
                  -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt
                    + -AltitudeGCS) - rtb_Down_b;

                // Sum: '<S22>/BiasPrevAlt' incorporates:
                //   DataStoreRead: '<S22>/PrevAltitudeGCS'
                //   Gain: '<S22>/PrevInverse'
                //   Sum: '<S152>/Sum'
                //   UnaryMinus: '<S152>/Ze2height'

                rtb_Down_b = -(temp + -AltitudeGCS) - rtb_Down_b;

                // Abs: '<S167>/Abs' incorporates:
                //   Abs: '<S189>/Abs'
                //   DataStoreRead: '<S22>/LatitudeGCS'

                rtb_Switch_fe = std::abs(LatitudeGCS);

                // Switch: '<S167>/Switch' incorporates:
                //   Abs: '<S167>/Abs'
                //   Bias: '<S167>/Bias'
                //   Bias: '<S167>/Bias1'
                //   Constant: '<S167>/Constant2'
                //   Constant: '<S168>/Constant'
                //   DataStoreRead: '<S22>/LatitudeGCS'
                //   Math: '<S167>/Math Function1'
                //   RelationalOperator: '<S168>/Compare'

                if (rtb_Switch_fe > 180.0) {
                  rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
                } else {
                  rtb_Switch = LatitudeGCS;
                }

                // Abs: '<S164>/Abs1'
                rtb_Abs1 = std::abs(rtb_Switch);

                // Switch: '<S164>/Switch' incorporates:
                //   Bias: '<S164>/Bias'
                //   Bias: '<S164>/Bias1'
                //   Constant: '<S155>/Constant'
                //   Constant: '<S155>/Constant1'
                //   Constant: '<S166>/Constant'
                //   Gain: '<S164>/Gain'
                //   Product: '<S164>/Divide1'
                //   RelationalOperator: '<S166>/Compare'
                //   Switch: '<S155>/Switch1'

                if (rtb_Abs1 > 90.0) {
                  // Signum: '<S164>/Sign1'
                  if (rtb_Switch < 0.0) {
                    rtb_Switch = -1.0;
                  } else if (rtb_Switch > 0.0) {
                    rtb_Switch = 1.0;
                  } else if (rtb_Switch == 0.0) {
                    rtb_Switch = 0.0;
                  } else {
                    rtb_Switch = (rtNaN);
                  }

                  rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
                  imo = 180;
                } else {
                  imo = 0;
                }

                // Sum: '<S155>/Sum' incorporates:
                //   DataStoreRead: '<S22>/LongitudeGCS'

                temp = static_cast<real_T>(imo) + LongitudeGCS;

                // Sum: '<S151>/Sum1'
                rtb_Abs1 =
                  codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat
                  - rtb_Switch;

                // Switch: '<S161>/Switch' incorporates:
                //   Abs: '<S161>/Abs'
                //   Bias: '<S161>/Bias'
                //   Bias: '<S161>/Bias1'
                //   Constant: '<S161>/Constant2'
                //   Constant: '<S162>/Constant'
                //   Math: '<S161>/Math Function1'
                //   RelationalOperator: '<S162>/Compare'

                if (std::abs(rtb_Abs1) > 180.0) {
                  rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                // Abs: '<S158>/Abs1'
                check = std::abs(rtb_Abs1);

                // Switch: '<S158>/Switch' incorporates:
                //   Bias: '<S158>/Bias'
                //   Bias: '<S158>/Bias1'
                //   Constant: '<S154>/Constant'
                //   Constant: '<S154>/Constant1'
                //   Constant: '<S160>/Constant'
                //   Gain: '<S158>/Gain'
                //   Product: '<S158>/Divide1'
                //   RelationalOperator: '<S160>/Compare'
                //   Switch: '<S154>/Switch1'

                if (check > 90.0) {
                  // Signum: '<S158>/Sign1'
                  if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                  } else if (rtb_Abs1 > 0.0) {
                    rtb_Abs1 = 1.0;
                  } else if (rtb_Abs1 == 0.0) {
                    rtb_Abs1 = 0.0;
                  } else {
                    rtb_Abs1 = (rtNaN);
                  }

                  check = (-(check + -90.0) + 90.0) * rtb_Abs1;
                  imo = 180;
                } else {
                  check = rtb_Abs1;
                  imo = 0;
                }

                // Switch: '<S165>/Switch' incorporates:
                //   Abs: '<S165>/Abs'
                //   Bias: '<S165>/Bias'
                //   Bias: '<S165>/Bias1'
                //   Constant: '<S165>/Constant2'
                //   Constant: '<S169>/Constant'
                //   Math: '<S165>/Math Function1'
                //   RelationalOperator: '<S169>/Compare'

                if (std::abs(temp) > 180.0) {
                  temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S154>/Sum' incorporates:
                //   Sum: '<S151>/Sum1'

                temp =
                  (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon
                   - temp) + static_cast<real_T>(imo);

                // UnitConversion: '<S157>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Abs1 = 0.017453292519943295 * check;

                // UnitConversion: '<S172>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch *= 0.017453292519943295;

                // Trigonometry: '<S173>/Trigonometric Function1'
                rtb_Down2Up_e = std::sin(rtb_Switch);

                // Sum: '<S173>/Sum1' incorporates:
                //   Constant: '<S173>/Constant'
                //   Product: '<S173>/Product1'

                rtb_Down2Up_e = 1.0 - codegenReal2Mission_ConstB.sqrt_m *
                  codegenReal2Mission_ConstB.sqrt_m * rtb_Down2Up_e *
                  rtb_Down2Up_e;

                // Product: '<S171>/Product1' incorporates:
                //   Constant: '<S171>/Constant1'
                //   Sqrt: '<S171>/sqrt'

                check = 6.378137E+6 / std::sqrt(rtb_Down2Up_e);

                // Product: '<S156>/dNorth' incorporates:
                //   Constant: '<S171>/Constant2'
                //   Product: '<S171>/Product3'
                //   Trigonometry: '<S171>/Trigonometric Function1'

                rtb_Down2Up_e = rtb_Abs1 / rt_atan2d_snf(1.0, check *
                  codegenReal2Mission_ConstB.Sum1_m / rtb_Down2Up_e);

                // Switch: '<S159>/Switch' incorporates:
                //   Abs: '<S159>/Abs'
                //   Bias: '<S159>/Bias'
                //   Bias: '<S159>/Bias1'
                //   Constant: '<S159>/Constant2'
                //   Constant: '<S163>/Constant'
                //   Math: '<S159>/Math Function1'
                //   RelationalOperator: '<S163>/Compare'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                if (std::abs(temp) > 180.0) {
                  temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
                }

                // Product: '<S156>/dEast' incorporates:
                //   Constant: '<S171>/Constant3'
                //   Product: '<S171>/Product4'
                //   Trigonometry: '<S171>/Trigonometric Function'
                //   Trigonometry: '<S171>/Trigonometric Function2'
                //   UnitConversion: '<S157>/Unit Conversion'

                check = 1.0 / rt_atan2d_snf(1.0, check * std::cos(rtb_Switch)) *
                  (0.017453292519943295 * temp);

                // Sum: '<S156>/Sum2' incorporates:
                //   Product: '<S156>/x*cos'
                //   Product: '<S156>/y*sin'

                temp = check * 0.0 + rtb_Down2Up_e;

                // Sum: '<S156>/Sum3' incorporates:
                //   Product: '<S156>/x*sin'
                //   Product: '<S156>/y*cos'

                check -= rtb_Down2Up_e * 0.0;

                // Product: '<S22>/Map2Radian' incorporates:
                //   Constant: '<S22>/One2ZeroIdx'
                //   DataTypeConversion: '<S22>/CastToDouble'
                //   DataTypeConversion: '<S22>/Param3'
                //   Sum: '<S22>/Minus'

                rtb_Down2Up_e = (static_cast<real_T>
                                 (codegenReal2Mission_B.MemoryCurrentMission.FormationPos)
                                 - 1.0) *
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param3;

                // Gain: '<S150>/Gain1'
                rtb_Gain1 = 0.017453292519943295 *
                  codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

                // Outputs for Triggered SubSystem: '<S22>/WayPointGenerator' incorporates:
                //   TriggerPort: '<S153>/Trigger'

                zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                                   &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE,
                                   (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput));
                if (zcEvent != NO_ZCEVENT) {
                  // Reshape: '<S153>/ReshapeRowVec'
                  rtb_ReshapeRowVec[0] = temp;
                  rtb_ReshapeRowVec[1] = check;
                  rtb_ReshapeRowVec[2] = b_shi;

                  // MATLABSystem: '<S153>/RotateATMissionHdg' incorporates:
                  //   SignalConversion generated from: '<S153>/RotateATMissionHdg'

                  ct[0] = std::cos(rtb_Gain1);
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = std::
                    sin(rtb_Gain1);
                  out[0] = ct[0];
                  out[3] = 0.0 * ct[0] -
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                  out[6] = 0.0 * ct[0] +
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] * 0.0;
                  out[1] = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                  out[4] = 0.0 *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] + ct[0];
                  out[7] = 0.0 *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] - ct[0]
                    * 0.0;
                  out[2] = -0.0;
                  out[5] = 0.0;
                  out[8] = 1.0;

                  // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S22>/Param2'
                  //   DataTypeConversion: '<S22>/Param3'
                  //   Product: '<S153>/ProductScanWidth'

                  rtb_Abs1 = std::ceil
                    (codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                     (codegenReal2Mission_B.MemoryCurrentMission.params.Param3 *
                      static_cast<real_T>
                      (codegenReal2Mission_B.MemoryCurrentMission.numUAV)));
                  rtb_Switch =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                    rtb_Abs1;
                  connectionObj.FlightPathAngleLimit[0] = -0.175;
                  connectionObj.FlightPathAngleLimit[1] = 0.175;
                  connectionObj.MaxRollAngle = 0.29670597283903605;
                  connectionObj.AirSpeed = 35.0;
                  connectionObj.MinTurningRadius = 408.85657731051754;
                  imo = static_cast<int32_T>(rtb_Abs1 * 2.0);
                  SequenceID_prev = CheckPoints->size[0] * CheckPoints->size[1];

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  CheckPoints->size[0] = imo;
                  CheckPoints->size[1] = 4;
                  codegenReal2Mission_emxEnsureCapacity_real_T(CheckPoints,
                    SequenceID_prev);

                  // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S22>/Param1'

                  b_nrows = (imo << 2) - 1;
                  for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                       SequenceID_prev++) {
                    CheckPoints->data[SequenceID_prev] = 0.0;
                  }

                  for (b_nrows = 0; b_nrows < static_cast<int32_T>(rtb_Abs1);
                       b_nrows++) {
                    if (rt_remd_snf(static_cast<real_T>(b_nrows) + 1.0, 2.0) ==
                        1.0) {
                      imo = (b_nrows + 1) << 1;
                      rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                        rtb_Switch;
                      CheckPoints->data[imo - 2] = rtb_Sum_j;
                      CheckPoints->data[(imo + CheckPoints->size[0]) - 2] = 0.0;
                      CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2]
                        = 0.0;
                      CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                        1.5707963267948966;
                      CheckPoints->data[imo - 1] = rtb_Sum_j;
                      CheckPoints->data[(imo + CheckPoints->size[0]) - 1] =
                        codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                      CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1]
                        = 0.0;
                      CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                        1.5707963267948966;
                    } else {
                      imo = (b_nrows + 1) << 1;
                      rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                        rtb_Switch;
                      CheckPoints->data[imo - 2] = rtb_Sum_j;
                      CheckPoints->data[(imo + CheckPoints->size[0]) - 2] =
                        codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                      CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2]
                        = 0.0;
                      CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                        -1.5707963267948966;
                      CheckPoints->data[imo - 1] = rtb_Sum_j;
                      CheckPoints->data[(imo + CheckPoints->size[0]) - 1] = 0.0;
                      CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1]
                        = 0.0;
                      CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                        -1.5707963267948966;
                    }
                  }

                  SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->
                    size[1];

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  dummyWayPoint->size[0] = 1;
                  dummyWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                    SequenceID_prev);

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  dummyWayPoint->data[0] = 0.0;
                  dummyWayPoint->data[1] = 0.0;
                  dummyWayPoint->data[2] = 0.0;
                  for (nrowx = 0; nrowx <= CheckPoints->size[0] - 2; nrowx++) {
                    LUp[0] = CheckPoints->data[nrowx];
                    LDp[0] = CheckPoints->data[nrowx + 1];
                    LUp[1] = CheckPoints->data[nrowx + CheckPoints->size[0]];
                    LDp[1] = CheckPoints->data[(nrowx + CheckPoints->size[0]) +
                      1];
                    LUp[2] = CheckPoints->data[nrowx + (CheckPoints->size[0] <<
                      1)];
                    LDp[2] = CheckPoints->data[(nrowx + (CheckPoints->size[0] <<
                      1)) + 1];
                    LUp[3] = CheckPoints->data[nrowx + CheckPoints->size[0] * 3];
                    LDp[3] = CheckPoints->data[(nrowx + CheckPoints->size[0] * 3)
                      + 1];
                    codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp,
                      100.0, segWayPoints);
                    SequenceID_prev = dummyWayPoint_0->size[0] *
                      dummyWayPoint_0->size[1];
                    dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                      segWayPoints->size[0];
                    dummyWayPoint_0->size[1] = 3;
                    codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                      SequenceID_prev);
                    b_nrows = dummyWayPoint->size[0];
                    for (imo = 0; imo < 3; imo++) {
                      for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                           SequenceID_prev++) {
                        dummyWayPoint_0->data[SequenceID_prev +
                          dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                          data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                      }
                    }

                    b_nrows = segWayPoints->size[0];
                    for (imo = 0; imo < 3; imo++) {
                      for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                           SequenceID_prev++) {
                        dummyWayPoint_0->data[(SequenceID_prev +
                          dummyWayPoint->size[0]) + dummyWayPoint_0->size[0] *
                          imo] = segWayPoints->data[SequenceID_prev +
                          segWayPoints->size[0] * imo];
                      }
                    }

                    SequenceID_prev = dummyWayPoint->size[0] *
                      dummyWayPoint->size[1];
                    dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                    dummyWayPoint->size[1] = 3;
                    codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                      SequenceID_prev);
                    b_nrows = dummyWayPoint_0->size[0] * 3;
                    for (imo = 0; imo < b_nrows; imo++) {
                      dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                    }
                  }

                  LUp[0] = CheckPoints->data[CheckPoints->size[0] - 1];
                  LDp[0] = CheckPoints->data[0];
                  LUp[1] = CheckPoints->data[(CheckPoints->size[0] +
                    CheckPoints->size[0]) - 1];
                  LDp[1] = CheckPoints->data[CheckPoints->size[0]];
                  LUp[2] = CheckPoints->data[(CheckPoints->size[0] +
                    (CheckPoints->size[0] << 1)) - 1];
                  LDp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
                  LUp[3] = CheckPoints->data[(CheckPoints->size[0] +
                    CheckPoints->size[0] * 3) - 1];
                  LDp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
                  codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                    segWayPoints);
                  SequenceID_prev = dummyWayPoint_0->size[0] *
                    dummyWayPoint_0->size[1];

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                    segWayPoints->size[0];
                  dummyWayPoint_0->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                    SequenceID_prev);

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  b_nrows = dummyWayPoint->size[0];
                  nrows = segWayPoints->size[0];
                  for (imo = 0; imo < 3; imo++) {
                    for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                         SequenceID_prev++) {
                      dummyWayPoint_0->data[SequenceID_prev +
                        dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                        data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                    }

                    for (SequenceID_prev = 0; SequenceID_prev < nrows;
                         SequenceID_prev++) {
                      dummyWayPoint_0->data[(SequenceID_prev +
                        dummyWayPoint->size[0]) + dummyWayPoint_0->size[0] * imo]
                        = segWayPoints->data[SequenceID_prev +
                        segWayPoints->size[0] * imo];
                    }
                  }

                  SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->
                    size[1];

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                  dummyWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                    SequenceID_prev);

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  b_nrows = dummyWayPoint_0->size[0] * 3;
                  for (imo = 0; imo < b_nrows; imo++) {
                    dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                  }

                  nrowx = dummyWayPoint->size[0] - 2;
                  nrows = dummyWayPoint->size[0] - 1;
                  for (imo = 0; imo <= nrowx; imo++) {
                    dummyWayPoint->data[imo] = dummyWayPoint->data[imo + 1];
                  }

                  for (imo = 0; imo <= nrowx; imo++) {
                    dummyWayPoint->data[imo + dummyWayPoint->size[0]] =
                      dummyWayPoint->data[(imo + dummyWayPoint->size[0]) + 1];
                  }

                  for (imo = 0; imo <= nrowx; imo++) {
                    dummyWayPoint->data[imo + (dummyWayPoint->size[0] << 1)] =
                      dummyWayPoint->data[(imo + (dummyWayPoint->size[0] << 1))
                      + 1];
                  }

                  if (1 > nrows) {
                    b_nrows = -1;
                  } else {
                    b_nrows = nrowx;
                  }

                  SequenceID_prev = segWayPoints->size[0] * segWayPoints->size[1];

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  segWayPoints->size[0] = b_nrows + 1;
                  segWayPoints->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(segWayPoints,
                    SequenceID_prev);

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  for (imo = 0; imo < 3; imo++) {
                    for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                         SequenceID_prev++) {
                      segWayPoints->data[SequenceID_prev + segWayPoints->size[0]
                        * imo] = dummyWayPoint->data[SequenceID_prev +
                        dummyWayPoint->size[0] * imo];
                    }
                  }

                  if (1 > nrows) {
                    imo = -1;
                    nrowx = -1;
                  } else {
                    imo = nrowx;
                  }

                  rtb_Abs1 = std::ceil(10240.0 / static_cast<real_T>(imo + 1));
                  SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->
                    size[1];

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  dummyWayPoint->size[0] = (nrowx + 1) * static_cast<int32_T>
                    (rtb_Abs1);
                  dummyWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                    SequenceID_prev);

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  b_nrows = segWayPoints->size[0];

                  // Reshape: '<S22>/Reshape2Row' incorporates:
                  //   Memory: '<S22>/MemoryPrevRelPos'

                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[1];
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                    codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[0];
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                    codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[2];

                  // Product: '<S153>/RotateRelPrevPos' incorporates:
                  //   MATLABSystem: '<S153>/RotateATMissionHdg'

                  rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1, out, ct);

                  // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
                  //   Product: '<S153>/RotateRelPrevPos'

                  for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                    nrows = imo * b_nrows + -1;
                    for (k = 1; k - 1 < b_nrows; k++) {
                      dummyWayPoint->data[nrows + k] = segWayPoints->data[k - 1];
                    }
                  }

                  LDp[0] = ct[0];
                  SequenceID_prev = segWayPoints->size[0] * static_cast<int32_T>
                    (rtb_Abs1) - 1;
                  for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                    nrows = imo * b_nrows + SequenceID_prev;
                    for (k = 1; k - 1 < b_nrows; k++) {
                      dummyWayPoint->data[nrows + k] = segWayPoints->data
                        [(b_nrows + k) - 1];
                    }
                  }

                  LDp[1] = ct[1];
                  nrowx = segWayPoints->size[0] << 1;
                  SequenceID_prev = ((segWayPoints->size[0] *
                                      static_cast<int32_T>(rtb_Abs1)) << 1) - 1;
                  for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                    nrows = imo * b_nrows + SequenceID_prev;
                    for (k = 1; k - 1 < b_nrows; k++) {
                      dummyWayPoint->data[nrows + k] = segWayPoints->data[(nrowx
                        + k) - 1];
                    }
                  }

                  LDp[2] = ct[2];
                  LDp[3] = 1.5707963267948966;
                  LUp[0] = CheckPoints->data[0];
                  LUp[1] = CheckPoints->data[CheckPoints->size[0]];
                  LUp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
                  LUp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
                  codegenReal2Mission_genSegWP_i(&connectionObj, LDp, LUp, 100.0,
                    segWayPoints);
                  SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  initWayPoint->size[0] = segWayPoints->size[0] +
                    dummyWayPoint->size[0];
                  initWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                    SequenceID_prev);

                  // MATLAB Function: '<S153>/WayPointGenerator'
                  b_nrows = segWayPoints->size[0];
                  nrows = dummyWayPoint->size[0];
                  for (imo = 0; imo < 3; imo++) {
                    for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                         SequenceID_prev++) {
                      initWayPoint->data[SequenceID_prev + initWayPoint->size[0]
                        * imo] = segWayPoints->data[SequenceID_prev +
                        segWayPoints->size[0] * imo];
                    }

                    for (SequenceID_prev = 0; SequenceID_prev < nrows;
                         SequenceID_prev++) {
                      initWayPoint->data[(SequenceID_prev + segWayPoints->size[0])
                        + initWayPoint->size[0] * imo] = dummyWayPoint->
                        data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                    }

                    for (SequenceID_prev = 0; SequenceID_prev < 10240;
                         SequenceID_prev++) {
                      codegenReal2Mission_B.WayPoint[SequenceID_prev + 10240 *
                        imo] = initWayPoint->data[SequenceID_prev +
                        initWayPoint->size[0] * imo];
                    }
                  }

                  for (imo = 0; imo < 10240; imo++) {
                    // MATLAB Function: '<S153>/biasWayPoint'
                    codegenReal2Mission_B.rtb_WayPoint_m[imo] =
                      codegenReal2Mission_B.WayPoint[imo] + rtb_Down2Up_e;
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240] =
                      codegenReal2Mission_B.WayPoint[imo + 10240];
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480] =
                      codegenReal2Mission_B.WayPoint[imo + 20480];

                    // Product: '<S153>/RotateIndivWayPoint' incorporates:
                    //   MATLABSystem: '<S153>/RotateATMissionHdg'

                    for (SequenceID_prev = 0; SequenceID_prev < 3;
                         SequenceID_prev++) {
                      b_nrows = imo + 10240 * SequenceID_prev;
                      codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                      codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out
                        [3 * SequenceID_prev] *
                        codegenReal2Mission_B.rtb_WayPoint_m[imo];
                      codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out
                        [3 * SequenceID_prev + 1] *
                        codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                      codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out
                        [3 * SequenceID_prev + 2] *
                        codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
                    }
                  }

                  // MATLAB Function: '<S153>/biasNED' incorporates:
                  //   Product: '<S153>/RotateIndivWayPoint'
                  //   Reshape: '<S153>/ReshapeRowVec'

                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    SequenceID_prev = b_nrows * 10240;
                    for (imo = 0; imo < 10240; imo++) {
                      codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                        rtb_ReshapeRowVec[b_nrows];
                    }
                  }

                  for (imo = 0; imo < 10240; imo++) {
                    codegenReal2Mission_B.nedWayPoint[imo] =
                      codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                      codegenReal2Mission_B.WayPoint[imo];
                    codegenReal2Mission_B.nedWayPoint[imo + 10240] =
                      codegenReal2Mission_B.WayPoint[imo + 10240] +
                      codegenReal2Mission_B.RotateIndivWayPoint[imo];
                    codegenReal2Mission_B.nedWayPoint[imo + 20480] =
                      codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                      codegenReal2Mission_B.WayPoint[imo + 20480];
                  }
                }

                // End of Outputs for SubSystem: '<S22>/WayPointGenerator'

                // BusCreator: '<S22>/GuidanceCMDBusCreator' incorporates:
                //   Constant: '<S22>/LookAheadDis'
                //   MATLAB Function: '<S153>/WayPointGenerator'
                //   MATLABSystem: '<S22>/Waypoint Follower'
                //   Memory: '<S22>/MemoryTriggerWP'
                //   Memory: '<S2>/DelayPose'

                codegenReal2Mission_WaypointFollowerBase_stepInternal
                  (&codegenReal2Mission_DW.obj,
                   codegenReal2Mission_DW.DelayPose_PreviousInput,
                   codegenReal2Mission_B.nedWayPoint, 200.0, rtb_ReshapeRowVec,
                   &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
                   &lookaheadFlag, &rtb_Switch, &status_0);

                // Merge: '<S14>/ Merge ' incorporates:
                //   DataTypeConversion: '<S22>/Cast To Double'
                //   MATLABSystem: '<S22>/Waypoint Follower'

                codegenReal2Mission_B.thisTaskStatus = status_0;

                // BusCreator: '<S22>/GuidanceCMDBusCreator' incorporates:
                //   DataTypeConversion: '<S22>/Param4'
                //   Gain: '<S22>/Down2Height'
                //   MATLABSystem: '<S22>/Waypoint Follower'

                codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
                codegenReal2Mission_B.GuidanceCmds.AirSpeed =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

                // Switch: '<S189>/Switch' incorporates:
                //   Bias: '<S189>/Bias'
                //   Bias: '<S189>/Bias1'
                //   Constant: '<S189>/Constant2'
                //   Constant: '<S190>/Constant'
                //   DataStoreRead: '<S22>/PrevLatitudeGCS'
                //   Math: '<S189>/Math Function1'
                //   RelationalOperator: '<S190>/Compare'

                if (rtb_Switch_fe > 180.0) {
                  rtb_Switch_fe = rt_modd_snf(LatitudeGCS + 180.0, 360.0) +
                    -180.0;
                } else {
                  rtb_Switch_fe = LatitudeGCS;
                }

                // Abs: '<S186>/Abs1'
                rtb_Abs1 = std::abs(rtb_Switch_fe);

                // Switch: '<S186>/Switch' incorporates:
                //   Bias: '<S186>/Bias'
                //   Bias: '<S186>/Bias1'
                //   Constant: '<S177>/Constant'
                //   Constant: '<S177>/Constant1'
                //   Constant: '<S188>/Constant'
                //   Gain: '<S186>/Gain'
                //   Product: '<S186>/Divide1'
                //   RelationalOperator: '<S188>/Compare'
                //   Switch: '<S177>/Switch1'

                if (rtb_Abs1 > 90.0) {
                  // Signum: '<S186>/Sign1'
                  if (rtb_Switch_fe < 0.0) {
                    rtb_Switch_fe = -1.0;
                  } else if (rtb_Switch_fe > 0.0) {
                    rtb_Switch_fe = 1.0;
                  } else if (rtb_Switch_fe == 0.0) {
                    rtb_Switch_fe = 0.0;
                  } else {
                    rtb_Switch_fe = (rtNaN);
                  }

                  rtb_Switch_fe *= -(rtb_Abs1 + -90.0) + 90.0;
                  imo = 180;
                } else {
                  imo = 0;
                }

                // Sum: '<S177>/Sum' incorporates:
                //   DataStoreRead: '<S22>/PrevLongitudeGCS'

                rtb_Sum_j = static_cast<real_T>(imo) + LongitudeGCS;

                // Sum: '<S152>/Sum1'
                rtb_Abs1 = fracSecs - rtb_Switch_fe;

                // Switch: '<S183>/Switch' incorporates:
                //   Abs: '<S183>/Abs'
                //   Bias: '<S183>/Bias'
                //   Bias: '<S183>/Bias1'
                //   Constant: '<S183>/Constant2'
                //   Constant: '<S184>/Constant'
                //   Math: '<S183>/Math Function1'
                //   RelationalOperator: '<S184>/Compare'

                if (std::abs(rtb_Abs1) > 180.0) {
                  rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                // Abs: '<S180>/Abs1'
                fracSecs = std::abs(rtb_Abs1);

                // Switch: '<S180>/Switch' incorporates:
                //   Bias: '<S180>/Bias'
                //   Bias: '<S180>/Bias1'
                //   Constant: '<S176>/Constant'
                //   Constant: '<S176>/Constant1'
                //   Constant: '<S182>/Constant'
                //   Gain: '<S180>/Gain'
                //   Product: '<S180>/Divide1'
                //   RelationalOperator: '<S182>/Compare'
                //   Switch: '<S176>/Switch1'

                if (fracSecs > 90.0) {
                  // Signum: '<S180>/Sign1'
                  if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                  } else if (rtb_Abs1 > 0.0) {
                    rtb_Abs1 = 1.0;
                  } else if (rtb_Abs1 == 0.0) {
                    rtb_Abs1 = 0.0;
                  } else {
                    rtb_Abs1 = (rtNaN);
                  }

                  rtb_Switch = (-(fracSecs + -90.0) + 90.0) * rtb_Abs1;
                  imo = 180;
                } else {
                  rtb_Switch = rtb_Abs1;
                  imo = 0;
                }

                // Switch: '<S187>/Switch' incorporates:
                //   Abs: '<S187>/Abs'
                //   Bias: '<S187>/Bias'
                //   Bias: '<S187>/Bias1'
                //   Constant: '<S187>/Constant2'
                //   Constant: '<S191>/Constant'
                //   Math: '<S187>/Math Function1'
                //   RelationalOperator: '<S191>/Compare'

                if (std::abs(rtb_Sum_j) > 180.0) {
                  rtb_Sum_j = rt_modd_snf(rtb_Sum_j + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S176>/Sum' incorporates:
                //   Sum: '<S152>/Sum1'

                rtb_Abs1 = (second - rtb_Sum_j) + static_cast<real_T>(imo);

                // UnitConversion: '<S194>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch_fe *= 0.017453292519943295;

                // Trigonometry: '<S195>/Trigonometric Function1'
                second = std::sin(rtb_Switch_fe);

                // Sum: '<S195>/Sum1' incorporates:
                //   Constant: '<S195>/Constant'
                //   Product: '<S195>/Product1'

                second = 1.0 - codegenReal2Mission_ConstB.sqrt_c *
                  codegenReal2Mission_ConstB.sqrt_c * second * second;

                // Product: '<S193>/Product1' incorporates:
                //   Constant: '<S193>/Constant1'
                //   Sqrt: '<S193>/sqrt'

                fracSecs = 6.378137E+6 / std::sqrt(second);

                // Product: '<S193>/Product4' incorporates:
                //   Trigonometry: '<S193>/Trigonometric Function'

                rtb_Switch_fe = fracSecs * std::cos(rtb_Switch_fe);

                // Product: '<S178>/dNorth' incorporates:
                //   Constant: '<S193>/Constant2'
                //   Product: '<S193>/Product3'
                //   Trigonometry: '<S193>/Trigonometric Function1'
                //   UnitConversion: '<S179>/Unit Conversion'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                fracSecs = 0.017453292519943295 * rtb_Switch / rt_atan2d_snf(1.0,
                  fracSecs * codegenReal2Mission_ConstB.Sum1_c / second);

                // Switch: '<S181>/Switch' incorporates:
                //   Abs: '<S181>/Abs'
                //   Bias: '<S181>/Bias'
                //   Bias: '<S181>/Bias1'
                //   Constant: '<S181>/Constant2'
                //   Constant: '<S185>/Constant'
                //   Math: '<S181>/Math Function1'
                //   RelationalOperator: '<S185>/Compare'

                if (std::abs(rtb_Abs1) > 180.0) {
                  rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                // Product: '<S178>/dEast' incorporates:
                //   Constant: '<S193>/Constant3'
                //   Trigonometry: '<S193>/Trigonometric Function2'
                //   UnitConversion: '<S179>/Unit Conversion'

                second = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe) *
                  (0.017453292519943295 * rtb_Abs1);

                // Sum: '<S178>/Sum2' incorporates:
                //   Product: '<S178>/x*cos'
                //   Product: '<S178>/y*sin'

                rtb_Switch = second * 0.0 + fracSecs;

                // Sum: '<S178>/Sum3' incorporates:
                //   Product: '<S178>/x*sin'
                //   Product: '<S178>/y*cos'

                fracSecs = second - fracSecs * 0.0;

                // Merge: '<S14>/ Merge 3' incorporates:
                //   Bias: '<S22>/Rotate90deg'
                //   Constant: '<S22>/InitialFlightPathAngle'
                //   Constant: '<S22>/InitialRollAngle'
                //   Constant: '<S22>/InitialRollAngleRate'
                //   DataTypeConversion: '<S22>/Param4'
                //   Gain: '<S22>/Down2Up'
                //   Product: '<S22>/ProductEast'
                //   Product: '<S22>/ProductNorth'
                //   Reshape: '<S22>/Reshape'
                //   Sum: '<S22>/SumInitEast'
                //   Sum: '<S22>/SumInitNorth'
                //   Trigonometry: '<S22>/Cos'
                //   Trigonometry: '<S22>/Sin'

                codegenReal2Mission_B.InitialState[0] = std::cos(rtb_Gain1 +
                  1.5707963267948966) * rtb_Down2Up_e + rtb_Switch;
                codegenReal2Mission_B.InitialState[1] = std::sin(rtb_Gain1 +
                  1.5707963267948966) * rtb_Down2Up_e + fracSecs;
                codegenReal2Mission_B.InitialState[2] = -rtb_Down_b;
                codegenReal2Mission_B.InitialState[3] =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
                codegenReal2Mission_B.InitialState[4] = rtb_Gain1;
                codegenReal2Mission_B.InitialState[5] = 0.0;
                codegenReal2Mission_B.InitialState[6] = 0.0;
                codegenReal2Mission_B.InitialState[7] = 0.0;

                // Update for Memory: '<S22>/MemoryPrevRelPos' incorporates:
                //   Sum: '<S22>/RelPrevPos'

                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[0] =
                  rtb_Switch - temp;
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[1] =
                  fracSecs - check;
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[2] =
                  rtb_Down_b - b_shi;

                // Update for Memory: '<S22>/MemoryTriggerWP' incorporates:
                //   Constant: '<S22>/TirggerWayPointGen'

                codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput = 1.0;
              } else {
                codegenReal2Mission_DW.is_WaypointFollower =
                  codegenReal2Mission_IN_CustomFormationNav;

                // Abs: '<S116>/Abs' incorporates:
                //   Abs: '<S138>/Abs'
                //   DataStoreRead: '<S21>/LatitudeGCS'

                rtb_Switch_fe = std::abs(LatitudeGCS);

                // Switch: '<S116>/Switch' incorporates:
                //   Abs: '<S116>/Abs'
                //   Bias: '<S116>/Bias'
                //   Bias: '<S116>/Bias1'
                //   Constant: '<S116>/Constant2'
                //   Constant: '<S117>/Constant'
                //   DataStoreRead: '<S21>/LatitudeGCS'
                //   Math: '<S116>/Math Function1'
                //   RelationalOperator: '<S117>/Compare'

                if (rtb_Switch_fe > 180.0) {
                  rtb_Down_b = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
                } else {
                  rtb_Down_b = LatitudeGCS;
                }

                // Abs: '<S113>/Abs1'
                rtb_Abs1 = std::abs(rtb_Down_b);

                // Switch: '<S113>/Switch' incorporates:
                //   Bias: '<S113>/Bias'
                //   Bias: '<S113>/Bias1'
                //   Constant: '<S104>/Constant'
                //   Constant: '<S104>/Constant1'
                //   Constant: '<S115>/Constant'
                //   Gain: '<S113>/Gain'
                //   Product: '<S113>/Divide1'
                //   RelationalOperator: '<S115>/Compare'
                //   Switch: '<S104>/Switch1'

                if (rtb_Abs1 > 90.0) {
                  // Signum: '<S113>/Sign1'
                  if (rtb_Down_b < 0.0) {
                    rtb_Down_b = -1.0;
                  } else if (rtb_Down_b > 0.0) {
                    rtb_Down_b = 1.0;
                  } else if (rtb_Down_b == 0.0) {
                    rtb_Down_b = 0.0;
                  } else {
                    rtb_Down_b = (rtNaN);
                  }

                  rtb_Down_b *= -(rtb_Abs1 + -90.0) + 90.0;
                  imo = 180;
                } else {
                  imo = 0;
                }

                // Sum: '<S104>/Sum' incorporates:
                //   DataStoreRead: '<S21>/LongitudeGCS'

                check = static_cast<real_T>(imo) + LongitudeGCS;

                // Sum: '<S100>/Sum1'
                rtb_Abs1 =
                  codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat
                  - rtb_Down_b;

                // Switch: '<S110>/Switch' incorporates:
                //   Abs: '<S110>/Abs'
                //   Bias: '<S110>/Bias'
                //   Bias: '<S110>/Bias1'
                //   Constant: '<S110>/Constant2'
                //   Constant: '<S111>/Constant'
                //   Math: '<S110>/Math Function1'
                //   RelationalOperator: '<S111>/Compare'

                if (std::abs(rtb_Abs1) > 180.0) {
                  rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                // Abs: '<S107>/Abs1'
                b_shi = std::abs(rtb_Abs1);

                // Switch: '<S107>/Switch' incorporates:
                //   Bias: '<S107>/Bias'
                //   Bias: '<S107>/Bias1'
                //   Constant: '<S103>/Constant'
                //   Constant: '<S103>/Constant1'
                //   Constant: '<S109>/Constant'
                //   Gain: '<S107>/Gain'
                //   Product: '<S107>/Divide1'
                //   RelationalOperator: '<S109>/Compare'
                //   Switch: '<S103>/Switch1'

                if (b_shi > 90.0) {
                  // Signum: '<S107>/Sign1'
                  if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                  } else if (rtb_Abs1 > 0.0) {
                    rtb_Abs1 = 1.0;
                  } else if (rtb_Abs1 == 0.0) {
                    rtb_Abs1 = 0.0;
                  } else {
                    rtb_Abs1 = (rtNaN);
                  }

                  b_shi = (-(b_shi + -90.0) + 90.0) * rtb_Abs1;
                  imo = 180;
                } else {
                  b_shi = rtb_Abs1;
                  imo = 0;
                }

                // Switch: '<S114>/Switch' incorporates:
                //   Abs: '<S114>/Abs'
                //   Bias: '<S114>/Bias'
                //   Bias: '<S114>/Bias1'
                //   Constant: '<S114>/Constant2'
                //   Constant: '<S118>/Constant'
                //   Math: '<S114>/Math Function1'
                //   RelationalOperator: '<S118>/Compare'

                if (std::abs(check) > 180.0) {
                  check = rt_modd_snf(check + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S103>/Sum' incorporates:
                //   Sum: '<S100>/Sum1'

                rtb_Down2Up_e =
                  (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon
                   - check) + static_cast<real_T>(imo);

                // UnitConversion: '<S106>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Abs1 = 0.017453292519943295 * b_shi;

                // UnitConversion: '<S121>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Down_b *= 0.017453292519943295;

                // Trigonometry: '<S122>/Trigonometric Function1'
                check = std::sin(rtb_Down_b);

                // Sum: '<S122>/Sum1' incorporates:
                //   Constant: '<S122>/Constant'
                //   Product: '<S122>/Product1'

                check = 1.0 - codegenReal2Mission_ConstB.sqrt_cy *
                  codegenReal2Mission_ConstB.sqrt_cy * check * check;

                // Product: '<S120>/Product1' incorporates:
                //   Constant: '<S120>/Constant1'
                //   Sqrt: '<S120>/sqrt'

                b_shi = 6.378137E+6 / std::sqrt(check);

                // Product: '<S105>/dNorth' incorporates:
                //   Constant: '<S120>/Constant2'
                //   Product: '<S120>/Product3'
                //   Trigonometry: '<S120>/Trigonometric Function1'

                check = rtb_Abs1 / rt_atan2d_snf(1.0, b_shi *
                  codegenReal2Mission_ConstB.Sum1_e / check);

                // Switch: '<S108>/Switch' incorporates:
                //   Abs: '<S108>/Abs'
                //   Bias: '<S108>/Bias'
                //   Bias: '<S108>/Bias1'
                //   Constant: '<S108>/Constant2'
                //   Constant: '<S112>/Constant'
                //   Math: '<S108>/Math Function1'
                //   RelationalOperator: '<S112>/Compare'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                if (std::abs(rtb_Down2Up_e) > 180.0) {
                  rtb_Down2Up_e = rt_modd_snf(rtb_Down2Up_e + 180.0, 360.0) +
                    -180.0;
                }

                // Product: '<S105>/dEast' incorporates:
                //   Constant: '<S120>/Constant3'
                //   Product: '<S120>/Product4'
                //   Trigonometry: '<S120>/Trigonometric Function'
                //   Trigonometry: '<S120>/Trigonometric Function2'
                //   UnitConversion: '<S106>/Unit Conversion'

                b_shi = 1.0 / rt_atan2d_snf(1.0, b_shi * std::cos(rtb_Down_b)) *
                  (0.017453292519943295 * rtb_Down2Up_e);

                // Sum: '<S105>/Sum2' incorporates:
                //   Product: '<S105>/x*cos'
                //   Product: '<S105>/y*sin'

                rtb_Down_b = b_shi * 0.0 + check;

                // Sum: '<S105>/Sum3' incorporates:
                //   Product: '<S105>/x*sin'
                //   Product: '<S105>/y*cos'

                b_shi -= check * 0.0;

                // Sum: '<S21>/Sum' incorporates:
                //   DataStoreRead: '<S21>/AltitudeGCS'
                //   Gain: '<S21>/Up2Down'
                //   Gain: '<S21>/inverse'
                //   Sum: '<S100>/Sum'
                //   UnaryMinus: '<S100>/Ze2height'

                check =
                  -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt
                    + -AltitudeGCS) +
                  -codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;

                // Gain: '<S99>/Gain1'
                rtb_Down2Up_e = 0.017453292519943295 *
                  codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

                // Outputs for Triggered SubSystem: '<S21>/WayPointGenerator' incorporates:
                //   TriggerPort: '<S102>/Trigger'

                zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                                   &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE_b,
                                   (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_k));
                if (zcEvent != NO_ZCEVENT) {
                  // Reshape: '<S102>/ReshapeRowVec'
                  rtb_ReshapeRowVec[0] = rtb_Down_b;
                  rtb_ReshapeRowVec[1] = b_shi;
                  rtb_ReshapeRowVec[2] = check;

                  // MATLABSystem: '<S102>/RotateATMissionHdg' incorporates:
                  //   SignalConversion generated from: '<S102>/RotateATMissionHdg'

                  ct[0] = std::cos(rtb_Down2Up_e);
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = std::
                    sin(rtb_Down2Up_e);
                  out[0] = ct[0];
                  out[3] = 0.0 * ct[0] -
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                  out[6] = 0.0 * ct[0] +
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] * 0.0;
                  out[1] = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
                  out[4] = 0.0 *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] + ct[0];
                  out[7] = 0.0 *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] - ct[0]
                    * 0.0;
                  out[2] = -0.0;
                  out[5] = 0.0;
                  out[8] = 1.0;

                  // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S21>/Param2'
                  //   DataTypeConversion: '<S21>/Param3'
                  //   Product: '<S102>/ProductScanWidth'

                  rtb_Abs1 = std::ceil
                    (codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                     (codegenReal2Mission_B.MemoryCurrentMission.params.Param3 *
                      static_cast<real_T>
                      (codegenReal2Mission_B.MemoryCurrentMission.numUAV)));
                  rtb_Switch =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                    rtb_Abs1;
                  connectionObj.FlightPathAngleLimit[0] = -0.175;
                  connectionObj.FlightPathAngleLimit[1] = 0.175;
                  connectionObj.MaxRollAngle = 0.29670597283903605;
                  connectionObj.AirSpeed = 35.0;
                  connectionObj.MinTurningRadius = 408.85657731051754;
                  imo = static_cast<int32_T>(rtb_Abs1 * 2.0);
                  SequenceID_prev = CheckPoints->size[0] * CheckPoints->size[1];

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  CheckPoints->size[0] = imo;
                  CheckPoints->size[1] = 4;
                  codegenReal2Mission_emxEnsureCapacity_real_T(CheckPoints,
                    SequenceID_prev);

                  // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
                  //   DataTypeConversion: '<S21>/Param1'

                  b_nrows = (imo << 2) - 1;
                  for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                       SequenceID_prev++) {
                    CheckPoints->data[SequenceID_prev] = 0.0;
                  }

                  for (b_nrows = 0; b_nrows < static_cast<int32_T>(rtb_Abs1);
                       b_nrows++) {
                    if (rt_remd_snf(static_cast<real_T>(b_nrows) + 1.0, 2.0) ==
                        1.0) {
                      imo = (b_nrows + 1) << 1;
                      rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                        rtb_Switch;
                      CheckPoints->data[imo - 2] = rtb_Sum_j;
                      CheckPoints->data[(imo + CheckPoints->size[0]) - 2] = 0.0;
                      CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2]
                        = 0.0;
                      CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                        1.5707963267948966;
                      CheckPoints->data[imo - 1] = rtb_Sum_j;
                      CheckPoints->data[(imo + CheckPoints->size[0]) - 1] =
                        codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                      CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1]
                        = 0.0;
                      CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                        1.5707963267948966;
                    } else {
                      imo = (b_nrows + 1) << 1;
                      rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                        rtb_Switch;
                      CheckPoints->data[imo - 2] = rtb_Sum_j;
                      CheckPoints->data[(imo + CheckPoints->size[0]) - 2] =
                        codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                      CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2]
                        = 0.0;
                      CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                        -1.5707963267948966;
                      CheckPoints->data[imo - 1] = rtb_Sum_j;
                      CheckPoints->data[(imo + CheckPoints->size[0]) - 1] = 0.0;
                      CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1]
                        = 0.0;
                      CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                        -1.5707963267948966;
                    }
                  }

                  SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->
                    size[1];

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  dummyWayPoint->size[0] = 1;
                  dummyWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                    SequenceID_prev);

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  dummyWayPoint->data[0] = 0.0;
                  dummyWayPoint->data[1] = 0.0;
                  dummyWayPoint->data[2] = 0.0;
                  for (nrowx = 0; nrowx <= CheckPoints->size[0] - 2; nrowx++) {
                    LUp[0] = CheckPoints->data[nrowx];
                    LDp[0] = CheckPoints->data[nrowx + 1];
                    LUp[1] = CheckPoints->data[nrowx + CheckPoints->size[0]];
                    LDp[1] = CheckPoints->data[(nrowx + CheckPoints->size[0]) +
                      1];
                    LUp[2] = CheckPoints->data[nrowx + (CheckPoints->size[0] <<
                      1)];
                    LDp[2] = CheckPoints->data[(nrowx + (CheckPoints->size[0] <<
                      1)) + 1];
                    LUp[3] = CheckPoints->data[nrowx + CheckPoints->size[0] * 3];
                    LDp[3] = CheckPoints->data[(nrowx + CheckPoints->size[0] * 3)
                      + 1];
                    codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp,
                      100.0, segWayPoints);
                    SequenceID_prev = dummyWayPoint_0->size[0] *
                      dummyWayPoint_0->size[1];
                    dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                      segWayPoints->size[0];
                    dummyWayPoint_0->size[1] = 3;
                    codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                      SequenceID_prev);
                    b_nrows = dummyWayPoint->size[0];
                    for (imo = 0; imo < 3; imo++) {
                      for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                           SequenceID_prev++) {
                        dummyWayPoint_0->data[SequenceID_prev +
                          dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                          data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                      }
                    }

                    b_nrows = segWayPoints->size[0];
                    for (imo = 0; imo < 3; imo++) {
                      for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                           SequenceID_prev++) {
                        dummyWayPoint_0->data[(SequenceID_prev +
                          dummyWayPoint->size[0]) + dummyWayPoint_0->size[0] *
                          imo] = segWayPoints->data[SequenceID_prev +
                          segWayPoints->size[0] * imo];
                      }
                    }

                    SequenceID_prev = dummyWayPoint->size[0] *
                      dummyWayPoint->size[1];
                    dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                    dummyWayPoint->size[1] = 3;
                    codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                      SequenceID_prev);
                    b_nrows = dummyWayPoint_0->size[0] * 3;
                    for (imo = 0; imo < b_nrows; imo++) {
                      dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                    }
                  }

                  LUp[0] = CheckPoints->data[CheckPoints->size[0] - 1];
                  LDp[0] = CheckPoints->data[0];
                  LUp[1] = CheckPoints->data[(CheckPoints->size[0] +
                    CheckPoints->size[0]) - 1];
                  LDp[1] = CheckPoints->data[CheckPoints->size[0]];
                  LUp[2] = CheckPoints->data[(CheckPoints->size[0] +
                    (CheckPoints->size[0] << 1)) - 1];
                  LDp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
                  LUp[3] = CheckPoints->data[(CheckPoints->size[0] +
                    CheckPoints->size[0] * 3) - 1];
                  LDp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
                  codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                    segWayPoints);
                  SequenceID_prev = dummyWayPoint_0->size[0] *
                    dummyWayPoint_0->size[1];

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                    segWayPoints->size[0];
                  dummyWayPoint_0->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                    SequenceID_prev);

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  b_nrows = dummyWayPoint->size[0];
                  nrows = segWayPoints->size[0];
                  for (imo = 0; imo < 3; imo++) {
                    for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                         SequenceID_prev++) {
                      dummyWayPoint_0->data[SequenceID_prev +
                        dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                        data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                    }

                    for (SequenceID_prev = 0; SequenceID_prev < nrows;
                         SequenceID_prev++) {
                      dummyWayPoint_0->data[(SequenceID_prev +
                        dummyWayPoint->size[0]) + dummyWayPoint_0->size[0] * imo]
                        = segWayPoints->data[SequenceID_prev +
                        segWayPoints->size[0] * imo];
                    }
                  }

                  SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->
                    size[1];

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                  dummyWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                    SequenceID_prev);

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  b_nrows = dummyWayPoint_0->size[0] * 3;
                  for (imo = 0; imo < b_nrows; imo++) {
                    dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                  }

                  SequenceID_prev = dummyWayPoint_2->size[0] *
                    dummyWayPoint_2->size[1];

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  dummyWayPoint_2->size[0] = dummyWayPoint->size[0];
                  dummyWayPoint_2->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_2,
                    SequenceID_prev);

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  b_nrows = dummyWayPoint->size[0] * dummyWayPoint->size[1] - 1;
                  for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_2->data[SequenceID_prev] = dummyWayPoint->
                      data[SequenceID_prev];
                  }

                  codegenReal2Mission_repmat(dummyWayPoint_2, std::ceil(10240.0 /
                    static_cast<real_T>(dummyWayPoint->size[0])), dummyWayPoint);
                  nrowx = dummyWayPoint->size[0] - 2;
                  nrows = dummyWayPoint->size[0] - 1;

                  // Reshape: '<S21>/Reshape2Row' incorporates:
                  //   Memory: '<S21>/MemoryPrevRelPos'

                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                    codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[1];
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                    codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[0];
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                    codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[2];

                  // Product: '<S102>/RotateRelPrevPos' incorporates:
                  //   MATLABSystem: '<S102>/RotateATMissionHdg'

                  rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf
                    (rtb_TmpSignalConversionAtRotateATMissionHdgInport1, out, ct);

                  // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
                  //   Product: '<S102>/RotateRelPrevPos'

                  for (imo = 0; imo <= nrowx; imo++) {
                    dummyWayPoint->data[imo] = dummyWayPoint->data[imo + 1];
                  }

                  LDp[0] = ct[0];
                  for (imo = 0; imo <= nrowx; imo++) {
                    dummyWayPoint->data[imo + dummyWayPoint->size[0]] =
                      dummyWayPoint->data[(imo + dummyWayPoint->size[0]) + 1];
                  }

                  LDp[1] = ct[1];
                  for (imo = 0; imo <= nrowx; imo++) {
                    dummyWayPoint->data[imo + (dummyWayPoint->size[0] << 1)] =
                      dummyWayPoint->data[(imo + (dummyWayPoint->size[0] << 1))
                      + 1];
                  }

                  LDp[2] = ct[2];
                  LDp[3] = 1.5707963267948966;
                  LUp[0] = CheckPoints->data[0];
                  LUp[1] = CheckPoints->data[CheckPoints->size[0]];
                  LUp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
                  LUp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
                  codegenReal2Mission_genSegWP_i(&connectionObj, LDp, LUp, 100.0,
                    segWayPoints);
                  if (1 > nrows) {
                    nrowx = -1;
                  }

                  SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  initWayPoint->size[0] = (segWayPoints->size[0] + nrowx) + 1;
                  initWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                    SequenceID_prev);

                  // MATLAB Function: '<S102>/WayPointGenerator'
                  b_nrows = segWayPoints->size[0];
                  for (imo = 0; imo < 3; imo++) {
                    for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                         SequenceID_prev++) {
                      initWayPoint->data[SequenceID_prev + initWayPoint->size[0]
                        * imo] = segWayPoints->data[SequenceID_prev +
                        segWayPoints->size[0] * imo];
                    }

                    for (SequenceID_prev = 0; SequenceID_prev <= nrowx;
                         SequenceID_prev++) {
                      initWayPoint->data[(SequenceID_prev + segWayPoints->size[0])
                        + initWayPoint->size[0] * imo] = dummyWayPoint->
                        data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                    }

                    for (SequenceID_prev = 0; SequenceID_prev < 10240;
                         SequenceID_prev++) {
                      codegenReal2Mission_B.WayPoint[SequenceID_prev + 10240 *
                        imo] = initWayPoint->data[SequenceID_prev +
                        initWayPoint->size[0] * imo];
                    }
                  }

                  for (imo = 0; imo < 10240; imo++) {
                    // MATLAB Function: '<S102>/biasWayPoint'
                    codegenReal2Mission_B.rtb_WayPoint_m[imo] =
                      codegenReal2Mission_B.WayPoint[imo] +
                      codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon;
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240] =
                      codegenReal2Mission_B.WayPoint[imo + 10240];
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480] =
                      codegenReal2Mission_B.WayPoint[imo + 20480];

                    // Product: '<S102>/RotateIndivWayPoint' incorporates:
                    //   MATLABSystem: '<S102>/RotateATMissionHdg'

                    for (SequenceID_prev = 0; SequenceID_prev < 3;
                         SequenceID_prev++) {
                      b_nrows = imo + 10240 * SequenceID_prev;
                      codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                      codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out
                        [3 * SequenceID_prev] *
                        codegenReal2Mission_B.rtb_WayPoint_m[imo];
                      codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out
                        [3 * SequenceID_prev + 1] *
                        codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                      codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out
                        [3 * SequenceID_prev + 2] *
                        codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
                    }
                  }

                  // MATLAB Function: '<S102>/biasNED' incorporates:
                  //   Product: '<S102>/RotateIndivWayPoint'
                  //   Reshape: '<S102>/ReshapeRowVec'

                  for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                    SequenceID_prev = b_nrows * 10240;
                    for (imo = 0; imo < 10240; imo++) {
                      codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                        rtb_ReshapeRowVec[b_nrows];
                    }
                  }

                  for (imo = 0; imo < 10240; imo++) {
                    codegenReal2Mission_B.nedWayPoint_a[imo] =
                      codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                      codegenReal2Mission_B.WayPoint[imo];
                    codegenReal2Mission_B.nedWayPoint_a[imo + 10240] =
                      codegenReal2Mission_B.WayPoint[imo + 10240] +
                      codegenReal2Mission_B.RotateIndivWayPoint[imo];
                    codegenReal2Mission_B.nedWayPoint_a[imo + 20480] =
                      codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                      codegenReal2Mission_B.WayPoint[imo + 20480];
                  }
                }

                // End of Outputs for SubSystem: '<S21>/WayPointGenerator'

                // BusCreator: '<S21>/GuidanceCMDBusCreator' incorporates:
                //   Constant: '<S21>/LookAheadDis'
                //   MATLAB Function: '<S102>/WayPointGenerator'
                //   MATLABSystem: '<S21>/Waypoint Follower'
                //   Memory: '<S21>/MemoryTriggerWP'
                //   Memory: '<S2>/DelayPose'

                codegenReal2Mission_WaypointFollowerBase_stepInternal
                  (&codegenReal2Mission_DW.obj_i,
                   codegenReal2Mission_DW.DelayPose_PreviousInput,
                   codegenReal2Mission_B.nedWayPoint_a, 200.0, rtb_ReshapeRowVec,
                   &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
                   &lookaheadFlag, &rtb_Switch, &status_0);

                // Merge: '<S14>/ Merge ' incorporates:
                //   DataTypeConversion: '<S21>/Cast To Double'
                //   MATLABSystem: '<S21>/Waypoint Follower'

                codegenReal2Mission_B.thisTaskStatus = status_0;

                // BusCreator: '<S21>/GuidanceCMDBusCreator' incorporates:
                //   DataTypeConversion: '<S21>/Param4'
                //   Gain: '<S21>/Down2Height'
                //   MATLABSystem: '<S21>/Waypoint Follower'

                codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
                codegenReal2Mission_B.GuidanceCmds.AirSpeed =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

                // Switch: '<S138>/Switch' incorporates:
                //   Bias: '<S138>/Bias'
                //   Bias: '<S138>/Bias1'
                //   Constant: '<S138>/Constant2'
                //   Constant: '<S139>/Constant'
                //   DataStoreRead: '<S21>/PrevLatitudeGCS'
                //   Math: '<S138>/Math Function1'
                //   RelationalOperator: '<S139>/Compare'

                if (rtb_Switch_fe > 180.0) {
                  rtb_Switch_fe = rt_modd_snf(LatitudeGCS + 180.0, 360.0) +
                    -180.0;
                } else {
                  rtb_Switch_fe = LatitudeGCS;
                }

                // Abs: '<S135>/Abs1'
                rtb_Abs1 = std::abs(rtb_Switch_fe);

                // Switch: '<S135>/Switch' incorporates:
                //   Bias: '<S135>/Bias'
                //   Bias: '<S135>/Bias1'
                //   Constant: '<S126>/Constant'
                //   Constant: '<S126>/Constant1'
                //   Constant: '<S137>/Constant'
                //   Gain: '<S135>/Gain'
                //   Product: '<S135>/Divide1'
                //   RelationalOperator: '<S137>/Compare'
                //   Switch: '<S126>/Switch1'

                if (rtb_Abs1 > 90.0) {
                  // Signum: '<S135>/Sign1'
                  if (rtb_Switch_fe < 0.0) {
                    rtb_Switch_fe = -1.0;
                  } else if (rtb_Switch_fe > 0.0) {
                    rtb_Switch_fe = 1.0;
                  } else if (rtb_Switch_fe == 0.0) {
                    rtb_Switch_fe = 0.0;
                  } else {
                    rtb_Switch_fe = (rtNaN);
                  }

                  rtb_Switch_fe *= -(rtb_Abs1 + -90.0) + 90.0;
                  imo = 180;
                } else {
                  imo = 0;
                }

                // Sum: '<S126>/Sum' incorporates:
                //   DataStoreRead: '<S21>/PrevLongitudeGCS'

                rtb_Gain1 = static_cast<real_T>(imo) + LongitudeGCS;

                // Sum: '<S101>/Sum1'
                rtb_Abs1 = fracSecs - rtb_Switch_fe;

                // Switch: '<S132>/Switch' incorporates:
                //   Abs: '<S132>/Abs'
                //   Bias: '<S132>/Bias'
                //   Bias: '<S132>/Bias1'
                //   Constant: '<S132>/Constant2'
                //   Constant: '<S133>/Constant'
                //   Math: '<S132>/Math Function1'
                //   RelationalOperator: '<S133>/Compare'

                if (std::abs(rtb_Abs1) > 180.0) {
                  rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                // Abs: '<S129>/Abs1'
                fracSecs = std::abs(rtb_Abs1);

                // Switch: '<S129>/Switch' incorporates:
                //   Bias: '<S129>/Bias'
                //   Bias: '<S129>/Bias1'
                //   Constant: '<S125>/Constant'
                //   Constant: '<S125>/Constant1'
                //   Constant: '<S131>/Constant'
                //   Gain: '<S129>/Gain'
                //   Product: '<S129>/Divide1'
                //   RelationalOperator: '<S131>/Compare'
                //   Switch: '<S125>/Switch1'

                if (fracSecs > 90.0) {
                  // Signum: '<S129>/Sign1'
                  if (rtb_Abs1 < 0.0) {
                    rtb_Abs1 = -1.0;
                  } else if (rtb_Abs1 > 0.0) {
                    rtb_Abs1 = 1.0;
                  } else if (rtb_Abs1 == 0.0) {
                    rtb_Abs1 = 0.0;
                  } else {
                    rtb_Abs1 = (rtNaN);
                  }

                  rtb_Abs1 *= -(fracSecs + -90.0) + 90.0;
                  imo = 180;
                } else {
                  imo = 0;
                }

                // Switch: '<S136>/Switch' incorporates:
                //   Abs: '<S136>/Abs'
                //   Bias: '<S136>/Bias'
                //   Bias: '<S136>/Bias1'
                //   Constant: '<S136>/Constant2'
                //   Constant: '<S140>/Constant'
                //   Math: '<S136>/Math Function1'
                //   RelationalOperator: '<S140>/Compare'

                if (std::abs(rtb_Gain1) > 180.0) {
                  rtb_Gain1 = rt_modd_snf(rtb_Gain1 + 180.0, 360.0) + -180.0;
                }

                // Sum: '<S125>/Sum' incorporates:
                //   Sum: '<S101>/Sum1'

                rtb_Gain1 = (second - rtb_Gain1) + static_cast<real_T>(imo);

                // UnitConversion: '<S143>/Unit Conversion'
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch_fe *= 0.017453292519943295;

                // Trigonometry: '<S144>/Trigonometric Function1'
                second = std::sin(rtb_Switch_fe);

                // Sum: '<S144>/Sum1' incorporates:
                //   Constant: '<S144>/Constant'
                //   Product: '<S144>/Product1'

                second = 1.0 - codegenReal2Mission_ConstB.sqrt_cp *
                  codegenReal2Mission_ConstB.sqrt_cp * second * second;

                // Product: '<S142>/Product1' incorporates:
                //   Constant: '<S142>/Constant1'
                //   Sqrt: '<S142>/sqrt'

                fracSecs = 6.378137E+6 / std::sqrt(second);

                // Product: '<S142>/Product4' incorporates:
                //   Trigonometry: '<S142>/Trigonometric Function'

                rtb_Switch_fe = fracSecs * std::cos(rtb_Switch_fe);

                // Product: '<S127>/dNorth' incorporates:
                //   Constant: '<S142>/Constant2'
                //   Product: '<S142>/Product3'
                //   Trigonometry: '<S142>/Trigonometric Function1'
                //   UnitConversion: '<S128>/Unit Conversion'

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                fracSecs = 0.017453292519943295 * rtb_Abs1 / rt_atan2d_snf(1.0,
                  fracSecs * codegenReal2Mission_ConstB.Sum1_h / second);

                // Switch: '<S130>/Switch' incorporates:
                //   Abs: '<S130>/Abs'
                //   Bias: '<S130>/Bias'
                //   Bias: '<S130>/Bias1'
                //   Constant: '<S130>/Constant2'
                //   Constant: '<S134>/Constant'
                //   Math: '<S130>/Math Function1'
                //   RelationalOperator: '<S134>/Compare'

                if (std::abs(rtb_Gain1) > 180.0) {
                  rtb_Gain1 = rt_modd_snf(rtb_Gain1 + 180.0, 360.0) + -180.0;
                }

                // Product: '<S127>/dEast' incorporates:
                //   Constant: '<S142>/Constant3'
                //   Trigonometry: '<S142>/Trigonometric Function2'
                //   UnitConversion: '<S128>/Unit Conversion'

                second = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe) *
                  (0.017453292519943295 * rtb_Gain1);

                // Sum: '<S127>/Sum2' incorporates:
                //   Product: '<S127>/x*cos'
                //   Product: '<S127>/y*sin'

                rtb_Switch_fe = second * 0.0 + fracSecs;

                // Sum: '<S127>/Sum3' incorporates:
                //   Product: '<S127>/x*sin'
                //   Product: '<S127>/y*cos'

                fracSecs = second - fracSecs * 0.0;

                // Merge: '<S14>/ Merge 3' incorporates:
                //   Bias: '<S21>/Rotate90deg'
                //   Constant: '<S21>/InitialFlightPathAngle'
                //   Constant: '<S21>/InitialRollAngle'
                //   Constant: '<S21>/InitialRollAngleRate'
                //   DataStoreRead: '<S21>/PrevAltitudeGCS'
                //   DataTypeConversion: '<S21>/Param4'
                //   Gain: '<S21>/PrevInverse'
                //   Product: '<S21>/FrontEast'
                //   Product: '<S21>/FrontNorth'
                //   Product: '<S21>/RightEast'
                //   Product: '<S21>/RightNorth'
                //   Reshape: '<S21>/Reshape'
                //   Sum: '<S101>/Sum'
                //   Sum: '<S21>/SumHeight'
                //   Sum: '<S21>/SumInitEast'
                //   Sum: '<S21>/SumInitNorth'
                //   Trigonometry: '<S21>/FrontCos'
                //   Trigonometry: '<S21>/FrontSin'
                //   Trigonometry: '<S21>/RightCos'
                //   Trigonometry: '<S21>/RightSin'

                codegenReal2Mission_B.InitialState[0] = (std::cos(rtb_Down2Up_e
                  + 1.5707963267948966) *
                  codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon +
                  rtb_Switch_fe) + std::cos(rtb_Down2Up_e) *
                  codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat;
                codegenReal2Mission_B.InitialState[1] = (std::sin(rtb_Down2Up_e)
                  * codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat
                  + fracSecs) + std::sin(rtb_Down2Up_e + 1.5707963267948966) *
                  codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon;
                codegenReal2Mission_B.InitialState[2] = (temp + -AltitudeGCS) +
                  codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;
                codegenReal2Mission_B.InitialState[3] =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
                codegenReal2Mission_B.InitialState[4] = rtb_Down2Up_e;
                codegenReal2Mission_B.InitialState[5] = 0.0;
                codegenReal2Mission_B.InitialState[6] = 0.0;
                codegenReal2Mission_B.InitialState[7] = 0.0;

                // Update for Memory: '<S21>/MemoryPrevRelPos' incorporates:
                //   DataStoreRead: '<S21>/PrevAltitudeGCS'
                //   Gain: '<S21>/PrevInverse'
                //   Sum: '<S101>/Sum'
                //   Sum: '<S21>/RelPrevPos'
                //   UnaryMinus: '<S101>/Ze2height'

                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[0] =
                  rtb_Switch_fe - rtb_Down_b;
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[1] =
                  fracSecs - b_shi;
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[2] =
                  -(temp + -AltitudeGCS) - check;

                // Update for Memory: '<S21>/MemoryTriggerWP' incorporates:
                //   Constant: '<S21>/TirggerWayPointGen'

                codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_k = 1.0;
              }
            } else if ((codegenReal2Mission_B.MemoryCurrentMission.MissionMode ==
                        3) ||
                       (codegenReal2Mission_B.MemoryCurrentMission.MissionMode ==
                        33)) {
              codegenReal2Mission_DW.is_GuidanceLogic =
                codegenReal2Mission_IN_RunWayNav;

              // Switch: '<S85>/Switch' incorporates:
              //   Abs: '<S85>/Abs'
              //   Bias: '<S85>/Bias'
              //   Bias: '<S85>/Bias1'
              //   Constant: '<S85>/Constant2'
              //   Constant: '<S86>/Constant'
              //   DataStoreRead: '<S20>/LatitudeGCS'
              //   Math: '<S85>/Math Function1'
              //   RelationalOperator: '<S86>/Compare'

              if (std::abs(LatitudeGCS) > 180.0) {
                fracSecs = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
              } else {
                fracSecs = LatitudeGCS;
              }

              // Abs: '<S82>/Abs1'
              rtb_Switch_fe = std::abs(fracSecs);

              // Switch: '<S82>/Switch' incorporates:
              //   Bias: '<S82>/Bias'
              //   Bias: '<S82>/Bias1'
              //   Constant: '<S73>/Constant'
              //   Constant: '<S73>/Constant1'
              //   Constant: '<S84>/Constant'
              //   Gain: '<S82>/Gain'
              //   Product: '<S82>/Divide1'
              //   RelationalOperator: '<S84>/Compare'
              //   Switch: '<S73>/Switch1'

              if (rtb_Switch_fe > 90.0) {
                // Signum: '<S82>/Sign1'
                if (fracSecs < 0.0) {
                  fracSecs = -1.0;
                } else if (fracSecs > 0.0) {
                  fracSecs = 1.0;
                } else if (fracSecs == 0.0) {
                  fracSecs = 0.0;
                } else {
                  fracSecs = (rtNaN);
                }

                fracSecs *= -(rtb_Switch_fe + -90.0) + 90.0;
                imo = 180;
              } else {
                imo = 0;
              }

              // Sum: '<S73>/Sum' incorporates:
              //   DataStoreRead: '<S20>/LongitudeGCS'

              second = static_cast<real_T>(imo) + LongitudeGCS;

              // Sum: '<S70>/Sum1'
              rtb_Abs1 =
                codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
                fracSecs;

              // Switch: '<S79>/Switch' incorporates:
              //   Abs: '<S79>/Abs'
              //   Bias: '<S79>/Bias'
              //   Bias: '<S79>/Bias1'
              //   Constant: '<S79>/Constant2'
              //   Constant: '<S80>/Constant'
              //   Math: '<S79>/Math Function1'
              //   RelationalOperator: '<S80>/Compare'

              if (std::abs(rtb_Abs1) > 180.0) {
                rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
              }

              // Abs: '<S76>/Abs1'
              rtb_Switch_fe = std::abs(rtb_Abs1);

              // Switch: '<S76>/Switch' incorporates:
              //   Bias: '<S76>/Bias'
              //   Bias: '<S76>/Bias1'
              //   Constant: '<S72>/Constant'
              //   Constant: '<S72>/Constant1'
              //   Constant: '<S78>/Constant'
              //   Gain: '<S76>/Gain'
              //   Product: '<S76>/Divide1'
              //   RelationalOperator: '<S78>/Compare'
              //   Switch: '<S72>/Switch1'

              if (rtb_Switch_fe > 90.0) {
                // Signum: '<S76>/Sign1'
                if (rtb_Abs1 < 0.0) {
                  rtb_Abs1 = -1.0;
                } else if (rtb_Abs1 > 0.0) {
                  rtb_Abs1 = 1.0;
                } else if (rtb_Abs1 == 0.0) {
                  rtb_Abs1 = 0.0;
                } else {
                  rtb_Abs1 = (rtNaN);
                }

                rtb_Switch_fe = (-(rtb_Switch_fe + -90.0) + 90.0) * rtb_Abs1;
                imo = 180;
              } else {
                rtb_Switch_fe = rtb_Abs1;
                imo = 0;
              }

              // Switch: '<S83>/Switch' incorporates:
              //   Abs: '<S83>/Abs'
              //   Bias: '<S83>/Bias'
              //   Bias: '<S83>/Bias1'
              //   Constant: '<S83>/Constant2'
              //   Constant: '<S87>/Constant'
              //   Math: '<S83>/Math Function1'
              //   RelationalOperator: '<S87>/Compare'

              if (std::abs(second) > 180.0) {
                second = rt_modd_snf(second + 180.0, 360.0) + -180.0;
              }

              // Sum: '<S72>/Sum' incorporates:
              //   Sum: '<S70>/Sum1'

              temp =
                (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon
                 - second) + static_cast<real_T>(imo);

              // UnitConversion: '<S75>/Unit Conversion'
              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              rtb_Abs1 = 0.017453292519943295 * rtb_Switch_fe;

              // UnitConversion: '<S90>/Unit Conversion'
              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              fracSecs *= 0.017453292519943295;

              // Trigonometry: '<S91>/Trigonometric Function1'
              second = std::sin(fracSecs);

              // Sum: '<S91>/Sum1' incorporates:
              //   Constant: '<S91>/Constant'
              //   Product: '<S91>/Product1'

              second = 1.0 - codegenReal2Mission_ConstB.sqrt_o *
                codegenReal2Mission_ConstB.sqrt_o * second * second;

              // Product: '<S89>/Product1' incorporates:
              //   Constant: '<S89>/Constant1'
              //   Sqrt: '<S89>/sqrt'

              rtb_Switch_fe = 6.378137E+6 / std::sqrt(second);

              // Product: '<S74>/dNorth' incorporates:
              //   Constant: '<S89>/Constant2'
              //   Product: '<S89>/Product3'
              //   Trigonometry: '<S89>/Trigonometric Function1'

              second = rtb_Abs1 / rt_atan2d_snf(1.0, rtb_Switch_fe *
                codegenReal2Mission_ConstB.Sum1_j / second);

              // Switch: '<S77>/Switch' incorporates:
              //   Abs: '<S77>/Abs'
              //   Bias: '<S77>/Bias'
              //   Bias: '<S77>/Bias1'
              //   Constant: '<S77>/Constant2'
              //   Constant: '<S81>/Constant'
              //   Math: '<S77>/Math Function1'
              //   RelationalOperator: '<S81>/Compare'

              // Unit Conversion - from: deg to: rad
              // Expression: output = (0.0174533*input) + (0)
              if (std::abs(temp) > 180.0) {
                temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
              }

              // Product: '<S74>/dEast' incorporates:
              //   Constant: '<S89>/Constant3'
              //   Product: '<S89>/Product4'
              //   Trigonometry: '<S89>/Trigonometric Function'
              //   Trigonometry: '<S89>/Trigonometric Function2'
              //   UnitConversion: '<S75>/Unit Conversion'

              rtb_Switch_fe = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe * std::cos
                (fracSecs)) * (0.017453292519943295 * temp);

              // Gain: '<S69>/Gain1'
              fracSecs = 0.017453292519943295 *
                codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

              // Outputs for Triggered SubSystem: '<S20>/WayPointGenerator' incorporates:
              //   TriggerPort: '<S71>/Trigger'

              zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                                 &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE_o,
                                 (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n));
              if (zcEvent != NO_ZCEVENT) {
                // Product: '<S71>/IndivRunwayRotAng' incorporates:
                //   DataTypeConversion: '<S20>/Param2'
                //   DataTypeConversion: '<S20>/Param5'
                //   Gain: '<S94>/Gain1'

                temp = 0.017453292519943295 *
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param2 *
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param5;

                // MATLAB Function: '<S71>/WayPointGenerator' incorporates:
                //   DataTypeConversion: '<S20>/Param3'

                codegenReal2Mission_uavDubinsConnection_uavDubinsConnection
                  (&connectionObj);
                LUp[0] = 0.0;
                rtb_Abs1 =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param3 / 2.0;
                LUp[1] = rtb_Abs1;
                LUp[2] = 0.0;
                LUp[3] = 1.5707963267948966;
                LDp[0] = 0.0;
                rtb_Down_b = -static_cast<real_T>
                  (codegenReal2Mission_B.MemoryCurrentMission.params.Param3) /
                  2.0;
                LDp[1] = rtb_Down_b;
                LDp[2] = 0.0;
                LDp[3] = 1.5707963267948966;
                codegenReal2Mission_uavDubinsConnection_connect(&connectionObj,
                  LUp, LDp, codegenReal2Mission_B.pathSegObj.data,
                  &codegenReal2Mission_B.pathSegObj.size, a__1_data,
                  &SequenceID_prev);
                codegenReal2Mission_uavDubinsPathSegment_interpolate
                  (codegenReal2Mission_B.pathSegObj.data[0].StartPose,
                   codegenReal2Mission_B.pathSegObj.data[0].GoalPose,
                   codegenReal2Mission_B.pathSegObj.data[0].FlightPathAngle,
                   codegenReal2Mission_B.pathSegObj.data[0].AirSpeed,
                   codegenReal2Mission_B.pathSegObj.data[0].MinTurningRadius,
                   codegenReal2Mission_B.pathSegObj.data[0].HelixRadius,
                   codegenReal2Mission_B.pathSegObj.data[0].MotionTypes,
                   codegenReal2Mission_B.pathSegObj.data[0].MotionLengths,
                   codegenReal2Mission_B.pathSegObj.data[0].Length,
                   codegenReal2Mission_B.pathSegObj.data[0].Length / 2.0,
                   midpose_data, midpose_size);
                rtb_startPose[0] = 0.0;
                b_shi = (codegenReal2Mission_B.pathSegObj.data[0].Length +
                         codegenReal2Mission_B.MemoryCurrentMission.params.Param3)
                  / 3.0 - codegenReal2Mission_B.pathSegObj.data[0].Length / 2.0;
                rtb_startPose[1] = rtb_Abs1 - b_shi;
                rtb_startPose[2] = 0.0;
                rtb_startPose[3] = 1.5707963267948966;
                ende[0] = 0.0;
                ende[1] = b_shi + rtb_Down_b;
                ende[2] = 0.0;
                ende[3] = 1.5707963267948966;
                SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

                // MATLAB Function: '<S71>/WayPointGenerator'
                initWayPoint->size[0] = 1;
                initWayPoint->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                  SequenceID_prev);

                // MATLAB Function: '<S71>/WayPointGenerator' incorporates:
                //   Constant: '<S71>/Three'
                //   DataTypeConversion: '<S71>/Cast To Double'
                //   Math: '<S71>/ModRunWayPose'

                initWayPoint->data[0] = 0.0;
                initWayPoint->data[1] = 0.0;
                initWayPoint->data[2] = 0.0;
                switch (static_cast<int32_T>(rt_modd_snf(static_cast<real_T>
                          (codegenReal2Mission_B.MemoryCurrentMission.FormationPos),
                          3.0))) {
                 case 0:
                  codegenReal2Mission_genSegWP(&connectionObj, rtb_startPose,
                    LUp, 100.0, segWayPoints);
                  SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
                  initWayPoint->size[0] = segWayPoints->size[0] + 1;
                  initWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                    SequenceID_prev);
                  b_nrows = segWayPoints->size[0];
                  for (imo = 0; imo < 3; imo++) {
                    initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                    for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                         SequenceID_prev++) {
                      initWayPoint->data[(SequenceID_prev + initWayPoint->size[0]
                                          * imo) + 1] = segWayPoints->
                        data[SequenceID_prev + segWayPoints->size[0] * imo];
                    }
                  }
                  break;

                 case 1:
                  rtb_startPose[0] = midpose_data[0];
                  rtb_startPose[1] = midpose_data[midpose_size[0]];
                  rtb_startPose[2] = midpose_data[midpose_size[0] << 1];
                  rtb_startPose[3] = midpose_data[midpose_size[0] * 3];
                  codegenReal2Mission_genSegWP(&connectionObj, &midpose_data[0],
                    LDp, 100.0, segWayPoints);
                  SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
                  initWayPoint->size[0] = segWayPoints->size[0] + 1;
                  initWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                    SequenceID_prev);
                  b_nrows = segWayPoints->size[0];
                  for (imo = 0; imo < 3; imo++) {
                    initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                    for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                         SequenceID_prev++) {
                      initWayPoint->data[(SequenceID_prev + initWayPoint->size[0]
                                          * imo) + 1] = segWayPoints->
                        data[SequenceID_prev + segWayPoints->size[0] * imo];
                    }
                  }
                  break;

                 case 2:
                  rtb_startPose[0] = 0.0;
                  rtb_startPose[1] = ende[1];
                  rtb_startPose[2] = 0.0;
                  rtb_startPose[3] = 1.5707963267948966;
                  codegenReal2Mission_genSegWP(&connectionObj, ende, LUp, 100.0,
                    segWayPoints);
                  SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];
                  initWayPoint->size[0] = segWayPoints->size[0] + 1;
                  initWayPoint->size[1] = 3;
                  codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                    SequenceID_prev);
                  b_nrows = segWayPoints->size[0];
                  for (imo = 0; imo < 3; imo++) {
                    initWayPoint->data[initWayPoint->size[0] * imo] = 0.0;
                    for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                         SequenceID_prev++) {
                      initWayPoint->data[(SequenceID_prev + initWayPoint->size[0]
                                          * imo) + 1] = segWayPoints->
                        data[SequenceID_prev + segWayPoints->size[0] * imo];
                    }
                  }
                  break;

                 default:
                  rtb_startPose[0] = 0.0;
                  rtb_startPose[1] = 0.0;
                  rtb_startPose[2] = 0.0;
                  rtb_startPose[3] = 0.0;
                  break;
                }

                codegenReal2Mission_genSegWP(&connectionObj, LUp, LDp, 100.0,
                  segWayPoints);
                SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

                // MATLAB Function: '<S71>/WayPointGenerator'
                dummyWayPoint->size[0] = segWayPoints->size[0] + 1;
                dummyWayPoint->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                  SequenceID_prev);

                // MATLAB Function: '<S71>/WayPointGenerator'
                b_nrows = segWayPoints->size[0];
                for (imo = 0; imo < 3; imo++) {
                  dummyWayPoint->data[dummyWayPoint->size[0] * imo] = 0.0;
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint->data[(SequenceID_prev + dummyWayPoint->size[0]
                                         * imo) + 1] = segWayPoints->
                      data[SequenceID_prev + segWayPoints->size[0] * imo];
                  }
                }

                codegenReal2Mission_genSegWP(&connectionObj, LDp, LUp, 100.0,
                  segWayPoints);
                SequenceID_prev = dummyWayPoint_0->size[0] *
                  dummyWayPoint_0->size[1];

                // MATLAB Function: '<S71>/WayPointGenerator'
                dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                  segWayPoints->size[0];
                dummyWayPoint_0->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                  SequenceID_prev);

                // MATLAB Function: '<S71>/WayPointGenerator'
                b_nrows = dummyWayPoint->size[0];
                nrows = segWayPoints->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[SequenceID_prev +
                      dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                      data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                  }

                  for (SequenceID_prev = 0; SequenceID_prev < nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->
                      size[0]) + dummyWayPoint_0->size[0] * imo] =
                      segWayPoints->data[SequenceID_prev + segWayPoints->size[0]
                      * imo];
                  }
                }

                SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

                // MATLAB Function: '<S71>/WayPointGenerator'
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                  SequenceID_prev);

                // MATLAB Function: '<S71>/WayPointGenerator'
                b_nrows = dummyWayPoint_0->size[0] * 3;
                for (imo = 0; imo < b_nrows; imo++) {
                  dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                }

                nrowx = dummyWayPoint->size[0] - 2;
                nrows = dummyWayPoint->size[0] - 1;
                for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
                  dummyWayPoint->data[b_nrows] = dummyWayPoint->data[b_nrows + 1];
                }

                for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
                  dummyWayPoint->data[b_nrows + dummyWayPoint->size[0]] =
                    dummyWayPoint->data[(b_nrows + dummyWayPoint->size[0]) + 1];
                }

                for (b_nrows = 0; b_nrows <= nrowx; b_nrows++) {
                  dummyWayPoint->data[b_nrows + (dummyWayPoint->size[0] << 1)] =
                    dummyWayPoint->data[(b_nrows + (dummyWayPoint->size[0] << 1))
                    + 1];
                }

                if (1 > nrows) {
                  nrowx = -1;
                  imo = -1;
                } else {
                  imo = nrowx;
                }

                b_nrows = imo + 1;
                SequenceID_prev = dummyWayPoint_0->size[0] *
                  dummyWayPoint_0->size[1];

                // MATLAB Function: '<S71>/WayPointGenerator'
                dummyWayPoint_0->size[0] = nrowx + 1;
                dummyWayPoint_0->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                  SequenceID_prev);

                // MATLAB Function: '<S71>/WayPointGenerator'
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[SequenceID_prev +
                      dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                      data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                  }
                }

                codegenReal2Mission_repmat(dummyWayPoint_0, std::ceil(10240.0 /
                  static_cast<real_T>(nrowx + 1)), dummyWayPoint);
                if (2 > initWayPoint->size[0]) {
                  k = -1;
                  b = -1;
                } else {
                  k = 0;
                  b = initWayPoint->size[0] - 1;
                }

                // Bias: '<S71>/Bias' incorporates:
                //   Sum: '<S71>/Sum'

                codegenReal2Mission_B.Bias = ((fracSecs + temp) + rtb_startPose
                  [3]) + -1.5707963267948966;

                // Gain: '<S71>/InterLayerDis' incorporates:
                //   Constant: '<S71>/Three'
                //   DataTypeConversion: '<S20>/Param5'
                //   Math: '<S71>/ModRunWayLayer'

                rtb_Abs1 = 15.0 * rt_modd_snf(static_cast<real_T>
                  (codegenReal2Mission_B.MemoryCurrentMission.params.Param5),
                  3.0);

                // Reshape: '<S71>/Reshape' incorporates:
                //   Constant: '<S71>/Zero'
                //   DataTypeConversion: '<S20>/Param1'

                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = 0.0;
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] = rtb_Abs1;

                // Reshape: '<S71>/ReshapeRowVec' incorporates:
                //   DataStoreRead: '<S20>/AltitudeGCS'
                //   Gain: '<S20>/inverse'
                //   Product: '<S74>/x*cos'
                //   Product: '<S74>/x*sin'
                //   Product: '<S74>/y*cos'
                //   Product: '<S74>/y*sin'
                //   Reshape: '<S71>/ReshapeRowVecStartpose'
                //   Sum: '<S70>/Sum'
                //   Sum: '<S74>/Sum2'
                //   Sum: '<S74>/Sum3'
                //   UnaryMinus: '<S70>/Ze2height'

                rtb_ReshapeRowVec[0] = rtb_Switch_fe * 0.0 + second;
                rtb_ReshapeRowVec[1] = rtb_Switch_fe - second * 0.0;
                rtb_ReshapeRowVec[2] =
                  -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt
                    + -AltitudeGCS);

                // MATLABSystem: '<S71>/RotateATMissionHdg' incorporates:
                //   SignalConversion generated from: '<S71>/RotateATMissionHdg'

                ct[0] = std::cos(fracSecs);
                turnVector[0] = std::sin(fracSecs);
                out[0] = ct[0];
                out[3] = 0.0 * ct[0] - turnVector[0];
                out[6] = 0.0 * ct[0] + turnVector[0] * 0.0;
                out[1] = turnVector[0];
                out[4] = 0.0 * turnVector[0] + ct[0];
                out[7] = 0.0 * turnVector[0] - ct[0] * 0.0;
                out[2] = -0.0;
                out[5] = 0.0;
                out[8] = 1.0;

                // SignalConversion generated from: '<S71>/RotateATRunWayHdg' incorporates:
                //   Constant: '<S71>/Zero'

                turnVector[0] = temp;
                turnVector[1] = 0.0;
                turnVector[2] = 0.0;

                // MATLABSystem: '<S71>/RotateATRunWayHdg' incorporates:
                //   SignalConversion generated from: '<S71>/RotateATRunWayHdg'

                ct[0] = temp;
                ct[1] = 0.0;
                ct[2] = 0.0;

                // MATLAB Function: '<S71>/WayPointGenerator'
                b_nrows = b - k;
                SequenceID_prev = segWayPoints->size[0] * segWayPoints->size[1];

                // MATLAB Function: '<S71>/WayPointGenerator'
                segWayPoints->size[0] = b_nrows + dummyWayPoint->size[0];
                segWayPoints->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(segWayPoints,
                  SequenceID_prev);

                // MATLAB Function: '<S71>/WayPointGenerator'
                nrows = dummyWayPoint->size[0];
                for (nrowx = 0; nrowx < 3; nrowx++) {
                  // MATLAB Function: '<S71>/minus' incorporates:
                  //   Reshape: '<S71>/Reshape'

                  SequenceID_prev = nrowx * 10240;
                  for (imo = 0; imo < 10240; imo++) {
                    codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                      rtb_TmpSignalConversionAtRotateATMissionHdgInport1[nrowx];
                  }

                  // MATLAB Function: '<S71>/WayPointGenerator'
                  for (imo = 0; imo < b_nrows; imo++) {
                    segWayPoints->data[imo + segWayPoints->size[0] * nrowx] =
                      initWayPoint->data[((k + imo) + initWayPoint->size[0] *
                                          nrowx) + 1];
                  }

                  for (imo = 0; imo < nrows; imo++) {
                    segWayPoints->data[((imo + b) - k) + segWayPoints->size[0] *
                      nrowx] = dummyWayPoint->data[imo + dummyWayPoint->size[0] *
                      nrowx];
                  }

                  // MATLAB Function: '<S71>/minus' incorporates:
                  //   MATLAB Function: '<S71>/WayPointGenerator'

                  for (imo = 0; imo < 10240; imo++) {
                    initWayPoint_tmp = 10240 * nrowx + imo;
                    codegenReal2Mission_B.rtb_WayPoint_m[initWayPoint_tmp] =
                      segWayPoints->data[imo + segWayPoints->size[0] * nrowx] -
                      codegenReal2Mission_B.WayPoint[initWayPoint_tmp];
                  }

                  ct[nrowx] = std::cos(ct[nrowx]);
                  turnVector[nrowx] = std::sin(turnVector[nrowx]);
                }

                // MATLABSystem: '<S71>/RotateATRunWayHdg'
                out_0[0] = ct[0] * ct[1];
                rtb_Switch_fe = turnVector[1] * turnVector[2];
                out_0[3] = rtb_Switch_fe * ct[0] - turnVector[0] * ct[2];
                second = turnVector[1] * ct[2];
                out_0[6] = second * ct[0] + turnVector[0] * turnVector[2];
                out_0[1] = turnVector[0] * ct[1];
                out_0[4] = rtb_Switch_fe * turnVector[0] + ct[0] * ct[2];
                out_0[7] = second * turnVector[0] - ct[0] * turnVector[2];
                out_0[2] = -turnVector[1];
                out_0[5] = ct[1] * turnVector[2];
                out_0[8] = ct[1] * ct[2];
                for (imo = 0; imo < 10240; imo++) {
                  // Product: '<S71>/RotateRunway' incorporates:
                  //   MATLABSystem: '<S71>/RotateATRunWayHdg'

                  for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev
                       ++) {
                    initWayPoint_tmp = imo + 10240 * SequenceID_prev;
                    codegenReal2Mission_B.WayPoint[initWayPoint_tmp] = 0.0;
                    codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                      SequenceID_prev] *
                      codegenReal2Mission_B.rtb_WayPoint_m[imo];
                    codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                      SequenceID_prev + 1] *
                      codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                    codegenReal2Mission_B.WayPoint[initWayPoint_tmp] += out_0[3 *
                      SequenceID_prev + 2] *
                      codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
                  }

                  // Product: '<S71>/RotateIndivWayPoint' incorporates:
                  //   MATLABSystem: '<S71>/RotateATMissionHdg'

                  for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev
                       ++) {
                    b_nrows = imo + 10240 * SequenceID_prev;
                    codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                    codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                      SequenceID_prev] * codegenReal2Mission_B.WayPoint[imo];
                    codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                      SequenceID_prev + 1] * codegenReal2Mission_B.WayPoint[imo
                      + 10240];
                    codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                      SequenceID_prev + 2] * codegenReal2Mission_B.WayPoint[imo
                      + 20480];
                  }
                }

                // Sum: '<S71>/BiasStartPose' incorporates:
                //   DataTypeConversion: '<S20>/Param1'

                rtb_Switch_fe = rtb_startPose[0];
                second = rtb_startPose[1] -
                  codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                rtb_Abs1 = rtb_startPose[2] - rtb_Abs1;

                // Product: '<S71>/RotateRunwayStartpose' incorporates:
                //   MATLABSystem: '<S71>/RotateATRunWayHdg'

                for (imo = 0; imo < 3; imo++) {
                  rtb_TmpSignalConversionAtRotateATMissionHdgInport1[imo] =
                    out_0[3 * imo + 2] * rtb_Abs1 + (out_0[3 * imo + 1] * second
                    + out_0[3 * imo] * rtb_Switch_fe);
                }

                for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                  // MATLAB Function: '<S71>/biasNED' incorporates:
                  //   Reshape: '<S71>/ReshapeRowVec'

                  SequenceID_prev = b_nrows * 10240;
                  for (imo = 0; imo < 10240; imo++) {
                    codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                      rtb_ReshapeRowVec[b_nrows];
                  }

                  ct[b_nrows] = out[3 * b_nrows + 2] *
                    rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] +
                    (out[3 * b_nrows + 1] *
                     rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] +
                     out[3 * b_nrows] *
                     rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0]);
                }

                // MATLAB Function: '<S71>/biasNED' incorporates:
                //   MATLABSystem: '<S71>/RotateATMissionHdg'
                //   Product: '<S71>/RotateIndivWayPoint'
                //   Product: '<S71>/RotateIndivWayPointStartpose'

                for (imo = 0; imo < 10240; imo++) {
                  codegenReal2Mission_B.nedWayPoint_m[imo] =
                    codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                    codegenReal2Mission_B.WayPoint[imo];
                  codegenReal2Mission_B.nedWayPoint_m[imo + 10240] =
                    codegenReal2Mission_B.WayPoint[imo + 10240] +
                    codegenReal2Mission_B.RotateIndivWayPoint[imo];
                  codegenReal2Mission_B.nedWayPoint_m[imo + 20480] =
                    codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                    codegenReal2Mission_B.WayPoint[imo + 20480];
                }

                // MATLAB Function: '<S71>/biasNEDstartpose' incorporates:
                //   Product: '<S71>/RotateIndivWayPointStartpose'
                //   Reshape: '<S71>/ReshapeRowVecStartpose'

                codegenReal2Mission_B.nedWayPoint_d[0] = rtb_ReshapeRowVec[0] +
                  ct[1];
                codegenReal2Mission_B.nedWayPoint_d[1] = ct[0] +
                  rtb_ReshapeRowVec[1];
                codegenReal2Mission_B.nedWayPoint_d[2] = ct[2] +
                  rtb_ReshapeRowVec[2];
              }

              // End of Outputs for SubSystem: '<S20>/WayPointGenerator'

              // BusCreator: '<S20>/GuidanceCMDBusCreator' incorporates:
              //   Constant: '<S20>/LookAheadDis'
              //   MATLAB Function: '<S71>/WayPointGenerator'
              //   MATLABSystem: '<S20>/Waypoint Follower'
              //   Memory: '<S20>/MemoryTriggerWP'
              //   Memory: '<S2>/DelayPose'

              codegenReal2Mission_WaypointFollowerBase_stepInternal
                (&codegenReal2Mission_DW.obj_e,
                 codegenReal2Mission_DW.DelayPose_PreviousInput,
                 codegenReal2Mission_B.nedWayPoint_m, 200.0, rtb_ReshapeRowVec,
                 &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
                 &lookaheadFlag, &rtb_Switch, &status_0);

              // Merge: '<S14>/ Merge ' incorporates:
              //   DataTypeConversion: '<S20>/Cast To Double'
              //   MATLABSystem: '<S20>/Waypoint Follower'

              codegenReal2Mission_B.thisTaskStatus = status_0;

              // BusCreator: '<S20>/GuidanceCMDBusCreator' incorporates:
              //   DataTypeConversion: '<S20>/Param4'
              //   Gain: '<S20>/Down2Height'
              //   MATLABSystem: '<S20>/Waypoint Follower'

              codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
              codegenReal2Mission_B.GuidanceCmds.AirSpeed =
                codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

              // Merge: '<S14>/ Merge 3' incorporates:
              //   Constant: '<S20>/InitialFlightPathAngle'
              //   Constant: '<S20>/InitialRollAngle'
              //   Constant: '<S20>/InitialRollAngleRate'
              //   DataTypeConversion: '<S20>/Param4'
              //   Gain: '<S20>/Down2Up'
              //   Reshape: '<S20>/Reshape'

              codegenReal2Mission_B.InitialState[0] =
                codegenReal2Mission_B.nedWayPoint_d[0];
              codegenReal2Mission_B.InitialState[1] =
                codegenReal2Mission_B.nedWayPoint_d[1];
              codegenReal2Mission_B.InitialState[2] =
                -codegenReal2Mission_B.nedWayPoint_d[2];
              codegenReal2Mission_B.InitialState[3] =
                codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
              codegenReal2Mission_B.InitialState[4] = codegenReal2Mission_B.Bias;
              codegenReal2Mission_B.InitialState[5] = 0.0;
              codegenReal2Mission_B.InitialState[6] = 0.0;
              codegenReal2Mission_B.InitialState[7] = 0.0;

              // Merge: '<S14>/ Merge 2' incorporates:
              //   Memory: '<S20>/MemoryStopTrigger1'
              //   Memory: '<S20>/MemoryTriggerWP'
              //   Sum: '<S20>/Sum'

              codegenReal2Mission_B.ResetTrigger =
                codegenReal2Mission_DW.MemoryStopTrigger1_PreviousInput +
                codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n;

              // Update for Memory: '<S20>/MemoryTriggerWP' incorporates:
              //   Constant: '<S20>/TirggerWayPointGen'

              codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_n = 1.0;

              // Update for Memory: '<S20>/MemoryStopTrigger1' incorporates:
              //   Memory: '<S20>/MemoryStopTrigger2'

              codegenReal2Mission_DW.MemoryStopTrigger1_PreviousInput =
                codegenReal2Mission_DW.MemoryStopTrigger2_PreviousInput;

              // Update for Memory: '<S20>/MemoryStopTrigger2' incorporates:
              //   Constant: '<S20>/StopTrigger'

              codegenReal2Mission_DW.MemoryStopTrigger2_PreviousInput = -1.0;
            }
          }
          break;

         default:
          // Merge: '<S14>/ Merge 2'
          // case IN_WaypointFollower:
          codegenReal2Mission_B.ResetTrigger = 0.0;
          if (codegenReal2Mission_DW.is_WaypointFollower == 1) {
            // Abs: '<S116>/Abs' incorporates:
            //   Abs: '<S138>/Abs'
            //   DataStoreRead: '<S21>/LatitudeGCS'

            rtb_Switch_fe = std::abs(LatitudeGCS);

            // Switch: '<S116>/Switch' incorporates:
            //   Abs: '<S116>/Abs'
            //   Bias: '<S116>/Bias'
            //   Bias: '<S116>/Bias1'
            //   Constant: '<S116>/Constant2'
            //   Constant: '<S117>/Constant'
            //   DataStoreRead: '<S21>/LatitudeGCS'
            //   Math: '<S116>/Math Function1'
            //   RelationalOperator: '<S117>/Compare'

            if (rtb_Switch_fe > 180.0) {
              rtb_Down_b = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Down_b = LatitudeGCS;
            }

            // Abs: '<S113>/Abs1'
            rtb_Abs1 = std::abs(rtb_Down_b);

            // Switch: '<S113>/Switch' incorporates:
            //   Bias: '<S113>/Bias'
            //   Bias: '<S113>/Bias1'
            //   Constant: '<S104>/Constant'
            //   Constant: '<S104>/Constant1'
            //   Constant: '<S115>/Constant'
            //   Gain: '<S113>/Gain'
            //   Product: '<S113>/Divide1'
            //   RelationalOperator: '<S115>/Compare'
            //   Switch: '<S104>/Switch1'

            if (rtb_Abs1 > 90.0) {
              // Signum: '<S113>/Sign1'
              if (rtb_Down_b < 0.0) {
                rtb_Down_b = -1.0;
              } else if (rtb_Down_b > 0.0) {
                rtb_Down_b = 1.0;
              } else if (rtb_Down_b == 0.0) {
                rtb_Down_b = 0.0;
              } else {
                rtb_Down_b = (rtNaN);
              }

              rtb_Down_b *= -(rtb_Abs1 + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Sum: '<S104>/Sum' incorporates:
            //   DataStoreRead: '<S21>/LongitudeGCS'

            check = static_cast<real_T>(imo) + LongitudeGCS;

            // Sum: '<S100>/Sum1'
            rtb_Abs1 =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
              rtb_Down_b;

            // Switch: '<S110>/Switch' incorporates:
            //   Abs: '<S110>/Abs'
            //   Bias: '<S110>/Bias'
            //   Bias: '<S110>/Bias1'
            //   Constant: '<S110>/Constant2'
            //   Constant: '<S111>/Constant'
            //   Math: '<S110>/Math Function1'
            //   RelationalOperator: '<S111>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S107>/Abs1'
            b_shi = std::abs(rtb_Abs1);

            // Switch: '<S107>/Switch' incorporates:
            //   Bias: '<S107>/Bias'
            //   Bias: '<S107>/Bias1'
            //   Constant: '<S103>/Constant'
            //   Constant: '<S103>/Constant1'
            //   Constant: '<S109>/Constant'
            //   Gain: '<S107>/Gain'
            //   Product: '<S107>/Divide1'
            //   RelationalOperator: '<S109>/Compare'
            //   Switch: '<S103>/Switch1'

            if (b_shi > 90.0) {
              // Signum: '<S107>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              b_shi = (-(b_shi + -90.0) + 90.0) * rtb_Abs1;
              imo = 180;
            } else {
              b_shi = rtb_Abs1;
              imo = 0;
            }

            // Switch: '<S114>/Switch' incorporates:
            //   Abs: '<S114>/Abs'
            //   Bias: '<S114>/Bias'
            //   Bias: '<S114>/Bias1'
            //   Constant: '<S114>/Constant2'
            //   Constant: '<S118>/Constant'
            //   Math: '<S114>/Math Function1'
            //   RelationalOperator: '<S118>/Compare'

            if (std::abs(check) > 180.0) {
              check = rt_modd_snf(check + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S103>/Sum' incorporates:
            //   Sum: '<S100>/Sum1'

            rtb_Down2Up_e =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon -
               check) + static_cast<real_T>(imo);

            // UnitConversion: '<S106>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 0.017453292519943295 * b_shi;

            // UnitConversion: '<S121>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Down_b *= 0.017453292519943295;

            // Trigonometry: '<S122>/Trigonometric Function1'
            check = std::sin(rtb_Down_b);

            // Sum: '<S122>/Sum1' incorporates:
            //   Constant: '<S122>/Constant'
            //   Product: '<S122>/Product1'

            check = 1.0 - codegenReal2Mission_ConstB.sqrt_cy *
              codegenReal2Mission_ConstB.sqrt_cy * check * check;

            // Product: '<S120>/Product1' incorporates:
            //   Constant: '<S120>/Constant1'
            //   Sqrt: '<S120>/sqrt'

            b_shi = 6.378137E+6 / std::sqrt(check);

            // Product: '<S105>/dNorth' incorporates:
            //   Constant: '<S120>/Constant2'
            //   Product: '<S120>/Product3'
            //   Trigonometry: '<S120>/Trigonometric Function1'

            check = rtb_Abs1 / rt_atan2d_snf(1.0, b_shi *
              codegenReal2Mission_ConstB.Sum1_e / check);

            // Switch: '<S108>/Switch' incorporates:
            //   Abs: '<S108>/Abs'
            //   Bias: '<S108>/Bias'
            //   Bias: '<S108>/Bias1'
            //   Constant: '<S108>/Constant2'
            //   Constant: '<S112>/Constant'
            //   Math: '<S108>/Math Function1'
            //   RelationalOperator: '<S112>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(rtb_Down2Up_e) > 180.0) {
              rtb_Down2Up_e = rt_modd_snf(rtb_Down2Up_e + 180.0, 360.0) + -180.0;
            }

            // Product: '<S105>/dEast' incorporates:
            //   Constant: '<S120>/Constant3'
            //   Product: '<S120>/Product4'
            //   Trigonometry: '<S120>/Trigonometric Function'
            //   Trigonometry: '<S120>/Trigonometric Function2'
            //   UnitConversion: '<S106>/Unit Conversion'

            b_shi = 1.0 / rt_atan2d_snf(1.0, b_shi * std::cos(rtb_Down_b)) *
              (0.017453292519943295 * rtb_Down2Up_e);

            // Sum: '<S105>/Sum2' incorporates:
            //   Product: '<S105>/x*cos'
            //   Product: '<S105>/y*sin'

            rtb_Down_b = b_shi * 0.0 + check;

            // Sum: '<S105>/Sum3' incorporates:
            //   Product: '<S105>/x*sin'
            //   Product: '<S105>/y*cos'

            b_shi -= check * 0.0;

            // Sum: '<S21>/Sum' incorporates:
            //   DataStoreRead: '<S21>/AltitudeGCS'
            //   Gain: '<S21>/Up2Down'
            //   Gain: '<S21>/inverse'
            //   Sum: '<S100>/Sum'
            //   UnaryMinus: '<S100>/Ze2height'

            check =
              -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
                -AltitudeGCS) +
              -codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;

            // Gain: '<S99>/Gain1'
            rtb_Down2Up_e = 0.017453292519943295 *
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

            // Outputs for Triggered SubSystem: '<S21>/WayPointGenerator' incorporates:
            //   TriggerPort: '<S102>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE_b,
                               (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_k));
            if (zcEvent != NO_ZCEVENT) {
              // Reshape: '<S102>/ReshapeRowVec'
              rtb_ReshapeRowVec[0] = rtb_Down_b;
              rtb_ReshapeRowVec[1] = b_shi;
              rtb_ReshapeRowVec[2] = check;

              // MATLABSystem: '<S102>/RotateATMissionHdg' incorporates:
              //   SignalConversion generated from: '<S102>/RotateATMissionHdg'

              ct[0] = std::cos(rtb_Down2Up_e);
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = std::sin
                (rtb_Down2Up_e);
              out[0] = ct[0];
              out[3] = 0.0 * ct[0] -
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
              out[6] = 0.0 * ct[0] +
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] * 0.0;
              out[1] = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
              out[4] = 0.0 * rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                [0] + ct[0];
              out[7] = 0.0 * rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                [0] - ct[0] * 0.0;
              out[2] = -0.0;
              out[5] = 0.0;
              out[8] = 1.0;

              // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S21>/Param2'
              //   DataTypeConversion: '<S21>/Param3'
              //   Product: '<S102>/ProductScanWidth'

              rtb_Abs1 = std::ceil
                (codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                 (codegenReal2Mission_B.MemoryCurrentMission.params.Param3 *
                  static_cast<real_T>
                  (codegenReal2Mission_B.MemoryCurrentMission.numUAV)));
              rtb_Switch =
                codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                rtb_Abs1;
              connectionObj.FlightPathAngleLimit[0] = -0.175;
              connectionObj.FlightPathAngleLimit[1] = 0.175;
              connectionObj.MaxRollAngle = 0.29670597283903605;
              connectionObj.AirSpeed = 35.0;
              connectionObj.MinTurningRadius = 408.85657731051754;
              imo = static_cast<int32_T>(rtb_Abs1 * 2.0);
              SequenceID_prev = CheckPoints->size[0] * CheckPoints->size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              CheckPoints->size[0] = imo;
              CheckPoints->size[1] = 4;
              codegenReal2Mission_emxEnsureCapacity_real_T(CheckPoints,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S21>/Param1'

              b_nrows = (imo << 2) - 1;
              for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                   SequenceID_prev++) {
                CheckPoints->data[SequenceID_prev] = 0.0;
              }

              for (b_nrows = 0; b_nrows < static_cast<int32_T>(rtb_Abs1);
                   b_nrows++) {
                if (rt_remd_snf(static_cast<real_T>(b_nrows) + 1.0, 2.0) == 1.0)
                {
                  imo = (b_nrows + 1) << 1;
                  rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                    rtb_Switch;
                  CheckPoints->data[imo - 2] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 2] = 0.0;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                    1.5707963267948966;
                  CheckPoints->data[imo - 1] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 1] =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                    1.5707963267948966;
                } else {
                  imo = (b_nrows + 1) << 1;
                  rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                    rtb_Switch;
                  CheckPoints->data[imo - 2] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 2] =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                    -1.5707963267948966;
                  CheckPoints->data[imo - 1] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 1] = 0.0;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                    -1.5707963267948966;
                }
              }

              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint->size[0] = 1;
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint->data[0] = 0.0;
              dummyWayPoint->data[1] = 0.0;
              dummyWayPoint->data[2] = 0.0;
              for (nrowx = 0; nrowx <= CheckPoints->size[0] - 2; nrowx++) {
                LUp[0] = CheckPoints->data[nrowx];
                LDp[0] = CheckPoints->data[nrowx + 1];
                LUp[1] = CheckPoints->data[nrowx + CheckPoints->size[0]];
                LDp[1] = CheckPoints->data[(nrowx + CheckPoints->size[0]) + 1];
                LUp[2] = CheckPoints->data[nrowx + (CheckPoints->size[0] << 1)];
                LDp[2] = CheckPoints->data[(nrowx + (CheckPoints->size[0] << 1))
                  + 1];
                LUp[3] = CheckPoints->data[nrowx + CheckPoints->size[0] * 3];
                LDp[3] = CheckPoints->data[(nrowx + CheckPoints->size[0] * 3) +
                  1];
                codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                  segWayPoints);
                SequenceID_prev = dummyWayPoint_0->size[0] *
                  dummyWayPoint_0->size[1];
                dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                  segWayPoints->size[0];
                dummyWayPoint_0->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                  SequenceID_prev);
                b_nrows = dummyWayPoint->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[SequenceID_prev +
                      dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                      data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                  }
                }

                b_nrows = segWayPoints->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->
                      size[0]) + dummyWayPoint_0->size[0] * imo] =
                      segWayPoints->data[SequenceID_prev + segWayPoints->size[0]
                      * imo];
                  }
                }

                SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                  SequenceID_prev);
                b_nrows = dummyWayPoint_0->size[0] * 3;
                for (imo = 0; imo < b_nrows; imo++) {
                  dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                }
              }

              LUp[0] = CheckPoints->data[CheckPoints->size[0] - 1];
              LDp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[(CheckPoints->size[0] +
                CheckPoints->size[0]) - 1];
              LDp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[(CheckPoints->size[0] +
                (CheckPoints->size[0] << 1)) - 1];
              LDp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
              LUp[3] = CheckPoints->data[(CheckPoints->size[0] +
                CheckPoints->size[0] * 3) - 1];
              LDp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
              codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                segWayPoints);
              SequenceID_prev = dummyWayPoint_0->size[0] * dummyWayPoint_0->
                size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                segWayPoints->size[0];
              dummyWayPoint_0->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              b_nrows = dummyWayPoint->size[0];
              nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  dummyWayPoint_0->data[SequenceID_prev + dummyWayPoint_0->size
                    [0] * imo] = dummyWayPoint->data[SequenceID_prev +
                    dummyWayPoint->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < nrows;
                     SequenceID_prev++) {
                  dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->size[0])
                    + dummyWayPoint_0->size[0] * imo] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }

              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              b_nrows = dummyWayPoint_0->size[0] * 3;
              for (imo = 0; imo < b_nrows; imo++) {
                dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
              }

              SequenceID_prev = dummyWayPoint_1->size[0] * dummyWayPoint_1->
                size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              dummyWayPoint_1->size[0] = dummyWayPoint->size[0];
              dummyWayPoint_1->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_1,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              b_nrows = dummyWayPoint->size[0] * dummyWayPoint->size[1] - 1;
              for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                   SequenceID_prev++) {
                dummyWayPoint_1->data[SequenceID_prev] = dummyWayPoint->
                  data[SequenceID_prev];
              }

              codegenReal2Mission_repmat(dummyWayPoint_1, std::ceil(10240.0 /
                static_cast<real_T>(dummyWayPoint->size[0])), dummyWayPoint);
              nrowx = dummyWayPoint->size[0] - 2;
              nrows = dummyWayPoint->size[0] - 1;

              // Reshape: '<S21>/Reshape2Row' incorporates:
              //   Memory: '<S21>/MemoryPrevRelPos'

              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[1];
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[0];
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[2];

              // Product: '<S102>/RotateRelPrevPos' incorporates:
              //   MATLABSystem: '<S102>/RotateATMissionHdg'

              rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1, out, ct);

              // MATLAB Function: '<S102>/WayPointGenerator' incorporates:
              //   Product: '<S102>/RotateRelPrevPos'

              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo] = dummyWayPoint->data[imo + 1];
              }

              LDp[0] = ct[0];
              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo + dummyWayPoint->size[0]] =
                  dummyWayPoint->data[(imo + dummyWayPoint->size[0]) + 1];
              }

              LDp[1] = ct[1];
              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo + (dummyWayPoint->size[0] << 1)] =
                  dummyWayPoint->data[(imo + (dummyWayPoint->size[0] << 1)) + 1];
              }

              LDp[2] = ct[2];
              LDp[3] = 1.5707963267948966;
              LUp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
              LUp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
              codegenReal2Mission_genSegWP_i(&connectionObj, LDp, LUp, 100.0,
                segWayPoints);
              if (1 > nrows) {
                nrowx = -1;
              }

              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

              // MATLAB Function: '<S102>/WayPointGenerator'
              initWayPoint->size[0] = (segWayPoints->size[0] + nrowx) + 1;
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S102>/WayPointGenerator'
              b_nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[SequenceID_prev + initWayPoint->size[0] *
                    imo] = segWayPoints->data[SequenceID_prev +
                    segWayPoints->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev <= nrowx;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + segWayPoints->size[0]) +
                    initWayPoint->size[0] * imo] = dummyWayPoint->
                    data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < 10240;
                     SequenceID_prev++) {
                  codegenReal2Mission_B.WayPoint[SequenceID_prev + 10240 * imo] =
                    initWayPoint->data[SequenceID_prev + initWayPoint->size[0] *
                    imo];
                }
              }

              for (imo = 0; imo < 10240; imo++) {
                // MATLAB Function: '<S102>/biasWayPoint'
                codegenReal2Mission_B.rtb_WayPoint_m[imo] =
                  codegenReal2Mission_B.WayPoint[imo] +
                  codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon;
                codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240] =
                  codegenReal2Mission_B.WayPoint[imo + 10240];
                codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480] =
                  codegenReal2Mission_B.WayPoint[imo + 20480];

                // Product: '<S102>/RotateIndivWayPoint' incorporates:
                //   MATLABSystem: '<S102>/RotateATMissionHdg'

                for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev++)
                {
                  b_nrows = imo + 10240 * SequenceID_prev;
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev] * codegenReal2Mission_B.rtb_WayPoint_m[imo];
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev + 1] *
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev + 2] *
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
                }
              }

              // MATLAB Function: '<S102>/biasNED' incorporates:
              //   Product: '<S102>/RotateIndivWayPoint'
              //   Reshape: '<S102>/ReshapeRowVec'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                SequenceID_prev = b_nrows * 10240;
                for (imo = 0; imo < 10240; imo++) {
                  codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                    rtb_ReshapeRowVec[b_nrows];
                }
              }

              for (imo = 0; imo < 10240; imo++) {
                codegenReal2Mission_B.nedWayPoint_a[imo] =
                  codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                  codegenReal2Mission_B.WayPoint[imo];
                codegenReal2Mission_B.nedWayPoint_a[imo + 10240] =
                  codegenReal2Mission_B.WayPoint[imo + 10240] +
                  codegenReal2Mission_B.RotateIndivWayPoint[imo];
                codegenReal2Mission_B.nedWayPoint_a[imo + 20480] =
                  codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                  codegenReal2Mission_B.WayPoint[imo + 20480];
              }
            }

            // End of Outputs for SubSystem: '<S21>/WayPointGenerator'

            // BusCreator: '<S21>/GuidanceCMDBusCreator' incorporates:
            //   Constant: '<S21>/LookAheadDis'
            //   MATLAB Function: '<S102>/WayPointGenerator'
            //   MATLABSystem: '<S21>/Waypoint Follower'
            //   Memory: '<S21>/MemoryTriggerWP'
            //   Memory: '<S2>/DelayPose'

            codegenReal2Mission_WaypointFollowerBase_stepInternal
              (&codegenReal2Mission_DW.obj_i,
               codegenReal2Mission_DW.DelayPose_PreviousInput,
               codegenReal2Mission_B.nedWayPoint_a, 200.0, rtb_ReshapeRowVec,
               &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
               &lookaheadFlag, &rtb_Switch, &status_0);

            // Merge: '<S14>/ Merge ' incorporates:
            //   DataTypeConversion: '<S21>/Cast To Double'
            //   MATLABSystem: '<S21>/Waypoint Follower'

            codegenReal2Mission_B.thisTaskStatus = status_0;

            // BusCreator: '<S21>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S21>/Param4'
            //   Gain: '<S21>/Down2Height'
            //   MATLABSystem: '<S21>/Waypoint Follower'

            codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
            codegenReal2Mission_B.GuidanceCmds.AirSpeed =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

            // Switch: '<S138>/Switch' incorporates:
            //   Bias: '<S138>/Bias'
            //   Bias: '<S138>/Bias1'
            //   Constant: '<S138>/Constant2'
            //   Constant: '<S139>/Constant'
            //   DataStoreRead: '<S21>/PrevLatitudeGCS'
            //   Math: '<S138>/Math Function1'
            //   RelationalOperator: '<S139>/Compare'

            if (rtb_Switch_fe > 180.0) {
              rtb_Switch_fe = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch_fe = LatitudeGCS;
            }

            // Abs: '<S135>/Abs1'
            rtb_Abs1 = std::abs(rtb_Switch_fe);

            // Switch: '<S135>/Switch' incorporates:
            //   Bias: '<S135>/Bias'
            //   Bias: '<S135>/Bias1'
            //   Constant: '<S126>/Constant'
            //   Constant: '<S126>/Constant1'
            //   Constant: '<S137>/Constant'
            //   Gain: '<S135>/Gain'
            //   Product: '<S135>/Divide1'
            //   RelationalOperator: '<S137>/Compare'
            //   Switch: '<S126>/Switch1'

            if (rtb_Abs1 > 90.0) {
              // Signum: '<S135>/Sign1'
              if (rtb_Switch_fe < 0.0) {
                rtb_Switch_fe = -1.0;
              } else if (rtb_Switch_fe > 0.0) {
                rtb_Switch_fe = 1.0;
              } else if (rtb_Switch_fe == 0.0) {
                rtb_Switch_fe = 0.0;
              } else {
                rtb_Switch_fe = (rtNaN);
              }

              rtb_Switch_fe *= -(rtb_Abs1 + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Sum: '<S126>/Sum' incorporates:
            //   DataStoreRead: '<S21>/PrevLongitudeGCS'

            rtb_Gain1 = static_cast<real_T>(imo) + LongitudeGCS;

            // Sum: '<S101>/Sum1'
            rtb_Abs1 = fracSecs - rtb_Switch_fe;

            // Switch: '<S132>/Switch' incorporates:
            //   Abs: '<S132>/Abs'
            //   Bias: '<S132>/Bias'
            //   Bias: '<S132>/Bias1'
            //   Constant: '<S132>/Constant2'
            //   Constant: '<S133>/Constant'
            //   Math: '<S132>/Math Function1'
            //   RelationalOperator: '<S133>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S129>/Abs1'
            fracSecs = std::abs(rtb_Abs1);

            // Switch: '<S129>/Switch' incorporates:
            //   Bias: '<S129>/Bias'
            //   Bias: '<S129>/Bias1'
            //   Constant: '<S125>/Constant'
            //   Constant: '<S125>/Constant1'
            //   Constant: '<S131>/Constant'
            //   Gain: '<S129>/Gain'
            //   Product: '<S129>/Divide1'
            //   RelationalOperator: '<S131>/Compare'
            //   Switch: '<S125>/Switch1'

            if (fracSecs > 90.0) {
              // Signum: '<S129>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              rtb_Abs1 *= -(fracSecs + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Switch: '<S136>/Switch' incorporates:
            //   Abs: '<S136>/Abs'
            //   Bias: '<S136>/Bias'
            //   Bias: '<S136>/Bias1'
            //   Constant: '<S136>/Constant2'
            //   Constant: '<S140>/Constant'
            //   Math: '<S136>/Math Function1'
            //   RelationalOperator: '<S140>/Compare'

            if (std::abs(rtb_Gain1) > 180.0) {
              rtb_Gain1 = rt_modd_snf(rtb_Gain1 + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S125>/Sum' incorporates:
            //   Sum: '<S101>/Sum1'

            rtb_Gain1 = (second - rtb_Gain1) + static_cast<real_T>(imo);

            // UnitConversion: '<S143>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_fe *= 0.017453292519943295;

            // Trigonometry: '<S144>/Trigonometric Function1'
            second = std::sin(rtb_Switch_fe);

            // Sum: '<S144>/Sum1' incorporates:
            //   Constant: '<S144>/Constant'
            //   Product: '<S144>/Product1'

            second = 1.0 - codegenReal2Mission_ConstB.sqrt_cp *
              codegenReal2Mission_ConstB.sqrt_cp * second * second;

            // Product: '<S142>/Product1' incorporates:
            //   Constant: '<S142>/Constant1'
            //   Sqrt: '<S142>/sqrt'

            fracSecs = 6.378137E+6 / std::sqrt(second);

            // Product: '<S142>/Product4' incorporates:
            //   Trigonometry: '<S142>/Trigonometric Function'

            rtb_Switch_fe = fracSecs * std::cos(rtb_Switch_fe);

            // Product: '<S127>/dNorth' incorporates:
            //   Constant: '<S142>/Constant2'
            //   Product: '<S142>/Product3'
            //   Trigonometry: '<S142>/Trigonometric Function1'
            //   UnitConversion: '<S128>/Unit Conversion'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            fracSecs = 0.017453292519943295 * rtb_Abs1 / rt_atan2d_snf(1.0,
              fracSecs * codegenReal2Mission_ConstB.Sum1_h / second);

            // Switch: '<S130>/Switch' incorporates:
            //   Abs: '<S130>/Abs'
            //   Bias: '<S130>/Bias'
            //   Bias: '<S130>/Bias1'
            //   Constant: '<S130>/Constant2'
            //   Constant: '<S134>/Constant'
            //   Math: '<S130>/Math Function1'
            //   RelationalOperator: '<S134>/Compare'

            if (std::abs(rtb_Gain1) > 180.0) {
              rtb_Gain1 = rt_modd_snf(rtb_Gain1 + 180.0, 360.0) + -180.0;
            }

            // Product: '<S127>/dEast' incorporates:
            //   Constant: '<S142>/Constant3'
            //   Trigonometry: '<S142>/Trigonometric Function2'
            //   UnitConversion: '<S128>/Unit Conversion'

            second = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe) *
              (0.017453292519943295 * rtb_Gain1);

            // Sum: '<S127>/Sum2' incorporates:
            //   Product: '<S127>/x*cos'
            //   Product: '<S127>/y*sin'

            rtb_Switch_fe = second * 0.0 + fracSecs;

            // Sum: '<S127>/Sum3' incorporates:
            //   Product: '<S127>/x*sin'
            //   Product: '<S127>/y*cos'

            fracSecs = second - fracSecs * 0.0;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Bias: '<S21>/Rotate90deg'
            //   Product: '<S21>/FrontEast'
            //   Product: '<S21>/FrontNorth'
            //   Product: '<S21>/RightEast'
            //   Product: '<S21>/RightNorth'
            //   Reshape: '<S21>/Reshape'
            //   Sum: '<S21>/SumInitEast'
            //   Sum: '<S21>/SumInitNorth'
            //   Trigonometry: '<S21>/FrontCos'
            //   Trigonometry: '<S21>/FrontSin'
            //   Trigonometry: '<S21>/RightCos'
            //   Trigonometry: '<S21>/RightSin'

            codegenReal2Mission_B.InitialState[0] = (std::cos(rtb_Down2Up_e +
              1.5707963267948966) *
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon +
              rtb_Switch_fe) + std::cos(rtb_Down2Up_e) *
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat;
            codegenReal2Mission_B.InitialState[1] = (std::sin(rtb_Down2Up_e) *
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lat +
              fracSecs) + std::sin(rtb_Down2Up_e + 1.5707963267948966) *
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Lon;

            // Sum: '<S101>/Sum' incorporates:
            //   DataStoreRead: '<S21>/PrevAltitudeGCS'
            //   Gain: '<S21>/PrevInverse'

            second = temp + -AltitudeGCS;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Constant: '<S21>/InitialFlightPathAngle'
            //   Constant: '<S21>/InitialRollAngle'
            //   Constant: '<S21>/InitialRollAngleRate'
            //   DataTypeConversion: '<S21>/Param4'
            //   Reshape: '<S21>/Reshape'
            //   Sum: '<S101>/Sum'
            //   Sum: '<S21>/SumHeight'

            codegenReal2Mission_B.InitialState[2] = second +
              codegenReal2Mission_B.MemoryCurrentMission.StartPosition.Alt;
            codegenReal2Mission_B.InitialState[3] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
            codegenReal2Mission_B.InitialState[4] = rtb_Down2Up_e;
            codegenReal2Mission_B.InitialState[5] = 0.0;
            codegenReal2Mission_B.InitialState[6] = 0.0;
            codegenReal2Mission_B.InitialState[7] = 0.0;

            // Update for Memory: '<S21>/MemoryPrevRelPos' incorporates:
            //   Sum: '<S21>/RelPrevPos'
            //   UnaryMinus: '<S101>/Ze2height'

            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[0] =
              rtb_Switch_fe - rtb_Down_b;
            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[1] =
              fracSecs - b_shi;
            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput_d[2] = -second
              - check;

            // Update for Memory: '<S21>/MemoryTriggerWP' incorporates:
            //   Constant: '<S21>/TirggerWayPointGen'

            codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput_k = 1.0;
          } else {
            // Gain: '<S22>/Gain' incorporates:
            //   Constant: '<S22>/One2ZeroIdx'
            //   Constant: '<S22>/Three'
            //   DataTypeConversion: '<S22>/CastToDouble'
            //   Math: '<S22>/ModRunWayLayer'
            //   Sum: '<S22>/Minus'

            // case IN_HorizontalFormationNav:
            rtb_Down_b = rt_modd_snf(static_cast<real_T>
              (codegenReal2Mission_B.MemoryCurrentMission.FormationPos) - 1.0,
              3.0) * 15.0;

            // Sum: '<S22>/BiasMissionAlt' incorporates:
            //   DataStoreRead: '<S22>/AltitudeGCS'
            //   Gain: '<S22>/inverse'
            //   Sum: '<S151>/Sum'
            //   UnaryMinus: '<S151>/Ze2height'

            b_shi =
              -(codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Alt +
                -AltitudeGCS) - rtb_Down_b;

            // Sum: '<S22>/BiasPrevAlt' incorporates:
            //   DataStoreRead: '<S22>/PrevAltitudeGCS'
            //   Gain: '<S22>/PrevInverse'
            //   Sum: '<S152>/Sum'
            //   UnaryMinus: '<S152>/Ze2height'

            rtb_Down_b = -(temp + -AltitudeGCS) - rtb_Down_b;

            // Abs: '<S167>/Abs' incorporates:
            //   Abs: '<S189>/Abs'
            //   DataStoreRead: '<S22>/LatitudeGCS'

            rtb_Switch_fe = std::abs(LatitudeGCS);

            // Switch: '<S167>/Switch' incorporates:
            //   Abs: '<S167>/Abs'
            //   Bias: '<S167>/Bias'
            //   Bias: '<S167>/Bias1'
            //   Constant: '<S167>/Constant2'
            //   Constant: '<S168>/Constant'
            //   DataStoreRead: '<S22>/LatitudeGCS'
            //   Math: '<S167>/Math Function1'
            //   RelationalOperator: '<S168>/Compare'

            if (rtb_Switch_fe > 180.0) {
              rtb_Switch = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch = LatitudeGCS;
            }

            // Abs: '<S164>/Abs1'
            rtb_Abs1 = std::abs(rtb_Switch);

            // Switch: '<S164>/Switch' incorporates:
            //   Bias: '<S164>/Bias'
            //   Bias: '<S164>/Bias1'
            //   Constant: '<S155>/Constant'
            //   Constant: '<S155>/Constant1'
            //   Constant: '<S166>/Constant'
            //   Gain: '<S164>/Gain'
            //   Product: '<S164>/Divide1'
            //   RelationalOperator: '<S166>/Compare'
            //   Switch: '<S155>/Switch1'

            if (rtb_Abs1 > 90.0) {
              // Signum: '<S164>/Sign1'
              if (rtb_Switch < 0.0) {
                rtb_Switch = -1.0;
              } else if (rtb_Switch > 0.0) {
                rtb_Switch = 1.0;
              } else if (rtb_Switch == 0.0) {
                rtb_Switch = 0.0;
              } else {
                rtb_Switch = (rtNaN);
              }

              rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Sum: '<S155>/Sum' incorporates:
            //   DataStoreRead: '<S22>/LongitudeGCS'

            temp = static_cast<real_T>(imo) + LongitudeGCS;

            // Sum: '<S151>/Sum1'
            rtb_Abs1 =
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lat -
              rtb_Switch;

            // Switch: '<S161>/Switch' incorporates:
            //   Abs: '<S161>/Abs'
            //   Bias: '<S161>/Bias'
            //   Bias: '<S161>/Bias1'
            //   Constant: '<S161>/Constant2'
            //   Constant: '<S162>/Constant'
            //   Math: '<S161>/Math Function1'
            //   RelationalOperator: '<S162>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S158>/Abs1'
            check = std::abs(rtb_Abs1);

            // Switch: '<S158>/Switch' incorporates:
            //   Bias: '<S158>/Bias'
            //   Bias: '<S158>/Bias1'
            //   Constant: '<S154>/Constant'
            //   Constant: '<S154>/Constant1'
            //   Constant: '<S160>/Constant'
            //   Gain: '<S158>/Gain'
            //   Product: '<S158>/Divide1'
            //   RelationalOperator: '<S160>/Compare'
            //   Switch: '<S154>/Switch1'

            if (check > 90.0) {
              // Signum: '<S158>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              check = (-(check + -90.0) + 90.0) * rtb_Abs1;
              imo = 180;
            } else {
              check = rtb_Abs1;
              imo = 0;
            }

            // Switch: '<S165>/Switch' incorporates:
            //   Abs: '<S165>/Abs'
            //   Bias: '<S165>/Bias'
            //   Bias: '<S165>/Bias1'
            //   Constant: '<S165>/Constant2'
            //   Constant: '<S169>/Constant'
            //   Math: '<S165>/Math Function1'
            //   RelationalOperator: '<S169>/Compare'

            if (std::abs(temp) > 180.0) {
              temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S154>/Sum' incorporates:
            //   Sum: '<S151>/Sum1'

            temp =
              (codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.Lon -
               temp) + static_cast<real_T>(imo);

            // UnitConversion: '<S157>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Abs1 = 0.017453292519943295 * check;

            // UnitConversion: '<S172>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch *= 0.017453292519943295;

            // Trigonometry: '<S173>/Trigonometric Function1'
            rtb_Down2Up_e = std::sin(rtb_Switch);

            // Sum: '<S173>/Sum1' incorporates:
            //   Constant: '<S173>/Constant'
            //   Product: '<S173>/Product1'

            rtb_Down2Up_e = 1.0 - codegenReal2Mission_ConstB.sqrt_m *
              codegenReal2Mission_ConstB.sqrt_m * rtb_Down2Up_e * rtb_Down2Up_e;

            // Product: '<S171>/Product1' incorporates:
            //   Constant: '<S171>/Constant1'
            //   Sqrt: '<S171>/sqrt'

            check = 6.378137E+6 / std::sqrt(rtb_Down2Up_e);

            // Product: '<S156>/dNorth' incorporates:
            //   Constant: '<S171>/Constant2'
            //   Product: '<S171>/Product3'
            //   Trigonometry: '<S171>/Trigonometric Function1'

            rtb_Down2Up_e = rtb_Abs1 / rt_atan2d_snf(1.0, check *
              codegenReal2Mission_ConstB.Sum1_m / rtb_Down2Up_e);

            // Switch: '<S159>/Switch' incorporates:
            //   Abs: '<S159>/Abs'
            //   Bias: '<S159>/Bias'
            //   Bias: '<S159>/Bias1'
            //   Constant: '<S159>/Constant2'
            //   Constant: '<S163>/Constant'
            //   Math: '<S159>/Math Function1'
            //   RelationalOperator: '<S163>/Compare'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            if (std::abs(temp) > 180.0) {
              temp = rt_modd_snf(temp + 180.0, 360.0) + -180.0;
            }

            // Product: '<S156>/dEast' incorporates:
            //   Constant: '<S171>/Constant3'
            //   Product: '<S171>/Product4'
            //   Trigonometry: '<S171>/Trigonometric Function'
            //   Trigonometry: '<S171>/Trigonometric Function2'
            //   UnitConversion: '<S157>/Unit Conversion'

            check = 1.0 / rt_atan2d_snf(1.0, check * std::cos(rtb_Switch)) *
              (0.017453292519943295 * temp);

            // Sum: '<S156>/Sum2' incorporates:
            //   Product: '<S156>/x*cos'
            //   Product: '<S156>/y*sin'

            temp = check * 0.0 + rtb_Down2Up_e;

            // Sum: '<S156>/Sum3' incorporates:
            //   Product: '<S156>/x*sin'
            //   Product: '<S156>/y*cos'

            check -= rtb_Down2Up_e * 0.0;

            // Product: '<S22>/Map2Radian' incorporates:
            //   Constant: '<S22>/One2ZeroIdx'
            //   DataTypeConversion: '<S22>/CastToDouble'
            //   DataTypeConversion: '<S22>/Param3'
            //   Sum: '<S22>/Minus'

            rtb_Down2Up_e = (static_cast<real_T>
                             (codegenReal2Mission_B.MemoryCurrentMission.FormationPos)
                             - 1.0) *
              codegenReal2Mission_B.MemoryCurrentMission.params.Param3;

            // Gain: '<S150>/Gain1'
            rtb_Gain1 = 0.017453292519943295 *
              codegenReal2Mission_B.MemoryCurrentMission.MissionLocation.degHDG;

            // Outputs for Triggered SubSystem: '<S22>/WayPointGenerator' incorporates:
            //   TriggerPort: '<S153>/Trigger'

            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE,
                               (codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput));
            if (zcEvent != NO_ZCEVENT) {
              // Reshape: '<S153>/ReshapeRowVec'
              rtb_ReshapeRowVec[0] = temp;
              rtb_ReshapeRowVec[1] = check;
              rtb_ReshapeRowVec[2] = b_shi;

              // MATLABSystem: '<S153>/RotateATMissionHdg' incorporates:
              //   SignalConversion generated from: '<S153>/RotateATMissionHdg'

              ct[0] = std::cos(rtb_Gain1);
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] = std::sin
                (rtb_Gain1);
              out[0] = ct[0];
              out[3] = 0.0 * ct[0] -
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
              out[6] = 0.0 * ct[0] +
                rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] * 0.0;
              out[1] = rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0];
              out[4] = 0.0 * rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                [0] + ct[0];
              out[7] = 0.0 * rtb_TmpSignalConversionAtRotateATMissionHdgInport1
                [0] - ct[0] * 0.0;
              out[2] = -0.0;
              out[5] = 0.0;
              out[8] = 1.0;

              // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S22>/Param2'
              //   DataTypeConversion: '<S22>/Param3'
              //   Product: '<S153>/ProductScanWidth'

              rtb_Abs1 = std::ceil
                (codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                 (codegenReal2Mission_B.MemoryCurrentMission.params.Param3 *
                  static_cast<real_T>
                  (codegenReal2Mission_B.MemoryCurrentMission.numUAV)));
              rtb_Switch =
                codegenReal2Mission_B.MemoryCurrentMission.params.Param2 /
                rtb_Abs1;
              connectionObj.FlightPathAngleLimit[0] = -0.175;
              connectionObj.FlightPathAngleLimit[1] = 0.175;
              connectionObj.MaxRollAngle = 0.29670597283903605;
              connectionObj.AirSpeed = 35.0;
              connectionObj.MinTurningRadius = 408.85657731051754;
              imo = static_cast<int32_T>(rtb_Abs1 * 2.0);
              SequenceID_prev = CheckPoints->size[0] * CheckPoints->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              CheckPoints->size[0] = imo;
              CheckPoints->size[1] = 4;
              codegenReal2Mission_emxEnsureCapacity_real_T(CheckPoints,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
              //   DataTypeConversion: '<S22>/Param1'

              b_nrows = (imo << 2) - 1;
              for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                   SequenceID_prev++) {
                CheckPoints->data[SequenceID_prev] = 0.0;
              }

              for (b_nrows = 0; b_nrows < static_cast<int32_T>(rtb_Abs1);
                   b_nrows++) {
                if (rt_remd_snf(static_cast<real_T>(b_nrows) + 1.0, 2.0) == 1.0)
                {
                  imo = (b_nrows + 1) << 1;
                  rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                    rtb_Switch;
                  CheckPoints->data[imo - 2] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 2] = 0.0;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                    1.5707963267948966;
                  CheckPoints->data[imo - 1] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 1] =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                    1.5707963267948966;
                } else {
                  imo = (b_nrows + 1) << 1;
                  rtb_Sum_j = ((static_cast<real_T>(b_nrows) + 1.0) - 1.0) *
                    rtb_Switch;
                  CheckPoints->data[imo - 2] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 2] =
                    codegenReal2Mission_B.MemoryCurrentMission.params.Param1;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 2] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 2] =
                    -1.5707963267948966;
                  CheckPoints->data[imo - 1] = rtb_Sum_j;
                  CheckPoints->data[(imo + CheckPoints->size[0]) - 1] = 0.0;
                  CheckPoints->data[(imo + (CheckPoints->size[0] << 1)) - 1] =
                    0.0;
                  CheckPoints->data[(imo + CheckPoints->size[0] * 3) - 1] =
                    -1.5707963267948966;
                }
              }

              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint->size[0] = 1;
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint->data[0] = 0.0;
              dummyWayPoint->data[1] = 0.0;
              dummyWayPoint->data[2] = 0.0;
              for (nrowx = 0; nrowx <= CheckPoints->size[0] - 2; nrowx++) {
                LUp[0] = CheckPoints->data[nrowx];
                LDp[0] = CheckPoints->data[nrowx + 1];
                LUp[1] = CheckPoints->data[nrowx + CheckPoints->size[0]];
                LDp[1] = CheckPoints->data[(nrowx + CheckPoints->size[0]) + 1];
                LUp[2] = CheckPoints->data[nrowx + (CheckPoints->size[0] << 1)];
                LDp[2] = CheckPoints->data[(nrowx + (CheckPoints->size[0] << 1))
                  + 1];
                LUp[3] = CheckPoints->data[nrowx + CheckPoints->size[0] * 3];
                LDp[3] = CheckPoints->data[(nrowx + CheckPoints->size[0] * 3) +
                  1];
                codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                  segWayPoints);
                SequenceID_prev = dummyWayPoint_0->size[0] *
                  dummyWayPoint_0->size[1];
                dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                  segWayPoints->size[0];
                dummyWayPoint_0->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                  SequenceID_prev);
                b_nrows = dummyWayPoint->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[SequenceID_prev +
                      dummyWayPoint_0->size[0] * imo] = dummyWayPoint->
                      data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                  }
                }

                b_nrows = segWayPoints->size[0];
                for (imo = 0; imo < 3; imo++) {
                  for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                       SequenceID_prev++) {
                    dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->
                      size[0]) + dummyWayPoint_0->size[0] * imo] =
                      segWayPoints->data[SequenceID_prev + segWayPoints->size[0]
                      * imo];
                  }
                }

                SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];
                dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
                dummyWayPoint->size[1] = 3;
                codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                  SequenceID_prev);
                b_nrows = dummyWayPoint_0->size[0] * 3;
                for (imo = 0; imo < b_nrows; imo++) {
                  dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
                }
              }

              LUp[0] = CheckPoints->data[CheckPoints->size[0] - 1];
              LDp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[(CheckPoints->size[0] +
                CheckPoints->size[0]) - 1];
              LDp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[(CheckPoints->size[0] +
                (CheckPoints->size[0] << 1)) - 1];
              LDp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
              LUp[3] = CheckPoints->data[(CheckPoints->size[0] +
                CheckPoints->size[0] * 3) - 1];
              LDp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
              codegenReal2Mission_genSegWP_i(&connectionObj, LUp, LDp, 100.0,
                segWayPoints);
              SequenceID_prev = dummyWayPoint_0->size[0] * dummyWayPoint_0->
                size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint_0->size[0] = dummyWayPoint->size[0] +
                segWayPoints->size[0];
              dummyWayPoint_0->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint_0,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              b_nrows = dummyWayPoint->size[0];
              nrows = segWayPoints->size[0];
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  dummyWayPoint_0->data[SequenceID_prev + dummyWayPoint_0->size
                    [0] * imo] = dummyWayPoint->data[SequenceID_prev +
                    dummyWayPoint->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < nrows;
                     SequenceID_prev++) {
                  dummyWayPoint_0->data[(SequenceID_prev + dummyWayPoint->size[0])
                    + dummyWayPoint_0->size[0] * imo] = segWayPoints->
                    data[SequenceID_prev + segWayPoints->size[0] * imo];
                }
              }

              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint->size[0] = dummyWayPoint_0->size[0];
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              b_nrows = dummyWayPoint_0->size[0] * 3;
              for (imo = 0; imo < b_nrows; imo++) {
                dummyWayPoint->data[imo] = dummyWayPoint_0->data[imo];
              }

              nrowx = dummyWayPoint->size[0] - 2;
              nrows = dummyWayPoint->size[0] - 1;
              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo] = dummyWayPoint->data[imo + 1];
              }

              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo + dummyWayPoint->size[0]] =
                  dummyWayPoint->data[(imo + dummyWayPoint->size[0]) + 1];
              }

              for (imo = 0; imo <= nrowx; imo++) {
                dummyWayPoint->data[imo + (dummyWayPoint->size[0] << 1)] =
                  dummyWayPoint->data[(imo + (dummyWayPoint->size[0] << 1)) + 1];
              }

              if (1 > nrows) {
                b_nrows = -1;
              } else {
                b_nrows = nrowx;
              }

              SequenceID_prev = segWayPoints->size[0] * segWayPoints->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              segWayPoints->size[0] = b_nrows + 1;
              segWayPoints->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(segWayPoints,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev <= b_nrows;
                     SequenceID_prev++) {
                  segWayPoints->data[SequenceID_prev + segWayPoints->size[0] *
                    imo] = dummyWayPoint->data[SequenceID_prev +
                    dummyWayPoint->size[0] * imo];
                }
              }

              if (1 > nrows) {
                imo = -1;
                nrowx = -1;
              } else {
                imo = nrowx;
              }

              rtb_Abs1 = std::ceil(10240.0 / static_cast<real_T>(imo + 1));
              SequenceID_prev = dummyWayPoint->size[0] * dummyWayPoint->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              dummyWayPoint->size[0] = (nrowx + 1) * static_cast<int32_T>
                (rtb_Abs1);
              dummyWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(dummyWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              b_nrows = segWayPoints->size[0];

              // Reshape: '<S22>/Reshape2Row' incorporates:
              //   Memory: '<S22>/MemoryPrevRelPos'

              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[0] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[1];
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[1] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[0];
              rtb_TmpSignalConversionAtRotateATMissionHdgInport1[2] =
                codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[2];

              // Product: '<S153>/RotateRelPrevPos' incorporates:
              //   MATLABSystem: '<S153>/RotateATMissionHdg'

              rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf
                (rtb_TmpSignalConversionAtRotateATMissionHdgInport1, out, ct);

              // MATLAB Function: '<S153>/WayPointGenerator' incorporates:
              //   Product: '<S153>/RotateRelPrevPos'

              for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                nrows = imo * b_nrows + -1;
                for (k = 1; k - 1 < b_nrows; k++) {
                  dummyWayPoint->data[nrows + k] = segWayPoints->data[k - 1];
                }
              }

              LDp[0] = ct[0];
              SequenceID_prev = segWayPoints->size[0] * static_cast<int32_T>
                (rtb_Abs1) - 1;
              for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                nrows = imo * b_nrows + SequenceID_prev;
                for (k = 1; k - 1 < b_nrows; k++) {
                  dummyWayPoint->data[nrows + k] = segWayPoints->data[(b_nrows +
                    k) - 1];
                }
              }

              LDp[1] = ct[1];
              nrowx = segWayPoints->size[0] << 1;
              SequenceID_prev = ((segWayPoints->size[0] * static_cast<int32_T>
                                  (rtb_Abs1)) << 1) - 1;
              for (imo = 0; imo < static_cast<int32_T>(rtb_Abs1); imo++) {
                nrows = imo * b_nrows + SequenceID_prev;
                for (k = 1; k - 1 < b_nrows; k++) {
                  dummyWayPoint->data[nrows + k] = segWayPoints->data[(nrowx + k)
                    - 1];
                }
              }

              LDp[2] = ct[2];
              LDp[3] = 1.5707963267948966;
              LUp[0] = CheckPoints->data[0];
              LUp[1] = CheckPoints->data[CheckPoints->size[0]];
              LUp[2] = CheckPoints->data[CheckPoints->size[0] << 1];
              LUp[3] = CheckPoints->data[CheckPoints->size[0] * 3];
              codegenReal2Mission_genSegWP_i(&connectionObj, LDp, LUp, 100.0,
                segWayPoints);
              SequenceID_prev = initWayPoint->size[0] * initWayPoint->size[1];

              // MATLAB Function: '<S153>/WayPointGenerator'
              initWayPoint->size[0] = segWayPoints->size[0] +
                dummyWayPoint->size[0];
              initWayPoint->size[1] = 3;
              codegenReal2Mission_emxEnsureCapacity_real_T(initWayPoint,
                SequenceID_prev);

              // MATLAB Function: '<S153>/WayPointGenerator'
              b_nrows = segWayPoints->size[0];
              nrows = dummyWayPoint->size[0];
              for (imo = 0; imo < 3; imo++) {
                for (SequenceID_prev = 0; SequenceID_prev < b_nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[SequenceID_prev + initWayPoint->size[0] *
                    imo] = segWayPoints->data[SequenceID_prev +
                    segWayPoints->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < nrows;
                     SequenceID_prev++) {
                  initWayPoint->data[(SequenceID_prev + segWayPoints->size[0]) +
                    initWayPoint->size[0] * imo] = dummyWayPoint->
                    data[SequenceID_prev + dummyWayPoint->size[0] * imo];
                }

                for (SequenceID_prev = 0; SequenceID_prev < 10240;
                     SequenceID_prev++) {
                  codegenReal2Mission_B.WayPoint[SequenceID_prev + 10240 * imo] =
                    initWayPoint->data[SequenceID_prev + initWayPoint->size[0] *
                    imo];
                }
              }

              for (imo = 0; imo < 10240; imo++) {
                // MATLAB Function: '<S153>/biasWayPoint'
                codegenReal2Mission_B.rtb_WayPoint_m[imo] =
                  codegenReal2Mission_B.WayPoint[imo] + rtb_Down2Up_e;
                codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240] =
                  codegenReal2Mission_B.WayPoint[imo + 10240];
                codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480] =
                  codegenReal2Mission_B.WayPoint[imo + 20480];

                // Product: '<S153>/RotateIndivWayPoint' incorporates:
                //   MATLABSystem: '<S153>/RotateATMissionHdg'

                for (SequenceID_prev = 0; SequenceID_prev < 3; SequenceID_prev++)
                {
                  b_nrows = imo + 10240 * SequenceID_prev;
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] = 0.0;
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev] * codegenReal2Mission_B.rtb_WayPoint_m[imo];
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev + 1] *
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 10240];
                  codegenReal2Mission_B.RotateIndivWayPoint[b_nrows] += out[3 *
                    SequenceID_prev + 2] *
                    codegenReal2Mission_B.rtb_WayPoint_m[imo + 20480];
                }
              }

              // MATLAB Function: '<S153>/biasNED' incorporates:
              //   Product: '<S153>/RotateIndivWayPoint'
              //   Reshape: '<S153>/ReshapeRowVec'

              for (b_nrows = 0; b_nrows < 3; b_nrows++) {
                SequenceID_prev = b_nrows * 10240;
                for (imo = 0; imo < 10240; imo++) {
                  codegenReal2Mission_B.WayPoint[SequenceID_prev + imo] =
                    rtb_ReshapeRowVec[b_nrows];
                }
              }

              for (imo = 0; imo < 10240; imo++) {
                codegenReal2Mission_B.nedWayPoint[imo] =
                  codegenReal2Mission_B.RotateIndivWayPoint[imo + 10240] +
                  codegenReal2Mission_B.WayPoint[imo];
                codegenReal2Mission_B.nedWayPoint[imo + 10240] =
                  codegenReal2Mission_B.WayPoint[imo + 10240] +
                  codegenReal2Mission_B.RotateIndivWayPoint[imo];
                codegenReal2Mission_B.nedWayPoint[imo + 20480] =
                  codegenReal2Mission_B.RotateIndivWayPoint[imo + 20480] +
                  codegenReal2Mission_B.WayPoint[imo + 20480];
              }
            }

            // End of Outputs for SubSystem: '<S22>/WayPointGenerator'

            // BusCreator: '<S22>/GuidanceCMDBusCreator' incorporates:
            //   Constant: '<S22>/LookAheadDis'
            //   MATLAB Function: '<S153>/WayPointGenerator'
            //   MATLABSystem: '<S22>/Waypoint Follower'
            //   Memory: '<S22>/MemoryTriggerWP'
            //   Memory: '<S2>/DelayPose'

            codegenReal2Mission_WaypointFollowerBase_stepInternal
              (&codegenReal2Mission_DW.obj,
               codegenReal2Mission_DW.DelayPose_PreviousInput,
               codegenReal2Mission_B.nedWayPoint, 200.0, rtb_ReshapeRowVec,
               &codegenReal2Mission_B.GuidanceCmds.HeadingAngle, &rtb_Abs1,
               &lookaheadFlag, &rtb_Switch, &status_0);

            // Merge: '<S14>/ Merge ' incorporates:
            //   DataTypeConversion: '<S22>/Cast To Double'
            //   MATLABSystem: '<S22>/Waypoint Follower'

            codegenReal2Mission_B.thisTaskStatus = status_0;

            // BusCreator: '<S22>/GuidanceCMDBusCreator' incorporates:
            //   DataTypeConversion: '<S22>/Param4'
            //   Gain: '<S22>/Down2Height'
            //   MATLABSystem: '<S22>/Waypoint Follower'

            codegenReal2Mission_B.GuidanceCmds.Height = -rtb_ReshapeRowVec[2];
            codegenReal2Mission_B.GuidanceCmds.AirSpeed =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;

            // Switch: '<S189>/Switch' incorporates:
            //   Bias: '<S189>/Bias'
            //   Bias: '<S189>/Bias1'
            //   Constant: '<S189>/Constant2'
            //   Constant: '<S190>/Constant'
            //   DataStoreRead: '<S22>/PrevLatitudeGCS'
            //   Math: '<S189>/Math Function1'
            //   RelationalOperator: '<S190>/Compare'

            if (rtb_Switch_fe > 180.0) {
              rtb_Switch_fe = rt_modd_snf(LatitudeGCS + 180.0, 360.0) + -180.0;
            } else {
              rtb_Switch_fe = LatitudeGCS;
            }

            // Abs: '<S186>/Abs1'
            rtb_Abs1 = std::abs(rtb_Switch_fe);

            // Switch: '<S186>/Switch' incorporates:
            //   Bias: '<S186>/Bias'
            //   Bias: '<S186>/Bias1'
            //   Constant: '<S177>/Constant'
            //   Constant: '<S177>/Constant1'
            //   Constant: '<S188>/Constant'
            //   Gain: '<S186>/Gain'
            //   Product: '<S186>/Divide1'
            //   RelationalOperator: '<S188>/Compare'
            //   Switch: '<S177>/Switch1'

            if (rtb_Abs1 > 90.0) {
              // Signum: '<S186>/Sign1'
              if (rtb_Switch_fe < 0.0) {
                rtb_Switch_fe = -1.0;
              } else if (rtb_Switch_fe > 0.0) {
                rtb_Switch_fe = 1.0;
              } else if (rtb_Switch_fe == 0.0) {
                rtb_Switch_fe = 0.0;
              } else {
                rtb_Switch_fe = (rtNaN);
              }

              rtb_Switch_fe *= -(rtb_Abs1 + -90.0) + 90.0;
              imo = 180;
            } else {
              imo = 0;
            }

            // Sum: '<S177>/Sum' incorporates:
            //   DataStoreRead: '<S22>/PrevLongitudeGCS'

            rtb_Sum_j = static_cast<real_T>(imo) + LongitudeGCS;

            // Sum: '<S152>/Sum1'
            rtb_Abs1 = fracSecs - rtb_Switch_fe;

            // Switch: '<S183>/Switch' incorporates:
            //   Abs: '<S183>/Abs'
            //   Bias: '<S183>/Bias'
            //   Bias: '<S183>/Bias1'
            //   Constant: '<S183>/Constant2'
            //   Constant: '<S184>/Constant'
            //   Math: '<S183>/Math Function1'
            //   RelationalOperator: '<S184>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Abs: '<S180>/Abs1'
            fracSecs = std::abs(rtb_Abs1);

            // Switch: '<S180>/Switch' incorporates:
            //   Bias: '<S180>/Bias'
            //   Bias: '<S180>/Bias1'
            //   Constant: '<S176>/Constant'
            //   Constant: '<S176>/Constant1'
            //   Constant: '<S182>/Constant'
            //   Gain: '<S180>/Gain'
            //   Product: '<S180>/Divide1'
            //   RelationalOperator: '<S182>/Compare'
            //   Switch: '<S176>/Switch1'

            if (fracSecs > 90.0) {
              // Signum: '<S180>/Sign1'
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = -1.0;
              } else if (rtb_Abs1 > 0.0) {
                rtb_Abs1 = 1.0;
              } else if (rtb_Abs1 == 0.0) {
                rtb_Abs1 = 0.0;
              } else {
                rtb_Abs1 = (rtNaN);
              }

              rtb_Switch = (-(fracSecs + -90.0) + 90.0) * rtb_Abs1;
              imo = 180;
            } else {
              rtb_Switch = rtb_Abs1;
              imo = 0;
            }

            // Switch: '<S187>/Switch' incorporates:
            //   Abs: '<S187>/Abs'
            //   Bias: '<S187>/Bias'
            //   Bias: '<S187>/Bias1'
            //   Constant: '<S187>/Constant2'
            //   Constant: '<S191>/Constant'
            //   Math: '<S187>/Math Function1'
            //   RelationalOperator: '<S191>/Compare'

            if (std::abs(rtb_Sum_j) > 180.0) {
              rtb_Sum_j = rt_modd_snf(rtb_Sum_j + 180.0, 360.0) + -180.0;
            }

            // Sum: '<S176>/Sum' incorporates:
            //   Sum: '<S152>/Sum1'

            rtb_Abs1 = (second - rtb_Sum_j) + static_cast<real_T>(imo);

            // UnitConversion: '<S194>/Unit Conversion'
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            rtb_Switch_fe *= 0.017453292519943295;

            // Trigonometry: '<S195>/Trigonometric Function1'
            second = std::sin(rtb_Switch_fe);

            // Sum: '<S195>/Sum1' incorporates:
            //   Constant: '<S195>/Constant'
            //   Product: '<S195>/Product1'

            second = 1.0 - codegenReal2Mission_ConstB.sqrt_c *
              codegenReal2Mission_ConstB.sqrt_c * second * second;

            // Product: '<S193>/Product1' incorporates:
            //   Constant: '<S193>/Constant1'
            //   Sqrt: '<S193>/sqrt'

            fracSecs = 6.378137E+6 / std::sqrt(second);

            // Product: '<S193>/Product4' incorporates:
            //   Trigonometry: '<S193>/Trigonometric Function'

            rtb_Switch_fe = fracSecs * std::cos(rtb_Switch_fe);

            // Product: '<S178>/dNorth' incorporates:
            //   Constant: '<S193>/Constant2'
            //   Product: '<S193>/Product3'
            //   Trigonometry: '<S193>/Trigonometric Function1'
            //   UnitConversion: '<S179>/Unit Conversion'

            // Unit Conversion - from: deg to: rad
            // Expression: output = (0.0174533*input) + (0)
            fracSecs = 0.017453292519943295 * rtb_Switch / rt_atan2d_snf(1.0,
              fracSecs * codegenReal2Mission_ConstB.Sum1_c / second);

            // Switch: '<S181>/Switch' incorporates:
            //   Abs: '<S181>/Abs'
            //   Bias: '<S181>/Bias'
            //   Bias: '<S181>/Bias1'
            //   Constant: '<S181>/Constant2'
            //   Constant: '<S185>/Constant'
            //   Math: '<S181>/Math Function1'
            //   RelationalOperator: '<S185>/Compare'

            if (std::abs(rtb_Abs1) > 180.0) {
              rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
            }

            // Product: '<S178>/dEast' incorporates:
            //   Constant: '<S193>/Constant3'
            //   Trigonometry: '<S193>/Trigonometric Function2'
            //   UnitConversion: '<S179>/Unit Conversion'

            second = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_fe) *
              (0.017453292519943295 * rtb_Abs1);

            // Sum: '<S178>/Sum2' incorporates:
            //   Product: '<S178>/x*cos'
            //   Product: '<S178>/y*sin'

            rtb_Switch = second * 0.0 + fracSecs;

            // Sum: '<S178>/Sum3' incorporates:
            //   Product: '<S178>/x*sin'
            //   Product: '<S178>/y*cos'

            fracSecs = second - fracSecs * 0.0;

            // Merge: '<S14>/ Merge 3' incorporates:
            //   Bias: '<S22>/Rotate90deg'
            //   Constant: '<S22>/InitialFlightPathAngle'
            //   Constant: '<S22>/InitialRollAngle'
            //   Constant: '<S22>/InitialRollAngleRate'
            //   DataTypeConversion: '<S22>/Param4'
            //   Gain: '<S22>/Down2Up'
            //   Product: '<S22>/ProductEast'
            //   Product: '<S22>/ProductNorth'
            //   Reshape: '<S22>/Reshape'
            //   Sum: '<S22>/SumInitEast'
            //   Sum: '<S22>/SumInitNorth'
            //   Trigonometry: '<S22>/Cos'
            //   Trigonometry: '<S22>/Sin'

            codegenReal2Mission_B.InitialState[0] = std::cos(rtb_Gain1 +
              1.5707963267948966) * rtb_Down2Up_e + rtb_Switch;
            codegenReal2Mission_B.InitialState[1] = std::sin(rtb_Gain1 +
              1.5707963267948966) * rtb_Down2Up_e + fracSecs;
            codegenReal2Mission_B.InitialState[2] = -rtb_Down_b;
            codegenReal2Mission_B.InitialState[3] =
              codegenReal2Mission_B.MemoryCurrentMission.params.Param4;
            codegenReal2Mission_B.InitialState[4] = rtb_Gain1;
            codegenReal2Mission_B.InitialState[5] = 0.0;
            codegenReal2Mission_B.InitialState[6] = 0.0;
            codegenReal2Mission_B.InitialState[7] = 0.0;

            // Update for Memory: '<S22>/MemoryPrevRelPos' incorporates:
            //   Sum: '<S22>/RelPrevPos'

            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[0] =
              rtb_Switch - temp;
            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[1] = fracSecs
              - check;
            codegenReal2Mission_DW.MemoryPrevRelPos_PreviousInput[2] =
              rtb_Down_b - b_shi;

            // Update for Memory: '<S22>/MemoryTriggerWP' incorporates:
            //   Constant: '<S22>/TirggerWayPointGen'

            codegenReal2Mission_DW.MemoryTriggerWP_PreviousInput = 1.0;
          }
          break;
        }
      }

      codegenReal2Mission_emxFree_real_T(&dummyWayPoint_3);
      codegenReal2Mission_emxFree_real_T(&dummyWayPoint_2);
      codegenReal2Mission_emxFree_real_T(&dummyWayPoint_1);
      codegenReal2Mission_emxFree_real_T(&dummyWayPoint_0);
      codegenReal2Mission_emxFree_real_T(&segWayPoints);
      codegenReal2Mission_emxFree_real_T(&dummyWayPoint);
      codegenReal2Mission_emxFree_real_T(&CheckPoints);
      codegenReal2Mission_emxFree_real_T(&initWayPoint);
    }

    // End of Chart: '<S2>/PreemptableMissionModeSelector'

    // Outputs for Enabled SubSystem: '<S2>/MissionSimUAV' incorporates:
    //   EnablePort: '<S13>/Enable'

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      codegenReal2Mission_DW.MissionSimUAV_MODE = rtb_ReceiveCurrentMission_o1;
    }

    // End of Outputs for SubSystem: '<S2>/MissionSimUAV'
  }

  // Outputs for Enabled SubSystem: '<S2>/MissionSimUAV' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
    // ModelReference generated from: '<S13>/MissionUavModel'
    MissionUAV(&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
               &codegenReal2Mission_B.ResetTrigger,
               &codegenReal2Mission_B.InitialState[0],
               &codegenReal2Mission_B.GuidanceCmds.Height,
               &codegenReal2Mission_B.GuidanceCmds.AirSpeed,
               &codegenReal2Mission_B.GuidanceCmds.HeadingAngle,
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
                   &codegenReal2Mission_B.North, &codegenReal2Mission_B.East,
                   &codegenReal2Mission_B.Height,
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
    codegenReal2Mission_getLocalTime(&fracSecs, &second, &rtb_Switch_fe,
      &rtb_Abs1, &temp, &rtb_Down_b, &b_shi, &rtb_ReceiveCurrentMission_o1);
    fracSecs /= 1.0E+6;
    check = (((((b_shi + rtb_Down_b) + temp) + rtb_Abs1) + rtb_Switch_fe) +
             second) + fracSecs;
    if ((!std::isinf(check)) && (!std::isnan(check))) {
      if ((rtb_Down_b < 1.0) || (rtb_Down_b > 12.0)) {
        check = std::floor((rtb_Down_b - 1.0) / 12.0);
        b_shi += check;
        rtb_Down_b = ((rtb_Down_b - 1.0) - check * 12.0) + 1.0;
      }

      if (rtb_Down_b < 3.0) {
        b_shi--;
        rtb_Down_b += 9.0;
      } else {
        rtb_Down_b -= 3.0;
      }

      if ((fracSecs < 0.0) || (1000.0 <= fracSecs)) {
        check = std::floor(fracSecs / 1000.0);
        second += check;
        fracSecs -= check * 1000.0;
      }

      t.re = ((((((365.0 * b_shi + std::floor(b_shi / 4.0)) - std::floor(b_shi /
        100.0)) + std::floor(b_shi / 400.0)) + std::floor((153.0 * rtb_Down_b +
                  2.0) / 5.0)) + temp) + 60.0) - 719529.0;
      t.im = 0.0;
      thisData = codegenReal2Mission_plus(codegenReal2Mission_plus
        (codegenReal2Mission_plus(codegenReal2Mission_times(t), (60.0 * rtb_Abs1
        + rtb_Switch_fe) * 60000.0), second * 1000.0), fracSecs);
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
    rtb_Switch_fe = (c_s.re + c_s.im) / 8.64E+7;
    rtb_Abs1 = 0.0;
    second = da.re;
    if (rtb_Switch_fe != 0.0) {
      second = da.re + rtb_Switch_fe;
      rtb_Abs1 = rtb_Switch_fe - (second - da.re);
    }

    if (std::isnan(rtb_Abs1)) {
      rtb_Abs1 = 0.0;
    }

    r.re = second;
    r.im = rtb_Abs1;
    r = floor_jeUa7tf2(r);
    rtb_Switch_fe = r.re + r.im;
    r = codegenReal2Mission_minus(thisData, codegenReal2Mission_times(r));
    da.re = r.re / 1000.0;
    t = split_MzIWb6Db(da.re);
    temp = da.re * 1000.0;
    rtb_Abs1 = (t.re * 1000.0 - temp) + t.im * 1000.0;
    imo = 0;
    if (std::isnan(rtb_Abs1)) {
      imo = 1;
    }

    if (0 <= imo - 1) {
      rtb_Abs1 = 0.0;
    }

    c_s.re = 0.0;
    c_s.im = 0.0;
    if (r.re != temp) {
      c_s = codegenReal2Mission_two_diff(r.re, temp);
    }

    c_s.re = (0.0 * r.im + c_s.re) - 0.0 * rtb_Abs1;
    c_s.im = (c_s.im + r.im) - rtb_Abs1;
    rtb_Abs1 = (c_s.re + c_s.im) / 1000.0;
    second = 0.0;
    fracSecs = da.re;
    if (rtb_Abs1 != 0.0) {
      fracSecs = da.re + rtb_Abs1;
      second = rtb_Abs1 - (fracSecs - da.re);
    }

    if (std::isnan(second)) {
      second = 0.0;
    }

    da.re = fracSecs;
    da.im = second;
    t = floor_jeUa7tf2(da);
    da = codegenReal2Mission_minus(da, t);
    rtb_Abs1 = t.re + t.im;
    if (((rtb_Switch_fe + 719529.0) - 61.0 >= 0.0) && ((rtb_Switch_fe + 719529.0)
         - 61.0 <= 2.147483647E+9)) {
      rtb_Switch_fe = std::round((rtb_Switch_fe + 719529.0) - 61.0);
      if (rtb_Switch_fe < 2.147483648E+9) {
        if (rtb_Switch_fe >= -2.147483648E+9) {
          imo = static_cast<int32_T>(rtb_Switch_fe);
        } else {
          imo = MIN_int32_T;
        }
      } else {
        imo = MAX_int32_T;
      }

      nrowx = imo - 146097 * div_s32(imo, 146097);
      b_nrows = static_cast<int32_T>(std::trunc(static_cast<real_T>(nrowx) /
        36524.0));
      SequenceID_prev = nrowx - 36524 * div_s32(nrowx, 36524);
      if (b_nrows > 3) {
        b_nrows = 3;
        SequenceID_prev = nrowx - 109572;
      }

      nrows = SequenceID_prev - 1461 * div_s32(SequenceID_prev, 1461);
      k = static_cast<int32_T>(std::trunc(static_cast<real_T>(nrows) / 365.0));
      nrowx = nrows - 365 * div_s32(nrows, 365);
      if (k > 3) {
        k = 3;
        nrowx = nrows - 1095;
      }

      rtb_Switch_fe = ((std::trunc(static_cast<real_T>(imo) / 146097.0) * 400.0
                        + static_cast<real_T>(b_nrows) * 100.0) + std::trunc(
        static_cast<real_T>(SequenceID_prev) / 1461.0) * 4.0) +
        static_cast<real_T>(k);
      imo = static_cast<int32_T>(std::trunc((static_cast<real_T>(nrowx) * 5.0 +
        308.0) / 153.0)) - 2;
      second = imo;
      rtb_Down_b = ((static_cast<real_T>(nrowx) - std::trunc((static_cast<real_T>
        (imo) + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    } else {
      second = std::floor(((rtb_Switch_fe + 719529.0) - 61.0) / 146097.0);
      rtb_Switch_fe = ((rtb_Switch_fe + 719529.0) - 61.0) - second * 146097.0;
      fracSecs = std::floor(rtb_Switch_fe / 36524.0);
      if (fracSecs > 3.0) {
        fracSecs = 3.0;
      }

      rtb_Switch_fe -= fracSecs * 36524.0;
      temp = std::floor(rtb_Switch_fe / 1461.0);
      rtb_Down_b = rtb_Switch_fe - temp * 1461.0;
      rtb_Switch_fe = std::floor(rtb_Down_b / 365.0);
      if (rtb_Switch_fe > 3.0) {
        rtb_Switch_fe = 3.0;
      }

      rtb_Down_b -= rtb_Switch_fe * 365.0;
      rtb_Switch_fe += (second * 400.0 + fracSecs * 100.0) + temp * 4.0;
      second = std::floor((rtb_Down_b * 5.0 + 308.0) / 153.0) - 2.0;
      rtb_Down_b = ((rtb_Down_b - std::floor((second + 4.0) * 153.0 / 5.0)) +
                    122.0) + 1.0;
    }

    if (second > 9.0) {
      rtb_Switch_fe++;
      second = (second + 2.0) - 11.0;
    } else {
      second = (second + 2.0) + 1.0;
    }

    if ((rtb_Abs1 >= 0.0) && (rtb_Abs1 <= 2.147483647E+9)) {
      imo = static_cast<int32_T>(std::round(rtb_Abs1));
      b_nrows = imo - 3600 * div_s32(imo, 3600);
      rtb_Switch = std::trunc(static_cast<real_T>(imo) / 3600.0);
      fracSecs = std::trunc(static_cast<real_T>(b_nrows) / 60.0);
      rtb_Abs1 = b_nrows - 60 * div_s32(b_nrows, 60);
    } else {
      rtb_Switch = std::floor(rtb_Abs1 / 3600.0);
      fracSecs = std::floor((rtb_Abs1 - 3600.0 * rtb_Switch) / 60.0);
      rtb_Abs1 -= 60.0 * fracSecs;
    }

    temp = (da.re + da.im) + rtb_Abs1;
    if (temp == 60.0) {
      temp = 59.999999999999993;
    }

    if ((thisData.re == (rtInf)) && (thisData.im == 0.0)) {
      rtb_Switch_fe = (rtInf);
    } else if ((thisData.re == (rtMinusInf)) && (thisData.im == 0.0)) {
      rtb_Switch_fe = (rtMinusInf);
    }

    rtb_Abs1 = std::floor(temp);
    temp = std::round((temp - rtb_Abs1) * 1000.0);

    // Receive: '<S1>/ReceiveThisMission'
    SequenceID_prev = codegenReal2Mission_ReceiveThisMission_RecvData
      (&codegenReal2Mission_B.ReceiveThisMission_o2);
    rtb_ReceiveCurrentMission_o1 = (SequenceID_prev != 1);

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

    if (std::isnan(rtb_Switch_fe) || std::isinf(rtb_Switch_fe)) {
      rtb_Switch_fe = 0.0;
    } else {
      rtb_Switch_fe = std::fmod(rtb_Switch_fe, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/year'

    rtb_IndividualUAVCmd.StartTime.year = rtb_Switch_fe < 0.0 ?
      -static_cast<int32_T>(static_cast<uint32_T>(-rtb_Switch_fe)) :
      static_cast<int32_T>(static_cast<uint32_T>(rtb_Switch_fe));

    // DataTypeConversion: '<S1>/month' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    if (std::isnan(second) || std::isinf(second)) {
      rtb_Switch_fe = 0.0;
    } else {
      rtb_Switch_fe = std::fmod(second, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/month'

    rtb_IndividualUAVCmd.StartTime.month = rtb_Switch_fe < 0.0 ?
      -static_cast<int32_T>(static_cast<uint32_T>(-rtb_Switch_fe)) :
      static_cast<int32_T>(static_cast<uint32_T>(rtb_Switch_fe));

    // DataTypeConversion: '<S1>/day' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    rtb_Switch_fe = std::floor(rtb_Down_b);
    if (std::isnan(rtb_Switch_fe) || std::isinf(rtb_Switch_fe)) {
      rtb_Switch_fe = 0.0;
    } else {
      rtb_Switch_fe = std::fmod(rtb_Switch_fe, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/day'

    rtb_IndividualUAVCmd.StartTime.day = rtb_Switch_fe < 0.0 ?
      -static_cast<int32_T>(static_cast<uint32_T>(-rtb_Switch_fe)) :
      static_cast<int32_T>(static_cast<uint32_T>(rtb_Switch_fe));

    // DataTypeConversion: '<S1>/hour' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    if (std::isnan(rtb_Switch) || std::isinf(rtb_Switch)) {
      rtb_Switch_fe = 0.0;
    } else {
      rtb_Switch_fe = std::fmod(rtb_Switch, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/hour'

    rtb_IndividualUAVCmd.StartTime.hour = rtb_Switch_fe < 0.0 ?
      -static_cast<int32_T>(static_cast<uint32_T>(-rtb_Switch_fe)) :
      static_cast<int32_T>(static_cast<uint32_T>(rtb_Switch_fe));

    // DataTypeConversion: '<S1>/minute' incorporates:
    //   MATLAB Function: '<S1>/getCurrentTime'

    if (std::isnan(fracSecs) || std::isinf(fracSecs)) {
      rtb_Switch_fe = 0.0;
    } else {
      rtb_Switch_fe = std::fmod(fracSecs, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/minute'

    rtb_IndividualUAVCmd.StartTime.minute = rtb_Switch_fe < 0.0 ? -static_cast<
      int32_T>(static_cast<uint32_T>(-rtb_Switch_fe)) : static_cast<int32_T>(
      static_cast<uint32_T>(rtb_Switch_fe));

    // DataTypeConversion: '<S1>/second'
    if (std::isnan(rtb_Abs1) || std::isinf(rtb_Abs1)) {
      rtb_Switch_fe = 0.0;
    } else {
      rtb_Switch_fe = std::fmod(rtb_Abs1, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/second'

    rtb_IndividualUAVCmd.StartTime.second = rtb_Switch_fe < 0.0 ? -static_cast<
      int32_T>(static_cast<uint32_T>(-rtb_Switch_fe)) : static_cast<int32_T>(
      static_cast<uint32_T>(rtb_Switch_fe));

    // DataTypeConversion: '<S1>/millisecond'
    if (std::isnan(temp) || std::isinf(temp)) {
      rtb_Switch_fe = 0.0;
    } else {
      rtb_Switch_fe = std::fmod(temp, 4.294967296E+9);
    }

    // BusCreator: '<S1>/IndividualUAVCmd' incorporates:
    //   DataTypeConversion: '<S1>/millisecond'

    rtb_IndividualUAVCmd.StartTime.millisecond = rtb_Switch_fe < 0.0 ? -
      static_cast<int32_T>(static_cast<uint32_T>(-rtb_Switch_fe)) : static_cast<
      int32_T>(static_cast<uint32_T>(rtb_Switch_fe));

    // Outputs for Triggered SubSystem: '<S1>/TriggerCurrentMisisonFeedback' incorporates:
    //   TriggerPort: '<S6>/Trigger'

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
      if (rtb_ReceiveCurrentMission_o1 &&
          (codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE !=
           1)) {
        // Send: '<S6>/Send'
        CurrentMissionSendData.SendData(&rtb_IndividualUAVCmd, sizeof
          (IndividualUAVCmd), &status);
      }

      codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
        rtb_ReceiveCurrentMission_o1;
    }

    // End of Outputs for SubSystem: '<S1>/TriggerCurrentMisisonFeedback'

    // Gain: '<S15>/Gain2'
    rtb_Down = -codegenReal2Mission_B.Height;

    // RateTransition: '<Root>/NonDeterministic' incorporates:
    //   DataStoreRead: '<Root>/ReadClock'

    codegenReal2Mission_DW.NonDeterministic_Buffer0 =
      codegenReal2Mission_DW.Clock;

    // Outport: '<Root>/thisTaskStatus'
    codegenReal2Mission_Y.thisTaskStatus = codegenReal2Mission_B.thisTaskStatus;
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
  // Derivatives for Enabled SubSystem: '<S2>/MissionSimUAV'
  if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
    // Derivatives for ModelReference generated from: '<S13>/MissionUavModel'
    MissionUAV_Deriv(&codegenReal2Mission_B.ResetTrigger,
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
  creal_T ahi;
  creal_T thisData;
  real_T NonDeterministic;
  real_T fracSecs;
  real_T second;
  real_T shi;
  real_T temp;
  int32_T NewCMD_FormationPos;
  int32_T NewCMD_MissionMode;
  int32_T NewCMD_numUAV;
  int32_T wholeSecsFromMillis{ 1 };

  // RateTransition: '<Root>/NonDeterministic'
  NonDeterministic = codegenReal2Mission_DW.NonDeterministic_Buffer0;

  // RootInportFunctionCallGenerator generated from: '<Root>/PushNewMission' incorporates:
  //   SubSystem: '<Root>/MissionValidation'

  // Receive: '<S3>/ReceivePushedMissionCMD'
  wholeSecsFromMillis = 1;
  MissionCMDRecvData.RecvData(&codegenReal2Mission_B.ReceivePushedMissionCMD,
    sizeof(IndividualUAVCmd), &wholeSecsFromMillis);

  // MATLAB Function: '<S3>/CommandCheck' incorporates:
  //   DataStoreRead: '<S3>/ReadPreviousCMD'

  rtb_SndCMD = codegenReal2Mission_DW.missionCmd_k;
  second = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.second;
  fracSecs = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.millisecond;
  temp = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.year;
  shi = codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.month;
  if ((codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.month < 1) ||
      (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.month > 12)) {
    wholeSecsFromMillis = static_cast<int32_T>(std::floor((static_cast<real_T>
      (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.month) - 1.0) /
      12.0));
    temp = static_cast<real_T>
      (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.year) +
      static_cast<real_T>(wholeSecsFromMillis);
    shi = ((static_cast<real_T>
            (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.month) -
            1.0) - static_cast<real_T>(wholeSecsFromMillis) * 12.0) + 1.0;
  }

  if (shi < 3.0) {
    temp--;
    shi += 9.0;
  } else {
    shi -= 3.0;
  }

  thisData.re = ((((((365.0 * temp + std::floor(temp / 4.0)) - std::floor(temp /
    100.0)) + std::floor(temp / 400.0)) + std::floor((153.0 * shi + 2.0) / 5.0))
                  + static_cast<real_T>
                  (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.day))
                 + 60.0) - 719529.0;
  temp = 1.34217729E+8 * thisData.re;
  temp -= temp - thisData.re;
  shi = thisData.re * 8.64E+7;
  if ((codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.millisecond < 0) ||
      (1000 <=
       codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.millisecond)) {
    wholeSecsFromMillis = static_cast<int32_T>(std::floor(static_cast<real_T>
      (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.millisecond) /
      1000.0));
    second = static_cast<real_T>
      (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.second) +
      static_cast<real_T>(wholeSecsFromMillis);
    fracSecs = static_cast<real_T>
      (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.millisecond) -
      static_cast<real_T>(wholeSecsFromMillis) * 1000.0;
  }

  ahi.re = shi;
  ahi.im = (thisData.re - temp) * 8.64E+7 + (temp * 8.64E+7 - shi);
  thisData = plus_aAYNoTqG(ahi, (60.0 * static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.hour) +
    static_cast<real_T>
    (codegenReal2Mission_B.ReceivePushedMissionCMD.StartTime.minute)) * 60000.0);
  wholeSecsFromMillis = codegenReal2Mission_B.ReceivePushedMissionCMD.SequenceId;
  NewCMD_MissionMode = codegenReal2Mission_B.ReceivePushedMissionCMD.MissionMode;
  NewCMD_numUAV = codegenReal2Mission_B.ReceivePushedMissionCMD.numUAV;
  NewCMD_FormationPos =
    codegenReal2Mission_B.ReceivePushedMissionCMD.FormationPos;
  second = (plus_aAYNoTqG(plus_aAYNoTqG(thisData, second * 1000.0), fracSecs)).
    re / 1000.0;
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
       codegenReal2Mission_DW.missionCmd_k.StartTime, wholeSecsFromMillis,
       NewCMD_MissionMode,
       codegenReal2Mission_B.ReceivePushedMissionCMD.MissionLocation,
       codegenReal2Mission_B.ReceivePushedMissionCMD.params,
       codegenReal2Mission_B.ReceivePushedMissionCMD.StartPosition,
       NewCMD_numUAV, NewCMD_FormationPos, second)) {
    if (codegenReal2Mission_DW.missionCmd_k.SequenceId ==
        codegenReal2Mission_B.ReceivePushedMissionCMD.SequenceId) {
      printf("Use a new Sequence ID for each new mission!");
      fflush(stdout);
    } else if (NonDeterministic > second) {
      printf("Mission Start Time has already passed!");
      fflush(stdout);
    } else {
      codegenReal2Mission_DW.missionCmd_k.SequenceId = wholeSecsFromMillis;
      codegenReal2Mission_DW.missionCmd_k.MissionMode = NewCMD_MissionMode;
      codegenReal2Mission_DW.missionCmd_k.MissionLocation =
        codegenReal2Mission_B.ReceivePushedMissionCMD.MissionLocation;
      codegenReal2Mission_DW.missionCmd_k.params =
        codegenReal2Mission_B.ReceivePushedMissionCMD.params;
      codegenReal2Mission_DW.missionCmd_k.StartPosition =
        codegenReal2Mission_B.ReceivePushedMissionCMD.StartPosition;
      codegenReal2Mission_DW.missionCmd_k.numUAV = NewCMD_numUAV;
      codegenReal2Mission_DW.missionCmd_k.FormationPos = NewCMD_FormationPos;
      codegenReal2Mission_DW.missionCmd_k.StartTime = second;
      rtb_SndCMD.SequenceId = wholeSecsFromMillis;
      rtb_SndCMD.MissionMode = NewCMD_MissionMode;
      rtb_SndCMD.MissionLocation =
        codegenReal2Mission_B.ReceivePushedMissionCMD.MissionLocation;
      rtb_SndCMD.params = codegenReal2Mission_B.ReceivePushedMissionCMD.params;
      rtb_SndCMD.StartPosition =
        codegenReal2Mission_B.ReceivePushedMissionCMD.StartPosition;
      rtb_SndCMD.numUAV = NewCMD_numUAV;
      rtb_SndCMD.FormationPos = NewCMD_FormationPos;
      rtb_SndCMD.StartTime = second;
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

  {
    int32_T i;

    // Start for slMsgMgr: '<Root>/slMsgMgr'
    codegenReal2Mission_initMemPool
      (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd,
       &codegenReal2Mission_DW.slMsgMgr_memArray_missionCmd[0],
       &codegenReal2Mission_DW.slMsgMgr_freeList_missionCmd[0], 6);
    codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
      POS_ZCSIG;
    codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE = POS_ZCSIG;
    codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE_o =
      UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE_b =
      UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.WayPointGenerator_Trig_ZCE = UNINITIALIZED_ZCSIG;
    codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE =
      UNINITIALIZED_ZCSIG;

    // SystemInitialize for Chart: '<S2>/PreemptableMissionModeSelector'
    codegenReal2Mission_B.GuidanceCmds.Height = 0.0;
    codegenReal2Mission_B.GuidanceCmds.AirSpeed = 0.0;
    codegenReal2Mission_B.GuidanceCmds.HeadingAngle = 0.0;

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CirclingNav' 
    // Start for MATLABSystem: '<S19>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_a.isInitialized = 0;
    codegenReal2Mission_DW.obj_a.isInitialized = 1;
    codegenReal2Mission_DW.obj_a.PrevResetSignal = 0.0;
    codegenReal2Mission_DW.obj_a.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_a.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S19>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_a.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_a.PrevResetSignal *= 0.0;
    codegenReal2Mission_DW.obj_a.NumCircles *= 0.0;
    codegenReal2Mission_DW.obj_a.StartFlag = true;
    codegenReal2Mission_DW.obj_a.SelectTurnDirectionFlag = true;
    codegenReal2Mission_DW.obj_a.TurnDirectionInternal = 1.0;
    codegenReal2Mission_DW.obj_a.OrbitRadiusFlag = 0U;
    codegenReal2Mission_DW.obj_a.LookaheadDistFlag = 0U;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CirclingNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 
    // Start for MATLABSystem: '<S18>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_n.isInitialized = 0;
    codegenReal2Mission_DW.obj_n.isInitialized = 1;
    codegenReal2Mission_DW.obj_n.PrevResetSignal = 0.0;
    codegenReal2Mission_DW.obj_n.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_n.NumCircles = 0.0;

    // InitializeConditions for MATLABSystem: '<S18>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_n.OrbitRadiusInternal = (rtNaN);
    codegenReal2Mission_DW.obj_n.PrevResetSignal *= 0.0;
    codegenReal2Mission_DW.obj_n.NumCircles *= 0.0;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CirclingNav' 
    // Start for MATLABSystem: '<S19>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_a.PrevPosition[0] = 0.0;
    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[0] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S19>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[0] = (rtNaN);
    codegenReal2Mission_DW.obj_a.PrevPosition[0] *= 0.0;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CirclingNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 
    // Start for MATLABSystem: '<S18>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_n.PrevPosition[0] = 0.0;
    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[0] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S18>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[0] = (rtNaN);
    codegenReal2Mission_DW.obj_n.PrevPosition[0] *= 0.0;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CirclingNav' 
    // Start for MATLABSystem: '<S19>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_a.PrevPosition[1] = 0.0;
    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[1] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S19>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[1] = (rtNaN);
    codegenReal2Mission_DW.obj_a.PrevPosition[1] *= 0.0;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CirclingNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 
    // Start for MATLABSystem: '<S18>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_n.PrevPosition[1] = 0.0;
    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[1] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S18>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[1] = (rtNaN);
    codegenReal2Mission_DW.obj_n.PrevPosition[1] *= 0.0;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CirclingNav' 
    // Start for MATLABSystem: '<S19>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_a.PrevPosition[2] = 0.0;
    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[2] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S19>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_a.OrbitCenterInternal[2] = (rtNaN);
    codegenReal2Mission_DW.obj_a.PrevPosition[2] *= 0.0;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CirclingNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 
    // Start for MATLABSystem: '<S18>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_n.PrevPosition[2] = 0.0;
    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[2] = (rtNaN);

    // InitializeConditions for MATLABSystem: '<S18>/Orbit Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_n.OrbitCenterInternal[2] = (rtNaN);
    codegenReal2Mission_DW.obj_n.PrevPosition[2] *= 0.0;
    codegenReal2Mission_DW.obj_n.StartFlag = true;
    codegenReal2Mission_DW.obj_n.SelectTurnDirectionFlag = true;
    codegenReal2Mission_DW.obj_n.TurnDirectionInternal = 1.0;
    codegenReal2Mission_DW.obj_n.OrbitRadiusFlag = 0U;
    codegenReal2Mission_DW.obj_n.LookaheadDistFlag = 0U;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.OrbitFollower.CircleDisplayNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.WaypointFollower.HorizontalFormationNav' 
    // Start for MATLABSystem: '<S22>/Waypoint Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj.LastWaypointFlag = false;
    codegenReal2Mission_DW.obj.StartFlag = true;
    codegenReal2Mission_DW.obj.LookaheadFactor = 1.01;
    codegenReal2Mission_DW.obj.isInitialized = 0;
    codegenReal2Mission_DW.obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S22>/Waypoint Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj.WaypointIndex = 1.0;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.WaypointFollower.HorizontalFormationNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.WaypointFollower.CustomFormationNav' 
    // Start for MATLABSystem: '<S21>/Waypoint Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_i.LastWaypointFlag = false;
    codegenReal2Mission_DW.obj_i.StartFlag = true;
    codegenReal2Mission_DW.obj_i.LookaheadFactor = 1.01;
    codegenReal2Mission_DW.obj_i.isInitialized = 0;
    codegenReal2Mission_DW.obj_i.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S21>/Waypoint Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_i.WaypointIndex = 1.0;

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.WaypointFollower.CustomFormationNav' 

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.RunWayNav'
    // Start for MATLABSystem: '<S20>/Waypoint Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_e.LastWaypointFlag = false;
    codegenReal2Mission_DW.obj_e.StartFlag = true;
    codegenReal2Mission_DW.obj_e.LookaheadFactor = 1.01;
    codegenReal2Mission_DW.obj_e.isInitialized = 0;
    codegenReal2Mission_DW.obj_e.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S20>/Waypoint Follower' incorporates:
    //   Chart: '<S2>/PreemptableMissionModeSelector'

    codegenReal2Mission_DW.obj_e.WaypointIndex = 1.0;

    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.WaypointFollower.CustomFormationNav' 
    // SystemInitialize for IfAction SubSystem: '<S14>/GuidanceLogic.WaypointFollower.HorizontalFormationNav' 
    for (i = 0; i < 30720; i++) {
      // Start for MATLABSystem: '<S22>/Waypoint Follower' incorporates:
      //   Chart: '<S2>/PreemptableMissionModeSelector'

      codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);

      // InitializeConditions for MATLABSystem: '<S22>/Waypoint Follower' incorporates:
      //   Chart: '<S2>/PreemptableMissionModeSelector'

      codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);

      // Start for MATLABSystem: '<S21>/Waypoint Follower' incorporates:
      //   Chart: '<S2>/PreemptableMissionModeSelector'

      codegenReal2Mission_DW.obj_i.WaypointsInternal[i] = (rtNaN);

      // InitializeConditions for MATLABSystem: '<S21>/Waypoint Follower' incorporates:
      //   Chart: '<S2>/PreemptableMissionModeSelector'

      codegenReal2Mission_DW.obj_i.WaypointsInternal[i] = (rtNaN);

      // Start for MATLABSystem: '<S20>/Waypoint Follower' incorporates:
      //   Chart: '<S2>/PreemptableMissionModeSelector'

      codegenReal2Mission_DW.obj_e.WaypointsInternal[i] = (rtNaN);

      // InitializeConditions for MATLABSystem: '<S20>/Waypoint Follower' incorporates:
      //   Chart: '<S2>/PreemptableMissionModeSelector'

      codegenReal2Mission_DW.obj_e.WaypointsInternal[i] = (rtNaN);
    }

    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.WaypointFollower.HorizontalFormationNav' 
    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.WaypointFollower.CustomFormationNav' 
    // End of SystemInitialize for SubSystem: '<S14>/GuidanceLogic.RunWayNav'

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
  }

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
