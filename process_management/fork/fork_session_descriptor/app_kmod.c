#include<stdio.h>
#include<fcntl.h>


int main()

{
	int fd;
	int pid;
	
	printf("%d",getpid());
	getchar();
	fd = open("/dev/myChar",O_RDWR);
	
	if(fd<0)
		perror("Unable to open the device\n");
	else
		printf("File opened Sucessfully %d\n",fd);
	
	fork();
	ioctl(fd,getpid(),0);
	
	close(fd);
	
	return 0;
}
