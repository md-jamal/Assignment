/*
 *	Programe:Write a function bit_copy (int snum, int dnum, int n, int s, int d) which copies n bits (right
 *		 adjusted) from bit position s in snum to bit position d in dnum.
 *	Author:=Pritam Krishna Mali.
 */

#include<stdio.h>
#include<math.h>

int bit_swap(int,int,int,int,int); //function for decimal to binary
int show_bit(int); 				   //function for swap

int main()
{
        int num1;					 //first number given as input 
        int num2;					 //second number given as input
		int no_bits; 					 //number of bits to be copied
        int src; 					 //the source position to be swapped
        int dest;					 // the destination psition to be swapped

        printf("enter the first number");
        num1 = atoimy();

        printf("enter the second number");
        num2 = atoimy();
	
		printf("enter the number of bits to copy");
		no_bits = atoimy();

        printf("enter the source number");
        src = atoimy();

        printf("enter the destination number");
        dest = atoimy();

		if(num1 >=0 && num2 >=0 && no_bits > 0 && src > 0 && dest > 0){
        	show_bit(num1);
		printf("\n");
        	show_bit(num2);
		printf("\n");
        	bit_swap(num1,num2,no_bits,src,dest);
		}
		else
			printf("\nYour Input Is Wrong Please Check\n\n");
        return 0;
}	

/*Bit Swap Function*/

int bit_swap(int n1,int n2, int nb, int src, int dest)
{
    int b1;

    b1 = ( n1 >> (src-nb) ) & (~ ((~0) <<nb));
    n2 =n2 & ( ~ ( ( ~ (  (~0) << nb ) ) << (dest-nb) ) );
    n2 = n2 | (b1 << (dest-nb)); 

	show_bit(n2);
	printf("\n");
	return 0;
}   
