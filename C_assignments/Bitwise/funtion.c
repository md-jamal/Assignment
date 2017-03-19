#include<stdio.h>
/* Show The bit in 31BIT Format */
int show_bit(int a_no)
{
	int i = 0;
		
	for(i=31; i>=0; i--)
	{
		printf("%d",(1 & (a_no >> i)));
	}
	return 0;
}
/*to convert char to int*/
int atoi(char s[])
{
	int i = 0;
	int n = 0;	
	
	for (i=0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n +(s[i] - '0');
	return n;
}

