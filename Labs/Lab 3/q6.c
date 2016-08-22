/*Q6 - Pass by Referrence:(passing parameters by referrence)*/
#include <stdio.h>
/* Declare Prototype */
void pass_by_reference (*int)
main()
{
	int initial_number = 1;
	printf("initial_number is %d\n", initial_number);
    getchar();
	/*Call function pass_by_reference()*/
	pass_by_reference(*initial_number);
    getchar();
	printf("\ninitial number is now %d \n", initial_number);
    getchar();
    flushall();
}/*end main*/
	
/*Implement any_function()*/

void pass_by_value(int* new_number)
{	
	*new_number++;
    printf("\nnew_number is %d\n", *new_number);
}/*end function*/