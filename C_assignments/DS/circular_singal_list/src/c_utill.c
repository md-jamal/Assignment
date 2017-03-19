#include"cll.h"

int main()
{
	int opt;
	cll *head = NULL;	
	while(1){
		printf("\n1.Insert begin");
		printf("\n2.Delete");
		printf("\n3.Display:");
		printf("\n4.EXIT");
		printf("\nChoose Option");
		scanf("%d",&opt);
		
		if(opt >= 4)
			break;
		switch(opt){
			case 1:
				head = add_begin(head);
				break;
			case 2:
				head = delete_begin(head);
				break;
			case 3:
				display(head);
				break;
		}
	}
}
