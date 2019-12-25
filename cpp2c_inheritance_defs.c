#include "cpp2c_inheritance_defs.h"
#include<stdio.h>



static const char* getName_Materials_t( Types type )
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	return names[type];
}

void  Material_t_mt( Material_t* mt, Types mat)
{
	mt->material = mat;
	printf("Material created, set to %s\n", name_Material_t(mt));
}


void  Material_t_m( Material_t* mt)
{
	mt->material = OTHER;
	printf("Material created, set to %s\n", name_Material_t(mt));
}

const char* name_Material_t(const Material_t* const mt)
{
	return getName_Materials_t(mt->material); 
}

/*----------------------- PhysicalBox ------------------------------*/

void init_PhysicalBox_pddd(PhysicalBox* pb ,double l, double w, double h)
{
	init_box_b_bddd(&(pb->father_box), w, h, l);
	Material_t_m(&(pb->material ));
	print_p_p(pb);
}

void init_PhysicalBox_pdddm(PhysicalBox* pb, double l, double w, double h, Types t)
{
	init_box_b_bddd(&(pb->father_box), w, h, l);
	pb->material.material = t;
	
	print_p_p(pb);
}

void init_PhysicalBox_pt(PhysicalBox* pb, Types t)
{
	init_box_b_(&(pb->father_box));
	pb->material.material = t;	
	
	print_p_p(pb);
}

void cpy_PhysicalBox_pp(PhysicalBox* this, const PhysicalBox* const other)
{
	this->father_box = other->father_box;
	this->material.material = other->material.material;
}

void _PhysicalBox_p(PhysicalBox* pb)
{
    printf("PhysicalBox dtor, %f x %f x %f, %s; ",getLength_box_b(&(pb->father_box)), getWidth_box_b(&(pb->father_box)), getHeight_box_b(&(pb->father_box)), name_Material_t(&(pb->material)));
}

Types getMaterial_p_p(PhysicalBox* const pb)
{
	return pb->material.material;
}

void print_p_p(const PhysicalBox* const pb)
{
    printf("PhysicalBox, made of %s; ", name_Material_t(&(pb->material)));
    
    print_box(&(pb->father_box));
}

bool operator_p_equal_pp(const PhysicalBox* const this , const PhysicalBox* const other )
{
	if(operator_equal_bb(this->father_box, other->father_box) && this->material.material == other->material.material)
		return true;
		
	return false;
}

bool operator_p_notequal_pp(const PhysicalBox* const this , const PhysicalBox* const other )
{
	if(operator_p_equal_pp(this, other))
		return false;
	
	return true;
}

/*----------------------- WeightBox ------------------------------*/

void init_WeightBox_wddd(WeightBox* wb, double l, double w, double h)
{
	init_box_b_(&(wb->father_box));
	wb->weight = 0;
	print_w_w(wb);
}

void init_WeightBox_wdddd(WeightBox* wb, double l, double w, double h, double wgt)
{
	init_box_b_(&(wb->father_box));
	wb->weight = wgt;
	
	print_w_w(wb);
}

void init_WeightBox_w_ww(WeightBox* this, const WeightBox* const other)
{
	this->father_box = other->father_box;
	this->weight = other->weight; 

	print_w_w(this);	
}

void des_WeightBox(WeightBox* this)
{
    printf("Destructing WeightBox; ");
    
    print_w_w(this);
}

void print_w_w(WeightBox* const wb)
{
    printf("WeightBox, weight: %f; ", wb->weight);
    
    print_box(&(wb->father_box));  
    
}

bool operator_w_equal_ww(const WeightBox* const this, const WeightBox* const other)
{
	if(operator_equal_bb(this->father_box, other->father_box) && this->weight == other->weight )
		return true;
		
	return false;
}

bool operator_w_notequal_ww(const WeightBox* const this, const WeightBox* const other)
{
	if(operator_w_equal_ww(this, other) )
		return false;
		
	return true;
}














