/*Create Node Function*/
#include"cll.h"
cll *create_node()
{
	int data = 0;
	cll *tmp_ptr = NULL;
	
	printf("\nEnter The Data:");
	scanf("%d",&data);
	if(NULL == ( tmp_ptr = (cll *)malloc(sizeof(cll)))){
		printf("\nMalloc Is failed...");
	}
	else{
		tmp_ptr->data = data;
		tmp_ptr->next = NULL;
	}
	return tmp_ptr;
}
