

#include "cpp2c_inheritance_defs.h"

/*Material_t*/
const char* Materials_getName_1CMaterials_Types_enum(Materials_Types_enum type)
{
    const char *const names[] = {"Plastic", "Metal", "Wood", "Paper", "Other"};
    return names[type];
}
const char* Material_t_name_1CMaterial_tKP(const Material_t * const material)
{
    return Materials_getName_1CMaterials_Types_enum(material->m_material);
}

void InitMaterial_t_2CMaterial_tKPTypes(Material_t * const material, Materials_Types_enum mat) {
    material->m_material = mat;
    printf("Material created, set to %s\n", Material_t_name_1CMaterial_tKP(material));
}

Material_t * Material_t_operator_assigment_2CMaterial_tP_Material_tP(Material_t * const material1,const Material_t * const material2)
{
    material1->m_material = material2->m_material;
    return material1;
}


/*PhysicalBox Defs */
void InitPhysicalBox_4CPhysicalBoxKPDLDLDL(PhysicalBox * const physicalbox, double l, double w, double h)
{
    /*base ctor*/

    InitBox_4CBOXPDLDLDL(&physicalbox->base_box, l, w, h);
    InitMaterial_t_2CMaterial_tKPTypes(&physicalbox->material, OTHER);

   /* dtor body*/
    PhysicalBox_printp_1PhysicalBoxKP(physicalbox);
}

void InitPhysicalBox_5CPhysicalBoxKPDLDLDLTypes(PhysicalBox * const physicalbox, double l, double w, double h, Materials_Types_enum t)
{
    /*base ctor*/
    Box base;
    Material_t material;
    InitBox_4CBOXPDLDLDL(&base, l, w, h);
    InitMaterial_t_2CMaterial_tKPTypes(&material, t);
    /*MIL*/
    physicalbox->base_box = base;
    physicalbox->material= material;
    /*dtor body*/
    PhysicalBox_printp_1PhysicalBoxKP(physicalbox);
}

void InitPhysicalBox_2CPhysicalBoxKPTypes(PhysicalBox * const physicalbox, Materials_Types_enum t)
{
    /*base ctor*/
    Box base;
    Material_t material;
    InitBox_1CBOXP(&base);
    InitMaterial_t_2CMaterial_tKPTypes(&material, t);
    /*MIL*/
    physicalbox->base_box = base;
    physicalbox->material= material;
    /*dtor body*/
    PhysicalBox_printp_1PhysicalBoxKP(physicalbox);
}

void PhysicalBoxDtor_1CPhysicalBoxkP(PhysicalBox * const physicalbox)
{
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", physicalbox->base_box.length, physicalbox->base_box.width, physicalbox->base_box.height, Material_t_name_1CMaterial_tKP(&physicalbox->material));
    BoxDtor_1CBOXP(&physicalbox->base_box);
}

void PhysicalBox_printp_1PhysicalBoxKP(const PhysicalBox * const physicalbox) {
    printf("PhysicalBox, made of %s; ", Material_t_name_1CMaterial_tKP(&physicalbox->material));
    BOX_print_1KCBOXP(&physicalbox->base_box);
}

PhysicalBox * PhysicalBox_operator_assignment_2CPhysicalboxKPCPhysicalboxKP(PhysicalBox * const physicalBox, const PhysicalBox * const other)
{
    physicalBox->base_box = other->base_box;
    Material_t_operator_assigment_2CMaterial_tP_Material_tP(&physicalBox->material,&other->material);
    return physicalBox;
}

Materials_Types_enum PhysicalBox_getMaterial_1PhysicalBoxKP(const PhysicalBox * const physicalbox)
{
    return physicalbox->material.m_material;
}
bool PhysicalBox_operator_eq_2CPhysicalBoxKPCPhysicalBoxKP(PhysicalBox *const box1, PhysicalBox*const box2)
{
    return BOX_operator_eq_2KCBOXPKCBOXP((Box* const )&box1->base_box, (Box* const )&box2->base_box) && PhysicalBox_getMaterial_1PhysicalBoxKP(box1) == PhysicalBox_getMaterial_1PhysicalBoxKP(box2);
}
bool PhysicalBox_operator_neq_2CPhysicalBoxKPCPhysicalBoxKP(PhysicalBox *const box1, PhysicalBox*const box2)
{
    return !(PhysicalBox_operator_eq_2CPhysicalBoxKPCPhysicalBoxKP(box1, box2));
}



/* WeightBox Defs */
void InitWeightBox_5CWeightBoxKPDLDLDLDL(WeightBox * const weightBox, double l, double w, double h, double wgt ) {
    /*base ctor*/
    InitBox_4CBOXPDLDLDL(&weightBox->base_box, l, w, h);
    /*MIL*/
    weightBox->weight = wgt;
    /*dtor body*/
    WeightBox_printw_1CWeightBoxKP(weightBox);
}
void WeightBox_copyCtor_2CWeightBoxKPCWeightBoxKP(WeightBox * const weightBox, const WeightBox * const other)
{
    /*base ctor*/
    InitBox_1CBOXP(&weightBox->base_box);
    /*MIL*/
    weightBox->weight = other->weight;
    /*dtor body*/
    WeightBox_printw_1CWeightBoxKP(weightBox);
}

void WeightBoxDTOR_1CWeightBoxKP(WeightBox * const weightBox)
{
    printf("Destructing WeightBox; ");
    WeightBox_printw_1CWeightBoxKP(weightBox);
    BoxDtor_1CBOXP(&weightBox->base_box);
}

WeightBox * WeightBox_operator_assignment_2CWeightBoxKPCWeightBoxKP(WeightBox * const weightBox, const WeightBox * const other)
{
    weightBox->weight = other->weight;
    return weightBox;
}

void WeightBox_printw_1CWeightBoxKP(WeightBox * const weightBox)
{
    printf("WeightBox, weight: %f; ", weightBox->weight);
    BOX_print_1KCBOXP(&weightBox->base_box);
}

double WeightBox_getWeight_1CWeightBoxKP(WeightBox * const weightBox)
{
    return weightBox->weight;
}
bool WeightBox_operator_eq_2CWeightBoxKPCWeightBoxKP(WeightBox * const weightBox1, WeightBox * const weightBox2)
{
    return BOX_operator_eq_2KCBOXPKCBOXP ((Box* const)&weightBox1->base_box, ( Box* const)&weightBox2->base_box) && WeightBox_getWeight_1CWeightBoxKP(weightBox1) == WeightBox_getWeight_1CWeightBoxKP(weightBox2);
}
bool WeightBox_operator_neq_2CWeightBoxKPCWeightBoxKP(WeightBox * const weightBox1, WeightBox * const weightBox2)
{
    return !WeightBox_operator_eq_2CWeightBoxKPCWeightBoxKP(weightBox1, weightBox2);
}
