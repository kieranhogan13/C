/* This program continuously reads the status of a PS2
   controller pad.  It display the pad status on the LCD
   display (you need to include display.c in your project).
   It is not optimized in any way - just a proof of concept
   which may be useful for other projects.  Perhaps one of
   the serial interfaces on the MSP could have been used but
   this approach was not taken.  Instead, a serial interface
   was implemented using PORT6 and some code.
*/
#include <msp430x14x.h>
#include "display.h"

typedef unsigned char byte;
/* The controller is wired to Port 6 (labelled as
   analogue inputs on the EasyWeb 2 board.)  The
   board also has an 3.6V supply that can power
   the controller (It is to be found along with a
   GND (0V) connection on the same header as Port6/Analogue in)
*/
/*
   9 pin Sony Playstation special connector layout,
   looking at the plug, pins facing, rounded corners
   down i.e.
*/
//    ____________________
//   | 1 2 3 4 5 6 7 8 9 |	
//   \___________________/	
//

// 	Pin 	Name 	Description
//	1	   DATA	Data	       P6IN, Bit 0
//	2	   CMD	Command        P6OUT, Bit 1
//	3 	   N/C   (9 V unused)  Not connected
//	4 	   GND	Ground
//	5	   VCC	Vcc	       Connected to 3.6V supply on EasyWeb2
//	6	   ATT	ATT select     P6OUT, Bit 2
//	7	   CLK	Clock	       P6OUT, Bit 3
//	8	   N/C	Not connected
//	9	   ACK	Acknowledge    P6IN, Bit 4




/* Some handy macros for controlling the "serial" port. */
#define OUTPORT P6OUT
#define INPORT P6IN
#define SELPORT P6SEL
#define DIRPORT P6DIR
#define CLK_HI OUTPORT = OUTPORT | 8
#define CLK_LO OUTPORT = OUTPORT & 0xf7
#define CMD_HI OUTPORT = OUTPORT | 2
#define CMD_LO OUTPORT = OUTPORT & 0xfd
#define ATT_HI OUTPORT = OUTPORT | 4
#define ATT_LO OUTPORT = OUTPORT & 0xfb
#define IS_DATA_HI ( (INPORT & 0x1) > 0)
#define IS_DATA_LO !DATA_LO
#define IS_ACK_HI  ((INPORT & 0x10) > 0)
#define IS_ACK_LO  !IS_ACK_HI
/* Globals */
byte status;
byte controller_id;
long dly_counter;
byte controller_data[10];

void bit_delay() {
// Inter-bit delay to allow signals stabilize
// Not really calibrated - just tried it and it worked
  int i;
  for (i=0;i<50;i++) {
  }
}
void byte_delay() {
// Inter-byte delay to allow controller catch up.
// Not really calibrated - just tried it and it worked
  int i;
  for (i=0;i<20000;i++) {
  }
}
byte exchange_byte(byte output) {
// write the supplied byte to the controller
// returns the byte the controller
  byte input;
  byte input_mask;
  int bit_counter;
  input = 0;
  bit_delay();
  input_mask = 0x1;
  for (bit_counter = 0; bit_counter < 8; bit_counter++) {
    if (output & 1)
      CMD_HI;
    else
      CMD_LO;
    output = output >> 1;
    CLK_LO;
    bit_delay();

    if (IS_DATA_HI)
      input = input | input_mask;
    input_mask = input_mask << 1;
    CLK_HI;
    bit_delay();
  }
  CMD_HI;
  CLK_HI;
  return input;
}
int GetControllerStatus() {
/* read 10 bytes from the controller */
    ATT_LO;
//  The command sequence 01,42 causes the controller to identify itself
//  and send back status information.
    controller_data[0] = exchange_byte(0x01);
    byte_delay();
    controller_data[1] = exchange_byte(0x42);
    byte_delay();
    controller_data[2] = exchange_byte(0x0);
    byte_delay();
    controller_data[3] = exchange_byte(0x0);
    byte_delay();
    controller_data[4] = exchange_byte(0x0);
    byte_delay();
    controller_data[5] = exchange_byte(0x0);
    byte_delay();
    controller_data[6] = exchange_byte(0x0);
    byte_delay();
    controller_data[7] = exchange_byte(0x0);
    byte_delay();
    controller_data[8] = exchange_byte(0x0);
    byte_delay();
    controller_data[9] = exchange_byte(0x0);
    ATT_HI;
}
int main()
{
  WDTCTL = WDTPW + WDTHOLD;
  initDisplay();
  SELPORT = 0; // turn off special functions
  DIRPORT = 0x0e; // outputs on bits 1,2,3 - rest are inputs.

  CLK_HI;
  ATT_HI;
  CMD_HI;
  printString("PS2 Contoller Test");
  for (dly_counter = 0; dly_counter < 10000; dly_counter++);

  for (;;) { // loop forever
    GetControllerStatus();
    clearDisplay();
    printString(" ");
    printByte(controller_data[0]);
    printString(" ");
    printByte(controller_data[1]);
    printString(" ");
    printByte(controller_data[2]);
    printString(" ");
    printByte(controller_data[3]);
    printString(" ");
    printByte(controller_data[4]);
    printString(" ");
    printByte(controller_data[5]);
    gotoSecondLine();
    printByte(controller_data[6]);
    printString(" ");
    printByte(controller_data[7]);
    printString(" ");
    printByte(controller_data[8]);
    printString(" ");
    printByte(controller_data[9]);
    // A delay to allow the display to persist for a while
    for (dly_counter = 0;dly_counter < 1000; dly_counter++);
  }
  return 0;
}
