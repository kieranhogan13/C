/*Program to show another use for malloc*/
#include <stdio.h>
#include <stdlib.h>

main()

{
    int i;
    float no_bytes, *ptr, *ptr2;
    int no_els = 5;
    
    
    /*Calculate the number of bytes required*/
    no_bytes = (no_els*sizeof(float));
    
    /*Allocate the memory*/
    ptr = (float*)malloc(no_bytes);
    
    if(ptr == NULL)
    {
        printf("Cannot allocate memory\n");
    }
    else
    {
        /*Enter the numbers*/
        printf("Enter 5 elements:\n");
        for(i=0;i<no_els;i++)
        {
            scanf("%f", (ptr+i));
        }
        /*Display the number entered in the block*/
        for(i=0;i<no_els;i++)
        {
            printf("%f\n", *(ptr+i));
        }
        /*Display the average of the numbers entered in the block*/
        for
        
        /*Free the allocated memory*/
        free(ptr);
    }
    flushall();
    getchar();
}/*End main*/