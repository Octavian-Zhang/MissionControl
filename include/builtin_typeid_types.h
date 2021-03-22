//
// File: builtin_typeid_types.h
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.137
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 22 20:09:14 2021
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

#ifndef BUILTIN_TYPEID_TYPES_H
#define BUILTIN_TYPEID_TYPES_H
#include "rtwtypes.h"
#ifndef BUILTIN_TYPEID_TYPES
#define BUILTIN_TYPEID_TYPES

// Enumeration of built-in data types
typedef enum {
  SS_DOUBLE = 0,                       // real_T
  SS_SINGLE = 1,                       // real32_T
  SS_INT8 = 2,                         // int8_T
  SS_UINT8 = 3,                        // uint8_T
  SS_INT16 = 4,                        // int16_T
  SS_UINT16 = 5,                       // uint16_T
  SS_INT32 = 6,                        // int32_T
  SS_UINT32 = 7,                       // uint32_T
  SS_BOOLEAN = 8                       // boolean_T
} BuiltInDTypeId;

#define SS_NUM_BUILT_IN_DTYPE          ((int_T)SS_BOOLEAN+1)

// Enumeration for MAT-file logging code
typedef int_T DTypeId;

#endif                                 // BUILTIN_TYPEID_TYPES
#endif                                 // BUILTIN_TYPEID_TYPES_H

//
// File trailer for generated code.
//
// [EOF]
//
