#include"string_dcrl.h" 
int main()
{
	char *sbuf;
	char *dbuf;
 
	sbuf = (char *)malloc(sizeof(char) * SIZE);
	dbuf = (char *)malloc(sizeof(char) * SIZE);
	
	printf("Enter the source string::");
	fgets(sbuf, SIZE, stdin);
	
	if (char_val(sbuf) == 0){

		strcpy_my(dbuf, sbuf);
		printf("The Destination String::"); 
		fputs(dbuf, stdout);
		printf("\n");

	}
	else
		printf("Invalid User Input.......Plz Check");
	return 0;
}
