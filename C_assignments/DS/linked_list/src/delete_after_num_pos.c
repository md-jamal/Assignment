#include"list.h"

/*Delete after Num Position*/

sll *delete_after_num_pos(sll *head , int num)
{
	int i = 1;
	sll *temp = NULL;      /*Traverse the List*/
	sll *prev_add = NULL; /*To hold preveious add*/
	sll *next_add = NULL;

	if(head == NULL)
		printf("\nList Is empty");
	else{
		temp = head;
		while(temp != NULL){
			if(temp->data == num)
				break;           
   			temp = temp->next;
		}
		if(temp == NULL)
			printf("\nNumber is Not Found In Linked List\n");  
		else{
			if(temp->next == NULL)
				printf("\nDeletion Not Possible Becasue Given Number is In last Node\n");
			else{
				prev_add = temp;
				next_add = prev_add->next;
				prev_add->next = next_add->next;
				free(next_add);
			}
		}
	}	
	return head; 
}
