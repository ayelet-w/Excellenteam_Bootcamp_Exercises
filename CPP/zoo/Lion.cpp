
#include <iostream>
#include "Lion.h"
 void Lion::print() const
{
    std::cout<<"Pregnancy Duration :"<<(int)getPregnancyDuration()<<"\n";

    std::cout<<"Number of newborn :"<<(int)getNumberOfNewborn()<<"\n";
}