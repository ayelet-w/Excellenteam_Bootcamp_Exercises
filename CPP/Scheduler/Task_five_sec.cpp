//
// Created by ayelet on 12/15/20.
//

#include "Task_five_sec.h"
#include <iostream>
Task_five_sec::Task_five_sec(unsigned long cycles)
{
    m_number_of_cycles = cycles;
    m_interval_next_time = 5;
    m_time = 0;
}

void Task_five_sec::run()
{
    std::cout<< "Five sec!\n";
    m_time += m_interval_next_time;
    m_number_of_cycles--;
}

unsigned long Task_five_sec::getNextRunPeriod()
{
    if(m_number_of_cycles > 0)
        return m_time;
    else
        return 0;
}