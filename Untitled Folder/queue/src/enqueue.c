#include "header.h"
void enqueue (int element)
{
	if ( rear >= MAX-1 )
		printf("the queue is full\n");
	else {
		rear = rear + 1;
		queue[rear] = element;
	}
}

