//
// File: DeSerOtherUAV.cpp
//
// Code generated for Simulink model 'DeSerOtherUAV'.
//
// Model version                  : 4.339
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Aug 10 13:58:08 2022
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
#include "DeSerOtherUAV.h"
#include "rtwtypes.h"
#include "DeSerOtherUAV_types.h"
#include <cstring>
#include <cmath>
#include "rt_modd_snf.h"
#include "rt_atan2d_snf.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include "DeSerOtherUAV_private.h"

const real_T DeSerOtherUAV_RGND{ 0.0 };// real_T ground

Msg_real_T DeSerOtherUAV::DeSerOtherUAV_createMsg(const real_T *data)
{
    Msg_real_T msg;

    // DiscreteEventSubgraph generated from: '<S1>/ProcessIndivState'
    msg.fData = *data;
    return msg;
}

boolean_T DeSerOtherUAV::DeSerOtherUAV_push(Buffer_real_T *q, const Msg_real_T
    *element)
{
    // Queue generated from: '<S1>/ProcessIndivState'
    q->fMsg = *element;
    q->fOccupied = true;
    return true;
}

int32_T DeSerOtherUAV::DeSerOtherUAV_Receive_SendData(const real_T *data,
    Buffer_real_T *queue)
{
    Msg_real_T msg;
    int32_T status{ 1 };

    // DiscreteEventSubgraph generated from: '<S1>/ProcessIndivState' incorporates:
    //   Send: '<S6>/Send'

    msg = DeSerOtherUAV_createMsg(data);

    // Queue generated from: '<S1>/ProcessIndivState' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/ProcessIndivState'
    //   Send: '<S6>/Send'

    if (DeSerOtherUAV_push(queue, &msg)) {
        status = 0;
    }

    // End of Queue generated from: '<S1>/ProcessIndivState'
    return status;
}

boolean_T DeSerOtherUAV::DeSerOtherUAV_pop(Buffer_real_T *q, Msg_real_T
    *elementOut)
{
    boolean_T isPop;

    // Queue generated from: '<S1>/ProcessIndivState'
    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<int32_T>
            (q->fOccupied) ^ 1))) {
        isPop = false;
    } else {
        *elementOut = q->fMsg;
        q->fOccupied = false;
        isPop = true;
    }

    // End of Queue generated from: '<S1>/ProcessIndivState'
    return isPop;
}

int32_T DeSerOtherUAV::DeSerOtherUAV_Receive_RecvData(real_T *data,
    Buffer_real_T *queue)
{
    Msg_real_T msg;
    int32_T status{ 1 };

    // Queue generated from: '<S1>/ProcessIndivState' incorporates:
    //   DiscreteEventSubgraph generated from: '<S1>/ProcessIndivState'
    //   Receive: '<S5>/Receive'

    if (DeSerOtherUAV_pop(queue, &msg)) {
        status = 0;
        *data = msg.fData;
    }

    // End of Queue generated from: '<S1>/ProcessIndivState'
    return status;
}

// System initialize for referenced model: 'DeSerOtherUAV'
void DeSerOtherUAV::init(void)
{
    // SystemInitialize for Iterator SubSystem: '<Root>/While Iterator Serializer' 
    // Start for DataStoreMemory: '<S1>/Data Store Memory'
    for (int32_T i{0}; i < 4096; i++) {
        DeSerOtherUAV_DW.CatPos[i] = (rtNaN);
    }

    // End of Start for DataStoreMemory: '<S1>/Data Store Memory'
    // End of SystemInitialize for SubSystem: '<Root>/While Iterator Serializer' 
}

// Disable for referenced model: 'DeSerOtherUAV'
void DeSerOtherUAV::disable(void)
{
    // Disable for Iterator SubSystem: '<Root>/While Iterator Serializer'
    // Disable for Enabled SubSystem: '<S1>/WriteBuff'
    DeSerOtherUAV_DW.WriteBuff_MODE = false;

    // End of Disable for SubSystem: '<S1>/WriteBuff'

    // Disable for Enabled SubSystem: '<S1>/ProcessIndivState'
    DeSerOtherUAV_DW.ProcessIndivState_MODE = false;

    // End of Disable for SubSystem: '<S1>/ProcessIndivState'
    // End of Disable for SubSystem: '<Root>/While Iterator Serializer'
}

