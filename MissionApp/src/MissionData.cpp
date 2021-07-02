#include "MissionData.h"

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

IndividualUAVCmd *MissionData::getMissionCmd()
{
	MissionCmd NewCMD{};
	{
		const std::lock_guard<std::mutex> lock(mutexQ);
		NewCMD = std::move(cmdQueue.front());
		cmdQueue.pop();
	}
	uavcmdLoc = {NewCMD.MissionLocation.Lat, NewCMD.MissionLocation.Lon, NewCMD.MissionLocation.Alt, NewCMD.MissionLocation.degHDG};
	uavcmdPara = {	NewCMD.params.Param1, 
					NewCMD.params.Param2, 
					NewCMD.params.Param3, 
					NewCMD.params.Param4, 
					NewCMD.params.Param5, 
					NewCMD.params.Param6, 
					NewCMD.params.Param7};
	uavStartPos = {	NewCMD.StartPosition.Lat, 
					NewCMD.StartPosition.Lon, 
					NewCMD.StartPosition.Alt, 
					NewCMD.StartPosition.degHDG};
	uavcmdStartTime = {	NewCMD.startTime.year, 
						NewCMD.startTime.month, 
						NewCMD.startTime.day, 
						NewCMD.startTime.hour, 
						NewCMD.startTime.minute, 
						NewCMD.startTime.second, 
						NewCMD.startTime.millisecond};
	this->uavCmd = {NewCMD.SequenceId, MissionModes(NewCMD.MissionMode), 
					uavcmdLoc, uavcmdPara, uavStartPos, NewCMD.numUAV, NewCMD.FormationPos, uavcmdStartTime};
	return &this->uavCmd;
}

void MissionData::setMissionCmdFB(const IndividualUAVCmd &missionCmdFeedback)
{
	std::unique_lock<std::mutex> lk(this->mutexFeedbackCMD);
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
	this->feedbackFlag = true;
	lk.unlock();
	this->cvFeedbackCMD.notify_one();
}

// call by IPC

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
void MissionData::setMissionCmd(MissionCmd&& cmd)
{
	const std::lock_guard<std::mutex> lock(mutexQ);
	cmdQueue.push(std::move(cmd));
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

bool MissionData::NewMissionCMD()
{
	const std::lock_guard<std::mutex> lock(mutexQ); 
	return !cmdQueue.empty();
}