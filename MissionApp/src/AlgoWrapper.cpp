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
	std::cout << "Waiting OS clock calibration..." << std::endl;
	std::unique_lock<std::mutex> lk(commonData->mutexSysTime);
	commonData->cvSysTime.wait(lk, [&](){return commonData->TimeCalibrated;});
	std::cout << "OS clock calibrated" << std::endl;
	MW_ert_main(); renameMATfile();
}

void AlgoWrapper::renameMATfile(void)
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