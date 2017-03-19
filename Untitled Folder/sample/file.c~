#include<stdio.h>
#define MAX 50
struct EH
{
	unsigned char e_ident[16];
	short e_type;
	short e_machine;
	int e_version;
	unsigned int e_entry;
};
void file_write(struct EH e[]);
int main()
{
	struct EH e[2];
	int i = 0;
	char e_type[20];                                                               
    char e_machine[20];                                                            
    char e_version[20];                                                              
   	char e_entry[20];
	
	while( i < 2){
		printf("Enter The E_ident::");
		fgets(e[i].e_ident , MAX , stdin);

		printf("\nEnter The Type::");
		fgets(e_type, MAX , stdin);
		e[i].e_type = atoi_my(e_type);

		printf("\nEnter The E_machine::");
		fgets(e_machine , MAX ,stdin);
		e[i].e_machine = atoi_my(e_machine);

		printf("\nEnter The E_version::");
		fgets(e_version ,MAX ,stdin);
		e[i].e_version = atoi_my(e_version);

		printf("\nEnter The E_entry");
		fgets(e_entry , MAX , stdin);
		e[i].e_entry = atoi_my(e_entry);

		i++;
	}
	file_write(e);
}
void file_write(struct EH e[])
{
	int i = 0;
	FILE *f1 = NULL;
	
	f1 = fopen("info.db" , "rb+");
	
	if(f1 == NULL){
		f1 = fopen("info.db" , "wb");
		printf("File info.db Created");
	}
		while(i++ < 2)
			fwrite(&e[i] , sizeof(e[i]), 1 , f1);

}

