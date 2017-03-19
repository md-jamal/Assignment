#include"file.h"

/*Function Writing Data To the info.db File*/

eh *file_write()
{
	eh ptr_eh;
	int i = 0;
	int j = 0;
	char e_type[20];                                                               
    char e_machine[20];                                                            
    char e_version[20];                                                              
   	char e_entry[20];

	FILE *fp = fopen("info.db","rb+");
	
	if(fp == NULL){
		fp = fopen("info.db","wb");
		printf("\nInfo.db File created\n");
	}

	fseek(fp , 0 , SEEK_END);

	printf("Write:%d",ftell(fp));
	while(i < SIZE){
		printf("Enter The E_ident::");
		fgets(ptr_eh.e_ident , MAX , stdin);
		ptr_eh.e_ident[strlen(ptr_eh.e_ident) - 1] = '\0';
		printf("\n%s",ptr_eh.e_ident );
		printf("\nEnter The Type::");
		fgets(e_type, MAX , stdin);
		ptr_eh.e_type = atoi_my(e_type);
		printf("\n%d",ptr_eh.e_type);

		printf("\nEnter The E_machine::");
		fgets(e_machine , MAX ,stdin);
		ptr_eh.e_machine = atoi_my(e_machine);

		printf("\nEnter The E_version::");
		fgets(e_version ,MAX ,stdin);
		ptr_eh.e_version = atoi_my(e_version);

		printf("\nEnter The E_entry");
		fgets(e_entry , MAX , stdin);
		ptr_eh.e_entry = atoi_my(e_entry);

		fwrite(&ptr_eh , sizeof(ptr_eh) , 1 ,fp);
		i++;
	}
	
//	return ptr_eh;
}
