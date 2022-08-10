//
// File: ImmedMission.h
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 3.28
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Aug 10 13:59:36 2022
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
#include <cstring>
#include "zero_crossing_types.h"

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

// Class declaration for model ImmedMission
class ImmedMission final
{
    // public data and function members
  public:
    // Block signals and states (default storage) for system '<S112>/Altitude'
    struct DW_Altitude_ImmedMission_T {
        uav_sluav_internal_system_WaypointFollower_ImmedMission_T obj;// '<S112>/Altitude' 
        real_T Altitude_o1[3];         // '<S112>/Altitude'
        real_T HeadingAngle;           // '<S112>/Altitude'
        uint8_T Altitude_o5;           // '<S112>/Altitude'
        boolean_T objisempty;          // '<S112>/Altitude'
    };

    // Block signals and states (default storage) for system '<S146>/Coordinate Transformation Conversion' 
    struct DW_CoordinateTransformationConversion_ImmedMission_T {
        robotics_slcore_internal_block_CoordinateTransformationConversion_ImmedMission_T
            obj;               // '<S146>/Coordinate Transformation Conversion'
        real_T CoordinateTransformationConversion[9];
                               // '<S146>/Coordinate Transformation Conversion'
        boolean_T objisempty;  // '<S146>/Coordinate Transformation Conversion'
    };

    // Block signals and states (default storage) for model 'ImmedMission'
    struct DW_ImmedMission_T {
        FILE* eml_openfiles[20];       // '<S64>/BaseWayPoint'
        uav_sluav_internal_system_WaypointFollower_ImmedMission_c_T obj;// '<S58>/Waypoint Follower' 
        uav_sluav_internal_system_OrbitFollower_ImmedMission_T obj_c;// '<S24>/Orbit Follower' 
        FixedWingGuidanceStateBus MergeCollAvoidSimUAV;// '<S1>/MergeCollAvoidSimUAV' 
        DubinsObjSingleton_ImmedMission_T SingletonInstance;// '<S64>/BaseWayPoint' 
        robotics_slcore_internal_block_CoordinateTransformationConversion_ImmedMission_T
            obj_n;                     // '<S64>/RotateATMissionHdg'
        real_T DiscreteTimeIntegrator[2];// '<S150>/Discrete-Time Integrator'
        real_T MatrixConcatenate[6];   // '<S115>/Matrix Concatenate'
        real_T MatrixConcatenate_d[30723];// '<S64>/Matrix Concatenate'
        real_T Minus[3];               // '<S64>/Minus'
        real_T nedWayPoint[30720];     // '<S64>/BaseWayPoint'
        real_T DiscreteTimeIntegrator_DSTATE[2];// '<S150>/Discrete-Time Integrator' 
        real_T Out_data[4096];
        real_T paddedWaypts[30723];
        real_T CirVec[720];
        real_T a[1092];
        real_T Omega;                  // '<S18>/Divide'
        real_T Omega_g;                // '<S141>/Divide'
        real_T OrbitNavHdg;            // '<S27>/OrbitNavHdg'
        real_T xSign_prev;             // '<S58>/TriggerCalibrStart'
        real_T xSign_start;            // '<S58>/TriggerCalibrStart'
        void *MatrixConcatenate_PWORK; // '<S64>/Matrix Concatenate'
        int32_T SFunction_DIMS2[2];    // '<Root>/RemoveNaN'
        int32_T MatrixConcatenate_DIMS1[2];// '<S64>/Matrix Concatenate'
        int32_T SFunction_DIMS2_b[2];  // '<S64>/BaseWayPoint'
        int32_T SFunction_DIMS2_c;     // '<S13>/pdist2'
        MissionModes ImmedMission_a;   // '<S1>/PreemptableMissionModeSelector'
        MissionModes FlightMode_prev;  // '<S1>/PreemptableMissionModeSelector'
        MissionModes FlightMode_start; // '<S1>/PreemptableMissionModeSelector'
        int16_T j_data[10242];
        int8_T SwitchCase_ActiveSubsystem;// '<S1>/Switch Case'
        uint8_T WaypointFollower_o5;   // '<S58>/Waypoint Follower'
        uint8_T Memory_PreviousInput;  // '<S1>/Memory'
        uint8_T Memory_PreviousInput_j;// '<Root>/Memory'
        uint8_T is_active_c12_ImmedMission;// '<S148>/EnableSailShift'
        uint8_T is_c12_ImmedMission;   // '<S148>/EnableSailShift'
        uint8_T temporalCounter_i1;    // '<S148>/EnableSailShift'
        uint8_T is_active_c7_ImmedMission;// '<S58>/TriggerCalibrStart'
        uint8_T is_c7_ImmedMission;    // '<S58>/TriggerCalibrStart'
        uint8_T is_active_c1_ImmedMission;// '<S24>/HdgHoldLogic'
        uint8_T is_c1_ImmedMission;    // '<S24>/HdgHoldLogic'
        uint8_T temporalCounter_i1_p;  // '<S24>/HdgHoldLogic'
        uint8_T is_active_c25_ImmedMission;// '<S1>/PreemptableMissionModeSelector' 
        uint8_T is_c25_ImmedMission;   // '<S1>/PreemptableMissionModeSelector'
        uint8_T is_ImmedMission;       // '<S1>/PreemptableMissionModeSelector'
        boolean_T i_data[10242];
        boolean_T x_data[30726];
        boolean_T objisempty;          // '<S58>/Waypoint Follower'
        boolean_T objisempty_o;        // '<S64>/RotateATMissionHdg'
        boolean_T SingletonInstance_not_empty;// '<S64>/BaseWayPoint'
        boolean_T objisempty_e;        // '<S24>/Orbit Follower'
        boolean_T SailShift_MODE;      // '<S148>/SailShift'
    };

