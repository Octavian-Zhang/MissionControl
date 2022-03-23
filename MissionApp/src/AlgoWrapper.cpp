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
#include "AlgoWrapper.h"
#include <iostream>
#include <string>
#include <fstream>
#include "MW_ert_main.h"

AlgoWrapper::AlgoWrapper(MissionData *const pCommonData) : commonData{pCommonData}
{
	if (nullptr == this->AlgoThread)
	{
		this->AlgoThread = new std::thread(&AlgoWrapper::AlgoThreadFunc, this);
	}
}

void AlgoWrapper::AlgoThreadFunc()
{
	std::cout << "Waiting OS clock calibration..." << std::endl;
	// std::unique_lock<std::mutex> lk(commonData->mutexSysTime);
	// commonData->cvSysTime.wait(lk, [&](){return commonData->TimeCalibrated;});
	std::cout << "OS clock calibrated" << std::endl;
	MW_ert_main();
}