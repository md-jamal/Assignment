#include "file.h"
/*
	Function : search string.
*/

void search_string(char *file_nm , FILE *f1 , char *usr_str)
{

	char ch;
	char *word = NULL;

	int i = 0;
	int line = 1;
	int fp1 = 0;
	int fp2 = 0;
	f1 = fopen(file_nm , "r");
	fp1 = ftell(f1);
	fp2 = ftell(f1);
 
	if(NULL == (word = (char *)malloc(sizeof(char) * MAX)))
	{        
		printf("\nMalloc Is failed");                                                                               
	}  
	
	if(f1 == NULL)
		printf("File Does Not Exists");
	else
	{
			while((ch = getc(f1)) != EOF)
			{	
				if(ch == '\n')
					fp1 = fp2;
				if(ch != ' ' && ch != '\n')
				{
					*(word + i++) = ch;
				}
				else
				{
						
					*(word + i++) = '\0';
					i = 0;
		
           			 	if(case_cmp(word , usr_str) == 0)
						{
              					 printf("\nString Found at line number %d\n",line);
					   			fseek(f1 , -(fp1+1) , SEEK_CUR);
								  while((ch = getc(f1)) != '\n')
										printf("%c",ch);
		//						break;  
						}
						(ch == 10) ? line++ : line ;
				}
				fp2 = ftell(f1);
				printf("%d%d",fp1,fp2);
			} 
	}	
	free(word);
}
