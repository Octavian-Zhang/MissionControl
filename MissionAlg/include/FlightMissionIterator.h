//
// File: FlightMissionIterator.h
//
// Code generated for Simulink model 'FlightMissionIterator'.
//
// Model version                  : 2.17
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 16:53:33 2022
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
#ifndef RTW_HEADER_FlightMissionIterator_h_
#define RTW_HEADER_FlightMissionIterator_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "FlightMissionIterator_types.h"
#include "FlightMissionMode.h"
#include "MissionUAV.h"
#include "MissionModes.h"
#include "rt_zcfcn.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include "zero_crossing_types.h"

// Block signals and states (default storage) for system '<S22>/Coordinate Transformation Conversion' 
struct DW_CoordinateTransformationConversion_FlightMissionIterator_T {
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionIterator_T
        obj;                    // '<S22>/Coordinate Transformation Conversion'
    real_T CoordinateTransformationConversion[9];
                                // '<S22>/Coordinate Transformation Conversion'
    boolean_T objisempty;       // '<S22>/Coordinate Transformation Conversion'
};

// Block signals and states (default storage) for model 'FlightMissionIterator'
struct DW_FlightMissionIterator_f_T {
    DW_CoordinateTransformationConversion_FlightMissionIterator_T
        CoordinateTransformationConversion_i;
                                // '<S22>/Coordinate Transformation Conversion'
    DW_CoordinateTransformationConversion_FlightMissionIterator_T
        CoordinateTransformationConversion;
                                // '<S22>/Coordinate Transformation Conversion'
    MdlrefDW_FlightMissionMode_T PreemptableMissionModeSelector_InstanceData;// '<S2>/PreemptableMissionModeSelector' 
    MdlrefDW_MissionUAV_T MissionUavModel_InstanceData;// '<S6>/MissionUavModel' 
    FixedWingGuidanceBus PreemptableMissionModeSelector_o2;// '<S2>/PreemptableMissionModeSelector' 
    real_T PreemptableMissionModeSelector_o3[8];// '<S2>/PreemptableMissionModeSelector' 
    real_T Delay_DSTATE_f[156];        // '<S2>/Delay'
    real_T DelayInput_DSTATE[2];       // '<S29>/DelayInput'
    real_T DelayOutput_DSTATE[2];      // '<S29>/DelayOutput'
    real_T MemoryPose_PreviousInput[4];// '<S2>/MemoryPose'
    real_T North;
                // '<S1>/BusConversion_InsertedFor_MissionUAVState_at_inport_0'
    real_T East;// '<S1>/BusConversion_InsertedFor_MissionUAVState_at_inport_0'
    real_T Height;
                // '<S1>/BusConversion_InsertedFor_MissionUAVState_at_inport_0'
    real_T AirSpeed;
                // '<S1>/BusConversion_InsertedFor_MissionUAVState_at_inport_0'
    real_T HeadingAngle;
                // '<S1>/BusConversion_InsertedFor_MissionUAVState_at_inport_0'
    real_T FlightPathAngle;
                // '<S1>/BusConversion_InsertedFor_MissionUAVState_at_inport_0'
    real_T RollAngle;
                // '<S1>/BusConversion_InsertedFor_MissionUAVState_at_inport_0'
    real_T RollAngleRate;
                // '<S1>/BusConversion_InsertedFor_MissionUAVState_at_inport_0'
    real_T thisTaskStatus;             // '<S2>/PreemptableMissionModeSelector'
    real_T DiscreteTimeIntegrator;     // '<S2>/Discrete-Time Integrator'
    real_T North_o;                    // '<S2>/MergeControlSwitch'
    real_T East_c;                     // '<S2>/MergeControlSwitch'
    real_T Height_i;                   // '<S2>/MergeControlSwitch'
    real_T AirSpeed_g;                 // '<S2>/MergeControlSwitch'
    real_T HeadingAngle_b;             // '<S2>/MergeControlSwitch'
    real_T FlightPathAngle_i;          // '<S2>/MergeControlSwitch'
    real_T RollAngle_c;                // '<S2>/MergeControlSwitch'
    real_T RollAngleRate_e;            // '<S2>/MergeControlSwitch'
    real_T Omega;                      // '<S17>/Divide'
    real_T CastToDouble;               // '<S6>/Cast To Double'
    real_T North_c;                    // '<S6>/MissionUavModel'
    real_T East_f;                     // '<S6>/MissionUavModel'
    real_T Height_f;                   // '<S6>/MissionUavModel'
    real_T AirSpeed_i;                 // '<S6>/MissionUavModel'
    real_T HeadingAngle_bv;            // '<S6>/MissionUavModel'
    real_T FlightPathAngle_if;         // '<S6>/MissionUavModel'
    real_T RollAngle_a;                // '<S6>/MissionUavModel'
    real_T RollAngleRate_g;            // '<S6>/MissionUavModel'
    real_T Delay_DSTATE;               // '<Root>/Delay'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S2>/Discrete-Time Integrator'
    int32_T DelayInput1_DSTATE;        // '<S24>/Delay Input1'
    MissionModes ImmedMission;         // '<S2>/ShiftModeSelector'
    int8_T SwitchCase_ActiveSubsystem; // '<S2>/Switch Case'
    int8_T DiscreteTimeIntegrator_PrevResetState;// '<S2>/Discrete-Time Integrator' 
    uint8_T is_c19_FlightMissionIterator;// '<S2>/TriggerStartSim'
    uint8_T is_active_c19_FlightMissionIterator;// '<S2>/TriggerStartSim'
    uint8_T is_c8_FlightMissionIterator;// '<S25>/EnableSailShift'
    uint8_T is_active_c8_FlightMissionIterator;// '<S25>/EnableSailShift'
    uint8_T temporalCounter_i1;        // '<S25>/EnableSailShift'
    uint8_T is_c17_FlightMissionIterator;// '<S2>/ShiftModeSelector'
    uint8_T is_active_c17_FlightMissionIterator;// '<S2>/ShiftModeSelector'
    boolean_T DelayInput1_DSTATE_m;    // '<S5>/Delay Input1'
};

