#include"dlist.h"

/*Delete End Node*/
dll *delete_end(dll *head)
{
	dll *tmp_ptr;
	dll *prev_add = NULL;
	if(head== NULL)
		printf("\nLinked List Is empty");
	else{
		
		if(head->next_node == NULL){
			tmp_ptr = head;
			head = NULL;
			free(tmp_ptr);
		}
		else{
				tmp_ptr = head;
			  while(tmp_ptr->next_node != NULL){                                                     
      			 prev_add = tmp_ptr;                                                     
       			 tmp_ptr = tmp_ptr->next_node;                                                
    		 } 
			prev_add->next_node = NULL;
			free(tmp_ptr);
		}
	}
	return head;
}
