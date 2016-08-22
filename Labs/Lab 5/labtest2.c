/*Lab Test 2 - Kieran Hogan - DT228/1 - 26/02/13*/
#include <stdio.h>
/*Declare function protoypes*/
int next_five_terms (int);
int output (int); 
main()
{
    int fibonacci[10]={0,1,1,2,3};
    int i; 
    int n = 0;
    for(i=4;i<10;i++)
    {
        fibonacci[i] = next_five_terms(n);
    }//end for
    
    for(i=0;i<10;i++)
    {
        output(fibonacci[i]);
    }//end for
    
    flushall();
    
    getchar();
}
//End main();

/*Function to handle the last 5 terms of the array*/
int next_five_terms (int n)

{
    if (n > 10)
    {
        return 0;
    }//end if
    else
    {
        return(next_five_terms(n-1) + next_five_terms(n-2));
    }//end else
}//end function next_five_terms();

/*Function to print out array*/
void output (int fibonacci[])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d", fibonacci[i]);
    }//end for
    
}//end function display();

//Program unfinished

