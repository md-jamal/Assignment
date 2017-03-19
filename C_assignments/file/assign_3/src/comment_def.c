#include"comment.h"

/*Definition Of emove Comment*/

void remove_comment()
{
	FILE *fp = fopen("sample.txt","r+");
	char ch;
	int count = 0;
	if(fp == NULL)
		printf("file Not Found");
	else{
		while(!feof(fp)){
			if(ch = fgetc(fp)== '/' && (ch = fgetc(fp)) == '/'){
				fseek(fp , -2 , SEEK_CUR);
				while(!feof(fp)){
					ch = fgetc(fp);
					if(ch == '\n')
						break;
					fseek(fp , -1 , SEEK_CUR);
					fputc(' ', fp);
				}
			}
			if(ch = fgetc(fp) == '/' && (ch = fgetc(fp) == '*')) {
				while(!feof(fp)){
					if((ch = fgetc(fp)) != '*' && (ch = fgetc(fp)) != '/')
						count++;
					else
						break;
				}		
				fseek(fp , -(count + 2) , SEEK_CUR);
				while(!feof(fp)){
					ch = fgetc(fp);
					if(ch == '\n')
						break;
					fseek(fp , -1 , SEEK_CUR);
					fputc(' ',fp);
				}
			}		
		}	
	}
}
