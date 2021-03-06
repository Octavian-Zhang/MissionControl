//
// File: FlightMissionMode.h
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 3.20
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Jul 25 00:05:26 2022
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

// Block signals and states (default storage) for system '<S123>/Waypoint Follower' 
struct DW_WaypointFollower_FlightMissionMode_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T obj;// '<S123>/Waypoint Follower' 
    real_T WaypointFollower_o1[3];     // '<S123>/Waypoint Follower'
    real_T WaypointFollower_o2;        // '<S123>/Waypoint Follower'
    real_T WaypointFollower_o3;        // '<S123>/Waypoint Follower'
    uint8_T WaypointFollower_o4;       // '<S123>/Waypoint Follower'
    uint8_T WaypointFollower_o5;       // '<S123>/Waypoint Follower'
    boolean_T objisempty;              // '<S123>/Waypoint Follower'
};

// Block signals and states (default storage) for system '<S92>/SegmentSwitch'
struct DW_SegmentSwitch_FlightMissionMode_T {
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_e;// '<S123>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_i;// '<S123>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_n;// '<S123>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_k;// '<S123>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower;// '<S123>/Waypoint Follower' 
    real_T MergeStatus;                // '<S96>/MergeStatus'
    real_T Memory_PreviousInput;       // '<S96>/Memory'
    int8_T SwitchCase_ActiveSubsystem; // '<S96>/Switch Case'
    uint8_T is_active_c3_PathPlanning; // '<S96>/Chart'
    uint8_T is_c3_PathPlanning;        // '<S96>/Chart'
    uint8_T is_Running;                // '<S96>/Chart'
    uint8_T temporalCounter_i1;        // '<S96>/Chart'
};

// Block signals and states (default storage) for system '<S97>/StartPointGenerator' 
struct DW_StartPointGenerator_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S97>/StartPointGenerator'
    DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S97>/StartPointGenerator' 
    boolean_T SingletonInstance_not_empty;// '<S97>/StartPointGenerator'
};

// Block signals and states (default storage) for system '<S97>/WayPointGenerator' 
struct DW_WayPointGenerator_FlightMissionMode_T {
    FILE* eml_openfiles[20];           // '<S97>/WayPointGenerator'
    DubinsObjSingleton_FlightMissionMode_b_T SingletonInstance;// '<S97>/WayPointGenerator' 
    boolean_T SingletonInstance_not_empty;// '<S97>/WayPointGenerator'
};

