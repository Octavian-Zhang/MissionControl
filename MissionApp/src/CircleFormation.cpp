//
// Code generated for Simulink model 'codegenReal2Mission'.
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
#include "CircleFormation.h"
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>

CircleFormation::CircleFormation(MissionData *const pCommonData) : commonData{pCommonData}
{
	if (background_thread == NULL)
	{
		background_thread = new std::thread(&CircleFormation::MissionMonitor, this);
	}
}

void CircleFormation::codegenReal2MissionModelClassSendData_IndividualUAVCmdT::
	SendData(const IndividualUAVCmd *data, int32_T length, int32_T *status)
{
	// Add send data logic here
	// 存在任务反馈信息时，通过下述代码设置标识、更新数据
	pCommonData->feedbackFlag = true;
	pCommonData->setMissionCmdFB(*data);
}

void CircleFormation::codegenReal2MissionModelClassRecvData_IndividualUAVCmdT::
	RecvData(IndividualUAVCmd *data, int32_T length, int32_T *status)
{
	// Add receive data logic here
	//下一行代码获取数据收发软件发送过来的任务指令
	*data = *missionCmd;
}

void CircleFormation::renameMATfile(void)
{
	// declare automatic model file name
	const std::string src_name = "MODEL.mat";

	// define source file stream
	std::ifstream src(src_name.c_str(), std::ios::binary);

	// generate destination file name with timestamp
	auto end_t = std::chrono::high_resolution_clock::now();
	auto epoch_end_t = end_t.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::nanoseconds>(epoch_end_t);
	long timestamp = value.count();
	std::string des_name = std::to_string(timestamp) + ".mat";

	// define destination file stream
	std::ofstream dst(des_name.c_str(), std::ios::binary);

	// write file to destination
	dst << src.rdbuf();
}

// temporal logic of mission algorithm
void CircleFormation::MissionMonitor()
{
	std::cout << "Waiting OS clock calibration..." << std::endl;
	while (1 != commonData->showCmdID()) // delay execution until simulation start
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	std::cout << "OS clock calibrated" << std::endl;
	ert_main();
	renameMATfile();
}

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void CircleFormation::rt_OneStep(void)
{
	static boolean_T OverrunFlag = false;

	// Disable interrupts here

	// Check for overrun
	if (OverrunFlag)
	{
		rtmSetErrorStatus(codegenReal2Mission_Obj.getRTM(), "Overrun");
		return;
	}

	OverrunFlag = true;

	// Save FPU context here (if necessary)
	// Re-enable timer or interrupt here
	// Set model inputs here
	codegenReal2Mission_Obj.setExternalInputs(&commonData->getExtU());

	// Step the model for base rate
	codegenReal2Mission_Obj.step();

	// Get model outputs here
	commonData->setExtY(codegenReal2Mission_Obj.getExternalOutputs());

	// Indicate task complete
	OverrunFlag = false;

	// Disable interrupts here
	// Restore FPU context here (if necessary)
	// Enable interrupts here
}

void CircleFormation::ert_main(void)
{
	// Initialize model
	codegenReal2Mission_Obj.initialize();

	// Initiate std::chrono based real-time interrupt
	auto SimulationStart = std::chrono::steady_clock::now();
	std::chrono::duration<double> TimeElapsed{};
	std::chrono::milliseconds SimulationTime{};

	while ((rtmGetErrorStatus(codegenReal2Mission_Obj.getRTM()) == (NULL)) &&
		   !rtmGetStopRequested(codegenReal2Mission_Obj.getRTM()))
	{
		rt_OneStep();
		// std::cout << "Running Time: " << SimulationTime.count() << " milliseconds" << std::endl;
		std::cout << "." << std::flush;

		// Store received MissionCmd from IPC into missionCmd data member
		MissionCMDRecvData_arg.missionCmd = commonData->getMissionCmd();
		if (nullptr != MissionCMDRecvData_arg.missionCmd)
		{ // Push New Mission if new command available
			std::cout << "Push New Mission!" << std::endl;
			codegenReal2Mission_Obj.codegenReal2Mission_PushNewMission();
		} //若missionCmd为nullptr，说明消息队列中没有任务指令；若不为空，则missionCmd指向最旧一条任务指令

		// increment SimulationTime for 100ms
		const std::chrono::milliseconds tick{100};
		SimulationTime += tick;

		while (TimeElapsed < SimulationTime) // delay execution until next simulation tick
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			TimeElapsed = std::chrono::steady_clock::now() - SimulationStart;
		}
	}

	// Matfile logging
	rt_StopDataLogging(MATFILE, codegenReal2Mission_Obj.getRTM()->rtwLogInfo);

	// Terminate model
	codegenReal2Mission_Obj.terminate();
}
//
// File trailer for generated code.
//
// [EOF]
//