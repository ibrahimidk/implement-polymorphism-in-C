#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include "cpp2c_encapsulation_defs.h"


typedef enum
{
	PLASTIC,
	METAL,
	WOOD,
	PAPER,
	OTHER
} Types;
	
	
typedef struct 
{
	Types t;
	
} Materials;



static const char* getName_Materials_t( Types type );


typedef struct
{
    Types material;

} Material_t;


void  Material_t_mt( Material_t* mt, Types mat);
void  Material_t_m( Material_t* mt);
const char* name_Material_t(const Material_t* const mt);


/*----------------------- PhysicalBox ------------------------------*/

typedef struct
{
	Box father_box;
	Material_t material;
	
} PhysicalBox;

void init_PhysicalBox_pddd(PhysicalBox* pb ,double l, double w, double h);

void init_PhysicalBox_pdddm(PhysicalBox* pb, double l, double w, double h, Types t);

void init_PhysicalBox_pt(PhysicalBox* pb, Types t);

void cpy_PhysicalBox_pp(PhysicalBox* this, const PhysicalBox* const other);

void _PhysicalBox_p(PhysicalBox* pb);

Types getMaterial_p_p(PhysicalBox* const pb);

void print_p_p(const PhysicalBox* const pb);

bool operator_p_equal_pp(const PhysicalBox* const this , const PhysicalBox* const other );
bool operator_p_notequal_pp(const PhysicalBox* const this , const PhysicalBox* const other );

/*----------------------- WeightBox ------------------------------*/

typedef struct 
{
	Box father_box;
    double weight;
    
} WeightBox;

void init_WeightBox_wddd(WeightBox* wb, double l, double w, double h);
void init_WeightBox_wdddd(WeightBox* wb, double l, double w, double h, double wgt);
void init_WeightBox_w_ww(WeightBox* this, const WeightBox* const other);
void des_WeightBox(WeightBox* this);

bool operator_w_equal_ww(const WeightBox* const this, const WeightBox* const other);
bool operator_w_notequal_ww(const WeightBox* const this, const WeightBox* const other);

void print_w_w(WeightBox* const wb);

#endif






















