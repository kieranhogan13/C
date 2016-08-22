/*Q5 - Lab 09/04/2013 - on sheet
Kieran Hogan - DT228/1*/
#include <stdio.h>
#include <string.h>

/*Declare structure template*/
struct city_data
{
	char city_name[21];
    int city_population;
    int annual_rainfall;
    int annual_sunshine;
};

struct city_data city_1, city_2;

int main(void)
{
    /*Enter city_1s data*/
    printf("Please enter the following details for City_1:\n");
    printf("\nEnter the name of the city: ");
    gets(city_1.city_name);
    flushall();
    printf("\nEnter population: ");
    scanf("%f", &city_1.city_population);
    flushall();
    printf("\nEnter annual rainfall: ");
    scanf("%f", &city_1.annual_rainfall);
    flushall();
    printf("\nEnter annual sunshine: ");
    scanf("%f", &city_1.annual_sunshine);
    flushall();
    
    /*Enter city_2s data*/
    printf("Please enter the following details for City_2:\n");
    printf("\nEnter the name of the city: ");
    gets(city_2.city_name);
    flushall();
    printf("\nEnter population: ");
    scanf("%f", &city_2.city_population);
    flushall();
    printf("\nEnter annual rainfall: ");
    scanf("%f", &city_2.annual_rainfall);
    flushall();
    printf("\nEnter annual sunshine: ");
    scanf("%f", &city_2.annual_sunshine);
    flushall();
    
    
    printf("\nPress Enter to close");
    flushall();
	getchar();
	return 0;
    
}
    
