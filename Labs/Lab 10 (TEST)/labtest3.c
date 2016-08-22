/*Kieran Hogan
DT228 / 1
16/04/2013
Lab Test 3*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Declare structure template
struct information
{
    //All information required of the athletes
    char surname[21];
    char firstname[21];
    int dob_day;
    int dob_month;
    int dob_year;
    char nationality[21];
    char event[31];
    int weight_kg;
    int weight_lb;
    
};

//Declare function prototypes

void readData( struct information );
void readData2( struct information );
    
void calculateWeight( struct information );
void calculateWeight2( struct information );
    
void displayData( struct information );
void displayData2( struct information );


//Main of program
int main( void )
{
    
    //Assigns 2 athletes to structure
    struct information athlete_1, athlete_2;
    
    //Read athlete_1 info
    
    readData( athlete_1 );
    printf("\nEnter to continue.");
    getchar();

    //Display athlete_1 info
    displayData( athlete_1 );
    getchar();
    
    //Read athlete_2 info
    
    readData2( athlete_2 );
    printf("\nEnter to continue.");
    getchar();

    //Display athlete_2 info
    displayData2( athlete_2 );
    getchar();
    return 0;
    

}//end main


void readData( struct information athlete_1 )
{
    
    //Function: read athlete_1.
    
    printf("Please enter the following details for athlete_1:\n");
    printf("\nEnter firstname: ");
    gets(athlete_1.firstname);
    flushall();
    printf("\nEnter surname: ");
    gets(athlete_1.surname);
    flushall();
    printf("\nEnter date of birth - day: ");
    scanf("%d", &athlete_1.dob_day);
    flushall();
    printf("\nEnter date of birth - month: ");
    scanf("%d", &athlete_1.dob_month);
    flushall();
    printf("\nEnter date of birth - year: ");
    scanf("%d", &athlete_1.dob_year);
    flushall();
    printf("\nEnter nationality: ");
    gets(athlete_1.nationality);
    printf("\nEnter event: ");
    gets(athlete_1.event);
    flushall();
    printf("\nEnter weight in kg: ");
    scanf("%f", &athlete_1.weight_kg);
    flushall();
    
}//end readData (athlete_1)

void displayData( struct information athlete_1 )
{
    //Function: Display athlete_1
    
    printf("\nAthlete_1\n");
    printf("\nFirstname: %s", athlete_1.firstname);
    printf("\nSurname: %s", athlete_1.surname);
    printf("\nDOB: %d:%d:%d", athlete_1.dob_day, athlete_1.dob_month, athlete_1.dob_year);
    printf("\nNationality: %s", athlete_1.nationality);
    printf("\nEvent: %s", athlete_1.event);
    printf("\nWeight in kg: %f", athlete_1.weight_kg);
    
    calculateWeight( athlete_1 );
    flushall();
    
    printf("\n");

}//end displayData (athlete_1)

void calculateWeight( struct information athlete_1 )
{
    
    //Function: Calculate weight of athlete_1 from kg to lb
    
    float calc = .45;
    athlete_1.weight_lb = athlete_1.weight_kg/calc;
    printf("\n%f", athlete_1.weight_lb);
    
}//end calculateWeight (athlete_2)



void readData2( struct information athlete_2 )
{
    
    //Function: read athlete_2.
    
    printf("Please enter the following details for athlete_2:\n");
    printf("\nEnter firstname: ");
    gets(athlete_2.firstname);
    flushall();
    printf("\nEnter surname: ");
    gets(athlete_2.surname);
    flushall();
    printf("\nEnter date of birth - day: ");
    scanf("%d", &athlete_2.dob_day);
    flushall();
    printf("\nEnter date of birth - month: ");
    scanf("%d", &athlete_2.dob_month);
    flushall();
    printf("\nEnter date of birth - year: ");
    scanf("%d", &athlete_2.dob_year);
    flushall();
    printf("\nEnter nationality: ");
    gets(athlete_2.nationality);
    printf("\nEnter event: ");
    gets(athlete_2.event);
    flushall();
    printf("\nEnter weight in kg: ");
    scanf("%f", &athlete_2.weight_kg);
    flushall();
    
}//end readData2 (athlete_2)

void displayData2( struct information athlete_2 )
{
    //Function: Display athlete_1
    
    printf("\nAthlete_2\n");
    printf("\nFirstname: %s", athlete_2.firstname);
    printf("\nSurname: %s", athlete_2.surname);
    printf("\nDOB: %d:%d:%d", athlete_2.dob_day, athlete_2.dob_month, athlete_2.dob_year);
    printf("\nNationality: %s", athlete_2.nationality);
    printf("\nEvent: %s", athlete_2.event);
    printf("\nWeight in kg: %f", athlete_2.weight_kg);
    calculateWeight( athlete_2 );
    flushall();
    printf("\n");

}//end displayData2 (athlete_2)

void calculateWeight2( struct information athlete_2 )
{
    
    //Function: Calculate weight of athlete_2 from kg to lb
    float calc = .45;
    athlete_2.weight_lb = athlete_2.weight_kg/calc;
    printf("\n%f", athlete_2.weight_lb);
    
}//end calculateWeight2 (athlete_2)

