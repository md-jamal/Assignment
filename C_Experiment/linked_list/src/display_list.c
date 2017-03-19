#include"list.h"

/*Display List Function*/

void display_list(sll *head)
{
	sll *temp = head;
	if (head == NULL)
		printf("Linked List is empty");
	else{
		printf("\n\nData::");
		while (temp != NULL) {
			printf("%d ",temp->data);
			temp = temp ->next;
		}
	}
}
