#include"bub.h"

int bubble_sort(int *arr)
{
	int i;
	int j;
	int temp;

	for(i = 0; i < MAX-1; i++){
		for(j = 0; j < MAX-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp; 
			}
		}
	}
	printf("\nData::");                                                 
    for(i = 0; i < MAX; i++)                                                    
        printf("%d ",arr[i]);
	return 0;
}
