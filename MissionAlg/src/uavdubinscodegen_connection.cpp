/* Copyright 2020 The MathWorks, Inc. */

#ifdef BUILDING_LIBMWUAVDUBINSCODEGEN
#include "uavdubinscodegen/uavdubinscodegen_connection.hpp"
#else
#include "uavdubinscodegen_connection.hpp"
#endif

uav::UavDubinsConnection::UavDubinsConnection(double airSpeed, double maxRollAngle,
double flightPathAngleLimits[2], std::vector<double> disabledPathTypes):mAirSpeed(airSpeed),
        mMaxRollAngle(maxRollAngle),mDisabledPathTypes(disabledPathTypes){

    mFlightPathAngleLimits[0] = flightPathAngleLimits[0];
    mFlightPathAngleLimits[1] = flightPathAngleLimits[1];
    // Compute MinTurningRadius
    mMinTurningRadius = updateMinTurningRadius();
}

uav::UavDubinsConnection::UavDubinsConnection(double airSpeed, double maxRollAngle,
double flightPathAngleLimits[2], double disabledPathTypes[], uint32_T mNumDisabledPathTypes):mAirSpeed(airSpeed),
        mMaxRollAngle(maxRollAngle){

    mFlightPathAngleLimits[0] = flightPathAngleLimits[0];
    mFlightPathAngleLimits[1] = flightPathAngleLimits[1];
    for(uint32_T i = 0 ; i < mNumDisabledPathTypes; i++)
    {
        mDisabledPathTypes.push_back(disabledPathTypes[i]);
    }
    // Compute MinTurningRadius
    mMinTurningRadius = updateMinTurningRadius();
}
                
//Setter functions
void uav::UavDubinsConnection::setAirSpeed(double airSpeed)
{
    mAirSpeed = airSpeed;
    mMinTurningRadius = updateMinTurningRadius();
}
void uav::UavDubinsConnection::setMaxRollAngle(double maxRollAngle)
{
    mMaxRollAngle = maxRollAngle;
    mMinTurningRadius = updateMinTurningRadius();
}
void uav::UavDubinsConnection::setFlightPathAngleLimits(double flightPathAngleLimits[2])
{
    mFlightPathAngleLimits[0] = flightPathAngleLimits[0];
    mFlightPathAngleLimits[1] = flightPathAngleLimits[1];
}
void uav::UavDubinsConnection::setDisabledPathTypes(std::vector<double> disabledPathTypes)
{
    mDisabledPathTypes = disabledPathTypes;
}
//Getter functions
double uav::UavDubinsConnection::getAirSpeed()
{
    return mAirSpeed;
}
double uav::UavDubinsConnection::getMaxRollAngle()
{
    return mMaxRollAngle;
}
double* uav::UavDubinsConnection::getFlightPathAngleLimits()
{
    return &mFlightPathAngleLimits[0];
}
std::vector<double> uav::UavDubinsConnection::getDisabledPathTypes()
{
    return mDisabledPathTypes;
}

