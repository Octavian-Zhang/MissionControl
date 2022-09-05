//
// File: FlightMissionMode.h
//
// Code generated for Simulink model 'FlightMissionMode'.
//
// Model version                  : 3.37
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Sep  5 17:36:03 2022
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

#include <cstring>

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
extern const FixedWingGuidanceBus FlightMissionMode_rtZFixedWingGuidanceBus;// FixedWingGuidanceBus ground 

// Class declaration for model FlightMissionMode
class FlightMissionMode final
{
    // public data and function members
  public:
    // Block signals and states (default storage) for system '<S38>/RotateATMissionHdg' 
    struct DW_RotateATMissionHdg_FlightMissionMode_T {
        robotics_slcore_internal_block_CoordinateTransformationConversion_FlightMissionMode_T
            obj;                       // '<S38>/RotateATMissionHdg'
        real_T RotateATMissionHdg[9];  // '<S38>/RotateATMissionHdg'
        boolean_T objisempty;          // '<S38>/RotateATMissionHdg'
    };

    // Block signals and states (default storage) for system '<S122>/Waypoint Follower' 
    struct DW_WaypointFollower_FlightMissionMode_T {
        uav_sluav_internal_system_WaypointFollower_FlightMissionMode_T obj;// '<S122>/Waypoint Follower' 
        real_T WaypointFollower_o1[3]; // '<S122>/Waypoint Follower'
        real_T WaypointFollower_o2;    // '<S122>/Waypoint Follower'
        real_T WaypointFollower_o3;    // '<S122>/Waypoint Follower'
        uint8_T WaypointFollower_o4;   // '<S122>/Waypoint Follower'
        uint8_T WaypointFollower_o5;   // '<S122>/Waypoint Follower'
        boolean_T objisempty;          // '<S122>/Waypoint Follower'
    };

    // Block signals and states (default storage) for system '<S91>/SegmentSwitch' 
    struct DW_SegmentSwitch_FlightMissionMode_T {
        DW_WaypointFollower_FlightMissionMode_T WaypointFollower_e;// '<S122>/Waypoint Follower' 
        DW_WaypointFollower_FlightMissionMode_T WaypointFollower_i;// '<S122>/Waypoint Follower' 
        DW_WaypointFollower_FlightMissionMode_T WaypointFollower_n;// '<S122>/Waypoint Follower' 
        DW_WaypointFollower_FlightMissionMode_T WaypointFollower_k;// '<S122>/Waypoint Follower' 
        DW_WaypointFollower_FlightMissionMode_T WaypointFollower;// '<S122>/Waypoint Follower' 
        real_T MergeStatus;            // '<S95>/MergeStatus'
        real_T Memory_PreviousInput;   // '<S95>/Memory'
        int8_T SwitchCase_ActiveSubsystem;// '<S95>/Switch Case'
        uint8_T is_active_c3_PathPlanning;// '<S95>/Chart'
        uint8_T is_c3_PathPlanning;    // '<S95>/Chart'
        uint8_T is_Running;            // '<S95>/Chart'
        uint8_T temporalCounter_i1;    // '<S95>/Chart'
    };

    // Block signals and states (default storage) for system '<S96>/StartPointGenerator' 
    struct DW_StartPointGenerator_FlightMissionMode_T {
        FILE* eml_openfiles[20];       // '<S96>/StartPointGenerator'
        DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S96>/StartPointGenerator' 
        boolean_T SingletonInstance_not_empty;// '<S96>/StartPointGenerator'
    };

    // Block signals and states (default storage) for system '<S96>/WayPointGenerator' 
    struct DW_WayPointGenerator_FlightMissionMode_T {
        FILE* eml_openfiles[20];       // '<S96>/WayPointGenerator'
        DubinsObjSingleton_FlightMissionMode_b_T SingletonInstance;// '<S96>/WayPointGenerator' 
        boolean_T SingletonInstance_not_empty;// '<S96>/WayPointGenerator'
    };

