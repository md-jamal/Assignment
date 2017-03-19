#include "dlist.h"

dll *delete_node(dll *head, int middle)
{
	dll *temp = head;
	int i = 1;

	if(head == NULL)
		printf("list is empty");
	else{
		if(head->next_node == NULL)
			head = delete_begin(head);
		else{
			while(i++ < (middle-1))
				temp = temp->next_node;
			((temp->next_node)->next_node)->prev_node = temp;
			temp->next_node = (temp->next_node)->next_node;
			free(temp);
		}
	}
	return head;
}
