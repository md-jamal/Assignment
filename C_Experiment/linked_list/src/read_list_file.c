#include"list.h"

sll *read_list_file(sll *head)
{
	FILE *fp;
	sll *temp = head;
	fp = fopen("slist.dat","rb");
	int data = 0;

	if(fp == NULL)
		printf("\nFile Does Not Exist");
	else{
	//	while(temp != NULL)		
		printf("\nData:");
		while(fread(&data , sizeof(data),1,fp) == 1)
			head = add_end_file(head,data);
	}
	fclose(fp);
	return head;
}
