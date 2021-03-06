/* Copyright 2020 The MathWorks, Inc. */

/**
 * @file
 * Constants used in uav Dubins features.
 * To fully support code generation, note that this file needs to be fully
 * compliant with the C++98 standard.
 */

#ifndef UAVDUBINSCODEGEN_CONSTANTS_H_
#define UAVDUBINSCODEGEN_CONSTANTS_H_

#ifdef BUILDING_LIBMWUAVDUBINSCODEGEN
#include "uavdubinscodegen/uavdubinscodegen_util.hpp"
#else
#include "uavdubinscodegen_util.hpp"
#endif

namespace uav {
// Codegen-compatible versions of declaration in
// matlab/math/foundation/src/mfl_scalar/export/include/mfl_scalar/detail/word_types.hpp
typedef union {
    real64_T value;
    struct {
        uint32_T lw;
        uint32_T hw;
    } words;
} auton_double_word_T;

// Codegen-compatible version of declarations in
// matlab/math/foundation/src/mfl_scalar/export/include/mfl_scalar/constants.hpp
inline real64_T getInf() {
    uav::auton_double_word_T tmp;
    tmp.words.hw = 0x7ff00000U;
    tmp.words.lw = 0x00000000U;
    return tmp.value;
}

inline real64_T getNaN(){
    uav::auton_double_word_T x;
    x.words.hw = 0xfff80000U;
    x.words.lw = 0x00000000U;
    return x.value;
}

inline real64_T getPi() {
    return 3.14159265358979323846;
}

// toosamll value found from a trial-and-error process to find thresholds 
// such that the unit tests would consistently pass. Source - OMPL.
const real64_T tooSmall = 1e-7;

const real64_T pi = uav::getPi();
const real64_T twoPi = 2.0 * uav::getPi();
const real64_T inf = uav::getInf();
const real64_T nan = uav::getNaN();

} // namespace uav

#endif // UAVDUBINSCODEGEN_CONSTANTS_H_
