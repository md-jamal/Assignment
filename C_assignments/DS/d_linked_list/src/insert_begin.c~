#include"dlist.h"

dll *insert_begin(dll *head) 
{
	dll *new = create_node();
	
	if(head == NULL)
		head = new;
	else{
		head->prev_node = new;
		new->next_node = head;	
		head = new;
	}
	return head;
}
