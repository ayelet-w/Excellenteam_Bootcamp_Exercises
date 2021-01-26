
#include "Person.h"


char Person::s_pool[]={};
FreeList* Person::s_firstfree = init();
FreeList* Person::init()
{
    FreeList* res = new FreeList();
    res->m_address = s_pool;
    res->m_next = NULL;
    return res;
}
Person::Person(char fullname[32], unsigned int id,unsigned char age)
{
   for(int i = 0; fullname[i] != '\0' ; i++)
   {
       m_fullname[i] = fullname[i];
   }
   m_id = id;
   m_age = age;
}

void* Person::operator new(size_t size)
{
//, char *name, unsigned int id, unsigned char age

//    s_firstfree->m_address = (char*)::new Person();
    char * res = s_firstfree->m_address;
    s_firstfree->m_address = s_firstfree->m_address + sizeof(Person);
    s_firstfree->m_next = NULL;
    return res;
}

void Person::operator delete(void *ptr)
{
    if(ptr == NULL)
        return;
    if(s_firstfree->m_address > ptr)
    {
        FreeList temp_freelist;
        temp_freelist.m_address = s_firstfree->m_address;
        temp_freelist.m_next = s_firstfree->m_next;
        s_firstfree->m_address = (char*)ptr;
        s_firstfree->m_next = new FreeList();
        s_firstfree->m_next->m_address = temp_freelist.m_address;
        s_firstfree->m_next->m_next = temp_freelist.m_next;

    }
    else if(s_firstfree->m_address < ptr)
    {
        s_firstfree->m_next->m_address = (char*)ptr;
    }


}

//FreeList *Person::init() {
//    s_firstfree = new FreeList();
//    s_firstfree->m_address = s_pool;
//    FreeList* temp_init = s_firstfree->m_next;
//
//    size_t number_of_person = SIZE_OF_POOL / sizeof(Person);
//    for(size_t i = 0; i < number_of_person; ++i)
//    {
//        temp_init->m_address = temp_init->m_address + sizeof(Person);
//        temp_init = temp_init->m_next;
//    }
//    temp_init->m_next = NULL;
//    return s_firstfree;
//}
