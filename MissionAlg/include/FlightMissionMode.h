//
// File: FlightMissionMode.h
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 3.19
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri May 27 23:15:08 2022
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

// Block signals and states (default storage) for system '<S39>/RotateATMissionHdg' 
struct DW_RotateATMissionHdg_FlightMissionMode_T {
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
        obj;                           // '<S39>/RotateATMissionHdg'
    real_T RotateATMissionHdg[9];      // '<S39>/RotateATMissionHdg'
    boolean_T objisempty;              // '<S39>/RotateATMissionHdg'
};

// Block signals and states (default storage) for system '<S122>/Waypoint Follower' 
struct DW_WaypointFollower_FlightMissionMode_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T obj;// '<S122>/Waypoint Follower' 
    real_T WaypointFollower_o1[3];     // '<S122>/Waypoint Follower'
    real_T WaypointFollower_o2;        // '<S122>/Waypoint Follower'
    real_T WaypointFollower_o3;        // '<S122>/Waypoint Follower'
    uint8_T WaypointFollower_o4;       // '<S122>/Waypoint Follower'
    uint8_T WaypointFollower_o5;       // '<S122>/Waypoint Follower'
    boolean_T objisempty;              // '<S122>/Waypoint Follower'
};

// Block signals and states (default storage) for system '<S92>/SegmentSwitch'
struct DW_SegmentSwitch_FlightMissionMode_T {
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_e;// '<S122>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_i;// '<S122>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_n;// '<S122>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_k;// '<S122>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower;// '<S122>/Waypoint Follower' 
    real_T MergeStatus;                // '<S95>/MergeStatus'
    real_T Memory_PreviousInput;       // '<S95>/Memory'
    int8_T SwitchCase_ActiveSubsystem; // '<S95>/Switch Case'
    uint8_T is_active_c3_PathPlanning; // '<S95>/Chart'
    uint8_T is_c3_PathPlanning;        // '<S95>/Chart'
    uint8_T is_Running;                // '<S95>/Chart'
    uint8_T temporalCounter_i1;        // '<S95>/Chart'
};

// Block signals and states (default storage) for system '<S96>/StartPointGenerator' 
struct DW_StartPointGenerator_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S96>/StartPointGenerator'
    DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S96>/StartPointGenerator' 
    boolean_T SingletonInstance_not_empty;// '<S96>/StartPointGenerator'
};

// Block signals and states (default storage) for system '<S96>/WayPointGenerator' 
struct DW_WayPointGenerator_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S96>/WayPointGenerator'
    DubinsObjSingleton_FlightMissionMode_b_T SingletonInstance;// '<S96>/WayPointGenerator' 
    boolean_T SingletonInstance_not_empty;// '<S96>/WayPointGenerator'
};

