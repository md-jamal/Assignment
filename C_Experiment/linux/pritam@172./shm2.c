#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <sys/mman.h>                                                           
#include <sys/stat.h>                                                           
#include <fcntl.h>            
#include <string.h>
#define PAGE_SIZE 4096
#define MAX 64

int main(void)                                                                  
{                                                                               
	int fd;
	char *ptr;
	char buf[MAX];
	if(-1 == (fd = shm_open("/shm", O_RDWR, 0666))) {
		perror("open failed\n");
		exit(EXIT_FAILURE);
	}

	if((void *)-1 == (ptr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,MAP_SHARED, fd, 0)))                                
		perror("mmap () failed "); 


	memcpy(buf, ptr, MAX);

	if(-1 == write(1, buf, strlen(buf))) {
		perror("Write failed\n");
		exit(1);
	}

	if(-1 == munmap(ptr, PAGE_SIZE)) {
		perror("munmap failed\n");
		exit(1);
	}

	if(-1 == shm_unlink("/shm")) {
		perror("unlink failed\n");
		exit(1);
	}

	if(-1 == (close (fd))) {
		perror("Close failed\n");
		exit(1);
	}
	return 0;                                                                   
}    
