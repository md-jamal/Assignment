#include"btree.h"

/*Create Node Of tree*/

BT *create_node(int data)
{
	BT *new_node = (BT * )malloc( sizeof(BT));
	
	if(new_node == NULL){
		printf("\nMalloc Failed");
		exit(1);
	}
	else{
		new_node->data = data;
		new_node->left_node_add = NULL;
		new_node->right_node_add = NULL; 
	}
	return new_node;
}
