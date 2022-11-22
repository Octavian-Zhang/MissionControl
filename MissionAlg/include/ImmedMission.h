//
// File: ImmedMission.h
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 4.1
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:16:39 2022
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
#ifndef RTW_HEADER_ImmedMission_h_
#define RTW_HEADER_ImmedMission_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ImmedMission_types.h"
#include "MissionModes.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include "rt_zcfcn.h"
#include "zero_crossing_types.h"

// Block signals and states (default storage) for system '<S55>/Altitude'
struct DW_Altitude_ImmedMission_T {
    uav_sluav_internal_system_WaypointFollower_ImmedMission_T obj;// '<S55>/Altitude' 
    real_T Altitude_o1[3];             // '<S55>/Altitude'
    real_T HeadingAngle;               // '<S55>/Altitude'
    uint8_T Altitude_o5;               // '<S55>/Altitude'
    boolean_T objisempty;              // '<S55>/Altitude'
};

// Block signals and states (default storage) for model 'ImmedMission'
struct DW_ImmedMission_f_T {
    DW_Altitude_ImmedMission_T Heading;// '<S55>/Altitude'
    DW_Altitude_ImmedMission_T Altitude;// '<S55>/Altitude'
    FILE* eml_openfiles[20];           // '<S24>/ReadHomePoint'
    FILE* eml_openfiles_o[20];         // '<S57>/ReadHomePoint'
    uav_sluav_internal_system_OrbitFollower_ImmedMission_T obj;// '<S20>/Orbit Follower' 
    FixedWingGuidanceStateBus MergeCollAvoidSimUAV;// '<S1>/MergeCollAvoidSimUAV' 
    real_T MatrixConcatenate[6];       // '<S58>/Matrix Concatenate'
    real_T HomePoint[3];               // '<S57>/ReadHomePoint'
    real_T HomePoint_l[3];             // '<S24>/ReadHomePoint'
    real_T Out_data[4096];
    real_T Omega;                      // '<S14>/Divide'
    real_T OrbitNavHdg;                // '<S22>/OrbitNavHdg'
    int32_T SFunction_DIMS2[2];        // '<Root>/RemoveNaN'
    int32_T SFunction_DIMS2_g;         // '<S9>/pdist2'
    MissionModes ImmedMission_n;       // '<S1>/PreemptableMissionModeSelector'
    int8_T SwitchCase_ActiveSubsystem; // '<S1>/Switch Case'
    uint8_T Memory_PreviousInput;      // '<Root>/Memory'
    uint8_T is_c1_ImmedMission;        // '<S20>/HdgHoldLogic'
    uint8_T is_active_c1_ImmedMission; // '<S20>/HdgHoldLogic'
    uint8_T temporalCounter_i1;        // '<S20>/HdgHoldLogic'
    uint8_T is_c25_ImmedMission;       // '<S1>/PreemptableMissionModeSelector'
    uint8_T is_active_c25_ImmedMission;// '<S1>/PreemptableMissionModeSelector'
    boolean_T HomePoint_not_empty;     // '<S57>/ReadHomePoint'
    boolean_T objisempty;              // '<S20>/Orbit Follower'
    boolean_T HomePoint_not_empty_p;   // '<S24>/ReadHomePoint'
};

// Zero-crossing (trigger) state for model 'ImmedMission'
struct ZCV_ImmedMission_g_T {
    real_T WayPointGen_Trig_ZC;        // '<S55>/WayPointGen'
};

// Zero-crossing (trigger) state for model 'ImmedMission'
struct ZCE_ImmedMission_T {
    ZCSigState WayPointGen_Trig_ZCE;   // '<S55>/WayPointGen'
};

// Real-time Model Data Structure
struct tag_RTM_ImmedMission_T {
    const char_T **errorStatus;
};

struct MdlrefDW_ImmedMission_T {
    DW_ImmedMission_f_T rtdw;
    RT_MODEL_ImmedMission_T rtm;
    ZCE_ImmedMission_T rtzce;
};

// Model reference registration function
extern void ImmedMission_initialize(const char_T **rt_errorStatus,
    RT_MODEL_ImmedMission_T *const ImmedMission_M);
