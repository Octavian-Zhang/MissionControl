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

class MissionData
{
private:
    codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T codegenReal2Mission_Y; //期望航点和速度
    codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T pExtU_codegenReal2Mission_T;
    RealUAVStateBus state;        //数据收发程序发送的当前位姿信息
    int8_t commandID = -1;        //setCtrlCmd函数设置的指令ID，未设置时为-1，其余暂定
    bool oneStepComplete = false; //仿真飞机完成一步计算后设置此标志位为true
    std::mutex resMut, realPosMut, expPosMut;

public:
    MissionData();
    ~MissionData();
    //数据收发端调用                                                                                           
    void setCtrlCmd(int8_t cmdId);                                                                               //设置任务指令（开始、结束、任务类型等）
    void updatePos(double lon, double lat, double height, double airspd, double yaw, double pitch, double roll); //外部更新本类的state变量
    bool calComplete();                                                                                          //每一步计算完成后，设置本类的isCompleteOneStep成员变量，供数据收发类获取是否完成了一步计算
    void getExpectedPos(std::vector<double> &expPos);
    //算法端调用
    int8_t getCtrlCmd();                                                                   //获取数据收发软件设置的控制指令
    RealUAVStateBus getRealPos();                                                          //获取当前实时位置
    void setExpectedPos(codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T expPos); //设置计算出的期望航点和速度
    void setOneStepResult(bool result);                                                    //设置是否完成了一步计算
};

#endif
