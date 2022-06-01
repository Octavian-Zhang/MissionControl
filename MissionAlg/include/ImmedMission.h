//
// File: ImmedMission.h
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 3.19
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  1 23:05:15 2022
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

extern "C" {

#include "rt_nonfinite.h"

}
    extern "C"
{

#include "rtGetInf.h"

}

#include "rt_zcfcn.h"
#include "zero_crossing_types.h"

// Block signals and states (default storage) for system '<S111>/Altitude'
struct DW_Altitude_ImmedMission_T {
    uav_sluav_internal_system_WaypointFollower_ImmedMission_T obj;// '<S111>/Altitude' 
    real_T Altitude_o1[3];             // '<S111>/Altitude'
    real_T HeadingAngle;               // '<S111>/Altitude'
    uint8_T Altitude_o5;               // '<S111>/Altitude'
    boolean_T objisempty;              // '<S111>/Altitude'
};

// Block signals and states (default storage) for system '<S145>/Coordinate Transformation Conversion' 
struct DW_CoordinateTransformationConversion_ImmedMission_T {
    robotics_slcore_internal_block_CoordinateTransformationConversion_ImmedMission_T
        obj;                   // '<S145>/Coordinate Transformation Conversion'
    real_T CoordinateTransformationConversion[9];
                               // '<S145>/Coordinate Transformation Conversion'
    boolean_T objisempty;      // '<S145>/Coordinate Transformation Conversion'
};

// Block signals and states (default storage) for model 'ImmedMission'
struct DW_ImmedMission_f_T {
    DW_CoordinateTransformationConversion_ImmedMission_T
        CoordinateTransformationConversion_j;
                               // '<S145>/Coordinate Transformation Conversion'
    DW_CoordinateTransformationConversion_ImmedMission_T
        CoordinateTransformationConversion;
                               // '<S145>/Coordinate Transformation Conversion'
    DW_Altitude_ImmedMission_T Heading;// '<S111>/Altitude'
    DW_Altitude_ImmedMission_T Altitude;// '<S111>/Altitude'
    FILE* eml_openfiles[20];           // '<S63>/BaseWayPoint'
    uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T obj;// '<S57>/Waypoint Follower' 
    uav_sluav_internal_system_OrbitFollower_ImmedMission_T obj_c;// '<S23>/Orbit Follower' 
    FixedWingGuidanceStateBus MergeCollAvoidSimUAV;// '<S1>/MergeCollAvoidSimUAV' 
    DubinsObjSingleton_ImmedMission_T SingletonInstance;// '<S63>/BaseWayPoint'
    robotics_slcore_internal_block_CoordinateTransformationConversion_ImmedMission_T
        obj_n;                         // '<S63>/RotateATMissionHdg'
    real_T Product[2];                 // '<S149>/Product'
    real_T DiscreteTimeIntegrator[2];  // '<S149>/Discrete-Time Integrator'
    real_T MatrixConcatenate[6];       // '<S114>/Matrix Concatenate'
    real_T MatrixConcatenate_d[30723]; // '<S63>/Matrix Concatenate'
    real_T Minus[3];                   // '<S63>/Minus'
    real_T nedWayPoint[30720];         // '<S63>/BaseWayPoint'
    real_T DiscreteTimeIntegrator_DSTATE[2];// '<S149>/Discrete-Time Integrator' 
    real_T paddedWaypts[30723];
    real_T CirVec[720];
    real_T a[1092];
    real_T Omega;                      // '<S17>/Divide'
    real_T Omega_g;                    // '<S140>/Divide'
    real_T OrbitNavHdg;                // '<S26>/OrbitNavHdg'
    real_T xSign_prev;                 // '<S57>/TriggerCalibrStart'
    real_T xSign_start;                // '<S57>/TriggerCalibrStart'
    void *MatrixConcatenate_PWORK;     // '<S63>/Matrix Concatenate'
    int32_T MatrixConcatenate_DIMS1[2];// '<S63>/Matrix Concatenate'
    int32_T SFunction_DIMS2_b[2];      // '<S63>/BaseWayPoint'
    int32_T SFunction_DIMS2;           // '<S12>/pdist2'
    MissionModes ImmedMission_a;       // '<S1>/PreemptableMissionModeSelector'
    MissionModes FlightMode_prev;      // '<S1>/PreemptableMissionModeSelector'
    MissionModes FlightMode_start;     // '<S1>/PreemptableMissionModeSelector'
    int16_T j_data[10242];
    int8_T SwitchCase_ActiveSubsystem; // '<S1>/Switch Case'
    uint8_T WaypointFollower_o5;       // '<S57>/Waypoint Follower'
    uint8_T Memory_PreviousInput;      // '<S1>/Memory'
    uint8_T Memory_PreviousInput_j;    // '<Root>/Memory'
    uint8_T is_active_c12_ImmedMission;// '<S147>/EnableSailShift'
    uint8_T is_c12_ImmedMission;       // '<S147>/EnableSailShift'
    uint8_T temporalCounter_i1;        // '<S147>/EnableSailShift'
    uint8_T is_active_c7_ImmedMission; // '<S57>/TriggerCalibrStart'
    uint8_T is_c7_ImmedMission;        // '<S57>/TriggerCalibrStart'
    uint8_T is_active_c1_ImmedMission; // '<S23>/HdgHoldLogic'
    uint8_T is_c1_ImmedMission;        // '<S23>/HdgHoldLogic'
    uint8_T temporalCounter_i1_p;      // '<S23>/HdgHoldLogic'
    uint8_T is_active_c25_ImmedMission;// '<S1>/PreemptableMissionModeSelector'
    uint8_T is_c25_ImmedMission;       // '<S1>/PreemptableMissionModeSelector'
    uint8_T is_ImmedMission;           // '<S1>/PreemptableMissionModeSelector'
    boolean_T i_data[10242];
    boolean_T x_data[30726];
    boolean_T objisempty;              // '<S57>/Waypoint Follower'
    boolean_T objisempty_o;            // '<S63>/RotateATMissionHdg'
    boolean_T SingletonInstance_not_empty;// '<S63>/BaseWayPoint'
    boolean_T objisempty_e;            // '<S23>/Orbit Follower'
    boolean_T SailShift_MODE;          // '<S147>/SailShift'
};

