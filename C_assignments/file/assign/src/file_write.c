/*
	Defination of Write data to info.db file....
*/
#include "file.h"
void file_write(FILE *f1 , struct EH *e)
{
	int i = 0; //loop Counter

	/*Opening File in Reading and writing mode*/
	f1 = fopen( "info.db" ,"rb+");
    	if(f1==NULL){
        	 printf("file not found");
      	}
    	else
      	{
			f1 = fopen("info.db" , "wb");
			printf("File info.db created..\n");
       	}
	printf("HII");
	while(i < 2){
		fwrite(&e[i] , sizeof(e) , 1 , f1);
		i++;
	}
        fclose(f1);
}
