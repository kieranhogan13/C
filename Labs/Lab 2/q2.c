/*Q2 - Program to use function with 2 parameters*/
#include <stdio.h>
/*Declare function prototype*/
void action(char, int);
main()
{
    char my_char;
    int my_num;
    printf("Enter a character\n");
    scanf("%1s", &my_char);
    printf("Enter a number\n");
    scanf("%d",&my_num);
    printf("See function below:\n\n");
    /*Call function action()*/
    action(my_char, my_num);
    printf("\n\nSee function above:");
    getchar();
}//End main

/*Implement action()*/
void action (char new_char, int new_num)
{
    int i;
    for (i=0;i<new_num;i++)
    {
        printf("%c\n", new_char);
    }//End for
}//End action()