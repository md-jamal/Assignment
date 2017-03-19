/*
	Programe : To count word in file.
*/
#include"file.h"

int main()
{
	struct EH e[10];
	FILE *fp = NULL; //File Pointer
	int i = 0; //loop counter
	while(i<2)
	{
		printf("Enter the E_ident");
		scanf("%s",e[i].e_ident);
		i++;
	}
	
	printf("Hii!@");
	file_write(fp , e); 
	return 0;
}
