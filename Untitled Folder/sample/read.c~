#include<stdio.h>
struct EH
{
	unsigned char e_ident[16];
	short e_type;
	short e_machine;
	int e_version;
	unsigned int e_entry;
};

int main()
{
	FILE *f1 = fopen("info.db","rb");
	struct EH e;
	while((fread(&e , sizeof(e) , 0 , f1)) != -1)
	{
		printf("E_ident%s",e.e_ident);
	}
	return 0;
}
