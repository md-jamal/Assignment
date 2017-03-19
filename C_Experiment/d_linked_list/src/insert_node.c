#include "dlist.h"

dll *insert_node(dll *head, int pos)
{
	dll *new_node = create_node();
	dll *temp = head;
	dll *ins_add = NULL;
	int i = 1;

	if(pos <= 0)
		printf("\nWrong Pos");
	else {
		if(pos > node_count(head))
			printf("\nWrong pos");
		else {
			if(pos == 1)
				head = insert_begin(head);
			else {
				while(i++ < (pos - 1))
					temp = temp -> next_node;
				ins_add = temp->next_node;
				temp->next_node = new_node;
				new_node -> prev_node = temp;
				new_node->next_node = ins_add;
				ins_add->prev_node = new_node;
			}
		}
	}
	return head;
}
