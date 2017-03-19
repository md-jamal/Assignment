#include<stdio.h>
#include<stdlib.h>

/*Macro*/

#define MAX 50

/*Structure of circular Double linked list*/

typedef struct cdlist {
	struct cdlist *prev;			/*To keep address of previous node*/
	int data;						/*To store User Data*/
	struct cdlist *next;			/*To keep address of next node*/
}CDLIST;

/*Declaration of Function*/
CDLIST *createnode ();
CDLIST *insert_node (CDLIST *);
CDLIST *delete_node (CDLIST *);
int display_list (CDLIST *);

