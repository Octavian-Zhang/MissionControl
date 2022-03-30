#ifndef DataLog
#define DataLog

#include "sqlite_orm.h"
#include "codegenReal2Mission.h"

#define initStorage(path) make_storage(path,                                                                    \
                        make_table<RealUAVStateBus>("RealUAVState",                                             \
                                make_column("Latitude_deg", &RealUAVStateBus::Latitude_deg),                    \
                                make_column("Longitude_deg", &RealUAVStateBus::Longitude_deg),                  \
                                make_column("Height_meter", &RealUAVStateBus::Height_meter),                    \
                                make_column("AirSpeed_mps", &RealUAVStateBus::AirSpeed_mps),                    \
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
                                make_column("Latitude_deg", &FCUCMD::Latitude_deg),                             \
                                make_column("Longitude_deg", &FCUCMD::Longitude_deg),                           \
                                make_column("Height_meter", &FCUCMD::Height_meter),                             \
                                make_column("RefAirSpd_mps", &FCUCMD::RefAirSpd_mps)),                          \
                        make_table<InternalStatus>("InnerState",                                                \
                                make_column("LagDistance", &InternalStatus::LagDistance),                       \
                                make_column("CrossTrackError", &InternalStatus::CrossTrackError),               \
                                make_column("EngagedFlag", &InternalStatus::EngagedFlag),                       \
                                make_column("RealHeading", &InternalStatus::RealHeading),                       \
                                make_column("TargetHeading", &InternalStatus::TargetHeading),                   \
                                make_column("HeadingDiff", &InternalStatus::HeadingDiff),                       \
                                make_column("ADRC_U", &InternalStatus::ADRC_U),                                 \
                                make_column("biasH", &InternalStatus::biasH),                                   \
                                make_column("HdgStatus", &InternalStatus::HdgStatus)),                          \
                        make_table<MiscellaneousFlightStatus>("MiscStatus",                                     \
                                make_column("GroundSpeed", &MiscellaneousFlightStatus::GroundSpeed),            \
                                make_column("FlightMode", &MiscellaneousFlightStatus::FlightMode),              \
                                make_column("Altitude", &MiscellaneousFlightStatus::Altitude),                  \
                                make_column("FlightPath", &MiscellaneousFlightStatus::FlightPath)),             \
                        make_table<VectorSpeed>("VectorSpd",                                                    \
                                make_column("eastSpeed", &VectorSpeed::eastSpeed),                              \
                                make_column("northSpeed", &VectorSpeed::northSpeed),                            \
                                make_column("skySpeed", &VectorSpeed::skySpeed)))                               

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