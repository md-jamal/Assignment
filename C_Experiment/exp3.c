#include<stdio.h>
#if 0
int main()
{
	int num[5];
	int i = 0;
	int sum = 0;
	printf("\nEnter the Data:");
	
	for(i=0; i<5; i++){
		scanf("%d",&num[i]);
		sum += num[i];
	}
	printf("Sum :%d\n",sum);
	
	return 0;
}
#endif

#if 0
int main()
{
	int a = 0;
	int b = 1;
	int c = 0;
	int num = 0;
	int i = 0;	
	printf("\nEnter the Number:");
	scanf("%d",&num);
	
	printf("%d\t%d\t",a,b);
	for(i = 0; i <= num; i++){
		c = a + b;
		printf("%d\t",c);
		a = b;
		b = c;
	}
}
#endif

#if 1
int main()
{
	int arr[2][2];
	int i = 0;
	int j = 0;

	for(i=0; i < 2; i++){
		for(j=0; j < 2; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0; i < 2; i++){
		for(j=0; j < 2; j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

	
	


}
#endif
