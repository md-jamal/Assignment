#include"cdlist.h"

/*Delete Node Function*/

CDLIST *delete_node(CDLIST *head)
{
	CDLIST *temp;
	if (head == NULL)
		printf("\nList Is Empty");
	else {
		if((head->next == head) && (head->prev == head)){
			temp = head;
			head = NULL;
			free(temp);
		}
		else {
			temp = head->prev;
			head->prev = (head->prev)->prev;
			(head->prev)->next = head;
			free(temp);
		}
	}
	return head;
}
