
/*Node Add End*/

#include"list.h"

sll *add_end(sll *head)
{
	sll *ptr = create_node();			/*Create New Node*/	
	sll *last_node = NULL;

	if (head == NULL) {
		head = ptr;
	}
	else {
		last_node = getlast_node(head);
		last_node->next = ptr;
	}
	return head;
}
