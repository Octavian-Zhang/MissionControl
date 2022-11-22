// This class manages POSIX mqueue creation and destruction

#ifndef MSG_QUEUE
#define MSG_QUEUE

#include <stdio.h>
#include <cstdlib>
#include <mqueue.h>
#include <errno.h>

class msgQueue
{
private:
    mqd_t MQ_;
    const char *qName_;

protected:
    const mqd_t &getMQ() { return MQ_; }
    int getAttr(struct mq_attr *attr) { return mq_getattr(MQ_, attr); }

public:
    msgQueue(const char *, int, int, int);
    ~msgQueue();
};

#endif