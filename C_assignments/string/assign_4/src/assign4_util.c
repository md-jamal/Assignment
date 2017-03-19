#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 
int main()
{
	char *sbuf;
	char *dbuf;
	char *res;
	dbuf = (char *)malloc(sizeof(char) * SIZE);
	sbuf = (char *)malloc(sizeof(char) * (SIZE + SIZE));
	printf("Enter the source string");
	fgets(sbuf , 50 ,stdin);
	
	printf("Enter the source string");
	fgets(dbuf , 50 ,stdin);

	if(char_val(sbuf) == 0 && char_val(dbuf) == 0)
	{
		sappend(sbuf , dbuf);		
		fputs( sbuf, stdout);
		printf("\n");
	}
	else
		printf("Invalid Input Plz check Input");
	return 0;
}
