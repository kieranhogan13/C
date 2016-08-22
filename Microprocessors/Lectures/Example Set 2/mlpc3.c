#include <stdio.h>
// PRBS support
// It is possible to make a maximal length 31 bit prbs signal using a single tap at 
// bit 28.  This bit is xored with the carry out of bit 30 and fed back to LSB
// Reference Horowitz & Hill, The art of electronics
unsigned long shift_register = 0xaa9669aa;
int tap1 = 0;
int tap2 = 0;
inline void shift() {

  shift_register = shift_register << 1;
  if (shift_register & ((long)0x10000000L)) 
    tap1 = 1;
  else 
    tap1 = 0;
  if (shift_register & (long)0x80000000) 
    tap2 = 1;
  else 
    tap2 = 0;
  if (tap1 ^ tap2)
    shift_register |= 1;
}

int get_random_c() {
  shift();
  return (int) shift_register;
}

int main() {
	int i;
	//for (i=0;i<10;i++) {
	//	printf("%d %d\n",get_random_c(),get_random());
	//}
	for (i=0;i<20000000;i++)	
		get_random();
}
