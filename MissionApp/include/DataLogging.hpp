#ifndef DataLog
#define DataLog

#include <iostream>
#include "sqlite_orm.h"
#include "codegenReal2Mission.h"

#define initStorage(path) make_storage(path,                                                                    \
                        make_table<RealUAVStateBus>("RealUAVState",                                             \
                                make_column("UAV_ID", &RealUAVStateBus::UAV_ID),                                \
                                make_column("Latitude_deg", &RealUAVStateBus::Latitude_deg),                    \
                                make_column("Longitude_deg", &RealUAVStateBus::Longitude_deg),                  \
                                make_column("Height_meter", &RealUAVStateBus::Height_meter),                    \
                                make_column("Altitude_meter", &RealUAVStateBus::Altitude_meter),                \
                                make_column("AirSpeed_mps", &RealUAVStateBus::AirSpeed_mps),                    \
                                make_column("GndSpd_mps", &RealUAVStateBus::GndSpd_mps),                        \
                                make_column("HeadingAngle_deg", &RealUAVStateBus::HeadingAngle_deg),            \
                                make_column("FlightPathAngle_deg", &RealUAVStateBus::FlightPathAngle_deg),      \
                                make_column("RollAngle_deg", &RealUAVStateBus::RollAngle_deg)),                 \
                        make_table<FixedWingGuidanceStateBus>("SimUAVState",                                    \
                                make_column("North", &FixedWingGuidanceStateBus::North),                        \
                                make_column("East", &FixedWingGuidanceStateBus::East),                          \
                                make_column("Height", &FixedWingGuidanceStateBus::Height),                      \
                                make_column("AirSpeed", &FixedWingGuidanceStateBus::AirSpeed),                  \
                                make_column("HeadingAngle", &FixedWingGuidanceStateBus::HeadingAngle),          \
                                make_column("FlightPathAngle", &FixedWingGuidanceStateBus::FlightPathAngle),    \
                                make_column("RollAngle", &FixedWingGuidanceStateBus::RollAngle),                \
                                make_column("RollAngleRate", &FixedWingGuidanceStateBus::RollAngleRate)),       \
                        make_table<FCUCMD>("FlightCMD",                                                         \
                                make_column("RefLatitude_deg", &FCUCMD::RefLatitude_deg),                       \
                                make_column("RefLongitude_deg", &FCUCMD::RefLongitude_deg),                     \
                                make_column("RefHeight_meter", &FCUCMD::RefHeight_meter),                       \
                                make_column("RefHdg_deg", &FCUCMD::RefHdg_deg),                                 \
                                make_column("RefAirSpd_mps", &FCUCMD::RefAirSpd_mps),                           \
                                make_column("RefGndSpd_mps", &FCUCMD::RefGndSpd_mps)),                          \
                        make_table<InternalStatus>("InnerState",                                                \
                                make_column("LagDistance", &InternalStatus::LagDistance),                       \
                                make_column("CrossTrackError", &InternalStatus::CrossTrackError),               \
                                make_column("EngagedFlag", &InternalStatus::EngagedFlag),                       \
                                make_column("RealHeading", &InternalStatus::RealHeading),                       \
                                make_column("TargetHeading", &InternalStatus::TargetHeading),                   \
                                make_column("HeadingDiff", &InternalStatus::HeadingDiff),                       \
                                make_column("biasH", &InternalStatus::biasH),                                   \
                                make_column("HdgStatus", &InternalStatus::HdgStatus),                           \
                                make_column("FlightMode", &InternalStatus::FlightMode),                         \
                                make_column("AvoidDanger", &InternalStatus::AvoidDanger)),                      \
                        make_table<VectorSpeed>("VectorSpd",                                                    \
                                make_column("eastSpeed", &VectorSpeed::eastSpeed),                              \
                                make_column("northSpeed", &VectorSpeed::northSpeed),                            \
                                make_column("skySpeed", &VectorSpeed::skySpeed)),                               \
                        make_table<ADRC>("ADRC_Log",                                                            \
                                make_column("x1_ControlError", &ADRC::x1_ControlError),                         \
                                make_column("x2", &ADRC::x2),                                                   \
                                make_column("x3_TotalDisturbance", &ADRC::x3_TotalDisturbance),                 \
                                make_column("u", &ADRC::u)),                                                    \
                        make_table<Time>("TimeNow",                                                             \
                                make_column("year", &Time::year),                                               \
                                make_column("month", &Time::month),                                             \
                                make_column("day", &Time::day),                                                 \
                                make_column("hour", &Time::hour),                                               \
                                make_column("minute", &Time::minute),                                           \
                                make_column("second", &Time::second),                                           \
                                make_column("millisecond", &Time::millisecond)))


using namespace sqlite_orm;
using Storage = decltype(initStorage(""));

class DataLogging
{
private:
        Storage storage_;
        DataLogging(const std::string&);
public:
        static void wrtieLog(const FlightLogging*);
        DataLogging(DataLogging const&) = delete;
        void operator=(DataLogging const&) = delete;
};

#endif