/*
 *	Program: Main Function Circular Double Linked List
 *	Author : Pritam Krishna Mali.
 */

#include"cdlist.h"

/*Main Function*/

int main()
{
	int opt;				/*User Input: Option*/
	int chk;				/*cheak variable*/
	CDLIST *head = NULL;	    /*List head*/
	
	while(1){
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display:");
		printf("\n4.EXIT");
		printf("\nChoose Option:");
		scanf("%d",&opt);
		
		if(opt >= 4)
			break;
		switch(opt){
			case 1:
				head = insert_node(head);				/*Add Node Function*/
				break;
			case 2:
				head = delete_node(head);			/**/
				break;
			case 3:
				if(display_list(head))						/*Display List*/
					printf("\nList Is Empty");
				break;
		}
	}
}
