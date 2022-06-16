//
// File: FlightMissionMode.h
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 3.25
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jun 16 22:43:06 2022
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
#ifndef RTW_HEADER_FlightMissionMode_h_
#define RTW_HEADER_FlightMissionMode_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "stdio.h"
#include "uavdubinscodegen_connection_api.hpp"
#include "FlightMissionMode_types.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"

extern "C" {

#include "rt_nonfinite.h"

}
    extern "C"
{

#include "rtGetInf.h"

}

// Block signals and states (default storage) for system '<S38>/RotateATMissionHdg' 
struct DW_RotateATMissionHdg_FlightMissionMode_T {
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
        obj;                           // '<S38>/RotateATMissionHdg'
    real_T RotateATMissionHdg[9];      // '<S38>/RotateATMissionHdg'
    boolean_T objisempty;              // '<S38>/RotateATMissionHdg'
};

// Block signals and states (default storage) for system '<S121>/Waypoint Follower' 
struct DW_WaypointFollower_FlightMissionMode_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T obj;// '<S121>/Waypoint Follower' 
    real_T WaypointFollower_o1[3];     // '<S121>/Waypoint Follower'
    real_T WaypointFollower_o2;        // '<S121>/Waypoint Follower'
    real_T WaypointFollower_o3;        // '<S121>/Waypoint Follower'
    uint8_T WaypointFollower_o4;       // '<S121>/Waypoint Follower'
    uint8_T WaypointFollower_o5;       // '<S121>/Waypoint Follower'
    boolean_T objisempty;              // '<S121>/Waypoint Follower'
};

// Block signals and states (default storage) for system '<S91>/SegmentSwitch'
struct DW_SegmentSwitch_FlightMissionMode_T {
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_e;// '<S121>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_i;// '<S121>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_n;// '<S121>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_k;// '<S121>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower;// '<S121>/Waypoint Follower' 
    real_T MergeStatus;                // '<S94>/MergeStatus'
    real_T Memory_PreviousInput;       // '<S94>/Memory'
    int8_T SwitchCase_ActiveSubsystem; // '<S94>/Switch Case'
    uint8_T is_active_c3_PathPlanning; // '<S94>/Chart'
    uint8_T is_c3_PathPlanning;        // '<S94>/Chart'
    uint8_T is_Running;                // '<S94>/Chart'
    uint8_T temporalCounter_i1;        // '<S94>/Chart'
};

// Block signals and states (default storage) for system '<S95>/StartPointGenerator' 
struct DW_StartPointGenerator_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S95>/StartPointGenerator'
    DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S95>/StartPointGenerator' 
    boolean_T SingletonInstance_not_empty;// '<S95>/StartPointGenerator'
};

// Block signals and states (default storage) for system '<S95>/WayPointGenerator' 
struct DW_WayPointGenerator_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S95>/WayPointGenerator'
    DubinsObjSingleton_FlightMissionMode_b_T SingletonInstance;// '<S95>/WayPointGenerator' 
    boolean_T SingletonInstance_not_empty;// '<S95>/WayPointGenerator'
};

