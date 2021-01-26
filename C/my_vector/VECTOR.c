

#include "VECTOR.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


 struct Vector
{
    int * m_values;
    size_t m_size;
    size_t m_current;
};

void resizeVector(Vector * vector)
{
    int* temp = malloc(vector->m_size * 2 * sizeof(int));


    /* copying old array elements to new array*/
    int i=0;
    for (; i < vector->m_size; i++) {
        temp[i] = vector->m_values[i];
    }

    /* deleting previous array*/
    free(vector->m_values);
    vector->m_size *= 2;
    vector->m_values = temp;
}

Vector* vectorCreate(size_t size)
{
    Vector * result;
    assert(size);

    result =(Vector*)malloc(sizeof(*result));

    if( !result )
    {
        return result;
    }

    result->m_values=malloc(size * sizeof(int));

    if(result->m_values)
    {
        result->m_size=size;
        result->m_current=0;
    }

    else
    {
        result = NULL;
        return result;
    }


    return result;
}

void vectorDestroy(Vector **vector)
{
    assert(vector);

    free((*vector)->m_values);
    free(*vector);

    *vector = NULL;
}

ErrorCode vectorPush(Vector *vector, int value)
{

    if (!vector)
        return E_NULL_PTR;

    if (vector->m_current == vector->m_size)
    {
        resizeVector(vector);/* realloc */
        if(!vector->m_values)
            return E_ALLOCATION_ERROR;
    }

    /* Inserting data*/
    vector->m_values[vector->m_current] = value;
    vector->m_current++;

    return E_OK;
}

ErrorCode vectorInsert(Vector *vector, int value, size_t index)
{
    int i;
    int k;
    int * copy_temp;
    if (index >= vector->m_size)
    {
         return E_BAD_INDEX;
    }
    else
    {
        if(vector->m_current==vector->m_size)
        {
            resizeVector(vector);
            if(!vector->m_values)
                return E_ALLOCATION_ERROR;
        }

        copy_temp=malloc(vector->m_size * sizeof(int));

        copy_temp[index]=value;

        i = 0;
        k = 0;
        while(i < vector->m_size)
        {
            copy_temp[k] = vector->m_values[i];
            i++;
            k++;
            if(i==index)
                k++;
        }
        /* deleting previous array */
        free(vector->m_values);
        vector->m_values = copy_temp;
        vector->m_current++;
    }

    return E_OK;
}

/* Clears the item at the end. */
ErrorCode vectorPop(Vector *vector, int *res)
{
    assert(res);

    if(!vector)
        return E_NULL_PTR;

    if(!vector->m_current)
        return E_UNDERFLOW;


    *res=vector->m_values[vector->m_current-1];
    vector->m_current--;
    vector->m_size--;

    return E_OK;
}

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, int *res)
{
    int *copy_temp;
    int i;
    int k;
    if(!vector)
        return E_NULL_PTR;

    if(index > vector->m_current)
        return E_BAD_INDEX;

    *res=vector->m_values[index];

    copy_temp = malloc(vector->m_size * sizeof(int));

    i=0;
    k=0;
    while(k < vector->m_current)
    {
        if(i==index)
            i++;
        copy_temp[k] = vector->m_values[i];
        i++;
        k++;

    }
    /* deleting previous array */
    free(vector->m_values);
    vector->m_values = copy_temp;

    return E_OK;
}

ErrorCode vectorGetElement(const Vector *vector, size_t index, int*res)
{
    if(!vector)
        return E_NULL_PTR;

    if(index > vector->m_current)
        return E_BAD_INDEX;

    *res=vector->m_values[index];

    return E_OK;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, int value)
{
    if(!vector)
        return E_NULL_PTR;

    if(index > vector->m_current)
        return E_BAD_INDEX;

    vector->m_values[index]=value;

    return E_OK;
}

size_t vectorGetSize(const Vector *vector)
{
    return vector->m_size+1;
}

size_t vectorGetCapacity(const Vector *vector)
{
    return vector->m_current;
}

/* Counts how many instances of a given value there are. */
size_t vectorCount(const Vector *vector, int value)
{
    size_t res=0;
    int i=0;
    for(; i<= vector->m_current; i++)
    {
        if(vector->m_values[i]==value)
            res++;
    }
    return res;
}

void vectorPrint(Vector * v )
{
    int i=0;
    for(; i < v->m_current; i++)
        printf("%d ",v->m_values[i]);
    printf("\n");
}