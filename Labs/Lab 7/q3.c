/*Q2 - Write a program that reads a sentence from the keyboard and uses separate functions
to do the following:
a) Determines the frequency of the word “is” in the sentence (ensure the string
contains at least 1 occurrence of this word).
b) Calculates the number of characters in the sentence.
c) Appends the sentence to the end of the following string: “My sentence is : “
Kieran Hogan - DT228/1 - 12/03/13*/
#include <stdio.h>
#include <string.h>
int main (void)

{
    printf("Please enter a sentence: ");
    char sentence[50];
    gets(sentence);
    
    getchar();
    printf("\nYou entered this sentence: %s", sentence);
    
    getchar();
    printf ( "\nThe sentence is %u characters long\n", strlen( sentence ) );

    char start[] = "My sentence is : ";
	strcat(start,sentence);
    printf("\n%s", sentence);
    getchar();
    printf("\n%s", start);
	flushall();
	return 0;
    
    
    getchar();
    flushall();
    return 0;
}