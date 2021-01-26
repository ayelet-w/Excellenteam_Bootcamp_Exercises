//
// Created by ayelet on 9/13/20.
//

#ifndef UNTITLED_BOOKS_H
#define UNTITLED_BOOKS_H
#include <stdbool.h>
enum zones { KIDS, HIGHSCHOOL, ADULT, DOCUMENTARY, COMICS};
enum genre {DRAMA,THRILLER,COMEDY,NON_FICTION};
struct Drama{
    int text_quality;
    int plot_quality;
};
struct Thriller{
    float thrilling_factor;
};
struct Comedy{
    int quality_of_humor;
    char humor_type;
};
struct Non_fiction{
    char field_of_book [4];
};
union genre_data{
    struct Drama drama;
    struct Thriller thriller;
    struct Comedy comedy;
    struct Non_fiction nonFiction;

};

struct Book
{
    int internal_book_number;//between 0-50000
    char name[50];
    int promotion;//between -100-100
    enum zones zone;
    enum genre book_genre;
    union genre_data genreData;
};

struct BookCopy
{
    int internal_book_number;
    int serial_number;//between 10000-1000000000
    bool is_borrowed;
    int borrowing_times;
    int conditions;
};
static const char * get_zone_name(enum zones zone);
void print_book(struct Book * book);
void print_copy(struct BookCopy * bookCopy);
int borrow_copy(struct BookCopy * bookCopy,bool is_borrowing);
void init_copy(struct BookCopy *bookCopy,int internal_book_number);
bool is_librarian_required(struct BookCopy * book_copy);
bool is_bookbinder_required(struct BookCopy * book_copy);
bool is_repairable(struct BookCopy * book_copy);
bool is_ok(struct BookCopy * book_copy);
bool is_useless(struct BookCopy * book_copy);
bool are_in_same_condition(struct BookCopy * book_copy_1,struct BookCopy * book_copy_2);
struct BookCopy * create_copy(int internal_book_number);
void get_nice_book_name(const char * src, char * dst);
void print_nicely(const struct Book* pbook);
void print_non_fiction(const struct Book* pbook);
void print_most_promoted(const struct Book* pbook);
void do_for_books(struct Book * books,int number,void (*action)(const struct Book *) );

#endif //UNTITLED_BOOKS_H
