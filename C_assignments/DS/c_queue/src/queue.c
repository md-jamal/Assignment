#include"que.h"

int c_enque(int data, int front, int rear, int *c_q)
{
	

	if((front > rear) && (front != -1 && rear != -1))
		printf("\nQueue is full");
 	else{
		if(rear == SIZE){
			rear = -1;
			c_q[++rear] = data;
		}
		else
			c_q[++rear] = data;
	}	
	return rear;
}

int c_deque(int front, int rear, int *c_q)
{
	if(front == -1 && rear == -1)
		printf("\nQueue is Empty");
	else{
		if(front == SIZE){
			front = -1;
		}
		printf("Dequeue Data::%d",c_q[++front]);
	}
	return front;
}
void display(int front, int rear, int *c_q)
{
	int i = 0;
	if(front== -1 && rear == -1)
	{
		printf("\nQueue Is Empty");
	}
	else{
		printf("\nData::");
		if(front > rear){
			for(i = front ; i<= SIZE ; i++)
				printf("%4d",c_q[i]);
			for(i = 0 ; i <= rear ; i++)
				printf("%4d",c_q[i]);
		}
		else{
			for(i = front; i <= rear ; i++)
				printf("%4d",c_q[i]);
		}
	}
	
}
int opt()
{
	int opt_ch = 0;
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n..Choose Option:");
	opt_ch = valid();
	printf("\n");
	
	return opt_ch;
}
