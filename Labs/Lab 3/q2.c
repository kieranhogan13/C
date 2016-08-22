/*Q2 - Program to use a function to find the average of 3 numbers and return the value*/
#include <stdio.h>
/*Declare function prototypes*/
int average (int, int, int);
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
    result = average(a,b,c);
    printf("\nThe average is %d.\n", result);
    
    flushall();
    getchar();
}    
    /*Implent funcion*/
int average (int num1, int num2, int num3)
{
    int add = num1 + num2 + num3;
    int avg = add/3;
    return(avg);
}