#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd, fd1;
	pid_t pid;	
	fd = open("/dev/myChar", O_RDWR);
	fd1 = open("just.txt", O_RDWR);
	if (fd < 0)  {
		perror("unable to open the device");
	}else {
		printf("file Opened successfully %d\n", fd);
	}  
	
	pid = fork();
	if(pid > 0) {	
		ioctl(fd, getpid(), fd1);
	} else if(pid == 0) {
		ioctl(fd, getpid(), fd1);
		exit(0);
	} else {
		perror("fork failed\n");
		exit(0);
	}

	close(fd);

	return 0;
}
