//
// File: MissionUAV.cpp
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 1.18
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Jul  2 07:51:54 2021
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
#include "MissionUAV.h"
#include "MissionUAV_private.h"
#include "rt_atan2d_snf.h"

// Forward declaration for local functions
static void MissionUAV_Model_resetImpl
    (robotics_core_internal_system_navigation_Model_MissionUAV_T *obj);
static void MissionUAV_Model_resetImpl
    (robotics_core_internal_system_navigation_Model_MissionUAV_T *obj)
{
    obj->ModelImpl.Configuration.PHeight = 3.9;
    obj->ModelImpl.Configuration.PFlightPathAngle = 39.0;
    obj->ModelImpl.Configuration.PAirSpeed = 0.39;
    obj->ModelImpl.Configuration.PHeight = 2.73;
    obj->ModelImpl.Configuration.PFlightPathAngle = 11.7;
    obj->ModelImpl.Configuration.PAirSpeed = 0.3;
    obj->ModelImpl.Configuration.PDRoll[0] = 3402.9722249999991;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -1.5707963267948966;
    obj->ModelImpl.Configuration.PDRoll[0] = 100.0;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -0.21109333322274654;
    obj->ModelImpl.Configuration.PDRoll[1] = 116.66999999999999;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 1.5707963267948966;
    obj->ModelImpl.Configuration.PDRoll[1] = 10.0;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 0.21109333322274654;
}

// System initialize for referenced model: 'MissionUAV'
void MissionUAV_Init(RT_MODEL_MissionUAV_T * const MissionUAV_M,
                     DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX)
{
    if (rtmIsFirstInitCond(MissionUAV_M)) {
        std::memset(&localX->Integrator_CSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));
    }

    localDW->Integrator_IWORK = 1;
    localX->TD_Bank_CSTATE = 0.0;
    localX->dotBankTD_CSTATE = 0.0;
    localDW->objisempty_g = true;
    localDW->obj_e.isInitialized = 1;
    MissionUAV_Model_resetImpl(&localDW->obj_e);
    MissionUAV_Model_resetImpl(&localDW->obj_e);
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
    localDW->obj.OutputTemplate.North = 0.0;
    localDW->obj.OutputTemplate.East = 0.0;
    localDW->obj.OutputTemplate.Height = 0.0;
    localDW->obj.OutputTemplate.AirSpeed = 0.0;
    localDW->obj.OutputTemplate.HeadingAngle = 0.0;
    localDW->obj.OutputTemplate.FlightPathAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngleRate = 0.0;
}

