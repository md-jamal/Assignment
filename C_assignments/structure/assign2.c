#include<stdio.h>
union sample
{
	int a:5;
	int b:10;
	int c:5;
	int d:21;
	int e;
};

int main()
{
	union sample s;
	s.e = 156;

	printf("A:%d B:%d C:%d D:%d E:%d",s.a,s.b,s.c,s.d,s.e);
}
