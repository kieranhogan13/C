/*Chapter 10, Q3)
Kieran Hogan - DT228/1 - 05/03/2013*/
#include <stdio.h>
#include <string.h>
#define SIZE 9
void main()
{
    char *text= "some text" ;
    //a)
    printf( "%s", text );
    printf( "\n\n" );
    //b)
    printf( "%c\n", *text );
    printf( "\n\n" );
    //c)
    printf( "%c\n", *"more text" );
    printf( "\n\n" );
    //d)
    printf( "%c\n", *(text+1) );
    printf( "\n\n" );
    //e)
    printf( "%s", text+1 );
    printf( "\n\n" );
    //f)
    printf( text );
    printf( "\n\n" );
    //g)
    *( text+4 ) = '\0' ; printf( "\n%s\n", text );
    printf( "\n\n" );
    //h)
    printf( "%c", "text" [2] );
    printf( "\n\n" );
    //i)
    printf( "%s", "text" + 2 );
    flushall();
    getchar();
}