void uav::UavDubinsConnection::connectAirplaneXYZ(const double startPose[4], const double goalPose[4],
        const bool flagOptimal, const double* idx, double motionLengths[3][6],
        double motionCosts[6], UavDubinsPathsegments* psegObjs)
{
    double minTurningRadius = mMinTurningRadius;
    double startPoseDubins2D[3] = {startPose[0] , startPose[1] , startPose[3]};
    double goalPoseDubins2D[3] = {goalPose[0] , goalPose[1] , goalPose[3]};
    double startAltitude = startPose[2];
    double goalAltitude = goalPose[2];
    double absAltitude = std::abs(startAltitude - goalAltitude);
    double lowestMotionCost;
    bool pathFeasible = false;
    double maxFlightPathAngle = mFlightPathAngleLimits[1];
    int signFlightPathAngle;
    
    if(maxFlightPathAngle > 0)
    {
        signFlightPathAngle = 1;
    }
    else if(maxFlightPathAngle == 0)
    {
        signFlightPathAngle = 0;
    }
    else
    {
        signFlightPathAngle = -1;
    }
    // Ascending
    if(startAltitude < goalAltitude)
    {
        if(maxFlightPathAngle > 0)
        {
            pathFeasible = true;
        }
    }
    // same Altitude
    else if(startAltitude == goalAltitude)
    {
        if(mFlightPathAngleLimits[0] <= 0 && mFlightPathAngleLimits[1] >= 0)
        {
            pathFeasible = true;
        }
    }
    // Descending
    else
    {
        if(mFlightPathAngleLimits[0] < 0)
        {
            pathFeasible = true;
            maxFlightPathAngle = std::abs(mFlightPathAngleLimits[0]);
            signFlightPathAngle = -1;
        }
    }
    
    int flagSame2DPose = 0;
    double minValue = motionCosts[0];
    for(int i = 1 ; i < 6; i++)
    {
        if(motionCosts[i] < minValue)
        {
            minValue = motionCosts[i];
        }
    }
    if(minValue == 0)
    {
        flagSame2DPose = 1;
    }
    
    
    if(pathFeasible)
    {
        
        bool flag = true;
        // Special case when start and goal pose are same except the altitude
        if(flagSame2DPose && absAltitude > 0)
        {
            for(int i=0; i < 4; i++)
            {
                motionCosts[i] = 2*pi*minTurningRadius;
                motionLengths[0][i] = 2*pi*minTurningRadius;
                motionLengths[1][i] = 0;
                motionLengths[2][i] = 0;
            }
        }
        int lowAltitudeFlags[6]{}, mediumAltitudeFlags[6]{}, highAltitudeFlags[6]{};
        for(int i = 0 ; i < 6; i++)
        {
            lowAltitudeFlags[i] = (motionCosts[i] * tan(maxFlightPathAngle)) >= absAltitude;
            highAltitudeFlags[i] = ((motionCosts[i] + 2 * pi * minTurningRadius) * tan(maxFlightPathAngle)) <= absAltitude;
        }
        bool checks[6];
        for(int i = 0 ; i < 6; i++)
        {
            checks[i] = highAltitudeFlags[i] && (motionCosts[i] > 0);
        }
        if(!std::any_of(checks , checks+6 , [](bool x) { return x; }) || flagOptimal == false)
        {
            
            double mincost = motionCosts[0];
            for(int j = 1 ; j < 6 ; j++)
            {
                if(mincost > motionCosts[j])
                {
                    mincost = motionCosts[j];
                }
            }
            if(!std::any_of(highAltitudeFlags, highAltitudeFlags+6 ,[](bool x){return (x == 1);})
            && absAltitude > mincost * tan(maxFlightPathAngle) &&
                    absAltitude < (mincost + 2*pi*minTurningRadius) * tan(maxFlightPathAngle))
            {
                for(int i=0;i<6;i++)
                {
                    mediumAltitudeFlags[i] = 1;
                }
                for(int i = 0 ; i < 6; i++)
                    mediumAltitudeFlags[i] = mediumAltitudeFlags[i] * (motionCosts[i] > 0) - (lowAltitudeFlags[i] +
                            highAltitudeFlags[i]) * (motionCosts[i] > 0);
            }
        }
        
        if((flagSame2DPose && absAltitude > 0 ) &&
                std::any_of(mediumAltitudeFlags , mediumAltitudeFlags+6 , [](bool x){return x;}))
        {
            for(int i = 0; i < 6; i++)
            {
                motionCosts[i] = 0;
                for(int j = 0 ; j < 3 ; j++)
                    motionLengths[j][i] = 0;
                lowAltitudeFlags[i] = 0;
                mediumAltitudeFlags[i] = 0;
                highAltitudeFlags[i] = 1;
            }
        }
        lowestMotionCost = inf;
        int optStartCurve;
        if(std::any_of(mediumAltitudeFlags , mediumAltitudeFlags+6 , [] (bool x){return x;}))
        {
            if(!std::equal(startPose , startPose+4 , goalPose))
            {
                optStartCurve = 1;
                double theta = startPoseDubins2D[2];

                if(startAltitude > goalAltitude)
                {
                    optStartCurve = 0;
                    theta = goalPoseDubins2D[2];
                }
                double tempMotionLength[2][3]{} , tempMotionCost[2]{};
                double lm[2];
                lm[0] = 0;
                lm[1] = 0;
                char tempMotionType[2][3];
                int qualityFlag{1};
                optimizeMidAltitude(startPoseDubins2D, goalPoseDubins2D,
                        theta, optStartCurve, maxFlightPathAngle, absAltitude,
                        tempMotionLength, tempMotionCost, tempMotionType, lm, &qualityFlag);

                if(qualityFlag)
                {
                    std::string tempMotionTypeForLeftArcString = "";
                    std::string tempMotionTypeForRightArcString = "";
                    for(int k = 0; k < 3 ; k++)
                    {
                        tempMotionTypeForLeftArcString += tempMotionType[0][k];
                        tempMotionTypeForRightArcString += tempMotionType[1][k];
                    }
                    double tempMotionLengths[3]{};
                    for(int i = 0 ; i < 3; i++)
                    {
                        tempMotionLengths[i] = tempMotionLength[0][i];
                    }
                    addArc(tempMotionTypeForLeftArcString, tempMotionCost[0],
                            tempMotionLengths, maxFlightPathAngle, lm[0], 'L', lowestMotionCost,
                            psegObjs, optStartCurve, flagOptimal, signFlightPathAngle);
                    for(int i = 0 ; i < 3; i++)
                    {
                        tempMotionLengths[i] = tempMotionLength[1][i];
                    }
                    addArc(tempMotionTypeForRightArcString, tempMotionCost[1],
                            tempMotionLengths, maxFlightPathAngle, lm[1], 'R', lowestMotionCost,
                            psegObjs, optStartCurve, flagOptimal, signFlightPathAngle);
                }
            }
        }
        int offsetIndex = 0;
        int countI = 0;
        int I[6];
        double flightPathLength{};
        double helixRadius{};
        if(! std::equal(startPose, startPose +4 ,  goalPose))
        {
            if(std::any_of(highAltitudeFlags , highAltitudeFlags+6 , [](bool x){return x;}))
            {
                for(int i = 0 ; i < 6; i++)
                {
                    if(highAltitudeFlags[i] > 0)
                    {
                        I[countI++] = i;
                    }
                }
            }
            for(int i = 0 ; i < countI ; i++)
            {
                if(startAltitude < goalAltitude)
                {
                    offsetIndex = 6;
                }
                else
                {
                    offsetIndex = 12;
                }
                size_t idxSize = static_cast<size_t>(28) - mDisabledPathTypes.size();
                double k = I[i] + offsetIndex;
                flag = false;
                for(size_t j = 0 ; j < idxSize; j++)
                {
                    if(idx[j] == k)
                    {
                        flag = true;
                    }
                }
                if(flag)
                {
                    double dubinsPathCost = motionCosts[I[i]];
                    k = floor(std::abs((absAltitude/tan(maxFlightPathAngle) - dubinsPathCost)/(2*pi*mMinTurningRadius)));
                    double dl = std::abs(absAltitude/tan(maxFlightPathAngle) - dubinsPathCost);

                    if(flagSame2DPose && absAltitude > 0 && k == 0)
                    {
                        k = 1;
                        dl = 2*pi*mMinTurningRadius;
                    }
                    helixRadius = dl/(2*pi*k);
                    double motionSegmentLength[4];
                    for(int j = 0;j<3;j++)
                    {
                        motionSegmentLength[j] = motionLengths[j][I[i]];
                    }
                    flightPathLength = (dubinsPathCost + dl)/cos(maxFlightPathAngle);

                    if(startAltitude < goalAltitude)
                    {
                        for(int j = 3; j >= 1; j--)
                            motionSegmentLength[j] = motionSegmentLength[j-1];
                        motionSegmentLength[0] = dl;
                    }
                    else
                    {
                        motionSegmentLength[3] = dl;
                    }
                    bool flagProcess = false;
                    if(flagOptimal)
                    {
                        if(flightPathLength < lowestMotionCost)
                        {
                            lowestMotionCost = flightPathLength;
                            psegObjs[0].MotionTypes = static_cast<int>(offsetIndex + I[i]);

                            offsetIndex = 0;
                            flagProcess =true;
                        }
                    }
                    else
                    {
                        offsetIndex += I[i];
                        flagProcess = true;

                    }
                    if(flagProcess)
                    {
                        psegObjs[offsetIndex].FlightPathAngle = signFlightPathAngle * maxFlightPathAngle;
                        for(size_t j = 0 ; j < 4; j++)
                        {
                            psegObjs[offsetIndex].MotionLengths[j] = (motionSegmentLength[j]/cos(maxFlightPathAngle));
                        }
                        psegObjs[offsetIndex].Length = 0;
                        for(size_t j = 0 ; j < (sizeof(psegObjs[offsetIndex].MotionLengths)/sizeof(psegObjs[offsetIndex].MotionLengths[0])); j++)
                        {
                            psegObjs[offsetIndex].Length += psegObjs[offsetIndex].MotionLengths[j];
                        }
                        psegObjs[offsetIndex].HelixRadius = helixRadius;
                    }
                }
            }
        }
        countI = 0;
        if(std::any_of(lowAltitudeFlags, lowAltitudeFlags+6 , [](int x){return (x == 1);}))
        {
            for(int i = 0 ; i < 6; i++)
            {
                if(lowAltitudeFlags[i] > 0)
                {
                    I[countI++] = i;
                }
            }
            size_t idxSize = static_cast<size_t>(28) - mDisabledPathTypes.size();
            for(int i = 0 ; i < countI; i++)
            {
                flag = false;
                for(size_t j = 0 ; j < idxSize;  j++)
                {
                    if(idx[j] == I[i])
                    {
                        flag = true;
                    }
                }
                if(flag)
                {
                    flightPathLength = 0;
                    double compFlightPathAngle = 0;
                    double sum = 0;
                    for(int j = 0 ; j < 4; j++)
                    {
                        sum += std::abs(startPose[j] - goalPose[j]);
                    }
                    if(sum != 0)
                    {
                        compFlightPathAngle = atan(absAltitude/motionCosts[I[i]]);
                        flightPathLength = motionCosts[I[i]]/cos(compFlightPathAngle);
                    }
                    double motionSegmentLength[3]{};
                    for(int j = 0;j<3;j++)
                    {
                        motionSegmentLength[j] = motionLengths[j][I[i]];
                    }
                    bool flagProcess = false;
                    if(flagOptimal)
                    {
                        if(flightPathLength < lowestMotionCost)
                        {

                            lowestMotionCost = flightPathLength;
                            offsetIndex = 0;
                            psegObjs[0].MotionTypes = static_cast<int>(I[i]);
                            flagProcess =true;
                        }
                    }
                    else
                    {
                        offsetIndex = I[i];
                        flagProcess = true;
                    }
                    if(flagProcess)
                    {
                        psegObjs[offsetIndex].FlightPathAngle = (signFlightPathAngle * compFlightPathAngle);
                        psegObjs[offsetIndex].MotionLengths[3] = 0;
                        psegObjs[offsetIndex].Length = 0;
                        for(size_t j = 0 ; j < 3; j++)
                        {
                            psegObjs[offsetIndex].MotionLengths[j] = (motionSegmentLength[j]/cos(compFlightPathAngle));
                        }
                        for(size_t j = 0 ; j < 4 ; j++)
                        {
                            psegObjs[offsetIndex].Length += psegObjs[offsetIndex].MotionLengths[j];
                        }
                    }
                }
            }
        }
    }
}

