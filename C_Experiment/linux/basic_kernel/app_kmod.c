#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	
	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0) 
		perror("unable to open the device");
	else
		printf("file Opened successfully %d\n", fd);

	ioctl(fd, getpid(), 1);

//	printf("in application pid is:%d", getpid());
	close(fd);

	return 0;
}
