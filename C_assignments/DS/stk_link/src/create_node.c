#include"stk.h"

stk *create_node()
{
	stk *temp;
	int data;
	if(NULL == (temp = (stk *)malloc(sizeof(stk))))
		printf("\nMalloc Failed");
	else{
		printf("\nEnter The Data");
		scanf("%d",&data);
		temp -> data = data;
		temp->next = NULL;
	}
	return temp;
}
