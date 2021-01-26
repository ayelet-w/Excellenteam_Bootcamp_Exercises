
#include "Task_hello_world.h"

Task_hello_word::Task_hello_word(unsigned long cycles, unsigned long interval)
{
    m_number_of_cycles = cycles;
    m_interval_next_time = interval;
    m_time = 0;
}

void Task_hello_word::run()
{
    std::cout<< "Hello World!\n";
    m_time += m_interval_next_time;
    m_number_of_cycles--;
}

unsigned long Task_hello_word::getNextRunPeriod()
{
    if(m_number_of_cycles > 0)
        return m_time;
    else
        return 0;
}