/*	programe: Set a bit
	Author: Pritam mali.
	Date: 
	Description: This program will test and set a bit position in a number.
*/

#include<stdio.h>
#include<stdlib.h>

#define bit_ts(num,pos) (num | (1 << pos))

int main()
{
	unsigned int num;			/*USER INPUT : Number*/
	int pos;					/*USER INPUT : position*/

	printf("Enter a number:");
	num = atoimy();

	show_bit(num);

	printf("\n");

	printf("Enter the position of bit to set:");
	pos = atoimy();

	printf("Number after setting a bit at position %d:\n", pos);
	show_bit(bit_ts(num,pos));
	printf("\n");

	return 0;
}
