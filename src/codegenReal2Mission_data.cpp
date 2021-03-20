//
// File: codegenReal2Mission_data.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.98
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sat Mar 20 14:48:46 2021
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
  ,                                    // '<S64>/Sum'
  0.99330562000985867
  ,                                    // '<S65>/Product1'
  0.00669437999014133
  ,                                    // '<S65>/Sum1'
  0.08181919084262157
  ,                                    // '<S65>/sqrt'
  0.0066943799901413295
  ,                                    // '<S60>/Product2'
  0.99330562000985867
  ,                                    // '<S60>/Sum1'
  0.0
  ,                                    // '<S61>/Unit Conversion'
  0.0
  ,                                    // '<S46>/SinCos'
  1.0
  ,                                    // '<S46>/SinCos'
  0.0
  ,                                    // '<S37>/Unit Conversion'
  0.99664718933525254
  ,                                    // '<S41>/Sum'
  0.99330562000985867
  ,                                    // '<S42>/Product1'
  0.00669437999014133
  ,                                    // '<S42>/Sum1'
  0.08181919084262157
  ,                                    // '<S42>/sqrt'
  0.0066943799901413295
  ,                                    // '<S38>/Product2'
  0.99330562000985867
  ,                                    // '<S38>/Sum1'
  0.0
  ,                                    // '<S23>/SinCos'
  1.0
  // '<S23>/SinCos'
};

// Block parameters (default storage)
codegenReal2MissionModelClass::P_codegenReal2Mission_T
  codegenReal2MissionModelClass::codegenReal2Mission_P = {
  // Variable: GCS_Altitude
  //  Referenced by: '<S14>/AltitudeGCS'

  10.0,

  // Variable: GCS_Latitude
  //  Referenced by: '<S14>/LatitudeGCS'

  34.95,

  // Variable: GCS_Longitude
  //  Referenced by: '<S14>/LongitudeGCS'

  113.24,

  // Variable: numMissionUAV
  //  Referenced by: '<S14>/Number Of Mission UAV'

  50.0,

  // Variable: UAVidx
  //  Referenced by: '<S14>/UAVidx'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
