//
// File: FlightMissionMode.h
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 2.62
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Mon Mar 21 01:08:16 2022
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
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "uavdubinscodegen_connection_api.hpp"
#include "FlightMissionMode_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Block signals and states (default storage) for system '<S36>/Orbit Follower'
struct DW_OrbitFollower_FlightMissionMode_T {
    uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T obj;// '<S36>/Orbit Follower' 
    real_T OrbitFollower_o1[3];        // '<S36>/Orbit Follower'
    real_T OrbitFollower_o2;           // '<S36>/Orbit Follower'
    real_T OrbitFollower_o6;           // '<S36>/Orbit Follower'
    boolean_T objisempty;              // '<S36>/Orbit Follower'
};

// Block signals and states (default storage) for system '<S122>/RotateATMissionHdg' 
struct DW_RotateATMissionHdg_FlightMissionMode_T {
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
        obj;                           // '<S122>/RotateATMissionHdg'
    real_T RotateATMissionHdg[9];      // '<S122>/RotateATMissionHdg'
    boolean_T objisempty;              // '<S122>/RotateATMissionHdg'
};

// Block signals and states (default storage) for system '<S122>/biasNED'
struct DW_biasNED_FlightMissionMode_T {
    real_T b[30720];
};

// Block signals and states (default storage) for system '<S118>/Waypoint Follower' 
struct DW_WaypointFollower_FlightMissionMode_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T obj;// '<S118>/Waypoint Follower' 
    real_T WaypointFollower_o1[3];     // '<S118>/Waypoint Follower'
    real_T paddedWaypts[30720];
    real_T WaypointFollower_o2;        // '<S118>/Waypoint Follower'
    int16_T c_data[10240];
    uint8_T WaypointFollower_o5;       // '<S118>/Waypoint Follower'
    boolean_T b[10240];
    boolean_T x[30720];
    boolean_T objisempty;              // '<S118>/Waypoint Follower'
};

// Block signals and states (default storage) for system '<S205>/Waypoint Follower' 
struct DW_WaypointFollower_FlightMissionMode_l_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_f_T obj;// '<S205>/Waypoint Follower' 
    real_T WaypointFollower_o1[3];     // '<S205>/Waypoint Follower'
    real_T WaypointFollower_o2;        // '<S205>/Waypoint Follower'
    real_T WaypointFollower_o3;        // '<S205>/Waypoint Follower'
    uint8_T WaypointFollower_o4;       // '<S205>/Waypoint Follower'
    uint8_T WaypointFollower_o5;       // '<S205>/Waypoint Follower'
    boolean_T objisempty;              // '<S205>/Waypoint Follower'
};

// Block signals and states (default storage) for system '<S175>/SegmentSwitch'
struct DW_SegmentSwitch_FlightMissionMode_T {
    DW_WaypointFollower_FlightMissionMode_l_T WaypointFollower_e;// '<S205>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_l_T WaypointFollower_i;// '<S205>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_l_T WaypointFollower_n;// '<S205>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_l_T WaypointFollower_k;// '<S205>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_l_T WaypointFollower;// '<S205>/Waypoint Follower' 
    real_T MergeStatus;                // '<S178>/MergeStatus'
    real_T Memory_PreviousInput;       // '<S178>/Memory'
    int8_T SwitchCase_ActiveSubsystem; // '<S178>/Switch Case'
    uint8_T is_active_c3_PathPlanning; // '<S178>/Chart'
    uint8_T is_c3_PathPlanning;        // '<S178>/Chart'
    uint8_T is_Running;                // '<S178>/Chart'
    uint8_T temporalCounter_i1;        // '<S178>/Chart'
};

