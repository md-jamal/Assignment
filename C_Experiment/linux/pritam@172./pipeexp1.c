
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256

int main(int argc, char *argv[])
{
	int fd[2];
	pid_t pid;
	char buf[MAX];
	char buf1[MAX];

	if(pipe(fd) == -1) {
		perror("Pipe failed\n");
	}

	pid = fork();

	if(pid == 0) {

		close(fd[1]);

		read(fd[0], buf1, MAX);
//		dup2(1, fd[0]);

		write(1, buf1, strlen(buf1));

		close(fd[0]);

	} else if(pid > 0) {

		close(fd[0]);
		if(NULL == fgets(buf, sizeof(buf), stdin)) {
			perror("fgets failed\n");
			exit(1);
		}
		buf[(strlen(buf))] = '\0';
		write(fd[1], buf, strlen(buf));
		close(fd[1]);
		wait(NULL);

	} else {
		perror("fork failed\n");
		exit(1);
	}

	return 0;
}
