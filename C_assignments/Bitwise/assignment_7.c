/*
	programe : Write the following functions which will count the number of bits set and number of bits cleared
		   in the given number num respectively
			a. count_bit_set (int num);
			b. count_bit_clear (int num);
	Author : Pritam KRishna Mali.
*/

#include<stdio.h>

#if 0
int count_bit_set(int);

int main()
{
	int num = 0; 					//user input : number

	printf("\nEnter the Number:");
	num = atoimy();

	if(num >= 0){
		show_bit(num);
		printf("\n\nCount:%d\n",count_bit_set(num));
		printf("\n");
	}
	else
		printf("\n");	
	return 0;	
}
int count_bit_set(int _num) 		/* count set bits */
{
	int i = 8 * sizeof(void *);
	int count = 0;
	
	for(; i >= 0; i--)
		(_num & (1 << (i-1))) ? count++ : count ;
	return count; 	
}
#endif

#if 1
int count_bit_clear(int);

int main()
{
        int num = 0; // user input : number

        printf("\nEnter the Number:");
        num = atoimy();

        if(num >= 0){
                show_bit(num);
                printf("\n\n Count:%d \n", count_bit_clear(num));
                printf("\n");
        }
        else
                printf("\n");   
        return 0;       
}
int count_bit_clear(int _num) //count clear bits
{
        int i = 8 * sizeof(void *);
        int count = 0;
        
        for(; i > 0; i--)
                (_num & (1 << (i - 1))) ? count : count++ ;
        return count;   
}
#endif
