#include<stdlib.h>
#include<stdio.h>

/*Macro*/

#define MAX 50
typedef struct DNODE
{
	struct DNODE *prev_node;	/*To hold previous Node Address*/
	int data;					/*To Store Data*/
	struct DNODE *next_node;	/*To Hold next Node Address*/
}dll;

/*Function Declaration*/

dll *create_node();
dll *insert_menu(dll *);

/*Insert Node Declaration*/
dll *insert_begin(dll *);
dll *insert_end(dll *);
dll *insert_befor_n_pos(dll * , int);
dll *return_pos_node(dll *, int);

/*Delete Node*/
dll *delete_begin(dll *);
dll *delete_end(dll *);
dll *delete_n_pos(dll *, int);

int node_count(dll *);
void display(dll *);
