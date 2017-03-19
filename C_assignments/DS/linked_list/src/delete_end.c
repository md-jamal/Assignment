#include"list.h"

/*Delete End Node*/
sll *delete_end(sll *head)
{
	sll *tmp_ptr;
	sll *prev_add = NULL;
	if(head== NULL)
		printf("\nLinked List Is empty");
	else{
		
		if(head->next == NULL){
			tmp_ptr = head;
			head = NULL;
			free(tmp_ptr);
		}
		else{
				tmp_ptr = head;
			  while(tmp_ptr->next != NULL){                                                     
      			 prev_add = tmp_ptr;                                                     
       			 tmp_ptr = tmp_ptr->next;                                                
    		 } 
			prev_add->next = NULL;
			free(tmp_ptr);
		}
	}
	return head;
}
