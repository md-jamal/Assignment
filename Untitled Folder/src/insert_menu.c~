#include"dlist.h"

dll *insert_menu(dll *head)
{
	int opt = 0;

	while(1){
		printf("Double Linked List insertion");
		printf("\n1.Insert Begin");
		printf("\n2.Display:");
		printf("\n3.EXIT");
		scanf("%d",&opt);
		
		if(opt >=3)
			break;
		switch(opt){
			case 1:
				head = insert_begin(head);
				break;
			case 2:
				display(head);
				break;
		}
	}
	return head;
}