    // Zero-crossing (trigger) state for model 'ImmedMission'
    struct PrevZCX_ImmedMission_T {
        ZCSigState WayPointGen_Trig_ZCE;// '<S112>/WayPointGen'
        ZCSigState WayPointGen_Trig_ZCE_d;// '<S58>/WayPointGen'
    };

    // Real-time Model Data Structure
    struct RT_MODEL_ImmedMission_T {
        const char_T **errorStatus;
    };

    // model data, for system '<S112>/Altitude'
    struct self_Altitude_ImmedMission_T {
        DW_Altitude_ImmedMission_T dwork;
    };

    // model data, for system '<S146>/Coordinate Transformation Conversion'
    struct self_CoordinateTransformationConversion_ImmedMission_T {
        DW_CoordinateTransformationConversion_ImmedMission_T dwork;
    };

    // model initialize function
    void initialize();

    // Initial conditions function
    void init(boolean_T rty_ControlSwitch[2], FixedWingGuidanceBus
              *rty_GuidanceCMD);

    // Copy Constructor
    ImmedMission(ImmedMission const&) = delete;

    // Assignment Operator
    ImmedMission& operator= (ImmedMission const&) & = delete;

    // Move Constructor
    ImmedMission(ImmedMission &&) = delete;

    // Move Assignment Operator
    ImmedMission& operator= (ImmedMission &&) = delete;

    // Real-Time Model get method
    ImmedMission::RT_MODEL_ImmedMission_T * getRTM();

    //member function to setup error status pointer
    void setErrorStatusPointer(const char_T **rt_errorStatus);

    // model step function
    void step(const FixedWingGuidanceStateBus *rtu_SimUAVstate, const missionCmd
              *rtu_MissionInput, const boolean_T *rtu_NewImmed, const
              RealUAVStateBus *rtu_RealUAVState, const int32_T
              *rtu_FlightMission_SequenceID, const MissionModes
              *rtu_FlightMission_MissionMode, const real_T
              *rtu_FlightMission_MissionLocation_Lat, const real_T
              *rtu_FlightMission_MissionLocation_Lon, const real_T
              *rtu_FlightMission_MissionLocation_Alt, const real_T
              *rtu_FlightMission_MissionLocation_degHDG, const real32_T
              *rtu_FlightMission_params_Param3, const int32_T
              *rtu_FlightMission_numUAV, const int32_T
              *rtu_FlightMission_FormationPos, const real_T rtu_OtherUAVstate
              [4096], const uint8_T *rtu_RealUAVEngaged, const MissionModes
              *rtu_FlightMode, real_T *rty_TaskStatus, FixedWingGuidanceStateBus
              *rty_FinalSimUAVState, boolean_T rty_ControlSwitch[2],
              FixedWingGuidanceBus *rty_GuidanceCMD);

    // model disable function
    void disable();

    // Constructor
    ImmedMission();

    // Destructor
    ~ImmedMission();

    // private data and function members
  private:
    // Block states
    DW_ImmedMission_T ImmedMission_DW;

    // Triggered events
    PrevZCX_ImmedMission_T ImmedMission_PrevZCX;

    // model data
    self_CoordinateTransformationConversion_ImmedMission_T
        self_CoordinateTransformationConversion_j;

