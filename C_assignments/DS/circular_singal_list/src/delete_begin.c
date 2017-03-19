#include"cll.h"

cll *delete_begin(cll *head)
{
	cll *temp = head ;
	cll *ptr = head;
	if(head == NULL)
		printf("\nList Is Empty");
	else{
		while(ptr->next != head)                                               
            ptr = ptr->next; 		
		head = temp->next;
		ptr->next = head;
		free(temp);
	}
	return head;
}
