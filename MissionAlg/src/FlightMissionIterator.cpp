//
// File: FlightMissionIterator.cpp
//
// Code generated for Simulink model 'FlightMissionIterator'.
//
// Model version                  : 2.17
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  2 16:53:33 2022
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
#include "FlightMissionIterator.h"
#include "rtwtypes.h"
#include "FlightMissionIterator_types.h"
#include "MissionModes.h"
#include <cmath>
#include <cstring>
#include "zero_crossing_types.h"
#include "FlightMissionIterator_private.h"
#include "FlightMissionMode.h"
#include "MissionUAV.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<S2>/ShiftModeSelector'
const uint8_T FlightMissionIterator_IN_Formation{ 1U };

const uint8_T FlightMissionIterator_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T FlightMissionIterator_IN_WaitToStart{ 2U };

// Named constants for Chart: '<S25>/EnableSailShift'
const uint8_T FlightMissionIterator_IN_NotShift{ 1U };

const uint8_T FlightMissionIterator_IN_Shift{ 2U };

// Named constants for Chart: '<S2>/TriggerStartSim'
const uint8_T FlightMissionIterator_IN_Pending{ 1U };

const uint8_T FlightMissionIterator_IN_Running{ 2U };

// Forward declaration for local functions
static MissionModes FlightMissionIterator_convert_to_enum_MissionModes(int32_T
    input);

// System initialize for atomic system:
void FlightMissionIterator_CoordinateTransformationConversion_Init
    (DW_CoordinateTransformationConversion_FlightMissionIterator_T *localDW)
{
    // Start for MATLABSystem: '<S22>/Coordinate Transformation Conversion'
    localDW->objisempty = true;
    localDW->obj.isInitialized = 1;
}

// Output and update for atomic system:
void FlightMissionIterator_CoordinateTransformationConversion(const real_T
    rtu_0[3], DW_CoordinateTransformationConversion_FlightMissionIterator_T
    *localDW)
{
    real_T out[9];
    real_T ct_idx_0;
    real_T ct_idx_1;
    real_T ct_idx_2;
    real_T out_tmp;
    real_T out_tmp_0;
    real_T st_idx_0;
    real_T st_idx_1;
    real_T st_idx_2;

    // MATLABSystem: '<S22>/Coordinate Transformation Conversion'
    ct_idx_0 = std::cos(rtu_0[0]);
    ct_idx_1 = std::cos(rtu_0[1]);
    ct_idx_2 = std::cos(rtu_0[2]);
    st_idx_0 = std::sin(rtu_0[0]);
    st_idx_1 = std::sin(rtu_0[1]);
    st_idx_2 = std::sin(rtu_0[2]);
    out[0] = ct_idx_0 * ct_idx_1;
    out_tmp = st_idx_1 * st_idx_2;
    out[3] = out_tmp * ct_idx_0 - st_idx_0 * ct_idx_2;
    out_tmp_0 = st_idx_1 * ct_idx_2;
    out[6] = out_tmp_0 * ct_idx_0 + st_idx_0 * st_idx_2;
    out[1] = st_idx_0 * ct_idx_1;
    out[4] = out_tmp * st_idx_0 + ct_idx_0 * ct_idx_2;
    out[7] = out_tmp_0 * st_idx_0 - ct_idx_0 * st_idx_2;
    out[2] = -st_idx_1;
    out[5] = ct_idx_1 * st_idx_2;
    out[8] = ct_idx_1 * ct_idx_2;

    // MATLABSystem: '<S22>/Coordinate Transformation Conversion'
    std::memcpy(&localDW->CoordinateTransformationConversion[0], &out[0],
                static_cast<uint32_T>(9U * sizeof(real_T)));
}

// Function for Chart: '<S2>/ShiftModeSelector'
static MissionModes FlightMissionIterator_convert_to_enum_MissionModes(int32_T
    input)
{
    MissionModes output;

    // Initialize output value to default value for MissionModes (None)
    output = MissionModes::None;
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
            static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
              static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>(
                 static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                   (static_cast<boolean_T>(static_cast<int32_T>
                     (static_cast<int32_T>(static_cast<boolean_T>
                       (static_cast<int32_T>(static_cast<int32_T>
                         (static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((input >= 0) & (input <= 3)))) | (input == 11)))) | (input == 22))))
                         | (input == 33)))) | (input == 44)))) | (input == 55))))
                | static_cast<int32_T>(static_cast<boolean_T>
                 (static_cast<int32_T>((input >= 128) & (input <= 130))))))) |
             (input == 133)))) | static_cast<int32_T>(static_cast<boolean_T>(
            static_cast<int32_T>((input >= 252) & (input <= 255))))))) {
        // Set output value to input value if it is a member of MissionModes
        output = static_cast<MissionModes>(input);
    }

    return output;
}

