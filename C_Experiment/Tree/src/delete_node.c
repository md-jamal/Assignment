#include"btree.h"

/*Delete Node From tree*/

BT *delete_node (BT *root, int data)
{
	BT *temp;					/*Temp variable*/
	
	/*Root is Null*/

	if(root == NULL)
		printf("\nTree Is Empty");
	else{
		
		/*To check data is less than root data*/
		
		if( data < root->data )
			root->left_node_add = delete_node( root->left_node_add, data);
		else{
		
			/*To check data is greater than root data*/
		
			if (data > root-> data)
				root->right_node_add = delete_node(root->right_node_add, data);
			else{

				/*To check left node portion is NULL or Not*/

				if( root->left_node_add == NULL ){
					temp = root->right_node_add;
					free(root);
					return temp;
				}
				else{
					if( root->right_node_add == NULL ){
						temp = root->left_node_add;
						free(root);
						return temp;
					}
					else{                                                             
             					   BT *temp = min_value(temp->right_node_add);                     
            					    root = delete_node(temp->right_node_add,temp->data);            
            				}
				
				}
			}
		}
	}	
	return root;
}
