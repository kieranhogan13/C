#include <stdlib.h>
void copymem(char *src, char *dest, int count);
void copymem_c(char *src, char *dest, int count) {
	while(count--) 
		*dest++=*src++;
}
int main() {
	int i;
	char s1[]="abcdefghijklmnopqrstuvwxyz";
	char s2[30];
	char *s3;
	char *s4;
	s3=(char *)malloc(10000);
	s4=(char *)malloc(10000);
	for(i=0;i<100000;i++)	
		copymem(s3,s4,10000);
	return(0);

}