//
// File: codegenReal2Mission_data.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.269
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Apr  1 17:28:10 2021
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
#include "codegenReal2Mission.h"
#include "codegenReal2Mission_private.h"

// Invariant block signals (default storage)
const codegenReal2MissionModelClass::ConstB_codegenReal2Mission_T
  codegenReal2Mission_ConstB = {
  0.0
  ,                                    // '<S38>/Unit Conversion'
  0.99664718933525254
  ,                                    // '<S42>/Sum'
  0.99330562000985867
  ,                                    // '<S43>/Product1'
  0.00669437999014133
  ,                                    // '<S43>/Sum1'
  0.08181919084262157
  ,                                    // '<S43>/sqrt'
  0.0066943799901413295
  ,                                    // '<S39>/Product2'
  0.99330562000985867
  ,                                    // '<S39>/Sum1'
  0.0
  ,                                    // '<S24>/SinCos'
  1.0
  ,                                    // '<S24>/SinCos'
  0.99664718933525254
  ,                                    // '<S65>/Sum'
  0.99330562000985867
  ,                                    // '<S66>/Product1'
  0.00669437999014133
  ,                                    // '<S66>/Sum1'
  0.08181919084262157
  ,                                    // '<S66>/sqrt'
  0.0066943799901413295
  ,                                    // '<S61>/Product2'
  0.99330562000985867
  ,                                    // '<S61>/Sum1'
  0.0
  ,                                    // '<S62>/Unit Conversion'
  0.0
  ,                                    // '<S47>/SinCos'
  1.0
  // '<S47>/SinCos'
};

// Block parameters (default storage)
codegenReal2MissionModelClass::P_codegenReal2Mission_T
  codegenReal2MissionModelClass::codegenReal2Mission_P = {
  // Variable: GCS_Altitude
  //  Referenced by: '<S5>/AltitudeGCS'

  30.0,

  // Variable: GCS_Latitude
  //  Referenced by: '<S5>/LatitudeGCS'

  34.93914083,

  // Variable: GCS_Longitude
  //  Referenced by: '<S5>/LongitudeGCS'

  113.2316744,

  // Variable: numMissionUAV
  //  Referenced by:
  //    '<S1>/Number Of Mission UAV'
  //    '<S5>/Number Of Mission UAV'

  50.0,

  // Variable: UAVidx
  //  Referenced by:
  //    '<S1>/UAVidx'
  //    '<S5>/UAVidx'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
