/*
	Defination of string append..
*/

void  sappend (char *str1, char *str2 , int n)
{
	int i = 0;
	int len = n;
	
	str1[len--] = str1[len]; 	
	while(str2[i] != '\0'){
		str1[len++] = str2[i];
		i++;
	}	
}