    // Block signals and states (default storage) for model 'FlightMissionMode'
    struct DW_FlightMissionMode_T {
        DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_f;// '<S138>/WayPointGenerator' 
        DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator_k;// '<S138>/StartPointGenerator' 
        DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg_k;// '<S38>/RotateATMissionHdg' 
        DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_k;// '<S38>/RotateATMissionHdg' 
        DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch_p;// '<S133>/SegmentSwitch' 
        DW_WayPointGenerator_FlightMissionMode_T sf_WayPointGenerator_k;// '<S96>/WayPointGenerator' 
        DW_StartPointGenerator_FlightMissionMode_T sf_StartPointGenerator;// '<S96>/StartPointGenerator' 
        DW_RotateATMissionHdg_FlightMissionMode_T RotateUpward;// '<S38>/RotateATMissionHdg' 
        DW_RotateATMissionHdg_FlightMissionMode_T RotateATRunWayHdg;// '<S38>/RotateATMissionHdg' 
        DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg_m;// '<S38>/RotateATMissionHdg' 
        DW_SegmentSwitch_FlightMissionMode_T SegmentSwitch;// '<S91>/SegmentSwitch' 
        DW_RotateATMissionHdg_FlightMissionMode_T RotateATMissionHdg;// '<S38>/RotateATMissionHdg' 
        FILE* eml_openfiles[20];       // '<S38>/WayPointGenerator'
        FILE* eml_openfiles_n[20];     // '<S181>/WayPointGenerator'
        uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T obj_j;// '<S179>/Waypoint Follower' 
        uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj;// '<S180>/Waypoint Follower' 
        uav_sluav_internal_system_WaypointFollower_FlightMissionMode_c_T obj_k;// '<S34>/Waypoint Follower' 
        uav_sluav_internal_system_OrbitFollower_FlightMissionMode_T obj_f;// '<S9>/Orbit Follower' 
        DubinsObjSingleton_FlightMissionMode_T SingletonInstance;// '<S38>/WayPointGenerator' 
        real_T WayPoint[24576];        // '<S181>/WayPointGenerator'
        real_T ProductFlipStartPose[5];// '<S138>/ProductFlipStartPose'
        real_T MatrixConcatenateWayPoint[1920];// '<S138>/Matrix Concatenate WayPoint' 
        real_T nedWayPoint[3];         // '<S138>/biasNEDstartpose1'
        real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0[1920];// '<S170>/biasNED' 
        real_T MergeLookAheadP[3];     // '<S137>/MergeLookAheadP'
        real_T MatrixConcatenateWayPoint_g[1920];// '<S96>/Matrix Concatenate WayPoint' 
        real_T nedWayPoint_m[3];       // '<S96>/biasNEDstartpose'
        real_T ImpAsg_InsertedFor_nedWayPoint_at_inport_0_c[1920];// '<S127>/biasNED' 
        real_T startPose_c[5];         // '<S96>/StartPointGenerator'
        real_T MergeLookAheadP_j[3];   // '<S95>/MergeLookAheadP'
        real_T nedWayPoint_o[24576];   // '<S38>/biasNED'
        real_T Delay_DSTATE[24];       // '<S91>/Delay'
        real_T RotateRelPrevPos_DWORK4[9];// '<S38>/RotateRelPrevPos'
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
        real_T Sum;                    // '<S138>/Sum'
        real_T MergeDesiredCourse;     // '<S137>/MergeDesiredCourse'
        real_T Sum_i;                  // '<S96>/Sum'
        real_T MergeDesiredCourse_p;   // '<S95>/MergeDesiredCourse'
        MissionModes FlightMission;  // '<Root>/PreemptableMissionModeSelector'
        RunWayLineSegment RunWayLineMode;// '<S137>/Chart'
        RunWayLineSegment RunWayLineMode_k;// '<S95>/Chart'
        int16_T c_data_f[8192];
        int16_T c_data_g[8192];
        int8_T SwitchCase_ActiveSubsystem;// '<Root>/Switch Case'
        int8_T SwitchCase_ActiveSubsystem_c;// '<S176>/Switch Case'
        uint8_T is_active_c2_FlightMissionMode;
                                     // '<Root>/PreemptableMissionModeSelector'
        uint8_T is_c2_FlightMissionMode;
                                     // '<Root>/PreemptableMissionModeSelector'
        boolean_T b[8192];
        boolean_T x[24576];
        boolean_T b_g[8192];
        boolean_T x_m[24576];
        boolean_T objisempty;          // '<S180>/Waypoint Follower'
        boolean_T objisempty_e;        // '<S179>/Waypoint Follower'
        boolean_T objisempty_n;        // '<S34>/Waypoint Follower'
        boolean_T SingletonInstance_not_empty;// '<S38>/WayPointGenerator'
        boolean_T objisempty_b;        // '<S9>/Orbit Follower'
        boolean_T WayPointGenerator_MODE;// '<S176>/WayPointGenerator'
        boolean_T WayPointGenerator_MODE_m;// '<S133>/WayPointGenerator'
        boolean_T WayPointGenerator_MODE_k;// '<S91>/WayPointGenerator'
        boolean_T WayPointGenerator_MODE_h;// '<S34>/WayPointGenerator'
    };

    // Real-time Model Data Structure
    struct RT_MODEL_FlightMissionMode_T {
        const char_T **errorStatus;
    };

    // model initialize function
    void initialize();

    // Initial conditions function
    void init(FixedWingGuidanceBus *rty_GuidanceCmds, real_T rty_InitialState[8]);

    // Copy Constructor
    FlightMissionMode(FlightMissionMode const&) = delete;

    // Assignment Operator
    FlightMissionMode& operator= (FlightMissionMode const&) & = delete;

    // Move Constructor
    FlightMissionMode(FlightMissionMode &&) = delete;

    // Move Assignment Operator
    FlightMissionMode& operator= (FlightMissionMode &&) = delete;

    // Real-Time Model get method
    FlightMissionMode::RT_MODEL_FlightMissionMode_T * getRTM();

    //member function to setup error status pointer
    void setErrorStatusPointer(const char_T **rt_errorStatus);

    // model step function
    void step(const boolean_T *rtu_startFlight, const MissionModes *rtu_mode,
              const Location *rtu_PrevLocation, const Location *rtu_Location,
              const Parameters *rtu_Parameters, const int32_T *rtu_Reset, const
              int32_T *rtu_FormationIDX, const int32_T *rtu_MissionUAV, const
              real_T rtu_Pose[4], real_T *rty_thisTaskStatus,
              FixedWingGuidanceBus *rty_GuidanceCmds, real_T rty_InitialState[8]);

    // model disable function
    void disable();

    // Constructor
    FlightMissionMode();

    // Destructor
    ~FlightMissionMode();

    // private data and function members
  private:
    // Block states
    DW_FlightMissionMode_T FlightMissionMode_DW;

    // private member function(s) for subsystem '<S38>/RotateATMissionHdg'
    static void FlightMissionMode_RotateATMissionHdg_Init
        (DW_RotateATMissionHdg_FlightMissionMode_T *localDW);
    static void FlightMissionMode_RotateATMissionHdg(const real_T rtu_0[3],
        DW_RotateATMissionHdg_FlightMissionMode_T *localDW);

    // private member function(s) for subsystem '<S122>/Waypoint Follower'
    static void FlightMissionMode_WaypointFollower_Init
        (DW_WaypointFollower_FlightMissionMode_T *localDW);
    static void FlightMissionMode_WaypointFollower_Reset
        (DW_WaypointFollower_FlightMissionMode_T *localDW);
    void FlightMissionMode_WaypointFollower(const real_T rtu_0[4], const real_T
        rtu_1[384], real_T rtu_2, DW_WaypointFollower_FlightMissionMode_T
        *localDW);
    real_T FlightMissionMode_norm(const real_T x[3]);

