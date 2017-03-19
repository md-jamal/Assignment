#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct s_list
{
	int data; 				/*	User DATA */
	struct s_list *next;	/*To Keep The Next Address Of s_list*/
}sll;

/*Global Varible Declar*/

sll *getlast_node();	
sll *create_node();

/*Function declaration*/

sll* add_begin(sll *);  
sll* add_end(sll *);
int node_count(sll *);
sll* return_pos_node(sll * , int pos); 
sll* insert_n_pos(sll *, int pos);
sll* insert_befor_n_pos(sll *, int pos);
sll* insert_after_n_pos(sll *, int pos);
sll* insert_befor_num_pos(sll *, int num);
sll* insert_after_num_pos(sll *, int num);
sll* insert_middle(sll *);
sll* penultinate_node(sll *); 
void display_list(sll *);
int menu();


/*Delete Function*/
sll *delete_begin(sll *);
sll *delete_end(sll *);
sll *delete_n_pos(sll *, int);
sll *delete_befor_n_pos(sll *, int);
sll *delete_after_n_pos(sll *, int);
sll *delete_befor_num_pos(sll *, int);
sll *delete_after_num_pos(sll *, int);
sll *delete_at_middle(sll *);
sll *delete_penultinate_node(sll *);

/*File Operation*/
void write_list_file(sll *);
sll *read_list_file(sll *);
sll *create_node_file(int);
sll *add_end_file(sll *,int);
