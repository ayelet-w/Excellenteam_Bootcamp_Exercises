//
// Created by ayelet on 9/21/20.
//

#ifndef PREWORK3_MY_TIME_H
#define PREWORK3_MY_TIME_H
#include <string>
#include <iostream>
class Time {
private:
    unsigned int hours;//0—100,000
    unsigned short minutes;//0-59
    unsigned short seconds ;//0-59
    static const unsigned short SIXTY=60;
    static const unsigned short TWENTY_FOUR=24;
    static const unsigned short ZERO=0;
    static const unsigned short FIFTY_NINE=59;
    static const unsigned int LIMITED_HOURS=100000;
    static char day_delimiter ;
    static char time_delimiter;
public:
    //ctor
    Time(unsigned int hours,unsigned short minutes,unsigned short seconds=0);

    Time(unsigned short seconds);

    Time();

    //Getter
    unsigned int getHours() const;

    unsigned short getMinutes() const;

    unsigned short getSeconds() const;
    //Setter
    void setHours(unsigned int hours);

    void setMinutes(unsigned short minutes);

    void setSeconds(unsigned short seconds);
    //function
    std::string get_as_str(bool is_using_days) const;

    int get_seconds();

    static void print_with_delimiter(char,char);
    //operators
    Time operator+(const Time &);

    Time operator+(const unsigned long);

    friend Time operator+(unsigned long seconds,Time time);

    void operator+=(const unsigned long);

    bool operator==(const Time &);

    bool operator!=(const Time &);

    bool operator<(const Time &);

    bool operator<=(const Time &);

    bool operator>(const Time &);

    bool operator>=(const Time &);

    friend std::ostream & operator << (std::ostream & os, Time time);

    friend void time_reset(Time * time);
};

void print(const Time & time);

void time_reset(Time * time);

#endif //PREWORK3_MY_TIME_H
