/*
 *	Program : Implemention Of Queue.
 *  Author	: Pritam Krishna Mali.
 */

#include "que.h"

int main( void )
{
	int option;							/*Choose Option variable*/
	int data;							/*Data Variable*/
	int q_arr[MAX];						/*Queue Array*/
	int rear = -1;						/*End or rear variable of Queue*/
	int front = 0;						/*Front or Start Variable Of Queue*/
	
		while(1)
		{
			system("clear");
			option = opt();
			
			if(option >=4)
				break;
			switch(option) {
				case 1:
					printf ("\nEnter the Data");
					data = valid();
					rear = enqueue(data, front, rear, q_arr); /*Enqueue Data*/
					break;
				case 2:
					front = dequeue(front, rear, q_arr);      /*Dequeue Data*/
					getchar();
					break;
				case 3:
					display(front, rear, q_arr);			  /*Display Data*/
					break;
				case 4:
					exit(0);
			}
		}
}