// Block signals and states (default storage) for model 'FlightMissionMode'
struct DW_FlightMissionMode_f_T {
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_f;// '<S139>/WayPointGenerator' 
    DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator_k;// '<S139>/StartPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg_k;// '<S39>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_k;// '<S39>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch_p;// '<S134>/SegmentSwitch' 
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_k;// '<S97>/WayPointGenerator' 
    DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator;// '<S97>/StartPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateUpward;// '<S39>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg;// '<S39>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_m;// '<S39>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch;// '<S92>/SegmentSwitch'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg;// '<S39>/RotateATMissionHdg' 
    FILE* eml_openfiles[20];           // '<S39>/WayPointGenerator'
    FILE* eml_openfiles_n[20];         // '<S182>/WayPointGenerator'
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T obj;// '<S180>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_ccd_T obj_p;// '<S181>/Waypoint Follower' 
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj_k;// '<S35>/Waypoint Follower' 
    uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T obj_f;// '<S10>/Orbit Follower' 
    DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S39>/WayPointGenerator' 
    real_T WayPoint[30720];            // '<S182>/WayPointGenerator'
    real_T ProductFlipStartPose[5];    // '<S139>/ProductFlipStartPose'
    real_T MatrixConcatenateWayPoint[1500];// '<S139>/Matrix Concatenate WayPoint' 
    real_T nedWayPoint[3];             // '<S139>/biasNEDstartpose1'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0[1500];// '<S171>/biasNED'
    real_T MergeLookAheadP[3];         // '<S138>/MergeLookAheadP'
    real_T MatrixConcatenateWayPoint_g[1500];// '<S97>/Matrix Concatenate WayPoint' 
    real_T nedWayPoint_m[3];           // '<S97>/biasNEDstartpose'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0_c[1500];// '<S128>/biasNED' 
    real_T startPose_c[5];             // '<S97>/StartPointGenerator'
    real_T MergeLookAheadP_j[3];       // '<S96>/MergeLookAheadP'
    real_T nedWayPoint_o[24576];       // '<S39>/biasNED'
    real_T Delay_DSTATE[200];          // '<S92>/Delay'
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
    real_T Sum;                        // '<S139>/Sum'
    real_T MergeDesiredCourse;         // '<S138>/MergeDesiredCourse'
    real_T CastToDouble;               // '<S92>/Cast To Double'
    real_T Sum_i;                      // '<S97>/Sum'
    real_T MergeDesiredCourse_p;       // '<S96>/MergeDesiredCourse'
    MissionModes FlightMission;      // '<Root>/PreemptableMissionModeSelector'
    RunWayLineSegment RunWayLineMode;  // '<S138>/Chart'
    RunWayLineSegment RunWayLineMode_k;// '<S96>/Chart'
    int16_T c_data_f[8192];
    int16_T c_data_g[10240];
    int16_T c_data_g1[10240];
    int8_T SwitchCase_ActiveSubsystem; // '<Root>/Switch Case'
    int8_T SwitchCase_ActiveSubsystem_c;// '<S177>/Switch Case'
    uint8_T is_active_c2_FlightMissionMode;
                                     // '<Root>/PreemptableMissionModeSelector'
    uint8_T is_c2_FlightMissionMode; // '<Root>/PreemptableMissionModeSelector'
    boolean_T b[8192];
    boolean_T x[24576];
    boolean_T b_m[10240];
    boolean_T x_n[30720];
    boolean_T b_p[10240];
    boolean_T x_l[30720];
    boolean_T objisempty;              // '<S181>/Waypoint Follower'
    boolean_T objisempty_e;            // '<S180>/Waypoint Follower'
    boolean_T objisempty_n;            // '<S35>/Waypoint Follower'
    boolean_T SingletonInstance_not_empty;// '<S39>/WayPointGenerator'
    boolean_T objisempty_b;            // '<S10>/Orbit Follower'
    boolean_T WayPointGenerator_MODE;  // '<S177>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_m;// '<S134>/WayPointGenerator'
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
//  Block '<S95>/Data Type Duplicate' : Unused code path elimination
//  Block '<S136>/Data Type Duplicate' : Unused code path elimination
//  Block '<S179>/Data Type Duplicate' : Unused code path elimination
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
//  Block '<S134>/Angle' : Eliminate redundant signal conversion block
//  Block '<S134>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S134>/Length' : Eliminate redundant signal conversion block
//  Block '<S134>/SepDis' : Eliminate redundant signal conversion block
//  Block '<S139>/DoubleOneSidePercentage' : Eliminate redundant data type conversion
//  Block '<S139>/Reshape2RowVec' : Reshape block reduction
//  Block '<S177>/FirstOrClosest' : Eliminate redundant signal conversion block
//  Block '<S177>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S177>/PathIDX' : Eliminate redundant signal conversion block
//  Block '<S177>/ShiftWP' : Eliminate redundant signal conversion block


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
//  '<S93>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Compare To Constant'
//  '<S94>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Degrees to Radians'
//  '<S95>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth'
//  '<S96>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch'
//  '<S97>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator'
//  '<S98>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap'
//  '<S99>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0'
//  '<S100>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem'
//  '<S101>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/pos_rad'
//  '<S102>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S103>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S104>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S105>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S106>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S107>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S108>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S109>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S110>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S111>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S112>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S113>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S114>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S115>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S116>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S117>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S118>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S119>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S120>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Bottom'
//  '<S121>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Chart'
//  '<S122>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Initial'
//  '<S123>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Left'
//  '<S124>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Right'
//  '<S125>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Top'
//  '<S126>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/Degrees to Radians'
//  '<S127>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/StartPointGenerator'
//  '<S128>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint'
//  '<S129>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/WayPointGenerator'
//  '<S130>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/biasNEDstartpose'
//  '<S131>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S132>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/minus'
//  '<S133>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant'
//  '<S134>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44'
//  '<S135>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/Degrees to Radians'
//  '<S136>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth'
//  '<S137>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/OneSidePercentage'
//  '<S138>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch'
//  '<S139>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator'
//  '<S140>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap'
//  '<S141>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0'
//  '<S142>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem'
//  '<S143>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/pos_rad'
//  '<S144>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S145>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S146>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S147>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S148>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S149>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S150>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S151>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S152>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S153>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S154>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S155>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S156>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S157>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S158>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S159>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S160>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S161>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S162>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/OneSidePercentage/Degrees to Radians'
//  '<S163>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Bottom'
//  '<S164>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Chart'
//  '<S165>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Initial'
//  '<S166>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Left'
//  '<S167>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Right'
//  '<S168>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/SegmentSwitch/Top'
//  '<S169>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/Degrees to Radians'
//  '<S170>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/StartPointGenerator'
//  '<S171>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint'
//  '<S172>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/WayPointGenerator'
//  '<S173>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/biasNEDstartpose1'
//  '<S174>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S175>' : 'FlightMissionMode/Mode44_ProtLine/Mode44_Variant/Mode44/WayPointGenerator/TransformWayPoint/minus'
//  '<S176>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant'
//  '<S177>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55'
//  '<S178>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/Degrees to Radians'
//  '<S179>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth'
//  '<S180>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/StartFromClosest'
//  '<S181>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/StartFromFirst'
//  '<S182>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator'
//  '<S183>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap'
//  '<S184>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0'
//  '<S185>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem'
//  '<S186>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/pos_rad'
//  '<S187>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S188>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S189>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S190>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S191>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S192>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S193>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S194>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S195>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S196>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S197>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S198>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S199>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S200>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S201>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S202>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S203>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S204>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S205>' : 'FlightMissionMode/Mode55_FrmnWayPoint/Mode55_Variant/Mode55/WayPointGenerator/WayPointGenerator'
//  '<S206>' : 'FlightMissionMode/Mode6_NewRunWay/Mode5_Variant'
//  '<S207>' : 'FlightMissionMode/Mode6_NewRunWay/Mode5_Variant/ModeNull'

#endif                                 // RTW_HEADER_FlightMissionMode_h_

//
// File trailer for generated code.
//
// [EOF]
//
