#include "ins.h"

int main()
{
	int arr[MAX];
	int i = 0;

	printf("\nEnter The Data");
	for(i = 0; i < MAX; i++)
		scanf("%d",&arr[i]);
	
	insertion_sort(arr);
	return 0;
}
