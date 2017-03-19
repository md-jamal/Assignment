#include<stdio.h>

void strcpy_my(char *dbuf ,char *sbuf)
{
	int i=0;

	while((dbuf[i] = sbuf[i]) != '\0')
		i++;
} 


