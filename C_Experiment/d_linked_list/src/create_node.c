#include"dlist.h"

dll *create_node()
{
	dll *temp_ptr;
	int num= 0;

	if(NULL == (temp_ptr = (dll *)malloc(sizeof(dll))))
		printf("\nMalloc Failed");
	else{
		printf("\nEnter the Data:");
		scanf("%d",&num);
		temp_ptr->data = num;
		temp_ptr->prev_node = NULL;
		temp_ptr->next_node = NULL;
	}
	return temp_ptr;
}
