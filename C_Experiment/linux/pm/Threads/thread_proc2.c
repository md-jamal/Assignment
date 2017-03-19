#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void func(void); 
void func2(void);
pthread_t thread2;
int main(void)
{
	pthread_t thread1;
	pid_t pid;
	pid = fork();
	if(pid > 0) {
		printf("In parent, Creating thread..\n");
		if(0 != (pthread_create(&thread1, NULL, (void*)&func, NULL))) {
			perror("Thread creation failed\n");
			exit(0);
			wait(NULL);
		}
	}else if(pid == 0) {
			printf("In child\n");
	} else {
			perror("main : Fork failed\n");
			exit(0);
	}
	pthread_exit(NULL);
	return 0;
}

void func(void)
{
	pid_t pid2;
	pid2 = fork();
	if(pid2 > 0) {
		printf("Func 1 : In thread\n");
	} else if(pid2 == 0) {
		printf("Func1 : Thread created process\n");
	} else {
		perror("Func1 : fork failed");
		exit(0);
	}

	if(0 != (pthread_create(&thread2, NULL, (void*)&func2, NULL))) {
		perror("Thread creation failed\n");
		exit(0);
	}
}

void func2(void)
{
	printf("Func2 : In thread created thread\n");
}
