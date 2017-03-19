#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int atoimy()
{
	int i;
	char r[100];
	char p[100];
	int t=0;
	int res=0;
	int flag = 2;
	char *s = (char *)malloc(sizeof(char) * MAX);
	fgets(s, MAX, stdin);	
	fgets(s, MAX, stdin);

	if(s[0] == '+'){
	flag = 1;
	t++; }
	if(s[0] == '-'){
	flag = 0;
	t++; }
	for(i=t;i<strlen(s)-1;i++){
		if((s[i] >= '0' && s[i]  <= '9')){
			
			res = (res * 10) + s[i] - '0' ;
		}
		else{
			printf("enter valid input\n");
			res = atoimy();
			return res;
		}
		
	}
	
	if(flag == 1)
		res = res;
	if(flag == 0)
		res = (~res)+1;
	if(res >= -2147454576 && res <= 214745456 )
		return res;
	else {
		printf("input out of range enter valid \n");
		res=atoimy();
		return res;
	}
}
