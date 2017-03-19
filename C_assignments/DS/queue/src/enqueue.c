#include"que.h"

/*Insert Data IN Array*/

int enqueue(int data, int front, int rear, int *q_arr)
{

	if(rear == MAX-1)
		printf("\nQueue Is Full");
	else{
		q_arr[++rear] = data;
		printf("Data Inserted\n");
	}
	return rear;
}

