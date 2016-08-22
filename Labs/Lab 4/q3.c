/*Q3 - Passing 1-D Array - Kieran Hogan DT228/1*/
#include <stdio.h>
/* Declare Prototype */
int my_array(int[]);
main()
{
    printf("Average from array of 5\n\n");
    int numbers[5];
    int size = 5;
	int average;
    int i;
    for(i=0;i<size;i++)
    {
        printf("Enter element: ");
        scanf("%d", &numbers[i]);
        printf("\n");
    }
        
	/*Call the function sum_array()*/
	average = my_array(numbers);
	printf("The average is %d", average);
    flushall();
    getchar();
}//end main

/*Implement function*/
int my_array (int numbers[])
{
    int j, sum=0;
    for (j = 0; j < 5; j++)
    {
        sum+=numbers[j];
    }//end for
    
    printf("\nSum is %d\n\n", sum);
    
    int average = sum/5;
	return(average);
}//end my_array