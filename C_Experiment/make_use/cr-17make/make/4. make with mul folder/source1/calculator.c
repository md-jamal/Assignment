#include "header.h"

int add (int, int);
int sub (int, int);
int mul (int, int);
float div (int, int);

int main (void)
{
	int num1 = 10;
	int num2 = 5;
	printf ("\n----------Simple Calculator-----------");
	printf ("\nResult of Addition \t\t: %d",add (num1, num2));
	printf ("\nResult of Subtration \t\t: %d",sub (num1, num2));
	printf ("\nResult of Multiplication \t: %d",mul (num1, num2));
	printf ("\nResult of Division \t\t: %.1f",div (num1, num2));
	printf ("\n--------------------------------------\n");

	return 0;
}
