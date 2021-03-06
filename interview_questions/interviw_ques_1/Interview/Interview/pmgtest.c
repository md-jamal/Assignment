/************************************************************************
 * Name  	: C_Programs.c					        *
 * Author 	: Robin Fernandes					*
 * Date  	: February 7, 2013					*
 * Description  : To Understand optimizing the code and logic thinking. *
 * Note 	: Share with your friends.				*
 ***********************************************************************/

/* Tricky C Questions asked in C test
 * Intention to minimize the code and optimize it
 * So that memory can be saved
 * Write functions above the main() to avoid prototypes*/

#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //strlen

/* Enable necessary macroi by uncommenting in and 
 * commenting other macros to run specific program.
 * Default Question 1 set to compile and execute
 */

//#define Q1   /*Enable program 1*/
//#define Q2 /*Enable program 2*/
//#define Q3 /*Enable program 3*/
//#define Q4 /*Enable program 4*/
//#define Q5 /*Enable program 5*/
//#define Q6 /*Enable program 6*/
//#define Q7 /*Enable program 7*/

void num_in_binary(int num)
{
	int pos;
	printf("%d in Binary = ",num);
	for(pos = 31; pos >= 0; pos--)
	{
		if((pos % 4) == 3) printf(" ");
		(num & (1 << pos)) ? printf("1") : printf("0");
	}
	printf("\n");
}

#ifdef Q1
 /* Question 1
  * Simplify: if (x == 0)
  * 		y = 10;
  * 	     else
  * 		y = 20;
 */

void main()
{
	int x , y;
	x = 0;
	y = x ? 20 : 10;
	printf(" x = %d\n y = %d\n", x, y);
}

#endif


#ifdef Q2
 /* Question 2
  * Check for a bit set.
  * Expected Logic to use is limit number of machine instructions here.
  * So Use Conditional to print result instead of returning status (0/-1).
 */

void check_bit(int num, int bit)
{
	(num & (1 << (bit-1))) ? printf("Set\n") : printf("Not set\n");
}

void main()
{
	int num , bit;
	printf("Enter a number\n");
	scanf("%d",&num);
	printf("Enter a bit to check\n");
	scanf("%d",&bit);
	num_in_binary(num);
	check_bit(num,bit);
}

#endif

#ifdef Q3
 /* Question 3
  * Set a bit.
  * Expected Logic to use is limit number of machine instructions here.
  * So Call by refernce used so that no need of return statement.
 */

void set_bit(int *num, int bit)
{
	*num |= (1 << (bit - 1));
}

void main()
{
	int num , bit;
	printf("Enter a number\n");
	scanf("%d",&num);
	printf("Enter a bit to set\n");
	scanf("%d",&bit);
	num_in_binary(num);
	set_bit(&num,bit);
	num_in_binary(num);
}

#endif

#ifdef Q4
 /* Question 4
  * Impliment Optimized strcpy.
 */

char * Strcpy (char*str1 , char *str) 
{
	if (str == NULL || str1 == NULL) return NULL;
	int l = strlen (str) ;
	while(*++str1 = *str++);
	return str1-l;
}

void main()
{
	char *str;
	char *str1;	
	str = malloc (10);
	str1 = malloc (10);
	printf("Enter the string\n");
	fgets(str , 10 , stdin);
	str[strlen(str)]='\0';
	printf("Original src = %s\n",str);
	str1  = Strcpy (str1 , str);	
	printf("Copied string = %s\n",str1);
	printf("Original src = %s\n",str);
}

#endif

#ifdef Q5
 /* Question 5
  * Impliment recursively xpowery i.e power(x,y).
 */

int power (int num, int degree)
{
	if(degree == 0) return 1;
	else if(degree == 1) return num;
	else return num * power(num , --degree);
}

void main()
{
	int num, degree;
	printf("Enter the number\n");
	scanf("%d",&num);
	printf("Enter the degree\n");
	scanf("%d",&degree);
	printf("%d^%d = %d\n",num, degree, power(num, degree));
}

#endif

#ifdef Q6
 /* Question 6
  * Function pointer to printf.
 */

void main()
{
	int (*func)();
	func = (void *) printf;
	func("Robin\n");
}

#endif

#ifdef Q7
 /* Question 7
  * Give anew method which performs same as below methods.
  * Method 1:	if(x == 0) 		Method 2: switch(x) {
  * 			fn0();		          case 0: fn0();
  * 		else if(x = 1)  			  break;
  *			fn1();		 	  case 1: fn1();	
  * 		else if(x = 2) 				  break;
  *			fn2();			  case 2: fn2();
  * 		else fnX();			          break;
  *						  default: fnX();
  *						}
  */

void fn0()
{
	printf("Function 0\n");
}

void fn1()
{
	printf("Function 1\n");
}

void fn2()
{
	printf("Function 2\n");
}

void fnX()
{
	printf("Function X\n");
}

void main()
{
	int x;
	for(x = -1; x < 4; x++)
	(x<0 | x >2) ? fnX() : ((x == 2) ? fn2(): (x ? fn1() : fn0()));
}

#endif

