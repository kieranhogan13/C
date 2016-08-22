/* Q4 Lab - Strings
Kieran Hogan - DT228/1 - 05/03/2013*/
#include <stdio.h>
#include <string.h>
#define SIZE 10
int main(void)
{
    char my_word_1[SIZE] = {'k','e','y','b','o','a','r','d','\0'};
    printf("%s\n", my_word_1);
    puts(my_word_1);
    char my_word_2[SIZE] = "piano";
    printf("\n%s\n", my_word_2);
    puts(my_word_2);
    flushall();
    getchar();
    return 0;
    
}