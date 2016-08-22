/*Q2 - Lab 19/03/2013 - pg146 - Q7
Kieran Hogan - DT228/1*/
#include <stdio.h>
#include <string.h>

/*Declare structure template*/
struct time_rec
{
	int hours;
    int mins;
    int seconds;
};

struct time_rec current_time;

int main(void)
{
    printf("Enter hours: ");
    scanf("%d", &current_time.hours);
    flushall();
    
    printf("\nEnter mins: ");
    scanf("%d", &current_time.mins);
    flushall();
    
    printf("\nEnter seconds: ");
    scanf("%d", &current_time.seconds);
    flushall();
    
    current_time.seconds++;
    
    printf("\nThe values in current_time are: %d:%d:%d", current_time.hours, current_time.mins, current_time.seconds);
    
    flushall();
	getchar();
	return 0;
}//end main