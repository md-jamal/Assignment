void str_rev(char *sbuf , int n)
{
	int i = 0;
	int j = n;	
	char tmp;

	sbuf[--j] = sbuf[j];
	j--;
		
	while(i < j)
	{
		tmp = sbuf[i];
		sbuf[i] = sbuf[j];
		sbuf[j] = tmp;
		i++;j--;
	}
		
}


