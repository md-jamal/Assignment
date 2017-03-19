#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "errors.h"

void function(void);
void function2(int *);
int g_var = 10;
int main(void)
{
	int *h_var = (int *)malloc(sizeof(int));
	pthread_t t1, t2;
	int l_var = 5;
	*h_var = 50;
	int fd = open("just.txt", O_RDWR);

	printf("In TGL Before modification : \n");
	printf("g_var %d\nl_var : %d\nh_var : %d\n", g_var, l_var, *h_var);
	printf("TGL tid : %lu\n", syscall(SYS_gettid));
	printf("pid : %d\n", getpid());
	if(0 != (pthread_create(&t1, NULL, (void *)&function2, h_var))) {
		err_abort(errno, "Thread creation failed\n");
		exit(0);
	}
	pthread_join(t1, NULL);
	printf("After modifying in thread \nIn TGL \n");
	printf("g_var : %d\nAddress of g_var : %p\n", g_var, &g_var);
	printf("h_var : %d\n", *h_var);
	return 0;
}

void function2(int *h_var)
{
	int b = 1;
	printf("In the thread \n");
	printf("Thread pid : %d\n", getpid());
	printf("Thread tid : %lu\n", syscall(SYS_gettid));
	printf("g_var : %d\nAddress of b : %p\n", g_var, &b);
	g_var = 20;
	*h_var = 100;
	exit(1);
	getchar();
}
