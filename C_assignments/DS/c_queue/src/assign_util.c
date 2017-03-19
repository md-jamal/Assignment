#include "que.h"

int main()
{
	int rear = -1;
	int front = -1;
	int data = 0;
	int option = 0;
	int c_q[SIZE];

	while(1)
	{
		option = opt();
		
		if(option >=4)
			break;
		switch(option)
		{
			case 1:
				printf("Enter the Data");
				data = valid();
				rear = c_enque(data, front, rear, c_q);
				break;
			case 2:
				front = c_deque(front, rear, c_q);
				break;
			case 3:
				display(front, rear, c_q);
				break;
			case 4:
				exit(0);
		}
	}
}
