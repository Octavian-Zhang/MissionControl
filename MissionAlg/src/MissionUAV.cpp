//
// File: MissionUAV.cpp
//
// Code generated for Simulink model 'MissionUAV'.
//
// Model version                  : 1.17
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 19 16:20:29 2021
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
  // InitializeConditions for Integrator: '<S2>/Integrator'
  if (rtmIsFirstInitCond(MissionUAV_M)) {
    std::memset(&localX->Integrator_CSTATE[0], 0, sizeof(real_T) << 3U);
  }

  localDW->Integrator_IWORK = 1;

  // End of InitializeConditions for Integrator: '<S2>/Integrator'

  // InitializeConditions for Integrator: '<S4>/TD_Bank'
  localX->TD_Bank_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<S4>/dotBankTD'
  localX->dotBankTD_CSTATE = 0.0;

  // Start for MATLABSystem: '<S2>/ComputeDerivative'
  localDW->objisempty_g = true;
  localDW->obj_e.isInitialized = 1;
  MissionUAV_Model_resetImpl(&localDW->obj_e);

  // InitializeConditions for MATLABSystem: '<S2>/ComputeDerivative'
  MissionUAV_Model_resetImpl(&localDW->obj_e);

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
                *rty_SimUAVState_RollAngleRate, B_MissionUAV_c_T *localB,
                DW_MissionUAV_f_T *localDW, X_MissionUAV_n_T *localX)
{
  real_T Vg;
  real_T a0;
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
  real_T y;
  boolean_T rEQ0;

  // Integrator: '<S2>/Integrator'
  rEQ0 = rtsiGetIsOkayToUpdateMode(MissionUAV_M->solverInfo);
  if (rEQ0 && ((*rtu_ResetState != 0.0) || (localDW->Integrator_IWORK != 0))) {
    // evaluate the level of the reset signal
    std::memcpy(&localX->Integrator_CSTATE[0], &rtu_StartPos[0], sizeof(real_T) <<
                3U);
  }

  if (rtmIsMajorTimeStep(MissionUAV_M)) {
    // BusCreator: '<S1>/FixedWingGuidanceEnvironmentBus' incorporates:
    //   Constant: '<S1>/Gravity'
    //   Constant: '<S1>/NoWind'

    localB->FixedWingGuidanceEnvironmentBus_h.WindNorth = 0.0;
    localB->FixedWingGuidanceEnvironmentBus_h.WindEast = 0.0;
    localB->FixedWingGuidanceEnvironmentBus_h.WindDown = 0.0;
    localB->FixedWingGuidanceEnvironmentBus_h.Gravity = 9.807;

    // Saturate: '<S1>/AirspeedSaturation'
    a0 = *rtu_UAVGuidanceCmd_AirSpeed;
    if (a0 > 40.0) {
      // BusCreator: '<S1>/SlewGuidanceBus'
      localB->SlewGuidanceBus.AirSpeed = 40.0;
    } else if (a0 < 30.0) {
      // BusCreator: '<S1>/SlewGuidanceBus'
      localB->SlewGuidanceBus.AirSpeed = 30.0;
    } else {
      // BusCreator: '<S1>/SlewGuidanceBus'
      localB->SlewGuidanceBus.AirSpeed = a0;
    }

    // End of Saturate: '<S1>/AirspeedSaturation'

    // Saturate: '<S1>/AltitudeSaturation'
    a0 = *rtu_UAVGuidanceCmd_Height;
    if (a0 > 500.0) {
      // BusCreator: '<S1>/SlewGuidanceBus'
      localB->SlewGuidanceBus.Height = 500.0;
    } else if (a0 < 100.0) {
      // BusCreator: '<S1>/SlewGuidanceBus'
      localB->SlewGuidanceBus.Height = 100.0;
    } else {
      // BusCreator: '<S1>/SlewGuidanceBus'
      localB->SlewGuidanceBus.Height = a0;
    }

    // End of Saturate: '<S1>/AltitudeSaturation'

    // BusCreator: '<S1>/SlewGuidanceBus' incorporates:
    //   Integrator: '<S4>/TD_Bank'

    localB->SlewGuidanceBus.RollAngle = localX->TD_Bank_CSTATE;
  }

  // MATLABSystem: '<S2>/ComputeDerivative' incorporates:
  //   Integrator: '<S2>/Integrator'
  //   MATLAB Function: '<S1>/SimHdgControl'

  y = std::cos(localX->Integrator_CSTATE[5]);
  b_tmp = std::cos(localX->Integrator_CSTATE[4]);
  d = std::sin(localX->Integrator_CSTATE[4]);
  skySpeed = std::sin(localX->Integrator_CSTATE[5]);
  Vg = (-(b_tmp * y) * localB->FixedWingGuidanceEnvironmentBus_h.WindNorth + -(d
         * y) * localB->FixedWingGuidanceEnvironmentBus_h.WindEast) + skySpeed *
    localB->FixedWingGuidanceEnvironmentBus_h.WindDown;
  a0 = ((localB->FixedWingGuidanceEnvironmentBus_h.WindNorth *
         localB->FixedWingGuidanceEnvironmentBus_h.WindNorth +
         localB->FixedWingGuidanceEnvironmentBus_h.WindEast *
         localB->FixedWingGuidanceEnvironmentBus_h.WindEast) +
        localB->FixedWingGuidanceEnvironmentBus_h.WindDown *
        localB->FixedWingGuidanceEnvironmentBus_h.WindDown) -
    localX->Integrator_CSTATE[3] * localX->Integrator_CSTATE[3];
  Vg = std::sqrt(Vg * Vg - a0) + -Vg;
  localB->ComputeDerivative[0] = Vg * b_tmp * y;
  localB->ComputeDerivative[1] = Vg * d * y;
  localB->ComputeDerivative[2] = Vg * skySpeed;
  localB->ComputeDerivative[3] = (localB->SlewGuidanceBus.AirSpeed -
    localX->Integrator_CSTATE[3]) *
    localDW->obj_e.ModelImpl.Configuration.PAirSpeed;
  if (Vg == 0.0) {
    localB->ComputeDerivative[4] = 0.0;
    localB->ComputeDerivative[5] = 0.0;
  } else {
    if (localX->Integrator_CSTATE[3] == 0.0) {
      localB->ComputeDerivative[4] = 0.0;
    } else {
      y = 1.0 / (std::cos(std::asin((Vg * std::sin(localX->Integrator_CSTATE[5])
        + localB->FixedWingGuidanceEnvironmentBus_h.WindDown) /
        localX->Integrator_CSTATE[3])) * localX->Integrator_CSTATE[3]);
      localB->ComputeDerivative[4] = std::cos(std::asin(y *
        localB->FixedWingGuidanceEnvironmentBus_h.WindNorth * -d + y *
        localB->FixedWingGuidanceEnvironmentBus_h.WindEast * b_tmp)) *
        (localB->FixedWingGuidanceEnvironmentBus_h.Gravity / Vg * std::tan
         (localX->Integrator_CSTATE[6]));
    }

    localB->ComputeDerivative[5] = (std::fmax(std::fmin(std::asin(std::fmax(std::
      fmin((localB->SlewGuidanceBus.Height - localX->Integrator_CSTATE[2]) *
           localDW->obj_e.ModelImpl.Configuration.PHeight / Vg, 1.0), -1.0)),
      localDW->obj_e.ModelImpl.Configuration.FlightPathAngleLimits[1]),
      localDW->obj_e.ModelImpl.Configuration.FlightPathAngleLimits[0]) -
      localX->Integrator_CSTATE[5]) *
      localDW->obj_e.ModelImpl.Configuration.PFlightPathAngle;
  }

  localB->ComputeDerivative[6] = localX->Integrator_CSTATE[7];
  localB->ComputeDerivative[7] = (std::fmax(std::fmin
    (localB->SlewGuidanceBus.RollAngle, 1.5707963267948966), -1.5707963267948966)
    - localX->Integrator_CSTATE[6]) *
    localDW->obj_e.ModelImpl.Configuration.PDRoll[0] +
    localDW->obj_e.ModelImpl.Configuration.PDRoll[1] *
    -localX->Integrator_CSTATE[7];

  // End of MATLABSystem: '<S2>/ComputeDerivative'
  if (rtmIsMajorTimeStep(MissionUAV_M)) {
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

    y = 1.0 / localX->Integrator_CSTATE[3];
    b_tmp = std::cos(localX->Integrator_CSTATE[5]);
    Vg = std::cos(localX->Integrator_CSTATE[4]);
    b_tmp = (Vg * b_tmp * localB->FixedWingGuidanceEnvironmentBus_h.WindNorth +
             d * b_tmp * localB->FixedWingGuidanceEnvironmentBus_h.WindEast) +
      -skySpeed * localB->FixedWingGuidanceEnvironmentBus_h.WindDown;
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
        if (!rEQ0) {
          q = std::abs((d + 3.1415926535897931) / 6.2831853071795862);
          rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 *
                   q);
        }

        if (rEQ0) {
          skySpeed = 0.0;
        } else if (d + 3.1415926535897931 < 0.0) {
          skySpeed += 6.2831853071795862;
        }
      }

      if ((skySpeed == 0.0) && (d + 3.1415926535897931 > 0.0)) {
        skySpeed = 6.2831853071795862;
      }

      d = skySpeed - 3.1415926535897931;
    }

    localB->RollAngle = rt_atan2d_snf((std::sqrt(b_tmp * b_tmp - a0) + -b_tmp) *
      (0.39 * d), std::cos(localX->Integrator_CSTATE[4] -
      (localX->Integrator_CSTATE[4] - std::asin(y *
      localB->FixedWingGuidanceEnvironmentBus_h.WindNorth * -std::sin
      (localX->Integrator_CSTATE[4]) + y *
      localB->FixedWingGuidanceEnvironmentBus_h.WindEast * Vg))) *
      localB->FixedWingGuidanceEnvironmentBus_h.Gravity);

    // Saturate: '<S1>/RollAngleSaturation'
    if (localB->RollAngle > 0.3490658503988659) {
      // MATLAB Function: '<S1>/SimHdgControl' incorporates:
      //   Saturate: '<S1>/RollAngleSaturation'

      localB->RollAngle = 0.3490658503988659;
    } else if (localB->RollAngle < -0.3490658503988659) {
      // MATLAB Function: '<S1>/SimHdgControl' incorporates:
      //   Saturate: '<S1>/RollAngleSaturation'

      localB->RollAngle = -0.3490658503988659;
    }

    // End of Saturate: '<S1>/RollAngleSaturation'
  }

  // Integrator: '<S4>/dotBankTD'
  localB->dotBankTD = localX->dotBankTD_CSTATE;

  // MATLAB Function: '<S4>/fhan_Bank' incorporates:
  //   Integrator: '<S4>/TD_Bank'
  //   SignalConversion generated from: '<S5>/ SFunction '
  //   Sum: '<S4>/Sum1'

  a0 = localB->dotBankTD * 0.1;
  y = (localX->TD_Bank_CSTATE - localB->RollAngle) + a0;
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
    2.0 + a0;
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
    b_tmp = -1.0;
  } else if (y - 0.0017453292519943296 > 0.0) {
    b_tmp = 1.0;
  } else if (y - 0.0017453292519943296 == 0.0) {
    b_tmp = 0.0;
  } else {
    b_tmp = (rtNaN);
  }

  a0 = ((a0 + y) - skySpeed) * ((d - b_tmp) / 2.0) + skySpeed;
  if (a0 < 0.0) {
    y = -1.0;
  } else if (a0 > 0.0) {
    y = 1.0;
  } else if (a0 == 0.0) {
    y = 0.0;
  } else {
    y = (rtNaN);
  }

  if (a0 + 0.0017453292519943296 < 0.0) {
    d = -1.0;
  } else if (a0 + 0.0017453292519943296 > 0.0) {
    d = 1.0;
  } else if (a0 + 0.0017453292519943296 == 0.0) {
    d = 0.0;
  } else {
    d = (rtNaN);
  }

  if (a0 - 0.0017453292519943296 < 0.0) {
    skySpeed = -1.0;
  } else if (a0 - 0.0017453292519943296 > 0.0) {
    skySpeed = 1.0;
  } else if (a0 - 0.0017453292519943296 == 0.0) {
    skySpeed = 0.0;
  } else {
    skySpeed = (rtNaN);
  }

  localB->fh = (a0 / 0.0017453292519943296 - y) * -0.17453292519943295 * ((d -
    skySpeed) / 2.0) - 0.17453292519943295 * y;

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
void MissionUAV_Deriv(const real_T *rtu_ResetState, B_MissionUAV_c_T *localB,
                      XDot_MissionUAV_n_T *localXdot)
{
  // Derivatives for Integrator: '<S2>/Integrator' incorporates:
  //   MATLABSystem: '<S2>/ComputeDerivative'

  if (*rtu_ResetState == 0.0) {
    std::memcpy(&localXdot->Integrator_CSTATE[0], &localB->ComputeDerivative[0],
                sizeof(real_T) << 3U);
  } else {
    // level reset is active
    std::memset(&localXdot->Integrator_CSTATE[0], 0, sizeof(real_T) << 3U);
  }

  // End of Derivatives for Integrator: '<S2>/Integrator'

  // Derivatives for Integrator: '<S4>/TD_Bank'
  localXdot->TD_Bank_CSTATE = localB->dotBankTD;

  // Derivatives for Integrator: '<S4>/dotBankTD'
  localXdot->dotBankTD_CSTATE = localB->fh;
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
