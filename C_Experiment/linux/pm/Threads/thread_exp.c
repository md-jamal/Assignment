#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>
#include "errors.h"
int fd1, fd;
void function(void);
int main(void)
{
	pid_t pid;                                                                  
	pthread_t thread;
	fd = open("/dev/myChar", O_RDWR);           
	fd1 = open("just.txt", O_RDWR);

	if (fd < 0)  {                                                              
		errno_abort("unable to open the device");                                    
	}else {                                                                     
		printf("file Opened successfully %d\n", fd);                            
	}
	
	ioctl(fd, getpid(), fd1);                            

	printf("Group leader pid : %lu\n", syscall(SYS_gettid));
	if (-1 == (write(fd1, "Global edge", 11))) {
		errno_abort("write failed\n");
		exit(0);
	}
	if (0 != (pthread_create(&thread, NULL, (void *)&function, NULL))) {
		err_abort(errno, "Threard creation failed\n");
		exit(0);
	}
	pthread_join(thread, NULL);
	close(fd1);
	return 0;
}

void function(void)
{
	printf("Thread pid : %lu\n", syscall(SYS_gettid));

	if (-1 == (write(fd1, "Software Limited", 11))) {
		errno_abort("write failed\n");
		exit(0);
	}
	ioctl(fd, getpid(), fd1);
	close(fd1);
}
