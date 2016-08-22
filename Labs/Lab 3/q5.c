/*Q5 - Pass by value:(passing parameters by value)*/
#include <stdio.h>
/* Declare Prototype */
void pass_by_value (int);
main()
{
	int initial_number = 1;
	printf("initial_number is %d\n", initial_number);
    getchar();
	/*Call function pass_by_value()*/
	pass_by_value(initial_number);
    getchar();
	printf("\ninitial_number is still %d\n", initial_number);
    getchar();
    flushall();
}/*end main*/
	
/*Implement any_function()*/

void pass_by_value(int new_number)
{	
	new_number++;
    printf("\nnew_number is %d\n", new_number);
}/*end function*/