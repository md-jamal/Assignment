#include"list.h"
/*Delete Node At Middle*/

sll *delete_at_middle(sll *head)
{
	int cnt = (node_count(head)/2);
	if(head == NULL)
		printf("\nList Is Empty");
	else
		head = delete_n_pos(head, cnt);  
	return head;
}

