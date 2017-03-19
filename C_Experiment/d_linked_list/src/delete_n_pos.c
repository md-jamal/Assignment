#include"dlist.h"

dll *delete_n_pos(dll *head , int pos )
{
	int i = 1;
	dll *prev_add = NULL;
	dll *temp = NULL;
	if(head == NULL)
		printf("\nList Is empty");
	else{
		if(pos == 1)
			head = delete_begin(head);
		else{
			if(pos < 1 || pos > node_count(head))
				printf("\nYour Position Is wrong\n");
			else{
				if(pos == node_count(head))
					head = delete_end(head);
				else{
					temp = head;
					while(i++ < pos){                                                           
       					 prev_add = temp;                                                        
   					     temp = temp->next_node;                                                      
    				}                                                                           
  				  prev_add->next_node = temp->next_node; 
				  (temp->next_node)->prev_node = prev_add;                                               
    			  free(temp);
				}
			}	
		}
	}
	return head; 
}
