#include"ins.h"

int insertion_sort(int *arr)
{
	int i;
	int j;
	int min;
	int temp;


	for(i = 1; i < MAX; i++){
			temp = arr[i];
		for(j = (i-1); j >= 0; j--){
			if(arr[j] > temp)
				arr[j+1] = arr[j];
			else
				break; 
		}			
		arr[j+1] = temp;
	}

	printf("\nData::");                                                 
    for(i = 0; i < MAX; i++)                                                    
        printf("%d ",arr[i]);
	return 0;
}
