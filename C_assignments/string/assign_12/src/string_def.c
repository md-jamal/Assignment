void squeeze(char *str , int n)
{
	int i;
	int j;

	for(i = 0, j = 0; i < n; i++,j++)  {
		for(;(str[i] == str[i + 1]) && (str[i + 1] != '\0');i++)
				;
		str[j] = str[i];
	}
	str[j] = '\0';
}
