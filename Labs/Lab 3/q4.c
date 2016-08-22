/*Q4 - Program to use a function to find the most common character of 3 characters entered*/
#include <stdio.h>
/*Declare function prototypes*/
int most_common (char, char, char, char, char);
main()
{
    char c1, c2, c3, c4, c5;
    int result;
 
    printf("Input character c1:\n");
    scanf("%c",&c1);
    printf("Input character c2:\n");
    scanf("%c",&c2);
    printf("Input character c3:\n");
    scanf("%c",&c3);
    printf("Input character c4:\n");
    scanf("%c",&c4);
    printf("Input character c5:\n");
    scanf("%c",&c5);
    
    /*Call function*/
    result = most_common(c1,c2,c3,c4,c5);
    printf("\nThe most commonly used character is %c.\n", result);
    
    flushall();
    getchar();
}    
    /*Implent funcion*/
int most_common (char letter1, char letter2, char letter3, char letter4, char letter5)
{
    
    ????
}