#include<stdio.h>                                                               
#include<string.h>                                                              
#include<stdlib.h> 
    
/*Macro For Input*/                                                         
#define MAX 50              
#define SIZE 1
                                                    
/*Structure Of EH */                                                            
typedef struct EH                                                                       
{                                                                               
    unsigned char e_ident[16];                                                  
    short e_type;                                                               
    short e_machine;                                                            
    int e_version;                                                              
    unsigned int e_entry;                                                       
}eh;

eh *file_write();      
void *file_read();                          
