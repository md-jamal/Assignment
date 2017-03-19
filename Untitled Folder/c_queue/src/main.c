#include "header.h"                                                             
                                                                                
int main()                                                                      
{                                                                               
    int option;                                                                 
    int element;                                                                
    char *str;
	count = 0;                                                                  
    front = -1;                                                                 
    rear = -1;                                                                  
    str = (char *)malloc(sizeof(char)*MAX);                                     
    while (1) {                                                                 
                                                                                
    printf("enter 1 for enqueue\nenter 2 for dequeue\nenter 3 for display\n");         
    printf("enter 4 to exit\n");                                                
                                                                                
    fgets(str,MAX,stdin);                                                       
    option = atoi(str);                                                         
                                                                                
    switch(option) {                                                            
                                                                                
        case 1:                                                                 
                printf("enter the element to be enqueued\n");                   
                fgets(str,MAX,stdin);                                           
                element = atoi(str);                                            
                enqueue(element);                                               
                break;                                                          
        case 2:                                                                 
                element = dequeue();                                            
                printf("the element dequeued is: %d\n",element);                
                break;                                                          
        case 3:                                                                 
                display();                                                      
                break;                                                          
                                                                                
        case 4:                                                                 
                return 0;                                                       
        default :                                                               
                printf("entered wrong option\nplease enter correct option\n");  
                                                                                
        } 
	}
	return 0;
}
