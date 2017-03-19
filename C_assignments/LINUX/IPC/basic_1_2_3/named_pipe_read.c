#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char * myfifo = "myfile";
    char buf;

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDWR);
 	
    while(read(fd, &buf, 1) > 0)
  	  printf("%c", buf);
    close(fd);

    return 0;
}
