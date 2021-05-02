//
// File: PreemptableMissionModeSelector.h
//
// Code generated for Simulink model 'PreemptableMissionModeSelector'.
//
// Model version                  : 2.427
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  2 12:25:38 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives:
//    1. Safety precaution
//    2. Execution efficiency
//    3. RAM efficiency
//    4. ROM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_PreemptableMissionModeSelector_h_
#define RTW_HEADER_PreemptableMissionModeSelector_h_
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "uavdubinscodegen_connection_api.hpp"
#include "PreemptableMissionModeSelector_types.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"

// Block signals for system '<S2>/Orbit Follower'
struct B_OrbitFollower_PreemptableMissionModeSelector_T {
  real_T OrbitFollower_o1[3];          // '<S2>/Orbit Follower'
  real_T OrbitFollower_o2;             // '<S2>/Orbit Follower'
  real_T OrbitFollower_o6;             // '<S2>/Orbit Follower'
};

// Block states (default storage) for system '<S2>/Orbit Follower'
struct DW_OrbitFollower_PreemptableMissionModeSelector_T {
  uav_sluav_internal_system_OrbitFollower_PreemptableMissionModeSelector_T obj;// '<S2>/Orbit Follower' 
  boolean_T objisempty;                // '<S2>/Orbit Follower'
};

// Block signals for system '<S56>/RotateATMissionHdg'
struct B_RotateATMissionHdg_PreemptableMissionModeSelector_T {
  real_T RotateATMissionHdg[9];        // '<S56>/RotateATMissionHdg'
};

// Block states (default storage) for system '<S56>/RotateATMissionHdg'
struct DW_RotateATMissionHdg_PreemptableMissionModeSelector_T {
  robotics_slcore_internal_block_CoordinateTransformationConversion_PreemptableMissionModeSelector_T
    obj;                               // '<S56>/RotateATMissionHdg'
  boolean_T objisempty;                // '<S56>/RotateATMissionHdg'
};

// Block signals for system '<S56>/biasNED'
struct B_biasNED_PreemptableMissionModeSelector_T {
  real_T b[30720];
};

// Block signals for system '<S4>/Waypoint Follower'
struct B_WaypointFollower_PreemptableMissionModeSelector_T {
  real_T paddedWaypts[30720];
  boolean_T x[30720];
  int16_T c_data[10240];
  boolean_T b[10240];
  real_T WaypointFollower_o1[3];       // '<S4>/Waypoint Follower'
  real_T WaypointFollower_o2;          // '<S4>/Waypoint Follower'
  uint8_T WaypointFollower_o5;         // '<S4>/Waypoint Follower'
};

// Block states (default storage) for system '<S4>/Waypoint Follower'
struct DW_WaypointFollower_PreemptableMissionModeSelector_T {
  uav_sluav_internal_system_WaypointFollower_PreemptableMissionModeSelector_T
    obj;                               // '<S4>/Waypoint Follower'
  boolean_T objisempty;                // '<S4>/Waypoint Follower'
};

// Block signals for system '<S117>/biasNED'
struct B_biasNED_PreemptableMissionModeSelector_h_T {
  real_T b[30720];
};

