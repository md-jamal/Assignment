#include"dlist.h"

/*To create New Node */

dll *create_node()
{
	dll *temp_ptr = (dll *)malloc(sizeof(dll));
	char *_num = (char *)malloc(sizeof(char) * MAX);
	int num;

	if( temp_ptr == NULL || _num == NULL){
		printf("\n\nMalloc Failed");
		return NULL;
	}
	else{
		getchar();
		printf("\nEnter The Data:");
		fgets(_num, MAX, stdin);
		temp_ptr->data = atoi(_num);
		temp_ptr->prev_node = NULL;
		temp_ptr->next_node = NULL;
	}
	return temp_ptr;
}
