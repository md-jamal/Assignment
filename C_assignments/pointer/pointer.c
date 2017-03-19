#include<stdio.h>
#include<string.h>

#if 0
int main(int argc , char *argv[])
{
	printf("Folder : %d" , argc);
	return 0;
}
#endif

#if 1
int main(int argc , char *argv[])
{
	int result=0;
	char ch,opr;

	do
	{
		while(1)
		{
			if(atoi(argv[1])<0)
			{
				printf("\nYour value is less than 0 plz reenter the value");
				continue;
			}
			if(atoi(argv[2])<0)
			{
				printf("\nYour value is less than 0 plz reenter the value");
				continue;
			}			
			printf("If u want close it:y/n");
			ch = getchar();
			if(ch=='y')
				exit(0);
			if(num_1>=0 && num_2>=0)
				break;
		}	
		switch(argv[0])
		{
			case '+':
				result = argv[1] + argv[2];
				break;
			case '-':
				result=num_1 - num_2;
				break;
			case '*':
				result=num_1 * num_2;
				break;
			case '/':
				if(num_2==0)
				{
					printf("Your Division is 0\n");
					break;
				}
				result=num_1 / num_2;
				break;
		}
		printf("\nResult:%d",result);
		printf("\nIf u want continue y/n\n");
		scanf(" %c",&ch);
	}while(ch=='y');
}
#endif
#endif
