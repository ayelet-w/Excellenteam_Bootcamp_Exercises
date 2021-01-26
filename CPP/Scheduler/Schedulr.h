
#ifndef SCHEDULER_SCHEDULR_H
#define SCHEDULER_SCHEDULR_H
#include <queue>
#include "Itask.h"

class Schedulr
{
public:
    void run_tasks();
    void insert_task(ITask * task){m_queue.push(task);}
private:
    std::queue<ITask*> m_queue;
};


#endif
