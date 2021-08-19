#ifndef RTW_HEADER_MissionModes_h_
#define RTW_HEADER_MissionModes_h_
#include "rtwtypes.h"

typedef enum {
    CircNav = 1,
    CircDispNav = 11,
    HorzFrmnNav = 2,
    CustomFrmnNav = 22,
    RunWayNav = 3,
    ProtLine = 4,
    DetailedInsp = 128,
    CollAvoidance = 129,
    FlightMissionRH = 130,
    WaitToStart = 255,
    None = 0
} MissionModes;

#endif
