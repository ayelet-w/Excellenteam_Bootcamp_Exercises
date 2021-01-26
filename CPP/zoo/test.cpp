
#include "test.h"
#include "Lion.h"
#include "Monkey.h"
#include "Owl.h"
#include "Goose.h"
#include "Shark.h"
#include "Whale.h"
#include "Dog.h"
#include "ClownFish.h"
#include <iostream>

TEST(testZoo, addAnimal)
{
    Zoo zoo;

    Lion lion1("Simba","Africani");

    zoo.addAnimal(&lion1);

    ASSERT_EQ(zoo.getAnimals().size(),1);
}
TEST(testZoo,wholeZoo)
{
    Zoo zoo;
    std::cout<<"Test the zoo: \n";

    Lion lion1("Simba","africai");

    Lion lion2("Mufasa","africai");

    Monkey monkey("Rafiki","gooo");

    Goose goose1("Akka","mrokay");

    Goose goose2("Morten","zarfati");

    Owl snowy_owl("Hedwig","sonwny");

    Dog dog("dog","sibiri");

    Shark shark("Jaws","sea");

    ClownFish clownfish("Nemo","okyanus");

    Whale whale("willy","an");

    zoo.addAnimal(&lion1);

    zoo.addAnimal(&lion2);

    zoo.addAnimal(&monkey);

    zoo.addAnimal(&goose1);

    zoo.addAnimal(&goose2);

    zoo.addAnimal(&snowy_owl);

    zoo.addAnimal(&dog);

    zoo.addAnimal(&shark);

    zoo.addAnimal(&clownfish);

    zoo.addAnimal(&whale);

    zoo.printAllAnimals();

    std::cout<<"--------------------------\n \n";

    ASSERT_EQ(zoo.getAnimals().size(),10);
}
TEST(testLion, getName)
{
    Lion lion("Simba", "Africani");


    ASSERT_EQ(lion.getName(), "Simba");
}
TEST(testLion, getSpecies)
{
    Lion lion("Simba", "Africani");

    ASSERT_EQ(lion.getSpecies(), "Africani");
}
TEST(testLion, getSpeed)
{
    Lion lion("Simba", "Africani");

    ASSERT_EQ(lion.getSpeed(), 70);
}
TEST(testLion, getNumberOfNewborn)
{
    Lion lion("Simba", "Africani");

    ASSERT_EQ(lion.getNumberOfNewborn(), 4);
}
TEST(testLion, getPregnancyDuration)
{
    Lion lion("Simba", "Africani");

    ASSERT_EQ(lion.getPregnancyDuration(), 110);
}
TEST(testLion, getLifeExpectancy)
{
    Lion lion("Simba", "Africani");

    ASSERT_EQ(lion.getLifeExpectancy(), 30);
}
TEST(testLion, getContinents)
{
    Lion lion("Simba", "Africani");

    ASSERT_EQ(lion.getContinents().size(), 3);
}
TEST(testLion, getTypeOfFoods)
{
    Lion lion("Simba", "Africani");

    ASSERT_EQ(lion.getTypeOfFoods().size(),1);

}



