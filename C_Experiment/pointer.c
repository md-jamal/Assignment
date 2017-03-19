#include <stdio.h>

int main()
{
	char *arr[10][10] = {"pritam" , "yogesh", "Trupti" , "Sonam"};
	
	printf("%d\n",sizeof(arr));
	printf("%c\n",*arr);
	printf("%c\n",*(*(arr+1)+1));
	return 0;
}
