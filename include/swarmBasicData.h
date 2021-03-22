#ifndef SWARM_BASIC_DATA_H
#define SWARM_BASIC_DATA_H

#include <string>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

//创建key
#define MSG_AVD_CTRL "/etc/avdCtrl"
#define MSG_AVD_OBSINFO "/etc/avdObsInfo"
#define MSG_AVD_ROUTE "/etc/avdRoute"
#define MSG_ORIG_ROUTE "/etc/origRoute"

//环形封锁
#define MSG_CIRCLE_CTRL "/etc/circleCtrl"
#define MSG_CIRCLE_FS "/etc/circleFSInfo"
#define MSG_CIRCLE_EXPFS "/etc/circleEXPFSInfo"

struct CircleCtrl
{
    long msgType;      //消息类型896
    int cmd;           //环形封锁控制消息，0开始任务，1结束任务
};

//航路中的航点
struct AirRoutePoint
{
    long msgType;      // 消息类型，正常航路997，避障航路998
    int waypointID;    // 航点ID，1、2、3，最后一个4096
    double longtitude; // 经度
    double latitude;   // 纬度
    double altitude;   // 高度
};

//实时位姿
struct FlightStatus
{
    long msgType;       // 消息类型1000，用于circle为1001
    double lon;         //经度
    double lat;         //纬度
    double alt;         //海拔
    double height;      //对地高度
    double yaw;         //偏航
    double pitch;       //俯仰
    double roll;        //滚转
    double airspeed;    //空速
    double groundspeed; //地速
    double northSpeed;  //北方向速度
    double eastSpeed;   //东方向速度
    double skySpeed;    //天方向速度
    uint8_t flightMode; //飞行模式
};

//实时位姿
struct ExpectedPosSpd
{
    long msgType;       // 消息类型897
    double lon;         //经度
    double lat;         //纬度
    double alt;         //海拔
    double height;      //对地高度
    double airspeed;    //空速
};

#endif