#define _GNU_SOURCE
#include "errors.h"

void *thread_fun(void *arg)
{
	pthread_attr_t gattr;
	struct sched_param prio;
	int i;
	int p;	
	
	prio.sched_priority = 94;
	p = pthread_setschedparam(pthread_self(), SCHED_FIFO, &prio);
	if(p != 0)
		errno_abort("pthread_setschedparam");
	

	p = pthread_getschedparam(pthread_self(), &i, &prio);
	if(p != 0)
		errno_abort("pthread_getschedparam");

	if(i == SCHED_FIFO)
		printf("child sched_FIFO\n");
	printf("child priority %d\n",prio.sched_priority);

	return NULL;
}

int main()
{
	pthread_t thr;
	int p;
	int i;
	pthread_attr_t attr;
	struct sched_param prio;



/*	p = pthread_attr_init(&attr);
	if(p != 0)
		errno_abort("pthread_attr_init");


	p = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(p != 0)
		errno_abort("pthread_attr_setinheritsched");

*/	
	p = pthread_create(&thr, NULL, thread_fun, NULL);
	if(p != 0)
		printf("pthread_create is failed\n");
/*
	p = pthread_getschedparam(pthread_self(), &i, &prio);
	if(p != 0)
		errno_abort("pthread_attr_getschedparam");
	
	if(i == SCHED_OTHER)
		printf("child sched_rr\n");

	printf("parent priority %d\n",prio.sched_priority);
*/	
	pthread_exit(NULL);
	return 0;
}