// Block signals and states (default storage) for model 'FlightMissionMode'
struct DW_FlightMissionMode_f_T {
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_f;// '<S138>/WayPointGenerator' 
    DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator_k;// '<S138>/StartPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg_k;// '<S39>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_k;// '<S39>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch_p;// '<S133>/SegmentSwitch' 
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_k;// '<S96>/WayPointGenerator' 
    DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator;// '<S96>/StartPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateUpward;// '<S39>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg;// '<S39>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_m;// '<S39>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch;// '<S92>/SegmentSwitch'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg;// '<S39>/RotateATMissionHdg' 
    FILE* eml_openfiles[20];           // '<S39>/WayPointGenerator'
    FILE* eml_openfiles_n[20];         // '<S181>/WayPointGenerator'
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T obj;// '<S179>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_ccd_T obj_p;// '<S180>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj_k;// '<S35>/Waypoint Follower' 
    uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T obj_f;// '<S10>/Orbit Follower' 
    DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S39>/WayPointGenerator' 
    real_T WayPoint[30720];            // '<S181>/WayPointGenerator'
    real_T ProductFlipStartPose[5];    // '<S138>/ProductFlipStartPose'
    real_T MatrixConcatenateWayPoint[1500];// '<S138>/Matrix Concatenate WayPoint' 
    real_T nedWayPoint[3];             // '<S138>/biasNEDstartpose1'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0[1500];// '<S170>/biasNED'
    real_T MergeLookAheadP[3];         // '<S137>/MergeLookAheadP'
    real_T MatrixConcatenateWayPoint_g[1500];// '<S96>/Matrix Concatenate WayPoint' 
    real_T nedWayPoint_m[3];           // '<S96>/biasNEDstartpose'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0_c[1500];// '<S127>/biasNED' 
    real_T startPose_c[5];             // '<S96>/StartPointGenerator'
    real_T MergeLookAheadP_j[3];       // '<S95>/MergeLookAheadP'
    real_T nedWayPoint_o[24576];       // '<S39>/biasNED'
    real_T RotateRelPrevPos_DWORK4[9]; // '<S39>/RotateRelPrevPos'
    real_T NED_WP_data[3072];
    real_T MAT[4096];
    real_T o_data[3072];
    real_T q_data[3072];
    real_T paddedWaypts[30720];
    real_T RotateIndivWayPoint_g[24576];// '<S39>/RotateIndivWayPoint'
    real_T WayPoint_p[24576];
    real_T WayPoint_p_m[24576];
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
    real_T Sum;                        // '<S138>/Sum'
    real_T MergeDesiredCourse;         // '<S137>/MergeDesiredCourse'
    real_T Sum_i;                      // '<S96>/Sum'
    real_T MergeDesiredCourse_p;       // '<S95>/MergeDesiredCourse'
    MissionModes FlightMission;      // '<Root>/PreemptableMissionModeSelector'
    RunWayLineSegment RunWayLineMode;  // '<S137>/Chart'
    RunWayLineSegment RunWayLineMode_k;// '<S95>/Chart'
    int16_T c_data_f[8192];
    int16_T c_data_g[10240];
    int16_T c_data_g1[10240];
    int8_T SwitchCase_ActiveSubsystem; // '<Root>/Switch Case'
    int8_T SwitchCase_ActiveSubsystem_c;// '<S176>/Switch Case'
    uint8_T is_active_c2_FlightMissionMode;
                                     // '<Root>/PreemptableMissionModeSelector'
    uint8_T is_c2_FlightMissionMode; // '<Root>/PreemptableMissionModeSelector'
    boolean_T b[8192];
    boolean_T x[24576];
    boolean_T b_m[10240];
    boolean_T x_n[30720];
    boolean_T b_p[10240];
    boolean_T x_l[30720];
    boolean_T objisempty;              // '<S180>/Waypoint Follower'
    boolean_T objisempty_e;            // '<S179>/Waypoint Follower'
    boolean_T objisempty_n;            // '<S35>/Waypoint Follower'
    boolean_T SingletonInstance_not_empty;// '<S39>/WayPointGenerator'
    boolean_T objisempty_b;            // '<S10>/Orbit Follower'
    boolean_T WayPointGenerator_MODE;  // '<S176>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_m;// '<S133>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_k;// '<S92>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_h;// '<S35>/WayPointGenerator'
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
    real_T rtu_1[300], real_T rtu_2, DW_WaypointFollower_FlightMissionMode_T
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
    real_T rtu_Pose[4], const real_T rtu_RawWaypoint[1500], real_T
    rty_LookAheadPoint[3], real_T *rty_DesiredCourse, RunWayLineSegment
    *rty_Status, real_T rtp_LookAheadDis, DW_SegmentSwitch_FlightMissionMode_T
    *localDW);
