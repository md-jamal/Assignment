
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void func(void);
void func2(void);

int main(void)
{
	pthread_t pt, pt2;
	if(0 != (pthread_create(&pt2, NULL, (void *)&func2, NULL))) {
			perror("Thread creation failed\n");
			exit(0);
	 }
	 
	 if(0 != (pthread_create(&pt, NULL, (void *)&func, NULL))) {
		perror("Thread creation failed\n"); 
		exit(0);
	}
	pthread_exit(NULL);
	return 0;
}

void func(void)
{
	while(1) 
	printf("Hello\n");
	return;
}

void func2(void)
{
	while(1) {
	printf("World\n");
	exit(0);
	}
}
