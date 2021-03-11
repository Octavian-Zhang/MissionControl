//
// File: codegenReal2Mission_data.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 1.343
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Mar 11 17:48:09 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
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
  ,                                    // '<S47>/SinCos'
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
  // '<S24>/SinCos'
};

// Block parameters (default storage)
codegenReal2MissionModelClass::P_codegenReal2Mission_T
  codegenReal2MissionModelClass::codegenReal2Mission_P = {
  // Variable: GCS_Altitude
  //  Referenced by: '<S13>/AltitudeGCS'

  10.0,

  // Variable: GCS_Latitude
  //  Referenced by: '<S13>/LatitudeGCS'

  22.385,

  // Variable: GCS_Longitude
  //  Referenced by: '<S13>/LongitudeGCS'

  113.63,

  // Variable: UAVidx
  //  Referenced by: '<S13>/UAVidx'

  1,

  // Variable: numMissionUAV
  //  Referenced by: '<S13>/Number Of Mission UAV'

  50
};

//
// File trailer for generated code.
//
// [EOF]
//