// Block signals and states (default storage) for model 'FlightMissionMode'
struct DW_FlightMissionMode_f_T {
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_f;// '<S137>/WayPointGenerator' 
    DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator_k;// '<S137>/StartPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg_k;// '<S38>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_k;// '<S38>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch_p;// '<S132>/SegmentSwitch' 
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_k;// '<S95>/WayPointGenerator' 
    DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator;// '<S95>/StartPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateUpward;// '<S38>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg;// '<S38>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_m;// '<S38>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch;// '<S91>/SegmentSwitch'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg;// '<S38>/RotateATMissionHdg' 
    FILE* eml_openfiles[20];           // '<S38>/WayPointGenerator'
    FILE* eml_openfiles_n[20];         // '<S180>/WayPointGenerator'
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T obj_j;// '<S178>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj;// '<S179>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj_k;// '<S34>/Waypoint Follower' 
    uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T obj_f;// '<S9>/Orbit Follower' 
    DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S38>/WayPointGenerator' 
    real_T WayPoint[24576];            // '<S180>/WayPointGenerator'
    real_T ProductFlipStartPose[5];    // '<S137>/ProductFlipStartPose'
    real_T MatrixConcatenateWayPoint[1920];// '<S137>/Matrix Concatenate WayPoint' 
    real_T nedWayPoint[3];             // '<S137>/biasNEDstartpose1'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0[1920];// '<S169>/biasNED'
    real_T MergeLookAheadP[3];         // '<S136>/MergeLookAheadP'
    real_T MatrixConcatenateWayPoint_g[1920];// '<S95>/Matrix Concatenate WayPoint' 
    real_T nedWayPoint_m[3];           // '<S95>/biasNEDstartpose'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0_c[1920];// '<S126>/biasNED' 
    real_T startPose_c[5];             // '<S95>/StartPointGenerator'
    real_T MergeLookAheadP_j[3];       // '<S94>/MergeLookAheadP'
    real_T nedWayPoint_o[24576];       // '<S38>/biasNED'
    real_T RotateRelPrevPos_DWORK4[9]; // '<S38>/RotateRelPrevPos'
    real_T NED_WP_data[3072];
    real_T MAT[4096];
    real_T o_data[3072];
    real_T q_data[3072];
    real_T RotateIndivWayPoint_g[24576];// '<S38>/RotateIndivWayPoint'
    real_T WayPoint_p[24576];
    real_T WayPoint_p_m[24576];
    real_T paddedWaypts[24576];
    real_T llatmp_data[3072];
    real_T lla0tmp_data[3072];
    real_T cosphi_data[1024];
    real_T sinphi_data[1024];
    real_T coslambda_data[1024];
    real_T ecefPosWithENUOrigin_data[3072];
    real_T tmp_data[1024];
    real_T b_data[1024];
    real_T sinphi_data_c[1024];
    real_T N_data[1024];
    real_T z_data[1024];
    real_T b_data_k[1024];
    real_T c_data[1024];
    real_T in2_data[1024];
    real_T in5_data[1024];
    real_T in7_data[1024];
    real_T in1_data[3072];
    real_T in2_data_c[1024];
    real_T in2_data_b[1024];
    real_T in5_data_p[1024];
    real_T in2_data_cv[1024];
    real_T Sum;                        // '<S137>/Sum'
    real_T MergeDesiredCourse;         // '<S136>/MergeDesiredCourse'
    real_T Sum_i;                      // '<S95>/Sum'
    real_T MergeDesiredCourse_p;       // '<S94>/MergeDesiredCourse'
    MissionModes FlightMission;      // '<Root>/PreemptableMissionModeSelector'
    RunWayLineSegment RunWayLineMode;  // '<S136>/Chart'
    RunWayLineSegment RunWayLineMode_k;// '<S94>/Chart'
    int16_T c_data_f[8192];
    int16_T c_data_g[8192];
    int8_T SwitchCase_ActiveSubsystem; // '<Root>/Switch Case'
    int8_T SwitchCase_ActiveSubsystem_c;// '<S175>/Switch Case'
    uint8_T is_active_c2_FlightMissionMode;
                                     // '<Root>/PreemptableMissionModeSelector'
    uint8_T is_c2_FlightMissionMode; // '<Root>/PreemptableMissionModeSelector'
    boolean_T b[8192];
    boolean_T x[24576];
    boolean_T b_g[8192];
    boolean_T x_m[24576];
    boolean_T objisempty;              // '<S179>/Waypoint Follower'
    boolean_T objisempty_e;            // '<S178>/Waypoint Follower'
    boolean_T objisempty_n;            // '<S34>/Waypoint Follower'
    boolean_T SingletonInstance_not_empty;// '<S38>/WayPointGenerator'
    boolean_T objisempty_b;            // '<S9>/Orbit Follower'
    boolean_T WayPointGenerator_MODE;  // '<S175>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_m;// '<S132>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_k;// '<S91>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_h;// '<S34>/WayPointGenerator'
};

// Real-time Model Data Structure
struct tag_RTM_FlightMissionMode_T {
    const char_T **errorStatus;
};

