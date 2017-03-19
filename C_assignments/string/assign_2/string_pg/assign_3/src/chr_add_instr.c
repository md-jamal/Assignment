/*
	Return address of character function declaration
*/
char *chr_add_instr(char *buf , char ch)
{
	int i=0;
 
	while(buf[i] != ch && buf[i] != '\0')
		i++;
	if(buf[i]=='\0')
		return '\0';
	else
		return &(buf[i]);
}
