#include"dlist.h"
/*Insert Befor N Position*/
dll *insert_befor_n_pos(dll *head , int pos)
{
	dll *new_node = create_node();
	dll *temp = head;
	int i = 1;

	if( head == NULL)
		head = new_node;
	else{
		if( pos == 1)
			head = insert_begin( head );
		else {
			if(pos == (node_count(head))+1){
				head = insert_end(head);
			}
			else{
				while( i++ <(pos-1))
					temp = temp -> next_node;
				new_node->prev_node = temp;
				new_node->next_node = temp->next_node;
				(temp->next_node)->prev_node = new_node;
				temp->next_node = new_node;
			}
		}
	} 
	/*if(pos > (node_count(head)) || pos <= 0)
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
	}*/
	return head;
}
