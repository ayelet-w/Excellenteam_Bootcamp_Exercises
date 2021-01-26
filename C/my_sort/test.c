
#include "test.h"

#include <stdio.h>

void testInt()
{
    int i;
    int arr[] = {1, 7, 6, 5 , 22, 8, 1, 15, 74};
    i=0;

    for(; i<sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, sizeof(arr), sizeof(int), compareInt);
    printf("After sort:\n");

    i=0;
    for(; i<sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void testChar()
{
    char arr[] = {'c','q','a','b'};
    int i;
    i=0;

    for(; i<sizeof(arr)/sizeof(char); i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");

    sort(arr, sizeof(arr), sizeof(char), compareChar);
    printf("After sort:\n");

    i=0;
    for(; i<sizeof(arr)/sizeof(char); i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}
void testStr()
{
    char *arr[] = {"ayelet", "yael", "baruch", "efrat" };
    int i;
    i=0;

    for(; i<sizeof(arr)/sizeof(char*); i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");

    i=0;
    sort(arr, sizeof(arr), sizeof(char*), compareStr);
    printf("After sort:\n");

    for(; i<sizeof(arr)/sizeof(char*); i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

void testAll()
{
    printf("Test int: \n");
    testInt();
    printf("Test char: \n");
    testChar();
    printf("Test string: \n");
    testStr();
    printf("Test Person: \n");

}