#include "cpp2c_encapsulation_defs_c.h"
#include<stdio.h>

void init_box_b_bddd( Box* b, double w, double h, double l )
{
	b->width = w;
	b->height = h;
	b->length = l;
	
	print_box( b );
}

void init_box_b_bd( Box* b, double dim )
{
	b->width = dim;
	b->height = dim;
	b->length = dim;

	print_box( b );	
}

void init_box_b_( Box* b )
{
	b->width = 1;
	b->height = 1;
	b->length = 1;

	print_box( b );
}

void free_box_b( Box* b )
{
	printf("Box destructor, %f x %f x %f\n", b->width, b->height, b->length);
}

double getWidth_box_b( Box* b )
{
	return b->width;	
}

double getLength_box_b( const Box* b )
{
	return b->length;
}

double getHeight_box_b( const Box* b )
{
	return b->height;
}

double getVolume_box_b( const Box* b )
{
	return b->width * b->length * b->height;
}

void operator_mult_box_bd( Box* b, double mult)
{
	b->width *= mult ;
	b->height *= mult;
	b->length *= mult;
}

void print_box( const Box* b )
{
	printf("Box: %f x %f x %f\n", b->width, b->height, b->length);
}

void operator_mult_bbd(Box* b , Box box, double mult)
{
    *b = box;
    operator_mult_box_bd(b, mult);
}

void operator_mult_bdb(Box* b, double mult, Box box)
{
	operator_mult_bbd (b, box, mult);
}

bool operator_equal_bb( Box lhs, Box rhs)
{
	if(lhs.width == rhs.width && lhs.height == rhs.height && lhs.length == lhs.length)
		return true;

	return false;
}

bool operator_notequal_bb( Box lhs, Box rhs)
{
	if(operator_equal_bb(lhs, rhs))
		return true;

	return false;
}



/*----------------------- shelf --------------------*/



void Shelf_shelf_s(Shelf* s)
{
	Box b;
	init_box_b_(&b);
	int i;
	for( i = 0; i < NUM_BOXES; ++i)
	{
		setBox_shelf_sib(s, i, b);
	}
}


void setBox_shelf_sib(Shelf* s  ,int index, Box dims)
{
	s->boxes[index] = dims;
}

double getVolume_shelf_s(Shelf* s)
{
	double vol = 0;
	int i = 0;
    for (i = 0; i < NUM_BOXES; ++i)
        vol += getVolume_box_b( &(s->boxes[i]) );

    return vol;
}

Box getBox_shelf_si(Shelf* s, int index)
{
	return s->boxes[index];
}

void print_shelf_s(Shelf* s)
{
	printf("%s %f\n", message, getVolume_shelf_s(s));
}

static int getNumBoxes_shelf_s(Shelf* s)
{
	return NUM_BOXES;
}

void setMessage_shelf_sc( Shelf* s, const char* msg )
{
	message = msg;
}

void free_shelf_s(Shelf* s )
{
	
}








