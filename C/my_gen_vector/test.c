
#include "test.h"
#include <stdio.h>

void testVectorPush(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    printf("*****************************\n");

    printf("Test push the element:c w r c\n");
    vectorPush(vector_char, (void *)'c');
    vectorPush(vector_char, (void *)'w');
    vectorPush(vector_char, (void *)'r');
    vectorPush(vector_char, (void *)'c');
    vectorPrint(vector_char,vectorPrint_char);
    printf("-----------------------------\n");

    printf("Test push the element:1 2 3 7 \n");
    vectorPush(vector_int, (void *)1);
    vectorPush(vector_int, (void *)2);
    vectorPush(vector_int, (void *)3);
    vectorPush(vector_int, (void *)7);
    vectorPrint(vector_int,vectorPrint_int);
    printf("-----------------------------\n");

    printf("Test push the element:'ayelet' 'efrat'  \n");
    vectorPush(vector_str, (void *)"ayelet");
    vectorPush(vector_str, (void *)"efrat");
    vectorPrint(vector_str,vectorPrint_str);
    printf("-----------------------------\n");

    printf("*****************************\n");
}
void testVectorPop(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    void * element;

    printf("*****************************\n");

    printf("Test pop:\n");
    vectorPop(vector_char, &element);
    printf("%c\n",(*(char *)&element));
    printf("-----------------------------\n");

    printf("Test pop:\n");
    vectorPop(vector_int, &element);
    printf("%d\n",(*(int *)&element));
    printf("-----------------------------\n");

    printf("Test pop:\n");
    vectorPop(vector_str, &element);
    printf("%s\n",(*(char **)&element));
    printf("-----------------------------\n");

    printf("*****************************\n");
}

void testVectorInsert(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    printf("*****************************\n");

    printf("Test insert vector char element u to index 3\n");
    vectorInsert(vector_char, (void *)'u', 3);
    vectorPrint(vector_char,vectorPrint_char);
    printf("-----------------------------\n");

    printf("Test insert vector char  element k to index 2\n");
    vectorInsert(vector_char, (void *)'k', 2);
    vectorPrint(vector_char,vectorPrint_char);
    printf("-----------------------------\n");

    printf("Test insert vector int element 8 to index 3\n");
    vectorInsert(vector_int, (void *)8, 3);
    vectorPrint(vector_int,vectorPrint_int);
    printf("-----------------------------\n");

    printf("Test insert the vector string element 'papi' to index 1\n");
    vectorInsert(vector_str, (void *)"papi", 1);
    vectorPrint(vector_str,vectorPrint_str);
    printf("-----------------------------\n");

    printf("*****************************\n");
}


void testVectorRemove(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    void * element;

    printf("*****************************\n");

    printf("Test remove the element from index 1\n");
    vectorRemove(vector_char, 1, &element);
    vectorPrint(vector_char,vectorPrint_char);
    printf("The element that removed: %c\n",(*(char *)&element));
    printf("-----------------------------\n");

    printf("Test remove the element from index 1\n");
    vectorRemove(vector_int, 1, &element);
    vectorPrint(vector_int,vectorPrint_int);
    printf("The element that removed: %d\n",(*(int *)&element));
    printf("-----------------------------\n");

    printf("Test remove the element from index 1\n");
    vectorRemove(vector_str, 1, &element);
    vectorPrint(vector_str,vectorPrint_str);
    printf("The element that removed: %s\n",(*(char**)&element));
    printf("-----------------------------\n");

    printf("*****************************\n");
}

void testVectorGetElement(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    void * element;

    printf("*****************************\n");

    printf("Test get element from index 2 \n");
    vectorGetElement(vector_char, 2, &element);
    vectorPrint(vector_char,vectorPrint_char);
    printf("The element: %c\n",(*(char *)&element));
    printf("-----------------------------\n");

    printf("Test get element from index 2 \n");
    vectorGetElement(vector_int, 2, &element);
    vectorPrint(vector_int,vectorPrint_int);
    printf("The element: %d\n",(*(int *)&element));
    printf("-----------------------------\n");

    printf("Test get element from index 0 \n");
    vectorGetElement(vector_str, 0, &element);
    vectorPrint(vector_str,vectorPrint_str);
    printf("The element: %s\n",(*(char**)&element));
    printf("-----------------------------\n");

    printf("*****************************\n");
}

void testVectorSetElement(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    void * element;

    printf("*****************************\n");

    element = (void *)'g';
    printf("Test set element 'g' to index 2 \n");
    vectorSetElement(vector_char, 2, element);
    vectorPrint(vector_char,vectorPrint_char);
    printf("-----------------------------\n");

    element = (void *)7;
    printf("Test set element 7 to index 2 \n");
    vectorSetElement(vector_int, 2, element);
    vectorPrint(vector_int,vectorPrint_int);
    printf("-----------------------------\n");

    element = (void *)"baruch";
    printf("Test set element 'baruch' to index 0 \n");
    vectorSetElement(vector_str, 0, element);
    vectorPrint(vector_str,vectorPrint_str);
    printf("-----------------------------\n");

    printf("*****************************\n");
}

void testVectorGetSize(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    printf("*****************************\n");

    printf("Test get size of the vector char:\n %d\n",(int)vectorGetSize(vector_char));
    printf("-----------------------------\n");

    printf("Test get size of the vector int:\n %d\n",(int)vectorGetSize(vector_int));
    printf("-----------------------------\n");

    printf("Test get size of the vector string:\n %d\n",(int)vectorGetSize(vector_str));
    printf("-----------------------------\n");

    printf("*****************************\n");
}

void testVectorGetCapacity(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    printf("*****************************\n");

    printf("Test get capacity of the vector char:\n %d\n",(int)vectorGetCapacity(vector_char));
    printf("-----------------------------\n");

    printf("Test get capacity of the vector int:\n %d\n",(int)vectorGetCapacity(vector_int));
    printf("-----------------------------\n");

    printf("Test get capacity of the vector string:\n %d\n",(int)vectorGetCapacity(vector_str));
    printf("-----------------------------\n");

    printf("*****************************\n");
}

void testVectorCount(Vector *vector_char,Vector *vector_int,Vector *vector_str)
{
    printf("*****************************\n");

    printf("Test how much c  are in the vector:\n %d\n", (int)vectorCount(vector_char, (void*)'c'));
    printf("-----------------------------\n");

    printf("Test how much 1  are in the vector:\n %d\n", (int)vectorCount(vector_int, (void*)1));
    printf("-----------------------------\n");

    printf("Test how much 'papi'  are in the vector:\n %d\n", (int)vectorCount(vector_str, (void*)"papi"));
    printf("-----------------------------\n");

    printf("*****************************\n");
}



void runAllTests()
{
    Vector *test_char = vectorCreate(5);
    Vector *test_int = vectorCreate(5);
    Vector *test_str = vectorCreate(3);
    testVectorPush(test_char,test_int,test_str);
    testVectorPop(test_char,test_int,test_str);
    testVectorInsert(test_char,test_int,test_str);
    testVectorRemove(test_char,test_int,test_str);
    testVectorGetElement(test_char,test_int,test_str);
    testVectorSetElement(test_char,test_int,test_str);
    testVectorGetSize(test_char,test_int,test_str);
    testVectorGetCapacity(test_char,test_int,test_str);
    testVectorCount(test_char,test_int,test_str);
    vectorDestroy(&test_char);
    vectorDestroy(&test_int);
    vectorDestroy(&test_str);

}