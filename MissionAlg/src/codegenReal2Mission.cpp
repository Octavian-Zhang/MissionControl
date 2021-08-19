#include "codegenReal2Mission.h"
#include "codegenReal2Mission_private.h"
#include "LookUp_real_T_real_T.h"
#include "div_s32.h"
#include "floor_jeUa7tf2.h"
#include "print_processing_4NEcbkvn.h"
#include "print_processing_J3zqIUjT.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "split_MzIWb6Db.h"

const uint8_T codegenReal2Mission_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T codegenReal2Mission_IN_Pending{ 1U };

const uint8_T codegenReal2Mission_IN_Sending{ 2U };

const uint8_T codegenReal2Mission_IN_NotShift{ 1U };

const uint8_T codegenReal2Mission_IN_Shift{ 2U };

const uint8_T codegenReal2Mission_IN_Running{ 2U };

const uint8_T codegenReal2Mission_IN_ImmedMission{ 1U };

const uint8_T codegenReal2Mission_IN_WaitToStart{ 2U };

const uint8_T codegenReal2Mission_IN_OutOfRange{ 1U };

const uint8_T codegenReal2Mission_IN_Turning{ 2U };

const uint8_T codegenReal2Mission_IN_WithInRange{ 3U };

const uint8_T codegenReal2Mission_IN_Long{ 1U };

const uint8_T codegenReal2Mission_IN_Short{ 2U };

const uint8_T codegenReal2Mission_IN_FlightMission{ 1U };

const uint8_T codegenReal2Mission_IN_ImmedMission_l{ 2U };

const FixedWingGuidanceBus codegenReal2Mission_rtZFixedWingGuidanceBus{
    0.0,
    0.0,
    0.0
} ;

real_T AltitudeGCS;
real_T LatitudeGCS;
real_T LongitudeGCS;
void* AltitudeGCS_m0;
void* LatitudeGCS_m0;
void* LongitudeGCS_m0;
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
    (void) std::memcpy(y, x,
                       static_cast<uint_T>(nXc)*sizeof(real_T));
    rtsiSetdX(si, f0);
    codegenReal2Mission_derivatives();
    temp = 0.5 * h;
    for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (temp*f0[i]);
    }

    rtsiSetT(si, t + temp);
    rtsiSetdX(si, f1);
    this->step();
    codegenReal2Mission_derivatives();
    for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (temp*f1[i]);
    }

    rtsiSetdX(si, f2);
    this->step();
    codegenReal2Mission_derivatives();
    for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (h*f2[i]);
    }

    rtsiSetT(si, tnew);
    rtsiSetdX(si, f3);
    this->step();
    codegenReal2Mission_derivatives();
    temp = h / 6.0;
    for (i = 0; i < nXc; i++) {
        x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
    }

    rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

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

creal_T codegenReal2MissionModelClass::codegenReal2Mission_plus(const creal_T a,
    real_T b)
{
    creal_T c;
    creal_T t;
    real_T ahi;
    real_T alo;
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

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_pop
    (Buffer_missionCmd *q, Msg_missionCmd *elementOut)
{
    boolean_T isPop;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    return isPop;
}

void codegenReal2MissionModelClass::codegenReal2Mission_freeMemPool
    (MemPool_missionCmd *memPool, missionCmd *dataPtr)
{
    memPool->fFreeList[memPool->fNumFree] = dataPtr;
    memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree + 1);
}

void codegenReal2MissionModelClass::codegenReal2Mission_destroyMsg
    (Msg_missionCmd *msg)
{
    codegenReal2Mission_freeMemPool
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd, msg->fData);
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    return status;
}

missionCmd *codegenReal2MissionModelClass::codegenReal2Mission_allocMemPool
    (MemPool_missionCmd *memPool, int32_T width)
{
    missionCmd *dataPtr;
    if (memPool->fNumFree > 0) {
        memPool->fNumFree = static_cast<int32_T>(memPool->fNumFree - 1);
        dataPtr = memPool->fFreeList[memPool->fNumFree];
    } else if (memPool->fNumUsed < memPool->fSize) {
        dataPtr = &memPool->fMemArray[memPool->fNumUsed];
        memPool->fNumUsed = static_cast<int32_T>(memPool->fNumUsed + width);
    } else {
        dataPtr = nullptr;
    }

    return dataPtr;
}

Msg_missionCmd codegenReal2MissionModelClass::codegenReal2Mission_createMsg(
    const missionCmd *data)
{
    Msg_missionCmd msg;
    msg.fData = codegenReal2Mission_allocMemPool
        (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd, 1);
    *msg.fData = *data;
    return msg;
}

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_push
    (Buffer_missionCmd *q, Msg_missionCmd *element)
{
    boolean_T isPush;
    if (q->fOccupied) {
        codegenReal2Mission_destroyMsg(&q->fMsg);
    }

    q->fMsg = *element;
    q->fOccupied = true;
    isPush = true;
    return isPush;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveCurrentMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    msg = codegenReal2Mission_createMsg(data);
    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveCurrentMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveCurrentMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_ReceiveCurrentMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveThisMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    msg = codegenReal2Mission_createMsg(data);
    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    return status;
}

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_RecvData
    (missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    return status;
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
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rEQ0) ^ 1))) {
                q = std::abs((delta + 3.1415926535897931) / 6.2831853071795862);
                rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs(q -
                    std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^ 1));
            }

            if (rEQ0) {
                thetaWrap = 0.0;
            } else if (delta + 3.1415926535897931 < 0.0) {
                thetaWrap += 6.2831853071795862;
            }
        }

        if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
                (delta + 3.1415926535897931 > 0.0)))) {
            thetaWrap = 6.2831853071795862;
        }

        delta = thetaWrap - 3.1415926535897931;
    }

    return delta;
}

void codegenReal2MissionModelClass::codegenReal2Mission_any(const boolean_T
    x_data[], const int32_T x_size[2], boolean_T y_data[], int32_T *y_size)
{
    int32_T i1;
    int32_T i2;
    int32_T ix;
    int32_T j;
    int32_T outsize_idx_0;
    boolean_T exitg1;
    outsize_idx_0 = x_size[0];
    *y_size = x_size[0];
    for (i1 = 0; i1 <= static_cast<int32_T>(outsize_idx_0 - 1); i1++) {
        y_data[i1] = false;
    }

    outsize_idx_0 = x_size[0];
    i1 = 0;
    i2 = static_cast<int32_T>(x_size[0] << 1);
    for (j = 0; j <= static_cast<int32_T>(outsize_idx_0 - 1); j++) {
        i1 = static_cast<int32_T>(i1 + 1);
        i2 = static_cast<int32_T>(i2 + 1);
        ix = i1;
        exitg1 = false;
        while ((!exitg1) && (static_cast<boolean_T>(static_cast<int32_T>
                 ((outsize_idx_0 > 0) & (ix <= i2))))) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (x_data[static_cast<int32_T>(ix - 1)]) ^ 1))) {
                ix = static_cast<int32_T>(ix + outsize_idx_0);
            } else {
                y_data[j] = true;
                exitg1 = true;
            }
        }
    }
}

void codegenReal2MissionModelClass::
    codegenReal2Mission_WaypointFollowerBase_getDistinctWpts(const real_T
    waypoints_data[], const int32_T waypoints_size[2], real_T distinctWpts_data[],
    int32_T distinctWpts_size[2])
{
    int32_T waypoints_size_0[2];
    int32_T c;
    int32_T d;
    int32_T j_size_idx_0;
    int32_T loop_ub_tmp;
    int32_T trueCount;
    int32_T waypoints_size_idx_0;
    int16_T j_data[900];
    boolean_T waypoints_data_0[2700];
    boolean_T i_data[900];
    if (static_cast<boolean_T>(static_cast<int32_T>((waypoints_size[0] == 0) |
            (waypoints_size[1] == 0)))) {
        distinctWpts_size[0] = 0;
        distinctWpts_size[1] = 0;
    } else {
        if (2 > waypoints_size[0]) {
            d = 0;
            c = -1;
        } else {
            d = 1;
            c = static_cast<int32_T>(waypoints_size[0] - 1);
        }

        c = static_cast<int32_T>(c - d);
        waypoints_size_idx_0 = static_cast<int32_T>(c + 2);
        loop_ub_tmp = static_cast<int32_T>(c + 1);
        for (trueCount = 0; trueCount < 3; trueCount++) {
            for (j_size_idx_0 = 0; j_size_idx_0 <= static_cast<int32_T>
                    (loop_ub_tmp - 1); j_size_idx_0++) {
                codegenReal2Mission_DW.waypoints_data[static_cast<int32_T>
                    (j_size_idx_0 + static_cast<int32_T>(static_cast<int32_T>(c
                       + 2) * trueCount))] = waypoints_data[static_cast<int32_T>
                    (static_cast<int32_T>(d + j_size_idx_0) +
                     static_cast<int32_T>(waypoints_size[0] * trueCount))];
            }
        }

        codegenReal2Mission_DW.waypoints_data[static_cast<int32_T>(c + 1)] =
            (rtNaN);
        codegenReal2Mission_DW.waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(c + c) + 3)] = (rtNaN);
        codegenReal2Mission_DW.waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(c + static_cast<int32_T>(static_cast<int32_T>
               (c + 2) << 1)) + 1)] = (rtNaN);
        d = waypoints_size[0];
        waypoints_size_0[0] = waypoints_size[0];
        waypoints_size_0[1] = 3;
        for (c = 0; c < 3; c++) {
            for (trueCount = 0; trueCount <= static_cast<int32_T>(d - 1);
                    trueCount++) {
                waypoints_data_0[static_cast<int32_T>(trueCount +
                    static_cast<int32_T>(waypoints_size_0[0] * c))] =
                    (waypoints_data[static_cast<int32_T>(trueCount +
                      static_cast<int32_T>(waypoints_size[0] * c))] !=
                     codegenReal2Mission_DW.waypoints_data[static_cast<int32_T>
                     (trueCount + static_cast<int32_T>(waypoints_size_idx_0 * c))]);
            }
        }

        codegenReal2Mission_any(waypoints_data_0, waypoints_size_0, i_data, &c);
        d = static_cast<int32_T>(c - 1);
        trueCount = 0;
        for (c = 0; c <= d; c++) {
            if (i_data[c]) {
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        j_size_idx_0 = trueCount;
        trueCount = 0;
        for (c = 0; c <= d; c++) {
            if (i_data[c]) {
                j_data[trueCount] = static_cast<int16_T>(static_cast<int32_T>(c
                    + 1));
                trueCount = static_cast<int32_T>(trueCount + 1);
            }
        }

        d = waypoints_size[1];
        distinctWpts_size[0] = j_size_idx_0;
        distinctWpts_size[1] = waypoints_size[1];
        for (c = 0; c <= static_cast<int32_T>(d - 1); c++) {
            for (trueCount = 0; trueCount <= static_cast<int32_T>(j_size_idx_0 -
                  1); trueCount++) {
                distinctWpts_data[static_cast<int32_T>(trueCount +
                    static_cast<int32_T>(j_size_idx_0 * c))] = waypoints_data[
                    static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<int32_T>(j_data[trueCount]) +
                     static_cast<int32_T>(waypoints_size[0] * c)) - 1)];
            }
        }
    }
}

void codegenReal2MissionModelClass::
    codegenReal2Mission_WaypointFollowerBase_createWaypoint
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     real_T virtualWaypoint[3])
{
    virtualWaypoint[0] = obj->InitialPose[0];
    virtualWaypoint[1] = obj->InitialPose[1];
    virtualWaypoint[2] = obj->InitialPose[2];
    obj->StartFlag = false;
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
    emxArray->size = (int32_T *)std::malloc(static_cast<uint32_T>(sizeof(int32_T)
        * static_cast<uint32_T>(numDimensions)));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = true;
    for (i = 0; i <= static_cast<int32_T>(numDimensions - 1); i++) {
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

        emxArray->data = (real_T *)newData;
        emxArray->allocatedSize = i;
        emxArray->canFreeData = true;
    }
}

void codegenReal2MissionModelClass::codegenReal2Mission_emxFree_real_T
    (emxArray_real_T_codegenReal2Mission_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_real_T_codegenReal2Mission_T *)nullptr) {
        if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)
                ->canFreeData) {
            std::free((*pEmxArray)->data);
        }

        std::free((*pEmxArray)->size);
        std::free(*pEmxArray);
        *pEmxArray = (emxArray_real_T_codegenReal2Mission_T *)nullptr;
    }
}

void codegenReal2MissionModelClass::
    codegenReal2Mission_WaypointFollowerBase_searchClosestPath
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     const real_T waypoints_data[], const int32_T waypoints_size[2], const
     real_T currentPose[4])
{
    emxArray_real_T_codegenReal2Mission_T *d;
    real_T currentPose_0[3];
    real_T currentPose_1[3];
    real_T currentPose_2[3];
    real_T currentPose_tmp;
    real_T currentPose_tmp_0;
    real_T currentPose_tmp_1;
    real_T lambda;
    real_T lambda_tmp_tmp;
    real_T lambda_tmp_tmp_0;
    real_T lambda_tmp_tmp_1;
    real_T tempEndWaypoint_idx_0;
    real_T tempEndWaypoint_idx_1;
    real_T tempStartWaypoint;
    real_T tempStartWaypoint_idx_0;
    real_T tempStartWaypoint_idx_1;
    int32_T b;
    int32_T b_idx;
    int32_T b_k;
    int32_T last;
    boolean_T exitg1;
    codegenReal2Mission_emxInit_real_T(&d, 2);
    b_k = static_cast<int32_T>(d->size[0] * d->size[1]);
    d->size[0] = 1;
    d->size[1] = static_cast<int32_T>(obj->NumWaypoints - 1.0);
    codegenReal2Mission_emxEnsureCapacity_real_T(d, b_k);
    last = static_cast<int32_T>(static_cast<int32_T>(obj->NumWaypoints - 1.0) -
        1);
    for (b_k = 0; b_k <= last; b_k++) {
        d->data[b_k] = 0.0;
        tempStartWaypoint = waypoints_data[b_k];
        lambda = waypoints_data[static_cast<int32_T>(static_cast<int32_T>((
            static_cast<real_T>(b_k) + 1.0) + 1.0) - 1)];
        lambda_tmp_tmp = lambda - tempStartWaypoint;
        currentPose_tmp = currentPose[0] - tempStartWaypoint;
        currentPose_0[0] = currentPose_tmp;
        currentPose_1[0] = currentPose[0] - lambda;
        tempStartWaypoint_idx_0 = tempStartWaypoint;
        tempEndWaypoint_idx_0 = lambda;
        tempStartWaypoint = waypoints_data[static_cast<int32_T>(b_k +
            waypoints_size[0])];
        lambda = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
            static_cast<int32_T>((static_cast<real_T>(b_k) + 1.0) + 1.0) +
            waypoints_size[0]) - 1)];
        lambda_tmp_tmp_0 = lambda - tempStartWaypoint;
        currentPose_tmp_0 = currentPose[1] - tempStartWaypoint;
        currentPose_0[1] = currentPose_tmp_0;
        currentPose_1[1] = currentPose[1] - lambda;
        tempStartWaypoint_idx_1 = tempStartWaypoint;
        tempEndWaypoint_idx_1 = lambda;
        tempStartWaypoint = waypoints_data[static_cast<int32_T>(b_k +
            static_cast<int32_T>(waypoints_size[0] << 1))];
        lambda = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
            static_cast<int32_T>((static_cast<real_T>(b_k) + 1.0) + 1.0) +
            static_cast<int32_T>(waypoints_size[0] << 1)) - 1)];
        lambda_tmp_tmp_1 = lambda - tempStartWaypoint;
        currentPose_tmp_1 = currentPose[2] - tempStartWaypoint;
        currentPose_0[2] = currentPose_tmp_1;
        currentPose_1[2] = currentPose[2] - lambda;
        lambda = (currentPose_tmp_1 * lambda_tmp_tmp_1 + (currentPose_tmp_0 *
                   lambda_tmp_tmp_0 + currentPose_tmp * lambda_tmp_tmp)) /
            (lambda_tmp_tmp_1 * lambda_tmp_tmp_1 + (lambda_tmp_tmp_0 *
              lambda_tmp_tmp_0 + lambda_tmp_tmp * lambda_tmp_tmp));
        currentPose_2[0] = currentPose[0] - ((tempEndWaypoint_idx_0 -
            tempStartWaypoint_idx_0) * lambda + tempStartWaypoint_idx_0);
        currentPose_2[1] = currentPose[1] - ((tempEndWaypoint_idx_1 -
            tempStartWaypoint_idx_1) * lambda + tempStartWaypoint_idx_1);
        currentPose_2[2] = currentPose[2] - (lambda_tmp_tmp_1 * lambda +
            tempStartWaypoint);
        if (lambda < 0.0) {
            d->data[b_k] = codegenReal2Mission_norm_b(currentPose_0);
        } else if (lambda > 1.0) {
            d->data[b_k] = codegenReal2Mission_norm_b(currentPose_1);
        } else {
            d->data[b_k] = codegenReal2Mission_norm_b(currentPose_2);
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
            lambda = d->data[static_cast<int32_T>(b_idx - 1)];
            b = b_idx;
            for (b_k = static_cast<int32_T>(b + 1); b_k <= last; b_k++) {
                tempStartWaypoint = d->data[static_cast<int32_T>(b_k - 1)];
                if (lambda > tempStartWaypoint) {
                    lambda = tempStartWaypoint;
                    b_idx = b_k;
                }
            }
        }
    }

    codegenReal2Mission_emxFree_real_T(&d);
    obj->WaypointIndex = static_cast<real_T>(b_idx);
    obj->SearchFlag = false;
}

void codegenReal2MissionModelClass::
    codegenReal2Mission_WaypointFollowerBase_getWaypoints
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
     startWaypoint[3], real_T endWaypoint[3])
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

    startWaypoint[0] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>
        (obj->WaypointIndex) - 1)];
    endWaypoint[0] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>
        (obj->WaypointIndex + 1.0) - 1)];
    startWaypoint[1] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex) + waypoints_size[0]) - 1)];
    endWaypoint[1] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex + 1.0) + waypoints_size[0]) - 1)];
    startWaypoint[2] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex) + static_cast<int32_T>
        (waypoints_size[0] << 1)) - 1)];
    endWaypoint[2] = waypoints_data[static_cast<int32_T>(static_cast<int32_T>(
        static_cast<int32_T>(obj->WaypointIndex + 1.0) + static_cast<int32_T>
        (waypoints_size[0] << 1)) - 1)];
}

void codegenReal2MissionModelClass::
    codegenReal2Mission_WaypointFollowerBase_endWaypointReached_b
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     const real_T waypoints_data[], const int32_T waypoints_size[2], real_T
     curStartWaypoint[3], real_T curEndWaypoint[3], const real_T currentPose[4])
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
        curEndWaypoint_1 = (curEndWaypoint_tmp / tmp_0 * (tmp[0] /
                             curEndWaypoint_1) + curEndWaypoint_tmp_0 / tmp_0 *
                            (tmp[1] / curEndWaypoint_1)) + curEndWaypoint_tmp_1 /
            tmp_0 * (tmp[2] / curEndWaypoint_1);
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

        curStartWaypoint[0] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(obj->WaypointIndex) - 1)];
        curEndWaypoint[0] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(obj->WaypointIndex + 1.0) - 1)];
        curStartWaypoint[1] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
              waypoints_size[0]) - 1)];
        curEndWaypoint[1] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex + 1.0)
              + waypoints_size[0]) - 1)];
        curStartWaypoint[2] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex) +
              static_cast<int32_T>(waypoints_size[0] << 1)) - 1)];
        curEndWaypoint[2] = waypoints_data[static_cast<int32_T>
            (static_cast<int32_T>(static_cast<int32_T>(obj->WaypointIndex + 1.0)
              + static_cast<int32_T>(waypoints_size[0] << 1)) - 1)];
    }
}

real_T codegenReal2MissionModelClass::
    codegenReal2Mission_WaypointFollowerBase_pointToLine(const real_T p1[3],
    const real_T p2[3], const real_T p[3])
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
    startWaypoint[3], const real_T endWaypoint[3], const real_T currentPosition
    [3])
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
        (lambda_tmp_tmp_1 * lambda_tmp_tmp_1 + (lambda_tmp_tmp_0 *
          lambda_tmp_tmp_0 + lambda_tmp_tmp * lambda_tmp_tmp));
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
    real_T a;
    real_T a_tmp_tmp;
    real_T a_tmp_tmp_0;
    real_T b;
    real_T b_tmp_idx_0_tmp;
    real_T b_tmp_idx_1_tmp;
    real_T b_tmp_idx_2_tmp;
    b = endWaypoint[0] - startWaypoint[0];
    b_tmp_idx_0_tmp = startWaypoint[0] - currentPosition[0];
    a_tmp_tmp = endWaypoint[1] - startWaypoint[1];
    b_tmp_idx_1_tmp = startWaypoint[1] - currentPosition[1];
    a_tmp_tmp_0 = endWaypoint[2] - startWaypoint[2];
    a = a_tmp_tmp_0 * a_tmp_tmp_0 + (a_tmp_tmp * a_tmp_tmp + b * b);
    b_tmp_idx_2_tmp = startWaypoint[2] - currentPosition[2];
    b = ((b * b_tmp_idx_0_tmp + a_tmp_tmp * b_tmp_idx_1_tmp) + a_tmp_tmp_0 *
         b_tmp_idx_2_tmp) * 2.0;
    b_tmp_idx_0_tmp = std::sqrt(b * b - (((b_tmp_idx_0_tmp * b_tmp_idx_0_tmp +
        b_tmp_idx_1_tmp * b_tmp_idx_1_tmp) + b_tmp_idx_2_tmp * b_tmp_idx_2_tmp)
        - obj->LookaheadDistance * obj->LookaheadDistance) * (4.0 * a));
    a = std::fmax((-b + b_tmp_idx_0_tmp) / 2.0 / a, (-b - b_tmp_idx_0_tmp) / 2.0
                  / a);
    lookaheadPoint[0] = (1.0 - a) * startWaypoint[0] + a * endWaypoint[0];
    lookaheadPoint[1] = (1.0 - a) * startWaypoint[1] + a * endWaypoint[1];
    lookaheadPoint[2] = (1.0 - a) * startWaypoint[2] + a * endWaypoint[2];
}

