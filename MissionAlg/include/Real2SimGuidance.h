#ifndef RTW_HEADER_Real2SimGuidance_h_
#define RTW_HEADER_Real2SimGuidance_h_
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Real2SimGuidance_types.h"
#include "rt_nonfinite.h"
#include "rtw_linux.h"

struct DW_Real2SimGuidance_f_T {
    uav_sluav_internal_system_WaypointFollower_Real2SimGuidance_T obj;
    real_T NorthEastHeight[3];
    real_T EastSequence_X[72];
    real_T HeightSequence_X[72];
    real_T NorthSequence_X[72];
    real_T Heading_Log[3];
    real_T RateLimiter;
    real_T BiasHSwitch;
    real_T dotAltTD;
    real_T fh;
    real_T InverseY;
    real_T InverseR;
    real_T dotTD;
    real_T GainADRCinvb0;
    real_T SumY;
    real_T fh_p;
    real_T ESO;
    real_T ESO_dot;
    real_T ESO_dotdot;
    real_T TrackInvH;
    real_T ADRC_U_Log;
    real_T CrossTrackError;
    real_T FlightMode_Log;
    real_T LagDistance;
    real_T biasH_Log;
    real_T PrevY;
    real_T MemoryRefHeight_PreviousInput;
    int32_T chartAbsoluteTimeCounter;
    int32_T durationLastReferenceTick_1;
    uint16_T temporalCounter_i1;
    uint8_T Status_Log;
    uint8_T is_active_c34_Real2SimGuidance;
    uint8_T is_c34_Real2SimGuidance;
    uint8_T is_DebounceExecution;
    uint8_T is_Persuit;
    uint8_T is_Debounce;
    uint8_T temporalCounter_i2;
    uint8_T is_active_c16_Real2SimGuidance;
    uint8_T is_c16_Real2SimGuidance;
    boolean_T Terminate;
    boolean_T Compare_e;
    boolean_T condWasTrueAtLastTimeStep_1;
    boolean_T objisempty;
    boolean_T ESO_MODE;
};

struct X_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;
    real_T dotAltTD_CSTATE;
    real_T TD_AirSpdADRC_CSTATE;
    real_T dotTD_CSTATE;
    real_T ESO_CSTATE;
    real_T ESO_dot_CSTATE;
    real_T ESO_dotdot_CSTATE;
};

struct XDot_Real2SimGuidance_n_T {
    real_T TD_Alt_CSTATE;
    real_T dotAltTD_CSTATE;
    real_T TD_AirSpdADRC_CSTATE;
    real_T dotTD_CSTATE;
    real_T ESO_CSTATE;
    real_T ESO_dot_CSTATE;
    real_T ESO_dotdot_CSTATE;
};

struct XDis_Real2SimGuidance_n_T {
    boolean_T TD_Alt_CSTATE;
    boolean_T dotAltTD_CSTATE;
    boolean_T TD_AirSpdADRC_CSTATE;
    boolean_T dotTD_CSTATE;
    boolean_T ESO_CSTATE;
    boolean_T ESO_dot_CSTATE;
    boolean_T ESO_dotdot_CSTATE;
};

struct tag_RTM_Real2SimGuidance_T {
    const char_T **errorStatus;
    RTWSolverInfo *solverInfo;
    struct {
        time_T stepSize0;
        SimTimeStep *simTimeStep;
        boolean_T *stopRequestedFlag;
    } Timing;
};

struct MdlrefDW_Real2SimGuidance_T {
    DW_Real2SimGuidance_f_T rtdw;
    RT_MODEL_Real2SimGuidance_T rtm;
};

extern real_T AltitudeGCS;
extern real_T LatitudeGCS;
extern real_T LongitudeGCS;
extern void Real2SimGuidance_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_Real2SimGuidance_T
    *const Real2SimGuidance_M);
extern void Real2SimGuidance_fale025h(real_T rtu_u, real_T rtu_u_j, real_T
    rtu_u_e, real_T *rty_y);
extern void Real2SimGuidance_Init(DW_Real2SimGuidance_f_T *localDW,
    X_Real2SimGuidance_n_T *localX);
extern void Real2SimGuidance_Deriv(DW_Real2SimGuidance_f_T *localDW,
    XDot_Real2SimGuidance_n_T *localXdot);
extern void Real2SimGuidance_Disable(DW_Real2SimGuidance_f_T *localDW);
extern void Real2SimGuidance_Update(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const FixedWingGuidanceStateBus *rtu_SimUAVState,
    DW_Real2SimGuidance_f_T *localDW);
extern void Real2SimGuidance(RT_MODEL_Real2SimGuidance_T * const
    Real2SimGuidance_M, const FixedWingGuidanceStateBus *rtu_SimUAVState, const
    boolean_T *rtu_ImmedModeSwitch, const RealUAVStateBus
    *rtu_RealUAVLatLonState, const uint8_T *rtu_FlightMode, const real_T
    *rtu_GroundSpd, const boolean_T rtu_ControlSwitch[2], const
    FixedWingGuidanceBus *rtu_ImmedGuidanceCMD, const MissionModes
    *rtu_thisTaskStatus_MissionMode, const int32_T *rtu_thisTaskStatus_numUAV,
    const int32_T *rtu_thisTaskStatus_FormationPos, LookAheadPoint
    *rty_LookAheadPoint, real_T *rty_RefAirspeed, real_T *rty_ExecutionTrigger,
    boolean_T *rty_EngagedFlag, FixedWingGuidanceStateBus *rty_RealUAVState,
    DW_Real2SimGuidance_f_T *localDW, X_Real2SimGuidance_n_T *localX);

#endif

