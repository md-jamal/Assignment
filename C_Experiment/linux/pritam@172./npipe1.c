#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	if(-1 == mkfifo("mypipe", 00006)) {
		perror("mkfifo failed\n");
		exit(0);
	}

	if(-1 == (fd = open("mypipe", O_RDWR))) {
		perror("open failed\n");
		exit(1);
	}

	if(-1 == (write(fd, "HELLO WORLD", 12))) {
		perror("write failed\n");
		exit(1);
	}

	return 0;
}
