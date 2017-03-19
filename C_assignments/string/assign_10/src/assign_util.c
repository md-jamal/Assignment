#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10 
int main()
{
	char *sbuf;
	char *dbuf;

	sbuf = (char *)malloc(sizeof(char) * size);
	dbuf = (char *)malloc(sizeof(char) * size);
	
	printf("Enter the source string");
	fgets(sbuf , 50 ,stdin);

		
	if(char_val(sbuf) == 0)
	{
		if(str_pal(sbuf , dbuf , strlen(sbuf)) == 0)
			printf("\nEnter the String palindrom");
		else
			printf("Enter the string not palindrom"); 
		printf("\n");
	}
	else
		printf("Invalid User Input.......Plz Check");
	return 0;
}
