/*Program that uses 2 or more parameters*/
#include <stdio.h>

/*Declare function prototype*/
void display (char, int);
main()
{
    char my_char;
    int num;
    printf("Enter a character\n");
    scanf("%1s", &my_char);
    printf("Enter a number\n");
    scanf("%d",&num);
    /*Call function display()*/
    display(my_char, num);
    getchar();
}//End main

/*Implement display()*/
void display (char new_char, int new_num)
{
    int i;
    for (i=0;i<new_num;i++)
    {
        printf("%c\n", new_char);
    }//End for
}//End display()