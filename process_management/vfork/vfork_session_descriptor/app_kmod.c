#include<stdio.h>
#include<fcntl.h>


int main()

{
	int fd;
	int pid;
	
		
	printf("%d",getpid());
	getchar();
    vfork();	
	fd = open("/dev/myChar",O_RDWR);
	
	if(fd<0)
		perror("Unable to open the device\n");
	else
		printf("File opened Sucessfully %d\n",fd);
	
	ioctl(fd,getpid(),0);
	close(fd);
	exit(1);
	
	return 0;
}