// Outputs for referenced model: 'MissionUAV'
void MissionUAV(RT_MODEL_MissionUAV_T * const MissionUAV_M, const real_T
                *rtu_ResetState, const real_T rtu_StartPos[8], const real_T
                *rtu_UAVGuidanceCmd_Height, const real_T
                *rtu_UAVGuidanceCmd_AirSpeed, const real_T
                *rtu_UAVGuidanceCmd_HeadingAngle, real_T *rty_SimUAVState_North,
                real_T *rty_SimUAVState_East, real_T *rty_SimUAVState_Height,
                real_T *rty_SimUAVState_AirSpeed, real_T
                *rty_SimUAVState_HeadingAngle, real_T
                *rty_SimUAVState_FlightPathAngle, real_T
                *rty_SimUAVState_RollAngle, real_T
                *rty_SimUAVState_RollAngleRate, DW_MissionUAV_f_T *localDW,
                X_MissionUAV_n_T *localX)
{
    real_T b;
    real_T b_tmp;
    real_T d;
    real_T q;
    real_T rtb_ZeroOrderHold_AirSpeed;
    real_T rtb_ZeroOrderHold_East;
    real_T rtb_ZeroOrderHold_FlightPathAngle;
    real_T rtb_ZeroOrderHold_HeadingAngle;
    real_T rtb_ZeroOrderHold_Height;
    real_T rtb_ZeroOrderHold_North;
    real_T rtb_ZeroOrderHold_RollAngle;
    real_T rtb_ZeroOrderHold_RollAngleRate;
    real_T skySpeed;
    real_T tmp;
    real_T y;
    boolean_T rEQ0;
    rEQ0 = rtsiGetIsOkayToUpdateMode(MissionUAV_M->solverInfo);
    if (rEQ0 && (static_cast<boolean_T>(static_cast<int32_T>((*rtu_ResetState !=
            0.0) | (localDW->Integrator_IWORK != 0))))) {
        // evaluate the level of the reset signal
        std::memcpy(&localX->Integrator_CSTATE[0], &rtu_StartPos[0],
                    static_cast<uint32_T>(sizeof(real_T) << 3U));
    }

    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        localDW->FixedWingGuidanceEnvironmentBus_h.WindNorth = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_h.WindEast = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_h.WindDown = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_h.Gravity = 9.807;
        y = *rtu_UAVGuidanceCmd_AirSpeed;
        if (y > 40.0) {
            localDW->SlewGuidanceBus.AirSpeed = 40.0;
        } else if (y < 30.0) {
            localDW->SlewGuidanceBus.AirSpeed = 30.0;
        } else {
            localDW->SlewGuidanceBus.AirSpeed = y;
        }

        localDW->SlewGuidanceBus.Height = *rtu_UAVGuidanceCmd_Height;
        localDW->SlewGuidanceBus.RollAngle = localX->TD_Bank_CSTATE;
    }

    y = std::cos(localX->Integrator_CSTATE[5]);
    d = std::cos(localX->Integrator_CSTATE[4]);
    skySpeed = std::sin(localX->Integrator_CSTATE[4]);
    q = std::sin(localX->Integrator_CSTATE[5]);
    b = (-(d * y) * localDW->FixedWingGuidanceEnvironmentBus_h.WindNorth +
         -(skySpeed * y) * localDW->FixedWingGuidanceEnvironmentBus_h.WindEast)
        + q * localDW->FixedWingGuidanceEnvironmentBus_h.WindDown;
    b_tmp = ((localDW->FixedWingGuidanceEnvironmentBus_h.WindNorth *
              localDW->FixedWingGuidanceEnvironmentBus_h.WindNorth +
              localDW->FixedWingGuidanceEnvironmentBus_h.WindEast *
              localDW->FixedWingGuidanceEnvironmentBus_h.WindEast) +
             localDW->FixedWingGuidanceEnvironmentBus_h.WindDown *
             localDW->FixedWingGuidanceEnvironmentBus_h.WindDown) -
        localX->Integrator_CSTATE[3] * localX->Integrator_CSTATE[3];
    b = std::sqrt(b * b - b_tmp) + -b;
    localDW->ComputeDerivative[0] = b * d * y;
    localDW->ComputeDerivative[1] = b * skySpeed * y;
    localDW->ComputeDerivative[2] = b * q;
    localDW->ComputeDerivative[3] = (localDW->SlewGuidanceBus.AirSpeed -
        localX->Integrator_CSTATE[3]) *
        localDW->obj_e.ModelImpl.Configuration.PAirSpeed;
    if (b == 0.0) {
        localDW->ComputeDerivative[4] = 0.0;
        localDW->ComputeDerivative[5] = 0.0;
    } else {
        if (localX->Integrator_CSTATE[3] == 0.0) {
            localDW->ComputeDerivative[4] = 0.0;
        } else {
            y = 1.0 / (std::cos(std::asin((b * std::sin
                          (localX->Integrator_CSTATE[5]) +
                          localDW->FixedWingGuidanceEnvironmentBus_h.WindDown) /
                         localX->Integrator_CSTATE[3])) *
                       localX->Integrator_CSTATE[3]);
            localDW->ComputeDerivative[4] = std::cos(std::asin(y *
                localDW->FixedWingGuidanceEnvironmentBus_h.WindNorth * -skySpeed
                + y * localDW->FixedWingGuidanceEnvironmentBus_h.WindEast * d)) *
                (localDW->FixedWingGuidanceEnvironmentBus_h.Gravity / b * std::
                 tan(localX->Integrator_CSTATE[6]));
        }

        localDW->ComputeDerivative[5] = (std::fmax(std::fmin(std::asin(std::fmax
            (std::fmin((localDW->SlewGuidanceBus.Height -
                        localX->Integrator_CSTATE[2]) *
                       localDW->obj_e.ModelImpl.Configuration.PHeight / b, 1.0),
             -1.0)),
            localDW->obj_e.ModelImpl.Configuration.FlightPathAngleLimits[1]),
            localDW->obj_e.ModelImpl.Configuration.FlightPathAngleLimits[0]) -
            localX->Integrator_CSTATE[5]) *
            localDW->obj_e.ModelImpl.Configuration.PFlightPathAngle;
    }

    localDW->ComputeDerivative[6] = localX->Integrator_CSTATE[7];
    localDW->ComputeDerivative[7] = (std::fmax(std::fmin
        (localDW->SlewGuidanceBus.RollAngle, 1.5707963267948966),
        -1.5707963267948966) - localX->Integrator_CSTATE[6]) *
        localDW->obj_e.ModelImpl.Configuration.PDRoll[0] +
        localDW->obj_e.ModelImpl.Configuration.PDRoll[1] *
        -localX->Integrator_CSTATE[7];
    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        rtb_ZeroOrderHold_North = localX->Integrator_CSTATE[0];
        rtb_ZeroOrderHold_East = localX->Integrator_CSTATE[1];
        rtb_ZeroOrderHold_Height = localX->Integrator_CSTATE[2];
        rtb_ZeroOrderHold_AirSpeed = localX->Integrator_CSTATE[3];
        rtb_ZeroOrderHold_HeadingAngle = localX->Integrator_CSTATE[4];
        rtb_ZeroOrderHold_FlightPathAngle = localX->Integrator_CSTATE[5];
        rtb_ZeroOrderHold_RollAngle = localX->Integrator_CSTATE[6];
        rtb_ZeroOrderHold_RollAngleRate = localX->Integrator_CSTATE[7];
        y = 1.0 / localX->Integrator_CSTATE[3];
        b = std::cos(localX->Integrator_CSTATE[5]);
        tmp = std::cos(localX->Integrator_CSTATE[4]);
        b = (tmp * b * localDW->FixedWingGuidanceEnvironmentBus_h.WindNorth +
             skySpeed * b * localDW->FixedWingGuidanceEnvironmentBus_h.WindEast)
            + -q * localDW->FixedWingGuidanceEnvironmentBus_h.WindDown;
        d = *rtu_UAVGuidanceCmd_HeadingAngle - localX->Integrator_CSTATE[4];
        if (std::abs(d) > 3.1415926535897931) {
            if (std::isnan(d + 3.1415926535897931)) {
                skySpeed = (rtNaN);
            } else if (std::isinf(d + 3.1415926535897931)) {
                skySpeed = (rtNaN);
            } else if (d + 3.1415926535897931 == 0.0) {
                skySpeed = 0.0;
            } else {
                skySpeed = std::fmod(d + 3.1415926535897931, 6.2831853071795862);
                rEQ0 = (skySpeed == 0.0);
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rEQ0) ^ 1))) {
                    q = std::abs((d + 3.1415926535897931) / 6.2831853071795862);
                    rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs
                        (q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^
                        1));
                }

                if (rEQ0) {
                    skySpeed = 0.0;
                } else if (d + 3.1415926535897931 < 0.0) {
                    skySpeed += 6.2831853071795862;
                }
            }

            if (static_cast<boolean_T>(static_cast<int32_T>((skySpeed == 0.0) &
                    (d + 3.1415926535897931 > 0.0)))) {
                skySpeed = 6.2831853071795862;
            }

            d = skySpeed - 3.1415926535897931;
        }

        y = rt_atan2d_snf((std::sqrt(b * b - b_tmp) + -b) * (0.39 * d), std::cos
                          (localX->Integrator_CSTATE[4] -
                           (localX->Integrator_CSTATE[4] - std::asin(y *
                             localDW->FixedWingGuidanceEnvironmentBus_h.WindNorth
                             * -std::sin(localX->Integrator_CSTATE[4]) + y *
                             localDW->FixedWingGuidanceEnvironmentBus_h.WindEast
                             * tmp))) *
                          localDW->FixedWingGuidanceEnvironmentBus_h.Gravity);
        if (y > 0.3490658503988659) {
            localDW->RollAngle = 0.3490658503988659;
        } else if (y < -0.3490658503988659) {
            localDW->RollAngle = -0.3490658503988659;
        } else {
            localDW->RollAngle = y;
        }
    }

    localDW->dotBankTD = localX->dotBankTD_CSTATE;
    b = localDW->dotBankTD * 0.1;
    y = (localX->TD_Bank_CSTATE - localDW->RollAngle) + b;
    if (y < 0.0) {
        d = -1.0;
    } else if (y > 0.0) {
        d = 1.0;
    } else if (y == 0.0) {
        d = 0.0;
    } else {
        d = (rtNaN);
    }

    skySpeed = (std::sqrt((8.0 * std::abs(y) + 0.0017453292519943296) *
                          0.0017453292519943296) - 0.0017453292519943296) * d /
        2.0 + b;
    if (y + 0.0017453292519943296 < 0.0) {
        d = -1.0;
    } else if (y + 0.0017453292519943296 > 0.0) {
        d = 1.0;
    } else if (y + 0.0017453292519943296 == 0.0) {
        d = 0.0;
    } else {
        d = (rtNaN);
    }

    if (y - 0.0017453292519943296 < 0.0) {
        q = -1.0;
    } else if (y - 0.0017453292519943296 > 0.0) {
        q = 1.0;
    } else if (y - 0.0017453292519943296 == 0.0) {
        q = 0.0;
    } else {
        q = (rtNaN);
    }

    b = ((b + y) - skySpeed) * ((d - q) / 2.0) + skySpeed;
    if (b < 0.0) {
        y = -1.0;
    } else if (b > 0.0) {
        y = 1.0;
    } else if (b == 0.0) {
        y = 0.0;
    } else {
        y = (rtNaN);
    }

    if (b + 0.0017453292519943296 < 0.0) {
        d = -1.0;
    } else if (b + 0.0017453292519943296 > 0.0) {
        d = 1.0;
    } else if (b + 0.0017453292519943296 == 0.0) {
        d = 0.0;
    } else {
        d = (rtNaN);
    }

    if (b - 0.0017453292519943296 < 0.0) {
        q = -1.0;
    } else if (b - 0.0017453292519943296 > 0.0) {
        q = 1.0;
    } else if (b - 0.0017453292519943296 == 0.0) {
        q = 0.0;
    } else {
        q = (rtNaN);
    }

    localDW->fh = (b / 0.0017453292519943296 - y) * -0.17453292519943295 * ((d -
        q) / 2.0) - 0.17453292519943295 * y;
    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        *rty_SimUAVState_North = rtb_ZeroOrderHold_North;
        *rty_SimUAVState_East = rtb_ZeroOrderHold_East;
        *rty_SimUAVState_Height = rtb_ZeroOrderHold_Height;
        *rty_SimUAVState_AirSpeed = rtb_ZeroOrderHold_AirSpeed;
        *rty_SimUAVState_HeadingAngle = rtb_ZeroOrderHold_HeadingAngle;
        *rty_SimUAVState_FlightPathAngle = rtb_ZeroOrderHold_FlightPathAngle;
        *rty_SimUAVState_RollAngle = rtb_ZeroOrderHold_RollAngle;
        *rty_SimUAVState_RollAngleRate = rtb_ZeroOrderHold_RollAngleRate;
    }
}

