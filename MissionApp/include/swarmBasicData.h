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
#define MSG_CIRCLE_MISSION "/etc/circleMissionInfo"
#define MSG_CIRCLE_MISSION_FB "/etc/circleMissionInfoFB"

struct AvoidCtrl
{
    long msgType; //消息类型996
    int cmd;      //控制消息，0准备接收正常航路，1准备接受障碍物信息，2开始避障
};

struct CircleCtrl
{
    long msgType; //消息类型896
    int cmd;      //环形封锁控制消息，1开始任务，0结束任务
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
//威胁信息
struct AirObstacle
{
    long msgType;      // 消息类型999
    double longtitude; // 经度
    double latitude;   // 纬度
    double altitude;   // 高度
    double radius;     // 半径
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
    long msgType;    // 消息类型897
    double lon;      //经度
    double lat;      //纬度
    double alt;      //海拔
    double height;   //对地高度
    double airspeed; //空速
};

//编队控制参数
struct DebugParam
{
    long msgType;
    double kp;       /*<  unit:0.01, 0-10 */
    double ki;       /*<  unit:0.01, 0-10 */
    double kd;       /*<  unit:0.01, 0-10 */
    double distance; /*<  feedforward distance, unit:1 0-500 */
    double angle;    /*<  feedforward angle, unit:1, 0-90*/
    double offset;   /*<  feedforward offset, unit:1, 0-50*/
};
//僚机偏移量
struct FollowerOffset
{
    long msgType;
    int16_t x;
    int16_t y;
    int16_t z;
};
//位置参数
//本机及临机位姿信息
struct CenterPosition
{
    long msgType;
    double lon; //经度
    double lat; //纬度
    double alt; //海拔
};

//障碍物参数
struct ThreatPos
{
    int id;
    double lon;
    double lat;
    double height;
    double radius;
    int type;
};

struct LocationParam
{
    double Lat;
    double Lon;
    double Alt;
    double degHDG;
};

struct ParameterList
{
    float Param1;
    float Param2;
    float Param3;
    float Param4;
    float Param5;
    float Param6;
    float Param7;
};

struct StartTime
{
    int32_t year;
    int32_t month;
    int32_t day;
    int32_t hour;
    int32_t minute;
    int32_t second;
    int32_t millisecond;
};

//真·任务指令
struct MissionCmd
{
    long msgType;//898
    int32_t SequenceId;
    int32_t MissionMode;
    LocationParam MissionLocation;
    ParameterList params;
    LocationParam StartPosition;
    int32_t numUAV;
    int32_t FormationPos;
    StartTime startTime;
};

#endif
