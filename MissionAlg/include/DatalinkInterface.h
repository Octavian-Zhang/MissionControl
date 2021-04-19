//
// File: DatalinkInterface.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.298
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 19 16:23:29 2021
//

#ifndef RTW_HEADER_DatalinkInterface_h_
#define RTW_HEADER_DatalinkInterface_h_
#include "rtwtypes.h"

struct Location
{
  real_T Lat;
  real_T Lon;
  real_T Alt;
  real_T degHDG;
};

struct Parameters
{
  real32_T Param1;
  real32_T Param2;
  real32_T Param3;
  real32_T Param4;
  real32_T Param5;
  real32_T Param6;
  real32_T Param7;
};

struct Time
{
  int32_T year;
  int32_T month;
  int32_T day;
  int32_T hour;
  int32_T minute;
  int32_T second;
  int32_T millisecond;
};

struct IndividualUAVCmd
{
  int32_T SequenceId;
  int32_T MissionMode;
  Location MissionLocation;
  Parameters params;
  Location StartPosition;
  int32_T numUAV;
  int32_T FormationPos;
  Time StartTime;
};

#endif                                 // RTW_HEADER_DatalinkInterface_h_

//
// File trailer for generated code.
//
// [EOF]
//