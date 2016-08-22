/*Chapter 10, Q6)
Kieran Hogan - DT228/1 - 05/03/2013*/
#include <stdio.h>
#include <string.h>
#define SIZE 50
void main()
{
    int i = 0;
    int j = 0;
    int count = 15;    
    char name[SIZE], new_name[SIZE];
    printf("Please enter your first name: ");
    
    gets(name);
    printf("\n");
    
    puts(name);
    printf("\n");
    
    getchar();
    
    for(i = 0; i<count; i++)
    {
        new_name[j]=name[i];
        j++;
        new_name[j] = ' ';
        j++;
    }
    
    puts(new_name);
    
    flushall();
    getchar();
}