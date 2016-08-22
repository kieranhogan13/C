/*Program to illustrate the use of calloc*/
#include <stdio.h>
#include <stdlib.h>

main()

{
    float *ptr;
    int no_els, i;
    printf("Enter the number of elements\n");
    scanf("%d", &no_els);
    
    /*Allocate the memory*/
    ptr = (float*)calloc(no_els, sizeof(float));
    
    /*Check if memory is allocated sucessfully*/
    if (ptr == NULL)
    {
        printf("Memory can not be allocated");
    }
    else
    {
        /*Enter the number*/
        for (i=0;i<no_els;i++)
        {
            scanf("%f", &*(ptr+i));            
        }
        /*Display the number entered in the block*/
        for(i=0;i<no_els;i++)
        {
            printf("%f\n", *(ptr+i));
        }
        /*Free the memory*/
        free (ptr);
    }
    flushall();
    getchar();
}/*End main*/
