/* Copyright 2020 The MathWorks, Inc. */

/**
 * @file
 * Implementation of external C-API for UAV Dubins motion primitives.
 * To fully support code generation, note that this file needs to be fully
 * compliant with the C++98 standard.
 */
#include <algorithm> // for std::max

#ifdef BUILDING_LIBMWUAVDUBINSCODEGEN
#include "uavdubinscodegen/uavdubinscodegen_connection.hpp"
#include "uavdubinscodegen/uavdubinscodegen_connection_api.hpp"
#include "uavdubinscodegen/uavdubinscodegen_dubins_functors.hpp"
#include "uavdubinscodegen/uavdubinscodegen_parallel_range.hpp"
#include "uavdubinscodegen/uavdubinscodegen_trig.hpp"
#else
#include "uavdubinscodegen_connection.hpp"
#include "uavdubinscodegen_connection_api.hpp"
#include "uavdubinscodegen_dubins_functors.hpp"
#include "uavdubinscodegen_parallel_range.hpp"
#include "uavdubinscodegen_trig.hpp"
#endif

EXTERN_C UAVDUBINSCODEGEN_API void* uavDubinsConnectionObj(
        const double airSpeed, const double maxRollAngle,
        double* flightPathAngleLimit, double* disabledPathTypes,
        uint32_T numDisabledPathTypes) {
    
    return static_cast<void*>(new uav::UavDubinsConnection(airSpeed,
            maxRollAngle, flightPathAngleLimit, disabledPathTypes , numDisabledPathTypes));     
}

EXTERN_C UAVDUBINSCODEGEN_API void uavDubinsConnectionObjCleanup(void* connObj) {
    uav::UavDubinsConnection* tempConnObj = static_cast<uav::UavDubinsConnection*>(connObj);
    delete tempConnObj;
}

EXTERN_C UAVDUBINSCODEGEN_API void uavDubinsDistanceCodegen_real64(
        void* connObj,
        real64_T* startPose,
        const uint32_T numStartPoses,
        real64_T* goalPose,
        const uint32_T numGoalPoses,
        const boolean_T flagOptimal,
        const real64_T minTurningRadius,
        real64_T* sp,
        real64_T* g,
        real64_T* fpa,
        real64_T* a,
        real64_T* mtr,
        real64_T* h,
        real64_T* mt,
        real64_T* ml) {
    
    const uint32_T maxNumPoses = std::max(numStartPoses, numGoalPoses);
    
    for(uint32_T i = 0 ; i < numStartPoses ; i++)
    {
        startPose[i + 3 * numStartPoses] = uav::wrapToPi(uav::wrapTo2Pi(startPose[i + 3 * numStartPoses]));
    }
    
    for(uint32_T i = 0 ; i < numGoalPoses ; i++)
    {
        goalPose[i + 3 * numGoalPoses] = uav::wrapToPi(uav::wrapTo2Pi(goalPose[i + 3 * numGoalPoses]));
    }
    uav::UavDubinsConnection* obj = static_cast<uav::UavDubinsConnection *>(connObj);
    uint32_T DisabledPathLength = static_cast<uint32_T>(obj->getDisabledPathTypes().size());
    uint32_T counter = 0;
    std::vector<real64_T> idx1;
    counter = 0;
    
    if(DisabledPathLength != 0 && flagOptimal)
    {
        for(uint32_T i = 0 ; i < 28; i++)
        {
            if(i == obj->getDisabledPathTypes()[counter])
            {
                if((counter+1) != DisabledPathLength)
                {
                    counter++;
                }
            }
            else
            {
                idx1.push_back(i);
            }
        }
    }
    else
    {
        for(uint32_T i = 0 ; i < 28; i++)
        {
            idx1.push_back(i);
        }
    }
    real64_T* idx = &idx1[0];
    
    uav::dubins::DubinsDistanceFunctor<real64_T> distanceFunctor =
            uav::dubins::DubinsDistanceFunctor<real64_T>(connObj,startPose, numStartPoses, goalPose,
            numGoalPoses ,idx, flagOptimal , minTurningRadius, sp,g,fpa, a,mtr,h,mt,ml);
    
    // Set the grain size to the same value as the maximum range to avoid
    // any range sub-divisions.
    uav::ParallelRange<uint32_T> range =
            uav::ParallelRange<uint32_T>(0, maxNumPoses, maxNumPoses);
    
    // Since we are not parallelizing here, simply call the functor
    distanceFunctor(range);
}
