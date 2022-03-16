#ifndef ALGORITHM_WRAPPER_H
#define ALGORITHM_WRAPPER_H

#include <thread>
#include <stddef.h>
#include "rtwtypes.h"
#include <vector>
#include "MissionData.h"

class AlgoWrapper
{
private:
	MissionData *commonData;
	std::thread* AlgoThread{};

public:
	explicit AlgoWrapper(MissionData *const); // prevent implicit data type conversion
	void AlgoThreadFunc();
	friend std::thread* getAlgoThread(AlgoWrapper AlgEnd) { return AlgEnd.AlgoThread; };
};

#endif
