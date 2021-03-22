//
// File: ert_main.cpp
//
// Code generated for Simulink model 'codegenReal2Mission'.
//
// Model version                  : 2.137
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Mar 22 20:09:14 2021
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

void CircleFormation::init(void)
{
  if (background_thread == NULL)
  {
    background_thread = new std::thread(&CircleFormation::MissionMonitor, this);
  }
}

void CircleFormation::setCommonDataField(MissionData *data)
{
  this->commonData = data;
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
  pExtU_codegenReal2Mission_T.RealUAVLatLonState = commonData->getRealPos(); //从公共数据域获取实时位姿数据
  codegenReal2Mission_Obj.setExternalInputs(&pExtU_codegenReal2Mission_T);

  // Step the model for base rate
  codegenReal2Mission_Obj.step();

  // Get model outputs here
  codegenReal2Mission_Y = codegenReal2Mission_Obj.getExternalOutputs();
  this->commonData->setExpectedPos(codegenReal2Mission_Y); //向公共数据域更新期望航点和速度
  this->commonData->setOneStepResult(true);                //更新公共数据域标志位，通知数据收发端获取新的期望航点和速度

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
  auto SimulationStart = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> TimeElapsed{};
  std::chrono::milliseconds SimulationTime{};

  while ((rtmGetErrorStatus(codegenReal2Mission_Obj.getRTM()) == (NULL)) &&
         !rtmGetStopRequested(codegenReal2Mission_Obj.getRTM()))
  {
    rt_OneStep();
    std::cout << "Simulation Time: " << SimulationTime.count() << " milliseconds" << std::endl;

    // increment SimulationTime for 100ms
    const std::chrono::milliseconds tick{ 100 };
    SimulationTime += tick;

    if (this->commonData != NULL && this->commonData->getCtrlCmd() == 0) //结束任务
    {
      rtmSetErrorStatus(codegenReal2Mission_Obj.getRTM(), "Terminate");
    }  

    while (TimeElapsed < SimulationTime) // delay execution until next simulation tick
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      TimeElapsed = std::chrono::high_resolution_clock::now() - SimulationStart;
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