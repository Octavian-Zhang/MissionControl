//
// File: codegenReal2Mission_data.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.241
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 29 11:29:58 2021
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
  ,                                    // '<S68>/Sum'
  0.99330562000985867
  ,                                    // '<S69>/Product1'
  0.00669437999014133
  ,                                    // '<S69>/Sum1'
  0.08181919084262157
  ,                                    // '<S69>/sqrt'
  0.0066943799901413295
  ,                                    // '<S64>/Product2'
  0.99330562000985867
  ,                                    // '<S64>/Sum1'
  0.0
  ,                                    // '<S65>/Unit Conversion'
  0.0
  ,                                    // '<S50>/SinCos'
  1.0
  ,                                    // '<S50>/SinCos'
  0.0
  ,                                    // '<S41>/Unit Conversion'
  0.99664718933525254
  ,                                    // '<S45>/Sum'
  0.99330562000985867
  ,                                    // '<S46>/Product1'
  0.00669437999014133
  ,                                    // '<S46>/Sum1'
  0.08181919084262157
  ,                                    // '<S46>/sqrt'
  0.0066943799901413295
  ,                                    // '<S42>/Product2'
  0.99330562000985867
  ,                                    // '<S42>/Sum1'
  0.0
  ,                                    // '<S27>/SinCos'
  1.0
  // '<S27>/SinCos'
};

// Block parameters (default storage)
codegenReal2MissionModelClass::P_codegenReal2Mission_T
  codegenReal2MissionModelClass::codegenReal2Mission_P = {
  // Variable: GCS_Altitude
  //  Referenced by: '<S4>/AltitudeGCS'

  30.0,

  // Variable: GCS_Latitude
  //  Referenced by: '<S4>/LatitudeGCS'

  34.93914083,

  // Variable: GCS_Longitude
  //  Referenced by: '<S4>/LongitudeGCS'

  113.2316744,

  // Variable: numMissionUAV
  //  Referenced by: '<S4>/Number Of Mission UAV'

  50.0,

  // Variable: UAVidx
  //  Referenced by: '<S4>/UAVidx'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
