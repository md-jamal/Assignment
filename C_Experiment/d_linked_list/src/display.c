#include"dlist.h"

void display(dll *head)
{
	dll *temp = head;
	
	if(head == NULL)
		printf("\nList Is Empty");
	else{
		printf("\nData::");
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next_node;
		}
	}
}
