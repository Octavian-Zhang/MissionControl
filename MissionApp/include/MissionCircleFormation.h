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

class MissionCircleFormation
{
public:
	MissionCircleFormation();
	~MissionCircleFormation();

	void start();                //启动后台运算线程
	void startCircle();          //环形编队算法
	void startCtrl();            //控制指令接收线程
	void startMission();         //任务指令接收线程
	void startMissionFeedback(); //任务指令反馈线程
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

	std::thread* ctrl_thread;
	std::thread* algorithm_thread;
	std::thread* mission_thread;
	std::thread* mission_fb_thread;

	int msgIDCtrl, msgIDFS, msgIDExpFS, msgIDMission, msgIDMissionFB;
	key_t keyCtrl, keyFS, keyExpFS, keyMission, keyMissionFB;

	struct CircleCtrl ctrlMsg;
	struct FlightStatus fs;
	struct ExpectedPosSpd expPosSpd;
	struct MissionCmd msCmd;
	struct MissionCmd msCmdFb;

	CircleFormation* circleFm;
	MissionData* missionData;

	// prevent shallow copy & assignment
	MissionCircleFormation(const MissionCircleFormation&);
	MissionCircleFormation& operator=(const MissionCircleFormation&);
};

#endif
