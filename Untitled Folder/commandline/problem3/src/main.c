#include "header.h"
//void (*calculators[]) (int a,int b) = {add,sub,mul,div};      
int main(int argc,char *argv[])
{
	char *str = NULL;
	void (*calculators[]) (int a,int b) = {add,sub,mul,div};           
	if ( NULL == (str = (char *)malloc(sizeof(char)*MAX ) ) ) {
		printf("malloc failed\n");
		exit(0);
	}
	
	if ( strcomp("add",argv[1]) == 1)
		(*calculators[0])(atoi(argv[2]),atoi(argv[3]));

	if ( strcomp("sub",argv[1]) == 1)
		(*calculators[1])(atoi(argv[2]),atoi(argv[3]));

	if ( strcomp("mul",argv[1]) == 1)
		(*calculators[2])(atoi(argv[2]),atoi(argv[3]));

	if ( strcomp("div",argv[1]) == 1)
		(*calculators[3])(atoi(argv[2]),atoi(argv[3]));
	return 0;
}
