#include"dlist.h"

dll *insert_menu(dll *head)
{
	int opt;
	int pos = 0;		/*position of node*/
	int num = 0;		/*Take number which is present in list*/
	char *_pos = NULL;
	char *_num = NULL;
	if(NULL == (_pos = (char *)malloc(sizeof(char) * MAX)))
		printf("malloc Failed");
	if(NULL == (_num = (char *)malloc(sizeof(char) * MAX)))                      
        printf("malloc Failed");

	while(1){
		printf("\nDouble Linked List Insertion");
		printf("\n1.Insert Begin");
		printf("\n2.Insert End");
		printf("\n3.Insert Befor N position");
		printf("\n4.Delete Begin");
		printf("\n5.Delete End");
		printf("\nDelete N position");
		printf("\n7.Display");
		printf("\n8.Exit");
		printf("\nChoose Option:");
		scanf("%d",&opt);
	
		if(opt >=8)
			break;
		switch(opt){
			case 1:
				head = insert_begin(head);
				break;
			case 2:
				head = insert_end(head);
				break;
			case 3:
				getchar();
				printf("Enter The Position");
				fgets(_pos , MAX , stdin);
				pos = atoi(_pos);		
				head = insert_befor_n_pos(head , pos); //Insert Node Before N pos
				break;
			case 4:
				head = delete_begin(head);
				break;
			case 5:
				head = delete_end(head);
				break;
			case 6:
				getchar();                                                      
                printf("Enter The Position");                                   
                fgets(_pos , MAX , stdin);                                      
                pos = atoi(_pos); 
				head = delete_n_pos(head, pos);
				break;
			case 7:
				display(head);
				break;
		}
	}
	return head;
}
