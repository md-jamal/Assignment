#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int atoi_1(char s[])
{
	int i;
	int n = 0;	

	for(i = 0; i < strlen(s); i++){
		if(((s[i] >= '0') && (s[i] <= '9')) || (s[0] == '-')){
			if(s[0] != '-')
				n = (10 * n) + (s[i] - '0');
		}
		else
		{
			printf("Invalid Input.....Plz Check");
			exit(0);
		}
	}
	if(s[0] == '-')
	{
		printf("\n%d\n",((~(n))+1));
		return ((~(n))+1);
	}
	else
	{
		return n;
	}
}


