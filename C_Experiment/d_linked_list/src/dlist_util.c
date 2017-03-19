#include"dlist.h"

int main()
{
	int opt;
	dll *head = NULL;
	dll *end = NULL;
	while(1){
		printf("\nDouble Linked List");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Exit");
		scanf("%d",&opt);

		if(opt >= 3)
			break;
		switch(opt){
			case 1:
				head = insert_menu(head); 
				break;
		}
	}
	return 0;
}