struct MdlrefDW_FlightMissionMode_T {
    DW_FlightMissionMode_f_T rtdw;
    RT_MODEL_FlightMissionMode_T rtm;
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
extern void FlightMissionMode_initialize(const char_T **rt_errorStatus,
    RT_MODEL_FlightMissionMode_T *const FlightMissionMode_M);
extern void FlightMissionMode_RotateATMissionHdg_Init
    (DW_RotateATMissionHdg_FlightMissionMode_T *localDW);
extern void FlightMissionMode_RotateATMissionHdg(const real_T rtu_0[3],
    DW_RotateATMissionHdg_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WaypointFollower_Init
    (DW_WaypointFollower_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WaypointFollower_Reset
    (DW_WaypointFollower_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WaypointFollower(const real_T rtu_0[4], const
    real_T rtu_1[384], real_T rtu_2, DW_WaypointFollower_FlightMissionMode_T
    *localDW);
extern void FlightMissionMode_SegmentSwitch_Init(real_T rty_LookAheadPoint[3],
    real_T *rty_DesiredCourse, RunWayLineSegment *rty_Status,
    DW_SegmentSwitch_FlightMissionMode_T *localDW);
extern void FlightMissionMode_SegmentSwitch_Reset(RunWayLineSegment *rty_Status,
    DW_SegmentSwitch_FlightMissionMode_T *localDW);
extern void FlightMissionMode_SegmentSwitch_Disable
    (DW_SegmentSwitch_FlightMissionMode_T *localDW);
extern void FlightMissionMode_SegmentSwitch_Update
    (DW_SegmentSwitch_FlightMissionMode_T *localDW);
extern void FlightMissionMode_SegmentSwitch(const int32_T *rtu_Reset, const
    real_T rtu_Pose[4], const real_T rtu_RawWaypoint[1920], real_T
    rty_LookAheadPoint[3], real_T *rty_DesiredCourse, RunWayLineSegment
    *rty_Status, real_T rtp_LookAheadDis, DW_SegmentSwitch_FlightMissionMode_T
    *localDW);
extern void FlightMissionMode_StartPointGenerator_Init
    (DW_StartPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_StartPointGenerator_Reset
    (DW_StartPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_StartPointGenerator(real_T rtu_Length, real_T
    rtu_RunWayUAV, real_T rtu_PosIDX, real_T rty_initWayPoint[384], real_T
    rty_startPose[5], DW_StartPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_minus(const real_T rtu_uP[384], const real_T
    rtu_uN[3], real_T rty_y[384]);
extern void FlightMissionMode_biasNED(const real_T rtu_MissionNED[3], const
    real_T rtu_IndivRotWP[384], real_T rty_nedWayPoint[384]);
extern void FlightMissionMode_WayPointGenerator_Init
    (DW_WayPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WayPointGenerator_Reset
    (DW_WayPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WayPointGenerator(real_T rtu_Length, real_T
    rty_left[384], real_T rty_top[384], real_T rty_right[384], real_T
    rty_bottom[384], DW_WayPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_biasNEDstartpose(const real_T rtu_MissionNED[3],
    const real_T rtu_IndivRotWP[3], real_T rty_nedWayPoint[3]);
extern void FlightMissionMode_Init(FixedWingGuidanceBus *rty_GuidanceCmds,
    real_T rty_InitialState[8], DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Reset(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Disable(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Update(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode(const boolean_T *rtu_startFlight, const
    MissionModes *rtu_mode, const Location *rtu_PrevLocation, const Location
    *rtu_Location, const Parameters *rtu_Parameters, const int32_T *rtu_Reset,
    const int32_T *rtu_FormationIDX, const int32_T *rtu_MissionUAV, const real_T
    rtu_Pose[4], real_T *rty_thisTaskStatus, FixedWingGuidanceBus
    *rty_GuidanceCmds, real_T rty_InitialState[8], DW_FlightMissionMode_f_T
    *localDW);
extern const FixedWingGuidanceBus FlightMissionMode_rtZFixedWingGuidanceBus;// FixedWingGuidanceBus ground 

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S10>/Data Type Duplicate' : Unused code path elimination
//  Block '<S36>/Data Type Duplicate' : Unused code path elimination
//  Block '<S64>/Data Type Duplicate' : Unused code path elimination
//  Block '<S93>/Data Type Duplicate' : Unused code path elimination
//  Block '<S134>/Data Type Duplicate' : Unused code path elimination
//  Block '<S177>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S9>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S9>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S34>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S34>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S34>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S34>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S38>/Reshape' : Reshape block reduction
//  Block '<S91>/AngleStep' : Eliminate redundant signal conversion block
//  Block '<S91>/Length' : Eliminate redundant signal conversion block
//  Block '<S91>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S91>/Radius' : Eliminate redundant signal conversion block
//  Block '<S91>/RunWayID' : Eliminate redundant signal conversion block
//  Block '<S132>/Angle' : Eliminate redundant signal conversion block
//  Block '<S132>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S132>/Length' : Eliminate redundant signal conversion block
//  Block '<S132>/SepDis' : Eliminate redundant signal conversion block
//  Block '<S137>/DoubleOneSidePercentage' : Eliminate redundant data type conversion
//  Block '<S137>/Reshape2RowVec' : Reshape block reduction
//  Block '<S175>/FirstOrClosest' : Eliminate redundant signal conversion block
//  Block '<S175>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S175>/PathIDX' : Eliminate redundant signal conversion block
//  Block '<S175>/ShiftWP' : Eliminate redundant signal conversion block


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
//  '<Root>' : 'FlightMissionMode'
//  '<S1>'   : 'FlightMissionMode/Mode1_CirclingNav'
//  '<S2>'   : 'FlightMissionMode/Mode255_WaitToStart'
//  '<S3>'   : 'FlightMissionMode/Mode2_HorzScanNav'
//  '<S4>'   : 'FlightMissionMode/Mode3_RunWayNav'
//  '<S5>'   : 'FlightMissionMode/Mode44_ProtLine'
//  '<S6>'   : 'FlightMissionMode/Mode55_FrmnWayPoint'
//  '<S7>'   : 'FlightMissionMode/PreemptableMissionModeSelector'
//  '<S8>'   : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant'
//  '<S9>'   : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1'
//  '<S10>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth'
//  '<S11>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap'
//  '<S12>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S13>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem'
//  '<S14>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/pos_rad'
//  '<S15>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S16>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S17>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S18>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S19>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S20>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S21>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S22>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S23>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S24>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S25>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S26>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S27>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S28>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S29>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S30>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S31>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S32>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S33>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant'
//  '<S34>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2'
//  '<S35>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Degrees to Radians'
//  '<S36>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth'
//  '<S37>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC'
//  '<S38>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator'
//  '<S39>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap'
//  '<S40>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0'
//  '<S41>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem'
//  '<S42>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/pos_rad'
//  '<S43>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S44>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S45>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S46>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S47>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S48>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S49>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S50>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S51>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S52>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S53>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S54>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S55>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S56>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S57>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S58>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S59>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S60>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S61>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroAlt'
//  '<S62>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroLat'
//  '<S63>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroLon'
//  '<S64>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth'
//  '<S65>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap'
//  '<S66>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S67>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem'
//  '<S68>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/pos_rad'
//  '<S69>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S70>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S71>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S72>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S73>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S74>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S75>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S76>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S77>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S78>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S79>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S80>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S81>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S82>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S83>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S84>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S85>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S86>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S87>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator/WayPointGenerator'
//  '<S88>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator/biasNED'
//  '<S89>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator/biasWayPoint'
//  '<S90>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant'
//  '<S91>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3'
//  '<S92>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Degrees to Radians'
//  '<S93>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth'
//  '<S94>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch'
//  '<S95>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator'
//  '<S96>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap'
//  '<S97>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0'
//  '<S98>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem'
//  '<S99>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/pos_rad'
//  '<S100>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S101>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S102>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S103>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S104>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S105>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S106>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S107>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S108>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S109>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S110>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S111>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S112>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S113>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S114>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S115>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S116>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S117>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S118>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Bottom'
//  '<S119>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Chart'
//  '<S120>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Initial'
//  '<S121>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Left'
//  '<S122>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Right'
//  '<S123>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Top'
//  '<S124>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/Degrees to Radians'
//  '<S125>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/StartPointGenerator'
//  '<S126>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint'
//  '<S127>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/WayPointGenerator'
//  '<S128>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/biasNEDstartpose'
//  '<S129>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S130>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/minus'
//  '<S131>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant'
//  '<S132>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44'
//  '<S133>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Degrees to Radians'
//  '<S134>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth'
//  '<S135>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/OneSidePercentage'
//  '<S136>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch'
//  '<S137>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator'
//  '<S138>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap'
//  '<S139>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0'
//  '<S140>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem'
//  '<S141>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/pos_rad'
//  '<S142>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S143>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S144>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S145>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S146>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S147>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S148>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S149>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S150>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S151>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S152>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S153>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S154>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S155>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S156>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S157>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S158>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S159>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S160>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/OneSidePercentage/Degrees to Radians'
//  '<S161>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Bottom'
//  '<S162>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Chart'
//  '<S163>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Initial'
//  '<S164>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Left'
//  '<S165>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Right'
//  '<S166>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Top'
//  '<S167>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/Degrees to Radians'
//  '<S168>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/StartPointGenerator'
//  '<S169>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint'
//  '<S170>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/WayPointGenerator'
//  '<S171>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/biasNEDstartpose1'
//  '<S172>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S173>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint/minus'
//  '<S174>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant'
//  '<S175>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55'
//  '<S176>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Degrees to Radians'
//  '<S177>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth'
//  '<S178>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/StartFromClosest'
//  '<S179>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/StartFromFirst'
//  '<S180>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator'
//  '<S181>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap'
//  '<S182>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0'
//  '<S183>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem'
//  '<S184>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/pos_rad'
//  '<S185>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S186>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S187>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S188>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S189>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S190>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S191>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S192>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S193>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S194>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S195>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S196>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S197>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S198>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S199>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S200>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S201>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S202>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S203>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator/WayPointGenerator'

#endif                                 // RTW_HEADER_FlightMissionMode_h_

//
// File trailer for generated code.
//
// [EOF]
//
