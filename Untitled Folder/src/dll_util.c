/*
	Program:Implement Double Linked List
	Author : Pritam Krishna Mali.
*/
#include"dlist.h"

int main()
{
	dll *head = NULL;
	int opt;
	
	while(1){
		printf("\n1.insert");
		printf("\n2.Delete");
		printf("\n3:EXIT");
		printf("\nChoose option:");
		scanf("%d",&opt);

		if(opt >= 3)
			break;
		switch(opt){
			case 1:
				head = insert_menu(head);
				break;
			case 2:
				break;
		}
	}
	return 0;
}

