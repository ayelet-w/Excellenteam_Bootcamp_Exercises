#include  <stdio.h>

#include "cpp2c_encapsulation_defs.h"


void InitBox_1CBOXP(Box * const box)
{
    box->length = 1;
    box->height = 1;
    box->width = 1;
    BOX_print_1KCBOXP(box);
}

void InitBox_2CBOXPDL(Box * const box,double dim)
{
    /*mil*/
    box->length = dim;
    box->width = dim;
    box->height = dim;
    /*body*/
    BOX_print_1KCBOXP(box);
}

void InitBox_4CBOXPDLDLDL(Box * const box, double l, double w, double h)
{
    /*mil*/
    box->length = l;
    box->width = w;
    box->height = h;
    /*body*/
    BOX_print_1KCBOXP(box);
}

void BoxDtor_1CBOXP(Box *box)
{
    printf("Box destructor, %f x %f x %f\n", box->width, box->height, box->length);
}

Box* BOX_operatorMultEq_2KCBOXPDL(Box * const box, double mult)
{
    box->width *= mult;
    box->height *= mult;
    box->length *= mult;
    return box;
}

void BOX_print_1KCBOXP(const Box * const box)
{
    printf("Box: %f x %f x %f\n", box->length, box->width, box->height);
}

double BOX_getWidth_1KCBOXP(const Box * const box)
{
    return box->width;
}

double BOX_getLength_1KCBOXP(const Box * const box)
{
    return box->length;
}

double BOX_getHeight_1KCBOXP(const Box * const box)
{
    return box->height;
}

double BOX_getVolume_1KCBOXP(const Box * const box)
{
    return BOX_getWidth_1KCBOXP(box) * BOX_getLength_1KCBOXP(box) * BOX_getHeight_1KCBOXP(box);
}

bool BOX_operator_eq_2KCBOXPKCBOXP(const Box * const box1,const Box * const box2)
{
    return box1->height == box2->height && box1->width == box2->width && box1->length == box2->length;
}




/*shelf*/

const char * message = "The total volume held on the shelf is";

void InitShelf_1KCSHELFP(Shelf * const shelf)
{
    size_t i;
    for (i = 0;  i < NUM_BOXES ; ++i)
    {
        InitBox_1CBOXP((shelf->boxes)+i);
    }
}

void ShelfDtor_1SHELFP(Shelf * shelf)
{
    size_t i;
    for (i = NUM_BOXES;  i > 0 ; --i)
    {
        BoxDtor_1CBOXP((shelf->boxes)+i -1);
    }
}

void SHELF_setBox_3KCSHELFPIKCBOXP(Shelf * shelf, int index, Box * const dims)
{
    shelf->boxes[index] = *(dims);
}

double SHELF_getVolume_1KCSHELFP(const Shelf * const shelf)
{
    double vol = 0;
    size_t i = 0;
    for (; i < NUM_BOXES; ++i)
    vol += shelf->boxes[i].width * shelf->boxes[i].height * shelf->boxes[i].length;
    return vol;
}

void SHELF_print_1KCSHELFP(const Shelf * const shelf)
{
    printf("%s %f\n", message, SHELF_getVolume_1KCSHELFP(shelf));
}

void SHELF_setMessage_1KCHP(const char* msg)
{
    message = msg;
}


