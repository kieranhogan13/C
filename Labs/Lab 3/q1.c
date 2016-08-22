/*Q1 - Program to check if a number is even or odd by returning value from a function*/
#include <stdio.h>
/*Declare function prototypes*/
int odd_even (int);
main()
{
    int x;
    int result;
 
    printf("Input a number to see if its odd or even:\n");
    scanf("%d",&x);
    
    /*Call function*/
    result = odd_even(x);
    if(result==1)
        printf("Even");
    else
        printf("Odd");
    
    flushall();
    getchar();
}    
    /*Implent funcion*/
int odd_even (int num)
{
    if(num%2==0)
        return (1);
    else
        return (0);
}