#ifndef CIRCLE_FORMATION_H
#define CIRCLE_FORMATION_H

#include <thread>
#include <stddef.h>
#include "rtwtypes.h"
#include <vector>
#include "MissionData.h"

class CircleFormation
{
private:
	MissionData* commonData;
	std::thread* background_thread{};                          //任务控制线程，绑定startMission函数

public:
	explicit CircleFormation(MissionData* const); // prevent implicit data type conversion
	friend std::thread* ert_thread(CircleFormation AlgEnd)
	{
		return AlgEnd.background_thread;
	};

	void rt_OneStep(void);
	void ert_main(void);
	void MissionMonitor(); //任务监控函数，监听公共数据域的任务指令
	void renameMATfile(void);
};

#endif