    // model data
    self_CoordinateTransformationConversion_ImmedMission_T
        self_CoordinateTransformationConversion;

    // model data
    self_Altitude_ImmedMission_T self_Heading;

    // model data
    self_Altitude_ImmedMission_T self_Altitude;

    // private member function(s) for subsystem '<S112>/Altitude'
    static void ImmedMission_Altitude_Init(self_Altitude_ImmedMission_T
        *ImmedMission_self_arg, const real_T rtu_0[4], const real_T rtu_1[6],
        real_T rtu_2);
    static void ImmedMission_Altitude_Reset(self_Altitude_ImmedMission_T
        *ImmedMission_self_arg);
    void ImmedMission_Altitude(self_Altitude_ImmedMission_T
        *ImmedMission_self_arg, const real_T rtu_0[4], const real_T rtu_1[6],
        real_T rtu_2);
    real_T ImmedMission_norm(const real_T x[3]);

    // private member function(s) for subsystem '<S146>/Coordinate Transformation Conversion'
    static void ImmedMission_CoordinateTransformationConversion_Init
        (self_CoordinateTransformationConversion_ImmedMission_T
         *ImmedMission_self_arg, const real_T rtu_0[3]);
    static void ImmedMission_CoordinateTransformationConversion
        (self_CoordinateTransformationConversion_ImmedMission_T
         *ImmedMission_self_arg, const real_T rtu_0[3]);

    // private member function(s) for subsystem '<S139>/DivisionByZeroProtection'
    static void ImmedMission_DivisionByZeroProtection(real_T rtu_HorizSpd,
        real_T rtu_CentripetalAcc, real_T *rty_OmegaRad);

    // private member function(s) for subsystem '<Root>/TmpModelReferenceSubsystem'
    void ImmedMission_emxInit_real_T(emxArray_real_T_ImmedMission_T **pEmxArray,
        int32_T numDimensions);
    void ImmedMission_emxFree_real_T(emxArray_real_T_ImmedMission_T **pEmxArray);
    real_T ImmedMission_norm_p(const real_T x[2]);
    void ImmedMission_emxInit_char_T(emxArray_char_T_ImmedMission_T **pEmxArray,
        int32_T numDimensions);
    int8_T ImmedMission_filedata(void) const;
    int8_T ImmedMission_cfopen(const char_T *cfilename, const char_T
        *cpermission);
    real_T ImmedMission_fileManager(void);
    void ImmedMission_emxEnsureCapacity_char_T(emxArray_char_T_ImmedMission_T
        *emxArray, int32_T oldNumel);
    void ImmedMission_fread(real_T fileID, emxArray_char_T_ImmedMission_T *A);
    void ImmedMission_emxFree_char_T(emxArray_char_T_ImmedMission_T **pEmxArray);
    boolean_T ImmedMission_copydigits(emxArray_char_T_ImmedMission_T *s1,
        int32_T *idx, const emxArray_char_T_ImmedMission_T *s, int32_T *k,
        int32_T n, boolean_T allowpoint);
    void ImmedMission_readfloat(emxArray_char_T_ImmedMission_T *s1, int32_T *idx,
        const emxArray_char_T_ImmedMission_T *s, int32_T *k, int32_T n,
        boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
        boolean_T *foundsign, boolean_T *success);
    creal_T ImmedMission_str2double(const emxArray_char_T_ImmedMission_T *s);
    int32_T ImmedMission_cfclose(real_T fid);
    void ImmedMission_strtok(const emxArray_char_T_ImmedMission_T *x,
        emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
        *remain);
    void ImmedMission_strtok_n(const emxArray_char_T_ImmedMission_T *x,
        emxArray_char_T_ImmedMission_T *token);
    void ImmedMission_strtrim(const emxArray_char_T_ImmedMission_T *x,
        emxArray_char_T_ImmedMission_T *y);
    boolean_T ImmedMission_strcmp(const emxArray_char_T_ImmedMission_T *a);
    boolean_T ImmedMission_strcmp_h(const emxArray_char_T_ImmedMission_T *a);
    boolean_T ImmedMission_contains(const emxArray_char_T_ImmedMission_T *str);
    void ImmedMission_find_token(const emxArray_char_T_ImmedMission_T *x,
        int32_T *itoken, int32_T *iremain);
    void ImmedMission_strtok_nx(const emxArray_char_T_ImmedMission_T *x,
        emxArray_char_T_ImmedMission_T *token, emxArray_char_T_ImmedMission_T
        *remain);
    void ImmedMission_strtok_nx2(const emxArray_char_T_ImmedMission_T *x,
        emxArray_char_T_ImmedMission_T *token);
    boolean_T ImmedMission_strcmp_ho(const emxArray_char_T_ImmedMission_T *a);
    void ImmedMission_readINI(emxArray_char_T_ImmedMission_T *ret);
    void ImmedMission_readINI_o(emxArray_char_T_ImmedMission_T *ret);
    boolean_T ImmedMission_strcmp_hoc(const emxArray_char_T_ImmedMission_T *a);
    uavDubinsConnection_ImmedMission_T
        *ImmedMission_uavDubinsConnection_uavDubinsConnection
        (uavDubinsConnection_ImmedMission_T *b_this, real_T varargin_2, real_T
         varargin_4);
    boolean_T ImmedMission_strcmp_hocj(const emxArray_char_T_ImmedMission_T *a);
    real_T ImmedMission_DubinsObjSingleton_getMinTurnRadius(void);
    void ImmedMission_emxEnsureCapacity_real_T(emxArray_real_T_ImmedMission_T
        *emxArray, int32_T oldNumel);
    void ImmedMission_binary_expand_op_pu(boolean_T in1_data[], int32_T
        in1_size[2], const emxArray_real_T_ImmedMission_T *in2, int32_T in3,
        int32_T in4);
    void ImmedMission_WaypointFollowerBase_getDistinctWpts(const
        emxArray_real_T_ImmedMission_T *waypoints,
        emxArray_real_T_ImmedMission_T *distinctWpts);
    void ImmedMission_circshift(emxArray_real_T_ImmedMission_T *a);
    real_T ImmedMission_norm_pv(const real_T x[3]);
    real_T ImmedMission_angdiff(real_T x, real_T y);
    void ImmedMission_binary_expand_op_p(emxArray_real_T_ImmedMission_T *in1,
        const emxArray_real_T_ImmedMission_T *in2, int32_T in3, int32_T in4);
    void ImmedMission_binary_expand_op(emxArray_real_T_ImmedMission_T *in1,
        const emxArray_real_T_ImmedMission_T *in2, const
        emxArray_real_T_ImmedMission_T *in3);

