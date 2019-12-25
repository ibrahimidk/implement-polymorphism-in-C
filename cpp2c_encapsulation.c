#include<stdio.h>
#include "cpp2c_encapsulation_defs_c.h"

static bool static_thisFunc_boxes = true;
static bool static_thatFunc_boxes = true;
static Box box99;
static Box box88;

static Box largeBox;

void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n"); 
    if(static_thisFunc_boxes){
		init_box_b_bddd(&box99, 99, 99, 99);
		static_thisFunc_boxes = false;
    }
    operator_mult_box_bd(&box99, 10);
}


void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n"); 
    if(static_thatFunc_boxes){
		init_box_b_bddd(&box88, 88, 88, 88);
    	static_thatFunc_boxes = false;
    }
    operator_mult_box_bd(&box88, 10);
}


void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1;
    init_box_b_bd(&b1, 3);
    Box b2;
    init_box_b_bddd(&b2,4, 5, 6);
    
    printf("b1 volume: %f\n", getVolume_box_b(&b1));
    printf("b2 volume: %f\n", getVolume_box_b(&b2));

	operator_mult_box_bd( &b1, 1.5);
	operator_mult_box_bd( &b2, 0.5);

    printf("b1 volume: %f\n", getVolume_box_b(&b1));
    printf("b2 volume: %f\n", getVolume_box_b(&b2));

    Box b3 = b2;
    
    Box b4;
    
    
    operator_mult_bdb(&b4, 3, b2);
    
    printf("b3 %s b4\n", operator_equal_bb(b3, b4) ? "equals" : "does not equal");

    operator_mult_box_bd(&b3, 1.5);
    operator_mult_box_bd(&b4, 0.5);
    
    printf("Now, b3 %s b4\n", operator_equal_bb(b3, b4) ? "equals" : "does not equal");
	
    printf("\n--- End doBoxes() ---\n\n");
    
    free_box_b(&b4);
    free_box_b(&b3);
    free_box_b(&b2);
    free_box_b(&b1);
}



void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");
	
	Box aBox;
	init_box_b_bd(&aBox, 5);
    

    Shelf aShelf;
    Shelf_shelf_s(&aShelf);
	
	print_shelf_s(&aShelf);
  	
  	init_box_b_bddd(&largeBox,10, 20, 30);
  	setBox_shelf_sib(&aShelf, 1, largeBox);
  	setBox_shelf_sib(&aShelf, 0, aBox);


	print_shelf_s(&aShelf);
	setMessage_shelf_sc(&aShelf, "This is the total volume on the shelf:" );
	print_shelf_s(&aShelf);
	setMessage_shelf_sc(&aShelf, "Shelf's volume:" );
	print_shelf_s(&aShelf);

	Box tmp;
	init_box_b_bddd(&tmp, 2, 4, 6);
	setBox_shelf_sib(&aShelf, 1, tmp);
	
	
	init_box_b_bd(&tmp, 2);
	setBox_shelf_sib(&aShelf, 2, tmp);
  
	print_shelf_s(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

	int i;
	for(i=NUM_BOXES - 1; i >= 0 ; --i )
	{
		free_box_b(&(aShelf.boxes[i]));	
	}
	
	free_box_b(&tmp);
}






