#include<stdio.h>
#include<stdlib.h>

typedef struct STKLINK
{
	int data;
	struct STKLINK *next;
}stl;
	
stl *create_node();
stl *push(stl *);
stl *pop(stl *);
void display(stl *);
