#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <sys/mman.h>                                                           
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <string.h>       
#include <semaphore.h>
#define MAX 64     
#define SIZE 2
#define PAGE_SIZE 4096                                                          

int main(void)                                                               
{                    
	int buf[SIZE];         
	int *p = buf;
	int fd;           
	int i = 0;
	int *addr;

	if(-1 == (fd = shm_open("/shm", O_RDWR | O_CREAT, 0666))) {                 
		perror("creating shm object failed\n");                                 
		exit(EXIT_FAILURE);                                                     
	}                                                                          

	if(-1 == (ftruncate(fd, PAGE_SIZE)))  {                                     
		perror("ftrucate failed\n");                                            
		exit(1);                                                                
	}                                                                           

	if((void*) -1 == (addr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0))) {
		perror("mmap failed\n");
		exit(1);
	}
	
	getchar();

	*(p + 0) = 5;
	*(p + 1) = 10;

	memcpy(addr, buf, sizeof(buf));

	if(-1 == close(fd)) {
		perror("close failed\n");
		exit(1);
	}

	return 0;                                                                   
}                                                                                  
