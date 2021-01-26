/*#include <stdio.h>

#include "cpp2c_encapsulation_defs.h"

static Box largeBox;
static Box * thisFunc_box99 = NULL;
static Box * thatFunc_box88 = NULL;



void thisFunc()
{
    static Box box99;
    printf("\n--- thisFunc() ---\n\n");

    if(!thisFunc_box99)
    {
        thisFunc_box99 = &box99;
        InitBox_4CBOXPDLDLDL(&box99,99, 99, 99);
    }

    BOX_operatorMultEq_2KCBOXPDL(&box99, 10);
}

void thatFunc()
{
    static Box box88;
    printf("\n--- thatFunc() ---\n\n");

    if(!thatFunc_box88)
    {
        thatFunc_box88 = &box88;
        InitBox_4CBOXPDLDLDL(&box88,88, 88, 88);
    }

    BOX_operatorMultEq_2KCBOXPDL(&box88, 10);
}

void doBoxes()
{
    Box b1;
    Box b2;
    Box b3;
    Box b4;

    printf("\n--- Start doBoxes() ---\n\n");

    InitBox_2CBOXPDL(&b1,3);
    InitBox_4CBOXPDLDLDL(&b2,4, 5, 6);

    printf("b1 volume: %f\n", BOX_getVolume_1KCBOXP(&b1));
    printf("b2 volume: %f\n", BOX_getVolume_1KCBOXP(&b2));

    BOX_operatorMultEq_2KCBOXPDL(&b1, 1.5);
    BOX_operatorMultEq_2KCBOXPDL(&b2, 0.5);

    printf("b1 volume: %f\n", BOX_getVolume_1KCBOXP(&b1));
    printf("b2 volume: %f\n", BOX_getVolume_1KCBOXP(&b2));

    b3 = b2;
    b2.width *= 3;
    b2.height *= 3;
    b2.length *= 3;
    b4 = b2;
    printf("b3 %s b4\n", b3.height == b4.height && b3.length == b4.length && b3.width == b4.width? "equals" : "does not equal");

    BOX_operatorMultEq_2KCBOXPDL(&b3, 1.5);
    BOX_operatorMultEq_2KCBOXPDL(&b4, 0.5);
    printf("Now, b3 %s b4\n", b3.height == b4.height && b3.length == b4.length && b3.width == b4.width? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    BoxDtor_1CBOXP(&b4);
    BoxDtor_1CBOXP(&b3);
    BoxDtor_1CBOXP(&b2);
    BoxDtor_1CBOXP(&b1);
}


void doShelves()
{
    Box aBox;
    Shelf aShelf;
    Box box;

    printf("\n--- start doShelves() ---\n\n");


    InitBox_2CBOXPDL(&aBox, 5);

    InitShelf_1KCSHELFP(&aShelf);

    SHELF_print_1KCSHELFP(&aShelf);
    SHELF_setBox_3KCSHELFPIKCBOXP(&aShelf, 1, &largeBox);
    SHELF_setBox_3KCSHELFPIKCBOXP(&aShelf, 0, &aBox);

    SHELF_print_1KCSHELFP(&aShelf);
    SHELF_setMessage_1KCHP("This is the total volume on the shelf:");
    SHELF_print_1KCSHELFP(&aShelf);
    SHELF_setMessage_1KCHP("Shelf's volume:");
    SHELF_print_1KCSHELFP(&aShelf);

    InitBox_4CBOXPDLDLDL(&box,2,4,6);
    SHELF_setBox_3KCSHELFPIKCBOXP(&aShelf, 1, &box);
    BoxDtor_1CBOXP(&box);


    InitBox_2CBOXPDL(&box,2);
    SHELF_setBox_3KCSHELFPIKCBOXP(&aShelf, 2, &box);
    BoxDtor_1CBOXP(&box);
    SHELF_print_1KCSHELFP(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    ShelfDtor_1SHELFP(&aShelf);
    BoxDtor_1CBOXP(&aBox);
}

int main()
{
    InitBox_4CBOXPDLDLDL(&largeBox,10, 20, 30);

    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");

    if(thatFunc_box88)
        BoxDtor_1CBOXP(thatFunc_box88);

    if(thisFunc_box99)
        BoxDtor_1CBOXP(thisFunc_box99);

    BoxDtor_1CBOXP(&largeBox);

    return 0;
}*/





/*part 2*/



#include "cpp2c_inheritance_defs.h"


