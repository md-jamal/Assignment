#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 10

int main ( void )
{
	char *argv[MAX];
	int i = 0;
	char *delimit = "\n ";
	pid_t pid;
	char arg[MAX] = {'\0'};   	

	while(1){ 
		
		printf("bash$:");
		if(NULL == (fgets(arg , MAX , stdin))) {

			perror("fgets failed\n");
			exit(0);
		}

		argv[0] = (char *)strtok (arg, delimit);

		for ( i= 0 ;(argv[i] != NULL); i++ ){
			argv[i + 1] =  (char *)strtok (NULL,delimit);
		}

		pid = vfork();

		if( pid == 0 ){

			if(-1 ==  (execvp(argv[0], argv))) {

				perror("execvp failed \n");
				exit(0);
			}
		}
		else if (pid > 0){

			wait(NULL);	

		} else {

			perror("fork failed\n");
			exit(0);
		}
	}
	return 0;
}
