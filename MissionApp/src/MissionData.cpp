#include "MissionData.h"

MissionData::MissionData()
{
}
MissionData::~MissionData()
{
}

// call by algorithm
void MissionData::setExtY(const codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T& algExtY) {
	mutexExtY.lock();
	this->ExtY = algExtY;
	mutexExtY.unlock();
}

const codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T& MissionData::getExtU() {
	mutexExtU.lock();
	return this->ExtU;
	mutexExtU.unlock();
}

// call by IPC
//--------------供数据收发软件设置控制指令-------------------//
void MissionData::setCtrlCmd(int8_t cmdId)
{
	this->commandID = cmdId;
}

//--------------供数据收发软件更新位置-------------------//
void MissionData::updatePos(FlightStatus fs)
{
  mutexExtU.lock();
  this->ExtU.RealUAVLatLonState = {fs.lat, fs.lon, fs.height, fs.airspeed, fs.yaw, fs.pitch, fs.roll};
  this->ExtU.FlightMode = fs.flightMode;
  this->ExtU.GroundSpd = fs.groundspeed;
  this->ExtU.VectorSpd = {fs.eastSpeed, fs.northSpeed, fs.skySpeed};
  this->ExtU.Altitude = fs.alt;
  mutexExtU.unlock();
}

//--------------供数据收发软件获取期望航点、速度---------//
void MissionData::getExpectedPos(std::vector<double> &expPos)
{
  mutexExtY.lock();
  expPos.push_back(this->ExtY.RefAirspeed);
  expPos.push_back(this->ExtY.LookAheadPoint_j.Longitude_deg);
  expPos.push_back(this->ExtY.LookAheadPoint_j.Latitude_deg);
  expPos.push_back(this->ExtY.LookAheadPoint_j.Height_meter);
  mutexExtY.unlock();
}

