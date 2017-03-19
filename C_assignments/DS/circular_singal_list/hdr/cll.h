#include<stdio.h>
#include<stdlib.h>

/*Macro*/

#define MAX 50

typedef struct NODE
{
	int data;
	struct NODE *next;
}cll;

/*Global Varible Declar*/

cll *create_node();

/*Function declaration*/

cll* add_begin(cll *);  
cll* delete_begin(cll *);
void display(cll *);
