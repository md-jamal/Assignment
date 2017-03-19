#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int g_var = 0;
void func(void);

int main(void)
{
	pthread_t p1;
	
	if(0 != (pthread_create(&p1, NULL, (void *)&func, NULL))) {
		perror("Thread creation failed\n");
		exit(1);
	}

	sleep(1);
	g_var = 5;
	
	pthread_exit(NULL);
}

void func(void)
{
	while(g_var != 5) {

	}

	printf("gvar : %d\n", g_var);
}

