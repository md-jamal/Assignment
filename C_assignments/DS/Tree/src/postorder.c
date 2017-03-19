#include"btree.h"                                                               
                                                                                
/*TO trvares Tree Postorder*/     
                                                
int postorder(BT *root)                                                           
{                                                                               
    if(root != NULL){                                                           
        postorder(root->left_node_add);                                                                                         
        postorder(root->right_node_add);   
		printf("%4d", root->data);                                       
    }                                                                           
    else                                                                        
        return 0;                                                               
}  
