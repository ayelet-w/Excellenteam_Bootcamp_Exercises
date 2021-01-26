#include <iostream>
#include "Goose.h"

void Goose::print() const
{
    std::cout<<"Typical Height: "<<getTypicalHeight()<<"\n";
    std::cout<<"Wing Span: "<<getWingSpan()<<"\n";

}