/*	Program:   Given a string “Global Edge” in a character buffer sbuf, 
 *  		   write a function void strncpy(char *dbuf, char, sbuf, int n) 
 *			   to copy n characters from character buffer sbuf to character 
 *			   buffer dbuf
 *
 *	Author:		Pritam Mali.
 */

#include"strcpy_n_my.h"
 
int main()
{
	char *sbuf;     	/*USER INPUT: Source String Buffer*/
	char *dbuf;			/*Destination String Buffer*/

	sbuf = (char *)malloc(sizeof(char) * SIZE);
	dbuf = (char *)malloc(sizeof(char) * SIZE);

	if (sbuf == NULL && dbuf == NULL){
		printf("Malloc Failed");
		return 0;
	}
	printf("Enter the source string");
	fgets(sbuf, SIZE, stdin);

	if (char_val(sbuf) == 0){
		printf("\nEnter the No of Chracter");
		stcpy_n_my(dbuf, sbuf, atoimy());
		printf("Destination String:");
		fputs(dbuf, stdout);
		printf("\n");
	}
	else
		printf("Invalid Input Plz check Input");
	return 0;
}
