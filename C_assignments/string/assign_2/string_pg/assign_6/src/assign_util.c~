#include "string_dcrl.h"
int main()
{
	char *sbuf; //User Input : String Buffer
	char *dbuf; //User Input : String Buffer

	sbuf = (char *)malloc(sizeof(char) * SIZE);
	dbuf = (char *)malloc(sizeof(char) * SIZE);
	
	printf("Enter the first string :");
	fgets(sbuf ,  ,stdin);
	
	printf("Enter the second string :");
	fgets(dbuf , 50 ,stdin);
	
	
	if(char_val(sbuf) == 0 && char_val(dbuf) == 0)
	{
		if(strcmp_my(dbuf , sbuf) == 0)
			printf("\nString is Equal");
		else {
			
			if(strcmp_my(dbuf , sbuf) == -1)
				printf("\nstr1 is less than str2\n");
			else
				printf("\nstr1 is greater than str2\n");
		}	 
		
		printf("\n");
	}
	else
		printf("Invalid User Input.......Plz Check");
	return 0;
}