// Block signals and states (default storage) for model 'FlightMissionMode'
struct DW_FlightMissionMode_f_T {
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_dd;// '<S118>/Waypoint Follower' 
    DW_biasNED_FlightMissionMode_T sf_biasNED_i;// '<S283>/biasNED'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateUpward_d;// '<S122>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_dd;// '<S122>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg_k;// '<S122>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_k;// '<S122>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch_p;// '<S216>/SegmentSwitch' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateUpward;// '<S122>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg;// '<S122>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_m;// '<S122>/RotateATMissionHdg' 
    DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch;// '<S175>/SegmentSwitch' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_d;// '<S118>/Waypoint Follower' 
    DW_biasNED_FlightMissionMode_T sf_biasNED1;// '<S65>/biasNED1'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_d;// '<S122>/RotateATMissionHdg' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower;// '<S118>/Waypoint Follower' 
    DW_biasNED_FlightMissionMode_T sf_biasNED;// '<S122>/biasNED'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg;// '<S122>/RotateATMissionHdg' 
    DW_OrbitFollower_FlightMissionMode_T OrbitFollower_l;// '<S36>/Orbit Follower' 
    DW_OrbitFollower_FlightMissionMode_T OrbitFollower;// '<S36>/Orbit Follower' 
    emxArray_uavDubinsPathSegment_1_FlightMissionMode_T pathSegment0;
    cell_wrap_2_FlightMissionMode_T motionType1List[500];
    cell_wrap_2_FlightMissionMode_T motionType2List[500];
    real_T nedWayPoint[3];             // '<S260>/biasNEDstartpose'
    real_T startPose[5];               // '<S260>/WayPointGenerator'
    real_T nedWayPoint_a[30720];       // '<S283>/biasNED'
    real_T ProductFlipStartPose[5];    // '<S220>/ProductFlipStartPose'
    real_T nedWayPoint_b[3];           // '<S220>/biasNEDstartpose1'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0[1500];// '<S251>/biasNED'
    real_T MergeLookAheadP[3];         // '<S219>/MergeLookAheadP'
    real_T nedWayPoint_m[3];           // '<S179>/biasNEDstartpose'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0_c[1500];// '<S210>/biasNED' 
    real_T startPose_o[5];             // '<S179>/StartPointGenerator'
    real_T MergeLookAheadP_j[3];       // '<S178>/MergeLookAheadP'
    real_T nedWayPoint_e[30720];       // '<S65>/biasNED1'
    real_T nedWayPoint_l[30720];       // '<S122>/biasNED'
    real_T RotateRelPrevPos_DWORK4[9]; // '<S65>/RotateRelPrevPos'
    real_T RotateRelPrevPos_DWORK4_d[9];// '<S122>/RotateRelPrevPos'
    real_T WayPoint0[61440];
    real_T MatrixConcatenateWayPoint_g[1500];// '<S179>/Matrix Concatenate WayPoint' 
    real_T WayPoint_i[30720];          // '<S122>/WayPointGenerator'
    real_T RotateIndivWayPoint_g[30720];// '<S122>/RotateIndivWayPoint'
    real_T rtb_WayPoint_i_m[30720];
    real_T Sum;                        // '<S260>/Sum'
    real_T Sum_e;                      // '<S220>/Sum'
    real_T MergeDesiredCourse;         // '<S219>/MergeDesiredCourse'
    real_T Sum_i;                      // '<S179>/Sum'
    real_T MergeDesiredCourse_p;       // '<S178>/MergeDesiredCourse'
    MissionModes FlightMission;      // '<Root>/PreemptableMissionModeSelector'
    RunWayLineSegment RunWayLineMode;  // '<S219>/Chart'
    RunWayLineSegment RunWayLineMode_n;// '<S178>/Chart'
    int8_T SwitchCase_ActiveSubsystem; // '<Root>/Switch Case'
    uint8_T is_active_c2_FlightMissionMode;
                                     // '<Root>/PreemptableMissionModeSelector'
    uint8_T is_GuidanceLogic;        // '<Root>/PreemptableMissionModeSelector'
    boolean_T WayPointGenerator_MODE;  // '<S257>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_m;// '<S216>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_k;// '<S175>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_d;// '<S61>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_h;// '<S118>/WayPointGenerator'
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
extern void FlightMissionMode_OrbitFollower_Init
    (DW_OrbitFollower_FlightMissionMode_T *localDW);
extern void FlightMissionMode_OrbitFollower_Reset
    (DW_OrbitFollower_FlightMissionMode_T *localDW);
extern void FlightMissionMode_OrbitFollower(const real_T rtu_0[4], const real_T
    rtu_1[3], real_T rtu_2, real_T rtu_3, real_T rtu_4,
    DW_OrbitFollower_FlightMissionMode_T *localDW);
extern void FlightMissionMode_RotateATMissionHdg_Init
    (DW_RotateATMissionHdg_FlightMissionMode_T *localDW);
extern void FlightMissionMode_RotateATMissionHdg(const real_T rtu_0[3],
    DW_RotateATMissionHdg_FlightMissionMode_T *localDW);
extern void FlightMissionMode_biasNED(const real_T rtu_MissionNED[3], const
    real_T rtu_IndivRotWP[30720], real_T rty_nedWayPoint[30720],
    DW_biasNED_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WaypointFollower_Init
    (DW_WaypointFollower_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WaypointFollower_Reset
    (DW_WaypointFollower_FlightMissionMode_T *localDW);
extern void FlightMissionMode_WaypointFollower(const real_T rtu_0[4], const
    real_T rtu_1[30720], real_T rtu_2, DW_WaypointFollower_FlightMissionMode_T
    *localDW);
extern void FlightMissionMode_WaypointFollower_m_Init
    (DW_WaypointFollower_FlightMissionMode_l_T *localDW);
extern void FlightMissionMode_WaypointFollower_j_Reset
    (DW_WaypointFollower_FlightMissionMode_l_T *localDW);
extern void FlightMissionMode_WaypointFollower_e(const real_T rtu_0[4], const
    real_T rtu_1[300], real_T rtu_2, DW_WaypointFollower_FlightMissionMode_l_T
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
extern void FlightMissionMode_StartPointGenerator(real_T rtu_Length, real_T
    rtu_RunWayUAV, real_T rtu_PosIDX, real_T rty_initWayPoint[300], real_T
    rty_startPose[5]);
extern void FlightMissionMode_minus(const real_T rtu_uP[300], const real_T
    rtu_uN[3], real_T rty_y[300]);
extern void FlightMissionMode_biasNED_j(const real_T rtu_MissionNED[3], const
    real_T rtu_IndivRotWP[300], real_T rty_nedWayPoint[300]);
extern void FlightMissionMode_WayPointGenerator(real_T rtu_Length, real_T
    rty_left[300], real_T rty_top[300], real_T rty_right[300], real_T
    rty_bottom[300], real_T rtp_numSegWP);
extern void FlightMissionMode_biasNEDstartpose(const real_T rtu_MissionNED[3],
    const real_T rtu_IndivRotWP[3], real_T rty_nedWayPoint[3]);
extern void FlightMissionMode_Init(FixedWingGuidanceBus *rty_GuidanceCmds,
    real_T rty_InitialState[8], DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Reset(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Disable(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Update(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode(const boolean_T *rtu_startFlight, const
    MissionModes *rtu_mode, const Location *rtu_PrevLocation, const Location
    *rtu_Location, const Parameters *rtu_Parameters, const Location
    *rtu_StartPosition, const int32_T *rtu_Reset, const int32_T
    *rtu_FormationIDX, const int32_T *rtu_MissionUAV, const real_T rtu_Pose[4],
    real_T *rty_thisTaskStatus, FixedWingGuidanceBus *rty_GuidanceCmds, real_T
    rty_InitialState[8], DW_FlightMissionMode_f_T *localDW);
extern const FixedWingGuidanceBus FlightMissionMode_rtZFixedWingGuidanceBus;// FixedWingGuidanceBus ground 

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S11>/Right' : Unused code path elimination
//  Block '<S11>/Front' : Eliminate redundant signal conversion block
//  Block '<S11>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S11>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S11>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S11>/Up' : Eliminate redundant signal conversion block
//  Block '<S36>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S36>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S36>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S61>/Front' : Eliminate redundant signal conversion block
//  Block '<S61>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S61>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S61>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S61>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S61>/Right' : Eliminate redundant signal conversion block
//  Block '<S61>/Up' : Eliminate redundant signal conversion block
//  Block '<S65>/Reshape' : Reshape block reduction
//  Block '<S118>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S118>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S118>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S118>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S122>/Reshape' : Reshape block reduction
//  Block '<S175>/AngleStep' : Eliminate redundant signal conversion block
//  Block '<S175>/Length' : Eliminate redundant signal conversion block
//  Block '<S175>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S175>/Radius' : Eliminate redundant signal conversion block
//  Block '<S175>/RunWayID' : Eliminate redundant signal conversion block
//  Block '<S216>/Angle' : Eliminate redundant signal conversion block
//  Block '<S216>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S216>/Length' : Eliminate redundant signal conversion block
//  Block '<S216>/OneSidePercentage' : Eliminate redundant signal conversion block
//  Block '<S216>/SepDis' : Eliminate redundant signal conversion block
//  Block '<S220>/DoubleOneSidePercentage' : Eliminate redundant data type conversion
//  Block '<S220>/Reshape2RowVec' : Reshape block reduction
//  Block '<S257>/AngleStep' : Eliminate redundant signal conversion block
//  Block '<S257>/Length' : Eliminate redundant signal conversion block
//  Block '<S257>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S257>/Radius' : Eliminate redundant signal conversion block
//  Block '<S260>/DoubleAngleStep' : Eliminate redundant data type conversion


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
//  '<S1>'   : 'FlightMissionMode/Mode11_CircDispNav'
//  '<S2>'   : 'FlightMissionMode/Mode1_CirclingNav'
//  '<S3>'   : 'FlightMissionMode/Mode22_CustomFrmnNav'
//  '<S4>'   : 'FlightMissionMode/Mode255_WaitToStart'
//  '<S5>'   : 'FlightMissionMode/Mode2_HorzFrmnNav'
//  '<S6>'   : 'FlightMissionMode/Mode3_RunWayNav'
//  '<S7>'   : 'FlightMissionMode/Mode4_ProtLine'
//  '<S8>'   : 'FlightMissionMode/Mode5_NewRunWay'
//  '<S9>'   : 'FlightMissionMode/PreemptableMissionModeSelector'
//  '<S10>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant'
//  '<S11>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11'
//  '<S12>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth'
//  '<S13>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap'
//  '<S14>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap LL0'
//  '<S15>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/Subsystem'
//  '<S16>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/pos_rad'
//  '<S17>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S18>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S19>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S20>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S21>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S22>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S23>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S24>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S25>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S26>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S27>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S28>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S29>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S30>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S31>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S32>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S33>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S34>'  : 'FlightMissionMode/Mode11_CircDispNav/Mode11_Variant/Mode11/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S35>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant'
//  '<S36>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1'
//  '<S37>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth'
//  '<S38>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap'
//  '<S39>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S40>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem'
//  '<S41>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/pos_rad'
//  '<S42>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S43>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S44>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S45>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S46>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S47>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S48>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S49>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S50>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S51>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S52>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S53>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S54>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S55>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S56>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S57>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S58>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S59>'  : 'FlightMissionMode/Mode1_CirclingNav/Mode1_Variant/Mode1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S60>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant'
//  '<S61>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22'
//  '<S62>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/Degrees to Radians'
//  '<S63>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth'
//  '<S64>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC'
//  '<S65>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/WayPointGenerator'
//  '<S66>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap'
//  '<S67>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap LL0'
//  '<S68>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/Subsystem'
//  '<S69>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/pos_rad'
//  '<S70>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S71>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S72>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S73>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S74>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S75>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S76>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S77>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S78>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S79>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S80>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S81>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S82>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S83>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S84>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S85>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S86>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S87>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S88>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/IsZeroAlt'
//  '<S89>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/IsZeroLat'
//  '<S90>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/IsZeroLon'
//  '<S91>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth'
//  '<S92>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap'
//  '<S93>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S94>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem'
//  '<S95>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/pos_rad'
//  '<S96>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S97>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S98>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S99>'  : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S100>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S101>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S102>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S103>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S104>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S105>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S106>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S107>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S108>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S109>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S110>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S111>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S112>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S113>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S114>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/WayPointGenerator/WayPointGenerator'
//  '<S115>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/WayPointGenerator/biasNED1'
//  '<S116>' : 'FlightMissionMode/Mode22_CustomFrmnNav/Mode22_Variant/Mode22/WayPointGenerator/biasWayPoint'
//  '<S117>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant'
//  '<S118>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2'
//  '<S119>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/Degrees to Radians'
//  '<S120>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth'
//  '<S121>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC'
//  '<S122>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/WayPointGenerator'
//  '<S123>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap'
//  '<S124>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0'
//  '<S125>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem'
//  '<S126>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/pos_rad'
//  '<S127>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S128>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S129>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S130>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S131>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S132>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S133>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S134>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S135>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S136>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S137>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S138>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S139>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S140>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S141>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S142>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S143>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S144>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S145>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroAlt'
//  '<S146>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroLat'
//  '<S147>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/IsZeroLon'
//  '<S148>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth'
//  '<S149>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap'
//  '<S150>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S151>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem'
//  '<S152>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/pos_rad'
//  '<S153>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S154>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S155>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S156>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S157>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S158>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S159>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S160>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S161>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S162>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S163>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S164>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S165>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S166>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S167>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S168>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S169>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S170>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S171>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/WayPointGenerator/WayPointGenerator'
//  '<S172>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/WayPointGenerator/biasNED'
//  '<S173>' : 'FlightMissionMode/Mode2_HorzFrmnNav/Mode2_Variant/Mode2/WayPointGenerator/biasWayPoint'
//  '<S174>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant'
//  '<S175>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3'
//  '<S176>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Degrees to Radians'
//  '<S177>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth'
//  '<S178>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch'
//  '<S179>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator'
//  '<S180>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap'
//  '<S181>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0'
//  '<S182>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem'
//  '<S183>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/pos_rad'
//  '<S184>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S185>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S186>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S187>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S188>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S189>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S190>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S191>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S192>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S193>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S194>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S195>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S196>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S197>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S198>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S199>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S200>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S201>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S202>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Bottom'
//  '<S203>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Chart'
//  '<S204>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Initial'
//  '<S205>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Left'
//  '<S206>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Right'
//  '<S207>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/SegmentSwitch/Top'
//  '<S208>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/Degrees to Radians'
//  '<S209>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/StartPointGenerator'
//  '<S210>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint'
//  '<S211>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/WayPointGenerator'
//  '<S212>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/biasNEDstartpose'
//  '<S213>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S214>' : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/WayPointGenerator/TransformWayPoint/minus'
//  '<S215>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant'
//  '<S216>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4'
//  '<S217>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/Degrees to Radians'
//  '<S218>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth'
//  '<S219>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/SegmentSwitch'
//  '<S220>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/WayPointGenerator'
//  '<S221>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap'
//  '<S222>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap LL0'
//  '<S223>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/Subsystem'
//  '<S224>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/pos_rad'
//  '<S225>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S226>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S227>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S228>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S229>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S230>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S231>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S232>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S233>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S234>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S235>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S236>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S237>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S238>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S239>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S240>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S241>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S242>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S243>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/SegmentSwitch/Bottom'
//  '<S244>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/SegmentSwitch/Chart'
//  '<S245>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/SegmentSwitch/Initial'
//  '<S246>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/SegmentSwitch/Left'
//  '<S247>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/SegmentSwitch/Right'
//  '<S248>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/SegmentSwitch/Top'
//  '<S249>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/WayPointGenerator/Degrees to Radians'
//  '<S250>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/WayPointGenerator/StartPointGenerator'
//  '<S251>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/WayPointGenerator/TransformWayPoint'
//  '<S252>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/WayPointGenerator/WayPointGenerator'
//  '<S253>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/WayPointGenerator/biasNEDstartpose1'
//  '<S254>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S255>' : 'FlightMissionMode/Mode4_ProtLine/Mode4_Variant/Mode4/WayPointGenerator/TransformWayPoint/minus'
//  '<S256>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant'
//  '<S257>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5'
//  '<S258>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/Degrees to Radians'
//  '<S259>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth'
//  '<S260>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/WayPointGenerator'
//  '<S261>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap'
//  '<S262>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap LL0'
//  '<S263>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/Subsystem'
//  '<S264>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/pos_rad'
//  '<S265>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S266>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S267>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S268>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S269>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S270>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S271>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S272>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S273>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S274>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S275>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S276>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S277>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S278>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S279>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S280>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S281>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S282>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S283>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/WayPointGenerator/TransformWayPoint'
//  '<S284>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/WayPointGenerator/WayPointGenerator'
//  '<S285>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/WayPointGenerator/biasNEDstartpose'
//  '<S286>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S287>' : 'FlightMissionMode/Mode5_NewRunWay/Mode5_Variant/Mode5/WayPointGenerator/TransformWayPoint/minus'

#endif                                 // RTW_HEADER_FlightMissionMode_h_

//
// File trailer for generated code.
//
// [EOF]
//