// System initialize for referenced model: 'FlightMissionIterator'
void FlightMissionIterator_Init(FixedWingGuidanceStateBus *rty_MissionUAVState,
    DW_FlightMissionIterator_f_T *localDW)
{
    // SystemInitialize for Iterator SubSystem: '<Root>/While Iterator Subsystem' 
    // SystemInitialize for Atomic SubSystem: '<S1>/FlightMission'
    // Start for SwitchCase: '<S2>/Switch Case'
    localDW->SwitchCase_ActiveSubsystem = -1;

    // InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0;

    // SystemInitialize for ModelReference: '<S2>/PreemptableMissionModeSelector' 
    FlightMissionMode_Init(&localDW->PreemptableMissionModeSelector_o2,
                           &localDW->PreemptableMissionModeSelector_o3[0],
                           &(localDW->PreemptableMissionModeSelector_InstanceData.rtdw));

    // SystemInitialize for Enabled SubSystem: '<S2>/MissionSimUAV'
    // SystemInitialize for ModelReference generated from: '<S6>/MissionUavModel' 
    MissionUAV_Init(&(localDW->MissionUavModel_InstanceData.rtdw));

    // End of SystemInitialize for SubSystem: '<S2>/MissionSimUAV'

    // SystemInitialize for IfAction SubSystem: '<S2>/Mode254_ShiftEarthENU'
    FlightMissionIterator_CoordinateTransformationConversion_Init
        (&localDW->CoordinateTransformationConversion);

    // End of SystemInitialize for SubSystem: '<S2>/Mode254_ShiftEarthENU'

    // SystemInitialize for IfAction SubSystem: '<S2>/Mode253_ShiftBodyXYZ'
    FlightMissionIterator_CoordinateTransformationConversion_Init
        (&localDW->CoordinateTransformationConversion_i);

    // End of SystemInitialize for SubSystem: '<S2>/Mode253_ShiftBodyXYZ'
    // End of SystemInitialize for SubSystem: '<S1>/FlightMission'

    // SystemInitialize for SignalConversion generated from: '<S1>/MissionUAVState' 
    localDW->North = localDW->North_o;

    // SystemInitialize for SignalConversion generated from: '<S1>/MissionUAVState' 
    localDW->East = localDW->East_c;

    // SystemInitialize for SignalConversion generated from: '<S1>/MissionUAVState' 
    localDW->Height = localDW->Height_i;

    // SystemInitialize for SignalConversion generated from: '<S1>/MissionUAVState' 
    localDW->AirSpeed = localDW->AirSpeed_g;

    // SystemInitialize for SignalConversion generated from: '<S1>/MissionUAVState' 
    localDW->HeadingAngle = localDW->HeadingAngle_b;

    // SystemInitialize for SignalConversion generated from: '<S1>/MissionUAVState' 
    localDW->FlightPathAngle = localDW->FlightPathAngle_i;

    // SystemInitialize for SignalConversion generated from: '<S1>/MissionUAVState' 
    localDW->RollAngle = localDW->RollAngle_c;

    // SystemInitialize for SignalConversion generated from: '<S1>/MissionUAVState' 
    localDW->RollAngleRate = localDW->RollAngleRate_e;

    // End of SystemInitialize for SubSystem: '<Root>/While Iterator Subsystem'

    // SystemInitialize for BusCreator generated from: '<Root>/MissionUAVState'
    rty_MissionUAVState->North = localDW->North;
    rty_MissionUAVState->East = localDW->East;
    rty_MissionUAVState->Height = localDW->Height;
    rty_MissionUAVState->AirSpeed = localDW->AirSpeed;
    rty_MissionUAVState->HeadingAngle = localDW->HeadingAngle;
    rty_MissionUAVState->FlightPathAngle = localDW->FlightPathAngle;
    rty_MissionUAVState->RollAngle = localDW->RollAngle;
    rty_MissionUAVState->RollAngleRate = localDW->RollAngleRate;
}

// Disable for referenced model: 'FlightMissionIterator'
void FlightMissionIterator_Disable(DW_FlightMissionIterator_f_T *localDW)
{
    // Disable for Iterator SubSystem: '<Root>/While Iterator Subsystem'
    // Disable for Atomic SubSystem: '<S1>/FlightMission'
    // Disable for ModelReference: '<S2>/PreemptableMissionModeSelector'
    FlightMissionMode_Disable
        (&(localDW->PreemptableMissionModeSelector_InstanceData.rtdw));

    // Disable for SwitchCase: '<S2>/Switch Case'
    localDW->SwitchCase_ActiveSubsystem = -1;

    // End of Disable for SubSystem: '<S1>/FlightMission'
    // End of Disable for SubSystem: '<Root>/While Iterator Subsystem'
}

