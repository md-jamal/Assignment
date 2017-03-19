//swap from source to destination in same number
//B.G.JayaSri
//10-11-2016
#include<stdio.h>
#include<math.h>

int bit_swap(int,int,int,int,int); //function for decimal to binary
extern int show_bits(int); //function for swap

int main()
{
        int n1; //first number given as input 
        int n2; //second number given as input
	int nb; //number of bits to be copied
        int src; //the source position to be swapped
        int dest; // the destination psition to be swapped

        printf("enter the first number");
        scanf("%d",&n1);

        printf("enter the second number");
        scanf("%d",&n2);
	
	printf("enter the number of bits to copy");
	scanf("%d",&nb);

        printf("enter the source number");
        scanf("%d",&src);

        printf("enter the destination number");
        scanf("%d",&dest);

        show_bits(n1);
        show_bits(n2);
        bit_swap(n1,n2,nb,src,dest);
        return 0;
}

int bit_swap(int n1,int n2, int nb, int src, int dest)
{
        int b1;

        b1 = ( n1 >> (src-nb) ) & (~ ((~0) <<nb));
        n2 =n2 & ( ~ ( ( ~ (  (~0) << nb ) ) << (dest-nb) ) );
        n2 = n2 | (b1 << (dest-nb)); 
	show_bits(n2);
	return 0;
}   
