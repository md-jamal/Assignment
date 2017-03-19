#include"dlist.h"

/*Delete Begin Node*/

dll *delete_begin(dll *head)
{
	dll *temp;
	if(head == NULL)
		printf("\nList is Empty");
	else{
		temp =head;
		head = head->next_node;
		head->prev_node = NULL;
		free(temp); 
	}
	return head;
}
