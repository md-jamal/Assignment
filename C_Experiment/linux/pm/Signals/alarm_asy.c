#include "errors.h"
#include <signal.h>

int status;

#if 1
int main( void )
{
	int seconds;
	char line[120];
	char message[64];
	pid_t pid; 
	
	while(1) {


		printf("\nAlarm>");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);

		if(strlen(line) <= 1) continue;


		pid = fork ();

		if (pid > 0){

		signal(SIGCHLD, SIG_IGN);

		}else if (pid == 0) {
			
			if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {
				fprintf(stderr, "Bad command \n");
			} else {
				sleep(seconds);
				printf("(%d) %s \n", seconds, message);
			}
			exit (0);
		} else {
			perror ("fork failed");
		}
	}

}
#endif
