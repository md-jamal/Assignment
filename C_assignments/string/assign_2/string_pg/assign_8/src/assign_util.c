#include<stdio.h>
#include<stdlib.h>
#define SIZE 50 
int main()
{
	char *sbuf;
	char *dbuf;
	size_t res;
	sbuf = (char *)malloc(sizeof(char) * SIZE);
	dbuf = (char *)malloc(sizeof(char) * SIZE);
	
	printf("Enter the source string");
	fgets(sbuf , SIZE ,stdin);
	
	printf("Enter the source string");
	fgets(dbuf , SIZE ,stdin);
	
	printf("Hiii");
	if(char_val(sbuf) == 0 && char_val(dbuf) == 0)
	{
		printf("%d" , strspn_my(dbuf , sbuf , res)); 
		printf("\n");
	}
	else
		printf("Invalid User Input.......Plz Check");
	return 0;
}