extern void ImmedMission_Altitude_Init(DW_Altitude_ImmedMission_T *localDW);
extern void ImmedMission_Altitude_Reset(DW_Altitude_ImmedMission_T *localDW);
extern void ImmedMission_Altitude(const real_T rtu_0[4], const real_T rtu_1[6],
    real_T rtu_2, DW_Altitude_ImmedMission_T *localDW);
extern void ImmedMission_Init(boolean_T rty_ControlSwitch[2],
    FixedWingGuidanceBus *rty_GuidanceCMD, DW_ImmedMission_f_T *localDW,
    ZCE_ImmedMission_T *localZCE);
extern void ImmedMission_Disable(DW_ImmedMission_f_T *localDW);
extern void ImmedMission(const FixedWingGuidanceStateBus *rtu_SimUAVstate, const
    missionCmd *rtu_MissionInput, const boolean_T *rtu_NewImmed, const
    FixedWingGuidanceStateBus *rtu_RealUAVState, const MissionModes
    *rtu_FlightMission_MissionMode, const real_T
    *rtu_FlightMission_MissionLocation_degHDG, const real32_T
    *rtu_FlightMission_params_Param3, const int32_T *rtu_FlightMission_numUAV,
    const int32_T *rtu_FlightMission_FormationPos, const real_T
    rtu_OtherUAVstate[4096], const uint8_T *rtu_RealUAVEngaged, const int32_T
    *rtu_SelfID, real_T *rty_TaskState, FixedWingGuidanceStateBus
    *rty_FinalSimUAVState, boolean_T rty_ControlSwitch[2], FixedWingGuidanceBus *
    rty_GuidanceCMD, DW_ImmedMission_f_T *localDW, ZCE_ImmedMission_T *localZCE);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S26>/Data Type Duplicate' : Unused code path elimination
//  Block '<S59>/Data Type Duplicate' : Unused code path elimination
//  Block '<S18>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S20>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S20>/LowerRange' : Eliminate redundant signal conversion block
//  Block '<S20>/UpperRange' : Eliminate redundant signal conversion block


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
//  '<Root>' : 'ImmedMission'
//  '<S1>'   : 'ImmedMission/ImmedMissionGuidance'
//  '<S2>'   : 'ImmedMission/RealState2Pose'
//  '<S3>'   : 'ImmedMission/RemoveNaN'
//  '<S4>'   : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision'
//  '<S5>'   : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp'
//  '<S6>'   : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH'
//  '<S7>'   : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack'
//  '<S8>'   : 'ImmedMission/ImmedMissionGuidance/PreemptableMissionModeSelector'
//  '<S9>'   : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance'
//  '<S10>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/Compare To Zero'
//  '<S11>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState'
//  '<S12>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/SelectState'
//  '<S13>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/pdist2'
//  '<S14>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/DivisionByZeroProtection'
//  '<S15>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/MATLAB Function'
//  '<S16>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Radians to Degrees'
//  '<S17>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix'
//  '<S18>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S19>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant'
//  '<S20>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128'
//  '<S21>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Calculate Range'
//  '<S22>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/FeedthroughHDG'
//  '<S23>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic'
//  '<S24>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg'
//  '<S25>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Turning'
//  '<S26>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth'
//  '<S27>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/ReadHomePoint'
//  '<S28>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap'
//  '<S29>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0'
//  '<S30>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/Subsystem'
//  '<S31>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/pos_rad'
//  '<S32>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S33>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S34>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S35>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S36>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S37>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S38>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S39>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S40>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S41>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S42>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S43>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S44>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S45>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S46>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S47>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S48>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S49>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S50>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant'
//  '<S51>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130'
//  '<S52>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130/Degrees to Radians'
//  '<S53>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130/RegionalScanMode'
//  '<S54>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant'
//  '<S55>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132'
//  '<S56>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Calculate Range'
//  '<S57>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg'
//  '<S58>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/WayPointGen'
//  '<S59>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth'
//  '<S60>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/ReadHomePoint'
//  '<S61>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap'
//  '<S62>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0'
//  '<S63>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/Subsystem'
//  '<S64>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/pos_rad'
//  '<S65>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S66>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S67>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S68>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S69>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S70>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S71>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S72>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S73>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S74>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S75>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S76>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S77>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S78>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S79>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S80>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S81>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S82>'  : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'

#endif                                 // RTW_HEADER_ImmedMission_h_

//
// File trailer for generated code.
//
// [EOF]
//
