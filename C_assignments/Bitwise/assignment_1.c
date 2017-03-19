/*
 *	Program : Bitwise Operation : Swap Bit.
 *	Author : Pritam Krishna Mali.
 *	Date : 10 NOV 2016.
 */


#include<stdio.h>
#include<stdlib.h>

int bit_swap(int, int, int); //Bit Swap function

int main()
{
	int dest_bit = 0; 				/* User Input : destination Bit  */
	int sorc_bit = 0; 				/* User Input :Sorc bit	*/
	int num = 0;      				/* User Input : value */
	
	printf("\nEnter the Number:");
	num = atoimy();
	 
	printf("\nEnter the Destination:");
	dest_bit = atoimy();
	
	printf("\nEnter the SourceL:");
	sorc_bit = atoimy();

	
	bit_swap(num, dest_bit, sorc_bit); /*Function Call*/

	return 0;
}

/*Bit Swap Function*/

int bit_swap(int a_num, int a_sorc_bit , int a_dest_bit) 
{
	int mask1 = 0; 			/* Masking Variable */
	int mask2 = 0;			/* Masking variable */
	
	show_bit(a_num);		
	printf("\n");
	
	mask1 = a_num & ( 1 << a_dest_bit );
	mask2 = a_num & ( 1 << a_sorc_bit );
	if(mask1 != mask2){
		a_num = a_num ^ (1 << a_sorc_bit);
		a_num = a_num ^ (1 << a_dest_bit);
	} 
	show_bit(a_num);

	printf("\n");
	
	return 0;
}
