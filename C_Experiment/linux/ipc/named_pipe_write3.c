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

	if (NULL == fgets(buf, MAX, stdin)) {                                   
		err_abort(errno, "writing in buf failed\n");                        
	}                                                                       


    if (-1 == mkfifo("./named_pipe", 0666)) {                     
        errno_abort("Pipe failed\n");                                           
    }                                                                           

	fd = open ("./named_pipe", O_WRONLY);

	write(fd, buf, MAX);

	close(fd);

	unlink("./named_pipe");
}
