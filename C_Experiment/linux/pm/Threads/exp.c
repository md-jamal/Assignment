#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

volatile int g;

void thread (void);

int main (void)
{
	pthread_t pt;
	int st;

	st = pthread_create(&pt, NULL, (void *)&thread, NULL);

	if (st > 0) {
		perror("pthread failed \n");
		exit(1);
	}
	printf("In parent\n");
	sleep(1);
	g = 5;

	pthread_exit(NULL);	
	return 0;
}

void thread (void)
{
	while (g != 5) {
	//	printf("In child\n");
	}

	printf("g = %d\n", g);
}
