#include "append.h"
int main()
{
	char *sbuf; //User Input : Source String
	char *dbuf; //User Input : Destination String

	dbuf = (char *)malloc(sizeof(char) * SIZE);
	sbuf = (char *)malloc(sizeof(char) * (SIZE + SIZE));
	printf("Enter the source string::");
	fgets(sbuf , SIZE ,stdin);
	
	printf("Enter the Destination string::");
	fgets(dbuf , SIZE ,stdin);

	if(char_val(sbuf) == 0 && char_val(dbuf) == 0){
		sappend(sbuf , dbuf ,strlen(sbuf));
		printf("\n\nOutput String:");		
		fputs( sbuf, stdout);
		printf("\n");
	}
	else
		printf("Invalid Input Plz check Input\n\n");
	return 0;
}
