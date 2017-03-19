
#include<stdio.h>
size_t strspn_my(const char *buf1 , const char *buf2 , size_t cnt)
{
	int i = 0;
	int j = 0;
		
	while(*buf1 != '\0'){
		j = 0;
		while(*buf2 != '\0'){
			if(*(buf1 + i) == *(buf2 + j))
				cnt++;
			j++;	 
		}	
		i++;	
	}
	return cnt;
}
	
