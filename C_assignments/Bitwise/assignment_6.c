/*
	programe:Write the following functions
		a. unsigned int left_rotate_bits (unsigned int num);
			which will return the number, resulted by left rotating the number 
		b.unsigned int right_rotate_bits (unsigned int num);
			which will return the number, resulted by right rotating the number num
		c. unsigned int left_rotate_n_bits (unsigned int num, int n);
			which will return the number, resulted by left rotating the number num by n bits
		d. unsigned int right_rotate_n_bits (unsigned int num, int n);
			which will return the number, resulted by right rotating the number num by n bitsum	
		 
	Author:Pritam Krishna Mali.
*/

#include<stdio.h>

#if 1 

unsigned int left_rotate_bits(unsigned int); 
int i = 8 * sizeof(void *);

int main()
{
	unsigned int num; /*user input : Number */
	
	printf("\nEnter the Number:");
	num = atoimy();

	if(num >=0){	
		show_bit(left_rotate_bits(num));
		printf("\n");
	}
	return 0;
}

unsigned int left_rotate_bits(unsigned int num) /* rotate bit to right*/
{
	return (num << 1) | (num & (1 << (i-1))) >> (i-1);
}

#endif

#if 0 
unsigned int right_rotate_bits(unsigned int); 
int i = 8 * sizeof(void *);

int main()
{
	unsigned int num; /*user input : Number */
	
	printf("\nEnter the Number:");
	num = atoimy();

	if(num >=0){	
		show_bit((int)(right_rotate_bits(num)));
		printf("\n");
	}
	return 0;
}

unsigned int right_rotate_bits(unsigned int num) /* rotate bit to left*/
{
	return  (num >> 1) | ((num & 1) << (i-1));

}
#endif

#if 0 
unsigned int right_rotate_bits(unsigned int , int); 
int i = 8 * sizeof(void *);

int main()
{
        unsigned int num; 				/*user input : Number */
		int bit_cnt = 0;        		/*Bit Counter*/
        printf("\nEnter the Number:");
       	num = atoimy();

		printf("\nEnter the Bits");
		bit_cnt = atoimy();

        if(num >=0){    
                show_bit((int)(right_rotate_bits(num , bit_cnt)));
                printf("\n");
        }
        return 0;
}

unsigned int right_rotate_bits(unsigned int num , int cnt) /* rotate bit to left*/
{
	int j= 0;
	for(j = 0; j < cnt; j++)
        	num = ((num & 1) << (i-1)) | (num >> 1); 	

	return num;
}
#endif
#if 0 

unsigned int left_rotate_n_bits(unsigned int , int); 
int i = 8 * sizeof(void *);

int main()
{
        unsigned int num; /*user input : Number */
        int pos;  /*User Input : bit Count */

        printf("\nEnter the Number:");
        num = atoimy();

		printf("\nEnter The Bit Count");
		scanf("%d",&pos);
        
		if(num >=0){    
                show_bit((int)(left_rotate_n_bits(num , pos)));
                printf("\n");
        }
        return 0;
}

unsigned int left_rotate_n_bits(unsigned int num , int pos) /* rotate bit to right*/
{
    int j = 0;
	for(j=0 ; j<pos ; j++)
		num = (num << 1) | (num & (1 << (i-1))) >> (i-1);
	return num;
}

#endif