// Zero-crossing (trigger) state for model 'ImmedMission'
struct ZCE_ImmedMission_T {
    ZCSigState WayPointGen_Trig_ZCE;   // '<S111>/WayPointGen'
    ZCSigState WayPointGen_Trig_ZCE_d; // '<S57>/WayPointGen'
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

//
//  Exported States
//
//  Note: Exported states are block states with an exported global
//  storage class designation.  Code generation will declare the memory for these
//  states and exports their symbols.
//

extern real_T AltitudeGCS;             // Simulink.Signal object 'AltitudeGCS'
extern real_T LatitudeGCS;             // Simulink.Signal object 'LatitudeGCS'
extern real_T LongitudeGCS;            // Simulink.Signal object 'LongitudeGCS'

// Model reference registration function
extern void ImmedMission_initialize(const char_T **rt_errorStatus,
    RT_MODEL_ImmedMission_T *const ImmedMission_M);
extern void ImmedMission_Altitude_Init(DW_Altitude_ImmedMission_T *localDW);
extern void ImmedMission_Altitude_Reset(DW_Altitude_ImmedMission_T *localDW);
extern void ImmedMission_Altitude(const real_T rtu_0[4], const real_T rtu_1[6],
    real_T rtu_2, DW_Altitude_ImmedMission_T *localDW);
extern void ImmedMission_CoordinateTransformationConversion_Init
    (DW_CoordinateTransformationConversion_ImmedMission_T *localDW);
extern void ImmedMission_CoordinateTransformationConversion(const real_T rtu_0[3],
    DW_CoordinateTransformationConversion_ImmedMission_T *localDW);
extern void ImmedMission_DivisionByZeroProtection(real_T rtu_HorizSpd, real_T
    rtu_CentripetalAcc, real_T *rty_OmegaRad);
extern void ImmedMission_Init(boolean_T rty_ControlSwitch[2],
    FixedWingGuidanceBus *rty_GuidanceCMD, DW_ImmedMission_f_T *localDW,
    ZCE_ImmedMission_T *localZCE);
extern void ImmedMission_Reset(DW_ImmedMission_f_T *localDW);
extern void ImmedMission_Disable(DW_ImmedMission_f_T *localDW);
extern void ImmedMission_Update(const uint8_T *rtu_RealUAVEngaged,
    DW_ImmedMission_f_T *localDW);
extern void ImmedMission(const FixedWingGuidanceStateBus *rtu_SimUAVstate, const
    missionCmd *rtu_MissionInput, const boolean_T *rtu_NewImmed, const
    RealUAVStateBus *rtu_RealUAVState, const int32_T
    *rtu_FlightMission_SequenceID, const MissionModes
    *rtu_FlightMission_MissionMode, const real_T
    *rtu_FlightMission_MissionLocation_Lat, const real_T
    *rtu_FlightMission_MissionLocation_Lon, const real_T
    *rtu_FlightMission_MissionLocation_Alt, const real_T
    *rtu_FlightMission_MissionLocation_degHDG, const real32_T
    *rtu_FlightMission_params_Param3, const int32_T *rtu_FlightMission_numUAV,
    const int32_T *rtu_FlightMission_FormationPos, const int32_T
    rtu_OtherUAVstate_DIMS1[2], const MissionModes *rtu_FlightMode, real_T
    *rty_TaskStatus, FixedWingGuidanceStateBus *rty_FinalSimUAVState, boolean_T
    rty_ControlSwitch[2], FixedWingGuidanceBus *rty_GuidanceCMD,
    DW_ImmedMission_f_T *localDW, ZCE_ImmedMission_T *localZCE);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S25>/Gain1' : Unused code path elimination
//  Block '<S28>/Data Type Duplicate' : Unused code path elimination
//  Block '<S60>/Data Type Duplicate' : Unused code path elimination
//  Block '<S86>/Data Type Duplicate' : Unused code path elimination
//  Block '<S113>/Data Type Duplicate' : Unused code path elimination
//  Block '<S154>/Data Type Duplicate' : Unused code path elimination
//  Block '<S21>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S23>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S23>/LowerRange' : Eliminate redundant signal conversion block
//  Block '<S23>/UpperRange' : Eliminate redundant signal conversion block
//  Block '<S53>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S57>/Cycles' : Eliminate redundant signal conversion block
//  Block '<S57>/FilletStep' : Eliminate redundant signal conversion block
//  Block '<S57>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S57>/Reshape' : Reshape block reduction
//  Block '<S57>/SideLength' : Eliminate redundant signal conversion block
//  Block '<S138>/Front' : Eliminate redundant signal conversion block
//  Block '<S138>/Right' : Eliminate redundant signal conversion block
//  Block '<S143>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S138>/Up' : Eliminate redundant signal conversion block
//  Block '<S145>/East' : Eliminate redundant signal conversion block
//  Block '<S145>/North' : Eliminate redundant signal conversion block
//  Block '<S145>/Up' : Eliminate redundant signal conversion block


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
//  '<S2>'   : 'ImmedMission/LatLon2NorthEast'
//  '<S3>'   : 'ImmedMission/RealState2Pose'
//  '<S4>'   : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision'
//  '<S5>'   : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp'
//  '<S6>'   : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH'
//  '<S7>'   : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr'
//  '<S8>'   : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack'
//  '<S9>'   : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ'
//  '<S10>'  : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU'
//  '<S11>'  : 'ImmedMission/ImmedMissionGuidance/PreemptableMissionModeSelector'
//  '<S12>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance'
//  '<S13>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/Compare To Zero'
//  '<S14>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState'
//  '<S15>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/SelectState'
//  '<S16>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/pdist2'
//  '<S17>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/DivisionByZeroProtection'
//  '<S18>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/MATLAB Function'
//  '<S19>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Radians to Degrees'
//  '<S20>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix'
//  '<S21>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S22>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant'
//  '<S23>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128'
//  '<S24>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Calculate Range'
//  '<S25>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Degrees to Radians'
//  '<S26>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/FeedthroughHDG'
//  '<S27>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic'
//  '<S28>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth'
//  '<S29>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Turning'
//  '<S30>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap'
//  '<S31>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0'
//  '<S32>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem'
//  '<S33>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/pos_rad'
//  '<S34>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S35>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S36>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S37>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S38>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S39>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S40>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S41>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S42>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S43>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S44>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S45>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S46>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S47>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S48>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S49>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S50>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S51>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S52>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant'
//  '<S53>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130'
//  '<S54>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130/Degrees to Radians'
//  '<S55>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130/RegionalScanMode'
//  '<S56>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant'
//  '<S57>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131'
//  '<S58>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/Cross Product'
//  '<S59>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/Degrees to Radians'
//  '<S60>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth'
//  '<S61>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC'
//  '<S62>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart'
//  '<S63>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/WayPointGen'
//  '<S64>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap'
//  '<S65>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0'
//  '<S66>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem'
//  '<S67>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/pos_rad'
//  '<S68>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S69>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S70>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S71>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S72>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S73>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S74>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S75>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S76>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S77>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S78>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S79>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S80>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S81>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S82>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S83>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S84>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S85>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S86>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth'
//  '<S87>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap'
//  '<S88>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S89>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem'
//  '<S90>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/pos_rad'
//  '<S91>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S92>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S93>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S94>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S95>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S96>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S97>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S98>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S99>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S100>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S101>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S102>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S103>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S104>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S105>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S106>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S107>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S108>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S109>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/WayPointGen/BaseWayPoint'
//  '<S110>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant'
//  '<S111>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132'
//  '<S112>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Calculate Range'
//  '<S113>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth'
//  '<S114>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/WayPointGen'
//  '<S115>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap'
//  '<S116>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0'
//  '<S117>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem'
//  '<S118>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/pos_rad'
//  '<S119>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S120>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S121>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S122>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S123>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S124>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S125>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S126>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S127>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S128>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S129>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S130>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S131>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S132>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S133>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S134>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S135>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S136>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S137>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant'
//  '<S138>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253'
//  '<S139>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/ConstTurnPred'
//  '<S140>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/DivisionByZeroProtection'
//  '<S141>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Radians to Degrees'
//  '<S142>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Rotation Angles to Direction Cosine Matrix'
//  '<S143>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S144>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant'
//  '<S145>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254'
//  '<S146>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/Degrees to Radians'
//  '<S147>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance'
//  '<S148>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift'
//  '<S149>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/SailShift'
//  '<S150>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/SailShift/Degrees to Radians'
//  '<S151>' : 'ImmedMission/LatLon2NorthEast/Degrees to Radians'
//  '<S152>' : 'ImmedMission/LatLon2NorthEast/Degrees to Radians1'
//  '<S153>' : 'ImmedMission/LatLon2NorthEast/Degrees to Radians2'
//  '<S154>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth'
//  '<S155>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S156>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S157>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S158>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S159>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S160>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S161>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S162>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S163>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S164>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S165>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S166>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S167>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S168>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S169>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S170>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S171>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S172>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S173>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S174>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S175>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S176>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'

#endif                                 // RTW_HEADER_ImmedMission_h_

//
// File trailer for generated code.
//
// [EOF]
//
