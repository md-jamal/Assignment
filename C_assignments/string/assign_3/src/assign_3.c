#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#define size 10 
int main()
{
        char *sbuf;
        char *dbuf;

        sbuf = (char *)malloc(sizeof(char) * size);
        
        printf("Enter the source string");
        fgets(sbuf , 50 ,stdin);
        
	if(char_val(sbuf) == 0){
        	printf("%p",(char *)chr_add_instr(sbuf , getchar()));
    
   	     	printf("\n");
		free(sbuf);
	}
	else
		printf("Invalid Input....Plz check");
        return 0;
}

