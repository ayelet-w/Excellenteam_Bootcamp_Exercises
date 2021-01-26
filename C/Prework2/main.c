#include <stdio.h>
#include "Books.h"
#include "local_library.h"
#include <stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
//functions for case:
struct BookCopy *find_book(struct BookCopy book_copies [], int serial_number)
{
    int i;
    for ( i = 0; i < 10; i++) {
        if(book_copies[i].serial_number==serial_number)
            return &book_copies[i];
    }
    return NULL;
}
void borrow_book(struct BookCopy book_copies [])
{
    printf("Enter a serial number: \n");
    int serial_number;
    scanf("%d",&serial_number);
    struct BookCopy *borrow = find_book(book_copies,serial_number);
    if(borrow == NULL)
        printf("Invalid serial number\n");
    else {
        if(borrow_copy(borrow, true)==1)
            printf("The book is already borrowed ");
    }
}
void return_book(struct BookCopy book_copies [])
{
    printf("Enter a serial number: \n");
    int serial_number;
    scanf("%d",&serial_number);
    struct BookCopy *book_return = find_book(book_copies,serial_number);
    if(book_return == NULL)
        printf("Invalid serial number\n");
    else {
        if(borrow_copy(book_return, false)==0)
            printf("The book is not borrowed while trying to return it to the library ");
    }
}
//phase 1:

/*int main()
{
    struct BookCopy book_copies[10];
    //Print the full list of the books in the library
    struct Book *books_ptr=books;
    printf("Print the books in the library:\n");
    while(books_ptr->internal_book_number!=-1)
    {
        print_book(books_ptr);
        books_ptr+=1;
        printf("\n");
    }
    int j;
    for ( j = 0; j < 10; j++)
    {
        printf("Please enter internal book number: ");
        int internal_book_number;
        scanf("%d", &internal_book_number);
        printf("\n");
        while(name_book(internal_book_number)==NULL)
        {
            printf("The internal book number not found, Please try again: ");
            scanf("%d", &internal_book_number);
            printf("\n");
        }
        struct BookCopy bookCopy_to_add;
        init_copy(&bookCopy_to_add,internal_book_number);
        book_copies[j] = bookCopy_to_add;
        print_copy(& bookCopy_to_add);
    }
    int step;
    printf("10 books-copy added successfully.\n ");
    do {
        printf("enter: 1. Borrow a book-copy \n 2. Return a book-copy \n 9. Exit  \n");
        scanf("%d", &step);
        printf("\n");
        switch (step) {
            case 1:
                borrow_book(book_copies);
                break;
            case 2:
                return_book(book_copies);
                break;
            case 9:
                printf("Good Bye");
                break;
            default:
                printf("Invalid number");
        }
    }
    while(step!=9);
    return 0;
}
*/
// phase 2:
/*
int main()
{

    printf("Enter a number of books: \n");
    int number;
    struct BookCopy * ptr_book_copy;
    scanf("%d",&number);
    ptr_book_copy=(struct BookCopy*) malloc(number*sizeof(struct BookCopy));
    if(ptr_book_copy == NULL)
    {
        printf("Error memory not allocated");
        free(ptr_book_copy);
        exit(0);
    }
    //Print the full list of the books in the library
    struct Book *books_ptr=books;
    printf("Print the books in the library:\n");
    while(books_ptr->internal_book_number!=-1)
    {
        print_book(books_ptr);
        books_ptr+=1;
        printf("\n");
    }
    int j;
    for ( j = 0; j < number; j++)
    {
        printf("Please enter internal book number: ");
        int internal_book_number;
        scanf("%d", &internal_book_number);
        printf("\n");
        while(name_book(internal_book_number)==NULL)
        {
            printf("The internal book number not found, Please try again: ");
            scanf("%d", &internal_book_number);
            printf("\n");
        }
        struct BookCopy *bookCopy_to_add;
        init_copy(bookCopy_to_add,internal_book_number);
        ptr_book_copy=bookCopy_to_add;
        print_copy(bookCopy_to_add);
        ptr_book_copy+=sizeof(struct BookCopy);
    }
    int step;
    printf("%d books-copy added successfully.\n ",number);
    do {
        printf("enter: 1. Borrow a book-copy \n 2. Return a book-copy \n 9. Exit  \n");
        scanf("%d", &step);
        printf("\n");
        switch (step) {
            case 1:
                borrow_book(ptr_book_copy);
                break;
            case 2:
                return_book(ptr_book_copy);
                break;
            case 9:
                printf("Good Bye");
                //free(ptr_book_copy);
                break;
            default:
                printf("Invalid number");
        }
    }
    while(step!=9);
    return 0;
}*/
//phase 3:
static int get_min_promotion(struct Book * books)
{
    int min_promotion=100;
    struct Book * books_ptr=books;
    while(books_ptr->promotion!=0)
    {
        min_promotion=MIN(min_promotion,books_ptr->promotion);
        books_ptr+=1;;
    }
    return min_promotion;
}
static int get_min_thrilling_factor(struct Book * books)
{
    int min_thrilling_factor=10000;
    struct Book * books_ptr=books;
    while(books_ptr->promotion!=0)
    {
        if(books_ptr->book_genre==1)
        {
            min_thrilling_factor=MIN(min_thrilling_factor,books->genreData.thriller.thrilling_factor);
        }
        books_ptr+=1;
    }
    return min_thrilling_factor;
}
int main()
{

    printf("Enter a number of books: \n");
    int number;
    struct BookCopy * ptr_book_copy;
    scanf("%d",&number);
    ptr_book_copy=(struct BookCopy*) malloc(number*sizeof(struct BookCopy));
    if(ptr_book_copy == NULL)
    {
        printf("Error memory not allocated");
        free(ptr_book_copy);
        exit(0);
    }
    //Print the full list of the books in the library
    struct Book *books_ptr=books;
    printf("Print the books in the library:\n");
    while(books_ptr->internal_book_number!=-1)
    {
        print_book(books_ptr);
        books_ptr+=1;
        printf("\n");
    }
    do_for_books(books,number_of_books(),print_nicely);
    do_for_books(books,number_of_books(),print_non_fiction);
    do_for_books(books,number_of_books(),print_most_promoted);
    printf("The minimum promotion is: %d\n",get_min_promotion(books));
    if (get_min_thrilling_factor(books)!=10000)
     printf("The minimum thrilling factor is: %d\n",get_min_thrilling_factor(books));
    else
        printf("There is no thrilling factor\n");
    int j;
    for ( j = 0; j < number; j++)
    {
        printf("Please enter internal book number: ");
        int internal_book_number;
        scanf("%d", &internal_book_number);
        printf("\n");
        while(name_book(internal_book_number)==NULL)
        {
            printf("The internal book number not found, Please try again: ");
            scanf("%d", &internal_book_number);
            printf("\n");
        }
        struct BookCopy *bookCopy_to_add;
        init_copy(bookCopy_to_add,internal_book_number);
        ptr_book_copy=bookCopy_to_add;
        print_copy(bookCopy_to_add);
        ptr_book_copy+=sizeof(struct BookCopy);
    }
    int step;
    printf("%d books-copy added successfully.\n ",number);
    do {
        printf("enter: 1. Borrow a book-copy \n 2. Return a book-copy \n 9. Exit  \n");
        scanf("%d", &step);
        printf("\n");
        switch (step) {
            case 1:
                borrow_book(ptr_book_copy);
                break;
            case 2:
                return_book(ptr_book_copy);
                break;
            case 9:
                printf("Good Bye");
                //free ??
                break;
            default:
                printf("Invalid number");
        }
    }
    while(step!=9);
    return 0;
}