    // Real-Time Model
    RT_MODEL_ImmedMission_T ImmedMission_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S26>/Gain1' : Unused code path elimination
//  Block '<S29>/Data Type Duplicate' : Unused code path elimination
//  Block '<S61>/Data Type Duplicate' : Unused code path elimination
//  Block '<S87>/Data Type Duplicate' : Unused code path elimination
//  Block '<S114>/Data Type Duplicate' : Unused code path elimination
//  Block '<S155>/Data Type Duplicate' : Unused code path elimination
//  Block '<S22>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S24>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S24>/LowerRange' : Eliminate redundant signal conversion block
//  Block '<S24>/UpperRange' : Eliminate redundant signal conversion block
//  Block '<S54>/InterPlaneDis' : Eliminate redundant signal conversion block
//  Block '<S58>/Cycles' : Eliminate redundant signal conversion block
//  Block '<S58>/FilletStep' : Eliminate redundant signal conversion block
//  Block '<S58>/FlightSpeed' : Eliminate redundant signal conversion block
//  Block '<S58>/Reshape' : Reshape block reduction
//  Block '<S58>/SideLength' : Eliminate redundant signal conversion block
//  Block '<S139>/Front' : Eliminate redundant signal conversion block
//  Block '<S139>/Right' : Eliminate redundant signal conversion block
//  Block '<S144>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S139>/Up' : Eliminate redundant signal conversion block
//  Block '<S146>/East' : Eliminate redundant signal conversion block
//  Block '<S146>/North' : Eliminate redundant signal conversion block
//  Block '<S146>/Up' : Eliminate redundant signal conversion block


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
//  '<S4>'   : 'ImmedMission/RemoveNaN'
//  '<S5>'   : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision'
//  '<S6>'   : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp'
//  '<S7>'   : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH'
//  '<S8>'   : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr'
//  '<S9>'   : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack'
//  '<S10>'  : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ'
//  '<S11>'  : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU'
//  '<S12>'  : 'ImmedMission/ImmedMissionGuidance/PreemptableMissionModeSelector'
//  '<S13>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance'
//  '<S14>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/Compare To Zero'
//  '<S15>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState'
//  '<S16>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/SelectState'
//  '<S17>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/pdist2'
//  '<S18>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/DivisionByZeroProtection'
//  '<S19>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/MATLAB Function'
//  '<S20>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Radians to Degrees'
//  '<S21>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix'
//  '<S22>'  : 'ImmedMission/ImmedMissionGuidance/AvoidInterPlaneCollision/DynamicCollisionAvoidance/ConstTurnPredState/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S23>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant'
//  '<S24>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128'
//  '<S25>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Calculate Range'
//  '<S26>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Degrees to Radians'
//  '<S27>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/FeedthroughHDG'
//  '<S28>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/HdgHoldLogic'
//  '<S29>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth'
//  '<S30>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/Turning'
//  '<S31>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap'
//  '<S32>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0'
//  '<S33>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem'
//  '<S34>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/pos_rad'
//  '<S35>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S36>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S37>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S38>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S39>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S40>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S41>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S42>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S43>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S44>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S45>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S46>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S47>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S48>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S49>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S50>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S51>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S52>'  : 'ImmedMission/ImmedMissionGuidance/Mode128_DetailedInsp/Mode128_Variant/Mode128/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S53>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant'
//  '<S54>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130'
//  '<S55>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130/Degrees to Radians'
//  '<S56>'  : 'ImmedMission/ImmedMissionGuidance/Mode130_FlightMissionRH/Mode130_Variant/Mode130/RegionalScanMode'
//  '<S57>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant'
//  '<S58>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131'
//  '<S59>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/Cross Product'
//  '<S60>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/Degrees to Radians'
//  '<S61>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth'
//  '<S62>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC'
//  '<S63>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/TriggerCalibrStart'
//  '<S64>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/WayPointGen'
//  '<S65>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap'
//  '<S66>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0'
//  '<S67>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem'
//  '<S68>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/pos_rad'
//  '<S69>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S70>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S71>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S72>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S73>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S74>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S75>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S76>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S77>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S78>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S79>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S80>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S81>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S82>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S83>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S84>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S85>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S86>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S87>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth'
//  '<S88>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap'
//  '<S89>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0'
//  '<S90>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem'
//  '<S91>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/pos_rad'
//  '<S92>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S93>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S94>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S95>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S96>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S97>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S98>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S99>'  : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S100>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S101>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S102>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S103>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S104>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S105>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S106>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S107>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S108>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S109>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/ReadPrevMissionLOC/Prev LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S110>' : 'ImmedMission/ImmedMissionGuidance/Mode131_SqCalibr/Mode131_Variant/Mode131/WayPointGen/BaseWayPoint'
//  '<S111>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant'
//  '<S112>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132'
//  '<S113>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/Calculate Range'
//  '<S114>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth'
//  '<S115>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/WayPointGen'
//  '<S116>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap'
//  '<S117>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0'
//  '<S118>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem'
//  '<S119>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/pos_rad'
//  '<S120>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S121>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S122>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S123>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S124>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S125>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S126>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S127>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S128>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S129>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S130>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S131>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S132>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S133>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S134>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S135>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S136>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S137>' : 'ImmedMission/ImmedMissionGuidance/Mode132_pAttack/Mode132_Variant/Mode132/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
//  '<S138>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant'
//  '<S139>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253'
//  '<S140>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/ConstTurnPred'
//  '<S141>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/DivisionByZeroProtection'
//  '<S142>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Radians to Degrees'
//  '<S143>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Rotation Angles to Direction Cosine Matrix'
//  '<S144>' : 'ImmedMission/ImmedMissionGuidance/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S145>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant'
//  '<S146>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254'
//  '<S147>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/Degrees to Radians'
//  '<S148>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance'
//  '<S149>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift'
//  '<S150>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/SailShift'
//  '<S151>' : 'ImmedMission/ImmedMissionGuidance/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/SailShift/Degrees to Radians'
//  '<S152>' : 'ImmedMission/LatLon2NorthEast/Degrees to Radians'
//  '<S153>' : 'ImmedMission/LatLon2NorthEast/Degrees to Radians1'
//  '<S154>' : 'ImmedMission/LatLon2NorthEast/Degrees to Radians2'
//  '<S155>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth'
//  '<S156>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap'
//  '<S157>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0'
//  '<S158>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem'
//  '<S159>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/pos_rad'
//  '<S160>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S161>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S162>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S163>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S164>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S165>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S166>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S167>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S168>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S169>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S170>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S171>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S172>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Angle Conversion2'
//  '<S173>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance'
//  '<S174>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
//  '<S175>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
//  '<S176>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
//  '<S177>' : 'ImmedMission/LatLon2NorthEast/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'

#endif                                 // RTW_HEADER_ImmedMission_h_

//
// File trailer for generated code.
//
// [EOF]
//
