#include <stdio.h>
struct student 
{
	int rno;
	char name[10];
};
int main( void )
{
	struct student s[10];
	struct student tmp;
	
	int i = 0, j = 0;

	FILE *fp = fopen("student.txt", "r");
	//if(fp == NULL)
		printf("HII");
	
	while(fread(&s[i++], sizeof(tmp),1,fp)  == 1)
		;
	
	for(i = 0;i < 5; i++)
	{
		for(j=0; j< 5; j++)
		{
			if(strcmp(s[j].name, s[j+1].name < 0))
			{
				tmp = s[j+1];
				s[j+1] = s[j];
				s[j] = tmp;
			}
		}
	}
	for(i = 0; i < 5; i++)
	{
		printf("Name : %s",s[i].name);
		printf("Rno : %d",s[i].rno);
	}
	return 0;
}

