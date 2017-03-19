#include"list.h"
/*Insert Node At Middle*/
sll *insert_middle(sll *head)
{
	int cnt = (node_count(head)/2);
	if(head == NULL)
		printf("\nList Is Empty");
	else
		head = insert_after_n_pos(head, cnt);  
	return head;
}

