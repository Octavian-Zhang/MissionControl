#include <MissionCircleFormation.h>
#include <CircleFormation.h>

MissionCircleFormation::MissionCircleFormation()
{
    std::cout << "Initiating Circle Formation Mission thread..." << std::endl;

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

    missionData = new MissionData();
    circleFm = new CircleFormation(missionData);
}

MissionCircleFormation::~MissionCircleFormation()
{
    delete missionData;
    delete circleFm;
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

    while (true) // lock step execution with System V IPC
    {
        std::cout << "Waiting for real time flight status message..." << std::endl;
        msgrcv(msgIDFS, &fs, sizeof(struct FlightStatus) - sizeof(long), 1001, 0); // 返回类型为1001的第一个消息
        printf("Real time flight status message received: %f, %f, %f. Speed:%f\n", fs.lon, fs.lat, fs.alt, fs.airspeed);

        // set algorithm input
        missionData->updatePos(fs);
        std::vector<double> expPos;

        // get algorithm output
        missionData->getExpectedPos(expPos);
        expPosSpd = {897, expPos[1], expPos[2], expPos[3], expPos[3], expPos[0]};

        msgsnd(msgIDExpFS, &expPosSpd, sizeof(struct ExpectedPosSpd) - sizeof(long), 0);
        printf("Receive expected position and speed: %f, %f, %f. Speed:%f\n", expPosSpd.lon, expPosSpd.lat, expPosSpd.alt, expPosSpd.airspeed);
    }
}

//----------------------------------------------------------------------------//
void MissionCircleFormation::join(){
    std::thread* ert_main_thread = ert_thread(*circleFm);
    ert_main_thread->join();
}
//----------------------------------------------------------------------------//
