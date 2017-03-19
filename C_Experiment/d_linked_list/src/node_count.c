/*Count Node*/

#include"dlist.h"

int node_count(dll *head)
{
	dll *temp = head;         
	int count = 0;
                                                   
    if(head == NULL)                                                            
        printf("Linked List is empty");                                         
    else{                                                                                                                       
        while(temp != NULL){                                                    
			count++;                                                      
            temp = temp->next_node;                                                 
        }                                                                       
    }     
	return count;
}
