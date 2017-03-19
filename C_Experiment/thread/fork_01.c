#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

#define   MAX_COUNT  5
#define   BUF_SIZE   100

void  main(void)
{
     pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];
	int a = 10;
     int n = fork();
     pid = getpid();
	printf("N::%d\n",n);
/*     for (i = 1; i <= MAX_COUNT; i++) {
          sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
          write(1, buf, strlen(buf));
     }*/ 
}
