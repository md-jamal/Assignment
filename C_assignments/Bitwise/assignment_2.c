/*
	program :Given the bit position s in number snum and the bit position d 
			  in number dnum, swap bit values between s and d.
	Author   :Pritam Krishna Mali. 
*/
#include<stdio.h>

int swapBits(unsigned int, unsigned int m, unsigned int, unsigned int); /*Swap Bit*/
int main()                                                                      
{                                                                               
    int res =  swapBits(10, 11, 0, 3);                                          
    return 0;                                                                   
}

int swapBits(unsigned int n, unsigned int m , unsigned int p1, unsigned int p2) 
{
    unsigned int bit1 =  (1 << p1) & n; // mask variable

    unsigned int bit2 =  (1 << p2) & m; // mask variable
 
    if(bit1 != bit2){
		n = n ^ (1 << p1);
		m = m ^ (1 << p2);
    }
 
    show_bit(n);
    printf("\n");
    show_bit(m);
    printf("\n");
    
    return 0;
}

