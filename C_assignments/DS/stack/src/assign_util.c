#include"stack_dcrl.h"

int main()
{
	int top = -1;
	int option;
	int res = 0;
	int data;
	int stk_arr[SIZE];

	while(1)
	{
		option = opt();
		
		if(option >=4)
			break;
		switch(option)
		{
			case 1:										/*Push Data*/
				printf("Enter the Data");				
				data = valid();
				if (push(data, stk_arr, &top ) == 0)
					printf("\nData Pushed");
				else
					printf("\nStack Is Full"); 
				break;
			case 2:										/*Pop Data*/
				res = pop(stk_arr, &top);				
				if(res == 1)
					printf("\nStack is Empty"); 
				else
					printf("Pop Data:%d",res);
				break;
			case 3:										/*Display Data*/
				display(stk_arr, &top);				
				break;
			case 4:
				exit(0);
		}
	}
}
