#include<stdio.h>
#include<fcntl.h>
#include<pthread.h> 
#include<string.h>
#include<sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#define _GNU_SOURCE 

void *thread_function(void *p)                                                  
{                                                                               
    printf("a thread tgid 3:%d     tid: %d\n",getpid(),syscall(SYS_gettid));    
	ioctl(*(int *)p,syscall(SYS_gettid),0);
	getchar();
	return NULL;                                                                
}   
int main()

{
	int fd;
	int *ptr = &fd;
	
	printf("%d",getpid());
	fd = open("/dev/myChar",O_RDWR);
	
	if(fd<0)
		perror("Unable to open the device\n");
	else
		printf("File opened Sucessfully %d\n",fd);
	
	pid_t pid;                                                                  
    int status;                                                                 
    pthread_t th_id;                                                            
    printf("process tgid %d    tid:  %ld\n",getpid(),syscall(SYS_gettid));      
    status = pthread_create(&th_id,NULL, thread_function,ptr);   // 0-upon sucess; error number for error
        if (status != 0){                                                       
            printf("thread failed: %s\n",strerror(status));                     
        }
	ioctl(fd,syscall(SYS_gettid),0);
	getchar();	
    pthread_exit(NULL); 
	close(fd);
	
	return 0;
}