// Block signals for model 'PreemptableMissionModeSelector'
struct B_PreemptableMissionModeSelector_c_T {
  real_T nedWayPoint[30720];           // '<S168>/biasNED'
  real_T nedWayPoint_a[30720];         // '<S117>/biasNED'
  real_T nedWayPoint_k[30720];         // '<S86>/biasNED'
  real_T WayPoint[30720];              // '<S168>/WayPointGenerator'
  real_T RotateIndivWayPoint[30720];   // '<S168>/RotateIndivWayPoint'
  real_T rtb_WayPoint_m[30720];
  real_T mt_data[784];
  real_T b_fpa_data[784];
  real_T b_a_data[784];
  real_T mtr_data[784];
  real_T h_data[784];
  real_T mt_data_c[784];
  real_T b_fpa_data_k[784];
  real_T b_a_data_c[784];
  real_T mtr_data_b[784];
  real_T h_data_p[784];
  real_T mt_data_cv[784];
  real_T b_fpa_data_f[784];
  real_T b_a_data_g[784];
  real_T mtr_data_g[784];
  real_T h_data_m[784];
  real_T mt_data_n[784];
  real_T b_fpa_data_p[784];
  real_T b_a_data_l[784];
  real_T mtr_data_j[784];
  real_T h_data_d[784];
  emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_T pathSegObj;
  emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_T pathSegObj_g;
  emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_T pathSegObj_l;
  emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_g_T
    pathSegObj_d;
  emxArray_uavDubinsPathSegment_2_PreemptableMissionModeSelector_g_T
    pathSegObj_dy;
  real_T Bias;                         // '<S86>/Bias'
  real_T nedWayPoint_f[3];             // '<S86>/biasNEDstartpose'
  real_T Bias_g;                       // '<S56>/Bias'
  real_T nedWayPoint_l[3];             // '<S56>/biasNEDstartpose'
  real_T nedWayPoint_j[30720];         // '<S56>/biasNED'
  B_WaypointFollower_PreemptableMissionModeSelector_T WaypointFollower_baf;// '<S4>/Waypoint Follower' 
  B_biasNED_PreemptableMissionModeSelector_h_T sf_biasNED_j;// '<S168>/biasNED'
  B_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATMissionHdg_baf;// '<S56>/RotateATMissionHdg' 
  B_WaypointFollower_PreemptableMissionModeSelector_T WaypointFollower_ba;// '<S4>/Waypoint Follower' 
  B_biasNED_PreemptableMissionModeSelector_h_T sf_biasNED_l;// '<S117>/biasNED'
  B_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATMissionHdg_ba;// '<S56>/RotateATMissionHdg' 
  B_WaypointFollower_PreemptableMissionModeSelector_T WaypointFollower_b;// '<S4>/Waypoint Follower' 
  B_biasNED_PreemptableMissionModeSelector_T sf_biasNED_f;// '<S86>/biasNED'
  B_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATRunWayHdg_b;// '<S56>/RotateATMissionHdg' 
  B_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATMissionHdg_b;// '<S56>/RotateATMissionHdg' 
  B_WaypointFollower_PreemptableMissionModeSelector_T WaypointFollower;// '<S4>/Waypoint Follower' 
  B_biasNED_PreemptableMissionModeSelector_T sf_biasNED;// '<S56>/biasNED'
  B_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATRunWayHdg;// '<S56>/RotateATMissionHdg' 
  B_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATMissionHdg;// '<S56>/RotateATMissionHdg' 
  B_OrbitFollower_PreemptableMissionModeSelector_T OrbitFollower_b;// '<S2>/Orbit Follower' 
  B_OrbitFollower_PreemptableMissionModeSelector_T OrbitFollower;// '<S2>/Orbit Follower' 
};

