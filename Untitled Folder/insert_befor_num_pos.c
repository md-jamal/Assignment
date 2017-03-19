#include"list.h"
/*Insert Node Before given Num */

sll *insert_befor_num_pos(sll *head , int num)
{
	sll *tmp_ptr = head;
	sll *prev_add = NULL;
	sll *new_node = NULL;                                                       
    sll *next_add = NULL;

	while(tmp_ptr != NULL){
		if(num == (tmp_ptr->data))
		{
			break;
		}
		else{
			prev_add = tmp_ptr;
			tmp_ptr = tmp_ptr->next;
		}
	}
		
	if(tmp_ptr == NULL)
		printf("Your number Not Found In Linked List");
	else{
		if(prev_add == NULL)
			head = add_begin(head);
		else{
			new_node = create_node();                                                                      
        	next_add = prev_add->next;                                              
        	prev_add->next = new_node;                                              
        	new_node->next = next_add; 
		}
	}	
	return head;
}
