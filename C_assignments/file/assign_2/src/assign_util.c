/*
	Programe : To convert character upper to lower in given file.
*/
#include"file.h"

int main(int argc , char *argv[])
{
	FILE *fp = NULL; //File Pointer
	char *src_word;
	int len = 0;
	int i = 0;
    

	if(NULL == (src_word = (char *)malloc(sizeof(char) * MAX)) ){            
                printf("\nMalloc Is failed OR String is invalid");                                                                                             
    }    
	else{
			printf("Enter The Search String:");                                         
    		fgets(src_word , MAX ,stdin);                                               
  			len = strlen(src_word);                                                     
   			src_word[--len] = '\0';     //To remove Enter character                     
                                                                   
		 search_string(argv[1] , fp , src_word);
	}
	return 0;
}
