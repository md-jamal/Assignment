
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX 10

int main(void)
{
	int i;	
	char  *argv[MAX];
	char *del = "\n ";
	char arg[MAX] = {'\0'};
	pid_t pid;

	while(1) {

		printf("bash : ");
		if(NULL == (fgets(arg, MAX, stdin))) {
			perror("fgets Failed\n");
			exit(1);
		}

		argv[0] = (char *)strtok(arg, del);

		for (i = 0; argv[i] != NULL; i++) 
			argv[i + 1] =(char *)strtok(NULL, del);

		pid = fork();

		if(pid > 0) {

			wait();

		} else if (pid == 0) {


			if (-1 == (execvp(argv[0], argv))) {
				
				perror("execvp failed\n");
				exit(0);
			}

		} else {

			perror("fork failed\n");
			exit(1);
		}

	}
	return 0;
}
