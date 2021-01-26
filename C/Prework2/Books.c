//
// Created by ayelet on 9/13/20.
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include "Books.h"
static const char * get_zone_name(enum zones zone)
{
    static const char * strings_of_zones[] = { "kids", "high school", "adult", "documentary", "comics"};
    //default??
    return strings_of_zones[zone];
}
static void print_details_drama(struct Book * book) {
    printf("Genre: drama \n plot quality: %d\n text quality: %d",book->genreData.drama.plot_quality,book->genreData.drama.text_quality);
}
static void print_details_thriller(struct Book * book) {
    printf("Genre: thriller\n Thrilling factor: %d",book->genreData.thriller.thrilling_factor);
}
static void print_details_comedy(struct Book * book) {
    printf("Genre: comedy\n Humor type: %c\n Quality of humor: %c",book->genreData.comedy.humor_type,book->genreData.comedy.quality_of_humor);
}
static void print_details_non_fiction(struct Book * book) {
    printf("Genre: non fiction\n Field of book: %s",book->genreData.nonFiction.field_of_book);
}
void print_book(struct Book * book)
{
    printf("Book details:\n");
    printf("Name: %s \n" ,book->name);
    printf("Internal book number: %d \n",book->internal_book_number);
    printf("Promotion: %d \n",book->promotion);
    printf("Zone: %s\n",get_zone_name(book->zone));
    switch (book->book_genre) {
        case 0:
            print_details_drama(book);
            break;
        case 1:
            print_details_thriller(book);
        case 2:
            print_details_comedy(book);
        case 3:
            print_details_non_fiction(book);
    }
}
void print_copy(struct BookCopy * bookCopy)
{
    printf("Internal book number: %d \n",bookCopy->internal_book_number);
    printf("Serial number: %d\n",bookCopy->serial_number);
    if(bookCopy->is_borrowed)
        printf("Is borrowed \n");
    else
        printf("Is not borrowed \n");
    printf("Borrowing times: %d\n",bookCopy->borrowing_times);
    printf("condition: %d\n",bookCopy->conditions);
}
int borrow_copy(struct BookCopy * bookCopy,bool is_borrowing)
{
    //is not borrowed while trying to return it to the library
    if(!bookCopy->is_borrowed && !is_borrowing)
        return 0;
    //If the book is already borrowed while trying to borrow it
    else if(bookCopy->is_borrowed && is_borrowing)
        return 1;
    else {
        bookCopy->is_borrowed = is_borrowing;
        return -1;
    }
}
void init_copy(struct BookCopy *bookCopy,int internal_book_number)
{
    static int serial_number = 10000;
    bookCopy->internal_book_number=internal_book_number;
    bookCopy->is_borrowed = false;
    bookCopy->serial_number = serial_number;
    serial_number+=1;
}
bool is_librarian_required(struct BookCopy * book_copy)
{
    int mask = 0b0000000000001011;
    return !(mask&book_copy->conditions);
}
bool is_bookbinder_required(struct BookCopy * book_copy)
{
    int mask = 0b0000000000110100;
    return !(mask&book_copy->conditions);
}
bool is_repairable(struct BookCopy * book_copy)
{
    int mask_stained  = 0b0000000000100000;
    int mask_missing = 0b0000000000000100;
    return !(mask_stained&book_copy->conditions)||!(mask_missing&book_copy->conditions);
}
bool is_ok(struct BookCopy * book_copy)
{
    int mask=0b1111111111111111;
    return !(mask&book_copy->conditions);
}
bool is_useless(struct BookCopy * book_copy)
{
    int mask_cover=0b0000000000000001;
    int mask_indexing=0b0000000000000010;
    int mask_missing=0b0000000000000100;
    int mask_bar_code=0b0000000000001000;
    int mask_spine_broken=0b0000000000010000;
    int mask_stained=0b0000000000100000;
    int counter=0;
    if(mask_cover & book_copy->conditions)
        counter+=1;
    if(mask_indexing & book_copy->conditions)
        counter+=1;
    if(mask_missing & book_copy->conditions)
        counter+=1;
    if(mask_bar_code & book_copy->conditions)
        counter+=1;
    if(mask_spine_broken & book_copy->conditions)
        counter+=1;
    if(mask_stained & book_copy->conditions)
        counter+=1;
    return (counter>=4);
}
bool are_in_same_condition(struct BookCopy * book_copy_1,struct BookCopy * book_copy_2)
{
   return !(!book_copy_1->conditions & book_copy_2->conditions);
}
struct BookCopy * create_copy(int internal_book_number)
{
    struct BookCopy * bookCopy_ptr;
    init_copy(bookCopy_ptr,internal_book_number);
    bookCopy_ptr->conditions=0;
    bookCopy_ptr->borrowing_times=0;
    return bookCopy_ptr;
}
void get_nice_book_name(const char * src, char * dst)
{
    int i;
    dst[0]=toupper(src[0]);
    for(i=1;src[i]!='\0';i++)//??
    {
        if(src[i-1]==' ')
        {
            dst[i]=toupper(src[i]);
        }
        else
            dst[i]=tolower(src[i]);
    }
}
void print_nicely(const struct Book* pbook)
{
    char nice_book_name[strlen(pbook->name)];
    get_nice_book_name(pbook->name,nice_book_name);
    printf("The book name: %s\n",nice_book_name);
}
void print_non_fiction(const struct Book* pbook)
{
    if(pbook->book_genre==3)
    {
        printf("Book name: %s\n",pbook->name);
        printf("code: %s\n",pbook->genreData.nonFiction.field_of_book);
    }
    else
        printf("---\n");
}
void print_most_promoted(const struct Book* pbook)
{
    if(pbook->promotion>50)
    {
        printf("Promotion: %d\n",pbook->promotion);
    }
    return;
}
void do_for_books(struct Book * books,int number,void (*action)(const struct Book *) )
{
    int i;
    for(i=0;i<number;i++)
    {
        action(&books[i]);
    }
}
