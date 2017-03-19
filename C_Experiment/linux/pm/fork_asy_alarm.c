/*
 * alarm.c
 * 
 * Simple asynchronous alarm program. This is used as a
 * reference for progressive examples of asynchronous 
 * alarm programs.
 */

#include "errors.h"
void fork_alarm(void);

int seconds;
char line[128];
char message[64];
pid_t pid;

int main (int argc, char *argv[])
{
	while(1) {
			
		int ret;
		while(0 != (ret = waitpid(0, NULL, WNOHANG))) {
			printf("ret : %d\n", ret);	
			if(ret == -1) {
				break;
			}
		}
		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL)
			exit(0);
		if (strlen (line) <= 1) 
			continue;

		pid = fork();

		if(pid > 0) {


		} else if (pid == 0) {

			if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {
				fprintf (stderr, "Bad command\n");
			} else {
				sleep(seconds);
				printf(" (%d) %s\n", seconds, message);
			}

		} else {

			printf("fork failed\n");
			exit(0);
		}
	}
	return 0;
}

