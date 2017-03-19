/*
 *	Program:Write the following functions which will toggle even bits 
 *			and odd bits respectively in a given number
 * 	    	a. Toggle even bit: int even_bit_toggle (int num);
 *	    	b. Toggle odd bit: int odd_bit_toggle (int num);
 *	
 *	Author:Pritam Krishna Mali.
*/
#include<stdio.h>
int toggle_even_bit(int); 
int toggle_odd_bit(int);

int main()
{
	int num = 0; 					/*USER INPUT: Number*/

	printf("\nEnter the Number:");
	num = atoimy();

	if(num >=0){
		show_bit(num);
		printf("\nEven Bit Toggle");
		toggle_even_bit(num);	
		printf("\nOdd Bit Toggle");
		toggle_odd_bit(num);
		printf("\n");
	}
	return 0;

}

int toggle_even_bit(int _num) /*Toggle Even bit*/
{
	int i;
	
	for(i = 0; i<=31; ){
		_num = _num ^ (1 << i);
		i = i+2;
	}
	show_bit(_num);
	printf("\n");
}
int toggle_odd_bit(int _num) /*Toggle odd Bit*/
{
	int i;
	
	for(i=1; i<=31; ){
		_num = _num ^ (1 << i);
		i = i+2;
	}
	
	show_bit(_num);
	printf("\n");
	

	return 0;
}
