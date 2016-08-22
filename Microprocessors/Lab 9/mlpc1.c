// mlpc1.c
// C language source file for mixed language programming example
#include <stdio.h>


void UpperCase(char *Str);

int main() {
	char UserString[20];
	fputs("Enter a string: ",stdout);
	fgets(UserString,19,stdin);
	fputs("\nYou entered: ",stdout);
	fputs(UserString,stdout);	
	fputs("\nAfter call to UpperCase this becomes: ",stdout);
	UpperCase(UserString);
	fputs(UserString,stdout);	
	fputs("\n",stdout);
}
