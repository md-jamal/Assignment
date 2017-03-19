#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdio_ext.h>
#include<limits.h>

#define MAX 64
#define INVALID printf("\n*****ENTERED INVALID INPUT****\n\n")

int valid(void)
{
	char *a;
	int i = 0;
	double num = 0;
	int flag = 1;
	int j = 0;
	int k = 0;
	while(1){
		i = 0; 
		num = 0;
		flag = 1; 
		
		if((a = malloc(sizeof(char) * MAX)) == NULL) {
			printf("malloc is failled \n");
			exit(1);
		}

		__fpurge(stdin);
		memset(a, '\0', MAX);	

		fgets(a, MAX, stdin);
		
		if(*(a + strlen(a) - 1) == '\n'){
			*(a + strlen(a) - 1) = '\0';
		}


		while((a[i] == ' ') && (a[i] != '\0'))
			i++;

		if(a[i] == '\0') {
			INVALID;
			free(a);
			continue;
		}

		if(a[i] == '-') {   
			i++;
			flag = -1;
		}
		else if(a[i] == '+'){ 
			i++;
			flag = 1;
		}
		for(j = i; a[j]; j++) {
			if(a[j] >= '0' && a[j] <= '9')
				num = num * 10  + (a[j] - '0');
			else if(a[j] == '.') {
				for(k = j + 1; a[k]; k++) {
					if(a[k] < '0' || a[k] > '9') {
						INVALID;
						free(a);
						a = NULL;
						break;	
					}
				}
				break;
			}		
			else {
				INVALID;
				free(a);
				a = NULL;
				break;
			}
		}
			if(NULL == a)
			continue;

		num = (flag == -1) ? (num * -1) : (num * 1);

		if((num >= INT_MIN) && (num <= INT_MAX)) {
			free(a);
			return (int)num;
		}
		else{
			printf("\ninteger out of range \n");
			printf("int range from -2147483648 to 214748367 \n");
			free(a);
			continue;
		}
	}
} 	




