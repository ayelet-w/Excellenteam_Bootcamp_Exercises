#include <iostream>
#include "Dog.h"
void Dog::print() const
{
    std::cout<<"Pregnancy Duration :"<<(int)getPregnancyDuration()<<"\n";

    std::cout<<"Number of newborn :"<<(int)getNumberOfNewborn()<<"\n";

}