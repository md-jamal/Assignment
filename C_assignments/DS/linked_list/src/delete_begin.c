#include"list.h"

sll *delete_begin(sll *head)
{
	sll *temp = head ;
	if(temp == NULL)
		printf("\nList Is Empty");
	else{
		head = temp->next;
		free(temp);
	}
	return head;
}
