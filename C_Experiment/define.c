#include<stdio.h>
#define cat(a,b) a##b

int main()
{
	printf("%d",cat(12,34));
	return 0;
}
