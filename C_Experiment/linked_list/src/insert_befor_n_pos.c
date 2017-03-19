/*Insert Node Before N position*/
#include"list.h"
sll *insert_befor_n_pos(sll *head , int key)
{
	sll *new_node = create_node_file(key);
        sll *temp = head;

        if(head == NULL){
                head = new_node;
        }
        else{
                //if ( head->next == NULL ){
                        if(head->data < key ){
                                head->next = new_node;
				return head;
			}
                        else{
                                new_node->next = new_node;
                                head = new_node;
				return head;
                        }
                        printf("HH%d",head->data);
                        while((temp->next)->data > key && (temp)!= NULL )
                                temp = temp->next;
                        new_node->next = temp->next;
                        temp = new_node;
                
        }
        return head;

}
