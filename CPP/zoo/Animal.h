
#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H
#include <string>
#include <vector>
#include <map>

//enum SPECIES {Male,Female};

/*inline std::ostream& operator<<(std::ostream& out, const SPECIES value){
    static std::map<SPECIES, std::string> strings;
    if (strings.empty()){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(Male);
        INSERT_ELEMENT(Female);
#undef INSERT_ELEMENT
    }

    return out << strings[value];
}*/

enum TYPE_OF_FOOD{Meat,Fish ,Vegetarian,Reptiles};

inline std::ostream& operator<<(std::ostream& out, const TYPE_OF_FOOD value){
    static std::map<TYPE_OF_FOOD, std::string> strings;
    if (strings.empty()){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(Meat);
        INSERT_ELEMENT(Fish);
        INSERT_ELEMENT(Vegetarian);
        INSERT_ELEMENT(Reptiles);
#undef INSERT_ELEMENT
    }

    return out << strings[value];
}

enum CONTINENT{USA,Europe,Africa,Asian,Australia};


inline std::ostream& operator<<(std::ostream& out, const CONTINENT value){
    static std::map<CONTINENT, std::string> strings;
    if (strings.empty()){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(USA);
        INSERT_ELEMENT(Europe);
        INSERT_ELEMENT(Africa);
        INSERT_ELEMENT(Asian);
        INSERT_ELEMENT(Australia);
#undef INSERT_ELEMENT
    }

    return out << strings[value];
}

class Animal {
public:
    Animal(const std::string &name, const std::string &species);

    virtual ~Animal(){};

    const std::string &getName() const;

    const std::string &getSpecies() const;

    virtual unsigned char getLifeExpectancy() const = 0;

    virtual const std::vector<CONTINENT> &getContinents() const = 0;

    virtual const std::vector<TYPE_OF_FOOD> &getTypeOfFoods() const = 0;

    virtual size_t getSpeed() const = 0;

    friend  std::ostream &operator<<(std::ostream &os, const Animal& animal);

    virtual void print() const = 0;

private:

    std::string m_name;

    std::string m_species;
};

inline const std::string &Animal::getName() const {
    return m_name;
}

inline const std::string &Animal::getSpecies() const {
    return m_species;
}
#endif
