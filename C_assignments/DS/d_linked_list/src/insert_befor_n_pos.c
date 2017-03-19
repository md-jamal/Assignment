#include"dlist.h"
/*Insert Befor N Position*/
dll *insert_befor_n_pos(dll *head , int pos)
{
	dll *new= NULL;
	dll *prev = NULL;
	
	if(pos > (node_count(head)) || pos <= 0)
		printf("\nSorry Your Given position Is Wrong.....\n");
	else{
		if(pos == 1)
			head = insert_begin(head);
		else{
			new = create_node();
			prev = return_pos_node(head , (--pos));	
			new->next_node = prev->next_node;	
			new->prev_node = prev;		
			prev->next_node = new;
		}
	}
	return head;
}
