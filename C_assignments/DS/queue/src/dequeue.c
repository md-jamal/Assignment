#include"que.h"
/*Remove Data From queue */

int dequeue(int front, int rear, int *q_arr)
{
	if (front > rear)
		printf("\nQueue Is Empty");
	else
		printf("Dequeue Element :%d\n",q_arr[front++]);
	return front;
}