void doMaterials()
{
    Materials mat;
    Material_t mat1;
    Material_t mat2;
    typedef struct MatTest MatTest;
    struct MatTest { Materials mat; Material_t mat_t; };

    printf("\n--- Start doMaterials() ---\n\n");

    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Materials_Types_enum: %lu\n", sizeof(Materials_Types_enum));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));
    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));

    /*default ctor mat1*/
    InitMaterial_t_2CMaterial_tKPTypes(&mat1,OTHER);
    InitMaterial_t_2CMaterial_tKPTypes(&mat2, METAL);

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
    PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;

    printf("\n--- Start doPhysicalBox() ---\n\n");

    InitPhysicalBox_5CPhysicalBoxKPDLDLDLTypes(&pb1, 8, 6, 4, PLASTIC);
    InitPhysicalBox_2CPhysicalBoxKPTypes(&pb2, WOOD);
    InitPhysicalBox_4CPhysicalBoxKPDLDLDL(&pb3, 7, 7, 7);
    printf("\npb4 is copy-constructed from pb1\n");
    PhysicalBox_operator_assignment_2CPhysicalboxKPCPhysicalboxKP(&pb4, &pb1);
    PhysicalBox_printp_1PhysicalBoxKP(&pb4);
    PhysicalBox_printp_1PhysicalBoxKP(&pb1);
    printf("pb4 %s pb1\n", PhysicalBox_operator_eq_2CPhysicalBoxKPCPhysicalBoxKP(&pb4, &pb1) ? "equals" : "does not equal");
    printf("\npb4 is copy-assigned from pb3\n");
    PhysicalBox_operator_assignment_2CPhysicalboxKPCPhysicalboxKP(&pb4, &pb3);
    PhysicalBox_printp_1PhysicalBoxKP(&pb4);
    PhysicalBox_printp_1PhysicalBoxKP(&pb3);
    printf("pb4 %s pb3\n", PhysicalBox_operator_eq_2CPhysicalBoxKPCPhysicalBoxKP(&pb4, &pb3) ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");

    PhysicalBoxDtor_1CPhysicalBoxkP(&pb4);
    PhysicalBoxDtor_1CPhysicalBoxkP(&pb3);
    PhysicalBoxDtor_1CPhysicalBoxkP(&pb2);
    PhysicalBoxDtor_1CPhysicalBoxkP(&pb1);
}
void doWeightBox()
{
    WeightBox pw1;
    WeightBox pw2;
    WeightBox pw3;
    WeightBox pw4;
    printf("\n--- Start doWeightBox() ---\n\n");

    InitWeightBox_5CWeightBoxKPDLDLDLDL(&pw1, 8, 6, 4, 25);
    InitWeightBox_5CWeightBoxKPDLDLDLDL(&pw2,1, 2, 3, 0.0);
    InitWeightBox_5CWeightBoxKPDLDLDLDL(&pw3,10, 20, 30, 15);
    printf("\npw4 is copy-constructed from pw1\n");
    WeightBox_copyCtor_2CWeightBoxKPCWeightBoxKP(&pw4, &pw1);
    WeightBox_printw_1CWeightBoxKP(&pw4);
    WeightBox_printw_1CWeightBoxKP(&pw1);
    printf("pw4 %s pw1\n", WeightBox_operator_eq_2CWeightBoxKPCWeightBoxKP(&pw4, &pw1) ? "equals" : "does not equal");
    printf("\npw4 is copy-assigned from pw3\n");
    WeightBox_operator_assignment_2CWeightBoxKPCWeightBoxKP(&pw4, &pw3);
    WeightBox_printw_1CWeightBoxKP(&pw4);
    WeightBox_printw_1CWeightBoxKP(&pw3);
    printf("pw4 %s pw3\n", WeightBox_operator_eq_2CWeightBoxKPCWeightBoxKP(&pw4, &pw3) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    WeightBoxDTOR_1CWeightBoxKP(&pw4);
    WeightBoxDTOR_1CWeightBoxKP(&pw3);
    WeightBoxDTOR_1CWeightBoxKP(&pw2);
    WeightBoxDTOR_1CWeightBoxKP(&pw1);

}

int main()
{
    /*init*/
    printf("\n--- Start main() ---\n\n");
    doMaterials();
    doPhysicalBox();
    doWeightBox();
    printf("\n--- End main() ---\n\n");
    return 0;
}


