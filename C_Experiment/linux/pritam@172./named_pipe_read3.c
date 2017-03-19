#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "errors.h"

#define MAX 100

int main (void)
{
	char buf[MAX] = {'\0'};
	int fd;

	fd = open ("./named_pipe", O_RDONLY);

	read(fd, buf, MAX);

	write(1, buf, sizeof(buf));

	close(fd);
}
