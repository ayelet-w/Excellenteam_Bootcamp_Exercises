
#include "gen_vector.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


struct Vector
{
    void ** m_values;
    size_t m_size;
    size_t m_current;
};


void resizeVector(Vector * vector)
{

    vector->m_size *= 2;
    vector->m_values = realloc(vector->m_values,vector->m_size * sizeof(*vector->m_values));

}

Vector * vectorCreate(size_t size)
{
    Vector * result;
    assert(size);

    result =(Vector *)malloc(sizeof(*result));

    if( !result )
    {
        return result;
    }

    result->m_values = malloc(size * sizeof(*result->m_values));

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


ErrorCode vectorPush(Vector *vector, void * value)
{

    if (!vector)
        return E_NULL_PTR;

    if (vector->m_current == vector->m_size)
    {

       resizeVector(vector);
        if(!vector->m_values)
            return E_ALLOCATION_ERROR;
    }

    /* Inserting data*/
    vector->m_values[vector->m_current++] = value;

    return E_OK;
}

ErrorCode vectorInsert(Vector *vector, void * value, size_t index)
{
    int i;
    int k;
    void ** copy_temp;
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

        copy_temp=malloc((vector->m_size)* sizeof(*(vector->m_values)));

        copy_temp[index]=value;

        i = 0;
        k = 0;
        while(i < vector->m_size)
        {
            if(i==index)
                k++;
            copy_temp[k] = vector->m_values[i];
            i++;
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
ErrorCode vectorPop(Vector *vector, void ** res)
{
    assert(res);

    if(!vector)
        return E_NULL_PTR;

    if(!vector->m_current)
        return E_UNDERFLOW;


    *res = vector->m_values[vector->m_current-1];
    vector->m_current--;
    vector->m_size--;

    return E_OK;
}

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, void ** res)
{
    void ** copy_temp;
    int i;
    int k;
    if(!vector)
        return E_NULL_PTR;

    if(index > vector->m_current)
        return E_BAD_INDEX;

    *res=vector->m_values[index];

    copy_temp = malloc(vector->m_size * sizeof(*(vector->m_values)));

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
    vector->m_current--;
    vector->m_size--;

    return E_OK;
}

ErrorCode vectorGetElement(const Vector *vector, size_t index, void ** res)
{
    if(!vector)
        return E_NULL_PTR;

    if(index > vector->m_current)
        return E_BAD_INDEX;

    *res = vector->m_values[index];

    return E_OK;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, void * value)
{
    if(!vector)
        return E_NULL_PTR;

    if(index > vector->m_current)
        return E_BAD_INDEX;

    vector->m_values[index] = value;

    return E_OK;
}

size_t vectorGetSize(const Vector *vector)
{
    return vector->m_size;
}

size_t vectorGetCapacity(const Vector *vector)
{
    return vector-> m_current;
}

/* Counts how many instances of a given value there are. */

size_t vectorCount(const Vector *vector, void * value)
{
    size_t res;
    int i ;
    res = 0;

    for(i=0; i<= vector->m_current; i++)
    {
        if(vector->m_values[i] == value)
            res++;
    }
    return res;
}

void vectorPrint_char(Vector * v )
{
    int i;
    for(i=0; i < v->m_current; i++)
        printf("%c ",(*(char *)(v->m_values+i)));
    printf("\n");
}
void vectorPrint_int(Vector * v )
{
    int i;
    for(i=0; i < v->m_current; i++)
        printf("%d ",(*(int *)(v->m_values+i)));
    printf("\n");
}
void vectorPrint_str(Vector * v )
{
    int i;
    for(i=0; i < v->m_current; i++)
        printf("%s ",(*(char **)(v->m_values+i)));
    printf("\n");
}



void vectorPrint(Vector * v ,PrintType print)
{
    print(v);
}