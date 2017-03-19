#include"list.h"

/*Delete after N Position*/

sll *delete_after_n_pos(sll *head , int pos )
{
	int i = 1;
	sll *prev_add = NULL;  /*To Hold Next Address Of Node*/
	sll *next_add = NULL;
	sll *temp = NULL;      /*Traverse the List*/
	if(head == NULL)
		printf("\nList Is empty");
	else{
			if(pos < 1 || pos >= node_count(head))
				printf("\nYour Position Is wrong");
			else{
					temp = head;
					while(i++ < pos)                    
   					     temp = temp->next;  
					prev_add = temp;
					next_add = prev_add->next;
					prev_add->next = next_add->next;
					free(next_add);
				}
		}	
	return head; 
}
