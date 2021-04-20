#ifndef CIRCLE_FORMATION_H
#define CIRCLE_FORMATION_H

#include <thread>
#include <stddef.h>
#include <stdio.h>               // This circleFormation.c example uses printf/fflush
#include "codegenReal2Mission.h" // Model's header file
#include "rtwtypes.h"
#include <vector>
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "rt_logging.h"
#include "MissionData.h"
#ifndef SAVEFILE
#define MATFILE2(file) #file ".mat"
#define MATFILE1(file) MATFILE2(file)
#define MATFILE MATFILE1(MODEL)
#else
#define QUOTE1(name) #name
#define QUOTE(name) QUOTE1(name) // need to expand name
#define MATFILE QUOTE(SAVEFILE)
#endif

class CircleFormation
{
private:
  class codegenReal2MissionModelClassSendData_IndividualUAVCmdT : public SendData_IndividualUAVCmdT
  { // nested send CMD Msg class def
    MissionData *pCommonData;

  public:
    codegenReal2MissionModelClassSendData_IndividualUAVCmdT(MissionData *pMissionData) : pCommonData{pMissionData} {};
    void SendData(const IndividualUAVCmd *, int32_T, int32_T *);
  };
  class codegenReal2MissionModelClassRecvData_IndividualUAVCmdT : public RecvData_IndividualUAVCmdT
  { // nested receive CMD Msg class def
    MissionData *pCommonData;

  public:
    IndividualUAVCmd *missionCmd{}; //任务指令指针
    codegenReal2MissionModelClassRecvData_IndividualUAVCmdT(MissionData *pMissionData) : pCommonData{pMissionData} {};
    void RecvData(IndividualUAVCmd *, int32_T, int32_T *);
  };

  MissionData *commonData;

  codegenReal2MissionModelClassRecvData_IndividualUAVCmdT MissionCMDRecvData_arg{commonData};
  codegenReal2MissionModelClassSendData_IndividualUAVCmdT CurrentMissionSendData_arg{commonData};
  codegenReal2MissionModelClass codegenReal2Mission_Obj{
      CurrentMissionSendData_arg, MissionCMDRecvData_arg}; // Instance of model class
  std::thread *background_thread;                          //任务控制线程，绑定startMission函数

public:
  explicit CircleFormation(MissionData *const); // prevent implicit data type conversion
  friend std::thread *ert_thread(CircleFormation AlgEnd)
  {
    return AlgEnd.background_thread;
  };

  void rt_OneStep(void);
  void ert_main(void);
  void MissionMonitor(); //任务监控函数，监听公共数据域的任务指令
  void renameMATfile(void);
};

#endif
