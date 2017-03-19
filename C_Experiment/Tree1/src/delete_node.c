#include"btree.h"

BT *min_value(BT *node)
{
	BT *current = node;
	while(current->left_node_add != NULL)
		current = current->left_node_add;
	return current;
}
BT *delete_node(BT *root,int key)
{
	if(root == NULL)
		return root;
	printf("Hiiiii");
	if(key < root->left_node_add->data)
		root->left_node_add = delete_node(root->left_node_add, key);
	else {
		if(key > root->right_node_add->data)
			root->right_node_add = delete_node(root->right_node_add,key);
		else{
			if(root->left_node_add == NULL){
				BT *temp = root->right_node_add;
				free(root);
				return temp;
			}
		else{
			if(root->right_node_add == NULL){
				BT *temp = root->left_node_add;
				free(root);
				return temp;
			}
			/*else{
				BT *temp = min_value(temp->right_node_add);
				root = delete_node(temp->right_node_add,temp->data);
			}*/
		}
	}
	return root;

}
}
