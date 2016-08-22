/*Q3 - Program to use a function to find the highest value of 3 numbers and return to main*/
#include <stdio.h>
/*Declare function prototypes*/
int highest (int, int, int);
main()
{
    int a,b,c;
    int result;
 
    printf("Input number a:\n");
    scanf("%d",&a);
    printf("Input number b:\n");
    scanf("%d",&b);
    printf("Input number c:\n");
    scanf("%d",&c);
    
    /*Call function*/
    result = highest(a,b,c);
    printf("\nThe highest is %d.\n", result);
    
    flushall();
    getchar();
}    
    /*Implent funcion*/
int highest (int num1, int num2, int num3)
{
    if(num1>num2)
        if(num1>num3)
            return(num1);
        else
            return(num3);
    else
        if(num2>num3)
            return(num2);
        else
            return(num3);
}