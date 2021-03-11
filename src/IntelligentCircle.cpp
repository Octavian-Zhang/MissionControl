#include <unistd.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "MissionCircleFormation.h"

//----------------------------------------------------------------------------//
int main(int argc, char* argv[])
{   
    std::cout << "Initiating Intelligent Circle Formation..." << std::endl;

	MissionCircleFormation* circleMission = new MissionCircleFormation();
    /*Config::setParameterFile("home/nvidia/dataDispatch/config/config.ini", "System");
    uint8_t planeID = Config::get<int8_t>("SelfUavId");
    circleMission->setSysID(planeID);*/

    //启动环形封锁任务
    circleMission->start();

    while(true)
    {
        sleep(500);
    }
}

//----------------------------------------------------------------------------//
