/*Insert At penultinate Node*/
#include"list.h"
sll *penultinate_node(sll *head)
{
	sll *new_node = NULL;                                                       
    sll *prev_add = NULL;                                                       
    sll *next_add = NULL;                                                       
    if(head == NULL)                                                
        printf("\nLinked List Is Empty\n");                  
    else{
		if(head->next == NULL)
			head = add_begin(head);
		else{                                                                       
      		new_node = create_node();                                               
        	prev_add = return_pos_node(head , (node_count(head)-1));                             
        	next_add = prev_add->next;                                              
        	prev_add->next = new_node;                                              
        	new_node->next = next_add;  
		}                                            
    }                                                                           
    return head;	
}
