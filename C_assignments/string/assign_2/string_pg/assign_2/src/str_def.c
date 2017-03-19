/*
	String N copy chrachter function Defination
*/
void stcpy_n_my(char *dest , char *src ,int n)
{
	int i = 0;
	
	while((i < n) && (*src != '\0')){
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
}
