/*To get last Node From List*/
#include"list.h"
sll *getlast_node(sll *head)
{
	sll *tmp_ptr = head;
	
	while(tmp_ptr->next != NULL)
		tmp_ptr = tmp_ptr -> next;
	return tmp_ptr;
}
