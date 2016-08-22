/*Q1 - Pass by Referrence to find area - Kieran Hogan DT228/1*/
#include <stdio.h>
/* Declare Prototype */
int area_of_square (int*);
float area_of_circle (float*);
main()
{
    printf("Area Calculator\n\n");
	int side_square;
    float radius_circle;
	printf("Please enter a number for the length of the side of the square: ");
    scanf("%d",&side_square);
    getchar();
    printf("Please enter a number for the radius of the circle: ");
    scanf("%f",&radius_circle);
    
	/*Call function area_of_square()*/
	int answer1 = area_of_square(&side_square);
	printf("\Area of the square is %d^2\n", answer1);
    getchar();
    
    /*Call function area_of_circle()*/
	float answer2 = area_of_circle(&radius_circle);
	printf("\Area of the circle is %f^2\n",answer2);
    flushall();
    getchar();
}/*end main*/
	
/*Implement area_of_square()*/
int area_of_square (int *var1)
{	
    int area_square;
    area_square = (*var1)*(*var1);
    return(area_square);
    
}/*end function*/


/*Implemen area_of_circle()*/
float area_of_circle (float *var2)
{
    float area_circle;
    area_circle = (3.14)*((*var2)*(*var2));
    return(area_circle);
    
}/*end function*/