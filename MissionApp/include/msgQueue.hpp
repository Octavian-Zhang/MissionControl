// This class manages POSIX mqueue creation and destruction

#ifndef MSG_QUEUE
#define MSG_QUEUE

#include <stdio.h>
#include <cstdlib>
#include <mqueue.h>

class msgQueue
{
private:
    mqd_t MQ_;
    const char *qName_;

public:
    msgQueue(const char *, int, int, int);
    const mqd_t getMQ() { return MQ_; }
    int getAttr(struct mq_attr *attr) { return mq_getattr(MQ_, attr); }
    ~msgQueue();
};

msgQueue::msgQueue(const char *name, int flags, int maxmsg, int msgsize) : qName_{name}
{
    struct mq_attr attr;
    attr.mq_flags = 0; /* Flags (ignored for mq_open()) */
    attr.mq_maxmsg = maxmsg;
    attr.mq_msgsize = msgsize;

    MQ_ = mq_open(qName_, flags, 0664, &attr);

    if (this->MQ_ < 0)
    {
        printf("mq_open failed\n");
        exit(1);
    }
}

msgQueue::~msgQueue()
{
    if (mq_close(MQ_) < 0)
    {
        printf("mq_close failed\n");
        exit(1);
    }
    if (mq_unlink(qName_) < 0)
    {
        printf("mq_unlink failed\n");
        exit(1);
    }
}

#endif