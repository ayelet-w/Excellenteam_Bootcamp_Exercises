
#ifndef ZOO_SHARK_H
#define ZOO_SHARK_H
#include "sea_creatures.h"
#include "Animal.h"

class Shark: public ISeaCreatures, public Animal {

public:
    Shark(const std::string &name,const std::string &species);

    unsigned char getLifeExpectancy() const;

    const std::vector<CONTINENT> &getContinents() const;

    const std::vector<TYPE_OF_FOOD> & getTypeOfFoods() const;

    size_t getSpeed() const;

    unsigned int getLowestDepth() const;

    void print() const;

private:

    std::vector<CONTINENT> m_continents;

    std::vector<TYPE_OF_FOOD> m_type_of_food;
};
inline Shark::Shark(const std::string &name,const std::string &species) : Animal(name,species)
{
    m_continents.push_back(USA);

    m_continents.push_back(Australia);

    m_type_of_food.push_back(Meat);

    m_type_of_food.push_back(Fish);
}
inline unsigned char Shark::getLifeExpectancy() const
{
    static unsigned char SharkLifeExpectancy = 10;

    return SharkLifeExpectancy;
}

inline const std::vector<CONTINENT> & Shark::getContinents() const
{
    return m_continents;
}

inline const std::vector<TYPE_OF_FOOD> & Shark::getTypeOfFoods() const
{
    return m_type_of_food;
}

inline size_t Shark::getSpeed() const
{
    static size_t SharkSpeed = 70;

    return SharkSpeed;
}

inline unsigned int Shark::getLowestDepth() const
{
    static unsigned int SharkLowestDepth = 20;

    return SharkLowestDepth;
}



#endif //ZOO_SHARK_H
