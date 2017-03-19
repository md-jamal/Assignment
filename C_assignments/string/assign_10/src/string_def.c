int str_pal(char *sbuf , int *dbuf , int n)
{
	int i = 0;
	int j = n;	
	char tmp;

	sbuf[--j] = sbuf[j];
	j--;
	strcpy_my(dbuf, sbuf);		
		
	while(i < j)
	{
		tmp = sbuf[i];
		sbuf[i] = sbuf[j];
		sbuf[j] = tmp;
		i++;j--;
	}
	
	if(strcmp(sbuf,dbuf)== 0)
		return 0;
	else
		return 1;

		
}


