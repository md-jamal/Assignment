#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <sys/mman.h>                                                           
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <string.h>
#include <semaphore.h>
#define MAX 15
#define SIZE 10
#define PAGE_SIZE 4096                                                          

int main(void)                                                                  
{
	int i;
	int buf[SIZE];                                                              
	int fd;                                                                     
	int *addr;
	/*const volatile*/ int *ptr;

	if(-1 == (fd = shm_open("/shm", O_RDWR, 0666))) {                 
		perror("creating shm object failed\n");                                 
		exit(EXIT_FAILURE);                                                     
	}                                                                                                                    
	
	if((void*) -1 == (addr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0))){
		perror("mmap failed\n");
		exit(1);
	}
	
	ptr = addr;

	while(*(ptr + 0) != 5)  {
	
	}
	printf("buf[1] : %d\n", *(ptr + 1));                                                         

	if(-1 == shm_unlink("/shm")) {
		perror("shared memory unlink failed\n");
		exit(1);
	}
	return 0;              
}                                                                              
