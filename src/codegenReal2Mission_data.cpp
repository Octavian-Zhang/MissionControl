//
// File: codegenReal2Mission_data.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.229
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 29 09:26:04 2021
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
  0.99664718933525254
  ,                                    // '<S67>/Sum'
  0.99330562000985867
  ,                                    // '<S68>/Product1'
  0.00669437999014133
  ,                                    // '<S68>/Sum1'
  0.08181919084262157
  ,                                    // '<S68>/sqrt'
  0.0066943799901413295
  ,                                    // '<S63>/Product2'
  0.99330562000985867
  ,                                    // '<S63>/Sum1'
  0.0
  ,                                    // '<S64>/Unit Conversion'
  0.0
  ,                                    // '<S49>/SinCos'
  1.0
  ,                                    // '<S49>/SinCos'
  0.0
  ,                                    // '<S40>/Unit Conversion'
  0.99664718933525254
  ,                                    // '<S44>/Sum'
  0.99330562000985867
  ,                                    // '<S45>/Product1'
  0.00669437999014133
  ,                                    // '<S45>/Sum1'
  0.08181919084262157
  ,                                    // '<S45>/sqrt'
  0.0066943799901413295
  ,                                    // '<S41>/Product2'
  0.99330562000985867
  ,                                    // '<S41>/Sum1'
  0.0
  ,                                    // '<S26>/SinCos'
  1.0
  // '<S26>/SinCos'
};

// Block parameters (default storage)
codegenReal2MissionModelClass::P_codegenReal2Mission_T
  codegenReal2MissionModelClass::codegenReal2Mission_P = {
  // Variable: GCS_Altitude
  //  Referenced by: '<S15>/AltitudeGCS'

  30.0,

  // Variable: GCS_Latitude
  //  Referenced by: '<S15>/LatitudeGCS'

  34.93914083,

  // Variable: GCS_Longitude
  //  Referenced by: '<S15>/LongitudeGCS'

  113.2316744,

  // Variable: numMissionUAV
  //  Referenced by: '<S15>/Number Of Mission UAV'

  50.0,

  // Variable: UAVidx
  //  Referenced by: '<S15>/UAVidx'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
