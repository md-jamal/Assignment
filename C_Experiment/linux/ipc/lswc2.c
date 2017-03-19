
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define MAX 100

int main ( void )
{
	int fd[2];
	int i = 0;
	pid_t pid;
	char buf1[MAX];
	char *buf2[MAX];

	if(pipe(fd) == -1) {
		perror("pipe failed\n");
		exit(1);
	}
	pid = fork();

	if( pid > 0 ){

		close(fd[0]);
		dup2(fd[1], 1);
		if(-1 ==  execl("/bin/ls", "ls", NULL)) {

			perror("execvp failed \n");
			exit(0);
		}
		wait(NULL);

	} else if (pid == 0) {	
	
		close(fd[1]);
		dup2(fd[0], 0);
	/*	read(fd[0], buf2, MAX);
		write(1, buf2, strlen(buf2));*/
		if(-1 ==  (execvp("wc", "wc"))) {

			perror("execvp failed \n");
			exit(0);
		}
		close(fd[0]);

	} else {

		perror("fork failed\n");
		exit(0);
	}
	return 0;
}
