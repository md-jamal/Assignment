/*Create Node Function*/
#include"list.h"
sll *create_node()
{
	int data = 0;
	sll *tmp_ptr = NULL;
	
	printf("\nEnter The Data:");
	scanf("%d",&data);
	if(NULL == ( tmp_ptr = (sll *)malloc(sizeof(sll)))){
		printf("\nMalloc Is failed...");
	}
	else{
		tmp_ptr->data = data;
		tmp_ptr->next = NULL;
	}
	return tmp_ptr;
}
