#include <msp430x14x.h>
void delay(int noise) {
int count;
for (count = 0; count < noise; count++);
}
void main() {
WDTCTL = WDTPW + WDTHOLD;
P4DIR=12;
while(1) {
  if(P4IN<241)
  P4OUT = 8;
  delay(P4IN);
  P4OUT = 4;
  delay(P4IN);

}
}