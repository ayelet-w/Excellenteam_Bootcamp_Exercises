
#ifndef ZOO_GOOSE_H
#define ZOO_GOOSE_H
#include "Bird.h"
#include "Animal.h"

class Goose : public IBird, public Animal{
public:
    Goose(const std::string &name,const std::string &species);

    unsigned char getLifeExpectancy() const;

    const std::vector<CONTINENT> &getContinents() const;

    const std::vector<TYPE_OF_FOOD> & getTypeOfFoods() const;

    size_t getSpeed() const;

    unsigned int getTypicalHeight() const;

    unsigned int getWingSpan() const;

    void print() const;

private:
    std::vector<CONTINENT> m_continents;

    std::vector<TYPE_OF_FOOD> m_type_of_food;

};
inline Goose::Goose(const std::string &name,const std::string &species) : Animal(name,species)
{
    m_continents.push_back(USA);

    m_continents.push_back(Europe);

    m_type_of_food.push_back(Vegetarian);

    m_type_of_food.push_back(Fish);

    m_type_of_food.push_back(Reptiles);
}
inline unsigned char Goose::getLifeExpectancy() const
{
    static unsigned char GooseLifeExpectancy = 5;

    return GooseLifeExpectancy;
}

inline const std::vector<CONTINENT> & Goose::getContinents() const
{
    return m_continents;
}

inline const std::vector<TYPE_OF_FOOD> & Goose::getTypeOfFoods() const
{
    return m_type_of_food;
}

inline size_t Goose::getSpeed() const
{
    static size_t GooseSpeed = 5;

    return GooseSpeed;
}

inline unsigned int Goose::getTypicalHeight() const
{
    unsigned int GooseTypicalHeight = 10;

    return GooseTypicalHeight;
}

inline unsigned int Goose::getWingSpan() const
{
    unsigned int GooseWingSpan = 12;

    return GooseWingSpan;
}



#endif //ZOO_GOOSE_H
