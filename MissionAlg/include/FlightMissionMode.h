//
// File: FlightMissionMode.h
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 2.689
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Jul  2 04:30:41 2021
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
#include "rtw_linux.h"
#include "rtGetInf.h"

// Block signals and states (default storage) for system '<S2>/Orbit Follower'
#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

struct DW_OrbitFollower_FlightMissionMode_T {
    uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T obj;// '<S2>/Orbit Follower' 
    real_T OrbitFollower_o1[3];        // '<S2>/Orbit Follower'
    real_T OrbitFollower_o2;           // '<S2>/Orbit Follower'
    real_T OrbitFollower_o6;           // '<S2>/Orbit Follower'
    boolean_T objisempty;              // '<S2>/Orbit Follower'
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

// Block signals and states (default storage) for system '<S109>/RotateATMissionHdg' 
#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

struct DW_RotateATMissionHdg_FlightMissionMode_T {
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
        obj;                           // '<S109>/RotateATMissionHdg'
    real_T RotateATMissionHdg[9];      // '<S109>/RotateATMissionHdg'
    boolean_T objisempty;              // '<S109>/RotateATMissionHdg'
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

// Block signals and states (default storage) for system '<S109>/biasNED'
#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

struct DW_biasNED_FlightMissionMode_T {
    real_T b[30720];
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

// Block signals and states (default storage) for system '<S4>/Waypoint Follower' 
#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

struct DW_WaypointFollower_FlightMissionMode_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T obj;// '<S4>/Waypoint Follower' 
    real_T WaypointFollower_o1[3];     // '<S4>/Waypoint Follower'
    real_T paddedWaypts[30720];
    real_T WaypointFollower_o2;        // '<S4>/Waypoint Follower'
    int16_T c_data[10240];
    uint8_T WaypointFollower_o5;       // '<S4>/Waypoint Follower'
    boolean_T b[10240];
    boolean_T x[30720];
    boolean_T objisempty;              // '<S4>/Waypoint Follower'
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

// Block signals and states (default storage) for system '<S185>/Waypoint Follower' 
#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

struct DW_WaypointFollower_FlightMissionMode_f_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj;// '<S185>/Waypoint Follower' 
    real_T WaypointFollower_o1[3];     // '<S185>/Waypoint Follower'
    real_T WaypointFollower_o2;        // '<S185>/Waypoint Follower'
    real_T WaypointFollower_o3;        // '<S185>/Waypoint Follower'
    uint8_T WaypointFollower_o4;       // '<S185>/Waypoint Follower'
    uint8_T WaypointFollower_o5;       // '<S185>/Waypoint Follower'
    boolean_T objisempty;              // '<S185>/Waypoint Follower'
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

// Block signals and states (default storage) for system '<S161>/WayPointGenerator' 
#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

struct DW_WayPointGenerator_FlightMissionMode_T {
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_T pathSegObj;
    real_T mt_data[784];
    real_T b_fpa_data[784];
    real_T b_a_data[784];
    real_T mtr_data[784];
    real_T h_data[784];
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

// Block signals and states (default storage) for model 'FlightMissionMode'
#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

struct DW_FlightMissionMode_f_T {
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_f;// '<S199>/WayPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg_p;// '<S109>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_pna;// '<S109>/RotateATMissionHdg' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevvfpgh;// '<S185>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevvfpg;// '<S185>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevvfp;// '<S185>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevvf;// '<S185>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevv;// '<S185>/Waypoint Follower' 
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_a;// '<S161>/WayPointGenerator' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg;// '<S109>/RotateATMissionHdg' 
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_pn;// '<S109>/RotateATMissionHdg' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaev;// '<S185>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnae;// '<S185>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pna;// '<S185>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pn;// '<S185>/Waypoint Follower' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_p;// '<S4>/Waypoint Follower' 
    DW_biasNED_FlightMissionMode_T sf_biasNED_f;// '<S57>/biasNED'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_p;// '<S109>/RotateATMissionHdg' 
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower;// '<S4>/Waypoint Follower' 
    DW_biasNED_FlightMissionMode_T sf_biasNED;// '<S109>/biasNED'
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg;// '<S109>/RotateATMissionHdg' 
    DW_OrbitFollower_FlightMissionMode_T OrbitFollower_p;// '<S2>/Orbit Follower' 
    DW_OrbitFollower_FlightMissionMode_T OrbitFollower;// '<S2>/Orbit Follower'
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_T pathSegObj_c;
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_T pathSegObj_k;
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_p_T pathSegObj;
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_p_T pathSegObj_m;
    real_T ProductFlipStartPose[5];    // '<S199>/ProductFlipStartPose'
    real_T nedWayPoint[3];             // '<S199>/biasNEDstartpose'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0[1500];// '<S230>/biasNED'
    real_T MergeLookAheadP[3];         // '<S198>/MergeLookAheadP'
    real_T nedWayPoint_g[3];           // '<S161>/biasNEDstartpose'
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0_l[1200];// '<S191>/biasNED' 
    real_T MergeLookAheadP_k[3];       // '<S160>/MergeLookAheadP'
    real_T nedWayPoint_m[30720];       // '<S57>/biasNED'
    real_T nedWayPoint_e[30720];       // '<S109>/biasNED'
    real_T Memory_PreviousInput_h[8];  // '<S3>/Memory'
    real_T RotateRelPrevPos_DWORK4[9]; // '<S57>/RotateRelPrevPos'
    real_T RotateRelPrevPos_DWORK4_h[9];// '<S109>/RotateRelPrevPos'
    real_T MatrixConcatenateWayPoint[1500];// '<S199>/Matrix Concatenate WayPoint' 
    real_T MatrixConcatenateWayPoint_d[1200];// '<S161>/Matrix Concatenate WayPoint' 
    real_T WayPoint_h[30720];          // '<S109>/WayPointGenerator'
    real_T RotateIndivWayPoint_n[30720];// '<S109>/RotateIndivWayPoint'
    real_T rtb_WayPoint_h_c[30720];
    real_T mt_data[784];
    real_T b_fpa_data[784];
    real_T b_a_data[784];
    real_T mtr_data[784];
    real_T h_data[784];
    real_T mt_data_b[784];
    real_T b_fpa_data_p[784];
    real_T b_a_data_c[784];
    real_T mtr_data_f[784];
    real_T h_data_g[784];
    real_T mt_data_g[784];
    real_T b_fpa_data_m[784];
    real_T b_a_data_n[784];
    real_T mtr_data_p[784];
    real_T h_data_l[784];
    real_T mt_data_j[784];
    real_T b_fpa_data_d[784];
    real_T b_a_data_g[784];
    real_T mtr_data_l[784];
    real_T h_data_d[784];
    real_T Sum;                        // '<S199>/Sum'
    real_T MergeDesiredCourse;         // '<S198>/MergeDesiredCourse'
    real_T MergeStatus;                // '<S198>/MergeStatus'
    real_T ModRunWayPose;              // '<S161>/ModRunWayPose'
    real_T Bias1;                      // '<S161>/Bias1'
    real_T MergeDesiredCourse_h;       // '<S160>/MergeDesiredCourse'
    real_T MergeStatus_e;              // '<S160>/MergeStatus'
    real_T Memory_PreviousInput;       // '<S198>/Memory'
    real_T Memory_PreviousInput_f;     // '<S160>/Memory'
    MissionModes PreemptableMissionModeSelectorMode;
                                     // '<Root>/PreemptableMissionModeSelector'
    RunWaySegment RunWayMode;          // '<S160>/ModeSwitch'
    ProtectionLineSegment ProtectionLineMode;// '<S198>/ModeSwitch'
    int8_T SwitchCase_ActiveSubsystem; // '<Root>/Switch Case'
    int8_T SwitchCase_ActiveSubsystem_h;// '<S198>/Switch Case'
    int8_T SwitchCase_ActiveSubsystem_k;// '<S160>/Switch Case'
    uint8_T is_active_c20_FlightMissionMode;// '<S198>/ModeSwitch'
    uint8_T is_c20_FlightMissionMode;  // '<S198>/ModeSwitch'
    uint8_T is_Running;                // '<S198>/ModeSwitch'
    uint8_T temporalCounter_i1;        // '<S198>/ModeSwitch'
    uint8_T is_active_c3_FlightMissionMode;// '<S160>/ModeSwitch'
    uint8_T is_Running_f;              // '<S160>/ModeSwitch'
    uint8_T is_active_c23_FlightMissionMode;
                                     // '<Root>/PreemptableMissionModeSelector'
    uint8_T is_GuidanceLogic;        // '<Root>/PreemptableMissionModeSelector'
    boolean_T WayPointGenerator_MODE;  // '<S6>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_a;// '<S5>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_f;// '<S3>/WayPointGenerator'
    boolean_T WayPointGenerator_MODE_l;// '<S4>/WayPointGenerator'
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

// Real-time Model Data Structure
struct tag_RTM_FlightMissionMode_T {
    const char_T **errorStatus;
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

struct MdlrefDW_FlightMissionMode_T {
    RT_MODEL_FlightMissionMode_T rtm;
};

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

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
extern void FlightMissionMode_Init(FixedWingGuidanceBus *rty_GuidanceCmds,
    real_T rty_InitialState[8]);
extern void FlightMissionMode_Disable(void);
extern void FlightMissionMode(const boolean_T *rtu_startFlight, const
    MissionModes *rtu_mode, const Location *rtu_PrevLocation, const Location
    *rtu_Location, const Parameters *rtu_Parameters, const Location
    *rtu_StartPosition, const int32_T *rtu_Reset, const int32_T
    *rtu_FormationIDX, const int32_T *rtu_MissionUAV, const real_T rtu_Pose[4],
    real_T *rty_thisTaskStatus, FixedWingGuidanceBus *rty_GuidanceCmds, real_T
    rty_InitialState[8]);

// Model reference registration function
extern void FlightMissionMode_initialize(const char_T **rt_errorStatus);

#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

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
extern void FlightMissionMode_WaypointFollower_c_Init
    (DW_WaypointFollower_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_WaypointFollower_a_Reset
    (DW_WaypointFollower_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_WaypointFollower_p(const real_T rtu_0[4], const
    real_T rtu_1[300], real_T rtu_2, DW_WaypointFollower_FlightMissionMode_f_T
    *localDW);
extern void FlightMissionMode_minus(const real_T rtu_uP[300], const real_T
    rtu_uN[3], real_T rty_y[300]);
extern void FlightMissionMode_biasNED_c(const real_T rtu_MissionNED[3], const
    real_T rtu_IndivRotWP[300], real_T rty_nedWayPoint[300]);
extern void FlightMissionMode_WayPointGenerator(real_T rtu_Length, real_T
    rty_left[300], real_T rty_top[300], real_T rty_right[300], real_T
    rty_bottom[300], real_T rtp_numSegWP,
    DW_WayPointGenerator_FlightMissionMode_T *localDW);
extern void FlightMissionMode_biasNEDstartpose(const real_T rtu_MissionNED[3],
    const real_T rtu_IndivRotWP[3], real_T rty_nedWayPoint[3]);

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

extern const FixedWingGuidanceBus FlightMissionMode_rtZFixedWingGuidanceBus;// FixedWingGuidanceBus ground 

#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

extern MdlrefDW_FlightMissionMode_T FlightMissionMode_MdlrefDW;

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

#ifndef FlightMissionMode_MDLREF_HIDE_CHILD_

// Block states (default storage)
extern DW_FlightMissionMode_f_T FlightMissionMode_DW;

#endif                                 //FlightMissionMode_MDLREF_HIDE_CHILD_

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
//  '<S3>'   : 'FlightMissionMode/Mode22_CustomFormationNav'
//  '<S4>'   : 'FlightMissionMode/Mode2_HorizontalFormationNav'
//  '<S5>'   : 'FlightMissionMode/Mode3_RunWayNav'
//  '<S6>'   : 'FlightMissionMode/Mode4_ProtectionLine'
//  '<S7>'   : 'FlightMissionMode/PreemptableMissionModeSelector'
//  '<S8>'   : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth'
//  '<S9>'   : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap'
//  '<S10>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S11>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/Subsystem'
//  '<S12>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/pos_rad'
//  '<S13>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S14>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S15>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S16>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S17>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S18>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S19>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S20>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S21>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S22>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S23>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S24>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S25>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S26>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S27>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S28>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S29>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S30>'  : 'FlightMissionMode/Mode11_CircDispNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S31>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth'
//  '<S32>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap'
//  '<S33>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S34>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/Subsystem'
//  '<S35>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/pos_rad'
//  '<S36>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S37>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S38>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S39>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S40>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S41>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S42>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S43>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S44>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S45>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S46>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S47>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S48>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S49>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S50>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S51>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S52>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S53>'  : 'FlightMissionMode/Mode1_CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S54>'  : 'FlightMissionMode/Mode22_CustomFormationNav/Degrees to Radians'
//  '<S55>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth'
//  '<S56>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC'
//  '<S57>'  : 'FlightMissionMode/Mode22_CustomFormationNav/WayPointGenerator'
//  '<S58>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap'
//  '<S59>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S60>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/Subsystem'
//  '<S61>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/pos_rad'
//  '<S62>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S63>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S64>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S65>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S66>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S67>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S68>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S69>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S70>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S71>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S72>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S73>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S74>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S75>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S76>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S77>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S78>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S79>'  : 'FlightMissionMode/Mode22_CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S80>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth'
//  '<S81>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap'
//  '<S82>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S83>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem'
//  '<S84>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/pos_rad'
//  '<S85>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S86>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S87>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S88>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S89>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S90>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S91>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S92>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S93>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S94>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S95>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S96>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S97>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S98>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S99>'  : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S100>' : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S101>' : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S102>' : 'FlightMissionMode/Mode22_CustomFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S103>' : 'FlightMissionMode/Mode22_CustomFormationNav/WayPointGenerator/WayPointGenerator'
//  '<S104>' : 'FlightMissionMode/Mode22_CustomFormationNav/WayPointGenerator/biasNED'
//  '<S105>' : 'FlightMissionMode/Mode22_CustomFormationNav/WayPointGenerator/biasWayPoint'
//  '<S106>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/Degrees to Radians'
//  '<S107>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth'
//  '<S108>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC'
//  '<S109>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/WayPointGenerator'
//  '<S110>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap'
//  '<S111>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S112>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/Subsystem'
//  '<S113>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/pos_rad'
//  '<S114>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S115>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S116>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S117>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S118>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S119>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S120>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S121>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S122>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S123>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S124>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S125>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S126>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S127>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S128>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S129>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S130>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S131>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S132>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth'
//  '<S133>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap'
//  '<S134>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S135>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem'
//  '<S136>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/pos_rad'
//  '<S137>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S138>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S139>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S140>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S141>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S142>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S143>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S144>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S145>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S146>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S147>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S148>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S149>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S150>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S151>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S152>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S153>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S154>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S155>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/WayPointGenerator/WayPointGenerator'
//  '<S156>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/WayPointGenerator/biasNED'
//  '<S157>' : 'FlightMissionMode/Mode2_HorizontalFormationNav/WayPointGenerator/biasWayPoint'
//  '<S158>' : 'FlightMissionMode/Mode3_RunWayNav/Degrees to Radians'
//  '<S159>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth'
//  '<S160>' : 'FlightMissionMode/Mode3_RunWayNav/SegmentSwitch'
//  '<S161>' : 'FlightMissionMode/Mode3_RunWayNav/WayPointGenerator'
//  '<S162>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap'
//  '<S163>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S164>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/Subsystem'
//  '<S165>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/pos_rad'
//  '<S166>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S167>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S168>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S169>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S170>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S171>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S172>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S173>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S174>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S175>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S176>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S177>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S178>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S179>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S180>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S181>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S182>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S183>' : 'FlightMissionMode/Mode3_RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S184>' : 'FlightMissionMode/Mode3_RunWayNav/SegmentSwitch/Bottom'
//  '<S185>' : 'FlightMissionMode/Mode3_RunWayNav/SegmentSwitch/Left'
//  '<S186>' : 'FlightMissionMode/Mode3_RunWayNav/SegmentSwitch/ModeSwitch'
//  '<S187>' : 'FlightMissionMode/Mode3_RunWayNav/SegmentSwitch/Right'
//  '<S188>' : 'FlightMissionMode/Mode3_RunWayNav/SegmentSwitch/Top'
//  '<S189>' : 'FlightMissionMode/Mode3_RunWayNav/WayPointGenerator/Degrees to Radians1'
//  '<S190>' : 'FlightMissionMode/Mode3_RunWayNav/WayPointGenerator/StartPointGenerator'
//  '<S191>' : 'FlightMissionMode/Mode3_RunWayNav/WayPointGenerator/TransformWayPoint'
//  '<S192>' : 'FlightMissionMode/Mode3_RunWayNav/WayPointGenerator/WayPointGenerator'
//  '<S193>' : 'FlightMissionMode/Mode3_RunWayNav/WayPointGenerator/biasNEDstartpose'
//  '<S194>' : 'FlightMissionMode/Mode3_RunWayNav/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S195>' : 'FlightMissionMode/Mode3_RunWayNav/WayPointGenerator/TransformWayPoint/minus'
//  '<S196>' : 'FlightMissionMode/Mode4_ProtectionLine/Degrees to Radians'
//  '<S197>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth'
//  '<S198>' : 'FlightMissionMode/Mode4_ProtectionLine/SegmentSwitch'
//  '<S199>' : 'FlightMissionMode/Mode4_ProtectionLine/WayPointGenerator'
//  '<S200>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap'
//  '<S201>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap LL0'
//  '<S202>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/Subsystem'
//  '<S203>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/pos_rad'
//  '<S204>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S205>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S206>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S207>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S208>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S209>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S210>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S211>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S212>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S213>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S214>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S215>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S216>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S217>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S218>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S219>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S220>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S221>' : 'FlightMissionMode/Mode4_ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S222>' : 'FlightMissionMode/Mode4_ProtectionLine/SegmentSwitch/Bottom'
//  '<S223>' : 'FlightMissionMode/Mode4_ProtectionLine/SegmentSwitch/Initial'
//  '<S224>' : 'FlightMissionMode/Mode4_ProtectionLine/SegmentSwitch/Left'
//  '<S225>' : 'FlightMissionMode/Mode4_ProtectionLine/SegmentSwitch/ModeSwitch'
//  '<S226>' : 'FlightMissionMode/Mode4_ProtectionLine/SegmentSwitch/Right'
//  '<S227>' : 'FlightMissionMode/Mode4_ProtectionLine/SegmentSwitch/Top'
//  '<S228>' : 'FlightMissionMode/Mode4_ProtectionLine/WayPointGenerator/Degrees to Radians'
//  '<S229>' : 'FlightMissionMode/Mode4_ProtectionLine/WayPointGenerator/StartPointGenerator'
//  '<S230>' : 'FlightMissionMode/Mode4_ProtectionLine/WayPointGenerator/TransformWayPoint'
//  '<S231>' : 'FlightMissionMode/Mode4_ProtectionLine/WayPointGenerator/WayPointGenerator'
//  '<S232>' : 'FlightMissionMode/Mode4_ProtectionLine/WayPointGenerator/biasNEDstartpose'
//  '<S233>' : 'FlightMissionMode/Mode4_ProtectionLine/WayPointGenerator/TransformWayPoint/biasNED'
//  '<S234>' : 'FlightMissionMode/Mode4_ProtectionLine/WayPointGenerator/TransformWayPoint/minus'

#endif                                 // RTW_HEADER_FlightMissionMode_h_

//
// File trailer for generated code.
//
// [EOF]
//
