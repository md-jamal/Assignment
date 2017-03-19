#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int strindex(const char *, char);
int main( void )
{
	char *str;
	char ch;
	int CHK;
	if(NULL == (str = (char *) malloc(sizeof(char) * MAX)))
		printf("\nMalloc Failed");
	else
	{
		printf("\nEnter The String:");
		fgets(str, MAX, stdin);
		printf("\nEnter The Char:");
		ch = getchar();			
		if(strindex(str,ch)!= -1)
			printf("Index Position %d",(CHK = strindex(str,ch)));
		else
			printf("Char Not Found");
	}
}

int strindex(const char *str, char ch)
{
	int len = strlen(str);
        int i = 0;
        for(i=len; i >= 0; i--){
        	if(str[i]==ch)
			return i;
	}
	if(i == -1)
		return -1;

}
