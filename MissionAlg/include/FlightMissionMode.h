//
// File: FlightMissionMode.h
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 4.33
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov 21 19:24:11 2022
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
#include "uavdubinscodegen_connection_api.hpp"
#include "FlightMissionMode_types.h"
#include "MissionModes.h"
#include "DatalinkInterface.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

// Block signals and states (default storage) for system '<S40>/RotateATMissionHdg' 
struct DW_RotateATMissionHdg_FlightMissionMode_T {
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
        obj;                           // '<S40>/RotateATMissionHdg'
    real_T RotateATMissionHdg[9];      // '<S40>/RotateATMissionHdg'
    boolean_T objisempty;              // '<S40>/RotateATMissionHdg'
};

// Block signals and states (default storage) for system '<S105>/Waypoint Follower' 
struct DW_WaypointFollower_FlightMissionMode_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T obj;// '<S105>/Waypoint Follower' 
    real_T WaypointFollower_o1[3];     // '<S105>/Waypoint Follower'
    real_T WaypointFollower_o2;        // '<S105>/Waypoint Follower'
    real_T WaypointFollower_o3;        // '<S105>/Waypoint Follower'
    uint8_T WaypointFollower_o4;       // '<S105>/Waypoint Follower'
    uint8_T WaypointFollower_o5;       // '<S105>/Waypoint Follower'
    boolean_T objisempty;              // '<S105>/Waypoint Follower'
};

// Block signals and states (default storage) for system '<S72>/SegmentSwitch'
struct DW_SegmentSwitch_FlightMissionMode_T {
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_e;// '<S105>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_i;// '<S105>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_n;// '<S105>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_k;// '<S105>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower;// '<S105>/Waypoint Follower' 
    real_T MergeStatus;                // '<S76>/MergeStatus'
    real_T Memory_PreviousInput;       // '<S76>/Memory'
    int8_T SwitchCase_ActiveSubsystem; // '<S76>/Switch Case'
    uint8_T is_c3_PathPlanning;        // '<S76>/Chart'
    uint8_T is_Running;                // '<S76>/Chart'
    uint8_T is_active_c3_PathPlanning; // '<S76>/Chart'
    uint8_T temporalCounter_i1;        // '<S76>/Chart'
};

// Block signals and states (default storage) for system '<S77>/StartPointGenerator' 
struct DW_StartPointGenerator_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S77>/StartPointGenerator'
    DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S77>/StartPointGenerator' 
    boolean_T SingletonInstance_not_empty;// '<S77>/StartPointGenerator'
};

// Block signals and states (default storage) for system '<S77>/TransformWayPoint' 
struct DW_CoreSubsys_FlightMissionMode_T {
    real_T MatrixDivide_DWORK4[9];     // '<S110>/Matrix Divide'
};

// Block signals and states (default storage) for system '<S77>/WayPointGenerator' 
struct DW_WayPointGenerator_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S77>/WayPointGenerator'
    DubinsObjSingleton_FlightMissionMode_m_T SingletonInstance;// '<S77>/WayPointGenerator' 
    boolean_T SingletonInstance_not_empty;// '<S77>/WayPointGenerator'
};

// Block signals and states (default storage) for system '<S121>/TransformWayPoint' 
struct DW_CoreSubsys_FlightMissionMode_i_T {
    real_T RotateRunway_DWORK4[9];     // '<S155>/RotateRunway'
    real_T RotateIndivWayPoint_DWORK4[9];// '<S155>/RotateIndivWayPoint'
};

// Block signals and states (default storage) for system '<S163>/ReadHomePoint'
struct DW_ReadHomePoint_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S163>/ReadHomePoint'
    real_T HomePoint[3];               // '<S163>/ReadHomePoint'
    boolean_T HomePoint_not_empty;     // '<S163>/ReadHomePoint'
};

