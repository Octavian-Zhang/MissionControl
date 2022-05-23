//
// File: MissionUAV.cpp
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun May 22 08:36:10 2022
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
#include "rtwtypes.h"
#include "MissionUAV_types.h"
#include <cstring>
#include <cmath>
#include "rt_atan2d_snf.h"
#include "MissionUAV_private.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Forward declaration for local functions
    static void MissionUAV_Model_resetImpl
    (robotics_core_internal_system_navigation_Model_MissionUAV_T *obj);

static void MissionUAV_Model_resetImpl
    (robotics_core_internal_system_navigation_Model_MissionUAV_T *obj)
{
    obj->ModelImpl.Configuration.PHeight = 3.9;
    obj->ModelImpl.Configuration.PFlightPathAngle = 39.0;
    obj->ModelImpl.Configuration.PAirSpeed = 0.39;
    obj->ModelImpl.Configuration.PHeight = 4.0;
    obj->ModelImpl.Configuration.PFlightPathAngle = 12.0;
    obj->ModelImpl.Configuration.PAirSpeed = 1.0;
    obj->ModelImpl.Configuration.PDRoll[0] = 3402.9722249999991;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -1.5707963267948966;
    obj->ModelImpl.Configuration.PDRoll[0] = 300.0;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[0] = -0.70862627212767026;
    obj->ModelImpl.Configuration.PDRoll[1] = 116.66999999999999;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 1.5707963267948966;
    obj->ModelImpl.Configuration.PDRoll[1] = 30.0;
    obj->ModelImpl.Configuration.FlightPathAngleLimits[1] = 0.70862627212767026;
}

// System initialize for referenced model: 'MissionUAV'
void MissionUAV_Init(RT_MODEL_MissionUAV_T * const MissionUAV_M,
                     DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX)
{
    // InitializeConditions for Integrator: '<S2>/Integrator'
    if (rtmIsFirstInitCond(MissionUAV_M)) {
        std::memset(&localX->Integrator_CSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));
    }

    localDW->Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S2>/Integrator'

    // InitializeConditions for Integrator: '<S4>/TD_Bank'
    localX->TD_Bank_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S4>/dotBankTD'
    localX->dotBankTD_CSTATE = 0.0;

    // Start for MATLABSystem: '<S2>/ComputeDerivative'
    localDW->objisempty_a = true;
    localDW->obj_j.isInitialized = 1;
    MissionUAV_Model_resetImpl(&localDW->obj_j);

    // InitializeConditions for MATLABSystem: '<S2>/ComputeDerivative'
    MissionUAV_Model_resetImpl(&localDW->obj_j);

    // Start for MATLABSystem: '<S2>/StateVector2Struct'
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;

    // InitializeConditions for MATLABSystem: '<S2>/StateVector2Struct'
    localDW->obj.OutputTemplate.North = 0.0;
    localDW->obj.OutputTemplate.East = 0.0;
    localDW->obj.OutputTemplate.Height = 0.0;
    localDW->obj.OutputTemplate.AirSpeed = 0.0;
    localDW->obj.OutputTemplate.HeadingAngle = 0.0;
    localDW->obj.OutputTemplate.FlightPathAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngle = 0.0;
    localDW->obj.OutputTemplate.RollAngleRate = 0.0;
}

