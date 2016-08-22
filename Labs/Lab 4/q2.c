/*Q2 - Passing 1-D Array - Kieran Hogan DT228/1*/
#include <stdio.h>
/* Declare Prototype */
int my_array(int[], int);
main()
{
    printf("Highest number from array of 5\n\n");
    int numbers[5];
    int size = 5;
	int highest;
    int i;
    for(i=0;i<size;i++)
    {
        printf("Enter element: ");
        scanf("%d", &numbers[i]);
        printf("\n");
    }
        
	/*Call the function sum_array()*/
	highest = my_array(numbers, 5);
	printf("The highest number is %d", highest);
    flushall();
    getchar();
}//end main

/*Implement function*/
int my_array (int numbers[], int highest)
{
    int j;
    for (j = 0; j < 5; j++)
    {
        if (numbers[j] > highest)
        {
            highest = numbers[j];
        }
    }//end for
	return(highest);
}//end my_array