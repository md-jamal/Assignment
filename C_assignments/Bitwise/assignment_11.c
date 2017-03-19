/* 
	Program : function invert (x,p,n) that returns x with n bits that 
			  begin at position p inverted, leaving others unchanged.
	Author :Pritam Krishna Mali. 
*/
#include<stdio.h>	

#if 1
int invert(int, int, int);
int main()
{
    int num; 						//User Input
    int i = 0; 						//Simple Variable for loop
	int pos = 0; 					//User Input : Destination Position
	int n = 0; 						//User Input : Source Position
  

    printf("\nEnter the Number:");
    num = atoimy();
	
	printf("\nEnter the Position:");
	pos = atoimy();
	
	printf("\nEnter the Bits");
	n = atoimy();

    if (num>=0) {     
		show_bit(invert(num , pos , n ));		
		printf("\n");
	}
}

int invert(int x, int p, int n)
{
	int num;
	num = (~(~0 << n)) << ((p+1)-n);
	show_bit(num);
	printf("\n");
	return  num ^ x;
}
#endif


