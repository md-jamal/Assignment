#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int status=1;
	unsigned int n = 0;
	//mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	//open("file_1.c", O_WRONLY,S_IWUSR);
	
	if(status < 0){
		perror("read failed");
		exit(1);
	}
	n = n + 1;

	status = write(2, &n, sizeof(n));

	if(status < 0){
		;
	}
	fscanf(stdin, "%d",&n);
	fprintf(stdout,"%d",n);

	printf("%s",strerror(17));	
}
