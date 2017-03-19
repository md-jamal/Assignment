
/*Node Add End*/

#include"list.h"

sll *add_end_file(sll *head, int key)
{
	sll *temp = create_node_file(key);
	sll *new_node = NULL;

	if(head == NULL){
		head = temp;
	}
	else{
		if ( head->next == NULL ){
			if(head->data < key )
				head->next = new_node;
			else{
				new_node->next = new_node;
				head = new_node;
			}
			printf("HH%d",head->data);
		}
		else{
			while((temp->next)->data > key )
				temp = temp->next;
			new_node = temp->next;
			temp = new_node;
		}
	}
	return head;
}
