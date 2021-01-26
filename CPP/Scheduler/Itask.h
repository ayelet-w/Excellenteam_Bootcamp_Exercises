

#ifndef SCHEDULER_ITASK_H
#define SCHEDULER_ITASK_H

struct ITask
{
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0;//Absolutetimesinceboot-up (in milliseconds)};
};



#endif //SCHEDULER_ITASK_H
