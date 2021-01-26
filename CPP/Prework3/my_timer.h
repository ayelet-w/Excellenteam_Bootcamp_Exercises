//
// Created by ayelet on 9/22/20.
//

#ifndef PREWORK3_MY_TIMER_H
#define PREWORK3_MY_TIMER_H
#include "my_time.h"
#include "msg_printer.h"

class Timer {
private:
    Time target;
    Time clock;
    MsgPrinter *pprinter;
public:
    Timer(const Time &target, MsgPrinter * pprinter);

    inline void tic();//without args increments in 1 second
    inline void tic(unsigned int seconds);//increments that number of seconds
    inline void tic(std::string hour_minute);//with the string “M”, “m”, “Min”, “min”, “Minute” or “minute” increments in one minute
                                      //with the string “H”, “h”, “Hour”, “hour” increments in one hour
    inline void tic(std::string hour_minute,unsigned int number);

};
void run_timer_1();
void run_timer_2();
void run_timer_3();
void run_timer_4();

#endif //PREWORK3_MY_TIMER_H
