#include "Animal.h"

#ifndef ZOO_ZOO_H
#define ZOO_ZOO_H

class Zoo {
public:
    Zoo();

    void addAnimal(Animal *);

    void printAllAnimals();

    const std::vector<Animal *> &getAnimals() const;

private:
    std::vector<Animal*> m_animals;

};
inline const std::vector<Animal *> &Zoo::getAnimals() const {
    return m_animals;
}

#endif //ZOO_ZOO_H
