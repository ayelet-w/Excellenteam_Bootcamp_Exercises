

#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H

struct IBird
{
    virtual unsigned int getTypicalHeight() const = 0;

    virtual unsigned int getWingSpan() const = 0;

};



#endif //ZOO_BIRD_H
