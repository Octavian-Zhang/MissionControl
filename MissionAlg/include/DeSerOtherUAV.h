//
// File: DeSerOtherUAV.h
//
// Code generated for Simulink model 'DeSerOtherUAV'.
//
// Model version                  : 4.339
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Aug 10 13:58:08 2022
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
#ifndef RTW_HEADER_DeSerOtherUAV_h_
#define RTW_HEADER_DeSerOtherUAV_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include <stddef.h>
#include "DeSerOtherUAV_types.h"

extern "C" {

#include "rt_nonfinite.h"

}
    extern "C"
{

#include "rtGetInf.h"

}

#include <cstring>

extern const real_T DeSerOtherUAV_RGND;// real_T ground

// Class declaration for model DeSerOtherUAV
class DeSerOtherUAV final
{
    // public data and function members
  public:
    // Block signals and states (default storage) for model 'DeSerOtherUAV'
    struct DW_DeSerOtherUAV_T {
        RealUAVStateBus MsgBuff[2];    // '<S1>/MsgBuffDS'
        RealUAVStateBus Receive_o2;    // '<S1>/Receive'
        Buffer_real_T Queue_InsertedFor_ProcessIndivState_at_inport_0_Queue;// synthesized block 
        real_T CatPos[4096];           // '<S1>/Data Store Memory'
        real_T Omega;                  // '<S15>/Divide'
        boolean_T DelayInput1_DSTATE;  // '<S3>/Delay Input1'
        boolean_T WriteBuff_MODE;      // '<S1>/WriteBuff'
        boolean_T ProcessIndivState_MODE;// '<S1>/ProcessIndivState'
    };

    // Real-time Model Data Structure
    struct RT_MODEL_DeSerOtherUAV_T {
        const char_T **errorStatus;
    };

    // model initialize function
    void initialize();

    // Initial conditions function
    void init();

    // Copy Constructor
    DeSerOtherUAV(DeSerOtherUAV const&) = delete;

    // Assignment Operator
    DeSerOtherUAV& operator= (DeSerOtherUAV const&) & = delete;

    // Move Constructor
    DeSerOtherUAV(DeSerOtherUAV &&) = delete;

    // Move Assignment Operator
    DeSerOtherUAV& operator= (DeSerOtherUAV &&) = delete;

    // Real-Time Model get method
    DeSerOtherUAV::RT_MODEL_DeSerOtherUAV_T * getRTM();

    //member function to setup error status pointer
    void setErrorStatusPointer(const char_T **rt_errorStatus);

    // model step function
    void step(const real_T rtu_GCS_LLA[3], real_T rty_AllUAVPos[4096]);

    // Constructor
    DeSerOtherUAV(RecvData_RealUAVStateBusT &OtherUAVstateRecvData_arg);

    // model disable function
    void disable();

    // Destructor
    ~DeSerOtherUAV();

    // private data and function members
  private:
    // Block states
    DW_DeSerOtherUAV_T DeSerOtherUAV_DW;
    RecvData_RealUAVStateBusT &OtherUAVstateRecvData;

    // private member function(s) for subsystem '<Root>/TmpModelReferenceSubsystem'
    Msg_real_T DeSerOtherUAV_createMsg(const real_T *data);
    boolean_T DeSerOtherUAV_push(Buffer_real_T *q, const Msg_real_T *element);
    int32_T DeSerOtherUAV_Receive_SendData(const real_T *data, Buffer_real_T
        *queue);
    boolean_T DeSerOtherUAV_pop(Buffer_real_T *q, Msg_real_T *elementOut);
    int32_T DeSerOtherUAV_Receive_RecvData(real_T *data, Buffer_real_T *queue);

    // Real-Time Model
    RT_MODEL_DeSerOtherUAV_T DeSerOtherUAV_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S24>/Data Type Duplicate' : Unused code path elimination
//  Block '<S19>/Reshape (9) to [3x3] column-major' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'DeSerOtherUAV'
//  '<S1>'   : 'DeSerOtherUAV/While Iterator Serializer'
//  '<S2>'   : 'DeSerOtherUAV/While Iterator Serializer/Compare To Constant'
//  '<S3>'   : 'DeSerOtherUAV/While Iterator Serializer/Detect Fall Nonpositive'
//  '<S4>'   : 'DeSerOtherUAV/While Iterator Serializer/Enabled Subsystem'
//  '<S5>'   : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState'
//  '<S6>'   : 'DeSerOtherUAV/While Iterator Serializer/WriteBuff'
//  '<S7>'   : 'DeSerOtherUAV/While Iterator Serializer/testUniq'
//  '<S8>'   : 'DeSerOtherUAV/While Iterator Serializer/Detect Fall Nonpositive/Nonpositive'
//  '<S9>'   : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem'
//  '<S10>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConcatenateUAVPos'
//  '<S11>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState'
//  '<S12>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED'
//  '<S13>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/PrintNbrID'
//  '<S14>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ReadBuff'
//  '<S15>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/DivisionByZeroProtection'
//  '<S16>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/MATLAB Function'
//  '<S17>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/Radians to Degrees'
//  '<S18>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix'
//  '<S19>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S20>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast'
//  '<S21>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/Degrees to Radians'
//  '<S22>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/Degrees to Radians1'
//  '<S23>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/Degrees to Radians2'
//  '<S24>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth'
//  '<S25>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S26>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S27>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S28>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S29>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S30>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S31>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S32>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S33>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S34>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S35>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S36>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S37>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S38>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S39>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S40>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S41>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S42>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S43>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S44>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S45>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S46>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/OthersLLA2NED/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S47>'  : 'DeSerOtherUAV/While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/PrintNbrID/PrintNbrID'
//  '<S48>'  : 'DeSerOtherUAV/While Iterator Serializer/WriteBuff/WriteBuff'

#endif                                 // RTW_HEADER_DeSerOtherUAV_h_

//
// File trailer for generated code.
//
// [EOF]
//
