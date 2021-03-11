#include <MissionCircleFormation.h>

//----------------------------------------------------------------------------//
MissionCircleFormation::MissionCircleFormation()
{
    std::cout << "Initiating Circle Formation Mission thread..." << std::endl;

    //记录日志
    std::string logFile = "CircleFormation";
    logFile.append(".log");
    logForCircleFm.open(logFile, std::ios::app);
    if (!logForCircleFm.is_open())
    {
        std::cout << "Error: Cannot open logForCircleFm" << std::endl;
    }
    else
    {
        logForCircleFm << "----------New Trial---------" << std::endl;
    }
    //创建消息队列key所需的文件
    std::ofstream fout1("/etc/circleCtrl", std::fstream::out);
    if (!fout1.is_open())
    {
        std::cout << "Cannot write circleCtrl." << std::endl;
        return;
    }
    fout1.close();

    std::ofstream fout2("/etc/circleFSInfo", std::fstream::out);
    if (!fout2.is_open())
    {
        std::cout << "Cannot write circleFSInfo." << std::endl;
        return;
    }
    fout2.close();

    std::ofstream fout3("/etc/circleEXPFSInfo", std::fstream::out);
    if (!fout3.is_open())
    {
        std::cout << "Cannot write circleEXPFSInfo." << std::endl;
        return;
    }
    fout3.close();

    circleFm = new CircleFormation();
    missionData = new MissionData();
    circleFm->setCommonDataField(missionData);
    circleFm->init();
}
//----------------------------------------------------------------------------//
MissionCircleFormation::~MissionCircleFormation()
{
    logForCircleFm.close();
}
//----------------------------------------------------------------------------//
void MissionCircleFormation::setSysID(uint8_t id)
{
    selfid = id;
}
//----------------------------------------------------------------------------//
void MissionCircleFormation::setGroupID(uint8_t id)
{
    groupid = id;
}
//----------------------------------------------------------------------------//
void MissionCircleFormation::setAlgParam(double offset, double minDistance)
{
}
//----------------------------------------------------------------------------//
void MissionCircleFormation::start()
{
    if (ctrl_thread == NULL)
    {
        ctrl_thread = new std::thread(&MissionCircleFormation::startCtrl, this);
    }
    if (algorithm_thread == NULL)
    {
        algorithm_thread = new std::thread(&MissionCircleFormation::startCircle, this);
    }
}
void MissionCircleFormation::startCtrl()
{
    //--------开始任务消息队列初始化---------/
    //获取任务控制消息队列key值
    if ((keyCtrl = ftok(MSG_CIRCLE_CTRL, 'z')) < 0)
    {
        perror("ftok for circle ctrl error");
        exit(1);
    }
    // 打印key值
    //printf("Message Queue for circle control- key is: %d.\n", keyCtrl);
    // 创建消息队列
    if ((msgIDCtrl = msgget(keyCtrl, IPC_CREAT | 0777)) == -1)
    {
        perror("msgget for circle ctrl error");
        exit(1);
    }
    //打印任务控制消息队列ID
    //printf("Msgid for circle control is: %d.\n", msgIDCtrl);

    while (true)
    {
        std::cout << "Waiting for circle control message..." << std::endl;
        msgrcv(msgIDCtrl, &ctrlMsg, sizeof(struct CircleCtrl) - sizeof(long), 896, 0); // 返回类型为896的第一个消息
        printf("Receive circle control message: %d\n", ctrlMsg.cmd);
        missionData->setCtrlCmd(ctrlMsg.cmd);
        if (ctrlMsg.cmd == 0) //开始任务
        {
            startMission = true;
            std::cout << "开始环形封锁算法！" << std::endl;
        }
        else
        {
            startMission = false;
            std::cout << "结束环形封锁算法！" << std::endl;
        }
    }
}
//----------------------------------------------------------------------------//
void MissionCircleFormation::startCircle()
{
    //---------实时飞行状态消息队列初始化-------/
    //获取实时飞行状态消息队列key值
    if ((keyFS = ftok(MSG_CIRCLE_FS, 'z')) < 0)
    {
        perror("ftok for route error");
        exit(1);
    }
    // 打印key值
    //printf("Message Queue for flight status to circle- Server key is: %d.\n", keyFS);

    // 创建消息队列
    if ((msgIDFS = msgget(keyFS, IPC_CREAT | 0777)) == -1)
    {
        perror("msgget for flight status to circle error");
        exit(1);
    }
    //打印实时飞行状态消息队列ID
    //printf("Msgid for flight status to circle is: %d.\n", msgIDFS);

    //---------期望位置速度消息队列初始化-------------/
    //期望位置速度消息队列key值
    if ((keyExpFS = ftok(MSG_CIRCLE_EXPFS, 'z')) < 0)
    {
        perror("ftok for expected position and speed error");
        exit(1);
    }
    // 打印key值
    //printf("Message Queue for expected position and speed- Server key is: %d.\n", keyExpFS);

    // 创建消息队列
    if ((msgIDExpFS = msgget(keyExpFS, IPC_CREAT | 0777)) == -1)
    {
        perror("msgget for expected position and speed error");
        exit(1);
    }
    //打印期望位置速度消息队列ID及进程ID
    //printf("Msgid for expected position and speed is: %d.\n", msgIDExpFS);

    while (true)
    {
        std::cout << "Waiting for real time flight status message..." << std::endl;
        msgrcv(msgIDFS, &fs, sizeof(struct FlightStatus) - sizeof(long), 1001, 0); // 返回类型为1001的第一个消息
        printf("Real time flight status message received: %f, %f, %f. Speed:%f\n", fs.lon, fs.lat, fs.alt, fs.airspeed);
    
        try
        {
            missionData->updatePos(fs.lon, fs.lat, fs.height, fs.airspeed, fs.yaw, fs.pitch, fs.roll);
            //circleFm->rt_OneStep();
            std::vector<double> expPos;
            while (missionData->calComplete() != true)
            {
                usleep(10000);
            }
            missionData->getExpectedPos(expPos);
            expPosSpd = {897, expPos[1], expPos[2], expPos[3], expPos[3], expPos[0]};
        }
        catch (const std::exception &e)
        {
            std::cout << "ERROR:环形封锁算法发生内部错误！" << std::endl;
        }
        msgsnd(msgIDExpFS, &expPosSpd, sizeof(struct ExpectedPosSpd) - sizeof(long), 0);
        printf("Receive expected position and speed: %f, %f, %f. Speed:%f\n", expPosSpd.lon, expPosSpd.lat, expPosSpd.alt, expPosSpd.airspeed);
    }
    delete circleFm;
}
//初始化航路-------------------------------------------------------------------//
void MissionCircleFormation::initFlightPath()
{
    /*
    //读取保存的航路文件
    //航线id，航点id（1-4096），经，纬，高
    std::ifstream pathFile("/home/nvidia/flightPath.txt");
    if (!pathFile.is_open())
    {
        std::cout << "Error: Cannot open flightPath.txt" << std::endl;
    }
    else
    {
        std::cout << "Reading last air route" << std::endl;
        //获取文件总行数，确定航点数量
        int size = 0;
        std::string line;
        while (getline(pathFile, line))
        {
            size++;
        }
        routeLen = size - 1;
        if (routeLen <= 0)
            return;
        routeFromFile = new AirRoutePoint[routeLen];
        logForCircleFm << "Total waypoints:" << routeLen << std::endl;
        std::cout << "Total waypoints:" << routeLen << std::endl;
        pathFile.close();

        if (pathFile.is_open())
        {
            pathFile.close();
        }
        else
        {
            pathFile.open("/home/nvidia/flightPath.txt");
        }

        if (pathFile.is_open()) //判断是否再次打开了该文件
        {
            if (getline(pathFile, line)) //第一行为航线id
            {
                try
                {
                    routeID = std::stoi(line);
                    std::cout << "RouteID " << routeID << std::endl;
                    logForCircleFm << "RouteID" << routeID << std::endl;
                }
                catch (const std::exception &e)
                {
                    std::cout << "exception caught: " << e.what() << '\n';
                }
            }
            int index = 0;                  //用于标识航点号
            while (getline(pathFile, line)) //后续每行格式均为航点id:经:纬:高
            {
                try
                {
                    std::cout << line << std::endl;
                    int preLonPos = line.find(":", 0);
                    int preLatPos = line.find(",", 0);
                    int afterLatPos = preLatPos + 1;
                    int preAltPos = line.find(",", afterLatPos);
                    int wpNum = std::stoi(line.substr(0, preLonPos));                          //航点id
                    double lon = std::stod(line.substr(preLonPos + 1, preLatPos - preLonPos)); //经度
                    double lat = std::stod(line.substr(preLatPos + 1, preAltPos - preLatPos)); //纬度
                    double alt = std::stod(line.substr(preAltPos + 1));                        //高度
                    //std::cout << wpNum << " " << std::setprecision(10) << lon << " " << lat << " " << alt << std::endl;
                    logForCircleFm << wpNum << " " << std::setprecision(10) << lon << " " << lat << " " << alt << std::endl;
                    if (index < size - 1)
                    {
                        routeFromFile[index].longtitude = lon;
                        routeFromFile[index].latitude = lat;
                        routeFromFile[index].altitude = alt;
                        routeFromFile[index].waypointID = wpNum;
                        fileRouteSet = true;
                    }
                }
                catch (std::exception &e)
                {
                    std::cout << "exception caught: " << e.what() << '\n';
                }
                index++;
            }
            pathFile.close();
        }
    }
    */
}
//保存航路-------------------------------------------------------------------//
void MissionCircleFormation::saveFlightPath(AirRoutePoint *route, int len)
{
    /*
    std::cout << "Saving flight path" << std::endl;
    std::ofstream fout("/home/nvidia/flightPath.txt", std::fstream::out);
    if (!fout.is_open())
    {
        std::cout << "Cannot write file." << std::endl;
        return;
    }
    fout << "1" << std::endl;
    for (int i = 0; i < len; i++)
    {
        fout << route[i].waypointID << ":" << std::setprecision(10) << route[i].longtitude << "," << route[i].latitude << "," << route[i].altitude << std::endl;
    }

    fout.close();
    */
}
//----------------------------------------------------------------------------//
void MissionCircleFormation::join()
{
}

//----------------------------------------------------------------------------//
