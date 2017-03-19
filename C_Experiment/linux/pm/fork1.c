
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int a = 10;

int main(void)
{
	int *p = (int *)malloc(4);
	int i = 5;
	int pid;
	pid = fork();
	if(pid > 0) {
	//	sleep(1);
		i = 6;
		a = 20;
		printf("a in parent : %d\naddress of a: %p\n i : %d\n", a, &a, i);
		printf("address of i : %p\naddress of p : %p\n", &i, p);
	} else if(pid == 0) {
		int b = 10;
		printf("a in child : %d\naddress of a in child : %p\n", a, &a);
		printf("b in child : %d\naddress of b : %p\n", b, &b);
		printf("i : %d\naddress of i : %p\naddress of p : %p\n", i, &i, p);
	} else {
		perror("fork failed\n");
		exit(1);
	}
	return 0;
}
