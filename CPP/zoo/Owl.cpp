#include <iostream>
#include "Owl.h"
void Owl::print() const
{
    std::cout<<"Typical Height: "<<getTypicalHeight()<<"\n";
    std::cout<<"Wing Span: "<<getWingSpan()<<"\n";

}