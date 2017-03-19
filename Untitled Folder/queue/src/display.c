#include "header.h"

void display()
{
	int i;
	
	printf("the elements in the queue are\n");	
	for ( i = front+1 ; i <= rear ; i++)
		printf("%d\t",queue[i]);
		printf("\n");
}
