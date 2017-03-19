#include"list.h"

void write_list_file(sll *head)
{
	FILE *fp;
	sll *temp = head;
	int d;
	fp = fopen("slist.dat","wb");

	fseek(fp , 0 ,SEEK_END);
	while(temp != NULL){
		fwrite(&temp->data, sizeof(temp->data), 1, fp);
		temp = temp->next;
	}
	fclose(fp);
}
