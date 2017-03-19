#include"que.h"
/*Display Queue*/

void display(int front, int rear, int *q_arr)
{
	int i;
	if(front > rear)
		printf("\nQueue Is Empty");
	else{
		printf("\nData:");
		i = front;
		while(i <= rear)
			printf("%d  ",q_arr[i++]);
	}
}
