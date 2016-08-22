#include <msp430x14x.h>

//These #defines allow access to libraries for the debugger.

#define BTN1MASK 0x10
#define BTN2MASK 0x20
#define BTN3MASK 0x40
#define BTN4MASK 0x80
#define RLY1MASK 0x20
#define RLY2MASK 0x40
#define BUZZ1MASK 0x04
#define BUZZ2MASK 0x08


  //When button 1 is pressed
int Btn1Pressed()
{
  int Result;
  Result = P4IN & BTN1MASK;
  //Value of button 1 set
  if (Result == 0)
    return 1;
  else
    return 0;
}

  //When button 2 is pressed
int Btn2Pressed()
{
  int Result;
  Result = P4IN & BTN2MASK;
  //Value of button 2 set
  if (Result == 0)
    return 1;
  else
    return 0;
} 

//To extend the program to the last two buttons, the following code does so.

//When button 3 is pressed
int Btn3Pressed()
{
  int Result;
  Result = P4IN & BTN3MASK;
  //Value of button 3 set
  if (Result == 0)
    return 1;
  else
    return 0;
} 

//When button 4 is pressed
int Btn4Pressed()
{
  int Result;
  Result = P4IN & BTN4MASK;
  //Value of button 4 set
  if (Result == 0)
    return 1;
  else
    return 0;
} 
/*A relay is a simple electromechanical switch made up of an electromagnet and a set of contacts. 
Relays are found hidden in many devices. Some of the first computers ever built used relays to 
implement Boolean gates. Relays are most commonly used for amplifying digital signals. They can 
be used to detect and isolate faults. They can also be used for time delays. For example you 
could time your central heating in an industrial automation system. In this case the relays are
connected to the led.*/

void Relay1On() 
{
  P1OUT = P1OUT | RLY1MASK;
} 
void Relay1Off() 
{
  // "~" represents a bit wise NOT
  P1OUT = P1OUT & ~RLY1MASK;
} 

void Relay2On() 
{
  P1OUT = P1OUT | RLY2MASK;
} 
void Relay2Off() 
{
  // "~" represents a bit wise NOT
  P1OUT = P1OUT & ~RLY2MASK;
} 

void InitializeBoard() {

  P4DIR = BUZZ1MASK+BUZZ2MASK; // setup bits 2 and 3 on Port 4 as
// outputs to drive the buzzer

  P1DIR = RLY1MASK+RLY2MASK; // bits 5 and 6 on port 1 drive the
//relays
} 
// Function for delay()
void delay() 
{
  int dly;
  for (dly=0;dly<50;dly++);
} 
// Function for beep()
void Beep() 
  {
    int count;

    for (count = 0; count < 50; count ++) {

      P4OUT = BUZZ1MASK;

      delay();

      P4OUT = BUZZ2MASK;

      delay();
  }
P4OUT = 0;
} 
void main( void )
{
// Stop watchdog timer to prevent time out reset
WDTCTL = WDTPW + WDTHOLD;
InitializeBoard();
// While each button is pressed - Uses functions
while (1) 
  {
    //This allows the first buttons 1 & 2 to buzz and the 3 & 4 to light the led.
    
    /*if (Btn1Pressed())
      Beep();
    if (Btn2Pressed())
      Beep();
    if (Btn3Pressed())
      Relay1On();
    else
      Relay1Off();
    if (Btn4Pressed())
      Relay1On();
    else
      Relay1Off();*/
    
    //This allows the first buttons 1 & 2 to switch the led in relay 1 on and off
    //and 3 and 4 switches the relay 2 on and off.
    
    if (Btn1Pressed())
      Relay1On();
    if (Btn2Pressed())
      Relay1Off();
    
    if (Btn3Pressed())
      Relay2On();
    if (Btn4Pressed())
      Relay2Off();
  }
}