// Output and update for referenced model: 'FlightMissionIterator'
void FlightMissionIterator(const boolean_T *rtu_NewMission, const missionCmd
    *rtu_ExecCMDMsg, const real_T *rtu_TgtCallCount, const real_T
    *rtu_ResetCount, FixedWingGuidanceStateBus *rty_MissionUAVState, real_T
    *rty_thisTaskStatus, DW_FlightMissionIterator_f_T *localDW,
    ZCE_FlightMissionIterator_T *localZCE)
{
    // local block i/o variables
    real_T rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1[3];
    real_T rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_m
        [3];
    real_T rtb_VectorConcatenate[9];
    real_T rtb_Product_h[3];
    real_T rtb_sincos_o1[3];
    real_T b_data;
    boolean_T loopCond;
    boolean_T rtb_StartSim;

    // Delay: '<Root>/Delay'
    if (rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->Delay_Reset_ZCE,
                 (*rtu_ResetCount)) != NO_ZCEVENT) {
        localDW->Delay_DSTATE = 0.0;
    }

    // Outputs for Iterator SubSystem: '<Root>/While Iterator Subsystem' incorporates:
    //   WhileIterator: '<S1>/While Iterator'

    // RelationalOperator: '<Root>/Relational Operator' incorporates:
    //   Delay: '<Root>/Delay'

    loopCond = (*rtu_TgtCallCount > localDW->Delay_DSTATE);
    while (loopCond) {
        real_T divisor;
        real_T rtb_AddY_idx_0;
        real_T rtb_Sin;
        int32_T superStepCount;
        int8_T rtAction;
        int8_T rtPrevAction;
        boolean_T isStable;
        boolean_T rtb_AND;

        // Outputs for Atomic SubSystem: '<S1>/FlightMission'
        // Delay: '<S2>/Delay'
        *rty_thisTaskStatus = localDW->Delay_DSTATE_f[0];

        // RelationalOperator: '<S5>/FixPt Relational Operator' incorporates:
        //   UnitDelay: '<S5>/Delay Input1'
        //
        //  Block description for '<S5>/Delay Input1':
        //
        //   Store in Global RAM

        loopCond = (static_cast<int32_T>(*rtu_NewMission) > static_cast<int32_T>
                    (localDW->DelayInput1_DSTATE_m));

        // Logic: '<S2>/AND' incorporates:
        //   Constant: '<S3>/Constant'
        //   Constant: '<S4>/Constant'
        //   RelationalOperator: '<S3>/Compare'
        //   RelationalOperator: '<S4>/Compare'

        rtb_AND = static_cast<boolean_T>(static_cast<int32_T>
            ((rtu_ExecCMDMsg->SequenceID > 0) & (rtu_ExecCMDMsg->MissionMode !=
            MissionModes::None)));

        // Chart: '<S2>/TriggerStartSim'
        // Gateway: While Iterator
        // Subsystem/FlightMission/TriggerStartSim
        superStepCount = 0;
        do {
            isStable = true;

            // During: While Iterator
            // Subsystem/FlightMission/TriggerStartSim
            if (static_cast<uint32_T>
                    (localDW->is_active_c19_FlightMissionIterator) == 0U) {
                // Entry: While Iterator
                // Subsystem/FlightMission/TriggerStartSim
                localDW->is_active_c19_FlightMissionIterator = 1U;

                // Entry Internal: While Iterator
                // Subsystem/FlightMission/TriggerStartSim
                // Transition: '<S12>:4'
                isStable = false;
                localDW->is_c19_FlightMissionIterator =
                    FlightMissionIterator_IN_Pending;

                // Entry 'Pending': '<S12>:3'
                rtb_StartSim = false;
            } else if (localDW->is_c19_FlightMissionIterator ==
                       FlightMissionIterator_IN_Pending) {
                // During 'Pending': '<S12>:3'
                if (rtb_AND) {
                    // Transition: '<S12>:6'
                    isStable = false;
                    localDW->is_c19_FlightMissionIterator =
                        FlightMissionIterator_IN_Running;

                    // Entry 'Running': '<S12>:5'
                    rtb_StartSim = true;
                } else {
                    rtb_StartSim = false;
                }
            } else {
                // During 'Running': '<S12>:5'
                rtb_StartSim = true;
            }

            superStepCount = static_cast<int32_T>(static_cast<uint32_T>(
                static_cast<uint32_T>(superStepCount) + 1U));
        } while (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<boolean_T>(static_cast<int32_T>(
                        static_cast<int32_T>(isStable) ^ 1))) &
                        (static_cast<uint32_T>(superStepCount) <= 1000U))));

        // ModelReference: '<S2>/PreemptableMissionModeSelector' incorporates:
        //   Memory: '<S2>/MemoryPose'

        FlightMissionMode(&rtb_StartSim, &rtu_ExecCMDMsg->MissionMode, &loopCond,
                          &rtu_ExecCMDMsg->StartPosition,
                          &rtu_ExecCMDMsg->MissionLocation,
                          &rtu_ExecCMDMsg->params, &rtu_ExecCMDMsg->FormationPos,
                          &rtu_ExecCMDMsg->numUAV,
                          &localDW->MemoryPose_PreviousInput[0],
                          &localDW->thisTaskStatus,
                          &localDW->PreemptableMissionModeSelector_o2,
                          &localDW->PreemptableMissionModeSelector_o3[0],
                          &(localDW->PreemptableMissionModeSelector_InstanceData.rtdw));

        // Logic: '<S2>/Reset' incorporates:
        //   Logic: '<S2>/NOT'

        loopCond = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>
            ((rtu_ExecCMDMsg->params.Param7 != 0.0F) ^ 1))) &
             static_cast<int32_T>(loopCond)));

        // Outputs for Enabled SubSystem: '<S2>/MissionSimUAV' incorporates:
        //   EnablePort: '<S6>/Enable'

        if (rtb_StartSim) {
            // DataTypeConversion: '<S6>/Cast To Double'
            localDW->CastToDouble = static_cast<real_T>(loopCond);

            // ModelReference generated from: '<S6>/MissionUavModel'
            MissionUAV(&localDW->CastToDouble,
                       &localDW->PreemptableMissionModeSelector_o3[0],
                       &localDW->PreemptableMissionModeSelector_o2.Height,
                       &localDW->PreemptableMissionModeSelector_o2.AirSpeed,
                       &localDW->PreemptableMissionModeSelector_o2.HeadingAngle,
                       &localDW->North_c, &localDW->East_f, &localDW->Height_f,
                       &localDW->AirSpeed_i, &localDW->HeadingAngle_bv,
                       &localDW->FlightPathAngle_if, &localDW->RollAngle_a,
                       &localDW->RollAngleRate_g,
                       &(localDW->MissionUavModel_InstanceData.rtdw),
                       &(localDW->MissionUavModel_InstanceData.rtzce));
        }

        // End of Outputs for SubSystem: '<S2>/MissionSimUAV'

        // Chart: '<S2>/ShiftModeSelector'
        // Gateway: While Iterator
        // Subsystem/FlightMission/ShiftModeSelector
        superStepCount = 0;
        do {
            isStable = true;

            // During: While Iterator
            // Subsystem/FlightMission/ShiftModeSelector
            if (static_cast<uint32_T>
                    (localDW->is_active_c17_FlightMissionIterator) == 0U) {
                // Entry: While Iterator
                // Subsystem/FlightMission/ShiftModeSelector
                localDW->is_active_c17_FlightMissionIterator = 1U;

                // Entry Internal: While Iterator
                // Subsystem/FlightMission/ShiftModeSelector
                // Transition: '<S9>:152'
                isStable = false;
                localDW->is_c17_FlightMissionIterator =
                    FlightMissionIterator_IN_WaitToStart;
                localDW->ImmedMission = MissionModes::WaitToStart;

                // Entry 'WaitToStart': '<S9>:151'
            } else if (localDW->is_c17_FlightMissionIterator ==
                       FlightMissionIterator_IN_Formation) {
                // During 'Formation': '<S9>:154'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((rtu_ExecCMDMsg->params.Param6 !=
                        254.0F) & (rtu_ExecCMDMsg->params.Param6 != 253.0F)))) {
                    // Transition: '<S9>:155'
                    // Exit Internal 'Formation': '<S9>:154'
                    isStable = false;
                    localDW->is_c17_FlightMissionIterator =
                        FlightMissionIterator_IN_WaitToStart;
                    localDW->ImmedMission = MissionModes::WaitToStart;

                    // Entry 'WaitToStart': '<S9>:151'
                }

                // During 'WaitToStart': '<S9>:151'
            } else if (static_cast<int32_T>(rtu_ExecCMDMsg->MissionMode) > 10) {
                rtb_Sin = static_cast<real_T>(rtu_ExecCMDMsg->MissionMode);
                for (divisor = 1.0; static_cast<real_T>
                        (rtu_ExecCMDMsg->MissionMode) / divisor >= 10.0; divisor
                     *= 10.0) {
                }

                int32_T exitg1;
                do {
                    exitg1 = 0;
                    if (rtb_Sin != 0.0) {
                        if (std::isnan(rtb_Sin)) {
                            rtb_AddY_idx_0 = (rtNaN);
                        } else {
                            rtb_AddY_idx_0 = std::fmod(rtb_Sin, 10.0);
                        }

                        if (std::floor(rtb_Sin / divisor) != rtb_AddY_idx_0) {
                            exitg1 = 1;
                        } else {
                            if ((static_cast<boolean_T>(static_cast<int32_T>
                                                        ((divisor == 0.0) ^ 1)))
                                && (static_cast<boolean_T>(static_cast<int32_T>(
                                    static_cast<int32_T>(std::isnan(rtb_Sin)) ^
                                    1))) && (static_cast<boolean_T>(static_cast<
                                    int32_T>(static_cast<int32_T>(std::isinf
                                    (divisor)) ^ 1)))) {
                                rtb_Sin = std::fmod(rtb_Sin, divisor);
                                if (rtb_Sin == 0.0) {
                                    rtb_Sin = divisor * 0.0;
                                }
                            }

                            rtb_Sin = std::floor(rtb_Sin / 10.0);
                            divisor = std::floor(divisor / 100.0);
                        }
                    } else {
                        // Transition: '<S9>:243'
                        switch
                            (FlightMissionIterator_convert_to_enum_MissionModes(
                              static_cast<int32_T>(rtu_ExecCMDMsg->params.Param6)))
                        {
                          case MissionModes::ShiftEarthENU:
                            // Transition: '<S9>:231'
                            // Transition: '<S9>:233'
                            localDW->is_c17_FlightMissionIterator =
                                FlightMissionIterator_IN_Formation;
                            isStable = false;
                            localDW->ImmedMission = MissionModes::ShiftEarthENU;
                            break;

                          case MissionModes::ShiftBodyXYZ:
                            // Transition: '<S9>:228'
                            // Transition: '<S9>:232'
                            // Transition: '<S9>:235'
                            localDW->is_c17_FlightMissionIterator =
                                FlightMissionIterator_IN_Formation;
                            isStable = false;
                            localDW->ImmedMission = MissionModes::ShiftBodyXYZ;
                            break;
                        }

                        exitg1 = 1;
                    }
                } while (exitg1 == 0);
            }

            superStepCount = static_cast<int32_T>(static_cast<uint32_T>(
                static_cast<uint32_T>(superStepCount) + 1U));
        } while (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                        (static_cast<boolean_T>(static_cast<int32_T>(
                        static_cast<int32_T>(isStable) ^ 1))) &
                        (static_cast<uint32_T>(superStepCount) <= 1000U))));

        // SwitchCase: '<S2>/Switch Case' incorporates:
        //   Sum: '<S29>/AddY'

        rtPrevAction = localDW->SwitchCase_ActiveSubsystem;
        switch (localDW->ImmedMission) {
          case MissionModes::ShiftEarthENU:
            rtAction = 0;
            break;

          case MissionModes::ShiftBodyXYZ:
            rtAction = 1;
            break;

          default:
            rtAction = 2;
            break;
        }

        localDW->SwitchCase_ActiveSubsystem = rtAction;
        switch (rtAction) {
          case 0:
            if (static_cast<int32_T>(rtAction) != static_cast<int32_T>
                    (rtPrevAction)) {
                // InitializeConditions for IfAction SubSystem: '<S2>/Mode254_ShiftEarthENU' incorporates:
                //   ActionPort: '<S8>/Action Port'

                // InitializeConditions for SwitchCase: '<S2>/Switch Case' incorporates:
                //   UnitDelay: '<S24>/Delay Input1'
                //
                //  Block description for '<S24>/Delay Input1':
                //
                //   Store in Global RAM

                localDW->DelayInput1_DSTATE = 0;

                // End of InitializeConditions for SubSystem: '<S2>/Mode254_ShiftEarthENU' 

                // SystemReset for IfAction SubSystem: '<S2>/Mode254_ShiftEarthENU' incorporates:
                //   ActionPort: '<S8>/Action Port'

                // SystemReset for Atomic SubSystem: '<S22>/SailDistance'
                // SystemReset for SwitchCase: '<S2>/Switch Case' incorporates:
                //   Chart: '<S25>/EnableSailShift'
                //   Delay: '<S29>/DelayInput'
                //   Delay: '<S29>/DelayOutput'

                localDW->temporalCounter_i1 = 0U;
                localDW->is_active_c8_FlightMissionIterator = 0U;
                localDW->is_c8_FlightMissionIterator =
                    FlightMissionIterator_IN_NO_ACTIVE_CHILD;

                // SystemReset for Atomic SubSystem: '<S27>/DiscreteIntegrator'
                localDW->DelayInput_DSTATE[0] = 0.0;
                localDW->DelayOutput_DSTATE[0] = 0.0;
                localDW->DelayInput_DSTATE[1] = 0.0;
                localDW->DelayOutput_DSTATE[1] = 0.0;

                // End of SystemReset for SubSystem: '<S27>/DiscreteIntegrator'
                // End of SystemReset for SubSystem: '<S22>/SailDistance'
                // End of SystemReset for SubSystem: '<S2>/Mode254_ShiftEarthENU' 
            }

            // Outputs for IfAction SubSystem: '<S2>/Mode254_ShiftEarthENU' incorporates:
            //   ActionPort: '<S8>/Action Port'

            // Outputs for Atomic SubSystem: '<S22>/SailDistance'
            // Gain: '<S23>/Gain1' incorporates:
            //   Gain: '<S28>/Gain1'

            rtb_Sin = 0.017453292519943295 *
                rtu_ExecCMDMsg->StartPosition.degHDG;

            // End of Outputs for SubSystem: '<S22>/SailDistance'

            // SignalConversion generated from: '<S22>/Coordinate Transformation Conversion' incorporates:
            //   Constant: '<S22>/Zero'
            //   Gain: '<S23>/Gain1'

            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_m[
                0] = rtb_Sin;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_m[
                1] = 0.0;
            rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_m[
                2] = 0.0;
            FlightMissionIterator_CoordinateTransformationConversion
                (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1_m,
                 &localDW->CoordinateTransformationConversion);

            // Product: '<S22>/Product' incorporates:
            //   MATLABSystem: '<S22>/Coordinate Transformation Conversion'
            //   Reshape: '<S22>/Reshape'

            superStepCount = 0;
            for (int32_T i{0}; i < 3; i++) {
                rtb_Product_h[i] = 0.0;
                rtb_Product_h[i] +=
                    localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                    [superStepCount] * rtu_ExecCMDMsg->StartPosition.Lat;
                rtb_Product_h[i] +=
                    localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                    [static_cast<int32_T>(superStepCount + 1)] *
                    rtu_ExecCMDMsg->StartPosition.Lon;
                rtb_Product_h[i] +=
                    localDW->CoordinateTransformationConversion.CoordinateTransformationConversion
                    [static_cast<int32_T>(superStepCount + 2)] *
                    rtu_ExecCMDMsg->StartPosition.Alt;
                superStepCount = static_cast<int32_T>(superStepCount + 3);
            }

            // End of Product: '<S22>/Product'

            // Outputs for Atomic SubSystem: '<S22>/SailDistance'
            // Chart: '<S25>/EnableSailShift' incorporates:
            //   RelationalOperator: '<S24>/FixPt Relational Operator'
            //   UnitDelay: '<S24>/Delay Input1'
            //
            //  Block description for '<S24>/Delay Input1':
            //
            //   Store in Global RAM

            // Gateway: While Iterator
            // Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
            if (static_cast<uint32_T>(localDW->temporalCounter_i1) < 127U) {
                localDW->temporalCounter_i1 = static_cast<uint8_T>
                    (static_cast<uint32_T>(static_cast<uint32_T>
                      (localDW->temporalCounter_i1) + 1U));
            }

            // During: While Iterator
            // Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
            if (static_cast<uint32_T>
                    (localDW->is_active_c8_FlightMissionIterator) == 0U) {
                // Entry: While Iterator
                // Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
                localDW->is_active_c8_FlightMissionIterator = 1U;

                // Entry Internal: While Iterator
                // Subsystem/FlightMission/Mode254_ShiftEarthENU/Mode254_Variant/Mode254/SailDistance/EnableSailShift 
                // Transition: '<S26>:5'
                localDW->is_c8_FlightMissionIterator =
                    FlightMissionIterator_IN_NotShift;
                localDW->temporalCounter_i1 = 0U;

                // Entry 'NotShift': '<S26>:4'
                isStable = true;
            } else if (localDW->is_c8_FlightMissionIterator ==
                       FlightMissionIterator_IN_NotShift) {
                // During 'NotShift': '<S26>:4'
                if (static_cast<boolean_T>(static_cast<int32_T>
                                           ((static_cast<int32_T>
                        (localDW->temporalCounter_i1) >= 100) &
                                            (rtu_ExecCMDMsg->params.Param5 !=
                        0.0F)))) {
                    // Transition: '<S26>:8'
                    localDW->is_c8_FlightMissionIterator =
                        FlightMissionIterator_IN_Shift;

                    // Entry 'Shift': '<S26>:6'
                    isStable = false;
                } else {
                    isStable = true;
                }

                // During 'Shift': '<S26>:6'
            } else if (static_cast<boolean_T>(static_cast<int32_T>
                        ((rtu_ExecCMDMsg->params.Param5 == 0.0F) |
                         (rtu_ExecCMDMsg->SequenceID !=
                          localDW->DelayInput1_DSTATE)))) {
                // Transition: '<S26>:9'
                localDW->is_c8_FlightMissionIterator =
                    FlightMissionIterator_IN_NotShift;
                localDW->temporalCounter_i1 = 0U;

                // Entry 'NotShift': '<S26>:4'
                isStable = true;
            } else {
                isStable = false;
            }

            // End of Chart: '<S25>/EnableSailShift'

            // Outputs for Atomic SubSystem: '<S27>/DiscreteIntegrator'
            // Delay: '<S29>/DelayInput'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (((localZCE->DelayInput_Reset_ZCE == POS_ZCSIG) != isStable)
                     & (localZCE->DelayInput_Reset_ZCE != UNINITIALIZED_ZCSIG))))
                  | static_cast<int32_T>(isStable)))) {
                localDW->DelayInput_DSTATE[0] = 0.0;
                localDW->DelayInput_DSTATE[1] = 0.0;
            }

            localZCE->DelayInput_Reset_ZCE = static_cast<ZCSigState>(isStable);

            // Logic: '<S29>/NOT'
            rtb_StartSim = static_cast<boolean_T>(static_cast<int32_T>(
                static_cast<int32_T>(isStable) ^ 1));

            // Delay: '<S29>/DelayOutput'
            if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
                    (static_cast<boolean_T>(static_cast<int32_T>
                    (((localZCE->DelayOutput_Reset_ZCE == POS_ZCSIG) != isStable)
                     & (localZCE->DelayOutput_Reset_ZCE != UNINITIALIZED_ZCSIG))))
                  | static_cast<int32_T>(isStable)))) {
                localDW->DelayOutput_DSTATE[0] = 0.0;
                localDW->DelayOutput_DSTATE[1] = 0.0;
            }

            localZCE->DelayOutput_Reset_ZCE = static_cast<ZCSigState>(isStable);

            // Sum: '<S29>/AddY' incorporates:
            //   Delay: '<S29>/DelayInput'
            //   Delay: '<S29>/DelayOutput'
            //   Gain: '<S29>/Gain'
            //   Product: '<S29>/Product'

            divisor = 0.1 * localDW->DelayInput_DSTATE[0] * static_cast<real_T>
                (rtb_StartSim) + localDW->DelayOutput_DSTATE[0];

            // End of Outputs for SubSystem: '<S27>/DiscreteIntegrator'

            // Update for Atomic SubSystem: '<S27>/DiscreteIntegrator'
            // Update for Delay: '<S29>/DelayOutput'
            localDW->DelayOutput_DSTATE[0] = divisor;

            // End of Update for SubSystem: '<S27>/DiscreteIntegrator'

            // Outputs for Atomic SubSystem: '<S27>/DiscreteIntegrator'
            rtb_AddY_idx_0 = divisor;

            // Sum: '<S29>/AddY' incorporates:
            //   Delay: '<S29>/DelayInput'
            //   Delay: '<S29>/DelayOutput'
            //   Gain: '<S29>/Gain'
            //   Product: '<S29>/Product'

            divisor = 0.1 * localDW->DelayInput_DSTATE[1] * static_cast<real_T>
                (rtb_StartSim) + localDW->DelayOutput_DSTATE[1];

            // End of Outputs for SubSystem: '<S27>/DiscreteIntegrator'

            // Update for Atomic SubSystem: '<S27>/DiscreteIntegrator'
            // Update for Delay: '<S29>/DelayOutput'
            localDW->DelayOutput_DSTATE[1] = divisor;

            // Update for Delay: '<S29>/DelayInput' incorporates:
            //   Product: '<S27>/Product'
            //   Trigonometry: '<S27>/Cos'
            //   Trigonometry: '<S27>/Sin'

            localDW->DelayInput_DSTATE[0] = static_cast<real_T>
                (rtu_ExecCMDMsg->params.Param5) * std::cos(rtb_Sin);
            localDW->DelayInput_DSTATE[1] = static_cast<real_T>
                (rtu_ExecCMDMsg->params.Param5) * std::sin(rtb_Sin);

            // End of Update for SubSystem: '<S27>/DiscreteIntegrator'
            // End of Outputs for SubSystem: '<S22>/SailDistance'

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   Sum: '<S22>/AddEast'

            localDW->East_c = (localDW->East_f + rtb_Product_h[0]) + divisor;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   Sum: '<S22>/AddNorth'

            localDW->North_o = (localDW->North_c + rtb_Product_h[1]) +
                rtb_AddY_idx_0;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   Sum: '<S22>/AddHeight'

            localDW->Height_i = localDW->Height_f + rtb_Product_h[2];

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S8>/ShiftedSimUAV'

            localDW->AirSpeed_g = localDW->AirSpeed_i;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S8>/ShiftedSimUAV'

            localDW->HeadingAngle_b = localDW->HeadingAngle_bv;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S8>/ShiftedSimUAV'

            localDW->FlightPathAngle_i = localDW->FlightPathAngle_if;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S8>/ShiftedSimUAV'

            localDW->RollAngle_c = localDW->RollAngle_a;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S8>/ShiftedSimUAV'

            localDW->RollAngleRate_e = localDW->RollAngleRate_g;

            // Update for UnitDelay: '<S24>/Delay Input1'
            //
            //  Block description for '<S24>/Delay Input1':
            //
            //   Store in Global RAM

            localDW->DelayInput1_DSTATE = rtu_ExecCMDMsg->SequenceID;

            // End of Outputs for SubSystem: '<S2>/Mode254_ShiftEarthENU'
            break;

          case 1:
            {
                real_T WT;

                // Outputs for IfAction SubSystem: '<S2>/Mode253_ShiftBodyXYZ' incorporates:
                //   ActionPort: '<S7>/Action Port'

                // SignalConversion generated from: '<S15>/Coordinate Transformation Conversion' 
                rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                    [0] = localDW->HeadingAngle_bv;
                rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                    [1] = localDW->FlightPathAngle_if;
                rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                    [2] = localDW->RollAngle_a;
                FlightMissionIterator_CoordinateTransformationConversion
                    (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1,
                     &localDW->CoordinateTransformationConversion_i);

                // Product: '<S15>/Matrix Multiply' incorporates:
                //   MATLABSystem: '<S15>/Coordinate Transformation Conversion'
                //   SignalConversion generated from: '<S15>/Matrix Multiply'

                for (superStepCount = 0; superStepCount < 3; superStepCount++) {
                    rtb_Product_h[superStepCount] = 0.0;
                    rtb_Product_h[superStepCount] +=
                        localDW->CoordinateTransformationConversion_i.CoordinateTransformationConversion
                        [superStepCount] * 0.0;
                    rtb_Product_h[superStepCount] +=
                        localDW->CoordinateTransformationConversion_i.CoordinateTransformationConversion
                        [static_cast<int32_T>(superStepCount + 3)] *
                        rtu_ExecCMDMsg->StartPosition.Lon;
                    rtb_Product_h[superStepCount] +=
                        localDW->CoordinateTransformationConversion_i.CoordinateTransformationConversion
                        [static_cast<int32_T>(superStepCount + 6)] *
                        rtu_ExecCMDMsg->StartPosition.Alt;
                }

                real_T rtb_VectorConcatenate_tmp;

                // End of Product: '<S15>/Matrix Multiply'

                // Trigonometry: '<S19>/sincos'
                rtb_sincos_o1[0] = std::sin
                    (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                     [0]);
                rtb_Sin = std::cos
                    (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                     [0]);
                rtb_sincos_o1[1] = std::sin
                    (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                     [1]);
                divisor = std::cos
                    (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                     [1]);
                rtb_sincos_o1[2] = std::sin
                    (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                     [2]);
                rtb_AddY_idx_0 = std::cos
                    (rtb_TmpSignalConversionAtCoordinateTransformationConversionInport1
                     [2]);

                // Fcn: '<S19>/Fcn11'
                rtb_VectorConcatenate[0] = rtb_Sin * divisor;

                // Fcn: '<S19>/Fcn21' incorporates:
                //   Fcn: '<S19>/Fcn22'

                WT = rtb_sincos_o1[1] * rtb_sincos_o1[2];
                rtb_VectorConcatenate[1] = WT * rtb_Sin - rtb_sincos_o1[0] *
                    rtb_AddY_idx_0;

                // Fcn: '<S19>/Fcn31' incorporates:
                //   Fcn: '<S19>/Fcn32'

                rtb_VectorConcatenate_tmp = rtb_sincos_o1[1] * rtb_AddY_idx_0;
                rtb_VectorConcatenate[2] = rtb_VectorConcatenate_tmp * rtb_Sin +
                    rtb_sincos_o1[0] * rtb_sincos_o1[2];

                // Fcn: '<S19>/Fcn12'
                rtb_VectorConcatenate[3] = rtb_sincos_o1[0] * divisor;

                // Fcn: '<S19>/Fcn22'
                rtb_VectorConcatenate[4] = WT * rtb_sincos_o1[0] + rtb_Sin *
                    rtb_AddY_idx_0;

                // Fcn: '<S19>/Fcn32'
                rtb_VectorConcatenate[5] = rtb_VectorConcatenate_tmp *
                    rtb_sincos_o1[0] - rtb_Sin * rtb_sincos_o1[2];

                // Fcn: '<S19>/Fcn13'
                rtb_VectorConcatenate[6] = -rtb_sincos_o1[1];

                // Fcn: '<S19>/Fcn23'
                rtb_VectorConcatenate[7] = divisor * rtb_sincos_o1[2];

                // Fcn: '<S19>/Fcn33'
                rtb_VectorConcatenate[8] = divisor * rtb_AddY_idx_0;

                // Product: '<S15>/Product' incorporates:
                //   Concatenate: '<S20>/Vector Concatenate'
                //   Reshape: '<S15>/Reshape'

                superStepCount = 0;
                for (int32_T i{0}; i < 3; i++) {
                    rtb_sincos_o1[i] = 0.0;
                    rtb_sincos_o1[i] += rtb_VectorConcatenate[superStepCount] *
                        localDW->AirSpeed_i;
                    rtb_sincos_o1[i] += rtb_VectorConcatenate
                        [static_cast<int32_T>(superStepCount + 1)] * 0.0;
                    rtb_sincos_o1[i] += rtb_VectorConcatenate[static_cast<
                        int32_T>(superStepCount + 2)] * 0.0;
                    superStepCount = static_cast<int32_T>(superStepCount + 3);
                }

                // End of Product: '<S15>/Product'

                // Product: '<S15>/HorizSpd' incorporates:
                //   Trigonometry: '<S15>/Cos'

                rtb_Sin = localDW->AirSpeed_i * std::cos
                    (localDW->FlightPathAngle_if);

                // Outputs for Enabled SubSystem: '<S15>/DivisionByZeroProtection' incorporates:
                //   EnablePort: '<S17>/Enable'

                if (rtb_Sin > 0.0) {
                    // Product: '<S17>/Divide' incorporates:
                    //   Gain: '<S15>/Gravity'
                    //   Trigonometry: '<S15>/Tan'

                    localDW->Omega = 1.0 / rtb_Sin * (9.81 * std::tan
                        (localDW->RollAngle_a));
                }

                // End of Outputs for SubSystem: '<S15>/DivisionByZeroProtection' 

                // Product: '<S15>/Divide'
                rtb_Sin = rtu_ExecCMDMsg->StartPosition.Lat /
                    localDW->AirSpeed_i;

                // MATLAB Function: '<S15>/ConstTurnPred' incorporates:
                //   Gain: '<S18>/Gain'

                // MATLAB Function 'While Iterator Subsystem/FlightMission/Mode253_ShiftBodyXYZ/Mode253_Variant/Mode253/ConstTurnPred': '<S16>:1' 
                // '<S16>:1:2'
                rtb_AddY_idx_0 = 57.295779513082323 * localDW->Omega;

                // '<S16>:1:4'
                divisor = std::fmax(std::abs(0.017453292519943295 *
                                     rtb_AddY_idx_0), 2.2204460492503131E-16);
                isStable = (rtb_AddY_idx_0 < 0.0);
                superStepCount = -1;
                if (isStable) {
                    superStepCount = 0;
                }

                if (superStepCount >= 0) {
                    b_data = -divisor;
                }

                if (isStable) {
                    divisor = b_data;
                }

                WT = divisor * rtb_Sin;
                rtb_AddY_idx_0 = std::sin(WT) / divisor;
                divisor = (1.0 - std::cos(WT)) / divisor;

                // '<S16>:1:5'
                WT = rtb_Sin * rtb_Sin * 0.5 * 0.0;

                // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
                //   MATLAB Function: '<S15>/ConstTurnPred'
                //   Product: '<S15>/Product'
                //   SignalConversion generated from: '<S7>/ShiftedSimUAV'
                //   Sum: '<S15>/AddNorth'

                localDW->North_o = (((localDW->North_c + rtb_Product_h[0]) +
                                     rtb_AddY_idx_0 * rtb_sincos_o1[0]) -
                                    divisor * rtb_sincos_o1[1]) + WT;

                // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
                //   MATLAB Function: '<S15>/ConstTurnPred'
                //   Product: '<S15>/Product'
                //   SignalConversion generated from: '<S7>/ShiftedSimUAV'
                //   Sum: '<S15>/AddEast'

                localDW->East_c = ((divisor * rtb_sincos_o1[0] +
                                    (localDW->East_f + rtb_Product_h[1])) +
                                   rtb_AddY_idx_0 * rtb_sincos_o1[1]) + WT;

                // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
                //   Gain: '<S15>/Down2Up'
                //   Gain: '<S15>/Inverse'
                //   MATLAB Function: '<S15>/ConstTurnPred'
                //   Product: '<S15>/Product'
                //   SignalConversion generated from: '<S7>/ShiftedSimUAV'
                //   Sum: '<S15>/AddHeight'

                localDW->Height_i = -((-(localDW->Height_f + rtb_Product_h[2]) +
                                       rtb_sincos_o1[2] * rtb_Sin) + WT);

                // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
                //   SignalConversion generated from: '<S7>/ShiftedSimUAV'

                localDW->AirSpeed_g = localDW->AirSpeed_i;

                // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
                //   SignalConversion generated from: '<S7>/ShiftedSimUAV'

                localDW->HeadingAngle_b = localDW->HeadingAngle_bv;

                // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
                //   SignalConversion generated from: '<S7>/ShiftedSimUAV'

                localDW->FlightPathAngle_i = localDW->FlightPathAngle_if;

                // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
                //   SignalConversion generated from: '<S7>/ShiftedSimUAV'

                localDW->RollAngle_c = localDW->RollAngle_a;

                // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
                //   SignalConversion generated from: '<S7>/ShiftedSimUAV'

                localDW->RollAngleRate_e = localDW->RollAngleRate_g;

                // End of Outputs for SubSystem: '<S2>/Mode253_ShiftBodyXYZ'
            }
            break;

          default:
            // Outputs for IfAction SubSystem: '<S2>/Switch Case Action Subsystem' incorporates:
            //   ActionPort: '<S11>/Action Port'

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S11>/UnchangedState'

            localDW->North_o = localDW->North_c;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S11>/UnchangedState'

            localDW->East_c = localDW->East_f;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S11>/UnchangedState'

            localDW->Height_i = localDW->Height_f;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S11>/UnchangedState'

            localDW->AirSpeed_g = localDW->AirSpeed_i;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S11>/UnchangedState'

            localDW->HeadingAngle_b = localDW->HeadingAngle_bv;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S11>/UnchangedState'

            localDW->FlightPathAngle_i = localDW->FlightPathAngle_if;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S11>/UnchangedState'

            localDW->RollAngle_c = localDW->RollAngle_a;

            // Merge generated from: '<S2>/MergeControlSwitch' incorporates:
            //   SignalConversion generated from: '<S11>/UnchangedState'

            localDW->RollAngleRate_e = localDW->RollAngleRate_g;

            // End of Outputs for SubSystem: '<S2>/Switch Case Action Subsystem' 
            break;
        }

        // DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
        if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                (localDW->DiscreteTimeIntegrator_PrevResetState) != 0) |
                static_cast<int32_T>(loopCond)))) {
            localDW->DiscreteTimeIntegrator_DSTATE = 1.0;
        }

        // DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
        localDW->DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;

        // Update for Delay: '<S2>/Delay' incorporates:
        //   SwitchCase: '<S2>/Switch Case'
        //   Trigonometry: '<S19>/sincos'

        for (superStepCount = 0; superStepCount < 155; superStepCount++) {
            // Outputs for IfAction SubSystem: '<S2>/Mode253_ShiftBodyXYZ' incorporates:
            //   ActionPort: '<S7>/Action Port'

            localDW->Delay_DSTATE_f[superStepCount] = localDW->Delay_DSTATE_f[
                static_cast<int_T>(superStepCount + 1)];

            // End of Outputs for SubSystem: '<S2>/Mode253_ShiftBodyXYZ'
        }

        localDW->Delay_DSTATE_f[155] = localDW->thisTaskStatus;

        // End of Update for Delay: '<S2>/Delay'

        // Update for UnitDelay: '<S5>/Delay Input1'
        //
        //  Block description for '<S5>/Delay Input1':
        //
        //   Store in Global RAM

        localDW->DelayInput1_DSTATE_m = *rtu_NewMission;

        // Outputs for Atomic SubSystem: '<S2>/SimState2Pose'
        // Update for Memory: '<S2>/MemoryPose' incorporates:
        //   Gain: '<S10>/Gain2'
        //   SignalConversion generated from: '<S10>/Pose'

        localDW->MemoryPose_PreviousInput[0] = localDW->North_c;
        localDW->MemoryPose_PreviousInput[1] = localDW->East_f;
        localDW->MemoryPose_PreviousInput[2] = -localDW->Height_f;
        localDW->MemoryPose_PreviousInput[3] = localDW->HeadingAngle_bv;

        // End of Outputs for SubSystem: '<S2>/SimState2Pose'

        // Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S2>/One'

        localDW->DiscreteTimeIntegrator_DSTATE++;
        localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
            (loopCond);

        // End of Outputs for SubSystem: '<S1>/FlightMission'

        // SignalConversion generated from: '<S1>/MissionUAVState'
        localDW->North = localDW->North_o;

        // SignalConversion generated from: '<S1>/MissionUAVState'
        localDW->East = localDW->East_c;

        // SignalConversion generated from: '<S1>/MissionUAVState'
        localDW->Height = localDW->Height_i;

        // SignalConversion generated from: '<S1>/MissionUAVState'
        localDW->AirSpeed = localDW->AirSpeed_g;

        // SignalConversion generated from: '<S1>/MissionUAVState'
        localDW->HeadingAngle = localDW->HeadingAngle_b;

        // SignalConversion generated from: '<S1>/MissionUAVState'
        localDW->FlightPathAngle = localDW->FlightPathAngle_i;

        // SignalConversion generated from: '<S1>/MissionUAVState'
        localDW->RollAngle = localDW->RollAngle_c;

        // SignalConversion generated from: '<S1>/MissionUAVState'
        localDW->RollAngleRate = localDW->RollAngleRate_e;

        // RelationalOperator: '<S1>/Relational Operator'
        loopCond = (localDW->DiscreteTimeIntegrator < *rtu_TgtCallCount);
    }

    // End of Outputs for SubSystem: '<Root>/While Iterator Subsystem'

    // BusCreator generated from: '<Root>/MissionUAVState'
    rty_MissionUAVState->North = localDW->North;
    rty_MissionUAVState->East = localDW->East;
    rty_MissionUAVState->Height = localDW->Height;
    rty_MissionUAVState->AirSpeed = localDW->AirSpeed;
    rty_MissionUAVState->HeadingAngle = localDW->HeadingAngle;
    rty_MissionUAVState->FlightPathAngle = localDW->FlightPathAngle;
    rty_MissionUAVState->RollAngle = localDW->RollAngle;
    rty_MissionUAVState->RollAngleRate = localDW->RollAngleRate;

    // Update for Delay: '<Root>/Delay'
    localDW->Delay_DSTATE = localDW->DiscreteTimeIntegrator;
}

