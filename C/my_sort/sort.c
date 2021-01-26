

#include "sort.h"
#include "my_strcmp.h"
#include <string.h>
struct Person
{
    unsigned int m_id;
    char m_name[16];
    unsigned char m_age;
};


/* person sort */
void sortPerson(Person * persons,size_t size,ComparePerson type_compare)
{
    int i,j;
    i = 0;
    for(; i < size; i++)
    {
        j = 0;

        for(; j < size-1; j++)
        {
            if(type_compare(persons[j], persons[j+1]) > 0)
            {
                char temp[sizeof(Person)];
                memcpy(temp,persons + sizeof(Person) * j , sizeof(Person));
                memcpy(persons + sizeof(Person) * j,persons + sizeof(Person) * (j + 1), sizeof(Person));
                memcpy(persons + sizeof(Person) * (j + 1),temp, sizeof(Person));
            }
        }

    }
}

int comparePersonInt(Person x, Person y)
{
    return x.m_id > y.m_id ? 1 : -1;
}

int comparePersonStr(Person x, Person y)
{
    return my_strcmp(x.m_name,y.m_name);
}

int comparePersonUnChar(Person x, Person y)
{
    return x.m_age > y.m_age ? 1 : -1;
}



/* generic sort */
void sort(void * arr, size_t data_size, size_t element_size, Compare type_compare){
    size_t length;
    int i,j;
    length = data_size/element_size;
     i = 0;
    for(; i < length; i++)
    {
        j = 0;

        for(; j < length-1; j++)
        {
            if(type_compare(arr + element_size * j, arr + element_size * (j+1)) > 0)
            {
                char temp[element_size];
                memcpy(temp,arr + element_size * j , element_size);
                memcpy(arr + element_size * j,arr + element_size * (j + 1), element_size);
                memcpy(arr + element_size * (j + 1),temp, element_size);
            }
        }

    }
}

int compareInt(void * x, void * y){
    int * value1 = (int*)x;
    int * value2 = (int*)y;
    return *value1 > *value2 ? 1 : -1;
}

int compareChar(void * x, void * y)
{
    char * p1 = (char*)x;
    char * p2 = (char*)y;
    return *p1 > *p2 ? 1 : -1;
}
int compareStr(void * x, void * y)
{
    char *c = *(char **)x;
    char *d = *(char **)y;
    return my_strcmp(c, d);
}
