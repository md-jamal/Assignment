#include"btree.h"                                                               
                                                                                
/*TO trvares Tree Preorder*/    
                                                 
int preorder(BT *root)                                                           
{                                                                               
    /*if(root != NULL)*/if(root->left_node_add != NULL){  
		printf("%4d", root->data);                                                         
        preorder(root->left_node_add);                                                                                         
        preorder(root->right_node_add);                                          
    }                                                                           
    else                                                                        
        return 0;                                                               
} 
