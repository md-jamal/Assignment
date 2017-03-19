
/*Return Given Position Node*/

#include"dlist.h"

dll *return_pos_node(dll *head , int pos)
{
	int i = 1;
	dll *temp = head;
	while(i++ < pos)
		temp = temp->next_node;
	return temp;
}
