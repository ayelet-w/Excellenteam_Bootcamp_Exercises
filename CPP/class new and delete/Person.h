

#ifndef CLASS_NEW_AND_DELETE_PERSON_H
#define CLASS_NEW_AND_DELETE_PERSON_H
#define SIZE_OF_POOL 1000
#include <cstddef>

struct FreeList
{
    char * m_address;
    FreeList * m_next;
};

class Person {
public:
    Person(char fullname[32], unsigned int id,unsigned char age);
    Person(){};
    void* operator new(size_t size);
    void operator delete (void * ptr);
    char * get_fullname(){return m_fullname;};
    unsigned int get_id(){return m_id;};
    unsigned char get_age(){return m_age;};
    static FreeList* init();
private:
    char m_fullname[32];
    unsigned int m_id;
    unsigned char m_age;
    static char s_pool[SIZE_OF_POOL];
    static FreeList * s_firstfree;
};


#endif