void codegenReal2MissionModelClass::
    codegenReal2Mission_WaypointFollowerBase_stepInternal
    (uav_sluav_internal_system_WaypointFollower_codegenReal2Mission_T *obj,
     const real_T currentPose[4], real_T waypointsIn_data[], int32_T
     waypointsIn_size[2], real_T lookaheadDist, real_T lookaheadPoint[3], real_T
     *desiredHeading, real_T *desiredYaw, uint8_T *lookaheadDistFlag, real_T
     *crossTrackError, uint8_T *status)
{
    real_T b_endWaypoint[3];
    real_T virtualWaypoint[3];
    real_T absx_tmp;
    real_T r;
    int32_T waypointsIn_size_0[2];
    int32_T waypoints_size[2];
    int32_T b_exponent;
    int32_T b_exponent_0;
    int32_T c;
    int32_T loop_ub;
    int32_T loop_ub_0;
    int32_T waypoints;
    int8_T waypointsIn[2];
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T p;
    boolean_T p_0;
    obj->LookaheadDistFlag = 0U;
    if (lookaheadDist < 10.0) {
        lookaheadDist = 10.0;
        obj->LookaheadDistFlag = 1U;
    }

    *lookaheadDistFlag = obj->LookaheadDistFlag;
    obj->InitialPose[0] = 0.0;
    obj->InitialPose[1] = 0.0;
    obj->InitialPose[2] = 0.0;
    obj->InitialPose[3] = 0.0;
    for (c = 0; c < 2700; c++) {
        codegenReal2Mission_DW.paddedWaypts[c] = (rtNaN);
    }

    loop_ub = waypointsIn_size[1];
    for (c = 0; c <= static_cast<int32_T>(loop_ub - 1); c++) {
        loop_ub_0 = waypointsIn_size[0];
        for (waypoints = 0; waypoints <= static_cast<int32_T>(loop_ub_0 - 1);
                waypoints++) {
            codegenReal2Mission_DW.paddedWaypts[static_cast<int32_T>(waypoints +
                static_cast<int32_T>(900 * c))] = waypointsIn_data
                [static_cast<int32_T>(waypoints + static_cast<int32_T>
                (waypointsIn_size[0] * c))];
        }
    }

    p = false;
    p_0 = true;
    c = 0;
    exitg1 = false;
    while ((!exitg1) && (c < 2700)) {
        if ((obj->WaypointsInternal[c] == codegenReal2Mission_DW.paddedWaypts[c])
            || (std::isnan(obj->WaypointsInternal[c]) && std::isnan
                (codegenReal2Mission_DW.paddedWaypts[c]))) {
            c = static_cast<int32_T>(c + 1);
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
        std::memcpy(&obj->WaypointsInternal[0],
                    &codegenReal2Mission_DW.paddedWaypts[0],
                    static_cast<uint32_T>(2700U * sizeof(real_T)));
        obj->WaypointIndex = 1.0;
        obj->SearchFlag = true;
    }

    waypointsIn_size_0[0] = waypointsIn_size[0];
    waypointsIn_size_0[1] = waypointsIn_size[1];
    loop_ub = static_cast<int32_T>(static_cast<int32_T>(waypointsIn_size[0] *
        waypointsIn_size[1]) - 1);
    for (c = 0; c <= loop_ub; c++) {
        codegenReal2Mission_DW.paddedWaypts[c] = waypointsIn_data[c];
    }

    codegenReal2Mission_WaypointFollowerBase_getDistinctWpts
        (codegenReal2Mission_DW.paddedWaypts, waypointsIn_size_0,
         waypointsIn_data, waypointsIn_size);
    obj->NumWaypoints = static_cast<real_T>(waypointsIn_size[0]);
    obj->LookaheadDistance = lookaheadDist;
    if (static_cast<boolean_T>(static_cast<int32_T>((waypointsIn_size[0] == 0) |
          (waypointsIn_size[1] == 0)))) {
        lookaheadPoint[0] = lookaheadDist * std::cos(currentPose[3]) +
            currentPose[0];
        lookaheadPoint[1] = lookaheadDist * std::sin(currentPose[3]) +
            currentPose[1];
        lookaheadPoint[2] = lookaheadDist * 0.0 + currentPose[2];
        *desiredHeading = currentPose[3];
        *desiredYaw = currentPose[3];
        *crossTrackError = 0.0;
        *status = 1U;
    } else {
        guard1 = false;
        if (waypointsIn_size[0] == 1) {
            if (obj->StartFlag) {
                obj->InitialPose[0] = currentPose[0];
                obj->InitialPose[1] = currentPose[1];
                obj->InitialPose[2] = currentPose[2];
                obj->InitialPose[3] = currentPose[3];
            }

            virtualWaypoint[0] = waypointsIn_data[0] - currentPose[0];
            virtualWaypoint[1] = waypointsIn_data[1] - currentPose[1];
            virtualWaypoint[2] = waypointsIn_data[2] - currentPose[2];
            if (codegenReal2Mission_norm_b(virtualWaypoint) <
                    1.4901161193847656E-8) {
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
                obj->NumWaypoints = 2.0;
                waypointsIn[0] = 1;
                waypointsIn[1] = 3;
                waypoints_size[0] = 2;
                waypoints_size[1] = 3;
                for (c = 0; c < 3; c++) {
                    waypoints = static_cast<int32_T>(c << 1);
                    codegenReal2Mission_DW.paddedWaypts[waypoints] =
                        virtualWaypoint[c];
                    codegenReal2Mission_DW.paddedWaypts[static_cast<int32_T>(1 +
                        waypoints)] = waypointsIn_data[static_cast<int32_T>(
                        static_cast<int32_T>(waypointsIn[0]) * c)];
                }

                guard1 = true;
            }
        } else {
            waypoints_size[0] = waypointsIn_size[0];
            waypoints_size[1] = waypointsIn_size[1];
            loop_ub = static_cast<int32_T>(waypointsIn_size[0] *
                waypointsIn_size[1]);
            for (c = 0; c <= static_cast<int32_T>(loop_ub - 1); c++) {
                codegenReal2Mission_DW.paddedWaypts[c] = waypointsIn_data[c];
            }

            guard1 = true;
        }

        if (guard1) {
            if (obj->SearchFlag) {
                codegenReal2Mission_WaypointFollowerBase_searchClosestPath(obj,
                    codegenReal2Mission_DW.paddedWaypts, waypoints_size,
                    currentPose);
            }

            codegenReal2Mission_WaypointFollowerBase_getWaypoints(obj,
                codegenReal2Mission_DW.paddedWaypts, waypoints_size,
                virtualWaypoint, b_endWaypoint);
            codegenReal2Mission_WaypointFollowerBase_endWaypointReached_b(obj,
                codegenReal2Mission_DW.paddedWaypts, waypoints_size,
                virtualWaypoint, b_endWaypoint, currentPose);
            *crossTrackError =
                codegenReal2Mission_WaypointFollowerBase_pointToLine
                (virtualWaypoint, b_endWaypoint, &currentPose[0]);
            if (obj->LastWaypointFlag) {
                *crossTrackError =
                    codegenReal2Mission_WaypointFollowerBase_projectToLine
                    (virtualWaypoint, b_endWaypoint, &currentPose[0]);
            }

            absx_tmp = std::abs(*crossTrackError);
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (static_cast<int32_T>(std::isinf(absx_tmp)) ^ 1))) &
                    static_cast<int32_T>(static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(std::isnan
                      (absx_tmp)) ^ 1)))))) {
                if (absx_tmp <= 2.2250738585072014E-308) {
                    r = 4.94065645841247E-324;
                    absx_tmp = 4.94065645841247E-324;
                } else {
                    frexp(absx_tmp, &b_exponent);
                    r = std::ldexp(1.0, static_cast<int32_T>(b_exponent - 53));
                    frexp(absx_tmp, &b_exponent_0);
                    absx_tmp = std::ldexp(1.0, static_cast<int32_T>(b_exponent_0
                                           - 53));
                }
            } else {
                r = (rtNaN);
                absx_tmp = (rtNaN);
            }

            if (obj->LookaheadDistance <= std::fmax(std::sqrt(r), 5.0 * absx_tmp)
                + *crossTrackError) {
                obj->LookaheadDistance = obj->LookaheadFactor * *crossTrackError;
            }

            codegenReal2Mission_WaypointFollowerBase_getLookahead(obj,
                virtualWaypoint, b_endWaypoint, &currentPose[0], lookaheadPoint);
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
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_ReceiveThisMission_RecvData(missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    if (codegenReal2Mission_pop
            (&codegenReal2Mission_DW.Queue_InsertedFor_FeedbackCurrentMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
        *data = *msg.fData;
        codegenReal2Mission_destroyMsg(&msg);
    }

    return status;
}

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

void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec_i(real_T dd,
    real_T *y, real_T *mo, real_T *d, real_T *h, real_T *m, real_T *s)
{
    creal_T c;
    creal_T c_c;
    creal_T c_s;
    creal_T r;
    creal_T t;
    real_T a;
    real_T b;
    real_T b_thi;
    real_T b_tmp;
    real_T c_ahi;
    real_T c_tmp;
    int32_T b_r_tmp;
    int32_T c_r_tmp;
    int32_T ia_quot;
    int32_T ic_quot;
    int32_T ic_rem;
    int32_T idn;
    c_c.re = dd / 8.64E+7;
    t = codegenReal2Mission_two_prod(c_c.re);
    c_s.re = 0.0;
    c_s.im = 0.0;
    if (dd != t.re) {
        c_s = codegenReal2Mission_two_diff(dd, t.re);
    }

    c_s.re -= 0.0 * t.im;
    c_s.im -= t.im;
    b_tmp = (c_s.re + c_s.im) / 8.64E+7;
    b_thi = 0.0;
    c_ahi = c_c.re;
    if (b_tmp != 0.0) {
        c_ahi = c_c.re + b_tmp;
        b_thi = b_tmp - (c_ahi - c_c.re);
    }

    if (std::isnan(b_thi)) {
        b_thi = 0.0;
    }

    r.re = c_ahi;
    r.im = b_thi;
    r = floor_jeUa7tf2(r);
    b_thi = r.re + r.im;
    c_tmp = r.im * 8.64E+7;
    c_c = codegenReal2Mission_two_prod(r.re);
    c_ahi = c_c.im;
    b_tmp = c_c.re;
    if (c_tmp != 0.0) {
        c_ahi = c_c.im + c_tmp;
        b_tmp = c_c.re + c_ahi;
        c_ahi -= b_tmp - c_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    t = codegenReal2Mission_two_diff(0.0, c_ahi);
    c_c = codegenReal2Mission_two_diff(dd, b_tmp);
    c_ahi = c_c.im;
    b_tmp = c_c.re;
    if (t.re != 0.0) {
        c_ahi = c_c.im + t.re;
        b_tmp = c_c.re + c_ahi;
        c_ahi -= b_tmp - c_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    c_c.re = b_tmp;
    if (t.im != 0.0) {
        c_ahi += t.im;
        b_tmp += c_ahi;
        c_ahi -= b_tmp - c_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    c_c.re = b_tmp;
    c.re = b_tmp / 1000.0;
    c_s = split_MzIWb6Db(c.re);
    b_tmp = c.re * 1000.0;
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
    if (c_c.re != b_tmp) {
        c_s = codegenReal2Mission_two_diff(c_c.re, b_tmp);
    }

    c_s.re = (0.0 * c_ahi + c_s.re) - 0.0 * c_tmp;
    c_s.im = (c_s.im + c_ahi) - c_tmp;
    c_tmp = (c_s.re + c_s.im) / 1000.0;
    c_ahi = 0.0;
    b_tmp = c.re;
    if (c_tmp != 0.0) {
        b_tmp = c.re + c_tmp;
        c_ahi = c_tmp - (b_tmp - c.re);
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    c.re = b_tmp;
    c.im = c_ahi;
    c_s = floor_jeUa7tf2(c);
    t = codegenReal2Mission_two_diff(c_ahi, c_s.im);
    c_c = codegenReal2Mission_two_diff(b_tmp, c_s.re);
    c_ahi = c_c.im;
    b_tmp = c_c.re;
    if (t.re != 0.0) {
        c_ahi = c_c.im + t.re;
        b_tmp = c_c.re + c_ahi;
        c_ahi -= b_tmp - c_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    c_c.re = b_tmp;
    if (t.im != 0.0) {
        c_ahi += t.im;
        b_tmp += c_ahi;
        c_ahi -= b_tmp - c_c.re;
    }

    if (std::isnan(c_ahi)) {
        c_ahi = 0.0;
    }

    c_c.re = b_tmp;
    c_c.im = c_ahi;
    c_ahi = c_s.re + c_s.im;
    if (static_cast<boolean_T>(static_cast<int32_T>(((b_thi + 719529.0) - 61.0 >=
           0.0) & ((b_thi + 719529.0) - 61.0 <= 2.147483647E+9)))) {
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

        b_r_tmp = static_cast<int32_T>(idn - static_cast<int32_T>(146097 *
            div_s32(idn, 146097)));
        b_thi = std::trunc(static_cast<real_T>(b_r_tmp) / 36524.0);
        ic_quot = static_cast<int32_T>(b_thi);
        ic_rem = static_cast<int32_T>(b_r_tmp - static_cast<int32_T>(36524 *
            div_s32(b_r_tmp, 36524)));
        if (b_thi > 3.0) {
            ic_quot = 3;
            ic_rem = static_cast<int32_T>(b_r_tmp - 109572);
        }

        c_r_tmp = static_cast<int32_T>(ic_rem - static_cast<int32_T>(1461 *
            div_s32(ic_rem, 1461)));
        b_thi = std::trunc(static_cast<real_T>(c_r_tmp) / 365.0);
        ia_quot = static_cast<int32_T>(b_thi);
        b_r_tmp = static_cast<int32_T>(c_r_tmp - static_cast<int32_T>(365 *
            div_s32(c_r_tmp, 365)));
        if (b_thi > 3.0) {
            ia_quot = 3;
            b_r_tmp = static_cast<int32_T>(c_r_tmp - 1095);
        }

        *y = ((std::trunc(static_cast<real_T>(idn) / 146097.0) * 400.0 +
               static_cast<real_T>(ic_quot) * 100.0) + std::trunc
              (static_cast<real_T>(ic_rem) / 1461.0) * 4.0) + static_cast<real_T>
            (ia_quot);
        idn = static_cast<int32_T>(static_cast<int32_T>(std::trunc((static_cast<
            real_T>(b_r_tmp) * 5.0 + 308.0) / 153.0)) - 2);
        b_thi = static_cast<real_T>(idn);
        *d = ((static_cast<real_T>(b_r_tmp) - std::trunc((static_cast<real_T>
                 (idn) + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    } else {
        b_tmp = std::floor((((r.re + r.im) + 719529.0) - 61.0) / 146097.0);
        c_tmp = ((b_thi + 719529.0) - 61.0) - b_tmp * 146097.0;
        b_thi = std::floor(c_tmp / 36524.0);
        if (b_thi > 3.0) {
            b_thi = 3.0;
        }

        c_tmp -= b_thi * 36524.0;
        b = std::floor(c_tmp / 1461.0);
        c_tmp -= b * 1461.0;
        a = std::floor(c_tmp / 365.0);
        if (a > 3.0) {
            a = 3.0;
        }

        c_tmp -= a * 365.0;
        *y = ((b_tmp * 400.0 + b_thi * 100.0) + b * 4.0) + a;
        b_thi = std::floor((c_tmp * 5.0 + 308.0) / 153.0) - 2.0;
        *d = ((c_tmp - std::floor((b_thi + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
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

    *s = (c_c.re + c_c.im) + b_thi;
    if (*s == 60.0) {
        *s = 59.999999999999993;
    }

    if (dd == (rtInf)) {
        *y = (rtInf);
    } else if (dd == (rtMinusInf)) {
        *y = (rtMinusInf);
    }
}

int8_T codegenReal2MissionModelClass::codegenReal2Mission_filedata(void)
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

int8_T codegenReal2MissionModelClass::codegenReal2Mission_cfopen(const char_T
    *cfilename, const char_T *cpermission)
{
    FILE * filestar;
    int32_T tmp;
    int8_T fileid;
    int8_T j;
    fileid = -1;
    j = codegenReal2Mission_filedata();
    if (static_cast<int32_T>(j) >= 1) {
        filestar = fopen(cfilename, cpermission);
        if (filestar != NULL) {
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

void codegenReal2MissionModelClass::codegenReal2Mission_fileManager(real_T
    varargin_1, FILE * *f, boolean_T *a)
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

void codegenReal2MissionModelClass::codegenReal2Mission_string_string
    (MissionModes val, char_T obj_Value_data[], int32_T obj_Value_size[2])
{
    static const char_T v[15]{ 'F', 'l', 'i', 'g', 'h', 't', 'M', 'i', 's', 's',
        'i', 'o', 'n', 'R', 'H' };

    static const char_T q[13]{ 'C', 'u', 's', 't', 'o', 'm', 'F', 'r', 'm', 'n',
        'N', 'a', 'v' };

    static const char_T u[13]{ 'C', 'o', 'l', 'l', 'A', 'v', 'o', 'i', 'd', 'a',
        'n', 'c', 'e' };

    static const char_T t[12]{ 'D', 'e', 't', 'a', 'i', 'l', 'e', 'd', 'I', 'n',
        's', 'p' };

    static const char_T o[11]{ 'C', 'i', 'r', 'c', 'D', 'i', 's', 'p', 'N', 'a',
        'v' };

    static const char_T p[11]{ 'H', 'o', 'r', 'z', 'F', 'r', 'm', 'n', 'N', 'a',
        'v' };

    static const char_T w[11]{ 'W', 'a', 'i', 't', 'T', 'o', 'S', 't', 'a', 'r',
        't' };

    static const char_T r[9]{ 'R', 'u', 'n', 'W', 'a', 'y', 'N', 'a', 'v' };

    static const char_T s[8]{ 'P', 'r', 'o', 't', 'L', 'i', 'n', 'e' };

    static const char_T n[7]{ 'C', 'i', 'r', 'c', 'N', 'a', 'v' };

    static const MissionModes enumVals[11]{ CircNav, CircDispNav, HorzFrmnNav,
        CustomFrmnNav, RunWayNav, ProtLine, DetailedInsp, CollAvoidance,
        FlightMissionRH, WaitToStart, None };

    cell_wrap_1_codegenReal2Mission_T b_0[11];
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
    int32_T enumIdx;
    int32_T k;
    int32_T loop_ub;
    boolean_T exitg1;
    b.f1.size[0] = 1;
    b.f1.size[1] = 7;
    for (k = 0; k < 7; k++) {
        b.f1.data[k] = n[k];
    }

    c.f1.size[0] = 1;
    c.f1.size[1] = 11;
    d.f1.size[0] = 1;
    d.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        c.f1.data[k] = o[k];
        d.f1.data[k] = p[k];
    }

    e.f1.size[0] = 1;
    e.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        e.f1.data[k] = q[k];
    }

    f.f1.size[0] = 1;
    f.f1.size[1] = 9;
    for (k = 0; k < 9; k++) {
        f.f1.data[k] = r[k];
    }

    g.f1.size[0] = 1;
    g.f1.size[1] = 8;
    for (k = 0; k < 8; k++) {
        g.f1.data[k] = s[k];
    }

    h.f1.size[0] = 1;
    h.f1.size[1] = 12;
    for (k = 0; k < 12; k++) {
        h.f1.data[k] = t[k];
    }

    i.f1.size[0] = 1;
    i.f1.size[1] = 13;
    for (k = 0; k < 13; k++) {
        i.f1.data[k] = u[k];
    }

    j.f1.size[0] = 1;
    j.f1.size[1] = 15;
    for (k = 0; k < 15; k++) {
        j.f1.data[k] = v[k];
    }

    l.f1.size[0] = 1;
    l.f1.size[1] = 11;
    for (k = 0; k < 11; k++) {
        l.f1.data[k] = w[k];
    }

    m.f1.size[0] = 1;
    m.f1.size[1] = 4;
    m.f1.data[0] = 'N';
    m.f1.data[1] = 'o';
    m.f1.data[2] = 'n';
    m.f1.data[3] = 'e';
    enumIdx = -1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
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
    loop_ub = b_0[enumIdx].f1.size[1];
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
    for (k = 0; k <= static_cast<int32_T>(loop_ub - 1); k++) {
        obj_Value_data[k] = b_0[enumIdx].f1.data[k];
    }
}

creal_T codegenReal2MissionModelClass::codegenReal2Mission_times(const creal_T a)
{
    creal_T c;
    real_T ahi;
    real_T alo;
    real_T tmp;
    tmp = a.im * 8.64E+7;
    c = codegenReal2Mission_two_prod(a.re);
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
    real_T fracSecs;
    real_T inData_idx_3;
    real_T inData_idx_4;
    real_T inData_idx_5;
    real_T inData_idx_6;
    real_T second;
    boolean_T expl_temp;
    codegenReal2Mission_getLocalTime(&second, &fracSecs, &check, &c_tm_hour,
        &c_tm_mday, &c_tm_mon, &c_tm_year, &expl_temp);
    inData_idx_3 = c_tm_hour;
    inData_idx_4 = check;
    inData_idx_5 = fracSecs;
    inData_idx_6 = second / 1.0E+6;
    second = fracSecs;
    fracSecs = inData_idx_6;
    check = (((((c_tm_year + c_tm_mon) + c_tm_mday) + c_tm_hour) + check) +
             inData_idx_5) + inData_idx_6;
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

        if ((inData_idx_6 < 0.0) || (1000.0 <= inData_idx_6)) {
            fracSecs = std::floor(inData_idx_6 / 1000.0);
            second = inData_idx_5 + fracSecs;
            fracSecs = inData_idx_6 - fracSecs * 1000.0;
        }

        tmp.re = ((((((365.0 * check + std::floor(check / 4.0)) - std::floor
                      (check / 100.0)) + std::floor(check / 400.0)) + std::floor
                    ((153.0 * c_tm_hour + 2.0) / 5.0)) + c_tm_mday) + 60.0) -
            719529.0;
        tmp.im = 0.0;
        b_this_data = codegenReal2Mission_plus(codegenReal2Mission_plus
            (codegenReal2Mission_plus(codegenReal2Mission_times(tmp), (60.0 *
            inData_idx_3 + inData_idx_4) * 60000.0), second * 1000.0), fracSecs);
    } else {
        b_this_data.re = check;
        b_this_data.im = 0.0;
    }

    return b_this_data;
}

creal_T codegenReal2MissionModelClass::codegenReal2Mission_minus(const creal_T a,
    const creal_T b)
{
    creal_T c;
    creal_T cout;
    creal_T t;
    real_T ahi;
    real_T alo;
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

void codegenReal2MissionModelClass::codegenReal2Mission_getDateVec(const creal_T
    dd, real_T *y, real_T *mo, real_T *d, real_T *h, real_T *m, real_T *s)
{
    creal_T b_c;
    creal_T c_s;
    creal_T msOfDay;
    creal_T r;
    creal_T t;
    real_T a;
    real_T b;
    real_T b_ahi;
    real_T b_thi;
    real_T b_tmp;
    real_T slo;
    int32_T b_r_tmp;
    int32_T c_r_tmp;
    int32_T ia_quot;
    int32_T ic_quot;
    int32_T ic_rem;
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

    r.re = b_thi;
    r.im = b_ahi;
    r = floor_jeUa7tf2(r);
    b_thi = r.re + r.im;
    msOfDay = codegenReal2Mission_minus(dd, codegenReal2Mission_times(r));
    b_c.re = msOfDay.re / 1000.0;
    t = split_MzIWb6Db(b_c.re);
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
    if (msOfDay.re != b_tmp) {
        c_s = codegenReal2Mission_two_diff(msOfDay.re, b_tmp);
    }

    c_s.re = (0.0 * msOfDay.im + c_s.re) - 0.0 * slo;
    c_s.im = (c_s.im + msOfDay.im) - slo;
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

    b_c.re = b_tmp;
    b_c.im = b_ahi;
    t = floor_jeUa7tf2(b_c);
    b_c = codegenReal2Mission_minus(b_c, t);
    b_ahi = t.re + t.im;
    if (static_cast<boolean_T>(static_cast<int32_T>(((b_thi + 719529.0) - 61.0 >=
           0.0) & ((b_thi + 719529.0) - 61.0 <= 2.147483647E+9)))) {
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

        b_r_tmp = static_cast<int32_T>(idn - static_cast<int32_T>(146097 *
            div_s32(idn, 146097)));
        b_thi = std::trunc(static_cast<real_T>(b_r_tmp) / 36524.0);
        ic_quot = static_cast<int32_T>(b_thi);
        ic_rem = static_cast<int32_T>(b_r_tmp - static_cast<int32_T>(36524 *
            div_s32(b_r_tmp, 36524)));
        if (b_thi > 3.0) {
            ic_quot = 3;
            ic_rem = static_cast<int32_T>(b_r_tmp - 109572);
        }

        c_r_tmp = static_cast<int32_T>(ic_rem - static_cast<int32_T>(1461 *
            div_s32(ic_rem, 1461)));
        b_thi = std::trunc(static_cast<real_T>(c_r_tmp) / 365.0);
        ia_quot = static_cast<int32_T>(b_thi);
        b_r_tmp = static_cast<int32_T>(c_r_tmp - static_cast<int32_T>(365 *
            div_s32(c_r_tmp, 365)));
        if (b_thi > 3.0) {
            ia_quot = 3;
            b_r_tmp = static_cast<int32_T>(c_r_tmp - 1095);
        }

        *y = ((std::trunc(static_cast<real_T>(idn) / 146097.0) * 400.0 +
               static_cast<real_T>(ic_quot) * 100.0) + std::trunc
              (static_cast<real_T>(ic_rem) / 1461.0) * 4.0) + static_cast<real_T>
            (ia_quot);
        idn = static_cast<int32_T>(static_cast<int32_T>(std::trunc((static_cast<
            real_T>(b_r_tmp) * 5.0 + 308.0) / 153.0)) - 2);
        b_thi = static_cast<real_T>(idn);
        *d = ((static_cast<real_T>(b_r_tmp) - std::trunc((static_cast<real_T>
                 (idn) + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
    } else {
        b_tmp = std::floor((((r.re + r.im) + 719529.0) - 61.0) / 146097.0);
        slo = ((b_thi + 719529.0) - 61.0) - b_tmp * 146097.0;
        b_thi = std::floor(slo / 36524.0);
        if (b_thi > 3.0) {
            b_thi = 3.0;
        }

        slo -= b_thi * 36524.0;
        b = std::floor(slo / 1461.0);
        slo -= b * 1461.0;
        a = std::floor(slo / 365.0);
        if (a > 3.0) {
            a = 3.0;
        }

        slo -= a * 365.0;
        *y = ((b_tmp * 400.0 + b_thi * 100.0) + b * 4.0) + a;
        b_thi = std::floor((slo * 5.0 + 308.0) / 153.0) - 2.0;
        *d = ((slo - std::floor((b_thi + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
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
    FILE * b_NULL;
    FILE * filestar;
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
    real_T c_s;
    real_T y;
    int32_T validatedHoleFilling[7];
    int32_T varargin_1_Value_size[2];
    int32_T b_varargin_1_data_tmp;
    int32_T loop_ub;
    char_T b_varargin_1_data[16];
    char_T varargin_1_Value_data[15];
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

    codegenReal2Mission_string_string(IndivMissionCMD_MissionMode,
        varargin_1_Value_data, varargin_1_Value_size);
    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        loop_ub = varargin_1_Value_size[1];
        for (b_varargin_1_data_tmp = 0; b_varargin_1_data_tmp <=
                static_cast<int32_T>(loop_ub - 1); b_varargin_1_data_tmp++) {
            b_varargin_1_data[b_varargin_1_data_tmp] =
                varargin_1_Value_data[b_varargin_1_data_tmp];
        }

        b_varargin_1_data[varargin_1_Value_size[1]] = '\x00';
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
        fprintf(filestar, "\tparam1:\t\t\t%f\n", IndivMissionCMD_params_Param1);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam2:\t\t\t%f\n", IndivMissionCMD_params_Param2);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam3:\t\t\t%f\n", IndivMissionCMD_params_Param3);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam4:\t\t\t%f\n", IndivMissionCMD_params_Param4);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam5:\t\t\t%f\n", IndivMissionCMD_params_Param5);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam6:\t\t\t%f\n", IndivMissionCMD_params_Param6);
        if (autoflush) {
            fflush(filestar);
        }
    }

    b_NULL = NULL;
    codegenReal2Mission_fileManager(fileID, &filestar, &autoflush);
    if (static_cast<boolean_T>(static_cast<int32_T>((filestar == b_NULL) ^ 1)))
    {
        fprintf(filestar, "\tparam7:\t\t\t%f\n", IndivMissionCMD_params_Param7);
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

    print_processing_J3zqIUjT(IndivMissionCMD_StartTime.year,
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
    codegenReal2Mission_getDateVec(TimeNow_data, &y, &a__1, &a__2, &a__3, &a__4,
        &a__5);
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
        &b_a__35, &c_s);
    print_processing_4NEcbkvn(y, a__1, a__2, a__3, a__4, std::floor(a__5), std::
        round((a__11 - std::floor(c_s)) * 1000.0), b_validatedHoleFilling);
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

int32_T codegenReal2MissionModelClass::codegenReal2Mission_cfclose(real_T fid)
{
    FILE * f;
    int32_T cst;
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
        f = codegenReal2Mission_DW.eml_openfiles[static_cast<int32_T>(
            static_cast<int32_T>(b_fileid) - 3)];
    } else {
        switch (static_cast<int32_T>(b_fileid)) {
          case 0:
            f = stdin;
            break;

          case 1:
            f = stdout;
            break;

          case 2:
            f = stderr;
            break;

          default:
            f = NULL;
            break;
        }
    }

    if (static_cast<boolean_T>(static_cast<int32_T>((f != NULL) &
            (static_cast<int32_T>(fileid) >= 3)))) {
        cst = fclose(f);
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
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
              isinf(check)) ^ 1))) & static_cast<int32_T>(static_cast<boolean_T>
            (static_cast<int32_T>(static_cast<int32_T>(std::isnan(check)) ^ 1))))))
    {
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

boolean_T codegenReal2MissionModelClass::codegenReal2Mission_isequaln_f
    (MissionModes varargin_1, MissionModes varargin_2)
{
    boolean_T p;
    p = false;
    if (static_cast<int32_T>(varargin_1) == static_cast<int32_T>(varargin_2)) {
        p = true;
    }

    return p;
}

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
                            e_p = static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>
                                (codegenReal2Mission_isequaln_f
                                 (varargin_1_MissionMode, varargin_2_MissionMode))
                                & (varargin_1_SequenceID ==
                                   varargin_2_SequenceID)));
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

int32_T codegenReal2MissionModelClass::codegenReal2Mission_RcvImmedCMD_SendData(
    const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    msg = codegenReal2Mission_createMsg(data);
    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvImmedCMD_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    return status;
}

int32_T codegenReal2MissionModelClass::
    codegenReal2Mission_RcvNextMission_SendData(const missionCmd *data)
{
    Msg_missionCmd msg;
    int32_T status{ 1 };

    msg = codegenReal2Mission_createMsg(data);
    if (codegenReal2Mission_push
            (&codegenReal2Mission_DW.Queue_InsertedFor_RcvNextMission_at_inport_0_Queue,
             &msg)) {
        status = 0;
    } else {
        codegenReal2Mission_destroyMsg(&msg);
    }

    return status;
}

void codegenReal2MissionModelClass::codegenReal2Mission_initMemPool
    (MemPool_missionCmd *memPool, missionCmd *memArray, missionCmd **freeList,
     int32_T size)
{
    memPool->fMemArray = memArray;
    memPool->fNumUsed = 0;
    memPool->fFreeList = freeList;
    memPool->fNumFree = 0;
    memPool->fSize = size;
}

void codegenReal2MissionModelClass::step()
{
    missionCmd rtb_DataStoreRead_pq;
    real_T rtb_MemoryPose_m[4];
    real_T rtb_Down_c;
    boolean_T rtb_Reset;
    creal_T thisData;
    real_T out[9];
    real_T rtb_Asin[6];
    real_T absx_0[4];
    real_T rtb_MathFunction_jp[3];
    real_T rtb_Sum_h[3];
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport2[3];
    real_T u[3];
    real_T v[3];
    real_T distToCenter_tmp[2];
    real_T rtb_Switch_a[2];
    real_T rtb_TmpSignalConversionAtOrbitF[2];
    real_T xyCenter[2];
    real_T absx;
    real_T ahi;
    real_T check;
    real_T distToCenter;
    real_T fracSecs;
    real_T normp;
    real_T normq;
    real_T qmult;
    real_T qmult_idx_0;
    real_T rtb_AltitudeGCS_d;
    real_T rtb_CoordinateTransformationConversion_f_idx_0;
    real_T rtb_CoordinateTransformationConversion_f_idx_1;
    real_T rtb_CoordinateTransformationConversion_f_idx_2;
    real_T rtb_CoordinateTransformationConversion_f_idx_3;
    real_T rtb_Down;
    real_T rtb_LatitudeGCS_i;
    real_T rtb_ProductN;
    real_T rtb_Sign_c;
    real_T rtb_Sum_i;
    real_T rtb_Switch_b;
    real_T rtb_Switch_hk;
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0;
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1;
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
    real_T rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
    real_T rtb_U;
    real_T rtb_U_tmp;
    real_T second;
    real_T t;
    real_T tmp;
    int32_T tmp_0[2];
    int32_T b_size_idx_0;
    int32_T fileID;
    int32_T i;
    int32_T rtb_RcvNextMission_o1_0;
    int32_T status;
    uint32_T inSize[8];
    int16_T b_data[361];
    int8_T rtAction;
    int8_T rtPrevAction;
    uint8_T rtb_MemoryStatus;
    boolean_T rtb_InDangerSequence[361];
    boolean_T exitg1;
    boolean_T guard1{ false };

    boolean_T guard2{ false };

    boolean_T rtb_Compare_gf;
    boolean_T rtb_RcvNextMission_o1;
    boolean_T rtb_ReceiveCurrentMission_o1;
    ZCEventType zcEvent;
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
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
    }

    if (rtmIsMinorTimeStep((&codegenReal2Mission_M))) {
        (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetT
            (&(&codegenReal2Mission_M)->solverInfo);
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        codegenReal2Mission_getLocalTime(&second, &fracSecs, &check, &ahi, &tmp,
            &absx, &rtb_Sign_c, &rtb_RcvNextMission_o1);
        distToCenter = tmp;
        rtb_AltitudeGCS_d = check;
        rtb_Switch_b = fracSecs;
        rtb_LatitudeGCS_i = second / 1.0E+6;
        second = fracSecs;
        fracSecs = rtb_LatitudeGCS_i;
        check = (((((rtb_Sign_c + absx) + tmp) + ahi) + check) + rtb_Switch_b) +
            rtb_LatitudeGCS_i;
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isinf(check)) ^ 1))) & static_cast<int32_T>
                (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                 (std::isnan(check)) ^ 1)))))) {
            tmp = rtb_Sign_c;
            check = absx;
            if ((absx < 1.0) || (absx > 12.0)) {
                check = std::floor((absx - 1.0) / 12.0);
                tmp = rtb_Sign_c + check;
                check = ((absx - 1.0) - check * 12.0) + 1.0;
            }

            if (check < 3.0) {
                tmp--;
                check += 9.0;
            } else {
                check -= 3.0;
            }

            tmp = ((((((365.0 * tmp + std::floor(tmp / 4.0)) - std::floor(tmp /
                        100.0)) + std::floor(tmp / 400.0)) + std::floor((153.0 *
                       check + 2.0) / 5.0)) + distToCenter) + 60.0) - 719529.0;
            check = 1.34217729E+8 * tmp;
            check -= check - tmp;
            rtb_Sign_c = check;
            absx = tmp - check;
            check = tmp * 8.64E+7;
            rtb_Sign_c = (rtb_Sign_c * 8.64E+7 - check) + absx * 8.64E+7;
            thisData.im = rtb_Sign_c;
            if (std::isnan(rtb_Sign_c)) {
                thisData.im = 0.0;
            }

            if ((rtb_LatitudeGCS_i < 0.0) || (1000.0 <= rtb_LatitudeGCS_i)) {
                fracSecs = std::floor(rtb_LatitudeGCS_i / 1000.0);
                second = rtb_Switch_b + fracSecs;
                fracSecs = rtb_LatitudeGCS_i - fracSecs * 1000.0;
            }

            thisData.re = check;
            thisData = codegenReal2Mission_plus(codegenReal2Mission_plus
                (codegenReal2Mission_plus(thisData, (60.0 * ahi +
                rtb_AltitudeGCS_d) * 60000.0), second * 1000.0), fracSecs);
        } else {
            thisData.re = check;
        }

        second = thisData.re / 1000.0;
        rtb_RcvNextMission_o1_0 = codegenReal2Mission_RcvNextMission_RecvData
            (&codegenReal2Mission_DW.RcvNextMission_o2);
        rtb_RcvNextMission_o1 = (rtb_RcvNextMission_o1_0 != 1);
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c20_codegenReal2Mission) == 0U)
        {
            codegenReal2Mission_DW.is_active_c20_codegenReal2Mission = 1U;
            codegenReal2Mission_DW.is_c20_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;
            codegenReal2Mission_DW.TriggerSend = 0.0;
        } else if (static_cast<int32_T>
                   (codegenReal2Mission_DW.is_c20_codegenReal2Mission) == 1) {
            if (second >= codegenReal2Mission_DW.RcvNextMission_o2.StartTime) {
                codegenReal2Mission_DW.is_c20_codegenReal2Mission =
                    codegenReal2Mission_IN_Sending;
                codegenReal2Mission_DW.TriggerSend = 1.0;
            } else {
                codegenReal2Mission_DW.TriggerSend = 0.0;
            }
        } else if (second <= codegenReal2Mission_DW.RcvNextMission_o2.StartTime)
        {
            codegenReal2Mission_DW.is_c20_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;
            codegenReal2Mission_DW.TriggerSend = 0.0;
        }

        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                               &codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE,
                               (codegenReal2Mission_DW.TriggerSend));
            if (zcEvent != NO_ZCEVENT) {
                codegenReal2Mission_ReceiveCurrentMission_SendData
                    (&codegenReal2Mission_DW.RcvNextMission_o2);
            }
        }

        rtb_RcvNextMission_o1_0 =
            codegenReal2Mission_ReceiveCurrentMission_RecvData
            (&codegenReal2Mission_DW.ReceiveCurrentMission_o2);
        rtb_ReceiveCurrentMission_o1 = (rtb_RcvNextMission_o1_0 != 1);
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c24_codegenReal2Mission) == 0U)
        {
            codegenReal2Mission_DW.is_active_c24_codegenReal2Mission = 1U;
            codegenReal2Mission_DW.is_c24_codegenReal2Mission =
                codegenReal2Mission_IN_Pending;
            codegenReal2Mission_DW.StartSim = false;
        } else if (static_cast<int32_T>
                   (codegenReal2Mission_DW.is_c24_codegenReal2Mission) == 1) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode
                   != None) & (codegenReal2Mission_DW.ReceiveCurrentMission_o2.SequenceID
                               > 0)))) {
                codegenReal2Mission_DW.is_c24_codegenReal2Mission =
                    codegenReal2Mission_IN_Running;
                codegenReal2Mission_DW.StartSim = true;
            } else {
                codegenReal2Mission_DW.StartSim = false;
            }
        } else {
            codegenReal2Mission_DW.StartSim = true;
        }

        rtb_DataStoreRead_pq = codegenReal2Mission_DW.cmdFlightMission;
        rtb_Reset = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((codegenReal2Mission_DW.ReceiveCurrentMission_o2.params.Param7 !=
              0.0F) ^ 1))) & static_cast<int32_T>(rtb_ReceiveCurrentMission_o1)));
        codegenReal2Mission_DW.CastToint32 = static_cast<int32_T>(rtb_Reset);
        rtb_MemoryPose_m[0] = codegenReal2Mission_DW.MemoryPose_PreviousInput_h
            [0];
        rtb_MemoryPose_m[1] = codegenReal2Mission_DW.MemoryPose_PreviousInput_h
            [1];
        rtb_MemoryPose_m[2] = codegenReal2Mission_DW.MemoryPose_PreviousInput_h
            [2];
        rtb_MemoryPose_m[3] = codegenReal2Mission_DW.MemoryPose_PreviousInput_h
            [3];
        FlightMissionMode(&codegenReal2Mission_DW.StartSim,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode,
                          &rtb_DataStoreRead_pq.MissionLocation,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionLocation,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.params,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.StartPosition,
                          &codegenReal2Mission_DW.CastToint32,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.FormationPos,
                          &codegenReal2Mission_DW.ReceiveCurrentMission_o2.numUAV,
                          &rtb_MemoryPose_m[0],
                          &codegenReal2Mission_DW.thisTaskStatus,
                          &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2,
                          &codegenReal2Mission_DW.PreemptableMissionModeSelector_o3
                          [0],
                          &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_ReceiveCurrentMission_o1) & (static_cast<int32_T>
                    (codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE) !=
                   1)))) {
                codegenReal2Mission_DW.cmdFlightMission =
                    codegenReal2Mission_DW.ReceiveCurrentMission_o2;
                codegenReal2Mission_ReceiveThisMission_SendData
                    (&codegenReal2Mission_DW.ReceiveCurrentMission_o2);
            }

            codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE =
                static_cast<ZCSigState>(rtb_ReceiveCurrentMission_o1);
            codegenReal2Mission_DW.MissionSimUAV_MODE =
                codegenReal2Mission_DW.StartSim;
        }
    }

    if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            codegenReal2Mission_DW.CastToDouble = static_cast<real_T>(rtb_Reset);
        }

        MissionUAV(&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
                   &codegenReal2Mission_DW.CastToDouble,
                   &codegenReal2Mission_DW.PreemptableMissionModeSelector_o3[0],
                   &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2.Height,
                   &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2.AirSpeed,
                   &codegenReal2Mission_DW.PreemptableMissionModeSelector_o2.HeadingAngle,
                   &codegenReal2Mission_DW.North_o,
                   &codegenReal2Mission_DW.East_k,
                   &codegenReal2Mission_DW.Height_f,
                   &codegenReal2Mission_DW.AirSpeed_a,
                   &codegenReal2Mission_DW.HeadingAngle_g,
                   &codegenReal2Mission_DW.FlightPathAngle_h,
                   &codegenReal2Mission_DW.RollAngle_b,
                   &codegenReal2Mission_DW.RollAngleRate_a,
                   &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw),
                   &(codegenReal2Mission_X.MissionUavModel_CSTATE));
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        if (static_cast<uint32_T>(codegenReal2Mission_DW.temporalCounter_i1_n) <
            127U) {
            codegenReal2Mission_DW.temporalCounter_i1_n = static_cast<uint8_T>(
                static_cast<uint32_T>(static_cast<uint32_T>
                (codegenReal2Mission_DW.temporalCounter_i1_n) + 1U));
        }

        guard1 = false;
        guard2 = false;
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c4_codegenReal2Mission) == 0U)
        {
            codegenReal2Mission_DW.is_active_c4_codegenReal2Mission = 1U;
            codegenReal2Mission_DW.is_c4_codegenReal2Mission =
                codegenReal2Mission_IN_NotShift;
            codegenReal2Mission_DW.temporalCounter_i1_n = 0U;
            guard1 = true;
        } else if (static_cast<int32_T>
                   (codegenReal2Mission_DW.is_c4_codegenReal2Mission) == 1) {
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((static_cast<uint32_T>
                    (codegenReal2Mission_DW.temporalCounter_i1_n) >= 100U) & (
                    static_cast<int32_T>
                    (codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode)
                   == 4)))) {
                codegenReal2Mission_DW.is_c4_codegenReal2Mission =
                    codegenReal2Mission_IN_Shift;
                guard2 = true;
            } else {
                guard1 = true;
            }
        } else if (static_cast<int32_T>
                   (codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionMode)
                   != 4) {
            codegenReal2Mission_DW.is_c4_codegenReal2Mission =
                codegenReal2Mission_IN_NotShift;
            codegenReal2Mission_DW.temporalCounter_i1_n = 0U;
            guard1 = true;
        } else {
            guard2 = true;
        }

        if (guard2) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (codegenReal2Mission_DW.SailShift_MODE) ^ 1))) {
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0;
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0;
                codegenReal2Mission_DW.DiscreteTimeIntegrator_PrevResetState = 0;
                codegenReal2Mission_DW.SailShift_MODE = true;
            }

            check = 0.017453292519943295 *
                codegenReal2Mission_DW.ReceiveCurrentMission_o2.MissionLocation.degHDG;
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_Reset) | (static_cast<int32_T>
                                   (codegenReal2Mission_DW.DiscreteTimeIntegrator_PrevResetState)
                                   != 0)))) {
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0;
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0;
            }

            rtb_Switch_a[0] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceiveCurrentMission_o2.params.Param4) *
                std::cos(check) * 0.05;
            rtb_Switch_a[1] = static_cast<real_T>
                (codegenReal2Mission_DW.ReceiveCurrentMission_o2.params.Param4) *
                std::sin(check) * 0.05;
            codegenReal2Mission_DW.DiscreteTimeIntegrator[0] =
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[0] +
                rtb_Switch_a[0];
            codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[0] =
                codegenReal2Mission_DW.DiscreteTimeIntegrator[0] + rtb_Switch_a
                [0];
            codegenReal2Mission_DW.DiscreteTimeIntegrator[1] =
                codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[1] +
                rtb_Switch_a[1];
            codegenReal2Mission_DW.DiscreteTimeIntegrator_DSTATE[1] =
                codegenReal2Mission_DW.DiscreteTimeIntegrator[1] + rtb_Switch_a
                [1];
            codegenReal2Mission_DW.DiscreteTimeIntegrator_PrevResetState =
                static_cast<int8_T>(rtb_Reset);
            rtb_Switch_a[0] = codegenReal2Mission_DW.DiscreteTimeIntegrator[0];
            rtb_Switch_a[1] = codegenReal2Mission_DW.DiscreteTimeIntegrator[1];
        }

        if (guard1) {
            codegenReal2Mission_DW.SailShift_MODE = false;
            rtb_Switch_a[0] = 0.0;
            rtb_Switch_a[1] = 0.0;
        }

        rtb_Down_c = -codegenReal2Mission_DW.Height_f;
        fracSecs = codegenReal2Mission_DW.East_k + rtb_Switch_a[1];
        check = codegenReal2Mission_DW.North_o + rtb_Switch_a[0];
        rtb_RcvNextMission_o1_0 = codegenReal2Mission_RcvImmedCMD_RecvData
            (&codegenReal2Mission_DW.RcvImmedCMD_o2);
        rtb_ReceiveCurrentMission_o1 = (rtb_RcvNextMission_o1_0 != 1);
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c26_codegenReal2Mission) == 0U)
        {
            codegenReal2Mission_DW.is_active_c26_codegenReal2Mission = 1U;
            codegenReal2Mission_DW.is_c26_codegenReal2Mission =
                codegenReal2Mission_IN_FlightMission;
            ahi = 0.0;
            codegenReal2Mission_DW.endImmed = true;
        } else if (static_cast<int32_T>
                   (codegenReal2Mission_DW.is_c26_codegenReal2Mission) == 1) {
            if (rtb_ReceiveCurrentMission_o1) {
                codegenReal2Mission_DW.is_c26_codegenReal2Mission =
                    codegenReal2Mission_IN_ImmedMission_l;
                ahi = 1.0;
            } else {
                ahi = 0.0;
                codegenReal2Mission_DW.endImmed = false;
            }
        } else if (rtb_RcvNextMission_o1) {
            codegenReal2Mission_DW.is_c26_codegenReal2Mission =
                codegenReal2Mission_IN_FlightMission;
            ahi = 0.0;
            codegenReal2Mission_DW.endImmed = true;
        } else {
            ahi = 1.0;
        }

        absx = codegenReal2Mission_DW.MemoryPose_PreviousInput.North;
        rtb_Sign_c = codegenReal2Mission_DW.MemoryPose_PreviousInput.East;
        distToCenter =
            codegenReal2Mission_DW.MemoryPose_PreviousInput.HeadingAngle;
        if (static_cast<uint32_T>
                (codegenReal2Mission_DW.is_active_c25_codegenReal2Mission) == 0U)
        {
            codegenReal2Mission_DW.is_active_c25_codegenReal2Mission = 1U;
            codegenReal2Mission_DW.is_GuidanceLogic =
                codegenReal2Mission_IN_WaitToStart;
            codegenReal2Mission_DW.ImmedMissionModeSelectorMode = WaitToStart;
        } else {
            guard1 = false;
            if (rtb_ReceiveCurrentMission_o1) {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((codegenReal2Mission_DW.RcvImmedCMD_o2.MissionMode
                       == DetailedInsp) | (codegenReal2Mission_DW.RcvImmedCMD_o2.MissionMode
                       == FlightMissionRH)))) {
                    codegenReal2Mission_DW.ImmedMissionModeSelectorMode = None;
                    codegenReal2Mission_DW.is_GuidanceLogic =
                        codegenReal2Mission_IN_ImmedMission;
                    if (codegenReal2Mission_DW.RcvImmedCMD_o2.MissionMode ==
                            DetailedInsp) {
                        codegenReal2Mission_DW.ImmedMissionModeSelectorMode =
                            DetailedInsp;
                    } else {
                        codegenReal2Mission_DW.ImmedMissionModeSelectorMode =
                            FlightMissionRH;
                    }
                } else if (codegenReal2Mission_DW.RcvImmedCMD_o2.MissionMode ==
                           CollAvoidance) {
                    codegenReal2Mission_DW.is_GuidanceLogic =
                        codegenReal2Mission_IN_ImmedMission;
                    codegenReal2Mission_DW.ImmedMissionModeSelectorMode =
                        CollAvoidance;
                } else {
                    guard1 = true;
                }
            } else {
                guard1 = true;
            }

            if (guard1) {
                if (static_cast<int32_T>(codegenReal2Mission_DW.is_GuidanceLogic)
                    == 1) {
                    if (codegenReal2Mission_DW.endImmed) {
                        codegenReal2Mission_DW.is_GuidanceLogic =
                            codegenReal2Mission_IN_WaitToStart;
                        codegenReal2Mission_DW.ImmedMissionModeSelectorMode =
                            WaitToStart;
                    }
                } else if (rtb_ReceiveCurrentMission_o1) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               ((codegenReal2Mission_DW.RcvImmedCMD_o2.MissionMode
                           == DetailedInsp) | (codegenReal2Mission_DW.RcvImmedCMD_o2.MissionMode
                           == FlightMissionRH)))) {
                        codegenReal2Mission_DW.ImmedMissionModeSelectorMode =
                            None;
                        codegenReal2Mission_DW.is_GuidanceLogic =
                            codegenReal2Mission_IN_ImmedMission;
                        if (codegenReal2Mission_DW.RcvImmedCMD_o2.MissionMode ==
                            DetailedInsp) {
                            codegenReal2Mission_DW.ImmedMissionModeSelectorMode =
                                DetailedInsp;
                        } else {
                            codegenReal2Mission_DW.ImmedMissionModeSelectorMode =
                                FlightMissionRH;
                        }
                    } else if (codegenReal2Mission_DW.RcvImmedCMD_o2.MissionMode
                               == CollAvoidance) {
                        codegenReal2Mission_DW.is_GuidanceLogic =
                            codegenReal2Mission_IN_ImmedMission;
                        codegenReal2Mission_DW.ImmedMissionModeSelectorMode =
                            CollAvoidance;
                    }
                }
            }
        }

        rtb_Down = -codegenReal2Mission_DW.MemoryPose_PreviousInput.Height;
        rtPrevAction = codegenReal2Mission_DW.SwitchCase_ActiveSubsystem;
        switch (codegenReal2Mission_DW.ImmedMissionModeSelectorMode) {
          case DetailedInsp:
            rtAction = 0;
            break;

          case CollAvoidance:
            rtAction = 1;
            break;

          case FlightMissionRH:
            rtAction = 2;
            break;

          default:
            rtAction = 3;
            break;
        }

        codegenReal2Mission_DW.SwitchCase_ActiveSubsystem = rtAction;
        switch (rtAction) {
          case 0:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                codegenReal2Mission_DW.temporalCounter_i1_i = 0U;
                codegenReal2Mission_DW.is_active_c5_codegenReal2Mission = 0U;
                codegenReal2Mission_DW.is_c5_codegenReal2Mission =
                    codegenReal2Mission_IN_NO_ACTIVE_CHILD;
                codegenReal2Mission_DW.obj_j.OrbitRadiusInternal = (rtNaN);
                codegenReal2Mission_DW.obj_j.PrevResetSignal *= 0.0;
                codegenReal2Mission_DW.obj_j.NumCircles *= 0.0;
                codegenReal2Mission_DW.obj_j.OrbitCenterInternal[0] = (rtNaN);
                codegenReal2Mission_DW.obj_j.PrevPosition[0] *= 0.0;
                codegenReal2Mission_DW.obj_j.OrbitCenterInternal[1] = (rtNaN);
                codegenReal2Mission_DW.obj_j.PrevPosition[1] *= 0.0;
                codegenReal2Mission_DW.obj_j.OrbitCenterInternal[2] = (rtNaN);
                codegenReal2Mission_DW.obj_j.PrevPosition[2] *= 0.0;
                codegenReal2Mission_DW.obj_j.StartFlag = true;
                codegenReal2Mission_DW.obj_j.SelectTurnDirectionFlag = true;
                codegenReal2Mission_DW.obj_j.TurnDirectionInternal = 1.0;
                codegenReal2Mission_DW.obj_j.OrbitRadiusFlag = 0U;
                codegenReal2Mission_DW.obj_j.LookaheadDistFlag = 0U;
            }

            rtw_pthread_mutex_lock(AltitudeGCS_m0);
            rtb_AltitudeGCS_d = AltitudeGCS;
            rtw_pthread_mutex_unlock(AltitudeGCS_m0);
            rtw_pthread_mutex_lock(LatitudeGCS_m0);
            rtb_LatitudeGCS_i = LatitudeGCS;
            rtw_pthread_mutex_unlock(LatitudeGCS_m0);
            rtw_pthread_mutex_lock(LongitudeGCS_m0);
            tmp = LongitudeGCS;
            rtw_pthread_mutex_unlock(LongitudeGCS_m0);
            rtb_Switch_a[0] =
                codegenReal2Mission_DW.RcvImmedCMD_o2.MissionLocation.Lat -
                rtb_LatitudeGCS_i;
            rtb_Switch_a[1] =
                codegenReal2Mission_DW.RcvImmedCMD_o2.MissionLocation.Lon - tmp;
            if (std::abs(rtb_Switch_a[0]) > 180.0) {
                rtb_Switch_hk = rt_modd_snf(rtb_Switch_a[0] + 180.0, 360.0) +
                    -180.0;
            } else {
                rtb_Switch_hk = rtb_Switch_a[0];
            }

            tmp = std::abs(rtb_Switch_hk);
            if (tmp > 90.0) {
                if (rtb_Switch_hk < 0.0) {
                    rtb_Switch_hk = -1.0;
                } else if (rtb_Switch_hk > 0.0) {
                    rtb_Switch_hk = 1.0;
                } else if (rtb_Switch_hk == 0.0) {
                    rtb_Switch_hk = 0.0;
                } else {
                    rtb_Switch_hk = (rtNaN);
                }

                rtb_Switch_hk *= -(tmp + -90.0) + 90.0;
                rtb_RcvNextMission_o1_0 = 180;
            } else {
                rtb_RcvNextMission_o1_0 = 0;
            }

            rtb_Sum_i = static_cast<real_T>(rtb_RcvNextMission_o1_0) +
                rtb_Switch_a[1];
            if (std::abs(rtb_Sum_i) > 180.0) {
                rtb_Sum_i = rt_modd_snf(rtb_Sum_i + 180.0, 360.0) + -180.0;
            }

            rtb_Switch_a[0] = 0.017453292519943295 * rtb_Switch_hk;
            rtb_Switch_a[1] = 0.017453292519943295 * rtb_Sum_i;
            rtb_LatitudeGCS_i *= 0.017453292519943295;
            rtb_Sum_i = std::sin(rtb_LatitudeGCS_i);
            rtb_Sum_i = 1.0 - 0.0066943799901413295 * rtb_Sum_i * rtb_Sum_i;
            rtb_Switch_hk = 6.378137E+6 / std::sqrt(rtb_Sum_i);
            rtb_Sum_i = rtb_Switch_a[0] / rt_atan2d_snf(1.0, rtb_Switch_hk *
                0.99330562000985867 / rtb_Sum_i);
            rtb_Switch_b = 0.0;
            rtb_Switch_hk = 1.0 / rt_atan2d_snf(1.0, rtb_Switch_hk * std::cos
                (rtb_LatitudeGCS_i)) * rtb_Switch_a[1];
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_Switch_hk *
                0.0 + rtb_Sum_i;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Switch_hk -
                rtb_Sum_i * 0.0;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                -(codegenReal2Mission_DW.RcvImmedCMD_o2.MissionLocation.Alt +
                  -rtb_AltitudeGCS_d);
            rtb_Sum_h[0] = absx - rtb_TmpSignalConversionAtOrbitFollowerInport2
                [0];
            rtb_Sum_h[1] = rtb_Sign_c -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
            rtb_Sum_h[2] = rtb_Down -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
            tmp = std::sqrt((rtb_Sum_h[0] * rtb_Sum_h[0] + rtb_Sum_h[1] *
                             rtb_Sum_h[1]) + rtb_Sum_h[2] * rtb_Sum_h[2]);
            if (static_cast<uint32_T>
                    (codegenReal2Mission_DW.temporalCounter_i1_i) < 31U) {
                codegenReal2Mission_DW.temporalCounter_i1_i =
                    static_cast<uint8_T>(static_cast<uint32_T>(static_cast<
                    uint32_T>(codegenReal2Mission_DW.temporalCounter_i1_i) + 1U));
            }

            if (static_cast<uint32_T>
                    (codegenReal2Mission_DW.is_active_c5_codegenReal2Mission) ==
                0U) {
                codegenReal2Mission_DW.is_active_c5_codegenReal2Mission = 1U;
                if (tmp >= static_cast<real_T>
                        (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param3)) {
                    codegenReal2Mission_DW.is_c5_codegenReal2Mission =
                        codegenReal2Mission_IN_OutOfRange;
                    rtb_AltitudeGCS_d = 1.0;
                } else {
                    codegenReal2Mission_DW.is_c5_codegenReal2Mission =
                        codegenReal2Mission_IN_WithInRange;
                    rtb_AltitudeGCS_d = 0.0;
                }
            } else {
                switch (codegenReal2Mission_DW.is_c5_codegenReal2Mission) {
                  case codegenReal2Mission_IN_OutOfRange:
                    if (tmp < static_cast<real_T>
                            (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param2))
                    {
                        codegenReal2Mission_DW.is_c5_codegenReal2Mission =
                            codegenReal2Mission_IN_WithInRange;
                        rtb_AltitudeGCS_d = 0.0;
                    } else {
                        rtb_AltitudeGCS_d = 1.0;
                    }
                    break;

                  case codegenReal2Mission_IN_Turning:
                    if (static_cast<uint32_T>
                            (codegenReal2Mission_DW.temporalCounter_i1_i) >= 20U)
                    {
                        codegenReal2Mission_DW.is_c5_codegenReal2Mission =
                            codegenReal2Mission_IN_OutOfRange;
                        rtb_AltitudeGCS_d = 1.0;
                    } else {
                        rtb_AltitudeGCS_d = 2.0;
                    }
                    break;

                  default:
                    if (tmp >= static_cast<real_T>
                            (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param3))
                    {
                        codegenReal2Mission_DW.is_c5_codegenReal2Mission =
                            codegenReal2Mission_IN_Turning;
                        codegenReal2Mission_DW.temporalCounter_i1_i = 0U;
                        rtb_AltitudeGCS_d = 2.0;
                    } else {
                        rtb_AltitudeGCS_d = 0.0;
                    }
                    break;
                }
            }

            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 = absx;
            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 = rtb_Sign_c;
            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 = rtb_Down;
            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 = distToCenter;
            if (static_cast<real_T>
                    (codegenReal2Mission_DW.RcvImmedCMD_o2.FormationPos) < 0.0)
            {
                rtb_Sign_c = -1.0;
            } else if (static_cast<real_T>
                       (codegenReal2Mission_DW.RcvImmedCMD_o2.FormationPos) >
                       0.0) {
                rtb_Sign_c = 1.0;
            } else {
                rtb_Sign_c = 0.0;
            }

            codegenReal2Mission_DW.obj_j.OrbitRadiusFlag = 0U;
            codegenReal2Mission_DW.obj_j.OrbitRadiusFlag = 1U;
            distToCenter = static_cast<real_T>
                (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param4);
            codegenReal2Mission_DW.obj_j.LookaheadDistFlag = 0U;
            if (static_cast<real_T>
                    (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param4) < 0.1)
            {
                distToCenter = 0.1;
                codegenReal2Mission_DW.obj_j.LookaheadDistFlag = 1U;
            }

            rtb_TmpSignalConversionAtOrbitF[0] = absx -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
            rtb_TmpSignalConversionAtOrbitF[1] =
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 -
                rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
            if (codegenReal2Mission_norm(rtb_TmpSignalConversionAtOrbitF) <
                    2.47032822920623E-323) {
                rtb_Sum_h[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                tmp = rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
            } else {
                rtb_RcvNextMission_o1 = false;
                rtb_Compare_gf = true;
                rtb_RcvNextMission_o1_0 = 0;
                exitg1 = false;
                while ((!exitg1) && (rtb_RcvNextMission_o1_0 < 3)) {
                    if ((codegenReal2Mission_DW.obj_j.OrbitCenterInternal[rtb_RcvNextMission_o1_0]
                         == rtb_TmpSignalConversionAtOrbitFollowerInport2[rtb_RcvNextMission_o1_0])
                        || (std::isnan
                            (codegenReal2Mission_DW.obj_j.OrbitCenterInternal[rtb_RcvNextMission_o1_0])
                            && std::isnan
                            (rtb_TmpSignalConversionAtOrbitFollowerInport2[rtb_RcvNextMission_o1_0])))
                    {
                        rtb_RcvNextMission_o1_0 = static_cast<int32_T>
                            (rtb_RcvNextMission_o1_0 + 1);
                    } else {
                        rtb_Compare_gf = false;
                        exitg1 = true;
                    }
                }

                if (rtb_Compare_gf) {
                    rtb_RcvNextMission_o1 = true;
                }

                if ((static_cast<boolean_T>(static_cast<int32_T>
                                            (static_cast<int32_T>
                        (rtb_RcvNextMission_o1) ^ 1))) || (static_cast<boolean_T>
                        (static_cast<int32_T>
                         ((codegenReal2Mission_DW.obj_j.OrbitRadiusInternal ==
                           0.1) ^ 1)))) {
                    codegenReal2Mission_DW.obj_j.NumCircles = 0.0;
                    codegenReal2Mission_DW.obj_j.OrbitCenterInternal[0] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                    codegenReal2Mission_DW.obj_j.OrbitCenterInternal[1] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                    codegenReal2Mission_DW.obj_j.OrbitCenterInternal[2] =
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                    codegenReal2Mission_DW.obj_j.OrbitRadiusInternal = 0.1;
                    codegenReal2Mission_DW.obj_j.SelectTurnDirectionFlag = true;
                }

                if (distToCenter >= 0.1) {
                    codegenReal2Mission_DW.obj_j.LookaheadDistance =
                        0.090000000000000011;
                } else {
                    codegenReal2Mission_DW.obj_j.LookaheadDistance =
                        distToCenter;
                }

                rtb_Switch_a[0] = absx;
                rtb_Switch_a[1] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1;
                xyCenter[0] = rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                xyCenter[1] = rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                rtb_Sum_i = rtb_Switch_a[0] - xyCenter[0];
                distToCenter_tmp[0] = rtb_Sum_i;
                rtb_LatitudeGCS_i = rtb_Switch_a[1] - xyCenter[1];
                distToCenter_tmp[1] = rtb_LatitudeGCS_i;
                distToCenter = std::sqrt(rtb_LatitudeGCS_i * rtb_LatitudeGCS_i +
                    rtb_Sum_i * rtb_Sum_i);
                rtb_Down = std::abs
                    (codegenReal2Mission_DW.obj_j.LookaheadDistance + 0.1);
                rtb_RcvNextMission_o1 = static_cast<boolean_T>
                    (static_cast<int32_T>(static_cast<int32_T>(std::isinf
                       (rtb_Down)) ^ 1));
                rtb_ReceiveCurrentMission_o1 = static_cast<boolean_T>(
                    static_cast<int32_T>(static_cast<int32_T>(std::isnan
                    (rtb_Down)) ^ 1));
                if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                        int32_T>(rtb_RcvNextMission_o1) & static_cast<int32_T>
                        (rtb_ReceiveCurrentMission_o1)))) {
                    if (rtb_Down <= 2.2250738585072014E-308) {
                        absx = 4.94065645841247E-324;
                    } else {
                        frexp(rtb_Down, &fileID);
                        absx = std::ldexp(1.0, static_cast<int32_T>(fileID - 53));
                    }
                } else {
                    absx = (rtNaN);
                }

                guard1 = false;
                if (distToCenter >=
                        (codegenReal2Mission_DW.obj_j.LookaheadDistance + 0.1) -
                    5.0 * absx) {
                    guard1 = true;
                } else {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               (static_cast<int32_T>
                                                (rtb_RcvNextMission_o1) &
                                                static_cast<int32_T>
                                                (rtb_ReceiveCurrentMission_o1))))
                    {
                        if (rtb_Down <= 2.2250738585072014E-308) {
                            absx = 4.94065645841247E-324;
                        } else {
                            frexp(rtb_Down, &i);
                            absx = std::ldexp(1.0, static_cast<int32_T>(i - 53));
                        }
                    } else {
                        absx = (rtNaN);
                    }

                    if (distToCenter <= (0.1 -
                                         codegenReal2Mission_DW.obj_j.LookaheadDistance)
                        + 5.0 * absx) {
                        guard1 = true;
                    } else {
                        if (codegenReal2Mission_DW.obj_j.StartFlag) {
                            codegenReal2Mission_DW.obj_j.PrevPosition[0] =
                                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0;
                            codegenReal2Mission_DW.obj_j.PrevPosition[1] =
                                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1;
                            codegenReal2Mission_DW.obj_j.PrevPosition[2] =
                                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
                            codegenReal2Mission_DW.obj_j.StartFlag = false;
                        }

                        rtb_TmpSignalConversionAtOrbitF[0] = rtb_Sum_i;
                        rtb_TmpSignalConversionAtOrbitF[1] = rtb_LatitudeGCS_i;
                        distToCenter = codegenReal2Mission_norm
                            (rtb_TmpSignalConversionAtOrbitF);
                        absx = codegenReal2Mission_DW.obj_j.LookaheadDistance *
                            codegenReal2Mission_DW.obj_j.LookaheadDistance;
                        tmp = ((absx - 0.010000000000000002) + distToCenter *
                               distToCenter) / (2.0 * distToCenter);
                        rtb_Switch_hk = xyCenter[0] - rtb_Switch_a[0];
                        rtb_Down = rtb_Switch_hk * tmp / distToCenter +
                            rtb_Switch_a[0];
                        rtb_Sum_i = xyCenter[1] - rtb_Switch_a[1];
                        rtb_LatitudeGCS_i = rtb_Sum_i * tmp / distToCenter +
                            rtb_Switch_a[1];
                        absx = std::sqrt(absx - tmp * tmp);
                        rtb_Sum_i = rtb_Sum_i * absx / distToCenter;
                        distToCenter_tmp[0] = rtb_Down - rtb_Sum_i;
                        distToCenter_tmp[1] = rtb_Sum_i + rtb_Down;
                        distToCenter = rtb_Switch_hk * absx / distToCenter;
                        absx = distToCenter + rtb_LatitudeGCS_i;
                        rtb_LatitudeGCS_i -= distToCenter;
                        if ((rtb_Sign_c == 0.0) && (static_cast<boolean_T>(
                                static_cast<int32_T>(static_cast<int32_T>
                                (codegenReal2Mission_DW.obj_j.SelectTurnDirectionFlag)
                               ^ 1)))) {
                            tmp =
                                codegenReal2Mission_DW.obj_j.TurnDirectionInternal;
                        } else {
                            tmp = rtb_Sign_c;
                        }

                        rtb_Sum_h[0] =
                            codegenReal2Mission_DW.obj_j.PrevPosition[0] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                        rtb_Sum_h[1] =
                            codegenReal2Mission_DW.obj_j.PrevPosition[1] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                        u[0] = rtb_Sum_h[0];
                        u[1] = rtb_Sum_h[1];
                        u[2] = 0.0;
                        v[0] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0
                            - rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                        v[1] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1
                            - rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                        v[2] = 0.0;
                        if (tmp < 0.0) {
                            u[0] = v[0];
                            v[0] = rtb_Sum_h[0];
                            u[1] = v[1];
                            v[1] = rtb_Sum_h[1];
                            u[2] = 0.0;
                            v[2] = 0.0;
                            tmp = -1.0;
                        } else if (tmp > 0.0) {
                            tmp = 1.0;
                        } else if (tmp == 0.0) {
                            tmp = 0.0;
                        } else {
                            tmp = (rtNaN);
                        }

                        rtb_CoordinateTransformationConversion_f_idx_0 =
                            codegenReal2Mission_norm_b(u);
                        rtb_CoordinateTransformationConversion_f_idx_1 =
                            codegenReal2Mission_norm_b(v);
                        rtb_U = u[0] /
                            rtb_CoordinateTransformationConversion_f_idx_0;
                        rtb_CoordinateTransformationConversion_f_idx_2 = v[0] /
                            rtb_CoordinateTransformationConversion_f_idx_1;
                        distToCenter = u[1] /
                            rtb_CoordinateTransformationConversion_f_idx_0;
                        rtb_Down = v[1] /
                            rtb_CoordinateTransformationConversion_f_idx_1;
                        codegenReal2Mission_DW.obj_j.PrevPosition[0] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0;
                        codegenReal2Mission_DW.obj_j.PrevPosition[1] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1;
                        codegenReal2Mission_DW.obj_j.PrevPosition[2] =
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
                        codegenReal2Mission_DW.obj_j.NumCircles += rt_atan2d_snf
                            (rtb_U * rtb_Down -
                             rtb_CoordinateTransformationConversion_f_idx_2 *
                             distToCenter, (rtb_U *
                                            rtb_CoordinateTransformationConversion_f_idx_2
                                            + distToCenter * rtb_Down) + 0.0 /
                             rtb_CoordinateTransformationConversion_f_idx_0 *
                             (0.0 /
                              rtb_CoordinateTransformationConversion_f_idx_1)) /
                            2.0 / 3.1415926535897931;
                        v[0] = xyCenter[0] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0;
                        v[1] = xyCenter[1] -
                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1;
                        switch (static_cast<int32_T>(tmp)) {
                          case 1:
                            if ((distToCenter_tmp[0] -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0)
                                * v[1] - (absx -
                                          rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1)
                                * v[0] > 0.0) {
                                xyCenter[0] = distToCenter_tmp[0];
                                xyCenter[1] = absx;
                            } else {
                                xyCenter[0] = distToCenter_tmp[1];
                                xyCenter[1] = rtb_LatitudeGCS_i;
                            }
                            break;

                          case -1:
                            if ((distToCenter_tmp[0] -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0)
                                * v[1] - (absx -
                                          rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1)
                                * v[0] < 0.0) {
                                xyCenter[0] = distToCenter_tmp[0];
                                xyCenter[1] = absx;
                            } else {
                                xyCenter[0] = distToCenter_tmp[1];
                                xyCenter[1] = rtb_LatitudeGCS_i;
                            }
                            break;

                          default:
                            tmp = std::abs(codegenReal2Mission_angdiff
                                           (rt_atan2d_snf(absx -
                                             rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1,
                                             distToCenter_tmp[0] -
                                             rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0),
                                            rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3));
                            if (tmp < std::abs(codegenReal2Mission_angdiff
                                               (rt_atan2d_snf(rtb_LatitudeGCS_i
                                    - rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1,
                                   distToCenter_tmp[1] -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0),
                                                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3)))
                            {
                                xyCenter[0] = distToCenter_tmp[0];
                                xyCenter[1] = absx;
                            } else {
                                xyCenter[0] = distToCenter_tmp[1];
                                xyCenter[1] = rtb_LatitudeGCS_i;
                            }

                            if ((xyCenter[0] -
                                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0)
                                * v[1] - (xyCenter[1] -
                                          rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1)
                                * v[0] > 0.0) {
                                codegenReal2Mission_DW.obj_j.TurnDirectionInternal
                                    = 1.0;
                            } else {
                                codegenReal2Mission_DW.obj_j.TurnDirectionInternal
                                    = -1.0;
                            }

                            codegenReal2Mission_DW.obj_j.SelectTurnDirectionFlag
                                = false;
                            break;
                        }
                    }
                }

                if (guard1) {
                    rtb_CoordinateTransformationConversion_f_idx_0 =
                        codegenReal2Mission_norm(distToCenter_tmp);
                    xyCenter[0] += rtb_Sum_i /
                        rtb_CoordinateTransformationConversion_f_idx_0 * 0.1;
                    xyCenter[1] += rtb_LatitudeGCS_i /
                        rtb_CoordinateTransformationConversion_f_idx_0 * 0.1;
                }

                rtb_Sum_h[2] = rtb_TmpSignalConversionAtOrbitFollowerInport2[2];
                tmp = rt_atan2d_snf(xyCenter[1] - rtb_Switch_a[1], xyCenter[0] -
                                    rtb_Switch_a[0]);
            }

            if (rtb_AltitudeGCS_d > 0.0) {
                codegenReal2Mission_DW.OrbitNavHdg = tmp;
            }

            if (rtb_AltitudeGCS_d == 2.0) {
                rtb_Switch_b = 2.3561944901923448 * rtb_Sign_c;
            }

            codegenReal2Mission_DW.MergeGuidanceCMD.Height =
                -((static_cast<real_T>
                   (codegenReal2Mission_DW.RcvImmedCMD_o2.FormationPos) - 0.5 *
                   rtb_Sign_c) * 10.0 + rtb_Sum_h[2]);
            codegenReal2Mission_DW.MergeGuidanceCMD.AirSpeed =
                static_cast<real_T>
                (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param1);
            codegenReal2Mission_DW.MergeGuidanceCMD.HeadingAngle = rtb_Switch_b
                + codegenReal2Mission_DW.OrbitNavHdg;
            rtb_Compare_gf = false;
            codegenReal2Mission_DW.MergeControlSwitch[0] = true;
            codegenReal2Mission_DW.MergeControlSwitch[1] = true;
            break;

          case 1:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                codegenReal2Mission_DW.MemoryStatus_PreviousInput = 0U;
                codegenReal2Mission_DW.MemoryPrevRange_PreviousInput = 0.0;
                for (i = 0; i < 360; i++) {
                    codegenReal2Mission_DW.NorthSequence_X[i] = 0.0;
                    codegenReal2Mission_DW.EastSequence_X[i] = 0.0;
                    codegenReal2Mission_DW.HeightSequence_X[i] = -150.0;
                    codegenReal2Mission_DW.InDangerSequence_X[i] = false;
                }

                codegenReal2Mission_DW.temporalCounter_i1 = 0U;
                codegenReal2Mission_DW.is_active_c10_codegenReal2Mission = 0U;
                codegenReal2Mission_DW.is_c10_codegenReal2Mission =
                    codegenReal2Mission_IN_NO_ACTIVE_CHILD;
                codegenReal2Mission_DW.obj.WaypointIndex = 1.0;
                for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 2700;
                     rtb_RcvNextMission_o1_0++) {
                    codegenReal2Mission_DW.obj.WaypointsInternal[rtb_RcvNextMission_o1_0]
                        = (rtNaN);
                }
            }

            rtb_MemoryStatus = codegenReal2Mission_DW.MemoryStatus_PreviousInput;
            rtw_pthread_mutex_lock(LatitudeGCS_m0);
            rtb_AltitudeGCS_d = LatitudeGCS;
            rtw_pthread_mutex_unlock(LatitudeGCS_m0);
            rtw_pthread_mutex_lock(LongitudeGCS_m0);
            tmp = LongitudeGCS;
            rtw_pthread_mutex_unlock(LongitudeGCS_m0);
            rtb_Switch_a[0] =
                codegenReal2Mission_DW.RcvImmedCMD_o2.MissionLocation.Lat -
                rtb_AltitudeGCS_d;
            rtb_Switch_a[1] =
                codegenReal2Mission_DW.RcvImmedCMD_o2.MissionLocation.Lon - tmp;
            if (std::abs(rtb_Switch_a[0]) > 180.0) {
                rtb_LatitudeGCS_i = rt_modd_snf(rtb_Switch_a[0] + 180.0, 360.0)
                    + -180.0;
            } else {
                rtb_LatitudeGCS_i = rtb_Switch_a[0];
            }

            tmp = std::abs(rtb_LatitudeGCS_i);
            if (tmp > 90.0) {
                if (rtb_LatitudeGCS_i < 0.0) {
                    rtb_LatitudeGCS_i = -1.0;
                } else if (rtb_LatitudeGCS_i > 0.0) {
                    rtb_LatitudeGCS_i = 1.0;
                } else if (rtb_LatitudeGCS_i == 0.0) {
                    rtb_LatitudeGCS_i = 0.0;
                } else {
                    rtb_LatitudeGCS_i = (rtNaN);
                }

                rtb_LatitudeGCS_i *= -(tmp + -90.0) + 90.0;
                rtb_RcvNextMission_o1_0 = 180;
            } else {
                rtb_RcvNextMission_o1_0 = 0;
            }

            rtb_Switch_hk = static_cast<real_T>(rtb_RcvNextMission_o1_0) +
                rtb_Switch_a[1];
            if (std::abs(rtb_Switch_hk) > 180.0) {
                rtb_Switch_hk = rt_modd_snf(rtb_Switch_hk + 180.0, 360.0) +
                    -180.0;
            }

            rtb_Switch_a[0] = 0.017453292519943295 * rtb_LatitudeGCS_i;
            rtb_Switch_a[1] = 0.017453292519943295 * rtb_Switch_hk;
            rtb_AltitudeGCS_d *= 0.017453292519943295;
            rtb_Switch_hk = std::sin(rtb_AltitudeGCS_d);
            rtb_Switch_hk = 1.0 - 0.0066943799901413295 * rtb_Switch_hk *
                rtb_Switch_hk;
            rtb_LatitudeGCS_i = 6.378137E+6 / std::sqrt(rtb_Switch_hk);
            rtb_Switch_hk = rtb_Switch_a[0] / rt_atan2d_snf(1.0,
                rtb_LatitudeGCS_i * 0.99330562000985867 / rtb_Switch_hk);
            rtb_LatitudeGCS_i = 1.0 / rt_atan2d_snf(1.0, rtb_LatitudeGCS_i * std::
                cos(rtb_AltitudeGCS_d)) * rtb_Switch_a[1];
            rtb_AltitudeGCS_d = rtb_LatitudeGCS_i * 0.0 + rtb_Switch_hk;
            rtb_Switch_hk = rtb_LatitudeGCS_i - rtb_Switch_hk * 0.0;
            rtw_pthread_mutex_lock(AltitudeGCS_m0);
            tmp = AltitudeGCS;
            rtw_pthread_mutex_unlock(AltitudeGCS_m0);
            rtb_Switch_b =
                codegenReal2Mission_DW.RcvImmedCMD_o2.MissionLocation.Alt + -tmp;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = rtb_AltitudeGCS_d
                - check;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = rtb_Switch_hk -
                fracSecs;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] = rtb_Switch_b -
                codegenReal2Mission_DW.Height_f;
            rtb_LatitudeGCS_i = std::sqrt
                ((rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                  rtb_TmpSignalConversionAtOrbitFollowerInport2[0] +
                  rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                  rtb_TmpSignalConversionAtOrbitFollowerInport2[1]) +
                 rtb_TmpSignalConversionAtOrbitFollowerInport2[2] *
                 rtb_TmpSignalConversionAtOrbitFollowerInport2[2]);
            rtb_Sum_i = static_cast<real_T>
                (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param1) +
                static_cast<real_T>
                (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param2);
            rtb_TmpSignalConversionAtOrbitFollowerInport2[0] = check -
                rtb_AltitudeGCS_d;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[1] = fracSecs -
                rtb_Switch_hk;
            rtb_TmpSignalConversionAtOrbitFollowerInport2[2] =
                codegenReal2Mission_DW.Height_f - rtb_Switch_b;
            codegenReal2Mission_DW.RelationalOperator = (rtb_LatitudeGCS_i <=
                rtb_Sum_i);
            if (codegenReal2Mission_DW.RelationalOperator) {
                v[0] = std::cos(codegenReal2Mission_DW.HeadingAngle_g);
                v[1] = std::cos(codegenReal2Mission_DW.FlightPathAngle_h);
                v[2] = std::cos(codegenReal2Mission_DW.RollAngle_b);
                rtb_Sum_h[0] = std::sin(codegenReal2Mission_DW.HeadingAngle_g);
                rtb_Sum_h[1] = std::sin(codegenReal2Mission_DW.FlightPathAngle_h);
                rtb_Sum_h[2] = std::sin(codegenReal2Mission_DW.RollAngle_b);
                out[0] = v[0] * v[1];
                tmp = rtb_Sum_h[1] * rtb_Sum_h[2];
                out[3] = tmp * v[0] - rtb_Sum_h[0] * v[2];
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 = rtb_Sum_h
                    [1] * v[2];
                out[6] = rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 *
                    v[0] + rtb_Sum_h[0] * rtb_Sum_h[2];
                out[1] = rtb_Sum_h[0] * v[1];
                out[4] = tmp * rtb_Sum_h[0] + v[0] * v[2];
                out[7] = rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 *
                    rtb_Sum_h[0] - v[0] * rtb_Sum_h[2];
                out[2] = -rtb_Sum_h[1];
                out[5] = v[1] * rtb_Sum_h[2];
                out[8] = v[1] * v[2];
                rtb_CoordinateTransformationConversion_f_idx_2 = 0.0;
                for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 3;
                        rtb_RcvNextMission_o1_0++) {
                    tmp = out[static_cast<int32_T>(rtb_RcvNextMission_o1_0 + 6)]
                        * 0.0 + (out[static_cast<int32_T>
                                 (rtb_RcvNextMission_o1_0 + 3)] * 0.0 +
                                 out[rtb_RcvNextMission_o1_0]);
                    rtb_CoordinateTransformationConversion_f_idx_2 += tmp * tmp;
                    v[rtb_RcvNextMission_o1_0] = tmp;
                }

                for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 3;
                        rtb_RcvNextMission_o1_0++) {
                    tmp = v[rtb_RcvNextMission_o1_0] /
                        rtb_CoordinateTransformationConversion_f_idx_2;
                    out[static_cast<int32_T>(3 * rtb_RcvNextMission_o1_0)] = v[0]
                        * tmp;
                    out[static_cast<int32_T>(static_cast<int32_T>(3 *
                        rtb_RcvNextMission_o1_0) + 1)] = v[1] * tmp;
                    out[static_cast<int32_T>(static_cast<int32_T>(3 *
                        rtb_RcvNextMission_o1_0) + 2)] = v[2] * tmp;
                }

                for (i = 0; i < 3; i++) {
                    rtb_U = out[static_cast<int32_T>(i + 6)] *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[2] + (out[
                        static_cast<int32_T>(i + 3)] *
                        rtb_TmpSignalConversionAtOrbitFollowerInport2[1] + out[i]
                        * rtb_TmpSignalConversionAtOrbitFollowerInport2[0]);
                    tmp = rtb_TmpSignalConversionAtOrbitFollowerInport2[i] -
                        rtb_U;
                    rtb_MathFunction_jp[i] = tmp * tmp;
                    rtb_Sum_h[i] = tmp;
                    u[i] = rtb_U;
                }

                tmp = std::sqrt((rtb_MathFunction_jp[0] + rtb_MathFunction_jp[1])
                                + rtb_MathFunction_jp[2]);
                rtb_U = rtb_Sum_i * rtb_Sum_i - tmp * tmp;
                rtb_U = std::sqrt(rtb_U);
                tmp = rtb_U * v[0];
                rtb_Asin[0] = tmp + rtb_Sum_h[0];
                rtb_Asin[3] = rtb_Sum_h[0] - tmp;
                tmp = rtb_U * v[1];
                rtb_Asin[1] = tmp + rtb_Sum_h[1];
                rtb_Asin[4] = rtb_Sum_h[1] - tmp;
                tmp = rtb_U * v[2];
                rtb_Asin[2] = tmp + rtb_Sum_h[2];
                rtb_Asin[5] = rtb_Sum_h[2] - tmp;
                for (i = 0; i < 6; i++) {
                    tmp = rtb_Asin[i] / rtb_Sum_i;
                    if (tmp > 1.0) {
                        tmp = 1.0;
                    } else if (tmp < -1.0) {
                        tmp = -1.0;
                    }

                    rtb_Asin[i] = std::asin(tmp);
                }

                rtb_Switch_a[0] = rtb_Asin[3] * rtb_Asin[3];
                rtb_Switch_a[1] = rtb_Asin[4] * rtb_Asin[4];
                rtb_MathFunction_jp[0] = rt_atan2d_snf(rtb_Asin[4], rtb_Asin[3])
                    / 2.0;
                rtb_MathFunction_jp[1] = rt_atan2d_snf(rtb_Asin[5], std::sqrt
                    (rtb_Switch_a[0] + rtb_Switch_a[1])) / 2.0;
                rtb_Sum_h[0] = std::cos(rtb_MathFunction_jp[0]);
                rtb_Sum_h[1] = std::cos(rtb_MathFunction_jp[1]);
                rtb_MathFunction_jp[0] = std::sin(rtb_MathFunction_jp[0]);
                rtb_MathFunction_jp[1] = std::sin(rtb_MathFunction_jp[1]);
                tmp = rtb_Sum_h[0] * rtb_Sum_h[1];
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 =
                    rtb_MathFunction_jp[0] * rtb_MathFunction_jp[1];
                rtb_CoordinateTransformationConversion_f_idx_0 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 * 0.0 +
                    tmp;
                rtb_CoordinateTransformationConversion_f_idx_1 = tmp * 0.0 -
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
                tmp = rtb_Sum_h[0] * rtb_MathFunction_jp[1];
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 =
                    rtb_MathFunction_jp[0] * rtb_Sum_h[1];
                rtb_CoordinateTransformationConversion_f_idx_2 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 * 0.0 +
                    tmp;
                rtb_CoordinateTransformationConversion_f_idx_3 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 - tmp *
                    0.0;
                rtb_Switch_a[0] = rtb_Asin[0] * rtb_Asin[0];
                rtb_Switch_a[1] = rtb_Asin[1] * rtb_Asin[1];
                rtb_MathFunction_jp[0] = rt_atan2d_snf(rtb_Asin[1], rtb_Asin[0])
                    / 2.0;
                rtb_MathFunction_jp[1] = rt_atan2d_snf(rtb_Asin[2], std::sqrt
                    (rtb_Switch_a[0] + rtb_Switch_a[1])) / 2.0;
                rtb_Sum_h[0] = std::cos(rtb_MathFunction_jp[0]);
                rtb_Sum_h[1] = std::cos(rtb_MathFunction_jp[1]);
                rtb_MathFunction_jp[0] = std::sin(rtb_MathFunction_jp[0]);
                rtb_MathFunction_jp[1] = std::sin(rtb_MathFunction_jp[1]);
                tmp = rtb_Sum_h[0] * rtb_Sum_h[1];
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 =
                    rtb_MathFunction_jp[0] * rtb_MathFunction_jp[1];
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 * 0.0 +
                    tmp;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 = tmp * 0.0
                    - rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
                tmp = rtb_Sum_h[0] * rtb_MathFunction_jp[1];
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 =
                    rtb_MathFunction_jp[0] * rtb_Sum_h[1];
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 * 0.0 +
                    tmp;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 -= tmp * 0.0;
                tmp = (u[0] * v[0] + u[1] * v[1]) + u[2] * v[2];
                if (tmp < 0.0) {
                    tmp = -1.0;
                } else if (tmp > 0.0) {
                    tmp = 1.0;
                } else if (tmp == 0.0) {
                    tmp = 0.0;
                } else {
                    tmp = (rtNaN);
                }

                tmp = (std::sqrt((u[0] * u[0] + u[1] * u[1]) + u[2] * u[2]) *
                       tmp + rtb_U) / (2.0 * rtb_U);
                if (tmp > 1.0) {
                    tmp = 1.0;
                } else if (tmp < 0.0) {
                    tmp = 0.0;
                }

                rtb_ProductN = 3.3121686421112381E-170;
                rtb_U_tmp = std::abs
                    (rtb_CoordinateTransformationConversion_f_idx_0);
                rtb_U = rtb_U_tmp;
                if (rtb_U > 3.3121686421112381E-170) {
                    normp = 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / 3.3121686421112381E-170;
                    normp = t * t;
                }

                rtb_U = std::abs(rtb_CoordinateTransformationConversion_f_idx_1);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normp = normp * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normp += t * t;
                }

                rtb_U = std::abs(rtb_CoordinateTransformationConversion_f_idx_2);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normp = normp * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normp += t * t;
                }

                rtb_U = std::abs(rtb_CoordinateTransformationConversion_f_idx_3);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normp = normp * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normp += t * t;
                }

                normp = rtb_ProductN * std::sqrt(normp);
                rtb_ProductN = 3.3121686421112381E-170;
                rtb_U = std::abs
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0);
                if (rtb_U > 3.3121686421112381E-170) {
                    normq = 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / 3.3121686421112381E-170;
                    normq = t * t;
                }

                rtb_U = std::abs
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normq = normq * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normq += t * t;
                }

                rtb_U = std::abs
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normq = normq * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normq += t * t;
                }

                rtb_U = std::abs
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normq = normq * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normq += t * t;
                }

                normq = rtb_ProductN * std::sqrt(normq);
                if (static_cast<boolean_T>(static_cast<int32_T>((normp >
                        1.0000000149011612) | (normp < 0.99999998509883881)))) {
                    rtb_ProductN = 3.3121686421112381E-170;
                    rtb_U = rtb_U_tmp;
                    if (rtb_U > 3.3121686421112381E-170) {
                        normp = 1.0;
                        rtb_ProductN = rtb_U;
                    } else {
                        t = rtb_U / 3.3121686421112381E-170;
                        normp = t * t;
                    }

                    rtb_U = std::abs
                        (rtb_CoordinateTransformationConversion_f_idx_1);
                    if (rtb_U > rtb_ProductN) {
                        t = rtb_ProductN / rtb_U;
                        normp = normp * t * t + 1.0;
                        rtb_ProductN = rtb_U;
                    } else {
                        t = rtb_U / rtb_ProductN;
                        normp += t * t;
                    }

                    rtb_U = std::abs
                        (rtb_CoordinateTransformationConversion_f_idx_2);
                    if (rtb_U > rtb_ProductN) {
                        t = rtb_ProductN / rtb_U;
                        normp = normp * t * t + 1.0;
                        rtb_ProductN = rtb_U;
                    } else {
                        t = rtb_U / rtb_ProductN;
                        normp += t * t;
                    }

                    rtb_U = std::abs
                        (rtb_CoordinateTransformationConversion_f_idx_3);
                    if (rtb_U > rtb_ProductN) {
                        t = rtb_ProductN / rtb_U;
                        normp = normp * t * t + 1.0;
                        rtb_ProductN = rtb_U;
                    } else {
                        t = rtb_U / rtb_ProductN;
                        normp += t * t;
                    }

                    normp = rtb_ProductN * std::sqrt(normp);
                    rtb_CoordinateTransformationConversion_f_idx_0 /= normp;
                    rtb_CoordinateTransformationConversion_f_idx_1 /= normp;
                    rtb_CoordinateTransformationConversion_f_idx_2 /= normp;
                    rtb_CoordinateTransformationConversion_f_idx_3 /= normp;
                }

                if (static_cast<boolean_T>(static_cast<int32_T>((normq >
                        1.0000000149011612) | (normq < 0.99999998509883881)))) {
                    rtb_ProductN = 3.3121686421112381E-170;
                    rtb_U = std::abs
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0);
                    if (rtb_U > 3.3121686421112381E-170) {
                        normp = 1.0;
                        rtb_ProductN = rtb_U;
                    } else {
                        t = rtb_U / 3.3121686421112381E-170;
                        normp = t * t;
                    }

                    rtb_U = std::abs
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1);
                    if (rtb_U > rtb_ProductN) {
                        t = rtb_ProductN / rtb_U;
                        normp = normp * t * t + 1.0;
                        rtb_ProductN = rtb_U;
                    } else {
                        t = rtb_U / rtb_ProductN;
                        normp += t * t;
                    }

                    rtb_U = std::abs
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2);
                    if (rtb_U > rtb_ProductN) {
                        t = rtb_ProductN / rtb_U;
                        normp = normp * t * t + 1.0;
                        rtb_ProductN = rtb_U;
                    } else {
                        t = rtb_U / rtb_ProductN;
                        normp += t * t;
                    }

                    rtb_U = std::abs
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3);
                    if (rtb_U > rtb_ProductN) {
                        t = rtb_ProductN / rtb_U;
                        normp = normp * t * t + 1.0;
                        rtb_ProductN = rtb_U;
                    } else {
                        t = rtb_U / rtb_ProductN;
                        normp += t * t;
                    }

                    normp = rtb_ProductN * std::sqrt(normp);
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 /= normp;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 /= normp;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 /= normp;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 /= normp;
                }

                if (((rtb_CoordinateTransformationConversion_f_idx_0 *
                        rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 +
                        rtb_CoordinateTransformationConversion_f_idx_1 *
                        rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1) +
                        rtb_CoordinateTransformationConversion_f_idx_2 *
                        rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2) +
                        rtb_CoordinateTransformationConversion_f_idx_3 *
                        rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 <
                        0.0) {
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 =
                        -rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 =
                        -rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 =
                        -rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 =
                        -rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
                }

                qmult_idx_0 = ((rtb_CoordinateTransformationConversion_f_idx_0 *
                                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0
                                - -rtb_CoordinateTransformationConversion_f_idx_1
                                * rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1)
                               - -rtb_CoordinateTransformationConversion_f_idx_2
                               * rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2)
                    - -rtb_CoordinateTransformationConversion_f_idx_3 *
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3;
                rtb_U_tmp = (rtb_CoordinateTransformationConversion_f_idx_0 *
                             rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1
                             + rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0
                             * -rtb_CoordinateTransformationConversion_f_idx_1)
                    + (-rtb_CoordinateTransformationConversion_f_idx_2 *
                       rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 -
                       rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 *
                       -rtb_CoordinateTransformationConversion_f_idx_3);
                normq = (rtb_CoordinateTransformationConversion_f_idx_0 *
                         rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 +
                         rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 *
                         -rtb_CoordinateTransformationConversion_f_idx_2) +
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 *
                     -rtb_CoordinateTransformationConversion_f_idx_3 -
                     -rtb_CoordinateTransformationConversion_f_idx_1 *
                     rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3);
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 =
                    (rtb_CoordinateTransformationConversion_f_idx_0 *
                     rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 +
                     rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 *
                     -rtb_CoordinateTransformationConversion_f_idx_3) +
                    (-rtb_CoordinateTransformationConversion_f_idx_1 *
                     rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 -
                     rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 *
                     -rtb_CoordinateTransformationConversion_f_idx_2);
                rtb_ProductN = 3.3121686421112381E-170;
                rtb_U = std::abs(qmult_idx_0);
                if (rtb_U > 3.3121686421112381E-170) {
                    normp = 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / 3.3121686421112381E-170;
                    normp = t * t;
                }

                rtb_U = std::abs(rtb_U_tmp);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normp = normp * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normp += t * t;
                }

                rtb_U = std::abs(normq);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normp = normp * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normp += t * t;
                }

                rtb_U = std::abs
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normp = normp * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normp += t * t;
                }

                normp = rtb_ProductN * std::sqrt(normp);
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 =
                    qmult_idx_0 / normp;
                rtb_U_tmp /= normp;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 = 0.0;
                qmult_idx_0 = normq / normp;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 = 0.0;
                qmult = rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 /
                    normp;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 = 0.0;
                rtb_ProductN = 3.3121686421112381E-170;
                rtb_U = std::abs(rtb_U_tmp);
                if (rtb_U > 3.3121686421112381E-170) {
                    normp = 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / 3.3121686421112381E-170;
                    normp = t * t;
                }

                rtb_U = std::abs(qmult_idx_0);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normp = normp * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normp += t * t;
                }

                rtb_U = std::abs(qmult);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normp = normp * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normp += t * t;
                }

                normp = rtb_ProductN * std::sqrt(normp);
                normq = rt_atan2d_snf(normp,
                                      rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0);
                if (normp != 0.0) {
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 =
                        rtb_U_tmp / normp * normq;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 =
                        qmult_idx_0 / normp * normq;
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 = qmult /
                        normp * normq;
                }

                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 = tmp * 0.0;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 *= tmp;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 *= tmp;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 *= tmp;
                rtb_ProductN = 3.3121686421112381E-170;
                rtb_U = std::abs
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1);
                if (rtb_U > 3.3121686421112381E-170) {
                    normq = 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / 3.3121686421112381E-170;
                    normq = t * t;
                }

                rtb_U = std::abs
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normq = normq * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normq += t * t;
                }

                rtb_U = std::abs
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3);
                if (rtb_U > rtb_ProductN) {
                    t = rtb_ProductN / rtb_U;
                    normq = normq * t * t + 1.0;
                    rtb_ProductN = rtb_U;
                } else {
                    t = rtb_U / rtb_ProductN;
                    normq += t * t;
                }

                normq = rtb_ProductN * std::sqrt(normq);
                if (normq == 0.0) {
                    v[0] = 0.0;
                    v[1] = 0.0;
                    v[2] = 0.0;
                } else {
                    tmp = std::exp
                        (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0) *
                        std::sin(normq);
                    v[0] = tmp *
                        rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 /
                        normq;
                    v[1] = tmp *
                        rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 /
                        normq;
                    v[2] = tmp *
                        rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 /
                        normq;
                }

                qmult_idx_0 = std::exp
                    (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0) * std::
                    cos(normq);
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 =
                    ((rtb_CoordinateTransformationConversion_f_idx_0 *
                      qmult_idx_0 -
                      rtb_CoordinateTransformationConversion_f_idx_1 * v[0]) -
                     rtb_CoordinateTransformationConversion_f_idx_2 * v[1]) -
                    rtb_CoordinateTransformationConversion_f_idx_3 * v[2];
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 =
                    (rtb_CoordinateTransformationConversion_f_idx_0 * v[0] +
                     qmult_idx_0 *
                     rtb_CoordinateTransformationConversion_f_idx_1) +
                    (rtb_CoordinateTransformationConversion_f_idx_2 * v[2] - v[1]
                     * rtb_CoordinateTransformationConversion_f_idx_3);
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 =
                    (rtb_CoordinateTransformationConversion_f_idx_0 * v[1] +
                     qmult_idx_0 *
                     rtb_CoordinateTransformationConversion_f_idx_2) + (v[0] *
                    rtb_CoordinateTransformationConversion_f_idx_3 -
                    rtb_CoordinateTransformationConversion_f_idx_1 * v[2]);
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 =
                    (rtb_CoordinateTransformationConversion_f_idx_0 * v[2] +
                     qmult_idx_0 *
                     rtb_CoordinateTransformationConversion_f_idx_3) +
                    (rtb_CoordinateTransformationConversion_f_idx_1 * v[1] - v[0]
                     * rtb_CoordinateTransformationConversion_f_idx_2);
                tmp = rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 *
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0;
                tmp = 1.0 / std::sqrt
                    (((rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 *
                       rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 + tmp)
                      + rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 *
                      rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2) +
                     rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 *
                     rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3);
                rtb_CoordinateTransformationConversion_f_idx_0 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 * tmp;
                rtb_CoordinateTransformationConversion_f_idx_1 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_1 * tmp;
                rtb_CoordinateTransformationConversion_f_idx_2 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 * tmp;
                rtb_CoordinateTransformationConversion_f_idx_3 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_3 * tmp;
                tmp = (rtb_CoordinateTransformationConversion_f_idx_1 *
                       rtb_CoordinateTransformationConversion_f_idx_3 -
                       rtb_CoordinateTransformationConversion_f_idx_0 *
                       rtb_CoordinateTransformationConversion_f_idx_2) * -2.0;
                if (tmp > 1.0) {
                    tmp = 1.0;
                }

                if (tmp < -1.0) {
                    tmp = -1.0;
                }

                rtb_CoordinateTransformationConversion_f_idx_0 = rt_atan2d_snf
                    ((rtb_CoordinateTransformationConversion_f_idx_1 *
                      rtb_CoordinateTransformationConversion_f_idx_2 +
                      rtb_CoordinateTransformationConversion_f_idx_0 *
                      rtb_CoordinateTransformationConversion_f_idx_3) * 2.0,
                     ((rtb_CoordinateTransformationConversion_f_idx_0 *
                       rtb_CoordinateTransformationConversion_f_idx_0 +
                       rtb_CoordinateTransformationConversion_f_idx_1 *
                       rtb_CoordinateTransformationConversion_f_idx_1) -
                      rtb_CoordinateTransformationConversion_f_idx_2 *
                      rtb_CoordinateTransformationConversion_f_idx_2) -
                     rtb_CoordinateTransformationConversion_f_idx_3 *
                     rtb_CoordinateTransformationConversion_f_idx_3);
                rtb_CoordinateTransformationConversion_f_idx_1 = std::asin(tmp);
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0] *
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[0];
                rtb_Switch_a[0] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0 =
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1] *
                    rtb_TmpSignalConversionAtOrbitFollowerInport2[1];
                rtb_Switch_a[1] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0;
                tmp = rt_atan2d_snf
                    (rtb_TmpSignalConversionAtOrbitFollowerInport2[1],
                     rtb_TmpSignalConversionAtOrbitFollowerInport2[0]) -
                    rtb_CoordinateTransformationConversion_f_idx_0;
                if (std::abs(tmp) > 3.1415926535897931) {
                    if (std::isnan(tmp + 3.1415926535897931)) {
                        rtb_U = (rtNaN);
                    } else if (std::isinf(tmp + 3.1415926535897931)) {
                        rtb_U = (rtNaN);
                    } else if (tmp + 3.1415926535897931 == 0.0) {
                        rtb_U = 0.0;
                    } else {
                        rtb_U = std::fmod(tmp + 3.1415926535897931,
                                          6.2831853071795862);
                        rtb_RcvNextMission_o1 = (rtb_U == 0.0);
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_RcvNextMission_o1) ^ 1)))
                        {
                            t = std::abs((tmp + 3.1415926535897931) /
                                         6.2831853071795862);
                            rtb_RcvNextMission_o1 = static_cast<boolean_T>(
                                static_cast<int32_T>((std::abs(t - std::floor(t
                                + 0.5)) > 2.2204460492503131E-16 * t) ^ 1));
                        }

                        if (rtb_RcvNextMission_o1) {
                            rtb_U = 0.0;
                        } else if (tmp + 3.1415926535897931 < 0.0) {
                            rtb_U += 6.2831853071795862;
                        }
                    }

                    if (static_cast<boolean_T>(static_cast<int32_T>((rtb_U ==
                            0.0) & (tmp + 3.1415926535897931 > 0.0)))) {
                        rtb_U = 6.2831853071795862;
                    }

                    tmp = rtb_U - 3.1415926535897931;
                }

                rtb_ProductN = rt_atan2d_snf
                    (rtb_TmpSignalConversionAtOrbitFollowerInport2[2], std::sqrt
                     (rtb_Switch_a[0] + rtb_Switch_a[1])) -
                    rtb_CoordinateTransformationConversion_f_idx_1;
                if (std::abs(rtb_ProductN) > 3.1415926535897931) {
                    if (std::isnan(rtb_ProductN + 3.1415926535897931)) {
                        rtb_U = (rtNaN);
                    } else if (std::isinf(rtb_ProductN + 3.1415926535897931)) {
                        rtb_U = (rtNaN);
                    } else if (rtb_ProductN + 3.1415926535897931 == 0.0) {
                        rtb_U = 0.0;
                    } else {
                        rtb_U = std::fmod(rtb_ProductN + 3.1415926535897931,
                                          6.2831853071795862);
                        rtb_RcvNextMission_o1 = (rtb_U == 0.0);
                        if (static_cast<boolean_T>(static_cast<int32_T>(
                                static_cast<int32_T>(rtb_RcvNextMission_o1) ^ 1)))
                        {
                            t = std::abs((rtb_ProductN + 3.1415926535897931) /
                                         6.2831853071795862);
                            rtb_RcvNextMission_o1 = static_cast<boolean_T>(
                                static_cast<int32_T>((std::abs(t - std::floor(t
                                + 0.5)) > 2.2204460492503131E-16 * t) ^ 1));
                        }

                        if (rtb_RcvNextMission_o1) {
                            rtb_U = 0.0;
                        } else if (rtb_ProductN + 3.1415926535897931 < 0.0) {
                            rtb_U += 6.2831853071795862;
                        }
                    }

                    if (static_cast<boolean_T>(static_cast<int32_T>((rtb_U ==
                            0.0) & (rtb_ProductN + 3.1415926535897931 > 0.0))))
                    {
                        rtb_U = 6.2831853071795862;
                    }

                    rtb_ProductN = rtb_U - 3.1415926535897931;
                }

                rtb_Switch_a[0] = 0.0;
                rtb_Switch_a[1] = 1.0;
                tmp += rtb_CoordinateTransformationConversion_f_idx_0;
                xyCenter[0] = rtb_CoordinateTransformationConversion_f_idx_0;
                xyCenter[1] = tmp;
                LookUp_real_T_real_T( &(tmp), &xyCenter[0], 0.6, &rtb_Switch_a[0],
                                     1U);
                rtb_U = rtb_ProductN +
                    rtb_CoordinateTransformationConversion_f_idx_1;
                xyCenter[0] = rtb_CoordinateTransformationConversion_f_idx_1;
                xyCenter[1] = rtb_U;
                LookUp_real_T_real_T( &(rtb_U), &xyCenter[0], 0.6,
                                     &rtb_Switch_a[0], 1U);
                rtb_ProductN = std::cos(rtb_U);
                rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 = std::sqrt
                    ((rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 +
                      rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_0) +
                     rtb_TmpSignalConversionAtOrbitFollowerInport2[2] *
                     rtb_TmpSignalConversionAtOrbitFollowerInport2[2]);
                codegenReal2Mission_DW.ProductTargetVec[0] = std::cos(tmp) *
                    rtb_ProductN *
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
                codegenReal2Mission_DW.ProductTargetVec[1] = std::sin(tmp) *
                    rtb_ProductN *
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2;
                codegenReal2Mission_DW.ProductTargetVec[2] =
                    rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2 * std::
                    sin(rtb_U);
            }

            if (codegenReal2Mission_DW.RelationalOperator) {
                tmp = static_cast<real_T>
                    (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param1) /
                    rtb_LatitudeGCS_i;
                rtb_Sum_i = static_cast<real_T>
                    (codegenReal2Mission_DW.RcvImmedCMD_o2.params.Param2) /
                    rtb_Sum_i;
                codegenReal2Mission_DW.Switch[0] = (tmp *
                    codegenReal2Mission_DW.ProductTargetVec[0] + rtb_Sum_i *
                    codegenReal2Mission_DW.ProductTargetVec[0]) +
                    rtb_AltitudeGCS_d;
                codegenReal2Mission_DW.Switch[1] = (tmp *
                    codegenReal2Mission_DW.ProductTargetVec[1] + rtb_Sum_i *
                    codegenReal2Mission_DW.ProductTargetVec[1]) + rtb_Switch_hk;
                codegenReal2Mission_DW.Switch[2] = (tmp *
                    codegenReal2Mission_DW.ProductTargetVec[2] + rtb_Sum_i *
                    codegenReal2Mission_DW.ProductTargetVec[2]) + rtb_Switch_b;
            } else {
                codegenReal2Mission_DW.Switch[0] = check;
                codegenReal2Mission_DW.Switch[1] = fracSecs;
                codegenReal2Mission_DW.Switch[2] =
                    codegenReal2Mission_DW.Height_f;
            }

            codegenReal2Mission_DW.North = codegenReal2Mission_DW.Switch[0];
            codegenReal2Mission_DW.East = codegenReal2Mission_DW.Switch[1];
            codegenReal2Mission_DW.Height = codegenReal2Mission_DW.Switch[2];
            codegenReal2Mission_DW.AirSpeed = codegenReal2Mission_DW.AirSpeed_a;
            codegenReal2Mission_DW.HeadingAngle =
                codegenReal2Mission_DW.HeadingAngle_g;
            codegenReal2Mission_DW.FlightPathAngle =
                codegenReal2Mission_DW.FlightPathAngle_h;
            codegenReal2Mission_DW.RollAngle =
                codegenReal2Mission_DW.RollAngle_b;
            codegenReal2Mission_DW.RollAngleRate =
                codegenReal2Mission_DW.RollAngleRate_a;
            rtb_AltitudeGCS_d = static_cast<real_T>
                (codegenReal2Mission_DW.RelationalOperator);
            codegenReal2Mission_DW.MatrixConcatenate[360] =
                codegenReal2Mission_DW.Switch[0];
            codegenReal2Mission_DW.MatrixConcatenate[721] =
                codegenReal2Mission_DW.Switch[1];
            codegenReal2Mission_DW.TrackInvH = -codegenReal2Mission_DW.Switch[2];
            codegenReal2Mission_DW.MatrixConcatenate[1082] =
                codegenReal2Mission_DW.TrackInvH;
            for (i = 0; i < 360; i++) {
                codegenReal2Mission_DW.MatrixConcatenate[i] =
                    codegenReal2Mission_DW.NorthSequence_X[i];
                codegenReal2Mission_DW.MatrixConcatenate[static_cast<int_T>(i +
                    361)] = codegenReal2Mission_DW.EastSequence_X[i];
                codegenReal2Mission_DW.MatrixConcatenate[static_cast<int_T>(i +
                    722)] = codegenReal2Mission_DW.HeightSequence_X[i];
                rtb_InDangerSequence[i] =
                    codegenReal2Mission_DW.InDangerSequence_X[i];
            }

            rtb_InDangerSequence[360] =
                codegenReal2Mission_DW.RelationalOperator;
            i = 0;
            for (fileID = 0; fileID < 361; fileID++) {
                if (rtb_InDangerSequence[fileID]) {
                    i = static_cast<int32_T>(i + 1);
                }
            }

            if (i <= 73) {
                codegenReal2Mission_DW.SFunction_DIMS2[0] = 73;
                codegenReal2Mission_DW.SFunction_DIMS2[1] = 3;
                for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 3;
                        rtb_RcvNextMission_o1_0++) {
                    for (i = 0; i < 73; i++) {
                        codegenReal2Mission_DW.Track[static_cast<int32_T>(i +
                            static_cast<int32_T>
                            (codegenReal2Mission_DW.SFunction_DIMS2[0] *
                             rtb_RcvNextMission_o1_0))] =
                            codegenReal2Mission_DW.MatrixConcatenate[
                            static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(361 * rtb_RcvNextMission_o1_0)
                            + i) + 288)];
                    }
                }
            } else {
                i = 0;
                for (fileID = 0; fileID < 361; fileID++) {
                    if (rtb_InDangerSequence[fileID]) {
                        i = static_cast<int32_T>(i + 1);
                    }
                }

                b_size_idx_0 = i;
                i = 0;
                for (fileID = 0; fileID < 361; fileID++) {
                    if (rtb_InDangerSequence[fileID]) {
                        b_data[i] = static_cast<int16_T>(static_cast<int32_T>
                            (fileID + 1));
                        i = static_cast<int32_T>(i + 1);
                    }
                }

                codegenReal2Mission_DW.SFunction_DIMS2[0] = b_size_idx_0;
                codegenReal2Mission_DW.SFunction_DIMS2[1] = 3;
                for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 3;
                        rtb_RcvNextMission_o1_0++) {
                    for (i = 0; i <= static_cast<int32_T>(b_size_idx_0 - 1); i++)
                    {
                        codegenReal2Mission_DW.Track[static_cast<int32_T>(i +
                            static_cast<int32_T>
                            (codegenReal2Mission_DW.SFunction_DIMS2[0] *
                             rtb_RcvNextMission_o1_0))] =
                            codegenReal2Mission_DW.MatrixConcatenate[
                            static_cast<int32_T>(static_cast<int32_T>(
                            static_cast<int32_T>(361 * rtb_RcvNextMission_o1_0)
                            + static_cast<int32_T>(b_data[i])) - 1)];
                    }
                }
            }

            if (static_cast<uint32_T>(codegenReal2Mission_DW.temporalCounter_i1)
                < 127U) {
                codegenReal2Mission_DW.temporalCounter_i1 = static_cast<uint8_T>
                    (static_cast<uint32_T>(static_cast<uint32_T>
                      (codegenReal2Mission_DW.temporalCounter_i1) + 1U));
            }

            if (static_cast<uint32_T>
                    (codegenReal2Mission_DW.is_active_c10_codegenReal2Mission) ==
                0U) {
                codegenReal2Mission_DW.is_active_c10_codegenReal2Mission = 1U;
                codegenReal2Mission_DW.is_c10_codegenReal2Mission =
                    codegenReal2Mission_IN_Short;
                codegenReal2Mission_DW.MergeControlSwitch[0] = false;
            } else if (static_cast<int32_T>
                       (codegenReal2Mission_DW.is_c10_codegenReal2Mission) == 1)
            {
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((static_cast<uint32_T>
                        (codegenReal2Mission_DW.temporalCounter_i1) >= 100U) &
                                            static_cast<int32_T>
                                            (static_cast<boolean_T>
                        (static_cast<int32_T>((static_cast<int32_T>
                          (rtb_MemoryStatus) != 0) & (rtb_LatitudeGCS_i -
                          codegenReal2Mission_DW.MemoryPrevRange_PreviousInput >=
                          0.0))))))) {
                    codegenReal2Mission_DW.is_c10_codegenReal2Mission =
                        codegenReal2Mission_IN_Short;
                    codegenReal2Mission_DW.MergeControlSwitch[0] = false;
                } else {
                    codegenReal2Mission_DW.MergeControlSwitch[0] = true;
                }
            } else if (codegenReal2Mission_DW.RelationalOperator) {
                codegenReal2Mission_DW.is_c10_codegenReal2Mission =
                    codegenReal2Mission_IN_Long;
                codegenReal2Mission_DW.temporalCounter_i1 = 0U;
                codegenReal2Mission_DW.MergeControlSwitch[0] = true;
            } else {
                codegenReal2Mission_DW.MergeControlSwitch[0] = false;
            }

            for (fileID = 0; fileID < 359; fileID++) {
                codegenReal2Mission_DW.NorthSequence_X[fileID] =
                    codegenReal2Mission_DW.NorthSequence_X[static_cast<int_T>
                    (fileID + 1)];
                codegenReal2Mission_DW.EastSequence_X[fileID] =
                    codegenReal2Mission_DW.EastSequence_X[static_cast<int_T>
                    (fileID + 1)];
                codegenReal2Mission_DW.HeightSequence_X[fileID] =
                    codegenReal2Mission_DW.HeightSequence_X[static_cast<int_T>
                    (fileID + 1)];
                codegenReal2Mission_DW.InDangerSequence_X[fileID] =
                    codegenReal2Mission_DW.InDangerSequence_X[static_cast<int_T>
                    (fileID + 1)];
            }

            codegenReal2Mission_DW.NorthSequence_X[359] =
                codegenReal2Mission_DW.Switch[0];
            codegenReal2Mission_DW.EastSequence_X[359] =
                codegenReal2Mission_DW.Switch[1];
            codegenReal2Mission_DW.HeightSequence_X[359] =
                codegenReal2Mission_DW.TrackInvH;
            codegenReal2Mission_DW.InDangerSequence_X[359] =
                codegenReal2Mission_DW.RelationalOperator;
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (codegenReal2Mission_DW.obj.CacheInputSizes) ^ 1))) {
                codegenReal2Mission_DW.obj.CacheInputSizes = true;
                for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 8;
                        rtb_RcvNextMission_o1_0++) {
                    codegenReal2Mission_DW.obj.inputVarSize[0]
                        .f1[rtb_RcvNextMission_o1_0] = 1U;
                }

                rtb_RcvNextMission_o1_0 =
                    codegenReal2Mission_DW.SFunction_DIMS2[0];
                if (codegenReal2Mission_DW.SFunction_DIMS2[0] < 0) {
                    rtb_RcvNextMission_o1_0 = 0;
                }

                codegenReal2Mission_DW.obj.inputVarSize[1].f1[0] =
                    static_cast<uint32_T>(rtb_RcvNextMission_o1_0);
                rtb_RcvNextMission_o1_0 =
                    codegenReal2Mission_DW.SFunction_DIMS2[1];
                if (codegenReal2Mission_DW.SFunction_DIMS2[1] < 0) {
                    rtb_RcvNextMission_o1_0 = 0;
                }

                codegenReal2Mission_DW.obj.inputVarSize[1].f1[1] =
                    static_cast<uint32_T>(rtb_RcvNextMission_o1_0);
                for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 6;
                        rtb_RcvNextMission_o1_0++) {
                    codegenReal2Mission_DW.obj.inputVarSize[1].f1
                        [static_cast<int32_T>(rtb_RcvNextMission_o1_0 + 2)] = 1U;
                }

                for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 8;
                        rtb_RcvNextMission_o1_0++) {
                    codegenReal2Mission_DW.obj.inputVarSize[2]
                        .f1[rtb_RcvNextMission_o1_0] = 1U;
                }
            }

            rtb_RcvNextMission_o1_0 = codegenReal2Mission_DW.SFunction_DIMS2[0];
            if (codegenReal2Mission_DW.SFunction_DIMS2[0] < 0) {
                rtb_RcvNextMission_o1_0 = 0;
            }

            inSize[0] = static_cast<uint32_T>(rtb_RcvNextMission_o1_0);
            rtb_RcvNextMission_o1_0 = codegenReal2Mission_DW.SFunction_DIMS2[1];
            if (codegenReal2Mission_DW.SFunction_DIMS2[1] < 0) {
                rtb_RcvNextMission_o1_0 = 0;
            }

            inSize[1] = static_cast<uint32_T>(rtb_RcvNextMission_o1_0);
            for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 6;
                    rtb_RcvNextMission_o1_0++) {
                inSize[static_cast<int32_T>(rtb_RcvNextMission_o1_0 + 2)] = 1U;
            }

            rtb_RcvNextMission_o1_0 = 0;
            exitg1 = false;
            while ((!exitg1) && (rtb_RcvNextMission_o1_0 < 8)) {
                if (codegenReal2Mission_DW.obj.inputVarSize[1]
                        .f1[rtb_RcvNextMission_o1_0] !=
                        inSize[rtb_RcvNextMission_o1_0]) {
                    for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 <
                            8; rtb_RcvNextMission_o1_0++) {
                        codegenReal2Mission_DW.obj.inputVarSize[1]
                            .f1[rtb_RcvNextMission_o1_0] =
                            inSize[rtb_RcvNextMission_o1_0];
                    }

                    exitg1 = true;
                } else {
                    rtb_RcvNextMission_o1_0 = static_cast<int32_T>
                        (rtb_RcvNextMission_o1_0 + 1);
                }
            }

            absx_0[0] = absx;
            absx_0[1] = rtb_Sign_c;
            absx_0[2] = rtb_Down;
            absx_0[3] = distToCenter;
            for (rtb_RcvNextMission_o1_0 = 0; rtb_RcvNextMission_o1_0 < 2;
                    rtb_RcvNextMission_o1_0++) {
                tmp_0[rtb_RcvNextMission_o1_0] =
                    codegenReal2Mission_DW.SFunction_DIMS2[rtb_RcvNextMission_o1_0];
            }

            codegenReal2Mission_WaypointFollowerBase_stepInternal
                (&codegenReal2Mission_DW.obj, absx_0,
                 codegenReal2Mission_DW.Track, tmp_0, 126.0, rtb_Sum_h,
                 &codegenReal2Mission_DW.MergeGuidanceCMD.HeadingAngle, &tmp,
                 &rtb_MemoryStatus, &rtb_Switch_hk,
                 &codegenReal2Mission_DW.MemoryStatus_PreviousInput);
            codegenReal2Mission_DW.MergeGuidanceCMD.Height =
                codegenReal2Mission_DW.Switch[2];
            codegenReal2Mission_DW.MergeGuidanceCMD.AirSpeed = 0.0;
            codegenReal2Mission_DW.MergeControlSwitch[1] = false;
            rtb_Compare_gf = codegenReal2Mission_DW.RelationalOperator;
            codegenReal2Mission_DW.MemoryPrevRange_PreviousInput =
                rtb_LatitudeGCS_i;
            break;

          case 2:
            codegenReal2Mission_DW.MergeControlSwitch[0] = false;
            codegenReal2Mission_DW.MergeControlSwitch[1] = false;
            codegenReal2Mission_DW.AirSpeed = codegenReal2Mission_DW.AirSpeed_a;
            codegenReal2Mission_DW.HeadingAngle =
                codegenReal2Mission_DW.HeadingAngle_g;
            codegenReal2Mission_DW.FlightPathAngle =
                codegenReal2Mission_DW.FlightPathAngle_h;
            codegenReal2Mission_DW.RollAngle =
                codegenReal2Mission_DW.RollAngle_b;
            codegenReal2Mission_DW.RollAngleRate =
                codegenReal2Mission_DW.RollAngleRate_a;
            tmp = 0.017453292519943295 *
                codegenReal2Mission_DW.cmdFlightMission.MissionLocation.degHDG +
                1.5707963267948966;
            rtb_Compare_gf =
                (codegenReal2Mission_DW.cmdFlightMission.MissionMode ==
                 HorzFrmnNav);
            rtb_AltitudeGCS_d = static_cast<real_T>(rtb_Compare_gf);
            absx = static_cast<real_T>(static_cast<int32_T>
                (codegenReal2Mission_DW.cmdFlightMission.numUAV - 1)) *
                static_cast<real_T>
                (codegenReal2Mission_DW.cmdFlightMission.params.Param3) /
                static_cast<real_T>(static_cast<int32_T>
                                    (codegenReal2Mission_DW.RcvImmedCMD_o2.numUAV
                - 1)) * (static_cast<real_T>
                         (codegenReal2Mission_DW.RcvImmedCMD_o2.FormationPos) +
                         -1.0) - static_cast<real_T>(static_cast<int32_T>
                (codegenReal2Mission_DW.cmdFlightMission.FormationPos - 1)) *
                static_cast<real_T>
                (codegenReal2Mission_DW.cmdFlightMission.params.Param3);
            codegenReal2Mission_DW.East = std::sin(tmp) * absx + fracSecs;
            codegenReal2Mission_DW.Height = (codegenReal2Mission_DW.Height_f -
                rt_modd_snf(static_cast<real_T>
                            (codegenReal2Mission_DW.cmdFlightMission.FormationPos)
                            - 1.0, 3.0) * 15.0) + rt_modd_snf(static_cast<real_T>
                (codegenReal2Mission_DW.RcvImmedCMD_o2.FormationPos) - 1.0, 3.0)
                * 15.0;
            codegenReal2Mission_DW.North = std::cos(tmp) * absx + check;
            break;

          default:
            codegenReal2Mission_DW.MergeControlSwitch[0] = false;
            codegenReal2Mission_DW.MergeControlSwitch[1] = false;
            rtb_Compare_gf = false;
            rtb_AltitudeGCS_d = -1.0;
            break;
        }

        if (rtb_Compare_gf) {
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.North
                = codegenReal2Mission_DW.North;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.East
                = codegenReal2Mission_DW.East;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.Height
                = codegenReal2Mission_DW.Height;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.AirSpeed
                = codegenReal2Mission_DW.AirSpeed;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.HeadingAngle
                = codegenReal2Mission_DW.HeadingAngle;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.FlightPathAngle
                = codegenReal2Mission_DW.FlightPathAngle;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.RollAngle
                = codegenReal2Mission_DW.RollAngle;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.RollAngleRate
                = codegenReal2Mission_DW.RollAngleRate;
        } else {
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.North
                = check;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.East
                = fracSecs;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.Height
                = codegenReal2Mission_DW.Height_f;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.AirSpeed
                = codegenReal2Mission_DW.AirSpeed_a;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.HeadingAngle
                = codegenReal2Mission_DW.HeadingAngle_g;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.FlightPathAngle
                = codegenReal2Mission_DW.FlightPathAngle_h;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.RollAngle
                = codegenReal2Mission_DW.RollAngle_b;
            codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1.RollAngleRate
                = codegenReal2Mission_DW.RollAngleRate_a;
        }

        codegenReal2Mission_DW.BooleanImmedMode = (ahi != 0.0);
        rtb_RcvNextMission_o1_0 =
            codegenReal2Mission_ReceiveThisMission_RecvData
            (&codegenReal2Mission_DW.ReceiveThisMission_o2);
        rtb_Compare_gf = (rtb_RcvNextMission_o1_0 != 1);
        rtb_CoordinateTransformationConversion_f_idx_0 = std::floor
            (codegenReal2Mission_DW.thisTaskStatus);
        if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(std::
                isnan(rtb_CoordinateTransformationConversion_f_idx_0)) |
                static_cast<int32_T>(std::isinf
                (rtb_CoordinateTransformationConversion_f_idx_0))))) {
            rtb_CoordinateTransformationConversion_f_idx_0 = 0.0;
        } else {
            rtb_CoordinateTransformationConversion_f_idx_0 = std::fmod
                (rtb_CoordinateTransformationConversion_f_idx_0, 4.294967296E+9);
        }

        codegenReal2Mission_Y.thisTaskStatus.FlightStatus =
            rtb_CoordinateTransformationConversion_f_idx_0 < 0.0 ?
            static_cast<int32_T>(-static_cast<int32_T>(static_cast<uint32_T>
            (-rtb_CoordinateTransformationConversion_f_idx_0))) :
            static_cast<int32_T>(static_cast<uint32_T>
            (rtb_CoordinateTransformationConversion_f_idx_0));
        rtb_RcvNextMission_o1_0 = static_cast<int32_T>(std::fmod
            (static_cast<real_T>(static_cast<int32_T>(rtb_AltitudeGCS_d)),
             4.294967296E+9));
        codegenReal2Mission_Y.thisTaskStatus.ImmedStatus =
            rtb_RcvNextMission_o1_0 < 0 ? static_cast<int32_T>
            (-static_cast<int32_T>(static_cast<uint32_T>(-static_cast<real_T>
               (rtb_RcvNextMission_o1_0)))) : rtb_RcvNextMission_o1_0;
        codegenReal2Mission_Y.thisTaskStatus.SequenceID =
            codegenReal2Mission_DW.ReceiveThisMission_o2.SequenceID;
        codegenReal2Mission_Y.thisTaskStatus.MissionMode =
            codegenReal2Mission_DW.cmdFlightMission.MissionMode;
        codegenReal2Mission_Y.thisTaskStatus.numUAV =
            codegenReal2Mission_DW.cmdFlightMission.numUAV;
        codegenReal2Mission_Y.thisTaskStatus.FormationPos =
            codegenReal2Mission_DW.cmdFlightMission.FormationPos;
    }

    Real2SimGuidance(&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
                     &codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1,
                     &codegenReal2Mission_DW.BooleanImmedMode,
                     &codegenReal2Mission_U.RealUAVLatLonState,
                     &codegenReal2Mission_U.FlightMode,
                     &codegenReal2Mission_U.GroundSpeed,
                     &codegenReal2Mission_DW.MergeControlSwitch[0],
                     &codegenReal2Mission_DW.MergeGuidanceCMD,
                     &codegenReal2Mission_Y.thisTaskStatus.MissionMode,
                     &codegenReal2Mission_Y.thisTaskStatus.numUAV,
                     &codegenReal2Mission_Y.thisTaskStatus.FormationPos,
                     &codegenReal2Mission_Y.LookAheadPoint_i,
                     &codegenReal2Mission_Y.RefAirspeed,
                     &codegenReal2Mission_DW.Real2SimGuidance_o3,
                     &codegenReal2Mission_Y.EngagedFlag,
                     &codegenReal2Mission_DW.RealUAVState,
                     &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
                     &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));
    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (rtb_Compare_gf) & (static_cast<int32_T>
                                        (codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE)
                   != 1)))) {
                fracSecs =
                    codegenReal2Mission_DW.ReceiveThisMission_o2.StartTime *
                    1000.0;
                codegenReal2Mission_getDateVec_i(fracSecs, &tmp, &check, &ahi,
                    &absx, &rtb_Sign_c, &distToCenter);
                codegenReal2Mission_getDateVec_i(fracSecs, &ahi, &check, &absx,
                    &rtb_Sign_c, &distToCenter, &rtb_Down);
                codegenReal2Mission_getDateVec_i(fracSecs, &absx, &rtb_Sign_c,
                    &ahi, &distToCenter, &rtb_Down, &rtb_AltitudeGCS_d);
                codegenReal2Mission_getDateVec_i(fracSecs, &rtb_Sign_c,
                    &distToCenter, &rtb_Down, &absx, &rtb_AltitudeGCS_d,
                    &rtb_LatitudeGCS_i);
                codegenReal2Mission_getDateVec_i(fracSecs, &distToCenter,
                    &rtb_Down, &rtb_AltitudeGCS_d, &rtb_LatitudeGCS_i,
                    &rtb_Sign_c, &rtb_Switch_hk);
                codegenReal2Mission_getDateVec_i(fracSecs, &rtb_Down,
                    &rtb_AltitudeGCS_d, &rtb_LatitudeGCS_i, &rtb_Switch_hk,
                    &rtb_Switch_b, &distToCenter);
                codegenReal2Mission_getDateVec_i(fracSecs, &rtb_AltitudeGCS_d,
                    &rtb_LatitudeGCS_i, &rtb_Switch_hk, &rtb_Switch_b,
                    &rtb_Sum_i, &rtb_Down);
                codegenReal2Mission_getDateVec_i(fracSecs, &rtb_AltitudeGCS_d,
                    &rtb_LatitudeGCS_i, &rtb_Switch_hk, &rtb_Switch_b,
                    &rtb_Sum_i,
                    &rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2);
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
                rtb_CoordinateTransformationConversion_f_idx_0 = std::round(tmp);
                if (rtb_CoordinateTransformationConversion_f_idx_0 <
                        2.147483648E+9) {
                    if (rtb_CoordinateTransformationConversion_f_idx_0 >=
                            -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.year =
                            static_cast<int32_T>
                            (rtb_CoordinateTransformationConversion_f_idx_0);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.year =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.year = MAX_int32_T;
                }

                rtb_CoordinateTransformationConversion_f_idx_0 = std::round
                    (check);
                if (rtb_CoordinateTransformationConversion_f_idx_0 <
                        2.147483648E+9) {
                    if (rtb_CoordinateTransformationConversion_f_idx_0 >=
                            -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.month =
                            static_cast<int32_T>
                            (rtb_CoordinateTransformationConversion_f_idx_0);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.month =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.month =
                        MAX_int32_T;
                }

                rtb_CoordinateTransformationConversion_f_idx_0 = std::round(ahi);
                if (rtb_CoordinateTransformationConversion_f_idx_0 <
                        2.147483648E+9) {
                    if (rtb_CoordinateTransformationConversion_f_idx_0 >=
                            -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.day =
                            static_cast<int32_T>
                            (rtb_CoordinateTransformationConversion_f_idx_0);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.day =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.day = MAX_int32_T;
                }

                rtb_CoordinateTransformationConversion_f_idx_0 = std::round(absx);
                if (rtb_CoordinateTransformationConversion_f_idx_0 <
                        2.147483648E+9) {
                    if (rtb_CoordinateTransformationConversion_f_idx_0 >=
                            -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.hour =
                            static_cast<int32_T>
                            (rtb_CoordinateTransformationConversion_f_idx_0);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.hour =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.hour = MAX_int32_T;
                }

                rtb_CoordinateTransformationConversion_f_idx_0 = std::round
                    (rtb_Sign_c);
                if (rtb_CoordinateTransformationConversion_f_idx_0 <
                        2.147483648E+9) {
                    if (rtb_CoordinateTransformationConversion_f_idx_0 >=
                            -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                            static_cast<int32_T>
                            (rtb_CoordinateTransformationConversion_f_idx_0);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.minute =
                        MAX_int32_T;
                }

                rtb_CoordinateTransformationConversion_f_idx_0 = std::floor
                    (distToCenter);
                if (rtb_CoordinateTransformationConversion_f_idx_0 <
                        2.147483648E+9) {
                    if (rtb_CoordinateTransformationConversion_f_idx_0 >=
                            -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.second =
                            static_cast<int32_T>
                            (rtb_CoordinateTransformationConversion_f_idx_0);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.second =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.second =
                        MAX_int32_T;
                }

                rtb_CoordinateTransformationConversion_f_idx_0 = std::round
                    ((rtb_Down - std::floor
                      (rtb_TmpSignalConversionAtOrbitFollowerInport1_idx_2)) *
                     1000.0);
                if (rtb_CoordinateTransformationConversion_f_idx_0 <
                        2.147483648E+9) {
                    if (rtb_CoordinateTransformationConversion_f_idx_0 >=
                            -2.147483648E+9) {
                        codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                            static_cast<int32_T>
                            (rtb_CoordinateTransformationConversion_f_idx_0);
                    } else {
                        codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                            MIN_int32_T;
                    }
                } else {
                    codegenReal2Mission_DW.IndivCMD.StartTime.millisecond =
                        MAX_int32_T;
                }

                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>
                                            (codegenReal2Mission_DW.NewRun_not_empty)
                      ^ 1))) {
                    rtPrevAction = codegenReal2Mission_cfopen(
                        "OnboardMissionCMD.log", "wb");
                    fileID = static_cast<int32_T>(rtPrevAction);
                    codegenReal2Mission_DW.NewRun = 1.0;
                    codegenReal2Mission_DW.NewRun_not_empty = true;
                } else {
                    rtPrevAction = codegenReal2Mission_cfopen(
                        "OnboardMissionCMD.log", "ab");
                    fileID = static_cast<int32_T>(rtPrevAction);
                    codegenReal2Mission_DW.NewRun++;
                }

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
                     static_cast<real_T>(fileID));
                codegenReal2Mission_cfclose(static_cast<real_T>(fileID));
                CurrentMissionSendData.SendData(&codegenReal2Mission_DW.IndivCMD,
                    sizeof(IndividualUAVCmd), &status);
            }

            codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
                static_cast<ZCSigState>(rtb_Compare_gf);
        }

        codegenReal2Mission_DW.NonDeterministic_Buffer0 = second;
        rtw_pthread_mutex_lock
            (codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
        rtPrevAction = static_cast<int8_T>(static_cast<int32_T>
            (static_cast<int32_T>(codegenReal2Mission_DW.RateTransition_LstBufWR)
             + 1));
        if (static_cast<int32_T>(rtPrevAction) == 3) {
            rtPrevAction = 0;
        }

        if (static_cast<int32_T>(rtPrevAction) == static_cast<int32_T>
                (codegenReal2Mission_DW.RateTransition_RDBuf)) {
            rtPrevAction = static_cast<int8_T>(static_cast<int32_T>(static_cast<
                int32_T>(rtPrevAction) + 1));
            if (static_cast<int32_T>(rtPrevAction) == 3) {
                rtPrevAction = 0;
            }
        }

        rtw_pthread_mutex_unlock
            (codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
        codegenReal2Mission_DW.RateTransition_Buf[static_cast<int32_T>
            (rtPrevAction)] = codegenReal2Mission_DW.cmdFlightMission;
        codegenReal2Mission_DW.RateTransition_LstBufWR = rtPrevAction;
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        rt_UpdateTXYLogVars((&codegenReal2Mission_M)->rtwLogInfo,
                            ((&codegenReal2Mission_M)->Timing.t));
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            codegenReal2Mission_DW.MemoryPose_PreviousInput_h[0] =
                codegenReal2Mission_DW.North_o;
            codegenReal2Mission_DW.MemoryPose_PreviousInput_h[1] =
                codegenReal2Mission_DW.East_k;
            codegenReal2Mission_DW.MemoryPose_PreviousInput_h[2] = rtb_Down_c;
            codegenReal2Mission_DW.MemoryPose_PreviousInput_h[3] =
                codegenReal2Mission_DW.HeadingAngle_g;
            FlightMissionMode_Update
                (&(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));
        }

        if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
            MissionUAV_Update
                (&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw));
        }

        if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
            codegenReal2Mission_DW.MemoryPose_PreviousInput =
                codegenReal2Mission_DW.RealUAVState;
        }

        Real2SimGuidance_Update
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm),
             &codegenReal2Mission_DW.BusConversion_InsertedFor_Real2SimGuidance_at_inport_0_BusCreator1,
             &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw));
    }

    if (rtmIsMajorTimeStep((&codegenReal2Mission_M))) {
        {
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
        if (!(++(&codegenReal2Mission_M)->Timing.clockTick0)) {
            ++(&codegenReal2Mission_M)->Timing.clockTickH0;
        }

        (&codegenReal2Mission_M)->Timing.t[0] = rtsiGetSolverStopTime
            (&(&codegenReal2Mission_M)->solverInfo);

        {
            (&codegenReal2Mission_M)->Timing.clockTick1++;
            if (!(&codegenReal2Mission_M)->Timing.clockTick1) {
                (&codegenReal2Mission_M)->Timing.clockTickH1++;
            }
        }
    }
}

