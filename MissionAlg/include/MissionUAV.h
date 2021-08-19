#ifndef RTW_HEADER_MissionUAV_h_
#define RTW_HEADER_MissionUAV_h_
#include <cmath>
#include <cstring>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MissionUAV_types.h"

#include "model_reference_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

struct DW_MissionUAV_f_T {
    robotics_core_internal_system_navigation_StateVector2Struct_MissionUAV_T obj;
    robotics_core_internal_system_navigation_Model_MissionUAV_T obj_e;
    FixedWingGuidanceEnvironmentBus FixedWingGuidanceEnvironmentBus_h;
    FixedWingGuidanceControlBus SlewGuidanceBus;
    real_T ComputeDerivative[8];
    real_T RollAngle;
    real_T dotBankTD;
    real_T fh;
    int_T Integrator_IWORK;
    boolean_T objisempty;
    boolean_T objisempty_g;
};

struct X_MissionUAV_n_T {
    real_T Integrator_CSTATE[8];
    real_T TD_Bank_CSTATE;
    real_T dotBankTD_CSTATE;
};

struct XDot_MissionUAV_n_T {
    real_T Integrator_CSTATE[8];
    real_T TD_Bank_CSTATE;
    real_T dotBankTD_CSTATE;
};

struct XDis_MissionUAV_n_T {
    boolean_T Integrator_CSTATE[8];
    boolean_T TD_Bank_CSTATE;
    boolean_T dotBankTD_CSTATE;
};

struct ZCE_MissionUAV_T {
    ZCSigState Integrator_Reset_ZCE;
};

struct tag_RTM_MissionUAV_T {
    const char_T **errorStatus;
    RTWSolverInfo *solverInfo;
    const rtTimingBridge *timingBridge;
    struct {
        time_T stepSize0;
        SimTimeStep *simTimeStep;
        boolean_T *stopRequestedFlag;
    } Timing;
};

struct MdlrefDW_MissionUAV_T {
    DW_MissionUAV_f_T rtdw;
    RT_MODEL_MissionUAV_T rtm;
    ZCE_MissionUAV_T rtzce;
};

extern void MissionUAV_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
    *timingBridge, RT_MODEL_MissionUAV_T *const MissionUAV_M, ZCE_MissionUAV_T
    *localZCE);
extern void MissionUAV_Init(RT_MODEL_MissionUAV_T * const MissionUAV_M,
    DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX);
extern void MissionUAV_Deriv(const real_T *rtu_ResetState, DW_MissionUAV_f_T
    *localDW, XDot_MissionUAV_n_T *localXdot);
extern void MissionUAV_Update(DW_MissionUAV_f_T *localDW);
extern void MissionUAV(RT_MODEL_MissionUAV_T * const MissionUAV_M, const real_T *
                       rtu_ResetState, const real_T rtu_StartPos[8], const
                       real_T *rtu_UAVGuidanceCmd_Height, const real_T
                       *rtu_UAVGuidanceCmd_AirSpeed, const real_T
                       *rtu_UAVGuidanceCmd_HeadingAngle, real_T
                       *rty_SimUAVState_North, real_T *rty_SimUAVState_East,
                       real_T *rty_SimUAVState_Height, real_T
                       *rty_SimUAVState_AirSpeed, real_T
                       *rty_SimUAVState_HeadingAngle, real_T
                       *rty_SimUAVState_FlightPathAngle, real_T
                       *rty_SimUAVState_RollAngle, real_T
                       *rty_SimUAVState_RollAngleRate, DW_MissionUAV_f_T
                       *localDW, X_MissionUAV_n_T *localX);

#endif

