void  insertchar (char *str, const char ch, int pos , int len)

{
	while(pos != len)
	{
		*(str + (len +1)) = *(str + len);
		len--;
	}
	*(str + len) = ch;

}







 


