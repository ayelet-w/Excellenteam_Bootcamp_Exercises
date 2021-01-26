

#ifndef UTH_CPP2C_INHERITANCE_DEFS_H
#define UTH_CPP2C_INHERITANCE_DEFS_H

#include <stdio.h>
#include <stdbool.h>
#include "cpp2c_encapsulation_defs.h"

typedef struct Materials
{
    char dummy;
}Materials;

typedef enum Materials_Types_enum
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Materials_Types_enum;



typedef struct Material_t
{
    /*empty struct Materials*/
    Materials_Types_enum m_material;
}Material_t;

const char* Materials_getName_1CMaterials_Types_enum(Materials_Types_enum type);

const char* Material_t_name_1CMaterial_tKP(const Material_t * const material);

void InitMaterial_t_2CMaterial_tKPTypes(Material_t * const material, Materials_Types_enum mat);

Material_t * Material_t_operator_assigment_2CMaterial_tP_Material_tP(Material_t * const material1,const Material_t * const material2);



/* PhysicalBox */
typedef struct PhysicalBox
{
    Box base_box;
    Material_t material;
} PhysicalBox;

void InitPhysicalBox_4CPhysicalBoxKPDLDLDL(PhysicalBox * const physicalbox, double l, double w, double h);

void InitPhysicalBox_5CPhysicalBoxKPDLDLDLTypes(PhysicalBox * const physicalbox, double l, double w, double h, Materials_Types_enum t);

void InitPhysicalBox_2CPhysicalBoxKPTypes(PhysicalBox * const physicalbox, Materials_Types_enum t);

void PhysicalBoxDtor_1CPhysicalBoxkP(PhysicalBox * const physicalbox);

PhysicalBox * PhysicalBox_operator_assignment_2CPhysicalboxKPCPhysicalboxKP(PhysicalBox * const physicalBox, const PhysicalBox * const other);

Materials_Types_enum PhysicalBox_getMaterial_1PhysicalBoxKP(const PhysicalBox * const physicalbox);

void PhysicalBox_printp_1PhysicalBoxKP(const PhysicalBox * const physicalbox);

bool PhysicalBox_operator_eq_2CPhysicalBoxKPCPhysicalBoxKP(PhysicalBox *const box1, PhysicalBox*const box2);

bool PhysicalBox_operator_neq_2CPhysicalBoxKPCPhysicalBoxKP(PhysicalBox *const box1, PhysicalBox*const box2);





/*WeightBox */
typedef  struct WeightBox
{
    Box base_box;
    double weight;
}WeightBox;

void InitWeightBox_5CWeightBoxKPDLDLDLDL(WeightBox * const weightBox, double l, double w, double h, double wgt );

void WeightBox_copyCtor_2CWeightBoxKPCWeightBoxKP(WeightBox * const weightBox, const WeightBox * const other);

void WeightBoxDTOR_1CWeightBoxKP(WeightBox * const weightBox);

WeightBox * WeightBox_operator_assignment_2CWeightBoxKPCWeightBoxKP(WeightBox * const weightBox, const WeightBox * const other);

double WeightBox_getWeight_1CWeightBoxKP(WeightBox * const weightBox);

void WeightBox_printw_1CWeightBoxKP(WeightBox * const weightBox);

bool WeightBox_operator_eq_2CWeightBoxKPCWeightBoxKP(WeightBox * const weightBox1, WeightBox * const weightBox2);

bool WeightBox_operator_neq_2CWeightBoxKPCWeightBoxKP(WeightBox * const weightBox1, WeightBox * const weightBox2);



#endif
