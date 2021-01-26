#include <iostream>
#include "Monkey.h"


void Monkey::print() const
{

    std::cout<<"Pregnancy Duration :"<<(int)getPregnancyDuration()<<"\n";

    std::cout<<"Number of newborn :"<<(int)getNumberOfNewborn()<<"\n";
}