// Update for referenced model: 'MissionUAV'
void MissionUAV_Update(DW_MissionUAV_f_T *localDW)
{
    localDW->Integrator_IWORK = 0;
}

// Derivatives for referenced model: 'MissionUAV'
void MissionUAV_Deriv(const real_T *rtu_ResetState, DW_MissionUAV_f_T *localDW,
                      XDot_MissionUAV_n_T *localXdot)
{
    if (*rtu_ResetState == 0.0) {
        std::memcpy(&localXdot->Integrator_CSTATE[0],
                    &localDW->ComputeDerivative[0], static_cast<uint32_T>(sizeof
                     (real_T) << 3U));
    } else {
        // level reset is active
        std::memset(&localXdot->Integrator_CSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));
    }

    localXdot->TD_Bank_CSTATE = localDW->dotBankTD;
    localXdot->dotBankTD_CSTATE = localDW->fh;
}

// Model initialize function
void MissionUAV_initialize(const char_T **rt_errorStatus, boolean_T
    *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
    *timingBridge, RT_MODEL_MissionUAV_T *const MissionUAV_M, ZCE_MissionUAV_T
    *localZCE)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));
    MissionUAV_M->timingBridge = (timingBridge);

    // initialize error status
    rtmSetErrorStatusPointer(MissionUAV_M, rt_errorStatus);

    // initialize stop requested flag
    rtmSetStopRequestedPtr(MissionUAV_M, rt_stopRequested);

    // initialize RTWSolverInfo
    MissionUAV_M->solverInfo = (rt_solverInfo);

    // Set the Timing fields to the appropriate data in the RTWSolverInfo
    rtmSetSimTimeStepPointer(MissionUAV_M, rtsiGetSimTimeStepPtr
        (MissionUAV_M->solverInfo));
    MissionUAV_M->Timing.stepSize0 = (rtsiGetStepSize(MissionUAV_M->solverInfo));
    localZCE->Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
}

//
// File trailer for generated code.
//
// [EOF]
//
