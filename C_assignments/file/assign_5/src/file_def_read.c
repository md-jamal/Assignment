#include"file.h"


void *file_read()
{
	FILE *f1 = fopen("info.db","rb");
	eh str_pt;
	if(f1 == NULL)
		printf("File is not Exists");
	else{
		rewind(f1);
		while(fread(&str_pt , sizeof(str_pt) , 1 , f1) == 1)
		{
			printf("E_ident::%s\n",str_pt.e_ident);
			printf("E_type::%d\n",str_pt.e_type);
			printf("E_machine%d\n",str_pt.e_version);
			printf("E_version::%d\n",str_pt.e_version);
			printf("E_E_entry::%u\n\n",str_pt.e_entry);
		}
	}
	return 0;
}
