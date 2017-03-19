#include"cll.h"

void display(cll *head)
{
	cll *temp = head;
	if(head == NULL)
		printf("\nList Is Empty");
	else{
		printf("\nData:");
		do{
			printf("%d ",temp->data);
			if(temp->next == head)
				break;
			temp =temp->next;
		}while(1);
	}
}
