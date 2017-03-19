#include "header.h"                                                             
                                                                                
void display()                                                                  
{                                                                               
    int i = front;
	int temp;
	temp = count;
	                                                                      
    if ( count == 0 ) {
		printf("the queue is empty\n");
	//	exit(0);
	} 
	else {                                                                            
   		printf("the elements in the queue are\n");                                  
    	while ( temp ) {   
			if ( i == MAX - 1 )
			i = -1;
			i ++;                                     
        	printf("%d\t",queue[i]); 
			temp --;  
		}                                             
        	printf("\n");                                                           
	}
}   
