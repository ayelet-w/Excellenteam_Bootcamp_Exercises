
#ifndef ZOO_OWL_H
#define ZOO_OWL_H
#include "Bird.h"
#include "Animal.h"

class Owl : public IBird, public Animal{
public:
    Owl(const std::string &name,const std::string &species);

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
inline Owl::Owl(const std::string &name,const std::string &species) : Animal(name,species)
{
    m_continents.push_back(Europe);

    m_type_of_food.push_back(Reptiles);
}
inline unsigned char Owl::getLifeExpectancy() const
{
    static unsigned char GooseLifeExpectancy = 15;

    return GooseLifeExpectancy;
}

inline const std::vector<CONTINENT> & Owl::getContinents() const
{
    return m_continents;
}

inline const std::vector<TYPE_OF_FOOD> & Owl::getTypeOfFoods() const
{
    return m_type_of_food;
}

inline size_t Owl::getSpeed() const
{
    static size_t OwlSpeed = 19;

    return OwlSpeed;
}

inline unsigned int Owl::getTypicalHeight() const
{
    unsigned int OwlTypicalHeight = 10;

    return OwlTypicalHeight;
}

inline unsigned int Owl::getWingSpan() const
{
    unsigned int OwlWingSpan = 12;

    return OwlWingSpan;
}




#endif //ZOO_OWL_H
