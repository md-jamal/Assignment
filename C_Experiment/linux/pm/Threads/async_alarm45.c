
#include "errors.h"
#define MAX 1024
void async_alarm(char *);

int main (int argc, char *argv[])
{
	char line[128];
	pthread_t *t1;
	int i = 0;
	while(1) {
		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL)
			exit(0);
		if (strlen (line) <= 1) 
			continue;
		t1 = (pthread_t *)malloc(sizeof(pthread_t));
		if(0 != (pthread_create(t1, NULL, (void*)&async_alarm, line))) {
			perror("Thread creation failed\n");
			exit(0);
		}
	}
	pthread_exit(NULL);
	return 0;
}

void async_alarm(char *line)
{	
		int seconds;
		char message[64];
		if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {
			fprintf (stderr, "Bad command\n");
		} else {
			sleep(seconds);
			printf(" (%d) %s\n", seconds, message);
		}
		pthread_detach(pthread_self());
}
