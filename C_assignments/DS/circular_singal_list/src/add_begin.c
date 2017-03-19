#include"cll.h"
/*Node Add Begin*/
cll *add_begin(cll *head)
{
	cll *ptr = create_node();
	cll *temp;
	int i = 0;
	if(head == NULL){
		head = ptr;
		head->next = head;
	}
	else{
		temp = head;
		while(temp->next != head)
			temp= temp->next;
		ptr->next = head;
		head = ptr;
		temp->next = head;
	}
	return (head);
}

