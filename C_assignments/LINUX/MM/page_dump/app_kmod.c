#include <stdio.h>
#include <fcntl.h>

int main( void )
{
	int fd;
	
	printf("pid= %d\n", getpid());

	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
 	ioctl(fd, getpid(), 10);	
	getchar();	
	
	close(fd);

	return 0;
}
