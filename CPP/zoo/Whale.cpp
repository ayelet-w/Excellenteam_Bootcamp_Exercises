#include <iostream>
#include "Whale.h"
void Whale::print() const
{
    std::cout<<"Pregnancy Duration :"<<(int)getPregnancyDuration()<<"\n";

    std::cout<<"Number of newborn :"<<(int)getNumberOfNewborn()<<"\n";

    std::cout<<"Lowest Depth :"<<getLowestDepth()<<"\n";
}
