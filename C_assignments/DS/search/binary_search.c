/*
	Program : To implement Binary Search
	Author : Pritam Krishna Mali.
*/
#include<stdio.h>
#define MAX 5
int main()
{
	int b_arr[MAX];
	int count = 0;
	int mid;
	int low = 0;
	int high = MAX;
	int s_num;

	printf("\nEnter The Data");
	while(count++ < MAX)
		scanf("%d",&b_arr[count]);
	
	printf("\nEnter The Search Num");
	scanf("%d",&s_num);

	while(low <= high){

		mid = (low + high)/2;
		
		if(b_arr[mid] == s_num){
			 printf("\nNumber Found At %d position",mid);
			break;
		}
		else {
			if(s_num < b_arr[mid])
				high = mid - 1;
			else
				low = mid +1;
		}
	}
	if(low > high)
		printf("\nNumber Is Not Found");	
	return 0;
}
