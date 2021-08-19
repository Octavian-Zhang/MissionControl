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

struct DW_OrbitFollower_FlightMissionMode_T {
    uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T obj;
    real_T OrbitFollower_o1[3];
    real_T OrbitFollower_o2;
    real_T OrbitFollower_o6;
    boolean_T objisempty;
};

struct DW_RotateATMissionHdg_FlightMissionMode_T {
    robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
        obj;
    real_T RotateATMissionHdg[9];
    boolean_T objisempty;
};

struct DW_biasNED_FlightMissionMode_T {
    real_T b[30720];
};

struct DW_WaypointFollower_FlightMissionMode_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T obj;
    real_T WaypointFollower_o1[3];
    real_T paddedWaypts[30720];
    real_T WaypointFollower_o2;
    int16_T c_data[10240];
    uint8_T WaypointFollower_o5;
    boolean_T b[10240];
    boolean_T x[30720];
    boolean_T objisempty;
};

struct DW_WaypointFollower_FlightMissionMode_f_T {
    uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj;
    real_T WaypointFollower_o1[3];
    real_T WaypointFollower_o2;
    real_T WaypointFollower_o3;
    uint8_T WaypointFollower_o4;
    uint8_T WaypointFollower_o5;
    boolean_T objisempty;
};

struct DW_WayPointGenerator_FlightMissionMode_T {
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_T pathSegObj;
    real_T mt_data[784];
    real_T b_fpa_data[784];
    real_T b_a_data[784];
    real_T mtr_data[784];
    real_T h_data[784];
};

struct DW_FlightMissionMode_f_T {
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_f;
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg_p;
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_pna;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevvfpgh;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevvfpg;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevvfp;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevvf;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaevv;
    DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_a;
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg;
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_pn;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnaev;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pnae;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pna;
    DW_WaypointFollower_FlightMissionMode_f_T WaypointFollower_pn;
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower_p;
    DW_biasNED_FlightMissionMode_T sf_biasNED_f;
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_p;
    DW_WaypointFollower_FlightMissionMode_T WaypointFollower;
    DW_biasNED_FlightMissionMode_T sf_biasNED;
    DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg;
    DW_OrbitFollower_FlightMissionMode_T OrbitFollower_p;
    DW_OrbitFollower_FlightMissionMode_T OrbitFollower;
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_T pathSegObj_c;
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_T pathSegObj_k;
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_p_T pathSegObj;
    emxArray_uavDubinsPathSegment_2_FlightMissionMode_p_T pathSegObj_m;
    real_T ProductFlipStartPose[5];
    real_T nedWayPoint[3];
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0[1500];
    real_T MergeLookAheadP[3];
    real_T nedWayPoint_g[3];
    real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0_l[1200];
    real_T MergeLookAheadP_k[3];
    real_T Reshape[8];
    real_T nedWayPoint_m[30720];
    real_T nedWayPoint_e[30720];
    real_T Memory_PreviousInput_h[8];
    real_T RotateRelPrevPos_DWORK4[9];
    real_T RotateRelPrevPos_DWORK4_h[9];
    real_T MatrixConcatenateWayPoint[1500];
    real_T MatrixConcatenateWayPoint_d[1200];
    real_T WayPoint_h[30720];
    real_T RotateIndivWayPoint_n[30720];
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
    real_T Sum;
    real_T MergeDesiredCourse;
    real_T MergeStatus;
    real_T ModRunWayPose;
    real_T Bias1;
    real_T MergeDesiredCourse_h;
    real_T MergeStatus_e;
    real_T Memory_PreviousInput;
    real_T Memory_PreviousInput_f;
    MissionModes PreemptableMissionModeSelectorMode;
    RunWaySegment RunWayMode;
    ProtectionLineSegment ProtectionLineMode;
    int8_T SwitchCase_ActiveSubsystem;
    int8_T SwitchCase_ActiveSubsystem_h;
    int8_T SwitchCase_ActiveSubsystem_k;
    uint8_T is_active_c20_FlightMissionMode;
    uint8_T is_c20_FlightMissionMode;
    uint8_T is_Running;
    uint8_T temporalCounter_i1;
    uint8_T is_active_c3_FlightMissionMode;
    uint8_T is_Running_f;
    uint8_T is_active_c23_FlightMissionMode;
    uint8_T is_GuidanceLogic;
    boolean_T WayPointGenerator_MODE;
    boolean_T WayPointGenerator_MODE_a;
    boolean_T WayPointGenerator_MODE_f;
    boolean_T WayPointGenerator_MODE_l;
};

struct tag_RTM_FlightMissionMode_T {
    const char_T **errorStatus;
};

struct MdlrefDW_FlightMissionMode_T {
    DW_FlightMissionMode_f_T rtdw;
    RT_MODEL_FlightMissionMode_T rtm;
};

extern real_T AltitudeGCS;
extern real_T LatitudeGCS;
extern real_T LongitudeGCS;
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
extern void FlightMissionMode_Init(FixedWingGuidanceBus *rty_GuidanceCmds,
    real_T rty_InitialState[8], DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Disable(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode_Update(DW_FlightMissionMode_f_T *localDW);
extern void FlightMissionMode(const boolean_T *rtu_startFlight, const
    MissionModes *rtu_mode, const Location *rtu_PrevLocation, const Location
    *rtu_Location, const Parameters *rtu_Parameters, const Location
    *rtu_StartPosition, const int32_T *rtu_Reset, const int32_T
    *rtu_FormationIDX, const int32_T *rtu_MissionUAV, const real_T rtu_Pose[4],
    real_T *rty_thisTaskStatus, FixedWingGuidanceBus *rty_GuidanceCmds, real_T
    rty_InitialState[8], DW_FlightMissionMode_f_T *localDW);
extern const FixedWingGuidanceBus FlightMissionMode_rtZFixedWingGuidanceBus;

#endif

