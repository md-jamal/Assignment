#include"list.h"

/*Delete after N Position*/

sll *delete_befor_n_pos(sll *head , int pos )
{
	int i = 1;
	sll *prev_add = NULL;  /*To Hold Next Address Of Node*/
	sll *temp = NULL;      /*Traverse the List*/
	if(head == NULL)
		printf("\nList Is empty");
	else{
			if(pos < 1 || pos >= node_count(head))
				printf("\nYour Position Is wrong");
			else{
					temp = head;
					while(i++ < pos){  
					     prev_add = temp;                 
   					     temp = temp->next;
					}  
					prev_add->next = temp->next;
					free(temp);
				}
		}	
	return head; 
}
