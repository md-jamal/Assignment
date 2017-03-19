#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* Show The bit in 31BIT Format */
int show_bit(int a_no)
{
	int i = 0;
		
	for(i=31; i>=0; i--)
	{
		printf("%d",(1 & (a_no >> i)));
	}
	return 0;
}
/*to convert char to int*/
int atoi_1(char s[])
{
	int i;
	int n = 0;	

	for(i = 0; i < strlen(s) -1; i++){
		if(((s[i] >= '0') && (s[i] <= '9')) || (s[0] == '-')){
			if(s[0] != '-')	
				n = (10 * n) + (s[i] - '0');
		}
		else
		{
			printf("Invalid Input.....Plz Check\n\n");
			exit(0);
		}
	}
	return n;
	
}

int char_val(char ch[])
{
	int i = 0;

	for(i = 0; i < strlen(ch); i++){
		if((ch[i] >= '0' && ch[i] <= '9') || (ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] == 32)){
			if(ch[0] == 32 || (ch[i] == 32 && ch[i+1] == 32 ))
				break;			
		}
		else
			break;
	}
	
	if(ch[i+1] == '\0')
		return 0;	
	else
		return 1;
	return 0;	
}

