
#ifndef UTH_CPP2C_ENCAPSULATION_DEFS_H
#define UTH_CPP2C_ENCAPSULATION_DEFS_H
#define NUM_BOXES 3

#include <stdbool.h>

typedef struct Box
{
    double length;
    double width;
    double height;
}Box;

void InitBox_1CBOXP(Box * const box);

void InitBox_2CBOXPDL(Box * const box,double dim);

void InitBox_4CBOXPDLDLDL(Box * const box, double l, double w, double h);

void BoxDtor_1CBOXP(Box *box);

Box* BOX_operatorMultEq_2KCBOXPDL(Box * const box, double mult);

void BOX_print_1KCBOXP(const Box * const box);

double BOX_getWidth_1KCBOXP(const Box * const box);

double BOX_getLength_1KCBOXP(const Box * const box);

double BOX_getHeight_1KCBOXP(const Box * const box);

double BOX_getVolume_1KCBOXP(const Box * const box);

bool BOX_operator_eq_2KCBOXPKCBOXP(const Box * const box1,const Box * const box2);







/*SHELF*/
static const char* const DEF_MSG = "The total volume held on the shelf is";

extern const char* message;


typedef struct Shelf
{
    Box boxes[NUM_BOXES];

}Shelf;

void InitShelf_1KCSHELFP(Shelf * const shelf);

void ShelfDtor_1SHELFP(Shelf * shelf);

void SHELF_setBox_3KCSHELFPIKCBOXP(Shelf * shelf, int index, Box * const dims);

double SHELF_getVolume_1KCSHELFP(const Shelf * const shelf);

void SHELF_print_1KCSHELFP(const Shelf * const shelf);

void SHELF_setMessage_1KCHP(const char* msg);

#endif