double uav::UavDubinsConnection::updateMinTurningRadius() const
{
    return (mAirSpeed*mAirSpeed)/(Gravity * tan(mMaxRollAngle));
}

void uav::UavDubinsConnection::optimizeMidAltitude(double startPoseDubins2D[3], double goalPoseDubins2D[3], double theta,
        int optStartCurve, double maxFlightPathAngle, double absAltitude, double motionLength[2][3],
        double motionCost[2], char motionType[2][3] , double lm[2], int* qualityFlag )
{
    double luBounds[2][2] = {{0 , 2*pi}, {0,2*pi}};
    double transformMatrix[2][2] = {{cos(theta), sin(theta)} , {-sin(theta) , cos(theta)}};
    unsigned int start_size = 1, goal_size=1;
    optStartCurve?start_size = 2:goal_size = 2;
    std::vector<real64_T> newStartPoseDubins2D;
    std::vector<real64_T> newGoalPoseDubins2D;
    newStartPoseDubins2D.resize(start_size * 3);
    newGoalPoseDubins2D.resize(goal_size * 3);
    for(int l = 0; l < 3; l++)
    {
        for(int n = 0; n<2 ;n++)
        {
            motionType[n][l] = 'N';
        }
    }
    int loopCounter = 0;
    bool iterFlag = true;
    *qualityFlag = 0;
    double prevlm[2] = {0, 0};
    int maxIter = 25;
    int iterCount = 0;
    double EPS ,prev_epsilon{};
    double d = std::numeric_limits<double>::epsilon();
    while(iterFlag)
    {
        loopCounter++;
        lm[0] = (luBounds[0][0] + luBounds[0][1])/2;
        lm[1] = (luBounds[1][0] + luBounds[1][1])/2;
        if(optStartCurve)
        {
            double X[2][2] = {{sin(lm[0]), 1-cos(lm[0])} ,  {sin(lm[1]), cos(lm[1])-1}};
            double transformedX[2][2]{};
            for(int i = 0 ;i < 2; i++)
            {
                for(int j = 0 ; j < 2 ; j++)
                {
                    transformedX[i][j] = X[i][0] * transformMatrix[0][j] + X[i][1] * transformMatrix[1][j];
                }
            }
            newStartPoseDubins2D[0] = startPoseDubins2D[0] + transformedX[0][0] * mMinTurningRadius;
            newStartPoseDubins2D[2] = startPoseDubins2D[1] + transformedX[0][1] * mMinTurningRadius;
            newStartPoseDubins2D[4] = startPoseDubins2D[2] + lm[0];
            newStartPoseDubins2D[1] = startPoseDubins2D[0] + transformedX[1][0] * mMinTurningRadius;
            newStartPoseDubins2D[3] = startPoseDubins2D[1] + transformedX[1][1] * mMinTurningRadius;
            newStartPoseDubins2D[5] = startPoseDubins2D[2] - lm[1];
            newGoalPoseDubins2D[0] = goalPoseDubins2D[0];
            newGoalPoseDubins2D[1] = goalPoseDubins2D[1];
            newGoalPoseDubins2D[2] = goalPoseDubins2D[2];
        }
        else
        {
            double X[2][2] = {{-sin(lm[0]) , 1-cos(lm[0])} ,  {-sin(lm[1]) , cos(lm[1])-1}};
            double transformedX[2][2];
            for(int i = 0 ;i < 2; i++)
            {
                for(int j = 0 ; j < 2 ; j++)
                {
                    transformedX[i][j] = X[i][0] * transformMatrix[0][j] + X[i][1] * transformMatrix[1][j];
                }
            }
            newGoalPoseDubins2D[0] = goalPoseDubins2D[0] + transformedX[0][0] * mMinTurningRadius;
            newGoalPoseDubins2D[2] = goalPoseDubins2D[1] + transformedX[0][1] * mMinTurningRadius;
            newGoalPoseDubins2D[4] = goalPoseDubins2D[2] - lm[0];
            newGoalPoseDubins2D[1] = goalPoseDubins2D[0] + transformedX[1][0] * mMinTurningRadius;
            newGoalPoseDubins2D[3] = goalPoseDubins2D[1] + transformedX[1][1] * mMinTurningRadius;
            newGoalPoseDubins2D[5] = goalPoseDubins2D[2] + lm[1];
            newStartPoseDubins2D[0] = startPoseDubins2D[0];
            newStartPoseDubins2D[1] = startPoseDubins2D[1];
            newStartPoseDubins2D[2] = startPoseDubins2D[2];
        }
        unsigned long m = 0;
        m = (start_size >= goal_size) ? start_size : goal_size;
        std::vector<real64_T> tempMotionCost;
        tempMotionCost.resize(m);
        #ifdef IS_NOT_MATLAB_HOST
            autonomousDubinsDistanceCodegen_real64(&newStartPoseDubins2D[0], start_size, &newGoalPoseDubins2D[0], goal_size, mMinTurningRadius, &tempMotionCost[0]);
        #else
            autonomousDubinsDistanceCodegen_tbb_real64(&newStartPoseDubins2D[0], start_size, &newGoalPoseDubins2D[0], goal_size, mMinTurningRadius, &tempMotionCost[0]);
        #endif
        double currentTotalCost[2];
        currentTotalCost[0] = (tempMotionCost[0] + (lm[0] * mMinTurningRadius )) * tan(maxFlightPathAngle);
        currentTotalCost[1] = (tempMotionCost[1] + (lm[1] * mMinTurningRadius )) * tan(maxFlightPathAngle);
        if(currentTotalCost[0] > absAltitude)
        {
            luBounds[0][1] = lm[0];
        }
        else
        {
            luBounds[0][0] = lm[0];
        }
        if(currentTotalCost[1] > absAltitude)
        {
            luBounds[1][1] = lm[1];
        }
        else
        {
            luBounds[1][0] = lm[1];
        }
        iterCount++;
        EPS = std::abs(prevlm[0] - lm[0])+std::abs(prevlm[1] - lm[1]);
        prev_epsilon = nextafter(double(EPS) , d) - double(EPS);
        if(EPS < 5 * prev_epsilon)
        {
            if(iterCount >= maxIter)
            {
                iterFlag = false;
            }
            if((std::abs(currentTotalCost[0] - absAltitude) < ErrorTolerance) && (std::abs(currentTotalCost[1] - absAltitude) < ErrorTolerance))
            {
                *qualityFlag = 1;
                iterFlag = false;
                real64_T tempMotionType[6]{};
                real64_T motionLengths[6]{};
                char motionTypesDubins[4] = {'L' , 'R' , 'S' , '\0'};
                #ifdef IS_NOT_MATLAB_HOST
                    autonomousDubinsSegmentsCodegen_real64(&newStartPoseDubins2D[0],
                            start_size, // number of start pose
                            &newGoalPoseDubins2D[0],
                            goal_size, // number of goal pose
                            mMinTurningRadius,
                            Dubins2DPathTypes,
                            true,       // return optimal path (so isOptimal should be true)
                            3,          // calculate 2 outputs
                            motionCost, motionLengths, tempMotionType);
                #else
                    autonomousDubinsSegmentsCodegen_tbb_real64(&newStartPoseDubins2D[0],
                            start_size, // number of start pose
                            &newGoalPoseDubins2D[0],
                            goal_size, // number of goal pose
                            mMinTurningRadius,
                            Dubins2DPathTypes,
                            true,       // return optimal path (so isOptimal should be true)
                            3,          // calculate 2 outputs
                            motionCost, motionLengths, tempMotionType);
                #endif
                int counter = 0;
                for(int n = 0 ; n < 2 ; n++)
                {
                    for(int l = 0 ; l < 3 ; l++)
                    {
                        motionType[n][l] = motionTypesDubins[static_cast<int>(tempMotionType[counter])];
                        counter++;
                    }
                }
                counter = 0;
                for(int n = 0 ; n < 2 ; n++)
                {
                    for(int l = 0 ; l < 3 ; l++)
                    {
                        motionLength[n][l] = motionLengths[counter];
                        counter++;
                    }
                }
            }
        }
        prevlm[0] = lm[0];
        prevlm[1] = lm[1];
    }
}
void uav::UavDubinsConnection::addArc(std::string tempMotionType, double tempMotionCost, double* tempMotionLength,
        double maxFlightPathAngle, double lm, char strMotion, double& lowestMotionCost,
        UavDubinsPathsegments* psegObjs, int optStartCurve, bool flagOptimal, int signFlightPathAngle)
{
    double minTurningRadius = mMinTurningRadius;
    int tempIdx = -1;
    double tempMotionLengthNew[4];
    int I = 0;
    size_t disabledLength = mDisabledPathTypes.size();
    tempMotionType.push_back('N');
    double flightPathLength = (tempMotionCost + lm * minTurningRadius) / cos(maxFlightPathAngle);
    if(optStartCurve)
    {
        if(tempMotionType[0] == strMotion)
        {
            bool flag = true;
            for(size_t i = 0 ; i < disabledLength ; i++)
            {
                if(tempMotionType.compare(AllPathTypes[static_cast<size_t>(mDisabledPathTypes[i])]) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(size_t i = 0 ; i < 28; i++)
                {
                    if(tempMotionType.compare(AllPathTypes[i]) == 0)
                    {
                        I = static_cast<int>(i);
                        break;
                    }
                }
                tempMotionLength[0] += (lm * minTurningRadius);
                tempMotionLengthNew[0] = tempMotionLength[0];
                tempMotionLengthNew[1] = tempMotionLength[1];
                tempMotionLengthNew[2] = tempMotionLength[2];
                tempMotionLengthNew[3] = 0;
                tempIdx = I;
            }
        }
        else
        {
            for(size_t l = 3; l >= 1; l--)
            {
                tempMotionType[l] = tempMotionType[l-1];
            }
            tempMotionType[0] = strMotion;
            bool flag = true;
            for(size_t i = 0 ; i < disabledLength ; i++)
            {
                if(tempMotionType.compare(AllPathTypes[static_cast<size_t>(mDisabledPathTypes[i])]) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(size_t i = 0 ; i < 28; i++)
                {
                    if(tempMotionType.compare(AllPathTypes[i]) == 0)
                    {
                        I = static_cast<int>(i);
                        break;
                    }
                }
                tempIdx = I;
                tempMotionLengthNew[0] = lm*minTurningRadius;
                for(size_t i = 1 ; i < 4; i++)
                {
                    tempMotionLengthNew[i] = tempMotionLength[i-1];
                }
            }
        }
    }
    else
    {
        if(tempMotionType[2] == strMotion)
        {
            bool flag = true;
            for(size_t i = 0 ; i < disabledLength ; i++)
            {
                if(tempMotionType.compare(AllPathTypes[static_cast<size_t>(mDisabledPathTypes[i])]) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(size_t i = 0 ; i < 28; i++)
                {
                    if(tempMotionType.compare(AllPathTypes[i]) == 0)
                    {
                        I = static_cast<int>(i);
                        break;
                    }
                }
                tempIdx = I;
                tempMotionLength[2] += lm*minTurningRadius;
                tempMotionLengthNew[0] = tempMotionLength[0];
                tempMotionLengthNew[1] = tempMotionLength[1];
                tempMotionLengthNew[2] = tempMotionLength[2];
                tempMotionLengthNew[3] = 0;
            }
        }
        else
        {
            bool flag = true;
            tempMotionType[3] = strMotion;
            for(size_t i = 0 ; i < disabledLength ; i++)
            {
                if(tempMotionType.compare(AllPathTypes[static_cast<size_t>(mDisabledPathTypes[i])]) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(size_t i = 0 ; i < 28; i++)
                {
                    if(tempMotionType.compare(AllPathTypes[i]) == 0)
                    {
                        I = static_cast<int>(i);
                        break;
                    }
                }
                tempIdx = I;
                tempMotionLengthNew[3] = lm*minTurningRadius;
                for(int i = 0 ; i < 3; i++)
                {
                    tempMotionLengthNew[i] = tempMotionLength[i];
                }
            }
        }
    }
    if(tempIdx >= 0)
    {
        int offsetIndex = -1;
        bool flagProcess = false;
        if(flagOptimal)
        {
            if(flightPathLength < lowestMotionCost)
            {
                lowestMotionCost = flightPathLength;
                offsetIndex = 0;
                
                psegObjs[0].MotionTypes = (static_cast<int>(tempIdx));
                
                flagProcess = true;
            }
        }
        else
        {
            offsetIndex = tempIdx;
            flagProcess = true;
        }
        if(flagProcess)
        {
            psegObjs[offsetIndex].FlightPathAngle = (signFlightPathAngle * maxFlightPathAngle);
            for(size_t i = 0 ; i < 4; i++)
            {
                tempMotionLengthNew[i] /= cos(maxFlightPathAngle);
            }
            for(size_t i = 0; i < 4; i++)
            {
                psegObjs[offsetIndex].MotionLengths[i] = tempMotionLengthNew[i];
            }
        }
    }
}
