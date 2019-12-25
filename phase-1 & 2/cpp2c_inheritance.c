#include "cpp2c_inheritance_defs.h"
#include<stdio.h>


void doMaterials()
{
    printf("\n--- Start doMaterials() ---\n\n");
    
    Materials mat;
    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    typedef struct { Materials mat; Material_t mat_t; }MatTest;
    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));
    
    Material_t mat1;
    Material_t_m(&mat1);
    Material_t mat2;
	Material_t_mt(&mat2, METAL);
	
    printf("\n--- End doMaterials() ---\n\n");
}


void doPhysicalBox()
{
    printf("\n--- Start doPhysicalBox() ---\n\n");

    PhysicalBox pb1;
    init_PhysicalBox_pdddm(&pb1, 8, 6, 4, PLASTIC);
    PhysicalBox pb2;
    init_PhysicalBox_pt(&pb2, WOOD);
    PhysicalBox pb3;
    init_PhysicalBox_pddd(&pb3, 7, 7, 7);
    
    printf("\npb4 is copy-constructed from pb1\n");
    PhysicalBox pb4;
    pb4 = pb1;
    cpy_PhysicalBox_pp(&pb4, &pb1);
    print_p_p(&pb4);
    print_p_p(&pb1);
    printf("pb4 %s pb1\n", operator_p_equal_pp(&pb4, &pb1) ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    cpy_PhysicalBox_pp(&pb4, &pb3);
    print_p_p(&pb4);
    print_p_p(&pb3);
    printf("pb4 %s pb3\n", operator_p_equal_pp(&pb4, &pb3) ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
}



void doWeightBox()
{
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox pw1;
    init_WeightBox_wdddd(&pw1, 8, 6, 4, 25);
    WeightBox pw2;
    init_WeightBox_wddd(&pw2, 1, 2, 3);
    WeightBox pw3;
    init_WeightBox_wdddd(&pw3, 10, 20, 30, 15);
    
    printf("\npw4 is copy-constructed from pw1\n");
    WeightBox pw4;
    init_WeightBox_w_ww(&pw4, &pw1);
    print_w_w(&pw4);
    print_w_w(&pw1);
    printf("pw4 %s pw1\n", operator_w_equal_ww(&pw4, &pw1) ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    init_WeightBox_w_ww(&pw4, &pw3);
    print_w_w(&pw4);
    print_w_w(&pw3);
    printf("pw4 %s pw3\n", operator_w_equal_ww(&pw4, &pw3) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
}





int main()
{
    printf("\n--- Start main() ---\n\n");
    
	doMaterials();
	doPhysicalBox();
	doWeightBox();
    printf("\n--- End main() ---\n\n");
    
	return 0;	
}
