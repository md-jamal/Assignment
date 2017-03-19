/*Insert Node After Given Number*/
#include"list.h"
sll *insert_after_num_pos(sll *head , int num)                                  
{                                                                               
    sll *tmp_ptr = head;                                                        
    sll *prev_add = NULL;                                                       
    sll *new_node = NULL;                                                       
    sll *next_add = NULL;                                                       
                                                                                
    while(tmp_ptr != NULL){                                                     
        if(num == (tmp_ptr->data))                                              
        	break;                                                              
        else                                                                  
           	tmp_ptr = tmp_ptr->next;                                                                            
    }                                                                           
    if(tmp_ptr == NULL)                                                         
        printf("Your number Not Found In Linked List");                         
    else{                                                                       
        if((tmp_ptr->next) == NULL)                                                    
            head = add_end(head);                                             
        else{                                                                   
            new_node = create_node();                                           
            next_add = tmp_ptr->next;                                          
            tmp_ptr->next = new_node;                                          
            new_node->next = next_add;                                          
        }                                                                       
    }                                                                           
    return head;                                                                
}