// System reset for referenced model: 'MissionUAV'
void MissionUAV_Reset(RT_MODEL_MissionUAV_T * const MissionUAV_M,
                      DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX)
{
    // InitializeConditions for Integrator: '<S2>/Integrator'
    if (rtmIsFirstInitCond(MissionUAV_M)) {
        std::memset(&localX->Integrator_CSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));
    }

    localDW->Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S2>/Integrator'

    // InitializeConditions for Integrator: '<S4>/TD_Bank'
    localX->TD_Bank_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S4>/dotBankTD'
    localX->dotBankTD_CSTATE = 0.0;

    // InitializeConditions for MATLABSystem: '<S2>/ComputeDerivative'
    MissionUAV_Model_resetImpl(&localDW->obj_j);

    // InitializeConditions for MATLABSystem: '<S2>/StateVector2Struct'
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
    real_T a0;
    real_T q;
    real_T rtb_AirSpeed_n;
    real_T rtb_AirSpeed_p_tmp;
    real_T rtb_ZeroOrderHold_AirSpeed;
    real_T rtb_ZeroOrderHold_East;
    real_T rtb_ZeroOrderHold_FlightPathAngle;
    real_T rtb_ZeroOrderHold_HeadingAngle;
    real_T rtb_ZeroOrderHold_Height;
    real_T rtb_ZeroOrderHold_North;
    real_T rtb_ZeroOrderHold_RollAngle;
    real_T rtb_ZeroOrderHold_RollAngleRate;
    real_T skySpeed;
    real_T y;
    real_T y_tmp;

    // RateTransition: '<S1>/Rate Transition'
    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        // RateTransition: '<S1>/Rate Transition'
        std::memcpy(&localDW->RateTransition[0], &rtu_StartPos[0],
                    static_cast<uint32_T>(sizeof(real_T) << 3U));

        // BusCreator: '<S1>/FixedWingGuidanceEnvironmentBus' incorporates:
        //   Constant: '<S1>/Gravity'
        //   Constant: '<S1>/NoWind'

        localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_p.WindEast = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_p.WindDown = 0.0;
        localDW->FixedWingGuidanceEnvironmentBus_p.Gravity = 9.807;

        // Saturate: '<S1>/AirspeedSaturation'
        rtb_AirSpeed_n = *rtu_UAVGuidanceCmd_AirSpeed;
        if (rtb_AirSpeed_n > 40.0) {
            rtb_AirSpeed_n = 40.0;
        } else if (rtb_AirSpeed_n < 30.0) {
            rtb_AirSpeed_n = 30.0;
        }

        // End of Saturate: '<S1>/AirspeedSaturation'
    }

    // End of RateTransition: '<S1>/Rate Transition'

    // Integrator: '<S2>/Integrator' incorporates:
    //   Integrator: '<S4>/TD_Bank'

    if (rtsiIsModeUpdateTimeStep(MissionUAV_M->solverInfo)) {
        // evaluate the level of the reset signal
        if (static_cast<boolean_T>(static_cast<int32_T>((*rtu_ResetState != 0.0)
              | (localDW->Integrator_IWORK != 0)))) {
            std::memcpy(&localX->Integrator_CSTATE[0], &localDW->RateTransition
                        [0], static_cast<uint32_T>(sizeof(real_T) << 3U));
        }

        // evaluate the level of the reset signal
        if (*rtu_ResetState != 0.0) {
            localX->TD_Bank_CSTATE = 0.0;
        }
    }

    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        // BusCreator: '<S1>/SlewGuidanceBus' incorporates:
        //   Integrator: '<S4>/TD_Bank'

        localDW->SlewGuidanceBus.Height = *rtu_UAVGuidanceCmd_Height;
        localDW->SlewGuidanceBus.AirSpeed = rtb_AirSpeed_n;
        localDW->SlewGuidanceBus.RollAngle = localX->TD_Bank_CSTATE;
    }

    // MATLABSystem: '<S2>/ComputeDerivative' incorporates:
    //   Integrator: '<S2>/Integrator'
    //   MATLAB Function: '<S1>/SimHdgControl'

    a0 = std::cos(localX->Integrator_CSTATE[5]);
    y_tmp = std::cos(localX->Integrator_CSTATE[4]);
    skySpeed = std::sin(localX->Integrator_CSTATE[4]);
    q = std::sin(localX->Integrator_CSTATE[5]);
    y = (-(y_tmp * a0) * localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth +
         -(skySpeed * a0) * localDW->FixedWingGuidanceEnvironmentBus_p.WindEast)
        + q * localDW->FixedWingGuidanceEnvironmentBus_p.WindDown;
    rtb_AirSpeed_p_tmp = ((localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth *
                           localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth
                           + localDW->FixedWingGuidanceEnvironmentBus_p.WindEast
                           * localDW->FixedWingGuidanceEnvironmentBus_p.WindEast)
                          + localDW->FixedWingGuidanceEnvironmentBus_p.WindDown *
                          localDW->FixedWingGuidanceEnvironmentBus_p.WindDown) -
        localX->Integrator_CSTATE[3] * localX->Integrator_CSTATE[3];
    rtb_AirSpeed_n = std::sqrt(y * y - rtb_AirSpeed_p_tmp) + -y;
    localDW->ComputeDerivative[0] = rtb_AirSpeed_n * y_tmp * a0;
    localDW->ComputeDerivative[1] = rtb_AirSpeed_n * skySpeed * a0;
    localDW->ComputeDerivative[2] = rtb_AirSpeed_n * q;
    localDW->ComputeDerivative[3] = (localDW->SlewGuidanceBus.AirSpeed -
        localX->Integrator_CSTATE[3]) *
        localDW->obj_j.ModelImpl.Configuration.PAirSpeed;
    if (rtb_AirSpeed_n == 0.0) {
        localDW->ComputeDerivative[4] = 0.0;
        localDW->ComputeDerivative[5] = 0.0;
    } else {
        if (localX->Integrator_CSTATE[3] == 0.0) {
            localDW->ComputeDerivative[4] = 0.0;
        } else {
            a0 = 1.0 / (std::cos(std::asin((rtb_AirSpeed_n * std::sin
                           (localX->Integrator_CSTATE[5]) +
                           localDW->FixedWingGuidanceEnvironmentBus_p.WindDown) /
                          localX->Integrator_CSTATE[3])) *
                        localX->Integrator_CSTATE[3]);
            localDW->ComputeDerivative[4] = std::cos(std::asin(a0 *
                localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth * -skySpeed
                + a0 * localDW->FixedWingGuidanceEnvironmentBus_p.WindEast *
                y_tmp)) * (localDW->FixedWingGuidanceEnvironmentBus_p.Gravity /
                           rtb_AirSpeed_n * std::tan(localX->Integrator_CSTATE[6]));
        }

        localDW->ComputeDerivative[5] = (std::fmax(std::fmin(std::asin(std::fmax
            (std::fmin((localDW->SlewGuidanceBus.Height -
                        localX->Integrator_CSTATE[2]) *
                       localDW->obj_j.ModelImpl.Configuration.PHeight /
                       rtb_AirSpeed_n, 1.0), -1.0)),
            localDW->obj_j.ModelImpl.Configuration.FlightPathAngleLimits[1]),
            localDW->obj_j.ModelImpl.Configuration.FlightPathAngleLimits[0]) -
            localX->Integrator_CSTATE[5]) *
            localDW->obj_j.ModelImpl.Configuration.PFlightPathAngle;
    }

    localDW->ComputeDerivative[6] = localX->Integrator_CSTATE[7];
    localDW->ComputeDerivative[7] = (std::fmax(std::fmin
        (localDW->SlewGuidanceBus.RollAngle, 1.5707963267948966),
        -1.5707963267948966) - localX->Integrator_CSTATE[6]) *
        localDW->obj_j.ModelImpl.Configuration.PDRoll[0] +
        localDW->obj_j.ModelImpl.Configuration.PDRoll[1] *
        -localX->Integrator_CSTATE[7];

    // End of MATLABSystem: '<S2>/ComputeDerivative'
    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        real_T rtb_AirSpeed_p_tmp_0;

        // ZeroOrderHold: '<S1>/Zero-Order Hold' incorporates:
        //   Integrator: '<S2>/Integrator'

        rtb_ZeroOrderHold_North = localX->Integrator_CSTATE[0];
        rtb_ZeroOrderHold_East = localX->Integrator_CSTATE[1];
        rtb_ZeroOrderHold_Height = localX->Integrator_CSTATE[2];
        rtb_ZeroOrderHold_AirSpeed = localX->Integrator_CSTATE[3];
        rtb_ZeroOrderHold_HeadingAngle = localX->Integrator_CSTATE[4];
        rtb_ZeroOrderHold_FlightPathAngle = localX->Integrator_CSTATE[5];
        rtb_ZeroOrderHold_RollAngle = localX->Integrator_CSTATE[6];
        rtb_ZeroOrderHold_RollAngleRate = localX->Integrator_CSTATE[7];

        // MATLAB Function: '<S1>/SimHdgControl' incorporates:
        //   Integrator: '<S2>/Integrator'

        // MATLAB Function 'MissionUAV/SimHdgControl': '<S3>:1'
        // '<S3>:1:3'
        // '<S3>:1:4'
        // '<S3>:1:5'
        // '<S3>:1:7'
        a0 = 1.0 / localX->Integrator_CSTATE[3];

        // '<S3>:1:8'
        rtb_AirSpeed_n = std::cos(localX->Integrator_CSTATE[5]);
        rtb_AirSpeed_p_tmp_0 = std::sin(localX->Integrator_CSTATE[4]);
        rtb_AirSpeed_n = (std::cos(localX->Integrator_CSTATE[4]) *
                          rtb_AirSpeed_n *
                          localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth +
                          rtb_AirSpeed_p_tmp_0 * rtb_AirSpeed_n *
                          localDW->FixedWingGuidanceEnvironmentBus_p.WindEast) +
            -q * localDW->FixedWingGuidanceEnvironmentBus_p.WindDown;

        // '<S3>:1:9'
        // '<S3>:1:10'
        // '<S3>:1:12'
        y = *rtu_UAVGuidanceCmd_HeadingAngle - localX->Integrator_CSTATE[4];
        if (std::abs(y) > 3.1415926535897931) {
            if (std::isnan(y + 3.1415926535897931)) {
                skySpeed = (rtNaN);
            } else if (std::isinf(y + 3.1415926535897931)) {
                skySpeed = (rtNaN);
            } else if (y + 3.1415926535897931 == 0.0) {
                skySpeed = 0.0;
            } else {
                boolean_T rEQ0;
                skySpeed = std::fmod(y + 3.1415926535897931, 6.2831853071795862);
                rEQ0 = (skySpeed == 0.0);
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           (static_cast<int32_T>(rEQ0) ^ 1))) {
                    q = std::abs((y + 3.1415926535897931) / 6.2831853071795862);
                    rEQ0 = static_cast<boolean_T>(static_cast<int32_T>((std::abs
                        (q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q) ^
                        1));
                }

                if (rEQ0) {
                    skySpeed = 0.0;
                } else if (y + 3.1415926535897931 < 0.0) {
                    skySpeed += 6.2831853071795862;
                }
            }

            if (static_cast<boolean_T>(static_cast<int32_T>((y +
                    3.1415926535897931 > 0.0) & (skySpeed == 0.0)))) {
                skySpeed = 6.2831853071795862;
            }

            y = skySpeed - 3.1415926535897931;
        }

        a0 = rt_atan2d_snf((std::sqrt(rtb_AirSpeed_n * rtb_AirSpeed_n -
                             rtb_AirSpeed_p_tmp) + -rtb_AirSpeed_n) * y, std::
                           cos(localX->Integrator_CSTATE[4] -
                               (localX->Integrator_CSTATE[4] - std::asin(a0 *
                              localDW->FixedWingGuidanceEnvironmentBus_p.WindNorth
                              * -rtb_AirSpeed_p_tmp_0 + a0 *
                              localDW->FixedWingGuidanceEnvironmentBus_p.WindEast
                              * y_tmp))) *
                           localDW->FixedWingGuidanceEnvironmentBus_p.Gravity);

        // Saturate: '<S1>/RollAngleSaturation'
        if (a0 > 0.78539816339744828) {
            // Saturate: '<S1>/RollAngleSaturation'
            localDW->RollAngle = 0.78539816339744828;
        } else if (a0 < -0.78539816339744828) {
            // Saturate: '<S1>/RollAngleSaturation'
            localDW->RollAngle = -0.78539816339744828;
        } else {
            // Saturate: '<S1>/RollAngleSaturation'
            localDW->RollAngle = a0;
        }

        // End of Saturate: '<S1>/RollAngleSaturation'
    }

    // Integrator: '<S4>/dotBankTD'
    if (rtsiIsModeUpdateTimeStep(MissionUAV_M->solverInfo) && (*rtu_ResetState
            != 0.0)) {
        // evaluate the level of the reset signal
        localX->dotBankTD_CSTATE = 0.0;
    }

    // Integrator: '<S4>/dotBankTD'
    localDW->dotBankTD = localX->dotBankTD_CSTATE;

    // MATLAB Function: '<S4>/fhan_Bank' incorporates:
    //   Integrator: '<S4>/TD_Bank'
    //   SignalConversion generated from: '<S5>/ SFunction '
    //   Sum: '<S4>/Sum1'

    // MATLAB Function 'MissionUAV/TD/fhan_Bank': '<S5>:1'
    // '<S5>:1:3'
    // '<S5>:1:4'
    // '<S5>:1:5'
    // '<S5>:1:6'
    // '<S5>:1:8'
    // '<S5>:1:9'
    a0 = localDW->dotBankTD * 0.1;

    // '<S5>:1:10'
    y = (localX->TD_Bank_CSTATE - localDW->RollAngle) + a0;

    // '<S5>:1:11'
    // '<S5>:1:12'
    if (std::isnan(y)) {
        rtb_AirSpeed_n = y;
    } else if (y < 0.0) {
        rtb_AirSpeed_n = -1.0;
    } else {
        rtb_AirSpeed_n = static_cast<real_T>(y > 0.0);
    }

    skySpeed = (std::sqrt((8.0 * std::abs(y) + 0.020943951023931956) *
                          0.020943951023931956) - 0.020943951023931956) *
        rtb_AirSpeed_n / 2.0 + a0;

    // '<S5>:1:13'
    // '<S5>:1:14'
    if (std::isnan(y + 0.020943951023931956)) {
        rtb_AirSpeed_n = y + 0.020943951023931956;
    } else if (y + 0.020943951023931956 < 0.0) {
        rtb_AirSpeed_n = -1.0;
    } else {
        rtb_AirSpeed_n = static_cast<real_T>(y + 0.020943951023931956 > 0.0);
    }

    if (std::isnan(y - 0.020943951023931956)) {
        y_tmp = y - 0.020943951023931956;
    } else if (y - 0.020943951023931956 < 0.0) {
        y_tmp = -1.0;
    } else {
        y_tmp = static_cast<real_T>(y - 0.020943951023931956 > 0.0);
    }

    a0 = ((a0 + y) - skySpeed) * ((rtb_AirSpeed_n - y_tmp) / 2.0) + skySpeed;

    // '<S5>:1:15'
    // '<S5>:1:17'
    if (std::isnan(a0)) {
        y = a0;
    } else if (a0 < 0.0) {
        y = -1.0;
    } else {
        y = static_cast<real_T>(a0 > 0.0);
    }

    if (std::isnan(a0 + 0.020943951023931956)) {
        rtb_AirSpeed_n = a0 + 0.020943951023931956;
    } else if (a0 + 0.020943951023931956 < 0.0) {
        rtb_AirSpeed_n = -1.0;
    } else {
        rtb_AirSpeed_n = static_cast<real_T>(a0 + 0.020943951023931956 > 0.0);
    }

    if (std::isnan(a0 - 0.020943951023931956)) {
        y_tmp = a0 - 0.020943951023931956;
    } else if (a0 - 0.020943951023931956 < 0.0) {
        y_tmp = -1.0;
    } else {
        y_tmp = static_cast<real_T>(a0 - 0.020943951023931956 > 0.0);
    }

    localDW->fh = (a0 / 0.020943951023931956 - y) * -2.0943951023931953 *
        ((rtb_AirSpeed_n - y_tmp) / 2.0) - 2.0943951023931953 * y;

    // End of MATLAB Function: '<S4>/fhan_Bank'
    if (rtmIsMajorTimeStep(MissionUAV_M)) {
        // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
        //   ZeroOrderHold: '<S1>/Zero-Order Hold'

        *rty_SimUAVState_North = rtb_ZeroOrderHold_North;

        // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
        //   ZeroOrderHold: '<S1>/Zero-Order Hold'

        *rty_SimUAVState_East = rtb_ZeroOrderHold_East;

        // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
        //   ZeroOrderHold: '<S1>/Zero-Order Hold'

        *rty_SimUAVState_Height = rtb_ZeroOrderHold_Height;

        // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
        //   ZeroOrderHold: '<S1>/Zero-Order Hold'

        *rty_SimUAVState_AirSpeed = rtb_ZeroOrderHold_AirSpeed;

        // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
        //   ZeroOrderHold: '<S1>/Zero-Order Hold'

        *rty_SimUAVState_HeadingAngle = rtb_ZeroOrderHold_HeadingAngle;

        // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
        //   ZeroOrderHold: '<S1>/Zero-Order Hold'

        *rty_SimUAVState_FlightPathAngle = rtb_ZeroOrderHold_FlightPathAngle;

        // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
        //   ZeroOrderHold: '<S1>/Zero-Order Hold'

        *rty_SimUAVState_RollAngle = rtb_ZeroOrderHold_RollAngle;

        // SignalConversion generated from: '<Root>/SimUAVState' incorporates:
        //   ZeroOrderHold: '<S1>/Zero-Order Hold'

        *rty_SimUAVState_RollAngleRate = rtb_ZeroOrderHold_RollAngleRate;
    }
}

