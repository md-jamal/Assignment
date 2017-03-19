#include"list.h"
sll *insert_after_n_pos(sll *head , int pos)
{
	sll *new_node = NULL;
	sll *prev_add = NULL;
	sll *next_add = NULL;
	if(pos > (node_count(head)))
		printf("\nSorry Your Given position Is Wrong.....\n");
	else{
		if(pos == (node_count(head)))
			add_end(head);
		else{
			new_node = create_node();
			prev_add = return_pos_node(head , pos);		
			next_add = prev_add->next;
			prev_add->next = new_node;
			new_node->next = next_add;
		}
	}
	return head;
}
