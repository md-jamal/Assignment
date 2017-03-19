#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	pid_t pid;	
	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)  {
		perror("unable to open the device");
	}else {
		printf("file Opened successfully %d\n", fd);
	}  
	
	pid = fork();
	if(pid > 0) {	
		ioctl(fd, getpid(), 1);
	} else if(pid == 0) {
		ioctl(fd, getpid(), 1);
	} else {
		perror("fork failed\n");
		exit(0);
	}

	close(fd);

	return 0;
}
