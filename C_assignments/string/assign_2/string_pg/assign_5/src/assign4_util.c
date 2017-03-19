#include"append.h" 
int main()
{
	char *sbuf; //User Input : String buffer
	char *dbuf; //User Input : String Buffer
	char *res; //User Input :: Number
	int n;
	dbuf = (char *)malloc(sizeof(char) * SIZE);
	sbuf = (char *)malloc(sizeof(char) * (SIZE + SIZE));
	res  = (char *)malloc(sizeof(char) * SIZE);
	
	printf("Enter the source string:");
	fgets(sbuf , 50 ,stdin);
	
	printf("Enter the Second string:");
	fgets(dbuf , 50 ,stdin);

	printf("Enter the Number :");
	fgets(res , 50 ,stdin);
	
	n = atoi_1(res);
	if(char_val(sbuf) == 0 && char_val(dbuf) == 0)
	{
		snappend(sbuf , dbuf , n);
		printf("Output :: ");		
		fputs( sbuf, stdout);
		printf("\n");
	}
	else
		printf("Invalid Input Plz check Input\n\n");
	return 0;
}
