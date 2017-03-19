#include "header.h"

int dequeue()
{
	int element;
	if ( front+1 > rear )
		printf("the queue is empty\n");
	else {
		front = front + 1;
		element = queue[front];
	}
	return element;
}
