/*
	Programe : String N copy Chrcter Programe
	Author : Pritam Krishna mali.
*/
#include "strcpy_n_my.h"
 
int main()
{
	char *sbuf;
	char *dbuf;
	char *num;
	sbuf = (char *)malloc(sizeof(char) * SIZE); // User Input : String One Buf
	dbuf = (char *)malloc(sizeof(char) * SIZE); // User Input : String Buffer input
	num = (char *)malloc(sizeof(char) * SIZE); // User Input : Number input
	
	printf("Enter the source string");
	fgets(sbuf , SIZE ,stdin);
	
	printf("Enter the Number ::");
	fgets(num , SIZE ,stdin);
	
	if(char_val(sbuf) == 0)
	{
		stcpy_n_my(dbuf ,sbuf ,atoi_1(num));
		printf("Result String ::");
		fputs(dbuf, stdout);
		printf("\n");
		free(sbuf);free(num);free(dbuf);
	}
	else
		printf("Invalid Input Plz check Input\n\n");
	return 0;
}
