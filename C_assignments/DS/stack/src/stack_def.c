#include"stack_dcrl.h"

/*Data push To The stack*/

int push(int data, int *stk_arr, int *top)
{
	if(*top == SIZE)
		return 1;
	else{
			stk_arr[++(*top)] = data;
			return 0; 
	}
}

/*Data pop From The Stack*/

int pop(int *stk_arr, int *top)
{
	if(*(top) == -1){
		return 1;
	}
	else
		return stk_arr[(*top)--];
}

/*Display Stack Function*/
void display(int *stk_arr, int *top)
{	
		int i = *top;
		printf("Data::");
		while(i >= 0)
			printf("%4d",stk_arr[i--]);
}

/*Display menu Function*/
int opt()
{
	int opt_ch = 0;
	system("clear");
	printf("\n\n......Stack Implementation........\n");
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n..Choose Option:");
	opt_ch = valid();
	printf("\n");
	
	return opt_ch;
}
