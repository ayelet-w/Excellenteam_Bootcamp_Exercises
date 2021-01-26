
#ifndef ZOO_MONKEY_H
#define ZOO_MONKEY_H
#include "Mammal.h"
#include "Animal.h"

class Monkey : public IMammal , public Animal{
public:
    Monkey(const std::string &name , const std::string &species);

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
inline Monkey::Monkey(const std::string &name , const std::string &species) : Animal(name,species)
{
    m_continents.push_back(Australia);

    m_continents.push_back(Africa);

    m_type_of_food.push_back(Vegetarian);
}
inline unsigned char Monkey::getLifeExpectancy() const
{
    static unsigned char MonkeyLifeExpectancy = 12;

    return MonkeyLifeExpectancy;
}

inline const std::vector<CONTINENT> & Monkey::getContinents() const
{
    return m_continents;
}

inline const std::vector<TYPE_OF_FOOD> & Monkey::getTypeOfFoods() const
{
    return m_type_of_food;
}

inline size_t Monkey::getSpeed() const
{
    static size_t MonkeySpeed = 20;

    return MonkeySpeed;
}

inline unsigned char Monkey::getPregnancyDuration() const
{
    static unsigned char MonkeyPregnancyDuration= 240;

    return MonkeyPregnancyDuration;
}

inline unsigned char Monkey::getNumberOfNewborn() const
{
    static unsigned char MonkeyNumberOfNewborn= 2;

    return MonkeyNumberOfNewborn;
}


#endif //ZOO_MONKEY_H
