#include"cdlist.h"

/*To insert node in Double linked List*/

CDLIST *insert_node(CDLIST *head)
{
	CDLIST *new_node = createnode();		/*To create New Node*/
	
	if (head == NULL) {
		head = new_node;
		head->prev = new_node;
		head->next = new_node; 
		return head;
	}else {
		(head->prev)->next = new_node;
		new_node->prev = head->prev;
		new_node->next = head;
		head->prev = new_node;	
	}
	return head;
}
