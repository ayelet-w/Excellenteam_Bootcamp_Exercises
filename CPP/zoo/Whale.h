

#ifndef ZOO_WHALE_H
#define ZOO_WHALE_H
#include "Animal.h"
#include "Mammal.h"
#include "sea_creatures.h"

class Whale : public ISeaCreatures, public IMammal, public Animal{
public:
    Whale(const std::string &name , const std::string &species);

    unsigned char getLifeExpectancy() const;

     const std::vector<CONTINENT> &getContinents() const;

    const std::vector<TYPE_OF_FOOD> & getTypeOfFoods() const;

    size_t getSpeed() const;

    unsigned char getPregnancyDuration() const;

    unsigned char getNumberOfNewborn() const;

    unsigned int getLowestDepth() const;

    void print() const;

private:
    std::vector<CONTINENT> m_continents;

    std::vector<TYPE_OF_FOOD> m_type_of_food;

};
inline Whale::Whale(const std::string &name , const std::string &species) : Animal(name,species)
{
    m_continents.push_back(USA);

    m_continents.push_back(Europe);

    m_type_of_food.push_back(Vegetarian);

    m_type_of_food.push_back(Fish);
}
inline unsigned char Whale::getLifeExpectancy() const
{
    static unsigned char WhaleLifeExpectancy = 100;

    return WhaleLifeExpectancy;
}

inline const std::vector<CONTINENT> & Whale::getContinents() const
{
    return m_continents;

}

inline const std::vector<TYPE_OF_FOOD> & Whale::getTypeOfFoods() const
{
    return m_type_of_food;
}

inline size_t Whale::getSpeed() const
{
    static size_t WhaleSpeed = 40;

    return WhaleSpeed;
}

inline unsigned char Whale::getPregnancyDuration() const
{
    static unsigned char WhalePregnancyDuration= 240;

    return WhalePregnancyDuration;
}

inline unsigned char Whale::getNumberOfNewborn() const
{
    static unsigned char WhaleNumberOfNewborn= 1;

    return WhaleNumberOfNewborn;
}

inline unsigned int Whale::getLowestDepth() const
{
    static unsigned int WhaleLowestDepth = 30;

    return WhaleLowestDepth;
}




#endif //ZOO_WHALE_H
