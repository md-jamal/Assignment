/*
	String Case Compare defination
*/

int case_cmp(char *str1 , char *str2)
{
	int i = 0;
	
	
			
	while(*(str1 + i) != '\0' || *(str2 + i) != '\0'){
	
		if((*(str1 + i) == *( str2 + i)) || (*(str1 + i) == *(str2+i) + 32) || (*(str1 + i) == *(str2 + i) + 32) || (*(str2 + i) == *(str1+i) + 32) || (*(str2 + i) == *(str1 + i) + 32))
				;
		else
			break;
		i++;
	}
	if(*(str1 + i) == '\0' && *(str2 + i) == '\0')
		return 0;
	else
		return ((*str1 < * str2) ? -1 : 1);
		
}