// Update for referenced model: 'MissionUAV'
void MissionUAV_Update(DW_MissionUAV_f_T *localDW)
{
    // Update for Integrator: '<S2>/Integrator'
    localDW->Integrator_IWORK = 0;
}

// Derivatives for referenced model: 'MissionUAV'
void MissionUAV_Deriv(const real_T *rtu_ResetState, DW_MissionUAV_f_T *localDW,
                      XDot_MissionUAV_n_T *localXdot)
{
    // Derivatives for Integrator: '<S2>/Integrator' incorporates:
    //   Integrator: '<S4>/TD_Bank'
    //   Integrator: '<S4>/dotBankTD'
    //   MATLABSystem: '<S2>/ComputeDerivative'

    if (*rtu_ResetState == 0.0) {
        std::memcpy(&localXdot->Integrator_CSTATE[0],
                    &localDW->ComputeDerivative[0], static_cast<uint32_T>(sizeof
                     (real_T) << 3U));
        localXdot->TD_Bank_CSTATE = localDW->dotBankTD;
        localXdot->dotBankTD_CSTATE = localDW->fh;
    } else {
        // level reset is active
        std::memset(&localXdot->Integrator_CSTATE[0], 0, static_cast<uint32_T>
                    (sizeof(real_T) << 3U));

        // level reset is active
        localXdot->TD_Bank_CSTATE = 0.0;

        // level reset is active
        localXdot->dotBankTD_CSTATE = 0.0;
    }

    // End of Derivatives for Integrator: '<S2>/Integrator'
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
    localZCE->TD_Bank_Reset_ZCE = UNINITIALIZED_ZCSIG;
    localZCE->dotBankTD_Reset_ZCE = UNINITIALIZED_ZCSIG;
}

//
// File trailer for generated code.
//
// [EOF]
//
