/*
	Defination of string append..
*/
#include<string.h>
#include<stdio.h>
void  sappend (char *str1, char *str2)
{
	int i = 0;
	int len = strlen(str1);
	
	str1[len--] = str1[len]; 	
	while(str2[i] != '\0'){
		str1[len++] = str2[i];
		i++;
	}	
}
