#include"dlist.h"

/*Display All Node of Double Linked list*/

void display(dll *head)
{
	dll *tmp = head;
	
	if(head == NULL)
		printf("\nList Is Empty");
	else{
		printf("\nData:");
		while(tmp != NULL){
			printf("%d  ",tmp->data);
			tmp = tmp->next;
		}
	}
}
