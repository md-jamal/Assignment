#include <stdio.h>
#include <pthread.h>

/*macro*/
#define NUM_LOOPS 500000

long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *counting_fun(void *arg)
{
	int offset = *(int *)arg;
	int i = 0;
	for(i=0; i <= NUM_LOOPS; i++)
	{
		pthread_mutex_lock(&mutex);
		
		sum +=   offset;
		
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}
int main( void )
{
	/*Spawn Threads*/
	pthread_t id1;
	int offset1 = 1;
	pthread_create(&id1, NULL, counting_fun, &offset1);
		
	pthread_t id2;
        int offset2 = -2;
        pthread_create(&id2, NULL, counting_fun, &offset2);
       
	/*Waiting For Thread Complete*/ 
		pthread_join(id1, NULL);
		pthread_join(id2, NULL);	
	
	printf("\nSum = %lld\n", sum);

	return 0;
}
