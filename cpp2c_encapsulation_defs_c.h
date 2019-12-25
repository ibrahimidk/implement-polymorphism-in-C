#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

#ifndef __cplusplus
typedef enum
{ 
	false ,true
}bool;
#endif


/*--------------- Box --------------------*/

typedef struct
{
    double width;
    double height;
    double length;
    
}Box;


void init_box_b_bddd( Box* b, double w, double h, double l );
void init_box_b_bd( Box* b, double dim );
void init_box_b_( Box* b );

void free_box_b( Box* b );
double getWidth_box_b( Box* b ); // const Box* const b 
double getLength_box_b( const Box* b ) ;
double getHeight_box_b( const Box* b );

double getVolume_box_b( const Box* b );

void operator_mult_box_bd( Box* b, double mult);

void print_box( const Box* b );



void operator_mult_bbd(Box* b , Box box, double mult);
void operator_mult_bdb(Box* b, double mult, Box box);
bool operator_equal_bb( Box lhs, Box rhs);
bool operator_notequal_bb( Box lhs, Box rhs);


/*--------------- Shelf --------------------*/

#define NUM_BOXES 3
#define DEF_MSG "The total volume held on the shelf is"

static const char* message = DEF_MSG;

typedef struct
{
    Box boxes[NUM_BOXES];
	
}Shelf;

void Shelf_shelf_s(Shelf* s);
void setBox_shelf_sib(Shelf* s  ,int index, Box dims);
double getVolume_shelf_s(Shelf* s);
Box getBox_shelf_si(Shelf* s, int index);
void print_shelf_s(Shelf* s);
static int getNumBoxes_shelf_s(Shelf* s);
void setMessage_shelf_sc( Shelf* s, const char* msg );
void free_shelf_s(Shelf* s );



#endif









