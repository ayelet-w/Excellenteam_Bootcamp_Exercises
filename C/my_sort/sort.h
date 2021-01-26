

#ifndef MY_SORT_SORT_H
#define MY_SORT_SORT_H

#include <stddef.h>

typedef struct Person Person;
/* generic */
typedef int(*Compare)(void * x, void * y);

void sort(void * arr, size_t data_size, size_t elem_size, Compare type_compare);

int compareInt(void * x, void * y);

int compareChar(void * x, void * y);

int compareStr(void * x, void * y);
/*Person*/
typedef int(*ComparePerson)(Person x, Person y);

void sortPerson(Person * persons,size_t size,ComparePerson type_compare);

int comparePersonInt(Person x, Person y);

int comparePersonStr(Person x, Person y);

int comparePersonUnChar(Person x, Person y);

#endif
