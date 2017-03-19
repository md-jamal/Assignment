/*
	Program : Write a macro getbits (x,p,n) that retuns (left adjusted) 
			   n-bit field of x that begins at position p.
	Author 	 : Pritam Krishna Mali.
*/
#include<stdio.h>
#define getbit(x, p , n) ~(~0 << n) << ((p+1)-n)

int main()
{
	int num;						//USER INPUT : Number 
	int pos;						//USER INPUT : position
	int n;							//USER INPUT : N bits
		
	printf("\nEnter the Number:");
	num = atoimy();

	
	printf("\nEnter the Position:");
	pos = atoimy();
	
	
	printf("\nEnter the Number:");
	n = atoimy();

	show_bit(getbit(num, pos, n));

	printf("\n");
	return 0;
}
