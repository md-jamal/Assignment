
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/sched.h>
#define stk_size 1024 * 1024
int add(void);

int main(void)
{
	char *stack;
	stack = (char *)malloc(stk_size);
	if(-1 == (clone(&add, stack + stk_size, CLONE_VM | CLONE_FS | CLONE_IO))) {
		perror("clone failed\n");
		exit(0);
	}
}

int add(void)
{
	printf("Hello\n");
	return 0;
}
