#include <stdio.h>
#include <signal.h>
#include "errors.h"

#if 0
void my_handler()
{
	printf("Child is killed\n");
}

int main (void)
{
	pid_t status;

	signal(SIGUSR1, my_handler);	

	status = fork();

	if (status == 0) {
		getchar();
		printf("In child\n");
		kill(getpid(), SIGUSR1);
	} else if (status > 0) {
		printf("In parent\n");
		kill(getpid(), SIGUSR1);
	} else {
		errno_abort("Fork failed\n");
	}
	kill(getpid(), SIGUSR1);


}
#endif

#if 0 

void my_handler(int sg)
{
	if (sg == SIGCHLD) 
		printf("Child is killed\n");
}

int main (void)
{
	pid_t status;

	signal(SIGCHLD, my_handler);

	status = fork();

	if (status == 0) {
		printf("In child\n");
	} else if (status > 0) {
		wait (NULL);
		printf("In parent\n");
	} else {
		printf("Fork is failed\n");
	}

	return 0;
}

#endif

#if 1

void my_handler(int sg)
{
	if (sg == SIGTSTP) {
		printf("\nTerminated on ctrl+z\n");
		exit(1);
	} else if (sg == SIGINT) {
		printf("\nTerminated on ctrl+c\n");
	}

}

int main (void)
{
	pid_t status;


	status = fork();

	if (status == 0) {
		getchar();
		printf("In child\n");
	} else if (status > 0) {
		signal(SIGTSTP, my_handler);
		signal(SIGINT, my_handler);
		printf("In parent\n");
		wait (NULL);
	} else {
		printf("Fork is failed\n");
	}

	return 0;
}

#endif

#if 0

void my_handler(int sg)
{
	if (sg == SIGCHLD) 
		printf("Child is killed\n");
}

int main (void)
{
	pid_t status;

	signal(SIGCHLD, my_handler);

	status = fork();

	if (status == 0) {
		printf("In child\n");
		sleep(2);
	} else if (status > 0) {
		wait (NULL);
		printf("In parent\n");
		getchar();
		kill(getppid(), SIGUSR2);
	} else {
		printf("Fork is failed\n");
	}

	return 0;
}

#endif

#if 0

void my_handler(int sg)
{
	if (sg == SIGCHLD) 
		printf("Child is killed\n");
}

int main (void)
{
	struct sigaction sa;
	pid_t status;

	sa.sa_handler = my_handler;
	sigaction(SIGCHLD, (const struct sigaction*)&sa, NULL);

//	signal(SIGCHLD, SIG_IGN);
	status = fork();

	if (status == 0) {
		printf("In child\n");
	} else if (status > 0) {
		printf("In parent\n");
		wait(NULL);
	} else {
		printf("Fork is failed\n");
	}

	return 0;
}

#endif
