

#include "Animal.h"
#include <iostream>


Animal::Animal(const std::string &name,const std::string &species):m_name(name),m_species(species){}


std::ostream &operator<<(std::ostream &os, const Animal &animal) {
    os << "Name: " << animal.getName() <<"\n";
    os <<"Species: "<<animal.getSpecies()<<"\n";
    os <<"Life expectancy: "<<(int)animal.getLifeExpectancy()<<"\n";
    os <<"Continents: ";
    for(size_t i = 0; i < animal.getContinents().size(); i++)
    {
        os <<animal.getContinents()[i]<<" ";
    }
    os<<"\n";
    os<<"Type of food: ";
    for(size_t i = 0; i < animal.getTypeOfFoods().size(); i++)
    {
        os <<animal.getTypeOfFoods()[i]<<" ";
    }
    os<<"\n";

    os<<"Speed: "<<animal.getSpeed()<<"\n";

    animal.print();

    return os;
}