extern void FlightMissionMode_StartPointGenerator_Init
    (DW_StartPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_StartPointGenerator_Reset
    (DW_StartPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_StartPointGenerator(real_T rtu_Length, real_T
    rtu_RunWayUAV, real_T rtu_PosIDX, real_T rty_initWayPoint[300], real_T
    rty_startPose[5], DW_StartPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_minus(const real_T rtu_uP[300], const real_T
    rtu_uN[3], real_T rty_y[300]);
extern void FlightMissionMode_biasNED(const real_T rtu_MissionNED[3], const
    real_T rtu_IndivRotWP[300], real_T rty_nedWayPoint[300]);
extern void FlightMissionMode_WayPointGenerator_Init
    (DW_WayPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WayPointGenerator_Reset
    (DW_WayPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WayPointGenerator(real_T rtu_Length, real_T
    rty_left[300], real_T rty_top[300], real_T rty_right[300], real_T
    rty_bottom[300], real_T rtp_numSegWP,
    DW_WayPointGenerator_FlightMissionMode_T *localDW);
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
//  Block '<S11>/Data Type Duplicate' : Unused code path elimination
//  Block '<S37>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Duplicate' : Unused code path elimination
//  Block '<S94>/Data Type Duplicate' : Unused code path elimination
//  Block '<S135>/Data Type Duplicate' : Unused code path elimination
//  Block '<S178>/Data Type Duplicate' : Unused code path elimination
//  Block '<S10>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S10>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S10>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S35>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S35>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S35>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S35>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S39>/Reshape' : Reshape block reduction
//  Block '<S92>/AngleStep' : Eliminate redundant signal conversion block
//  Block '<S92>/Length' : Eliminate redundant signal conversion block
//  Block '<S92>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S92>/Radius' : Eliminate redundant signal conversion block
//  Block '<S92>/RunWayID' : Eliminate redundant signal conversion block
//  Block '<S133>/Angle' : Eliminate redundant signal conversion block
//  Block '<S133>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S133>/Length' : Eliminate redundant signal conversion block
//  Block '<S133>/SepDis' : Eliminate redundant signal conversion block
//  Block '<S138>/DoubleOneSidePercentage' : Eliminate redundant data type conversion
//  Block '<S138>/Reshape2RowVec' : Reshape block reduction
//  Block '<S176>/FirstOrClosest' : Eliminate redundant signal conversion block
//  Block '<S176>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S176>/PathIDX' : Eliminate redundant signal conversion block
//  Block '<S176>/ShiftWP' : Eliminate redundant signal conversion block


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
//  '<S7>'   : 'FlightMissionMode/Mode6_NewRunWay'
//  '<S8>'   : 'FlightMissionMode/PreemptableMissionModeSelector'
//  '<S9>'   : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant'
//  '<S10>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1'
//  '<S11>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth'
//  '<S12>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap'
//  '<S13>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S14>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem'
//  '<S15>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/pos_rad'
//  '<S16>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S17>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S18>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S19>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S20>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S21>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S22>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S23>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S24>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S25>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S26>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S27>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S28>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S29>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S30>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S31>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S32>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S33>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S34>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant'
//  '<S35>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2'
//  '<S36>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/Degrees to Radians'
//  '<S37>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth'
//  '<S38>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC'
//  '<S39>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator'
//  '<S40>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap'
//  '<S41>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0'
//  '<S42>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem'
//  '<S43>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/pos_rad'
//  '<S44>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S45>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S46>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S47>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S48>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S49>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S50>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S51>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S52>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S53>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S54>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S55>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S56>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S57>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S58>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S59>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S60>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S61>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S62>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroAlt'
//  '<S63>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroLat'
//  '<S64>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroLon'
//  '<S65>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth'
//  '<S66>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap'
//  '<S67>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S68>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem'
//  '<S69>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/pos_rad'
//  '<S70>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S71>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S72>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S73>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S74>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S75>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S76>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S77>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S78>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S79>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S80>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S81>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S82>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S83>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S84>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S85>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S86>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S87>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S88>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator/WayPointGenerator'
//  '<S89>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator/biasNED'
//  '<S90>'  : 'FlightMissionMode/Mode2_HorzScanNav/Mode2_Variant/Mode2/WayPointGenerator/biasWayPoint'
//  '<S91>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant'
//  '<S92>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3'
//  '<S93>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Degrees to Radians'
//  '<S94>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth'
//  '<S95>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch'
//  '<S96>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator'
//  '<S97>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap'
//  '<S98>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0'
//  '<S99>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem'
//  '<S100>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/pos_rad'
//  '<S101>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S102>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S103>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S104>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S105>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S106>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S107>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S108>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S109>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S110>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S111>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S112>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S113>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S114>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S115>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S116>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S117>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S118>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S119>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Bottom'
//  '<S120>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Chart'
//  '<S121>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Initial'
//  '<S122>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Left'
//  '<S123>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Right'
//  '<S124>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Top'
//  '<S125>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/Degrees to Radians'
//  '<S126>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/StartPointGenerator'
//  '<S127>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint'
//  '<S128>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/WayPointGenerator'
//  '<S129>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/biasNEDstartpose'
//  '<S130>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S131>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/minus'
//  '<S132>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant'
//  '<S133>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44'
//  '<S134>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Degrees to Radians'
//  '<S135>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth'
//  '<S136>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/OneSidePercentage'
//  '<S137>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch'
//  '<S138>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator'
//  '<S139>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap'
//  '<S140>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0'
//  '<S141>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem'
//  '<S142>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/pos_rad'
//  '<S143>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S144>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S145>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S146>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S147>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S148>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S149>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S150>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S151>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S152>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S153>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S154>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S155>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S156>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S157>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S158>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S159>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S160>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S161>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/OneSidePercentage/Degrees to Radians'
//  '<S162>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Bottom'
//  '<S163>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Chart'
//  '<S164>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Initial'
//  '<S165>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Left'
//  '<S166>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Right'
//  '<S167>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Top'
//  '<S168>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/Degrees to Radians'
//  '<S169>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/StartPointGenerator'
//  '<S170>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint'
//  '<S171>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/WayPointGenerator'
//  '<S172>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/biasNEDstartpose1'
//  '<S173>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S174>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint/minus'
//  '<S175>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant'
//  '<S176>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55'
//  '<S177>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Degrees to Radians'
//  '<S178>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth'
//  '<S179>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/StartFromClosest'
//  '<S180>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/StartFromFirst'
//  '<S181>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator'
//  '<S182>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap'
//  '<S183>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0'
//  '<S184>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem'
//  '<S185>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/pos_rad'
//  '<S186>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S187>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S188>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S189>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S190>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S191>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S192>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S193>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S194>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S195>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S196>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S197>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S198>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S199>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S200>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S201>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S202>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S203>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S204>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator/WayPointGenerator'
//  '<S205>' : 'FlightMissionMode/Mode6_NewRunWay/Mode5_Variant'
//  '<S206>' : 'FlightMissionMode/Mode6_NewRunWay/Mode5_Variant/ModeNull'

#endif                                 // RTW_HEADER_FlightMissionMode_h_

//
// File trailer for generated code.
//
// [EOF]
//
