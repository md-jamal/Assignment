#include"btree.h"

/*TO trvares Tree Inorder*/
int inorder(BT *root)
{	
	if(root != NULL){
		inorder(root->left_node_add);
		printf("%4d", root->data);
		inorder(root->right_node_add);
	}
	else
		return 0;
}
