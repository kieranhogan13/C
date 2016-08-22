/*Q2 - Lab 09/04/2013 - on sheet
Kieran Hogan - DT228/1*/
#include <stdio.h>
#include <string.h>

/*Declare structure template*/
struct airline
{
	char airline_name[21];
    int flight_number;
	char passenger_surname[21];
    int seat_number;
    char destination[21];
	int number_of_bags;
};

struct airline passenger1, passenger2, passenger3;

int main(void)
{
    printf("Enter Passenger 1 Information\n\n");
    
    printf("Enter the airline name: ");
    gets(passenger1.airline_name);
    flushall();
    
    printf("\nEnter the flight number: ");
    scanf("%d", &passenger1.flight_number);
    flushall();
    
    printf("\nEnter the passengers surname: ");
    gets(passenger1.passenger_surname);
    flushall();
    
    printf("\nEnter the seat number: ");
    scanf("%d", &passenger1.seat_number);
    flushall();
    
    printf("\nEnter the destination: ");
    gets(passenger1.destination);
    flushall();
    
    printf("\nEnter the number of bags: ");
    scanf("%d", &passenger1.number_of_bags);
    flushall();

    /*Display passenger details*/
    printf("\nPassenger 1 Information\n\n");
	printf("Airline: %s", passenger1.airline_name);
	printf("\nFlight Number: %d", passenger1.flight_number);
	printf("\nPassenger Surname: %s", passenger1.passenger_surname);
	printf("\nSeat Number: %d\n", passenger1.seat_number);
    printf("\nDestination: %s", passenger1.destination);
    printf("\nBags: %d\n", passenger1.number_of_bags);

	flushall();
	getchar();
	return 0;
}//end main