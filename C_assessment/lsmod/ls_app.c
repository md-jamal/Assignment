#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

int main()
{
	int fd;	
	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)  {
		perror("unable to open the device");
	}else {
		printf("file Opened successfully %d\n", fd);
	}  

	ioctl(fd, getpid(), 1);
	
	close(fd);

	return 0;
}
