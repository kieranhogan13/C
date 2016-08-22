/*Chapter 10, Q5)
Kieran Hogan - DT228/1 - 05/03/2013*/
#include <stdio.h>
#include <string.h>
void main()
{
    //a)
    char *q = "abcd";
    while ( *q )
        putchar( *q++ );
    
    getchar();
    getchar();
    
    //b)
    char *text = "abcd";
    char *p = text;
    p += strlen( p )-1;
    while ( text <= p )
        puts( p--);
    
    
    flushall();
    getchar();
}