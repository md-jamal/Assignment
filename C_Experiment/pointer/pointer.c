#include<stdio.h>

int main( void )
{
	char arr[5][10] = {"pritam","sonam","trupti","yogesh","runali"};
	char *ptr = arr;
	printf("Ptr:%c\n",*(*(ptr + 1)+1));
	return 0;
}
