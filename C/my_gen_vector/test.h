
#ifndef MY_GEN_VECTOR_TEST_H
#define MY_GEN_VECTOR_TEST_H
#include "gen_vector.h"

void testVectorPush(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void testVectorInsert(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void testVectorPop(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void testVectorRemove(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void testVectorGetElement(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void testVectorSetElement(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void testVectorGetSize(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void testVectorGetCapacity(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void testVectorCount(Vector *vector_char,Vector *vector_int,Vector *vector_str);

void runAllTests();


#endif
