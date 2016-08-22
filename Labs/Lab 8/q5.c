/*Q2 - Lab 19/03/2013 - pg146 - Q8
Kieran Hogan - DT228/1*/
#include <stdio.h>
#include <string.h>

/*Declare structure template*/
struct bio_data
{
	char firstname[21];
    char surname[21];
    int dob_day;
    int dob_month;
    int dob_year;
    float height;
    float weight;
    char eyecolour[15];
    char country_of_citizenship[21];
};

struct bio_data person_1, person_2;

int main(void)
{
    /*Enter person_1s data*/
    printf("Please enter the following details for Person_1:\n");
    printf("\nEnter firstname: ");
    gets(person_1.firstname);
    flushall();
    printf("\nEnter surname: ");
    gets(person_1.surname);
    flushall();
    printf("\nEnter date of birth - day: ");
    scanf("%d", &person_1.dob_day);
    flushall();
    printf("\nEnter date of birth - month: ");
    scanf("%d", &person_1.dob_month);
    flushall();
    printf("\nEnter date of birth - year: ");
    scanf("%d", &person_1.dob_year);
    flushall();
    printf("\nEnter height in cm: ");
    scanf("%f", &person_1.height);
    flushall();
    printf("\nEnter weight in kg: ");
    scanf("%f", &person_1.weight);
    flushall();
    printf("\nEnter eyecolour: ");
    gets(person_1.eyecolour);
    flushall();
    printf("\nEnter country of citizenship: ");
    gets(person_1.country_of_citizenship);
    
    

    /*Copy from person_1 to person_2*/
    strcpy(person_2.firstname, person_1.firstname);
    strcpy(person_2.surname, person_1.surname);
    person_2.dob_day = person_1.dob_day;
    person_2.dob_month = person_1.dob_month;
    person_2.dob_year = person_1.dob_year;
    person_2.height = person_1.height;
    person_2.weight = person_1.weight;
    strcpy(person_2.eyecolour, person_1.eyecolour);
    strcpy(person_2.country_of_citizenship, person_1.country_of_citizenship);



    /*Modify person_2s data*/
    printf("\nPlease enter the following details for Person_2:\n");
    printf("\nEnter firstname: ");
    gets(person_2.firstname);
    flushall();
    printf("\nEnter surname: ");
    gets(person_2.surname);
    flushall();
    printf("\nEnter date of birth - day: ");
    scanf("%d", &person_2.dob_day);
    flushall();
    printf("\nEnter date of birth - month: ");
    scanf("%d", &person_2.dob_month);
    flushall();
    printf("\nEnter date of birth - year: ");
    scanf("%d", &person_2.dob_year);
    flushall();
    printf("\nEnter height in cm: ");
    scanf("%f", &person_2.height);
    flushall();
    printf("\nEnter weight in kg: ");
    scanf("%f", &person_2.weight);
    flushall();
    printf("\nEnter eyecolour: ");
    gets(person_2.eyecolour);
    flushall();
    printf("\nEnter country of citizenship: ");
    gets(person_2.country_of_citizenship);


    /*Print person_1s data*/
    printf("\nPerson_1\n");
    printf("\nFirstname: %s", person_1.firstname);
    printf("\nSurname: %s", person_1.surname);
    printf("\nDOB: %d:%d:%d", person_1.dob_day, person_1.dob_month, person_1.dob_year);
    printf("\nHeight: %f", person_1.height);
    printf("\nWeight: %f", person_1.weight);
    printf("\nEyecolour: %s", person_1.eyecolour);
    printf("\nCountry of citizenship: %s", person_1.country_of_citizenship);
    printf("\n");
    
    /*Print modified person_2s data*/
    printf("\nPerson_2\n");
    printf("\nFirstname: %s", person_2.firstname);
    printf("\nSurname: %s", person_2.surname);
    printf("\nDOB: %d:%d:%d", person_2.dob_day, person_2.dob_month, person_2.dob_year);
    printf("\nHeight: %f", person_2.height);
    printf("\nWeight: %f", person_2.weight);
    printf("\nEyecolour: %s", person_2.eyecolour);
    printf("\nCountry of citizenship: %s", person_2.country_of_citizenship);

    printf("\nPress Enter to close");
    flushall();
	getchar();
	return 0;
}//end main