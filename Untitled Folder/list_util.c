/*
	Programe : To Create New Linked List And To perform aoperation Insertion 
			   And Deletion
	Author : Pritam Krishna Mali.
*/

#include"list.h"

int main()
{
	sll *head = NULL;   /*To hold Address OF First Node*/
	int opt = 0;		/*To keep user selected Option*/	
	int pos = 0;		/*position of node*/
	int num = 0;		/*Take number which is present in list*/

	while(1){
		opt = menu();
		if(opt >=11)
			break;
		switch(opt){
			case 1:	
				head =  add_begin(head);			   //Add Begin NODE
				break;
			case 2:
				head = add_end(head);		    	   //Add End NODE
				break;
			case 3:
				printf("Enter The Position");
				scanf("%d",&pos);
				head = insert_n_pos(head , pos);	   //Insert nts position
				break;
			case 4:
				printf("Enter The Position");                                   
                scanf("%d",&pos); 
				head = insert_befor_n_pos(head , pos); //Insert Node Before N pos
				break;
			case 5:
				printf("Enter The Position");                                   
                scanf("%d",&pos);                                               
                head = insert_after_n_pos(head , pos); //Insert Node After N Pos                         
                break;
			case 6:
			 	printf("Enter The Number");                                   
                scanf("%d",&num);                                               
                head = insert_befor_num_pos(head , num); //Insert Befor Num Pos                          
                break;
			case 7:
				printf("Enter The Number");                                     
                scanf("%d",&num);                                               
                head = insert_after_num_pos(head , num); //Insert After Num pos                       
                break;
			case 8:
				 head = insert_middle(head);             //Insert At Middle           
                 break;
			case 9:
				head = penultinate_node(head);           //Insert Penultinate Node
				break; 
			case 10:
				display_list(head);						//Display list
				break;
		}  
	}
	return 0;
}
