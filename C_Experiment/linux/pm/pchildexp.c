
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int *p;
	pid_t pid;
		printf("parent pid : %d\n", getpid());
		printf("parent pid : %d\n", getppid());
	pid = fork();
	if(pid > 0) {
		printf("parent pid : %d\n", getpid());
		printf("Child pid : %d\n", pid);
		printf("In parent \n");
	while(1) {
		}//	sleep(1);
	} else if(pid == 0) {
		printf("child pid : %d\nchild ppid : %d\n",getpid(), getppid());
		printf("In child\n");
		while(1) {
		}
	} else {
		perror("fork failed\n");
		exit(1);
	}
	return 0;
}
