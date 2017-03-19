#include<stdio.h>
#include<stdlib.h>

/*Macro*/
#define MAX 50

typedef struct btree
{
	struct btree *left_node_add;		/*To Hold Left Node Address*/
	int data;							/*USER INPUT : Data*/
	struct btree *right_node_add;		/*To Hold Right Node Address*/
}BT;

/*Function Declaration */

BT *insert_node(BT *, int);
BT *create_node(int);
int inorder(BT *);
