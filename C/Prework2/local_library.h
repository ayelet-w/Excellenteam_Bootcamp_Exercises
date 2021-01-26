//
// Created by ayelet on 9/15/20.
//

#ifndef UNTITLED_LOCAL_LIBRARY_H
#define UNTITLED_LOCAL_LIBRARY_H
#include "Books.h"
extern struct Book books[];
const  struct Book* first_book_ptr();
int number_of_books();
char * name_book(int internal_book_number);
#endif //UNTITLED_LOCAL_LIBRARY_H
