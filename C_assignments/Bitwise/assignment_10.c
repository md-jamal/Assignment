/*
	Programe : Write a function setbits (x,p,n,y) that returns x with 
			   the ‘n’ bits that begin at position p set to the	right 
			   most n bits of y, leaving the other bits unchanged.
	Author   : Pritam Mali
*/


#include<stdio.h>
int setbits(int, int,int,int);

int main()
{

	int num_1;						/*USER Input : Number */
	int num_2;						/*USER Input : Number */
	int no;							/*USER INPUT : No Of Bits*/
	int pos;						/*USER INPUT : Bit Position*/

	printf("Enter the number=");
	num_1 = atoimy();

	show_bit(num_1);
	printf("\n");
	printf("enter the second number=");
	num_2 = atoimy();

	show_bit(num_2);
	printf("\n");

	printf("Enter the position=");
	pos = atoimy();
	printf("\n");
	
	printf("Enter the no of Bits=");
	no = atoimy();
	setbits(num_1, pos, no, num_2);
	printf("\n");
	return 0;
}

int setbits(int x,int p,int n,int y)
{
	x = (x & (( ~ (~0 << n)) << (p + 1 - n)) >> (p + 1 - n));
	y = y & (~0 << n);
	y = x | y;

	printf("the number y after replacement =");
	show_bit(y);
	return 0;
}
