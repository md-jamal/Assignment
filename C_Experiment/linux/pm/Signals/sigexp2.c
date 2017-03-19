
#include "errors.h"
#include <signal.h>

void my_sig_handler(int sig)
{
	if(SIGCHLD == sig)
		printf("Child exited.....\n");
}

int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid > 0) {
		signal(SIGCHLD, my_sig_handler);
		//wait(NULL);
	} else if(pid == 0) {
		printf("In child, Signaling...\n"); 
 /*here SIGCHLD will be signaled, and we have registered my_sig_handler
   so that will be executed */

	} else {
		printf("Fork failed\n");
	}
	return 0;
}
