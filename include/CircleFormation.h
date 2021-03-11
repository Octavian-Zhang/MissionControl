#ifndef CIRCLE_FORMATION_H
#define CIRCLE_FORMATION_H

#include <thread>
#include <stddef.h>
#include <stdio.h>               // This circleFormation.c example uses printf/fflush
#include "codegenReal2Mission.h" // Model's header file
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <vector>
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
    codegenReal2MissionModelClass codegenReal2Mission_Obj; // Instance of model class
    codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T codegenReal2Mission_Y; //期望航点和速度
    codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T pExtU_codegenReal2Mission_T;
    std::thread *background_thread;//任务控制线程，绑定startMission函数
    MissionData *commonData;

public:
    void init(void);//初始化任务
    void rt_OneStep(void);
    void logData();
    void MissionMonitor();//任务监控函数，监听公共数据域的任务指令
    void setCommonDataField(MissionData *data);//设置公共数据域指针
};

#endif
