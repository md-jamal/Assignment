#include"list.h"

sll *delete_n_pos(sll *head , int pos )
{
	int i = 1;
	sll *prev_add = NULL;
	sll *temp = NULL;
	if(head == NULL)
		printf("\nList Is empty");
	else{
		if(pos == 1)
			head = delete_begin(head);
		else{
			if(pos < 1 || pos > node_count(head))
				printf("\nYour Position Is wrong");
			else{
				if(pos == node_count(head))
					head = delete_end(head);
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
		}
	}
	return head; 
}
