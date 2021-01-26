

#ifndef SCHEDULER_TASK_HELLO_WORD_H
#define SCHEDULER_TASK_HELLO_WORD_H
#include "Itask.h"
#include <iostream>

class Task_hello_word : public ITask
{
public:
    Task_hello_word(unsigned long cycles = 0, unsigned long interval = 0);
    void run();
    unsigned long getNextRunPeriod();
private:
    unsigned long m_number_of_cycles;
    unsigned long m_interval_next_time;
    unsigned long m_time;
};


#endif //SCHEDULER_TASK_HELLO_WORD_H
