#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
int main()
{
	char *sbuf;

	sbuf = (char *)malloc(sizeof(char) * SIZE);

	printf("Enter the source string::");
	fgets(sbuf , 50 ,stdin);
	
	if(char_val(sbuf) == 0)
	{
		squeeze(sbuf , strlen(sbuf)); 
		printf("\nModified String:");
		fputs(sbuf, stdout);
		printf("\n");
	}
	else
		printf("Invalid User Input.......Plz Check");
	return 0;
}