// Model initialize function
void FlightMissionIterator_initialize(const char_T **rt_errorStatus,
    RT_MODEL_FlightMissionIterator_T *const FlightMissionIterator_M,
    DW_FlightMissionIterator_f_T *localDW, ZCE_FlightMissionIterator_T *localZCE)
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));

    // initialize error status
    rtmSetErrorStatusPointer(FlightMissionIterator_M, rt_errorStatus);

    // Model Initialize function for ModelReference Block: '<S2>/PreemptableMissionModeSelector' 
    FlightMissionMode_initialize(rtmGetErrorStatusPointer
        (FlightMissionIterator_M),
        &(localDW->PreemptableMissionModeSelector_InstanceData.rtm));

    // Model Initialize function for ModelReference Block: '<S6>/MissionUavModel' 
    MissionUAV_initialize(rtmGetErrorStatusPointer(FlightMissionIterator_M),
                          &(localDW->MissionUavModel_InstanceData.rtm),
                          &(localDW->MissionUavModel_InstanceData.rtzce));
    localZCE->Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    localZCE->DelayInput_Reset_ZCE = UNINITIALIZED_ZCSIG;
    localZCE->DelayOutput_Reset_ZCE = UNINITIALIZED_ZCSIG;
}

//
// File trailer for generated code.
//
// [EOF]
//
