/*Chapter 10, Q1)
Kieran Hogan - DT228/1 - 05/03/2013*/
#include <stdio.h>
void main()
{
    //a)
    printf( "%5s" , "abcd" );
    printf( "\n\n" );
    //b)
    printf( "%5s" , "abcdef" );
    printf( "\n\n" );
    //c)
    printf( "%-5s" , "abc" );
    printf( "\n\n" );
    //d)
    printf( "%5.2s" , "abcde" );
    printf( "\n\n" );
    //e)
    printf( "%-5.2s" , "abcde" );
    flushall();
    getchar();
}