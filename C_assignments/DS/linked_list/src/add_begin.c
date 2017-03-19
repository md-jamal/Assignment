#include"list.h"

/*Node Add Begin*/

sll *add_begin(sll *head)
{
	sll *ptr = create_node();			/*Create New Node*/
	if(head == NULL)
		head = ptr;
	else{
		ptr->next = head;
		head = ptr;
	}
	return (head);
}

