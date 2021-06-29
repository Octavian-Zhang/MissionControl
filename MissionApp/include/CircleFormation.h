#ifndef CIRCLE_FORMATION_H
#define CIRCLE_FORMATION_H

#include <thread>
#include <stddef.h>
#include "rtwtypes.h"
#include <vector>
#include "MissionData.h"

class CircleFormation
{
private:
	MissionData *commonData;
	void renameMATfile(void);

public:
	explicit CircleFormation(MissionData *const); // prevent implicit data type conversion
};

#endif