// Block states (default storage) for model 'PreemptableMissionModeSelector'
struct DW_PreemptableMissionModeSelector_f_T {
  real_T MemoryPrevRelPos_PreviousInput[3];// '<S7>/MemoryPrevRelPos'
  real_T MemoryTriggerWP_PreviousInput;// '<S7>/MemoryTriggerWP'
  real_T RotateRelPrevPos_DWORK4[9];   // '<S168>/RotateRelPrevPos'
  real_T MemoryPrevRelPos_PreviousInput_n[3];// '<S6>/MemoryPrevRelPos'
  real_T MemoryTriggerWP_PreviousInput_d;// '<S6>/MemoryTriggerWP'
  real_T RotateRelPrevPos_DWORK4_b[9]; // '<S117>/RotateRelPrevPos'
  real_T MemoryTriggerWP_PreviousInput_b;// '<S5>/MemoryTriggerWP'
  real_T MemoryStopTrigger1_PreviousInput;// '<S5>/MemoryStopTrigger1'
  real_T MemoryStopTrigger2_PreviousInput;// '<S5>/MemoryStopTrigger2'
  real_T MemoryTriggerWP_PreviousInput_i;// '<S4>/MemoryTriggerWP'
  real_T MemoryStopTrigger1_PreviousInput_o;// '<S4>/MemoryStopTrigger1'
  real_T MemoryStopTrigger2_PreviousInput_n;// '<S4>/MemoryStopTrigger2'
  int32_T SequenceID_prev;           // '<Root>/PreemptableMissionModeSelector'
  int32_T SequenceID_start;          // '<Root>/PreemptableMissionModeSelector'
  uint8_T is_active_c23_PreemptableMissionModeSelector;
                                     // '<Root>/PreemptableMissionModeSelector'
  uint8_T is_GuidanceLogic;          // '<Root>/PreemptableMissionModeSelector'
  uint8_T is_OrbitFollower;          // '<Root>/PreemptableMissionModeSelector'
  uint8_T is_WaypointFollower;       // '<Root>/PreemptableMissionModeSelector'
  DW_WaypointFollower_PreemptableMissionModeSelector_T WaypointFollower_baf;// '<S4>/Waypoint Follower' 
  DW_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATMissionHdg_baf;// '<S56>/RotateATMissionHdg' 
  DW_WaypointFollower_PreemptableMissionModeSelector_T WaypointFollower_ba;// '<S4>/Waypoint Follower' 
  DW_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATMissionHdg_ba;// '<S56>/RotateATMissionHdg' 
  DW_WaypointFollower_PreemptableMissionModeSelector_T WaypointFollower_b;// '<S4>/Waypoint Follower' 
  DW_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATRunWayHdg_b;// '<S56>/RotateATMissionHdg' 
  DW_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATMissionHdg_b;// '<S56>/RotateATMissionHdg' 
  DW_WaypointFollower_PreemptableMissionModeSelector_T WaypointFollower;// '<S4>/Waypoint Follower' 
  DW_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATRunWayHdg;// '<S56>/RotateATMissionHdg' 
  DW_RotateATMissionHdg_PreemptableMissionModeSelector_T RotateATMissionHdg;// '<S56>/RotateATMissionHdg' 
  DW_OrbitFollower_PreemptableMissionModeSelector_T OrbitFollower_b;// '<S2>/Orbit Follower' 
  DW_OrbitFollower_PreemptableMissionModeSelector_T OrbitFollower;// '<S2>/Orbit Follower' 
};

// Zero-crossing (trigger) state for model 'PreemptableMissionModeSelector'
struct ZCE_PreemptableMissionModeSelector_T {
  ZCSigState WayPointGenerator_Trig_ZCE;// '<S7>/WayPointGenerator'
  ZCSigState WayPointGenerator_Trig_ZCE_a;// '<S6>/WayPointGenerator'
  ZCSigState WayPointGenerator_Trig_ZCE_e;// '<S5>/WayPointGenerator'
  ZCSigState WayPointGenerator_Trig_ZCE_p;// '<S4>/WayPointGenerator'
};

