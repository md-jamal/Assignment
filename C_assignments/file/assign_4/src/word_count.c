/*
	Defination of Word Count..
*/
#include "file.h"
void word_count(char *fnm , FILE *f1)
{
	int w_count = 0;
	char ch;
	char check = 'X'; // To store previous charcter
	/*Opening File in Reading mode*/
	f1 = fopen( fnm ,"r");
    	if(f1==NULL){
        	 printf("file not found");
      	}
    	else
      	{
        	ch=fgetc(f1);
		if(ch == 32)
			w_count--;
          	while(ch!=EOF){
                	printf("%c",ch);
                        if((ch==' '||ch=='\n') && check != ' ')
				w_count++;
                        
			check = ch;
                        ch=fgetc(f1);
                 }
               	 printf("\nWords in a file are=%d\n",w_count);
     	}
        fclose(f1);
}
