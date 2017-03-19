#include"dlist.h"

/*Add Node At End*/

dll *insert_end(dll *head)
{
	dll *new = create_node();
	dll *temp;
	if(head == NULL)
		head  = new;
	else{
		temp = head;
		while(temp->next_node != NULL)
				temp = temp->next_node;
		temp->next_node = new;
		new->prev_node = temp;
	} 
	return head;
}