// Invariant block signals for model 'PreemptableMissionModeSelector'
struct ConstB_PreemptableMissionModeSelector_h_T {
  real_T Sum;                          // '<S189>/Sum'
  real_T Product1;                     // '<S190>/Product1'
  real_T Sum1;                         // '<S190>/Sum1'
  real_T sqrt_b;                       // '<S190>/sqrt'
  real_T Product2;                     // '<S186>/Product2'
  real_T Sum1_d;                       // '<S186>/Sum1'
  real_T Sum_c;                        // '<S211>/Sum'
  real_T Product1_p;                   // '<S212>/Product1'
  real_T Sum1_i;                       // '<S212>/Sum1'
  real_T sqrt_c;                       // '<S212>/sqrt'
  real_T Product2_g;                   // '<S208>/Product2'
  real_T Sum1_in;                      // '<S208>/Sum1'
  real_T Sum_g;                        // '<S138>/Sum'
  real_T Product1_m;                   // '<S139>/Product1'
  real_T Sum1_p;                       // '<S139>/Sum1'
  real_T sqrt_bu;                      // '<S139>/sqrt'
  real_T Product2_e;                   // '<S135>/Product2'
  real_T Sum1_c;                       // '<S135>/Sum1'
  real_T Sum_h;                        // '<S160>/Sum'
  real_T Product1_e;                   // '<S161>/Product1'
  real_T Sum1_g;                       // '<S161>/Sum1'
  real_T sqrt_a;                       // '<S161>/sqrt'
  real_T Product2_c;                   // '<S157>/Product2'
  real_T Sum1_l;                       // '<S157>/Sum1'
  real_T Sum_j;                        // '<S107>/Sum'
  real_T Product1_pa;                  // '<S108>/Product1'
  real_T Sum1_dc;                      // '<S108>/Sum1'
  real_T sqrt_j;                       // '<S108>/sqrt'
  real_T Product2_k;                   // '<S104>/Product2'
  real_T Sum1_f;                       // '<S104>/Sum1'
  real_T Sum_ch;                       // '<S77>/Sum'
  real_T Product1_f;                   // '<S78>/Product1'
  real_T Sum1_lu;                      // '<S78>/Sum1'
  real_T sqrt_d;                       // '<S78>/sqrt'
  real_T Product2_j;                   // '<S74>/Product2'
  real_T Sum1_k;                       // '<S74>/Sum1'
  real_T Sum_e;                        // '<S52>/Sum'
  real_T Product1_b;                   // '<S53>/Product1'
  real_T Sum1_cu;                      // '<S53>/Sum1'
  real_T sqrt_i;                       // '<S53>/sqrt'
  real_T Product2_i;                   // '<S49>/Product2'
  real_T Sum1_fv;                      // '<S49>/Sum1'
  real_T Sum_a;                        // '<S29>/Sum'
  real_T Product1_eu;                  // '<S30>/Product1'
  real_T Sum1_ip;                      // '<S30>/Sum1'
  real_T sqrt_g;                       // '<S30>/sqrt'
  real_T Product2_ex;                  // '<S26>/Product2'
  real_T Sum1_kk;                      // '<S26>/Sum1'
};

// Real-time Model Data Structure
struct tag_RTM_PreemptableMissionModeSelector_T {
  const char_T **errorStatus;
};

