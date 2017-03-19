#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)  {
		perror("unable to open the device");
	}else {
		printf("file Opened successfully %d\n", fd);
	} 

	printf("pid : %d\n", getpid());
	ioctl(fd, getpid(), 1);
	getchar();
	close(fd);

	return 0;
}
