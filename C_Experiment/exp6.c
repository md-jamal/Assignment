/*
	Program : Swap Variable
*/ 

#include<stdio.h>

#if 0
void swap(int * , int *);

int main()
{
	int num1 = 10;
	int num2 = 20;

	swap(&num1 , &num2);
	
	printf("A: %d B: %d",num1,num2);

	return 0;
}
void swap(int *a , int *b)
{
	 int tmp = 0;

	 tmp = *a;
	*a= *b;
	*b = tmp;
}
#endif
 
#if 1

/*Program : add multiply sub*/

int a_m_s(int *, int *,int *);
int main()
{
	int num1;  //Var : Addition
	int num2;  //var : subtraction
	int num3;  //var : Multiplication

	a_m_s(&num1 , &num2, &num3);   //call Function a_m_s
	
	printf("Add : %d\n Multi:%d\n Sub:%d\n",num1,num2,num3);

	return 0;
}

/*Addition Subtraction Multiplication of Two Number*/

void a_m_s(int *add, int *mul, int *sub)
{
	int no1 = 10;
	int no2 = 20;

	*add = no1 + no2;
	*mul = no1 * no2;
	*sub = no2 - no1;

}






#endif