// Output and update for referenced model: 'DeSerOtherUAV'
void DeSerOtherUAV::step(const real_T rtu_GCS_LLA[3], real_T rty_AllUAVPos[4096])
{
    RealUAVStateBus b;
    real_T rtb_VectorConcatenate[9];
    real_T rtb_Reshape[4];
    real_T rtb_sincos_o1[3];
    real_T Receive;
    real_T b_data_0;
    int32_T x[2];
    int32_T s1_iter;
    int32_T s9_iter{ 1 };

    int16_T b_data[1024];
    int16_T ii_data_idx_0;
    int8_T ii_data;
    boolean_T c[1024];

    // Outputs for Iterator SubSystem: '<Root>/While Iterator Serializer' incorporates:
    //   WhileIterator: '<S1>/While Iterator'

    s1_iter = 1;

    // End of Outputs for SubSystem: '<Root>/While Iterator Serializer'
    boolean_T rtb_Receive_o1;
    do {
        int32_T i;
        int32_T j;
        boolean_T exitg1;
        boolean_T rtb_rcv;
        if (s1_iter == 1) {
            for (i = 0; i < 4096; i++) {
                DeSerOtherUAV_DW.CatPos[i] = (rtNaN);
            }
        }

        s9_iter = 1;
        OtherUAVstateRecvData.RecvData(&DeSerOtherUAV_DW.Receive_o2, sizeof
            (RealUAVStateBus), &s9_iter);
        if (s9_iter == 1) {
            std::memset(&DeSerOtherUAV_DW.Receive_o2, 0, sizeof(RealUAVStateBus));
        }

        rtb_Receive_o1 = (s9_iter != 1);
        if (rtb_Receive_o1) {
            RealUAVStateBus a_idx_1;
            DeSerOtherUAV_DW.WriteBuff_MODE = true;
            DeSerOtherUAV_Receive_SendData((const_cast<real_T*>
                (&DeSerOtherUAV_RGND)),
                &DeSerOtherUAV_DW.Queue_InsertedFor_ProcessIndivState_at_inport_0_Queue);

            // MATLAB Function 'While Iterator Serializer/WriteBuff/WriteBuff': '<S48>:1' 
            // '<S48>:1:5'
            a_idx_1 = DeSerOtherUAV_DW.MsgBuff[0];
            DeSerOtherUAV_DW.MsgBuff[0] = DeSerOtherUAV_DW.MsgBuff[1];
            DeSerOtherUAV_DW.MsgBuff[1] = a_idx_1;

            // '<S48>:1:7'
            DeSerOtherUAV_DW.MsgBuff[0] = DeSerOtherUAV_DW.Receive_o2;
        } else {
            DeSerOtherUAV_DW.WriteBuff_MODE = false;
        }

        // MATLAB Function 'While Iterator Serializer/testUniq': '<S7>:1'
        // '<S7>:1:3'
        j = 0;
        for (i = 0; i < 1024; i++) {
            rtb_rcv = static_cast<boolean_T>(static_cast<int32_T>
                (static_cast<int32_T>(std::isnan(DeSerOtherUAV_DW.CatPos[i])) ^
                 1));
            if (rtb_rcv) {
                j = static_cast<int32_T>(j + 1);
            }

            c[i] = rtb_rcv;
        }

        i = 0;
        for (s9_iter = 0; s9_iter < 1024; s9_iter++) {
            if (c[s9_iter]) {
                b_data[i] = static_cast<int16_T>(static_cast<int32_T>(s9_iter +
                    1));
                i = static_cast<int32_T>(i + 1);
            }
        }

        // '<S7>:1:3'
        rtb_rcv = false;
        s9_iter = 0;
        exitg1 = false;
        while ((!exitg1) && (s9_iter <= static_cast<int32_T>(j - 1))) {
            if (DeSerOtherUAV_DW.CatPos[static_cast<int32_T>(static_cast<int32_T>
                    (b_data[s9_iter]) - 1)] == static_cast<real_T>
                    (DeSerOtherUAV_DW.Receive_o2.UAV_ID)) {
                rtb_rcv = true;
                exitg1 = true;
            } else {
                s9_iter = static_cast<int32_T>(s9_iter + 1);
            }
        }

        rtb_Receive_o1 = static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(static_cast<boolean_T>(static_cast<int32_T>(
            static_cast<int32_T>(rtb_rcv) ^ 1))) & static_cast<int32_T>
            (rtb_Receive_o1)));
        if (rtb_Receive_o1) {
            DeSerOtherUAV_DW.ProcessIndivState_MODE = true;
            DeSerOtherUAV_Receive_RecvData(&Receive,
                &DeSerOtherUAV_DW.Queue_InsertedFor_ProcessIndivState_at_inport_0_Queue);
            s9_iter = 1;
            b.UAV_ID = 0;
            b.Latitude_deg = 0.0;
            b.Longitude_deg = 0.0;
            b.Height_meter = 0.0;
            b.Altitude_meter = 0.0;
            b.AirSpeed_mps = 0.0;
            b.GndSpd_mps = 0.0;
            b.HeadingAngle_deg = 0.0;
            b.FlightPathAngle_deg = 0.0;
            b.RollAngle_deg = 0.0;
            int32_T b_ii;
            int32_T ii_size_idx_1;
            do {
                real_T SW;
                real_T rtb_Abs1;
                real_T rtb_Abs1_d;
                real_T rtb_Gain1_a;
                real_T rtb_Gain1_g;
                real_T rtb_HorizSpd;
                real_T rtb_Sum_k;
                real_T rtb_Switch;
                real_T rtb_VectorConcatenate_tmp;
                real_T rtb_VectorConcatenate_tmp_0;
                real_T rtb_dEast;
                real_T rtb_sincos_o1_n;

                // MATLAB Function 'While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ReadBuff': '<S14>:1' 
                // '<S14>:1:5'
                x[0] = DeSerOtherUAV_DW.MsgBuff[0].UAV_ID;
                x[1] = DeSerOtherUAV_DW.MsgBuff[1].UAV_ID;
                j = 0;
                ii_size_idx_1 = 1;
                b_ii = 2;
                exitg1 = false;
                while ((!exitg1) && (b_ii > 0)) {
                    if (x[static_cast<int32_T>(b_ii - 1)] != 0) {
                        j = 1;
                        ii_data = static_cast<int8_T>(b_ii);
                        exitg1 = true;
                    } else {
                        b_ii = static_cast<int32_T>(b_ii - 1);
                    }
                }

                if (j == 0) {
                    ii_size_idx_1 = 0;
                    i = 0;
                    rtb_Abs1_d = 0.0;
                    rtb_dEast = 0.0;
                    Receive = 0.0;
                    rtb_HorizSpd = 0.0;
                    SW = 0.0;
                    rtb_Gain1_g = 0.0;
                    rtb_Gain1_a = 0.0;

                    // '<S14>:1:10'
                    // '<S14>:1:15'
                    rtb_rcv = false;
                } else {
                    // '<S14>:1:6'
                    // '<S14>:1:7'
                    i = DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].UAV_ID;
                    rtb_Abs1_d = DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].Latitude_deg;
                    rtb_dEast = DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].Longitude_deg;
                    Receive = DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].Height_meter;
                    rtb_HorizSpd = DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>
                        (static_cast<int32_T>(ii_data) - 1)].AirSpeed_mps;
                    SW = DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].HeadingAngle_deg;
                    rtb_Gain1_g = DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].FlightPathAngle_deg;
                    rtb_Gain1_a = DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>(
                        static_cast<int32_T>(ii_data) - 1)].RollAngle_deg;

                    // '<S14>:1:8'
                    rtb_rcv = true;
                }

                // '<S14>:1:18'
                if (static_cast<int32_T>(ii_size_idx_1 - 1) >= 0) {
                    DeSerOtherUAV_DW.MsgBuff[static_cast<int32_T>
                        (static_cast<int32_T>(ii_data) - 1)] = b;
                }

                rtb_Gain1_g *= 0.017453292519943295;
                rtb_Gain1_a *= 0.017453292519943295;
                if (std::abs(rtu_GCS_LLA[0]) > 180.0) {
                    rtb_Switch = rt_modd_snf(rtu_GCS_LLA[0] + 180.0, 360.0) +
                        -180.0;
                } else {
                    rtb_Switch = rtu_GCS_LLA[0];
                }

                rtb_Abs1 = std::abs(rtb_Switch);
                if (rtb_Abs1 > 90.0) {
                    if (static_cast<boolean_T>(static_cast<int32_T>
                                               (static_cast<int32_T>(std::isnan
                            (rtb_Switch)) ^ 1))) {
                        if (rtb_Switch < 0.0) {
                            rtb_Switch = -1.0;
                        } else {
                            rtb_Switch = static_cast<real_T>(rtb_Switch > 0.0);
                        }
                    }

                    rtb_Switch *= -(rtb_Abs1 + -90.0) + 90.0;
                    j = 180;
                } else {
                    j = 0;
                }

                rtb_Abs1 = static_cast<real_T>(j) + rtu_GCS_LLA[1];
                if (std::abs(rtb_Abs1) > 180.0) {
                    rtb_Abs1 = rt_modd_snf(rtb_Abs1 + 180.0, 360.0) + -180.0;
                }

                rtb_Abs1_d -= rtb_Switch;
                rtb_dEast -= rtb_Abs1;
                if (std::abs(rtb_Abs1_d) > 180.0) {
                    rtb_Abs1 = rt_modd_snf(rtb_Abs1_d + 180.0, 360.0) + -180.0;
                } else {
                    rtb_Abs1 = rtb_Abs1_d;
                }

                rtb_Abs1_d = std::abs(rtb_Abs1);
                if (rtb_Abs1_d > 90.0) {
                    if (static_cast<boolean_T>(static_cast<int32_T>(static_cast<
                            int32_T>(std::isnan(rtb_Abs1)) ^ 1))) {
                        if (rtb_Abs1 < 0.0) {
                            rtb_Abs1 = -1.0;
                        } else {
                            rtb_Abs1 = static_cast<real_T>(rtb_Abs1 > 0.0);
                        }
                    }

                    rtb_Abs1 *= -(rtb_Abs1_d + -90.0) + 90.0;
                    j = 180;
                } else {
                    j = 0;
                }

                rtb_Sum_k = static_cast<real_T>(j) + rtb_dEast;
                if (std::abs(rtb_Sum_k) > 180.0) {
                    rtb_Sum_k = rt_modd_snf(rtb_Sum_k + 180.0, 360.0) + -180.0;
                }

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Switch *= 0.017453292519943295;
                rtb_dEast = std::sin(rtb_Switch);
                rtb_dEast = 1.0 - 0.0066943799901413295 * rtb_dEast * rtb_dEast;
                rtb_Abs1_d = 6.378137E+6 / std::sqrt(rtb_dEast);
                rtb_Switch = rtb_Abs1_d * std::cos(rtb_Switch);

                // Unit Conversion - from: deg to: rad
                // Expression: output = (0.0174533*input) + (0)
                rtb_Abs1_d = 0.017453292519943295 * rtb_Abs1 / rt_atan2d_snf(1.0,
                    rtb_Abs1_d * 0.99330562000985867 / rtb_dEast);
                rtb_dEast = 1.0 / rt_atan2d_snf(1.0, rtb_Switch) *
                    (0.017453292519943295 * rtb_Sum_k);
                rtb_sincos_o1[0] = 0.017453292519943295 * SW;
                SW = std::cos(rtb_sincos_o1[0]);
                rtb_Switch = std::sin(rtb_sincos_o1[0]);
                rtb_Sum_k = std::cos(rtb_Gain1_g);
                rtb_Gain1_g = std::sin(rtb_Gain1_g);
                rtb_Abs1 = std::cos(rtb_Gain1_a);
                rtb_sincos_o1_n = std::sin(rtb_Gain1_a);
                rtb_VectorConcatenate[0] = SW * rtb_Sum_k;
                rtb_VectorConcatenate_tmp = rtb_Gain1_g * rtb_sincos_o1_n;
                rtb_VectorConcatenate[1] = rtb_VectorConcatenate_tmp * SW -
                    rtb_Switch * rtb_Abs1;
                rtb_VectorConcatenate_tmp_0 = rtb_Gain1_g * rtb_Abs1;
                rtb_VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 * SW +
                    rtb_Switch * rtb_sincos_o1_n;
                rtb_VectorConcatenate[3] = rtb_Switch * rtb_Sum_k;
                rtb_VectorConcatenate[4] = rtb_VectorConcatenate_tmp *
                    rtb_Switch + SW * rtb_Abs1;
                rtb_VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
                    rtb_Switch - SW * rtb_sincos_o1_n;
                rtb_VectorConcatenate[6] = -rtb_Gain1_g;
                rtb_VectorConcatenate[7] = rtb_Sum_k * rtb_sincos_o1_n;
                rtb_VectorConcatenate[8] = rtb_Sum_k * rtb_Abs1;
                j = 0;
                for (b_ii = 0; b_ii < 3; b_ii++) {
                    rtb_sincos_o1[b_ii] = 0.0;
                    rtb_sincos_o1[b_ii] += rtb_VectorConcatenate[j] *
                        rtb_HorizSpd;
                    rtb_sincos_o1[b_ii] += rtb_VectorConcatenate
                        [static_cast<int32_T>(j + 1)] * 0.0;
                    rtb_sincos_o1[b_ii] += rtb_VectorConcatenate
                        [static_cast<int32_T>(j + 2)] * 0.0;
                    j = static_cast<int32_T>(j + 3);
                }

                rtb_HorizSpd *= rtb_Sum_k;
                if (rtb_HorizSpd > 0.0) {
                    DeSerOtherUAV_DW.Omega = 1.0 / rtb_HorizSpd * (9.81 * std::
                        tan(rtb_Gain1_a));
                }

                rtb_Abs1 = -(Receive + -rtu_GCS_LLA[2]);

                // MATLAB Function 'ConstTurnPredState/MATLAB Function': '<S16>:1' 
                // '<S16>:1:2'
                rtb_Gain1_a = 57.295779513082323 * DeSerOtherUAV_DW.Omega;

                // '<S16>:1:4'
                Receive = std::fmax(std::abs(0.017453292519943295 * rtb_Gain1_a),
                                    2.2204460492503131E-16);
                j = 0;
                if (rtb_Gain1_a < 0.0) {
                    j = 1;
                }

                if (static_cast<int32_T>(j - 1) >= 0) {
                    b_data_0 = -Receive;
                }

                rtb_HorizSpd = Receive;
                if (rtb_Gain1_a < 0.0) {
                    rtb_HorizSpd = b_data_0;
                }

                Receive = std::sin(rtb_HorizSpd);
                SW = Receive / rtb_HorizSpd;
                rtb_Gain1_g = (1.0 - std::cos(rtb_HorizSpd)) / rtb_HorizSpd;

                // '<S16>:1:5'
                rtb_Reshape[0] = static_cast<real_T>(i);
                rtb_Reshape[1] = ((rtb_dEast * 0.0 + rtb_Abs1_d) + SW *
                                  rtb_sincos_o1[0]) - rtb_Gain1_g *
                    rtb_sincos_o1[1];
                rtb_Reshape[2] = ((rtb_dEast - rtb_Abs1_d * 0.0) + rtb_Gain1_g *
                                  rtb_sincos_o1[0]) + SW * rtb_sincos_o1[1];
                rtb_Reshape[3] = -(rtb_Abs1 + rtb_sincos_o1[2]);

                // MATLAB Function 'While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/ConcatenateUAVPos': '<S10>:1' 
                // '<S10>:1:8'
                // '<S10>:1:5'
                // '<S10>:1:6'
                if (static_cast<int32_T>(1 - static_cast<int32_T>
                                         (static_cast<boolean_T>
                                          (static_cast<int32_T>
                                           ((static_cast<real_T>(i) != 0.0) ^ 1))))
                    >= 1) {
                    // '<S10>:1:7'
                    for (j = 0; j < 1024; j++) {
                        c[j] = std::isnan(DeSerOtherUAV_DW.CatPos[j]);
                    }

                    b_ii = 0;
                    exitg1 = false;
                    while ((!exitg1) && (b_ii < 1024)) {
                        if (c[b_ii]) {
                            ii_data_idx_0 = static_cast<int16_T>
                                (static_cast<int32_T>(b_ii + 1));
                            exitg1 = true;
                        } else {
                            b_ii = static_cast<int32_T>(b_ii + 1);
                        }
                    }

                    // '<S10>:1:8'
                    for (j = 0; j < 4; j++) {
                        DeSerOtherUAV_DW.CatPos[static_cast<int32_T>(
                            static_cast<int32_T>(static_cast<int32_T>
                            (ii_data_idx_0) + static_cast<int32_T>(j << 10)) - 1)]
                            = rtb_Reshape[j];
                    }
                }

                // MATLAB Function 'While Iterator Serializer/ProcessIndivState/While Iterator Subsystem/PrintNbrID/PrintNbrID': '<S47>:1' 
                if (i != 0) {
                    // '<S47>:1:3'
                    // '<S47>:1:4'
                    printf("UAV%i", i);
                    fflush(stdout);
                }

                s9_iter = static_cast<int32_T>(s9_iter + 1);
            } while (static_cast<boolean_T>(static_cast<int32_T>((s9_iter <= 5)
                            & static_cast<int32_T>(rtb_rcv))));
        } else {
            DeSerOtherUAV_DW.ProcessIndivState_MODE = false;
        }

        rtb_rcv = static_cast<boolean_T>(static_cast<int32_T>
            (static_cast<int32_T>(rtb_Receive_o1) ^ 1));
        for (i = 0; i < 4096; i++) {
            if (static_cast<boolean_T>(static_cast<int32_T>((static_cast<int32_T>
                    (rtb_rcv) > static_cast<int32_T>
                    (DeSerOtherUAV_DW.DelayInput1_DSTATE)) | static_cast<int32_T>
                    (rtb_Receive_o1)))) {
                rty_AllUAVPos[i] = DeSerOtherUAV_DW.CatPos[i];
            } else {
                rty_AllUAVPos[i] = (rtNaN);
            }
        }

        DeSerOtherUAV_DW.DelayInput1_DSTATE = rtb_rcv;
        s1_iter = static_cast<int32_T>(s1_iter + 1);
    } while (static_cast<boolean_T>(static_cast<int32_T>((s1_iter <= 1024) &
                    static_cast<int32_T>(rtb_Receive_o1))));
}

// Model initialize function
void DeSerOtherUAV::initialize()
{
    // Registration code

    // initialize non-finites
    rt_InitInfAndNaN(sizeof(real_T));
}

// Constructor
DeSerOtherUAV::DeSerOtherUAV(RecvData_RealUAVStateBusT&
    OtherUAVstateRecvData_arg) :
    DeSerOtherUAV_DW(),
    OtherUAVstateRecvData(OtherUAVstateRecvData_arg),
    DeSerOtherUAV_M()
{
    // Currently there is no constructor body generated.
}

// Destructor
DeSerOtherUAV::~DeSerOtherUAV()
{
    // Currently there is no destructor body generated.
}

// Real-Time Model get method
DeSerOtherUAV::RT_MODEL_DeSerOtherUAV_T * DeSerOtherUAV::getRTM()
{
    return (&DeSerOtherUAV_M);
}

// member function to setup error status pointer
void DeSerOtherUAV::setErrorStatusPointer(const char_T **rt_errorStatus)
{
    rtmSetErrorStatusPointer((&DeSerOtherUAV_M), rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
