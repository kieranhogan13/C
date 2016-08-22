#include <stdio.h>
char hexdigit(unsigned int nibble) 
{
	if ( (nibble >=0) && (nibble < 10) )
		return nibble + 48;
	else if ( (nibble >=10) && (nibble < 16) )
		return nibble + 55;
	else
		return '?';
}
void Int2HexString(unsigned int Value, char *HexString) 
{
	// assumes that the string is big enough to receive the digits
	// assumes 32 bit integers
	// 32 bit hex string has 8 hex digits (index 0 to 7 inclusive)
	// need space for a terminating null also
	int i;
	for (i=7; i>=0; i--) {
		HexString[i]=hexdigit(Value & 0xf);	
		Value = Value >> 4; 
	}
	HexString[8]=0;
}
void Int2DecimalString(int Value, char *DecimalString) 
{
	// assumes that the string is big enough to receive the digits
	// assumes 32 bit integers
	// 32 bit decimal number can have 10 digits plus a sign
	// need space for a terminating null also

	int i;
	if (Value > 0)
		DecimalString[0] = '+';
	else {
	// Value is negative so put minus sign in string
		DecimalString[0] = '-';
	// Have taken sign into account, pretend number is positive now
		Value = -Value;		
	}
	for (i=10; i>0; i--) {
		DecimalString[i]=(Value % 10) + 48;
		Value = Value / 10; 
	}
	DecimalString[11]=0; // terminate the string
}

int hexval(char c) {
	if ( (c >= '0') && (c <='9') )
		return c-48;
	else if ( (c >= 'A') && (c <='F') )
		return c-55;
	else
		return 0;
}
int FixedHexStringToInteger(char *String)
{
	// assumes a fixed length 8 digit hex string
	int Value=0;
	int i;
	for (i=0;i<8;i++) {
		Value = Value * 16;
		Value = Value + hexval(String[i]);
	}
	return Value;
}

int FixedDecimalStringToInteger(char *String)
{
	// assumes a fixed length 10 digit unsigned decimal string
	int Value=0;
	int i;
	for (i=0;i<10;i++) {
		Value = Value * 10;
		Value = Value + String[i]-48;
	}
	return Value;
}

int main() 
{
	char HexString[10];
	char DecimalString[12];
	int Value;
	Int2HexString(0x1234abcd,HexString);
	printf("Testing Int2HexString(0x1234abcd): Result %s\n",HexString);
	Int2DecimalString(1234567890,DecimalString);
	printf("Testing Int2DecString(1234567890): Result %s\n",DecimalString);
 	Value = FixedHexStringToInteger("1234ABCD");
	printf("Testing FixedHexStringToInteger(\"1234ABCD\"): Result %d\n",Value);
 	Value = FixedDecimalStringToInteger("1234567890");
	printf("Testing FixedDecimalStringToInteger(\"1234567890\"): Result %d\n",Value);

}
