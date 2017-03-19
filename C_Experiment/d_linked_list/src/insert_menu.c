#include"dlist.h"

dll *insert_menu(dll *head)
{
	int opt;
	int pos = 0;		/*position of node*/
	int num = 0;		/*Take number which is present in list*/
	char *_pos = NULL;
	char *_num = NULL;
	dll *temp = head;
	if(NULL == (_pos = (char *)malloc(sizeof(char) * MAX)))
		printf("malloc Failed");
	if(NULL == (_num = (char *)malloc(sizeof(char) * MAX)))                      
        printf("malloc Failed");

	while(1){
		printf("\nDouble Linked List Insertion");
		printf("\n1.Insert Begin");
		printf("\n2.Insert End");
		printf("\n3.Insert Befor N position");
		printf("\n4.Insert At given position");
		printf("\n5.Delete Begin");
		printf("\n6.Delete End");
		printf("\n7.Delete N position");
		printf("\n8.Delete_middle");
		printf("\n9.Display");
		printf("\n10.Display Reverse");
		printf("\n11.Exit");
		printf("\nChoose Option:");
		scanf("%d",&opt);
	
		if(opt >=11)
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
				 getchar();                                                      
				 printf("Enter The Position");                                  
				 fgets(_pos , MAX , stdin);                                      
				 pos = atoi(_pos);                                              												                 head = insert_node(head , pos); //Insert Node Before Ni
				 break;
			case 5:
				head = delete_begin(head);
				break;
			case 6:
				head = delete_end(head);
				break;
			case 7:
				getchar();                                                      
                printf("Enter The Position");                                   
                fgets(_pos , MAX , stdin);                                      
                pos = atoi(_pos); 
				head = delete_n_pos(head, pos);
				break;
			case 8:                      
				while(temp != NULL){
					pos++;
					temp = temp->next_node;
				}
				head = delete_node(head,pos);                                
				break;
			case 9:
				display(head);
				break;
			case 10:
				rev_disp(head);
				break;
		}
	}
	return head;
}
