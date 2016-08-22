#include <intrinsics.h>
#include "io430.h"
#include "softuart.h"

// the following number allows you to introduce a predictable error rate
// If the value of ERROR_LEVEL is 100 then one bit in every 100 should be wrong
#define ERROR_LEVEL 2003

#define TX_PIN_HIGH (P1OUT |= 2)
#define TX_PIN_LOW (P1OUT &= 0xfd)

// Not using parity checking in this simple software UART.
byte TXBuffer;
typedef struct tagUARTStatus {

	byte Busy : 1;
	byte BitCounter : 4;	        

} UARTStatus;
volatile UARTStatus TXStatus;	
volatile unsigned int milliseconds=0;
unsigned int ticks=0;
unsigned int ErrorCounter=ERROR_LEVEL;
#pragma vector=TIMERA0_VECTOR
__interrupt void OnTimer(void)
{
  poll_UART();
  ticks++;
  if (ticks > 2) {
    milliseconds++; // approx 1 ms timebase.
    ticks=0;
  }
  if (milliseconds > 1000)
  {
    milliseconds = 0;
  }    
}
void initUART() {
        TX_PIN_HIGH;
        P1DIR |= 2;
	TXStatus.Busy = TXStatus.BitCounter = 0;
	TXBuffer = 0;
         // set up Timer A to manage the transmission of bits.
        TACTL = MC_1+TASSEL_2+TACLR;        
        TACCR0=417;// 1000000 / 2400 = 417 approx (needs tweaking in practice)
        TACCTL0 = CCIE;
        milliseconds = 0;
        __enable_interrupt();
        
}
void putc(char c) {
  
  int i;
  TXBuffer = c;
  TX_PIN_HIGH; 
  TXStatus.BitCounter = 10; // 1 start bit, 8 data bits and 1 stop bit        
  TACTL |= TACLR;
  TXStatus.Busy = 1;// This actually starts the transmission
  P1OUT |=BIT6; // show UART state
  while (TXStatus.Busy) {
  }    
  TX_PIN_HIGH; 
  delay(2);
  P1OUT &=~BIT6; // show UART state  
}   
void poll_UART() 
{      
	if (TXStatus.Busy) {          
          if (TXStatus.BitCounter==10) {
            // sending start bit           
            TXStatus.BitCounter--;	
            TX_PIN_LOW;
          }
	  else if (TXStatus.BitCounter > 1) {
            TXStatus.BitCounter--;	
            ErrorCounter--;
            if (ErrorCounter) {
              if ((TXBuffer & 1))
	        TX_PIN_HIGH;
    	      else
	        TX_PIN_LOW;
            }
            else {
              // deliberately send the wrong bit
              if ((TXBuffer & 1))
	        TX_PIN_LOW;
    	      else
	        TX_PIN_HIGH;
              ErrorCounter = ERROR_LEVEL;
            }
	    TXBuffer = TXBuffer >> 1;            	     			
	  } else {
			// send the stop bit
              TXStatus.BitCounter--;	
	      TX_PIN_HIGH;
	      TXStatus.Busy = 0;                       		
	    }		
    	  }	            
}
void TXString(char * s) {
  while(*s) {
    putc(*s++);   
    delay(2);
  }
}
void TXDecimal(int Number) {
  char c;
  c = ( Number / 10000)+48;
  putc(c);
  Number = Number % 10000; 
  
  c = ( (Number / 1000))+48;  
  putc(c);
  Number = Number % 1000; 
  
  c = ( (Number / 100))+48;
  putc(c);
  Number = Number % 100; 
  
  c = ( (Number / 10 ))+48;
  putc(c);
  Number = Number % 10; 
  
  c = ( (Number  ))+48;
  putc(c);
}
void TXHex(int Number) {
  char c;
  
  c = (Number >> 12) & 0x0f;
  if (c > 9)
    c = c+55;
  else
    c = c+48;
  putc(c);
  
  c = (Number >> 8) & 0x0f;
  if (c > 9)
    c = c+55;
  else
    c = c+48;
  putc(c);

  c = (Number >>4) & 0x0f;
  if (c > 9)
    c = c+55;
  else
    c = c+48;
  putc(c);
  
  c = (Number) & 0x0f;
  if (c > 9)
    c = c+55;
  else
    c = c+48;
  putc(c);
}
void delay(int millis) {  
 /* int i;
  while (millis--)
     for(i=0;i<100;i++);*/
  milliseconds = 0;
  while (milliseconds < millis);
}
