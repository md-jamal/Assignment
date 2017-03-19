#include"btree.h"

/*Insert Node Function of Tree*/

BT *insert_node(BT *root, int data)
{
	BT *new_node = create_node(data);	/*To hold New node Address*/
	BT *temp = root;					/*To hold Root Address*/

	if (root == NULL)
		root = new_node;
	else{
		while (1){
			if (data < temp->data){
				if (temp->left_node_add == NULL){
					temp->left_node_add = new_node;
					break;
				}
				else
					temp = temp->left_node_add;
			}
			else{
				if (temp->right_node_add == NULL){
					temp->right_node_add = new_node;
					break; 
				} 
				else
					temp = temp->right_node_add;
			}
		}
	}
	return root;
}
