#include"list.h"

/*Delete penultinate node*/

sll *delete_penultinate_node(sll *head)
{
	sll *temp = NULL;                                                       
    sll *prev_add = NULL;                                                       
    sll *next_add = NULL;                                                       
    if(head == NULL)                                                
        printf("\nLinked List Is Empty\n");                  
    else{
		if(head->next == NULL)
			head = add_begin(head);
		else{                                                                       
      		temp = head;
			while((temp->next)->next != NULL){
				prev_add = temp;
				temp = temp->next;
			}
			next_add = prev_add->next;
			prev_add->next = temp->next;
			free(next_add);
		}                                            
    }                                                                           
    return head;	
}
