/*
	programe::Return address of given character 
*/
#include"cha_add_instr.h"
int main()
{
        char *sbuf; //User Input :: String Buffer
        char *dbuf; //User Input :: String Buffer

        sbuf = (char *)malloc(sizeof(char) * SIZE);
        
        printf("Enter the source string ::");
        fgets(sbuf , SIZE ,stdin);
        
	 printf("Enter the Chracter ::");
	if(char_val(sbuf) == 0){
        	printf("%p",(char *)chr_add_instr(sbuf , getchar()));
    
   	     	printf("\n");
		free(sbuf);
	}
	else
		printf("Invalid Input....Plz check\n\n");
        return 0;
}

