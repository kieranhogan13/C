
#include <msp430x14x.h>
#include "display.h"

// NOTE: THIS PROGRAM ONLY WORKS IF YOU PLUG OUT THE JTAG INTERFACE AFTER DOWNLOADING
// YOU MUST THEN SWITCH YOUR BOARD OFF AND ON.

long TimeCount=0;
void initTimer() {
  // set the timer going at a predictable rate. 
  CCTL0 = CCIE;
  TACTL = TASSEL_1 + MC_1 | TACLR; // source timer from ACLK, count up to CCR0 and clear TAR 
  CCR0 = 4000;  // This should create a 1kHz timebase
  _EINT();
  
}
#pragma vector=TIMERA0_VECTOR
__interrupt void OnTimerIRQ() {
 // This should happen at a rate of 10kHz.
 P2OUT ^= BIT0; // for debugging purposes, allows you to look at interrupt
  // rate on an oscilloscope.
  // Insert code here that will update the time variables in memory.
 TimeCount++;
}
void waitStart() {
  // wait until someone presses the start button
  while ( (P4IN & BIT7) );
}
void waitStartRelease() {
  // wait until someone releases the start button
  while ( (P4IN & BIT7)==0 );
}
void holdWeight() {
  P1OUT &= ~BIT5;
}
void dropWeight() {
  P1OUT |= BIT5;
}
int WeightArrived() {
  if (P4IN & BIT6)
    return 0;
  else
    return 1;
}
void displayGravity(long TimeCount) {
   printString("g X 100=");
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  initDisplay();
  clearDisplay();
  holdWeight();
  P2DIR |= BIT0; 
  P1DIR |= BIT5;
  while(1) {    
    printString("Press Start");   
    initTimer();
    waitStart();
    TimeCount =0;
    dropWeight();
    while(!WeightArrived()) {
      // wait for the weight to fall.
    }
    _DINT();  // disable further interrupts
    clearDisplay();
    displayGravity(TimeCount);      
    gotoSecondLine();
    printString("Start to repeat");
    waitStart();
    waitStartRelease();
    clearDisplay();
    holdWeight();
  }
    return 0;
    
}
