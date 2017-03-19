#include <stdio.h>
#include <fcntl.h>

int main( void )
{
	int fd;

	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
 	ioctl(fd, getpid(), 10);	
	printf("\n%d",getpid());
	getchar();
	close(fd);

	return 0;
}
