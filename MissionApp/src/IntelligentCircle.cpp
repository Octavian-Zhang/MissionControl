#include "MissionCircleFormation.h"

MissionData *pCommonData = new MissionData();

//程序入口---------------------------------------------------------------------//
int main(int argc, char *argv[])
{
	std::cout << "Initiating Mission Control..." << std::endl;
	MissionCircleFormation *circleMission = new MissionCircleFormation(pCommonData);
	//启动环形封锁任务
	circleMission->start();
	circleMission->join();
}
//----------------------------------------------------------------------------//