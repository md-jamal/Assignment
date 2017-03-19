#include"cdlist.h"

int display_list(CDLIST *head)
{
	CDLIST *temp = head;

	if(head == NULL)
		return 1;
	else{
			printf("Data::");
			do{
				printf("%d ",temp->data);
				temp = temp ->next;
			} while(temp != head);
		}
	return 0;
}
