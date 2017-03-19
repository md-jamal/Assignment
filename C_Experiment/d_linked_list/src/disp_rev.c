#include"dlist.h"

void rev_disp(dll *head)
{
	if(head == NULL)
		return;
	else{
		rev_disp(head->next_node);
		printf("%4d",head->data);
	}
	return;
}
