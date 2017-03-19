#include "file.h"
/*
	Function : To convert character upper to lower.
*/
void upper_to_lower(char *file_nm , FILE *f1)
{

	char ch;
	
	f1 = fopen(file_nm , "r+");
	if(f1 == NULL)
		printf("File Does Not Exists");
	else{
		while((ch = getc(f1)) != EOF){
			(ch >=65 && ch <= 92) ? ch = ch + 32 : ch;
			fseek(f1 ,-1 , SEEK_CUR);
			putc(ch , f1);	
		}
	}
}
