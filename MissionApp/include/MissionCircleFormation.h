#ifndef MISSION_CIRCLE_FORMATION_H
#define MISSION_CIRCLE_FORMATION_H

#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <sys/time.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "CircleFormation.h"
#include "swarmBasicData.h"
#include "unistd.h"

//创建key
#define MSG_CIRCLE_CTRL "/etc/circleCtrl"
#define MSG_CIRCLE_FS "/etc/circleFSInfo"
#define MSG_CIRCLE_EXPFS "/etc/circleEXPFSInfo"

class MissionCircleFormation
{
public:
    MissionCircleFormation();
    ~MissionCircleFormation();

    void start();       //启动后台运算线程
    void startCircle(); //环形编队算法
    void startCtrl();   //控制指令接收线程
    void join();

    void setSysID(uint8_t id);
    void setGroupID(uint8_t id);

    void setAlgParam(double offset, double minDistance);

private:
    uint8_t testX = 0;
    uint8_t selfid;
    uint8_t groupid = 0xFF;

    //For log
    std::ofstream logForCircleFm;

    std::thread *ctrl_thread;
    std::thread *algorithm_thread;

    int msgIDCtrl, msgIDFS, msgIDExpFS;
    key_t keyCtrl, keyFS, keyExpFS;

    struct CircleCtrl ctrlMsg;
    struct FlightStatus fs;
    struct ExpectedPosSpd expPosSpd;

    bool startMission = false;

    CircleFormation *circleFm;
    MissionData *missionData;
};

#endif
