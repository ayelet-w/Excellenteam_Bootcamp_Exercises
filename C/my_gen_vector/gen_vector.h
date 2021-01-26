
#ifndef MY_GEN_VECTOR_GEN_VECTOR_H
#define MY_GEN_VECTOR_GEN_VECTOR_H

#include <stddef.h>
typedef enum
{
    E_OK,
    E_NULL_PTR,
    E_UNDERFLOW,
    E_ALLOCATION_ERROR,
    E_BAD_INDEX
} ErrorCode;

typedef struct Vector   Vector;

/*typedef int(* IsEqual)(const void *, const void *);*/

Vector* vectorCreate(size_t size);

void vectorDestroy(Vector **vector);

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode vectorPush(Vector *vector, void * value);

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode vectorInsert(Vector *vector, void * value, size_t index);

/* Clears the item at the end. */
ErrorCode vectorPop(Vector *vector, void ** res);

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, void **res);

ErrorCode vectorGetElement(const Vector *vector, size_t index, void ** res);

ErrorCode vectorSetElement(Vector *vector, size_t index, void * value);

size_t vectorGetSize(const Vector *vector);

size_t vectorGetCapacity(const Vector *vector);

/* Counts how many instances of a given value there are. */
size_t vectorCount(const Vector *vector, void * value);

typedef void (*PrintType)(Vector * v);

void vectorPrint(Vector * v,PrintType p );

void vectorPrint_str(Vector * v );

void vectorPrint_int(Vector * v );

void vectorPrint_char(Vector * v );

#ifdef _DEBUG
#endif
#endif
