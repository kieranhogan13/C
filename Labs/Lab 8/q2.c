/*Q1 - Lab 19/03/2013 - pg145 - Q3
Kieran Hogan - DT228/1*/
#include <stdio.h>
#include <string.h>

/*Declare structure template*/
struct stock_record
{
	int no;
    char description[21];
    float price;
    int qty;
};

struct stock_record stock_item;

int main(void)
{
//a)
    printf("Enter a stock number: ");
    scanf("%d", &stock_item.no);
    flushall();
    
    printf("\nEnter a stock item description: )");
    gets(stock_item.description);
    
    printf("\nEnter a stock item price: )");
    scanf("%f", &stock_item.price);
    flushall();
    
    printf("\nEnter a stock item qty: )");
    scanf("%d", &stock_item.qty);
    flushall();

    /*Display stock_item details*/
	printf("Stock number is: %d", stock_item.no);
	printf("\nStock item description is: %s", stock_item.description);
	printf("\nStock item price is: %f", stock_item.price);
	printf("\nStock item qty is: %d\n", stock_item.qty);

	flushall();
	getchar();
	return 0;
}//end main