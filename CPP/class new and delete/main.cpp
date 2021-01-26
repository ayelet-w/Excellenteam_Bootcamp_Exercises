#include <iostream>
#include "Person.h"
int main() {
    Person *p1 = new Person("a",1,1);
    std::cout<<"sizeof person: "<<sizeof(Person)<<"\n";
    std::cout<<"address of p1: "<<p1<<"\n";
    Person *p2 = new Person("a",1,1);
    std::cout<<"address of p2: "<<p2<<"\n";
    Person *p3 = new Person("a",1,1);
    delete p2;
    std::cout<<"address of p3: "<<p3<<"\n";
    Person *p4 = new Person("a",1,1);
    std::cout<<"address of p4: "<<p4<<"\n";
    Person *p5 = new Person("a",1,1);
    std::cout<<"address of p5: "<<p5<<"\n";


//    Person *p4 = new Person("a",1,1);
//    std::cout<<"address of p4: "<<p4<<"\n";
//    delete p1;
//    delete p4;
    return 0;
}
