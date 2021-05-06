#ifndef MISSION_DATA_H
#define MISSION_DATA_H

#include <stdio.h>
#include "codegenReal2Mission.h" // Model's header file
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "zero_crossing_types.h"
#include <vector>
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include <mutex>
#include <queue>
#include "DatalinkInterface.h"
#include "swarmBasicData.h"

class MissionData
{
private:
	// Algorithm IO
	codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T ExtY;
	codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T ExtU;

	// IPC flags
	int8_t commandID = -1; //setCtrlCmd函数设置的指令ID，未设置时为-1，其余暂定
	std::queue<MissionCmd> cmdQueue;
	MissionCmd missionCmd, missionCmdFB; //任务指令、任务指令反馈
	IndividualUAVCmd uavCmd, uavCmdFB;   //算法用任务指令、任务指令反馈
	Location uavcmdLoc, uavStartPos;
	Parameters uavcmdPara;
	Time uavcmdStartTime;

	std::mutex mutexExtY, mutexExtU, mutexQ;

public:
	MissionData();
	~MissionData();
	// Call by Algorithm
	void setExtY(const codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T&);
	const codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T& getExtU();
	IndividualUAVCmd* getMissionCmd();
	void setMissionCmdFB(const IndividualUAVCmd& missionCmdFeedback);
	bool feedbackFlag = false; //任务进度反馈标识，当存在任务进度反馈消息时，设为true
	// Call by IPC
	void setCtrlCmd(int8_t cmdId);      //设置任务指令（开始、结束、任务类型等）
	void setMissionCmd(MissionCmd cmd); //设置任务信息
	MissionCmd getMissionCmdFeedback(); //获取任务信息反馈
	void updatePos(FlightStatus fs);    //外部更新本类的state变量
	void getExpectedPos(std::vector<double>& expPos);
	int8_T showCmdID() {return commandID;};
};

#endif