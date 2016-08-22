/*Q4 - Program to use 2 functions with 3 parameters to find the sum() and average()*/
#include <stdio.h>
/*Declare function prototypes(2 in this case)*/
void sum(int, int, int);
void average(int, int, int);
main()
{
    int num1,num2,num3;
    printf("Enter the first number and hit enter:\n");
    scanf("%d", &num1);
    printf("Enter the second number and hit enter:\n");
    scanf("%d", &num2);
    printf("Enter the third number and hit enter:\n");
    scanf("%d", &num3);
    
    /*Call function sum()*/
    
    sum(num1, num2, num3);
    
    /*Call function average()*/
    
    average(num1, num2, num3);
    
    getchar();
    getchar();
    
}//End main

/*Implement sum()*/
void sum (int1, int2, int3)

{
    int total = int1+int2+int3;
    printf("The sum of these numbers is %d.\n", total);
    
}//End average()


/*Implement average()*/
void average (int1, int2, int3)

{
    int total = int1+int2+int3;
    int mean = total/3;
    printf("The average of these numbers is %d.\n", mean);
    
}//End average()