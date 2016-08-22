/*Q1 - Lab 19/03/2013 - pg 145 Q1
Kieran Hogan - DT228/1*/
#include <stdio.h>
#include <string.h>

/*Declare structure template a)*/
struct playing_card
{
	int card_number[13];
    char suit [5];
};


/*Declare structure template b)*/
struct stock_rec
{
	int stock_number;
	char description[21];
	int quantity;
};

/*Declare structure template c)*/
struct book_record
{
	char ISBN[14];
	char book_title[31];
    char author[26];
	float price;
};

/*Declare structure template d)*/
struct customer_record
{
	unsigned int customer_number;
	char name[26];
    char address[46];
	double outstanding_balance;
};

/*Declare structure template e)*/
struct transaction_record
{
	char transaction_type[1];
	int date_day;
    int date_month;
    int date_year;
    float transaction_amount;
};

/*Declare structure template f)*/
struct time_of_day
{
	char am_or_pm[2];
    int hour;
    int minutes;
    int seconds;
};

/*Declare structure template g)*/
struct co_ordinates
{
	int degrees;
    int minutes;
    char direction[1];
};

/*Declare structure template h)*/
struct league
{
	char team_name[21];
    int home_wins;
    int home_losses;
    int home_draws;
    int away_wins;
    int away_losses;
    int away_draws;
};
