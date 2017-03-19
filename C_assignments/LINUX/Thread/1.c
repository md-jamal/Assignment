#include<pthread.h>
#include<stdio.h>
#include <unistd.h>

int A = 10;
void* thread_function (void* arg)
{
	A = A + 10;
    printf ("child thread pid is %d\n", (int) getpid ());
	printf("PID = %d",getpid());
	getchar();
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
	A = A + 100;
	printf("Value Of A: %d\n",A);
	
	printf("PID = %d",getpid());
	getchar();
	pthread_exit(NULL);   
    return 0;
}
