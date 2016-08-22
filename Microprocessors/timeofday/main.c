#include <msp430x14x.h>
#include "display.h"
int counter = 0;
int seconds;
int minutes;
int hours;
int i;
int j;
int k;

void delay(long amount) 
{
  while(amount--);
}

void printTime(int hours, int minutes, int seconds) 
{
  char DecimalBuffer [2];
    DecimalBuffer[0] = (hours%10)+'0';
  DecimalBuffer[1] = (hours / 10)+'0';
 DecimalBuffer[2] = ':';
  DecimalBuffer[3] = (minutes%10)+'0';
  DecimalBuffer[4] = (minutes / 10)+'0';
 DecimalBuffer[5] = ':';
  DecimalBuffer[6] = (seconds%10)+'0';
  DecimalBuffer[7] = (seconds / 10)+'0';
  printString(DecimalBuffer);
}

void main( void )
{
// Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  initDisplay();
  clearDisplay();
  printString("Hello Masters");

  while(1) 
  {
  {    
  // insert code here to periodically update the display and update global
  // variables that count seconds, minutes and hours.
  // Suggestion: update the display each time the number of seconds changes.
  // You will need to 'calibrate' the delay loop.
    for (k=0; k<60; k++)
{
	for (j=0;j<60;j++)
	{
		for (i=0;i<60;i++)
		{
			clearDisplay();
                        delay(65535);
			seconds = i;
			
		}
		minutes=j;
	}
	hours=k;
}

  
    
    delay(65535); //this controls rate of counter, 65535 is maximum value of 16bit counter
    counter++;
    printTime(hours, minutes, seconds);
    clearDisplay();
    printDecimal(counter);
  }
  }
}