struct MdlrefDW_PreemptableMissionModeSelector_T {
  B_PreemptableMissionModeSelector_c_T rtb;
  DW_PreemptableMissionModeSelector_f_T rtdw;
  RT_MODEL_PreemptableMissionModeSelector_T rtm;
  ZCE_PreemptableMissionModeSelector_T rtzce;
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
extern void PreemptableMissionModeSelector_initialize(const char_T
  **rt_errorStatus, RT_MODEL_PreemptableMissionModeSelector_T *const
  PreemptableMissionModeSelector_M, ZCE_PreemptableMissionModeSelector_T
  *localZCE);
extern void PreemptableMissionModeSelector_OrbitFollower_Init
  (DW_OrbitFollower_PreemptableMissionModeSelector_T *localDW);
extern void PreemptableMissionModeSelector_OrbitFollower(const real_T rtu_0[4],
  const real_T rtu_1[3], real_T rtu_2, real_T rtu_3, real_T rtu_4,
  B_OrbitFollower_PreemptableMissionModeSelector_T *localB,
  DW_OrbitFollower_PreemptableMissionModeSelector_T *localDW);
extern void PreemptableMissionModeSelector_RotateATMissionHdg_Init
  (DW_RotateATMissionHdg_PreemptableMissionModeSelector_T *localDW);
extern void PreemptableMissionModeSelector_RotateATMissionHdg(const real_T
  rtu_0[3], B_RotateATMissionHdg_PreemptableMissionModeSelector_T *localB);
extern void PreemptableMissionModeSelector_biasNED(const real_T rtu_MissionNED[3],
  const real_T rtu_IndivRotWP[30720], real_T rty_nedWayPoint[30720],
  B_biasNED_PreemptableMissionModeSelector_T *localB);
extern void PreemptableMissionModeSelector_biasNEDstartpose(const real_T
  rtu_MissionNED[3], const real_T rtu_IndivRotWP[3], real_T rty_nedWayPoint[3]);
extern void PreemptableMissionModeSelector_minus(const real_T rtu_uP[30720],
  const real_T rtu_uN[3], real_T rty_y[30720]);
extern void PreemptableMissionModeSelector_WaypointFollower_Init
  (DW_WaypointFollower_PreemptableMissionModeSelector_T *localDW);
extern void PreemptableMissionModeSelector_WaypointFollower(const real_T rtu_0[4],
  const real_T rtu_1[30720], real_T rtu_2,
  B_WaypointFollower_PreemptableMissionModeSelector_T *localB,
  DW_WaypointFollower_PreemptableMissionModeSelector_T *localDW);
extern void PreemptableMissionModeSelector_biasNED_l(const real_T
  rtu_MissionNED[3], const real_T rtu_IndivRotWP[30720], real_T rty_nedWayPoint
  [30720], B_biasNED_PreemptableMissionModeSelector_h_T *localB);
extern void PreemptableMissionModeSelector_Init(FixedWingGuidanceBus
  *rty_GuidanceCmds, real_T rty_InitialState[8], real_T rty_VelShift[2],
  DW_PreemptableMissionModeSelector_f_T *localDW);
extern void PreemptableMissionModeSelector(const boolean_T *rtu_startFlight,
  const int32_T *rtu_mode, const Location *rtu_PrevLocation, const Location
  *rtu_Location, const Parameters *rtu_Parameters, const Location
  *rtu_StartPosition, const int32_T *rtu_SequenceID, const int32_T
  *rtu_FormationIDX, const int32_T *rtu_MissionUAV, const real_T rtu_Pose[4],
  real_T *rty_thisTaskStatus, FixedWingGuidanceBus *rty_GuidanceCmds, real_T
  *rty_ResetTrigger, real_T rty_InitialState[8], real_T rty_VelShift[2],
  B_PreemptableMissionModeSelector_c_T *localB,
  DW_PreemptableMissionModeSelector_f_T *localDW,
  ZCE_PreemptableMissionModeSelector_T *localZCE);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Right' : Unused code path elimination
//  Block '<S2>/Front' : Eliminate redundant signal conversion block
//  Block '<S2>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S2>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S2>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S2>/Up' : Eliminate redundant signal conversion block
//  Block '<S3>/MissionAirspeed35' : Eliminate redundant signal conversion block
//  Block '<S3>/Rasius' : Eliminate redundant signal conversion block
//  Block '<S3>/TurnDirection' : Eliminate redundant signal conversion block
//  Block '<S4>/Angle' : Eliminate redundant signal conversion block
//  Block '<S4>/Length' : Eliminate redundant signal conversion block
//  Block '<S4>/MaxSpeed' : Eliminate redundant signal conversion block
//  Block '<S4>/MinSpeed' : Eliminate redundant signal conversion block
//  Block '<S4>/SepDis' : Eliminate redundant signal conversion block
//  Block '<S5>/AngleStep' : Eliminate redundant signal conversion block
//  Block '<S5>/Length' : Eliminate redundant signal conversion block
//  Block '<S5>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S5>/Radius' : Eliminate redundant signal conversion block
//  Block '<S5>/RunWayID' : Eliminate redundant signal conversion block
//  Block '<S6>/Front' : Eliminate redundant signal conversion block
//  Block '<S6>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S6>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S6>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S6>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S6>/Right' : Eliminate redundant signal conversion block
//  Block '<S6>/Up' : Eliminate redundant signal conversion block
//  Block '<S117>/Reshape' : Reshape block reduction
//  Block '<S7>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S7>/LengthX' : Eliminate redundant signal conversion block
//  Block '<S7>/LengthY' : Eliminate redundant signal conversion block
//  Block '<S7>/MissionAirspeed' : Eliminate redundant signal conversion block
//  Block '<S168>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'PreemptableMissionModeSelector'
//  '<S1>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector'
//  '<S2>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav'
//  '<S3>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav'
//  '<S4>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine'
//  '<S5>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav'
//  '<S6>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav'
//  '<S7>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav'
//  '<S8>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth'
//  '<S9>'   : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap'
//  '<S10>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S11>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem'
//  '<S12>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/pos_rad'
//  '<S13>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S14>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S15>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S16>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S17>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S18>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S19>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S20>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S21>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S22>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S23>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S24>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S25>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S26>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S27>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S28>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S29>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S30>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CircleDisplayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S31>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth'
//  '<S32>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap'
//  '<S33>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S34>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem'
//  '<S35>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/pos_rad'
//  '<S36>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S37>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S38>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S39>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S40>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S41>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S42>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S43>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S44>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S45>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S46>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S47>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S48>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S49>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S50>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S51>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S52>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S53>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.OrbitFollower.CirclingNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S54>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/Degrees to Radians'
//  '<S55>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth'
//  '<S56>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/WayPointGenerator'
//  '<S57>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap'
//  '<S58>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap LL0'
//  '<S59>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/Subsystem'
//  '<S60>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/pos_rad'
//  '<S61>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S62>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S63>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S64>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S65>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S66>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S67>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S68>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S69>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S70>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S71>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S72>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S73>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S74>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S75>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S76>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S77>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S78>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S79>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/WayPointGenerator/Degrees to Radians'
//  '<S80>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/WayPointGenerator/WayPointGenerator'
//  '<S81>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/WayPointGenerator/biasNED'
//  '<S82>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/WayPointGenerator/biasNEDstartpose'
//  '<S83>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.ProtectionLine/WayPointGenerator/minus'
//  '<S84>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/Degrees to Radians'
//  '<S85>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth'
//  '<S86>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/WayPointGenerator'
//  '<S87>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap'
//  '<S88>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S89>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/Subsystem'
//  '<S90>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/pos_rad'
//  '<S91>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S92>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S93>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S94>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S95>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S96>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S97>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S98>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S99>'  : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S100>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S101>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S102>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S103>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S104>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S105>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S106>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S107>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S108>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S109>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/WayPointGenerator/Degrees to Radians'
//  '<S110>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/WayPointGenerator/WayPointGenerator'
//  '<S111>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/WayPointGenerator/biasNED'
//  '<S112>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/WayPointGenerator/biasNEDstartpose'
//  '<S113>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.RunWayNav/WayPointGenerator/minus'
//  '<S114>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Degrees to Radians'
//  '<S115>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth'
//  '<S116>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth'
//  '<S117>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/WayPointGenerator'
//  '<S118>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap'
//  '<S119>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S120>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem'
//  '<S121>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/pos_rad'
//  '<S122>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S123>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S124>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S125>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S126>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S127>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S128>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S129>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S130>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S131>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S132>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S133>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S134>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S135>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S136>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S137>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S138>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S139>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S140>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap'
//  '<S141>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S142>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem'
//  '<S143>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/pos_rad'
//  '<S144>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S145>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S146>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S147>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S148>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S149>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S150>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S151>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S152>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S153>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S154>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S155>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S156>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S157>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S158>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S159>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S160>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S161>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S162>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/WayPointGenerator/WayPointGenerator'
//  '<S163>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/WayPointGenerator/biasNED'
//  '<S164>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.CustomFormationNav/WayPointGenerator/biasWayPoint'
//  '<S165>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Degrees to Radians'
//  '<S166>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth'
//  '<S167>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth'
//  '<S168>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/WayPointGenerator'
//  '<S169>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap'
//  '<S170>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0'
//  '<S171>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem'
//  '<S172>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/pos_rad'
//  '<S173>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S174>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S175>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S176>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S177>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S178>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S179>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S180>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S181>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S182>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S183>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S184>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S185>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S186>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S187>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S188>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S189>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S190>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S191>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap'
//  '<S192>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S193>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem'
//  '<S194>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/pos_rad'
//  '<S195>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S196>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S197>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S198>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S199>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S200>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S201>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S202>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S203>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S204>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S205>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S206>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S207>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S208>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S209>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S210>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S211>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S212>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S213>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/WayPointGenerator/WayPointGenerator'
//  '<S214>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/WayPointGenerator/biasNED'
//  '<S215>' : 'PreemptableMissionModeSelector/PreemptableMissionModeSelector/GuidanceLogic.WaypointFollower.HorizontalFormationNav/WayPointGenerator/biasWayPoint'

#endif                          // RTW_HEADER_PreemptableMissionModeSelector_h_

//
// File trailer for generated code.
//
// [EOF]
//
