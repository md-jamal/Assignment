/*
	Programe : To convert character upper to lower in given file.
*/
#include "file.h"

int main(int argc , char *argv[])
{
	FILE *fp = NULL; //File Pointer

	upper_to_lower(argv[1] , fp );
	return 0;
}
