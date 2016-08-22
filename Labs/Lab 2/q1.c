/*Q1 - Program to use function to print stars*/
#include <stdio.h>
/*Declare function prototype*/
void star(void);
main()
{
    printf("See function below:\n\n");
    /*Call function star*/
    star();
    printf("\n\nSee function above:");
    getchar();
}
//End main

void star (void)
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("* ",i);
    }//End for()
}//End star()