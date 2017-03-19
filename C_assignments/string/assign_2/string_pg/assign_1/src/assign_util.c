/*
	Programe : 
	Author :Pritam krishna Mali.	

*/

#include "string_dcrl.h" 
int main()
{
	char *sbuf; /*User Input : First String Buffer*/
	char *dbuf; /*User Input : Second String Buffer*/

	sbuf = (char *)malloc(sizeof(char) * SIZE);
	dbuf = (char *)malloc(sizeof(char) * SIZE);
	
	printf("Enter the source string::");
	fgets(sbuf , SIZE ,stdin);
	
	if(char_val(sbuf) == 0)
	{
		strcpy_my(dbuf , sbuf);
		printf("\nStrring Copy::"); 
		fputs(dbuf, stdout);
		printf("\n");
		free(sbuf);
		free(dbuf);
	}
	else
		printf("Invalid User Input.......Plz Check\n\n");
	return 0;
}