void codegenReal2MissionModelClass::codegenReal2Mission_derivatives()
{
    if (codegenReal2Mission_DW.MissionSimUAV_MODE) {
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

    Real2SimGuidance_Deriv
        (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
         &(((XDot_codegenReal2Mission_T *) (&codegenReal2Mission_M)->derivs)
           ->Real2SimGuidance_CSTATE));
}

void codegenReal2MissionModelClass::codegenReal2Mission_PushNewMission()
{
    Location *NewCMD_MissionLocation;
    Location *NewCMD_StartPosition;
    Parameters *NewCMD_params;
    missionCmd RateTransition;
    missionCmd rtb_SndCMD;
    missionCmd rtb_ThisCMD;
    creal_T thisData;
    real_T c_tm_year_0[7];
    real_T processedInData[7];
    real_T NewCMD_StartTime_tmp;
    real_T NonDeterministic;
    real_T a__17;
    real_T a__23;
    real_T a__29;
    real_T a__35;
    real_T b_a__35;
    real_T c_s;
    real_T c_tm_hour;
    real_T c_tm_mday;
    real_T c_tm_min;
    real_T c_tm_mon;
    real_T c_tm_year;
    int32_T D;
    int32_T H;
    int32_T M;
    int32_T MI;
    int32_T MS;
    int32_T NewCMD_FormationPos;
    int32_T NewCMD_SequenceID;
    int32_T NewCMD_numUAV;
    int32_T S;
    int32_T Y;
    int32_T status{ 1 };

    boolean_T expl_temp;
    MissionModes NewCMD_MissionMode;
    NonDeterministic = codegenReal2Mission_DW.NonDeterministic_Buffer0;
    rtw_pthread_mutex_lock(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
    codegenReal2Mission_DW.RateTransition_RDBuf =
        codegenReal2Mission_DW.RateTransition_LstBufWR;
    rtw_pthread_mutex_unlock(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
    RateTransition =
        codegenReal2Mission_DW.RateTransition_Buf[codegenReal2Mission_DW.RateTransition_RDBuf];
    status = 1;
    MissionCMDRecvData.RecvData(&codegenReal2Mission_DW.ReceivePushedMissionCMD,
        sizeof(IndividualUAVCmd), &status);
    status = 0;
    rtb_ThisCMD = codegenReal2Mission_DW.MissionCMD;
    rtb_SndCMD = codegenReal2Mission_DW.MissionCMD;
    Y = codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.year;
    M = codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.month;
    D = codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.day;
    H = codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.hour;
    MI = codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.minute;
    S = codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.second;
    MS = codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.millisecond;
    processedInData[0] = static_cast<real_T>
        (codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.year);
    processedInData[1] = static_cast<real_T>
        (codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.month);
    processedInData[2] = static_cast<real_T>
        (codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.day);
    processedInData[3] = static_cast<real_T>
        (codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.hour);
    processedInData[4] = static_cast<real_T>
        (codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.minute);
    processedInData[5] = static_cast<real_T>
        (codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.second);
    processedInData[6] = static_cast<real_T>
        (codegenReal2Mission_DW.ReceivePushedMissionCMD.StartTime.millisecond);
    NewCMD_SequenceID =
        codegenReal2Mission_DW.ReceivePushedMissionCMD.SequenceID;
    NewCMD_MissionMode =
        codegenReal2Mission_DW.ReceivePushedMissionCMD.MissionMode;
    NewCMD_MissionLocation =
        &codegenReal2Mission_DW.ReceivePushedMissionCMD.MissionLocation;
    NewCMD_params = &codegenReal2Mission_DW.ReceivePushedMissionCMD.params;
    NewCMD_StartPosition =
        &codegenReal2Mission_DW.ReceivePushedMissionCMD.StartPosition;
    NewCMD_numUAV = codegenReal2Mission_DW.ReceivePushedMissionCMD.numUAV;
    NewCMD_FormationPos =
        codegenReal2Mission_DW.ReceivePushedMissionCMD.FormationPos;
    NewCMD_StartTime_tmp = (codegenReal2Mission_createFromDateVec
                            (processedInData)).re / 1000.0;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
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
              codegenReal2Mission_DW.MissionCMD.StartTime, NewCMD_SequenceID,
              NewCMD_MissionMode, *NewCMD_MissionLocation, *NewCMD_params,
              *NewCMD_StartPosition, NewCMD_numUAV, NewCMD_FormationPos,
              NewCMD_StartTime_tmp)) ^ 1))) {
        if (static_cast<boolean_T>(static_cast<int32_T>
                                   ((codegenReal2Mission_DW.ReceivePushedMissionCMD.MissionMode
               == None) & (codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param7
                           == 1.0F)))) {
            rtb_ThisCMD = RateTransition;
            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param1
                   != 0.0F) ^ 1))) {
                rtb_ThisCMD.params.Param1 =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param1;
                rtb_ThisCMD.SequenceID =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.SequenceID;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param2
                   != 0.0F) ^ 1))) {
                rtb_ThisCMD.params.Param2 =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param2;
                rtb_ThisCMD.SequenceID =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.SequenceID;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param3
                   != 0.0F) ^ 1))) {
                rtb_ThisCMD.params.Param3 =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param3;
                rtb_ThisCMD.SequenceID =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.SequenceID;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param4
                   != 0.0F) ^ 1))) {
                rtb_ThisCMD.params.Param4 =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param4;
                rtb_ThisCMD.SequenceID =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.SequenceID;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param5
                   != 0.0F) ^ 1))) {
                rtb_ThisCMD.params.Param5 =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param5;
                rtb_ThisCMD.SequenceID =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.SequenceID;
            }

            if (static_cast<boolean_T>(static_cast<int32_T>
                                       ((codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param6
                   != 0.0F) ^ 1))) {
                rtb_ThisCMD.params.Param6 =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.params.Param6;
                rtb_ThisCMD.SequenceID =
                    codegenReal2Mission_DW.ReceivePushedMissionCMD.SequenceID;
            }

            rtb_SndCMD = rtb_ThisCMD;
            printf("Reset flight mission, cancle immediate mission!\n");
            fflush(stdout);
        } else if (codegenReal2Mission_DW.MissionCMD.SequenceID ==
                   codegenReal2Mission_DW.ReceivePushedMissionCMD.SequenceID) {
            printf("Use a new Sequence ID for each new mission!\n");
            fflush(stdout);
            printf("PrevCMD SequenceID: %d\n",
                   codegenReal2Mission_DW.MissionCMD.SequenceID);
            fflush(stdout);
            printf("NewCMD SequenceID: %d\n", NewCMD_SequenceID);
            fflush(stdout);
        } else {
            if (static_cast<int32_T>
                    (codegenReal2Mission_DW.ReceivePushedMissionCMD.MissionMode)
                > 127) {
                status = 1;
                rtb_SndCMD.SequenceID = NewCMD_SequenceID;
                rtb_SndCMD.MissionMode = NewCMD_MissionMode;
                rtb_SndCMD.MissionLocation = *NewCMD_MissionLocation;
                rtb_SndCMD.params = *NewCMD_params;
                rtb_SndCMD.StartPosition = *NewCMD_StartPosition;
                rtb_SndCMD.numUAV = NewCMD_numUAV;
                rtb_SndCMD.FormationPos = NewCMD_FormationPos;
                rtb_SndCMD.StartTime = NewCMD_StartTime_tmp;
            } else if (NonDeterministic <= NewCMD_StartTime_tmp) {
                rtb_ThisCMD.SequenceID = NewCMD_SequenceID;
                rtb_ThisCMD.MissionMode = NewCMD_MissionMode;
                rtb_ThisCMD.MissionLocation = *NewCMD_MissionLocation;
                rtb_ThisCMD.params = *NewCMD_params;
                rtb_ThisCMD.StartPosition = *NewCMD_StartPosition;
                rtb_ThisCMD.numUAV = NewCMD_numUAV;
                rtb_ThisCMD.FormationPos = NewCMD_FormationPos;
                rtb_ThisCMD.StartTime = NewCMD_StartTime_tmp;
                rtb_SndCMD.SequenceID = NewCMD_SequenceID;
                rtb_SndCMD.MissionMode = NewCMD_MissionMode;
                rtb_SndCMD.MissionLocation = *NewCMD_MissionLocation;
                rtb_SndCMD.params = *NewCMD_params;
                rtb_SndCMD.StartPosition = *NewCMD_StartPosition;
                rtb_SndCMD.numUAV = NewCMD_numUAV;
                rtb_SndCMD.FormationPos = NewCMD_FormationPos;
                rtb_SndCMD.StartTime = NewCMD_StartTime_tmp;
            } else {
                printf("Mission Start Time has already passed!\n");
                fflush(stdout);
            }

            printf("Start Time:   %04d-%02d-%02d %02d:%02d:%02d.%03d\n", Y, M, D,
                   H, MI, S, MS);
            fflush(stdout);
            codegenReal2Mission_getLocalTime(&NonDeterministic, &c_tm_year_0[5],
                &c_tm_year_0[4], &c_tm_year_0[3], &c_tm_year_0[2], &c_tm_year_0
                [1], &c_tm_year_0[0], &expl_temp);
            c_tm_year_0[6] = NonDeterministic / 1.0E+6;
            thisData = codegenReal2Mission_createFromDateVec(c_tm_year_0);
            codegenReal2Mission_getDateVec(thisData, &NonDeterministic,
                &NewCMD_StartTime_tmp, &c_tm_min, &c_tm_hour, &c_tm_mday,
                &c_tm_mon);
            codegenReal2Mission_getDateVec(thisData, &c_tm_min,
                &NewCMD_StartTime_tmp, &c_tm_hour, &c_tm_mday, &c_tm_mon,
                &c_tm_year);
            codegenReal2Mission_getDateVec(thisData, &c_tm_hour, &c_tm_mday,
                &c_tm_min, &c_tm_mon, &c_tm_year, &a__17);
            codegenReal2Mission_getDateVec(thisData, &c_tm_mday, &c_tm_mon,
                &c_tm_year, &c_tm_hour, &a__17, &a__23);
            codegenReal2Mission_getDateVec(thisData, &c_tm_mon, &c_tm_year,
                &a__17, &a__23, &c_tm_mday, &a__29);
            codegenReal2Mission_getDateVec(thisData, &c_tm_year, &a__17, &a__23,
                &a__29, &a__35, &c_tm_mon);
            codegenReal2Mission_getDateVec(thisData, &a__17, &a__23, &a__29,
                &a__35, &b_a__35, &c_tm_year);
            codegenReal2Mission_getDateVec(thisData, &a__17, &a__23, &a__29,
                &a__35, &b_a__35, &c_s);
            printf("Current Time: %04.0f-%02.0f-%02.0f %02.0f:%02.0f:%02.0f.%03.0f\n",
                   NonDeterministic, NewCMD_StartTime_tmp, c_tm_min, c_tm_hour,
                   c_tm_mday, std::floor(c_tm_mon), std::round(1000.0 *
                    (c_tm_year - std::floor(c_s))));
            fflush(stdout);
        }
    }

    codegenReal2Mission_DW.MissionCMD = rtb_ThisCMD;
    if (status > 0) {
        codegenReal2Mission_RcvImmedCMD_SendData(&rtb_SndCMD);
    }

    if (status == 0) {
        codegenReal2Mission_RcvNextMission_SendData(&rtb_SndCMD);
    }

    codegenReal2Mission_ReceiveThisMission_SendData(&rtb_SndCMD);
}

