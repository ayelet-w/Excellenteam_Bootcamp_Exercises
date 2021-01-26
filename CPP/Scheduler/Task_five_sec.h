

#ifndef SCHEDULER_TASK_FIVE_SEC_H
#define SCHEDULER_TASK_FIVE_SEC_H
#include "Itask.h"

class Task_five_sec: public ITask
{
public:
    Task_five_sec(unsigned long cycles = 0);
    void run();
    unsigned long getNextRunPeriod();
private:
    unsigned long m_number_of_cycles;
    unsigned long m_interval_next_time;
    unsigned long m_time;
};


#endif
