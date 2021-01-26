
#ifndef ZOO_DOG_H
#define ZOO_DOG_H
#include "Mammal.h"
#include "Animal.h"

class Dog: public IMammal , public Animal{
public:
    Dog(const std::string &name,const std::string &species) ;

    unsigned char getLifeExpectancy() const;

    const std::vector<CONTINENT> &getContinents() const;

    const std::vector<TYPE_OF_FOOD> & getTypeOfFoods() const;

    size_t getSpeed() const;

    unsigned char getPregnancyDuration() const;

    unsigned char getNumberOfNewborn() const;

    void print() const;

private:
    std::vector<CONTINENT> m_continents;

    std::vector<TYPE_OF_FOOD> m_type_of_food;

};
inline Dog::Dog(const std::string &name,const std::string &species) : Animal(name,species)
{

    m_continents.push_back(Europe);

    m_continents.push_back(Asian);

    m_continents.push_back(USA);

    m_type_of_food.push_back(Vegetarian);

    m_type_of_food.push_back(Meat);
}

inline unsigned char Dog::getLifeExpectancy() const
{
    static unsigned char DogLifeExpectancy = 30;

    return DogLifeExpectancy;
}

inline const std::vector<CONTINENT> &Dog::getContinents() const
{
    return m_continents;
}

inline const std::vector<TYPE_OF_FOOD> & Dog::getTypeOfFoods() const
{
    return m_type_of_food;
}

inline size_t Dog::getSpeed() const
{
    static size_t DogSpeed = 40;

    return DogSpeed;
}

inline unsigned char Dog::getPregnancyDuration() const
{
    static unsigned char DogPregnancyDuration= 60;

    return DogPregnancyDuration;
}

inline unsigned char Dog::getNumberOfNewborn() const
{
    static unsigned char DogNumberOfNewborn= 4;

    return DogNumberOfNewborn;
}




#endif //ZOO_DOG_H
