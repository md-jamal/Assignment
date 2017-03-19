/*Return Given Position Node*/
#include"list.h"
sll *return_pos_node(sll *head , int pos)
{
	int i = 1;
	sll *temp = head;
	while(i++ < pos)
		temp = temp->next;
	return temp;
}
