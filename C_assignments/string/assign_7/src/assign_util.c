/*
	PROGRAME : String Comapre ignoring case
	Author :Pritam Krishna Mali
*/

#include "str_decrl.h"
int main()
{
	char *sbuf = NULL; //User Input : String 1
	char *dbuf = NULL; //User Input : String 2

	sbuf = (char *)malloc(sizeof(char) * SIZE);
	dbuf = (char *)malloc(sizeof(char) * SIZE);
	
	printf("Enter the first string :");
	fgets(sbuf , SIZE ,stdin);
	
	printf("Enter the second string:");
	fgets(dbuf , SIZE ,stdin);
	
	
	if(char_val(sbuf) == 0 && char_val(dbuf) == 0){
		if(case_cmp(dbuf , sbuf) == 0)
			printf("\nString is Equal");
		else 
			(case_cmp(dbuf , sbuf) == 1) ? printf("\nstr1 is greater than str2\n") : printf("\nstr1 is less than str2\n");
		printf("\n");
	}
	else
		printf("Invalid User Input.......Plz Check.....Plz run again\n\n");
	return 0;
}
