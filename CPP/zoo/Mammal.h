
#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H


struct IMammal{

    virtual unsigned char getPregnancyDuration() const = 0;

    virtual unsigned char getNumberOfNewborn() const = 0;

};





#endif