// Block signals and states (default storage) for model 'FlightMissionMode'
struct DW_FlightMissionMode_f_T {
    DW_ReadHomePoint_FlightMissionMode_T sf_ReadHomePoint_kc;// '<S166>/ReadHomePoint' 
    DW_ReadHomePoint_FlightMissionMode_T sf_ReadHomePoint_l;// '<S163>/ReadHomePoint' 
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_f;// '<S121>/WayPointGenerator' 
    DW_CoreSubsys_FlightMissionMode_i_T CoreSubsys_k[5];// '<S121>/TransformWayPoint' 
    DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator_k;// '<S121>/StartPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg_k;// '<S40>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_k;// '<S40>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch_p;// '<S116>/SegmentSwitch' 
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator;// '<S77>/WayPointGenerator' 
    DW_CoreSubsys_FlightMissionMode_T CoreSubsys[5];// '<S77>/TransformWayPoint' 
    DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator;// '<S77>/StartPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateUpward;// '<S40>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg;// '<S40>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_m;// '<S40>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch;// '<S72>/SegmentSwitch'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg;// '<S40>/RotateATMissionHdg' 
    FILE* eml_openfiles[20];           // '<S10>/ReadHomePoint'
    FILE* eml_openfiles_b[20];         // '<S37>/ReadHomePoint'
    FILE* eml_openfiles_k[20];         // '<S40>/CheckPointInterp'
    FILE* eml_openfiles_d[20];         // '<S75>/ReadHomePoint'
    FILE* eml_openfiles_bx[20];        // '<S118>/ReadHomePoint'
    FILE* eml_openfiles_i[20];         // '<S166>/WayPointGenerator'
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T obj_j;// '<S164>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj;// '<S165>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj_k;// '<S36>/Waypoint Follower' 
    uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T obj_f;// '<S9>/Orbit Follower' 
    DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S40>/CheckPointInterp' 
    real_T WayPoint[24576];            // '<S166>/WayPointGenerator'
    real_T MatrixConcatenateWayPoint[1920];// '<S121>/Matrix Concatenate WayPoint' 
    real_T ProductFlipStartPose[5];    // '<S121>/ProductFlipStartPose'
    real_T nedWayPoint[3];             // '<S121>/biasNEDstartpose'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0[1920];// '<S155>/biasNED'
    real_T MergeLookAheadP[3];         // '<S120>/MergeLookAheadP'
    real_T MatrixConcatenateWayPoint_g[1920];// '<S77>/Matrix Concatenate WayPoint' 
    real_T nedWayPoint_j[3];           // '<S77>/biasNEDstartpose'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0_c[1920];// '<S110>/biasNED' 
    real_T startPose_a[5];             // '<S77>/StartPointGenerator'
    real_T MergeLookAheadP_j[3];       // '<S76>/MergeLookAheadP'
    real_T CheckPoints[32768];         // '<S41>/CheckPointGenerator'
    real_T nedWayPoint_o[24576];       // '<S40>/biasNED'
    real_T Delay_DSTATE[24];           // '<S72>/Delay'
    real_T RotateRunwayStartpose_DWORK4[9];// '<S121>/RotateRunwayStartpose'
    real_T RotateIndivWayPointStartpose_DWORK4[9];// '<S121>/RotateIndivWayPointStartpose' 
    real_T HomePoint[3];               // '<S118>/ReadHomePoint'
    real_T MatrixDivide_DWORK4[9];     // '<S77>/Matrix Divide'
    real_T HomePoint_o[3];             // '<S75>/ReadHomePoint'
    real_T MatrixDivide_DWORK4_l[9];   // '<S40>/Matrix Divide'
    real_T HomePoint_m[3];             // '<S37>/ReadHomePoint'
    real_T HomePoint_p[3];             // '<S10>/ReadHomePoint'
    real_T NED_WP_data[3072];
    real_T MAT[4096];
    real_T q_data[3072];
    real_T WayPoint_k[24576];
    real_T WayPoint_k_m[24576];
    real_T llatmp_data[3072];
    real_T lla0tmp_data[3072];
    real_T phi_data[1024];
    real_T lambda_data[1024];
    real_T cosphi_data[1024];
    real_T coslambda_data[1024];
    real_T ecefPosWithENUOrigin_data[3072];
    real_T tmp_data[1024];
    real_T lambda_data_c[1024];
    real_T phi_data_k[1024];
    real_T sinphi_data[1024];
    real_T N_data[1024];
    real_T c_data[1024];
    real_T in2_data[1024];
    real_T in5_data[1024];
    real_T in7_data[1024];
    real_T in1_data[3072];
    real_T in2_data_c[1024];
    real_T in2_data_b[1024];
    real_T in5_data_p[1024];
    real_T in2_data_cv[1024];
    real_T Sum;                        // '<S121>/Sum'
    real_T MergeDesiredCourse;         // '<S120>/MergeDesiredCourse'
    real_T Sum_i;                      // '<S77>/Sum'
    real_T MergeDesiredCourse_p;       // '<S76>/MergeDesiredCourse'
    real_T ProductEast;                // '<S41>/ProductEast'
    real_T ProductNorth;               // '<S41>/ProductNorth'
    MissionModes FlightMission;      // '<Root>/PreemptableMissionModeSelector'
    RunWayLineSegment RunWayLineMode;  // '<S120>/Chart'
    RunWayLineSegment RunWayLineMode_o;// '<S76>/Chart'
    int16_T d_data[8192];
    int16_T b_data[8192];
    int8_T SwitchCase_ActiveSubsystem; // '<Root>/Switch Case'
    int8_T SwitchCase_ActiveSubsystem_c;// '<S161>/Switch Case'
    uint8_T is_c2_FlightMissionMode; // '<Root>/PreemptableMissionModeSelector'
    uint8_T is_active_c2_FlightMissionMode;
                                     // '<Root>/PreemptableMissionModeSelector'
    boolean_T x[32768];
    boolean_T distinctWptsIdx[8192];
    boolean_T y[8191];
    boolean_T x_f[24573];
    boolean_T objisempty;              // '<S165>/Waypoint Follower'
    boolean_T objisempty_e;            // '<S164>/Waypoint Follower'
    boolean_T HomePoint_not_empty;     // '<S118>/ReadHomePoint'
    boolean_T HomePoint_not_empty_o;   // '<S75>/ReadHomePoint'
    boolean_T objisempty_n;            // '<S36>/Waypoint Follower'
    boolean_T SingletonInstance_not_empty;// '<S40>/CheckPointInterp'
    boolean_T HomePoint_not_empty_g;   // '<S37>/ReadHomePoint'
    boolean_T objisempty_b;            // '<S9>/Orbit Follower'
    boolean_T HomePoint_not_empty_l;   // '<S10>/ReadHomePoint'
    boolean_T WayPointGenerator_MODE;  // '<S161>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_m;// '<S116>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_k;// '<S72>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_h;// '<S36>/WayPointGenerator'
    boolean_T WayPoint_MODE;           // '<S36>/WayPoint'
};

