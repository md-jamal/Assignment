#include"list.h"

/*Delete after N Position*/

sll *delete_befor_num_pos(sll *head , int num)
{
	int i = 1;
	sll *prev_add = NULL;  /*To Hold Next Address Of Node*/
	sll *temp = NULL;      /*Traverse the List*/
	if(head == NULL)
		printf("\nList Is empty");
	else{
		temp = head;
		while(temp != NULL){
			if((temp->next)->data == num)
				break;      
			prev_add = temp;           
   			temp = temp->next;
		}
		if(temp == NULL)
			printf("\nNumber is Not Found In Linked List\n");  
		else{
			prev_add->next = temp->next;
			free(temp);
		}
	}	
	return head; 
}
