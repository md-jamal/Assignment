#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int g_var = 10;

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
	printf("gvar address : %08x\ng_var value : %d\n", &g_var, g_var);
	ioctl(fd, getpid(), ((unsigned long)&g_var));
	close(fd);
	getchar();
	return 0;
}
