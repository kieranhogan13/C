
#include "io430.h"

//masks
#define STATUS_LED_ON P1OUT &= ~BIT0    //STATUS_LED - P2.1
#define STATUS_LED_OFF P1OUT |= BIT0     //STATUS_LED - P2.1
#define FORWARD P1OUT &= 0xFE
#define REVERSE P1OUT &= 0xFD
#define FORWARDLEFT P1OUT &= 0xF6
#define FORWARDRIGHT P1OUT &= 0xFA
#define REVERSELEFT P1OUT &= 0xF5
#define REVERSERIGHT P1OUT &= 0XF9
#define STOP P1OUT = 0x0F

//functions
void forward (int);
void reverse (int);
void stop (int);
void left (int, int); //forward and left
void right (int, int); //forward and right
void SysInit();
void delay(long milliseconds); // delay for stated number of milliseconds
// Global variables here

// Main function
void main()
{

  
SysInit();
while(1) 

{ 
  
  // main control loop goes here
   delay(2);
  forward(1);
  left(1, 1);
  forward(1);
  left(1, 1);
  reverse(2);
  STOP;
}
}

void delay( long time )
{
  unsigned long i;
  int j;
  unsigned long second = 120000;
  
  for( j = 0; j < time; j++)
  {
    for( i = 0; i < second; i++ );
  }//end for
    
}//end delay

void forward( int time )
{
 
  FORWARD;
  
  delay( time );
  
  STOP;
  
}//end forward

void reverse( int time )
{
  REVERSE;
  
  delay( time );
  
  STOP;
}//end reverse

void left( int direction, int time )
{
  
  if (direction == 1)
    FORWARDLEFT;
    
    delay( time );
    
    STOP;

  
}//end left

void right( int direction, int time )
{
  
  if( direction == 1 )
  {
    FORWARDRIGHT;
    
    delay( time );
    
    STOP;
  }

  
}//end right


void stop( int time )
{
 
  STOP;
  
  delay( time );
  
  STOP;
  
}//end stop


void SysInit()
{
WDTCTL = WDTPW + WDTHOLD; // disable watchdog timer for debugging purposes.
// set chip running at 1MHz (factory calibrated)
DCOCTL = CALDCO_1MHZ;
BCSCTL1 = CALBC1_1MHZ;
// set up data direction registers etc. here
P1DIR = 0x0F;
P1OUT = 0X0F;
}