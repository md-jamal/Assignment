#include "string_dcrl.h" 
int main()
{
	char *sbuf;
	char *dbuf;
	char *num;
	sbuf = (char *)malloc(sizeof(char) * SIZE);
	
	num = (char *)malloc(sizeof(char) * SIZE);
	
	
	printf("Enter the source string");
	fgets(sbuf , SIZE ,stdin);

	printf("Enter The Position:");
	fgets(num , SIZE , stdin);	
	if(char_val(sbuf) == 0)
	{
		insertchar(sbuf , getchar() , atoi_1(num) , strlen(sbuf)); 
		fputs(sbuf, stdout);
		printf("\n");
	}
	else
		printf("Invalid User Input.......Plz Check");
	return 0;
}
