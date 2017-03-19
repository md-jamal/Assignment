#include<pthread.h>
#include<stdio.h>
#include <unistd.h>

void* thread_function (void* arg)
{
    return NULL;
}

int main ()
{
	pthread_t thread;
	int status = 0; 
    	printf ("main thread pid is %d\n", (int) getpid ());
    	status = pthread_create (&thread, NULL, &thread_function, NULL);

	if ( status != 0)
	{
		printf("Thread Creation Failed %d",strerror(status));
	}
	pthread_exit(NULL);   
   
	 return 0;
}
