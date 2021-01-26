

#ifndef ZOO_CLOWNFISH_H
#define ZOO_CLOWNFISH_H
#include "sea_creatures.h"
#include "Animal.h"

class ClownFish : public ISeaCreatures,public Animal{
public:
    ClownFish(const std::string &name,const std::string &species);

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
inline ClownFish::ClownFish(const std::string &name,const std::string &species) : Animal(name,species)
{
    m_continents.push_back(USA);

    m_continents.push_back(Asian);

    m_type_of_food.push_back(Reptiles);
}
inline unsigned char ClownFish::getLifeExpectancy() const
{
    static unsigned char ClownFishLifeExpectancy = 1;

    return ClownFishLifeExpectancy;
}

inline const std::vector<CONTINENT> & ClownFish::getContinents() const
{
    return m_continents;
}

inline const std::vector<TYPE_OF_FOOD> & ClownFish::getTypeOfFoods() const
{
    return m_type_of_food;
}

inline size_t ClownFish::getSpeed() const
{
    static size_t ClownFishSpeed = 30;

    return ClownFishSpeed;
}

inline unsigned int ClownFish::getLowestDepth() const
{
    static unsigned int ClownFishLowestDepth = 40;

    return ClownFishLowestDepth;
}




#endif //ZOO_CLOWNFISH_H
