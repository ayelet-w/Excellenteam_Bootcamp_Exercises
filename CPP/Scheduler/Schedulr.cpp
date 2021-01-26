//
// Created by ayelet on 12/15/20.
//

#include "Schedulr.h"

void Schedulr::run_tasks()
{
    while(!m_queue.empty())
    {
        ITask * curr = m_queue.front();
        curr->run();
        if(curr->getNextRunPeriod() > 0)
        {
            m_queue.push(curr);
        }
        m_queue.pop();
    }
}