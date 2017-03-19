/*Count Node*/
#include"list.h"
int node_count(sll *head)
{
	sll *temp = head;         
	int count = 0;
                                                   
    if(head == NULL)                                                            
        printf("Linked List is empty");                                         
    else{                                                                                                                       
        while(temp != NULL){                                                    
			count++;                                                      
            temp = temp->next;                                                 
        }                                                                       
    }     
	return count;
}
