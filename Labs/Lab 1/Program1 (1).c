/*http://www.linuxtopia.org/online_books/programming_books/gnu_c_programming_tutorial/index.html*/

/*Program to illustrate the use of malloc*/
#include <stdio.h>
#include <stdlib.h>

main()

{
    int *ptr;
    int no_els, no_bytes, i;
    printf("Enter the number of elements\n");
    scanf("%d", &no_els);
    
    /*Calculate the number of bytes required*/
    no_bytes = (no_els*sizeof(int));
    
    /*Allocate the memory*/
    ptr = (int*)malloc(no_bytes);
    
    if(ptr == NULL)
    {
        printf("Cannot allocate memory\n");
    }
    else
    {
        /*Enter the numbers*/
        for(i=0;i<no_els;i++)
        {
            scanf("%d", (ptr+i));
        }
        /*Display the number entered in the block*/
        for(i=0;i<no_els;i++)
        {
            printf("%d\n", *(ptr+i));
        }
        /*Free the allocated memory*/
        free(ptr);
    }
    flushall();
    getchar();
}/*End main*/