void codegenReal2MissionModelClass::initialize()
{
    rt_InitInfAndNaN(sizeof(real_T));

    {
        {
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

        {
            static RTWLogInfo rt_DataLoggingInfo;
            rt_DataLoggingInfo.loggingInterval = (nullptr);
            (&codegenReal2Mission_M)->rtwLogInfo = &rt_DataLoggingInfo;
        }

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

    FlightMissionMode_initialize(rtmGetErrorStatusPointer
        ((&codegenReal2Mission_M)),
        &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtm));
    MissionUAV_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
                          rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
                          &((&codegenReal2Mission_M)->solverInfo),
                          &(&codegenReal2Mission_M)->timingBridge,
                          &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
                          &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtzce));
    Real2SimGuidance_initialize(rtmGetErrorStatusPointer((&codegenReal2Mission_M)),
        rtmGetStopRequestedPtr((&codegenReal2Mission_M)),
        &((&codegenReal2Mission_M)->solverInfo),
        &(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtm));
    rt_StartDataLoggingWithStartTime((&codegenReal2Mission_M)->rtwLogInfo, 0.0,
        rtmGetTFinal((&codegenReal2Mission_M)), (&codegenReal2Mission_M)
        ->Timing.stepSize0, (&rtmGetErrorStatus((&codegenReal2Mission_M))));

    {
        FILE * a;
        int32_T i;
        codegenReal2Mission_initMemPool
            (&codegenReal2Mission_DW.slMsgMgr_MemPool_missionCmd,
             &codegenReal2Mission_DW.slMsgMgr_memArray_missionCmd[0],
             &codegenReal2Mission_DW.slMsgMgr_freeList_missionCmd[0], 9);
        rtw_pthread_mutex_init
            (&codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
        codegenReal2Mission_PrevZCX.TriggerCurrentMisisonFeedback_Trig_ZCE =
            POS_ZCSIG;
        codegenReal2Mission_PrevZCX.FeedbackMissionCMD_Trig_ZCE = POS_ZCSIG;
        codegenReal2Mission_PrevZCX.TriggerBroadcastAtMissionTime_Trig_ZCE =
            UNINITIALIZED_ZCSIG;
        rtw_pthread_mutex_init(&AltitudeGCS_m0);
        rtw_pthread_mutex_init(&LatitudeGCS_m0);
        rtw_pthread_mutex_init(&LongitudeGCS_m0);
        FlightMissionMode_Init
            (&codegenReal2Mission_DW.PreemptableMissionModeSelector_o2,
             &codegenReal2Mission_DW.PreemptableMissionModeSelector_o3[0],
             &(codegenReal2Mission_DW.PreemptableMissionModeSelector_InstanceData.rtdw));
        MissionUAV_Init
            (&(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtm),
             &(codegenReal2Mission_DW.MissionUavModel_InstanceData.rtdw),
             &(codegenReal2Mission_X.MissionUavModel_CSTATE));
        codegenReal2Mission_DW.SwitchCase_ActiveSubsystem = -1;
        codegenReal2Mission_DW.obj_j.isInitialized = 0;
        codegenReal2Mission_DW.obj_j.isInitialized = 1;
        codegenReal2Mission_DW.obj_j.PrevResetSignal = 0.0;
        codegenReal2Mission_DW.obj_j.OrbitRadiusInternal = (rtNaN);
        codegenReal2Mission_DW.obj_j.NumCircles = 0.0;
        codegenReal2Mission_DW.obj_j.OrbitRadiusInternal = (rtNaN);
        codegenReal2Mission_DW.obj_j.PrevResetSignal *= 0.0;
        codegenReal2Mission_DW.obj_j.NumCircles *= 0.0;
        codegenReal2Mission_DW.obj_j.PrevPosition[0] = 0.0;
        codegenReal2Mission_DW.obj_j.OrbitCenterInternal[0] = (rtNaN);
        codegenReal2Mission_DW.obj_j.OrbitCenterInternal[0] = (rtNaN);
        codegenReal2Mission_DW.obj_j.PrevPosition[0] *= 0.0;
        codegenReal2Mission_DW.obj_j.PrevPosition[1] = 0.0;
        codegenReal2Mission_DW.obj_j.OrbitCenterInternal[1] = (rtNaN);
        codegenReal2Mission_DW.obj_j.OrbitCenterInternal[1] = (rtNaN);
        codegenReal2Mission_DW.obj_j.PrevPosition[1] *= 0.0;
        codegenReal2Mission_DW.obj_j.PrevPosition[2] = 0.0;
        codegenReal2Mission_DW.obj_j.OrbitCenterInternal[2] = (rtNaN);
        codegenReal2Mission_DW.obj_j.OrbitCenterInternal[2] = (rtNaN);
        codegenReal2Mission_DW.obj_j.PrevPosition[2] *= 0.0;
        codegenReal2Mission_DW.obj_j.StartFlag = true;
        codegenReal2Mission_DW.obj_j.SelectTurnDirectionFlag = true;
        codegenReal2Mission_DW.obj_j.TurnDirectionInternal = 1.0;
        codegenReal2Mission_DW.obj_j.OrbitRadiusFlag = 0U;
        codegenReal2Mission_DW.obj_j.LookaheadDistFlag = 0U;
        for (i = 0; i < 360; i++) {
            codegenReal2Mission_DW.HeightSequence_X[i] = -150.0;
        }

        codegenReal2Mission_DW.obj.LastWaypointFlag = false;
        codegenReal2Mission_DW.obj.StartFlag = true;
        codegenReal2Mission_DW.obj.LookaheadFactor = 1.01;
        codegenReal2Mission_DW.obj.SearchFlag = true;
        codegenReal2Mission_DW.obj.isInitialized = 0;
        codegenReal2Mission_DW.obj.CacheInputSizes = false;
        codegenReal2Mission_DW.obj.isInitialized = 1;
        for (i = 0; i < 8; i++) {
            codegenReal2Mission_DW.obj.inputVarSize[0].f1[i] = 1U;
        }

        i = codegenReal2Mission_DW.SFunction_DIMS2[0];
        if (codegenReal2Mission_DW.SFunction_DIMS2[0] < 0) {
            i = 0;
        }

        codegenReal2Mission_DW.obj.inputVarSize[1].f1[0] = static_cast<uint32_T>
            (i);
        i = codegenReal2Mission_DW.SFunction_DIMS2[1];
        if (codegenReal2Mission_DW.SFunction_DIMS2[1] < 0) {
            i = 0;
        }

        codegenReal2Mission_DW.obj.inputVarSize[1].f1[1] = static_cast<uint32_T>
            (i);
        for (i = 0; i < 6; i++) {
            codegenReal2Mission_DW.obj.inputVarSize[1].f1[static_cast<int32_T>(i
                + 2)] = 1U;
        }

        for (i = 0; i < 8; i++) {
            codegenReal2Mission_DW.obj.inputVarSize[2].f1[i] = 1U;
        }

        codegenReal2Mission_DW.obj.WaypointIndex = 1.0;
        for (i = 0; i < 2700; i++) {
            codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);
            codegenReal2Mission_DW.obj.WaypointsInternal[i] = (rtNaN);
        }

        codegenReal2Mission_DW.MergeGuidanceCMD =
            codegenReal2Mission_rtZFixedWingGuidanceBus;
        Real2SimGuidance_Init
            (&(codegenReal2Mission_DW.Real2SimGuidance_InstanceData.rtdw),
             &(codegenReal2Mission_X.Real2SimGuidance_CSTATE));
        a = NULL;
        for (i = 0; i < 20; i++) {
            codegenReal2Mission_DW.eml_openfiles[i] = a;
        }

        rtw_pthread_mutex_lock(AltitudeGCS_m0);
        AltitudeGCS = GCS_Altitude;
        rtw_pthread_mutex_unlock(AltitudeGCS_m0);
        rtw_pthread_mutex_lock(LatitudeGCS_m0);
        LatitudeGCS = GCS_Latitude;
        rtw_pthread_mutex_unlock(LatitudeGCS_m0);
        rtw_pthread_mutex_lock(LongitudeGCS_m0);
        LongitudeGCS = GCS_Longitude;
        rtw_pthread_mutex_unlock(LongitudeGCS_m0);
    }

    if (rtmIsFirstInitCond((&codegenReal2Mission_M))) {
        rtmSetFirstInitCond((&codegenReal2Mission_M), 0);
    }
}

