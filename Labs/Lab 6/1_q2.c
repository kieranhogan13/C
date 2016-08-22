/*Chapter 10, Q2)
Kieran Hogan - DT228/1 - 05/03/2013*/
#include <stdio.h>
#include <string.h>
#define SIZE 7
void main()
{
    char name[SIZE] = {'R','o','b','e','r','t','\0'};
    //a)
    puts( name );
    printf( "\n\n" );
    //b)
    scanf( "%s", name );
    printf( "%s\n", name );
    printf( "\n\n" );
    //c)
    strcpy( name, "Philip" );
    printf( "%s\n", name );
    printf( "\n\n" );
    //d)
    *( name+5 ) = 'a' ;
    printf( "%s\n", name );
    //e)
    strcpy( name, "Philip" );
    printf( "%s\n", name );
    flushall();
    getchar();
}