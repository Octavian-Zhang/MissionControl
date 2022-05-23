//
// File: rt_zcfcn.h
//
// Code generated for Simulink model 'ImmedMission'.
//
// Model version                  : 3.3
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun May 22 08:38:12 2022
//
#ifndef RTW_HEADER_rt_zcfcn_h_
#define RTW_HEADER_rt_zcfcn_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "solver_zc.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

#ifdef __cplusplus

extern "C" {

#endif

    extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
        currValue);

#ifdef __cplusplus

}                                      // extern "C"
#endif
#endif                                 // RTW_HEADER_rt_zcfcn_h_

//
// File trailer for generated code.
//
// [EOF]
//