void codegenReal2MissionModelClass::terminate()
{
    rtw_pthread_mutex_destroy(codegenReal2Mission_DW.RateTransition_d0_SEMAPHORE);
    rtw_pthread_mutex_destroy(AltitudeGCS_m0);
    rtw_pthread_mutex_destroy(LatitudeGCS_m0);
    rtw_pthread_mutex_destroy(LongitudeGCS_m0);
}

codegenReal2MissionModelClass::codegenReal2MissionModelClass
    (SendData_IndividualUAVCmdT& CurrentMissionSendData_arg,
     RecvData_IndividualUAVCmdT& MissionCMDRecvData_arg) :
    codegenReal2Mission_DW(),
    codegenReal2Mission_X(),
    codegenReal2Mission_PrevZCX(),
    codegenReal2Mission_U(),
    codegenReal2Mission_Y(),
    codegenReal2Mission_M(),
    CurrentMissionSendData(CurrentMissionSendData_arg),
    MissionCMDRecvData(MissionCMDRecvData_arg)
{
}

codegenReal2MissionModelClass::~codegenReal2MissionModelClass()
{
}

codegenReal2MissionModelClass::RT_MODEL_codegenReal2Mission_T
    * codegenReal2MissionModelClass::getRTM()
{
    return (&codegenReal2Mission_M);
}