// Real-time Model Data Structure
struct tag_RTM_FlightMissionMode_T {
    const char_T **errorStatus;
};

struct MdlrefDW_FlightMissionMode_T {
    DW_FlightMissionMode_f_T rtdw;
    RT_MODEL_FlightMissionMode_T rtm;
};

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
extern void FlightMissionMode_SegmentSwitch(const boolean_T *rtu_Reset, const
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
extern void FlightMissionMode_ReadHomePoint_Init
    (DW_ReadHomePoint_FlightMissionMode_T *localDW);
extern void FlightMissionMode_ReadHomePoint_Reset
    (DW_ReadHomePoint_FlightMissionMode_T *localDW);
extern void FlightMissionMode_ReadHomePoint(real_T rty_LLA0[3],
    DW_ReadHomePoint_FlightMissionMode_T *localDW);
extern void FlightMissionMode_Init(FixedWingGuidanceBus *rty_GuidanceCmds,
    real_T rty_InitialState[8], DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Disable(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode(const boolean_T *rtu_startFlight, const
    MissionModes *rtu_mode, const boolean_T *rtu_Reset, const Location
    *rtu_StartLocation, const Location *rtu_MissionLocation, const Parameters
    *rtu_Parameters, const int32_T *rtu_FormationIDX, const int32_T
    *rtu_MissionUAV, const real_T rtu_Pose[4], real_T *rty_thisTaskStatus,
    FixedWingGuidanceBus *rty_GuidanceCmds, real_T rty_InitialState[8],
    DW_FlightMissionMode_f_T *localDW);
extern const FixedWingGuidanceBus FlightMissionMode_rtZFixedWingGuidanceBus;// FixedWingGuidanceBus ground 

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S11>/Data Type Duplicate' : Unused code path elimination
//  Block '<S42>/Data Type Duplicate' : Unused code path elimination
//  Block '<S78>/Data Type Duplicate' : Unused code path elimination
//  Block '<S122>/Data Type Duplicate' : Unused code path elimination
//  Block '<S167>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S9>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S9>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S36>/Down' : Eliminate redundant signal conversion block
//  Block '<S36>/East' : Eliminate redundant signal conversion block
//  Block '<S36>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S36>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S36>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S36>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S36>/North' : Eliminate redundant signal conversion block
//  Block '<S40>/ReshapeRelNED' : Reshape block reduction
//  Block '<S72>/AngleStep' : Eliminate redundant signal conversion block
//  Block '<S72>/Length' : Eliminate redundant signal conversion block
//  Block '<S72>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S72>/Radius' : Eliminate redundant signal conversion block
//  Block '<S72>/RunWayID' : Eliminate redundant signal conversion block
//  Block '<S116>/Angle' : Eliminate redundant signal conversion block
//  Block '<S116>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S116>/Length' : Eliminate redundant signal conversion block
//  Block '<S116>/SepDis' : Eliminate redundant signal conversion block
//  Block '<S121>/DoubleOneSidePercentage' : Eliminate redundant data type conversion
//  Block '<S121>/Reshape2RowVec' : Reshape block reduction
//  Block '<S161>/FirstOrClosest' : Eliminate redundant signal conversion block
//  Block '<S161>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S161>/PathIDX' : Eliminate redundant signal conversion block
//  Block '<S161>/ShiftWP' : Eliminate redundant signal conversion block
//  Block '<S166>/Reshape' : Reshape block reduction


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
//  '<S10>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1'
//  '<S11>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth'
//  '<S12>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/ReadHomePoint'
//  '<S13>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap'
//  '<S14>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S15>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/Subsystem'
//  '<S16>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/pos_rad'
//  '<S17>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S18>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S19>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S20>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S21>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S22>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S23>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S24>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S25>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S26>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S27>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S28>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S29>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S30>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S31>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S32>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S33>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S34>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S35>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant'
//  '<S36>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2'
//  '<S37>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1'
//  '<S38>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/MissionD2R'
//  '<S39>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/StartD2R'
//  '<S40>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPoint'
//  '<S41>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator'
//  '<S42>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth'
//  '<S43>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/ReadHomePoint'
//  '<S44>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap'
//  '<S45>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S46>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/Subsystem'
//  '<S47>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/pos_rad'
//  '<S48>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S49>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S50>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S51>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S52>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S53>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S54>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S55>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S56>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S57>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S58>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S59>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S60>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S61>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S62>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S63>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S64>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S65>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S66>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPoint/CheckPointInterp'
//  '<S67>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPoint/biasNED'
//  '<S68>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPoint/biasWayPoint'
//  '<S69>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator/CheckPointGenerator'
//  '<S70>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator/CompScanWidth'
//  '<S71>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant'
//  '<S72>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3'
//  '<S73>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Compare To Constant'
//  '<S74>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Degrees to Radians'
//  '<S75>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1'
//  '<S76>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch'
//  '<S77>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator'
//  '<S78>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth'
//  '<S79>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/ReadHomePoint'
//  '<S80>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap'
//  '<S81>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S82>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/Subsystem'
//  '<S83>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/pos_rad'
//  '<S84>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S85>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S86>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S87>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S88>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S89>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S90>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S91>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S92>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S93>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S94>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S95>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S96>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S97>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S98>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S99>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S100>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S101>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S102>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Bottom'
//  '<S103>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Chart'
//  '<S104>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Initial'
//  '<S105>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Left'
//  '<S106>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Right'
//  '<S107>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Top'
//  '<S108>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/Degrees to Radians'
//  '<S109>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/StartPointGenerator'
//  '<S110>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint'
//  '<S111>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/WayPointGenerator'
//  '<S112>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/biasNEDstartpose'
//  '<S113>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S114>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/minus'
//  '<S115>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant'
//  '<S116>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44'
//  '<S117>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Degrees to Radians'
//  '<S118>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1'
//  '<S119>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/OneSidePercentage'
//  '<S120>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch'
//  '<S121>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator'
//  '<S122>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth'
//  '<S123>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/ReadHomePoint'
//  '<S124>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap'
//  '<S125>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S126>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/Subsystem'
//  '<S127>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/pos_rad'
//  '<S128>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S129>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S130>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S131>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S132>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S133>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S134>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S135>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S136>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S137>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S138>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S139>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S140>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S141>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S142>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S143>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S144>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S145>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Location2XeHdg1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S146>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/OneSidePercentage/Degrees to Radians'
//  '<S147>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Bottom'
//  '<S148>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Chart'
//  '<S149>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Initial'
//  '<S150>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Left'
//  '<S151>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Right'
//  '<S152>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Top'
//  '<S153>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/Degrees to Radians'
//  '<S154>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/StartPointGenerator'
//  '<S155>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint'
//  '<S156>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/WayPointGenerator'
//  '<S157>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/biasNEDstartpose'
//  '<S158>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S159>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint/minus'
//  '<S160>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant'
//  '<S161>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55'
//  '<S162>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Degrees to Radians'
//  '<S163>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg'
//  '<S164>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/StartFromClosest'
//  '<S165>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/StartFromFirst'
//  '<S166>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator'
//  '<S167>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth'
//  '<S168>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/ReadHomePoint'
//  '<S169>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap'
//  '<S170>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0'
//  '<S171>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/Subsystem'
//  '<S172>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/pos_rad'
//  '<S173>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S174>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S175>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S176>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S177>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S178>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S179>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S180>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S181>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S182>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S183>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S184>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S185>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S186>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S187>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S188>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S189>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S190>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Location2XeHdg/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S191>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator/ReadHomePoint'
//  '<S192>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator/WayPointGenerator'

#endif                                 // RTW_HEADER_FlightMissionMode_h_

//
// File trailer for generated code.
//
// [EOF]
//
