/*Q3 - Program to use function with 3 parameters to find the highest*/
#include <stdio.h>
/*Declare function prototype*/
void highest_lowest(int, int, int);
main()
{
    int num1,num2,num3;
    printf("Enter the first number and hit enter:\n");
    scanf("%d", &num1);
    printf("Enter the second number and hit enter:\n");
    scanf("%d", &num2);
    printf("Enter the third number and hit enter:\n");
    scanf("%d", &num3);
    
     /*Call function highest_lowest()*/
    
    highest_lowest(num1, num2, num3);
    
    getchar();
    getchar();
    
}//End main

/*Implement highest_lowest()*/
void highest_lowest (int1, int2, int3)
{
    if (int1>int2)
    {
        if(int1>int3)
        {
            printf("\n\n%d is the biggest.\n\n",int1);
        }//End if
        else
        {
            printf("\n\n%d is the biggest.\n\n",int3);
        }//End else
    }
    else
    {
        if(int2>int3)
        {
            printf("\n\n%d is the biggest.\n\n",int2);
        }//End if
        else
        {
            printf("\n\n%d is the biggest.\n\n",int3);
        }//End else
    }//End else

    if (int1<int2)
    {
        if(int1<int3)
        {
            printf("%d is the smallest.",int1);
        }//End if
        else
        {
            printf("%d is the smallest.",int3);
        }//End else
    }
    else
    {
        if(int2<int3)
        {
            printf("%d is the smallest.", int2);
        }//End if
        else
        {
            printf("%d is the smallest.", int3);
        }//End else
    }//End else

}//End highest_lowest()