#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <sys/mman.h>                                                           
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <string.h>
#include <semaphore.h>
#define MAX 15                                                                  
#define PAGE_SIZE 4096                                                          

int main(void)                                                                  
{
	sem_t *sv;
	char buf[MAX];                                                              
	int fd;                                                                     
	char *addr;

	if(-1 == (fd = shm_open("/shm", O_RDWR, 0666))) {                 
		perror("creating shm object failed\n");                                 
		exit(EXIT_FAILURE);                                                     
	}                                                                                                                    
	
	if((void*) -1 == (addr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0))){
		perror("mmap failed\n");
		exit(1);
	}

	if(SEM_FAILED == (sv = sem_open("/semaphore", O_CREAT, 0666, 2u))) {            
		perror("Semaphore creation fialed\n");                                  
		exit(1);                                                                
	}                                                                           
	if(-1 == sem_wait(sv)) {                                                    
		perror("wait failed\n");                                                
		exit(1);                                                                
	}            
	
	memcpy(buf, addr, MAX);
	
	if(-1 == (write(1, buf, strlen(buf)))){
			perror("write failed\n");
			exit(1);
	}

	if(-1 == (sem_post(sv))) {                                                  
		perror("post failed\n");                                                 
		exit(1);                                                                
	}    
	
	if(-1 == (sem_unlink("/sem1"))) {
		perror("semaphore unlink failed\n");
		exit(1);
	}

	if(-1 == shm_unlink("/shm")) {
		perror("shared memory unlink failed\n");
		exit(1);
	}
	return 0;              
}                                                                              
