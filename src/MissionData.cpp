#include "MissionData.h"
MissionData::MissionData()
{
}
MissionData::~MissionData()
{
}
///--------------------------------------供数据收发端调用------------------------------------///
//--------------供数据收发软件设置控制指令-------------------//
void MissionData::setCtrlCmd(int8_t cmdId)
{
  this->commandID = cmdId;
}
//--------------供数据收发软件更新位置-------------------//
void MissionData::updatePos(double lon, double lat, double height, double airspd, double yaw, double pitch, double roll)
{
  printf("Common data update: %f, %f, %f, %f, %f, %f, %f\n", lon, lat, height, airspd, yaw, pitch, roll);
  realPosMut.lock();
  this->state = {lat, lon, height, airspd, yaw, pitch, roll};
  realPosMut.unlock();
}
//--------------供数据收发软件获取是否已更新期望航点-----//
bool MissionData::calComplete()
{
  return this->oneStepComplete;
}
//--------------供数据收发软件获取期望航点、速度---------//
void MissionData::getExpectedPos(std::vector<double> &expPos)
{
  expPos.push_back(codegenReal2Mission_Y.RefAirspeed);
  expPos.push_back(codegenReal2Mission_Y.LookAheadPoint_j.Longitude_deg);
  expPos.push_back(codegenReal2Mission_Y.LookAheadPoint_j.Latitude_deg);
  expPos.push_back(codegenReal2Mission_Y.LookAheadPoint_j.Height_meter);
}
///
///--------------------------------------供算法端调用------------------------------------///
///
//--------------获取控制指令----------------------------//
int8_t MissionData::getCtrlCmd()
{
  return this->commandID;
}
//--------------获取实时位姿----------------------------//
RealUAVStateBus MissionData::getRealPos()
{
  return this->state;
}
//--------------设置期望航点和速度----------------------//
void MissionData::setExpectedPos(codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T expPos)
{
  expPosMut.lock();
  this->codegenReal2Mission_Y.LookAheadPoint_j.Longitude_deg = expPos.LookAheadPoint_j.Longitude_deg;
  this->codegenReal2Mission_Y.LookAheadPoint_j.Latitude_deg = expPos.LookAheadPoint_j.Latitude_deg;
  this->codegenReal2Mission_Y.LookAheadPoint_j.Height_meter = expPos.LookAheadPoint_j.Height_meter;
  this->codegenReal2Mission_Y.RefAirspeed = expPos.RefAirspeed;
  expPosMut.unlock();
}
//--------------设置标志位，标识期望航点和速度是否已更新--//
void MissionData::setOneStepResult(bool result)
{
  resMut.lock();
  this->oneStepComplete = result;
  resMut.unlock();
}
