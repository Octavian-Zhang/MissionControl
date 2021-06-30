#ifndef MISSION_DATA_H
#define MISSION_DATA_H

#include <vector>
#include <mutex>
#include <queue>
#include <iostream>
#include <condition_variable>
#include "codegenReal2Mission.h"
#include "DatalinkInterface.h"
#include "protocol.h"

class MissionData
{
private:
	// Algorithm IO
	codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T ExtY;
	codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T ExtU;

	// IPC flags
	std::queue<MissionCmd> cmdQueue;
	MissionCmd missionCmdFB; //任务指令、任务指令反馈
	IndividualUAVCmd uavCmd, uavCmdFB;	 //算法用任务指令、任务指令反馈
	Location uavcmdLoc, uavStartPos;
	Parameters uavcmdPara;
	Time uavcmdStartTime;

	std::mutex mutexExtY, mutexExtU, mutexQ;

public:
	// system time calibration
	bool TimeCalibrated = false; // determine the operating system has been calibrated
	std::condition_variable cvSysTime;
	std::mutex mutexSysTime;

	// Call by Algorithm
	void setExtY(const codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T &);
	const codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T &getExtU();
	IndividualUAVCmd *getMissionCmd();
	void setMissionCmdFB(const IndividualUAVCmd &missionCmdFeedback);
	bool feedbackFlag = false; //任务进度反馈标识，当存在任务进度反馈消息时，设为true
	bool NewMissionCMD();

	// Call by IPC
	void setMissionCmd(MissionCmd&& cmd); //设置任务信息
	MissionCmd getMissionCmdFeedback(); //获取任务信息反馈
	void updatePos(FlightStatus fs);	//外部更新本类的state变量
	void getExpectedPos(std::vector<double> &expPos);
};

#endif