//
// Created by ayelet on 9/21/20.
//

#include "my_time.h"
#include <stdexcept>
#include <stdio.h>
#include <iostream>
Time::Time(unsigned int hours,unsigned short minutes,unsigned short seconds) :
hours(hours),minutes(minutes),seconds(seconds)
{
    if (hours < ZERO || hours > LIMITED_HOURS)
    {
        this->hours=0;
        throw std::invalid_argument("Invalid Hours parameter");
    }
    if (minutes < ZERO || minutes > FIFTY_NINE)
    {
        this->minutes=0;
        throw std::invalid_argument("Invalid minutes parameter");
    }
    if(seconds < ZERO || seconds > FIFTY_NINE)
    {
        this->seconds=0;
        throw std::invalid_argument("Invalid seconds parameter");
    }
}

Time::Time(unsigned short seconds)
{
    this->seconds = seconds % SIXTY;
    seconds/= SIXTY;
    this->minutes = seconds % SIXTY;
    seconds/= SIXTY;
    this->hours = seconds % SIXTY;
};

Time::Time() {
    this->hours=0;
    this->minutes=0;
    this->seconds=0;
}

unsigned int Time::getHours() const {
    return hours;
}

unsigned short Time::getMinutes() const {
    return minutes;
}

unsigned short Time::getSeconds() const {
    return seconds;
}

void Time::setHours(unsigned int hours) {
    Time::hours = hours;
    if (hours < ZERO || hours > LIMITED_HOURS)
    {
        this->hours = 0;
        throw std::invalid_argument("Invalid Hours parameter");
    }

}

void Time::setMinutes(unsigned short minutes) {
    Time::minutes = minutes;
    if (minutes < ZERO || minutes > FIFTY_NINE)
    {
        this->minutes = 0;
        throw std::invalid_argument("Invalid minutes parameter");
    }
}

void Time::setSeconds(unsigned short seconds) {
    Time::seconds = seconds;
    if (seconds < ZERO || seconds > FIFTY_NINE)
    {
        this->seconds=0;
        throw std::invalid_argument("Invalid seconds parameter");
    }
}

std::string Time::get_as_str(bool is_using_days) const
{
    char result[13];
    if(is_using_days)
    {
        unsigned short days;
        days=this->hours/TWENTY_FOUR;
        sprintf(result,"%d%c%d%c%d%c%d",days,this->day_delimiter,this->hours%TWENTY_FOUR,this->time_delimiter,this->minutes,this->time_delimiter,this->seconds);
    }
    else
    {
        sprintf(result,"%d%c%d%c%d",this->hours,this->time_delimiter,this->minutes,this->time_delimiter,this->seconds);
    }

    return (std::string)result;
}

int Time::get_seconds()
{
    int result = this->getSeconds() + this->getMinutes() * SIXTY + this->getHours() * SIXTY * SIXTY;
    return result;
}

Time Time::operator+(const Time & time) {
    Time result(0,0,0);
    result.setSeconds((this->getSeconds() + time.getSeconds()) % SIXTY);
    unsigned short carry = (this->getSeconds() + time.getSeconds()) / SIXTY;
    result.setMinutes((this->getMinutes() + time.getMinutes() + carry) % SIXTY);
    carry = (this->getMinutes() + time.getMinutes() + carry) / SIXTY;
    result.setHours(this->getHours() + time.getHours() + carry);
    if(result.hours>LIMITED_HOURS)
        result.hours=LIMITED_HOURS;
    return result;
}

Time Time::operator+(const unsigned long seconds) {
    Time result(0,0,0);
    result.setSeconds((this->getSeconds() + seconds ) % SIXTY);
    unsigned short carry = (this->getSeconds() + seconds) / SIXTY;
    result.setMinutes((this->getMinutes()  + carry) % SIXTY);
    carry = (this->getMinutes() + carry) / SIXTY;
    result.setHours(this->getHours() + carry);
    if(result.hours>LIMITED_HOURS)
        result.hours=LIMITED_HOURS;
    return result;
}

Time operator+(unsigned long seconds, Time time) {
    Time result=time+seconds;
    return result;
}

void Time::operator+=(const unsigned long seconds) {
    this->setSeconds((this->getSeconds() + seconds ) % SIXTY);
    unsigned short carry = (this->getSeconds() + seconds) / SIXTY;
    this->setMinutes((this->getMinutes()  + carry) % SIXTY);
    carry = (this->getMinutes() + carry) / SIXTY;
    this->setHours(this->getHours() + carry);
    if(this->hours>LIMITED_HOURS)
        this->hours=LIMITED_HOURS;
}

bool Time::operator==(const Time & time) {
    return (this->getSeconds()==time.getSeconds()
       && this->getMinutes()==time.getMinutes()
       && this->getHours() == time.getHours());
}

bool Time::operator!=(const Time & time) {
    return !(*this==time);
}

bool Time::operator<(const Time & time) {
    if(this->getHours() < time.getHours())
        return true;
    else if(this->getHours() == time.getHours() &&
           this->getMinutes() < time.getMinutes())
        return true;
    else if(this->getHours() == time.getHours() &&
            this->getMinutes() == time.getMinutes() &&
            this->getSeconds() < time.getSeconds())
        return true;
    return false;
}

bool Time::operator<=(const Time & time) {
    return (*this < time || *this == time);
}

bool Time::operator>(const Time & time) {
    return (!(*this <= time) );
}

bool Time::operator>=(const Time & time) {
    return !(*this < time );
}

std::ostream & operator<<(std::ostream &os, Time time) {
    os<<time.get_as_str(true);
    return os;
}
char Time::day_delimiter='.';
char Time::time_delimiter=':';
void Time::print_with_delimiter(char day_delimiter_, char time_delimiter_){
    if(isdigit(day_delimiter_) || isdigit(time_delimiter_))
    {
        day_delimiter = '.';
        time_delimiter = ':';
        throw std::invalid_argument("Invalid delimiter");
    }
    day_delimiter=day_delimiter_;
    time_delimiter=time_delimiter_;
}

void print(const Time & time)
{
    std::cout<<time.getHours()/24<<"/"<<time.getHours()%24<<"/"<<time.getMinutes()<<"/"<<time.getSeconds()<<"\n";
}

void time_reset(Time * time)
{
    time->hours=0;
    time->minutes=0;
    time->seconds=0;
}





