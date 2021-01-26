
#ifndef ZOO_LION_H
#define ZOO_LION_H
#include "Animal.h"
#include "Mammal.h"

class Lion : public IMammal, public Animal{
public:
    Lion(const std::string &name , const std::string &species);

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
inline Lion::Lion(const std::string &name, const std::string &species) :Animal(name, species)
{
    m_continents.push_back(Africa);

    m_continents.push_back(Asian);

    m_continents.push_back(Australia);

    m_type_of_food.push_back(Meat);
}
inline unsigned char Lion::getLifeExpectancy() const
{
    static unsigned char LionLifeExpectancy = 30;

    return LionLifeExpectancy;
}

inline const std::vector<CONTINENT> & Lion::getContinents() const
{
    return m_continents;
}

inline const std::vector<TYPE_OF_FOOD> & Lion::getTypeOfFoods() const
{
    return m_type_of_food;
}

inline size_t Lion::getSpeed() const
{
    static size_t LionSpeed = 70;

    return LionSpeed;
}

inline unsigned char Lion::getPregnancyDuration() const
{
    static unsigned char LionPregnancyDuration= 110;

    return LionPregnancyDuration;
}

inline unsigned char Lion::getNumberOfNewborn() const
{
    static unsigned char LionNumberOfNewborn= 4;

    return LionNumberOfNewborn;
}


#endif //ZOO_LION_H
