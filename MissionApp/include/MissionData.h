#ifndef MISSION_DATA_H
#define MISSION_DATA_H

#include <stdio.h>
#include "codegenReal2Mission.h" // Model's header file
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <vector>
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include <mutex>

#include "swarmBasicData.h"

class MissionData
{
private:
    // Algorithm IO
    codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T ExtY;
    codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T ExtU;

    // IPC flags
    int8_t commandID = -1;        //setCtrlCmd函数设置的指令ID，未设置时为-1，其余暂定

    std::mutex mutexExtY, mutexExtU;

public:
    MissionData();
    ~MissionData();
    // Call by Algorithm
    void setExtY(const codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T&);
    const codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T& getExtU();
    // Call by IPC
    void setCtrlCmd(int8_t cmdId);   //设置任务指令（开始、结束、任务类型等）
    void updatePos(FlightStatus fs); //外部更新本类的state变量
    void getExpectedPos(std::vector<double> &expPos);
};

#endif
