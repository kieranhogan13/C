/*Q9 - Use of strcmp() for comparing name to array of names
Kieran Hogan - DT228/1 - 12/03/13*/
#include <stdio.h>
#include <string.h>
int main (void)

{
	char enter_name[20];
	char *name_list[10] = {"Ciaran", "Michael", "Kieran", "Hogan", "Andy", "John", "Mary", "Ben", "Craig", "Mark"};
    printf("Enter your name: ");
    scanf("%s",enter_name);
    printf("\n\n");
    int i;
	for(i=0;i<10;i++)
	{
        if ( strcmp(enter_name, *name_list)==0)
        {	
            printf("Hello %s", name_list[i]);
            getchar();
        }
        else
        {
            printf("Name not found");
            getchar();
            getchar();
            return 0;
        }
	}
    getchar();
	flushall();
	return 0;
}