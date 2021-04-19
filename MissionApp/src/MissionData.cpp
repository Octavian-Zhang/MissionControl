#include "MissionData.h"

MissionData::MissionData()
{
}
MissionData::~MissionData()
{
}

// call by algorithm
void MissionData::setExtY(const codegenReal2MissionModelClass::ExtY_codegenReal2Mission_T &algExtY)
{
  const std::lock_guard<std::mutex> lock(mutexExtY);
  this->ExtY = algExtY;
}

const codegenReal2MissionModelClass::ExtU_codegenReal2Mission_T &MissionData::getExtU()
{
  const std::lock_guard<std::mutex> lock(mutexExtU);
  return this->ExtU;
}

IndividualUAVCmd* MissionData::getMissionCmd()
{
  if (this->cmdQueue.empty())
    return nullptr;
  {
    const std::lock_guard<std::mutex> lock(mutexQ);
    this->missionCmd = cmdQueue.front();
    cmdQueue.pop();
  }
  uavcmdLoc = {missionCmd.MissionLocation.Lat, missionCmd.MissionLocation.Lon, missionCmd.MissionLocation.Alt, missionCmd.MissionLocation.degHDG};
  uavcmdPara = {missionCmd.params.Param1, missionCmd.params.Param2, missionCmd.params.Param3, missionCmd.params.Param4, missionCmd.params.Param5, missionCmd.params.Param6, missionCmd.params.Param7};
  uavStartPos = {missionCmd.StartPosition.Lat, missionCmd.StartPosition.Lon, missionCmd.StartPosition.Alt, missionCmd.StartPosition.degHDG};
  uavcmdStartTime = {missionCmd.startTime.year, missionCmd.startTime.month, missionCmd.startTime.day, missionCmd.startTime.hour, missionCmd.startTime.minute, missionCmd.startTime.second, missionCmd.startTime.millisecond};
  this->uavCmd = {missionCmd.SequenceId, missionCmd.MissionMode, uavcmdLoc, uavcmdPara, uavStartPos, missionCmd.numUAV, missionCmd.FormationPos, uavcmdStartTime};
  return &this->uavCmd;
}

void MissionData::setMissionCmdFB(const IndividualUAVCmd &missionCmdFeedback)
{
  this->missionCmdFB =
      {
          899,
          missionCmdFeedback.SequenceId,
          missionCmdFeedback.MissionMode,
          {missionCmdFeedback.MissionLocation.Lat,
           missionCmdFeedback.MissionLocation.Lon,
           missionCmdFeedback.MissionLocation.Alt,
           missionCmdFeedback.MissionLocation.degHDG},
          {missionCmdFeedback.params.Param1,
           missionCmdFeedback.params.Param2,
           missionCmdFeedback.params.Param3,
           missionCmdFeedback.params.Param4,
           missionCmdFeedback.params.Param5,
           missionCmdFeedback.params.Param6,
           missionCmdFeedback.params.Param7},
          {missionCmdFeedback.StartPosition.Lat,
           missionCmdFeedback.StartPosition.Lon,
           missionCmdFeedback.StartPosition.Alt,
           missionCmdFeedback.StartPosition.degHDG},
          missionCmdFeedback.numUAV,
          missionCmdFeedback.FormationPos,
          {missionCmdFeedback.StartTime.year,
           missionCmdFeedback.StartTime.month,
           missionCmdFeedback.StartTime.day,
           missionCmdFeedback.StartTime.hour,
           missionCmdFeedback.StartTime.minute,
           missionCmdFeedback.StartTime.second,
           missionCmdFeedback.StartTime.millisecond}};
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
  const std::lock_guard<std::mutex> lock(mutexExtU);
  this->ExtU.RealUAVLatLonState = {fs.lat, fs.lon, fs.height, fs.airspeed, fs.yaw, fs.pitch, fs.roll};
  this->ExtU.FlightMode = fs.flightMode;
  this->ExtU.GroundSpeed = fs.groundspeed;
  this->ExtU.VectorSpd = {fs.eastSpeed, fs.northSpeed, fs.skySpeed};
  this->ExtU.Altitude = fs.alt;
}

//--------------供数据收发软件设置任务指令-------------------//
void MissionData::setMissionCmd(MissionCmd cmd)
{
  this->missionCmd = cmd;
  const std::lock_guard<std::mutex> lock(mutexQ);
  cmdQueue.push(cmd);
  //this->uavCmd = {this->missionCmd.SequenceId, this->missionCmd.MissionMode, this->missionCmd.MissionLocation, this->missionCmd.params, this->missionCmd.StartPosition, this->missionCmd.numUAV, this->missionCmd.FormationPos, this->missionCmd.startTime};
}

//--------------供数据收发软件设置任务指令反馈-------------------//
MissionCmd MissionData::getMissionCmdFeedback()
{
  return this->missionCmdFB;
}

//--------------供数据收发软件获取期望航点、速度---------//
void MissionData::getExpectedPos(std::vector<double> &expPos)
{
  const std::lock_guard<std::mutex> lock(mutexExtY);
  expPos.push_back(this->ExtY.RefAirspeed);
  expPos.push_back(this->ExtY.LookAheadPoint_i.Longitude_deg);
  expPos.push_back(this->ExtY.LookAheadPoint_i.Latitude_deg);
  expPos.push_back(this->ExtY.LookAheadPoint_i.Height_meter);
}
