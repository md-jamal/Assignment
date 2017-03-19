#include <stdio.h>
#include <fcntl.h>

int main( void )
{
	int fd;
	int g_var = 10;
	printf("pid= %d\n", getpid());

	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
	printf("G_VAR::%d", g_var);
 	ioctl(fd, getpid(), &g_var);	
	printf("Updated G_var%d",g_var);
	getchar();	
	
	close(fd);

	return 0;
}
