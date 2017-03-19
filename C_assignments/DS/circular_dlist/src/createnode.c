#include"cdlist.h"

/*Create Node Function*/

CDLIST *createnode()
{
	CDLIST *new_node = NULL;			/*New Node Variable*/
	int data = 0;						/*User Input : Data*/

	/*To check Memory Alloction and to assign data to the node*/

	if ( NULL == (new_node = (CDLIST *)malloc(sizeof(CDLIST))) ) {
		printf("\n Malloc Is Failes");
	}
	else {
		printf ("\nEnter The Data");
		data = atoimy();
		new_node->data = data;	
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	return new_node;
}