// Zero-crossing (trigger) state for model 'FlightMissionIterator'
struct ZCV_FlightMissionIterator_g_T {
    real_T Delay_Reset_ZC;             // '<Root>/Delay'
    real_T DelayInput_Reset_ZC;        // '<S29>/DelayInput'
    real_T DelayOutput_Reset_ZC;       // '<S29>/DelayOutput'
    ZCV_MissionUAV_g_T MissionUavModel_Reset_ZC;// '<S6>/MissionUavModel'
};

// Zero-crossing (trigger) state for model 'FlightMissionIterator'
struct ZCE_FlightMissionIterator_T {
    ZCSigState Delay_Reset_ZCE;        // '<Root>/Delay'
    ZCSigState DelayInput_Reset_ZCE;   // '<S29>/DelayInput'
    ZCSigState DelayOutput_Reset_ZCE;  // '<S29>/DelayOutput'
};

// Real-time Model Data Structure
struct tag_RTM_FlightMissionIterator_T {
    const char_T **errorStatus;
};

struct MdlrefDW_FlightMissionIterator_T {
    DW_FlightMissionIterator_f_T rtdw;
    RT_MODEL_FlightMissionIterator_T rtm;
    ZCE_FlightMissionIterator_T rtzce;
};

// Model reference registration function
extern void FlightMissionIterator_initialize(const char_T **rt_errorStatus,
    RT_MODEL_FlightMissionIterator_T *const FlightMissionIterator_M,
    DW_FlightMissionIterator_f_T *localDW, ZCE_FlightMissionIterator_T *localZCE);
extern void FlightMissionIterator_CoordinateTransformationConversion_Init
    (DW_CoordinateTransformationConversion_FlightMissionIterator_T *localDW);
extern void FlightMissionIterator_CoordinateTransformationConversion(const
    real_T rtu_0[3],
    DW_CoordinateTransformationConversion_FlightMissionIterator_T *localDW);
extern void FlightMissionIterator_Init(FixedWingGuidanceStateBus
    *rty_MissionUAVState, DW_FlightMissionIterator_f_T *localDW);
extern void FlightMissionIterator_Disable(DW_FlightMissionIterator_f_T *localDW);
extern void FlightMissionIterator(const boolean_T *rtu_NewMission, const
    missionCmd *rtu_ExecCMDMsg, const real_T *rtu_TgtCallCount, const real_T
    *rtu_ResetCount, FixedWingGuidanceStateBus *rty_MissionUAVState, real_T
    *rty_thisTaskStatus, DW_FlightMissionIterator_f_T *localDW,
    ZCE_FlightMissionIterator_T *localZCE);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Display' : Unused code path elimination
//  Block '<S15>/Front' : Eliminate redundant signal conversion block
//  Block '<S15>/Right' : Eliminate redundant signal conversion block
//  Block '<S20>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S15>/Up' : Eliminate redundant signal conversion block
//  Block '<S22>/East' : Eliminate redundant signal conversion block
//  Block '<S22>/North' : Eliminate redundant signal conversion block
//  Block '<S22>/Up' : Eliminate redundant signal conversion block


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
//  '<Root>' : 'FlightMissionIterator'
//  '<S1>'   : 'FlightMissionIterator/While Iterator Subsystem'
//  '<S2>'   : 'FlightMissionIterator/While Iterator Subsystem/FlightMission'
//  '<S3>'   : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Compare To Constant'
//  '<S4>'   : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Compare To Zero (ID)'
//  '<S5>'   : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Detect Rise Positive'
//  '<S6>'   : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/MissionSimUAV'
//  '<S7>'   : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ'
//  '<S8>'   : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU'
//  '<S9>'   : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/ShiftModeSelector'
//  '<S10>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/SimState2Pose'
//  '<S11>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Switch Case Action Subsystem'
//  '<S12>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/TriggerStartSim'
//  '<S13>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Detect Rise Positive/Positive'
//  '<S14>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ/Mode253_Variant'
//  '<S15>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253'
//  '<S16>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/ConstTurnPred'
//  '<S17>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/DivisionByZeroProtection'
//  '<S18>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Radians to Degrees'
//  '<S19>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Rotation Angles to Direction Cosine Matrix'
//  '<S20>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S21>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant'
//  '<S22>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254'
//  '<S23>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/Degrees to Radians'
//  '<S24>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/Detect Change'
//  '<S25>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance'
//  '<S26>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift'
//  '<S27>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/SailShift'
//  '<S28>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/SailShift/Degrees to Radians'
//  '<S29>'  : 'FlightMissionIterator/While Iterator Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/SailShift/DiscreteIntegrator'

#endif                                 // RTW_HEADER_FlightMissionIterator_h_

//
// File trailer for generated code.
//
// [EOF]
//
