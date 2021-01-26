//
// Created by ayelet on 9/22/20.
//

#include "my_timer.h"
#include <unistd.h>
#include <vector>
#include <list>
Timer::Timer(const Time &target,MsgPrinter * pprinter): target(target), pprinter (pprinter) {}

 void Timer::tic() {
    this->clock+=1;
    if(this->clock >= target)
        pprinter->print();
}

 void Timer::tic(unsigned int seconds) {
    this->clock+=seconds;
    if(this->clock >= target)
        pprinter->print();
}

 void Timer::tic(std::string hour_minute) {
    if(hour_minute=="M" || hour_minute=="m" || hour_minute=="Min" || hour_minute=="min" || hour_minute=="Minute" || hour_minute=="minute")
        this->clock+=60;
    else if (hour_minute=="H" || hour_minute=="h" || hour_minute=="Hour" || hour_minute=="hour")
        this->clock = clock + (60*60);
    else
        throw std::invalid_argument("Invalid string");
    if(this->clock >= target)
        pprinter->print();
}

void Timer::tic(std::string hour_minute, unsigned int number) {
    if(hour_minute=="M" || hour_minute=="m" || hour_minute=="Min" || hour_minute=="min" || hour_minute=="Minute" || hour_minute=="minute") {
        number = number * 60;
        this->clock+=number;
    }
    else if (hour_minute=="H" || hour_minute=="h" || hour_minute=="Hour" || hour_minute=="hour"){
        number = number * 60 * 60;
        this->clock+=number;
    }
    else
        throw std::invalid_argument("Invalid string");

    if(this->clock >= target)
        pprinter->print();
}

void run_timer_1()
{
    MsgPrinter msgPrinter("Hello world");
    Timer timer(Time(1,30,0),&msgPrinter);
    for (int i = 0; i < 50; i++) {
        std::cout<<"Iteration number: "<<(i+1)<<"\n";
        timer.tic("min",2);
    }
}
void run_timer_2()
{
    MsgPrinter msgPrinter("Seven Seconds");
    Timer timer(Time(0,0,7),&msgPrinter);
    for (int i = 0; i < 10; ++i) {
        sleep(1);
        std::cout<<"Iteration number: "<<(i+1)<<"\n";
        timer.tic();
    }

}

void run_timer_3()
{
    std::vector<MsgPrinter *> printers(3);
    MsgPrinter *msgPrinter=new MsgPrinter("This is the message");
    printers[0]=msgPrinter;
    MsgPrinterSurrounding *msgPrinterSurrounding=new MsgPrinterSurrounding("Surrounded","---Start---","----End----");
    printers[1]=msgPrinterSurrounding;
    MsgPrinterMultipleSurrounding *msgPrinterMultipleSurrounding=new MsgPrinterMultipleSurrounding("Really Surrounded",">>>>>>>","<<<<<<<",3);
    printers[2]=msgPrinterMultipleSurrounding;
    Timer t1(Time(0,0,10),printers[0]);
    Timer t2(Time(0,0,15),printers[1]);
    Timer t3(Time(0,0,20),printers[1]);
    Timer t4(Time(0,0,25),printers[2]);
    Timer t5(Time(0,0,30),printers[2]);
    for (int i = 0; i < 40; ++i) {
        std::cout<<"Iteration number: "<<(i+1)<<"\n";
        t1.tic();
        t2.tic();
        t3.tic();
        t4.tic();
        t5.tic();
    }
    for(int j = 0; j < 3; j++)
    {
        delete printers[j];
    }
}


void run_timer_4()
{
    std::vector<MsgPrinter *> printers(3);
    MsgPrinter *msgPrinter=new MsgPrinter("This is the message");
    printers[0]=msgPrinter;
    MsgPrinterSurrounding *msgPrinterSurrounding=new MsgPrinterSurrounding("Surrounded","---Start---","----End----");
    printers[1]=msgPrinterSurrounding;
    MsgPrinterMultipleSurrounding *msgPrinterMultipleSurrounding=new MsgPrinterMultipleSurrounding("Really Surrounded",">>>>>>>","<<<<<<<",3);
    printers[2]=msgPrinterMultipleSurrounding;
    std::list<Timer> timers_list;
    timers_list.push_back(Timer(Time(0,0,10),printers[0]));
    timers_list.push_back(Timer (Time(0,0,15),printers[1]));
    timers_list.push_back(Timer(Time(0,0,20),printers[1]));
    timers_list.push_back(Timer(Time(0,0,25),printers[2]));
    timers_list.push_back(Timer(Time(0,0,30),printers[2]));
    std::list<Timer>::iterator itr=timers_list.begin();
    for (int i = 0; i < 80; ++i) {
        std::cout<<"Iteration number: "<<(i+1)<<"\n";
        while(itr!=timers_list.end())
        {
            itr->tic();
            itr++;
        }
       itr=timers_list.begin();
    }
    for(int j = 0; j < 3; j++)
    {
        delete printers[j];
    }
}