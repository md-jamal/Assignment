#include<stdio.h>
#include<math.h>

/*To Check the number is power of two or not*/

#if 1
int power_two(int);

int main()
{
	char test[20];  //User Input : Number
	int num = 0;
	
	printf("\nEnter the number:");
	scanf("%s",test);
	
	num = atoi_1(test);

	if(num != 1)
	{
		power_two(num);
	}
	else
		printf("\nUser Input is Wrong\n");
	return 0;
}
int power_two(int num)
{
	show_bit( num );
        printf("\n");   

        if(!(num & (num -1)))        // To check The Number is Power Of Two or Not
            printf("\nThe Number is Power of 2\n");
        else
            printf("\nThe Number is Not Power of 2\n");
}

#endif


/*To multiply a number by 4 */

#if 0
int four_multi(int);
int main()
{
	int num = 0; //User Input : Number
        char test[20];
	
	printf("\nEnter the number:");
	scanf("%s",test);

	num = atoi(test);
	printf("\n%d",num);
	if(num != 1)
	{	
		four_multi(num);
	}
	else
		printf("Plz Check your input\n");

	return 0;
}
int four_multi(int num)
{
	show_bit(num);
        printf("\n");

        num = num << 2;       //to multiply by 4 
        
        show_bit(num);
        printf("\n");

        printf("\nThe Number is:%d\n",num);
}
#endif

#if 0 
/* Count the number of bits set in a number*/

int cnt_bit(int);
int main()
{
	char test[20]; //User Input : number
	int num = 0;

	printf("\nEnter the number:");
	scanf("%s",test);
	
	num = atoi(test);
	
	if(num != 1)
	{
		cnt_bit(num);
	}
	else
		printf("\nUser Input Wrong\n\n");
}
int cnt_bit(int num)
{
		int i = 0;
		int cnt = 0;
		show_bit(num);
                printf("\n");

                for(i = 0; i<= (8 * sizeof(void *)-1); i++)
                        (num & (1 << i))? cnt++ : cnt;
                printf("\nThe Count Is:%d\n",cnt);
	
		return 0;
}
#endif
