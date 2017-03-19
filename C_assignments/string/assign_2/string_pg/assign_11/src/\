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
		str_rev(sbuf , strlen(sbuf));
		printf("Reverse String : ");
		fputs(sbuf , stdout); 
		printf("\n");
	}
	else
		printf("Invalid User Input.......Plz Checki\n");
	return 0;
}
