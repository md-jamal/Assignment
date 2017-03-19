#include<stdio.h>
/*
	Program : 2D Array Addition
*/
#if 0
int array_addi(int a[][] , int b[][n]);
int main()
{
	int a[3][3];
	int b[3][3];
	int res = 0;
	
	if(array_addi(a , b))
		printf("\nPrograme Successful");
	else
		printf("\nPrograme Not Execute");

	return 0;
}	

/*Addition of Array*/
/*int array_addi(int a[][n] , int b[][n])
{
	int i = 0;	
	int j = 0;

	printf("\nEnter First Matrix Number");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nEnter Second Matrix Number");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			scanf("%d",&b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif

#if 1
int main()
{
        int a[2][2]; //First Array
        int b[2][2]; //Second Array
        int i = 0;   //simple var
        int j = 0;   //simple var

        printf("\nEnter First Matrix Number");
        for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                        scanf("%d",&a[i][j]);
                }
                printf("\n");
        }
        
        printf("\nEnter Second Matrix Number");
        for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                        scanf("%d",&b[i][j]);
                }
                printf("\n");
        }
	
	printf("Addition of Matrixes");
	printf("\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d\t", a[i][j] + b[i][j]);
		}
		printf("\n");
	}
        return 0;
}
#endif
	
