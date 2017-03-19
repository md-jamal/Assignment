int main()
{
	int i = 0;
	int j = 0;
	char str[10];
	int count = 0;

	char ch;

	scanf("%s",str);
	while((*str + i)!= '\0'){
		ch = *(str + i);
		for(j = 0; j < 8 ; j++){
			if(ch & (j << i))
				count++;
		}
		i++;
	}

}
