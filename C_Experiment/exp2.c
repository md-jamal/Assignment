#include<stdio.h>

int main()
{
	int num[10];
	int i;
	int max = 0;
	printf("\nEnter The Number");
	for(i = 0; i <= 5; i++)
	{
		scanf("%d",&num[i]);
		
		if(max < num[i])
			max=num[i]
	}
	printf("\n Largest Number:%d", max);
	return 0;
}

