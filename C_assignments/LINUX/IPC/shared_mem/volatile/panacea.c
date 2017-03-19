#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>

/*Macro*/
#define SHM_SIZE 512
#define SHM_NAME "/shm"
int main( void )
{
	const size_t region_size = sysconf(_SC_PAGE_SIZE);
	int count = 0, i = 0;
	int value[3];
    sem_t *my_sem;	
	int fd = shm_open(SHM_NAME, O_RDWR, 0666);

	int *addr;
	
	if(fd == -1){
		printf("\nshm_open:failed");
		exit(EXIT_FAILURE);
	}
	int *ptr = (int *)mmap(0, region_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	if(ptr == MAP_FAILED)
	{
		printf("\nmmap:Failed");
		exit(EXIT_FAILURE);	
	}	

	addr = ptr;
	
	printf("\nValue::%d",*(addr + 0)); 

	while( *(addr + 0) != 85)
		;
	printf("\nValue :: %d",*(addr + 0));
	

	if(munmap(ptr, region_size) != 0 )
		printf("\nmunmap:failed");

	if(close(fd) != 0)
		printf("\nClose Failed");
	if(shm_unlink(SHM_NAME) != 0)
		printf("shm_unlink:failed");	
	
	return 0;
}


