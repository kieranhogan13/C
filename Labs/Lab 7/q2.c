/*Q11 - Use of strings to print capital city of country
Kieran Hogan - DT228/1 - 12/03/13*/
#include <stdio.h>
#include <string.h>
int main (void)

{
    char *country_list[10] = {"Australia", "Belgium", "China", "Denmark", "England", "France", "Greece", "Ireland", "Scotland", "Wales"};
    char *capital_list[] = {"Canberra", "Brussels", "Beijing", "Copenhagen", "London", "Paris", "Athens", "Dublin", "Edinburgh", "Cardiff"};
    char enter_country[15];
    int i;
    scanf("%s", enter_country);
    for(i=0;i<12;i++)
	{
		if ( strcmp(enter_country, country_list[i])==0)
        {
            printf("Country is here");
            getchar();
            getchar();
            return 0;
        }
        else
        {
            printf("Country not present: please enter another country");
            getchar();
            getchar();
            return 0;
        }
	}
    
    getchar();
	flushall();
	return 0;
}