/*
	String Case Compare defination
*/

int case_cmp(char *s1 , char *s2)
{
	int i = 0;
	
	
			
	while(*s1 != '\0' || *s2 != '\0'){
	
	/*	if((*(str1 + i) == *( str2 + i)) || (*(str1 + i) == *(str2+i) + 32) || (*(str1 + i) == *(str2 + i) + 32) || (*(str2 + i) == *(str1+i) + 32) || (*(str2 + i) == *(str1 + i) + 32))
				;
		else
			break;
		i++;
	}*/
		if(!(*s1++ == *s2++) )
		{
			if(((*s1 + 32) == *s2) || ((*s1-32) == *s2) || (*s1 == (*s2+32)) || *s1 == (*s2-32)  ||(*s2 + 32) == *s1 || (*s2-32) == *s1) 
				;
			else
				break;
		}
}
	if(*(s1) == '\0' && *(s2) == '\0')
		return 0;
	else
		return ((*s1 < * s2) ? -1 : 1);
		
}
