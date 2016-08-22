
#include "io430.h"
#include "softuart.h"
// NOTE: Hardware UART is not available in msp430G2231


void SysInit() {
  // initialize the clock system 
  // Set clock to run at 1MHz
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
  IFG1 &= ~2;
} 
void InitADC()
{
  ADC10CTL0=0;
  ADC10CTL0=ADC10ON+REFON+REF2_5V+ADC10SHT_3+SREF_1;
  ADC10CTL1=INCH_10+ADC10SSEL_2;
  ADC10CTL0 |= ENC;
}
int ReadTemperature()
{
  ADC10CTL0 |= ADC10SC;
  while((ADC10CTL1 & ADC10BUSY)!=0);
  long Temp=ADC10MEM;  
  return Temp;
}
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  int i;
  SysInit();
  initUART();  
  InitADC();
  P1DIR |= BIT6;
  i = 0;
  while(1) {
    TXString("Temperature: ");
    TXDecimal(ReadTemperature());
    TXString("\r\n");
    delay(200);
  }
  return 0;
}