    // private member function(s) for subsystem '<S91>/SegmentSwitch'
    static void FlightMissionMode_SegmentSwitch_Init(real_T rty_LookAheadPoint[3],
        real_T *rty_DesiredCourse, RunWayLineSegment *rty_Status,
        DW_SegmentSwitch_FlightMissionMode_T *localDW);
    static void FlightMissionMode_SegmentSwitch_Reset(RunWayLineSegment
        *rty_Status, DW_SegmentSwitch_FlightMissionMode_T *localDW);
    static void FlightMissionMode_SegmentSwitch_Disable
        (DW_SegmentSwitch_FlightMissionMode_T *localDW);
    void FlightMissionMode_SegmentSwitch(const int32_T *rtu_Reset, const real_T
        rtu_Pose[4], const real_T rtu_RawWaypoint[1920], real_T
        rty_LookAheadPoint[3], real_T *rty_DesiredCourse, RunWayLineSegment
        *rty_Status, real_T rtp_LookAheadDis,
        DW_SegmentSwitch_FlightMissionMode_T *localDW);

    // private member function(s) for subsystem '<S96>/StartPointGenerator'
    static void FlightMissionMode_StartPointGenerator_Init
        (DW_StartPointGenerator_FlightMissionMode_T *localDW);
    static void FlightMissionMode_StartPointGenerator_Reset
        (DW_StartPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_StartPointGenerator(real_T rtu_Length, real_T
        rtu_RunWayUAV, real_T rtu_PosIDX, real_T rty_initWayPoint[384], real_T
        rty_startPose[5], DW_StartPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_emxInit_char_T(emxArray_char_T_FlightMissionMode_T
        **pEmxArray, int32_T numDimensions);
    int8_T FlightMissionMode_filedata(DW_StartPointGenerator_FlightMissionMode_T
        *localDW);
    int8_T FlightMissionMode_cfopen(const char_T *cfilename, const char_T
        *cpermission, DW_StartPointGenerator_FlightMissionMode_T *localDW);
    real_T FlightMissionMode_fileManager
        (DW_StartPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_emxEnsureCapacity_char_T
        (emxArray_char_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_fread(real_T fileID,
        emxArray_char_T_FlightMissionMode_T *A,
        DW_StartPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_emxFree_char_T(emxArray_char_T_FlightMissionMode_T
        **pEmxArray);
    boolean_T FlightMissionMode_copydigits(emxArray_char_T_FlightMissionMode_T
        *s1, int32_T *idx, const emxArray_char_T_FlightMissionMode_T *s, int32_T
        *k, int32_T n, boolean_T allowpoint);
    void FlightMissionMode_readfloat(emxArray_char_T_FlightMissionMode_T *s1,
        int32_T *idx, const emxArray_char_T_FlightMissionMode_T *s, int32_T *k,
        int32_T n, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
        real_T *nfv, boolean_T *foundsign, boolean_T *success);
    creal_T FlightMissionMode_str2double(const
        emxArray_char_T_FlightMissionMode_T *s);
    int32_T FlightMissionMode_cfclose(real_T fid,
        DW_StartPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_strtok(const emxArray_char_T_FlightMissionMode_T *x,
        emxArray_char_T_FlightMissionMode_T *token,
        emxArray_char_T_FlightMissionMode_T *remain);
    void FlightMissionMode_strtok_o(const emxArray_char_T_FlightMissionMode_T *x,
        emxArray_char_T_FlightMissionMode_T *token);
    void FlightMissionMode_strtrim(const emxArray_char_T_FlightMissionMode_T *x,
        emxArray_char_T_FlightMissionMode_T *y);
    boolean_T FlightMissionMode_strcmp(const emxArray_char_T_FlightMissionMode_T
        *a);
    boolean_T FlightMissionMode_strcmp_b(const
        emxArray_char_T_FlightMissionMode_T *a);
    boolean_T FlightMissionMode_contains(const
        emxArray_char_T_FlightMissionMode_T *str);
    void FlightMissionMode_find_token(const emxArray_char_T_FlightMissionMode_T *
        x, int32_T *itoken, int32_T *iremain);
    void FlightMissionMode_strtok_of(const emxArray_char_T_FlightMissionMode_T
        *x, emxArray_char_T_FlightMissionMode_T *token,
        emxArray_char_T_FlightMissionMode_T *remain);
    void FlightMissionMode_strtok_ofg(const emxArray_char_T_FlightMissionMode_T *
        x, emxArray_char_T_FlightMissionMode_T *token);
    boolean_T FlightMissionMode_strcmp_bt(const
        emxArray_char_T_FlightMissionMode_T *a);
    void FlightMissionMode_readINI(emxArray_char_T_FlightMissionMode_T *ret,
        DW_StartPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_readINI_b(emxArray_char_T_FlightMissionMode_T *ret,
        DW_StartPointGenerator_FlightMissionMode_T *localDW);
    boolean_T FlightMissionMode_strcmp_bt4(const
        emxArray_char_T_FlightMissionMode_T *a);
    boolean_T FlightMissionMode_strcmp_bt4y(const
        emxArray_char_T_FlightMissionMode_T *a);
    uavDubinsConnection_FlightMissionMode_T
        *FlightMissionMode_uavDubinsConnection_uavDubinsConnection
        (uavDubinsConnection_FlightMissionMode_T *b_this, real_T varargin_2,
         real_T varargin_4, const real_T varargin_6[2]);
    uavDubinsConnection_FlightMissionMode_T
        *FlightMissionMode_DubinsObjSingleton_getConnector
        (DW_StartPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_merge(int32_T idx_data[], int32_T x_data[], int32_T
        offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T
        xwork_data[]);
    void FlightMissionMode_sort(int32_T x_data[], const int32_T *x_size, int32_T
        idx_data[], int32_T *idx_size);
    void FlightMissionMode_do_vectors(real_T c_data[], int32_T c_size[2],
        int32_T ia_data[], int32_T *ia_size, int32_T *ib_size);
    void FlightMissionMode_do_vectors_b(const real_T b_data[], const int32_T
        *b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[], int32_T *
        ia_size, int32_T *ib_size);
    void FlightMissionMode_merge_m(int32_T idx_data[], real_T x_data[], int32_T
        offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T xwork_data[]);
    void FlightMissionMode_sort_l(real_T x_data[], const int32_T *x_size);
    void* FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable(real_T
        airSpeed, real_T maxRollAngle, const real_T flightPathAngle[2], const
        real_T disabledPathTypes_data[], const int32_T *disabledPathTypes_size);
    boolean_T FlightMissionMode_strcmp_bt4yh(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_bt4yhx(const char_T a_data[], const
        int32_T a_size[2]);
    void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_h(const
        real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3,
        real_T varargin_4, real_T varargin_5, real_T varargin_6, const
        cell_wrap_0_FlightMissionMode_T varargin_7[4], const real_T varargin_8[4],
        uavDubinsPathSegment_FlightMissionMode_T *b_this);
    void FlightMissionMode_uavDubinsBuiltins_connect(const
        uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPose[4],
        const real_T goalPose[4], real_T turningRadius, const real_T dpt_data[],
        const int32_T *dpt_size, uavDubinsPathSegment_FlightMissionMode_T
        *pathSegObjs, real_T *pathCosts);
    void FlightMissionMode_uavDubinsConnection_connect(const
        uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPoses[4],
        const real_T goalPoses[4], uavDubinsPathSegment_FlightMissionMode_T
        *pathSegObjs, real_T *pathCosts);
    void FlightMissionMode_emxInit_real_T(emxArray_real_T_FlightMissionMode_T
        **pEmxArray, int32_T numDimensions);
    void FlightMissionMode_strcmp_bt4yhx3(const cell_wrap_0_FlightMissionMode_T
        a[4], boolean_T b_bool[4]);
    boolean_T FlightMissionMode_any(const boolean_T x[4]);
    void FlightMissionMode_useConstantDim(const real_T varargin_2_data[], const
        int32_T varargin_2_size[2], real_T varargout_1_data[], int32_T
        varargout_1_size[2]);
    void FlightMissionMode_emxFree_real_T(emxArray_real_T_FlightMissionMode_T
        **pEmxArray);
    void FlightMissionMode_eml_find(boolean_T x, int32_T i_data[], int32_T
        i_size[2]);
    void FlightMissionMode_emxEnsureCapacity_real_T
        (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    boolean_T FlightMissionMode_strcmp_bt4yhx33(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_bt4yhx33c(const char_T a_data[], const
        int32_T a_size[2]);
    void FlightMissionMode_emxInit_boolean_T
        (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T
         numDimensions);
    void FlightMissionMode_emxEnsureCapacity_boolean_T
        (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_emxFree_boolean_T
        (emxArray_boolean_T_FlightMissionMode_T **pEmxArray);
    void FlightMissionMode_binary_expand_op
        (emxArray_boolean_T_FlightMissionMode_T *in1, const
         emxArray_real_T_FlightMissionMode_T *in2, const
         emxArray_real_T_FlightMissionMode_T *in3);
    void FlightMissionMode_wrapToPi(emxArray_real_T_FlightMissionMode_T *theta);
    boolean_T FlightMissionMode_strcmp_bt4yhx33cu(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_bt4yhx33cua(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_bt4yhx33cuar(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_bt4yhx33cuary(const char_T a_data[],
        const int32_T a_size[2]);
    void FlightMissionMode_mtimes(const emxArray_real_T_FlightMissionMode_T *A,
        const real_T B[4], emxArray_real_T_FlightMissionMode_T *C);
    void FlightMissionMode_uavDubinsPathSegment_interpolate(const real_T
        b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
        b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
        b_this_MinTurningRadius, real_T b_this_HelixRadius, const
        cell_wrap_0_FlightMissionMode_T b_this_MotionTypes[4], const real_T
        b_this_MotionLengths[4], real_T b_this_Length, real_T samples, real_T
        poses_data[], int32_T poses_size[2]);
    void FlightMissionMode_emxInit_int32_T(emxArray_int32_T_FlightMissionMode_T **
        pEmxArray, int32_T numDimensions);
    void FlightMissionMode_emxEnsureCapacity_int32_T
        (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_emxFree_int32_T(emxArray_int32_T_FlightMissionMode_T **
        pEmxArray);
    void FlightMissionMode_merge_mi(emxArray_int32_T_FlightMissionMode_T *idx,
        emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T np,
        int32_T nq, emxArray_int32_T_FlightMissionMode_T *iwork,
        emxArray_real_T_FlightMissionMode_T *xwork);
    void FlightMissionMode_merge_block(emxArray_int32_T_FlightMissionMode_T *idx,
        emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T n,
        int32_T preSortLevel, emxArray_int32_T_FlightMissionMode_T *iwork,
        emxArray_real_T_FlightMissionMode_T *xwork);
    void FlightMissionMode_sort_ll(emxArray_real_T_FlightMissionMode_T *x);
    void FlightMissionMode_eml_find_n(const
        emxArray_boolean_T_FlightMissionMode_T *x,
        emxArray_int32_T_FlightMissionMode_T *i);
    void FlightMissionMode_uavDubinsPathSegment_interpolate_p(const real_T
        b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
        b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
        b_this_MinTurningRadius, real_T b_this_HelixRadius, const
        cell_wrap_0_FlightMissionMode_T b_this_MotionTypes[4], const real_T
        b_this_MotionLengths[4], real_T b_this_Length,
        emxArray_real_T_FlightMissionMode_T *samples,
        emxArray_real_T_FlightMissionMode_T *poses);
    void FlightMissionMode_genSegWP(const real_T start[4], const real_T ende[4],
        emxArray_real_T_FlightMissionMode_T *segWayPoints,
        DW_StartPointGenerator_FlightMissionMode_T *localDW);

    // private member function(s) for subsystem '<S127>/minus'
    static void FlightMissionMode_minus(const real_T rtu_uP[384], const real_T
        rtu_uN[3], real_T rty_y[384]);

    // private member function(s) for subsystem '<S127>/biasNED'
    static void FlightMissionMode_biasNED(const real_T rtu_MissionNED[3], const
        real_T rtu_IndivRotWP[384], real_T rty_nedWayPoint[384]);

    // private member function(s) for subsystem '<S96>/WayPointGenerator'
    static void FlightMissionMode_WayPointGenerator_Init
        (DW_WayPointGenerator_FlightMissionMode_T *localDW);
    static void FlightMissionMode_WayPointGenerator_Reset
        (DW_WayPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_WayPointGenerator(real_T rtu_Length, real_T rty_left
        [384], real_T rty_top[384], real_T rty_right[384], real_T rty_bottom[384],
        DW_WayPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_emxInit_real_T_i(emxArray_real_T_FlightMissionMode_T **
        pEmxArray, int32_T numDimensions);
    void FlightMissionMode_emxInit_char_T_b(emxArray_char_T_FlightMissionMode_T **
        pEmxArray, int32_T numDimensions);
    int8_T FlightMissionMode_filedata_d(DW_WayPointGenerator_FlightMissionMode_T
        *localDW);
    int8_T FlightMissionMode_cfopen_h(const char_T *cfilename, const char_T
        *cpermission, DW_WayPointGenerator_FlightMissionMode_T *localDW);
    real_T FlightMissionMode_fileManager_d
        (DW_WayPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_emxEnsureCapacity_char_T_o
        (emxArray_char_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_fread_o(real_T fileID,
        emxArray_char_T_FlightMissionMode_T *A,
        DW_WayPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_emxFree_char_T_d(emxArray_char_T_FlightMissionMode_T **
        pEmxArray);
    boolean_T FlightMissionMode_copydigits_l(emxArray_char_T_FlightMissionMode_T
        *s1, int32_T *idx, const emxArray_char_T_FlightMissionMode_T *s, int32_T
        *k, int32_T n, boolean_T allowpoint);
    void FlightMissionMode_readfloat_e(emxArray_char_T_FlightMissionMode_T *s1,
        int32_T *idx, const emxArray_char_T_FlightMissionMode_T *s, int32_T *k,
        int32_T n, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
        real_T *nfv, boolean_T *foundsign, boolean_T *success);
    creal_T FlightMissionMode_str2double_o(const
        emxArray_char_T_FlightMissionMode_T *s);
    int32_T FlightMissionMode_cfclose_i(real_T fid,
        DW_WayPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_strtok_m(const emxArray_char_T_FlightMissionMode_T *x,
        emxArray_char_T_FlightMissionMode_T *token,
        emxArray_char_T_FlightMissionMode_T *remain);
    void FlightMissionMode_strtok_mv(const emxArray_char_T_FlightMissionMode_T
        *x, emxArray_char_T_FlightMissionMode_T *token);
    void FlightMissionMode_strtrim_c(const emxArray_char_T_FlightMissionMode_T
        *x, emxArray_char_T_FlightMissionMode_T *y);
    boolean_T FlightMissionMode_strcmp_o(const
        emxArray_char_T_FlightMissionMode_T *a);
    boolean_T FlightMissionMode_strcmp_oq(const
        emxArray_char_T_FlightMissionMode_T *a);
    boolean_T FlightMissionMode_contains_o(const
        emxArray_char_T_FlightMissionMode_T *str);
    void FlightMissionMode_find_token_g(const
        emxArray_char_T_FlightMissionMode_T *x, int32_T *itoken, int32_T
        *iremain);
    void FlightMissionMode_strtok_mv4(const emxArray_char_T_FlightMissionMode_T *
        x, emxArray_char_T_FlightMissionMode_T *token,
        emxArray_char_T_FlightMissionMode_T *remain);
    void FlightMissionMode_strtok_mv4j(const emxArray_char_T_FlightMissionMode_T
        *x, emxArray_char_T_FlightMissionMode_T *token);
    boolean_T FlightMissionMode_strcmp_oqn(const
        emxArray_char_T_FlightMissionMode_T *a);
    void FlightMissionMode_readINI_c(emxArray_char_T_FlightMissionMode_T *ret,
        DW_WayPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_readINI_co(emxArray_char_T_FlightMissionMode_T *ret,
        DW_WayPointGenerator_FlightMissionMode_T *localDW);
    boolean_T FlightMissionMode_strcmp_oqn4(const
        emxArray_char_T_FlightMissionMode_T *a);
    boolean_T FlightMissionMode_strcmp_oqn4q(const
        emxArray_char_T_FlightMissionMode_T *a);
    uavDubinsConnection_FlightMissionMode_c_T
        *FlightMissionMode_uavDubinsConnection_uavDubinsConnection_e
        (uavDubinsConnection_FlightMissionMode_c_T *b_this, real_T varargin_2,
         real_T varargin_4, const real_T varargin_6[2]);
    uavDubinsConnection_FlightMissionMode_c_T
        *FlightMissionMode_DubinsObjSingleton_getConnector_g
        (DW_WayPointGenerator_FlightMissionMode_T *localDW);
    void FlightMissionMode_merge_p(int32_T idx_data[], int32_T x_data[], int32_T
        offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T
        xwork_data[]);
    void FlightMissionMode_sort_o(int32_T x_data[], const int32_T *x_size,
        int32_T idx_data[], int32_T *idx_size);
    void FlightMissionMode_do_vectors_d(real_T c_data[], int32_T c_size[2],
        int32_T ia_data[], int32_T *ia_size, int32_T *ib_size);
    void FlightMissionMode_do_vectors_dl(const real_T b_data[], const int32_T
        *b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[], int32_T *
        ia_size, int32_T *ib_size);
    void FlightMissionMode_merge_p2(int32_T idx_data[], real_T x_data[], int32_T
        offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T xwork_data[]);
    void FlightMissionMode_sort_oi(real_T x_data[], const int32_T *x_size);
    void* FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable_i(real_T
        airSpeed, real_T maxRollAngle, const real_T flightPathAngle[2], const
        real_T disabledPathTypes_data[], const int32_T *disabledPathTypes_size);
    boolean_T FlightMissionMode_strcmp_oqn4q5(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_oqn4q52(const char_T a_data[], const
        int32_T a_size[2]);
    void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_n1(const
        real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3,
        real_T varargin_4, real_T varargin_5, real_T varargin_6, const
        cell_wrap_11_FlightMissionMode_T varargin_7[4], const real_T varargin_8
        [4], uavDubinsPathSegment_FlightMissionMode_g_T *b_this);
    void FlightMissionMode_uavDubinsBuiltins_connect_d(const
        uavDubinsConnection_FlightMissionMode_c_T *obj, const real_T startPose[4],
        const real_T goalPose[4], real_T turningRadius, const real_T dpt_data[],
        const int32_T *dpt_size, uavDubinsPathSegment_FlightMissionMode_g_T
        *pathSegObjs, real_T *pathCosts);
    void FlightMissionMode_emxEnsureCapacity_real_T_a
        (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_emxFree_real_T_c(emxArray_real_T_FlightMissionMode_T **
        pEmxArray);
    void FlightMissionMode_strcmp_oqn4q52h(const
        cell_wrap_11_FlightMissionMode_T a[4], boolean_T b_bool[4]);
    boolean_T FlightMissionMode_any_l(const boolean_T x[4]);
    void FlightMissionMode_useConstantDim_c(const real_T varargin_2_data[],
        const int32_T varargin_2_size[2], real_T varargout_1_data[], int32_T
        varargout_1_size[2]);
    void FlightMissionMode_emxInit_int32_T_j
        (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
    void FlightMissionMode_emxEnsureCapacity_int32_T_c
        (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_emxFree_int32_T_k
        (emxArray_int32_T_FlightMissionMode_T **pEmxArray);
    void FlightMissionMode_merge_p2m(emxArray_int32_T_FlightMissionMode_T *idx,
        emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T np,
        int32_T nq, emxArray_int32_T_FlightMissionMode_T *iwork,
        emxArray_real_T_FlightMissionMode_T *xwork);
    void FlightMissionMode_merge_block_n(emxArray_int32_T_FlightMissionMode_T
        *idx, emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T n,
        int32_T preSortLevel, emxArray_int32_T_FlightMissionMode_T *iwork,
        emxArray_real_T_FlightMissionMode_T *xwork);
    void FlightMissionMode_sort_oi4(emxArray_real_T_FlightMissionMode_T *x);
    void FlightMissionMode_emxInit_boolean_T_k
        (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T
         numDimensions);
    void FlightMissionMode_emxFree_boolean_T_d
        (emxArray_boolean_T_FlightMissionMode_T **pEmxArray);
    void FlightMissionMode_emxEnsureCapacity_boolean_T_p
        (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_binary_expand_op_h
        (emxArray_boolean_T_FlightMissionMode_T *in1, const
         emxArray_real_T_FlightMissionMode_T *in2, const
         emxArray_real_T_FlightMissionMode_T *in3);
    void FlightMissionMode_wrapToPi_i(emxArray_real_T_FlightMissionMode_T *theta);
    void FlightMissionMode_eml_find_p(const
        emxArray_boolean_T_FlightMissionMode_T *x,
        emxArray_int32_T_FlightMissionMode_T *i);
    boolean_T FlightMissionMode_strcmp_oqn4q52hk(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_oqn4q52hkt(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_oqn4q52hktu(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_oqn4q52hktuw(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_oqn4q52hktuwa(const char_T a_data[],
        const int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_oqn4q52hktuwav(const char_T a_data[],
        const int32_T a_size[2]);
    void FlightMissionMode_mtimes_n(const emxArray_real_T_FlightMissionMode_T *A,
        const real_T B[4], emxArray_real_T_FlightMissionMode_T *C);
    void FlightMissionMode_uavDubinsPathSegment_interpolate_d(const real_T
        b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
        b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
        b_this_MinTurningRadius, real_T b_this_HelixRadius, const
        cell_wrap_11_FlightMissionMode_T b_this_MotionTypes[4], const real_T
        b_this_MotionLengths[4], real_T b_this_Length,
        emxArray_real_T_FlightMissionMode_T *samples,
        emxArray_real_T_FlightMissionMode_T *poses);
    void FlightMissionMode_genSegWP_p(const real_T start[4], const real_T ende[4],
        emxArray_real_T_FlightMissionMode_T *segWayPoints,
        DW_WayPointGenerator_FlightMissionMode_T *localDW);

    // private member function(s) for subsystem '<S96>/biasNEDstartpose'
    static void FlightMissionMode_biasNEDstartpose(const real_T rtu_MissionNED[3],
        const real_T rtu_IndivRotWP[3], real_T rty_nedWayPoint[3]);

    // private member function(s) for subsystem '<Root>/TmpModelReferenceSubsystem'
    void FlightMissionMode_emxInit_char_T_e(emxArray_char_T_FlightMissionMode_T **
        pEmxArray, int32_T numDimensions);
    void FlightMissionMode_emxInit_real_T_h(emxArray_real_T_FlightMissionMode_T **
        pEmxArray, int32_T numDimensions);
    void FlightMissionMode_emxFree_real_T_n(emxArray_real_T_FlightMissionMode_T **
        pEmxArray);
    void FlightMissionMode_emxFree_char_T_o(emxArray_char_T_FlightMissionMode_T **
        pEmxArray);
    void FlightMissionMode_string_string(real_T val, char_T obj_Value_data[],
        int32_T obj_Value_size[2]);
    void FlightMissionMode_emxEnsureCapacity_real_T_c
        (emxArray_real_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    real_T FlightMissionMode_norm_pv(const real_T x[3]);
    void FlightMissionMode_WaypointFollower_stepImpl
        (uav_sluav_internal_system_WaypointFollower_FlightMissionMode_cc_T *obj,
         const real_T currentPose[4], const real_T waypoints[24576], real_T
         lookaheadDistance, real_T varargout_1[3], real_T *varargout_2, real_T
         *varargout_3, uint8_T *varargout_4, uint8_T *varargout_5);
    int8_T FlightMissionMode_filedata_g(void) const;
    int8_T FlightMissionMode_cfopen_f(const char_T cfilename_data[], const
        int32_T cfilename_size[2], const char_T *cpermission);
    int32_T FlightMissionMode_cfclose_m(real_T fid);
    FILE* FlightMissionMode_fileManager_l(real_T varargin_1);
    void FlightMissionMode_emxEnsureCapacity_char_T_g
        (emxArray_char_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_fgetl(real_T fileID,
        emxArray_char_T_FlightMissionMode_T *out);
    real_T FlightMissionMode_norm_p(const real_T x[2]);
    void FlightMissionMode_circshift(real_T a_data[], const int32_T a_size[2],
        real_T p);
    void FlightMissionMode_sind(real_T x_data[], const int32_T *x_size);
    void FlightMissionMode_cosd(real_T x_data[], const int32_T *x_size);
    void FlightMissionMode_binary_expand_op_puhaq(real_T in1_data[], int32_T
        *in1_size, const real_T in2_data[], const int32_T *in2_size, const
        real_T in3_data[], const int32_T in3_size[2]);
    void FlightMissionMode_binary_expand_op_puha(real_T in1_data[], int32_T
        in1_size[2], const real_T in2_data[], const int32_T *in2_size, const
        real_T in3_data[], const int32_T *in3_size, const real_T in4_data[],
        const int32_T *in4_size, const real_T in5_data[], const int32_T
        *in5_size, const real_T in6_data[], const int32_T in6_size[2], const
        real_T in7_data[], const int32_T *in7_size);
    void FlightMissionMode_lla2ecef(const real_T llaPos_data[], const int32_T
        llaPos_size[2], real_T ecefPos_data[], int32_T ecefPos_size[2]);
    void FlightMissionMode_minus_l(real_T in1_data[], int32_T in1_size[2], const
        real_T in2_data[], const int32_T in2_size[2]);
    void FlightMissionMode_binary_expand_op_puh(real_T in1_data[], int32_T
        *in1_size, const real_T in2_data[], const int32_T *in2_size, const
        real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
        const int32_T *in4_size);
    void FlightMissionMode_binary_expand_op_pu(real_T in1_data[], int32_T
        in1_size[2], const real_T in2_data[], const int32_T *in2_size, const
        real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
        const int32_T *in4_size, const real_T in5_data[], const int32_T
        *in5_size, const real_T in6_data[], const int32_T *in6_size, const
        real_T in7_data[], const int32_T *in7_size);
    void FlightMissionMode_lla2ned(const real_T lla_data[], const int32_T
        lla_size[2], const real_T lla0[3], real_T xyzNED_data[], int32_T
        xyzNED_size[2]);
    boolean_T FlightMissionMode_copydigits_d(emxArray_char_T_FlightMissionMode_T
        *s1, int32_T *idx, const emxArray_char_T_FlightMissionMode_T *s, int32_T
        *k, int32_T n, boolean_T allowpoint);
    void FlightMissionMode_readfloat_i(emxArray_char_T_FlightMissionMode_T *s1,
        int32_T *idx, const emxArray_char_T_FlightMissionMode_T *s, int32_T *k,
        int32_T n, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
        real_T *nfv, boolean_T *foundsign, boolean_T *success);
    real_T FlightMissionMode_angdiff(real_T x, real_T y);
    int8_T FlightMissionMode_filedata_dj(void) const;
    int8_T FlightMissionMode_cfopen_g(const char_T *cfilename, const char_T
        *cpermission);
    real_T FlightMissionMode_fileManager_e(void);
    void FlightMissionMode_fread_e(real_T fileID,
        emxArray_char_T_FlightMissionMode_T *A);
    creal_T FlightMissionMode_str2double_a(const
        emxArray_char_T_FlightMissionMode_T *s);
    int32_T FlightMissionMode_cfclose_p(real_T fid);
    void FlightMissionMode_strtok_o5(const emxArray_char_T_FlightMissionMode_T
        *x, emxArray_char_T_FlightMissionMode_T *token,
        emxArray_char_T_FlightMissionMode_T *remain);
    void FlightMissionMode_strtok_o5f(const emxArray_char_T_FlightMissionMode_T *
        x, emxArray_char_T_FlightMissionMode_T *token);
    void FlightMissionMode_strtrim_j(const emxArray_char_T_FlightMissionMode_T
        *x, emxArray_char_T_FlightMissionMode_T *y);
    boolean_T FlightMissionMode_strcmp_n(const
        emxArray_char_T_FlightMissionMode_T *a);
    boolean_T FlightMissionMode_strcmp_np(const
        emxArray_char_T_FlightMissionMode_T *a);
    boolean_T FlightMissionMode_contains_k(const
        emxArray_char_T_FlightMissionMode_T *str);
    void FlightMissionMode_find_token_a(const
        emxArray_char_T_FlightMissionMode_T *x, int32_T *itoken, int32_T
        *iremain);
    void FlightMissionMode_strtok_o5ft(const emxArray_char_T_FlightMissionMode_T
        *x, emxArray_char_T_FlightMissionMode_T *token,
        emxArray_char_T_FlightMissionMode_T *remain);
    void FlightMissionMode_strtok_o5ft5(const
        emxArray_char_T_FlightMissionMode_T *x,
        emxArray_char_T_FlightMissionMode_T *token);
    boolean_T FlightMissionMode_strcmp_npg(const
        emxArray_char_T_FlightMissionMode_T *a);
    void FlightMissionMode_readINI_m(emxArray_char_T_FlightMissionMode_T *ret);
    void FlightMissionMode_readINI_mk(emxArray_char_T_FlightMissionMode_T *ret);
    boolean_T FlightMissionMode_strcmp_npg2(const
        emxArray_char_T_FlightMissionMode_T *a);
    boolean_T FlightMissionMode_strcmp_npg2o(const
        emxArray_char_T_FlightMissionMode_T *a);
    uavDubinsConnection_FlightMissionMode_T
        *FlightMissionMode_uavDubinsConnection_uavDubinsConnection_o
        (uavDubinsConnection_FlightMissionMode_T *b_this, real_T varargin_2,
         real_T varargin_4, const real_T varargin_6[2]);
    uavDubinsConnection_FlightMissionMode_T
        *FlightMissionMode_DubinsObjSingleton_getConnector_gb(void);
    void FlightMissionMode_merge_b(int32_T idx_data[], int32_T x_data[], int32_T
        offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T
        xwork_data[]);
    void FlightMissionMode_sort_c(int32_T x_data[], const int32_T *x_size,
        int32_T idx_data[], int32_T *idx_size);
    void FlightMissionMode_do_vectors_m(real_T c_data[], int32_T c_size[2],
        int32_T ia_data[], int32_T *ia_size, int32_T *ib_size);
    void FlightMissionMode_do_vectors_mj(const real_T b_data[], const int32_T
        *b_size, real_T c_data[], int32_T c_size[2], int32_T ia_data[], int32_T *
        ia_size, int32_T *ib_size);
    void FlightMissionMode_merge_b3(int32_T idx_data[], real_T x_data[], int32_T
        offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T xwork_data[]);
    void FlightMissionMode_sort_c5(real_T x_data[], const int32_T *x_size);
    void* FlightMissionMode_uavDubinsBuildable_uavDubinsBuildable_e(real_T
        airSpeed, real_T maxRollAngle, const real_T flightPathAngle[2], const
        real_T disabledPathTypes_data[], const int32_T *disabledPathTypes_size);
    boolean_T FlightMissionMode_strcmp_npg2ox(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_npg2ox3(const char_T a_data[], const
        int32_T a_size[2]);
    void FlightMissionMode_uavDubinsPathSegment_uavDubinsPathSegment_gj(const
        real_T varargin_1[4], const real_T varargin_2[4], real_T varargin_3,
        real_T varargin_4, real_T varargin_5, real_T varargin_6, const
        cell_wrap_0_FlightMissionMode_T varargin_7[4], const real_T varargin_8[4],
        uavDubinsPathSegment_FlightMissionMode_T *b_this);
    void FlightMissionMode_uavDubinsBuiltins_connect_i(const
        uavDubinsConnection_FlightMissionMode_T *obj, const real_T startPose[4],
        const real_T goalPose[4], real_T turningRadius, const real_T dpt_data[],
        const int32_T *dpt_size, uavDubinsPathSegment_FlightMissionMode_T
        *pathSegObjs, real_T *pathCosts);
    void FlightMissionMode_strcmp_npg2ox3u(const cell_wrap_0_FlightMissionMode_T
        a[4], boolean_T b_bool[4]);
    boolean_T FlightMissionMode_any_o(const boolean_T x[4]);
    void FlightMissionMode_useConstantDim_d(const real_T varargin_2_data[],
        const int32_T varargin_2_size[2], real_T varargout_1_data[], int32_T
        varargout_1_size[2]);
    void FlightMissionMode_emxInit_int32_T_k
        (emxArray_int32_T_FlightMissionMode_T **pEmxArray, int32_T numDimensions);
    void FlightMissionMode_emxEnsureCapacity_int32_T_j
        (emxArray_int32_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_emxFree_int32_T_a
        (emxArray_int32_T_FlightMissionMode_T **pEmxArray);
    void FlightMissionMode_merge_b30(emxArray_int32_T_FlightMissionMode_T *idx,
        emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T np,
        int32_T nq, emxArray_int32_T_FlightMissionMode_T *iwork,
        emxArray_real_T_FlightMissionMode_T *xwork);
    void FlightMissionMode_merge_block_f(emxArray_int32_T_FlightMissionMode_T
        *idx, emxArray_real_T_FlightMissionMode_T *x, int32_T offset, int32_T n,
        int32_T preSortLevel, emxArray_int32_T_FlightMissionMode_T *iwork,
        emxArray_real_T_FlightMissionMode_T *xwork);
    void FlightMissionMode_sort_c5e(emxArray_real_T_FlightMissionMode_T *x);
    void FlightMissionMode_emxInit_boolean_T_c
        (emxArray_boolean_T_FlightMissionMode_T **pEmxArray, int32_T
         numDimensions);
    void FlightMissionMode_emxFree_boolean_T_n
        (emxArray_boolean_T_FlightMissionMode_T **pEmxArray);
    void FlightMissionMode_emxEnsureCapacity_boolean_T_f
        (emxArray_boolean_T_FlightMissionMode_T *emxArray, int32_T oldNumel);
    void FlightMissionMode_binary_expand_op_p
        (emxArray_boolean_T_FlightMissionMode_T *in1, const
         emxArray_real_T_FlightMissionMode_T *in2, const
         emxArray_real_T_FlightMissionMode_T *in3);
    void FlightMissionMode_wrapToPi_o(emxArray_real_T_FlightMissionMode_T *theta);
    void FlightMissionMode_eml_find_c(const
        emxArray_boolean_T_FlightMissionMode_T *x,
        emxArray_int32_T_FlightMissionMode_T *i);
    boolean_T FlightMissionMode_strcmp_npg2ox3uz(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_npg2ox3uzp(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_npg2ox3uzpm(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_npg2ox3uzpmy(const char_T a_data[], const
        int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_npg2ox3uzpmyq(const char_T a_data[],
        const int32_T a_size[2]);
    boolean_T FlightMissionMode_strcmp_npg2ox3uzpmyq2(const char_T a_data[],
        const int32_T a_size[2]);
    void FlightMissionMode_mtimes_k(const emxArray_real_T_FlightMissionMode_T *A,
        const real_T B[4], emxArray_real_T_FlightMissionMode_T *C);
    void FlightMissionMode_uavDubinsPathSegment_interpolate_a(const real_T
        b_this_StartPose[4], const real_T b_this_GoalPose[4], real_T
        b_this_FlightPathAngle, real_T b_this_AirSpeed, real_T
        b_this_MinTurningRadius, real_T b_this_HelixRadius, const
        cell_wrap_0_FlightMissionMode_T b_this_MotionTypes[4], const real_T
        b_this_MotionLengths[4], real_T b_this_Length,
        emxArray_real_T_FlightMissionMode_T *samples,
        emxArray_real_T_FlightMissionMode_T *poses);
    void FlightMissionMode_genSegWP_m(const real_T start[4], const real_T ende[4],
        real_T numWPs, emxArray_real_T_FlightMissionMode_T *segWayPoints);

    // Real-Time Model
    RT_MODEL_FlightMissionMode_T FlightMissionMode_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S10>/Data Type Duplicate' : Unused code path elimination
//  Block '<S36>/Data Type Duplicate' : Unused code path elimination
//  Block '<S64>/Data Type Duplicate' : Unused code path elimination
//  Block '<S94>/Data Type Duplicate' : Unused code path elimination
//  Block '<S135>/Data Type Duplicate' : Unused code path elimination
//  Block '<S178>/Data Type Duplicate' : Unused code path elimination
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
//  '<S92>'  : 'FlightMissionMode/Mode3_RunWayNav/Mode3_Variant/Mode3/Compare To Constant'
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

#endif                                 // RTW_HEADER_FlightMissionMode_h_

//
// File trailer for generated code.
//
// [EOF]
//
