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
	sem_t *sv;
	int buf[SIZE];                                                              
	int fd;                                                                     
	int *addr;

	if(-1 == (fd = shm_open("/shm", O_RDWR, 0666))) {                 
		perror("creating shm object failed\n");                                 
		exit(EXIT_FAILURE);                                                     
	}                                                                                                                    
	
	if((void*) -1 == (addr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0))){
		perror("mmap failed\n");
		exit(1);
	}

	if(SEM_FAILED == (sv = sem_open("/sem2", O_CREAT, 0666, 1u))) {            
		perror("Semaphore creation fialed\n");                                  
		exit(1);                                                                
	}

	if(-1 == sem_wait(sv)) {                                                    
		perror("wait failed\n");                                                
		exit(1);                                                                
	}   

	memcpy(buf, addr, sizeof(buf));

	for(i = 0; i < SIZE; i++) {
		printf("%ld\n", buf[i]);
		buf[i] = 0;
	}
	if(-1 == (sem_post(sv))) {                                                  
		perror("post failed\n");                                                 
		exit(1);                                                                
	}    

	
	if(-1 == (sem_unlink("/sem2"))) {
		perror("semaphore unlink failed\n");
		exit(1);
	}

	if(-1 == shm_unlink("/shm")) {
		perror("shared memory unlink failed\n");
		exit(1);
	}
	return 0;              
}                                                                              
