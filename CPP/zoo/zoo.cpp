
#include <iostream>
#include "zoo.h"

Zoo::Zoo() {}

void Zoo::addAnimal(Animal * animal)
{
    m_animals.push_back(animal);

}

void Zoo::printAllAnimals()
{
    for(size_t i = 0; i < m_animals.size(); i++ )
    {
       std::cout<<*m_animals[i]<<"\n";
    }

}

